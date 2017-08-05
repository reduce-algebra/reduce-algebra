
// $destdir/u26.c        Machine generated C code

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



// Code for cl_susiupdknowl1

static LispObject CC_cl_susiupdknowl1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_14572, v_14573, v_14574;
    LispObject fn;
    LispObject v_14520, v_14519, v_14518, v_14517;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_susiupdknowl1");
    va_start(aa, nargs);
    v_14517 = va_arg(aa, LispObject);
    v_14518 = va_arg(aa, LispObject);
    v_14519 = va_arg(aa, LispObject);
    v_14520 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_14520,v_14519,v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_14517,v_14518,v_14519,v_14520);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_14520;
    stack[-1] = v_14519;
    v_14574 = v_14518;
    v_14572 = v_14517;
// end of prologue
    goto v_14530;
v_14526:
    v_14573 = v_14572;
    goto v_14527;
v_14528:
    v_14572 = elt(env, 1); // and
    goto v_14529;
v_14530:
    goto v_14526;
v_14527:
    goto v_14528;
v_14529:
    if (v_14573 == v_14572) goto v_14524;
    else goto v_14525;
v_14524:
    goto v_14540;
v_14534:
    goto v_14546;
v_14542:
    v_14573 = v_14574;
    goto v_14543;
v_14544:
    v_14572 = stack[0];
    goto v_14545;
v_14546:
    goto v_14542;
v_14543:
    goto v_14544;
v_14545:
    v_14574 = cons(v_14573, v_14572);
    env = stack[-2];
    goto v_14535;
v_14536:
    v_14573 = stack[-1];
    goto v_14537;
v_14538:
    v_14572 = stack[0];
    goto v_14539;
v_14540:
    goto v_14534;
v_14535:
    goto v_14536;
v_14537:
    goto v_14538;
v_14539:
    {
        fn = elt(env, 2); // cl_susiupdknowl2
        return (*qfnn(fn))(fn, 3, v_14574, v_14573, v_14572);
    }
v_14525:
    goto v_14560;
v_14554:
    goto v_14566;
v_14562:
    v_14572 = v_14574;
    fn = elt(env, 3); // rl_negateat
    v_14573 = (*qfn1(fn))(fn, v_14572);
    env = stack[-2];
    goto v_14563;
v_14564:
    v_14572 = stack[0];
    goto v_14565;
v_14566:
    goto v_14562;
v_14563:
    goto v_14564;
v_14565:
    v_14574 = cons(v_14573, v_14572);
    env = stack[-2];
    goto v_14555;
v_14556:
    v_14573 = stack[-1];
    goto v_14557;
v_14558:
    v_14572 = stack[0];
    goto v_14559;
v_14560:
    goto v_14554;
v_14555:
    goto v_14556;
v_14557:
    goto v_14558;
v_14559:
    {
        fn = elt(env, 2); // cl_susiupdknowl2
        return (*qfnn(fn))(fn, 3, v_14574, v_14573, v_14572);
    }
    v_14572 = nil;
    return onevalue(v_14572);
}



// Code for vdp_setsugar

static LispObject CC_vdp_setsugar(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14539, v_14540, v_14541;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14539 = v_14518;
    v_14541 = v_14517;
// end of prologue
    v_14540 = qvalue(elt(env, 1)); // !*cgbsugar
    if (v_14540 == nil) goto v_14522;
    else goto v_14523;
v_14522:
    v_14539 = v_14541;
    goto v_14521;
v_14523:
    goto v_14535;
v_14529:
    goto v_14530;
v_14531:
    v_14540 = elt(env, 2); // sugar
    goto v_14532;
v_14533:
    goto v_14534;
v_14535:
    goto v_14529;
v_14530:
    goto v_14531;
v_14532:
    goto v_14533;
v_14534:
    {
        fn = elt(env, 3); // vdp_putprop
        return (*qfnn(fn))(fn, 3, v_14541, v_14540, v_14539);
    }
    v_14539 = nil;
v_14521:
    return onevalue(v_14539);
}



// Code for quotof

static LispObject CC_quotof(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14814, v_14815, v_14816;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_14518;
    stack[-3] = v_14517;
// end of prologue
    v_14814 = stack[-3];
    if (v_14814 == nil) goto v_14522;
    else goto v_14523;
v_14522:
    v_14814 = nil;
    goto v_14521;
v_14523:
    goto v_14532;
v_14528:
    v_14815 = stack[-3];
    goto v_14529;
v_14530:
    v_14814 = stack[-2];
    goto v_14531;
v_14532:
    goto v_14528;
v_14529:
    goto v_14530;
v_14531:
    if (equal(v_14815, v_14814)) goto v_14526;
    else goto v_14527;
v_14526:
    v_14814 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14521;
v_14527:
    goto v_14542;
v_14538:
    v_14815 = stack[-2];
    goto v_14539;
v_14540:
    v_14814 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14541;
v_14542:
    goto v_14538;
v_14539:
    goto v_14540;
v_14541:
    if (v_14815 == v_14814) goto v_14536;
    else goto v_14537;
v_14536:
    v_14814 = stack[-3];
    goto v_14521;
v_14537:
    v_14814 = stack[-2];
    if (!consp(v_14814)) goto v_14550;
    else goto v_14551;
v_14550:
    v_14814 = lisp_true;
    goto v_14549;
v_14551:
    v_14814 = stack[-2];
    v_14814 = qcar(v_14814);
    v_14814 = (consp(v_14814) ? nil : lisp_true);
    goto v_14549;
    v_14814 = nil;
v_14549:
    if (v_14814 == nil) goto v_14547;
    goto v_14564;
v_14560:
    v_14815 = stack[-3];
    goto v_14561;
v_14562:
    v_14814 = stack[-2];
    goto v_14563;
v_14564:
    goto v_14560;
v_14561:
    goto v_14562;
v_14563:
    {
        fn = elt(env, 3); // quotofd
        return (*qfn2(fn))(fn, v_14815, v_14814);
    }
v_14547:
    v_14814 = stack[-3];
    if (!consp(v_14814)) goto v_14571;
    else goto v_14572;
v_14571:
    v_14814 = lisp_true;
    goto v_14570;
v_14572:
    v_14814 = stack[-3];
    v_14814 = qcar(v_14814);
    v_14814 = (consp(v_14814) ? nil : lisp_true);
    goto v_14570;
    v_14814 = nil;
v_14570:
    if (v_14814 == nil) goto v_14568;
    v_14814 = stack[-2];
    v_14814 = qcar(v_14814);
    v_14814 = qcar(v_14814);
    v_14814 = qcdr(v_14814);
    goto v_14591;
v_14587:
    goto v_14597;
v_14593:
    v_14815 = stack[-2];
    v_14815 = qcar(v_14815);
    v_14815 = qcar(v_14815);
    stack[0] = qcar(v_14815);
    goto v_14594;
v_14595:
    v_14815 = v_14814;
    if (is_number(v_14815)) goto v_14604;
    else goto v_14605;
v_14604:
    v_14814 = negate(v_14814);
    env = stack[-5];
    goto v_14603;
v_14605:
    goto v_14616;
v_14612:
    v_14815 = elt(env, 1); // minus
    goto v_14613;
v_14614:
    goto v_14615;
v_14616:
    goto v_14612;
v_14613:
    goto v_14614;
v_14615:
    v_14814 = list2(v_14815, v_14814);
    env = stack[-5];
    goto v_14603;
    v_14814 = nil;
v_14603:
    goto v_14596;
v_14597:
    goto v_14593;
v_14594:
    goto v_14595;
v_14596:
    fn = elt(env, 4); // mksp
    stack[0] = (*qfn2(fn))(fn, stack[0], v_14814);
    env = stack[-5];
    goto v_14588;
v_14589:
    goto v_14624;
v_14620:
    stack[-1] = stack[-3];
    goto v_14621;
v_14622:
    goto v_14631;
v_14627:
    v_14815 = stack[-2];
    goto v_14628;
v_14629:
    v_14814 = elt(env, 2); // lcx
    goto v_14630;
v_14631:
    goto v_14627;
v_14628:
    goto v_14629;
v_14630:
    fn = elt(env, 5); // carx
    v_14814 = (*qfn2(fn))(fn, v_14815, v_14814);
    env = stack[-5];
    v_14814 = qcdr(v_14814);
    goto v_14623;
v_14624:
    goto v_14620;
v_14621:
    goto v_14622;
v_14623:
    v_14814 = CC_quotof(elt(env, 0), stack[-1], v_14814);
    env = stack[-5];
    goto v_14590;
v_14591:
    goto v_14587;
v_14588:
    goto v_14589;
v_14590:
    v_14814 = cons(stack[0], v_14814);
    return ncons(v_14814);
v_14568:
    v_14814 = stack[-3];
    v_14814 = qcar(v_14814);
    v_14815 = qcar(v_14814);
    v_14814 = stack[-2];
    v_14814 = qcar(v_14814);
    v_14814 = qcar(v_14814);
    stack[0] = v_14815;
    stack[-4] = v_14814;
    goto v_14653;
v_14649:
    v_14814 = stack[0];
    v_14815 = qcar(v_14814);
    goto v_14650;
v_14651:
    v_14814 = stack[-4];
    v_14814 = qcar(v_14814);
    goto v_14652;
v_14653:
    goto v_14649;
v_14650:
    goto v_14651;
v_14652:
    if (v_14815 == v_14814) goto v_14647;
    else goto v_14648;
v_14647:
    goto v_14663;
v_14659:
    v_14814 = stack[0];
    v_14815 = qcdr(v_14814);
    goto v_14660;
v_14661:
    v_14814 = stack[-4];
    v_14814 = qcdr(v_14814);
    goto v_14662;
v_14663:
    goto v_14659;
v_14660:
    goto v_14661;
v_14662:
    stack[-1] = difference2(v_14815, v_14814);
    env = stack[-5];
    goto v_14673;
v_14669:
    v_14814 = stack[-3];
    v_14814 = qcar(v_14814);
    stack[0] = qcdr(v_14814);
    goto v_14670;
v_14671:
    goto v_14682;
v_14678:
    v_14815 = stack[-2];
    goto v_14679;
v_14680:
    v_14814 = elt(env, 2); // lcx
    goto v_14681;
v_14682:
    goto v_14678;
v_14679:
    goto v_14680;
v_14681:
    fn = elt(env, 5); // carx
    v_14814 = (*qfn2(fn))(fn, v_14815, v_14814);
    env = stack[-5];
    v_14814 = qcdr(v_14814);
    goto v_14672;
v_14673:
    goto v_14669;
v_14670:
    goto v_14671;
v_14672:
    stack[0] = CC_quotof(elt(env, 0), stack[0], v_14814);
    env = stack[-5];
    goto v_14691;
v_14687:
    v_14814 = stack[-3];
    v_14815 = qcdr(v_14814);
    goto v_14688;
v_14689:
    v_14814 = stack[-2];
    goto v_14690;
v_14691:
    goto v_14687;
v_14688:
    goto v_14689;
v_14690:
    v_14814 = CC_quotof(elt(env, 0), v_14815, v_14814);
    env = stack[-5];
    v_14816 = stack[-1];
    stack[-1] = stack[0];
    stack[0] = v_14814;
    goto v_14706;
v_14702:
    v_14815 = v_14816;
    goto v_14703;
v_14704:
    v_14814 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14705;
v_14706:
    goto v_14702;
v_14703:
    goto v_14704;
v_14705:
    if (v_14815 == v_14814) goto v_14700;
    else goto v_14701;
v_14700:
    goto v_14714;
v_14710:
    v_14815 = stack[-1];
    goto v_14711;
v_14712:
    v_14814 = stack[0];
    goto v_14713;
v_14714:
    goto v_14710;
v_14711:
    goto v_14712;
v_14713:
    {
        fn = elt(env, 6); // raddf
        return (*qfn2(fn))(fn, v_14815, v_14814);
    }
v_14701:
    goto v_14726;
v_14720:
    goto v_14732;
v_14728:
    v_14814 = stack[-4];
    v_14814 = qcar(v_14814);
    goto v_14729;
v_14730:
    v_14815 = v_14816;
    goto v_14731;
v_14732:
    goto v_14728;
v_14729:
    goto v_14730;
v_14731:
    fn = elt(env, 7); // to
    v_14816 = (*qfn2(fn))(fn, v_14814, v_14815);
    goto v_14721;
v_14722:
    v_14815 = stack[-1];
    goto v_14723;
v_14724:
    v_14814 = stack[0];
    goto v_14725;
v_14726:
    goto v_14720;
v_14721:
    goto v_14722;
v_14723:
    goto v_14724;
v_14725:
    return acons(v_14816, v_14815, v_14814);
    v_14814 = nil;
    goto v_14646;
v_14648:
    goto v_14745;
v_14741:
    v_14814 = stack[0];
    v_14815 = qcar(v_14814);
    goto v_14742;
v_14743:
    v_14814 = stack[-4];
    v_14814 = qcar(v_14814);
    goto v_14744;
v_14745:
    goto v_14741;
v_14742:
    goto v_14743;
v_14744:
    fn = elt(env, 8); // ordop
    v_14814 = (*qfn2(fn))(fn, v_14815, v_14814);
    env = stack[-5];
    if (v_14814 == nil) goto v_14739;
    goto v_14757;
v_14751:
    stack[-1] = stack[0];
    goto v_14752;
v_14753:
    goto v_14764;
v_14760:
    v_14814 = stack[-3];
    v_14814 = qcar(v_14814);
    v_14815 = qcdr(v_14814);
    goto v_14761;
v_14762:
    v_14814 = stack[-2];
    goto v_14763;
v_14764:
    goto v_14760;
v_14761:
    goto v_14762;
v_14763:
    stack[0] = CC_quotof(elt(env, 0), v_14815, v_14814);
    env = stack[-5];
    goto v_14754;
v_14755:
    goto v_14774;
v_14770:
    v_14814 = stack[-3];
    v_14815 = qcdr(v_14814);
    goto v_14771;
v_14772:
    v_14814 = stack[-2];
    goto v_14773;
v_14774:
    goto v_14770;
v_14771:
    goto v_14772;
v_14773:
    v_14814 = CC_quotof(elt(env, 0), v_14815, v_14814);
    goto v_14756;
v_14757:
    goto v_14751;
v_14752:
    goto v_14753;
v_14754:
    goto v_14755;
v_14756:
    {
        LispObject v_14822 = stack[-1];
        LispObject v_14823 = stack[0];
        return acons(v_14822, v_14823, v_14814);
    }
v_14739:
    goto v_14786;
v_14782:
    goto v_14792;
v_14788:
    v_14814 = stack[-4];
    stack[0] = qcar(v_14814);
    goto v_14789;
v_14790:
    v_14814 = stack[-4];
    v_14814 = qcdr(v_14814);
    v_14814 = negate(v_14814);
    env = stack[-5];
    goto v_14791;
v_14792:
    goto v_14788;
v_14789:
    goto v_14790;
v_14791:
    fn = elt(env, 4); // mksp
    stack[0] = (*qfn2(fn))(fn, stack[0], v_14814);
    env = stack[-5];
    goto v_14783;
v_14784:
    goto v_14803;
v_14799:
    stack[-1] = stack[-3];
    goto v_14800;
v_14801:
    goto v_14810;
v_14806:
    v_14815 = stack[-2];
    goto v_14807;
v_14808:
    v_14814 = elt(env, 2); // lcx
    goto v_14809;
v_14810:
    goto v_14806;
v_14807:
    goto v_14808;
v_14809:
    fn = elt(env, 5); // carx
    v_14814 = (*qfn2(fn))(fn, v_14815, v_14814);
    env = stack[-5];
    v_14814 = qcdr(v_14814);
    goto v_14802;
v_14803:
    goto v_14799;
v_14800:
    goto v_14801;
v_14802:
    v_14814 = CC_quotof(elt(env, 0), stack[-1], v_14814);
    env = stack[-5];
    goto v_14785;
v_14786:
    goto v_14782;
v_14783:
    goto v_14784;
v_14785:
    v_14814 = cons(stack[0], v_14814);
    return ncons(v_14814);
    v_14814 = nil;
v_14646:
    goto v_14521;
    v_14814 = nil;
v_14521:
    return onevalue(v_14814);
}



// Code for ordop2

static LispObject CC_ordop2(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14562, v_14563, v_14564, v_14565, v_14566;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14565 = v_14518;
    v_14566 = v_14517;
// end of prologue
    v_14562 = qvalue(elt(env, 1)); // kord!*
    v_14564 = v_14562;
v_14523:
    v_14562 = v_14564;
    if (v_14562 == nil) goto v_14527;
    else goto v_14528;
v_14527:
    goto v_14535;
v_14531:
    v_14562 = v_14566;
    goto v_14532;
v_14533:
    v_14563 = v_14565;
    goto v_14534;
v_14535:
    goto v_14531;
v_14532:
    goto v_14533;
v_14534:
    {
        fn = elt(env, 2); // ordp
        return (*qfn2(fn))(fn, v_14562, v_14563);
    }
v_14528:
    goto v_14544;
v_14540:
    v_14563 = v_14566;
    goto v_14541;
v_14542:
    v_14562 = v_14564;
    v_14562 = qcar(v_14562);
    goto v_14543;
v_14544:
    goto v_14540;
v_14541:
    goto v_14542;
v_14543:
    if (v_14563 == v_14562) goto v_14538;
    else goto v_14539;
v_14538:
    v_14562 = lisp_true;
    goto v_14522;
v_14539:
    goto v_14555;
v_14551:
    v_14563 = v_14565;
    goto v_14552;
v_14553:
    v_14562 = v_14564;
    v_14562 = qcar(v_14562);
    goto v_14554;
v_14555:
    goto v_14551;
v_14552:
    goto v_14553;
v_14554:
    if (v_14563 == v_14562) goto v_14549;
    else goto v_14550;
v_14549:
    v_14562 = nil;
    goto v_14522;
v_14550:
    v_14562 = v_14564;
    v_14562 = qcdr(v_14562);
    v_14564 = v_14562;
    goto v_14523;
v_14522:
    return onevalue(v_14562);
}



// Code for factorial

static LispObject CC_factorial(LispObject env,
                         LispObject v_14517)
{
    env = qenv(env);
    LispObject v_14562, v_14563;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14517);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_14517;
// end of prologue
    v_14562 = stack[-1];
    v_14562 = integerp(v_14562);
    if (v_14562 == nil) goto v_14525;
    else goto v_14526;
v_14525:
    v_14562 = lisp_true;
    goto v_14524;
v_14526:
    goto v_14537;
v_14533:
    v_14563 = stack[-1];
    goto v_14534;
v_14535:
    v_14562 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14536;
v_14537:
    goto v_14533;
v_14534:
    goto v_14535;
v_14536:
    v_14562 = (LispObject)lessp2(v_14563, v_14562);
    v_14562 = v_14562 ? lisp_true : nil;
    env = stack[-3];
    goto v_14524;
    v_14562 = nil;
v_14524:
    if (v_14562 == nil) goto v_14522;
    goto v_14547;
v_14541:
    stack[-2] = elt(env, 1); // arith
    goto v_14542;
v_14543:
    stack[0] = (LispObject)64+TAG_FIXNUM; // 4
    goto v_14544;
v_14545:
    goto v_14555;
v_14551:
    v_14563 = stack[-1];
    goto v_14552;
v_14553:
    v_14562 = elt(env, 2); // "invalid factorial argument"
    goto v_14554;
v_14555:
    goto v_14551;
v_14552:
    goto v_14553;
v_14554:
    v_14562 = list2(v_14563, v_14562);
    env = stack[-3];
    goto v_14546;
v_14547:
    goto v_14541;
v_14542:
    goto v_14543;
v_14544:
    goto v_14545;
v_14546:
    {
        LispObject v_14567 = stack[-2];
        LispObject v_14568 = stack[0];
        fn = elt(env, 3); // rerror
        return (*qfnn(fn))(fn, 3, v_14567, v_14568, v_14562);
    }
v_14522:
    v_14562 = stack[-1];
    {
        fn = elt(env, 4); // nfactorial
        return (*qfn1(fn))(fn, v_14562);
    }
    v_14562 = nil;
    return onevalue(v_14562);
}



// Code for assert_install1

static LispObject CC_assert_install1(LispObject env,
                         LispObject v_14517)
{
    env = qenv(env);
    LispObject v_14603, v_14604, v_14605;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14517);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_14517;
// end of prologue
    goto v_14528;
v_14524:
    v_14604 = stack[0];
    goto v_14525;
v_14526:
    v_14603 = elt(env, 1); // assert_installed
    goto v_14527;
v_14528:
    goto v_14524;
v_14525:
    goto v_14526;
v_14527:
    v_14603 = get(v_14604, v_14603);
    env = stack[-1];
    if (v_14603 == nil) goto v_14522;
    goto v_14537;
v_14533:
    v_14604 = elt(env, 2); // "assert already installed for"
    goto v_14534;
v_14535:
    v_14603 = stack[0];
    goto v_14536;
v_14537:
    goto v_14533;
v_14534:
    goto v_14535;
v_14536:
    v_14603 = list2(v_14604, v_14603);
    env = stack[-1];
    {
        fn = elt(env, 7); // lprim
        return (*qfn1(fn))(fn, v_14603);
    }
v_14522:
    goto v_14547;
v_14543:
    v_14603 = stack[0];
    fn = elt(env, 8); // getd
    v_14604 = (*qfn1(fn))(fn, v_14603);
    env = stack[-1];
    goto v_14544;
v_14545:
    v_14603 = elt(env, 3); // expr
    goto v_14546;
v_14547:
    goto v_14543;
v_14544:
    goto v_14545;
v_14546:
    if (!consp(v_14604)) goto v_14540;
    v_14604 = qcar(v_14604);
    if (v_14604 == v_14603) goto v_14541;
v_14540:
    goto v_14557;
v_14553:
    v_14604 = stack[0];
    goto v_14554;
v_14555:
    v_14603 = elt(env, 4); // "is not an expr procedure - ignoring assert"
    goto v_14556;
v_14557:
    goto v_14553;
v_14554:
    goto v_14555;
v_14556:
    v_14603 = list2(v_14604, v_14603);
    env = stack[-1];
    {
        fn = elt(env, 7); // lprim
        return (*qfn1(fn))(fn, v_14603);
    }
v_14541:
    goto v_14567;
v_14563:
    goto v_14573;
v_14569:
    v_14604 = stack[0];
    goto v_14570;
v_14571:
    v_14603 = elt(env, 5); // assert_noassertfn
    goto v_14572;
v_14573:
    goto v_14569;
v_14570:
    goto v_14571;
v_14572:
    v_14604 = get(v_14604, v_14603);
    env = stack[-1];
    goto v_14564;
v_14565:
    v_14603 = stack[0];
    goto v_14566;
v_14567:
    goto v_14563;
v_14564:
    goto v_14565;
v_14566:
    fn = elt(env, 9); // copyd
    v_14603 = (*qfn2(fn))(fn, v_14604, v_14603);
    env = stack[-1];
    goto v_14582;
v_14578:
    v_14605 = stack[0];
    goto v_14579;
v_14580:
    goto v_14589;
v_14585:
    v_14604 = stack[0];
    goto v_14586;
v_14587:
    v_14603 = elt(env, 6); // assert_assertfn
    goto v_14588;
v_14589:
    goto v_14585;
v_14586:
    goto v_14587;
v_14588:
    v_14603 = get(v_14604, v_14603);
    env = stack[-1];
    goto v_14581;
v_14582:
    goto v_14578;
v_14579:
    goto v_14580;
v_14581:
    fn = elt(env, 9); // copyd
    v_14603 = (*qfn2(fn))(fn, v_14605, v_14603);
    env = stack[-1];
    goto v_14599;
v_14593:
    v_14604 = stack[0];
    goto v_14594;
v_14595:
    v_14605 = elt(env, 1); // assert_installed
    goto v_14596;
v_14597:
    v_14603 = lisp_true;
    goto v_14598;
v_14599:
    goto v_14593;
v_14594:
    goto v_14595;
v_14596:
    goto v_14597;
v_14598:
        return Lputprop(nil, 3, v_14604, v_14605, v_14603);
    v_14603 = nil;
    return onevalue(v_14603);
}



// Code for mo_zero

static LispObject CC_mo_zero(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_14527;
    LispObject fn;
    argcheck(nargs, 0, "mo_zero");
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
    goto v_14523;
v_14519:
    stack[0] = nil;
    goto v_14520;
v_14521:
    v_14527 = nil;
    fn = elt(env, 1); // mo!=deglist
    v_14527 = (*qfn1(fn))(fn, v_14527);
    goto v_14522;
v_14523:
    goto v_14519;
v_14520:
    goto v_14521;
v_14522:
    {
        LispObject v_14529 = stack[0];
        return cons(v_14529, v_14527);
    }
}



