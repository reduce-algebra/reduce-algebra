
// $destdir/u32.c        Machine generated C code

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



// Code for lex_basic_token

static LispObject CC_lex_basic_token(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18195, v_18196, v_18197;
    LispObject fn;
    argcheck(nargs, 0, "lex_basic_token");
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
    stack_popper stack_popper_var(6);
// end of prologue
v_16955:
    stack[-4] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    v_18195 = qvalue(elt(env, 1)); // lex_peeked
    if (v_18195 == nil) goto v_16965;
    v_18195 = qvalue(elt(env, 1)); // lex_peeked
    stack[-4] = v_18195;
    v_18195 = qvalue(elt(env, 2)); // lex_peeked_yylval
    qvalue(elt(env, 3)) = v_18195; // yylval
    v_18195 = qvalue(elt(env, 4)); // lex_peeked_escaped
    qvalue(elt(env, 5)) = v_18195; // lex_escaped
    v_18195 = nil;
    qvalue(elt(env, 4)) = v_18195; // lex_peeked_escaped
    qvalue(elt(env, 2)) = v_18195; // lex_peeked_yylval
    qvalue(elt(env, 1)) = v_18195; // lex_peeked
    v_18195 = stack[-4];
    goto v_16961;
v_16965:
    v_18195 = nil;
    qvalue(elt(env, 5)) = v_18195; // lex_escaped
v_16975:
    goto v_16988;
v_16984:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_16985;
v_16986:
    v_18195 = elt(env, 7); // ! 
    goto v_16987;
v_16988:
    goto v_16984;
v_16985:
    goto v_16986;
v_16987:
    if (v_18196 == v_18195) goto v_16982;
    else goto v_16983;
v_16982:
    v_18195 = lisp_true;
    goto v_16981;
v_16983:
    goto v_17002;
v_16998:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_16999;
v_17000:
    v_18195 = qvalue(elt(env, 8)); // !$eol!$
    goto v_17001;
v_17002:
    goto v_16998;
v_16999:
    goto v_17000;
v_17001:
    if (equal(v_18196, v_18195)) goto v_16996;
    else goto v_16997;
v_16996:
    v_18195 = lisp_true;
    goto v_16995;
v_16997:
    goto v_17016;
v_17012:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17013;
v_17014:
    v_18195 = elt(env, 9); // !	
    goto v_17015;
v_17016:
    goto v_17012;
v_17013:
    goto v_17014;
v_17015:
    if (v_18196 == v_18195) goto v_17010;
    else goto v_17011;
v_17010:
    v_18195 = lisp_true;
    goto v_17009;
v_17011:
    v_18195 = qvalue(elt(env, 6)); // lex_char
    fn = elt(env, 46); // lex_start_line_comment
    v_18195 = (*qfn1(fn))(fn, v_18195);
    env = stack[-5];
    if (v_18195 == nil) goto v_17027;
    else goto v_17028;
v_17027:
    v_18195 = nil;
    goto v_17026;
v_17028:
    fn = elt(env, 47); // lex_skip_line_comment
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17026;
    v_18195 = nil;
v_17026:
    if (v_18195 == nil) goto v_17024;
    else goto v_17023;
v_17024:
    v_18195 = qvalue(elt(env, 6)); // lex_char
    fn = elt(env, 48); // lex_start_block_comment
    v_18195 = (*qfn1(fn))(fn, v_18195);
    env = stack[-5];
    if (v_18195 == nil) goto v_17037;
    else goto v_17038;
v_17037:
    v_18195 = nil;
    goto v_17036;
v_17038:
    fn = elt(env, 49); // lex_skip_block_comment
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17036;
    v_18195 = nil;
v_17036:
v_17023:
    goto v_17009;
    v_18195 = nil;
v_17009:
    goto v_16995;
    v_18195 = nil;
v_16995:
    goto v_16981;
    v_18195 = nil;
v_16981:
    if (v_18195 == nil) goto v_16978;
    else goto v_16979;
v_16978:
    goto v_16974;
v_16979:
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_16975;
v_16974:
    goto v_17055;
v_17051:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17052;
v_17053:
    v_18195 = qvalue(elt(env, 10)); // !$eof!$
    goto v_17054;
v_17055:
    goto v_17051;
v_17052:
    goto v_17053;
v_17054:
    if (equal(v_18196, v_18195)) goto v_17049;
    else goto v_17050;
v_17049:
    v_18195 = qvalue(elt(env, 6)); // lex_char
    qvalue(elt(env, 3)) = v_18195; // yylval
    v_18195 = qvalue(elt(env, 11)); // lex_eof_code
    goto v_16961;
v_17050:
    v_18195 = qvalue(elt(env, 6)); // lex_char
    fn = elt(env, 51); // lexer_word_starter
    v_18195 = (*qfn1(fn))(fn, v_18195);
    env = stack[-5];
    if (v_18195 == nil) goto v_17064;
    else goto v_17062;
v_17064:
    goto v_17076;
v_17072:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17073;
v_17074:
    v_18195 = elt(env, 12); // !!
    goto v_17075;
v_17076:
    goto v_17072;
v_17073:
    goto v_17074;
v_17075:
    if (v_18196 == v_18195) goto v_17070;
    else goto v_17071;
v_17070:
    goto v_17089;
v_17085:
    v_18196 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17086;
v_17087:
    v_18195 = (LispObject)524288+TAG_FIXNUM; // 32768
    goto v_17088;
v_17089:
    goto v_17085;
v_17086:
    goto v_17087;
v_17088:
    fn = elt(env, 52); // land
    v_18195 = (*qfn2(fn))(fn, v_18196, v_18195);
    env = stack[-5];
    v_18195 = (LispObject)zerop(v_18195);
    v_18195 = v_18195 ? lisp_true : nil;
    env = stack[-5];
    if (v_18195 == nil) goto v_17081;
    else goto v_17082;
v_17081:
    v_18196 = nil;
    v_18195 = nil;
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=14 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 14, -1);
    qvalue(elt(env, 14)) = v_18196; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 15, 0);
    qvalue(elt(env, 15)) = v_18195; // !*lower
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    v_18195 = lisp_true;
    qvalue(elt(env, 5)) = v_18195; // lex_escaped
    goto v_17080;
v_17082:
    v_18195 = nil;
    goto v_17080;
    v_18195 = nil;
v_17080:
    goto v_17069;
v_17071:
    v_18195 = nil;
    goto v_17069;
    v_18195 = nil;
v_17069:
    if (v_18195 == nil) goto v_17067;
    else goto v_17062;
v_17067:
    goto v_17063;
v_17062:
    goto v_17109;
v_17105:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17106;
v_17107:
    v_18195 = stack[-4];
    goto v_17108;
v_17109:
    goto v_17105;
v_17106:
    goto v_17107;
v_17108:
    v_18195 = cons(v_18196, v_18195);
    env = stack[-5];
    stack[-4] = v_18195;
v_17114:
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    fn = elt(env, 53); // lexer_word_continues
    v_18195 = (*qfn1(fn))(fn, v_18195);
    env = stack[-5];
    if (v_18195 == nil) goto v_17119;
    else goto v_17118;
v_17119:
    goto v_17131;
v_17127:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17128;
v_17129:
    v_18195 = elt(env, 12); // !!
    goto v_17130;
v_17131:
    goto v_17127;
v_17128:
    goto v_17129;
v_17130:
    if (v_18196 == v_18195) goto v_17125;
    else goto v_17126;
v_17125:
    goto v_17144;
v_17140:
    v_18196 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17141;
v_17142:
    v_18195 = (LispObject)524288+TAG_FIXNUM; // 32768
    goto v_17143;
v_17144:
    goto v_17140;
v_17141:
    goto v_17142;
v_17143:
    fn = elt(env, 52); // land
    v_18195 = (*qfn2(fn))(fn, v_18196, v_18195);
    env = stack[-5];
    v_18195 = (LispObject)zerop(v_18195);
    v_18195 = v_18195 ? lisp_true : nil;
    env = stack[-5];
    if (v_18195 == nil) goto v_17136;
    else goto v_17137;
v_17136:
    v_18196 = nil;
    v_18195 = nil;
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=14 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 14, -1);
    qvalue(elt(env, 14)) = v_18196; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 15, 0);
    qvalue(elt(env, 15)) = v_18195; // !*lower
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    v_18195 = lisp_true;
    qvalue(elt(env, 5)) = v_18195; // lex_escaped
    goto v_17135;
v_17137:
    v_18195 = nil;
    goto v_17135;
    v_18195 = nil;
v_17135:
    goto v_17124;
v_17126:
    v_18195 = nil;
    goto v_17124;
    v_18195 = nil;
v_17124:
    if (v_18195 == nil) goto v_17122;
    else goto v_17118;
v_17122:
    goto v_17113;
v_17118:
    goto v_17165;
v_17161:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17162;
v_17163:
    v_18195 = stack[-4];
    goto v_17164;
v_17165:
    goto v_17161;
v_17162:
    goto v_17163;
v_17164:
    v_18195 = cons(v_18196, v_18195);
    env = stack[-5];
    stack[-4] = v_18195;
    goto v_17114;
v_17113:
    v_18195 = stack[-4];
    v_18195 = Lnreverse(nil, v_18195);
    env = stack[-5];
    stack[-4] = v_18195;
    fn = elt(env, 54); // list2widestring
    v_18195 = (*qfn1(fn))(fn, v_18195);
    env = stack[-5];
    v_18195 = Lintern(nil, v_18195);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18195; // yylval
    goto v_17184;
v_17180:
    v_18196 = qvalue(elt(env, 3)); // yylval
    goto v_17181;
v_17182:
    v_18195 = elt(env, 16); // comment
    goto v_17183;
v_17184:
    goto v_17180;
v_17181:
    goto v_17182;
v_17183:
    if (v_18196 == v_18195) goto v_17178;
    else goto v_17179;
v_17178:
    goto v_17197;
v_17193:
    v_18196 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17194;
v_17195:
    v_18195 = (LispObject)4194304+TAG_FIXNUM; // 262144
    goto v_17196;
v_17197:
    goto v_17193;
v_17194:
    goto v_17195;
v_17196:
    fn = elt(env, 52); // land
    v_18195 = (*qfn2(fn))(fn, v_18196, v_18195);
    env = stack[-5];
    v_18195 = (LispObject)zerop(v_18195);
    v_18195 = v_18195 ? lisp_true : nil;
    env = stack[-5];
    if (v_18195 == nil) goto v_17189;
    else goto v_17190;
v_17189:
    v_18195 = qvalue(elt(env, 5)); // lex_escaped
    v_18195 = (v_18195 == nil ? lisp_true : nil);
    goto v_17188;
v_17190:
    v_18195 = nil;
    goto v_17188;
    v_18195 = nil;
v_17188:
    goto v_17177;
v_17179:
    v_18195 = nil;
    goto v_17177;
    v_18195 = nil;
v_17177:
    if (v_18195 == nil) goto v_17175;
v_17210:
    goto v_17223;
v_17219:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17220;
v_17221:
    v_18195 = elt(env, 17); // !;
    goto v_17222;
v_17223:
    goto v_17219;
v_17220:
    goto v_17221;
v_17222:
    if (v_18196 == v_18195) goto v_17217;
    else goto v_17218;
v_17217:
    v_18195 = lisp_true;
    goto v_17216;
v_17218:
    goto v_17233;
v_17229:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17230;
v_17231:
    v_18195 = elt(env, 18); // !$
    goto v_17232;
v_17233:
    goto v_17229;
v_17230:
    goto v_17231;
v_17232:
    v_18195 = (v_18196 == v_18195 ? lisp_true : nil);
    goto v_17216;
    v_18195 = nil;
v_17216:
    if (v_18195 == nil) goto v_17214;
    goto v_17209;
v_17214:
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17210;
v_17209:
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_16955;
v_17175:
    v_18195 = qvalue(elt(env, 5)); // lex_escaped
    if (v_18195 == nil) goto v_17247;
    else goto v_17248;
v_17247:
    goto v_17255;
v_17251:
    v_18196 = qvalue(elt(env, 3)); // yylval
    goto v_17252;
v_17253:
    v_18195 = elt(env, 19); // lex_code
    goto v_17254;
v_17255:
    goto v_17251;
v_17252:
    goto v_17253;
v_17254:
    v_18195 = get(v_18196, v_18195);
    env = stack[-5];
    stack[-3] = v_18195;
    goto v_17246;
v_17248:
    v_18195 = nil;
    goto v_17246;
    v_18195 = nil;
v_17246:
    if (v_18195 == nil) goto v_17244;
    v_18195 = stack[-3];
    goto v_16961;
v_17244:
    goto v_17273;
v_17269:
    v_18196 = stack[-4];
    goto v_17270;
v_17271:
    v_18195 = elt(env, 20); // !'
    goto v_17272;
v_17273:
    goto v_17269;
v_17270:
    goto v_17271;
v_17272:
    if (!consp(v_18196)) goto v_17267;
    v_18196 = qcar(v_18196);
    if (v_18196 == v_18195) goto v_17266;
    else goto v_17267;
v_17266:
    v_18195 = lisp_true;
    goto v_17265;
v_17267:
    goto v_17284;
v_17280:
    v_18196 = stack[-4];
    goto v_17281;
v_17282:
    v_18195 = elt(env, 21); // lex_is_typename
    goto v_17283;
v_17284:
    goto v_17280;
v_17281:
    goto v_17282;
v_17283:
    v_18195 = get(v_18196, v_18195);
    env = stack[-5];
    goto v_17265;
    v_18195 = nil;
v_17265:
    if (v_18195 == nil) goto v_17263;
    v_18195 = qvalue(elt(env, 22)); // lex_typename_code
    goto v_16961;
v_17263:
    v_18195 = qvalue(elt(env, 23)); // lex_symbol_code
    goto v_16961;
    goto v_17061;
v_17063:
    v_18195 = qvalue(elt(env, 6)); // lex_char
    v_18195 = Ldigitp(nil, v_18195);
    env = stack[-5];
    if (v_18195 == nil) goto v_17293;
    else goto v_17291;
v_17293:
    goto v_17305;
v_17301:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17302;
v_17303:
    v_18195 = elt(env, 24); // !~
    goto v_17304;
v_17305:
    goto v_17301;
v_17302:
    goto v_17303;
v_17304:
    if (v_18196 == v_18195) goto v_17299;
    else goto v_17300;
v_17299:
    goto v_17318;
v_17314:
    v_18196 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17315;
v_17316:
    v_18195 = (LispObject)2097152+TAG_FIXNUM; // 131072
    goto v_17317;
v_17318:
    goto v_17314;
v_17315:
    goto v_17316;
v_17317:
    fn = elt(env, 52); // land
    v_18195 = (*qfn2(fn))(fn, v_18196, v_18195);
    env = stack[-5];
    v_18195 = (LispObject)zerop(v_18195);
    v_18195 = v_18195 ? lisp_true : nil;
    env = stack[-5];
    if (v_18195 == nil) goto v_17310;
    else goto v_17311;
v_17310:
    fn = elt(env, 55); // yypeek
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18195 = Ldigitp(nil, v_18195);
    env = stack[-5];
    goto v_17309;
v_17311:
    v_18195 = nil;
    goto v_17309;
    v_18195 = nil;
v_17309:
    goto v_17298;
v_17300:
    v_18195 = nil;
    goto v_17298;
    v_18195 = nil;
v_17298:
    if (v_18195 == nil) goto v_17296;
    else goto v_17291;
v_17296:
    goto v_17292;
v_17291:
    goto v_17337;
v_17333:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17334;
v_17335:
    v_18195 = elt(env, 24); // !~
    goto v_17336;
v_17337:
    goto v_17333;
v_17334:
    goto v_17335;
v_17336:
    if (v_18196 == v_18195) goto v_17331;
    else goto v_17332;
v_17331:
    v_18195 = lisp_true;
    stack[-2] = v_18195;
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17330;
v_17332:
v_17330:
    goto v_17354;
v_17350:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17351;
v_17352:
    v_18195 = elt(env, 25); // !0
    goto v_17353;
v_17354:
    goto v_17350;
v_17351:
    goto v_17352;
v_17353:
    if (v_18196 == v_18195) goto v_17348;
    else goto v_17349;
v_17348:
    goto v_17365;
v_17361:
    fn = elt(env, 55); // yypeek
    v_18196 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17362;
v_17363:
    v_18195 = elt(env, 26); // x
    goto v_17364;
v_17365:
    goto v_17361;
v_17362:
    goto v_17363;
v_17364:
    if (v_18196 == v_18195) goto v_17359;
    else goto v_17360;
v_17359:
    v_18195 = lisp_true;
    goto v_17358;
v_17360:
    goto v_17375;
v_17371:
    fn = elt(env, 55); // yypeek
    v_18196 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17372;
v_17373:
    v_18195 = elt(env, 27); // !X
    goto v_17374;
v_17375:
    goto v_17371;
v_17372:
    goto v_17373;
v_17374:
    v_18195 = (v_18196 == v_18195 ? lisp_true : nil);
    goto v_17358;
    v_18195 = nil;
v_17358:
    goto v_17347;
v_17349:
    v_18195 = nil;
    goto v_17347;
    v_18195 = nil;
v_17347:
    if (v_18195 == nil) goto v_17345;
    v_18195 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 3)) = v_18195; // yylval
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
v_17386:
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    fn = elt(env, 56); // lex_hexval
    v_18195 = (*qfn1(fn))(fn, v_18195);
    env = stack[-5];
    stack[-3] = v_18195;
    if (v_18195 == nil) goto v_17389;
    else goto v_17390;
v_17389:
    goto v_17385;
v_17390:
    goto v_17399;
v_17395:
    goto v_17405;
v_17401:
    v_18196 = (LispObject)256+TAG_FIXNUM; // 16
    goto v_17402;
v_17403:
    v_18195 = qvalue(elt(env, 3)); // yylval
    goto v_17404;
v_17405:
    goto v_17401;
v_17402:
    goto v_17403;
v_17404:
    v_18196 = times2(v_18196, v_18195);
    env = stack[-5];
    goto v_17396;
v_17397:
    v_18195 = stack[-3];
    goto v_17398;
v_17399:
    goto v_17395;
v_17396:
    goto v_17397;
v_17398:
    v_18195 = plus2(v_18196, v_18195);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18195; // yylval
    goto v_17386;
v_17385:
    v_18195 = stack[-2];
    if (v_18195 == nil) goto v_17412;
    v_18195 = qvalue(elt(env, 3)); // yylval
    v_18195 = negate(v_18195);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18195; // yylval
    goto v_17410;
v_17412:
v_17410:
    v_18195 = qvalue(elt(env, 28)); // lex_number_code
    goto v_16961;
v_17345:
    v_18195 = qvalue(elt(env, 6)); // lex_char
    v_18195 = ncons(v_18195);
    env = stack[-5];
    stack[-4] = v_18195;
v_17421:
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18195 = qvalue(elt(env, 6)); // lex_char
    v_18195 = Ldigitp(nil, v_18195);
    env = stack[-5];
    if (v_18195 == nil) goto v_17424;
    else goto v_17425;
v_17424:
    goto v_17420;
v_17425:
    goto v_17435;
v_17431:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17432;
v_17433:
    v_18195 = stack[-4];
    goto v_17434;
v_17435:
    goto v_17431;
v_17432:
    goto v_17433;
v_17434:
    v_18195 = cons(v_18196, v_18195);
    env = stack[-5];
    stack[-4] = v_18195;
    goto v_17421;
v_17420:
    goto v_17446;
v_17442:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17443;
v_17444:
    v_18195 = elt(env, 29); // !.
    goto v_17445;
v_17446:
    goto v_17442;
v_17443:
    goto v_17444;
v_17445:
    if (v_18196 == v_18195) goto v_17440;
    else goto v_17441;
v_17440:
    v_18195 = lisp_true;
    stack[-3] = v_18195;
    goto v_17455;
v_17451:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17452;
v_17453:
    v_18195 = stack[-4];
    goto v_17454;
v_17455:
    goto v_17451;
v_17452:
    goto v_17453;
v_17454:
    v_18195 = cons(v_18196, v_18195);
    env = stack[-5];
    stack[-4] = v_18195;
v_17460:
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18195 = qvalue(elt(env, 6)); // lex_char
    v_18195 = Ldigitp(nil, v_18195);
    env = stack[-5];
    if (v_18195 == nil) goto v_17463;
    else goto v_17464;
v_17463:
    goto v_17459;
v_17464:
    goto v_17474;
v_17470:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17471;
v_17472:
    v_18195 = stack[-4];
    goto v_17473;
v_17474:
    goto v_17470;
v_17471:
    goto v_17472;
v_17473:
    v_18195 = cons(v_18196, v_18195);
    env = stack[-5];
    stack[-4] = v_18195;
    goto v_17460;
v_17459:
    goto v_17439;
v_17441:
v_17439:
    goto v_17489;
v_17485:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17486;
v_17487:
    v_18195 = elt(env, 30); // e
    goto v_17488;
v_17489:
    goto v_17485;
v_17486:
    goto v_17487;
v_17488:
    if (v_18196 == v_18195) goto v_17483;
    else goto v_17484;
v_17483:
    v_18195 = lisp_true;
    goto v_17482;
v_17484:
    goto v_17499;
v_17495:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17496;
v_17497:
    v_18195 = elt(env, 31); // !E
    goto v_17498;
v_17499:
    goto v_17495;
v_17496:
    goto v_17497;
v_17498:
    v_18195 = (v_18196 == v_18195 ? lisp_true : nil);
    goto v_17482;
    v_18195 = nil;
v_17482:
    if (v_18195 == nil) goto v_17480;
    v_18195 = stack[-3];
    if (v_18195 == nil) goto v_17505;
    else goto v_17506;
v_17505:
    goto v_17515;
v_17509:
    v_18197 = elt(env, 25); // !0
    goto v_17510;
v_17511:
    v_18196 = elt(env, 29); // !.
    goto v_17512;
v_17513:
    v_18195 = stack[-4];
    goto v_17514;
