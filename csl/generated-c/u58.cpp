
// $destdir/u58.c        Machine generated C code

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



// Code for preproc1

static LispObject CC_preproc1(LispObject env,
                         LispObject v_34723)
{
    env = qenv(env);
    LispObject v_35517, v_35518, v_35519;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34723);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_34723;
// end of prologue
v_34727:
    v_35517 = stack[-1];
    if (!consp(v_35517)) goto v_34730;
    else goto v_34731;
v_34730:
    v_35517 = stack[-1];
    return ncons(v_35517);
v_34731:
    goto v_34741;
v_34737:
    v_35517 = stack[-1];
    v_35518 = qcar(v_35517);
    goto v_34738;
v_34739:
    v_35517 = elt(env, 1); // !:rd!:
    goto v_34740;
v_34741:
    goto v_34737;
v_34738:
    goto v_34739;
v_34740:
    if (v_35518 == v_35517) goto v_34735;
    else goto v_34736;
v_34735:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    if (!consp(v_35517)) goto v_34748;
    else goto v_34749;
v_34748:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    v_35517 = Lfloatp(nil, v_35517);
    env = stack[-5];
    if (v_35517 == nil) goto v_34755;
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    fn = elt(env, 19); // fl2bf
    v_35517 = (*qfn1(fn))(fn, v_35517);
    goto v_34753;
v_34755:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    if (!consp(v_35517)) goto v_34768;
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    goto v_34766;
v_34768:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    v_35517 = integerp(v_35517);
    if (v_35517 == nil) goto v_34774;
    goto v_34785;
v_34779:
    v_35519 = elt(env, 1); // !:rd!:
    goto v_34780;
v_34781:
    v_35517 = stack[-1];
    v_35518 = qcdr(v_35517);
    goto v_34782;
v_34783:
    v_35517 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34784;
v_34785:
    goto v_34779;
v_34780:
    goto v_34781;
v_34782:
    goto v_34783;
v_34784:
    v_35517 = list2star(v_35519, v_35518, v_35517);
    env = stack[-5];
    goto v_34766;
v_34774:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    fn = elt(env, 20); // read!:num
    v_35517 = (*qfn1(fn))(fn, v_35517);
    env = stack[-5];
    goto v_34766;
    v_35517 = nil;
v_34766:
    fn = elt(env, 21); // normbf
    v_35517 = (*qfn1(fn))(fn, v_35517);
    goto v_34753;
    v_35517 = nil;
v_34753:
    goto v_34747;
v_34749:
    v_35517 = stack[-1];
    goto v_34747;
    v_35517 = nil;
v_34747:
    return ncons(v_35517);
v_34736:
    goto v_34804;
v_34800:
    v_35517 = stack[-1];
    v_35518 = qcar(v_35517);
    goto v_34801;
v_34802:
    v_35517 = elt(env, 2); // !:dn!:
    goto v_34803;
v_34804:
    goto v_34800;
v_34801:
    goto v_34802;
v_34803:
    if (v_35518 == v_35517) goto v_34798;
    else goto v_34799;
v_34798:
    goto v_34813;
v_34809:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    v_35518 = qcar(v_35517);
    goto v_34810;
v_34811:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    v_35517 = qcdr(v_35517);
    goto v_34812;
v_34813:
    goto v_34809;
v_34810:
    goto v_34811;
v_34812:
    fn = elt(env, 22); // decimal2internal
    v_35517 = (*qfn2(fn))(fn, v_35518, v_35517);
    env = stack[-5];
    stack[-1] = v_35517;
    goto v_34727;
v_34799:
    goto v_34826;
v_34822:
    v_35517 = stack[-1];
    v_35518 = qcar(v_35517);
    goto v_34823;
v_34824:
    v_35517 = elt(env, 3); // !*sq
    goto v_34825;
v_34826:
    goto v_34822;
v_34823:
    goto v_34824;
v_34825:
    if (v_35518 == v_35517) goto v_34820;
    else goto v_34821;
v_34820:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    v_35517 = qcar(v_35517);
    fn = elt(env, 23); // prepsq
    v_35517 = (*qfn1(fn))(fn, v_35517);
    env = stack[-5];
    stack[-1] = v_35517;
    goto v_34727;
v_34821:
    goto v_34840;
v_34836:
    v_35517 = stack[-1];
    v_35518 = qcar(v_35517);
    goto v_34837;
v_34838:
    v_35517 = elt(env, 4); // procedure
    goto v_34839;
v_34840:
    goto v_34836;
v_34837:
    goto v_34838;
v_34839:
    if (v_35518 == v_35517) goto v_34834;
    else goto v_34835;
v_34834:
    goto v_34851;
v_34845:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    v_35519 = qcar(v_35517);
    goto v_34846;
v_34847:
    v_35518 = elt(env, 5); // !*params!*
    goto v_34848;
v_34849:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    v_35517 = qcdr(v_35517);
    v_35517 = qcdr(v_35517);
    v_35517 = qcdr(v_35517);
    v_35517 = qcar(v_35517);
    goto v_34850;
v_34851:
    goto v_34845;
v_34846:
    goto v_34847;
v_34848:
    goto v_34849;
v_34850:
    fn = elt(env, 24); // symtabput
    v_35517 = (*qfnn(fn))(fn, 3, v_35519, v_35518, v_35517);
    env = stack[-5];
    v_35517 = qvalue(elt(env, 6)); // !*getdecs
    if (v_35517 == nil) goto v_34865;
    goto v_34875;
v_34871:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    v_35517 = qcdr(v_35517);
    v_35518 = qcar(v_35517);
    goto v_34872;
v_34873:
    v_35517 = elt(env, 7); // (real integer)
    goto v_34874;
v_34875:
    goto v_34871;
v_34872:
    goto v_34873;
v_34874:
    v_35517 = Lmemq(nil, v_35518, v_35517);
    if (v_35517 == nil) goto v_34870;
    goto v_34889;
v_34883:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    stack[-2] = qcar(v_35517);
    goto v_34884;
v_34885:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    stack[0] = qcar(v_35517);
    goto v_34886;
v_34887:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    v_35517 = qcdr(v_35517);
    v_35517 = qcar(v_35517);
    v_35517 = ncons(v_35517);
    env = stack[-5];
    goto v_34888;
v_34889:
    goto v_34883;
v_34884:
    goto v_34885;
v_34886:
    goto v_34887;
v_34888:
    fn = elt(env, 24); // symtabput
    v_35517 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_35517);
    env = stack[-5];
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    v_35517 = qcdr(v_35517);
    v_35517 = qcdr(v_35517);
    v_35517 = qcdr(v_35517);
    v_35517 = qcar(v_35517);
    stack[-3] = v_35517;
v_34904:
    v_35517 = stack[-3];
    if (v_35517 == nil) goto v_34913;
    else goto v_34914;
v_34913:
    goto v_34903;
v_34914:
    v_35517 = stack[-3];
    v_35517 = qcar(v_35517);
    v_35518 = v_35517;
    goto v_34927;
v_34921:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    stack[-2] = qcar(v_35517);
    goto v_34922;
v_34923:
    stack[0] = v_35518;
    goto v_34924;
v_34925:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    v_35517 = qcdr(v_35517);
    v_35517 = qcar(v_35517);
    v_35517 = ncons(v_35517);
    env = stack[-5];
    goto v_34926;
v_34927:
    goto v_34921;
v_34922:
    goto v_34923;
v_34924:
    goto v_34925;
v_34926:
    fn = elt(env, 24); // symtabput
    v_35517 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_35517);
    env = stack[-5];
    v_35517 = stack[-3];
    v_35517 = qcdr(v_35517);
    stack[-3] = v_35517;
    goto v_34904;
v_34903:
    goto v_34945;
v_34941:
    goto v_34953;
v_34947:
    v_35519 = elt(env, 4); // procedure
    goto v_34948;
v_34949:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    v_35518 = qcar(v_35517);
    goto v_34950;
v_34951:
    v_35517 = nil;
    goto v_34952;
v_34953:
    goto v_34947;
v_34948:
    goto v_34949;
v_34950:
    goto v_34951;
v_34952:
    stack[-4] = list3(v_35519, v_35518, v_35517);
    env = stack[-5];
    goto v_34942;
v_34943:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    v_35517 = qcdr(v_35517);
    v_35517 = qcdr(v_35517);
    stack[-3] = v_35517;
v_34964:
    v_35517 = stack[-3];
    if (v_35517 == nil) goto v_34972;
    else goto v_34973;
v_34972:
    v_35517 = nil;
    goto v_34963;
v_34973:
    v_35517 = stack[-3];
    v_35517 = qcar(v_35517);
    v_35517 = CC_preproc1(elt(env, 0), v_35517);
    env = stack[-5];
    stack[-2] = v_35517;
    v_35517 = stack[-2];
    fn = elt(env, 25); // lastpair
    v_35517 = (*qfn1(fn))(fn, v_35517);
    env = stack[-5];
    stack[-1] = v_35517;
    v_35517 = stack[-3];
    v_35517 = qcdr(v_35517);
    stack[-3] = v_35517;
    v_35517 = stack[-1];
    if (!consp(v_35517)) goto v_34987;
    else goto v_34988;
v_34987:
    goto v_34964;
v_34988:
v_34965:
    v_35517 = stack[-3];
    if (v_35517 == nil) goto v_34992;
    else goto v_34993;
v_34992:
    v_35517 = stack[-2];
    goto v_34963;
v_34993:
    goto v_35001;
v_34997:
    stack[0] = stack[-1];
    goto v_34998;
v_34999:
    v_35517 = stack[-3];
    v_35517 = qcar(v_35517);
    v_35517 = CC_preproc1(elt(env, 0), v_35517);
    env = stack[-5];
    goto v_35000;
v_35001:
    goto v_34997;
v_34998:
    goto v_34999;
v_35000:
    v_35517 = Lrplacd(nil, stack[0], v_35517);
    env = stack[-5];
    v_35517 = stack[-1];
    fn = elt(env, 25); // lastpair
    v_35517 = (*qfn1(fn))(fn, v_35517);
    env = stack[-5];
    stack[-1] = v_35517;
    v_35517 = stack[-3];
    v_35517 = qcdr(v_35517);
    stack[-3] = v_35517;
    goto v_34965;
v_34963:
    goto v_34944;
v_34945:
    goto v_34941;
v_34942:
    goto v_34943;
v_34944:
    v_35517 = Lnconc(nil, stack[-4], v_35517);
    return ncons(v_35517);
v_34870:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    v_35517 = qcdr(v_35517);
    v_35517 = qcdr(v_35517);
    v_35517 = qcdr(v_35517);
    v_35517 = qcar(v_35517);
    stack[-3] = v_35517;
v_35017:
    v_35517 = stack[-3];
    if (v_35517 == nil) goto v_35026;
    else goto v_35027;
v_35026:
    goto v_35016;
v_35027:
    v_35517 = stack[-3];
    v_35517 = qcar(v_35517);
    v_35518 = v_35517;
    goto v_35040;
v_35034:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    stack[-2] = qcar(v_35517);
    goto v_35035;
v_35036:
    stack[0] = v_35518;
    goto v_35037;
v_35038:
    v_35517 = qvalue(elt(env, 8)); // deftype!*
    v_35517 = ncons(v_35517);
    env = stack[-5];
    goto v_35039;
v_35040:
    goto v_35034;
v_35035:
    goto v_35036;
v_35037:
    goto v_35038;
v_35039:
    fn = elt(env, 24); // symtabput
    v_35517 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_35517);
    env = stack[-5];
    v_35517 = stack[-3];
    v_35517 = qcdr(v_35517);
    stack[-3] = v_35517;
    goto v_35017;
v_35016:
    v_35517 = stack[-1];
    stack[-3] = v_35517;
v_35055:
    v_35517 = stack[-3];
    if (v_35517 == nil) goto v_35060;
    else goto v_35061;
v_35060:
    v_35517 = nil;
    goto v_35054;
v_35061:
    v_35517 = stack[-3];
    v_35517 = qcar(v_35517);
    v_35517 = CC_preproc1(elt(env, 0), v_35517);
    env = stack[-5];
    stack[-2] = v_35517;
    v_35517 = stack[-2];
    fn = elt(env, 25); // lastpair
    v_35517 = (*qfn1(fn))(fn, v_35517);
    env = stack[-5];
    stack[-1] = v_35517;
    v_35517 = stack[-3];
    v_35517 = qcdr(v_35517);
    stack[-3] = v_35517;
    v_35517 = stack[-1];
    if (!consp(v_35517)) goto v_35075;
    else goto v_35076;
v_35075:
    goto v_35055;
v_35076:
v_35056:
    v_35517 = stack[-3];
    if (v_35517 == nil) goto v_35080;
    else goto v_35081;
v_35080:
    v_35517 = stack[-2];
    goto v_35054;
v_35081:
    goto v_35089;
v_35085:
    stack[0] = stack[-1];
    goto v_35086;
v_35087:
    v_35517 = stack[-3];
    v_35517 = qcar(v_35517);
    v_35517 = CC_preproc1(elt(env, 0), v_35517);
    env = stack[-5];
    goto v_35088;
v_35089:
    goto v_35085;
v_35086:
    goto v_35087;
v_35088:
    v_35517 = Lrplacd(nil, stack[0], v_35517);
    env = stack[-5];
    v_35517 = stack[-1];
    fn = elt(env, 25); // lastpair
    v_35517 = (*qfn1(fn))(fn, v_35517);
    env = stack[-5];
    stack[-1] = v_35517;
    v_35517 = stack[-3];
    v_35517 = qcdr(v_35517);
    stack[-3] = v_35517;
    goto v_35056;
v_35054:
    return ncons(v_35517);
    goto v_34863;
v_34865:
    v_35517 = stack[-1];
    stack[-3] = v_35517;
v_35108:
    v_35517 = stack[-3];
    if (v_35517 == nil) goto v_35113;
    else goto v_35114;
v_35113:
    v_35517 = nil;
    goto v_35107;
v_35114:
    v_35517 = stack[-3];
    v_35517 = qcar(v_35517);
    v_35517 = CC_preproc1(elt(env, 0), v_35517);
    env = stack[-5];
    stack[-2] = v_35517;
    v_35517 = stack[-2];
    fn = elt(env, 25); // lastpair
    v_35517 = (*qfn1(fn))(fn, v_35517);
    env = stack[-5];
    stack[-1] = v_35517;
    v_35517 = stack[-3];
    v_35517 = qcdr(v_35517);
    stack[-3] = v_35517;
    v_35517 = stack[-1];
    if (!consp(v_35517)) goto v_35128;
    else goto v_35129;
v_35128:
    goto v_35108;
v_35129:
v_35109:
    v_35517 = stack[-3];
    if (v_35517 == nil) goto v_35133;
    else goto v_35134;
v_35133:
    v_35517 = stack[-2];
    goto v_35107;
v_35134:
    goto v_35142;
v_35138:
    stack[0] = stack[-1];
    goto v_35139;
v_35140:
    v_35517 = stack[-3];
    v_35517 = qcar(v_35517);
    v_35517 = CC_preproc1(elt(env, 0), v_35517);
    env = stack[-5];
    goto v_35141;
v_35142:
    goto v_35138;
v_35139:
    goto v_35140;
v_35141:
    v_35517 = Lrplacd(nil, stack[0], v_35517);
    env = stack[-5];
    v_35517 = stack[-1];
    fn = elt(env, 25); // lastpair
    v_35517 = (*qfn1(fn))(fn, v_35517);
    env = stack[-5];
    stack[-1] = v_35517;
    v_35517 = stack[-3];
    v_35517 = qcdr(v_35517);
    stack[-3] = v_35517;
    goto v_35109;
v_35107:
    return ncons(v_35517);
v_34863:
    goto v_34729;
v_34835:
    goto v_35159;
v_35155:
    v_35517 = stack[-1];
    v_35518 = qcar(v_35517);
    goto v_35156;
v_35157:
    v_35517 = elt(env, 9); // declare
    goto v_35158;
v_35159:
    goto v_35155;
v_35156:
    goto v_35157;
v_35158:
    if (v_35518 == v_35517) goto v_35153;
    else goto v_35154;
v_35153:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    v_35517 = CC_preproc1(elt(env, 0), v_35517);
    env = stack[-5];
    v_35517 = qcar(v_35517);
    stack[-1] = v_35517;
    v_35517 = stack[-1];
    fn = elt(env, 26); // preprocdec
    v_35517 = (*qfn1(fn))(fn, v_35517);
    env = stack[-5];
    stack[-1] = v_35517;
    v_35517 = stack[-1];
    stack[-4] = v_35517;
v_35172:
    v_35517 = stack[-4];
    if (v_35517 == nil) goto v_35176;
    else goto v_35177;
v_35176:
    goto v_35171;
v_35177:
    v_35517 = stack[-4];
    v_35517 = qcar(v_35517);
    stack[-3] = v_35517;
    v_35517 = stack[-3];
    v_35517 = qcdr(v_35517);
    stack[-2] = v_35517;
v_35186:
    v_35517 = stack[-2];
    if (v_35517 == nil) goto v_35191;
    else goto v_35192;
v_35191:
    goto v_35185;
v_35192:
    v_35517 = stack[-2];
    v_35517 = qcar(v_35517);
    v_35519 = v_35517;
    goto v_35206;
v_35202:
    v_35517 = stack[-3];
    v_35518 = qcar(v_35517);
    goto v_35203;
v_35204:
    v_35517 = elt(env, 10); // (subroutine function)
    goto v_35205;
v_35206:
    goto v_35202;
v_35203:
    goto v_35204;
v_35205:
    v_35517 = Lmemq(nil, v_35518, v_35517);
    if (v_35517 == nil) goto v_35201;
    goto v_35218;
v_35212:
    goto v_35213;
v_35214:
    v_35518 = elt(env, 11); // !*type!*
    goto v_35215;
v_35216:
    v_35517 = stack[-3];
    v_35517 = qcar(v_35517);
    goto v_35217;
v_35218:
    goto v_35212;
v_35213:
    goto v_35214;
v_35215:
    goto v_35216;
v_35217:
    fn = elt(env, 24); // symtabput
    v_35517 = (*qfnn(fn))(fn, 3, v_35519, v_35518, v_35517);
    env = stack[-5];
    goto v_35199;
v_35201:
    goto v_35232;
v_35226:
    stack[-1] = nil;
    goto v_35227;
v_35228:
    v_35517 = v_35519;
    if (!consp(v_35517)) goto v_35236;
    else goto v_35237;
v_35236:
    v_35517 = v_35519;
    stack[0] = v_35517;
    goto v_35235;
v_35237:
    v_35517 = v_35519;
    v_35517 = qcar(v_35517);
    stack[0] = v_35517;
    goto v_35235;
    stack[0] = nil;
v_35235:
    goto v_35229;
v_35230:
    v_35517 = v_35519;
    if (!consp(v_35517)) goto v_35246;
    else goto v_35247;
v_35246:
    v_35517 = stack[-3];
    v_35517 = qcar(v_35517);
    v_35517 = ncons(v_35517);
    env = stack[-5];
    goto v_35245;
v_35247:
    goto v_35259;
v_35255:
    v_35517 = stack[-3];
    v_35517 = qcar(v_35517);
    goto v_35256;
v_35257:
    v_35518 = v_35519;
    v_35518 = qcdr(v_35518);
    goto v_35258;
v_35259:
    goto v_35255;
v_35256:
    goto v_35257;
v_35258:
    v_35517 = cons(v_35517, v_35518);
    env = stack[-5];
    goto v_35245;
    v_35517 = nil;
v_35245:
    goto v_35231;
v_35232:
    goto v_35226;
v_35227:
    goto v_35228;
v_35229:
    goto v_35230;
v_35231:
    fn = elt(env, 24); // symtabput
    v_35517 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_35517);
    env = stack[-5];
    goto v_35199;
v_35199:
    v_35517 = stack[-2];
    v_35517 = qcdr(v_35517);
    stack[-2] = v_35517;
    goto v_35186;
