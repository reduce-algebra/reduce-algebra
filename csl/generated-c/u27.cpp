
// $destdir/u27.c        Machine generated C code

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
#undef PACKAGE
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef VERSION
#undef PACKAGE_VERSION
#undef PACKAGE_BUGREPORT
#undef PACKAGE_TARNAME
#undef PACKAGE_URL
#include <ffi.h>
#undef PACKAGE
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef VERSION
#undef PACKAGE_VERSION
#undef PACKAGE_BUGREPORT
#undef PACKAGE_TARNAME
#undef PACKAGE_URL
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
extern LispObject nil;
#define SIXTY_FOUR_BIT (sizeof(intptr_t) == 8)
static inline void CSL_IGNORE(LispObject x)
{ (void)x;
}
#ifndef PAGE_BITS
# define PAGE_BITS 23
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
typedef LispObject one_arg(LispObject, LispObject);
typedef LispObject two_args(LispObject, LispObject, LispObject);
typedef LispObject three_args(LispObject, LispObject, LispObject, LispObject);
typedef LispObject fourup_args(LispObject, LispObject, LispObject,
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
static inline bool vector_holds_binary(Header h)
{ return ((h) & (0x2<<Tw)) != 0;
}
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
static inline bool is_basic_vector(LispObject v)
{ return type_of_header(vechdr(v)) != TYPE_INDEXVEC;
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
static inline LispObject& basic_elt(LispObject v, size_t n)
{ return *(LispObject *)((char *)v +
 (CELL-TAG_VECTOR) +
 (n*sizeof(LispObject)));
}
static inline bool vector_i8(LispObject n)
{ if (is_basic_vector(n)) return vector_i8(vechdr(n));
 else return vector_i8(vechdr(basic_elt(n, 0)));
}
static inline bool vector_i16(LispObject n)
{ if (is_basic_vector(n)) return vector_i16(vechdr(n));
 else return vector_i16(vechdr(basic_elt(n, 0)));
}
static inline bool vector_i32(LispObject n)
{ if (is_basic_vector(n)) return vector_i32(vechdr(n));
 else return vector_i32(vechdr(basic_elt(n, 0)));
}
static inline bool vector_i64(LispObject n)
{ if (is_basic_vector(n)) return vector_i64(vechdr(n));
 else return vector_i64(vechdr(basic_elt(n, 0)));
}
static inline bool vector_i128(LispObject n)
{ if (is_basic_vector(n)) return vector_i128(vechdr(n));
 else return vector_i128(vechdr(basic_elt(n, 0)));
}
static inline bool vector_f32(LispObject n)
{ if (is_basic_vector(n)) return vector_f32(vechdr(n));
 else return vector_f32(vechdr(basic_elt(n, 0)));
}
static inline bool vector_f64(LispObject n)
{ if (is_basic_vector(n)) return vector_f64(vechdr(n));
 else return vector_f64(vechdr(basic_elt(n, 0)));
}
static inline bool vector_f128(LispObject n)
{ if (is_basic_vector(n)) return vector_f128(vechdr(n));
 else return vector_f128(vechdr(basic_elt(n, 0)));
}
#define TYPE_BIGNUMINDEX ( 0x1d <<Tw)
#define TYPE_BIGNUM ( 0x1f <<Tw)
#define TYPE_RATNUM ( 0x3d <<Tw)
#define TYPE_SINGLE_FLOAT ( 0x3f <<Tw)
#define TYPE_COMPLEX_NUM ( 0x5d <<Tw)
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
{ if (is_basic_vector(n)) return is_string_header(vechdr(n));
 else return is_string_header(vechdr(basic_elt(n, 0)));
}
static inline bool is_vec8_header(Header h)
{ return (type_of_header(h) & (0x1f<<Tw)) == TYPE_VEC8_1;
}
static inline bool is_vec8(LispObject n)
{ if (is_basic_vector(n)) return is_vec8_header(vechdr(n));
 else return is_vec8_header(vechdr(basic_elt(n, 0)));
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
{ if (is_basic_vector(n)) return is_vec16_header(vechdr(n));
 else return is_vec16_header(vechdr(basic_elt(n, 0)));
}
static inline bool is_bitvec_header(Header h)
{ return (type_of_header(h) & (0x03<<Tw)) == TYPE_BITVEC_1;
}
static inline bool is_bitvec(LispObject n)
{ if (is_basic_vector(n)) return is_bitvec_header(vechdr(n));
 else return is_bitvec_header(vechdr(basic_elt(n, 0)));
}
static inline char& basic_celt(LispObject v, size_t n)
{ return *((char *)(v) + (CELL-TAG_VECTOR) + n);
}
static inline unsigned char& basic_ucelt(LispObject v, size_t n)
{ return *((unsigned char *)v + (CELL-TAG_VECTOR) + n);
}
static inline signed char& basic_scelt(LispObject v, size_t n)
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
static inline int16_t& basic_helt(LispObject v, size_t n)
{ return *(int16_t *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(int16_t));
}
static inline intptr_t& basic_ielt(LispObject v, size_t n)
{ return *(intptr_t *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(intptr_t));
}
static inline int32_t& basic_ielt32(LispObject v, size_t n)
{ return *(int32_t *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(int32_t));
}
static inline float& basic_felt(LispObject v, size_t n)
{ return *(float *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(float));
}
static inline double& basic_delt(LispObject v, size_t n)
{ return *(double *)((char *)v +
 (8-TAG_VECTOR) +
 n*sizeof(double));
}
#define LOG2_VECTOR_CHUNK_BYTES (PAGE_BITS-2)
#define VECTOR_CHUNK_BYTES ((size_t)(((size_t)1)<<LOG2_VECTOR_CHUNK_BYTES))
static inline bool is_power_of_two(uint64_t n)
{ return (n == (n & (-n)));
}
static inline int intlog2(uint64_t n)
{
 static const unsigned char intlog2_table[] =
 {
 0, 0, 1, 39, 2, 15, 40, 23,
 3, 12, 16, 59, 41, 19, 24, 54,
 4,0, 13, 10, 17, 62, 60, 28,
 42, 30, 20, 51, 25, 44, 55, 47,
 5,32, 0, 38, 14, 22, 11, 58,
 18, 53, 63, 9, 61, 27, 29, 50,
 43, 46, 31, 37, 21, 57, 52, 8,
 26, 49, 45, 36, 56, 7, 48, 35,
 6,34, 33
 };
 return intlog2_table[n % (sizeof(intlog2_table)/sizeof(intlog2_table[0]))];
}
static inline int type_of_vector(LispObject v)
{ if (is_basic_vector(v)) return type_of_header(vechdr(v));
 else return type_of_header(vechdr(basic_elt(v, 0)));
}
static inline size_t bytes_in_bytevector(LispObject v)
{ if (is_basic_vector(v)) return length_of_byteheader(vechdr(v)) - CELL;
 size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
 return VECTOR_CHUNK_BYTES*(n-1) +
 length_of_byteheader(vechdr(basic_elt(v, n-1))) - CELL;
}
static inline size_t hwords_in_hwordvector(LispObject v)
{ if (is_basic_vector(v)) return length_of_hwordheader(vechdr(v)) - (CELL/2);
 size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
 return (VECTOR_CHUNK_BYTES/2)*(n-1) +
 length_of_hwordheader(vechdr(basic_elt(v, n-1))) - (CELL/2);
}
static inline size_t bits_in_bitvector(LispObject v)
{ if (is_basic_vector(v)) return length_of_bitheader(vechdr(v)) - 8*CELL;
 size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
 return (8*VECTOR_CHUNK_BYTES)*(n-1) +
 length_of_bitheader(vechdr(basic_elt(v, n-1))) - 8*CELL;
}
static inline size_t bytes_in_vector(LispObject v)
{ if (is_basic_vector(v)) return length_of_header(vechdr(v)) - CELL;
 size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
 return VECTOR_CHUNK_BYTES*(n-1) +
 length_of_header(vechdr(basic_elt(v, n-1))) - CELL;
}
static inline size_t cells_in_vector(LispObject v)
{ return bytes_in_vector(v)/CELL;
}
static inline bool vector_holds_binary(LispObject v)
{ if (is_basic_vector(v)) return vector_holds_binary(vechdr(v));
 else return vector_holds_binary(vechdr(basic_elt(v, 0)));
}
extern LispObject free_vectors[LOG2_VECTOR_CHUNK_BYTES+1];
static inline void discard_basic_vector(LispObject v)
{ size_t n = length_of_header(vechdr(v)) - CELL;
 if (is_power_of_two(n)) 
 { int i = intlog2(n); 
 if (i <= LOG2_VECTOR_CHUNK_BYTES)
 { basic_elt(v, 0) = free_vectors[i];
 vechdr(v) = TYPE_SIMPLE_VEC +
 ((n+CELL) << (Tw+5)) +
 TAG_HDR_IMMED;
 v = (v & ~(uintptr_t)TAG_BITS) | TAG_VECTOR;
 free_vectors[i] = v;
 }
 }
}
static inline void discard_vector(LispObject v)
{ if (is_basic_vector(v)) discard_basic_vector(v);
 else
 { size_t n1 = length_of_header(vechdr(v))/CELL - 1;
 for (size_t i=0; i<n1; i++)
 discard_basic_vector(basic_elt(v, i));
 }
}
static inline LispObject& elt(LispObject v, size_t n)
{ if (is_basic_vector(v)) return basic_elt(v, n);
 return basic_elt(basic_elt(v, n/(VECTOR_CHUNK_BYTES/CELL)),
 n%(VECTOR_CHUNK_BYTES/CELL));
}
static inline char& celt(LispObject v, size_t n)
{ if (is_basic_vector(v)) return basic_celt(v, n);
 return basic_celt(basic_elt(v, n/VECTOR_CHUNK_BYTES),
 n%VECTOR_CHUNK_BYTES);
}
static inline unsigned char& ucelt(LispObject v, size_t n)
{ if (is_basic_vector(v)) return basic_ucelt(v, n);
 return basic_ucelt(basic_elt(v, n/VECTOR_CHUNK_BYTES),
 n%VECTOR_CHUNK_BYTES);
}
static inline signed char& scelt(LispObject v, size_t n)
{ if (is_basic_vector(v)) return basic_scelt(v, n);
 return basic_scelt(basic_elt(v, n/VECTOR_CHUNK_BYTES),
 n%VECTOR_CHUNK_BYTES);
}
static inline int16_t& helt(LispObject v, size_t n)
{ if (is_basic_vector(v)) return basic_helt(v, n);
 return basic_helt(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(int16_t))),
 n%(VECTOR_CHUNK_BYTES/sizeof(int16_t)));
}
static inline intptr_t& ielt(LispObject v, size_t n)
{ if (is_basic_vector(v)) return basic_ielt(v, n);
 return basic_ielt(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(intptr_t))),
 n%(VECTOR_CHUNK_BYTES/sizeof(intptr_t)));
}
static inline int32_t& ielt32(LispObject v, size_t n)
{ if (is_basic_vector(v)) return basic_ielt32(v, n);
 return basic_ielt32(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(int32_t))),
 n%(VECTOR_CHUNK_BYTES/sizeof(int32_t)));
}
static inline float& felt(LispObject v, size_t n)
{ if (is_basic_vector(v)) return basic_felt(v, n);
 return basic_felt(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(float))),
 n%(VECTOR_CHUNK_BYTES/sizeof(float)));
}
static inline double& delt(LispObject v, size_t n)
{ if (is_basic_vector(v)) return basic_delt(v, n);
 return basic_delt(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(double))),
 n%(VECTOR_CHUNK_BYTES/sizeof(double)));
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
 intptr_t function4up;
 uint64_t count; 
} Symbol_Head;
#ifdef FUTURE_IDEA
typedef struct Symbol_Head
{ Header header; 
 LispObject value; 
 LispObject plist; 
 LispObject fastgets; 
 LispObject pname; 
 LispObject package; 
 LispObject function; 
 uintptr_t count; 
} Symbol_Head;
typedef struct Function_Object
{ Header header; 
 LispObject env; 
 intptr_t function0; 
 intptr_t function1; 
 intptr_t function2; 
 intptr_t function3; 
 intptr_t function4up;
 uintptr_t count; 
} Function_Object;
typedef struct Bytecoded_Function_Object
{ Header header; 
 LispObject env; 
 intptr_t function0; 
 intptr_t function1; 
 intptr_t function2; 
 intptr_t function3; 
 intptr_t function4up;
 uintptr_t count; 
 unsigned char bytecodes[]; 
} Bytecoded_Function_Object;
#endif 
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
static inline intptr_t& ifn4up(LispObject p)
{ return *(intptr_t *)((char *)p + (11*CELL-TAG_SYMBOL));
}
static inline intptr_t& ifnunused(LispObject p)
{ return *(intptr_t *)((char *)p + (12*CELL-TAG_SYMBOL));
}
static inline intptr_t& ifnn(LispObject p)
{ return *(intptr_t *)((char *)p + (13*CELL-TAG_SYMBOL));
}
static inline no_args*& qfn0(LispObject p)
{ return *(no_args **)((char *)p + (7*CELL-TAG_SYMBOL));
}
static inline one_arg*& qfn1(LispObject p)
{ return *(one_arg **)((char *)p + (8*CELL-TAG_SYMBOL));
}
static inline two_args*& qfn2(LispObject p)
{ return *(two_args **)((char *)p + (9*CELL-TAG_SYMBOL));
}
static inline three_args*& qfn3(LispObject p)
{ return *(three_args **)((char *)p + (10*CELL-TAG_SYMBOL));
}
static inline fourup_args*& qfn4up(LispObject p)
{ return *(fourup_args **)((char *)p + (11*CELL-TAG_SYMBOL));
}
NORETURN extern void aerror1(const char *s, LispObject a);
static inline LispObject arg4(const char *name, LispObject a4up)
{ if (qcdr(a4up) != nil) aerror1(name, a4up); 
 return qcar(a4up);
}
static inline void a4a5(const char *name, LispObject a4up,
 LispObject& a4, LispObject& a5)
{ a4 = qcar(a4up);
 a4up = qcdr(a4up);
 if (a4up==nil || qcdr(a4up) != nil) aerror1(name, a4up); 
 a5 = qcar(a4up);
}
static inline void a4a5a6(const char *name, LispObject a4up,
 LispObject& a4, LispObject& a5, LispObject& a6)
{ a4 = qcar(a4up);
 a4up = qcdr(a4up);
 if (a4up == nil) aerror1(name, a4up); 
 a5 = qcar(a4up);
 a4up = qcdr(a4up);
 if (a4up==nil || qcdr(a4up) != nil) aerror1(name, a4up); 
 a6 = qcar(a4up);
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
extern LispObject interrupted(LispObject p);
NORETURN extern void error(int nargs, int code, ...);
NORETURN extern void cerror(int nargs, int code1, int code2, ...);
NORETURN extern void got_0_wanted_1(LispObject env);
NORETURN extern void got_0_wanted_2(LispObject env);
NORETURN extern void got_0_wanted_3(LispObject env);
NORETURN extern void got_0_wanted_4up(LispObject env);
NORETURN extern void got_0_wanted_other(LispObject env);
NORETURN extern void got_1_wanted_0(LispObject env, LispObject a1);
NORETURN extern void got_1_wanted_2(LispObject env, LispObject a1);
NORETURN extern void got_1_wanted_3(LispObject env, LispObject a1);
NORETURN extern void got_1_wanted_4up(LispObject env, LispObject a1);
NORETURN extern void got_1_wanted_other(LispObject env, LispObject a1);
NORETURN extern void got_2_wanted_0(LispObject env, LispObject a1,
 LispObject a2);
NORETURN extern void got_2_wanted_1(LispObject env, LispObject a1,
 LispObject a2);
NORETURN extern void got_2_wanted_3(LispObject env, LispObject a1,
 LispObject a2);
NORETURN extern void got_2_wanted_4up(LispObject env, LispObject a1,
 LispObject a2);
NORETURN extern void got_2_wanted_other(LispObject env, LispObject a1,
 LispObject a2);
NORETURN extern void got_3_wanted_0(LispObject env, LispObject a1,
 LispObject a2, LispObject a3);
NORETURN extern void got_3_wanted_1(LispObject env, LispObject a1,
 LispObject a2, LispObject a3);
NORETURN extern void got_3_wanted_2(LispObject env, LispObject a1,
 LispObject a2, LispObject a3);
NORETURN extern void got_3_wanted_4up(LispObject env, LispObject a1,
 LispObject a2, LispObject a3);
NORETURN extern void got_3_wanted_other(LispObject env, LispObject a1,
 LispObject a2, LispObject a3);
NORETURN extern void got_4up_wanted_0(LispObject env, LispObject a1,
 LispObject a2, LispObject a3,
 LispObject a4up);
NORETURN extern void got_4up_wanted_1(LispObject env, LispObject a1,
 LispObject a2, LispObject a3,
 LispObject a4up);
NORETURN extern void got_4up_wanted_2(LispObject env, LispObject a1,
 LispObject a2, LispObject a3,
 LispObject a4up);
NORETURN extern void got_4up_wanted_3(LispObject env, LispObject a1,
 LispObject a2, LispObject a3,
 LispObject a4up);
NORETURN extern void got_4up_wanted_other(LispObject env, LispObject a1,
 LispObject a2, LispObject a3,
 LispObject a4up);
NORETURN extern void bad_specialfn_0(LispObject env);
NORETURN extern void bad_specialfn_2(LispObject env, LispObject, LispObject);
NORETURN extern void bad_specialfn_3(LispObject env, LispObject, LispObject, LispObject);
NORETURN extern void bad_specialfn_4up(LispObject env, LispObject, LispObject, LispObject, LispObject);
#define G0W1 ((no_args *)got_0_wanted_1)
#define G0W2 ((no_args *)got_0_wanted_2)
#define G0W3 ((no_args *)got_0_wanted_3)
#define G0W4up ((no_args *)got_0_wanted_4up)
#define G0Wother ((no_args *)got_0_wanted_other)
#define G1W0 ((one_arg *)got_1_wanted_0)
#define G1W2 ((one_arg *)got_1_wanted_2)
#define G1W3 ((one_arg *)got_1_wanted_3)
#define G1W4up ((one_arg *)got_1_wanted_4up)
#define G1Wother ((one_arg *)got_1_wanted_other)
#define G2W0 ((two_args *)got_2_wanted_0)
#define G2W1 ((two_args *)got_2_wanted_1)
#define G2W3 ((two_args *)got_2_wanted_3)
#define G2W4up ((two_args *)got_2_wanted_4up)
#define G2Wother ((two_args *)got_2_wanted_other)
#define G3W0 ((three_args *)got_3_wanted_0)
#define G3W1 ((three_args *)got_3_wanted_1)
#define G3W2 ((three_args *)got_3_wanted_2)
#define G3W4up ((three_args *)got_3_wanted_4up)
#define G3Wother ((three_args *)got_3_wanted_other)
#define G4W0 ((fourup_args *)got_4up_wanted_0)
#define G4W1 ((fourup_args *)got_4up_wanted_1)
#define G4W2 ((fourup_args *)got_4up_wanted_2)
#define G4W3 ((fourup_args *)got_4up_wanted_3)
#define G4Wother ((fourup_args *)got_4up_wanted_other)
#define BAD_SPECIAL_0 ((no_args *)bad_specialfn_0)
#define BAD_SPECIAL_2 ((two_args *)bad_specialfn_2)
#define BAD_SPECIAL_3 ((three_args *)bad_specialfn_3)
#define BAD_SPECIAL_4up ((fourup_args *)bad_specialfn_4up)
NORETURN extern void aerror(const char *s); 
NORETURN extern void aerror0(const char *s);
NORETURN extern void aerror1(const char *s, LispObject a);
NORETURN extern void aerror2(const char *s, LispObject a, LispObject b);
NORETURN extern void aerror3(const char *s, LispObject a, LispObject b, LispObject c);
NORETURN extern void fatal_error(int code, ...);
extern LispObject carerror(LispObject a);
extern LispObject cdrerror(LispObject a);
NORETURN extern void car_fails(LispObject a);
NORETURN extern void cdr_fails(LispObject a);
NORETURN extern void rplaca_fails(LispObject a);
NORETURN extern void rplacd_fails(LispObject a);
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
#define err_undefined_function_4up 7 
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
 "undefined function (0 args)",
 "undefined function (1 arg)",
 "undefined function (2 args)",
 "undefined function (3 args)",
 "undefined function (4 or more args)",
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
NORETURN extern void my_abort();
template <typename F>
inline void my_assert(bool ok, F&& action)
{
#ifndef NDEBUG
 if (!ok) { action(); my_abort(); }
#endif 
}
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(const char *file, int line);
extern void show_stack();
static intline void if_check_stack()
{ if (check_stack("@" __FILE__,__LINE__))
 { show_stack();
 aerror("stack overflow");
 }
}
#else
static inline void if_check_stack()
{ const char *_p_ = (const char *)&_p_; \
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
extern LispObject list_symbol, liststar_symbol;
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
#define mv_4 workbase[4]
#define work_50 workbase[50]
extern void copy_into_nilseg();
extern void copy_out_of_nilseg();
extern void rehash_this_table(LispObject v);
extern void simple_print(LispObject x);
extern void simple_msg(const char *s, LispObject x);
extern LispObject eq_hash_tables;
extern uint64_t hash_equal(LispObject key);
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
extern bool force_verbos, force_echo, force_backtrace;
extern bool stop_on_error;
extern size_t number_of_input_files,
 number_of_symbols_to_define,
 number_of_fasl_paths;
extern int init_flags;
extern const char *standard_directory;
extern int64_t gc_number;
extern int64_t reclaim_trap_count;
extern uintptr_t reclaim_stack_limit;
extern bool next_gc_is_hard;
extern uint64_t reclaim_trigger_count, reclaim_trigger_target;
extern int deal_with_tick();
extern LispObject reclaim(LispObject value_to_return, const char *why,
 int stg_class, intptr_t size);
static inline void stackcheck0() 
{ if_check_stack(); 
 if (++reclaim_trigger_count == reclaim_trigger_target ||
 (--countdown < 0 && deal_with_tick()) || 
 stack >= stacklimit) 
 { reclaim(nil, "stack", GC_STACK, 0); 
 }
}
static inline void stackcheck1(LispObject& a1) 
{ if_check_stack(); 
 if (++reclaim_trigger_count == reclaim_trigger_target ||
 (--countdown < 0 && deal_with_tick()) || 
 stack >= stacklimit)
 { a1 = reclaim(a1, "stack", GC_STACK, 0); 
 }
}
static inline void stackcheck2(LispObject& a1, LispObject& a2) 
{ if_check_stack(); 
 if (++reclaim_trigger_count == reclaim_trigger_target ||
 (--countdown < 0 && deal_with_tick()) || 
 stack >= stacklimit)
 { push(a2); 
 a1 = reclaim(a1, "stack", GC_STACK, 0);
 pop(a2); 
 }
}
static inline void stackcheck3(LispObject& a1, LispObject& a2, LispObject& a3) 
{ if_check_stack(); 
 if (++reclaim_trigger_count == reclaim_trigger_target ||
 (--countdown < 0 && deal_with_tick()) || 
 stack >= stacklimit)
 { push2(a2, a3); 
 a1 = reclaim(a1, "stack", GC_STACK, 0); 
 pop2(a3, a2); 
 }
}
static inline void stackcheck4(LispObject& a1, LispObject& a2, LispObject& a3, LispObject& a4) 
{ if_check_stack(); 
 if (++reclaim_trigger_count == reclaim_trigger_target ||
 (--countdown < 0 && deal_with_tick()) || 
 stack >= stacklimit)
 { push3(a2, a3, a4); 
 a1 = reclaim(a1, "stack", GC_STACK, 0); 
 pop3(a4, a3, a2); 
 }
}
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
{ one_arg *p;
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
typedef struct _entry_point4up
{ fourup_args *p;
 const char *s;
} entry_point4up;
extern entry_point0 entries_table0[];
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_point3 entries_table3[];
extern entry_point4up entries_table4up[];
extern entry_point1 entries_tableio[];
extern const char *linker_type;
extern const char *compiler_command[], *import_data[],
 *config_header[], *csl_headers[];
extern LispObject encapsulate_pointer(void *);
extern void *extract_pointer(LispObject a);
extern LispObject Lencapsulatedp(LispObject env, LispObject a);
typedef void initfn(LispObject *, LispObject **, LispObject * volatile *);
extern LispObject characterify(LispObject a);
extern LispObject char_to_id(int ch);
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
extern const char *CSLtmpnam(const char *suffix, size_t suffixlen);
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
NORETURN extern void my_exit(int n);
extern void *my_malloc(size_t n);
extern void check_heap_segments();
extern clock_t base_time;
extern double *clock_stack;
extern void push_clock();
extern double pop_clock();
extern double consolidated_time[10], gc_time;
extern bool volatile already_in_gc, tick_on_gc_exit;
extern bool volatile interrupt_pending, tick_pending;
extern bool trap_floating_overflow;
extern const volatile char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(LispObject *, bool findcatch);
extern bool segvtrap;
extern bool batch_flag;
extern int escaped_printing;
extern void low_level_signal_handler(int code);
extern void sigint_handler(int code);
extern int async_interrupt(int a);
extern void record_get(LispObject tag, bool found);
extern bool isprime(uint64_t);
extern void set_up_functions(int restartp);
extern void get_user_files_checksum(unsigned char *);
extern LispObject acons(LispObject a, LispObject b, LispObject c);
extern LispObject ash(LispObject a, LispObject b);
extern LispObject bytestream_interpret(size_t ppc, LispObject lit,
 LispObject *entry_stack);
extern bool complex_stringp(LispObject a);
extern LispObject copy_string(LispObject a, size_t n);
extern void freshline_trace();
extern void freshline_debug();
extern LispObject cons(LispObject a, LispObject b);
extern LispObject cons_no_gc(LispObject a, LispObject b);
extern LispObject cons_gc_test(LispObject a);
extern void convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern LispObject eval(LispObject u, LispObject env);
extern uint32_t Crand();
extern LispObject Cremainder(LispObject a, LispObject b);
extern void Csrand(uint32_t a, uint32_t b);
extern void discard(LispObject a);
extern bool eql_fn(LispObject a, LispObject b);
extern bool cl_equal_fn(LispObject a, LispObject b);
extern bool equal_fn(LispObject a, LispObject b);
#ifdef TRACED_EQUAL
extern bool traced_equal_fn(LispObject a, LispObject b,
 const char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern bool equalp(LispObject a, LispObject b);
extern LispObject apply(LispObject fn, LispObject args, LispObject env,
 LispObject from);
extern LispObject apply_lambda(LispObject def, LispObject args,
 LispObject env, LispObject name);
extern void deallocate_pages();
extern void drop_heap_segments();
extern LispObject gcd(LispObject a, LispObject b);
extern LispObject get_pname(LispObject a);
extern LispObject get(LispObject a, LispObject b, LispObject c=nil);
extern LispObject get_basic_vector(int tag, int type, size_t length);
extern LispObject get_basic_vector_init(size_t n, LispObject v);
extern LispObject get_vector(int tag, int type, size_t length);
extern LispObject get_vector_init(size_t n, LispObject v);
extern uint64_t hash_lisp_string(LispObject s);
extern void lose_C_def(LispObject a);
extern bool geq2(LispObject a, LispObject b);
extern bool greaterp2(LispObject a, LispObject b);
extern bool lesseq2(LispObject a, LispObject b);
extern bool lessp2(LispObject a, LispObject b);
extern LispObject list2(LispObject a, LispObject b);
extern LispObject list2star(LispObject a, LispObject b, LispObject c);
extern LispObject list3(LispObject a, LispObject b, LispObject c);
extern LispObject list3star(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern LispObject list4(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern LispObject lognot(LispObject a);
extern LispObject macroexpand(LispObject form, LispObject env);
extern LispObject make_package(LispObject name);
extern LispObject make_string(const char *b);
extern LispObject make_nstring(const char *b, size_t n);
extern LispObject make_undefined_symbol(const char *s);
extern LispObject make_symbol(char const *s, int restartp,
 no_args *f0, one_arg *f1, two_args *f2,
 three_args *f3, fourup_args *f4up);
extern void stdout_printf(const char *fmt, ...);
extern void term_printf(const char *fmt, ...);
extern void err_printf(const char *fmt, ...);
extern void debug_printf(const char *fmt, ...);
extern void trace_printf(const char *fmt, ...);
extern const char *my_getenv(const char *name);
extern LispObject ncons(LispObject a);
extern LispObject ndelete(LispObject a, LispObject b);
extern LispObject negate(LispObject a);
extern LispObject nreverse(LispObject a);
extern LispObject nreverse2(LispObject a, LispObject b);
extern FILE *open_file(char *filename, const char *original_name,
 size_t n, const char *dirn, FILE *old_file);
extern LispObject plus2(LispObject a, LispObject b);
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
extern LispObject quot2(LispObject a, LispObject b);
extern LispObject quotrem2(LispObject a, LispObject b);
extern LispObject rational(LispObject a);
extern void read_eval_print(int noisy);
extern void set_fns(LispObject sym, no_args *f0, one_arg *f1,
 two_args *f2, three_args *f3, fourup_args *f4up);
extern void setup(int restartp, double storesize);
extern void set_up_variables(int restart_flag);
extern void warm_setup();
extern void write_everything();
extern LispObject simplify_string(LispObject s);
extern bool stringp(LispObject a);
extern LispObject times2(LispObject a, LispObject b);
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
extern no_args *no_arg_functions[];
extern one_arg *one_arg_functions[];
extern two_args *two_arg_functions[];
extern three_args *three_arg_functions[];
extern fourup_args *fourup_arg_functions[];
extern bool no_arg_traceflags[];
extern bool one_arg_traceflags[];
extern bool two_arg_traceflags[];
extern bool three_arg_traceflags[];
extern bool fourup_arg_traceflags[];
extern const char *no_arg_names[];
extern const char *one_arg_names[];
extern const char *two_arg_names[];
extern const char *three_arg_names[];
extern const char *fourup_arg_names[];
typedef struct setup_type
{ const char *name;
 no_args *zero;
 one_arg *one;
 two_args *two;
 three_args *three;
 fourup_args *fourup;
} setup_type;
typedef struct setup_type_1
{ const char *name;
 no_args *zero;
 one_arg *one;
 two_args *two;
 three_args *three;
 fourup_args *fourup;
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
extern LispObject negateb(LispObject);
extern LispObject copyb(LispObject);
extern LispObject negate(LispObject);
extern LispObject plus2(LispObject a, LispObject b);
extern LispObject difference2(LispObject a, LispObject b);
extern LispObject times2(LispObject a, LispObject b);
extern LispObject quot2(LispObject a, LispObject b);
extern LispObject CLquot2(LispObject a, LispObject b);
extern LispObject quotbn(LispObject a, int32_t n);
extern LispObject quotbn1(LispObject a, int32_t n);
#define QUOTBB_QUOTIENT_NEEDED 1
#define QUOTBB_REMAINDER_NEEDED 2
extern LispObject quotbb(LispObject a, LispObject b, int needs);
extern LispObject Cremainder(LispObject a, LispObject b);
extern LispObject rembi(LispObject a, LispObject b);
extern LispObject rembb(LispObject a, LispObject b);
extern LispObject shrink_bignum(LispObject a, size_t lena);
extern LispObject modulus(LispObject a, LispObject b);
extern LispObject rational(LispObject a);
extern LispObject rationalize(LispObject a);
extern LispObject lcm(LispObject a, LispObject b);
extern LispObject lengthen_by_one_bit(LispObject a, int32_t msd);
extern bool numeq2(LispObject a, LispObject b);
extern bool zerop(LispObject a);
extern bool onep(LispObject a);
extern bool minusp(LispObject a);
extern bool plusp(LispObject a);
extern LispObject integer_decode_long_float(LispObject a);
extern LispObject Linteger_decode_float(LispObject env, LispObject a);
extern LispObject validate_number(const char *s, LispObject a,
 LispObject b, LispObject c);
extern LispObject make_fake_bignum(intptr_t n);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_two_word_bignum(int32_t a, uint32_t b);
extern LispObject make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern LispObject make_four_word_bignum(int32_t a, uint32_t b,
 uint32_t c, uint32_t d);
extern LispObject make_five_word_bignum(int32_t a, uint32_t b,
 uint32_t c, uint32_t d, uint32_t e);
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
extern LispObject add1(LispObject p);
extern LispObject sub1(LispObject p);
extern LispObject integerp(LispObject p);
extern double float_of_number(LispObject a);
extern float128_t float128_of_number(LispObject a);
extern LispObject make_complex(LispObject r, LispObject i);
extern LispObject make_ratio(LispObject p, LispObject q);
extern LispObject make_approx_ratio(LispObject p, LispObject q, int bits);
extern LispObject ash(LispObject a, LispObject b);
extern LispObject lognot(LispObject a);
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
extern void f128M_ldexp(float128_t *p, int n);
extern void f128M_frexp(float128_t *p, float128_t *r, int *x);
static bool f128M_infinite(const float128_t *p);
static bool f128M_finite(const float128_t *p);
static bool f128M_nan(const float128_t *x);
static bool f128M_subnorm(const float128_t *x);
static bool f128M_negative(const float128_t *x);
static void f128M_negate(float128_t *x);
extern void f128M_split(
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
extern float128_t f128_0, 
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
extern void f256M_add(
 const float256_t *x, const float256_t *y, float256_t *z);
extern void f256M_mul(
 const float256_t *x, const float256_t *y, float256_t *z);
extern void f256M_pow(const float256_t *x, unsigned int y, float256_t *z);
extern float256_t f256_1, f256_10, f256_r10, f256_5, f256_r5;
extern int f128M_sprint_E(char *s, int width, int precision, float128_t *p);
extern int f128M_sprint_F(char *s, int width, int precision, float128_t *p);
extern int f128M_sprint_G(char *s, int width, int precision, float128_t *p);
extern int f128M_print_E(int width, int precision, float128_t *p);
extern int f128M_print_F(int width, int precision, float128_t *p);
extern int f128M_print_G(int width, int precision, float128_t *p);
extern float128_t atof128(const char *s);
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
extern LispObject Lbatchp(LispObject env);
extern LispObject Ldate(LispObject env);
extern LispObject Ldatestamp(LispObject env);
extern LispObject Leject(LispObject env);
NORETURN extern void Lerror_0(LispObject env);
extern LispObject Lall_symbols0(LispObject env);
extern LispObject Lflush(LispObject env);
extern LispObject Lgc0(LispObject env);
extern LispObject Lgctime(LispObject env);
extern LispObject Lgensym(LispObject env);
extern LispObject Llist_modules(LispObject env);
extern LispObject Llibrary_members0(LispObject env);
extern LispObject Lload_source0(LispObject env);
extern LispObject Lload_selected_source0(LispObject env);
extern LispObject Lload_spid(LispObject);
extern LispObject Llposn(LispObject env);
extern LispObject Lmapstore0(LispObject env);
extern LispObject Lnext_random(LispObject env);
extern LispObject Lnilfn(LispObject env);
extern LispObject Lposn(LispObject env);
extern LispObject Lread(LispObject env);
extern LispObject Lreadch(LispObject env);
extern LispObject Lrtell(LispObject env);
extern LispObject Lterpri(LispObject env);
extern LispObject Ltime(LispObject env);
extern LispObject Ltmpnam(LispObject env);
extern LispObject Ltyi(LispObject env);
extern LispObject Lunserialize(LispObject env);
extern LispObject autoload_0(LispObject env);
extern LispObject bytecoded_0(LispObject env);
extern LispObject Lbytecounts_0(LispObject env);
extern LispObject byteopt_0(LispObject def);
extern LispObject byteoptrest_0(LispObject def);
extern LispObject funarged_0(LispObject env);
extern LispObject tracefunarged_0(LispObject env);
extern LispObject hardopt_0(LispObject def);
extern LispObject hardoptrest_0(LispObject def);
extern LispObject interpreted_0(LispObject env);
extern LispObject tracebytecoded_0(LispObject env);
extern LispObject tracebyteopt_0(LispObject def);
extern LispObject tracebyteoptrest_0(LispObject def);
extern LispObject tracebytecoded_0(LispObject env);
extern LispObject traceinterpreted_0(LispObject env);
extern LispObject tracehardopt_0(LispObject def);
extern LispObject tracehardoptrest_0(LispObject def);
extern LispObject undefined_0(LispObject env);
extern LispObject f0_as_0(LispObject env);
extern LispObject autoload_1(LispObject env, LispObject a);
extern LispObject bytecoded_1(LispObject env, LispObject a);
extern LispObject Lbytecounts_1(LispObject env, LispObject a);
extern LispObject byteopt_1(LispObject def, LispObject a);
extern LispObject byteoptrest_1(LispObject def, LispObject a);
extern LispObject funarged_1(LispObject env, LispObject a1);
extern LispObject tracefunarged_1(LispObject env, LispObject a1);
extern LispObject hardopt_1(LispObject def, LispObject a);
extern LispObject hardoptrest_1(LispObject def, LispObject a);
extern LispObject interpreted_1(LispObject env, LispObject a1);
extern LispObject tracebytecoded_1(LispObject env, LispObject a);
extern LispObject tracebyteopt_1(LispObject def, LispObject a);
extern LispObject tracebyteoptrest_1(LispObject def, LispObject a);
extern LispObject tracebytecoded_1(LispObject env, LispObject a);
extern LispObject traceinterpreted_1(LispObject env, LispObject a1);
extern LispObject tracehardopt_1(LispObject def, LispObject a);
extern LispObject tracehardoptrest_1(LispObject def, LispObject a);
extern LispObject undefined_1(LispObject env, LispObject a1);
extern LispObject f1_as_0(LispObject env, LispObject a);
extern LispObject f1_as_1(LispObject env, LispObject a);
extern LispObject Labsval(LispObject env, LispObject a);
extern LispObject Ladd1(LispObject env, LispObject a);
extern LispObject Lalpha_char_p(LispObject env, LispObject a);
extern LispObject Lall_symbols(LispObject env, LispObject a1);
extern LispObject Lapply0(LispObject env, LispObject a);
extern LispObject Lapply_1(LispObject env, LispObject fn);
extern LispObject Latan(LispObject env, LispObject a);
extern LispObject Latom(LispObject env, LispObject a);
extern LispObject Lbanner(LispObject env, LispObject a);
extern LispObject Lboundp(LispObject env, LispObject a);
extern LispObject Lbpsp(LispObject env, LispObject a);
extern LispObject Lbpsupbv(LispObject env, LispObject v);
extern LispObject Lcaaaar(LispObject env, LispObject a);
extern LispObject Lcaaadr(LispObject env, LispObject a);
extern LispObject Lcaaar(LispObject env, LispObject a);
extern LispObject Lcaadar(LispObject env, LispObject a);
extern LispObject Lcaaddr(LispObject env, LispObject a);
extern LispObject Lcaadr(LispObject env, LispObject a);
extern LispObject Lcaar(LispObject env, LispObject a);
extern LispObject Lcaar(LispObject env, LispObject a);
extern LispObject Lcadaar(LispObject env, LispObject a);
extern LispObject Lcadadr(LispObject env, LispObject a);
extern LispObject Lcadar(LispObject env, LispObject a);
extern LispObject Lcaddar(LispObject env, LispObject a);
extern LispObject Lcadddr(LispObject env, LispObject a);
extern LispObject Lcaddr(LispObject env, LispObject a);
extern LispObject Lcadr(LispObject env, LispObject a);
extern LispObject Lcadr(LispObject env, LispObject a);
extern LispObject Lcar(LispObject env, LispObject a);
extern LispObject Lcar(LispObject env, LispObject a);
extern LispObject Lcdaaar(LispObject env, LispObject a);
extern LispObject Lcdaadr(LispObject env, LispObject a);
extern LispObject Lcdaar(LispObject env, LispObject a);
extern LispObject Lcdadar(LispObject env, LispObject a);
extern LispObject Lcdaddr(LispObject env, LispObject a);
extern LispObject Lcdadr(LispObject env, LispObject a);
extern LispObject Lcdar(LispObject env, LispObject a);
extern LispObject Lcdar(LispObject env, LispObject a);
extern LispObject Lcddaar(LispObject env, LispObject a);
extern LispObject Lcddadr(LispObject env, LispObject a);
extern LispObject Lcddar(LispObject env, LispObject a);
extern LispObject Lcdddar(LispObject env, LispObject a);
extern LispObject Lcddddr(LispObject env, LispObject a);
extern LispObject Lcdddr(LispObject env, LispObject a);
extern LispObject Lcddr(LispObject env, LispObject a);
extern LispObject Lcddr(LispObject env, LispObject a);
extern LispObject Lcdr(LispObject env, LispObject a);
extern LispObject Lcdr(LispObject env, LispObject a);
extern LispObject Lchar_code(LispObject env, LispObject a);
extern LispObject Lclose(LispObject env, LispObject a);
extern LispObject Lcodep(LispObject env, LispObject a);
extern LispObject Lcompress(LispObject env, LispObject a);
extern LispObject Lconsp(LispObject env, LispObject a);
extern LispObject Lconstantp(LispObject env, LispObject a);
extern LispObject Lcopy_module(LispObject env, LispObject a);
extern LispObject Ldefine_in_module(LispObject env, LispObject a);
extern LispObject Ldelete_module(LispObject env, LispObject a);
extern LispObject Ldigitp(LispObject env, LispObject a);
extern LispObject Lendp(LispObject env, LispObject a);
NORETURN extern void Lerror_1(LispObject env, LispObject a1);
extern LispObject Lerrorset_1(LispObject env, LispObject form);
extern LispObject Leval(LispObject env, LispObject a);
extern LispObject Levenp(LispObject env, LispObject a);
extern LispObject Levlis(LispObject env, LispObject a);
extern LispObject Lexplode(LispObject env, LispObject a);
extern LispObject Lexplode2lc(LispObject env, LispObject a);
extern LispObject Lexplode2lcn(LispObject env, LispObject a);
extern LispObject Lexplode2n(LispObject env, LispObject a);
extern LispObject Lexplodec(LispObject env, LispObject a);
extern LispObject Lexplodecn(LispObject env, LispObject a);
extern LispObject Lexplodehex(LispObject env, LispObject a);
extern LispObject Lexploden(LispObject env, LispObject a);
extern LispObject Lexplodeoctal(LispObject env, LispObject a);
extern LispObject Lfixp(LispObject env, LispObject a);
extern LispObject Lfloat(LispObject env, LispObject a);
extern LispObject Lfloatp(LispObject env, LispObject a);
extern LispObject Lfrexp(LispObject env, LispObject a);
extern LispObject Lfuncall_1(LispObject env, LispObject fn);
extern LispObject Lgc(LispObject env, LispObject a);
extern LispObject Lgensym0(LispObject env, LispObject a, const char *s);
extern LispObject Lgensym1(LispObject env, LispObject a);
extern LispObject Lgensym2(LispObject env, LispObject a);
extern LispObject Lgetd(LispObject env, LispObject a);
extern LispObject Lgetenv(LispObject env, LispObject a);
extern LispObject Lget_bps(LispObject env, LispObject a);
extern LispObject Liadd1(LispObject env, LispObject a);
extern LispObject Lidentity(LispObject env, LispObject a);
extern LispObject Liminus(LispObject env, LispObject a);
extern LispObject Liminusp(LispObject env, LispObject a);
extern LispObject Lindirect(LispObject env, LispObject a);
extern LispObject Lintegerp(LispObject env, LispObject a);
extern LispObject Lintern(LispObject env, LispObject a);
extern LispObject Lionep(LispObject env, LispObject a);
extern LispObject Lis_spid(LispObject env, LispObject a);
extern LispObject Lisub1(LispObject env, LispObject a);
extern LispObject Lizerop(LispObject env, LispObject a);
extern LispObject Llength(LispObject env, LispObject a);
extern LispObject Llengthc(LispObject env, LispObject a);
extern LispObject Llibrary_members(LispObject env, LispObject a);
extern LispObject Llinelength(LispObject env, LispObject a);
extern LispObject Llist_to_string(LispObject env, LispObject a);
extern LispObject Llist_to_vector(LispObject env, LispObject a);
extern LispObject Lload_module(LispObject env, LispObject a);
extern LispObject Lload_source(LispObject env, LispObject a);
extern LispObject Lload_selected_source(LispObject env, LispObject a);
extern LispObject Llognot(LispObject env, LispObject a);
extern LispObject Llog_1(LispObject env, LispObject a);
extern LispObject Llsd(LispObject env, LispObject a);
extern LispObject Lmacroexpand(LispObject env, LispObject a);
extern LispObject Lmacroexpand_1(LispObject env, LispObject a);
extern LispObject Lmacro_function(LispObject env, LispObject a);
extern LispObject Lmake_global(LispObject env, LispObject a);
extern LispObject Lmake_keyword(LispObject env, LispObject a);
extern LispObject Lmake_special(LispObject env, LispObject a);
extern LispObject Lmapstore(LispObject env, LispObject a);
extern LispObject Lmd5(LispObject env, LispObject a1);
extern LispObject Lmd60(LispObject env, LispObject a1);
extern LispObject Lminus(LispObject env, LispObject a);
extern LispObject Lminusp(LispObject env, LispObject a);
extern LispObject Lmkevect(LispObject env, LispObject n);
extern LispObject Lmkquote(LispObject env, LispObject a);
extern LispObject Lmkvect(LispObject env, LispObject a);
extern LispObject Lmodular_minus(LispObject env, LispObject a);
extern LispObject Lmodular_number(LispObject env, LispObject a);
extern LispObject Lmodular_reciprocal(LispObject env, LispObject a);
extern LispObject Lmodule_exists(LispObject env, LispObject a);
extern LispObject Lmsd(LispObject env, LispObject a);
extern LispObject Lmv_list(LispObject env, LispObject a);
extern LispObject Lncons(LispObject env, LispObject a);
extern LispObject Lnreverse(LispObject env, LispObject a);
extern LispObject Lnull(LispObject env, LispObject a);
extern LispObject Lnumberp(LispObject env, LispObject a);
extern LispObject Loddp(LispObject env, LispObject a);
extern LispObject Lonep(LispObject env, LispObject a);
extern LispObject Lpagelength(LispObject env, LispObject a);
extern LispObject Lplist(LispObject env, LispObject a);
extern LispObject Lplusp(LispObject env, LispObject a);
extern LispObject Lprin(LispObject env, LispObject a);
extern LispObject Lprin(LispObject env, LispObject a);
extern LispObject Lprin2a(LispObject env, LispObject a);
extern LispObject Lprinc(LispObject env, LispObject a);
extern LispObject Lprinc(LispObject env, LispObject a);
extern LispObject Lprint(LispObject env, LispObject a);
extern LispObject Lprintc(LispObject env, LispObject a);
extern LispObject Lrandom_1(LispObject env, LispObject a);
extern LispObject Lrational(LispObject env, LispObject a);
extern LispObject Lrdf1(LispObject env, LispObject a);
extern LispObject Lrds(LispObject env, LispObject a);
extern LispObject Lremd(LispObject env, LispObject a);
extern LispObject Lrepresentation1(LispObject env, LispObject a);
extern LispObject Lreverse(LispObject env, LispObject a);
extern LispObject Lserialize(LispObject env, LispObject a);
extern LispObject Lserialize1(LispObject env, LispObject a);
extern LispObject Lsetpchar(LispObject env, LispObject a);
extern LispObject Lset_small_modulus(LispObject env, LispObject a);
extern LispObject Lsmkvect(LispObject env, LispObject a);
extern LispObject Lspecial_char(LispObject env, LispObject a);
extern LispObject Lspecial_form_p(LispObject env, LispObject a);
extern LispObject Lspid_to_nil(LispObject env, LispObject a);
extern LispObject Lspool(LispObject env, LispObject a);
extern LispObject Lstart_module(LispObject env, LispObject a);
NORETURN extern void Lstop1(LispObject env, LispObject a);
extern LispObject Lstringp(LispObject env, LispObject a);
extern LispObject Lsub1(LispObject env, LispObject a);
extern LispObject Lsymbolp(LispObject env, LispObject a);
extern LispObject Lsymbol_argcount(LispObject env, LispObject a);
extern LispObject Lsymbol_argcode(LispObject env, LispObject a);
extern LispObject Lsymbol_env(LispObject env, LispObject a);
extern LispObject Lsymbol_function(LispObject env, LispObject a);
extern LispObject Lsymbol_globalp(LispObject env, LispObject a);
extern LispObject Lsymbol_name(LispObject env, LispObject a);
extern LispObject Lsymbol_restore_fns(LispObject env, LispObject a);
extern LispObject Lsymbol_specialp(LispObject env, LispObject a);
extern LispObject Lsymbol_value(LispObject env, LispObject a);
extern LispObject Lsystem(LispObject env, LispObject a);
extern LispObject Lthreevectorp(LispObject env, LispObject a);
extern LispObject Lthrow_nil(LispObject env, LispObject a);
extern LispObject Ltrace(LispObject env, LispObject a);
extern LispObject Ltruncate(LispObject env, LispObject a);
extern LispObject Lttab(LispObject env, LispObject a);
extern LispObject Ltyo(LispObject env, LispObject a);
extern LispObject Lunintern(LispObject env, LispObject a);
extern LispObject Lunmake_global(LispObject env, LispObject a);
extern LispObject Lunmake_keyword(LispObject env, LispObject a);
extern LispObject Lunmake_special(LispObject env, LispObject a);
extern LispObject Luntrace(LispObject env, LispObject a);
extern LispObject Lupbv(LispObject env, LispObject a);
extern LispObject Lsimple_vectorp(LispObject env, LispObject a);
extern LispObject Lvectorp(LispObject env, LispObject a);
extern LispObject Lverbos(LispObject env, LispObject a);
extern LispObject Lwhitespace_char_p(LispObject env, LispObject a);
extern LispObject Lwritable_libraryp(LispObject env, LispObject a);
extern LispObject Lwrs(LispObject env, LispObject a);
extern LispObject Lxtab(LispObject env, LispObject a);
extern LispObject Lxtab(LispObject env, LispObject a);
extern LispObject Lzerop(LispObject env, LispObject a);
extern LispObject Lfind_symbol_1(LispObject env, LispObject str);
extern LispObject Llistp(LispObject env, LispObject a);
extern LispObject autoload_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject bytecoded_2(LispObject env, LispObject a, LispObject b);
extern LispObject byteopt_2(LispObject def, LispObject a, LispObject b);
extern LispObject byteoptrest_2(LispObject def, LispObject a, LispObject b);
extern LispObject funarged_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject tracefunarged_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject hardopt_2(LispObject def, LispObject a, LispObject b);
extern LispObject hardoptrest_2(LispObject def, LispObject a, LispObject b);
extern LispObject interpreted_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject tracebyteopt_2(LispObject def, LispObject a, LispObject b);
extern LispObject tracebyteoptrest_2(LispObject def, LispObject a, LispObject b);
extern LispObject tracebytecoded_2(LispObject env, LispObject a, LispObject b);
extern LispObject traceinterpreted_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject tracehardopt_2(LispObject def, LispObject a, LispObject b);
extern LispObject tracehardoptrest_2(LispObject def, LispObject a, LispObject b);
extern LispObject undefined_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject f2_as_0(LispObject env, LispObject a, LispObject b);
extern LispObject f2_as_1(LispObject env, LispObject a, LispObject b);
extern LispObject f2_as_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lappend_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lapply_2(LispObject env, LispObject fn, LispObject a1);
extern LispObject Lapply1(LispObject env, LispObject a, LispObject b);
extern LispObject Lash(LispObject env, LispObject a, LispObject b);
extern LispObject Lash1(LispObject env, LispObject a, LispObject b);
extern LispObject Lassoc(LispObject env, LispObject a, LispObject b);
extern LispObject Latan2(LispObject env, LispObject a, LispObject b);
extern LispObject Latan2d(LispObject env, LispObject a, LispObject b);
extern LispObject Latsoc(LispObject env, LispObject a, LispObject b);
extern LispObject Lbpsgetv(LispObject env, LispObject v, LispObject n);
extern LispObject Lcons(LispObject env, LispObject a, LispObject b);
extern LispObject Ldeleq(LispObject env, LispObject a, LispObject b);
extern LispObject Ldelete(LispObject env, LispObject a, LispObject b);
extern LispObject Ldifference_2(LispObject env, LispObject a, LispObject b);
extern LispObject Ldivide_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern LispObject Leq(LispObject env, LispObject a, LispObject b);
extern LispObject Leqcar(LispObject env, LispObject a, LispObject b);
extern LispObject Lequalcar(LispObject env, LispObject a, LispObject b);
extern LispObject Leql(LispObject env, LispObject a, LispObject b);
extern LispObject Leqn_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lcl_equal(LispObject env, LispObject a, LispObject b);
extern LispObject Lequal(LispObject env, LispObject a, LispObject b);
NORETURN extern void Lerror_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject Lerrorset_2(LispObject env, LispObject form, LispObject ffg1);
extern LispObject Lexpt(LispObject env, LispObject a, LispObject b);
extern LispObject Lflag(LispObject env, LispObject a, LispObject b);
extern LispObject Lflagp(LispObject env, LispObject a, LispObject b);
extern LispObject Lflagpcar(LispObject env, LispObject a, LispObject b);
extern LispObject Lfuncall_2(LispObject env, LispObject fn, LispObject a1);
extern LispObject Lgcd_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lgeq_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lget(LispObject env, LispObject a, LispObject b);
extern LispObject Lget_hash_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lgetv(LispObject env, LispObject a, LispObject b);
extern LispObject Lgreaterp_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lidifference_2(LispObject env, LispObject a, LispObject b);
extern LispObject Ligeq_2(LispObject env, LispObject a, LispObject b);
extern LispObject Ligreaterp_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lileq_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lilessp_2(LispObject env, LispObject a, LispObject b);
extern LispObject Limax_2(LispObject env, LispObject a, LispObject b);
extern LispObject Limin_2(LispObject env, LispObject a, LispObject b);
extern LispObject Linorm(LispObject env, LispObject a, LispObject k);
extern LispObject Lintersect(LispObject env, LispObject a, LispObject b);
extern LispObject Lintersect_symlist(LispObject env, LispObject a, LispObject b);
extern LispObject Liplus_2(LispObject env, LispObject a, LispObject b);
extern LispObject Liquotient_2(LispObject env, LispObject a, LispObject b);
extern LispObject Liremainder_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lirightshift(LispObject env, LispObject a, LispObject b);
extern LispObject Litimes_2(LispObject env, LispObject a, LispObject b);
extern LispObject Llcm_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lleq_2(LispObject env, LispObject a, LispObject b);
extern LispObject Llessp_2(LispObject env, LispObject a, LispObject b);
extern LispObject Llist_2(LispObject env, LispObject a, LispObject b);
extern LispObject Llog(LispObject env, LispObject a, LispObject b);
extern LispObject Llog_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b);
extern LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b);
extern LispObject Lmax_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmember(LispObject env, LispObject a, LispObject b);
extern LispObject Lmemq(LispObject env, LispObject a, LispObject b);
extern LispObject Lmin_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmkhash_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmod_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmodular_difference(LispObject env, LispObject a, LispObject b);
extern LispObject Lmodular_expt(LispObject env, LispObject a, LispObject b);
extern LispObject Lmodular_plus(LispObject env, LispObject a, LispObject b);
extern LispObject Lmodular_quotient(LispObject env, LispObject a, LispObject b);
extern LispObject Lmodular_times(LispObject env, LispObject a, LispObject b);
extern LispObject Lnconc(LispObject env, LispObject a, LispObject b);
extern LispObject Lneq_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lnreverse2(LispObject env, LispObject a, LispObject b);
extern LispObject Lorderp(LispObject env, LispObject a, LispObject b);
extern LispObject Lpair(LispObject env, LispObject a, LispObject b);
extern LispObject Lplus_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lquotient_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lrem_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lremflag(LispObject env, LispObject a, LispObject b);
extern LispObject Lremprop(LispObject env, LispObject a, LispObject b);
extern LispObject Lrepresentation2(LispObject env, LispObject a, LispObject b);
extern LispObject Lresource_limit_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lrplaca(LispObject env, LispObject a, LispObject b);
extern LispObject Lrplacd(LispObject env, LispObject a, LispObject b);
extern LispObject Lrseek(LispObject env, LispObject a);
extern LispObject Lset(LispObject env, LispObject a, LispObject b);
extern LispObject Lset_help_file(LispObject env, LispObject a, LispObject b);
extern LispObject Lsgetv(LispObject env, LispObject a, LispObject b);
extern LispObject Lsmemq(LispObject env, LispObject a, LispObject b);
extern LispObject Lsubla(LispObject env, LispObject a, LispObject b);
extern LispObject Lsublis(LispObject env, LispObject a, LispObject b);
extern LispObject Lsymbol_protect(LispObject env, LispObject a, LispObject b);
extern LispObject Lsymbol_set_definition(LispObject env, LispObject a, LispObject b);
extern LispObject Lsymbol_set_env(LispObject env, LispObject a, LispObject b);
NORETURN extern void Lthrow_one_value(LispObject env, LispObject a, LispObject b);
extern LispObject Ltimes_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lunion(LispObject env, LispObject a, LispObject b);
extern LispObject Lunion_symlist(LispObject env, LispObject a, LispObject b);
extern LispObject Lwrite_module(LispObject env, LispObject a, LispObject b);
extern LispObject Lxcons(LispObject env, LispObject a, LispObject b);
extern LispObject Laref_2(LispObject env, LispObject a, LispObject b);
extern LispObject Latan_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern LispObject Lfloat_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lintern_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmacroexpand_1_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmacroexpand_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lrandom_2(LispObject env, LispObject a, LispObject b);
extern LispObject Ltruncate_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lunintern_2(LispObject env, LispObject a, LispObject b);
extern LispObject f3_as_0(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject f3_as_1(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject f3_as_2(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject f3_as_3(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lapply_3(LispObject env, LispObject fn, LispObject a1, LispObject a2);
extern LispObject Lapply2(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lacons(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Laref_3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3);
extern LispObject Laset_3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3);
extern LispObject Lbpsputv(LispObject env, LispObject a1, LispObject a2, LispObject a3);
NORETURN extern void Lerror_3(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lerrorset_3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3);
extern LispObject Lfuncall_3(LispObject env, LispObject fn, LispObject a1, LispObject a2);
extern LispObject Llist_2star(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Llist_3(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lput_hash(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lputprop(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lputv(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lresource_limit_3(LispObject env, LispObject a, LispObject b, LispObject c);
extern LispObject Lsputv(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lsubst(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lget_3(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lmkhash_3(LispObject env, LispObject a, LispObject b, LispObject c);
extern LispObject autoload_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject bytecoded_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject byteopt_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject byteoptrest_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject funarged_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject tracefunarged_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject hardopt_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject hardoptrest_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject interpreted_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject tracebytecoded_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject tracebyteopt_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject tracebyteoptrest_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject tracebytecoded_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject traceinterpreted_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject tracehardopt_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject tracehardoptrest_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject undefined_3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3);
extern LispObject autoload_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject bytecoded_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject byteopt_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject byteoptrest_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject funarged_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracefunarged_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject hardopt_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject hardoptrest_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject interpreted_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracebyteopt_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracebyteoptrest_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracebytecoded0(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracebytecoded_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject traceinterpreted_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracehardopt_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracehardoptrest_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject undefined_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lapply_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lapply3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
NORETURN extern void Lerror_34up(LispObject env, LispObject a1, LispObject a2, LispObject a3, LispObject a4up);
extern LispObject Lerrorset_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lfuncall_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llist_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lliststar_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llogand_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llogeqv_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llogor_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llogxor_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lmax_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lmin_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lresource_limit_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lvalues_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lappend_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Laref_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Laset_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Leqn_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lgcd_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lgeq_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lgreaterp_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llcm_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lleq_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llessp_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lquotient_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
#ifdef OPENMATH
extern LispObject om_openFileDev(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject om_openStringDev(LispObject env, LispObject lstr, LispObject lenc);
extern LispObject om_closeDev(LispObject env, LispObject dev);
extern LispObject om_setDevEncoding(LispObject env, LispObject ldev, LispObject lenc);
extern LispObject om_makeConn(LispObject env, LispObject ltimeout);
extern LispObject om_closeConn(LispObject env, LispObject lconn);
extern LispObject om_getConnInDevice(LispObject env, LispObject lconn);
extern LispObject om_getConnOutDevice(LispObject env, LispObject lconn);
extern LispObject om_connectTCP(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
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
extern LispObject om_putSymbol2(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
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
extern LispObject om_listCDs(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject om_listSymbols(LispObject env, LispObject lcd);
extern LispObject om_whichCDs(LispObject env, LispObject lsym);
#endif
extern LispObject undefined_4up(LispObject env,
 LispObject a1, LispObject a2, LispObject a3, LispObject a4);
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
 { err_printf("[Stack Sanity Oddity] %p => %p in %s : %s:%d\n",
 saveStack, stack, fname, file, line);
 err_printf("Data: ");
 prin_to_error(w);
 err_printf("\n");
 err_printf("exit_count = %d, exit_reason = %d\n",
 exit_count, exit_reason);
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
 if (miscflags & HEADLINE_FLAG) \
 err_printf("\n+++ Error %s: ", errorset_msg); \
 throw LispSignal(); \
 case 2: exit_reason = UNWIND_SIGINT; \
 if (miscflags & HEADLINE_FLAG) \
 err_printf("\n+++ Error %s: ", errorset_msg); \
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



// Code for !*di2q

static LispObject CC_Hdi2q(LispObject env,
                         LispObject v_3, LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_59, v_60, v_61;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_4,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_59 = v_4;
    v_60 = v_3;
// end of prologue
// Binding varlist!*
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(basic_elt(env, 1)) = v_59; // varlist!*
    v_59 = v_60;
    stack[-3] = v_59;
    v_59 = stack[-3];
    if (v_59 == nil) goto v_21;
    else goto v_22;
v_21:
    v_59 = nil;
    v_60 = v_59;
    goto v_16;
v_22:
    v_59 = stack[-3];
    if (!car_legal(v_59)) v_59 = carerror(v_59); else
    v_59 = qcar(v_59);
    v_60 = v_59;
    if (!car_legal(v_60)) v_61 = carerror(v_60); else
    v_61 = qcar(v_60);
    if (!car_legal(v_59)) v_60 = cdrerror(v_59); else
    v_60 = qcdr(v_59);
    v_59 = (LispObject)16+TAG_FIXNUM; // 1
    v_59 = list2star(v_61, v_60, v_59);
    env = stack[-5];
    v_59 = ncons(v_59);
    env = stack[-5];
    stack[-1] = v_59;
    stack[-2] = v_59;
v_17:
    v_59 = stack[-3];
    if (!car_legal(v_59)) v_59 = cdrerror(v_59); else
    v_59 = qcdr(v_59);
    stack[-3] = v_59;
    v_59 = stack[-3];
    if (v_59 == nil) goto v_39;
    else goto v_40;
v_39:
    v_59 = stack[-2];
    v_60 = v_59;
    goto v_16;
v_40:
    stack[0] = stack[-1];
    v_59 = stack[-3];
    if (!car_legal(v_59)) v_59 = carerror(v_59); else
    v_59 = qcar(v_59);
    v_60 = v_59;
    if (!car_legal(v_60)) v_61 = carerror(v_60); else
    v_61 = qcar(v_60);
    if (!car_legal(v_59)) v_60 = cdrerror(v_59); else
    v_60 = qcdr(v_59);
    v_59 = (LispObject)16+TAG_FIXNUM; // 1
    v_59 = list2star(v_61, v_60, v_59);
    env = stack[-5];
    v_59 = ncons(v_59);
    env = stack[-5];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    qcdr(stack[0]) = v_59;
    v_59 = stack[-1];
    if (!car_legal(v_59)) v_59 = cdrerror(v_59); else
    v_59 = qcdr(v_59);
    stack[-1] = v_59;
    goto v_17;
v_16:
    v_59 = qvalue(basic_elt(env, 1)); // varlist!*
    fn = basic_elt(env, 2); // !*di2q0
    v_59 = (*qfn2(fn))(fn, v_60, v_59);
    ;}  // end of a binding scope
    return onevalue(v_59);
}



// Code for st_ad_numsorttree

static LispObject CC_st_ad_numsorttree(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_15, v_16;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15 = v_2;
// end of prologue
    fn = basic_elt(env, 1); // st_ad_numsorttree1
    v_15 = (*qfn1(fn))(fn, v_15);
    v_16 = v_15;
    if (!car_legal(v_16)) v_16 = carerror(v_16); else
    v_16 = qcar(v_16);
    if (!car_legal(v_15)) v_15 = cdrerror(v_15); else
    v_15 = qcdr(v_15);
    if (!car_legal(v_15)) v_15 = carerror(v_15); else
    v_15 = qcar(v_15);
    return cons(v_16, v_15);
    return onevalue(v_15);
}



// Code for max!-degree

static LispObject CC_maxKdegree(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_53, v_54, v_55, v_56;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_54 = v_3;
    v_55 = v_2;
// end of prologue
v_8:
    v_53 = v_55;
    if (!consp(v_53)) goto v_15;
    else goto v_16;
v_15:
    v_53 = lisp_true;
    goto v_14;
v_16:
    v_53 = v_55;
    if (!car_legal(v_53)) v_53 = carerror(v_53); else
    v_53 = qcar(v_53);
    v_53 = (consp(v_53) ? nil : lisp_true);
    goto v_14;
    v_53 = nil;
v_14:
    if (v_53 == nil) goto v_12;
    v_53 = v_54;
    goto v_7;
v_12:
    v_56 = v_54;
    v_53 = v_55;
    if (!car_legal(v_53)) v_53 = carerror(v_53); else
    v_53 = qcar(v_53);
    if (!car_legal(v_53)) v_53 = carerror(v_53); else
    v_53 = qcar(v_53);
    if (!car_legal(v_53)) v_53 = cdrerror(v_53); else
    v_53 = qcdr(v_53);
    if (((intptr_t)(v_56)) > ((intptr_t)(v_53))) goto v_25;
    else goto v_26;
v_25:
    v_53 = v_55;
    if (!car_legal(v_53)) v_53 = cdrerror(v_53); else
    v_53 = qcdr(v_53);
    stack[0] = v_53;
    v_53 = v_55;
    if (!car_legal(v_53)) v_53 = carerror(v_53); else
    v_53 = qcar(v_53);
    if (!car_legal(v_53)) v_53 = cdrerror(v_53); else
    v_53 = qcdr(v_53);
    v_53 = CC_maxKdegree(basic_elt(env, 0), v_53, v_54);
    env = stack[-1];
    v_54 = v_53;
    v_53 = stack[0];
    v_55 = v_53;
    goto v_8;
v_26:
    v_53 = v_55;
    if (!car_legal(v_53)) v_53 = cdrerror(v_53); else
    v_53 = qcdr(v_53);
    stack[0] = v_53;
    v_53 = v_55;
    if (!car_legal(v_53)) v_53 = carerror(v_53); else
    v_53 = qcar(v_53);
    if (!car_legal(v_53)) v_53 = cdrerror(v_53); else
    v_53 = qcdr(v_53);
    v_54 = v_55;
    if (!car_legal(v_54)) v_54 = carerror(v_54); else
    v_54 = qcar(v_54);
    if (!car_legal(v_54)) v_54 = carerror(v_54); else
    v_54 = qcar(v_54);
    if (!car_legal(v_54)) v_54 = cdrerror(v_54); else
    v_54 = qcdr(v_54);
    v_53 = CC_maxKdegree(basic_elt(env, 0), v_53, v_54);
    env = stack[-1];
    v_54 = v_53;
    v_53 = stack[0];
    v_55 = v_53;
    goto v_8;
    v_53 = nil;
v_7:
    return onevalue(v_53);
}



// Code for talp_specsubt

static LispObject CC_talp_specsubt(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_78, v_79, v_80;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push3(v_2,v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_4,v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[0] = v_4;
    stack[-4] = v_3;
    stack[-5] = v_2;
// end of prologue
    v_78 = stack[0];
    if (!consp(v_78)) goto v_11;
    else goto v_12;
v_11:
    v_79 = stack[0];
    v_78 = stack[-5];
    if (v_79 == v_78) goto v_16;
    else goto v_17;
v_16:
    v_78 = stack[-4];
    goto v_15;
v_17:
    v_78 = stack[0];
    goto v_15;
    v_78 = nil;
v_15:
    goto v_8;
v_12:
    v_79 = stack[-5];
    v_78 = stack[0];
    fn = basic_elt(env, 1); // talp_eqtp
    v_78 = (*qfn2(fn))(fn, v_79, v_78);
    env = stack[-7];
    if (v_78 == nil) goto v_27;
    v_78 = stack[-4];
    goto v_8;
v_27:
    v_78 = stack[0];
    if (!car_legal(v_78)) stack[-6] = carerror(v_78); else
    stack[-6] = qcar(v_78);
    v_78 = stack[0];
    if (!car_legal(v_78)) v_78 = cdrerror(v_78); else
    v_78 = qcdr(v_78);
    stack[-3] = v_78;
    v_78 = stack[-3];
    if (v_78 == nil) goto v_45;
    else goto v_46;
v_45:
    v_78 = nil;
    goto v_39;
v_46:
    v_78 = stack[-3];
    if (!car_legal(v_78)) v_78 = carerror(v_78); else
    v_78 = qcar(v_78);
    v_80 = stack[-5];
    v_79 = stack[-4];
    v_78 = CC_talp_specsubt(basic_elt(env, 0), v_80, v_79, v_78);
    env = stack[-7];
    v_78 = ncons(v_78);
    env = stack[-7];
    stack[-1] = v_78;
    stack[-2] = v_78;
v_40:
    v_78 = stack[-3];
    if (!car_legal(v_78)) v_78 = cdrerror(v_78); else
    v_78 = qcdr(v_78);
    stack[-3] = v_78;
    v_78 = stack[-3];
    if (v_78 == nil) goto v_61;
    else goto v_62;
v_61:
    v_78 = stack[-2];
    goto v_39;
v_62:
    stack[0] = stack[-1];
    v_78 = stack[-3];
    if (!car_legal(v_78)) v_78 = carerror(v_78); else
    v_78 = qcar(v_78);
    v_80 = stack[-5];
    v_79 = stack[-4];
    v_78 = CC_talp_specsubt(basic_elt(env, 0), v_80, v_79, v_78);
    env = stack[-7];
    v_78 = ncons(v_78);
    env = stack[-7];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    qcdr(stack[0]) = v_78;
    v_78 = stack[-1];
    if (!car_legal(v_78)) v_78 = cdrerror(v_78); else
    v_78 = qcdr(v_78);
    stack[-1] = v_78;
    goto v_40;
v_39:
    {
        LispObject v_88 = stack[-6];
        return cons(v_88, v_78);
    }
v_8:
    return onevalue(v_78);
}



// Code for pasf_sisub

static LispObject CC_pasf_sisub(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_271, v_272, v_273;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push3(v_2,v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_4,v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_4;
    stack[-5] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_271 = stack[-1];
    if (!consp(v_271)) goto v_11;
    else goto v_12;
v_11:
    v_271 = stack[-1];
    goto v_10;
v_12:
    v_271 = stack[-1];
    if (!car_legal(v_271)) v_271 = carerror(v_271); else
    v_271 = qcar(v_271);
    goto v_10;
    v_271 = nil;
v_10:
    stack[-6] = v_271;
    v_272 = stack[-6];
    v_271 = basic_elt(env, 1); // ex
    if (v_272 == v_271) goto v_25;
    else goto v_26;
v_25:
    v_271 = lisp_true;
    goto v_24;
v_26:
    v_272 = stack[-6];
    v_271 = basic_elt(env, 2); // all
    v_271 = (v_272 == v_271 ? lisp_true : nil);
    goto v_24;
    v_271 = nil;
v_24:
    if (v_271 == nil) goto v_22;
    stack[-2] = stack[-6];
    v_271 = stack[-1];
    if (!car_legal(v_271)) v_271 = cdrerror(v_271); else
    v_271 = qcdr(v_271);
    if (!car_legal(v_271)) stack[0] = carerror(v_271); else
    stack[0] = qcar(v_271);
    v_271 = stack[-1];
    if (!car_legal(v_271)) v_271 = cdrerror(v_271); else
    v_271 = qcdr(v_271);
    if (!car_legal(v_271)) v_271 = cdrerror(v_271); else
    v_271 = qcdr(v_271);
    if (!car_legal(v_271)) v_273 = carerror(v_271); else
    v_273 = qcar(v_271);
    v_272 = stack[-5];
    v_271 = stack[-4];
    v_271 = CC_pasf_sisub(basic_elt(env, 0), v_273, v_272, v_271);
    {
        LispObject v_281 = stack[-2];
        LispObject v_282 = stack[0];
        return list3(v_281, v_282, v_271);
    }
v_22:
    v_272 = stack[-6];
    v_271 = basic_elt(env, 3); // bex
    if (v_272 == v_271) goto v_53;
    else goto v_54;
v_53:
    v_271 = lisp_true;
    goto v_52;
v_54:
    v_272 = stack[-6];
    v_271 = basic_elt(env, 4); // ball
    v_271 = (v_272 == v_271 ? lisp_true : nil);
    goto v_52;
    v_271 = nil;
v_52:
    if (v_271 == nil) goto v_50;
    stack[-3] = stack[-6];
    v_271 = stack[-1];
    if (!car_legal(v_271)) v_271 = cdrerror(v_271); else
    v_271 = qcdr(v_271);
    if (!car_legal(v_271)) stack[-2] = carerror(v_271); else
    stack[-2] = qcar(v_271);
    v_271 = stack[-1];
    if (!car_legal(v_271)) v_271 = cdrerror(v_271); else
    v_271 = qcdr(v_271);
    if (!car_legal(v_271)) v_271 = cdrerror(v_271); else
    v_271 = qcdr(v_271);
    if (!car_legal(v_271)) v_273 = carerror(v_271); else
    v_273 = qcar(v_271);
    v_272 = stack[-5];
    v_271 = stack[-4];
    stack[0] = CC_pasf_sisub(basic_elt(env, 0), v_273, v_272, v_271);
    env = stack[-7];
    v_271 = stack[-1];
    if (!car_legal(v_271)) v_271 = cdrerror(v_271); else
    v_271 = qcdr(v_271);
    if (!car_legal(v_271)) v_271 = cdrerror(v_271); else
    v_271 = qcdr(v_271);
    if (!car_legal(v_271)) v_271 = cdrerror(v_271); else
    v_271 = qcdr(v_271);
    if (!car_legal(v_271)) v_273 = carerror(v_271); else
    v_273 = qcar(v_271);
    v_272 = stack[-5];
    v_271 = stack[-4];
    v_271 = CC_pasf_sisub(basic_elt(env, 0), v_273, v_272, v_271);
    {
        LispObject v_283 = stack[-3];
        LispObject v_284 = stack[-2];
        LispObject v_285 = stack[0];
        return list4(v_283, v_284, v_285, v_271);
    }
v_50:
    v_272 = stack[-6];
    v_271 = basic_elt(env, 5); // and
    if (v_272 == v_271) goto v_85;
    else goto v_86;
v_85:
    stack[0] = basic_elt(env, 5); // and
    v_271 = stack[-1];
    if (!car_legal(v_271)) stack[-1] = cdrerror(v_271); else
    stack[-1] = qcdr(v_271);
    stack[-2] = stack[-5];
    v_273 = stack[-4];
    v_272 = basic_elt(env, 6); // true
    v_271 = basic_elt(env, 7); // false
    v_271 = list3(v_273, v_272, v_271);
    env = stack[-7];
    {
        LispObject v_286 = stack[0];
        LispObject v_287 = stack[-1];
        LispObject v_288 = stack[-2];
        fn = basic_elt(env, 13); // pasf_sisub!-gand
        return (*qfn4up(fn))(fn, v_286, v_287, v_288, v_271);
    }
v_86:
    v_272 = stack[-6];
    v_271 = basic_elt(env, 8); // or
    if (v_272 == v_271) goto v_100;
    else goto v_101;
v_100:
    stack[0] = basic_elt(env, 8); // or
    v_271 = stack[-1];
    if (!car_legal(v_271)) stack[-1] = cdrerror(v_271); else
    stack[-1] = qcdr(v_271);
    stack[-2] = stack[-5];
    v_273 = stack[-4];
    v_272 = basic_elt(env, 7); // false
    v_271 = basic_elt(env, 6); // true
    v_271 = list3(v_273, v_272, v_271);
    env = stack[-7];
    {
        LispObject v_289 = stack[0];
        LispObject v_290 = stack[-1];
        LispObject v_291 = stack[-2];
        fn = basic_elt(env, 13); // pasf_sisub!-gand
        return (*qfn4up(fn))(fn, v_289, v_290, v_291, v_271);
    }
v_101:
    v_272 = stack[-6];
    v_271 = basic_elt(env, 8); // or
    if (v_272 == v_271) goto v_127;
    else goto v_128;
v_127:
    v_271 = lisp_true;
    goto v_126;
v_128:
    v_272 = stack[-6];
    v_271 = basic_elt(env, 5); // and
    v_271 = (v_272 == v_271 ? lisp_true : nil);
    goto v_126;
    v_271 = nil;
v_126:
    if (v_271 == nil) goto v_124;
    v_271 = lisp_true;
    goto v_122;
v_124:
    v_272 = stack[-6];
    v_271 = basic_elt(env, 9); // not
    v_271 = (v_272 == v_271 ? lisp_true : nil);
    goto v_122;
    v_271 = nil;
v_122:
    if (v_271 == nil) goto v_120;
    v_271 = lisp_true;
    goto v_118;
v_120:
    v_272 = stack[-6];
    v_271 = basic_elt(env, 10); // impl
    if (v_272 == v_271) goto v_148;
    else goto v_149;
v_148:
    v_271 = lisp_true;
    goto v_147;
v_149:
    v_272 = stack[-6];
    v_271 = basic_elt(env, 11); // repl
    if (v_272 == v_271) goto v_157;
    else goto v_158;
v_157:
    v_271 = lisp_true;
    goto v_156;
v_158:
    v_272 = stack[-6];
    v_271 = basic_elt(env, 12); // equiv
    v_271 = (v_272 == v_271 ? lisp_true : nil);
    goto v_156;
    v_271 = nil;
v_156:
    goto v_147;
    v_271 = nil;
v_147:
    goto v_118;
    v_271 = nil;
v_118:
    if (v_271 == nil) goto v_116;
    v_271 = stack[-1];
    if (!car_legal(v_271)) v_271 = cdrerror(v_271); else
    v_271 = qcdr(v_271);
    stack[-3] = v_271;
    v_271 = stack[-3];
    if (v_271 == nil) goto v_177;
    else goto v_178;
v_177:
    v_271 = nil;
    goto v_171;
v_178:
    v_271 = stack[-3];
    if (!car_legal(v_271)) v_271 = carerror(v_271); else
    v_271 = qcar(v_271);
    v_273 = v_271;
    v_272 = stack[-5];
    v_271 = stack[-4];
    v_271 = CC_pasf_sisub(basic_elt(env, 0), v_273, v_272, v_271);
    env = stack[-7];
    v_271 = ncons(v_271);
    env = stack[-7];
    stack[-1] = v_271;
    stack[-2] = v_271;
v_172:
    v_271 = stack[-3];
    if (!car_legal(v_271)) v_271 = cdrerror(v_271); else
    v_271 = qcdr(v_271);
    stack[-3] = v_271;
    v_271 = stack[-3];
    if (v_271 == nil) goto v_193;
    else goto v_194;
v_193:
    v_271 = stack[-2];
    goto v_171;
v_194:
    stack[0] = stack[-1];
    v_271 = stack[-3];
    if (!car_legal(v_271)) v_271 = carerror(v_271); else
    v_271 = qcar(v_271);
    v_273 = v_271;
    v_272 = stack[-5];
    v_271 = stack[-4];
    v_271 = CC_pasf_sisub(basic_elt(env, 0), v_273, v_272, v_271);
    env = stack[-7];
    v_271 = ncons(v_271);
    env = stack[-7];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    qcdr(stack[0]) = v_271;
    v_271 = stack[-1];
    if (!car_legal(v_271)) v_271 = cdrerror(v_271); else
    v_271 = qcdr(v_271);
    stack[-1] = v_271;
    goto v_172;
v_171:
    v_272 = v_271;
    v_271 = v_272;
    if (v_271 == nil) goto v_213;
    v_271 = v_272;
    if (!car_legal(v_271)) v_271 = cdrerror(v_271); else
    v_271 = qcdr(v_271);
    if (v_271 == nil) goto v_213;
    v_271 = stack[-6];
    return cons(v_271, v_272);
v_213:
    v_271 = v_272;
    if (v_271 == nil) goto v_222;
    else goto v_223;
v_222:
    v_272 = stack[-6];
    v_271 = basic_elt(env, 5); // and
    if (v_272 == v_271) goto v_227;
    else goto v_228;
v_227:
    v_271 = basic_elt(env, 6); // true
    goto v_226;
v_228:
    v_271 = basic_elt(env, 7); // false
    goto v_226;
    v_271 = nil;
v_226:
    goto v_211;
v_223:
    v_271 = v_272;
    if (!car_legal(v_271)) v_271 = carerror(v_271); else
    v_271 = qcar(v_271);
    goto v_211;
    v_271 = nil;
v_211:
    goto v_8;
v_116:
    v_272 = stack[-6];
    v_271 = basic_elt(env, 6); // true
    if (v_272 == v_271) goto v_245;
    else goto v_246;
v_245:
    v_271 = lisp_true;
    goto v_244;
v_246:
    v_272 = stack[-6];
    v_271 = basic_elt(env, 7); // false
    v_271 = (v_272 == v_271 ? lisp_true : nil);
    goto v_244;
    v_271 = nil;
v_244:
    if (v_271 == nil) goto v_242;
    v_271 = stack[-1];
    goto v_8;
v_242:
    v_271 = stack[-1];
    if (!car_legal(v_271)) stack[0] = carerror(v_271); else
    stack[0] = qcar(v_271);
    v_271 = stack[-1];
    if (!car_legal(v_271)) v_271 = cdrerror(v_271); else
    v_271 = qcdr(v_271);
    if (!car_legal(v_271)) stack[-1] = carerror(v_271); else
    stack[-1] = qcar(v_271);
    v_272 = stack[-5];
    v_271 = stack[-4];
    v_271 = cons(v_272, v_271);
    env = stack[-7];
    v_271 = ncons(v_271);
    env = stack[-7];
    fn = basic_elt(env, 14); // subf
    v_271 = (*qfn2(fn))(fn, stack[-1], v_271);
    env = stack[-7];
    if (!car_legal(v_271)) v_272 = carerror(v_271); else
    v_272 = qcar(v_271);
    v_271 = nil;
    v_272 = list3(stack[0], v_272, v_271);
    env = stack[-7];
    v_271 = stack[-6];
    {
        fn = basic_elt(env, 15); // pasf_simplat1
        return (*qfn2(fn))(fn, v_272, v_271);
    }
v_8:
    return onevalue(v_271);
}



// Code for ev_max!#

static LispObject CC_ev_maxC(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_15, v_16, v_17, v_18;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16 = v_3;
    v_17 = v_2;
// end of prologue
    v_18 = v_17;
    v_15 = v_16;
    if (((intptr_t)(v_18)) > ((intptr_t)(v_15))) goto v_7;
    else goto v_8;
v_7:
    v_15 = v_17;
    goto v_6;
v_8:
    v_15 = v_16;
    goto v_6;
    v_15 = nil;
v_6:
    return onevalue(v_15);
}



// Code for containerml

static LispObject CC_containerml(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_35, v_36;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_36 = stack[0];
    v_35 = basic_elt(env, 1); // integer_interval
    if (v_36 == v_35) goto v_9;
    else goto v_10;
v_9:
    v_35 = basic_elt(env, 2); // interval
    stack[0] = v_35;
    goto v_8;
v_10:
v_8:
    v_35 = basic_elt(env, 3); // "<"
    fn = basic_elt(env, 7); // printout
    v_35 = (*qfn1(fn))(fn, v_35);
    env = stack[-2];
    v_35 = stack[0];
    v_35 = Lprinc(nil, v_35);
    env = stack[-2];
    v_35 = stack[-1];
    if (!car_legal(v_35)) v_36 = carerror(v_35); else
    v_36 = qcar(v_35);
    v_35 = basic_elt(env, 4); // ""
    fn = basic_elt(env, 8); // attributesml
    v_35 = (*qfn2(fn))(fn, v_36, v_35);
    env = stack[-2];
    v_35 = lisp_true;
    fn = basic_elt(env, 9); // indent!*
    v_35 = (*qfn1(fn))(fn, v_35);
    env = stack[-2];
    v_35 = stack[-1];
    if (!car_legal(v_35)) v_35 = cdrerror(v_35); else
    v_35 = qcdr(v_35);
    fn = basic_elt(env, 10); // multi_elem
    v_35 = (*qfn1(fn))(fn, v_35);
    env = stack[-2];
    v_35 = nil;
    fn = basic_elt(env, 9); // indent!*
    v_35 = (*qfn1(fn))(fn, v_35);
    env = stack[-2];
    v_35 = basic_elt(env, 5); // "</"
    fn = basic_elt(env, 7); // printout
    v_35 = (*qfn1(fn))(fn, v_35);
    env = stack[-2];
    v_35 = stack[0];
    v_35 = Lprinc(nil, v_35);
    env = stack[-2];
    v_35 = basic_elt(env, 6); // ">"
    v_35 = Lprinc(nil, v_35);
    v_35 = nil;
    return onevalue(v_35);
}



// Code for mkempspmat

static LispObject CC_mkempspmat(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_14, v_15;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    v_14 = v_2;
// end of prologue
    stack[-1] = basic_elt(env, 1); // sparsemat
    v_15 = Lmkvect(nil, v_14);
    v_14 = stack[0];
    {
        LispObject v_18 = stack[-1];
        return list3(v_18, v_15, v_14);
    }
    return onevalue(v_14);
}



// Code for insoccs

static LispObject CC_insoccs(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_64, v_65;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_64 = stack[-1];
    if (symbolp(v_64)) goto v_9;
    v_64 = stack[-1];
    fn = basic_elt(env, 1); // subscriptedvarp
    v_64 = (*qfn1(fn))(fn, v_64);
    env = stack[-2];
    if (v_64 == nil) goto v_14;
    else goto v_9;
v_14:
    v_64 = stack[-1];
    v_64 = Lconsp(nil, v_64);
    env = stack[-2];
    if (v_64 == nil) goto v_17;
    v_64 = stack[-1];
    if (!car_legal(v_64)) v_64 = carerror(v_64); else
    v_64 = qcar(v_64);
    fn = basic_elt(env, 1); // subscriptedvarp
    v_64 = (*qfn1(fn))(fn, v_64);
    env = stack[-2];
    if (v_64 == nil) goto v_17;
    goto v_9;
v_17:
    goto v_10;
v_9:
    v_65 = stack[0];
    v_64 = stack[-1];
    fn = basic_elt(env, 2); // insertocc
    v_64 = (*qfn2(fn))(fn, v_65, v_64);
    env = stack[-2];
    stack[0] = v_64;
    goto v_8;
v_10:
v_8:
    v_64 = stack[-1];
    if (symbolp(v_64)) goto v_35;
    v_64 = stack[-1];
    fn = basic_elt(env, 3); // constp
    v_64 = (*qfn1(fn))(fn, v_64);
    env = stack[-2];
    v_64 = (v_64 == nil ? lisp_true : nil);
    goto v_33;
v_35:
    v_64 = nil;
    goto v_33;
    v_64 = nil;
v_33:
    if (v_64 == nil) goto v_31;
    v_64 = stack[-1];
    if (!car_legal(v_64)) v_64 = cdrerror(v_64); else
    v_64 = qcdr(v_64);
    stack[-1] = v_64;
v_46:
    v_64 = stack[-1];
    if (v_64 == nil) goto v_51;
    else goto v_52;
v_51:
    goto v_45;
v_52:
    v_64 = stack[-1];
    if (!car_legal(v_64)) v_64 = carerror(v_64); else
    v_64 = qcar(v_64);
    v_65 = v_64;
    v_64 = stack[0];
    v_64 = CC_insoccs(basic_elt(env, 0), v_65, v_64);
    env = stack[-2];
    stack[0] = v_64;
    v_64 = stack[-1];
    if (!car_legal(v_64)) v_64 = cdrerror(v_64); else
    v_64 = qcdr(v_64);
    stack[-1] = v_64;
    goto v_46;
v_45:
    goto v_29;
v_31:
v_29:
    v_64 = stack[0];
    return onevalue(v_64);
}



// Code for !:dmtimeslst

static LispObject CC_Tdmtimeslst(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_24, v_25;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_25 = v_2;
// end of prologue
    v_24 = v_25;
    if (v_24 == nil) goto v_6;
    else goto v_7;
v_6:
    v_24 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5;
v_7:
    v_24 = v_25;
    if (!car_legal(v_24)) v_24 = cdrerror(v_24); else
    v_24 = qcdr(v_24);
    if (v_24 == nil) goto v_10;
    else goto v_11;
v_10:
    v_24 = v_25;
    if (!car_legal(v_24)) v_24 = carerror(v_24); else
    v_24 = qcar(v_24);
    goto v_5;
v_11:
    v_24 = v_25;
    if (!car_legal(v_24)) stack[0] = carerror(v_24); else
    stack[0] = qcar(v_24);
    v_24 = v_25;
    if (!car_legal(v_24)) v_24 = cdrerror(v_24); else
    v_24 = qcdr(v_24);
    v_24 = CC_Tdmtimeslst(basic_elt(env, 0), v_24);
    env = stack[-1];
    {
        LispObject v_27 = stack[0];
        fn = basic_elt(env, 1); // !:times
        return (*qfn2(fn))(fn, v_27, v_24);
    }
    v_24 = nil;
v_5:
    return onevalue(v_24);
}



// Code for !*xadd

static LispObject CC_Hxadd(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_40, v_41, v_42, v_43;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_43 = v_3;
    stack[0] = v_2;
// end of prologue
    v_40 = v_43;
    v_42 = v_40;
v_11:
    v_40 = v_42;
    if (v_40 == nil) goto v_14;
    v_40 = stack[0];
    if (!car_legal(v_40)) v_41 = carerror(v_40); else
    v_41 = qcar(v_40);
    v_40 = v_42;
    if (!car_legal(v_40)) v_40 = carerror(v_40); else
    v_40 = qcar(v_40);
    if (!car_legal(v_40)) v_40 = carerror(v_40); else
    v_40 = qcar(v_40);
    if (equal(v_41, v_40)) goto v_14;
    goto v_15;
v_14:
    goto v_10;
v_15:
    v_40 = v_42;
    if (!car_legal(v_40)) v_40 = cdrerror(v_40); else
    v_40 = qcdr(v_40);
    v_42 = v_40;
    goto v_11;
v_10:
    v_40 = v_42;
    if (v_40 == nil) goto v_30;
    v_40 = v_42;
    if (!car_legal(v_40)) v_40 = carerror(v_40); else
    v_40 = qcar(v_40);
    v_41 = v_43;
    v_40 = Ldelete(nil, v_40, v_41);
    v_43 = v_40;
    goto v_28;
v_30:
v_28:
    v_40 = stack[0];
    v_41 = v_43;
    return cons(v_40, v_41);
    return onevalue(v_40);
}



// Code for incident

static LispObject CC_incident(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_37, v_38, v_39;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push3(v_2,v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_4,v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_4;
    stack[0] = v_3;
    stack[-2] = v_2;
// end of prologue
v_1:
    v_37 = stack[0];
    if (v_37 == nil) goto v_8;
    else goto v_9;
v_8:
    v_37 = nil;
    goto v_7;
v_9:
    v_39 = stack[-2];
    v_37 = stack[0];
    if (!car_legal(v_37)) v_38 = carerror(v_37); else
    v_38 = qcar(v_37);
    v_37 = stack[-1];
    fn = basic_elt(env, 1); // incident1
    v_37 = (*qfn3(fn))(fn, v_39, v_38, v_37);
    env = stack[-3];
    v_38 = v_37;
    v_37 = v_38;
    if (v_37 == nil) goto v_23;
    v_37 = stack[0];
    if (!car_legal(v_37)) v_37 = cdrerror(v_37); else
    v_37 = qcdr(v_37);
    return cons(v_38, v_37);
v_23:
    v_37 = stack[0];
    if (!car_legal(v_37)) stack[0] = cdrerror(v_37); else
    stack[0] = qcdr(v_37);
    v_37 = stack[-1];
    v_37 = add1(v_37);
    env = stack[-3];
    stack[-1] = v_37;
    goto v_1;
    v_37 = nil;
    goto v_7;
    v_37 = nil;
v_7:
    return onevalue(v_37);
}



// Code for innprodp2

static LispObject CC_innprodp2(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_34, v_35;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_34 = v_3;
    stack[-2] = v_2;
// end of prologue
    v_35 = nil;
    v_34 = cons(v_35, v_34);
    env = stack[-4];
v_12:
    v_35 = stack[-2];
    if (v_35 == nil) goto v_15;
    v_35 = v_34;
    if (v_35 == nil) goto v_15;
    goto v_16;
v_15:
    goto v_11;
v_16:
    stack[-3] = nil;
    v_35 = stack[-2];
    if (!car_legal(v_35)) stack[-1] = carerror(v_35); else
    stack[-1] = qcar(v_35);
    v_35 = v_34;
    if (!car_legal(v_35)) stack[0] = cdrerror(v_35); else
    stack[0] = qcdr(v_35);
    if (!car_legal(v_34)) v_34 = carerror(v_34); else
    v_34 = qcar(v_34);
    v_34 = ncons(v_34);
    env = stack[-4];
    fn = basic_elt(env, 1); // innprodkp
    v_34 = (*qfn4up(fn))(fn, stack[-3], stack[-1], stack[0], v_34);
    env = stack[-4];
    v_35 = stack[-2];
    if (!car_legal(v_35)) v_35 = cdrerror(v_35); else
    v_35 = qcdr(v_35);
    stack[-2] = v_35;
    goto v_12;
v_11:
    return onevalue(v_34);
}



// Code for iv_cutcongs1

static LispObject CC_iv_cutcongs1(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_29, v_30;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
v_7:
    v_29 = stack[0];
    if (v_29 == nil) goto v_11;
    v_30 = stack[-1];
    v_29 = stack[0];
    if (!car_legal(v_29)) v_29 = carerror(v_29); else
    v_29 = qcar(v_29);
    fn = basic_elt(env, 1); // iv_cutcongs2
    v_29 = (*qfn2(fn))(fn, v_30, v_29);
    env = stack[-2];
    if (v_29 == nil) goto v_16;
    v_29 = stack[0];
    if (!car_legal(v_29)) v_29 = cdrerror(v_29); else
    v_29 = qcdr(v_29);
    stack[0] = v_29;
    goto v_7;
v_16:
    v_29 = nil;
    goto v_6;
    goto v_9;
v_11:
    v_29 = lisp_true;
    goto v_6;
v_9:
    v_29 = nil;
v_6:
    return onevalue(v_29);
}



// Code for vdelete

static LispObject CC_vdelete(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_35, v_36, v_37;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_37 = nil;
v_8:
    v_35 = stack[0];
    if (v_35 == nil) goto v_11;
    else goto v_12;
v_11:
    v_35 = v_37;
    {
        fn = basic_elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_35);
    }
v_12:
    v_35 = stack[-1];
    if (!car_legal(v_35)) v_36 = carerror(v_35); else
    v_36 = qcar(v_35);
    v_35 = stack[0];
    if (!car_legal(v_35)) v_35 = carerror(v_35); else
    v_35 = qcar(v_35);
    if (!car_legal(v_35)) v_35 = carerror(v_35); else
    v_35 = qcar(v_35);
    if (equal(v_36, v_35)) goto v_16;
    else goto v_17;
v_16:
    v_36 = v_37;
    v_35 = stack[0];
    if (!car_legal(v_35)) v_35 = cdrerror(v_35); else
    v_35 = qcdr(v_35);
    {
        fn = basic_elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_36, v_35);
    }
v_17:
    v_35 = stack[0];
    if (!car_legal(v_35)) v_35 = carerror(v_35); else
    v_35 = qcar(v_35);
    v_36 = v_37;
    v_35 = cons(v_35, v_36);
    env = stack[-2];
    v_37 = v_35;
    v_35 = stack[0];
    if (!car_legal(v_35)) v_35 = cdrerror(v_35); else
    v_35 = qcdr(v_35);
    stack[0] = v_35;
    goto v_8;
    v_35 = nil;
    return onevalue(v_35);
}



// Code for omatpir

static LispObject CC_omatpir(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_21, v_22, v_23;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// end of prologue
    fn = basic_elt(env, 2); // lex
    v_21 = (*qfn0(fn))(fn);
    env = stack[-2];
    fn = basic_elt(env, 3); // omsir
    v_21 = (*qfn0(fn))(fn);
    env = stack[-2];
    if (!car_legal(v_21)) v_21 = carerror(v_21); else
    v_21 = qcar(v_21);
    stack[-1] = v_21;
    fn = basic_elt(env, 2); // lex
    v_21 = (*qfn0(fn))(fn);
    env = stack[-2];
    fn = basic_elt(env, 4); // omobj
    v_21 = (*qfn0(fn))(fn);
    env = stack[-2];
    if (!car_legal(v_21)) v_21 = carerror(v_21); else
    v_21 = qcar(v_21);
    stack[0] = v_21;
    fn = basic_elt(env, 2); // lex
    v_21 = (*qfn0(fn))(fn);
    env = stack[-2];
    v_21 = basic_elt(env, 1); // (!/ o m a t p)
    fn = basic_elt(env, 5); // checktag
    v_21 = (*qfn1(fn))(fn, v_21);
    env = stack[-2];
    v_23 = stack[-1];
    v_22 = stack[0];
    v_21 = nil;
    v_21 = list2star(v_23, v_22, v_21);
    return ncons(v_21);
    return onevalue(v_21);
}



// Code for suchp

static LispObject CC_suchp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_16, v_17;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_17 = v_2;
// end of prologue
    v_16 = v_17;
    if (!consp(v_16)) goto v_7;
    v_16 = v_17;
    if (!car_legal(v_16)) v_16 = carerror(v_16); else
    v_16 = qcar(v_16);
    v_17 = basic_elt(env, 1); // such!-that
    v_16 = (v_16 == v_17 ? lisp_true : nil);
    goto v_5;
v_7:
    v_16 = nil;
    goto v_5;
    v_16 = nil;
v_5:
    return onevalue(v_16);
}



// Code for module

static LispObject CC_module(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_12, v_13;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12 = v_2;
// end of prologue
    v_13 = qvalue(basic_elt(env, 1)); // !*mode
    v_12 = qvalue(basic_elt(env, 2)); // mode!-list!*
    v_12 = cons(v_13, v_12);
    env = stack[0];
    qvalue(basic_elt(env, 2)) = v_12; // mode!-list!*
    v_12 = nil;
    v_12 = ncons(v_12);
    env = stack[0];
    qvalue(basic_elt(env, 3)) = v_12; // alglist!*
    v_12 = basic_elt(env, 4); // symbolic
    qvalue(basic_elt(env, 1)) = v_12; // !*mode
    v_12 = nil;
    return onevalue(v_12);
}



// Code for s_actual_world1

static LispObject CC_s_actual_world1(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_8;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8 = v_2;
// end of prologue
    if (!car_legal(v_8)) v_8 = carerror(v_8); else
    v_8 = qcar(v_8);
    if (!car_legal(v_8)) v_8 = carerror(v_8); else
    v_8 = qcar(v_8);
    if (!car_legal(v_8)) v_8 = carerror(v_8); else
    v_8 = qcar(v_8);
    return onevalue(v_8);
}



// Code for read_typed_name

static LispObject CC_read_typed_name(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_21, v_22;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// end of prologue
    v_21 = qvalue(basic_elt(env, 1)); // cursym!*
    stack[0] = v_21;
    fn = basic_elt(env, 4); // scan
    v_21 = (*qfn0(fn))(fn);
    env = stack[-1];
    v_22 = qvalue(basic_elt(env, 1)); // cursym!*
    v_21 = basic_elt(env, 2); // !*colon!*
    if (v_22 == v_21) goto v_11;
    v_21 = stack[0];
    v_22 = basic_elt(env, 3); // general
    return cons(v_21, v_22);
v_11:
    fn = basic_elt(env, 4); // scan
    v_21 = (*qfn0(fn))(fn);
    env = stack[-1];
    fn = basic_elt(env, 5); // read_type
    v_21 = (*qfn0(fn))(fn);
    {
        LispObject v_24 = stack[0];
        return cons(v_24, v_21);
    }
    return onevalue(v_21);
}



// Code for subs2chk

static LispObject CC_subs2chk(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_21, v_22, v_23;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_21 = qvalue(basic_elt(env, 1)); // subfg!*
    if (v_21 == nil) goto v_10;
    v_21 = stack[0];
    fn = basic_elt(env, 2); // subs2f
    v_21 = (*qfn1(fn))(fn, v_21);
    v_23 = v_21;
    if (!car_legal(v_21)) v_22 = cdrerror(v_21); else
    v_22 = qcdr(v_21);
    v_21 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_22 == v_21) goto v_13;
    else goto v_10;
v_13:
    v_21 = v_23;
    if (!car_legal(v_21)) v_21 = carerror(v_21); else
    v_21 = qcar(v_21);
    stack[0] = v_21;
    goto v_8;
v_10:
v_8:
    v_21 = stack[0];
    return onevalue(v_21);
}



// Code for simp!-prop!-condense

static LispObject CC_simpKpropKcondense(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_56, v_57;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_2;
// end of prologue
    stack[-2] = nil;
    v_57 = stack[-3];
    v_56 = basic_elt(env, 1); // lambda_rfde09ec49c92
    fn = basic_elt(env, 2); // sort
    v_56 = (*qfn2(fn))(fn, v_57, v_56);
    env = stack[-5];
    stack[-3] = v_56;
v_13:
    v_56 = stack[-3];
    if (v_56 == nil) goto v_16;
    else goto v_17;
v_16:
    goto v_12;
v_17:
    v_56 = stack[-3];
    if (!car_legal(v_56)) v_56 = carerror(v_56); else
    v_56 = qcar(v_56);
    stack[-4] = v_56;
    v_56 = stack[-3];
    if (!car_legal(v_56)) v_56 = cdrerror(v_56); else
    v_56 = qcdr(v_56);
    stack[-3] = v_56;
    v_57 = stack[-4];
    v_56 = stack[-2];
    v_56 = cons(v_57, v_56);
    env = stack[-5];
    stack[-2] = v_56;
    v_56 = stack[-3];
    stack[-1] = v_56;
v_30:
    v_56 = stack[-1];
    if (v_56 == nil) goto v_34;
    else goto v_35;
v_34:
    goto v_29;
v_35:
    v_56 = stack[-1];
    if (!car_legal(v_56)) v_56 = carerror(v_56); else
    v_56 = qcar(v_56);
    stack[0] = v_56;
    v_57 = stack[-4];
    v_56 = stack[0];
    fn = basic_elt(env, 3); // subsetp
    v_56 = (*qfn2(fn))(fn, v_57, v_56);
    env = stack[-5];
    if (v_56 == nil) goto v_44;
    v_57 = stack[0];
    v_56 = stack[-3];
    v_56 = Ldelete(nil, v_57, v_56);
    env = stack[-5];
    stack[-3] = v_56;
    goto v_42;
v_44:
v_42:
    v_56 = stack[-1];
    if (!car_legal(v_56)) v_56 = cdrerror(v_56); else
    v_56 = qcdr(v_56);
    stack[-1] = v_56;
    goto v_30;
v_29:
    goto v_13;
v_12:
    v_56 = stack[-2];
    {
        fn = basic_elt(env, 4); // ordn
        return (*qfn1(fn))(fn, v_56);
    }
    return onevalue(v_56);
}



// Code for lambda_rfde09ec49c92

static LispObject CC_lambda_rfde09ec49c92(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_10;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    v_10 = v_2;
// end of prologue
    stack[-1] = Llength(nil, v_10);
    env = stack[-2];
    v_10 = stack[0];
    v_10 = Llength(nil, v_10);
    {
        LispObject v_13 = stack[-1];
        return Llessp_2(nil, v_13, v_10);
    }
}



// Code for skp_ordp

static LispObject CC_skp_ordp(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_11, v_12, v_13;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11 = v_3;
    v_12 = v_2;
// end of prologue
    if (!car_legal(v_12)) v_13 = carerror(v_12); else
    v_13 = qcar(v_12);
    if (!car_legal(v_11)) v_12 = carerror(v_11); else
    v_12 = qcar(v_11);
    v_11 = basic_elt(env, 1); // atom_compare
    {
        fn = basic_elt(env, 2); // cons_ordp
        return (*qfn3(fn))(fn, v_13, v_12, v_11);
    }
}



// Code for chkrn!*

static LispObject CC_chkrnH(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_14, v_15;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15 = v_2;
// end of prologue
    v_14 = qvalue(basic_elt(env, 1)); // !*!*roundbf
    if (v_14 == nil) goto v_7;
    v_14 = v_15;
    goto v_5;
v_7:
    v_14 = v_15;
    {
        fn = basic_elt(env, 2); // bf2flck
        return (*qfn1(fn))(fn, v_14);
    }
    v_14 = nil;
v_5:
    return onevalue(v_14);
}



// Code for vp2

static LispObject CC_vp2(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_22, v_23;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_23 = nil;
v_7:
    v_22 = stack[0];
    if (v_22 == nil) goto v_10;
    else goto v_11;
v_10:
    v_22 = v_23;
    {
        fn = basic_elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_22);
    }
v_11:
    v_22 = (LispObject)0+TAG_FIXNUM; // 0
    v_22 = cons(v_22, v_23);
    env = stack[-1];
    v_23 = v_22;
    v_22 = stack[0];
    if (!car_legal(v_22)) v_22 = cdrerror(v_22); else
    v_22 = qcdr(v_22);
    stack[0] = v_22;
    goto v_7;
    v_22 = nil;
    return onevalue(v_22);
}



// Code for pasf_floor

static LispObject CC_pasf_floor(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_82, v_83, v_84;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_82 = stack[-1];
    if (!consp(v_82)) goto v_15;
    else goto v_16;
v_15:
    v_82 = lisp_true;
    goto v_14;
v_16:
    v_82 = stack[-1];
    if (!car_legal(v_82)) v_82 = carerror(v_82); else
    v_82 = qcar(v_82);
    v_82 = (consp(v_82) ? nil : lisp_true);
    goto v_14;
    v_82 = nil;
v_14:
    if (v_82 == nil) goto v_12;
    v_82 = stack[0];
    if (!consp(v_82)) goto v_26;
    else goto v_27;
v_26:
    v_82 = lisp_true;
    goto v_25;
v_27:
    v_82 = stack[0];
    if (!car_legal(v_82)) v_82 = carerror(v_82); else
    v_82 = qcar(v_82);
    v_82 = (consp(v_82) ? nil : lisp_true);
    goto v_25;
    v_82 = nil;
v_25:
    goto v_10;
v_12:
    v_82 = nil;
    goto v_10;
    v_82 = nil;
v_10:
    if (v_82 == nil) goto v_8;
    v_82 = stack[-1];
    if (v_82 == nil) goto v_40;
    else goto v_41;
v_40:
    v_82 = nil;
    goto v_39;
v_41:
    v_83 = stack[-1];
    v_82 = stack[0];
    v_83 = Cremainder(v_83, v_82);
    env = stack[-2];
    v_82 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_83 == v_82) goto v_49;
    else goto v_50;
v_49:
    v_83 = stack[-1];
    v_82 = stack[0];
    v_82 = quot2(v_83, v_82);
    env = stack[-2];
    goto v_48;
v_50:
    v_83 = stack[-1];
    v_82 = stack[0];
    v_83 = times2(v_83, v_82);
    env = stack[-2];
    v_82 = (LispObject)0+TAG_FIXNUM; // 0
    v_82 = (LispObject)greaterp2(v_83, v_82);
    v_82 = v_82 ? lisp_true : nil;
    env = stack[-2];
    if (v_82 == nil) goto v_59;
    v_83 = stack[-1];
    v_82 = stack[0];
    v_82 = quot2(v_83, v_82);
    env = stack[-2];
    goto v_48;
v_59:
    v_83 = stack[-1];
    v_82 = stack[0];
    v_82 = quot2(v_83, v_82);
    env = stack[-2];
    v_82 = sub1(v_82);
    env = stack[-2];
    goto v_48;
    v_82 = nil;
v_48:
    fn = basic_elt(env, 2); // simp
    v_82 = (*qfn1(fn))(fn, v_82);
    if (!car_legal(v_82)) v_82 = carerror(v_82); else
    v_82 = qcar(v_82);
    goto v_39;
    v_82 = nil;
v_39:
    goto v_6;
v_8:
    v_84 = basic_elt(env, 1); // "pasf_floor: not a domain valued sf in input"
    v_83 = stack[-1];
    v_82 = stack[0];
    v_82 = list3(v_84, v_83, v_82);
    env = stack[-2];
    {
        fn = basic_elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_82);
    }
    v_82 = nil;
v_6:
    return onevalue(v_82);
}



// Code for dip_ilcomb2r

static LispObject CC_dip_ilcomb2r(LispObject env, LispObject v_2,
                         LispObject v_3, LispObject v_4, LispObject _a4up_)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_149, v_150, v_151;
    LispObject fn;
    LispObject v_5, v_6, v_7, v_8;
    if (_a4up_ == nil)
        aerror1("not enough arguments provided", basic_elt(env, 0));
    v_5 = qcar(_a4up_); _a4up_ = qcdr(_a4up_);
    if (_a4up_ == nil)
        aerror1("not enough arguments provided", basic_elt(env, 0));
    v_6 = qcar(_a4up_); _a4up_ = qcdr(_a4up_);
    if (_a4up_ == nil)
        aerror1("not enough arguments provided", basic_elt(env, 0));
    v_7 = qcar(_a4up_); _a4up_ = qcdr(_a4up_);
    if (_a4up_ == nil)
        aerror1("not enough arguments provided", basic_elt(env, 0));
    v_8 = qcar(_a4up_); _a4up_ = qcdr(_a4up_);
    if (_a4up_ != nil)
        aerror1("too many arguments provided", basic_elt(env, 0));
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push6(v_2,v_3,v_4,v_5,v_6,v_7);
        push(v_8);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_8,v_7,v_6,v_5,v_4,v_3);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[0] = v_8;
    stack[-1] = v_7;
    stack[-2] = v_6;
    stack[-3] = v_5;
    stack[-4] = v_4;
    stack[-5] = v_3;
    stack[-6] = v_2;
// end of prologue
    stack[-7] = nil;
v_16:
    v_149 = stack[-1];
    if (v_149 == nil) goto v_19;
    v_150 = stack[-4];
    v_149 = stack[-2];
    fn = basic_elt(env, 1); // ev_comp
    v_150 = (*qfn2(fn))(fn, v_150, v_149);
    env = stack[-8];
    stack[-7] = v_150;
    v_149 = (LispObject)-16+TAG_FIXNUM; // -1
    fn = basic_elt(env, 2); // iequal
    v_149 = (*qfn2(fn))(fn, v_150, v_149);
    env = stack[-8];
    if (v_149 == nil) goto v_19;
    goto v_20;
v_19:
    goto v_15;
v_20:
    v_151 = stack[-3];
    v_150 = stack[-2];
    v_149 = stack[-6];
    v_149 = list2star(v_151, v_150, v_149);
    env = stack[-8];
    stack[-6] = v_149;
    v_149 = stack[-1];
    if (!car_legal(v_149)) v_149 = carerror(v_149); else
    v_149 = qcar(v_149);
    stack[-2] = v_149;
    v_149 = stack[-1];
    if (!car_legal(v_149)) v_149 = cdrerror(v_149); else
    v_149 = qcdr(v_149);
    stack[-1] = v_149;
    v_149 = stack[-1];
    if (!car_legal(v_149)) v_150 = carerror(v_149); else
    v_150 = qcar(v_149);
    v_149 = stack[0];
    fn = basic_elt(env, 3); // bc_prod
    v_149 = (*qfn2(fn))(fn, v_150, v_149);
    env = stack[-8];
    stack[-3] = v_149;
    v_149 = stack[-1];
    if (!car_legal(v_149)) v_149 = cdrerror(v_149); else
    v_149 = qcdr(v_149);
    stack[-1] = v_149;
    goto v_16;
v_15:
    v_149 = stack[-1];
    if (v_149 == nil) goto v_47;
    v_150 = stack[-7];
    v_149 = (LispObject)16+TAG_FIXNUM; // 1
    fn = basic_elt(env, 2); // iequal
    v_149 = (*qfn2(fn))(fn, v_150, v_149);
    env = stack[-8];
    if (v_149 == nil) goto v_52;
    v_151 = stack[-5];
    v_150 = stack[-4];
    v_149 = stack[-6];
    v_149 = list2star(v_151, v_150, v_149);
    env = stack[-8];
    v_149 = list2star(stack[-3], stack[-2], v_149);
    env = stack[-8];
    stack[-6] = v_149;
    goto v_50;
v_52:
    v_150 = stack[-5];
    v_149 = stack[-3];
    fn = basic_elt(env, 4); // bc_sum
    v_149 = (*qfn2(fn))(fn, v_150, v_149);
    env = stack[-8];
    stack[-2] = v_149;
    v_149 = stack[-2];
    fn = basic_elt(env, 5); // bc_zero!?
    v_149 = (*qfn1(fn))(fn, v_149);
    env = stack[-8];
    if (v_149 == nil) goto v_70;
    else goto v_71;
v_70:
    v_151 = stack[-2];
    v_150 = stack[-4];
    v_149 = stack[-6];
    v_149 = list2star(v_151, v_150, v_149);
    env = stack[-8];
    stack[-6] = v_149;
    goto v_69;
v_71:
v_69:
    goto v_50;
v_50:
v_80:
    v_149 = stack[-1];
    if (v_149 == nil) goto v_83;
    else goto v_84;
v_83:
    goto v_79;
v_84:
    v_149 = stack[-1];
    if (!car_legal(v_149)) v_150 = carerror(v_149); else
    v_150 = qcar(v_149);
    v_149 = stack[-6];
    v_149 = cons(v_150, v_149);
    env = stack[-8];
    stack[-6] = v_149;
    v_149 = stack[-1];
    if (!car_legal(v_149)) v_149 = cdrerror(v_149); else
    v_149 = qcdr(v_149);
    stack[-1] = v_149;
    v_149 = stack[-1];
    if (!car_legal(v_149)) v_150 = carerror(v_149); else
    v_150 = qcar(v_149);
    v_149 = stack[0];
    fn = basic_elt(env, 3); // bc_prod
    v_150 = (*qfn2(fn))(fn, v_150, v_149);
    env = stack[-8];
    v_149 = stack[-6];
    v_149 = cons(v_150, v_149);
    env = stack[-8];
    stack[-6] = v_149;
    v_149 = stack[-1];
    if (!car_legal(v_149)) v_149 = cdrerror(v_149); else
    v_149 = qcdr(v_149);
    stack[-1] = v_149;
    goto v_80;
v_79:
    v_149 = stack[-6];
        return Lnreverse(nil, v_149);
v_47:
    v_150 = stack[-4];
    v_149 = stack[-2];
    fn = basic_elt(env, 1); // ev_comp
    v_149 = (*qfn2(fn))(fn, v_150, v_149);
    env = stack[-8];
    stack[-7] = v_149;
    v_150 = stack[-7];
    v_149 = (LispObject)-16+TAG_FIXNUM; // -1
    fn = basic_elt(env, 2); // iequal
    v_149 = (*qfn2(fn))(fn, v_150, v_149);
    env = stack[-8];
    if (v_149 == nil) goto v_109;
    stack[0] = stack[-5];
    stack[-1] = stack[-4];
    v_151 = stack[-3];
    v_150 = stack[-2];
    v_149 = stack[-6];
    v_149 = list2star(v_151, v_150, v_149);
    env = stack[-8];
    v_149 = list2star(stack[0], stack[-1], v_149);
    stack[-6] = v_149;
    goto v_107;
v_109:
    v_150 = stack[-7];
    v_149 = (LispObject)16+TAG_FIXNUM; // 1
    fn = basic_elt(env, 2); // iequal
    v_149 = (*qfn2(fn))(fn, v_150, v_149);
    env = stack[-8];
    if (v_149 == nil) goto v_121;
    stack[0] = stack[-3];
    stack[-1] = stack[-2];
    v_151 = stack[-5];
    v_150 = stack[-4];
    v_149 = stack[-6];
    v_149 = list2star(v_151, v_150, v_149);
    env = stack[-8];
    v_149 = list2star(stack[0], stack[-1], v_149);
    stack[-6] = v_149;
    goto v_107;
v_121:
    v_150 = stack[-5];
    v_149 = stack[-3];
    fn = basic_elt(env, 4); // bc_sum
    v_149 = (*qfn2(fn))(fn, v_150, v_149);
    env = stack[-8];
    stack[-2] = v_149;
    v_149 = stack[-2];
    fn = basic_elt(env, 5); // bc_zero!?
    v_149 = (*qfn1(fn))(fn, v_149);
    env = stack[-8];
    if (v_149 == nil) goto v_139;
    else goto v_140;
v_139:
    v_151 = stack[-2];
    v_150 = stack[-4];
    v_149 = stack[-6];
    v_149 = list2star(v_151, v_150, v_149);
    stack[-6] = v_149;
    goto v_138;
v_140:
v_138:
    goto v_107;
v_107:
    v_149 = stack[-6];
        return Lnreverse(nil, v_149);
    return onevalue(v_149);
}



// Code for bvarrd

static LispObject CC_bvarrd(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_56, v_57;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// end of prologue
    fn = basic_elt(env, 9); // lex
    v_56 = (*qfn0(fn))(fn);
    env = stack[-3];
    v_57 = qvalue(basic_elt(env, 1)); // char
    v_56 = basic_elt(env, 2); // (d e g r e e)
    if (equal(v_57, v_56)) goto v_10;
    else goto v_11;
v_10:
    v_57 = basic_elt(env, 3); // "<bvar>"
    v_56 = (LispObject)240+TAG_FIXNUM; // 15
    fn = basic_elt(env, 10); // errorml
    v_56 = (*qfn2(fn))(fn, v_57, v_56);
    env = stack[-3];
    goto v_9;
v_11:
v_9:
    fn = basic_elt(env, 11); // mathml2
    v_56 = (*qfn0(fn))(fn);
    env = stack[-3];
    stack[0] = v_56;
    fn = basic_elt(env, 9); // lex
    v_56 = (*qfn0(fn))(fn);
    env = stack[-3];
    v_57 = qvalue(basic_elt(env, 1)); // char
    v_56 = basic_elt(env, 2); // (d e g r e e)
    if (equal(v_57, v_56)) goto v_21;
    else goto v_22;
v_21:
    fn = basic_elt(env, 12); // mathml
    v_56 = (*qfn0(fn))(fn);
    env = stack[-3];
    stack[-2] = v_56;
    fn = basic_elt(env, 9); // lex
    v_56 = (*qfn0(fn))(fn);
    env = stack[-3];
    v_57 = qvalue(basic_elt(env, 1)); // char
    v_56 = basic_elt(env, 4); // (!/ d e g r e e)
    if (equal(v_57, v_56)) goto v_30;
    v_57 = basic_elt(env, 5); // "</degree>"
    v_56 = (LispObject)32+TAG_FIXNUM; // 2
    fn = basic_elt(env, 13); // error
    v_56 = (*qfn2(fn))(fn, v_57, v_56);
    env = stack[-3];
    goto v_28;
v_30:
v_28:
    fn = basic_elt(env, 9); // lex
    v_56 = (*qfn0(fn))(fn);
    env = stack[-3];
    goto v_20;
v_22:
    v_56 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_56;
    goto v_20;
v_20:
    v_57 = qvalue(basic_elt(env, 1)); // char
    v_56 = basic_elt(env, 6); // (!/ b v a r)
    if (equal(v_57, v_56)) goto v_42;
    else goto v_43;
v_42:
    stack[-1] = basic_elt(env, 7); // bvar
    v_56 = stack[-2];
    v_56 = ncons(v_56);
    {
        LispObject v_61 = stack[-1];
        LispObject v_62 = stack[0];
        return list2star(v_61, v_62, v_56);
    }
v_43:
    v_57 = basic_elt(env, 8); // "</bvar>"
    v_56 = (LispObject)32+TAG_FIXNUM; // 2
    fn = basic_elt(env, 10); // errorml
    v_56 = (*qfn2(fn))(fn, v_57, v_56);
    goto v_41;
v_41:
    v_56 = nil;
    return onevalue(v_56);
}



// Code for prop!-simp

static LispObject CC_propKsimp(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_12, v_13;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_12 = v_3;
    v_13 = v_2;
// end of prologue
    stack[-2] = v_13;
    stack[-1] = v_12;
    stack[0] = nil;
    v_13 = (LispObject)0+TAG_FIXNUM; // 0
    v_12 = (LispObject)16+TAG_FIXNUM; // 1
    v_12 = list2(v_13, v_12);
    env = stack[-3];
    {
        LispObject v_17 = stack[-2];
        LispObject v_18 = stack[-1];
        LispObject v_19 = stack[0];
        fn = basic_elt(env, 1); // prop!-simp1
        return (*qfn4up(fn))(fn, v_17, v_18, v_19, v_12);
    }
}



// Code for make_tuple_type

static LispObject CC_make_tuple_type(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_23, v_24;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_24 = v_2;
// end of prologue
    v_23 = v_24;
    if (v_23 == nil) goto v_6;
    else goto v_7;
v_6:
    v_23 = basic_elt(env, 1); // unit
    goto v_5;
v_7:
    v_23 = v_24;
    if (!car_legal(v_23)) v_23 = cdrerror(v_23); else
    v_23 = qcdr(v_23);
    if (v_23 == nil) goto v_10;
    else goto v_11;
v_10:
    v_23 = v_24;
    if (!car_legal(v_23)) v_23 = carerror(v_23); else
    v_23 = qcar(v_23);
    if (!car_legal(v_23)) v_23 = cdrerror(v_23); else
    v_23 = qcdr(v_23);
    goto v_5;
v_11:
    stack[0] = basic_elt(env, 2); // times
    v_23 = v_24;
    fn = basic_elt(env, 3); // collect_cdrs
    v_23 = (*qfn1(fn))(fn, v_23);
    {
        LispObject v_26 = stack[0];
        return cons(v_26, v_23);
    }
    v_23 = nil;
v_5:
    return onevalue(v_23);
}



// Code for arglength

static LispObject CC_arglength(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_30, v_31;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31 = v_2;
// end of prologue
// Binding !*intstr
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(basic_elt(env, 1)) = nil; // !*intstr
    v_30 = v_31;
    if (v_30 == nil) goto v_11;
    else goto v_12;
v_11:
    v_30 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8;
v_12:
    v_30 = lisp_true;
    qvalue(basic_elt(env, 1)) = v_30; // !*intstr
    v_30 = v_31;
    fn = basic_elt(env, 2); // reval
    v_30 = (*qfn1(fn))(fn, v_30);
    env = stack[-1];
    v_31 = v_30;
    v_30 = v_31;
    if (!consp(v_30)) goto v_20;
    else goto v_21;
v_20:
    v_30 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_19;
v_21:
    v_30 = v_31;
    if (!car_legal(v_30)) v_30 = cdrerror(v_30); else
    v_30 = qcdr(v_30);
    v_30 = Llength(nil, v_30);
    goto v_19;
    v_30 = nil;
v_19:
v_8:
    ;}  // end of a binding scope
    return onevalue(v_30);
}



// Code for list_is_all_free

static LispObject CC_list_is_all_free(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_23;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
v_6:
    v_23 = stack[0];
    if (v_23 == nil) goto v_9;
    else goto v_10;
v_9:
    v_23 = lisp_true;
    goto v_5;
v_10:
    v_23 = stack[0];
    if (!car_legal(v_23)) v_23 = carerror(v_23); else
    v_23 = qcar(v_23);
    fn = basic_elt(env, 1); // nodum_varp
    v_23 = (*qfn1(fn))(fn, v_23);
    env = stack[-1];
    if (v_23 == nil) goto v_14;
    v_23 = stack[0];
    if (!car_legal(v_23)) v_23 = cdrerror(v_23); else
    v_23 = qcdr(v_23);
    stack[0] = v_23;
    goto v_6;
v_14:
    v_23 = nil;
    goto v_5;
    v_23 = nil;
v_5:
    return onevalue(v_23);
}



// Code for derivative!-mod!-p!-1

static LispObject CC_derivativeKmodKpK1(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_74, v_75, v_76;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
    v_74 = stack[-2];
    if (!consp(v_74)) goto v_11;
    else goto v_12;
v_11:
    v_74 = lisp_true;
    goto v_10;
v_12:
    v_74 = stack[-2];
    if (!car_legal(v_74)) v_74 = carerror(v_74); else
    v_74 = qcar(v_74);
    v_74 = (consp(v_74) ? nil : lisp_true);
    goto v_10;
    v_74 = nil;
v_10:
    if (v_74 == nil) goto v_8;
    v_74 = nil;
    goto v_6;
v_8:
    v_74 = stack[-2];
    if (!car_legal(v_74)) v_74 = carerror(v_74); else
    v_74 = qcar(v_74);
    if (!car_legal(v_74)) v_74 = carerror(v_74); else
    v_74 = qcar(v_74);
    if (!car_legal(v_74)) v_75 = carerror(v_74); else
    v_75 = qcar(v_74);
    v_74 = stack[-1];
    if (equal(v_75, v_74)) goto v_22;
    v_74 = nil;
    goto v_6;
v_22:
    v_74 = stack[-2];
    if (!car_legal(v_74)) v_74 = carerror(v_74); else
    v_74 = qcar(v_74);
    if (!car_legal(v_74)) v_74 = carerror(v_74); else
    v_74 = qcar(v_74);
    if (!car_legal(v_74)) v_75 = cdrerror(v_74); else
    v_75 = qcdr(v_74);
    v_74 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_75 == v_74) goto v_29;
    else goto v_30;
v_29:
    v_74 = stack[-2];
    if (!car_legal(v_74)) v_74 = carerror(v_74); else
    v_74 = qcar(v_74);
    if (!car_legal(v_74)) v_74 = cdrerror(v_74); else
    v_74 = qcdr(v_74);
    goto v_6;
v_30:
    v_74 = stack[-2];
    if (!car_legal(v_74)) v_74 = carerror(v_74); else
    v_74 = qcar(v_74);
    if (!car_legal(v_74)) stack[0] = cdrerror(v_74); else
    stack[0] = qcdr(v_74);
    v_74 = stack[-2];
    if (!car_legal(v_74)) v_74 = carerror(v_74); else
    v_74 = qcar(v_74);
    if (!car_legal(v_74)) v_74 = carerror(v_74); else
    v_74 = qcar(v_74);
    if (!car_legal(v_74)) v_74 = cdrerror(v_74); else
    v_74 = qcdr(v_74);
    v_74 = Lmodular_number(nil, v_74);
    env = stack[-4];
    fn = basic_elt(env, 1); // multiply!-by!-constant!-mod!-p
    stack[0] = (*qfn2(fn))(fn, stack[0], v_74);
    env = stack[-4];
    v_74 = stack[-2];
    if (!car_legal(v_74)) v_75 = cdrerror(v_74); else
    v_75 = qcdr(v_74);
    v_74 = stack[-1];
    v_74 = CC_derivativeKmodKpK1(basic_elt(env, 0), v_75, v_74);
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v_74;
    v_74 = stack[-3];
    if (v_74 == nil) goto v_58;
    else goto v_59;
v_58:
    v_74 = stack[0];
    goto v_57;
v_59:
    v_75 = stack[-1];
    v_74 = stack[-2];
    if (!car_legal(v_74)) v_74 = carerror(v_74); else
    v_74 = qcar(v_74);
    if (!car_legal(v_74)) v_74 = carerror(v_74); else
    v_74 = qcar(v_74);
    if (!car_legal(v_74)) v_74 = cdrerror(v_74); else
    v_74 = qcdr(v_74);
    v_74 = (LispObject)((intptr_t)(v_74) - 0x10);
    fn = basic_elt(env, 2); // mksp
    v_76 = (*qfn2(fn))(fn, v_75, v_74);
    v_75 = stack[-3];
    v_74 = stack[0];
    return acons(v_76, v_75, v_74);
    v_74 = nil;
v_57:
    goto v_6;
    v_74 = nil;
v_6:
    return onevalue(v_74);
}



// Code for general!-horner!-rule!-mod!-p

static LispObject CC_generalKhornerKruleKmodKp(LispObject env, LispObject v_2,
                         LispObject v_3, LispObject v_4, LispObject _a4up_)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_108, v_109, v_110, v_111;
    LispObject fn;
    LispObject v_5, v_6;
    if (_a4up_ == nil)
        aerror1("not enough arguments provided", basic_elt(env, 0));
    v_5 = qcar(_a4up_); _a4up_ = qcdr(_a4up_);
    if (_a4up_ == nil)
        aerror1("not enough arguments provided", basic_elt(env, 0));
    v_6 = qcar(_a4up_); _a4up_ = qcdr(_a4up_);
    if (_a4up_ != nil)
        aerror1("too many arguments provided", basic_elt(env, 0));
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push5(v_2,v_3,v_4,v_5,v_6);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_6,v_5,v_4,v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_6;
    stack[-3] = v_5;
    stack[-4] = v_4;
    v_109 = v_3;
    v_110 = v_2;
// end of prologue
    v_108 = stack[-4];
    if (!consp(v_108)) goto v_18;
    else goto v_19;
v_18:
    v_108 = lisp_true;
    goto v_17;
v_19:
    v_108 = stack[-4];
    if (!car_legal(v_108)) v_108 = carerror(v_108); else
    v_108 = qcar(v_108);
    v_108 = (consp(v_108) ? nil : lisp_true);
    goto v_17;
    v_108 = nil;
v_17:
    if (v_108 == nil) goto v_15;
    v_108 = lisp_true;
    goto v_13;
v_15:
    v_108 = stack[-4];
    if (!car_legal(v_108)) v_108 = carerror(v_108); else
    v_108 = qcar(v_108);
    if (!car_legal(v_108)) v_108 = carerror(v_108); else
    v_108 = qcar(v_108);
    if (!car_legal(v_108)) v_111 = carerror(v_108); else
    v_111 = qcar(v_108);
    v_108 = stack[-2];
    v_108 = (equal(v_111, v_108) ? lisp_true : nil);
    v_108 = (v_108 == nil ? lisp_true : nil);
    goto v_13;
    v_108 = nil;
v_13:
    if (v_108 == nil) goto v_11;
    v_108 = stack[-3];
    if (v_108 == nil) goto v_43;
    else goto v_44;
v_43:
    v_108 = lisp_true;
    goto v_42;
v_44:
    v_108 = stack[-3];
    v_108 = (LispObject)zerop(v_108);
    v_108 = v_108 ? lisp_true : nil;
    env = stack[-6];
    goto v_42;
    v_108 = nil;
v_42:
    if (v_108 == nil) goto v_40;
    v_108 = stack[-4];
    goto v_38;
v_40:
    stack[0] = v_110;
    v_108 = stack[-3];
    fn = basic_elt(env, 1); // general!-expt!-mod!-p
    v_108 = (*qfn2(fn))(fn, v_108, v_109);
    env = stack[-6];
    fn = basic_elt(env, 2); // general!-times!-mod!-p
    v_108 = (*qfn2(fn))(fn, stack[0], v_108);
    env = stack[-6];
    v_110 = v_108;
    v_108 = stack[-4];
    v_109 = v_110;
    {
        fn = basic_elt(env, 3); // general!-plus!-mod!-p
        return (*qfn2(fn))(fn, v_108, v_109);
    }
    v_108 = nil;
v_38:
    goto v_9;
v_11:
    v_108 = stack[-4];
    if (!car_legal(v_108)) v_108 = carerror(v_108); else
    v_108 = qcar(v_108);
    if (!car_legal(v_108)) v_108 = carerror(v_108); else
    v_108 = qcar(v_108);
    if (!car_legal(v_108)) v_108 = cdrerror(v_108); else
    v_108 = qcdr(v_108);
    stack[-5] = v_108;
    v_108 = stack[-3];
    if (v_108 == nil) goto v_78;
    else goto v_79;
v_78:
    v_108 = lisp_true;
    goto v_77;
v_79:
    v_108 = stack[-3];
    v_108 = (LispObject)zerop(v_108);
    v_108 = v_108 ? lisp_true : nil;
    env = stack[-6];
    goto v_77;
    v_108 = nil;
v_77:
    if (v_108 == nil) goto v_75;
    v_108 = stack[-4];
    if (!car_legal(v_108)) v_108 = carerror(v_108); else
    v_108 = qcar(v_108);
    if (!car_legal(v_108)) v_108 = cdrerror(v_108); else
    v_108 = qcdr(v_108);
    stack[0] = v_108;
    goto v_73;
v_75:
    v_108 = stack[-4];
    if (!car_legal(v_108)) v_108 = carerror(v_108); else
    v_108 = qcar(v_108);
    if (!car_legal(v_108)) stack[-1] = cdrerror(v_108); else
    stack[-1] = qcdr(v_108);
    stack[0] = v_110;
    v_110 = stack[-3];
    v_108 = stack[-5];
    v_108 = (LispObject)(intptr_t)((intptr_t)v_109 - (intptr_t)v_108 + TAG_FIXNUM);
    fn = basic_elt(env, 1); // general!-expt!-mod!-p
    v_108 = (*qfn2(fn))(fn, v_110, v_108);
    env = stack[-6];
    fn = basic_elt(env, 2); // general!-times!-mod!-p
    v_108 = (*qfn2(fn))(fn, stack[0], v_108);
    env = stack[-6];
    fn = basic_elt(env, 3); // general!-plus!-mod!-p
    v_108 = (*qfn2(fn))(fn, stack[-1], v_108);
    env = stack[-6];
    stack[0] = v_108;
    goto v_73;
    stack[0] = nil;
v_73:
    stack[-1] = stack[-5];
    v_108 = stack[-4];
    if (!car_legal(v_108)) stack[-4] = cdrerror(v_108); else
    stack[-4] = qcdr(v_108);
    v_109 = stack[-3];
    v_108 = stack[-2];
    v_108 = list2(v_109, v_108);
    env = stack[-6];
    {
        LispObject v_118 = stack[0];
        LispObject v_119 = stack[-1];
        LispObject v_120 = stack[-4];
        fn = basic_elt(env, 0); // general!-horner!-rule!-mod!-p
        return (*qfn4up(fn))(fn, v_118, v_119, v_120, v_108);
    }
    goto v_9;
    v_108 = nil;
v_9:
    return onevalue(v_108);
}



// Code for comb

static LispObject CC_comb(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_75, v_76, v_77;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_3;
    stack[-4] = v_2;
// end of prologue
    stack[-5] = nil;
    v_76 = stack[-3];
    v_75 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_76 == v_75) goto v_13;
    else goto v_14;
v_13:
    v_75 = nil;
    return ncons(v_75);
v_14:
    v_75 = stack[-4];
    v_76 = Llength(nil, v_75);
    env = stack[-6];
    v_75 = stack[-3];
    v_76 = difference2(v_76, v_75);
    env = stack[-6];
    stack[-2] = v_76;
    v_75 = (LispObject)0+TAG_FIXNUM; // 0
    v_75 = (LispObject)lessp2(v_76, v_75);
    v_75 = v_75 ? lisp_true : nil;
    env = stack[-6];
    if (v_75 == nil) goto v_20;
    v_75 = nil;
    goto v_9;
v_20:
    v_75 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_75;
v_31:
    v_76 = stack[-2];
    v_75 = stack[-1];
    v_75 = difference2(v_76, v_75);
    env = stack[-6];
    v_75 = Lminusp(nil, v_75);
    env = stack[-6];
    if (v_75 == nil) goto v_36;
    goto v_30;
v_36:
    v_75 = stack[-4];
    if (!car_legal(v_75)) stack[0] = cdrerror(v_75); else
    stack[0] = qcdr(v_75);
    v_75 = stack[-3];
    v_75 = sub1(v_75);
    env = stack[-6];
    v_75 = CC_comb(basic_elt(env, 0), stack[0], v_75);
    env = stack[-6];
    stack[0] = v_75;
v_50:
    v_75 = stack[0];
    if (v_75 == nil) goto v_54;
    else goto v_55;
v_54:
    goto v_49;
v_55:
    v_75 = stack[0];
    if (!car_legal(v_75)) v_75 = carerror(v_75); else
    v_75 = qcar(v_75);
    v_76 = stack[-4];
    if (!car_legal(v_76)) v_77 = carerror(v_76); else
    v_77 = qcar(v_76);
    v_76 = v_75;
    v_75 = stack[-5];
    v_75 = acons(v_77, v_76, v_75);
    env = stack[-6];
    stack[-5] = v_75;
    v_75 = stack[0];
    if (!car_legal(v_75)) v_75 = cdrerror(v_75); else
    v_75 = qcdr(v_75);
    stack[0] = v_75;
    goto v_50;
v_49:
    v_75 = stack[-4];
    if (!car_legal(v_75)) v_75 = cdrerror(v_75); else
    v_75 = qcdr(v_75);
    stack[-4] = v_75;
    v_75 = stack[-1];
    v_75 = add1(v_75);
    env = stack[-6];
    stack[-1] = v_75;
    goto v_31;
v_30:
    v_76 = stack[-4];
    v_75 = stack[-5];
    return cons(v_76, v_75);
v_9:
    return onevalue(v_75);
}



// Code for gitimes!:

static LispObject CC_gitimesT(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_36, v_37, v_38, v_39;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_36 = v_3;
    v_37 = v_2;
// end of prologue
    v_38 = v_37;
    if (!car_legal(v_38)) v_38 = cdrerror(v_38); else
    v_38 = qcdr(v_38);
    if (!car_legal(v_38)) v_39 = carerror(v_38); else
    v_39 = qcar(v_38);
    if (!car_legal(v_37)) v_37 = cdrerror(v_37); else
    v_37 = qcdr(v_37);
    if (!car_legal(v_37)) v_38 = cdrerror(v_37); else
    v_38 = qcdr(v_37);
    v_37 = v_36;
    if (!car_legal(v_37)) v_37 = cdrerror(v_37); else
    v_37 = qcdr(v_37);
    if (!car_legal(v_37)) v_37 = carerror(v_37); else
    v_37 = qcar(v_37);
    if (!car_legal(v_36)) v_36 = cdrerror(v_36); else
    v_36 = qcdr(v_36);
    if (!car_legal(v_36)) v_36 = cdrerror(v_36); else
    v_36 = qcdr(v_36);
    stack[-4] = v_39;
    stack[-3] = v_38;
    stack[-2] = v_37;
    stack[-1] = v_36;
    v_37 = stack[-4];
    v_36 = stack[-2];
    stack[0] = times2(v_37, v_36);
    env = stack[-5];
    v_37 = stack[-3];
    v_36 = stack[-1];
    v_36 = times2(v_37, v_36);
    env = stack[-5];
    stack[0] = difference2(stack[0], v_36);
    env = stack[-5];
    v_37 = stack[-4];
    v_36 = stack[-1];
    stack[-1] = times2(v_37, v_36);
    env = stack[-5];
    v_37 = stack[-2];
    v_36 = stack[-3];
    v_36 = times2(v_37, v_36);
    env = stack[-5];
    v_36 = plus2(stack[-1], v_36);
    env = stack[-5];
    {
        LispObject v_45 = stack[0];
        fn = basic_elt(env, 1); // mkgi
        return (*qfn2(fn))(fn, v_45, v_36);
    }
}



// Code for !*a2f

static LispObject CC_Ha2f(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_7;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7 = v_2;
// end of prologue
    fn = basic_elt(env, 1); // simp!*
    v_7 = (*qfn1(fn))(fn, v_7);
    env = stack[0];
    {
        fn = basic_elt(env, 2); // !*q2f
        return (*qfn1(fn))(fn, v_7);
    }
}



// Code for multdfconst

static LispObject CC_multdfconst(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_41, v_42;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
    stack[-3] = nil;
v_8:
    v_41 = stack[-1];
    if (v_41 == nil) goto v_15;
    else goto v_16;
v_15:
    v_41 = lisp_true;
    goto v_14;
v_16:
    v_41 = stack[-2];
    if (!car_legal(v_41)) v_41 = carerror(v_41); else
    v_41 = qcar(v_41);
    v_41 = (v_41 == nil ? lisp_true : nil);
    goto v_14;
    v_41 = nil;
v_14:
    if (v_41 == nil) goto v_12;
    v_41 = stack[-3];
    {
        fn = basic_elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_41);
    }
v_12:
    v_41 = stack[-1];
    if (!car_legal(v_41)) v_41 = carerror(v_41); else
    v_41 = qcar(v_41);
    if (!car_legal(v_41)) stack[0] = carerror(v_41); else
    stack[0] = qcar(v_41);
    v_42 = stack[-2];
    v_41 = stack[-1];
    if (!car_legal(v_41)) v_41 = carerror(v_41); else
    v_41 = qcar(v_41);
    if (!car_legal(v_41)) v_41 = cdrerror(v_41); else
    v_41 = qcdr(v_41);
    fn = basic_elt(env, 2); // multsq
    v_41 = (*qfn2(fn))(fn, v_42, v_41);
    env = stack[-4];
    fn = basic_elt(env, 3); // subs2q
    v_42 = (*qfn1(fn))(fn, v_41);
    env = stack[-4];
    v_41 = stack[-3];
    v_41 = acons(stack[0], v_42, v_41);
    env = stack[-4];
    stack[-3] = v_41;
    v_41 = stack[-1];
    if (!car_legal(v_41)) v_41 = cdrerror(v_41); else
    v_41 = qcdr(v_41);
    stack[-1] = v_41;
    goto v_8;
    v_41 = nil;
    return onevalue(v_41);
}



// Code for ev_2a

static LispObject CC_ev_2a(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_7, v_8;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7 = v_2;
// end of prologue
    v_8 = v_7;
    v_7 = qvalue(basic_elt(env, 1)); // dip_vars!*
    {
        fn = basic_elt(env, 2); // ev_2a1
        return (*qfn2(fn))(fn, v_8, v_7);
    }
}



// Code for sets

static LispObject CC_sets(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_26, v_27;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_26 = basic_elt(env, 1); // "<apply>"
    fn = basic_elt(env, 5); // printout
    v_26 = (*qfn1(fn))(fn, v_26);
    env = stack[-2];
    v_26 = basic_elt(env, 2); // "<"
    v_26 = Lprinc(nil, v_26);
    env = stack[-2];
    v_26 = stack[0];
    v_26 = Lprinc(nil, v_26);
    env = stack[-2];
    v_26 = stack[-1];
    if (!car_legal(v_26)) v_27 = carerror(v_26); else
    v_27 = qcar(v_26);
    v_26 = basic_elt(env, 3); // "/"
    fn = basic_elt(env, 6); // attributesml
    v_26 = (*qfn2(fn))(fn, v_27, v_26);
    env = stack[-2];
    v_26 = lisp_true;
    fn = basic_elt(env, 7); // indent!*
    v_26 = (*qfn1(fn))(fn, v_26);
    env = stack[-2];
    v_26 = stack[-1];
    if (!car_legal(v_26)) v_26 = cdrerror(v_26); else
    v_26 = qcdr(v_26);
    fn = basic_elt(env, 8); // multi_elem
    v_26 = (*qfn1(fn))(fn, v_26);
    env = stack[-2];
    v_26 = nil;
    fn = basic_elt(env, 7); // indent!*
    v_26 = (*qfn1(fn))(fn, v_26);
    env = stack[-2];
    v_26 = basic_elt(env, 4); // "</apply>"
    fn = basic_elt(env, 5); // printout
    v_26 = (*qfn1(fn))(fn, v_26);
    v_26 = nil;
    return onevalue(v_26);
}



// Code for alg_plus

static LispObject CC_alg_plus(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_12, v_13, v_14;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12 = v_3;
    v_13 = v_2;
// end of prologue
    v_14 = basic_elt(env, 1); // plus
    v_12 = list3(v_14, v_13, v_12);
    env = stack[0];
    {
        fn = basic_elt(env, 2); // aeval
        return (*qfn1(fn))(fn, v_12);
    }
    return onevalue(v_12);
}



// Code for !*a2k

static LispObject CC_Ha2k(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_32, v_33;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_32 = stack[0];
    fn = basic_elt(env, 2); // simp!*
    v_32 = (*qfn1(fn))(fn, v_32);
    env = stack[-2];
    stack[-1] = v_32;
    fn = basic_elt(env, 3); // kernp
    v_32 = (*qfn1(fn))(fn, v_32);
    env = stack[-2];
    if (v_32 == nil) goto v_10;
    v_32 = stack[-1];
    if (!car_legal(v_32)) v_32 = carerror(v_32); else
    v_32 = qcar(v_32);
    if (!car_legal(v_32)) v_32 = carerror(v_32); else
    v_32 = qcar(v_32);
    if (!car_legal(v_32)) v_32 = carerror(v_32); else
    v_32 = qcar(v_32);
    if (!car_legal(v_32)) v_32 = carerror(v_32); else
    v_32 = qcar(v_32);
    goto v_6;
v_10:
    v_32 = stack[0];
    if (v_32 == nil) goto v_24;
    else goto v_25;
v_24:
    v_32 = (LispObject)0+TAG_FIXNUM; // 0
    v_33 = v_32;
    goto v_23;
v_25:
    v_32 = stack[0];
    v_33 = v_32;
    goto v_23;
    v_33 = nil;
v_23:
    v_32 = basic_elt(env, 1); // kernel
    fn = basic_elt(env, 4); // typerr
    v_32 = (*qfn2(fn))(fn, v_33, v_32);
    goto v_8;
v_8:
    v_32 = nil;
v_6:
    return onevalue(v_32);
}



// Code for matrixp

static LispObject CC_matrixp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_36, v_37, v_38;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_37 = v_2;
// end of prologue
    v_36 = v_37;
    v_36 = Lconsp(nil, v_36);
    env = stack[0];
    if (v_36 == nil) goto v_8;
    else goto v_9;
v_8:
    v_36 = v_37;
    fn = basic_elt(env, 3); // reval
    v_36 = (*qfn1(fn))(fn, v_36);
    env = stack[0];
    v_37 = v_36;
    goto v_7;
v_9:
v_7:
    v_38 = v_37;
    v_36 = basic_elt(env, 1); // mat
    if (!consp(v_38)) goto v_20;
    v_38 = qcar(v_38);
    if (v_38 == v_36) goto v_21;
v_20:
    v_36 = basic_elt(env, 2); // sparsemat
    v_36 = Leqcar(nil, v_37, v_36);
    v_36 = (v_36 == nil ? lisp_true : nil);
    goto v_19;
v_21:
    v_36 = nil;
    goto v_19;
    v_36 = nil;
v_19:
    if (v_36 == nil) goto v_17;
    v_36 = nil;
    goto v_5;
v_17:
    v_36 = lisp_true;
    goto v_5;
    v_36 = nil;
v_5:
    return onevalue(v_36);
}



// Code for amatch

static LispObject CC_amatch(LispObject env,
                         LispObject v_4, LispObject v_5,
                         LispObject v_6, LispObject _a4up_)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_92, v_93, v_94;
    LispObject fn;
    LispObject v_7;
    if (_a4up_ == nil)
        aerror1("not enough arguments provided", basic_elt(env, 0));
    v_7 = qcar(_a4up_); _a4up_ = qcdr(_a4up_);
    if (_a4up_ != nil)
        aerror1("too many arguments provided", basic_elt(env, 0));
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push4(v_4,v_5,v_6,v_7);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_7,v_6,v_5,v_4);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_7;
    stack[-5] = v_6;
    v_93 = v_5;
    v_92 = v_4;
// end of prologue
// Binding r
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
// Binding p
// FLUIDBIND: reloadenv=7 litvec-offset=2 saveloc=3
{   bind_fluid_stack bind_fluid_var(-7, 2, -3);
    qvalue(basic_elt(env, 1)) = v_92; // r
    v_92 = v_93;
    qvalue(basic_elt(env, 2)) = v_92; // p
v_20:
    v_92 = qvalue(basic_elt(env, 1)); // r
    if (!consp(v_92)) goto v_23;
    else goto v_24;
v_23:
    stack[-2] = nil;
    v_92 = qvalue(basic_elt(env, 1)); // r
    v_92 = ncons(v_92);
    env = stack[-7];
    fn = basic_elt(env, 5); // mval
    stack[-1] = (*qfn1(fn))(fn, v_92);
    env = stack[-7];
    v_92 = qvalue(basic_elt(env, 2)); // p
    stack[0] = ncons(v_92);
    env = stack[-7];
    v_93 = stack[-5];
    v_92 = stack[-4];
    v_92 = list2(v_93, v_92);
    env = stack[-7];
    fn = basic_elt(env, 6); // unify
    v_92 = (*qfn4up(fn))(fn, stack[-2], stack[-1], stack[0], v_92);
    goto v_19;
v_24:
    v_92 = qvalue(basic_elt(env, 2)); // p
    if (!consp(v_92)) goto v_40;
    else goto v_41;
v_40:
    v_92 = lisp_true;
    goto v_39;
v_41:
    v_92 = qvalue(basic_elt(env, 1)); // r
    if (!car_legal(v_92)) v_93 = carerror(v_92); else
    v_93 = qcar(v_92);
    v_92 = qvalue(basic_elt(env, 2)); // p
    if (!car_legal(v_92)) v_92 = carerror(v_92); else
    v_92 = qcar(v_92);
    v_92 = Lneq_2(nil, v_93, v_92);
    env = stack[-7];
    goto v_39;
    v_92 = nil;
v_39:
    if (v_92 == nil) goto v_36;
    else goto v_37;
v_36:
    v_92 = qvalue(basic_elt(env, 1)); // r
    if (!car_legal(v_92)) stack[-2] = carerror(v_92); else
    stack[-2] = qcar(v_92);
    v_92 = qvalue(basic_elt(env, 1)); // r
    if (!car_legal(v_92)) v_92 = cdrerror(v_92); else
    v_92 = qcdr(v_92);
    fn = basic_elt(env, 5); // mval
    stack[-1] = (*qfn1(fn))(fn, v_92);
    env = stack[-7];
    v_92 = qvalue(basic_elt(env, 2)); // p
    if (!car_legal(v_92)) stack[0] = cdrerror(v_92); else
    stack[0] = qcdr(v_92);
    v_93 = stack[-5];
    v_92 = stack[-4];
    v_92 = list2(v_93, v_92);
    env = stack[-7];
    fn = basic_elt(env, 6); // unify
    v_92 = (*qfn4up(fn))(fn, stack[-2], stack[-1], stack[0], v_92);
    goto v_19;
v_37:
    v_92 = qvalue(basic_elt(env, 1)); // r
    fn = basic_elt(env, 7); // suchp
    v_92 = (*qfn1(fn))(fn, v_92);
    env = stack[-7];
    if (v_92 == nil) goto v_63;
    v_92 = qvalue(basic_elt(env, 1)); // r
    if (!car_legal(v_92)) v_92 = cdrerror(v_92); else
    v_92 = qcdr(v_92);
    if (!car_legal(v_92)) v_92 = carerror(v_92); else
    v_92 = qcar(v_92);
    stack[0] = v_92;
    v_92 = qvalue(basic_elt(env, 1)); // r
    if (!car_legal(v_92)) v_92 = cdrerror(v_92); else
    v_92 = qcdr(v_92);
    if (!car_legal(v_92)) v_92 = cdrerror(v_92); else
    v_92 = qcdr(v_92);
    if (!car_legal(v_92)) v_93 = carerror(v_92); else
    v_93 = qcar(v_92);
    v_92 = stack[-5];
    v_92 = cons(v_93, v_92);
    env = stack[-7];
    stack[-5] = v_92;
    v_92 = stack[0];
    qvalue(basic_elt(env, 1)) = v_92; // r
    goto v_20;
v_63:
    v_92 = qvalue(basic_elt(env, 3)); // !*semantic
    if (v_92 == nil) goto v_77;
    v_94 = basic_elt(env, 4); // equal
    v_93 = qvalue(basic_elt(env, 1)); // r
    v_92 = qvalue(basic_elt(env, 2)); // p
    v_93 = list3(v_94, v_93, v_92);
    env = stack[-7];
    v_92 = stack[-5];
    v_93 = cons(v_93, v_92);
    env = stack[-7];
    v_92 = stack[-4];
    fn = basic_elt(env, 8); // resume
    v_92 = (*qfn2(fn))(fn, v_93, v_92);
    goto v_19;
v_77:
    v_92 = nil;
    goto v_19;
    v_92 = nil;
v_19:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_92);
}



// Code for groebnormalform

static LispObject CC_groebnormalform(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_12, v_13, v_14;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push3(v_2,v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_4,v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_12 = v_4;
    v_13 = v_3;
    v_14 = v_2;
// end of prologue
    stack[-2] = v_14;
    stack[-1] = v_13;
    stack[0] = v_12;
    v_12 = nil;
    v_12 = ncons(v_12);
    env = stack[-3];
    {
        LispObject v_18 = stack[-2];
        LispObject v_19 = stack[-1];
        LispObject v_20 = stack[0];
        fn = basic_elt(env, 1); // groebnormalform0
        return (*qfn4up(fn))(fn, v_18, v_19, v_20, v_12);
    }
}



// Code for evaluate!-horner

static LispObject CC_evaluateKhorner(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_32, v_33, v_34;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_2;
// end of prologue
    v_33 = stack[-1];
    v_32 = qvalue(basic_elt(env, 1)); // horner!-cache!*
    v_32 = Lassoc(nil, v_33, v_32);
    stack[-2] = v_32;
    v_32 = stack[-2];
    if (v_32 == nil) goto v_11;
    v_32 = stack[-2];
    if (!car_legal(v_32)) v_32 = cdrerror(v_32); else
    v_32 = qcdr(v_32);
    goto v_9;
v_11:
    v_32 = stack[-1];
    fn = basic_elt(env, 2); // simp!*
    v_32 = (*qfn1(fn))(fn, v_32);
    env = stack[-3];
    stack[-2] = v_32;
    v_32 = stack[-2];
    if (!car_legal(v_32)) v_32 = carerror(v_32); else
    v_32 = qcar(v_32);
    fn = basic_elt(env, 3); // hornerf
    stack[0] = (*qfn1(fn))(fn, v_32);
    env = stack[-3];
    v_32 = stack[-2];
    if (!car_legal(v_32)) v_32 = cdrerror(v_32); else
    v_32 = qcdr(v_32);
    fn = basic_elt(env, 3); // hornerf
    v_32 = (*qfn1(fn))(fn, v_32);
    env = stack[-3];
    v_32 = cons(stack[0], v_32);
    env = stack[-3];
    fn = basic_elt(env, 4); // prepsq
    v_32 = (*qfn1(fn))(fn, v_32);
    env = stack[-3];
    stack[-2] = v_32;
    v_34 = stack[-1];
    v_33 = stack[-2];
    v_32 = qvalue(basic_elt(env, 1)); // horner!-cache!*
    v_32 = acons(v_34, v_33, v_32);
    env = stack[-3];
    qvalue(basic_elt(env, 1)) = v_32; // horner!-cache!*
    v_32 = stack[-2];
    goto v_9;
    v_32 = nil;
v_9:
    return onevalue(v_32);
}



// Code for toolongexpp

static LispObject CC_toolongexpp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_8, v_9;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_8 = v_2;
// end of prologue
    fn = basic_elt(env, 2); // numprintlen
    v_8 = (*qfn1(fn))(fn, v_8);
    env = stack[0];
    v_9 = qvalue(basic_elt(env, 1)); // maxexpprintlen!*
        return Lgreaterp_2(nil, v_8, v_9);
}



// Code for find_buble

static LispObject CC_find_buble(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_24, v_25;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
v_1:
    v_24 = stack[0];
    if (v_24 == nil) goto v_7;
    else goto v_8;
v_7:
    v_24 = nil;
    goto v_6;
v_8:
    v_25 = stack[-1];
    v_24 = stack[0];
    if (!car_legal(v_24)) v_24 = carerror(v_24); else
    v_24 = qcar(v_24);
    fn = basic_elt(env, 1); // is_buble
    v_24 = (*qfn2(fn))(fn, v_25, v_24);
    env = stack[-2];
    if (v_24 == nil) goto v_15;
    else goto v_14;
v_15:
    v_25 = stack[-1];
    v_24 = stack[0];
    if (!car_legal(v_24)) v_24 = cdrerror(v_24); else
    v_24 = qcdr(v_24);
    stack[-1] = v_25;
    stack[0] = v_24;
    goto v_1;
v_14:
    goto v_6;
    v_24 = nil;
v_6:
    return onevalue(v_24);
}



// Code for log_assignment

static LispObject CC_log_assignment(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_84, v_85, v_86;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_3;
    v_85 = v_2;
// end of prologue
v_7:
    v_84 = stack[0];
    if (!consp(v_84)) goto v_14;
    else goto v_15;
v_14:
    v_84 = lisp_true;
    goto v_13;
v_15:
    v_86 = stack[0];
    v_84 = basic_elt(env, 1); // quote
    if (!consp(v_86)) goto v_23;
    v_86 = qcar(v_86);
    if (v_86 == v_84) goto v_22;
    else goto v_23;
v_22:
    v_84 = lisp_true;
    goto v_21;
v_23:
    v_86 = stack[0];
    v_84 = basic_elt(env, 2); // function
    v_84 = Leqcar(nil, v_86, v_84);
    env = stack[-1];
    goto v_21;
    v_84 = nil;
v_21:
    goto v_13;
    v_84 = nil;
v_13:
    if (v_84 == nil) goto v_11;
    v_84 = nil;
    goto v_6;
v_11:
    v_86 = stack[0];
    v_84 = basic_elt(env, 3); // setq
    if (!consp(v_86)) goto v_35;
    v_86 = qcar(v_86);
    if (v_86 == v_84) goto v_34;
    else goto v_35;
v_34:
    v_84 = stack[0];
    if (!car_legal(v_84)) v_84 = cdrerror(v_84); else
    v_84 = qcdr(v_84);
    if (!car_legal(v_84)) v_86 = carerror(v_84); else
    v_86 = qcar(v_84);
    v_84 = v_85;
    v_84 = Lmember(nil, v_86, v_84);
    if (v_84 == nil) goto v_42;
    v_84 = Lposn(nil);
    env = stack[-1];
    v_84 = (LispObject)zerop(v_84);
    v_84 = v_84 ? lisp_true : nil;
    env = stack[-1];
    if (v_84 == nil) goto v_50;
    else goto v_51;
v_50:
    v_84 = Lterpri(nil);
    env = stack[-1];
    goto v_49;
v_51:
v_49:
    v_84 = basic_elt(env, 4); // "+++ Assignment to parameter of inline: "
    v_84 = Lprinc(nil, v_84);
    env = stack[-1];
    v_84 = stack[0];
    v_84 = Lprint(nil, v_84);
    env = stack[-1];
    v_84 = basic_elt(env, 5); // "+++ Macro was: "
    v_84 = Lprinc(nil, v_84);
    env = stack[-1];
    v_84 = qvalue(basic_elt(env, 6)); // inlineinfo
    v_84 = Lprint(nil, v_84);
    v_84 = lisp_true;
    goto v_6;
v_42:
    v_84 = stack[0];
    if (!car_legal(v_84)) v_84 = cdrerror(v_84); else
    v_84 = qcdr(v_84);
    if (!car_legal(v_84)) v_84 = cdrerror(v_84); else
    v_84 = qcdr(v_84);
    if (!car_legal(v_84)) v_84 = carerror(v_84); else
    v_84 = qcar(v_84);
    stack[0] = v_84;
    goto v_7;
    goto v_9;
v_35:
    v_86 = stack[0];
    v_84 = basic_elt(env, 7); // cond
    if (!consp(v_86)) goto v_71;
    v_86 = qcar(v_86);
    if (v_86 == v_84) goto v_70;
    else goto v_71;
v_70:
    v_84 = stack[0];
    if (!car_legal(v_84)) v_84 = cdrerror(v_84); else
    v_84 = qcdr(v_84);
    {
        fn = basic_elt(env, 8); // log_assignment_list_list
        return (*qfn2(fn))(fn, v_85, v_84);
    }
v_71:
    v_84 = stack[0];
    {
        fn = basic_elt(env, 9); // log_assignment_list
        return (*qfn2(fn))(fn, v_85, v_84);
    }
v_9:
    v_84 = nil;
v_6:
    return onevalue(v_84);
}



// Code for fs!:onep!:

static LispObject CC_fsTonepT(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_7;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7 = v_2;
// end of prologue
    if (!car_legal(v_7)) v_7 = cdrerror(v_7); else
    v_7 = qcdr(v_7);
    {
        fn = basic_elt(env, 1); // fs!:onep
        return (*qfn1(fn))(fn, v_7);
    }
}



// Code for dummyp

static LispObject CC_dummyp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_91, v_92, v_93;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_2;
// end of prologue
    v_91 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_91;
    v_91 = stack[-3];
    fn = basic_elt(env, 4); // listp
    v_91 = (*qfn1(fn))(fn, v_91);
    env = stack[-5];
    if (v_91 == nil) goto v_14;
    v_92 = stack[-3];
    v_91 = basic_elt(env, 1); // minus
    if (!consp(v_92)) goto v_20;
    v_92 = qcar(v_92);
    if (v_92 == v_91) goto v_19;
    else goto v_20;
v_19:
    v_91 = stack[-3];
    if (!car_legal(v_91)) v_91 = cdrerror(v_91); else
    v_91 = qcdr(v_91);
    if (!car_legal(v_91)) v_91 = carerror(v_91); else
    v_91 = qcar(v_91);
    stack[-3] = v_91;
    goto v_18;
v_20:
    v_91 = nil;
    goto v_8;
v_18:
    goto v_12;
v_14:
v_12:
    v_91 = stack[-3];
    if (is_number(v_91)) goto v_32;
    v_91 = stack[-3];
    fn = basic_elt(env, 5); // !*id2num
    v_91 = (*qfn1(fn))(fn, v_91);
    env = stack[-5];
    if (v_91 == nil) goto v_36;
    else goto v_32;
v_36:
    goto v_33;
v_32:
    v_91 = nil;
    goto v_8;
v_33:
    v_91 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_91;
v_43:
    stack[0] = stack[-4];
    v_91 = qvalue(basic_elt(env, 2)); // g_dvnames
    fn = basic_elt(env, 6); // upbve
    v_91 = (*qfn1(fn))(fn, v_91);
    env = stack[-5];
    v_91 = (LispObject)lesseq2(stack[0], v_91);
    v_91 = v_91 ? lisp_true : nil;
    env = stack[-5];
    if (v_91 == nil) goto v_46;
    else goto v_47;
v_46:
    goto v_42;
v_47:
    stack[-1] = stack[-3];
    stack[0] = qvalue(basic_elt(env, 2)); // g_dvnames
    v_91 = stack[-4];
    v_91 = sub1(v_91);
    env = stack[-5];
    v_91 = Lgetv(nil, stack[0], v_91);
    env = stack[-5];
    if (equal(stack[-1], v_91)) goto v_55;
    else goto v_56;
v_55:
    v_91 = stack[-4];
    stack[-2] = v_91;
    v_91 = qvalue(basic_elt(env, 2)); // g_dvnames
    fn = basic_elt(env, 6); // upbve
    v_91 = (*qfn1(fn))(fn, v_91);
    env = stack[-5];
    v_91 = add1(v_91);
    env = stack[-5];
    stack[-4] = v_91;
    goto v_54;
v_56:
    v_91 = stack[-4];
    v_91 = add1(v_91);
    env = stack[-5];
    stack[-4] = v_91;
    goto v_54;
v_54:
    goto v_43;
v_42:
    v_92 = stack[-2];
    v_91 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_92 == v_91) goto v_73;
    else goto v_74;
v_73:
    v_91 = stack[-3];
    fn = basic_elt(env, 7); // ad_splitname
    v_91 = (*qfn1(fn))(fn, v_91);
    env = stack[-5];
    v_92 = v_91;
    v_91 = v_92;
    if (!car_legal(v_91)) v_91 = carerror(v_91); else
    v_91 = qcar(v_91);
    v_93 = qvalue(basic_elt(env, 3)); // g_dvbase
    if (v_91 == v_93) goto v_81;
    else goto v_82;
v_81:
    v_91 = v_92;
    if (!car_legal(v_91)) v_91 = cdrerror(v_91); else
    v_91 = qcdr(v_91);
    goto v_8;
v_82:
    goto v_72;
v_74:
    v_91 = stack[-2];
    goto v_8;
v_72:
    v_91 = nil;
v_8:
    return onevalue(v_91);
}



// Code for ratdif

static LispObject CC_ratdif(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_10, v_11;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10 = v_3;
    v_11 = v_2;
// end of prologue
    stack[0] = v_11;
    fn = basic_elt(env, 1); // ratminus
    v_11 = (*qfn1(fn))(fn, v_10);
    env = stack[-1];
    v_10 = nil;
    {
        LispObject v_13 = stack[0];
        fn = basic_elt(env, 2); // ratplusm
        return (*qfn3(fn))(fn, v_13, v_11, v_10);
    }
}



// Code for !*tayexp2q

static LispObject CC_Htayexp2q(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_25, v_26;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_26 = v_2;
// end of prologue
    v_25 = v_26;
    if (!consp(v_25)) goto v_6;
    else goto v_7;
v_6:
    v_25 = v_26;
    v_25 = (LispObject)zerop(v_25);
    v_25 = v_25 ? lisp_true : nil;
    if (v_25 == nil) goto v_13;
    v_25 = nil;
    v_26 = v_25;
    goto v_11;
v_13:
    v_25 = v_26;
    v_26 = v_25;
    goto v_11;
    v_26 = nil;
v_11:
    v_25 = (LispObject)16+TAG_FIXNUM; // 1
    return cons(v_26, v_25);
v_7:
    v_25 = v_26;
    if (!car_legal(v_25)) v_25 = cdrerror(v_25); else
    v_25 = qcdr(v_25);
    goto v_5;
    v_25 = nil;
v_5:
    return onevalue(v_25);
}



// Code for talp_sumd

static LispObject CC_talp_sumd(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_41, v_42;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_42 = v_2;
// end of prologue
    v_41 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_41;
    v_41 = v_42;
    if (!consp(v_41)) goto v_11;
    else goto v_12;
v_11:
    v_41 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7;
v_12:
    v_41 = v_42;
    fn = basic_elt(env, 1); // rl_atl
    v_41 = (*qfn1(fn))(fn, v_41);
    env = stack[-3];
    stack[-2] = v_41;
v_19:
    v_41 = stack[-2];
    if (v_41 == nil) goto v_22;
    else goto v_23;
v_22:
    goto v_18;
v_23:
    stack[-1] = stack[0];
    v_41 = stack[-2];
    if (!car_legal(v_41)) v_41 = carerror(v_41); else
    v_41 = qcar(v_41);
    fn = basic_elt(env, 2); // talp_arg2l
    v_41 = (*qfn1(fn))(fn, v_41);
    env = stack[-3];
    fn = basic_elt(env, 3); // talp_td
    stack[0] = (*qfn1(fn))(fn, v_41);
    env = stack[-3];
    v_41 = stack[-2];
    if (!car_legal(v_41)) v_41 = carerror(v_41); else
    v_41 = qcar(v_41);
    fn = basic_elt(env, 4); // talp_arg2r
    v_41 = (*qfn1(fn))(fn, v_41);
    env = stack[-3];
    fn = basic_elt(env, 3); // talp_td
    v_41 = (*qfn1(fn))(fn, v_41);
    env = stack[-3];
    v_41 = plus2(stack[0], v_41);
    env = stack[-3];
    v_41 = plus2(stack[-1], v_41);
    env = stack[-3];
    stack[0] = v_41;
    v_41 = stack[-2];
    if (!car_legal(v_41)) v_41 = cdrerror(v_41); else
    v_41 = qcdr(v_41);
    stack[-2] = v_41;
    goto v_19;
v_18:
    v_41 = stack[0];
v_7:
    return onevalue(v_41);
}



// Code for pasf_cein

static LispObject CC_pasf_cein(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_162, v_163;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_2;
// end of prologue
    v_163 = stack[-3];
    v_162 = basic_elt(env, 1); // true
    if (v_163 == v_162) goto v_18;
    else goto v_19;
v_18:
    v_162 = lisp_true;
    goto v_17;
v_19:
    v_163 = stack[-3];
    v_162 = basic_elt(env, 2); // false
    v_162 = (v_163 == v_162 ? lisp_true : nil);
    goto v_17;
    v_162 = nil;
v_17:
    if (v_162 == nil) goto v_15;
    v_162 = lisp_true;
    goto v_13;
v_15:
    v_163 = stack[-3];
    v_162 = basic_elt(env, 1); // true
    if (v_163 == v_162) goto v_37;
    else goto v_38;
v_37:
    v_162 = lisp_true;
    goto v_36;
v_38:
    v_163 = stack[-3];
    v_162 = basic_elt(env, 2); // false
    v_162 = (v_163 == v_162 ? lisp_true : nil);
    goto v_36;
    v_162 = nil;
v_36:
    if (v_162 == nil) goto v_34;
    v_162 = stack[-3];
    v_163 = v_162;
    goto v_32;
v_34:
    v_162 = stack[-3];
    if (!car_legal(v_162)) v_162 = carerror(v_162); else
    v_162 = qcar(v_162);
    v_162 = Lconsp(nil, v_162);
    env = stack[-5];
    if (v_162 == nil) goto v_49;
    v_162 = stack[-3];
    if (!car_legal(v_162)) v_162 = carerror(v_162); else
    v_162 = qcar(v_162);
    if (!car_legal(v_162)) v_162 = carerror(v_162); else
    v_162 = qcar(v_162);
    v_163 = v_162;
    goto v_32;
v_49:
    v_162 = stack[-3];
    if (!car_legal(v_162)) v_162 = carerror(v_162); else
    v_162 = qcar(v_162);
    v_163 = v_162;
    goto v_32;
    v_163 = nil;
v_32:
    v_162 = basic_elt(env, 3); // (leq greaterp geq lessp)
    v_162 = Lmemq(nil, v_163, v_162);
    v_162 = (v_162 == nil ? lisp_true : nil);
    goto v_13;
    v_162 = nil;
v_13:
    if (v_162 == nil) goto v_11;
    v_162 = stack[-3];
    goto v_7;
v_11:
    v_162 = stack[-3];
    if (!car_legal(v_162)) v_162 = cdrerror(v_162); else
    v_162 = qcdr(v_162);
    if (!car_legal(v_162)) v_162 = carerror(v_162); else
    v_162 = qcar(v_162);
    fn = basic_elt(env, 6); // pasf_deci
    v_162 = (*qfn1(fn))(fn, v_162);
    env = stack[-5];
    stack[-2] = v_162;
    v_162 = stack[-2];
    if (!car_legal(v_162)) v_162 = carerror(v_162); else
    v_162 = qcar(v_162);
    fn = basic_elt(env, 7); // sfto_dcontentf
    v_162 = (*qfn1(fn))(fn, v_162);
    env = stack[-5];
    stack[-4] = v_162;
    v_162 = stack[-3];
    if (!car_legal(v_162)) stack[-1] = carerror(v_162); else
    stack[-1] = qcar(v_162);
    v_162 = stack[-2];
    if (!car_legal(v_162)) stack[0] = carerror(v_162); else
    stack[0] = qcar(v_162);
    v_162 = stack[-4];
    fn = basic_elt(env, 8); // simp
    v_162 = (*qfn1(fn))(fn, v_162);
    env = stack[-5];
    if (!car_legal(v_162)) v_162 = carerror(v_162); else
    v_162 = qcar(v_162);
    fn = basic_elt(env, 9); // quotfx
    stack[0] = (*qfn2(fn))(fn, stack[0], v_162);
    env = stack[-5];
    v_163 = stack[-3];
    v_162 = basic_elt(env, 1); // true
    if (v_163 == v_162) goto v_91;
    else goto v_92;
v_91:
    v_162 = lisp_true;
    goto v_90;
v_92:
    v_163 = stack[-3];
    v_162 = basic_elt(env, 2); // false
    v_162 = (v_163 == v_162 ? lisp_true : nil);
    goto v_90;
    v_162 = nil;
v_90:
    if (v_162 == nil) goto v_88;
    v_162 = stack[-3];
    v_163 = v_162;
    goto v_86;
v_88:
    v_162 = stack[-3];
    if (!car_legal(v_162)) v_162 = carerror(v_162); else
    v_162 = qcar(v_162);
    v_162 = Lconsp(nil, v_162);
    env = stack[-5];
    if (v_162 == nil) goto v_103;
    v_162 = stack[-3];
    if (!car_legal(v_162)) v_162 = carerror(v_162); else
    v_162 = qcar(v_162);
    if (!car_legal(v_162)) v_162 = carerror(v_162); else
    v_162 = qcar(v_162);
    v_163 = v_162;
    goto v_86;
v_103:
    v_162 = stack[-3];
    if (!car_legal(v_162)) v_162 = carerror(v_162); else
    v_162 = qcar(v_162);
    v_163 = v_162;
    goto v_86;
    v_163 = nil;
v_86:
    v_162 = basic_elt(env, 4); // (leq greaterp)
    v_162 = Lmemq(nil, v_163, v_162);
    if (v_162 == nil) goto v_84;
    v_162 = stack[-2];
    if (!car_legal(v_162)) v_162 = cdrerror(v_162); else
    v_162 = qcdr(v_162);
    v_163 = negate(v_162);
    env = stack[-5];
    v_162 = stack[-4];
    fn = basic_elt(env, 10); // pasf_floor
    v_162 = (*qfn2(fn))(fn, v_163, v_162);
    env = stack[-5];
    fn = basic_elt(env, 11); // negf
    v_162 = (*qfn1(fn))(fn, v_162);
    env = stack[-5];
    goto v_82;
v_84:
    v_163 = stack[-3];
    v_162 = basic_elt(env, 1); // true
    if (v_163 == v_162) goto v_130;
    else goto v_131;
v_130:
    v_162 = lisp_true;
    goto v_129;
v_131:
    v_163 = stack[-3];
    v_162 = basic_elt(env, 2); // false
    v_162 = (v_163 == v_162 ? lisp_true : nil);
    goto v_129;
    v_162 = nil;
v_129:
    if (v_162 == nil) goto v_127;
    v_162 = stack[-3];
    v_163 = v_162;
    goto v_125;
v_127:
    v_162 = stack[-3];
    if (!car_legal(v_162)) v_162 = carerror(v_162); else
    v_162 = qcar(v_162);
    v_162 = Lconsp(nil, v_162);
    env = stack[-5];
    if (v_162 == nil) goto v_142;
    v_162 = stack[-3];
    if (!car_legal(v_162)) v_162 = carerror(v_162); else
    v_162 = qcar(v_162);
    if (!car_legal(v_162)) v_162 = carerror(v_162); else
    v_162 = qcar(v_162);
    v_163 = v_162;
    goto v_125;
v_142:
    v_162 = stack[-3];
    if (!car_legal(v_162)) v_162 = carerror(v_162); else
    v_162 = qcar(v_162);
    v_163 = v_162;
    goto v_125;
    v_163 = nil;
v_125:
    v_162 = basic_elt(env, 5); // (geq lessp)
    v_162 = Lmemq(nil, v_163, v_162);
    if (v_162 == nil) goto v_123;
    v_162 = stack[-2];
    if (!car_legal(v_162)) v_162 = cdrerror(v_162); else
    v_162 = qcdr(v_162);
    v_163 = negate(v_162);
    env = stack[-5];
    v_162 = stack[-4];
    fn = basic_elt(env, 12); // pasf_ceil
    v_162 = (*qfn2(fn))(fn, v_163, v_162);
    env = stack[-5];
    fn = basic_elt(env, 11); // negf
    v_162 = (*qfn1(fn))(fn, v_162);
    env = stack[-5];
    goto v_82;
v_123:
    v_162 = nil;
v_82:
    fn = basic_elt(env, 13); // addf
    v_163 = (*qfn2(fn))(fn, stack[0], v_162);
    v_162 = nil;
    {
        LispObject v_169 = stack[-1];
        return list3(v_169, v_163, v_162);
    }
v_7:
    return onevalue(v_162);
}



// Code for mapcarcar

static LispObject CC_mapcarcar(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_41;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_41 = v_2;
// end of prologue
    stack[-3] = v_41;
    v_41 = stack[-3];
    if (v_41 == nil) goto v_13;
    else goto v_14;
v_13:
    v_41 = nil;
    goto v_8;
v_14:
    v_41 = stack[-3];
    if (!car_legal(v_41)) v_41 = carerror(v_41); else
    v_41 = qcar(v_41);
    if (!car_legal(v_41)) v_41 = carerror(v_41); else
    v_41 = qcar(v_41);
    v_41 = ncons(v_41);
    env = stack[-4];
    stack[-1] = v_41;
    stack[-2] = v_41;
v_9:
    v_41 = stack[-3];
    if (!car_legal(v_41)) v_41 = cdrerror(v_41); else
    v_41 = qcdr(v_41);
    stack[-3] = v_41;
    v_41 = stack[-3];
    if (v_41 == nil) goto v_27;
    else goto v_28;
v_27:
    v_41 = stack[-2];
    goto v_8;
v_28:
    stack[0] = stack[-1];
    v_41 = stack[-3];
    if (!car_legal(v_41)) v_41 = carerror(v_41); else
    v_41 = qcar(v_41);
    if (!car_legal(v_41)) v_41 = carerror(v_41); else
    v_41 = qcar(v_41);
    v_41 = ncons(v_41);
    env = stack[-4];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    qcdr(stack[0]) = v_41;
    v_41 = stack[-1];
    if (!car_legal(v_41)) v_41 = cdrerror(v_41); else
    v_41 = qcdr(v_41);
    stack[-1] = v_41;
    goto v_9;
v_8:
    return onevalue(v_41);
}



// Code for matrixom

static LispObject CC_matrixom(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_22;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_22 = basic_elt(env, 1); // "<OMA>"
    fn = basic_elt(env, 4); // printout
    v_22 = (*qfn1(fn))(fn, v_22);
    env = stack[-1];
    v_22 = lisp_true;
    fn = basic_elt(env, 5); // indent!*
    v_22 = (*qfn1(fn))(fn, v_22);
    env = stack[-1];
    v_22 = basic_elt(env, 2); // "<OMS cd=""linalg1"" name=""matrix""/>"
    fn = basic_elt(env, 4); // printout
    v_22 = (*qfn1(fn))(fn, v_22);
    env = stack[-1];
    v_22 = stack[0];
    if (!car_legal(v_22)) v_22 = cdrerror(v_22); else
    v_22 = qcdr(v_22);
    if (!car_legal(v_22)) v_22 = cdrerror(v_22); else
    v_22 = qcdr(v_22);
    if (!car_legal(v_22)) v_22 = cdrerror(v_22); else
    v_22 = qcdr(v_22);
    if (!car_legal(v_22)) v_22 = carerror(v_22); else
    v_22 = qcar(v_22);
    fn = basic_elt(env, 6); // matrixrowom
    v_22 = (*qfn1(fn))(fn, v_22);
    env = stack[-1];
    v_22 = nil;
    fn = basic_elt(env, 5); // indent!*
    v_22 = (*qfn1(fn))(fn, v_22);
    env = stack[-1];
    v_22 = basic_elt(env, 3); // "</OMA>"
    fn = basic_elt(env, 4); // printout
    v_22 = (*qfn1(fn))(fn, v_22);
    v_22 = nil;
    return onevalue(v_22);
}



// Code for close_forall

static LispObject CC_close_forall(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_13, v_14;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
    stack_popper stack_popper_var(1);
// end of prologue
    v_14 = qvalue(basic_elt(env, 1)); // flagg
    v_13 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_14 == v_13) goto v_7;
    else goto v_8;
v_7:
    v_13 = basic_elt(env, 2); // "</apply>"
    fn = basic_elt(env, 3); // printout
    v_13 = (*qfn1(fn))(fn, v_13);
    goto v_6;
v_8:
v_6:
    v_13 = nil;
    return onevalue(v_13);
}



// Code for evload

static LispObject CC_evload(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_20;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
v_8:
    v_20 = stack[0];
    if (v_20 == nil) goto v_11;
    else goto v_12;
v_11:
    goto v_7;
v_12:
    v_20 = stack[0];
    if (!car_legal(v_20)) v_20 = carerror(v_20); else
    v_20 = qcar(v_20);
    v_20 = Lload_module(nil, v_20);
    env = stack[-1];
    v_20 = stack[0];
    if (!car_legal(v_20)) v_20 = cdrerror(v_20); else
    v_20 = qcdr(v_20);
    stack[0] = v_20;
    goto v_8;
v_7:
    v_20 = nil;
    return onevalue(v_20);
}



// Code for difference!:

static LispObject CC_differenceT(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_69, v_70, v_71, v_72;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_71 = v_3;
    v_72 = v_2;
// end of prologue
    v_69 = v_72;
    if (!car_legal(v_69)) v_69 = cdrerror(v_69); else
    v_69 = qcdr(v_69);
    if (!car_legal(v_69)) v_70 = carerror(v_69); else
    v_70 = qcar(v_69);
    stack[-1] = v_70;
    v_69 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_70 == v_69) goto v_14;
    else goto v_15;
v_14:
    v_69 = v_71;
    {
        fn = basic_elt(env, 2); // minus!:
        return (*qfn1(fn))(fn, v_69);
    }
v_15:
    v_69 = v_71;
    if (!car_legal(v_69)) v_69 = cdrerror(v_69); else
    v_69 = qcdr(v_69);
    if (!car_legal(v_69)) v_70 = carerror(v_69); else
    v_70 = qcar(v_69);
    stack[0] = v_70;
    v_69 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_70 == v_69) goto v_22;
    else goto v_23;
v_22:
    v_69 = v_72;
    goto v_13;
v_23:
    v_69 = v_72;
    if (!car_legal(v_69)) v_69 = cdrerror(v_69); else
    v_69 = qcdr(v_69);
    if (!car_legal(v_69)) v_69 = cdrerror(v_69); else
    v_69 = qcdr(v_69);
    stack[-4] = v_69;
    v_70 = v_71;
    if (!car_legal(v_70)) v_70 = cdrerror(v_70); else
    v_70 = qcdr(v_70);
    if (!car_legal(v_70)) v_70 = cdrerror(v_70); else
    v_70 = qcdr(v_70);
    stack[-2] = v_70;
    v_70 = difference2(v_69, v_70);
    env = stack[-5];
    stack[-3] = v_70;
    v_69 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_70 == v_69) goto v_29;
    else goto v_30;
v_29:
    stack[-2] = basic_elt(env, 1); // !:rd!:
    v_70 = stack[-1];
    v_69 = stack[0];
    v_70 = difference2(v_70, v_69);
    v_69 = stack[-4];
    {
        LispObject v_78 = stack[-2];
        return list2star(v_78, v_70, v_69);
    }
v_30:
    v_70 = stack[-3];
    v_69 = (LispObject)0+TAG_FIXNUM; // 0
    v_69 = (LispObject)greaterp2(v_70, v_69);
    v_69 = v_69 ? lisp_true : nil;
    env = stack[-5];
    if (v_69 == nil) goto v_46;
    stack[-4] = basic_elt(env, 1); // !:rd!:
    v_70 = stack[-1];
    v_69 = stack[-3];
    fn = basic_elt(env, 3); // ashift
    v_70 = (*qfn2(fn))(fn, v_70, v_69);
    env = stack[-5];
    v_69 = stack[0];
    v_70 = difference2(v_70, v_69);
    v_69 = stack[-2];
    {
        LispObject v_79 = stack[-4];
        return list2star(v_79, v_70, v_69);
    }
v_46:
    stack[-2] = basic_elt(env, 1); // !:rd!:
    v_69 = stack[-3];
    v_69 = negate(v_69);
    env = stack[-5];
    fn = basic_elt(env, 3); // ashift
    v_69 = (*qfn2(fn))(fn, stack[0], v_69);
    env = stack[-5];
    v_70 = difference2(stack[-1], v_69);
    v_69 = stack[-4];
    {
        LispObject v_80 = stack[-2];
        return list2star(v_80, v_70, v_69);
    }
    v_69 = nil;
v_13:
    return onevalue(v_69);
}



// Code for lispreadp

static LispObject CC_lispreadp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_7, v_8;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7 = v_2;
// end of prologue
    v_8 = basic_elt(env, 1); // read
        return Leqcar(nil, v_7, v_8);
}



// Code for indexsymmetrize

static LispObject CC_indexsymmetrize(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_48, v_49, v_50;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_2;
// end of prologue
    v_48 = stack[-2];
    if (!car_legal(v_48)) v_49 = carerror(v_48); else
    v_49 = qcar(v_48);
    v_48 = basic_elt(env, 1); // indxsymmetrize
    v_48 = get(v_49, v_48);
    env = stack[-4];
    stack[-3] = v_48;
    v_48 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_48;
    v_49 = (LispObject)16+TAG_FIXNUM; // 1
    v_48 = stack[-2];
    if (!car_legal(v_48)) v_48 = cdrerror(v_48); else
    v_48 = qcdr(v_48);
    v_48 = cons(v_49, v_48);
    env = stack[-4];
    stack[-1] = v_48;
v_9:
    v_48 = stack[-3];
    if (v_48 == nil) goto v_22;
    else goto v_23;
v_22:
    v_50 = stack[0];
    v_48 = stack[-2];
    if (!car_legal(v_48)) v_49 = carerror(v_48); else
    v_49 = qcar(v_48);
    v_48 = stack[-1];
    if (!car_legal(v_48)) v_48 = cdrerror(v_48); else
    v_48 = qcdr(v_48);
    return list2star(v_50, v_49, v_48);
v_23:
    v_48 = stack[-3];
    if (!car_legal(v_48)) v_49 = carerror(v_48); else
    v_49 = qcar(v_48);
    v_48 = stack[-1];
    if (!car_legal(v_48)) v_48 = cdrerror(v_48); else
    v_48 = qcdr(v_48);
    v_48 = Lapply1(nil, v_49, v_48);
    env = stack[-4];
    stack[-1] = v_48;
    v_48 = stack[-1];
    if (v_48 == nil) goto v_38;
    else goto v_39;
v_38:
    v_48 = nil;
    goto v_8;
v_39:
    v_48 = stack[-1];
    if (!car_legal(v_48)) v_49 = carerror(v_48); else
    v_49 = qcar(v_48);
    v_48 = stack[0];
    v_48 = times2(v_49, v_48);
    env = stack[-4];
    stack[0] = v_48;
    v_48 = stack[-3];
    if (!car_legal(v_48)) v_48 = cdrerror(v_48); else
    v_48 = qcdr(v_48);
    stack[-3] = v_48;
    goto v_9;
v_8:
    return onevalue(v_48);
}



// Code for reval3

static LispObject CC_reval3(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_9;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_9 = v_2;
// end of prologue
    fn = basic_elt(env, 1); // simp
    v_9 = (*qfn1(fn))(fn, v_9);
    env = stack[0];
    {
        fn = basic_elt(env, 2); // mk!*sq
        return (*qfn1(fn))(fn, v_9);
    }
}



// Code for color!-roads

static LispObject CC_colorKroads(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_67, v_68, v_69;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_3;
    v_69 = v_2;
// end of prologue
    v_67 = stack[-4];
    if (!car_legal(v_67)) v_67 = carerror(v_67); else
    v_67 = qcar(v_67);
    if (!car_legal(v_67)) v_68 = carerror(v_67); else
    v_68 = qcar(v_67);
    v_67 = v_69;
    v_67 = Lassoc(nil, v_68, v_67);
    if (!car_legal(v_67)) v_67 = cdrerror(v_67); else
    v_67 = qcdr(v_67);
    stack[-1] = v_67;
    v_67 = stack[-4];
    if (!car_legal(v_67)) v_67 = cdrerror(v_67); else
    v_67 = qcdr(v_67);
    if (!car_legal(v_67)) v_67 = carerror(v_67); else
    v_67 = qcar(v_67);
    if (!car_legal(v_67)) v_68 = carerror(v_67); else
    v_68 = qcar(v_67);
    v_67 = v_69;
    v_67 = Lassoc(nil, v_68, v_67);
    if (!car_legal(v_67)) v_67 = cdrerror(v_67); else
    v_67 = qcdr(v_67);
    stack[0] = v_67;
    v_67 = stack[-4];
    if (!car_legal(v_67)) v_67 = cdrerror(v_67); else
    v_67 = qcdr(v_67);
    if (!car_legal(v_67)) v_67 = cdrerror(v_67); else
    v_67 = qcdr(v_67);
    if (!car_legal(v_67)) v_67 = carerror(v_67); else
    v_67 = qcar(v_67);
    if (!car_legal(v_67)) v_67 = carerror(v_67); else
    v_67 = qcar(v_67);
    v_68 = v_69;
    v_67 = Lassoc(nil, v_67, v_68);
    if (!car_legal(v_67)) v_67 = cdrerror(v_67); else
    v_67 = qcdr(v_67);
    stack[-5] = v_67;
    stack[-2] = stack[-1];
    v_68 = stack[0];
    v_67 = stack[-5];
    v_67 = plus2(v_68, v_67);
    env = stack[-6];
    v_68 = plus2(stack[-2], v_67);
    env = stack[-6];
    v_67 = (LispObject)32+TAG_FIXNUM; // 2
    v_67 = quot2(v_68, v_67);
    env = stack[-6];
    stack[-2] = v_67;
    v_68 = stack[-2];
    v_67 = stack[-1];
    v_67 = difference2(v_68, v_67);
    env = stack[-6];
    stack[-1] = v_67;
    v_68 = stack[-2];
    v_67 = stack[0];
    v_67 = difference2(v_68, v_67);
    env = stack[-6];
    stack[0] = v_67;
    v_68 = stack[-2];
    v_67 = stack[-5];
    v_67 = difference2(v_68, v_67);
    env = stack[-6];
    stack[-5] = v_67;
    v_67 = stack[-4];
    if (!car_legal(v_67)) v_67 = carerror(v_67); else
    v_67 = qcar(v_67);
    if (!car_legal(v_67)) stack[-3] = carerror(v_67); else
    stack[-3] = qcar(v_67);
    stack[-2] = stack[-1];
    v_67 = stack[-4];
    if (!car_legal(v_67)) v_67 = cdrerror(v_67); else
    v_67 = qcdr(v_67);
    if (!car_legal(v_67)) v_67 = carerror(v_67); else
    v_67 = qcar(v_67);
    if (!car_legal(v_67)) stack[-1] = carerror(v_67); else
    stack[-1] = qcar(v_67);
    v_67 = stack[-4];
    if (!car_legal(v_67)) v_67 = cdrerror(v_67); else
    v_67 = qcdr(v_67);
    if (!car_legal(v_67)) v_67 = cdrerror(v_67); else
    v_67 = qcdr(v_67);
    if (!car_legal(v_67)) v_67 = carerror(v_67); else
    v_67 = qcar(v_67);
    if (!car_legal(v_67)) v_68 = carerror(v_67); else
    v_68 = qcar(v_67);
    v_67 = stack[-5];
    v_67 = cons(v_68, v_67);
    env = stack[-6];
    v_67 = ncons(v_67);
    env = stack[-6];
    v_67 = acons(stack[-1], stack[0], v_67);
    {
        LispObject v_76 = stack[-3];
        LispObject v_77 = stack[-2];
        return acons(v_76, v_77, v_67);
    }
    return onevalue(v_67);
}



// Code for clogsq!*

static LispObject CC_clogsqH(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_28, v_29;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_28 = v_2;
// end of prologue
// Binding !*div
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(basic_elt(env, 1)) = nil; // !*div
// Binding !*combinelogs
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=2
{   bind_fluid_stack bind_fluid_var(-4, 2, -2);
    qvalue(basic_elt(env, 2)) = nil; // !*combinelogs
// Binding !*expandlogs
// FLUIDBIND: reloadenv=4 litvec-offset=3 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 3, -1);
    qvalue(basic_elt(env, 3)) = nil; // !*expandlogs
    v_29 = lisp_true;
    qvalue(basic_elt(env, 3)) = v_29; // !*expandlogs
    qvalue(basic_elt(env, 1)) = v_29; // !*div
    v_29 = lisp_true;
// Binding !*uncached
// FLUIDBIND: reloadenv=4 litvec-offset=4 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 4, 0);
    qvalue(basic_elt(env, 4)) = v_29; // !*uncached
    fn = basic_elt(env, 5); // prepsq
    v_28 = (*qfn1(fn))(fn, v_28);
    env = stack[-4];
    fn = basic_elt(env, 6); // simp
    v_28 = (*qfn1(fn))(fn, v_28);
    env = stack[-4];
    ;}  // end of a binding scope
    v_29 = nil;
    qvalue(basic_elt(env, 3)) = v_29; // !*expandlogs
    fn = basic_elt(env, 7); // prepsq!*
    v_28 = (*qfn1(fn))(fn, v_28);
    env = stack[-4];
    fn = basic_elt(env, 8); // comblog
    v_28 = (*qfn1(fn))(fn, v_28);
    env = stack[-4];
    fn = basic_elt(env, 9); // simp!*
    v_28 = (*qfn1(fn))(fn, v_28);
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_28);
}



