
// $destdir/u47.c        Machine generated C code

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



// Code for tchscheme2

static LispObject CC_tchscheme2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27634, v_27635;
    LispObject fn;
    argcheck(nargs, 0, "tchscheme2");
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
    v_27634 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_27634;
v_27612:
    goto v_27624;
v_27620:
    v_27635 = qvalue(elt(env, 1)); // rowmax
    goto v_27621;
v_27622:
    v_27634 = stack[0];
    goto v_27623;
v_27624:
    goto v_27620;
v_27621:
    goto v_27622;
v_27623:
    v_27634 = difference2(v_27635, v_27634);
    env = stack[-1];
    v_27634 = Lminusp(nil, v_27634);
    env = stack[-1];
    if (v_27634 == nil) goto v_27617;
    goto v_27611;
v_27617:
    v_27634 = stack[0];
    fn = elt(env, 2); // removechild
    v_27634 = (*qfn1(fn))(fn, v_27634);
    env = stack[-1];
    v_27634 = stack[0];
    fn = elt(env, 3); // to!*scheme
    v_27634 = (*qfn1(fn))(fn, v_27634);
    env = stack[-1];
    v_27634 = stack[0];
    v_27634 = add1(v_27634);
    env = stack[-1];
    stack[0] = v_27634;
    goto v_27612;
v_27611:
    v_27634 = nil;
    return onevalue(v_27634);
}



// Code for sroot1

static LispObject CC_sroot1(LispObject env,
                         LispObject v_27606, LispObject v_27607)
{
    env = qenv(env);
    LispObject v_27791, v_27792, v_27793, v_27794;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27606,v_27607);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_27607;
    stack[-3] = v_27606;
// end of prologue
// Binding freevars
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-5, 1, -2);
    qvalue(elt(env, 1)) = nil; // freevars
// Binding substitution
// FLUIDBIND: reloadenv=5 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 2, -1);
    qvalue(elt(env, 2)) = nil; // substitution
    goto v_27627;
v_27623:
    v_27792 = qvalue(elt(env, 3)); // rpt
    goto v_27624;
v_27625:
    v_27791 = elt(env, 4); // inf
    goto v_27626;
v_27627:
    goto v_27623;
v_27624:
    goto v_27625;
v_27626:
    if (v_27792 == v_27791) goto v_27622;
    goto v_27635;
v_27631:
    v_27792 = qvalue(elt(env, 3)); // rpt
    goto v_27632;
v_27633:
    v_27791 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27634;
v_27635:
    goto v_27631;
v_27632:
    goto v_27633;
v_27634:
    v_27791 = (LispObject)lesseq2(v_27792, v_27791);
    v_27791 = v_27791 ? lisp_true : nil;
    env = stack[-5];
    goto v_27620;
v_27622:
    v_27791 = nil;
    goto v_27620;
    v_27791 = nil;
v_27620:
    if (v_27791 == nil) goto v_27618;
    else goto v_27616;
v_27618:
    v_27791 = stack[-3];
    if (!consp(v_27791)) goto v_27644;
    else goto v_27645;
v_27644:
    v_27791 = lisp_true;
    goto v_27643;
v_27645:
    goto v_27655;
v_27651:
    v_27791 = stack[-3];
    v_27792 = qcar(v_27791);
    goto v_27652;
v_27653:
    v_27791 = stack[0];
    v_27791 = qcdr(v_27791);
    v_27791 = qcar(v_27791);
    v_27791 = qcar(v_27791);
    goto v_27654;
v_27655:
    goto v_27651;
v_27652:
    goto v_27653;
v_27654:
    v_27791 = Lneq(nil, v_27792, v_27791);
    env = stack[-5];
    goto v_27643;
    v_27791 = nil;
v_27643:
    if (v_27791 == nil) goto v_27641;
    else goto v_27616;
v_27641:
    goto v_27617;
v_27616:
    v_27791 = stack[-3];
    goto v_27613;
v_27617:
    goto v_27668;
v_27664:
    v_27791 = stack[0];
    v_27791 = qcdr(v_27791);
    v_27791 = qcar(v_27791);
    fn = elt(env, 10); // findnewvars
    v_27792 = (*qfn1(fn))(fn, v_27791);
    env = stack[-5];
    goto v_27665;
v_27666:
    v_27791 = nil;
    goto v_27667;
v_27668:
    goto v_27664;
v_27665:
    goto v_27666;
v_27667:
    fn = elt(env, 11); // union
    v_27791 = (*qfn2(fn))(fn, v_27792, v_27791);
    env = stack[-5];
    qvalue(elt(env, 1)) = v_27791; // freevars
    v_27791 = stack[0];
    v_27791 = qcdr(v_27791);
    v_27791 = qcdr(v_27791);
    v_27791 = qcar(v_27791);
    qvalue(elt(env, 2)) = v_27791; // substitution
    v_27791 = qvalue(elt(env, 1)); // freevars
    stack[-4] = v_27791;
v_27681:
    v_27791 = stack[-4];
    if (v_27791 == nil) goto v_27685;
    else goto v_27686;
v_27685:
    goto v_27680;
v_27686:
    v_27791 = stack[-4];
    v_27791 = qcar(v_27791);
    fn = elt(env, 12); // newenv
    v_27791 = (*qfn1(fn))(fn, v_27791);
    env = stack[-5];
    v_27791 = stack[-4];
    v_27791 = qcdr(v_27791);
    stack[-4] = v_27791;
    goto v_27681;
v_27680:
    v_27791 = qvalue(elt(env, 5)); // !*trpm
    if (v_27791 == nil) goto v_27699;
    v_27791 = elt(env, 6); // "Trying rule  "
    v_27791 = Lprinc(nil, v_27791);
    env = stack[-5];
    v_27791 = stack[0];
    fn = elt(env, 13); // rprint
    v_27791 = (*qfn1(fn))(fn, v_27791);
    env = stack[-5];
    v_27791 = elt(env, 7); // "against      "
    v_27791 = Lprinc(nil, v_27791);
    env = stack[-5];
    v_27791 = stack[-3];
    fn = elt(env, 13); // rprint
    v_27791 = (*qfn1(fn))(fn, v_27791);
    env = stack[-5];
    goto v_27697;
v_27699:
v_27697:
    goto v_27720;
v_27712:
    v_27791 = stack[0];
    v_27791 = qcdr(v_27791);
    v_27794 = qcar(v_27791);
    goto v_27713;
v_27714:
    v_27793 = stack[-3];
    goto v_27715;
v_27716:
    v_27792 = lisp_true;
    goto v_27717;
v_27718:
    v_27791 = nil;
    goto v_27719;
v_27720:
    goto v_27712;
v_27713:
    goto v_27714;
v_27715:
    goto v_27716;
v_27717:
    goto v_27718;
v_27719:
    fn = elt(env, 14); // amatch
    v_27791 = (*qfnn(fn))(fn, 4, v_27794, v_27793, v_27792, v_27791);
    env = stack[-5];
    stack[-4] = v_27791;
    v_27791 = qvalue(elt(env, 5)); // !*trpm
    if (v_27791 == nil) goto v_27730;
    v_27791 = stack[-4];
    if (v_27791 == nil) goto v_27735;
    v_27791 = elt(env, 8); // "producing    "
    v_27791 = Lprinc(nil, v_27791);
    env = stack[-5];
    v_27791 = stack[-4];
    fn = elt(env, 15); // embed!-null!-fn
    v_27791 = (*qfn1(fn))(fn, v_27791);
    env = stack[-5];
    stack[-4] = v_27791;
    fn = elt(env, 13); // rprint
    v_27791 = (*qfn1(fn))(fn, v_27791);
    env = stack[-5];
    goto v_27733;
v_27735:
    v_27791 = elt(env, 9); // "failed"
    v_27791 = Lprinc(nil, v_27791);
    env = stack[-5];
    v_27791 = Lterpri(nil, 0);
    env = stack[-5];
    goto v_27733;
v_27733:
    v_27791 = Lterpri(nil, 0);
    env = stack[-5];
    goto v_27728;
v_27730:
v_27728:
    v_27791 = qvalue(elt(env, 1)); // freevars
    stack[0] = v_27791;
v_27753:
    v_27791 = stack[0];
    if (v_27791 == nil) goto v_27757;
    else goto v_27758;
v_27757:
    goto v_27752;
v_27758:
    v_27791 = stack[0];
    v_27791 = qcar(v_27791);
    fn = elt(env, 16); // restorenv
    v_27791 = (*qfn1(fn))(fn, v_27791);
    env = stack[-5];
    v_27791 = stack[0];
    v_27791 = qcdr(v_27791);
    stack[0] = v_27791;
    goto v_27753;
v_27752:
    v_27791 = stack[-4];
    if (v_27791 == nil) goto v_27771;
    goto v_27781;
v_27777:
    v_27792 = qvalue(elt(env, 3)); // rpt
    goto v_27778;
v_27779:
    v_27791 = elt(env, 4); // inf
    goto v_27780;
v_27781:
    goto v_27777;
v_27778:
    goto v_27779;
v_27780:
    if (v_27792 == v_27791) goto v_27776;
    v_27791 = qvalue(elt(env, 3)); // rpt
    v_27791 = sub1(v_27791);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_27791; // rpt
    goto v_27774;
v_27776:
v_27774:
    v_27791 = stack[-4];
    fn = elt(env, 15); // embed!-null!-fn
    v_27791 = (*qfn1(fn))(fn, v_27791);
    goto v_27769;
v_27771:
    v_27791 = stack[-3];
    goto v_27769;
    v_27791 = nil;
v_27769:
v_27613:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_27791);
}



// Code for endmodule

static LispObject CC_endmodule(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27624;
    LispObject fn;
    argcheck(nargs, 0, "endmodule");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
    stack_popper stack_popper_var(1);
// end of prologue
    v_27624 = qvalue(elt(env, 1)); // mode!-list!*
    if (v_27624 == nil) goto v_27611;
    else goto v_27612;
v_27611:
    v_27624 = elt(env, 2); // "ENDMODULE called outside module"
    fn = elt(env, 7); // rederr
    v_27624 = (*qfn1(fn))(fn, v_27624);
    env = stack[0];
    goto v_27610;
v_27612:
v_27610:
    v_27624 = nil;
    qvalue(elt(env, 3)) = v_27624; // exportslist!*
    v_27624 = nil;
    qvalue(elt(env, 4)) = v_27624; // importslist!*
    v_27624 = nil;
    v_27624 = ncons(v_27624);
    env = stack[0];
    qvalue(elt(env, 5)) = v_27624; // alglist!*
    v_27624 = qvalue(elt(env, 1)); // mode!-list!*
    v_27624 = qcar(v_27624);
    qvalue(elt(env, 6)) = v_27624; // !*mode
    v_27624 = qvalue(elt(env, 1)); // mode!-list!*
    v_27624 = qcdr(v_27624);
    qvalue(elt(env, 1)) = v_27624; // mode!-list!*
    v_27624 = nil;
    return onevalue(v_27624);
}



// Code for mkprec

static LispObject CC_mkprec(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27715, v_27716, v_27717;
    argcheck(nargs, 0, "mkprec");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// end of prologue
    goto v_27618;
v_27614:
    v_27716 = qvalue(elt(env, 1)); // fixedpreclis!*
    goto v_27615;
v_27616:
    v_27715 = qvalue(elt(env, 2)); // preclis!*
    goto v_27617;
v_27618:
    goto v_27614;
v_27615:
    goto v_27616;
v_27617:
    v_27715 = Lappend(nil, v_27716, v_27715);
    env = stack[-4];
    stack[-3] = v_27715;
    v_27715 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_27715;
v_27612:
    v_27715 = stack[-3];
    if (v_27715 == nil) goto v_27624;
    else goto v_27625;
v_27624:
    v_27715 = nil;
    goto v_27611;
v_27625:
    goto v_27635;
v_27629:
    v_27715 = stack[-3];
    v_27717 = qcar(v_27715);
    goto v_27630;
v_27631:
    v_27716 = elt(env, 3); // infix
    goto v_27632;
v_27633:
    v_27715 = stack[-2];
    goto v_27634;
v_27635:
    goto v_27629;
v_27630:
    goto v_27631;
v_27632:
    goto v_27633;
v_27634:
    v_27715 = Lputprop(nil, 3, v_27717, v_27716, v_27715);
    env = stack[-4];
    goto v_27647;
v_27641:
    v_27715 = stack[-3];
    stack[-1] = qcar(v_27715);
    goto v_27642;
v_27643:
    stack[0] = elt(env, 4); // op
    goto v_27644;
v_27645:
    goto v_27657;
v_27653:
    v_27716 = stack[-2];
    goto v_27654;
v_27655:
    v_27715 = stack[-2];
    goto v_27656;
v_27657:
    goto v_27653;
v_27654:
    goto v_27655;
v_27656:
    v_27715 = list2(v_27716, v_27715);
    env = stack[-4];
    v_27715 = ncons(v_27715);
    env = stack[-4];
    goto v_27646;
v_27647:
    goto v_27641;
v_27642:
    goto v_27643;
v_27644:
    goto v_27645;
v_27646:
    v_27715 = Lputprop(nil, 3, stack[-1], stack[0], v_27715);
    env = stack[-4];
    goto v_27669;
v_27665:
    v_27715 = stack[-3];
    v_27716 = qcar(v_27715);
    goto v_27666;
v_27667:
    v_27715 = elt(env, 5); // unary
    goto v_27668;
v_27669:
    goto v_27665;
v_27666:
    goto v_27667;
v_27668:
    v_27715 = get(v_27716, v_27715);
    env = stack[-4];
    stack[0] = v_27715;
    if (v_27715 == nil) goto v_27663;
    goto v_27680;
v_27674:
    v_27717 = stack[0];
    goto v_27675;
v_27676:
    v_27716 = elt(env, 3); // infix
    goto v_27677;
v_27678:
    v_27715 = stack[-2];
    goto v_27679;
v_27680:
    goto v_27674;
v_27675:
    goto v_27676;
v_27677:
    goto v_27678;
v_27679:
    v_27715 = Lputprop(nil, 3, v_27717, v_27716, v_27715);
    env = stack[-4];
    goto v_27661;
v_27663:
v_27661:
    v_27715 = stack[0];
    if (v_27715 == nil) goto v_27687;
    v_27715 = stack[0];
    if (!symbolp(v_27715)) v_27715 = nil;
    else { v_27715 = qfastgets(v_27715);
           if (v_27715 != nil) { v_27715 = elt(v_27715, 35); // nary
#ifdef RECORD_GET
             if (v_27715 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v_27715 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v_27715 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v_27715 == SPID_NOPROP) v_27715 = nil; else v_27715 = lisp_true; }}
#endif
    if (v_27715 == nil) goto v_27690;
    else goto v_27687;
v_27690:
    goto v_27700;
v_27694:
    stack[-1] = stack[0];
    goto v_27695;
v_27696:
    stack[0] = elt(env, 4); // op
    goto v_27697;
v_27698:
    goto v_27708;
v_27704:
    v_27716 = nil;
    goto v_27705;
v_27706:
    v_27715 = stack[-2];
    goto v_27707;
v_27708:
    goto v_27704;
v_27705:
    goto v_27706;
v_27707:
    v_27715 = list2(v_27716, v_27715);
    env = stack[-4];
    goto v_27699;
v_27700:
    goto v_27694;
v_27695:
    goto v_27696;
v_27697:
    goto v_27698;
v_27699:
    v_27715 = Lputprop(nil, 3, stack[-1], stack[0], v_27715);
    env = stack[-4];
    goto v_27685;
v_27687:
v_27685:
    v_27715 = stack[-3];
    v_27715 = qcdr(v_27715);
    stack[-3] = v_27715;
    v_27715 = stack[-2];
    v_27715 = add1(v_27715);
    env = stack[-4];
    stack[-2] = v_27715;
    goto v_27612;
v_27611:
    return onevalue(v_27715);
}



// Code for ordpl

static LispObject CC_ordpl(LispObject env,
                         LispObject v_27606, LispObject v_27607)
{
    env = qenv(env);
    LispObject v_27656, v_27657, v_27658, v_27659;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27657 = v_27607;
    v_27658 = v_27606;
// end of prologue
v_27611:
    v_27656 = v_27658;
    if (!consp(v_27656)) goto v_27614;
    else goto v_27615;
v_27614:
    goto v_27622;
v_27618:
    v_27656 = v_27658;
    goto v_27619;
v_27620:
    goto v_27621;
v_27622:
    goto v_27618;
v_27619:
    goto v_27620;
v_27621:
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_27656, v_27657);
    }
v_27615:
    v_27656 = v_27657;
    if (!consp(v_27656)) goto v_27625;
    else goto v_27626;
v_27625:
    v_27656 = lisp_true;
    goto v_27610;
v_27626:
    goto v_27635;
v_27631:
    v_27656 = v_27658;
    v_27659 = qcar(v_27656);
    goto v_27632;
v_27633:
    v_27656 = v_27657;
    v_27656 = qcar(v_27656);
    goto v_27634;
v_27635:
    goto v_27631;
v_27632:
    goto v_27633;
v_27634:
    if (equal(v_27659, v_27656)) goto v_27629;
    else goto v_27630;
v_27629:
    v_27656 = v_27658;
    v_27656 = qcdr(v_27656);
    v_27658 = v_27656;
    v_27656 = v_27657;
    v_27656 = qcdr(v_27656);
    v_27657 = v_27656;
    goto v_27611;
v_27630:
    goto v_27651;
v_27647:
    v_27656 = v_27658;
    v_27656 = qcar(v_27656);
    goto v_27648;
v_27649:
    v_27657 = qcar(v_27657);
    goto v_27650;
v_27651:
    goto v_27647;
v_27648:
    goto v_27649;
v_27650:
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_27656, v_27657);
    }
    v_27656 = nil;
v_27610:
    return onevalue(v_27656);
}



// Code for setmatelem

static LispObject CC_setmatelem(LispObject env,
                         LispObject v_27606, LispObject v_27607)
{
    env = qenv(env);
    LispObject v_27792, v_27793, v_27794;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27606,v_27607);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_27607;
    stack[-3] = v_27606;
// end of prologue
    goto v_27621;
v_27617:
    v_27792 = stack[-3];
    v_27793 = Llength(nil, v_27792);
    env = stack[-5];
    goto v_27618;
v_27619:
    v_27792 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_27620;
v_27621:
    goto v_27617;
v_27618:
    goto v_27619;
v_27620:
    if (v_27793 == v_27792) goto v_27616;
    goto v_27630;
v_27626:
    v_27793 = stack[-3];
    goto v_27627;
v_27628:
    v_27792 = elt(env, 1); // "matrix element"
    goto v_27629;
v_27630:
    goto v_27626;
v_27627:
    goto v_27628;
v_27629:
    fn = elt(env, 8); // typerr
    v_27792 = (*qfn2(fn))(fn, v_27793, v_27792);
    env = stack[-5];
    goto v_27614;
v_27616:
v_27614:
    v_27792 = stack[-3];
    v_27792 = qcar(v_27792);
    if (!symbolp(v_27792)) v_27792 = nil;
    else { v_27792 = qfastgets(v_27792);
           if (v_27792 != nil) { v_27792 = elt(v_27792, 4); // avalue
#ifdef RECORD_GET
             if (v_27792 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_27792 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_27792 == SPID_NOPROP) v_27792 = nil; }}
#endif
    stack[-4] = v_27792;
    v_27792 = stack[-4];
    if (v_27792 == nil) goto v_27642;
    else goto v_27643;
v_27642:
    v_27792 = lisp_true;
    goto v_27641;
v_27643:
    goto v_27652;
v_27648:
    v_27792 = stack[-4];
    v_27793 = qcar(v_27792);
    goto v_27649;
v_27650:
    v_27792 = elt(env, 2); // matrix
    goto v_27651;
v_27652:
    goto v_27648;
v_27649:
    goto v_27650;
v_27651:
    v_27792 = (v_27793 == v_27792 ? lisp_true : nil);
    v_27792 = (v_27792 == nil ? lisp_true : nil);
    goto v_27641;
    v_27792 = nil;
v_27641:
    if (v_27792 == nil) goto v_27639;
    goto v_27663;
v_27659:
    v_27792 = stack[-3];
    v_27793 = qcar(v_27792);
    goto v_27660;
v_27661:
    v_27792 = elt(env, 3); // "matrix"
    goto v_27662;
v_27663:
    goto v_27659;
v_27660:
    goto v_27661;
v_27662:
    fn = elt(env, 8); // typerr
    v_27792 = (*qfn2(fn))(fn, v_27793, v_27792);
    env = stack[-5];
    goto v_27637;
v_27639:
    goto v_27674;
v_27670:
    v_27792 = stack[-4];
    v_27792 = qcdr(v_27792);
    v_27793 = qcar(v_27792);
    stack[-4] = v_27793;
    goto v_27671;
v_27672:
    v_27792 = elt(env, 4); // mat
    goto v_27673;
v_27674:
    goto v_27670;
v_27671:
    goto v_27672;
v_27673:
    if (!consp(v_27793)) goto v_27667;
    v_27793 = qcar(v_27793);
    if (v_27793 == v_27792) goto v_27668;
v_27667:
    goto v_27686;
v_27680:
    stack[-1] = elt(env, 2); // matrix
    goto v_27681;
v_27682:
    stack[0] = (LispObject)160+TAG_FIXNUM; // 10
    goto v_27683;
v_27684:
    goto v_27696;
v_27690:
    v_27794 = elt(env, 5); // "Matrix"
    goto v_27691;
v_27692:
    v_27792 = stack[-3];
    v_27793 = qcar(v_27792);
    goto v_27693;
v_27694:
    v_27792 = elt(env, 6); // "not set"
    goto v_27695;
v_27696:
    goto v_27690;
v_27691:
    goto v_27692;
v_27693:
    goto v_27694;
v_27695:
    v_27792 = list3(v_27794, v_27793, v_27792);
    env = stack[-5];
    goto v_27685;
v_27686:
    goto v_27680;
v_27681:
    goto v_27682;
v_27683:
    goto v_27684;
v_27685:
    fn = elt(env, 9); // rerror
    v_27792 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_27792);
    env = stack[-5];
    goto v_27637;
v_27668:
v_27637:
    v_27792 = stack[-3];
    v_27792 = qcdr(v_27792);
    v_27792 = qcar(v_27792);
    fn = elt(env, 10); // reval_without_mod
    v_27792 = (*qfn1(fn))(fn, v_27792);
    env = stack[-5];
    stack[0] = v_27792;
    v_27792 = stack[0];
    v_27792 = integerp(v_27792);
    if (v_27792 == nil) goto v_27711;
    else goto v_27712;
v_27711:
    v_27792 = lisp_true;
    goto v_27710;
