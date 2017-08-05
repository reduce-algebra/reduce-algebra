
// $destdir/u21.c        Machine generated C code

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



// Code for mkprod

static LispObject CC_mkprod(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_12206, v_12207;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11934);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_11934;
// end of prologue
// Binding !*exp
// FLUIDBIND: reloadenv=6 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-6, 1, -2);
    qvalue(elt(env, 1)) = nil; // !*exp
// Binding !*sub2
// FLUIDBIND: reloadenv=6 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-6, 2, -1);
    qvalue(elt(env, 2)) = nil; // !*sub2
    v_12206 = stack[-4];
    if (v_12206 == nil) goto v_11950;
    else goto v_11951;
v_11950:
    v_12206 = lisp_true;
    goto v_11949;
v_11951:
    v_12206 = stack[-4];
    fn = elt(env, 8); // kernlp
    v_12206 = (*qfn1(fn))(fn, v_12206);
    env = stack[-6];
    goto v_11949;
    v_12206 = nil;
v_11949:
    if (v_12206 == nil) goto v_11947;
    v_12206 = stack[-4];
    goto v_11943;
v_11947:
    v_12206 = lisp_true;
    qvalue(elt(env, 2)) = v_12206; // !*sub2
    goto v_11966;
v_11962:
    v_12207 = stack[-4];
    goto v_11963;
v_11964:
    v_12206 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11965;
v_11966:
    goto v_11962;
v_11963:
    goto v_11964;
v_11965:
    v_12206 = cons(v_12207, v_12206);
    env = stack[-6];
    fn = elt(env, 9); // subs2
    v_12206 = (*qfn1(fn))(fn, v_12206);
    env = stack[-6];
    stack[0] = v_12206;
    goto v_11977;
v_11973:
    v_12206 = stack[0];
    v_12207 = qcdr(v_12206);
    goto v_11974;
v_11975:
    v_12206 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11976;
v_11977:
    goto v_11973;
v_11974:
    goto v_11975;
v_11976:
    if (v_12207 == v_12206) goto v_11972;
    v_12206 = stack[-4];
    goto v_11943;
v_11972:
    goto v_11988;
v_11984:
    v_12206 = stack[0];
    v_12207 = qcar(v_12206);
    goto v_11985;
v_11986:
    v_12206 = stack[-4];
    goto v_11987;
v_11988:
    goto v_11984;
v_11985:
    goto v_11986;
v_11987:
    if (equal(v_12207, v_12206)) goto v_11983;
    v_12206 = stack[0];
    v_12206 = qcar(v_12206);
    stack[-4] = v_12206;
    v_12206 = stack[-4];
    if (v_12206 == nil) goto v_12000;
    else goto v_12001;
v_12000:
    v_12206 = lisp_true;
    goto v_11999;
v_12001:
    v_12206 = stack[-4];
    fn = elt(env, 8); // kernlp
    v_12206 = (*qfn1(fn))(fn, v_12206);
    env = stack[-6];
    goto v_11999;
    v_12206 = nil;
v_11999:
    if (v_12206 == nil) goto v_11997;
    v_12206 = stack[-4];
    goto v_11943;
v_11997:
    goto v_11970;
v_11983:
v_11970:
    v_12206 = lisp_true;
    qvalue(elt(env, 1)) = v_12206; // !*exp
    v_12206 = stack[-4];
    fn = elt(env, 10); // ckrn
    v_12206 = (*qfn1(fn))(fn, v_12206);
    env = stack[-6];
    stack[-5] = v_12206;
    goto v_12017;
v_12013:
    v_12207 = stack[-4];
    goto v_12014;
v_12015:
    v_12206 = stack[-5];
    goto v_12016;
v_12017:
    goto v_12013;
v_12014:
    goto v_12015;
v_12016:
    fn = elt(env, 11); // quotf
    v_12206 = (*qfn2(fn))(fn, v_12207, v_12206);
    env = stack[-6];
    stack[-4] = v_12206;
    v_12206 = stack[-4];
    fn = elt(env, 12); // expnd
    v_12206 = (*qfn1(fn))(fn, v_12206);
    env = stack[-6];
    stack[0] = v_12206;
    v_12206 = stack[0];
    if (v_12206 == nil) goto v_12028;
    else goto v_12029;
v_12028:
    v_12206 = lisp_true;
    goto v_12027;
v_12029:
    v_12206 = stack[0];
    fn = elt(env, 8); // kernlp
    v_12206 = (*qfn1(fn))(fn, v_12206);
    env = stack[-6];
    goto v_12027;
    v_12206 = nil;
v_12027:
    if (v_12206 == nil) goto v_12025;
    goto v_12041;
v_12037:
    v_12207 = stack[-5];
    goto v_12038;
v_12039:
    v_12206 = stack[0];
    goto v_12040;
v_12041:
    goto v_12037;
v_12038:
    goto v_12039;
v_12040:
    fn = elt(env, 13); // multf
    v_12206 = (*qfn2(fn))(fn, v_12207, v_12206);
    goto v_11943;
v_12025:
    v_12206 = qvalue(elt(env, 3)); // !*mcd
    if (v_12206 == nil) goto v_12047;
    v_12206 = qvalue(elt(env, 4)); // !*sqfree
    if (v_12206 == nil) goto v_12051;
    else goto v_12050;
v_12051:
    v_12206 = qvalue(elt(env, 5)); // !*factor
    if (v_12206 == nil) goto v_12054;
    else goto v_12050;
v_12054:
    v_12206 = qvalue(elt(env, 6)); // !*gcd
    if (v_12206 == nil) goto v_12056;
    else goto v_12050;
v_12056:
    goto v_12047;
v_12050:
    v_12206 = stack[0];
    fn = elt(env, 14); // fctrf
    v_12206 = (*qfn1(fn))(fn, v_12206);
    env = stack[-6];
    stack[-3] = v_12206;
    goto v_12045;
v_12047:
    v_12206 = stack[0];
    fn = elt(env, 10); // ckrn
    v_12206 = (*qfn1(fn))(fn, v_12206);
    env = stack[-6];
    stack[-3] = v_12206;
    goto v_12069;
v_12065:
    v_12207 = stack[0];
    goto v_12066;
v_12067:
    v_12206 = stack[-3];
    goto v_12068;
v_12069:
    goto v_12065;
v_12066:
    goto v_12067;
v_12068:
    fn = elt(env, 11); // quotf
    v_12206 = (*qfn2(fn))(fn, v_12207, v_12206);
    env = stack[-6];
    stack[0] = v_12206;
    goto v_12077;
v_12073:
    goto v_12074;
v_12075:
    goto v_12084;
v_12080:
    v_12207 = stack[0];
    goto v_12081;
v_12082:
    v_12206 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12083;
v_12084:
    goto v_12080;
v_12081:
    goto v_12082;
v_12083:
    v_12206 = cons(v_12207, v_12206);
    env = stack[-6];
    goto v_12076;
v_12077:
    goto v_12073;
v_12074:
    goto v_12075;
v_12076:
    v_12206 = list2(stack[-3], v_12206);
    env = stack[-6];
    stack[-3] = v_12206;
    goto v_12045;
v_12045:
    goto v_12097;
v_12093:
    v_12206 = stack[-3];
    v_12206 = qcdr(v_12206);
    v_12206 = qcar(v_12206);
    v_12207 = qcdr(v_12206);
    goto v_12094;
v_12095:
    v_12206 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12096;
v_12097:
    goto v_12093;
v_12094:
    goto v_12095;
v_12096:
    v_12206 = (LispObject)greaterp2(v_12207, v_12206);
    v_12206 = v_12206 ? lisp_true : nil;
    env = stack[-6];
    if (v_12206 == nil) goto v_12091;
    else goto v_12089;
v_12091:
    v_12206 = stack[-3];
    v_12206 = qcdr(v_12206);
    v_12206 = qcdr(v_12206);
    if (v_12206 == nil) goto v_12103;
    else goto v_12089;
v_12103:
    goto v_12090;
v_12089:
    v_12206 = stack[-3];
    v_12206 = qcar(v_12206);
    stack[0] = v_12206;
    v_12206 = stack[-3];
    v_12206 = qcdr(v_12206);
    stack[-3] = v_12206;
v_12112:
    v_12206 = stack[-3];
    if (v_12206 == nil) goto v_12117;
    else goto v_12118;
v_12117:
    goto v_12111;
v_12118:
    v_12206 = stack[-3];
    v_12206 = qcar(v_12206);
    goto v_12129;
v_12125:
    goto v_12135;
v_12131:
    v_12207 = v_12206;
    v_12207 = qcar(v_12207);
    goto v_12132;
v_12133:
    v_12206 = qcdr(v_12206);
    goto v_12134;
v_12135:
    goto v_12131;
v_12132:
    goto v_12133;
v_12134:
    fn = elt(env, 15); // mksp!*
    v_12207 = (*qfn2(fn))(fn, v_12207, v_12206);
    env = stack[-6];
    goto v_12126;
v_12127:
    v_12206 = stack[0];
    goto v_12128;
v_12129:
    goto v_12125;
v_12126:
    goto v_12127;
v_12128:
    fn = elt(env, 13); // multf
    v_12206 = (*qfn2(fn))(fn, v_12207, v_12206);
    env = stack[-6];
    stack[0] = v_12206;
    v_12206 = stack[-3];
    v_12206 = qcdr(v_12206);
    stack[-3] = v_12206;
    goto v_12112;
v_12111:
    goto v_12088;
v_12090:
    v_12206 = qvalue(elt(env, 7)); // !*group
    if (v_12206 == nil) goto v_12147;
    else goto v_12148;
v_12147:
    goto v_12155;
v_12151:
    v_12206 = stack[-4];
    fn = elt(env, 16); // tmsf
    stack[0] = (*qfn1(fn))(fn, v_12206);
    env = stack[-6];
    goto v_12152;
v_12153:
    v_12206 = stack[-3];
    v_12206 = qcdr(v_12206);
    v_12206 = qcar(v_12206);
    v_12206 = qcar(v_12206);
    fn = elt(env, 16); // tmsf
    v_12206 = (*qfn1(fn))(fn, v_12206);
    env = stack[-6];
    goto v_12154;
v_12155:
    goto v_12151;
v_12152:
    goto v_12153;
v_12154:
    v_12206 = (LispObject)greaterp2(stack[0], v_12206);
    v_12206 = v_12206 ? lisp_true : nil;
    env = stack[-6];
    goto v_12146;
v_12148:
    v_12206 = nil;
    goto v_12146;
    v_12206 = nil;
v_12146:
    if (v_12206 == nil) goto v_12144;
    goto v_12171;
v_12167:
    goto v_12177;
v_12173:
    v_12206 = stack[-3];
    v_12206 = qcdr(v_12206);
    v_12206 = qcar(v_12206);
    v_12207 = qcar(v_12206);
    goto v_12174;
v_12175:
    v_12206 = stack[-3];
    v_12206 = qcdr(v_12206);
    v_12206 = qcar(v_12206);
    v_12206 = qcdr(v_12206);
    goto v_12176;
v_12177:
    goto v_12173;
v_12174:
    goto v_12175;
v_12176:
    fn = elt(env, 15); // mksp!*
    v_12207 = (*qfn2(fn))(fn, v_12207, v_12206);
    env = stack[-6];
    goto v_12168;
v_12169:
    v_12206 = stack[-3];
    v_12206 = qcar(v_12206);
    goto v_12170;
v_12171:
    goto v_12167;
v_12168:
    goto v_12169;
v_12170:
    fn = elt(env, 13); // multf
    v_12206 = (*qfn2(fn))(fn, v_12207, v_12206);
    env = stack[-6];
    stack[0] = v_12206;
    goto v_12088;
v_12144:
    goto v_12195;
v_12191:
    v_12207 = stack[-4];
    goto v_12192;
v_12193:
    v_12206 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12194;
v_12195:
    goto v_12191;
v_12192:
    goto v_12193;
v_12194:
    fn = elt(env, 15); // mksp!*
    v_12206 = (*qfn2(fn))(fn, v_12207, v_12206);
    env = stack[-6];
    stack[0] = v_12206;
    goto v_12088;
v_12088:
    goto v_12203;
v_12199:
    v_12207 = stack[-5];
    goto v_12200;
v_12201:
    v_12206 = stack[0];
    goto v_12202;
v_12203:
    goto v_12199;
v_12200:
    goto v_12201;
v_12202:
    fn = elt(env, 13); // multf
    v_12206 = (*qfn2(fn))(fn, v_12207, v_12206);
v_11943:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_12206);
}



// Code for cl_simpl1

static LispObject CC_cl_simpl1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12661, v_12662, v_12663, v_12664;
    LispObject fn;
    LispObject v_11937, v_11936, v_11935, v_11934;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_simpl1");
    va_start(aa, nargs);
    v_11934 = va_arg(aa, LispObject);
    v_11935 = va_arg(aa, LispObject);
    v_11936 = va_arg(aa, LispObject);
    v_11937 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_11937,v_11936,v_11935,v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_11934,v_11935,v_11936,v_11937);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_11937;
    stack[-1] = v_11936;
    stack[-2] = v_11935;
    stack[-3] = v_11934;
// end of prologue
    goto v_11954;
v_11950:
    v_12662 = stack[-1];
    goto v_11951;
v_11952:
    v_12661 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11953;
v_11954:
    goto v_11950;
v_11951:
    goto v_11952;
v_11953:
    v_12661 = Leqn(nil, v_12662, v_12661);
    env = stack[-5];
    if (v_12661 == nil) goto v_11948;
    v_12661 = stack[-3];
    goto v_11944;
v_11948:
    v_12661 = stack[-3];
    if (!consp(v_12661)) goto v_11960;
    else goto v_11961;
v_11960:
    v_12661 = stack[-3];
    goto v_11959;
v_11961:
    v_12661 = stack[-3];
    v_12661 = qcar(v_12661);
    goto v_11959;
    v_12661 = nil;
v_11959:
    stack[-4] = v_12661;
    goto v_11980;
v_11976:
    v_12662 = stack[-4];
    goto v_11977;
v_11978:
    v_12661 = elt(env, 1); // true
    goto v_11979;
v_11980:
    goto v_11976;
v_11977:
    goto v_11978;
v_11979:
    if (v_12662 == v_12661) goto v_11974;
    else goto v_11975;
v_11974:
    v_12661 = lisp_true;
    goto v_11973;
v_11975:
    goto v_11990;
v_11986:
    v_12662 = stack[-4];
    goto v_11987;
v_11988:
    v_12661 = elt(env, 2); // false
    goto v_11989;
v_11990:
    goto v_11986;
v_11987:
    goto v_11988;
v_11989:
    v_12661 = (v_12662 == v_12661 ? lisp_true : nil);
    goto v_11973;
    v_12661 = nil;
v_11973:
    if (v_12661 == nil) goto v_11971;
    v_12661 = stack[-3];
    goto v_11944;
v_11971:
    goto v_12007;
v_12003:
    v_12662 = stack[-4];
    goto v_12004;
v_12005:
    v_12661 = elt(env, 3); // or
    goto v_12006;
v_12007:
    goto v_12003;
v_12004:
    goto v_12005;
v_12006:
    if (v_12662 == v_12661) goto v_12001;
    else goto v_12002;
v_12001:
    v_12661 = lisp_true;
    goto v_12000;
v_12002:
    goto v_12017;
v_12013:
    v_12662 = stack[-4];
    goto v_12014;
v_12015:
    v_12661 = elt(env, 4); // and
    goto v_12016;
v_12017:
    goto v_12013;
v_12014:
    goto v_12015;
v_12016:
    v_12661 = (v_12662 == v_12661 ? lisp_true : nil);
    goto v_12000;
    v_12661 = nil;
v_12000:
    if (v_12661 == nil) goto v_11998;
    goto v_12030;
v_12022:
    v_12664 = stack[-4];
    goto v_12023;
v_12024:
    v_12661 = stack[-3];
    v_12663 = qcdr(v_12661);
    goto v_12025;
v_12026:
    v_12662 = stack[-2];
    goto v_12027;
v_12028:
    v_12661 = stack[-1];
    goto v_12029;
v_12030:
    goto v_12022;
v_12023:
    goto v_12024;
v_12025:
    goto v_12026;
v_12027:
    goto v_12028;
v_12029:
    fn = elt(env, 16); // cl_smsimpl!-junct
    v_12661 = (*qfnn(fn))(fn, 4, v_12664, v_12663, v_12662, v_12661);
    env = stack[-5];
    v_12662 = v_12661;
    v_12661 = v_12662;
    if (v_12661 == nil) goto v_12040;
    v_12661 = v_12662;
    v_12661 = qcdr(v_12661);
    if (v_12661 == nil) goto v_12040;
    goto v_12051;
v_12047:
    v_12661 = stack[-4];
    goto v_12048;
v_12049:
    goto v_12050;
v_12051:
    goto v_12047;
v_12048:
    goto v_12049;
v_12050:
    return cons(v_12661, v_12662);
v_12040:
    v_12661 = v_12662;
    if (v_12661 == nil) goto v_12054;
    else goto v_12055;
v_12054:
    goto v_12065;
v_12061:
    v_12662 = stack[-4];
    goto v_12062;
v_12063:
    v_12661 = elt(env, 4); // and
    goto v_12064;
v_12065:
    goto v_12061;
v_12062:
    goto v_12063;
v_12064:
    if (v_12662 == v_12661) goto v_12059;
    else goto v_12060;
v_12059:
    v_12661 = elt(env, 1); // true
    goto v_12058;
v_12060:
    v_12661 = elt(env, 2); // false
    goto v_12058;
    v_12661 = nil;
v_12058:
    goto v_12038;
v_12055:
    v_12661 = v_12662;
    v_12661 = qcar(v_12661);
    goto v_12038;
    v_12661 = nil;
v_12038:
    goto v_11944;
v_11998:
    goto v_12084;
v_12080:
    v_12662 = stack[-4];
    goto v_12081;
v_12082:
    v_12661 = elt(env, 5); // not
    goto v_12083;
v_12084:
    goto v_12080;
v_12081:
    goto v_12082;
v_12083:
    if (v_12662 == v_12661) goto v_12078;
    else goto v_12079;
v_12078:
    goto v_12096;
v_12088:
    v_12661 = stack[-3];
    v_12661 = qcdr(v_12661);
    stack[0] = qcar(v_12661);
    goto v_12089;
v_12090:
    goto v_12091;
v_12092:
    v_12661 = stack[-1];
    v_12662 = sub1(v_12661);
    env = stack[-5];
    goto v_12093;
v_12094:
    v_12661 = elt(env, 5); // not
    goto v_12095;
v_12096:
    goto v_12088;
v_12089:
    goto v_12090;
v_12091:
    goto v_12092;
v_12093:
    goto v_12094;
v_12095:
    v_12661 = CC_cl_simpl1(elt(env, 0), 4, stack[0], stack[-2], v_12662, v_12661);
    env = stack[-5];
    stack[-1] = v_12661;
    goto v_12116;
v_12112:
    v_12662 = stack[-1];
    goto v_12113;
v_12114:
    v_12661 = elt(env, 1); // true
    goto v_12115;
v_12116:
    goto v_12112;
v_12113:
    goto v_12114;
v_12115:
    if (v_12662 == v_12661) goto v_12110;
    else goto v_12111;
v_12110:
    v_12661 = lisp_true;
    goto v_12109;
v_12111:
    goto v_12126;
v_12122:
    v_12662 = stack[-1];
    goto v_12123;
v_12124:
    v_12661 = elt(env, 2); // false
    goto v_12125;
v_12126:
    goto v_12122;
v_12123:
    goto v_12124;
v_12125:
    v_12661 = (v_12662 == v_12661 ? lisp_true : nil);
    goto v_12109;
    v_12661 = nil;
v_12109:
    if (v_12661 == nil) goto v_12107;
    v_12661 = stack[-1];
    {
        fn = elt(env, 17); // cl_flip
        return (*qfn1(fn))(fn, v_12661);
    }
v_12107:
    v_12661 = stack[-1];
    fn = elt(env, 18); // cl_atfp
    v_12661 = (*qfn1(fn))(fn, v_12661);
    env = stack[-5];
    if (v_12661 == nil) goto v_12135;
    v_12661 = stack[-1];
    {
        fn = elt(env, 19); // rl_negateat
        return (*qfn1(fn))(fn, v_12661);
    }
v_12135:
    v_12661 = stack[-1];
    {
        fn = elt(env, 20); // cl_negate!-invol
        return (*qfn1(fn))(fn, v_12661);
    }
v_12079:
    goto v_12154;
v_12150:
    v_12662 = stack[-4];
    goto v_12151;
v_12152:
    v_12661 = elt(env, 6); // ex
    goto v_12153;
v_12154:
    goto v_12150;
v_12151:
    goto v_12152;
v_12153:
    if (v_12662 == v_12661) goto v_12148;
    else goto v_12149;
v_12148:
    v_12661 = lisp_true;
    goto v_12147;
v_12149:
    goto v_12164;
v_12160:
    v_12662 = stack[-4];
    goto v_12161;
v_12162:
    v_12661 = elt(env, 7); // all
    goto v_12163;
v_12164:
    goto v_12160;
v_12161:
    goto v_12162;
v_12163:
    v_12661 = (v_12662 == v_12661 ? lisp_true : nil);
    goto v_12147;
    v_12661 = nil;
v_12147:
    if (v_12661 == nil) goto v_12145;
    v_12661 = qvalue(elt(env, 8)); // !*rlsism
    if (v_12661 == nil) goto v_12171;
    goto v_12178;
v_12174:
    v_12662 = stack[-2];
    goto v_12175;
