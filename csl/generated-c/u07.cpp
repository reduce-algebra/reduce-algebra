
// $destdir/u07.c        Machine generated C code

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



// Code for raddf

static LispObject CC_raddf(LispObject env,
                         LispObject v_2355, LispObject v_2356)
{
    env = qenv(env);
    LispObject v_2521, v_2522;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2355,v_2356);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_2356;
    stack[-2] = v_2355;
// end of prologue
    stack[-3] = nil;
v_2361:
    v_2521 = stack[-2];
    if (v_2521 == nil) goto v_2364;
    else goto v_2365;
v_2364:
    goto v_2372;
v_2368:
    v_2522 = stack[-3];
    goto v_2369;
v_2370:
    v_2521 = stack[-1];
    goto v_2371;
v_2372:
    goto v_2368;
v_2369:
    goto v_2370;
v_2371:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_2522, v_2521);
    }
v_2365:
    v_2521 = stack[-1];
    if (v_2521 == nil) goto v_2375;
    else goto v_2376;
v_2375:
    goto v_2383;
v_2379:
    v_2522 = stack[-3];
    goto v_2380;
v_2381:
    v_2521 = stack[-2];
    goto v_2382;
v_2383:
    goto v_2379;
v_2380:
    goto v_2381;
v_2382:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_2522, v_2521);
    }
v_2376:
    v_2521 = stack[-2];
    if (!consp(v_2521)) goto v_2390;
    else goto v_2391;
v_2390:
    v_2521 = lisp_true;
    goto v_2389;
v_2391:
    v_2521 = stack[-2];
    v_2521 = qcar(v_2521);
    v_2521 = (consp(v_2521) ? nil : lisp_true);
    goto v_2389;
    v_2521 = nil;
v_2389:
    if (v_2521 == nil) goto v_2387;
    goto v_2404;
v_2400:
    stack[0] = stack[-3];
    goto v_2401;
v_2402:
    goto v_2411;
v_2407:
    v_2522 = stack[-2];
    goto v_2408;
v_2409:
    v_2521 = stack[-1];
    goto v_2410;
v_2411:
    goto v_2407;
v_2408:
    goto v_2409;
v_2410:
    fn = elt(env, 2); // addd
    v_2521 = (*qfn2(fn))(fn, v_2522, v_2521);
    env = stack[-4];
    goto v_2403;
v_2404:
    goto v_2400;
v_2401:
    goto v_2402;
v_2403:
    {
        LispObject v_2527 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_2527, v_2521);
    }
v_2387:
    v_2521 = stack[-1];
    if (!consp(v_2521)) goto v_2418;
    else goto v_2419;
v_2418:
    v_2521 = lisp_true;
    goto v_2417;
v_2419:
    v_2521 = stack[-1];
    v_2521 = qcar(v_2521);
    v_2521 = (consp(v_2521) ? nil : lisp_true);
    goto v_2417;
    v_2521 = nil;
v_2417:
    if (v_2521 == nil) goto v_2415;
    goto v_2432;
v_2428:
    stack[0] = stack[-3];
    goto v_2429;
v_2430:
    goto v_2439;
v_2435:
    v_2522 = stack[-1];
    goto v_2436;
v_2437:
    v_2521 = stack[-2];
    goto v_2438;
v_2439:
    goto v_2435;
v_2436:
    goto v_2437;
v_2438:
    fn = elt(env, 2); // addd
    v_2521 = (*qfn2(fn))(fn, v_2522, v_2521);
    env = stack[-4];
    goto v_2431;
v_2432:
    goto v_2428;
v_2429:
    goto v_2430;
v_2431:
    {
        LispObject v_2528 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_2528, v_2521);
    }
v_2415:
    goto v_2448;
v_2444:
    v_2521 = stack[-2];
    v_2521 = qcar(v_2521);
    v_2522 = qcar(v_2521);
    goto v_2445;
v_2446:
    v_2521 = stack[-1];
    v_2521 = qcar(v_2521);
    v_2521 = qcar(v_2521);
    goto v_2447;
v_2448:
    goto v_2444;
v_2445:
    goto v_2446;
v_2447:
    if (equal(v_2522, v_2521)) goto v_2442;
    else goto v_2443;
v_2442:
    goto v_2462;
v_2456:
    v_2521 = stack[-2];
    v_2521 = qcar(v_2521);
    stack[0] = qcar(v_2521);
    goto v_2457;
v_2458:
    goto v_2471;
v_2467:
    v_2521 = stack[-2];
    v_2521 = qcar(v_2521);
    v_2522 = qcdr(v_2521);
    goto v_2468;
v_2469:
    v_2521 = stack[-1];
    v_2521 = qcar(v_2521);
    v_2521 = qcdr(v_2521);
    goto v_2470;
v_2471:
    goto v_2467;
v_2468:
    goto v_2469;
v_2470:
    v_2522 = CC_raddf(elt(env, 0), v_2522, v_2521);
    env = stack[-4];
    goto v_2459;
v_2460:
    v_2521 = stack[-3];
    goto v_2461;
v_2462:
    goto v_2456;
v_2457:
    goto v_2458;
v_2459:
    goto v_2460;
v_2461:
    v_2521 = acons(stack[0], v_2522, v_2521);
    env = stack[-4];
    stack[-3] = v_2521;
    v_2521 = stack[-2];
    v_2521 = qcdr(v_2521);
    stack[-2] = v_2521;
    v_2521 = stack[-1];
    v_2521 = qcdr(v_2521);
    stack[-1] = v_2521;
    goto v_2361;
v_2443:
    goto v_2490;
v_2486:
    v_2521 = stack[-2];
    v_2521 = qcar(v_2521);
    v_2522 = qcar(v_2521);
    goto v_2487;
v_2488:
    v_2521 = stack[-1];
    v_2521 = qcar(v_2521);
    v_2521 = qcar(v_2521);
    goto v_2489;
v_2490:
    goto v_2486;
v_2487:
    goto v_2488;
v_2489:
    fn = elt(env, 3); // ordpp
    v_2521 = (*qfn2(fn))(fn, v_2522, v_2521);
    env = stack[-4];
    if (v_2521 == nil) goto v_2484;
    goto v_2502;
v_2498:
    v_2521 = stack[-2];
    v_2522 = qcar(v_2521);
    goto v_2499;
v_2500:
    v_2521 = stack[-3];
    goto v_2501;
v_2502:
    goto v_2498;
v_2499:
    goto v_2500;
v_2501:
    v_2521 = cons(v_2522, v_2521);
    env = stack[-4];
    stack[-3] = v_2521;
    v_2521 = stack[-2];
    v_2521 = qcdr(v_2521);
    stack[-2] = v_2521;
    goto v_2361;
v_2484:
    goto v_2515;
v_2511:
    v_2521 = stack[-1];
    v_2522 = qcar(v_2521);
    goto v_2512;
v_2513:
    v_2521 = stack[-3];
    goto v_2514;
v_2515:
    goto v_2511;
v_2512:
    goto v_2513;
v_2514:
    v_2521 = cons(v_2522, v_2521);
    env = stack[-4];
    stack[-3] = v_2521;
    v_2521 = stack[-1];
    v_2521 = qcdr(v_2521);
    stack[-1] = v_2521;
    goto v_2361;
    v_2521 = nil;
    return onevalue(v_2521);
}



// Code for talp_varlt1

static LispObject CC_talp_varlt1(LispObject env,
                         LispObject v_2355, LispObject v_2356)
{
    env = qenv(env);
    LispObject v_2421, v_2422;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2355,v_2356);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_2356;
    stack[-1] = v_2355;
// end of prologue
    v_2421 = stack[-1];
    if (!consp(v_2421)) goto v_2362;
    else goto v_2363;
v_2362:
    goto v_2373;
v_2369:
    stack[-2] = stack[-1];
    goto v_2370;
v_2371:
    fn = elt(env, 1); // talp_getl
    v_2421 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_2372;
v_2373:
    goto v_2369;
v_2370:
    goto v_2371;
v_2372:
    v_2421 = Latsoc(nil, stack[-2], v_2421);
    if (v_2421 == nil) goto v_2367;
    else goto v_2368;
v_2367:
    goto v_2382;
v_2378:
    v_2422 = stack[-1];
    goto v_2379;
v_2380:
    v_2421 = stack[0];
    goto v_2381;
v_2382:
    goto v_2378;
v_2379:
    goto v_2380;
v_2381:
    {
        fn = elt(env, 2); // lto_insert
        return (*qfn2(fn))(fn, v_2422, v_2421);
    }
v_2368:
    v_2421 = nil;
    goto v_2359;
    goto v_2361;
v_2363:
v_2361:
    v_2421 = stack[-1];
    fn = elt(env, 3); // talp_argl
    v_2421 = (*qfn1(fn))(fn, v_2421);
    env = stack[-3];
    stack[-1] = v_2421;
v_2391:
    v_2421 = stack[-1];
    if (v_2421 == nil) goto v_2396;
    else goto v_2397;
v_2396:
    goto v_2390;
v_2397:
    v_2421 = stack[-1];
    v_2421 = qcar(v_2421);
    goto v_2408;
v_2404:
    goto v_2414;
v_2410:
    v_2422 = v_2421;
    goto v_2411;
v_2412:
    v_2421 = stack[0];
    goto v_2413;
v_2414:
    goto v_2410;
v_2411:
    goto v_2412;
v_2413:
    v_2422 = CC_talp_varlt1(elt(env, 0), v_2422, v_2421);
    env = stack[-3];
    goto v_2405;
v_2406:
    v_2421 = stack[0];
    goto v_2407;
v_2408:
    goto v_2404;
v_2405:
    goto v_2406;
v_2407:
    fn = elt(env, 4); // union
    v_2421 = (*qfn2(fn))(fn, v_2422, v_2421);
    env = stack[-3];
    stack[0] = v_2421;
    v_2421 = stack[-1];
    v_2421 = qcdr(v_2421);
    stack[-1] = v_2421;
    goto v_2391;
v_2390:
    v_2421 = stack[0];
v_2359:
    return onevalue(v_2421);
}



// Code for mri_simplfloor

static LispObject CC_mri_simplfloor(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2368;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2355;
// end of prologue
    v_2368 = stack[0];
    fn = elt(env, 1); // mri_floorkernelp
    v_2368 = (*qfn1(fn))(fn, v_2368);
    env = stack[-1];
    if (v_2368 == nil) goto v_2359;
    else goto v_2360;
v_2359:
    v_2368 = stack[0];
    goto v_2358;
v_2360:
    v_2368 = stack[0];
    {
        fn = elt(env, 2); // mri_simplfloor1
        return (*qfn1(fn))(fn, v_2368);
    }
    v_2368 = nil;
v_2358:
    return onevalue(v_2368);
}



// Code for rl_simpat

static LispObject CC_rl_simpat(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2366;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_2366 = v_2355;
// end of prologue
    goto v_2362;
v_2358:
    stack[0] = qvalue(elt(env, 1)); // rl_simpat!*
    goto v_2359;
v_2360:
    v_2366 = ncons(v_2366);
    env = stack[-1];
    goto v_2361;
v_2362:
    goto v_2358;
v_2359:
    goto v_2360;
v_2361:
    {
        LispObject v_2368 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_2368, v_2366);
    }
}



// Code for ev_invlexcomp

static LispObject CC_ev_invlexcomp(LispObject env,
                         LispObject v_2355, LispObject v_2356)
{
    env = qenv(env);
    LispObject v_2444, v_2445;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2355,v_2356);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_2356;
    stack[-1] = v_2355;
// end of prologue
v_2354:
    v_2444 = stack[-1];
    if (v_2444 == nil) goto v_2363;
    else goto v_2364;
v_2363:
    v_2444 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2360;
v_2364:
    goto v_2376;
v_2372:
    v_2444 = stack[-1];
    v_2445 = qcar(v_2444);
    goto v_2373;
v_2374:
    v_2444 = stack[0];
    v_2444 = qcar(v_2444);
    goto v_2375;
v_2376:
    goto v_2372;
v_2373:
    goto v_2374;
v_2375:
    fn = elt(env, 1); // iequal
    v_2444 = (*qfn2(fn))(fn, v_2445, v_2444);
    env = stack[-3];
    if (v_2444 == nil) goto v_2370;
    goto v_2386;
v_2382:
    v_2444 = stack[-1];
    v_2445 = qcdr(v_2444);
    goto v_2383;
v_2384:
    v_2444 = stack[0];
    v_2444 = qcdr(v_2444);
    goto v_2385;
v_2386:
    goto v_2382;
v_2383:
    goto v_2384;
v_2385:
    stack[-1] = v_2445;
    stack[0] = v_2444;
    goto v_2354;
v_2370:
    goto v_2396;
v_2392:
    v_2444 = stack[-1];
    v_2445 = qcdr(v_2444);
    goto v_2393;
v_2394:
    v_2444 = stack[0];
    v_2444 = qcdr(v_2444);
    goto v_2395;
v_2396:
    goto v_2392;
v_2393:
    goto v_2394;
v_2395:
    v_2444 = CC_ev_invlexcomp(elt(env, 0), v_2445, v_2444);
    env = stack[-3];
    stack[-2] = v_2444;
    goto v_2410;
v_2406:
    v_2445 = stack[-2];
    goto v_2407;
v_2408:
    v_2444 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2409;
v_2410:
    goto v_2406;
v_2407:
    goto v_2408;
v_2409:
    fn = elt(env, 1); // iequal
    v_2444 = (*qfn2(fn))(fn, v_2445, v_2444);
    env = stack[-3];
    if (v_2444 == nil) goto v_2403;
    else goto v_2404;
v_2403:
    v_2444 = stack[-2];
    goto v_2360;
v_2404:
    goto v_2423;
v_2419:
    v_2444 = stack[0];
    v_2445 = qcar(v_2444);
    goto v_2420;
v_2421:
    v_2444 = stack[-1];
    v_2444 = qcar(v_2444);
    goto v_2422;
v_2423:
    goto v_2419;
v_2420:
    goto v_2421;
v_2422:
    fn = elt(env, 1); // iequal
    v_2444 = (*qfn2(fn))(fn, v_2445, v_2444);
    if (v_2444 == nil) goto v_2417;
    v_2444 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2360;
v_2417:
    goto v_2437;
v_2433:
    v_2444 = stack[0];
    v_2445 = qcar(v_2444);
    goto v_2434;
v_2435:
    v_2444 = stack[-1];
    v_2444 = qcar(v_2444);
    goto v_2436;
v_2437:
    goto v_2433;
v_2434:
    goto v_2435;
v_2436:
    if (((intptr_t)(v_2445)) > ((intptr_t)(v_2444))) goto v_2431;
    else goto v_2432;
v_2431:
    v_2444 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2360;
v_2432:
    v_2444 = (LispObject)-16+TAG_FIXNUM; // -1
v_2360:
    return onevalue(v_2444);
}



// Code for quotfd

static LispObject CC_quotfd(LispObject env,
                         LispObject v_2355, LispObject v_2356)
{
    env = qenv(env);
    LispObject v_2413, v_2414, v_2415, v_2416;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2415 = v_2356;
    v_2416 = v_2355;
// end of prologue
    goto v_2366;
v_2362:
    v_2414 = v_2416;
    goto v_2363;
v_2364:
    v_2413 = v_2415;
    goto v_2365;
v_2366:
    goto v_2362;
v_2363:
    goto v_2364;
v_2365:
    if (equal(v_2414, v_2413)) goto v_2360;
    else goto v_2361;
v_2360:
    v_2413 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2359;
v_2361:
    v_2413 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_2413)) v_2413 = nil;
    else { v_2413 = qfastgets(v_2413);
           if (v_2413 != nil) { v_2413 = elt(v_2413, 3); // field
#ifdef RECORD_GET
             if (v_2413 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_2413 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_2413 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_2413 == SPID_NOPROP) v_2413 = nil; else v_2413 = lisp_true; }}
#endif
    if (v_2413 == nil) goto v_2371;
    goto v_2379;
v_2375:
    v_2413 = v_2416;
    goto v_2376;
v_2377:
    v_2414 = v_2415;
    goto v_2378;
v_2379:
    goto v_2375;
v_2376:
    goto v_2377;
v_2378:
    {
        fn = elt(env, 2); // divd
        return (*qfn2(fn))(fn, v_2413, v_2414);
    }
v_2371:
    v_2413 = v_2416;
    if (!consp(v_2413)) goto v_2386;
    else goto v_2387;
v_2386:
    v_2413 = lisp_true;
    goto v_2385;
v_2387:
    v_2413 = v_2416;
    v_2413 = qcar(v_2413);
    v_2413 = (consp(v_2413) ? nil : lisp_true);
    goto v_2385;
    v_2413 = nil;
v_2385:
    if (v_2413 == nil) goto v_2383;
    goto v_2400;
v_2396:
    v_2413 = v_2416;
    goto v_2397;
v_2398:
    v_2414 = v_2415;
    goto v_2399;
v_2400:
    goto v_2396;
v_2397:
    goto v_2398;
v_2399:
    {
        fn = elt(env, 3); // quotdd
        return (*qfn2(fn))(fn, v_2413, v_2414);
    }
v_2383:
    goto v_2410;
v_2406:
    v_2413 = v_2416;
    goto v_2407;
v_2408:
    v_2414 = v_2415;
    goto v_2409;
v_2410:
    goto v_2406;
v_2407:
    goto v_2408;
v_2409:
    {
        fn = elt(env, 4); // quotk
        return (*qfn2(fn))(fn, v_2413, v_2414);
    }
    v_2413 = nil;
v_2359:
    return onevalue(v_2413);
}



// Code for find