// Code for nonlnrsys

static LispObject CC_nonlnrsys(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14549, v_14550;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_14518;
    stack[-1] = v_14517;
// end of prologue
v_14516:
    v_14549 = stack[-1];
    if (v_14549 == nil) goto v_14522;
    else goto v_14523;
v_14522:
    v_14549 = nil;
    goto v_14521;
v_14523:
    goto v_14536;
v_14532:
    v_14549 = stack[-1];
    v_14550 = qcar(v_14549);
    goto v_14533;
v_14534:
    v_14549 = stack[0];
    goto v_14535;
v_14536:
    goto v_14532;
v_14533:
    goto v_14534;
v_14535:
    fn = elt(env, 1); // nonlnr
    v_14549 = (*qfn2(fn))(fn, v_14550, v_14549);
    env = stack[-2];
    if (v_14549 == nil) goto v_14530;
    else goto v_14529;
v_14530:
    goto v_14545;
v_14541:
    v_14549 = stack[-1];
    v_14550 = qcdr(v_14549);
    goto v_14542;
v_14543:
    v_14549 = stack[0];
    goto v_14544;
v_14545:
    goto v_14541;
v_14542:
    goto v_14543;
v_14544:
    stack[-1] = v_14550;
    stack[0] = v_14549;
    goto v_14516;
v_14529:
    goto v_14521;
    v_14549 = nil;
v_14521:
    return onevalue(v_14549);
}



// Code for dmconv0

static LispObject CC_dmconv0(LispObject env,
                         LispObject v_14517)
{
    env = qenv(env);
    LispObject v_14538, v_14539, v_14540;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14540 = v_14517;
// end of prologue
    v_14538 = v_14540;
    if (v_14538 == nil) goto v_14521;
    else goto v_14522;
v_14521:
    v_14538 = elt(env, 1); // !:rn!:
    goto v_14520;
v_14522:
    goto v_14531;
v_14527:
    v_14539 = v_14540;
    goto v_14528;
v_14529:
    v_14538 = elt(env, 2); // !:gi!:
    goto v_14530;
v_14531:
    goto v_14527;
v_14528:
    goto v_14529;
v_14530:
    if (v_14539 == v_14538) goto v_14525;
    else goto v_14526;
v_14525:
    v_14538 = elt(env, 3); // !:crn!:
    goto v_14520;
v_14526:
    v_14538 = v_14540;
    goto v_14520;
    v_14538 = nil;
v_14520:
    qvalue(elt(env, 4)) = v_14538; // dmd!*
    return onevalue(v_14538);
}



// Code for let3

static LispObject CC_let3(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_14729, v_14730, v_14731, v_14732, v_14733, v_14734;
    LispObject fn;
    LispObject v_14521, v_14520, v_14519, v_14518, v_14517;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "let3");
    va_start(aa, nargs);
    v_14517 = va_arg(aa, LispObject);
    v_14518 = va_arg(aa, LispObject);
    v_14519 = va_arg(aa, LispObject);
    v_14520 = va_arg(aa, LispObject);
    v_14521 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_14521,v_14520,v_14519,v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_14517,v_14518,v_14519,v_14520,v_14521);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-1] = v_14521;
    stack[-2] = v_14520;
    stack[-3] = v_14519;
    stack[-4] = v_14518;
    stack[-5] = v_14517;
// end of prologue
    v_14729 = stack[-5];
    stack[-6] = v_14729;
    v_14729 = stack[-6];
    if (v_14729 == nil) goto v_14532;
    else goto v_14533;
v_14532:
    v_14729 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_14729;
    v_14729 = stack[-5];
    {
        fn = elt(env, 5); // errpri1
        return (*qfn1(fn))(fn, v_14729);
    }
v_14533:
    v_14729 = stack[-6];
    if (is_number(v_14729)) goto v_14538;
    else goto v_14539;
v_14538:
    v_14729 = stack[-5];
    {
        fn = elt(env, 5); // errpri1
        return (*qfn1(fn))(fn, v_14729);
    }
v_14539:
    v_14729 = stack[-4];
    fn = elt(env, 6); // getrtype
    v_14729 = (*qfn1(fn))(fn, v_14729);
    env = stack[-7];
    stack[0] = v_14729;
    v_14729 = stack[-2];
    if (v_14729 == nil) goto v_14548;
    v_14729 = stack[-6];
    if (symbolp(v_14729)) goto v_14551;
    else goto v_14548;
v_14551:
    goto v_14558;
v_14554:
    v_14730 = stack[-6];
    goto v_14555;
v_14556:
    v_14729 = elt(env, 1); // rtype
    goto v_14557;
v_14558:
    goto v_14554;
v_14555:
    goto v_14556;
v_14557:
    v_14729 = Lremprop(nil, v_14730, v_14729);
    env = stack[-7];
    goto v_14566;
v_14562:
    v_14730 = stack[-6];
    goto v_14563;
v_14564:
    v_14729 = elt(env, 2); // avalue
    goto v_14565;
v_14566:
    goto v_14562;
v_14563:
    goto v_14564;
v_14565:
    v_14729 = Lremprop(nil, v_14730, v_14729);
    env = stack[-7];
    goto v_14546;
v_14548:
v_14546:
    v_14729 = stack[-6];
    fn = elt(env, 6); // getrtype
    v_14729 = (*qfn1(fn))(fn, v_14729);
    env = stack[-7];
    v_14731 = v_14729;
    if (v_14729 == nil) goto v_14572;
    goto v_14584;
v_14580:
    v_14730 = v_14731;
    goto v_14581;
v_14582:
    v_14729 = elt(env, 3); // typeletfn
    goto v_14583;
v_14584:
    goto v_14580;
v_14581:
    goto v_14582;
v_14583:
    v_14729 = get(v_14730, v_14729);
    env = stack[-7];
    v_14730 = v_14729;
    if (v_14729 == nil) goto v_14578;
    goto v_14592;
v_14588:
    stack[-3] = v_14730;
    goto v_14589;
v_14590:
    goto v_14603;
v_14595:
    stack[-5] = stack[-6];
    goto v_14596;
v_14597:
    stack[-1] = stack[-4];
    goto v_14598;
v_14599:
    stack[0] = v_14731;
    goto v_14600;
v_14601:
    goto v_14612;
v_14608:
    goto v_14609;
v_14610:
    v_14729 = stack[-4];
    fn = elt(env, 6); // getrtype
    v_14729 = (*qfn1(fn))(fn, v_14729);
    env = stack[-7];
    goto v_14611;
v_14612:
    goto v_14608;
v_14609:
    goto v_14610;
v_14611:
    v_14729 = list2(stack[-2], v_14729);
    env = stack[-7];
    goto v_14602;
v_14603:
    goto v_14595;
v_14596:
    goto v_14597;
v_14598:
    goto v_14599;
v_14600:
    goto v_14601;
v_14602:
    v_14729 = list3star(stack[-5], stack[-1], stack[0], v_14729);
    env = stack[-7];
    goto v_14591;
v_14592:
    goto v_14588;
v_14589:
    goto v_14590;
v_14591:
    {
        LispObject v_14742 = stack[-3];
        fn = elt(env, 7); // lispapply
        return (*qfn2(fn))(fn, v_14742, v_14729);
    }
v_14578:
    goto v_14629;
v_14619:
    stack[-3] = stack[-6];
    goto v_14620;
v_14621:
    stack[-1] = stack[-4];
    goto v_14622;
v_14623:
    stack[0] = v_14731;
    goto v_14624;
v_14625:
    goto v_14626;
v_14627:
    v_14729 = stack[-4];
    fn = elt(env, 6); // getrtype
    v_14729 = (*qfn1(fn))(fn, v_14729);
    env = stack[-7];
    goto v_14628;
v_14629:
    goto v_14619;
v_14620:
    goto v_14621;
v_14622:
    goto v_14623;
v_14624:
    goto v_14625;
v_14626:
    goto v_14627;
v_14628:
    {
        LispObject v_14743 = stack[-3];
        LispObject v_14744 = stack[-1];
        LispObject v_14745 = stack[0];
        LispObject v_14746 = stack[-2];
        fn = elt(env, 8); // typelet
        return (*qfnn(fn))(fn, 5, v_14743, v_14744, v_14745, v_14746, v_14729);
    }
    v_14729 = nil;
    goto v_14528;
v_14572:
    v_14729 = stack[0];
    if (v_14729 == nil) goto v_14637;
    goto v_14645;
v_14641:
    v_14730 = stack[0];
    goto v_14642;
v_14643:
    v_14729 = elt(env, 4); // yetunknowntype
    goto v_14644;
v_14645:
    goto v_14641;
v_14642:
    goto v_14643;
v_14644:
    if (v_14730 == v_14729) goto v_14637;
    goto v_14657;
v_14653:
    v_14730 = stack[0];
    goto v_14654;
v_14655:
    v_14729 = elt(env, 3); // typeletfn
    goto v_14656;
v_14657:
    goto v_14653;
v_14654:
    goto v_14655;
v_14656:
    v_14729 = get(v_14730, v_14729);
    env = stack[-7];
    v_14730 = v_14729;
    if (v_14729 == nil) goto v_14651;
    goto v_14665;
v_14661:
    stack[-3] = v_14730;
    goto v_14662;
v_14663:
    goto v_14676;
v_14668:
    stack[-5] = stack[-6];
    goto v_14669;
v_14670:
    goto v_14671;
v_14672:
    stack[-1] = nil;
    goto v_14673;
v_14674:
    goto v_14685;
v_14681:
    v_14730 = stack[-2];
    goto v_14682;
v_14683:
    v_14729 = stack[0];
    goto v_14684;
v_14685:
    goto v_14681;
v_14682:
    goto v_14683;
v_14684:
    v_14729 = list2(v_14730, v_14729);
    env = stack[-7];
    goto v_14675;
v_14676:
    goto v_14668;
v_14669:
    goto v_14670;
v_14671:
    goto v_14672;
v_14673:
    goto v_14674;
v_14675:
    v_14729 = list3star(stack[-5], stack[-4], stack[-1], v_14729);
    env = stack[-7];
    goto v_14664;
v_14665:
    goto v_14661;
v_14662:
    goto v_14663;
v_14664:
    {
        LispObject v_14747 = stack[-3];
        fn = elt(env, 7); // lispapply
        return (*qfn2(fn))(fn, v_14747, v_14729);
    }
v_14651:
    goto v_14701;
v_14691:
    v_14733 = stack[-6];
    goto v_14692;
v_14693:
    v_14732 = stack[-4];
    goto v_14694;
v_14695:
    v_14731 = nil;
    goto v_14696;
v_14697:
    v_14730 = stack[-2];
    goto v_14698;
v_14699:
    v_14729 = stack[0];
    goto v_14700;
v_14701:
    goto v_14691;
v_14692:
    goto v_14693;
v_14694:
    goto v_14695;
v_14696:
    goto v_14697;
v_14698:
    goto v_14699;
v_14700:
    {
        fn = elt(env, 8); // typelet
        return (*qfnn(fn))(fn, 5, v_14733, v_14732, v_14731, v_14730, v_14729);
    }
    v_14729 = nil;
    goto v_14528;
v_14637:
    goto v_14722;
v_14710:
    v_14734 = stack[-5];
    goto v_14711;
v_14712:
    v_14733 = stack[-4];
    goto v_14713;
v_14714:
    v_14732 = stack[-3];
    goto v_14715;
v_14716:
    v_14731 = stack[-6];
    goto v_14717;
v_14718:
    v_14730 = stack[-2];
    goto v_14719;
v_14720:
    v_14729 = stack[-1];
    goto v_14721;
v_14722:
    goto v_14710;
v_14711:
    goto v_14712;
v_14713:
    goto v_14714;
v_14715:
    goto v_14716;
v_14717:
    goto v_14718;
v_14719:
    goto v_14720;
v_14721:
    fn = elt(env, 9); // letscalar
    v_14729 = (*qfnn(fn))(fn, 6, v_14734, v_14733, v_14732, v_14731, v_14730, v_14729);
    goto v_14570;
v_14570:
    v_14729 = nil;
v_14528:
    return onevalue(v_14729);
}



// Code for ra_zerop

static LispObject CC_ra_zerop(LispObject env,
                         LispObject v_14517)
{
    env = qenv(env);
    LispObject v_14523;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14517);
    }
// copy arguments values to proper place
    v_14523 = v_14517;
// end of prologue
    fn = elt(env, 1); // ra_f
    v_14523 = (*qfn1(fn))(fn, v_14523);
    v_14523 = qcdr(v_14523);
    v_14523 = (v_14523 == nil ? lisp_true : nil);
    return onevalue(v_14523);
}



// Code for lalr_make_arglist

static LispObject CC_lalr_make_arglist(LispObject env,
                         LispObject v_14517)
{
    env = qenv(env);
    LispObject v_14589, v_14590;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14517);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_14517;
// end of prologue
    v_14589 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_14589;
    goto v_14536;
v_14532:
    v_14590 = stack[-4];
    goto v_14533;
v_14534:
    v_14589 = stack[-5];
    goto v_14535;
v_14536:
    goto v_14532;
v_14533:
    goto v_14534;
v_14535:
    v_14589 = difference2(v_14590, v_14589);
    env = stack[-6];
    v_14589 = Lminusp(nil, v_14589);
    env = stack[-6];
    if (v_14589 == nil) goto v_14529;
    v_14589 = nil;
    goto v_14523;
v_14529:
    goto v_14548;
v_14544:
    stack[0] = elt(env, 1); // !$
    goto v_14545;
v_14546:
    v_14589 = stack[-5];
    v_14589 = Lexplodec(nil, v_14589);
    env = stack[-6];
    goto v_14547;
v_14548:
    goto v_14544;
v_14545:
    goto v_14546;
v_14547:
    v_14589 = cons(stack[0], v_14589);
    env = stack[-6];
    fn = elt(env, 2); // list2string
    v_14589 = (*qfn1(fn))(fn, v_14589);
    env = stack[-6];
    v_14589 = Lintern(nil, v_14589);
    env = stack[-6];
    v_14589 = ncons(v_14589);
    env = stack[-6];
    stack[-2] = v_14589;
    stack[-3] = v_14589;
v_14524:
    v_14589 = stack[-5];
    v_14589 = add1(v_14589);
    env = stack[-6];
    stack[-5] = v_14589;
    goto v_14564;
v_14560:
    v_14590 = stack[-4];
    goto v_14561;
v_14562:
    v_14589 = stack[-5];
    goto v_14563;
v_14564:
    goto v_14560;
v_14561:
    goto v_14562;
v_14563:
    v_14589 = difference2(v_14590, v_14589);
    env = stack[-6];
    v_14589 = Lminusp(nil, v_14589);
    env = stack[-6];
    if (v_14589 == nil) goto v_14557;
    v_14589 = stack[-3];
    goto v_14523;
v_14557:
    goto v_14573;
v_14569:
    stack[-1] = stack[-2];
    goto v_14570;
v_14571:
    goto v_14583;
v_14579:
    stack[0] = elt(env, 1); // !$
    goto v_14580;
v_14581:
    v_14589 = stack[-5];
    v_14589 = Lexplodec(nil, v_14589);
    env = stack[-6];
    goto v_14582;
v_14583:
    goto v_14579;
v_14580:
    goto v_14581;
v_14582:
    v_14589 = cons(stack[0], v_14589);
    env = stack[-6];
    fn = elt(env, 2); // list2string
    v_14589 = (*qfn1(fn))(fn, v_14589);
    env = stack[-6];
    v_14589 = Lintern(nil, v_14589);
    env = stack[-6];
    v_14589 = ncons(v_14589);
    env = stack[-6];
    goto v_14572;
v_14573:
    goto v_14569;
v_14570:
    goto v_14571;
v_14572:
    v_14589 = Lrplacd(nil, stack[-1], v_14589);
    env = stack[-6];
    v_14589 = stack[-2];
    v_14589 = qcdr(v_14589);
    stack[-2] = v_14589;
    goto v_14524;
v_14523:
    return onevalue(v_14589);
}



// Code for rl_bettergaussp

static LispObject CC_rl_bettergaussp(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14535, v_14536;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_14535 = v_14518;
    v_14536 = v_14517;
// end of prologue
    goto v_14525;
v_14521:
    stack[0] = qvalue(elt(env, 1)); // rl_bettergaussp!*
    goto v_14522;
v_14523:
    goto v_14532;
v_14528:
    goto v_14529;
v_14530:
    goto v_14531;
v_14532:
    goto v_14528;
v_14529:
    goto v_14530;
v_14531:
    v_14535 = list2(v_14536, v_14535);
    env = stack[-1];
    goto v_14524;
v_14525:
    goto v_14521;
v_14522:
    goto v_14523;
v_14524:
    {
        LispObject v_14538 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_14538, v_14535);
    }
}



// Code for monomcomparedeglex

static LispObject CC_monomcomparedeglex(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14670, v_14671, v_14672, v_14673;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_14518;
    v_14673 = v_14517;
// end of prologue
    v_14670 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_14670;
    goto v_14535;
v_14531:
    goto v_14540;
v_14536:
    v_14671 = v_14673;
    goto v_14537;
v_14538:
    v_14670 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14539;
v_14540:
    goto v_14536;
v_14537:
    goto v_14538;
v_14539:
    v_14672 = *(LispObject *)((char *)v_14671 + (CELL-TAG_VECTOR) + (((intptr_t)v_14670-TAG_FIXNUM)/(16/CELL)));
    goto v_14532;
v_14533:
    goto v_14548;
v_14544:
    v_14671 = stack[-1];
    goto v_14545;
v_14546:
    v_14670 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14547;
v_14548:
    goto v_14544;
v_14545:
    goto v_14546;
v_14547:
    v_14670 = *(LispObject *)((char *)v_14671 + (CELL-TAG_VECTOR) + (((intptr_t)v_14670-TAG_FIXNUM)/(16/CELL)));
    goto v_14534;
v_14535:
    goto v_14531;
v_14532:
    goto v_14533;
v_14534:
    if (((intptr_t)(v_14672)) > ((intptr_t)(v_14670))) goto v_14529;
    else goto v_14530;
v_14529:
    v_14670 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_14670;
    goto v_14528;
v_14530:
    goto v_14559;
v_14555:
    goto v_14564;
v_14560:
    v_14671 = v_14673;
    goto v_14561;
v_14562:
    v_14670 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14563;
v_14564:
    goto v_14560;
v_14561:
    goto v_14562;
v_14563:
    v_14672 = *(LispObject *)((char *)v_14671 + (CELL-TAG_VECTOR) + (((intptr_t)v_14670-TAG_FIXNUM)/(16/CELL)));
    goto v_14556;
v_14557:
    goto v_14572;
v_14568:
    v_14671 = stack[-1];
    goto v_14569;
v_14570:
    v_14670 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14571;
v_14572:
    goto v_14568;
v_14569:
    goto v_14570;
v_14571:
    v_14670 = *(LispObject *)((char *)v_14671 + (CELL-TAG_VECTOR) + (((intptr_t)v_14670-TAG_FIXNUM)/(16/CELL)));
    goto v_14558;
v_14559:
    goto v_14555;
v_14556:
    goto v_14557;
v_14558:
    if (((intptr_t)(v_14672)) < ((intptr_t)(v_14670))) goto v_14553;
    else goto v_14554;
v_14553:
    v_14670 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[0] = v_14670;
    goto v_14528;
v_14554:
    goto v_14585;
v_14581:
    v_14671 = nil;
    goto v_14582;
v_14583:
    goto v_14591;
v_14587:
    v_14672 = v_14673;
    goto v_14588;
v_14589:
    v_14670 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14590;
v_14591:
    goto v_14587;
v_14588:
    goto v_14589;
v_14590:
    v_14670 = *(LispObject *)((char *)v_14672 + (CELL-TAG_VECTOR) + (((intptr_t)v_14670-TAG_FIXNUM)/(16/CELL)));
    goto v_14584;
v_14585:
    goto v_14581;
v_14582:
    goto v_14583;
v_14584:
    v_14670 = cons(v_14671, v_14670);
    env = stack[-3];
    v_14670 = Lreverse(nil, v_14670);
    env = stack[-3];
    v_14670 = qcdr(v_14670);
    stack[-2] = v_14670;
    goto v_14602;
v_14598:
    v_14672 = nil;
    goto v_14599;
v_14600:
    goto v_14608;
v_14604:
    v_14671 = stack[-1];
    goto v_14605;
v_14606:
    v_14670 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14607;
v_14608:
    goto v_14604;
v_14605:
    goto v_14606;
v_14607:
    v_14670 = *(LispObject *)((char *)v_14671 + (CELL-TAG_VECTOR) + (((intptr_t)v_14670-TAG_FIXNUM)/(16/CELL)));
    goto v_14601;
v_14602:
    goto v_14598;
v_14599:
    goto v_14600;
v_14601:
    v_14670 = cons(v_14672, v_14670);
    env = stack[-3];
    v_14670 = Lreverse(nil, v_14670);
    env = stack[-3];
    v_14670 = qcdr(v_14670);
    stack[-1] = v_14670;
v_14615:
    v_14670 = stack[-2];
    v_14670 = qcar(v_14670);
    if (v_14670 == nil) goto v_14618;
    v_14670 = stack[-1];
    v_14670 = qcar(v_14670);
    if (v_14670 == nil) goto v_14618;
    goto v_14619;
v_14618:
    goto v_14614;
v_14619:
    goto v_14636;
v_14632:
    v_14670 = stack[-2];
    v_14671 = qcar(v_14670);
    goto v_14633;
v_14634:
    v_14670 = stack[-1];
    v_14670 = qcar(v_14670);
    goto v_14635;
v_14636:
    goto v_14632;
v_14633:
    goto v_14634;
v_14635:
    v_14670 = (LispObject)lessp2(v_14671, v_14670);
    v_14670 = v_14670 ? lisp_true : nil;
    env = stack[-3];
    if (v_14670 == nil) goto v_14630;
    v_14670 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_14670;
    v_14670 = nil;
    v_14670 = ncons(v_14670);
    env = stack[-3];
    stack[-2] = v_14670;
    goto v_14628;
v_14630:
    goto v_14652;
v_14648:
    v_14670 = stack[-2];
    v_14671 = qcar(v_14670);
    goto v_14649;
v_14650:
    v_14670 = stack[-1];
    v_14670 = qcar(v_14670);
    goto v_14651;
v_14652:
    goto v_14648;
v_14649:
    goto v_14650;
v_14651:
    v_14670 = (LispObject)greaterp2(v_14671, v_14670);
    v_14670 = v_14670 ? lisp_true : nil;
    env = stack[-3];
    if (v_14670 == nil) goto v_14646;
    v_14670 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[0] = v_14670;
    v_14670 = nil;
    v_14670 = ncons(v_14670);
    env = stack[-3];
    stack[-2] = v_14670;
    goto v_14628;
v_14646:
    v_14670 = stack[-2];
    v_14670 = qcdr(v_14670);
    stack[-2] = v_14670;
    v_14670 = stack[-1];
    v_14670 = qcdr(v_14670);
    stack[-1] = v_14670;
    goto v_14628;
v_14628:
    goto v_14615;
v_14614:
    goto v_14528;
v_14528:
    v_14670 = stack[0];
    return onevalue(v_14670);
}



// Code for talp_list2vec

static LispObject CC_talp_list2vec(LispObject env,
                         LispObject v_14517)
{
    env = qenv(env);
    LispObject v_14562, v_14563, v_14564;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14517);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_14517;
// end of prologue
    v_14562 = stack[-1];
    v_14562 = Llength(nil, v_14562);
    env = stack[-3];
    v_14562 = sub1(v_14562);
    env = stack[-3];
    v_14562 = Lmkvect(nil, v_14562);
    env = stack[-3];
    stack[-2] = v_14562;
    v_14562 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_14562;
v_14529:
    goto v_14541;
v_14537:
    v_14562 = stack[-2];
    v_14563 = Lupbv(nil, v_14562);
    env = stack[-3];
    goto v_14538;
v_14539:
    v_14562 = stack[0];
    goto v_14540;
v_14541:
    goto v_14537;
v_14538:
    goto v_14539;
v_14540:
    v_14562 = difference2(v_14563, v_14562);
    env = stack[-3];
    v_14562 = Lminusp(nil, v_14562);
    env = stack[-3];
    if (v_14562 == nil) goto v_14534;
    goto v_14528;
v_14534:
    goto v_14552;
v_14546:
    v_14564 = stack[-2];
    goto v_14547;
v_14548:
    v_14563 = stack[0];
    goto v_14549;
v_14550:
    v_14562 = stack[-1];
    v_14562 = qcar(v_14562);
    goto v_14551;
v_14552:
    goto v_14546;
v_14547:
    goto v_14548;
v_14549:
    goto v_14550;