v_27712:
    goto v_27723;
v_27719:
    v_27793 = stack[0];
    goto v_27720;
v_27721:
    v_27792 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27722;
v_27723:
    goto v_27719;
v_27720:
    goto v_27721;
v_27722:
    v_27792 = (LispObject)lesseq2(v_27793, v_27792);
    v_27792 = v_27792 ? lisp_true : nil;
    env = stack[-5];
    goto v_27710;
    v_27792 = nil;
v_27710:
    if (v_27792 == nil) goto v_27708;
    goto v_27731;
v_27727:
    v_27793 = stack[0];
    goto v_27728;
v_27729:
    v_27792 = elt(env, 7); // "positive integer"
    goto v_27730;
v_27731:
    goto v_27727;
v_27728:
    goto v_27729;
v_27730:
    fn = elt(env, 8); // typerr
    v_27792 = (*qfn2(fn))(fn, v_27793, v_27792);
    env = stack[-5];
    goto v_27706;
v_27708:
v_27706:
    goto v_27739;
v_27735:
    v_27792 = stack[-4];
    v_27793 = qcdr(v_27792);
    goto v_27736;
v_27737:
    v_27792 = stack[0];
    goto v_27738;
v_27739:
    goto v_27735;
v_27736:
    goto v_27737;
v_27738:
    fn = elt(env, 11); // nth
    v_27792 = (*qfn2(fn))(fn, v_27793, v_27792);
    env = stack[-5];
    stack[-4] = v_27792;
    v_27792 = stack[-3];
    v_27792 = qcdr(v_27792);
    v_27792 = qcdr(v_27792);
    v_27792 = qcar(v_27792);
    fn = elt(env, 10); // reval_without_mod
    v_27792 = (*qfn1(fn))(fn, v_27792);
    env = stack[-5];
    stack[0] = v_27792;
    v_27792 = stack[0];
    v_27792 = integerp(v_27792);
    if (v_27792 == nil) goto v_27754;
    else goto v_27755;
v_27754:
    v_27792 = lisp_true;
    goto v_27753;
v_27755:
    goto v_27766;
v_27762:
    v_27793 = stack[0];
    goto v_27763;
v_27764:
    v_27792 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27765;
v_27766:
    goto v_27762;
v_27763:
    goto v_27764;
v_27765:
    v_27792 = (LispObject)lesseq2(v_27793, v_27792);
    v_27792 = v_27792 ? lisp_true : nil;
    env = stack[-5];
    goto v_27753;
    v_27792 = nil;
v_27753:
    if (v_27792 == nil) goto v_27751;
    goto v_27774;
v_27770:
    v_27793 = stack[0];
    goto v_27771;
v_27772:
    v_27792 = elt(env, 7); // "positive integer"
    goto v_27773;
v_27774:
    goto v_27770;
v_27771:
    goto v_27772;
v_27773:
    fn = elt(env, 8); // typerr
    v_27792 = (*qfn2(fn))(fn, v_27793, v_27792);
    env = stack[-5];
    goto v_27749;
v_27751:
v_27749:
    goto v_27782;
v_27778:
    goto v_27788;
v_27784:
    v_27793 = stack[-4];
    goto v_27785;
v_27786:
    v_27792 = stack[0];
    goto v_27787;
v_27788:
    goto v_27784;
v_27785:
    goto v_27786;
v_27787:
    fn = elt(env, 12); // pnth
    v_27793 = (*qfn2(fn))(fn, v_27793, v_27792);
    goto v_27779;
v_27780:
    v_27792 = stack[-2];
    goto v_27781;
v_27782:
    goto v_27778;
v_27779:
    goto v_27780;
v_27781:
        return Lrplaca(nil, v_27793, v_27792);
    return onevalue(v_27792);
}



// Code for rfirst

static LispObject CC_rfirst(LispObject env,
                         LispObject v_27606)
{
    env = qenv(env);
    LispObject v_27676, v_27677, v_27678;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27606);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27606;
// end of prologue
    v_27676 = stack[0];
    v_27676 = qcar(v_27676);
    fn = elt(env, 3); // reval
    v_27676 = (*qfn1(fn))(fn, v_27676);
    env = stack[-1];
    stack[0] = v_27676;
    fn = elt(env, 4); // bagp
    v_27676 = (*qfn1(fn))(fn, v_27676);
    env = stack[-1];
    if (v_27676 == nil) goto v_27611;
    v_27676 = stack[0];
    v_27676 = qcdr(v_27676);
    if (v_27676 == nil) goto v_27618;
    else goto v_27619;
v_27618:
    v_27676 = stack[0];
    v_27676 = qcar(v_27676);
    return ncons(v_27676);
v_27619:
    goto v_27634;
v_27628:
    v_27676 = stack[0];
    v_27678 = qcar(v_27676);
    goto v_27629;
v_27630:
    v_27676 = stack[0];
    v_27676 = qcdr(v_27676);
    v_27677 = qcar(v_27676);
    goto v_27631;
v_27632:
    v_27676 = nil;
    goto v_27633;
v_27634:
    goto v_27628;
v_27629:
    goto v_27630;
v_27631:
    goto v_27632;
v_27633:
    return list2star(v_27678, v_27677, v_27676);
    v_27676 = nil;
    goto v_27609;
v_27611:
    goto v_27647;
v_27643:
    v_27676 = stack[0];
    v_27677 = qcar(v_27676);
    goto v_27644;
v_27645:
    v_27676 = elt(env, 1); // list
    goto v_27646;
v_27647:
    goto v_27643;
v_27644:
    goto v_27645;
v_27646:
    if (v_27677 == v_27676) goto v_27642;
    goto v_27656;
v_27652:
    v_27677 = stack[0];
    goto v_27653;
v_27654:
    v_27676 = elt(env, 2); // "list or bag"
    goto v_27655;
v_27656:
    goto v_27652;
v_27653:
    goto v_27654;
v_27655:
    {
        fn = elt(env, 5); // typerr
        return (*qfn2(fn))(fn, v_27677, v_27676);
    }
v_27642:
    v_27676 = stack[0];
    v_27676 = qcdr(v_27676);
    if (v_27676 == nil) goto v_27659;
    else goto v_27660;
v_27659:
    goto v_27668;
v_27664:
    v_27677 = stack[0];
    goto v_27665;
v_27666:
    v_27676 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27667;
v_27668:
    goto v_27664;
v_27665:
    goto v_27666;
v_27667:
    {
        fn = elt(env, 6); // parterr
        return (*qfn2(fn))(fn, v_27677, v_27676);
    }
v_27660:
    v_27676 = stack[0];
    v_27676 = qcdr(v_27676);
    v_27676 = qcar(v_27676);
    goto v_27609;
    v_27676 = nil;
v_27609:
    return onevalue(v_27676);
}



// Code for mv2sf

static LispObject CC_mv2sf(LispObject env,
                         LispObject v_27606, LispObject v_27607)
{
    env = qenv(env);
    LispObject v_27663, v_27664, v_27665;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27606,v_27607);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27607;
    stack[-1] = v_27606;
// end of prologue
    stack[-2] = nil;
v_27613:
    v_27663 = stack[-1];
    if (v_27663 == nil) goto v_27618;
    else goto v_27619;
v_27618:
    goto v_27614;
v_27619:
    goto v_27626;
v_27622:
    goto v_27634;
v_27628:
    v_27663 = stack[-1];
    v_27663 = qcar(v_27663);
    v_27665 = qcar(v_27663);
    goto v_27629;
v_27630:
    v_27663 = stack[-1];
    v_27663 = qcar(v_27663);
    v_27664 = qcdr(v_27663);
    goto v_27631;
v_27632:
    v_27663 = stack[0];
    goto v_27633;
v_27634:
    goto v_27628;
v_27629:
    goto v_27630;
v_27631:
    goto v_27632;
v_27633:
    fn = elt(env, 1); // mv2sf1
    v_27664 = (*qfnn(fn))(fn, 3, v_27665, v_27664, v_27663);
    env = stack[-3];
    goto v_27623;
v_27624:
    v_27663 = stack[-2];
    goto v_27625;
v_27626:
    goto v_27622;
v_27623:
    goto v_27624;
v_27625:
    v_27663 = cons(v_27664, v_27663);
    env = stack[-3];
    stack[-2] = v_27663;
    v_27663 = stack[-1];
    v_27663 = qcdr(v_27663);
    stack[-1] = v_27663;
    goto v_27613;
v_27614:
    v_27663 = nil;
    v_27664 = v_27663;
v_27615:
    v_27663 = stack[-2];
    if (v_27663 == nil) goto v_27648;
    else goto v_27649;
v_27648:
    v_27663 = v_27664;
    goto v_27612;
v_27649:
    goto v_27657;
v_27653:
    v_27663 = stack[-2];
    v_27663 = qcar(v_27663);
    goto v_27654;
v_27655:
    goto v_27656;
v_27657:
    goto v_27653;
v_27654:
    goto v_27655;
v_27656:
    fn = elt(env, 2); // addf
    v_27663 = (*qfn2(fn))(fn, v_27663, v_27664);
    env = stack[-3];
    v_27664 = v_27663;
    v_27663 = stack[-2];
    v_27663 = qcdr(v_27663);
    stack[-2] = v_27663;
    goto v_27615;
v_27612:
    return onevalue(v_27663);
}



// Code for nodum_varp

static LispObject CC_nodum_varp(LispObject env,
                         LispObject v_27606)
{
    env = qenv(env);
    LispObject v_27661, v_27662;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27606);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27606;
// end of prologue
    v_27661 = stack[0];
    fn = elt(env, 4); // listp
    v_27661 = (*qfn1(fn))(fn, v_27661);
    env = stack[-1];
    if (v_27661 == nil) goto v_27611;
    v_27661 = lisp_true;
    goto v_27609;
v_27611:
    v_27661 = stack[0];
    if (!symbolp(v_27661)) v_27661 = nil;
    else { v_27661 = qfastgets(v_27661);
           if (v_27661 != nil) { v_27661 = elt(v_27661, 32); // dummy
#ifdef RECORD_GET
             if (v_27661 == SPID_NOPROP)
                record_get(elt(fastget_names, 32), 0),
                v_27661 = nil;
             else record_get(elt(fastget_names, 32), 1),
                v_27661 = lisp_true; }
           else record_get(elt(fastget_names, 32), 0); }
#else
             if (v_27661 == SPID_NOPROP) v_27661 = nil; else v_27661 = lisp_true; }}
#endif
    if (v_27661 == nil) goto v_27620;
    v_27661 = lisp_true;
    goto v_27618;
v_27620:
    goto v_27634;
v_27630:
    v_27661 = stack[0];
    fn = elt(env, 5); // ad_splitname
    v_27661 = (*qfn1(fn))(fn, v_27661);
    env = stack[-1];
    v_27662 = qcar(v_27661);
    goto v_27631;
v_27632:
    v_27661 = qvalue(elt(env, 1)); // g_dvbase
    goto v_27633;
v_27634:
    goto v_27630;
v_27631:
    goto v_27632;
v_27633:
    if (equal(v_27662, v_27661)) goto v_27628;
    else goto v_27629;
v_27628:
    v_27661 = lisp_true;
    goto v_27627;
v_27629:
    goto v_27646;
v_27642:
    goto v_27643;
v_27644:
    goto v_27653;
v_27649:
    v_27662 = elt(env, 2); // !~dv
    goto v_27650;
v_27651:
    v_27661 = elt(env, 3); // !~dva
    goto v_27652;
v_27653:
    goto v_27649;
v_27650:
    goto v_27651;
v_27652:
    v_27661 = list2(v_27662, v_27661);
    goto v_27645;
v_27646:
    goto v_27642;
v_27643:
    goto v_27644;
v_27645:
    v_27661 = Lmember(nil, stack[0], v_27661);
    goto v_27627;
    v_27661 = nil;
v_27627:
    goto v_27618;
    v_27661 = nil;
v_27618:
    if (v_27661 == nil) goto v_27616;
    v_27661 = nil;
    goto v_27609;
v_27616:
    v_27661 = lisp_true;
    goto v_27609;
    v_27661 = nil;
v_27609:
    return onevalue(v_27661);
}



// Code for polynomlistautoreduce

static LispObject CC_polynomlistautoreduce(LispObject env,
                         LispObject v_27606, LispObject v_27607)
{
    env = qenv(env);
    LispObject v_27817, v_27818, v_27819;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27606,v_27607);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_27607;
    stack[-4] = v_27606;
// end of prologue
    v_27817 = nil;
    v_27817 = ncons(v_27817);
    env = stack[-6];
    stack[-5] = v_27817;
v_27619:
    v_27817 = stack[-4];
    v_27817 = qcar(v_27817);
    if (v_27817 == nil) goto v_27622;
    else goto v_27623;
v_27622:
    goto v_27618;
v_27623:
    goto v_27634;
v_27628:
    v_27819 = stack[-5];
    goto v_27629;
v_27630:
    v_27817 = stack[-4];
    v_27818 = qcar(v_27817);
    goto v_27631;
v_27632:
    v_27817 = stack[-3];
    goto v_27633;
v_27634:
    goto v_27628;
v_27629:
    goto v_27630;
v_27631:
    goto v_27632;
v_27633:
    fn = elt(env, 1); // polynomlistreduce
    v_27817 = (*qfnn(fn))(fn, 3, v_27819, v_27818, v_27817);
    env = stack[-6];
    stack[-2] = v_27817;
    goto v_27644;
v_27640:
    goto v_27650;
v_27646:
    v_27818 = stack[-4];
    goto v_27647;
v_27648:
    v_27817 = stack[-4];
    v_27817 = qcdr(v_27817);
    v_27817 = qcar(v_27817);
    goto v_27649;
v_27650:
    goto v_27646;
v_27647:
    goto v_27648;
v_27649:
    v_27818 = Lrplaca(nil, v_27818, v_27817);
    env = stack[-6];
    goto v_27641;
v_27642:
    v_27817 = stack[-4];
    v_27817 = qcdr(v_27817);
    v_27817 = qcdr(v_27817);
    goto v_27643;
v_27644:
    goto v_27640;
v_27641:
    goto v_27642;
v_27643:
    v_27817 = Lrplacd(nil, v_27818, v_27817);
    env = stack[-6];
    v_27817 = stack[-2];
    v_27817 = qcar(v_27817);
    if (v_27817 == nil) goto v_27661;
    v_27817 = stack[-2];
    v_27817 = qcar(v_27817);
    stack[-1] = v_27817;
    v_27817 = stack[-5];
    stack[0] = v_27817;
v_27669:
    v_27817 = stack[0];
    v_27817 = qcar(v_27817);
    if (v_27817 == nil) goto v_27672;
    else goto v_27673;
v_27672:
    goto v_27668;
v_27673:
    goto v_27686;
v_27682:
    v_27817 = stack[0];
    v_27817 = qcar(v_27817);
    v_27818 = qcar(v_27817);
    goto v_27683;
v_27684:
    v_27817 = stack[-1];
    goto v_27685;
v_27686:
    goto v_27682;
v_27683:
    goto v_27684;
v_27685:
    fn = elt(env, 2); // monomisdivisibleby
    v_27817 = (*qfn2(fn))(fn, v_27818, v_27817);
    env = stack[-6];
    if (v_27817 == nil) goto v_27680;
    goto v_27696;
v_27692:
    v_27818 = stack[-4];
    goto v_27693;
v_27694:
    v_27817 = stack[0];
    v_27817 = qcar(v_27817);
    goto v_27695;
v_27696:
    goto v_27692;
v_27693:
    goto v_27694;
v_27695:
    fn = elt(env, 3); // pushback
    v_27817 = (*qfn2(fn))(fn, v_27818, v_27817);
    env = stack[-6];
    goto v_27705;
v_27701:
    goto v_27711;
v_27707:
    v_27818 = stack[0];
    goto v_27708;
v_27709:
    v_27817 = stack[0];
    v_27817 = qcdr(v_27817);
    v_27817 = qcar(v_27817);
    goto v_27710;
v_27711:
    goto v_27707;
v_27708:
    goto v_27709;
v_27710:
    v_27818 = Lrplaca(nil, v_27818, v_27817);
    env = stack[-6];
    goto v_27702;
v_27703:
    v_27817 = stack[0];
    v_27817 = qcdr(v_27817);
    v_27817 = qcdr(v_27817);
    goto v_27704;
v_27705:
    goto v_27701;
v_27702:
    goto v_27703;
v_27704:
    v_27817 = Lrplacd(nil, v_27818, v_27817);
    env = stack[-6];
    goto v_27678;
v_27680:
    v_27817 = stack[0];
    v_27817 = qcdr(v_27817);
    stack[0] = v_27817;
    goto v_27678;
v_27678:
    goto v_27669;
v_27668:
    goto v_27731;
v_27727:
    v_27818 = stack[-5];
    goto v_27728;
v_27729:
    v_27817 = stack[-2];
    goto v_27730;
v_27731:
    goto v_27727;
v_27728:
    goto v_27729;
v_27730:
    fn = elt(env, 3); // pushback
    v_27817 = (*qfn2(fn))(fn, v_27818, v_27817);
    env = stack[-6];
    goto v_27659;
v_27661:
v_27659:
    goto v_27619;
v_27618:
    v_27817 = stack[-5];
    stack[0] = v_27817;
v_27739:
    v_27817 = stack[0];
    v_27817 = qcar(v_27817);
    if (v_27817 == nil) goto v_27742;
    else goto v_27743;
v_27742:
    goto v_27738;
v_27743:
    v_27817 = stack[0];
    v_27817 = qcar(v_27817);
    stack[-2] = v_27817;
    goto v_27754;
v_27750:
    goto v_27760;
v_27756:
    v_27818 = stack[0];
    goto v_27757;
v_27758:
    v_27817 = stack[0];
    v_27817 = qcdr(v_27817);
    v_27817 = qcar(v_27817);
    goto v_27759;
v_27760:
    goto v_27756;
v_27757:
    goto v_27758;
v_27759:
    v_27818 = Lrplaca(nil, v_27818, v_27817);
    env = stack[-6];
    goto v_27751;
v_27752:
    v_27817 = stack[0];
    v_27817 = qcdr(v_27817);
    v_27817 = qcdr(v_27817);
    goto v_27753;
v_27754:
    goto v_27750;
v_27751:
    goto v_27752;
v_27753:
    v_27817 = Lrplacd(nil, v_27818, v_27817);
    env = stack[-6];
    goto v_27775;
v_27769:
    v_27819 = stack[-5];
    goto v_27770;
v_27771:
    v_27818 = stack[-2];
    goto v_27772;
v_27773:
    v_27817 = stack[-3];
    goto v_27774;
v_27775:
    goto v_27769;
v_27770:
    goto v_27771;
v_27772:
    goto v_27773;
v_27774:
    fn = elt(env, 1); // polynomlistreduce
    v_27817 = (*qfnn(fn))(fn, 3, v_27819, v_27818, v_27817);
    env = stack[-6];
    stack[-2] = v_27817;
    v_27817 = stack[-2];
    if (v_27817 == nil) goto v_27782;
    v_27817 = stack[-2];
    v_27817 = qcar(v_27817);
    if (v_27817 == nil) goto v_27782;
    goto v_27793;
v_27789:
    goto v_27799;
v_27795:
    stack[-1] = stack[0];
    goto v_27796;
v_27797:
    goto v_27806;
v_27802:
    v_27817 = stack[0];
    v_27818 = qcar(v_27817);
    goto v_27803;
v_27804:
    v_27817 = stack[0];
    v_27817 = qcdr(v_27817);
    goto v_27805;
v_27806:
    goto v_27802;
v_27803:
    goto v_27804;
v_27805:
    v_27817 = cons(v_27818, v_27817);
    env = stack[-6];
    goto v_27798;
v_27799:
    goto v_27795;
v_27796:
    goto v_27797;
v_27798:
    v_27818 = Lrplacd(nil, stack[-1], v_27817);
    env = stack[-6];
    goto v_27790;
v_27791:
    v_27817 = stack[-2];
    goto v_27792;
v_27793:
    goto v_27789;
v_27790:
    goto v_27791;
v_27792:
    v_27817 = Lrplaca(nil, v_27818, v_27817);
    env = stack[-6];
    v_27817 = stack[0];
    v_27817 = qcdr(v_27817);
    stack[0] = v_27817;
    goto v_27780;
v_27782:
v_27780:
    goto v_27739;
v_27738:
    v_27817 = stack[-5];
    return onevalue(v_27817);
}



// Code for talp_simplatlinv

static LispObject CC_talp_simplatlinv(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27643, v_27644, v_27645;
    LispObject fn;
    LispObject v_27608, v_27607, v_27606;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_simplatlinv");
    va_start(aa, nargs);
    v_27606 = va_arg(aa, LispObject);
    v_27607 = va_arg(aa, LispObject);
    v_27608 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27608,v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27606,v_27607,v_27608);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27608;
    stack[-1] = v_27607;
    stack[-2] = v_27606;
// end of prologue
    v_27643 = stack[-1];
    fn = elt(env, 1); // talp_simplt
    v_27643 = (*qfn1(fn))(fn, v_27643);
    env = stack[-3];
    stack[-1] = v_27643;
    v_27643 = stack[-1];
    fn = elt(env, 2); // talp_invp
    v_27643 = (*qfn1(fn))(fn, v_27643);
    env = stack[-3];
    if (v_27643 == nil) goto v_27615;
    goto v_27625;
v_27619:
    v_27645 = stack[-2];
    goto v_27620;
v_27621:
    v_27644 = stack[-1];
    goto v_27622;
v_27623:
    v_27643 = stack[0];
    goto v_27624;
v_27625:
    goto v_27619;
v_27620:
    goto v_27621;
v_27622:
    goto v_27623;
v_27624:
    {
        fn = elt(env, 3); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_27645, v_27644, v_27643);
    }
v_27615:
    goto v_27638;
v_27632:
    goto v_27633;
v_27634:
    goto v_27635;
v_27636:
    v_27643 = stack[0];
    fn = elt(env, 1); // talp_simplt
    v_27643 = (*qfn1(fn))(fn, v_27643);
    env = stack[-3];
    goto v_27637;
v_27638:
    goto v_27632;
v_27633:
    goto v_27634;
v_27635:
    goto v_27636;
v_27637:
    {
        LispObject v_27649 = stack[-2];
        LispObject v_27650 = stack[-1];
        fn = elt(env, 4); // talp_simplat2
        return (*qfnn(fn))(fn, 3, v_27649, v_27650, v_27643);
    }
    v_27643 = nil;
    return onevalue(v_27643);
}



// Code for cnml

static LispObject CC_cnml(LispObject env,
                         LispObject v_27606)
{
    env = qenv(env);
    LispObject v_27627, v_27628;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27606);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27606;