static LispObject CC_find(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_3558, v_3559, v_3560;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_2355;
// end of prologue
v_2354:
    v_3558 = elt(env, 1); // mcd
    v_3558 = ncons(v_3558);
    env = stack[-3];
    fn = elt(env, 14); // off
    v_3558 = (*qfn1(fn))(fn, v_3558);
    env = stack[-3];
    v_3558 = elt(env, 2); // factor
    v_3558 = ncons(v_3558);
    env = stack[-3];
    fn = elt(env, 14); // off
    v_3558 = (*qfn1(fn))(fn, v_3558);
    env = stack[-3];
    v_3558 = elt(env, 3); // exp
    v_3558 = ncons(v_3558);
    env = stack[-3];
    fn = elt(env, 14); // off
    v_3558 = (*qfn1(fn))(fn, v_3558);
    env = stack[-3];
    v_3558 = stack[-1];
    if (!consp(v_3558)) goto v_2370;
    else goto v_2371;
v_2370:
    goto v_2382;
v_2378:
    v_3559 = stack[-1];
    goto v_2379;
v_2380:
    v_3558 = elt(env, 4); // ww
    goto v_2381;
v_2382:
    goto v_2378;
v_2379:
    goto v_2380;
v_2381:
    fn = elt(env, 15); // freeof
    v_3558 = (*qfn2(fn))(fn, v_3559, v_3558);
    env = stack[-3];
    if (v_3558 == nil) goto v_2376;
    v_3558 = stack[-1];
    if (is_number(v_3558)) goto v_2387;
    else goto v_2388;
v_2387:
    goto v_2395;
v_2391:
    v_3559 = elt(env, 5); // number
    goto v_2392;
v_2393:
    v_3558 = stack[-1];
    goto v_2394;
v_2395:
    goto v_2391;
v_2392:
    goto v_2393;
v_2394:
    return list2(v_3559, v_3558);
v_2388:
    goto v_2408;
v_2404:
    v_3559 = stack[-1];
    goto v_2405;
v_2406:
    v_3558 = elt(env, 6); // e
    goto v_2407;
v_2408:
    goto v_2404;
v_2405:
    goto v_2406;
v_2407:
    if (v_3559 == v_3558) goto v_2402;
    else goto v_2403;
v_2402:
    goto v_2416;
v_2412:
    v_3558 = elt(env, 5); // number
    goto v_2413;
v_2414:
    v_3559 = elt(env, 6); // e
    goto v_2415;
v_2416:
    goto v_2412;
v_2413:
    goto v_2414;
v_2415:
    return list2(v_3558, v_3559);
v_2403:
    goto v_2426;
v_2422:
    v_3559 = elt(env, 7); // x_exp
    goto v_2423;
v_2424:
    v_3558 = stack[-1];
    goto v_2425;
v_2426:
    goto v_2422;
v_2423:
    goto v_2424;
v_2425:
    return list2(v_3559, v_3558);
    goto v_2386;
v_2386:
    goto v_2374;
v_2376:
    goto v_2439;
v_2433:
    v_3559 = elt(env, 8); // expt
    goto v_2434;
v_2435:
    v_3560 = elt(env, 4); // ww
    goto v_2436;
v_2437:
    v_3558 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2438;
v_2439:
    goto v_2433;
v_2434:
    goto v_2435;
v_2436:
    goto v_2437;
v_2438:
    return list3(v_3559, v_3560, v_3558);
v_2374:
    goto v_2369;
v_2371:
    goto v_2453;
v_2449:
    v_3558 = stack[-1];
    v_3559 = qcar(v_3558);
    goto v_2450;
v_2451:
    v_3558 = elt(env, 8); // expt
    goto v_2452;
v_2453:
    goto v_2449;
v_2450:
    goto v_2451;
v_2452:
    if (v_3559 == v_3558) goto v_2447;
    else goto v_2448;
v_2447:
    goto v_2464;
v_2458:
    v_3560 = elt(env, 8); // expt
    goto v_2459;
v_2460:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_2461;
v_2462:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    goto v_2463;
v_2464:
    goto v_2458;
v_2459:
    goto v_2460;
v_2461:
    goto v_2462;
v_2463:
    return list3(v_3560, v_3559, v_3558);
v_2448:
    goto v_2483;
v_2479:
    v_3558 = stack[-1];
    v_3559 = qcar(v_3558);
    goto v_2480;
v_2481:
    v_3558 = elt(env, 9); // plus
    goto v_2482;
v_2483:
    goto v_2479;
v_2480:
    goto v_2481;
v_2482:
    if (v_3559 == v_3558) goto v_2477;
    else goto v_2478;
v_2477:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    if (!consp(v_3558)) goto v_2493;
    else goto v_2494;
v_2493:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = (consp(v_3558) ? nil : lisp_true);
    goto v_2492;
v_2494:
    v_3558 = nil;
    goto v_2492;
    v_3558 = nil;
v_2492:
    if (v_3558 == nil) goto v_2490;
    goto v_2515;
v_2511:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = Llength(nil, v_3558);
    env = stack[-3];
    goto v_2512;
v_2513:
    v_3558 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_2514;
v_2515:
    goto v_2511;
v_2512:
    goto v_2513;
v_2514:
    v_3558 = (LispObject)greaterp2(v_3559, v_3558);
    v_3558 = v_3558 ? lisp_true : nil;
    env = stack[-3];
    if (v_3558 == nil) goto v_2509;
    goto v_2532;
v_2528:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_2529;
v_2530:
    v_3558 = elt(env, 4); // ww
    goto v_2531;
v_2532:
    goto v_2528;
v_2529:
    goto v_2530;
v_2531:
    if (v_3559 == v_3558) goto v_2526;
    else goto v_2527;
v_2526:
    goto v_2542;
v_2538:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_2539;
v_2540:
    v_3558 = elt(env, 4); // ww
    goto v_2541;
v_2542:
    goto v_2538;
v_2539:
    goto v_2540;
v_2541:
    fn = elt(env, 15); // freeof
    v_3558 = (*qfn2(fn))(fn, v_3559, v_3558);
    env = stack[-3];
    goto v_2525;
v_2527:
    v_3558 = nil;
    goto v_2525;
    v_3558 = nil;
v_2525:
    if (v_3558 == nil) goto v_2523;
    goto v_2556;
v_2552:
    goto v_2564;
v_2558:
    v_3560 = elt(env, 8); // expt
    goto v_2559;
v_2560:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_2561;
v_2562:
    v_3558 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2563;
v_2564:
    goto v_2558;
v_2559:
    goto v_2560;
v_2561:
    goto v_2562;
v_2563:
    stack[0] = list3(v_3560, v_3559, v_3558);
    env = stack[-3];
    goto v_2553;
v_2554:
    goto v_2576;
v_2572:
    v_3558 = elt(env, 9); // plus
    v_3559 = ncons(v_3558);
    env = stack[-3];
    goto v_2573;
v_2574:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    goto v_2575;
v_2576:
    goto v_2572;
v_2573:
    goto v_2574;
v_2575:
    v_3558 = Lappend(nil, v_3559, v_3558);
    env = stack[-3];
    v_3558 = CC_find(elt(env, 0), v_3558);
    goto v_2555;
v_2556:
    goto v_2552;
v_2553:
    goto v_2554;
v_2555:
    {
        LispObject v_3564 = stack[0];
        return Lappend(nil, v_3564, v_3558);
    }
v_2523:
    goto v_2589;
v_2585:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    stack[0] = CC_find(elt(env, 0), v_3558);
    env = stack[-3];
    goto v_2586;
v_2587:
    goto v_2599;
v_2595:
    v_3558 = elt(env, 9); // plus
    v_3559 = ncons(v_3558);
    env = stack[-3];
    goto v_2596;
v_2597:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    goto v_2598;
v_2599:
    goto v_2595;
v_2596:
    goto v_2597;
v_2598:
    v_3558 = Lappend(nil, v_3559, v_3558);
    goto v_2588;
v_2589:
    goto v_2585;
v_2586:
    goto v_2587;
v_2588:
    {
        LispObject v_3565 = stack[0];
        return Lappend(nil, v_3565, v_3558);
    }
    goto v_2507;
v_2509:
    goto v_2619;
v_2615:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_2616;
v_2617:
    v_3558 = elt(env, 4); // ww
    goto v_2618;
v_2619:
    goto v_2615;
v_2616:
    goto v_2617;
v_2618:
    if (v_3559 == v_3558) goto v_2613;
    else goto v_2614;
v_2613:
    goto v_2630;
v_2626:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_2627;
v_2628:
    v_3558 = elt(env, 4); // ww
    goto v_2629;
v_2630:
    goto v_2626;
v_2627:
    goto v_2628;
v_2629:
    fn = elt(env, 15); // freeof
    v_3558 = (*qfn2(fn))(fn, v_3559, v_3558);
    env = stack[-3];
    goto v_2612;
v_2614:
    v_3558 = nil;
    goto v_2612;
    v_3558 = nil;
v_2612:
    if (v_3558 == nil) goto v_2610;
    goto v_2647;
v_2639:
    stack[-2] = elt(env, 7); // x_exp
    goto v_2640;
v_2641:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    stack[-1] = qcar(v_3558);
    goto v_2642;
v_2643:
    stack[0] = elt(env, 8); // expt
    goto v_2644;
v_2645:
    goto v_2658;
v_2654:
    v_3559 = elt(env, 4); // ww
    goto v_2655;
v_2656:
    v_3558 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2657;
v_2658:
    goto v_2654;
v_2655:
    goto v_2656;
v_2657:
    v_3558 = list2(v_3559, v_3558);
    goto v_2646;
v_2647:
    goto v_2639;
v_2640:
    goto v_2641;
v_2642:
    goto v_2643;
v_2644:
    goto v_2645;
v_2646:
    {
        LispObject v_3566 = stack[-2];
        LispObject v_3567 = stack[-1];
        LispObject v_3568 = stack[0];
        return list3star(v_3566, v_3567, v_3568, v_3558);
    }
v_2610:
    goto v_2675;
v_2671:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_2672;
v_2673:
    v_3558 = elt(env, 4); // ww
    goto v_2674;
v_2675:
    goto v_2671;
v_2672:
    goto v_2673;
v_2674:
    if (v_3559 == v_3558) goto v_2669;
    else goto v_2670;
v_2669:
    goto v_2685;
v_2681:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_2682;
v_2683:
    v_3558 = elt(env, 4); // ww
    goto v_2684;
v_2685:
    goto v_2681;
v_2682:
    goto v_2683;
v_2684:
    fn = elt(env, 15); // freeof
    v_3558 = (*qfn2(fn))(fn, v_3559, v_3558);
    env = stack[-3];
    goto v_2668;
v_2670:
    v_3558 = nil;
    goto v_2668;
    v_3558 = nil;
v_2668:
    if (v_3558 == nil) goto v_2666;
    goto v_2699;
v_2695:
    goto v_2707;
v_2701:
    v_3560 = elt(env, 8); // expt
    goto v_2702;
v_2703:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_2704;
v_2705:
    v_3558 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2706;
v_2707:
    goto v_2701;
v_2702:
    goto v_2703;
v_2704:
    goto v_2705;
v_2706:
    stack[0] = list3(v_3560, v_3559, v_3558);
    env = stack[-3];
    goto v_2696;
v_2697:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = CC_find(elt(env, 0), v_3558);
    goto v_2698;
v_2699:
    goto v_2695;
v_2696:
    goto v_2697;
v_2698:
    {
        LispObject v_3569 = stack[0];
        return Lappend(nil, v_3569, v_3558);
    }
v_2666:
    goto v_2725;
v_2721:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    stack[0] = CC_find(elt(env, 0), v_3558);
    env = stack[-3];
    goto v_2722;
v_2723:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = CC_find(elt(env, 0), v_3558);
    goto v_2724;
v_2725:
    goto v_2721;
v_2722:
    goto v_2723;
v_2724:
    {
        LispObject v_3570 = stack[0];
        return Lappend(nil, v_3570, v_3558);
    }
    goto v_2608;
v_2608:
    goto v_2507;
v_2507:
    goto v_2488;
v_2490:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    if (!consp(v_3558)) goto v_2743;
    else goto v_2744;
v_2743:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = Lconsp(nil, v_3558);
    env = stack[-3];
    goto v_2742;
v_2744:
    v_3558 = nil;
    goto v_2742;
    v_3558 = nil;
v_2742:
    if (v_3558 == nil) goto v_2740;
    goto v_2765;
v_2761:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = Llength(nil, v_3558);
    env = stack[-3];
    goto v_2762;
v_2763:
    v_3558 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_2764;
v_2765:
    goto v_2761;
v_2762:
    goto v_2763;
v_2764:
    v_3558 = (LispObject)greaterp2(v_3559, v_3558);
    v_3558 = v_3558 ? lisp_true : nil;
    env = stack[-3];
    if (v_3558 == nil) goto v_2759;
    goto v_2778;
v_2774:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_2775;
v_2776:
    v_3558 = elt(env, 4); // ww
    goto v_2777;
v_2778:
    goto v_2774;
v_2775:
    goto v_2776;
v_2777:
    if (v_3559 == v_3558) goto v_2772;
    else goto v_2773;
v_2772:
    goto v_2788;
v_2784:
    goto v_2796;
v_2790:
    v_3560 = elt(env, 8); // expt
    goto v_2791;
v_2792:
    v_3559 = elt(env, 4); // ww
    goto v_2793;
v_2794:
    v_3558 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2795;
v_2796:
    goto v_2790;
v_2791:
    goto v_2792;
v_2793:
    goto v_2794;
v_2795:
    stack[0] = list3(v_3560, v_3559, v_3558);
    env = stack[-3];
    goto v_2785;
v_2786:
    goto v_2806;
v_2802:
    v_3558 = elt(env, 9); // plus
    v_3559 = ncons(v_3558);
    env = stack[-3];
    goto v_2803;
v_2804:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    goto v_2805;
v_2806:
    goto v_2802;
v_2803:
    goto v_2804;
v_2805:
    v_3558 = Lappend(nil, v_3559, v_3558);
    env = stack[-3];
    v_3558 = CC_find(elt(env, 0), v_3558);
    goto v_2787;
v_2788:
    goto v_2784;
v_2785:
    goto v_2786;
v_2787:
    {
        LispObject v_3571 = stack[0];
        return Lappend(nil, v_3571, v_3558);
    }
v_2773:
    goto v_2819;
v_2815:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    stack[0] = CC_find(elt(env, 0), v_3558);
    env = stack[-3];
    goto v_2816;
v_2817:
    goto v_2830;
v_2826:
    v_3558 = elt(env, 9); // plus
    v_3559 = ncons(v_3558);
    env = stack[-3];
    goto v_2827;
v_2828:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    goto v_2829;
v_2830:
    goto v_2826;
v_2827:
    goto v_2828;
v_2829:
    v_3558 = Lappend(nil, v_3559, v_3558);
    env = stack[-3];
    v_3558 = CC_find(elt(env, 0), v_3558);
    goto v_2818;
v_2819:
    goto v_2815;
v_2816:
    goto v_2817;
v_2818:
    {
        LispObject v_3572 = stack[0];
        return Lappend(nil, v_3572, v_3558);
    }
    goto v_2757;
v_2759:
    goto v_2843;
v_2839:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    stack[0] = CC_find(elt(env, 0), v_3558);
    env = stack[-3];
    goto v_2840;
v_2841:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = CC_find(elt(env, 0), v_3558);
    goto v_2842;
v_2843:
    goto v_2839;
v_2840:
    goto v_2841;
v_2842:
    {
        LispObject v_3573 = stack[0];
        return Lappend(nil, v_3573, v_3558);
    }
v_2757:
    goto v_2738;
v_2740:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = Lconsp(nil, v_3558);
    env = stack[-3];
    if (v_3558 == nil) goto v_2858;
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = Lconsp(nil, v_3558);
    env = stack[-3];
    if (v_3558 == nil) goto v_2858;
    goto v_2879;
v_2875:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = Llength(nil, v_3558);
    env = stack[-3];
    goto v_2876;
v_2877:
    v_3558 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_2878;
v_2879:
    goto v_2875;
v_2876:
    goto v_2877;
v_2878:
    v_3558 = (LispObject)greaterp2(v_3559, v_3558);
    v_3558 = v_3558 ? lisp_true : nil;
    env = stack[-3];
    if (v_3558 == nil) goto v_2873;
    goto v_2889;
v_2885:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    stack[0] = CC_find(elt(env, 0), v_3558);
    env = stack[-3];
    goto v_2886;
v_2887:
    goto v_2900;
v_2896:
    v_3558 = elt(env, 9); // plus
    v_3559 = ncons(v_3558);
    env = stack[-3];
    goto v_2897;
v_2898:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    goto v_2899;
v_2900:
    goto v_2896;
v_2897:
    goto v_2898;
v_2899:
    v_3558 = Lappend(nil, v_3559, v_3558);
    env = stack[-3];
    v_3558 = CC_find(elt(env, 0), v_3558);
    goto v_2888;
v_2889:
    goto v_2885;
v_2886:
    goto v_2887;
v_2888:
    {
        LispObject v_3574 = stack[0];
        return Lappend(nil, v_3574, v_3558);
    }
v_2873:
    goto v_2913;
v_2909:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    stack[0] = CC_find(elt(env, 0), v_3558);
    env = stack[-3];
    goto v_2910;
v_2911:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = CC_find(elt(env, 0), v_3558);
    goto v_2912;
v_2913:
    goto v_2909;
v_2910:
    goto v_2911;
v_2912:
    {
        LispObject v_3575 = stack[0];
        return Lappend(nil, v_3575, v_3558);
    }
    goto v_2856;
v_2858:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = Lconsp(nil, v_3558);
    env = stack[-3];
    if (v_3558 == nil) goto v_2928;
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    if (!consp(v_3558)) goto v_2934;
    else goto v_2928;
v_2934:
    goto v_2948;
v_2944:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = Llength(nil, v_3558);
    env = stack[-3];
    goto v_2945;
v_2946:
    v_3558 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_2947;
v_2948:
    goto v_2944;
v_2945:
    goto v_2946;
v_2947:
    v_3558 = (LispObject)greaterp2(v_3559, v_3558);
    v_3558 = v_3558 ? lisp_true : nil;
    env = stack[-3];
    if (v_3558 == nil) goto v_2942;
    goto v_2961;
v_2957:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_2958;
v_2959:
    v_3558 = elt(env, 4); // ww
    goto v_2960;
v_2961:
    goto v_2957;
v_2958:
    goto v_2959;
v_2960:
    if (v_3559 == v_3558) goto v_2955;
    else goto v_2956;
v_2955:
    goto v_2974;
v_2968:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    stack[-2] = CC_find(elt(env, 0), v_3558);
    env = stack[-3];
    goto v_2969;
v_2970:
    goto v_2986;
v_2980:
    v_3560 = elt(env, 8); // expt
    goto v_2981;
v_2982:
    v_3559 = elt(env, 4); // ww
    goto v_2983;
v_2984:
    v_3558 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2985;
v_2986:
    goto v_2980;
v_2981:
    goto v_2982;
v_2983:
    goto v_2984;
v_2985:
    stack[0] = list3(v_3560, v_3559, v_3558);
    env = stack[-3];
    goto v_2971;
v_2972:
    goto v_2996;
v_2992:
    v_3558 = elt(env, 9); // plus
    v_3559 = ncons(v_3558);
    env = stack[-3];
    goto v_2993;
v_2994:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    goto v_2995;
v_2996:
    goto v_2992;
v_2993:
    goto v_2994;
v_2995:
    v_3558 = Lappend(nil, v_3559, v_3558);
    env = stack[-3];
    v_3558 = CC_find(elt(env, 0), v_3558);
    goto v_2973;
v_2974:
    goto v_2968;
v_2969:
    goto v_2970;
v_2971:
    goto v_2972;
v_2973:
    {
        LispObject v_3576 = stack[-2];
        LispObject v_3577 = stack[0];
        return list2star(v_3576, v_3577, v_3558);
    }
v_2956:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    if (is_number(v_3558)) goto v_3006;
    else goto v_3007;
v_3006:
    goto v_3019;
v_3013:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    stack[-2] = CC_find(elt(env, 0), v_3558);
    env = stack[-3];
    goto v_3014;
v_3015:
    goto v_3029;
v_3025:
    v_3559 = elt(env, 5); // number
    goto v_3026;
v_3027:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    goto v_3028;
v_3029:
    goto v_3025;
v_3026:
    goto v_3027;
v_3028:
    stack[0] = list2(v_3559, v_3558);
    env = stack[-3];
    goto v_3016;
v_3017:
    goto v_3041;
v_3037:
    v_3558 = elt(env, 9); // plus
    v_3559 = ncons(v_3558);
    env = stack[-3];
    goto v_3038;
v_3039:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    goto v_3040;
v_3041:
    goto v_3037;
v_3038:
    goto v_3039;
v_3040:
    v_3558 = Lappend(nil, v_3559, v_3558);
    env = stack[-3];
    v_3558 = CC_find(elt(env, 0), v_3558);
    goto v_3018;
v_3019:
    goto v_3013;
v_3014:
    goto v_3015;
v_3016:
    goto v_3017;
v_3018:
    {
        LispObject v_3578 = stack[-2];
        LispObject v_3579 = stack[0];
        return list2star(v_3578, v_3579, v_3558);
    }
v_3007:
    goto v_3005;
v_3005:
    goto v_2954;
v_2954:
    goto v_2940;
v_2942:
    goto v_3056;
v_3052:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    stack[0] = CC_find(elt(env, 0), v_3558);
    env = stack[-3];
    goto v_3053;
v_3054:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = CC_find(elt(env, 0), v_3558);
    goto v_3055;
v_3056:
    goto v_3052;
v_3053:
    goto v_3054;
v_3055:
    {
        LispObject v_3580 = stack[0];
        return Lappend(nil, v_3580, v_3558);
    }
v_2940:
    goto v_2926;
v_2928:
    goto v_3073;
v_3069:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    stack[0] = CC_find(elt(env, 0), v_3558);
    env = stack[-3];
    goto v_3070;
v_3071:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = ncons(v_3558);
    goto v_3072;
v_3073:
    goto v_3069;
v_3070:
    goto v_3071;
v_3072:
    {
        LispObject v_3581 = stack[0];
        return Lappend(nil, v_3581, v_3558);
    }
v_2926:
    goto v_2856;
v_2856:
    goto v_2738;
v_2738:
    goto v_2488;
v_2488:
    goto v_2476;
v_2478:
    goto v_3093;
v_3089:
    v_3558 = stack[-1];
    v_3559 = qcar(v_3558);
    goto v_3090;
v_3091:
    v_3558 = elt(env, 10); // lminus
    goto v_3092;
v_3093:
    goto v_3089;
v_3090:
    goto v_3091;
v_3092:
    if (v_3559 == v_3558) goto v_3087;
    else goto v_3088;
v_3087:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    if (is_number(v_3558)) goto v_3099;
    else goto v_3100;
v_3099:
    goto v_3109;
v_3105:
    v_3559 = elt(env, 5); // number
    goto v_3106;
v_3107:
    v_3558 = stack[-1];
    goto v_3108;
v_3109:
    goto v_3105;
v_3106:
    goto v_3107;
v_3108:
    return list2(v_3559, v_3558);
v_3100:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    stack[-1] = v_3558;
    goto v_2354;
    goto v_3086;
v_3088:
    goto v_3128;
v_3124:
    v_3558 = stack[-1];
    v_3559 = qcar(v_3558);
    goto v_3125;
v_3126:
    v_3558 = elt(env, 11); // quotient
    goto v_3127;
v_3128:
    goto v_3124;
v_3125:
    goto v_3126;
v_3127:
    if (v_3559 == v_3558) goto v_3122;
    else goto v_3123;
v_3122:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    if (is_number(v_3558)) goto v_3136;
    else goto v_3135;
v_3136:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    if (is_number(v_3558)) goto v_3140;
    else goto v_3135;
v_3140:
    goto v_3152;
v_3146:
    v_3560 = elt(env, 5); // number
    goto v_3147;
v_3148:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_3149;
v_3150:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    goto v_3151;
v_3152:
    goto v_3146;
v_3147:
    goto v_3148;
v_3149:
    goto v_3150;
v_3151:
    return list3(v_3560, v_3559, v_3558);
v_3135:
    goto v_3168;
v_3164:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    stack[0] = CC_find(elt(env, 0), v_3558);
    env = stack[-3];
    goto v_3165;
v_3166:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = CC_find(elt(env, 0), v_3558);
    goto v_3167;
v_3168:
    goto v_3164;
v_3165:
    goto v_3166;
v_3167:
    {
        LispObject v_3582 = stack[0];
        return Lappend(nil, v_3582, v_3558);
    }
    goto v_3121;
v_3123:
    goto v_3188;
v_3184:
    v_3558 = stack[-1];
    v_3559 = qcar(v_3558);
    goto v_3185;
v_3186:
    v_3558 = elt(env, 12); // minus
    goto v_3187;
v_3188:
    goto v_3184;
v_3185:
    goto v_3186;
v_3187:
    if (v_3559 == v_3558) goto v_3182;
    else goto v_3183;
v_3182:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    if (!consp(v_3558)) goto v_3194;
    else goto v_3195;
v_3194:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    stack[-1] = v_3558;
    goto v_2354;
v_3195:
    goto v_3216;
v_3212:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_3213;
v_3214:
    v_3558 = elt(env, 8); // expt
    goto v_3215;
v_3216:
    goto v_3212;
v_3213:
    goto v_3214;
v_3215:
    if (v_3559 == v_3558) goto v_3210;
    else goto v_3211;
v_3210:
    goto v_3225;
v_3221:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_3222;
v_3223:
    v_3558 = elt(env, 4); // ww
    goto v_3224;
v_3225:
    goto v_3221;
v_3222:
    goto v_3223;
v_3224:
    v_3558 = (v_3559 == v_3558 ? lisp_true : nil);
    goto v_3209;
v_3211:
    v_3558 = nil;
    goto v_3209;
    v_3558 = nil;
v_3209:
    if (v_3558 == nil) goto v_3207;
    goto v_3240;
v_3236:
    goto v_3246;
v_3242:
    v_3558 = elt(env, 12); // minus
    stack[0] = ncons(v_3558);
    env = stack[-3];
    goto v_3243;
v_3244:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = CC_find(elt(env, 0), v_3558);
    env = stack[-3];
    goto v_3245;
v_3246:
    goto v_3242;
v_3243:
    goto v_3244;
v_3245:
    stack[0] = Lappend(nil, stack[0], v_3558);
    env = stack[-3];
    goto v_3237;
v_3238:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = CC_find(elt(env, 0), v_3558);
    goto v_3239;
v_3240:
    goto v_3236;
v_3237:
    goto v_3238;
v_3239:
    {
        LispObject v_3583 = stack[0];
        return Lappend(nil, v_3583, v_3558);
    }
v_3207:
    goto v_3265;
v_3261:
    v_3558 = elt(env, 12); // minus
    stack[0] = ncons(v_3558);
    env = stack[-3];
    goto v_3262;
v_3263:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = CC_find(elt(env, 0), v_3558);
    goto v_3264;
v_3265:
    goto v_3261;
v_3262:
    goto v_3263;
v_3264:
    {
        LispObject v_3584 = stack[0];
        return Lappend(nil, v_3584, v_3558);
    }
    goto v_3193;
v_3193:
    goto v_3181;
v_3183:
    goto v_3282;
v_3278:
    v_3558 = stack[-1];
    v_3559 = qcar(v_3558);
    goto v_3279;
v_3280:
    v_3558 = elt(env, 13); // times
    goto v_3281;
v_3282:
    goto v_3278;
v_3279:
    goto v_3280;
v_3281:
    if (v_3559 == v_3558) goto v_3276;
    else goto v_3277;
v_3276:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    if (!consp(v_3558)) goto v_3292;
    else goto v_3293;
v_3292:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = (consp(v_3558) ? nil : lisp_true);
    goto v_3291;
v_3293:
    v_3558 = nil;
    goto v_3291;
    v_3558 = nil;
v_3291:
    if (v_3558 == nil) goto v_3289;
    goto v_3314;
v_3310:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_3311;
v_3312:
    v_3558 = elt(env, 4); // ww
    goto v_3313;
v_3314:
    goto v_3310;
v_3311:
    goto v_3312;
v_3313:
    fn = elt(env, 15); // freeof
    v_3558 = (*qfn2(fn))(fn, v_3559, v_3558);
    env = stack[-3];
    if (v_3558 == nil) goto v_3307;
    else goto v_3308;
v_3307:
    goto v_3326;
v_3320:
    v_3560 = elt(env, 8); // expt
    goto v_3321;
v_3322:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_3323;
v_3324:
    v_3558 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3325;
v_3326:
    goto v_3320;
v_3321:
    goto v_3322;
v_3323:
    goto v_3324;
v_3325:
    return list3(v_3560, v_3559, v_3558);
v_3308:
    goto v_3343;
v_3339:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_3340;
v_3341:
    v_3558 = elt(env, 4); // ww
    goto v_3342;
v_3343:
    goto v_3339;
v_3340:
    goto v_3341;
v_3342:
    fn = elt(env, 15); // freeof
    v_3558 = (*qfn2(fn))(fn, v_3559, v_3558);
    if (v_3558 == nil) goto v_3336;
    else goto v_3337;
v_3336:
    goto v_3354;
v_3350:
    v_3559 = nil;
    goto v_3351;
v_3352:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    goto v_3353;
v_3354:
    goto v_3350;
v_3351:
    goto v_3352;
v_3353:
    return list2(v_3559, v_3558);
v_3337:
    goto v_3335;
v_3335:
    goto v_3306;
v_3306:
    goto v_3287;
v_3289:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    if (!consp(v_3558)) goto v_3371;
    else goto v_3372;
v_3371:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = Lconsp(nil, v_3558);
    env = stack[-3];
    goto v_3370;
v_3372:
    v_3558 = nil;
    goto v_3370;
    v_3558 = nil;
v_3370:
    if (v_3558 == nil) goto v_3368;
    goto v_3393;
v_3389:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_3390;
v_3391:
    v_3558 = elt(env, 4); // ww
    goto v_3392;
v_3393:
    goto v_3389;
v_3390:
    goto v_3391;
v_3392:
    fn = elt(env, 15); // freeof
    v_3558 = (*qfn2(fn))(fn, v_3559, v_3558);
    env = stack[-3];
    if (v_3558 == nil) goto v_3386;
    else goto v_3387;
v_3386:
    goto v_3405;
v_3399:
    v_3560 = elt(env, 8); // expt
    goto v_3400;
v_3401:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_3402;
v_3403:
    v_3558 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3404;
v_3405:
    goto v_3399;
v_3400:
    goto v_3401;
v_3402:
    goto v_3403;
v_3404:
    return list3(v_3560, v_3559, v_3558);
v_3387:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    stack[-1] = v_3558;
    goto v_2354;
    goto v_3366;
v_3368:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = Lconsp(nil, v_3558);
    env = stack[-3];
    if (v_3558 == nil) goto v_3423;
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = Lconsp(nil, v_3558);
    env = stack[-3];
    if (v_3558 == nil) goto v_3423;
    goto v_3444;
v_3440:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = Llength(nil, v_3558);
    env = stack[-3];
    goto v_3441;
v_3442:
    v_3558 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_3443;
v_3444:
    goto v_3440;
v_3441:
    goto v_3442;
v_3443:
    v_3558 = (LispObject)greaterp2(v_3559, v_3558);
    v_3558 = v_3558 ? lisp_true : nil;
    env = stack[-3];
    if (v_3558 == nil) goto v_3438;
    goto v_3454;
v_3450:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    stack[0] = CC_find(elt(env, 0), v_3558);
    env = stack[-3];
    goto v_3451;
v_3452:
    goto v_3465;
v_3461:
    v_3558 = elt(env, 13); // times
    v_3559 = ncons(v_3558);
    env = stack[-3];
    goto v_3462;
v_3463:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    goto v_3464;
v_3465:
    goto v_3461;
v_3462:
    goto v_3463;
v_3464:
    v_3558 = Lappend(nil, v_3559, v_3558);
    env = stack[-3];
    v_3558 = CC_find(elt(env, 0), v_3558);
    goto v_3453;
v_3454:
    goto v_3450;
v_3451:
    goto v_3452;
v_3453:
    {
        LispObject v_3585 = stack[0];
        return Lappend(nil, v_3585, v_3558);
    }
v_3438:
    goto v_3478;
v_3474:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    stack[0] = CC_find(elt(env, 0), v_3558);
    env = stack[-3];
    goto v_3475;
v_3476:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = CC_find(elt(env, 0), v_3558);
    goto v_3477;
v_3478:
    goto v_3474;
v_3475:
    goto v_3476;
v_3477:
    {
        LispObject v_3586 = stack[0];
        return Lappend(nil, v_3586, v_3558);
    }
    goto v_3421;
v_3423:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = Lconsp(nil, v_3558);
    env = stack[-3];
    if (v_3558 == nil) goto v_3493;
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    if (!consp(v_3558)) goto v_3499;
    else goto v_3493;
v_3499:
    goto v_3514;
v_3510:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_3511;
v_3512:
    v_3558 = elt(env, 4); // ww
    goto v_3513;
v_3514:
    goto v_3510;
v_3511:
    goto v_3512;
v_3513:
    fn = elt(env, 15); // freeof
    v_3558 = (*qfn2(fn))(fn, v_3559, v_3558);
    env = stack[-3];
    if (v_3558 == nil) goto v_3507;
    goto v_3524;
v_3520:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3559 = qcar(v_3558);
    goto v_3521;
v_3522:
    v_3558 = elt(env, 4); // ww
    goto v_3523;
v_3524:
    goto v_3520;
v_3521:
    goto v_3522;
v_3523:
    if (v_3559 == v_3558) goto v_3519;
    else goto v_3507;
v_3519:
    goto v_3537;
v_3531:
    v_3559 = elt(env, 8); // expt
    goto v_3532;
v_3533:
    v_3560 = elt(env, 4); // ww
    goto v_3534;
v_3535:
    v_3558 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3536;
v_3537:
    goto v_3531;
v_3532:
    goto v_3533;
v_3534:
    goto v_3535;
v_3536:
    return list3(v_3559, v_3560, v_3558);
v_3507:
    goto v_3548;
v_3544:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    stack[0] = CC_find(elt(env, 0), v_3558);
    env = stack[-3];
    goto v_3545;
v_3546:
    v_3558 = stack[-1];
    v_3558 = qcdr(v_3558);
    v_3558 = qcdr(v_3558);
    v_3558 = qcar(v_3558);
    v_3558 = CC_find(elt(env, 0), v_3558);
    goto v_3547;
v_3548:
    goto v_3544;
v_3545:
    goto v_3546;
v_3547:
    {
        LispObject v_3587 = stack[0];
        return Lappend(nil, v_3587, v_3558);
    }
    goto v_3491;
v_3493:
v_3491:
    goto v_3421;
v_3421:
    goto v_3366;
v_3366:
    goto v_3287;
v_3287:
    goto v_3275;
v_3277:
v_3275:
    goto v_3181;
v_3181:
    goto v_3121;
v_3121:
    goto v_3086;
v_3086:
    goto v_2476;
v_2476:
    goto v_2446;
v_2446:
    goto v_2369;
v_2369:
    v_3558 = nil;
    return onevalue(v_3558);
}