v_12176:
    v_12661 = stack[-3];
    v_12661 = qcdr(v_12661);
    v_12661 = qcar(v_12661);
    goto v_12177;
v_12178:
    goto v_12174;
v_12175:
    goto v_12176;
v_12177:
    fn = elt(env, 21); // rl_smrmknowl
    v_12661 = (*qfn2(fn))(fn, v_12662, v_12661);
    env = stack[-5];
    stack[-2] = v_12661;
    goto v_12169;
v_12171:
v_12169:
    goto v_12192;
v_12184:
    v_12661 = stack[-3];
    v_12661 = qcdr(v_12661);
    v_12661 = qcdr(v_12661);
    stack[0] = qcar(v_12661);
    goto v_12185;
v_12186:
    goto v_12187;
v_12188:
    v_12661 = stack[-1];
    v_12662 = sub1(v_12661);
    env = stack[-5];
    goto v_12189;
v_12190:
    v_12661 = stack[-4];
    goto v_12191;
v_12192:
    goto v_12184;
v_12185:
    goto v_12186;
v_12187:
    goto v_12188;
v_12189:
    goto v_12190;
v_12191:
    v_12661 = CC_cl_simpl1(elt(env, 0), 4, stack[0], stack[-2], v_12662, v_12661);
    env = stack[-5];
    stack[-1] = v_12661;
    goto v_12213;
v_12209:
    v_12662 = stack[-1];
    goto v_12210;
v_12211:
    v_12661 = elt(env, 1); // true
    goto v_12212;
v_12213:
    goto v_12209;
v_12210:
    goto v_12211;
v_12212:
    if (v_12662 == v_12661) goto v_12207;
    else goto v_12208;
v_12207:
    v_12661 = lisp_true;
    goto v_12206;
v_12208:
    goto v_12223;
v_12219:
    v_12662 = stack[-1];
    goto v_12220;
v_12221:
    v_12661 = elt(env, 2); // false
    goto v_12222;
v_12223:
    goto v_12219;
v_12220:
    goto v_12221;
v_12222:
    v_12661 = (v_12662 == v_12661 ? lisp_true : nil);
    goto v_12206;
    v_12661 = nil;
v_12206:
    if (v_12661 == nil) goto v_12204;
    v_12661 = stack[-1];
    goto v_11944;
v_12204:
    goto v_12236;
v_12232:
    v_12661 = stack[-3];
    v_12661 = qcdr(v_12661);
    stack[0] = qcar(v_12661);
    goto v_12233;
v_12234:
    v_12661 = stack[-1];
    fn = elt(env, 22); // cl_fvarl
    v_12661 = (*qfn1(fn))(fn, v_12661);
    goto v_12235;
v_12236:
    goto v_12232;
v_12233:
    goto v_12234;
v_12235:
    v_12661 = Lmemq(nil, stack[0], v_12661);
    if (v_12661 == nil) goto v_12230;
    else goto v_12231;
v_12230:
    v_12661 = stack[-1];
    goto v_11944;
v_12231:
    goto v_12251;
v_12245:
    v_12663 = stack[-4];
    goto v_12246;
v_12247:
    v_12661 = stack[-3];
    v_12661 = qcdr(v_12661);
    v_12662 = qcar(v_12661);
    goto v_12248;
v_12249:
    v_12661 = stack[-1];
    goto v_12250;
v_12251:
    goto v_12245;
v_12246:
    goto v_12247;
v_12248:
    goto v_12249;
v_12250:
    return list3(v_12663, v_12662, v_12661);
v_12145:
    goto v_12269;
v_12265:
    v_12662 = stack[-4];
    goto v_12266;
v_12267:
    v_12661 = elt(env, 9); // bex
    goto v_12268;
v_12269:
    goto v_12265;
v_12266:
    goto v_12267;
v_12268:
    if (v_12662 == v_12661) goto v_12263;
    else goto v_12264;
v_12263:
    v_12661 = lisp_true;
    goto v_12262;
v_12264:
    goto v_12279;
v_12275:
    v_12662 = stack[-4];
    goto v_12276;
v_12277:
    v_12661 = elt(env, 10); // ball
    goto v_12278;
v_12279:
    goto v_12275;
v_12276:
    goto v_12277;
v_12278:
    v_12661 = (v_12662 == v_12661 ? lisp_true : nil);
    goto v_12262;
    v_12661 = nil;
v_12262:
    if (v_12661 == nil) goto v_12260;
    v_12661 = qvalue(elt(env, 8)); // !*rlsism
    if (v_12661 == nil) goto v_12286;
    goto v_12293;
v_12289:
    v_12662 = stack[-2];
    goto v_12290;
v_12291:
    v_12661 = stack[-3];
    v_12661 = qcdr(v_12661);
    v_12661 = qcar(v_12661);
    goto v_12292;
v_12293:
    goto v_12289;
v_12290:
    goto v_12291;
v_12292:
    fn = elt(env, 21); // rl_smrmknowl
    v_12661 = (*qfn2(fn))(fn, v_12662, v_12661);
    env = stack[-5];
    stack[-2] = v_12661;
    goto v_12284;
v_12286:
v_12284:
    goto v_12305;
v_12299:
    v_12663 = stack[-3];
    goto v_12300;
v_12301:
    v_12662 = stack[-2];
    goto v_12302;
v_12303:
    v_12661 = stack[-1];
    goto v_12304;
v_12305:
    goto v_12299;
v_12300:
    goto v_12301;
v_12302:
    goto v_12303;
v_12304:
    {
        fn = elt(env, 23); // cl_simplbq
        return (*qfnn(fn))(fn, 3, v_12663, v_12662, v_12661);
    }
v_12260:
    goto v_12317;
v_12313:
    v_12662 = stack[-4];
    goto v_12314;
v_12315:
    v_12661 = elt(env, 11); // impl
    goto v_12316;
v_12317:
    goto v_12313;
v_12314:
    goto v_12315;
v_12316:
    if (v_12662 == v_12661) goto v_12311;
    else goto v_12312;
v_12311:
    goto v_12329;
v_12321:
    v_12661 = stack[-3];
    v_12661 = qcdr(v_12661);
    v_12664 = qcar(v_12661);
    goto v_12322;
v_12323:
    v_12661 = stack[-3];
    v_12661 = qcdr(v_12661);
    v_12661 = qcdr(v_12661);
    v_12663 = qcar(v_12661);
    goto v_12324;
v_12325:
    v_12662 = stack[-2];
    goto v_12326;
v_12327:
    v_12661 = stack[-1];
    goto v_12328;
v_12329:
    goto v_12321;
v_12322:
    goto v_12323;
v_12324:
    goto v_12325;
v_12326:
    goto v_12327;
v_12328:
    {
        fn = elt(env, 24); // cl_smsimpl!-imprep
        return (*qfnn(fn))(fn, 4, v_12664, v_12663, v_12662, v_12661);
    }
v_12312:
    goto v_12347;
v_12343:
    v_12662 = stack[-4];
    goto v_12344;
v_12345:
    v_12661 = elt(env, 12); // repl
    goto v_12346;
v_12347:
    goto v_12343;
v_12344:
    goto v_12345;
v_12346:
    if (v_12662 == v_12661) goto v_12341;
    else goto v_12342;
v_12341:
    goto v_12359;
v_12351:
    v_12661 = stack[-3];
    v_12661 = qcdr(v_12661);
    v_12661 = qcdr(v_12661);
    v_12664 = qcar(v_12661);
    goto v_12352;
v_12353:
    v_12661 = stack[-3];
    v_12661 = qcdr(v_12661);
    v_12663 = qcar(v_12661);
    goto v_12354;
v_12355:
    v_12662 = stack[-2];
    goto v_12356;
v_12357:
    v_12661 = stack[-1];
    goto v_12358;
v_12359:
    goto v_12351;
v_12352:
    goto v_12353;
v_12354:
    goto v_12355;
v_12356:
    goto v_12357;
v_12358:
    {
        fn = elt(env, 24); // cl_smsimpl!-imprep
        return (*qfnn(fn))(fn, 4, v_12664, v_12663, v_12662, v_12661);
    }
v_12342:
    goto v_12377;
v_12373:
    v_12662 = stack[-4];
    goto v_12374;
v_12375:
    v_12661 = elt(env, 13); // equiv
    goto v_12376;
v_12377:
    goto v_12373;
v_12374:
    goto v_12375;
v_12376:
    if (v_12662 == v_12661) goto v_12371;
    else goto v_12372;
v_12371:
    goto v_12389;
v_12381:
    v_12661 = stack[-3];
    v_12661 = qcdr(v_12661);
    v_12664 = qcar(v_12661);
    goto v_12382;
v_12383:
    v_12661 = stack[-3];
    v_12661 = qcdr(v_12661);
    v_12661 = qcdr(v_12661);
    v_12663 = qcar(v_12661);
    goto v_12384;
v_12385:
    v_12662 = stack[-2];
    goto v_12386;
v_12387:
    v_12661 = stack[-1];
    goto v_12388;
v_12389:
    goto v_12381;
v_12382:
    goto v_12383;
v_12384:
    goto v_12385;
v_12386:
    goto v_12387;
v_12388:
    {
        fn = elt(env, 25); // cl_smsimpl!-equiv
        return (*qfnn(fn))(fn, 4, v_12664, v_12663, v_12662, v_12661);
    }
v_12372:
    goto v_12408;
v_12404:
    v_12662 = stack[-4];
    goto v_12405;
v_12406:
    v_12661 = elt(env, 14); // cl_simpl
    goto v_12407;
v_12408:
    goto v_12404;
v_12405:
    goto v_12406;
v_12407:
    fn = elt(env, 26); // rl_external
    v_12661 = (*qfn2(fn))(fn, v_12662, v_12661);
    env = stack[-5];
    v_12662 = v_12661;
    if (v_12661 == nil) goto v_12402;
    goto v_12416;
v_12412:
    stack[0] = v_12662;
    goto v_12413;
v_12414:
    v_12661 = stack[-3];
    v_12661 = ncons(v_12661);
    env = stack[-5];
    goto v_12415;
v_12416:
    goto v_12412;
v_12413:
    goto v_12414;
v_12415:
    {
        LispObject v_12670 = stack[0];
        fn = elt(env, 27); // apply
        return (*qfn2(fn))(fn, v_12670, v_12661);
    }
v_12402:
    goto v_12425;
v_12421:
    v_12662 = stack[-3];
    goto v_12422;
v_12423:
    v_12661 = stack[0];
    goto v_12424;
v_12425:
    goto v_12421;
v_12422:
    goto v_12423;
v_12424:
    fn = elt(env, 28); // cl_simplat
    v_12661 = (*qfn2(fn))(fn, v_12662, v_12661);
    env = stack[-5];
    v_12662 = v_12661;
    v_12661 = qvalue(elt(env, 8)); // !*rlsism
    if (v_12661 == nil) goto v_12431;
    v_12661 = v_12662;
    if (!consp(v_12661)) goto v_12435;
    else goto v_12436;
v_12435:
    v_12661 = v_12662;
    goto v_12434;
v_12436:
    v_12661 = v_12662;
    v_12661 = qcar(v_12661);
    goto v_12434;
    v_12661 = nil;
v_12434:
    stack[-4] = v_12661;
    goto v_12455;
v_12451:
    v_12663 = stack[-4];
    goto v_12452;
v_12453:
    v_12661 = elt(env, 3); // or
    goto v_12454;
v_12455:
    goto v_12451;
v_12452:
    goto v_12453;
v_12454:
    if (v_12663 == v_12661) goto v_12449;
    else goto v_12450;
v_12449:
    v_12661 = lisp_true;
    goto v_12448;
v_12450:
    goto v_12465;
v_12461:
    v_12663 = stack[-4];
    goto v_12462;
v_12463:
    v_12661 = elt(env, 4); // and
    goto v_12464;
v_12465:
    goto v_12461;
v_12462:
    goto v_12463;
v_12464:
    v_12661 = (v_12663 == v_12661 ? lisp_true : nil);
    goto v_12448;
    v_12661 = nil;
v_12448:
    if (v_12661 == nil) goto v_12446;
    goto v_12478;
v_12470:
    v_12664 = stack[-4];
    goto v_12471;
v_12472:
    v_12661 = v_12662;
    v_12663 = qcdr(v_12661);
    goto v_12473;
v_12474:
    v_12662 = stack[-2];
    goto v_12475;
v_12476:
    v_12661 = stack[-1];
    goto v_12477;
v_12478:
    goto v_12470;
v_12471:
    goto v_12472;
v_12473:
    goto v_12474;
v_12475:
    goto v_12476;
v_12477:
    fn = elt(env, 16); // cl_smsimpl!-junct
    v_12661 = (*qfnn(fn))(fn, 4, v_12664, v_12663, v_12662, v_12661);
    env = stack[-5];
    v_12662 = v_12661;
    v_12661 = v_12662;
    if (v_12661 == nil) goto v_12488;
    v_12661 = v_12662;
    v_12661 = qcdr(v_12661);
    if (v_12661 == nil) goto v_12488;
    goto v_12499;
v_12495:
    v_12661 = stack[-4];
    goto v_12496;
v_12497:
    goto v_12498;
v_12499:
    goto v_12495;
v_12496:
    goto v_12497;
v_12498:
    return cons(v_12661, v_12662);
v_12488:
    v_12661 = v_12662;
    if (v_12661 == nil) goto v_12502;
    else goto v_12503;
v_12502:
    goto v_12513;
v_12509:
    v_12662 = stack[-4];
    goto v_12510;
v_12511:
    v_12661 = elt(env, 4); // and
    goto v_12512;
v_12513:
    goto v_12509;
v_12510:
    goto v_12511;
v_12512:
    if (v_12662 == v_12661) goto v_12507;
    else goto v_12508;
v_12507:
    v_12661 = elt(env, 1); // true
    goto v_12506;
v_12508:
    v_12661 = elt(env, 2); // false
    goto v_12506;
    v_12661 = nil;
v_12506:
    goto v_12486;
v_12503:
    v_12661 = v_12662;
    v_12661 = qcar(v_12661);
    goto v_12486;
    v_12661 = nil;
v_12486:
    goto v_11944;
v_12446:
    goto v_12536;
v_12532:
    v_12663 = stack[-4];
    goto v_12533;
v_12534:
    v_12661 = elt(env, 1); // true
    goto v_12535;
v_12536:
    goto v_12532;
v_12533:
    goto v_12534;
v_12535:
    if (v_12663 == v_12661) goto v_12530;
    else goto v_12531;
v_12530:
    v_12661 = lisp_true;
    goto v_12529;
v_12531:
    goto v_12546;
v_12542:
    v_12663 = stack[-4];
    goto v_12543;
v_12544:
    v_12661 = elt(env, 2); // false
    goto v_12545;
v_12546:
    goto v_12542;
v_12543:
    goto v_12544;
v_12545:
    v_12661 = (v_12663 == v_12661 ? lisp_true : nil);
    goto v_12529;
    v_12661 = nil;
v_12529:
    if (v_12661 == nil) goto v_12527;
    v_12661 = v_12662;
    goto v_11944;
v_12527:
    goto v_12560;
v_12552:
    stack[-3] = elt(env, 4); // and
    goto v_12553;
v_12554:
    v_12661 = v_12662;
    stack[0] = ncons(v_12661);
    env = stack[-5];
    goto v_12555;
v_12556:
    v_12661 = stack[-2];
    fn = elt(env, 29); // rl_smcpknowl
    v_12662 = (*qfn1(fn))(fn, v_12661);
    env = stack[-5];
    goto v_12557;
v_12558:
    v_12661 = stack[-1];
    goto v_12559;
v_12560:
    goto v_12552;
v_12553:
    goto v_12554;
v_12555:
    goto v_12556;
v_12557:
    goto v_12558;
v_12559:
    fn = elt(env, 30); // rl_smupdknowl
    v_12661 = (*qfnn(fn))(fn, 4, stack[-3], stack[0], v_12662, v_12661);
    env = stack[-5];
    goto v_12575;
v_12571:
    v_12663 = v_12661;
    goto v_12572;
v_12573:
    v_12662 = elt(env, 2); // false
    goto v_12574;
v_12575:
    goto v_12571;
v_12572:
    goto v_12573;
v_12574:
    if (v_12663 == v_12662) goto v_12569;
    else goto v_12570;
v_12569:
    v_12661 = elt(env, 2); // false
    goto v_11944;
v_12570:
    goto v_12588;
v_12580:
    v_12664 = elt(env, 4); // and
    goto v_12581;
v_12582:
    v_12663 = stack[-2];
    goto v_12583;
v_12584:
    v_12662 = v_12661;
    goto v_12585;
v_12586:
    v_12661 = stack[-1];
    goto v_12587;
v_12588:
    goto v_12580;
v_12581:
    goto v_12582;
v_12583:
    goto v_12584;
v_12585:
    goto v_12586;
v_12587:
    fn = elt(env, 31); // rl_smmkatl
    v_12661 = (*qfnn(fn))(fn, 4, v_12664, v_12663, v_12662, v_12661);
    env = stack[-5];
    v_12662 = v_12661;
    goto v_12601;
v_12597:
    v_12663 = v_12662;
    goto v_12598;
v_12599:
    v_12661 = elt(env, 2); // false
    goto v_12600;
v_12601:
    goto v_12597;
v_12598:
    goto v_12599;
v_12600:
    if (v_12663 == v_12661) goto v_12595;
    else goto v_12596;
v_12595:
    v_12661 = elt(env, 2); // false
    goto v_12594;
v_12596:
    v_12661 = v_12662;
    if (v_12661 == nil) goto v_12610;
    v_12661 = v_12662;
    v_12661 = qcdr(v_12661);
    if (v_12661 == nil) goto v_12610;
    goto v_12621;
v_12617:
    v_12661 = elt(env, 4); // and
    goto v_12618;
v_12619:
    goto v_12620;
v_12621:
    goto v_12617;
v_12618:
    goto v_12619;
v_12620:
    return cons(v_12661, v_12662);
v_12610:
    v_12661 = v_12662;
    if (v_12661 == nil) goto v_12624;
    else goto v_12625;
v_12624:
    goto v_12635;
v_12631:
    v_12662 = elt(env, 4); // and
    goto v_12632;
v_12633:
    v_12661 = elt(env, 4); // and
    goto v_12634;
v_12635:
    goto v_12631;
v_12632:
    goto v_12633;
v_12634:
    if (v_12662 == v_12661) goto v_12629;
    else goto v_12630;
v_12629:
    v_12661 = elt(env, 1); // true
    goto v_12628;
v_12630:
    v_12661 = elt(env, 2); // false
    goto v_12628;
    v_12661 = nil;
v_12628:
    goto v_12608;
v_12625:
    v_12661 = v_12662;
    v_12661 = qcar(v_12661);
    goto v_12608;
    v_12661 = nil;
v_12608:
    goto v_12594;
    v_12661 = nil;
v_12594:
    goto v_11944;
v_12431:
    v_12661 = v_12662;
    if (v_12661 == nil) goto v_12649;
    v_12661 = v_12662;
    goto v_11944;
v_12649:
    goto v_12658;
v_12654:
    v_12662 = elt(env, 15); // "cl_simpl1(): unknown operator"
    goto v_12655;
v_12656:
    v_12661 = stack[-4];
    goto v_12657;
v_12658:
    goto v_12654;
v_12655:
    goto v_12656;
v_12657:
    v_12661 = list2(v_12662, v_12661);
    env = stack[-5];
    fn = elt(env, 32); // rederr
    v_12661 = (*qfn1(fn))(fn, v_12661);
    v_12661 = nil;
v_11944:
    return onevalue(v_12661);
}



// Code for bc_zero!?

static LispObject CC_bc_zeroW(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_11939;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11939 = v_11934;
// end of prologue
    v_11939 = qcar(v_11939);
    v_11939 = (v_11939 == nil ? lisp_true : nil);
    return onevalue(v_11939);
}



// Code for ir2mml

static LispObject CC_ir2mml(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_11952;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11934);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_11934;
// end of prologue
    v_11952 = elt(env, 1); // (indent)
    fn = elt(env, 6); // fluid
    v_11952 = (*qfn1(fn))(fn, v_11952);
    env = stack[-1];
    v_11952 = (LispObject)48+TAG_FIXNUM; // 3
    qvalue(elt(env, 2)) = v_11952; // ind
    v_11952 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 3)) = v_11952; // indent
    v_11952 = elt(env, 4); // "<math>"
    fn = elt(env, 7); // printout
    v_11952 = (*qfn1(fn))(fn, v_11952);
    env = stack[-1];
    v_11952 = lisp_true;
    fn = elt(env, 8); // indent!*
    v_11952 = (*qfn1(fn))(fn, v_11952);
    env = stack[-1];
    v_11952 = stack[0];
    fn = elt(env, 9); // expression
    v_11952 = (*qfn1(fn))(fn, v_11952);
    env = stack[-1];
    v_11952 = nil;
    fn = elt(env, 8); // indent!*
    v_11952 = (*qfn1(fn))(fn, v_11952);
    env = stack[-1];
    v_11952 = elt(env, 5); // "</math>"
    fn = elt(env, 7); // printout
    v_11952 = (*qfn1(fn))(fn, v_11952);
    v_11952 = nil;
    return onevalue(v_11952);
}



// Code for chk

static LispObject CC_chk(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_12015, v_12016, v_12017;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11934);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11934;
// end of prologue
v_11933:
    v_12015 = stack[0];
    if (v_12015 == nil) goto v_11938;
    else goto v_11939;
v_11938:
    v_12015 = lisp_true;
    goto v_11937;
v_11939:
    goto v_11952;
v_11948:
    v_12016 = stack[0];
    goto v_11949;