v_35185:
    v_35517 = stack[-4];
    v_35517 = qcdr(v_35517);
    stack[-4] = v_35517;
    goto v_35172;
v_35171:
    v_35517 = nil;
    goto v_34726;
v_35154:
    goto v_35279;
v_35275:
    v_35517 = stack[-1];
    v_35518 = qcar(v_35517);
    goto v_35276;
v_35277:
    v_35517 = elt(env, 12); // setq
    goto v_35278;
v_35279:
    goto v_35275;
v_35276:
    goto v_35277;
v_35278:
    if (v_35518 == v_35517) goto v_35273;
    else goto v_35274;
v_35273:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    v_35517 = qcdr(v_35517);
    v_35517 = qcar(v_35517);
    v_35517 = Lconsp(nil, v_35517);
    env = stack[-5];
    if (v_35517 == nil) goto v_35285;
    else goto v_35286;
v_35285:
    v_35517 = nil;
    goto v_35284;
v_35286:
    goto v_35299;
v_35295:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    v_35517 = qcdr(v_35517);
    v_35517 = qcar(v_35517);
    v_35518 = qcar(v_35517);
    goto v_35296;
v_35297:
    v_35517 = elt(env, 13); // (cond progn)
    goto v_35298;
v_35299:
    goto v_35295;
v_35296:
    goto v_35297;
v_35298:
    v_35517 = Lmemq(nil, v_35518, v_35517);
    goto v_35284;
    v_35517 = nil;
v_35284:
    goto v_35272;
v_35274:
    v_35517 = nil;
    goto v_35272;
    v_35517 = nil;
v_35272:
    if (v_35517 == nil) goto v_35270;
    v_35517 = stack[-1];
    {
        fn = elt(env, 27); // migrate!-setqs
        return (*qfn1(fn))(fn, v_35517);
    }
v_35270:
    goto v_35318;
v_35314:
    v_35517 = stack[-1];
    v_35518 = qcar(v_35517);
    goto v_35315;
v_35316:
    v_35517 = elt(env, 14); // (plus times difference quotient minus)
    goto v_35317;
v_35318:
    goto v_35314;
v_35315:
    goto v_35316;
v_35317:
    v_35517 = Lmemq(nil, v_35518, v_35517);
    if (v_35517 == nil) goto v_35313;
    v_35517 = stack[-1];
    fn = elt(env, 28); // simp!*
    v_35517 = (*qfn1(fn))(fn, v_35517);
    env = stack[-5];
    v_35519 = v_35517;
    v_35517 = qcar(v_35517);
    v_35517 = Lconsp(nil, v_35517);
    env = stack[-5];
    if (v_35517 == nil) goto v_35329;
    goto v_35340;
v_35336:
    v_35517 = v_35519;
    v_35517 = qcar(v_35517);
    v_35518 = qcar(v_35517);
    goto v_35337;
v_35338:
    v_35517 = elt(env, 15); // (!:cr!: !:crn!: !:gi!:)
    goto v_35339;
v_35340:
    goto v_35336;
v_35337:
    goto v_35338;
v_35339:
    v_35517 = Lmemq(nil, v_35518, v_35517);
    if (v_35517 == nil) goto v_35329;
    v_35517 = v_35519;
    v_35517 = qcdr(v_35517);
    v_35517 = Lonep(nil, v_35517);
    env = stack[-5];
    if (v_35517 == nil) goto v_35349;
    v_35517 = v_35519;
    v_35517 = qcar(v_35517);
    return ncons(v_35517);
v_35349:
    goto v_35366;
v_35360:
    stack[-1] = elt(env, 16); // quotient
    goto v_35361;
v_35362:
    v_35517 = v_35519;
    stack[0] = qcar(v_35517);
    goto v_35363;
v_35364:
    goto v_35377;
v_35373:
    v_35517 = v_35519;
    v_35518 = qcdr(v_35517);
    goto v_35374;
v_35375:
    v_35517 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35376;
v_35377:
    goto v_35373;
v_35374:
    goto v_35375;
v_35376:
    v_35517 = cons(v_35518, v_35517);
    env = stack[-5];
    fn = elt(env, 23); // prepsq
    v_35517 = (*qfn1(fn))(fn, v_35517);
    env = stack[-5];
    v_35517 = CC_preproc1(elt(env, 0), v_35517);
    env = stack[-5];
    v_35517 = qcar(v_35517);
    goto v_35365;
v_35366:
    goto v_35360;
v_35361:
    goto v_35362;
v_35363:
    goto v_35364;
v_35365:
    v_35517 = list3(stack[-1], stack[0], v_35517);
    return ncons(v_35517);
    v_35517 = nil;
    goto v_35327;
v_35329:
    v_35517 = stack[-1];
    stack[-3] = v_35517;
v_35390:
    v_35517 = stack[-3];
    if (v_35517 == nil) goto v_35395;
    else goto v_35396;
v_35395:
    v_35517 = nil;
    goto v_35389;
v_35396:
    v_35517 = stack[-3];
    v_35517 = qcar(v_35517);
    v_35517 = CC_preproc1(elt(env, 0), v_35517);
    env = stack[-5];
    stack[-2] = v_35517;
    v_35517 = stack[-2];
    fn = elt(env, 25); // lastpair
    v_35517 = (*qfn1(fn))(fn, v_35517);
    env = stack[-5];
    stack[-1] = v_35517;
    v_35517 = stack[-3];
    v_35517 = qcdr(v_35517);
    stack[-3] = v_35517;
    v_35517 = stack[-1];
    if (!consp(v_35517)) goto v_35410;
    else goto v_35411;
v_35410:
    goto v_35390;
v_35411:
v_35391:
    v_35517 = stack[-3];
    if (v_35517 == nil) goto v_35415;
    else goto v_35416;
v_35415:
    v_35517 = stack[-2];
    goto v_35389;
v_35416:
    goto v_35424;
v_35420:
    stack[0] = stack[-1];
    goto v_35421;
v_35422:
    v_35517 = stack[-3];
    v_35517 = qcar(v_35517);
    v_35517 = CC_preproc1(elt(env, 0), v_35517);
    env = stack[-5];
    goto v_35423;
v_35424:
    goto v_35420;
v_35421:
    goto v_35422;
v_35423:
    v_35517 = Lrplacd(nil, stack[0], v_35517);
    env = stack[-5];
    v_35517 = stack[-1];
    fn = elt(env, 25); // lastpair
    v_35517 = (*qfn1(fn))(fn, v_35517);
    env = stack[-5];
    stack[-1] = v_35517;
    v_35517 = stack[-3];
    v_35517 = qcdr(v_35517);
    stack[-3] = v_35517;
    goto v_35391;
v_35389:
    return ncons(v_35517);
    v_35517 = nil;
v_35327:
    goto v_34726;
v_35313:
    v_35517 = qvalue(elt(env, 6)); // !*getdecs
    if (v_35517 == nil) goto v_35440;
    goto v_35448;
v_35444:
    v_35517 = stack[-1];
    v_35518 = qcar(v_35517);
    goto v_35445;
v_35446:
    v_35517 = elt(env, 17); // (!~for for)
    goto v_35447;
v_35448:
    goto v_35444;
v_35445:
    goto v_35446;
v_35447:
    v_35517 = Lmemq(nil, v_35518, v_35517);
    if (v_35517 == nil) goto v_35440;
    goto v_35460;
v_35454:
    v_35519 = nil;
    goto v_35455;
v_35456:
    v_35517 = stack[-1];
    v_35517 = qcdr(v_35517);
    v_35518 = qcar(v_35517);
    goto v_35457;
v_35458:
    v_35517 = elt(env, 18); // (integer)
    goto v_35459;
v_35460:
    goto v_35454;
v_35455:
    goto v_35456;
v_35457:
    goto v_35458;
v_35459:
    fn = elt(env, 24); // symtabput
    v_35517 = (*qfnn(fn))(fn, 3, v_35519, v_35518, v_35517);
    env = stack[-5];
    goto v_35438;
v_35440:
v_35438:
    v_35517 = stack[-1];
    stack[-3] = v_35517;
v_35472:
    v_35517 = stack[-3];
    if (v_35517 == nil) goto v_35477;
    else goto v_35478;
v_35477:
    v_35517 = nil;
    goto v_35471;
v_35478:
    v_35517 = stack[-3];
    v_35517 = qcar(v_35517);
    v_35517 = CC_preproc1(elt(env, 0), v_35517);
    env = stack[-5];
    stack[-2] = v_35517;
    v_35517 = stack[-2];
    fn = elt(env, 25); // lastpair
    v_35517 = (*qfn1(fn))(fn, v_35517);
    env = stack[-5];
    stack[-1] = v_35517;
    v_35517 = stack[-3];
    v_35517 = qcdr(v_35517);
    stack[-3] = v_35517;
    v_35517 = stack[-1];
    if (!consp(v_35517)) goto v_35492;
    else goto v_35493;
v_35492:
    goto v_35472;
v_35493:
v_35473:
    v_35517 = stack[-3];
    if (v_35517 == nil) goto v_35497;
    else goto v_35498;
v_35497:
    v_35517 = stack[-2];
    goto v_35471;
v_35498:
    goto v_35506;
v_35502:
    stack[0] = stack[-1];
    goto v_35503;
v_35504:
    v_35517 = stack[-3];
    v_35517 = qcar(v_35517);
    v_35517 = CC_preproc1(elt(env, 0), v_35517);
    env = stack[-5];
    goto v_35505;
v_35506:
    goto v_35502;
v_35503:
    goto v_35504;
v_35505:
    v_35517 = Lrplacd(nil, stack[0], v_35517);
    env = stack[-5];
    v_35517 = stack[-1];
    fn = elt(env, 25); // lastpair
    v_35517 = (*qfn1(fn))(fn, v_35517);
    env = stack[-5];
    stack[-1] = v_35517;
    v_35517 = stack[-3];
    v_35517 = qcdr(v_35517);
    stack[-3] = v_35517;
    goto v_35473;
v_35471:
    return ncons(v_35517);
v_34729:
    v_35517 = nil;
v_34726:
    return onevalue(v_35517);
}



// Code for basisvectorp

static LispObject CC_basisvectorp(LispObject env,
                         LispObject v_34723)
{
    env = qenv(env);
    LispObject v_34741, v_34742;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_34742 = v_34723;
// end of prologue
    v_34741 = v_34742;
    if (!consp(v_34741)) goto v_34728;
    goto v_34734;
v_34730:
    v_34741 = v_34742;
    goto v_34731;
v_34732:
    v_34742 = qvalue(elt(env, 1)); // basisvectorl!*
    goto v_34733;
v_34734:
    goto v_34730;
v_34731:
    goto v_34732;
v_34733:
    v_34741 = Lmemq(nil, v_34741, v_34742);
    goto v_34726;
v_34728:
    v_34741 = nil;
    goto v_34726;
    v_34741 = nil;
v_34726:
    return onevalue(v_34741);
}



// Code for find_bubles1

static LispObject CC_find_bubles1(LispObject env,
                         LispObject v_34723, LispObject v_34724)
{
    env = qenv(env);
    LispObject v_34752, v_34753, v_34754, v_34755, v_34756, v_34757;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_34752 = v_34724;
    v_34753 = v_34723;
// end of prologue
    goto v_34739;
v_34727:
    v_34757 = nil;
    goto v_34728;
v_34729:
    v_34754 = v_34753;
    v_34756 = qcar(v_34754);
    goto v_34730;
v_34731:
    v_34755 = nil;
    goto v_34732;
v_34733:
    v_34754 = v_34753;
    v_34754 = qcdr(v_34754);
    v_34754 = qcar(v_34754);
    goto v_34734;
v_34735:
    v_34753 = qcdr(v_34753);
    v_34753 = qcdr(v_34753);
    v_34753 = qcar(v_34753);
    goto v_34736;
v_34737:
    goto v_34738;
v_34739:
    goto v_34727;
v_34728:
    goto v_34729;
v_34730:
    goto v_34731;
v_34732:
    goto v_34733;
v_34734:
    goto v_34735;
v_34736:
    goto v_34737;
v_34738:
    {
        fn = elt(env, 1); // select_bubles
        return (*qfnn(fn))(fn, 6, v_34757, v_34756, v_34755, v_34754, v_34753, v_34752);
    }
}



// Code for compactf1

static LispObject CC_compactf1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_34762, v_34763, v_34764, v_34765, v_34766;
    LispObject fn;
    LispObject v_34726, v_34725, v_34724, v_34723;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "compactf1");
    va_start(aa, nargs);
    v_34723 = va_arg(aa, LispObject);
    v_34724 = va_arg(aa, LispObject);
    v_34725 = va_arg(aa, LispObject);
    v_34726 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_34726,v_34725,v_34724,v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_34723,v_34724,v_34725,v_34726);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_34726;
    stack[-1] = v_34725;
    stack[-2] = v_34724;
    stack[-3] = v_34723;
// end of prologue
    goto v_34736;
v_34732:
    v_34763 = stack[-1];
    goto v_34733;
v_34734:
    v_34762 = stack[0];
    goto v_34735;
v_34736:
    goto v_34732;
v_34733:
    goto v_34734;
v_34735:
    fn = elt(env, 1); // intersection
    v_34762 = (*qfn2(fn))(fn, v_34763, v_34762);
    env = stack[-4];
    v_34763 = v_34762;
    if (v_34763 == nil) goto v_34741;
    else goto v_34742;
v_34741:
    v_34762 = stack[-3];
    goto v_34730;
v_34742:
    goto v_34756;
v_34746:
    v_34766 = stack[-3];
    goto v_34747;
v_34748:
    v_34765 = stack[-2];
    goto v_34749;
v_34750:
    v_34764 = stack[-1];
    goto v_34751;
v_34752:
    v_34763 = stack[0];
    goto v_34753;
v_34754:
    goto v_34755;
v_34756:
    goto v_34746;
v_34747:
    goto v_34748;
v_34749:
    goto v_34750;
v_34751:
    goto v_34752;
v_34753:
    goto v_34754;
v_34755:
    {
        fn = elt(env, 2); // compactf11
        return (*qfnn(fn))(fn, 5, v_34766, v_34765, v_34764, v_34763, v_34762);
    }
v_34730:
    return onevalue(v_34762);
}



// Code for mo_deletecomp

static LispObject CC_mo_deletecomp(LispObject env,
                         LispObject v_34723)
{
    env = qenv(env);
    LispObject v_34768, v_34769;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34723);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_34768 = v_34723;
// end of prologue
    v_34769 = v_34768;
    v_34769 = qcar(v_34769);
    if (v_34769 == nil) goto v_34727;
    else goto v_34728;
v_34727:
    goto v_34726;
v_34728:
    v_34769 = v_34768;
    v_34769 = qcar(v_34769);
    v_34769 = qcdr(v_34769);
    if (v_34769 == nil) goto v_34732;
    else goto v_34733;
v_34732:
    goto v_34742;
v_34738:
    stack[0] = nil;
    goto v_34739;
v_34740:
    v_34768 = nil;
    fn = elt(env, 1); // mo!=deglist
    v_34768 = (*qfn1(fn))(fn, v_34768);
    goto v_34741;
v_34742:
    goto v_34738;
v_34739:
    goto v_34740;
v_34741:
    {
        LispObject v_34771 = stack[0];
        return cons(v_34771, v_34768);
    }
v_34733:
    goto v_34753;
v_34749:
    v_34769 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34750;
v_34751:
    v_34768 = qcar(v_34768);
    v_34768 = qcdr(v_34768);
    goto v_34752;
v_34753:
    goto v_34749;
v_34750:
    goto v_34751;
v_34752:
    v_34768 = cons(v_34769, v_34768);
    env = stack[-1];
    goto v_34764;
v_34760:
    stack[0] = v_34768;
    goto v_34761;
v_34762:
    fn = elt(env, 1); // mo!=deglist
    v_34768 = (*qfn1(fn))(fn, v_34768);
    goto v_34763;
v_34764:
    goto v_34760;
v_34761:
    goto v_34762;
v_34763:
    {
        LispObject v_34772 = stack[0];
        return cons(v_34772, v_34768);
    }
    v_34768 = nil;
v_34726:
    return onevalue(v_34768);
}



// Code for solvevars

static LispObject CC_solvevars(LispObject env,
                         LispObject v_34723)
{
    env = qenv(env);
    LispObject v_34759, v_34760;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34723);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_34760 = v_34723;
// end of prologue
    v_34759 = nil;
    stack[-2] = v_34759;
    v_34759 = v_34760;
    fn = elt(env, 1); // allbkern
    v_34759 = (*qfn1(fn))(fn, v_34759);
    env = stack[-3];
    stack[-1] = v_34759;
v_34730:
    v_34759 = stack[-1];
    if (v_34759 == nil) goto v_34735;
    else goto v_34736;
v_34735:
    goto v_34729;
v_34736:
    v_34759 = stack[-1];
    v_34759 = qcar(v_34759);
    stack[0] = v_34759;
    v_34759 = stack[0];
    fn = elt(env, 2); // constant_exprp
    v_34759 = (*qfn1(fn))(fn, v_34759);
    env = stack[-3];
    if (v_34759 == nil) goto v_34744;
    else goto v_34745;
v_34744:
    goto v_34753;
v_34749:
    v_34760 = stack[0];
    goto v_34750;
v_34751:
    v_34759 = stack[-2];
    goto v_34752;
v_34753:
    goto v_34749;
v_34750:
    goto v_34751;
v_34752:
    fn = elt(env, 3); // ordad
    v_34759 = (*qfn2(fn))(fn, v_34760, v_34759);
    env = stack[-3];
    stack[-2] = v_34759;
    goto v_34743;
v_34745:
v_34743:
    v_34759 = stack[-1];
    v_34759 = qcdr(v_34759);
    stack[-1] = v_34759;
    goto v_34730;
v_34729:
    v_34759 = stack[-2];
    return onevalue(v_34759);
}



// Code for rat_mk

static LispObject CC_rat_mk(LispObject env,
                         LispObject v_34723, LispObject v_34724)
{
    env = qenv(env);
    LispObject v_34736;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34724,v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34723,v_34724);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_34724;
    v_34736 = v_34723;
// end of prologue
    goto v_34731;
v_34727:
    fn = elt(env, 1); // simp
    stack[-1] = (*qfn1(fn))(fn, v_34736);
    env = stack[-2];
    goto v_34728;
v_34729:
    v_34736 = stack[0];
    fn = elt(env, 1); // simp
    v_34736 = (*qfn1(fn))(fn, v_34736);
    env = stack[-2];
    goto v_34730;
v_34731:
    goto v_34727;
v_34728:
    goto v_34729;
v_34730:
    {
        LispObject v_34739 = stack[-1];
        fn = elt(env, 2); // quotsq
        return (*qfn2(fn))(fn, v_34739, v_34736);
    }
}



// Code for gcdlist1

static LispObject CC_gcdlist1(LispObject env,
                         LispObject v_34723)
{
    env = qenv(env);
    LispObject v_35016, v_35017, v_35018;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34723);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[0] = v_34723;
// end of prologue
// Binding reduction!-count
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
    qvalue(elt(env, 1)) = nil; // reduction!-count
    v_35016 = stack[0];
    v_35016 = qcar(v_35016);
    v_35016 = qcdr(v_35016);
    stack[-4] = v_35016;
    stack[-2] = v_35016;
    v_35016 = stack[0];
    v_35016 = qcdr(v_35016);
    stack[-3] = v_35016;
v_34739:
    v_35016 = stack[-3];
    if (v_35016 == nil) goto v_34744;
    else goto v_34745;
v_34744:
    goto v_34738;
v_34745:
    v_35016 = stack[-3];
    v_35016 = qcar(v_35016);
    stack[-1] = v_35016;
    goto v_34756;
v_34752:
    v_35017 = stack[-2];
    goto v_34753;
v_34754:
    v_35016 = stack[-1];
    v_35016 = qcdr(v_35016);
    goto v_34755;
v_34756:
    goto v_34752;
v_34753:
    goto v_34754;