v_17515:
    goto v_17509;
v_17510:
    goto v_17511;
v_17512:
    goto v_17513;
v_17514:
    v_18195 = list2star(v_18197, v_18196, v_18195);
    env = stack[-5];
    stack[-4] = v_18195;
    goto v_17504;
v_17506:
v_17504:
    goto v_17525;
v_17521:
    v_18196 = elt(env, 30); // e
    goto v_17522;
v_17523:
    v_18195 = stack[-4];
    goto v_17524;
v_17525:
    goto v_17521;
v_17522:
    goto v_17523;
v_17524:
    v_18195 = cons(v_18196, v_18195);
    env = stack[-5];
    stack[-4] = v_18195;
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17541;
v_17537:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17538;
v_17539:
    v_18195 = elt(env, 32); // !+
    goto v_17540;
v_17541:
    goto v_17537;
v_17538:
    goto v_17539;
v_17540:
    if (v_18196 == v_18195) goto v_17535;
    else goto v_17536;
v_17535:
    v_18195 = lisp_true;
    goto v_17534;
v_17536:
    goto v_17551;
v_17547:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17548;
v_17549:
    v_18195 = elt(env, 33); // !-
    goto v_17550;
v_17551:
    goto v_17547;
v_17548:
    goto v_17549;
v_17550:
    v_18195 = (v_18196 == v_18195 ? lisp_true : nil);
    goto v_17534;
    v_18195 = nil;
v_17534:
    if (v_18195 == nil) goto v_17532;
    goto v_17560;
v_17556:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17557;
v_17558:
    v_18195 = stack[-4];
    goto v_17559;
v_17560:
    goto v_17556;
v_17557:
    goto v_17558;
v_17559:
    v_18195 = cons(v_18196, v_18195);
    env = stack[-5];
    stack[-4] = v_18195;
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17530;
v_17532:
v_17530:
    v_18195 = qvalue(elt(env, 6)); // lex_char
    v_18195 = Ldigitp(nil, v_18195);
    env = stack[-5];
    if (v_18195 == nil) goto v_17566;
    else goto v_17567;
v_17566:
    goto v_17575;
v_17571:
    v_18196 = elt(env, 25); // !0
    goto v_17572;
v_17573:
    v_18195 = stack[-4];
    goto v_17574;
v_17575:
    goto v_17571;
v_17572:
    goto v_17573;
v_17574:
    v_18195 = cons(v_18196, v_18195);
    env = stack[-5];
    stack[-4] = v_18195;
    goto v_17565;
v_17567:
    goto v_17585;
v_17581:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17582;
v_17583:
    v_18195 = stack[-4];
    goto v_17584;
v_17585:
    goto v_17581;
v_17582:
    goto v_17583;
v_17584:
    v_18195 = cons(v_18196, v_18195);
    env = stack[-5];
    stack[-4] = v_18195;
v_17590:
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18195 = qvalue(elt(env, 6)); // lex_char
    v_18195 = Ldigitp(nil, v_18195);
    env = stack[-5];
    if (v_18195 == nil) goto v_17593;
    else goto v_17594;
v_17593:
    goto v_17589;
v_17594:
    goto v_17604;
v_17600:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17601;
v_17602:
    v_18195 = stack[-4];
    goto v_17603;
v_17604:
    goto v_17600;
v_17601:
    goto v_17602;
v_17603:
    v_18195 = cons(v_18196, v_18195);
    env = stack[-5];
    stack[-4] = v_18195;
    goto v_17590;
v_17589:
    goto v_17565;
v_17565:
    goto v_17478;
v_17480:
v_17478:
    v_18195 = stack[-4];
    v_18195 = Lnreverse(nil, v_18195);
    env = stack[-5];
    v_18195 = Lcompress(nil, v_18195);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18195; // yylval
    v_18195 = stack[-2];
    if (v_18195 == nil) goto v_17613;
    v_18195 = qvalue(elt(env, 3)); // yylval
    v_18195 = negate(v_18195);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18195; // yylval
    goto v_17611;
v_17613:
v_17611:
    v_18195 = qvalue(elt(env, 28)); // lex_number_code
    goto v_16961;
v_17292:
    goto v_17628;
v_17624:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17625;
v_17626:
    v_18195 = elt(env, 34); // !"
    goto v_17627;
v_17628:
    goto v_17624;
v_17625:
    goto v_17626;
v_17627:
    if (v_18196 == v_18195) goto v_17622;
    else goto v_17623;
v_17622:
    goto v_17637;
v_17633:
    v_18196 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17634;
v_17635:
    v_18195 = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_17636;
v_17637:
    goto v_17633;
v_17634:
    goto v_17635;
v_17636:
    fn = elt(env, 52); // land
    v_18195 = (*qfn2(fn))(fn, v_18196, v_18195);
    env = stack[-5];
    v_18195 = (LispObject)zerop(v_18195);
    v_18195 = v_18195 ? lisp_true : nil;
    env = stack[-5];
    v_18195 = (v_18195 == nil ? lisp_true : nil);
    goto v_17621;
v_17623:
    v_18195 = nil;
    goto v_17621;
    v_18195 = nil;
v_17621:
    if (v_18195 == nil) goto v_17619;
    goto v_17654;
v_17650:
    v_18196 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17651;
v_17652:
    v_18195 = (LispObject)16384+TAG_FIXNUM; // 1024
    goto v_17653;
v_17654:
    goto v_17650;
v_17651:
    goto v_17652;
v_17653:
    fn = elt(env, 52); // land
    v_18195 = (*qfn2(fn))(fn, v_18196, v_18195);
    env = stack[-5];
    v_18195 = (LispObject)zerop(v_18195);
    v_18195 = v_18195 ? lisp_true : nil;
    env = stack[-5];
    if (v_18195 == nil) goto v_17646;
    else goto v_17647;
v_17646:
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=14 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 14, -1);
    qvalue(elt(env, 14)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 15, 0);
    qvalue(elt(env, 15)) = nil; // !*lower
v_17663:
    goto v_17676;
v_17672:
    fn = elt(env, 50); // yyreadch
    v_18196 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17673;
v_17674:
    v_18195 = elt(env, 34); // !"
    goto v_17675;
v_17676:
    goto v_17672;
v_17673:
    goto v_17674;
v_17675:
    if (v_18196 == v_18195) goto v_17671;
    v_18195 = lisp_true;
    goto v_17669;
v_17671:
    goto v_17690;
v_17686:
    fn = elt(env, 55); // yypeek
    v_18196 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17687;
v_17688:
    v_18195 = elt(env, 34); // !"
    goto v_17689;
v_17690:
    goto v_17686;
v_17687:
    goto v_17688;
v_17689:
    if (v_18196 == v_18195) goto v_17684;
    else goto v_17685;
v_17684:
    goto v_17697;
v_17693:
    fn = elt(env, 50); // yyreadch
    v_18196 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17694;
v_17695:
    v_18195 = elt(env, 34); // !"
    goto v_17696;
v_17697:
    goto v_17693;
v_17694:
    goto v_17695;
v_17696:
    v_18195 = (v_18196 == v_18195 ? lisp_true : nil);
    goto v_17683;
v_17685:
    v_18195 = nil;
    goto v_17683;
    v_18195 = nil;
v_17683:
    goto v_17669;
    v_18195 = nil;
v_17669:
    if (v_18195 == nil) goto v_17666;
    else goto v_17667;
v_17666:
    goto v_17662;
v_17667:
    goto v_17710;
v_17706:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17707;
v_17708:
    v_18195 = stack[-4];
    goto v_17709;
v_17710:
    goto v_17706;
v_17707:
    goto v_17708;
v_17709:
    v_18195 = cons(v_18196, v_18195);
    env = stack[-5];
    stack[-4] = v_18195;
    goto v_17663;
v_17662:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_17645;
v_17647:
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=14 saveloc=2
{   bind_fluid_stack bind_fluid_var(-5, 14, -2);
    qvalue(elt(env, 14)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 15, -1);
    qvalue(elt(env, 15)) = nil; // !*lower
    stack[0] = nil;
v_17722:
    goto v_17735;
v_17731:
    fn = elt(env, 50); // yyreadch
    v_18196 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17732;
v_17733:
    v_18195 = elt(env, 34); // !"
    goto v_17734;
v_17735:
    goto v_17731;
v_17732:
    goto v_17733;
v_17734:
    if (v_18196 == v_18195) goto v_17730;
    v_18195 = lisp_true;
    goto v_17728;
v_17730:
    goto v_17745;
v_17741:
    v_18196 = stack[0];
    goto v_17742;
v_17743:
    v_18195 = elt(env, 35); // !\ (backslash)
    goto v_17744;
v_17745:
    goto v_17741;
v_17742:
    goto v_17743;
v_17744:
    v_18195 = (v_18196 == v_18195 ? lisp_true : nil);
    goto v_17728;
    v_18195 = nil;
v_17728:
    if (v_18195 == nil) goto v_17725;
    else goto v_17726;
v_17725:
    goto v_17721;
v_17726:
    v_18195 = qvalue(elt(env, 6)); // lex_char
    stack[0] = v_18195;
    goto v_17756;
v_17752:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17753;
v_17754:
    v_18195 = stack[-4];
    goto v_17755;
v_17756:
    goto v_17752;
v_17753:
    goto v_17754;
v_17755:
    v_18195 = cons(v_18196, v_18195);
    env = stack[-5];
    stack[-4] = v_18195;
    goto v_17722;
v_17721:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_17645;
v_17645:
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18195 = stack[-4];
    v_18195 = Lnreverse(nil, v_18195);
    env = stack[-5];
    fn = elt(env, 54); // list2widestring
    v_18195 = (*qfn1(fn))(fn, v_18195);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18195; // yylval
    v_18195 = qvalue(elt(env, 36)); // lex_string_code
    goto v_16961;
v_17619:
    goto v_17774;
v_17770:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17771;
v_17772:
    v_18195 = elt(env, 20); // !'
    goto v_17773;
v_17774:
    goto v_17770;
v_17771:
    goto v_17772;
v_17773:
    if (v_18196 == v_18195) goto v_17768;
    else goto v_17769;
v_17768:
    goto v_17783;
v_17779:
    v_18196 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17780;
v_17781:
    v_18195 = (LispObject)4096+TAG_FIXNUM; // 256
    goto v_17782;
v_17783:
    goto v_17779;
v_17780:
    goto v_17781;
v_17782:
    fn = elt(env, 52); // land
    v_18195 = (*qfn2(fn))(fn, v_18196, v_18195);
    env = stack[-5];
    v_18195 = (LispObject)zerop(v_18195);
    v_18195 = v_18195 ? lisp_true : nil;
    env = stack[-5];
    v_18195 = (v_18195 == nil ? lisp_true : nil);
    goto v_17767;
v_17769:
    v_18195 = nil;
    goto v_17767;
    v_18195 = nil;
v_17767:
    if (v_18195 == nil) goto v_17765;
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=14 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 14, -1);
    qvalue(elt(env, 14)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 15, 0);
    qvalue(elt(env, 15)) = nil; // !*lower
v_17796:
v_17799:
    goto v_17808;
v_17804:
    fn = elt(env, 50); // yyreadch
    v_18196 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17805;
v_17806:
    v_18195 = elt(env, 20); // !'
    goto v_17807;
v_17808:
    goto v_17804;
v_17805:
    goto v_17806;
v_17807:
    if (v_18196 == v_18195) goto v_17802;
    else goto v_17803;
v_17802:
    goto v_17798;
v_17803:
    goto v_17817;
v_17813:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17814;
v_17815:
    v_18195 = stack[-4];
    goto v_17816;
v_17817:
    goto v_17813;
v_17814:
    goto v_17815;
v_17816:
    v_18195 = cons(v_18196, v_18195);
    env = stack[-5];
    stack[-4] = v_18195;
    goto v_17799;
v_17798:
    goto v_17825;
v_17821:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17822;
v_17823:
    v_18195 = stack[-4];
    goto v_17824;
v_17825:
    goto v_17821;
v_17822:
    goto v_17823;
v_17824:
    v_18195 = cons(v_18196, v_18195);
    env = stack[-5];
    stack[-4] = v_18195;
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17837;
v_17833:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17834;
v_17835:
    v_18195 = elt(env, 20); // !'
    goto v_17836;
v_17837:
    goto v_17833;
v_17834:
    goto v_17835;
v_17836:
    if (v_18196 == v_18195) goto v_17831;
    else goto v_17832;
v_17831:
    goto v_17796;
v_17832:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    v_18195 = stack[-4];
    v_18195 = qcdr(v_18195);
    v_18195 = Lnreverse(nil, v_18195);
    env = stack[-5];
    fn = elt(env, 54); // list2widestring
    v_18195 = (*qfn1(fn))(fn, v_18195);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18195; // yylval
    v_18195 = qvalue(elt(env, 37)); // lex_char_code
    goto v_16961;
v_17765:
    goto v_17855;
v_17851:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17852;
v_17853:
    v_18195 = elt(env, 20); // !'
    goto v_17854;
v_17855:
    goto v_17851;
v_17852:
    goto v_17853;
v_17854:
    if (v_18196 == v_18195) goto v_17849;
    else goto v_17850;
v_17849:
    goto v_17864;
v_17860:
    v_18196 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17861;
v_17862:
    v_18195 = (LispObject)4194304+TAG_FIXNUM; // 262144
    goto v_17863;
v_17864:
    goto v_17860;
v_17861:
    goto v_17862;
v_17863:
    fn = elt(env, 52); // land
    v_18195 = (*qfn2(fn))(fn, v_18196, v_18195);
    env = stack[-5];
    v_18195 = (LispObject)zerop(v_18195);
    v_18195 = v_18195 ? lisp_true : nil;
    env = stack[-5];
    v_18195 = (v_18195 == nil ? lisp_true : nil);
    goto v_17848;
v_17850:
    v_18195 = nil;
    goto v_17848;
    v_18195 = nil;
v_17848:
    if (v_18195 == nil) goto v_17846;
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    fn = elt(env, 57); // read_s_expression
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17878;
v_17874:
    v_18196 = elt(env, 38); // quote
    goto v_17875;
v_17876:
    v_18195 = qvalue(elt(env, 3)); // yylval
    goto v_17877;
v_17878:
    goto v_17874;
v_17875:
    goto v_17876;
v_17877:
    v_18195 = list2(v_18196, v_18195);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18195; // yylval
    v_18195 = qvalue(elt(env, 39)); // lex_list_code
    goto v_16961;
v_17846:
    goto v_17892;
v_17888:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_17889;
v_17890:
    v_18195 = elt(env, 40); // !`
    goto v_17891;
v_17892:
    goto v_17888;
v_17889:
    goto v_17890;
v_17891:
    if (v_18196 == v_18195) goto v_17886;
    else goto v_17887;
v_17886:
    goto v_17901;
v_17897:
    v_18196 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17898;
v_17899:
    v_18195 = (LispObject)4194304+TAG_FIXNUM; // 262144
    goto v_17900;
v_17901:
    goto v_17897;
v_17898:
    goto v_17899;
v_17900:
    fn = elt(env, 52); // land
    v_18195 = (*qfn2(fn))(fn, v_18196, v_18195);
    env = stack[-5];
    v_18195 = (LispObject)zerop(v_18195);
    v_18195 = v_18195 ? lisp_true : nil;
    env = stack[-5];
    v_18195 = (v_18195 == nil ? lisp_true : nil);
    goto v_17885;
v_17887:
    v_18195 = nil;
    goto v_17885;
    v_18195 = nil;
v_17885:
    if (v_18195 == nil) goto v_17883;
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    fn = elt(env, 57); // read_s_expression
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17915;
v_17911:
    v_18196 = elt(env, 41); // backquote
    goto v_17912;
v_17913:
    v_18195 = qvalue(elt(env, 3)); // yylval
    goto v_17914;
v_17915:
    goto v_17911;
v_17912:
    goto v_17913;
v_17914:
    v_18195 = list2(v_18196, v_18195);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18195; // yylval
    v_18195 = qvalue(elt(env, 39)); // lex_list_code
    goto v_16961;
v_17883:
    v_18195 = qvalue(elt(env, 6)); // lex_char
    qvalue(elt(env, 3)) = v_18195; // yylval
    goto v_17930;
v_17926:
    v_18196 = qvalue(elt(env, 3)); // yylval
    goto v_17927;
v_17928:
    v_18195 = qvalue(elt(env, 10)); // !$eof!$
    goto v_17929;
v_17930:
    goto v_17926;
v_17927:
    goto v_17928;
v_17929:
    if (equal(v_18196, v_18195)) goto v_17924;
    else goto v_17925;
v_17924:
    v_18195 = qvalue(elt(env, 11)); // lex_eof_code
    goto v_16961;
v_17925:
    goto v_17950;
v_17946:
    v_18196 = qvalue(elt(env, 3)); // yylval
    goto v_17947;
v_17948:
    v_18195 = elt(env, 42); // !#
    goto v_17949;
v_17950:
    goto v_17946;
v_17947:
    goto v_17948;
v_17949:
    if (v_18196 == v_18195) goto v_17944;
    else goto v_17945;
v_17944:
    goto v_17959;
v_17955:
    v_18196 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17956;
v_17957:
    v_18195 = (LispObject)1024+TAG_FIXNUM; // 64
    goto v_17958;
v_17959:
    goto v_17955;
v_17956:
    goto v_17957;
v_17958:
    fn = elt(env, 52); // land
    v_18195 = (*qfn2(fn))(fn, v_18196, v_18195);
    env = stack[-5];
    v_18195 = (LispObject)zerop(v_18195);
    v_18195 = v_18195 ? lisp_true : nil;
    env = stack[-5];
    v_18195 = (v_18195 == nil ? lisp_true : nil);
    goto v_17943;
v_17945:
    v_18195 = nil;
    goto v_17943;
    v_18195 = nil;
v_17943:
    if (v_18195 == nil) goto v_17941;
    v_18195 = lisp_true;
    goto v_17939;
v_17941:
    goto v_17977;
v_17973:
    v_18196 = qvalue(elt(env, 3)); // yylval
    goto v_17974;
v_17975:
    v_18195 = elt(env, 43); // lex_dipthong
    goto v_17976;
v_17977:
    goto v_17973;
v_17974:
    goto v_17975;
v_17976:
    v_18195 = get(v_18196, v_18195);
    env = stack[-5];
    if (v_18195 == nil) goto v_17971;
    else goto v_17970;
v_17971:
    goto v_17990;
v_17986:
    v_18196 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17987;
v_17988:
    v_18195 = (LispObject)2097152+TAG_FIXNUM; // 131072
    goto v_17989;
v_17990:
    goto v_17986;
v_17987:
    goto v_17988;
v_17989:
    fn = elt(env, 52); // land
    v_18195 = (*qfn2(fn))(fn, v_18196, v_18195);
    env = stack[-5];
    v_18195 = (LispObject)zerop(v_18195);
    v_18195 = v_18195 ? lisp_true : nil;
    env = stack[-5];
    if (v_18195 == nil) goto v_17982;
    else goto v_17983;
v_17982:
    goto v_17998;
v_17994:
    v_18196 = qvalue(elt(env, 3)); // yylval
    goto v_17995;
v_17996:
    v_18195 = elt(env, 44); // sml_opchar
    goto v_17997;
v_17998:
    goto v_17994;
v_17995:
    goto v_17996;
v_17997:
    v_18195 = Lflagp(nil, v_18196, v_18195);
    env = stack[-5];
    goto v_17981;
v_17983:
    v_18195 = nil;
    goto v_17981;
    v_18195 = nil;
v_17981:
v_17970:
    goto v_17939;
    v_18195 = nil;
v_17939:
    if (v_18195 == nil) goto v_17937;
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17935;
v_17937:
    v_18195 = elt(env, 7); // ! 
    qvalue(elt(env, 6)) = v_18195; // lex_char
    goto v_17935;
v_17935:
    goto v_18021;
v_18017:
    v_18196 = qvalue(elt(env, 3)); // yylval
    goto v_18018;
v_18019:
    v_18195 = elt(env, 42); // !#
    goto v_18020;
v_18021:
    goto v_18017;
v_18018:
    goto v_18019;
v_18020:
    if (v_18196 == v_18195) goto v_18015;
    else goto v_18016;
v_18015:
    goto v_18034;
v_18030:
    v_18196 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_18031;
v_18032:
    v_18195 = (LispObject)1024+TAG_FIXNUM; // 64
    goto v_18033;
v_18034:
    goto v_18030;
v_18031:
    goto v_18032;
v_18033:
    fn = elt(env, 52); // land
    v_18195 = (*qfn2(fn))(fn, v_18196, v_18195);
    env = stack[-5];
    v_18195 = (LispObject)zerop(v_18195);
    v_18195 = v_18195 ? lisp_true : nil;
    env = stack[-5];
    if (v_18195 == nil) goto v_18026;
    else goto v_18027;
v_18026:
    v_18195 = qvalue(elt(env, 6)); // lex_char
    v_18195 = Lalpha_char_p(nil, v_18195);
    env = stack[-5];
    goto v_18025;
v_18027:
    v_18195 = nil;
    goto v_18025;
    v_18195 = nil;
v_18025:
    goto v_18014;
v_18016:
    v_18195 = nil;
    goto v_18014;
    v_18195 = nil;
v_18014:
    if (v_18195 == nil) goto v_18012;
    else goto v_18010;
v_18012:
    goto v_18050;
v_18046:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_18047;
v_18048:
    v_18195 = elt(env, 12); // !!
    goto v_18049;
v_18050:
    goto v_18046;
v_18047:
    goto v_18048;
v_18049:
    if (v_18196 == v_18195) goto v_18010;
    goto v_18011;
v_18010:
    v_18195 = CC_lex_basic_token(elt(env, 0), 0);
    env = stack[-5];
    stack[-4] = v_18195;
    goto v_18062;
v_18058:
    v_18196 = qvalue(elt(env, 3)); // yylval
    goto v_18059;
v_18060:
    v_18195 = elt(env, 45); // (if else elif endif define eval)
    goto v_18061;