// end of prologue
    v_27627 = elt(env, 1); // "<cn"
    fn = elt(env, 4); // printout
    v_27627 = (*qfn1(fn))(fn, v_27627);
    env = stack[-1];
    goto v_27617;
v_27613:
    v_27627 = stack[0];
    v_27628 = qcar(v_27627);
    goto v_27614;
v_27615:
    v_27627 = elt(env, 2); // ""
    goto v_27616;
v_27617:
    goto v_27613;
v_27614:
    goto v_27615;
v_27616:
    fn = elt(env, 5); // attributesml
    v_27627 = (*qfn2(fn))(fn, v_27628, v_27627);
    env = stack[-1];
    v_27627 = stack[0];
    v_27627 = qcdr(v_27627);
    v_27627 = qcar(v_27627);
    v_27627 = Lprinc(nil, v_27627);
    env = stack[-1];
    v_27627 = elt(env, 3); // "</cn>"
    v_27627 = Lprinc(nil, v_27627);
    v_27627 = nil;
    return onevalue(v_27627);
}



// Code for newsym1

static LispObject CC_newsym1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27623, v_27624;
    argcheck(nargs, 0, "newsym1");
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
    v_27623 = qvalue(elt(env, 1)); // cindex!*
    v_27623 = Lexplode(nil, v_27623);
    env = stack[-1];
    stack[0] = v_27623;
    v_27623 = qvalue(elt(env, 1)); // cindex!*
    v_27623 = add1(v_27623);
    env = stack[-1];
    qvalue(elt(env, 1)) = v_27623; // cindex!*
    goto v_27620;
v_27616:
    v_27624 = qvalue(elt(env, 2)); // cname!*
    goto v_27617;
v_27618:
    v_27623 = stack[0];
    goto v_27619;
v_27620:
    goto v_27616;
v_27617:
    goto v_27618;
v_27619:
    v_27623 = Lappend(nil, v_27624, v_27623);
        return Lcompress(nil, v_27623);
    return onevalue(v_27623);
}



// Code for xregister_spoly_pair

static LispObject CC_xregister_spoly_pair(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27608;
    argcheck(nargs, 0, "xregister_spoly_pair");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_27608 = nil;
    return onevalue(v_27608);
}



// Code for evaluate2

static LispObject CC_evaluate2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27804, v_27805, v_27806;
    LispObject fn;
    LispObject v_27608, v_27607, v_27606;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "evaluate2");
    va_start(aa, nargs);
    v_27606 = va_arg(aa, LispObject);
    v_27607 = va_arg(aa, LispObject);
    v_27608 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27608,v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27606,v_27607,v_27608);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_27608;
    v_27805 = v_27607;
    stack[-4] = v_27606;
// end of prologue
    goto v_27618;
v_27614:
    v_27806 = stack[-4];
    goto v_27615;
v_27616:
    v_27804 = elt(env, 1); // !:dn!:
    goto v_27617;
v_27618:
    goto v_27614;
v_27615:
    goto v_27616;
v_27617:
    if (v_27806 == v_27804) goto v_27612;
    else goto v_27613;
v_27612:
    v_27804 = v_27805;
    fn = elt(env, 5); // dn!:simp
    v_27804 = (*qfn1(fn))(fn, v_27804);
    v_27804 = qcar(v_27804);
    goto v_27611;
v_27613:
    v_27804 = v_27805;
    stack[-5] = v_27804;
    v_27804 = stack[-5];
    if (v_27804 == nil) goto v_27637;
    else goto v_27638;
v_27637:
    v_27804 = nil;
    goto v_27632;
v_27638:
    v_27804 = stack[-5];
    v_27804 = qcar(v_27804);
    goto v_27650;
v_27646:
    v_27805 = v_27804;
    goto v_27647;
v_27648:
    v_27804 = stack[-3];
    goto v_27649;
v_27650:
    goto v_27646;
v_27647:
    goto v_27648;
v_27649:
    fn = elt(env, 6); // evaluate1
    v_27804 = (*qfn2(fn))(fn, v_27805, v_27804);
    env = stack[-6];
    v_27804 = ncons(v_27804);
    env = stack[-6];
    stack[-1] = v_27804;
    stack[-2] = v_27804;
v_27633:
    v_27804 = stack[-5];
    v_27804 = qcdr(v_27804);
    stack[-5] = v_27804;
    v_27804 = stack[-5];
    if (v_27804 == nil) goto v_27657;
    else goto v_27658;
v_27657:
    v_27804 = stack[-2];
    goto v_27632;
v_27658:
    goto v_27666;
v_27662:
    stack[0] = stack[-1];
    goto v_27663;
v_27664:
    v_27804 = stack[-5];
    v_27804 = qcar(v_27804);
    goto v_27677;
v_27673:
    v_27805 = v_27804;
    goto v_27674;
v_27675:
    v_27804 = stack[-3];
    goto v_27676;
v_27677:
    goto v_27673;
v_27674:
    goto v_27675;
v_27676:
    fn = elt(env, 6); // evaluate1
    v_27804 = (*qfn2(fn))(fn, v_27805, v_27804);
    env = stack[-6];
    v_27804 = ncons(v_27804);
    env = stack[-6];
    goto v_27665;
v_27666:
    goto v_27662;
v_27663:
    goto v_27664;
v_27665:
    v_27804 = Lrplacd(nil, stack[0], v_27804);
    env = stack[-6];
    v_27804 = stack[-1];
    v_27804 = qcdr(v_27804);
    stack[-1] = v_27804;
    goto v_27633;
v_27632:
    v_27805 = v_27804;
    goto v_27690;
v_27686:
    v_27806 = stack[-4];
    goto v_27687;
v_27688:
    v_27804 = elt(env, 2); // plus
    goto v_27689;
v_27690:
    goto v_27686;
v_27687:
    goto v_27688;
v_27689:
    if (v_27806 == v_27804) goto v_27684;
    else goto v_27685;
v_27684:
    v_27804 = v_27805;
    {
        fn = elt(env, 7); // !:dmpluslst
        return (*qfn1(fn))(fn, v_27804);
    }
v_27685:
    goto v_27701;
v_27697:
    v_27806 = stack[-4];
    goto v_27698;
v_27699:
    v_27804 = elt(env, 3); // times
    goto v_27700;
v_27701:
    goto v_27697;
v_27698:
    goto v_27699;
v_27700:
    if (v_27806 == v_27804) goto v_27695;
    else goto v_27696;
v_27695:
    v_27804 = v_27805;
    {
        fn = elt(env, 8); // !:dmtimeslst
        return (*qfn1(fn))(fn, v_27804);
    }
v_27696:
    goto v_27712;
v_27708:
    v_27806 = stack[-4];
    goto v_27709;
v_27710:
    v_27804 = qvalue(elt(env, 4)); // dmarith!*
    goto v_27711;
v_27712:
    goto v_27708;
v_27709:
    goto v_27710;
v_27711:
    v_27804 = Lassoc(nil, v_27806, v_27804);
    v_27806 = v_27804;
    if (v_27804 == nil) goto v_27707;
    goto v_27721;
v_27717:
    v_27804 = v_27806;
    v_27804 = qcdr(v_27804);
    goto v_27718;
v_27719:
    goto v_27720;
v_27721:
    goto v_27717;
v_27718:
    goto v_27719;
v_27720:
    {
        fn = elt(env, 9); // apply
        return (*qfn2(fn))(fn, v_27804, v_27805);
    }
v_27707:
    v_27804 = v_27805;
    v_27804 = qcar(v_27804);
    v_27804 = Lconsp(nil, v_27804);
    env = stack[-6];
    if (v_27804 == nil) goto v_27726;
    goto v_27737;
v_27733:
    v_27806 = stack[-4];
    goto v_27734;
v_27735:
    v_27804 = v_27805;
    v_27804 = qcar(v_27804);
    v_27804 = qcar(v_27804);
    goto v_27736;
v_27737:
    goto v_27733;
v_27734:
    goto v_27735;
v_27736:
    v_27804 = get(v_27806, v_27804);
    env = stack[-6];
    v_27806 = v_27804;
    if (v_27804 == nil) goto v_27726;
    goto v_27747;
v_27743:
    v_27804 = v_27806;
    goto v_27744;
v_27745:
    goto v_27746;
v_27747:
    goto v_27743;
v_27744:
    goto v_27745;
v_27746:
    {
        fn = elt(env, 9); // apply
        return (*qfn2(fn))(fn, v_27804, v_27805);
    }
v_27726:
    goto v_27759;
v_27755:
    goto v_27756;
v_27757:
    v_27804 = v_27805;
    stack[-3] = v_27804;
    v_27804 = stack[-3];
    if (v_27804 == nil) goto v_27770;
    else goto v_27771;
v_27770:
    v_27804 = nil;
    goto v_27765;
v_27771:
    v_27804 = stack[-3];
    v_27804 = qcar(v_27804);
    fn = elt(env, 10); // prepf
    v_27804 = (*qfn1(fn))(fn, v_27804);
    env = stack[-6];
    v_27804 = ncons(v_27804);
    env = stack[-6];
    stack[-1] = v_27804;
    stack[-2] = v_27804;
v_27766:
    v_27804 = stack[-3];
    v_27804 = qcdr(v_27804);
    stack[-3] = v_27804;
    v_27804 = stack[-3];
    if (v_27804 == nil) goto v_27784;
    else goto v_27785;
v_27784:
    v_27804 = stack[-2];
    goto v_27765;
v_27785:
    goto v_27793;
v_27789:
    stack[0] = stack[-1];
    goto v_27790;
v_27791:
    v_27804 = stack[-3];
    v_27804 = qcar(v_27804);
    fn = elt(env, 10); // prepf
    v_27804 = (*qfn1(fn))(fn, v_27804);
    env = stack[-6];
    v_27804 = ncons(v_27804);
    env = stack[-6];
    goto v_27792;
v_27793:
    goto v_27789;
v_27790:
    goto v_27791;
v_27792:
    v_27804 = Lrplacd(nil, stack[0], v_27804);
    env = stack[-6];
    v_27804 = stack[-1];
    v_27804 = qcdr(v_27804);
    stack[-1] = v_27804;
    goto v_27766;
v_27765:
    goto v_27758;
v_27759:
    goto v_27755;
v_27756:
    goto v_27757;
v_27758:
    v_27804 = cons(stack[-4], v_27804);
    env = stack[-6];
    fn = elt(env, 11); // simp
    v_27804 = (*qfn1(fn))(fn, v_27804);
    env = stack[-6];
    v_27804 = qcar(v_27804);
    {
        fn = elt(env, 12); // force!-to!-dm
        return (*qfn1(fn))(fn, v_27804);
    }
    v_27804 = nil;
    goto v_27611;
    v_27804 = nil;
v_27611:
    return onevalue(v_27804);
}



// Code for mkforttab

static LispObject CC_mkforttab(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27622, v_27623;
    argcheck(nargs, 0, "mkforttab");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// end of prologue
    goto v_27612;
v_27608:
    stack[0] = elt(env, 1); // forttab
    goto v_27609;
v_27610:
    goto v_27619;
v_27615:
    v_27623 = qvalue(elt(env, 2)); // fortcurrind!*
    goto v_27616;
v_27617:
    v_27622 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_27618;
v_27619:
    goto v_27615;
v_27616:
    goto v_27617;
v_27618:
    v_27622 = plus2(v_27623, v_27622);
    goto v_27611;
v_27612:
    goto v_27608;
v_27609:
    goto v_27610;
v_27611:
    {
        LispObject v_27625 = stack[0];
        return list2(v_27625, v_27622);
    }
}



// Code for sign!-abs

static LispObject CC_signKabs(LispObject env,
                         LispObject v_27606)
{
    env = qenv(env);
    LispObject v_27653, v_27654;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27606);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27606;
// end of prologue
    v_27653 = stack[0];
    fn = elt(env, 2); // sign!-of
    v_27653 = (*qfn1(fn))(fn, v_27653);
    env = stack[-2];
    stack[-1] = v_27653;
    v_27653 = stack[-1];
    if (is_number(v_27653)) goto v_27614;
    v_27653 = nil;
    goto v_27612;
v_27614:
    goto v_27629;
v_27625:
    v_27654 = stack[-1];
    goto v_27626;
v_27627:
    v_27653 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27628;
v_27629:
    goto v_27625;
v_27626:
    goto v_27627;
v_27628:
    v_27653 = (LispObject)lessp2(v_27654, v_27653);
    v_27653 = v_27653 ? lisp_true : nil;
    env = stack[-2];
    if (v_27653 == nil) goto v_27623;
    goto v_27637;
v_27633:
    v_27654 = elt(env, 1); // minus
    goto v_27634;
v_27635:
    v_27653 = stack[0];
    goto v_27636;
v_27637:
    goto v_27633;
v_27634:
    goto v_27635;
v_27636:
    v_27653 = list2(v_27654, v_27653);
    env = stack[-2];
    goto v_27621;
v_27623:
    goto v_27646;
v_27642:
    v_27654 = stack[-1];
    goto v_27643;
v_27644:
    v_27653 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27645;
v_27646:
    goto v_27642;
v_27643:
    goto v_27644;
v_27645:
    if (v_27654 == v_27653) goto v_27640;
    else goto v_27641;
v_27640:
    v_27653 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27621;
v_27641:
    v_27653 = stack[0];
    goto v_27621;
    v_27653 = nil;
v_27621:
    {
        fn = elt(env, 3); // simp
        return (*qfn1(fn))(fn, v_27653);
    }
    v_27653 = nil;
v_27612:
    return onevalue(v_27653);
}



// Code for mv!-compact

static LispObject CC_mvKcompact(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27756, v_27757, v_27758;
    LispObject fn;
    LispObject v_27608, v_27607, v_27606;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mv-compact");
    va_start(aa, nargs);
    v_27606 = va_arg(aa, LispObject);
    v_27607 = va_arg(aa, LispObject);
    v_27608 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27608,v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27606,v_27607,v_27608);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_27608;
    stack[-2] = v_27607;
    stack[-3] = v_27606;
// end of prologue
v_27605:
    v_27756 = stack[-3];
    if (v_27756 == nil) goto v_27616;
    else goto v_27617;
v_27616:
    v_27756 = stack[-1];
    {
        fn = elt(env, 1); // mv!-reverse
        return (*qfn1(fn))(fn, v_27756);
    }
v_27617:
    goto v_27631;
v_27627:
    v_27757 = stack[-3];
    goto v_27628;
v_27629:
    v_27756 = stack[-2];
    goto v_27630;
v_27631:
    goto v_27627;
v_27628:
    goto v_27629;
v_27630:
    fn = elt(env, 2); // mv!-pow!-chk
    v_27756 = (*qfn2(fn))(fn, v_27757, v_27756);
    env = stack[-5];
    stack[-4] = v_27756;
    if (v_27756 == nil) goto v_27624;
    goto v_27640;
v_27636:
    stack[0] = stack[-3];
    goto v_27637;
v_27638:
    goto v_27647;
v_27643:
    v_27757 = stack[-4];
    goto v_27644;
v_27645:
    v_27756 = stack[-2];
    goto v_27646;
v_27647:
    goto v_27643;
v_27644:
    goto v_27645;
v_27646:
    fn = elt(env, 3); // mv!-pow!-mv!-!+
    v_27756 = (*qfn2(fn))(fn, v_27757, v_27756);
    env = stack[-5];
    goto v_27639;
v_27640:
    goto v_27636;
v_27637:
    goto v_27638;
v_27639:
    fn = elt(env, 4); // mv!-compact2
    v_27756 = (*qfn2(fn))(fn, stack[0], v_27756);
    env = stack[-5];
    stack[0] = v_27756;
    if (v_27756 == nil) goto v_27624;
    goto v_27657;
v_27651:
    v_27758 = stack[0];
    goto v_27652;
v_27653:
    v_27757 = stack[-2];
    goto v_27654;
v_27655:
    v_27756 = stack[-1];
    goto v_27656;
v_27657:
    goto v_27651;
v_27652:
    goto v_27653;
v_27654:
    goto v_27655;
v_27656:
    stack[-3] = v_27758;
    stack[-2] = v_27757;
    stack[-1] = v_27756;
    goto v_27605;
v_27624:
    goto v_27669;
v_27665:
    v_27757 = stack[-3];
    goto v_27666;
v_27667:
    v_27756 = stack[-2];
    v_27756 = qcdr(v_27756);
    goto v_27668;
v_27669:
    goto v_27665;
v_27666:
    goto v_27667;
v_27668:
    fn = elt(env, 2); // mv!-pow!-chk
    v_27756 = (*qfn2(fn))(fn, v_27757, v_27756);
    env = stack[-5];
    stack[-4] = v_27756;
    if (v_27756 == nil) goto v_27662;
    goto v_27683;
v_27679:
    goto v_27689;
v_27685:
    v_27757 = stack[-4];
    goto v_27686;
v_27687:
    v_27756 = stack[-2];
    v_27756 = qcar(v_27756);
    v_27756 = qcar(v_27756);
    goto v_27688;
v_27689:
    goto v_27685;
v_27686:
    goto v_27687;
v_27688:
    fn = elt(env, 5); // mv!-pow!-!+
    v_27757 = (*qfn2(fn))(fn, v_27757, v_27756);
    env = stack[-5];
    stack[0] = v_27757;
    goto v_27680;
v_27681:
    v_27756 = stack[-1];
    goto v_27682;
v_27683:
    goto v_27679;
v_27680:
    goto v_27681;
v_27682:
    fn = elt(env, 6); // mv!-pow!-assoc
    v_27756 = (*qfn2(fn))(fn, v_27757, v_27756);
    env = stack[-5];
    if (v_27756 == nil) goto v_27676;
    else goto v_27677;
v_27676:
    goto v_27700;
v_27696:
    goto v_27708;
v_27702:
    v_27758 = stack[0];
    goto v_27703;
v_27704:
    v_27757 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27705;
v_27706:
    v_27756 = stack[-3];
    goto v_27707;
v_27708:
    goto v_27702;
v_27703:
    goto v_27704;
v_27705:
    goto v_27706;
v_27707:
    stack[0] = acons(v_27758, v_27757, v_27756);
    env = stack[-5];
    goto v_27697;
v_27698:
    goto v_27717;
v_27713:
    v_27757 = stack[-4];
    goto v_27714;
v_27715:
    v_27756 = stack[-2];
    goto v_27716;
v_27717:
    goto v_27713;
v_27714:
    goto v_27715;
v_27716:
    fn = elt(env, 3); // mv!-pow!-mv!-!+
    v_27756 = (*qfn2(fn))(fn, v_27757, v_27756);
    env = stack[-5];
    goto v_27699;
v_27700:
    goto v_27696;
v_27697:
    goto v_27698;
v_27699:
    fn = elt(env, 4); // mv!-compact2
    v_27756 = (*qfn2(fn))(fn, stack[0], v_27756);
    env = stack[-5];
    stack[0] = v_27756;
    goto v_27675;
v_27677:
    v_27756 = nil;
    goto v_27675;
    v_27756 = nil;
v_27675:
    if (v_27756 == nil) goto v_27662;
    goto v_27730;
v_27724:
    v_27758 = stack[0];
    goto v_27725;
v_27726:
    v_27757 = stack[-2];
    goto v_27727;
v_27728:
    v_27756 = stack[-1];
    goto v_27729;
v_27730:
    goto v_27724;
v_27725:
    goto v_27726;
v_27727:
    goto v_27728;
v_27729:
    stack[-3] = v_27758;
    stack[-2] = v_27757;
    stack[-1] = v_27756;
    goto v_27605;
v_27662:
    goto v_27743;
v_27737:
    v_27756 = stack[-3];
    stack[0] = qcdr(v_27756);
    goto v_27738;
v_27739:
    goto v_27740;
v_27741:
    goto v_27752;
v_27748:
    v_27756 = stack[-3];
    v_27757 = qcar(v_27756);
    goto v_27749;
v_27750:
    v_27756 = stack[-1];
    goto v_27751;
v_27752:
    goto v_27748;
v_27749:
    goto v_27750;
v_27751:
    v_27756 = cons(v_27757, v_27756);
    env = stack[-5];
    goto v_27742;
v_27743:
    goto v_27737;
v_27738:
    goto v_27739;
v_27740:
    goto v_27741;
v_27742:
    stack[-3] = stack[0];
    stack[-1] = v_27756;
    goto v_27605;
    v_27756 = nil;
    return onevalue(v_27756);
}



// Code for simp!-prop

static LispObject CC_simpKprop(LispObject env,
                         LispObject v_27606)
{
    env = qenv(env);
    LispObject v_27826, v_27827, v_27828;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27606);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-2] = v_27606;
// end of prologue
// Binding propvars!*
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
    qvalue(elt(env, 1)) = nil; // propvars!*
    v_27826 = stack[-2];
    v_27826 = qcdr(v_27826);
    stack[-4] = v_27826;
    v_27826 = stack[-4];
    if (v_27826 == nil) goto v_27623;
    else goto v_27624;
v_27623:
    v_27826 = nil;
    goto v_27617;
v_27624:
    v_27826 = stack[-4];
    v_27826 = qcar(v_27826);
    fn = elt(env, 12); // reval
    v_27826 = (*qfn1(fn))(fn, v_27826);
    env = stack[-7];
    v_27826 = ncons(v_27826);
    env = stack[-7];
    stack[-1] = v_27826;
    stack[-3] = v_27826;
v_27618:
    v_27826 = stack[-4];
    v_27826 = qcdr(v_27826);
    stack[-4] = v_27826;
    v_27826 = stack[-4];
    if (v_27826 == nil) goto v_27637;
    else goto v_27638;
v_27637:
    v_27826 = stack[-3];
    goto v_27617;
v_27638:
    goto v_27646;
v_27642:
    stack[0] = stack[-1];
    goto v_27643;
v_27644:
    v_27826 = stack[-4];
    v_27826 = qcar(v_27826);
    fn = elt(env, 12); // reval
    v_27826 = (*qfn1(fn))(fn, v_27826);
    env = stack[-7];
    v_27826 = ncons(v_27826);
    env = stack[-7];
    goto v_27645;
v_27646:
    goto v_27642;
v_27643:
    goto v_27644;
v_27645:
    v_27826 = Lrplacd(nil, stack[0], v_27826);
    env = stack[-7];
    v_27826 = stack[-1];
    v_27826 = qcdr(v_27826);
    stack[-1] = v_27826;
    goto v_27618;
v_27617:
    stack[-5] = v_27826;
    goto v_27664;
v_27660:
    v_27827 = elt(env, 2); // and
    goto v_27661;
v_27662:
    v_27826 = stack[-5];
    goto v_27663;
v_27664:
    goto v_27660;
v_27661:
    goto v_27662;
