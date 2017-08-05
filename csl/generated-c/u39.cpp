
// $destdir/u39.c        Machine generated C code

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



// Code for num_signsort

static LispObject CC_num_signsort(LispObject env,
                         LispObject v_22093)
{
    env = qenv(env);
    LispObject v_22103, v_22104;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22103 = v_22093;
// end of prologue
    goto v_22100;
v_22096:
    v_22104 = v_22103;
    goto v_22097;
v_22098:
    v_22103 = elt(env, 1); // lambda_ygm6np4pcqv31
    goto v_22099;
v_22100:
    goto v_22096;
v_22097:
    goto v_22098;
v_22099:
    {
        fn = elt(env, 2); // ad_signsort
        return (*qfn2(fn))(fn, v_22104, v_22103);
    }
}



// Code for lambda_ygm6np4pcqv31

static LispObject CC_lambda_ygm6np4pcqv31(LispObject env,
                         LispObject v_22093, LispObject v_22094)
{
    env = qenv(env);
    LispObject v_22104, v_22105;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22104 = v_22094;
    v_22105 = v_22093;
// end of prologue
    goto v_22101;
v_22097:
    goto v_22098;
v_22099:
    goto v_22100;
v_22101:
    goto v_22097;
v_22098:
    goto v_22099;
v_22100:
        return Lleq(nil, v_22105, v_22104);
}



// Code for assoc2

static LispObject CC_assoc2(LispObject env,
                         LispObject v_22093, LispObject v_22094)
{
    env = qenv(env);
    LispObject v_22122, v_22123, v_22124, v_22125;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22123 = v_22094;
    v_22124 = v_22093;
// end of prologue
v_22098:
    v_22122 = v_22123;
    if (v_22122 == nil) goto v_22101;
    else goto v_22102;
v_22101:
    v_22122 = nil;
    goto v_22097;
v_22102:
    goto v_22111;
v_22107:
    v_22125 = v_22124;
    goto v_22108;
v_22109:
    v_22122 = v_22123;
    v_22122 = qcar(v_22122);
    v_22122 = qcdr(v_22122);
    goto v_22110;
v_22111:
    goto v_22107;
v_22108:
    goto v_22109;
v_22110:
    if (equal(v_22125, v_22122)) goto v_22105;
    else goto v_22106;
v_22105:
    v_22122 = v_22123;
    v_22122 = qcar(v_22122);
    goto v_22097;
v_22106:
    v_22122 = v_22123;
    v_22122 = qcdr(v_22122);
    v_22123 = v_22122;
    goto v_22098;
    v_22122 = nil;
v_22097:
    return onevalue(v_22122);
}



// Code for lalr_make_compressed_goto_table

static LispObject CC_lalr_make_compressed_goto_table(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22156, v_22157, v_22158, v_22159;
    LispObject fn;
    argcheck(nargs, 0, "lalr_make_compressed_goto_table");
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
    v_22156 = qvalue(elt(env, 1)); // nonterminals
    v_22156 = Llength(nil, v_22156);
    env = stack[-3];
    v_22156 = sub1(v_22156);
    env = stack[-3];
    v_22156 = Lmkvect(nil, v_22156);
    env = stack[-3];
    stack[-2] = v_22156;
    v_22156 = qvalue(elt(env, 1)); // nonterminals
    stack[-1] = v_22156;
v_22105:
    v_22156 = stack[-1];
    if (v_22156 == nil) goto v_22109;
    else goto v_22110;
v_22109:
    goto v_22104;
v_22110:
    v_22156 = stack[-1];
    v_22156 = qcar(v_22156);
    stack[0] = v_22156;
    goto v_22124;
v_22120:
    v_22157 = stack[0];
    goto v_22121;
v_22122:
    v_22156 = elt(env, 2); // !S!'
    goto v_22123;
v_22124:
    goto v_22120;
v_22121:
    goto v_22122;
v_22123:
    if (v_22157 == v_22156) goto v_22119;
    v_22156 = stack[0];
    fn = elt(env, 5); // lalr_make_compressed_goto_column
    v_22156 = (*qfn1(fn))(fn, v_22156);
    env = stack[-3];
    v_22159 = v_22156;
    goto v_22135;
v_22129:
    v_22158 = stack[-2];
    goto v_22130;
v_22131:
    goto v_22142;
v_22138:
    v_22157 = stack[0];
    goto v_22139;
v_22140:
    v_22156 = elt(env, 3); // lalr_nonterminal_code
    goto v_22141;
v_22142:
    goto v_22138;
v_22139:
    goto v_22140;
v_22141:
    v_22156 = get(v_22157, v_22156);
    env = stack[-3];
    goto v_22132;
v_22133:
    v_22157 = v_22159;
    goto v_22134;
v_22135:
    goto v_22129;
v_22130:
    goto v_22131;
v_22132:
    goto v_22133;
v_22134:
    *(LispObject *)((char *)v_22158 + (CELL-TAG_VECTOR) + (((intptr_t)v_22156-TAG_FIXNUM)/(16/CELL))) = v_22157;
    goto v_22117;
v_22119:
v_22117:
    v_22156 = stack[-1];
    v_22156 = qcdr(v_22156);
    stack[-1] = v_22156;
    goto v_22105;
v_22104:
    v_22156 = qvalue(elt(env, 4)); // !*lalr_verbose
    if (v_22156 == nil) goto v_22151;
    v_22156 = stack[-2];
    fn = elt(env, 6); // lalr_print_compressed_goto_table
    v_22156 = (*qfn1(fn))(fn, v_22156);
    goto v_22149;
v_22151:
v_22149:
    v_22156 = stack[-2];
    return onevalue(v_22156);
}



// Code for get!-term!-n

static LispObject CC_getKtermKn(LispObject env,
                         LispObject v_22093, LispObject v_22094)
{
    env = qenv(env);
    LispObject v_22142, v_22143, v_22144, v_22145;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22093,v_22094);
    }
// copy arguments values to proper place
    v_22144 = v_22094;
    v_22145 = v_22093;
// end of prologue
v_22098:
    v_22142 = v_22144;
    if (v_22142 == nil) goto v_22105;
    else goto v_22106;
v_22105:
    v_22142 = lisp_true;
    goto v_22104;
v_22106:
    goto v_22115;
v_22111:
    v_22143 = v_22145;
    goto v_22112;
v_22113:
    v_22142 = v_22144;
    v_22142 = qcar(v_22142);
    v_22142 = qcar(v_22142);
    goto v_22114;
v_22115:
    goto v_22111;
v_22112:
    goto v_22113;
v_22114:
    v_22142 = ((intptr_t)v_22143 > (intptr_t)v_22142) ? lisp_true : nil;
    goto v_22104;
    v_22142 = nil;
v_22104:
    if (v_22142 == nil) goto v_22102;
    v_22142 = elt(env, 1); // no
    goto v_22097;
v_22102:
    goto v_22128;
v_22124:
    v_22142 = v_22144;
    v_22142 = qcar(v_22142);
    v_22143 = qcar(v_22142);
    goto v_22125;
v_22126:
    v_22142 = v_22145;
    goto v_22127;
v_22128:
    goto v_22124;
v_22125:
    goto v_22126;
v_22127:
    if (equal(v_22143, v_22142)) goto v_22122;
    else goto v_22123;
v_22122:
    v_22142 = v_22144;
    v_22142 = qcar(v_22142);
    v_22142 = qcdr(v_22142);
    v_22142 = ncons(v_22142);
    return ncons(v_22142);
v_22123:
    v_22142 = v_22144;
    v_22142 = qcdr(v_22142);
    v_22144 = v_22142;
    goto v_22098;
    v_22142 = nil;
v_22097:
    return onevalue(v_22142);
}



// Code for ofsf_qesubqat

static LispObject CC_ofsf_qesubqat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22290, v_22291, v_22292;
    LispObject fn;
    LispObject v_22095, v_22094, v_22093;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_qesubqat");
    va_start(aa, nargs);
    v_22093 = va_arg(aa, LispObject);
    v_22094 = va_arg(aa, LispObject);
    v_22095 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22095,v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22093,v_22094,v_22095);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_22095;
    stack[-1] = v_22094;
    stack[-2] = v_22093;
// end of prologue
    goto v_22110;
v_22106:
    stack[-3] = stack[-1];
    goto v_22107;
v_22108:
    v_22290 = stack[-2];
    fn = elt(env, 6); // ofsf_varlat
    v_22290 = (*qfn1(fn))(fn, v_22290);
    env = stack[-4];
    goto v_22109;
v_22110:
    goto v_22106;
v_22107:
    goto v_22108;
v_22109:
    v_22290 = Lmemq(nil, stack[-3], v_22290);
    if (v_22290 == nil) goto v_22104;
    else goto v_22105;
v_22104:
    v_22290 = stack[-2];
    goto v_22101;
v_22105:
    v_22290 = qvalue(elt(env, 1)); // !*rlqesubf
    if (v_22290 == nil) goto v_22119;
    goto v_22126;
v_22122:
    v_22290 = stack[-2];
    v_22290 = qcdr(v_22290);
    stack[-3] = qcar(v_22290);
    goto v_22123;
v_22124:
    goto v_22136;
v_22132:
    goto v_22133;
v_22134:
    v_22290 = stack[0];
    fn = elt(env, 7); // prepsq
    v_22290 = (*qfn1(fn))(fn, v_22290);
    env = stack[-4];
    goto v_22135;
v_22136:
    goto v_22132;
v_22133:
    goto v_22134;
v_22135:
    v_22290 = cons(stack[-1], v_22290);
    env = stack[-4];
    v_22290 = ncons(v_22290);
    env = stack[-4];
    goto v_22125;
v_22126:
    goto v_22122;
v_22123:
    goto v_22124;
v_22125:
    fn = elt(env, 8); // subf
    v_22290 = (*qfn2(fn))(fn, stack[-3], v_22290);
    env = stack[-4];
    goto v_22117;
v_22119:
    goto v_22149;
v_22143:
    v_22290 = stack[-2];
    v_22290 = qcdr(v_22290);
    v_22292 = qcar(v_22290);
    goto v_22144;
v_22145:
    v_22291 = stack[-1];
    goto v_22146;
v_22147:
    v_22290 = stack[0];
    goto v_22148;
v_22149:
    goto v_22143;
v_22144:
    goto v_22145;
v_22146:
    goto v_22147;
v_22148:
    fn = elt(env, 9); // ofsf_subf
    v_22290 = (*qfnn(fn))(fn, 3, v_22292, v_22291, v_22290);
    env = stack[-4];
    goto v_22117;
    v_22290 = nil;
v_22117:
    stack[-1] = v_22290;
    v_22290 = stack[-2];
    v_22290 = qcar(v_22290);
    stack[0] = v_22290;
    v_22290 = qvalue(elt(env, 2)); // !*rlqelocal
    if (v_22290 == nil) goto v_22160;
    goto v_22167;
v_22163:
    v_22291 = stack[0];
    goto v_22164;
v_22165:
    v_22290 = stack[-1];
    goto v_22166;
v_22167:
    goto v_22163;
v_22164:
    goto v_22165;
v_22166:
    {
        fn = elt(env, 10); // ofsf_qesubqat!-local
        return (*qfn2(fn))(fn, v_22291, v_22290);
    }
v_22160:
    goto v_22182;
v_22178:
    v_22291 = stack[0];
    goto v_22179;
v_22180:
    v_22290 = elt(env, 3); // equal
    goto v_22181;
v_22182:
    goto v_22178;
v_22179:
    goto v_22180;
v_22181:
    if (v_22291 == v_22290) goto v_22176;
    else goto v_22177;
v_22176:
    v_22290 = lisp_true;
    goto v_22175;
v_22177:
    goto v_22196;
v_22192:
    v_22291 = stack[0];
    goto v_22193;
v_22194:
    v_22290 = elt(env, 4); // neq
    goto v_22195;
v_22196:
    goto v_22192;
v_22193:
    goto v_22194;
v_22195:
    if (v_22291 == v_22290) goto v_22190;
    else goto v_22191;
v_22190:
    v_22290 = lisp_true;
    goto v_22189;
v_22191:
    goto v_22207;
v_22203:
    goto v_22215;
v_22209:
    v_22292 = elt(env, 5); // geq
    goto v_22210;
v_22211:
    v_22290 = stack[-1];
    v_22291 = qcdr(v_22290);
    goto v_22212;
v_22213:
    v_22290 = nil;
    goto v_22214;
v_22215:
    goto v_22209;
v_22210:
    goto v_22211;
v_22212:
    goto v_22213;
v_22214:
    v_22291 = list3(v_22292, v_22291, v_22290);
    env = stack[-4];
    goto v_22204;
v_22205:
    v_22290 = nil;
    goto v_22206;
v_22207:
    goto v_22203;
v_22204:
    goto v_22205;
v_22206:
    fn = elt(env, 11); // ofsf_surep
    v_22290 = (*qfn2(fn))(fn, v_22291, v_22290);
    env = stack[-4];
    goto v_22189;
    v_22290 = nil;
v_22189:
    goto v_22175;
    v_22290 = nil;
v_22175:
    if (v_22290 == nil) goto v_22173;
    goto v_22228;
v_22222:
    v_22292 = stack[0];
    goto v_22223;
v_22224:
    v_22290 = stack[-1];
    v_22291 = qcar(v_22290);
    goto v_22225;
v_22226:
    v_22290 = nil;
    goto v_22227;
v_22228:
    goto v_22222;
v_22223:
    goto v_22224;
v_22225:
    goto v_22226;
v_22227:
    return list3(v_22292, v_22291, v_22290);
v_22173:
    v_22290 = stack[-1];
    v_22290 = qcdr(v_22290);
    fn = elt(env, 12); // sfto_pdecf
    v_22290 = (*qfn1(fn))(fn, v_22290);
    env = stack[-4];
    v_22290 = qcar(v_22290);
    stack[-2] = v_22290;
    goto v_22246;
v_22242:
    goto v_22254;
v_22248:
    v_22292 = elt(env, 5); // geq
    goto v_22249;
v_22250:
    v_22291 = stack[-2];
    goto v_22251;
v_22252:
    v_22290 = nil;
    goto v_22253;
v_22254:
    goto v_22248;
v_22249:
    goto v_22250;
v_22251:
    goto v_22252;
v_22253:
    v_22291 = list3(v_22292, v_22291, v_22290);
    env = stack[-4];
    goto v_22243;
v_22244:
    v_22290 = nil;
    goto v_22245;
v_22246:
    goto v_22242;
v_22243:
    goto v_22244;
v_22245:
    fn = elt(env, 11); // ofsf_surep
    v_22290 = (*qfn2(fn))(fn, v_22291, v_22290);
    env = stack[-4];
    if (v_22290 == nil) goto v_22240;
    goto v_22266;
v_22260:
    v_22292 = stack[0];
    goto v_22261;
v_22262:
    v_22290 = stack[-1];
    v_22291 = qcar(v_22290);
    goto v_22263;
v_22264:
    v_22290 = nil;
    goto v_22265;
v_22266:
    goto v_22260;
v_22261:
    goto v_22262;
v_22263:
    goto v_22264;
v_22265:
    return list3(v_22292, v_22291, v_22290);
v_22240:
    goto v_22278;
v_22272:
    goto v_22273;
v_22274:
    goto v_22285;
v_22281:
    v_22290 = stack[-1];
    v_22291 = qcar(v_22290);
    goto v_22282;
v_22283:
    v_22290 = stack[-2];
    goto v_22284;
v_22285:
    goto v_22281;
v_22282:
    goto v_22283;
v_22284:
    fn = elt(env, 13); // multf
    v_22291 = (*qfn2(fn))(fn, v_22291, v_22290);
    goto v_22275;
v_22276:
    v_22290 = nil;
    goto v_22277;
v_22278:
    goto v_22272;
v_22273:
    goto v_22274;
v_22275:
    goto v_22276;
v_22277:
    {
        LispObject v_22297 = stack[0];
        return list3(v_22297, v_22291, v_22290);
    }
v_22101:
    return onevalue(v_22290);
}



// Code for tayfkern

static LispObject CC_tayfkern(LispObject env,
                         LispObject v_22093)
{
    env = qenv(env);
    LispObject v_22156, v_22157, v_22158;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22093);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_22158 = v_22093;
// end of prologue
    v_22156 = qvalue(elt(env, 1)); // !*tayinternal!*
    if (v_22156 == nil) goto v_22102;
    v_22156 = v_22158;
    goto v_22098;
v_22102:
    v_22156 = elt(env, 2); // taylor!*
    if (!symbolp(v_22156)) v_22156 = nil;
    else { v_22156 = qfastgets(v_22156);
           if (v_22156 != nil) { v_22156 = elt(v_22156, 24); // klist
#ifdef RECORD_GET
             if (v_22156 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v_22156 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v_22156 == SPID_NOPROP) v_22156 = nil; }}
#endif
    stack[0] = v_22156;
    goto v_22111;
v_22107:
    v_22157 = v_22158;
    goto v_22108;
v_22109:
    v_22156 = stack[0];
    goto v_22110;
v_22111:
    goto v_22107;
v_22108:
    goto v_22109;
v_22110:
    v_22156 = Lassoc(nil, v_22157, v_22156);
    stack[-1] = v_22156;
    v_22156 = stack[-1];
    if (v_22156 == nil) goto v_22117;
    else goto v_22118;
v_22117:
    goto v_22125;
v_22121:
    v_22157 = v_22158;
    goto v_22122;
v_22123:
    v_22156 = nil;
    goto v_22124;
v_22125:
    goto v_22121;
v_22122:
    goto v_22123;
v_22124:
    v_22156 = list2(v_22157, v_22156);
    env = stack[-2];
    stack[-1] = v_22156;
    goto v_22133;
v_22129:
    v_22157 = stack[-1];
    goto v_22130;
v_22131:
    v_22156 = stack[0];
    goto v_22132;
v_22133:
    goto v_22129;
v_22130:
    goto v_22131;
v_22132:
    fn = elt(env, 6); // ordad
    v_22156 = (*qfn2(fn))(fn, v_22157, v_22156);
    env = stack[-2];
    stack[0] = v_22156;
    goto v_22141;
v_22137:
    v_22157 = elt(env, 3); // (taylor!*)
    goto v_22138;
v_22139:
    v_22156 = qvalue(elt(env, 4)); // kprops!*
    goto v_22140;
v_22141:
    goto v_22137;
v_22138:
    goto v_22139;
v_22140:
    fn = elt(env, 7); // union
    v_22156 = (*qfn2(fn))(fn, v_22157, v_22156);
    env = stack[-2];
    qvalue(elt(env, 4)) = v_22156; // kprops!*
    goto v_22151;
v_22145:
    v_22158 = elt(env, 2); // taylor!*
    goto v_22146;
v_22147:
    v_22157 = elt(env, 5); // klist
    goto v_22148;
v_22149:
    v_22156 = stack[0];
    goto v_22150;
v_22151:
    goto v_22145;
v_22146:
    goto v_22147;
v_22148:
    goto v_22149;
v_22150:
    v_22156 = Lputprop(nil, 3, v_22158, v_22157, v_22156);
    goto v_22116;
v_22118:
v_22116:
    v_22156 = stack[-1];
v_22098:
    return onevalue(v_22156);
}



// Code for my!+nullsq!+p

static LispObject CC_myLnullsqLp(LispObject env,
                         LispObject v_22093)
{
    env = qenv(env);
    LispObject v_22104;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22104 = v_22093;
// end of prologue
    v_22104 = qcar(v_22104);
    if (v_22104 == nil) goto v_22099;
    else goto v_22100;
v_22099:
    v_22104 = lisp_true;
    goto v_22096;
v_22100:
    v_22104 = nil;
v_22096:
    return onevalue(v_22104);
}



// Code for mri_ofsf2mriat

static LispObject CC_mri_ofsf2mriat(LispObject env,
                         LispObject v_22093, LispObject v_22094)
{
    env = qenv(env);
    LispObject v_22110, v_22111, v_22112;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22110 = v_22094;
    v_22111 = v_22093;
// end of prologue
    goto v_22103;
v_22097:
    v_22112 = v_22111;
    v_22112 = qcar(v_22112);
    goto v_22098;
v_22099:
    v_22111 = qcdr(v_22111);
    v_22111 = qcar(v_22111);
    goto v_22100;
v_22101:
    goto v_22102;
v_22103:
    goto v_22097;
v_22098:
    goto v_22099;
v_22100:
    goto v_22101;
v_22102:
    {
        fn = elt(env, 1); // mri_0mk2
        return (*qfnn(fn))(fn, 3, v_22112, v_22111, v_22110);
    }
}



// Code for dvfsf_smupdknowl

static LispObject CC_dvfsf_smupdknowl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22133, v_22134, v_22135, v_22136, v_22137;
    LispObject fn;
    LispObject v_22096, v_22095, v_22094, v_22093;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "dvfsf_smupdknowl");
    va_start(aa, nargs);
    v_22093 = va_arg(aa, LispObject);
    v_22094 = va_arg(aa, LispObject);
    v_22095 = va_arg(aa, LispObject);
    v_22096 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22134 = v_22096;
    v_22135 = v_22095;
    v_22136 = v_22094;
    v_22137 = v_22093;
// end of prologue
    v_22133 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_22133 == nil) goto v_22101;
    goto v_22112;
v_22104:
    v_22133 = v_22137;
    goto v_22105;
v_22106:
    goto v_22107;
v_22108:
    goto v_22109;
v_22110:
    goto v_22111;
v_22112:
    goto v_22104;
v_22105:
    goto v_22106;
v_22107:
    goto v_22108;
v_22109:
    goto v_22110;
v_22111:
    {
        fn = elt(env, 2); // cl_susiupdknowl
        return (*qfnn(fn))(fn, 4, v_22133, v_22136, v_22135, v_22134);
    }
v_22101:
    goto v_22128;
v_22120:
    v_22133 = v_22137;
    goto v_22121;
v_22122:
    goto v_22123;
v_22124:
    goto v_22125;
v_22126:
    goto v_22127;
v_22128:
    goto v_22120;
v_22121:
    goto v_22122;
v_22123:
    goto v_22124;
v_22125:
    goto v_22126;
v_22127:
    {
        fn = elt(env, 3); // cl_smupdknowl
        return (*qfnn(fn))(fn, 4, v_22133, v_22136, v_22135, v_22134);
    }
    v_22133 = nil;
    return onevalue(v_22133);
}



// Code for intervalom

static LispObject CC_intervalom(LispObject env,
                         LispObject v_22093)
{
    env = qenv(env);
    LispObject v_22185, v_22186, v_22187;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22093);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_22093;
// end of prologue
    v_22185 = stack[-2];
    v_22185 = qcdr(v_22185);
    v_22185 = qcar(v_22185);
    stack[-3] = v_22185;
    v_22185 = stack[-2];
    v_22185 = qcar(v_22185);
    stack[-1] = v_22185;
    goto v_22114;
v_22110:
    v_22186 = stack[-1];
    goto v_22111;
v_22112:
    v_22185 = elt(env, 1); // lowupperlimit
    goto v_22113;
v_22114:
    goto v_22110;
v_22111:
    goto v_22112;
v_22113:
    if (v_22186 == v_22185) goto v_22108;
    else goto v_22109;