// Code for freexp

static LispObject CC_freexp(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2375;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2355;
// end of prologue
v_2354:
    v_2375 = stack[0];
    if (!consp(v_2375)) goto v_2359;
    else goto v_2360;
v_2359:
    v_2375 = stack[0];
    {
        fn = elt(env, 1); // pm!:free
        return (*qfn1(fn))(fn, v_2375);
    }
v_2360:
    v_2375 = stack[0];
    v_2375 = qcar(v_2375);
    v_2375 = CC_freexp(elt(env, 0), v_2375);
    env = stack[-1];
    if (v_2375 == nil) goto v_2368;
    else goto v_2367;
v_2368:
    v_2375 = stack[0];
    v_2375 = qcdr(v_2375);
    stack[0] = v_2375;
    goto v_2354;
v_2367:
    goto v_2358;
    v_2375 = nil;
v_2358:
    return onevalue(v_2375);
}



// Code for prepd

static LispObject CC_prepd(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2436, v_2437;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2355;
// end of prologue
    v_2436 = stack[0];
    if (!consp(v_2436)) goto v_2359;
    else goto v_2360;
v_2359:
    goto v_2371;
v_2367:
    v_2437 = stack[0];
    goto v_2368;
v_2369:
    v_2436 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2370;
v_2371:
    goto v_2367;
v_2368:
    goto v_2369;
v_2370:
    v_2436 = (LispObject)lessp2(v_2437, v_2436);
    v_2436 = v_2436 ? lisp_true : nil;
    env = stack[-2];
    if (v_2436 == nil) goto v_2365;
    goto v_2379;
v_2375:
    stack[-1] = elt(env, 1); // minus
    goto v_2376;
v_2377:
    v_2436 = stack[0];
    v_2436 = negate(v_2436);
    goto v_2378;
v_2379:
    goto v_2375;
v_2376:
    goto v_2377;
v_2378:
    {
        LispObject v_2440 = stack[-1];
        return list2(v_2440, v_2436);
    }
v_2365:
    v_2436 = stack[0];
    goto v_2363;
    v_2436 = nil;
v_2363:
    goto v_2358;
v_2360:
    goto v_2393;
v_2389:
    v_2436 = stack[0];
    v_2436 = qcar(v_2436);
    if (!symbolp(v_2436)) v_2437 = nil;
    else { v_2437 = qfastgets(v_2436);
           if (v_2437 != nil) { v_2437 = elt(v_2437, 30); // minusp
#ifdef RECORD_GET
             if (v_2437 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v_2437 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v_2437 == SPID_NOPROP) v_2437 = nil; }}
#endif
    goto v_2390;
v_2391:
    v_2436 = stack[0];
    goto v_2392;
v_2393:
    goto v_2389;
v_2390:
    goto v_2391;
v_2392:
    v_2436 = Lapply1(nil, v_2437, v_2436);
    env = stack[-2];
    if (v_2436 == nil) goto v_2387;
    v_2436 = stack[0];
    fn = elt(env, 3); // !:minus
    v_2436 = (*qfn1(fn))(fn, v_2436);
    env = stack[-2];
    fn = elt(env, 4); // prepd1
    v_2436 = (*qfn1(fn))(fn, v_2436);
    env = stack[-2];
    v_2437 = v_2436;
    v_2436 = v_2437;
    if (v_2436 == nil) goto v_2404;
    else goto v_2405;
v_2404:
    v_2436 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2403;
v_2405:
    goto v_2415;
v_2411:
    v_2436 = elt(env, 1); // minus
    goto v_2412;
v_2413:
    goto v_2414;
v_2415:
    goto v_2411;
v_2412:
    goto v_2413;
v_2414:
    return list2(v_2436, v_2437);
    v_2436 = nil;
v_2403:
    goto v_2358;
v_2387:
    goto v_2425;
v_2421:
    goto v_2431;
v_2427:
    v_2436 = stack[0];
    v_2437 = qcar(v_2436);
    goto v_2428;
v_2429:
    v_2436 = elt(env, 2); // prepfn
    goto v_2430;
v_2431:
    goto v_2427;
v_2428:
    goto v_2429;
v_2430:
    v_2437 = get(v_2437, v_2436);
    goto v_2422;
v_2423:
    v_2436 = stack[0];
    goto v_2424;
v_2425:
    goto v_2421;
v_2422:
    goto v_2423;
v_2424:
        return Lapply1(nil, v_2437, v_2436);
    v_2436 = nil;
v_2358:
    return onevalue(v_2436);
}



// Code for diplength

static LispObject CC_diplength(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2398, v_2399;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2355;
// end of prologue
    stack[-1] = nil;
v_2361:
    v_2398 = stack[0];
    if (v_2398 == nil) goto v_2366;
    else goto v_2367;
v_2366:
    goto v_2362;
v_2367:
    goto v_2374;
v_2370:
    v_2399 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2371;
v_2372:
    v_2398 = stack[-1];
    goto v_2373;
v_2374:
    goto v_2370;
v_2371:
    goto v_2372;
v_2373:
    v_2398 = cons(v_2399, v_2398);
    env = stack[-2];
    stack[-1] = v_2398;
    v_2398 = stack[0];
    v_2398 = qcdr(v_2398);
    v_2398 = qcdr(v_2398);
    stack[0] = v_2398;
    goto v_2361;
v_2362:
    v_2398 = (LispObject)0+TAG_FIXNUM; // 0
    v_2399 = v_2398;
v_2363:
    v_2398 = stack[-1];
    if (v_2398 == nil) goto v_2383;
    else goto v_2384;
v_2383:
    v_2398 = v_2399;
    goto v_2360;
v_2384:
    goto v_2392;
v_2388:
    v_2398 = stack[-1];
    v_2398 = qcar(v_2398);
    goto v_2389;
v_2390:
    goto v_2391;
v_2392:
    goto v_2388;
v_2389:
    goto v_2390;
v_2391:
    v_2398 = plus2(v_2398, v_2399);
    env = stack[-2];
    v_2399 = v_2398;
    v_2398 = stack[-1];
    v_2398 = qcdr(v_2398);
    stack[-1] = v_2398;
    goto v_2363;
v_2360:
    return onevalue(v_2398);
}



// Code for quotematrix

static LispObject CC_quotematrix(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2358;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2358 = v_2355;
// end of prologue
    v_2358 = elt(env, 1); // matrix
    return onevalue(v_2358);
}



// Code for deg!*farg

static LispObject CC_degHfarg(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2397, v_2398;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_2398 = v_2355;
// end of prologue
    v_2397 = v_2398;
    v_2397 = qcdr(v_2397);
    if (v_2397 == nil) goto v_2359;
    else goto v_2360;
v_2359:
    v_2397 = v_2398;
    v_2397 = qcar(v_2397);
    {
        fn = elt(env, 1); // deg!*form
        return (*qfn1(fn))(fn, v_2397);
    }
v_2360:
    stack[-1] = nil;
    v_2397 = v_2398;
    stack[0] = v_2397;
v_2374:
    v_2397 = stack[0];
    if (v_2397 == nil) goto v_2378;
    else goto v_2379;
v_2378:
    goto v_2373;
v_2379:
    v_2397 = stack[0];
    v_2397 = qcar(v_2397);
    goto v_2390;
v_2386:
    fn = elt(env, 1); // deg!*form
    v_2398 = (*qfn1(fn))(fn, v_2397);
    env = stack[-2];
    goto v_2387;
v_2388:
    v_2397 = stack[-1];
    goto v_2389;
v_2390:
    goto v_2386;
v_2387:
    goto v_2388;
v_2389:
    fn = elt(env, 2); // addf
    v_2397 = (*qfn2(fn))(fn, v_2398, v_2397);
    env = stack[-2];
    stack[-1] = v_2397;
    v_2397 = stack[0];
    v_2397 = qcdr(v_2397);
    stack[0] = v_2397;
    goto v_2374;
v_2373:
    v_2397 = stack[-1];
    goto v_2358;
    v_2397 = nil;
v_2358:
    return onevalue(v_2397);
}



// Code for round!:mt

static LispObject CC_roundTmt(LispObject env,
                         LispObject v_2355, LispObject v_2356)
{
    env = qenv(env);
    LispObject v_2478, v_2479;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2355,v_2356);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_2356;
    stack[-2] = v_2355;
// end of prologue
    goto v_2375;
v_2371:
    v_2479 = stack[-2];
    goto v_2372;
v_2373:
    v_2478 = elt(env, 1); // !:rd!:
    goto v_2374;
v_2375:
    goto v_2371;
v_2372:
    goto v_2373;
v_2374:
    if (!consp(v_2479)) goto v_2369;
    v_2479 = qcar(v_2479);
    if (v_2479 == v_2478) goto v_2368;
    else goto v_2369;
v_2368:
    v_2478 = stack[-2];
    v_2478 = qcdr(v_2478);
    v_2478 = (consp(v_2478) ? nil : lisp_true);
    v_2478 = (v_2478 == nil ? lisp_true : nil);
    goto v_2367;
v_2369:
    v_2478 = nil;
    goto v_2367;
    v_2478 = nil;
v_2367:
    if (v_2478 == nil) goto v_2365;
    v_2478 = stack[-1];
    v_2478 = integerp(v_2478);
    if (v_2478 == nil) goto v_2387;
    else goto v_2388;
v_2387:
    v_2478 = nil;
    goto v_2386;
v_2388:
    goto v_2399;
v_2395:
    v_2479 = stack[-1];
    goto v_2396;
v_2397:
    v_2478 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2398;
v_2399:
    goto v_2395;
v_2396:
    goto v_2397;
v_2398:
    v_2478 = (LispObject)greaterp2(v_2479, v_2478);
    v_2478 = v_2478 ? lisp_true : nil;
    env = stack[-4];
    goto v_2386;
    v_2478 = nil;
v_2386:
    goto v_2363;
v_2365:
    v_2478 = nil;
    goto v_2363;
    v_2478 = nil;
v_2363:
    if (v_2478 == nil) goto v_2361;
    goto v_2414;
v_2410:
    goto v_2421;
v_2417:
    v_2478 = stack[-2];
    v_2478 = qcdr(v_2478);
    v_2478 = qcar(v_2478);
    v_2478 = Labsval(nil, v_2478);
    env = stack[-4];
    fn = elt(env, 2); // msd
    v_2479 = (*qfn1(fn))(fn, v_2478);
    env = stack[-4];
    goto v_2418;
v_2419:
    v_2478 = stack[-1];
    goto v_2420;
v_2421:
    goto v_2417;
v_2418:
    goto v_2419;
v_2420:
    v_2478 = difference2(v_2479, v_2478);
    env = stack[-4];
    v_2479 = sub1(v_2478);
    env = stack[-4];
    stack[-1] = v_2479;
    goto v_2411;
v_2412:
    v_2478 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2413;
v_2414:
    goto v_2410;
v_2411:
    goto v_2412;
v_2413:
    v_2478 = (LispObject)lessp2(v_2479, v_2478);
    v_2478 = v_2478 ? lisp_true : nil;
    env = stack[-4];
    if (v_2478 == nil) goto v_2408;
    v_2478 = stack[-2];
    goto v_2406;
v_2408:
    goto v_2436;
v_2432:
    v_2479 = stack[-1];
    goto v_2433;
v_2434:
    v_2478 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2435;
v_2436:
    goto v_2432;
v_2433:
    goto v_2434;
v_2435:
    if (v_2479 == v_2478) goto v_2430;
    else goto v_2431;
v_2430:
    v_2478 = stack[-2];
    {
        fn = elt(env, 3); // round!:last
        return (*qfn1(fn))(fn, v_2478);
    }
v_2431:
    goto v_2451;
v_2445:
    stack[-3] = elt(env, 1); // !:rd!:
    goto v_2446;
v_2447:
    goto v_2458;
v_2454:
    v_2478 = stack[-2];
    v_2478 = qcdr(v_2478);
    stack[0] = qcar(v_2478);
    goto v_2455;
v_2456:
    v_2478 = stack[-1];
    v_2478 = negate(v_2478);
    env = stack[-4];
    goto v_2457;
v_2458:
    goto v_2454;
v_2455:
    goto v_2456;
v_2457:
    fn = elt(env, 4); // ashift
    stack[0] = (*qfn2(fn))(fn, stack[0], v_2478);
    env = stack[-4];
    goto v_2448;
v_2449:
    goto v_2469;
v_2465:
    v_2478 = stack[-2];
    v_2478 = qcdr(v_2478);
    v_2479 = qcdr(v_2478);
    goto v_2466;
v_2467:
    v_2478 = stack[-1];
    goto v_2468;
v_2469:
    goto v_2465;
v_2466:
    goto v_2467;
v_2468:
    v_2478 = plus2(v_2479, v_2478);
    env = stack[-4];
    goto v_2450;
v_2451:
    goto v_2445;
v_2446:
    goto v_2447;
v_2448:
    goto v_2449;
v_2450:
    v_2478 = list2star(stack[-3], stack[0], v_2478);
    env = stack[-4];
    {
        fn = elt(env, 3); // round!:last
        return (*qfn1(fn))(fn, v_2478);
    }
    v_2478 = nil;
v_2406:
    goto v_2359;
v_2361:
    v_2478 = elt(env, 0); // round!:mt
    {
        fn = elt(env, 5); // bflerrmsg
        return (*qfn1(fn))(fn, v_2478);
    }
    v_2478 = nil;
v_2359:
    return onevalue(v_2478);
}



// Code for gizerop!:

static LispObject CC_gizeropT(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2383, v_2384, v_2385;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2384 = v_2355;
// end of prologue
    goto v_2365;
v_2361:
    v_2383 = v_2384;
    v_2383 = qcdr(v_2383);
    v_2385 = qcar(v_2383);
    goto v_2362;
v_2363:
    v_2383 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2364;
v_2365:
    goto v_2361;
v_2362:
    goto v_2363;
v_2364:
    if (v_2385 == v_2383) goto v_2359;
    else goto v_2360;
v_2359:
    goto v_2374;
v_2370:
    v_2383 = v_2384;
    v_2383 = qcdr(v_2383);
    v_2384 = qcdr(v_2383);
    goto v_2371;
v_2372:
    v_2383 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2373;
v_2374:
    goto v_2370;
v_2371:
    goto v_2372;
v_2373:
    v_2383 = (v_2384 == v_2383 ? lisp_true : nil);
    goto v_2358;
v_2360:
    v_2383 = nil;
    goto v_2358;
    v_2383 = nil;
v_2358:
    return onevalue(v_2383);
}



// Code for red!-char!-downcase

static LispObject CC_redKcharKdowncase(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2376, v_2377, v_2378;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2377 = v_2355;
// end of prologue
    goto v_2361;
v_2357:
    v_2376 = v_2377;
    goto v_2358;
v_2359:
    v_2378 = qvalue(elt(env, 1)); // charassoc!*
    goto v_2360;
v_2361:
    goto v_2357;
v_2358:
    goto v_2359;
v_2360:
    v_2376 = Latsoc(nil, v_2376, v_2378);
    v_2378 = v_2376;
    v_2376 = v_2378;
    if (v_2376 == nil) goto v_2369;
    v_2376 = v_2378;
    v_2376 = qcdr(v_2376);
    goto v_2367;
v_2369:
    v_2376 = v_2377;
    goto v_2367;
    v_2376 = nil;
v_2367:
    return onevalue(v_2376);
}