// Code for formrlis

static LispObject CC_formrlis(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_82, v_83, v_84;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push3(v_2,v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_4,v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_82 = v_4;
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
    v_82 = stack[-2];
    if (!car_legal(v_82)) v_83 = carerror(v_82); else
    v_83 = qcar(v_82);
    v_82 = basic_elt(env, 1); // flagop
    v_82 = Lflagp(nil, v_83, v_82);
    env = stack[-4];
    if (v_82 == nil) goto v_8;
    else goto v_9;
v_8:
    v_82 = stack[-2];
    if (!car_legal(v_82)) stack[-3] = carerror(v_82); else
    stack[-3] = qcar(v_82);
    stack[0] = basic_elt(env, 2); // list
    v_82 = stack[-2];
    if (!car_legal(v_82)) v_83 = carerror(v_82); else
    v_83 = qcar(v_82);
    v_82 = basic_elt(env, 3); // share
    if (v_83 == v_82) goto v_21;
    else goto v_22;
v_21:
    stack[-1] = nil;
    v_82 = stack[-2];
    if (!car_legal(v_82)) v_82 = cdrerror(v_82); else
    v_82 = qcdr(v_82);
    stack[-2] = v_82;
v_34:
    v_82 = stack[-2];
    if (v_82 == nil) goto v_37;
    else goto v_38;
v_37:
    goto v_33;
v_38:
    v_82 = stack[-2];
    if (!car_legal(v_82)) v_82 = carerror(v_82); else
    v_82 = qcar(v_82);
    v_83 = Lmkquote(nil, v_82);
    env = stack[-4];
    v_82 = stack[-1];
    v_82 = cons(v_83, v_82);
    env = stack[-4];
    stack[-1] = v_82;
    v_82 = stack[-2];
    if (!car_legal(v_82)) v_82 = cdrerror(v_82); else
    v_82 = qcdr(v_82);
    stack[-2] = v_82;
    goto v_34;
v_33:
    v_82 = stack[-1];
    fn = basic_elt(env, 8); // reversip!*
    v_82 = (*qfn1(fn))(fn, v_82);
    env = stack[-4];
    goto v_20;
v_22:
    v_82 = stack[-2];
    if (!car_legal(v_82)) v_84 = cdrerror(v_82); else
    v_84 = qcdr(v_82);
    v_83 = stack[-1];
    v_82 = basic_elt(env, 4); // algebraic
    fn = basic_elt(env, 9); // formlis
    v_82 = (*qfn3(fn))(fn, v_84, v_83, v_82);
    env = stack[-4];
    goto v_20;
    v_82 = nil;
v_20:
    v_82 = cons(stack[0], v_82);
    {
        LispObject v_89 = stack[-3];
        return list2(v_89, v_82);
    }
v_9:
    v_82 = stack[-2];
    if (!car_legal(v_82)) v_82 = cdrerror(v_82); else
    v_82 = qcdr(v_82);
    fn = basic_elt(env, 10); // idlistp
    v_82 = (*qfn1(fn))(fn, v_82);
    env = stack[-4];
    if (v_82 == nil) goto v_57;
    else goto v_58;
v_57:
    v_83 = basic_elt(env, 5); // !*comma!*
    v_82 = stack[-2];
    if (!car_legal(v_82)) v_82 = cdrerror(v_82); else
    v_82 = qcdr(v_82);
    v_83 = cons(v_83, v_82);
    env = stack[-4];
    v_82 = basic_elt(env, 6); // "identifier list"
    {
        fn = basic_elt(env, 11); // typerr
        return (*qfn2(fn))(fn, v_83, v_82);
    }
v_58:
    stack[-3] = basic_elt(env, 7); // flag
    stack[0] = basic_elt(env, 2); // list
    v_82 = stack[-2];
    if (!car_legal(v_82)) v_84 = cdrerror(v_82); else
    v_84 = qcdr(v_82);
    v_83 = stack[-1];
    v_82 = basic_elt(env, 4); // algebraic
    fn = basic_elt(env, 9); // formlis
    v_82 = (*qfn3(fn))(fn, v_84, v_83, v_82);
    env = stack[-4];
    stack[0] = cons(stack[0], v_82);
    env = stack[-4];
    v_82 = stack[-2];
    if (!car_legal(v_82)) v_82 = carerror(v_82); else
    v_82 = qcar(v_82);
    v_82 = Lmkquote(nil, v_82);
    {
        LispObject v_90 = stack[-3];
        LispObject v_91 = stack[0];
        return list3(v_90, v_91, v_82);
    }
    v_82 = nil;
    return onevalue(v_82);
}



// Code for remchkf

static LispObject CC_remchkf(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_48, v_49, v_50;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push3(v_2,v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_4,v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_4;
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
    v_49 = stack[-2];
    v_48 = stack[-1];
    fn = basic_elt(env, 1); // remchkf1
    v_48 = (*qfn2(fn))(fn, v_49, v_48);
    env = stack[-4];
    stack[-3] = v_48;
    v_48 = stack[-3];
    if (!consp(v_48)) goto v_20;
    else goto v_21;
v_20:
    v_48 = lisp_true;
    goto v_19;
v_21:
    v_48 = stack[-3];
    if (!car_legal(v_48)) v_48 = carerror(v_48); else
    v_48 = qcar(v_48);
    v_48 = (consp(v_48) ? nil : lisp_true);
    goto v_19;
    v_48 = nil;
v_19:
    if (v_48 == nil) goto v_17;
    v_48 = lisp_true;
    goto v_15;
v_17:
    v_48 = stack[-2];
    fn = basic_elt(env, 2); // kernels
    v_49 = (*qfn1(fn))(fn, v_48);
    env = stack[-4];
    v_48 = stack[0];
    fn = basic_elt(env, 3); // intersection
    v_48 = (*qfn2(fn))(fn, v_49, v_48);
    env = stack[-4];
    v_48 = (v_48 == nil ? lisp_true : nil);
    goto v_15;
    v_48 = nil;
v_15:
    if (v_48 == nil) goto v_13;
    v_48 = stack[-3];
    goto v_11;
v_13:
    v_48 = stack[-3];
    if (!car_legal(v_48)) stack[-2] = carerror(v_48); else
    stack[-2] = qcar(v_48);
    v_48 = stack[-3];
    if (!car_legal(v_48)) v_50 = cdrerror(v_48); else
    v_50 = qcdr(v_48);
    v_49 = stack[-1];
    v_48 = stack[0];
    v_48 = CC_remchkf(basic_elt(env, 0), v_50, v_49, v_48);
    {
        LispObject v_55 = stack[-2];
        return cons(v_55, v_48);
    }
    v_48 = nil;
v_11:
    return onevalue(v_48);
}



// Code for dfprintfn

static LispObject CC_dfprintfn(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_45, v_46, v_47;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_45 = v_2;
// end of prologue
    v_46 = qvalue(basic_elt(env, 1)); // !*nat
    if (v_46 == nil) goto v_10;
    else goto v_11;
v_10:
    v_46 = lisp_true;
    goto v_9;
v_11:
    v_46 = qvalue(basic_elt(env, 2)); // !*fort
    if (v_46 == nil) goto v_18;
    else goto v_17;
v_18:
    v_46 = qvalue(basic_elt(env, 3)); // !*dfprint
    v_46 = (v_46 == nil ? lisp_true : nil);
v_17:
    goto v_9;
    v_46 = nil;
v_9:
    if (v_46 == nil) goto v_7;
    v_45 = basic_elt(env, 4); // failed
    goto v_5;
v_7:
    v_46 = basic_elt(env, 5); // !!df!!
    if (!car_legal(v_45)) v_45 = cdrerror(v_45); else
    v_45 = qcdr(v_45);
    v_47 = cons(v_46, v_45);
    env = stack[0];
    v_46 = (LispObject)0+TAG_FIXNUM; // 0
    v_45 = nil;
    fn = basic_elt(env, 6); // layout!-formula
    v_45 = (*qfn3(fn))(fn, v_47, v_46, v_45);
    env = stack[0];
    v_46 = v_45;
    v_45 = v_46;
    if (v_45 == nil) goto v_37;
    else goto v_38;
v_37:
    v_45 = basic_elt(env, 4); // failed
    goto v_27;
v_38:
    v_45 = v_46;
    fn = basic_elt(env, 7); // putpline
    v_45 = (*qfn1(fn))(fn, v_45);
    goto v_36;
v_36:
    v_45 = nil;
v_27:
    goto v_5;
    v_45 = nil;
v_5:
    return onevalue(v_45);
}



setup_type const u27_setup[] =
{
    {"*di2q",                   G0W2,     G1W2,     CC_Hdi2q, G3W2,     G4W2},
    {"st_ad_numsorttree",       G0W1,     CC_st_ad_numsorttree,G2W1,G3W1,G4W1},
    {"max-degree",              G0W2,     G1W2,     CC_maxKdegree,G3W2, G4W2},
    {"talp_specsubt",           G0W3,     G1W3,     G2W3,     CC_talp_specsubt,G4W3},
    {"pasf_sisub",              G0W3,     G1W3,     G2W3,     CC_pasf_sisub,G4W3},
    {"ev_max#",                 G0W2,     G1W2,     CC_ev_maxC,G3W2,    G4W2},
    {"containerml",             G0W2,     G1W2,     CC_containerml,G3W2,G4W2},
    {"mkempspmat",              G0W2,     G1W2,     CC_mkempspmat,G3W2, G4W2},
    {"insoccs",                 G0W2,     G1W2,     CC_insoccs,G3W2,    G4W2},
    {":dmtimeslst",             G0W1,     CC_Tdmtimeslst,G2W1,G3W1,     G4W1},
    {"*xadd",                   G0W2,     G1W2,     CC_Hxadd, G3W2,     G4W2},
    {"incident",                G0W3,     G1W3,     G2W3,     CC_incident,G4W3},
    {"innprodp2",               G0W2,     G1W2,     CC_innprodp2,G3W2,  G4W2},
    {"iv_cutcongs1",            G0W2,     G1W2,     CC_iv_cutcongs1,G3W2,G4W2},
    {"vdelete",                 G0W2,     G1W2,     CC_vdelete,G3W2,    G4W2},
    {"omatpir",                 CC_omatpir,G1W0,    G2W0,     G3W0,     G4W0},
    {"suchp",                   G0W1,     CC_suchp, G2W1,     G3W1,     G4W1},
    {"module",                  G0W1,     CC_module,G2W1,     G3W1,     G4W1},
    {"s_actual_world1",         G0W1,     CC_s_actual_world1,G2W1,G3W1, G4W1},
    {"read_typed_name",         CC_read_typed_name,G1W0,G2W0, G3W0,     G4W0},
    {"subs2chk",                G0W1,     CC_subs2chk,G2W1,   G3W1,     G4W1},
    {"simp-prop-condense",      G0W1,     CC_simpKpropKcondense,G2W1,G3W1,G4W1},
    {"lambda_rfde09ec49c92",    G0W2,     G1W2,     CC_lambda_rfde09ec49c92,G3W2,G4W2},
    {"skp_ordp",                G0W2,     G1W2,     CC_skp_ordp,G3W2,   G4W2},
    {"chkrn*",                  G0W1,     CC_chkrnH,G2W1,     G3W1,     G4W1},
    {"vp2",                     G0W1,     CC_vp2,   G2W1,     G3W1,     G4W1},
    {"pasf_floor",              G0W2,     G1W2,     CC_pasf_floor,G3W2, G4W2},
    {"dip_ilcomb2r",            G0W4up,   G1W4up,   G2W4up,   G3W4up,   CC_dip_ilcomb2r},
    {"bvarrd",                  CC_bvarrd,G1W0,     G2W0,     G3W0,     G4W0},
    {"prop-simp",               G0W2,     G1W2,     CC_propKsimp,G3W2,  G4W2},
    {"make_tuple_type",         G0W1,     CC_make_tuple_type,G2W1,G3W1, G4W1},
    {"arglength",               G0W1,     CC_arglength,G2W1,  G3W1,     G4W1},
    {"list_is_all_free",        G0W1,     CC_list_is_all_free,G2W1,G3W1,G4W1},
    {"derivative-mod-p-1",      G0W2,     G1W2,     CC_derivativeKmodKpK1,G3W2,G4W2},
    {"general-horner-rule-mod-p",G0W4up,  G1W4up,   G2W4up,   G3W4up,   CC_generalKhornerKruleKmodKp},
    {"comb",                    G0W2,     G1W2,     CC_comb,  G3W2,     G4W2},
    {"gitimes:",                G0W2,     G1W2,     CC_gitimesT,G3W2,   G4W2},
    {"*a2f",                    G0W1,     CC_Ha2f,  G2W1,     G3W1,     G4W1},
    {"multdfconst",             G0W2,     G1W2,     CC_multdfconst,G3W2,G4W2},
    {"ev_2a",                   G0W1,     CC_ev_2a, G2W1,     G3W1,     G4W1},
    {"sets",                    G0W2,     G1W2,     CC_sets,  G3W2,     G4W2},
    {"alg_plus",                G0W2,     G1W2,     CC_alg_plus,G3W2,   G4W2},
    {"*a2k",                    G0W1,     CC_Ha2k,  G2W1,     G3W1,     G4W1},
    {"matrixp",                 G0W1,     CC_matrixp,G2W1,    G3W1,     G4W1},
    {"amatch",                  G0W4up,   G1W4up,   G2W4up,   G3W4up,   CC_amatch},
    {"groebnormalform",         G0W3,     G1W3,     G2W3,     CC_groebnormalform,G4W3},
    {"evaluate-horner",         G0W1,     CC_evaluateKhorner,G2W1,G3W1, G4W1},
    {"toolongexpp",             G0W1,     CC_toolongexpp,G2W1,G3W1,     G4W1},
    {"find_buble",              G0W2,     G1W2,     CC_find_buble,G3W2, G4W2},
    {"log_assignment",          G0W2,     G1W2,     CC_log_assignment,G3W2,G4W2},
    {"fs:onep:",                G0W1,     CC_fsTonepT,G2W1,   G3W1,     G4W1},
    {"dummyp",                  G0W1,     CC_dummyp,G2W1,     G3W1,     G4W1},
    {"ratdif",                  G0W2,     G1W2,     CC_ratdif,G3W2,     G4W2},
    {"*tayexp2q",               G0W1,     CC_Htayexp2q,G2W1,  G3W1,     G4W1},
    {"talp_sumd",               G0W1,     CC_talp_sumd,G2W1,  G3W1,     G4W1},
    {"pasf_cein",               G0W1,     CC_pasf_cein,G2W1,  G3W1,     G4W1},
    {"mapcarcar",               G0W1,     CC_mapcarcar,G2W1,  G3W1,     G4W1},
    {"matrixom",                G0W1,     CC_matrixom,G2W1,   G3W1,     G4W1},
    {"close_forall",            CC_close_forall,G1W0,G2W0,    G3W0,     G4W0},
    {"evload",                  G0W1,     CC_evload,G2W1,     G3W1,     G4W1},
    {"difference:",             G0W2,     G1W2,     CC_differenceT,G3W2,G4W2},
    {"lispreadp",               G0W1,     CC_lispreadp,G2W1,  G3W1,     G4W1},
    {"indexsymmetrize",         G0W1,     CC_indexsymmetrize,G2W1,G3W1, G4W1},
    {"reval3",                  G0W1,     CC_reval3,G2W1,     G3W1,     G4W1},
    {"color-roads",             G0W2,     G1W2,     CC_colorKroads,G3W2,G4W2},
    {"clogsq*",                 G0W1,     CC_clogsqH,G2W1,    G3W1,     G4W1},
    {"formrlis",                G0W3,     G1W3,     G2W3,     CC_formrlis,G4W3},
    {"remchkf",                 G0W3,     G1W3,     G2W3,     CC_remchkf,G4W3},
    {"dfprintfn",               G0W1,     CC_dfprintfn,G2W1,  G3W1,     G4W1},
    {NULL, (no_args *)"u27", (one_arg *)"87423 8878935 4746513",
        NULL, NULL, NULL}
};

// end of generated code