v_14551:
    *(LispObject *)((char *)v_14564 + (CELL-TAG_VECTOR) + (((intptr_t)v_14563-TAG_FIXNUM)/(16/CELL))) = v_14562;
    v_14562 = stack[-1];
    v_14562 = qcdr(v_14562);
    stack[-1] = v_14562;
    v_14562 = stack[0];
    v_14562 = add1(v_14562);
    env = stack[-3];
    stack[0] = v_14562;
    goto v_14529;
v_14528:
    v_14562 = stack[-2];
    return onevalue(v_14562);
}



// Code for cl_susiinter

static LispObject CC_cl_susiinter(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_14620, v_14621, v_14622, v_14623;
    LispObject fn;
    LispObject v_14519, v_14518, v_14517;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cl_susiinter");
    va_start(aa, nargs);
    v_14517 = va_arg(aa, LispObject);
    v_14518 = va_arg(aa, LispObject);
    v_14519 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_14519,v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_14517,v_14518,v_14519);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_14519;
    stack[-4] = v_14518;
    v_14620 = v_14517;
// end of prologue
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    stack[0] = v_14620;
v_14529:
    v_14620 = stack[0];
    if (v_14620 == nil) goto v_14533;
    else goto v_14534;
v_14533:
    goto v_14528;
v_14534:
    v_14620 = stack[0];
    v_14620 = qcar(v_14620);
    v_14622 = v_14620;
    goto v_14552;
v_14548:
    v_14620 = v_14622;
    v_14621 = qcar(v_14620);
    goto v_14549;
v_14550:
    v_14620 = elt(env, 1); // delete
    goto v_14551;
v_14552:
    goto v_14548;
v_14549:
    goto v_14550;
v_14551:
    if (v_14621 == v_14620) goto v_14546;
    else goto v_14547;
v_14546:
    v_14620 = lisp_true;
    goto v_14545;
v_14547:
    goto v_14563;
v_14559:
    v_14620 = v_14622;
    v_14621 = qcar(v_14620);
    goto v_14560;
v_14561:
    v_14620 = elt(env, 2); // ignore
    goto v_14562;
v_14563:
    goto v_14559;
v_14560:
    goto v_14561;
v_14562:
    v_14620 = (v_14621 == v_14620 ? lisp_true : nil);
    goto v_14545;
    v_14620 = nil;
v_14545:
    if (v_14620 == nil) goto v_14543;
    v_14620 = v_14622;
    v_14620 = qcdr(v_14620);
    if (v_14620 == nil) goto v_14571;
    v_14620 = lisp_true;
    stack[-1] = v_14620;
    goto v_14569;
v_14571:
    goto v_14582;
v_14578:
    v_14621 = stack[-3];
    goto v_14579;
v_14580:
    v_14620 = stack[-4];
    goto v_14581;
v_14582:
    goto v_14578;
v_14579:
    goto v_14580;
v_14581:
    fn = elt(env, 4); // lto_delqip
    v_14620 = (*qfn2(fn))(fn, v_14621, v_14620);
    env = stack[-6];
    stack[-4] = v_14620;
    goto v_14569;
v_14569:
    goto v_14541;
v_14543:
    goto v_14591;
v_14587:
    v_14620 = v_14622;
    v_14621 = qcar(v_14620);
    goto v_14588;
v_14589:
    v_14620 = elt(env, 3); // add
    goto v_14590;
v_14591:
    goto v_14587;
v_14588:
    goto v_14589;
v_14590:
    if (v_14621 == v_14620) goto v_14585;
    else goto v_14586;
v_14585:
    goto v_14600;
v_14596:
    v_14620 = v_14622;
    v_14621 = qcdr(v_14620);
    goto v_14597;
v_14598:
    v_14620 = stack[-5];
    goto v_14599;
v_14600:
    goto v_14596;
v_14597:
    goto v_14598;
v_14599:
    v_14620 = cons(v_14621, v_14620);
    env = stack[-6];
    stack[-5] = v_14620;
    goto v_14541;
v_14586:
v_14541:
    v_14620 = stack[0];
    v_14620 = qcdr(v_14620);
    stack[0] = v_14620;
    goto v_14529;
v_14528:
    goto v_14615;
v_14607:
    v_14623 = stack[-4];
    goto v_14608;
v_14609:
    v_14622 = stack[-5];
    goto v_14610;
v_14611:
    v_14621 = stack[-2];
    goto v_14612;
v_14613:
    v_14620 = stack[-1];
    goto v_14614;
v_14615:
    goto v_14607;
v_14608:
    goto v_14609;
v_14610:
    goto v_14611;
v_14612:
    goto v_14613;
v_14614:
    return list4(v_14623, v_14622, v_14621, v_14620);
    return onevalue(v_14620);
}



// Code for ofsf_sippsubst

static LispObject CC_ofsf_sippsubst(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14536, v_14537, v_14538;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14537 = v_14518;
    v_14538 = v_14517;
// end of prologue
    v_14536 = v_14537;
    if (v_14536 == nil) goto v_14523;
    goto v_14530;
v_14526:
    v_14536 = v_14538;
    goto v_14527;
v_14528:
    goto v_14529;
v_14530:
    goto v_14526;
v_14527:
    goto v_14528;
v_14529:
    {
        fn = elt(env, 1); // ofsf_sippsubst1
        return (*qfn2(fn))(fn, v_14536, v_14537);
    }
v_14523:
    v_14536 = v_14538;
    goto v_14521;
    v_14536 = nil;
v_14521:
    return onevalue(v_14536);
}



// Code for band_matrix

static LispObject CC_band_matrix(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14749, v_14750;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-8] = v_14518;
    stack[-9] = v_14517;
// end of prologue
    stack[-10] = nil;
    v_14749 = stack[-8];
    v_14749 = integerp(v_14749);
    if (v_14749 == nil) goto v_14533;
    else goto v_14534;
v_14533:
    v_14749 = elt(env, 1); // "Error in band_matrix(second argument): should be an integer."
    fn = elt(env, 7); // rederr
    v_14749 = (*qfn1(fn))(fn, v_14749);
    env = stack[-11];
    goto v_14532;
v_14534:
v_14532:
    v_14749 = stack[-9];
    if (!consp(v_14749)) goto v_14541;
    else goto v_14542;
v_14541:
    v_14749 = stack[-9];
    v_14749 = ncons(v_14749);
    env = stack[-11];
    stack[-9] = v_14749;
    goto v_14540;
v_14542:
    goto v_14552;
v_14548:
    v_14749 = stack[-9];
    v_14750 = qcar(v_14749);
    goto v_14549;
v_14550:
    v_14749 = elt(env, 2); // list
    goto v_14551;
v_14552:
    goto v_14548;
v_14549:
    goto v_14550;
v_14551:
    if (v_14750 == v_14749) goto v_14546;
    else goto v_14547;
v_14546:
    v_14749 = stack[-9];
    v_14749 = qcdr(v_14749);
    stack[-9] = v_14749;
    goto v_14540;
v_14547:
    v_14749 = elt(env, 3); // "Error in band_matrix(first argument): should be single value or list."
    fn = elt(env, 7); // rederr
    v_14749 = (*qfn1(fn))(fn, v_14749);
    env = stack[-11];
    goto v_14540;
v_14540:
    v_14749 = stack[-9];
    v_14749 = Llength(nil, v_14749);
    env = stack[-11];
    stack[-7] = v_14749;
    v_14749 = stack[-7];
    v_14749 = Levenp(nil, v_14749);
    env = stack[-11];
    if (v_14749 == nil) goto v_14567;
    v_14749 = elt(env, 4); // "Error in band matrix(first argument): number of elements must be odd."
    fn = elt(env, 7); // rederr
    v_14749 = (*qfn1(fn))(fn, v_14749);
    env = stack[-11];
    goto v_14565;
v_14567:
v_14565:
    goto v_14580;
v_14574:
    stack[0] = elt(env, 5); // quotient
    goto v_14575;
v_14576:
    v_14749 = stack[-7];
    v_14750 = add1(v_14749);
    env = stack[-11];
    goto v_14577;
v_14578:
    v_14749 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_14579;
v_14580:
    goto v_14574;
v_14575:
    goto v_14576;
v_14577:
    goto v_14578;
v_14579:
    v_14749 = list3(stack[0], v_14750, v_14749);
    env = stack[-11];
    fn = elt(env, 8); // reval
    v_14749 = (*qfn1(fn))(fn, v_14749);
    env = stack[-11];
    stack[-6] = v_14749;
    goto v_14594;
v_14590:
    v_14749 = stack[-6];
    v_14749 = integerp(v_14749);
    if (v_14749 == nil) goto v_14598;
    v_14749 = stack[-6];
    v_14750 = v_14749;
    goto v_14596;
v_14598:
    v_14749 = stack[-6];
    fn = elt(env, 8); // reval
    v_14749 = (*qfn1(fn))(fn, v_14749);
    env = stack[-11];
    v_14750 = v_14749;
    goto v_14596;
    v_14750 = nil;
v_14596:
    goto v_14591;
v_14592:
    v_14749 = stack[-8];
    goto v_14593;
v_14594:
    goto v_14590;
v_14591:
    goto v_14592;
v_14593:
    v_14749 = (LispObject)greaterp2(v_14750, v_14749);
    v_14749 = v_14749 ? lisp_true : nil;
    env = stack[-11];
    if (v_14749 == nil) goto v_14588;
    v_14749 = elt(env, 6); // "Error in band_matrix: too many elements. Band matrix is overflowing."
    fn = elt(env, 7); // rederr
    v_14749 = (*qfn1(fn))(fn, v_14749);
    env = stack[-11];
    goto v_14586;
v_14588:
    goto v_14616;
v_14612:
    v_14750 = stack[-8];
    goto v_14613;
v_14614:
    v_14749 = stack[-8];
    goto v_14615;
v_14616:
    goto v_14612;
v_14613:
    goto v_14614;
v_14615:
    fn = elt(env, 9); // mkmatrix
    v_14749 = (*qfn2(fn))(fn, v_14750, v_14749);
    env = stack[-11];
    stack[-10] = v_14749;
    goto v_14586;
v_14586:
    v_14749 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_14749;
v_14622:
    goto v_14634;
v_14630:
    v_14750 = stack[-8];
    goto v_14631;
v_14632:
    v_14749 = stack[-5];
    goto v_14633;
v_14634:
    goto v_14630;
v_14631:
    goto v_14632;
v_14633:
    v_14749 = difference2(v_14750, v_14749);
    env = stack[-11];
    v_14749 = Lminusp(nil, v_14749);
    env = stack[-11];
    if (v_14749 == nil) goto v_14627;
    goto v_14621;
v_14627:
    v_14749 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_14749;
v_14641:
    goto v_14653;
v_14649:
    v_14750 = stack[-8];
    goto v_14650;
v_14651:
    v_14749 = stack[-4];
    goto v_14652;
v_14653:
    goto v_14649;
v_14650:
    goto v_14651;
v_14652:
    v_14749 = difference2(v_14750, v_14749);
    env = stack[-11];
    v_14749 = Lminusp(nil, v_14749);
    env = stack[-11];
    if (v_14749 == nil) goto v_14646;
    goto v_14640;
v_14646:
    goto v_14667;
v_14663:
    goto v_14673;
v_14669:
    goto v_14679;
v_14675:
    v_14750 = stack[-6];
    goto v_14676;
v_14677:
    v_14749 = stack[-5];
    goto v_14678;
v_14679:
    goto v_14675;
v_14676:
    goto v_14677;
v_14678:
    v_14750 = difference2(v_14750, v_14749);
    env = stack[-11];
    goto v_14670;
v_14671:
    v_14749 = stack[-4];
    goto v_14672;
v_14673:
    goto v_14669;
v_14670:
    goto v_14671;
v_14672:
    v_14750 = plus2(v_14750, v_14749);
    env = stack[-11];
    goto v_14664;
v_14665:
    v_14749 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14666;
v_14667:
    goto v_14663;
v_14664:
    goto v_14665;
v_14666:
    v_14749 = (LispObject)greaterp2(v_14750, v_14749);
    v_14749 = v_14749 ? lisp_true : nil;
    env = stack[-11];
    if (v_14749 == nil) goto v_14660;
    goto v_14690;
v_14686:
    goto v_14696;
v_14692:
    goto v_14702;
v_14698:
    v_14750 = stack[-6];
    goto v_14699;
v_14700:
    v_14749 = stack[-5];
    goto v_14701;
v_14702:
    goto v_14698;
v_14699:
    goto v_14700;
v_14701:
    v_14750 = difference2(v_14750, v_14749);
    env = stack[-11];
    goto v_14693;
v_14694:
    v_14749 = stack[-4];
    goto v_14695;
v_14696:
    goto v_14692;
v_14693:
    goto v_14694;
v_14695:
    v_14750 = plus2(v_14750, v_14749);
    env = stack[-11];
    goto v_14687;
v_14688:
    v_14749 = stack[-7];
    goto v_14689;
v_14690:
    goto v_14686;
v_14687:
    goto v_14688;
v_14689:
    v_14749 = (LispObject)lesseq2(v_14750, v_14749);
    v_14749 = v_14749 ? lisp_true : nil;
    env = stack[-11];
    if (v_14749 == nil) goto v_14660;
    goto v_14716;
v_14708:
    stack[-3] = stack[-10];
    goto v_14709;
v_14710:
    stack[-2] = stack[-5];
    goto v_14711;
v_14712:
    stack[-1] = stack[-4];
    goto v_14713;
v_14714:
    goto v_14725;
v_14721:
    stack[0] = stack[-9];
    goto v_14722;
v_14723:
    goto v_14732;
v_14728:
    goto v_14738;
v_14734:
    v_14750 = stack[-6];
    goto v_14735;
v_14736:
    v_14749 = stack[-5];
    goto v_14737;
v_14738:
    goto v_14734;
v_14735:
    goto v_14736;
v_14737:
    v_14750 = difference2(v_14750, v_14749);
    env = stack[-11];
    goto v_14729;
v_14730:
    v_14749 = stack[-4];
    goto v_14731;
v_14732:
    goto v_14728;
v_14729:
    goto v_14730;
v_14731:
    v_14749 = plus2(v_14750, v_14749);
    env = stack[-11];
    goto v_14724;
v_14725:
    goto v_14721;
v_14722:
    goto v_14723;
v_14724:
    fn = elt(env, 10); // nth
    v_14749 = (*qfn2(fn))(fn, stack[0], v_14749);
    env = stack[-11];
    goto v_14715;
v_14716:
    goto v_14708;
v_14709:
    goto v_14710;
v_14711:
    goto v_14712;
v_14713:
    goto v_14714;
v_14715:
    fn = elt(env, 11); // setmat
    v_14749 = (*qfnn(fn))(fn, 4, stack[-3], stack[-2], stack[-1], v_14749);
    env = stack[-11];
    goto v_14658;
v_14660:
v_14658:
    v_14749 = stack[-4];
    v_14749 = add1(v_14749);
    env = stack[-11];
    stack[-4] = v_14749;
    goto v_14641;
v_14640:
    v_14749 = stack[-5];
    v_14749 = add1(v_14749);
    env = stack[-11];
    stack[-5] = v_14749;
    goto v_14622;
v_14621:
    v_14749 = stack[-10];
    return onevalue(v_14749);
}



// Code for vdpvevlcomp

static LispObject CC_vdpvevlcomp(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14536, v_14537;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14536 = v_14518;
    v_14537 = v_14517;
// end of prologue
    goto v_14525;
v_14521:
    v_14537 = qcdr(v_14537);
    v_14537 = qcdr(v_14537);
    v_14537 = qcdr(v_14537);
    v_14537 = qcar(v_14537);
    goto v_14522;
v_14523:
    v_14536 = qcdr(v_14536);
    v_14536 = qcdr(v_14536);
    v_14536 = qcdr(v_14536);
    v_14536 = qcar(v_14536);
    goto v_14524;
v_14525:
    goto v_14521;
v_14522:
    goto v_14523;
v_14524:
    {
        fn = elt(env, 1); // dipevlcomp
        return (*qfn2(fn))(fn, v_14537, v_14536);
    }
}



// Code for gftimesn

static LispObject CC_gftimesn(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14600, v_14601, v_14602;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_14601 = v_14518;
    v_14602 = v_14517;
// end of prologue
    v_14600 = v_14602;
    v_14600 = qcar(v_14600);
    if (!consp(v_14600)) goto v_14522;
    else goto v_14523;
v_14522:
    goto v_14531;
v_14527:
    v_14600 = v_14602;
    goto v_14528;
v_14529:
    goto v_14530;
v_14531:
    goto v_14527;
v_14528:
    goto v_14529;
v_14530:
    {
        fn = elt(env, 1); // gfftimes
        return (*qfn2(fn))(fn, v_14600, v_14601);
    }
v_14523:
    v_14600 = v_14602;
    v_14600 = qcar(v_14600);
    stack[-4] = v_14600;
    v_14600 = v_14602;
    v_14600 = qcdr(v_14600);
    stack[-3] = v_14600;
    v_14600 = v_14601;
    v_14600 = qcar(v_14600);
    stack[-2] = v_14600;
    v_14600 = v_14601;
    v_14600 = qcdr(v_14600);
    stack[-1] = v_14600;
    goto v_14555;
v_14551:
    goto v_14561;
v_14557:
    goto v_14567;
v_14563:
    v_14601 = stack[-4];
    goto v_14564;
v_14565:
    v_14600 = stack[-2];
    goto v_14566;
v_14567:
    goto v_14563;
v_14564:
    goto v_14565;
v_14566:
    fn = elt(env, 2); // times!:
    stack[0] = (*qfn2(fn))(fn, v_14601, v_14600);
    env = stack[-5];
    goto v_14558;
v_14559:
    goto v_14575;
v_14571:
    v_14601 = stack[-3];
    goto v_14572;
v_14573:
    v_14600 = stack[-1];
    goto v_14574;
v_14575:
    goto v_14571;
v_14572:
    goto v_14573;
v_14574:
    fn = elt(env, 2); // times!:
    v_14600 = (*qfn2(fn))(fn, v_14601, v_14600);
    env = stack[-5];
    goto v_14560;
v_14561:
    goto v_14557;
v_14558:
    goto v_14559;
v_14560:
    fn = elt(env, 3); // difference!:
    stack[0] = (*qfn2(fn))(fn, stack[0], v_14600);
    env = stack[-5];
    goto v_14552;
v_14553:
    goto v_14583;
v_14579:
    goto v_14589;
v_14585:
    v_14601 = stack[-4];
    goto v_14586;
v_14587:
    v_14600 = stack[-1];
    goto v_14588;
v_14589:
    goto v_14585;
v_14586:
    goto v_14587;
v_14588:
    fn = elt(env, 2); // times!:
    stack[-1] = (*qfn2(fn))(fn, v_14601, v_14600);
    env = stack[-5];
    goto v_14580;
v_14581:
    goto v_14597;
v_14593:
    v_14601 = stack[-3];
    goto v_14594;
v_14595:
    v_14600 = stack[-2];
    goto v_14596;
v_14597:
    goto v_14593;
v_14594:
    goto v_14595;
v_14596:
    fn = elt(env, 2); // times!:
    v_14600 = (*qfn2(fn))(fn, v_14601, v_14600);
    env = stack[-5];
    goto v_14582;
v_14583:
    goto v_14579;
v_14580:
    goto v_14581;
v_14582:
    fn = elt(env, 4); // plus!:
    v_14600 = (*qfn2(fn))(fn, stack[-1], v_14600);
    goto v_14554;
v_14555:
    goto v_14551;
v_14552:
    goto v_14553;
v_14554:
    {
        LispObject v_14608 = stack[0];
        return cons(v_14608, v_14600);
    }
    goto v_14521;
    v_14600 = nil;
v_14521:
    return onevalue(v_14600);
}



// Code for rd!:plus

static LispObject CC_rdTplus(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14708, v_14709, v_14710;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_14518;
    stack[-2] = v_14517;
// end of prologue
    v_14708 = nil;
    stack[-3] = v_14708;
    v_14708 = qvalue(elt(env, 1)); // !*!*roundbf
    if (v_14708 == nil) goto v_14528;
    else goto v_14529;
v_14528:
    v_14708 = stack[-2];
    v_14708 = qcdr(v_14708);
    if (!consp(v_14708)) goto v_14533;
    else goto v_14534;
v_14533:
    v_14708 = stack[0];
    v_14708 = qcdr(v_14708);
    if (!consp(v_14708)) goto v_14539;
    else goto v_14540;
v_14539:
    goto v_14548;
v_14544:
    v_14708 = stack[-2];
    v_14709 = qcdr(v_14708);
    goto v_14545;
v_14546:
    v_14708 = stack[0];
    v_14708 = qcdr(v_14708);
    goto v_14547;
v_14548:
    goto v_14544;
v_14545:
    goto v_14546;
v_14547:
    fn = elt(env, 4); // safe!-fp!-plus
    v_14708 = (*qfn2(fn))(fn, v_14709, v_14708);
    env = stack[-4];
    stack[-3] = v_14708;
    goto v_14538;
v_14540:
    v_14708 = nil;
    goto v_14538;
    v_14708 = nil;
v_14538:
    goto v_14532;
v_14534:
    v_14708 = nil;
    goto v_14532;
    v_14708 = nil;
v_14532:
    goto v_14527;
v_14529:
    v_14708 = nil;
    goto v_14527;
    v_14708 = nil;
v_14527:
    if (v_14708 == nil) goto v_14525;
    goto v_14567;
v_14563:
    v_14709 = elt(env, 2); // !:rd!:
    goto v_14564;
v_14565:
    v_14708 = stack[-3];
    goto v_14566;
v_14567:
    goto v_14563;
v_14564:
    goto v_14565;
v_14566:
    return cons(v_14709, v_14708);
v_14525:
    goto v_14581;
v_14577:
    v_14709 = stack[-2];
    goto v_14578;
v_14579:
    v_14708 = stack[0];
    goto v_14580;
v_14581:
    goto v_14577;
v_14578:
    goto v_14579;
v_14580:
    fn = elt(env, 5); // convprc2
    v_14708 = (*qfn2(fn))(fn, v_14709, v_14708);
    env = stack[-4];
    stack[-1] = v_14708;
    v_14708 = qvalue(elt(env, 3)); // yy!!
    stack[0] = v_14708;
    v_14708 = stack[-1];
    if (!consp(v_14708)) goto v_14588;
    goto v_14595;
v_14591:
    v_14709 = stack[-1];
    goto v_14592;
v_14593:
    v_14708 = stack[0];
    goto v_14594;
v_14595:
    goto v_14591;
v_14592:
    goto v_14593;
v_14594:
    fn = elt(env, 6); // plubf
    v_14708 = (*qfn2(fn))(fn, v_14709, v_14708);
    env = stack[-4];
    goto v_14586;
v_14588:
    goto v_14605;
v_14601:
    v_14709 = stack[-1];
    goto v_14602;
v_14603:
    v_14708 = stack[0];
    goto v_14604;
v_14605:
    goto v_14601;
v_14602:
    goto v_14603;
v_14604:
    v_14708 = plus2(v_14709, v_14708);
    env = stack[-4];
    stack[-3] = v_14708;
    v_14708 = stack[-3];
    fn = elt(env, 7); // fp!-infinite
    v_14708 = (*qfn1(fn))(fn, v_14708);
    env = stack[-4];
    if (v_14708 == nil) goto v_14611;
    fn = elt(env, 8); // rndbfon
    v_14708 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_14620;
v_14616:
    v_14708 = stack[-1];
    v_14708 = Lfloatp(nil, v_14708);
    env = stack[-4];
    if (v_14708 == nil) goto v_14624;
    v_14708 = stack[-1];
    fn = elt(env, 9); // fl2bf
    v_14708 = (*qfn1(fn))(fn, v_14708);
    env = stack[-4];
    stack[-2] = v_14708;
    goto v_14622;
v_14624:
    v_14708 = stack[-1];
    if (!consp(v_14708)) goto v_14635;
    v_14708 = stack[-1];
    goto v_14633;
v_14635:
    v_14708 = stack[-1];
    v_14708 = integerp(v_14708);
    if (v_14708 == nil) goto v_14639;
    goto v_14649;
v_14643:
    v_14710 = elt(env, 2); // !:rd!:
    goto v_14644;
v_14645:
    v_14709 = stack[-1];
    goto v_14646;
v_14647:
    v_14708 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14648;
v_14649:
    goto v_14643;
v_14644:
    goto v_14645;
v_14646:
    goto v_14647;
v_14648:
    v_14708 = list2star(v_14710, v_14709, v_14708);
    env = stack[-4];
    goto v_14633;
v_14639:
    v_14708 = stack[-1];
    fn = elt(env, 10); // read!:num
    v_14708 = (*qfn1(fn))(fn, v_14708);
    env = stack[-4];
    goto v_14633;
    v_14708 = nil;
v_14633:
    fn = elt(env, 11); // normbf
    v_14708 = (*qfn1(fn))(fn, v_14708);
    env = stack[-4];
    stack[-2] = v_14708;
    goto v_14622;
    stack[-2] = nil;
v_14622:
    stack[-1] = stack[-2];
    goto v_14617;
v_14618:
    v_14708 = stack[0];
    v_14708 = Lfloatp(nil, v_14708);
    env = stack[-4];
    if (v_14708 == nil) goto v_14660;
    v_14708 = stack[0];
    fn = elt(env, 9); // fl2bf
    v_14708 = (*qfn1(fn))(fn, v_14708);
    env = stack[-4];
    goto v_14658;
v_14660:
    v_14708 = stack[0];
    if (!consp(v_14708)) goto v_14671;
    v_14708 = stack[0];
    goto v_14669;
v_14671:
    v_14708 = stack[0];
    v_14708 = integerp(v_14708);
    if (v_14708 == nil) goto v_14675;
    goto v_14685;
v_14679:
    v_14710 = elt(env, 2); // !:rd!:
    goto v_14680;
v_14681:
    v_14709 = stack[0];
    goto v_14682;
v_14683:
    v_14708 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14684;
v_14685:
    goto v_14679;
v_14680:
    goto v_14681;
v_14682:
    goto v_14683;
v_14684:
    v_14708 = list2star(v_14710, v_14709, v_14708);
    env = stack[-4];
    goto v_14669;
v_14675:
    v_14708 = stack[0];
    fn = elt(env, 10); // read!:num
    v_14708 = (*qfn1(fn))(fn, v_14708);
    env = stack[-4];
    goto v_14669;
    v_14708 = nil;
v_14669:
    fn = elt(env, 11); // normbf
    v_14708 = (*qfn1(fn))(fn, v_14708);
    env = stack[-4];
    goto v_14658;
    v_14708 = nil;
v_14658:
    stack[0] = v_14708;
    goto v_14619;
v_14620:
    goto v_14616;
v_14617:
    goto v_14618;
v_14619:
    fn = elt(env, 6); // plubf
    v_14708 = (*qfn2(fn))(fn, stack[-2], v_14708);
    env = stack[-4];
    goto v_14609;
v_14611:
    v_14708 = stack[-3];
    goto v_14609;
    v_14708 = nil;
v_14609:
    goto v_14586;
    v_14708 = nil;
v_14586:
    stack[-2] = v_14708;
    goto v_14704;
v_14698:
    v_14710 = stack[-2];
    goto v_14699;
v_14700:
    v_14709 = stack[-1];
    goto v_14701;
v_14702:
    v_14708 = stack[0];
    goto v_14703;
v_14704:
    goto v_14698;
v_14699:
    goto v_14700;
v_14701:
    goto v_14702;
v_14703:
    fn = elt(env, 12); // rdzchk
    v_14708 = (*qfnn(fn))(fn, 3, v_14710, v_14709, v_14708);
    env = stack[-4];
    {
        fn = elt(env, 13); // mkround
        return (*qfn1(fn))(fn, v_14708);
    }
    goto v_14523;
    v_14708 = nil;
v_14523:
    return onevalue(v_14708);
}



