
// $destdir/u38.c        Machine generated C code

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



// Code for rootextractf

static LispObject CC_rootextractf(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21845, v_21846, v_21847;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21531);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_21531;
// end of prologue
    v_21845 = stack[-3];
    if (!consp(v_21845)) goto v_21539;
    else goto v_21540;
v_21539:
    v_21845 = lisp_true;
    goto v_21538;
v_21540:
    v_21845 = stack[-3];
    v_21845 = qcar(v_21845);
    v_21845 = (consp(v_21845) ? nil : lisp_true);
    goto v_21538;
    v_21845 = nil;
v_21538:
    if (v_21845 == nil) goto v_21536;
    v_21845 = stack[-3];
    goto v_21534;
v_21536:
    v_21845 = stack[-3];
    v_21845 = qcar(v_21845);
    v_21845 = qcar(v_21845);
    v_21845 = qcar(v_21845);
    stack[-4] = v_21845;
    v_21845 = stack[-3];
    v_21845 = qcar(v_21845);
    v_21845 = qcar(v_21845);
    v_21845 = qcdr(v_21845);
    stack[0] = v_21845;
    v_21845 = stack[-3];
    v_21845 = qcdr(v_21845);
    v_21845 = CC_rootextractf(elt(env, 0), v_21845);
    env = stack[-5];
    stack[-2] = v_21845;
    v_21845 = stack[-3];
    v_21845 = qcar(v_21845);
    v_21845 = qcdr(v_21845);
    v_21845 = CC_rootextractf(elt(env, 0), v_21845);
    env = stack[-5];
    stack[-1] = v_21845;
    v_21845 = stack[-1];
    if (v_21845 == nil) goto v_21575;
    else goto v_21576;
v_21575:
    v_21845 = stack[-2];
    goto v_21557;
v_21576:
    v_21845 = stack[-4];
    if (!consp(v_21845)) goto v_21579;
    else goto v_21580;
v_21579:
    goto v_21589;
v_21583:
    v_21845 = stack[-3];
    v_21845 = qcar(v_21845);
    v_21847 = qcar(v_21845);
    goto v_21584;
v_21585:
    v_21846 = stack[-1];
    goto v_21586;
v_21587:
    v_21845 = stack[-2];
    goto v_21588;
v_21589:
    goto v_21583;
v_21584:
    goto v_21585;
v_21586:
    goto v_21587;
v_21588:
    return acons(v_21847, v_21846, v_21845);
v_21580:
    goto v_21605;
v_21601:
    v_21845 = stack[-4];
    v_21846 = qcar(v_21845);
    goto v_21602;
v_21603:
    v_21845 = elt(env, 1); // sqrt
    goto v_21604;
v_21605:
    goto v_21601;
v_21602:
    goto v_21603;
v_21604:
    if (v_21846 == v_21845) goto v_21599;
    else goto v_21600;
v_21599:
    v_21845 = lisp_true;
    goto v_21598;
v_21600:
    goto v_21620;
v_21616:
    v_21845 = stack[-4];
    v_21846 = qcar(v_21845);
    goto v_21617;
v_21618:
    v_21845 = elt(env, 2); // expt
    goto v_21619;
v_21620:
    goto v_21616;
v_21617:
    goto v_21618;
v_21619:
    if (v_21846 == v_21845) goto v_21614;
    else goto v_21615;
v_21614:
    goto v_21633;
v_21629:
    v_21845 = stack[-4];
    v_21845 = qcdr(v_21845);
    v_21845 = qcdr(v_21845);
    v_21846 = qcar(v_21845);
    goto v_21630;
v_21631:
    v_21845 = elt(env, 3); // quotient
    goto v_21632;
v_21633:
    goto v_21629;
v_21630:
    goto v_21631;
v_21632:
    if (!consp(v_21846)) goto v_21627;
    v_21846 = qcar(v_21846);
    if (v_21846 == v_21845) goto v_21626;
    else goto v_21627;
v_21626:
    goto v_21647;
v_21643:
    v_21845 = stack[-4];
    v_21845 = qcdr(v_21845);
    v_21845 = qcdr(v_21845);
    v_21845 = qcar(v_21845);
    v_21845 = qcdr(v_21845);
    v_21846 = qcar(v_21845);
    goto v_21644;
v_21645:
    v_21845 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21646;
v_21647:
    goto v_21643;
v_21644:
    goto v_21645;
v_21646:
    if (v_21846 == v_21845) goto v_21641;
    else goto v_21642;
v_21641:
    v_21845 = stack[-4];
    v_21845 = qcdr(v_21845);
    v_21845 = qcdr(v_21845);
    v_21845 = qcar(v_21845);
    v_21845 = qcdr(v_21845);
    v_21845 = qcdr(v_21845);
    v_21845 = qcar(v_21845);
    v_21845 = (is_number(v_21845) ? lisp_true : nil);
    goto v_21640;
v_21642:
    v_21845 = nil;
    goto v_21640;
    v_21845 = nil;
v_21640:
    goto v_21625;
v_21627:
    v_21845 = nil;
    goto v_21625;
    v_21845 = nil;
v_21625:
    goto v_21613;
v_21615:
    v_21845 = nil;
    goto v_21613;
    v_21845 = nil;
v_21613:
    goto v_21598;
    v_21845 = nil;
v_21598:
    if (v_21845 == nil) goto v_21596;
    goto v_21677;
v_21673:
    v_21847 = stack[0];
    goto v_21674;
v_21675:
    goto v_21687;
v_21683:
    v_21845 = stack[-4];
    v_21846 = qcar(v_21845);
    goto v_21684;
v_21685:
    v_21845 = elt(env, 1); // sqrt
    goto v_21686;
v_21687:
    goto v_21683;
v_21684:
    goto v_21685;
v_21686:
    if (v_21846 == v_21845) goto v_21681;
    else goto v_21682;
v_21681:
    v_21845 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_21680;
v_21682:
    v_21845 = stack[-4];
    v_21845 = qcdr(v_21845);
    v_21845 = qcdr(v_21845);
    v_21845 = qcar(v_21845);
    v_21845 = qcdr(v_21845);
    v_21845 = qcdr(v_21845);
    v_21845 = qcar(v_21845);
    goto v_21680;
    v_21845 = nil;
v_21680:
    goto v_21676;
v_21677:
    goto v_21673;
v_21674:
    goto v_21675;
v_21676:
    v_21845 = Ldivide(nil, v_21847, v_21845);
    env = stack[-5];
    stack[0] = v_21845;
    goto v_21709;
v_21705:
    v_21845 = stack[0];
    v_21846 = qcar(v_21845);
    goto v_21706;
v_21707:
    v_21845 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21708;
v_21709:
    goto v_21705;
v_21706:
    goto v_21707;
v_21708:
    if (v_21846 == v_21845) goto v_21703;
    else goto v_21704;
v_21703:
    v_21845 = stack[-1];
    if (v_21845 == nil) goto v_21715;
    else goto v_21716;
v_21715:
    v_21845 = stack[-2];
    goto v_21714;
v_21716:
    goto v_21728;
v_21722:
    v_21845 = stack[-3];
    v_21845 = qcar(v_21845);
    v_21847 = qcar(v_21845);
    goto v_21723;
v_21724:
    v_21846 = stack[-1];
    goto v_21725;
v_21726:
    v_21845 = stack[-2];
    goto v_21727;
v_21728:
    goto v_21722;
v_21723:
    goto v_21724;
v_21725:
    goto v_21726;
v_21727:
    return acons(v_21847, v_21846, v_21845);
    v_21845 = nil;
v_21714:
    goto v_21557;
v_21704:
    v_21845 = stack[-4];
    v_21845 = qcdr(v_21845);
    v_21845 = qcar(v_21845);
    if (is_number(v_21845)) goto v_21734;
    else goto v_21735;
v_21734:
    goto v_21744;
v_21740:
    goto v_21750;
v_21746:
    v_21845 = stack[-4];
    v_21845 = qcdr(v_21845);
    v_21846 = qcar(v_21845);
    goto v_21747;
v_21748:
    v_21845 = stack[0];
    v_21845 = qcar(v_21845);
    goto v_21749;
v_21750:
    goto v_21746;
v_21747:
    goto v_21748;
v_21749:
    v_21846 = Lexpt(nil, v_21846, v_21845);
    env = stack[-5];
    goto v_21741;
v_21742:
    v_21845 = stack[-1];
    goto v_21743;
v_21744:
    goto v_21740;
v_21741:
    goto v_21742;
v_21743:
    fn = elt(env, 4); // multd
    v_21845 = (*qfn2(fn))(fn, v_21846, v_21845);
    env = stack[-5];
    stack[-1] = v_21845;
    v_21845 = stack[0];
    v_21845 = qcdr(v_21845);
    stack[0] = v_21845;
    goto v_21702;
v_21735:
    goto v_21767;
v_21763:
    v_21845 = stack[-4];
    v_21845 = qcdr(v_21845);
    v_21846 = qcar(v_21845);
    goto v_21764;
v_21765:
    v_21845 = stack[0];
    v_21845 = qcar(v_21845);
    goto v_21766;
v_21767:
    goto v_21763;
v_21764:
    goto v_21765;
v_21766:
    v_21845 = list2(v_21846, v_21845);
    env = stack[-5];
    fn = elt(env, 5); // simpexpt
    v_21845 = (*qfn1(fn))(fn, v_21845);
    env = stack[-5];
    v_21847 = v_21845;
    goto v_21781;
v_21777:
    v_21845 = v_21847;
    v_21846 = qcdr(v_21845);
    goto v_21778;
v_21779:
    v_21845 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21780;
v_21781:
    goto v_21777;
v_21778:
    goto v_21779;
v_21780:
    if (v_21846 == v_21845) goto v_21775;
    else goto v_21776;
v_21775:
    goto v_21790;
v_21786:
    v_21845 = v_21847;
    v_21846 = qcar(v_21845);
    goto v_21787;
v_21788:
    v_21845 = stack[-1];
    goto v_21789;
v_21790:
    goto v_21786;
v_21787:
    goto v_21788;
v_21789:
    fn = elt(env, 6); // multf
    v_21845 = (*qfn2(fn))(fn, v_21846, v_21845);
    env = stack[-5];
    stack[-1] = v_21845;
    v_21845 = stack[0];
    v_21845 = qcdr(v_21845);
    stack[0] = v_21845;
    goto v_21774;
v_21776:
    v_21845 = stack[-3];
    v_21845 = qcar(v_21845);
    v_21845 = qcar(v_21845);
    v_21845 = qcdr(v_21845);
    stack[0] = v_21845;
    goto v_21774;
v_21774:
    goto v_21702;
v_21702:
    goto v_21574;
v_21596:
v_21574:
    goto v_21810;
v_21806:
    v_21846 = stack[0];
    goto v_21807;
v_21808:
    v_21845 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21809;
v_21810:
    goto v_21806;
v_21807:
    goto v_21808;
v_21809:
    if (v_21846 == v_21845) goto v_21804;
    else goto v_21805;
v_21804:
    goto v_21818;
v_21814:
    v_21846 = stack[-1];
    goto v_21815;
v_21816:
    v_21845 = stack[-2];
    goto v_21817;
v_21818:
    goto v_21814;
v_21815:
    goto v_21816;
v_21817:
    {
        fn = elt(env, 7); // addf
        return (*qfn2(fn))(fn, v_21846, v_21845);
    }
v_21805:
    v_21845 = stack[-1];
    if (v_21845 == nil) goto v_21821;
    else goto v_21822;
v_21821:
    v_21845 = stack[-2];
    goto v_21803;
v_21822:
    goto v_21834;
v_21828:
    goto v_21840;
v_21836:
    v_21846 = stack[-4];
    goto v_21837;
v_21838:
    v_21845 = stack[0];
    goto v_21839;
v_21840:
    goto v_21836;
v_21837:
    goto v_21838;
v_21839:
    fn = elt(env, 8); // to
    v_21847 = (*qfn2(fn))(fn, v_21846, v_21845);
    goto v_21829;
v_21830:
    v_21846 = stack[-1];
    goto v_21831;
v_21832:
    v_21845 = stack[-2];
    goto v_21833;
v_21834:
    goto v_21828;
v_21829:
    goto v_21830;
v_21831:
    goto v_21832;
v_21833:
    return acons(v_21847, v_21846, v_21845);
    v_21845 = nil;
v_21803:
v_21557:
    goto v_21534;
    v_21845 = nil;
v_21534:
    return onevalue(v_21845);
}



// Code for ratlessp

static LispObject CC_ratlessp(LispObject env,
                         LispObject v_21531, LispObject v_21532)
{
    env = qenv(env);
    LispObject v_21550, v_21551;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21531,v_21532);
    }
// copy arguments values to proper place
    v_21550 = v_21532;
    v_21551 = v_21531;
// end of prologue
    goto v_21539;
v_21535:
    goto v_21545;
v_21541:
    goto v_21542;
v_21543:
    goto v_21544;
v_21545:
    goto v_21541;
v_21542:
    goto v_21543;
v_21544:
    fn = elt(env, 1); // ratdif
    v_21550 = (*qfn2(fn))(fn, v_21551, v_21550);
    v_21551 = qcar(v_21550);
    goto v_21536;
v_21537:
    v_21550 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21538;
v_21539:
    goto v_21535;
v_21536:
    goto v_21537;
v_21538:
        return Llessp(nil, v_21551, v_21550);
}



// Code for make!-image

static LispObject CC_makeKimage(LispObject env,
                         LispObject v_21531, LispObject v_21532)
{
    env = qenv(env);
    LispObject v_21616, v_21617, v_21618;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21531,v_21532);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21532;
    stack[-1] = v_21531;
// end of prologue
    v_21616 = stack[-1];
    if (!consp(v_21616)) goto v_21540;
    else goto v_21541;
v_21540:
    v_21616 = lisp_true;
    goto v_21539;
v_21541:
    v_21616 = stack[-1];
    v_21616 = qcar(v_21616);
    v_21616 = (consp(v_21616) ? nil : lisp_true);
    goto v_21539;
    v_21616 = nil;
v_21539:
    if (v_21616 == nil) goto v_21537;
    v_21616 = stack[-1];
    goto v_21535;
v_21537:
    goto v_21556;
v_21552:
    v_21616 = stack[-1];
    v_21616 = qcar(v_21616);
    v_21616 = qcar(v_21616);
    v_21617 = qcar(v_21616);
    goto v_21553;
v_21554:
    v_21616 = qvalue(elt(env, 1)); // m!-image!-variable
    goto v_21555;
v_21556:
    goto v_21552;
v_21553:
    goto v_21554;
v_21555:
    if (equal(v_21617, v_21616)) goto v_21550;
    else goto v_21551;
v_21550:
    goto v_21568;
v_21564:
    v_21616 = stack[-1];
    v_21616 = qcar(v_21616);
    v_21617 = qcdr(v_21616);
    goto v_21565;
v_21566:
    v_21616 = stack[0];
    goto v_21567;
v_21568:
    goto v_21564;
v_21565:
    goto v_21566;
v_21567:
    fn = elt(env, 2); // evaluate!-in!-order
    v_21616 = (*qfn2(fn))(fn, v_21617, v_21616);
    env = stack[-3];
    fn = elt(env, 3); // !*n2f
    stack[-2] = (*qfn1(fn))(fn, v_21616);
    env = stack[-3];
    goto v_21578;
v_21574:
    v_21616 = stack[-1];
    v_21617 = qcdr(v_21616);
    goto v_21575;
v_21576:
    v_21616 = stack[0];
    goto v_21577;
v_21578:
    goto v_21574;
v_21575:
    goto v_21576;
v_21577:
    v_21616 = CC_makeKimage(elt(env, 0), v_21617, v_21616);
    v_21617 = stack[-2];
    v_21618 = v_21617;
    if (v_21618 == nil) goto v_21586;
    else goto v_21587;
v_21586:
    goto v_21585;
v_21587:
    goto v_21599;
v_21593:
    v_21618 = stack[-1];
    v_21618 = qcar(v_21618);
    v_21618 = qcar(v_21618);
    goto v_21594;
v_21595:
    goto v_21596;
v_21597:
    goto v_21598;
v_21599:
    goto v_21593;
v_21594:
    goto v_21595;
v_21596:
    goto v_21597;
v_21598:
    return acons(v_21618, v_21617, v_21616);
    v_21616 = nil;
v_21585:
    goto v_21535;
v_21551:
    goto v_21613;
v_21609:
    v_21617 = stack[-1];
    goto v_21610;
v_21611:
    v_21616 = stack[0];
    goto v_21612;
v_21613:
    goto v_21609;
v_21610:
    goto v_21611;
v_21612:
    fn = elt(env, 2); // evaluate!-in!-order
    v_21616 = (*qfn2(fn))(fn, v_21617, v_21616);
    env = stack[-3];
    {
        fn = elt(env, 3); // !*n2f
        return (*qfn1(fn))(fn, v_21616);
    }
    v_21616 = nil;
v_21535:
    return onevalue(v_21616);
}



// Code for settcollectnonmultiprolongations

static LispObject CC_settcollectnonmultiprolongations(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21669, v_21670, v_21671;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21531);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_21531;
// end of prologue
    v_21669 = qvalue(elt(env, 1)); // fluidbibasissett
    v_21669 = qcar(v_21669);
    if (v_21669 == nil) goto v_21536;
    v_21669 = qvalue(elt(env, 1)); // fluidbibasissett
    v_21669 = qcar(v_21669);
    stack[-4] = v_21669;
    goto v_21553;
v_21549:
    v_21670 = stack[-4];
    goto v_21550;
v_21551:
    v_21669 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21552;
v_21553:
    goto v_21549;
v_21550:
    goto v_21551;
v_21552:
    v_21669 = *(LispObject *)((char *)v_21670 + (CELL-TAG_VECTOR) + (((intptr_t)v_21669-TAG_FIXNUM)/(16/CELL)));
    v_21669 = qcar(v_21669);
    fn = elt(env, 3); // monomgetfirstmultivar
    v_21669 = (*qfn1(fn))(fn, v_21669);
    env = stack[-5];
    v_21669 = (LispObject)((intptr_t)(v_21669) - 0x10);
    stack[-1] = v_21669;
    v_21669 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_21669;
v_21562:
    goto v_21574;
v_21570:
    v_21670 = stack[-1];
    goto v_21571;
v_21572:
    v_21669 = stack[0];
    goto v_21573;
v_21574:
    goto v_21570;
v_21571:
    goto v_21572;
v_21573:
    v_21669 = difference2(v_21670, v_21669);
    env = stack[-5];
    v_21669 = Lminusp(nil, v_21669);
    env = stack[-5];
    if (v_21669 == nil) goto v_21567;
    goto v_21561;
v_21567:
    goto v_21587;
v_21583:
    v_21670 = stack[-4];
    goto v_21584;
v_21585:
    v_21669 = stack[0];
    goto v_21586;
v_21587:
    goto v_21583;
v_21584:
    goto v_21585;
v_21586:
    fn = elt(env, 4); // tripleisprolongedby
    v_21669 = (*qfn2(fn))(fn, v_21670, v_21669);
    env = stack[-5];
    if (v_21669 == nil) goto v_21580;
    else goto v_21581;
v_21580:
    goto v_21595;
v_21591:
    goto v_21600;
v_21596:
    v_21670 = stack[-4];
    goto v_21597;
v_21598:
    v_21669 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21599;
v_21600:
    goto v_21596;
v_21597:
    goto v_21598;
v_21599:
    v_21671 = *(LispObject *)((char *)v_21670 + (CELL-TAG_VECTOR) + (((intptr_t)v_21669-TAG_FIXNUM)/(16/CELL)));
    goto v_21592;
v_21593:
    goto v_21608;
v_21604:
    v_21670 = qvalue(elt(env, 2)); // fluidbibasissinglevariablemonomialss
    goto v_21605;
v_21606:
    v_21669 = stack[0];
    goto v_21607;
v_21608:
    goto v_21604;
v_21605:
    goto v_21606;
v_21607:
    v_21669 = *(LispObject *)((char *)v_21670 + (CELL-TAG_VECTOR) + (((intptr_t)v_21669-TAG_FIXNUM)/(16/CELL)));
    goto v_21594;
v_21595:
    goto v_21591;
v_21592:
    goto v_21593;
v_21594:
    fn = elt(env, 5); // polynommultiplybymonom
    v_21669 = (*qfn2(fn))(fn, v_21671, v_21669);
    env = stack[-5];
    stack[-2] = v_21669;
    goto v_21617;
v_21613:
    v_21670 = stack[-4];
    goto v_21614;
v_21615:
    v_21669 = stack[0];
    goto v_21616;
v_21617:
    goto v_21613;
v_21614:
    goto v_21615;
v_21616:
    fn = elt(env, 6); // triplesetprolongedby
    v_21669 = (*qfn2(fn))(fn, v_21670, v_21669);
    env = stack[-5];
    v_21669 = stack[-2];
    v_21669 = qcar(v_21669);
    if (v_21669 == nil) goto v_21623;
    goto v_21631;
v_21627:
    v_21671 = stack[-2];
    goto v_21628;
v_21629:
    goto v_21637;
v_21633:
    v_21670 = stack[-4];
    goto v_21634;
v_21635:
    v_21669 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_21636;
v_21637:
    goto v_21633;
v_21634:
    goto v_21635;
v_21636:
    v_21669 = *(LispObject *)((char *)v_21670 + (CELL-TAG_VECTOR) + (((intptr_t)v_21669-TAG_FIXNUM)/(16/CELL)));
    goto v_21630;
v_21631:
    goto v_21627;
v_21628:
    goto v_21629;
v_21630:
    fn = elt(env, 7); // createtriplewithancestor
    v_21669 = (*qfn2(fn))(fn, v_21671, v_21669);
    env = stack[-5];
    stack[-2] = v_21669;
    goto v_21646;
v_21642:
    v_21671 = stack[-2];
    goto v_21643;
v_21644:
    goto v_21652;
v_21648:
    v_21670 = stack[-4];
    goto v_21649;
v_21650:
    v_21669 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_21651;
v_21652:
    goto v_21648;
v_21649:
    goto v_21650;
v_21651:
    v_21669 = *(LispObject *)((char *)v_21670 + (CELL-TAG_VECTOR) + (((intptr_t)v_21669-TAG_FIXNUM)/(16/CELL)));
    goto v_21645;
v_21646:
    goto v_21642;
v_21643:
    goto v_21644;
v_21645:
    fn = elt(env, 8); // triplesetprolongset
    v_21669 = (*qfn2(fn))(fn, v_21671, v_21669);
    env = stack[-5];
    goto v_21661;
v_21657:
    v_21670 = stack[-3];
    goto v_21658;
v_21659:
    v_21669 = stack[-2];
    goto v_21660;
v_21661:
    goto v_21657;
v_21658:
    goto v_21659;
v_21660:
    fn = elt(env, 9); // sortedtriplelistinsert
    v_21669 = (*qfn2(fn))(fn, v_21670, v_21669);
    env = stack[-5];
    goto v_21621;
v_21623:
v_21621:
    goto v_21579;
v_21581:
v_21579:
    v_21669 = stack[0];
    v_21669 = add1(v_21669);
    env = stack[-5];
    stack[0] = v_21669;
    goto v_21562;
v_21561:
    v_21669 = nil;
    goto v_21534;
v_21536:
    v_21669 = nil;