// Code for repeatsp

static LispObject CC_repeatsp(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2381, v_2382, v_2383;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2382 = v_2355;
// end of prologue
v_2354:
    v_2381 = v_2382;
    if (v_2381 == nil) goto v_2359;
    else goto v_2360;
v_2359:
    v_2381 = nil;
    goto v_2358;
v_2360:
    goto v_2372;
v_2368:
    v_2381 = v_2382;
    v_2383 = qcar(v_2381);
    goto v_2369;
v_2370:
    v_2381 = v_2382;
    v_2381 = qcdr(v_2381);
    goto v_2371;
v_2372:
    goto v_2368;
v_2369:
    goto v_2370;
v_2371:
    v_2381 = Lmember(nil, v_2383, v_2381);
    if (v_2381 == nil) goto v_2367;
    else goto v_2366;
v_2367:
    v_2381 = v_2382;
    v_2381 = qcdr(v_2381);
    v_2382 = v_2381;
    goto v_2354;
v_2366:
    goto v_2358;
    v_2381 = nil;
v_2358:
    return onevalue(v_2381);
}



// Code for red_divtestbe

static LispObject CC_red_divtestbe(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2399, v_2400;
    LispObject fn;
    LispObject v_2357, v_2356, v_2355;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "red_divtestbe");
    va_start(aa, nargs);
    v_2355 = va_arg(aa, LispObject);
    v_2356 = va_arg(aa, LispObject);
    v_2357 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_2357,v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_2355,v_2356,v_2357);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_2357;
    stack[-1] = v_2356;
    stack[-2] = v_2355;
// end of prologue
v_2361:
    v_2399 = stack[-2];
    if (v_2399 == nil) goto v_2364;
    else goto v_2365;
v_2364:
    v_2399 = nil;
    goto v_2360;
v_2365:
    goto v_2376;
v_2372:
    v_2399 = stack[-2];
    v_2399 = qcar(v_2399);
    fn = elt(env, 1); // bas_dpecart
    v_2400 = (*qfn1(fn))(fn, v_2399);
    env = stack[-3];
    goto v_2373;
v_2374:
    v_2399 = stack[0];
    goto v_2375;
v_2376:
    goto v_2372;
v_2373:
    goto v_2374;
v_2375:
    v_2399 = (LispObject)lesseq2(v_2400, v_2399);
    v_2399 = v_2399 ? lisp_true : nil;
    env = stack[-3];
    if (v_2399 == nil) goto v_2369;
    goto v_2387;
v_2383:
    v_2399 = stack[-2];
    v_2399 = qcar(v_2399);
    fn = elt(env, 2); // bas_dpoly
    v_2399 = (*qfn1(fn))(fn, v_2399);
    env = stack[-3];
    fn = elt(env, 3); // dp_lmon
    v_2400 = (*qfn1(fn))(fn, v_2399);
    env = stack[-3];
    goto v_2384;
v_2385:
    v_2399 = stack[-1];
    goto v_2386;
v_2387:
    goto v_2383;
v_2384:
    goto v_2385;
v_2386:
    fn = elt(env, 4); // mo_vdivides!?
    v_2399 = (*qfn2(fn))(fn, v_2400, v_2399);
    env = stack[-3];
    if (v_2399 == nil) goto v_2369;
    v_2399 = stack[-2];
    v_2399 = qcar(v_2399);
    goto v_2360;
v_2369:
    v_2399 = stack[-2];
    v_2399 = qcdr(v_2399);
    stack[-2] = v_2399;
    goto v_2361;
    v_2399 = nil;
v_2360:
    return onevalue(v_2399);
}



// Code for resimp1

static LispObject CC_resimp1(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2385, v_2386;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2355;
// end of prologue
    goto v_2364;
v_2360:
    goto v_2370;
v_2366:
    v_2385 = stack[0];
    v_2386 = qcar(v_2385);
    goto v_2367;
v_2368:
    v_2385 = nil;
    goto v_2369;
v_2370:
    goto v_2366;
v_2367:
    goto v_2368;
v_2369:
    fn = elt(env, 2); // subf1
    stack[-1] = (*qfn2(fn))(fn, v_2386, v_2385);
    env = stack[-2];
    goto v_2361;
v_2362:
    goto v_2379;
v_2375:
    v_2385 = stack[0];
    v_2386 = qcdr(v_2385);
    goto v_2376;
v_2377:
    v_2385 = nil;
    goto v_2378;
v_2379:
    goto v_2375;
v_2376:
    goto v_2377;
v_2378:
    fn = elt(env, 2); // subf1
    v_2385 = (*qfn2(fn))(fn, v_2386, v_2385);
    env = stack[-2];
    goto v_2363;
v_2364:
    goto v_2360;
v_2361:
    goto v_2362;
v_2363:
    fn = elt(env, 3); // quotsq
    v_2385 = (*qfn2(fn))(fn, stack[-1], v_2385);
    env = stack[-2];
    stack[0] = v_2385;
    v_2385 = lisp_true;
    qvalue(elt(env, 1)) = v_2385; // !*sub2
    v_2385 = stack[0];
    return onevalue(v_2385);
}



// Code for pappl_pv

static LispObject CC_pappl_pv(LispObject env,
                         LispObject v_2355, LispObject v_2356)
{
    env = qenv(env);
    LispObject v_2431, v_2432;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2355,v_2356);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_2431 = v_2356;
    stack[-4] = v_2355;
// end of prologue
    stack[-5] = v_2431;
    v_2431 = stack[-5];
    if (v_2431 == nil) goto v_2368;
    else goto v_2369;
v_2368:
    v_2431 = nil;
    goto v_2363;
v_2369:
    v_2431 = stack[-5];
    v_2431 = qcar(v_2431);
    goto v_2381;
v_2377:
    v_2432 = v_2431;
    stack[0] = qcar(v_2432);
    goto v_2378;
v_2379:
    goto v_2389;
v_2385:
    v_2432 = stack[-4];
    goto v_2386;
v_2387:
    v_2431 = qcdr(v_2431);
    goto v_2388;
v_2389:
    goto v_2385;
v_2386:
    goto v_2387;
v_2388:
    fn = elt(env, 1); // pappl0
    v_2431 = (*qfn2(fn))(fn, v_2432, v_2431);
    env = stack[-6];
    goto v_2380;
v_2381:
    goto v_2377;
v_2378:
    goto v_2379;
v_2380:
    v_2431 = cons(stack[0], v_2431);
    env = stack[-6];
    v_2431 = ncons(v_2431);
    env = stack[-6];
    stack[-2] = v_2431;
    stack[-3] = v_2431;
v_2364:
    v_2431 = stack[-5];
    v_2431 = qcdr(v_2431);
    stack[-5] = v_2431;
    v_2431 = stack[-5];
    if (v_2431 == nil) goto v_2397;
    else goto v_2398;
v_2397:
    v_2431 = stack[-3];
    goto v_2363;
v_2398:
    goto v_2406;
v_2402:
    stack[-1] = stack[-2];
    goto v_2403;
v_2404:
    v_2431 = stack[-5];
    v_2431 = qcar(v_2431);
    goto v_2417;
v_2413:
    v_2432 = v_2431;
    stack[0] = qcar(v_2432);
    goto v_2414;
v_2415:
    goto v_2425;
v_2421:
    v_2432 = stack[-4];
    goto v_2422;
v_2423:
    v_2431 = qcdr(v_2431);
    goto v_2424;
v_2425:
    goto v_2421;
v_2422:
    goto v_2423;
v_2424:
    fn = elt(env, 1); // pappl0
    v_2431 = (*qfn2(fn))(fn, v_2432, v_2431);
    env = stack[-6];
    goto v_2416;
v_2417:
    goto v_2413;
v_2414:
    goto v_2415;
v_2416:
    v_2431 = cons(stack[0], v_2431);
    env = stack[-6];
    v_2431 = ncons(v_2431);
    env = stack[-6];
    goto v_2405;
v_2406:
    goto v_2402;
v_2403:
    goto v_2404;
v_2405:
    v_2431 = Lrplacd(nil, stack[-1], v_2431);
    env = stack[-6];
    v_2431 = stack[-2];
    v_2431 = qcdr(v_2431);
    stack[-2] = v_2431;
    goto v_2364;
v_2363:
    {
        fn = elt(env, 2); // pv_sort
        return (*qfn1(fn))(fn, v_2431);
    }
}



// Code for !*modular2f

static LispObject CC_Hmodular2f(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2455, v_2456;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2355;
// end of prologue
v_2359:
    goto v_2368;
v_2364:
    v_2456 = stack[0];
    goto v_2365;
v_2366:
    v_2455 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2367;
v_2368:
    goto v_2364;
v_2365:
    goto v_2366;
v_2367:
    if (v_2456 == v_2455) goto v_2362;
    else goto v_2363;
v_2362:
    v_2455 = nil;
    goto v_2358;
v_2363:
    v_2455 = qvalue(elt(env, 1)); // !*balanced_mod
    if (v_2455 == nil) goto v_2373;
    goto v_2384;
v_2380:
    goto v_2390;
v_2386:
    v_2456 = stack[0];
    goto v_2387;
v_2388:
    v_2455 = stack[0];
    goto v_2389;
v_2390:
    goto v_2386;
v_2387:
    goto v_2388;
v_2389:
    v_2456 = plus2(v_2456, v_2455);
    env = stack[-2];
    goto v_2381;
v_2382:
    v_2455 = qvalue(elt(env, 2)); // current!-modulus
    goto v_2383;
v_2384:
    goto v_2380;
v_2381:
    goto v_2382;
v_2383:
    v_2455 = (LispObject)greaterp2(v_2456, v_2455);
    v_2455 = v_2455 ? lisp_true : nil;
    env = stack[-2];
    if (v_2455 == nil) goto v_2378;
    goto v_2399;
v_2395:
    stack[-1] = elt(env, 3); // !:mod!:
    goto v_2396;
v_2397:
    goto v_2406;
v_2402:
    v_2456 = stack[0];
    goto v_2403;
v_2404:
    v_2455 = qvalue(elt(env, 2)); // current!-modulus
    goto v_2405;
v_2406:
    goto v_2402;
v_2403:
    goto v_2404;
v_2405:
    v_2455 = difference2(v_2456, v_2455);
    goto v_2398;
v_2399:
    goto v_2395;
v_2396:
    goto v_2397;
v_2398:
    {
        LispObject v_2459 = stack[-1];
        return cons(v_2459, v_2455);
    }
v_2378:
    goto v_2416;
v_2412:
    goto v_2422;
v_2418:
    v_2456 = stack[0];
    goto v_2419;
v_2420:
    v_2455 = stack[0];
    goto v_2421;
v_2422:
    goto v_2418;
v_2419:
    goto v_2420;
v_2421:
    stack[-1] = plus2(v_2456, v_2455);
    env = stack[-2];
    goto v_2413;
v_2414:
    v_2455 = qvalue(elt(env, 2)); // current!-modulus
    v_2455 = negate(v_2455);
    env = stack[-2];
    goto v_2415;
v_2416:
    goto v_2412;
v_2413:
    goto v_2414;
v_2415:
    v_2455 = (LispObject)lesseq2(stack[-1], v_2455);
    v_2455 = v_2455 ? lisp_true : nil;
    env = stack[-2];
    if (v_2455 == nil) goto v_2410;
    goto v_2432;
v_2428:
    v_2456 = stack[0];
    goto v_2429;
v_2430:
    v_2455 = qvalue(elt(env, 2)); // current!-modulus
    goto v_2431;
v_2432:
    goto v_2428;
v_2429:
    goto v_2430;
v_2431:
    v_2455 = plus2(v_2456, v_2455);
    env = stack[-2];
    stack[0] = v_2455;
    goto v_2359;
v_2410:
    goto v_2442;
v_2438:
    v_2456 = elt(env, 3); // !:mod!:
    goto v_2439;
v_2440:
    v_2455 = stack[0];
    goto v_2441;
v_2442:
    goto v_2438;
v_2439:
    goto v_2440;
v_2441:
    return cons(v_2456, v_2455);
    goto v_2361;
v_2373:
    goto v_2452;
v_2448:
    v_2456 = elt(env, 3); // !:mod!:
    goto v_2449;
v_2450:
    v_2455 = stack[0];
    goto v_2451;
v_2452:
    goto v_2448;
v_2449:
    goto v_2450;
v_2451:
    return cons(v_2456, v_2455);
v_2361:
    v_2455 = nil;
v_2358:
    return onevalue(v_2455);
}



// Code for exptmod!:

static LispObject CC_exptmodT(LispObject env,
                         LispObject v_2355, LispObject v_2356)
{
    env = qenv(env);
    LispObject v_2368, v_2369;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2355,v_2356);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_2368 = v_2356;
    v_2369 = v_2355;
// end of prologue
    goto v_2364;
v_2360:
    v_2369 = qcdr(v_2369);
    goto v_2361;
v_2362:
    goto v_2363;
v_2364:
    goto v_2360;
v_2361:
    goto v_2362;
v_2363:
    fn = elt(env, 1); // general!-modular!-expt
    v_2368 = (*qfn2(fn))(fn, v_2369, v_2368);
    env = stack[0];
    {
        fn = elt(env, 2); // !*modular2f
        return (*qfn1(fn))(fn, v_2368);
    }
}



// Code for lalr_add_goto

static LispObject CC_lalr_add_goto(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2387, v_2388, v_2389;
    LispObject fn;
    LispObject v_2357, v_2356, v_2355;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "lalr_add_goto");
    va_start(aa, nargs);
    v_2355 = va_arg(aa, LispObject);
    v_2356 = va_arg(aa, LispObject);
    v_2357 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_2357,v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_2355,v_2356,v_2357);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_2387 = v_2357;
    v_2388 = v_2356;
    v_2389 = v_2355;
// end of prologue
    goto v_2366;
v_2360:
    stack[-3] = v_2388;
    goto v_2361;
v_2362:
    stack[-2] = qvalue(elt(env, 1)); // goto_table
    goto v_2363;
v_2364:
    goto v_2376;
v_2370:
    stack[-1] = v_2389;
    goto v_2371;
v_2372:
    stack[0] = v_2387;
    goto v_2373;
v_2374:
    goto v_2384;
v_2380:
    goto v_2381;
v_2382:
    v_2387 = qvalue(elt(env, 1)); // goto_table
    goto v_2383;
v_2384:
    goto v_2380;
v_2381:
    goto v_2382;
v_2383:
    fn = elt(env, 2); // gethash
    v_2387 = (*qfn2(fn))(fn, v_2388, v_2387);
    env = stack[-4];
    goto v_2375;
v_2376:
    goto v_2370;
v_2371:
    goto v_2372;
v_2373:
    goto v_2374;
v_2375:
    v_2387 = acons(stack[-1], stack[0], v_2387);
    env = stack[-4];
    goto v_2365;
v_2366:
    goto v_2360;
v_2361:
    goto v_2362;
v_2363:
    goto v_2364;
v_2365:
    {
        LispObject v_2394 = stack[-3];
        LispObject v_2395 = stack[-2];
        fn = elt(env, 3); // puthash
        return (*qfnn(fn))(fn, 3, v_2394, v_2395, v_2387);
    }
}



// Code for gcdf1

static LispObject CC_gcdf1(LispObject env,
                         LispObject v_2355, LispObject v_2356)
{
    env = qenv(env);
    LispObject v_2565, v_2566;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2355,v_2356);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_2356;
    stack[-2] = v_2355;
// end of prologue
    v_2565 = stack[-2];
    if (v_2565 == nil) goto v_2363;
    else goto v_2364;
v_2363:
    v_2565 = stack[-1];
    goto v_2360;
v_2364:
    v_2565 = stack[-1];
    if (v_2565 == nil) goto v_2367;
    else goto v_2368;
v_2367:
    v_2565 = stack[-2];
    goto v_2360;
v_2368:
    goto v_2381;
v_2377:
    v_2566 = stack[-2];
    goto v_2378;
v_2379:
    v_2565 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2380;
v_2381:
    goto v_2377;
v_2378:
    goto v_2379;
v_2380:
    if (v_2566 == v_2565) goto v_2375;
    else goto v_2376;
v_2375:
    v_2565 = lisp_true;
    goto v_2374;
v_2376:
    goto v_2391;
v_2387:
    v_2566 = stack[-1];
    goto v_2388;
v_2389:
    v_2565 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2390;
v_2391:
    goto v_2387;
v_2388:
    goto v_2389;
v_2390:
    v_2565 = (v_2566 == v_2565 ? lisp_true : nil);
    goto v_2374;
    v_2565 = nil;
v_2374:
    if (v_2565 == nil) goto v_2372;
    v_2565 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2360;
v_2372:
    v_2565 = stack[-2];
    if (!consp(v_2565)) goto v_2400;
    else goto v_2401;
v_2400:
    v_2565 = lisp_true;
    goto v_2399;
v_2401:
    v_2565 = stack[-2];
    v_2565 = qcar(v_2565);
    v_2565 = (consp(v_2565) ? nil : lisp_true);
    goto v_2399;
    v_2565 = nil;
v_2399:
    if (v_2565 == nil) goto v_2397;
    goto v_2414;
v_2410:
    v_2566 = stack[-2];
    goto v_2411;
v_2412:
    v_2565 = stack[-1];
    goto v_2413;
v_2414:
    goto v_2410;
v_2411:
    goto v_2412;
v_2413:
    {
        fn = elt(env, 6); // gcdfd
        return (*qfn2(fn))(fn, v_2566, v_2565);
    }
v_2397:
    v_2565 = stack[-1];
    if (!consp(v_2565)) goto v_2421;
    else goto v_2422;
v_2421:
    v_2565 = lisp_true;
    goto v_2420;
v_2422:
    v_2565 = stack[-1];
    v_2565 = qcar(v_2565);
    v_2565 = (consp(v_2565) ? nil : lisp_true);
    goto v_2420;
    v_2565 = nil;
v_2420:
    if (v_2565 == nil) goto v_2418;
    goto v_2435;
v_2431:
    v_2566 = stack[-1];
    goto v_2432;
v_2433:
    v_2565 = stack[-2];
    goto v_2434;
v_2435:
    goto v_2431;
v_2432:
    goto v_2433;
v_2434:
    {
        fn = elt(env, 6); // gcdfd
        return (*qfn2(fn))(fn, v_2566, v_2565);
    }
v_2418:
    v_2565 = qvalue(elt(env, 1)); // !*anygcd
    if (v_2565 == nil) goto v_2442;
    else goto v_2443;
v_2442:
    v_2565 = lisp_true;
    goto v_2441;
v_2443:
    v_2565 = stack[-2];
    fn = elt(env, 7); // num!-exponents
    v_2565 = (*qfn1(fn))(fn, v_2565);
    env = stack[-4];
    if (v_2565 == nil) goto v_2450;
    else goto v_2451;
v_2450:
    v_2565 = lisp_true;
    goto v_2449;
v_2451:
    v_2565 = stack[-1];
    fn = elt(env, 7); // num!-exponents
    v_2565 = (*qfn1(fn))(fn, v_2565);
    env = stack[-4];
    v_2565 = (v_2565 == nil ? lisp_true : nil);
    goto v_2449;
    v_2565 = nil;
v_2449:
    goto v_2441;
    v_2565 = nil;
v_2441:
    if (v_2565 == nil) goto v_2439;
    v_2565 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2360;
v_2439:
    goto v_2468;
v_2464:
    v_2566 = stack[-2];
    goto v_2465;
v_2466:
    v_2565 = stack[-1];
    goto v_2467;
v_2468:
    goto v_2464;
v_2465:
    goto v_2466;
v_2467:
    fn = elt(env, 8); // quotf1
    v_2565 = (*qfn2(fn))(fn, v_2566, v_2565);
    env = stack[-4];
    if (v_2565 == nil) goto v_2462;
    v_2565 = stack[-1];
    goto v_2360;
v_2462:
    goto v_2479;
v_2475:
    v_2566 = stack[-1];
    goto v_2476;
v_2477:
    v_2565 = stack[-2];
    goto v_2478;
v_2479:
    goto v_2475;
v_2476:
    goto v_2477;
v_2478:
    fn = elt(env, 8); // quotf1
    v_2565 = (*qfn2(fn))(fn, v_2566, v_2565);
    env = stack[-4];
    if (v_2565 == nil) goto v_2473;
    v_2565 = stack[-2];
    goto v_2360;
v_2473:
    goto v_2488;
v_2484:
    v_2566 = stack[-2];
    goto v_2485;
v_2486:
    v_2565 = stack[-1];
    goto v_2487;
v_2488:
    goto v_2484;
v_2485:
    goto v_2486;
v_2487:
    fn = elt(env, 9); // gcdf2
    v_2565 = (*qfn2(fn))(fn, v_2566, v_2565);
    env = stack[-4];
    stack[-3] = v_2565;
    v_2565 = qvalue(elt(env, 2)); // !*gcd
    if (v_2565 == nil) goto v_2494;
    goto v_2506;
v_2502:
    v_2566 = qvalue(elt(env, 3)); // dmode!*
    goto v_2503;
v_2504:
    v_2565 = elt(env, 4); // (!:rd!: !:cr!:)
    goto v_2505;
v_2506:
    goto v_2502;
v_2503:
    goto v_2504;
v_2505:
    v_2565 = Lmemq(nil, v_2566, v_2565);
    if (v_2565 == nil) goto v_2500;
    else goto v_2501;
v_2500:
    goto v_2519;
v_2515:
    v_2566 = stack[-2];
    goto v_2516;
v_2517:
    v_2565 = stack[-3];
    goto v_2518;
v_2519:
    goto v_2515;
v_2516:
    goto v_2517;
v_2518:
    fn = elt(env, 8); // quotf1
    v_2565 = (*qfn2(fn))(fn, v_2566, v_2565);
    env = stack[-4];
    if (v_2565 == nil) goto v_2512;
    else goto v_2513;
v_2512:
    v_2565 = lisp_true;
    goto v_2511;
v_2513:
    goto v_2530;
v_2526:
    v_2566 = stack[-1];
    goto v_2527;
v_2528:
    v_2565 = stack[-3];
    goto v_2529;
v_2530:
    goto v_2526;
v_2527:
    goto v_2528;
v_2529:
    fn = elt(env, 8); // quotf1
    v_2565 = (*qfn2(fn))(fn, v_2566, v_2565);
    env = stack[-4];
    v_2565 = (v_2565 == nil ? lisp_true : nil);
    goto v_2511;
    v_2565 = nil;