v_22108:
    v_22185 = elt(env, 2); // integer_interval
    stack[-1] = v_22185;
    v_22185 = nil;
    stack[-3] = v_22185;
    goto v_22126;
v_22120:
    v_22185 = stack[-2];
    v_22187 = qcar(v_22185);
    goto v_22121;
v_22122:
    v_22186 = nil;
    goto v_22123;
v_22124:
    v_22185 = stack[-2];
    v_22185 = qcdr(v_22185);
    goto v_22125;
v_22126:
    goto v_22120;
v_22121:
    goto v_22122;
v_22123:
    goto v_22124;
v_22125:
    v_22185 = list2star(v_22187, v_22186, v_22185);
    env = stack[-4];
    stack[-2] = v_22185;
    goto v_22107;
v_22109:
v_22107:
    goto v_22136;
v_22132:
    v_22186 = stack[-1];
    goto v_22133;
v_22134:
    v_22185 = qvalue(elt(env, 3)); // valid_om!*
    goto v_22135;
v_22136:
    goto v_22132;
v_22133:
    goto v_22134;
v_22135:
    v_22185 = Lassoc(nil, v_22186, v_22185);
    v_22185 = qcdr(v_22185);
    v_22185 = qcar(v_22185);
    stack[0] = v_22185;
    v_22185 = stack[-3];
    if (v_22185 == nil) goto v_22145;
    goto v_22151;
v_22147:
    v_22185 = stack[-3];
    v_22185 = qcar(v_22185);
    v_22185 = qcdr(v_22185);
    v_22185 = qcar(v_22185);
    v_22186 = Lintern(nil, v_22185);
    env = stack[-4];
    goto v_22148;
v_22149:
    v_22185 = qvalue(elt(env, 4)); // interval!*
    goto v_22150;
v_22151:
    goto v_22147;
v_22148:
    goto v_22149;
v_22150:
    v_22185 = Lassoc(nil, v_22186, v_22185);
    v_22185 = qcdr(v_22185);
    v_22185 = qcar(v_22185);
    stack[-1] = v_22185;
    goto v_22143;
v_22145:
v_22143:
    v_22185 = elt(env, 5); // "<OMA>"
    fn = elt(env, 10); // printout
    v_22185 = (*qfn1(fn))(fn, v_22185);
    env = stack[-4];
    v_22185 = lisp_true;
    fn = elt(env, 11); // indent!*
    v_22185 = (*qfn1(fn))(fn, v_22185);
    env = stack[-4];
    v_22185 = elt(env, 6); // "<OMS cd="""
    fn = elt(env, 10); // printout
    v_22185 = (*qfn1(fn))(fn, v_22185);
    env = stack[-4];
    v_22185 = stack[0];
    v_22185 = Lprinc(nil, v_22185);
    env = stack[-4];
    v_22185 = elt(env, 7); // """ name="""
    v_22185 = Lprinc(nil, v_22185);
    env = stack[-4];
    v_22185 = stack[-1];
    v_22185 = Lprinc(nil, v_22185);
    env = stack[-4];
    v_22185 = elt(env, 8); // """/>"
    v_22185 = Lprinc(nil, v_22185);
    env = stack[-4];
    v_22185 = stack[-2];
    v_22185 = qcdr(v_22185);
    v_22185 = qcdr(v_22185);
    fn = elt(env, 12); // multiom
    v_22185 = (*qfn1(fn))(fn, v_22185);
    env = stack[-4];
    v_22185 = nil;
    fn = elt(env, 11); // indent!*
    v_22185 = (*qfn1(fn))(fn, v_22185);
    env = stack[-4];
    v_22185 = elt(env, 9); // "</OMA>"
    fn = elt(env, 10); // printout
    v_22185 = (*qfn1(fn))(fn, v_22185);
    v_22185 = nil;
    return onevalue(v_22185);
}



// Code for sptransmat

static LispObject CC_sptransmat(LispObject env,
                         LispObject v_22093)
{
    env = qenv(env);
    LispObject v_22250, v_22251, v_22252, v_22253;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22093);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-1] = v_22093;
// end of prologue
    v_22250 = stack[-1];
    v_22250 = Lconsp(nil, v_22250);
    env = stack[-7];
    if (v_22250 == nil) goto v_22108;
    v_22250 = stack[-1];
    stack[0] = v_22250;
    v_22250 = stack[-1];
    fn = elt(env, 2); // matlength
    v_22250 = (*qfn1(fn))(fn, v_22250);
    env = stack[-7];
    v_22250 = qcdr(v_22250);
    goto v_22106;
v_22108:
    v_22250 = stack[-1];
    fn = elt(env, 3); // aeval
    v_22250 = (*qfn1(fn))(fn, v_22250);
    env = stack[-7];
    stack[0] = v_22250;
    v_22250 = stack[-1];
    fn = elt(env, 3); // aeval
    v_22250 = (*qfn1(fn))(fn, v_22250);
    env = stack[-7];
    fn = elt(env, 2); // matlength
    v_22250 = (*qfn1(fn))(fn, v_22250);
    env = stack[-7];
    v_22250 = qcdr(v_22250);
    goto v_22106;
v_22106:
    v_22251 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_22251;
    v_22251 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_22251;
    goto v_22130;
v_22126:
    v_22251 = v_22250;
    stack[-1] = qcar(v_22251);
    goto v_22127;
v_22128:
    goto v_22138;
v_22134:
    v_22251 = elt(env, 1); // spm
    goto v_22135;
v_22136:
    goto v_22137;
v_22138:
    goto v_22134;
v_22135:
    goto v_22136;
v_22137:
    v_22250 = cons(v_22251, v_22250);
    env = stack[-7];
    goto v_22129;
v_22130:
    goto v_22126;
v_22127:
    goto v_22128;
v_22129:
    fn = elt(env, 4); // mkempspmat
    v_22250 = (*qfn2(fn))(fn, stack[-1], v_22250);
    env = stack[-7];
    stack[-2] = v_22250;
    v_22250 = nil;
    v_22250 = ncons(v_22250);
    env = stack[-7];
    v_22250 = ncons(v_22250);
    env = stack[-7];
    stack[-3] = v_22250;
    v_22250 = stack[0];
    v_22250 = qcdr(v_22250);
    stack[-1] = v_22250;
v_22147:
    v_22250 = stack[-1];
    if (v_22250 == nil) goto v_22152;
    else goto v_22153;
v_22152:
    goto v_22146;
v_22153:
    v_22250 = stack[-1];
    v_22250 = qcar(v_22250);
    stack[0] = v_22250;
    v_22250 = stack[-6];
    v_22250 = add1(v_22250);
    env = stack[-7];
    stack[-6] = v_22250;
    v_22250 = stack[0];
    stack[0] = v_22250;
v_22165:
    v_22250 = stack[0];
    if (v_22250 == nil) goto v_22169;
    else goto v_22170;
v_22169:
    goto v_22164;
v_22170:
    v_22250 = stack[0];
    v_22250 = qcar(v_22250);
    stack[-4] = v_22250;
    v_22250 = stack[-5];
    v_22250 = add1(v_22250);
    env = stack[-7];
    stack[-5] = v_22250;
    goto v_22187;
v_22183:
    v_22251 = stack[-4];
    goto v_22184;
v_22185:
    v_22250 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22186;
v_22187:
    goto v_22183;
v_22184:
    goto v_22185;
v_22186:
    if (v_22251 == v_22250) goto v_22181;
    else goto v_22182;
v_22181:
    goto v_22180;
v_22182:
    goto v_22200;
v_22194:
    v_22252 = stack[-5];
    goto v_22195;
v_22196:
    v_22251 = stack[-4];
    goto v_22197;
v_22198:
    v_22250 = stack[-3];
    goto v_22199;
v_22200:
    goto v_22194;
v_22195:
    goto v_22196;
v_22197:
    goto v_22198;
v_22199:
    v_22250 = acons(v_22252, v_22251, v_22250);
    env = stack[-7];
    stack[-3] = v_22250;
    goto v_22180;
v_22180:
    v_22250 = stack[0];
    v_22250 = qcdr(v_22250);
    stack[0] = v_22250;
    goto v_22165;
v_22164:
    v_22250 = stack[-3];
    v_22250 = Lreverse(nil, v_22250);
    env = stack[-7];
    stack[-3] = v_22250;
    goto v_22216;
v_22212:
    stack[0] = stack[-3];
    goto v_22213;
v_22214:
    v_22250 = nil;
    v_22250 = ncons(v_22250);
    env = stack[-7];
    v_22250 = ncons(v_22250);
    env = stack[-7];
    goto v_22215;
v_22216:
    goto v_22212;
v_22213:
    goto v_22214;
v_22215:
    if (equal(stack[0], v_22250)) goto v_22211;
    goto v_22230;
v_22222:
    goto v_22236;
v_22232:
    v_22251 = stack[-2];
    goto v_22233;
v_22234:
    v_22250 = stack[-6];
    goto v_22235;
v_22236:
    goto v_22232;
v_22233:
    goto v_22234;
v_22235:
    v_22253 = list2(v_22251, v_22250);
    env = stack[-7];
    goto v_22223;
v_22224:
    v_22252 = stack[-3];
    goto v_22225;
v_22226:
    v_22251 = stack[-2];
    goto v_22227;
v_22228:
    v_22250 = nil;
    goto v_22229;
v_22230:
    goto v_22222;
v_22223:
    goto v_22224;
v_22225:
    goto v_22226;
v_22227:
    goto v_22228;
v_22229:
    fn = elt(env, 5); // letmtr3
    v_22250 = (*qfnn(fn))(fn, 4, v_22253, v_22252, v_22251, v_22250);
    env = stack[-7];
    goto v_22209;
v_22211:
v_22209:
    v_22250 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_22250;
    v_22250 = nil;
    v_22250 = ncons(v_22250);
    env = stack[-7];
    v_22250 = ncons(v_22250);
    env = stack[-7];
    stack[-3] = v_22250;
    v_22250 = stack[-1];
    v_22250 = qcdr(v_22250);
    stack[-1] = v_22250;
    goto v_22147;
v_22146:
    v_22250 = stack[-2];
    return onevalue(v_22250);
}



// Code for groebspolynom3

static LispObject CC_groebspolynom3(LispObject env,
                         LispObject v_22093, LispObject v_22094)
{
    env = qenv(env);
    LispObject v_22110, v_22111;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22093,v_22094);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_22110 = v_22094;
    v_22111 = v_22093;
// end of prologue
    goto v_22104;
v_22100:
    goto v_22101;
v_22102:
    goto v_22103;
v_22104:
    goto v_22100;
v_22101:
    goto v_22102;
v_22103:
    fn = elt(env, 1); // groebspolynom4
    v_22110 = (*qfn2(fn))(fn, v_22111, v_22110);
    env = stack[-1];
    stack[0] = v_22110;
    v_22110 = stack[0];
    fn = elt(env, 2); // groebsavelterm
    v_22110 = (*qfn1(fn))(fn, v_22110);
    v_22110 = stack[0];
    return onevalue(v_22110);
}



// Code for exdfprn

static LispObject CC_exdfprn(LispObject env,
                         LispObject v_22093)
{
    env = qenv(env);
    LispObject v_22101;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22093);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_22093;
// end of prologue
    v_22101 = elt(env, 1); // "d"
    fn = elt(env, 2); // prin2!*
    v_22101 = (*qfn1(fn))(fn, v_22101);
    env = stack[-1];
    v_22101 = stack[0];
    v_22101 = qcdr(v_22101);
    v_22101 = qcar(v_22101);
    {
        fn = elt(env, 3); // rembras
        return (*qfn1(fn))(fn, v_22101);
    }
}



// Code for multiply!-by!-power!-of!-ten

static LispObject CC_multiplyKbyKpowerKofKten(LispObject env,
                         LispObject v_22093, LispObject v_22094)
{
    env = qenv(env);
    LispObject v_22178, v_22179;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22093,v_22094);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_22094;
    stack[-1] = v_22093;
// end of prologue
    goto v_22105;
v_22101:
    v_22179 = stack[0];
    goto v_22102;
v_22103:
    v_22178 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22104;
v_22105:
    goto v_22101;
v_22102:
    goto v_22103;
v_22104:
    v_22178 = (LispObject)lessp2(v_22179, v_22178);
    v_22178 = v_22178 ? lisp_true : nil;
    env = stack[-3];
    if (v_22178 == nil) goto v_22099;
    v_22178 = elt(env, 0); // multiply!-by!-power!-of!-ten
    {
        fn = elt(env, 3); // bflerrmsg
        return (*qfn1(fn))(fn, v_22178);
    }
v_22099:
    v_22178 = qvalue(elt(env, 1)); // bften!*
    stack[-2] = v_22178;
v_22116:
    goto v_22126;
v_22122:
    v_22179 = stack[0];
    goto v_22123;
v_22124:
    v_22178 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22125;
v_22126:
    goto v_22122;
v_22123:
    goto v_22124;
v_22125:
    v_22178 = (LispObject)greaterp2(v_22179, v_22178);
    v_22178 = v_22178 ? lisp_true : nil;
    env = stack[-3];
    if (v_22178 == nil) goto v_22119;
    else goto v_22120;
v_22119:
    goto v_22115;
v_22120:
    v_22178 = stack[0];
    v_22178 = Levenp(nil, v_22178);
    env = stack[-3];
    if (v_22178 == nil) goto v_22132;
    else goto v_22133;
v_22132:
    goto v_22142;
v_22138:
    v_22179 = stack[-1];
    goto v_22139;
v_22140:
    v_22178 = stack[-2];
    goto v_22141;
v_22142:
    goto v_22138;
v_22139:
    goto v_22140;
v_22141:
    fn = elt(env, 4); // times!:
    v_22178 = (*qfn2(fn))(fn, v_22179, v_22178);
    env = stack[-3];
    fn = elt(env, 5); // normbf
    v_22178 = (*qfn1(fn))(fn, v_22178);
    env = stack[-3];
    stack[-1] = v_22178;
    goto v_22131;
v_22133:
v_22131:
    goto v_22150;
v_22146:
    v_22179 = stack[0];
    goto v_22147;
v_22148:
    v_22178 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_22149;
v_22150:
    goto v_22146;
v_22147:
    goto v_22148;
v_22149:
    fn = elt(env, 6); // lshift
    v_22178 = (*qfn2(fn))(fn, v_22179, v_22178);
    env = stack[-3];
    stack[0] = v_22178;
    goto v_22159;
v_22155:
    goto v_22165;
v_22161:
    v_22179 = stack[-2];
    goto v_22162;
v_22163:
    v_22178 = stack[-2];
    goto v_22164;
v_22165:
    goto v_22161;
v_22162:
    goto v_22163;
v_22164:
    fn = elt(env, 4); // times!:
    v_22179 = (*qfn2(fn))(fn, v_22179, v_22178);
    env = stack[-3];
    goto v_22156;
v_22157:
    v_22178 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_22158;
v_22159:
    goto v_22155;
v_22156:
    goto v_22157;
v_22158:
    fn = elt(env, 7); // cut!:mt
    v_22178 = (*qfn2(fn))(fn, v_22179, v_22178);
    env = stack[-3];
    fn = elt(env, 5); // normbf
    v_22178 = (*qfn1(fn))(fn, v_22178);
    env = stack[-3];
    stack[-2] = v_22178;
    goto v_22116;
v_22115:
    goto v_22175;
v_22171:
    v_22179 = stack[-1];
    goto v_22172;
v_22173:
    v_22178 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_22174;
v_22175:
    goto v_22171;
v_22172:
    goto v_22173;
v_22174:
    fn = elt(env, 7); // cut!:mt
    v_22178 = (*qfn2(fn))(fn, v_22179, v_22178);
    env = stack[-3];
    {
        fn = elt(env, 5); // normbf
        return (*qfn1(fn))(fn, v_22178);
    }
    v_22178 = nil;
    return onevalue(v_22178);
}



// Code for toolongassignp

static LispObject CC_toolongassignp(LispObject env,
                         LispObject v_22093)
{
    env = qenv(env);
    LispObject v_22100;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22100 = v_22093;
// end of prologue
    v_22100 = qcdr(v_22100);
    v_22100 = qcdr(v_22100);
    v_22100 = qcar(v_22100);
    {
        fn = elt(env, 1); // toolongexpp
        return (*qfn1(fn))(fn, v_22100);
    }
}



// Code for simppartdf

static LispObject CC_simppartdf(LispObject env,
                         LispObject v_22093)
{
    env = qenv(env);
    LispObject v_22098;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22093);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_22098 = v_22093;
// end of prologue
    fn = elt(env, 1); // partitpartdf
    v_22098 = (*qfn1(fn))(fn, v_22098);
    env = stack[0];
    {
        fn = elt(env, 2); // !*pf2sq
        return (*qfn1(fn))(fn, v_22098);
    }
}



// Code for lf!=zero

static LispObject CC_lfMzero(LispObject env,
                         LispObject v_22093)
{
    env = qenv(env);
    LispObject v_22098;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22098 = v_22093;
// end of prologue
    v_22098 = qcdr(v_22098);
    v_22098 = (v_22098 == nil ? lisp_true : nil);
    return onevalue(v_22098);
}



// Code for vector!-to!-poly

static LispObject CC_vectorKtoKpoly(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22186, v_22187, v_22188;
    LispObject fn;
    LispObject v_22095, v_22094, v_22093;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "vector-to-poly");
    va_start(aa, nargs);
    v_22093 = va_arg(aa, LispObject);
    v_22094 = va_arg(aa, LispObject);
    v_22095 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22095,v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22093,v_22094,v_22095);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_22095;
    stack[-2] = v_22094;
    stack[-3] = v_22093;
// end of prologue
    goto v_22108;
v_22104:
    v_22187 = stack[-2];
    goto v_22105;
v_22106:
    v_22186 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22107;
v_22108:
    goto v_22104;
v_22105:
    goto v_22106;
v_22107:
    if (((intptr_t)(v_22187)) < ((intptr_t)(v_22186))) goto v_22102;
    else goto v_22103;
v_22102:
    v_22186 = nil;
    goto v_22099;
v_22103:
    goto v_22117;
v_22113:
    v_22187 = stack[-3];
    goto v_22114;
v_22115:
    v_22186 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22116;
v_22117:
    goto v_22113;
v_22114:
    goto v_22115;
v_22116:
    v_22186 = *(LispObject *)((char *)v_22187 + (CELL-TAG_VECTOR) + (((intptr_t)v_22186-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 1); // !*n2f
    v_22186 = (*qfn1(fn))(fn, v_22186);
    env = stack[-5];
    stack[-4] = v_22186;
    v_22186 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_22186;
v_22124:
    goto v_22136;
v_22132:
    v_22187 = stack[-2];
    goto v_22133;
v_22134:
    v_22186 = stack[0];
    goto v_22135;
v_22136:
    goto v_22132;
v_22133:
    goto v_22134;
v_22135:
    v_22186 = difference2(v_22187, v_22186);
    env = stack[-5];
    v_22186 = Lminusp(nil, v_22186);
    env = stack[-5];
    if (v_22186 == nil) goto v_22129;
    goto v_22123;
v_22129:
    goto v_22148;
v_22144:
    goto v_22153;
v_22149:
    v_22187 = stack[-3];
    goto v_22150;
v_22151:
    v_22186 = stack[0];
    goto v_22152;
v_22153:
    goto v_22149;
v_22150:
    goto v_22151;
v_22152:
    v_22187 = *(LispObject *)((char *)v_22187 + (CELL-TAG_VECTOR) + (((intptr_t)v_22186-TAG_FIXNUM)/(16/CELL)));
    goto v_22145;
v_22146:
    v_22186 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22147;
v_22148:
    goto v_22144;
v_22145:
    goto v_22146;
v_22147:
    if (v_22187 == v_22186) goto v_22143;
    goto v_22165;
v_22159:
    goto v_22171;
v_22167:
    v_22187 = stack[-1];
    goto v_22168;
v_22169:
    v_22186 = stack[0];
    goto v_22170;
v_22171:
    goto v_22167;
v_22168:
    goto v_22169;
v_22170:
    fn = elt(env, 2); // to
    v_22188 = (*qfn2(fn))(fn, v_22187, v_22186);
    env = stack[-5];
    goto v_22160;
v_22161:
    goto v_22178;
v_22174:
    v_22187 = stack[-3];
    goto v_22175;
v_22176:
    v_22186 = stack[0];
    goto v_22177;
v_22178:
    goto v_22174;
v_22175:
    goto v_22176;
v_22177:
    v_22187 = *(LispObject *)((char *)v_22187 + (CELL-TAG_VECTOR) + (((intptr_t)v_22186-TAG_FIXNUM)/(16/CELL)));
    goto v_22162;
v_22163:
    v_22186 = stack[-4];
    goto v_22164;
v_22165:
    goto v_22159;
v_22160:
    goto v_22161;
v_22162:
    goto v_22163;
v_22164:
    v_22186 = acons(v_22188, v_22187, v_22186);
    env = stack[-5];
    stack[-4] = v_22186;
    goto v_22141;
v_22143:
v_22141:
    v_22186 = stack[0];
    v_22186 = add1(v_22186);
    env = stack[-5];
    stack[0] = v_22186;
    goto v_22124;
v_22123:
    v_22186 = stack[-4];
v_22099:
    return onevalue(v_22186);
}



// Code for setqinsertlist

static LispObject CC_setqinsertlist(LispObject env,
                         LispObject v_22093)
{
    env = qenv(env);
    LispObject v_22240, v_22241, v_22242;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22093);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_22241 = v_22093;
// end of prologue
    v_22240 = qvalue(elt(env, 1)); // fluidbibasissetq
    stack[-2] = v_22240;
    v_22240 = v_22241;
    stack[-1] = v_22240;
v_22105:
    v_22240 = stack[-2];
    v_22240 = qcar(v_22240);
    if (v_22240 == nil) goto v_22108;
    v_22240 = stack[-1];
    v_22240 = qcar(v_22240);
    if (v_22240 == nil) goto v_22108;
    goto v_22109;
v_22108:
    goto v_22104;
v_22109:
    goto v_22122;
v_22118:
    goto v_22127;
v_22123:
    v_22240 = stack[-2];
    v_22241 = qcar(v_22240);
    goto v_22124;
v_22125:
    v_22240 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22126;
v_22127:
    goto v_22123;
v_22124:
    goto v_22125;
v_22126:
    v_22240 = *(LispObject *)((char *)v_22241 + (CELL-TAG_VECTOR) + (((intptr_t)v_22240-TAG_FIXNUM)/(16/CELL)));
    v_22242 = qcar(v_22240);
    goto v_22119;
v_22120:
    goto v_22137;
v_22133:
    v_22240 = stack[-1];
    v_22241 = qcar(v_22240);
    goto v_22134;
v_22135:
    v_22240 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22136;
v_22137:
    goto v_22133;
v_22134:
    goto v_22135;
v_22136:
    v_22240 = *(LispObject *)((char *)v_22241 + (CELL-TAG_VECTOR) + (((intptr_t)v_22240-TAG_FIXNUM)/(16/CELL)));
    v_22240 = qcar(v_22240);
    goto v_22121;
v_22122:
    goto v_22118;
v_22119:
    goto v_22120;
v_22121:
    fn = elt(env, 2); // monomcompare
    v_22240 = (*qfn2(fn))(fn, v_22242, v_22240);
    env = stack[-3];
    v_22242 = v_22240;
    goto v_22155;
v_22151:
    v_22241 = v_22242;
    goto v_22152;
v_22153:
    v_22240 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_22154;
v_22155:
    goto v_22151;
v_22152:
    goto v_22153;
v_22154:
    if (v_22241 == v_22240) goto v_22149;
    else goto v_22150;
v_22149:
    v_22240 = lisp_true;
    goto v_22148;
v_22150:
    goto v_22165;
v_22161:
    v_22241 = v_22242;
    goto v_22162;
v_22163:
    v_22240 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22164;
v_22165:
    goto v_22161;
v_22162:
    goto v_22163;
v_22164:
    v_22240 = (v_22241 == v_22240 ? lisp_true : nil);
    goto v_22148;
    v_22240 = nil;
v_22148:
    if (v_22240 == nil) goto v_22146;
    v_22240 = stack[-2];
    v_22240 = qcdr(v_22240);
    stack[-2] = v_22240;
    goto v_22144;
v_22146:
    goto v_22179;
v_22175:
    goto v_22185;
v_22181:
    stack[0] = stack[-2];
    goto v_22182;
v_22183:
    goto v_22192;
v_22188:
    v_22240 = stack[-2];
    v_22241 = qcar(v_22240);
    goto v_22189;
v_22190:
    v_22240 = stack[-2];
    v_22240 = qcdr(v_22240);
    goto v_22191;
v_22192:
    goto v_22188;
v_22189:
    goto v_22190;
v_22191:
    v_22240 = cons(v_22241, v_22240);
    env = stack[-3];
    goto v_22184;
v_22185:
    goto v_22181;
v_22182:
    goto v_22183;
v_22184:
    v_22241 = Lrplacd(nil, stack[0], v_22240);
    env = stack[-3];
    goto v_22176;
v_22177:
    v_22240 = stack[-1];
    v_22240 = qcar(v_22240);
    goto v_22178;
v_22179:
    goto v_22175;
v_22176:
    goto v_22177;
v_22178:
    v_22240 = Lrplaca(nil, v_22241, v_22240);
    env = stack[-3];
    v_22240 = stack[-2];
    v_22240 = qcdr(v_22240);
    stack[-2] = v_22240;
    v_22240 = stack[-1];
    v_22240 = qcdr(v_22240);
    stack[-1] = v_22240;
    goto v_22144;
v_22144:
    goto v_22105;
v_22104:
    v_22240 = stack[-1];
    v_22240 = qcar(v_22240);
    if (v_22240 == nil) goto v_22208;
    goto v_22216;
v_22212:
    v_22241 = stack[-2];
    goto v_22213;
v_22214:
    v_22240 = stack[-1];
    goto v_22215;
v_22216:
    goto v_22212;
v_22213:
    goto v_22214;
v_22215:
    v_22240 = Lrplacd(nil, v_22241, v_22240);
    env = stack[-3];
    stack[0] = v_22240;
    goto v_22225;
v_22221:
    goto v_22231;
v_22227:
    v_22241 = stack[0];
    goto v_22228;
v_22229:
    v_22240 = stack[0];
    v_22240 = qcdr(v_22240);
    v_22240 = qcar(v_22240);
    goto v_22230;
v_22231:
    goto v_22227;
v_22228:
    goto v_22229;
v_22230:
    v_22241 = Lrplaca(nil, v_22241, v_22240);
    env = stack[-3];
    goto v_22222;
v_22223:
    v_22240 = stack[0];
    v_22240 = qcdr(v_22240);
    v_22240 = qcdr(v_22240);
    goto v_22224;
v_22225:
    goto v_22221;
v_22222:
    goto v_22223;
v_22224:
    v_22240 = Lrplacd(nil, v_22241, v_22240);
    goto v_22206;
v_22208:
v_22206:
    v_22240 = nil;
    return onevalue(v_22240);
}