v_18062:
    goto v_18058;
v_18059:
    goto v_18060;
v_18061:
    v_18195 = Lmemq(nil, v_18196, v_18195);
    if (v_18195 == nil) goto v_18057;
    goto v_18073;
v_18069:
    stack[0] = elt(env, 42); // !#
    goto v_18070;
v_18071:
    v_18195 = qvalue(elt(env, 3)); // yylval
    v_18195 = Lsymbol_name(nil, v_18195);
    env = stack[-5];
    fn = elt(env, 58); // widestring2list
    v_18195 = (*qfn1(fn))(fn, v_18195);
    env = stack[-5];
    goto v_18072;
v_18073:
    goto v_18069;
v_18070:
    goto v_18071;
v_18072:
    v_18195 = cons(stack[0], v_18195);
    env = stack[-5];
    fn = elt(env, 54); // list2widestring
    v_18195 = (*qfn1(fn))(fn, v_18195);
    env = stack[-5];
    v_18195 = Lintern(nil, v_18195);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18195; // yylval
    goto v_18055;
v_18057:
    v_18195 = stack[-4];
    qvalue(elt(env, 1)) = v_18195; // lex_peeked
    v_18195 = qvalue(elt(env, 3)); // yylval
    qvalue(elt(env, 2)) = v_18195; // lex_peeked_yylval
    v_18195 = qvalue(elt(env, 5)); // lex_escaped
    qvalue(elt(env, 4)) = v_18195; // lex_peeked_escaped
    v_18195 = elt(env, 42); // !#
    qvalue(elt(env, 3)) = v_18195; // yylval
    v_18195 = nil;
    qvalue(elt(env, 5)) = v_18195; // lex_escaped
    goto v_18055;
v_18055:
    goto v_18009;
v_18011:
v_18009:
v_18087:
    goto v_18096;
v_18092:
    v_18197 = qvalue(elt(env, 6)); // lex_char
    goto v_18093;
v_18094:
    goto v_18103;
v_18099:
    v_18196 = qvalue(elt(env, 3)); // yylval
    goto v_18100;
v_18101:
    v_18195 = elt(env, 43); // lex_dipthong
    goto v_18102;
v_18103:
    goto v_18099;
v_18100:
    goto v_18101;
v_18102:
    v_18195 = get(v_18196, v_18195);
    env = stack[-5];
    goto v_18095;
v_18096:
    goto v_18092;
v_18093:
    goto v_18094;
v_18095:
    v_18195 = Latsoc(nil, v_18197, v_18195);
    stack[-3] = v_18195;
    if (v_18195 == nil) goto v_18090;
    else goto v_18091;
v_18090:
    goto v_18086;
v_18091:
    v_18195 = stack[-3];
    v_18195 = qcdr(v_18195);
    qvalue(elt(env, 3)) = v_18195; // yylval
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_18087;
v_18086:
    goto v_18125;
v_18121:
    v_18196 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_18122;
v_18123:
    v_18195 = (LispObject)2097152+TAG_FIXNUM; // 131072
    goto v_18124;
v_18125:
    goto v_18121;
v_18122:
    goto v_18123;
v_18124:
    fn = elt(env, 52); // land
    v_18195 = (*qfn2(fn))(fn, v_18196, v_18195);
    env = stack[-5];
    v_18195 = (LispObject)zerop(v_18195);
    v_18195 = v_18195 ? lisp_true : nil;
    env = stack[-5];
    if (v_18195 == nil) goto v_18117;
    else goto v_18118;
v_18117:
    v_18195 = qvalue(elt(env, 3)); // yylval
    v_18195 = Lexplodec(nil, v_18195);
    env = stack[-5];
    stack[-3] = v_18195;
    fn = elt(env, 59); // all_sml_opchar
    v_18195 = (*qfn1(fn))(fn, v_18195);
    env = stack[-5];
    goto v_18116;
v_18118:
    v_18195 = nil;
    goto v_18116;
    v_18195 = nil;
v_18116:
    if (v_18195 == nil) goto v_18114;
v_18136:
    goto v_18151;
v_18147:
    v_18196 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_18148;
v_18149:
    v_18195 = (LispObject)2097152+TAG_FIXNUM; // 131072
    goto v_18150;
v_18151:
    goto v_18147;
v_18148:
    goto v_18149;
v_18150:
    fn = elt(env, 52); // land
    v_18195 = (*qfn2(fn))(fn, v_18196, v_18195);
    env = stack[-5];
    v_18195 = (LispObject)zerop(v_18195);
    v_18195 = v_18195 ? lisp_true : nil;
    env = stack[-5];
    if (v_18195 == nil) goto v_18143;
    else goto v_18144;
v_18143:
    goto v_18159;
v_18155:
    v_18196 = qvalue(elt(env, 6)); // lex_char
    goto v_18156;
v_18157:
    v_18195 = elt(env, 44); // sml_opchar
    goto v_18158;
v_18159:
    goto v_18155;
v_18156:
    goto v_18157;
v_18158:
    v_18195 = Lflagp(nil, v_18196, v_18195);
    env = stack[-5];
    goto v_18142;
v_18144:
    v_18195 = nil;
    goto v_18142;
    v_18195 = nil;
v_18142:
    if (v_18195 == nil) goto v_18139;
    else goto v_18140;
v_18139:
    goto v_18135;
v_18140:
    goto v_18171;
v_18167:
    stack[0] = stack[-3];
    goto v_18168;
v_18169:
    v_18195 = qvalue(elt(env, 6)); // lex_char
    v_18195 = ncons(v_18195);
    env = stack[-5];
    goto v_18170;
v_18171:
    goto v_18167;
v_18168:
    goto v_18169;
v_18170:
    v_18195 = Lappend(nil, stack[0], v_18195);
    env = stack[-5];
    stack[-3] = v_18195;
    fn = elt(env, 50); // yyreadch
    v_18195 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_18136;
v_18135:
    v_18195 = stack[-3];
    fn = elt(env, 60); // list2string
    v_18195 = (*qfn1(fn))(fn, v_18195);
    env = stack[-5];
    v_18195 = Lintern(nil, v_18195);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18195; // yylval
    goto v_18112;
v_18114:
v_18112:
    goto v_18188;
v_18184:
    v_18196 = qvalue(elt(env, 3)); // yylval
    goto v_18185;
v_18186:
    v_18195 = elt(env, 19); // lex_code
    goto v_18187;
v_18188:
    goto v_18184;
v_18185:
    goto v_18186;
v_18187:
    v_18195 = get(v_18196, v_18195);
    env = stack[-5];
    stack[-3] = v_18195;
    if (v_18195 == nil) goto v_18182;
    v_18195 = stack[-3];
    goto v_16961;
v_18182:
    v_18195 = qvalue(elt(env, 23)); // lex_symbol_code
    goto v_16961;
    goto v_17061;
v_17061:
    v_18195 = nil;
v_16961:
    return onevalue(v_18195);
}



// Code for formproc

static LispObject CC_formproc(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17759, v_17760, v_17761, v_17762;
    LispObject fn;
    LispObject v_16958, v_16957, v_16956;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formproc");
    va_start(aa, nargs);
    v_16956 = va_arg(aa, LispObject);
    v_16957 = va_arg(aa, LispObject);
    v_16958 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_16958,v_16957,v_16956);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_16956,v_16957,v_16958);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-2] = v_16958;
    stack[-1] = v_16957;
    stack[0] = v_16956;
// end of prologue
// Binding fname!*
// FLUIDBIND: reloadenv=10 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-10, 1, -6);
    qvalue(elt(env, 1)) = nil; // fname!*
    stack[-8] = nil;
    v_17759 = stack[0];
    v_17759 = qcdr(v_17759);
    stack[0] = v_17759;
    v_17759 = stack[0];
    v_17759 = qcar(v_17759);
    qvalue(elt(env, 1)) = v_17759; // fname!*
    stack[-5] = v_17759;
    v_17759 = stack[0];
    v_17759 = qcdr(v_17759);
    v_17759 = qcar(v_17759);
    if (v_17759 == nil) goto v_16979;
    v_17759 = stack[0];
    v_17759 = qcdr(v_17759);
    v_17759 = qcar(v_17759);
    stack[-2] = v_17759;
    goto v_16977;
v_16979:
v_16977:
    v_17759 = stack[0];
    v_17759 = qcdr(v_17759);
    v_17759 = qcdr(v_17759);
    stack[0] = v_17759;
    v_17759 = stack[0];
    v_17759 = qcar(v_17759);
    qvalue(elt(env, 2)) = v_17759; // ftype!*
    stack[-4] = v_17759;
    v_17759 = stack[-5];
    if (!symbolp(v_17759)) v_17759 = nil;
    else { v_17759 = qfastgets(v_17759);
           if (v_17759 != nil) { v_17759 = elt(v_17759, 1); // lose
#ifdef RECORD_GET
             if (v_17759 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v_17759 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v_17759 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v_17759 == SPID_NOPROP) v_17759 = nil; else v_17759 = lisp_true; }}
#endif
    if (v_17759 == nil) goto v_16998;
    v_17759 = qvalue(elt(env, 3)); // !*lose
    if (v_17759 == nil) goto v_17003;
    else goto v_17002;
v_17003:
    v_17759 = qvalue(elt(env, 4)); // !*defn
    v_17759 = (v_17759 == nil ? lisp_true : nil);
v_17002:
    goto v_16996;
v_16998:
    v_17759 = nil;
    goto v_16996;
    v_17759 = nil;
v_16996:
    if (v_17759 == nil) goto v_16994;
    goto v_17016;
v_17012:
    v_17760 = stack[-5];
    goto v_17013;
v_17014:
    v_17759 = elt(env, 5); // "not defined (LOSE flag)"
    goto v_17015;
v_17016:
    goto v_17012;
v_17013:
    goto v_17014;
v_17015:
    v_17759 = list2(v_17760, v_17759);
    env = stack[-10];
    fn = elt(env, 47); // lprim
    v_17759 = (*qfn1(fn))(fn, v_17759);
    env = stack[-10];
    v_17759 = elt(env, 6); // (quote nil)
    goto v_16971;
v_16994:
    v_17759 = qvalue(elt(env, 7)); // !*redeflg!*
    if (v_17759 == nil) goto v_17021;
    v_17759 = stack[-5];
    fn = elt(env, 48); // getd
    v_17759 = (*qfn1(fn))(fn, v_17759);
    env = stack[-10];
    if (v_17759 == nil) goto v_17021;
    goto v_17033;
v_17029:
    v_17760 = stack[-5];
    goto v_17030;
v_17031:
    v_17759 = elt(env, 8); // "redefined"
    goto v_17032;
v_17033:
    goto v_17029;
v_17030:
    goto v_17031;
v_17032:
    v_17759 = list2(v_17760, v_17759);
    env = stack[-10];
    fn = elt(env, 47); // lprim
    v_17759 = (*qfn1(fn))(fn, v_17759);
    env = stack[-10];
    goto v_16992;
v_17021:
v_16992:
    v_17759 = stack[0];
    v_17759 = qcdr(v_17759);
    v_17759 = qcar(v_17759);
    stack[-3] = v_17759;
v_17041:
    v_17759 = stack[-3];
    if (v_17759 == nil) goto v_17044;
    else goto v_17045;
v_17044:
    goto v_17040;
v_17045:
    v_17759 = stack[-3];
    v_17759 = qcar(v_17759);
    if (v_17759 == nil) goto v_17054;
    else goto v_17055;
v_17054:
    v_17759 = lisp_true;
    goto v_17053;
v_17055:
    goto v_17065;
v_17061:
    v_17759 = stack[-3];
    v_17760 = qcar(v_17759);
    goto v_17062;
v_17063:
    v_17759 = lisp_true;
    goto v_17064;
v_17065:
    goto v_17061;
v_17062:
    goto v_17063;
v_17064:
    v_17759 = (v_17760 == v_17759 ? lisp_true : nil);
    goto v_17053;
    v_17759 = nil;
v_17053:
    if (v_17759 == nil) goto v_17051;
    v_17759 = stack[-3];
    v_17759 = qcar(v_17759);
    fn = elt(env, 49); // rsverr
    v_17759 = (*qfn1(fn))(fn, v_17759);
    env = stack[-10];
    goto v_17049;
v_17051:
v_17049:
    v_17759 = stack[-3];
    v_17759 = qcdr(v_17759);
    stack[-3] = v_17759;
    goto v_17041;
v_17040:
    v_17759 = stack[0];
    v_17759 = qcdr(v_17759);
    v_17759 = qcar(v_17759);
    stack[-3] = v_17759;
v_17080:
    v_17759 = stack[-3];
    if (v_17759 == nil) goto v_17083;
    else goto v_17084;
v_17083:
    goto v_17079;
v_17084:
    v_17759 = stack[-3];
    v_17759 = qcar(v_17759);
    v_17759 = Lsymbol_specialp(nil, v_17759);
    env = stack[-10];
    if (v_17759 == nil) goto v_17091;
    else goto v_17089;
v_17091:
    v_17759 = stack[-3];
    v_17759 = qcar(v_17759);
    v_17759 = Lsymbol_globalp(nil, v_17759);
    env = stack[-10];
    if (v_17759 == nil) goto v_17095;
    else goto v_17089;
v_17095:
    goto v_17090;
v_17089:
    goto v_17104;
v_17100:
    v_17759 = stack[-3];
    v_17760 = qcar(v_17759);
    goto v_17101;
v_17102:
    v_17759 = stack[-8];
    goto v_17103;
v_17104:
    goto v_17100;
v_17101:
    goto v_17102;
v_17103:
    v_17759 = cons(v_17760, v_17759);
    env = stack[-10];
    stack[-8] = v_17759;
    goto v_17088;
v_17090:
v_17088:
    v_17759 = stack[-3];
    v_17759 = qcdr(v_17759);
    stack[-3] = v_17759;
    goto v_17080;
v_17079:
    v_17759 = stack[0];
    v_17759 = qcdr(v_17759);
    v_17759 = qcar(v_17759);
    stack[-3] = v_17759;
    v_17759 = stack[0];
    v_17759 = qcdr(v_17759);
    v_17759 = qcdr(v_17759);
    v_17759 = qcar(v_17759);
    stack[-7] = v_17759;
    goto v_17126;
v_17122:
    v_17760 = stack[-7];
    goto v_17123;
v_17124:
    v_17759 = elt(env, 9); // rblock
    goto v_17125;
v_17126:
    goto v_17122;
v_17123:
    goto v_17124;
v_17125:
    if (!consp(v_17760)) goto v_17120;
    v_17760 = qcar(v_17760);
    if (v_17760 == v_17759) goto v_17119;
    else goto v_17120;
v_17119:
    v_17759 = stack[-7];
    v_17759 = qcdr(v_17759);
    v_17759 = qcar(v_17759);
    goto v_17118;
v_17120:
    v_17759 = nil;
    goto v_17118;
    v_17759 = nil;
v_17118:
    stack[0] = v_17759;
    goto v_17144;
v_17136:
    v_17762 = stack[-3];
    goto v_17137;
v_17138:
    v_17761 = stack[0];
    goto v_17139;
v_17140:
    v_17760 = stack[-1];
    goto v_17141;
v_17142:
    v_17759 = stack[-2];
    goto v_17143;
v_17144:
    goto v_17136;
v_17137:
    goto v_17138;
v_17139:
    goto v_17140;
v_17141:
    goto v_17142;
v_17143:
    fn = elt(env, 50); // pairxvars
    v_17759 = (*qfnn(fn))(fn, 4, v_17762, v_17761, v_17760, v_17759);
    env = stack[-10];
    stack[-1] = v_17759;
    v_17759 = stack[0];
    if (v_17759 == nil) goto v_17152;
    goto v_17159;
v_17155:
    v_17759 = stack[-7];
    stack[0] = qcar(v_17759);
    goto v_17156;
v_17157:
    goto v_17167;
v_17163:
    v_17759 = stack[-7];
    v_17760 = qcdr(v_17759);
    goto v_17164;
v_17165:
    v_17759 = stack[-1];
    v_17759 = qcdr(v_17759);
    goto v_17166;
v_17167:
    goto v_17163;
v_17164:
    goto v_17165;
v_17166:
    fn = elt(env, 51); // rplaca!*
    v_17759 = (*qfn2(fn))(fn, v_17760, v_17759);
    env = stack[-10];
    goto v_17158;
v_17159:
    goto v_17155;
v_17156:
    goto v_17157;
v_17158:
    v_17759 = cons(stack[0], v_17759);
    env = stack[-10];
    stack[-7] = v_17759;
    goto v_17150;
v_17152:
v_17150:
    goto v_17181;
v_17177:
    v_17760 = stack[-5];
    goto v_17178;
v_17179:
    v_17759 = elt(env, 10); // formc
    goto v_17180;
v_17181:
    goto v_17177;
v_17178:
    goto v_17179;
v_17180:
    v_17759 = Lflagp(nil, v_17760, v_17759);
    env = stack[-10];
    if (v_17759 == nil) goto v_17175;
    goto v_17191;
v_17185:
    v_17761 = stack[-7];
    goto v_17186;
v_17187:
    v_17759 = stack[-1];
    v_17760 = qcar(v_17759);
    goto v_17188;
v_17189:
    v_17759 = stack[-2];
    goto v_17190;
v_17191:
    goto v_17185;
v_17186:
    goto v_17187;
v_17188:
    goto v_17189;
v_17190:
    fn = elt(env, 10); // formc
    v_17759 = (*qfnn(fn))(fn, 3, v_17761, v_17760, v_17759);
    env = stack[-10];
    goto v_17173;
v_17175:
    goto v_17205;
v_17199:
    v_17761 = stack[-7];
    goto v_17200;
v_17201:
    v_17759 = stack[-1];
    v_17760 = qcar(v_17759);
    goto v_17202;
v_17203:
    v_17759 = stack[-2];
    goto v_17204;
v_17205:
    goto v_17199;
v_17200:
    goto v_17201;
v_17202:
    goto v_17203;
v_17204:
    fn = elt(env, 52); // form1
    v_17759 = (*qfnn(fn))(fn, 3, v_17761, v_17760, v_17759);
    env = stack[-10];
    goto v_17173;
    v_17759 = nil;
v_17173:
    stack[-7] = v_17759;
    v_17759 = qvalue(elt(env, 11)); // !*noinlines
    if (v_17759 == nil) goto v_17213;
    goto v_17221;
v_17217:
    v_17760 = stack[-4];
    goto v_17218;
v_17219:
    v_17759 = elt(env, 12); // inline
    goto v_17220;
v_17221:
    goto v_17217;
v_17218:
    goto v_17219;
v_17220:
    if (v_17760 == v_17759) goto v_17216;
    else goto v_17213;
v_17216:
    v_17759 = elt(env, 13); // expr
    stack[-4] = v_17759;
    goto v_17211;
v_17213:
v_17211:
    v_17759 = stack[-8];
    if (v_17759 == nil) goto v_17228;
    goto v_17236;
v_17232:
    v_17760 = stack[-4];
    goto v_17233;
v_17234:
    v_17759 = elt(env, 14); // (expr fexpr macro)
    goto v_17235;
v_17236:
    goto v_17232;
v_17233:
    goto v_17234;
v_17235:
    v_17759 = Lmemq(nil, v_17760, v_17759);
    if (v_17759 == nil) goto v_17228;
    goto v_17247;
v_17241:
    stack[-1] = elt(env, 15); // progn
    goto v_17242;
v_17243:
    goto v_17254;
v_17250:
    stack[0] = elt(env, 16); // declare
    goto v_17251;
v_17252:
    goto v_17261;
v_17257:
    v_17760 = elt(env, 17); // special
    goto v_17258;
v_17259:
    v_17759 = stack[-8];
    goto v_17260;
v_17261:
    goto v_17257;
v_17258:
    goto v_17259;
v_17260:
    v_17759 = cons(v_17760, v_17759);
    env = stack[-10];
    goto v_17253;
v_17254:
    goto v_17250;
v_17251:
    goto v_17252;
v_17253:
    v_17760 = list2(stack[0], v_17759);
    env = stack[-10];
    goto v_17244;
v_17245:
    v_17759 = stack[-7];
    goto v_17246;
v_17247:
    goto v_17241;
v_17242:
    goto v_17243;
v_17244:
    goto v_17245;
v_17246:
    v_17759 = list3(stack[-1], v_17760, v_17759);
    env = stack[-10];
    stack[-7] = v_17759;
    goto v_17226;
v_17228:
v_17226:
    v_17759 = stack[-7];
    stack[-8] = v_17759;
    goto v_17274;
v_17270:
    v_17760 = stack[-4];
    goto v_17271;
v_17272:
    v_17759 = elt(env, 12); // inline
    goto v_17273;
v_17274:
    goto v_17270;
v_17271:
    goto v_17272;
v_17273:
    if (v_17760 == v_17759) goto v_17268;
    else goto v_17269;
v_17268:
    goto v_17287;
v_17281:
    v_17761 = elt(env, 18); // lambda
    goto v_17282;
v_17283:
    v_17760 = stack[-3];
    goto v_17284;
v_17285:
    v_17759 = stack[-7];
    goto v_17286;
v_17287:
    goto v_17281;
v_17282:
    goto v_17283;
v_17284:
    goto v_17285;
v_17286:
    v_17759 = list3(v_17761, v_17760, v_17759);
    env = stack[-10];
    stack[0] = v_17759;
    goto v_17299;
v_17295:
    v_17761 = stack[0];
    goto v_17296;
v_17297:
    goto v_17306;
v_17302:
    v_17760 = stack[-5];
    goto v_17303;
v_17304:
    v_17759 = elt(env, 12); // inline
    goto v_17305;
v_17306:
    goto v_17302;
v_17303:
    goto v_17304;
v_17305:
    v_17759 = get(v_17760, v_17759);
    env = stack[-10];
    goto v_17298;
v_17299:
    goto v_17295;
v_17296:
    goto v_17297;