// Code for getphystypecar

static LispObject CC_getphystypecar(LispObject env,
                         LispObject v_14517)
{
    env = qenv(env);
    LispObject v_14530, v_14531;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14531 = v_14517;
// end of prologue
    v_14530 = v_14531;
    if (!consp(v_14530)) goto v_14522;
    v_14530 = v_14531;
    v_14530 = qcar(v_14530);
    {
        fn = elt(env, 1); // getphystype
        return (*qfn1(fn))(fn, v_14530);
    }
v_14522:
    v_14530 = nil;
    goto v_14520;
    v_14530 = nil;
v_14520:
    return onevalue(v_14530);
}



// Code for groeb!=newpair

static LispObject CC_groebMnewpair(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_14565, v_14566, v_14567;
    LispObject fn;
    LispObject v_14519, v_14518, v_14517;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "groeb=newpair");
    va_start(aa, nargs);
    v_14517 = va_arg(aa, LispObject);
    v_14518 = va_arg(aa, LispObject);
    v_14519 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_14519,v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_14517,v_14518,v_14519);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_14519;
    stack[-3] = v_14518;
    stack[-1] = v_14517;
// end of prologue
    goto v_14526;
v_14522:
    v_14565 = stack[-3];
    fn = elt(env, 1); // bas_dpoly
    v_14565 = (*qfn1(fn))(fn, v_14565);
    env = stack[-5];
    fn = elt(env, 2); // dp_lmon
    stack[0] = (*qfn1(fn))(fn, v_14565);
    env = stack[-5];
    goto v_14523;
v_14524:
    v_14565 = stack[-2];
    fn = elt(env, 1); // bas_dpoly
    v_14565 = (*qfn1(fn))(fn, v_14565);
    env = stack[-5];
    fn = elt(env, 2); // dp_lmon
    v_14565 = (*qfn1(fn))(fn, v_14565);
    env = stack[-5];
    goto v_14525;
v_14526:
    goto v_14522;
v_14523:
    goto v_14524;
v_14525:
    fn = elt(env, 3); // mo_lcm
    v_14565 = (*qfn2(fn))(fn, stack[0], v_14565);
    env = stack[-5];
    stack[0] = v_14565;
    goto v_14543;
v_14535:
    stack[-4] = stack[-1];
    goto v_14536;
v_14537:
    goto v_14552;
v_14546:
    v_14567 = stack[0];
    goto v_14547;
v_14548:
    v_14566 = stack[-3];
    goto v_14549;
v_14550:
    v_14565 = stack[-2];
    goto v_14551;
v_14552:
    goto v_14546;
v_14547:
    goto v_14548;
v_14549:
    goto v_14550;
v_14551:
    fn = elt(env, 4); // groeb!=weight
    stack[-1] = (*qfnn(fn))(fn, 3, v_14567, v_14566, v_14565);
    env = stack[-5];
    goto v_14538;
v_14539:
    goto v_14540;
v_14541:
    goto v_14562;
v_14558:
    v_14566 = stack[-3];
    goto v_14559;
v_14560:
    v_14565 = stack[-2];
    goto v_14561;
v_14562:
    goto v_14558;
v_14559:
    goto v_14560;
v_14561:
    v_14565 = list2(v_14566, v_14565);
    goto v_14542;
v_14543:
    goto v_14535;
v_14536:
    goto v_14537;
v_14538:
    goto v_14539;
v_14540:
    goto v_14541;
v_14542:
    {
        LispObject v_14573 = stack[-4];
        LispObject v_14574 = stack[-1];
        LispObject v_14575 = stack[0];
        return list3star(v_14573, v_14574, v_14575, v_14565);
    }
}



// Code for subs3t

static LispObject CC_subs3t(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14978, v_14979, v_14980, v_14981;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_14979 = v_14518;
    stack[-4] = v_14517;
// end of prologue
    stack[-5] = nil;
    goto v_14538;
v_14534:
    v_14978 = stack[-4];
    stack[0] = qcar(v_14978);
    goto v_14535;
v_14536:
    v_14978 = stack[-4];
    v_14978 = qcdr(v_14978);
    if (!consp(v_14978)) goto v_14547;
    else goto v_14548;
v_14547:
    v_14978 = lisp_true;
    goto v_14546;
v_14548:
    v_14978 = stack[-4];
    v_14978 = qcdr(v_14978);
    v_14978 = qcar(v_14978);
    v_14978 = (consp(v_14978) ? nil : lisp_true);
    goto v_14546;
    v_14978 = nil;
v_14546:
    if (v_14978 == nil) goto v_14544;
    goto v_14563;
v_14559:
    goto v_14560;
v_14561:
    v_14978 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14562;
v_14563:
    goto v_14559;
v_14560:
    goto v_14561;
v_14562:
    fn = elt(env, 5); // sizchk
    v_14978 = (*qfn2(fn))(fn, v_14979, v_14978);
    env = stack[-6];
    goto v_14542;
v_14544:
    v_14978 = v_14979;
    goto v_14542;
    v_14978 = nil;
v_14542:
    goto v_14537;
v_14538:
    goto v_14534;
v_14535:
    goto v_14536;
v_14537:
    fn = elt(env, 6); // mtchk
    v_14978 = (*qfn2(fn))(fn, stack[0], v_14978);
    env = stack[-6];
    stack[-3] = v_14978;
    v_14978 = stack[-3];
    if (v_14978 == nil) goto v_14571;
    else goto v_14572;
v_14571:
    goto v_14527;
v_14572:
    v_14978 = stack[-3];
    v_14978 = qcar(v_14978);
    v_14978 = qcar(v_14978);
    if (v_14978 == nil) goto v_14574;
    else goto v_14575;
v_14574:
    goto v_14528;
v_14575:
    goto v_14586;
v_14580:
    v_14978 = stack[-4];
    v_14980 = qcdr(v_14978);
    goto v_14581;
v_14582:
    v_14979 = stack[-3];
    goto v_14583;
v_14584:
    v_14978 = nil;
    goto v_14585;
v_14586:
    goto v_14580;
v_14581:
    goto v_14582;
v_14583:
    goto v_14584;
v_14585:
    fn = elt(env, 7); // subs3f1
    v_14978 = (*qfnn(fn))(fn, 3, v_14980, v_14979, v_14978);
    env = stack[-6];
    stack[-2] = v_14978;
    v_14978 = qvalue(elt(env, 1)); // mchfg!*
    if (v_14978 == nil) goto v_14594;
    goto v_14601;
v_14597:
    goto v_14607;
v_14603:
    goto v_14614;
v_14610:
    v_14978 = stack[-4];
    v_14979 = qcar(v_14978);
    goto v_14611;
v_14612:
    v_14978 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14613;
v_14614:
    goto v_14610;
v_14611:
    goto v_14612;
v_14613:
    v_14978 = cons(v_14979, v_14978);
    env = stack[-6];
    v_14979 = ncons(v_14978);
    env = stack[-6];
    goto v_14604;
v_14605:
    v_14978 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14606;
v_14607:
    goto v_14603;
v_14604:
    goto v_14605;
v_14606:
    v_14979 = cons(v_14979, v_14978);
    env = stack[-6];
    goto v_14598;
v_14599:
    v_14978 = stack[-2];
    goto v_14600;
v_14601:
    goto v_14597;
v_14598:
    goto v_14599;
v_14600:
    {
        fn = elt(env, 8); // multsq
        return (*qfn2(fn))(fn, v_14979, v_14978);
    }
v_14594:
v_14527:
    goto v_14625;
v_14621:
    v_14978 = stack[-4];
    v_14979 = ncons(v_14978);
    goto v_14622;
v_14623:
    v_14978 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14624;
v_14625:
    goto v_14621;
v_14622:
    goto v_14623;
v_14624:
    return cons(v_14979, v_14978);
v_14528:
    v_14978 = stack[-3];
    v_14978 = qcar(v_14978);
    v_14978 = qcdr(v_14978);
    v_14978 = qcdr(v_14978);
    stack[-3] = v_14978;
    v_14978 = stack[-3];
    v_14978 = qcdr(v_14978);
    v_14978 = qcar(v_14978);
    v_14978 = qcar(v_14978);
    stack[-1] = v_14978;
    v_14978 = nil;
    qvalue(elt(env, 1)) = v_14978; // mchfg!*
    goto v_14645;
v_14639:
    v_14978 = stack[-4];
    v_14980 = qcdr(v_14978);
    goto v_14640;
v_14641:
    v_14979 = qvalue(elt(env, 2)); // !*match
    goto v_14642;
v_14643:
    v_14978 = nil;
    goto v_14644;
v_14645:
    goto v_14639;
v_14640:
    goto v_14641;
v_14642:
    goto v_14643;
v_14644:
    fn = elt(env, 7); // subs3f1
    v_14978 = (*qfnn(fn))(fn, 3, v_14980, v_14979, v_14978);
    env = stack[-6];
    stack[-2] = v_14978;
    v_14978 = lisp_true;
    qvalue(elt(env, 1)) = v_14978; // mchfg!*
    goto v_14659;
v_14655:
    v_14978 = stack[-1];
    v_14979 = qcar(v_14978);
    goto v_14656;
v_14657:
    v_14978 = stack[-4];
    v_14978 = qcar(v_14978);
    v_14978 = qcar(v_14978);
    goto v_14658;
v_14659:
    goto v_14655;
v_14656:
    goto v_14657;
v_14658:
    if (equal(v_14979, v_14978)) goto v_14654;
    goto v_14532;
v_14654:
    goto v_14671;
v_14667:
    v_14979 = stack[-1];
    goto v_14668;
v_14669:
    v_14978 = stack[-4];
    v_14978 = qcar(v_14978);
    goto v_14670;
v_14671:
    goto v_14667;
v_14668:
    goto v_14669;
v_14670:
    if (equal(v_14979, v_14978)) goto v_14666;
    goto v_14680;
v_14676:
    goto v_14686;
v_14682:
    goto v_14693;
v_14689:
    goto v_14699;
v_14695:
    v_14978 = stack[-4];
    v_14978 = qcar(v_14978);
    stack[0] = qcar(v_14978);
    goto v_14696;
v_14697:
    goto v_14708;
v_14704:
    v_14978 = stack[-4];
    v_14978 = qcar(v_14978);
    v_14979 = qcdr(v_14978);
    goto v_14705;
v_14706:
    v_14978 = stack[-1];
    v_14978 = qcdr(v_14978);
    goto v_14707;
v_14708:
    goto v_14704;
v_14705:
    goto v_14706;
v_14707:
    v_14978 = difference2(v_14979, v_14978);
    env = stack[-6];
    goto v_14698;
v_14699:
    goto v_14695;
v_14696:
    goto v_14697;
v_14698:
    fn = elt(env, 9); // to
    v_14979 = (*qfn2(fn))(fn, stack[0], v_14978);
    env = stack[-6];
    goto v_14690;
v_14691:
    v_14978 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14692;
v_14693:
    goto v_14689;
v_14690:
    goto v_14691;
v_14692:
    v_14978 = cons(v_14979, v_14978);
    env = stack[-6];
    v_14979 = ncons(v_14978);
    env = stack[-6];
    goto v_14683;
v_14684:
    v_14978 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14685;
v_14686:
    goto v_14682;
v_14683:
    goto v_14684;
v_14685:
    v_14979 = cons(v_14979, v_14978);
    env = stack[-6];
    goto v_14677;
v_14678:
    v_14978 = stack[-2];
    goto v_14679;
v_14680:
    goto v_14676;
v_14677:
    goto v_14678;
v_14679:
    fn = elt(env, 8); // multsq
    v_14978 = (*qfn2(fn))(fn, v_14979, v_14978);
    env = stack[-6];
    stack[-2] = v_14978;
    goto v_14652;
v_14666:
v_14652:
v_14529:
    goto v_14722;
v_14718:
    v_14978 = stack[-3];
    fn = elt(env, 10); // simpcar
    v_14979 = (*qfn1(fn))(fn, v_14978);
    env = stack[-6];
    goto v_14719;
v_14720:
    v_14978 = stack[-2];
    goto v_14721;
v_14722:
    goto v_14718;
v_14719:
    goto v_14720;
v_14721:
    fn = elt(env, 8); // multsq
    v_14978 = (*qfn2(fn))(fn, v_14979, v_14978);
    env = stack[-6];
    stack[-2] = v_14978;
    v_14978 = stack[-3];
    v_14978 = qcdr(v_14978);
    v_14978 = qcar(v_14978);
    v_14978 = qcdr(v_14978);
    stack[-3] = v_14978;
    v_14978 = stack[-3];
    if (v_14978 == nil) goto v_14732;
    else goto v_14733;
v_14732:
    v_14978 = stack[-2];
    goto v_14526;
v_14733:
    v_14978 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_14978;
v_14530:
    v_14978 = stack[-3];
    if (v_14978 == nil) goto v_14739;
    else goto v_14740;
v_14739:
    goto v_14531;
v_14740:
    v_14978 = stack[-3];
    v_14978 = qcar(v_14978);
    v_14978 = qcar(v_14978);
    if (!consp(v_14978)) goto v_14748;
    else goto v_14749;
v_14748:
    v_14978 = lisp_true;
    goto v_14747;
v_14749:
    v_14978 = stack[-3];
    v_14978 = qcar(v_14978);
    v_14978 = qcar(v_14978);
    fn = elt(env, 11); // sfp
    v_14978 = (*qfn1(fn))(fn, v_14978);
    env = stack[-6];
    goto v_14747;
    v_14978 = nil;
v_14747:
    if (v_14978 == nil) goto v_14745;
    v_14978 = stack[-3];
    v_14978 = qcar(v_14978);
    v_14978 = qcar(v_14978);
    goto v_14743;
v_14745:
    v_14978 = nil;
// Binding subfg!*
// FLUIDBIND: reloadenv=6 litvec-offset=3 saveloc=4
{   bind_fluid_stack bind_fluid_var(-6, 3, -4);
    qvalue(elt(env, 3)) = v_14978; // subfg!*
    v_14978 = stack[-3];
    v_14978 = qcar(v_14978);
    v_14978 = qcar(v_14978);
    fn = elt(env, 12); // simp
    v_14978 = (*qfn1(fn))(fn, v_14978);
    env = stack[-6];
    stack[0] = v_14978;
    v_14978 = stack[0];
    fn = elt(env, 13); // kernp
    v_14978 = (*qfn1(fn))(fn, v_14978);
    env = stack[-6];
    if (v_14978 == nil) goto v_14775;
    goto v_14785;
v_14781:
    v_14978 = stack[0];
    v_14978 = qcar(v_14978);
    v_14978 = qcar(v_14978);
    v_14978 = qcar(v_14978);
    v_14979 = qcar(v_14978);
    stack[0] = v_14979;
    goto v_14782;
v_14783:
    v_14978 = stack[-3];
    v_14978 = qcar(v_14978);
    v_14978 = qcar(v_14978);
    v_14978 = qcar(v_14978);
    goto v_14784;
v_14785:
    goto v_14781;
v_14782:
    goto v_14783;
v_14784:
    if (!consp(v_14979)) goto v_14775;
    v_14979 = qcar(v_14979);
    if (v_14979 == v_14978) goto v_14779;
    else goto v_14775;
v_14779:
    v_14978 = stack[0];
    goto v_14773;
v_14775:
    v_14978 = stack[-3];
    v_14978 = qcar(v_14978);
    v_14978 = qcar(v_14978);
    fn = elt(env, 14); // revop1
    v_14978 = (*qfn1(fn))(fn, v_14978);
    env = stack[-6];
    goto v_14773;
    v_14978 = nil;
v_14773:
    ;}  // end of a binding scope
    goto v_14743;
    v_14978 = nil;
v_14743:
    stack[0] = v_14978;
    v_14978 = stack[0];
    fn = elt(env, 15); // noncomp
    v_14978 = (*qfn1(fn))(fn, v_14978);
    env = stack[-6];
    if (v_14978 == nil) goto v_14806;
    else goto v_14804;
v_14806:
    v_14978 = qvalue(elt(env, 4)); // !*mcd
    if (v_14978 == nil) goto v_14804;
    goto v_14805;
v_14804:
    v_14978 = lisp_true;
    stack[-5] = v_14978;
    goto v_14803;
v_14805:
v_14803:
    goto v_14817;
v_14813:
    goto v_14814;
v_14815:
    goto v_14825;
v_14821:
    goto v_14831;
v_14827:
    goto v_14828;
v_14829:
    v_14978 = stack[-5];
    if (v_14978 == nil) goto v_14835;
    else goto v_14836;
v_14835:
    v_14978 = stack[-3];
    v_14978 = qcar(v_14978);
    v_14978 = qcdr(v_14978);
    goto v_14834;
v_14836:
    v_14978 = stack[-3];
    v_14978 = qcar(v_14978);
    v_14978 = qcdr(v_14978);
    v_14978 = negate(v_14978);
    env = stack[-6];
    goto v_14834;
    v_14978 = nil;
v_14834:
    goto v_14830;
v_14831:
    goto v_14827;
v_14828:
    goto v_14829;
v_14830:
    fn = elt(env, 16); // mksp
    v_14979 = (*qfn2(fn))(fn, stack[0], v_14978);
    env = stack[-6];
    goto v_14822;
v_14823:
    v_14978 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14824;
v_14825:
    goto v_14821;
v_14822:
    goto v_14823;
v_14824:
    v_14978 = cons(v_14979, v_14978);
    env = stack[-6];
    v_14978 = ncons(v_14978);
    env = stack[-6];
    goto v_14816;
v_14817:
    goto v_14813;
v_14814:
    goto v_14815;
v_14816:
    fn = elt(env, 17); // multf
    v_14978 = (*qfn2(fn))(fn, stack[-1], v_14978);
    env = stack[-6];
    stack[-1] = v_14978;
    v_14978 = stack[-3];
    v_14978 = qcdr(v_14978);
    stack[-3] = v_14978;
    goto v_14530;
v_14531:
    v_14978 = stack[-5];
    if (v_14978 == nil) goto v_14852;
    else goto v_14853;
v_14852:
    goto v_14860;
v_14856:
    v_14978 = stack[-2];
    stack[0] = qcar(v_14978);
    goto v_14857;
v_14858:
    goto v_14868;
v_14864:
    v_14979 = stack[-1];
    goto v_14865;
v_14866:
    v_14978 = stack[-2];
    v_14978 = qcdr(v_14978);
    goto v_14867;
v_14868:
    goto v_14864;
v_14865:
    goto v_14866;
v_14867:
    fn = elt(env, 17); // multf
    v_14978 = (*qfn2(fn))(fn, v_14979, v_14978);
    goto v_14859;
v_14860:
    goto v_14856;
v_14857:
    goto v_14858;
v_14859:
    {
        LispObject v_14988 = stack[0];
        return cons(v_14988, v_14978);
    }
v_14853:
    goto v_14879;
v_14875:
    goto v_14885;
v_14881:
    v_14979 = stack[-1];
    goto v_14882;
v_14883:
    v_14978 = stack[-2];
    v_14978 = qcar(v_14978);
    goto v_14884;
v_14885:
    goto v_14881;
v_14882:
    goto v_14883;
v_14884:
    fn = elt(env, 17); // multf
    v_14979 = (*qfn2(fn))(fn, v_14979, v_14978);
    goto v_14876;
v_14877:
    v_14978 = stack[-2];
    v_14978 = qcdr(v_14978);
    goto v_14878;
v_14879:
    goto v_14875;
v_14876:
    goto v_14877;
v_14878:
    return cons(v_14979, v_14978);
    v_14978 = nil;
    goto v_14526;
v_14532:
    goto v_14899;
v_14895:
    v_14978 = stack[-1];
    v_14978 = qcar(v_14978);
    fn = elt(env, 12); // simp
    stack[0] = (*qfn1(fn))(fn, v_14978);
    env = stack[-6];
    goto v_14896;
v_14897:
    v_14978 = stack[-4];
    v_14978 = qcar(v_14978);
    v_14978 = qcar(v_14978);
    fn = elt(env, 12); // simp
    v_14978 = (*qfn1(fn))(fn, v_14978);
    env = stack[-6];
    goto v_14898;
v_14899:
    goto v_14895;
v_14896:
    goto v_14897;
v_14898:
    if (equal(stack[0], v_14978)) goto v_14894;
    goto v_14917;
v_14909:
    v_14981 = elt(env, 0); // subs3t
    goto v_14910;
v_14911:
    v_14980 = stack[-4];
    goto v_14912;
v_14913:
    v_14979 = stack[-3];
    goto v_14914;
v_14915:
    v_14978 = stack[-1];
    goto v_14916;
v_14917:
    goto v_14909;
v_14910:
    goto v_14911;
v_14912:
    goto v_14913;
v_14914:
    goto v_14915;
v_14916:
    v_14978 = list4(v_14981, v_14980, v_14979, v_14978);
    env = stack[-6];
    fn = elt(env, 18); // errach
    v_14978 = (*qfn1(fn))(fn, v_14978);
    env = stack[-6];
    goto v_14892;
v_14894:
v_14892:
    goto v_14930;
v_14926:
    v_14978 = stack[-1];
    v_14979 = qcdr(v_14978);
    goto v_14927;
v_14928:
    v_14978 = stack[-4];
    v_14978 = qcar(v_14978);
    v_14978 = qcdr(v_14978);
    goto v_14929;
v_14930:
    goto v_14926;
v_14927:
    goto v_14928;
v_14929:
    if (equal(v_14979, v_14978)) goto v_14925;
    goto v_14941;
v_14937:
    goto v_14947;
v_14943:
    goto v_14954;
v_14950:
    goto v_14960;
v_14956:
    v_14978 = stack[-4];
    v_14978 = qcar(v_14978);
    stack[0] = qcar(v_14978);
    goto v_14957;
v_14958:
    goto v_14969;
v_14965:
    v_14978 = stack[-4];
    v_14978 = qcar(v_14978);
    v_14979 = qcdr(v_14978);
    goto v_14966;
v_14967:
    v_14978 = stack[-1];
    v_14978 = qcdr(v_14978);
    goto v_14968;
v_14969:
    goto v_14965;
v_14966:
    goto v_14967;
v_14968:
    v_14978 = difference2(v_14979, v_14978);
    env = stack[-6];
    goto v_14959;
v_14960:
    goto v_14956;
v_14957:
    goto v_14958;
v_14959:
    fn = elt(env, 9); // to
    v_14979 = (*qfn2(fn))(fn, stack[0], v_14978);
    env = stack[-6];
    goto v_14951;
v_14952:
    v_14978 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14953;
v_14954:
    goto v_14950;
v_14951:
    goto v_14952;
v_14953:
    v_14978 = cons(v_14979, v_14978);
    env = stack[-6];
    v_14979 = ncons(v_14978);
    env = stack[-6];
    goto v_14944;
v_14945:
    v_14978 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14946;
v_14947:
    goto v_14943;
v_14944:
    goto v_14945;
v_14946:
    v_14979 = cons(v_14979, v_14978);
    env = stack[-6];
    goto v_14938;
v_14939:
    v_14978 = stack[-2];
    goto v_14940;
v_14941:
    goto v_14937;
v_14938:
    goto v_14939;
v_14940:
    fn = elt(env, 8); // multsq
    v_14978 = (*qfn2(fn))(fn, v_14979, v_14978);
    env = stack[-6];
    stack[-2] = v_14978;
    goto v_14923;
v_14925:
v_14923:
    goto v_14529;
v_14526:
    return onevalue(v_14978);
}