v_34755:
    fn = elt(env, 3); // vunion
    v_35016 = (*qfn2(fn))(fn, v_35017, v_35016);
    env = stack[-7];
    stack[-2] = v_35016;
    goto v_34765;
v_34761:
    v_35017 = stack[-4];
    goto v_34762;
v_34763:
    v_35016 = stack[-1];
    v_35016 = qcdr(v_35016);
    goto v_34764;
v_34765:
    goto v_34761;
v_34762:
    goto v_34763;
v_34764:
    fn = elt(env, 4); // vintersection
    v_35016 = (*qfn2(fn))(fn, v_35017, v_35016);
    env = stack[-7];
    stack[-4] = v_35016;
    v_35016 = stack[-3];
    v_35016 = qcdr(v_35016);
    stack[-3] = v_35016;
    goto v_34739;
v_34738:
    v_35016 = stack[-4];
    if (v_35016 == nil) goto v_34773;
    else goto v_34774;
v_34773:
    v_35016 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34732;
v_34774:
    v_35016 = stack[-4];
    stack[-1] = v_35016;
v_34780:
    v_35016 = stack[-1];
    if (v_35016 == nil) goto v_34784;
    else goto v_34785;
v_34784:
    goto v_34779;
v_34785:
    v_35016 = stack[-1];
    v_35016 = qcar(v_35016);
    goto v_34796;
v_34792:
    v_35017 = v_35016;
    goto v_34793;
v_34794:
    v_35016 = stack[-2];
    goto v_34795;
v_34796:
    goto v_34792;
v_34793:
    goto v_34794;
v_34795:
    fn = elt(env, 5); // vdelete
    v_35016 = (*qfn2(fn))(fn, v_35017, v_35016);
    env = stack[-7];
    stack[-2] = v_35016;
    v_35016 = stack[-1];
    v_35016 = qcdr(v_35016);
    stack[-1] = v_35016;
    goto v_34780;
v_34779:
    goto v_34806;
v_34802:
    v_35017 = stack[-4];
    goto v_34803;
v_34804:
    v_35016 = elt(env, 2); // lesspcdr
    goto v_34805;
v_34806:
    goto v_34802;
v_34803:
    goto v_34804;
v_34805:
    fn = elt(env, 6); // sort
    v_35016 = (*qfn2(fn))(fn, v_35017, v_35016);
    env = stack[-7];
    stack[-4] = v_35016;
    goto v_34817;
v_34813:
    v_35016 = stack[-4];
    v_35016 = qcar(v_35016);
    v_35017 = qcdr(v_35016);
    goto v_34814;
v_34815:
    v_35016 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34816;
v_34817:
    goto v_34813;
v_34814:
    goto v_34815;
v_34816:
    if (v_35017 == v_35016) goto v_34811;
    else goto v_34812;
v_34811:
    goto v_34828;
v_34824:
    v_35017 = stack[-4];
    goto v_34825;
v_34826:
    v_35016 = stack[-2];
    goto v_34827;
v_34828:
    goto v_34824;
v_34825:
    goto v_34826;
v_34827:
    v_35016 = Lappend(nil, v_35017, v_35016);
    env = stack[-7];
    fn = elt(env, 7); // mapcarcar
    v_35016 = (*qfn1(fn))(fn, v_35016);
    env = stack[-7];
    stack[-5] = v_35016;
    v_35016 = stack[-5];
    fn = elt(env, 8); // setkorder
    v_35016 = (*qfn1(fn))(fn, v_35016);
    env = stack[-7];
    stack[-4] = v_35016;
    goto v_34840;
v_34834:
    v_35016 = stack[0];
    stack[-3] = v_35016;
    v_35016 = stack[-3];
    if (v_35016 == nil) goto v_34850;
    else goto v_34851;
v_34850:
    v_35016 = nil;
    v_35018 = v_35016;
    goto v_34845;
v_34851:
    v_35016 = stack[-3];
    v_35016 = qcar(v_35016);
    v_35016 = qcar(v_35016);
    fn = elt(env, 9); // reorder
    v_35016 = (*qfn1(fn))(fn, v_35016);
    env = stack[-7];
    v_35016 = ncons(v_35016);
    env = stack[-7];
    stack[-1] = v_35016;
    stack[-2] = v_35016;
v_34846:
    v_35016 = stack[-3];
    v_35016 = qcdr(v_35016);
    stack[-3] = v_35016;
    v_35016 = stack[-3];
    if (v_35016 == nil) goto v_34865;
    else goto v_34866;
v_34865:
    v_35016 = stack[-2];
    v_35018 = v_35016;
    goto v_34845;
v_34866:
    goto v_34874;
v_34870:
    stack[0] = stack[-1];
    goto v_34871;
v_34872:
    v_35016 = stack[-3];
    v_35016 = qcar(v_35016);
    v_35016 = qcar(v_35016);
    fn = elt(env, 9); // reorder
    v_35016 = (*qfn1(fn))(fn, v_35016);
    env = stack[-7];
    v_35016 = ncons(v_35016);
    env = stack[-7];
    goto v_34873;
v_34874:
    goto v_34870;
v_34871:
    goto v_34872;
v_34873:
    v_35016 = Lrplacd(nil, stack[0], v_35016);
    env = stack[-7];
    v_35016 = stack[-1];
    v_35016 = qcdr(v_35016);
    stack[-1] = v_35016;
    goto v_34846;
v_34845:
    goto v_34835;
v_34836:
    v_35017 = nil;
    goto v_34837;
v_34838:
    v_35016 = stack[-5];
    goto v_34839;
v_34840:
    goto v_34834;
v_34835:
    goto v_34836;
v_34837:
    goto v_34838;
v_34839:
    fn = elt(env, 10); // gcdlist3
    v_35016 = (*qfnn(fn))(fn, 3, v_35018, v_35017, v_35016);
    env = stack[-7];
    stack[0] = v_35016;
    v_35016 = stack[-4];
    fn = elt(env, 8); // setkorder
    v_35016 = (*qfn1(fn))(fn, v_35016);
    env = stack[-7];
    v_35016 = stack[0];
    fn = elt(env, 9); // reorder
    v_35016 = (*qfn1(fn))(fn, v_35016);
    goto v_34732;
v_34812:
    v_35016 = stack[-2];
    if (v_35016 == nil) goto v_34891;
    else goto v_34892;
v_34891:
    goto v_34899;
v_34895:
    v_35017 = stack[0];
    goto v_34896;
v_34897:
    v_35016 = stack[-4];
    goto v_34898;
v_34899:
    goto v_34895;
v_34896:
    goto v_34897;
v_34898:
    fn = elt(env, 11); // gcdlist2
    v_35016 = (*qfn2(fn))(fn, v_35017, v_35016);
    goto v_34732;
v_34892:
    goto v_34909;
v_34905:
    v_35017 = stack[-2];
    goto v_34906;
v_34907:
    v_35016 = stack[-4];
    goto v_34908;
v_34909:
    goto v_34905;
v_34906:
    goto v_34907;
v_34908:
    v_35016 = Lappend(nil, v_35017, v_35016);
    env = stack[-7];
    fn = elt(env, 7); // mapcarcar
    v_35016 = (*qfn1(fn))(fn, v_35016);
    env = stack[-7];
    fn = elt(env, 8); // setkorder
    v_35016 = (*qfn1(fn))(fn, v_35016);
    env = stack[-7];
    stack[-5] = v_35016;
    v_35016 = nil;
    stack[-4] = v_35016;
    v_35016 = stack[0];
    stack[-1] = v_35016;
v_34916:
    v_35016 = stack[-1];
    if (v_35016 == nil) goto v_34920;
    else goto v_34921;
v_34920:
    goto v_34915;
v_34921:
    v_35016 = stack[-1];
    v_35016 = qcar(v_35016);
    goto v_34934;
v_34928:
    v_35016 = qcar(v_35016);
    fn = elt(env, 9); // reorder
    stack[0] = (*qfn1(fn))(fn, v_35016);
    env = stack[-7];
    goto v_34929;
v_34930:
    v_35016 = stack[-2];
    fn = elt(env, 7); // mapcarcar
    v_35017 = (*qfn1(fn))(fn, v_35016);
    env = stack[-7];
    goto v_34931;
v_34932:
    v_35016 = stack[-4];
    goto v_34933;
v_34934:
    goto v_34928;
v_34929:
    goto v_34930;
v_34931:
    goto v_34932;
v_34933:
    fn = elt(env, 12); // split!-wrt!-variables
    v_35016 = (*qfnn(fn))(fn, 3, stack[0], v_35017, v_35016);
    env = stack[-7];
    stack[-4] = v_35016;
    v_35016 = stack[-1];
    v_35016 = qcdr(v_35016);
    stack[-1] = v_35016;
    goto v_34916;
v_34915:
    v_35016 = stack[-5];
    fn = elt(env, 8); // setkorder
    v_35016 = (*qfn1(fn))(fn, v_35016);
    env = stack[-7];
    v_35016 = stack[-4];
    stack[-5] = v_35016;
    v_35016 = stack[-5];
    if (v_35016 == nil) goto v_34955;
    else goto v_34956;
v_34955:
    v_35016 = nil;
    goto v_34950;
v_34956:
    v_35016 = stack[-5];
    v_35016 = qcar(v_35016);
    stack[-1] = v_35016;
    goto v_34968;
v_34964:
    v_35016 = stack[-1];
    fn = elt(env, 9); // reorder
    stack[0] = (*qfn1(fn))(fn, v_35016);
    env = stack[-7];
    goto v_34965;
v_34966:
    goto v_34976;
v_34972:
    v_35017 = stack[-1];
    goto v_34973;
v_34974:
    v_35016 = nil;
    goto v_34975;
v_34976:
    goto v_34972;
v_34973:
    goto v_34974;
v_34975:
    fn = elt(env, 13); // total!-degree!-in!-powers
    v_35016 = (*qfn2(fn))(fn, v_35017, v_35016);
    env = stack[-7];
    goto v_34967;
v_34968:
    goto v_34964;
v_34965:
    goto v_34966;
v_34967:
    v_35016 = cons(stack[0], v_35016);
    env = stack[-7];
    v_35016 = ncons(v_35016);
    env = stack[-7];
    stack[-3] = v_35016;
    stack[-4] = v_35016;
v_34951:
    v_35016 = stack[-5];
    v_35016 = qcdr(v_35016);
    stack[-5] = v_35016;
    v_35016 = stack[-5];
    if (v_35016 == nil) goto v_34983;
    else goto v_34984;
v_34983:
    v_35016 = stack[-4];
    goto v_34950;
v_34984:
    goto v_34992;
v_34988:
    stack[-2] = stack[-3];
    goto v_34989;
v_34990:
    v_35016 = stack[-5];
    v_35016 = qcar(v_35016);
    stack[-1] = v_35016;
    goto v_35003;
v_34999:
    v_35016 = stack[-1];
    fn = elt(env, 9); // reorder
    stack[0] = (*qfn1(fn))(fn, v_35016);
    env = stack[-7];
    goto v_35000;
v_35001:
    goto v_35011;
v_35007:
    v_35017 = stack[-1];
    goto v_35008;
v_35009:
    v_35016 = nil;
    goto v_35010;
v_35011:
    goto v_35007;
v_35008:
    goto v_35009;
v_35010:
    fn = elt(env, 13); // total!-degree!-in!-powers
    v_35016 = (*qfn2(fn))(fn, v_35017, v_35016);
    env = stack[-7];
    goto v_35002;
v_35003:
    goto v_34999;
v_35000:
    goto v_35001;
v_35002:
    v_35016 = cons(stack[0], v_35016);
    env = stack[-7];
    v_35016 = ncons(v_35016);
    env = stack[-7];
    goto v_34991;
v_34992:
    goto v_34988;
v_34989:
    goto v_34990;
v_34991:
    v_35016 = Lrplacd(nil, stack[-2], v_35016);
    env = stack[-7];
    v_35016 = stack[-3];
    v_35016 = qcdr(v_35016);
    stack[-3] = v_35016;
    goto v_34951;
v_34950:
    v_35016 = CC_gcdlist1(elt(env, 0), v_35016);
v_34732:
    ;}  // end of a binding scope
    return onevalue(v_35016);
}



// Code for get!-min!-degreelist

static LispObject CC_getKminKdegreelist(LispObject env,
                         LispObject v_34723)
{
    env = qenv(env);
    LispObject v_34842, v_34843;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34723);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_34843 = v_34723;
// end of prologue
    v_34842 = v_34843;
    if (v_34842 == nil) goto v_34727;
    else goto v_34728;
v_34727:
    v_34842 = elt(env, 0); // get!-min!-degreelist
    {
        fn = elt(env, 1); // confusion
        return (*qfn1(fn))(fn, v_34842);
    }
v_34728:
    v_34842 = v_34843;
    v_34842 = qcdr(v_34842);
    if (v_34842 == nil) goto v_34732;
    else goto v_34733;
v_34732:
    v_34842 = v_34843;
    v_34842 = qcar(v_34842);
    v_34842 = qcar(v_34842);
    stack[-4] = v_34842;
    v_34842 = stack[-4];
    if (v_34842 == nil) goto v_34747;
    else goto v_34748;
v_34747:
    v_34842 = nil;
    goto v_34740;
v_34748:
    v_34842 = stack[-4];
    v_34842 = qcar(v_34842);
    stack[0] = v_34842;
    v_34842 = (LispObject)0+TAG_FIXNUM; // 0
    v_34843 = v_34842;
v_34759:
    v_34842 = stack[0];
    if (v_34842 == nil) goto v_34764;
    else goto v_34765;
v_34764:
    v_34842 = v_34843;
    goto v_34758;
v_34765:
    goto v_34773;
v_34769:
    v_34842 = stack[0];
    v_34842 = qcar(v_34842);
    goto v_34770;
v_34771:
    goto v_34772;
v_34773:
    goto v_34769;
v_34770:
    goto v_34771;
v_34772:
    fn = elt(env, 2); // tayexp!-plus2
    v_34842 = (*qfn2(fn))(fn, v_34842, v_34843);
    env = stack[-5];
    v_34843 = v_34842;
    v_34842 = stack[0];
    v_34842 = qcdr(v_34842);
    stack[0] = v_34842;
    goto v_34759;
v_34758:
    v_34842 = ncons(v_34842);
    env = stack[-5];
    stack[-2] = v_34842;
    stack[-3] = v_34842;
v_34741:
    v_34842 = stack[-4];
    v_34842 = qcdr(v_34842);
    stack[-4] = v_34842;
    v_34842 = stack[-4];
    if (v_34842 == nil) goto v_34785;
    else goto v_34786;
v_34785:
    v_34842 = stack[-3];
    goto v_34740;
v_34786:
    goto v_34794;
v_34790:
    stack[-1] = stack[-2];
    goto v_34791;
v_34792:
    v_34842 = stack[-4];
    v_34842 = qcar(v_34842);
    stack[0] = v_34842;
    v_34842 = (LispObject)0+TAG_FIXNUM; // 0
    v_34843 = v_34842;
v_34804:
    v_34842 = stack[0];
    if (v_34842 == nil) goto v_34809;
    else goto v_34810;
v_34809:
    v_34842 = v_34843;
    goto v_34803;
v_34810:
    goto v_34818;
v_34814:
    v_34842 = stack[0];
    v_34842 = qcar(v_34842);
    goto v_34815;
v_34816:
    goto v_34817;
v_34818:
    goto v_34814;
v_34815:
    goto v_34816;
v_34817:
    fn = elt(env, 2); // tayexp!-plus2
    v_34842 = (*qfn2(fn))(fn, v_34842, v_34843);
    env = stack[-5];
    v_34843 = v_34842;
    v_34842 = stack[0];
    v_34842 = qcdr(v_34842);
    stack[0] = v_34842;
    goto v_34804;
v_34803:
    v_34842 = ncons(v_34842);
    env = stack[-5];
    goto v_34793;
v_34794:
    goto v_34790;
v_34791:
    goto v_34792;
v_34793:
    v_34842 = Lrplacd(nil, stack[-1], v_34842);
    env = stack[-5];
    v_34842 = stack[-2];
    v_34842 = qcdr(v_34842);
    stack[-2] = v_34842;
    goto v_34741;
v_34740:
    goto v_34726;
v_34733:
    goto v_34835;
v_34831:
    v_34842 = v_34843;
    v_34842 = qcar(v_34842);
    stack[0] = qcar(v_34842);
    goto v_34832;
v_34833:
    v_34842 = v_34843;
    v_34842 = qcdr(v_34842);
    v_34842 = CC_getKminKdegreelist(elt(env, 0), v_34842);
    env = stack[-5];
    goto v_34834;
v_34835:
    goto v_34831;
v_34832:
    goto v_34833;
v_34834:
    {
        LispObject v_34849 = stack[0];
        fn = elt(env, 3); // taymindegreel
        return (*qfn2(fn))(fn, v_34849, v_34842);
    }
    v_34842 = nil;
v_34726:
    return onevalue(v_34842);
}



// Code for cl_subfof1

static LispObject CC_cl_subfof1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_35457, v_35458, v_35459, v_35460;
    LispObject fn;
    LispObject v_34726, v_34725, v_34724, v_34723;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_subfof1");
    va_start(aa, nargs);
    v_34723 = va_arg(aa, LispObject);
    v_34724 = va_arg(aa, LispObject);
    v_34725 = va_arg(aa, LispObject);
    v_34726 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_34726,v_34725,v_34724,v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_34723,v_34724,v_34725,v_34726);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-7] = v_34726;
    stack[-2] = v_34725;
    v_35459 = v_34724;
    stack[-8] = v_34723;
// end of prologue
    v_35457 = v_35459;
    if (!consp(v_35457)) goto v_34737;
    else goto v_34738;
v_34737:
    v_35457 = v_35459;
    goto v_34736;
v_34738:
    v_35457 = v_35459;
    v_35457 = qcar(v_35457);
    goto v_34736;
    v_35457 = nil;
v_34736:
    stack[-9] = v_35457;
    goto v_34757;
v_34753:
    v_35458 = stack[-9];
    goto v_34754;
v_34755:
    v_35457 = elt(env, 1); // true
    goto v_34756;
v_34757:
    goto v_34753;
v_34754:
    goto v_34755;
v_34756:
    if (v_35458 == v_35457) goto v_34751;
    else goto v_34752;
v_34751:
    v_35457 = lisp_true;
    goto v_34750;
v_34752:
    goto v_34767;
v_34763:
    v_35458 = stack[-9];
    goto v_34764;
v_34765:
    v_35457 = elt(env, 2); // false
    goto v_34766;
v_34767:
    goto v_34763;
v_34764:
    goto v_34765;
v_34766:
    v_35457 = (v_35458 == v_35457 ? lisp_true : nil);
    goto v_34750;
    v_35457 = nil;
v_34750:
    if (v_35457 == nil) goto v_34748;
    v_35457 = v_35459;
    goto v_34734;
v_34748:
    goto v_34784;
v_34780:
    v_35458 = stack[-9];
    goto v_34781;
v_34782:
    v_35457 = elt(env, 3); // ex
    goto v_34783;
v_34784:
    goto v_34780;
v_34781:
    goto v_34782;
v_34783:
    if (v_35458 == v_35457) goto v_34778;
    else goto v_34779;
v_34778:
    v_35457 = lisp_true;
    goto v_34777;
v_34779:
    goto v_34794;
v_34790:
    v_35458 = stack[-9];
    goto v_34791;
v_34792:
    v_35457 = elt(env, 4); // all
    goto v_34793;
v_34794:
    goto v_34790;
v_34791:
    goto v_34792;
v_34793:
    v_35457 = (v_35458 == v_35457 ? lisp_true : nil);
    goto v_34777;
    v_35457 = nil;
v_34777:
    if (v_35457 == nil) goto v_34775;
    v_35457 = v_35459;
    v_35457 = qcdr(v_35457);
    v_35457 = qcar(v_35457);
    stack[-6] = v_35457;
    v_35457 = v_35459;
    v_35457 = qcdr(v_35457);
    v_35457 = qcdr(v_35457);
    v_35457 = qcar(v_35457);
    stack[-5] = v_35457;
    v_35457 = stack[-8];
    stack[-4] = v_35457;