v_17298:
    if (equal(v_17761, v_17759)) goto v_17294;
    v_17759 = Lposn(nil, 0);
    env = stack[-10];
    v_17759 = (LispObject)zerop(v_17759);
    v_17759 = v_17759 ? lisp_true : nil;
    env = stack[-10];
    if (v_17759 == nil) goto v_17311;
    else goto v_17312;
v_17311:
    v_17759 = Lterpri(nil, 0);
    env = stack[-10];
    goto v_17310;
v_17312:
v_17310:
    v_17759 = elt(env, 19); // "+++ Record new inline definition:"
    v_17759 = Lprinc(nil, v_17759);
    env = stack[-10];
    v_17759 = Lterpri(nil, 0);
    env = stack[-10];
    goto v_17329;
v_17321:
    v_17762 = elt(env, 20); // de
    goto v_17322;
v_17323:
    v_17761 = stack[-5];
    goto v_17324;
v_17325:
    v_17760 = stack[-3];
    goto v_17326;
v_17327:
    v_17759 = stack[-7];
    goto v_17328;
v_17329:
    goto v_17321;
v_17322:
    goto v_17323;
v_17324:
    goto v_17325;
v_17326:
    goto v_17327;
v_17328:
    v_17759 = list4(v_17762, v_17761, v_17760, v_17759);
    env = stack[-10];
    v_17759 = Lprint(nil, v_17759);
    env = stack[-10];
    goto v_17341;
v_17335:
    v_17761 = stack[-5];
    goto v_17336;
v_17337:
    v_17760 = stack[0];
    goto v_17338;
v_17339:
    v_17759 = qvalue(elt(env, 21)); // new_inline_definitions
    goto v_17340;
v_17341:
    goto v_17335;
v_17336:
    goto v_17337;
v_17338:
    goto v_17339;
v_17340:
    v_17759 = acons(v_17761, v_17760, v_17759);
    env = stack[-10];
    qvalue(elt(env, 21)) = v_17759; // new_inline_definitions
    goto v_17292;
v_17294:
v_17292:
    goto v_17267;
v_17269:
v_17267:
    goto v_17358;
v_17354:
    v_17760 = stack[-4];
    goto v_17355;
v_17356:
    v_17759 = elt(env, 12); // inline
    goto v_17357;
v_17358:
    goto v_17354;
v_17355:
    goto v_17356;
v_17357:
    if (v_17760 == v_17759) goto v_17353;
    goto v_17366;
v_17362:
    v_17760 = stack[-5];
    goto v_17363;
v_17364:
    v_17759 = elt(env, 12); // inline
    goto v_17365;
v_17366:
    goto v_17362;
v_17363:
    goto v_17364;
v_17365:
    v_17759 = get(v_17760, v_17759);
    env = stack[-10];
    goto v_17351;
v_17353:
    v_17759 = nil;
    goto v_17351;
    v_17759 = nil;
v_17351:
    if (v_17759 == nil) goto v_17349;
    else goto v_17347;
v_17349:
    goto v_17381;
v_17377:
    v_17760 = stack[-4];
    goto v_17378;
v_17379:
    v_17759 = elt(env, 22); // smacro
    goto v_17380;
v_17381:
    goto v_17377;
v_17378:
    goto v_17379;
v_17380:
    if (v_17760 == v_17759) goto v_17376;
    goto v_17389;
v_17385:
    v_17760 = stack[-5];
    goto v_17386;
v_17387:
    v_17759 = elt(env, 22); // smacro
    goto v_17388;
v_17389:
    goto v_17385;
v_17386:
    goto v_17387;
v_17388:
    v_17759 = get(v_17760, v_17759);
    env = stack[-10];
    goto v_17374;
v_17376:
    v_17759 = nil;
    goto v_17374;
    v_17759 = nil;
v_17374:
    if (v_17759 == nil) goto v_17372;
    else goto v_17347;
v_17372:
    goto v_17348;
v_17347:
    goto v_17403;
v_17397:
    v_17761 = elt(env, 23); // "SMACRO/INLINE"
    goto v_17398;
v_17399:
    v_17760 = stack[-5];
    goto v_17400;
v_17401:
    v_17759 = elt(env, 8); // "redefined"
    goto v_17402;
v_17403:
    goto v_17397;
v_17398:
    goto v_17399;
v_17400:
    goto v_17401;
v_17402:
    v_17759 = list3(v_17761, v_17760, v_17759);
    env = stack[-10];
    fn = elt(env, 47); // lprim
    v_17759 = (*qfn1(fn))(fn, v_17759);
    env = stack[-10];
    goto v_17346;
v_17348:
v_17346:
    goto v_17414;
v_17408:
    v_17761 = stack[-3];
    goto v_17409;
v_17410:
    v_17760 = stack[-7];
    goto v_17411;
v_17412:
    v_17759 = stack[-2];
    goto v_17413;
v_17414:
    goto v_17408;
v_17409:
    goto v_17410;
v_17411:
    goto v_17412;
v_17413:
    fn = elt(env, 53); // symbvarlst
    v_17759 = (*qfnn(fn))(fn, 3, v_17761, v_17760, v_17759);
    env = stack[-10];
    goto v_17426;
v_17422:
    v_17760 = stack[-4];
    goto v_17423;
v_17424:
    v_17759 = elt(env, 13); // expr
    goto v_17425;
v_17426:
    goto v_17422;
v_17423:
    goto v_17424;
v_17425:
    if (v_17760 == v_17759) goto v_17420;
    else goto v_17421;
v_17420:
    goto v_17438;
v_17430:
    v_17762 = elt(env, 20); // de
    goto v_17431;
v_17432:
    v_17761 = stack[-5];
    goto v_17433;
v_17434:
    v_17760 = stack[-3];
    goto v_17435;
v_17436:
    v_17759 = stack[-7];
    goto v_17437;
v_17438:
    goto v_17430;
v_17431:
    goto v_17432;
v_17433:
    goto v_17434;
v_17435:
    goto v_17436;
v_17437:
    v_17759 = list4(v_17762, v_17761, v_17760, v_17759);
    env = stack[-10];
    stack[-7] = v_17759;
    goto v_17419;
v_17421:
    goto v_17449;
v_17445:
    v_17760 = stack[-4];
    goto v_17446;
v_17447:
    v_17759 = elt(env, 24); // fexpr
    goto v_17448;
v_17449:
    goto v_17445;
v_17446:
    goto v_17447;
v_17448:
    if (v_17760 == v_17759) goto v_17443;
    else goto v_17444;
v_17443:
    goto v_17461;
v_17453:
    v_17762 = elt(env, 25); // df
    goto v_17454;
v_17455:
    v_17761 = stack[-5];
    goto v_17456;
v_17457:
    v_17760 = stack[-3];
    goto v_17458;
v_17459:
    v_17759 = stack[-7];
    goto v_17460;
v_17461:
    goto v_17453;
v_17454:
    goto v_17455;
v_17456:
    goto v_17457;
v_17458:
    goto v_17459;
v_17460:
    v_17759 = list4(v_17762, v_17761, v_17760, v_17759);
    env = stack[-10];
    stack[-7] = v_17759;
    goto v_17419;
v_17444:
    goto v_17472;
v_17468:
    v_17760 = stack[-4];
    goto v_17469;
v_17470:
    v_17759 = elt(env, 26); // macro
    goto v_17471;
v_17472:
    goto v_17468;
v_17469:
    goto v_17470;
v_17471:
    if (v_17760 == v_17759) goto v_17466;
    else goto v_17467;
v_17466:
    goto v_17484;
v_17476:
    v_17762 = elt(env, 27); // dm
    goto v_17477;
v_17478:
    v_17761 = stack[-5];
    goto v_17479;
v_17480:
    v_17760 = stack[-3];
    goto v_17481;
v_17482:
    v_17759 = stack[-7];
    goto v_17483;
v_17484:
    goto v_17476;
v_17477:
    goto v_17478;
v_17479:
    goto v_17480;
v_17481:
    goto v_17482;
v_17483:
    v_17759 = list4(v_17762, v_17761, v_17760, v_17759);
    env = stack[-10];
    stack[-7] = v_17759;
    goto v_17419;
v_17467:
    goto v_17496;
v_17492:
    v_17760 = stack[-4];
    goto v_17493;
v_17494:
    v_17759 = elt(env, 28); // procfn
    goto v_17495;
v_17496:
    goto v_17492;
v_17493:
    goto v_17494;
v_17495:
    v_17759 = get(v_17760, v_17759);
    env = stack[-10];
    stack[0] = v_17759;
    if (v_17759 == nil) goto v_17490;
    goto v_17508;
v_17500:
    v_17762 = stack[0];
    goto v_17501;
v_17502:
    v_17761 = stack[-5];
    goto v_17503;
v_17504:
    v_17760 = stack[-3];
    goto v_17505;
v_17506:
    v_17759 = stack[-7];
    goto v_17507;
v_17508:
    goto v_17500;
v_17501:
    goto v_17502;
v_17503:
    goto v_17504;
v_17505:
    goto v_17506;
v_17507:
    v_17759 = Lapply3(nil, 4, v_17762, v_17761, v_17760, v_17759);
    goto v_16971;
v_17490:
    goto v_17524;
v_17516:
    stack[-9] = elt(env, 29); // putc
    goto v_17517;
v_17518:
    v_17759 = stack[-5];
    stack[-1] = Lmkquote(nil, v_17759);
    env = stack[-10];
    goto v_17519;
v_17520:
    v_17759 = stack[-4];
    stack[0] = Lmkquote(nil, v_17759);
    env = stack[-10];
    goto v_17521;
v_17522:
    goto v_17538;
v_17532:
    v_17761 = elt(env, 18); // lambda
    goto v_17533;
v_17534:
    v_17760 = stack[-3];
    goto v_17535;
v_17536:
    v_17759 = stack[-7];
    goto v_17537;
v_17538:
    goto v_17532;
v_17533:
    goto v_17534;
v_17535:
    goto v_17536;
v_17537:
    v_17759 = list3(v_17761, v_17760, v_17759);
    env = stack[-10];
    v_17759 = Lmkquote(nil, v_17759);
    env = stack[-10];
    goto v_17523;
v_17524:
    goto v_17516;
v_17517:
    goto v_17518;
v_17519:
    goto v_17520;
v_17521:
    goto v_17522;
v_17523:
    v_17759 = list4(stack[-9], stack[-1], stack[0], v_17759);
    env = stack[-10];
    stack[-7] = v_17759;
    goto v_17419;
v_17419:
    goto v_17550;
v_17546:
    v_17760 = stack[-2];
    goto v_17547;
v_17548:
    v_17759 = elt(env, 30); // symbolic
    goto v_17549;
v_17550:
    goto v_17546;
v_17547:
    goto v_17548;
v_17549:
    if (v_17760 == v_17759) goto v_17545;
    goto v_17558;
v_17554:
    goto v_17566;
v_17560:
    stack[-1] = elt(env, 31); // flag
    goto v_17561;
v_17562:
    v_17759 = stack[-5];
    v_17759 = ncons(v_17759);
    env = stack[-10];
    stack[0] = Lmkquote(nil, v_17759);
    env = stack[-10];
    goto v_17563;
v_17564:
    v_17759 = elt(env, 32); // opfn
    v_17759 = Lmkquote(nil, v_17759);
    env = stack[-10];
    goto v_17565;
v_17566:
    goto v_17560;
v_17561:
    goto v_17562;
v_17563:
    goto v_17564;
v_17565:
    v_17760 = list3(stack[-1], stack[0], v_17759);
    env = stack[-10];
    goto v_17555;
v_17556:
    v_17759 = stack[-7];
    goto v_17557;
v_17558:
    goto v_17554;
v_17555:
    goto v_17556;
v_17557:
    fn = elt(env, 54); // mkprogn
    v_17759 = (*qfn2(fn))(fn, v_17760, v_17759);
    env = stack[-10];
    stack[-7] = v_17759;
    goto v_17543;
v_17545:
v_17543:
    v_17759 = qvalue(elt(env, 33)); // !*argnochk
    if (v_17759 == nil) goto v_17577;
    goto v_17585;
v_17581:
    v_17760 = stack[-4];
    goto v_17582;
v_17583:
    v_17759 = elt(env, 34); // (expr inline smacro)
    goto v_17584;
v_17585:
    goto v_17581;
v_17582:
    goto v_17583;
v_17584:
    v_17759 = Lmemq(nil, v_17760, v_17759);
    if (v_17759 == nil) goto v_17577;
    v_17759 = stack[-5];
    if (!symbolp(v_17759)) v_17759 = nil;
    else { v_17759 = qfastgets(v_17759);
           if (v_17759 != nil) { v_17759 = elt(v_17759, 42); // number!-of!-args
#ifdef RECORD_GET
             if (v_17759 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v_17759 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v_17759 == SPID_NOPROP) v_17759 = nil; }}
#endif
    stack[-9] = v_17759;
    if (v_17759 == nil) goto v_17592;
    goto v_17606;
v_17602:
    v_17760 = stack[-5];
    goto v_17603;
v_17604:
    v_17759 = elt(env, 35); // variadic
    goto v_17605;
v_17606:
    goto v_17602;
v_17603:
    goto v_17604;
v_17605:
    v_17759 = Lflagp(nil, v_17760, v_17759);
    env = stack[-10];
    if (v_17759 == nil) goto v_17599;
    else goto v_17600;
v_17599:
    goto v_17614;
v_17610:
    stack[0] = stack[-9];
    goto v_17611;
v_17612:
    v_17759 = stack[-3];
    v_17759 = Llength(nil, v_17759);
    env = stack[-10];
    goto v_17613;
v_17614:
    goto v_17610;
v_17611:
    goto v_17612;
v_17613:
    v_17759 = Lneq(nil, stack[0], v_17759);
    env = stack[-10];
    goto v_17598;
v_17600:
    v_17759 = nil;
    goto v_17598;
    v_17759 = nil;
v_17598:
    if (v_17759 == nil) goto v_17592;
    v_17759 = qvalue(elt(env, 36)); // !*strict_argcount
    if (v_17759 == nil) goto v_17624;
    goto v_17634;
v_17628:
    v_17761 = elt(env, 37); // "Definition of"
    goto v_17629;
v_17630:
    v_17760 = stack[-5];
    goto v_17631;
v_17632:
    v_17759 = elt(env, 38); // "different count from args previously called with"
    goto v_17633;
v_17634:
    goto v_17628;
v_17629:
    goto v_17630;
v_17631:
    goto v_17632;
v_17633:
    v_17759 = list3(v_17761, v_17760, v_17759);
    env = stack[-10];
    fn = elt(env, 55); // lprie
    v_17759 = (*qfn1(fn))(fn, v_17759);
    env = stack[-10];
    goto v_17622;
v_17624:
    goto v_17650;
v_17642:
    stack[-2] = stack[-5];
    goto v_17643;
v_17644:
    stack[-1] = elt(env, 39); // "defined with"
    goto v_17645;
v_17646:
    v_17759 = stack[-3];
    stack[0] = Llength(nil, v_17759);
    env = stack[-10];
    goto v_17647;
v_17648:
    goto v_17662;
v_17656:
    v_17761 = elt(env, 40); // "but previously called with"
    goto v_17657;
v_17658:
    v_17760 = stack[-9];
    goto v_17659;
v_17660:
    v_17759 = elt(env, 41); // "arguments"
    goto v_17661;
v_17662:
    goto v_17656;
v_17657:
    goto v_17658;
v_17659:
    goto v_17660;
v_17661:
    v_17759 = list3(v_17761, v_17760, v_17759);
    env = stack[-10];
    goto v_17649;
v_17650:
    goto v_17642;
v_17643:
    goto v_17644;
v_17645:
    goto v_17646;
v_17647:
    goto v_17648;
v_17649:
    v_17759 = list3star(stack[-2], stack[-1], stack[0], v_17759);
    env = stack[-10];
    fn = elt(env, 47); // lprim
    v_17759 = (*qfn1(fn))(fn, v_17759);
    env = stack[-10];
    goto v_17622;
v_17622:
    goto v_17590;
v_17592:
v_17590:
    goto v_17671;
v_17667:
    goto v_17681;
v_17673:
    stack[-2] = elt(env, 42); // put
    goto v_17674;
v_17675:
    v_17759 = stack[-5];
    stack[-1] = Lmkquote(nil, v_17759);
    env = stack[-10];
    goto v_17676;
v_17677:
    v_17759 = elt(env, 43); // number!-of!-args
    stack[0] = Lmkquote(nil, v_17759);
    env = stack[-10];
    goto v_17678;
v_17679:
    v_17759 = stack[-3];
    v_17759 = Llength(nil, v_17759);
    env = stack[-10];
    goto v_17680;
v_17681:
    goto v_17673;
v_17674:
    goto v_17675;
v_17676:
    goto v_17677;
v_17678:
    goto v_17679;
v_17680:
    v_17760 = list4(stack[-2], stack[-1], stack[0], v_17759);
    env = stack[-10];
    goto v_17668;
v_17669:
    v_17759 = stack[-7];
    goto v_17670;
v_17671:
    goto v_17667;
v_17668:
    goto v_17669;
v_17670:
    fn = elt(env, 54); // mkprogn
    v_17759 = (*qfn2(fn))(fn, v_17760, v_17759);
    env = stack[-10];
    stack[-7] = v_17759;
    goto v_17575;
v_17577:
v_17575:
    v_17759 = qvalue(elt(env, 4)); // !*defn
    if (v_17759 == nil) goto v_17693;
    goto v_17701;
v_17697:
    v_17760 = stack[-4];
    goto v_17698;
v_17699:
    v_17759 = elt(env, 44); // (fexpr macro inline smacro)
    goto v_17700;
v_17701:
    goto v_17697;
v_17698:
    goto v_17699;
v_17700:
    v_17759 = Lmemq(nil, v_17760, v_17759);
    if (v_17759 == nil) goto v_17693;
    v_17759 = stack[-7];
    fn = elt(env, 56); // lispeval
    v_17759 = (*qfn1(fn))(fn, v_17759);
    env = stack[-10];
    goto v_17691;
v_17693:
v_17691:
    goto v_17715;
v_17711:
    v_17760 = stack[-4];
    goto v_17712;
v_17713:
    v_17759 = elt(env, 12); // inline
    goto v_17714;
v_17715:
    goto v_17711;
v_17712:
    goto v_17713;
v_17714:
    if (v_17760 == v_17759) goto v_17709;
    else goto v_17710;
v_17709:
    goto v_17724;
v_17720:
    goto v_17734;
v_17726:
    v_17762 = elt(env, 20); // de
    goto v_17727;
v_17728:
    v_17761 = stack[-5];
    goto v_17729;
v_17730:
    v_17760 = stack[-3];
    goto v_17731;
v_17732:
    v_17759 = stack[-8];
    goto v_17733;
v_17734:
    goto v_17726;
v_17727:
    goto v_17728;
v_17729:
    goto v_17730;
v_17731:
    goto v_17732;
v_17733:
    v_17760 = list4(v_17762, v_17761, v_17760, v_17759);
    env = stack[-10];
    goto v_17721;
v_17722:
    v_17759 = stack[-7];
    goto v_17723;
v_17724:
    goto v_17720;
v_17721:
    goto v_17722;
v_17723:
    fn = elt(env, 54); // mkprogn
    v_17759 = (*qfn2(fn))(fn, v_17760, v_17759);
    env = stack[-10];
    v_17759 = Lprint(nil, v_17759);
    env = stack[-10];
    stack[-7] = v_17759;
    goto v_17708;
v_17710:
v_17708:
    v_17759 = qvalue(elt(env, 45)); // !*micro!-version
    if (v_17759 == nil) goto v_17743;
    goto v_17751;
v_17747:
    v_17759 = stack[-4];
    goto v_17748;
v_17749:
    v_17760 = elt(env, 46); // (fexpr macro smacro)
    goto v_17750;
v_17751:
    goto v_17747;
v_17748:
    goto v_17749;
v_17750:
    v_17759 = Lmemq(nil, v_17759, v_17760);
    if (v_17759 == nil) goto v_17743;
    v_17759 = nil;
    goto v_17741;
v_17743:
    v_17759 = stack[-7];
    goto v_17741;
    v_17759 = nil;
v_17741:
v_16971:
    ;}  // end of a binding scope
    return onevalue(v_17759);
}



// Code for monomgetfirstmultivar

static LispObject CC_monomgetfirstmultivar(LispObject env,
                         LispObject v_16956)
{
    env = qenv(env);
    LispObject v_16985, v_16986, v_16987;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16986 = v_16956;
// end of prologue
    goto v_16968;
v_16964:
    v_16987 = v_16986;
    goto v_16965;
v_16966:
    v_16985 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16967;
v_16968:
    goto v_16964;
v_16965:
    goto v_16966;
v_16967:
    v_16985 = *(LispObject *)((char *)v_16987 + (CELL-TAG_VECTOR) + (((intptr_t)v_16985-TAG_FIXNUM)/(16/CELL)));
    v_16985 = qcar(v_16985);
    if (v_16985 == nil) goto v_16963;
    goto v_16977;
v_16973:
    goto v_16974;
v_16975:
    v_16985 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16976;
v_16977:
    goto v_16973;
v_16974:
    goto v_16975;
v_16976:
    v_16985 = *(LispObject *)((char *)v_16986 + (CELL-TAG_VECTOR) + (((intptr_t)v_16985-TAG_FIXNUM)/(16/CELL)));
    v_16985 = qcar(v_16985);
    goto v_16961;
v_16963:
    v_16985 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16961;
    v_16985 = nil;
v_16961:
    return onevalue(v_16985);
}



// Code for sfto_updecf

static LispObject CC_sfto_updecf(LispObject env,
                         LispObject v_16956)
{
    env = qenv(env);
    LispObject v_16975, v_16976;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16956);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16956);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_16976 = v_16956;
// end of prologue
    v_16975 = qvalue(elt(env, 1)); // !*sfto_yun
    if (v_16975 == nil) goto v_16961;
    v_16975 = v_16976;
    {
        fn = elt(env, 4); // sfto_yun!-updecf
        return (*qfn1(fn))(fn, v_16975);
    }