// Code for processpartitie1list1

static LispObject CC_processpartitie1list1(LispObject env,
                         LispObject v_22093, LispObject v_22094)
{
    env = qenv(env);
    LispObject v_22130, v_22131;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22093,v_22094);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_22094;
    v_22130 = v_22093;
// end of prologue
v_22099:
    v_22131 = v_22130;
    if (v_22131 == nil) goto v_22102;
    else goto v_22103;
v_22102:
    v_22130 = stack[-3];
    goto v_22098;
v_22103:
    v_22131 = v_22130;
    v_22131 = qcdr(v_22131);
    stack[-4] = v_22131;
    goto v_22121;
v_22111:
    stack[-2] = qcar(v_22130);
    goto v_22112;
v_22113:
    stack[-1] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22114;
v_22115:
    stack[0] = nil;
    goto v_22116;
v_22117:
    v_22130 = nil;
    v_22131 = ncons(v_22130);
    env = stack[-5];
    goto v_22118;
v_22119:
    v_22130 = stack[-3];
    goto v_22120;
v_22121:
    goto v_22111;
v_22112:
    goto v_22113;
v_22114:
    goto v_22115;
v_22116:
    goto v_22117;
v_22118:
    goto v_22119;
v_22120:
    fn = elt(env, 1); // processpartitie1
    v_22130 = (*qfnn(fn))(fn, 5, stack[-2], stack[-1], stack[0], v_22131, v_22130);
    env = stack[-5];
    stack[-3] = v_22130;
    v_22130 = stack[-4];
    goto v_22099;
    v_22130 = nil;
v_22098:
    return onevalue(v_22130);
}



// Code for pickbasicset

static LispObject CC_pickbasicset(LispObject env,
                         LispObject v_22093)
{
    env = qenv(env);
    LispObject v_22211, v_22212;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22093);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_22093;
// end of prologue
    stack[-3] = nil;
    v_22211 = qvalue(elt(env, 1)); // wuvarlist!*
    stack[-1] = v_22211;
v_22101:
    v_22211 = stack[-1];
    if (v_22211 == nil) goto v_22105;
    else goto v_22106;
v_22105:
    goto v_22100;
v_22106:
    v_22211 = stack[-1];
    v_22211 = qcar(v_22211);
    stack[0] = v_22211;
v_22114:
    v_22211 = stack[-2];
    if (v_22211 == nil) goto v_22117;
    goto v_22127;
v_22123:
    v_22211 = stack[-2];
    v_22211 = qcar(v_22211);
    v_22211 = qcar(v_22211);
    v_22211 = qcar(v_22211);
    v_22212 = qcar(v_22211);
    goto v_22124;
v_22125:
    v_22211 = stack[0];
    goto v_22126;
v_22127:
    goto v_22123;
v_22124:
    goto v_22125;
v_22126:
    fn = elt(env, 2); // symbollessp
    v_22211 = (*qfn2(fn))(fn, v_22212, v_22211);
    env = stack[-4];
    if (v_22211 == nil) goto v_22117;
    goto v_22118;
v_22117:
    goto v_22113;
v_22118:
    v_22211 = stack[-2];
    v_22211 = qcdr(v_22211);
    stack[-2] = v_22211;
    goto v_22114;
v_22113:
v_22139:
    v_22211 = stack[-2];
    if (v_22211 == nil) goto v_22142;
    goto v_22155;
v_22151:
    v_22212 = stack[0];
    goto v_22152;
v_22153:
    v_22211 = stack[-2];
    v_22211 = qcar(v_22211);
    v_22211 = qcar(v_22211);
    v_22211 = qcar(v_22211);
    v_22211 = qcar(v_22211);
    goto v_22154;
v_22155:
    goto v_22151;
v_22152:
    goto v_22153;
v_22154:
    if (equal(v_22212, v_22211)) goto v_22149;
    else goto v_22150;
v_22149:
    goto v_22167;
v_22163:
    v_22211 = stack[-2];
    v_22212 = qcar(v_22211);
    goto v_22164;
v_22165:
    v_22211 = stack[-3];
    goto v_22166;
v_22167:
    goto v_22163;
v_22164:
    goto v_22165;
v_22166:
    fn = elt(env, 3); // wureducedpolysp
    v_22211 = (*qfn2(fn))(fn, v_22212, v_22211);
    env = stack[-4];
    v_22211 = (v_22211 == nil ? lisp_true : nil);
    goto v_22148;
v_22150:
    v_22211 = nil;
    goto v_22148;
    v_22211 = nil;
v_22148:
    if (v_22211 == nil) goto v_22142;
    goto v_22143;
v_22142:
    goto v_22138;
v_22143:
    v_22211 = stack[-2];
    v_22211 = qcdr(v_22211);
    stack[-2] = v_22211;
    goto v_22139;
v_22138:
    v_22211 = stack[-2];
    if (v_22211 == nil) goto v_22181;
    goto v_22189;
v_22185:
    v_22212 = stack[0];
    goto v_22186;
v_22187:
    v_22211 = stack[-2];
    v_22211 = qcar(v_22211);
    v_22211 = qcar(v_22211);
    v_22211 = qcar(v_22211);
    v_22211 = qcar(v_22211);
    goto v_22188;
v_22189:
    goto v_22185;
v_22186:
    goto v_22187;
v_22188:
    if (equal(v_22212, v_22211)) goto v_22184;
    else goto v_22181;
v_22184:
    goto v_22201;
v_22197:
    v_22211 = stack[-2];
    v_22212 = qcar(v_22211);
    goto v_22198;
v_22199:
    v_22211 = stack[-3];
    goto v_22200;
v_22201:
    goto v_22197;
v_22198:
    goto v_22199;
v_22200:
    v_22211 = cons(v_22212, v_22211);
    env = stack[-4];
    stack[-3] = v_22211;
    v_22211 = stack[-2];
    v_22211 = qcdr(v_22211);
    stack[-2] = v_22211;
    goto v_22179;
v_22181:
v_22179:
    v_22211 = stack[-1];
    v_22211 = qcdr(v_22211);
    stack[-1] = v_22211;
    goto v_22101;
v_22100:
    v_22211 = stack[-3];
        return Lnreverse(nil, v_22211);
    return onevalue(v_22211);
}



// Code for cl_bvarl

static LispObject CC_cl_bvarl(LispObject env,
                         LispObject v_22093)
{
    env = qenv(env);
    LispObject v_22104, v_22105;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22093);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_22104 = v_22093;
// end of prologue
    goto v_22100;
v_22096:
    fn = elt(env, 2); // cl_bvarl1
    v_22105 = (*qfn1(fn))(fn, v_22104);
    env = stack[0];
    goto v_22097;
v_22098:
    v_22104 = elt(env, 1); // ordp
    goto v_22099;
v_22100:
    goto v_22096;
v_22097:
    goto v_22098;
v_22099:
    {
        fn = elt(env, 3); // sort
        return (*qfn2(fn))(fn, v_22105, v_22104);
    }
}



// Code for dip_sum

static LispObject CC_dip_sum(LispObject env,
                         LispObject v_22093, LispObject v_22094)
{
    env = qenv(env);
    LispObject v_22247, v_22248, v_22249;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22093,v_22094);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_22094;
    stack[-6] = v_22093;
// end of prologue
    stack[-7] = nil;
    stack[-4] = nil;
    stack[0] = nil;
v_22108:
    v_22247 = stack[0];
    if (v_22247 == nil) goto v_22112;
    goto v_22107;
v_22112:
    v_22247 = stack[-6];
    if (v_22247 == nil) goto v_22117;
    else goto v_22118;
v_22117:
    v_22247 = stack[-5];
    stack[-1] = v_22247;
    v_22247 = lisp_true;
    stack[0] = v_22247;
    goto v_22116;
v_22118:
    v_22247 = stack[-5];
    if (v_22247 == nil) goto v_22122;
    else goto v_22123;
v_22122:
    v_22247 = stack[-6];
    stack[-1] = v_22247;
    v_22247 = lisp_true;
    stack[0] = v_22247;
    goto v_22116;
v_22123:
    v_22247 = stack[-6];
    fn = elt(env, 1); // dip_evlmon
    v_22247 = (*qfn1(fn))(fn, v_22247);
    env = stack[-8];
    stack[-2] = v_22247;
    v_22247 = stack[-5];
    fn = elt(env, 1); // dip_evlmon
    v_22247 = (*qfn1(fn))(fn, v_22247);
    env = stack[-8];
    stack[-1] = v_22247;
    goto v_22138;
v_22134:
    v_22248 = stack[-2];
    goto v_22135;
v_22136:
    v_22247 = stack[-1];
    goto v_22137;
v_22138:
    goto v_22134;
v_22135:
    goto v_22136;
v_22137:
    fn = elt(env, 2); // ev_comp
    v_22247 = (*qfn2(fn))(fn, v_22248, v_22247);
    env = stack[-8];
    stack[-3] = v_22247;
    goto v_22150;
v_22146:
    v_22248 = stack[-3];
    goto v_22147;
v_22148:
    v_22247 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22149;
v_22150:
    goto v_22146;
v_22147:
    goto v_22148;
v_22149:
    fn = elt(env, 3); // iequal
    v_22247 = (*qfn2(fn))(fn, v_22248, v_22247);
    env = stack[-8];
    if (v_22247 == nil) goto v_22144;
    goto v_22160;
v_22154:
    v_22247 = stack[-6];
    fn = elt(env, 4); // dip_lbc
    v_22249 = (*qfn1(fn))(fn, v_22247);
    env = stack[-8];
    goto v_22155;
v_22156:
    v_22248 = stack[-2];
    goto v_22157;
v_22158:
    v_22247 = nil;
    goto v_22159;
v_22160:
    goto v_22154;
v_22155:
    goto v_22156;
v_22157:
    goto v_22158;
v_22159:
    fn = elt(env, 5); // dip_moncomp
    v_22247 = (*qfnn(fn))(fn, 3, v_22249, v_22248, v_22247);
    env = stack[-8];
    stack[-1] = v_22247;
    v_22247 = stack[-6];
    fn = elt(env, 6); // dip_mred
    v_22247 = (*qfn1(fn))(fn, v_22247);
    env = stack[-8];
    stack[-6] = v_22247;
    goto v_22142;
v_22144:
    goto v_22174;
v_22170:
    v_22248 = stack[-3];
    goto v_22171;
v_22172:
    v_22247 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_22173;
v_22174:
    goto v_22170;
v_22171:
    goto v_22172;
v_22173:
    fn = elt(env, 3); // iequal
    v_22247 = (*qfn2(fn))(fn, v_22248, v_22247);
    env = stack[-8];
    if (v_22247 == nil) goto v_22168;
    goto v_22184;
v_22178:
    v_22247 = stack[-5];
    fn = elt(env, 4); // dip_lbc
    v_22249 = (*qfn1(fn))(fn, v_22247);
    env = stack[-8];
    goto v_22179;
v_22180:
    v_22248 = stack[-1];
    goto v_22181;
v_22182:
    v_22247 = nil;
    goto v_22183;
v_22184:
    goto v_22178;
v_22179:
    goto v_22180;
v_22181:
    goto v_22182;
v_22183:
    fn = elt(env, 5); // dip_moncomp
    v_22247 = (*qfnn(fn))(fn, 3, v_22249, v_22248, v_22247);
    env = stack[-8];
    stack[-1] = v_22247;
    v_22247 = stack[-5];
    fn = elt(env, 6); // dip_mred
    v_22247 = (*qfn1(fn))(fn, v_22247);
    env = stack[-8];
    stack[-5] = v_22247;
    goto v_22142;
v_22168:
    goto v_22198;
v_22194:
    v_22247 = stack[-6];
    fn = elt(env, 4); // dip_lbc
    stack[-1] = (*qfn1(fn))(fn, v_22247);
    env = stack[-8];
    goto v_22195;
v_22196:
    v_22247 = stack[-5];
    fn = elt(env, 4); // dip_lbc
    v_22247 = (*qfn1(fn))(fn, v_22247);
    env = stack[-8];
    goto v_22197;
v_22198:
    goto v_22194;
v_22195:
    goto v_22196;
v_22197:
    fn = elt(env, 7); // bc_sum
    v_22247 = (*qfn2(fn))(fn, stack[-1], v_22247);
    env = stack[-8];
    v_22248 = v_22247;
    v_22247 = v_22248;
    if (v_22247 == nil) goto v_22206;
    goto v_22215;
v_22209:
    v_22249 = v_22248;
    goto v_22210;
v_22211:
    v_22248 = stack[-2];
    goto v_22212;
v_22213:
    v_22247 = nil;
    goto v_22214;
v_22215:
    goto v_22209;
v_22210:
    goto v_22211;
v_22212:
    goto v_22213;
v_22214:
    fn = elt(env, 5); // dip_moncomp
    v_22247 = (*qfnn(fn))(fn, 3, v_22249, v_22248, v_22247);
    env = stack[-8];
    goto v_22204;
v_22206:
    v_22247 = nil;
v_22204:
    stack[-1] = v_22247;
    v_22247 = stack[-6];
    fn = elt(env, 6); // dip_mred
    v_22247 = (*qfn1(fn))(fn, v_22247);
    env = stack[-8];
    stack[-6] = v_22247;
    v_22247 = stack[-5];
    fn = elt(env, 6); // dip_mred
    v_22247 = (*qfn1(fn))(fn, v_22247);
    env = stack[-8];
    stack[-5] = v_22247;
    goto v_22142;
v_22142:
    goto v_22116;
v_22116:
    v_22247 = stack[-1];
    if (v_22247 == nil) goto v_22226;
    v_22247 = stack[-7];
    if (v_22247 == nil) goto v_22230;
    else goto v_22231;
v_22230:
    v_22247 = stack[-1];
    stack[-4] = v_22247;
    stack[-7] = v_22247;
    goto v_22229;
v_22231:
    goto v_22241;
v_22237:
    v_22247 = stack[-4];
    v_22248 = qcdr(v_22247);
    goto v_22238;
v_22239:
    v_22247 = stack[-1];
    goto v_22240;
v_22241:
    goto v_22237;
v_22238:
    goto v_22239;
v_22240:
    fn = elt(env, 8); // setcdr
    v_22247 = (*qfn2(fn))(fn, v_22248, v_22247);
    env = stack[-8];
    v_22247 = stack[-1];
    stack[-4] = v_22247;
    goto v_22229;
v_22229:
    goto v_22224;
v_22226:
v_22224:
    goto v_22108;
v_22107:
    v_22247 = stack[-7];
    return onevalue(v_22247);
}



// Code for matrixelems

static LispObject CC_matrixelems(LispObject env,
                         LispObject v_22093)
{
    env = qenv(env);
    LispObject v_22121, v_22122;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22093);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_22093;
// end of prologue
    v_22122 = nil;
v_22098:
    v_22121 = stack[0];
    if (v_22121 == nil) goto v_22102;
    goto v_22109;
v_22105:
    v_22121 = stack[0];
    v_22121 = qcar(v_22121);
    v_22121 = qcdr(v_22121);
    v_22121 = qcdr(v_22121);
    goto v_22106;
v_22107:
    goto v_22108;
v_22109:
    goto v_22105;
v_22106:
    goto v_22107;
v_22108:
    v_22121 = cons(v_22121, v_22122);
    env = stack[-1];
    v_22122 = v_22121;
    v_22121 = stack[0];
    v_22121 = qcdr(v_22121);
    stack[0] = v_22121;
    goto v_22098;
v_22102:
    v_22121 = v_22122;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_22121);
    }
    v_22121 = nil;
    return onevalue(v_22121);
}



// Code for multerm

static LispObject CC_multerm(LispObject env,
                         LispObject v_22093, LispObject v_22094)
{
    env = qenv(env);
    LispObject v_22126, v_22127;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22093,v_22094);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_22094;
    stack[-1] = v_22093;
// end of prologue
    goto v_22104;
v_22100:
    v_22126 = stack[-1];
    v_22127 = qcdr(v_22126);
    goto v_22101;
v_22102:
    v_22126 = stack[0];
    v_22126 = qcdr(v_22126);
    goto v_22103;
v_22104:
    goto v_22100;
v_22101:
    goto v_22102;
v_22103:
    fn = elt(env, 1); // !*multsq
    v_22126 = (*qfn2(fn))(fn, v_22127, v_22126);
    env = stack[-3];
    goto v_22114;
v_22110:
    stack[-2] = v_22126;
    goto v_22111;
v_22112:
    goto v_22121;
v_22117:
    v_22126 = stack[-1];
    v_22127 = qcar(v_22126);
    goto v_22118;
v_22119:
    v_22126 = stack[0];
    v_22126 = qcar(v_22126);
    goto v_22120;
v_22121:
    goto v_22117;
v_22118:
    goto v_22119;
v_22120:
    fn = elt(env, 2); // mulpower
    v_22126 = (*qfn2(fn))(fn, v_22127, v_22126);
    env = stack[-3];
    goto v_22113;
v_22114:
    goto v_22110;
v_22111:
    goto v_22112;
v_22113:
    {
        LispObject v_22131 = stack[-2];
        fn = elt(env, 3); // multdfconst
        return (*qfn2(fn))(fn, v_22131, v_22126);
    }
    return onevalue(v_22126);
}



// Code for transmat1

static LispObject CC_transmat1(LispObject env,
                         LispObject v_22093)
{
    env = qenv(env);
    LispObject v_22270, v_22271, v_22272, v_22273;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22093);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_22093;
// end of prologue
    v_22270 = stack[-6];
    v_22270 = qcar(v_22270);
    fn = elt(env, 5); // aeval
    v_22270 = (*qfn1(fn))(fn, v_22270);
    env = stack[-8];
    v_22270 = qcdr(v_22270);
    stack[0] = v_22270;
    v_22270 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_22270;
    v_22270 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_22270;
    v_22270 = stack[-6];
    v_22270 = qcar(v_22270);
    fn = elt(env, 5); // aeval
    v_22270 = (*qfn1(fn))(fn, v_22270);
    env = stack[-8];
    fn = elt(env, 6); // matlength
    v_22270 = (*qfn1(fn))(fn, v_22270);
    env = stack[-8];
    v_22270 = qcdr(v_22270);
    goto v_22121;
v_22117:
    v_22271 = v_22270;
    stack[-1] = qcar(v_22271);
    goto v_22118;
v_22119:
    goto v_22129;
v_22125:
    v_22271 = elt(env, 1); // spm
    goto v_22126;
v_22127:
    goto v_22128;
v_22129:
    goto v_22125;
v_22126:
    goto v_22127;
v_22128:
    v_22270 = cons(v_22271, v_22270);
    env = stack[-8];
    goto v_22120;
v_22121:
    goto v_22117;
v_22118:
    goto v_22119;
v_22120:
    fn = elt(env, 7); // mkempspmat
    v_22270 = (*qfn2(fn))(fn, stack[-1], v_22270);
    env = stack[-8];
    stack[-7] = v_22270;
    v_22270 = nil;
    v_22270 = ncons(v_22270);
    env = stack[-8];
    v_22270 = ncons(v_22270);
    env = stack[-8];
    stack[-2] = v_22270;
    v_22270 = stack[0];
    stack[-1] = v_22270;
v_22138:
    v_22270 = stack[-1];
    if (v_22270 == nil) goto v_22142;
    else goto v_22143;
v_22142:
    goto v_22137;
