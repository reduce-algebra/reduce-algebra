
// $destdir/u28.c        Machine generated C code

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



// Code for homogp

static LispObject CC_homogp(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15522, v_15523;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15433);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15433;
// end of prologue
    v_15522 = stack[0];
    if (!consp(v_15522)) goto v_15445;
    else goto v_15446;
v_15445:
    v_15522 = lisp_true;
    goto v_15444;
v_15446:
    v_15522 = stack[0];
    v_15522 = qcar(v_15522);
    v_15522 = (consp(v_15522) ? nil : lisp_true);
    goto v_15444;
    v_15522 = nil;
v_15444:
    if (v_15522 == nil) goto v_15442;
    v_15522 = lisp_true;
    goto v_15440;
v_15442:
    v_15522 = stack[0];
    v_15522 = qcar(v_15522);
    if (!consp(v_15522)) goto v_15459;
    else goto v_15460;
v_15459:
    v_15522 = lisp_true;
    goto v_15458;
v_15460:
    v_15522 = stack[0];
    v_15522 = qcar(v_15522);
    v_15522 = qcar(v_15522);
    v_15522 = (consp(v_15522) ? nil : lisp_true);
    goto v_15458;
    v_15522 = nil;
v_15458:
    goto v_15440;
    v_15522 = nil;
v_15440:
    if (v_15522 == nil) goto v_15438;
    v_15522 = nil;
    goto v_15436;
v_15438:
    v_15522 = stack[0];
    v_15522 = qcdr(v_15522);
    v_15522 = qcar(v_15522);
    v_15522 = qcdr(v_15522);
    if (v_15522 == nil) goto v_15471;
    else goto v_15472;
v_15471:
    v_15522 = nil;
    goto v_15436;
v_15472:
    v_15522 = stack[0];
    v_15522 = qcdr(v_15522);
    v_15522 = qcar(v_15522);
    fn = elt(env, 1); // lastnondomain
    v_15522 = (*qfn1(fn))(fn, v_15522);
    env = stack[-2];
    v_15522 = qcdr(v_15522);
    v_15523 = v_15522;
    v_15522 = v_15523;
    if (!consp(v_15522)) goto v_15488;
    else goto v_15489;
v_15488:
    v_15522 = lisp_true;
    goto v_15487;
v_15489:
    v_15522 = v_15523;
    v_15522 = qcar(v_15522);
    v_15522 = (consp(v_15522) ? nil : lisp_true);
    goto v_15487;
    v_15522 = nil;
v_15487:
    if (v_15522 == nil) goto v_15479;
    v_15522 = nil;
    goto v_15436;
v_15479:
    goto v_15504;
v_15500:
    v_15522 = stack[0];
    v_15522 = qcdr(v_15522);
    v_15522 = qcar(v_15522);
    v_15522 = qcar(v_15522);
    v_15522 = qcar(v_15522);
    fn = elt(env, 2); // listsum
    stack[-1] = (*qfn1(fn))(fn, v_15522);
    env = stack[-2];
    goto v_15501;
v_15502:
    v_15522 = stack[0];
    v_15522 = qcdr(v_15522);
    v_15522 = qcar(v_15522);
    fn = elt(env, 1); // lastnondomain
    v_15522 = (*qfn1(fn))(fn, v_15522);
    env = stack[-2];
    v_15522 = qcar(v_15522);
    v_15522 = qcar(v_15522);
    fn = elt(env, 2); // listsum
    v_15522 = (*qfn1(fn))(fn, v_15522);
    goto v_15503;
v_15504:
    goto v_15500;
v_15501:
    goto v_15502;
v_15503:
    if (equal(stack[-1], v_15522)) goto v_15498;
    else goto v_15499;
v_15498:
    v_15522 = lisp_true;
    goto v_15436;
v_15499:
    v_15522 = nil;
    goto v_15436;
    v_15522 = nil;
v_15436:
    return onevalue(v_15522);
}



// Code for ofsf_optsubstat

static LispObject CC_ofsf_optsubstat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15492, v_15493;
    LispObject fn;
    LispObject v_15435, v_15434, v_15433;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_optsubstat");
    va_start(aa, nargs);
    v_15433 = va_arg(aa, LispObject);
    v_15434 = va_arg(aa, LispObject);
    v_15435 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15435,v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15433,v_15434,v_15435);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_15492 = v_15435;
    stack[-2] = v_15434;
    stack[0] = v_15433;
// end of prologue
    goto v_15449;
v_15445:
    v_15493 = stack[0];
    v_15493 = qcdr(v_15493);
    v_15493 = qcar(v_15493);
    goto v_15446;
v_15447:
    goto v_15448;
v_15449:
    goto v_15445;
v_15446:
    goto v_15447;
v_15448:
    fn = elt(env, 1); // ofsf_optsplitterm
    v_15492 = (*qfn2(fn))(fn, v_15493, v_15492);
    env = stack[-4];
    stack[-3] = v_15492;
    if (v_15492 == nil) goto v_15442;
    else goto v_15443;
v_15442:
    v_15492 = stack[0];
    goto v_15439;
v_15443:
    goto v_15462;
v_15456:
    v_15492 = stack[0];
    stack[-1] = qcar(v_15492);
    goto v_15457;
v_15458:
    goto v_15470;
v_15466:
    goto v_15476;
v_15472:
    v_15492 = stack[-3];
    v_15493 = qcar(v_15492);
    goto v_15473;
v_15474:
    v_15492 = stack[-2];
    v_15492 = qcar(v_15492);
    goto v_15475;
v_15476:
    goto v_15472;
v_15473:
    goto v_15474;
v_15475:
    fn = elt(env, 2); // multf
    stack[0] = (*qfn2(fn))(fn, v_15493, v_15492);
    env = stack[-4];
    goto v_15467;
v_15468:
    goto v_15486;
v_15482:
    v_15492 = stack[-3];
    v_15493 = qcdr(v_15492);
    goto v_15483;
v_15484:
    v_15492 = stack[-2];
    v_15492 = qcdr(v_15492);
    goto v_15485;
v_15486:
    goto v_15482;
v_15483:
    goto v_15484;
v_15485:
    fn = elt(env, 2); // multf
    v_15492 = (*qfn2(fn))(fn, v_15493, v_15492);
    env = stack[-4];
    goto v_15469;
v_15470:
    goto v_15466;
v_15467:
    goto v_15468;
v_15469:
    fn = elt(env, 3); // addf
    v_15493 = (*qfn2(fn))(fn, stack[0], v_15492);
    goto v_15459;
v_15460:
    v_15492 = nil;
    goto v_15461;
v_15462:
    goto v_15456;
v_15457:
    goto v_15458;
v_15459:
    goto v_15460;
v_15461:
    {
        LispObject v_15498 = stack[-1];
        return list3(v_15498, v_15493, v_15492);
    }
v_15439:
    return onevalue(v_15492);
}



// Code for atomlis

static LispObject CC_atomlis(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15455, v_15456;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15455 = v_15433;
// end of prologue
v_15432:
    v_15456 = v_15455;
    if (v_15456 == nil) goto v_15437;
    else goto v_15438;
v_15437:
    v_15455 = lisp_true;
    goto v_15436;
v_15438:
    v_15456 = v_15455;
    v_15456 = qcar(v_15456);
    if (!consp(v_15456)) goto v_15445;
    else goto v_15446;
v_15445:
    v_15455 = qcdr(v_15455);
    goto v_15432;
v_15446:
    v_15455 = nil;
    goto v_15444;
    v_15455 = nil;
v_15444:
    goto v_15436;
    v_15455 = nil;
v_15436:
    return onevalue(v_15455);
}



// Code for rowdel

static LispObject CC_rowdel(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15509, v_15510, v_15511;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15433);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15433;
// end of prologue
    v_15509 = stack[0];
    fn = elt(env, 3); // delhisto
    v_15509 = (*qfn1(fn))(fn, v_15509);
    env = stack[-2];
    goto v_15443;
v_15437:
    goto v_15448;
v_15444:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_15445;
v_15446:
    goto v_15455;
v_15451:
    v_15510 = qvalue(elt(env, 2)); // maxvar
    goto v_15452;
v_15453:
    v_15509 = stack[0];
    goto v_15454;
v_15455:
    goto v_15451;
v_15452:
    goto v_15453;
v_15454:
    v_15509 = plus2(v_15510, v_15509);
    env = stack[-2];
    goto v_15447;
v_15448:
    goto v_15444;
v_15445:
    goto v_15446;
v_15447:
    v_15511 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_15509-TAG_FIXNUM)/(16/CELL)));
    goto v_15438;
v_15439:
    v_15510 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15440;
v_15441:
    v_15509 = nil;
    goto v_15442;
v_15443:
    goto v_15437;
v_15438:
    goto v_15439;
v_15440:
    goto v_15441;
v_15442:
    *(LispObject *)((char *)v_15511 + (CELL-TAG_VECTOR) + (((intptr_t)v_15510-TAG_FIXNUM)/(16/CELL))) = v_15509;
    goto v_15469;
v_15465:
    goto v_15474;
v_15470:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_15471;
v_15472:
    goto v_15481;
v_15477:
    v_15510 = qvalue(elt(env, 2)); // maxvar
    goto v_15478;
v_15479:
    v_15509 = stack[0];
    goto v_15480;
v_15481:
    goto v_15477;
v_15478:
    goto v_15479;
v_15480:
    v_15509 = plus2(v_15510, v_15509);
    env = stack[-2];
    goto v_15473;
v_15474:
    goto v_15470;
v_15471:
    goto v_15472;
v_15473:
    v_15510 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_15509-TAG_FIXNUM)/(16/CELL)));
    goto v_15466;
v_15467:
    v_15509 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_15468;
v_15469:
    goto v_15465;
v_15466:
    goto v_15467;
v_15468:
    v_15509 = *(LispObject *)((char *)v_15510 + (CELL-TAG_VECTOR) + (((intptr_t)v_15509-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_15509;
v_15464:
    v_15509 = stack[0];
    if (v_15509 == nil) goto v_15489;
    else goto v_15490;
v_15489:
    v_15509 = nil;
    goto v_15463;
v_15490:
    v_15509 = stack[0];
    v_15509 = qcar(v_15509);
    goto v_15501;
v_15497:
    v_15510 = v_15509;
    v_15510 = qcar(v_15510);
    goto v_15498;
v_15499:
    v_15509 = qcdr(v_15509);
    v_15509 = qcar(v_15509);
    goto v_15500;
v_15501:
    goto v_15497;
v_15498:
    goto v_15499;
v_15500:
    fn = elt(env, 4); // downwght
    v_15509 = (*qfn2(fn))(fn, v_15510, v_15509);
    env = stack[-2];
    v_15509 = stack[0];
    v_15509 = qcdr(v_15509);
    stack[0] = v_15509;
    goto v_15464;
v_15463:
    return onevalue(v_15509);
}



// Code for dip2vdp

static LispObject CC_dip2vdp(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15499, v_15500;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15433);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_15500 = v_15433;
// end of prologue
    v_15499 = qvalue(elt(env, 1)); // !*groebsubs
    if (v_15499 == nil) goto v_15438;
    v_15499 = v_15500;
    fn = elt(env, 3); // dipsubs2
    v_15499 = (*qfn1(fn))(fn, v_15499);
    env = stack[-3];
    goto v_15436;
v_15438:
    v_15499 = v_15500;
    goto v_15436;
    v_15499 = nil;
v_15436:
    v_15500 = v_15499;
    v_15499 = v_15500;
    if (v_15499 == nil) goto v_15448;
    else goto v_15449;
v_15448:
    goto v_15460;
v_15452:
    stack[-2] = elt(env, 2); // vdp
    goto v_15453;
v_15454:
    stack[-1] = nil;
    goto v_15455;
v_15456:
    v_15499 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 4); // a2bc
    stack[0] = (*qfn1(fn))(fn, v_15499);
    env = stack[-3];
    goto v_15457;
v_15458:
    goto v_15470;
v_15466:
    v_15500 = nil;
    goto v_15467;
v_15468:
    v_15499 = nil;
    goto v_15469;
v_15470:
    goto v_15466;
v_15467:
    goto v_15468;
v_15469:
    v_15499 = list2(v_15500, v_15499);
    goto v_15459;
v_15460:
    goto v_15452;
v_15453:
    goto v_15454;
v_15455:
    goto v_15456;
v_15457:
    goto v_15458;
v_15459:
    {
        LispObject v_15504 = stack[-2];
        LispObject v_15505 = stack[-1];
        LispObject v_15506 = stack[0];
        return list3star(v_15504, v_15505, v_15506, v_15499);
    }
v_15449:
    goto v_15484;
v_15476:
    stack[-2] = elt(env, 2); // vdp
    goto v_15477;
v_15478:
    v_15499 = v_15500;
    stack[-1] = qcar(v_15499);
    goto v_15479;
v_15480:
    v_15499 = v_15500;
    v_15499 = qcdr(v_15499);
    stack[0] = qcar(v_15499);
    goto v_15481;
v_15482:
    goto v_15496;
v_15492:
    goto v_15493;
v_15494:
    v_15499 = nil;
    goto v_15495;
v_15496:
    goto v_15492;
v_15493:
    goto v_15494;
v_15495:
    v_15499 = list2(v_15500, v_15499);
    goto v_15483;
v_15484:
    goto v_15476;
v_15477:
    goto v_15478;
v_15479:
    goto v_15480;
v_15481:
    goto v_15482;
v_15483:
    {
        LispObject v_15507 = stack[-2];
        LispObject v_15508 = stack[-1];
        LispObject v_15509 = stack[0];
        return list3star(v_15507, v_15508, v_15509, v_15499);
    }
    v_15499 = nil;
    return onevalue(v_15499);
}



// Code for groebnormalform

static LispObject CC_groebnormalform(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15451, v_15452, v_15453, v_15454;
    LispObject fn;
    LispObject v_15435, v_15434, v_15433;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "groebnormalform");
    va_start(aa, nargs);
    v_15433 = va_arg(aa, LispObject);
    v_15434 = va_arg(aa, LispObject);
    v_15435 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15451 = v_15435;
    v_15452 = v_15434;
    v_15453 = v_15433;
// end of prologue
    goto v_15446;
v_15438:
    v_15454 = v_15453;
    goto v_15439;
v_15440:
    v_15453 = v_15452;
    goto v_15441;
v_15442:
    v_15452 = v_15451;
    goto v_15443;
v_15444:
    v_15451 = nil;
    goto v_15445;
v_15446:
    goto v_15438;
v_15439:
    goto v_15440;
v_15441:
    goto v_15442;
v_15443:
    goto v_15444;
v_15445:
    {
        fn = elt(env, 1); // groebnormalform0
        return (*qfnn(fn))(fn, 4, v_15454, v_15453, v_15452, v_15451);
    }
}



// Code for bfplusn

static LispObject CC_bfplusn(LispObject env,
                         LispObject v_15433, LispObject v_15434)
{
    env = qenv(env);
    LispObject v_15459, v_15460, v_15461;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15460 = v_15434;
    v_15461 = v_15433;
// end of prologue
    v_15459 = v_15461;
    if (!consp(v_15459)) goto v_15438;
    else goto v_15439;
v_15438:
    goto v_15446;
v_15442:
    v_15459 = v_15461;
    goto v_15443;
v_15444:
    goto v_15445;
v_15446:
    goto v_15442;
v_15443:
    goto v_15444;
v_15445:
    return plus2(v_15459, v_15460);
v_15439:
    goto v_15456;
v_15452:
    v_15459 = v_15461;
    goto v_15453;
v_15454:
    goto v_15455;
v_15456:
    goto v_15452;
v_15453:
    goto v_15454;
v_15455:
    {
        fn = elt(env, 1); // plus!:
        return (*qfn2(fn))(fn, v_15459, v_15460);
    }
    v_15459 = nil;
    return onevalue(v_15459);
}



// Code for contr!-strand

static LispObject CC_contrKstrand(LispObject env,
                         LispObject v_15433, LispObject v_15434)
{
    env = qenv(env);
    LispObject v_15458, v_15459;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15433,v_15434);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15434;
    v_15458 = v_15433;
// end of prologue
v_15438:
    v_15459 = stack[0];
    if (v_15459 == nil) goto v_15441;
    else goto v_15442;
v_15441:
    goto v_15437;
v_15442:
    goto v_15452;
v_15448:
    v_15459 = v_15458;
    goto v_15449;
v_15450:
    v_15458 = stack[0];
    v_15458 = qcar(v_15458);
    goto v_15451;
v_15452:
    goto v_15448;
v_15449:
    goto v_15450;
v_15451:
    fn = elt(env, 1); // contr1!-strand
    v_15458 = (*qfn2(fn))(fn, v_15459, v_15458);
    env = stack[-1];
    v_15459 = stack[0];
    v_15459 = qcdr(v_15459);
    stack[0] = v_15459;
    goto v_15438;
    v_15458 = nil;
v_15437:
    return onevalue(v_15458);
}



// Code for formde

static LispObject CC_formde(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15502, v_15503, v_15504;
    LispObject fn;
    LispObject v_15435, v_15434, v_15433;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formde");
    va_start(aa, nargs);
    v_15433 = va_arg(aa, LispObject);
    v_15434 = va_arg(aa, LispObject);
    v_15435 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15435,v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15433,v_15434,v_15435);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_15435;
    stack[-5] = v_15434;
    v_15502 = v_15433;
// end of prologue
    goto v_15444;
v_15438:
    goto v_15454;
v_15446:
    stack[-6] = elt(env, 1); // procedure
    goto v_15447;
v_15448:
    v_15503 = v_15502;
    v_15503 = qcdr(v_15503);
    stack[-3] = qcar(v_15503);
    goto v_15449;
v_15450:
    stack[-2] = elt(env, 2); // symbolic
    goto v_15451;
v_15452:
    goto v_15467;
v_15461:
    stack[-1] = elt(env, 3); // expr
    goto v_15462;
v_15463:
    v_15503 = v_15502;
    v_15503 = qcdr(v_15503);
    v_15503 = qcdr(v_15503);
    stack[0] = qcar(v_15503);
    goto v_15464;
v_15465:
    v_15503 = v_15502;
    v_15503 = qcdr(v_15503);
    v_15503 = qcdr(v_15503);
    v_15503 = qcdr(v_15503);
    v_15503 = qcdr(v_15503);
    if (v_15503 == nil) goto v_15475;
    else goto v_15476;
v_15475:
    v_15502 = qcdr(v_15502);
    v_15502 = qcdr(v_15502);
    v_15502 = qcdr(v_15502);
    v_15502 = qcar(v_15502);
    goto v_15474;
v_15476:
    goto v_15494;
v_15490:
    v_15503 = elt(env, 4); // progn
    goto v_15491;
v_15492:
    v_15502 = qcdr(v_15502);
    v_15502 = qcdr(v_15502);
    v_15502 = qcdr(v_15502);
    goto v_15493;
v_15494:
    goto v_15490;
v_15491:
    goto v_15492;
v_15493:
    v_15502 = cons(v_15503, v_15502);
    env = stack[-7];
    goto v_15474;
    v_15502 = nil;
v_15474:
    goto v_15466;
v_15467:
    goto v_15461;
v_15462:
    goto v_15463;
v_15464:
    goto v_15465;
v_15466:
    v_15502 = list3(stack[-1], stack[0], v_15502);
    env = stack[-7];
    goto v_15453;
v_15454:
    goto v_15446;
v_15447:
    goto v_15448;
v_15449:
    goto v_15450;
v_15451:
    goto v_15452;
v_15453:
    v_15504 = list3star(stack[-6], stack[-3], stack[-2], v_15502);
    env = stack[-7];
    goto v_15439;
v_15440:
    v_15503 = stack[-5];
    goto v_15441;
v_15442:
    v_15502 = stack[-4];
    goto v_15443;
v_15444:
    goto v_15438;
v_15439:
    goto v_15440;
v_15441:
    goto v_15442;
v_15443:
    {
        fn = elt(env, 5); // formproc
        return (*qfnn(fn))(fn, 3, v_15504, v_15503, v_15502);
    }
}



// Code for nf

static LispObject CC_nf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15726, v_15727, v_15728;
    LispObject fn;
    LispObject v_15436, v_15435, v_15434;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "nf");
    va_start(aa, nargs);
    v_15434 = va_arg(aa, LispObject);
    v_15435 = va_arg(aa, LispObject);
    v_15436 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15436,v_15435,v_15434);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15434,v_15435,v_15436);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_15436;
    v_15726 = v_15435;
    v_15727 = v_15434;