v_16961:
    v_16975 = qvalue(elt(env, 2)); // !*sfto_musser
    if (v_16975 == nil) goto v_16966;
    v_16975 = v_16976;
    {
        fn = elt(env, 5); // sfto_musser!-updecf
        return (*qfn1(fn))(fn, v_16975);
    }
v_16966:
    v_16975 = elt(env, 3); // "sfto_updecf: select a decomposition method"
    v_16975 = ncons(v_16975);
    env = stack[0];
    {
        fn = elt(env, 6); // rederr
        return (*qfn1(fn))(fn, v_16975);
    }
    v_16975 = nil;
    return onevalue(v_16975);
}



// Code for get_char_group

static LispObject CC_get_char_group(LispObject env,
                         LispObject v_16956)
{
    env = qenv(env);
    LispObject v_16962;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16962 = v_16956;
// end of prologue
    v_16962 = qcar(v_16962);
    return onevalue(v_16962);
}



// Code for lesspcdadr

static LispObject CC_lesspcdadr(LispObject env,
                         LispObject v_16956, LispObject v_16957)
{
    env = qenv(env);
    LispObject v_16973, v_16974;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16973 = v_16957;
    v_16974 = v_16956;
// end of prologue
    goto v_16964;
v_16960:
    v_16974 = qcdr(v_16974);
    v_16974 = qcar(v_16974);
    v_16974 = qcdr(v_16974);
    goto v_16961;
v_16962:
    v_16973 = qcdr(v_16973);
    v_16973 = qcar(v_16973);
    v_16973 = qcdr(v_16973);
    goto v_16963;
v_16964:
    goto v_16960;
v_16961:
    goto v_16962;
v_16963:
        return Llessp(nil, v_16974, v_16973);
}



// Code for matrix_rows

static LispObject CC_matrix_rows(LispObject env,
                         LispObject v_16956)
{
    env = qenv(env);
    LispObject v_16980;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16956);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16956);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_16956;
// end of prologue
    v_16980 = stack[0];
    if (v_16980 == nil) goto v_16963;
    v_16980 = elt(env, 1); // "<matrixrow>"
    fn = elt(env, 3); // printout
    v_16980 = (*qfn1(fn))(fn, v_16980);
    env = stack[-1];
    v_16980 = lisp_true;
    fn = elt(env, 4); // indent!*
    v_16980 = (*qfn1(fn))(fn, v_16980);
    env = stack[-1];
    v_16980 = stack[0];
    v_16980 = qcar(v_16980);
    fn = elt(env, 5); // row
    v_16980 = (*qfn1(fn))(fn, v_16980);
    env = stack[-1];
    v_16980 = nil;
    fn = elt(env, 4); // indent!*
    v_16980 = (*qfn1(fn))(fn, v_16980);
    env = stack[-1];
    v_16980 = elt(env, 2); // "</matrixrow>"
    fn = elt(env, 3); // printout
    v_16980 = (*qfn1(fn))(fn, v_16980);
    env = stack[-1];
    v_16980 = stack[0];
    v_16980 = qcdr(v_16980);
    v_16980 = CC_matrix_rows(elt(env, 0), v_16980);
    goto v_16961;
v_16963:
v_16961:
    v_16980 = nil;
    return onevalue(v_16980);
}



// Code for add_minus

static LispObject CC_add_minus(LispObject env,
                         LispObject v_16956)
{
    env = qenv(env);
    LispObject v_17140, v_17141;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16956);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16956);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_16956;
// end of prologue
    v_17140 = stack[-1];
    if (!consp(v_17140)) goto v_16962;
    else goto v_16963;
v_16962:
    v_17140 = stack[-1];
    goto v_16959;
v_16963:
    goto v_16976;
v_16972:
    v_17140 = stack[-1];
    v_17141 = qcar(v_17140);
    goto v_16973;
v_16974:
    v_17140 = elt(env, 1); // !:rd!:
    goto v_16975;
v_16976:
    goto v_16972;
v_16973:
    goto v_16974;
v_16975:
    if (v_17141 == v_17140) goto v_16970;
    else goto v_16971;
v_16970:
    goto v_16985;
v_16981:
    v_17140 = stack[-1];
    v_17141 = qcdr(v_17140);
    goto v_16982;
v_16983:
    v_17140 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16984;
v_16985:
    goto v_16981;
v_16982:
    goto v_16983;
v_16984:
    v_17140 = (LispObject)geq2(v_17141, v_17140);
    v_17140 = v_17140 ? lisp_true : nil;
    env = stack[-3];
    goto v_16969;
v_16971:
    v_17140 = nil;
    goto v_16969;
    v_17140 = nil;
v_16969:
    if (v_17140 == nil) goto v_16967;
    v_17140 = stack[-1];
    goto v_16959;
v_16967:
    goto v_17003;
v_16999:
    v_17140 = stack[-1];
    v_17141 = qcar(v_17140);
    goto v_17000;
v_17001:
    v_17140 = elt(env, 1); // !:rd!:
    goto v_17002;
v_17003:
    goto v_16999;
v_17000:
    goto v_17001;
v_17002:
    if (v_17141 == v_17140) goto v_16997;
    else goto v_16998;
v_16997:
    goto v_17012;
v_17008:
    v_17140 = stack[-1];
    v_17141 = qcdr(v_17140);
    goto v_17009;
v_17010:
    v_17140 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17011;
v_17012:
    goto v_17008;
v_17009:
    goto v_17010;
v_17011:
    v_17140 = (LispObject)lessp2(v_17141, v_17140);
    v_17140 = v_17140 ? lisp_true : nil;
    env = stack[-3];
    goto v_16996;
v_16998:
    v_17140 = nil;
    goto v_16996;
    v_17140 = nil;
v_16996:
    if (v_17140 == nil) goto v_16994;
    goto v_17024;
v_17020:
    stack[-2] = elt(env, 2); // minus
    goto v_17021;
v_17022:
    goto v_17031;
v_17027:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_17028;
v_17029:
    v_17140 = stack[-1];
    v_17140 = qcdr(v_17140);
    v_17140 = Labsval(nil, v_17140);
    env = stack[-3];
    goto v_17030;
v_17031:
    goto v_17027;
v_17028:
    goto v_17029;
v_17030:
    v_17140 = cons(stack[0], v_17140);
    goto v_17023;
v_17024:
    goto v_17020;
v_17021:
    goto v_17022;
v_17023:
    {
        LispObject v_17145 = stack[-2];
        return list2(v_17145, v_17140);
    }
v_16994:
    goto v_17046;
v_17042:
    v_17140 = stack[-1];
    v_17141 = qcar(v_17140);
    goto v_17043;
v_17044:
    v_17140 = elt(env, 2); // minus
    goto v_17045;
v_17046:
    goto v_17042;
v_17043:
    goto v_17044;
v_17045:
    if (v_17141 == v_17140) goto v_17040;
    else goto v_17041;
v_17040:
    v_17140 = stack[-1];
    v_17140 = qcdr(v_17140);
    v_17140 = qcar(v_17140);
    v_17140 = (is_number(v_17140) ? lisp_true : nil);
    goto v_17039;
v_17041:
    v_17140 = nil;
    goto v_17039;
    v_17140 = nil;
v_17039:
    if (v_17140 == nil) goto v_17037;
    v_17140 = stack[-1];
    goto v_16959;
v_17037:
    goto v_17068;
v_17064:
    v_17140 = stack[-1];
    v_17141 = qcar(v_17140);
    goto v_17065;
v_17066:
    v_17140 = elt(env, 2); // minus
    goto v_17067;
v_17068:
    goto v_17064;
v_17065:
    goto v_17066;
v_17067:
    if (v_17141 == v_17140) goto v_17062;
    else goto v_17063;
v_17062:
    goto v_17077;
v_17073:
    v_17140 = stack[-1];
    v_17140 = qcdr(v_17140);
    v_17140 = qcar(v_17140);
    v_17141 = qcdr(v_17140);
    goto v_17074;
v_17075:
    v_17140 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17076;
v_17077:
    goto v_17073;
v_17074:
    goto v_17075;
v_17076:
    v_17140 = (LispObject)lessp2(v_17141, v_17140);
    v_17140 = v_17140 ? lisp_true : nil;
    env = stack[-3];
    goto v_17061;
v_17063:
    v_17140 = nil;
    goto v_17061;
    v_17140 = nil;
v_17061:
    if (v_17140 == nil) goto v_17059;
    goto v_17091;
v_17087:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_17088;
v_17089:
    v_17140 = stack[-1];
    v_17140 = qcdr(v_17140);
    v_17140 = qcar(v_17140);
    v_17140 = qcdr(v_17140);
    v_17140 = Labsval(nil, v_17140);
    goto v_17090;
v_17091:
    goto v_17087;
v_17088:
    goto v_17089;
v_17090:
    {
        LispObject v_17146 = stack[0];
        return cons(v_17146, v_17140);
    }
v_17059:
    goto v_17104;
v_17100:
    v_17140 = stack[-1];
    v_17141 = qcar(v_17140);
    goto v_17101;
v_17102:
    v_17140 = elt(env, 2); // minus
    goto v_17103;
v_17104:
    goto v_17100;
v_17101:
    goto v_17102;
v_17103:
    if (v_17141 == v_17140) goto v_17098;
    else goto v_17099;
v_17098:
    v_17140 = stack[-1];
    goto v_16959;
v_17099:
    goto v_17116;
v_17112:
    v_17140 = stack[-1];
    v_17141 = qcdr(v_17140);
    goto v_17113;
v_17114:
    v_17140 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17115;
v_17116:
    goto v_17112;
v_17113:
    goto v_17114;
v_17115:
    v_17140 = (LispObject)lessp2(v_17141, v_17140);
    v_17140 = v_17140 ? lisp_true : nil;
    env = stack[-3];
    if (v_17140 == nil) goto v_17110;
    goto v_17125;
v_17121:
    stack[-2] = elt(env, 2); // minus
    goto v_17122;
v_17123:
    goto v_17132;
v_17128:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_17129;
v_17130:
    v_17140 = stack[-1];
    v_17140 = qcdr(v_17140);
    v_17140 = Labsval(nil, v_17140);
    env = stack[-3];
    goto v_17131;
v_17132:
    goto v_17128;
v_17129:
    goto v_17130;
v_17131:
    v_17140 = cons(stack[0], v_17140);
    goto v_17124;
v_17125:
    goto v_17121;
v_17122:
    goto v_17123;
v_17124:
    {
        LispObject v_17147 = stack[-2];
        return list2(v_17147, v_17140);
    }
v_17110:
    v_17140 = stack[-1];
    goto v_16959;
    v_17140 = nil;
v_16959:
    return onevalue(v_17140);
}



// Code for insoccs

static LispObject CC_insoccs(LispObject env,
                         LispObject v_16956, LispObject v_16957)
{
    env = qenv(env);
    LispObject v_17028, v_17029;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16957,v_16956);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16956,v_16957);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_16957;
    stack[-1] = v_16956;
// end of prologue
    v_17028 = stack[-1];
    if (symbolp(v_17028)) goto v_16963;
    v_17028 = stack[-1];
    fn = elt(env, 1); // subscriptedvarp
    v_17028 = (*qfn1(fn))(fn, v_17028);
    env = stack[-2];
    if (v_17028 == nil) goto v_16968;
    else goto v_16963;
v_16968:
    v_17028 = stack[-1];
    v_17028 = Lconsp(nil, v_17028);
    env = stack[-2];
    if (v_17028 == nil) goto v_16971;
    v_17028 = stack[-1];
    v_17028 = qcar(v_17028);
    fn = elt(env, 1); // subscriptedvarp
    v_17028 = (*qfn1(fn))(fn, v_17028);
    env = stack[-2];
    if (v_17028 == nil) goto v_16971;
    goto v_16963;
v_16971:
    goto v_16964;
v_16963:
    goto v_16984;
v_16980:
    v_17029 = stack[0];
    goto v_16981;
v_16982:
    v_17028 = stack[-1];
    goto v_16983;
v_16984:
    goto v_16980;
v_16981:
    goto v_16982;
v_16983:
    fn = elt(env, 2); // insertocc
    v_17028 = (*qfn2(fn))(fn, v_17029, v_17028);
    env = stack[-2];
    stack[0] = v_17028;
    goto v_16962;
v_16964:
v_16962:
    v_17028 = stack[-1];
    if (symbolp(v_17028)) goto v_16994;
    v_17028 = stack[-1];
    fn = elt(env, 3); // constp
    v_17028 = (*qfn1(fn))(fn, v_17028);
    env = stack[-2];
    v_17028 = (v_17028 == nil ? lisp_true : nil);
    goto v_16992;
v_16994:
    v_17028 = nil;
    goto v_16992;
    v_17028 = nil;
v_16992:
    if (v_17028 == nil) goto v_16990;
    v_17028 = stack[-1];
    v_17028 = qcdr(v_17028);
    stack[-1] = v_17028;
v_17005:
    v_17028 = stack[-1];
    if (v_17028 == nil) goto v_17010;
    else goto v_17011;
v_17010:
    goto v_17004;
v_17011:
    v_17028 = stack[-1];
    v_17028 = qcar(v_17028);
    goto v_17022;
v_17018:
    v_17029 = v_17028;
    goto v_17019;
v_17020:
    v_17028 = stack[0];
    goto v_17021;
v_17022:
    goto v_17018;
v_17019:
    goto v_17020;
v_17021:
    v_17028 = CC_insoccs(elt(env, 0), v_17029, v_17028);
    env = stack[-2];
    stack[0] = v_17028;
    v_17028 = stack[-1];
    v_17028 = qcdr(v_17028);
    stack[-1] = v_17028;
    goto v_17005;
v_17004:
    goto v_16988;
v_16990:
v_16988:
    v_17028 = stack[0];
    return onevalue(v_17028);
}



// Code for vdp2a

static LispObject CC_vdp2a(LispObject env,
                         LispObject v_16956)
{
    env = qenv(env);
    LispObject v_16964;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16964 = v_16956;
// end of prologue
    v_16964 = qcdr(v_16964);
    v_16964 = qcdr(v_16964);
    v_16964 = qcdr(v_16964);
    v_16964 = qcar(v_16964);
    {
        fn = elt(env, 1); // dip2a
        return (*qfn1(fn))(fn, v_16964);
    }
}



// Code for overall_factor

static LispObject CC_overall_factor(LispObject env,
                         LispObject v_16956, LispObject v_16957)
{
    env = qenv(env);
    LispObject v_16992, v_16993;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16957,v_16956);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16956,v_16957);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16957;
    stack[-1] = v_16956;
// end of prologue
v_16955:
    v_16992 = stack[0];
    if (v_16992 == nil) goto v_16961;
    else goto v_16962;
v_16961:
    v_16992 = lisp_true;
    goto v_16960;
v_16962:
    goto v_16975;
v_16971:
    stack[-2] = stack[-1];
    goto v_16972;
v_16973:
    v_16992 = stack[0];
    fn = elt(env, 1); // xval
    v_16992 = (*qfn1(fn))(fn, v_16992);
    env = stack[-3];
    goto v_16974;
v_16975:
    goto v_16971;
v_16972:
    goto v_16973;
v_16974:
    v_16992 = Lmemq(nil, stack[-2], v_16992);
    if (v_16992 == nil) goto v_16969;
    else goto v_16970;
v_16969:
    v_16992 = nil;
    goto v_16968;
v_16970:
    goto v_16988;
v_16984:
    v_16993 = stack[-1];
    goto v_16985;
v_16986:
    v_16992 = stack[0];
    v_16992 = qcdr(v_16992);
    goto v_16987;
v_16988:
    goto v_16984;
v_16985:
    goto v_16986;
v_16987:
    stack[-1] = v_16993;
    stack[0] = v_16992;
    goto v_16955;
    v_16992 = nil;
v_16968:
    goto v_16960;
    v_16992 = nil;
v_16960:
    return onevalue(v_16992);
}



// Code for testchar1

static LispObject CC_testchar1(LispObject env,
                         LispObject v_16956)
{
    env = qenv(env);
    LispObject v_17004, v_17005;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16956);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16956);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_16956;
// end of prologue
    v_17004 = stack[0];
    v_17004 = integerp(v_17004);
    if (v_17004 == nil) goto v_16961;
    v_17004 = stack[0];
    goto v_16959;
v_16961:
    v_17004 = stack[0];
    v_17004 = Lexplodec(nil, v_17004);
    env = stack[-1];
    v_17004 = qcdr(v_17004);
    if (v_17004 == nil) goto v_16965;
    else goto v_16966;
v_16965:
    v_17004 = stack[0];
    goto v_16959;
v_16966:
    goto v_16977;
v_16973:
    v_17005 = stack[0];
    goto v_16974;
v_16975:
    v_17004 = qvalue(elt(env, 1)); // nochar!*
    goto v_16976;
v_16977:
    goto v_16973;
v_16974:
    goto v_16975;
v_16976:
    v_17004 = Lmember(nil, v_17005, v_17004);
    if (v_17004 == nil) goto v_16972;
    v_17004 = stack[0];
    goto v_16959;
v_16972:
    goto v_16988;
v_16984:
    v_17005 = stack[0];
    goto v_16985;
v_16986:
    v_17004 = qvalue(elt(env, 2)); // nochar1!*
    goto v_16987;
v_16988:
    goto v_16984;
v_16985:
    goto v_16986;
v_16987:
    v_17004 = Lmember(nil, v_17005, v_17004);
    if (v_17004 == nil) goto v_16983;
    v_17004 = stack[0];
    goto v_16959;
v_16983:
    goto v_17000;
v_16996:
    v_17005 = stack[0];
    goto v_16997;
v_16998:
    v_17004 = qvalue(elt(env, 2)); // nochar1!*
    goto v_16999;
v_17000:
    goto v_16996;
v_16997:
    goto v_16998;
v_16999:
    v_17004 = cons(v_17005, v_17004);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_17004; // nochar1!*
    v_17004 = stack[0];
    goto v_16959;
    v_17004 = nil;
v_16959:
    return onevalue(v_17004);
}



// Code for sign!-of

static LispObject CC_signKof(LispObject env,
                         LispObject v_16956)
{
    env = qenv(env);
    LispObject v_16972, v_16973;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16956);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16956);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_16972 = v_16956;
// end of prologue
    v_16972 = ncons(v_16972);
    env = stack[0];
    fn = elt(env, 1); // simp!-sign
    v_16972 = (*qfn1(fn))(fn, v_16972);
    v_16972 = qcar(v_16972);
    v_16973 = v_16972;
    v_16972 = v_16973;
    if (is_number(v_16972)) goto v_16966;
    v_16972 = nil;
    goto v_16964;
v_16966:
    v_16972 = v_16973;
    goto v_16964;
    v_16972 = nil;
v_16964:
    return onevalue(v_16972);
}



// Code for assert_stat!-parse

static LispObject CC_assert_statKparse(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17046, v_17047, v_17048;
    LispObject fn;
    argcheck(nargs, 0, "assert_stat-parse");
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
    fn = elt(env, 8); // scan
    v_17046 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-2] = v_17046;
    goto v_16971;
v_16967:
    fn = elt(env, 8); // scan
    v_17047 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_16968;
v_16969:
    v_17046 = elt(env, 1); // !*colon!*
    goto v_16970;
v_16971:
    goto v_16967;
v_16968:
    goto v_16969;
v_16970:
    if (v_17047 == v_17046) goto v_16966;
    goto v_16980;
v_16976:
    v_17047 = elt(env, 2); // "expecting ':' in assert but found"
    goto v_16977;
v_16978:
    v_17046 = qvalue(elt(env, 3)); // cursym!*
    goto v_16979;
v_16980:
    goto v_16976;
v_16977:
    goto v_16978;
v_16979:
    v_17046 = list2(v_17047, v_17046);
    env = stack[-3];
    fn = elt(env, 9); // rederr
    v_17046 = (*qfn1(fn))(fn, v_17046);
    env = stack[-3];
    goto v_16964;
v_16966:
v_16964:
    fn = elt(env, 10); // assert_stat1
    v_17046 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-1] = v_17046;
    goto v_16996;
v_16992:
    fn = elt(env, 8); // scan
    v_17047 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_16993;
v_16994:
    v_17046 = elt(env, 4); // difference
    goto v_16995;
v_16996:
    goto v_16992;
v_16993:
    goto v_16994;
v_16995:
    if (v_17047 == v_17046) goto v_16991;
    v_17046 = lisp_true;
    goto v_16989;
v_16991:
    goto v_17007;
v_17003:
    fn = elt(env, 8); // scan
    v_17047 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_17004;
v_17005:
    v_17046 = elt(env, 5); // greaterp
    goto v_17006;
v_17007:
    goto v_17003;
v_17004:
    goto v_17005;
v_17006:
    v_17046 = Lneq(nil, v_17047, v_17046);
    env = stack[-3];
    goto v_16989;
    v_17046 = nil;
v_16989:
    if (v_17046 == nil) goto v_16987;
    goto v_17016;
v_17012:
    v_17047 = elt(env, 6); // "expecting '->' in assert but found"
    goto v_17013;
v_17014:
    v_17046 = qvalue(elt(env, 3)); // cursym!*
    goto v_17015;
v_17016:
    goto v_17012;
v_17013:
    goto v_17014;
v_17015:
    v_17046 = list2(v_17047, v_17046);
    env = stack[-3];
    fn = elt(env, 9); // rederr
    v_17046 = (*qfn1(fn))(fn, v_17046);
    env = stack[-3];
    goto v_16985;
v_16987:
v_16985:
    fn = elt(env, 8); // scan
    v_17046 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[0] = v_17046;
    fn = elt(env, 8); // scan
    v_17046 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    if (!symbolp(v_17046)) v_17046 = nil;
    else { v_17046 = qfastgets(v_17046);
           if (v_17046 != nil) { v_17046 = elt(v_17046, 55); // delim
#ifdef RECORD_GET
             if (v_17046 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v_17046 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v_17046 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v_17046 == SPID_NOPROP) v_17046 = nil; else v_17046 = lisp_true; }}