v_22143:
    v_22270 = stack[-1];
    v_22270 = qcar(v_22270);
    stack[0] = v_22270;
    v_22270 = stack[-5];
    v_22270 = add1(v_22270);
    env = stack[-8];
    stack[-5] = v_22270;
    v_22270 = stack[0];
    stack[0] = v_22270;
v_22155:
    v_22270 = stack[0];
    if (v_22270 == nil) goto v_22159;
    else goto v_22160;
v_22159:
    goto v_22154;
v_22160:
    v_22270 = stack[0];
    v_22270 = qcar(v_22270);
    stack[-3] = v_22270;
    v_22270 = stack[-4];
    v_22270 = add1(v_22270);
    env = stack[-8];
    stack[-4] = v_22270;
    goto v_22177;
v_22173:
    v_22271 = stack[-3];
    goto v_22174;
v_22175:
    v_22270 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22176;
v_22177:
    goto v_22173;
v_22174:
    goto v_22175;
v_22176:
    if (v_22271 == v_22270) goto v_22171;
    else goto v_22172;
v_22171:
    goto v_22170;
v_22172:
    goto v_22190;
v_22184:
    v_22272 = stack[-4];
    goto v_22185;
v_22186:
    v_22271 = stack[-3];
    goto v_22187;
v_22188:
    v_22270 = stack[-2];
    goto v_22189;
v_22190:
    goto v_22184;
v_22185:
    goto v_22186;
v_22187:
    goto v_22188;
v_22189:
    v_22270 = acons(v_22272, v_22271, v_22270);
    env = stack[-8];
    stack[-2] = v_22270;
    goto v_22170;
v_22170:
    v_22270 = stack[0];
    v_22270 = qcdr(v_22270);
    stack[0] = v_22270;
    goto v_22155;
v_22154:
    v_22270 = stack[-2];
    v_22270 = Lreverse(nil, v_22270);
    env = stack[-8];
    stack[-2] = v_22270;
    goto v_22206;
v_22202:
    stack[0] = stack[-2];
    goto v_22203;
v_22204:
    v_22270 = nil;
    v_22270 = ncons(v_22270);
    env = stack[-8];
    v_22270 = ncons(v_22270);
    env = stack[-8];
    goto v_22205;
v_22206:
    goto v_22202;
v_22203:
    goto v_22204;
v_22205:
    if (equal(stack[0], v_22270)) goto v_22201;
    goto v_22220;
v_22212:
    goto v_22226;
v_22222:
    v_22271 = stack[-7];
    goto v_22223;
v_22224:
    v_22270 = stack[-5];
    goto v_22225;
v_22226:
    goto v_22222;
v_22223:
    goto v_22224;
v_22225:
    v_22273 = list2(v_22271, v_22270);
    env = stack[-8];
    goto v_22213;
v_22214:
    v_22272 = stack[-2];
    goto v_22215;
v_22216:
    v_22271 = stack[-7];
    goto v_22217;
v_22218:
    v_22270 = nil;
    goto v_22219;
v_22220:
    goto v_22212;
v_22213:
    goto v_22214;
v_22215:
    goto v_22216;
v_22217:
    goto v_22218;
v_22219:
    fn = elt(env, 8); // letmtr3
    v_22270 = (*qfnn(fn))(fn, 4, v_22273, v_22272, v_22271, v_22270);
    env = stack[-8];
    goto v_22199;
v_22201:
v_22199:
    v_22270 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_22270;
    v_22270 = nil;
    v_22270 = ncons(v_22270);
    env = stack[-8];
    v_22270 = ncons(v_22270);
    env = stack[-8];
    stack[-2] = v_22270;
    v_22270 = stack[-1];
    v_22270 = qcdr(v_22270);
    stack[-1] = v_22270;
    goto v_22138;
v_22137:
    goto v_22246;
v_22240:
    v_22270 = stack[-6];
    stack[-1] = qcar(v_22270);
    goto v_22241;
v_22242:
    stack[0] = elt(env, 2); // avalue
    goto v_22243;
v_22244:
    goto v_22255;
v_22251:
    v_22271 = elt(env, 3); // sparse
    goto v_22252;
v_22253:
    v_22270 = stack[-7];
    goto v_22254;
v_22255:
    goto v_22251;
v_22252:
    goto v_22253;
v_22254:
    v_22270 = list2(v_22271, v_22270);
    env = stack[-8];
    goto v_22245;
v_22246:
    goto v_22240;
v_22241:
    goto v_22242;
v_22243:
    goto v_22244;
v_22245:
    v_22270 = Lputprop(nil, 3, stack[-1], stack[0], v_22270);
    env = stack[-8];
    goto v_22265;
v_22259:
    v_22270 = stack[-6];
    v_22272 = qcar(v_22270);
    goto v_22260;
v_22261:
    v_22271 = elt(env, 4); // rtype
    goto v_22262;
v_22263:
    v_22270 = elt(env, 3); // sparse
    goto v_22264;
v_22265:
    goto v_22259;
v_22260:
    goto v_22261;
v_22262:
    goto v_22263;
v_22264:
    v_22270 = Lputprop(nil, 3, v_22272, v_22271, v_22270);
    v_22270 = nil;
    return onevalue(v_22270);
}



// Code for remzzzz

static LispObject CC_remzzzz(LispObject env,
                         LispObject v_22093, LispObject v_22094)
{
    env = qenv(env);
    LispObject v_22143, v_22144, v_22145;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22093,v_22094);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22094;
    stack[-1] = v_22093;
// end of prologue
    v_22145 = nil;
v_22099:
    v_22143 = stack[-1];
    if (v_22143 == nil) goto v_22102;
    else goto v_22103;
v_22102:
    goto v_22110;
v_22106:
    v_22144 = v_22145;
    goto v_22107;
v_22108:
    v_22143 = stack[0];
    goto v_22109;
v_22110:
    goto v_22106;
v_22107:
    goto v_22108;
v_22109:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_22144, v_22143);
    }
v_22103:
    goto v_22119;
v_22115:
    v_22143 = stack[-1];
    v_22143 = qcar(v_22143);
    v_22144 = qcar(v_22143);
    goto v_22116;
v_22117:
    v_22143 = stack[0];
    v_22143 = qcar(v_22143);
    v_22143 = qcar(v_22143);
    goto v_22118;
v_22119:
    goto v_22115;
v_22116:
    goto v_22117;
v_22118:
    if (equal(v_22144, v_22143)) goto v_22113;
    else goto v_22114;
v_22113:
    v_22143 = stack[-1];
    v_22143 = qcdr(v_22143);
    stack[-1] = v_22143;
    v_22143 = stack[0];
    v_22143 = qcdr(v_22143);
    stack[0] = v_22143;
    goto v_22099;
v_22114:
    goto v_22137;
v_22133:
    v_22143 = stack[0];
    v_22143 = qcar(v_22143);
    goto v_22134;
v_22135:
    v_22144 = v_22145;
    goto v_22136;
v_22137:
    goto v_22133;
v_22134:
    goto v_22135;
v_22136:
    v_22143 = cons(v_22143, v_22144);
    env = stack[-2];
    v_22145 = v_22143;
    v_22143 = stack[0];
    v_22143 = qcdr(v_22143);
    stack[0] = v_22143;
    goto v_22099;
    v_22143 = nil;
    return onevalue(v_22143);
}



// Code for diplmon2sq

static LispObject CC_diplmon2sq(LispObject env,
                         LispObject v_22093, LispObject v_22094)
{
    env = qenv(env);
    LispObject v_22118, v_22119;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22093,v_22094);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_22118 = v_22094;
    v_22119 = v_22093;
// end of prologue
    goto v_22101;
v_22097:
    stack[0] = v_22119;
    goto v_22098;
v_22099:
    goto v_22108;
v_22104:
    goto v_22114;
v_22110:
    v_22119 = v_22118;
    goto v_22111;
v_22112:
    v_22118 = qvalue(elt(env, 1)); // dipvars!*
    goto v_22113;
v_22114:
    goto v_22110;
v_22111:
    goto v_22112;
v_22113:
    fn = elt(env, 2); // dipev2f
    v_22119 = (*qfn2(fn))(fn, v_22119, v_22118);
    env = stack[-1];
    goto v_22105;
v_22106:
    v_22118 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22107;
v_22108:
    goto v_22104;
v_22105:
    goto v_22106;
v_22107:
    v_22118 = cons(v_22119, v_22118);
    env = stack[-1];
    goto v_22100;
v_22101:
    goto v_22097;
v_22098:
    goto v_22099;
v_22100:
    {
        LispObject v_22121 = stack[0];
        fn = elt(env, 3); // multsq
        return (*qfn2(fn))(fn, v_22121, v_22118);
    }
}



// Code for weak_xreduce1

static LispObject CC_weak_xreduce1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22269, v_22270, v_22271;
    LispObject fn;
    LispObject v_22095, v_22094, v_22093;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "weak_xreduce1");
    va_start(aa, nargs);
    v_22093 = va_arg(aa, LispObject);
    v_22094 = va_arg(aa, LispObject);
    v_22095 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22095,v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22093,v_22094,v_22095);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_22095;
    stack[-4] = v_22094;
    stack[-5] = v_22093;
// end of prologue
    v_22269 = stack[-4];
    stack[0] = v_22269;
v_22107:
    v_22269 = stack[-5];
    if (v_22269 == nil) goto v_22110;
    v_22269 = stack[0];
    if (v_22269 == nil) goto v_22110;
    goto v_22111;
v_22110:
    goto v_22106;
v_22111:
    v_22269 = stack[0];
    v_22269 = qcar(v_22269);
    stack[-6] = v_22269;
    v_22269 = stack[0];
    v_22269 = qcdr(v_22269);
    stack[0] = v_22269;
    goto v_22132;
v_22128:
    v_22269 = stack[-6];
    fn = elt(env, 7); // xval
    stack[-1] = (*qfn1(fn))(fn, v_22269);
    env = stack[-7];
    goto v_22129;
v_22130:
    v_22269 = stack[-5];
    fn = elt(env, 7); // xval
    v_22269 = (*qfn1(fn))(fn, v_22269);
    env = stack[-7];
    goto v_22131;
v_22132:
    goto v_22128;
v_22129:
    goto v_22130;
v_22131:
    fn = elt(env, 8); // xdiv
    v_22269 = (*qfn2(fn))(fn, stack[-1], v_22269);
    env = stack[-7];
    stack[-1] = v_22269;
    if (v_22269 == nil) goto v_22126;
    goto v_22147;
v_22141:
    v_22269 = stack[-1];
    fn = elt(env, 9); // mknwedge
    v_22271 = (*qfn1(fn))(fn, v_22269);
    env = stack[-7];
    goto v_22142;
v_22143:
    v_22270 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22144;
v_22145:
    v_22269 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22146;
v_22147:
    goto v_22141;
v_22142:
    goto v_22143;
v_22144:
    goto v_22145;
v_22146:
    v_22269 = list2star(v_22271, v_22270, v_22269);
    env = stack[-7];
    v_22269 = ncons(v_22269);
    env = stack[-7];
    stack[-1] = v_22269;
    goto v_22157;
v_22153:
    v_22270 = stack[-1];
    goto v_22154;
v_22155:
    v_22269 = stack[-6];
    goto v_22156;
v_22157:
    goto v_22153;
v_22154:
    goto v_22155;
v_22156:
    fn = elt(env, 10); // wedgepf
    v_22269 = (*qfn2(fn))(fn, v_22270, v_22269);
    env = stack[-7];
    stack[0] = v_22269;
    goto v_22165;
v_22161:
    v_22269 = stack[-5];
    v_22269 = qcar(v_22269);
    v_22270 = qcdr(v_22269);
    goto v_22162;
v_22163:
    v_22269 = stack[0];
    v_22269 = qcar(v_22269);
    v_22269 = qcdr(v_22269);
    goto v_22164;
v_22165:
    goto v_22161;
v_22162:
    goto v_22163;
v_22164:
    fn = elt(env, 11); // quotsq
    v_22269 = (*qfn2(fn))(fn, v_22270, v_22269);
    env = stack[-7];
    stack[-2] = v_22269;
    goto v_22178;
v_22174:
    goto v_22175;
v_22176:
    goto v_22185;
v_22181:
    goto v_22182;
v_22183:
    v_22269 = stack[-2];
    fn = elt(env, 12); // negsq
    v_22269 = (*qfn1(fn))(fn, v_22269);
    env = stack[-7];
    goto v_22184;
v_22185:
    goto v_22181;
v_22182:
    goto v_22183;
v_22184:
    fn = elt(env, 13); // multpfsq
    v_22269 = (*qfn2(fn))(fn, stack[0], v_22269);
    env = stack[-7];
    goto v_22177;
v_22178:
    goto v_22174;
v_22175:
    goto v_22176;
v_22177:
    fn = elt(env, 14); // addpf
    v_22269 = (*qfn2(fn))(fn, stack[-5], v_22269);
    env = stack[-7];
    fn = elt(env, 15); // subs2pf
    v_22269 = (*qfn1(fn))(fn, v_22269);
    env = stack[-7];
    stack[-5] = v_22269;
    v_22269 = qvalue(elt(env, 1)); // !*trxmod
    if (v_22269 == nil) goto v_22192;
    goto v_22199;
v_22195:
    stack[0] = stack[-3];
    goto v_22196;
v_22197:
    goto v_22207;
v_22203:
    goto v_22213;
v_22209:
    v_22270 = stack[-1];
    goto v_22210;
v_22211:
    v_22269 = stack[-2];
    goto v_22212;
v_22213:
    goto v_22209;
v_22210:
    goto v_22211;
v_22212:
    fn = elt(env, 13); // multpfsq
    v_22270 = (*qfn2(fn))(fn, v_22270, v_22269);
    env = stack[-7];
    goto v_22204;
v_22205:
    v_22269 = stack[-6];
    goto v_22206;
v_22207:
    goto v_22203;
v_22204:
    goto v_22205;
v_22206:
    v_22269 = list2(v_22270, v_22269);
    env = stack[-7];
    v_22269 = ncons(v_22269);
    env = stack[-7];
    goto v_22198;
v_22199:
    goto v_22195;
v_22196:
    goto v_22197;
v_22198:
    v_22269 = Lnconc(nil, stack[0], v_22269);
    env = stack[-7];
    stack[-3] = v_22269;
    goto v_22190;
v_22192:
v_22190:
    v_22269 = qvalue(elt(env, 1)); // !*trxmod
    if (v_22269 == nil) goto v_22220;
    goto v_22227;
v_22223:
    v_22270 = elt(env, 2); // "   "
    goto v_22224;
v_22225:
    v_22269 = elt(env, 3); // first
    goto v_22226;
v_22227:
    goto v_22223;
v_22224:
    goto v_22225;
v_22226:
    fn = elt(env, 16); // writepri
    v_22269 = (*qfn2(fn))(fn, v_22270, v_22269);
    env = stack[-7];
    goto v_22235;
v_22231:
    goto v_22244;
v_22238:
    stack[0] = elt(env, 4); // wedge
    goto v_22239;
v_22240:
    goto v_22252;
v_22248:
    v_22270 = stack[-1];
    goto v_22249;
v_22250:
    v_22269 = stack[-2];
    goto v_22251;
v_22252:
    goto v_22248;
v_22249:
    goto v_22250;
v_22251:
    fn = elt(env, 13); // multpfsq
    v_22269 = (*qfn2(fn))(fn, v_22270, v_22269);
    env = stack[-7];
    fn = elt(env, 17); // preppf
    stack[-1] = (*qfn1(fn))(fn, v_22269);
    env = stack[-7];
    goto v_22241;
v_22242:
    v_22269 = stack[-6];
    fn = elt(env, 17); // preppf
    v_22269 = (*qfn1(fn))(fn, v_22269);
    env = stack[-7];
    goto v_22243;
v_22244:
    goto v_22238;
v_22239:
    goto v_22240;
v_22241:
    goto v_22242;
v_22243:
    v_22269 = list3(stack[0], stack[-1], v_22269);
    env = stack[-7];
    v_22270 = Lmkquote(nil, v_22269);
    env = stack[-7];
    goto v_22232;
v_22233:
    v_22269 = nil;
    goto v_22234;
v_22235:
    goto v_22231;
v_22232:
    goto v_22233;
v_22234:
    fn = elt(env, 16); // writepri
    v_22269 = (*qfn2(fn))(fn, v_22270, v_22269);
    env = stack[-7];
    goto v_22263;
v_22259:
    v_22270 = elt(env, 5); // " +"
    goto v_22260;
v_22261:
    v_22269 = elt(env, 6); // last
    goto v_22262;
v_22263:
    goto v_22259;
v_22260:
    goto v_22261;
v_22262:
    fn = elt(env, 16); // writepri
    v_22269 = (*qfn2(fn))(fn, v_22270, v_22269);
    env = stack[-7];
    goto v_22218;
v_22220:
v_22218:
    v_22269 = stack[-4];
    stack[0] = v_22269;
    goto v_22124;
v_22126:
v_22124:
    goto v_22107;
v_22106:
    v_22269 = stack[-5];
    return onevalue(v_22269);
}



// Code for rd!:difference

static LispObject CC_rdTdifference(LispObject env,
                         LispObject v_22093, LispObject v_22094)
{
    env = qenv(env);
    LispObject v_22295, v_22296, v_22297;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22093,v_22094);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_22094;
    stack[-2] = v_22093;
// end of prologue
    v_22295 = nil;
    stack[-3] = v_22295;
    v_22295 = qvalue(elt(env, 1)); // !*!*roundbf
    if (v_22295 == nil) goto v_22104;
    else goto v_22105;
v_22104:
    v_22295 = stack[-2];
    v_22295 = qcdr(v_22295);
    if (!consp(v_22295)) goto v_22109;
    else goto v_22110;
v_22109:
    v_22295 = stack[0];
    v_22295 = qcdr(v_22295);
    if (!consp(v_22295)) goto v_22115;
    else goto v_22116;
v_22115:
    goto v_22124;
v_22120:
    v_22295 = stack[-2];
    stack[-1] = qcdr(v_22295);
    goto v_22121;
v_22122:
    v_22295 = stack[0];
    v_22295 = qcdr(v_22295);
    fn = elt(env, 4); // safe!-fp!-minus
    v_22295 = (*qfn1(fn))(fn, v_22295);
    env = stack[-4];
    goto v_22123;
v_22124:
    goto v_22120;
v_22121:
    goto v_22122;
v_22123:
    fn = elt(env, 5); // safe!-fp!-plus
    v_22295 = (*qfn2(fn))(fn, stack[-1], v_22295);
    env = stack[-4];
    stack[-3] = v_22295;
    goto v_22114;
v_22116:
    v_22295 = nil;
    goto v_22114;
    v_22295 = nil;
v_22114:
    goto v_22108;
v_22110:
    v_22295 = nil;
    goto v_22108;
    v_22295 = nil;
v_22108:
    goto v_22103;
v_22105:
    v_22295 = nil;
    goto v_22103;
    v_22295 = nil;
v_22103:
    if (v_22295 == nil) goto v_22101;
    goto v_22144;
v_22140:
    v_22296 = elt(env, 2); // !:rd!:
    goto v_22141;
v_22142:
    v_22295 = stack[-3];
    goto v_22143;
v_22144:
    goto v_22140;
v_22141:
    goto v_22142;
v_22143:
    return cons(v_22296, v_22295);
v_22101:
    goto v_22158;
v_22154:
    v_22296 = stack[-2];
    goto v_22155;
v_22156:
    v_22295 = stack[0];
    goto v_22157;
v_22158:
    goto v_22154;
v_22155:
    goto v_22156;
v_22157:
    fn = elt(env, 6); // convprc2
    v_22295 = (*qfn2(fn))(fn, v_22296, v_22295);
    env = stack[-4];
    stack[-1] = v_22295;
    v_22295 = qvalue(elt(env, 3)); // yy!!
    stack[0] = v_22295;
    v_22295 = stack[-1];
    if (!consp(v_22295)) goto v_22165;
    goto v_22172;
v_22168:
    v_22296 = stack[-1];
    goto v_22169;
v_22170:
    v_22295 = stack[0];
    goto v_22171;
v_22172:
    goto v_22168;
v_22169:
    goto v_22170;
v_22171:
    fn = elt(env, 7); // difbf
    v_22295 = (*qfn2(fn))(fn, v_22296, v_22295);
    env = stack[-4];
    goto v_22163;
v_22165:
    goto v_22182;
v_22178:
    v_22296 = stack[-1];
    goto v_22179;
v_22180:
    v_22295 = stack[0];
    goto v_22181;
v_22182:
    goto v_22178;
v_22179:
    goto v_22180;
v_22181:
    v_22295 = difference2(v_22296, v_22295);
    env = stack[-4];
    stack[-3] = v_22295;
    v_22295 = stack[-3];
    fn = elt(env, 8); // fp!-infinite
    v_22295 = (*qfn1(fn))(fn, v_22295);
    env = stack[-4];
    if (v_22295 == nil) goto v_22188;
    fn = elt(env, 9); // rndbfon
    v_22295 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_22197;
v_22193:
    v_22295 = stack[-1];
    v_22295 = Lfloatp(nil, v_22295);
    env = stack[-4];
    if (v_22295 == nil) goto v_22201;
    v_22295 = stack[-1];
    fn = elt(env, 10); // fl2bf
    v_22295 = (*qfn1(fn))(fn, v_22295);
    env = stack[-4];
    stack[-2] = v_22295;
    goto v_22199;
v_22201:
    v_22295 = stack[-1];
    if (!consp(v_22295)) goto v_22212;
    v_22295 = stack[-1];
    goto v_22210;
v_22212:
    v_22295 = stack[-1];
    v_22295 = integerp(v_22295);
    if (v_22295 == nil) goto v_22216;
    goto v_22226;
v_22220:
    v_22297 = elt(env, 2); // !:rd!:
    goto v_22221;
v_22222:
    v_22296 = stack[-1];
    goto v_22223;
v_22224:
    v_22295 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22225;
v_22226:
    goto v_22220;
v_22221:
    goto v_22222;
v_22223:
    goto v_22224;
v_22225:
    v_22295 = list2star(v_22297, v_22296, v_22295);
    env = stack[-4];
    goto v_22210;
v_22216:
    v_22295 = stack[-1];
    fn = elt(env, 11); // read!:num
    v_22295 = (*qfn1(fn))(fn, v_22295);
    env = stack[-4];
    goto v_22210;
    v_22295 = nil;
v_22210:
    fn = elt(env, 12); // normbf
    v_22295 = (*qfn1(fn))(fn, v_22295);
    env = stack[-4];
    stack[-2] = v_22295;
    goto v_22199;
    stack[-2] = nil;
v_22199:
    stack[-1] = stack[-2];
    goto v_22194;
v_22195:
    v_22295 = stack[0];
    v_22295 = Lfloatp(nil, v_22295);
    env = stack[-4];
    if (v_22295 == nil) goto v_22237;
    v_22295 = stack[0];
    fn = elt(env, 10); // fl2bf
    v_22295 = (*qfn1(fn))(fn, v_22295);
    env = stack[-4];
    goto v_22235;
v_22237:
    v_22295 = stack[0];
    if (!consp(v_22295)) goto v_22248;
    v_22295 = stack[0];
    goto v_22246;
v_22248:
    v_22295 = stack[0];
    v_22295 = integerp(v_22295);
    if (v_22295 == nil) goto v_22252;
    goto v_22262;