v_34810:
    v_35457 = stack[-4];
    if (v_35457 == nil) goto v_34815;
    else goto v_34816;
v_34815:
    v_35457 = nil;
    goto v_34809;
v_34816:
    v_35457 = stack[-4];
    v_35457 = qcar(v_35457);
    v_35459 = v_35457;
    goto v_34831;
v_34827:
    v_35458 = v_35459;
    goto v_34828;
v_34829:
    v_35457 = stack[-6];
    goto v_34830;
v_34831:
    goto v_34827;
v_34828:
    goto v_34829;
v_34830:
    if (!consp(v_35458)) goto v_34824;
    v_35458 = qcar(v_35458);
    if (v_35458 == v_35457) goto v_34825;
v_34824:
    v_35457 = v_35459;
    v_35457 = ncons(v_35457);
    env = stack[-10];
    goto v_34823;
v_34825:
    v_35457 = nil;
v_34823:
    stack[-3] = v_35457;
    v_35457 = stack[-3];
    fn = elt(env, 13); // lastpair
    v_35457 = (*qfn1(fn))(fn, v_35457);
    env = stack[-10];
    stack[-1] = v_35457;
    v_35457 = stack[-4];
    v_35457 = qcdr(v_35457);
    stack[-4] = v_35457;
    v_35457 = stack[-1];
    if (!consp(v_35457)) goto v_34842;
    else goto v_34843;
v_34842:
    goto v_34810;
v_34843:
v_34811:
    v_35457 = stack[-4];
    if (v_35457 == nil) goto v_34847;
    else goto v_34848;
v_34847:
    v_35457 = stack[-3];
    goto v_34809;
v_34848:
    goto v_34856;
v_34852:
    stack[0] = stack[-1];
    goto v_34853;
v_34854:
    v_35457 = stack[-4];
    v_35457 = qcar(v_35457);
    v_35459 = v_35457;
    goto v_34870;
v_34866:
    v_35458 = v_35459;
    goto v_34867;
v_34868:
    v_35457 = stack[-6];
    goto v_34869;
v_34870:
    goto v_34866;
v_34867:
    goto v_34868;
v_34869:
    if (!consp(v_35458)) goto v_34863;
    v_35458 = qcar(v_35458);
    if (v_35458 == v_35457) goto v_34864;
v_34863:
    v_35457 = v_35459;
    v_35457 = ncons(v_35457);
    env = stack[-10];
    goto v_34862;
v_34864:
    v_35457 = nil;
v_34862:
    goto v_34855;
v_34856:
    goto v_34852;
v_34853:
    goto v_34854;
v_34855:
    v_35457 = Lrplacd(nil, stack[0], v_35457);
    env = stack[-10];
    v_35457 = stack[-1];
    fn = elt(env, 13); // lastpair
    v_35457 = (*qfn1(fn))(fn, v_35457);
    env = stack[-10];
    stack[-1] = v_35457;
    v_35457 = stack[-4];
    v_35457 = qcdr(v_35457);
    stack[-4] = v_35457;
    goto v_34811;
v_34809:
    stack[-8] = v_35457;
    v_35457 = stack[-2];
    stack[-3] = v_35457;
v_34884:
    v_35457 = stack[-3];
    if (v_35457 == nil) goto v_34889;
    else goto v_34890;
v_34889:
    v_35457 = nil;
    goto v_34883;
v_34890:
    v_35457 = stack[-3];
    v_35457 = qcar(v_35457);
    v_35459 = v_35457;
    goto v_34905;
v_34901:
    v_35458 = v_35459;
    goto v_34902;
v_34903:
    v_35457 = stack[-6];
    goto v_34904;
v_34905:
    goto v_34901;
v_34902:
    goto v_34903;
v_34904:
    if (!consp(v_35458)) goto v_34898;
    v_35458 = qcar(v_35458);
    if (v_35458 == v_35457) goto v_34899;
v_34898:
    v_35457 = v_35459;
    v_35457 = ncons(v_35457);
    env = stack[-10];
    goto v_34897;
v_34899:
    v_35457 = nil;
v_34897:
    stack[-2] = v_35457;
    v_35457 = stack[-2];
    fn = elt(env, 13); // lastpair
    v_35457 = (*qfn1(fn))(fn, v_35457);
    env = stack[-10];
    stack[-1] = v_35457;
    v_35457 = stack[-3];
    v_35457 = qcdr(v_35457);
    stack[-3] = v_35457;
    v_35457 = stack[-1];
    if (!consp(v_35457)) goto v_34916;
    else goto v_34917;
v_34916:
    goto v_34884;
v_34917:
v_34885:
    v_35457 = stack[-3];
    if (v_35457 == nil) goto v_34921;
    else goto v_34922;
v_34921:
    v_35457 = stack[-2];
    goto v_34883;
v_34922:
    goto v_34930;
v_34926:
    stack[0] = stack[-1];
    goto v_34927;
v_34928:
    v_35457 = stack[-3];
    v_35457 = qcar(v_35457);
    v_35459 = v_35457;
    goto v_34944;
v_34940:
    v_35458 = v_35459;
    goto v_34941;
v_34942:
    v_35457 = stack[-6];
    goto v_34943;
v_34944:
    goto v_34940;
v_34941:
    goto v_34942;
v_34943:
    if (!consp(v_35458)) goto v_34937;
    v_35458 = qcar(v_35458);
    if (v_35458 == v_35457) goto v_34938;
v_34937:
    v_35457 = v_35459;
    v_35457 = ncons(v_35457);
    env = stack[-10];
    goto v_34936;
v_34938:
    v_35457 = nil;
v_34936:
    goto v_34929;
v_34930:
    goto v_34926;
v_34927:
    goto v_34928;
v_34929:
    v_35457 = Lrplacd(nil, stack[0], v_35457);
    env = stack[-10];
    v_35457 = stack[-1];
    fn = elt(env, 13); // lastpair
    v_35457 = (*qfn1(fn))(fn, v_35457);
    env = stack[-10];
    stack[-1] = v_35457;
    v_35457 = stack[-3];
    v_35457 = qcdr(v_35457);
    stack[-3] = v_35457;
    goto v_34885;
v_34883:
    stack[-2] = v_35457;
    goto v_34962;
v_34954:
    v_35460 = stack[-6];
    goto v_34955;
v_34956:
    v_35459 = stack[-5];
    goto v_34957;
v_34958:
    v_35458 = stack[-2];
    goto v_34959;
v_34960:
    v_35457 = stack[-7];
    goto v_34961;
v_34962:
    goto v_34954;
v_34955:
    goto v_34956;
v_34957:
    goto v_34958;
v_34959:
    goto v_34960;
v_34961:
    fn = elt(env, 14); // cl_newv
    v_35457 = (*qfnn(fn))(fn, 4, v_35460, v_35459, v_35458, v_35457);
    env = stack[-10];
    stack[0] = v_35457;
    goto v_34975;
v_34971:
    v_35458 = stack[0];
    goto v_34972;
v_34973:
    v_35457 = stack[-6];
    goto v_34974;
v_34975:
    goto v_34971;
v_34972:
    goto v_34973;
v_34974:
    if (equal(v_35458, v_35457)) goto v_34970;
    goto v_34983;
v_34979:
    v_35458 = stack[0];
    goto v_34980;
v_34981:
    v_35457 = stack[-7];
    goto v_34982;
v_34983:
    goto v_34979;
v_34980:
    goto v_34981;
v_34982:
    v_35457 = cons(v_35458, v_35457);
    env = stack[-10];
    stack[-7] = v_35457;
    goto v_34993;
v_34987:
    v_35459 = stack[0];
    goto v_34988;
v_34989:
    v_35458 = stack[-6];
    goto v_34990;
v_34991:
    v_35457 = stack[-5];
    goto v_34992;
v_34993:
    goto v_34987;
v_34988:
    goto v_34989;
v_34990:
    goto v_34991;
v_34992:
    fn = elt(env, 15); // cl_subvarsubstat
    v_35457 = (*qfnn(fn))(fn, 3, v_35459, v_35458, v_35457);
    env = stack[-10];
    stack[-5] = v_35457;
    goto v_34968;
v_34970:
v_34968:
    goto v_35004;
v_34998:
    stack[-1] = stack[-9];
    goto v_34999;
v_35000:
    goto v_35001;
v_35002:
    goto v_35016;
v_35008:
    v_35460 = stack[-8];
    goto v_35009;
v_35010:
    v_35459 = stack[-5];
    goto v_35011;
v_35012:
    v_35458 = stack[-2];
    goto v_35013;
v_35014:
    v_35457 = stack[-7];
    goto v_35015;
v_35016:
    goto v_35008;
v_35009:
    goto v_35010;
v_35011:
    goto v_35012;
v_35013:
    goto v_35014;
v_35015:
    v_35457 = CC_cl_subfof1(elt(env, 0), 4, v_35460, v_35459, v_35458, v_35457);
    goto v_35003;
v_35004:
    goto v_34998;
v_34999:
    goto v_35000;
v_35001:
    goto v_35002;
v_35003:
    {
        LispObject v_35471 = stack[-1];
        LispObject v_35472 = stack[0];
        return list3(v_35471, v_35472, v_35457);
    }
v_34775:
    goto v_35033;
v_35029:
    v_35458 = stack[-9];
    goto v_35030;
v_35031:
    v_35457 = elt(env, 5); // bex
    goto v_35032;
v_35033:
    goto v_35029;
v_35030:
    goto v_35031;
v_35032:
    if (v_35458 == v_35457) goto v_35027;
    else goto v_35028;
v_35027:
    v_35457 = lisp_true;
    goto v_35026;
v_35028:
    goto v_35043;
v_35039:
    v_35458 = stack[-9];
    goto v_35040;
v_35041:
    v_35457 = elt(env, 6); // ball
    goto v_35042;
v_35043:
    goto v_35039;
v_35040:
    goto v_35041;
v_35042:
    v_35457 = (v_35458 == v_35457 ? lisp_true : nil);
    goto v_35026;
    v_35457 = nil;
v_35026:
    if (v_35457 == nil) goto v_35024;
    v_35457 = v_35459;
    v_35457 = qcdr(v_35457);
    v_35457 = qcar(v_35457);
    stack[-6] = v_35457;
    v_35457 = v_35459;
    v_35457 = qcdr(v_35457);
    v_35457 = qcdr(v_35457);
    v_35457 = qcar(v_35457);
    stack[-5] = v_35457;
    v_35457 = v_35459;
    v_35457 = qcdr(v_35457);
    v_35457 = qcdr(v_35457);
    v_35457 = qcdr(v_35457);
    v_35457 = qcar(v_35457);
    stack[-4] = v_35457;
    v_35457 = stack[-8];
    stack[-8] = v_35457;
v_35064:
    v_35457 = stack[-8];
    if (v_35457 == nil) goto v_35069;
    else goto v_35070;
v_35069:
    v_35457 = nil;
    goto v_35063;
v_35070:
    v_35457 = stack[-8];
    v_35457 = qcar(v_35457);
    v_35459 = v_35457;
    goto v_35085;
v_35081:
    v_35458 = v_35459;
    goto v_35082;
v_35083:
    v_35457 = stack[-6];
    goto v_35084;
v_35085:
    goto v_35081;
v_35082:
    goto v_35083;
v_35084:
    if (!consp(v_35458)) goto v_35078;
    v_35458 = qcar(v_35458);
    if (v_35458 == v_35457) goto v_35079;
v_35078:
    v_35457 = v_35459;
    v_35457 = ncons(v_35457);
    env = stack[-10];
    goto v_35077;
v_35079:
    v_35457 = nil;
v_35077:
    stack[-3] = v_35457;
    v_35457 = stack[-3];
    fn = elt(env, 13); // lastpair
    v_35457 = (*qfn1(fn))(fn, v_35457);
    env = stack[-10];
    stack[-1] = v_35457;
    v_35457 = stack[-8];
    v_35457 = qcdr(v_35457);
    stack[-8] = v_35457;
    v_35457 = stack[-1];
    if (!consp(v_35457)) goto v_35096;
    else goto v_35097;
v_35096:
    goto v_35064;
v_35097:
v_35065:
    v_35457 = stack[-8];
    if (v_35457 == nil) goto v_35101;
    else goto v_35102;
v_35101:
    v_35457 = stack[-3];
    goto v_35063;
v_35102:
    goto v_35110;
v_35106:
    stack[0] = stack[-1];
    goto v_35107;
v_35108:
    v_35457 = stack[-8];
    v_35457 = qcar(v_35457);
    v_35459 = v_35457;
    goto v_35124;
v_35120:
    v_35458 = v_35459;
    goto v_35121;
v_35122:
    v_35457 = stack[-6];
    goto v_35123;
v_35124:
    goto v_35120;
v_35121:
    goto v_35122;
v_35123:
    if (!consp(v_35458)) goto v_35117;
    v_35458 = qcar(v_35458);
    if (v_35458 == v_35457) goto v_35118;
v_35117:
    v_35457 = v_35459;
    v_35457 = ncons(v_35457);
    env = stack[-10];
    goto v_35116;
v_35118:
    v_35457 = nil;
v_35116:
    goto v_35109;
v_35110:
    goto v_35106;
v_35107:
    goto v_35108;
v_35109:
    v_35457 = Lrplacd(nil, stack[0], v_35457);
    env = stack[-10];
    v_35457 = stack[-1];
    fn = elt(env, 13); // lastpair
    v_35457 = (*qfn1(fn))(fn, v_35457);
    env = stack[-10];
    stack[-1] = v_35457;
    v_35457 = stack[-8];
    v_35457 = qcdr(v_35457);
    stack[-8] = v_35457;
    goto v_35065;
v_35063:
    stack[-8] = v_35457;
    v_35457 = stack[-2];
    stack[-3] = v_35457;
v_35138:
    v_35457 = stack[-3];
    if (v_35457 == nil) goto v_35143;
    else goto v_35144;
v_35143:
    v_35457 = nil;
    goto v_35137;
v_35144:
    v_35457 = stack[-3];
    v_35457 = qcar(v_35457);
    v_35459 = v_35457;
    goto v_35159;
v_35155:
    v_35458 = v_35459;
    goto v_35156;
v_35157:
    v_35457 = stack[-6];
    goto v_35158;
v_35159:
    goto v_35155;
v_35156:
    goto v_35157;
v_35158:
    if (!consp(v_35458)) goto v_35152;
    v_35458 = qcar(v_35458);
    if (v_35458 == v_35457) goto v_35153;
v_35152:
    v_35457 = v_35459;
    v_35457 = ncons(v_35457);
    env = stack[-10];
    goto v_35151;
v_35153:
    v_35457 = nil;
v_35151:
    stack[-2] = v_35457;
    v_35457 = stack[-2];
    fn = elt(env, 13); // lastpair
    v_35457 = (*qfn1(fn))(fn, v_35457);
    env = stack[-10];
    stack[-1] = v_35457;
    v_35457 = stack[-3];
    v_35457 = qcdr(v_35457);
    stack[-3] = v_35457;
    v_35457 = stack[-1];
    if (!consp(v_35457)) goto v_35170;
    else goto v_35171;
v_35170:
    goto v_35138;
v_35171:
v_35139:
    v_35457 = stack[-3];
    if (v_35457 == nil) goto v_35175;
    else goto v_35176;
v_35175:
    v_35457 = stack[-2];
    goto v_35137;
v_35176:
    goto v_35184;
v_35180:
    stack[0] = stack[-1];
    goto v_35181;
v_35182:
    v_35457 = stack[-3];
    v_35457 = qcar(v_35457);
    v_35459 = v_35457;
    goto v_35198;
v_35194:
    v_35458 = v_35459;
    goto v_35195;
v_35196:
    v_35457 = stack[-6];
    goto v_35197;
v_35198:
    goto v_35194;
v_35195:
    goto v_35196;
v_35197:
    if (!consp(v_35458)) goto v_35191;
    v_35458 = qcar(v_35458);
    if (v_35458 == v_35457) goto v_35192;
v_35191:
    v_35457 = v_35459;
    v_35457 = ncons(v_35457);
    env = stack[-10];
    goto v_35190;
v_35192:
    v_35457 = nil;
v_35190:
    goto v_35183;
v_35184:
    goto v_35180;
v_35181:
    goto v_35182;
v_35183:
    v_35457 = Lrplacd(nil, stack[0], v_35457);
    env = stack[-10];
    v_35457 = stack[-1];
    fn = elt(env, 13); // lastpair
    v_35457 = (*qfn1(fn))(fn, v_35457);
    env = stack[-10];
    stack[-1] = v_35457;
    v_35457 = stack[-3];
    v_35457 = qcdr(v_35457);
    stack[-3] = v_35457;
    goto v_35139;
v_35137:
    stack[-2] = v_35457;
    goto v_35216;
v_35208:
    v_35460 = stack[-6];
    goto v_35209;
v_35210:
    v_35459 = stack[-5];
    goto v_35211;
v_35212:
    v_35458 = stack[-2];
    goto v_35213;
v_35214:
    v_35457 = stack[-7];
    goto v_35215;
v_35216:
    goto v_35208;
v_35209:
    goto v_35210;
v_35211:
    goto v_35212;
v_35213:
    goto v_35214;
v_35215:
    fn = elt(env, 14); // cl_newv
    v_35457 = (*qfnn(fn))(fn, 4, v_35460, v_35459, v_35458, v_35457);
    env = stack[-10];
    stack[0] = v_35457;
    goto v_35229;
v_35225:
    v_35458 = stack[0];
    goto v_35226;
v_35227:
    v_35457 = stack[-6];
    goto v_35228;
v_35229:
    goto v_35225;
v_35226:
    goto v_35227;
v_35228:
    if (equal(v_35458, v_35457)) goto v_35224;
    goto v_35237;
v_35233:
    v_35458 = stack[0];
    goto v_35234;
v_35235:
    v_35457 = stack[-7];
    goto v_35236;
v_35237:
    goto v_35233;
v_35234:
    goto v_35235;
v_35236:
    v_35457 = cons(v_35458, v_35457);
    env = stack[-10];
    stack[-7] = v_35457;
    goto v_35247;
v_35241:
    v_35459 = stack[0];
    goto v_35242;
v_35243:
    v_35458 = stack[-6];
    goto v_35244;
v_35245:
    v_35457 = stack[-5];
    goto v_35246;
v_35247:
    goto v_35241;
v_35242:
    goto v_35243;
v_35244:
    goto v_35245;
v_35246:
    fn = elt(env, 15); // cl_subvarsubstat
    v_35457 = (*qfnn(fn))(fn, 3, v_35459, v_35458, v_35457);
    env = stack[-10];
    stack[-5] = v_35457;
    goto v_35222;
v_35224:
v_35222:
    goto v_35260;
v_35252:
    stack[-1] = stack[-9];
    goto v_35253;
v_35254:
    goto v_35255;
v_35256:
    goto v_35272;
v_35264:
    v_35460 = stack[-8];
    goto v_35265;
v_35266:
    v_35459 = stack[-5];
    goto v_35267;
v_35268:
    v_35458 = stack[-2];
    goto v_35269;
v_35270:
    v_35457 = stack[-7];
    goto v_35271;
v_35272:
    goto v_35264;
v_35265:
    goto v_35266;
v_35267:
    goto v_35268;
v_35269:
    goto v_35270;
v_35271:
    stack[-3] = CC_cl_subfof1(elt(env, 0), 4, v_35460, v_35459, v_35458, v_35457);
    env = stack[-10];
    goto v_35257;
v_35258:
    goto v_35286;
v_35278:
    v_35460 = stack[-8];
    goto v_35279;
v_35280:
    v_35459 = stack[-4];
    goto v_35281;
v_35282:
    v_35458 = stack[-2];
    goto v_35283;
v_35284:
    v_35457 = stack[-7];
    goto v_35285;
v_35286:
    goto v_35278;
v_35279:
    goto v_35280;
v_35281:
    goto v_35282;