v_21534:
    return onevalue(v_21669);
}



// Code for valuecoefft

static LispObject CC_valuecoefft(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21578, v_21579, v_21580, v_21581, v_21582;
    LispObject fn;
    LispObject v_21533, v_21532, v_21531;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "valuecoefft");
    va_start(aa, nargs);
    v_21531 = va_arg(aa, LispObject);
    v_21532 = va_arg(aa, LispObject);
    v_21533 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21580 = v_21533;
    v_21581 = v_21532;
    v_21582 = v_21531;
// end of prologue
v_21537:
    v_21578 = v_21580;
    if (v_21578 == nil) goto v_21540;
    else goto v_21541;
v_21540:
    v_21578 = elt(env, 1); // "Valuecoefft - no value"
    {
        fn = elt(env, 2); // interr
        return (*qfn1(fn))(fn, v_21578);
    }
v_21541:
    goto v_21551;
v_21547:
    v_21579 = v_21582;
    goto v_21548;
v_21549:
    v_21578 = v_21580;
    v_21578 = qcar(v_21578);
    goto v_21550;
v_21551:
    goto v_21547;
v_21548:
    goto v_21549;
v_21550:
    if (v_21579 == v_21578) goto v_21545;
    else goto v_21546;
v_21545:
    goto v_21563;
v_21559:
    v_21578 = v_21581;
    v_21579 = qcar(v_21578);
    goto v_21560;
v_21561:
    v_21578 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21562;
v_21563:
    goto v_21559;
v_21560:
    goto v_21561;
v_21562:
    if (v_21579 == v_21578) goto v_21557;
    else goto v_21558;
v_21557:
    v_21578 = nil;
    goto v_21536;
v_21558:
    v_21578 = v_21581;
    v_21578 = qcar(v_21578);
    goto v_21536;
    goto v_21539;
v_21546:
    v_21578 = v_21581;
    v_21578 = qcdr(v_21578);
    v_21581 = v_21578;
    v_21578 = v_21580;
    v_21578 = qcdr(v_21578);
    v_21580 = v_21578;
    goto v_21537;
v_21539:
    v_21578 = nil;
v_21536:
    return onevalue(v_21578);
}



// Code for internal!-factorf

static LispObject CC_internalKfactorf(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21817, v_21818;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21531);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_21531;
// end of prologue
    v_21817 = qvalue(elt(env, 1)); // current!-modulus
// Binding current!-modulus
// FLUIDBIND: reloadenv=10 litvec-offset=1 saveloc=9
{   bind_fluid_stack bind_fluid_var(-10, 1, -9);
    qvalue(elt(env, 1)) = v_21817; // current!-modulus
// Binding m!-image!-variable
// FLUIDBIND: reloadenv=10 litvec-offset=2 saveloc=7
{   bind_fluid_stack bind_fluid_var(-10, 2, -7);
    qvalue(elt(env, 2)) = nil; // m!-image!-variable
    stack[-6] = nil;
    v_21817 = stack[-8];
    if (!consp(v_21817)) goto v_21550;
    else goto v_21551;
v_21550:
    v_21817 = lisp_true;
    goto v_21549;
v_21551:
    v_21817 = stack[-8];
    v_21817 = qcar(v_21817);
    v_21817 = (consp(v_21817) ? nil : lisp_true);
    goto v_21549;
    v_21817 = nil;
v_21549:
    if (v_21817 == nil) goto v_21547;
    v_21817 = stack[-8];
    v_21817 = ncons(v_21817);
    goto v_21543;
v_21547:
    goto v_21566;
v_21562:
    v_21818 = stack[-8];
    goto v_21563;
v_21564:
    v_21817 = nil;
    goto v_21565;
v_21566:
    goto v_21562;
v_21563:
    goto v_21564;
v_21565:
    fn = elt(env, 4); // kernord
    v_21817 = (*qfn2(fn))(fn, v_21818, v_21817);
    env = stack[-10];
    v_21818 = v_21817;
    v_21817 = qvalue(elt(env, 3)); // !*kernreverse
    if (v_21817 == nil) goto v_21572;
    v_21817 = v_21818;
    v_21817 = Lreverse(nil, v_21817);
    env = stack[-10];
    v_21818 = v_21817;
    goto v_21570;
v_21572:
v_21570:
    v_21817 = v_21818;
    fn = elt(env, 5); // setkorder
    v_21817 = (*qfn1(fn))(fn, v_21817);
    env = stack[-10];
    stack[-3] = v_21817;
    v_21817 = stack[-8];
    fn = elt(env, 6); // reorder
    v_21817 = (*qfn1(fn))(fn, v_21817);
    env = stack[-10];
    stack[-8] = v_21817;
    v_21817 = stack[-8];
    fn = elt(env, 7); // minusf
    v_21817 = (*qfn1(fn))(fn, v_21817);
    env = stack[-10];
    if (v_21817 == nil) goto v_21583;
    v_21817 = stack[-6];
    v_21817 = (v_21817 == nil ? lisp_true : nil);
    stack[-6] = v_21817;
    v_21817 = stack[-8];
    fn = elt(env, 8); // negf
    v_21817 = (*qfn1(fn))(fn, v_21817);
    env = stack[-10];
    stack[-8] = v_21817;
    goto v_21581;
v_21583:
v_21581:
    v_21817 = stack[-8];
    fn = elt(env, 9); // comfac
    v_21817 = (*qfn1(fn))(fn, v_21817);
    env = stack[-10];
    stack[-2] = v_21817;
    goto v_21597;
v_21593:
    stack[0] = stack[-8];
    goto v_21594;
v_21595:
    v_21817 = stack[-2];
    fn = elt(env, 10); // comfac!-to!-poly
    v_21817 = (*qfn1(fn))(fn, v_21817);
    env = stack[-10];
    goto v_21596;
v_21597:
    goto v_21593;
v_21594:
    goto v_21595;
v_21596:
    fn = elt(env, 11); // quotf1
    v_21817 = (*qfn2(fn))(fn, stack[0], v_21817);
    env = stack[-10];
    stack[-8] = v_21817;
    v_21817 = stack[-8];
    if (!consp(v_21817)) goto v_21607;
    else goto v_21608;
v_21607:
    v_21817 = lisp_true;
    goto v_21606;
v_21608:
    v_21817 = stack[-8];
    v_21817 = qcar(v_21817);
    v_21817 = (consp(v_21817) ? nil : lisp_true);
    goto v_21606;
    v_21817 = nil;
v_21606:
    if (v_21817 == nil) goto v_21604;
    v_21817 = stack[-8];
    stack[-5] = v_21817;
    v_21817 = nil;
    stack[-8] = v_21817;
    goto v_21602;
v_21604:
    v_21817 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_21817;
    v_21817 = stack[-8];
    v_21817 = qcar(v_21817);
    v_21817 = qcar(v_21817);
    v_21817 = qcar(v_21817);
    qvalue(elt(env, 2)) = v_21817; // m!-image!-variable
    goto v_21630;
v_21626:
    v_21817 = stack[-8];
    fn = elt(env, 12); // factorize!-primitive!-polynomial
    v_21818 = (*qfn1(fn))(fn, v_21817);
    env = stack[-10];
    goto v_21627;
v_21628:
    v_21817 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21629;
v_21630:
    goto v_21626;
v_21627:
    goto v_21628;
v_21629:
    fn = elt(env, 13); // distribute!.multiplicity
    v_21817 = (*qfn2(fn))(fn, v_21818, v_21817);
    env = stack[-10];
    stack[-8] = v_21817;
    goto v_21602;
v_21602:
    v_21817 = stack[-2];
    v_21817 = qcar(v_21817);
    stack[-1] = v_21817;
    v_21817 = stack[-2];
    v_21817 = qcdr(v_21817);
    fn = elt(env, 14); // fctrf1
    v_21817 = (*qfn1(fn))(fn, v_21817);
    env = stack[-10];
    stack[-2] = v_21817;
    v_21817 = stack[-1];
    if (v_21817 == nil) goto v_21642;
    goto v_21651;
v_21645:
    v_21817 = stack[-2];
    stack[0] = qcar(v_21817);
    goto v_21646;
v_21647:
    goto v_21659;
v_21655:
    goto v_21666;
v_21662:
    goto v_21672;
v_21668:
    v_21817 = stack[-1];
    v_21818 = qcar(v_21817);
    goto v_21669;
v_21670:
    v_21817 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21671;
v_21672:
    goto v_21668;
v_21669:
    goto v_21670;
v_21671:
    fn = elt(env, 15); // to
    v_21818 = (*qfn2(fn))(fn, v_21818, v_21817);
    env = stack[-10];
    goto v_21663;
v_21664:
    v_21817 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21665;
v_21666:
    goto v_21662;
v_21663:
    goto v_21664;
v_21665:
    v_21817 = cons(v_21818, v_21817);
    env = stack[-10];
    v_21818 = ncons(v_21817);
    env = stack[-10];
    goto v_21656;
v_21657:
    v_21817 = stack[-1];
    v_21817 = qcdr(v_21817);
    goto v_21658;
v_21659:
    goto v_21655;
v_21656:
    goto v_21657;
v_21658:
    v_21818 = cons(v_21818, v_21817);
    env = stack[-10];
    goto v_21648;
v_21649:
    v_21817 = stack[-2];
    v_21817 = qcdr(v_21817);
    goto v_21650;
v_21651:
    goto v_21645;
v_21646:
    goto v_21647;
v_21648:
    goto v_21649;
v_21650:
    v_21817 = list2star(stack[0], v_21818, v_21817);
    env = stack[-10];
    stack[-2] = v_21817;
    goto v_21640;
v_21642:
v_21640:
    v_21817 = stack[-6];
    if (v_21817 == nil) goto v_21684;
    v_21817 = stack[-5];
    fn = elt(env, 8); // negf
    v_21817 = (*qfn1(fn))(fn, v_21817);
    env = stack[-10];
    stack[-5] = v_21817;
    goto v_21682;
v_21684:
v_21682:
    goto v_21693;
v_21689:
    stack[0] = stack[-2];
    goto v_21690;
v_21691:
    goto v_21700;
v_21696:
    v_21818 = stack[-5];
    goto v_21697;
v_21698:
    v_21817 = stack[-8];
    goto v_21699;
v_21700:
    goto v_21696;
v_21697:
    goto v_21698;
v_21699:
    v_21817 = cons(v_21818, v_21817);
    env = stack[-10];
    goto v_21692;
v_21693:
    goto v_21689;
v_21690:
    goto v_21691;
v_21692:
    fn = elt(env, 16); // fac!-merge
    v_21817 = (*qfn2(fn))(fn, stack[0], v_21817);
    env = stack[-10];
    stack[-8] = v_21817;
    v_21817 = stack[-3];
    fn = elt(env, 5); // setkorder
    v_21817 = (*qfn1(fn))(fn, v_21817);
    env = stack[-10];
    v_21817 = stack[-8];
    v_21817 = qcdr(v_21817);
    stack[-4] = v_21817;
    v_21817 = stack[-4];
    if (v_21817 == nil) goto v_21715;
    else goto v_21716;
v_21715:
    v_21817 = nil;
    goto v_21709;
v_21716:
    v_21817 = stack[-4];
    v_21817 = qcar(v_21817);
    stack[0] = v_21817;
    goto v_21728;
v_21724:
    v_21817 = stack[0];
    v_21817 = qcar(v_21817);
    fn = elt(env, 6); // reorder
    v_21817 = (*qfn1(fn))(fn, v_21817);
    env = stack[-10];
    stack[-5] = v_21817;
    fn = elt(env, 7); // minusf
    v_21817 = (*qfn1(fn))(fn, v_21817);
    env = stack[-10];
    if (v_21817 == nil) goto v_21732;
    v_21817 = stack[-6];
    v_21817 = (v_21817 == nil ? lisp_true : nil);
    stack[-6] = v_21817;
    v_21817 = stack[-5];
    fn = elt(env, 8); // negf
    v_21817 = (*qfn1(fn))(fn, v_21817);
    env = stack[-10];
    v_21818 = v_21817;
    goto v_21730;
v_21732:
    v_21817 = stack[-5];
    v_21818 = v_21817;
    goto v_21730;
    v_21818 = nil;
v_21730:
    goto v_21725;
v_21726:
    v_21817 = stack[0];
    v_21817 = qcdr(v_21817);
    goto v_21727;
v_21728:
    goto v_21724;
v_21725:
    goto v_21726;
v_21727:
    v_21817 = cons(v_21818, v_21817);
    env = stack[-10];
    v_21817 = ncons(v_21817);
    env = stack[-10];
    stack[-2] = v_21817;
    stack[-3] = v_21817;
v_21710:
    v_21817 = stack[-4];
    v_21817 = qcdr(v_21817);
    stack[-4] = v_21817;
    v_21817 = stack[-4];
    if (v_21817 == nil) goto v_21750;
    else goto v_21751;
v_21750:
    v_21817 = stack[-3];
    goto v_21709;
v_21751:
    goto v_21759;
v_21755:
    stack[-1] = stack[-2];
    goto v_21756;
v_21757:
    v_21817 = stack[-4];
    v_21817 = qcar(v_21817);
    stack[0] = v_21817;
    goto v_21770;
v_21766:
    v_21817 = stack[0];
    v_21817 = qcar(v_21817);
    fn = elt(env, 6); // reorder
    v_21817 = (*qfn1(fn))(fn, v_21817);
    env = stack[-10];
    stack[-5] = v_21817;
    fn = elt(env, 7); // minusf
    v_21817 = (*qfn1(fn))(fn, v_21817);
    env = stack[-10];
    if (v_21817 == nil) goto v_21774;
    v_21817 = stack[-6];
    v_21817 = (v_21817 == nil ? lisp_true : nil);
    stack[-6] = v_21817;
    v_21817 = stack[-5];
    fn = elt(env, 8); // negf
    v_21817 = (*qfn1(fn))(fn, v_21817);
    env = stack[-10];
    v_21818 = v_21817;
    goto v_21772;
v_21774:
    v_21817 = stack[-5];
    v_21818 = v_21817;
    goto v_21772;
    v_21818 = nil;
v_21772:
    goto v_21767;
v_21768:
    v_21817 = stack[0];
    v_21817 = qcdr(v_21817);
    goto v_21769;
v_21770:
    goto v_21766;
v_21767:
    goto v_21768;
v_21769:
    v_21817 = cons(v_21818, v_21817);
    env = stack[-10];
    v_21817 = ncons(v_21817);
    env = stack[-10];
    goto v_21758;
v_21759:
    goto v_21755;
v_21756:
    goto v_21757;
v_21758:
    v_21817 = Lrplacd(nil, stack[-1], v_21817);
    env = stack[-10];
    v_21817 = stack[-2];
    v_21817 = qcdr(v_21817);
    stack[-2] = v_21817;
    goto v_21710;
v_21709:
    stack[-2] = v_21817;
    goto v_21795;
v_21791:
    goto v_21804;
v_21800:
    stack[0] = stack[-6];
    goto v_21801;
v_21802:
    v_21817 = stack[-8];
    v_21817 = qcar(v_21817);
    fn = elt(env, 7); // minusf
    v_21817 = (*qfn1(fn))(fn, v_21817);
    env = stack[-10];
    goto v_21803;
v_21804:
    goto v_21800;
v_21801:
    goto v_21802;
v_21803:
    if (equal(stack[0], v_21817)) goto v_21799;
    v_21817 = stack[-8];
    v_21817 = qcar(v_21817);
    fn = elt(env, 8); // negf
    v_21817 = (*qfn1(fn))(fn, v_21817);
    env = stack[-10];
    v_21818 = v_21817;
    goto v_21797;
v_21799:
    v_21817 = stack[-8];
    v_21817 = qcar(v_21817);
    v_21818 = v_21817;
    goto v_21797;
    v_21818 = nil;
v_21797:
    goto v_21792;
v_21793:
    v_21817 = stack[-2];
    goto v_21794;
v_21795:
    goto v_21791;
v_21792:
    goto v_21793;
v_21794:
    v_21817 = cons(v_21818, v_21817);
v_21543:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_21817);
}



// Code for ioto_smaprinbuf

static LispObject CC_ioto_smaprinbuf(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21551, v_21552;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21531);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21531;
// end of prologue
    goto v_21538;
v_21534:
    v_21552 = elt(env, 1); // !!
    goto v_21535;
v_21536:
    v_21551 = qvalue(elt(env, 2)); // rlsmaprinbuf!*
    goto v_21537;
v_21538:
    goto v_21534;
v_21535:
    goto v_21536;
v_21537:
    v_21551 = cons(v_21552, v_21551);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_21551; // rlsmaprinbuf!*
    goto v_21547;
v_21543:
    v_21552 = stack[0];
    goto v_21544;
v_21545:
    v_21551 = qvalue(elt(env, 2)); // rlsmaprinbuf!*
    goto v_21546;
v_21547:
    goto v_21543;
v_21544:
    goto v_21545;
v_21546:
    v_21551 = cons(v_21552, v_21551);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_21551; // rlsmaprinbuf!*
    v_21551 = stack[0];
    return onevalue(v_21551);
}



// Code for containerom

static LispObject CC_containerom(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21659, v_21660;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21531);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_21531;
// end of prologue
    v_21659 = stack[-2];
    v_21659 = qcdr(v_21659);
    v_21659 = qcar(v_21659);
    stack[-1] = v_21659;
    v_21659 = stack[-2];
    v_21659 = qcar(v_21659);
    stack[0] = v_21659;
    v_21659 = elt(env, 1); // "<OMA>"
    fn = elt(env, 13); // printout
    v_21659 = (*qfn1(fn))(fn, v_21659);
    env = stack[-4];
    v_21659 = lisp_true;
    fn = elt(env, 14); // indent!*
    v_21659 = (*qfn1(fn))(fn, v_21659);
    env = stack[-4];
    goto v_21555;
v_21551:
    v_21660 = stack[0];
    goto v_21552;
v_21553:
    v_21659 = elt(env, 2); // vectorml
    goto v_21554;
v_21555:
    goto v_21551;
v_21552:
    goto v_21553;
v_21554:
    if (v_21660 == v_21659) goto v_21549;
    else goto v_21550;
v_21549:
    v_21659 = elt(env, 3); // vector
    stack[0] = v_21659;
    goto v_21548;
v_21550:
v_21548:
    goto v_21563;
v_21559:
    v_21660 = stack[0];
    goto v_21560;
v_21561:
    v_21659 = qvalue(elt(env, 4)); // valid_om!*
    goto v_21562;
v_21563:
    goto v_21559;
v_21560:
    goto v_21561;
v_21562:
    v_21659 = Lassoc(nil, v_21660, v_21659);
    v_21659 = qcdr(v_21659);
    v_21659 = qcar(v_21659);
    stack[-3] = v_21659;
    goto v_21581;
v_21577:
    v_21659 = stack[-2];
    v_21660 = qcar(v_21659);
    goto v_21578;
v_21579:
    v_21659 = elt(env, 5); // set
    goto v_21580;
v_21581:
    goto v_21577;
v_21578:
    goto v_21579;
v_21580:
    if (v_21660 == v_21659) goto v_21575;
    else goto v_21576;
v_21575:
    v_21659 = stack[-1];
    v_21659 = Lconsp(nil, v_21659);
    env = stack[-4];
    goto v_21574;
v_21576:
    v_21659 = nil;
    goto v_21574;
    v_21659 = nil;
v_21574:
    if (v_21659 == nil) goto v_21572;
    goto v_21598;
v_21594:
    v_21659 = stack[-1];
    v_21659 = qcar(v_21659);
    v_21659 = qcdr(v_21659);
    v_21659 = qcar(v_21659);
    v_21660 = Lintern(nil, v_21659);
    env = stack[-4];
    goto v_21595;
v_21596:
    v_21659 = elt(env, 6); // multiset
    goto v_21597;
v_21598:
    goto v_21594;
v_21595:
    goto v_21596;
v_21597:
    if (v_21660 == v_21659) goto v_21592;
    else goto v_21593;
v_21592:
    v_21659 = elt(env, 7); // multiset1
    stack[-3] = v_21659;
    goto v_21591;
v_21593:
v_21591:
    goto v_21570;
v_21572:
v_21570:
    goto v_21615;
v_21611:
    v_21659 = stack[-2];
    v_21660 = qcar(v_21659);
    goto v_21612;
v_21613:
    v_21659 = elt(env, 2); // vectorml
    goto v_21614;
v_21615:
    goto v_21611;
v_21612:
    goto v_21613;
v_21614:
    if (v_21660 == v_21659) goto v_21609;
    else goto v_21610;
v_21609:
    v_21659 = elt(env, 8); // "vector"
    stack[0] = v_21659;
    goto v_21608;
v_21610:
v_21608:
    goto v_21628;
v_21624:
    v_21659 = stack[-2];
    v_21660 = qcar(v_21659);
    goto v_21625;
v_21626:
    v_21659 = elt(env, 2); // vectorml
    goto v_21627;
v_21628:
    goto v_21624;
v_21625:
    goto v_21626;
v_21627:
    if (v_21660 == v_21659) goto v_21622;
    else goto v_21623;
v_21622:
    goto v_21637;
v_21633:
    v_21660 = elt(env, 3); // vector
    goto v_21634;
v_21635:
    v_21659 = stack[-2];
    v_21659 = qcdr(v_21659);
    goto v_21636;
v_21637:
    goto v_21633;
v_21634:
    goto v_21635;
v_21636:
    v_21659 = cons(v_21660, v_21659);
    env = stack[-4];
    stack[-2] = v_21659;
    goto v_21621;
v_21623:
v_21621:
    v_21659 = elt(env, 9); // "<OMS cd="""
    fn = elt(env, 13); // printout
    v_21659 = (*qfn1(fn))(fn, v_21659);
    env = stack[-4];
    v_21659 = stack[-3];
    v_21659 = Lprinc(nil, v_21659);
    env = stack[-4];
    v_21659 = elt(env, 10); // """ name="""
    v_21659 = Lprinc(nil, v_21659);
    env = stack[-4];
    v_21659 = stack[0];
    v_21659 = Lprinc(nil, v_21659);
    env = stack[-4];
    v_21659 = elt(env, 11); // """/>"
    v_21659 = Lprinc(nil, v_21659);
    env = stack[-4];
    v_21659 = stack[-2];
    v_21659 = qcdr(v_21659);
    v_21659 = qcdr(v_21659);
    fn = elt(env, 15); // multiom
    v_21659 = (*qfn1(fn))(fn, v_21659);
    env = stack[-4];
    v_21659 = nil;
    fn = elt(env, 14); // indent!*
    v_21659 = (*qfn1(fn))(fn, v_21659);
    env = stack[-4];
    v_21659 = elt(env, 12); // "</OMA>"
    fn = elt(env, 13); // printout
    v_21659 = (*qfn1(fn))(fn, v_21659);
    v_21659 = nil;
    return onevalue(v_21659);
}



// Code for rewrite

static LispObject CC_rewrite(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21929, v_21930, v_21931;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21531);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-4] = v_21531;
// end of prologue
    v_21929 = elt(env, 1); // list
    v_21929 = ncons(v_21929);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21929 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    stack[-9] = v_21929;
    goto v_21552;
v_21546:
    v_21931 = elt(env, 2); // part
    goto v_21547;
v_21548:
    v_21930 = stack[-4];
    goto v_21549;