// Code for charnump!:

static LispObject CC_charnumpT(LispObject env,
                         LispObject v_14517)
{
    env = qenv(env);
    LispObject v_14591, v_14592;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14517);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(14);
// copy arguments values to proper place
    v_14591 = v_14517;
// end of prologue
    goto v_14527;
v_14523:
    stack[-12] = v_14591;
    goto v_14524;
v_14525:
    goto v_14538;
v_14530:
    stack[-11] = elt(env, 1); // !0
    goto v_14531;
v_14532:
    stack[-10] = elt(env, 2); // !1
    goto v_14533;
v_14534:
    stack[-9] = elt(env, 3); // !2
    goto v_14535;
v_14536:
    goto v_14551;
v_14543:
    stack[-8] = elt(env, 4); // !3
    goto v_14544;
v_14545:
    stack[-7] = elt(env, 5); // !4
    goto v_14546;
v_14547:
    stack[-6] = elt(env, 6); // !5
    goto v_14548;
v_14549:
    goto v_14564;
v_14556:
    stack[-5] = elt(env, 7); // !6
    goto v_14557;
v_14558:
    stack[-4] = elt(env, 8); // !7
    goto v_14559;
v_14560:
    stack[-3] = elt(env, 9); // !8
    goto v_14561;
v_14562:
    goto v_14577;
v_14569:
    stack[-2] = elt(env, 10); // !9
    goto v_14570;
v_14571:
    stack[-1] = elt(env, 11); // !10
    goto v_14572;
v_14573:
    stack[0] = elt(env, 12); // !11
    goto v_14574;
v_14575:
    goto v_14586;
v_14582:
    v_14592 = elt(env, 13); // !12
    goto v_14583;
v_14584:
    v_14591 = elt(env, 14); // !13
    goto v_14585;
v_14586:
    goto v_14582;
v_14583:
    goto v_14584;
v_14585:
    v_14591 = list2(v_14592, v_14591);
    env = stack[-13];
    goto v_14576;
v_14577:
    goto v_14569;
v_14570:
    goto v_14571;
v_14572:
    goto v_14573;
v_14574:
    goto v_14575;
v_14576:
    v_14591 = list3star(stack[-2], stack[-1], stack[0], v_14591);
    env = stack[-13];
    goto v_14563;
v_14564:
    goto v_14556;
v_14557:
    goto v_14558;
v_14559:
    goto v_14560;
v_14561:
    goto v_14562;
v_14563:
    v_14591 = list3star(stack[-5], stack[-4], stack[-3], v_14591);
    env = stack[-13];
    goto v_14550;
v_14551:
    goto v_14543;
v_14544:
    goto v_14545;
v_14546:
    goto v_14547;
v_14548:
    goto v_14549;
v_14550:
    v_14591 = list3star(stack[-8], stack[-7], stack[-6], v_14591);
    env = stack[-13];
    goto v_14537;
v_14538:
    goto v_14530;
v_14531:
    goto v_14532;
v_14533:
    goto v_14534;
v_14535:
    goto v_14536;
v_14537:
    v_14591 = list3star(stack[-11], stack[-10], stack[-9], v_14591);
    goto v_14526;
v_14527:
    goto v_14523;
v_14524:
    goto v_14525;
v_14526:
    v_14591 = Lmemq(nil, stack[-12], v_14591);
    if (v_14591 == nil) goto v_14522;
    v_14591 = lisp_true;
    goto v_14520;
v_14522:
    v_14591 = nil;
v_14520:
    return onevalue(v_14591);
}



// Code for trailing!.coefft

static LispObject CC_trailingQcoefft(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14556, v_14557, v_14558, v_14559;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14557 = v_14518;
    v_14558 = v_14517;
// end of prologue
v_14522:
    v_14556 = v_14558;
    if (!consp(v_14556)) goto v_14529;
    else goto v_14530;
v_14529:
    v_14556 = lisp_true;
    goto v_14528;
v_14530:
    v_14556 = v_14558;
    v_14556 = qcar(v_14556);
    v_14556 = (consp(v_14556) ? nil : lisp_true);
    goto v_14528;
    v_14556 = nil;
v_14528:
    if (v_14556 == nil) goto v_14526;
    v_14556 = v_14558;
    goto v_14521;
v_14526:
    goto v_14545;
v_14541:
    v_14556 = v_14558;
    v_14556 = qcar(v_14556);
    v_14556 = qcar(v_14556);
    v_14559 = qcar(v_14556);
    goto v_14542;
v_14543:
    v_14556 = v_14557;
    goto v_14544;
v_14545:
    goto v_14541;
v_14542:
    goto v_14543;
v_14544:
    if (equal(v_14559, v_14556)) goto v_14539;
    else goto v_14540;
v_14539:
    v_14556 = v_14558;
    v_14556 = qcdr(v_14556);
    v_14558 = v_14556;
    goto v_14522;
v_14540:
    v_14556 = v_14558;
    goto v_14521;
    v_14556 = nil;
v_14521:
    return onevalue(v_14556);
}



// Code for extmult

static LispObject CC_extmult(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14666, v_14667, v_14668;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_14518;
    stack[-4] = v_14517;
// end of prologue
    stack[-5] = nil;
v_14526:
    v_14666 = stack[-4];
    if (v_14666 == nil) goto v_14534;
    else goto v_14535;
v_14534:
    v_14666 = lisp_true;
    goto v_14533;
v_14535:
    v_14666 = stack[-3];
    v_14666 = (v_14666 == nil ? lisp_true : nil);
    goto v_14533;
    v_14666 = nil;
v_14533:
    if (v_14666 == nil) goto v_14531;
    v_14666 = nil;
    stack[0] = v_14666;
    goto v_14527;
v_14531:
    goto v_14550;
v_14544:
    v_14668 = stack[-4];
    goto v_14545;
v_14546:
    v_14667 = stack[-3];
    goto v_14547;
v_14548:
    v_14666 = stack[-5];
    goto v_14549;
v_14550:
    goto v_14544;
v_14545:
    goto v_14546;
v_14547:
    goto v_14548;
v_14549:
    v_14666 = acons(v_14668, v_14667, v_14666);
    env = stack[-6];
    stack[-5] = v_14666;
    v_14666 = stack[-4];
    v_14666 = qcdr(v_14666);
    if (v_14666 == nil) goto v_14557;
    v_14666 = stack[-4];
    v_14666 = qcar(v_14666);
    v_14666 = ncons(v_14666);
    env = stack[-6];
    stack[-4] = v_14666;
    goto v_14555;
v_14557:
v_14555:
    v_14666 = stack[-3];
    v_14666 = qcdr(v_14666);
    stack[-3] = v_14666;
    goto v_14526;
v_14527:
v_14567:
    v_14666 = stack[-5];
    if (v_14666 == nil) goto v_14570;
    else goto v_14571;
v_14570:
    goto v_14566;
v_14571:
    v_14666 = stack[-5];
    v_14666 = qcar(v_14666);
    v_14666 = qcar(v_14666);
    stack[-4] = v_14666;
    v_14666 = stack[-5];
    v_14666 = qcar(v_14666);
    v_14666 = qcdr(v_14666);
    stack[-3] = v_14666;
    v_14666 = stack[-5];
    v_14666 = qcdr(v_14666);
    stack[-5] = v_14666;
    goto v_14587;
v_14583:
    v_14666 = stack[-4];
    v_14666 = qcar(v_14666);
    v_14666 = qcar(v_14666);
    v_14667 = qcar(v_14666);
    goto v_14584;
v_14585:
    v_14666 = stack[-3];
    v_14666 = qcar(v_14666);
    v_14666 = qcar(v_14666);
    goto v_14586;
v_14587:
    goto v_14583;
v_14584:
    goto v_14585;
v_14586:
    fn = elt(env, 1); // ordexn
    v_14666 = (*qfn2(fn))(fn, v_14667, v_14666);
    env = stack[-6];
    stack[-1] = v_14666;
    v_14666 = stack[-1];
    if (v_14666 == nil) goto v_14598;
    goto v_14605;
v_14601:
    v_14666 = stack[-4];
    v_14666 = qcar(v_14666);
    v_14667 = qcdr(v_14666);
    goto v_14602;
v_14603:
    v_14666 = stack[-3];
    v_14666 = qcar(v_14666);
    v_14666 = qcdr(v_14666);
    goto v_14604;
v_14605:
    goto v_14601;
v_14602:
    goto v_14603;
v_14604:
    fn = elt(env, 2); // c!:subs2multf
    v_14666 = (*qfn2(fn))(fn, v_14667, v_14666);
    env = stack[-6];
    v_14667 = v_14666;
    v_14666 = stack[-1];
    v_14666 = qcar(v_14666);
    if (v_14666 == nil) goto v_14615;
    v_14666 = v_14667;
    fn = elt(env, 3); // negf
    v_14666 = (*qfn1(fn))(fn, v_14666);
    env = stack[-6];
    v_14667 = v_14666;
    goto v_14613;
v_14615:
v_14613:
    goto v_14627;
v_14621:
    v_14666 = stack[-1];
    stack[-2] = qcdr(v_14666);
    goto v_14622;
v_14623:
    stack[-1] = v_14667;
    goto v_14624;
v_14625:
    goto v_14636;
v_14632:
    goto v_14633;
v_14634:
    goto v_14643;
v_14639:
    v_14666 = stack[-4];
    v_14667 = qcdr(v_14666);
    goto v_14640;
v_14641:
    v_14666 = stack[-3];
    goto v_14642;
v_14643:
    goto v_14639;
v_14640:
    goto v_14641;
v_14642:
    v_14666 = CC_extmult(elt(env, 0), v_14667, v_14666);
    env = stack[-6];
    goto v_14635;
v_14636:
    goto v_14632;
v_14633:
    goto v_14634;
v_14635:
    fn = elt(env, 4); // extadd
    v_14666 = (*qfn2(fn))(fn, stack[0], v_14666);
    env = stack[-6];
    goto v_14626;
v_14627:
    goto v_14621;
v_14622:
    goto v_14623;
v_14624:
    goto v_14625;
v_14626:
    v_14666 = acons(stack[-2], stack[-1], v_14666);
    env = stack[-6];
    stack[0] = v_14666;
    goto v_14596;
v_14598:
    goto v_14654;
v_14650:
    goto v_14660;
v_14656:
    v_14666 = stack[-4];
    v_14667 = qcdr(v_14666);
    goto v_14657;
v_14658:
    v_14666 = stack[-3];
    goto v_14659;
v_14660:
    goto v_14656;
v_14657:
    goto v_14658;
v_14659:
    v_14667 = CC_extmult(elt(env, 0), v_14667, v_14666);
    env = stack[-6];
    goto v_14651;
v_14652:
    v_14666 = stack[0];
    goto v_14653;
v_14654:
    goto v_14650;
v_14651:
    goto v_14652;
v_14653:
    fn = elt(env, 4); // extadd
    v_14666 = (*qfn2(fn))(fn, v_14667, v_14666);
    env = stack[-6];
    stack[0] = v_14666;
    goto v_14596;
v_14596:
    goto v_14567;
v_14566:
    v_14666 = stack[0];
    return onevalue(v_14666);
}



// Code for ofsf_at2ir

static LispObject CC_ofsf_at2ir(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14614, v_14615, v_14616;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_14518;
    v_14615 = v_14517;
// end of prologue
    v_14614 = v_14615;
    v_14614 = qcar(v_14614);
    stack[-4] = v_14614;
    v_14614 = v_14615;
    v_14614 = qcdr(v_14614);
    v_14614 = qcar(v_14614);
    stack[-2] = v_14614;
    stack[0] = v_14614;
v_14533:
    v_14614 = stack[0];
    if (!consp(v_14614)) goto v_14540;
    else goto v_14541;
v_14540:
    v_14614 = lisp_true;
    goto v_14539;
v_14541:
    v_14614 = stack[0];
    v_14614 = qcar(v_14614);
    v_14614 = (consp(v_14614) ? nil : lisp_true);
    goto v_14539;
    v_14614 = nil;
v_14539:
    if (v_14614 == nil) goto v_14537;
    goto v_14532;
v_14537:
    v_14614 = stack[0];
    v_14614 = qcdr(v_14614);
    stack[0] = v_14614;
    goto v_14533;
v_14532:
    goto v_14557;
v_14553:
    stack[-1] = stack[-2];
    goto v_14554;
v_14555:
    v_14614 = stack[0];
    fn = elt(env, 1); // negf
    v_14614 = (*qfn1(fn))(fn, v_14614);
    env = stack[-5];
    goto v_14556;
v_14557:
    goto v_14553;
v_14554:
    goto v_14555;
v_14556:
    fn = elt(env, 2); // addf
    v_14614 = (*qfn2(fn))(fn, stack[-1], v_14614);
    env = stack[-5];
    stack[-2] = v_14614;
    v_14614 = stack[-2];
    fn = elt(env, 3); // sfto_dcontentf
    v_14614 = (*qfn1(fn))(fn, v_14614);
    env = stack[-5];
    stack[-1] = v_14614;
    goto v_14568;
v_14564:
    v_14615 = stack[-2];
    goto v_14565;
v_14566:
    v_14614 = stack[-1];
    goto v_14567;
v_14568:
    goto v_14564;
v_14565:
    goto v_14566;
v_14567:
    fn = elt(env, 4); // quotf
    v_14614 = (*qfn2(fn))(fn, v_14615, v_14614);
    env = stack[-5];
    stack[-2] = v_14614;
    goto v_14576;
v_14572:
    goto v_14582;
v_14578:
    v_14615 = stack[0];
    goto v_14579;
v_14580:
    v_14614 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14581;
v_14582:
    goto v_14578;
v_14579:
    goto v_14580;
v_14581:
    stack[0] = cons(v_14615, v_14614);
    env = stack[-5];
    goto v_14573;
v_14574:
    goto v_14590;
v_14586:
    v_14615 = stack[-1];
    goto v_14587;
v_14588:
    v_14614 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14589;
v_14590:
    goto v_14586;
v_14587:
    goto v_14588;
v_14589:
    v_14614 = cons(v_14615, v_14614);
    env = stack[-5];
    goto v_14575;
v_14576:
    goto v_14572;
v_14573:
    goto v_14574;
v_14575:
    fn = elt(env, 5); // quotsq
    v_14614 = (*qfn2(fn))(fn, stack[0], v_14614);
    env = stack[-5];
    stack[0] = v_14614;
    goto v_14600;
v_14594:
    stack[-1] = stack[-2];
    goto v_14595;
v_14596:
    goto v_14609;
v_14603:
    v_14616 = stack[-3];
    goto v_14604;
v_14605:
    v_14615 = stack[-4];
    goto v_14606;
v_14607:
    v_14614 = stack[0];
    goto v_14608;
v_14609:
    goto v_14603;
v_14604:
    goto v_14605;
v_14606:
    goto v_14607;
v_14608:
    v_14615 = list2star(v_14616, v_14615, v_14614);
    goto v_14597;
v_14598:
    v_14614 = nil;
    goto v_14599;
v_14600:
    goto v_14594;
v_14595:
    goto v_14596;
v_14597:
    goto v_14598;
v_14599:
    {
        LispObject v_14622 = stack[-1];
        return list2star(v_14622, v_14615, v_14614);
    }
    return onevalue(v_14614);
}



// Code for smemberlp

static LispObject CC_smemberlp(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14560, v_14561;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_14518;
    stack[-1] = v_14517;
// end of prologue
v_14516:
    v_14560 = stack[0];
    if (v_14560 == nil) goto v_14522;
    else goto v_14523;
v_14522:
    v_14560 = nil;
    goto v_14521;
v_14523:
    v_14560 = stack[0];
    if (!consp(v_14560)) goto v_14526;
    else goto v_14527;
v_14526:
    goto v_14533;
v_14529:
    v_14561 = stack[0];
    goto v_14530;
v_14531:
    v_14560 = stack[-1];
    goto v_14532;
v_14533:
    goto v_14529;
v_14530:
    goto v_14531;
v_14532:
    v_14560 = Lmember(nil, v_14561, v_14560);
    goto v_14521;
v_14527:
    goto v_14547;
v_14543:
    v_14561 = stack[-1];
    goto v_14544;
v_14545:
    v_14560 = stack[0];
    v_14560 = qcar(v_14560);
    goto v_14546;
v_14547:
    goto v_14543;
v_14544:
    goto v_14545;
v_14546:
    v_14560 = CC_smemberlp(elt(env, 0), v_14561, v_14560);
    env = stack[-2];
    if (v_14560 == nil) goto v_14541;
    else goto v_14540;
v_14541:
    goto v_14556;
v_14552:
    v_14561 = stack[-1];
    goto v_14553;
v_14554:
    v_14560 = stack[0];
    v_14560 = qcdr(v_14560);
    goto v_14555;
v_14556:
    goto v_14552;
v_14553:
    goto v_14554;
v_14555:
    stack[-1] = v_14561;
    stack[0] = v_14560;
    goto v_14516;
v_14540:
    goto v_14521;
    v_14560 = nil;
v_14521:
    return onevalue(v_14560);
}



// Code for offexpchk

static LispObject CC_offexpchk(LispObject env,
                         LispObject v_14517)
{
    env = qenv(env);
    LispObject v_14552;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14517);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_14517;
// end of prologue
    v_14552 = qvalue(elt(env, 1)); // !*really_off_exp
    if (v_14552 == nil) goto v_14523;
    else goto v_14521;
v_14523:
    v_14552 = qvalue(elt(env, 2)); // frlis!*
    if (v_14552 == nil) goto v_14526;
    v_14552 = stack[0];
    v_14552 = qcar(v_14552);
    fn = elt(env, 3); // freevarinexptchk
    v_14552 = (*qfn1(fn))(fn, v_14552);
    env = stack[-2];
    if (v_14552 == nil) goto v_14526;
    goto v_14521;
v_14526:
    v_14552 = stack[0];
    v_14552 = qcdr(v_14552);
    fn = elt(env, 3); // freevarinexptchk
    v_14552 = (*qfn1(fn))(fn, v_14552);
    env = stack[-2];
    if (v_14552 == nil) goto v_14533;
    else goto v_14521;
v_14533:
    goto v_14522;
v_14521:
    v_14552 = stack[0];
    goto v_14520;
v_14522:
    goto v_14545;
v_14541:
    v_14552 = stack[0];
    v_14552 = qcar(v_14552);
    fn = elt(env, 4); // mkprod
    stack[-1] = (*qfn1(fn))(fn, v_14552);
    env = stack[-2];
    goto v_14542;
v_14543:
    v_14552 = stack[0];
    v_14552 = qcdr(v_14552);
    fn = elt(env, 4); // mkprod
    v_14552 = (*qfn1(fn))(fn, v_14552);
    env = stack[-2];
    goto v_14544;
v_14545:
    goto v_14541;
v_14542:
    goto v_14543;
v_14544:
    {
        LispObject v_14555 = stack[-1];
        fn = elt(env, 5); // canprod
        return (*qfn2(fn))(fn, v_14555, v_14552);
    }
    v_14552 = nil;
v_14520:
    return onevalue(v_14552);
}



// Code for lambdafun

static LispObject CC_lambdafun(LispObject env,
                         LispObject v_14517)
{
    env = qenv(env);
    LispObject v_14524;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14517);
    }
// copy arguments values to proper place
    v_14524 = v_14517;
// end of prologue
    v_14524 = Lreverse(nil, v_14524);
    v_14524 = qcar(v_14524);
    return onevalue(v_14524);
}



// Code for setdmode

static LispObject CC_setdmode(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14682, v_14683, v_14684;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_14518;
    stack[-2] = v_14517;
// end of prologue
    v_14682 = stack[-2];
    if (!symbolp(v_14682)) v_14682 = nil;
    else { v_14682 = qfastgets(v_14682);
           if (v_14682 != nil) { v_14682 = elt(v_14682, 8); // dname
#ifdef RECORD_GET
             if (v_14682 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_14682 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_14682 == SPID_NOPROP) v_14682 = nil; }}
#endif
    stack[0] = v_14682;
    if (v_14682 == nil) goto v_14526;
    v_14682 = stack[0];
    stack[-2] = v_14682;
    goto v_14524;
v_14526:
v_14524:
    goto v_14538;
v_14534:
    v_14683 = stack[-2];
    goto v_14535;
v_14536:
    v_14682 = elt(env, 1); // complex!-rational
    goto v_14537;
v_14538:
    goto v_14534;
v_14535:
    goto v_14536;
v_14537:
    if (v_14683 == v_14682) goto v_14532;
    else goto v_14533;
v_14532:
    v_14682 = qvalue(elt(env, 2)); // dmode!*
    stack[0] = v_14682;
    if (v_14682 == nil) goto v_14544;
    v_14682 = stack[0];
    if (!symbolp(v_14682)) v_14682 = nil;
    else { v_14682 = qfastgets(v_14682);
           if (v_14682 != nil) { v_14682 = elt(v_14682, 8); // dname
#ifdef RECORD_GET
             if (v_14682 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_14682 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_14682 == SPID_NOPROP) v_14682 = nil; }}
#endif
    stack[0] = v_14682;
    goto v_14542;
v_14544:
v_14542:
    goto v_14553;
v_14549:
    v_14683 = elt(env, 3); // complex
    goto v_14550;
v_14551:
    v_14682 = stack[-1];
    goto v_14552;
v_14553:
    goto v_14549;
v_14550:
    goto v_14551;
v_14552:
    fn = elt(env, 13); // onoff
    v_14682 = (*qfn2(fn))(fn, v_14683, v_14682);
    env = stack[-4];
    goto v_14561;
v_14557:
    v_14683 = elt(env, 4); // rational
    goto v_14558;
v_14559:
    v_14682 = stack[-1];
    goto v_14560;
v_14561:
    goto v_14557;
v_14558:
    goto v_14559;
v_14560:
    fn = elt(env, 13); // onoff
    v_14682 = (*qfn2(fn))(fn, v_14683, v_14682);
    v_14682 = stack[0];
    goto v_14522;
v_14533:
    goto v_14571;
v_14567:
    v_14683 = stack[-2];
    goto v_14568;
v_14569:
    v_14682 = elt(env, 5); // complex!-rounded
    goto v_14570;
v_14571:
    goto v_14567;
v_14568:
    goto v_14569;
v_14570:
    if (v_14683 == v_14682) goto v_14565;
    else goto v_14566;
v_14565:
    v_14682 = qvalue(elt(env, 2)); // dmode!*
    stack[0] = v_14682;
    if (v_14682 == nil) goto v_14577;
    v_14682 = stack[0];
    if (!symbolp(v_14682)) v_14682 = nil;
    else { v_14682 = qfastgets(v_14682);
           if (v_14682 != nil) { v_14682 = elt(v_14682, 8); // dname
#ifdef RECORD_GET
             if (v_14682 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_14682 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_14682 == SPID_NOPROP) v_14682 = nil; }}
#endif
    stack[0] = v_14682;
    goto v_14575;
v_14577:
v_14575:
    goto v_14586;
v_14582:
    v_14683 = elt(env, 3); // complex
    goto v_14583;
v_14584:
    v_14682 = stack[-1];
    goto v_14585;
v_14586:
    goto v_14582;
v_14583:
    goto v_14584;
v_14585:
    fn = elt(env, 13); // onoff
    v_14682 = (*qfn2(fn))(fn, v_14683, v_14682);
    env = stack[-4];
    goto v_14594;
v_14590:
    v_14683 = elt(env, 6); // rounded
    goto v_14591;
v_14592:
    v_14682 = stack[-1];
    goto v_14593;
v_14594:
    goto v_14590;
v_14591:
    goto v_14592;
v_14593:
    fn = elt(env, 13); // onoff
    v_14682 = (*qfn2(fn))(fn, v_14683, v_14682);
    v_14682 = stack[0];
    goto v_14522;
v_14566:
    goto v_14607;
v_14603:
    v_14683 = stack[-2];
    goto v_14604;
v_14605:
    v_14682 = elt(env, 7); // tag
    goto v_14606;
v_14607:
    goto v_14603;
v_14604:
    goto v_14605;
v_14606:
    v_14682 = get(v_14683, v_14682);
    env = stack[-4];
    if (v_14682 == nil) goto v_14600;
    else goto v_14601;
v_14600:
    goto v_14617;
v_14611:
    stack[-3] = elt(env, 8); // poly
    goto v_14612;
v_14613:
    stack[0] = (LispObject)80+TAG_FIXNUM; // 5
    goto v_14614;
v_14615:
    goto v_14627;
v_14621:
    v_14684 = elt(env, 9); // "Domain mode error:"
    goto v_14622;
v_14623:
    v_14683 = stack[-2];
    goto v_14624;
v_14625:
    v_14682 = elt(env, 10); // "is not a domain mode"
    goto v_14626;
v_14627:
    goto v_14621;
v_14622:
    goto v_14623;
v_14624:
    goto v_14625;
v_14626:
    v_14682 = list3(v_14684, v_14683, v_14682);
    env = stack[-4];
    goto v_14616;
v_14617:
    goto v_14611;
v_14612:
    goto v_14613;
v_14614:
    goto v_14615;
v_14616:
    fn = elt(env, 14); // rerror
    v_14682 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_14682);
    env = stack[-4];
    goto v_14599;