v_2511:
    goto v_2499;
v_2501:
    v_2565 = nil;
    goto v_2499;
    v_2565 = nil;
v_2499:
    if (v_2565 == nil) goto v_2494;
    v_2565 = stack[-2];
    fn = elt(env, 10); // noncomfp
    v_2565 = (*qfn1(fn))(fn, v_2565);
    env = stack[-4];
    if (v_2565 == nil) goto v_2541;
    else goto v_2539;
v_2541:
    v_2565 = stack[-1];
    fn = elt(env, 10); // noncomfp
    v_2565 = (*qfn1(fn))(fn, v_2565);
    env = stack[-4];
    if (v_2565 == nil) goto v_2544;
    else goto v_2539;
v_2544:
    goto v_2540;
v_2539:
    v_2565 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2360;
v_2540:
    goto v_2558;
v_2552:
    stack[0] = elt(env, 5); // "gcdf failed"
    goto v_2553;
v_2554:
    v_2565 = stack[-2];
    fn = elt(env, 11); // prepf
    stack[-2] = (*qfn1(fn))(fn, v_2565);
    env = stack[-4];
    goto v_2555;
v_2556:
    v_2565 = stack[-1];
    fn = elt(env, 11); // prepf
    v_2565 = (*qfn1(fn))(fn, v_2565);
    env = stack[-4];
    goto v_2557;
v_2558:
    goto v_2552;
v_2553:
    goto v_2554;
v_2555:
    goto v_2556;
v_2557:
    v_2565 = list3(stack[0], stack[-2], v_2565);
    env = stack[-4];
    fn = elt(env, 12); // errach
    v_2565 = (*qfn1(fn))(fn, v_2565);
    goto v_2538;
v_2538:
    goto v_2492;
v_2494:
v_2492:
    v_2565 = stack[-3];
v_2360:
    return onevalue(v_2565);
}



// Code for talp_smupdknowl

static LispObject CC_talp_smupdknowl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2418, v_2419, v_2420, v_2421;
    LispObject fn;
    LispObject v_2358, v_2357, v_2356, v_2355;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "talp_smupdknowl");
    va_start(aa, nargs);
    v_2355 = va_arg(aa, LispObject);
    v_2356 = va_arg(aa, LispObject);
    v_2357 = va_arg(aa, LispObject);
    v_2358 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_2358,v_2357,v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_2355,v_2356,v_2357,v_2358);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_2358;
    v_2418 = v_2357;
    stack[-1] = v_2356;
    stack[-2] = v_2355;
// end of prologue
    stack[-3] = nil;
v_2365:
    v_2419 = stack[-1];
    if (v_2419 == nil) goto v_2368;
    else goto v_2369;
v_2368:
    goto v_2364;
v_2369:
    v_2419 = stack[-1];
    v_2419 = qcar(v_2419);
    stack[-3] = v_2419;
    v_2419 = stack[-1];
    v_2419 = qcdr(v_2419);
    stack[-1] = v_2419;
    goto v_2385;
v_2377:
    v_2421 = stack[-2];
    goto v_2378;
v_2379:
    v_2420 = stack[-3];
    goto v_2380;
v_2381:
    v_2419 = v_2418;
    goto v_2382;
v_2383:
    v_2418 = stack[0];
    goto v_2384;
v_2385:
    goto v_2377;
v_2378:
    goto v_2379;
v_2380:
    goto v_2381;
v_2382:
    goto v_2383;
v_2384:
    fn = elt(env, 3); // talp_smupdknowl1
    v_2418 = (*qfnn(fn))(fn, 4, v_2421, v_2420, v_2419, v_2418);
    env = stack[-4];
    goto v_2398;
v_2394:
    v_2420 = v_2418;
    goto v_2395;
v_2396:
    v_2419 = elt(env, 1); // false
    goto v_2397;
v_2398:
    goto v_2394;
v_2395:
    goto v_2396;
v_2397:
    if (v_2420 == v_2419) goto v_2392;
    else goto v_2393;
v_2392:
    v_2419 = nil;
    stack[-1] = v_2419;
    v_2419 = elt(env, 2); // break
    stack[-3] = v_2419;
    goto v_2391;
v_2393:
v_2391:
    goto v_2365;
v_2364:
    goto v_2411;
v_2407:
    v_2420 = stack[-3];
    goto v_2408;
v_2409:
    v_2419 = elt(env, 2); // break
    goto v_2410;
v_2411:
    goto v_2407;
v_2408:
    goto v_2409;
v_2410:
    if (v_2420 == v_2419) goto v_2405;
    else goto v_2406;
v_2405:
    v_2418 = elt(env, 1); // false
    goto v_2362;
v_2406:
    goto v_2362;
    v_2418 = nil;
v_2362:
    return onevalue(v_2418);
}



// Code for kernord

static LispObject CC_kernord(LispObject env,
                         LispObject v_2355, LispObject v_2356)
{
    env = qenv(env);
    LispObject v_2378, v_2379;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2355,v_2356);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_2378 = v_2356;
    stack[0] = v_2355;
// end of prologue
    goto v_2363;
v_2359:
    v_2379 = stack[0];
    goto v_2360;
v_2361:
    goto v_2362;
v_2363:
    goto v_2359;
v_2360:
    goto v_2361;
v_2362:
    fn = elt(env, 1); // kernord!-split
    v_2378 = (*qfn2(fn))(fn, v_2379, v_2378);
    env = stack[-2];
    stack[0] = v_2378;
    goto v_2371;
v_2367:
    v_2378 = stack[0];
    v_2378 = qcar(v_2378);
    fn = elt(env, 2); // kernord!-sort
    stack[-1] = (*qfn1(fn))(fn, v_2378);
    env = stack[-2];
    goto v_2368;
v_2369:
    v_2378 = stack[0];
    v_2378 = qcdr(v_2378);
    fn = elt(env, 2); // kernord!-sort
    v_2378 = (*qfn1(fn))(fn, v_2378);
    goto v_2370;
v_2371:
    goto v_2367;
v_2368:
    goto v_2369;
v_2370:
    {
        LispObject v_2382 = stack[-1];
        return Lappend(nil, v_2382, v_2378);
    }
}



// Code for powers2

static LispObject CC_powers2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2422, v_2423, v_2424;
    LispObject fn;
    LispObject v_2357, v_2356, v_2355;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "powers2");
    va_start(aa, nargs);
    v_2355 = va_arg(aa, LispObject);
    v_2356 = va_arg(aa, LispObject);
    v_2357 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_2357,v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_2355,v_2356,v_2357);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_2357;
    stack[-1] = v_2356;
    stack[-2] = v_2355;
// end of prologue
v_2362:
    v_2422 = stack[-2];
    if (!consp(v_2422)) goto v_2369;
    else goto v_2370;
v_2369:
    v_2422 = lisp_true;
    goto v_2368;
v_2370:
    v_2422 = stack[-2];
    v_2422 = qcar(v_2422);
    v_2422 = (consp(v_2422) ? nil : lisp_true);
    goto v_2368;
    v_2422 = nil;
v_2368:
    if (v_2422 == nil) goto v_2366;
    v_2422 = stack[-2];
    if (v_2422 == nil) goto v_2380;
    else goto v_2381;
v_2380:
    v_2422 = stack[-1];
    goto v_2361;
v_2381:
    goto v_2391;
v_2387:
    v_2423 = stack[0];
    goto v_2388;
v_2389:
    v_2422 = stack[-1];
    goto v_2390;
v_2391:
    goto v_2387;
v_2388:
    goto v_2389;
v_2390:
    {
        fn = elt(env, 1); // powers4
        return (*qfn2(fn))(fn, v_2423, v_2422);
    }
    goto v_2364;
v_2366:
    v_2422 = stack[-2];
    v_2422 = qcar(v_2422);
    v_2422 = qcdr(v_2422);
    stack[-3] = v_2422;
    goto v_2406;
v_2400:
    v_2422 = stack[-2];
    v_2424 = qcdr(v_2422);
    goto v_2401;
v_2402:
    v_2423 = stack[-1];
    goto v_2403;
v_2404:
    v_2422 = stack[0];
    goto v_2405;
v_2406:
    goto v_2400;
v_2401:
    goto v_2402;
v_2403:
    goto v_2404;
v_2405:
    v_2422 = CC_powers2(elt(env, 0), 3, v_2424, v_2423, v_2422);
    env = stack[-4];
    stack[-1] = v_2422;
    goto v_2416;
v_2412:
    v_2422 = stack[-2];
    v_2422 = qcar(v_2422);
    v_2423 = qcar(v_2422);
    goto v_2413;
v_2414:
    v_2422 = stack[0];
    goto v_2415;
v_2416:
    goto v_2412;
v_2413:
    goto v_2414;
v_2415:
    v_2422 = cons(v_2423, v_2422);
    env = stack[-4];
    stack[0] = v_2422;
    v_2422 = stack[-3];
    stack[-2] = v_2422;
    goto v_2362;
v_2364:
    v_2422 = nil;
v_2361:
    return onevalue(v_2422);
}



// Code for simp!*

static LispObject CC_simpH(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2499, v_2500;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_2355;
// end of prologue
// Binding !*asymp!*
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = nil; // !*asymp!*
    goto v_2374;
v_2370:
    v_2500 = stack[-2];
    goto v_2371;
v_2372:
    v_2499 = elt(env, 2); // !*sq
    goto v_2373;
v_2374:
    goto v_2370;
v_2371:
    goto v_2372;
v_2373:
    if (!consp(v_2500)) goto v_2368;
    v_2500 = qcar(v_2500);
    if (v_2500 == v_2499) goto v_2367;
    else goto v_2368;
v_2367:
    v_2499 = stack[-2];
    v_2499 = qcdr(v_2499);
    v_2499 = qcdr(v_2499);
    v_2499 = qcar(v_2499);
    if (v_2499 == nil) goto v_2379;
    else goto v_2380;
v_2379:
    v_2499 = nil;
    goto v_2378;
v_2380:
    v_2499 = qvalue(elt(env, 3)); // !*resimp
    v_2499 = (v_2499 == nil ? lisp_true : nil);
    goto v_2378;
    v_2499 = nil;
v_2378:
    goto v_2366;
v_2368:
    v_2499 = nil;
    goto v_2366;
    v_2499 = nil;
v_2366:
    if (v_2499 == nil) goto v_2364;
    v_2499 = stack[-2];
    v_2499 = qcdr(v_2499);
    v_2499 = qcar(v_2499);
    goto v_2360;
v_2364:
    goto v_2401;
v_2397:
    v_2500 = qvalue(elt(env, 4)); // mul!*
    goto v_2398;
v_2399:
    v_2499 = qvalue(elt(env, 5)); // !*sub2
    goto v_2400;
v_2401:
    goto v_2397;
v_2398:
    goto v_2399;
v_2400:
    v_2499 = cons(v_2500, v_2499);
    env = stack[-4];
    stack[-1] = v_2499;
    v_2499 = nil;
    qvalue(elt(env, 4)) = v_2499; // mul!*
    v_2499 = stack[-2];
    fn = elt(env, 13); // simp
    v_2499 = (*qfn1(fn))(fn, v_2499);
    env = stack[-4];
    stack[-2] = v_2499;
    v_2499 = qvalue(elt(env, 6)); // !*nospurp
    if (v_2499 == nil) goto v_2410;
    goto v_2417;
v_2413:
    v_2500 = qvalue(elt(env, 4)); // mul!*
    goto v_2414;
v_2415:
    v_2499 = elt(env, 7); // (isimpq)
    goto v_2416;
v_2417:
    goto v_2413;
v_2414:
    goto v_2415;
v_2416:
    fn = elt(env, 14); // union
    v_2499 = (*qfn2(fn))(fn, v_2500, v_2499);
    env = stack[-4];
    qvalue(elt(env, 4)) = v_2499; // mul!*
    goto v_2408;
v_2410:
v_2408:
    v_2499 = qvalue(elt(env, 4)); // mul!*
    stack[0] = v_2499;
v_2423:
    v_2499 = stack[0];
    if (v_2499 == nil) goto v_2427;
    else goto v_2428;
v_2427:
    goto v_2422;
v_2428:
    v_2499 = stack[0];
    v_2499 = qcar(v_2499);
    goto v_2439;
v_2435:
    v_2500 = v_2499;
    goto v_2436;
v_2437:
    v_2499 = stack[-2];
    goto v_2438;
v_2439:
    goto v_2435;
v_2436:
    goto v_2437;
v_2438:
    v_2499 = Lapply1(nil, v_2500, v_2499);
    env = stack[-4];
    stack[-2] = v_2499;
    v_2499 = stack[0];
    v_2499 = qcdr(v_2499);
    stack[0] = v_2499;
    goto v_2423;
v_2422:
    v_2499 = stack[-1];
    v_2499 = qcar(v_2499);
    qvalue(elt(env, 4)) = v_2499; // mul!*
    v_2499 = stack[-2];
    fn = elt(env, 15); // subs2
    v_2499 = (*qfn1(fn))(fn, v_2499);
    env = stack[-4];
    stack[-2] = v_2499;
    v_2499 = qvalue(elt(env, 8)); // !*combinelogs
    if (v_2499 == nil) goto v_2451;
    v_2499 = stack[-2];
    fn = elt(env, 16); // clogsq!*
    v_2499 = (*qfn1(fn))(fn, v_2499);
    env = stack[-4];
    stack[-2] = v_2499;
    goto v_2449;
v_2451:
v_2449:
    goto v_2467;
v_2463:
    v_2500 = qvalue(elt(env, 9)); // dmode!*
    goto v_2464;
v_2465:
    v_2499 = elt(env, 10); // !:gi!:
    goto v_2466;
v_2467:
    goto v_2463;
v_2464:
    goto v_2465;
v_2466:
    if (v_2500 == v_2499) goto v_2461;
    else goto v_2462;
v_2461:
    v_2499 = qvalue(elt(env, 11)); // !*norationalgi
    v_2499 = (v_2499 == nil ? lisp_true : nil);
    goto v_2460;
v_2462:
    v_2499 = nil;
    goto v_2460;
    v_2499 = nil;
v_2460:
    if (v_2499 == nil) goto v_2458;
    v_2499 = stack[-2];
    fn = elt(env, 17); // girationalize!:
    v_2499 = (*qfn1(fn))(fn, v_2499);
    env = stack[-4];
    stack[-2] = v_2499;
    goto v_2456;
v_2458:
    v_2499 = qvalue(elt(env, 12)); // !*rationalize
    if (v_2499 == nil) goto v_2478;
    v_2499 = stack[-2];
    fn = elt(env, 18); // rationalizesq
    v_2499 = (*qfn1(fn))(fn, v_2499);
    env = stack[-4];
    stack[-2] = v_2499;
    goto v_2456;
v_2478:
    v_2499 = stack[-2];
    fn = elt(env, 19); // rationalizei
    v_2499 = (*qfn1(fn))(fn, v_2499);
    env = stack[-4];
    stack[-2] = v_2499;
    goto v_2456;
v_2456:
    v_2499 = stack[-1];
    v_2499 = qcdr(v_2499);
    qvalue(elt(env, 5)) = v_2499; // !*sub2
    v_2499 = qvalue(elt(env, 1)); // !*asymp!*
    if (v_2499 == nil) goto v_2491;
    v_2499 = qvalue(elt(env, 12)); // !*rationalize
    if (v_2499 == nil) goto v_2491;
    v_2499 = stack[-2];
    fn = elt(env, 20); // gcdchk
    v_2499 = (*qfn1(fn))(fn, v_2499);
    stack[-2] = v_2499;
    goto v_2489;
v_2491:
v_2489:
    v_2499 = stack[-2];
v_2360:
    ;}  // end of a binding scope
    return onevalue(v_2499);
}



// Code for downwght

static LispObject CC_downwght(LispObject env,
                         LispObject v_2355, LispObject v_2356)
{
    env = qenv(env);
    LispObject v_2370, v_2371;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2355,v_2356);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2356;
    stack[-1] = v_2355;
// end of prologue
    v_2370 = stack[-1];
    fn = elt(env, 1); // delhisto
    v_2370 = (*qfn1(fn))(fn, v_2370);
    env = stack[-2];
    goto v_2365;
v_2361:
    v_2371 = stack[-1];
    goto v_2362;
v_2363:
    v_2370 = stack[0];
    goto v_2364;
v_2365:
    goto v_2361;
v_2362:
    goto v_2363;
v_2364:
    fn = elt(env, 2); // downwght1
    v_2370 = (*qfn2(fn))(fn, v_2371, v_2370);
    env = stack[-2];
    v_2370 = stack[-1];
    {
        fn = elt(env, 3); // inshisto
        return (*qfn1(fn))(fn, v_2370);
    }
}



// Code for termordp

static LispObject CC_termordp(LispObject env,
                         LispObject v_2355, LispObject v_2356)
{
    env = qenv(env);
    LispObject v_2368;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2355,v_2356);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2356;
    v_2368 = v_2355;
// end of prologue
    goto v_2363;
v_2359:
    fn = elt(env, 1); // wedgefax
    stack[-1] = (*qfn1(fn))(fn, v_2368);
    env = stack[-2];
    goto v_2360;
v_2361:
    v_2368 = stack[0];
    fn = elt(env, 1); // wedgefax
    v_2368 = (*qfn1(fn))(fn, v_2368);
    env = stack[-2];
    goto v_2362;
v_2363:
    goto v_2359;
v_2360:
    goto v_2361;
v_2362:
    {
        LispObject v_2371 = stack[-1];
        fn = elt(env, 2); // monordp
        return (*qfn2(fn))(fn, v_2371, v_2368);
    }
}



// Code for make!-set

static LispObject CC_makeKset(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2366, v_2367;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_2366 = v_2355;
// end of prologue
    goto v_2363;
v_2359:
    v_2367 = v_2366;
    goto v_2360;
v_2361:
    v_2366 = elt(env, 1); // set!-ordp
    goto v_2362;
v_2363:
    goto v_2359;
v_2360:
    goto v_2361;
v_2362:
    fn = elt(env, 2); // sort
    v_2366 = (*qfn2(fn))(fn, v_2367, v_2366);
    env = stack[0];
    {
        fn = elt(env, 3); // makelist
        return (*qfn1(fn))(fn, v_2366);
    }
}



// Code for !:plus

static LispObject CC_Tplus(LispObject env,
                         LispObject v_2355, LispObject v_2356)
{
    env = qenv(env);
    LispObject v_2417, v_2418, v_2419;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2355,v_2356);
    }
// copy arguments values to proper place
    v_2418 = v_2356;
    v_2419 = v_2355;
// end of prologue
    v_2417 = v_2419;
    if (v_2417 == nil) goto v_2360;
    else goto v_2361;
v_2360:
    v_2417 = v_2418;
    goto v_2359;
v_2361:
    v_2417 = v_2418;
    if (v_2417 == nil) goto v_2364;
    else goto v_2365;
v_2364:
    v_2417 = v_2419;
    goto v_2359;
v_2365:
    v_2417 = v_2419;
    if (!consp(v_2417)) goto v_2372;
    else goto v_2373;
v_2372:
    v_2417 = v_2418;
    v_2417 = (consp(v_2417) ? nil : lisp_true);
    goto v_2371;
v_2373:
    v_2417 = nil;
    goto v_2371;
    v_2417 = nil;
v_2371:
    if (v_2417 == nil) goto v_2369;
    goto v_2385;
v_2381:
    v_2417 = v_2419;
    goto v_2382;
v_2383:
    goto v_2384;
v_2385:
    goto v_2381;
v_2382:
    goto v_2383;
v_2384:
    v_2417 = plus2(v_2417, v_2418);
    v_2419 = v_2417;
    goto v_2397;
v_2393:
    v_2418 = v_2419;
    goto v_2394;
v_2395:
    v_2417 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2396;
v_2397:
    goto v_2393;
v_2394:
    goto v_2395;
v_2396:
    if (v_2418 == v_2417) goto v_2391;
    else goto v_2392;
v_2391:
    v_2417 = nil;
    goto v_2390;
v_2392:
    v_2417 = v_2419;
    goto v_2390;
    v_2417 = nil;
v_2390:
    goto v_2359;
v_2369:
    goto v_2413;
v_2407:
    goto v_2408;
v_2409:
    goto v_2410;
v_2411:
    v_2417 = elt(env, 1); // plus
    goto v_2412;
v_2413:
    goto v_2407;
v_2408:
    goto v_2409;
v_2410:
    goto v_2411;
v_2412:
    {
        fn = elt(env, 2); // dcombine
        return (*qfnn(fn))(fn, 3, v_2419, v_2418, v_2417);
    }
    v_2417 = nil;
v_2359:
    return onevalue(v_2417);
}



// Code for optype

static LispObject CC_optype(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2365, v_2366;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2365 = v_2355;
// end of prologue
    goto v_2362;
v_2358:
    goto v_2359;
v_2360:
    v_2366 = elt(env, 1); // !*optype!*
    goto v_2361;
v_2362:
    goto v_2358;
v_2359:
    goto v_2360;
v_2361:
    return get(v_2365, v_2366);
}



// Code for macrochk

static LispObject CC_macrochk(LispObject env,
                         LispObject v_2355, LispObject v_2356)
{
    env = qenv(env);
    LispObject v_2428, v_2429, v_2430, v_2431;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2355,v_2356);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2356;
    stack[-1] = v_2355;
// end of prologue
    v_2428 = stack[-1];
    if (!consp(v_2428)) goto v_2363;
    else goto v_2364;
v_2363:
    v_2428 = stack[-1];
    goto v_2360;
v_2364:
    v_2428 = stack[-1];
    v_2428 = qcar(v_2428);
    fn = elt(env, 3); // expdrmacro
    v_2428 = (*qfn1(fn))(fn, v_2428);
    env = stack[-2];
    v_2429 = v_2428;
    if (v_2428 == nil) goto v_2368;
    goto v_2382;
v_2378:
    v_2430 = stack[0];
    goto v_2379;
v_2380:
    v_2428 = elt(env, 1); // symbolic
    goto v_2381;
v_2382:
    goto v_2378;
v_2379:
    goto v_2380;
v_2381:
    if (v_2430 == v_2428) goto v_2376;
    else goto v_2377;
v_2376:
    v_2428 = lisp_true;
    goto v_2375;
v_2377:
    v_2428 = stack[-1];
    v_2428 = qcar(v_2428);
    if (symbolp(v_2428)) goto v_2391;
    v_2428 = nil;
    goto v_2389;