// end of prologue
// Binding gg!*
// FLUIDBIND: reloadenv=11 litvec-offset=1 saveloc=10
{   bind_fluid_stack bind_fluid_var(-11, 1, -10);
    qvalue(elt(env, 1)) = v_15726; // gg!*
    v_15726 = qvalue(elt(env, 1)); // gg!*
    if (v_15726 == nil) goto v_15444;
    else goto v_15445;
v_15444:
    v_15726 = v_15727;
    goto v_15443;
v_15445:
    stack[-3] = nil;
    v_15726 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_15726;
    v_15726 = v_15727;
    stack[-8] = v_15726;
    v_15726 = qvalue(elt(env, 1)); // gg!*
    stack[-2] = v_15726;
v_15463:
    v_15726 = stack[-8];
    if (v_15726 == nil) goto v_15470;
    else goto v_15471;
v_15470:
    goto v_15464;
v_15471:
    v_15726 = stack[-8];
    v_15726 = qcar(v_15726);
    v_15726 = qcar(v_15726);
    stack[-7] = v_15726;
v_15478:
    v_15726 = stack[-2];
    if (v_15726 == nil) goto v_15486;
    goto v_15493;
v_15489:
    v_15727 = stack[-7];
    goto v_15490;
v_15491:
    v_15726 = stack[-2];
    v_15726 = qcar(v_15726);
    v_15726 = qcdr(v_15726);
    goto v_15492;
v_15493:
    goto v_15489;
v_15490:
    goto v_15491;
v_15492:
    fn = elt(env, 12); // dless
    v_15726 = (*qfn2(fn))(fn, v_15727, v_15726);
    env = stack[-11];
    goto v_15484;
v_15486:
    v_15726 = nil;
    goto v_15484;
    v_15726 = nil;
v_15484:
    if (v_15726 == nil) goto v_15481;
    else goto v_15482;
v_15481:
    goto v_15477;
v_15482:
    v_15726 = stack[-2];
    v_15726 = qcdr(v_15726);
    stack[-2] = v_15726;
    goto v_15478;
v_15477:
    v_15726 = stack[-2];
    if (v_15726 == nil) goto v_15506;
    else goto v_15507;
v_15506:
    goto v_15464;
v_15507:
    v_15726 = stack[-2];
    stack[-1] = v_15726;
v_15512:
    v_15726 = stack[-1];
    if (v_15726 == nil) goto v_15515;
    goto v_15524;
v_15520:
    goto v_15530;
v_15526:
    v_15726 = stack[-1];
    v_15726 = qcar(v_15726);
    v_15727 = qcdr(v_15726);
    goto v_15527;
v_15528:
    v_15726 = stack[-7];
    goto v_15529;
v_15530:
    goto v_15526;
v_15527:
    goto v_15528;
v_15529:
    fn = elt(env, 13); // dd
    stack[-4] = (*qfn2(fn))(fn, v_15727, v_15726);
    env = stack[-11];
    goto v_15521;
v_15522:
    goto v_15540;
v_15536:
    v_15727 = stack[-9];
    goto v_15537;
v_15538:
    v_15726 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_15539;
v_15540:
    goto v_15536;
v_15537:
    goto v_15538;
v_15539:
    v_15726 = plus2(v_15727, v_15726);
    env = stack[-11];
    goto v_15523;
v_15524:
    goto v_15520;
v_15521:
    goto v_15522;
v_15523:
    if (((intptr_t)(stack[-4])) < ((intptr_t)(v_15726))) goto v_15519;
    else goto v_15515;
v_15519:
    goto v_15516;
v_15515:
    goto v_15511;
v_15516:
    v_15726 = stack[-1];
    v_15726 = qcdr(v_15726);
    stack[-1] = v_15726;
    goto v_15512;
v_15511:
    v_15726 = stack[-1];
    if (v_15726 == nil) goto v_15548;
    else goto v_15549;
v_15548:
    v_15726 = qvalue(elt(env, 2)); // redtails
    if (v_15726 == nil) goto v_15554;
    goto v_15563;
v_15557:
    v_15728 = stack[-7];
    goto v_15558;
v_15559:
    v_15726 = stack[-8];
    v_15726 = qcar(v_15726);
    v_15727 = qcdr(v_15726);
    goto v_15560;
v_15561:
    v_15726 = stack[-3];
    goto v_15562;
v_15563:
    goto v_15557;
v_15558:
    goto v_15559;
v_15560:
    goto v_15561;
v_15562:
    v_15726 = acons(v_15728, v_15727, v_15726);
    env = stack[-11];
    stack[-3] = v_15726;
    v_15726 = stack[-8];
    v_15726 = qcdr(v_15726);
    stack[-8] = v_15726;
    goto v_15552;
v_15554:
    goto v_15464;
v_15552:
    goto v_15547;
v_15549:
    goto v_15579;
v_15575:
    v_15727 = qvalue(elt(env, 3)); // gv!*
    goto v_15576;
v_15577:
    v_15726 = stack[-1];
    v_15726 = qcar(v_15726);
    v_15726 = qcar(v_15726);
    goto v_15578;
v_15579:
    goto v_15575;
v_15576:
    goto v_15577;
v_15578:
    v_15726 = *(LispObject *)((char *)v_15727 + (CELL-TAG_VECTOR) + (((intptr_t)v_15726-TAG_FIXNUM)/(16/CELL)));
    stack[-6] = v_15726;
    goto v_15590;
v_15586:
    v_15726 = stack[-8];
    v_15726 = qcar(v_15726);
    v_15727 = qcdr(v_15726);
    goto v_15587;
v_15588:
    v_15726 = stack[-6];
    v_15726 = qcar(v_15726);
    v_15726 = qcdr(v_15726);
    goto v_15589;
v_15590:
    goto v_15586;
v_15587:
    goto v_15588;
v_15589:
    fn = elt(env, 14); // gcdf!*
    v_15726 = (*qfn2(fn))(fn, v_15727, v_15726);
    env = stack[-11];
    stack[-4] = v_15726;
    goto v_15602;
v_15598:
    v_15726 = stack[-8];
    v_15726 = qcar(v_15726);
    v_15727 = qcdr(v_15726);
    goto v_15599;
v_15600:
    v_15726 = stack[-4];
    goto v_15601;
v_15602:
    goto v_15598;
v_15599:
    goto v_15600;
v_15601:
    fn = elt(env, 15); // cdiv
    v_15726 = (*qfn2(fn))(fn, v_15727, v_15726);
    env = stack[-11];
    stack[-5] = v_15726;
    goto v_15612;
v_15608:
    v_15726 = stack[-6];
    v_15726 = qcar(v_15726);
    v_15727 = qcdr(v_15726);
    goto v_15609;
v_15610:
    v_15726 = stack[-4];
    goto v_15611;
v_15612:
    goto v_15608;
v_15609:
    goto v_15610;
v_15611:
    fn = elt(env, 15); // cdiv
    v_15726 = (*qfn2(fn))(fn, v_15727, v_15726);
    env = stack[-11];
    stack[-4] = v_15726;
    goto v_15622;
v_15618:
    v_15727 = stack[-8];
    goto v_15619;
v_15620:
    v_15726 = stack[-4];
    goto v_15621;
v_15622:
    goto v_15618;
v_15619:
    goto v_15620;
v_15621:
    fn = elt(env, 16); // pcmult
    v_15726 = (*qfn2(fn))(fn, v_15727, v_15726);
    env = stack[-11];
    stack[-8] = v_15726;
    goto v_15630;
v_15626:
    v_15727 = stack[-3];
    goto v_15627;
v_15628:
    v_15726 = stack[-4];
    goto v_15629;
v_15630:
    goto v_15626;
v_15627:
    goto v_15628;
v_15629:
    fn = elt(env, 16); // pcmult
    v_15726 = (*qfn2(fn))(fn, v_15727, v_15726);
    env = stack[-11];
    stack[-3] = v_15726;
    goto v_15638;
v_15634:
    v_15727 = stack[-6];
    goto v_15635;
v_15636:
    v_15726 = stack[-5];
    goto v_15637;
v_15638:
    goto v_15634;
v_15635:
    goto v_15636;
v_15637:
    fn = elt(env, 16); // pcmult
    v_15726 = (*qfn2(fn))(fn, v_15727, v_15726);
    env = stack[-11];
    stack[-6] = v_15726;
    goto v_15646;
v_15642:
    v_15726 = stack[-6];
    stack[-4] = qcdr(v_15726);
    goto v_15643;
v_15644:
    goto v_15654;
v_15650:
    v_15727 = stack[-7];
    goto v_15651;
v_15652:
    v_15726 = stack[-1];
    v_15726 = qcar(v_15726);
    v_15726 = qcdr(v_15726);
    goto v_15653;
v_15654:
    goto v_15650;
v_15651:
    goto v_15652;
v_15653:
    fn = elt(env, 17); // dquot
    v_15726 = (*qfn2(fn))(fn, v_15727, v_15726);
    env = stack[-11];
    goto v_15645;
v_15646:
    goto v_15642;
v_15643:
    goto v_15644;
v_15645:
    fn = elt(env, 18); // pdmult
    v_15726 = (*qfn2(fn))(fn, stack[-4], v_15726);
    env = stack[-11];
    stack[-4] = v_15726;
    v_15726 = qvalue(elt(env, 4)); // tred
    if (v_15726 == nil) goto v_15662;
    v_15726 = Lterpri(nil, 0);
    env = stack[-11];
    v_15726 = elt(env, 5); // "r e d u c t i o n :  "
    v_15726 = Lprinc(nil, v_15726);
    env = stack[-11];
    v_15726 = stack[-7];
    v_15726 = Lprinc(nil, v_15726);
    env = stack[-11];
    v_15726 = elt(env, 6); // "/"
    v_15726 = Lprinc(nil, v_15726);
    env = stack[-11];
    v_15726 = stack[-1];
    v_15726 = qcar(v_15726);
    v_15726 = qcdr(v_15726);
    v_15726 = Lprinc(nil, v_15726);
    env = stack[-11];
    v_15726 = Lterpri(nil, 0);
    env = stack[-11];
    goto v_15660;
v_15662:
v_15660:
    v_15726 = qvalue(elt(env, 7)); // stars
    if (v_15726 == nil) goto v_15681;
    v_15726 = elt(env, 8); // "*"
    v_15726 = Lprinc(nil, v_15726);
    env = stack[-11];
    goto v_15679;
v_15681:
v_15679:
    v_15726 = stack[0];
    v_15726 = (LispObject)((intptr_t)(v_15726) + 0x10);
    stack[0] = v_15726;
    goto v_15693;
v_15689:
    v_15726 = stack[-8];
    v_15727 = qcdr(v_15726);
    goto v_15690;
v_15691:
    v_15726 = stack[-4];
    goto v_15692;
v_15693:
    goto v_15689;
v_15690:
    goto v_15691;
v_15692:
    fn = elt(env, 19); // pdif
    v_15726 = (*qfn2(fn))(fn, v_15727, v_15726);
    env = stack[-11];
    stack[-8] = v_15726;
    goto v_15547;
v_15547:
    goto v_15463;
v_15464:
    goto v_15702;
v_15698:
    v_15727 = qvalue(elt(env, 9)); // reductions!*
    goto v_15699;
v_15700:
    v_15726 = stack[0];
    goto v_15701;
v_15702:
    goto v_15698;
v_15699:
    goto v_15700;
v_15701:
    v_15726 = (LispObject)(intptr_t)((intptr_t)v_15727 + (intptr_t)v_15726 - TAG_FIXNUM);
    qvalue(elt(env, 9)) = v_15726; // reductions!*
    v_15726 = qvalue(elt(env, 10)); // nforms!*
    v_15726 = (LispObject)((intptr_t)(v_15726) + 0x10);
    qvalue(elt(env, 10)) = v_15726; // nforms!*
    goto v_15714;
v_15710:
    v_15726 = stack[-3];
    v_15727 = Lnreverse(nil, v_15726);
    env = stack[-11];
    goto v_15711;
v_15712:
    v_15726 = stack[-8];
    goto v_15713;
v_15714:
    goto v_15710;
v_15711:
    goto v_15712;
v_15713:
    v_15726 = Lappend(nil, v_15727, v_15726);
    env = stack[-11];
    fn = elt(env, 20); // gcdout
    v_15726 = (*qfn1(fn))(fn, v_15726);
    env = stack[-11];
    stack[-4] = v_15726;
    v_15726 = stack[-4];
    if (v_15726 == nil) goto v_15720;
    else goto v_15721;
v_15720:
    v_15726 = qvalue(elt(env, 11)); // zeros!*
    v_15726 = (LispObject)((intptr_t)(v_15726) + 0x10);
    qvalue(elt(env, 11)) = v_15726; // zeros!*
    goto v_15719;
v_15721:
v_15719:
    v_15726 = stack[-4];
    goto v_15443;
    v_15726 = nil;
v_15443:
    ;}  // end of a binding scope
    return onevalue(v_15726);
}



// Code for setk1

static LispObject CC_setk1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15713, v_15714, v_15715, v_15716, v_15717;
    LispObject fn;
    LispObject v_15435, v_15434, v_15433;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "setk1");
    va_start(aa, nargs);
    v_15433 = va_arg(aa, LispObject);
    v_15434 = va_arg(aa, LispObject);
    v_15435 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15435,v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15433,v_15434,v_15435);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-1] = v_15435;
    stack[0] = v_15434;
    stack[-5] = v_15433;
// end of prologue
    stack[-6] = nil;
// Binding !*uncached
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-7, 1, -2);
    qvalue(elt(env, 1)) = nil; // !*uncached
    v_15713 = lisp_true;
    qvalue(elt(env, 1)) = v_15713; // !*uncached
    v_15713 = stack[-5];
    if (!consp(v_15713)) goto v_15446;
    else goto v_15447;
v_15446:
    v_15713 = stack[-1];
    if (v_15713 == nil) goto v_15451;
    else goto v_15452;
v_15451:
    v_15713 = stack[-5];
    if (!symbolp(v_15713)) v_15713 = nil;
    else { v_15713 = qfastgets(v_15713);
           if (v_15713 != nil) { v_15713 = elt(v_15713, 4); // avalue
#ifdef RECORD_GET
             if (v_15713 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_15713 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_15713 == SPID_NOPROP) v_15713 = nil; }}
#endif
    if (v_15713 == nil) goto v_15456;
    else goto v_15457;
v_15456:
    goto v_15471;
v_15461:
    v_15717 = nil;
    goto v_15462;
v_15463:
    v_15716 = stack[-5];
    goto v_15464;
v_15465:
    v_15715 = elt(env, 2); // "not found"
    goto v_15466;
v_15467:
    v_15714 = nil;
    goto v_15468;
v_15469:
    v_15713 = nil;
    goto v_15470;
v_15471:
    goto v_15461;
v_15462:
    goto v_15463;
v_15464:
    goto v_15465;
v_15466:
    goto v_15467;
v_15468:
    goto v_15469;
v_15470:
    fn = elt(env, 10); // msgpri
    v_15713 = (*qfnn(fn))(fn, 5, v_15717, v_15716, v_15715, v_15714, v_15713);
    goto v_15455;
v_15457:
    goto v_15484;
v_15480:
    v_15714 = stack[-5];
    goto v_15481;
v_15482:
    v_15713 = elt(env, 3); // avalue
    goto v_15483;
v_15484:
    goto v_15480;
v_15481:
    goto v_15482;
v_15483:
    v_15713 = Lremprop(nil, v_15714, v_15713);
    goto v_15455;
v_15455:
    v_15713 = nil;
    goto v_15442;
v_15452:
    v_15713 = stack[-5];
    if (!symbolp(v_15713)) v_15713 = nil;
    else { v_15713 = qfastgets(v_15713);
           if (v_15713 != nil) { v_15713 = elt(v_15713, 4); // avalue
#ifdef RECORD_GET
             if (v_15713 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_15713 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_15713 == SPID_NOPROP) v_15713 = nil; }}
#endif
    stack[-6] = v_15713;
    if (v_15713 == nil) goto v_15489;
    goto v_15499;
v_15493:
    v_15715 = stack[-5];
    goto v_15494;
v_15495:
    v_15713 = stack[-6];
    v_15714 = qcar(v_15713);
    goto v_15496;
v_15497:
    v_15713 = stack[0];
    goto v_15498;
v_15499:
    goto v_15493;
v_15494:
    goto v_15495;
v_15496:
    goto v_15497;
v_15498:
    fn = elt(env, 11); // put!-avalue
    v_15713 = (*qfnn(fn))(fn, 3, v_15715, v_15714, v_15713);
    goto v_15450;
v_15489:
    goto v_15513;
v_15507:
    v_15715 = stack[-5];
    goto v_15508;
v_15509:
    v_15714 = elt(env, 4); // scalar
    goto v_15510;
v_15511:
    v_15713 = stack[0];
    goto v_15512;
v_15513:
    goto v_15507;
v_15508:
    goto v_15509;
v_15510:
    goto v_15511;
v_15512:
    fn = elt(env, 11); // put!-avalue
    v_15713 = (*qfnn(fn))(fn, 3, v_15715, v_15714, v_15713);
    goto v_15450;
v_15450:
    v_15713 = stack[0];
    goto v_15442;
v_15447:
    v_15713 = stack[-5];
    v_15713 = qcar(v_15713);
    if (!consp(v_15713)) goto v_15519;
    goto v_15529;
v_15523:
    v_15715 = elt(env, 5); // alg
    goto v_15524;
v_15525:
    v_15714 = (LispObject)400+TAG_FIXNUM; // 25
    goto v_15526;
v_15527:
    v_15713 = elt(env, 6); // "Invalid syntax: improper assignment"
    goto v_15528;
v_15529:
    goto v_15523;
v_15524:
    goto v_15525;
v_15526:
    goto v_15527;
v_15528:
    fn = elt(env, 12); // rerror
    v_15713 = (*qfnn(fn))(fn, 3, v_15715, v_15714, v_15713);
    env = stack[-7];
    goto v_15445;
v_15519:
v_15445:
    goto v_15538;
v_15534:
    v_15713 = stack[-5];
    stack[-3] = qcar(v_15713);
    goto v_15535;
v_15536:
    v_15713 = stack[-5];
    v_15713 = qcdr(v_15713);
    fn = elt(env, 13); // revlis
    v_15713 = (*qfn1(fn))(fn, v_15713);
    env = stack[-7];
    goto v_15537;
v_15538:
    goto v_15534;
v_15535:
    goto v_15536;
v_15537:
    v_15713 = cons(stack[-3], v_15713);
    env = stack[-7];
    stack[-5] = v_15713;
    v_15713 = stack[-1];
    if (v_15713 == nil) goto v_15546;
    else goto v_15547;
v_15546:
    goto v_15553;
v_15549:
    v_15714 = stack[-5];
    goto v_15550;
v_15551:
    v_15713 = qvalue(elt(env, 7)); // wtl!*
    goto v_15552;
v_15553:
    goto v_15549;
v_15550:
    goto v_15551;
v_15552:
    v_15713 = Lassoc(nil, v_15714, v_15713);
    stack[-3] = v_15713;
    v_15713 = stack[-5];
    v_15713 = qcar(v_15713);
    if (!symbolp(v_15713)) v_15713 = nil;
    else { v_15713 = qfastgets(v_15713);
           if (v_15713 != nil) { v_15713 = elt(v_15713, 50); // kvalue
#ifdef RECORD_GET
             if (v_15713 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v_15713 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v_15713 == SPID_NOPROP) v_15713 = nil; }}
#endif
    stack[-4] = v_15713;
    if (v_15713 == nil) goto v_15563;
    else goto v_15564;
v_15563:
    v_15713 = lisp_true;
    goto v_15562;
v_15564:
    goto v_15575;
v_15571:
    v_15714 = stack[-5];
    goto v_15572;
v_15573:
    v_15713 = stack[-4];
    goto v_15574;
v_15575:
    goto v_15571;
v_15572:
    goto v_15573;
v_15574:
    v_15713 = Lassoc(nil, v_15714, v_15713);
    stack[-6] = v_15713;
    v_15713 = (v_15713 == nil ? lisp_true : nil);
    goto v_15562;
    v_15713 = nil;
v_15562:
    if (v_15713 == nil) goto v_15560;
    v_15713 = stack[-3];
    if (v_15713 == nil) goto v_15586;
    else goto v_15587;
v_15586:
    v_15713 = qvalue(elt(env, 8)); // !*sqrtrulep
    v_15713 = (v_15713 == nil ? lisp_true : nil);
    goto v_15585;
v_15587:
    v_15713 = nil;
    goto v_15585;
    v_15713 = nil;
v_15585:
    if (v_15713 == nil) goto v_15583;
    goto v_15605;
v_15595:
    v_15717 = nil;
    goto v_15596;
v_15597:
    v_15716 = stack[-5];
    goto v_15598;
v_15599:
    v_15715 = elt(env, 2); // "not found"
    goto v_15600;
v_15601:
    v_15714 = nil;
    goto v_15602;
v_15603:
    v_15713 = nil;
    goto v_15604;
v_15605:
    goto v_15595;
v_15596:
    goto v_15597;
v_15598:
    goto v_15599;
v_15600:
    goto v_15601;
v_15602:
    goto v_15603;
v_15604:
    fn = elt(env, 10); // msgpri
    v_15713 = (*qfnn(fn))(fn, 5, v_15717, v_15716, v_15715, v_15714, v_15713);
    env = stack[-7];
    goto v_15581;
v_15583:
v_15581:
    goto v_15558;
v_15560:
    goto v_15620;
v_15614:
    v_15713 = stack[-5];
    stack[-1] = qcar(v_15713);
    goto v_15615;
v_15616:
    stack[0] = elt(env, 9); // kvalue
    goto v_15617;
v_15618:
    goto v_15629;
v_15625:
    v_15714 = stack[-6];
    goto v_15626;
v_15627:
    v_15713 = stack[-4];
    goto v_15628;
v_15629:
    goto v_15625;
v_15626:
    goto v_15627;
v_15628:
    v_15713 = Ldelete(nil, v_15714, v_15713);
    env = stack[-7];
    goto v_15619;
v_15620:
    goto v_15614;
v_15615:
    goto v_15616;
v_15617:
    goto v_15618;
v_15619:
    v_15713 = Lputprop(nil, 3, stack[-1], stack[0], v_15713);
    env = stack[-7];
    goto v_15558;
v_15558:
    v_15713 = stack[-3];
    if (v_15713 == nil) goto v_15635;
    goto v_15642;
v_15638:
    v_15714 = stack[-5];
    goto v_15639;
v_15640:
    v_15713 = qvalue(elt(env, 7)); // wtl!*
    goto v_15641;
v_15642:
    goto v_15638;
v_15639:
    goto v_15640;
v_15641:
    fn = elt(env, 14); // delasc
    v_15713 = (*qfn2(fn))(fn, v_15714, v_15713);
    env = stack[-7];
    qvalue(elt(env, 7)) = v_15713; // wtl!*
    goto v_15633;
v_15635:
v_15633:
    v_15713 = nil;
    goto v_15442;
v_15547:
    v_15713 = stack[-5];
    v_15713 = qcar(v_15713);
    if (!symbolp(v_15713)) v_15713 = nil;
    else { v_15713 = qfastgets(v_15713);
           if (v_15713 != nil) { v_15713 = elt(v_15713, 50); // kvalue
#ifdef RECORD_GET
             if (v_15713 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v_15713 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v_15713 == SPID_NOPROP) v_15713 = nil; }}
#endif
    stack[-4] = v_15713;
    if (v_15713 == nil) goto v_15646;
    else goto v_15647;
v_15646:
    goto v_15660;
v_15652:
    v_15713 = stack[-5];
    v_15716 = qcar(v_15713);
    goto v_15653;
v_15654:
    v_15715 = nil;
    goto v_15655;
v_15656:
    v_15714 = stack[-5];
    goto v_15657;
v_15658:
    v_15713 = stack[0];
    goto v_15659;
v_15660:
    goto v_15652;
v_15653:
    goto v_15654;
v_15655:
    goto v_15656;
v_15657:
    goto v_15658;