#endif
    if (v_17046 == nil) goto v_17022;
    else goto v_17023;
v_17022:
    goto v_17032;
v_17028:
    v_17047 = elt(env, 7); // "expecting end of assert but found"
    goto v_17029;
v_17030:
    v_17046 = qvalue(elt(env, 3)); // cursym!*
    goto v_17031;
v_17032:
    goto v_17028;
v_17029:
    goto v_17030;
v_17031:
    v_17046 = list2(v_17047, v_17046);
    env = stack[-3];
    fn = elt(env, 9); // rederr
    v_17046 = (*qfn1(fn))(fn, v_17046);
    goto v_17021;
v_17023:
v_17021:
    goto v_17042;
v_17036:
    v_17048 = stack[-2];
    goto v_17037;
v_17038:
    v_17047 = stack[-1];
    goto v_17039;
v_17040:
    v_17046 = stack[0];
    goto v_17041;
v_17042:
    goto v_17036;
v_17037:
    goto v_17038;
v_17039:
    goto v_17040;
v_17041:
    return list3(v_17048, v_17047, v_17046);
    return onevalue(v_17046);
}



// Code for make!-x!-to!-p

static LispObject CC_makeKxKtoKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17181, v_17182, v_17183, v_17184, v_17185;
    LispObject fn;
    LispObject v_16958, v_16957, v_16956;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "make-x-to-p");
    va_start(aa, nargs);
    v_16956 = va_arg(aa, LispObject);
    v_16957 = va_arg(aa, LispObject);
    v_16958 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_16958,v_16957,v_16956);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_16956,v_16957,v_16958);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_16958;
    stack[-1] = v_16957;
    stack[-2] = v_16956;
// end of prologue
    goto v_16972;
v_16968:
    v_17182 = stack[-2];
    goto v_16969;
v_16970:
    v_17181 = qvalue(elt(env, 1)); // dpoly
    goto v_16971;
v_16972:
    goto v_16968;
v_16969:
    goto v_16970;
v_16971:
    if (((intptr_t)(v_17182)) < ((intptr_t)(v_17181))) goto v_16966;
    else goto v_16967;
v_16966:
    v_17181 = (LispObject)0+TAG_FIXNUM; // 0
    v_17184 = v_17181;
v_16978:
    goto v_16988;
v_16984:
    v_17181 = stack[-2];
    v_17182 = (LispObject)((intptr_t)(v_17181) - 0x10);
    goto v_16985;
v_16986:
    v_17181 = v_17184;
    goto v_16987;
v_16988:
    goto v_16984;
v_16985:
    goto v_16986;
v_16987:
    v_17181 = (LispObject)(intptr_t)((intptr_t)v_17182 - (intptr_t)v_17181 + TAG_FIXNUM);
    v_17181 = ((intptr_t)(v_17181) < 0 ? lisp_true : nil);
    if (v_17181 == nil) goto v_16983;
    goto v_16977;
v_16983:
    goto v_17001;
v_16995:
    v_17183 = stack[0];
    goto v_16996;
v_16997:
    v_17182 = v_17184;
    goto v_16998;
v_16999:
    v_17181 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17000;
v_17001:
    goto v_16995;
v_16996:
    goto v_16997;
v_16998:
    goto v_16999;
v_17000:
    *(LispObject *)((char *)v_17183 + (CELL-TAG_VECTOR) + (((intptr_t)v_17182-TAG_FIXNUM)/(16/CELL))) = v_17181;
    v_17181 = v_17184;
    v_17181 = (LispObject)((intptr_t)(v_17181) + 0x10);
    v_17184 = v_17181;
    goto v_16978;
v_16977:
    goto v_17013;
v_17007:
    v_17183 = stack[0];
    goto v_17008;
v_17009:
    v_17182 = stack[-2];
    goto v_17010;
v_17011:
    v_17181 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17012;
v_17013:
    goto v_17007;
v_17008:
    goto v_17009;
v_17010:
    goto v_17011;
v_17012:
    *(LispObject *)((char *)v_17183 + (CELL-TAG_VECTOR) + (((intptr_t)v_17182-TAG_FIXNUM)/(16/CELL))) = v_17181;
    v_17181 = stack[-2];
    goto v_16963;
v_16967:
    goto v_17025;
v_17019:
    goto v_17031;
v_17027:
    v_17182 = stack[-2];
    goto v_17028;
v_17029:
    v_17181 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_17030;
v_17031:
    goto v_17027;
v_17028:
    goto v_17029;
v_17030:
    v_17183 = quot2(v_17182, v_17181);
    env = stack[-4];
    goto v_17020;
v_17021:
    v_17182 = stack[-1];
    goto v_17022;
v_17023:
    v_17181 = stack[0];
    goto v_17024;
v_17025:
    goto v_17019;
v_17020:
    goto v_17021;
v_17022:
    goto v_17023;
v_17024:
    v_17181 = CC_makeKxKtoKp(elt(env, 0), 3, v_17183, v_17182, v_17181);
    env = stack[-4];
    goto v_17047;
v_17037:
    v_17185 = stack[0];
    goto v_17038;
v_17039:
    v_17184 = v_17181;
    goto v_17040;
v_17041:
    v_17183 = stack[0];
    goto v_17042;
v_17043:
    v_17182 = v_17181;
    goto v_17044;
v_17045:
    v_17181 = stack[-1];
    goto v_17046;
v_17047:
    goto v_17037;
v_17038:
    goto v_17039;
v_17040:
    goto v_17041;
v_17042:
    goto v_17043;
v_17044:
    goto v_17045;
v_17046:
    fn = elt(env, 3); // times!-in!-vector
    v_17181 = (*qfnn(fn))(fn, 5, v_17185, v_17184, v_17183, v_17182, v_17181);
    env = stack[-4];
    stack[-3] = v_17181;
    goto v_17062;
v_17054:
    v_17184 = stack[-1];
    goto v_17055;
v_17056:
    v_17183 = stack[-3];
    goto v_17057;
v_17058:
    v_17182 = qvalue(elt(env, 2)); // poly!-vector
    goto v_17059;
v_17060:
    v_17181 = qvalue(elt(env, 1)); // dpoly
    goto v_17061;
v_17062:
    goto v_17054;
v_17055:
    goto v_17056;
v_17057:
    goto v_17058;
v_17059:
    goto v_17060;
v_17061:
    fn = elt(env, 4); // remainder!-in!-vector
    v_17181 = (*qfnn(fn))(fn, 4, v_17184, v_17183, v_17182, v_17181);
    env = stack[-4];
    stack[-3] = v_17181;
    goto v_17075;
v_17071:
    goto v_17081;
v_17077:
    v_17182 = stack[-2];
    goto v_17078;
v_17079:
    v_17181 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_17080;
v_17081:
    goto v_17077;
v_17078:
    goto v_17079;
v_17080:
    v_17182 = Liremainder(nil, v_17182, v_17181);
    env = stack[-4];
    goto v_17072;
v_17073:
    v_17181 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17074;
v_17075:
    goto v_17071;
v_17072:
    goto v_17073;
v_17074:
    if (v_17182 == v_17181) goto v_17070;
    v_17181 = stack[-3];
    v_17185 = v_17181;
v_17088:
    v_17181 = v_17185;
    v_17181 = ((intptr_t)(v_17181) < 0 ? lisp_true : nil);
    if (v_17181 == nil) goto v_17093;
    goto v_17087;
v_17093:
    goto v_17103;
v_17097:
    v_17184 = stack[-1];
    goto v_17098;
v_17099:
    v_17181 = v_17185;
    v_17183 = (LispObject)((intptr_t)(v_17181) + 0x10);
    goto v_17100;
v_17101:
    goto v_17111;
v_17107:
    v_17182 = stack[-1];
    goto v_17108;
v_17109:
    v_17181 = v_17185;
    goto v_17110;
v_17111:
    goto v_17107;
v_17108:
    goto v_17109;
v_17110:
    v_17181 = *(LispObject *)((char *)v_17182 + (CELL-TAG_VECTOR) + (((intptr_t)v_17181-TAG_FIXNUM)/(16/CELL)));
    goto v_17102;
v_17103:
    goto v_17097;
v_17098:
    goto v_17099;
v_17100:
    goto v_17101;
v_17102:
    *(LispObject *)((char *)v_17184 + (CELL-TAG_VECTOR) + (((intptr_t)v_17183-TAG_FIXNUM)/(16/CELL))) = v_17181;
    v_17181 = v_17185;
    v_17181 = (LispObject)((intptr_t)(v_17181) - 0x10);
    v_17185 = v_17181;
    goto v_17088;
v_17087:
    goto v_17123;
v_17117:
    v_17183 = stack[-1];
    goto v_17118;
v_17119:
    v_17182 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17120;
v_17121:
    v_17181 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17122;
v_17123:
    goto v_17117;
v_17118:
    goto v_17119;
v_17120:
    goto v_17121;
v_17122:
    *(LispObject *)((char *)v_17183 + (CELL-TAG_VECTOR) + (((intptr_t)v_17182-TAG_FIXNUM)/(16/CELL))) = v_17181;
    goto v_17136;
v_17128:
    v_17184 = stack[-1];
    goto v_17129;
v_17130:
    v_17181 = stack[-3];
    v_17183 = (LispObject)((intptr_t)(v_17181) + 0x10);
    goto v_17131;
v_17132:
    v_17182 = qvalue(elt(env, 2)); // poly!-vector
    goto v_17133;
v_17134:
    v_17181 = qvalue(elt(env, 1)); // dpoly
    goto v_17135;
v_17136:
    goto v_17128;
v_17129:
    goto v_17130;
v_17131:
    goto v_17132;
v_17133:
    goto v_17134;
v_17135:
    fn = elt(env, 4); // remainder!-in!-vector
    v_17181 = (*qfnn(fn))(fn, 4, v_17184, v_17183, v_17182, v_17181);
    stack[-3] = v_17181;
    goto v_17068;
v_17070:
v_17068:
    v_17181 = (LispObject)0+TAG_FIXNUM; // 0
    v_17185 = v_17181;
v_17145:
    goto v_17155;
v_17151:
    v_17182 = stack[-3];
    goto v_17152;
v_17153:
    v_17181 = v_17185;
    goto v_17154;
v_17155:
    goto v_17151;
v_17152:
    goto v_17153;
v_17154:
    v_17181 = (LispObject)(intptr_t)((intptr_t)v_17182 - (intptr_t)v_17181 + TAG_FIXNUM);
    v_17181 = ((intptr_t)(v_17181) < 0 ? lisp_true : nil);
    if (v_17181 == nil) goto v_17150;
    goto v_17144;
v_17150:
    goto v_17167;
v_17161:
    v_17184 = stack[0];
    goto v_17162;
v_17163:
    v_17183 = v_17185;
    goto v_17164;
v_17165:
    goto v_17174;
v_17170:
    v_17182 = stack[-1];
    goto v_17171;
v_17172:
    v_17181 = v_17185;
    goto v_17173;
v_17174:
    goto v_17170;
v_17171:
    goto v_17172;
v_17173:
    v_17181 = *(LispObject *)((char *)v_17182 + (CELL-TAG_VECTOR) + (((intptr_t)v_17181-TAG_FIXNUM)/(16/CELL)));
    goto v_17166;
v_17167:
    goto v_17161;
v_17162:
    goto v_17163;
v_17164:
    goto v_17165;
v_17166:
    *(LispObject *)((char *)v_17184 + (CELL-TAG_VECTOR) + (((intptr_t)v_17183-TAG_FIXNUM)/(16/CELL))) = v_17181;
    v_17181 = v_17185;
    v_17181 = (LispObject)((intptr_t)(v_17181) + 0x10);
    v_17185 = v_17181;
    goto v_17145;
v_17144:
    v_17181 = stack[-3];
v_16963:
    return onevalue(v_17181);
}



// Code for lalr_process_reductions

static LispObject CC_lalr_process_reductions(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17165, v_17166, v_17167;
    LispObject fn;
    argcheck(nargs, 0, "lalr_process_reductions");
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
    stack[-6] = nil;
    v_17165 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[-4] = v_17165;
    v_17165 = qvalue(elt(env, 1)); // nonterminals
    stack[-5] = v_17165;
v_16974:
    v_17165 = stack[-5];
    if (v_17165 == nil) goto v_16978;
    else goto v_16979;
v_16978:
    goto v_16973;
v_16979:
    v_17165 = stack[-5];
    v_17165 = qcar(v_17165);
    stack[-3] = v_17165;
    v_17165 = stack[-3];
    fn = elt(env, 3); // lalr_productions
    v_17165 = (*qfn1(fn))(fn, v_17165);
    env = stack[-7];
    stack[-2] = v_17165;
v_16988:
    v_17165 = stack[-2];
    if (v_17165 == nil) goto v_16993;
    else goto v_16994;
v_16993:
    goto v_16987;
v_16994:
    v_17165 = stack[-2];
    v_17165 = qcar(v_17165);
    stack[-1] = v_17165;
    goto v_17007;
v_17001:
    stack[0] = stack[-3];
    goto v_17002;
v_17003:
    v_17165 = stack[-1];
    v_17165 = qcar(v_17165);
    v_17166 = Llength(nil, v_17165);
    env = stack[-7];
    goto v_17004;
v_17005:
    v_17165 = stack[-1];
    v_17165 = qcdr(v_17165);
    goto v_17006;
v_17007:
    goto v_17001;
v_17002:
    goto v_17003;
v_17004:
    goto v_17005;
v_17006:
    v_17165 = acons(stack[0], v_17166, v_17165);
    env = stack[-7];
    v_17167 = v_17165;
    goto v_17018;
v_17014:
    v_17166 = v_17167;
    goto v_17015;
v_17016:
    v_17165 = stack[-6];
    goto v_17017;
v_17018:
    goto v_17014;
v_17015:
    goto v_17016;
v_17017:
    v_17165 = Lassoc(nil, v_17166, v_17165);
    stack[0] = v_17165;
    v_17165 = stack[0];
    if (v_17165 == nil) goto v_17024;
    else goto v_17025;
v_17024:
    goto v_17032;
v_17028:
    stack[0] = v_17167;
    goto v_17029;
v_17030:
    v_17165 = stack[-4];
    v_17165 = add1(v_17165);
    env = stack[-7];
    stack[-4] = v_17165;
    goto v_17031;
v_17032:
    goto v_17028;
v_17029:
    goto v_17030;
v_17031:
    v_17165 = cons(stack[0], v_17165);
    env = stack[-7];
    stack[0] = v_17165;
    goto v_17041;
v_17037:
    v_17166 = stack[0];
    goto v_17038;
v_17039:
    v_17165 = stack[-6];
    goto v_17040;
v_17041:
    goto v_17037;
v_17038:
    goto v_17039;
v_17040:
    v_17165 = cons(v_17166, v_17165);
    env = stack[-7];
    stack[-6] = v_17165;
    goto v_17023;
v_17025:
v_17023:
    goto v_17049;
v_17045:
    v_17166 = stack[-1];
    goto v_17046;
v_17047:
    v_17165 = stack[0];
    v_17165 = qcdr(v_17165);
    goto v_17048;
v_17049:
    goto v_17045;
v_17046:
    goto v_17047;
v_17048:
    v_17165 = Lrplacd(nil, v_17166, v_17165);
    env = stack[-7];
    v_17165 = stack[-2];
    v_17165 = qcdr(v_17165);
    stack[-2] = v_17165;
    goto v_16988;
v_16987:
    v_17165 = stack[-5];
    v_17165 = qcdr(v_17165);
    stack[-5] = v_17165;
    goto v_16974;
v_16973:
    v_17165 = stack[-4];
    v_17165 = add1(v_17165);
    env = stack[-7];
    stack[0] = v_17165;
    v_17165 = stack[0];
    v_17165 = sub1(v_17165);
    env = stack[-7];
    v_17165 = Lmkvect(nil, v_17165);
    env = stack[-7];
    stack[-5] = v_17165;
    v_17165 = stack[0];
    v_17165 = sub1(v_17165);
    env = stack[-7];
    fn = elt(env, 4); // mkvect16
    v_17165 = (*qfn1(fn))(fn, v_17165);
    env = stack[-7];
    stack[-3] = v_17165;
    v_17165 = stack[0];
    v_17165 = sub1(v_17165);
    env = stack[-7];
    fn = elt(env, 5); // mkvect8
    v_17165 = (*qfn1(fn))(fn, v_17165);
    env = stack[-7];
    stack[-2] = v_17165;
    v_17165 = stack[-6];
    stack[-1] = v_17165;
v_17071:
    v_17165 = stack[-1];
    if (v_17165 == nil) goto v_17075;
    else goto v_17076;
v_17075:
    goto v_17070;
v_17076:
    v_17165 = stack[-1];
    v_17165 = qcar(v_17165);
    stack[0] = v_17165;
    v_17165 = stack[0];
    v_17165 = qcdr(v_17165);
    stack[-4] = v_17165;
    v_17165 = stack[0];
    v_17165 = qcar(v_17165);
    v_17165 = qcar(v_17165);
    v_17165 = qcdr(v_17165);
    stack[-6] = v_17165;
    goto v_17093;
v_17089:
    v_17165 = stack[0];
    v_17165 = qcar(v_17165);
    v_17165 = qcar(v_17165);
    v_17166 = qcar(v_17165);
    goto v_17090;
v_17091:
    v_17165 = elt(env, 2); // lalr_nonterminal_code
    goto v_17092;
v_17093:
    goto v_17089;
v_17090:
    goto v_17091;
v_17092:
    v_17165 = get(v_17166, v_17165);
    env = stack[-7];
    goto v_17106;
v_17100:
    v_17167 = stack[-3];
    goto v_17101;
v_17102:
    v_17166 = stack[-4];
    goto v_17103;
v_17104:
    goto v_17105;
v_17106:
    goto v_17100;
v_17101:
    goto v_17102;
v_17103:
    goto v_17104;
v_17105:
    fn = elt(env, 6); // putv16
    v_17165 = (*qfnn(fn))(fn, 3, v_17167, v_17166, v_17165);
    env = stack[-7];
    goto v_17117;
v_17111:
    v_17167 = stack[-2];
    goto v_17112;
v_17113:
    v_17166 = stack[-4];
    goto v_17114;
v_17115:
    v_17165 = stack[-6];
    goto v_17116;
v_17117:
    goto v_17111;
v_17112:
    goto v_17113;
v_17114:
    goto v_17115;
v_17116:
    fn = elt(env, 7); // putv8
    v_17165 = (*qfnn(fn))(fn, 3, v_17167, v_17166, v_17165);
    env = stack[-7];
    v_17165 = stack[0];
    v_17165 = qcar(v_17165);
    v_17165 = qcdr(v_17165);
    if (v_17165 == nil) goto v_17124;
    v_17165 = stack[0];
    v_17165 = qcar(v_17165);
    v_17165 = qcdr(v_17165);
    goto v_17136;
v_17132:
    v_17166 = v_17165;
    goto v_17133;
v_17134:
    v_17165 = stack[-6];
    goto v_17135;
v_17136:
    goto v_17132;
v_17133:
    goto v_17134;
v_17135:
    fn = elt(env, 8); // lalr_construct_fn
    v_17165 = (*qfn2(fn))(fn, v_17166, v_17165);
    env = stack[-7];
    goto v_17122;
v_17124:
    v_17165 = nil;
    goto v_17122;
v_17122:
    goto v_17148;
v_17142:
    v_17167 = stack[-5];
    goto v_17143;
v_17144:
    v_17166 = stack[-4];
    goto v_17145;
v_17146:
    goto v_17147;
v_17148:
    goto v_17142;
v_17143:
    goto v_17144;
v_17145:
    goto v_17146;
v_17147:
    *(LispObject *)((char *)v_17167 + (CELL-TAG_VECTOR) + (((intptr_t)v_17166-TAG_FIXNUM)/(16/CELL))) = v_17165;
    v_17165 = stack[-1];
    v_17165 = qcdr(v_17165);
    stack[-1] = v_17165;
    goto v_17071;
v_17070:
    goto v_17161;
v_17155:
    v_17167 = stack[-5];
    goto v_17156;
v_17157:
    v_17166 = stack[-2];
    goto v_17158;
v_17159:
    v_17165 = stack[-3];
    goto v_17160;
v_17161:
    goto v_17155;
v_17156:
    goto v_17157;
v_17158:
    goto v_17159;
v_17160:
    return list3(v_17167, v_17166, v_17165);
    return onevalue(v_17165);
}



// Code for gcref_off1

static LispObject CC_gcref_off1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17186, v_17187, v_17188;
    LispObject fn;
    argcheck(nargs, 0, "gcref_off1");
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
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// end of prologue
    v_17186 = nil;
    qvalue(elt(env, 1)) = v_17186; // dfprint!*
    v_17186 = nil;
    qvalue(elt(env, 2)) = v_17186; // !*defn
    v_17186 = qvalue(elt(env, 3)); // !*algebraics
    if (v_17186 == nil) goto v_16964;
    else goto v_16965;
v_16964:
    goto v_16972;
v_16968:
    v_17187 = elt(env, 4); // algebraic
    goto v_16969;
v_16970:
    v_17186 = elt(env, 5); // newnam
    goto v_16971;
v_16972:
    goto v_16968;
v_16969:
    goto v_16970;
v_16971:
    v_17186 = Lremprop(nil, v_17187, v_17186);
    env = stack[-8];
    goto v_16963;
v_16965:
v_16963:
    v_17186 = qvalue(elt(env, 6)); // seen!*
    stack[-1] = v_17186;
v_16978:
    v_17186 = stack[-1];
    if (v_17186 == nil) goto v_16982;
    else goto v_16983;
v_16982:
    goto v_16977;
v_16983:
    v_17186 = stack[-1];
    v_17186 = qcar(v_17186);
    stack[0] = v_17186;
    goto v_16998;
v_16994:
    v_17187 = stack[0];
    goto v_16995;