v_2391:
    v_2428 = stack[-1];
    v_2428 = qcar(v_2428);
    if (!symbolp(v_2428)) v_2428 = nil;
    else { v_2428 = qfastgets(v_2428);
           if (v_2428 != nil) { v_2428 = elt(v_2428, 59); // opfn
#ifdef RECORD_GET
             if (v_2428 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v_2428 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v_2428 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v_2428 == SPID_NOPROP) v_2428 = nil; else v_2428 = lisp_true; }}
#endif
    goto v_2389;
    v_2428 = nil;
v_2389:
    goto v_2375;
    v_2428 = nil;
v_2375:
    if (v_2428 == nil) goto v_2368;
    goto v_2409;
v_2401:
    goto v_2415;
v_2411:
    v_2428 = v_2429;
    v_2430 = qcar(v_2428);
    goto v_2412;
v_2413:
    v_2428 = elt(env, 2); // macrofn
    goto v_2414;
v_2415:
    goto v_2411;
v_2412:
    goto v_2413;
v_2414:
    v_2431 = get(v_2430, v_2428);
    goto v_2402;
v_2403:
    v_2428 = v_2429;
    v_2430 = qcdr(v_2428);
    goto v_2404;
v_2405:
    v_2428 = stack[-1];
    v_2429 = qcdr(v_2428);
    goto v_2406;
v_2407:
    v_2428 = stack[-1];
    v_2428 = qcar(v_2428);
    goto v_2408;
v_2409:
    goto v_2401;
v_2402:
    goto v_2403;
v_2404:
    goto v_2405;
v_2406:
    goto v_2407;
v_2408:
        return Lapply3(nil, 4, v_2431, v_2430, v_2429, v_2428);
v_2368:
    v_2428 = stack[-1];
    goto v_2360;
    v_2428 = nil;
v_2360:
    return onevalue(v_2428);
}



// Code for groeb!=testa

static LispObject CC_groebMtesta(LispObject env,
                         LispObject v_2355, LispObject v_2356)
{
    env = qenv(env);
    LispObject v_2380, v_2381;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2355,v_2356);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2356;
    v_2380 = v_2355;
// end of prologue
    goto v_2363;
v_2359:
    goto v_2369;
v_2365:
    v_2381 = v_2380;
    goto v_2366;
v_2367:
    v_2380 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_2368;
v_2369:
    goto v_2365;
v_2366:
    goto v_2367;
v_2368:
    fn = elt(env, 1); // nth
    stack[-1] = (*qfn2(fn))(fn, v_2381, v_2380);
    env = stack[-2];
    goto v_2360;
v_2361:
    goto v_2377;
v_2373:
    v_2381 = stack[0];
    goto v_2374;
v_2375:
    v_2380 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_2376;
v_2377:
    goto v_2373;
v_2374:
    goto v_2375;
v_2376:
    fn = elt(env, 1); // nth
    v_2380 = (*qfn2(fn))(fn, v_2381, v_2380);
    env = stack[-2];
    goto v_2362;
v_2363:
    goto v_2359;
v_2360:
    goto v_2361;
v_2362:
    {
        LispObject v_2384 = stack[-1];
        fn = elt(env, 2); // mo_divides!?
        return (*qfn2(fn))(fn, v_2384, v_2380);
    }
}



// Code for gperm2

static LispObject CC_gperm2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2396, v_2397, v_2398, v_2399;
    LispObject fn;
    LispObject v_2357, v_2356, v_2355;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "gperm2");
    va_start(aa, nargs);
    v_2355 = va_arg(aa, LispObject);
    v_2356 = va_arg(aa, LispObject);
    v_2357 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_2357,v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_2355,v_2356,v_2357);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_2357;
    stack[-1] = v_2356;
    v_2396 = v_2355;
// end of prologue
v_2362:
    v_2397 = v_2396;
    if (v_2397 == nil) goto v_2365;
    else goto v_2366;
v_2365:
    v_2396 = stack[0];
    goto v_2361;
v_2366:
    v_2397 = v_2396;
    v_2397 = qcdr(v_2397);
    stack[-2] = v_2397;
    goto v_2382;
v_2374:
    goto v_2388;
v_2384:
    v_2397 = qcar(v_2396);
    goto v_2385;
v_2386:
    v_2396 = nil;
    goto v_2387;
v_2388:
    goto v_2384;
v_2385:
    goto v_2386;
v_2387:
    fn = elt(env, 1); // rev
    v_2399 = (*qfn2(fn))(fn, v_2397, v_2396);
    env = stack[-3];
    goto v_2375;
v_2376:
    v_2398 = stack[-1];
    goto v_2377;
v_2378:
    v_2397 = nil;
    goto v_2379;
v_2380:
    v_2396 = stack[0];
    goto v_2381;
v_2382:
    goto v_2374;
v_2375:
    goto v_2376;
v_2377:
    goto v_2378;
v_2379:
    goto v_2380;
v_2381:
    fn = elt(env, 2); // gperm1
    v_2396 = (*qfnn(fn))(fn, 4, v_2399, v_2398, v_2397, v_2396);
    env = stack[-3];
    stack[0] = v_2396;
    v_2396 = stack[-2];
    goto v_2362;
    v_2396 = nil;
v_2361:
    return onevalue(v_2396);
}



// Code for !*i2ar

static LispObject CC_Hi2ar(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2365, v_2366;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2365 = v_2355;
// end of prologue
    goto v_2362;
v_2358:
    v_2366 = elt(env, 1); // !:ar!:
    goto v_2359;
v_2360:
    goto v_2361;
v_2362:
    goto v_2358;
v_2359:
    goto v_2360;
v_2361:
    return cons(v_2366, v_2365);
}



// Code for general!-modular!-minus

static LispObject CC_generalKmodularKminus(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2379, v_2380, v_2381;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2381 = v_2355;
// end of prologue
    goto v_2365;
v_2361:
    v_2380 = v_2381;
    goto v_2362;
v_2363:
    v_2379 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2364;
v_2365:
    goto v_2361;
v_2362:
    goto v_2363;
v_2364:
    if (v_2380 == v_2379) goto v_2359;
    else goto v_2360;
v_2359:
    v_2379 = v_2381;
    goto v_2358;
v_2360:
    goto v_2376;
v_2372:
    v_2379 = qvalue(elt(env, 1)); // current!-modulus
    goto v_2373;
v_2374:
    v_2380 = v_2381;
    goto v_2375;
v_2376:
    goto v_2372;
v_2373:
    goto v_2374;
v_2375:
    return difference2(v_2379, v_2380);
    v_2379 = nil;
v_2358:
    return onevalue(v_2379);
}



// Code for convprec!*

static LispObject CC_convprecH(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2374, v_2375;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_2374 = v_2355;
// end of prologue
    v_2375 = v_2374;
    if (!consp(v_2375)) goto v_2360;
    else goto v_2361;
v_2360:
    goto v_2359;
v_2361:
    goto v_2371;
v_2367:
    v_2375 = elt(env, 1); // !:rd!:
    goto v_2368;
v_2369:
    goto v_2370;
v_2371:
    goto v_2367;
v_2368:
    goto v_2369;
v_2370:
    v_2374 = cons(v_2375, v_2374);
    env = stack[0];
    goto v_2359;
    v_2374 = nil;
v_2359:
    {
        fn = elt(env, 2); // convchk
        return (*qfn1(fn))(fn, v_2374);
    }
}



// Code for lalr_remove_duplicates

static LispObject CC_lalr_remove_duplicates(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2398, v_2399, v_2400, v_2401;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_2398 = v_2355;
// end of prologue
    v_2401 = nil;
    stack[0] = v_2398;
v_2363:
    v_2398 = stack[0];
    if (v_2398 == nil) goto v_2367;
    else goto v_2368;
v_2367:
    goto v_2362;
v_2368:
    v_2398 = stack[0];
    v_2398 = qcar(v_2398);
    v_2400 = v_2398;
    goto v_2382;
v_2378:
    v_2399 = v_2400;
    goto v_2379;
v_2380:
    v_2398 = v_2401;
    goto v_2381;
v_2382:
    goto v_2378;
v_2379:
    goto v_2380;
v_2381:
    v_2398 = Lmember(nil, v_2399, v_2398);
    if (v_2398 == nil) goto v_2376;
    else goto v_2377;
v_2376:
    goto v_2391;
v_2387:
    v_2398 = v_2400;
    goto v_2388;
v_2389:
    v_2399 = v_2401;
    goto v_2390;
v_2391:
    goto v_2387;
v_2388:
    goto v_2389;
v_2390:
    v_2398 = cons(v_2398, v_2399);
    env = stack[-1];
    v_2401 = v_2398;
    goto v_2375;
v_2377:
v_2375:
    v_2398 = stack[0];
    v_2398 = qcdr(v_2398);
    stack[0] = v_2398;
    goto v_2363;
v_2362:
    v_2398 = v_2401;
        return Lnreverse(nil, v_2398);
    return onevalue(v_2398);
}



// Code for sgn

static LispObject CC_sgn(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2384, v_2385;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2355;
// end of prologue
    goto v_2366;
v_2362:
    v_2385 = stack[0];
    goto v_2363;
v_2364:
    v_2384 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2365;
v_2366:
    goto v_2362;
v_2363:
    goto v_2364;
v_2365:
    v_2384 = (LispObject)greaterp2(v_2385, v_2384);
    v_2384 = v_2384 ? lisp_true : nil;
    env = stack[-1];
    if (v_2384 == nil) goto v_2360;
    v_2384 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2358;
v_2360:
    goto v_2377;
v_2373:
    v_2385 = stack[0];
    goto v_2374;
v_2375:
    v_2384 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2376;
v_2377:
    goto v_2373;
v_2374:
    goto v_2375;
v_2376:
    v_2384 = (LispObject)lessp2(v_2385, v_2384);
    v_2384 = v_2384 ? lisp_true : nil;
    if (v_2384 == nil) goto v_2371;
    v_2384 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_2358;
v_2371:
    v_2384 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2358;
    v_2384 = nil;
v_2358:
    return onevalue(v_2384);
}



// Code for sfto_gcdf

static LispObject CC_sfto_gcdf(LispObject env,
                         LispObject v_2355, LispObject v_2356)
{
    env = qenv(env);
    LispObject v_2411, v_2412;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2355,v_2356);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_2356;
    stack[-1] = v_2355;
// end of prologue
    v_2411 = qvalue(elt(env, 1)); // !*rldavgcd
    if (v_2411 == nil) goto v_2360;
    else goto v_2361;
v_2360:
    goto v_2368;
v_2364:
    v_2412 = stack[-1];
    goto v_2365;
v_2366:
    v_2411 = stack[0];
    goto v_2367;
v_2368:
    goto v_2364;
v_2365:
    goto v_2366;
v_2367:
    {
        fn = elt(env, 3); // gcdf
        return (*qfn2(fn))(fn, v_2412, v_2411);
    }
v_2361:
    goto v_2379;
v_2375:
    v_2412 = stack[-1];
    goto v_2376;
v_2377:
    v_2411 = nil;
    goto v_2378;
v_2379:
    goto v_2375;
v_2376:
    goto v_2377;
v_2378:
    fn = elt(env, 4); // sfto_davp
    v_2411 = (*qfn2(fn))(fn, v_2412, v_2411);
    env = stack[-3];
    if (v_2411 == nil) goto v_2373;
    else goto v_2371;
v_2373:
    goto v_2388;
v_2384:
    v_2412 = stack[0];
    goto v_2385;
v_2386:
    v_2411 = nil;
    goto v_2387;
v_2388:
    goto v_2384;
v_2385:
    goto v_2386;
v_2387:
    fn = elt(env, 4); // sfto_davp
    v_2411 = (*qfn2(fn))(fn, v_2412, v_2411);
    env = stack[-3];
    if (v_2411 == nil) goto v_2382;
    else goto v_2371;
v_2382:
    goto v_2372;
v_2371:
    v_2411 = nil;
// Binding !*ezgcd
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 2, -2);
    qvalue(elt(env, 2)) = v_2411; // !*ezgcd
    goto v_2398;
v_2394:
    v_2412 = stack[-1];
    goto v_2395;
v_2396:
    v_2411 = stack[0];
    goto v_2397;
v_2398:
    goto v_2394;
v_2395:
    goto v_2396;
v_2397:
    fn = elt(env, 3); // gcdf
    v_2411 = (*qfn2(fn))(fn, v_2412, v_2411);
    ;}  // end of a binding scope
    goto v_2359;
v_2372:
    goto v_2408;
v_2404:
    v_2412 = stack[-1];
    goto v_2405;
v_2406:
    v_2411 = stack[0];
    goto v_2407;
v_2408:
    goto v_2404;
v_2405:
    goto v_2406;
v_2407:
    {
        fn = elt(env, 5); // ezgcdf
        return (*qfn2(fn))(fn, v_2412, v_2411);
    }
    v_2411 = nil;
v_2359:
    return onevalue(v_2411);
}



// Code for cl_atfp

static LispObject CC_cl_atfp(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2545, v_2546, v_2547;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2546 = v_2355;
// end of prologue
    v_2545 = v_2546;
    if (!consp(v_2545)) goto v_2359;
    else goto v_2360;
v_2359:
    v_2545 = v_2546;
    goto v_2358;
v_2360:
    v_2545 = v_2546;
    v_2545 = qcar(v_2545);
    goto v_2358;
    v_2545 = nil;
v_2358:
    v_2547 = v_2545;
    goto v_2380;
v_2376:
    v_2546 = v_2547;
    goto v_2377;
v_2378:
    v_2545 = elt(env, 1); // true
    goto v_2379;
v_2380:
    goto v_2376;
v_2377:
    goto v_2378;
v_2379:
    if (v_2546 == v_2545) goto v_2374;
    else goto v_2375;
v_2374:
    v_2545 = lisp_true;
    goto v_2373;
v_2375:
    goto v_2390;
v_2386:
    v_2546 = v_2547;
    goto v_2387;
v_2388:
    v_2545 = elt(env, 2); // false
    goto v_2389;
v_2390:
    goto v_2386;
v_2387:
    goto v_2388;
v_2389:
    v_2545 = (v_2546 == v_2545 ? lisp_true : nil);
    goto v_2373;
    v_2545 = nil;
v_2373:
    if (v_2545 == nil) goto v_2371;
    v_2545 = lisp_true;
    goto v_2369;
v_2371:
    goto v_2417;
v_2413:
    v_2546 = v_2547;
    goto v_2414;
v_2415:
    v_2545 = elt(env, 3); // or
    goto v_2416;
v_2417:
    goto v_2413;
v_2414:
    goto v_2415;
v_2416:
    if (v_2546 == v_2545) goto v_2411;
    else goto v_2412;
v_2411:
    v_2545 = lisp_true;
    goto v_2410;
v_2412:
    goto v_2427;
v_2423:
    v_2546 = v_2547;
    goto v_2424;
v_2425:
    v_2545 = elt(env, 4); // and
    goto v_2426;
v_2427:
    goto v_2423;
v_2424:
    goto v_2425;
v_2426:
    v_2545 = (v_2546 == v_2545 ? lisp_true : nil);
    goto v_2410;
    v_2545 = nil;
v_2410:
    if (v_2545 == nil) goto v_2408;
    v_2545 = lisp_true;
    goto v_2406;
v_2408:
    goto v_2438;
v_2434:
    v_2546 = v_2547;
    goto v_2435;
v_2436:
    v_2545 = elt(env, 5); // not
    goto v_2437;
v_2438:
    goto v_2434;
v_2435:
    goto v_2436;
v_2437:
    v_2545 = (v_2546 == v_2545 ? lisp_true : nil);
    goto v_2406;
    v_2545 = nil;
v_2406:
    if (v_2545 == nil) goto v_2404;
    v_2545 = lisp_true;
    goto v_2402;
v_2404:
    goto v_2453;
v_2449:
    v_2546 = v_2547;
    goto v_2450;
v_2451:
    v_2545 = elt(env, 6); // impl
    goto v_2452;
v_2453:
    goto v_2449;
v_2450:
    goto v_2451;
v_2452:
    if (v_2546 == v_2545) goto v_2447;
    else goto v_2448;
v_2447:
    v_2545 = lisp_true;
    goto v_2446;
v_2448:
    goto v_2467;
v_2463:
    v_2546 = v_2547;
    goto v_2464;
v_2465:
    v_2545 = elt(env, 7); // repl
    goto v_2466;
v_2467:
    goto v_2463;
v_2464:
    goto v_2465;
v_2466:
    if (v_2546 == v_2545) goto v_2461;
    else goto v_2462;
v_2461:
    v_2545 = lisp_true;
    goto v_2460;
v_2462:
    goto v_2477;
v_2473:
    v_2546 = v_2547;
    goto v_2474;
v_2475:
    v_2545 = elt(env, 8); // equiv
    goto v_2476;
v_2477:
    goto v_2473;
v_2474:
    goto v_2475;
v_2476:
    v_2545 = (v_2546 == v_2545 ? lisp_true : nil);
    goto v_2460;
    v_2545 = nil;
v_2460:
    goto v_2446;
    v_2545 = nil;
v_2446:
    goto v_2402;
    v_2545 = nil;
v_2402:
    if (v_2545 == nil) goto v_2400;
    v_2545 = lisp_true;
    goto v_2398;
v_2400:
    goto v_2496;
v_2492:
    v_2546 = v_2547;
    goto v_2493;
v_2494:
    v_2545 = elt(env, 9); // ex
    goto v_2495;
v_2496:
    goto v_2492;
v_2493:
    goto v_2494;
v_2495:
    if (v_2546 == v_2545) goto v_2490;
    else goto v_2491;
v_2490:
    v_2545 = lisp_true;
    goto v_2489;
v_2491:
    goto v_2506;
v_2502:
    v_2546 = v_2547;
    goto v_2503;
v_2504:
    v_2545 = elt(env, 10); // all
    goto v_2505;
v_2506:
    goto v_2502;
v_2503:
    goto v_2504;
v_2505:
    v_2545 = (v_2546 == v_2545 ? lisp_true : nil);
    goto v_2489;
    v_2545 = nil;
v_2489:
    if (v_2545 == nil) goto v_2487;
    v_2545 = lisp_true;
    goto v_2485;
v_2487:
    goto v_2525;
v_2521:
    v_2546 = v_2547;
    goto v_2522;
v_2523:
    v_2545 = elt(env, 11); // bex
    goto v_2524;
v_2525:
    goto v_2521;
v_2522:
    goto v_2523;
v_2524:
    if (v_2546 == v_2545) goto v_2519;
    else goto v_2520;
v_2519:
    v_2545 = lisp_true;
    goto v_2518;
v_2520:
    goto v_2535;
v_2531:
    v_2545 = v_2547;
    goto v_2532;
v_2533:
    v_2546 = elt(env, 12); // ball
    goto v_2534;
v_2535:
    goto v_2531;
v_2532:
    goto v_2533;
v_2534:
    v_2545 = (v_2545 == v_2546 ? lisp_true : nil);
    goto v_2518;
    v_2545 = nil;
v_2518:
    if (v_2545 == nil) goto v_2516;
    v_2545 = lisp_true;
    goto v_2514;
v_2516:
    v_2545 = v_2547;
    if (!symbolp(v_2545)) v_2545 = nil;
    else { v_2545 = qfastgets(v_2545);
           if (v_2545 != nil) { v_2545 = elt(v_2545, 21); // rl_external
#ifdef RECORD_GET
             if (v_2545 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_2545 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_2545 == SPID_NOPROP) v_2545 = nil; }}
#endif
    goto v_2514;
    v_2545 = nil;
v_2514:
    goto v_2485;
    v_2545 = nil;
v_2485:
    goto v_2398;
    v_2545 = nil;
v_2398:
    goto v_2369;
    v_2545 = nil;
v_2369:
    v_2545 = (v_2545 == nil ? lisp_true : nil);
    return onevalue(v_2545);
}



// Code for qqe_id!-nyt!-branchb

static LispObject CC_qqe_idKnytKbranchb(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2381;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2355;
// end of prologue
    v_2381 = stack[0];
    if (!consp(v_2381)) goto v_2359;
    else goto v_2360;
v_2359:
    v_2381 = stack[0];
    fn = elt(env, 1); // qqe_btidp
    v_2381 = (*qfn1(fn))(fn, v_2381);
    env = stack[-1];
    if (v_2381 == nil) goto v_2364;
    else goto v_2363;
v_2364:
    v_2381 = stack[0];
    {
        fn = elt(env, 2); // qqe_nytidp
        return (*qfn1(fn))(fn, v_2381);
    }
v_2363:
    goto v_2358;
v_2360:
    v_2381 = stack[0];
    v_2381 = qcar(v_2381);
    fn = elt(env, 3); // qqe_qopaddp
    v_2381 = (*qfn1(fn))(fn, v_2381);
    env = stack[-1];
    if (v_2381 == nil) goto v_2373;
    else goto v_2372;
v_2373:
    v_2381 = stack[0];
    v_2381 = qcar(v_2381);
    fn = elt(env, 4); // qqe_qoptailp
    v_2381 = (*qfn1(fn))(fn, v_2381);
v_2372:
    v_2381 = (v_2381 == nil ? lisp_true : nil);
    goto v_2358;
    v_2381 = nil;
v_2358:
    return onevalue(v_2381);
}



// Code for ibalp_calcmom

static LispObject CC_ibalp_calcmom(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2408, v_2409;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2355;
// end of prologue
    goto v_2362;
v_2358:
    goto v_2368;
v_2364:
    goto v_2374;
v_2370:
    v_2408 = stack[0];
    v_2408 = qcdr(v_2408);
    v_2408 = qcdr(v_2408);
    v_2408 = qcdr(v_2408);
    v_2408 = qcdr(v_2408);
    v_2409 = qcar(v_2408);
    goto v_2371;
v_2372:
    v_2408 = stack[0];
    v_2408 = qcdr(v_2408);
    v_2408 = qcdr(v_2408);
    v_2408 = qcdr(v_2408);
    v_2408 = qcdr(v_2408);
    v_2408 = qcdr(v_2408);
    v_2408 = qcar(v_2408);
    goto v_2373;
v_2374:
    goto v_2370;
v_2371:
    goto v_2372;
v_2373:
    v_2409 = plus2(v_2409, v_2408);
    env = stack[-2];
    goto v_2365;
v_2366:
    v_2408 = (LispObject)512+TAG_FIXNUM; // 32
    goto v_2367;
v_2368:
    goto v_2364;
v_2365:
    goto v_2366;
v_2367:
    stack[-1] = times2(v_2409, v_2408);
    env = stack[-2];
    goto v_2359;
v_2360:
    goto v_2394;
v_2390:
    v_2408 = stack[0];
    v_2408 = qcdr(v_2408);
    v_2408 = qcdr(v_2408);
    v_2408 = qcdr(v_2408);
    v_2408 = qcdr(v_2408);
    v_2409 = qcar(v_2408);
    goto v_2391;
v_2392:
    v_2408 = stack[0];
    v_2408 = qcdr(v_2408);
    v_2408 = qcdr(v_2408);
    v_2408 = qcdr(v_2408);
    v_2408 = qcdr(v_2408);
    v_2408 = qcdr(v_2408);
    v_2408 = qcar(v_2408);
    goto v_2393;
v_2394:
    goto v_2390;
v_2391:
    goto v_2392;
v_2393:
    v_2408 = times2(v_2409, v_2408);
    goto v_2361;
v_2362:
    goto v_2358;
v_2359:
    goto v_2360;
v_2361:
    {
        LispObject v_2412 = stack[-1];
        return plus2(v_2412, v_2408);
    }
}