v_15659:
    fn = elt(env, 15); // put!-kvalue
    v_15713 = (*qfnn(fn))(fn, 4, v_15716, v_15715, v_15714, v_15713);
    goto v_15545;
v_15647:
    goto v_15676;
v_15672:
    v_15714 = stack[-5];
    goto v_15673;
v_15674:
    v_15713 = stack[-4];
    goto v_15675;
v_15676:
    goto v_15672;
v_15673:
    goto v_15674;
v_15675:
    v_15713 = Lassoc(nil, v_15714, v_15713);
    stack[-6] = v_15713;
    if (v_15713 == nil) goto v_15671;
    goto v_15685;
v_15681:
    v_15714 = stack[-5];
    goto v_15682;
v_15683:
    v_15713 = stack[0];
    goto v_15684;
v_15685:
    goto v_15681;
v_15682:
    goto v_15683;
v_15684:
    fn = elt(env, 16); // updoldrules
    v_15713 = (*qfn2(fn))(fn, v_15714, v_15713);
    env = stack[-7];
    goto v_15693;
v_15689:
    v_15713 = stack[-6];
    v_15714 = qcar(v_15713);
    goto v_15690;
v_15691:
    v_15713 = stack[-4];
    goto v_15692;
v_15693:
    goto v_15689;
v_15690:
    goto v_15691;
v_15692:
    fn = elt(env, 14); // delasc
    v_15713 = (*qfn2(fn))(fn, v_15714, v_15713);
    env = stack[-7];
    stack[-4] = v_15713;
    goto v_15669;
v_15671:
v_15669:
    goto v_15706;
v_15698:
    v_15713 = stack[-5];
    v_15716 = qcar(v_15713);
    goto v_15699;
v_15700:
    v_15715 = stack[-4];
    goto v_15701;
v_15702:
    v_15714 = stack[-5];
    goto v_15703;
v_15704:
    v_15713 = stack[0];
    goto v_15705;
v_15706:
    goto v_15698;
v_15699:
    goto v_15700;
v_15701:
    goto v_15702;
v_15703:
    goto v_15704;
v_15705:
    fn = elt(env, 15); // put!-kvalue
    v_15713 = (*qfnn(fn))(fn, 4, v_15716, v_15715, v_15714, v_15713);
    goto v_15545;
v_15545:
    v_15713 = stack[0];
v_15442:
    ;}  // end of a binding scope
    return onevalue(v_15713);
}



// Code for lex_export_codes

static LispObject CC_lex_export_codes(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15442, v_15443;
    LispObject fn;
    argcheck(nargs, 0, "lex_export_codes");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    goto v_15439;
v_15435:
    v_15443 = qvalue(elt(env, 1)); // lex_codename
    goto v_15436;
v_15437:
    v_15442 = elt(env, 2); // ordopcar
    goto v_15438;
v_15439:
    goto v_15435;
v_15436:
    goto v_15437;
v_15438:
    {
        fn = elt(env, 3); // sort
        return (*qfn2(fn))(fn, v_15443, v_15442);
    }
}



// Code for aex_lc

static LispObject CC_aex_lc(LispObject env,
                         LispObject v_15433, LispObject v_15434)
{
    env = qenv(env);
    LispObject v_15498, v_15499;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15433,v_15434);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_15498 = v_15434;
    stack[-1] = v_15433;
// end of prologue
    goto v_15449;
v_15445:
    v_15499 = stack[-1];
    goto v_15446;
v_15447:
    goto v_15448;
v_15449:
    goto v_15445;
v_15446:
    goto v_15447;
v_15448:
    fn = elt(env, 1); // aex_mvartest
    v_15498 = (*qfn2(fn))(fn, v_15499, v_15498);
    env = stack[-3];
    if (v_15498 == nil) goto v_15443;
    v_15498 = stack[-1];
    fn = elt(env, 2); // aex_ex
    v_15498 = (*qfn1(fn))(fn, v_15498);
    env = stack[-3];
    stack[-2] = v_15498;
    goto v_15459;
v_15455:
    goto v_15465;
v_15461:
    v_15498 = stack[-2];
    v_15498 = qcar(v_15498);
    fn = elt(env, 3); // sfto_lcx
    v_15499 = (*qfn1(fn))(fn, v_15498);
    env = stack[-3];
    goto v_15462;
v_15463:
    v_15498 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15464;
v_15465:
    goto v_15461;
v_15462:
    goto v_15463;
v_15464:
    stack[0] = cons(v_15499, v_15498);
    env = stack[-3];
    goto v_15456;
v_15457:
    goto v_15475;
v_15471:
    v_15498 = stack[-2];
    v_15499 = qcdr(v_15498);
    goto v_15472;
v_15473:
    v_15498 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15474;
v_15475:
    goto v_15471;
v_15472:
    goto v_15473;
v_15474:
    v_15498 = cons(v_15499, v_15498);
    env = stack[-3];
    goto v_15458;
v_15459:
    goto v_15455;
v_15456:
    goto v_15457;
v_15458:
    fn = elt(env, 4); // quotsq
    v_15498 = (*qfn2(fn))(fn, stack[0], v_15498);
    env = stack[-3];
    goto v_15484;
v_15480:
    stack[-2] = v_15498;
    goto v_15481;
v_15482:
    goto v_15491;
v_15487:
    v_15498 = qcar(v_15498);
    fn = elt(env, 5); // kernels
    stack[0] = (*qfn1(fn))(fn, v_15498);
    env = stack[-3];
    goto v_15488;
v_15489:
    v_15498 = stack[-1];
    fn = elt(env, 6); // aex_ctx
    v_15498 = (*qfn1(fn))(fn, v_15498);
    env = stack[-3];
    goto v_15490;
v_15491:
    goto v_15487;
v_15488:
    goto v_15489;
v_15490:
    fn = elt(env, 7); // ctx_filter
    v_15498 = (*qfn2(fn))(fn, stack[0], v_15498);
    env = stack[-3];
    goto v_15483;
v_15484:
    goto v_15480;
v_15481:
    goto v_15482;
v_15483:
    {
        LispObject v_15503 = stack[-2];
        fn = elt(env, 8); // aex_mk
        return (*qfn2(fn))(fn, v_15503, v_15498);
    }
v_15443:
    v_15498 = stack[-1];
    return onevalue(v_15498);
}



// Code for procstat1

static LispObject CC_procstat1(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15830, v_15831, v_15832;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15433);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_15433;
// end of prologue
    stack[-8] = nil;
    stack[-7] = nil;
    stack[-2] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-1] = nil;
    v_15830 = qvalue(elt(env, 1)); // ifl!*
    if (v_15830 == nil) goto v_15449;
    v_15830 = qvalue(elt(env, 1)); // ifl!*
    v_15830 = qcar(v_15830);
    stack[-5] = v_15830;
    goto v_15447;
v_15449:
    goto v_15459;
v_15455:
    goto v_15456;
v_15457:
    goto v_15458;
v_15459:
    goto v_15455;
v_15456:
    goto v_15457;
v_15458:
    goto v_15447;
v_15447:
    v_15830 = qvalue(elt(env, 3)); // curline!*
    stack[-4] = v_15830;
    v_15830 = qvalue(elt(env, 4)); // erfg!*
    stack[-10] = v_15830;
    v_15830 = qvalue(elt(env, 5)); // fname!*
    if (v_15830 == nil) goto v_15468;
    v_15830 = lisp_true;
    stack[-10] = v_15830;
    goto v_15476;
v_15472:
    v_15831 = elt(env, 6); // (symerr (quote procedure) t)
    goto v_15473;
v_15474:
    v_15830 = nil;
    goto v_15475;
v_15476:
    goto v_15472;
v_15473:
    goto v_15474;
v_15475:
    fn = elt(env, 25); // errorset!*
    v_15830 = (*qfn2(fn))(fn, v_15831, v_15830);
    env = stack[-11];
    goto v_15466;
v_15468:
    goto v_15489;
v_15485:
    v_15831 = qvalue(elt(env, 7)); // cursym!*
    goto v_15486;
v_15487:
    v_15830 = elt(env, 8); // procedure
    goto v_15488;
v_15489:
    goto v_15485;
v_15486:
    goto v_15487;
v_15488:
    if (v_15831 == v_15830) goto v_15483;
    else goto v_15484;
v_15483:
    v_15830 = elt(env, 9); // expr
    stack[-8] = v_15830;
    goto v_15482;
v_15484:
    v_15830 = qvalue(elt(env, 7)); // cursym!*
    stack[-8] = v_15830;
    fn = elt(env, 26); // scan
    v_15830 = (*qfnn(fn))(fn, 0);
    env = stack[-11];
    goto v_15482;
v_15482:
    goto v_15505;
v_15501:
    v_15831 = qvalue(elt(env, 7)); // cursym!*
    goto v_15502;
v_15503:
    v_15830 = elt(env, 8); // procedure
    goto v_15504;
v_15505:
    goto v_15501;
v_15502:
    goto v_15503;
v_15504:
    if (v_15831 == v_15830) goto v_15500;
    goto v_15513;
v_15509:
    v_15831 = elt(env, 6); // (symerr (quote procedure) t)
    goto v_15510;
v_15511:
    v_15830 = nil;
    goto v_15512;
v_15513:
    goto v_15509;
v_15510:
    goto v_15511;
v_15512:
    fn = elt(env, 25); // errorset!*
    v_15830 = (*qfn2(fn))(fn, v_15831, v_15830);
    env = stack[-11];
    goto v_15498;
v_15500:
    v_15830 = qvalue(elt(env, 10)); // !*reduce4
    if (v_15830 == nil) goto v_15521;
    fn = elt(env, 26); // scan
    v_15830 = (*qfnn(fn))(fn, 0);
    env = stack[-11];
    qvalue(elt(env, 5)) = v_15830; // fname!*
    v_15830 = qvalue(elt(env, 5)); // fname!*
    if (symbolp(v_15830)) goto v_15527;
    goto v_15534;
v_15530:
    v_15831 = qvalue(elt(env, 5)); // fname!*
    goto v_15531;
v_15532:
    v_15830 = elt(env, 11); // "procedure name"
    goto v_15533;
v_15534:
    goto v_15530;
v_15531:
    goto v_15532;
v_15533:
    fn = elt(env, 27); // typerr
    v_15830 = (*qfn2(fn))(fn, v_15831, v_15830);
    env = stack[-11];
    goto v_15525;
v_15527:
    fn = elt(env, 26); // scan
    v_15830 = (*qfnn(fn))(fn, 0);
    env = stack[-11];
    goto v_15545;
v_15541:
    goto v_15551;
v_15547:
    stack[0] = elt(env, 12); // read_param_list
    goto v_15548;
v_15549:
    v_15830 = stack[-9];
    v_15830 = Lmkquote(nil, v_15830);
    env = stack[-11];
    goto v_15550;
v_15551:
    goto v_15547;
v_15548:
    goto v_15549;
v_15550:
    v_15831 = list2(stack[0], v_15830);
    env = stack[-11];
    goto v_15542;
v_15543:
    v_15830 = nil;
    goto v_15544;
v_15545:
    goto v_15541;
v_15542:
    goto v_15543;
v_15544:
    fn = elt(env, 25); // errorset!*
    v_15830 = (*qfn2(fn))(fn, v_15831, v_15830);
    env = stack[-11];
    stack[-2] = v_15830;
    v_15830 = stack[-2];
    fn = elt(env, 28); // errorp
    v_15830 = (*qfn1(fn))(fn, v_15830);
    env = stack[-11];
    if (v_15830 == nil) goto v_15558;
    else goto v_15559;
v_15558:
    v_15830 = stack[-2];
    v_15830 = qcar(v_15830);
    stack[-2] = v_15830;
    goto v_15572;
v_15568:
    v_15831 = qvalue(elt(env, 7)); // cursym!*
    goto v_15569;
v_15570:
    v_15830 = elt(env, 13); // !*colon!*
    goto v_15571;
v_15572:
    goto v_15568;
v_15569:
    goto v_15570;
v_15571:
    if (v_15831 == v_15830) goto v_15566;
    else goto v_15567;
v_15566:
    fn = elt(env, 29); // read_type
    v_15830 = (*qfnn(fn))(fn, 0);
    env = stack[-11];
    stack[-9] = v_15830;
    goto v_15565;
v_15567:
v_15565:
    goto v_15557;
v_15559:
v_15557:
    goto v_15525;
v_15525:
    goto v_15519;
v_15521:
    fn = elt(env, 26); // scan
    v_15830 = (*qfnn(fn))(fn, 0);
    env = stack[-11];
    fn = elt(env, 30); // read_signature
    v_15830 = (*qfnn(fn))(fn, 0);
    env = stack[-11];
    stack[-7] = v_15830;
    goto v_15589;
v_15581:
    stack[-3] = elt(env, 14); // put
    goto v_15582;
v_15583:
    v_15830 = stack[-7];
    v_15830 = qcar(v_15830);
    v_15830 = qcar(v_15830);
    stack[-2] = Lmkquote(nil, v_15830);
    env = stack[-11];
    goto v_15584;
v_15585:
    stack[-1] = elt(env, 15); // (quote procedure_type)
    goto v_15586;
v_15587:
    goto v_15604;
v_15598:
    stack[0] = elt(env, 16); // arrow
    goto v_15599;
v_15600:
    v_15830 = stack[-7];
    v_15830 = qcar(v_15830);
    v_15830 = qcdr(v_15830);
    fn = elt(env, 31); // make_tuple_type
    v_15831 = (*qfn1(fn))(fn, v_15830);
    env = stack[-11];
    goto v_15601;
v_15602:
    v_15830 = stack[-7];
    v_15830 = qcdr(v_15830);
    goto v_15603;
v_15604:
    goto v_15598;
v_15599:
    goto v_15600;
v_15601:
    goto v_15602;
v_15603:
    v_15830 = list2star(stack[0], v_15831, v_15830);
    env = stack[-11];
    v_15830 = Lmkquote(nil, v_15830);
    env = stack[-11];
    goto v_15588;
v_15589:
    goto v_15581;
v_15582:
    goto v_15583;
v_15584:
    goto v_15585;
v_15586:
    goto v_15587;
v_15588:
    v_15830 = list4(stack[-3], stack[-2], stack[-1], v_15830);
    env = stack[-11];
    stack[-1] = v_15830;
    v_15830 = stack[-7];
    v_15830 = qcar(v_15830);
    stack[-7] = v_15830;
    v_15830 = stack[-7];
    v_15830 = qcar(v_15830);
    qvalue(elt(env, 5)) = v_15830; // fname!*
    goto v_15621;
v_15617:
    stack[0] = qvalue(elt(env, 5)); // fname!*
    goto v_15618;
v_15619:
    v_15830 = stack[-7];
    v_15830 = qcdr(v_15830);
    fn = elt(env, 32); // collect_cars
    v_15830 = (*qfn1(fn))(fn, v_15830);
    env = stack[-11];
    goto v_15620;
v_15621:
    goto v_15617;
v_15618:
    goto v_15619;
v_15620:
    v_15830 = cons(stack[0], v_15830);
    env = stack[-11];
    stack[-7] = v_15830;
    v_15830 = stack[-7];
    v_15830 = qcdr(v_15830);
    stack[-2] = v_15830;
    goto v_15519;
v_15519:
    goto v_15498;
v_15498:
    goto v_15466;
v_15466:
    goto v_15637;
v_15633:
    v_15831 = qvalue(elt(env, 17)); // eof!*
    goto v_15634;
v_15635:
    v_15830 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15636;
v_15637:
    goto v_15633;
v_15634:
    goto v_15635;
v_15636:
    v_15830 = (LispObject)greaterp2(v_15831, v_15830);
    v_15830 = v_15830 ? lisp_true : nil;
    env = stack[-11];
    if (v_15830 == nil) goto v_15631;
    v_15830 = elt(env, 18); // !*semicol!*
    qvalue(elt(env, 7)) = v_15830; // cursym!*
    v_15830 = nil;
    qvalue(elt(env, 19)) = v_15830; // curescaped!*
    goto v_15629;
v_15631:
    goto v_15649;
v_15645:
    v_15831 = elt(env, 20); // (xread t)
    goto v_15646;
v_15647:
    v_15830 = nil;
    goto v_15648;
v_15649:
    goto v_15645;
v_15646:
    goto v_15647;
v_15648:
    fn = elt(env, 25); // errorset!*
    v_15830 = (*qfn2(fn))(fn, v_15831, v_15830);
    env = stack[-11];
    stack[-6] = v_15830;
    v_15830 = stack[-6];
    fn = elt(env, 28); // errorp
    v_15830 = (*qfn1(fn))(fn, v_15830);
    env = stack[-11];
    if (v_15830 == nil) goto v_15654;
    else goto v_15655;
v_15654:
    v_15830 = stack[-6];
    v_15830 = qcar(v_15830);
    stack[-6] = v_15830;
    goto v_15653;
v_15655:
v_15653:
    v_15830 = qvalue(elt(env, 4)); // erfg!*
    if (v_15830 == nil) goto v_15662;
    else goto v_15663;
v_15662:
    goto v_15674;
v_15666:
    stack[0] = elt(env, 8); // procedure
    goto v_15667;
v_15668:
    v_15830 = qvalue(elt(env, 10)); // !*reduce4
    if (v_15830 == nil) goto v_15678;
    else goto v_15679;
v_15678:
    v_15830 = stack[-7];
    v_15830 = qcar(v_15830);
    stack[-3] = v_15830;
    goto v_15677;
v_15679:
    v_15830 = qvalue(elt(env, 5)); // fname!*
    stack[-3] = v_15830;
    goto v_15677;
    stack[-3] = nil;
v_15677:
    goto v_15669;
v_15670:
    stack[-7] = stack[-9];
    goto v_15671;
v_15672:
    goto v_15694;
v_15688:
    v_15832 = stack[-8];
    goto v_15689;
v_15690:
    v_15831 = stack[-2];
    goto v_15691;
v_15692:
    v_15830 = stack[-6];
    goto v_15693;
v_15694:
    goto v_15688;
v_15689:
    goto v_15690;
v_15691:
    goto v_15692;
v_15693:
    v_15830 = list3(v_15832, v_15831, v_15830);
    env = stack[-11];
    goto v_15673;
v_15674:
    goto v_15666;
v_15667:
    goto v_15668;
v_15669:
    goto v_15670;
v_15671:
    goto v_15672;
v_15673:
    v_15830 = list3star(stack[0], stack[-3], stack[-7], v_15830);
    env = stack[-11];
    stack[-6] = v_15830;
    goto v_15661;
v_15663:
v_15661:
    goto v_15629;
v_15629:
    goto v_15703;
v_15699:
    v_15830 = qvalue(elt(env, 5)); // fname!*
    v_15831 = ncons(v_15830);
    env = stack[-11];
    goto v_15700;
v_15701:
    v_15830 = elt(env, 21); // fnc
    goto v_15702;
v_15703:
    goto v_15699;
v_15700:
    goto v_15701;
v_15702:
    v_15830 = Lremflag(nil, v_15831, v_15830);
    env = stack[-11];
    v_15830 = nil;
    qvalue(elt(env, 5)) = v_15830; // fname!*
    v_15830 = qvalue(elt(env, 4)); // erfg!*
    if (v_15830 == nil) goto v_15711;
    v_15830 = nil;
    stack[-6] = v_15830;
    v_15830 = stack[-10];
    if (v_15830 == nil) goto v_15716;
    else goto v_15717;
v_15716:
    Lerror0(nil, 0);
    env = stack[-11];
    goto v_15715;
v_15717:
v_15715:
    goto v_15709;
v_15711:
v_15709:
    v_15830 = qvalue(elt(env, 1)); // ifl!*
    if (v_15830 == nil) goto v_15723;
    v_15830 = stack[-6];
    if (!consp(v_15830)) goto v_15730;
    v_15830 = stack[-6];
    v_15830 = qcdr(v_15830);
    if (!consp(v_15830)) goto v_15735;
    v_15830 = stack[-6];
    v_15830 = qcdr(v_15830);
    v_15830 = qcar(v_15830);
    v_15830 = Lsymbolp(nil, v_15830);
    env = stack[-11];
    goto v_15733;
v_15735:
    v_15830 = nil;
    goto v_15733;
    v_15830 = nil;
v_15733:
    goto v_15728;
v_15730:
    v_15830 = nil;
    goto v_15728;
    v_15830 = nil;
v_15728:
    if (v_15830 == nil) goto v_15723;
    goto v_15755;
v_15749:
    goto v_15765;
v_15757:
    stack[-3] = elt(env, 14); // put
    goto v_15758;
v_15759:
    v_15830 = stack[-6];
    v_15830 = qcdr(v_15830);
    v_15830 = qcar(v_15830);
    stack[-2] = Lmkquote(nil, v_15830);
    env = stack[-11];
    goto v_15760;
v_15761:
    stack[0] = elt(env, 22); // (quote defined!-in!-file)
    goto v_15762;
v_15763:
    v_15830 = stack[-5];
    fn = elt(env, 33); // simplify!-filename
    v_15830 = (*qfn1(fn))(fn, v_15830);
    env = stack[-11];
    v_15830 = Lintern(nil, v_15830);
    env = stack[-11];
    v_15830 = Lmkquote(nil, v_15830);
    env = stack[-11];
    goto v_15764;
v_15765:
    goto v_15757;
v_15758:
    goto v_15759;
v_15760:
    goto v_15761;
v_15762:
    goto v_15763;
v_15764:
    stack[-2] = list4(stack[-3], stack[-2], stack[0], v_15830);
    env = stack[-11];
    goto v_15750;
v_15751:
    goto v_15785;
v_15777:
    stack[0] = elt(env, 14); // put
    goto v_15778;
v_15779:
    v_15830 = stack[-6];
    v_15830 = qcdr(v_15830);
    v_15830 = qcar(v_15830);
    v_15832 = Lmkquote(nil, v_15830);
    env = stack[-11];
    goto v_15780;
v_15781:
    v_15831 = elt(env, 23); // (quote defined!-on!-line)
    goto v_15782;
v_15783:
    v_15830 = stack[-4];
    goto v_15784;
v_15785:
    goto v_15777;
v_15778:
    goto v_15779;
v_15780:
    goto v_15781;
v_15782:
    goto v_15783;
v_15784:
    v_15831 = list4(stack[0], v_15832, v_15831, v_15830);
    env = stack[-11];
    goto v_15752;
v_15753:
    v_15830 = stack[-6];
    goto v_15754;