v_14601:
v_14599:
    goto v_14640;
v_14636:
    v_14683 = stack[-2];
    goto v_14637;
v_14638:
    v_14682 = elt(env, 11); // package!-name
    goto v_14639;
v_14640:
    goto v_14636;
v_14637:
    goto v_14638;
v_14639:
    v_14682 = get(v_14683, v_14682);
    env = stack[-4];
    stack[0] = v_14682;
    if (v_14682 == nil) goto v_14634;
    v_14682 = stack[0];
    fn = elt(env, 15); // load!-package
    v_14682 = (*qfn1(fn))(fn, v_14682);
    env = stack[-4];
    goto v_14632;
v_14634:
v_14632:
    goto v_14657;
v_14653:
    v_14683 = stack[-2];
    goto v_14654;
v_14655:
    v_14682 = elt(env, 3); // complex
    goto v_14656;
v_14657:
    goto v_14653;
v_14654:
    goto v_14655;
v_14656:
    if (v_14683 == v_14682) goto v_14651;
    else goto v_14652;
v_14651:
    v_14682 = lisp_true;
    goto v_14650;
v_14652:
    v_14682 = qvalue(elt(env, 12)); // !*complex
    goto v_14650;
    v_14682 = nil;
v_14650:
    if (v_14682 == nil) goto v_14648;
    goto v_14669;
v_14665:
    v_14683 = stack[-2];
    goto v_14666;
v_14667:
    v_14682 = stack[-1];
    goto v_14668;
v_14669:
    goto v_14665;
v_14666:
    goto v_14667;
v_14668:
    {
        fn = elt(env, 16); // setcmpxmode
        return (*qfn2(fn))(fn, v_14683, v_14682);
    }
v_14648:
    goto v_14679;
v_14675:
    v_14683 = stack[-2];
    goto v_14676;
v_14677:
    v_14682 = stack[-1];
    goto v_14678;
v_14679:
    goto v_14675;
v_14676:
    goto v_14677;
v_14678:
    {
        fn = elt(env, 17); // setdmode1
        return (*qfn2(fn))(fn, v_14683, v_14682);
    }
    v_14682 = nil;
v_14522:
    return onevalue(v_14682);
}



// Code for random

static LispObject CC_random(LispObject env,
                         LispObject v_14517)
{
    env = qenv(env);
    LispObject v_14670, v_14671;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14517);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_14517;
// end of prologue
    v_14670 = stack[-3];
    if (is_number(v_14670)) goto v_14530;
    v_14670 = lisp_true;
    goto v_14528;
v_14530:
    goto v_14540;
v_14536:
    v_14671 = stack[-3];
    goto v_14537;
v_14538:
    v_14670 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14539;
v_14540:
    goto v_14536;
v_14537:
    goto v_14538;
v_14539:
    v_14670 = (LispObject)lesseq2(v_14671, v_14670);
    v_14670 = v_14670 ? lisp_true : nil;
    env = stack[-5];
    goto v_14528;
    v_14670 = nil;
v_14528:
    if (v_14670 == nil) goto v_14526;
    goto v_14548;
v_14544:
    v_14671 = stack[-3];
    goto v_14545;
v_14546:
    v_14670 = elt(env, 1); // "positive number"
    goto v_14547;
v_14548:
    goto v_14544;
v_14545:
    goto v_14546;
v_14547:
    fn = elt(env, 4); // typerr
    v_14670 = (*qfn2(fn))(fn, v_14671, v_14670);
    env = stack[-5];
    goto v_14524;
v_14526:
v_14524:
    v_14670 = stack[-3];
    v_14670 = Lfloatp(nil, v_14670);
    env = stack[-5];
    if (v_14670 == nil) goto v_14554;
    goto v_14562;
v_14558:
    fn = elt(env, 5); // next!-random!-number
    v_14670 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_14671 = Lfloat(nil, v_14670);
    env = stack[-5];
    goto v_14559;
v_14560:
    v_14670 = qvalue(elt(env, 2)); // unidev_fac!*
    goto v_14561;
v_14562:
    goto v_14558;
v_14559:
    goto v_14560;
v_14561:
    v_14670 = times2(v_14671, v_14670);
    env = stack[-5];
    stack[-2] = v_14670;
    goto v_14571;
v_14567:
    goto v_14577;
v_14573:
    fn = elt(env, 5); // next!-random!-number
    v_14670 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_14671 = Lfloat(nil, v_14670);
    env = stack[-5];
    goto v_14574;
v_14575:
    v_14670 = stack[-2];
    goto v_14576;
v_14577:
    goto v_14573;
v_14574:
    goto v_14575;
v_14576:
    stack[0] = plus2(v_14671, v_14670);
    env = stack[-5];
    goto v_14568;
v_14569:
    goto v_14586;
v_14582:
    v_14671 = qvalue(elt(env, 2)); // unidev_fac!*
    goto v_14583;
v_14584:
    v_14670 = stack[-3];
    goto v_14585;
v_14586:
    goto v_14582;
v_14583:
    goto v_14584;
v_14585:
    v_14670 = times2(v_14671, v_14670);
    goto v_14570;
v_14571:
    goto v_14567;
v_14568:
    goto v_14569;
v_14570:
    {
        LispObject v_14677 = stack[0];
        return times2(v_14677, v_14670);
    }
v_14554:
v_14593:
    fn = elt(env, 5); // next!-random!-number
    v_14670 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[-2] = v_14670;
    v_14670 = qvalue(elt(env, 3)); // randommodulus!*
    stack[-4] = v_14670;
v_14598:
    goto v_14608;
v_14604:
    v_14671 = stack[-4];
    goto v_14605;
v_14606:
    v_14670 = stack[-3];
    goto v_14607;
v_14608:
    goto v_14604;
v_14605:
    goto v_14606;
v_14607:
    v_14670 = (LispObject)lessp2(v_14671, v_14670);
    v_14670 = v_14670 ? lisp_true : nil;
    env = stack[-5];
    if (v_14670 == nil) goto v_14601;
    else goto v_14602;
v_14601:
    goto v_14597;
v_14602:
    goto v_14617;
v_14613:
    v_14671 = stack[-4];
    goto v_14614;
v_14615:
    v_14670 = qvalue(elt(env, 3)); // randommodulus!*
    goto v_14616;
v_14617:
    goto v_14613;
v_14614:
    goto v_14615;
v_14616:
    v_14670 = times2(v_14671, v_14670);
    env = stack[-5];
    stack[-4] = v_14670;
    goto v_14625;
v_14621:
    goto v_14631;
v_14627:
    v_14671 = qvalue(elt(env, 3)); // randommodulus!*
    goto v_14628;
v_14629:
    v_14670 = stack[-2];
    goto v_14630;
v_14631:
    goto v_14627;
v_14628:
    goto v_14629;
v_14630:
    stack[0] = times2(v_14671, v_14670);
    env = stack[-5];
    goto v_14622;
v_14623:
    fn = elt(env, 5); // next!-random!-number
    v_14670 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_14624;
v_14625:
    goto v_14621;
v_14622:
    goto v_14623;
v_14624:
    v_14670 = plus2(stack[0], v_14670);
    env = stack[-5];
    stack[-2] = v_14670;
    goto v_14598;
v_14597:
    goto v_14645;
v_14641:
    stack[-1] = stack[-2];
    goto v_14642;
v_14643:
    goto v_14652;
v_14648:
    stack[0] = stack[-4];
    goto v_14649;
v_14650:
    goto v_14659;
v_14655:
    v_14671 = stack[-4];
    goto v_14656;
v_14657:
    v_14670 = stack[-3];
    goto v_14658;
v_14659:
    goto v_14655;
v_14656:
    goto v_14657;
v_14658:
    v_14670 = Cremainder(v_14671, v_14670);
    env = stack[-5];
    goto v_14651;
v_14652:
    goto v_14648;
v_14649:
    goto v_14650;
v_14651:
    v_14670 = difference2(stack[0], v_14670);
    env = stack[-5];
    goto v_14644;
v_14645:
    goto v_14641;
v_14642:
    goto v_14643;
v_14644:
    v_14670 = (LispObject)lessp2(stack[-1], v_14670);
    v_14670 = v_14670 ? lisp_true : nil;
    env = stack[-5];
    if (v_14670 == nil) goto v_14638;
    else goto v_14639;
v_14638:
    goto v_14593;
v_14639:
    goto v_14667;
v_14663:
    v_14671 = stack[-2];
    goto v_14664;
v_14665:
    v_14670 = stack[-3];
    goto v_14666;
v_14667:
    goto v_14663;
v_14664:
    goto v_14665;
v_14666:
    return Cremainder(v_14671, v_14670);
    v_14670 = nil;
    return onevalue(v_14670);
}



// Code for red!=hidelt

static LispObject CC_redMhidelt(LispObject env,
                         LispObject v_14517)
{
    env = qenv(env);
    LispObject v_14546;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14517);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_14517;
// end of prologue
    v_14546 = stack[-2];
    fn = elt(env, 1); // bas_dpoly
    v_14546 = (*qfn1(fn))(fn, v_14546);
    env = stack[-4];
    stack[-3] = v_14546;
    goto v_14529;
v_14523:
    v_14546 = stack[-2];
    fn = elt(env, 2); // bas_nr
    stack[-1] = (*qfn1(fn))(fn, v_14546);
    env = stack[-4];
    goto v_14524;
v_14525:
    v_14546 = stack[-3];
    stack[0] = qcdr(v_14546);
    goto v_14526;
v_14527:
    goto v_14539;
v_14535:
    v_14546 = stack[-2];
    fn = elt(env, 3); // bas_rep
    stack[-2] = (*qfn1(fn))(fn, v_14546);
    env = stack[-4];
    goto v_14536;
v_14537:
    v_14546 = stack[-3];
    v_14546 = qcar(v_14546);
    v_14546 = ncons(v_14546);
    env = stack[-4];
    fn = elt(env, 4); // red!=hide
    v_14546 = (*qfn1(fn))(fn, v_14546);
    env = stack[-4];
    goto v_14538;
v_14539:
    goto v_14535;
v_14536:
    goto v_14537;
v_14538:
    fn = elt(env, 5); // dp_sum
    v_14546 = (*qfn2(fn))(fn, stack[-2], v_14546);
    env = stack[-4];
    goto v_14528;
v_14529:
    goto v_14523;
v_14524:
    goto v_14525;
v_14526:
    goto v_14527;
v_14528:
    {
        LispObject v_14551 = stack[-1];
        LispObject v_14552 = stack[0];
        fn = elt(env, 6); // bas_make1
        return (*qfnn(fn))(fn, 3, v_14551, v_14552, v_14546);
    }
}



// Code for repeats

static LispObject CC_repeats(LispObject env,
                         LispObject v_14517)
{
    env = qenv(env);
    LispObject v_14557, v_14558, v_14559;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14517);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_14517;
// end of prologue
    v_14559 = nil;
v_14522:
    v_14557 = stack[0];
    if (v_14557 == nil) goto v_14525;
    else goto v_14526;
v_14525:
    v_14557 = v_14559;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_14557);
    }
v_14526:
    goto v_14536;
v_14532:
    v_14557 = stack[0];
    v_14558 = qcar(v_14557);
    goto v_14533;
v_14534:
    v_14557 = stack[0];
    v_14557 = qcdr(v_14557);
    goto v_14535;
v_14536:
    goto v_14532;
v_14533:
    goto v_14534;
v_14535:
    v_14557 = Lmember(nil, v_14558, v_14557);
    if (v_14557 == nil) goto v_14531;
    goto v_14547;
v_14543:
    v_14557 = stack[0];
    v_14557 = qcar(v_14557);
    goto v_14544;
v_14545:
    v_14558 = v_14559;
    goto v_14546;
v_14547:
    goto v_14543;
v_14544:
    goto v_14545;
v_14546:
    v_14557 = cons(v_14557, v_14558);
    env = stack[-1];
    v_14559 = v_14557;
    v_14557 = stack[0];
    v_14557 = qcdr(v_14557);
    stack[0] = v_14557;
    goto v_14522;
v_14531:
    v_14557 = stack[0];
    v_14557 = qcdr(v_14557);
    stack[0] = v_14557;
    goto v_14522;
    v_14557 = nil;
    return onevalue(v_14557);
}



// Code for mod_eval_uni_poly

static LispObject CC_mod_eval_uni_poly(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14637, v_14638, v_14639;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_14518;
    stack[-2] = v_14517;
// end of prologue
    v_14637 = stack[-2];
    if (!consp(v_14637)) goto v_14522;
    else goto v_14523;
v_14522:
    v_14637 = stack[-2];
    {
        fn = elt(env, 2); // mod!#
        return (*qfn1(fn))(fn, v_14637);
    }
v_14523:
    v_14637 = stack[-2];
    v_14637 = qcar(v_14637);
    v_14637 = qcdr(v_14637);
    fn = elt(env, 2); // mod!#
    v_14637 = (*qfn1(fn))(fn, v_14637);
    env = stack[-4];
    v_14639 = v_14637;
    v_14637 = stack[-2];
    v_14637 = qcar(v_14637);
    v_14637 = qcar(v_14637);
    v_14637 = qcdr(v_14637);
    v_14638 = v_14637;
    v_14637 = stack[-2];
    v_14637 = qcdr(v_14637);
    stack[-2] = v_14637;
v_14545:
    v_14637 = stack[-2];
    if (!consp(v_14637)) goto v_14548;
    else goto v_14549;
v_14548:
    goto v_14544;
v_14549:
    goto v_14557;
v_14553:
    goto v_14563;
v_14559:
    goto v_14569;
v_14565:
    stack[-3] = v_14639;
    goto v_14566;
v_14567:
    goto v_14576;
v_14572:
    stack[0] = stack[-1];
    goto v_14573;
v_14574:
    goto v_14583;
v_14579:
    goto v_14580;
v_14581:
    v_14637 = stack[-2];
    v_14637 = qcar(v_14637);
    v_14637 = qcar(v_14637);
    v_14637 = qcdr(v_14637);
    goto v_14582;
v_14583:
    goto v_14579;
v_14580:
    goto v_14581;
v_14582:
    v_14637 = difference2(v_14638, v_14637);
    env = stack[-4];
    goto v_14575;
v_14576:
    goto v_14572;
v_14573:
    goto v_14574;
v_14575:
    fn = elt(env, 3); // general!-modular!-expt
    v_14637 = (*qfn2(fn))(fn, stack[0], v_14637);
    env = stack[-4];
    goto v_14568;
v_14569:
    goto v_14565;
v_14566:
    goto v_14567;
v_14568:
    v_14638 = times2(stack[-3], v_14637);
    env = stack[-4];
    goto v_14560;
v_14561:
    v_14637 = qvalue(elt(env, 1)); // current!-modulus
    goto v_14562;
v_14563:
    goto v_14559;
v_14560:
    goto v_14561;
v_14562:
    stack[0] = Cremainder(v_14638, v_14637);
    env = stack[-4];
    goto v_14554;
v_14555:
    v_14637 = stack[-2];
    v_14637 = qcar(v_14637);
    v_14637 = qcdr(v_14637);
    fn = elt(env, 2); // mod!#
    v_14637 = (*qfn1(fn))(fn, v_14637);
    env = stack[-4];
    goto v_14556;
v_14557:
    goto v_14553;
v_14554:
    goto v_14555;
v_14556:
    fn = elt(env, 4); // general!-modular!-plus
    v_14637 = (*qfn2(fn))(fn, stack[0], v_14637);
    env = stack[-4];
    v_14639 = v_14637;
    v_14637 = stack[-2];
    v_14637 = qcar(v_14637);
    v_14637 = qcar(v_14637);
    v_14637 = qcdr(v_14637);
    v_14638 = v_14637;
    v_14637 = stack[-2];
    v_14637 = qcdr(v_14637);
    stack[-2] = v_14637;
    goto v_14545;
v_14544:
    goto v_14605;
v_14601:
    goto v_14611;
v_14607:
    stack[0] = v_14639;
    goto v_14608;
v_14609:
    goto v_14618;
v_14614:
    v_14637 = stack[-1];
    goto v_14615;
v_14616:
    goto v_14617;
v_14618:
    goto v_14614;
v_14615:
    goto v_14616;
v_14617:
    fn = elt(env, 3); // general!-modular!-expt
    v_14637 = (*qfn2(fn))(fn, v_14637, v_14638);
    env = stack[-4];
    goto v_14610;
v_14611:
    goto v_14607;
v_14608:
    goto v_14609;
v_14610:
    v_14638 = times2(stack[0], v_14637);
    env = stack[-4];
    goto v_14602;
v_14603:
    v_14637 = qvalue(elt(env, 1)); // current!-modulus
    goto v_14604;
v_14605:
    goto v_14601;
v_14602:
    goto v_14603;
v_14604:
    v_14637 = Cremainder(v_14638, v_14637);
    env = stack[-4];
    v_14639 = v_14637;
    v_14637 = stack[-2];
    if (v_14637 == nil) goto v_14625;
    goto v_14632;
v_14628:
    stack[0] = v_14639;
    goto v_14629;
v_14630:
    v_14637 = stack[-2];
    fn = elt(env, 2); // mod!#
    v_14637 = (*qfn1(fn))(fn, v_14637);
    env = stack[-4];
    goto v_14631;
v_14632:
    goto v_14628;
v_14629:
    goto v_14630;
v_14631:
    fn = elt(env, 4); // general!-modular!-plus
    v_14637 = (*qfn2(fn))(fn, stack[0], v_14637);
    v_14639 = v_14637;
    goto v_14623;
v_14625:
v_14623:
    v_14637 = v_14639;
    goto v_14521;
    v_14637 = nil;
v_14521:
    return onevalue(v_14637);
}



// Code for outrefend

static LispObject CC_outrefend(LispObject env,
                         LispObject v_14517)
{
    env = qenv(env);
    LispObject v_14819, v_14820, v_14821;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14517);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_14517;
// end of prologue
    v_14819 = qvalue(elt(env, 1)); // calls!*
    v_14820 = v_14819;
    v_14819 = v_14820;
    if (v_14819 == nil) goto v_14524;
    goto v_14533;
v_14527:
    stack[-1] = stack[-2];
    goto v_14528;
v_14529:
    stack[0] = elt(env, 2); // calls
    goto v_14530;
v_14531:
    v_14819 = qvalue(elt(env, 3)); // toplv!*
    if (v_14819 == nil) goto v_14539;
    goto v_14546;
v_14542:
    v_14821 = v_14820;
    goto v_14543;
v_14544:
    goto v_14553;
v_14549:
    v_14820 = stack[-2];
    goto v_14550;
v_14551:
    v_14819 = elt(env, 2); // calls
    goto v_14552;
v_14553:
    goto v_14549;
v_14550:
    goto v_14551;
v_14552:
    v_14819 = get(v_14820, v_14819);
    env = stack[-4];
    goto v_14545;
v_14546:
    goto v_14542;
v_14543:
    goto v_14544;
v_14545:
    fn = elt(env, 20); // union
    v_14819 = (*qfn2(fn))(fn, v_14821, v_14819);
    env = stack[-4];
    goto v_14537;
v_14539:
    v_14819 = v_14820;
    goto v_14537;
    v_14819 = nil;
v_14537:
    goto v_14532;
v_14533:
    goto v_14527;
v_14528:
    goto v_14529;
v_14530:
    goto v_14531;
v_14532:
    v_14819 = Lputprop(nil, 3, stack[-1], stack[0], v_14819);
    env = stack[-4];
    goto v_14522;
v_14524:
v_14522:
    v_14819 = qvalue(elt(env, 1)); // calls!*
    stack[-1] = v_14819;
v_14562:
    v_14819 = stack[-1];
    if (v_14819 == nil) goto v_14566;
    else goto v_14567;
v_14566:
    goto v_14561;
v_14567:
    v_14819 = stack[-1];
    v_14819 = qcar(v_14819);
    stack[0] = v_14819;
    goto v_14578;
v_14574:
    v_14819 = stack[0];
    v_14820 = ncons(v_14819);
    env = stack[-4];
    goto v_14575;
v_14576:
    v_14819 = elt(env, 4); // cinthis
    goto v_14577;
v_14578:
    goto v_14574;
v_14575:
    goto v_14576;
v_14577:
    v_14819 = Lremflag(nil, v_14820, v_14819);
    env = stack[-4];
    goto v_14590;
v_14586:
    v_14820 = stack[0];
    goto v_14587;
v_14588:
    v_14819 = stack[-2];
    goto v_14589;
v_14590:
    goto v_14586;
v_14587:
    goto v_14588;
v_14589:
    if (v_14820 == v_14819) goto v_14585;
    goto v_14602;
v_14598:
    v_14820 = stack[0];
    goto v_14599;
v_14600:
    v_14819 = elt(env, 5); // seen
    goto v_14601;
v_14602:
    goto v_14598;
v_14599:
    goto v_14600;
v_14601:
    v_14819 = Lflagp(nil, v_14820, v_14819);
    env = stack[-4];
    if (v_14819 == nil) goto v_14595;
    else goto v_14596;
v_14595:
    goto v_14610;
v_14606:
    v_14819 = stack[0];
    v_14820 = ncons(v_14819);
    env = stack[-4];
    goto v_14607;
v_14608:
    v_14819 = elt(env, 5); // seen
    goto v_14609;
v_14610:
    goto v_14606;
v_14607:
    goto v_14608;
v_14609:
    v_14819 = Lflag(nil, v_14820, v_14819);
    env = stack[-4];
    goto v_14619;
v_14615:
    v_14820 = stack[0];
    goto v_14616;
v_14617:
    v_14819 = qvalue(elt(env, 6)); // seen!*
    goto v_14618;
v_14619:
    goto v_14615;
v_14616:
    goto v_14617;
v_14618:
    v_14819 = cons(v_14820, v_14819);
    env = stack[-4];
    qvalue(elt(env, 6)) = v_14819; // seen!*
    goto v_14594;
v_14596:
v_14594:
    goto v_14629;
v_14623:
    v_14821 = stack[0];
    goto v_14624;
v_14625:
    v_14820 = elt(env, 7); // calledby
    goto v_14626;
v_14627:
    v_14819 = stack[-2];
    goto v_14628;
v_14629:
    goto v_14623;
v_14624:
    goto v_14625;
v_14626:
    goto v_14627;
v_14628:
    fn = elt(env, 21); // traput
    v_14819 = (*qfnn(fn))(fn, 3, v_14821, v_14820, v_14819);
    env = stack[-4];
    goto v_14583;