// Code for multi_elem

static LispObject CC_multi_elem(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2383, v_2384;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2355;
// end of prologue
    goto v_2367;
v_2363:
    v_2383 = stack[0];
    v_2384 = Llength(nil, v_2383);
    env = stack[-1];
    goto v_2364;
v_2365:
    v_2383 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2366;
v_2367:
    goto v_2363;
v_2364:
    goto v_2365;
v_2366:
    if (v_2384 == v_2383) goto v_2361;
    else goto v_2362;
v_2361:
    v_2383 = stack[0];
    v_2383 = qcar(v_2383);
    fn = elt(env, 1); // expression
    v_2383 = (*qfn1(fn))(fn, v_2383);
    goto v_2360;
v_2362:
    v_2383 = stack[0];
    v_2383 = qcar(v_2383);
    fn = elt(env, 1); // expression
    v_2383 = (*qfn1(fn))(fn, v_2383);
    env = stack[-1];
    v_2383 = stack[0];
    v_2383 = qcdr(v_2383);
    v_2383 = CC_multi_elem(elt(env, 0), v_2383);
    goto v_2360;
v_2360:
    v_2383 = nil;
    return onevalue(v_2383);
}



// Code for rationalizei

static LispObject CC_rationalizei(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2464, v_2465;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_2355;
// end of prologue
    v_2464 = stack[-1];
    v_2464 = qcdr(v_2464);
    stack[-2] = v_2464;
    v_2465 = v_2464;
    v_2464 = v_2465;
    if (!consp(v_2464)) goto v_2371;
    else goto v_2372;
v_2371:
    v_2464 = lisp_true;
    goto v_2370;
v_2372:
    v_2464 = v_2465;
    v_2464 = qcar(v_2464);
    v_2464 = (consp(v_2464) ? nil : lisp_true);
    goto v_2370;
    v_2464 = nil;
v_2370:
    if (v_2464 == nil) goto v_2365;
    else goto v_2363;
v_2365:
    goto v_2386;
v_2382:
    v_2465 = elt(env, 1); // i
    goto v_2383;
v_2384:
    v_2464 = stack[-2];
    goto v_2385;
v_2386:
    goto v_2382;
v_2383:
    goto v_2384;
v_2385:
    v_2464 = Lsmemq(nil, v_2465, v_2464);
    env = stack[-3];
    if (v_2464 == nil) goto v_2363;
    goto v_2364;
v_2363:
    v_2464 = stack[-1];
    goto v_2360;
v_2364:
    goto v_2395;
v_2391:
    v_2465 = elt(env, 1); // i
    goto v_2392;
v_2393:
    v_2464 = qvalue(elt(env, 2)); // kord!*
    goto v_2394;
v_2395:
    goto v_2391;
v_2392:
    goto v_2393;
v_2394:
    v_2464 = cons(v_2465, v_2464);
    env = stack[-3];
// Binding kord!*
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-3, 2, 0);
    qvalue(elt(env, 2)) = v_2464; // kord!*
    v_2464 = stack[-1];
    fn = elt(env, 4); // reordsq
    v_2464 = (*qfn1(fn))(fn, v_2464);
    env = stack[-3];
    stack[-2] = v_2464;
    ;}  // end of a binding scope
    goto v_2413;
v_2409:
    v_2464 = stack[-2];
    v_2464 = qcdr(v_2464);
    stack[0] = v_2464;
    v_2464 = qcar(v_2464);
    v_2465 = qcar(v_2464);
    goto v_2410;
v_2411:
    v_2464 = elt(env, 3); // (i . 1)
    goto v_2412;
v_2413:
    goto v_2409;
v_2410:
    goto v_2411;
v_2412:
    if (equal(v_2465, v_2464)) goto v_2407;
    else goto v_2408;
v_2407:
    v_2464 = stack[0];
    v_2464 = qcdr(v_2464);
    v_2464 = (v_2464 == nil ? lisp_true : nil);
    goto v_2406;
v_2408:
    v_2464 = nil;
    goto v_2406;
    v_2464 = nil;
v_2406:
    if (v_2464 == nil) goto v_2404;
    goto v_2430;
v_2426:
    goto v_2437;
v_2433:
    goto v_2444;
v_2440:
    goto v_2450;
v_2446:
    v_2465 = elt(env, 1); // i
    goto v_2447;
v_2448:
    v_2464 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2449;
v_2450:
    goto v_2446;
v_2447:
    goto v_2448;
v_2449:
    fn = elt(env, 5); // to
    v_2465 = (*qfn2(fn))(fn, v_2465, v_2464);
    env = stack[-3];
    goto v_2441;
v_2442:
    v_2464 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2443;
v_2444:
    goto v_2440;
v_2441:
    goto v_2442;
v_2443:
    v_2464 = cons(v_2465, v_2464);
    env = stack[-3];
    stack[-1] = ncons(v_2464);
    env = stack[-3];
    goto v_2434;
v_2435:
    v_2464 = stack[-2];
    v_2464 = qcar(v_2464);
    fn = elt(env, 6); // reorder
    v_2464 = (*qfn1(fn))(fn, v_2464);
    env = stack[-3];
    goto v_2436;
v_2437:
    goto v_2433;
v_2434:
    goto v_2435;
v_2436:
    fn = elt(env, 7); // multf
    v_2464 = (*qfn2(fn))(fn, stack[-1], v_2464);
    env = stack[-3];
    fn = elt(env, 8); // negf
    stack[-1] = (*qfn1(fn))(fn, v_2464);
    env = stack[-3];
    goto v_2427;
v_2428:
    v_2464 = stack[0];
    v_2464 = qcar(v_2464);
    v_2464 = qcdr(v_2464);
    fn = elt(env, 6); // reorder
    v_2464 = (*qfn1(fn))(fn, v_2464);
    goto v_2429;
v_2430:
    goto v_2426;
v_2427:
    goto v_2428;
v_2429:
    {
        LispObject v_2469 = stack[-1];
        return cons(v_2469, v_2464);
    }
v_2404:
    v_2464 = stack[-1];
    goto v_2402;
    v_2464 = nil;
v_2402:
v_2360:
    return onevalue(v_2464);
}



// Code for mintype

static LispObject CC_mintype(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2367, v_2368;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2367 = v_2355;
// end of prologue
    v_2368 = v_2367;
    if (!consp(v_2368)) goto v_2359;
    else goto v_2360;
v_2359:
    goto v_2358;
v_2360:
    v_2367 = qcar(v_2367);
    goto v_2358;
    v_2367 = nil;
v_2358:
    return onevalue(v_2367);
}



// Code for nextarg

static LispObject CC_nextarg(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2368, v_2369;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2369 = v_2355;
// end of prologue
    v_2368 = qvalue(elt(env, 1)); // symm
    if (v_2368 == nil) goto v_2360;
    v_2368 = v_2369;
    {
        fn = elt(env, 2); // s!-nextarg
        return (*qfn1(fn))(fn, v_2368);
    }
v_2360:
    v_2368 = v_2369;
    {
        fn = elt(env, 3); // o!-nextarg
        return (*qfn1(fn))(fn, v_2368);
    }
    v_2368 = nil;
    return onevalue(v_2368);
}



// Code for layout!-formula

static LispObject CC_layoutKformula(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2448, v_2449;
    LispObject fn;
    LispObject v_2357, v_2356, v_2355;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "layout-formula");
    va_start(aa, nargs);
    v_2355 = va_arg(aa, LispObject);
    v_2356 = va_arg(aa, LispObject);
    v_2357 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_2357,v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_2355,v_2356,v_2357);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-6] = v_2357;
    stack[-7] = v_2356;
    stack[-8] = v_2355;
// end of prologue
// Binding ycoord!*
// FLUIDBIND: reloadenv=10 litvec-offset=1 saveloc=9
{   bind_fluid_stack bind_fluid_var(-10, 1, -9);
    qvalue(elt(env, 1)) = nil; // ycoord!*
// Binding ymin!*
// FLUIDBIND: reloadenv=10 litvec-offset=2 saveloc=5
{   bind_fluid_stack bind_fluid_var(-10, 2, -5);
    qvalue(elt(env, 2)) = nil; // ymin!*
// Binding ymax!*
// FLUIDBIND: reloadenv=10 litvec-offset=3 saveloc=4
{   bind_fluid_stack bind_fluid_var(-10, 3, -4);
    qvalue(elt(env, 3)) = nil; // ymax!*
// Binding posn!*
// FLUIDBIND: reloadenv=10 litvec-offset=4 saveloc=3
{   bind_fluid_stack bind_fluid_var(-10, 4, -3);
    qvalue(elt(env, 4)) = nil; // posn!*
// Binding pline!*
// FLUIDBIND: reloadenv=10 litvec-offset=5 saveloc=2
{   bind_fluid_stack bind_fluid_var(-10, 5, -2);
    qvalue(elt(env, 5)) = nil; // pline!*
// Binding testing!-width!*
// FLUIDBIND: reloadenv=10 litvec-offset=6 saveloc=1
{   bind_fluid_stack bind_fluid_var(-10, 6, -1);
    qvalue(elt(env, 6)) = nil; // testing!-width!*
// Binding overflowed!*
// FLUIDBIND: reloadenv=10 litvec-offset=7 saveloc=0
{   bind_fluid_stack bind_fluid_var(-10, 7, 0);
    qvalue(elt(env, 7)) = nil; // overflowed!*
    v_2448 = nil;
    qvalue(elt(env, 7)) = v_2448; // overflowed!*
    qvalue(elt(env, 5)) = v_2448; // pline!*
    v_2448 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 3)) = v_2448; // ymax!*
    qvalue(elt(env, 2)) = v_2448; // ymin!*
    qvalue(elt(env, 1)) = v_2448; // ycoord!*
    v_2448 = qvalue(elt(env, 8)); // orig!*
    qvalue(elt(env, 4)) = v_2448; // posn!*
    v_2448 = lisp_true;
    qvalue(elt(env, 6)) = v_2448; // testing!-width!*
    v_2448 = stack[-6];
    if (v_2448 == nil) goto v_2375;
    goto v_2385;
v_2381:
    v_2449 = stack[-6];
    goto v_2382;
v_2383:
    v_2448 = elt(env, 9); // inbrackets
    goto v_2384;
v_2385:
    goto v_2381;
v_2382:
    goto v_2383;
v_2384:
    if (v_2449 == v_2448) goto v_2379;
    else goto v_2380;
v_2379:
    v_2448 = elt(env, 10); // "("
    fn = elt(env, 12); // prin2!*
    v_2448 = (*qfn1(fn))(fn, v_2448);
    env = stack[-10];
    goto v_2378;
v_2380:
    v_2448 = stack[-6];
    fn = elt(env, 13); // oprin
    v_2448 = (*qfn1(fn))(fn, v_2448);
    env = stack[-10];
    goto v_2378;
v_2378:
    goto v_2373;
v_2375:
v_2373:
    goto v_2399;
v_2395:
    v_2449 = stack[-8];
    goto v_2396;
v_2397:
    v_2448 = stack[-7];
    goto v_2398;
v_2399:
    goto v_2395;
v_2396:
    goto v_2397;
v_2398:
    fn = elt(env, 14); // maprint
    v_2448 = (*qfn2(fn))(fn, v_2449, v_2448);
    env = stack[-10];
    goto v_2410;
v_2406:
    v_2449 = stack[-6];
    goto v_2407;
v_2408:
    v_2448 = elt(env, 9); // inbrackets
    goto v_2409;
v_2410:
    goto v_2406;
v_2407:
    goto v_2408;
v_2409:
    if (v_2449 == v_2448) goto v_2404;
    else goto v_2405;
v_2404:
    v_2448 = elt(env, 11); // ")"
    fn = elt(env, 12); // prin2!*
    v_2448 = (*qfn1(fn))(fn, v_2448);
    env = stack[-10];
    goto v_2403;
v_2405:
v_2403:
    v_2448 = qvalue(elt(env, 7)); // overflowed!*
    if (v_2448 == nil) goto v_2418;
    v_2448 = nil;
    goto v_2367;
v_2418:
    goto v_2430;
v_2424:
    stack[-7] = qvalue(elt(env, 5)); // pline!*
    goto v_2425;
v_2426:
    goto v_2437;
v_2433:
    v_2449 = qvalue(elt(env, 4)); // posn!*
    goto v_2434;
v_2435:
    v_2448 = qvalue(elt(env, 8)); // orig!*
    goto v_2436;
v_2437:
    goto v_2433;
v_2434:
    goto v_2435;
v_2436:
    stack[-6] = difference2(v_2449, v_2448);
    env = stack[-10];
    goto v_2427;
v_2428:
    goto v_2445;
v_2441:
    v_2449 = qvalue(elt(env, 2)); // ymin!*
    goto v_2442;
v_2443:
    v_2448 = qvalue(elt(env, 3)); // ymax!*
    goto v_2444;
v_2445:
    goto v_2441;
v_2442:
    goto v_2443;
v_2444:
    v_2448 = cons(v_2449, v_2448);
    env = stack[-10];
    goto v_2429;
v_2430:
    goto v_2424;
v_2425:
    goto v_2426;
v_2427:
    goto v_2428;
v_2429:
    v_2448 = acons(stack[-7], stack[-6], v_2448);
    goto v_2367;
    v_2448 = nil;
v_2367:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_2448);
}



// Code for abs!:

static LispObject CC_absT(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2390, v_2391;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2355;
// end of prologue
    goto v_2366;
v_2362:
    v_2390 = stack[0];
    v_2390 = qcdr(v_2390);
    v_2391 = qcar(v_2390);
    goto v_2363;
v_2364:
    v_2390 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2365;
v_2366:
    goto v_2362;
v_2363:
    goto v_2364;
v_2365:
    v_2390 = (LispObject)greaterp2(v_2391, v_2390);
    v_2390 = v_2390 ? lisp_true : nil;
    env = stack[-2];
    if (v_2390 == nil) goto v_2360;
    v_2390 = stack[0];
    goto v_2358;
v_2360:
    goto v_2381;
v_2375:
    stack[-1] = elt(env, 1); // !:rd!:
    goto v_2376;
v_2377:
    v_2390 = stack[0];
    v_2390 = qcdr(v_2390);
    v_2390 = qcar(v_2390);
    v_2391 = negate(v_2390);
    goto v_2378;
v_2379:
    v_2390 = stack[0];
    v_2390 = qcdr(v_2390);
    v_2390 = qcdr(v_2390);
    goto v_2380;
v_2381:
    goto v_2375;
v_2376:
    goto v_2377;
v_2378:
    goto v_2379;
v_2380:
    {
        LispObject v_2394 = stack[-1];
        return list2star(v_2394, v_2391, v_2390);
    }
    v_2390 = nil;
v_2358:
    return onevalue(v_2390);
}



// Code for setcloc!*

static LispObject CC_setclocH(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2376, v_2377, v_2378;
    argcheck(nargs, 0, "setcloc*");
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
    v_2376 = qvalue(elt(env, 1)); // ifl!*
    if (v_2376 == nil) goto v_2358;
    else goto v_2359;
v_2358:
    v_2376 = nil;
    goto v_2357;
v_2359:
    goto v_2371;
v_2365:
    v_2376 = qvalue(elt(env, 1)); // ifl!*
    v_2378 = qcar(v_2376);
    goto v_2366;
v_2367:
    v_2377 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2368;
v_2369:
    v_2376 = qvalue(elt(env, 2)); // curline!*
    goto v_2370;
v_2371:
    goto v_2365;
v_2366:
    goto v_2367;
v_2368:
    goto v_2369;
v_2370:
    v_2376 = list2star(v_2378, v_2377, v_2376);
    env = stack[0];
    goto v_2357;
    v_2376 = nil;
v_2357:
    qvalue(elt(env, 3)) = v_2376; // cloc!*
    return onevalue(v_2376);
}



// Code for mv!-pow!-mv!-term!-!+

static LispObject CC_mvKpowKmvKtermKL(LispObject env,
                         LispObject v_2355, LispObject v_2356)
{
    env = qenv(env);
    LispObject v_2375, v_2376;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2355,v_2356);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_2356;
    v_2375 = v_2355;
// end of prologue
    goto v_2363;
v_2359:
    goto v_2369;
v_2365:
    v_2376 = v_2375;
    goto v_2366;
v_2367:
    v_2375 = stack[0];
    v_2375 = qcar(v_2375);
    goto v_2368;
v_2369:
    goto v_2365;
v_2366:
    goto v_2367;
v_2368:
    fn = elt(env, 1); // mv!-pow!-!+
    v_2376 = (*qfn2(fn))(fn, v_2376, v_2375);
    goto v_2360;
v_2361:
    v_2375 = stack[0];
    v_2375 = qcdr(v_2375);
    goto v_2362;
v_2363:
    goto v_2359;
v_2360:
    goto v_2361;
v_2362:
    return cons(v_2376, v_2375);
}



// Code for rnplus!:

static LispObject CC_rnplusT(LispObject env,
                         LispObject v_2355, LispObject v_2356)
{
    env = qenv(env);
    LispObject v_2406, v_2407;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2355,v_2356);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_2356;
    stack[-1] = v_2355;
// end of prologue
    goto v_2363;
v_2359:
    goto v_2369;
v_2365:
    goto v_2375;
v_2371:
    v_2406 = stack[-1];
    v_2406 = qcdr(v_2406);
    v_2407 = qcar(v_2406);
    goto v_2372;
v_2373:
    v_2406 = stack[0];
    v_2406 = qcdr(v_2406);
    v_2406 = qcdr(v_2406);
    goto v_2374;
v_2375:
    goto v_2371;
v_2372:
    goto v_2373;
v_2374:
    stack[-2] = times2(v_2407, v_2406);
    env = stack[-3];
    goto v_2366;
v_2367:
    goto v_2387;
v_2383:
    v_2406 = stack[-1];
    v_2406 = qcdr(v_2406);
    v_2407 = qcdr(v_2406);
    goto v_2384;
v_2385:
    v_2406 = stack[0];
    v_2406 = qcdr(v_2406);
    v_2406 = qcar(v_2406);
    goto v_2386;
v_2387:
    goto v_2383;
v_2384:
    goto v_2385;
v_2386:
    v_2406 = times2(v_2407, v_2406);
    env = stack[-3];
    goto v_2368;
v_2369:
    goto v_2365;
v_2366:
    goto v_2367;
v_2368:
    stack[-2] = plus2(stack[-2], v_2406);
    env = stack[-3];
    goto v_2360;
v_2361:
    goto v_2399;
v_2395:
    v_2406 = stack[-1];
    v_2406 = qcdr(v_2406);
    v_2407 = qcdr(v_2406);
    goto v_2396;
v_2397:
    v_2406 = stack[0];
    v_2406 = qcdr(v_2406);
    v_2406 = qcdr(v_2406);
    goto v_2398;
v_2399:
    goto v_2395;
v_2396:
    goto v_2397;
v_2398:
    v_2406 = times2(v_2407, v_2406);
    env = stack[-3];
    goto v_2362;
v_2363:
    goto v_2359;
v_2360:
    goto v_2361;
v_2362:
    {
        LispObject v_2411 = stack[-2];
        fn = elt(env, 1); // mkrn
        return (*qfn2(fn))(fn, v_2411, v_2406);
    }
}



// Code for lalr_analyze_lookaheads

static LispObject CC_lalr_analyze_lookaheads(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2521, v_2522, v_2523;
    LispObject fn;
    argcheck(nargs, 0, "lalr_analyze_lookaheads");
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
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// end of prologue
    stack[-9] = nil;
    v_2521 = qvalue(elt(env, 1)); // itemset_collection
    stack[-4] = v_2521;
v_2370:
    v_2521 = stack[-4];
    if (v_2521 == nil) goto v_2374;
    else goto v_2375;
v_2374:
    goto v_2369;
v_2375:
    v_2521 = stack[-4];
    v_2521 = qcar(v_2521);
    stack[-3] = v_2521;
    v_2521 = stack[-3];
    v_2521 = qcar(v_2521);
    stack[-2] = v_2521;
v_2384:
    v_2521 = stack[-2];
    if (v_2521 == nil) goto v_2389;
    else goto v_2390;
v_2389:
    goto v_2383;
v_2390:
    v_2521 = stack[-2];
    v_2521 = qcar(v_2521);
    stack[-1] = v_2521;
    goto v_2401;
v_2397:
    v_2521 = stack[-1];
    v_2522 = qcar(v_2521);
    goto v_2398;
v_2399:
    v_2521 = elt(env, 2); // (-1)
    goto v_2400;
v_2401:
    goto v_2397;
v_2398:
    goto v_2399;
v_2400:
    v_2521 = cons(v_2522, v_2521);
    env = stack[-10];
    v_2521 = ncons(v_2521);
    env = stack[-10];
    fn = elt(env, 4); // lalr_closure
    v_2521 = (*qfn1(fn))(fn, v_2521);
    env = stack[-10];
    stack[0] = v_2521;
v_2408:
    v_2521 = stack[0];
    if (v_2521 == nil) goto v_2414;
    else goto v_2415;
v_2414:
    goto v_2407;
v_2415:
    v_2521 = stack[0];
    v_2521 = qcar(v_2521);
    v_2522 = v_2521;
    v_2521 = v_2522;
    v_2521 = qcar(v_2521);
    stack[-6] = v_2521;
    v_2521 = v_2522;
    v_2521 = qcdr(v_2521);
    stack[-8] = v_2521;
    goto v_2433;
v_2429:
    v_2522 = elt(env, 3); // !.
    goto v_2430;
v_2431:
    v_2521 = stack[-6];
    goto v_2432;
v_2433:
    goto v_2429;
v_2430:
    goto v_2431;
v_2432:
    v_2521 = Lmember(nil, v_2522, v_2521);
    v_2521 = qcdr(v_2521);
    v_2522 = v_2521;
    if (v_2521 == nil) goto v_2428;
    v_2521 = v_2522;
    v_2521 = qcar(v_2521);
    stack[-5] = v_2521;
    goto v_2447;
v_2443:
    v_2522 = stack[-3];
    goto v_2444;
v_2445:
    v_2521 = stack[-5];
    goto v_2446;
v_2447:
    goto v_2443;
v_2444:
    goto v_2445;
v_2446:
    fn = elt(env, 5); // lalr_goto
    v_2521 = (*qfn2(fn))(fn, v_2522, v_2521);
    env = stack[-10];
    stack[-7] = v_2521;
    goto v_2455;
v_2451:
    goto v_2461;
v_2457:
    v_2522 = stack[-6];
    goto v_2458;
v_2459:
    v_2521 = stack[-5];
    goto v_2460;
v_2461:
    goto v_2457;
v_2458:
    goto v_2459;
v_2460:
    fn = elt(env, 6); // lalr_lr0_move_dot
    v_2522 = (*qfn2(fn))(fn, v_2522, v_2521);
    env = stack[-10];
    goto v_2452;
v_2453:
    v_2521 = stack[-7];
    v_2521 = qcar(v_2521);
    goto v_2454;
v_2455:
    goto v_2451;
v_2452:
    goto v_2453;
v_2454:
    fn = elt(env, 7); // lalr_item_with_rule
    v_2521 = (*qfn2(fn))(fn, v_2522, v_2521);
    env = stack[-10];
    stack[-5] = v_2521;
    v_2521 = stack[-8];
    stack[-6] = v_2521;
v_2469:
    v_2521 = stack[-6];
    if (v_2521 == nil) goto v_2473;
    else goto v_2474;
v_2473:
    goto v_2468;
v_2474:
    v_2521 = stack[-6];
    v_2521 = qcar(v_2521);
    v_2523 = v_2521;
    goto v_2488;
v_2484:
    v_2522 = v_2523;
    goto v_2485;
v_2486:
    v_2521 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_2487;
v_2488:
    goto v_2484;
v_2485:
    goto v_2486;
v_2487:
    if (v_2522 == v_2521) goto v_2482;
    else goto v_2483;
v_2482:
    goto v_2498;
v_2492:
    v_2523 = stack[-1];
    goto v_2493;
v_2494:
    v_2522 = stack[-5];
    goto v_2495;
v_2496:
    v_2521 = stack[-9];
    goto v_2497;
v_2498:
    goto v_2492;
v_2493:
    goto v_2494;
v_2495:
    goto v_2496;
v_2497:
    v_2521 = acons(v_2523, v_2522, v_2521);
    env = stack[-10];
    stack[-9] = v_2521;
    goto v_2481;
v_2483:
    goto v_2509;
v_2505:
    v_2521 = stack[-5];
    goto v_2506;
v_2507:
    v_2522 = v_2523;
    goto v_2508;
v_2509:
    goto v_2505;
v_2506:
    goto v_2507;
v_2508:
    fn = elt(env, 8); // lalr_add_lookahead
    v_2521 = (*qfn2(fn))(fn, v_2521, v_2522);
    env = stack[-10];
    goto v_2481;
v_2481:
    v_2521 = stack[-6];
    v_2521 = qcdr(v_2521);
    stack[-6] = v_2521;
    goto v_2469;
v_2468:
    goto v_2426;
v_2428:
v_2426:
    v_2521 = stack[0];
    v_2521 = qcdr(v_2521);
    stack[0] = v_2521;
    goto v_2408;
v_2407:
    v_2521 = stack[-2];
    v_2521 = qcdr(v_2521);
    stack[-2] = v_2521;
    goto v_2384;
v_2383:
    v_2521 = stack[-4];
    v_2521 = qcdr(v_2521);
    stack[-4] = v_2521;
    goto v_2370;
v_2369:
    v_2521 = stack[-9];
    return onevalue(v_2521);
}



// Code for sfto_davp

static LispObject CC_sfto_davp(LispObject env,
                         LispObject v_2355, LispObject v_2356)
{
    env = qenv(env);
    LispObject v_2459, v_2460;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2355,v_2356);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2356;
    stack[-1] = v_2355;
// end of prologue
v_2361:
    v_2459 = stack[-1];
    if (!consp(v_2459)) goto v_2368;
    else goto v_2369;
v_2368:
    v_2459 = lisp_true;
    goto v_2367;
v_2369:
    v_2459 = stack[-1];
    v_2459 = qcar(v_2459);
    v_2459 = (consp(v_2459) ? nil : lisp_true);
    goto v_2367;
    v_2459 = nil;
v_2367:
    if (v_2459 == nil) goto v_2365;
    v_2459 = lisp_true;
    goto v_2360;
v_2365:
    goto v_2385;
v_2381:
    v_2459 = stack[-1];
    v_2459 = qcar(v_2459);
    v_2459 = qcar(v_2459);
    v_2460 = qcdr(v_2459);
    goto v_2382;
v_2383:
    v_2459 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_2384;
v_2385:
    goto v_2381;
v_2382:
    goto v_2383;
v_2384:
    v_2459 = (LispObject)greaterp2(v_2460, v_2459);
    v_2459 = v_2459 ? lisp_true : nil;
    env = stack[-2];
    if (v_2459 == nil) goto v_2379;
    v_2459 = stack[0];
    if (v_2459 == nil) goto v_2394;
    goto v_2402;
v_2398:
    v_2459 = stack[-1];
    v_2459 = qcar(v_2459);
    v_2459 = qcar(v_2459);
    v_2460 = qcar(v_2459);
    goto v_2399;
v_2400:
    v_2459 = stack[0];
    goto v_2401;
v_2402:
    goto v_2398;
v_2399:
    goto v_2400;
v_2401:
    if (equal(v_2460, v_2459)) goto v_2394;
    v_2459 = nil;
    goto v_2360;
v_2394:
    goto v_2420;
v_2416:
    v_2459 = stack[-1];
    v_2459 = qcar(v_2459);
    v_2460 = qcdr(v_2459);
    goto v_2417;
v_2418:
    v_2459 = stack[-1];
    v_2459 = qcar(v_2459);
    v_2459 = qcar(v_2459);
    v_2459 = qcar(v_2459);
    goto v_2419;
v_2420:
    goto v_2416;
v_2417:
    goto v_2418;
v_2419:
    v_2459 = CC_sfto_davp(elt(env, 0), v_2460, v_2459);
    env = stack[-2];
    if (v_2459 == nil) goto v_2414;
    v_2459 = stack[-1];
    v_2459 = qcdr(v_2459);
    v_2460 = v_2459;
    v_2459 = stack[-1];
    v_2459 = qcar(v_2459);
    v_2459 = qcar(v_2459);
    v_2459 = qcar(v_2459);
    stack[0] = v_2459;
    v_2459 = v_2460;
    stack[-1] = v_2459;
    goto v_2361;
v_2414:
    v_2459 = nil;
    goto v_2360;
    goto v_2392;
v_2392:
    goto v_2363;
v_2379:
    goto v_2449;
v_2445:
    v_2459 = stack[-1];
    v_2459 = qcar(v_2459);
    v_2460 = qcdr(v_2459);
    goto v_2446;
v_2447:
    v_2459 = stack[0];
    goto v_2448;
v_2449:
    goto v_2445;
v_2446:
    goto v_2447;
v_2448:
    v_2459 = CC_sfto_davp(elt(env, 0), v_2460, v_2459);
    env = stack[-2];
    if (v_2459 == nil) goto v_2443;
    v_2459 = stack[-1];
    v_2459 = qcdr(v_2459);
    stack[-1] = v_2459;
    goto v_2361;
v_2443:
    v_2459 = nil;
    goto v_2360;
    goto v_2363;
v_2363:
    v_2459 = nil;
v_2360:
    return onevalue(v_2459);
}