v_15755:
    goto v_15749;
v_15750:
    goto v_15751;
v_15752:
    goto v_15753;
v_15754:
    v_15830 = list3(stack[-2], v_15831, v_15830);
    env = stack[-11];
    stack[-6] = v_15830;
    goto v_15721;
v_15723:
    v_15830 = stack[-6];
    v_15830 = ncons(v_15830);
    env = stack[-11];
    stack[-6] = v_15830;
    goto v_15721;
v_15721:
    v_15830 = stack[-1];
    if (v_15830 == nil) goto v_15801;
    goto v_15808;
v_15804:
    v_15831 = stack[-1];
    goto v_15805;
v_15806:
    v_15830 = stack[-6];
    goto v_15807;
v_15808:
    goto v_15804;
v_15805:
    goto v_15806;
v_15807:
    v_15830 = cons(v_15831, v_15830);
    env = stack[-11];
    stack[-6] = v_15830;
    goto v_15799;
v_15801:
v_15799:
    v_15830 = stack[-6];
    v_15830 = qcdr(v_15830);
    if (v_15830 == nil) goto v_15813;
    else goto v_15814;
v_15813:
    v_15830 = stack[-6];
    v_15830 = qcar(v_15830);
    stack[-6] = v_15830;
    goto v_15812;
v_15814:
    goto v_15826;
v_15822:
    v_15831 = elt(env, 24); // progn
    goto v_15823;
v_15824:
    v_15830 = stack[-6];
    goto v_15825;
v_15826:
    goto v_15822;
v_15823:
    goto v_15824;
v_15825:
    v_15830 = cons(v_15831, v_15830);
    stack[-6] = v_15830;
    goto v_15812;
v_15812:
    v_15830 = stack[-6];
    return onevalue(v_15830);
}



// Code for prepreform1

static LispObject CC_prepreform1(LispObject env,
                         LispObject v_15433, LispObject v_15434)
{
    env = qenv(env);
    LispObject v_15631, v_15632;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15433,v_15434);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_15434;
    stack[0] = v_15433;
// end of prologue
v_15432:
    v_15631 = stack[0];
    if (!consp(v_15631)) goto v_15442;
    else goto v_15443;
v_15442:
    v_15631 = lisp_true;
    goto v_15441;
v_15443:
    v_15631 = stack[0];
    v_15631 = qcar(v_15631);
    if (!symbolp(v_15631)) v_15631 = nil;
    else { v_15631 = qfastgets(v_15631);
           if (v_15631 != nil) { v_15631 = elt(v_15631, 8); // dname
#ifdef RECORD_GET
             if (v_15631 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_15631 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_15631 == SPID_NOPROP) v_15631 = nil; }}
#endif
    goto v_15441;
    v_15631 = nil;
v_15441:
    if (v_15631 == nil) goto v_15439;
    v_15631 = stack[0];
    goto v_15437;
v_15439:
    stack[-6] = nil;
    v_15631 = stack[-5];
    stack[-1] = v_15631;
v_15461:
    v_15631 = stack[-6];
    if (v_15631 == nil) goto v_15468;
    else goto v_15469;
v_15468:
    v_15631 = stack[-1];
    goto v_15467;
v_15469:
    v_15631 = nil;
    goto v_15467;
    v_15631 = nil;
v_15467:
    if (v_15631 == nil) goto v_15464;
    else goto v_15465;
v_15464:
    goto v_15460;
v_15465:
    goto v_15485;
v_15481:
    v_15631 = stack[-1];
    v_15632 = qcar(v_15631);
    goto v_15482;
v_15483:
    v_15631 = stack[0];
    v_15631 = qcdr(v_15631);
    goto v_15484;
v_15485:
    goto v_15481;
v_15482:
    goto v_15483;
v_15484:
    v_15631 = Lsmemq(nil, v_15632, v_15631);
    env = stack[-7];
    if (v_15631 == nil) goto v_15479;
    v_15631 = lisp_true;
    stack[-6] = v_15631;
    goto v_15477;
v_15479:
    v_15631 = stack[-1];
    v_15631 = qcdr(v_15631);
    stack[-1] = v_15631;
    goto v_15477;
v_15477:
    goto v_15461;
v_15460:
    v_15631 = stack[-6];
    if (v_15631 == nil) goto v_15497;
    else goto v_15498;
v_15497:
    v_15631 = stack[0];
    goto v_15457;
v_15498:
    goto v_15510;
v_15506:
    v_15631 = stack[0];
    v_15632 = qcar(v_15631);
    goto v_15507;
v_15508:
    v_15631 = elt(env, 1); // (plus difference minus times quotient)
    goto v_15509;
v_15510:
    goto v_15506;
v_15507:
    goto v_15508;
v_15509:
    v_15631 = Lmemq(nil, v_15632, v_15631);
    if (v_15631 == nil) goto v_15505;
    else goto v_15503;
v_15505:
    v_15631 = stack[0];
    v_15631 = qcar(v_15631);
    if (!symbolp(v_15631)) v_15631 = nil;
    else { v_15631 = qfastgets(v_15631);
           if (v_15631 != nil) { v_15631 = elt(v_15631, 22); // simpfn
#ifdef RECORD_GET
             if (v_15631 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v_15631 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v_15631 == SPID_NOPROP) v_15631 = nil; }}
#endif
    if (v_15631 == nil) goto v_15503;
    goto v_15504;
v_15503:
    v_15631 = nil;
    stack[-6] = v_15631;
    goto v_15502;
v_15504:
v_15502:
    goto v_15528;
v_15524:
    v_15631 = stack[0];
    v_15632 = qcar(v_15631);
    goto v_15525;
v_15526:
    v_15631 = elt(env, 2); // !*sq
    goto v_15527;
v_15528:
    goto v_15524;
v_15525:
    goto v_15526;
v_15527:
    if (v_15632 == v_15631) goto v_15522;
    else goto v_15523;
v_15522:
    goto v_15537;
v_15533:
    v_15631 = stack[0];
    v_15631 = qcdr(v_15631);
    v_15631 = qcar(v_15631);
    fn = elt(env, 3); // sqhorner!*
    v_15631 = (*qfn1(fn))(fn, v_15631);
    env = stack[-7];
    fn = elt(env, 4); // prepsq!*
    v_15632 = (*qfn1(fn))(fn, v_15631);
    env = stack[-7];
    goto v_15534;
v_15535:
    v_15631 = stack[-5];
    goto v_15536;
v_15537:
    goto v_15533;
v_15534:
    goto v_15535;
v_15536:
    stack[0] = v_15632;
    stack[-5] = v_15631;
    goto v_15432;
v_15523:
    goto v_15551;
v_15547:
    v_15631 = stack[0];
    stack[-4] = qcar(v_15631);
    goto v_15548;
v_15549:
    v_15631 = stack[0];
    v_15631 = qcdr(v_15631);
    stack[-3] = v_15631;
    v_15631 = stack[-3];
    if (v_15631 == nil) goto v_15564;
    else goto v_15565;
v_15564:
    v_15631 = nil;
    goto v_15558;
v_15565:
    v_15631 = stack[-3];
    v_15631 = qcar(v_15631);
    v_15632 = v_15631;
    goto v_15577;
v_15573:
    v_15631 = stack[-6];
    if (v_15631 == nil) goto v_15581;
    v_15631 = v_15632;
    fn = elt(env, 5); // simp!*
    v_15631 = (*qfn1(fn))(fn, v_15631);
    env = stack[-7];
    fn = elt(env, 3); // sqhorner!*
    v_15631 = (*qfn1(fn))(fn, v_15631);
    env = stack[-7];
    fn = elt(env, 4); // prepsq!*
    v_15631 = (*qfn1(fn))(fn, v_15631);
    env = stack[-7];
    v_15632 = v_15631;
    goto v_15579;
v_15581:
    v_15631 = v_15632;
    v_15632 = v_15631;
    goto v_15579;
    v_15632 = nil;
v_15579:
    goto v_15574;
v_15575:
    v_15631 = stack[-5];
    goto v_15576;
v_15577:
    goto v_15573;
v_15574:
    goto v_15575;
v_15576:
    v_15631 = CC_prepreform1(elt(env, 0), v_15632, v_15631);
    env = stack[-7];
    v_15631 = ncons(v_15631);
    env = stack[-7];
    stack[-1] = v_15631;
    stack[-2] = v_15631;
v_15559:
    v_15631 = stack[-3];
    v_15631 = qcdr(v_15631);
    stack[-3] = v_15631;
    v_15631 = stack[-3];
    if (v_15631 == nil) goto v_15595;
    else goto v_15596;
v_15595:
    v_15631 = stack[-2];
    goto v_15558;
v_15596:
    goto v_15604;
v_15600:
    stack[0] = stack[-1];
    goto v_15601;
v_15602:
    v_15631 = stack[-3];
    v_15631 = qcar(v_15631);
    v_15632 = v_15631;
    goto v_15615;
v_15611:
    v_15631 = stack[-6];
    if (v_15631 == nil) goto v_15619;
    v_15631 = v_15632;
    fn = elt(env, 5); // simp!*
    v_15631 = (*qfn1(fn))(fn, v_15631);
    env = stack[-7];
    fn = elt(env, 3); // sqhorner!*
    v_15631 = (*qfn1(fn))(fn, v_15631);
    env = stack[-7];
    fn = elt(env, 4); // prepsq!*
    v_15631 = (*qfn1(fn))(fn, v_15631);
    env = stack[-7];
    v_15632 = v_15631;
    goto v_15617;
v_15619:
    v_15631 = v_15632;
    v_15632 = v_15631;
    goto v_15617;
    v_15632 = nil;
v_15617:
    goto v_15612;
v_15613:
    v_15631 = stack[-5];
    goto v_15614;
v_15615:
    goto v_15611;
v_15612:
    goto v_15613;
v_15614:
    v_15631 = CC_prepreform1(elt(env, 0), v_15632, v_15631);
    env = stack[-7];
    v_15631 = ncons(v_15631);
    env = stack[-7];
    goto v_15603;
v_15604:
    goto v_15600;
v_15601:
    goto v_15602;
v_15603:
    v_15631 = Lrplacd(nil, stack[0], v_15631);
    env = stack[-7];
    v_15631 = stack[-1];
    v_15631 = qcdr(v_15631);
    stack[-1] = v_15631;
    goto v_15559;
v_15558:
    goto v_15550;
v_15551:
    goto v_15547;
v_15548:
    goto v_15549;
v_15550:
    {
        LispObject v_15640 = stack[-4];
        return cons(v_15640, v_15631);
    }
    v_15631 = nil;
v_15457:
    goto v_15437;
    v_15631 = nil;
v_15437:
    return onevalue(v_15631);
}



// Code for talp_try

static LispObject CC_talp_try(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15440;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15433);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15440 = v_15433;
// end of prologue
    fn = elt(env, 1); // rl_pnf
    v_15440 = (*qfn1(fn))(fn, v_15440);
    env = stack[0];
    fn = elt(env, 2); // talp_invtscsimpl
    v_15440 = (*qfn1(fn))(fn, v_15440);
    env = stack[0];
    fn = elt(env, 3); // talp_lssimpl
    v_15440 = (*qfn1(fn))(fn, v_15440);
    env = stack[0];
    {
        fn = elt(env, 4); // talp_try1
        return (*qfn1(fn))(fn, v_15440);
    }
}



// Code for bc_2sq

static LispObject CC_bc_2sq(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15436;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15436 = v_15433;
// end of prologue
    return onevalue(v_15436);
}



// Code for ombindir

static LispObject CC_ombindir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15465;
    LispObject fn;
    argcheck(nargs, 0, "ombindir");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// end of prologue
    fn = elt(env, 2); // lex
    v_15465 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    fn = elt(env, 3); // omobj
    v_15465 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-1] = v_15465;
    fn = elt(env, 2); // lex
    v_15465 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    fn = elt(env, 4); // variablesir
    v_15465 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    fn = elt(env, 5); // tobvarir
    v_15465 = (*qfn1(fn))(fn, v_15465);
    env = stack[-3];
    stack[0] = v_15465;
    fn = elt(env, 2); // lex
    v_15465 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    fn = elt(env, 3); // omobj
    v_15465 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-2] = v_15465;
    fn = elt(env, 2); // lex
    v_15465 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    v_15465 = elt(env, 1); // (!/ o m b i n d)
    fn = elt(env, 6); // checktag
    v_15465 = (*qfn1(fn))(fn, v_15465);
    env = stack[-3];
    goto v_15454;
v_15450:
    goto v_15451;
v_15452:
    goto v_15461;
v_15457:
    goto v_15458;
v_15459:
    v_15465 = stack[-2];
    v_15465 = ncons(v_15465);
    env = stack[-3];
    goto v_15460;
v_15461:
    goto v_15457;
v_15458:
    goto v_15459;
v_15460:
    v_15465 = Lappend(nil, stack[0], v_15465);
    goto v_15453;
v_15454:
    goto v_15450;
v_15451:
    goto v_15452;
v_15453:
    {
        LispObject v_15469 = stack[-1];
        return Lappend(nil, v_15469, v_15465);
    }
    return onevalue(v_15465);
}



// Code for simpdf!*

static LispObject CC_simpdfH(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15459, v_15460, v_15461;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15433);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_15459 = v_15433;
// end of prologue
    fn = elt(env, 1); // simpdf
    v_15459 = (*qfn1(fn))(fn, v_15459);
    env = stack[-1];
    stack[0] = v_15459;
    v_15459 = stack[0];
    fn = elt(env, 2); // rootextractsq
    v_15459 = (*qfn1(fn))(fn, v_15459);
    env = stack[-1];
    v_15461 = v_15459;
    goto v_15451;
v_15447:
    v_15460 = v_15461;
    goto v_15448;
v_15449:
    v_15459 = stack[0];
    goto v_15450;
v_15451:
    goto v_15447;
v_15448:
    goto v_15449;
v_15450:
    if (equal(v_15460, v_15459)) goto v_15446;
    v_15459 = v_15461;
    {
        fn = elt(env, 3); // resimp
        return (*qfn1(fn))(fn, v_15459);
    }
v_15446:
    v_15459 = stack[0];
    goto v_15438;
    v_15459 = nil;
v_15438:
    return onevalue(v_15459);
}



// Code for nextcomb

static LispObject CC_nextcomb(LispObject env,
                         LispObject v_15433, LispObject v_15434)
{
    env = qenv(env);
    LispObject v_15580, v_15581;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15433,v_15434);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15434;
    v_15581 = v_15433;
// end of prologue
// Binding i
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-4, 1, -2);
    qvalue(elt(env, 1)) = nil; // i
    v_15580 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_15580; // i
    v_15580 = v_15581;
    v_15580 = qcar(v_15580);
    stack[-3] = v_15580;
    v_15580 = v_15581;
    v_15580 = qcdr(v_15580);
    stack[-1] = v_15580;
    goto v_15455;
v_15451:
    v_15581 = stack[0];
    goto v_15452;
v_15453:
    v_15580 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15454;
v_15455:
    goto v_15451;
v_15452:
    goto v_15453;
v_15454:
    if (v_15581 == v_15580) goto v_15449;
    else goto v_15450;
v_15449:
    v_15580 = nil;
    v_15580 = ncons(v_15580);
    goto v_15448;
v_15450:
    goto v_15467;
v_15463:
    goto v_15473;
v_15469:
    v_15580 = stack[-3];
    v_15581 = Llength(nil, v_15580);
    env = stack[-4];
    goto v_15470;
v_15471:
    v_15580 = stack[0];
    goto v_15472;
v_15473:
    goto v_15469;
v_15470:
    goto v_15471;
v_15472:
    v_15581 = difference2(v_15581, v_15580);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_15581; // i
    goto v_15464;
v_15465:
    v_15580 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15466;
v_15467:
    goto v_15463;
v_15464:
    goto v_15465;
v_15466:
    v_15580 = (LispObject)lessp2(v_15581, v_15580);
    v_15580 = v_15580 ? lisp_true : nil;
    env = stack[-4];
    if (v_15580 == nil) goto v_15461;
    v_15580 = nil;
    v_15580 = ncons(v_15580);
    goto v_15448;
v_15461:
    goto v_15486;
v_15482:
    v_15581 = qvalue(elt(env, 1)); // i
    goto v_15483;
v_15484:
    v_15580 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15485;
v_15486:
    goto v_15482;
v_15483:
    goto v_15484;
v_15485:
    if (v_15581 == v_15580) goto v_15480;
    else goto v_15481;
v_15480:
    v_15580 = stack[-3];
    v_15580 = ncons(v_15580);
    goto v_15448;
v_15481:
    v_15580 = stack[-1];
    if (v_15580 == nil) goto v_15492;
    goto v_15499;
v_15495:
    goto v_15496;
v_15497:
    v_15580 = stack[0];
    v_15580 = sub1(v_15580);
    env = stack[-4];
    goto v_15498;
v_15499:
    goto v_15495;
v_15496:
    goto v_15497;
v_15498:
    v_15580 = CC_nextcomb(elt(env, 0), stack[-1], v_15580);
    env = stack[-4];
    goto v_15510;
v_15504:
    v_15581 = stack[-3];
    stack[-1] = qcar(v_15581);
    goto v_15505;
v_15506:
    v_15581 = v_15580;
    stack[0] = qcar(v_15581);
    goto v_15507;
v_15508:
    v_15581 = v_15580;
    v_15581 = qcdr(v_15581);
    if (v_15581 == nil) goto v_15518;
    goto v_15526;
v_15522:
    v_15581 = stack[-3];
    goto v_15523;
v_15524:
    v_15580 = qcdr(v_15580);
    goto v_15525;
v_15526:
    goto v_15522;
v_15523:
    goto v_15524;
v_15525:
    v_15580 = cons(v_15581, v_15580);
    env = stack[-4];
    goto v_15516;
v_15518:
    v_15580 = stack[-3];
    v_15580 = qcdr(v_15580);
    v_15580 = ncons(v_15580);
    env = stack[-4];
    goto v_15516;
    v_15580 = nil;
v_15516:
    goto v_15509;
v_15510:
    goto v_15504;
v_15505:
    goto v_15506;
v_15507:
    goto v_15508;
v_15509:
    v_15580 = acons(stack[-1], stack[0], v_15580);
    goto v_15448;
v_15492:
    goto v_15542;
v_15538:
    v_15580 = stack[-3];
    v_15580 = qcdr(v_15580);
    fn = elt(env, 2); // initcomb
    stack[-1] = (*qfn1(fn))(fn, v_15580);
    env = stack[-4];
    goto v_15539;
v_15540:
    v_15580 = stack[0];
    v_15580 = sub1(v_15580);
    env = stack[-4];
    goto v_15541;
v_15542:
    goto v_15538;
v_15539:
    goto v_15540;
v_15541:
    v_15580 = CC_nextcomb(elt(env, 0), stack[-1], v_15580);
    env = stack[-4];
    goto v_15555;
v_15549:
    v_15581 = stack[-3];
    stack[-1] = qcar(v_15581);
    goto v_15550;
v_15551:
    v_15581 = v_15580;
    stack[0] = qcar(v_15581);
    goto v_15552;
v_15553:
    v_15581 = v_15580;
    v_15581 = qcdr(v_15581);
    if (v_15581 == nil) goto v_15563;
    goto v_15571;
v_15567:
    v_15581 = stack[-3];
    goto v_15568;
v_15569:
    v_15580 = qcdr(v_15580);
    goto v_15570;
v_15571:
    goto v_15567;
v_15568:
    goto v_15569;
v_15570:
    v_15580 = cons(v_15581, v_15580);
    env = stack[-4];
    goto v_15561;
v_15563:
    v_15580 = stack[-3];
    v_15580 = qcdr(v_15580);
    v_15580 = ncons(v_15580);
    env = stack[-4];
    goto v_15561;
    v_15580 = nil;
v_15561:
    goto v_15554;
v_15555:
    goto v_15549;
v_15550:
    goto v_15551;
v_15552:
    goto v_15553;
v_15554:
    v_15580 = acons(stack[-1], stack[0], v_15580);
    goto v_15448;
    v_15580 = nil;
v_15448:
    ;}  // end of a binding scope
    return onevalue(v_15580);
}



// Code for dip!-nc!-ev!-prod1

static LispObject CC_dipKncKevKprod1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15469, v_15470, v_15471, v_15472;
    LispObject fn;
    LispObject v_15435, v_15434, v_15433;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dip-nc-ev-prod1");
    va_start(aa, nargs);
    v_15433 = va_arg(aa, LispObject);
    v_15434 = va_arg(aa, LispObject);
    v_15435 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15435,v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15433,v_15434,v_15435);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_15470 = v_15435;
    v_15471 = v_15434;
    v_15472 = v_15433;
// end of prologue
    v_15469 = v_15472;
    if (v_15469 == nil) goto v_15439;
    else goto v_15440;
v_15439:
    v_15469 = v_15470;
    goto v_15438;
v_15440:
    goto v_15452;
v_15446:
    v_15469 = v_15472;
    stack[-1] = qcar(v_15469);
    goto v_15447;
v_15448:
    stack[0] = v_15471;
    goto v_15449;
v_15450:
    goto v_15463;
v_15457:
    v_15469 = v_15472;
    v_15469 = qcdr(v_15469);
    goto v_15458;
v_15459:
    v_15471 = (LispObject)((intptr_t)(v_15471) + 0x10);
    goto v_15460;
v_15461:
    goto v_15462;
v_15463:
    goto v_15457;
v_15458:
    goto v_15459;
v_15460:
    goto v_15461;
v_15462:
    v_15469 = CC_dipKncKevKprod1(elt(env, 0), 3, v_15469, v_15471, v_15470);
    env = stack[-2];
    goto v_15451;
v_15452:
    goto v_15446;
v_15447:
    goto v_15448;
v_15449:
    goto v_15450;
v_15451:
    {
        LispObject v_15475 = stack[-1];
        LispObject v_15476 = stack[0];
        fn = elt(env, 1); // dip!-nc!-ev!-prod2
        return (*qfnn(fn))(fn, 3, v_15475, v_15476, v_15469);
    }
    v_15469 = nil;
v_15438:
    return onevalue(v_15469);
}



// Code for pterpri