v_11950:
    v_12015 = lisp_true;
    goto v_11951;
v_11952:
    goto v_11948;
v_11949:
    goto v_11950;
v_11951:
    if (v_12016 == v_12015) goto v_11946;
    else goto v_11947;
v_11946:
    v_12015 = lisp_true;
    goto v_11945;
v_11947:
    v_12015 = stack[0];
    v_12015 = qcar(v_12015);
    fn = elt(env, 1); // bsubs
    v_12015 = (*qfn1(fn))(fn, v_12015);
    env = stack[-2];
    stack[-1] = v_12015;
    v_12015 = stack[-1];
    fn = elt(env, 2); // freexp
    v_12015 = (*qfn1(fn))(fn, v_12015);
    env = stack[-2];
    if (v_12015 == nil) goto v_11965;
    v_12015 = stack[0];
    v_12015 = qcdr(v_12015);
    v_12015 = CC_chk(elt(env, 0), v_12015);
    v_12017 = v_12015;
    v_12015 = v_12017;
    if (v_12015 == nil) goto v_11974;
    else goto v_11975;
v_11974:
    v_12015 = nil;
    goto v_11973;
v_11975:
    goto v_11984;
v_11980:
    v_12016 = v_12017;
    goto v_11981;
v_11982:
    v_12015 = lisp_true;
    goto v_11983;
v_11984:
    goto v_11980;
v_11981:
    goto v_11982;
v_11983:
    if (v_12016 == v_12015) goto v_11978;
    else goto v_11979;
v_11978:
    v_12015 = stack[-1];
    return ncons(v_12015);
v_11979:
    goto v_11996;
v_11992:
    v_12015 = stack[-1];
    goto v_11993;
v_11994:
    v_12016 = v_12017;
    goto v_11995;
v_11996:
    goto v_11992;
v_11993:
    goto v_11994;
v_11995:
    return cons(v_12015, v_12016);
    v_12015 = nil;
v_11973:
    goto v_11963;
v_11965:
    goto v_12005;
v_12001:
    v_12015 = stack[-1];
    fn = elt(env, 3); // reval
    v_12016 = (*qfn1(fn))(fn, v_12015);
    env = stack[-2];
    goto v_12002;
v_12003:
    v_12015 = lisp_true;
    goto v_12004;
v_12005:
    goto v_12001;
v_12002:
    goto v_12003;
v_12004:
    if (v_12016 == v_12015) goto v_11999;
    else goto v_12000;
v_11999:
    v_12015 = stack[0];
    v_12015 = qcdr(v_12015);
    stack[0] = v_12015;
    goto v_11933;
v_12000:
    v_12015 = nil;
    goto v_11963;
    v_12015 = nil;
v_11963:
    goto v_11945;
    v_12015 = nil;
v_11945:
    goto v_11937;
    v_12015 = nil;
v_11937:
    return onevalue(v_12015);
}



// Code for expvec2a

static LispObject CC_expvec2a(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_11944, v_11945;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11944 = v_11934;
// end of prologue
    goto v_11941;
v_11937:
    v_11945 = v_11944;
    goto v_11938;
v_11939:
    v_11944 = qvalue(elt(env, 1)); // dipvars!*
    goto v_11940;
v_11941:
    goto v_11937;
v_11938:
    goto v_11939;
v_11940:
    {
        fn = elt(env, 2); // expvec2a1
        return (*qfn2(fn))(fn, v_11945, v_11944);
    }
}



// Code for treesizep

static LispObject CC_treesizep(LispObject env,
                         LispObject v_11934, LispObject v_11935)
{
    env = qenv(env);
    LispObject v_11952, v_11953;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11935,v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11934,v_11935);
    }
// copy arguments values to proper place
    v_11952 = v_11935;
    v_11953 = v_11934;
// end of prologue
    goto v_11941;
v_11937:
    goto v_11947;
v_11943:
    goto v_11944;
v_11945:
    goto v_11946;
v_11947:
    goto v_11943;
v_11944:
    goto v_11945;
v_11946:
    fn = elt(env, 1); // treesizep1
    v_11953 = (*qfn2(fn))(fn, v_11953, v_11952);
    goto v_11938;
v_11939:
    v_11952 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11940;
v_11941:
    goto v_11937;
v_11938:
    goto v_11939;
v_11940:
    v_11952 = (v_11953 == v_11952 ? lisp_true : nil);
    return onevalue(v_11952);
}



// Code for ncoeffs

static LispObject CC_ncoeffs(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_12005, v_12006;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11934);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_12006 = v_11934;
// end of prologue
    stack[-4] = nil;
    stack[-3] = nil;
    v_12005 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_12005;
    v_12005 = v_12006;
    stack[-1] = v_12005;
v_11945:
    v_12005 = stack[-1];
    if (v_12005 == nil) goto v_11949;
    else goto v_11950;
v_11949:
    goto v_11944;
v_11950:
    v_12005 = stack[-1];
    v_12005 = qcar(v_12005);
    stack[0] = v_12005;
    v_12005 = stack[0];
    v_12005 = qcar(v_12005);
    stack[-4] = v_12005;
v_11960:
    goto v_11970;
v_11966:
    v_12006 = stack[-2];
    goto v_11967;
v_11968:
    v_12005 = stack[-4];
    goto v_11969;
v_11970:
    goto v_11966;
v_11967:
    goto v_11968;
v_11969:
    v_12005 = (LispObject)lessp2(v_12006, v_12005);
    v_12005 = v_12005 ? lisp_true : nil;
    env = stack[-5];
    if (v_12005 == nil) goto v_11963;
    else goto v_11964;
v_11963:
    goto v_11959;
v_11964:
    goto v_11979;
v_11975:
    v_12006 = nil;
    goto v_11976;
v_11977:
    v_12005 = stack[-3];
    goto v_11978;
v_11979:
    goto v_11975;
v_11976:
    goto v_11977;
v_11978:
    v_12005 = cons(v_12006, v_12005);
    env = stack[-5];
    stack[-3] = v_12005;
    v_12005 = stack[-2];
    v_12005 = add1(v_12005);
    env = stack[-5];
    stack[-2] = v_12005;
    goto v_11960;
v_11959:
    v_12005 = stack[-2];
    v_12005 = add1(v_12005);
    env = stack[-5];
    stack[-2] = v_12005;
    goto v_11991;
v_11987:
    v_12005 = stack[0];
    v_12006 = qcdr(v_12005);
    goto v_11988;
v_11989:
    v_12005 = stack[-3];
    goto v_11990;
v_11991:
    goto v_11987;
v_11988:
    goto v_11989;
v_11990:
    v_12005 = cons(v_12006, v_12005);
    env = stack[-5];
    stack[-3] = v_12005;
    v_12005 = stack[-1];
    v_12005 = qcdr(v_12005);
    stack[-1] = v_12005;
    goto v_11945;
v_11944:
    goto v_12002;
v_11998:
    v_12006 = stack[-4];
    goto v_11999;
v_12000:
    v_12005 = stack[-3];
    goto v_12001;
v_12002:
    goto v_11998;
v_11999:
    goto v_12000;
v_12001:
    return cons(v_12006, v_12005);
    return onevalue(v_12005);
}



// Code for nfactorial

static LispObject CC_nfactorial(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_11992, v_11993;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11934);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_11934;
// end of prologue
    goto v_11945;
v_11941:
    v_11993 = stack[-1];
    goto v_11942;
v_11943:
    v_11992 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_11944;
v_11945:
    goto v_11941;
v_11942:
    goto v_11943;
v_11944:
    v_11992 = (LispObject)greaterp2(v_11993, v_11992);
    v_11992 = v_11992 ? lisp_true : nil;
    env = stack[-3];
    if (v_11992 == nil) goto v_11939;
    goto v_11953;
v_11949:
    v_11993 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11950;
v_11951:
    v_11992 = stack[-1];
    goto v_11952;
v_11953:
    goto v_11949;
v_11950:
    goto v_11951;
v_11952:
    {
        fn = elt(env, 1); // fac!-part
        return (*qfn2(fn))(fn, v_11993, v_11992);
    }
v_11939:
    v_11992 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_11992;
    v_11992 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_11992;
v_11965:
    goto v_11977;
v_11973:
    v_11993 = stack[-1];
    goto v_11974;
v_11975:
    v_11992 = stack[0];
    goto v_11976;
v_11977:
    goto v_11973;
v_11974:
    goto v_11975;
v_11976:
    v_11992 = difference2(v_11993, v_11992);
    env = stack[-3];
    v_11992 = Lminusp(nil, v_11992);
    env = stack[-3];
    if (v_11992 == nil) goto v_11970;
    goto v_11964;
v_11970:
    goto v_11986;
v_11982:
    v_11993 = stack[-2];
    goto v_11983;
v_11984:
    v_11992 = stack[0];
    goto v_11985;
v_11986:
    goto v_11982;
v_11983:
    goto v_11984;
v_11985:
    v_11992 = times2(v_11993, v_11992);
    env = stack[-3];
    stack[-2] = v_11992;
    v_11992 = stack[0];
    v_11992 = add1(v_11992);
    env = stack[-3];
    stack[0] = v_11992;
    goto v_11965;
v_11964:
    v_11992 = stack[-2];
    goto v_11937;
    v_11992 = nil;
v_11937:
    return onevalue(v_11992);
}



// Code for rootrnd

static LispObject CC_rootrnd(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_11944, v_11945;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11944 = v_11934;
// end of prologue
    goto v_11941;
v_11937:
    v_11945 = v_11944;
    goto v_11938;
v_11939:
    v_11944 = qvalue(elt(env, 1)); // acc!#
    goto v_11940;
v_11941:
    goto v_11937;
v_11938:
    goto v_11939;
v_11940:
    {
        fn = elt(env, 2); // rtrnda
        return (*qfn2(fn))(fn, v_11945, v_11944);
    }
}



// Code for cde_delete

static LispObject CC_cde_delete(LispObject env,
                         LispObject v_11934, LispObject v_11935)
{
    env = qenv(env);
    LispObject v_11977, v_11978, v_11979, v_11980;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11935,v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11934,v_11935);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_11977 = v_11935;
    stack[0] = v_11934;
// end of prologue
    v_11980 = nil;
    stack[-1] = v_11977;
v_11943:
    v_11977 = stack[-1];
    if (v_11977 == nil) goto v_11947;
    else goto v_11948;
v_11947:
    goto v_11942;
v_11948:
    v_11977 = stack[-1];
    v_11977 = qcar(v_11977);
    v_11979 = v_11977;
    goto v_11962;
v_11958:
    v_11978 = v_11979;
    goto v_11959;
v_11960:
    v_11977 = stack[0];
    goto v_11961;
v_11962:
    goto v_11958;
v_11959:
    goto v_11960;
v_11961:
    if (equal(v_11978, v_11977)) goto v_11957;
    goto v_11970;
v_11966:
    v_11977 = v_11979;
    goto v_11967;
v_11968:
    v_11978 = v_11980;
    goto v_11969;
v_11970:
    goto v_11966;
v_11967:
    goto v_11968;
v_11969:
    v_11977 = cons(v_11977, v_11978);
    env = stack[-2];
    v_11980 = v_11977;
    goto v_11955;
v_11957:
v_11955:
    v_11977 = stack[-1];
    v_11977 = qcdr(v_11977);
    stack[-1] = v_11977;
    goto v_11943;
v_11942:
    v_11977 = v_11980;
        return Lnreverse(nil, v_11977);
    return onevalue(v_11977);
}



// Code for derivative!-mod!-p!-1

static LispObject CC_derivativeKmodKpK1(LispObject env,
                         LispObject v_11934, LispObject v_11935)
{
    env = qenv(env);
    LispObject v_12038, v_12039, v_12040;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11935,v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11934,v_11935);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11935;
    stack[-2] = v_11934;
// end of prologue
    v_12038 = stack[-2];
    if (!consp(v_12038)) goto v_11943;
    else goto v_11944;
v_11943:
    v_12038 = lisp_true;
    goto v_11942;
v_11944:
    v_12038 = stack[-2];
    v_12038 = qcar(v_12038);
    v_12038 = (consp(v_12038) ? nil : lisp_true);
    goto v_11942;
    v_12038 = nil;
v_11942:
    if (v_12038 == nil) goto v_11940;
    v_12038 = nil;
    goto v_11938;
v_11940:
    goto v_11959;
v_11955:
    v_12038 = stack[-2];
    v_12038 = qcar(v_12038);
    v_12038 = qcar(v_12038);
    v_12039 = qcar(v_12038);
    goto v_11956;
v_11957:
    v_12038 = stack[-1];
    goto v_11958;
v_11959:
    goto v_11955;
v_11956:
    goto v_11957;
v_11958:
    if (equal(v_12039, v_12038)) goto v_11954;
    v_12038 = nil;
    goto v_11938;
v_11954:
    goto v_11972;
v_11968:
    v_12038 = stack[-2];
    v_12038 = qcar(v_12038);
    v_12038 = qcar(v_12038);
    v_12039 = qcdr(v_12038);
    goto v_11969;
v_11970:
    v_12038 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11971;
v_11972:
    goto v_11968;
v_11969:
    goto v_11970;
v_11971:
    if (v_12039 == v_12038) goto v_11966;
    else goto v_11967;
v_11966:
    v_12038 = stack[-2];
    v_12038 = qcar(v_12038);
    v_12038 = qcdr(v_12038);
    goto v_11938;
v_11967:
    goto v_11988;
v_11984:
    v_12038 = stack[-2];
    v_12038 = qcar(v_12038);
    v_12039 = qcdr(v_12038);
    goto v_11985;
v_11986:
    v_12038 = stack[-2];
    v_12038 = qcar(v_12038);
    v_12038 = qcar(v_12038);
    v_12038 = qcdr(v_12038);
    v_12038 = Lmodular_number(nil, v_12038);
    env = stack[-4];
    goto v_11987;
v_11988:
    goto v_11984;
v_11985:
    goto v_11986;
v_11987:
    fn = elt(env, 1); // multiply!-by!-constant!-mod!-p
    stack[0] = (*qfn2(fn))(fn, v_12039, v_12038);
    env = stack[-4];
    goto v_12002;
v_11998:
    v_12038 = stack[-2];
    v_12039 = qcdr(v_12038);
    goto v_11999;
v_12000:
    v_12038 = stack[-1];
    goto v_12001;
v_12002:
    goto v_11998;
v_11999:
    goto v_12000;
v_12001:
    v_12038 = CC_derivativeKmodKpK1(elt(env, 0), v_12039, v_12038);
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v_12038;
    v_12038 = stack[-3];
    if (v_12038 == nil) goto v_12010;
    else goto v_12011;
v_12010:
    v_12038 = stack[0];
    goto v_12009;
v_12011:
    goto v_12023;
v_12017:
    goto v_12029;
v_12025:
    v_12039 = stack[-1];
    goto v_12026;
v_12027:
    v_12038 = stack[-2];
    v_12038 = qcar(v_12038);
    v_12038 = qcar(v_12038);
    v_12038 = qcdr(v_12038);
    v_12038 = (LispObject)((intptr_t)(v_12038) - 0x10);
    goto v_12028;
v_12029:
    goto v_12025;
v_12026:
    goto v_12027;
v_12028:
    fn = elt(env, 2); // mksp
    v_12040 = (*qfn2(fn))(fn, v_12039, v_12038);
    goto v_12018;
v_12019:
    v_12039 = stack[-3];
    goto v_12020;
v_12021:
    v_12038 = stack[0];
    goto v_12022;
v_12023:
    goto v_12017;
v_12018:
    goto v_12019;
v_12020:
    goto v_12021;
v_12022:
    return acons(v_12040, v_12039, v_12038);
    v_12038 = nil;
v_12009:
    goto v_11938;
    v_12038 = nil;
v_11938:
    return onevalue(v_12038);
}



// Code for carrassoc

static LispObject CC_carrassoc(LispObject env,
                         LispObject v_11934, LispObject v_11935)
{
    env = qenv(env);
    LispObject v_11965, v_11966;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11935,v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11934,v_11935);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11935;
    stack[-1] = v_11934;
// end of prologue
    goto v_11949;
v_11945:
    v_11966 = stack[-1];
    goto v_11946;
v_11947:
    v_11965 = stack[0];
    goto v_11948;
v_11949:
    goto v_11945;
v_11946:
    goto v_11947;
v_11948:
    fn = elt(env, 4); // rassoc
    v_11965 = (*qfn2(fn))(fn, v_11966, v_11965);
    env = stack[-2];
    v_11966 = v_11965;
    if (!consp(v_11965)) goto v_11943;
    v_11965 = v_11966;
    v_11965 = qcar(v_11965);
    goto v_11939;
v_11943:
    v_11965 = Lterpri(nil, 0);
    env = stack[-2];
    v_11965 = elt(env, 1); // "RASSOC trouble: "
    v_11965 = Lprinc(nil, v_11965);
    env = stack[-2];
    v_11965 = stack[-1];
    v_11965 = Lprin(nil, v_11965);
    env = stack[-2];
    v_11965 = elt(env, 2); // " "
    v_11965 = Lprinc(nil, v_11965);
    env = stack[-2];
    v_11965 = stack[0];
    v_11965 = Lprint(nil, v_11965);
    env = stack[-2];
    v_11965 = elt(env, 3); // "rassoc trouble"
    fn = elt(env, 5); // rederr
    v_11965 = (*qfn1(fn))(fn, v_11965);
    v_11965 = nil;
v_11939:
    return onevalue(v_11965);
}



// Code for gcref_select

static LispObject CC_gcref_select(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_12042, v_12043, v_12044;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11934);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_12042 = v_11934;
// end of prologue
    stack[-3] = v_12042;
v_11941:
    v_12042 = stack[-3];
    if (v_12042 == nil) goto v_11946;
    else goto v_11947;
v_11946:
    v_12042 = nil;
    goto v_11940;
v_11947:
    v_12042 = stack[-3];
    v_12042 = qcar(v_12042);
    v_12044 = v_12042;
    goto v_11966;
v_11962:
    v_12043 = v_12044;
    goto v_11963;
v_11964:
    v_12042 = elt(env, 1); // defd
    goto v_11965;
v_11966:
    goto v_11962;
v_11963:
    goto v_11964;
v_11965:
    v_12042 = Lflagp(nil, v_12043, v_12042);
    env = stack[-4];
    if (v_12042 == nil) goto v_11960;
    goto v_11973;
v_11969:
    v_12043 = v_12044;
    goto v_11970;
v_11971:
    v_12042 = qvalue(elt(env, 2)); // gcref_nolist!*
    goto v_11972;
v_11973:
    goto v_11969;
v_11970:
    goto v_11971;
v_11972:
    v_12042 = Lmemq(nil, v_12043, v_12042);
    v_12042 = (v_12042 == nil ? lisp_true : nil);
    goto v_11958;
v_11960:
    v_12042 = nil;
    goto v_11958;
    v_12042 = nil;
v_11958:
    if (v_12042 == nil) goto v_11956;
    v_12042 = v_12044;
    v_12042 = ncons(v_12042);
    env = stack[-4];
    goto v_11954;
v_11956:
    v_12042 = nil;
v_11954:
    stack[-2] = v_12042;
    v_12042 = stack[-2];
    fn = elt(env, 3); // lastpair
    v_12042 = (*qfn1(fn))(fn, v_12042);
    env = stack[-4];
    stack[-1] = v_12042;
    v_12042 = stack[-3];
    v_12042 = qcdr(v_12042);
    stack[-3] = v_12042;
    v_12042 = stack[-1];
    if (!consp(v_12042)) goto v_11989;
    else goto v_11990;
v_11989:
    goto v_11941;
v_11990:
v_11942:
    v_12042 = stack[-3];
    if (v_12042 == nil) goto v_11994;
    else goto v_11995;
v_11994:
    v_12042 = stack[-2];
    goto v_11940;
v_11995:
    goto v_12003;
v_11999:
    stack[0] = stack[-1];
    goto v_12000;
v_12001:
    v_12042 = stack[-3];
    v_12042 = qcar(v_12042);
    v_12044 = v_12042;
    goto v_12021;
v_12017:
    v_12043 = v_12044;
    goto v_12018;
v_12019:
    v_12042 = elt(env, 1); // defd
    goto v_12020;
v_12021:
    goto v_12017;
v_12018:
    goto v_12019;
v_12020:
    v_12042 = Lflagp(nil, v_12043, v_12042);
    env = stack[-4];
    if (v_12042 == nil) goto v_12015;
    goto v_12028;
v_12024:
    v_12043 = v_12044;
    goto v_12025;
v_12026:
    v_12042 = qvalue(elt(env, 2)); // gcref_nolist!*
    goto v_12027;
v_12028:
    goto v_12024;
v_12025:
    goto v_12026;
v_12027:
    v_12042 = Lmemq(nil, v_12043, v_12042);
    v_12042 = (v_12042 == nil ? lisp_true : nil);
    goto v_12013;
v_12015:
    v_12042 = nil;
    goto v_12013;
    v_12042 = nil;
v_12013:
    if (v_12042 == nil) goto v_12011;
    v_12042 = v_12044;
    v_12042 = ncons(v_12042);
    env = stack[-4];
    goto v_12009;
v_12011:
    v_12042 = nil;
v_12009:
    goto v_12002;
v_12003:
    goto v_11999;
v_12000:
    goto v_12001;
v_12002:
    v_12042 = Lrplacd(nil, stack[0], v_12042);
    env = stack[-4];
    v_12042 = stack[-1];
    fn = elt(env, 3); // lastpair
    v_12042 = (*qfn1(fn))(fn, v_12042);
    env = stack[-4];
    stack[-1] = v_12042;
    v_12042 = stack[-3];
    v_12042 = qcdr(v_12042);
    stack[-3] = v_12042;
    goto v_11942;