v_27663:
    v_27826 = Lmember(nil, v_27827, v_27826);
    if (v_27826 == nil) goto v_27659;
    v_27826 = elt(env, 3); // or
    qvalue(elt(env, 4)) = v_27826; // !'and
    v_27826 = elt(env, 2); // and
    qvalue(elt(env, 5)) = v_27826; // !'or
    v_27826 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 6)) = v_27826; // !'true
    v_27826 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 7)) = v_27826; // !'false
    goto v_27657;
v_27659:
    v_27826 = elt(env, 2); // and
    qvalue(elt(env, 4)) = v_27826; // !'and
    v_27826 = elt(env, 3); // or
    qvalue(elt(env, 5)) = v_27826; // !'or
    v_27826 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 6)) = v_27826; // !'true
    v_27826 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 7)) = v_27826; // !'false
    goto v_27657;
v_27657:
    goto v_27687;
v_27683:
    v_27826 = stack[-2];
    v_27827 = qcar(v_27826);
    goto v_27684;
v_27685:
    v_27826 = lisp_true;
    goto v_27686;
v_27687:
    goto v_27683;
v_27684:
    goto v_27685;
v_27686:
    fn = elt(env, 13); // simp!-prop1
    v_27826 = (*qfn2(fn))(fn, v_27827, v_27826);
    env = stack[-7];
    fn = elt(env, 14); // prepf
    v_27826 = (*qfn1(fn))(fn, v_27826);
    env = stack[-7];
    fn = elt(env, 12); // reval
    v_27826 = (*qfn1(fn))(fn, v_27826);
    env = stack[-7];
    v_27828 = v_27826;
    goto v_27699;
v_27695:
    v_27827 = v_27828;
    goto v_27696;
v_27697:
    v_27826 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27698;
v_27699:
    goto v_27695;
v_27696:
    goto v_27697;
v_27698:
    if (v_27827 == v_27826) goto v_27693;
    else goto v_27694;
v_27693:
    v_27826 = qvalue(elt(env, 7)); // !'false
    fn = elt(env, 15); // simp
    v_27826 = (*qfn1(fn))(fn, v_27826);
    goto v_27612;
v_27694:
    v_27826 = qvalue(elt(env, 1)); // propvars!*
    stack[-4] = v_27826;
v_27707:
    v_27826 = stack[-4];
    if (v_27826 == nil) goto v_27711;
    else goto v_27712;
v_27711:
    goto v_27706;
v_27712:
    v_27826 = stack[-4];
    v_27826 = qcar(v_27826);
    goto v_27726;
v_27720:
    stack[-3] = elt(env, 8); // times
    goto v_27721;
v_27722:
    stack[-2] = v_27828;
    goto v_27723;
v_27724:
    goto v_27735;
v_27731:
    goto v_27743;
v_27737:
    stack[-1] = qvalue(elt(env, 5)); // !'or
    goto v_27738;
v_27739:
    stack[0] = v_27826;
    goto v_27740;
v_27741:
    goto v_27751;
v_27747:
    v_27827 = elt(env, 9); // not
    goto v_27748;
v_27749:
    goto v_27750;
v_27751:
    goto v_27747;
v_27748:
    goto v_27749;
v_27750:
    v_27826 = list2(v_27827, v_27826);
    env = stack[-7];
    goto v_27742;
v_27743:
    goto v_27737;
v_27738:
    goto v_27739;
v_27740:
    goto v_27741;
v_27742:
    v_27827 = list3(stack[-1], stack[0], v_27826);
    env = stack[-7];
    goto v_27732;
v_27733:
    v_27826 = lisp_true;
    goto v_27734;
v_27735:
    goto v_27731;
v_27732:
    goto v_27733;
v_27734:
    fn = elt(env, 13); // simp!-prop1
    v_27826 = (*qfn2(fn))(fn, v_27827, v_27826);
    env = stack[-7];
    fn = elt(env, 14); // prepf
    v_27826 = (*qfn1(fn))(fn, v_27826);
    env = stack[-7];
    goto v_27725;
v_27726:
    goto v_27720;
v_27721:
    goto v_27722;
v_27723:
    goto v_27724;
v_27725:
    v_27826 = list3(stack[-3], stack[-2], v_27826);
    env = stack[-7];
    fn = elt(env, 12); // reval
    v_27826 = (*qfn1(fn))(fn, v_27826);
    env = stack[-7];
    v_27828 = v_27826;
    v_27826 = stack[-4];
    v_27826 = qcdr(v_27826);
    stack[-4] = v_27826;
    goto v_27707;
v_27706:
    v_27826 = v_27828;
    fn = elt(env, 16); // simp!-prop!-dist
    v_27826 = (*qfn1(fn))(fn, v_27826);
    env = stack[-7];
    v_27828 = v_27826;
    goto v_27767;
v_27763:
    v_27827 = elt(env, 10); // full
    goto v_27764;
v_27765:
    v_27826 = stack[-5];
    goto v_27766;
v_27767:
    goto v_27763;
v_27764:
    goto v_27765;
v_27766:
    v_27826 = Lmember(nil, v_27827, v_27826);
    if (v_27826 == nil) goto v_27761;
    else goto v_27762;
v_27761:
    v_27826 = v_27828;
    fn = elt(env, 17); // simp!-prop2
    v_27826 = (*qfn1(fn))(fn, v_27826);
    env = stack[-7];
    v_27828 = v_27826;
    goto v_27760;
v_27762:
v_27760:
    v_27826 = v_27828;
    fn = elt(env, 18); // simp!-prop!-form
    v_27826 = (*qfn1(fn))(fn, v_27826);
    env = stack[-7];
    v_27828 = v_27826;
    v_27826 = v_27828;
    if (is_number(v_27826)) goto v_27777;
    else goto v_27778;
v_27777:
    goto v_27785;
v_27781:
    v_27827 = v_27828;
    goto v_27782;
v_27783:
    v_27826 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27784;
v_27785:
    goto v_27781;
v_27782:
    goto v_27783;
v_27784:
    v_27826 = cons(v_27827, v_27826);
    goto v_27612;
v_27778:
    v_27826 = v_27828;
    if (!consp(v_27826)) goto v_27791;
    goto v_27798;
v_27794:
    v_27826 = elt(env, 11); // boolean
    goto v_27795;
v_27796:
    v_27827 = v_27828;
    goto v_27797;
v_27798:
    goto v_27794;
v_27795:
    goto v_27796;
v_27797:
    v_27826 = list2(v_27826, v_27827);
    env = stack[-7];
    v_27828 = v_27826;
    goto v_27789;
v_27791:
v_27789:
    goto v_27808;
v_27802:
    goto v_27814;
v_27810:
    goto v_27820;
v_27816:
    v_27827 = v_27828;
    goto v_27817;
v_27818:
    v_27826 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27819;
v_27820:
    goto v_27816;
v_27817:
    goto v_27818;
v_27819:
    fn = elt(env, 19); // to
    v_27827 = (*qfn2(fn))(fn, v_27827, v_27826);
    env = stack[-7];
    goto v_27811;
v_27812:
    v_27826 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27813;
v_27814:
    goto v_27810;
v_27811:
    goto v_27812;
v_27813:
    v_27828 = cons(v_27827, v_27826);
    env = stack[-7];
    goto v_27803;
v_27804:
    v_27827 = nil;
    goto v_27805;
v_27806:
    v_27826 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27807;
v_27808:
    goto v_27802;
v_27803:
    goto v_27804;
v_27805:
    goto v_27806;
v_27807:
    v_27826 = acons(v_27828, v_27827, v_27826);
v_27612:
    ;}  // end of a binding scope
    return onevalue(v_27826);
}



// Code for ctx_get

static LispObject CC_ctx_get(LispObject env,
                         LispObject v_27606, LispObject v_27607)
{
    env = qenv(env);
    LispObject v_27646, v_27647, v_27648;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27606,v_27607);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27607;
    v_27646 = v_27606;
// end of prologue
    stack[-1] = nil;
    fn = elt(env, 1); // ctx_ial
    v_27646 = (*qfn1(fn))(fn, v_27646);
    v_27648 = v_27646;
v_27617:
    v_27646 = v_27648;
    if (v_27646 == nil) goto v_27620;
    v_27646 = stack[-1];
    if (v_27646 == nil) goto v_27624;
    else goto v_27620;
v_27624:
    goto v_27621;
v_27620:
    goto v_27616;
v_27621:
    goto v_27635;
v_27631:
    v_27646 = v_27648;
    v_27646 = qcar(v_27646);
    v_27647 = qcar(v_27646);
    goto v_27632;
v_27633:
    v_27646 = stack[0];
    goto v_27634;
v_27635:
    goto v_27631;
v_27632:
    goto v_27633;
v_27634:
    if (v_27647 == v_27646) goto v_27629;
    else goto v_27630;
v_27629:
    v_27646 = v_27648;
    v_27646 = qcar(v_27646);
    v_27646 = qcdr(v_27646);
    stack[-1] = v_27646;
    goto v_27628;
v_27630:
v_27628:
    v_27646 = v_27648;
    v_27646 = qcdr(v_27646);
    v_27648 = v_27646;
    goto v_27617;
v_27616:
    v_27646 = stack[-1];
    return onevalue(v_27646);
}



// Code for qqe_simplqneq

static LispObject CC_qqe_simplqneq(LispObject env,
                         LispObject v_27606, LispObject v_27607)
{
    env = qenv(env);
    LispObject v_27680, v_27681, v_27682;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27606,v_27607);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_27681 = v_27607;
    v_27680 = v_27606;
// end of prologue
    v_27681 = v_27680;
    v_27681 = qcdr(v_27681);
    v_27681 = qcar(v_27681);
    v_27680 = qcdr(v_27680);
    v_27680 = qcdr(v_27680);
    v_27680 = qcar(v_27680);
    goto v_27629;
v_27625:
    goto v_27637;
v_27631:
    v_27682 = elt(env, 1); // qequal
    goto v_27632;
v_27633:
    goto v_27634;
v_27635:
    goto v_27636;
v_27637:
    goto v_27631;
v_27632:
    goto v_27633;
v_27634:
    goto v_27635;
v_27636:
    fn = elt(env, 5); // qqe_mk2
    v_27681 = (*qfnn(fn))(fn, 3, v_27682, v_27681, v_27680);
    env = stack[-3];
    goto v_27626;
v_27627:
    v_27680 = nil;
    goto v_27628;
v_27629:
    goto v_27625;
v_27626:
    goto v_27627;
v_27628:
    fn = elt(env, 6); // qqe_simplqequal
    v_27680 = (*qfn2(fn))(fn, v_27681, v_27680);
    env = stack[-3];
    stack[-2] = v_27680;
    goto v_27650;
v_27646:
    v_27681 = stack[-2];
    goto v_27647;
v_27648:
    v_27680 = elt(env, 2); // true
    goto v_27649;
v_27650:
    goto v_27646;
v_27647:
    goto v_27648;
v_27649:
    if (v_27681 == v_27680) goto v_27644;
    else goto v_27645;
v_27644:
    v_27680 = elt(env, 3); // false
    goto v_27643;
v_27645:
    goto v_27660;
v_27656:
    v_27681 = stack[-2];
    goto v_27657;
v_27658:
    v_27680 = elt(env, 3); // false
    goto v_27659;
v_27660:
    goto v_27656;
v_27657:
    goto v_27658;
v_27659:
    if (v_27681 == v_27680) goto v_27654;
    else goto v_27655;
v_27654:
    v_27680 = elt(env, 2); // true
    goto v_27643;
v_27655:
    goto v_27673;
v_27667:
    stack[-1] = elt(env, 4); // qneq
    goto v_27668;
v_27669:
    v_27680 = stack[-2];
    fn = elt(env, 7); // qqe_arg2l
    stack[0] = (*qfn1(fn))(fn, v_27680);
    env = stack[-3];
    goto v_27670;
v_27671:
    v_27680 = stack[-2];
    fn = elt(env, 8); // qqe_arg2r
    v_27680 = (*qfn1(fn))(fn, v_27680);
    env = stack[-3];
    goto v_27672;
v_27673:
    goto v_27667;
v_27668:
    goto v_27669;
v_27670:
    goto v_27671;
v_27672:
    fn = elt(env, 5); // qqe_mk2
    v_27680 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_27680);
    goto v_27643;
v_27643:
    return onevalue(v_27680);
}



// Code for pasf_ordatp

static LispObject CC_pasf_ordatp(LispObject env,
                         LispObject v_27606, LispObject v_27607)
{
    env = qenv(env);
    LispObject v_27722, v_27723, v_27724, v_27725, v_27726, v_27727;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27606,v_27607);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_27725 = v_27607;
    v_27726 = v_27606;
// end of prologue
    v_27722 = v_27726;
    v_27722 = qcdr(v_27722);
    v_27722 = qcar(v_27722);
    v_27727 = v_27722;
    v_27722 = v_27725;
    v_27722 = qcdr(v_27722);
    v_27722 = qcar(v_27722);
    v_27724 = v_27722;
    goto v_27627;
v_27623:
    v_27723 = v_27727;
    goto v_27624;
v_27625:
    v_27722 = v_27724;
    goto v_27626;
v_27627:
    goto v_27623;
v_27624:
    goto v_27625;
v_27626:
    if (equal(v_27723, v_27722)) goto v_27622;
    goto v_27635;
v_27631:
    v_27722 = v_27727;
    goto v_27632;
v_27633:
    v_27723 = v_27724;
    goto v_27634;
v_27635:
    goto v_27631;
v_27632:
    goto v_27633;
v_27634:
    {
        fn = elt(env, 3); // ordp
        return (*qfn2(fn))(fn, v_27722, v_27723);
    }
v_27622:
    goto v_27643;
v_27639:
    goto v_27656;
v_27652:
    v_27723 = v_27726;
    goto v_27653;
v_27654:
    v_27722 = elt(env, 1); // true
    goto v_27655;
v_27656:
    goto v_27652;
v_27653:
    goto v_27654;
v_27655:
    if (v_27723 == v_27722) goto v_27650;
    else goto v_27651;
v_27650:
    v_27722 = lisp_true;
    goto v_27649;
v_27651:
    goto v_27666;
v_27662:
    v_27723 = v_27726;
    goto v_27663;
v_27664:
    v_27722 = elt(env, 2); // false
    goto v_27665;
v_27666:
    goto v_27662;
v_27663:
    goto v_27664;
v_27665:
    v_27722 = (v_27723 == v_27722 ? lisp_true : nil);
    goto v_27649;
    v_27722 = nil;
v_27649:
    if (v_27722 == nil) goto v_27647;
    v_27722 = v_27726;
    v_27724 = v_27722;
    goto v_27645;
v_27647:
    v_27722 = v_27726;
    v_27722 = qcar(v_27722);
    v_27722 = Lconsp(nil, v_27722);
    env = stack[0];
    if (v_27722 == nil) goto v_27672;
    v_27722 = v_27726;
    v_27722 = qcar(v_27722);
    v_27722 = qcar(v_27722);
    v_27724 = v_27722;
    goto v_27645;
v_27672:
    v_27722 = v_27726;
    v_27722 = qcar(v_27722);
    v_27724 = v_27722;
    goto v_27645;
    v_27724 = nil;
v_27645:
    goto v_27640;
v_27641:
    goto v_27695;
v_27691:
    v_27723 = v_27725;
    goto v_27692;
v_27693:
    v_27722 = elt(env, 1); // true
    goto v_27694;
v_27695:
    goto v_27691;
v_27692:
    goto v_27693;
v_27694:
    if (v_27723 == v_27722) goto v_27689;
    else goto v_27690;
v_27689:
    v_27722 = lisp_true;
    goto v_27688;
v_27690:
    goto v_27705;
v_27701:
    v_27723 = v_27725;
    goto v_27702;
v_27703:
    v_27722 = elt(env, 2); // false
    goto v_27704;
v_27705:
    goto v_27701;
v_27702:
    goto v_27703;
v_27704:
    v_27722 = (v_27723 == v_27722 ? lisp_true : nil);
    goto v_27688;
    v_27722 = nil;
v_27688:
    if (v_27722 == nil) goto v_27686;
    v_27722 = v_27725;
    goto v_27684;
v_27686:
    v_27722 = v_27725;
    v_27722 = qcar(v_27722);
    v_27722 = Lconsp(nil, v_27722);
    env = stack[0];
    if (v_27722 == nil) goto v_27711;
    v_27722 = v_27725;
    v_27722 = qcar(v_27722);
    v_27722 = qcar(v_27722);
    goto v_27684;
v_27711:
    v_27722 = v_27725;
    v_27722 = qcar(v_27722);
    goto v_27684;
    v_27722 = nil;
v_27684:
    goto v_27642;
v_27643:
    goto v_27639;
v_27640:
    goto v_27641;
v_27642:
    {
        fn = elt(env, 4); // pasf_ordrelp
        return (*qfn2(fn))(fn, v_27724, v_27722);
    }
    return onevalue(v_27722);
}



// Code for operator_fn

static LispObject CC_operator_fn(LispObject env,
                         LispObject v_27606)
{
    env = qenv(env);
    LispObject v_27636;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27606);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27606;
// end of prologue
    v_27636 = elt(env, 1); // "<apply>"
    fn = elt(env, 7); // printout
    v_27636 = (*qfn1(fn))(fn, v_27636);
    env = stack[-1];
    v_27636 = lisp_true;
    fn = elt(env, 8); // indent!*
    v_27636 = (*qfn1(fn))(fn, v_27636);
    env = stack[-1];
    v_27636 = elt(env, 2); // "<csymbol>"
    fn = elt(env, 7); // printout
    v_27636 = (*qfn1(fn))(fn, v_27636);
    env = stack[-1];
    v_27636 = lisp_true;
    fn = elt(env, 8); // indent!*
    v_27636 = (*qfn1(fn))(fn, v_27636);
    env = stack[-1];
    v_27636 = elt(env, 3); // "<ci>"
    fn = elt(env, 7); // printout
    v_27636 = (*qfn1(fn))(fn, v_27636);
    env = stack[-1];
    v_27636 = stack[0];
    v_27636 = qcar(v_27636);
    v_27636 = Lprinc(nil, v_27636);
    env = stack[-1];
    v_27636 = elt(env, 4); // "</ci>"
    v_27636 = Lprinc(nil, v_27636);
    env = stack[-1];
    v_27636 = nil;
    fn = elt(env, 8); // indent!*
    v_27636 = (*qfn1(fn))(fn, v_27636);
    env = stack[-1];
    v_27636 = elt(env, 5); // "</csymbol>"
    fn = elt(env, 7); // printout
    v_27636 = (*qfn1(fn))(fn, v_27636);
    env = stack[-1];
    v_27636 = stack[0];
    v_27636 = qcdr(v_27636);
    fn = elt(env, 9); // multi_args
    v_27636 = (*qfn1(fn))(fn, v_27636);
    env = stack[-1];
    v_27636 = nil;
    fn = elt(env, 8); // indent!*
    v_27636 = (*qfn1(fn))(fn, v_27636);
    env = stack[-1];
    v_27636 = elt(env, 6); // "</apply>"
    fn = elt(env, 7); // printout
    v_27636 = (*qfn1(fn))(fn, v_27636);
    v_27636 = nil;
    return onevalue(v_27636);
}



// Code for mulpower

static LispObject CC_mulpower(LispObject env,
                         LispObject v_27606, LispObject v_27607)
{
    env = qenv(env);
    LispObject v_27660, v_27661, v_27662;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27606,v_27607);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_27660 = v_27607;
    v_27661 = v_27606;
// end of prologue
    stack[0] = nil;
    goto v_27618;
v_27614:
    goto v_27615;
v_27616:
    goto v_27617;
v_27618:
    goto v_27614;
v_27615:
    goto v_27616;
v_27617:
    fn = elt(env, 3); // addexptsdf
    v_27660 = (*qfn2(fn))(fn, v_27661, v_27660);
    env = stack[-2];
    stack[-1] = v_27660;
    v_27660 = qvalue(elt(env, 1)); // sqrtlist
    if (v_27660 == nil) goto v_27624;
    goto v_27631;
v_27627:
    v_27661 = stack[-1];
    goto v_27628;
v_27629:
    v_27660 = qvalue(elt(env, 2)); // zlist
    goto v_27630;
v_27631:
    goto v_27627;
v_27628:
    goto v_27629;
v_27630:
    fn = elt(env, 4); // reduceroots
    v_27660 = (*qfn2(fn))(fn, v_27661, v_27660);
    env = stack[-2];
    stack[0] = v_27660;
    goto v_27622;
v_27624:
v_27622:
    goto v_27642;
v_27636:
    v_27662 = stack[-1];
    goto v_27637;
v_27638:
    v_27661 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27639;
v_27640:
    v_27660 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27641;
v_27642:
    goto v_27636;
v_27637:
    goto v_27638;
v_27639:
    goto v_27640;
v_27641:
    v_27660 = list2star(v_27662, v_27661, v_27660);
    env = stack[-2];
    v_27660 = ncons(v_27660);
    env = stack[-2];
    stack[-1] = v_27660;
    v_27660 = stack[0];
    if (v_27660 == nil) goto v_27649;
    goto v_27656;
v_27652:
    v_27661 = stack[-1];
    goto v_27653;
v_27654:
    v_27660 = stack[0];
    goto v_27655;
v_27656:
    goto v_27652;
v_27653:
    goto v_27654;
v_27655:
    fn = elt(env, 5); // multdf
    v_27660 = (*qfn2(fn))(fn, v_27661, v_27660);
    stack[-1] = v_27660;
    goto v_27647;
v_27649:
v_27647:
    v_27660 = stack[-1];
    return onevalue(v_27660);
}



// Code for lndepends

static LispObject CC_lndepends(LispObject env,
                         LispObject v_27606, LispObject v_27607)
{
    env = qenv(env);
    LispObject v_27649, v_27650;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27606,v_27607);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27607;
    stack[-1] = v_27606;
// end of prologue
v_27605:
    v_27649 = stack[-1];
    if (v_27649 == nil) goto v_27611;
    else goto v_27612;
v_27611:
    v_27649 = nil;
    goto v_27610;
v_27612:
    v_27649 = stack[-1];
    if (!consp(v_27649)) goto v_27615;
    else goto v_27616;
v_27615:
    goto v_27623;
v_27619:
    v_27650 = stack[-1];
    goto v_27620;
v_27621:
    v_27649 = stack[0];
    goto v_27622;
v_27623:
    goto v_27619;
v_27620:
    goto v_27621;
v_27622:
    {
        fn = elt(env, 1); // ndepends
        return (*qfn2(fn))(fn, v_27650, v_27649);
    }
v_27616:
    goto v_27636;