static LispObject CC_pterpri(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15498, v_15499, v_15500;
    LispObject fn;
    argcheck(nargs, 0, "pterpri");
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
    v_15498 = nil;
    v_15498 = Lwrs(nil, v_15498);
    env = stack[-4];
    stack[-3] = v_15498;
    v_15498 = qvalue(elt(env, 1)); // !*pprinbuf!*
    v_15498 = Lnreverse(nil, v_15498);
    env = stack[-4];
    stack[-2] = v_15498;
    v_15498 = qvalue(elt(env, 2)); // !*outchanl!*
    stack[-1] = v_15498;
v_15445:
    v_15498 = stack[-1];
    if (v_15498 == nil) goto v_15449;
    else goto v_15450;
v_15449:
    goto v_15444;
v_15450:
    v_15498 = stack[-1];
    v_15498 = qcar(v_15498);
    v_15498 = Lwrs(nil, v_15498);
    env = stack[-4];
    v_15498 = stack[-2];
    stack[0] = v_15498;
v_15461:
    v_15498 = stack[0];
    if (v_15498 == nil) goto v_15465;
    else goto v_15466;
v_15465:
    goto v_15460;
v_15466:
    v_15498 = stack[0];
    v_15498 = qcar(v_15498);
    v_15500 = v_15498;
    goto v_15480;
v_15476:
    v_15499 = qvalue(elt(env, 3)); // gentranlang!*
    goto v_15477;
v_15478:
    v_15498 = elt(env, 4); // fortran
    goto v_15479;
v_15480:
    goto v_15476;
v_15477:
    goto v_15478;
v_15479:
    if (v_15499 == v_15498) goto v_15474;
    else goto v_15475;
v_15474:
    v_15498 = v_15500;
    fn = elt(env, 6); // fprin2
    v_15498 = (*qfn1(fn))(fn, v_15498);
    env = stack[-4];
    goto v_15473;
v_15475:
    v_15498 = v_15500;
    v_15498 = Lprinc(nil, v_15498);
    env = stack[-4];
    goto v_15473;
v_15473:
    v_15498 = stack[0];
    v_15498 = qcdr(v_15498);
    stack[0] = v_15498;
    goto v_15461;
v_15460:
    v_15498 = Lterpri(nil, 0);
    env = stack[-4];
    v_15498 = stack[-1];
    v_15498 = qcdr(v_15498);
    stack[-1] = v_15498;
    goto v_15445;
v_15444:
    v_15498 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 5)) = v_15498; // !*posn!*
    v_15498 = nil;
    qvalue(elt(env, 1)) = v_15498; // !*pprinbuf!*
    v_15498 = stack[-3];
    v_15498 = Lwrs(nil, v_15498);
    v_15498 = nil;
    return onevalue(v_15498);
}



// Code for getphystypeor

static LispObject CC_getphystypeor(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15452;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15433);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15433;
// end of prologue
v_15432:
    v_15452 = stack[0];
    if (!consp(v_15452)) goto v_15438;
    v_15452 = stack[0];
    v_15452 = qcar(v_15452);
    fn = elt(env, 1); // getphystype
    v_15452 = (*qfn1(fn))(fn, v_15452);
    env = stack[-1];
    if (v_15452 == nil) goto v_15442;
    else goto v_15441;
v_15442:
    v_15452 = stack[0];
    v_15452 = qcdr(v_15452);
    stack[0] = v_15452;
    goto v_15432;
v_15441:
    goto v_15436;
v_15438:
    v_15452 = nil;
    goto v_15436;
    v_15452 = nil;
v_15436:
    return onevalue(v_15452);
}



// Code for prop!-simp

static LispObject CC_propKsimp(LispObject env,
                         LispObject v_15433, LispObject v_15434)
{
    env = qenv(env);
    LispObject v_15453, v_15454, v_15455, v_15456, v_15457;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15453 = v_15434;
    v_15454 = v_15433;
// end of prologue
    goto v_15447;
v_15437:
    v_15457 = v_15454;
    goto v_15438;
v_15439:
    v_15456 = v_15453;
    goto v_15440;
v_15441:
    v_15455 = nil;
    goto v_15442;
v_15443:
    v_15454 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15444;
v_15445:
    v_15453 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15446;
v_15447:
    goto v_15437;
v_15438:
    goto v_15439;
v_15440:
    goto v_15441;
v_15442:
    goto v_15443;
v_15444:
    goto v_15445;
v_15446:
    {
        fn = elt(env, 1); // prop!-simp1
        return (*qfnn(fn))(fn, 5, v_15457, v_15456, v_15455, v_15454, v_15453);
    }
}



// Code for nzero

static LispObject CC_nzero(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15464, v_15465;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15433);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15433;
// end of prologue
    stack[-1] = nil;
v_15438:
    goto v_15447;
v_15443:
    v_15465 = stack[0];
    goto v_15444;
v_15445:
    v_15464 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15446;
v_15447:
    goto v_15443;
v_15444:
    goto v_15445;
v_15446:
    if (v_15465 == v_15464) goto v_15441;
    else goto v_15442;
v_15441:
    v_15464 = stack[-1];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_15464);
    }
v_15442:
    goto v_15459;
v_15455:
    v_15465 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15456;
v_15457:
    v_15464 = stack[-1];
    goto v_15458;
v_15459:
    goto v_15455;
v_15456:
    goto v_15457;
v_15458:
    v_15464 = cons(v_15465, v_15464);
    env = stack[-2];
    stack[-1] = v_15464;
    v_15464 = stack[0];
    v_15464 = sub1(v_15464);
    env = stack[-2];
    stack[0] = v_15464;
    goto v_15438;
    v_15464 = nil;
    return onevalue(v_15464);
}



// Code for general!-evaluate!-mod!-p

static LispObject CC_generalKevaluateKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15556, v_15557, v_15558, v_15559, v_15560;
    LispObject fn;
    LispObject v_15435, v_15434, v_15433;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "general-evaluate-mod-p");
    va_start(aa, nargs);
    v_15433 = va_arg(aa, LispObject);
    v_15434 = va_arg(aa, LispObject);
    v_15435 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15435,v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15433,v_15434,v_15435);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15435;
    stack[-1] = v_15434;
    stack[-2] = v_15433;
// end of prologue
v_15439:
    v_15556 = stack[-2];
    if (!consp(v_15556)) goto v_15446;
    else goto v_15447;
v_15446:
    v_15556 = lisp_true;
    goto v_15445;
v_15447:
    v_15556 = stack[-2];
    v_15556 = qcar(v_15556);
    v_15556 = (consp(v_15556) ? nil : lisp_true);
    goto v_15445;
    v_15556 = nil;
v_15445:
    if (v_15556 == nil) goto v_15443;
    v_15556 = stack[-2];
    goto v_15438;
v_15443:
    goto v_15462;
v_15458:
    v_15557 = stack[0];
    goto v_15459;
v_15460:
    v_15556 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15461;
v_15462:
    goto v_15458;
v_15459:
    goto v_15460;
v_15461:
    if (v_15557 == v_15556) goto v_15456;
    else goto v_15457;
v_15456:
    v_15556 = nil;
    stack[0] = v_15556;
    goto v_15439;
v_15457:
    v_15556 = stack[-1];
    if (v_15556 == nil) goto v_15466;
    else goto v_15467;
v_15466:
    v_15556 = elt(env, 1); // "Variable=NIL in GENERAL-EVALUATE-MOD-P"
    {
        fn = elt(env, 2); // errorf
        return (*qfn1(fn))(fn, v_15556);
    }
v_15467:
    goto v_15477;
v_15473:
    v_15556 = stack[-2];
    v_15556 = qcar(v_15556);
    v_15556 = qcar(v_15556);
    v_15557 = qcar(v_15556);
    goto v_15474;
v_15475:
    v_15556 = stack[-1];
    goto v_15476;
v_15477:
    goto v_15473;
v_15474:
    goto v_15475;
v_15476:
    if (equal(v_15557, v_15556)) goto v_15471;
    else goto v_15472;
v_15471:
    goto v_15494;
v_15484:
    v_15556 = stack[-2];
    v_15556 = qcar(v_15556);
    v_15560 = qcdr(v_15556);
    goto v_15485;
v_15486:
    v_15556 = stack[-2];
    v_15556 = qcar(v_15556);
    v_15556 = qcar(v_15556);
    v_15559 = qcdr(v_15556);
    goto v_15487;
v_15488:
    v_15556 = stack[-2];
    v_15558 = qcdr(v_15556);
    goto v_15489;
v_15490:
    v_15557 = stack[0];
    goto v_15491;
v_15492:
    v_15556 = stack[-1];
    goto v_15493;
v_15494:
    goto v_15484;
v_15485:
    goto v_15486;
v_15487:
    goto v_15488;
v_15489:
    goto v_15490;
v_15491:
    goto v_15492;
v_15493:
    {
        fn = elt(env, 3); // general!-horner!-rule!-mod!-p
        return (*qfnn(fn))(fn, 5, v_15560, v_15559, v_15558, v_15557, v_15556);
    }
v_15472:
    goto v_15515;
v_15509:
    v_15556 = stack[-2];
    v_15556 = qcar(v_15556);
    v_15558 = qcdr(v_15556);
    goto v_15510;
v_15511:
    v_15557 = stack[-1];
    goto v_15512;
v_15513:
    v_15556 = stack[0];
    goto v_15514;
v_15515:
    goto v_15509;
v_15510:
    goto v_15511;
v_15512:
    goto v_15513;
v_15514:
    stack[-3] = CC_generalKevaluateKmodKp(elt(env, 0), 3, v_15558, v_15557, v_15556);
    env = stack[-4];
    goto v_15528;
v_15522:
    v_15556 = stack[-2];
    v_15558 = qcdr(v_15556);
    goto v_15523;
v_15524:
    v_15557 = stack[-1];
    goto v_15525;
v_15526:
    v_15556 = stack[0];
    goto v_15527;
v_15528:
    goto v_15522;
v_15523:
    goto v_15524;
v_15525:
    goto v_15526;
v_15527:
    v_15556 = CC_generalKevaluateKmodKp(elt(env, 0), 3, v_15558, v_15557, v_15556);
    v_15557 = stack[-3];
    v_15558 = v_15557;
    if (v_15558 == nil) goto v_15537;
    else goto v_15538;
v_15537:
    goto v_15536;
v_15538:
    goto v_15550;
v_15544:
    v_15558 = stack[-2];
    v_15558 = qcar(v_15558);
    v_15558 = qcar(v_15558);
    goto v_15545;
v_15546:
    goto v_15547;
v_15548:
    goto v_15549;
v_15550:
    goto v_15544;
v_15545:
    goto v_15546;
v_15547:
    goto v_15548;
v_15549:
    return acons(v_15558, v_15557, v_15556);
    v_15556 = nil;
v_15536:
    goto v_15438;
    v_15556 = nil;
v_15438:
    return onevalue(v_15556);
}



// Code for lalr_generate_collection

static LispObject CC_lalr_generate_collection(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15516, v_15517;
    LispObject fn;
    argcheck(nargs, 0, "lalr_generate_collection");
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
    v_15516 = qvalue(elt(env, 1)); // itemset_collection
    stack[-1] = v_15516;
v_15441:
    v_15516 = stack[-1];
    if (v_15516 == nil) goto v_15445;
    else goto v_15446;
v_15445:
    goto v_15440;
v_15446:
    v_15516 = stack[-1];
    v_15516 = qcar(v_15516);
    goto v_15457;
v_15453:
    stack[0] = v_15516;
    goto v_15454;
v_15455:
    v_15516 = qcar(v_15516);
    fn = elt(env, 3); // lalr_lr0_itemset_to_lalr_kernel
    v_15516 = (*qfn1(fn))(fn, v_15516);
    env = stack[-2];
    goto v_15456;
v_15457:
    goto v_15453;
v_15454:
    goto v_15455;
v_15456:
    v_15516 = Lrplaca(nil, stack[0], v_15516);
    env = stack[-2];
    v_15516 = stack[-1];
    v_15516 = qcdr(v_15516);
    stack[-1] = v_15516;
    goto v_15441;
v_15440:
    fn = elt(env, 4); // lalr_analyze_lookaheads
    v_15516 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[0] = v_15516;
    goto v_15470;
v_15466:
    v_15517 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15467;
v_15468:
    v_15516 = qvalue(elt(env, 1)); // itemset_collection
    goto v_15469;
v_15470:
    goto v_15466;
v_15467:
    goto v_15468;
v_15469:
    fn = elt(env, 5); // carrassoc
    v_15516 = (*qfn2(fn))(fn, v_15517, v_15516);
    env = stack[-2];
    goto v_15478;
v_15474:
    v_15517 = qcar(v_15516);
    goto v_15475;
v_15476:
    v_15516 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15477;
v_15478:
    goto v_15474;
v_15475:
    goto v_15476;
v_15477:
    fn = elt(env, 6); // lalr_add_lookahead
    v_15516 = (*qfn2(fn))(fn, v_15517, v_15516);
    env = stack[-2];
    v_15516 = stack[0];
    fn = elt(env, 7); // lalr_propagate_lookaheads
    v_15516 = (*qfn1(fn))(fn, v_15516);
    env = stack[-2];
    v_15516 = qvalue(elt(env, 1)); // itemset_collection
    stack[-1] = v_15516;
v_15487:
    v_15516 = stack[-1];
    if (v_15516 == nil) goto v_15491;
    else goto v_15492;
v_15491:
    goto v_15486;
v_15492:
    v_15516 = stack[-1];
    v_15516 = qcar(v_15516);
    goto v_15503;
v_15499:
    stack[0] = v_15516;
    goto v_15500;
v_15501:
    v_15516 = qcar(v_15516);
    fn = elt(env, 8); // lalr_closure
    v_15516 = (*qfn1(fn))(fn, v_15516);
    env = stack[-2];
    goto v_15502;
v_15503:
    goto v_15499;
v_15500:
    goto v_15501;
v_15502:
    v_15516 = Lrplaca(nil, stack[0], v_15516);
    env = stack[-2];
    v_15516 = stack[-1];
    v_15516 = qcdr(v_15516);
    stack[-1] = v_15516;
    goto v_15487;
v_15486:
    v_15516 = qvalue(elt(env, 2)); // !*lalr_verbose
    if (v_15516 == nil) goto v_15513;
    fn = elt(env, 9); // lalr_print_collection
    v_15516 = (*qfnn(fn))(fn, 0);
    goto v_15511;
v_15513:
v_15511:
    v_15516 = nil;
    return onevalue(v_15516);
}



// Code for comm1

static LispObject CC_comm1(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15519, v_15520;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15433);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15433;
// end of prologue
    stack[-1] = nil;
    goto v_15446;
v_15442:
    v_15520 = stack[0];
    goto v_15443;
v_15444:
    v_15519 = elt(env, 1); // end
    goto v_15445;
v_15446:
    goto v_15442;
v_15443:
    goto v_15444;
v_15445:
    if (v_15520 == v_15519) goto v_15440;
    else goto v_15441;
v_15440:
    fn = elt(env, 6); // scan
    v_15519 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_15439;
v_15441:
v_15439:
v_15452:
    goto v_15465;
v_15461:
    v_15520 = qvalue(elt(env, 2)); // cursym!*
    goto v_15462;
v_15463:
    v_15519 = elt(env, 3); // !*semicol!*
    goto v_15464;
v_15465:
    goto v_15461;
v_15462:
    goto v_15463;
v_15464:
    if (v_15520 == v_15519) goto v_15459;
    else goto v_15460;
v_15459:
    v_15519 = lisp_true;
    goto v_15458;
v_15460:
    goto v_15479;
v_15475:
    v_15520 = stack[0];
    goto v_15476;
v_15477:
    v_15519 = elt(env, 1); // end
    goto v_15478;
v_15479:
    goto v_15475;
v_15476:
    goto v_15477;
v_15478:
    if (v_15520 == v_15519) goto v_15473;
    else goto v_15474;
v_15473:
    goto v_15486;
v_15482:
    v_15520 = qvalue(elt(env, 2)); // cursym!*
    goto v_15483;
v_15484:
    v_15519 = elt(env, 4); // (end else then until !*rpar!* !*rsqbkt!*)
    goto v_15485;
v_15486:
    goto v_15482;
v_15483:
    goto v_15484;
v_15485:
    v_15519 = Lmemq(nil, v_15520, v_15519);
    goto v_15472;
v_15474:
    v_15519 = nil;
    goto v_15472;
    v_15519 = nil;
v_15472:
    goto v_15458;
    v_15519 = nil;
v_15458:
    if (v_15519 == nil) goto v_15456;
    goto v_15451;
v_15456:
    goto v_15506;
v_15502:
    v_15520 = stack[0];
    goto v_15503;
v_15504:
    v_15519 = elt(env, 1); // end
    goto v_15505;
v_15506:
    goto v_15502;
v_15503:
    goto v_15504;
v_15505:
    if (v_15520 == v_15519) goto v_15500;
    else goto v_15501;
v_15500:
    v_15519 = stack[-1];
    v_15519 = (v_15519 == nil ? lisp_true : nil);
    goto v_15499;
v_15501:
    v_15519 = nil;
    goto v_15499;
    v_15519 = nil;
v_15499:
    if (v_15519 == nil) goto v_15497;
    v_15519 = elt(env, 5); // "END-COMMENT NO LONGER SUPPORTED"
    v_15519 = ncons(v_15519);
    env = stack[-2];
    fn = elt(env, 7); // lprim
    v_15519 = (*qfn1(fn))(fn, v_15519);
    env = stack[-2];
    v_15519 = lisp_true;
    stack[-1] = v_15519;
    goto v_15495;
v_15497:
v_15495:
    fn = elt(env, 6); // scan
    v_15519 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_15452;
v_15451:
    v_15519 = nil;
    return onevalue(v_15519);
}



// Code for normalform

static LispObject CC_normalform(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15550, v_15551, v_15552;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15433);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_15433;
// end of prologue
    v_15550 = nil;
    v_15550 = ncons(v_15550);
    env = stack[-3];
    stack[-2] = v_15550;
    v_15550 = stack[-1];
    v_15550 = qcar(v_15550);
    if (v_15550 == nil) goto v_15443;
    else goto v_15444;
v_15443:
    v_15550 = stack[-2];
    goto v_15438;
v_15444:
    v_15550 = qvalue(elt(env, 1)); // fluidbibasisnormalforms
    v_15550 = (LispObject)((intptr_t)(v_15550) + 0x10);
    qvalue(elt(env, 1)) = v_15550; // fluidbibasisnormalforms
v_15453:
    v_15550 = stack[-1];
    v_15550 = qcar(v_15550);
    if (v_15550 == nil) goto v_15456;
    else goto v_15457;
v_15456:
    goto v_15452;
v_15457:
    v_15550 = stack[-1];
    v_15550 = qcar(v_15550);
    fn = elt(env, 2); // janettreefind
    v_15550 = (*qfn1(fn))(fn, v_15550);
    env = stack[-3];
v_15466:
    v_15551 = v_15550;
    if (v_15551 == nil) goto v_15469;
    else goto v_15470;
v_15469:
    goto v_15465;
v_15470:
    goto v_15478;
v_15474:
    v_15552 = stack[-1];
    goto v_15475;
v_15476:
    goto v_15484;
v_15480:
    v_15551 = v_15550;
    goto v_15481;
v_15482:
    v_15550 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15483;
v_15484:
    goto v_15480;
v_15481:
    goto v_15482;
v_15483:
    v_15550 = *(LispObject *)((char *)v_15551 + (CELL-TAG_VECTOR) + (((intptr_t)v_15550-TAG_FIXNUM)/(16/CELL)));
    goto v_15477;
v_15478:
    goto v_15474;
v_15475:
    goto v_15476;
v_15477:
    fn = elt(env, 3); // polynomheadreduceby
    v_15550 = (*qfn2(fn))(fn, v_15552, v_15550);
    env = stack[-3];
    v_15550 = stack[-1];
    v_15550 = qcar(v_15550);
    if (v_15550 == nil) goto v_15491;
    v_15550 = stack[-1];
    v_15550 = qcar(v_15550);
    fn = elt(env, 2); // janettreefind
    v_15550 = (*qfn1(fn))(fn, v_15550);
    env = stack[-3];
    goto v_15489;
v_15491:
    v_15550 = nil;
    goto v_15489;
v_15489:
    goto v_15466;
v_15465:
    v_15550 = stack[-1];
    v_15550 = qcar(v_15550);
    if (v_15550 == nil) goto v_15506;
    goto v_15514;
v_15510:
    stack[0] = stack[-2];
    goto v_15511;
v_15512:
    goto v_15523;
v_15517:
    v_15550 = stack[-1];
    v_15552 = qcar(v_15550);
    goto v_15518;
v_15519:
    v_15551 = nil;
    goto v_15520;
v_15521:
    v_15550 = nil;
    goto v_15522;
v_15523:
    goto v_15517;
v_15518:
    goto v_15519;
v_15520:
    goto v_15521;
v_15522:
    v_15550 = list2star(v_15552, v_15551, v_15550);
    env = stack[-3];
    goto v_15513;
v_15514:
    goto v_15510;
v_15511:
    goto v_15512;
v_15513:
    fn = elt(env, 4); // polynomadd
    v_15550 = (*qfn2(fn))(fn, stack[0], v_15550);
    env = stack[-3];
    goto v_15533;
v_15529:
    goto v_15539;
v_15535:
    v_15551 = stack[-1];
    goto v_15536;
v_15537:
    v_15550 = stack[-1];
    v_15550 = qcdr(v_15550);
    v_15550 = qcar(v_15550);
    goto v_15538;
v_15539:
    goto v_15535;
v_15536:
    goto v_15537;
v_15538:
    v_15551 = Lrplaca(nil, v_15551, v_15550);
    env = stack[-3];
    goto v_15530;
v_15531:
    v_15550 = stack[-1];
    v_15550 = qcdr(v_15550);
    v_15550 = qcdr(v_15550);
    goto v_15532;
v_15533:
    goto v_15529;
v_15530:
    goto v_15531;
v_15532:
    v_15550 = Lrplacd(nil, v_15551, v_15550);
    env = stack[-3];
    goto v_15504;
v_15506:
v_15504:
    goto v_15453;
v_15452:
    v_15550 = stack[-2];
v_15438:
    return onevalue(v_15550);
}



// Code for co_new

static LispObject CC_co_new(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15436;
    argcheck(nargs, 0, "co_new");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_15436 = nil;
    return ncons(v_15436);
}



// Code for wureducedp