v_11940:
    return onevalue(v_12042);
}



// Code for cl_atl

static LispObject CC_cl_atl(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_11945, v_11946;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11934);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_11945 = v_11934;
// end of prologue
    goto v_11941;
v_11937:
    fn = elt(env, 2); // cl_atl1
    v_11946 = (*qfn1(fn))(fn, v_11945);
    env = stack[0];
    goto v_11938;
v_11939:
    v_11945 = elt(env, 1); // rl_ordatp
    goto v_11940;
v_11941:
    goto v_11937;
v_11938:
    goto v_11939;
v_11940:
    {
        fn = elt(env, 3); // sort
        return (*qfn2(fn))(fn, v_11946, v_11945);
    }
}



// Code for sq2sstm

static LispObject CC_sq2sstm(LispObject env,
                         LispObject v_11934, LispObject v_11935)
{
    env = qenv(env);
    LispObject v_12043, v_12044, v_12045;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11935,v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11934,v_11935);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_11935;
    v_12045 = v_11934;
// end of prologue
    goto v_11950;
v_11946:
    v_12043 = v_12045;
    v_12043 = qcar(v_12043);
    v_12044 = qcar(v_12043);
    goto v_11947;
v_11948:
    v_12043 = stack[-2];
    v_12043 = qcar(v_12043);
    v_12043 = qcar(v_12043);
    goto v_11949;
v_11950:
    goto v_11946;
v_11947:
    goto v_11948;
v_11949:
    if (equal(v_12044, v_12043)) goto v_11944;
    else goto v_11945;
v_11944:
    v_12043 = v_12045;
    v_12043 = qcdr(v_12043);
    stack[0] = v_12043;
    v_12043 = v_12045;
    v_12043 = qcar(v_12043);
    v_12043 = qcdr(v_12043);
    stack[-3] = v_12043;
    v_12043 = stack[0];
    if (!consp(v_12043)) goto v_11968;
    else goto v_11969;
v_11968:
    v_12043 = lisp_true;
    goto v_11967;
v_11969:
    v_12043 = stack[0];
    v_12043 = qcar(v_12043);
    v_12043 = (consp(v_12043) ? nil : lisp_true);
    goto v_11967;
    v_12043 = nil;
v_11967:
    if (v_12043 == nil) goto v_11965;
    goto v_11985;
v_11979:
    stack[-1] = stack[-3];
    goto v_11980;
v_11981:
    v_12043 = stack[-2];
    v_12043 = qcdr(v_12043);
    fn = elt(env, 1); // mkzl
    v_12044 = (*qfn1(fn))(fn, v_12043);
    env = stack[-4];
    goto v_11982;
v_11983:
    v_12043 = stack[0];
    goto v_11984;
v_11985:
    goto v_11979;
v_11980:
    goto v_11981;
v_11982:
    goto v_11983;
v_11984:
    v_12043 = acons(stack[-1], v_12044, v_12043);
    return ncons(v_12043);
v_11965:
    goto v_11998;
v_11994:
    stack[-1] = stack[0];
    goto v_11995;
v_11996:
    goto v_12005;
v_12001:
    v_12043 = stack[-2];
    v_12043 = qcar(v_12043);
    stack[0] = qcdr(v_12043);
    goto v_12002;
v_12003:
    v_12043 = stack[-2];
    v_12043 = qcdr(v_12043);
    v_12043 = sub1(v_12043);
    env = stack[-4];
    goto v_12004;
v_12005:
    goto v_12001;
v_12002:
    goto v_12003;
v_12004:
    v_12043 = cons(stack[0], v_12043);
    env = stack[-4];
    goto v_11997;
v_11998:
    goto v_11994;
v_11995:
    goto v_11996;
v_11997:
    fn = elt(env, 2); // sq2sscfpl
    v_12043 = (*qfn2(fn))(fn, stack[-1], v_12043);
    env = stack[-4];
    goto v_11963;
v_11963:
    goto v_11943;
v_11945:
    goto v_12019;
v_12015:
    v_12043 = v_12045;
    stack[-1] = ncons(v_12043);
    env = stack[-4];
    goto v_12016;
v_12017:
    goto v_12027;
v_12023:
    v_12043 = stack[-2];
    v_12043 = qcar(v_12043);
    stack[0] = qcdr(v_12043);
    goto v_12024;
v_12025:
    v_12043 = stack[-2];
    v_12043 = qcdr(v_12043);
    v_12043 = sub1(v_12043);
    env = stack[-4];
    goto v_12026;
v_12027:
    goto v_12023;
v_12024:
    goto v_12025;
v_12026:
    v_12043 = cons(stack[0], v_12043);
    env = stack[-4];
    goto v_12018;
v_12019:
    goto v_12015;
v_12016:
    goto v_12017;
v_12018:
    fn = elt(env, 2); // sq2sscfpl
    v_12043 = (*qfn2(fn))(fn, stack[-1], v_12043);
    env = stack[-4];
    v_12044 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_12044;
    goto v_11943;
v_11943:
    goto v_12040;
v_12036:
    v_12044 = stack[-3];
    goto v_12037;
v_12038:
    goto v_12039;
v_12040:
    goto v_12036;
v_12037:
    goto v_12038;
v_12039:
    {
        fn = elt(env, 3); // mapins
        return (*qfn2(fn))(fn, v_12044, v_12043);
    }
    return onevalue(v_12043);
}



// Code for diff!-over!-k!-mod!-p

static LispObject CC_diffKoverKkKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12109, v_12110, v_12111;
    LispObject fn;
    LispObject v_11936, v_11935, v_11934;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "diff-over-k-mod-p");
    va_start(aa, nargs);
    v_11934 = va_arg(aa, LispObject);
    v_11935 = va_arg(aa, LispObject);
    v_11936 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_11936,v_11935,v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_11934,v_11935,v_11936);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_11936;
    stack[-1] = v_11935;
    stack[-2] = v_11934;
// end of prologue
    v_12109 = stack[-2];
    if (!consp(v_12109)) goto v_11944;
    else goto v_11945;
v_11944:
    v_12109 = lisp_true;
    goto v_11943;
v_11945:
    v_12109 = stack[-2];
    v_12109 = qcar(v_12109);
    v_12109 = (consp(v_12109) ? nil : lisp_true);
    goto v_11943;
    v_12109 = nil;
v_11943:
    if (v_12109 == nil) goto v_11941;
    v_12109 = nil;
    goto v_11939;
v_11941:
    goto v_11960;
v_11956:
    v_12109 = stack[-2];
    v_12109 = qcar(v_12109);
    v_12109 = qcar(v_12109);
    v_12110 = qcar(v_12109);
    goto v_11957;
v_11958:
    v_12109 = stack[0];
    goto v_11959;
v_11960:
    goto v_11956;
v_11957:
    goto v_11958;
v_11959:
    if (equal(v_12110, v_12109)) goto v_11954;
    else goto v_11955;
v_11954:
    goto v_11974;
v_11970:
    v_12109 = stack[-2];
    v_12109 = qcar(v_12109);
    v_12109 = qcar(v_12109);
    v_12110 = qcdr(v_12109);
    goto v_11971;
v_11972:
    v_12109 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11973;
v_11974:
    goto v_11970;
v_11971:
    goto v_11972;
v_11973:
    if (v_12110 == v_12109) goto v_11968;
    else goto v_11969;
v_11968:
    goto v_11985;
v_11981:
    v_12109 = stack[-2];
    v_12109 = qcar(v_12109);
    v_12110 = qcdr(v_12109);
    goto v_11982;
v_11983:
    v_12109 = stack[-1];
    v_12109 = Lmodular_number(nil, v_12109);
    env = stack[-4];
    goto v_11984;
v_11985:
    goto v_11981;
v_11982:
    goto v_11983;
v_11984:
    {
        fn = elt(env, 1); // quotfail!-mod!-p
        return (*qfn2(fn))(fn, v_12110, v_12109);
    }
v_11969:
    goto v_11998;
v_11994:
    goto v_12004;
v_12000:
    v_12109 = stack[-2];
    v_12109 = qcar(v_12109);
    v_12109 = qcar(v_12109);
    v_12109 = qcdr(v_12109);
    v_12110 = Lmodular_number(nil, v_12109);
    env = stack[-4];
    goto v_12001;
v_12002:
    v_12109 = stack[-2];
    v_12109 = qcar(v_12109);
    v_12109 = qcdr(v_12109);
    goto v_12003;
v_12004:
    goto v_12000;
v_12001:
    goto v_12002;
v_12003:
    fn = elt(env, 2); // times!-mod!-p
    v_12110 = (*qfn2(fn))(fn, v_12110, v_12109);
    env = stack[-4];
    goto v_11995;
v_11996:
    v_12109 = stack[-1];
    v_12109 = Lmodular_number(nil, v_12109);
    env = stack[-4];
    goto v_11997;
v_11998:
    goto v_11994;
v_11995:
    goto v_11996;
v_11997:
    fn = elt(env, 1); // quotfail!-mod!-p
    stack[-3] = (*qfn2(fn))(fn, v_12110, v_12109);
    env = stack[-4];
    goto v_12022;
v_12016:
    v_12109 = stack[-2];
    v_12111 = qcdr(v_12109);
    goto v_12017;
v_12018:
    v_12110 = stack[-1];
    goto v_12019;
v_12020:
    v_12109 = stack[0];
    goto v_12021;
v_12022:
    goto v_12016;
v_12017:
    goto v_12018;
v_12019:
    goto v_12020;
v_12021:
    v_12109 = CC_diffKoverKkKmodKp(elt(env, 0), 3, v_12111, v_12110, v_12109);
    env = stack[-4];
    stack[-1] = v_12109;
    v_12109 = stack[-3];
    if (v_12109 == nil) goto v_12031;
    else goto v_12032;
v_12031:
    v_12109 = stack[-1];
    goto v_12030;
v_12032:
    goto v_12044;
v_12038:
    goto v_12050;
v_12046:
    v_12110 = stack[0];
    goto v_12047;
v_12048:
    v_12109 = stack[-2];
    v_12109 = qcar(v_12109);
    v_12109 = qcar(v_12109);
    v_12109 = qcdr(v_12109);
    v_12109 = (LispObject)((intptr_t)(v_12109) - 0x10);
    goto v_12049;
v_12050:
    goto v_12046;
v_12047:
    goto v_12048;
v_12049:
    fn = elt(env, 3); // mksp
    v_12111 = (*qfn2(fn))(fn, v_12110, v_12109);
    goto v_12039;
v_12040:
    v_12110 = stack[-3];
    goto v_12041;
v_12042:
    v_12109 = stack[-1];
    goto v_12043;
v_12044:
    goto v_12038;
v_12039:
    goto v_12040;
v_12041:
    goto v_12042;
v_12043:
    return acons(v_12111, v_12110, v_12109);
    v_12109 = nil;
v_12030:
    goto v_11967;
    v_12109 = nil;
v_11967:
    goto v_11939;
v_11955:
    goto v_12068;
v_12062:
    v_12109 = stack[-2];
    v_12109 = qcar(v_12109);
    v_12111 = qcdr(v_12109);
    goto v_12063;
v_12064:
    v_12110 = stack[-1];
    goto v_12065;
v_12066:
    v_12109 = stack[0];
    goto v_12067;
v_12068:
    goto v_12062;
v_12063:
    goto v_12064;
v_12065:
    goto v_12066;
v_12067:
    stack[-3] = CC_diffKoverKkKmodKp(elt(env, 0), 3, v_12111, v_12110, v_12109);
    env = stack[-4];
    goto v_12081;
v_12075:
    v_12109 = stack[-2];
    v_12111 = qcdr(v_12109);
    goto v_12076;
v_12077:
    v_12110 = stack[-1];
    goto v_12078;
v_12079:
    v_12109 = stack[0];
    goto v_12080;
v_12081:
    goto v_12075;
v_12076:
    goto v_12077;
v_12078:
    goto v_12079;
v_12080:
    v_12109 = CC_diffKoverKkKmodKp(elt(env, 0), 3, v_12111, v_12110, v_12109);
    v_12110 = stack[-3];
    v_12111 = v_12110;
    if (v_12111 == nil) goto v_12090;
    else goto v_12091;
v_12090:
    goto v_12089;
v_12091:
    goto v_12103;
v_12097:
    v_12111 = stack[-2];
    v_12111 = qcar(v_12111);
    v_12111 = qcar(v_12111);
    goto v_12098;
v_12099:
    goto v_12100;
v_12101:
    goto v_12102;
v_12103:
    goto v_12097;
v_12098:
    goto v_12099;
v_12100:
    goto v_12101;
v_12102:
    return acons(v_12111, v_12110, v_12109);
    v_12109 = nil;
v_12089:
    goto v_11939;
    v_12109 = nil;
v_11939:
    return onevalue(v_12109);
}



// Code for rd!:prep

static LispObject CC_rdTprep(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_11958;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11934);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_11934;
// end of prologue
    v_11958 = qvalue(elt(env, 1)); // !*noconvert
    if (v_11958 == nil) goto v_11939;
    v_11958 = stack[0];
    {
        fn = elt(env, 2); // rdprep1
        return (*qfn1(fn))(fn, v_11958);
    }
v_11939:
    v_11958 = stack[0];
    fn = elt(env, 3); // rd!:onep
    v_11958 = (*qfn1(fn))(fn, v_11958);
    env = stack[-1];
    if (v_11958 == nil) goto v_11944;
    v_11958 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11937;
v_11944:
    v_11958 = stack[0];
    fn = elt(env, 4); // rd!:minus
    v_11958 = (*qfn1(fn))(fn, v_11958);
    env = stack[-1];
    fn = elt(env, 3); // rd!:onep
    v_11958 = (*qfn1(fn))(fn, v_11958);
    env = stack[-1];
    if (v_11958 == nil) goto v_11949;
    v_11958 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_11937;
v_11949:
    v_11958 = stack[0];
    {
        fn = elt(env, 2); // rdprep1
        return (*qfn1(fn))(fn, v_11958);
    }
    v_11958 = nil;
v_11937:
    return onevalue(v_11958);
}



// Code for dipevlcomp

static LispObject CC_dipevlcomp(LispObject env,
                         LispObject v_11934, LispObject v_11935)
{
    env = qenv(env);
    LispObject v_11948, v_11949;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11935,v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11934,v_11935);
    }
// copy arguments values to proper place
    v_11948 = v_11935;
    v_11949 = v_11934;
// end of prologue
    goto v_11942;
v_11938:
    v_11949 = qcar(v_11949);
    goto v_11939;
v_11940:
    v_11948 = qcar(v_11948);
    goto v_11941;
v_11942:
    goto v_11938;
v_11939:
    goto v_11940;
v_11941:
    fn = elt(env, 1); // evcompless!?
    v_11948 = (*qfn2(fn))(fn, v_11949, v_11948);
    v_11948 = (v_11948 == nil ? lisp_true : nil);
    return onevalue(v_11948);
}



// Code for coposp

static LispObject CC_coposp(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_11959, v_11960;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11960 = v_11934;
// end of prologue
    v_11959 = v_11960;
    v_11959 = qcdr(v_11959);
    if (v_11959 == nil) goto v_11938;
    else goto v_11939;
v_11938:
    v_11959 = lisp_true;
    goto v_11937;
v_11939:
    v_11959 = v_11960;
    v_11959 = qcar(v_11959);
    if (!consp(v_11959)) goto v_11947;
    else goto v_11948;
v_11947:
    v_11959 = v_11960;
    v_11959 = qcdr(v_11959);
    {
        fn = elt(env, 1); // contposp
        return (*qfn1(fn))(fn, v_11959);
    }
v_11948:
    v_11959 = v_11960;
    v_11959 = qcdr(v_11959);
    {
        fn = elt(env, 2); // covposp
        return (*qfn1(fn))(fn, v_11959);
    }
    v_11959 = nil;
    goto v_11937;
    v_11959 = nil;
v_11937:
    return onevalue(v_11959);
}



// Code for assert_format

static LispObject CC_assert_format(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12087, v_12088, v_12089;
    LispObject v_11936, v_11935, v_11934;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "assert_format");
    va_start(aa, nargs);
    v_11934 = va_arg(aa, LispObject);
    v_11935 = va_arg(aa, LispObject);
    v_11936 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_11936,v_11935,v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_11934,v_11935,v_11936);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    v_12087 = v_11936;
    stack[-8] = v_11935;
    stack[-9] = v_11934;
// end of prologue
    v_12087 = Lexplode(nil, v_12087);
    env = stack[-11];
    stack[-10] = v_12087;
    goto v_11950;
v_11944:
    stack[-7] = elt(env, 1); // !!
    goto v_11945;
v_11946:
    stack[-6] = elt(env, 2); // !)
    goto v_11947;
v_11948:
    goto v_11960;
v_11954:
    stack[-5] = elt(env, 1); // !!
    goto v_11955;
v_11956:
    stack[-4] = elt(env, 3); // ! 
    goto v_11957;
v_11958:
    goto v_11970;
v_11964:
    stack[-3] = elt(env, 1); // !!
    goto v_11965;
v_11966:
    stack[-2] = elt(env, 4); // !-
    goto v_11967;
v_11968:
    goto v_11980;
v_11974:
    stack[-1] = elt(env, 1); // !!
    goto v_11975;
v_11976:
    stack[0] = elt(env, 5); // !>
    goto v_11977;
v_11978:
    goto v_11990;
v_11984:
    v_12089 = elt(env, 1); // !!
    goto v_11985;
v_11986:
    v_12088 = elt(env, 3); // ! 
    goto v_11987;
v_11988:
    v_12087 = stack[-10];
    goto v_11989;
v_11990:
    goto v_11984;
v_11985:
    goto v_11986;
v_11987:
    goto v_11988;
v_11989:
    v_12087 = list2star(v_12089, v_12088, v_12087);
    env = stack[-11];
    goto v_11979;
v_11980:
    goto v_11974;
v_11975:
    goto v_11976;
v_11977:
    goto v_11978;
v_11979:
    v_12087 = list2star(stack[-1], stack[0], v_12087);
    env = stack[-11];
    goto v_11969;
v_11970:
    goto v_11964;
v_11965:
    goto v_11966;
v_11967:
    goto v_11968;
v_11969:
    v_12087 = list2star(stack[-3], stack[-2], v_12087);
    env = stack[-11];
    goto v_11959;
v_11960:
    goto v_11954;
v_11955:
    goto v_11956;
v_11957:
    goto v_11958;
v_11959:
    v_12087 = list2star(stack[-5], stack[-4], v_12087);
    env = stack[-11];
    goto v_11949;
v_11950:
    goto v_11944;
v_11945:
    goto v_11946;
v_11947:
    goto v_11948;
v_11949:
    v_12087 = list2star(stack[-7], stack[-6], v_12087);
    env = stack[-11];
    stack[-10] = v_12087;
    v_12087 = stack[-8];
    v_12087 = Lreverse(nil, v_12087);
    env = stack[-11];
    stack[-4] = v_12087;
v_11997:
    v_12087 = stack[-4];
    if (v_12087 == nil) goto v_12002;
    else goto v_12003;
v_12002:
    goto v_11996;
v_12003:
    v_12087 = stack[-4];
    v_12087 = qcar(v_12087);
    goto v_12016;
v_12010:
    stack[-3] = elt(env, 1); // !!
    goto v_12011;
v_12012:
    stack[-2] = elt(env, 6); // !,
    goto v_12013;
v_12014:
    goto v_12026;
v_12020:
    stack[-1] = elt(env, 1); // !!
    goto v_12021;
v_12022:
    stack[0] = elt(env, 3); // ! 
    goto v_12023;
v_12024:
    goto v_12034;
v_12030:
    v_12088 = Lexplode(nil, v_12087);
    env = stack[-11];
    goto v_12031;
v_12032:
    v_12087 = stack[-10];
    goto v_12033;
v_12034:
    goto v_12030;
v_12031:
    goto v_12032;
v_12033:
    v_12087 = Lnconc(nil, v_12088, v_12087);
    env = stack[-11];
    goto v_12025;
v_12026:
    goto v_12020;
v_12021:
    goto v_12022;
v_12023:
    goto v_12024;
v_12025:
    v_12087 = list2star(stack[-1], stack[0], v_12087);
    env = stack[-11];
    goto v_12015;
v_12016:
    goto v_12010;
v_12011:
    goto v_12012;
v_12013:
    goto v_12014;
v_12015:
    v_12087 = list2star(stack[-3], stack[-2], v_12087);
    env = stack[-11];
    stack[-10] = v_12087;
    v_12087 = stack[-4];
    v_12087 = qcdr(v_12087);
    stack[-4] = v_12087;
    goto v_11997;
v_11996:
    v_12087 = stack[-10];
    v_12087 = qcdr(v_12087);
    v_12087 = qcdr(v_12087);
    v_12087 = qcdr(v_12087);
    v_12087 = qcdr(v_12087);
    stack[-10] = v_12087;
    goto v_12052;
v_12046:
    stack[-3] = elt(env, 1); // !!
    goto v_12047;
v_12048:
    stack[-2] = elt(env, 7); // !:
    goto v_12049;
v_12050:
    goto v_12062;
v_12056:
    stack[-1] = elt(env, 1); // !!
    goto v_12057;
v_12058:
    stack[0] = elt(env, 3); // ! 
    goto v_12059;
v_12060:
    goto v_12072;
v_12066:
    v_12089 = elt(env, 1); // !!
    goto v_12067;
v_12068:
    v_12088 = elt(env, 8); // !(
    goto v_12069;