v_35283:
    goto v_35284;
v_35285:
    v_35457 = CC_cl_subfof1(elt(env, 0), 4, v_35460, v_35459, v_35458, v_35457);
    goto v_35259;
v_35260:
    goto v_35252;
v_35253:
    goto v_35254;
v_35255:
    goto v_35256;
v_35257:
    goto v_35258;
v_35259:
    {
        LispObject v_35473 = stack[-1];
        LispObject v_35474 = stack[0];
        LispObject v_35475 = stack[-3];
        return list4(v_35473, v_35474, v_35475, v_35457);
    }
v_35024:
    goto v_35311;
v_35307:
    v_35458 = stack[-9];
    goto v_35308;
v_35309:
    v_35457 = elt(env, 7); // or
    goto v_35310;
v_35311:
    goto v_35307;
v_35308:
    goto v_35309;
v_35310:
    if (v_35458 == v_35457) goto v_35305;
    else goto v_35306;
v_35305:
    v_35457 = lisp_true;
    goto v_35304;
v_35306:
    goto v_35321;
v_35317:
    v_35458 = stack[-9];
    goto v_35318;
v_35319:
    v_35457 = elt(env, 8); // and
    goto v_35320;
v_35321:
    goto v_35317;
v_35318:
    goto v_35319;
v_35320:
    v_35457 = (v_35458 == v_35457 ? lisp_true : nil);
    goto v_35304;
    v_35457 = nil;
v_35304:
    if (v_35457 == nil) goto v_35302;
    v_35457 = lisp_true;
    goto v_35300;
v_35302:
    goto v_35332;
v_35328:
    v_35458 = stack[-9];
    goto v_35329;
v_35330:
    v_35457 = elt(env, 9); // not
    goto v_35331;
v_35332:
    goto v_35328;
v_35329:
    goto v_35330;
v_35331:
    v_35457 = (v_35458 == v_35457 ? lisp_true : nil);
    goto v_35300;
    v_35457 = nil;
v_35300:
    if (v_35457 == nil) goto v_35298;
    v_35457 = lisp_true;
    goto v_35296;
v_35298:
    goto v_35347;
v_35343:
    v_35458 = stack[-9];
    goto v_35344;
v_35345:
    v_35457 = elt(env, 10); // impl
    goto v_35346;
v_35347:
    goto v_35343;
v_35344:
    goto v_35345;
v_35346:
    if (v_35458 == v_35457) goto v_35341;
    else goto v_35342;
v_35341:
    v_35457 = lisp_true;
    goto v_35340;
v_35342:
    goto v_35361;
v_35357:
    v_35458 = stack[-9];
    goto v_35358;
v_35359:
    v_35457 = elt(env, 11); // repl
    goto v_35360;
v_35361:
    goto v_35357;
v_35358:
    goto v_35359;
v_35360:
    if (v_35458 == v_35457) goto v_35355;
    else goto v_35356;
v_35355:
    v_35457 = lisp_true;
    goto v_35354;
v_35356:
    goto v_35371;
v_35367:
    v_35458 = stack[-9];
    goto v_35368;
v_35369:
    v_35457 = elt(env, 12); // equiv
    goto v_35370;
v_35371:
    goto v_35367;
v_35368:
    goto v_35369;
v_35370:
    v_35457 = (v_35458 == v_35457 ? lisp_true : nil);
    goto v_35354;
    v_35457 = nil;
v_35354:
    goto v_35340;
    v_35457 = nil;
v_35340:
    goto v_35296;
    v_35457 = nil;
v_35296:
    if (v_35457 == nil) goto v_35294;
    goto v_35380;
v_35376:
    stack[-5] = stack[-9];
    goto v_35377;
v_35378:
    v_35457 = v_35459;
    v_35457 = qcdr(v_35457);
    stack[-4] = v_35457;
    v_35457 = stack[-4];
    if (v_35457 == nil) goto v_35392;
    else goto v_35393;
v_35392:
    v_35457 = nil;
    goto v_35386;
v_35393:
    v_35457 = stack[-4];
    v_35457 = qcar(v_35457);
    goto v_35409;
v_35401:
    v_35460 = stack[-8];
    goto v_35402;
v_35403:
    v_35459 = v_35457;
    goto v_35404;
v_35405:
    v_35458 = stack[-2];
    goto v_35406;
v_35407:
    v_35457 = stack[-7];
    goto v_35408;
v_35409:
    goto v_35401;
v_35402:
    goto v_35403;
v_35404:
    goto v_35405;
v_35406:
    goto v_35407;
v_35408:
    v_35457 = CC_cl_subfof1(elt(env, 0), 4, v_35460, v_35459, v_35458, v_35457);
    env = stack[-10];
    v_35457 = ncons(v_35457);
    env = stack[-10];
    stack[-1] = v_35457;
    stack[-3] = v_35457;
v_35387:
    v_35457 = stack[-4];
    v_35457 = qcdr(v_35457);
    stack[-4] = v_35457;
    v_35457 = stack[-4];
    if (v_35457 == nil) goto v_35418;
    else goto v_35419;
v_35418:
    v_35457 = stack[-3];
    goto v_35386;
v_35419:
    goto v_35427;
v_35423:
    stack[0] = stack[-1];
    goto v_35424;
v_35425:
    v_35457 = stack[-4];
    v_35457 = qcar(v_35457);
    goto v_35442;
v_35434:
    v_35460 = stack[-8];
    goto v_35435;
v_35436:
    v_35459 = v_35457;
    goto v_35437;
v_35438:
    v_35458 = stack[-2];
    goto v_35439;
v_35440:
    v_35457 = stack[-7];
    goto v_35441;
v_35442:
    goto v_35434;
v_35435:
    goto v_35436;
v_35437:
    goto v_35438;
v_35439:
    goto v_35440;
v_35441:
    v_35457 = CC_cl_subfof1(elt(env, 0), 4, v_35460, v_35459, v_35458, v_35457);
    env = stack[-10];
    v_35457 = ncons(v_35457);
    env = stack[-10];
    goto v_35426;
v_35427:
    goto v_35423;
v_35424:
    goto v_35425;
v_35426:
    v_35457 = Lrplacd(nil, stack[0], v_35457);
    env = stack[-10];
    v_35457 = stack[-1];
    v_35457 = qcdr(v_35457);
    stack[-1] = v_35457;
    goto v_35387;
v_35386:
    goto v_35379;
v_35380:
    goto v_35376;
v_35377:
    goto v_35378;
v_35379:
    {
        LispObject v_35476 = stack[-5];
        return cons(v_35476, v_35457);
    }
v_35294:
    goto v_35454;
v_35450:
    v_35457 = stack[-8];
    goto v_35451;
v_35452:
    v_35458 = v_35459;
    goto v_35453;
v_35454:
    goto v_35450;
v_35451:
    goto v_35452;
v_35453:
    {
        fn = elt(env, 16); // rl_subat
        return (*qfn2(fn))(fn, v_35457, v_35458);
    }
v_34734:
    return onevalue(v_35457);
}



// Code for cd_ordatp

static LispObject CC_cd_ordatp(LispObject env,
                         LispObject v_34723, LispObject v_34724)
{
    env = qenv(env);
    LispObject v_34796, v_34797, v_34798, v_34799;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_34798 = v_34724;
    v_34799 = v_34723;
// end of prologue
    goto v_34738;
v_34734:
    v_34796 = v_34799;
    v_34797 = qcar(v_34796);
    goto v_34735;
v_34736:
    v_34796 = elt(env, 1); // neq
    goto v_34737;
v_34738:
    goto v_34734;
v_34735:
    goto v_34736;
v_34737:
    if (v_34797 == v_34796) goto v_34732;
    else goto v_34733;
v_34732:
    goto v_34746;
v_34742:
    v_34796 = v_34798;
    v_34797 = qcar(v_34796);
    goto v_34743;
v_34744:
    v_34796 = elt(env, 2); // equal
    goto v_34745;
v_34746:
    goto v_34742;
v_34743:
    goto v_34744;
v_34745:
    v_34796 = (v_34797 == v_34796 ? lisp_true : nil);
    goto v_34731;
v_34733:
    v_34796 = nil;
    goto v_34731;
    v_34796 = nil;
v_34731:
    if (v_34796 == nil) goto v_34729;
    v_34796 = lisp_true;
    goto v_34727;
v_34729:
    goto v_34765;
v_34761:
    v_34796 = v_34799;
    v_34797 = qcar(v_34796);
    goto v_34762;
v_34763:
    v_34796 = elt(env, 2); // equal
    goto v_34764;
v_34765:
    goto v_34761;
v_34762:
    goto v_34763;
v_34764:
    if (v_34797 == v_34796) goto v_34759;
    else goto v_34760;
v_34759:
    goto v_34773;
v_34769:
    v_34796 = v_34798;
    v_34797 = qcar(v_34796);
    goto v_34770;
v_34771:
    v_34796 = elt(env, 1); // neq
    goto v_34772;
v_34773:
    goto v_34769;
v_34770:
    goto v_34771;
v_34772:
    v_34796 = (v_34797 == v_34796 ? lisp_true : nil);
    goto v_34758;
v_34760:
    v_34796 = nil;
    goto v_34758;
    v_34796 = nil;
v_34758:
    if (v_34796 == nil) goto v_34756;
    v_34796 = nil;
    goto v_34727;
v_34756:
    goto v_34789;
v_34785:
    v_34796 = v_34799;
    v_34796 = qcdr(v_34796);
    v_34796 = qcar(v_34796);
    goto v_34786;
v_34787:
    v_34797 = v_34798;
    v_34797 = qcdr(v_34797);
    v_34797 = qcar(v_34797);
    goto v_34788;
v_34789:
    goto v_34785;
v_34786:
    goto v_34787;
v_34788:
    {
        fn = elt(env, 3); // ordp
        return (*qfn2(fn))(fn, v_34796, v_34797);
    }
    v_34796 = nil;
v_34727:
    return onevalue(v_34796);
}



// Code for force!-lc

static LispObject CC_forceKlc(LispObject env,
                         LispObject v_34723, LispObject v_34724)
{
    env = qenv(env);
    LispObject v_34740, v_34741, v_34742;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_34740 = v_34724;
    v_34741 = v_34723;
// end of prologue
    goto v_34733;
v_34727:
    v_34742 = v_34741;
    v_34742 = qcar(v_34742);
    v_34742 = qcar(v_34742);
    goto v_34728;
v_34729:
    goto v_34730;
v_34731:
    v_34741 = qcdr(v_34741);
    goto v_34732;
v_34733:
    goto v_34727;
v_34728:
    goto v_34729;
v_34730:
    goto v_34731;
v_34732:
    return acons(v_34742, v_34740, v_34741);
}



// Code for compute!:intlog

static LispObject CC_computeTintlog(LispObject env,
                         LispObject v_34723)
{
    env = qenv(env);
    LispObject v_34757, v_34758, v_34759;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34723);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_34723;
// end of prologue
    goto v_34735;
v_34731:
    v_34758 = stack[0];
    goto v_34732;
v_34733:
    v_34757 = qvalue(elt(env, 1)); // intlog!:rem
    goto v_34734;
v_34735:
    goto v_34731;
v_34732:
    goto v_34733;
v_34734:
    v_34757 = Latsoc(nil, v_34758, v_34757);
    stack[-1] = v_34757;
    if (v_34757 == nil) goto v_34730;
    v_34757 = stack[-1];
    v_34757 = qcdr(v_34757);
    goto v_34728;
v_34730:
    v_34757 = stack[0];
    fn = elt(env, 2); // compute!:intlog1
    v_34757 = (*qfn1(fn))(fn, v_34757);
    env = stack[-2];
    stack[-1] = v_34757;
    goto v_34752;
v_34746:
    v_34759 = stack[0];
    goto v_34747;
v_34748:
    v_34758 = stack[-1];
    goto v_34749;
v_34750:
    v_34757 = qvalue(elt(env, 1)); // intlog!:rem
    goto v_34751;
v_34752:
    goto v_34746;
v_34747:
    goto v_34748;
v_34749:
    goto v_34750;
v_34751:
    v_34757 = acons(v_34759, v_34758, v_34757);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_34757; // intlog!:rem
    v_34757 = stack[-1];
    goto v_34728;
    v_34757 = nil;
v_34728:
    return onevalue(v_34757);
}



// Code for vdpenumerate

static LispObject CC_vdpenumerate(LispObject env,
                         LispObject v_34723)
{
    env = qenv(env);
    LispObject v_34773, v_34774, v_34775;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34723);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_34723;
// end of prologue
    v_34773 = stack[0];
    if (v_34773 == nil) goto v_34731;
    else goto v_34732;
v_34731:
    v_34773 = lisp_true;
    goto v_34730;
v_34732:
    v_34773 = stack[0];
    v_34773 = qcdr(v_34773);
    v_34773 = qcdr(v_34773);
    v_34773 = qcdr(v_34773);
    v_34773 = qcar(v_34773);
    v_34773 = (v_34773 == nil ? lisp_true : nil);
    goto v_34730;
    v_34773 = nil;
v_34730:
    if (v_34773 == nil) goto v_34728;
    v_34773 = stack[0];
    goto v_34726;
v_34728:
    v_34773 = stack[0];
    fn = elt(env, 3); // vdpsave
    v_34773 = (*qfn1(fn))(fn, v_34773);
    env = stack[-1];
    stack[0] = v_34773;
    goto v_34757;
v_34753:
    v_34774 = stack[0];
    goto v_34754;
v_34755:
    v_34773 = elt(env, 1); // number
    goto v_34756;
v_34757:
    goto v_34753;
v_34754:
    goto v_34755;
v_34756:
    fn = elt(env, 4); // vdpgetprop
    v_34773 = (*qfn2(fn))(fn, v_34774, v_34773);
    env = stack[-1];
    if (v_34773 == nil) goto v_34750;
    else goto v_34751;
v_34750:
    goto v_34767;
v_34761:
    v_34775 = stack[0];
    goto v_34762;
v_34763:
    v_34774 = elt(env, 1); // number
    goto v_34764;
v_34765:
    v_34773 = qvalue(elt(env, 2)); // pcount!*
    v_34773 = (LispObject)((intptr_t)(v_34773) + 0x10);
    qvalue(elt(env, 2)) = v_34773; // pcount!*
    goto v_34766;
v_34767:
    goto v_34761;
v_34762:
    goto v_34763;
v_34764:
    goto v_34765;
v_34766:
    fn = elt(env, 5); // vdpputprop
    v_34773 = (*qfnn(fn))(fn, 3, v_34775, v_34774, v_34773);
    stack[0] = v_34773;
    goto v_34749;
v_34751:
v_34749:
    v_34773 = stack[0];
    goto v_34726;
    v_34773 = nil;
v_34726:
    return onevalue(v_34773);
}



// Code for xnormalise

static LispObject CC_xnormalise(LispObject env,
                         LispObject v_34723)
{
    env = qenv(env);
    LispObject v_34763, v_34764;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34723);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_34723;
// end of prologue
    v_34763 = stack[0];
    if (v_34763 == nil) goto v_34727;
    else goto v_34728;
v_34727:
    v_34763 = nil;
    goto v_34726;
v_34728:
    goto v_34737;
v_34733:
    v_34763 = stack[0];
    v_34763 = qcar(v_34763);
    stack[-1] = qcdr(v_34763);
    goto v_34734;
v_34735:
    goto v_34746;
v_34742:
    v_34764 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34743;
v_34744:
    v_34763 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34745;
v_34746:
    goto v_34742;
v_34743:
    goto v_34744;
v_34745:
    v_34763 = cons(v_34764, v_34763);
    env = stack[-2];
    goto v_34736;
v_34737:
    goto v_34733;
v_34734:
    goto v_34735;
v_34736:
    if (equal(stack[-1], v_34763)) goto v_34731;
    else goto v_34732;
v_34731:
    v_34763 = stack[0];
    goto v_34726;
v_34732:
    goto v_34757;
v_34753:
    stack[-1] = stack[0];
    goto v_34754;
v_34755:
    v_34763 = stack[0];
    v_34763 = qcar(v_34763);
    v_34763 = qcdr(v_34763);
    fn = elt(env, 1); // invsq
    v_34763 = (*qfn1(fn))(fn, v_34763);
    env = stack[-2];
    goto v_34756;
v_34757:
    goto v_34753;
v_34754:
    goto v_34755;
v_34756:
    {
        LispObject v_34767 = stack[-1];
        fn = elt(env, 2); // multpfsq
        return (*qfn2(fn))(fn, v_34767, v_34763);
    }
    v_34763 = nil;
v_34726:
    return onevalue(v_34763);
}



// Code for validrule

static LispObject CC_validrule(LispObject env,
                         LispObject v_34723)
{
    env = qenv(env);
    LispObject v_34738, v_34739;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34723);
    }
// copy arguments values to proper place
    v_34738 = v_34723;
// end of prologue
    fn = elt(env, 1); // validrule1
    v_34738 = (*qfn1(fn))(fn, v_34738);
    v_34739 = v_34738;
    v_34738 = v_34739;
    if (v_34738 == nil) goto v_34730;
    else goto v_34731;
v_34730:
    v_34738 = nil;
    goto v_34729;
v_34731:
    v_34738 = v_34739;
    return ncons(v_34738);
    v_34738 = nil;
v_34729:
    return onevalue(v_34738);
}



// Code for listofvarnames

static LispObject CC_listofvarnames(LispObject env,
                         LispObject v_34723)
{
    env = qenv(env);
    LispObject v_34879, v_34880;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34723);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_34723;
// end of prologue
    v_34879 = stack[0];
    fn = elt(env, 3); // listp
    v_34879 = (*qfn1(fn))(fn, v_34879);
    env = stack[-5];
    if (v_34879 == nil) goto v_34727;
    else goto v_34728;
v_34727:
    v_34879 = elt(env, 1); // "invalid argument to listofvarnames"
    {
        fn = elt(env, 4); // rederr
        return (*qfn1(fn))(fn, v_34879);
    }
v_34728:
    v_34879 = stack[0];
    stack[-4] = v_34879;
    v_34879 = stack[-4];
    if (v_34879 == nil) goto v_34744;
    else goto v_34745;
v_34744:
    v_34879 = nil;
    goto v_34739;
v_34745:
    v_34879 = stack[-4];
    v_34879 = qcar(v_34879);
    stack[0] = v_34879;
    v_34879 = stack[0];
    fn = elt(env, 5); // domain!*p
    v_34879 = (*qfn1(fn))(fn, v_34879);
    env = stack[-5];
    if (v_34879 == nil) goto v_34755;
    goto v_34763;
v_34759:
    v_34880 = nil;
    goto v_34760;
v_34761:
    v_34879 = elt(env, 2); // free
    goto v_34762;
v_34763:
    goto v_34759;
v_34760:
    goto v_34761;
v_34762:
    v_34879 = cons(v_34880, v_34879);
    env = stack[-5];
    goto v_34753;
v_34755:
    v_34879 = stack[0];
    if (!consp(v_34879)) goto v_34766;
    else goto v_34767;
v_34766:
    goto v_34774;
v_34770:
    v_34880 = nil;
    goto v_34771;
v_34772:
    v_34879 = elt(env, 2); // free
    goto v_34773;
v_34774:
    goto v_34770;
v_34771:
    goto v_34772;
v_34773:
    v_34879 = cons(v_34880, v_34879);
    env = stack[-5];
    goto v_34753;
v_34767:
    v_34879 = stack[0];
    v_34879 = qcar(v_34879);
    if (symbolp(v_34879)) goto v_34777;
    else goto v_34778;
v_34777:
    goto v_34786;
v_34782:
    v_34879 = stack[0];
    v_34880 = qcar(v_34879);
    goto v_34783;
v_34784:
    v_34879 = elt(env, 2); // free
    goto v_34785;
v_34786:
    goto v_34782;
v_34783:
    goto v_34784;
v_34785:
    v_34879 = cons(v_34880, v_34879);
    env = stack[-5];
    goto v_34753;