v_16996:
    v_17186 = elt(env, 7); // calledby
    goto v_16997;
v_16998:
    goto v_16994;
v_16995:
    goto v_16996;
v_16997:
    v_17186 = get(v_17187, v_17186);
    env = stack[-8];
    if (v_17186 == nil) goto v_16991;
    else goto v_16992;
v_16991:
    goto v_17006;
v_17002:
    v_17187 = stack[0];
    goto v_17003;
v_17004:
    v_17186 = qvalue(elt(env, 8)); // entpts!*
    goto v_17005;
v_17006:
    goto v_17002;
v_17003:
    goto v_17004;
v_17005:
    v_17186 = cons(v_17187, v_17186);
    env = stack[-8];
    qvalue(elt(env, 8)) = v_17186; // entpts!*
    goto v_16990;
v_16992:
v_16990:
    v_17186 = stack[0];
    fn = elt(env, 16); // undefdchk
    v_17186 = (*qfn1(fn))(fn, v_17186);
    env = stack[-8];
    v_17186 = stack[-1];
    v_17186 = qcdr(v_17186);
    stack[-1] = v_17186;
    goto v_16978;
v_16977:
    v_17186 = qvalue(elt(env, 9)); // tseen!*
    fn = elt(env, 17); // idsort
    v_17186 = (*qfn1(fn))(fn, v_17186);
    env = stack[-8];
    stack[-6] = v_17186;
    v_17186 = stack[-6];
    if (v_17186 == nil) goto v_17023;
    else goto v_17024;
v_17023:
    v_17186 = nil;
    goto v_17017;
v_17024:
    v_17186 = stack[-6];
    v_17186 = qcar(v_17186);
    stack[-2] = v_17186;
    goto v_17036;
v_17032:
    v_17187 = stack[-2];
    goto v_17033;
v_17034:
    v_17186 = elt(env, 10); // tseen
    goto v_17035;
v_17036:
    goto v_17032;
v_17033:
    goto v_17034;
v_17035:
    v_17186 = Lremprop(nil, v_17187, v_17186);
    env = stack[-8];
    goto v_17048;
v_17044:
    v_17187 = stack[-2];
    goto v_17045;
v_17046:
    v_17186 = elt(env, 11); // funs
    goto v_17047;
v_17048:
    goto v_17044;
v_17045:
    goto v_17046;
v_17047:
    v_17186 = get(v_17187, v_17186);
    env = stack[-8];
    stack[-7] = v_17186;
    stack[-1] = v_17186;
v_17042:
    v_17186 = stack[-1];
    if (v_17186 == nil) goto v_17053;
    else goto v_17054;
v_17053:
    goto v_17041;
v_17054:
    v_17186 = stack[-1];
    v_17186 = qcar(v_17186);
    stack[0] = v_17186;
    v_17186 = stack[0];
    fn = elt(env, 16); // undefdchk
    v_17186 = (*qfn1(fn))(fn, v_17186);
    env = stack[-8];
    goto v_17067;
v_17063:
    v_17187 = stack[0];
    goto v_17064;
v_17065:
    v_17186 = elt(env, 12); // rccnam
    goto v_17066;
v_17067:
    goto v_17063;
v_17064:
    goto v_17065;
v_17066:
    v_17186 = Lremprop(nil, v_17187, v_17186);
    env = stack[-8];
    v_17186 = stack[-1];
    v_17186 = qcdr(v_17186);
    stack[-1] = v_17186;
    goto v_17042;
v_17041:
    goto v_17077;
v_17073:
    v_17187 = stack[-2];
    goto v_17074;
v_17075:
    v_17186 = stack[-7];
    goto v_17076;
v_17077:
    goto v_17073;
v_17074:
    goto v_17075;
v_17076:
    v_17186 = cons(v_17187, v_17186);
    env = stack[-8];
    v_17186 = ncons(v_17186);
    env = stack[-8];
    stack[-4] = v_17186;
    stack[-5] = v_17186;
v_17018:
    v_17186 = stack[-6];
    v_17186 = qcdr(v_17186);
    stack[-6] = v_17186;
    v_17186 = stack[-6];
    if (v_17186 == nil) goto v_17084;
    else goto v_17085;
v_17084:
    v_17186 = stack[-5];
    goto v_17017;
v_17085:
    goto v_17093;
v_17089:
    stack[-3] = stack[-4];
    goto v_17090;
v_17091:
    v_17186 = stack[-6];
    v_17186 = qcar(v_17186);
    stack[-2] = v_17186;
    goto v_17104;
v_17100:
    v_17187 = stack[-2];
    goto v_17101;
v_17102:
    v_17186 = elt(env, 10); // tseen
    goto v_17103;
v_17104:
    goto v_17100;
v_17101:
    goto v_17102;
v_17103:
    v_17186 = Lremprop(nil, v_17187, v_17186);
    env = stack[-8];
    goto v_17116;
v_17112:
    v_17187 = stack[-2];
    goto v_17113;
v_17114:
    v_17186 = elt(env, 11); // funs
    goto v_17115;
v_17116:
    goto v_17112;
v_17113:
    goto v_17114;
v_17115:
    v_17186 = get(v_17187, v_17186);
    env = stack[-8];
    stack[-7] = v_17186;
    stack[-1] = v_17186;
v_17110:
    v_17186 = stack[-1];
    if (v_17186 == nil) goto v_17121;
    else goto v_17122;
v_17121:
    goto v_17109;
v_17122:
    v_17186 = stack[-1];
    v_17186 = qcar(v_17186);
    stack[0] = v_17186;
    v_17186 = stack[0];
    fn = elt(env, 16); // undefdchk
    v_17186 = (*qfn1(fn))(fn, v_17186);
    env = stack[-8];
    goto v_17135;
v_17131:
    v_17187 = stack[0];
    goto v_17132;
v_17133:
    v_17186 = elt(env, 12); // rccnam
    goto v_17134;
v_17135:
    goto v_17131;
v_17132:
    goto v_17133;
v_17134:
    v_17186 = Lremprop(nil, v_17187, v_17186);
    env = stack[-8];
    v_17186 = stack[-1];
    v_17186 = qcdr(v_17186);
    stack[-1] = v_17186;
    goto v_17110;
v_17109:
    goto v_17145;
v_17141:
    v_17187 = stack[-2];
    goto v_17142;
v_17143:
    v_17186 = stack[-7];
    goto v_17144;
v_17145:
    goto v_17141;
v_17142:
    goto v_17143;
v_17144:
    v_17186 = cons(v_17187, v_17186);
    env = stack[-8];
    v_17186 = ncons(v_17186);
    env = stack[-8];
    goto v_17092;
v_17093:
    goto v_17089;
v_17090:
    goto v_17091;
v_17092:
    v_17186 = Lrplacd(nil, stack[-3], v_17186);
    env = stack[-8];
    v_17186 = stack[-4];
    v_17186 = qcdr(v_17186);
    stack[-4] = v_17186;
    goto v_17018;
v_17017:
    qvalue(elt(env, 9)) = v_17186; // tseen!*
    v_17186 = qvalue(elt(env, 13)); // gseen!*
    stack[0] = v_17186;
v_17153:
    v_17186 = stack[0];
    if (v_17186 == nil) goto v_17157;
    else goto v_17158;
v_17157:
    goto v_17152;
v_17158:
    v_17186 = stack[0];
    v_17186 = qcar(v_17186);
    v_17188 = v_17186;
    goto v_17173;
v_17169:
    v_17187 = v_17188;
    goto v_17170;
v_17171:
    v_17186 = elt(env, 14); // usedunby
    goto v_17172;
v_17173:
    goto v_17169;
v_17170:
    goto v_17171;
v_17172:
    v_17186 = get(v_17187, v_17186);
    env = stack[-8];
    if (v_17186 == nil) goto v_17167;
    goto v_17181;
v_17177:
    v_17187 = v_17188;
    goto v_17178;
v_17179:
    v_17186 = qvalue(elt(env, 15)); // undefg!*
    goto v_17180;
v_17181:
    goto v_17177;
v_17178:
    goto v_17179;
v_17180:
    v_17186 = cons(v_17187, v_17186);
    env = stack[-8];
    qvalue(elt(env, 15)) = v_17186; // undefg!*
    goto v_17165;
v_17167:
v_17165:
    v_17186 = stack[0];
    v_17186 = qcdr(v_17186);
    stack[0] = v_17186;
    goto v_17153;
v_17152:
    v_17186 = nil;
    return onevalue(v_17186);
}



// Code for talp_noffcts

static LispObject CC_talp_noffcts(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16993, v_16994;
    LispObject fn;
    argcheck(nargs, 0, "talp_noffcts");
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
    v_16993 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_16993;
    fn = elt(env, 1); // talp_getl
    v_16993 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[0] = v_16993;
v_16964:
    v_16993 = stack[0];
    if (v_16993 == nil) goto v_16968;
    else goto v_16969;
v_16968:
    goto v_16963;
v_16969:
    v_16993 = stack[0];
    v_16993 = qcar(v_16993);
    goto v_16984;
v_16980:
    v_16994 = qcdr(v_16993);
    goto v_16981;
v_16982:
    v_16993 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16983;
v_16984:
    goto v_16980;
v_16981:
    goto v_16982;
v_16983:
    v_16993 = (LispObject)greaterp2(v_16994, v_16993);
    v_16993 = v_16993 ? lisp_true : nil;
    env = stack[-2];
    if (v_16993 == nil) goto v_16978;
    v_16993 = stack[-1];
    v_16993 = add1(v_16993);
    env = stack[-2];
    stack[-1] = v_16993;
    goto v_16976;
v_16978:
v_16976:
    v_16993 = stack[0];
    v_16993 = qcdr(v_16993);
    stack[0] = v_16993;
    goto v_16964;
v_16963:
    v_16993 = stack[-1];
    return onevalue(v_16993);
}



// Code for pasf_dt

static LispObject CC_pasf_dt(LispObject env,
                         LispObject v_16956)
{
    env = qenv(env);
    LispObject v_17327, v_17328, v_17329, v_17330;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16956);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16956);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_16956;
// end of prologue
    goto v_16974;
v_16970:
    v_17328 = stack[0];
    goto v_16971;
v_16972:
    v_17327 = elt(env, 1); // true
    goto v_16973;
v_16974:
    goto v_16970;
v_16971:
    goto v_16972;
v_16973:
    if (v_17328 == v_17327) goto v_16968;
    else goto v_16969;
v_16968:
    v_17327 = lisp_true;
    goto v_16967;
v_16969:
    goto v_16984;
v_16980:
    v_17328 = stack[0];
    goto v_16981;
v_16982:
    v_17327 = elt(env, 2); // false
    goto v_16983;
v_16984:
    goto v_16980;
v_16981:
    goto v_16982;
v_16983:
    v_17327 = (v_17328 == v_17327 ? lisp_true : nil);
    goto v_16967;
    v_17327 = nil;
v_16967:
    if (v_17327 == nil) goto v_16965;
    v_17327 = stack[0];
    goto v_16961;
v_16965:
    v_17327 = stack[0];
    v_17327 = qcdr(v_17327);
    v_17327 = qcar(v_17327);
    fn = elt(env, 16); // pasf_pdp
    v_17327 = (*qfn1(fn))(fn, v_17327);
    env = stack[-1];
    v_17330 = v_17327;
    goto v_17005;
v_17001:
    v_17328 = stack[0];
    goto v_17002;
v_17003:
    v_17327 = elt(env, 1); // true
    goto v_17004;
v_17005:
    goto v_17001;
v_17002:
    goto v_17003;
v_17004:
    if (v_17328 == v_17327) goto v_16999;
    else goto v_17000;
v_16999:
    v_17327 = lisp_true;
    goto v_16998;
v_17000:
    goto v_17015;
v_17011:
    v_17328 = stack[0];
    goto v_17012;
v_17013:
    v_17327 = elt(env, 2); // false
    goto v_17014;
v_17015:
    goto v_17011;
v_17012:
    goto v_17013;
v_17014:
    v_17327 = (v_17328 == v_17327 ? lisp_true : nil);
    goto v_16998;
    v_17327 = nil;
v_16998:
    if (v_17327 == nil) goto v_16996;
    v_17327 = stack[0];
    goto v_16994;
v_16996:
    v_17327 = stack[0];
    v_17327 = qcar(v_17327);
    v_17327 = Lconsp(nil, v_17327);
    env = stack[-1];
    if (v_17327 == nil) goto v_17021;
    v_17327 = stack[0];
    v_17327 = qcar(v_17327);
    v_17327 = qcar(v_17327);
    goto v_16994;
v_17021:
    v_17327 = stack[0];
    v_17327 = qcar(v_17327);
    goto v_16994;
    v_17327 = nil;
v_16994:
    v_17329 = v_17327;
    goto v_17044;
v_17040:
    v_17328 = v_17330;
    goto v_17041;
v_17042:
    v_17327 = elt(env, 3); // pdef
    goto v_17043;
v_17044:
    goto v_17040;
v_17041:
    goto v_17042;
v_17043:
    if (v_17328 == v_17327) goto v_17038;
    else goto v_17039;
v_17038:
    goto v_17051;
v_17047:
    v_17328 = v_17329;
    goto v_17048;
v_17049:
    v_17327 = elt(env, 4); // (equal lessp leq)
    goto v_17050;
v_17051:
    goto v_17047;
v_17048:
    goto v_17049;
v_17050:
    v_17327 = Lmemq(nil, v_17328, v_17327);
    goto v_17037;
v_17039:
    v_17327 = nil;
    goto v_17037;
    v_17327 = nil;
v_17037:
    if (v_17327 == nil) goto v_17035;
    v_17327 = elt(env, 2); // false
    goto v_16961;
v_17035:
    goto v_17071;
v_17067:
    v_17328 = v_17330;
    goto v_17068;
v_17069:
    v_17327 = elt(env, 5); // ndef
    goto v_17070;
v_17071:
    goto v_17067;
v_17068:
    goto v_17069;
v_17070:
    if (v_17328 == v_17327) goto v_17065;
    else goto v_17066;
v_17065:
    goto v_17078;
v_17074:
    v_17328 = v_17329;
    goto v_17075;
v_17076:
    v_17327 = elt(env, 6); // (equal greaterp geq)
    goto v_17077;
v_17078:
    goto v_17074;
v_17075:
    goto v_17076;
v_17077:
    v_17327 = Lmemq(nil, v_17328, v_17327);
    goto v_17064;
v_17066:
    v_17327 = nil;
    goto v_17064;
    v_17327 = nil;
v_17064:
    if (v_17327 == nil) goto v_17062;
    v_17327 = elt(env, 2); // false
    goto v_16961;
v_17062:
    goto v_17098;
v_17094:
    v_17328 = v_17330;
    goto v_17095;
v_17096:
    v_17327 = elt(env, 3); // pdef
    goto v_17097;
v_17098:
    goto v_17094;
v_17095:
    goto v_17096;
v_17097:
    if (v_17328 == v_17327) goto v_17092;
    else goto v_17093;
v_17092:
    goto v_17105;
v_17101:
    v_17328 = v_17329;
    goto v_17102;
v_17103:
    v_17327 = elt(env, 7); // (neq greaterp geq)
    goto v_17104;
v_17105:
    goto v_17101;
v_17102:
    goto v_17103;
v_17104:
    v_17327 = Lmemq(nil, v_17328, v_17327);
    goto v_17091;
v_17093:
    v_17327 = nil;
    goto v_17091;
    v_17327 = nil;
v_17091:
    if (v_17327 == nil) goto v_17089;
    v_17327 = elt(env, 1); // true
    goto v_16961;
v_17089:
    goto v_17125;
v_17121:
    v_17328 = v_17330;
    goto v_17122;
v_17123:
    v_17327 = elt(env, 5); // ndef
    goto v_17124;
v_17125:
    goto v_17121;
v_17122:
    goto v_17123;
v_17124:
    if (v_17328 == v_17327) goto v_17119;
    else goto v_17120;
v_17119:
    goto v_17132;
v_17128:
    v_17328 = v_17329;
    goto v_17129;
v_17130:
    v_17327 = elt(env, 8); // (neq lessp leq)
    goto v_17131;
v_17132:
    goto v_17128;
v_17129:
    goto v_17130;
v_17131:
    v_17327 = Lmemq(nil, v_17328, v_17327);
    goto v_17118;
v_17120:
    v_17327 = nil;
    goto v_17118;
    v_17327 = nil;
v_17118:
    if (v_17327 == nil) goto v_17116;
    v_17327 = elt(env, 1); // true
    goto v_16961;
v_17116:
    goto v_17152;
v_17148:
    v_17328 = v_17330;
    goto v_17149;
v_17150:
    v_17327 = elt(env, 9); // psdef
    goto v_17151;
v_17152:
    goto v_17148;
v_17149:
    goto v_17150;
v_17151:
    if (v_17328 == v_17327) goto v_17146;
    else goto v_17147;
v_17146:
    goto v_17159;
v_17155:
    v_17328 = v_17329;
    goto v_17156;
v_17157:
    v_17327 = elt(env, 10); // lessp
    goto v_17158;
v_17159:
    goto v_17155;
v_17156:
    goto v_17157;
v_17158:
    v_17327 = (v_17328 == v_17327 ? lisp_true : nil);
    goto v_17145;
v_17147:
    v_17327 = nil;
    goto v_17145;
    v_17327 = nil;
v_17145:
    if (v_17327 == nil) goto v_17143;
    v_17327 = elt(env, 2); // false
    goto v_16961;
v_17143:
    goto v_17179;
v_17175:
    v_17328 = v_17330;
    goto v_17176;
v_17177:
    v_17327 = elt(env, 11); // nsdef
    goto v_17178;
v_17179:
    goto v_17175;
v_17176:
    goto v_17177;
v_17178:
    if (v_17328 == v_17327) goto v_17173;
    else goto v_17174;
v_17173:
    goto v_17186;
v_17182:
    v_17328 = v_17329;
    goto v_17183;
v_17184:
    v_17327 = elt(env, 12); // greaterp
    goto v_17185;
v_17186:
    goto v_17182;
v_17183:
    goto v_17184;
v_17185:
    v_17327 = (v_17328 == v_17327 ? lisp_true : nil);
    goto v_17172;
v_17174:
    v_17327 = nil;
    goto v_17172;
    v_17327 = nil;
v_17172:
    if (v_17327 == nil) goto v_17170;
    v_17327 = elt(env, 2); // false
    goto v_16961;
v_17170:
    goto v_17206;
v_17202:
    v_17328 = v_17330;
    goto v_17203;
v_17204:
    v_17327 = elt(env, 9); // psdef
    goto v_17205;
v_17206:
    goto v_17202;
v_17203:
    goto v_17204;
v_17205:
    if (v_17328 == v_17327) goto v_17200;
    else goto v_17201;
v_17200:
    goto v_17213;
v_17209:
    v_17328 = v_17329;
    goto v_17210;
v_17211:
    v_17327 = elt(env, 13); // geq
    goto v_17212;
v_17213:
    goto v_17209;
v_17210:
    goto v_17211;
v_17212:
    v_17327 = (v_17328 == v_17327 ? lisp_true : nil);
    goto v_17199;
v_17201:
    v_17327 = nil;
    goto v_17199;
    v_17327 = nil;
v_17199:
    if (v_17327 == nil) goto v_17197;
    v_17327 = elt(env, 1); // true
    goto v_16961;
v_17197:
    goto v_17233;
v_17229:
    v_17328 = v_17330;
    goto v_17230;
v_17231:
    v_17327 = elt(env, 11); // nsdef
    goto v_17232;
v_17233:
    goto v_17229;
v_17230:
    goto v_17231;
v_17232:
    if (v_17328 == v_17327) goto v_17227;
    else goto v_17228;
v_17227:
    goto v_17240;
v_17236:
    v_17328 = v_17329;
    goto v_17237;
v_17238:
    v_17327 = elt(env, 14); // leq
    goto v_17239;
v_17240:
    goto v_17236;
v_17237:
    goto v_17238;
v_17239:
    v_17327 = (v_17328 == v_17327 ? lisp_true : nil);
    goto v_17226;
v_17228:
    v_17327 = nil;
    goto v_17226;
    v_17327 = nil;
v_17226:
    if (v_17327 == nil) goto v_17224;
    v_17327 = elt(env, 1); // true
    goto v_16961;
v_17224:
    goto v_17260;
v_17256:
    v_17328 = v_17330;
    goto v_17257;
v_17258:
    v_17327 = elt(env, 9); // psdef
    goto v_17259;
v_17260:
    goto v_17256;
v_17257:
    goto v_17258;
v_17259:
    if (v_17328 == v_17327) goto v_17254;
    else goto v_17255;
v_17254:
    goto v_17267;
v_17263:
    v_17328 = v_17329;
    goto v_17264;
v_17265:
    v_17327 = elt(env, 15); // neq
    goto v_17266;
v_17267:
    goto v_17263;
v_17264:
    goto v_17265;
v_17266:
    v_17327 = (v_17328 == v_17327 ? lisp_true : nil);
    goto v_17253;
v_17255:
    v_17327 = nil;
    goto v_17253;
    v_17327 = nil;
v_17253:
    if (v_17327 == nil) goto v_17251;
    goto v_17281;
v_17275:
    v_17329 = elt(env, 12); // greaterp
    goto v_17276;
v_17277:
    v_17327 = stack[0];
    v_17327 = qcdr(v_17327);
    v_17328 = qcar(v_17327);
    goto v_17278;
v_17279:
    v_17327 = nil;
    goto v_17280;
v_17281:
    goto v_17275;
v_17276:
    goto v_17277;
v_17278:
    goto v_17279;
v_17280:
    return list3(v_17329, v_17328, v_17327);
v_17251:
    goto v_17299;
v_17295:
    v_17328 = v_17330;
    goto v_17296;
v_17297:
    v_17327 = elt(env, 11); // nsdef
    goto v_17298;
v_17299:
    goto v_17295;
v_17296:
    goto v_17297;
v_17298:
    if (v_17328 == v_17327) goto v_17293;
    else goto v_17294;