static LispObject CC_wureducedp(LispObject env,
                         LispObject v_15433, LispObject v_15434)
{
    env = qenv(env);
    LispObject v_15476, v_15477;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15433,v_15434);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15434;
    stack[-1] = v_15433;
// end of prologue
    v_15476 = stack[0];
    fn = elt(env, 1); // wuconstantp
    v_15476 = (*qfn1(fn))(fn, v_15476);
    env = stack[-2];
    if (v_15476 == nil) goto v_15438;
    else goto v_15437;
v_15438:
    v_15476 = stack[-1];
    fn = elt(env, 1); // wuconstantp
    v_15476 = (*qfn1(fn))(fn, v_15476);
    env = stack[-2];
    if (v_15476 == nil) goto v_15443;
    else goto v_15442;
v_15443:
    goto v_15451;
v_15447:
    goto v_15457;
v_15453:
    goto v_15454;
v_15455:
    v_15476 = stack[0];
    fn = elt(env, 1); // wuconstantp
    v_15476 = (*qfn1(fn))(fn, v_15476);
    env = stack[-2];
    if (v_15476 == nil) goto v_15462;
    v_15476 = nil;
    goto v_15460;
v_15462:
    v_15476 = stack[0];
    v_15476 = qcar(v_15476);
    v_15476 = qcar(v_15476);
    v_15476 = qcar(v_15476);
    goto v_15460;
    v_15476 = nil;
v_15460:
    goto v_15456;
v_15457:
    goto v_15453;
v_15454:
    goto v_15455;
v_15456:
    fn = elt(env, 2); // deginvar
    v_15477 = (*qfn2(fn))(fn, stack[-1], v_15476);
    goto v_15448;
v_15449:
    v_15476 = stack[0];
    v_15476 = qcar(v_15476);
    v_15476 = qcar(v_15476);
    v_15476 = qcdr(v_15476);
    goto v_15450;
v_15451:
    goto v_15447;
v_15448:
    goto v_15449;
v_15450:
        return Llessp(nil, v_15477, v_15476);
v_15442:
v_15437:
    return onevalue(v_15476);
}



// Code for get!-denom!-ll

static LispObject CC_getKdenomKll(LispObject env,
                         LispObject v_15433, LispObject v_15434)
{
    env = qenv(env);
    LispObject v_15471, v_15472;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15433,v_15434);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_15434;
    stack[-2] = v_15433;
// end of prologue
    stack[-3] = nil;
v_15439:
    v_15471 = stack[-2];
    if (v_15471 == nil) goto v_15442;
    else goto v_15443;
v_15442:
    v_15471 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_15471);
    }
v_15443:
    goto v_15454;
v_15450:
    goto v_15460;
v_15456:
    v_15471 = stack[-2];
    stack[0] = qcar(v_15471);
    goto v_15457;
v_15458:
    v_15471 = stack[-1];
    v_15471 = qcar(v_15471);
    fn = elt(env, 2); // get!-denom!-l
    v_15471 = (*qfn1(fn))(fn, v_15471);
    env = stack[-4];
    goto v_15459;
v_15460:
    goto v_15456;
v_15457:
    goto v_15458;
v_15459:
    fn = elt(env, 3); // lcmn
    v_15472 = (*qfn2(fn))(fn, stack[0], v_15471);
    env = stack[-4];
    goto v_15451;
v_15452:
    v_15471 = stack[-3];
    goto v_15453;
v_15454:
    goto v_15450;
v_15451:
    goto v_15452;
v_15453:
    v_15471 = cons(v_15472, v_15471);
    env = stack[-4];
    stack[-3] = v_15471;
    v_15471 = stack[-2];
    v_15471 = qcdr(v_15471);
    stack[-2] = v_15471;
    v_15471 = stack[-1];
    v_15471 = qcdr(v_15471);
    stack[-1] = v_15471;
    goto v_15439;
    v_15471 = nil;
    return onevalue(v_15471);
}



// Code for pasf_varlat

static LispObject CC_pasf_varlat(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15534, v_15535;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15433);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15433;
// end of prologue
    goto v_15443;
v_15439:
    v_15534 = stack[0];
    v_15534 = qcdr(v_15534);
    v_15534 = qcar(v_15534);
    fn = elt(env, 3); // kernels
    stack[-1] = (*qfn1(fn))(fn, v_15534);
    env = stack[-4];
    goto v_15440;
v_15441:
    v_15534 = stack[0];
    v_15534 = Lconsp(nil, v_15534);
    env = stack[-4];
    if (v_15534 == nil) goto v_15451;
    v_15534 = stack[0];
    v_15534 = qcar(v_15534);
    v_15534 = Lconsp(nil, v_15534);
    env = stack[-4];
    if (v_15534 == nil) goto v_15451;
    goto v_15465;
v_15461:
    v_15534 = stack[0];
    v_15534 = qcar(v_15534);
    v_15535 = qcar(v_15534);
    goto v_15462;
v_15463:
    v_15534 = elt(env, 1); // (cong ncong)
    goto v_15464;
v_15465:
    goto v_15461;
v_15462:
    goto v_15463;
v_15464:
    v_15534 = Lmemq(nil, v_15535, v_15534);
    if (v_15534 == nil) goto v_15451;
    v_15534 = stack[0];
    v_15534 = qcar(v_15534);
    v_15534 = qcdr(v_15534);
    fn = elt(env, 3); // kernels
    v_15534 = (*qfn1(fn))(fn, v_15534);
    env = stack[-4];
    goto v_15449;
v_15451:
    v_15534 = nil;
    goto v_15449;
    v_15534 = nil;
v_15449:
    goto v_15442;
v_15443:
    goto v_15439;
v_15440:
    goto v_15441;
v_15442:
    v_15534 = Lappend(nil, stack[-1], v_15534);
    env = stack[-4];
    v_15535 = v_15534;
    v_15534 = qvalue(elt(env, 2)); // !*rlbrkcxk
    if (v_15534 == nil) goto v_15481;
    v_15534 = v_15535;
    stack[-3] = v_15534;
v_15488:
    v_15534 = stack[-3];
    if (v_15534 == nil) goto v_15493;
    else goto v_15494;
v_15493:
    v_15534 = nil;
    goto v_15487;
v_15494:
    v_15534 = stack[-3];
    v_15534 = qcar(v_15534);
    fn = elt(env, 4); // lto_lpvarl
    v_15534 = (*qfn1(fn))(fn, v_15534);
    env = stack[-4];
    stack[-2] = v_15534;
    v_15534 = stack[-2];
    fn = elt(env, 5); // lastpair
    v_15534 = (*qfn1(fn))(fn, v_15534);
    env = stack[-4];
    stack[-1] = v_15534;
    v_15534 = stack[-3];
    v_15534 = qcdr(v_15534);
    stack[-3] = v_15534;
    v_15534 = stack[-1];
    if (!consp(v_15534)) goto v_15508;
    else goto v_15509;
v_15508:
    goto v_15488;
v_15509:
v_15489:
    v_15534 = stack[-3];
    if (v_15534 == nil) goto v_15513;
    else goto v_15514;
v_15513:
    v_15534 = stack[-2];
    goto v_15487;
v_15514:
    goto v_15522;
v_15518:
    stack[0] = stack[-1];
    goto v_15519;
v_15520:
    v_15534 = stack[-3];
    v_15534 = qcar(v_15534);
    fn = elt(env, 4); // lto_lpvarl
    v_15534 = (*qfn1(fn))(fn, v_15534);
    env = stack[-4];
    goto v_15521;
v_15522:
    goto v_15518;
v_15519:
    goto v_15520;
v_15521:
    v_15534 = Lrplacd(nil, stack[0], v_15534);
    env = stack[-4];
    v_15534 = stack[-1];
    fn = elt(env, 5); // lastpair
    v_15534 = (*qfn1(fn))(fn, v_15534);
    env = stack[-4];
    stack[-1] = v_15534;
    v_15534 = stack[-3];
    v_15534 = qcdr(v_15534);
    stack[-3] = v_15534;
    goto v_15489;
v_15487:
    v_15535 = v_15534;
    goto v_15479;
v_15481:
v_15479:
    v_15534 = v_15535;
    return onevalue(v_15534);
}



// Code for vunion

static LispObject CC_vunion(LispObject env,
                         LispObject v_15433, LispObject v_15434)
{
    env = qenv(env);
    LispObject v_15536, v_15537;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15433,v_15434);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_15434;
    stack[-2] = v_15433;
// end of prologue
    v_15536 = stack[-2];
    if (v_15536 == nil) goto v_15441;
    else goto v_15442;
v_15441:
    v_15536 = stack[-1];
    goto v_15440;
v_15442:
    goto v_15451;
v_15447:
    v_15536 = stack[-2];
    v_15536 = qcar(v_15536);
    v_15537 = qcar(v_15536);
    goto v_15448;
v_15449:
    v_15536 = stack[-1];
    goto v_15450;
v_15451:
    goto v_15447;
v_15448:
    goto v_15449;
v_15450:
    v_15536 = Lassoc(nil, v_15537, v_15536);
    stack[-3] = v_15536;
    if (v_15536 == nil) goto v_15445;
    else goto v_15446;
v_15445:
    goto v_15462;
v_15458:
    v_15536 = stack[-2];
    stack[0] = qcar(v_15536);
    goto v_15459;
v_15460:
    goto v_15470;
v_15466:
    v_15536 = stack[-2];
    v_15537 = qcdr(v_15536);
    goto v_15467;
v_15468:
    v_15536 = stack[-1];
    goto v_15469;
v_15470:
    goto v_15466;
v_15467:
    goto v_15468;
v_15469:
    v_15536 = CC_vunion(elt(env, 0), v_15537, v_15536);
    goto v_15461;
v_15462:
    goto v_15458;
v_15459:
    goto v_15460;
v_15461:
    {
        LispObject v_15542 = stack[0];
        return cons(v_15542, v_15536);
    }
v_15446:
    goto v_15481;
v_15477:
    v_15536 = stack[-2];
    v_15536 = qcar(v_15536);
    v_15537 = qcdr(v_15536);
    goto v_15478;
v_15479:
    v_15536 = stack[-3];
    v_15536 = qcdr(v_15536);
    goto v_15480;
v_15481:
    goto v_15477;
v_15478:
    goto v_15479;
v_15480:
    v_15536 = (LispObject)greaterp2(v_15537, v_15536);
    v_15536 = v_15536 ? lisp_true : nil;
    env = stack[-4];
    if (v_15536 == nil) goto v_15475;
    goto v_15492;
v_15488:
    v_15536 = stack[-2];
    stack[0] = qcar(v_15536);
    goto v_15489;
v_15490:
    goto v_15500;
v_15496:
    v_15536 = stack[-2];
    stack[-2] = qcdr(v_15536);
    goto v_15497;
v_15498:
    goto v_15508;
v_15504:
    v_15537 = stack[-3];
    goto v_15505;
v_15506:
    v_15536 = stack[-1];
    goto v_15507;
v_15508:
    goto v_15504;
v_15505:
    goto v_15506;
v_15507:
    v_15536 = Ldelete(nil, v_15537, v_15536);
    env = stack[-4];
    goto v_15499;
v_15500:
    goto v_15496;
v_15497:
    goto v_15498;
v_15499:
    v_15536 = CC_vunion(elt(env, 0), stack[-2], v_15536);
    goto v_15491;
v_15492:
    goto v_15488;
v_15489:
    goto v_15490;
v_15491:
    {
        LispObject v_15543 = stack[0];
        return cons(v_15543, v_15536);
    }
v_15475:
    goto v_15518;
v_15514:
    stack[0] = stack[-3];
    goto v_15515;
v_15516:
    goto v_15525;
v_15521:
    v_15536 = stack[-2];
    stack[-2] = qcdr(v_15536);
    goto v_15522;
v_15523:
    goto v_15533;
v_15529:
    v_15537 = stack[-3];
    goto v_15530;
v_15531:
    v_15536 = stack[-1];
    goto v_15532;
v_15533:
    goto v_15529;
v_15530:
    goto v_15531;
v_15532:
    v_15536 = Ldelete(nil, v_15537, v_15536);
    env = stack[-4];
    goto v_15524;
v_15525:
    goto v_15521;
v_15522:
    goto v_15523;
v_15524:
    v_15536 = CC_vunion(elt(env, 0), stack[-2], v_15536);
    goto v_15517;
v_15518:
    goto v_15514;
v_15515:
    goto v_15516;
v_15517:
    {
        LispObject v_15544 = stack[0];
        return cons(v_15544, v_15536);
    }
    v_15536 = nil;
v_15440:
    return onevalue(v_15536);
}



// Code for aex_mvar

static LispObject CC_aex_mvar(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15444;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15433);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15444 = v_15433;
// end of prologue
    goto v_15438;
    goto v_15436;
v_15438:
v_15436:
    fn = elt(env, 1); // aex_ex
    v_15444 = (*qfn1(fn))(fn, v_15444);
    env = stack[0];
    v_15444 = qcar(v_15444);
    {
        fn = elt(env, 2); // sfto_mvarx
        return (*qfn1(fn))(fn, v_15444);
    }
}



// Code for dipnumcontent

static LispObject CC_dipnumcontent(LispObject env,
                         LispObject v_15433, LispObject v_15434)
{
    env = qenv(env);
    LispObject v_15466, v_15467;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15433,v_15434);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15434;
    stack[-1] = v_15433;
// end of prologue
v_15439:
    v_15466 = stack[0];
    fn = elt(env, 1); // bcone!?
    v_15466 = (*qfn1(fn))(fn, v_15466);
    env = stack[-3];
    if (v_15466 == nil) goto v_15444;
    else goto v_15442;
v_15444:
    v_15466 = stack[-1];
    if (v_15466 == nil) goto v_15442;
    goto v_15443;
v_15442:
    v_15466 = stack[0];
    goto v_15438;
v_15443:
    v_15466 = stack[-1];
    v_15466 = qcdr(v_15466);
    v_15466 = qcdr(v_15466);
    stack[-2] = v_15466;
    goto v_15460;
v_15456:
    v_15467 = stack[0];
    goto v_15457;
v_15458:
    v_15466 = stack[-1];
    v_15466 = qcdr(v_15466);
    v_15466 = qcar(v_15466);
    goto v_15459;
v_15460:
    goto v_15456;
v_15457:
    goto v_15458;
v_15459:
    fn = elt(env, 2); // vbcgcd
    v_15466 = (*qfn2(fn))(fn, v_15467, v_15466);
    env = stack[-3];
    stack[0] = v_15466;
    v_15466 = stack[-2];
    stack[-1] = v_15466;
    goto v_15439;
    v_15466 = nil;
v_15438:
    return onevalue(v_15466);
}



// Code for ordexp

static LispObject CC_ordexp(LispObject env,
                         LispObject v_15433, LispObject v_15434)
{
    env = qenv(env);
    LispObject v_15482, v_15483, v_15484, v_15485;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15483 = v_15434;
    v_15484 = v_15433;
// end of prologue
v_15438:
    v_15482 = v_15484;
    if (v_15482 == nil) goto v_15441;
    else goto v_15442;
v_15441:
    v_15482 = lisp_true;
    goto v_15437;
v_15442:
    goto v_15451;
v_15447:
    v_15482 = v_15484;
    v_15485 = qcar(v_15482);
    goto v_15448;
v_15449:
    v_15482 = v_15483;
    v_15482 = qcar(v_15482);
    goto v_15450;
v_15451:
    goto v_15447;
v_15448:
    goto v_15449;
v_15450:
    if (v_15485 == v_15482) goto v_15445;
    else goto v_15446;
v_15445:
    v_15482 = v_15484;
    v_15482 = qcdr(v_15482);
    v_15484 = v_15482;
    v_15482 = v_15483;
    v_15482 = qcdr(v_15482);
    v_15483 = v_15482;
    goto v_15438;
v_15446:
    v_15482 = v_15484;
    v_15482 = qcar(v_15482);
    if (v_15482 == nil) goto v_15460;
    else goto v_15461;
v_15460:
    v_15482 = nil;
    goto v_15437;
v_15461:
    v_15482 = v_15483;
    v_15482 = qcar(v_15482);
    if (v_15482 == nil) goto v_15465;
    else goto v_15466;
v_15465:
    v_15482 = lisp_true;
    goto v_15437;
v_15466:
    goto v_15477;
v_15473:
    v_15482 = v_15484;
    v_15482 = qcar(v_15482);
    goto v_15474;
v_15475:
    v_15483 = qcar(v_15483);
    goto v_15476;
v_15477:
    goto v_15473;
v_15474:
    goto v_15475;
v_15476:
    {
        fn = elt(env, 1); // ordop
        return (*qfn2(fn))(fn, v_15482, v_15483);
    }
    v_15482 = nil;
v_15437:
    return onevalue(v_15482);
}



// Code for l!-subst

static LispObject CC_lKsubst(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15481, v_15482, v_15483;
    LispObject fn;
    LispObject v_15435, v_15434, v_15433;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "l-subst");
    va_start(aa, nargs);
    v_15433 = va_arg(aa, LispObject);
    v_15434 = va_arg(aa, LispObject);
    v_15435 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15435,v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15433,v_15434,v_15435);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15435;
    stack[-1] = v_15434;
    stack[-2] = v_15433;
// end of prologue
    v_15483 = nil;
v_15440:
    v_15481 = stack[0];
    if (v_15481 == nil) goto v_15443;
    else goto v_15444;
v_15443:
    v_15481 = v_15483;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_15481);
    }
v_15444:
    goto v_15454;
v_15450:
    v_15482 = stack[-1];
    goto v_15451;
v_15452:
    v_15481 = stack[0];
    v_15481 = qcar(v_15481);
    goto v_15453;
v_15454:
    goto v_15450;
v_15451:
    goto v_15452;
v_15453:
    if (equal(v_15482, v_15481)) goto v_15448;
    else goto v_15449;
v_15448:
    goto v_15463;
v_15459:
    v_15481 = stack[-2];
    goto v_15460;
v_15461:
    v_15482 = v_15483;
    goto v_15462;
v_15463:
    goto v_15459;
v_15460:
    goto v_15461;
v_15462:
    v_15481 = cons(v_15481, v_15482);
    env = stack[-3];
    v_15483 = v_15481;
    v_15481 = stack[0];
    v_15481 = qcdr(v_15481);
    stack[0] = v_15481;
    goto v_15440;
v_15449:
    goto v_15475;
v_15471:
    v_15481 = stack[0];
    v_15481 = qcar(v_15481);
    goto v_15472;
v_15473:
    v_15482 = v_15483;
    goto v_15474;
v_15475:
    goto v_15471;
v_15472:
    goto v_15473;
v_15474:
    v_15481 = cons(v_15481, v_15482);
    env = stack[-3];
    v_15483 = v_15481;
    v_15481 = stack[0];
    v_15481 = qcdr(v_15481);
    stack[0] = v_15481;
    goto v_15440;
    v_15481 = nil;
    return onevalue(v_15481);
}



// Code for sqhorner!*

static LispObject CC_sqhornerH(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15466, v_15467;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15433);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_15433;
// end of prologue
    v_15466 = qvalue(elt(env, 1)); // !*horner
    if (v_15466 == nil) goto v_15437;
    else goto v_15438;
v_15437:
    v_15466 = stack[-1];
    goto v_15436;
v_15438:
    goto v_15448;
v_15444:
    v_15467 = qvalue(elt(env, 2)); // ordl!*
    goto v_15445;
v_15446:
    v_15466 = qvalue(elt(env, 3)); // kord!*
    goto v_15447;
v_15448:
    goto v_15444;
v_15445:
    goto v_15446;
v_15447:
    v_15466 = Lappend(nil, v_15467, v_15466);
    env = stack[-3];
// Binding kord!*
// FLUIDBIND: reloadenv=3 litvec-offset=3 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 3, -2);
    qvalue(elt(env, 3)) = v_15466; // kord!*
    goto v_15458;
v_15454:
    v_15466 = stack[-1];
    v_15466 = qcar(v_15466);
    fn = elt(env, 4); // reorder
    stack[0] = (*qfn1(fn))(fn, v_15466);
    env = stack[-3];
    goto v_15455;
v_15456:
    v_15466 = stack[-1];
    v_15466 = qcdr(v_15466);
    fn = elt(env, 4); // reorder
    v_15466 = (*qfn1(fn))(fn, v_15466);
    env = stack[-3];
    fn = elt(env, 5); // hornerf
    v_15466 = (*qfn1(fn))(fn, v_15466);
    env = stack[-3];
    goto v_15457;
v_15458:
    goto v_15454;
v_15455:
    goto v_15456;
v_15457:
    v_15466 = cons(stack[0], v_15466);
    env = stack[-3];
    fn = elt(env, 6); // hornersq
    v_15466 = (*qfn1(fn))(fn, v_15466);
    ;}  // end of a binding scope
    goto v_15436;
    v_15466 = nil;
v_15436:
    return onevalue(v_15466);
}



// Code for no_dum_varp

static LispObject CC_no_dum_varp(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15469, v_15470;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15433);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_15433;
// end of prologue
    v_15469 = stack[0];
    v_15469 = qcdr(v_15469);
    if (v_15469 == nil) goto v_15441;
    else goto v_15442;
v_15441:
    v_15469 = lisp_true;
    goto v_15440;
v_15442:
    goto v_15452;
v_15448:
    goto v_15458;
v_15454:
    v_15469 = stack[0];
    v_15470 = qcdr(v_15469);
    goto v_15455;
v_15456:
    v_15469 = elt(env, 1); // list
    goto v_15457;
v_15458:
    goto v_15454;
v_15455:
    goto v_15456;
v_15457:
    fn = elt(env, 2); // splitlist!:
    v_15470 = (*qfn2(fn))(fn, v_15470, v_15469);
    goto v_15449;
v_15450:
    v_15469 = stack[0];
    v_15469 = qcdr(v_15469);
    goto v_15451;
v_15452:
    goto v_15448;
v_15449:
    goto v_15450;
v_15451:
    v_15469 = (equal(v_15470, v_15469) ? lisp_true : nil);
    goto v_15440;
    v_15469 = nil;
v_15440:
    if (v_15469 == nil) goto v_15438;
    v_15469 = lisp_true;
    goto v_15436;
v_15438:
    v_15469 = nil;
    goto v_15436;
    v_15469 = nil;
v_15436:
    return onevalue(v_15469);
}



// Code for proper!-simpsqrt