v_21550:
    v_21929 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21551;
v_21552:
    goto v_21546;
v_21547:
    goto v_21548;
v_21549:
    goto v_21550;
v_21551:
    v_21929 = list3(v_21931, v_21930, v_21929);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21929 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    stack[-8] = v_21929;
    goto v_21563;
v_21557:
    goto v_21570;
v_21566:
    v_21930 = elt(env, 3); // length
    goto v_21567;
v_21568:
    v_21929 = stack[-8];
    goto v_21569;
v_21570:
    goto v_21566;
v_21567:
    goto v_21568;
v_21569:
    v_21929 = list2(v_21930, v_21929);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21931 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    goto v_21558;
v_21559:
    v_21930 = nil;
    goto v_21560;
v_21561:
    v_21929 = elt(env, 4); // only
    goto v_21562;
v_21563:
    goto v_21557;
v_21558:
    goto v_21559;
v_21560:
    goto v_21561;
v_21562:
    fn = elt(env, 24); // assgnpri
    v_21929 = (*qfnn(fn))(fn, 3, v_21931, v_21930, v_21929);
    env = stack[-10];
    v_21929 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_21929;
v_21578:
    goto v_21592;
v_21586:
    stack[0] = elt(env, 5); // difference
    goto v_21587;
v_21588:
    goto v_21600;
v_21596:
    v_21930 = elt(env, 6); // arglength
    goto v_21597;
v_21598:
    v_21929 = stack[-4];
    goto v_21599;
v_21600:
    goto v_21596;
v_21597:
    goto v_21598;
v_21599:
    v_21929 = list2(v_21930, v_21929);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_21930 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    goto v_21589;
v_21590:
    v_21929 = stack[-5];
    goto v_21591;
v_21592:
    goto v_21586;
v_21587:
    goto v_21588;
v_21589:
    goto v_21590;
v_21591:
    v_21929 = list3(stack[0], v_21930, v_21929);
    env = stack[-10];
    fn = elt(env, 26); // aminusp!:
    v_21929 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    if (v_21929 == nil) goto v_21583;
    goto v_21577;
v_21583:
    goto v_21613;
v_21607:
    stack[-3] = elt(env, 7); // plus
    goto v_21608;
v_21609:
    goto v_21620;
v_21616:
    stack[-1] = elt(env, 3); // length
    goto v_21617;
v_21618:
    goto v_21627;
v_21623:
    stack[0] = elt(env, 8); // den
    goto v_21624;
v_21625:
    goto v_21636;
v_21630:
    v_21931 = elt(env, 2); // part
    goto v_21631;
v_21632:
    v_21930 = stack[-4];
    goto v_21633;
v_21634:
    v_21929 = stack[-5];
    goto v_21635;
v_21636:
    goto v_21630;
v_21631:
    goto v_21632;
v_21633:
    goto v_21634;
v_21635:
    v_21929 = list3(v_21931, v_21930, v_21929);
    env = stack[-10];
    goto v_21626;
v_21627:
    goto v_21623;
v_21624:
    goto v_21625;
v_21626:
    v_21929 = list2(stack[0], v_21929);
    env = stack[-10];
    goto v_21619;
v_21620:
    goto v_21616;
v_21617:
    goto v_21618;
v_21619:
    stack[-2] = list2(stack[-1], v_21929);
    env = stack[-10];
    goto v_21610;
v_21611:
    goto v_21645;
v_21641:
    stack[-1] = elt(env, 3); // length
    goto v_21642;
v_21643:
    goto v_21652;
v_21648:
    stack[0] = elt(env, 9); // num
    goto v_21649;
v_21650:
    goto v_21661;
v_21655:
    v_21931 = elt(env, 2); // part
    goto v_21656;
v_21657:
    v_21930 = stack[-4];
    goto v_21658;
v_21659:
    v_21929 = stack[-5];
    goto v_21660;
v_21661:
    goto v_21655;
v_21656:
    goto v_21657;
v_21658:
    goto v_21659;
v_21660:
    v_21929 = list3(v_21931, v_21930, v_21929);
    env = stack[-10];
    goto v_21651;
v_21652:
    goto v_21648;
v_21649:
    goto v_21650;
v_21651:
    v_21929 = list2(stack[0], v_21929);
    env = stack[-10];
    goto v_21644;
v_21645:
    goto v_21641;
v_21642:
    goto v_21643;
v_21644:
    v_21929 = list2(stack[-1], v_21929);
    env = stack[-10];
    goto v_21612;
v_21613:
    goto v_21607;
v_21608:
    goto v_21609;
v_21610:
    goto v_21611;
v_21612:
    v_21929 = list3(stack[-3], stack[-2], v_21929);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_21929 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    stack[0] = v_21929;
    goto v_21672;
v_21666:
    v_21929 = stack[0];
    fn = elt(env, 25); // aeval!*
    v_21931 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    goto v_21667;
v_21668:
    v_21930 = nil;
    goto v_21669;
v_21670:
    v_21929 = elt(env, 4); // only
    goto v_21671;
v_21672:
    goto v_21666;
v_21667:
    goto v_21668;
v_21669:
    goto v_21670;
v_21671:
    fn = elt(env, 24); // assgnpri
    v_21929 = (*qfnn(fn))(fn, 3, v_21931, v_21930, v_21929);
    env = stack[-10];
    goto v_21686;
v_21682:
    v_21929 = stack[0];
    fn = elt(env, 25); // aeval!*
    stack[-3] = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    goto v_21683;
v_21684:
    goto v_21697;
v_21691:
    stack[-2] = elt(env, 7); // plus
    goto v_21692;
v_21693:
    goto v_21704;
v_21700:
    stack[0] = elt(env, 3); // length
    goto v_21701;
v_21702:
    goto v_21711;
v_21707:
    v_21930 = elt(env, 8); // den
    goto v_21708;
v_21709:
    v_21929 = stack[-8];
    goto v_21710;
v_21711:
    goto v_21707;
v_21708:
    goto v_21709;
v_21710:
    v_21929 = list2(v_21930, v_21929);
    env = stack[-10];
    goto v_21703;
v_21704:
    goto v_21700;
v_21701:
    goto v_21702;
v_21703:
    stack[-1] = list2(stack[0], v_21929);
    env = stack[-10];
    goto v_21694;
v_21695:
    goto v_21719;
v_21715:
    stack[0] = elt(env, 3); // length
    goto v_21716;
v_21717:
    goto v_21726;
v_21722:
    v_21930 = elt(env, 9); // num
    goto v_21723;
v_21724:
    v_21929 = stack[-8];
    goto v_21725;
v_21726:
    goto v_21722;
v_21723:
    goto v_21724;
v_21725:
    v_21929 = list2(v_21930, v_21929);
    env = stack[-10];
    goto v_21718;
v_21719:
    goto v_21715;
v_21716:
    goto v_21717;
v_21718:
    v_21929 = list2(stack[0], v_21929);
    env = stack[-10];
    goto v_21696;
v_21697:
    goto v_21691;
v_21692:
    goto v_21693;
v_21694:
    goto v_21695;
v_21696:
    v_21929 = list3(stack[-2], stack[-1], v_21929);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_21929 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    goto v_21685;
v_21686:
    goto v_21682;
v_21683:
    goto v_21684;
v_21685:
    fn = elt(env, 27); // evallessp
    v_21929 = (*qfn2(fn))(fn, stack[-3], v_21929);
    env = stack[-10];
    if (v_21929 == nil) goto v_21680;
    goto v_21737;
v_21731:
    v_21931 = elt(env, 2); // part
    goto v_21732;
v_21733:
    v_21930 = stack[-4];
    goto v_21734;
v_21735:
    v_21929 = stack[-5];
    goto v_21736;
v_21737:
    goto v_21731;
v_21732:
    goto v_21733;
v_21734:
    goto v_21735;
v_21736:
    v_21929 = list3(v_21931, v_21930, v_21929);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_21929 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    stack[-8] = v_21929;
    goto v_21678;
v_21680:
v_21678:
    v_21929 = nil;
    fn = elt(env, 25); // aeval!*
    v_21929 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    v_21929 = stack[-5];
    goto v_21753;
v_21747:
    v_21931 = elt(env, 7); // plus
    goto v_21748;
v_21749:
    v_21930 = v_21929;
    goto v_21750;
v_21751:
    v_21929 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21752;
v_21753:
    goto v_21747;
v_21748:
    goto v_21749;
v_21750:
    goto v_21751;
v_21752:
    v_21929 = list3(v_21931, v_21930, v_21929);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_21929 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    stack[-5] = v_21929;
    goto v_21578;
v_21577:
    goto v_21764;
v_21758:
    v_21929 = elt(env, 10); // "g is "
    fn = elt(env, 23); // aeval
    v_21931 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    goto v_21759;
v_21760:
    v_21930 = nil;
    goto v_21761;
v_21762:
    v_21929 = elt(env, 11); // first
    goto v_21763;
v_21764:
    goto v_21758;
v_21759:
    goto v_21760;
v_21761:
    goto v_21762;
v_21763:
    fn = elt(env, 24); // assgnpri
    v_21929 = (*qfnn(fn))(fn, 3, v_21931, v_21930, v_21929);
    env = stack[-10];
    goto v_21776;
v_21770:
    v_21929 = stack[-8];
    fn = elt(env, 23); // aeval
    v_21931 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    goto v_21771;
v_21772:
    v_21930 = nil;
    goto v_21773;
v_21774:
    v_21929 = elt(env, 12); // last
    goto v_21775;
v_21776:
    goto v_21770;
v_21771:
    goto v_21772;
v_21773:
    goto v_21774;
v_21775:
    fn = elt(env, 24); // assgnpri
    v_21929 = (*qfnn(fn))(fn, 3, v_21931, v_21930, v_21929);
    env = stack[-10];
    v_21929 = stack[-4];
    fn = elt(env, 23); // aeval
    v_21929 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    fn = elt(env, 28); // getrlist
    v_21929 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    stack[-6] = v_21929;
v_21784:
    v_21929 = stack[-6];
    if (v_21929 == nil) goto v_21790;
    else goto v_21791;
v_21790:
    goto v_21783;
v_21791:
    v_21929 = stack[-6];
    v_21929 = qcar(v_21929);
    stack[0] = v_21929;
    goto v_21807;
v_21799:
    stack[-3] = elt(env, 13); // limit
    goto v_21800;
v_21801:
    goto v_21816;
v_21810:
    stack[-2] = elt(env, 14); // quotient
    goto v_21811;
v_21812:
    goto v_21823;
v_21819:
    v_21930 = elt(env, 15); // log
    goto v_21820;
v_21821:
    v_21929 = stack[0];
    goto v_21822;
v_21823:
    goto v_21819;
v_21820:
    goto v_21821;
v_21822:
    stack[-1] = list2(v_21930, v_21929);
    env = stack[-10];
    goto v_21813;
v_21814:
    goto v_21831;
v_21827:
    v_21930 = elt(env, 15); // log
    goto v_21828;
v_21829:
    v_21929 = stack[-8];
    goto v_21830;
v_21831:
    goto v_21827;
v_21828:
    goto v_21829;
v_21830:
    v_21929 = list2(v_21930, v_21929);
    env = stack[-10];
    goto v_21815;
v_21816:
    goto v_21810;
v_21811:
    goto v_21812;
v_21813:
    goto v_21814;
v_21815:
    v_21931 = list3(stack[-2], stack[-1], v_21929);
    env = stack[-10];
    goto v_21802;
v_21803:
    v_21930 = elt(env, 16); // x
    goto v_21804;
v_21805:
    v_21929 = elt(env, 17); // infinity
    goto v_21806;
v_21807:
    goto v_21799;
v_21800:
    goto v_21801;
v_21802:
    goto v_21803;
v_21804:
    goto v_21805;
v_21806:
    v_21929 = list4(stack[-3], v_21931, v_21930, v_21929);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21929 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    stack[-7] = v_21929;
    goto v_21844;
v_21838:
    stack[-5] = elt(env, 18); // expt
    goto v_21839;
v_21840:
    stack[-4] = elt(env, 19); // e
    goto v_21841;
v_21842:
    goto v_21854;
v_21848:
    stack[-3] = elt(env, 5); // difference
    goto v_21849;
v_21850:
    goto v_21861;
v_21857:
    v_21930 = elt(env, 15); // log
    goto v_21858;
v_21859:
    v_21929 = stack[0];
    goto v_21860;
v_21861:
    goto v_21857;
v_21858:
    goto v_21859;
v_21860:
    stack[-2] = list2(v_21930, v_21929);
    env = stack[-10];
    goto v_21851;
v_21852:
    goto v_21871;
v_21865:
    stack[-1] = elt(env, 20); // times
    goto v_21866;
v_21867:
    stack[0] = stack[-7];
    goto v_21868;
v_21869:
    goto v_21879;
v_21875:
    v_21930 = elt(env, 15); // log
    goto v_21876;
v_21877:
    v_21929 = stack[-8];
    goto v_21878;
v_21879:
    goto v_21875;
v_21876:
    goto v_21877;
v_21878:
    v_21929 = list2(v_21930, v_21929);
    env = stack[-10];
    goto v_21870;
v_21871:
    goto v_21865;
v_21866:
    goto v_21867;
v_21868:
    goto v_21869;
v_21870:
    v_21929 = list3(stack[-1], stack[0], v_21929);
    env = stack[-10];
    goto v_21853;
v_21854:
    goto v_21848;
v_21849:
    goto v_21850;
v_21851:
    goto v_21852;
v_21853:
    v_21929 = list3(stack[-3], stack[-2], v_21929);
    env = stack[-10];
    goto v_21843;
v_21844:
    goto v_21838;
v_21839:
    goto v_21840;
v_21841:
    goto v_21842;
v_21843:
    v_21929 = list3(stack[-5], stack[-4], v_21929);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21929 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    goto v_21890;
v_21884:
    stack[-1] = elt(env, 20); // times
    goto v_21885;
v_21886:
    stack[0] = v_21929;
    goto v_21887;
v_21888:
    goto v_21900;
v_21894:
    v_21931 = elt(env, 18); // expt
    goto v_21895;
v_21896:
    v_21930 = elt(env, 21); // w
    goto v_21897;
v_21898:
    v_21929 = stack[-7];
    goto v_21899;
v_21900:
    goto v_21894;
v_21895:
    goto v_21896;
v_21897:
    goto v_21898;
v_21899:
    v_21929 = list3(v_21931, v_21930, v_21929);
    env = stack[-10];
    goto v_21889;
v_21890:
    goto v_21884;
v_21885:
    goto v_21886;
v_21887:
    goto v_21888;
v_21889:
    v_21929 = list3(stack[-1], stack[0], v_21929);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21929 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    stack[0] = v_21929;
    goto v_21912;
v_21906:
    stack[-1] = elt(env, 22); // append
    goto v_21907;
v_21908:
    goto v_21919;
v_21915:
    v_21930 = elt(env, 1); // list
    goto v_21916;
v_21917:
    v_21929 = stack[0];
    goto v_21918;
v_21919:
    goto v_21915;
v_21916:
    goto v_21917;
v_21918:
    v_21930 = list2(v_21930, v_21929);
    env = stack[-10];
    goto v_21909;
v_21910:
    v_21929 = stack[-9];
    goto v_21911;
v_21912:
    goto v_21906;
v_21907:
    goto v_21908;
v_21909:
    goto v_21910;
v_21911:
    v_21929 = list3(stack[-1], v_21930, v_21929);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21929 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    stack[-9] = v_21929;
    v_21929 = nil;
    fn = elt(env, 23); // aeval
    v_21929 = (*qfn1(fn))(fn, v_21929);
    env = stack[-10];
    v_21929 = stack[-6];
    v_21929 = qcdr(v_21929);
    stack[-6] = v_21929;
    goto v_21784;
v_21783:
    v_21929 = stack[-9];
    {
        fn = elt(env, 23); // aeval
        return (*qfn1(fn))(fn, v_21929);
    }
    return onevalue(v_21929);
}



// Code for evalnumberp

static LispObject CC_evalnumberp(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21591, v_21592, v_21593;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21531);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21591 = v_21531;
// end of prologue
    fn = elt(env, 3); // aeval
    v_21591 = (*qfn1(fn))(fn, v_21591);
    env = stack[0];
    v_21593 = v_21591;
    v_21591 = v_21593;
    if (!consp(v_21591)) goto v_21538;
    else goto v_21539;
v_21538:
    v_21591 = v_21593;
    v_21591 = (is_number(v_21591) ? lisp_true : nil);
    goto v_21537;
v_21539:
    goto v_21553;
v_21549:
    v_21591 = v_21593;
    v_21592 = qcar(v_21591);
    goto v_21550;
v_21551:
    v_21591 = elt(env, 1); // !*sq
    goto v_21552;
v_21553:
    goto v_21549;
v_21550:
    goto v_21551;
v_21552:
    if (v_21592 == v_21591) goto v_21548;
    v_21591 = lisp_true;
    goto v_21546;
v_21548:
    v_21591 = v_21593;
    v_21591 = qcdr(v_21591);
    v_21591 = qcar(v_21591);
    v_21591 = qcdr(v_21591);
    v_21591 = (consp(v_21591) ? nil : lisp_true);
    v_21591 = (v_21591 == nil ? lisp_true : nil);
    goto v_21546;
    v_21591 = nil;
v_21546:
    if (v_21591 == nil) goto v_21544;
    v_21591 = nil;
    goto v_21537;
v_21544:
    v_21591 = v_21593;
    v_21591 = qcdr(v_21591);
    v_21591 = qcar(v_21591);
    v_21591 = qcar(v_21591);
    v_21592 = v_21591;
    v_21591 = v_21592;
    if (!consp(v_21591)) goto v_21576;
    else goto v_21577;
v_21576:
    v_21591 = lisp_true;
    goto v_21575;
v_21577:
    goto v_21587;
v_21583:
    v_21591 = v_21592;
    v_21591 = qcar(v_21591);
    goto v_21584;
v_21585:
    v_21592 = elt(env, 2); // numbertag
    goto v_21586;
v_21587:
    goto v_21583;
v_21584:
    goto v_21585;
v_21586:
        return Lflagp(nil, v_21591, v_21592);
    v_21591 = nil;
v_21575:
    goto v_21537;
    v_21591 = nil;
v_21537:
    return onevalue(v_21591);
}



// Code for contposp

static LispObject CC_contposp(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21553, v_21554;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21553 = v_21531;
// end of prologue
v_21530:
    v_21554 = v_21553;
    if (v_21554 == nil) goto v_21535;
    else goto v_21536;
v_21535:
    v_21553 = lisp_true;
    goto v_21534;
v_21536:
    v_21554 = v_21553;
    v_21554 = qcar(v_21554);
    if (!consp(v_21554)) goto v_21543;
    else goto v_21544;
v_21543:
    v_21553 = qcdr(v_21553);
    goto v_21530;
v_21544:
    v_21553 = nil;
    goto v_21542;
    v_21553 = nil;
v_21542:
    goto v_21534;
    v_21553 = nil;
v_21534:
    return onevalue(v_21553);
}



// Code for gbfplus

static LispObject CC_gbfplus(LispObject env,
                         LispObject v_21531, LispObject v_21532)
{
    env = qenv(env);
    LispObject v_21560, v_21561;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21531,v_21532);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21532;
    stack[-1] = v_21531;
// end of prologue
    goto v_21539;
v_21535:
    goto v_21545;
v_21541:
    v_21560 = stack[-1];
    v_21561 = qcar(v_21560);
    goto v_21542;
v_21543:
    v_21560 = stack[0];
    v_21560 = qcar(v_21560);
    goto v_21544;
v_21545:
    goto v_21541;
v_21542:
    goto v_21543;
v_21544:
    fn = elt(env, 1); // plubf
    stack[-2] = (*qfn2(fn))(fn, v_21561, v_21560);
    env = stack[-3];
    goto v_21536;
v_21537:
    goto v_21555;
v_21551:
    v_21560 = stack[-1];
    v_21561 = qcdr(v_21560);
    goto v_21552;
v_21553:
    v_21560 = stack[0];
    v_21560 = qcdr(v_21560);
    goto v_21554;
v_21555:
    goto v_21551;
v_21552:
    goto v_21553;
v_21554:
    fn = elt(env, 1); // plubf
    v_21560 = (*qfn2(fn))(fn, v_21561, v_21560);
    goto v_21538;
v_21539:
    goto v_21535;
v_21536:
    goto v_21537;
v_21538:
    {
        LispObject v_21565 = stack[-2];
        return cons(v_21565, v_21560);
    }
}



// Code for diff_vertex

static LispObject CC_diff_vertex(LispObject env,
                         LispObject v_21531, LispObject v_21532)
{
    env = qenv(env);
    LispObject v_21584, v_21585, v_21586;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21531,v_21532);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21532;
    stack[-1] = v_21531;
// end of prologue
    v_21586 = nil;
v_21537:
    v_21584 = stack[-1];
    if (v_21584 == nil) goto v_21540;
    else goto v_21541;
v_21540:
    v_21584 = v_21586;
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_21584);
    }
v_21541:
    goto v_21552;
v_21548:
    v_21584 = stack[-1];
    v_21584 = qcar(v_21584);
    v_21585 = qcar(v_21584);
    goto v_21549;
v_21550:
    v_21584 = stack[0];
    goto v_21551;
v_21552:
    goto v_21548;
v_21549:
    goto v_21550;
v_21551:
    v_21584 = Lassoc(nil, v_21585, v_21584);
    if (v_21584 == nil) goto v_21546;
    goto v_21563;
v_21559:
    v_21584 = stack[-1];
    v_21584 = qcar(v_21584);
    v_21585 = qcar(v_21584);
    goto v_21560;
v_21561:
    v_21584 = qvalue(elt(env, 1)); // !_0edge
    v_21584 = qcar(v_21584);
    goto v_21562;
v_21563:
    goto v_21559;
v_21560:
    goto v_21561;
v_21562:
    if (v_21585 == v_21584) goto v_21546;
    v_21584 = stack[-1];
    v_21584 = qcdr(v_21584);
    stack[-1] = v_21584;
    goto v_21537;
v_21546:
    goto v_21578;
v_21574:
    v_21584 = stack[-1];
    v_21584 = qcar(v_21584);
    goto v_21575;
v_21576:
    v_21585 = v_21586;
    goto v_21577;
v_21578:
    goto v_21574;
v_21575:
    goto v_21576;
v_21577:
    v_21584 = cons(v_21584, v_21585);
    env = stack[-2];
    v_21586 = v_21584;
    v_21584 = stack[-1];
    v_21584 = qcdr(v_21584);
    stack[-1] = v_21584;
    goto v_21537;
    v_21584 = nil;
    return onevalue(v_21584);
}



// Code for assert_kernelp

static LispObject CC_assert_kernelp(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21577, v_21578;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21531);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21577 = v_21531;
// end of prologue
    v_21578 = v_21577;
    if (symbolp(v_21578)) goto v_21538;
    else goto v_21539;
v_21538:
    v_21577 = lisp_true;
    goto v_21535;
v_21539:
    v_21578 = v_21577;
    v_21578 = Lconsp(nil, v_21578);
    env = stack[0];
    if (v_21578 == nil) goto v_21544;
    else goto v_21545;
v_21544:
    v_21577 = nil;
    goto v_21535;