v_34778:
    v_34879 = stack[0];
    v_34879 = qcar(v_34879);
    v_34879 = qcar(v_34879);
    if (symbolp(v_34879)) goto v_34790;
    else goto v_34791;
v_34790:
    goto v_34800;
v_34796:
    v_34879 = stack[0];
    v_34879 = qcar(v_34879);
    v_34880 = qcar(v_34879);
    goto v_34797;
v_34798:
    v_34879 = elt(env, 2); // free
    goto v_34799;
v_34800:
    goto v_34796;
v_34797:
    goto v_34798;
v_34799:
    v_34879 = cons(v_34880, v_34879);
    env = stack[-5];
    goto v_34753;
v_34791:
    v_34879 = nil;
v_34753:
    v_34879 = ncons(v_34879);
    env = stack[-5];
    stack[-2] = v_34879;
    stack[-3] = v_34879;
v_34740:
    v_34879 = stack[-4];
    v_34879 = qcdr(v_34879);
    stack[-4] = v_34879;
    v_34879 = stack[-4];
    if (v_34879 == nil) goto v_34809;
    else goto v_34810;
v_34809:
    v_34879 = stack[-3];
    goto v_34739;
v_34810:
    goto v_34818;
v_34814:
    stack[-1] = stack[-2];
    goto v_34815;
v_34816:
    v_34879 = stack[-4];
    v_34879 = qcar(v_34879);
    stack[0] = v_34879;
    v_34879 = stack[0];
    fn = elt(env, 5); // domain!*p
    v_34879 = (*qfn1(fn))(fn, v_34879);
    env = stack[-5];
    if (v_34879 == nil) goto v_34827;
    goto v_34835;
v_34831:
    v_34880 = nil;
    goto v_34832;
v_34833:
    v_34879 = elt(env, 2); // free
    goto v_34834;
v_34835:
    goto v_34831;
v_34832:
    goto v_34833;
v_34834:
    v_34879 = cons(v_34880, v_34879);
    env = stack[-5];
    goto v_34825;
v_34827:
    v_34879 = stack[0];
    if (!consp(v_34879)) goto v_34838;
    else goto v_34839;
v_34838:
    goto v_34846;
v_34842:
    v_34880 = nil;
    goto v_34843;
v_34844:
    v_34879 = elt(env, 2); // free
    goto v_34845;
v_34846:
    goto v_34842;
v_34843:
    goto v_34844;
v_34845:
    v_34879 = cons(v_34880, v_34879);
    env = stack[-5];
    goto v_34825;
v_34839:
    v_34879 = stack[0];
    v_34879 = qcar(v_34879);
    if (symbolp(v_34879)) goto v_34849;
    else goto v_34850;
v_34849:
    goto v_34858;
v_34854:
    v_34879 = stack[0];
    v_34880 = qcar(v_34879);
    goto v_34855;
v_34856:
    v_34879 = elt(env, 2); // free
    goto v_34857;
v_34858:
    goto v_34854;
v_34855:
    goto v_34856;
v_34857:
    v_34879 = cons(v_34880, v_34879);
    env = stack[-5];
    goto v_34825;
v_34850:
    v_34879 = stack[0];
    v_34879 = qcar(v_34879);
    v_34879 = qcar(v_34879);
    if (symbolp(v_34879)) goto v_34862;
    else goto v_34863;
v_34862:
    goto v_34872;
v_34868:
    v_34879 = stack[0];
    v_34879 = qcar(v_34879);
    v_34880 = qcar(v_34879);
    goto v_34869;
v_34870:
    v_34879 = elt(env, 2); // free
    goto v_34871;
v_34872:
    goto v_34868;
v_34869:
    goto v_34870;
v_34871:
    v_34879 = cons(v_34880, v_34879);
    env = stack[-5];
    goto v_34825;
v_34863:
    v_34879 = nil;
v_34825:
    v_34879 = ncons(v_34879);
    env = stack[-5];
    goto v_34817;
v_34818:
    goto v_34814;
v_34815:
    goto v_34816;
v_34817:
    v_34879 = Lrplacd(nil, stack[-1], v_34879);
    env = stack[-5];
    v_34879 = stack[-2];
    v_34879 = qcdr(v_34879);
    stack[-2] = v_34879;
    goto v_34740;
v_34739:
    goto v_34726;
    v_34879 = nil;
v_34726:
    return onevalue(v_34879);
}



// Code for calc_map_2d

static LispObject CC_calc_map_2d(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_34773, v_34774;
    LispObject fn;
    LispObject v_34726, v_34725, v_34724, v_34723;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "calc_map_2d");
    va_start(aa, nargs);
    v_34723 = va_arg(aa, LispObject);
    v_34724 = va_arg(aa, LispObject);
    v_34725 = va_arg(aa, LispObject);
    v_34726 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_34726,v_34725,v_34724,v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_34723,v_34724,v_34725,v_34726);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_34726;
    stack[-2] = v_34725;
    stack[-3] = v_34724;
    stack[-4] = v_34723;
// end of prologue
    goto v_34735;
v_34729:
    goto v_34743;
v_34737:
    v_34773 = stack[-4];
    v_34773 = qcar(v_34773);
    v_34773 = qcar(v_34773);
    fn = elt(env, 1); // mk_names_map_2
    stack[-5] = (*qfn1(fn))(fn, v_34773);
    env = stack[-6];
    goto v_34738;
v_34739:
    v_34773 = stack[-4];
    v_34773 = qcar(v_34773);
    stack[0] = qcdr(v_34773);
    goto v_34740;
v_34741:
    goto v_34756;
v_34752:
    v_34773 = stack[-4];
    v_34773 = qcdr(v_34773);
    v_34774 = qcar(v_34773);
    goto v_34753;
v_34754:
    v_34773 = stack[-3];
    goto v_34755;
v_34756:
    goto v_34752;
v_34753:
    goto v_34754;
v_34755:
    v_34773 = cons(v_34774, v_34773);
    env = stack[-6];
    goto v_34742;
v_34743:
    goto v_34737;
v_34738:
    goto v_34739;
v_34740:
    goto v_34741;
v_34742:
    stack[0] = list2star(stack[-5], stack[0], v_34773);
    env = stack[-6];
    goto v_34730;
v_34731:
    goto v_34732;
v_34733:
    goto v_34767;
v_34763:
    v_34773 = stack[-4];
    v_34773 = qcdr(v_34773);
    v_34773 = qcdr(v_34773);
    v_34774 = qcar(v_34773);
    goto v_34764;
v_34765:
    v_34773 = stack[-1];
    goto v_34766;
v_34767:
    goto v_34763;
v_34764:
    goto v_34765;
v_34766:
    fn = elt(env, 2); // mk_binding
    v_34773 = (*qfn2(fn))(fn, v_34774, v_34773);
    env = stack[-6];
    goto v_34734;
v_34735:
    goto v_34729;
v_34730:
    goto v_34731;
v_34732:
    goto v_34733;
v_34734:
    {
        LispObject v_34781 = stack[0];
        LispObject v_34782 = stack[-2];
        fn = elt(env, 3); // coeff_calc
        return (*qfnn(fn))(fn, 3, v_34781, v_34782, v_34773);
    }
}



// Code for !*sf2exb

static LispObject CC_Hsf2exb(LispObject env,
                         LispObject v_34723, LispObject v_34724)
{
    env = qenv(env);
    LispObject v_34795, v_34796, v_34797;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34724,v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34723,v_34724);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_34724;
    stack[-1] = v_34723;
// end of prologue
    stack[-2] = nil;
v_34729:
    goto v_34738;
v_34734:
    goto v_34744;
v_34740:
    v_34796 = stack[-1];
    goto v_34741;
v_34742:
    v_34795 = stack[0];
    goto v_34743;
v_34744:
    goto v_34740;
v_34741:
    goto v_34742;
v_34743:
    fn = elt(env, 1); // degr
    v_34796 = (*qfn2(fn))(fn, v_34796, v_34795);
    env = stack[-3];
    goto v_34735;
v_34736:
    v_34795 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34737;
v_34738:
    goto v_34734;
v_34735:
    goto v_34736;
v_34737:
    if (v_34796 == v_34795) goto v_34732;
    else goto v_34733;
v_34732:
    v_34795 = stack[-1];
    if (v_34795 == nil) goto v_34750;
    else goto v_34751;
v_34750:
    v_34795 = stack[-2];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_34795);
    }
v_34751:
    goto v_34762;
v_34758:
    stack[0] = stack[-2];
    goto v_34759;
v_34760:
    goto v_34770;
v_34766:
    v_34795 = (LispObject)0+TAG_FIXNUM; // 0
    v_34796 = ncons(v_34795);
    env = stack[-3];
    goto v_34767;
v_34768:
    v_34795 = stack[-1];
    goto v_34769;
v_34770:
    goto v_34766;
v_34767:
    goto v_34768;
v_34769:
    v_34795 = cons(v_34796, v_34795);
    env = stack[-3];
    v_34795 = ncons(v_34795);
    env = stack[-3];
    goto v_34761;
v_34762:
    goto v_34758;
v_34759:
    goto v_34760;
v_34761:
    {
        LispObject v_34801 = stack[0];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_34801, v_34795);
    }
    goto v_34731;
v_34733:
    goto v_34783;
v_34777:
    v_34795 = stack[-1];
    v_34795 = qcar(v_34795);
    v_34795 = qcar(v_34795);
    v_34795 = qcdr(v_34795);
    v_34797 = ncons(v_34795);
    env = stack[-3];
    goto v_34778;
v_34779:
    v_34795 = stack[-1];
    v_34795 = qcar(v_34795);
    v_34796 = qcdr(v_34795);
    goto v_34780;
v_34781:
    v_34795 = stack[-2];
    goto v_34782;
v_34783:
    goto v_34777;
v_34778:
    goto v_34779;
v_34780:
    goto v_34781;
v_34782:
    v_34795 = acons(v_34797, v_34796, v_34795);
    env = stack[-3];
    stack[-2] = v_34795;
    v_34795 = stack[-1];
    v_34795 = qcdr(v_34795);
    stack[-1] = v_34795;
    goto v_34729;
v_34731:
    v_34795 = nil;
    return onevalue(v_34795);
}



// Code for x!*!*p!-w

static LispObject CC_xHHpKw(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_34750, v_34751;
    LispObject fn;
    LispObject v_34725, v_34724, v_34723;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "x**p-w");
    va_start(aa, nargs);
    v_34723 = va_arg(aa, LispObject);
    v_34724 = va_arg(aa, LispObject);
    v_34725 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_34725,v_34724,v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_34723,v_34724,v_34725);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_34725;
    v_34750 = v_34724;
    v_34751 = v_34723;
// end of prologue
    goto v_34732;
v_34728:
    goto v_34739;
v_34735:
    goto v_34745;
v_34741:
    goto v_34742;
v_34743:
    goto v_34744;
v_34745:
    goto v_34741;
v_34742:
    goto v_34743;
v_34744:
    fn = elt(env, 1); // to
    v_34751 = (*qfn2(fn))(fn, v_34751, v_34750);
    env = stack[-1];
    goto v_34736;
v_34737:
    v_34750 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34738;
v_34739:
    goto v_34735;
v_34736:
    goto v_34737;
v_34738:
    v_34750 = cons(v_34751, v_34750);
    env = stack[-1];
    v_34751 = ncons(v_34750);
    env = stack[-1];
    goto v_34729;
v_34730:
    v_34750 = stack[0];
    goto v_34731;
v_34732:
    goto v_34728;
v_34729:
    goto v_34730;
v_34731:
    {
        fn = elt(env, 2); // general!-difference!-mod!-p
        return (*qfn2(fn))(fn, v_34751, v_34750);
    }
}



// Code for aex_red

static LispObject CC_aex_red(LispObject env,
                         LispObject v_34723, LispObject v_34724)
{
    env = qenv(env);
    LispObject v_34788, v_34789;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34724,v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34723,v_34724);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_34788 = v_34724;
    stack[-1] = v_34723;
// end of prologue
    goto v_34739;
v_34735:
    v_34789 = stack[-1];
    goto v_34736;
v_34737:
    goto v_34738;
v_34739:
    goto v_34735;
v_34736:
    goto v_34737;
v_34738:
    fn = elt(env, 1); // aex_mvartest
    v_34788 = (*qfn2(fn))(fn, v_34789, v_34788);
    env = stack[-3];
    if (v_34788 == nil) goto v_34733;
    v_34788 = stack[-1];
    fn = elt(env, 2); // aex_ex
    v_34788 = (*qfn1(fn))(fn, v_34788);
    env = stack[-3];
    stack[-2] = v_34788;
    goto v_34749;
v_34745:
    goto v_34755;
v_34751:
    v_34788 = stack[-2];
    v_34788 = qcar(v_34788);
    fn = elt(env, 3); // sfto_redx
    v_34789 = (*qfn1(fn))(fn, v_34788);
    env = stack[-3];
    goto v_34752;
v_34753:
    v_34788 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34754;
v_34755:
    goto v_34751;
v_34752:
    goto v_34753;
v_34754:
    stack[0] = cons(v_34789, v_34788);
    env = stack[-3];
    goto v_34746;
v_34747:
    goto v_34765;
v_34761:
    v_34788 = stack[-2];
    v_34789 = qcdr(v_34788);
    goto v_34762;
v_34763:
    v_34788 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34764;
v_34765:
    goto v_34761;
v_34762:
    goto v_34763;
v_34764:
    v_34788 = cons(v_34789, v_34788);
    env = stack[-3];
    goto v_34748;
v_34749:
    goto v_34745;
v_34746:
    goto v_34747;
v_34748:
    fn = elt(env, 4); // quotsq
    v_34788 = (*qfn2(fn))(fn, stack[0], v_34788);
    env = stack[-3];
    goto v_34774;
v_34770:
    stack[-2] = v_34788;
    goto v_34771;
v_34772:
    goto v_34781;
v_34777:
    v_34788 = qcar(v_34788);
    fn = elt(env, 5); // kernels
    stack[0] = (*qfn1(fn))(fn, v_34788);
    env = stack[-3];
    goto v_34778;
v_34779:
    v_34788 = stack[-1];
    fn = elt(env, 6); // aex_ctx
    v_34788 = (*qfn1(fn))(fn, v_34788);
    env = stack[-3];
    goto v_34780;
v_34781:
    goto v_34777;
v_34778:
    goto v_34779;
v_34780:
    fn = elt(env, 7); // ctx_filter
    v_34788 = (*qfn2(fn))(fn, stack[0], v_34788);
    env = stack[-3];
    goto v_34773;
v_34774:
    goto v_34770;
v_34771:
    goto v_34772;
v_34773:
    {
        LispObject v_34793 = stack[-2];
        fn = elt(env, 8); // aex_mk
        return (*qfn2(fn))(fn, v_34793, v_34788);
    }
v_34733:
    {
        fn = elt(env, 9); // aex_0
        return (*qfnn(fn))(fn, 0);
    }
    return onevalue(v_34788);
}



// Code for makecoeffpairs1

static LispObject CC_makecoeffpairs1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_34999, v_35000, v_35001, v_35002;
    LispObject fn;
    LispObject v_34726, v_34725, v_34724, v_34723;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "makecoeffpairs1");
    va_start(aa, nargs);
    v_34723 = va_arg(aa, LispObject);
    v_34724 = va_arg(aa, LispObject);
    v_34725 = va_arg(aa, LispObject);
    v_34726 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_34726,v_34725,v_34724,v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_34723,v_34724,v_34725,v_34726);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(16);
// copy arguments values to proper place
    stack[-10] = v_34726;
    stack[-11] = v_34725;
    stack[-12] = v_34724;
    stack[-13] = v_34723;
// end of prologue
    v_34999 = stack[-12];
    if (v_34999 == nil) goto v_34730;
    else goto v_34731;
v_34730:
    v_34999 = elt(env, 1); // ((nil))
    goto v_34729;
v_34731:
    goto v_34752;
v_34744:
    v_34999 = stack[-13];
    v_35002 = qcdr(v_34999);
    goto v_34745;
v_34746:
    v_34999 = stack[-12];
    v_35001 = qcdr(v_34999);
    goto v_34747;
v_34748:
    v_34999 = stack[-11];
    v_35000 = qcdr(v_34999);
    goto v_34749;
v_34750:
    v_34999 = stack[-10];
    v_34999 = qcdr(v_34999);
    goto v_34751;
v_34752:
    goto v_34744;
v_34745:
    goto v_34746;
v_34747:
    goto v_34748;
v_34749:
    goto v_34750;
v_34751:
    v_34999 = CC_makecoeffpairs1(elt(env, 0), 4, v_35002, v_35001, v_35000, v_34999);
    env = stack[-15];
    stack[-14] = v_34999;
v_34741:
    v_34999 = stack[-14];
    if (v_34999 == nil) goto v_34763;
    else goto v_34764;
v_34763:
    v_34999 = nil;
    goto v_34740;
v_34764:
    v_34999 = stack[-14];
    v_34999 = qcar(v_34999);
    stack[-6] = v_34999;
    goto v_34785;
v_34777:
    v_34999 = stack[-13];
    stack[-2] = qcar(v_34999);
    goto v_34778;
v_34779:
    v_34999 = stack[-12];
    stack[-1] = qcar(v_34999);
    goto v_34780;
v_34781:
    v_34999 = stack[-11];
    stack[0] = qcar(v_34999);
    goto v_34782;
v_34783:
    v_34999 = stack[-10];
    v_34999 = qcar(v_34999);
    fn = elt(env, 2); // tayexp!-minus
    v_34999 = (*qfn1(fn))(fn, v_34999);
    env = stack[-15];
    goto v_34784;
v_34785:
    goto v_34777;
v_34778:
    goto v_34779;
v_34780:
    goto v_34781;
v_34782:
    goto v_34783;
v_34784:
    fn = elt(env, 3); // makecoeffpairshom
    v_34999 = (*qfnn(fn))(fn, 4, stack[-2], stack[-1], stack[0], v_34999);
    env = stack[-15];
    stack[-5] = v_34999;
    v_34999 = stack[-5];
    if (v_34999 == nil) goto v_34797;
    else goto v_34798;
v_34797:
    v_34999 = nil;
    goto v_34774;
v_34798:
    v_34999 = stack[-5];
    v_34999 = qcar(v_34999);
    v_35000 = v_34999;
    goto v_34812;
v_34806:
    v_34999 = v_35000;
    stack[-1] = qcar(v_34999);
    goto v_34807;
v_34808:
    v_34999 = stack[-6];
    stack[0] = qcar(v_34999);
    goto v_34809;
v_34810:
    goto v_34822;
v_34818:
    v_34999 = v_35000;
    v_35000 = qcdr(v_34999);
    goto v_34819;
v_34820:
    v_34999 = stack[-6];
    v_34999 = qcdr(v_34999);
    goto v_34821;
v_34822:
    goto v_34818;
v_34819:
    goto v_34820;
v_34821:
    v_34999 = cons(v_35000, v_34999);
    env = stack[-15];
    goto v_34811;
v_34812:
    goto v_34806;
v_34807:
    goto v_34808;
v_34809:
    goto v_34810;
v_34811:
    v_34999 = acons(stack[-1], stack[0], v_34999);
    env = stack[-15];
    v_34999 = ncons(v_34999);
    env = stack[-15];
    stack[-3] = v_34999;
    stack[-4] = v_34999;
v_34775:
    v_34999 = stack[-5];
    v_34999 = qcdr(v_34999);
    stack[-5] = v_34999;
    v_34999 = stack[-5];
    if (v_34999 == nil) goto v_34831;
    else goto v_34832;
v_34831:
    v_34999 = stack[-4];
    goto v_34774;
v_34832:
    goto v_34840;
v_34836:
    stack[-2] = stack[-3];
    goto v_34837;
v_34838:
    v_34999 = stack[-5];
    v_34999 = qcar(v_34999);
    v_35000 = v_34999;
    goto v_34853;
v_34847:
    v_34999 = v_35000;
    stack[-1] = qcar(v_34999);
    goto v_34848;