v_22256:
    v_22297 = elt(env, 2); // !:rd!:
    goto v_22257;
v_22258:
    v_22296 = stack[0];
    goto v_22259;
v_22260:
    v_22295 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22261;
v_22262:
    goto v_22256;
v_22257:
    goto v_22258;
v_22259:
    goto v_22260;
v_22261:
    v_22295 = list2star(v_22297, v_22296, v_22295);
    env = stack[-4];
    goto v_22246;
v_22252:
    v_22295 = stack[0];
    fn = elt(env, 11); // read!:num
    v_22295 = (*qfn1(fn))(fn, v_22295);
    env = stack[-4];
    goto v_22246;
    v_22295 = nil;
v_22246:
    fn = elt(env, 12); // normbf
    v_22295 = (*qfn1(fn))(fn, v_22295);
    env = stack[-4];
    goto v_22235;
    v_22295 = nil;
v_22235:
    stack[0] = v_22295;
    goto v_22196;
v_22197:
    goto v_22193;
v_22194:
    goto v_22195;
v_22196:
    fn = elt(env, 7); // difbf
    v_22295 = (*qfn2(fn))(fn, stack[-2], v_22295);
    env = stack[-4];
    goto v_22186;
v_22188:
    v_22295 = stack[-3];
    goto v_22186;
    v_22295 = nil;
v_22186:
    goto v_22163;
    v_22295 = nil;
v_22163:
    stack[-2] = v_22295;
    goto v_22281;
v_22275:
    goto v_22276;
v_22277:
    goto v_22278;
v_22279:
    v_22295 = stack[0];
    if (!consp(v_22295)) goto v_22286;
    else goto v_22287;
v_22286:
    v_22295 = stack[0];
    v_22295 = negate(v_22295);
    env = stack[-4];
    goto v_22285;
v_22287:
    v_22295 = stack[0];
    fn = elt(env, 13); // minus!:
    v_22295 = (*qfn1(fn))(fn, v_22295);
    env = stack[-4];
    goto v_22285;
    v_22295 = nil;
v_22285:
    goto v_22280;
v_22281:
    goto v_22275;
v_22276:
    goto v_22277;
v_22278:
    goto v_22279;
v_22280:
    fn = elt(env, 14); // rdzchk
    v_22295 = (*qfnn(fn))(fn, 3, stack[-2], stack[-1], v_22295);
    env = stack[-4];
    {
        fn = elt(env, 15); // mkround
        return (*qfn1(fn))(fn, v_22295);
    }
    goto v_22099;
    v_22295 = nil;
v_22099:
    return onevalue(v_22295);
}



// Code for indxsymp

static LispObject CC_indxsymp(LispObject env,
                         LispObject v_22093, LispObject v_22094)
{
    env = qenv(env);
    LispObject v_22129, v_22130;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22093,v_22094);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22094;
    stack[-1] = v_22093;
// end of prologue
v_22092:
    v_22129 = stack[0];
    if (v_22129 == nil) goto v_22098;
    else goto v_22099;
v_22098:
    v_22129 = lisp_true;
    goto v_22097;
v_22099:
    goto v_22113;
v_22109:
    v_22129 = stack[0];
    v_22130 = qcar(v_22129);
    goto v_22110;
v_22111:
    v_22129 = stack[-1];
    goto v_22112;
v_22113:
    goto v_22109;
v_22110:
    goto v_22111;
v_22112:
    v_22129 = Lapply1(nil, v_22130, v_22129);
    env = stack[-2];
    if (v_22129 == nil) goto v_22106;
    else goto v_22107;
v_22106:
    v_22129 = nil;
    goto v_22105;
v_22107:
    goto v_22125;
v_22121:
    v_22130 = stack[-1];
    goto v_22122;
v_22123:
    v_22129 = stack[0];
    v_22129 = qcdr(v_22129);
    goto v_22124;
v_22125:
    goto v_22121;
v_22122:
    goto v_22123;
v_22124:
    stack[-1] = v_22130;
    stack[0] = v_22129;
    goto v_22092;
    v_22129 = nil;
v_22105:
    goto v_22097;
    v_22129 = nil;
v_22097:
    return onevalue(v_22129);
}



// Code for calc_coeffmap_

static LispObject CC_calc_coeffmap_(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22138, v_22139, v_22140;
    LispObject fn;
    LispObject v_22095, v_22094, v_22093;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "calc_coeffmap_");
    va_start(aa, nargs);
    v_22093 = va_arg(aa, LispObject);
    v_22094 = va_arg(aa, LispObject);
    v_22095 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22095,v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22093,v_22094,v_22095);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_22095;
    stack[-2] = v_22094;
    v_22138 = v_22093;
// end of prologue
    goto v_22102;
v_22098:
    v_22139 = v_22138;
    goto v_22099;
v_22100:
    v_22138 = stack[-1];
    goto v_22101;
v_22102:
    goto v_22098;
v_22099:
    goto v_22100;
v_22101:
    fn = elt(env, 2); // calc_map_
    v_22138 = (*qfn2(fn))(fn, v_22139, v_22138);
    env = stack[-4];
    v_22140 = v_22138;
    goto v_22114;
v_22110:
    v_22139 = v_22140;
    goto v_22111;
v_22112:
    v_22138 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22113;
v_22114:
    goto v_22110;
v_22111:
    goto v_22112;
v_22113:
    if (v_22139 == v_22138) goto v_22108;
    else goto v_22109;
v_22108:
    v_22138 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22107;
v_22109:
    goto v_22127;
v_22121:
    stack[-3] = elt(env, 1); // times
    goto v_22122;
v_22123:
    stack[0] = v_22140;
    goto v_22124;
v_22125:
    goto v_22135;
v_22131:
    v_22139 = stack[-2];
    goto v_22132;
v_22133:
    v_22138 = stack[-1];
    goto v_22134;
v_22135:
    goto v_22131;
v_22132:
    goto v_22133;
v_22134:
    fn = elt(env, 3); // calc_coeff
    v_22138 = (*qfn2(fn))(fn, v_22139, v_22138);
    goto v_22126;
v_22127:
    goto v_22121;
v_22122:
    goto v_22123;
v_22124:
    goto v_22125;
v_22126:
    {
        LispObject v_22145 = stack[-3];
        LispObject v_22146 = stack[0];
        return list2star(v_22145, v_22146, v_22138);
    }
    v_22138 = nil;
v_22107:
    return onevalue(v_22138);
}



// Code for prepsq!*1

static LispObject CC_prepsqH1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22804, v_22805, v_22806;
    LispObject fn;
    LispObject v_22095, v_22094, v_22093;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "prepsq*1");
    va_start(aa, nargs);
    v_22093 = va_arg(aa, LispObject);
    v_22094 = va_arg(aa, LispObject);
    v_22095 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22095,v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22093,v_22094,v_22095);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_22095;
    stack[-5] = v_22094;
    stack[-6] = v_22093;
// end of prologue
    v_22804 = stack[-6];
    if (!consp(v_22804)) goto v_22112;
    else goto v_22113;
v_22112:
    v_22804 = lisp_true;
    goto v_22111;
v_22113:
    v_22804 = stack[-6];
    v_22804 = qcar(v_22804);
    v_22804 = (consp(v_22804) ? nil : lisp_true);
    goto v_22111;
    v_22804 = nil;
v_22111:
    if (v_22804 == nil) goto v_22108;
    else goto v_22109;
v_22108:
    goto v_22128;
v_22124:
    v_22804 = stack[-6];
    v_22804 = qcar(v_22804);
    v_22804 = qcar(v_22804);
    v_22805 = qcar(v_22804);
    goto v_22125;
v_22126:
    v_22804 = qvalue(elt(env, 1)); // factors!*
    goto v_22127;
v_22128:
    goto v_22124;
v_22125:
    goto v_22126;
v_22127:
    v_22804 = Lmember(nil, v_22805, v_22804);
    if (v_22804 == nil) goto v_22123;
    else goto v_22122;
v_22123:
    v_22804 = stack[-6];
    v_22804 = qcar(v_22804);
    v_22804 = qcar(v_22804);
    v_22804 = qcar(v_22804);
    if (!consp(v_22804)) goto v_22138;
    goto v_22147;
v_22143:
    v_22804 = stack[-6];
    v_22804 = qcar(v_22804);
    v_22804 = qcar(v_22804);
    v_22804 = qcar(v_22804);
    v_22805 = qcar(v_22804);
    goto v_22144;
v_22145:
    v_22804 = qvalue(elt(env, 1)); // factors!*
    goto v_22146;
v_22147:
    goto v_22143;
v_22144:
    goto v_22145;
v_22146:
    v_22804 = Lmember(nil, v_22805, v_22804);
    goto v_22136;
v_22138:
    v_22804 = nil;
    goto v_22136;
    v_22804 = nil;
v_22136:
v_22122:
    goto v_22107;
v_22109:
    v_22804 = nil;
    goto v_22107;
    v_22804 = nil;
v_22107:
    if (v_22804 == nil) goto v_22105;
    goto v_22166;
v_22162:
    goto v_22175;
v_22171:
    v_22805 = stack[-5];
    goto v_22172;
v_22173:
    v_22804 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22174;
v_22175:
    goto v_22171;
v_22172:
    goto v_22173;
v_22174:
    if (v_22805 == v_22804) goto v_22169;
    else goto v_22170;
v_22169:
    goto v_22183;
v_22179:
    goto v_22189;
v_22185:
    v_22804 = stack[-6];
    v_22804 = qcar(v_22804);
    v_22805 = qcdr(v_22804);
    goto v_22186;
v_22187:
    v_22804 = stack[-5];
    goto v_22188;
v_22189:
    goto v_22185;
v_22186:
    goto v_22187;
v_22188:
    stack[0] = cons(v_22805, v_22804);
    env = stack[-8];
    goto v_22180;
v_22181:
    goto v_22199;
v_22195:
    v_22804 = stack[-6];
    v_22804 = qcar(v_22804);
    v_22805 = qcar(v_22804);
    goto v_22196;
v_22197:
    v_22804 = stack[-4];
    goto v_22198;
v_22199:
    goto v_22195;
v_22196:
    goto v_22197;
v_22198:
    v_22804 = cons(v_22805, v_22804);
    env = stack[-8];
    goto v_22182;
v_22183:
    goto v_22179;
v_22180:
    goto v_22181;
v_22182:
    fn = elt(env, 10); // prepsq!*0
    v_22804 = (*qfn2(fn))(fn, stack[0], v_22804);
    env = stack[-8];
    stack[0] = v_22804;
    goto v_22168;
v_22170:
    v_22804 = stack[-6];
    v_22804 = qcar(v_22804);
    v_22804 = qcar(v_22804);
    v_22804 = qcdr(v_22804);
    stack[-2] = v_22804;
    v_22804 = stack[-5];
    stack[-1] = v_22804;
    goto v_22222;
v_22218:
    goto v_22228;
v_22224:
    v_22804 = stack[-6];
    v_22804 = qcar(v_22804);
    v_22804 = qcar(v_22804);
    v_22805 = qcar(v_22804);
    goto v_22225;
v_22226:
    v_22804 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22227;
v_22228:
    goto v_22224;
v_22225:
    goto v_22226;
v_22227:
    fn = elt(env, 11); // to
    v_22805 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    goto v_22219;
v_22220:
    v_22804 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22221;
v_22222:
    goto v_22218;
v_22219:
    goto v_22220;
v_22221:
    v_22804 = cons(v_22805, v_22804);
    env = stack[-8];
    v_22804 = ncons(v_22804);
    env = stack[-8];
    stack[0] = v_22804;
v_22237:
    goto v_22247;
v_22243:
    v_22805 = stack[-1];
    goto v_22244;
v_22245:
    v_22804 = stack[0];
    goto v_22246;
v_22247:
    goto v_22243;
v_22244:
    goto v_22245;
v_22246:
    fn = elt(env, 12); // quotfm
    v_22804 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    stack[-7] = v_22804;
    if (v_22804 == nil) goto v_22240;
    else goto v_22241;
v_22240:
    goto v_22236;
v_22241:
    v_22804 = stack[-7];
    stack[-1] = v_22804;
    v_22804 = stack[-2];
    v_22804 = sub1(v_22804);
    env = stack[-8];
    stack[-2] = v_22804;
    goto v_22237;
v_22236:
    goto v_22259;
v_22255:
    goto v_22265;
v_22261:
    v_22804 = stack[-6];
    v_22804 = qcar(v_22804);
    v_22805 = qcdr(v_22804);
    goto v_22262;
v_22263:
    v_22804 = stack[-1];
    goto v_22264;
v_22265:
    goto v_22261;
v_22262:
    goto v_22263;
v_22264:
    stack[0] = cons(v_22805, v_22804);
    env = stack[-8];
    goto v_22256;
v_22257:
    goto v_22279;
v_22275:
    v_22805 = stack[-2];
    goto v_22276;
v_22277:
    v_22804 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22278;
v_22279:
    goto v_22275;
v_22276:
    goto v_22277;
v_22278:
    v_22804 = (LispObject)greaterp2(v_22805, v_22804);
    v_22804 = v_22804 ? lisp_true : nil;
    env = stack[-8];
    if (v_22804 == nil) goto v_22273;
    goto v_22287;
v_22283:
    goto v_22293;
v_22289:
    v_22804 = stack[-6];
    v_22804 = qcar(v_22804);
    v_22804 = qcar(v_22804);
    v_22805 = qcar(v_22804);
    goto v_22290;
v_22291:
    v_22804 = stack[-2];
    goto v_22292;
v_22293:
    goto v_22289;
v_22290:
    goto v_22291;
v_22292:
    fn = elt(env, 11); // to
    v_22805 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    goto v_22284;
v_22285:
    v_22804 = stack[-4];
    goto v_22286;
v_22287:
    goto v_22283;
v_22284:
    goto v_22285;
v_22286:
    v_22804 = cons(v_22805, v_22804);
    env = stack[-8];
    goto v_22271;
v_22273:
    goto v_22307;
v_22303:
    v_22805 = stack[-2];
    goto v_22304;
v_22305:
    v_22804 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22306;
v_22307:
    goto v_22303;
v_22304:
    goto v_22305;
v_22306:
    v_22804 = (LispObject)lessp2(v_22805, v_22804);
    v_22804 = v_22804 ? lisp_true : nil;
    env = stack[-8];
    if (v_22804 == nil) goto v_22301;
    goto v_22315;
v_22311:
    goto v_22321;
v_22317:
    goto v_22329;
v_22323:
    v_22806 = elt(env, 2); // expt
    goto v_22324;
v_22325:
    v_22804 = stack[-6];
    v_22804 = qcar(v_22804);
    v_22804 = qcar(v_22804);
    v_22805 = qcar(v_22804);
    goto v_22326;
v_22327:
    v_22804 = stack[-2];
    goto v_22328;
v_22329:
    goto v_22323;
v_22324:
    goto v_22325;
v_22326:
    goto v_22327;
v_22328:
    v_22805 = list3(v_22806, v_22805, v_22804);
    env = stack[-8];
    goto v_22318;
v_22319:
    v_22804 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22320;
v_22321:
    goto v_22317;
v_22318:
    goto v_22319;
v_22320:
    fn = elt(env, 13); // mksp
    v_22805 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    goto v_22312;
v_22313:
    v_22804 = stack[-4];
    goto v_22314;
v_22315:
    goto v_22311;
v_22312:
    goto v_22313;
v_22314:
    v_22804 = cons(v_22805, v_22804);
    env = stack[-8];
    goto v_22271;
v_22301:
    v_22804 = stack[-4];
    goto v_22271;
    v_22804 = nil;
v_22271:
    goto v_22258;
v_22259:
    goto v_22255;
v_22256:
    goto v_22257;
v_22258:
    fn = elt(env, 10); // prepsq!*0
    v_22804 = (*qfn2(fn))(fn, stack[0], v_22804);
    env = stack[-8];
    stack[0] = v_22804;
    goto v_22168;
    stack[0] = nil;
v_22168:
    goto v_22163;
v_22164:
    goto v_22346;
v_22342:
    goto v_22352;
v_22348:
    v_22804 = stack[-6];
    v_22805 = qcdr(v_22804);
    goto v_22349;
v_22350:
    v_22804 = stack[-5];
    goto v_22351;
v_22352:
    goto v_22348;
v_22349:
    goto v_22350;
v_22351:
    v_22805 = cons(v_22805, v_22804);
    env = stack[-8];
    goto v_22343;
v_22344:
    v_22804 = stack[-4];
    goto v_22345;
v_22346:
    goto v_22342;
v_22343:
    goto v_22344;
v_22345:
    fn = elt(env, 10); // prepsq!*0
    v_22804 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    goto v_22165;
v_22166:
    goto v_22162;
v_22163:
    goto v_22164;
v_22165:
    {
        LispObject v_22815 = stack[0];
        fn = elt(env, 14); // nconc!*
        return (*qfn2(fn))(fn, v_22815, v_22804);
    }
v_22105:
    v_22804 = stack[-5];
    if (!consp(v_22804)) goto v_22363;
    else goto v_22364;
v_22363:
    v_22804 = lisp_true;
    goto v_22362;
v_22364:
    v_22804 = stack[-5];
    v_22804 = qcar(v_22804);
    v_22804 = (consp(v_22804) ? nil : lisp_true);
    goto v_22362;
    v_22804 = nil;
v_22362:
    if (v_22804 == nil) goto v_22359;
    else goto v_22360;
v_22359:
    v_22804 = qvalue(elt(env, 3)); // kord!*
    stack[-3] = v_22804;
v_22375:
    v_22804 = stack[-3];
    if (v_22804 == nil) goto v_22379;
    else goto v_22380;
v_22379:
    goto v_22374;
v_22380:
    v_22804 = stack[-3];
    v_22804 = qcar(v_22804);
    stack[-2] = v_22804;
    v_22804 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_22804;
    goto v_22398;
v_22394:
    goto v_22404;
v_22400:
    v_22805 = stack[-2];
    goto v_22401;
v_22402:
    v_22804 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22403;
v_22404:
    goto v_22400;
v_22401:
    goto v_22402;
v_22403:
    fn = elt(env, 11); // to
    v_22805 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    goto v_22395;
v_22396:
    v_22804 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22397;
v_22398:
    goto v_22394;
v_22395:
    goto v_22396;
v_22397:
    v_22804 = cons(v_22805, v_22804);
    env = stack[-8];
    v_22804 = ncons(v_22804);
    env = stack[-8];
    stack[0] = v_22804;
v_22410:
    goto v_22420;
v_22416:
    v_22805 = stack[-5];
    goto v_22417;
v_22418:
    v_22804 = stack[0];
    goto v_22419;
v_22420:
    goto v_22416;
v_22417:
    goto v_22418;
v_22419:
    fn = elt(env, 12); // quotfm
    v_22804 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    stack[-7] = v_22804;
    if (v_22804 == nil) goto v_22413;
    else goto v_22414;
v_22413:
    goto v_22409;
v_22414:
    v_22804 = stack[-1];
    v_22804 = sub1(v_22804);
    env = stack[-8];
    stack[-1] = v_22804;
    v_22804 = stack[-7];
    stack[-5] = v_22804;
    goto v_22410;
v_22409:
    goto v_22436;
v_22432:
    v_22805 = stack[-1];
    goto v_22433;
v_22434:
    v_22804 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22435;
v_22436:
    goto v_22432;
v_22433:
    goto v_22434;
v_22435:
    v_22804 = (LispObject)lessp2(v_22805, v_22804);
    v_22804 = v_22804 ? lisp_true : nil;
    env = stack[-8];
    if (v_22804 == nil) goto v_22430;
    goto v_22444;
v_22440:
    goto v_22450;
v_22446:
    goto v_22458;
v_22452:
    v_22806 = elt(env, 2); // expt
    goto v_22453;
v_22454:
    v_22805 = stack[-2];
    goto v_22455;
v_22456:
    v_22804 = stack[-1];
    goto v_22457;
v_22458:
    goto v_22452;
v_22453:
    goto v_22454;
v_22455:
    goto v_22456;
v_22457:
    v_22805 = list3(v_22806, v_22805, v_22804);
    env = stack[-8];
    goto v_22447;
v_22448:
    v_22804 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22449;
v_22450:
    goto v_22446;
v_22447:
    goto v_22448;
v_22449:
    fn = elt(env, 13); // mksp
    v_22805 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    goto v_22441;
v_22442:
    v_22804 = stack[-4];
    goto v_22443;
v_22444:
    goto v_22440;
v_22441:
    goto v_22442;
v_22443:
    v_22804 = cons(v_22805, v_22804);
    env = stack[-8];
    stack[-4] = v_22804;
    goto v_22428;
v_22430:
v_22428:
    v_22804 = stack[-3];
    v_22804 = qcdr(v_22804);
    stack[-3] = v_22804;
    goto v_22375;
v_22374:
    goto v_22358;
v_22360:
v_22358:
    v_22804 = stack[-6];
    fn = elt(env, 15); // kernlp
    v_22804 = (*qfn1(fn))(fn, v_22804);
    env = stack[-8];
    if (v_22804 == nil) goto v_22469;
    goto v_22477;
v_22473:
    v_22805 = stack[-4];
    goto v_22474;
v_22475:
    v_22804 = stack[-6];
    goto v_22476;
v_22477:
    goto v_22473;
v_22474:
    goto v_22475;
v_22476:
    fn = elt(env, 16); // mkkl
    v_22804 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    stack[-6] = v_22804;
    v_22804 = nil;
    stack[-4] = v_22804;
    goto v_22467;
v_22469:
v_22467:
    v_22804 = qvalue(elt(env, 4)); // dnl!*
    if (v_22804 == nil) goto v_22484;
    v_22804 = qvalue(elt(env, 5)); // !*allfac
    if (v_22804 == nil) goto v_22488;
    else goto v_22489;
v_22488:
    v_22804 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22487;
v_22489:
    v_22804 = stack[-6];
    fn = elt(env, 17); // ckrn
    v_22804 = (*qfn1(fn))(fn, v_22804);
    env = stack[-8];
    goto v_22487;
    v_22804 = nil;
v_22487:
    stack[-1] = v_22804;
    goto v_22501;
v_22497:
    v_22805 = stack[-1];
    goto v_22498;
v_22499:
    v_22804 = qvalue(elt(env, 4)); // dnl!*
    goto v_22500;
v_22501:
    goto v_22497;
v_22498:
    goto v_22499;
v_22500:
    fn = elt(env, 18); // ckrn!*
    v_22804 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    stack[-7] = v_22804;
    goto v_22509;
v_22505:
    v_22805 = stack[-1];
    goto v_22506;
v_22507:
    v_22804 = stack[-7];
    goto v_22508;
v_22509:
    goto v_22505;
v_22506:
    goto v_22507;
v_22508:
    fn = elt(env, 19); // quotof
    v_22804 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    goto v_22517;
v_22513:
    v_22805 = stack[-6];
    goto v_22514;
v_22515:
    v_22804 = stack[-7];
    goto v_22516;
v_22517:
    goto v_22513;
v_22514:
    goto v_22515;
v_22516:
    fn = elt(env, 19); // quotof
    v_22804 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    stack[-6] = v_22804;
    goto v_22525;