v_17293:
    goto v_17306;
v_17302:
    v_17328 = v_17329;
    goto v_17303;
v_17304:
    v_17327 = elt(env, 15); // neq
    goto v_17305;
v_17306:
    goto v_17302;
v_17303:
    goto v_17304;
v_17305:
    v_17327 = (v_17328 == v_17327 ? lisp_true : nil);
    goto v_17292;
v_17294:
    v_17327 = nil;
    goto v_17292;
    v_17327 = nil;
v_17292:
    if (v_17327 == nil) goto v_17290;
    goto v_17320;
v_17314:
    v_17329 = elt(env, 10); // lessp
    goto v_17315;
v_17316:
    v_17327 = stack[0];
    v_17327 = qcdr(v_17327);
    v_17328 = qcar(v_17327);
    goto v_17317;
v_17318:
    v_17327 = nil;
    goto v_17319;
v_17320:
    goto v_17314;
v_17315:
    goto v_17316;
v_17317:
    goto v_17318;
v_17319:
    return list3(v_17329, v_17328, v_17327);
v_17290:
    v_17327 = stack[0];
v_16961:
    return onevalue(v_17327);
}



// Code for containerml

static LispObject CC_containerml(LispObject env,
                         LispObject v_16956, LispObject v_16957)
{
    env = qenv(env);
    LispObject v_16999, v_17000;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16957,v_16956);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16956,v_16957);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_16957;
    stack[-1] = v_16956;
// end of prologue
    goto v_16969;
v_16965:
    v_17000 = stack[0];
    goto v_16966;
v_16967:
    v_16999 = elt(env, 1); // integer_interval
    goto v_16968;
v_16969:
    goto v_16965;
v_16966:
    goto v_16967;
v_16968:
    if (v_17000 == v_16999) goto v_16963;
    else goto v_16964;
v_16963:
    v_16999 = elt(env, 2); // interval
    stack[0] = v_16999;
    goto v_16962;
v_16964:
v_16962:
    v_16999 = elt(env, 3); // "<"
    fn = elt(env, 7); // printout
    v_16999 = (*qfn1(fn))(fn, v_16999);
    env = stack[-2];
    v_16999 = stack[0];
    v_16999 = Lprinc(nil, v_16999);
    env = stack[-2];
    goto v_16982;
v_16978:
    v_16999 = stack[-1];
    v_17000 = qcar(v_16999);
    goto v_16979;
v_16980:
    v_16999 = elt(env, 4); // ""
    goto v_16981;
v_16982:
    goto v_16978;
v_16979:
    goto v_16980;
v_16981:
    fn = elt(env, 8); // attributesml
    v_16999 = (*qfn2(fn))(fn, v_17000, v_16999);
    env = stack[-2];
    v_16999 = lisp_true;
    fn = elt(env, 9); // indent!*
    v_16999 = (*qfn1(fn))(fn, v_16999);
    env = stack[-2];
    v_16999 = stack[-1];
    v_16999 = qcdr(v_16999);
    fn = elt(env, 10); // multi_elem
    v_16999 = (*qfn1(fn))(fn, v_16999);
    env = stack[-2];
    v_16999 = nil;
    fn = elt(env, 9); // indent!*
    v_16999 = (*qfn1(fn))(fn, v_16999);
    env = stack[-2];
    v_16999 = elt(env, 5); // "</"
    fn = elt(env, 7); // printout
    v_16999 = (*qfn1(fn))(fn, v_16999);
    env = stack[-2];
    v_16999 = stack[0];
    v_16999 = Lprinc(nil, v_16999);
    env = stack[-2];
    v_16999 = elt(env, 6); // ">"
    v_16999 = Lprinc(nil, v_16999);
    v_16999 = nil;
    return onevalue(v_16999);
}



// Code for sc_getrow

static LispObject CC_sc_getrow(LispObject env,
                         LispObject v_16956, LispObject v_16957)
{
    env = qenv(env);
    LispObject v_16968, v_16969;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16957,v_16956);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16956,v_16957);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_16968 = v_16957;
    v_16969 = v_16956;
// end of prologue
    goto v_16964;
v_16960:
    stack[0] = v_16969;
    goto v_16961;
v_16962:
    v_16968 = sub1(v_16968);
    env = stack[-1];
    goto v_16963;
v_16964:
    goto v_16960;
v_16961:
    goto v_16962;
v_16963:
    {
        LispObject v_16971 = stack[0];
        fn = elt(env, 1); // sc_igetv
        return (*qfn2(fn))(fn, v_16971, v_16968);
    }
}



// Code for xriterion_1

static LispObject CC_xriterion_1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17137, v_17138, v_17139;
    LispObject fn;
    LispObject v_16958, v_16957, v_16956;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xriterion_1");
    va_start(aa, nargs);
    v_16956 = va_arg(aa, LispObject);
    v_16957 = va_arg(aa, LispObject);
    v_16958 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_16958,v_16957,v_16956);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_16956,v_16957,v_16958);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_16958;
    stack[-1] = v_16957;
    stack[-2] = v_16956;
// end of prologue
v_16955:
    v_17137 = stack[-1];
    if (v_17137 == nil) goto v_16962;
    else goto v_16963;
v_16962:
    v_17137 = nil;
    goto v_16961;
v_16963:
    goto v_16972;
v_16968:
    v_17137 = stack[-2];
    v_17137 = qcdr(v_17137);
    v_17138 = qcar(v_17137);
    goto v_16969;
v_16970:
    v_17137 = elt(env, 1); // spoly_pair
    goto v_16971;
v_16972:
    goto v_16968;
v_16969:
    goto v_16970;
v_16971:
    if (v_17138 == v_17137) goto v_16967;
    v_17137 = nil;
    goto v_16961;
v_16967:
    v_17137 = stack[-1];
    v_17137 = qcar(v_17137);
    stack[-3] = v_17137;
    goto v_16994;
v_16990:
    v_17138 = stack[-3];
    goto v_16991;
v_16992:
    v_17137 = stack[-2];
    v_17137 = qcdr(v_17137);
    v_17137 = qcdr(v_17137);
    v_17137 = qcar(v_17137);
    goto v_16993;
v_16994:
    goto v_16990;
v_16991:
    goto v_16992;
v_16993:
    if (equal(v_17138, v_17137)) goto v_16989;
    goto v_17008;
v_17004:
    v_17138 = stack[-3];
    goto v_17005;
v_17006:
    v_17137 = stack[-2];
    v_17137 = qcdr(v_17137);
    v_17137 = qcdr(v_17137);
    v_17137 = qcdr(v_17137);
    v_17137 = qcar(v_17137);
    goto v_17007;
v_17008:
    goto v_17004;
v_17005:
    goto v_17006;
v_17007:
    if (equal(v_17138, v_17137)) goto v_17003;
    goto v_17024;
v_17020:
    v_17137 = stack[-3];
    fn = elt(env, 5); // xval
    v_17138 = (*qfn1(fn))(fn, v_17137);
    env = stack[-4];
    goto v_17021;
v_17022:
    v_17137 = stack[-2];
    v_17137 = qcar(v_17137);
    goto v_17023;
v_17024:
    goto v_17020;
v_17021:
    goto v_17022;
v_17023:
    fn = elt(env, 6); // xdiv
    v_17137 = (*qfn2(fn))(fn, v_17138, v_17137);
    env = stack[-4];
    if (v_17137 == nil) goto v_17017;
    else goto v_17018;
v_17017:
    v_17137 = nil;
    goto v_17016;
v_17018:
    goto v_17041;
v_17037:
    v_17138 = stack[-3];
    goto v_17038;
v_17039:
    v_17137 = stack[-2];
    v_17137 = qcdr(v_17137);
    v_17137 = qcdr(v_17137);
    v_17137 = qcar(v_17137);
    goto v_17040;
v_17041:
    goto v_17037;
v_17038:
    goto v_17039;
v_17040:
    fn = elt(env, 7); // make_spoly_pair
    v_17137 = (*qfn2(fn))(fn, v_17138, v_17137);
    env = stack[-4];
    v_17138 = v_17137;
    v_17137 = v_17138;
    if (v_17137 == nil) goto v_17050;
    else goto v_17051;
v_17050:
    v_17137 = lisp_true;
    goto v_17049;
v_17051:
    goto v_17061;
v_17057:
    goto v_17058;
v_17059:
    v_17137 = stack[0];
    goto v_17060;
v_17061:
    goto v_17057;
v_17058:
    goto v_17059;
v_17060:
    fn = elt(env, 8); // find_item
    v_17137 = (*qfn2(fn))(fn, v_17138, v_17137);
    env = stack[-4];
    v_17137 = (v_17137 == nil ? lisp_true : nil);
    goto v_17049;
    v_17137 = nil;
v_17049:
    if (v_17137 == nil) goto v_17034;
    else goto v_17035;
v_17034:
    v_17137 = nil;
    goto v_17033;
v_17035:
    goto v_17077;
v_17073:
    v_17138 = stack[-3];
    goto v_17074;
v_17075:
    v_17137 = stack[-2];
    v_17137 = qcdr(v_17137);
    v_17137 = qcdr(v_17137);
    v_17137 = qcdr(v_17137);
    v_17137 = qcar(v_17137);
    goto v_17076;
v_17077:
    goto v_17073;
v_17074:
    goto v_17075;
v_17076:
    fn = elt(env, 7); // make_spoly_pair
    v_17137 = (*qfn2(fn))(fn, v_17138, v_17137);
    env = stack[-4];
    v_17138 = v_17137;
    v_17137 = v_17138;
    if (v_17137 == nil) goto v_17087;
    else goto v_17088;
v_17087:
    v_17137 = lisp_true;
    goto v_17086;
v_17088:
    goto v_17098;
v_17094:
    goto v_17095;
v_17096:
    v_17137 = stack[0];
    goto v_17097;
v_17098:
    goto v_17094;
v_17095:
    goto v_17096;
v_17097:
    fn = elt(env, 8); // find_item
    v_17137 = (*qfn2(fn))(fn, v_17138, v_17137);
    env = stack[-4];
    v_17137 = (v_17137 == nil ? lisp_true : nil);
    goto v_17086;
    v_17137 = nil;
v_17086:
    if (v_17137 == nil) goto v_17070;
    else goto v_17071;
v_17070:
    v_17137 = nil;
    goto v_17069;
v_17071:
    v_17137 = qvalue(elt(env, 2)); // !*trxideal
    if (v_17137 == nil) goto v_17108;
    goto v_17115;
v_17111:
    v_17138 = elt(env, 3); // "criterion 1 hit"
    goto v_17112;
v_17113:
    v_17137 = elt(env, 4); // last
    goto v_17114;
v_17115:
    goto v_17111;
v_17112:
    goto v_17113;
v_17114:
    fn = elt(env, 9); // writepri
    v_17137 = (*qfn2(fn))(fn, v_17138, v_17137);
    env = stack[-4];
    goto v_17106;
v_17108:
v_17106:
    v_17137 = lisp_true;
    goto v_17069;
    v_17137 = nil;
v_17069:
    goto v_17033;
    v_17137 = nil;
v_17033:
    goto v_17016;
    v_17137 = nil;
v_17016:
    goto v_17001;
v_17003:
    v_17137 = nil;
    goto v_17001;
    v_17137 = nil;
v_17001:
    goto v_16987;
v_16989:
    v_17137 = nil;
    goto v_16987;
    v_17137 = nil;
v_16987:
    if (v_17137 == nil) goto v_16985;
    else goto v_16984;
v_16985:
    goto v_17132;
v_17126:
    v_17139 = stack[-2];
    goto v_17127;
v_17128:
    v_17137 = stack[-1];
    v_17138 = qcdr(v_17137);
    goto v_17129;
v_17130:
    v_17137 = stack[0];
    goto v_17131;
v_17132:
    goto v_17126;
v_17127:
    goto v_17128;
v_17129:
    goto v_17130;
v_17131:
    stack[-2] = v_17139;
    stack[-1] = v_17138;
    stack[0] = v_17137;
    goto v_16955;
v_16984:
    goto v_16961;
    v_17137 = nil;
v_16961:
    return onevalue(v_17137);
}



// Code for eqexpr

static LispObject CC_eqexpr(LispObject env,
                         LispObject v_16956)
{
    env = qenv(env);
    LispObject v_16997, v_16998, v_16999;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16956);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16956);
    }
// copy arguments values to proper place
    v_16999 = v_16956;
// end of prologue
    v_16997 = v_16999;
    if (!consp(v_16997)) goto v_16961;
    goto v_16972;
v_16968:
    v_16997 = v_16999;
    v_16998 = qcar(v_16997);
    goto v_16969;
v_16970:
    v_16997 = elt(env, 1); // equalopr
    goto v_16971;
v_16972:
    goto v_16968;
v_16969:
    goto v_16970;
v_16971:
    v_16997 = Lflagp(nil, v_16998, v_16997);
    if (v_16997 == nil) goto v_16966;
    v_16997 = v_16999;
    v_16997 = qcdr(v_16997);
    v_16997 = qcdr(v_16997);
    if (v_16997 == nil) goto v_16978;
    else goto v_16979;
v_16978:
    v_16997 = nil;
    goto v_16977;
v_16979:
    v_16997 = v_16999;
    v_16997 = qcdr(v_16997);
    v_16997 = qcdr(v_16997);
    v_16997 = qcdr(v_16997);
    v_16997 = (v_16997 == nil ? lisp_true : nil);
    goto v_16977;
    v_16997 = nil;
v_16977:
    goto v_16964;
v_16966:
    v_16997 = nil;
    goto v_16964;
    v_16997 = nil;
v_16964:
    goto v_16959;
v_16961:
    v_16997 = nil;
    goto v_16959;
    v_16997 = nil;
v_16959:
    return onevalue(v_16997);
}



// Code for one!-entryp

static LispObject CC_oneKentryp(LispObject env,
                         LispObject v_16956, LispObject v_16957)
{
    env = qenv(env);
    LispObject v_17001, v_17002;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16957,v_16956);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16956,v_16957);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_16957;
    stack[-1] = v_16956;
// end of prologue
v_16961:
    v_17001 = stack[0];
    if (!consp(v_17001)) goto v_16964;
    else goto v_16965;
v_16964:
    v_17001 = lisp_true;
    goto v_16960;
v_16965:
    goto v_16975;
v_16971:
    v_17002 = stack[-1];
    goto v_16972;
v_16973:
    v_17001 = stack[0];
    v_17001 = qcar(v_17001);
    goto v_16974;
v_16975:
    goto v_16971;
v_16972:
    goto v_16973;
v_16974:
    v_17001 = Lsmemq(nil, v_17002, v_17001);
    env = stack[-2];
    if (v_17001 == nil) goto v_16969;
    goto v_16988;
v_16984:
    v_17002 = stack[-1];
    goto v_16985;
v_16986:
    v_17001 = stack[0];
    v_17001 = qcdr(v_17001);
    goto v_16987;
v_16988:
    goto v_16984;
v_16985:
    goto v_16986;
v_16987:
    v_17001 = Lsmemq(nil, v_17002, v_17001);
    env = stack[-2];
    if (v_17001 == nil) goto v_16982;
    v_17001 = nil;
    goto v_16960;
v_16982:
    v_17001 = stack[0];
    v_17001 = qcar(v_17001);
    stack[0] = v_17001;
    goto v_16961;
    goto v_16963;
v_16969:
    v_17001 = stack[0];
    v_17001 = qcdr(v_17001);
    stack[0] = v_17001;
    goto v_16961;
v_16963:
    v_17001 = nil;
v_16960:
    return onevalue(v_17001);
}



// Code for comb

static LispObject CC_comb(LispObject env,
                         LispObject v_16956, LispObject v_16957)
{
    env = qenv(env);
    LispObject v_17066, v_17067, v_17068;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16957,v_16956);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16956,v_16957);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_16957;
    stack[-4] = v_16956;
// end of prologue
    stack[-5] = nil;
    goto v_16973;
v_16969:
    v_17067 = stack[-3];
    goto v_16970;
v_16971:
    v_17066 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16972;
v_16973:
    goto v_16969;
v_16970:
    goto v_16971;
v_16972:
    if (v_17067 == v_17066) goto v_16967;
    else goto v_16968;
v_16967:
    v_17066 = nil;
    return ncons(v_17066);
v_16968:
    goto v_16985;
v_16981:
    goto v_16991;
v_16987:
    v_17066 = stack[-4];
    v_17067 = Llength(nil, v_17066);
    env = stack[-6];
    goto v_16988;
v_16989:
    v_17066 = stack[-3];
    goto v_16990;
v_16991:
    goto v_16987;
v_16988:
    goto v_16989;
v_16990:
    v_17067 = difference2(v_17067, v_17066);
    env = stack[-6];
    stack[-2] = v_17067;
    goto v_16982;
v_16983:
    v_17066 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16984;
v_16985:
    goto v_16981;
v_16982:
    goto v_16983;
v_16984:
    v_17066 = (LispObject)lessp2(v_17067, v_17066);
    v_17066 = v_17066 ? lisp_true : nil;
    env = stack[-6];
    if (v_17066 == nil) goto v_16979;
    v_17066 = nil;
    goto v_16963;
v_16979:
    v_17066 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_17066;
v_17000:
    goto v_17012;
v_17008:
    v_17067 = stack[-2];
    goto v_17009;
v_17010:
    v_17066 = stack[-1];
    goto v_17011;
v_17012:
    goto v_17008;
v_17009:
    goto v_17010;
v_17011:
    v_17066 = difference2(v_17067, v_17066);
    env = stack[-6];
    v_17066 = Lminusp(nil, v_17066);
    env = stack[-6];
    if (v_17066 == nil) goto v_17005;
    goto v_16999;
v_17005:
    goto v_17021;
v_17017:
    v_17066 = stack[-4];
    stack[0] = qcdr(v_17066);
    goto v_17018;
v_17019:
    v_17066 = stack[-3];
    v_17066 = sub1(v_17066);
    env = stack[-6];
    goto v_17020;
v_17021:
    goto v_17017;
v_17018:
    goto v_17019;
v_17020:
    v_17066 = CC_comb(elt(env, 0), stack[0], v_17066);
    env = stack[-6];
    stack[0] = v_17066;
v_17029:
    v_17066 = stack[0];
    if (v_17066 == nil) goto v_17033;
    else goto v_17034;
v_17033:
    goto v_17028;
v_17034:
    v_17066 = stack[0];
    v_17066 = qcar(v_17066);
    goto v_17047;
v_17041:
    v_17067 = stack[-4];
    v_17068 = qcar(v_17067);
    goto v_17042;
v_17043:
    v_17067 = v_17066;
    goto v_17044;
v_17045:
    v_17066 = stack[-5];
    goto v_17046;
v_17047:
    goto v_17041;
v_17042:
    goto v_17043;
v_17044:
    goto v_17045;
v_17046:
    v_17066 = acons(v_17068, v_17067, v_17066);
    env = stack[-6];
    stack[-5] = v_17066;
    v_17066 = stack[0];
    v_17066 = qcdr(v_17066);
    stack[0] = v_17066;
    goto v_17029;
v_17028:
    v_17066 = stack[-4];
    v_17066 = qcdr(v_17066);
    stack[-4] = v_17066;
    v_17066 = stack[-1];
    v_17066 = add1(v_17066);
    env = stack[-6];
    stack[-1] = v_17066;
    goto v_17000;
v_16999:
    goto v_17063;
v_17059:
    v_17067 = stack[-4];
    goto v_17060;
v_17061:
    v_17066 = stack[-5];
    goto v_17062;
v_17063:
    goto v_17059;
v_17060:
    goto v_17061;
v_17062:
    return cons(v_17067, v_17066);
v_16963:
    return onevalue(v_17066);
}



setup_type const u32_setup[] =
{
    {"lex_basic_token",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex_basic_token},
    {"formproc",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formproc},
    {"monomgetfirstmultivar",   CC_monomgetfirstmultivar,TOO_MANY_1,WRONG_NO_1},
    {"sfto_updecf",             CC_sfto_updecf, TOO_MANY_1,    WRONG_NO_1},
    {"get_char_group",          CC_get_char_group,TOO_MANY_1,  WRONG_NO_1},
    {"lesspcdadr",              TOO_FEW_2,      CC_lesspcdadr, WRONG_NO_2},
    {"matrix_rows",             CC_matrix_rows, TOO_MANY_1,    WRONG_NO_1},
    {"add_minus",               CC_add_minus,   TOO_MANY_1,    WRONG_NO_1},
    {"insoccs",                 TOO_FEW_2,      CC_insoccs,    WRONG_NO_2},
    {"vdp2a",                   CC_vdp2a,       TOO_MANY_1,    WRONG_NO_1},
    {"overall_factor",          TOO_FEW_2,      CC_overall_factor,WRONG_NO_2},
    {"testchar1",               CC_testchar1,   TOO_MANY_1,    WRONG_NO_1},
    {"sign-of",                 CC_signKof,     TOO_MANY_1,    WRONG_NO_1},
    {"assert_stat-parse",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_assert_statKparse},
    {"make-x-to-p",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_makeKxKtoKp},
    {"lalr_process_reductions", WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lalr_process_reductions},
    {"gcref_off1",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gcref_off1},
    {"talp_noffcts",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_noffcts},
    {"pasf_dt",                 CC_pasf_dt,     TOO_MANY_1,    WRONG_NO_1},
    {"containerml",             TOO_FEW_2,      CC_containerml,WRONG_NO_2},
    {"sc_getrow",               TOO_FEW_2,      CC_sc_getrow,  WRONG_NO_2},
    {"xriterion_1",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xriterion_1},
    {"eqexpr",                  CC_eqexpr,      TOO_MANY_1,    WRONG_NO_1},
    {"one-entryp",              TOO_FEW_2,      CC_oneKentryp, WRONG_NO_2},
    {"comb",                    TOO_FEW_2,      CC_comb,       WRONG_NO_2},
    {NULL, (one_args *)"u32", (two_args *)"164219 4978930 8160493", 0}
};

// end of generated code