v_21545:
    v_21578 = v_21577;
    v_21578 = qcar(v_21578);
    if (!symbolp(v_21578)) v_21578 = nil;
    else { v_21578 = qfastgets(v_21578);
           if (v_21578 != nil) { v_21578 = elt(v_21578, 38); // fkernfn
#ifdef RECORD_GET
             if (v_21578 != SPID_NOPROP)
                record_get(elt(fastget_names, 38), 1);
             else record_get(elt(fastget_names, 38), 0),
                v_21578 = nil; }
           else record_get(elt(fastget_names, 38), 0); }
#else
             if (v_21578 == SPID_NOPROP) v_21578 = nil; }}
#endif
    if (v_21578 == nil) goto v_21552;
    v_21577 = lisp_true;
    goto v_21535;
v_21552:
    v_21578 = v_21577;
    v_21578 = qcar(v_21578);
    if (!consp(v_21578)) goto v_21559;
    else goto v_21560;
v_21559:
    v_21578 = v_21577;
    v_21578 = qcar(v_21578);
    if (!symbolp(v_21578)) v_21578 = nil;
    else { v_21578 = qfastgets(v_21578);
           if (v_21578 != nil) { v_21578 = elt(v_21578, 24); // klist
#ifdef RECORD_GET
             if (v_21578 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v_21578 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v_21578 == SPID_NOPROP) v_21578 = nil; }}
#endif
    goto v_21558;
v_21560:
    v_21578 = qvalue(elt(env, 1)); // exlist!*
    goto v_21558;
    v_21578 = nil;
v_21558:
    goto v_21573;
v_21569:
    goto v_21570;
v_21571:
    goto v_21572;
v_21573:
    goto v_21569;
v_21570:
    goto v_21571;
v_21572:
    v_21577 = Latsoc(nil, v_21577, v_21578);
v_21535:
    return onevalue(v_21577);
}



// Code for dp_from_ei

static LispObject CC_dp_from_ei(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21544;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21531);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21531;
// end of prologue
    goto v_21539;
v_21535:
    v_21544 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 1); // cali_bc_fi
    stack[-1] = (*qfn1(fn))(fn, v_21544);
    env = stack[-2];
    goto v_21536;
v_21537:
    v_21544 = stack[0];
    fn = elt(env, 2); // mo_from_ei
    v_21544 = (*qfn1(fn))(fn, v_21544);
    env = stack[-2];
    goto v_21538;
v_21539:
    goto v_21535;
v_21536:
    goto v_21537;
v_21538:
    fn = elt(env, 3); // dp_term
    v_21544 = (*qfn2(fn))(fn, stack[-1], v_21544);
    return ncons(v_21544);
}



// Code for getavalue

static LispObject CC_getavalue(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21547, v_21548;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21547 = v_21531;
// end of prologue
    if (!symbolp(v_21547)) v_21547 = nil;
    else { v_21547 = qfastgets(v_21547);
           if (v_21547 != nil) { v_21547 = elt(v_21547, 4); // avalue
#ifdef RECORD_GET
             if (v_21547 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_21547 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_21547 == SPID_NOPROP) v_21547 = nil; }}
#endif
    v_21548 = v_21547;
    v_21547 = v_21548;
    if (v_21547 == nil) goto v_21539;
    v_21547 = v_21548;
    v_21547 = qcdr(v_21547);
    v_21547 = qcar(v_21547);
    goto v_21537;
v_21539:
    v_21547 = nil;
    goto v_21537;
    v_21547 = nil;
v_21537:
    return onevalue(v_21547);
}



// Code for msolve!-psys1

static LispObject CC_msolveKpsys1(LispObject env,
                         LispObject v_21531, LispObject v_21532)
{
    env = qenv(env);
    LispObject v_21655, v_21656;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21531,v_21532);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_21532;
    stack[0] = v_21531;
// end of prologue
    v_21655 = nil;
    v_21655 = ncons(v_21655);
    env = stack[-7];
    v_21656 = v_21655;
    v_21655 = stack[0];
    stack[-4] = v_21655;
v_21545:
    v_21655 = stack[-4];
    if (v_21655 == nil) goto v_21549;
    else goto v_21550;
v_21549:
    goto v_21544;
v_21550:
    v_21655 = stack[-4];
    v_21655 = qcar(v_21655);
    stack[-3] = v_21655;
    v_21655 = nil;
    stack[-6] = v_21655;
    v_21655 = v_21656;
    stack[-2] = v_21655;
v_21560:
    v_21655 = stack[-2];
    if (v_21655 == nil) goto v_21564;
    else goto v_21565;
v_21564:
    goto v_21559;
v_21565:
    v_21655 = stack[-2];
    v_21655 = qcar(v_21655);
    stack[-1] = v_21655;
    goto v_21578;
v_21574:
    v_21656 = stack[-3];
    goto v_21575;
v_21576:
    v_21655 = stack[-1];
    goto v_21577;
v_21578:
    goto v_21574;
v_21575:
    goto v_21576;
v_21577:
    fn = elt(env, 1); // subf
    v_21655 = (*qfn2(fn))(fn, v_21656, v_21655);
    env = stack[-7];
    v_21655 = qcar(v_21655);
    fn = elt(env, 2); // moduntag
    v_21655 = (*qfn1(fn))(fn, v_21655);
    env = stack[-7];
    fn = elt(env, 3); // general!-reduce!-mod!-p
    v_21655 = (*qfn1(fn))(fn, v_21655);
    env = stack[-7];
    v_21656 = v_21655;
    v_21655 = v_21656;
    if (v_21655 == nil) goto v_21584;
    else goto v_21585;
v_21584:
    goto v_21592;
v_21588:
    v_21656 = stack[-1];
    goto v_21589;
v_21590:
    v_21655 = stack[-6];
    goto v_21591;
v_21592:
    goto v_21588;
v_21589:
    goto v_21590;
v_21591:
    v_21655 = cons(v_21656, v_21655);
    env = stack[-7];
    stack[-6] = v_21655;
    goto v_21583;
v_21585:
    v_21655 = v_21656;
    if (!consp(v_21655)) goto v_21599;
    else goto v_21600;
v_21599:
    v_21655 = lisp_true;
    goto v_21598;
v_21600:
    v_21655 = v_21656;
    v_21655 = qcar(v_21655);
    v_21655 = (consp(v_21655) ? nil : lisp_true);
    goto v_21598;
    v_21655 = nil;
v_21598:
    if (v_21655 == nil) goto v_21596;
    goto v_21583;
v_21596:
    goto v_21620;
v_21616:
    goto v_21617;
v_21618:
    v_21655 = stack[-5];
    goto v_21619;
v_21620:
    goto v_21616;
v_21617:
    goto v_21618;
v_21619:
    fn = elt(env, 4); // msolve!-poly
    v_21655 = (*qfn2(fn))(fn, v_21656, v_21655);
    env = stack[-7];
    stack[0] = v_21655;
v_21614:
    v_21655 = stack[0];
    if (v_21655 == nil) goto v_21625;
    else goto v_21626;
v_21625:
    goto v_21613;
v_21626:
    v_21655 = stack[0];
    v_21655 = qcar(v_21655);
    goto v_21637;
v_21633:
    goto v_21643;
v_21639:
    v_21656 = stack[-1];
    goto v_21640;
v_21641:
    goto v_21642;
v_21643:
    goto v_21639;
v_21640:
    goto v_21641;
v_21642:
    v_21656 = Lappend(nil, v_21656, v_21655);
    env = stack[-7];
    goto v_21634;
v_21635:
    v_21655 = stack[-6];
    goto v_21636;
v_21637:
    goto v_21633;
v_21634:
    goto v_21635;
v_21636:
    v_21655 = cons(v_21656, v_21655);
    env = stack[-7];
    stack[-6] = v_21655;
    v_21655 = stack[0];
    v_21655 = qcdr(v_21655);
    stack[0] = v_21655;
    goto v_21614;
v_21613:
    goto v_21583;
v_21583:
    v_21655 = stack[-2];
    v_21655 = qcdr(v_21655);
    stack[-2] = v_21655;
    goto v_21560;
v_21559:
    v_21655 = stack[-6];
    v_21656 = v_21655;
    v_21655 = stack[-4];
    v_21655 = qcdr(v_21655);
    stack[-4] = v_21655;
    goto v_21545;
v_21544:
    v_21655 = v_21656;
    return onevalue(v_21655);
}



// Code for ra_u

static LispObject CC_ra_u(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21536;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21531);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21536 = v_21531;
// end of prologue
    fn = elt(env, 1); // ra_iv
    v_21536 = (*qfn1(fn))(fn, v_21536);
    env = stack[0];
    {
        fn = elt(env, 2); // riv_u
        return (*qfn1(fn))(fn, v_21536);
    }
}



// Code for lastcar

static LispObject CC_lastcar(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21552, v_21553;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21552 = v_21531;
// end of prologue
v_21535:
    v_21553 = v_21552;
    if (v_21553 == nil) goto v_21538;
    else goto v_21539;
v_21538:
    v_21552 = nil;
    goto v_21534;
v_21539:
    v_21553 = v_21552;
    v_21553 = qcdr(v_21553);
    if (v_21553 == nil) goto v_21542;
    else goto v_21543;
v_21542:
    v_21552 = qcar(v_21552);
    goto v_21534;
v_21543:
    v_21552 = qcdr(v_21552);
    goto v_21535;
    v_21552 = nil;
v_21534:
    return onevalue(v_21552);
}



// Code for rl_qefsolset

static LispObject CC_rl_qefsolset(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21565, v_21566, v_21567, v_21568, v_21569;
    LispObject fn;
    LispObject v_21535, v_21534, v_21533, v_21532, v_21531;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "rl_qefsolset");
    va_start(aa, nargs);
    v_21531 = va_arg(aa, LispObject);
    v_21532 = va_arg(aa, LispObject);
    v_21533 = va_arg(aa, LispObject);
    v_21534 = va_arg(aa, LispObject);
    v_21535 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_21535,v_21534,v_21533,v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_21531,v_21532,v_21533,v_21534,v_21535);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_21565 = v_21535;
    v_21566 = v_21534;
    v_21567 = v_21533;
    v_21568 = v_21532;
    v_21569 = v_21531;
// end of prologue
    goto v_21542;
v_21538:
    stack[-3] = qvalue(elt(env, 1)); // rl_qefsolset!*
    goto v_21539;
v_21540:
    goto v_21553;
v_21545:
    stack[-2] = v_21569;
    goto v_21546;
v_21547:
    stack[-1] = v_21568;
    goto v_21548;
v_21549:
    stack[0] = v_21567;
    goto v_21550;
v_21551:
    goto v_21562;
v_21558:
    goto v_21559;
v_21560:
    goto v_21561;
v_21562:
    goto v_21558;
v_21559:
    goto v_21560;
v_21561:
    v_21565 = list2(v_21566, v_21565);
    env = stack[-4];
    goto v_21552;
v_21553:
    goto v_21545;
v_21546:
    goto v_21547;
v_21548:
    goto v_21549;
v_21550:
    goto v_21551;
v_21552:
    v_21565 = list3star(stack[-2], stack[-1], stack[0], v_21565);
    env = stack[-4];
    goto v_21541;
v_21542:
    goto v_21538;
v_21539:
    goto v_21540;
v_21541:
    {
        LispObject v_21574 = stack[-3];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_21574, v_21565);
    }
}



// Code for rl_bnfsimpl

static LispObject CC_rl_bnfsimpl(LispObject env,
                         LispObject v_21531, LispObject v_21532)
{
    env = qenv(env);
    LispObject v_21549, v_21550;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21531,v_21532);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21549 = v_21532;
    v_21550 = v_21531;
// end of prologue
    goto v_21539;
v_21535:
    stack[0] = qvalue(elt(env, 1)); // rl_bnfsimpl!*
    goto v_21536;
v_21537:
    goto v_21546;
v_21542:
    goto v_21543;
v_21544:
    goto v_21545;
v_21546:
    goto v_21542;
v_21543:
    goto v_21544;
v_21545:
    v_21549 = list2(v_21550, v_21549);
    env = stack[-1];
    goto v_21538;
v_21539:
    goto v_21535;
v_21536:
    goto v_21537;
v_21538:
    {
        LispObject v_21552 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_21552, v_21549);
    }
}



// Code for setfuncsnaryrd

static LispObject CC_setfuncsnaryrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21584, v_21585;
    LispObject fn;
    argcheck(nargs, 0, "setfuncsnaryrd");
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
    fn = elt(env, 3); // mathml
    v_21584 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_21584;
    v_21584 = stack[0];
    v_21584 = Lconsp(nil, v_21584);
    env = stack[-1];
    if (v_21584 == nil) goto v_21539;
    v_21584 = stack[0];
    v_21584 = qcdr(v_21584);
    v_21584 = qcar(v_21584);
    if (v_21584 == nil) goto v_21545;
    goto v_21557;
v_21553:
    v_21584 = stack[0];
    v_21584 = qcdr(v_21584);
    v_21584 = qcar(v_21584);
    v_21584 = qcar(v_21584);
    v_21584 = qcdr(v_21584);
    v_21584 = qcar(v_21584);
    v_21585 = Lintern(nil, v_21584);
    env = stack[-1];
    goto v_21554;
v_21555:
    v_21584 = elt(env, 1); // multiset
    goto v_21556;
v_21557:
    goto v_21553;
v_21554:
    goto v_21555;
v_21556:
    if (v_21585 == v_21584) goto v_21551;
    else goto v_21552;
v_21551:
    v_21584 = elt(env, 1); // multiset
    qvalue(elt(env, 2)) = v_21584; // mmlatts
    goto v_21550;
v_21552:
v_21550:
    goto v_21543;
v_21545:
v_21543:
    goto v_21537;
v_21539:
v_21537:
    v_21584 = stack[0];
    if (v_21584 == nil) goto v_21570;
    else goto v_21571;
v_21570:
    v_21584 = nil;
    goto v_21569;
v_21571:
    goto v_21581;
v_21577:
    goto v_21578;
v_21579:
    v_21584 = CC_setfuncsnaryrd(elt(env, 0), 0);
    goto v_21580;
v_21581:
    goto v_21577;
v_21578:
    goto v_21579;
v_21580:
    {
        LispObject v_21587 = stack[0];
        return cons(v_21587, v_21584);
    }
    v_21584 = nil;
v_21569:
    return onevalue(v_21584);
}



// Code for groebinvokecritm

static LispObject CC_groebinvokecritm(LispObject env,
                         LispObject v_21531, LispObject v_21532)
{
    env = qenv(env);
    LispObject v_21575, v_21576;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21531,v_21532);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_21532;
    stack[-2] = v_21531;
// end of prologue
    v_21575 = stack[-1];
    stack[-3] = v_21575;
v_21537:
    v_21575 = stack[-3];
    if (v_21575 == nil) goto v_21541;
    else goto v_21542;
v_21541:
    goto v_21536;
v_21542:
    v_21575 = stack[-3];
    v_21575 = qcar(v_21575);
    stack[0] = v_21575;
    goto v_21557;
v_21553:
    v_21575 = stack[-2];
    v_21576 = qcar(v_21575);
    goto v_21554;
v_21555:
    v_21575 = stack[0];
    v_21575 = qcar(v_21575);
    goto v_21556;
v_21557:
    goto v_21553;
v_21554:
    goto v_21555;
v_21556:
    fn = elt(env, 2); // buchvevdivides!?
    v_21575 = (*qfn2(fn))(fn, v_21576, v_21575);
    env = stack[-4];
    if (v_21575 == nil) goto v_21551;
    v_21575 = qvalue(elt(env, 1)); // mcount!*
    v_21575 = add1(v_21575);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_21575; // mcount!*
    goto v_21569;
v_21565:
    v_21576 = stack[0];
    goto v_21566;
v_21567:
    v_21575 = stack[-1];
    goto v_21568;
v_21569:
    goto v_21565;
v_21566:
    goto v_21567;
v_21568:
    fn = elt(env, 3); // groedeletip
    v_21575 = (*qfn2(fn))(fn, v_21576, v_21575);
    env = stack[-4];
    stack[-1] = v_21575;
    goto v_21549;
v_21551:
v_21549:
    v_21575 = stack[-3];
    v_21575 = qcdr(v_21575);
    stack[-3] = v_21575;
    goto v_21537;
v_21536:
    v_21575 = stack[-1];
    return onevalue(v_21575);
}



// Code for intrdsortin

static LispObject CC_intrdsortin(LispObject env,
                         LispObject v_21531, LispObject v_21532)
{
    env = qenv(env);
    LispObject v_21598, v_21599;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21531,v_21532);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21532;
    stack[-1] = v_21531;
// end of prologue
    stack[-2] = nil;
v_21537:
    v_21598 = stack[0];
    if (v_21598 == nil) goto v_21540;
    else goto v_21541;
v_21540:
    goto v_21548;
v_21544:
    stack[0] = stack[-2];
    goto v_21545;
v_21546:
    v_21598 = stack[-1];
    v_21598 = ncons(v_21598);
    env = stack[-3];
    goto v_21547;
v_21548:
    goto v_21544;
v_21545:
    goto v_21546;
v_21547:
    {
        LispObject v_21603 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_21603, v_21598);
    }
v_21541:
    v_21598 = stack[-1];
    v_21599 = qcar(v_21598);
    v_21598 = stack[0];
    v_21598 = qcar(v_21598);
    v_21598 = qcar(v_21598);
    goto v_21567;
v_21563:
    goto v_21564;
v_21565:
    goto v_21566;
v_21567:
    goto v_21563;
v_21564:
    goto v_21565;
v_21566:
    fn = elt(env, 2); // !:difference
    v_21598 = (*qfn2(fn))(fn, v_21599, v_21598);
    env = stack[-3];
    fn = elt(env, 3); // !:minusp
    v_21598 = (*qfn1(fn))(fn, v_21598);
    env = stack[-3];
    if (v_21598 == nil) goto v_21553;
    goto v_21575;
v_21571:
    v_21598 = stack[0];
    v_21599 = qcar(v_21598);
    goto v_21572;
v_21573:
    v_21598 = stack[-2];
    goto v_21574;
v_21575:
    goto v_21571;
v_21572:
    goto v_21573;
v_21574:
    v_21598 = cons(v_21599, v_21598);
    env = stack[-3];
    stack[-2] = v_21598;
    v_21598 = stack[0];
    v_21598 = qcdr(v_21598);
    stack[0] = v_21598;
    goto v_21537;
v_21553:
    goto v_21588;
v_21584:
    goto v_21585;
v_21586:
    goto v_21595;
v_21591:
    v_21599 = stack[-1];
    goto v_21592;
v_21593:
    v_21598 = stack[0];
    goto v_21594;
v_21595:
    goto v_21591;
v_21592:
    goto v_21593;
v_21594:
    v_21598 = cons(v_21599, v_21598);
    env = stack[-3];
    goto v_21587;
v_21588:
    goto v_21584;
v_21585:
    goto v_21586;
v_21587:
    {
        LispObject v_21604 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_21604, v_21598);
    }
    v_21598 = nil;
    return onevalue(v_21598);
}



// Code for z!-roads

static LispObject CC_zKroads(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21608, v_21609, v_21610;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21609 = v_21531;
// end of prologue
    goto v_21541;
v_21537:
    v_21610 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21538;
v_21539:
    v_21608 = v_21609;
    v_21608 = qcar(v_21608);
    v_21608 = qcar(v_21608);
    v_21608 = qcdr(v_21608);
    goto v_21540;
v_21541:
    goto v_21537;
v_21538:
    goto v_21539;
v_21540:
    if (v_21610 == v_21608) goto v_21535;
    else goto v_21536;
v_21535:
    v_21608 = v_21609;
    v_21608 = qcar(v_21608);
    v_21608 = qcar(v_21608);
    goto v_21534;
v_21536:
    goto v_21556;
v_21552:
    v_21610 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21553;
v_21554:
    v_21608 = v_21609;
    v_21608 = qcar(v_21608);
    v_21608 = qcdr(v_21608);
    v_21608 = qcar(v_21608);
    v_21608 = qcdr(v_21608);
    goto v_21555;
v_21556:
    goto v_21552;
v_21553:
    goto v_21554;
v_21555:
    if (v_21610 == v_21608) goto v_21550;
    else goto v_21551;
v_21550:
    v_21608 = v_21609;
    v_21608 = qcar(v_21608);
    v_21608 = qcdr(v_21608);
    v_21608 = qcar(v_21608);
    goto v_21534;
v_21551:
    goto v_21573;
v_21569:
    v_21610 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21570;
v_21571:
    v_21608 = v_21609;
    v_21608 = qcar(v_21608);
    v_21608 = qcdr(v_21608);
    v_21608 = qcdr(v_21608);
    v_21608 = qcar(v_21608);
    v_21608 = qcdr(v_21608);
    goto v_21572;
v_21573:
    goto v_21569;
v_21570:
    goto v_21571;
v_21572:
    if (v_21610 == v_21608) goto v_21567;
    else goto v_21568;
v_21567:
    v_21608 = v_21609;
    v_21608 = qcar(v_21608);
    v_21608 = qcdr(v_21608);
    v_21608 = qcdr(v_21608);
    v_21608 = qcar(v_21608);
    goto v_21534;
v_21568:
    v_21608 = nil;
    goto v_21534;
    v_21608 = nil;
v_21534:
    v_21610 = v_21608;
    v_21608 = v_21610;
    if (v_21608 == nil) goto v_21592;
    else goto v_21593;
v_21592:
    v_21608 = nil;
    goto v_21591;
v_21593:
    goto v_21603;
v_21599:
    v_21608 = v_21610;
    v_21608 = qcar(v_21608);
    goto v_21600;
v_21601:
    v_21609 = qcdr(v_21609);
    goto v_21602;
v_21603:
    goto v_21599;
v_21600:
    goto v_21601;
v_21602:
    return cons(v_21608, v_21609);
    v_21608 = nil;
v_21591:
    return onevalue(v_21608);
}



// Code for listeval0

static LispObject CC_listeval0(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21613, v_21614, v_21615;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21531);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21531;
// end of prologue
    goto v_21545;
v_21541:
    v_21613 = qvalue(elt(env, 1)); // simpcount!*
    v_21614 = add1(v_21613);
    env = stack[-1];
    qvalue(elt(env, 1)) = v_21614; // simpcount!*
    goto v_21542;
v_21543:
    v_21613 = qvalue(elt(env, 2)); // simplimit!*
    goto v_21544;
v_21545:
    goto v_21541;
v_21542:
    goto v_21543;
v_21544:
    v_21613 = (LispObject)greaterp2(v_21614, v_21613);
    v_21613 = v_21613 ? lisp_true : nil;
    env = stack[-1];
    if (v_21613 == nil) goto v_21539;
    v_21613 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_21613; // simpcount!*
    goto v_21557;
v_21551:
    v_21615 = elt(env, 3); // rlisp
    goto v_21552;
v_21553:
    v_21614 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_21554;
v_21555:
    v_21613 = elt(env, 4); // "Simplification recursion too deep"
    goto v_21556;
v_21557:
    goto v_21551;
v_21552:
    goto v_21553;
v_21554:
    goto v_21555;
v_21556:
    fn = elt(env, 6); // rerror
    v_21613 = (*qfnn(fn))(fn, 3, v_21615, v_21614, v_21613);
    env = stack[-1];
    goto v_21537;