v_27632:
    v_27649 = stack[-1];
    v_27650 = qcar(v_27649);
    goto v_27633;
v_27634:
    v_27649 = stack[0];
    goto v_27635;
v_27636:
    goto v_27632;
v_27633:
    goto v_27634;
v_27635:
    fn = elt(env, 1); // ndepends
    v_27649 = (*qfn2(fn))(fn, v_27650, v_27649);
    env = stack[-2];
    if (v_27649 == nil) goto v_27630;
    else goto v_27629;
v_27630:
    goto v_27645;
v_27641:
    v_27649 = stack[-1];
    v_27650 = qcdr(v_27649);
    goto v_27642;
v_27643:
    v_27649 = stack[0];
    goto v_27644;
v_27645:
    goto v_27641;
v_27642:
    goto v_27643;
v_27644:
    stack[-1] = v_27650;
    stack[0] = v_27649;
    goto v_27605;
v_27629:
    goto v_27610;
    v_27649 = nil;
v_27610:
    return onevalue(v_27649);
}



// Code for split!-comfac!-part

static LispObject CC_splitKcomfacKpart(LispObject env,
                         LispObject v_27606)
{
    env = qenv(env);
    LispObject v_27619, v_27620, v_27621;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27619 = v_27606;
// end of prologue
    goto v_27615;
v_27609:
    v_27621 = v_27619;
    goto v_27610;
v_27611:
    v_27620 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27612;
v_27613:
    v_27619 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27614;
v_27615:
    goto v_27609;
v_27610:
    goto v_27611;
v_27612:
    goto v_27613;
v_27614:
    {
        fn = elt(env, 1); // split!-comfac
        return (*qfnn(fn))(fn, 3, v_27621, v_27620, v_27619);
    }
}



// Code for reduce!-weights

static LispObject CC_reduceKweights(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27694, v_27695;
    LispObject fn;
    LispObject v_27608, v_27607, v_27606;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "reduce-weights");
    va_start(aa, nargs);
    v_27606 = va_arg(aa, LispObject);
    v_27607 = va_arg(aa, LispObject);
    v_27608 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27608,v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27606,v_27607,v_27608);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_27608;
    stack[-4] = v_27607;
    stack[-5] = v_27606;
// end of prologue
    stack[-6] = nil;
    goto v_27623;
v_27619:
    v_27695 = stack[-5];
    goto v_27620;
v_27621:
    v_27694 = stack[-3];
    goto v_27622;
v_27623:
    goto v_27619;
v_27620:
    goto v_27621;
v_27622:
    fn = elt(env, 1); // red!-weight
    v_27694 = (*qfn2(fn))(fn, v_27695, v_27694);
    env = stack[-7];
    stack[-2] = v_27694;
v_27616:
    goto v_27631;
v_27627:
    v_27695 = stack[-5];
    goto v_27628;
v_27629:
    v_27694 = stack[-4];
    goto v_27630;
v_27631:
    goto v_27627;
v_27628:
    goto v_27629;
v_27630:
    fn = elt(env, 2); // mv!-domainlist!-!+
    v_27694 = (*qfn2(fn))(fn, v_27695, v_27694);
    env = stack[-7];
    stack[-1] = v_27694;
    goto v_27639;
v_27635:
    v_27695 = stack[-1];
    goto v_27636;
v_27637:
    v_27694 = stack[-3];
    goto v_27638;
v_27639:
    goto v_27635;
v_27636:
    goto v_27637;
v_27638:
    fn = elt(env, 1); // red!-weight
    v_27694 = (*qfn2(fn))(fn, v_27695, v_27694);
    env = stack[-7];
    stack[0] = v_27694;
    goto v_27651;
v_27647:
    v_27695 = stack[0];
    goto v_27648;
v_27649:
    v_27694 = stack[-2];
    goto v_27650;
v_27651:
    goto v_27647;
v_27648:
    goto v_27649;
v_27650:
    fn = elt(env, 3); // red!-weight!-less!-p
    v_27694 = (*qfn2(fn))(fn, v_27695, v_27694);
    env = stack[-7];
    if (v_27694 == nil) goto v_27645;
    v_27694 = lisp_true;
    stack[-6] = v_27694;
    v_27694 = stack[-1];
    stack[-5] = v_27694;
    v_27694 = stack[0];
    stack[-2] = v_27694;
    goto v_27616;
v_27645:
    v_27694 = stack[-6];
    if (v_27694 == nil) goto v_27660;
    v_27694 = stack[-5];
    goto v_27615;
v_27660:
v_27617:
    goto v_27668;
v_27664:
    v_27695 = stack[-5];
    goto v_27665;
v_27666:
    v_27694 = stack[-4];
    goto v_27667;
v_27668:
    goto v_27664;
v_27665:
    goto v_27666;
v_27667:
    fn = elt(env, 4); // mv!-domainlist!-!-
    v_27694 = (*qfn2(fn))(fn, v_27695, v_27694);
    env = stack[-7];
    stack[-1] = v_27694;
    goto v_27676;
v_27672:
    v_27695 = stack[-1];
    goto v_27673;
v_27674:
    v_27694 = stack[-3];
    goto v_27675;
v_27676:
    goto v_27672;
v_27673:
    goto v_27674;
v_27675:
    fn = elt(env, 1); // red!-weight
    v_27694 = (*qfn2(fn))(fn, v_27695, v_27694);
    env = stack[-7];
    stack[0] = v_27694;
    goto v_27688;
v_27684:
    v_27695 = stack[0];
    goto v_27685;
v_27686:
    v_27694 = stack[-2];
    goto v_27687;
v_27688:
    goto v_27684;
v_27685:
    goto v_27686;
v_27687:
    fn = elt(env, 3); // red!-weight!-less!-p
    v_27694 = (*qfn2(fn))(fn, v_27695, v_27694);
    env = stack[-7];
    if (v_27694 == nil) goto v_27682;
    v_27694 = stack[-1];
    stack[-5] = v_27694;
    v_27694 = stack[0];
    stack[-2] = v_27694;
    goto v_27617;
v_27682:
    v_27694 = stack[-5];
v_27615:
    return onevalue(v_27694);
}



// Code for cali_bc_from_a

static LispObject CC_cali_bc_from_a(LispObject env,
                         LispObject v_27606)
{
    env = qenv(env);
    LispObject v_27612;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27606);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_27612 = v_27606;
// end of prologue
    fn = elt(env, 1); // simp!*
    v_27612 = (*qfn1(fn))(fn, v_27612);
    env = stack[0];
    v_27612 = qcar(v_27612);
    {
        fn = elt(env, 2); // bc!=simp
        return (*qfn1(fn))(fn, v_27612);
    }
}



// Code for vecsimp!*

static LispObject CC_vecsimpH(LispObject env,
                         LispObject v_27606)
{
    env = qenv(env);
    LispObject v_27619;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27606);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27606;
// end of prologue
    v_27619 = stack[0];
    fn = elt(env, 1); // vecp
    v_27619 = (*qfn1(fn))(fn, v_27619);
    env = stack[-1];
    if (v_27619 == nil) goto v_27611;
    v_27619 = stack[0];
    {
        fn = elt(env, 2); // vecsm!*
        return (*qfn1(fn))(fn, v_27619);
    }
v_27611:
    v_27619 = stack[0];
    goto v_27609;
    v_27619 = nil;
v_27609:
    return onevalue(v_27619);
}



// Code for mkrootsq

static LispObject CC_mkrootsq(LispObject env,
                         LispObject v_27606, LispObject v_27607)
{
    env = qenv(env);
    LispObject v_27838, v_27839, v_27840;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27606,v_27607);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27607;
    stack[-1] = v_27606;
// end of prologue
    goto v_27617;
v_27613:
    v_27839 = stack[-1];
    goto v_27614;
v_27615:
    v_27838 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27616;
v_27617:
    goto v_27613;
v_27614:
    goto v_27615;
v_27616:
    if (v_27839 == v_27838) goto v_27611;
    else goto v_27612;
v_27611:
    v_27838 = (LispObject)16+TAG_FIXNUM; // 1
    {
        fn = elt(env, 8); // !*d2q
        return (*qfn1(fn))(fn, v_27838);
    }
v_27612:
    goto v_27632;
v_27628:
    v_27839 = stack[0];
    goto v_27629;
v_27630:
    v_27838 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_27631;
v_27632:
    goto v_27628;
v_27629:
    goto v_27630;
v_27631:
    if (v_27839 == v_27838) goto v_27626;
    else goto v_27627;
v_27626:
    goto v_27643;
v_27639:
    v_27839 = stack[-1];
    goto v_27640;
v_27641:
    v_27838 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_27642;
v_27643:
    goto v_27639;
v_27640:
    goto v_27641;
v_27642:
    if (v_27839 == v_27838) goto v_27637;
    else goto v_27638;
v_27637:
    v_27838 = lisp_true;
    goto v_27636;
v_27638:
    goto v_27653;
v_27649:
    v_27839 = stack[-1];
    goto v_27650;
v_27651:
    v_27838 = elt(env, 1); // (minus 1)
    goto v_27652;
v_27653:
    goto v_27649;
v_27650:
    goto v_27651;
v_27652:
    v_27838 = (equal(v_27839, v_27838) ? lisp_true : nil);
    goto v_27636;
    v_27838 = nil;
v_27636:
    goto v_27625;
v_27627:
    v_27838 = nil;
    goto v_27625;
    v_27838 = nil;
v_27625:
    if (v_27838 == nil) goto v_27623;
    v_27838 = elt(env, 2); // i
    {
        fn = elt(env, 9); // simp
        return (*qfn1(fn))(fn, v_27838);
    }
v_27623:
    goto v_27673;
v_27669:
    v_27839 = stack[-1];
    goto v_27670;
v_27671:
    v_27838 = elt(env, 3); // expt
    goto v_27672;
v_27673:
    goto v_27669;
v_27670:
    goto v_27671;
v_27672:
    if (!consp(v_27839)) goto v_27667;
    v_27839 = qcar(v_27839);
    if (v_27839 == v_27838) goto v_27666;
    else goto v_27667;
v_27666:
    v_27838 = stack[-1];
    v_27838 = qcdr(v_27838);
    v_27838 = qcdr(v_27838);
    v_27838 = qcar(v_27838);
    v_27838 = integerp(v_27838);
    if (v_27838 == nil) goto v_27678;
    else goto v_27679;
v_27678:
    v_27838 = nil;
    goto v_27677;
v_27679:
    v_27838 = qvalue(elt(env, 4)); // !*precise_complex
    v_27838 = (v_27838 == nil ? lisp_true : nil);
    goto v_27677;
    v_27838 = nil;
v_27677:
    goto v_27665;
v_27667:
    v_27838 = nil;
    goto v_27665;
    v_27838 = nil;
v_27665:
    if (v_27838 == nil) goto v_27663;
    goto v_27698;
v_27694:
    goto v_27704;
v_27700:
    v_27838 = stack[-1];
    v_27838 = qcdr(v_27838);
    v_27839 = qcar(v_27838);
    goto v_27701;
v_27702:
    v_27838 = stack[0];
    goto v_27703;
v_27704:
    goto v_27700;
v_27701:
    goto v_27702;
v_27703:
    v_27839 = CC_mkrootsq(elt(env, 0), v_27839, v_27838);
    env = stack[-3];
    goto v_27695;
v_27696:
    v_27838 = stack[-1];
    v_27838 = qcdr(v_27838);
    v_27838 = qcdr(v_27838);
    v_27838 = qcar(v_27838);
    goto v_27697;
v_27698:
    goto v_27694;
v_27695:
    goto v_27696;
v_27697:
    {
        fn = elt(env, 10); // exptsq
        return (*qfn2(fn))(fn, v_27839, v_27838);
    }
v_27663:
    stack[-2] = nil;
    v_27838 = stack[-1];
    v_27838 = integerp(v_27838);
    if (v_27838 == nil) goto v_27722;
    v_27838 = stack[-1];
    v_27838 = Lminusp(nil, v_27838);
    env = stack[-3];
    if (v_27838 == nil) goto v_27729;
    else goto v_27730;
v_27729:
    goto v_27741;
v_27737:
    goto v_27748;
v_27744:
    stack[-2] = stack[-1];
    goto v_27745;
v_27746:
    goto v_27758;
v_27754:
    v_27839 = stack[-1];
    goto v_27755;
v_27756:
    v_27838 = qvalue(elt(env, 5)); // factorbound!*
    goto v_27757;
v_27758:
    goto v_27754;
v_27755:
    goto v_27756;
v_27757:
    v_27838 = (LispObject)lessp2(v_27839, v_27838);
    v_27838 = v_27838 ? lisp_true : nil;
    env = stack[-3];
    if (v_27838 == nil) goto v_27752;
    else goto v_27751;
v_27752:
    v_27838 = qvalue(elt(env, 6)); // !*ifactor
v_27751:
    goto v_27747;
v_27748:
    goto v_27744;
v_27745:
    goto v_27746;
v_27747:
    fn = elt(env, 11); // zfactor1
    v_27838 = (*qfn2(fn))(fn, stack[-2], v_27838);
    env = stack[-3];
    stack[-2] = v_27838;
    v_27839 = Llength(nil, v_27838);
    env = stack[-3];
    goto v_27738;
v_27739:
    v_27838 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27740;
v_27741:
    goto v_27737;
v_27738:
    goto v_27739;
v_27740:
    v_27838 = (LispObject)greaterp2(v_27839, v_27838);
    v_27838 = v_27838 ? lisp_true : nil;
    env = stack[-3];
    if (v_27838 == nil) goto v_27735;
    else goto v_27734;
v_27735:
    goto v_27768;
v_27764:
    v_27838 = stack[-2];
    v_27838 = qcar(v_27838);
    v_27839 = qcdr(v_27838);
    goto v_27765;
v_27766:
    v_27838 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27767;
v_27768:
    goto v_27764;
v_27765:
    goto v_27766;
v_27767:
    v_27838 = (LispObject)greaterp2(v_27839, v_27838);
    v_27838 = v_27838 ? lisp_true : nil;
    env = stack[-3];
v_27734:
    goto v_27728;
v_27730:
    v_27838 = nil;
    goto v_27728;
    v_27838 = nil;
v_27728:
    if (v_27838 == nil) goto v_27722;
    goto v_27781;
v_27777:
    v_27839 = stack[-2];
    goto v_27778;
v_27779:
    v_27838 = stack[0];
    goto v_27780;
v_27781:
    goto v_27777;
v_27778:
    goto v_27779;
v_27780:
    {
        fn = elt(env, 12); // mkrootsql
        return (*qfn2(fn))(fn, v_27839, v_27838);
    }
v_27722:
    goto v_27792;
v_27788:
    v_27839 = stack[0];
    goto v_27789;
v_27790:
    v_27838 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_27791;
v_27792:
    goto v_27788;
v_27789:
    goto v_27790;
v_27791:
    if (v_27839 == v_27838) goto v_27786;
    else goto v_27787;
v_27786:
    v_27838 = stack[-1];
    fn = elt(env, 13); // mksqrt
    v_27838 = (*qfn1(fn))(fn, v_27838);
    env = stack[-3];
    goto v_27785;
v_27787:
    goto v_27806;
v_27800:
    stack[-2] = elt(env, 3); // expt
    goto v_27801;
v_27802:
    goto v_27803;
v_27804:
    goto v_27816;
v_27810:
    v_27840 = elt(env, 7); // quotient
    goto v_27811;
v_27812:
    v_27839 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27813;
v_27814:
    v_27838 = stack[0];
    goto v_27815;
v_27816:
    goto v_27810;
v_27811:
    goto v_27812;
v_27813:
    goto v_27814;
v_27815:
    v_27838 = list3(v_27840, v_27839, v_27838);
    env = stack[-3];
    goto v_27805;
v_27806:
    goto v_27800;
v_27801:
    goto v_27802;
v_27803:
    goto v_27804;
v_27805:
    v_27838 = list3(stack[-2], stack[-1], v_27838);
    env = stack[-3];
    goto v_27785;
    v_27838 = nil;
v_27785:
    stack[-2] = v_27838;
    v_27838 = stack[-2];
    fn = elt(env, 14); // opmtch
    v_27838 = (*qfn1(fn))(fn, v_27838);
    env = stack[-3];
    v_27839 = v_27838;
    if (v_27838 == nil) goto v_27823;
    v_27838 = v_27839;
    {
        fn = elt(env, 9); // simp
        return (*qfn1(fn))(fn, v_27838);
    }
v_27823:
    goto v_27835;
v_27831:
    v_27839 = stack[-2];
    goto v_27832;
v_27833:
    v_27838 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27834;
v_27835:
    goto v_27831;
v_27832:
    goto v_27833;
v_27834:
    {
        fn = elt(env, 15); // mksq
        return (*qfn2(fn))(fn, v_27839, v_27838);
    }
    v_27838 = nil;
    goto v_27610;
    v_27838 = nil;
v_27610:
    return onevalue(v_27838);
}



// Code for check_letop

static LispObject CC_check_letop(LispObject env,
                         LispObject v_27606)
{
    env = qenv(env);
    LispObject v_27622, v_27623;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27606);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_27622 = v_27606;
// end of prologue
    goto v_27617;
v_27613:
    v_27623 = v_27622;
    goto v_27614;
v_27615:
    v_27622 = elt(env, 1); // letop
    goto v_27616;
v_27617:
    goto v_27613;
v_27614:
    goto v_27615;
v_27616:
    fn = elt(env, 3); // freeof
    v_27622 = (*qfn2(fn))(fn, v_27623, v_27622);
    env = stack[0];
    if (v_27622 == nil) goto v_27610;
    else goto v_27611;
v_27610:
    v_27622 = elt(env, 2); // "Presence of letop, jetspace too small!"
    {
        fn = elt(env, 4); // rederr
        return (*qfn1(fn))(fn, v_27622);
    }
v_27611:
    v_27622 = nil;
    return onevalue(v_27622);
}



// Code for try!-all!-constants

static LispObject CC_tryKallKconstants(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27699, v_27700, v_27701;
    LispObject fn;
    LispObject v_27608, v_27607, v_27606;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "try-all-constants");
    va_start(aa, nargs);
    v_27606 = va_arg(aa, LispObject);
    v_27607 = va_arg(aa, LispObject);
    v_27608 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27608,v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27606,v_27607,v_27608);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_27608;
    stack[-3] = v_27607;
    v_27700 = v_27606;
// end of prologue
    v_27699 = nil;
    stack[-1] = v_27699;
    v_27699 = v_27700;
    stack[-4] = v_27699;
    v_27699 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_27699;
v_27616:
    goto v_27626;
v_27620:
    v_27701 = stack[-3];
    goto v_27621;
v_27622:
    v_27700 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27623;
v_27624:
    v_27699 = stack[0];
    goto v_27625;
v_27626:
    goto v_27620;
v_27621:
    goto v_27622;
v_27623:
    goto v_27624;
v_27625:
    *(LispObject *)((char *)v_27701 + (CELL-TAG_VECTOR) + (((intptr_t)v_27700-TAG_FIXNUM)/(16/CELL))) = v_27699;
    goto v_27637;
v_27631:
    v_27701 = stack[-4];
    goto v_27632;
v_27633:
    v_27700 = stack[-3];
    goto v_27634;
v_27635:
    v_27699 = stack[-2];
    goto v_27636;
v_27637:
    goto v_27631;
v_27632:
    goto v_27633;
v_27634:
    goto v_27635;
v_27636:
    fn = elt(env, 3); // split!-further
    v_27699 = (*qfnn(fn))(fn, 3, v_27701, v_27700, v_27699);
    env = stack[-5];
    v_27700 = v_27699;
    v_27699 = v_27700;
    v_27699 = qcdr(v_27699);
    stack[-4] = v_27699;
    v_27699 = v_27700;
    v_27699 = qcar(v_27699);
    v_27700 = v_27699;
    goto v_27650;
v_27646:
    goto v_27647;
v_27648:
    v_27699 = stack[-1];
    goto v_27649;
v_27650:
    goto v_27646;
v_27647:
    goto v_27648;
v_27649:
    v_27699 = Lnconc(nil, v_27700, v_27699);
    env = stack[-5];
    stack[-1] = v_27699;
    v_27699 = stack[-4];
    if (v_27699 == nil) goto v_27655;
    else goto v_27656;
v_27655:
    v_27699 = stack[-1];
    goto v_27615;
v_27656:
    goto v_27667;
v_27663:
    v_27700 = qvalue(elt(env, 1)); // number!-needed
    goto v_27664;
v_27665:
    v_27699 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27666;
v_27667:
    goto v_27663;
v_27664:
    goto v_27665;
v_27666:
    if (v_27700 == v_27699) goto v_27661;
    else goto v_27662;
v_27661:
    goto v_27675;
v_27671:
    v_27700 = stack[-4];
    goto v_27672;
v_27673:
    v_27699 = stack[-1];
    goto v_27674;
v_27675:
    goto v_27671;
v_27672:
    goto v_27673;
v_27674:
        return Lnconc(nil, v_27700, v_27699);
v_27662:
    v_27699 = stack[0];
    v_27699 = (LispObject)((intptr_t)(v_27699) + 0x10);
    stack[0] = v_27699;
    goto v_27688;
v_27684:
    v_27700 = stack[0];
    goto v_27685;
v_27686:
    v_27699 = qvalue(elt(env, 2)); // current!-modulus
    goto v_27687;
v_27688:
    goto v_27684;
v_27685:
    goto v_27686;
v_27687:
    if (((intptr_t)(v_27700)) < ((intptr_t)(v_27699))) goto v_27682;
    else goto v_27683;
v_27682:
    goto v_27616;
v_27683:
    goto v_27696;
v_27692:
    v_27700 = stack[-4];
    goto v_27693;
v_27694:
    v_27699 = stack[-1];
    goto v_27695;
v_27696:
    goto v_27692;
v_27693:
    goto v_27694;
v_27695:
        return Lnconc(nil, v_27700, v_27699);
v_27615:
    return onevalue(v_27699);
}



// Code for cl_identifyonoff

static LispObject CC_cl_identifyonoff(LispObject env,
                         LispObject v_27606)
{
    env = qenv(env);
    LispObject v_27609;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27609 = v_27606;
// end of prologue
    v_27609 = nil;
    qvalue(elt(env, 1)) = v_27609; // cl_identify!-atl!*
    return onevalue(v_27609);
}



// Code for cl_rename!-vars1

static LispObject CC_cl_renameKvars1(LispObject env,
                         LispObject v_27606, LispObject v_27607)
{
    env = qenv(env);
    LispObject v_28244, v_28245, v_28246, v_28247;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27606,v_27607);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_27607;
    stack[0] = v_27606;
// end of prologue
    stack[-3] = nil;
    v_28244 = stack[0];
    if (!consp(v_28244)) goto v_27618;
    else goto v_27619;