v_12070:
    v_12087 = stack[-10];
    goto v_12071;
v_12072:
    goto v_12066;
v_12067:
    goto v_12068;
v_12069:
    goto v_12070;
v_12071:
    v_12087 = list2star(v_12089, v_12088, v_12087);
    env = stack[-11];
    goto v_12061;
v_12062:
    goto v_12056;
v_12057:
    goto v_12058;
v_12059:
    goto v_12060;
v_12061:
    v_12087 = list2star(stack[-1], stack[0], v_12087);
    env = stack[-11];
    goto v_12051;
v_12052:
    goto v_12046;
v_12047:
    goto v_12048;
v_12049:
    goto v_12050;
v_12051:
    v_12087 = list2star(stack[-3], stack[-2], v_12087);
    env = stack[-11];
    stack[-10] = v_12087;
    goto v_12081;
v_12077:
    v_12087 = stack[-9];
    v_12088 = Lexplode(nil, v_12087);
    env = stack[-11];
    goto v_12078;
v_12079:
    v_12087 = stack[-10];
    goto v_12080;
v_12081:
    goto v_12077;
v_12078:
    goto v_12079;
v_12080:
    v_12087 = Lnconc(nil, v_12088, v_12087);
    stack[-10] = v_12087;
    v_12087 = stack[-10];
        return Lcompress(nil, v_12087);
    return onevalue(v_12087);
}



// Code for mv!-domainlist

static LispObject CC_mvKdomainlist(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_11961, v_11962;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11934);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_11934;
// end of prologue
    v_11962 = nil;
v_11939:
    v_11961 = stack[0];
    if (v_11961 == nil) goto v_11942;
    else goto v_11943;
v_11942:
    v_11961 = v_11962;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_11961);
    }
v_11943:
    goto v_11954;
v_11950:
    v_11961 = stack[0];
    v_11961 = qcar(v_11961);
    v_11961 = qcdr(v_11961);
    goto v_11951;
v_11952:
    goto v_11953;
v_11954:
    goto v_11950;
v_11951:
    goto v_11952;
v_11953:
    v_11961 = cons(v_11961, v_11962);
    env = stack[-1];
    v_11962 = v_11961;
    v_11961 = stack[0];
    v_11961 = qcdr(v_11961);
    stack[0] = v_11961;
    goto v_11939;
    v_11961 = nil;
    return onevalue(v_11961);
}



// Code for rnprep!:

static LispObject CC_rnprepT(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_11971, v_11972, v_11973;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11934);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_11934;
// end of prologue
    v_11971 = stack[-1];
    v_11971 = qcdr(v_11971);
    v_11971 = qcar(v_11971);
    fn = elt(env, 2); // prepf
    v_11971 = (*qfn1(fn))(fn, v_11971);
    env = stack[-3];
    v_11973 = v_11971;
    goto v_11949;
v_11945:
    v_11971 = stack[-1];
    v_11971 = qcdr(v_11971);
    v_11972 = qcdr(v_11971);
    goto v_11946;
v_11947:
    v_11971 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11948;
v_11949:
    goto v_11945;
v_11946:
    goto v_11947;
v_11948:
    if (v_11972 == v_11971) goto v_11943;
    else goto v_11944;
v_11943:
    v_11971 = v_11973;
    goto v_11942;
v_11944:
    goto v_11964;
v_11958:
    stack[-2] = elt(env, 1); // quotient
    goto v_11959;
v_11960:
    stack[0] = v_11973;
    goto v_11961;
v_11962:
    v_11971 = stack[-1];
    v_11971 = qcdr(v_11971);
    v_11971 = qcdr(v_11971);
    fn = elt(env, 2); // prepf
    v_11971 = (*qfn1(fn))(fn, v_11971);
    goto v_11963;
v_11964:
    goto v_11958;
v_11959:
    goto v_11960;
v_11961:
    goto v_11962;
v_11963:
    {
        LispObject v_11977 = stack[-2];
        LispObject v_11978 = stack[0];
        return list3(v_11977, v_11978, v_11971);
    }
    v_11971 = nil;
v_11942:
    return onevalue(v_11971);
}



// Code for mkcr

static LispObject CC_mkcr(LispObject env,
                         LispObject v_11934, LispObject v_11935)
{
    env = qenv(env);
    LispObject v_11950;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11935,v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11934,v_11935);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_11935;
    v_11950 = v_11934;
// end of prologue
    goto v_11944;
v_11938:
    stack[-2] = elt(env, 1); // !:cr!:
    goto v_11939;
v_11940:
    fn = elt(env, 2); // striptag
    stack[0] = (*qfn1(fn))(fn, v_11950);
    env = stack[-3];
    goto v_11941;
v_11942:
    v_11950 = stack[-1];
    fn = elt(env, 2); // striptag
    v_11950 = (*qfn1(fn))(fn, v_11950);
    goto v_11943;
v_11944:
    goto v_11938;
v_11939:
    goto v_11940;
v_11941:
    goto v_11942;
v_11943:
    {
        LispObject v_11954 = stack[-2];
        LispObject v_11955 = stack[0];
        return list2star(v_11954, v_11955, v_11950);
    }
}



// Code for lalr_prin_rhs

static LispObject CC_lalr_prin_rhs(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_11965, v_11966;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11934);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_11966 = v_11934;
// end of prologue
    v_11965 = v_11966;
    if (v_11965 == nil) goto v_11938;
    else goto v_11939;
v_11938:
    v_11965 = elt(env, 1); // "<empty>"
        return Lprinc(nil, v_11965);
v_11939:
    v_11965 = v_11966;
    stack[0] = v_11965;
v_11948:
    v_11965 = stack[0];
    if (v_11965 == nil) goto v_11952;
    else goto v_11953;
v_11952:
    v_11965 = nil;
    goto v_11947;
v_11953:
    v_11965 = stack[0];
    v_11965 = qcar(v_11965);
    fn = elt(env, 3); // lalr_prin_symbol
    v_11965 = (*qfn1(fn))(fn, v_11965);
    env = stack[-1];
    v_11965 = elt(env, 2); // " "
    v_11965 = Lprinc(nil, v_11965);
    env = stack[-1];
    v_11965 = stack[0];
    v_11965 = qcdr(v_11965);
    stack[0] = v_11965;
    goto v_11948;
v_11947:
    goto v_11937;
    v_11965 = nil;
v_11937:
    return onevalue(v_11965);
}



// Code for ofsf_varlat

static LispObject CC_ofsf_varlat(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_11999, v_12000;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11934);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_11999 = v_11934;
// end of prologue
    v_11999 = qcdr(v_11999);
    v_11999 = qcar(v_11999);
    fn = elt(env, 2); // kernels
    v_11999 = (*qfn1(fn))(fn, v_11999);
    env = stack[-4];
    v_12000 = v_11999;
    v_11999 = qvalue(elt(env, 1)); // !*rlbrkcxk
    if (v_11999 == nil) goto v_11946;
    v_11999 = v_12000;
    stack[-3] = v_11999;
v_11953:
    v_11999 = stack[-3];
    if (v_11999 == nil) goto v_11958;
    else goto v_11959;
v_11958:
    v_11999 = nil;
    goto v_11952;
v_11959:
    v_11999 = stack[-3];
    v_11999 = qcar(v_11999);
    fn = elt(env, 3); // lto_lpvarl
    v_11999 = (*qfn1(fn))(fn, v_11999);
    env = stack[-4];
    stack[-2] = v_11999;
    v_11999 = stack[-2];
    fn = elt(env, 4); // lastpair
    v_11999 = (*qfn1(fn))(fn, v_11999);
    env = stack[-4];
    stack[-1] = v_11999;
    v_11999 = stack[-3];
    v_11999 = qcdr(v_11999);
    stack[-3] = v_11999;
    v_11999 = stack[-1];
    if (!consp(v_11999)) goto v_11973;
    else goto v_11974;
v_11973:
    goto v_11953;
v_11974:
v_11954:
    v_11999 = stack[-3];
    if (v_11999 == nil) goto v_11978;
    else goto v_11979;
v_11978:
    v_11999 = stack[-2];
    goto v_11952;
v_11979:
    goto v_11987;
v_11983:
    stack[0] = stack[-1];
    goto v_11984;
v_11985:
    v_11999 = stack[-3];
    v_11999 = qcar(v_11999);
    fn = elt(env, 3); // lto_lpvarl
    v_11999 = (*qfn1(fn))(fn, v_11999);
    env = stack[-4];
    goto v_11986;
v_11987:
    goto v_11983;
v_11984:
    goto v_11985;
v_11986:
    v_11999 = Lrplacd(nil, stack[0], v_11999);
    env = stack[-4];
    v_11999 = stack[-1];
    fn = elt(env, 4); // lastpair
    v_11999 = (*qfn1(fn))(fn, v_11999);
    env = stack[-4];
    stack[-1] = v_11999;
    v_11999 = stack[-3];
    v_11999 = qcdr(v_11999);
    stack[-3] = v_11999;
    goto v_11954;
v_11952:
    v_12000 = v_11999;
    goto v_11944;
v_11946:
v_11944:
    v_11999 = v_12000;
    return onevalue(v_11999);
}



// Code for vintersection

static LispObject CC_vintersection(LispObject env,
                         LispObject v_11934, LispObject v_11935)
{
    env = qenv(env);
    LispObject v_12058, v_12059;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11935,v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11934,v_11935);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11935;
    stack[-1] = v_11934;
// end of prologue
v_11933:
    v_12058 = stack[-1];
    if (v_12058 == nil) goto v_11942;
    else goto v_11943;
v_11942:
    v_12058 = nil;
    goto v_11941;
v_11943:
    goto v_11952;
v_11948:
    v_12058 = stack[-1];
    v_12058 = qcar(v_12058);
    v_12059 = qcar(v_12058);
    goto v_11949;
v_11950:
    v_12058 = stack[0];
    goto v_11951;
v_11952:
    goto v_11948;
v_11949:
    goto v_11950;
v_11951:
    v_12058 = Lassoc(nil, v_12059, v_12058);
    stack[-2] = v_12058;
    if (v_12058 == nil) goto v_11946;
    else goto v_11947;
v_11946:
    goto v_11963;
v_11959:
    v_12058 = stack[-1];
    v_12059 = qcdr(v_12058);
    goto v_11960;
v_11961:
    v_12058 = stack[0];
    goto v_11962;
v_11963:
    goto v_11959;
v_11960:
    goto v_11961;
v_11962:
    stack[-1] = v_12059;
    stack[0] = v_12058;
    goto v_11933;
v_11947:
    goto v_11974;
v_11970:
    v_12058 = stack[-1];
    v_12058 = qcar(v_12058);
    v_12059 = qcdr(v_12058);
    goto v_11971;
v_11972:
    v_12058 = stack[-2];
    v_12058 = qcdr(v_12058);
    goto v_11973;
v_11974:
    goto v_11970;
v_11971:
    goto v_11972;
v_11973:
    v_12058 = (LispObject)greaterp2(v_12059, v_12058);
    v_12058 = v_12058 ? lisp_true : nil;
    env = stack[-3];
    if (v_12058 == nil) goto v_11968;
    goto v_11988;
v_11984:
    v_12058 = stack[-2];
    v_12059 = qcdr(v_12058);
    goto v_11985;
v_11986:
    v_12058 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11987;
v_11988:
    goto v_11984;
v_11985:
    goto v_11986;
v_11987:
    if (v_12059 == v_12058) goto v_11982;
    else goto v_11983;
v_11982:
    goto v_11997;
v_11993:
    v_12058 = stack[-1];
    v_12059 = qcdr(v_12058);
    goto v_11994;
v_11995:
    v_12058 = stack[0];
    goto v_11996;
v_11997:
    goto v_11993;
v_11994:
    goto v_11995;
v_11996:
    stack[-1] = v_12059;
    stack[0] = v_12058;
    goto v_11933;
v_11983:
    goto v_12008;
v_12004:
    goto v_12005;
v_12006:
    goto v_12015;
v_12011:
    v_12058 = stack[-1];
    v_12059 = qcdr(v_12058);
    goto v_12012;
v_12013:
    v_12058 = stack[0];
    goto v_12014;
v_12015:
    goto v_12011;
v_12012:
    goto v_12013;
v_12014:
    v_12058 = CC_vintersection(elt(env, 0), v_12059, v_12058);
    goto v_12007;
v_12008:
    goto v_12004;
v_12005:
    goto v_12006;
v_12007:
    {
        LispObject v_12063 = stack[-2];
        return cons(v_12063, v_12058);
    }
    v_12058 = nil;
    goto v_11941;
v_11968:
    goto v_12025;
v_12021:
    v_12058 = stack[-1];
    v_12058 = qcar(v_12058);
    v_12059 = qcdr(v_12058);
    goto v_12022;
v_12023:
    v_12058 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12024;
v_12025:
    goto v_12021;
v_12022:
    goto v_12023;
v_12024:
    if (v_12059 == v_12058) goto v_12019;
    else goto v_12020;
v_12019:
    goto v_12035;
v_12031:
    v_12058 = stack[-1];
    v_12059 = qcdr(v_12058);
    goto v_12032;
v_12033:
    v_12058 = stack[0];
    goto v_12034;
v_12035:
    goto v_12031;
v_12032:
    goto v_12033;
v_12034:
    stack[-1] = v_12059;
    stack[0] = v_12058;
    goto v_11933;
v_12020:
    goto v_12046;
v_12042:
    v_12058 = stack[-1];
    stack[-2] = qcar(v_12058);
    goto v_12043;
v_12044:
    goto v_12054;
v_12050:
    v_12058 = stack[-1];
    v_12059 = qcdr(v_12058);
    goto v_12051;
v_12052:
    v_12058 = stack[0];
    goto v_12053;
v_12054:
    goto v_12050;
v_12051:
    goto v_12052;
v_12053:
    v_12058 = CC_vintersection(elt(env, 0), v_12059, v_12058);
    goto v_12045;
v_12046:
    goto v_12042;
v_12043:
    goto v_12044;
v_12045:
    {
        LispObject v_12064 = stack[-2];
        return cons(v_12064, v_12058);
    }
    v_12058 = nil;
v_11941:
    return onevalue(v_12058);
}



// Code for quotofd

static LispObject CC_quotofd(LispObject env,
                         LispObject v_11934, LispObject v_11935)
{
    env = qenv(env);
    LispObject v_12002, v_12003;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11935,v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11934,v_11935);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11935;
    stack[-2] = v_11934;
// end of prologue
    stack[-3] = nil;
v_11940:
    v_12002 = stack[-2];
    if (v_12002 == nil) goto v_11943;
    else goto v_11944;
v_11943:
    v_12002 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12002);
    }
v_11944:
    v_12002 = stack[-2];
    if (!consp(v_12002)) goto v_11952;
    else goto v_11953;
v_11952:
    v_12002 = lisp_true;
    goto v_11951;
v_11953:
    v_12002 = stack[-2];
    v_12002 = qcar(v_12002);
    v_12002 = (consp(v_12002) ? nil : lisp_true);
    goto v_11951;
    v_12002 = nil;
v_11951:
    if (v_12002 == nil) goto v_11949;
    goto v_11966;
v_11962:
    stack[0] = stack[-3];
    goto v_11963;
v_11964:
    goto v_11973;
v_11969:
    v_12003 = stack[-2];
    goto v_11970;
v_11971:
    v_12002 = stack[-1];
    goto v_11972;
v_11973:
    goto v_11969;
v_11970:
    goto v_11971;
v_11972:
    fn = elt(env, 2); // quotodd
    v_12002 = (*qfn2(fn))(fn, v_12003, v_12002);
    env = stack[-4];
    goto v_11965;
v_11966:
    goto v_11962;
v_11963:
    goto v_11964;
v_11965:
    {
        LispObject v_12008 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_12008, v_12002);
    }
v_11949:
    goto v_11985;
v_11979:
    v_12002 = stack[-2];
    v_12002 = qcar(v_12002);
    stack[0] = qcar(v_12002);
    goto v_11980;
v_11981:
    goto v_11994;
v_11990:
    v_12002 = stack[-2];
    v_12002 = qcar(v_12002);
    v_12003 = qcdr(v_12002);
    goto v_11991;
v_11992:
    v_12002 = stack[-1];
    goto v_11993;
v_11994:
    goto v_11990;
v_11991:
    goto v_11992;
v_11993:
    v_12003 = CC_quotofd(elt(env, 0), v_12003, v_12002);
    env = stack[-4];
    goto v_11982;
v_11983:
    v_12002 = stack[-3];
    goto v_11984;
v_11985:
    goto v_11979;
v_11980:
    goto v_11981;
v_11982:
    goto v_11983;
v_11984:
    v_12002 = acons(stack[0], v_12003, v_12002);
    env = stack[-4];
    stack[-3] = v_12002;
    v_12002 = stack[-2];
    v_12002 = qcdr(v_12002);
    stack[-2] = v_12002;
    goto v_11940;
    v_12002 = nil;
    return onevalue(v_12002);
}



// Code for dm!-gt

static LispObject CC_dmKgt(LispObject env,
                         LispObject v_11934, LispObject v_11935)
{
    env = qenv(env);
    LispObject v_11946, v_11947;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11935,v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11934,v_11935);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_11947 = v_11935;
    v_11946 = v_11934;
// end of prologue
    goto v_11943;
v_11939:
    goto v_11940;
v_11941:
    goto v_11942;
v_11943:
    goto v_11939;
v_11940:
    goto v_11941;
v_11942:
    fn = elt(env, 1); // dm!-difference
    v_11946 = (*qfn2(fn))(fn, v_11947, v_11946);
    env = stack[0];
    {
        fn = elt(env, 2); // !:minusp
        return (*qfn1(fn))(fn, v_11946);
    }
}



// Code for dipcondense

static LispObject CC_dipcondense(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_12025, v_12026;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11934);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_11934;
// end of prologue
    v_12025 = qvalue(elt(env, 1)); // dipevlist!*
    stack[-3] = v_12025;
v_11943:
    v_12025 = stack[-2];
    if (v_12025 == nil) goto v_11946;
    else goto v_11947;
v_11946:
    goto v_11942;
v_11947:
    v_12025 = stack[-2];
    v_12025 = qcar(v_12025);
    stack[-1] = v_12025;
v_11954:
    v_12025 = stack[-3];
    v_12025 = qcdr(v_12025);
    if (v_12025 == nil) goto v_11957;
    goto v_11968;
v_11964:
    v_12025 = stack[-2];
    v_12026 = qcar(v_12025);
    goto v_11965;
v_11966:
    v_12025 = stack[-3];
    v_12025 = qcdr(v_12025);
    v_12025 = qcar(v_12025);
    goto v_11967;
v_11968:
    goto v_11964;
v_11965:
    goto v_11966;
v_11967:
    fn = elt(env, 2); // evcompless!?
    v_12025 = (*qfn2(fn))(fn, v_12026, v_12025);
    env = stack[-4];
    if (v_12025 == nil) goto v_11957;
    goto v_11958;
v_11957:
    goto v_11953;
v_11958:
    v_12025 = stack[-3];
    v_12025 = qcdr(v_12025);
    stack[-3] = v_12025;
    goto v_11954;
v_11953:
    v_12025 = stack[-3];
    v_12025 = qcdr(v_12025);
    if (v_12025 == nil) goto v_11980;
    goto v_11989;
v_11985:
    v_12026 = stack[-1];
    goto v_11986;
v_11987:
    v_12025 = stack[-3];
    v_12025 = qcdr(v_12025);
    v_12025 = qcar(v_12025);
    goto v_11988;
v_11989:
    goto v_11985;
v_11986:
    goto v_11987;
v_11988:
    if (equal(v_12026, v_12025)) goto v_11984;
    else goto v_11980;
v_11984:
    goto v_11999;
v_11995:
    v_12026 = stack[-2];
    goto v_11996;
v_11997:
    v_12025 = stack[-3];
    v_12025 = qcdr(v_12025);
    v_12025 = qcar(v_12025);
    goto v_11998;
v_11999:
    goto v_11995;
v_11996:
    goto v_11997;
v_11998:
    fn = elt(env, 3); // setcar
    v_12025 = (*qfn2(fn))(fn, v_12026, v_12025);
    env = stack[-4];
    goto v_11978;
v_11980:
    goto v_12011;
v_12007:
    stack[0] = stack[-3];
    goto v_12008;
v_12009:
    goto v_12018;
v_12014:
    v_12026 = stack[-1];
    goto v_12015;
v_12016:
    v_12025 = stack[-3];
    v_12025 = qcdr(v_12025);
    goto v_12017;
v_12018:
    goto v_12014;
v_12015:
    goto v_12016;
v_12017:
    v_12025 = cons(v_12026, v_12025);
    env = stack[-4];
    goto v_12010;
v_12011:
    goto v_12007;
v_12008:
    goto v_12009;
v_12010:
    fn = elt(env, 4); // setcdr
    v_12025 = (*qfn2(fn))(fn, stack[0], v_12025);
    env = stack[-4];
    goto v_11978;
v_11978:
    v_12025 = stack[-2];
    v_12025 = qcdr(v_12025);
    v_12025 = qcdr(v_12025);
    stack[-2] = v_12025;
    goto v_11943;
v_11942:
    v_12025 = nil;
    return onevalue(v_12025);
}



// Code for partitexdf

static LispObject CC_partitexdf(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_11940;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11934);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_11940 = v_11934;
// end of prologue
    v_11940 = qcar(v_11940);
    fn = elt(env, 1); // partitop
    v_11940 = (*qfn1(fn))(fn, v_11940);
    env = stack[0];
    {
        fn = elt(env, 2); // exdfpf
        return (*qfn1(fn))(fn, v_11940);
    }
}