v_21539:
v_21537:
    v_21613 = stack[0];
    if (symbolp(v_21613)) goto v_21563;
    else goto v_21564;
v_21563:
    v_21613 = stack[0];
    if (!symbolp(v_21613)) v_21613 = nil;
    else { v_21613 = qfastgets(v_21613);
           if (v_21613 != nil) { v_21613 = elt(v_21613, 17); // share
#ifdef RECORD_GET
             if (v_21613 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v_21613 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v_21613 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v_21613 == SPID_NOPROP) v_21613 = nil; else v_21613 = lisp_true; }}
#endif
    if (v_21613 == nil) goto v_21569;
    v_21613 = stack[0];
    fn = elt(env, 7); // eval
    v_21613 = (*qfn1(fn))(fn, v_21613);
    env = stack[-1];
    v_21613 = CC_listeval0(elt(env, 0), v_21613);
    env = stack[-1];
    stack[0] = v_21613;
    goto v_21567;
v_21569:
    v_21613 = stack[0];
    if (!symbolp(v_21613)) v_21613 = nil;
    else { v_21613 = qfastgets(v_21613);
           if (v_21613 != nil) { v_21613 = elt(v_21613, 4); // avalue
#ifdef RECORD_GET
             if (v_21613 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_21613 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_21613 == SPID_NOPROP) v_21613 = nil; }}
#endif
    v_21615 = v_21613;
    if (v_21613 == nil) goto v_21576;
    goto v_21585;
v_21581:
    v_21613 = v_21615;
    v_21613 = qcdr(v_21613);
    v_21614 = qcar(v_21613);
    goto v_21582;
v_21583:
    v_21613 = stack[0];
    goto v_21584;
v_21585:
    goto v_21581;
v_21582:
    goto v_21583;
v_21584:
    if (equal(v_21614, v_21613)) goto v_21576;
    v_21613 = v_21615;
    v_21613 = qcdr(v_21613);
    v_21613 = qcar(v_21613);
    v_21613 = CC_listeval0(elt(env, 0), v_21613);
    env = stack[-1];
    stack[0] = v_21613;
    goto v_21567;
v_21576:
v_21567:
    goto v_21562;
v_21564:
v_21562:
    goto v_21602;
v_21598:
    v_21613 = stack[0];
    v_21613 = qcar(v_21613);
    fn = elt(env, 8); // getrtype
    v_21614 = (*qfn1(fn))(fn, v_21613);
    env = stack[-1];
    goto v_21599;
v_21600:
    v_21613 = elt(env, 5); // array
    goto v_21601;
v_21602:
    goto v_21598;
v_21599:
    goto v_21600;
v_21601:
    if (v_21614 == v_21613) goto v_21596;
    else goto v_21597;
v_21596:
    v_21613 = stack[0];
    fn = elt(env, 9); // getelv
    v_21613 = (*qfn1(fn))(fn, v_21613);
    env = stack[-1];
    v_21613 = CC_listeval0(elt(env, 0), v_21613);
    env = stack[-1];
    stack[0] = v_21613;
    goto v_21595;
v_21597:
v_21595:
    v_21613 = qvalue(elt(env, 1)); // simpcount!*
    v_21613 = sub1(v_21613);
    env = stack[-1];
    qvalue(elt(env, 1)) = v_21613; // simpcount!*
    v_21613 = stack[0];
    return onevalue(v_21613);
}



// Code for lalr_expand_grammar

static LispObject CC_lalr_expand_grammar(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21566, v_21567;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21531);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_21566 = v_21531;
// end of prologue
// Binding pending_rules!*
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 1, -1);
    qvalue(elt(env, 1)) = nil; // pending_rules!*
    fn = elt(env, 2); // lalr_check_grammar
    v_21566 = (*qfn1(fn))(fn, v_21566);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_21566; // pending_rules!*
    v_21566 = nil;
    stack[0] = v_21566;
v_21544:
    v_21566 = qvalue(elt(env, 1)); // pending_rules!*
    if (v_21566 == nil) goto v_21547;
    else goto v_21548;
v_21547:
    goto v_21543;
v_21548:
    v_21566 = qvalue(elt(env, 1)); // pending_rules!*
    v_21566 = qcar(v_21566);
    v_21567 = v_21566;
    v_21566 = qvalue(elt(env, 1)); // pending_rules!*
    v_21566 = qcdr(v_21566);
    qvalue(elt(env, 1)) = v_21566; // pending_rules!*
    goto v_21560;
v_21556:
    v_21566 = v_21567;
    fn = elt(env, 3); // expand_rule
    v_21567 = (*qfn1(fn))(fn, v_21566);
    env = stack[-2];
    goto v_21557;
v_21558:
    v_21566 = stack[0];
    goto v_21559;
v_21560:
    goto v_21556;
v_21557:
    goto v_21558;
v_21559:
    v_21566 = cons(v_21567, v_21566);
    env = stack[-2];
    stack[0] = v_21566;
    goto v_21544;
v_21543:
    v_21566 = stack[0];
    v_21566 = Lreverse(nil, v_21566);
    ;}  // end of a binding scope
    return onevalue(v_21566);
}



// Code for ofsf_sippsubst1

static LispObject CC_ofsf_sippsubst1(LispObject env,
                         LispObject v_21531, LispObject v_21532)
{
    env = qenv(env);
    LispObject v_21564, v_21565, v_21566;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21531,v_21532);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21565 = v_21532;
    v_21566 = v_21531;
// end of prologue
    goto v_21541;
v_21535:
    v_21564 = v_21566;
    if (!consp(v_21564)) goto v_21544;
    else goto v_21545;
v_21544:
    v_21564 = v_21566;
    stack[0] = v_21564;
    goto v_21543;
v_21545:
    v_21564 = v_21566;
    v_21564 = qcar(v_21564);
    stack[0] = v_21564;
    goto v_21543;
    stack[0] = nil;
v_21543:
    goto v_21536;
v_21537:
    goto v_21557;
v_21553:
    v_21564 = v_21566;
    v_21564 = qcdr(v_21564);
    v_21564 = qcar(v_21564);
    goto v_21554;
v_21555:
    goto v_21556;
v_21557:
    goto v_21553;
v_21554:
    goto v_21555;
v_21556:
    fn = elt(env, 1); // ofsf_siatsubf
    v_21564 = (*qfn2(fn))(fn, v_21564, v_21565);
    v_21565 = qcar(v_21564);
    goto v_21538;
v_21539:
    v_21564 = nil;
    goto v_21540;
v_21541:
    goto v_21535;
v_21536:
    goto v_21537;
v_21538:
    goto v_21539;
v_21540:
    {
        LispObject v_21568 = stack[0];
        return list3(v_21568, v_21565, v_21564);
    }
}



// Code for janettreenodebuild

static LispObject CC_janettreenodebuild(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21649, v_21650;
    LispObject fn;
    LispObject v_21533, v_21532, v_21531;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "janettreenodebuild");
    va_start(aa, nargs);
    v_21531 = va_arg(aa, LispObject);
    v_21532 = va_arg(aa, LispObject);
    v_21533 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21533,v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21531,v_21532,v_21533);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-5] = v_21533;
    stack[-6] = v_21532;
    stack[-7] = v_21531;
// end of prologue
    goto v_21544;
v_21540:
    v_21650 = stack[-5];
    goto v_21541;
v_21542:
    v_21649 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21543;
v_21544:
    goto v_21540;
v_21541:
    goto v_21542;
v_21543:
    v_21649 = *(LispObject *)((char *)v_21650 + (CELL-TAG_VECTOR) + (((intptr_t)v_21649-TAG_FIXNUM)/(16/CELL)));
    v_21649 = qcar(v_21649);
    stack[-3] = v_21649;
    goto v_21556;
v_21550:
    goto v_21562;
v_21558:
    v_21650 = stack[-3];
    goto v_21559;
v_21560:
    v_21649 = stack[-6];
    goto v_21561;
v_21562:
    goto v_21558;
v_21559:
    goto v_21560;
v_21561:
    fn = elt(env, 1); // monomgetvariabledegree
    stack[-1] = (*qfn2(fn))(fn, v_21650, v_21649);
    env = stack[-9];
    goto v_21551;
v_21552:
    stack[0] = nil;
    goto v_21553;
v_21554:
    v_21649 = nil;
    v_21649 = ncons(v_21649);
    env = stack[-9];
    goto v_21555;
v_21556:
    goto v_21550;
v_21551:
    goto v_21552;
v_21553:
    goto v_21554;
v_21555:
    v_21649 = acons(stack[-1], stack[0], v_21649);
    env = stack[-9];
    stack[-8] = v_21649;
    v_21649 = stack[-8];
    stack[-4] = v_21649;
v_21571:
    goto v_21580;
v_21576:
    stack[0] = stack[-7];
    goto v_21577;
v_21578:
    goto v_21587;
v_21583:
    v_21650 = stack[-3];
    goto v_21584;
v_21585:
    v_21649 = stack[-6];
    goto v_21586;
v_21587:
    goto v_21583;
v_21584:
    goto v_21585;
v_21586:
    fn = elt(env, 1); // monomgetvariabledegree
    v_21649 = (*qfn2(fn))(fn, v_21650, v_21649);
    env = stack[-9];
    goto v_21579;
v_21580:
    goto v_21576;
v_21577:
    goto v_21578;
v_21579:
    if (((intptr_t)(stack[0])) > ((intptr_t)(v_21649))) goto v_21575;
    goto v_21570;
v_21575:
    goto v_21595;
v_21591:
    stack[0] = stack[-7];
    goto v_21592;
v_21593:
    goto v_21602;
v_21598:
    v_21650 = stack[-3];
    goto v_21599;
v_21600:
    v_21649 = stack[-6];
    goto v_21601;
v_21602:
    goto v_21598;
v_21599:
    goto v_21600;
v_21601:
    fn = elt(env, 1); // monomgetvariabledegree
    v_21649 = (*qfn2(fn))(fn, v_21650, v_21649);
    env = stack[-9];
    goto v_21594;
v_21595:
    goto v_21591;
v_21592:
    goto v_21593;
v_21594:
    v_21649 = (LispObject)(intptr_t)((intptr_t)stack[0] - (intptr_t)v_21649 + TAG_FIXNUM);
    stack[-7] = v_21649;
    v_21649 = stack[-6];
    v_21649 = (LispObject)((intptr_t)(v_21649) + 0x10);
    stack[-6] = v_21649;
    goto v_21613;
v_21609:
    v_21649 = stack[-4];
    stack[-2] = qcdr(v_21649);
    goto v_21610;
v_21611:
    goto v_21623;
v_21617:
    goto v_21629;
v_21625:
    v_21650 = stack[-3];
    goto v_21626;
v_21627:
    v_21649 = stack[-6];
    goto v_21628;
v_21629:
    goto v_21625;
v_21626:
    goto v_21627;
v_21628:
    fn = elt(env, 1); // monomgetvariabledegree
    stack[-1] = (*qfn2(fn))(fn, v_21650, v_21649);
    env = stack[-9];
    goto v_21618;
v_21619:
    stack[0] = nil;
    goto v_21620;
v_21621:
    v_21649 = nil;
    v_21649 = ncons(v_21649);
    env = stack[-9];
    goto v_21622;
v_21623:
    goto v_21617;
v_21618:
    goto v_21619;
v_21620:
    goto v_21621;
v_21622:
    v_21649 = acons(stack[-1], stack[0], v_21649);
    env = stack[-9];
    goto v_21612;
v_21613:
    goto v_21609;
v_21610:
    goto v_21611;
v_21612:
    fn = elt(env, 2); // setcdr
    v_21649 = (*qfn2(fn))(fn, stack[-2], v_21649);
    env = stack[-9];
    v_21649 = stack[-4];
    v_21649 = qcdr(v_21649);
    v_21649 = qcdr(v_21649);
    stack[-4] = v_21649;
    goto v_21571;
v_21570:
    goto v_21644;
v_21640:
    v_21649 = stack[-4];
    v_21650 = qcar(v_21649);
    goto v_21641;
v_21642:
    v_21649 = stack[-5];
    goto v_21643;
v_21644:
    goto v_21640;
v_21641:
    goto v_21642;
v_21643:
    fn = elt(env, 2); // setcdr
    v_21649 = (*qfn2(fn))(fn, v_21650, v_21649);
    v_21649 = stack[-8];
    return onevalue(v_21649);
}



// Code for testord

static LispObject CC_testord(LispObject env,
                         LispObject v_21531, LispObject v_21532)
{
    env = qenv(env);
    LispObject v_21562, v_21563;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21531,v_21532);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21532;
    stack[-1] = v_21531;
// end of prologue
v_21536:
    v_21562 = stack[-1];
    if (v_21562 == nil) goto v_21539;
    else goto v_21540;
v_21539:
    v_21562 = lisp_true;
    goto v_21535;
v_21540:
    goto v_21550;
v_21546:
    v_21562 = stack[-1];
    v_21563 = qcar(v_21562);
    goto v_21547;
v_21548:
    v_21562 = stack[0];
    v_21562 = qcar(v_21562);
    goto v_21549;
v_21550:
    goto v_21546;
v_21547:
    goto v_21548;
v_21549:
    v_21562 = (LispObject)lesseq2(v_21563, v_21562);
    v_21562 = v_21562 ? lisp_true : nil;
    env = stack[-2];
    if (v_21562 == nil) goto v_21544;
    v_21562 = stack[-1];
    v_21562 = qcdr(v_21562);
    stack[-1] = v_21562;
    v_21562 = stack[0];
    v_21562 = qcdr(v_21562);
    stack[0] = v_21562;
    goto v_21536;
v_21544:
    v_21562 = nil;
    goto v_21535;
    v_21562 = nil;
v_21535:
    return onevalue(v_21562);
}



// Code for mk!+outer!+list

static LispObject CC_mkLouterLlist(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21544, v_21545;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21531);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_21531;
// end of prologue
    goto v_21540;
v_21536:
    v_21544 = elt(env, 1); // list
    v_21545 = ncons(v_21544);
    goto v_21537;
v_21538:
    v_21544 = stack[0];
    goto v_21539;
v_21540:
    goto v_21536;
v_21537:
    goto v_21538;
v_21539:
        return Lappend(nil, v_21545, v_21544);
    return onevalue(v_21544);
}



// Code for mri_opn

static LispObject CC_mri_opn(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21546, v_21547;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21531);
    }
// copy arguments values to proper place
    v_21546 = v_21531;
// end of prologue
    fn = elt(env, 1); // mri_op
    v_21546 = (*qfn1(fn))(fn, v_21546);
    v_21547 = v_21546;
    v_21546 = v_21547;
    if (!consp(v_21546)) goto v_21538;
    else goto v_21539;
v_21538:
    v_21546 = v_21547;
    goto v_21537;
v_21539:
    v_21546 = v_21547;
    v_21546 = qcar(v_21546);
    goto v_21537;
    v_21546 = nil;
v_21537:
    return onevalue(v_21546);
}



// Code for repr_n

static LispObject CC_repr_n(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21567, v_21568, v_21569;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21531);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21568 = v_21531;
// end of prologue
    v_21567 = v_21568;
    v_21567 = qcdr(v_21567);
    v_21567 = qcdr(v_21567);
    v_21567 = qcar(v_21567);
    if (v_21567 == nil) goto v_21535;
    else goto v_21536;
v_21535:
    v_21567 = elt(env, 1); // "repr_n : invalid REPR structure"
    v_21567 = ncons(v_21567);
    env = stack[0];
    {
        fn = elt(env, 2); // rederr
        return (*qfn1(fn))(fn, v_21567);
    }
v_21536:
    goto v_21550;
v_21546:
    v_21567 = v_21568;
    v_21567 = qcdr(v_21567);
    v_21567 = qcdr(v_21567);
    v_21567 = qcdr(v_21567);
    v_21567 = qcdr(v_21567);
    v_21569 = qcar(v_21567);
    goto v_21547;
v_21548:
    v_21567 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21549;
v_21550:
    goto v_21546;
v_21547:
    goto v_21548;
v_21549:
    if (v_21569 == v_21567) goto v_21544;
    else goto v_21545;
v_21544:
    v_21567 = nil;
    goto v_21534;
v_21545:
    v_21567 = v_21568;
    v_21567 = qcdr(v_21567);
    v_21567 = qcdr(v_21567);
    v_21567 = qcar(v_21567);
    v_21567 = qcar(v_21567);
    v_21567 = qcar(v_21567);
    goto v_21534;
    v_21567 = nil;
v_21534:
    return onevalue(v_21567);
}



// Code for rl_surep

static LispObject CC_rl_surep(LispObject env,
                         LispObject v_21531, LispObject v_21532)
{
    env = qenv(env);
    LispObject v_21549, v_21550;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21531,v_21532);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21549 = v_21532;
    v_21550 = v_21531;
// end of prologue
    goto v_21539;
v_21535:
    stack[0] = qvalue(elt(env, 1)); // rl_surep!*
    goto v_21536;
v_21537:
    goto v_21546;
v_21542:
    goto v_21543;
v_21544:
    goto v_21545;
v_21546:
    goto v_21542;
v_21543:
    goto v_21544;
v_21545:
    v_21549 = list2(v_21550, v_21549);
    env = stack[-1];
    goto v_21538;
v_21539:
    goto v_21535;
v_21536:
    goto v_21537;
v_21538:
    {
        LispObject v_21552 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_21552, v_21549);
    }
}



// Code for vdpcleanup

static LispObject CC_vdpcleanup(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21534;
    argcheck(nargs, 0, "vdpcleanup");
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
    v_21534 = nil;
    v_21534 = ncons(v_21534);
    env = stack[0];
    qvalue(elt(env, 1)) = v_21534; // dipevlist!*
    return onevalue(v_21534);
}



// Code for bflessp

static LispObject CC_bflessp(LispObject env,
                         LispObject v_21531, LispObject v_21532)
{
    env = qenv(env);
    LispObject v_21557, v_21558, v_21559;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21558 = v_21532;
    v_21559 = v_21531;
// end of prologue
    v_21557 = v_21559;
    if (!consp(v_21557)) goto v_21536;
    else goto v_21537;
v_21536:
    goto v_21544;
v_21540:
    v_21557 = v_21559;
    goto v_21541;
v_21542:
    goto v_21543;
v_21544:
    goto v_21540;
v_21541:
    goto v_21542;
v_21543:
        return Llessp(nil, v_21557, v_21558);
v_21537:
    goto v_21554;
v_21550:
    v_21557 = v_21558;
    goto v_21551;
v_21552:
    v_21558 = v_21559;
    goto v_21553;
v_21554:
    goto v_21550;
v_21551:
    goto v_21552;
v_21553:
    {
        fn = elt(env, 1); // grpbf
        return (*qfn2(fn))(fn, v_21557, v_21558);
    }
    v_21557 = nil;
    return onevalue(v_21557);
}



// Code for atom_compare

static LispObject CC_atom_compare(LispObject env,
                         LispObject v_21531, LispObject v_21532)
{
    env = qenv(env);
    LispObject v_21571, v_21572, v_21573;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21531,v_21532);
    }
// copy arguments values to proper place
    v_21572 = v_21532;
    v_21573 = v_21531;
// end of prologue
    v_21571 = v_21573;
    if (is_number(v_21571)) goto v_21536;
    else goto v_21537;
v_21536:
    v_21571 = v_21572;
    if (is_number(v_21571)) goto v_21542;
    v_21571 = nil;
    goto v_21540;
v_21542:
    goto v_21552;
v_21548:
    v_21571 = v_21573;
    goto v_21549;
v_21550:
    goto v_21551;
v_21552:
    goto v_21548;
v_21549:
    goto v_21550;
v_21551:
    v_21571 = (LispObject)lessp2(v_21571, v_21572);
    v_21571 = v_21571 ? lisp_true : nil;
    v_21571 = (v_21571 == nil ? lisp_true : nil);
    goto v_21540;
    v_21571 = nil;
v_21540:
    goto v_21535;
v_21537:
    v_21571 = v_21572;
    if (symbolp(v_21571)) goto v_21556;
    else goto v_21557;
v_21556:
    goto v_21564;
v_21560:
    v_21571 = v_21573;
    goto v_21561;
v_21562:
    goto v_21563;
v_21564:
    goto v_21560;
v_21561:
    goto v_21562;
v_21563:
        return Lorderp(nil, v_21571, v_21572);
v_21557:
    v_21571 = v_21572;
    v_21571 = (is_number(v_21571) ? lisp_true : nil);
    goto v_21535;
    v_21571 = nil;
v_21535:
    return onevalue(v_21571);
}



// Code for makeqn!-maybe

static LispObject CC_makeqnKmaybe(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21554, v_21555, v_21556;
    LispObject v_21533, v_21532, v_21531;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "makeqn-maybe");
    va_start(aa, nargs);
    v_21531 = va_arg(aa, LispObject);
    v_21532 = va_arg(aa, LispObject);
    v_21533 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21554 = v_21533;
    v_21555 = v_21532;
    v_21556 = v_21531;
// end of prologue
    if (v_21554 == nil) goto v_21538;
    v_21554 = v_21555;
    goto v_21536;
v_21538:
    goto v_21550;
v_21544:
    v_21554 = elt(env, 1); // equal
    goto v_21545;
v_21546:
    goto v_21547;
v_21548:
    goto v_21549;
v_21550:
    goto v_21544;
v_21545:
    goto v_21546;
v_21547:
    goto v_21548;
v_21549:
    return list3(v_21554, v_21556, v_21555);
    v_21554 = nil;
v_21536:
    return onevalue(v_21554);
}



// Code for set_parser

static LispObject CC_set_parser(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21563, v_21564;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21531);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21531;
// end of prologue
    v_21563 = stack[0];
    v_21563 = qcar(v_21563);
    fn = elt(env, 8); // lex_restore_context
    v_21563 = (*qfn1(fn))(fn, v_21563);
    env = stack[-1];
    v_21563 = stack[0];
    v_21563 = qcdr(v_21563);
    stack[0] = v_21563;
    v_21563 = qcar(v_21563);
    qvalue(elt(env, 1)) = v_21563; // parser_action_table
    v_21563 = stack[0];
    v_21563 = qcdr(v_21563);
    stack[0] = v_21563;
    v_21563 = qcar(v_21563);
    v_21564 = v_21563;
    v_21563 = v_21564;
    v_21563 = qcar(v_21563);
    qvalue(elt(env, 2)) = v_21563; // reduction_fn
    v_21563 = v_21564;
    v_21563 = qcdr(v_21563);
    v_21564 = v_21563;
    v_21563 = qcar(v_21563);
    qvalue(elt(env, 3)) = v_21563; // reduction_rhs_n
    v_21563 = v_21564;
    v_21563 = qcdr(v_21563);
    v_21563 = qcar(v_21563);
    qvalue(elt(env, 4)) = v_21563; // reduction_lhs
    v_21563 = stack[0];
    v_21563 = qcdr(v_21563);
    stack[0] = v_21563;
    v_21563 = qcar(v_21563);
    qvalue(elt(env, 5)) = v_21563; // parser_goto_table
    v_21563 = stack[0];
    v_21563 = qcdr(v_21563);
    stack[0] = v_21563;
    v_21563 = qcar(v_21563);
    qvalue(elt(env, 6)) = v_21563; // nonterminal_codes
    v_21563 = stack[0];
    v_21563 = qcdr(v_21563);
    v_21563 = qcar(v_21563);
    qvalue(elt(env, 7)) = v_21563; // terminal_codes
    v_21563 = nil;
    return onevalue(v_21563);
}