// Code for powers1

static LispObject CC_powers1(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2375, v_2376;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_2375 = v_2355;
// end of prologue
    goto v_2364;
v_2358:
    stack[0] = v_2375;
    goto v_2359;
v_2360:
    goto v_2371;
v_2367:
    v_2376 = v_2375;
    goto v_2368;
v_2369:
    v_2375 = nil;
    goto v_2370;
v_2371:
    goto v_2367;
v_2368:
    goto v_2369;
v_2370:
    fn = elt(env, 1); // powers3
    v_2376 = (*qfn2(fn))(fn, v_2376, v_2375);
    env = stack[-1];
    goto v_2361;
v_2362:
    v_2375 = nil;
    goto v_2363;
v_2364:
    goto v_2358;
v_2359:
    goto v_2360;
v_2361:
    goto v_2362;
v_2363:
    {
        LispObject v_2378 = stack[0];
        fn = elt(env, 2); // powers2
        return (*qfnn(fn))(fn, 3, v_2378, v_2376, v_2375);
    }
}



// Code for mcharg

static LispObject CC_mcharg(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2495, v_2496, v_2497;
    LispObject fn;
    LispObject v_2357, v_2356, v_2355;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mcharg");
    va_start(aa, nargs);
    v_2355 = va_arg(aa, LispObject);
    v_2356 = va_arg(aa, LispObject);
    v_2357 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_2357,v_2356,v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_2355,v_2356,v_2357);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_2357;
    stack[0] = v_2356;
    v_2497 = v_2355;
// end of prologue
    goto v_2367;
v_2363:
    v_2496 = elt(env, 1); // minus
    goto v_2364;
v_2365:
    v_2495 = stack[0];
    goto v_2366;
v_2367:
    goto v_2363;
v_2364:
    goto v_2365;
v_2366:
    v_2495 = Latsoc(nil, v_2496, v_2495);
    if (v_2495 == nil) goto v_2362;
    goto v_2378;
v_2372:
    goto v_2384;
v_2380:
    v_2496 = v_2497;
    goto v_2381;
v_2382:
    v_2495 = stack[0];
    goto v_2383;
v_2384:
    goto v_2380;
v_2381:
    goto v_2382;
v_2383:
    fn = elt(env, 3); // reform!-minus
    v_2497 = (*qfn2(fn))(fn, v_2496, v_2495);
    env = stack[-5];
    goto v_2373;
v_2374:
    v_2496 = stack[0];
    goto v_2375;
v_2376:
    v_2495 = stack[-3];
    goto v_2377;
v_2378:
    goto v_2372;
v_2373:
    goto v_2374;
v_2375:
    goto v_2376;
v_2377:
    {
        fn = elt(env, 4); // mcharg1
        return (*qfnn(fn))(fn, 3, v_2497, v_2496, v_2495);
    }
v_2362:
    v_2495 = stack[0];
    if (v_2495 == nil) goto v_2390;
    goto v_2399;
v_2395:
    v_2495 = stack[0];
    v_2496 = qcar(v_2495);
    goto v_2396;
v_2397:
    v_2495 = elt(env, 2); // slash
    goto v_2398;
v_2399:
    goto v_2395;
v_2396:
    goto v_2397;
v_2398:
    if (!consp(v_2496)) goto v_2390;
    v_2496 = qcar(v_2496);
    if (v_2496 == v_2495) goto v_2393;
    else goto v_2390;
v_2393:
    goto v_2415;
v_2411:
    v_2496 = v_2497;
    goto v_2412;
v_2413:
    v_2495 = stack[0];
    goto v_2414;
v_2415:
    goto v_2411;
v_2412:
    goto v_2413;
v_2414:
    fn = elt(env, 5); // reform!-minus2
    v_2495 = (*qfn2(fn))(fn, v_2496, v_2495);
    env = stack[-5];
    stack[-4] = v_2495;
v_2408:
    v_2495 = stack[-4];
    if (v_2495 == nil) goto v_2420;
    else goto v_2421;
v_2420:
    v_2495 = nil;
    goto v_2407;
v_2421:
    v_2495 = stack[-4];
    v_2495 = qcar(v_2495);
    goto v_2434;
v_2428:
    v_2496 = v_2495;
    v_2497 = qcar(v_2496);
    goto v_2429;
v_2430:
    v_2496 = qcdr(v_2495);
    goto v_2431;
v_2432:
    v_2495 = stack[-3];
    goto v_2433;
v_2434:
    goto v_2428;
v_2429:
    goto v_2430;
v_2431:
    goto v_2432;
v_2433:
    fn = elt(env, 4); // mcharg1
    v_2495 = (*qfnn(fn))(fn, 3, v_2497, v_2496, v_2495);
    env = stack[-5];
    stack[-2] = v_2495;
    v_2495 = stack[-2];
    fn = elt(env, 6); // lastpair
    v_2495 = (*qfn1(fn))(fn, v_2495);
    env = stack[-5];
    stack[-1] = v_2495;
    v_2495 = stack[-4];
    v_2495 = qcdr(v_2495);
    stack[-4] = v_2495;
    v_2495 = stack[-1];
    if (!consp(v_2495)) goto v_2446;
    else goto v_2447;
v_2446:
    goto v_2408;
v_2447:
v_2409:
    v_2495 = stack[-4];
    if (v_2495 == nil) goto v_2451;
    else goto v_2452;
v_2451:
    v_2495 = stack[-2];
    goto v_2407;
v_2452:
    goto v_2460;
v_2456:
    stack[0] = stack[-1];
    goto v_2457;
v_2458:
    v_2495 = stack[-4];
    v_2495 = qcar(v_2495);
    goto v_2472;
v_2466:
    v_2496 = v_2495;
    v_2497 = qcar(v_2496);
    goto v_2467;
v_2468:
    v_2496 = qcdr(v_2495);
    goto v_2469;
v_2470:
    v_2495 = stack[-3];
    goto v_2471;
v_2472:
    goto v_2466;
v_2467:
    goto v_2468;
v_2469:
    goto v_2470;
v_2471:
    fn = elt(env, 4); // mcharg1
    v_2495 = (*qfnn(fn))(fn, 3, v_2497, v_2496, v_2495);
    env = stack[-5];
    goto v_2459;
v_2460:
    goto v_2456;
v_2457:
    goto v_2458;
v_2459:
    v_2495 = Lrplacd(nil, stack[0], v_2495);
    env = stack[-5];
    v_2495 = stack[-1];
    fn = elt(env, 6); // lastpair
    v_2495 = (*qfn1(fn))(fn, v_2495);
    env = stack[-5];
    stack[-1] = v_2495;
    v_2495 = stack[-4];
    v_2495 = qcdr(v_2495);
    stack[-4] = v_2495;
    goto v_2409;
v_2407:
    goto v_2360;
v_2390:
    goto v_2491;
v_2485:
    goto v_2486;
v_2487:
    v_2496 = stack[0];
    goto v_2488;
v_2489:
    v_2495 = stack[-3];
    goto v_2490;
v_2491:
    goto v_2485;
v_2486:
    goto v_2487;
v_2488:
    goto v_2489;
v_2490:
    {
        fn = elt(env, 4); // mcharg1
        return (*qfnn(fn))(fn, 3, v_2497, v_2496, v_2495);
    }
    v_2495 = nil;
v_2360:
    return onevalue(v_2495);
}



// Code for talp_tcfrp

static LispObject CC_talp_tcfrp(LispObject env,
                         LispObject v_2355)
{
    env = qenv(env);
    LispObject v_2368, v_2369;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2355);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2355);
    }
// copy arguments values to proper place
    v_2369 = v_2355;
// end of prologue
    v_2368 = v_2369;
    if (!consp(v_2368)) goto v_2359;
    else goto v_2360;
v_2359:
    v_2368 = lisp_true;
    goto v_2358;
v_2360:
    v_2368 = v_2369;
    fn = elt(env, 1); // talp_invp
    v_2368 = (*qfn1(fn))(fn, v_2368);
    goto v_2358;
    v_2368 = nil;
v_2358:
    v_2368 = (v_2368 == nil ? lisp_true : nil);
    return onevalue(v_2368);
}



// Code for omobjs

static LispObject CC_omobjs(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2398, v_2399;
    LispObject fn;
    argcheck(nargs, 0, "omobjs");
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
    goto v_2368;
v_2364:
    v_2399 = qvalue(elt(env, 1)); // char
    goto v_2365;
v_2366:
    v_2398 = elt(env, 2); // (!/ o m a)
    goto v_2367;
v_2368:
    goto v_2364;
v_2365:
    goto v_2366;
v_2367:
    if (equal(v_2399, v_2398)) goto v_2363;
    fn = elt(env, 3); // omobj
    v_2398 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_2398;
    fn = elt(env, 4); // lex
    v_2398 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_2398 = CC_omobjs(elt(env, 0), 0);
    v_2399 = stack[0];
    if (v_2399 == nil) goto v_2376;
    else goto v_2377;
v_2376:
    goto v_2384;
v_2380:
    v_2399 = stack[0];
    goto v_2381;
v_2382:
    goto v_2383;
v_2384:
    goto v_2380;
v_2381:
    goto v_2382;
v_2383:
        return Lappend(nil, v_2399, v_2398);
v_2377:
    goto v_2394;
v_2390:
    v_2399 = stack[0];
    goto v_2391;
v_2392:
    goto v_2393;
v_2394:
    goto v_2390;
v_2391:
    goto v_2392;
v_2393:
    return cons(v_2399, v_2398);
    goto v_2361;
v_2363:
v_2361:
    v_2398 = nil;
    return onevalue(v_2398);
}



setup_type const u07_setup[] =
{
    {"raddf",                   TOO_FEW_2,      CC_raddf,      WRONG_NO_2},
    {"talp_varlt1",             TOO_FEW_2,      CC_talp_varlt1,WRONG_NO_2},
    {"mri_simplfloor",          CC_mri_simplfloor,TOO_MANY_1,  WRONG_NO_1},
    {"rl_simpat",               CC_rl_simpat,   TOO_MANY_1,    WRONG_NO_1},
    {"ev_invlexcomp",           TOO_FEW_2,      CC_ev_invlexcomp,WRONG_NO_2},
    {"quotfd",                  TOO_FEW_2,      CC_quotfd,     WRONG_NO_2},
    {"find",                    CC_find,        TOO_MANY_1,    WRONG_NO_1},
    {"freexp",                  CC_freexp,      TOO_MANY_1,    WRONG_NO_1},
    {"prepd",                   CC_prepd,       TOO_MANY_1,    WRONG_NO_1},
    {"diplength",               CC_diplength,   TOO_MANY_1,    WRONG_NO_1},
    {"quotematrix",             CC_quotematrix, TOO_MANY_1,    WRONG_NO_1},
    {"deg*farg",                CC_degHfarg,    TOO_MANY_1,    WRONG_NO_1},
    {"round:mt",                TOO_FEW_2,      CC_roundTmt,   WRONG_NO_2},
    {"gizerop:",                CC_gizeropT,    TOO_MANY_1,    WRONG_NO_1},
    {"red-char-downcase",       CC_redKcharKdowncase,TOO_MANY_1,WRONG_NO_1},
    {"repeatsp",                CC_repeatsp,    TOO_MANY_1,    WRONG_NO_1},
    {"red_divtestbe",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_red_divtestbe},
    {"resimp1",                 CC_resimp1,     TOO_MANY_1,    WRONG_NO_1},
    {"pappl_pv",                TOO_FEW_2,      CC_pappl_pv,   WRONG_NO_2},
    {"*modular2f",              CC_Hmodular2f,  TOO_MANY_1,    WRONG_NO_1},
    {"exptmod:",                TOO_FEW_2,      CC_exptmodT,   WRONG_NO_2},
    {"lalr_add_goto",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lalr_add_goto},
    {"gcdf1",                   TOO_FEW_2,      CC_gcdf1,      WRONG_NO_2},
    {"talp_smupdknowl",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_smupdknowl},
    {"kernord",                 TOO_FEW_2,      CC_kernord,    WRONG_NO_2},
    {"powers2",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_powers2},
    {"simp*",                   CC_simpH,       TOO_MANY_1,    WRONG_NO_1},
    {"downwght",                TOO_FEW_2,      CC_downwght,   WRONG_NO_2},
    {"termordp",                TOO_FEW_2,      CC_termordp,   WRONG_NO_2},
    {"make-set",                CC_makeKset,    TOO_MANY_1,    WRONG_NO_1},
    {":plus",                   TOO_FEW_2,      CC_Tplus,      WRONG_NO_2},
    {"optype",                  CC_optype,      TOO_MANY_1,    WRONG_NO_1},
    {"macrochk",                TOO_FEW_2,      CC_macrochk,   WRONG_NO_2},
    {"groeb=testa",             TOO_FEW_2,      CC_groebMtesta,WRONG_NO_2},
    {"gperm2",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gperm2},
    {"*i2ar",                   CC_Hi2ar,       TOO_MANY_1,    WRONG_NO_1},
    {"general-modular-minus",   CC_generalKmodularKminus,TOO_MANY_1,WRONG_NO_1},
    {"convprec*",               CC_convprecH,   TOO_MANY_1,    WRONG_NO_1},
    {"lalr_remove_duplicates",  CC_lalr_remove_duplicates,TOO_MANY_1,WRONG_NO_1},
    {"sgn",                     CC_sgn,         TOO_MANY_1,    WRONG_NO_1},
    {"sfto_gcdf",               TOO_FEW_2,      CC_sfto_gcdf,  WRONG_NO_2},
    {"cl_atfp",                 CC_cl_atfp,     TOO_MANY_1,    WRONG_NO_1},
    {"qqe_id-nyt-branchb",      CC_qqe_idKnytKbranchb,TOO_MANY_1,WRONG_NO_1},
    {"ibalp_calcmom",           CC_ibalp_calcmom,TOO_MANY_1,   WRONG_NO_1},
    {"multi_elem",              CC_multi_elem,  TOO_MANY_1,    WRONG_NO_1},
    {"rationalizei",            CC_rationalizei,TOO_MANY_1,    WRONG_NO_1},
    {"mintype",                 CC_mintype,     TOO_MANY_1,    WRONG_NO_1},
    {"nextarg",                 CC_nextarg,     TOO_MANY_1,    WRONG_NO_1},
    {"layout-formula",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_layoutKformula},
    {"abs:",                    CC_absT,        TOO_MANY_1,    WRONG_NO_1},
    {"setcloc*",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setclocH},
    {"mv-pow-mv-term-+",        TOO_FEW_2,      CC_mvKpowKmvKtermKL,WRONG_NO_2},
    {"rnplus:",                 TOO_FEW_2,      CC_rnplusT,    WRONG_NO_2},
    {"lalr_analyze_lookaheads", WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lalr_analyze_lookaheads},
    {"sfto_davp",               TOO_FEW_2,      CC_sfto_davp,  WRONG_NO_2},
    {"powers1",                 CC_powers1,     TOO_MANY_1,    WRONG_NO_1},
    {"mcharg",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mcharg},
    {"talp_tcfrp",              CC_talp_tcfrp,  TOO_MANY_1,    WRONG_NO_1},
    {"omobjs",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_omobjs},
    {NULL, (one_args *)"u07", (two_args *)"103358 3525028 9399999", 0}
};

// end of generated code