v_22521:
    v_22805 = stack[-5];
    goto v_22522;
v_22523:
    v_22804 = stack[-7];
    goto v_22524;
v_22525:
    goto v_22521;
v_22522:
    goto v_22523;
v_22524:
    fn = elt(env, 19); // quotof
    v_22804 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    stack[-5] = v_22804;
    goto v_22482;
v_22484:
v_22482:
    v_22804 = qvalue(elt(env, 6)); // upl!*
    if (v_22804 == nil) goto v_22531;
    v_22804 = stack[-5];
    fn = elt(env, 17); // ckrn
    v_22804 = (*qfn1(fn))(fn, v_22804);
    env = stack[-8];
    stack[0] = v_22804;
    goto v_22540;
v_22536:
    v_22805 = stack[0];
    goto v_22537;
v_22538:
    v_22804 = qvalue(elt(env, 6)); // upl!*
    goto v_22539;
v_22540:
    goto v_22536;
v_22537:
    goto v_22538;
v_22539:
    fn = elt(env, 18); // ckrn!*
    v_22804 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    stack[-7] = v_22804;
    goto v_22548;
v_22544:
    v_22805 = stack[0];
    goto v_22545;
v_22546:
    v_22804 = stack[-7];
    goto v_22547;
v_22548:
    goto v_22544;
v_22545:
    goto v_22546;
v_22547:
    fn = elt(env, 19); // quotof
    v_22804 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    stack[0] = v_22804;
    goto v_22556;
v_22552:
    v_22805 = stack[-6];
    goto v_22553;
v_22554:
    v_22804 = stack[-7];
    goto v_22555;
v_22556:
    goto v_22552;
v_22553:
    goto v_22554;
v_22555:
    fn = elt(env, 19); // quotof
    v_22804 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    stack[-6] = v_22804;
    goto v_22564;
v_22560:
    v_22805 = stack[-5];
    goto v_22561;
v_22562:
    v_22804 = stack[-7];
    goto v_22563;
v_22564:
    goto v_22560;
v_22561:
    goto v_22562;
v_22563:
    fn = elt(env, 19); // quotof
    v_22804 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    stack[-5] = v_22804;
    goto v_22529;
v_22531:
    v_22804 = qvalue(elt(env, 7)); // !*div
    if (v_22804 == nil) goto v_22568;
    v_22804 = stack[-5];
    fn = elt(env, 17); // ckrn
    v_22804 = (*qfn1(fn))(fn, v_22804);
    env = stack[-8];
    stack[0] = v_22804;
    goto v_22529;
v_22568:
    v_22804 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_22804;
    goto v_22529;
v_22529:
    goto v_22581;
v_22577:
    stack[-1] = stack[-6];
    goto v_22578;
v_22579:
    goto v_22588;
v_22584:
    v_22805 = stack[-5];
    goto v_22585;
v_22586:
    v_22804 = stack[0];
    goto v_22587;
v_22588:
    goto v_22584;
v_22585:
    goto v_22586;
v_22587:
    fn = elt(env, 19); // quotof
    v_22804 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    goto v_22580;
v_22581:
    goto v_22577;
v_22578:
    goto v_22579;
v_22580:
    v_22804 = cons(stack[-1], v_22804);
    env = stack[-8];
    fn = elt(env, 20); // canonsq
    v_22804 = (*qfn1(fn))(fn, v_22804);
    env = stack[-8];
    stack[-6] = v_22804;
    goto v_22596;
v_22592:
    goto v_22602;
v_22598:
    v_22804 = stack[-6];
    v_22805 = qcar(v_22804);
    goto v_22599;
v_22600:
    v_22804 = stack[0];
    goto v_22601;
v_22602:
    goto v_22598;
v_22599:
    goto v_22600;
v_22601:
    fn = elt(env, 19); // quotof
    v_22805 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    goto v_22593;
v_22594:
    v_22804 = stack[-6];
    v_22804 = qcdr(v_22804);
    goto v_22595;
v_22596:
    goto v_22592;
v_22593:
    goto v_22594;
v_22595:
    v_22804 = cons(v_22805, v_22804);
    env = stack[-8];
    stack[-6] = v_22804;
    v_22804 = qvalue(elt(env, 5)); // !*allfac
    if (v_22804 == nil) goto v_22611;
    v_22804 = stack[-6];
    v_22804 = qcar(v_22804);
    fn = elt(env, 17); // ckrn
    v_22804 = (*qfn1(fn))(fn, v_22804);
    env = stack[-8];
    stack[-1] = v_22804;
    v_22804 = stack[-6];
    v_22804 = qcdr(v_22804);
    fn = elt(env, 17); // ckrn
    v_22804 = (*qfn1(fn))(fn, v_22804);
    env = stack[-8];
    stack[0] = v_22804;
    goto v_22635;
v_22631:
    v_22805 = stack[-1];
    goto v_22632;
v_22633:
    v_22804 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22634;
v_22635:
    goto v_22631;
v_22632:
    goto v_22633;
v_22634:
    if (v_22805 == v_22804) goto v_22630;
    v_22804 = lisp_true;
    goto v_22628;
v_22630:
    goto v_22646;
v_22642:
    v_22805 = stack[0];
    goto v_22643;
v_22644:
    v_22804 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22645;
v_22646:
    goto v_22642;
v_22643:
    goto v_22644;
v_22645:
    v_22804 = Lneq(nil, v_22805, v_22804);
    env = stack[-8];
    goto v_22628;
    v_22804 = nil;
v_22628:
    if (v_22804 == nil) goto v_22626;
    goto v_22657;
v_22653:
    v_22805 = stack[-1];
    goto v_22654;
v_22655:
    v_22804 = stack[-6];
    v_22804 = qcar(v_22804);
    goto v_22656;
v_22657:
    goto v_22653;
v_22654:
    goto v_22655;
v_22656:
    if (equal(v_22805, v_22804)) goto v_22652;
    v_22804 = lisp_true;
    goto v_22650;
v_22652:
    goto v_22669;
v_22665:
    v_22805 = stack[0];
    goto v_22666;
v_22667:
    v_22804 = stack[-6];
    v_22804 = qcdr(v_22804);
    goto v_22668;
v_22669:
    goto v_22665;
v_22666:
    goto v_22667;
v_22668:
    v_22804 = Lneq(nil, v_22805, v_22804);
    env = stack[-8];
    goto v_22650;
    v_22804 = nil;
v_22650:
    goto v_22624;
v_22626:
    v_22804 = nil;
    goto v_22624;
    v_22804 = nil;
v_22624:
    if (v_22804 == nil) goto v_22622;
    goto v_22681;
v_22677:
    v_22804 = stack[-6];
    v_22805 = qcdr(v_22804);
    goto v_22678;
v_22679:
    v_22804 = stack[0];
    goto v_22680;
v_22681:
    goto v_22677;
v_22678:
    goto v_22679;
v_22680:
    fn = elt(env, 19); // quotof
    v_22804 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    stack[-5] = v_22804;
    goto v_22690;
v_22686:
    v_22804 = stack[-6];
    v_22805 = qcar(v_22804);
    goto v_22687;
v_22688:
    v_22804 = stack[-1];
    goto v_22689;
v_22690:
    goto v_22686;
v_22687:
    goto v_22688;
v_22689:
    fn = elt(env, 19); // quotof
    v_22804 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    stack[-6] = v_22804;
    goto v_22700;
v_22696:
    v_22805 = stack[-4];
    goto v_22697;
v_22698:
    v_22804 = stack[-1];
    goto v_22699;
v_22700:
    goto v_22696;
v_22697:
    goto v_22698;
v_22699:
    fn = elt(env, 16); // mkkl
    v_22804 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    fn = elt(env, 21); // prepf
    v_22804 = (*qfn1(fn))(fn, v_22804);
    env = stack[-8];
    stack[-4] = v_22804;
    v_22804 = stack[0];
    fn = elt(env, 21); // prepf
    v_22804 = (*qfn1(fn))(fn, v_22804);
    env = stack[-8];
    stack[-1] = v_22804;
    goto v_22710;
v_22706:
    v_22805 = stack[-4];
    goto v_22707;
v_22708:
    v_22804 = stack[-6];
    goto v_22709;
v_22710:
    goto v_22706;
v_22707:
    goto v_22708;
v_22709:
    fn = elt(env, 22); // addfactors
    v_22804 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    stack[-6] = v_22804;
    goto v_22718;
v_22714:
    v_22805 = stack[-1];
    goto v_22715;
v_22716:
    v_22804 = stack[-5];
    goto v_22717;
v_22718:
    goto v_22714;
v_22715:
    goto v_22716;
v_22717:
    fn = elt(env, 22); // addfactors
    v_22804 = (*qfn2(fn))(fn, v_22805, v_22804);
    env = stack[-8];
    stack[-5] = v_22804;
    goto v_22729;
v_22725:
    v_22805 = stack[-5];
    goto v_22726;
v_22727:
    v_22804 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22728;
v_22729:
    goto v_22725;
v_22726:
    goto v_22727;
v_22728:
    if (v_22805 == v_22804) goto v_22723;
    else goto v_22724;
v_22723:
    v_22804 = stack[-6];
    {
        fn = elt(env, 23); // rmplus
        return (*qfn1(fn))(fn, v_22804);
    }
v_22724:
    goto v_22746;
v_22742:
    v_22805 = stack[-6];
    goto v_22743;
v_22744:
    v_22804 = elt(env, 8); // minus
    goto v_22745;
v_22746:
    goto v_22742;
v_22743:
    goto v_22744;
v_22745:
    if (!consp(v_22805)) goto v_22740;
    v_22805 = qcar(v_22805);
    if (v_22805 == v_22804) goto v_22739;
    else goto v_22740;
v_22739:
    goto v_22754;
v_22750:
    stack[0] = elt(env, 8); // minus
    goto v_22751;
v_22752:
    goto v_22763;
v_22757:
    v_22806 = elt(env, 9); // quotient
    goto v_22758;
v_22759:
    v_22804 = stack[-6];
    v_22804 = qcdr(v_22804);
    v_22805 = qcar(v_22804);
    goto v_22760;
v_22761:
    v_22804 = stack[-5];
    goto v_22762;
v_22763:
    goto v_22757;
v_22758:
    goto v_22759;
v_22760:
    goto v_22761;
v_22762:
    v_22804 = list3(v_22806, v_22805, v_22804);
    env = stack[-8];
    goto v_22753;
v_22754:
    goto v_22750;
v_22751:
    goto v_22752;
v_22753:
    v_22804 = list2(stack[0], v_22804);
    goto v_22738;
v_22740:
    goto v_22778;
v_22772:
    v_22806 = elt(env, 9); // quotient
    goto v_22773;
v_22774:
    v_22805 = stack[-6];
    goto v_22775;
v_22776:
    v_22804 = stack[-5];
    goto v_22777;
v_22778:
    goto v_22772;
v_22773:
    goto v_22774;
v_22775:
    goto v_22776;
v_22777:
    v_22804 = list3(v_22806, v_22805, v_22804);
    goto v_22738;
    v_22804 = nil;
v_22738:
    return ncons(v_22804);
    v_22804 = nil;
    goto v_22101;
v_22622:
    goto v_22609;
v_22611:
v_22609:
    v_22804 = stack[-4];
    if (v_22804 == nil) goto v_22785;
    goto v_22794;
v_22790:
    v_22804 = stack[-4];
    fn = elt(env, 24); // exchk
    stack[0] = (*qfn1(fn))(fn, v_22804);
    env = stack[-8];
    goto v_22791;
v_22792:
    v_22804 = stack[-6];
    fn = elt(env, 25); // prepsq
    v_22804 = (*qfn1(fn))(fn, v_22804);
    env = stack[-8];
    goto v_22793;
v_22794:
    goto v_22790;
v_22791:
    goto v_22792;
v_22793:
    fn = elt(env, 26); // aconc!*
    v_22804 = (*qfn2(fn))(fn, stack[0], v_22804);
    env = stack[-8];
    fn = elt(env, 27); // retimes
    v_22804 = (*qfn1(fn))(fn, v_22804);
    return ncons(v_22804);
v_22785:
    v_22804 = stack[-6];
    fn = elt(env, 25); // prepsq
    v_22804 = (*qfn1(fn))(fn, v_22804);
    env = stack[-8];
    {
        fn = elt(env, 23); // rmplus
        return (*qfn1(fn))(fn, v_22804);
    }
    v_22804 = nil;
v_22101:
    return onevalue(v_22804);
}



// Code for ctx_union

static LispObject CC_ctx_union(LispObject env,
                         LispObject v_22093, LispObject v_22094)
{
    env = qenv(env);
    LispObject v_22249, v_22250;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22093,v_22094);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_22094;
    v_22249 = v_22093;
// end of prologue
    fn = elt(env, 4); // ctx_ial
    v_22249 = (*qfn1(fn))(fn, v_22249);
    env = stack[-5];
    stack[-4] = v_22249;
    v_22249 = stack[-4];
    if (v_22249 == nil) goto v_22111;
    else goto v_22112;
v_22111:
    v_22249 = nil;
    goto v_22105;
v_22112:
    v_22249 = stack[-4];
    v_22249 = qcar(v_22249);
    goto v_22124;
v_22120:
    v_22250 = v_22249;
    v_22250 = qcar(v_22250);
    goto v_22121;
v_22122:
    v_22249 = qcdr(v_22249);
    goto v_22123;
v_22124:
    goto v_22120;
v_22121:
    goto v_22122;
v_22123:
    v_22249 = cons(v_22250, v_22249);
    env = stack[-5];
    v_22249 = ncons(v_22249);
    env = stack[-5];
    stack[-1] = v_22249;
    stack[-3] = v_22249;
v_22106:
    v_22249 = stack[-4];
    v_22249 = qcdr(v_22249);
    stack[-4] = v_22249;
    v_22249 = stack[-4];
    if (v_22249 == nil) goto v_22133;
    else goto v_22134;
v_22133:
    v_22249 = stack[-3];
    goto v_22105;
v_22134:
    goto v_22142;
v_22138:
    stack[0] = stack[-1];
    goto v_22139;
v_22140:
    v_22249 = stack[-4];
    v_22249 = qcar(v_22249);
    goto v_22153;
v_22149:
    v_22250 = v_22249;
    v_22250 = qcar(v_22250);
    goto v_22150;
v_22151:
    v_22249 = qcdr(v_22249);
    goto v_22152;
v_22153:
    goto v_22149;
v_22150:
    goto v_22151;
v_22152:
    v_22249 = cons(v_22250, v_22249);
    env = stack[-5];
    v_22249 = ncons(v_22249);
    env = stack[-5];
    goto v_22141;
v_22142:
    goto v_22138;
v_22139:
    goto v_22140;
v_22141:
    v_22249 = Lrplacd(nil, stack[0], v_22249);
    env = stack[-5];
    v_22249 = stack[-1];
    v_22249 = qcdr(v_22249);
    stack[-1] = v_22249;
    goto v_22106;
v_22105:
    stack[-4] = v_22249;
    v_22249 = stack[-2];
    fn = elt(env, 4); // ctx_ial
    v_22249 = (*qfn1(fn))(fn, v_22249);
    env = stack[-5];
    stack[-3] = v_22249;
    v_22249 = stack[-3];
    if (v_22249 == nil) goto v_22170;
    else goto v_22171;
v_22170:
    v_22249 = nil;
    goto v_22164;
v_22171:
    v_22249 = stack[-3];
    v_22249 = qcar(v_22249);
    goto v_22183;
v_22179:
    v_22250 = v_22249;
    v_22250 = qcar(v_22250);
    goto v_22180;
v_22181:
    v_22249 = qcdr(v_22249);
    goto v_22182;
v_22183:
    goto v_22179;
v_22180:
    goto v_22181;
v_22182:
    v_22249 = cons(v_22250, v_22249);
    env = stack[-5];
    v_22249 = ncons(v_22249);
    env = stack[-5];
    stack[-1] = v_22249;
    stack[-2] = v_22249;
v_22165:
    v_22249 = stack[-3];
    v_22249 = qcdr(v_22249);
    stack[-3] = v_22249;
    v_22249 = stack[-3];
    if (v_22249 == nil) goto v_22192;
    else goto v_22193;
v_22192:
    v_22249 = stack[-2];
    goto v_22164;
v_22193:
    goto v_22201;
v_22197:
    stack[0] = stack[-1];
    goto v_22198;
v_22199:
    v_22249 = stack[-3];
    v_22249 = qcar(v_22249);
    goto v_22212;
v_22208:
    v_22250 = v_22249;
    v_22250 = qcar(v_22250);
    goto v_22209;
v_22210:
    v_22249 = qcdr(v_22249);
    goto v_22211;
v_22212:
    goto v_22208;
v_22209:
    goto v_22210;
v_22211:
    v_22249 = cons(v_22250, v_22249);
    env = stack[-5];
    v_22249 = ncons(v_22249);
    env = stack[-5];
    goto v_22200;
v_22201:
    goto v_22197;
v_22198:
    goto v_22199;
v_22200:
    v_22249 = Lrplacd(nil, stack[0], v_22249);
    env = stack[-5];
    v_22249 = stack[-1];
    v_22249 = qcdr(v_22249);
    stack[-1] = v_22249;
    goto v_22165;
v_22164:
    goto v_22224;
v_22220:
    goto v_22230;
v_22226:
    v_22250 = stack[-4];
    goto v_22227;
v_22228:
    goto v_22229;
v_22230:
    goto v_22226;
v_22227:
    goto v_22228;
v_22229:
    v_22250 = list2(v_22250, v_22249);
    env = stack[-5];
    goto v_22221;
v_22222:
    v_22249 = elt(env, 1); // arg1of2
    goto v_22223;
v_22224:
    goto v_22220;
v_22221:
    goto v_22222;
v_22223:
    fn = elt(env, 5); // lto_almerge
    v_22249 = (*qfn2(fn))(fn, v_22250, v_22249);
    env = stack[-5];
    goto v_22239;
v_22235:
    stack[0] = elt(env, 2); // ctx
    goto v_22236;
v_22237:
    goto v_22246;
v_22242:
    v_22250 = v_22249;
    goto v_22243;
v_22244:
    v_22249 = elt(env, 3); // ordopcar
    goto v_22245;
v_22246:
    goto v_22242;
v_22243:
    goto v_22244;
v_22245:
    fn = elt(env, 6); // sort
    v_22249 = (*qfn2(fn))(fn, v_22250, v_22249);
    goto v_22238;
v_22239:
    goto v_22235;
v_22236:
    goto v_22237;
v_22238:
    {
        LispObject v_22256 = stack[0];
        return list2(v_22256, v_22249);
    }
    return onevalue(v_22249);
}



// Code for createmonomunit

static LispObject CC_createmonomunit(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22121, v_22122, v_22123;
    argcheck(nargs, 0, "createmonomunit");
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
    v_22121 = (LispObject)16+TAG_FIXNUM; // 1
    v_22121 = Lmkvect(nil, v_22121);
    env = stack[-3];
    stack[-2] = v_22121;
    goto v_22105;
v_22099:
    v_22123 = stack[-2];
    goto v_22100;
v_22101:
    v_22122 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22102;
v_22103:
    v_22121 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22104;
v_22105:
    goto v_22099;
v_22100:
    goto v_22101;
v_22102:
    goto v_22103;
v_22104:
    *(LispObject *)((char *)v_22123 + (CELL-TAG_VECTOR) + (((intptr_t)v_22122-TAG_FIXNUM)/(16/CELL))) = v_22121;
    goto v_22115;
v_22109:
    stack[-1] = stack[-2];
    goto v_22110;
v_22111:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22112;
v_22113:
    v_22121 = nil;
    v_22121 = ncons(v_22121);
    goto v_22114;
v_22115:
    goto v_22109;
v_22110:
    goto v_22111;
v_22112:
    goto v_22113;
v_22114:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_22121;
    v_22121 = stack[-2];
    return onevalue(v_22121);
}



// Code for squashsqrt

static LispObject CC_squashsqrt(LispObject env,
                         LispObject v_22093)
{
    env = qenv(env);
    LispObject v_22295, v_22296, v_22297;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22093);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_22093;
// end of prologue
v_22092:
    v_22295 = qvalue(elt(env, 1)); // sqrtflag
    if (v_22295 == nil) goto v_22101;
    else goto v_22102;
v_22101:
    v_22295 = lisp_true;
    goto v_22100;
v_22102:
    v_22295 = stack[-1];
    if (!consp(v_22295)) goto v_22109;
    else goto v_22110;
v_22109:
    v_22295 = lisp_true;
    goto v_22108;
v_22110:
    v_22295 = stack[-1];
    v_22295 = qcar(v_22295);
    v_22295 = qcar(v_22295);
    v_22295 = qcar(v_22295);
    v_22295 = (consp(v_22295) ? nil : lisp_true);
    goto v_22108;
    v_22295 = nil;
v_22108:
    goto v_22100;
    v_22295 = nil;
v_22100:
    if (v_22295 == nil) goto v_22098;
    v_22295 = stack[-1];
    goto v_22096;
v_22098:
    goto v_22131;
v_22127:
    v_22295 = stack[-1];
    v_22295 = qcar(v_22295);
    v_22295 = qcar(v_22295);
    v_22295 = qcar(v_22295);
    v_22296 = qcar(v_22295);
    goto v_22128;
v_22129:
    v_22295 = elt(env, 2); // sqrt
    goto v_22130;
v_22131:
    goto v_22127;
v_22128:
    goto v_22129;
v_22130:
    if (v_22296 == v_22295) goto v_22125;
    else goto v_22126;
v_22125:
    goto v_22143;
v_22139:
    v_22295 = stack[-1];
    v_22295 = qcar(v_22295);
    v_22295 = qcar(v_22295);
    v_22296 = qcdr(v_22295);
    goto v_22140;
v_22141:
    v_22295 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22142;
v_22143:
    goto v_22139;
v_22140:
    goto v_22141;
v_22142:
    v_22295 = (LispObject)greaterp2(v_22296, v_22295);
    v_22295 = v_22295 ? lisp_true : nil;
    env = stack[-3];
    goto v_22124;
v_22126:
    v_22295 = nil;
    goto v_22124;
    v_22295 = nil;
v_22124:
    if (v_22295 == nil) goto v_22122;
    goto v_22157;
v_22153:
    v_22295 = stack[-1];
    v_22295 = qcdr(v_22295);
    stack[0] = CC_squashsqrt(elt(env, 0), v_22295);
    env = stack[-3];
    goto v_22154;
v_22155:
    goto v_22168;
v_22162:
    v_22295 = stack[-1];
    v_22295 = qcar(v_22295);
    v_22295 = qcar(v_22295);
    v_22297 = qcar(v_22295);
    goto v_22163;
v_22164:
    v_22295 = stack[-1];
    v_22295 = qcar(v_22295);
    v_22296 = qcdr(v_22295);
    goto v_22165;
v_22166:
    v_22295 = stack[-1];
    v_22295 = qcar(v_22295);
    v_22295 = qcar(v_22295);
    v_22295 = qcdr(v_22295);
    goto v_22167;
v_22168:
    goto v_22162;
v_22163:
    goto v_22164;
v_22165:
    goto v_22166;