// Code for ofsf_decdeg2

static LispObject CC_ofsf_decdeg2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21749, v_21750, v_21751;
    LispObject fn;
    LispObject v_21533, v_21532, v_21531;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_decdeg2");
    va_start(aa, nargs);
    v_21531 = va_arg(aa, LispObject);
    v_21532 = va_arg(aa, LispObject);
    v_21533 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21533,v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21531,v_21532,v_21533);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_21533;
    stack[-5] = v_21532;
    stack[-3] = v_21531;
// end of prologue
// Binding !*gcd
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-7, 1, -2);
    qvalue(elt(env, 1)) = nil; // !*gcd
    stack[-1] = nil;
    v_21749 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_21749;
    v_21749 = lisp_true;
    qvalue(elt(env, 1)) = v_21749; // !*gcd
    v_21749 = qvalue(elt(env, 2)); // !*rlbrkcxk
    if (v_21749 == nil) goto v_21548;
    goto v_21555;
v_21551:
    v_21750 = stack[-3];
    goto v_21552;
v_21553:
    v_21749 = stack[-5];
    goto v_21554;
v_21555:
    goto v_21551;
v_21552:
    goto v_21553;
v_21554:
    fn = elt(env, 4); // ofsf_cxkdgcd
    v_21749 = (*qfn2(fn))(fn, v_21750, v_21749);
    env = stack[-7];
    stack[0] = v_21749;
    goto v_21546;
v_21548:
v_21546:
    v_21749 = stack[-3];
    fn = elt(env, 5); // cl_atl1
    v_21749 = (*qfn1(fn))(fn, v_21749);
    env = stack[-7];
    stack[-3] = v_21749;
v_21562:
    v_21749 = stack[-3];
    if (v_21749 == nil) goto v_21565;
    goto v_21575;
v_21571:
    v_21750 = stack[0];
    goto v_21572;
v_21573:
    v_21749 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21574;
v_21575:
    goto v_21571;
v_21572:
    goto v_21573;
v_21574:
    v_21749 = Leqn(nil, v_21750, v_21749);
    env = stack[-7];
    if (v_21749 == nil) goto v_21569;
    else goto v_21565;
v_21569:
    goto v_21566;
v_21565:
    goto v_21561;
v_21566:
    v_21749 = stack[-3];
    v_21749 = qcar(v_21749);
    v_21750 = v_21749;
    v_21749 = stack[-3];
    v_21749 = qcdr(v_21749);
    stack[-3] = v_21749;
    v_21749 = v_21750;
    stack[-6] = v_21749;
    goto v_21595;
v_21589:
    v_21751 = stack[-6];
    goto v_21590;
v_21591:
    v_21750 = stack[-5];
    goto v_21592;
v_21593:
    v_21749 = stack[-4];
    goto v_21594;
v_21595:
    goto v_21589;
v_21590:
    goto v_21591;
v_21592:
    goto v_21593;
v_21594:
    fn = elt(env, 6); // ofsf_ignshift
    v_21749 = (*qfnn(fn))(fn, 3, v_21751, v_21750, v_21749);
    env = stack[-7];
    v_21751 = v_21749;
    goto v_21611;
v_21607:
    v_21750 = v_21751;
    goto v_21608;
v_21609:
    v_21749 = elt(env, 3); // odd
    goto v_21610;
v_21611:
    goto v_21607;
v_21608:
    goto v_21609;
v_21610:
    if (v_21750 == v_21749) goto v_21605;
    else goto v_21606;
v_21605:
    v_21749 = stack[-1];
    v_21749 = (v_21749 == nil ? lisp_true : nil);
    goto v_21604;
v_21606:
    v_21749 = nil;
    goto v_21604;
    v_21749 = nil;
v_21604:
    if (v_21749 == nil) goto v_21602;
    v_21749 = elt(env, 3); // odd
    stack[-1] = v_21749;
    goto v_21600;
v_21602:
    v_21749 = v_21751;
    if (v_21749 == nil) goto v_21620;
    else goto v_21621;
v_21620:
    goto v_21628;
v_21624:
    v_21749 = stack[-6];
    v_21749 = qcdr(v_21749);
    v_21750 = qcar(v_21749);
    goto v_21625;
v_21626:
    v_21749 = stack[-5];
    goto v_21627;
v_21628:
    goto v_21624;
v_21625:
    goto v_21626;
v_21627:
    fn = elt(env, 7); // sfto_reorder
    v_21749 = (*qfn2(fn))(fn, v_21750, v_21749);
    env = stack[-7];
    stack[-6] = v_21749;
v_21635:
    v_21749 = stack[-6];
    if (!consp(v_21749)) goto v_21646;
    else goto v_21647;
v_21646:
    v_21749 = lisp_true;
    goto v_21645;
v_21647:
    v_21749 = stack[-6];
    v_21749 = qcar(v_21749);
    v_21749 = (consp(v_21749) ? nil : lisp_true);
    goto v_21645;
    v_21749 = nil;
v_21645:
    if (v_21749 == nil) goto v_21642;
    else goto v_21643;
v_21642:
    goto v_21663;
v_21659:
    v_21749 = stack[-6];
    v_21749 = qcar(v_21749);
    v_21749 = qcar(v_21749);
    v_21750 = qcar(v_21749);
    goto v_21660;
v_21661:
    v_21749 = stack[-5];
    goto v_21662;
v_21663:
    goto v_21659;
v_21660:
    goto v_21661;
v_21662:
    if (v_21750 == v_21749) goto v_21657;
    else goto v_21658;
v_21657:
    goto v_21674;
v_21670:
    v_21750 = stack[0];
    goto v_21671;
v_21672:
    v_21749 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21673;
v_21674:
    goto v_21670;
v_21671:
    goto v_21672;
v_21673:
    v_21749 = Lneq(nil, v_21750, v_21749);
    env = stack[-7];
    goto v_21656;
v_21658:
    v_21749 = nil;
    goto v_21656;
    v_21749 = nil;
v_21656:
    goto v_21641;
v_21643:
    v_21749 = nil;
    goto v_21641;
    v_21749 = nil;
v_21641:
    if (v_21749 == nil) goto v_21638;
    else goto v_21639;
v_21638:
    goto v_21634;
v_21639:
    goto v_21689;
v_21685:
    v_21750 = stack[0];
    goto v_21686;
v_21687:
    v_21749 = stack[-6];
    v_21749 = qcar(v_21749);
    v_21749 = qcar(v_21749);
    v_21749 = qcdr(v_21749);
    goto v_21688;
v_21689:
    goto v_21685;
v_21686:
    goto v_21687;
v_21688:
    fn = elt(env, 8); // gcdf
    v_21749 = (*qfn2(fn))(fn, v_21750, v_21749);
    env = stack[-7];
    stack[0] = v_21749;
    v_21749 = stack[-6];
    v_21749 = qcdr(v_21749);
    stack[-6] = v_21749;
    goto v_21635;
v_21634:
    goto v_21600;
v_21621:
v_21600:
    goto v_21707;
v_21703:
    v_21750 = stack[0];
    goto v_21704;
v_21705:
    v_21749 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21706;
v_21707:
    goto v_21703;
v_21704:
    goto v_21705;
v_21706:
    v_21749 = (LispObject)greaterp2(v_21750, v_21749);
    v_21749 = v_21749 ? lisp_true : nil;
    env = stack[-7];
    if (v_21749 == nil) goto v_21700;
    goto v_21715;
v_21711:
    v_21750 = stack[-1];
    goto v_21712;
v_21713:
    v_21749 = elt(env, 3); // odd
    goto v_21714;
v_21715:
    goto v_21711;
v_21712:
    goto v_21713;
v_21714:
    if (v_21750 == v_21749) goto v_21710;
    else goto v_21700;
v_21710:
    v_21749 = lisp_true;
    stack[-1] = v_21749;
v_21721:
    goto v_21731;
v_21727:
    v_21750 = stack[0];
    goto v_21728;
v_21729:
    v_21749 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_21730;
v_21731:
    goto v_21727;
v_21728:
    goto v_21729;
v_21730:
    fn = elt(env, 9); // quotf
    v_21749 = (*qfn2(fn))(fn, v_21750, v_21749);
    env = stack[-7];
    v_21751 = v_21749;
    if (v_21749 == nil) goto v_21724;
    else goto v_21725;
v_21724:
    goto v_21720;
v_21725:
    v_21749 = v_21751;
    stack[0] = v_21749;
    goto v_21721;
v_21720:
    goto v_21698;
v_21700:
v_21698:
    goto v_21562;
v_21561:
    goto v_21744;
v_21740:
    v_21750 = stack[0];
    goto v_21741;
v_21742:
    v_21749 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21743;
v_21744:
    goto v_21740;
v_21741:
    goto v_21742;
v_21743:
    if (v_21750 == v_21749) goto v_21738;
    else goto v_21739;
v_21738:
    v_21749 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21542;
v_21739:
    v_21749 = stack[0];
v_21542:
    ;}  // end of a binding scope
    return onevalue(v_21749);
}



// Code for even_action_term

static LispObject CC_even_action_term(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21603, v_21604;
    LispObject fn;
    LispObject v_21534, v_21533, v_21532, v_21531;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "even_action_term");
    va_start(aa, nargs);
    v_21531 = va_arg(aa, LispObject);
    v_21532 = va_arg(aa, LispObject);
    v_21533 = va_arg(aa, LispObject);
    v_21534 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_21534,v_21533,v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_21531,v_21532,v_21533,v_21534);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-2] = v_21534;
    stack[-3] = v_21533;
    stack[-4] = v_21532;
    stack[-5] = v_21531;
// end of prologue
    goto v_21541;
v_21537:
    goto v_21551;
v_21543:
    stack[-6] = stack[-5];
    goto v_21544;
v_21545:
    v_21603 = stack[-4];
    stack[-1] = qcar(v_21603);
    goto v_21546;
v_21547:
    stack[0] = stack[-3];
    goto v_21548;
v_21549:
    goto v_21561;
v_21557:
    goto v_21567;
v_21563:
    v_21604 = stack[-2];
    goto v_21564;
v_21565:
    v_21603 = stack[-4];
    v_21603 = qcdr(v_21603);
    goto v_21566;
v_21567:
    goto v_21563;
v_21564:
    goto v_21565;
v_21566:
    fn = elt(env, 1); // multf
    v_21604 = (*qfn2(fn))(fn, v_21604, v_21603);
    env = stack[-7];
    goto v_21558;
v_21559:
    v_21603 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21560;
v_21561:
    goto v_21557;
v_21558:
    goto v_21559;
v_21560:
    v_21603 = cons(v_21604, v_21603);
    env = stack[-7];
    goto v_21550;
v_21551:
    goto v_21543;
v_21544:
    goto v_21545;
v_21546:
    goto v_21547;
v_21548:
    goto v_21549;
v_21550:
    fn = elt(env, 2); // even_action_pow
    stack[-1] = (*qfnn(fn))(fn, 4, stack[-6], stack[-1], stack[0], v_21603);
    env = stack[-7];
    goto v_21538;
v_21539:
    goto v_21581;
v_21573:
    goto v_21574;
v_21575:
    v_21603 = stack[-4];
    stack[0] = qcdr(v_21603);
    goto v_21576;
v_21577:
    goto v_21578;
v_21579:
    goto v_21591;
v_21587:
    goto v_21588;
v_21589:
    goto v_21599;
v_21595:
    v_21603 = stack[-4];
    v_21604 = qcar(v_21603);
    goto v_21596;
v_21597:
    v_21603 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21598;
v_21599:
    goto v_21595;
v_21596:
    goto v_21597;
v_21598:
    v_21603 = cons(v_21604, v_21603);
    env = stack[-7];
    v_21603 = ncons(v_21603);
    env = stack[-7];
    goto v_21590;
v_21591:
    goto v_21587;
v_21588:
    goto v_21589;
v_21590:
    fn = elt(env, 1); // multf
    v_21603 = (*qfn2(fn))(fn, stack[-2], v_21603);
    env = stack[-7];
    goto v_21580;
v_21581:
    goto v_21573;
v_21574:
    goto v_21575;
v_21576:
    goto v_21577;
v_21578:
    goto v_21579;
v_21580:
    fn = elt(env, 3); // even_action_sf
    v_21603 = (*qfnn(fn))(fn, 4, stack[-5], stack[0], stack[-3], v_21603);
    env = stack[-7];
    goto v_21540;
v_21541:
    goto v_21537;
v_21538:
    goto v_21539;
v_21540:
    {
        LispObject v_21612 = stack[-1];
        fn = elt(env, 4); // addsq
        return (*qfn2(fn))(fn, v_21612, v_21603);
    }
}



// Code for cl_atnum

static LispObject CC_cl_atnum(LispObject env,
                         LispObject v_21531)
{
    env = qenv(env);
    LispObject v_21782, v_21783, v_21784;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21531);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21531;
// end of prologue
v_21530:
    v_21782 = stack[0];
    if (!consp(v_21782)) goto v_21539;
    else goto v_21540;
v_21539:
    v_21782 = stack[0];
    goto v_21538;
v_21540:
    v_21782 = stack[0];
    v_21782 = qcar(v_21782);
    goto v_21538;
    v_21782 = nil;
v_21538:
    v_21784 = v_21782;
    goto v_21567;
v_21563:
    v_21783 = v_21784;
    goto v_21564;
v_21565:
    v_21782 = elt(env, 1); // or
    goto v_21566;
v_21567:
    goto v_21563;
v_21564:
    goto v_21565;
v_21566:
    if (v_21783 == v_21782) goto v_21561;
    else goto v_21562;
v_21561:
    v_21782 = lisp_true;
    goto v_21560;
v_21562:
    goto v_21577;
v_21573:
    v_21783 = v_21784;
    goto v_21574;
v_21575:
    v_21782 = elt(env, 2); // and
    goto v_21576;
v_21577:
    goto v_21573;
v_21574:
    goto v_21575;
v_21576:
    v_21782 = (v_21783 == v_21782 ? lisp_true : nil);
    goto v_21560;
    v_21782 = nil;
v_21560:
    if (v_21782 == nil) goto v_21558;
    v_21782 = lisp_true;
    goto v_21556;
v_21558:
    goto v_21588;
v_21584:
    v_21783 = v_21784;
    goto v_21585;
v_21586:
    v_21782 = elt(env, 3); // not
    goto v_21587;
v_21588:
    goto v_21584;
v_21585:
    goto v_21586;
v_21587:
    v_21782 = (v_21783 == v_21782 ? lisp_true : nil);
    goto v_21556;
    v_21782 = nil;
v_21556:
    if (v_21782 == nil) goto v_21554;
    v_21782 = lisp_true;
    goto v_21552;
v_21554:
    goto v_21603;
v_21599:
    v_21783 = v_21784;
    goto v_21600;
v_21601:
    v_21782 = elt(env, 4); // impl
    goto v_21602;
v_21603:
    goto v_21599;
v_21600:
    goto v_21601;
v_21602:
    if (v_21783 == v_21782) goto v_21597;
    else goto v_21598;
v_21597:
    v_21782 = lisp_true;
    goto v_21596;
v_21598:
    goto v_21617;
v_21613:
    v_21783 = v_21784;
    goto v_21614;
v_21615:
    v_21782 = elt(env, 5); // repl
    goto v_21616;
v_21617:
    goto v_21613;
v_21614:
    goto v_21615;
v_21616:
    if (v_21783 == v_21782) goto v_21611;
    else goto v_21612;
v_21611:
    v_21782 = lisp_true;
    goto v_21610;
v_21612:
    goto v_21627;
v_21623:
    v_21783 = v_21784;
    goto v_21624;
v_21625:
    v_21782 = elt(env, 6); // equiv
    goto v_21626;
v_21627:
    goto v_21623;
v_21624:
    goto v_21625;
v_21626:
    v_21782 = (v_21783 == v_21782 ? lisp_true : nil);
    goto v_21610;
    v_21782 = nil;
v_21610:
    goto v_21596;
    v_21782 = nil;
v_21596:
    goto v_21552;
    v_21782 = nil;
v_21552:
    if (v_21782 == nil) goto v_21550;
    v_21782 = stack[0];
    v_21782 = qcdr(v_21782);
    stack[-1] = v_21782;
    v_21782 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_21782;
v_21635:
    v_21782 = stack[-1];
    if (v_21782 == nil) goto v_21641;
    else goto v_21642;
v_21641:
    v_21782 = stack[0];
    goto v_21634;
v_21642:
    goto v_21650;
v_21646:
    v_21782 = stack[-1];
    v_21782 = qcar(v_21782);
    v_21783 = CC_cl_atnum(elt(env, 0), v_21782);
    env = stack[-2];
    goto v_21647;
v_21648:
    v_21782 = stack[0];
    goto v_21649;
v_21650:
    goto v_21646;
v_21647:
    goto v_21648;
v_21649:
    v_21782 = plus2(v_21783, v_21782);
    env = stack[-2];
    stack[0] = v_21782;
    v_21782 = stack[-1];
    v_21782 = qcdr(v_21782);
    stack[-1] = v_21782;
    goto v_21635;
v_21634:
    goto v_21536;
v_21550:
    goto v_21671;
v_21667:
    v_21783 = v_21784;
    goto v_21668;
v_21669:
    v_21782 = elt(env, 7); // ex
    goto v_21670;
v_21671:
    goto v_21667;
v_21668:
    goto v_21669;
v_21670:
    if (v_21783 == v_21782) goto v_21665;
    else goto v_21666;
v_21665:
    v_21782 = lisp_true;
    goto v_21664;
v_21666:
    goto v_21681;
v_21677:
    v_21783 = v_21784;
    goto v_21678;
v_21679:
    v_21782 = elt(env, 8); // all
    goto v_21680;
v_21681:
    goto v_21677;
v_21678:
    goto v_21679;
v_21680:
    v_21782 = (v_21783 == v_21782 ? lisp_true : nil);
    goto v_21664;
    v_21782 = nil;
v_21664:
    if (v_21782 == nil) goto v_21662;
    v_21782 = stack[0];
    v_21782 = qcdr(v_21782);
    v_21782 = qcdr(v_21782);
    v_21782 = qcar(v_21782);
    stack[0] = v_21782;
    goto v_21530;
v_21662:
    goto v_21702;
v_21698:
    v_21783 = v_21784;
    goto v_21699;
v_21700:
    v_21782 = elt(env, 9); // bex
    goto v_21701;
v_21702:
    goto v_21698;
v_21699:
    goto v_21700;
v_21701:
    if (v_21783 == v_21782) goto v_21696;
    else goto v_21697;
v_21696:
    v_21782 = lisp_true;
    goto v_21695;
v_21697:
    goto v_21712;
v_21708:
    v_21783 = v_21784;
    goto v_21709;
v_21710:
    v_21782 = elt(env, 10); // ball
    goto v_21711;
v_21712:
    goto v_21708;
v_21709:
    goto v_21710;
v_21711:
    v_21782 = (v_21783 == v_21782 ? lisp_true : nil);
    goto v_21695;
    v_21782 = nil;
v_21695:
    if (v_21782 == nil) goto v_21693;
    goto v_21721;
v_21717:
    v_21782 = stack[0];
    v_21782 = qcdr(v_21782);
    v_21782 = qcdr(v_21782);
    v_21782 = qcar(v_21782);
    stack[-1] = CC_cl_atnum(elt(env, 0), v_21782);
    env = stack[-2];
    goto v_21718;
v_21719:
    v_21782 = stack[0];
    v_21782 = qcdr(v_21782);
    v_21782 = qcdr(v_21782);
    v_21782 = qcdr(v_21782);
    v_21782 = qcar(v_21782);
    v_21782 = CC_cl_atnum(elt(env, 0), v_21782);
    goto v_21720;
v_21721:
    goto v_21717;
v_21718:
    goto v_21719;
v_21720:
    {
        LispObject v_21787 = stack[-1];
        return plus2(v_21787, v_21782);
    }
v_21693:
    goto v_21745;
v_21741:
    v_21783 = v_21784;
    goto v_21742;
v_21743:
    v_21782 = elt(env, 11); // true
    goto v_21744;
v_21745:
    goto v_21741;
v_21742:
    goto v_21743;
v_21744:
    if (v_21783 == v_21782) goto v_21739;
    else goto v_21740;
v_21739:
    v_21782 = lisp_true;
    goto v_21738;
v_21740:
    goto v_21755;
v_21751:
    v_21783 = v_21784;
    goto v_21752;
v_21753:
    v_21782 = elt(env, 12); // false
    goto v_21754;
v_21755:
    goto v_21751;
v_21752:
    goto v_21753;
v_21754:
    v_21782 = (v_21783 == v_21782 ? lisp_true : nil);
    goto v_21738;
    v_21782 = nil;
v_21738:
    if (v_21782 == nil) goto v_21736;
    v_21782 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21536;
v_21736:
    goto v_21769;
v_21765:
    v_21783 = v_21784;
    goto v_21766;
v_21767:
    v_21782 = elt(env, 0); // cl_atnum
    goto v_21768;
v_21769:
    goto v_21765;
v_21766:
    goto v_21767;
v_21768:
    fn = elt(env, 13); // rl_external
    v_21782 = (*qfn2(fn))(fn, v_21783, v_21782);
    env = stack[-2];
    v_21783 = v_21782;
    if (v_21782 == nil) goto v_21763;
    goto v_21777;
v_21773:
    stack[-1] = v_21783;
    goto v_21774;
v_21775:
    v_21782 = stack[0];
    v_21782 = ncons(v_21782);
    env = stack[-2];
    goto v_21776;
v_21777:
    goto v_21773;
v_21774:
    goto v_21775;
v_21776:
    {
        LispObject v_21788 = stack[-1];
        fn = elt(env, 14); // apply
        return (*qfn2(fn))(fn, v_21788, v_21782);
    }
v_21763:
    v_21782 = (LispObject)16+TAG_FIXNUM; // 1
v_21536:
    return onevalue(v_21782);
}



// Code for sq_member

static LispObject CC_sq_member(LispObject env,
                         LispObject v_21531, LispObject v_21532)
{
    env = qenv(env);
    LispObject v_21555, v_21556;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21531,v_21532);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21532;
    stack[-1] = v_21531;
// end of prologue
    goto v_21542;
v_21538:
    v_21556 = stack[-1];
    goto v_21539;
v_21540:
    v_21555 = stack[0];
    v_21555 = qcar(v_21555);
    goto v_21541;
v_21542:
    goto v_21538;
v_21539:
    goto v_21540;
v_21541:
    fn = elt(env, 1); // sf_member
    v_21555 = (*qfn2(fn))(fn, v_21556, v_21555);
    env = stack[-2];
    if (v_21555 == nil) goto v_21536;
    else goto v_21535;
v_21536:
    goto v_21551;
v_21547:
    v_21556 = stack[-1];
    goto v_21548;
v_21549:
    v_21555 = stack[0];
    v_21555 = qcdr(v_21555);
    goto v_21550;
v_21551:
    goto v_21547;
v_21548:
    goto v_21549;
v_21550:
    {
        fn = elt(env, 1); // sf_member
        return (*qfn2(fn))(fn, v_21556, v_21555);
    }
v_21535:
    return onevalue(v_21555);
}