v_14585:
v_14583:
    v_14819 = stack[-1];
    v_14819 = qcdr(v_14819);
    stack[-1] = v_14819;
    goto v_14562;
v_14561:
    v_14819 = qvalue(elt(env, 8)); // globs!*
    v_14820 = v_14819;
    v_14819 = v_14820;
    if (v_14819 == nil) goto v_14640;
    goto v_14649;
v_14643:
    stack[-1] = stack[-2];
    goto v_14644;
v_14645:
    stack[0] = elt(env, 9); // globs
    goto v_14646;
v_14647:
    v_14819 = qvalue(elt(env, 3)); // toplv!*
    if (v_14819 == nil) goto v_14655;
    goto v_14662;
v_14658:
    v_14821 = v_14820;
    goto v_14659;
v_14660:
    goto v_14669;
v_14665:
    v_14820 = stack[-2];
    goto v_14666;
v_14667:
    v_14819 = elt(env, 9); // globs
    goto v_14668;
v_14669:
    goto v_14665;
v_14666:
    goto v_14667;
v_14668:
    v_14819 = get(v_14820, v_14819);
    env = stack[-4];
    goto v_14661;
v_14662:
    goto v_14658;
v_14659:
    goto v_14660;
v_14661:
    fn = elt(env, 20); // union
    v_14819 = (*qfn2(fn))(fn, v_14821, v_14819);
    env = stack[-4];
    goto v_14653;
v_14655:
    v_14819 = v_14820;
    goto v_14653;
    v_14819 = nil;
v_14653:
    goto v_14648;
v_14649:
    goto v_14643;
v_14644:
    goto v_14645;
v_14646:
    goto v_14647;
v_14648:
    v_14819 = Lputprop(nil, 3, stack[-1], stack[0], v_14819);
    env = stack[-4];
    goto v_14638;
v_14640:
v_14638:
    v_14819 = qvalue(elt(env, 8)); // globs!*
    stack[-3] = v_14819;
v_14678:
    v_14819 = stack[-3];
    if (v_14819 == nil) goto v_14682;
    else goto v_14683;
v_14682:
    v_14819 = nil;
    goto v_14677;
v_14683:
    v_14819 = stack[-3];
    v_14819 = qcar(v_14819);
    stack[-1] = v_14819;
    goto v_14696;
v_14690:
    stack[0] = stack[-1];
    goto v_14691;
v_14692:
    goto v_14707;
v_14703:
    v_14820 = stack[-1];
    goto v_14704;
v_14705:
    v_14819 = elt(env, 10); // dclglb
    goto v_14706;
v_14707:
    goto v_14703;
v_14704:
    goto v_14705;
v_14706:
    v_14819 = Lflagp(nil, v_14820, v_14819);
    env = stack[-4];
    if (v_14819 == nil) goto v_14701;
    v_14819 = elt(env, 11); // usedby
    v_14820 = v_14819;
    goto v_14699;
v_14701:
    goto v_14722;
v_14718:
    v_14820 = stack[-1];
    goto v_14719;
v_14720:
    v_14819 = elt(env, 12); // gseen
    goto v_14721;
v_14722:
    goto v_14718;
v_14719:
    goto v_14720;
v_14721:
    v_14819 = Lflagp(nil, v_14820, v_14819);
    env = stack[-4];
    if (v_14819 == nil) goto v_14715;
    else goto v_14716;
v_14715:
    goto v_14730;
v_14726:
    v_14820 = stack[-1];
    goto v_14727;
v_14728:
    v_14819 = qvalue(elt(env, 13)); // gseen!*
    goto v_14729;
v_14730:
    goto v_14726;
v_14727:
    goto v_14728;
v_14729:
    v_14819 = cons(v_14820, v_14819);
    env = stack[-4];
    qvalue(elt(env, 13)) = v_14819; // gseen!*
    goto v_14738;
v_14734:
    v_14819 = stack[-1];
    v_14820 = ncons(v_14819);
    env = stack[-4];
    goto v_14735;
v_14736:
    v_14819 = elt(env, 12); // gseen
    goto v_14737;
v_14738:
    goto v_14734;
v_14735:
    goto v_14736;
v_14737:
    v_14819 = Lflag(nil, v_14820, v_14819);
    env = stack[-4];
    goto v_14714;
v_14716:
v_14714:
    v_14819 = elt(env, 14); // usedunby
    v_14820 = v_14819;
    goto v_14699;
    v_14820 = nil;
v_14699:
    goto v_14693;
v_14694:
    v_14819 = stack[-2];
    goto v_14695;
v_14696:
    goto v_14690;
v_14691:
    goto v_14692;
v_14693:
    goto v_14694;
v_14695:
    fn = elt(env, 21); // traput
    v_14819 = (*qfnn(fn))(fn, 3, stack[0], v_14820, v_14819);
    env = stack[-4];
    goto v_14749;
v_14745:
    v_14819 = stack[-1];
    v_14820 = ncons(v_14819);
    env = stack[-4];
    goto v_14746;
v_14747:
    v_14819 = elt(env, 15); // glb2rf
    goto v_14748;
v_14749:
    goto v_14745;
v_14746:
    goto v_14747;
v_14748:
    v_14819 = Lremflag(nil, v_14820, v_14819);
    env = stack[-4];
    goto v_14762;
v_14758:
    v_14820 = stack[-1];
    goto v_14759;
v_14760:
    v_14819 = elt(env, 16); // glb2bd
    goto v_14761;
v_14762:
    goto v_14758;
v_14759:
    goto v_14760;
v_14761:
    v_14819 = Lflagp(nil, v_14820, v_14819);
    env = stack[-4];
    if (v_14819 == nil) goto v_14756;
    goto v_14770;
v_14766:
    v_14819 = stack[-1];
    v_14820 = ncons(v_14819);
    env = stack[-4];
    goto v_14767;
v_14768:
    v_14819 = elt(env, 16); // glb2bd
    goto v_14769;
v_14770:
    goto v_14766;
v_14767:
    goto v_14768;
v_14769:
    v_14819 = Lremflag(nil, v_14820, v_14819);
    env = stack[-4];
    goto v_14781;
v_14775:
    v_14821 = stack[-1];
    goto v_14776;
v_14777:
    v_14820 = elt(env, 17); // boundby
    goto v_14778;
v_14779:
    v_14819 = stack[-2];
    goto v_14780;
v_14781:
    goto v_14775;
v_14776:
    goto v_14777;
v_14778:
    goto v_14779;
v_14780:
    fn = elt(env, 21); // traput
    v_14819 = (*qfnn(fn))(fn, 3, v_14821, v_14820, v_14819);
    env = stack[-4];
    goto v_14754;
v_14756:
v_14754:
    goto v_14794;
v_14790:
    v_14820 = stack[-1];
    goto v_14791;
v_14792:
    v_14819 = elt(env, 18); // glb2st
    goto v_14793;
v_14794:
    goto v_14790;
v_14791:
    goto v_14792;
v_14793:
    v_14819 = Lflagp(nil, v_14820, v_14819);
    env = stack[-4];
    if (v_14819 == nil) goto v_14788;
    goto v_14802;
v_14798:
    v_14819 = stack[-1];
    v_14820 = ncons(v_14819);
    env = stack[-4];
    goto v_14799;
v_14800:
    v_14819 = elt(env, 18); // glb2st
    goto v_14801;
v_14802:
    goto v_14798;
v_14799:
    goto v_14800;
v_14801:
    v_14819 = Lremflag(nil, v_14820, v_14819);
    env = stack[-4];
    goto v_14813;
v_14807:
    v_14821 = stack[-1];
    goto v_14808;
v_14809:
    v_14820 = elt(env, 19); // setby
    goto v_14810;
v_14811:
    v_14819 = stack[-2];
    goto v_14812;
v_14813:
    goto v_14807;
v_14808:
    goto v_14809;
v_14810:
    goto v_14811;
v_14812:
    fn = elt(env, 21); // traput
    v_14819 = (*qfnn(fn))(fn, 3, v_14821, v_14820, v_14819);
    env = stack[-4];
    goto v_14786;
v_14788:
v_14786:
    v_14819 = stack[-3];
    v_14819 = qcdr(v_14819);
    stack[-3] = v_14819;
    goto v_14678;
v_14677:
    return onevalue(v_14819);
}



// Code for simpcv

static LispObject CC_simpcv(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14593, v_14594;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_14518;
    stack[-1] = v_14517;
// end of prologue
    goto v_14528;
v_14524:
    v_14593 = stack[-1];
    v_14594 = Llength(nil, v_14593);
    env = stack[-2];
    goto v_14525;
v_14526:
    v_14593 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_14527;
v_14528:
    goto v_14524;
v_14525:
    goto v_14526;
v_14527:
    if (v_14594 == v_14593) goto v_14523;
    goto v_14538;
v_14534:
    v_14594 = elt(env, 1); // "Invalid number of edges in vertex"
    goto v_14535;
v_14536:
    v_14593 = stack[-1];
    goto v_14537;
v_14538:
    goto v_14534;
v_14535:
    goto v_14536;
v_14537:
    v_14593 = list2(v_14594, v_14593);
    env = stack[-2];
    {
        fn = elt(env, 4); // cerror
        return (*qfn1(fn))(fn, v_14593);
    }
v_14523:
    goto v_14551;
v_14547:
    v_14594 = elt(env, 2); // simpcgraph
    goto v_14548;
v_14549:
    v_14593 = qvalue(elt(env, 3)); // mul!*
    goto v_14550;
v_14551:
    goto v_14547;
v_14548:
    goto v_14549;
v_14550:
    v_14593 = Lmemq(nil, v_14594, v_14593);
    if (v_14593 == nil) goto v_14545;
    else goto v_14546;
v_14545:
    goto v_14560;
v_14556:
    v_14594 = qvalue(elt(env, 3)); // mul!*
    goto v_14557;
v_14558:
    v_14593 = elt(env, 2); // simpcgraph
    goto v_14559;
v_14560:
    goto v_14556;
v_14557:
    goto v_14558;
v_14559:
    fn = elt(env, 5); // aconc!*
    v_14593 = (*qfn2(fn))(fn, v_14594, v_14593);
    env = stack[-2];
    qvalue(elt(env, 3)) = v_14593; // mul!*
    goto v_14544;
v_14546:
v_14544:
    goto v_14568;
v_14564:
    goto v_14575;
v_14571:
    goto v_14581;
v_14577:
    goto v_14587;
v_14583:
    v_14594 = stack[0];
    goto v_14584;
v_14585:
    v_14593 = stack[-1];
    goto v_14586;
v_14587:
    goto v_14583;
v_14584:
    goto v_14585;
v_14586:
    v_14594 = cons(v_14594, v_14593);
    env = stack[-2];
    goto v_14578;
v_14579:
    v_14593 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14580;
v_14581:
    goto v_14577;
v_14578:
    goto v_14579;
v_14580:
    fn = elt(env, 6); // to
    v_14594 = (*qfn2(fn))(fn, v_14594, v_14593);
    env = stack[-2];
    goto v_14572;
v_14573:
    v_14593 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14574;
v_14575:
    goto v_14571;
v_14572:
    goto v_14573;
v_14574:
    v_14593 = cons(v_14594, v_14593);
    env = stack[-2];
    v_14594 = ncons(v_14593);
    goto v_14565;
v_14566:
    v_14593 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14567;
v_14568:
    goto v_14564;
v_14565:
    goto v_14566;
v_14567:
    return cons(v_14594, v_14593);
    v_14593 = nil;
    return onevalue(v_14593);
}



// Code for talp_subat

static LispObject CC_talp_subat(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14548;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_14518;
    stack[-2] = v_14517;
// end of prologue
    goto v_14527;
v_14521:
    v_14548 = stack[-1];
    fn = elt(env, 1); // talp_op
    stack[-3] = (*qfn1(fn))(fn, v_14548);
    env = stack[-4];
    goto v_14522;
v_14523:
    goto v_14535;
v_14531:
    stack[0] = stack[-2];
    goto v_14532;
v_14533:
    v_14548 = stack[-1];
    fn = elt(env, 2); // talp_arg2l
    v_14548 = (*qfn1(fn))(fn, v_14548);
    env = stack[-4];
    goto v_14534;
v_14535:
    goto v_14531;
v_14532:
    goto v_14533;
v_14534:
    fn = elt(env, 3); // talp_subt
    stack[0] = (*qfn2(fn))(fn, stack[0], v_14548);
    env = stack[-4];
    goto v_14524;
v_14525:
    goto v_14544;
v_14540:
    goto v_14541;
v_14542:
    v_14548 = stack[-1];
    fn = elt(env, 4); // talp_arg2r
    v_14548 = (*qfn1(fn))(fn, v_14548);
    env = stack[-4];
    goto v_14543;
v_14544:
    goto v_14540;
v_14541:
    goto v_14542;
v_14543:
    fn = elt(env, 3); // talp_subt
    v_14548 = (*qfn2(fn))(fn, stack[-2], v_14548);
    env = stack[-4];
    goto v_14526;
v_14527:
    goto v_14521;
v_14522:
    goto v_14523;
v_14524:
    goto v_14525;
v_14526:
    {
        LispObject v_14553 = stack[-3];
        LispObject v_14554 = stack[0];
        fn = elt(env, 5); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_14553, v_14554, v_14548);
    }
}



// Code for matrixrowom

static LispObject CC_matrixrowom(LispObject env,
                         LispObject v_14517)
{
    env = qenv(env);
    LispObject v_14543;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14517);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_14517;
// end of prologue
    v_14543 = stack[0];
    if (v_14543 == nil) goto v_14524;
    v_14543 = elt(env, 1); // "<OMA>"
    fn = elt(env, 4); // printout
    v_14543 = (*qfn1(fn))(fn, v_14543);
    env = stack[-1];
    v_14543 = lisp_true;
    fn = elt(env, 5); // indent!*
    v_14543 = (*qfn1(fn))(fn, v_14543);
    env = stack[-1];
    v_14543 = elt(env, 2); // "<OMS cd=""linalg1"" name=""matrixrow""/>"
    fn = elt(env, 4); // printout
    v_14543 = (*qfn1(fn))(fn, v_14543);
    env = stack[-1];
    v_14543 = stack[0];
    v_14543 = qcar(v_14543);
    fn = elt(env, 6); // multiom
    v_14543 = (*qfn1(fn))(fn, v_14543);
    env = stack[-1];
    v_14543 = nil;
    fn = elt(env, 5); // indent!*
    v_14543 = (*qfn1(fn))(fn, v_14543);
    env = stack[-1];
    v_14543 = elt(env, 3); // "</OMA>"
    fn = elt(env, 4); // printout
    v_14543 = (*qfn1(fn))(fn, v_14543);
    env = stack[-1];
    v_14543 = stack[0];
    v_14543 = qcdr(v_14543);
    v_14543 = CC_matrixrowom(elt(env, 0), v_14543);
    goto v_14522;
v_14524:
v_14522:
    v_14543 = nil;
    return onevalue(v_14543);
}



// Code for vdpequal

static LispObject CC_vdpequal(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14587, v_14588, v_14589;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_14518;
    stack[-1] = v_14517;
// end of prologue
    goto v_14528;
v_14524:
    v_14588 = stack[-1];
    goto v_14525;
v_14526:
    v_14587 = stack[0];
    goto v_14527;
v_14528:
    goto v_14524;
v_14525:
    goto v_14526;
v_14527:
    if (v_14588 == v_14587) goto v_14522;
    else goto v_14523;
v_14522:
    v_14587 = lisp_true;
    goto v_14521;
v_14523:
    goto v_14539;
v_14535:
    v_14588 = stack[-1];
    goto v_14536;
v_14537:
    v_14587 = elt(env, 1); // number
    goto v_14538;
v_14539:
    goto v_14535;
v_14536:
    goto v_14537;
v_14538:
    fn = elt(env, 2); // vdpgetprop
    stack[-2] = (*qfn2(fn))(fn, v_14588, v_14587);
    env = stack[-3];
    goto v_14547;
v_14543:
    v_14588 = stack[0];
    goto v_14544;
v_14545:
    v_14587 = elt(env, 1); // number
    goto v_14546;
v_14547:
    goto v_14543;
v_14544:
    goto v_14545;
v_14546:
    fn = elt(env, 2); // vdpgetprop
    v_14587 = (*qfn2(fn))(fn, v_14588, v_14587);
    env = stack[-3];
    v_14589 = stack[-2];
    v_14588 = v_14587;
    v_14587 = v_14589;
    if (v_14587 == nil) goto v_14557;
    else goto v_14558;
v_14557:
    v_14587 = nil;
    goto v_14556;
v_14558:
    goto v_14567;
v_14563:
    v_14587 = v_14589;
    goto v_14564;
v_14565:
    goto v_14566;
v_14567:
    goto v_14563;
v_14564:
    goto v_14565;
v_14566:
    v_14587 = (equal(v_14587, v_14588) ? lisp_true : nil);
    goto v_14556;
    v_14587 = nil;
v_14556:
    if (v_14587 == nil) goto v_14554;
    else goto v_14553;
v_14554:
    goto v_14576;
v_14572:
    v_14587 = stack[-1];
    v_14587 = qcdr(v_14587);
    v_14587 = qcdr(v_14587);
    v_14587 = qcdr(v_14587);
    v_14588 = qcar(v_14587);
    goto v_14573;
v_14574:
    v_14587 = stack[0];
    v_14587 = qcdr(v_14587);
    v_14587 = qcdr(v_14587);
    v_14587 = qcdr(v_14587);
    v_14587 = qcar(v_14587);
    goto v_14575;
v_14576:
    goto v_14572;
v_14573:
    goto v_14574;
v_14575:
    {
        fn = elt(env, 3); // dipequal
        return (*qfn2(fn))(fn, v_14588, v_14587);
    }
v_14553:
    goto v_14521;
    v_14587 = nil;
v_14521:
    return onevalue(v_14587);
}



// Code for freeoff

static LispObject CC_freeoff(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14622, v_14623;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_14518;
    stack[-1] = v_14517;
// end of prologue
v_14522:
    v_14622 = stack[-1];
    if (!consp(v_14622)) goto v_14529;
    else goto v_14530;
v_14529:
    v_14622 = lisp_true;
    goto v_14528;
v_14530:
    v_14622 = stack[-1];
    v_14622 = qcar(v_14622);
    v_14622 = (consp(v_14622) ? nil : lisp_true);
    goto v_14528;
    v_14622 = nil;
v_14528:
    if (v_14622 == nil) goto v_14526;
    v_14622 = lisp_true;
    goto v_14521;
v_14526:
    v_14622 = stack[-1];
    v_14622 = qcar(v_14622);
    v_14622 = qcar(v_14622);
    v_14622 = qcar(v_14622);
    fn = elt(env, 1); // sfp
    v_14622 = (*qfn1(fn))(fn, v_14622);
    env = stack[-2];
    if (v_14622 == nil) goto v_14540;
    goto v_14555;
v_14551:
    v_14622 = stack[-1];
    v_14622 = qcar(v_14622);
    v_14622 = qcar(v_14622);
    v_14623 = qcar(v_14622);
    goto v_14552;
v_14553:
    v_14622 = stack[0];
    goto v_14554;
v_14555:
    goto v_14551;
v_14552:
    goto v_14553;
v_14554:
    v_14622 = CC_freeoff(elt(env, 0), v_14623, v_14622);
    env = stack[-2];
    if (v_14622 == nil) goto v_14549;
    goto v_14570;
v_14566:
    v_14622 = stack[-1];
    v_14622 = qcar(v_14622);
    v_14623 = qcdr(v_14622);
    goto v_14567;
v_14568:
    v_14622 = stack[0];
    goto v_14569;
v_14570:
    goto v_14566;
v_14567:
    goto v_14568;
v_14569:
    v_14622 = CC_freeoff(elt(env, 0), v_14623, v_14622);
    env = stack[-2];
    if (v_14622 == nil) goto v_14564;
    v_14622 = stack[-1];
    v_14622 = qcdr(v_14622);
    stack[-1] = v_14622;
    goto v_14522;
v_14564:
    v_14622 = nil;
    goto v_14521;
    goto v_14547;
v_14549:
    v_14622 = nil;
    goto v_14521;
v_14547:
    goto v_14524;
v_14540:
    goto v_14594;
v_14590:
    v_14622 = stack[-1];
    v_14622 = qcar(v_14622);
    v_14622 = qcar(v_14622);
    v_14623 = qcar(v_14622);
    goto v_14591;
v_14592:
    v_14622 = stack[0];
    goto v_14593;
v_14594:
    goto v_14590;
v_14591:
    goto v_14592;
v_14593:
    fn = elt(env, 2); // ndepends
    v_14622 = (*qfn2(fn))(fn, v_14623, v_14622);
    env = stack[-2];
    if (v_14622 == nil) goto v_14587;
    else goto v_14588;
v_14587:
    goto v_14609;
v_14605:
    v_14622 = stack[-1];
    v_14622 = qcar(v_14622);
    v_14623 = qcdr(v_14622);
    goto v_14606;
v_14607:
    v_14622 = stack[0];
    goto v_14608;
v_14609:
    goto v_14605;
v_14606:
    goto v_14607;
v_14608:
    v_14622 = CC_freeoff(elt(env, 0), v_14623, v_14622);
    env = stack[-2];
    if (v_14622 == nil) goto v_14603;
    v_14622 = stack[-1];
    v_14622 = qcdr(v_14622);
    stack[-1] = v_14622;
    goto v_14522;
v_14603:
    v_14622 = nil;
    goto v_14521;
    goto v_14586;
v_14588:
    v_14622 = nil;
    goto v_14521;
v_14586:
    goto v_14524;
v_14524:
    v_14622 = nil;
v_14521:
    return onevalue(v_14622);
}



// Code for oprinla

static LispObject CC_oprinla(LispObject env,
                         LispObject v_14517)
{
    env = qenv(env);
    LispObject v_14560, v_14561, v_14562;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14517);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_14561 = v_14517;
// end of prologue
    goto v_14531;
v_14527:
    v_14562 = v_14561;
    goto v_14528;
v_14529:
    v_14560 = elt(env, 1); // lapr
    goto v_14530;
v_14531:
    goto v_14527;
v_14528:
    goto v_14529;
v_14530:
    v_14560 = get(v_14562, v_14560);
    env = stack[0];
    v_14562 = v_14560;
    if (v_14560 == nil) goto v_14525;
    v_14560 = v_14562;
    fn = elt(env, 4); // prin2la
    v_14560 = (*qfn1(fn))(fn, v_14560);
    goto v_14523;
v_14525:
    v_14560 = v_14561;
    if (!symbolp(v_14560)) v_14560 = nil;
    else { v_14560 = qfastgets(v_14560);
           if (v_14560 != nil) { v_14560 = elt(v_14560, 37); // prtch
#ifdef RECORD_GET
             if (v_14560 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v_14560 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v_14560 == SPID_NOPROP) v_14560 = nil; }}
#endif
    v_14562 = v_14560;
    if (v_14560 == nil) goto v_14537;
    v_14560 = v_14562;
    fn = elt(env, 4); // prin2la
    v_14560 = (*qfn1(fn))(fn, v_14560);
    goto v_14523;
v_14537:
    goto v_14549;
v_14545:
    v_14562 = v_14561;
    goto v_14546;
v_14547:
    v_14560 = elt(env, 2); // lapop
    goto v_14548;
v_14549:
    goto v_14545;
v_14546:
    goto v_14547;
v_14548:
    v_14560 = get(v_14562, v_14560);
    env = stack[0];
    v_14562 = v_14560;
    if (v_14560 == nil) goto v_14543;
    v_14560 = v_14562;
    fn = elt(env, 4); // prin2la
    v_14560 = (*qfn1(fn))(fn, v_14560);
    env = stack[0];
    v_14560 = elt(env, 3); // ! 
    fn = elt(env, 4); // prin2la
    v_14560 = (*qfn1(fn))(fn, v_14560);
    goto v_14523;
v_14543:
    v_14560 = v_14561;
    fn = elt(env, 5); // prinlatom
    v_14560 = (*qfn1(fn))(fn, v_14560);
    goto v_14523;
v_14523:
    v_14560 = nil;
    return onevalue(v_14560);
}



// Code for physopordchk!*