// Code for indord2

static LispObject CC_indord2(LispObject env,
                         LispObject v_11934, LispObject v_11935)
{
    env = qenv(env);
    LispObject v_11967, v_11968;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11935,v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11934,v_11935);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_11935;
    stack[-1] = v_11934;
// end of prologue
    goto v_11946;
v_11942:
    v_11968 = stack[-1];
    goto v_11943;
v_11944:
    v_11967 = stack[0];
    goto v_11945;
v_11946:
    goto v_11942;
v_11943:
    goto v_11944;
v_11945:
    fn = elt(env, 1); // indordp
    v_11967 = (*qfn2(fn))(fn, v_11968, v_11967);
    if (v_11967 == nil) goto v_11940;
    goto v_11954;
v_11950:
    v_11968 = stack[-1];
    goto v_11951;
v_11952:
    v_11967 = stack[0];
    goto v_11953;
v_11954:
    goto v_11950;
v_11951:
    goto v_11952;
v_11953:
    return list2(v_11968, v_11967);
v_11940:
    goto v_11964;
v_11960:
    v_11968 = stack[0];
    goto v_11961;
v_11962:
    v_11967 = stack[-1];
    goto v_11963;
v_11964:
    goto v_11960;
v_11961:
    goto v_11962;
v_11963:
    return list2(v_11968, v_11967);
    v_11967 = nil;
    return onevalue(v_11967);
}



// Code for sf2mv1

static LispObject CC_sf2mv1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12047, v_12048, v_12049;
    LispObject fn;
    LispObject v_11936, v_11935, v_11934;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sf2mv1");
    va_start(aa, nargs);
    v_11934 = va_arg(aa, LispObject);
    v_11935 = va_arg(aa, LispObject);
    v_11936 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_11936,v_11935,v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_11934,v_11935,v_11936);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_11936;
    stack[-2] = v_11935;
    stack[-3] = v_11934;
// end of prologue
v_11940:
    v_12047 = stack[-3];
    if (v_12047 == nil) goto v_11943;
    else goto v_11944;
v_11943:
    v_12047 = nil;
    goto v_11939;
v_11944:
    v_12047 = stack[-3];
    if (!consp(v_12047)) goto v_11951;
    else goto v_11952;
v_11951:
    v_12047 = lisp_true;
    goto v_11950;
v_11952:
    v_12047 = stack[-3];
    v_12047 = qcar(v_12047);
    v_12047 = (consp(v_12047) ? nil : lisp_true);
    goto v_11950;
    v_12047 = nil;
v_11950:
    if (v_12047 == nil) goto v_11948;
    goto v_11966;
v_11962:
    goto v_11972;
v_11968:
    stack[0] = stack[-2];
    goto v_11969;
v_11970:
    v_12047 = stack[-1];
    v_12047 = Llength(nil, v_12047);
    env = stack[-5];
    fn = elt(env, 1); // nzeros
    v_12047 = (*qfn1(fn))(fn, v_12047);
    env = stack[-5];
    goto v_11971;
v_11972:
    goto v_11968;
v_11969:
    goto v_11970;
v_11971:
    v_12048 = Lappend(nil, stack[0], v_12047);
    env = stack[-5];
    goto v_11963;
v_11964:
    v_12047 = stack[-3];
    goto v_11965;
v_11966:
    goto v_11962;
v_11963:
    goto v_11964;
v_11965:
    v_12047 = cons(v_12048, v_12047);
    return ncons(v_12047);
v_11948:
    goto v_11984;
v_11980:
    v_12047 = stack[-3];
    v_12047 = qcar(v_12047);
    v_12047 = qcar(v_12047);
    v_12048 = qcar(v_12047);
    goto v_11981;
v_11982:
    v_12047 = stack[-1];
    v_12047 = qcar(v_12047);
    goto v_11983;
v_11984:
    goto v_11980;
v_11981:
    goto v_11982;
v_11983:
    if (equal(v_12048, v_12047)) goto v_11978;
    else goto v_11979;
v_11978:
    goto v_11996;
v_11992:
    goto v_12004;
v_11998:
    v_12047 = stack[-3];
    v_12047 = qcar(v_12047);
    stack[-4] = qcdr(v_12047);
    goto v_11999;
v_12000:
    goto v_12013;
v_12009:
    stack[0] = stack[-2];
    goto v_12010;
v_12011:
    v_12047 = stack[-3];
    v_12047 = qcar(v_12047);
    v_12047 = qcar(v_12047);
    v_12047 = qcdr(v_12047);
    v_12047 = ncons(v_12047);
    env = stack[-5];
    goto v_12012;
v_12013:
    goto v_12009;
v_12010:
    goto v_12011;
v_12012:
    v_12048 = Lappend(nil, stack[0], v_12047);
    env = stack[-5];
    goto v_12001;
v_12002:
    v_12047 = stack[-1];
    v_12047 = qcdr(v_12047);
    goto v_12003;
v_12004:
    goto v_11998;
v_11999:
    goto v_12000;
v_12001:
    goto v_12002;
v_12003:
    stack[0] = CC_sf2mv1(elt(env, 0), 3, stack[-4], v_12048, v_12047);
    env = stack[-5];
    goto v_11993;
v_11994:
    goto v_12029;
v_12023:
    v_12047 = stack[-3];
    v_12049 = qcdr(v_12047);
    goto v_12024;
v_12025:
    v_12048 = stack[-2];
    goto v_12026;
v_12027:
    v_12047 = stack[-1];
    goto v_12028;
v_12029:
    goto v_12023;
v_12024:
    goto v_12025;
v_12026:
    goto v_12027;
v_12028:
    v_12047 = CC_sf2mv1(elt(env, 0), 3, v_12049, v_12048, v_12047);
    goto v_11995;
v_11996:
    goto v_11992;
v_11993:
    goto v_11994;
v_11995:
    {
        LispObject v_12055 = stack[0];
        return Lappend(nil, v_12055, v_12047);
    }
v_11979:
    goto v_12041;
v_12037:
    stack[0] = stack[-2];
    goto v_12038;
v_12039:
    v_12047 = (LispObject)0+TAG_FIXNUM; // 0
    v_12047 = ncons(v_12047);
    env = stack[-5];
    goto v_12040;
v_12041:
    goto v_12037;
v_12038:
    goto v_12039;
v_12040:
    v_12047 = Lappend(nil, stack[0], v_12047);
    env = stack[-5];
    stack[-2] = v_12047;
    v_12047 = stack[-1];
    v_12047 = qcdr(v_12047);
    stack[-1] = v_12047;
    goto v_11940;
    v_12047 = nil;
v_11939:
    return onevalue(v_12047);
}



// Code for !:rn2rd

static LispObject CC_Trn2rd(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_11949, v_11950;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11950 = v_11934;
// end of prologue
    v_11949 = qvalue(elt(env, 1)); // !*roundall
    if (v_11949 == nil) goto v_11939;
    v_11949 = qvalue(elt(env, 2)); // !*rounded
    if (v_11949 == nil) goto v_11939;
    v_11949 = v_11950;
    {
        fn = elt(env, 3); // !*rn2rd
        return (*qfn1(fn))(fn, v_11949);
    }
v_11939:
    v_11949 = v_11950;
    goto v_11937;
    v_11949 = nil;
v_11937:
    return onevalue(v_11949);
}



// Code for groeb!=weight

static LispObject CC_groebMweight(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11956;
    LispObject fn;
    LispObject v_11936, v_11935, v_11934;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "groeb=weight");
    va_start(aa, nargs);
    v_11934 = va_arg(aa, LispObject);
    v_11935 = va_arg(aa, LispObject);
    v_11936 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_11936,v_11935,v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_11934,v_11935,v_11936);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11936;
    stack[-1] = v_11935;
    v_11956 = v_11934;
// end of prologue
    goto v_11943;
v_11939:
    fn = elt(env, 1); // mo_ecart
    stack[-2] = (*qfn1(fn))(fn, v_11956);
    env = stack[-3];
    goto v_11940;
v_11941:
    goto v_11951;
v_11947:
    v_11956 = stack[-1];
    fn = elt(env, 2); // bas_dpecart
    stack[-1] = (*qfn1(fn))(fn, v_11956);
    env = stack[-3];
    goto v_11948;
v_11949:
    v_11956 = stack[0];
    fn = elt(env, 2); // bas_dpecart
    v_11956 = (*qfn1(fn))(fn, v_11956);
    env = stack[-3];
    goto v_11950;
v_11951:
    goto v_11947;
v_11948:
    goto v_11949;
v_11950:
    v_11956 = Lmin2(nil, stack[-1], v_11956);
    goto v_11942;
v_11943:
    goto v_11939;
v_11940:
    goto v_11941;
v_11942:
    {
        LispObject v_11960 = stack[-2];
        return plus2(v_11960, v_11956);
    }
}



// Code for tensorp

static LispObject CC_tensorp(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_11953, v_11954;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11954 = v_11934;
// end of prologue
    v_11953 = v_11954;
    if (!consp(v_11953)) goto v_11939;
    goto v_11946;
v_11942:
    v_11953 = v_11954;
    v_11953 = qcar(v_11953);
    goto v_11943;
v_11944:
    v_11954 = elt(env, 1); // tensor
    goto v_11945;
v_11946:
    goto v_11942;
v_11943:
    goto v_11944;
v_11945:
        return Lflagp(nil, v_11953, v_11954);
v_11939:
    v_11953 = nil;
    goto v_11937;
    v_11953 = nil;
v_11937:
    return onevalue(v_11953);
}



// Code for reducepowers

static LispObject CC_reducepowers(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_12066, v_12067;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11934);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11934;
// end of prologue
v_11938:
    v_12066 = stack[0];
    if (!consp(v_12066)) goto v_11949;
    else goto v_11950;
v_11949:
    v_12066 = lisp_true;
    goto v_11948;
v_11950:
    v_12066 = stack[0];
    v_12066 = qcar(v_12066);
    v_12066 = (consp(v_12066) ? nil : lisp_true);
    goto v_11948;
    v_12066 = nil;
v_11948:
    if (v_12066 == nil) goto v_11946;
    v_12066 = lisp_true;
    goto v_11944;
v_11946:
    goto v_11966;
v_11962:
    v_12066 = stack[0];
    v_12066 = qcar(v_12066);
    v_12066 = qcar(v_12066);
    v_12067 = qcdr(v_12066);
    goto v_11963;
v_11964:
    v_12066 = qvalue(elt(env, 1)); // repowl!*
    v_12066 = qcar(v_12066);
    v_12066 = qcdr(v_12066);
    goto v_11965;
v_11966:
    goto v_11962;
v_11963:
    goto v_11964;
v_11965:
    v_12066 = (LispObject)lessp2(v_12067, v_12066);
    v_12066 = v_12066 ? lisp_true : nil;
    env = stack[-2];
    goto v_11944;
    v_12066 = nil;
v_11944:
    if (v_12066 == nil) goto v_11942;
    v_12066 = stack[0];
    goto v_11937;
v_11942:
    goto v_11981;
v_11977:
    v_12066 = stack[0];
    v_12066 = qcar(v_12066);
    v_12066 = qcar(v_12066);
    v_12067 = qcdr(v_12066);
    goto v_11978;
v_11979:
    v_12066 = qvalue(elt(env, 1)); // repowl!*
    v_12066 = qcar(v_12066);
    v_12066 = qcdr(v_12066);
    goto v_11980;
v_11981:
    goto v_11977;
v_11978:
    goto v_11979;
v_11980:
    if (equal(v_12067, v_12066)) goto v_11975;
    else goto v_11976;
v_11975:
    goto v_11994;
v_11990:
    goto v_12000;
v_11996:
    v_12066 = qvalue(elt(env, 1)); // repowl!*
    v_12067 = qcdr(v_12066);
    goto v_11997;
v_11998:
    v_12066 = stack[0];
    v_12066 = qcar(v_12066);
    v_12066 = qcdr(v_12066);
    goto v_11999;
v_12000:
    goto v_11996;
v_11997:
    goto v_11998;
v_11999:
    fn = elt(env, 2); // multf
    v_12067 = (*qfn2(fn))(fn, v_12067, v_12066);
    env = stack[-2];
    goto v_11991;
v_11992:
    v_12066 = stack[0];
    v_12066 = qcdr(v_12066);
    goto v_11993;
v_11994:
    goto v_11990;
v_11991:
    goto v_11992;
v_11993:
    {
        fn = elt(env, 3); // addf
        return (*qfn2(fn))(fn, v_12067, v_12066);
    }
v_11976:
    goto v_12015;
v_12011:
    goto v_12021;
v_12017:
    goto v_12027;
v_12023:
    goto v_12034;
v_12030:
    goto v_12040;
v_12036:
    v_12066 = stack[0];
    v_12066 = qcar(v_12066);
    v_12066 = qcar(v_12066);
    stack[-1] = qcar(v_12066);
    goto v_12037;
v_12038:
    goto v_12050;
v_12046:
    v_12066 = stack[0];
    v_12066 = qcar(v_12066);
    v_12066 = qcar(v_12066);
    v_12067 = qcdr(v_12066);
    goto v_12047;
v_12048:
    v_12066 = qvalue(elt(env, 1)); // repowl!*
    v_12066 = qcar(v_12066);
    v_12066 = qcdr(v_12066);
    goto v_12049;
v_12050:
    goto v_12046;
v_12047:
    goto v_12048;
v_12049:
    v_12066 = difference2(v_12067, v_12066);
    env = stack[-2];
    goto v_12039;
v_12040:
    goto v_12036;
v_12037:
    goto v_12038;
v_12039:
    fn = elt(env, 4); // to
    v_12067 = (*qfn2(fn))(fn, stack[-1], v_12066);
    env = stack[-2];
    goto v_12031;
v_12032:
    v_12066 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12033;
v_12034:
    goto v_12030;
v_12031:
    goto v_12032;
v_12033:
    v_12066 = cons(v_12067, v_12066);
    env = stack[-2];
    v_12067 = ncons(v_12066);
    env = stack[-2];
    goto v_12024;
v_12025:
    v_12066 = stack[0];
    v_12066 = qcar(v_12066);
    v_12066 = qcdr(v_12066);
    goto v_12026;
v_12027:
    goto v_12023;
v_12024:
    goto v_12025;
v_12026:
    fn = elt(env, 2); // multf
    v_12067 = (*qfn2(fn))(fn, v_12067, v_12066);
    env = stack[-2];
    goto v_12018;
v_12019:
    v_12066 = qvalue(elt(env, 1)); // repowl!*
    v_12066 = qcdr(v_12066);
    goto v_12020;
v_12021:
    goto v_12017;
v_12018:
    goto v_12019;
v_12020:
    fn = elt(env, 2); // multf
    v_12067 = (*qfn2(fn))(fn, v_12067, v_12066);
    env = stack[-2];
    goto v_12012;
v_12013:
    v_12066 = stack[0];
    v_12066 = qcdr(v_12066);
    goto v_12014;
v_12015:
    goto v_12011;
v_12012:
    goto v_12013;
v_12014:
    fn = elt(env, 3); // addf
    v_12066 = (*qfn2(fn))(fn, v_12067, v_12066);
    env = stack[-2];
    stack[0] = v_12066;
    goto v_11938;
    v_12066 = nil;
v_11937:
    return onevalue(v_12066);
}



// Code for general!-reciprocal!-by!-gcd

static LispObject CC_generalKreciprocalKbyKgcd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12040, v_12041, v_12042;
    LispObject fn;
    LispObject v_11937, v_11936, v_11935, v_11934;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "general-reciprocal-by-gcd");
    va_start(aa, nargs);
    v_11934 = va_arg(aa, LispObject);
    v_11935 = va_arg(aa, LispObject);
    v_11936 = va_arg(aa, LispObject);
    v_11937 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_11937,v_11936,v_11935,v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_11934,v_11935,v_11936,v_11937);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_11937;
    stack[-2] = v_11936;
    stack[-3] = v_11935;
    stack[-4] = v_11934;
// end of prologue
v_11943:
    goto v_11952;
v_11948:
    v_12041 = stack[-3];
    goto v_11949;
v_11950:
    v_12040 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11951;
v_11952:
    goto v_11948;
v_11949:
    goto v_11950;
v_11951:
    if (v_12041 == v_12040) goto v_11946;
    else goto v_11947;
v_11946:
    goto v_11962;
v_11956:
    v_12042 = elt(env, 1); // alg
    goto v_11957;
v_11958:
    v_12041 = (LispObject)128+TAG_FIXNUM; // 8
    goto v_11959;
v_11960:
    v_12040 = elt(env, 2); // "Invalid modular division"
    goto v_11961;
v_11962:
    goto v_11956;
v_11957:
    goto v_11958;
v_11959:
    goto v_11960;
v_11961:
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_12042, v_12041, v_12040);
    }
v_11947:
    goto v_11972;
v_11968:
    v_12041 = stack[-3];
    goto v_11969;
v_11970:
    v_12040 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11971;
v_11972:
    goto v_11968;
v_11969:
    goto v_11970;
v_11971:
    if (v_12041 == v_12040) goto v_11966;
    else goto v_11967;
v_11966:
    goto v_11984;
v_11980:
    v_12041 = stack[-1];
    goto v_11981;
v_11982:
    v_12040 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11983;
v_11984:
    goto v_11980;
v_11981:
    goto v_11982;
v_11983:
    v_12040 = (LispObject)lessp2(v_12041, v_12040);
    v_12040 = v_12040 ? lisp_true : nil;
    env = stack[-6];
    if (v_12040 == nil) goto v_11978;
    goto v_11992;
v_11988:
    v_12040 = stack[-1];
    goto v_11989;
v_11990:
    v_12041 = qvalue(elt(env, 3)); // current!-modulus
    goto v_11991;
v_11992:
    goto v_11988;
v_11989:
    goto v_11990;
v_11991:
    return plus2(v_12040, v_12041);
v_11978:
    v_12040 = stack[-1];
    goto v_11976;
    v_12040 = nil;
v_11976:
    goto v_11942;
v_11967:
    goto v_12003;
v_11999:
    v_12041 = stack[-4];
    goto v_12000;
v_12001:
    v_12040 = stack[-3];
    goto v_12002;
v_12003:
    goto v_11999;
v_12000:
    goto v_12001;
v_12002:
    v_12040 = quot2(v_12041, v_12040);
    env = stack[-6];
    stack[-5] = v_12040;
    v_12040 = stack[-4];
    v_12041 = v_12040;
    v_12040 = stack[-3];
    stack[-4] = v_12040;
    goto v_12013;
v_12009:
    stack[0] = v_12041;
    goto v_12010;
v_12011:
    goto v_12020;
v_12016:
    v_12041 = stack[-3];
    goto v_12017;
v_12018:
    v_12040 = stack[-5];
    goto v_12019;
v_12020:
    goto v_12016;
v_12017:
    goto v_12018;
v_12019:
    v_12040 = times2(v_12041, v_12040);
    env = stack[-6];
    goto v_12012;
v_12013:
    goto v_12009;
v_12010:
    goto v_12011;
v_12012:
    v_12040 = difference2(stack[0], v_12040);
    env = stack[-6];
    stack[-3] = v_12040;
    v_12040 = stack[-2];
    v_12041 = v_12040;
    v_12040 = stack[-1];
    stack[-2] = v_12040;
    goto v_12030;
v_12026:
    stack[0] = v_12041;
    goto v_12027;
v_12028:
    goto v_12037;
v_12033:
    v_12041 = stack[-1];
    goto v_12034;
v_12035:
    v_12040 = stack[-5];
    goto v_12036;
v_12037:
    goto v_12033;
v_12034:
    goto v_12035;
v_12036:
    v_12040 = times2(v_12041, v_12040);
    env = stack[-6];
    goto v_12029;
v_12030:
    goto v_12026;
v_12027:
    goto v_12028;
v_12029:
    v_12040 = difference2(stack[0], v_12040);
    env = stack[-6];
    stack[-1] = v_12040;
    goto v_11943;
v_11942:
    return onevalue(v_12040);
}



// Code for exc

static LispObject CC_exc(LispObject env,
                         LispObject v_11934, LispObject v_11935)
{
    env = qenv(env);
    LispObject v_11948, v_11949;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11948 = v_11935;
    v_11949 = v_11934;
// end of prologue
    v_11949 = qcdr(v_11949);
    if (v_11949 == nil) goto v_11939;
    else goto v_11940;
v_11939:
    goto v_11938;
v_11940:
    v_11948 = (v_11948 == nil ? lisp_true : nil);
    goto v_11938;
    v_11948 = nil;
v_11938:
    return onevalue(v_11948);
}



// Code for lalr_precalculate_first_sets