v_27618:
    v_28244 = stack[0];
    goto v_27617;
v_27619:
    v_28244 = stack[0];
    v_28244 = qcar(v_28244);
    goto v_27617;
    v_28244 = nil;
v_27617:
    stack[-5] = v_28244;
    goto v_27646;
v_27642:
    v_28245 = stack[-5];
    goto v_27643;
v_27644:
    v_28244 = elt(env, 1); // or
    goto v_27645;
v_27646:
    goto v_27642;
v_27643:
    goto v_27644;
v_27645:
    if (v_28245 == v_28244) goto v_27640;
    else goto v_27641;
v_27640:
    v_28244 = lisp_true;
    goto v_27639;
v_27641:
    goto v_27656;
v_27652:
    v_28245 = stack[-5];
    goto v_27653;
v_27654:
    v_28244 = elt(env, 2); // and
    goto v_27655;
v_27656:
    goto v_27652;
v_27653:
    goto v_27654;
v_27655:
    v_28244 = (v_28245 == v_28244 ? lisp_true : nil);
    goto v_27639;
    v_28244 = nil;
v_27639:
    if (v_28244 == nil) goto v_27637;
    v_28244 = lisp_true;
    goto v_27635;
v_27637:
    goto v_27667;
v_27663:
    v_28245 = stack[-5];
    goto v_27664;
v_27665:
    v_28244 = elt(env, 3); // not
    goto v_27666;
v_27667:
    goto v_27663;
v_27664:
    goto v_27665;
v_27666:
    v_28244 = (v_28245 == v_28244 ? lisp_true : nil);
    goto v_27635;
    v_28244 = nil;
v_27635:
    if (v_28244 == nil) goto v_27633;
    v_28244 = lisp_true;
    goto v_27631;
v_27633:
    goto v_27682;
v_27678:
    v_28245 = stack[-5];
    goto v_27679;
v_27680:
    v_28244 = elt(env, 4); // impl
    goto v_27681;
v_27682:
    goto v_27678;
v_27679:
    goto v_27680;
v_27681:
    if (v_28245 == v_28244) goto v_27676;
    else goto v_27677;
v_27676:
    v_28244 = lisp_true;
    goto v_27675;
v_27677:
    goto v_27696;
v_27692:
    v_28245 = stack[-5];
    goto v_27693;
v_27694:
    v_28244 = elt(env, 5); // repl
    goto v_27695;
v_27696:
    goto v_27692;
v_27693:
    goto v_27694;
v_27695:
    if (v_28245 == v_28244) goto v_27690;
    else goto v_27691;
v_27690:
    v_28244 = lisp_true;
    goto v_27689;
v_27691:
    goto v_27706;
v_27702:
    v_28245 = stack[-5];
    goto v_27703;
v_27704:
    v_28244 = elt(env, 6); // equiv
    goto v_27705;
v_27706:
    goto v_27702;
v_27703:
    goto v_27704;
v_27705:
    v_28244 = (v_28245 == v_28244 ? lisp_true : nil);
    goto v_27689;
    v_28244 = nil;
v_27689:
    goto v_27675;
    v_28244 = nil;
v_27675:
    goto v_27631;
    v_28244 = nil;
v_27631:
    if (v_28244 == nil) goto v_27629;
    v_28244 = stack[0];
    v_28244 = qcdr(v_28244);
    stack[0] = v_28244;
v_27713:
    v_28244 = stack[0];
    if (v_28244 == nil) goto v_27718;
    else goto v_27719;
v_27718:
    goto v_27712;
v_27719:
    v_28244 = stack[0];
    v_28244 = qcar(v_28244);
    goto v_27733;
v_27729:
    v_28245 = v_28244;
    goto v_27730;
v_27731:
    v_28244 = stack[-4];
    goto v_27732;
v_27733:
    goto v_27729;
v_27730:
    goto v_27731;
v_27732:
    v_28244 = CC_cl_renameKvars1(elt(env, 0), v_28245, v_28244);
    env = stack[-7];
    v_28245 = v_28244;
    v_28244 = v_28245;
    v_28244 = qcar(v_28244);
    stack[-1] = v_28244;
    v_28244 = v_28245;
    v_28244 = qcdr(v_28244);
    stack[-4] = v_28244;
    goto v_27746;
v_27742:
    v_28245 = stack[-1];
    goto v_27743;
v_27744:
    v_28244 = stack[-3];
    goto v_27745;
v_27746:
    goto v_27742;
v_27743:
    goto v_27744;
v_27745:
    v_28244 = cons(v_28245, v_28244);
    env = stack[-7];
    stack[-3] = v_28244;
    v_28244 = stack[0];
    v_28244 = qcdr(v_28244);
    stack[0] = v_28244;
    goto v_27713;
v_27712:
    goto v_27759;
v_27753:
    v_28245 = stack[-5];
    goto v_27754;
v_27755:
    v_28244 = stack[-3];
    v_28246 = Lnreverse(nil, v_28244);
    goto v_27756;
v_27757:
    v_28244 = stack[-4];
    goto v_27758;
v_27759:
    goto v_27753;
v_27754:
    goto v_27755;
v_27756:
    goto v_27757;
v_27758:
    return acons(v_28245, v_28246, v_28244);
v_27629:
    goto v_27776;
v_27772:
    v_28245 = stack[-5];
    goto v_27773;
v_27774:
    v_28244 = elt(env, 7); // ex
    goto v_27775;
v_27776:
    goto v_27772;
v_27773:
    goto v_27774;
v_27775:
    if (v_28245 == v_28244) goto v_27770;
    else goto v_27771;
v_27770:
    v_28244 = lisp_true;
    goto v_27769;
v_27771:
    goto v_27786;
v_27782:
    v_28245 = stack[-5];
    goto v_27783;
v_27784:
    v_28244 = elt(env, 8); // all
    goto v_27785;
v_27786:
    goto v_27782;
v_27783:
    goto v_27784;
v_27785:
    v_28244 = (v_28245 == v_28244 ? lisp_true : nil);
    goto v_27769;
    v_28244 = nil;
v_27769:
    if (v_28244 == nil) goto v_27767;
    goto v_27798;
v_27794:
    v_28244 = stack[0];
    v_28244 = qcdr(v_28244);
    v_28244 = qcdr(v_28244);
    v_28245 = qcar(v_28244);
    goto v_27795;
v_27796:
    v_28244 = stack[-4];
    goto v_27797;
v_27798:
    goto v_27794;
v_27795:
    goto v_27796;
v_27797:
    v_28244 = CC_cl_renameKvars1(elt(env, 0), v_28245, v_28244);
    env = stack[-7];
    v_28245 = v_28244;
    v_28244 = v_28245;
    v_28244 = qcar(v_28244);
    stack[-1] = v_28244;
    v_28244 = v_28245;
    v_28244 = qcdr(v_28244);
    stack[-4] = v_28244;
    goto v_27813;
v_27809:
    v_28244 = stack[0];
    v_28244 = qcdr(v_28244);
    v_28245 = qcar(v_28244);
    goto v_27810;
v_27811:
    v_28244 = stack[-4];
    v_28244 = qcdr(v_28244);
    goto v_27812;
v_27813:
    goto v_27809;
v_27810:
    goto v_27811;
v_27812:
    v_28244 = Lassoc(nil, v_28245, v_28244);
    stack[-3] = v_28244;
    v_28244 = stack[-3];
    if (v_28244 == nil) goto v_27823;
    goto v_27834;
v_27830:
    v_28244 = stack[-3];
    v_28245 = qcdr(v_28244);
    goto v_27831;
v_27832:
    v_28244 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27833;
v_27834:
    goto v_27830;
v_27831:
    goto v_27832;
v_27833:
    v_28244 = Leqn(nil, v_28245, v_28244);
    env = stack[-7];
    if (v_28244 == nil) goto v_27828;
    goto v_27843;
v_27839:
    v_28245 = stack[-3];
    goto v_27840;
v_27841:
    v_28244 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27842;
v_27843:
    goto v_27839;
v_27840:
    goto v_27841;
v_27842:
    fn = elt(env, 12); // setcdr
    v_28244 = (*qfn2(fn))(fn, v_28245, v_28244);
    env = stack[-7];
    goto v_27851;
v_27847:
    goto v_27859;
v_27853:
    v_28246 = stack[-5];
    goto v_27854;
v_27855:
    v_28244 = stack[0];
    v_28244 = qcdr(v_28244);
    v_28245 = qcar(v_28244);
    goto v_27856;
v_27857:
    v_28244 = stack[-1];
    goto v_27858;
v_27859:
    goto v_27853;
v_27854:
    goto v_27855;
v_27856:
    goto v_27857;
v_27858:
    v_28245 = list3(v_28246, v_28245, v_28244);
    goto v_27848;
v_27849:
    v_28244 = stack[-4];
    goto v_27850;
v_27851:
    goto v_27847;
v_27848:
    goto v_27849;
v_27850:
    return cons(v_28245, v_28244);
v_27828:
v_27868:
    goto v_27874;
v_27870:
    v_28244 = stack[-3];
    v_28245 = qcar(v_28244);
    goto v_27871;
v_27872:
    v_28244 = stack[-3];
    v_28244 = qcdr(v_28244);
    goto v_27873;
v_27874:
    goto v_27870;
v_27871:
    goto v_27872;
v_27873:
    fn = elt(env, 13); // mkid
    v_28244 = (*qfn2(fn))(fn, v_28245, v_28244);
    env = stack[-7];
    stack[-2] = v_28244;
    goto v_27884;
v_27880:
    stack[0] = stack[-3];
    goto v_27881;
v_27882:
    v_28244 = stack[-3];
    v_28244 = qcdr(v_28244);
    v_28244 = add1(v_28244);
    env = stack[-7];
    goto v_27883;
v_27884:
    goto v_27880;
v_27881:
    goto v_27882;
v_27883:
    fn = elt(env, 12); // setcdr
    v_28244 = (*qfn2(fn))(fn, stack[0], v_28244);
    env = stack[-7];
    goto v_27898;
v_27894:
    v_28245 = stack[-2];
    goto v_27895;
v_27896:
    v_28244 = stack[-4];
    v_28244 = qcar(v_28244);
    goto v_27897;
v_27898:
    goto v_27894;
v_27895:
    goto v_27896;
v_27897:
    v_28244 = Lmemq(nil, v_28245, v_28244);
    if (v_28244 == nil) goto v_27893;
    else goto v_27891;
v_27893:
    v_28244 = stack[-2];
    if (!symbolp(v_28244)) v_28244 = nil;
    else { v_28244 = qfastgets(v_28244);
           if (v_28244 != nil) { v_28244 = elt(v_28244, 4); // avalue
#ifdef RECORD_GET
             if (v_28244 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_28244 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_28244 == SPID_NOPROP) v_28244 = nil; }}
#endif
    if (v_28244 == nil) goto v_27903;
    else goto v_27891;
v_27903:
    goto v_27892;
v_27891:
    goto v_27868;
v_27892:
    goto v_27911;
v_27907:
    stack[0] = stack[-4];
    goto v_27908;
v_27909:
    goto v_27918;
v_27914:
    v_28245 = stack[-2];
    goto v_27915;
v_27916:
    v_28244 = stack[-4];
    v_28244 = qcar(v_28244);
    goto v_27917;
v_27918:
    goto v_27914;
v_27915:
    goto v_27916;
v_27917:
    v_28244 = cons(v_28245, v_28244);
    env = stack[-7];
    goto v_27910;
v_27911:
    goto v_27907;
v_27908:
    goto v_27909;
v_27910:
    fn = elt(env, 14); // setcar
    v_28244 = (*qfn2(fn))(fn, stack[0], v_28244);
    env = stack[-7];
    goto v_27930;
v_27924:
    goto v_27925;
v_27926:
    stack[0] = elt(env, 9); // rl_varsubstat
    goto v_27927;
v_27928:
    goto v_27938;
v_27934:
    v_28245 = stack[-2];
    goto v_27935;
v_27936:
    v_28244 = stack[-3];
    v_28244 = qcar(v_28244);
    goto v_27937;
v_27938:
    goto v_27934;
v_27935:
    goto v_27936;
v_27937:
    v_28244 = list2(v_28245, v_28244);
    env = stack[-7];
    goto v_27929;
v_27930:
    goto v_27924;
v_27925:
    goto v_27926;
v_27927:
    goto v_27928;
v_27929:
    fn = elt(env, 15); // cl_apply2ats1
    v_28244 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_28244);
    env = stack[-7];
    stack[-1] = v_28244;
    goto v_27947;
v_27943:
    goto v_27955;
v_27949:
    v_28246 = stack[-5];
    goto v_27950;
v_27951:
    v_28245 = stack[-2];
    goto v_27952;
v_27953:
    v_28244 = stack[-1];
    goto v_27954;
v_27955:
    goto v_27949;
v_27950:
    goto v_27951;
v_27952:
    goto v_27953;
v_27954:
    v_28245 = list3(v_28246, v_28245, v_28244);
    goto v_27944;
v_27945:
    v_28244 = stack[-4];
    goto v_27946;
v_27947:
    goto v_27943;
v_27944:
    goto v_27945;
v_27946:
    return cons(v_28245, v_28244);
v_27823:
    goto v_27965;
v_27961:
    goto v_27973;
v_27967:
    v_28246 = stack[-5];
    goto v_27968;
v_27969:
    v_28244 = stack[0];
    v_28244 = qcdr(v_28244);
    v_28245 = qcar(v_28244);
    goto v_27970;
v_27971:
    v_28244 = stack[-1];
    goto v_27972;
v_27973:
    goto v_27967;
v_27968:
    goto v_27969;
v_27970:
    goto v_27971;
v_27972:
    v_28245 = list3(v_28246, v_28245, v_28244);
    goto v_27962;
v_27963:
    v_28244 = stack[-4];
    goto v_27964;
v_27965:
    goto v_27961;
v_27962:
    goto v_27963;
v_27964:
    return cons(v_28245, v_28244);
v_27767:
    goto v_27992;
v_27988:
    v_28245 = stack[-5];
    goto v_27989;
v_27990:
    v_28244 = elt(env, 10); // bex
    goto v_27991;
v_27992:
    goto v_27988;
v_27989:
    goto v_27990;
v_27991:
    if (v_28245 == v_28244) goto v_27986;
    else goto v_27987;
v_27986:
    v_28244 = lisp_true;
    goto v_27985;
v_27987:
    goto v_28002;
v_27998:
    v_28245 = stack[-5];
    goto v_27999;
v_28000:
    v_28244 = elt(env, 11); // ball
    goto v_28001;
v_28002:
    goto v_27998;
v_27999:
    goto v_28000;
v_28001:
    v_28244 = (v_28245 == v_28244 ? lisp_true : nil);
    goto v_27985;
    v_28244 = nil;
v_27985:
    if (v_28244 == nil) goto v_27983;
    goto v_28014;
v_28010:
    v_28244 = stack[0];
    v_28244 = qcdr(v_28244);
    v_28244 = qcdr(v_28244);
    v_28245 = qcar(v_28244);
    goto v_28011;
v_28012:
    v_28244 = stack[-4];
    goto v_28013;
v_28014:
    goto v_28010;
v_28011:
    goto v_28012;
v_28013:
    v_28244 = CC_cl_renameKvars1(elt(env, 0), v_28245, v_28244);
    env = stack[-7];
    v_28245 = v_28244;
    v_28244 = v_28245;
    v_28244 = qcar(v_28244);
    stack[-1] = v_28244;
    v_28244 = v_28245;
    v_28244 = qcdr(v_28244);
    stack[-4] = v_28244;
    goto v_28029;
v_28025:
    v_28244 = stack[0];
    v_28244 = qcdr(v_28244);
    v_28245 = qcar(v_28244);
    goto v_28026;
v_28027:
    v_28244 = stack[-4];
    v_28244 = qcdr(v_28244);
    goto v_28028;
v_28029:
    goto v_28025;
v_28026:
    goto v_28027;
v_28028:
    v_28244 = Lassoc(nil, v_28245, v_28244);
    stack[-3] = v_28244;
    v_28244 = stack[-3];
    if (v_28244 == nil) goto v_28039;
    goto v_28050;
v_28046:
    v_28244 = stack[-3];
    v_28245 = qcdr(v_28244);
    goto v_28047;
v_28048:
    v_28244 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28049;
v_28050:
    goto v_28046;
v_28047:
    goto v_28048;
v_28049:
    v_28244 = Leqn(nil, v_28245, v_28244);
    env = stack[-7];
    if (v_28244 == nil) goto v_28044;
    goto v_28059;
v_28055:
    v_28245 = stack[-3];
    goto v_28056;
v_28057:
    v_28244 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28058;
v_28059:
    goto v_28055;
v_28056:
    goto v_28057;
v_28058:
    fn = elt(env, 12); // setcdr
    v_28244 = (*qfn2(fn))(fn, v_28245, v_28244);
    env = stack[-7];
    goto v_28067;
v_28063:
    goto v_28077;
v_28069:
    v_28247 = stack[-5];
    goto v_28070;
v_28071:
    v_28244 = stack[0];
    v_28244 = qcdr(v_28244);
    v_28246 = qcar(v_28244);
    goto v_28072;
v_28073:
    v_28245 = stack[-1];
    goto v_28074;
v_28075:
    v_28244 = stack[0];
    v_28244 = qcdr(v_28244);
    v_28244 = qcdr(v_28244);
    v_28244 = qcdr(v_28244);
    v_28244 = qcar(v_28244);
    goto v_28076;
v_28077:
    goto v_28069;
v_28070:
    goto v_28071;
v_28072:
    goto v_28073;
v_28074:
    goto v_28075;
v_28076:
    v_28245 = list4(v_28247, v_28246, v_28245, v_28244);
    goto v_28064;
v_28065:
    v_28244 = stack[-4];
    goto v_28066;
v_28067:
    goto v_28063;
v_28064:
    goto v_28065;
v_28066:
    return cons(v_28245, v_28244);
v_28044:
v_28091:
    goto v_28097;
v_28093:
    v_28244 = stack[-3];
    v_28245 = qcar(v_28244);
    goto v_28094;
v_28095:
    v_28244 = stack[-3];
    v_28244 = qcdr(v_28244);
    goto v_28096;
v_28097:
    goto v_28093;
v_28094:
    goto v_28095;
v_28096:
    fn = elt(env, 13); // mkid
    v_28244 = (*qfn2(fn))(fn, v_28245, v_28244);
    env = stack[-7];
    stack[-2] = v_28244;
    goto v_28107;
v_28103:
    stack[-6] = stack[-3];
    goto v_28104;
v_28105:
    v_28244 = stack[-3];
    v_28244 = qcdr(v_28244);
    v_28244 = add1(v_28244);
    env = stack[-7];
    goto v_28106;
v_28107:
    goto v_28103;
v_28104:
    goto v_28105;
v_28106:
    fn = elt(env, 12); // setcdr
    v_28244 = (*qfn2(fn))(fn, stack[-6], v_28244);
    env = stack[-7];
    goto v_28121;
v_28117:
    v_28245 = stack[-2];
    goto v_28118;
v_28119:
    v_28244 = stack[-4];
    v_28244 = qcar(v_28244);
    goto v_28120;
v_28121:
    goto v_28117;
v_28118:
    goto v_28119;
v_28120:
    v_28244 = Lmemq(nil, v_28245, v_28244);
    if (v_28244 == nil) goto v_28116;
    else goto v_28114;
v_28116:
    v_28244 = stack[-2];
    if (!symbolp(v_28244)) v_28244 = nil;
    else { v_28244 = qfastgets(v_28244);
           if (v_28244 != nil) { v_28244 = elt(v_28244, 4); // avalue
#ifdef RECORD_GET
             if (v_28244 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_28244 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_28244 == SPID_NOPROP) v_28244 = nil; }}
#endif
    if (v_28244 == nil) goto v_28126;
    else goto v_28114;
v_28126:
    goto v_28115;
v_28114:
    goto v_28091;
v_28115:
    goto v_28134;
v_28130:
    stack[-6] = stack[-4];
    goto v_28131;
v_28132:
    goto v_28141;
v_28137:
    v_28245 = stack[-2];
    goto v_28138;
v_28139:
    v_28244 = stack[-4];
    v_28244 = qcar(v_28244);
    goto v_28140;
v_28141:
    goto v_28137;
v_28138:
    goto v_28139;
v_28140:
    v_28244 = cons(v_28245, v_28244);
    env = stack[-7];
    goto v_28133;
v_28134:
    goto v_28130;
v_28131:
    goto v_28132;
v_28133:
    fn = elt(env, 14); // setcar
    v_28244 = (*qfn2(fn))(fn, stack[-6], v_28244);
    env = stack[-7];
    goto v_28153;
v_28147:
    v_28244 = stack[0];
    v_28244 = qcdr(v_28244);
    v_28244 = qcdr(v_28244);
    v_28244 = qcdr(v_28244);
    stack[-6] = qcar(v_28244);
    goto v_28148;
v_28149:
    stack[0] = elt(env, 9); // rl_varsubstat
    goto v_28150;
v_28151:
    goto v_28165;
v_28161:
    v_28245 = stack[-2];
    goto v_28162;
v_28163:
    v_28244 = stack[-3];
    v_28244 = qcar(v_28244);
    goto v_28164;
v_28165:
    goto v_28161;
v_28162:
    goto v_28163;
v_28164:
    v_28244 = list2(v_28245, v_28244);
    env = stack[-7];
    goto v_28152;
v_28153:
    goto v_28147;
v_28148:
    goto v_28149;
v_28150:
    goto v_28151;
v_28152:
    fn = elt(env, 15); // cl_apply2ats1
    v_28244 = (*qfnn(fn))(fn, 3, stack[-6], stack[0], v_28244);
    env = stack[-7];
    stack[-6] = v_28244;
    goto v_28176;
v_28170:
    goto v_28171;
v_28172:
    stack[0] = elt(env, 9); // rl_varsubstat
    goto v_28173;
v_28174:
    goto v_28184;
v_28180:
    v_28245 = stack[-2];
    goto v_28181;
v_28182:
    v_28244 = stack[-3];
    v_28244 = qcar(v_28244);
    goto v_28183;
v_28184:
    goto v_28180;
v_28181:
    goto v_28182;
v_28183:
    v_28244 = list2(v_28245, v_28244);
    env = stack[-7];
    goto v_28175;
v_28176:
    goto v_28170;
v_28171:
    goto v_28172;
v_28173:
    goto v_28174;
v_28175:
    fn = elt(env, 15); // cl_apply2ats1
    v_28244 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_28244);
    env = stack[-7];
    stack[-1] = v_28244;
    goto v_28193;
v_28189:
    goto v_28203;