v_22167:
    fn = elt(env, 4); // !*multfsqrt
    v_22295 = (*qfnn(fn))(fn, 3, v_22297, v_22296, v_22295);
    env = stack[-3];
    goto v_22156;
v_22157:
    goto v_22153;
v_22154:
    goto v_22155;
v_22156:
    {
        LispObject v_22301 = stack[0];
        fn = elt(env, 5); // addf
        return (*qfn2(fn))(fn, v_22301, v_22295);
    }
v_22122:
    goto v_22190;
v_22186:
    v_22295 = stack[-1];
    v_22295 = qcar(v_22295);
    v_22295 = qcar(v_22295);
    v_22295 = qcar(v_22295);
    v_22296 = qcar(v_22295);
    goto v_22187;
v_22188:
    v_22295 = elt(env, 3); // expt
    goto v_22189;
v_22190:
    goto v_22186;
v_22187:
    goto v_22188;
v_22189:
    if (v_22296 == v_22295) goto v_22184;
    else goto v_22185;
v_22184:
    v_22295 = stack[-1];
    v_22295 = qcar(v_22295);
    v_22295 = qcar(v_22295);
    v_22295 = qcar(v_22295);
    v_22295 = qcdr(v_22295);
    v_22295 = qcdr(v_22295);
    v_22295 = qcar(v_22295);
    fn = elt(env, 6); // prefix!-rational!-numberp
    v_22295 = (*qfn1(fn))(fn, v_22295);
    env = stack[-3];
    if (v_22295 == nil) goto v_22199;
    else goto v_22200;
v_22199:
    v_22295 = nil;
    goto v_22198;
v_22200:
    goto v_22217;
v_22213:
    v_22295 = stack[-1];
    v_22295 = qcar(v_22295);
    v_22295 = qcar(v_22295);
    v_22296 = qcdr(v_22295);
    goto v_22214;
v_22215:
    v_22295 = stack[-1];
    v_22295 = qcar(v_22295);
    v_22295 = qcar(v_22295);
    v_22295 = qcar(v_22295);
    v_22295 = qcdr(v_22295);
    v_22295 = qcdr(v_22295);
    v_22295 = qcar(v_22295);
    v_22295 = qcdr(v_22295);
    v_22295 = qcdr(v_22295);
    v_22295 = qcar(v_22295);
    goto v_22216;
v_22217:
    goto v_22213;
v_22214:
    goto v_22215;
v_22216:
    v_22295 = (LispObject)geq2(v_22296, v_22295);
    v_22295 = v_22295 ? lisp_true : nil;
    env = stack[-3];
    goto v_22198;
    v_22295 = nil;
v_22198:
    goto v_22183;
v_22185:
    v_22295 = nil;
    goto v_22183;
    v_22295 = nil;
v_22183:
    if (v_22295 == nil) goto v_22181;
    goto v_22240;
v_22236:
    v_22295 = stack[-1];
    v_22295 = qcdr(v_22295);
    stack[0] = CC_squashsqrt(elt(env, 0), v_22295);
    env = stack[-3];
    goto v_22237;
v_22238:
    goto v_22251;
v_22245:
    v_22295 = stack[-1];
    v_22295 = qcar(v_22295);
    v_22295 = qcar(v_22295);
    v_22297 = qcar(v_22295);
    goto v_22246;
v_22247:
    v_22295 = stack[-1];
    v_22295 = qcar(v_22295);
    v_22296 = qcdr(v_22295);
    goto v_22248;
v_22249:
    v_22295 = stack[-1];
    v_22295 = qcar(v_22295);
    v_22295 = qcar(v_22295);
    v_22295 = qcdr(v_22295);
    goto v_22250;
v_22251:
    goto v_22245;
v_22246:
    goto v_22247;
v_22248:
    goto v_22249;
v_22250:
    fn = elt(env, 7); // !*multfexpt
    v_22295 = (*qfnn(fn))(fn, 3, v_22297, v_22296, v_22295);
    env = stack[-3];
    goto v_22239;
v_22240:
    goto v_22236;
v_22237:
    goto v_22238;
v_22239:
    {
        LispObject v_22302 = stack[0];
        fn = elt(env, 5); // addf
        return (*qfn2(fn))(fn, v_22302, v_22295);
    }
v_22181:
    v_22295 = stack[-1];
    v_22295 = qcar(v_22295);
    v_22295 = qcdr(v_22295);
    v_22295 = CC_squashsqrt(elt(env, 0), v_22295);
    env = stack[-3];
    v_22296 = v_22295;
    v_22295 = v_22296;
    if (v_22295 == nil) goto v_22272;
    else goto v_22273;
v_22272:
    v_22295 = stack[-1];
    v_22295 = qcdr(v_22295);
    stack[-1] = v_22295;
    goto v_22092;
v_22273:
    goto v_22287;
v_22281:
    v_22295 = stack[-1];
    v_22295 = qcar(v_22295);
    stack[-2] = qcar(v_22295);
    goto v_22282;
v_22283:
    stack[0] = v_22296;
    goto v_22284;
v_22285:
    v_22295 = stack[-1];
    v_22295 = qcdr(v_22295);
    v_22295 = CC_squashsqrt(elt(env, 0), v_22295);
    goto v_22286;
v_22287:
    goto v_22281;
v_22282:
    goto v_22283;
v_22284:
    goto v_22285;
v_22286:
    {
        LispObject v_22303 = stack[-2];
        LispObject v_22304 = stack[0];
        return acons(v_22303, v_22304, v_22295);
    }
    v_22295 = nil;
    goto v_22096;
    v_22295 = nil;
v_22096:
    return onevalue(v_22295);
}



// Code for talp_nextt1

static LispObject CC_talp_nextt1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22387, v_22388, v_22389, v_22390, v_22391, v_22392, v_22393, v_22394;
    LispObject fn;
    LispObject v_22100, v_22099, v_22098, v_22097, v_22096, v_22095, v_22094, v_22093;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 8, "talp_nextt1");
    va_start(aa, nargs);
    v_22093 = va_arg(aa, LispObject);
    v_22094 = va_arg(aa, LispObject);
    v_22095 = va_arg(aa, LispObject);
    v_22096 = va_arg(aa, LispObject);
    v_22097 = va_arg(aa, LispObject);
    v_22098 = va_arg(aa, LispObject);
    v_22099 = va_arg(aa, LispObject);
    v_22100 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_22100,v_22099,v_22098,v_22097,v_22096,v_22095);
        push2(v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_22093,v_22094,v_22095,v_22096,v_22097,v_22098);
        pop2(v_22099,v_22100);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(13);
// copy arguments values to proper place
    stack[-3] = v_22100;
    stack[-4] = v_22099;
    stack[-5] = v_22098;
    stack[-6] = v_22097;
    stack[-7] = v_22096;
    stack[-8] = v_22095;
    stack[-9] = v_22094;
    stack[-10] = v_22093;
// end of prologue
    stack[-11] = nil;
    v_22387 = stack[-10];
    if (!consp(v_22387)) goto v_22109;
    else goto v_22110;
v_22109:
    goto v_22129;
v_22113:
    v_22394 = stack[-10];
    goto v_22114;
v_22115:
    v_22393 = stack[-9];
    goto v_22116;
v_22117:
    v_22392 = stack[-8];
    goto v_22118;
v_22119:
    v_22391 = stack[-7];
    goto v_22120;
v_22121:
    v_22390 = stack[-6];
    goto v_22122;
v_22123:
    v_22389 = stack[-5];
    goto v_22124;
v_22125:
    v_22388 = stack[-4];
    goto v_22126;
v_22127:
    v_22387 = stack[-3];
    goto v_22128;
v_22129:
    goto v_22113;
v_22114:
    goto v_22115;
v_22116:
    goto v_22117;
v_22118:
    goto v_22119;
v_22120:
    goto v_22121;
v_22122:
    goto v_22123;
v_22124:
    goto v_22125;
v_22126:
    goto v_22127;
v_22128:
    {
        fn = elt(env, 1); // talp_nextt!-atom
        return (*qfnn(fn))(fn, 8, v_22394, v_22393, v_22392, v_22391, v_22390, v_22389, v_22388, v_22387);
    }
v_22110:
    v_22387 = stack[-10];
    fn = elt(env, 2); // talp_invp
    v_22387 = (*qfn1(fn))(fn, v_22387);
    env = stack[-12];
    if (v_22387 == nil) goto v_22141;
    goto v_22161;
v_22145:
    v_22387 = stack[-10];
    fn = elt(env, 3); // talp_fargl
    v_22387 = (*qfn1(fn))(fn, v_22387);
    env = stack[-12];
    stack[0] = qcar(v_22387);
    goto v_22146;
v_22147:
    v_22387 = stack[-9];
    v_22393 = add1(v_22387);
    env = stack[-12];
    goto v_22148;
v_22149:
    v_22392 = stack[-8];
    goto v_22150;
v_22151:
    v_22391 = stack[-7];
    goto v_22152;
v_22153:
    v_22390 = stack[-6];
    goto v_22154;
v_22155:
    v_22389 = stack[-5];
    goto v_22156;
v_22157:
    v_22388 = stack[-4];
    goto v_22158;
v_22159:
    v_22387 = lisp_true;
    goto v_22160;
v_22161:
    goto v_22145;
v_22146:
    goto v_22147;
v_22148:
    goto v_22149;
v_22150:
    goto v_22151;
v_22152:
    goto v_22153;
v_22154:
    goto v_22155;
v_22156:
    goto v_22157;
v_22158:
    goto v_22159;
v_22160:
    v_22387 = CC_talp_nextt1(elt(env, 0), 8, stack[0], v_22393, v_22392, v_22391, v_22390, v_22389, v_22388, v_22387);
    env = stack[-12];
    v_22388 = v_22387;
    v_22387 = v_22388;
    v_22387 = qcar(v_22387);
    if (v_22387 == nil) goto v_22177;
    goto v_22185;
v_22181:
    stack[0] = stack[-10];
    goto v_22182;
v_22183:
    v_22387 = v_22388;
    v_22387 = qcdr(v_22387);
    v_22387 = ncons(v_22387);
    env = stack[-12];
    goto v_22184;
v_22185:
    goto v_22181;
v_22182:
    goto v_22183;
v_22184:
    fn = elt(env, 4); // setcdr
    v_22387 = (*qfn2(fn))(fn, stack[0], v_22387);
    goto v_22195;
v_22191:
    v_22388 = lisp_true;
    goto v_22192;
v_22193:
    v_22387 = stack[-10];
    goto v_22194;
v_22195:
    goto v_22191;
v_22192:
    goto v_22193;
v_22194:
    return cons(v_22388, v_22387);
v_22177:
    goto v_22139;
v_22141:
    v_22387 = stack[-10];
    fn = elt(env, 3); // talp_fargl
    v_22387 = (*qfn1(fn))(fn, v_22387);
    env = stack[-12];
    stack[-1] = v_22387;
    goto v_22206;
v_22202:
    v_22388 = stack[-7];
    goto v_22203;
v_22204:
    v_22387 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22205;
v_22206:
    goto v_22202;
v_22203:
    goto v_22204;
v_22205:
    v_22387 = *(LispObject *)((char *)v_22388 + (CELL-TAG_VECTOR) + (((intptr_t)v_22387-TAG_FIXNUM)/(16/CELL)));
    stack[-2] = v_22387;
v_22212:
    v_22387 = stack[-1];
    if (v_22387 == nil) goto v_22215;
    v_22387 = stack[-11];
    if (v_22387 == nil) goto v_22219;
    else goto v_22215;
v_22219:
    goto v_22216;
v_22215:
    goto v_22211;
v_22216:
    goto v_22239;
v_22223:
    v_22387 = stack[-1];
    stack[0] = qcar(v_22387);
    goto v_22224;
v_22225:
    v_22387 = stack[-9];
    v_22393 = add1(v_22387);
    env = stack[-12];
    goto v_22226;
v_22227:
    v_22392 = stack[-8];
    goto v_22228;
v_22229:
    v_22391 = stack[-7];
    goto v_22230;
v_22231:
    v_22390 = stack[-6];
    goto v_22232;
v_22233:
    v_22389 = stack[-5];
    goto v_22234;
v_22235:
    v_22388 = stack[-4];
    goto v_22236;
v_22237:
    v_22387 = nil;
    goto v_22238;
v_22239:
    goto v_22223;
v_22224:
    goto v_22225;
v_22226:
    goto v_22227;
v_22228:
    goto v_22229;
v_22230:
    goto v_22231;
v_22232:
    goto v_22233;
v_22234:
    goto v_22235;
v_22236:
    goto v_22237;
v_22238:
    v_22387 = CC_talp_nextt1(elt(env, 0), 8, stack[0], v_22393, v_22392, v_22391, v_22390, v_22389, v_22388, v_22387);
    env = stack[-12];
    v_22388 = v_22387;
    v_22388 = qcar(v_22388);
    if (v_22388 == nil) goto v_22254;
    v_22388 = lisp_true;
    stack[-11] = v_22388;
    goto v_22263;
v_22259:
    v_22388 = stack[-1];
    goto v_22260;
v_22261:
    v_22387 = qcdr(v_22387);
    goto v_22262;
v_22263:
    goto v_22259;
v_22260:
    goto v_22261;
v_22262:
    fn = elt(env, 5); // setcar
    v_22387 = (*qfn2(fn))(fn, v_22388, v_22387);
    env = stack[-12];
    goto v_22252;
v_22254:
    goto v_22274;
v_22270:
    v_22388 = stack[-1];
    goto v_22271;
v_22272:
    v_22387 = stack[-2];
    goto v_22273;
v_22274:
    goto v_22270;
v_22271:
    goto v_22272;
v_22273:
    fn = elt(env, 5); // setcar
    v_22387 = (*qfn2(fn))(fn, v_22388, v_22387);
    env = stack[-12];
    goto v_22252;
v_22252:
    v_22387 = stack[-1];
    v_22387 = qcdr(v_22387);
    stack[-1] = v_22387;
    goto v_22212;
v_22211:
    goto v_22139;
v_22139:
    v_22387 = stack[-11];
    if (v_22387 == nil) goto v_22281;
    else goto v_22282;
v_22281:
    v_22387 = stack[-3];
    if (v_22387 == nil) goto v_22287;
    goto v_22294;
v_22290:
    v_22388 = stack[-10];
    goto v_22291;
v_22292:
    v_22387 = stack[-4];
    goto v_22293;
v_22294:
    goto v_22290;
v_22291:
    goto v_22292;
v_22293:
    fn = elt(env, 6); // talp_get!-idx
    v_22387 = (*qfn2(fn))(fn, v_22388, v_22387);
    env = stack[-12];
    stack[-1] = v_22387;
    goto v_22307;
v_22303:
    stack[0] = stack[-1];
    goto v_22304;
v_22305:
    v_22387 = stack[-4];
    v_22387 = Lupbv(nil, v_22387);
    env = stack[-12];
    goto v_22306;
v_22307:
    goto v_22303;
v_22304:
    goto v_22305;
v_22306:
    v_22387 = (LispObject)lessp2(stack[0], v_22387);
    v_22387 = v_22387 ? lisp_true : nil;
    env = stack[-12];
    if (v_22387 == nil) goto v_22301;
    goto v_22316;
v_22312:
    stack[0] = lisp_true;
    goto v_22313;
v_22314:
    goto v_22327;
v_22319:
    v_22387 = stack[-1];
    v_22390 = add1(v_22387);
    env = stack[-12];
    goto v_22320;
v_22321:
    v_22389 = stack[-4];
    goto v_22322;
v_22323:
    v_22388 = stack[-6];
    goto v_22324;
v_22325:
    v_22387 = stack[-7];
    goto v_22326;
v_22327:
    goto v_22319;
v_22320:
    goto v_22321;
v_22322:
    goto v_22323;
v_22324:
    goto v_22325;
v_22326:
    fn = elt(env, 7); // talp_get!-minfct
    v_22387 = (*qfnn(fn))(fn, 4, v_22390, v_22389, v_22388, v_22387);
    goto v_22315;
v_22316:
    goto v_22312;
v_22313:
    goto v_22314;
v_22315:
    {
        LispObject v_22407 = stack[0];
        return cons(v_22407, v_22387);
    }
v_22301:
    goto v_22285;
v_22287:
    goto v_22340;
v_22336:
    v_22388 = stack[-10];
    goto v_22337;
v_22338:
    v_22387 = stack[-5];
    goto v_22339;
v_22340:
    goto v_22336;
v_22337:
    goto v_22338;
v_22339:
    fn = elt(env, 6); // talp_get!-idx
    v_22387 = (*qfn2(fn))(fn, v_22388, v_22387);
    env = stack[-12];
    stack[-1] = v_22387;
    goto v_22353;
v_22349:
    stack[0] = stack[-1];
    goto v_22350;
v_22351:
    v_22387 = stack[-5];
    v_22387 = Lupbv(nil, v_22387);
    env = stack[-12];
    goto v_22352;
v_22353:
    goto v_22349;
v_22350:
    goto v_22351;
v_22352:
    v_22387 = (LispObject)lessp2(stack[0], v_22387);
    v_22387 = v_22387 ? lisp_true : nil;
    env = stack[-12];
    if (v_22387 == nil) goto v_22347;
    goto v_22362;
v_22358:
    stack[0] = lisp_true;
    goto v_22359;
v_22360:
    goto v_22373;
v_22365:
    v_22387 = stack[-1];
    v_22390 = add1(v_22387);
    env = stack[-12];
    goto v_22366;
v_22367:
    v_22389 = stack[-5];
    goto v_22368;
v_22369:
    v_22388 = stack[-6];
    goto v_22370;
v_22371:
    v_22387 = stack[-7];
    goto v_22372;
v_22373:
    goto v_22365;
v_22366:
    goto v_22367;
v_22368:
    goto v_22369;
v_22370:
    goto v_22371;
v_22372:
    fn = elt(env, 7); // talp_get!-minfct
    v_22387 = (*qfnn(fn))(fn, 4, v_22390, v_22389, v_22388, v_22387);
    goto v_22361;
v_22362:
    goto v_22358;
v_22359:
    goto v_22360;
v_22361:
    {
        LispObject v_22408 = stack[0];
        return cons(v_22408, v_22387);
    }
v_22347:
    goto v_22285;
v_22285:
    goto v_22280;
v_22282:
v_22280:
    goto v_22384;
v_22380:
    v_22388 = stack[-11];
    goto v_22381;
v_22382:
    v_22387 = stack[-10];
    goto v_22383;
v_22384:
    goto v_22380;
v_22381:
    goto v_22382;
v_22383:
    return cons(v_22388, v_22387);
    return onevalue(v_22387);
}



// Code for ofsf_optsplitterm

static LispObject CC_ofsf_optsplitterm(LispObject env,
                         LispObject v_22093, LispObject v_22094)
{
    env = qenv(env);
    LispObject v_22176, v_22177, v_22178;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22093,v_22094);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_22094;
    stack[-3] = v_22093;
// end of prologue
    goto v_22104;
v_22100:
    v_22177 = stack[-3];
    goto v_22101;
v_22102:
    v_22176 = stack[0];
    goto v_22103;
v_22104:
    goto v_22100;
v_22101:
    goto v_22102;
v_22103:
    fn = elt(env, 4); // sfto_reorder
    v_22176 = (*qfn2(fn))(fn, v_22177, v_22176);
    env = stack[-5];
    stack[-3] = v_22176;
    goto v_22115;
v_22111:
    goto v_22121;
v_22117:
    v_22177 = stack[-3];
    goto v_22118;
v_22119:
    v_22176 = stack[0];
    goto v_22120;
v_22121:
    goto v_22117;
v_22118:
    goto v_22119;
v_22120:
    fn = elt(env, 5); // degr
    v_22177 = (*qfn2(fn))(fn, v_22177, v_22176);
    env = stack[-5];
    stack[-4] = v_22177;
    goto v_22112;
v_22113:
    v_22176 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22114;
v_22115:
    goto v_22111;
v_22112:
    goto v_22113;
v_22114:
    if (v_22177 == v_22176) goto v_22109;
    else goto v_22110;
v_22109:
    v_22176 = nil;
    goto v_22098;
v_22110:
    goto v_22135;
v_22131:
    v_22177 = stack[-4];
    goto v_22132;
v_22133:
    v_22176 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22134;
v_22135:
    goto v_22131;
v_22132:
    goto v_22133;
v_22134:
    v_22176 = (LispObject)greaterp2(v_22177, v_22176);
    v_22176 = v_22176 ? lisp_true : nil;
    env = stack[-5];
    if (v_22176 == nil) goto v_22129;
    goto v_22148;
v_22140:
    stack[-2] = elt(env, 1); // "ofsf_optsplitterm:"
    goto v_22141;
v_22142:
    stack[-1] = stack[0];
    goto v_22143;
v_22144:
    stack[0] = elt(env, 2); // "has degree"
    goto v_22145;
v_22146:
    goto v_22159;
v_22153:
    v_22178 = stack[-4];
    goto v_22154;
v_22155:
    v_22177 = elt(env, 3); // "in"
    goto v_22156;
v_22157:
    v_22176 = stack[-3];
    goto v_22158;
v_22159:
    goto v_22153;
v_22154:
    goto v_22155;
v_22156:
    goto v_22157;
v_22158:
    v_22176 = list3(v_22178, v_22177, v_22176);
    env = stack[-5];
    goto v_22147;
v_22148:
    goto v_22140;
v_22141:
    goto v_22142;
v_22143:
    goto v_22144;
v_22145:
    goto v_22146;
v_22147:
    v_22176 = list3star(stack[-2], stack[-1], stack[0], v_22176);
    env = stack[-5];
    fn = elt(env, 6); // rederr
    v_22176 = (*qfn1(fn))(fn, v_22176);
    env = stack[-5];
    goto v_22127;
v_22129:
v_22127:
    goto v_22168;
v_22164:
    v_22176 = stack[-3];
    v_22176 = qcar(v_22176);
    v_22176 = qcdr(v_22176);
    fn = elt(env, 7); // reorder
    stack[0] = (*qfn1(fn))(fn, v_22176);
    env = stack[-5];
    goto v_22165;
v_22166:
    v_22176 = stack[-3];
    v_22176 = qcdr(v_22176);
    fn = elt(env, 7); // reorder
    v_22176 = (*qfn1(fn))(fn, v_22176);
    goto v_22167;
v_22168:
    goto v_22164;
v_22165:
    goto v_22166;
v_22167:
    {
        LispObject v_22184 = stack[0];
        return cons(v_22184, v_22176);
    }
v_22098:
    return onevalue(v_22176);
}



// Code for determinantrd

static LispObject CC_determinantrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22101;
    LispObject fn;
    argcheck(nargs, 0, "determinantrd");
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
    v_22101 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_22101;
    fn = elt(env, 2); // lex
    v_22101 = (*qfnn(fn))(fn, 0);
    v_22101 = stack[0];
    return ncons(v_22101);
    return onevalue(v_22101);
}



// Code for dipcontevmin

static LispObject CC_dipcontevmin(LispObject env,
                         LispObject v_22093, LispObject v_22094)
{
    env = qenv(env);
    LispObject v_22164, v_22165, v_22166;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22093,v_22094);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22094;
    stack[-1] = v_22093;
// end of prologue
    v_22166 = nil;