static LispObject CC_lalr_precalculate_first_sets(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12121, v_12122, v_12123;
    LispObject fn;
    argcheck(nargs, 0, "lalr_precalculate_first_sets");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// end of prologue
    stack[-3] = nil;
v_11943:
    v_12121 = nil;
    stack[-6] = v_12121;
    v_12121 = qvalue(elt(env, 1)); // nonterminals
    stack[-2] = v_12121;
v_11948:
    v_12121 = stack[-2];
    if (v_12121 == nil) goto v_11952;
    else goto v_11953;
v_11952:
    goto v_11947;
v_11953:
    v_12121 = stack[-2];
    v_12121 = qcar(v_12121);
    stack[-1] = v_12121;
    goto v_11964;
v_11960:
    v_12122 = stack[-1];
    goto v_11961;
v_11962:
    v_12121 = elt(env, 2); // lalr_first
    goto v_11963;
v_11964:
    goto v_11960;
v_11961:
    goto v_11962;
v_11963:
    v_12121 = get(v_12122, v_12121);
    env = stack[-7];
    stack[-5] = v_12121;
    v_12121 = stack[-1];
    fn = elt(env, 4); // lalr_productions
    v_12121 = (*qfn1(fn))(fn, v_12121);
    env = stack[-7];
    stack[0] = v_12121;
v_11970:
    v_12121 = stack[0];
    if (v_12121 == nil) goto v_11975;
    else goto v_11976;
v_11975:
    goto v_11969;
v_11976:
    v_12121 = stack[0];
    v_12121 = qcar(v_12121);
    v_12121 = qcar(v_12121);
    stack[-4] = v_12121;
v_11986:
    v_12121 = stack[-4];
    if (v_12121 == nil) goto v_11989;
    v_12121 = stack[-4];
    v_12121 = qcar(v_12121);
    if (is_number(v_12121)) goto v_11997;
    goto v_12004;
v_12000:
    v_12123 = nil;
    goto v_12001;
v_12002:
    goto v_12011;
v_12007:
    v_12121 = stack[-4];
    v_12122 = qcar(v_12121);
    goto v_12008;
v_12009:
    v_12121 = elt(env, 2); // lalr_first
    goto v_12010;
v_12011:
    goto v_12007;
v_12008:
    goto v_12009;
v_12010:
    v_12121 = get(v_12122, v_12121);
    env = stack[-7];
    stack[-3] = v_12121;
    goto v_12003;
v_12004:
    goto v_12000;
v_12001:
    goto v_12002;
v_12003:
    v_12121 = Lmember(nil, v_12123, v_12121);
    goto v_11995;
v_11997:
    v_12121 = nil;
    goto v_11995;
    v_12121 = nil;
v_11995:
    if (v_12121 == nil) goto v_11989;
    goto v_11990;
v_11989:
    goto v_11985;
v_11990:
    goto v_12025;
v_12021:
    goto v_12031;
v_12027:
    v_12122 = nil;
    goto v_12028;
v_12029:
    v_12121 = stack[-3];
    goto v_12030;
v_12031:
    goto v_12027;
v_12028:
    goto v_12029;
v_12030:
    v_12122 = Ldeleq(nil, v_12122, v_12121);
    env = stack[-7];
    goto v_12022;
v_12023:
    v_12121 = stack[-5];
    goto v_12024;
v_12025:
    goto v_12021;
v_12022:
    goto v_12023;
v_12024:
    fn = elt(env, 5); // union
    v_12121 = (*qfn2(fn))(fn, v_12122, v_12121);
    env = stack[-7];
    stack[-5] = v_12121;
    v_12121 = stack[-4];
    v_12121 = qcdr(v_12121);
    stack[-4] = v_12121;
    goto v_11986;
v_11985:
    v_12121 = stack[-4];
    if (v_12121 == nil) goto v_12039;
    else goto v_12040;
v_12039:
    goto v_12047;
v_12043:
    v_12122 = elt(env, 3); // (nil)
    goto v_12044;
v_12045:
    v_12121 = stack[-5];
    goto v_12046;
v_12047:
    goto v_12043;
v_12044:
    goto v_12045;
v_12046:
    fn = elt(env, 5); // union
    v_12121 = (*qfn2(fn))(fn, v_12122, v_12121);
    env = stack[-7];
    stack[-5] = v_12121;
    goto v_12038;
v_12040:
    v_12121 = stack[-4];
    v_12121 = qcar(v_12121);
    if (is_number(v_12121)) goto v_12050;
    else goto v_12051;
v_12050:
    goto v_12059;
v_12055:
    v_12121 = stack[-4];
    v_12121 = qcar(v_12121);
    v_12122 = ncons(v_12121);
    env = stack[-7];
    goto v_12056;
v_12057:
    v_12121 = stack[-5];
    goto v_12058;
v_12059:
    goto v_12055;
v_12056:
    goto v_12057;
v_12058:
    fn = elt(env, 5); // union
    v_12121 = (*qfn2(fn))(fn, v_12122, v_12121);
    env = stack[-7];
    stack[-5] = v_12121;
    goto v_12038;
v_12051:
    goto v_12071;
v_12067:
    goto v_12077;
v_12073:
    v_12121 = stack[-4];
    v_12122 = qcar(v_12121);
    goto v_12074;
v_12075:
    v_12121 = elt(env, 2); // lalr_first
    goto v_12076;
v_12077:
    goto v_12073;
v_12074:
    goto v_12075;
v_12076:
    v_12122 = get(v_12122, v_12121);
    env = stack[-7];
    goto v_12068;
v_12069:
    v_12121 = stack[-5];
    goto v_12070;
v_12071:
    goto v_12067;
v_12068:
    goto v_12069;
v_12070:
    fn = elt(env, 5); // union
    v_12121 = (*qfn2(fn))(fn, v_12122, v_12121);
    env = stack[-7];
    stack[-5] = v_12121;
    goto v_12038;
v_12038:
    v_12121 = stack[0];
    v_12121 = qcdr(v_12121);
    stack[0] = v_12121;
    goto v_11970;
v_11969:
    goto v_12092;
v_12088:
    v_12123 = stack[-5];
    goto v_12089;
v_12090:
    goto v_12099;
v_12095:
    v_12122 = stack[-1];
    goto v_12096;
v_12097:
    v_12121 = elt(env, 2); // lalr_first
    goto v_12098;
v_12099:
    goto v_12095;
v_12096:
    goto v_12097;
v_12098:
    v_12121 = get(v_12122, v_12121);
    env = stack[-7];
    goto v_12091;
v_12092:
    goto v_12088;
v_12089:
    goto v_12090;
v_12091:
    if (equal(v_12123, v_12121)) goto v_12087;
    v_12121 = lisp_true;
    stack[-6] = v_12121;
    goto v_12110;
v_12104:
    v_12123 = stack[-1];
    goto v_12105;
v_12106:
    v_12122 = elt(env, 2); // lalr_first
    goto v_12107;
v_12108:
    v_12121 = stack[-5];
    goto v_12109;
v_12110:
    goto v_12104;
v_12105:
    goto v_12106;
v_12107:
    goto v_12108;
v_12109:
    v_12121 = Lputprop(nil, 3, v_12123, v_12122, v_12121);
    env = stack[-7];
    goto v_12085;
v_12087:
v_12085:
    v_12121 = stack[-2];
    v_12121 = qcdr(v_12121);
    stack[-2] = v_12121;
    goto v_11948;
v_11947:
    v_12121 = stack[-6];
    if (v_12121 == nil) goto v_12119;
    goto v_11943;
v_12119:
    v_12121 = nil;
    return onevalue(v_12121);
}



// Code for sfto_dgcd

static LispObject CC_sfto_dgcd(LispObject env,
                         LispObject v_11934, LispObject v_11935)
{
    env = qenv(env);
    LispObject v_11964, v_11965;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11935,v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11934,v_11935);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11935;
    v_11964 = v_11934;
// end of prologue
    fn = elt(env, 1); // sfto_dcontentf
    v_11964 = (*qfn1(fn))(fn, v_11964);
    env = stack[-2];
    stack[-1] = v_11964;
    goto v_11951;
v_11947:
    v_11965 = stack[-1];
    goto v_11948;
v_11949:
    v_11964 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11950;
v_11951:
    goto v_11947;
v_11948:
    goto v_11949;
v_11950:
    v_11964 = Leqn(nil, v_11965, v_11964);
    env = stack[-2];
    if (v_11964 == nil) goto v_11945;
    v_11964 = stack[-1];
    goto v_11939;
v_11945:
    goto v_11960;
v_11956:
    goto v_11957;
v_11958:
    v_11964 = stack[0];
    fn = elt(env, 1); // sfto_dcontentf
    v_11964 = (*qfn1(fn))(fn, v_11964);
    env = stack[-2];
    goto v_11959;
v_11960:
    goto v_11956;
v_11957:
    goto v_11958;
v_11959:
    {
        LispObject v_11968 = stack[-1];
        fn = elt(env, 2); // sfto_gcdf
        return (*qfn2(fn))(fn, v_11968, v_11964);
    }
v_11939:
    return onevalue(v_11964);
}



// Code for mk!+unit!+mat

static LispObject CC_mkLunitLmat(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_11940;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11940 = v_11934;
// end of prologue
    {
        fn = elt(env, 1); // gen!+can!+bas
        return (*qfn1(fn))(fn, v_11940);
    }
    return onevalue(v_11940);
}



// Code for cl_flip

static LispObject CC_cl_flip(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_12029, v_12030, v_12031;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11934);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12031 = v_11934;
// end of prologue
    goto v_11944;
v_11940:
    v_12030 = v_12031;
    goto v_11941;
v_11942:
    v_12029 = elt(env, 1); // and
    goto v_11943;
v_11944:
    goto v_11940;
v_11941:
    goto v_11942;
v_11943:
    if (v_12030 == v_12029) goto v_11938;
    else goto v_11939;
v_11938:
    v_12029 = elt(env, 2); // or
    goto v_11937;
v_11939:
    goto v_11954;
v_11950:
    v_12030 = v_12031;
    goto v_11951;
v_11952:
    v_12029 = elt(env, 2); // or
    goto v_11953;
v_11954:
    goto v_11950;
v_11951:
    goto v_11952;
v_11953:
    if (v_12030 == v_12029) goto v_11948;
    else goto v_11949;
v_11948:
    v_12029 = elt(env, 1); // and
    goto v_11937;
v_11949:
    goto v_11964;
v_11960:
    v_12030 = v_12031;
    goto v_11961;
v_11962:
    v_12029 = elt(env, 3); // all
    goto v_11963;
v_11964:
    goto v_11960;
v_11961:
    goto v_11962;
v_11963:
    if (v_12030 == v_12029) goto v_11958;
    else goto v_11959;
v_11958:
    v_12029 = elt(env, 4); // ex
    goto v_11937;
v_11959:
    goto v_11974;
v_11970:
    v_12030 = v_12031;
    goto v_11971;
v_11972:
    v_12029 = elt(env, 4); // ex
    goto v_11973;
v_11974:
    goto v_11970;
v_11971:
    goto v_11972;
v_11973:
    if (v_12030 == v_12029) goto v_11968;
    else goto v_11969;
v_11968:
    v_12029 = elt(env, 3); // all
    goto v_11937;
v_11969:
    goto v_11984;
v_11980:
    v_12030 = v_12031;
    goto v_11981;
v_11982:
    v_12029 = elt(env, 5); // ball
    goto v_11983;
v_11984:
    goto v_11980;
v_11981:
    goto v_11982;
v_11983:
    if (v_12030 == v_12029) goto v_11978;
    else goto v_11979;
v_11978:
    v_12029 = elt(env, 6); // bex
    goto v_11937;
v_11979:
    goto v_11994;
v_11990:
    v_12030 = v_12031;
    goto v_11991;
v_11992:
    v_12029 = elt(env, 6); // bex
    goto v_11993;
v_11994:
    goto v_11990;
v_11991:
    goto v_11992;
v_11993:
    if (v_12030 == v_12029) goto v_11988;
    else goto v_11989;
v_11988:
    v_12029 = elt(env, 5); // ball
    goto v_11937;
v_11989:
    goto v_12004;
v_12000:
    v_12030 = v_12031;
    goto v_12001;
v_12002:
    v_12029 = elt(env, 7); // true
    goto v_12003;
v_12004:
    goto v_12000;
v_12001:
    goto v_12002;
v_12003:
    if (v_12030 == v_12029) goto v_11998;
    else goto v_11999;
v_11998:
    v_12029 = elt(env, 8); // false
    goto v_11937;
v_11999:
    goto v_12014;
v_12010:
    v_12030 = v_12031;
    goto v_12011;
v_12012:
    v_12029 = elt(env, 8); // false
    goto v_12013;
v_12014:
    goto v_12010;
v_12011:
    goto v_12012;
v_12013:
    if (v_12030 == v_12029) goto v_12008;
    else goto v_12009;
v_12008:
    v_12029 = elt(env, 7); // true
    goto v_11937;
v_12009:
    goto v_12026;
v_12022:
    v_12029 = elt(env, 9); // "cl_flip(): don't know"
    goto v_12023;
v_12024:
    v_12030 = v_12031;
    goto v_12025;
v_12026:
    goto v_12022;
v_12023:
    goto v_12024;
v_12025:
    v_12029 = list2(v_12029, v_12030);
    env = stack[0];
    {
        fn = elt(env, 10); // rederr
        return (*qfn1(fn))(fn, v_12029);
    }
    v_12029 = nil;
v_11937:
    return onevalue(v_12029);
}



// Code for simprecip

static LispObject CC_simprecip(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_11969, v_11970;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11934);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_11970 = v_11934;
// end of prologue
    v_11969 = qvalue(elt(env, 1)); // !*mcd
    if (v_11969 == nil) goto v_11938;
    else goto v_11939;
v_11938:
    goto v_11947;
v_11943:
    goto v_11953;
v_11949:
    goto v_11950;
v_11951:
    v_11969 = elt(env, 2); // recip
    goto v_11952;
v_11953:
    goto v_11949;
v_11950:
    goto v_11951;
v_11952:
    fn = elt(env, 3); // carx
    v_11970 = (*qfn2(fn))(fn, v_11970, v_11969);
    env = stack[0];
    goto v_11944;
v_11945:
    v_11969 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_11946;
v_11947:
    goto v_11943;
v_11944:
    goto v_11945;
v_11946:
    v_11969 = list2(v_11970, v_11969);
    env = stack[0];
    {
        fn = elt(env, 4); // simpexpt
        return (*qfn1(fn))(fn, v_11969);
    }
v_11939:
    goto v_11966;
v_11962:
    goto v_11963;
v_11964:
    v_11969 = elt(env, 2); // recip
    goto v_11965;
v_11966:
    goto v_11962;
v_11963:
    goto v_11964;
v_11965:
    fn = elt(env, 3); // carx
    v_11969 = (*qfn2(fn))(fn, v_11970, v_11969);
    env = stack[0];
    fn = elt(env, 5); // simp
    v_11969 = (*qfn1(fn))(fn, v_11969);
    env = stack[0];
    {
        fn = elt(env, 6); // invsq
        return (*qfn1(fn))(fn, v_11969);
    }
    v_11969 = nil;
    return onevalue(v_11969);
}



// Code for coordp

static LispObject CC_coordp(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_11944, v_11945;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11944 = v_11934;
// end of prologue
    goto v_11940;
v_11936:
    goto v_11937;
v_11938:
    v_11945 = qvalue(elt(env, 1)); // coord!*
    goto v_11939;
v_11940:
    goto v_11936;
v_11937:
    goto v_11938;
v_11939:
    v_11944 = Lmemq(nil, v_11944, v_11945);
    return onevalue(v_11944);
}



// Code for begin11

static LispObject CC_begin11(LispObject env,
                         LispObject v_11934)
{
    env = qenv(env);
    LispObject v_12476, v_12477;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11934);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11934);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_11934;
// end of prologue
// Binding errmsg!*
// FLUIDBIND: reloadenv=6 litvec-offset=1 saveloc=5
{   bind_fluid_stack bind_fluid_var(-6, 1, -5);
    qvalue(elt(env, 1)) = nil; // errmsg!*
    stack[-3] = nil;
// Binding newrule!*
// FLUIDBIND: reloadenv=6 litvec-offset=2 saveloc=2
{   bind_fluid_stack bind_fluid_var(-6, 2, -2);
    qvalue(elt(env, 2)) = nil; // newrule!*
    goto v_11950;
v_11946:
    v_12477 = qvalue(elt(env, 3)); // cursym!*
    goto v_11947;
v_11948:
    v_12476 = elt(env, 4); // end
    goto v_11949;
v_11950:
    goto v_11946;
v_11947:
    goto v_11948;
v_11949:
    if (v_12477 == v_12476) goto v_11944;
    else goto v_11945;
v_11944:
    fn = elt(env, 47); // terminalp
    v_12476 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    if (v_12476 == nil) goto v_11956;
    v_12476 = qvalue(elt(env, 5)); // !*lisp_hook
    if (v_12476 == nil) goto v_11959;
    else goto v_11956;
v_11959:
    v_12476 = elt(env, 6); // !*semicol!*
    qvalue(elt(env, 3)) = v_12476; // cursym!*
    v_12476 = nil;
    qvalue(elt(env, 7)) = v_12476; // curescaped!*
    v_12476 = lisp_true;
    qvalue(elt(env, 8)) = v_12476; // !*nosave!*
    v_12476 = nil;
    goto v_11941;
v_11956:
    v_12476 = elt(env, 4); // end
    fn = elt(env, 48); // comm1
    v_12476 = (*qfn1(fn))(fn, v_12476);
    env = stack[-6];
    v_12476 = elt(env, 4); // end
    goto v_11941;
    goto v_11943;
v_11945:
    goto v_11977;
v_11973:
    v_12476 = qvalue(elt(env, 9)); // !*reduce4
    if (v_12476 == nil) goto v_11981;
    v_12476 = stack[-4];
    v_12477 = v_12476;
    goto v_11979;
v_11981:
    v_12476 = stack[-4];
    v_12476 = qcdr(v_12476);
    v_12476 = qcar(v_12476);
    v_12477 = v_12476;
    goto v_11979;
    v_12477 = nil;
v_11979:
    goto v_11974;
v_11975:
    v_12476 = elt(env, 10); // retry
    goto v_11976;
v_11977:
    goto v_11973;
v_11974:
    goto v_11975;
v_11976:
    if (!consp(v_12477)) goto v_11971;
    v_12477 = qcar(v_12477);
    if (v_12477 == v_12476) goto v_11970;
    else goto v_11971;
v_11970:
    v_12476 = qvalue(elt(env, 11)); // programl!*
    if (v_12476 == nil) goto v_11993;
    v_12476 = qvalue(elt(env, 11)); // programl!*
    stack[-4] = v_12476;
    goto v_11991;
v_11993:
    v_12476 = elt(env, 12); // "No previous expression"
    fn = elt(env, 49); // lprim
    v_12476 = (*qfn1(fn))(fn, v_12476);
    v_12476 = nil;
    goto v_11941;
v_11991:
    goto v_11943;
v_11971:
v_11943:
    v_12476 = qvalue(elt(env, 9)); // !*reduce4
    if (v_12476 == nil) goto v_12003;
    else goto v_12004;
v_12003:
    v_12476 = stack[-4];
    v_12476 = qcar(v_12476);
    stack[-3] = v_12476;
    v_12476 = stack[-4];
    v_12476 = qcdr(v_12476);
    v_12476 = qcar(v_12476);
    stack[-4] = v_12476;
    goto v_12002;
v_12004:
v_12002:
    v_12476 = stack[-4];
    qvalue(elt(env, 13)) = v_12476; // program!*
    fn = elt(env, 50); // eofcheck
    v_12476 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    if (v_12476 == nil) goto v_12015;
    v_12476 = elt(env, 14); // c
    goto v_11941;
v_12015:
    v_12476 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 15)) = v_12476; // eof!*
    goto v_12013;
v_12013:
    goto v_12026;
v_12022:
    v_12477 = stack[-4];
    goto v_12023;
v_12024:
    v_12476 = qvalue(elt(env, 9)); // !*reduce4
    if (v_12476 == nil) goto v_12031;
    v_12476 = nil;
    goto v_12029;
v_12031:
    v_12476 = stack[-3];
    goto v_12029;
    v_12476 = nil;
v_12029:
    goto v_12025;
v_12026:
    goto v_12022;
v_12023:
    goto v_12024;
v_12025:
    fn = elt(env, 51); // add2inputbuf
    v_12476 = (*qfn2(fn))(fn, v_12477, v_12476);
    env = stack[-6];
    v_12476 = stack[-4];
    if (!consp(v_12476)) goto v_12044;
    goto v_12050;
v_12046:
    v_12476 = stack[-4];
    v_12477 = qcar(v_12476);
    goto v_12047;
v_12048:
    v_12476 = elt(env, 16); // (bye quit)
    goto v_12049;
v_12050:
    goto v_12046;
v_12047:
    goto v_12048;
v_12049:
    v_12476 = Lmemq(nil, v_12477, v_12476);
    goto v_12042;
v_12044:
    v_12476 = nil;
    goto v_12042;
    v_12476 = nil;
v_12042:
    if (v_12476 == nil) goto v_12040;
    v_12476 = elt(env, 17); // bye
    fn = elt(env, 52); // getd
    v_12476 = (*qfn1(fn))(fn, v_12476);
    env = stack[-6];
    if (v_12476 == nil) goto v_12061;
    v_12476 = stack[-4];
    fn = elt(env, 53); // lispeval
    v_12476 = (*qfn1(fn))(fn, v_12476);
    env = stack[-6];
    v_12476 = lisp_true;
    qvalue(elt(env, 8)) = v_12476; // !*nosave!*
    v_12476 = nil;
    goto v_11941;
v_12061:
    v_12476 = lisp_true;
    qvalue(elt(env, 18)) = v_12476; // !*byeflag!*
    v_12476 = nil;
    goto v_11941;
    goto v_12038;
v_12040:
    v_12476 = qvalue(elt(env, 9)); // !*reduce4
    if (v_12476 == nil) goto v_12076;
    else goto v_12077;
v_12076:
    goto v_12084;
v_12080:
    v_12477 = stack[-4];
    goto v_12081;
v_12082:
    v_12476 = elt(env, 19); // ed
    goto v_12083;
v_12084:
    goto v_12080;
v_12081:
    goto v_12082;
v_12083:
    v_12476 = Leqcar(nil, v_12477, v_12476);
    env = stack[-6];
    goto v_12075;