v_28195:
    v_28247 = stack[-5];
    goto v_28196;
v_28197:
    v_28246 = stack[-2];
    goto v_28198;
v_28199:
    v_28245 = stack[-1];
    goto v_28200;
v_28201:
    v_28244 = stack[-6];
    goto v_28202;
v_28203:
    goto v_28195;
v_28196:
    goto v_28197;
v_28198:
    goto v_28199;
v_28200:
    goto v_28201;
v_28202:
    v_28245 = list4(v_28247, v_28246, v_28245, v_28244);
    goto v_28190;
v_28191:
    v_28244 = stack[-4];
    goto v_28192;
v_28193:
    goto v_28189;
v_28190:
    goto v_28191;
v_28192:
    return cons(v_28245, v_28244);
v_28039:
    goto v_28214;
v_28210:
    goto v_28224;
v_28216:
    v_28247 = stack[-5];
    goto v_28217;
v_28218:
    v_28244 = stack[0];
    v_28244 = qcdr(v_28244);
    v_28246 = qcar(v_28244);
    goto v_28219;
v_28220:
    v_28245 = stack[-1];
    goto v_28221;
v_28222:
    v_28244 = stack[0];
    v_28244 = qcdr(v_28244);
    v_28244 = qcdr(v_28244);
    v_28244 = qcdr(v_28244);
    v_28244 = qcar(v_28244);
    goto v_28223;
v_28224:
    goto v_28216;
v_28217:
    goto v_28218;
v_28219:
    goto v_28220;
v_28221:
    goto v_28222;
v_28223:
    v_28245 = list4(v_28247, v_28246, v_28245, v_28244);
    goto v_28211;
v_28212:
    v_28244 = stack[-4];
    goto v_28213;
v_28214:
    goto v_28210;
v_28211:
    goto v_28212;
v_28213:
    return cons(v_28245, v_28244);
v_27983:
    goto v_28241;
v_28237:
    v_28245 = stack[0];
    goto v_28238;
v_28239:
    v_28244 = stack[-4];
    goto v_28240;
v_28241:
    goto v_28237;
v_28238:
    goto v_28239;
v_28240:
    return cons(v_28245, v_28244);
    return onevalue(v_28244);
}



// Code for cl_sacat

static LispObject CC_cl_sacat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27625, v_27626, v_27627;
    LispObject v_27608, v_27607, v_27606;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cl_sacat");
    va_start(aa, nargs);
    v_27606 = va_arg(aa, LispObject);
    v_27607 = va_arg(aa, LispObject);
    v_27608 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27625 = v_27608;
    v_27626 = v_27607;
    v_27627 = v_27606;
// end of prologue
    goto v_27618;
v_27614:
    v_27625 = v_27627;
    goto v_27615;
v_27616:
    goto v_27617;
v_27618:
    goto v_27614;
v_27615:
    goto v_27616;
v_27617:
    if (equal(v_27625, v_27626)) goto v_27612;
    else goto v_27613;
v_27612:
    v_27625 = elt(env, 1); // keep
    goto v_27611;
v_27613:
    v_27625 = nil;
    goto v_27611;
    v_27625 = nil;
v_27611:
    return onevalue(v_27625);
}



// Code for vdp_monp

static LispObject CC_vdp_monp(LispObject env,
                         LispObject v_27606)
{
    env = qenv(env);
    LispObject v_27611;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27606);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_27611 = v_27606;
// end of prologue
    fn = elt(env, 1); // vdp_poly
    v_27611 = (*qfn1(fn))(fn, v_27611);
    env = stack[0];
    {
        fn = elt(env, 2); // dip_monp
        return (*qfn1(fn))(fn, v_27611);
    }
}



// Code for ofsf_optfindeqsol

static LispObject CC_ofsf_optfindeqsol(LispObject env,
                         LispObject v_27606, LispObject v_27607)
{
    env = qenv(env);
    LispObject v_27699, v_27700;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27606,v_27607);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_27607;
    stack[-2] = v_27606;
// end of prologue
v_27605:
    v_27699 = stack[-2];
    v_27699 = qcar(v_27699);
    stack[-3] = v_27699;
    goto v_27627;
v_27623:
    v_27699 = stack[-3];
    v_27700 = qcar(v_27699);
    goto v_27624;
v_27625:
    v_27699 = elt(env, 1); // equal
    goto v_27626;
v_27627:
    goto v_27623;
v_27624:
    goto v_27625;
v_27626:
    if (v_27700 == v_27699) goto v_27621;
    else goto v_27622;
v_27621:
    goto v_27635;
v_27631:
    stack[0] = stack[-1];
    goto v_27632;
v_27633:
    v_27699 = stack[-3];
    fn = elt(env, 2); // ofsf_varlat
    v_27699 = (*qfn1(fn))(fn, v_27699);
    env = stack[-4];
    goto v_27634;
v_27635:
    goto v_27631;
v_27632:
    goto v_27633;
v_27634:
    v_27699 = Lmemq(nil, stack[0], v_27699);
    goto v_27620;
v_27622:
    v_27699 = nil;
    goto v_27620;
    v_27699 = nil;
v_27620:
    if (v_27699 == nil) goto v_27618;
    goto v_27648;
v_27644:
    v_27699 = stack[-3];
    v_27699 = qcdr(v_27699);
    v_27700 = qcar(v_27699);
    goto v_27645;
v_27646:
    v_27699 = stack[-1];
    goto v_27647;
v_27648:
    goto v_27644;
v_27645:
    goto v_27646;
v_27647:
    fn = elt(env, 3); // ofsf_optmksol
    v_27699 = (*qfn2(fn))(fn, v_27700, v_27699);
    env = stack[-4];
    stack[-1] = v_27699;
    goto v_27658;
v_27654:
    stack[-2] = stack[-3];
    goto v_27655;
v_27656:
    goto v_27665;
v_27661:
    goto v_27671;
v_27667:
    v_27699 = stack[-1];
    v_27700 = qcar(v_27699);
    goto v_27668;
v_27669:
    v_27699 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27670;
v_27671:
    goto v_27667;
v_27668:
    goto v_27669;
v_27670:
    stack[0] = cons(v_27700, v_27699);
    env = stack[-4];
    goto v_27662;
v_27663:
    goto v_27680;
v_27676:
    v_27699 = stack[-1];
    v_27700 = qcdr(v_27699);
    goto v_27677;
v_27678:
    v_27699 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27679;
v_27680:
    goto v_27676;
v_27677:
    goto v_27678;
v_27679:
    v_27699 = cons(v_27700, v_27699);
    env = stack[-4];
    goto v_27664;
v_27665:
    goto v_27661;
v_27662:
    goto v_27663;
v_27664:
    fn = elt(env, 4); // quotsq
    v_27699 = (*qfn2(fn))(fn, stack[0], v_27699);
    goto v_27657;
v_27658:
    goto v_27654;
v_27655:
    goto v_27656;
v_27657:
    {
        LispObject v_27705 = stack[-2];
        return cons(v_27705, v_27699);
    }
v_27618:
    v_27699 = stack[-2];
    v_27699 = qcdr(v_27699);
    if (v_27699 == nil) goto v_27687;
    goto v_27695;
v_27691:
    v_27699 = stack[-2];
    v_27700 = qcdr(v_27699);
    goto v_27692;
v_27693:
    v_27699 = stack[-1];
    goto v_27694;
v_27695:
    goto v_27691;
v_27692:
    goto v_27693;
v_27694:
    stack[-2] = v_27700;
    stack[-1] = v_27699;
    goto v_27605;
v_27687:
    v_27699 = nil;
    return onevalue(v_27699);
}



// Code for limitom

static LispObject CC_limitom(LispObject env,
                         LispObject v_27606)
{
    env = qenv(env);
    LispObject v_27708, v_27709, v_27710;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27606);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_27709 = v_27606;
// end of prologue
    v_27708 = v_27709;
    v_27708 = qcdr(v_27708);
    v_27708 = qcdr(v_27708);
    v_27708 = qcar(v_27708);
    stack[-2] = v_27708;
    v_27708 = v_27709;
    v_27708 = qcdr(v_27708);
    v_27708 = qcdr(v_27708);
    v_27708 = qcdr(v_27708);
    v_27708 = qcar(v_27708);
    stack[0] = v_27708;
    v_27708 = v_27709;
    v_27708 = Lreverse(nil, v_27708);
    env = stack[-4];
    v_27708 = qcar(v_27708);
    stack[-3] = v_27708;
    v_27708 = elt(env, 1); // "<OMA>"
    fn = elt(env, 10); // printout
    v_27708 = (*qfn1(fn))(fn, v_27708);
    env = stack[-4];
    v_27708 = lisp_true;
    fn = elt(env, 11); // indent!*
    v_27708 = (*qfn1(fn))(fn, v_27708);
    env = stack[-4];
    v_27708 = elt(env, 2); // "<OMS cd=""limit1"" name=""limit""/>"
    fn = elt(env, 10); // printout
    v_27708 = (*qfn1(fn))(fn, v_27708);
    env = stack[-4];
    goto v_27640;
v_27636:
    v_27708 = stack[0];
    v_27709 = qcar(v_27708);
    goto v_27637;
v_27638:
    v_27708 = elt(env, 3); // lowlimit
    goto v_27639;
v_27640:
    goto v_27636;
v_27637:
    goto v_27638;
v_27639:
    if (v_27709 == v_27708) goto v_27634;
    else goto v_27635;
v_27634:
    v_27708 = stack[0];
    v_27708 = qcdr(v_27708);
    v_27708 = qcar(v_27708);
    fn = elt(env, 12); // objectom
    v_27708 = (*qfn1(fn))(fn, v_27708);
    env = stack[-4];
    v_27708 = elt(env, 4); // "<OMS cd=""limit1"" name=""null""/>"
    fn = elt(env, 10); // printout
    v_27708 = (*qfn1(fn))(fn, v_27708);
    env = stack[-4];
    goto v_27633;
v_27635:
v_27633:
    goto v_27658;
v_27654:
    v_27708 = stack[0];
    v_27709 = qcar(v_27708);
    goto v_27655;
v_27656:
    v_27708 = elt(env, 5); // condition
    goto v_27657;
v_27658:
    goto v_27654;
v_27655:
    goto v_27656;
v_27657:
    if (v_27709 == v_27708) goto v_27652;
    else goto v_27653;
v_27652:
    v_27708 = stack[0];
    v_27708 = qcdr(v_27708);
    v_27708 = qcar(v_27708);
    v_27708 = Lreverse(nil, v_27708);
    env = stack[-4];
    v_27708 = qcar(v_27708);
    fn = elt(env, 12); // objectom
    v_27708 = (*qfn1(fn))(fn, v_27708);
    env = stack[-4];
    v_27708 = stack[0];
    v_27708 = qcdr(v_27708);
    v_27708 = qcar(v_27708);
    v_27708 = qcdr(v_27708);
    v_27708 = qcar(v_27708);
    v_27708 = qcar(v_27708);
    v_27708 = qcdr(v_27708);
    v_27708 = qcar(v_27708);
    stack[0] = v_27708;
    v_27708 = elt(env, 6); // "<OMS cd=""limit1"" name="""
    fn = elt(env, 10); // printout
    v_27708 = (*qfn1(fn))(fn, v_27708);
    env = stack[-4];
    v_27708 = stack[0];
    v_27708 = Lprinc(nil, v_27708);
    env = stack[-4];
    v_27708 = elt(env, 7); // """/>"
    v_27708 = Lprinc(nil, v_27708);
    env = stack[-4];
    goto v_27651;
v_27653:
v_27651:
    goto v_27690;
v_27684:
    stack[-1] = elt(env, 8); // limit
    goto v_27685;
v_27686:
    stack[0] = nil;
    goto v_27687;
v_27688:
    goto v_27700;
v_27694:
    v_27710 = stack[-2];
    goto v_27695;
v_27696:
    v_27709 = stack[-3];
    goto v_27697;
v_27698:
    v_27708 = nil;
    goto v_27699;
v_27700:
    goto v_27694;
v_27695:
    goto v_27696;
v_27697:
    goto v_27698;
v_27699:
    v_27708 = list2star(v_27710, v_27709, v_27708);
    env = stack[-4];
    goto v_27689;
v_27690:
    goto v_27684;
v_27685:
    goto v_27686;
v_27687:
    goto v_27688;
v_27689:
    v_27708 = list2star(stack[-1], stack[0], v_27708);
    env = stack[-4];
    fn = elt(env, 13); // lambdaom
    v_27708 = (*qfn1(fn))(fn, v_27708);
    env = stack[-4];
    v_27708 = nil;
    fn = elt(env, 11); // indent!*
    v_27708 = (*qfn1(fn))(fn, v_27708);
    env = stack[-4];
    v_27708 = elt(env, 9); // "</OMA>"
    fn = elt(env, 10); // printout
    v_27708 = (*qfn1(fn))(fn, v_27708);
    v_27708 = nil;
    return onevalue(v_27708);
}



// Code for i2ps

static LispObject CC_i2ps(LispObject env,
                         LispObject v_27606)
{
    env = qenv(env);
    LispObject v_27609;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27609 = v_27606;
// end of prologue
    return onevalue(v_27609);
}



// Code for asymmetrize!-inds

static LispObject CC_asymmetrizeKinds(LispObject env,
                         LispObject v_27606, LispObject v_27607)
{
    env = qenv(env);
    LispObject v_27943, v_27944;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27606,v_27607);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-8] = v_27607;
    stack[-9] = v_27606;
// end of prologue
    v_27943 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-10] = v_27943;
    v_27943 = stack[-9];
    stack[-7] = v_27943;
    v_27943 = stack[-7];
    if (v_27943 == nil) goto v_27627;
    else goto v_27628;
v_27627:
    v_27943 = nil;
    goto v_27622;
v_27628:
    v_27943 = stack[-7];
    v_27943 = qcar(v_27943);
    v_27944 = v_27943;
    if (!consp(v_27944)) goto v_27637;
    else goto v_27638;
v_27637:
    goto v_27645;
v_27641:
    v_27944 = stack[-8];
    goto v_27642;
v_27643:
    goto v_27644;
v_27645:
    goto v_27641;
v_27642:
    goto v_27643;
v_27644:
    fn = elt(env, 1); // nth
    v_27943 = (*qfn2(fn))(fn, v_27944, v_27943);
    env = stack[-11];
    goto v_27636;
v_27638:
    stack[-3] = v_27943;
    v_27943 = stack[-3];
    if (v_27943 == nil) goto v_27659;
    else goto v_27660;
v_27659:
    v_27943 = nil;
    goto v_27654;
v_27660:
    v_27943 = stack[-3];
    v_27943 = qcar(v_27943);
    goto v_27672;
v_27668:
    v_27944 = stack[-8];
    goto v_27669;
v_27670:
    goto v_27671;
v_27672:
    goto v_27668;
v_27669:
    goto v_27670;
v_27671:
    fn = elt(env, 1); // nth
    v_27943 = (*qfn2(fn))(fn, v_27944, v_27943);
    env = stack[-11];
    v_27943 = ncons(v_27943);
    env = stack[-11];
    stack[-1] = v_27943;
    stack[-2] = v_27943;
v_27655:
    v_27943 = stack[-3];
    v_27943 = qcdr(v_27943);
    stack[-3] = v_27943;
    v_27943 = stack[-3];
    if (v_27943 == nil) goto v_27679;
    else goto v_27680;
v_27679:
    v_27943 = stack[-2];
    goto v_27654;
v_27680:
    goto v_27688;
v_27684:
    stack[0] = stack[-1];
    goto v_27685;
v_27686:
    v_27943 = stack[-3];
    v_27943 = qcar(v_27943);
    goto v_27699;
v_27695:
    v_27944 = stack[-8];
    goto v_27696;
v_27697:
    goto v_27698;
v_27699:
    goto v_27695;
v_27696:
    goto v_27697;
v_27698:
    fn = elt(env, 1); // nth
    v_27943 = (*qfn2(fn))(fn, v_27944, v_27943);
    env = stack[-11];
    v_27943 = ncons(v_27943);
    env = stack[-11];
    goto v_27687;
v_27688:
    goto v_27684;
v_27685:
    goto v_27686;
v_27687:
    v_27943 = Lrplacd(nil, stack[0], v_27943);
    env = stack[-11];
    v_27943 = stack[-1];
    v_27943 = qcdr(v_27943);
    stack[-1] = v_27943;
    goto v_27655;
v_27654:
    goto v_27636;
    v_27943 = nil;
v_27636:
    v_27943 = ncons(v_27943);
    env = stack[-11];
    stack[-5] = v_27943;
    stack[-6] = v_27943;
v_27623:
    v_27943 = stack[-7];
    v_27943 = qcdr(v_27943);
    stack[-7] = v_27943;
    v_27943 = stack[-7];
    if (v_27943 == nil) goto v_27708;
    else goto v_27709;
v_27708:
    v_27943 = stack[-6];
    goto v_27622;
v_27709:
    goto v_27717;
v_27713:
    stack[-4] = stack[-5];
    goto v_27714;
v_27715:
    v_27943 = stack[-7];
    v_27943 = qcar(v_27943);
    v_27944 = v_27943;
    if (!consp(v_27944)) goto v_27725;
    else goto v_27726;
v_27725:
    goto v_27733;
v_27729:
    v_27944 = stack[-8];
    goto v_27730;
v_27731:
    goto v_27732;
v_27733:
    goto v_27729;
v_27730:
    goto v_27731;
v_27732:
    fn = elt(env, 1); // nth
    v_27943 = (*qfn2(fn))(fn, v_27944, v_27943);
    env = stack[-11];
    goto v_27724;
v_27726:
    stack[-3] = v_27943;
    v_27943 = stack[-3];
    if (v_27943 == nil) goto v_27747;
    else goto v_27748;
v_27747:
    v_27943 = nil;
    goto v_27742;
v_27748:
    v_27943 = stack[-3];
    v_27943 = qcar(v_27943);
    goto v_27760;
v_27756:
    v_27944 = stack[-8];
    goto v_27757;
v_27758:
    goto v_27759;
v_27760:
    goto v_27756;
v_27757:
    goto v_27758;
v_27759:
    fn = elt(env, 1); // nth
    v_27943 = (*qfn2(fn))(fn, v_27944, v_27943);
    env = stack[-11];
    v_27943 = ncons(v_27943);
    env = stack[-11];
    stack[-1] = v_27943;
    stack[-2] = v_27943;
v_27743:
    v_27943 = stack[-3];
    v_27943 = qcdr(v_27943);
    stack[-3] = v_27943;
    v_27943 = stack[-3];
    if (v_27943 == nil) goto v_27767;
    else goto v_27768;
v_27767:
    v_27943 = stack[-2];
    goto v_27742;
v_27768:
    goto v_27776;
v_27772:
    stack[0] = stack[-1];
    goto v_27773;
v_27774:
    v_27943 = stack[-3];
    v_27943 = qcar(v_27943);
    goto v_27787;
v_27783:
    v_27944 = stack[-8];
    goto v_27784;
v_27785:
    goto v_27786;
v_27787:
    goto v_27783;
v_27784:
    goto v_27785;
v_27786:
    fn = elt(env, 1); // nth
    v_27943 = (*qfn2(fn))(fn, v_27944, v_27943);
    env = stack[-11];
    v_27943 = ncons(v_27943);
    env = stack[-11];
    goto v_27775;
v_27776:
    goto v_27772;
v_27773:
    goto v_27774;
v_27775:
    v_27943 = Lrplacd(nil, stack[0], v_27943);
    env = stack[-11];
    v_27943 = stack[-1];
    v_27943 = qcdr(v_27943);
    stack[-1] = v_27943;
    goto v_27743;
v_27742:
    goto v_27724;
    v_27943 = nil;
v_27724:
    v_27943 = ncons(v_27943);
    env = stack[-11];
    goto v_27716;
v_27717:
    goto v_27713;
v_27714:
    goto v_27715;
v_27716:
    v_27943 = Lrplacd(nil, stack[-4], v_27943);
    env = stack[-11];
    v_27943 = stack[-5];
    v_27943 = qcdr(v_27943);
    stack[-5] = v_27943;
    goto v_27623;
v_27622:
    stack[0] = v_27943;
    v_27943 = stack[0];
    fn = elt(env, 2); // repeats
    v_27943 = (*qfn1(fn))(fn, v_27943);
    env = stack[-11];
    if (v_27943 == nil) goto v_27797;
    v_27943 = nil;
    goto v_27615;
v_27797:
    goto v_27810;
v_27806:
    v_27943 = stack[0];
    v_27943 = qcar(v_27943);
    if (!consp(v_27943)) goto v_27813;
    else goto v_27814;
v_27813:
    v_27943 = stack[0];
    fn = elt(env, 3); // indordn
    v_27943 = (*qfn1(fn))(fn, v_27943);
    env = stack[-11];
    v_27944 = v_27943;
    goto v_27812;
v_27814:
    v_27943 = stack[0];
    fn = elt(env, 4); // indordln
    v_27943 = (*qfn1(fn))(fn, v_27943);
    env = stack[-11];
    v_27944 = v_27943;
    goto v_27812;
    v_27944 = nil;
v_27812:
    stack[-5] = v_27944;
    goto v_27807;
v_27808:
    v_27943 = stack[0];
    goto v_27809;
v_27810:
    goto v_27806;
v_27807:
    goto v_27808;
v_27809:
    fn = elt(env, 5); // permp
    v_27943 = (*qfn2(fn))(fn, v_27944, v_27943);
    env = stack[-11];
    if (v_27943 == nil) goto v_27804;
    v_27943 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27802;
v_27804:
    v_27943 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_27802;
    v_27943 = nil;
v_27802:
    stack[0] = v_27943;
    v_27943 = stack[-9];
    v_27943 = qcar(v_27943);
    if (!consp(v_27943)) goto v_27831;
    v_27943 = stack[-9];
    fn = elt(env, 6); // flatindl
    v_27943 = (*qfn1(fn))(fn, v_27943);
    env = stack[-11];
    stack[-9] = v_27943;
    v_27943 = stack[-5];
    fn = elt(env, 6); // flatindl
    v_27943 = (*qfn1(fn))(fn, v_27943);
    env = stack[-11];
    stack[-5] = v_27943;
    goto v_27829;
v_27831:
v_27829:
    goto v_27843;
v_27839:
    v_27944 = stack[-9];
    goto v_27840;
v_27841:
    v_27943 = stack[-5];
    goto v_27842;
v_27843:
    goto v_27839;
v_27840:
    goto v_27841;
v_27842:
    fn = elt(env, 7); // pair
    v_27943 = (*qfn2(fn))(fn, v_27944, v_27943);
    env = stack[-11];
    stack[-5] = v_27943;
    goto v_27851;