v_34849:
    v_34999 = stack[-6];
    stack[0] = qcar(v_34999);
    goto v_34850;
v_34851:
    goto v_34863;
v_34859:
    v_34999 = v_35000;
    v_35000 = qcdr(v_34999);
    goto v_34860;
v_34861:
    v_34999 = stack[-6];
    v_34999 = qcdr(v_34999);
    goto v_34862;
v_34863:
    goto v_34859;
v_34860:
    goto v_34861;
v_34862:
    v_34999 = cons(v_35000, v_34999);
    env = stack[-15];
    goto v_34852;
v_34853:
    goto v_34847;
v_34848:
    goto v_34849;
v_34850:
    goto v_34851;
v_34852:
    v_34999 = acons(stack[-1], stack[0], v_34999);
    env = stack[-15];
    v_34999 = ncons(v_34999);
    env = stack[-15];
    goto v_34839;
v_34840:
    goto v_34836;
v_34837:
    goto v_34838;
v_34839:
    v_34999 = Lrplacd(nil, stack[-2], v_34999);
    env = stack[-15];
    v_34999 = stack[-3];
    v_34999 = qcdr(v_34999);
    stack[-3] = v_34999;
    goto v_34775;
v_34774:
    stack[-9] = v_34999;
    v_34999 = stack[-9];
    fn = elt(env, 4); // lastpair
    v_34999 = (*qfn1(fn))(fn, v_34999);
    env = stack[-15];
    stack[-8] = v_34999;
    v_34999 = stack[-14];
    v_34999 = qcdr(v_34999);
    stack[-14] = v_34999;
    v_34999 = stack[-8];
    if (!consp(v_34999)) goto v_34876;
    else goto v_34877;
v_34876:
    goto v_34741;
v_34877:
v_34742:
    v_34999 = stack[-14];
    if (v_34999 == nil) goto v_34881;
    else goto v_34882;
v_34881:
    v_34999 = stack[-9];
    goto v_34740;
v_34882:
    goto v_34890;
v_34886:
    stack[-7] = stack[-8];
    goto v_34887;
v_34888:
    v_34999 = stack[-14];
    v_34999 = qcar(v_34999);
    stack[-6] = v_34999;
    goto v_34910;
v_34902:
    v_34999 = stack[-13];
    stack[-2] = qcar(v_34999);
    goto v_34903;
v_34904:
    v_34999 = stack[-12];
    stack[-1] = qcar(v_34999);
    goto v_34905;
v_34906:
    v_34999 = stack[-11];
    stack[0] = qcar(v_34999);
    goto v_34907;
v_34908:
    v_34999 = stack[-10];
    v_34999 = qcar(v_34999);
    fn = elt(env, 2); // tayexp!-minus
    v_34999 = (*qfn1(fn))(fn, v_34999);
    env = stack[-15];
    goto v_34909;
v_34910:
    goto v_34902;
v_34903:
    goto v_34904;
v_34905:
    goto v_34906;
v_34907:
    goto v_34908;
v_34909:
    fn = elt(env, 3); // makecoeffpairshom
    v_34999 = (*qfnn(fn))(fn, 4, stack[-2], stack[-1], stack[0], v_34999);
    env = stack[-15];
    stack[-5] = v_34999;
    v_34999 = stack[-5];
    if (v_34999 == nil) goto v_34922;
    else goto v_34923;
v_34922:
    v_34999 = nil;
    goto v_34899;
v_34923:
    v_34999 = stack[-5];
    v_34999 = qcar(v_34999);
    v_35000 = v_34999;
    goto v_34937;
v_34931:
    v_34999 = v_35000;
    stack[-1] = qcar(v_34999);
    goto v_34932;
v_34933:
    v_34999 = stack[-6];
    stack[0] = qcar(v_34999);
    goto v_34934;
v_34935:
    goto v_34947;
v_34943:
    v_34999 = v_35000;
    v_35000 = qcdr(v_34999);
    goto v_34944;
v_34945:
    v_34999 = stack[-6];
    v_34999 = qcdr(v_34999);
    goto v_34946;
v_34947:
    goto v_34943;
v_34944:
    goto v_34945;
v_34946:
    v_34999 = cons(v_35000, v_34999);
    env = stack[-15];
    goto v_34936;
v_34937:
    goto v_34931;
v_34932:
    goto v_34933;
v_34934:
    goto v_34935;
v_34936:
    v_34999 = acons(stack[-1], stack[0], v_34999);
    env = stack[-15];
    v_34999 = ncons(v_34999);
    env = stack[-15];
    stack[-3] = v_34999;
    stack[-4] = v_34999;
v_34900:
    v_34999 = stack[-5];
    v_34999 = qcdr(v_34999);
    stack[-5] = v_34999;
    v_34999 = stack[-5];
    if (v_34999 == nil) goto v_34956;
    else goto v_34957;
v_34956:
    v_34999 = stack[-4];
    goto v_34899;
v_34957:
    goto v_34965;
v_34961:
    stack[-2] = stack[-3];
    goto v_34962;
v_34963:
    v_34999 = stack[-5];
    v_34999 = qcar(v_34999);
    v_35000 = v_34999;
    goto v_34978;
v_34972:
    v_34999 = v_35000;
    stack[-1] = qcar(v_34999);
    goto v_34973;
v_34974:
    v_34999 = stack[-6];
    stack[0] = qcar(v_34999);
    goto v_34975;
v_34976:
    goto v_34988;
v_34984:
    v_34999 = v_35000;
    v_35000 = qcdr(v_34999);
    goto v_34985;
v_34986:
    v_34999 = stack[-6];
    v_34999 = qcdr(v_34999);
    goto v_34987;
v_34988:
    goto v_34984;
v_34985:
    goto v_34986;
v_34987:
    v_34999 = cons(v_35000, v_34999);
    env = stack[-15];
    goto v_34977;
v_34978:
    goto v_34972;
v_34973:
    goto v_34974;
v_34975:
    goto v_34976;
v_34977:
    v_34999 = acons(stack[-1], stack[0], v_34999);
    env = stack[-15];
    v_34999 = ncons(v_34999);
    env = stack[-15];
    goto v_34964;
v_34965:
    goto v_34961;
v_34962:
    goto v_34963;
v_34964:
    v_34999 = Lrplacd(nil, stack[-2], v_34999);
    env = stack[-15];
    v_34999 = stack[-3];
    v_34999 = qcdr(v_34999);
    stack[-3] = v_34999;
    goto v_34900;
v_34899:
    goto v_34889;
v_34890:
    goto v_34886;
v_34887:
    goto v_34888;
v_34889:
    v_34999 = Lrplacd(nil, stack[-7], v_34999);
    env = stack[-15];
    v_34999 = stack[-8];
    fn = elt(env, 4); // lastpair
    v_34999 = (*qfn1(fn))(fn, v_34999);
    env = stack[-15];
    stack[-8] = v_34999;
    v_34999 = stack[-14];
    v_34999 = qcdr(v_34999);
    stack[-14] = v_34999;
    goto v_34742;
v_34740:
    goto v_34729;
    v_34999 = nil;
v_34729:
    return onevalue(v_34999);
}



// Code for null!+vec!+p

static LispObject CC_nullLvecLp(LispObject env,
                         LispObject v_34723)
{
    env = qenv(env);
    LispObject v_34735;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34723);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_34735 = v_34723;
// end of prologue
    fn = elt(env, 1); // mk!+squared!+norm
    v_34735 = (*qfn1(fn))(fn, v_34735);
    env = stack[0];
    fn = elt(env, 2); // my!+nullsq!+p
    v_34735 = (*qfn1(fn))(fn, v_34735);
    if (v_34735 == nil) goto v_34730;
    v_34735 = lisp_true;
    goto v_34726;
v_34730:
    v_34735 = nil;
v_34726:
    return onevalue(v_34735);
}



// Code for talp_get!-minfct

static LispObject CC_talp_getKminfct(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_34838, v_34839, v_34840;
    LispObject fn;
    LispObject v_34726, v_34725, v_34724, v_34723;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "talp_get-minfct");
    va_start(aa, nargs);
    v_34723 = va_arg(aa, LispObject);
    v_34724 = va_arg(aa, LispObject);
    v_34725 = va_arg(aa, LispObject);
    v_34726 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_34726,v_34725,v_34724,v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_34723,v_34724,v_34725,v_34726);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_34726;
    stack[0] = v_34725;
    v_34839 = v_34724;
    v_34838 = v_34723;
// end of prologue
    goto v_34732;
v_34728:
    goto v_34729;
v_34730:
    goto v_34731;
v_34732:
    goto v_34728;
v_34729:
    goto v_34730;
v_34731:
    v_34838 = *(LispObject *)((char *)v_34839 + (CELL-TAG_VECTOR) + (((intptr_t)v_34838-TAG_FIXNUM)/(16/CELL)));
    stack[-6] = v_34838;
    v_34838 = stack[-6];
    fn = elt(env, 1); // talp_invp
    v_34838 = (*qfn1(fn))(fn, v_34838);
    env = stack[-7];
    if (v_34838 == nil) goto v_34740;
    goto v_34750;
v_34744:
    v_34838 = stack[-6];
    fn = elt(env, 2); // talp_fop
    v_34840 = (*qfn1(fn))(fn, v_34838);
    goto v_34745;
v_34746:
    goto v_34757;
v_34753:
    v_34839 = stack[0];
    goto v_34754;
v_34755:
    v_34838 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34756;
v_34757:
    goto v_34753;
v_34754:
    goto v_34755;
v_34756:
    v_34839 = *(LispObject *)((char *)v_34839 + (CELL-TAG_VECTOR) + (((intptr_t)v_34838-TAG_FIXNUM)/(16/CELL)));
    goto v_34747;
v_34748:
    v_34838 = nil;
    goto v_34749;
v_34750:
    goto v_34744;
v_34745:
    goto v_34746;
v_34747:
    goto v_34748;
v_34749:
    return list2star(v_34840, v_34839, v_34838);
v_34740:
    goto v_34769;
v_34765:
    v_34838 = stack[-6];
    fn = elt(env, 2); // talp_fop
    stack[-4] = (*qfn1(fn))(fn, v_34838);
    env = stack[-7];
    goto v_34766;
v_34767:
    v_34838 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_34838;
    goto v_34789;
v_34785:
    v_34838 = stack[-6];
    v_34839 = qcdr(v_34838);
    goto v_34786;
v_34787:
    v_34838 = stack[-3];
    goto v_34788;
v_34789:
    goto v_34785;
v_34786:
    goto v_34787;
v_34788:
    v_34838 = difference2(v_34839, v_34838);
    env = stack[-7];
    v_34838 = Lminusp(nil, v_34838);
    env = stack[-7];
    if (v_34838 == nil) goto v_34782;
    v_34838 = nil;
    goto v_34776;
v_34782:
    goto v_34799;
v_34795:
    v_34839 = stack[-5];
    goto v_34796;
v_34797:
    v_34838 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34798;
v_34799:
    goto v_34795;
v_34796:
    goto v_34797;
v_34798:
    v_34838 = *(LispObject *)((char *)v_34839 + (CELL-TAG_VECTOR) + (((intptr_t)v_34838-TAG_FIXNUM)/(16/CELL)));
    v_34838 = ncons(v_34838);
    env = stack[-7];
    stack[-1] = v_34838;
    stack[-2] = v_34838;
v_34777:
    v_34838 = stack[-3];
    v_34838 = add1(v_34838);
    env = stack[-7];
    stack[-3] = v_34838;
    goto v_34815;
v_34811:
    v_34838 = stack[-6];
    v_34839 = qcdr(v_34838);
    goto v_34812;
v_34813:
    v_34838 = stack[-3];
    goto v_34814;
v_34815:
    goto v_34811;
v_34812:
    goto v_34813;
v_34814:
    v_34838 = difference2(v_34839, v_34838);
    env = stack[-7];
    v_34838 = Lminusp(nil, v_34838);
    env = stack[-7];
    if (v_34838 == nil) goto v_34808;
    v_34838 = stack[-2];
    goto v_34776;
v_34808:
    goto v_34825;
v_34821:
    stack[0] = stack[-1];
    goto v_34822;
v_34823:
    goto v_34832;
v_34828:
    v_34839 = stack[-5];
    goto v_34829;
v_34830:
    v_34838 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34831;
v_34832:
    goto v_34828;
v_34829:
    goto v_34830;
v_34831:
    v_34838 = *(LispObject *)((char *)v_34839 + (CELL-TAG_VECTOR) + (((intptr_t)v_34838-TAG_FIXNUM)/(16/CELL)));
    v_34838 = ncons(v_34838);
    env = stack[-7];
    goto v_34824;
v_34825:
    goto v_34821;
v_34822:
    goto v_34823;
v_34824:
    v_34838 = Lrplacd(nil, stack[0], v_34838);
    env = stack[-7];
    v_34838 = stack[-1];
    v_34838 = qcdr(v_34838);
    stack[-1] = v_34838;
    goto v_34777;
v_34776:
    goto v_34768;
v_34769:
    goto v_34765;
v_34766:
    goto v_34767;
v_34768:
    {
        LispObject v_34848 = stack[-4];
        fn = elt(env, 3); // talp_mktn
        return (*qfn2(fn))(fn, v_34848, v_34838);
    }
    v_34838 = nil;
    return onevalue(v_34838);
}



// Code for rl_b2atl

static LispObject CC_rl_b2atl(LispObject env,
                         LispObject v_34723, LispObject v_34724)
{
    env = qenv(env);
    LispObject v_34741, v_34742;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34724,v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34723,v_34724);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_34741 = v_34724;
    v_34742 = v_34723;
// end of prologue
    goto v_34731;
v_34727:
    stack[0] = qvalue(elt(env, 1)); // rl_b2atl!*
    goto v_34728;
v_34729:
    goto v_34738;
v_34734:
    goto v_34735;
v_34736:
    goto v_34737;
v_34738:
    goto v_34734;
v_34735:
    goto v_34736;
v_34737:
    v_34741 = list2(v_34742, v_34741);
    env = stack[-1];
    goto v_34730;
v_34731:
    goto v_34727;
v_34728:
    goto v_34729;
v_34730:
    {
        LispObject v_34744 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_34744, v_34741);
    }
}



// Code for ps!:expt!-erule

static LispObject CC_psTexptKerule(LispObject env,
                         LispObject v_34723, LispObject v_34724)
{
    env = qenv(env);
    LispObject v_34985, v_34986, v_34987;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34724,v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34723,v_34724);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_34724;
    v_34986 = v_34723;
// end of prologue
    v_34985 = v_34986;
    v_34985 = qcdr(v_34985);
    v_34985 = qcar(v_34985);
    stack[-10] = v_34985;
    v_34985 = v_34986;
    v_34985 = qcdr(v_34985);
    v_34985 = qcdr(v_34985);
    v_34985 = qcar(v_34985);
    stack[-6] = v_34985;
    v_34985 = v_34986;
    v_34985 = qcdr(v_34985);
    v_34985 = qcdr(v_34985);
    v_34985 = qcdr(v_34985);
    v_34985 = qcar(v_34985);
    stack[-5] = v_34985;
    v_34985 = stack[-10];
    fn = elt(env, 3); // ps!:order
    v_34985 = (*qfn1(fn))(fn, v_34985);
    env = stack[-11];
    stack[-8] = v_34985;
    v_34985 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 3); // ps!:order
    v_34985 = (*qfn1(fn))(fn, v_34985);
    env = stack[-11];
    stack[-7] = v_34985;
    goto v_34758;
v_34754:
    v_34986 = stack[-9];
    goto v_34755;
v_34756:
    v_34985 = stack[-7];
    goto v_34757;
v_34758:
    goto v_34754;
v_34755:
    goto v_34756;
v_34757:
    if (equal(v_34986, v_34985)) goto v_34752;
    else goto v_34753;
v_34752:
    goto v_34769;
v_34765:
    v_34986 = stack[-5];
    goto v_34766;
v_34767:
    v_34985 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34768;
v_34769:
    goto v_34765;
v_34766:
    goto v_34767;
v_34768:
    if (v_34986 == v_34985) goto v_34763;
    else goto v_34764;
v_34763:
    v_34985 = stack[-6];
    stack[0] = v_34985;
    goto v_34762;
v_34764:
    goto v_34782;
v_34776:
    v_34987 = elt(env, 2); // quotient
    goto v_34777;
v_34778:
    v_34986 = stack[-6];
    goto v_34779;
v_34780:
    v_34985 = stack[-5];
    goto v_34781;
v_34782:
    goto v_34776;
v_34777:
    goto v_34778;
v_34779:
    goto v_34780;
v_34781:
    v_34985 = list3(v_34987, v_34986, v_34985);
    env = stack[-11];
    stack[0] = v_34985;
    goto v_34762;
v_34762:
    goto v_34792;
v_34788:
    goto v_34799;
v_34795:
    v_34986 = stack[-10];
    goto v_34796;
v_34797:
    v_34985 = stack[-8];
    goto v_34798;
v_34799:
    goto v_34795;
v_34796:
    goto v_34797;
v_34798:
    fn = elt(env, 4); // ps!:evaluate
    v_34985 = (*qfn2(fn))(fn, v_34986, v_34985);
    env = stack[-11];
    fn = elt(env, 5); // prepsqxx
    v_34986 = (*qfn1(fn))(fn, v_34985);
    env = stack[-11];
    goto v_34789;
v_34790:
    v_34985 = stack[0];
    goto v_34791;
v_34792:
    goto v_34788;
v_34789:
    goto v_34790;
v_34791:
    v_34985 = list2(v_34986, v_34985);
    env = stack[-11];
    {
        fn = elt(env, 6); // simpexpt
        return (*qfn1(fn))(fn, v_34985);
    }
v_34753:
    goto v_34810;
v_34806:
    v_34986 = nil;
    goto v_34807;
v_34808:
    v_34985 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34809;
v_34810:
    goto v_34806;
v_34807:
    goto v_34808;
v_34809:
    v_34985 = cons(v_34986, v_34985);
    env = stack[-11];
    stack[0] = v_34985;
    v_34985 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_34985;
v_34816:
    goto v_34828;
v_34824:
    goto v_34834;
v_34830:
    v_34986 = stack[-9];
    goto v_34831;
v_34832:
    v_34985 = stack[-7];
    goto v_34833;
v_34834:
    goto v_34830;
v_34831:
    goto v_34832;
v_34833:
    v_34986 = difference2(v_34986, v_34985);
    env = stack[-11];
    goto v_34825;
v_34826:
    v_34985 = stack[-4];
    goto v_34827;
v_34828:
    goto v_34824;
v_34825:
    goto v_34826;
v_34827:
    v_34985 = difference2(v_34986, v_34985);
    env = stack[-11];
    v_34985 = Lminusp(nil, v_34985);
    env = stack[-11];
    if (v_34985 == nil) goto v_34821;
    goto v_34815;
v_34821:
    goto v_34844;
v_34840:
    stack[-3] = stack[0];
    goto v_34841;
v_34842:
    goto v_34851;
v_34847:
    goto v_34857;
v_34853:
    goto v_34863;
v_34859:
    goto v_34869;
v_34865:
    v_34986 = stack[-4];
    goto v_34866;
v_34867:
    v_34985 = stack[-6];
    goto v_34868;
v_34869:
    goto v_34865;
v_34866:
    goto v_34867;
v_34868:
    stack[-1] = times2(v_34986, v_34985);
    env = stack[-11];
    goto v_34860;
v_34861:
    goto v_34877;
v_34873:
    stack[0] = stack[-5];
    goto v_34874;
v_34875:
    goto v_34884;
v_34880:
    goto v_34890;
v_34886:
    v_34986 = stack[-4];
    goto v_34887;
v_34888:
    v_34985 = stack[-9];
    goto v_34889;
v_34890:
    goto v_34886;
v_34887:
    goto v_34888;
v_34889:
    v_34986 = difference2(v_34986, v_34985);
    env = stack[-11];
    goto v_34881;
v_34882:
    v_34985 = stack[-7];
    goto v_34883;
v_34884:
    goto v_34880;