v_12077:
    v_12476 = nil;
    goto v_12075;
    v_12476 = nil;
v_12075:
    if (v_12476 == nil) goto v_12073;
    v_12476 = elt(env, 20); // cedit
    fn = elt(env, 52); // getd
    v_12476 = (*qfn1(fn))(fn, v_12476);
    env = stack[-6];
    if (v_12476 == nil) goto v_12093;
    fn = elt(env, 47); // terminalp
    v_12476 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    if (v_12476 == nil) goto v_12093;
    v_12476 = stack[-4];
    v_12476 = qcdr(v_12476);
    fn = elt(env, 20); // cedit
    v_12476 = (*qfn1(fn))(fn, v_12476);
    env = stack[-6];
    goto v_12091;
v_12093:
    v_12476 = elt(env, 21); // "ED not supported"
    fn = elt(env, 49); // lprim
    v_12476 = (*qfn1(fn))(fn, v_12476);
    env = stack[-6];
    goto v_12091;
v_12091:
    v_12476 = lisp_true;
    qvalue(elt(env, 8)) = v_12476; // !*nosave!*
    v_12476 = nil;
    goto v_11941;
v_12073:
    v_12476 = qvalue(elt(env, 22)); // !*defn
    if (v_12476 == nil) goto v_12109;
    v_12476 = qvalue(elt(env, 23)); // erfg!*
    if (v_12476 == nil) goto v_12114;
    v_12476 = nil;
    goto v_11941;
v_12114:
    goto v_12128;
v_12124:
    v_12477 = qvalue(elt(env, 24)); // key!*
    goto v_12125;
v_12126:
    v_12476 = elt(env, 25); // ignore
    goto v_12127;
v_12128:
    goto v_12124;
v_12125:
    goto v_12126;
v_12127:
    v_12476 = Lflagp(nil, v_12477, v_12476);
    env = stack[-6];
    if (v_12476 == nil) goto v_12121;
    else goto v_12122;
v_12121:
    goto v_12136;
v_12132:
    v_12477 = stack[-4];
    goto v_12133;
v_12134:
    v_12476 = elt(env, 26); // quote
    goto v_12135;
v_12136:
    goto v_12132;
v_12133:
    goto v_12134;
v_12135:
    v_12476 = Leqcar(nil, v_12477, v_12476);
    env = stack[-6];
    v_12476 = (v_12476 == nil ? lisp_true : nil);
    goto v_12120;
v_12122:
    v_12476 = nil;
    goto v_12120;
    v_12476 = nil;
v_12120:
    if (v_12476 == nil) goto v_12118;
    v_12476 = stack[-4];
    if (v_12476 == nil) goto v_12146;
    v_12476 = stack[-4];
    fn = elt(env, 54); // dfprint
    v_12476 = (*qfn1(fn))(fn, v_12476);
    env = stack[-6];
    goto v_12144;
v_12146:
    goto v_12144;
v_12144:
    goto v_12162;
v_12158:
    v_12477 = qvalue(elt(env, 24)); // key!*
    goto v_12159;
v_12160:
    v_12476 = elt(env, 27); // eval
    goto v_12161;
v_12162:
    goto v_12158;
v_12159:
    goto v_12160;
v_12161:
    v_12476 = Lflagp(nil, v_12477, v_12476);
    env = stack[-6];
    if (v_12476 == nil) goto v_12155;
    else goto v_12156;
v_12155:
    v_12476 = nil;
    goto v_11941;
v_12156:
    goto v_12112;
v_12118:
v_12112:
    goto v_12038;
v_12109:
v_12038:
    v_12476 = qvalue(elt(env, 28)); // !*output
    if (v_12476 == nil) goto v_12169;
    v_12476 = qvalue(elt(env, 29)); // ifl!*
    if (v_12476 == nil) goto v_12169;
    v_12476 = qvalue(elt(env, 30)); // !*echo
    if (v_12476 == nil) goto v_12169;
    v_12476 = qvalue(elt(env, 31)); // !*lessspace
    if (v_12476 == nil) goto v_12178;
    else goto v_12169;
v_12178:
    v_12476 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_12167;
v_12169:
v_12167:
    v_12476 = qvalue(elt(env, 32)); // ulimit!*
    v_12476 = integerp(v_12476);
    if (v_12476 == nil) goto v_12184;
    goto v_12192;
v_12188:
    v_12477 = qvalue(elt(env, 32)); // ulimit!*
    goto v_12189;
v_12190:
    v_12476 = stack[-4];
    goto v_12191;
v_12192:
    goto v_12188;
v_12189:
    goto v_12190;
v_12191:
    fn = elt(env, 55); // errorset_with_timeout
    v_12476 = (*qfn2(fn))(fn, v_12477, v_12476);
    env = stack[-6];
    stack[0] = v_12476;
    v_12476 = stack[0];
    if (!consp(v_12476)) goto v_12198;
    v_12476 = stack[0];
    v_12476 = qcar(v_12476);
    stack[0] = v_12476;
    goto v_12196;
v_12198:
v_12196:
    goto v_12182;
v_12184:
    goto v_12209;
v_12205:
    v_12477 = stack[-4];
    goto v_12206;
v_12207:
    v_12476 = lisp_true;
    goto v_12208;
v_12209:
    goto v_12205;
v_12206:
    goto v_12207;
v_12208:
    fn = elt(env, 56); // errorset!*
    v_12476 = (*qfn2(fn))(fn, v_12477, v_12476);
    env = stack[-6];
    stack[0] = v_12476;
    goto v_12182;
v_12182:
    v_12476 = stack[0];
    fn = elt(env, 57); // errorp
    v_12476 = (*qfn1(fn))(fn, v_12476);
    env = stack[-6];
    if (v_12476 == nil) goto v_12216;
    else goto v_12214;
v_12216:
    v_12476 = qvalue(elt(env, 23)); // erfg!*
    if (v_12476 == nil) goto v_12219;
    else goto v_12214;
v_12219:
    goto v_12215;
v_12214:
    goto v_12226;
v_12222:
    v_12477 = stack[-3];
    goto v_12223;
v_12224:
    v_12476 = stack[-4];
    goto v_12225;
v_12226:
    goto v_12222;
v_12223:
    goto v_12224;
v_12225:
    v_12476 = list2(v_12477, v_12476);
    env = stack[-6];
    qvalue(elt(env, 11)) = v_12476; // programl!*
    v_12476 = elt(env, 33); // err2
    goto v_11941;
v_12215:
    v_12476 = qvalue(elt(env, 22)); // !*defn
    if (v_12476 == nil) goto v_12231;
    v_12476 = nil;
    goto v_11941;
v_12231:
    v_12476 = qvalue(elt(env, 9)); // !*reduce4
    if (v_12476 == nil) goto v_12236;
    else goto v_12237;
v_12236:
    goto v_12247;
v_12243:
    v_12477 = stack[-3];
    goto v_12244;
v_12245:
    v_12476 = elt(env, 34); // symbolic
    goto v_12246;
v_12247:
    goto v_12243;
v_12244:
    goto v_12245;
v_12246:
    if (v_12477 == v_12476) goto v_12242;
    v_12476 = stack[-4];
    fn = elt(env, 58); // getsetvars
    v_12476 = (*qfn1(fn))(fn, v_12476);
    env = stack[-6];
    stack[-4] = v_12476;
    goto v_12240;
v_12242:
    goto v_12240;
v_12240:
    goto v_12235;
v_12237:
    v_12476 = stack[0];
    v_12476 = qcar(v_12476);
    stack[0] = v_12476;
    v_12476 = stack[0];
    if (v_12476 == nil) goto v_12261;
    else goto v_12262;
v_12261:
    goto v_12269;
v_12265:
    v_12477 = nil;
    goto v_12266;
v_12267:
    v_12476 = elt(env, 35); // noval
    goto v_12268;
v_12269:
    goto v_12265;
v_12266:
    goto v_12267;
v_12268:
    fn = elt(env, 59); // mkobject
    v_12476 = (*qfn2(fn))(fn, v_12477, v_12476);
    env = stack[-6];
    stack[0] = v_12476;
    goto v_12260;
v_12262:
v_12260:
    v_12476 = stack[0];
    fn = elt(env, 60); // type
    v_12476 = (*qfn1(fn))(fn, v_12476);
    env = stack[-6];
    stack[-3] = v_12476;
    v_12476 = stack[0];
    fn = elt(env, 61); // value
    v_12476 = (*qfn1(fn))(fn, v_12476);
    env = stack[-6];
    stack[0] = v_12476;
    goto v_12235;
v_12235:
    goto v_12281;
v_12277:
    v_12476 = qvalue(elt(env, 9)); // !*reduce4
    if (v_12476 == nil) goto v_12284;
    else goto v_12285;
v_12284:
    v_12476 = stack[0];
    v_12476 = qcar(v_12476);
    v_12477 = v_12476;
    goto v_12283;
v_12285:
    v_12476 = stack[0];
    v_12477 = v_12476;
    goto v_12283;
    v_12477 = nil;
v_12283:
    goto v_12278;
v_12279:
    v_12476 = stack[-3];
    goto v_12280;
v_12281:
    goto v_12277;
v_12278:
    goto v_12279;
v_12280:
    fn = elt(env, 62); // add2resultbuf
    v_12476 = (*qfn2(fn))(fn, v_12477, v_12476);
    env = stack[-6];
    v_12476 = qvalue(elt(env, 28)); // !*output
    if (v_12476 == nil) goto v_12295;
    else goto v_12296;
v_12295:
    v_12476 = nil;
    goto v_11941;
v_12296:
    goto v_12305;
v_12301:
    v_12477 = qvalue(elt(env, 36)); // semic!*
    goto v_12302;
v_12303:
    v_12476 = elt(env, 37); // !$
    goto v_12304;
v_12305:
    goto v_12301;
v_12302:
    goto v_12303;
v_12304:
    if (v_12477 == v_12476) goto v_12300;
    v_12476 = qvalue(elt(env, 9)); // !*reduce4
    if (v_12476 == nil) goto v_12311;
    v_12476 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_12324;
v_12320:
    v_12477 = stack[-3];
    goto v_12321;
v_12322:
    v_12476 = elt(env, 35); // noval
    goto v_12323;
v_12324:
    goto v_12320;
v_12321:
    goto v_12322;
v_12323:
    if (v_12477 == v_12476) goto v_12318;
    else goto v_12319;
v_12318:
    goto v_12314;
v_12319:
    v_12476 = qvalue(elt(env, 38)); // !*debug
    if (v_12476 == nil) goto v_12329;
    v_12476 = elt(env, 39); // "Value:"
    fn = elt(env, 63); // prin2t
    v_12476 = (*qfn1(fn))(fn, v_12476);
    env = stack[-6];
    goto v_12317;
v_12329:
v_12317:
    goto v_12338;
v_12334:
    stack[-1] = elt(env, 40); // print
    goto v_12335;
v_12336:
    goto v_12346;
v_12342:
    v_12477 = stack[-3];
    goto v_12343;
v_12344:
    v_12476 = stack[0];
    goto v_12345;
v_12346:
    goto v_12342;
v_12343:
    goto v_12344;
v_12345:
    v_12476 = list2(v_12477, v_12476);
    env = stack[-6];
    v_12476 = ncons(v_12476);
    env = stack[-6];
    goto v_12337;
v_12338:
    goto v_12334;
v_12335:
    goto v_12336;
v_12337:
    fn = elt(env, 64); // rapply1
    v_12476 = (*qfn2(fn))(fn, stack[-1], v_12476);
    env = stack[-6];
v_12314:
    goto v_12309;
v_12311:
    goto v_12355;
v_12351:
    v_12477 = stack[-3];
    goto v_12352;
v_12353:
    v_12476 = elt(env, 34); // symbolic
    goto v_12354;
v_12355:
    goto v_12351;
v_12352:
    goto v_12353;
v_12354:
    if (v_12477 == v_12476) goto v_12349;
    else goto v_12350;
v_12349:
    v_12476 = stack[0];
    v_12476 = qcar(v_12476);
    if (v_12476 == nil) goto v_12364;
    else goto v_12365;
v_12364:
    goto v_12372;
v_12368:
    v_12477 = qvalue(elt(env, 41)); // !*mode
    goto v_12369;
v_12370:
    v_12476 = elt(env, 34); // symbolic
    goto v_12371;
v_12372:
    goto v_12368;
v_12369:
    goto v_12370;
v_12371:
    v_12476 = (v_12477 == v_12476 ? lisp_true : nil);
    v_12476 = (v_12476 == nil ? lisp_true : nil);
    goto v_12363;
v_12365:
    v_12476 = nil;
    goto v_12363;
    v_12476 = nil;
v_12363:
    if (v_12476 == nil) goto v_12361;
    goto v_12359;
v_12361:
    v_12476 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_12391;
v_12387:
    goto v_12397;
v_12393:
    stack[-1] = elt(env, 40); // print
    goto v_12394;
v_12395:
    v_12476 = stack[0];
    v_12476 = qcar(v_12476);
    v_12476 = Lmkquote(nil, v_12476);
    env = stack[-6];
    goto v_12396;
v_12397:
    goto v_12393;
v_12394:
    goto v_12395;
v_12396:
    v_12477 = list2(stack[-1], v_12476);
    env = stack[-6];
    goto v_12388;
v_12389:
    v_12476 = lisp_true;
    goto v_12390;
v_12391:
    goto v_12387;
v_12388:
    goto v_12389;
v_12390:
    fn = elt(env, 56); // errorset!*
    v_12476 = (*qfn2(fn))(fn, v_12477, v_12476);
    env = stack[-6];
    stack[0] = v_12476;
    goto v_12359;
v_12359:
    goto v_12309;
v_12350:
    v_12476 = stack[0];
    v_12476 = qcar(v_12476);
    if (v_12476 == nil) goto v_12404;
    goto v_12412;
v_12408:
    goto v_12422;
v_12414:
    stack[-1] = elt(env, 42); // assgnpri
    goto v_12415;
v_12416:
    v_12476 = stack[0];
    v_12476 = qcar(v_12476);
    stack[0] = Lmkquote(nil, v_12476);
    env = stack[-6];
    goto v_12417;
v_12418:
    v_12476 = stack[-4];
    if (v_12476 == nil) goto v_12430;
    goto v_12437;
v_12433:
    v_12477 = elt(env, 43); // list
    goto v_12434;
v_12435:
    v_12476 = stack[-4];
    goto v_12436;
v_12437:
    goto v_12433;
v_12434:
    goto v_12435;
v_12436:
    v_12476 = cons(v_12477, v_12476);
    env = stack[-6];
    stack[-4] = v_12476;
    goto v_12428;
v_12430:
    v_12476 = nil;
    stack[-4] = v_12476;
    goto v_12428;
    stack[-4] = nil;
v_12428:
    goto v_12419;
v_12420:
    v_12476 = elt(env, 44); // only
    v_12476 = Lmkquote(nil, v_12476);
    env = stack[-6];
    goto v_12421;
v_12422:
    goto v_12414;
v_12415:
    goto v_12416;
v_12417:
    goto v_12418;
v_12419:
    goto v_12420;
v_12421:
    v_12477 = list4(stack[-1], stack[0], stack[-4], v_12476);
    env = stack[-6];
    goto v_12409;
v_12410:
    v_12476 = lisp_true;
    goto v_12411;
v_12412:
    goto v_12408;
v_12409:
    goto v_12410;
v_12411:
    fn = elt(env, 56); // errorset!*
    v_12476 = (*qfn2(fn))(fn, v_12477, v_12476);
    env = stack[-6];
    stack[0] = v_12476;
    goto v_12309;
v_12404:
v_12309:
    goto v_12294;
v_12300:
v_12294:
    v_12476 = qvalue(elt(env, 9)); // !*reduce4
    if (v_12476 == nil) goto v_12448;
    else goto v_12449;
v_12448:
    v_12476 = stack[0];
    fn = elt(env, 57); // errorp
    v_12476 = (*qfn1(fn))(fn, v_12476);
    env = stack[-6];
    if (v_12476 == nil) goto v_12454;
    v_12476 = elt(env, 45); // err3
    goto v_12452;
v_12454:
    v_12476 = nil;
    goto v_12452;
    v_12476 = nil;
v_12452:
    goto v_11941;
v_12449:
    goto v_12467;
v_12463:
    v_12477 = qvalue(elt(env, 41)); // !*mode
    goto v_12464;
v_12465:
    v_12476 = elt(env, 35); // noval
    goto v_12466;
v_12467:
    goto v_12463;
v_12464:
    goto v_12465;
v_12466:
    if (v_12477 == v_12476) goto v_12462;
    v_12476 = Lterpri(nil, 0);
    env = stack[-6];
    v_12476 = elt(env, 46); // "of type: "
    v_12476 = Lprinc(nil, v_12476);
    env = stack[-6];
    v_12476 = stack[-3];
    v_12476 = Lprint(nil, v_12476);
    goto v_12447;
v_12462:
v_12447:
    v_12476 = nil;
v_11941:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_12476);
}



setup_type const u21_setup[] =
{
    {"mkprod",                  CC_mkprod,      TOO_MANY_1,    WRONG_NO_1},
    {"cl_simpl1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_simpl1},
    {"bc_zero?",                CC_bc_zeroW,    TOO_MANY_1,    WRONG_NO_1},
    {"ir2mml",                  CC_ir2mml,      TOO_MANY_1,    WRONG_NO_1},
    {"chk",                     CC_chk,         TOO_MANY_1,    WRONG_NO_1},
    {"expvec2a",                CC_expvec2a,    TOO_MANY_1,    WRONG_NO_1},
    {"treesizep",               TOO_FEW_2,      CC_treesizep,  WRONG_NO_2},
    {"ncoeffs",                 CC_ncoeffs,     TOO_MANY_1,    WRONG_NO_1},
    {"nfactorial",              CC_nfactorial,  TOO_MANY_1,    WRONG_NO_1},
    {"rootrnd",                 CC_rootrnd,     TOO_MANY_1,    WRONG_NO_1},
    {"cde_delete",              TOO_FEW_2,      CC_cde_delete, WRONG_NO_2},
    {"derivative-mod-p-1",      TOO_FEW_2,      CC_derivativeKmodKpK1,WRONG_NO_2},
    {"carrassoc",               TOO_FEW_2,      CC_carrassoc,  WRONG_NO_2},
    {"gcref_select",            CC_gcref_select,TOO_MANY_1,    WRONG_NO_1},
    {"cl_atl",                  CC_cl_atl,      TOO_MANY_1,    WRONG_NO_1},
    {"sq2sstm",                 TOO_FEW_2,      CC_sq2sstm,    WRONG_NO_2},
    {"diff-over-k-mod-p",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_diffKoverKkKmodKp},
    {"rd:prep",                 CC_rdTprep,     TOO_MANY_1,    WRONG_NO_1},
    {"dipevlcomp",              TOO_FEW_2,      CC_dipevlcomp, WRONG_NO_2},
    {"coposp",                  CC_coposp,      TOO_MANY_1,    WRONG_NO_1},
    {"assert_format",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_assert_format},
    {"mv-domainlist",           CC_mvKdomainlist,TOO_MANY_1,   WRONG_NO_1},
    {"rnprep:",                 CC_rnprepT,     TOO_MANY_1,    WRONG_NO_1},
    {"mkcr",                    TOO_FEW_2,      CC_mkcr,       WRONG_NO_2},
    {"lalr_prin_rhs",           CC_lalr_prin_rhs,TOO_MANY_1,   WRONG_NO_1},
    {"ofsf_varlat",             CC_ofsf_varlat, TOO_MANY_1,    WRONG_NO_1},
    {"vintersection",           TOO_FEW_2,      CC_vintersection,WRONG_NO_2},
    {"quotofd",                 TOO_FEW_2,      CC_quotofd,    WRONG_NO_2},
    {"dm-gt",                   TOO_FEW_2,      CC_dmKgt,      WRONG_NO_2},
    {"dipcondense",             CC_dipcondense, TOO_MANY_1,    WRONG_NO_1},
    {"partitexdf",              CC_partitexdf,  TOO_MANY_1,    WRONG_NO_1},
    {"indord2",                 TOO_FEW_2,      CC_indord2,    WRONG_NO_2},
    {"sf2mv1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_sf2mv1},
    {":rn2rd",                  CC_Trn2rd,      TOO_MANY_1,    WRONG_NO_1},
    {"groeb=weight",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_groebMweight},
    {"tensorp",                 CC_tensorp,     TOO_MANY_1,    WRONG_NO_1},
    {"reducepowers",            CC_reducepowers,TOO_MANY_1,    WRONG_NO_1},
    {"general-reciprocal-by-gcd",WRONG_NO_NA,   WRONG_NO_NB,   (n_args *)CC_generalKreciprocalKbyKgcd},
    {"exc",                     TOO_FEW_2,      CC_exc,        WRONG_NO_2},
    {"lalr_precalculate_first_sets",WRONG_NO_NA,WRONG_NO_NB,   (n_args *)CC_lalr_precalculate_first_sets},
    {"sfto_dgcd",               TOO_FEW_2,      CC_sfto_dgcd,  WRONG_NO_2},
    {"mk+unit+mat",             CC_mkLunitLmat, TOO_MANY_1,    WRONG_NO_1},
    {"cl_flip",                 CC_cl_flip,     TOO_MANY_1,    WRONG_NO_1},
    {"simprecip",               CC_simprecip,   TOO_MANY_1,    WRONG_NO_1},
    {"coordp",                  CC_coordp,      TOO_MANY_1,    WRONG_NO_1},
    {"begin11",                 CC_begin11,     TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u21", (two_args *)"112669 5474574 4819721", 0}
};

// end of generated code