static LispObject CC_properKsimpsqrt(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15444, v_15445;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15433);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15444 = v_15433;
// end of prologue
    goto v_15441;
v_15437:
    v_15445 = v_15444;
    goto v_15438;
v_15439:
    v_15444 = elt(env, 0); // proper!-simpsqrt
    goto v_15440;
v_15441:
    goto v_15437;
v_15438:
    goto v_15439;
v_15440:
    fn = elt(env, 1); // carx
    v_15444 = (*qfn2(fn))(fn, v_15445, v_15444);
    env = stack[0];
    {
        fn = elt(env, 2); // simpsqrti
        return (*qfn1(fn))(fn, v_15444);
    }
}



// Code for delasc

static LispObject CC_delasc(LispObject env,
                         LispObject v_15433, LispObject v_15434)
{
    env = qenv(env);
    LispObject v_15484, v_15485;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15433,v_15434);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15434;
    stack[-1] = v_15433;
// end of prologue
    stack[-2] = nil;
v_15441:
    v_15484 = stack[0];
    if (v_15484 == nil) goto v_15444;
    else goto v_15445;
v_15444:
    goto v_15440;
v_15445:
    v_15484 = stack[0];
    v_15484 = qcar(v_15484);
    if (!consp(v_15484)) goto v_15454;
    else goto v_15455;
v_15454:
    v_15484 = lisp_true;
    goto v_15453;
v_15455:
    goto v_15466;
v_15462:
    v_15485 = stack[-1];
    goto v_15463;
v_15464:
    v_15484 = stack[0];
    v_15484 = qcar(v_15484);
    v_15484 = qcar(v_15484);
    goto v_15465;
v_15466:
    goto v_15462;
v_15463:
    goto v_15464;
v_15465:
    v_15484 = Lneq(nil, v_15485, v_15484);
    env = stack[-3];
    goto v_15453;
    v_15484 = nil;
v_15453:
    if (v_15484 == nil) goto v_15451;
    goto v_15476;
v_15472:
    v_15484 = stack[0];
    v_15485 = qcar(v_15484);
    goto v_15473;
v_15474:
    v_15484 = stack[-2];
    goto v_15475;
v_15476:
    goto v_15472;
v_15473:
    goto v_15474;
v_15475:
    v_15484 = cons(v_15485, v_15484);
    env = stack[-3];
    stack[-2] = v_15484;
    goto v_15449;
v_15451:
v_15449:
    v_15484 = stack[0];
    v_15484 = qcdr(v_15484);
    stack[0] = v_15484;
    goto v_15441;
v_15440:
    v_15484 = stack[-2];
        return Lnreverse(nil, v_15484);
    return onevalue(v_15484);
}



// Code for lalr_prin_reduction

static LispObject CC_lalr_prin_reduction(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15494, v_15495;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15433);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_15433;
// end of prologue
    v_15494 = qvalue(elt(env, 1)); // reduction_info
    v_15494 = qcar(v_15494);
    stack[-3] = v_15494;
    v_15494 = qvalue(elt(env, 1)); // reduction_info
    v_15494 = qcdr(v_15494);
    v_15494 = qcar(v_15494);
    stack[-1] = v_15494;
    v_15494 = qvalue(elt(env, 1)); // reduction_info
    v_15494 = qcdr(v_15494);
    v_15494 = qcdr(v_15494);
    v_15494 = qcar(v_15494);
    stack[0] = v_15494;
    v_15494 = elt(env, 2); // "reduce by #"
    v_15494 = Lprinc(nil, v_15494);
    env = stack[-4];
    v_15494 = stack[-2];
    v_15494 = Lprin(nil, v_15494);
    env = stack[-4];
    v_15494 = elt(env, 3); // ": "
    v_15494 = Lprinc(nil, v_15494);
    env = stack[-4];
    goto v_15462;
v_15458:
    v_15495 = stack[0];
    goto v_15459;
v_15460:
    v_15494 = stack[-2];
    goto v_15461;
v_15462:
    goto v_15458;
v_15459:
    goto v_15460;
v_15461:
    fn = elt(env, 6); // getv16
    v_15494 = (*qfn2(fn))(fn, v_15495, v_15494);
    env = stack[-4];
    fn = elt(env, 7); // lalr_prin_nonterminal
    v_15494 = (*qfn1(fn))(fn, v_15494);
    env = stack[-4];
    v_15494 = elt(env, 4); // " -> ["
    v_15494 = Lprinc(nil, v_15494);
    env = stack[-4];
    goto v_15473;
v_15469:
    v_15495 = stack[-1];
    goto v_15470;
v_15471:
    v_15494 = stack[-2];
    goto v_15472;
v_15473:
    goto v_15469;
v_15470:
    goto v_15471;
v_15472:
    fn = elt(env, 8); // getv8
    v_15494 = (*qfn2(fn))(fn, v_15495, v_15494);
    env = stack[-4];
    v_15494 = Lprin(nil, v_15494);
    env = stack[-4];
    v_15494 = elt(env, 5); // " symbols] "
    v_15494 = Lprinc(nil, v_15494);
    env = stack[-4];
    goto v_15486;
v_15482:
    v_15495 = stack[-3];
    goto v_15483;
v_15484:
    v_15494 = stack[-2];
    goto v_15485;
v_15486:
    goto v_15482;
v_15483:
    goto v_15484;
v_15485:
    v_15494 = *(LispObject *)((char *)v_15495 + (CELL-TAG_VECTOR) + (((intptr_t)v_15494-TAG_FIXNUM)/(16/CELL)));
    v_15495 = v_15494;
    if (v_15494 == nil) goto v_15481;
    v_15494 = v_15495;
    fn = elt(env, 9); // getd
    v_15494 = (*qfn1(fn))(fn, v_15494);
    env = stack[-4];
    v_15494 = qcdr(v_15494);
    fn = elt(env, 10); // prin_with_margin
    v_15494 = (*qfn1(fn))(fn, v_15494);
    goto v_15479;
v_15481:
v_15479:
    v_15494 = nil;
    return onevalue(v_15494);
}



// Code for quotfx1

static LispObject CC_quotfx1(LispObject env,
                         LispObject v_15433, LispObject v_15434)
{
    env = qenv(env);
    LispObject v_15813, v_15814, v_15815, v_15816;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15433,v_15434);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-7] = v_15434;
    stack[-8] = v_15433;
// end of prologue
    v_15813 = stack[-8];
    if (v_15813 == nil) goto v_15438;
    else goto v_15439;
v_15438:
    goto v_15446;
v_15442:
    v_15814 = stack[-8];
    goto v_15443;
v_15444:
    v_15813 = stack[-7];
    goto v_15445;
v_15446:
    goto v_15442;
v_15443:
    goto v_15444;
v_15445:
    {
        fn = elt(env, 1); // quotfxerr
        return (*qfn2(fn))(fn, v_15814, v_15813);
    }
v_15439:
    goto v_15455;
v_15451:
    v_15814 = stack[-8];
    goto v_15452;
v_15453:
    v_15813 = stack[-7];
    goto v_15454;
v_15455:
    goto v_15451;
v_15452:
    goto v_15453;
v_15454:
    if (equal(v_15814, v_15813)) goto v_15449;
    else goto v_15450;
v_15449:
    v_15813 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15437;
v_15450:
    goto v_15465;
v_15461:
    v_15814 = stack[-7];
    goto v_15462;
v_15463:
    v_15813 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15464;
v_15465:
    goto v_15461;
v_15462:
    goto v_15463;
v_15464:
    if (v_15814 == v_15813) goto v_15459;
    else goto v_15460;
v_15459:
    v_15813 = stack[-8];
    goto v_15437;
v_15460:
    v_15813 = stack[-7];
    if (!consp(v_15813)) goto v_15473;
    else goto v_15474;
v_15473:
    v_15813 = lisp_true;
    goto v_15472;
v_15474:
    v_15813 = stack[-7];
    v_15813 = qcar(v_15813);
    v_15813 = (consp(v_15813) ? nil : lisp_true);
    goto v_15472;
    v_15813 = nil;
v_15472:
    if (v_15813 == nil) goto v_15470;
    goto v_15487;
v_15483:
    v_15814 = stack[-8];
    goto v_15484;
v_15485:
    v_15813 = stack[-7];
    goto v_15486;
v_15487:
    goto v_15483;
v_15484:
    goto v_15485;
v_15486:
    {
        fn = elt(env, 2); // quotfdx
        return (*qfn2(fn))(fn, v_15814, v_15813);
    }
v_15470:
    v_15813 = stack[-8];
    if (!consp(v_15813)) goto v_15494;
    else goto v_15495;
v_15494:
    v_15813 = lisp_true;
    goto v_15493;
v_15495:
    v_15813 = stack[-8];
    v_15813 = qcar(v_15813);
    v_15813 = (consp(v_15813) ? nil : lisp_true);
    goto v_15493;
    v_15813 = nil;
v_15493:
    if (v_15813 == nil) goto v_15491;
    goto v_15508;
v_15504:
    v_15814 = stack[-8];
    goto v_15505;
v_15506:
    v_15813 = stack[-7];
    goto v_15507;
v_15508:
    goto v_15504;
v_15505:
    goto v_15506;
v_15507:
    {
        fn = elt(env, 1); // quotfxerr
        return (*qfn2(fn))(fn, v_15814, v_15813);
    }
v_15491:
    goto v_15517;
v_15513:
    v_15813 = stack[-8];
    v_15813 = qcar(v_15813);
    v_15813 = qcar(v_15813);
    v_15814 = qcar(v_15813);
    goto v_15514;
v_15515:
    v_15813 = stack[-7];
    v_15813 = qcar(v_15813);
    v_15813 = qcar(v_15813);
    v_15813 = qcar(v_15813);
    goto v_15516;
v_15517:
    goto v_15513;
v_15514:
    goto v_15515;
v_15516:
    if (v_15814 == v_15813) goto v_15511;
    else goto v_15512;
v_15511:
    stack[-9] = nil;
    stack[-1] = nil;
    v_15813 = stack[-7];
    v_15813 = qcar(v_15813);
    v_15813 = qcar(v_15813);
    v_15813 = qcdr(v_15813);
    stack[-5] = v_15813;
v_15538:
    goto v_15557;
v_15553:
    v_15813 = stack[-8];
    v_15813 = qcar(v_15813);
    v_15813 = qcar(v_15813);
    v_15814 = qcdr(v_15813);
    stack[-6] = v_15814;
    goto v_15554;
v_15555:
    v_15813 = stack[-5];
    goto v_15556;
v_15557:
    goto v_15553;
v_15554:
    goto v_15555;
v_15556:
    v_15813 = (LispObject)lessp2(v_15814, v_15813);
    v_15813 = v_15813 ? lisp_true : nil;
    env = stack[-10];
    if (v_15813 == nil) goto v_15551;
    goto v_15568;
v_15564:
    v_15814 = stack[-8];
    goto v_15565;
v_15566:
    v_15813 = stack[-7];
    goto v_15567;
v_15568:
    goto v_15564;
v_15565:
    goto v_15566;
v_15567:
    {
        fn = elt(env, 1); // quotfxerr
        return (*qfn2(fn))(fn, v_15814, v_15813);
    }
v_15551:
    v_15813 = stack[-8];
    fn = elt(env, 3); // lt!*
    v_15813 = (*qfn1(fn))(fn, v_15813);
    env = stack[-10];
    stack[0] = v_15813;
    v_15813 = stack[-7];
    fn = elt(env, 3); // lt!*
    v_15813 = (*qfn1(fn))(fn, v_15813);
    env = stack[-10];
    v_15814 = stack[-7];
    v_15814 = qcar(v_15814);
    v_15814 = qcar(v_15814);
    v_15814 = qcar(v_15814);
    stack[-4] = v_15814;
    goto v_15584;
v_15580:
    v_15814 = stack[0];
    v_15814 = qcdr(v_15814);
    goto v_15581;
v_15582:
    v_15813 = qcdr(v_15813);
    goto v_15583;
v_15584:
    goto v_15580;
v_15581:
    goto v_15582;
v_15583:
    v_15813 = CC_quotfx1(elt(env, 0), v_15814, v_15813);
    env = stack[-10];
    stack[-3] = v_15813;
    goto v_15593;
v_15589:
    v_15814 = stack[-6];
    goto v_15590;
v_15591:
    v_15813 = stack[-5];
    goto v_15592;
v_15593:
    goto v_15589;
v_15590:
    goto v_15591;
v_15592:
    v_15813 = (LispObject)(intptr_t)((intptr_t)v_15814 - (intptr_t)v_15813 + TAG_FIXNUM);
    stack[0] = v_15813;
    goto v_15605;
v_15601:
    v_15814 = stack[0];
    goto v_15602;
v_15603:
    v_15813 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15604;
v_15605:
    goto v_15601;
v_15602:
    goto v_15603;
v_15604:
    if (v_15814 == v_15813) goto v_15599;
    else goto v_15600;
v_15599:
    goto v_15613;
v_15609:
    v_15814 = stack[-1];
    goto v_15610;
v_15611:
    v_15813 = stack[-3];
    goto v_15612;
v_15613:
    goto v_15609;
v_15610:
    goto v_15611;
v_15612:
    {
        fn = elt(env, 4); // rnconc
        return (*qfn2(fn))(fn, v_15814, v_15813);
    }
v_15600:
    goto v_15621;
v_15617:
    v_15814 = stack[-4];
    goto v_15618;
v_15619:
    v_15813 = stack[0];
    goto v_15620;
v_15621:
    goto v_15617;
v_15618:
    goto v_15619;
v_15620:
    fn = elt(env, 5); // to
    v_15813 = (*qfn2(fn))(fn, v_15814, v_15813);
    env = stack[-10];
    stack[-2] = v_15813;
    v_15813 = stack[-9];
    if (v_15813 == nil) goto v_15626;
    else goto v_15627;
v_15626:
    goto v_15636;
v_15630:
    v_15816 = stack[-8];
    goto v_15631;
v_15632:
    v_15815 = stack[-4];
    goto v_15633;
v_15634:
    goto v_15643;
v_15639:
    v_15814 = stack[-6];
    goto v_15640;
v_15641:
    v_15813 = stack[0];
    goto v_15642;
v_15643:
    goto v_15639;
v_15640:
    goto v_15641;
v_15642:
    v_15813 = (LispObject)(intptr_t)((intptr_t)v_15814 - (intptr_t)v_15813 + TAG_FIXNUM);
    v_15813 = (LispObject)((intptr_t)(v_15813) - 0x10);
    goto v_15635;
v_15636:
    goto v_15630;
v_15631:
    goto v_15632;
v_15633:
    goto v_15634;
v_15635:
    fn = elt(env, 6); // cutf
    v_15813 = (*qfnn(fn))(fn, 3, v_15816, v_15815, v_15813);
    env = stack[-10];
    stack[-8] = v_15813;
    goto v_15625;
v_15627:
v_15625:
    v_15813 = lisp_true;
    stack[-9] = v_15813;
    goto v_15656;
v_15650:
    v_15816 = stack[-7];
    goto v_15651;
v_15652:
    v_15815 = stack[-4];
    goto v_15653;
v_15654:
    goto v_15663;
v_15659:
    v_15814 = stack[-5];
    goto v_15660;
v_15661:
    v_15813 = stack[0];
    goto v_15662;
v_15663:
    goto v_15659;
v_15660:
    goto v_15661;
v_15662:
    v_15813 = (LispObject)(intptr_t)((intptr_t)v_15814 - (intptr_t)v_15813 + TAG_FIXNUM);
    v_15813 = (LispObject)((intptr_t)(v_15813) - 0x10);
    goto v_15655;
v_15656:
    goto v_15650;
v_15651:
    goto v_15652;
v_15653:
    goto v_15654;
v_15655:
    fn = elt(env, 6); // cutf
    v_15813 = (*qfnn(fn))(fn, 3, v_15816, v_15815, v_15813);
    env = stack[-10];
    stack[-7] = v_15813;
    goto v_15673;
v_15669:
    stack[-6] = stack[-8];
    goto v_15670;
v_15671:
    goto v_15680;
v_15676:
    goto v_15689;
v_15685:
    v_15814 = stack[0];
    goto v_15686;
v_15687:
    v_15813 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15688;
v_15689:
    goto v_15685;
v_15686:
    goto v_15687;
v_15688:
    if (v_15814 == v_15813) goto v_15683;
    else goto v_15684;
v_15683:
    v_15813 = stack[-7];
    stack[0] = v_15813;
    goto v_15682;
v_15684:
    goto v_15700;
v_15696:
    goto v_15707;
v_15703:
    v_15814 = stack[-2];
    goto v_15704;
v_15705:
    v_15813 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15706;
v_15707:
    goto v_15703;
v_15704:
    goto v_15705;
v_15706:
    v_15813 = cons(v_15814, v_15813);
    env = stack[-10];
    v_15814 = ncons(v_15813);
    env = stack[-10];
    goto v_15697;
v_15698:
    v_15813 = stack[-7];
    goto v_15699;
v_15700:
    goto v_15696;
v_15697:
    goto v_15698;
v_15699:
    fn = elt(env, 7); // multf
    v_15813 = (*qfn2(fn))(fn, v_15814, v_15813);
    env = stack[-10];
    stack[0] = v_15813;
    goto v_15682;
    stack[0] = nil;
v_15682:
    goto v_15677;
v_15678:
    v_15813 = stack[-3];
    fn = elt(env, 8); // negf
    v_15813 = (*qfn1(fn))(fn, v_15813);
    env = stack[-10];
    goto v_15679;
v_15680:
    goto v_15676;
v_15677:
    goto v_15678;
v_15679:
    fn = elt(env, 7); // multf
    v_15813 = (*qfn2(fn))(fn, stack[0], v_15813);
    env = stack[-10];
    goto v_15672;
v_15673:
    goto v_15669;
v_15670:
    goto v_15671;
v_15672:
    fn = elt(env, 9); // addf
    v_15813 = (*qfn2(fn))(fn, stack[-6], v_15813);
    env = stack[-10];
    stack[-8] = v_15813;
    v_15813 = stack[-8];
    if (v_15813 == nil) goto v_15716;
    v_15813 = stack[-8];
    if (!consp(v_15813)) goto v_15726;
    else goto v_15727;
v_15726:
    v_15813 = lisp_true;
    goto v_15725;
v_15727:
    v_15813 = stack[-8];
    v_15813 = qcar(v_15813);
    v_15813 = (consp(v_15813) ? nil : lisp_true);
    goto v_15725;
    v_15813 = nil;
v_15725:
    if (v_15813 == nil) goto v_15723;
    v_15813 = lisp_true;
    goto v_15721;
v_15723:
    goto v_15742;
v_15738:
    v_15813 = stack[-8];
    v_15813 = qcar(v_15813);
    v_15813 = qcar(v_15813);
    v_15814 = qcar(v_15813);
    goto v_15739;
v_15740:
    v_15813 = stack[-4];
    goto v_15741;
v_15742:
    goto v_15738;
v_15739:
    goto v_15740;
v_15741:
    v_15813 = (v_15814 == v_15813 ? lisp_true : nil);
    v_15813 = (v_15813 == nil ? lisp_true : nil);
    goto v_15721;
    v_15813 = nil;
v_15721:
    if (v_15813 == nil) goto v_15716;
    goto v_15755;
v_15751:
    v_15814 = stack[-8];
    goto v_15752;
v_15753:
    v_15813 = stack[-7];
    goto v_15754;
v_15755:
    goto v_15751;
v_15752:
    goto v_15753;
v_15754:
    {
        fn = elt(env, 1); // quotfxerr
        return (*qfn2(fn))(fn, v_15814, v_15813);
    }
v_15716:
    goto v_15763;
v_15759:
    stack[0] = stack[-1];
    goto v_15760;
v_15761:
    goto v_15770;
v_15766:
    v_15814 = stack[-2];
    goto v_15767;
v_15768:
    v_15813 = stack[-3];
    goto v_15769;
v_15770:
    goto v_15766;
v_15767:
    goto v_15768;
v_15769:
    v_15813 = cons(v_15814, v_15813);
    env = stack[-10];
    goto v_15762;
v_15763:
    goto v_15759;
v_15760:
    goto v_15761;
v_15762:
    fn = elt(env, 10); // aconc!*
    v_15813 = (*qfn2(fn))(fn, stack[0], v_15813);
    env = stack[-10];
    stack[-1] = v_15813;
    v_15813 = stack[-8];
    if (v_15813 == nil) goto v_15775;
    else goto v_15776;
v_15775:
    v_15813 = stack[-1];
    goto v_15537;
v_15776:
    goto v_15538;
v_15537:
    goto v_15437;
v_15512:
    goto v_15786;
v_15782:
    v_15813 = stack[-8];
    v_15813 = qcar(v_15813);
    v_15813 = qcar(v_15813);
    v_15814 = qcar(v_15813);
    goto v_15783;
v_15784:
    v_15813 = stack[-7];
    v_15813 = qcar(v_15813);
    v_15813 = qcar(v_15813);
    v_15813 = qcar(v_15813);
    goto v_15785;
v_15786:
    goto v_15782;
v_15783:
    goto v_15784;
v_15785:
    fn = elt(env, 11); // ordop
    v_15813 = (*qfn2(fn))(fn, v_15814, v_15813);
    env = stack[-10];
    if (v_15813 == nil) goto v_15780;
    goto v_15800;
v_15796:
    v_15814 = stack[-8];
    goto v_15797;
v_15798:
    v_15813 = stack[-7];
    goto v_15799;
v_15800:
    goto v_15796;
v_15797:
    goto v_15798;
v_15799:
    {
        fn = elt(env, 12); // quotkx
        return (*qfn2(fn))(fn, v_15814, v_15813);
    }
v_15780:
    goto v_15810;
v_15806:
    v_15814 = stack[-8];
    goto v_15807;
v_15808:
    v_15813 = stack[-7];
    goto v_15809;
v_15810:
    goto v_15806;
v_15807:
    goto v_15808;
v_15809:
    {
        fn = elt(env, 1); // quotfxerr
        return (*qfn2(fn))(fn, v_15814, v_15813);
    }
    v_15813 = nil;
v_15437:
    return onevalue(v_15813);
}



// Code for gcref_remprops