// Code for simpexpt1

static LispObject CC_simpexpt1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22081, v_22082, v_22083;
    LispObject fn;
    LispObject v_21533, v_21532, v_21531;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "simpexpt1");
    va_start(aa, nargs);
    v_21531 = va_arg(aa, LispObject);
    v_21532 = va_arg(aa, LispObject);
    v_21533 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21533,v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21531,v_21532,v_21533);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_21533;
    stack[-5] = v_21532;
    stack[-6] = v_21531;
// end of prologue
// Binding !*allfac
// FLUIDBIND: reloadenv=8 litvec-offset=1 saveloc=7
{   bind_fluid_stack bind_fluid_var(-8, 1, -7);
    qvalue(elt(env, 1)) = nil; // !*allfac
// Binding !*div
// FLUIDBIND: reloadenv=8 litvec-offset=2 saveloc=3
{   bind_fluid_stack bind_fluid_var(-8, 2, -3);
    qvalue(elt(env, 2)) = nil; // !*div
    v_22081 = stack[-6];
    v_22081 = Lonep(nil, v_22081);
    env = stack[-8];
    if (v_22081 == nil) goto v_21545;
    goto v_21553;
v_21549:
    v_22082 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21550;
v_21551:
    v_22081 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21552;
v_21553:
    goto v_21549;
v_21550:
    goto v_21551;
v_21552:
    v_22081 = cons(v_22082, v_22081);
    goto v_21541;
v_21545:
    v_22081 = lisp_true;
    qvalue(elt(env, 1)) = v_22081; // !*allfac
    v_22081 = stack[-5];
    v_22081 = qcar(v_22081);
    stack[-2] = v_22081;
    goto v_21571;
v_21567:
    v_22082 = stack[-2];
    goto v_21568;
v_21569:
    v_22081 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21570;
v_21571:
    goto v_21567;
v_21568:
    goto v_21569;
v_21570:
    if (v_22082 == v_22081) goto v_21565;
    else goto v_21566;
v_21565:
    goto v_21578;
v_21574:
    v_22081 = stack[-5];
    v_22082 = qcdr(v_22081);
    goto v_21575;
v_21576:
    v_22081 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21577;
v_21578:
    goto v_21574;
v_21575:
    goto v_21576;
v_21577:
    v_22081 = (v_22082 == v_22081 ? lisp_true : nil);
    goto v_21564;
v_21566:
    v_22081 = nil;
    goto v_21564;
    v_22081 = nil;
v_21564:
    if (v_22081 == nil) goto v_21562;
    v_22081 = stack[-6];
    fn = elt(env, 10); // simp
    v_22081 = (*qfn1(fn))(fn, v_22081);
    goto v_21541;
v_21562:
    goto v_21600;
v_21596:
    v_22082 = stack[-6];
    goto v_21597;
v_21598:
    v_22081 = elt(env, 3); // e
    goto v_21599;
v_21600:
    goto v_21596;
v_21597:
    goto v_21598;
v_21599:
    if (v_22082 == v_22081) goto v_21594;
    else goto v_21595;
v_21594:
    v_22081 = stack[-5];
    v_22081 = qcdr(v_22081);
    if (!consp(v_22081)) goto v_21609;
    else goto v_21610;
v_21609:
    v_22081 = lisp_true;
    goto v_21608;
v_21610:
    v_22081 = stack[-5];
    v_22081 = qcdr(v_22081);
    v_22081 = qcar(v_22081);
    v_22081 = (consp(v_22081) ? nil : lisp_true);
    goto v_21608;
    v_22081 = nil;
v_21608:
    if (v_22081 == nil) goto v_21606;
    v_22081 = stack[-2];
    if (!consp(v_22081)) goto v_21626;
    else goto v_21627;
v_21626:
    v_22081 = lisp_true;
    goto v_21625;
v_21627:
    v_22081 = stack[-2];
    v_22081 = qcar(v_22081);
    v_22081 = (consp(v_22081) ? nil : lisp_true);
    goto v_21625;
    v_22081 = nil;
v_21625:
    if (v_22081 == nil) goto v_21622;
    else goto v_21623;
v_21622:
    goto v_21643;
v_21639:
    v_22081 = stack[-2];
    v_22081 = qcar(v_22081);
    v_22081 = qcar(v_22081);
    v_22082 = qcdr(v_22081);
    goto v_21640;
v_21641:
    v_22081 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21642;
v_21643:
    goto v_21639;
v_21640:
    goto v_21641;
v_21642:
    if (v_22082 == v_22081) goto v_21637;
    else goto v_21638;
v_21637:
    v_22081 = stack[-2];
    v_22081 = qcdr(v_22081);
    if (v_22081 == nil) goto v_21651;
    else goto v_21652;
v_21651:
    goto v_21660;
v_21656:
    v_22081 = stack[-2];
    v_22081 = qcar(v_22081);
    v_22081 = qcar(v_22081);
    v_22082 = qcar(v_22081);
    goto v_21657;
v_21658:
    v_22081 = elt(env, 4); // log
    goto v_21659;
v_21660:
    goto v_21656;
v_21657:
    goto v_21658;
v_21659:
    v_22081 = Leqcar(nil, v_22082, v_22081);
    env = stack[-8];
    goto v_21650;
v_21652:
    v_22081 = nil;
    goto v_21650;
    v_22081 = nil;
v_21650:
    goto v_21636;
v_21638:
    v_22081 = nil;
    goto v_21636;
    v_22081 = nil;
v_21636:
    goto v_21621;
v_21623:
    v_22081 = nil;
    goto v_21621;
    v_22081 = nil;
v_21621:
    goto v_21604;
v_21606:
    v_22081 = nil;
    goto v_21604;
    v_22081 = nil;
v_21604:
    goto v_21593;
v_21595:
    v_22081 = nil;
    goto v_21593;
    v_22081 = nil;
v_21593:
    if (v_22081 == nil) goto v_21591;
    goto v_21688;
v_21682:
    v_22081 = stack[-2];
    v_22081 = qcar(v_22081);
    v_22081 = qcar(v_22081);
    v_22081 = qcar(v_22081);
    v_22081 = qcdr(v_22081);
    v_22081 = qcar(v_22081);
    fn = elt(env, 11); // simp!*
    v_22081 = (*qfn1(fn))(fn, v_22081);
    env = stack[-8];
    fn = elt(env, 12); // prepsq!*
    stack[0] = (*qfn1(fn))(fn, v_22081);
    env = stack[-8];
    goto v_21683;
v_21684:
    goto v_21702;
v_21698:
    v_22081 = stack[-2];
    v_22081 = qcar(v_22081);
    v_22082 = qcdr(v_22081);
    goto v_21699;
v_21700:
    v_22081 = stack[-5];
    v_22081 = qcdr(v_22081);
    goto v_21701;
v_21702:
    goto v_21698;
v_21699:
    goto v_21700;
v_21701:
    v_22082 = cons(v_22082, v_22081);
    env = stack[-8];
    goto v_21685;
v_21686:
    v_22081 = nil;
    goto v_21687;
v_21688:
    goto v_21682;
v_21683:
    goto v_21684;
v_21685:
    goto v_21686;
v_21687:
    v_22081 = CC_simpexpt1(elt(env, 0), 3, stack[0], v_22082, v_22081);
    goto v_21541;
v_21591:
    v_22081 = stack[-2];
    if (!consp(v_22081)) goto v_21719;
    else goto v_21720;
v_21719:
    v_22081 = lisp_true;
    goto v_21718;
v_21720:
    v_22081 = stack[-2];
    v_22081 = qcar(v_22081);
    v_22081 = (consp(v_22081) ? nil : lisp_true);
    goto v_21718;
    v_22081 = nil;
v_21718:
    if (v_22081 == nil) goto v_21715;
    else goto v_21716;
v_21715:
    v_22081 = lisp_true;
    goto v_21714;
v_21716:
    v_22081 = stack[-5];
    v_22081 = qcdr(v_22081);
    if (!consp(v_22081)) goto v_21733;
    else goto v_21734;
v_21733:
    v_22081 = lisp_true;
    goto v_21732;
v_21734:
    v_22081 = stack[-5];
    v_22081 = qcdr(v_22081);
    v_22081 = qcar(v_22081);
    v_22081 = (consp(v_22081) ? nil : lisp_true);
    goto v_21732;
    v_22081 = nil;
v_21732:
    v_22081 = (v_22081 == nil ? lisp_true : nil);
    goto v_21714;
    v_22081 = nil;
v_21714:
    if (v_22081 == nil) goto v_21712;
    goto v_21752;
v_21746:
    v_22083 = stack[-6];
    goto v_21747;
v_21748:
    v_22082 = stack[-5];
    goto v_21749;
v_21750:
    v_22081 = stack[-4];
    goto v_21751;
v_21752:
    goto v_21746;
v_21747:
    goto v_21748;
v_21749:
    goto v_21750;
v_21751:
    fn = elt(env, 13); // simpexpt11
    v_22081 = (*qfnn(fn))(fn, 3, v_22083, v_22082, v_22081);
    goto v_21541;
v_21712:
    v_22081 = stack[-6];
    fn = elt(env, 10); // simp
    v_22081 = (*qfn1(fn))(fn, v_22081);
    env = stack[-8];
    stack[-1] = v_22081;
    v_22081 = stack[-2];
    if (v_22081 == nil) goto v_21760;
    else goto v_21761;
v_21760:
    v_22081 = stack[-1];
    v_22081 = qcar(v_22081);
    if (v_22081 == nil) goto v_21765;
    else goto v_21766;
v_21765:
    goto v_21776;
v_21770:
    v_22083 = elt(env, 5); // alg
    goto v_21771;
v_21772:
    v_22082 = (LispObject)224+TAG_FIXNUM; // 14
    goto v_21773;
v_21774:
    v_22081 = elt(env, 6); // "0**0 formed"
    goto v_21775;
v_21776:
    goto v_21770;
v_21771:
    goto v_21772;
v_21773:
    goto v_21774;
v_21775:
    fn = elt(env, 14); // rerror
    v_22081 = (*qfnn(fn))(fn, 3, v_22083, v_22082, v_22081);
    goto v_21764;
v_21766:
    goto v_21787;
v_21783:
    v_22082 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21784;
v_21785:
    v_22081 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21786;
v_21787:
    goto v_21783;
v_21784:
    goto v_21785;
v_21786:
    v_22081 = cons(v_22082, v_22081);
    goto v_21764;
    v_22081 = nil;
v_21764:
    goto v_21541;
v_21761:
    v_22081 = stack[-1];
    v_22081 = qcar(v_22081);
    if (v_22081 == nil) goto v_21792;
    else goto v_21793;
v_21792:
    v_22081 = stack[-2];
    if (!consp(v_22081)) goto v_21806;
    else goto v_21807;
v_21806:
    v_22081 = lisp_true;
    goto v_21805;
v_21807:
    v_22081 = stack[-2];
    v_22081 = qcar(v_22081);
    v_22081 = (consp(v_22081) ? nil : lisp_true);
    goto v_21805;
    v_22081 = nil;
v_21805:
    if (v_22081 == nil) goto v_21803;
    v_22081 = stack[-2];
    fn = elt(env, 15); // minusf
    v_22081 = (*qfn1(fn))(fn, v_22081);
    env = stack[-8];
    goto v_21801;
v_21803:
    v_22081 = nil;
    goto v_21801;
    v_22081 = nil;
v_21801:
    if (v_22081 == nil) goto v_21799;
    goto v_21827;
v_21821:
    v_22083 = elt(env, 5); // alg
    goto v_21822;
v_21823:
    v_22082 = (LispObject)240+TAG_FIXNUM; // 15
    goto v_21824;
v_21825:
    v_22081 = elt(env, 7); // "Zero divisor"
    goto v_21826;
v_21827:
    goto v_21821;
v_21822:
    goto v_21823;
v_21824:
    goto v_21825;
v_21826:
    fn = elt(env, 14); // rerror
    v_22081 = (*qfnn(fn))(fn, 3, v_22083, v_22082, v_22081);
    goto v_21797;
v_21799:
    goto v_21838;
v_21834:
    v_22082 = nil;
    goto v_21835;
v_21836:
    v_22081 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21837;
v_21838:
    goto v_21834;
v_21835:
    goto v_21836;
v_21837:
    v_22081 = cons(v_22082, v_22081);
    goto v_21797;
    v_22081 = nil;
v_21797:
    goto v_21791;
v_21793:
    v_22081 = stack[-2];
    if (!consp(v_22081)) goto v_21845;
    else goto v_21846;
v_21845:
    goto v_21856;
v_21852:
    v_22081 = stack[-5];
    v_22082 = qcdr(v_22081);
    goto v_21853;
v_21854:
    v_22081 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21855;
v_21856:
    goto v_21852;
v_21853:
    goto v_21854;
v_21855:
    if (v_22082 == v_22081) goto v_21850;
    else goto v_21851;
v_21850:
    v_22081 = stack[-1];
    v_22081 = qcar(v_22081);
    if (!consp(v_22081)) goto v_21866;
    else goto v_21867;
v_21866:
    v_22081 = lisp_true;
    goto v_21865;
v_21867:
    v_22081 = stack[-1];
    v_22081 = qcar(v_22081);
    v_22081 = qcar(v_22081);
    v_22081 = (consp(v_22081) ? nil : lisp_true);
    goto v_21865;
    v_22081 = nil;
v_21865:
    if (v_22081 == nil) goto v_21863;
    goto v_21881;
v_21877:
    v_22081 = stack[-1];
    v_22082 = qcdr(v_22081);
    goto v_21878;
v_21879:
    v_22081 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21880;
v_21881:
    goto v_21877;
v_21878:
    goto v_21879;
v_21880:
    v_22081 = (v_22082 == v_22081 ? lisp_true : nil);
    goto v_21861;
v_21863:
    v_22081 = nil;
    goto v_21861;
    v_22081 = nil;
v_21861:
    goto v_21849;
v_21851:
    v_22081 = nil;
    goto v_21849;
    v_22081 = nil;
v_21849:
    goto v_21844;
v_21846:
    v_22081 = nil;
    goto v_21844;
    v_22081 = nil;
v_21844:
    if (v_22081 == nil) goto v_21842;
    v_22081 = stack[-1];
    v_22081 = qcar(v_22081);
    if (!consp(v_22081)) goto v_21901;
    else goto v_21902;
v_21901:
    goto v_21910;
v_21906:
    v_22082 = stack[-2];
    goto v_21907;
v_21908:
    v_22081 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21909;
v_21910:
    goto v_21906;
v_21907:
    goto v_21908;
v_21909:
    v_22081 = (LispObject)greaterp2(v_22082, v_22081);
    v_22081 = v_22081 ? lisp_true : nil;
    env = stack[-8];
    goto v_21900;
v_21902:
    v_22081 = nil;
    goto v_21900;
    v_22081 = nil;
v_21900:
    if (v_22081 == nil) goto v_21898;
    goto v_21922;
v_21918:
    v_22081 = stack[-1];
    v_22082 = qcar(v_22081);
    goto v_21919;
v_21920:
    v_22081 = stack[-2];
    goto v_21921;
v_21922:
    goto v_21918;
v_21919:
    goto v_21920;
v_21921:
    v_22081 = Lexpt(nil, v_22082, v_22081);
    env = stack[-8];
    fn = elt(env, 16); // !*d2q
    v_22081 = (*qfn1(fn))(fn, v_22081);
    goto v_21896;
v_21898:
    goto v_21933;
v_21929:
    goto v_21939;
v_21935:
    v_22081 = stack[-1];
    v_22082 = qcar(v_22081);
    goto v_21936;
v_21937:
    v_22081 = stack[-2];
    goto v_21938;
v_21939:
    goto v_21935;
v_21936:
    goto v_21937;
v_21938:
    fn = elt(env, 17); // !:expt
    v_22082 = (*qfn2(fn))(fn, v_22082, v_22081);
    env = stack[-8];
    goto v_21930;
v_21931:
    v_22081 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21932;
v_21933:
    goto v_21929;
v_21930:
    goto v_21931;
v_21932:
    v_22081 = cons(v_22082, v_22081);
    env = stack[-8];
    stack[-1] = v_22081;
    v_22081 = qvalue(elt(env, 8)); // !*mcd
    if (v_22081 == nil) goto v_21947;
    v_22081 = stack[-1];
    fn = elt(env, 18); // resimp
    v_22081 = (*qfn1(fn))(fn, v_22081);
    goto v_21945;
v_21947:
    v_22081 = stack[-1];
    goto v_21945;
    v_22081 = nil;
v_21945:
    goto v_21896;
    v_22081 = nil;
v_21896:
    goto v_21791;
v_21842:
    goto v_21961;
v_21957:
    stack[0] = elt(env, 9); // expt
    goto v_21958;
v_21959:
    goto v_21968;
v_21964:
    v_22082 = stack[-1];
    goto v_21965;
v_21966:
    v_22081 = stack[-5];
    goto v_21967;
v_21968:
    goto v_21964;
v_21965:
    goto v_21966;
v_21967:
    v_22081 = list2(v_22082, v_22081);
    env = stack[-8];
    goto v_21960;
v_21961:
    goto v_21957;
v_21958:
    goto v_21959;
v_21960:
    fn = elt(env, 19); // domainvalchk
    v_22081 = (*qfn2(fn))(fn, stack[0], v_22081);
    env = stack[-8];
    v_22082 = v_22081;
    if (v_22081 == nil) goto v_21955;
    v_22081 = v_22082;
    goto v_21791;
v_21955:
    v_22081 = stack[-2];
    if (!consp(v_22081)) goto v_21976;
    else goto v_21977;
v_21976:
    goto v_21983;
v_21979:
    v_22081 = stack[-5];
    v_22082 = qcdr(v_22081);
    goto v_21980;
v_21981:
    v_22081 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21982;
v_21983:
    goto v_21979;
v_21980:
    goto v_21981;
v_21982:
    v_22081 = (v_22082 == v_22081 ? lisp_true : nil);
    goto v_21975;
v_21977:
    v_22081 = nil;
    goto v_21975;
    v_22081 = nil;
v_21975:
    if (v_22081 == nil) goto v_21973;
    goto v_22000;
v_21996:
    v_22082 = stack[-2];
    goto v_21997;
v_21998:
    v_22081 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21999;
v_22000:
    goto v_21996;
v_21997:
    goto v_21998;
v_21999:
    v_22081 = (LispObject)lessp2(v_22082, v_22081);
    v_22081 = v_22081 ? lisp_true : nil;
    env = stack[-8];
    if (v_22081 == nil) goto v_21993;
    else goto v_21994;
v_21993:
    goto v_22008;
v_22004:
    v_22082 = stack[-1];
    goto v_22005;
v_22006:
    v_22081 = stack[-2];
    goto v_22007;
v_22008:
    goto v_22004;
v_22005:
    goto v_22006;
v_22007:
    fn = elt(env, 20); // exptsq
    v_22081 = (*qfn2(fn))(fn, v_22082, v_22081);
    goto v_21992;
v_21994:
    v_22081 = qvalue(elt(env, 8)); // !*mcd
    if (v_22081 == nil) goto v_22012;
    goto v_22020;
v_22016:
    stack[0] = stack[-1];
    goto v_22017;
v_22018:
    v_22081 = stack[-2];
    v_22081 = negate(v_22081);
    env = stack[-8];
    goto v_22019;
v_22020:
    goto v_22016;
v_22017:
    goto v_22018;
v_22019:
    fn = elt(env, 20); // exptsq
    v_22081 = (*qfn2(fn))(fn, stack[0], v_22081);
    env = stack[-8];
    fn = elt(env, 21); // invsq
    v_22081 = (*qfn1(fn))(fn, v_22081);
    goto v_21992;
v_22012:
    goto v_22031;
v_22027:
    goto v_22037;
v_22033:
    goto v_22043;
v_22039:
    v_22081 = stack[-1];
    v_22082 = qcar(v_22081);
    goto v_22040;
v_22041:
    v_22081 = stack[-2];
    goto v_22042;
v_22043:
    goto v_22039;
v_22040:
    goto v_22041;
v_22042:
    fn = elt(env, 22); // expf
    stack[0] = (*qfn2(fn))(fn, v_22082, v_22081);
    env = stack[-8];
    goto v_22034;
v_22035:
    goto v_22052;
v_22048:
    v_22081 = stack[-1];
    stack[-1] = qcdr(v_22081);
    goto v_22049;
v_22050:
    v_22081 = stack[-2];
    v_22081 = negate(v_22081);
    env = stack[-8];
    goto v_22051;
v_22052:
    goto v_22048;
v_22049:
    goto v_22050;
v_22051:
    fn = elt(env, 23); // mksfpf
    v_22081 = (*qfn2(fn))(fn, stack[-1], v_22081);
    env = stack[-8];
    goto v_22036;
v_22037:
    goto v_22033;
v_22034:
    goto v_22035;
v_22036:
    fn = elt(env, 24); // multf
    v_22082 = (*qfn2(fn))(fn, stack[0], v_22081);
    env = stack[-8];
    goto v_22028;
v_22029:
    v_22081 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22030;
v_22031:
    goto v_22027;
v_22028:
    goto v_22029;
v_22030:
    v_22081 = cons(v_22082, v_22081);
    goto v_21992;
    v_22081 = nil;
v_21992:
    goto v_21791;
v_21973:
    goto v_22067;
v_22061:
    v_22081 = stack[-4];
    if (v_22081 == nil) goto v_22071;
    v_22081 = stack[-6];
    v_22083 = v_22081;
    goto v_22069;
v_22071:
    v_22081 = stack[-1];
    fn = elt(env, 25); // subs2!*
    v_22081 = (*qfn1(fn))(fn, v_22081);
    env = stack[-8];
    fn = elt(env, 12); // prepsq!*
    v_22081 = (*qfn1(fn))(fn, v_22081);
    env = stack[-8];
    v_22083 = v_22081;
    goto v_22069;
    v_22083 = nil;
v_22069:
    goto v_22062;
v_22063:
    v_22082 = stack[-5];
    goto v_22064;
v_22065:
    v_22081 = lisp_true;
    goto v_22066;
v_22067:
    goto v_22061;
v_22062:
    goto v_22063;
v_22064:
    goto v_22065;
v_22066:
    fn = elt(env, 13); // simpexpt11
    v_22081 = (*qfnn(fn))(fn, 3, v_22083, v_22082, v_22081);
    goto v_21791;
    v_22081 = nil;
v_21791:
v_21541:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_22081);
}



// Code for dip_f2dip2

static LispObject CC_dip_f2dip2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21600, v_21601, v_21602, v_21603, v_21604, v_21605;
    LispObject fn;
    LispObject v_21535, v_21534, v_21533, v_21532, v_21531;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "dip_f2dip2");
    va_start(aa, nargs);
    v_21531 = va_arg(aa, LispObject);
    v_21532 = va_arg(aa, LispObject);
    v_21533 = va_arg(aa, LispObject);
    v_21534 = va_arg(aa, LispObject);
    v_21535 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_21535,v_21534,v_21533,v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_21531,v_21532,v_21533,v_21534,v_21535);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_21535;
    v_21602 = v_21534;
    v_21603 = v_21533;
    v_21604 = v_21532;
    v_21605 = v_21531;
// end of prologue
    goto v_21545;
v_21541:
    v_21601 = v_21605;
    goto v_21542;