static LispObject CC_physopordchkH(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14665, v_14666;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_14518;
    stack[-1] = v_14517;
// end of prologue
v_14516:
    v_14665 = stack[-1];
    v_14665 = qcar(v_14665);
    stack[-4] = v_14665;
    v_14665 = stack[-1];
    v_14665 = qcdr(v_14665);
    stack[-1] = v_14665;
    v_14665 = stack[-1];
    if (v_14665 == nil) goto v_14531;
    else goto v_14532;
v_14531:
    v_14665 = stack[0];
    v_14665 = qcdr(v_14665);
    if (v_14665 == nil) goto v_14536;
    else goto v_14537;
v_14536:
    goto v_14549;
v_14545:
    v_14666 = stack[-4];
    goto v_14546;
v_14547:
    v_14665 = stack[0];
    v_14665 = qcar(v_14665);
    goto v_14548;
v_14549:
    goto v_14545;
v_14546:
    goto v_14547;
v_14548:
    fn = elt(env, 1); // ncmpchk
    v_14665 = (*qfn2(fn))(fn, v_14666, v_14665);
    env = stack[-5];
    if (v_14665 == nil) goto v_14542;
    else goto v_14543;
v_14542:
    v_14665 = nil;
    goto v_14541;
v_14543:
    goto v_14560;
v_14556:
    v_14665 = stack[-4];
    fn = elt(env, 2); // invp
    v_14666 = (*qfn1(fn))(fn, v_14665);
    goto v_14557;
v_14558:
    v_14665 = stack[0];
    v_14665 = qcar(v_14665);
    goto v_14559;
v_14560:
    goto v_14556;
v_14557:
    goto v_14558;
v_14559:
    v_14665 = (equal(v_14666, v_14665) ? lisp_true : nil);
    v_14665 = (v_14665 == nil ? lisp_true : nil);
    goto v_14541;
    v_14665 = nil;
v_14541:
    goto v_14524;
v_14537:
    v_14665 = stack[0];
    stack[-3] = v_14665;
    v_14665 = stack[-3];
    if (v_14665 == nil) goto v_14578;
    else goto v_14579;
v_14578:
    v_14665 = nil;
    goto v_14573;
v_14579:
    v_14665 = stack[-3];
    v_14665 = qcar(v_14665);
    goto v_14591;
v_14587:
    v_14666 = stack[-4];
    goto v_14588;
v_14589:
    goto v_14590;
v_14591:
    goto v_14587;
v_14588:
    goto v_14589;
v_14590:
    fn = elt(env, 1); // ncmpchk
    v_14665 = (*qfn2(fn))(fn, v_14666, v_14665);
    env = stack[-5];
    v_14665 = ncons(v_14665);
    env = stack[-5];
    stack[-1] = v_14665;
    stack[-2] = v_14665;
v_14574:
    v_14665 = stack[-3];
    v_14665 = qcdr(v_14665);
    stack[-3] = v_14665;
    v_14665 = stack[-3];
    if (v_14665 == nil) goto v_14598;
    else goto v_14599;
v_14598:
    v_14665 = stack[-2];
    goto v_14573;
v_14599:
    goto v_14607;
v_14603:
    stack[0] = stack[-1];
    goto v_14604;
v_14605:
    v_14665 = stack[-3];
    v_14665 = qcar(v_14665);
    goto v_14618;
v_14614:
    v_14666 = stack[-4];
    goto v_14615;
v_14616:
    goto v_14617;
v_14618:
    goto v_14614;
v_14615:
    goto v_14616;
v_14617:
    fn = elt(env, 1); // ncmpchk
    v_14665 = (*qfn2(fn))(fn, v_14666, v_14665);
    env = stack[-5];
    v_14665 = ncons(v_14665);
    env = stack[-5];
    goto v_14606;
v_14607:
    goto v_14603;
v_14604:
    goto v_14605;
v_14606:
    v_14665 = Lrplacd(nil, stack[0], v_14665);
    env = stack[-5];
    v_14665 = stack[-1];
    v_14665 = qcdr(v_14665);
    stack[-1] = v_14665;
    goto v_14574;
v_14573:
    goto v_14631;
v_14627:
    v_14666 = nil;
    goto v_14628;
v_14629:
    goto v_14630;
v_14631:
    goto v_14627;
v_14628:
    goto v_14629;
v_14630:
    v_14665 = Lmember(nil, v_14666, v_14665);
    if (v_14665 == nil) goto v_14626;
    v_14665 = nil;
    goto v_14524;
v_14626:
    v_14665 = lisp_true;
    goto v_14524;
    goto v_14535;
v_14535:
    goto v_14530;
v_14532:
    goto v_14650;
v_14646:
    v_14665 = stack[-4];
    v_14666 = ncons(v_14665);
    env = stack[-5];
    goto v_14647;
v_14648:
    v_14665 = stack[0];
    goto v_14649;
v_14650:
    goto v_14646;
v_14647:
    goto v_14648;
v_14649:
    v_14665 = CC_physopordchkH(elt(env, 0), v_14666, v_14665);
    env = stack[-5];
    if (v_14665 == nil) goto v_14643;
    else goto v_14644;
v_14643:
    v_14665 = nil;
    goto v_14642;
v_14644:
    goto v_14662;
v_14658:
    v_14666 = stack[-1];
    goto v_14659;
v_14660:
    v_14665 = stack[0];
    goto v_14661;
v_14662:
    goto v_14658;
v_14659:
    goto v_14660;
v_14661:
    stack[-1] = v_14666;
    stack[0] = v_14665;
    goto v_14516;
    v_14665 = nil;
v_14642:
    goto v_14524;
v_14530:
    v_14665 = nil;
v_14524:
    return onevalue(v_14665);
}



// Code for fieldconv

static LispObject CC_fieldconv(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14752, v_14753, v_14754;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_14518;
    stack[-2] = v_14517;
// end of prologue
    v_14752 = stack[-1];
    v_14752 = qcar(v_14752);
    stack[-3] = v_14752;
    v_14752 = stack[-1];
    v_14752 = qcdr(v_14752);
    stack[0] = v_14752;
    v_14752 = qvalue(elt(env, 1)); // dmode!*
    if (v_14752 == nil) goto v_14531;
    else goto v_14532;
v_14531:
    goto v_14543;
v_14539:
    v_14753 = stack[-2];
    goto v_14540;
v_14541:
    v_14752 = elt(env, 2); // !:rn!:
    goto v_14542;
v_14543:
    goto v_14539;
v_14540:
    goto v_14541;
v_14542:
    if (!consp(v_14753)) goto v_14536;
    v_14753 = qcar(v_14753);
    if (v_14753 == v_14752) goto v_14537;
v_14536:
    goto v_14556;
v_14552:
    v_14752 = stack[-2];
    v_14753 = qcar(v_14752);
    goto v_14553;
v_14554:
    v_14752 = elt(env, 2); // !:rn!:
    goto v_14555;
v_14556:
    goto v_14552;
v_14553:
    goto v_14554;
v_14555:
    v_14752 = get(v_14753, v_14752);
    env = stack[-4];
    v_14753 = v_14752;
    if (v_14752 == nil) goto v_14549;
    v_14752 = v_14753;
    if (!consp(v_14752)) goto v_14560;
    else goto v_14549;
v_14560:
    goto v_14567;
v_14563:
    goto v_14564;
v_14565:
    v_14752 = stack[-2];
    goto v_14566;
v_14567:
    goto v_14563;
v_14564:
    goto v_14565;
v_14566:
    v_14752 = Lapply1(nil, v_14753, v_14752);
    env = stack[-4];
    stack[-2] = v_14752;
    goto v_14547;
v_14549:
    goto v_14577;
v_14573:
    v_14752 = stack[-2];
    v_14753 = qcar(v_14752);
    goto v_14574;
v_14575:
    v_14752 = elt(env, 3); // quotient
    goto v_14576;
v_14577:
    goto v_14573;
v_14574:
    goto v_14575;
v_14576:
    v_14752 = get(v_14753, v_14752);
    env = stack[-4];
    if (v_14752 == nil) goto v_14571;
    goto v_14588;
v_14582:
    v_14754 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14583;
v_14584:
    v_14753 = stack[-2];
    goto v_14585;
v_14586:
    v_14752 = elt(env, 3); // quotient
    goto v_14587;
v_14588:
    goto v_14582;
v_14583:
    goto v_14584;
v_14585:
    goto v_14586;
v_14587:
    fn = elt(env, 5); // dcombine
    v_14752 = (*qfnn(fn))(fn, 3, v_14754, v_14753, v_14752);
    env = stack[-4];
    stack[-2] = v_14752;
    goto v_14597;
v_14593:
    goto v_14603;
v_14599:
    v_14753 = stack[-2];
    goto v_14600;
v_14601:
    v_14752 = stack[-1];
    v_14752 = qcar(v_14752);
    goto v_14602;
v_14603:
    goto v_14599;
v_14600:
    goto v_14601;
v_14602:
    fn = elt(env, 6); // multd
    stack[0] = (*qfn2(fn))(fn, v_14753, v_14752);
    env = stack[-4];
    goto v_14594;
v_14595:
    goto v_14612;
v_14608:
    v_14753 = stack[-2];
    goto v_14609;
v_14610:
    v_14752 = stack[-1];
    v_14752 = qcdr(v_14752);
    goto v_14611;
v_14612:
    goto v_14608;
v_14609:
    goto v_14610;
v_14611:
    fn = elt(env, 6); // multd
    v_14752 = (*qfn2(fn))(fn, v_14753, v_14752);
    goto v_14596;
v_14597:
    goto v_14593;
v_14594:
    goto v_14595;
v_14596:
    {
        LispObject v_14759 = stack[0];
        return cons(v_14759, v_14752);
    }
v_14571:
    goto v_14624;
v_14620:
    v_14753 = elt(env, 4); // "field conversion"
    goto v_14621;
v_14622:
    v_14752 = stack[-2];
    goto v_14623;
v_14624:
    goto v_14620;
v_14621:
    goto v_14622;
v_14623:
    v_14752 = list2(v_14753, v_14752);
    env = stack[-4];
    fn = elt(env, 7); // errach
    v_14752 = (*qfn1(fn))(fn, v_14752);
    env = stack[-4];
    goto v_14547;
v_14547:
    goto v_14535;
v_14537:
v_14535:
    goto v_14634;
v_14628:
    v_14752 = stack[-2];
    v_14754 = qcar(v_14752);
    goto v_14629;
v_14630:
    v_14752 = stack[-2];
    v_14752 = qcdr(v_14752);
    v_14753 = qcdr(v_14752);
    goto v_14631;
v_14632:
    v_14752 = stack[-2];
    v_14752 = qcdr(v_14752);
    v_14752 = qcar(v_14752);
    goto v_14633;
v_14634:
    goto v_14628;
v_14629:
    goto v_14630;
v_14631:
    goto v_14632;
v_14633:
    v_14752 = list2star(v_14754, v_14753, v_14752);
    env = stack[-4];
    stack[-2] = v_14752;
    v_14752 = stack[0];
    if (!consp(v_14752)) goto v_14650;
    else goto v_14651;
v_14650:
    v_14752 = lisp_true;
    goto v_14649;
v_14651:
    v_14752 = stack[0];
    v_14752 = qcar(v_14752);
    v_14752 = (consp(v_14752) ? nil : lisp_true);
    goto v_14649;
    v_14752 = nil;
v_14649:
    if (v_14752 == nil) goto v_14647;
    goto v_14664;
v_14660:
    goto v_14670;
v_14666:
    v_14753 = stack[-2];
    goto v_14667;
v_14668:
    v_14752 = stack[-3];
    goto v_14669;
v_14670:
    goto v_14666;
v_14667:
    goto v_14668;
v_14669:
    fn = elt(env, 6); // multd
    v_14753 = (*qfn2(fn))(fn, v_14753, v_14752);
    env = stack[-4];
    goto v_14661;
v_14662:
    v_14752 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14663;
v_14664:
    goto v_14660;
v_14661:
    goto v_14662;
v_14663:
    v_14752 = cons(v_14753, v_14752);
    env = stack[-4];
    goto v_14645;
v_14647:
    goto v_14681;
v_14677:
    goto v_14687;
v_14683:
    v_14753 = stack[-2];
    goto v_14684;
v_14685:
    v_14752 = stack[-3];
    goto v_14686;
v_14687:
    goto v_14683;
v_14684:
    goto v_14685;
v_14686:
    fn = elt(env, 6); // multd
    stack[-1] = (*qfn2(fn))(fn, v_14753, v_14752);
    env = stack[-4];
    goto v_14678;
v_14679:
    goto v_14695;
v_14691:
    v_14753 = stack[-2];
    goto v_14692;
v_14693:
    v_14752 = stack[0];
    goto v_14694;
v_14695:
    goto v_14691;
v_14692:
    goto v_14693;
v_14694:
    fn = elt(env, 6); // multd
    v_14752 = (*qfn2(fn))(fn, v_14753, v_14752);
    env = stack[-4];
    goto v_14680;
v_14681:
    goto v_14677;
v_14678:
    goto v_14679;
v_14680:
    v_14752 = cons(stack[-1], v_14752);
    env = stack[-4];
    goto v_14645;
    v_14752 = nil;
v_14645:
    {
        fn = elt(env, 8); // simpgd
        return (*qfn1(fn))(fn, v_14752);
    }
v_14532:
    v_14752 = stack[0];
    if (!consp(v_14752)) goto v_14704;
    else goto v_14705;
v_14704:
    v_14752 = lisp_true;
    goto v_14703;
v_14705:
    v_14752 = stack[0];
    v_14752 = qcar(v_14752);
    v_14752 = (consp(v_14752) ? nil : lisp_true);
    goto v_14703;
    v_14752 = nil;
v_14703:
    if (v_14752 == nil) goto v_14701;
    goto v_14718;
v_14714:
    goto v_14724;
v_14720:
    v_14753 = stack[-3];
    goto v_14721;
v_14722:
    v_14752 = stack[0];
    goto v_14723;
v_14724:
    goto v_14720;
v_14721:
    goto v_14722;
v_14723:
    fn = elt(env, 9); // divd
    v_14753 = (*qfn2(fn))(fn, v_14753, v_14752);
    goto v_14715;
v_14716:
    v_14752 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14717;
v_14718:
    goto v_14714;
v_14715:
    goto v_14716;
v_14717:
    return cons(v_14753, v_14752);
v_14701:
    goto v_14735;
v_14731:
    goto v_14741;
v_14737:
    v_14753 = stack[-3];
    goto v_14738;
v_14739:
    v_14752 = stack[-2];
    goto v_14740;
v_14741:
    goto v_14737;
v_14738:
    goto v_14739;
v_14740:
    fn = elt(env, 9); // divd
    stack[-1] = (*qfn2(fn))(fn, v_14753, v_14752);
    env = stack[-4];
    goto v_14732;
v_14733:
    goto v_14749;
v_14745:
    v_14753 = stack[0];
    goto v_14746;
v_14747:
    v_14752 = stack[-2];
    goto v_14748;
v_14749:
    goto v_14745;
v_14746:
    goto v_14747;
v_14748:
    fn = elt(env, 9); // divd
    v_14752 = (*qfn2(fn))(fn, v_14753, v_14752);
    goto v_14734;
v_14735:
    goto v_14731;
v_14732:
    goto v_14733;
v_14734:
    {
        LispObject v_14760 = stack[-1];
        return cons(v_14760, v_14752);
    }
    v_14752 = nil;
    return onevalue(v_14752);
}



// Code for reduce!-mod!-p!*

static LispObject CC_reduceKmodKpH(LispObject env,
                         LispObject v_14517, LispObject v_14518)
{
    env = qenv(env);
    LispObject v_14524, v_14525;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14518,v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14517,v_14518);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_14524 = v_14518;
    v_14525 = v_14517;
// end of prologue
// Binding current!-modulus
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_14524; // current!-modulus
    v_14524 = v_14525;
    fn = elt(env, 2); // general!-reduce!-mod!-p
    v_14524 = (*qfn1(fn))(fn, v_14524);
    ;}  // end of a binding scope
    return onevalue(v_14524);
}



// Code for gf2cr!:

static LispObject CC_gf2crT(LispObject env,
                         LispObject v_14517)
{
    env = qenv(env);
    LispObject v_14534;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14517);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_14517;
// end of prologue
    goto v_14526;
v_14520:
    stack[-2] = elt(env, 1); // !:cr!:
    goto v_14521;
v_14522:
    v_14534 = stack[-1];
    v_14534 = qcar(v_14534);
    fn = elt(env, 2); // striptag
    stack[0] = (*qfn1(fn))(fn, v_14534);
    env = stack[-3];
    goto v_14523;
v_14524:
    v_14534 = stack[-1];
    v_14534 = qcdr(v_14534);
    fn = elt(env, 2); // striptag
    v_14534 = (*qfn1(fn))(fn, v_14534);
    goto v_14525;
v_14526:
    goto v_14520;
v_14521:
    goto v_14522;
v_14523:
    goto v_14524;
v_14525:
    {
        LispObject v_14538 = stack[-2];
        LispObject v_14539 = stack[0];
        return list2star(v_14538, v_14539, v_14534);
    }
}



// Code for string!-of!-list

static LispObject CC_stringKofKlist(LispObject env,
                         LispObject v_14517)
{
    env = qenv(env);
    LispObject v_14593, v_14594;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14517);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14517);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_14594 = v_14517;
// end of prologue
    v_14593 = v_14594;
    if (v_14593 == nil) goto v_14521;
    else goto v_14522;
v_14521:
    v_14593 = elt(env, 1); // ""
    goto v_14520;
v_14522:
    v_14593 = v_14594;
    stack[-4] = v_14593;
v_14533:
    v_14593 = stack[-4];
    if (v_14593 == nil) goto v_14538;
    else goto v_14539;
v_14538:
    v_14593 = nil;
    goto v_14532;
v_14539:
    v_14593 = stack[-4];
    v_14593 = qcar(v_14593);
    goto v_14550;
v_14546:
    stack[0] = elt(env, 2); // !;
    goto v_14547;
v_14548:
    v_14593 = Lexplode(nil, v_14593);
    env = stack[-5];
    goto v_14549;
v_14550:
    goto v_14546;
v_14547:
    goto v_14548;
v_14549:
    v_14593 = cons(stack[0], v_14593);
    env = stack[-5];
    stack[-3] = v_14593;
    v_14593 = stack[-3];
    fn = elt(env, 3); // lastpair
    v_14593 = (*qfn1(fn))(fn, v_14593);
    env = stack[-5];
    stack[-2] = v_14593;
    v_14593 = stack[-4];
    v_14593 = qcdr(v_14593);
    stack[-4] = v_14593;
    v_14593 = stack[-2];
    if (!consp(v_14593)) goto v_14560;
    else goto v_14561;
v_14560:
    goto v_14533;
v_14561:
v_14534:
    v_14593 = stack[-4];
    if (v_14593 == nil) goto v_14565;
    else goto v_14566;
v_14565:
    v_14593 = stack[-3];
    goto v_14532;
v_14566:
    goto v_14574;
v_14570:
    stack[-1] = stack[-2];
    goto v_14571;
v_14572:
    v_14593 = stack[-4];
    v_14593 = qcar(v_14593);
    goto v_14584;
v_14580:
    stack[0] = elt(env, 2); // !;
    goto v_14581;
v_14582:
    v_14593 = Lexplode(nil, v_14593);
    env = stack[-5];
    goto v_14583;
v_14584:
    goto v_14580;
v_14581:
    goto v_14582;
v_14583:
    v_14593 = cons(stack[0], v_14593);
    env = stack[-5];
    goto v_14573;
v_14574:
    goto v_14570;
v_14571:
    goto v_14572;
v_14573:
    v_14593 = Lrplacd(nil, stack[-1], v_14593);
    env = stack[-5];
    v_14593 = stack[-2];
    fn = elt(env, 3); // lastpair
    v_14593 = (*qfn1(fn))(fn, v_14593);
    env = stack[-5];
    stack[-2] = v_14593;
    v_14593 = stack[-4];
    v_14593 = qcdr(v_14593);
    stack[-4] = v_14593;
    goto v_14534;
v_14532:
    v_14593 = qcdr(v_14593);
    {
        fn = elt(env, 4); // list2string
        return (*qfn1(fn))(fn, v_14593);
    }
    v_14593 = nil;
v_14520:
    return onevalue(v_14593);
}



setup_type const u26_setup[] =
{
    {"cl_susiupdknowl1",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_susiupdknowl1},
    {"vdp_setsugar",            TOO_FEW_2,      CC_vdp_setsugar,WRONG_NO_2},
    {"quotof",                  TOO_FEW_2,      CC_quotof,     WRONG_NO_2},
    {"ordop2",                  TOO_FEW_2,      CC_ordop2,     WRONG_NO_2},
    {"factorial",               CC_factorial,   TOO_MANY_1,    WRONG_NO_1},
    {"assert_install1",         CC_assert_install1,TOO_MANY_1, WRONG_NO_1},
    {"mo_zero",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mo_zero},
    {"nonlnrsys",               TOO_FEW_2,      CC_nonlnrsys,  WRONG_NO_2},
    {"dmconv0",                 CC_dmconv0,     TOO_MANY_1,    WRONG_NO_1},
    {"let3",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_let3},
    {"ra_zerop",                CC_ra_zerop,    TOO_MANY_1,    WRONG_NO_1},
    {"lalr_make_arglist",       CC_lalr_make_arglist,TOO_MANY_1,WRONG_NO_1},
    {"rl_bettergaussp",         TOO_FEW_2,      CC_rl_bettergaussp,WRONG_NO_2},
    {"monomcomparedeglex",      TOO_FEW_2,      CC_monomcomparedeglex,WRONG_NO_2},
    {"talp_list2vec",           CC_talp_list2vec,TOO_MANY_1,   WRONG_NO_1},
    {"cl_susiinter",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_susiinter},
    {"ofsf_sippsubst",          TOO_FEW_2,      CC_ofsf_sippsubst,WRONG_NO_2},
    {"band_matrix",             TOO_FEW_2,      CC_band_matrix,WRONG_NO_2},
    {"vdpvevlcomp",             TOO_FEW_2,      CC_vdpvevlcomp,WRONG_NO_2},
    {"gftimesn",                TOO_FEW_2,      CC_gftimesn,   WRONG_NO_2},
    {"rd:plus",                 TOO_FEW_2,      CC_rdTplus,    WRONG_NO_2},
    {"getphystypecar",          CC_getphystypecar,TOO_MANY_1,  WRONG_NO_1},
    {"groeb=newpair",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_groebMnewpair},
    {"subs3t",                  TOO_FEW_2,      CC_subs3t,     WRONG_NO_2},
    {"charnump:",               CC_charnumpT,   TOO_MANY_1,    WRONG_NO_1},
    {"trailing.coefft",         TOO_FEW_2,      CC_trailingQcoefft,WRONG_NO_2},
    {"extmult",                 TOO_FEW_2,      CC_extmult,    WRONG_NO_2},
    {"ofsf_at2ir",              TOO_FEW_2,      CC_ofsf_at2ir, WRONG_NO_2},
    {"smemberlp",               TOO_FEW_2,      CC_smemberlp,  WRONG_NO_2},
    {"offexpchk",               CC_offexpchk,   TOO_MANY_1,    WRONG_NO_1},
    {"lambdafun",               CC_lambdafun,   TOO_MANY_1,    WRONG_NO_1},
    {"setdmode",                TOO_FEW_2,      CC_setdmode,   WRONG_NO_2},
    {"random",                  CC_random,      TOO_MANY_1,    WRONG_NO_1},
    {"red=hidelt",              CC_redMhidelt,  TOO_MANY_1,    WRONG_NO_1},
    {"repeats",                 CC_repeats,     TOO_MANY_1,    WRONG_NO_1},
    {"mod_eval_uni_poly",       TOO_FEW_2,      CC_mod_eval_uni_poly,WRONG_NO_2},
    {"outrefend",               CC_outrefend,   TOO_MANY_1,    WRONG_NO_1},
    {"simpcv",                  TOO_FEW_2,      CC_simpcv,     WRONG_NO_2},
    {"talp_subat",              TOO_FEW_2,      CC_talp_subat, WRONG_NO_2},
    {"matrixrowom",             CC_matrixrowom, TOO_MANY_1,    WRONG_NO_1},
    {"vdpequal",                TOO_FEW_2,      CC_vdpequal,   WRONG_NO_2},
    {"freeoff",                 TOO_FEW_2,      CC_freeoff,    WRONG_NO_2},
    {"oprinla",                 CC_oprinla,     TOO_MANY_1,    WRONG_NO_1},
    {"physopordchk*",           TOO_FEW_2,      CC_physopordchkH,WRONG_NO_2},
    {"fieldconv",               TOO_FEW_2,      CC_fieldconv,  WRONG_NO_2},
    {"reduce-mod-p*",           TOO_FEW_2,      CC_reduceKmodKpH,WRONG_NO_2},
    {"gf2cr:",                  CC_gf2crT,      TOO_MANY_1,    WRONG_NO_1},
    {"string-of-list",          CC_stringKofKlist,TOO_MANY_1,  WRONG_NO_1},
    {NULL, (one_args *)"u26", (two_args *)"85903 9001890 3591880", 0}
};

// end of generated code