static LispObject CC_gcref_remprops(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15500, v_15501, v_15502;
    LispObject fn;
    argcheck(nargs, 0, "gcref_remprops");
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
    goto v_15439;
v_15435:
    v_15501 = qvalue(elt(env, 1)); // seen!*
    goto v_15436;
v_15437:
    v_15500 = elt(env, 2); // (gall calls globs calledby alsois sameas)
    goto v_15438;
v_15439:
    goto v_15435;
v_15436:
    goto v_15437;
v_15438:
    fn = elt(env, 12); // rempropss
    v_15500 = (*qfn2(fn))(fn, v_15501, v_15500);
    env = stack[0];
    goto v_15447;
v_15443:
    v_15501 = qvalue(elt(env, 1)); // seen!*
    goto v_15444;
v_15445:
    v_15500 = elt(env, 3); // (seen cinthis defd)
    goto v_15446;
v_15447:
    goto v_15443;
v_15444:
    goto v_15445;
v_15446:
    fn = elt(env, 13); // remflagss
    v_15500 = (*qfn2(fn))(fn, v_15501, v_15500);
    env = stack[0];
    goto v_15455;
v_15451:
    v_15501 = qvalue(elt(env, 4)); // gcref_exportl!*
    goto v_15452;
v_15453:
    v_15500 = elt(env, 5); // (exported)
    goto v_15454;
v_15455:
    goto v_15451;
v_15452:
    goto v_15453;
v_15454:
    fn = elt(env, 13); // remflagss
    v_15500 = (*qfn2(fn))(fn, v_15501, v_15500);
    env = stack[0];
    goto v_15463;
v_15459:
    v_15501 = qvalue(elt(env, 6)); // gseen!*
    goto v_15460;
v_15461:
    v_15500 = elt(env, 7); // (usedby usedunby boundby setby)
    goto v_15462;
v_15463:
    goto v_15459;
v_15460:
    goto v_15461;
v_15462:
    fn = elt(env, 12); // rempropss
    v_15500 = (*qfn2(fn))(fn, v_15501, v_15500);
    env = stack[0];
    goto v_15471;
v_15467:
    v_15501 = qvalue(elt(env, 6)); // gseen!*
    goto v_15468;
v_15469:
    v_15500 = elt(env, 8); // (dclglb gseen glb2rf glb2bd glb2st)
    goto v_15470;
v_15471:
    goto v_15467;
v_15468:
    goto v_15469;
v_15470:
    fn = elt(env, 13); // remflagss
    v_15500 = (*qfn2(fn))(fn, v_15501, v_15500);
    env = stack[0];
    v_15500 = qvalue(elt(env, 9)); // tseen!*
    v_15502 = v_15500;
v_15477:
    v_15500 = v_15502;
    if (v_15500 == nil) goto v_15481;
    else goto v_15482;
v_15481:
    goto v_15476;
v_15482:
    v_15500 = v_15502;
    v_15500 = qcar(v_15500);
    goto v_15493;
v_15489:
    v_15501 = qcar(v_15500);
    goto v_15490;
v_15491:
    v_15500 = elt(env, 10); // funs
    goto v_15492;
v_15493:
    goto v_15489;
v_15490:
    goto v_15491;
v_15492:
    v_15500 = Lremprop(nil, v_15501, v_15500);
    env = stack[0];
    v_15500 = v_15502;
    v_15500 = qcdr(v_15500);
    v_15502 = v_15500;
    goto v_15477;
v_15476:
    v_15500 = nil;
    qvalue(elt(env, 9)) = v_15500; // tseen!*
    qvalue(elt(env, 1)) = v_15500; // seen!*
    qvalue(elt(env, 6)) = v_15500; // gseen!*
    qvalue(elt(env, 11)) = v_15500; // haveargs!*
    return onevalue(v_15500);
}



// Code for sortedtriplelistinsert

static LispObject CC_sortedtriplelistinsert(LispObject env,
                         LispObject v_15433, LispObject v_15434)
{
    env = qenv(env);
    LispObject v_15512, v_15513, v_15514;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15433,v_15434);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_15434;
    v_15514 = v_15433;
// end of prologue
    goto v_15444;
v_15440:
    v_15513 = stack[-1];
    goto v_15441;
v_15442:
    v_15512 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15443;
v_15444:
    goto v_15440;
v_15441:
    goto v_15442;
v_15443:
    v_15512 = *(LispObject *)((char *)v_15513 + (CELL-TAG_VECTOR) + (((intptr_t)v_15512-TAG_FIXNUM)/(16/CELL)));
    v_15512 = qcar(v_15512);
    stack[0] = v_15512;
    v_15512 = v_15514;
    stack[-2] = v_15512;
v_15452:
    v_15512 = stack[-2];
    v_15512 = qcar(v_15512);
    if (v_15512 == nil) goto v_15455;
    goto v_15465;
v_15461:
    goto v_15471;
v_15467:
    goto v_15476;
v_15472:
    v_15512 = stack[-2];
    v_15513 = qcar(v_15512);
    goto v_15473;
v_15474:
    v_15512 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15475;
v_15476:
    goto v_15472;
v_15473:
    goto v_15474;
v_15475:
    v_15512 = *(LispObject *)((char *)v_15513 + (CELL-TAG_VECTOR) + (((intptr_t)v_15512-TAG_FIXNUM)/(16/CELL)));
    v_15513 = qcar(v_15512);
    goto v_15468;
v_15469:
    v_15512 = stack[0];
    goto v_15470;
v_15471:
    goto v_15467;
v_15468:
    goto v_15469;
v_15470:
    fn = elt(env, 1); // monomcompare
    v_15513 = (*qfn2(fn))(fn, v_15513, v_15512);
    env = stack[-3];
    goto v_15462;
v_15463:
    v_15512 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15464;
v_15465:
    goto v_15461;
v_15462:
    goto v_15463;
v_15464:
    if (v_15513 == v_15512) goto v_15455;
    goto v_15456;
v_15455:
    goto v_15451;
v_15456:
    v_15512 = stack[-2];
    v_15512 = qcdr(v_15512);
    stack[-2] = v_15512;
    goto v_15452;
v_15451:
    goto v_15493;
v_15489:
    goto v_15499;
v_15495:
    stack[0] = stack[-2];
    goto v_15496;
v_15497:
    goto v_15506;
v_15502:
    v_15512 = stack[-2];
    v_15513 = qcar(v_15512);
    goto v_15503;
v_15504:
    v_15512 = stack[-2];
    v_15512 = qcdr(v_15512);
    goto v_15505;
v_15506:
    goto v_15502;
v_15503:
    goto v_15504;
v_15505:
    v_15512 = cons(v_15513, v_15512);
    env = stack[-3];
    goto v_15498;
v_15499:
    goto v_15495;
v_15496:
    goto v_15497;
v_15498:
    v_15513 = Lrplacd(nil, stack[0], v_15512);
    env = stack[-3];
    goto v_15490;
v_15491:
    v_15512 = stack[-1];
    goto v_15492;
v_15493:
    goto v_15489;
v_15490:
    goto v_15491;
v_15492:
    v_15512 = Lrplaca(nil, v_15513, v_15512);
    v_15512 = nil;
    return onevalue(v_15512);
}



// Code for add!-degrees

static LispObject CC_addKdegrees(LispObject env,
                         LispObject v_15433, LispObject v_15434)
{
    env = qenv(env);
    LispObject v_15501, v_15502;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15433,v_15434);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_15434;
    stack[-4] = v_15433;
// end of prologue
    stack[-5] = nil;
v_15444:
    v_15501 = stack[-4];
    if (v_15501 == nil) goto v_15447;
    else goto v_15448;
v_15447:
    goto v_15443;
v_15448:
    v_15501 = stack[-4];
    v_15501 = qcar(v_15501);
    stack[-2] = v_15501;
    v_15501 = stack[-3];
    v_15501 = qcar(v_15501);
    stack[-1] = v_15501;
    v_15501 = nil;
    stack[0] = v_15501;
v_15458:
    v_15501 = stack[-2];
    if (v_15501 == nil) goto v_15461;
    else goto v_15462;
v_15461:
    goto v_15457;
v_15462:
    goto v_15470;
v_15466:
    goto v_15476;
v_15472:
    v_15501 = stack[-2];
    v_15502 = qcar(v_15501);
    goto v_15473;
v_15474:
    v_15501 = stack[-1];
    v_15501 = qcar(v_15501);
    goto v_15475;
v_15476:
    goto v_15472;
v_15473:
    goto v_15474;
v_15475:
    fn = elt(env, 1); // tayexp!-plus2
    v_15502 = (*qfn2(fn))(fn, v_15502, v_15501);
    env = stack[-6];
    goto v_15467;
v_15468:
    v_15501 = stack[0];
    goto v_15469;
v_15470:
    goto v_15466;
v_15467:
    goto v_15468;
v_15469:
    v_15501 = cons(v_15502, v_15501);
    env = stack[-6];
    stack[0] = v_15501;
    v_15501 = stack[-2];
    v_15501 = qcdr(v_15501);
    stack[-2] = v_15501;
    v_15501 = stack[-1];
    v_15501 = qcdr(v_15501);
    stack[-1] = v_15501;
    goto v_15458;
v_15457:
    goto v_15491;
v_15487:
    v_15501 = stack[0];
    v_15502 = Lnreverse(nil, v_15501);
    env = stack[-6];
    goto v_15488;
v_15489:
    v_15501 = stack[-5];
    goto v_15490;
v_15491:
    goto v_15487;
v_15488:
    goto v_15489;
v_15490:
    v_15501 = cons(v_15502, v_15501);
    env = stack[-6];
    stack[-5] = v_15501;
    v_15501 = stack[-4];
    v_15501 = qcdr(v_15501);
    stack[-4] = v_15501;
    v_15501 = stack[-3];
    v_15501 = qcdr(v_15501);
    stack[-3] = v_15501;
    goto v_15444;
v_15443:
    v_15501 = stack[-5];
        return Lnreverse(nil, v_15501);
    return onevalue(v_15501);
}



// Code for mk!+conjugate!+sq

static LispObject CC_mkLconjugateLsq(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15439;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15439 = v_15433;
// end of prologue
    {
        fn = elt(env, 1); // conjsq
        return (*qfn1(fn))(fn, v_15439);
    }
    return onevalue(v_15439);
}



// Code for mksp!*

static LispObject CC_mkspH(LispObject env,
                         LispObject v_15433, LispObject v_15434)
{
    env = qenv(env);
    LispObject v_15498, v_15499;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15433,v_15434);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15434;
    stack[-1] = v_15433;
// end of prologue
    stack[-2] = nil;
    v_15498 = stack[-1];
    if (v_15498 == nil) goto v_15445;
    else goto v_15446;
v_15445:
    v_15498 = lisp_true;
    goto v_15444;
v_15446:
    v_15498 = stack[-1];
    fn = elt(env, 1); // kernlp
    v_15498 = (*qfn1(fn))(fn, v_15498);
    env = stack[-3];
    goto v_15444;
    v_15498 = nil;
v_15444:
    if (v_15498 == nil) goto v_15442;
    goto v_15458;
v_15454:
    v_15499 = stack[-1];
    goto v_15455;
v_15456:
    v_15498 = stack[0];
    goto v_15457;
v_15458:
    goto v_15454;
v_15455:
    goto v_15456;
v_15457:
    {
        fn = elt(env, 2); // exptf
        return (*qfn2(fn))(fn, v_15499, v_15498);
    }
v_15442:
    v_15498 = stack[-1];
    fn = elt(env, 3); // minusf
    v_15498 = (*qfn1(fn))(fn, v_15498);
    env = stack[-3];
    if (v_15498 == nil) goto v_15462;
    v_15498 = lisp_true;
    stack[-2] = v_15498;
    v_15498 = stack[-1];
    fn = elt(env, 4); // negf
    v_15498 = (*qfn1(fn))(fn, v_15498);
    env = stack[-3];
    stack[-1] = v_15498;
    goto v_15440;
v_15462:
v_15440:
    goto v_15474;
v_15470:
    goto v_15480;
v_15476:
    v_15499 = stack[-1];
    goto v_15477;
v_15478:
    v_15498 = stack[0];
    goto v_15479;
v_15480:
    goto v_15476;
v_15477:
    goto v_15478;
v_15479:
    fn = elt(env, 5); // mksp
    v_15499 = (*qfn2(fn))(fn, v_15499, v_15498);
    env = stack[-3];
    goto v_15471;
v_15472:
    v_15498 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15473;
v_15474:
    goto v_15470;
v_15471:
    goto v_15472;
v_15473:
    v_15498 = cons(v_15499, v_15498);
    env = stack[-3];
    v_15498 = ncons(v_15498);
    env = stack[-3];
    stack[-1] = v_15498;
    v_15498 = stack[-2];
    if (v_15498 == nil) goto v_15487;
    v_15498 = stack[0];
    v_15498 = Levenp(nil, v_15498);
    env = stack[-3];
    if (v_15498 == nil) goto v_15490;
    else goto v_15487;
v_15490:
    v_15498 = stack[-1];
    {
        fn = elt(env, 4); // negf
        return (*qfn1(fn))(fn, v_15498);
    }
v_15487:
    v_15498 = stack[-1];
    goto v_15485;
    v_15498 = nil;
v_15485:
    return onevalue(v_15498);
}



// Code for cl_atl1

static LispObject CC_cl_atl1(LispObject env,
                         LispObject v_15433)
{
    env = qenv(env);
    LispObject v_15478;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15433);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_15478 = v_15433;
// end of prologue
    fn = elt(env, 1); // cl_atml1
    v_15478 = (*qfn1(fn))(fn, v_15478);
    env = stack[-4];
    stack[-3] = v_15478;
    v_15478 = stack[-3];
    if (v_15478 == nil) goto v_15445;
    else goto v_15446;
v_15445:
    v_15478 = nil;
    goto v_15439;
v_15446:
    v_15478 = stack[-3];
    v_15478 = qcar(v_15478);
    v_15478 = qcar(v_15478);
    v_15478 = ncons(v_15478);
    env = stack[-4];
    stack[-1] = v_15478;
    stack[-2] = v_15478;
v_15440:
    v_15478 = stack[-3];
    v_15478 = qcdr(v_15478);
    stack[-3] = v_15478;
    v_15478 = stack[-3];
    if (v_15478 == nil) goto v_15459;
    else goto v_15460;
v_15459:
    v_15478 = stack[-2];
    goto v_15439;
v_15460:
    goto v_15468;
v_15464:
    stack[0] = stack[-1];
    goto v_15465;
v_15466:
    v_15478 = stack[-3];
    v_15478 = qcar(v_15478);
    v_15478 = qcar(v_15478);
    v_15478 = ncons(v_15478);
    env = stack[-4];
    goto v_15467;
v_15468:
    goto v_15464;
v_15465:
    goto v_15466;
v_15467:
    v_15478 = Lrplacd(nil, stack[0], v_15478);
    env = stack[-4];
    v_15478 = stack[-1];
    v_15478 = qcdr(v_15478);
    stack[-1] = v_15478;
    goto v_15440;
v_15439:
    return onevalue(v_15478);
}



// Code for cl_susiupdknowl

static LispObject CC_cl_susiupdknowl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15496, v_15497, v_15498, v_15499;
    LispObject fn;
    LispObject v_15436, v_15435, v_15434, v_15433;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_susiupdknowl");
    va_start(aa, nargs);
    v_15433 = va_arg(aa, LispObject);
    v_15434 = va_arg(aa, LispObject);
    v_15435 = va_arg(aa, LispObject);
    v_15436 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_15436,v_15435,v_15434,v_15433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_15433,v_15434,v_15435,v_15436);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15436;
    v_15496 = v_15435;
    stack[-1] = v_15434;
    stack[-2] = v_15433;
// end of prologue
    stack[-3] = nil;
v_15443:
    v_15497 = stack[-1];
    if (v_15497 == nil) goto v_15446;
    else goto v_15447;
v_15446:
    goto v_15442;
v_15447:
    v_15497 = stack[-1];
    v_15497 = qcar(v_15497);
    stack[-3] = v_15497;
    v_15497 = stack[-1];
    v_15497 = qcdr(v_15497);
    stack[-1] = v_15497;
    goto v_15463;
v_15455:
    v_15499 = stack[-2];
    goto v_15456;
v_15457:
    v_15498 = stack[-3];
    goto v_15458;
v_15459:
    v_15497 = v_15496;
    goto v_15460;
v_15461:
    v_15496 = stack[0];
    goto v_15462;
v_15463:
    goto v_15455;
v_15456:
    goto v_15457;
v_15458:
    goto v_15459;
v_15460:
    goto v_15461;
v_15462:
    fn = elt(env, 3); // cl_susiupdknowl1
    v_15496 = (*qfnn(fn))(fn, 4, v_15499, v_15498, v_15497, v_15496);
    env = stack[-4];
    goto v_15476;
v_15472:
    v_15498 = v_15496;
    goto v_15473;
v_15474:
    v_15497 = elt(env, 1); // false
    goto v_15475;
v_15476:
    goto v_15472;
v_15473:
    goto v_15474;
v_15475:
    if (v_15498 == v_15497) goto v_15470;
    else goto v_15471;
v_15470:
    v_15497 = nil;
    stack[-1] = v_15497;
    v_15497 = elt(env, 2); // break
    stack[-3] = v_15497;
    goto v_15469;
v_15471:
v_15469:
    goto v_15443;
v_15442:
    goto v_15489;
v_15485:
    v_15498 = stack[-3];
    goto v_15486;
v_15487:
    v_15497 = elt(env, 2); // break
    goto v_15488;
v_15489:
    goto v_15485;
v_15486:
    goto v_15487;
v_15488:
    if (v_15498 == v_15497) goto v_15483;
    else goto v_15484;
v_15483:
    v_15496 = elt(env, 1); // false
    goto v_15440;
v_15484:
    goto v_15440;
    v_15496 = nil;
v_15440:
    return onevalue(v_15496);
}



setup_type const u28_setup[] =
{
    {"homogp",                  CC_homogp,      TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_optsubstat",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_optsubstat},
    {"atomlis",                 CC_atomlis,     TOO_MANY_1,    WRONG_NO_1},
    {"rowdel",                  CC_rowdel,      TOO_MANY_1,    WRONG_NO_1},
    {"dip2vdp",                 CC_dip2vdp,     TOO_MANY_1,    WRONG_NO_1},
    {"groebnormalform",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_groebnormalform},
    {"bfplusn",                 TOO_FEW_2,      CC_bfplusn,    WRONG_NO_2},
    {"contr-strand",            TOO_FEW_2,      CC_contrKstrand,WRONG_NO_2},
    {"formde",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formde},
    {"nf",                      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_nf},
    {"setk1",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setk1},
    {"lex_export_codes",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex_export_codes},
    {"aex_lc",                  TOO_FEW_2,      CC_aex_lc,     WRONG_NO_2},
    {"procstat1",               CC_procstat1,   TOO_MANY_1,    WRONG_NO_1},
    {"prepreform1",             TOO_FEW_2,      CC_prepreform1,WRONG_NO_2},
    {"talp_try",                CC_talp_try,    TOO_MANY_1,    WRONG_NO_1},
    {"bc_2sq",                  CC_bc_2sq,      TOO_MANY_1,    WRONG_NO_1},
    {"ombindir",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ombindir},
    {"simpdf*",                 CC_simpdfH,     TOO_MANY_1,    WRONG_NO_1},
    {"nextcomb",                TOO_FEW_2,      CC_nextcomb,   WRONG_NO_2},
    {"dip-nc-ev-prod1",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dipKncKevKprod1},
    {"pterpri",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pterpri},
    {"getphystypeor",           CC_getphystypeor,TOO_MANY_1,   WRONG_NO_1},
    {"prop-simp",               TOO_FEW_2,      CC_propKsimp,  WRONG_NO_2},
    {"nzero",                   CC_nzero,       TOO_MANY_1,    WRONG_NO_1},
    {"general-evaluate-mod-p",  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_generalKevaluateKmodKp},
    {"lalr_generate_collection",WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lalr_generate_collection},
    {"comm1",                   CC_comm1,       TOO_MANY_1,    WRONG_NO_1},
    {"normalform",              CC_normalform,  TOO_MANY_1,    WRONG_NO_1},
    {"co_new",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_co_new},
    {"wureducedp",              TOO_FEW_2,      CC_wureducedp, WRONG_NO_2},
    {"get-denom-ll",            TOO_FEW_2,      CC_getKdenomKll,WRONG_NO_2},
    {"pasf_varlat",             CC_pasf_varlat, TOO_MANY_1,    WRONG_NO_1},
    {"vunion",                  TOO_FEW_2,      CC_vunion,     WRONG_NO_2},
    {"aex_mvar",                CC_aex_mvar,    TOO_MANY_1,    WRONG_NO_1},
    {"dipnumcontent",           TOO_FEW_2,      CC_dipnumcontent,WRONG_NO_2},
    {"ordexp",                  TOO_FEW_2,      CC_ordexp,     WRONG_NO_2},
    {"l-subst",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lKsubst},
    {"sqhorner*",               CC_sqhornerH,   TOO_MANY_1,    WRONG_NO_1},
    {"no_dum_varp",             CC_no_dum_varp, TOO_MANY_1,    WRONG_NO_1},
    {"proper-simpsqrt",         CC_properKsimpsqrt,TOO_MANY_1, WRONG_NO_1},
    {"delasc",                  TOO_FEW_2,      CC_delasc,     WRONG_NO_2},
    {"lalr_prin_reduction",     CC_lalr_prin_reduction,TOO_MANY_1,WRONG_NO_1},
    {"quotfx1",                 TOO_FEW_2,      CC_quotfx1,    WRONG_NO_2},
    {"gcref_remprops",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gcref_remprops},
    {"sortedtriplelistinsert",  TOO_FEW_2,      CC_sortedtriplelistinsert,WRONG_NO_2},
    {"add-degrees",             TOO_FEW_2,      CC_addKdegrees,WRONG_NO_2},
    {"mk+conjugate+sq",         CC_mkLconjugateLsq,TOO_MANY_1, WRONG_NO_1},
    {"mksp*",                   TOO_FEW_2,      CC_mkspH,      WRONG_NO_2},
    {"cl_atl1",                 CC_cl_atl1,     TOO_MANY_1,    WRONG_NO_1},
    {"cl_susiupdknowl",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_susiupdknowl},
    {NULL, (one_args *)"u28", (two_args *)"23028 4051071 7092875", 0}
};

// end of generated code