v_21543:
    v_21600 = qvalue(elt(env, 1)); // dip_vars!*
    goto v_21544;
v_21545:
    goto v_21541;
v_21542:
    goto v_21543;
v_21544:
    v_21600 = Lmemq(nil, v_21601, v_21600);
    if (v_21600 == nil) goto v_21540;
    goto v_21556;
v_21550:
    stack[0] = v_21603;
    goto v_21551;
v_21552:
    goto v_21567;
v_21559:
    v_21601 = v_21602;
    goto v_21560;
v_21561:
    v_21602 = v_21605;
    goto v_21562;
v_21563:
    v_21603 = v_21604;
    goto v_21564;
v_21565:
    v_21600 = qvalue(elt(env, 1)); // dip_vars!*
    goto v_21566;
v_21567:
    goto v_21559;
v_21560:
    goto v_21561;
v_21562:
    goto v_21563;
v_21564:
    goto v_21565;
v_21566:
    fn = elt(env, 2); // ev_insert
    v_21601 = (*qfnn(fn))(fn, 4, v_21601, v_21602, v_21603, v_21600);
    env = stack[-3];
    goto v_21553;
v_21554:
    v_21600 = stack[-1];
    goto v_21555;
v_21556:
    goto v_21550;
v_21551:
    goto v_21552;
v_21553:
    goto v_21554;
v_21555:
    {
        LispObject v_21609 = stack[0];
        fn = elt(env, 3); // dip_f2dip1
        return (*qfnn(fn))(fn, 3, v_21609, v_21601, v_21600);
    }
v_21540:
    goto v_21582;
v_21576:
    stack[-2] = v_21603;
    goto v_21577;
v_21578:
    stack[0] = v_21602;
    goto v_21579;
v_21580:
    goto v_21590;
v_21586:
    goto v_21587;
v_21588:
    goto v_21597;
v_21593:
    v_21600 = v_21605;
    goto v_21594;
v_21595:
    v_21601 = v_21604;
    goto v_21596;
v_21597:
    goto v_21593;
v_21594:
    goto v_21595;
v_21596:
    fn = elt(env, 4); // bc_pmon
    v_21600 = (*qfn2(fn))(fn, v_21600, v_21601);
    env = stack[-3];
    goto v_21589;
v_21590:
    goto v_21586;
v_21587:
    goto v_21588;
v_21589:
    fn = elt(env, 5); // bc_prod
    v_21600 = (*qfn2(fn))(fn, stack[-1], v_21600);
    env = stack[-3];
    goto v_21581;
v_21582:
    goto v_21576;
v_21577:
    goto v_21578;
v_21579:
    goto v_21580;
v_21581:
    {
        LispObject v_21610 = stack[-2];
        LispObject v_21611 = stack[0];
        fn = elt(env, 3); // dip_f2dip1
        return (*qfnn(fn))(fn, 3, v_21610, v_21611, v_21600);
    }
    v_21600 = nil;
    return onevalue(v_21600);
}



// Code for sfto_b!:ordexp

static LispObject CC_sfto_bTordexp(LispObject env,
                         LispObject v_21531, LispObject v_21532)
{
    env = qenv(env);
    LispObject v_21574, v_21575;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21531,v_21532);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21532;
    stack[-1] = v_21531;
// end of prologue
v_21536:
    v_21574 = stack[-1];
    if (v_21574 == nil) goto v_21539;
    else goto v_21540;
v_21539:
    v_21574 = lisp_true;
    goto v_21535;
v_21540:
    goto v_21550;
v_21546:
    v_21574 = stack[-1];
    v_21575 = qcar(v_21574);
    goto v_21547;
v_21548:
    v_21574 = stack[0];
    v_21574 = qcar(v_21574);
    goto v_21549;
v_21550:
    goto v_21546;
v_21547:
    goto v_21548;
v_21549:
    v_21574 = (LispObject)greaterp2(v_21575, v_21574);
    v_21574 = v_21574 ? lisp_true : nil;
    env = stack[-2];
    if (v_21574 == nil) goto v_21544;
    v_21574 = lisp_true;
    goto v_21535;
v_21544:
    goto v_21562;
v_21558:
    v_21574 = stack[-1];
    v_21575 = qcar(v_21574);
    goto v_21559;
v_21560:
    v_21574 = stack[0];
    v_21574 = qcar(v_21574);
    goto v_21561;
v_21562:
    goto v_21558;
v_21559:
    goto v_21560;
v_21561:
    if (equal(v_21575, v_21574)) goto v_21556;
    else goto v_21557;
v_21556:
    v_21574 = stack[-1];
    v_21574 = qcdr(v_21574);
    stack[-1] = v_21574;
    v_21574 = stack[0];
    v_21574 = qcdr(v_21574);
    stack[0] = v_21574;
    goto v_21536;
v_21557:
    v_21574 = nil;
    goto v_21535;
    v_21574 = nil;
v_21535:
    return onevalue(v_21574);
}



// Code for minusrd

static LispObject CC_minusrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21560, v_21561, v_21562;
    LispObject fn;
    argcheck(nargs, 0, "minusrd");
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
    v_21560 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_21560;
    fn = elt(env, 1); // mathml
    v_21560 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_21561 = v_21560;
    if (v_21561 == nil) goto v_21540;
    else goto v_21541;
v_21540:
    v_21560 = stack[0];
    v_21560 = ncons(v_21560);
    stack[0] = v_21560;
    goto v_21539;
v_21541:
    goto v_21554;
v_21548:
    v_21562 = stack[0];
    goto v_21549;
v_21550:
    v_21561 = v_21560;
    goto v_21551;
v_21552:
    v_21560 = nil;
    goto v_21553;
v_21554:
    goto v_21548;
v_21549:
    goto v_21550;
v_21551:
    goto v_21552;
v_21553:
    v_21560 = list2star(v_21562, v_21561, v_21560);
    env = stack[-1];
    stack[0] = v_21560;
    fn = elt(env, 2); // lex
    v_21560 = (*qfnn(fn))(fn, 0);
    goto v_21539;
v_21539:
    v_21560 = stack[0];
    return onevalue(v_21560);
}



// Code for greatertype

static LispObject CC_greatertype(LispObject env,
                         LispObject v_21531, LispObject v_21532)
{
    env = qenv(env);
    LispObject v_21721, v_21722, v_21723;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21531,v_21532);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_21532;
    stack[-6] = v_21531;
// end of prologue
    stack[-4] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    goto v_21548;
v_21544:
    v_21721 = qvalue(elt(env, 1)); // optlang!*
    if (v_21721 == nil) goto v_21552;
    v_21721 = qvalue(elt(env, 1)); // optlang!*
    v_21722 = v_21721;
    goto v_21550;
v_21552:
    v_21721 = elt(env, 2); // fortran
    v_21722 = v_21721;
    goto v_21550;
    v_21722 = nil;
v_21550:
    goto v_21545;
v_21546:
    v_21721 = elt(env, 3); // conversion
    goto v_21547;
v_21548:
    goto v_21544;
v_21545:
    goto v_21546;
v_21547:
    v_21721 = get(v_21722, v_21721);
    env = stack[-8];
    fn = elt(env, 4); // eval
    v_21721 = (*qfn1(fn))(fn, v_21721);
    env = stack[-8];
    stack[-7] = v_21721;
    goto v_21567;
v_21563:
    v_21721 = stack[-7];
    v_21722 = qcar(v_21721);
    goto v_21564;
v_21565:
    v_21721 = stack[-5];
    goto v_21566;
v_21567:
    goto v_21563;
v_21564:
    goto v_21565;
v_21566:
    if (equal(v_21722, v_21721)) goto v_21561;
    else goto v_21562;
v_21561:
    v_21721 = lisp_true;
    stack[-1] = v_21721;
    goto v_21560;
v_21562:
    goto v_21578;
v_21574:
    v_21721 = stack[-7];
    v_21722 = qcar(v_21721);
    goto v_21575;
v_21576:
    v_21721 = stack[-6];
    goto v_21577;
v_21578:
    goto v_21574;
v_21575:
    goto v_21576;
v_21577:
    if (equal(v_21722, v_21721)) goto v_21572;
    else goto v_21573;
v_21572:
    v_21721 = nil;
    stack[-1] = v_21721;
    goto v_21560;
v_21573:
v_21587:
    v_21721 = stack[-7];
    v_21721 = qcdr(v_21721);
    stack[-7] = v_21721;
    if (v_21721 == nil) goto v_21590;
    v_21721 = stack[-4];
    if (v_21721 == nil) goto v_21595;
    else goto v_21590;
v_21595:
    goto v_21591;
v_21590:
    goto v_21586;
v_21591:
    v_21721 = stack[-7];
    v_21721 = qcar(v_21721);
    v_21723 = v_21721;
v_21602:
    v_21721 = v_21723;
    if (v_21721 == nil) goto v_21605;
    v_21721 = stack[-2];
    if (v_21721 == nil) goto v_21609;
    else goto v_21605;
v_21609:
    goto v_21606;
v_21605:
    goto v_21601;
v_21606:
    goto v_21620;
v_21616:
    v_21721 = v_21723;
    v_21722 = qcar(v_21721);
    goto v_21617;
v_21618:
    v_21721 = stack[-6];
    goto v_21619;
v_21620:
    goto v_21616;
v_21617:
    goto v_21618;
v_21619:
    if (equal(v_21722, v_21721)) goto v_21614;
    else goto v_21615;
v_21614:
    v_21721 = lisp_true;
    stack[-3] = v_21721;
    goto v_21613;
v_21615:
v_21613:
    goto v_21633;
v_21629:
    v_21721 = v_21723;
    v_21722 = qcar(v_21721);
    goto v_21630;
v_21631:
    v_21721 = stack[-5];
    goto v_21632;
v_21633:
    goto v_21629;
v_21630:
    goto v_21631;
v_21632:
    if (equal(v_21722, v_21721)) goto v_21627;
    else goto v_21628;
v_21627:
    v_21721 = lisp_true;
    stack[-2] = v_21721;
    goto v_21626;
v_21628:
    v_21721 = v_21723;
    v_21721 = qcdr(v_21721);
    v_21723 = v_21721;
    goto v_21626;
v_21626:
    goto v_21602;
v_21601:
    v_21721 = stack[-2];
    if (v_21721 == nil) goto v_21645;
    v_21721 = v_21723;
    v_21721 = qcdr(v_21721);
    v_21723 = v_21721;
v_21651:
    v_21721 = v_21723;
    if (v_21721 == nil) goto v_21654;
    v_21721 = stack[-1];
    if (v_21721 == nil) goto v_21658;
    else goto v_21654;
v_21658:
    goto v_21655;
v_21654:
    goto v_21650;
v_21655:
    goto v_21669;
v_21665:
    v_21721 = v_21723;
    v_21722 = qcar(v_21721);
    goto v_21666;
v_21667:
    v_21721 = stack[-6];
    goto v_21668;
v_21669:
    goto v_21665;
v_21666:
    goto v_21667;
v_21668:
    if (equal(v_21722, v_21721)) goto v_21663;
    else goto v_21664;
v_21663:
    v_21721 = lisp_true;
    stack[-1] = v_21721;
    stack[-3] = v_21721;
    goto v_21662;
v_21664:
    v_21721 = v_21723;
    v_21721 = qcdr(v_21721);
    v_21723 = v_21721;
    goto v_21662;
v_21662:
    goto v_21651;
v_21650:
    goto v_21643;
v_21645:
v_21643:
    v_21721 = stack[-3];
    if (v_21721 == nil) goto v_21683;
    v_21721 = stack[-2];
    if (v_21721 == nil) goto v_21686;
    else goto v_21683;
v_21686:
    goto v_21681;
v_21683:
    v_21721 = stack[-3];
    if (v_21721 == nil) goto v_21691;
    else goto v_21692;
v_21691:
    v_21721 = stack[-2];
    goto v_21690;
v_21692:
    v_21721 = nil;
    goto v_21690;
    v_21721 = nil;
v_21690:
    if (v_21721 == nil) goto v_21688;
    else goto v_21681;
v_21688:
    goto v_21682;
v_21681:
    goto v_21703;
v_21699:
    stack[0] = (LispObject)64+TAG_FIXNUM; // 4
    goto v_21700;
v_21701:
    goto v_21710;
v_21706:
    v_21722 = stack[-6];
    goto v_21707;
v_21708:
    v_21721 = stack[-5];
    goto v_21709;
v_21710:
    goto v_21706;
v_21707:
    goto v_21708;
v_21709:
    v_21721 = cons(v_21722, v_21721);
    env = stack[-8];
    goto v_21702;
v_21703:
    goto v_21699;
v_21700:
    goto v_21701;
v_21702:
    fn = elt(env, 5); // typerror
    v_21721 = (*qfn2(fn))(fn, stack[0], v_21721);
    env = stack[-8];
    goto v_21680;
v_21682:
    v_21721 = stack[-3];
    if (v_21721 == nil) goto v_21714;
    v_21721 = stack[-2];
    if (v_21721 == nil) goto v_21714;
    v_21721 = lisp_true;
    stack[-4] = v_21721;
    goto v_21680;
v_21714:
v_21680:
    goto v_21587;
v_21586:
    goto v_21560;
v_21560:
    v_21721 = stack[-1];
    return onevalue(v_21721);
}



// Code for divide!-by!-power!-of!-ten

static LispObject CC_divideKbyKpowerKofKten(LispObject env,
                         LispObject v_21531, LispObject v_21532)
{
    env = qenv(env);
    LispObject v_21611, v_21612, v_21613;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21531,v_21532);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21532;
    stack[-1] = v_21531;
// end of prologue
    goto v_21543;
v_21539:
    v_21612 = stack[0];
    goto v_21540;
v_21541:
    v_21611 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21542;
v_21543:
    goto v_21539;
v_21540:
    goto v_21541;
v_21542:
    v_21611 = (LispObject)lessp2(v_21612, v_21611);
    v_21611 = v_21611 ? lisp_true : nil;
    env = stack[-3];
    if (v_21611 == nil) goto v_21537;
    v_21611 = elt(env, 0); // divide!-by!-power!-of!-ten
    {
        fn = elt(env, 3); // bflerrmsg
        return (*qfn1(fn))(fn, v_21611);
    }
v_21537:
    v_21611 = qvalue(elt(env, 1)); // bften!*
    stack[-2] = v_21611;
v_21554:
    goto v_21564;
v_21560:
    v_21612 = stack[0];
    goto v_21561;
v_21562:
    v_21611 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21563;
v_21564:
    goto v_21560;
v_21561:
    goto v_21562;
v_21563:
    v_21611 = (LispObject)greaterp2(v_21612, v_21611);
    v_21611 = v_21611 ? lisp_true : nil;
    env = stack[-3];
    if (v_21611 == nil) goto v_21557;
    else goto v_21558;
v_21557:
    goto v_21553;
v_21558:
    v_21611 = stack[0];
    v_21611 = Levenp(nil, v_21611);
    env = stack[-3];
    if (v_21611 == nil) goto v_21570;
    else goto v_21571;
v_21570:
    goto v_21582;
v_21576:
    v_21613 = stack[-1];
    goto v_21577;
v_21578:
    v_21612 = stack[-2];
    goto v_21579;
v_21580:
    v_21611 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_21581;
v_21582:
    goto v_21576;
v_21577:
    goto v_21578;
v_21579:
    goto v_21580;
v_21581:
    fn = elt(env, 4); // divide!:
    v_21611 = (*qfnn(fn))(fn, 3, v_21613, v_21612, v_21611);
    env = stack[-3];
    fn = elt(env, 5); // normbf
    v_21611 = (*qfn1(fn))(fn, v_21611);
    env = stack[-3];
    stack[-1] = v_21611;
    goto v_21569;
v_21571:
v_21569:
    goto v_21591;
v_21587:
    v_21612 = stack[0];
    goto v_21588;
v_21589:
    v_21611 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_21590;
v_21591:
    goto v_21587;
v_21588:
    goto v_21589;
v_21590:
    fn = elt(env, 6); // lshift
    v_21611 = (*qfn2(fn))(fn, v_21612, v_21611);
    env = stack[-3];
    stack[0] = v_21611;
    goto v_21600;
v_21596:
    goto v_21606;
v_21602:
    v_21612 = stack[-2];
    goto v_21603;
v_21604:
    v_21611 = stack[-2];
    goto v_21605;
v_21606:
    goto v_21602;
v_21603:
    goto v_21604;
v_21605:
    fn = elt(env, 7); // times!:
    v_21612 = (*qfn2(fn))(fn, v_21612, v_21611);
    env = stack[-3];
    goto v_21597;
v_21598:
    v_21611 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_21599;
v_21600:
    goto v_21596;
v_21597:
    goto v_21598;
v_21599:
    fn = elt(env, 8); // cut!:mt
    v_21611 = (*qfn2(fn))(fn, v_21612, v_21611);
    env = stack[-3];
    fn = elt(env, 5); // normbf
    v_21611 = (*qfn1(fn))(fn, v_21611);
    env = stack[-3];
    stack[-2] = v_21611;
    goto v_21554;
v_21553:
    v_21611 = stack[-1];
    goto v_21535;
    v_21611 = nil;
v_21535:
    return onevalue(v_21611);
}



// Code for calc_den_tar

static LispObject CC_calc_den_tar(LispObject env,
                         LispObject v_21531, LispObject v_21532)
{
    env = qenv(env);
    LispObject v_21559, v_21560;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21532,v_21531);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21531,v_21532);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21559 = v_21532;
    v_21560 = v_21531;
// end of prologue
    goto v_21539;
v_21535:
    goto v_21536;
v_21537:
    goto v_21538;
v_21539:
    goto v_21535;
v_21536:
    goto v_21537;
v_21538:
    fn = elt(env, 1); // denlist
    v_21559 = (*qfn2(fn))(fn, v_21560, v_21559);
    env = stack[0];
    v_21560 = v_21559;
    v_21559 = v_21560;
    if (v_21559 == nil) goto v_21545;
    else goto v_21546;
v_21545:
    v_21559 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21544;
v_21546:
    v_21559 = v_21560;
    v_21559 = qcdr(v_21559);
    if (v_21559 == nil) goto v_21549;
    else goto v_21550;
v_21549:
    v_21559 = v_21560;
    v_21559 = qcar(v_21559);
    goto v_21544;
v_21550:
    v_21559 = v_21560;
    {
        fn = elt(env, 2); // constimes
        return (*qfn1(fn))(fn, v_21559);
    }
    v_21559 = nil;
v_21544:
    return onevalue(v_21559);
}



setup_type const u38_setup[] =
{
    {"rootextractf",            CC_rootextractf,TOO_MANY_1,    WRONG_NO_1},
    {"ratlessp",                TOO_FEW_2,      CC_ratlessp,   WRONG_NO_2},
    {"make-image",              TOO_FEW_2,      CC_makeKimage, WRONG_NO_2},
    {"settcollectnonmultiprolongations",CC_settcollectnonmultiprolongations,TOO_MANY_1,WRONG_NO_1},
    {"valuecoefft",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_valuecoefft},
    {"internal-factorf",        CC_internalKfactorf,TOO_MANY_1,WRONG_NO_1},
    {"ioto_smaprinbuf",         CC_ioto_smaprinbuf,TOO_MANY_1, WRONG_NO_1},
    {"containerom",             CC_containerom, TOO_MANY_1,    WRONG_NO_1},
    {"rewrite",                 CC_rewrite,     TOO_MANY_1,    WRONG_NO_1},
    {"evalnumberp",             CC_evalnumberp, TOO_MANY_1,    WRONG_NO_1},
    {"contposp",                CC_contposp,    TOO_MANY_1,    WRONG_NO_1},
    {"gbfplus",                 TOO_FEW_2,      CC_gbfplus,    WRONG_NO_2},
    {"diff_vertex",             TOO_FEW_2,      CC_diff_vertex,WRONG_NO_2},
    {"assert_kernelp",          CC_assert_kernelp,TOO_MANY_1,  WRONG_NO_1},
    {"dp_from_ei",              CC_dp_from_ei,  TOO_MANY_1,    WRONG_NO_1},
    {"getavalue",               CC_getavalue,   TOO_MANY_1,    WRONG_NO_1},
    {"msolve-psys1",            TOO_FEW_2,      CC_msolveKpsys1,WRONG_NO_2},
    {"ra_u",                    CC_ra_u,        TOO_MANY_1,    WRONG_NO_1},
    {"lastcar",                 CC_lastcar,     TOO_MANY_1,    WRONG_NO_1},
    {"rl_qefsolset",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rl_qefsolset},
    {"rl_bnfsimpl",             TOO_FEW_2,      CC_rl_bnfsimpl,WRONG_NO_2},
    {"setfuncsnaryrd",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setfuncsnaryrd},
    {"groebinvokecritm",        TOO_FEW_2,      CC_groebinvokecritm,WRONG_NO_2},
    {"intrdsortin",             TOO_FEW_2,      CC_intrdsortin,WRONG_NO_2},
    {"z-roads",                 CC_zKroads,     TOO_MANY_1,    WRONG_NO_1},
    {"listeval0",               CC_listeval0,   TOO_MANY_1,    WRONG_NO_1},
    {"lalr_expand_grammar",     CC_lalr_expand_grammar,TOO_MANY_1,WRONG_NO_1},
    {"ofsf_sippsubst1",         TOO_FEW_2,      CC_ofsf_sippsubst1,WRONG_NO_2},
    {"janettreenodebuild",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_janettreenodebuild},
    {"testord",                 TOO_FEW_2,      CC_testord,    WRONG_NO_2},
    {"mk+outer+list",           CC_mkLouterLlist,TOO_MANY_1,   WRONG_NO_1},
    {"mri_opn",                 CC_mri_opn,     TOO_MANY_1,    WRONG_NO_1},
    {"repr_n",                  CC_repr_n,      TOO_MANY_1,    WRONG_NO_1},
    {"rl_surep",                TOO_FEW_2,      CC_rl_surep,   WRONG_NO_2},
    {"vdpcleanup",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vdpcleanup},
    {"bflessp",                 TOO_FEW_2,      CC_bflessp,    WRONG_NO_2},
    {"atom_compare",            TOO_FEW_2,      CC_atom_compare,WRONG_NO_2},
    {"makeqn-maybe",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_makeqnKmaybe},
    {"set_parser",              CC_set_parser,  TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_decdeg2",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_decdeg2},
    {"even_action_term",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_even_action_term},
    {"cl_atnum",                CC_cl_atnum,    TOO_MANY_1,    WRONG_NO_1},
    {"sq_member",               TOO_FEW_2,      CC_sq_member,  WRONG_NO_2},
    {"simpexpt1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_simpexpt1},
    {"dip_f2dip2",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dip_f2dip2},
    {"sfto_b:ordexp",           TOO_FEW_2,      CC_sfto_bTordexp,WRONG_NO_2},
    {"minusrd",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_minusrd},
    {"greatertype",             TOO_FEW_2,      CC_greatertype,WRONG_NO_2},
    {"divide-by-power-of-ten",  TOO_FEW_2,      CC_divideKbyKpowerKofKten,WRONG_NO_2},
    {"calc_den_tar",            TOO_FEW_2,      CC_calc_den_tar,WRONG_NO_2},
    {NULL, (one_args *)"u38", (two_args *)"82622 8561944 9963904", 0}
};

// end of generated code