v_22101:
    v_22164 = stack[-1];
    if (v_22164 == nil) goto v_22104;
    v_22164 = stack[0];
    if (v_22164 == nil) goto v_22104;
    goto v_22105;
v_22104:
    goto v_22100;
v_22105:
    goto v_22116;
v_22112:
    goto v_22125;
v_22121:
    v_22164 = stack[-1];
    v_22165 = qcar(v_22164);
    goto v_22122;
v_22123:
    v_22164 = stack[0];
    v_22164 = qcar(v_22164);
    goto v_22124;
v_22125:
    goto v_22121;
v_22122:
    goto v_22123;
v_22124:
    if (((intptr_t)(v_22165)) < ((intptr_t)(v_22164))) goto v_22119;
    else goto v_22120;
v_22119:
    v_22164 = stack[-1];
    v_22164 = qcar(v_22164);
    goto v_22118;
v_22120:
    v_22164 = stack[0];
    v_22164 = qcar(v_22164);
    goto v_22118;
    v_22164 = nil;
v_22118:
    goto v_22113;
v_22114:
    v_22165 = v_22166;
    goto v_22115;
v_22116:
    goto v_22112;
v_22113:
    goto v_22114;
v_22115:
    v_22164 = cons(v_22164, v_22165);
    env = stack[-2];
    v_22166 = v_22164;
    v_22164 = stack[-1];
    v_22164 = qcdr(v_22164);
    stack[-1] = v_22164;
    v_22164 = stack[0];
    v_22164 = qcdr(v_22164);
    stack[0] = v_22164;
    goto v_22101;
v_22100:
v_22143:
    v_22164 = v_22166;
    if (v_22164 == nil) goto v_22146;
    goto v_22155;
v_22151:
    v_22165 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22152;
v_22153:
    v_22164 = v_22166;
    v_22164 = qcar(v_22164);
    goto v_22154;
v_22155:
    goto v_22151;
v_22152:
    goto v_22153;
v_22154:
    if (v_22165 == v_22164) goto v_22150;
    else goto v_22146;
v_22150:
    goto v_22147;
v_22146:
    goto v_22142;
v_22147:
    v_22164 = v_22166;
    v_22164 = qcdr(v_22164);
    v_22166 = v_22164;
    goto v_22143;
v_22142:
    v_22164 = v_22166;
        return Lnreverse(nil, v_22164);
    return onevalue(v_22164);
}



// Code for f2dip1

static LispObject CC_f2dip1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22187, v_22188, v_22189, v_22190, v_22191;
    LispObject fn;
    LispObject v_22095, v_22094, v_22093;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "f2dip1");
    va_start(aa, nargs);
    v_22093 = va_arg(aa, LispObject);
    v_22094 = va_arg(aa, LispObject);
    v_22095 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22095,v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22093,v_22094,v_22095);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_22095;
    stack[-1] = v_22094;
    stack[-2] = v_22093;
// end of prologue
    v_22187 = stack[-2];
    if (v_22187 == nil) goto v_22099;
    else goto v_22100;
v_22099:
    v_22187 = nil;
    goto v_22098;
v_22100:
    v_22187 = stack[-2];
    if (!consp(v_22187)) goto v_22107;
    else goto v_22108;
v_22107:
    v_22187 = lisp_true;
    goto v_22106;
v_22108:
    v_22187 = stack[-2];
    v_22187 = qcar(v_22187);
    v_22187 = (consp(v_22187) ? nil : lisp_true);
    goto v_22106;
    v_22187 = nil;
v_22106:
    if (v_22187 == nil) goto v_22104;
    v_22187 = stack[0];
    v_22187 = (is_number(v_22187) ? lisp_true : nil);
    if (v_22187 == nil) goto v_22118;
    else goto v_22117;
v_22118:
    v_22187 = stack[0];
    fn = elt(env, 1); // f2dip11
    v_22187 = (*qfn1(fn))(fn, v_22187);
    env = stack[-4];
v_22117:
    goto v_22130;
v_22124:
    goto v_22125;
v_22126:
    goto v_22137;
v_22133:
    goto v_22134;
v_22135:
    v_22187 = stack[-2];
    fn = elt(env, 2); // bcfd
    v_22187 = (*qfn1(fn))(fn, v_22187);
    env = stack[-4];
    goto v_22136;
v_22137:
    goto v_22133;
v_22134:
    goto v_22135;
v_22136:
    fn = elt(env, 3); // bcprod
    v_22188 = (*qfn2(fn))(fn, stack[0], v_22187);
    goto v_22127;
v_22128:
    v_22187 = nil;
    goto v_22129;
v_22130:
    goto v_22124;
v_22125:
    goto v_22126;
v_22127:
    goto v_22128;
v_22129:
    {
        LispObject v_22196 = stack[-1];
        return list2star(v_22196, v_22188, v_22187);
    }
v_22104:
    goto v_22149;
v_22145:
    goto v_22161;
v_22151:
    v_22187 = stack[-2];
    v_22187 = qcar(v_22187);
    v_22187 = qcar(v_22187);
    v_22191 = qcar(v_22187);
    goto v_22152;
v_22153:
    v_22187 = stack[-2];
    v_22187 = qcar(v_22187);
    v_22187 = qcar(v_22187);
    v_22190 = qcdr(v_22187);
    goto v_22154;
v_22155:
    v_22187 = stack[-2];
    v_22187 = qcar(v_22187);
    v_22189 = qcdr(v_22187);
    goto v_22156;
v_22157:
    v_22188 = stack[-1];
    goto v_22158;
v_22159:
    v_22187 = stack[0];
    goto v_22160;
v_22161:
    goto v_22151;
v_22152:
    goto v_22153;
v_22154:
    goto v_22155;
v_22156:
    goto v_22157;
v_22158:
    goto v_22159;
v_22160:
    fn = elt(env, 4); // f2dip2
    stack[-3] = (*qfnn(fn))(fn, 5, v_22191, v_22190, v_22189, v_22188, v_22187);
    env = stack[-4];
    goto v_22146;
v_22147:
    goto v_22182;
v_22176:
    v_22187 = stack[-2];
    v_22189 = qcdr(v_22187);
    goto v_22177;
v_22178:
    v_22188 = stack[-1];
    goto v_22179;
v_22180:
    v_22187 = stack[0];
    goto v_22181;
v_22182:
    goto v_22176;
v_22177:
    goto v_22178;
v_22179:
    goto v_22180;
v_22181:
    v_22187 = CC_f2dip1(elt(env, 0), 3, v_22189, v_22188, v_22187);
    env = stack[-4];
    goto v_22148;
v_22149:
    goto v_22145;
v_22146:
    goto v_22147;
v_22148:
    {
        LispObject v_22197 = stack[-3];
        fn = elt(env, 5); // dipsum
        return (*qfn2(fn))(fn, v_22197, v_22187);
    }
    v_22187 = nil;
v_22098:
    return onevalue(v_22187);
}



// Code for xnsiz

static LispObject CC_xnsiz(LispObject env,
                         LispObject v_22093)
{
    env = qenv(env);
    LispObject v_22105, v_22106;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22093);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_22105 = v_22093;
// end of prologue
    goto v_22101;
v_22097:
    fn = elt(env, 2); // xnsiz1
    v_22106 = (*qfn1(fn))(fn, v_22105);
    env = stack[0];
    goto v_22098;
v_22099:
    v_22105 = qvalue(elt(env, 1)); // !!log2of10
    goto v_22100;
v_22101:
    goto v_22097;
v_22098:
    goto v_22099;
v_22100:
    v_22105 = quot2(v_22106, v_22105);
    env = stack[0];
    {
        fn = elt(env, 3); // ceiling
        return (*qfn1(fn))(fn, v_22105);
    }
}



// Code for spp

static LispObject CC_spp(LispObject env,
                         LispObject v_22093)
{
    env = qenv(env);
    LispObject v_22107, v_22108;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22093);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_22107 = v_22093;
// end of prologue
    v_22108 = v_22107;
    v_22108 = Lconsp(nil, v_22108);
    env = stack[0];
    if (v_22108 == nil) goto v_22097;
    else goto v_22098;
v_22097:
    v_22107 = nil;
    goto v_22096;
v_22098:
    v_22107 = qcar(v_22107);
    {
        fn = elt(env, 1); // kernelp
        return (*qfn1(fn))(fn, v_22107);
    }
    v_22107 = nil;
v_22096:
    return onevalue(v_22107);
}



// Code for dfp!-sub

static LispObject CC_dfpKsub(LispObject env,
                         LispObject v_22093, LispObject v_22094)
{
    env = qenv(env);
    LispObject v_22271, v_22272, v_22273;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22094,v_22093);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22093,v_22094);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_22094;
    stack[-4] = v_22093;
// end of prologue
    v_22271 = stack[-3];
    v_22271 = qcdr(v_22271);
    v_22271 = qcar(v_22271);
    v_22272 = v_22271;
    v_22271 = v_22272;
    v_22271 = qcdr(v_22271);
    stack[-5] = v_22271;
    goto v_22114;
v_22110:
    v_22271 = v_22272;
    v_22272 = qcar(v_22271);
    stack[-2] = v_22272;
    goto v_22111;
v_22112:
    v_22271 = elt(env, 1); // generic_function
    goto v_22113;
v_22114:
    goto v_22110;
v_22111:
    goto v_22112;
v_22113:
    v_22271 = get(v_22272, v_22271);
    env = stack[-6];
    stack[-1] = v_22271;
    v_22271 = stack[-5];
    if (v_22271 == nil) goto v_22120;
    else goto v_22121;
v_22120:
    v_22271 = nil;
    v_22272 = stack[-1];
    v_22273 = v_22272;
v_22127:
    v_22272 = v_22273;
    if (v_22272 == nil) goto v_22131;
    else goto v_22132;
v_22131:
    goto v_22126;
v_22132:
    v_22272 = v_22273;
    v_22272 = qcar(v_22272);
    if (v_22271 == nil) goto v_22140;
    else goto v_22139;
v_22140:
    goto v_22146;
v_22142:
    goto v_22143;
v_22144:
    v_22271 = stack[-4];
    goto v_22145;
v_22146:
    goto v_22142;
v_22143:
    goto v_22144;
v_22145:
    v_22271 = Lassoc(nil, v_22272, v_22271);
v_22139:
    v_22272 = v_22273;
    v_22272 = qcdr(v_22272);
    v_22273 = v_22272;
    goto v_22127;
v_22126:
    if (v_22271 == nil) goto v_22155;
    v_22271 = stack[-1];
    stack[-5] = v_22271;
    goto v_22153;
v_22155:
v_22153:
    goto v_22119;
v_22121:
v_22119:
    goto v_22164;
v_22160:
    stack[0] = stack[-4];
    goto v_22161;
v_22162:
    goto v_22171;
v_22167:
    v_22272 = elt(env, 2); // list
    goto v_22168;
v_22169:
    v_22271 = stack[-5];
    goto v_22170;
v_22171:
    goto v_22167;
v_22168:
    goto v_22169;
v_22170:
    v_22271 = cons(v_22272, v_22271);
    env = stack[-6];
    goto v_22163;
v_22164:
    goto v_22160;
v_22161:
    goto v_22162;
v_22163:
    fn = elt(env, 4); // listsub
    v_22271 = (*qfn2(fn))(fn, stack[0], v_22271);
    env = stack[-6];
    v_22271 = qcdr(v_22271);
    stack[-5] = v_22271;
    goto v_22187;
v_22183:
    v_22272 = stack[-2];
    goto v_22184;
v_22185:
    v_22271 = stack[-4];
    goto v_22186;
v_22187:
    goto v_22183;
v_22184:
    goto v_22185;
v_22186:
    v_22272 = Lassoc(nil, v_22272, v_22271);
    v_22271 = v_22272;
    if (v_22272 == nil) goto v_22181;
    else goto v_22182;
v_22181:
    goto v_22195;
v_22191:
    goto v_22201;
v_22197:
    v_22272 = stack[-2];
    goto v_22198;
v_22199:
    v_22271 = stack[-1];
    goto v_22200;
v_22201:
    goto v_22197;
v_22198:
    goto v_22199;
v_22200:
    v_22272 = cons(v_22272, v_22271);
    env = stack[-6];
    goto v_22192;
v_22193:
    v_22271 = stack[-4];
    goto v_22194;
v_22195:
    goto v_22191;
v_22192:
    goto v_22193;
v_22194:
    v_22272 = Lassoc(nil, v_22272, v_22271);
    v_22271 = v_22272;
    v_22272 = (v_22272 == nil ? lisp_true : nil);
    goto v_22180;
v_22182:
    v_22272 = nil;
    goto v_22180;
    v_22272 = nil;
v_22180:
    if (v_22272 == nil) goto v_22178;
    goto v_22217;
v_22211:
    stack[0] = elt(env, 3); // dfp
    goto v_22212;
v_22213:
    goto v_22224;
v_22220:
    v_22272 = stack[-2];
    goto v_22221;
v_22222:
    v_22271 = stack[-5];
    goto v_22223;
v_22224:
    goto v_22220;
v_22221:
    goto v_22222;
v_22223:
    v_22272 = cons(v_22272, v_22271);
    goto v_22214;
v_22215:
    v_22271 = stack[-3];
    v_22271 = qcdr(v_22271);
    v_22271 = qcdr(v_22271);
    v_22271 = qcar(v_22271);
    goto v_22216;
v_22217:
    goto v_22211;
v_22212:
    goto v_22213;
v_22214:
    goto v_22215;
v_22216:
    {
        LispObject v_22280 = stack[0];
        return list3(v_22280, v_22272, v_22271);
    }
v_22178:
    v_22271 = qcdr(v_22271);
    fn = elt(env, 5); // reval
    v_22271 = (*qfn1(fn))(fn, v_22271);
    env = stack[-6];
    goto v_22241;
v_22235:
    stack[0] = v_22271;
    goto v_22236;
v_22237:
    v_22271 = stack[-5];
    if (v_22271 == nil) goto v_22246;
    goto v_22253;
v_22249:
    v_22272 = stack[-1];
    goto v_22250;
v_22251:
    v_22271 = stack[-5];
    goto v_22252;
v_22253:
    goto v_22249;
v_22250:
    goto v_22251;
v_22252:
    fn = elt(env, 6); // pair
    v_22271 = (*qfn2(fn))(fn, v_22272, v_22271);
    env = stack[-6];
    v_22272 = v_22271;
    goto v_22244;
v_22246:
    v_22272 = nil;
v_22244:
    goto v_22238;
v_22239:
    v_22271 = stack[-4];
    goto v_22240;
v_22241:
    goto v_22235;
v_22236:
    goto v_22237;
v_22238:
    goto v_22239;
v_22240:
    fn = elt(env, 7); // dfp!-sub1
    v_22271 = (*qfnn(fn))(fn, 3, stack[0], v_22272, v_22271);
    env = stack[-6];
    goto v_22264;
v_22258:
    v_22273 = elt(env, 3); // dfp
    goto v_22259;
v_22260:
    v_22272 = v_22271;
    goto v_22261;
v_22262:
    v_22271 = stack[-3];
    v_22271 = qcdr(v_22271);
    v_22271 = qcdr(v_22271);
    v_22271 = qcar(v_22271);
    goto v_22263;
v_22264:
    goto v_22258;
v_22259:
    goto v_22260;
v_22261:
    goto v_22262;
v_22263:
    return list3(v_22273, v_22272, v_22271);
    return onevalue(v_22271);
}



// Code for fs!:minusp

static LispObject CC_fsTminusp(LispObject env,
                         LispObject v_22093)
{
    env = qenv(env);
    LispObject v_22134, v_22135, v_22136;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22135 = v_22093;
// end of prologue
v_22097:
    v_22134 = v_22135;
    if (v_22134 == nil) goto v_22100;
    else goto v_22101;
v_22100:
    v_22134 = nil;
    goto v_22096;
v_22101:
    goto v_22110;
v_22106:
    v_22136 = v_22135;
    goto v_22107;
v_22108:
    v_22134 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_22109;
v_22110:
    goto v_22106;
v_22107:
    goto v_22108;
v_22109:
    v_22134 = *(LispObject *)((char *)v_22136 + (CELL-TAG_VECTOR) + (((intptr_t)v_22134-TAG_FIXNUM)/(16/CELL)));
    if (v_22134 == nil) goto v_22104;
    else goto v_22105;
v_22104:
    goto v_22119;
v_22115:
    goto v_22116;
v_22117:
    v_22134 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22118;
v_22119:
    goto v_22115;
v_22116:
    goto v_22117;
v_22118:
    v_22134 = *(LispObject *)((char *)v_22135 + (CELL-TAG_VECTOR) + (((intptr_t)v_22134-TAG_FIXNUM)/(16/CELL)));
    v_22134 = qcar(v_22134);
    {
        fn = elt(env, 1); // minusf
        return (*qfn1(fn))(fn, v_22134);
    }
v_22105:
    goto v_22130;
v_22126:
    goto v_22127;
v_22128:
    v_22134 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_22129;
v_22130:
    goto v_22126;
v_22127:
    goto v_22128;
v_22129:
    v_22134 = *(LispObject *)((char *)v_22135 + (CELL-TAG_VECTOR) + (((intptr_t)v_22134-TAG_FIXNUM)/(16/CELL)));
    v_22135 = v_22134;
    goto v_22097;
    v_22134 = nil;
v_22096:
    return onevalue(v_22134);
}



// Code for lalr_lr0_initial_itemset

static LispObject CC_lalr_lr0_initial_itemset(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22117, v_22118, v_22119;
    LispObject fn;
    argcheck(nargs, 0, "lalr_lr0_initial_itemset");
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
    v_22117 = elt(env, 1); // !S!'
    fn = elt(env, 3); // lalr_productions
    v_22117 = (*qfn1(fn))(fn, v_22117);
    env = stack[0];
    v_22117 = qcar(v_22117);
    v_22117 = qcar(v_22117);
    v_22117 = qcar(v_22117);
    goto v_22110;
v_22104:
    v_22119 = elt(env, 1); // !S!'
    goto v_22105;
v_22106:
    v_22118 = elt(env, 2); // !.
    goto v_22107;
v_22108:
    goto v_22109;
v_22110:
    goto v_22104;
v_22105:
    goto v_22106;
v_22107:
    goto v_22108;
v_22109:
    v_22117 = list3(v_22119, v_22118, v_22117);
    env = stack[0];
    v_22117 = ncons(v_22117);
    env = stack[0];
    {
        fn = elt(env, 4); // lalr_lr0_closure
        return (*qfn1(fn))(fn, v_22117);
    }
    return onevalue(v_22117);
}



setup_type const u39_setup[] =
{
    {"num_signsort",            CC_num_signsort,TOO_MANY_1,    WRONG_NO_1},
    {"lambda_ygm6np4pcqv31",    TOO_FEW_2,      CC_lambda_ygm6np4pcqv31,WRONG_NO_2},
    {"assoc2",                  TOO_FEW_2,      CC_assoc2,     WRONG_NO_2},
    {"lalr_make_compressed_goto_table",WRONG_NO_NA,WRONG_NO_NB,(n_args *)CC_lalr_make_compressed_goto_table},
    {"get-term-n",              TOO_FEW_2,      CC_getKtermKn, WRONG_NO_2},
    {"ofsf_qesubqat",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_qesubqat},
    {"tayfkern",                CC_tayfkern,    TOO_MANY_1,    WRONG_NO_1},
    {"my+nullsq+p",             CC_myLnullsqLp, TOO_MANY_1,    WRONG_NO_1},
    {"mri_ofsf2mriat",          TOO_FEW_2,      CC_mri_ofsf2mriat,WRONG_NO_2},
    {"dvfsf_smupdknowl",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dvfsf_smupdknowl},
    {"intervalom",              CC_intervalom,  TOO_MANY_1,    WRONG_NO_1},
    {"sptransmat",              CC_sptransmat,  TOO_MANY_1,    WRONG_NO_1},
    {"groebspolynom3",          TOO_FEW_2,      CC_groebspolynom3,WRONG_NO_2},
    {"exdfprn",                 CC_exdfprn,     TOO_MANY_1,    WRONG_NO_1},
    {"multiply-by-power-of-ten",TOO_FEW_2,      CC_multiplyKbyKpowerKofKten,WRONG_NO_2},
    {"toolongassignp",          CC_toolongassignp,TOO_MANY_1,  WRONG_NO_1},
    {"simppartdf",              CC_simppartdf,  TOO_MANY_1,    WRONG_NO_1},
    {"lf=zero",                 CC_lfMzero,     TOO_MANY_1,    WRONG_NO_1},
    {"vector-to-poly",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vectorKtoKpoly},
    {"setqinsertlist",          CC_setqinsertlist,TOO_MANY_1,  WRONG_NO_1},
    {"processpartitie1list1",   TOO_FEW_2,      CC_processpartitie1list1,WRONG_NO_2},
    {"pickbasicset",            CC_pickbasicset,TOO_MANY_1,    WRONG_NO_1},
    {"cl_bvarl",                CC_cl_bvarl,    TOO_MANY_1,    WRONG_NO_1},
    {"dip_sum",                 TOO_FEW_2,      CC_dip_sum,    WRONG_NO_2},
    {"matrixelems",             CC_matrixelems, TOO_MANY_1,    WRONG_NO_1},
    {"multerm",                 TOO_FEW_2,      CC_multerm,    WRONG_NO_2},
    {"transmat1",               CC_transmat1,   TOO_MANY_1,    WRONG_NO_1},
    {"remzzzz",                 TOO_FEW_2,      CC_remzzzz,    WRONG_NO_2},
    {"diplmon2sq",              TOO_FEW_2,      CC_diplmon2sq, WRONG_NO_2},
    {"weak_xreduce1",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_weak_xreduce1},
    {"rd:difference",           TOO_FEW_2,      CC_rdTdifference,WRONG_NO_2},
    {"indxsymp",                TOO_FEW_2,      CC_indxsymp,   WRONG_NO_2},
    {"calc_coeffmap_",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_calc_coeffmap_},
    {"prepsq*1",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_prepsqH1},
    {"ctx_union",               TOO_FEW_2,      CC_ctx_union,  WRONG_NO_2},
    {"createmonomunit",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_createmonomunit},
    {"squashsqrt",              CC_squashsqrt,  TOO_MANY_1,    WRONG_NO_1},
    {"talp_nextt1",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_nextt1},
    {"ofsf_optsplitterm",       TOO_FEW_2,      CC_ofsf_optsplitterm,WRONG_NO_2},
    {"determinantrd",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_determinantrd},
    {"dipcontevmin",            TOO_FEW_2,      CC_dipcontevmin,WRONG_NO_2},
    {"f2dip1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_f2dip1},
    {"xnsiz",                   CC_xnsiz,       TOO_MANY_1,    WRONG_NO_1},
    {"spp",                     CC_spp,         TOO_MANY_1,    WRONG_NO_1},
    {"dfp-sub",                 TOO_FEW_2,      CC_dfpKsub,    WRONG_NO_2},
    {"fs:minusp",               CC_fsTminusp,   TOO_MANY_1,    WRONG_NO_1},
    {"lalr_lr0_initial_itemset",WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lalr_lr0_initial_itemset},
    {NULL, (one_args *)"u39", (two_args *)"144228 9032973 9334946", 0}
};

// end of generated code