v_27847:
    stack[-6] = stack[0];
    goto v_27848;
v_27849:
    v_27943 = stack[-8];
    stack[-7] = v_27943;
    v_27943 = stack[-7];
    if (v_27943 == nil) goto v_27862;
    else goto v_27863;
v_27862:
    v_27943 = nil;
    goto v_27857;
v_27863:
    v_27943 = stack[-7];
    v_27943 = qcar(v_27943);
    stack[-1] = v_27943;
    v_27943 = stack[-5];
    if (v_27943 == nil) goto v_27873;
    goto v_27881;
v_27877:
    v_27943 = stack[-5];
    v_27943 = qcar(v_27943);
    stack[0] = qcar(v_27943);
    goto v_27878;
v_27879:
    v_27943 = stack[-10];
    v_27943 = add1(v_27943);
    env = stack[-11];
    stack[-10] = v_27943;
    goto v_27880;
v_27881:
    goto v_27877;
v_27878:
    goto v_27879;
v_27880:
    if (equal(stack[0], v_27943)) goto v_27876;
    else goto v_27873;
v_27876:
    v_27943 = stack[-5];
    v_27943 = qcar(v_27943);
    v_27943 = qcdr(v_27943);
    v_27944 = v_27943;
    v_27943 = stack[-5];
    v_27943 = qcdr(v_27943);
    stack[-5] = v_27943;
    v_27943 = v_27944;
    goto v_27871;
v_27873:
    v_27943 = stack[-1];
    goto v_27871;
    v_27943 = nil;
v_27871:
    v_27943 = ncons(v_27943);
    env = stack[-11];
    stack[-3] = v_27943;
    stack[-4] = v_27943;
v_27858:
    v_27943 = stack[-7];
    v_27943 = qcdr(v_27943);
    stack[-7] = v_27943;
    v_27943 = stack[-7];
    if (v_27943 == nil) goto v_27900;
    else goto v_27901;
v_27900:
    v_27943 = stack[-4];
    goto v_27857;
v_27901:
    goto v_27909;
v_27905:
    stack[-2] = stack[-3];
    goto v_27906;
v_27907:
    v_27943 = stack[-7];
    v_27943 = qcar(v_27943);
    stack[-1] = v_27943;
    v_27943 = stack[-5];
    if (v_27943 == nil) goto v_27918;
    goto v_27926;
v_27922:
    v_27943 = stack[-5];
    v_27943 = qcar(v_27943);
    stack[0] = qcar(v_27943);
    goto v_27923;
v_27924:
    v_27943 = stack[-10];
    v_27943 = add1(v_27943);
    env = stack[-11];
    stack[-10] = v_27943;
    goto v_27925;
v_27926:
    goto v_27922;
v_27923:
    goto v_27924;
v_27925:
    if (equal(stack[0], v_27943)) goto v_27921;
    else goto v_27918;
v_27921:
    v_27943 = stack[-5];
    v_27943 = qcar(v_27943);
    v_27943 = qcdr(v_27943);
    v_27944 = v_27943;
    v_27943 = stack[-5];
    v_27943 = qcdr(v_27943);
    stack[-5] = v_27943;
    v_27943 = v_27944;
    goto v_27916;
v_27918:
    v_27943 = stack[-1];
    goto v_27916;
    v_27943 = nil;
v_27916:
    v_27943 = ncons(v_27943);
    env = stack[-11];
    goto v_27908;
v_27909:
    goto v_27905;
v_27906:
    goto v_27907;
v_27908:
    v_27943 = Lrplacd(nil, stack[-2], v_27943);
    env = stack[-11];
    v_27943 = stack[-3];
    v_27943 = qcdr(v_27943);
    stack[-3] = v_27943;
    goto v_27858;
v_27857:
    goto v_27850;
v_27851:
    goto v_27847;
v_27848:
    goto v_27849;
v_27850:
    {
        LispObject v_27956 = stack[-6];
        return cons(v_27956, v_27943);
    }
v_27615:
    return onevalue(v_27943);
}



// Code for defined_all_edge

static LispObject CC_defined_all_edge(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27683, v_27684, v_27685;
    LispObject fn;
    LispObject v_27608, v_27607, v_27606;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "defined_all_edge");
    va_start(aa, nargs);
    v_27606 = va_arg(aa, LispObject);
    v_27607 = va_arg(aa, LispObject);
    v_27608 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27608,v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27606,v_27607,v_27608);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_27608;
    stack[-1] = v_27607;
    stack[-2] = v_27606;
// end of prologue
v_27613:
    v_27683 = stack[-2];
    if (v_27683 == nil) goto v_27616;
    else goto v_27617;
v_27616:
    v_27683 = nil;
    goto v_27612;
v_27617:
    goto v_27627;
v_27623:
    v_27683 = stack[-2];
    v_27684 = qcar(v_27683);
    goto v_27624;
v_27625:
    v_27683 = stack[0];
    goto v_27626;
v_27627:
    goto v_27623;
v_27624:
    goto v_27625;
v_27626:
    fn = elt(env, 1); // def_edge
    v_27683 = (*qfn2(fn))(fn, v_27684, v_27683);
    env = stack[-4];
    if (v_27683 == nil) goto v_27621;
    v_27683 = stack[-2];
    v_27683 = qcar(v_27683);
    fn = elt(env, 2); // p_def_edge
    v_27683 = (*qfn1(fn))(fn, v_27683);
    env = stack[-4];
    if (v_27683 == nil) goto v_27634;
    v_27683 = lisp_true;
    goto v_27612;
v_27634:
    goto v_27646;
v_27642:
    goto v_27652;
v_27648:
    v_27684 = stack[-1];
    goto v_27649;
v_27650:
    v_27683 = stack[-2];
    goto v_27651;
v_27652:
    goto v_27648;
v_27649:
    goto v_27650;
v_27651:
    stack[0] = Lnconc(nil, v_27684, v_27683);
    env = stack[-4];
    goto v_27643;
v_27644:
    goto v_27662;
v_27656:
    v_27683 = stack[-2];
    v_27683 = qcar(v_27683);
    v_27683 = qcdr(v_27683);
    v_27685 = qcar(v_27683);
    goto v_27657;
v_27658:
    v_27684 = lisp_true;
    goto v_27659;
v_27660:
    v_27683 = nil;
    goto v_27661;
v_27662:
    goto v_27656;
v_27657:
    goto v_27658;
v_27659:
    goto v_27660;
v_27661:
    v_27683 = list2star(v_27685, v_27684, v_27683);
    env = stack[-4];
    goto v_27645;
v_27646:
    goto v_27642;
v_27643:
    goto v_27644;
v_27645:
    {
        LispObject v_27690 = stack[0];
        fn = elt(env, 3); // rep_edge_prop_
        return (*qfn2(fn))(fn, v_27690, v_27683);
    }
    goto v_27615;
v_27621:
    v_27683 = stack[-2];
    v_27683 = qcdr(v_27683);
    stack[-3] = v_27683;
    goto v_27678;
v_27674:
    v_27683 = stack[-2];
    v_27684 = qcar(v_27683);
    goto v_27675;
v_27676:
    v_27683 = stack[-1];
    goto v_27677;
v_27678:
    goto v_27674;
v_27675:
    goto v_27676;
v_27677:
    v_27683 = cons(v_27684, v_27683);
    env = stack[-4];
    stack[-1] = v_27683;
    v_27683 = stack[-3];
    stack[-2] = v_27683;
    goto v_27613;
v_27615:
    v_27683 = nil;
v_27612:
    return onevalue(v_27683);
}



// Code for random!-small!-prime

static LispObject CC_randomKsmallKprime(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27629;
    LispObject fn;
    argcheck(nargs, 0, "random-small-prime");
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
v_27612:
    fn = elt(env, 1); // small!-random!-number
    v_27629 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_27629;
    v_27629 = stack[0];
    v_27629 = Levenp(nil, v_27629);
    env = stack[-1];
    if (v_27629 == nil) goto v_27617;
    v_27629 = stack[0];
    v_27629 = (LispObject)((intptr_t)(v_27629) + 0x10);
    stack[0] = v_27629;
    goto v_27615;
v_27617:
v_27615:
    v_27629 = stack[0];
    fn = elt(env, 2); // primep
    v_27629 = (*qfn1(fn))(fn, v_27629);
    env = stack[-1];
    if (v_27629 == nil) goto v_27624;
    else goto v_27625;
v_27624:
    goto v_27612;
v_27625:
    v_27629 = stack[0];
    return onevalue(v_27629);
}



// Code for polynomreduceby

static LispObject CC_polynomreduceby(LispObject env,
                         LispObject v_27606, LispObject v_27607)
{
    env = qenv(env);
    LispObject v_27688, v_27689;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27606,v_27607);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_27607;
    stack[-2] = v_27606;
// end of prologue
    stack[-3] = nil;
v_27616:
    v_27688 = stack[-3];
    if (v_27688 == nil) goto v_27620;
    goto v_27615;
v_27620:
    v_27688 = stack[-2];
    stack[0] = v_27688;
v_27626:
    v_27688 = stack[0];
    v_27688 = qcar(v_27688);
    if (v_27688 == nil) goto v_27629;
    goto v_27640;
v_27636:
    v_27688 = stack[0];
    v_27689 = qcar(v_27688);
    goto v_27637;
v_27638:
    v_27688 = stack[-1];
    v_27688 = qcar(v_27688);
    goto v_27639;
v_27640:
    goto v_27636;
v_27637:
    goto v_27638;
v_27639:
    fn = elt(env, 2); // monomisdivisibleby
    v_27688 = (*qfn2(fn))(fn, v_27689, v_27688);
    env = stack[-4];
    if (v_27688 == nil) goto v_27634;
    else goto v_27629;
v_27634:
    goto v_27630;
v_27629:
    goto v_27625;
v_27630:
    v_27688 = stack[0];
    v_27688 = qcdr(v_27688);
    stack[0] = v_27688;
    goto v_27626;
v_27625:
    v_27688 = stack[0];
    v_27688 = qcar(v_27688);
    if (v_27688 == nil) goto v_27651;
    else goto v_27652;
v_27651:
    v_27688 = lisp_true;
    stack[-3] = v_27688;
    goto v_27650;
v_27652:
    goto v_27664;
v_27660:
    v_27688 = stack[0];
    v_27689 = qcar(v_27688);
    goto v_27661;
v_27662:
    v_27688 = stack[-1];
    v_27688 = qcar(v_27688);
    goto v_27663;
v_27664:
    goto v_27660;
v_27661:
    goto v_27662;
v_27663:
    fn = elt(env, 3); // monomdivide
    v_27688 = (*qfn2(fn))(fn, v_27689, v_27688);
    env = stack[-4];
    goto v_27674;
v_27670:
    stack[0] = stack[-2];
    goto v_27671;
v_27672:
    goto v_27681;
v_27677:
    v_27689 = stack[-1];
    goto v_27678;
v_27679:
    goto v_27680;
v_27681:
    goto v_27677;
v_27678:
    goto v_27679;
v_27680:
    fn = elt(env, 4); // polynommultiplybymonom
    v_27688 = (*qfn2(fn))(fn, v_27689, v_27688);
    env = stack[-4];
    goto v_27673;
v_27674:
    goto v_27670;
v_27671:
    goto v_27672;
v_27673:
    fn = elt(env, 5); // polynomadd
    v_27688 = (*qfn2(fn))(fn, stack[0], v_27688);
    env = stack[-4];
    goto v_27650;
v_27650:
    goto v_27616;
v_27615:
    v_27688 = qvalue(elt(env, 1)); // fluidbibasisreductionsmade
    v_27688 = (LispObject)((intptr_t)(v_27688) + 0x10);
    qvalue(elt(env, 1)) = v_27688; // fluidbibasisreductionsmade
    v_27688 = nil;
    return onevalue(v_27688);
}



// Code for checkexp

static LispObject CC_checkexp(LispObject env,
                         LispObject v_27606, LispObject v_27607)
{
    env = qenv(env);
    LispObject v_27645, v_27646, v_27647, v_27648;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27607,v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27606,v_27607);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_27647 = v_27607;
    v_27648 = v_27606;
// end of prologue
    goto v_27617;
v_27613:
    v_27646 = v_27647;
    goto v_27614;
v_27615:
    v_27645 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27616;
v_27617:
    goto v_27613;
v_27614:
    goto v_27615;
v_27616:
    if (v_27646 == v_27645) goto v_27611;
    else goto v_27612;
v_27611:
    v_27645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27610;
v_27612:
    goto v_27627;
v_27623:
    v_27646 = v_27647;
    goto v_27624;
v_27625:
    v_27645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27626;
v_27627:
    goto v_27623;
v_27624:
    goto v_27625;
v_27626:
    if (v_27646 == v_27645) goto v_27621;
    else goto v_27622;
v_27621:
    v_27645 = v_27648;
    goto v_27610;
v_27622:
    goto v_27640;
v_27634:
    stack[-1] = elt(env, 1); // expt
    goto v_27635;
v_27636:
    stack[0] = v_27648;
    goto v_27637;
v_27638:
    v_27645 = v_27647;
    fn = elt(env, 2); // preptayexp
    v_27645 = (*qfn1(fn))(fn, v_27645);
    goto v_27639;
v_27640:
    goto v_27634;
v_27635:
    goto v_27636;
v_27637:
    goto v_27638;
v_27639:
    {
        LispObject v_27651 = stack[-1];
        LispObject v_27652 = stack[0];
        return list3(v_27651, v_27652, v_27645);
    }
    v_27645 = nil;
v_27610:
    return onevalue(v_27645);
}



// Code for f2df

static LispObject CC_f2df(LispObject env,
                         LispObject v_27606)
{
    env = qenv(env);
    LispObject v_27722, v_27723, v_27724;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27606);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27606);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27606;
// end of prologue
    v_27722 = stack[0];
    if (!consp(v_27722)) goto v_27614;
    else goto v_27615;
v_27614:
    v_27722 = lisp_true;
    goto v_27613;
v_27615:
    v_27722 = stack[0];
    v_27722 = qcar(v_27722);
    v_27722 = (consp(v_27722) ? nil : lisp_true);
    goto v_27613;
    v_27722 = nil;
v_27613:
    if (v_27722 == nil) goto v_27611;
    goto v_27629;
v_27625:
    v_27723 = stack[0];
    goto v_27626;
v_27627:
    v_27722 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27628;
v_27629:
    goto v_27625;
v_27626:
    goto v_27627;
v_27628:
    v_27722 = cons(v_27723, v_27722);
    env = stack[-2];
    {
        fn = elt(env, 2); // dfconst
        return (*qfn1(fn))(fn, v_27722);
    }
v_27611:
    goto v_27638;
v_27634:
    v_27722 = stack[0];
    v_27722 = qcar(v_27722);
    v_27722 = qcar(v_27722);
    v_27723 = qcar(v_27722);
    goto v_27635;
v_27636:
    v_27722 = qvalue(elt(env, 1)); // zlist
    goto v_27637;
v_27638:
    goto v_27634;
v_27635:
    goto v_27636;
v_27637:
    v_27722 = Lmember(nil, v_27723, v_27722);
    if (v_27722 == nil) goto v_27633;
    goto v_27650;
v_27646:
    goto v_27656;
v_27652:
    goto v_27664;
v_27658:
    v_27722 = stack[0];
    v_27722 = qcar(v_27722);
    v_27722 = qcar(v_27722);
    v_27724 = qcar(v_27722);
    goto v_27659;
v_27660:
    v_27722 = stack[0];
    v_27722 = qcar(v_27722);
    v_27722 = qcar(v_27722);
    v_27723 = qcdr(v_27722);
    goto v_27661;
v_27662:
    v_27722 = qvalue(elt(env, 1)); // zlist
    goto v_27663;
v_27664:
    goto v_27658;
v_27659:
    goto v_27660;
v_27661:
    goto v_27662;
v_27663:
    fn = elt(env, 3); // vp2df
    stack[-1] = (*qfnn(fn))(fn, 3, v_27724, v_27723, v_27722);
    env = stack[-2];
    goto v_27653;
v_27654:
    v_27722 = stack[0];
    v_27722 = qcar(v_27722);
    v_27722 = qcdr(v_27722);
    v_27722 = CC_f2df(elt(env, 0), v_27722);
    env = stack[-2];
    goto v_27655;
v_27656:
    goto v_27652;
v_27653:
    goto v_27654;
v_27655:
    fn = elt(env, 4); // multdf
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_27722);
    env = stack[-2];
    goto v_27647;
v_27648:
    v_27722 = stack[0];
    v_27722 = qcdr(v_27722);
    v_27722 = CC_f2df(elt(env, 0), v_27722);
    env = stack[-2];
    goto v_27649;
v_27650:
    goto v_27646;
v_27647:
    goto v_27648;
v_27649:
    {
        LispObject v_27727 = stack[-1];
        fn = elt(env, 5); // plusdf
        return (*qfn2(fn))(fn, v_27727, v_27722);
    }
v_27633:
    goto v_27688;
v_27684:
    goto v_27694;
v_27690:
    goto v_27702;
v_27696:
    goto v_27708;
v_27704:
    v_27722 = stack[0];
    v_27722 = qcar(v_27722);
    v_27723 = qcar(v_27722);
    goto v_27705;
v_27706:
    v_27722 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27707;
v_27708:
    goto v_27704;
v_27705:
    goto v_27706;
v_27707:
    v_27724 = cons(v_27723, v_27722);
    env = stack[-2];
    goto v_27697;
v_27698:
    v_27723 = nil;
    goto v_27699;
v_27700:
    v_27722 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27701;
v_27702:
    goto v_27696;
v_27697:
    goto v_27698;
v_27699:
    goto v_27700;
v_27701:
    stack[-1] = acons(v_27724, v_27723, v_27722);
    env = stack[-2];
    goto v_27691;
v_27692:
    v_27722 = stack[0];
    v_27722 = qcar(v_27722);
    v_27722 = qcdr(v_27722);
    v_27722 = CC_f2df(elt(env, 0), v_27722);
    env = stack[-2];
    goto v_27693;
v_27694:
    goto v_27690;
v_27691:
    goto v_27692;
v_27693:
    fn = elt(env, 6); // multdfconst
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_27722);
    env = stack[-2];
    goto v_27685;
v_27686:
    v_27722 = stack[0];
    v_27722 = qcdr(v_27722);
    v_27722 = CC_f2df(elt(env, 0), v_27722);
    env = stack[-2];
    goto v_27687;
v_27688:
    goto v_27684;
v_27685:
    goto v_27686;
v_27687:
    {
        LispObject v_27728 = stack[-1];
        fn = elt(env, 5); // plusdf
        return (*qfn2(fn))(fn, v_27728, v_27722);
    }
    v_27722 = nil;
    return onevalue(v_27722);
}



setup_type const u47_setup[] =
{
    {"tchscheme2",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_tchscheme2},
    {"sroot1",                  TOO_FEW_2,      CC_sroot1,     WRONG_NO_2},
    {"endmodule",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_endmodule},
    {"mkprec",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mkprec},
    {"ordpl",                   TOO_FEW_2,      CC_ordpl,      WRONG_NO_2},
    {"setmatelem",              TOO_FEW_2,      CC_setmatelem, WRONG_NO_2},
    {"rfirst",                  CC_rfirst,      TOO_MANY_1,    WRONG_NO_1},
    {"mv2sf",                   TOO_FEW_2,      CC_mv2sf,      WRONG_NO_2},
    {"nodum_varp",              CC_nodum_varp,  TOO_MANY_1,    WRONG_NO_1},
    {"polynomlistautoreduce",   TOO_FEW_2,      CC_polynomlistautoreduce,WRONG_NO_2},
    {"talp_simplatlinv",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_simplatlinv},
    {"cnml",                    CC_cnml,        TOO_MANY_1,    WRONG_NO_1},
    {"newsym1",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_newsym1},
    {"xregister_spoly_pair",    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xregister_spoly_pair},
    {"evaluate2",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_evaluate2},
    {"mkforttab",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mkforttab},
    {"sign-abs",                CC_signKabs,    TOO_MANY_1,    WRONG_NO_1},
    {"mv-compact",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mvKcompact},
    {"simp-prop",               CC_simpKprop,   TOO_MANY_1,    WRONG_NO_1},
    {"ctx_get",                 TOO_FEW_2,      CC_ctx_get,    WRONG_NO_2},
    {"qqe_simplqneq",           TOO_FEW_2,      CC_qqe_simplqneq,WRONG_NO_2},
    {"pasf_ordatp",             TOO_FEW_2,      CC_pasf_ordatp,WRONG_NO_2},
    {"operator_fn",             CC_operator_fn, TOO_MANY_1,    WRONG_NO_1},
    {"mulpower",                TOO_FEW_2,      CC_mulpower,   WRONG_NO_2},
    {"lndepends",               TOO_FEW_2,      CC_lndepends,  WRONG_NO_2},
    {"split-comfac-part",       CC_splitKcomfacKpart,TOO_MANY_1,WRONG_NO_1},
    {"reduce-weights",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_reduceKweights},
    {"cali_bc_from_a",          CC_cali_bc_from_a,TOO_MANY_1,  WRONG_NO_1},
    {"vecsimp*",                CC_vecsimpH,    TOO_MANY_1,    WRONG_NO_1},
    {"mkrootsq",                TOO_FEW_2,      CC_mkrootsq,   WRONG_NO_2},
    {"check_letop",             CC_check_letop, TOO_MANY_1,    WRONG_NO_1},
    {"try-all-constants",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_tryKallKconstants},
    {"cl_identifyonoff",        CC_cl_identifyonoff,TOO_MANY_1,WRONG_NO_1},
    {"cl_rename-vars1",         TOO_FEW_2,      CC_cl_renameKvars1,WRONG_NO_2},
    {"cl_sacat",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_sacat},
    {"vdp_monp",                CC_vdp_monp,    TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_optfindeqsol",       TOO_FEW_2,      CC_ofsf_optfindeqsol,WRONG_NO_2},
    {"limitom",                 CC_limitom,     TOO_MANY_1,    WRONG_NO_1},
    {"i2ps",                    CC_i2ps,        TOO_MANY_1,    WRONG_NO_1},
    {"asymmetrize-inds",        TOO_FEW_2,      CC_asymmetrizeKinds,WRONG_NO_2},
    {"defined_all_edge",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_defined_all_edge},
    {"random-small-prime",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_randomKsmallKprime},
    {"polynomreduceby",         TOO_FEW_2,      CC_polynomreduceby,WRONG_NO_2},
    {"checkexp",                TOO_FEW_2,      CC_checkexp,   WRONG_NO_2},
    {"f2df",                    CC_f2df,        TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u47", (two_args *)"32587 5724483 1772074", 0}
};

// end of generated code