v_34881:
    goto v_34882;
v_34883:
    v_34985 = plus2(v_34986, v_34985);
    env = stack[-11];
    goto v_34876;
v_34877:
    goto v_34873;
v_34874:
    goto v_34875;
v_34876:
    v_34985 = times2(stack[0], v_34985);
    env = stack[-11];
    goto v_34862;
v_34863:
    goto v_34859;
v_34860:
    goto v_34861;
v_34862:
    v_34985 = plus2(stack[-1], v_34985);
    env = stack[-11];
    v_34987 = v_34985;
    goto v_34903;
v_34899:
    v_34986 = v_34987;
    goto v_34900;
v_34901:
    v_34985 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34902;
v_34903:
    goto v_34899;
v_34900:
    goto v_34901;
v_34902:
    if (v_34986 == v_34985) goto v_34897;
    else goto v_34898;
v_34897:
    v_34985 = nil;
    v_34986 = v_34985;
    goto v_34896;
v_34898:
    v_34985 = v_34987;
    v_34986 = v_34985;
    goto v_34896;
    v_34986 = nil;
v_34896:
    goto v_34854;
v_34855:
    v_34985 = stack[-5];
    goto v_34856;
v_34857:
    goto v_34853;
v_34854:
    goto v_34855;
v_34856:
    stack[-2] = cons(v_34986, v_34985);
    env = stack[-11];
    goto v_34848;
v_34849:
    goto v_34916;
v_34912:
    goto v_34922;
v_34918:
    stack[0] = stack[-10];
    goto v_34919;
v_34920:
    goto v_34929;
v_34925:
    v_34986 = stack[-4];
    goto v_34926;
v_34927:
    v_34985 = stack[-8];
    goto v_34928;
v_34929:
    goto v_34925;
v_34926:
    goto v_34927;
v_34928:
    v_34985 = plus2(v_34986, v_34985);
    env = stack[-11];
    goto v_34921;
v_34922:
    goto v_34918;
v_34919:
    goto v_34920;
v_34921:
    fn = elt(env, 4); // ps!:evaluate
    stack[-1] = (*qfn2(fn))(fn, stack[0], v_34985);
    env = stack[-11];
    goto v_34913;
v_34914:
    goto v_34937;
v_34933:
    stack[0] = qvalue(elt(env, 1)); // ps
    goto v_34934;
v_34935:
    goto v_34944;
v_34940:
    v_34986 = stack[-9];
    goto v_34941;
v_34942:
    v_34985 = stack[-4];
    goto v_34943;
v_34944:
    goto v_34940;
v_34941:
    goto v_34942;
v_34943:
    v_34985 = difference2(v_34986, v_34985);
    env = stack[-11];
    goto v_34936;
v_34937:
    goto v_34933;
v_34934:
    goto v_34935;
v_34936:
    fn = elt(env, 4); // ps!:evaluate
    v_34985 = (*qfn2(fn))(fn, stack[0], v_34985);
    env = stack[-11];
    goto v_34915;
v_34916:
    goto v_34912;
v_34913:
    goto v_34914;
v_34915:
    fn = elt(env, 7); // multsq
    v_34985 = (*qfn2(fn))(fn, stack[-1], v_34985);
    env = stack[-11];
    goto v_34850;
v_34851:
    goto v_34847;
v_34848:
    goto v_34849;
v_34850:
    fn = elt(env, 7); // multsq
    v_34985 = (*qfn2(fn))(fn, stack[-2], v_34985);
    env = stack[-11];
    goto v_34843;
v_34844:
    goto v_34840;
v_34841:
    goto v_34842;
v_34843:
    fn = elt(env, 8); // addsq
    v_34985 = (*qfn2(fn))(fn, stack[-3], v_34985);
    env = stack[-11];
    stack[0] = v_34985;
    v_34985 = stack[-4];
    v_34985 = add1(v_34985);
    env = stack[-11];
    stack[-4] = v_34985;
    goto v_34816;
v_34815:
    goto v_34954;
v_34950:
    goto v_34951;
v_34952:
    goto v_34961;
v_34957:
    goto v_34967;
v_34963:
    goto v_34973;
v_34969:
    v_34986 = stack[-9];
    goto v_34970;
v_34971:
    v_34985 = stack[-7];
    goto v_34972;
v_34973:
    goto v_34969;
v_34970:
    goto v_34971;
v_34972:
    v_34986 = difference2(v_34986, v_34985);
    env = stack[-11];
    goto v_34964;
v_34965:
    v_34985 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34966;
v_34967:
    goto v_34963;
v_34964:
    goto v_34965;
v_34966:
    stack[-1] = cons(v_34986, v_34985);
    env = stack[-11];
    goto v_34958;
v_34959:
    goto v_34982;
v_34978:
    v_34986 = stack[-10];
    goto v_34979;
v_34980:
    v_34985 = stack[-8];
    goto v_34981;
v_34982:
    goto v_34978;
v_34979:
    goto v_34980;
v_34981:
    fn = elt(env, 4); // ps!:evaluate
    v_34985 = (*qfn2(fn))(fn, v_34986, v_34985);
    env = stack[-11];
    goto v_34960;
v_34961:
    goto v_34957;
v_34958:
    goto v_34959;
v_34960:
    fn = elt(env, 7); // multsq
    v_34985 = (*qfn2(fn))(fn, stack[-1], v_34985);
    env = stack[-11];
    goto v_34953;
v_34954:
    goto v_34950;
v_34951:
    goto v_34952;
v_34953:
    {
        LispObject v_34999 = stack[0];
        fn = elt(env, 9); // quotsq
        return (*qfn2(fn))(fn, v_34999, v_34985);
    }
    v_34985 = nil;
    return onevalue(v_34985);
}



// Code for frlp

static LispObject CC_frlp(LispObject env,
                         LispObject v_34723)
{
    env = qenv(env);
    LispObject v_34752, v_34753, v_34754;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_34753 = v_34723;
// end of prologue
v_34722:
    v_34752 = v_34753;
    if (v_34752 == nil) goto v_34727;
    else goto v_34728;
v_34727:
    v_34752 = lisp_true;
    goto v_34726;
v_34728:
    goto v_34741;
v_34737:
    v_34752 = v_34753;
    v_34754 = qcar(v_34752);
    goto v_34738;
v_34739:
    v_34752 = qvalue(elt(env, 1)); // frlis!*
    goto v_34740;
v_34741:
    goto v_34737;
v_34738:
    goto v_34739;
v_34740:
    v_34752 = Lmemq(nil, v_34754, v_34752);
    if (v_34752 == nil) goto v_34735;
    else goto v_34736;
v_34735:
    v_34752 = nil;
    goto v_34734;
v_34736:
    v_34752 = v_34753;
    v_34752 = qcdr(v_34752);
    v_34753 = v_34752;
    goto v_34722;
    v_34752 = nil;
v_34734:
    goto v_34726;
    v_34752 = nil;
v_34726:
    return onevalue(v_34752);
}



// Code for dm!-quotient

static LispObject CC_dmKquotient(LispObject env,
                         LispObject v_34723, LispObject v_34724)
{
    env = qenv(env);
    LispObject v_34752, v_34753;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34724,v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34723,v_34724);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_34724;
    v_34753 = v_34723;
// end of prologue
    v_34752 = nil;
    qvalue(elt(env, 1)) = v_34752; // !*noequiv
    goto v_34736;
v_34732:
    v_34752 = v_34753;
    fn = elt(env, 2); // dm!-mkfloat
    stack[-1] = (*qfn1(fn))(fn, v_34752);
    env = stack[-2];
    goto v_34733;
v_34734:
    v_34752 = stack[0];
    fn = elt(env, 2); // dm!-mkfloat
    v_34752 = (*qfn1(fn))(fn, v_34752);
    env = stack[-2];
    goto v_34735;
v_34736:
    goto v_34732;
v_34733:
    goto v_34734;
v_34735:
    fn = elt(env, 3); // !:quotient
    v_34752 = (*qfn2(fn))(fn, stack[-1], v_34752);
    v_34753 = v_34752;
    v_34752 = v_34753;
    if (v_34752 == nil) goto v_34744;
    else goto v_34745;
v_34744:
    v_34752 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34743;
v_34745:
    v_34752 = v_34753;
    goto v_34743;
    v_34752 = nil;
v_34743:
    return onevalue(v_34752);
}



// Code for groebsaveltermbc

static LispObject CC_groebsaveltermbc(LispObject env,
                         LispObject v_34723)
{
    env = qenv(env);
    LispObject v_34786, v_34787, v_34788;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34723);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_34723;
// end of prologue
    v_34786 = stack[0];
    fn = elt(env, 2); // vbc2a
    v_34786 = (*qfn1(fn))(fn, v_34786);
    env = stack[-2];
    stack[0] = v_34786;
    v_34786 = stack[0];
    if (is_number(v_34786)) goto v_34734;
    v_34786 = stack[0];
    fn = elt(env, 3); // constant_exprp
    v_34786 = (*qfn1(fn))(fn, v_34786);
    env = stack[-2];
    v_34786 = (v_34786 == nil ? lisp_true : nil);
    goto v_34732;
v_34734:
    v_34786 = nil;
    goto v_34732;
    v_34786 = nil;
v_34732:
    if (v_34786 == nil) goto v_34730;
    v_34786 = stack[0];
    fn = elt(env, 4); // simp
    v_34786 = (*qfn1(fn))(fn, v_34786);
    env = stack[-2];
    v_34786 = qcar(v_34786);
    fn = elt(env, 5); // fctrf
    v_34786 = (*qfn1(fn))(fn, v_34786);
    env = stack[-2];
    v_34786 = qcdr(v_34786);
    stack[-1] = v_34786;
v_34745:
    v_34786 = stack[-1];
    if (v_34786 == nil) goto v_34753;
    else goto v_34754;
v_34753:
    v_34786 = nil;
    goto v_34744;
v_34754:
    v_34786 = stack[-1];
    v_34786 = qcar(v_34786);
    v_34788 = v_34786;
    v_34786 = v_34788;
    v_34786 = qcar(v_34786);
    fn = elt(env, 6); // prepf
    v_34786 = (*qfn1(fn))(fn, v_34786);
    env = stack[-2];
    v_34788 = v_34786;
    goto v_34771;
v_34767:
    v_34787 = v_34788;
    goto v_34768;
v_34769:
    v_34786 = qvalue(elt(env, 1)); // glterms
    goto v_34770;
v_34771:
    goto v_34767;
v_34768:
    goto v_34769;
v_34770:
    v_34786 = Lmember(nil, v_34787, v_34786);
    if (v_34786 == nil) goto v_34765;
    else goto v_34766;
v_34765:
    goto v_34780;
v_34776:
    stack[0] = qvalue(elt(env, 1)); // glterms
    goto v_34777;
v_34778:
    v_34786 = v_34788;
    v_34786 = ncons(v_34786);
    env = stack[-2];
    goto v_34779;
v_34780:
    goto v_34776;
v_34777:
    goto v_34778;
v_34779:
    v_34786 = Lnconc(nil, stack[0], v_34786);
    env = stack[-2];
    goto v_34764;
v_34766:
v_34764:
    v_34786 = stack[-1];
    v_34786 = qcdr(v_34786);
    stack[-1] = v_34786;
    goto v_34745;
v_34744:
    goto v_34728;
v_34730:
    v_34786 = nil;
v_34728:
    return onevalue(v_34786);
}



// Code for lispcondp

static LispObject CC_lispcondp(LispObject env,
                         LispObject v_34723)
{
    env = qenv(env);
    LispObject v_34733, v_34734;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_34733 = v_34723;
// end of prologue
    goto v_34730;
v_34726:
    goto v_34727;
v_34728:
    v_34734 = elt(env, 1); // cond
    goto v_34729;
v_34730:
    goto v_34726;
v_34727:
    goto v_34728;
v_34729:
        return Leqcar(nil, v_34733, v_34734);
}



// Code for simpabs

static LispObject CC_simpabs(LispObject env,
                         LispObject v_34723)
{
    env = qenv(env);
    LispObject v_34811, v_34812;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34723);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_34723;
// end of prologue
    v_34811 = stack[0];
    if (v_34811 == nil) goto v_34731;
    else goto v_34732;
v_34731:
    v_34811 = lisp_true;
    goto v_34730;
v_34732:
    v_34811 = stack[0];
    v_34811 = qcdr(v_34811);
    goto v_34730;
    v_34811 = nil;
v_34730:
    if (v_34811 == nil) goto v_34728;
    goto v_34744;
v_34740:
    goto v_34750;
v_34746:
    stack[-1] = elt(env, 1); // abs
    goto v_34747;
v_34748:
    v_34811 = stack[0];
    fn = elt(env, 2); // revlis
    v_34811 = (*qfn1(fn))(fn, v_34811);
    env = stack[-2];
    goto v_34749;
v_34750:
    goto v_34746;
v_34747:
    goto v_34748;
v_34749:
    v_34812 = cons(stack[-1], v_34811);
    env = stack[-2];
    goto v_34741;
v_34742:
    v_34811 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34743;
v_34744:
    goto v_34740;
v_34741:
    goto v_34742;
v_34743:
    {
        fn = elt(env, 3); // mksq
        return (*qfn2(fn))(fn, v_34812, v_34811);
    }
v_34728:
    v_34811 = stack[0];
    v_34811 = qcar(v_34811);
    stack[0] = v_34811;
    v_34811 = stack[0];
    if (is_number(v_34811)) goto v_34764;
    else goto v_34765;
v_34764:
    goto v_34772;
v_34768:
    v_34811 = stack[0];
    v_34812 = Labsval(nil, v_34811);
    goto v_34769;
v_34770:
    v_34811 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34771;
v_34772:
    goto v_34768;
v_34769:
    goto v_34770;
v_34771:
    return cons(v_34812, v_34811);
v_34765:
    v_34811 = stack[0];
    fn = elt(env, 4); // sign!-abs
    v_34811 = (*qfn1(fn))(fn, v_34811);
    env = stack[-2];
    v_34812 = v_34811;
    if (v_34811 == nil) goto v_34777;
    v_34811 = v_34812;
    goto v_34759;
v_34777:
    v_34811 = stack[0];
    fn = elt(env, 5); // simp!*
    v_34811 = (*qfn1(fn))(fn, v_34811);
    env = stack[-2];
    stack[0] = v_34811;
    v_34811 = stack[0];
    v_34811 = qcar(v_34811);
    if (v_34811 == nil) goto v_34785;
    else goto v_34786;
v_34785:
    goto v_34794;
v_34790:
    v_34812 = nil;
    goto v_34791;
v_34792:
    v_34811 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34793;
v_34794:
    goto v_34790;
v_34791:
    goto v_34792;
v_34793:
    return cons(v_34812, v_34811);
v_34786:
    goto v_34804;
v_34800:
    v_34811 = stack[0];
    v_34811 = qcar(v_34811);
    fn = elt(env, 6); // simpabs1
    stack[-1] = (*qfn1(fn))(fn, v_34811);
    env = stack[-2];
    goto v_34801;
v_34802:
    v_34811 = stack[0];
    v_34811 = qcdr(v_34811);
    fn = elt(env, 6); // simpabs1
    v_34811 = (*qfn1(fn))(fn, v_34811);
    env = stack[-2];
    goto v_34803;
v_34804:
    goto v_34800;
v_34801:
    goto v_34802;
v_34803:
    {
        LispObject v_34815 = stack[-1];
        fn = elt(env, 7); // quotsq
        return (*qfn2(fn))(fn, v_34815, v_34811);
    }
    v_34811 = nil;
v_34759:
    goto v_34726;
    v_34811 = nil;
v_34726:
    return onevalue(v_34811);
}



// Code for formclear

static LispObject CC_formclear(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_34746, v_34747, v_34748;
    LispObject fn;
    LispObject v_34725, v_34724, v_34723;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formclear");
    va_start(aa, nargs);
    v_34723 = va_arg(aa, LispObject);
    v_34724 = va_arg(aa, LispObject);
    v_34725 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_34725,v_34724,v_34723);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_34723,v_34724,v_34725);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_34746 = v_34725;
    v_34747 = v_34724;
    v_34748 = v_34723;
// end of prologue
    goto v_34732;
v_34728:
    stack[0] = elt(env, 1); // clear
    goto v_34729;
v_34730:
    goto v_34741;
v_34735:
    v_34748 = qcdr(v_34748);
    goto v_34736;
v_34737:
    goto v_34738;
v_34739:
    goto v_34740;
v_34741:
    goto v_34735;
v_34736:
    goto v_34737;
v_34738:
    goto v_34739;
v_34740:
    fn = elt(env, 2); // formclear1
    v_34746 = (*qfnn(fn))(fn, 3, v_34748, v_34747, v_34746);
    goto v_34731;
v_34732:
    goto v_34728;
v_34729:
    goto v_34730;
v_34731:
    {
        LispObject v_34750 = stack[0];
        return list2(v_34750, v_34746);
    }
}



setup_type const u58_setup[] =
{
    {"preproc1",                CC_preproc1,    TOO_MANY_1,    WRONG_NO_1},
    {"basisvectorp",            CC_basisvectorp,TOO_MANY_1,    WRONG_NO_1},
    {"find_bubles1",            TOO_FEW_2,      CC_find_bubles1,WRONG_NO_2},
    {"compactf1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_compactf1},
    {"mo_deletecomp",           CC_mo_deletecomp,TOO_MANY_1,   WRONG_NO_1},
    {"solvevars",               CC_solvevars,   TOO_MANY_1,    WRONG_NO_1},
    {"rat_mk",                  TOO_FEW_2,      CC_rat_mk,     WRONG_NO_2},
    {"gcdlist1",                CC_gcdlist1,    TOO_MANY_1,    WRONG_NO_1},
    {"get-min-degreelist",      CC_getKminKdegreelist,TOO_MANY_1,WRONG_NO_1},
    {"cl_subfof1",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_subfof1},
    {"cd_ordatp",               TOO_FEW_2,      CC_cd_ordatp,  WRONG_NO_2},
    {"force-lc",                TOO_FEW_2,      CC_forceKlc,   WRONG_NO_2},
    {"compute:intlog",          CC_computeTintlog,TOO_MANY_1,  WRONG_NO_1},
    {"vdpenumerate",            CC_vdpenumerate,TOO_MANY_1,    WRONG_NO_1},
    {"xnormalise",              CC_xnormalise,  TOO_MANY_1,    WRONG_NO_1},
    {"validrule",               CC_validrule,   TOO_MANY_1,    WRONG_NO_1},
    {"listofvarnames",          CC_listofvarnames,TOO_MANY_1,  WRONG_NO_1},
    {"calc_map_2d",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_calc_map_2d},
    {"*sf2exb",                 TOO_FEW_2,      CC_Hsf2exb,    WRONG_NO_2},
    {"x**p-w",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xHHpKw},
    {"aex_red",                 TOO_FEW_2,      CC_aex_red,    WRONG_NO_2},
    {"makecoeffpairs1",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_makecoeffpairs1},
    {"null+vec+p",              CC_nullLvecLp,  TOO_MANY_1,    WRONG_NO_1},
    {"talp_get-minfct",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_getKminfct},
    {"rl_b2atl",                TOO_FEW_2,      CC_rl_b2atl,   WRONG_NO_2},
    {"ps:expt-erule",           TOO_FEW_2,      CC_psTexptKerule,WRONG_NO_2},
    {"frlp",                    CC_frlp,        TOO_MANY_1,    WRONG_NO_1},
    {"dm-quotient",             TOO_FEW_2,      CC_dmKquotient,WRONG_NO_2},
    {"groebsaveltermbc",        CC_groebsaveltermbc,TOO_MANY_1,WRONG_NO_1},
    {"lispcondp",               CC_lispcondp,   TOO_MANY_1,    WRONG_NO_1},
    {"simpabs",                 CC_simpabs,     TOO_MANY_1,    WRONG_NO_1},
    {"formclear",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formclear},
    {NULL, (one_args *)"u58", (two_args *)"140239 8675572 9755358", 0}
};

// end of generated code
