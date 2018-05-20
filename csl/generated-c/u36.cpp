
// $destdir/u36.c        Machine generated C code

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
#include <random>
#include <thread>
#include <mutex>
#include <condition_variable>
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
#define PAGE_POWER_OF_TWO (((size_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE (PAGE_POWER_OF_TWO)
#ifndef MAX_HEAPSIZE
#define MAX_HEAPBITS (SIXTY_FOUR_BIT ? 41 : 31)
#define MAX_HEAPSIZE (((size_t)1) << (MAX_HEAPBITS-20))
#endif 
#define MEGABYTE ((size_t)0x100000)
#if PAGE_BITS >= 20
#define MAX_PAGES (MAX_HEAPSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES (MAX_HEAPSIZE << (20-PAGE_BITS))
#endif
#define LONGEST_LEGAL_FILENAME 1024
#define CELL ((size_t)sizeof(LispObject))
#define TAG_BITS 0x7
#define XTAG_BITS 0xf
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
#define FIXNUM_OF_INT(n) (16*(n)+TAG_FIXNUM)
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
#define TYPE_HASH ( 0x15 <<Tw) 
#define TYPE_HASHX ( 0x19 <<Tw) 
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
#define VIRTUAL_TYPE_REF ( 0x17d <<Tw)
#define VIRTUAL_TYPE_NIL ( 0x27d <<Tw)
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
{ size_t size = length_of_header(vechdr(v));
 size_t n = size/CELL - 1;
 if (is_power_of_two(n)) 
 { int i = intlog2(n); 
 if (i <= LOG2_VECTOR_CHUNK_BYTES)
 { basic_elt(v, 0) = free_vectors[i];
 vechdr(v) = TYPE_SIMPLE_VEC +
 (size << (Tw+5)) +
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
 discard_basic_vector(v);
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
static inline int32_t& intfloat64_t_val_hi(LispObject v)
{ return *(int32_t *)((char *)v + (8-TAG_BOXFLOAT));
}
static inline int32_t& intfloat64_t_val_lo(LispObject v)
{ return *(int32_t *)((char *)v + (12-TAG_BOXFLOAT));
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
static inline int32_t& intfloat128_t_val32_0(LispObject v)
{ return *(int32_t *)((char *)v + (8-TAG_BOXFLOAT));
}
static inline int32_t& intfloat128_t_val32_1(LispObject v)
{ return *(int32_t *)((char *)v + (12-TAG_BOXFLOAT));
}
static inline int32_t& intfloat128_t_val32_2(LispObject v)
{ return *(int32_t *)((char *)v + (16-TAG_BOXFLOAT));
}
static inline int32_t& intfloat128_t_val32_3(LispObject v)
{ return *(int32_t *)((char *)v + (20-TAG_BOXFLOAT));
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
#define HASH_AS_EQ 0
#define HASH_AS_EQL 1
#define HASH_AS_CL_EQUAL 2
#define HASH_AS_EQUAL 3
#define HASH_AS_EQUALP 4
#define HASH_AS_SYMBOL 5
#define HASH_AS_SXHASH 6
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
extern uintptr_t *pages_hash_table;
#define PAGE_TYPE_2CELL 0
#define PAGE_TYPE_4CELL 1
#define PAGE_TYPE_BIG 2
typedef struct _page_header
{ unsigned int fringe;
 unsigned int type:2
 unsigned int pinsize:30
} page_header;
#endif
extern size_t pages_count, heap_pages_count, vheap_pages_count;
extern size_t new_heap_pages_count, new_vheap_pages_count;
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
NORETURN extern void my_abort();
extern void trace_printf(const char *fmt, ...);
template <typename F>
inline void my_assert(bool ok, F&& action)
{
#ifndef NDEBUG
 if (!ok) { action(); my_abort(); }
#endif 
}
static inline void push(LispObject a)
{ *++stack = a;
 my_assert(a != 0, [&]{ trace_printf("pushed a zero\n"); });
}
static inline void push2(LispObject a, LispObject b)
{ *++stack = a;
 my_assert(a != 0, [&]{ trace_printf("pushed a zero\n"); });
 *++stack = b;
 my_assert(b != 0, [&]{ trace_printf("pushed a zero\n"); });
}
static inline void push3(LispObject a, LispObject b, LispObject c)
{ *++stack = a;
 my_assert(a != 0, [&]{ trace_printf("pushed a zero\n"); });
 *++stack = b;
 my_assert(b != 0, [&]{ trace_printf("pushed a zero\n"); });
 *++stack = c;
 my_assert(c != 0, [&]{ trace_printf("pushed a zero\n"); });
}
static inline void push4(LispObject a, LispObject b, LispObject c,
 LispObject d)
{ *++stack = a;
 my_assert(a != 0, [&]{ trace_printf("pushed a zero\n"); });
 *++stack = b;
 my_assert(b != 0, [&]{ trace_printf("pushed a zero\n"); });
 *++stack = c;
 my_assert(c != 0, [&]{ trace_printf("pushed a zero\n"); });
 *++stack = d;
 my_assert(d != 0, [&]{ trace_printf("pushed a zero\n"); });
}
static inline void push5(LispObject a, LispObject b, LispObject c,
 LispObject d, LispObject e)
{ *++stack = a;
 my_assert(a != 0, [&]{ trace_printf("pushed a zero\n"); });
 *++stack = b;
 my_assert(b != 0, [&]{ trace_printf("pushed a zero\n"); });
 *++stack = c;
 my_assert(c != 0, [&]{ trace_printf("pushed a zero\n"); });
 *++stack = d;
 my_assert(d != 0, [&]{ trace_printf("pushed a zero\n"); });
 *++stack = e;
 my_assert(e != 0, [&]{ trace_printf("pushed a zero\n"); });
}
static inline void push6(LispObject a, LispObject b, LispObject c,
 LispObject d, LispObject e, LispObject f)
{ *++stack = a;
 my_assert(a != 0, [&]{ trace_printf("pushed a zero\n"); });
 *++stack = b;
 my_assert(b != 0, [&]{ trace_printf("pushed a zero\n"); });
 *++stack = c;
 my_assert(c != 0, [&]{ trace_printf("pushed a zero\n"); });
 *++stack = d;
 my_assert(d != 0, [&]{ trace_printf("pushed a zero\n"); });
 *++stack = e;
 my_assert(e != 0, [&]{ trace_printf("pushed a zero\n"); });
 *++stack = f;
 my_assert(f != 0, [&]{ trace_printf("pushed a zero\n"); });
}
static inline void pop(LispObject& a)
{ a = *stack--;
 my_assert(a != 0, [&]{ trace_printf("popped a zero\n"); });
}
static inline void pop(volatile LispObject& a)
{ a = *stack--;
 my_assert(a != 0, [&]{ trace_printf("popped a zero\n"); });
}
static inline void pop2(LispObject& a, LispObject& b)
{ a = *stack--;
 my_assert(a != 0, [&]{ trace_printf("popped a zero\n"); });
 b = *stack--;
 my_assert(b != 0, [&]{ trace_printf("popped a zero\n"); });
}
static inline void pop3(LispObject& a, LispObject& b, LispObject& c)
{ a = *stack--;
 my_assert(a != 0, [&]{ trace_printf("popped a zero\n"); });
 b = *stack--;
 my_assert(b != 0, [&]{ trace_printf("popped a zero\n"); });
 c = *stack--;
 my_assert(c != 0, [&]{ trace_printf("popped a zero\n"); });
}
static inline void pop4(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d)
{ a = *stack--;
 my_assert(a != 0, [&]{ trace_printf("popped a zero\n"); });
 b = *stack--;
 my_assert(b != 0, [&]{ trace_printf("popped a zero\n"); });
 c = *stack--;
 my_assert(c != 0, [&]{ trace_printf("popped a zero\n"); });
 d = *stack--;
 my_assert(d != 0, [&]{ trace_printf("popped a zero\n"); });
}
static inline void pop5(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d, LispObject& e)
{ a = *stack--;
 my_assert(a != 0, [&]{ trace_printf("popped a zero\n"); });
 b = *stack--;
 my_assert(b != 0, [&]{ trace_printf("popped a zero\n"); });
 c = *stack--;
 my_assert(c != 0, [&]{ trace_printf("popped a zero\n"); });
 d = *stack--;
 my_assert(d != 0, [&]{ trace_printf("popped a zero\n"); });
 e = *stack--;
 my_assert(e != 0, [&]{ trace_printf("popped a zero\n"); });
}
static inline void pop6(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d, LispObject& e, LispObject& f)
{ a = *stack--;
 my_assert(a != 0, [&]{ trace_printf("popped a zero\n"); });
 b = *stack--;
 my_assert(b != 0, [&]{ trace_printf("popped a zero\n"); });
 c = *stack--;
 my_assert(c != 0, [&]{ trace_printf("popped a zero\n"); });
 d = *stack--;
 my_assert(d != 0, [&]{ trace_printf("popped a zero\n"); });
 e = *stack--;
 my_assert(e != 0, [&]{ trace_printf("popped a zero\n"); });
 f = *stack--;
 my_assert(f != 0, [&]{ trace_printf("popped a zero\n"); });
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
extern LispObject list_symbol, liststar_symbol, eq_symbol, eql_symbol;
extern LispObject cl_equal_symbol, equal_symbol, equalp_symbol;
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
extern LispObject sys_hash_table, sxhash_hash_table;
extern LispObject help_index, cfunarg, lex_words;
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
 int stg_class, size_t size);
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
extern void ensure_screen();
extern int window_heading;
NORETURN extern void my_exit(int n);
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
extern LispObject acons_no_gc(LispObject a, LispObject b, LispObject c);
extern LispObject cons_gc_test(LispObject a);
extern void convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern LispObject eval(LispObject u, LispObject env);
extern uint32_t Crand();
extern LispObject Cremainder(LispObject a, LispObject b);
extern void Csrand(uint32_t a);
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
extern LispObject reduce_basic_vector_size(LispObject v, size_t len);
extern LispObject get_vector(int tag, int type, size_t length);
extern LispObject get_vector_init(size_t n, LispObject v);
extern LispObject reduce_vector_size(LispObject n, size_t length);
extern void prepare_for_borrowing();
static inline void zero_out(void *p)
{ char *p1 = (char *)doubleword_align_up((intptr_t)p);
 memset(p1, 0, CSL_PAGE_SIZE);
}
extern LispObject borrow_basic_vector(int tag, int type, size_t length);
extern LispObject borrow_vector(int tag, int type, size_t length);
extern uint64_t hash_lisp_string(LispObject s);
extern void lose_C_def(LispObject a);
extern bool geq2(LispObject a, LispObject b);
extern bool greaterp2(LispObject a, LispObject b);
extern bool lesseq2(LispObject a, LispObject b);
extern bool lessp2(LispObject a, LispObject b);
extern LispObject list2(LispObject a, LispObject b);
extern LispObject list2star(LispObject a, LispObject b, LispObject c);
extern LispObject list2starrev(LispObject a, LispObject b, LispObject c);
extern LispObject list3(LispObject a, LispObject b, LispObject c);
extern LispObject list3rev(LispObject a, LispObject b, LispObject c);
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
extern void init_heap_segments(double size);
extern void grab_more_memory(size_t npages);
extern bool allocate_more_memory();
extern void setup(int restartp, double storesize);
extern void set_up_variables(int restart_flag);
extern void warm_setup();
extern void write_everything();
extern LispObject simplify_string(LispObject s);
extern bool stringp(LispObject a);
extern LispObject times2(LispObject a, LispObject b);
extern int32_t thirty_two_bits(LispObject a);
extern uint32_t thirty_two_bits_unsigned(LispObject a);
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
 lisphash_setup[], print_setup[], read_setup[],
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
#ifndef HAVE_CILK
extern void kara_worker(int n);
extern std::thread kara_thread[2];
extern std::mutex kara_mutex[2];
extern std::condition_variable kara_cv[2];
extern bool kara_ready[2];
extern bool kara_quit;
#endif
extern size_t karatsuba_parallel;
#ifndef KARATSUBA_PARALLEL_CUTOFF
# define KARATSUBA_PARALLEL_CUTOFF 120
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
extern LispObject Lgc_forcer1(LispObject env, LispObject a);
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
extern LispObject Lmkhash_1(LispObject env, LispObject a);
extern LispObject Lmkhashset(LispObject env, LispObject a);
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
extern LispObject Lgc_forcer(LispObject env, LispObject a, LispObject b);
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



// Code for prepsq!*0

static LispObject CC_prepsqH0(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_41, v_42, v_43;
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
    v_41 = stack[-2];
    if (!car_legal(v_41)) v_41 = carerror(v_41); else
    v_41 = qcar(v_41);
    if (v_41 == nil) goto v_10;
    else goto v_11;
v_10:
    v_41 = nil;
    goto v_9;
v_11:
    v_41 = stack[-2];
    if (!car_legal(v_41)) v_42 = carerror(v_41); else
    v_42 = qcar(v_41);
    v_41 = stack[-2];
    if (!car_legal(v_41)) v_41 = cdrerror(v_41); else
    v_41 = qcdr(v_41);
    fn = basic_elt(env, 1); // gcdf
    v_42 = (*qfn2(fn))(fn, v_42, v_41);
    env = stack[-4];
    stack[-3] = v_42;
    v_41 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_42 == v_41) goto v_16;
    v_41 = stack[-2];
    if (!car_legal(v_41)) v_42 = carerror(v_41); else
    v_42 = qcar(v_41);
    v_41 = stack[-3];
    fn = basic_elt(env, 2); // quotf!-fail
    stack[0] = (*qfn2(fn))(fn, v_42, v_41);
    env = stack[-4];
    v_41 = stack[-2];
    if (!car_legal(v_41)) v_42 = cdrerror(v_41); else
    v_42 = qcdr(v_41);
    v_41 = stack[-3];
    fn = basic_elt(env, 2); // quotf!-fail
    v_42 = (*qfn2(fn))(fn, v_42, v_41);
    env = stack[-4];
    v_41 = stack[-1];
    {
        LispObject v_48 = stack[0];
        fn = basic_elt(env, 3); // prepsq!*1
        return (*qfn3(fn))(fn, v_48, v_42, v_41);
    }
v_16:
    v_41 = stack[-2];
    if (!car_legal(v_41)) v_43 = carerror(v_41); else
    v_43 = qcar(v_41);
    v_41 = stack[-2];
    if (!car_legal(v_41)) v_42 = cdrerror(v_41); else
    v_42 = qcdr(v_41);
    v_41 = stack[-1];
    {
        fn = basic_elt(env, 3); // prepsq!*1
        return (*qfn3(fn))(fn, v_43, v_42, v_41);
    }
    v_41 = nil;
v_9:
    return onevalue(v_41);
}



// Code for gadd

static LispObject CC_gadd(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
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
        push3(v_2,v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_4,v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_4;
    stack[-3] = v_3;
    stack[-4] = v_2;
// end of prologue
    stack[-5] = nil;
    v_74 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_74;
    v_75 = stack[-2];
    v_74 = stack[-3];
    v_74 = Latsoc(nil, v_75, v_74);
    stack[-1] = v_74;
    if (v_74 == nil) goto v_18;
    else goto v_19;
v_18:
    goto v_11;
v_19:
    v_75 = stack[-1];
    v_74 = stack[-3];
    v_74 = Ldelete(nil, v_75, v_74);
    env = stack[-6];
    stack[-3] = v_74;
    v_74 = stack[-1];
    if (!car_legal(v_74)) v_74 = cdrerror(v_74); else
    v_74 = qcdr(v_74);
    if (!car_legal(v_74)) v_74 = cdrerror(v_74); else
    v_74 = qcdr(v_74);
    stack[-5] = v_74;
    v_74 = stack[-1];
    if (!car_legal(v_74)) v_74 = cdrerror(v_74); else
    v_74 = qcdr(v_74);
    if (!car_legal(v_74)) v_74 = carerror(v_74); else
    v_74 = qcar(v_74);
    stack[-1] = v_74;
v_11:
    v_74 = stack[-4];
    if (v_74 == nil) goto v_34;
    else goto v_35;
v_34:
    v_74 = stack[0];
    stack[0] = Levenp(nil, v_74);
    env = stack[-6];
    v_76 = stack[-2];
    v_75 = stack[-1];
    v_74 = stack[-5];
    v_75 = list2star(v_76, v_75, v_74);
    v_74 = stack[-3];
    {
        LispObject v_83 = stack[0];
        return list2star(v_83, v_75, v_74);
    }
v_35:
    v_74 = stack[-4];
    if (!car_legal(v_74)) v_75 = carerror(v_74); else
    v_75 = qcar(v_74);
    v_74 = basic_elt(env, 1); // a
    if (v_75 == v_74) goto v_45;
    else goto v_46;
v_45:
    goto v_13;
v_46:
    v_74 = stack[-4];
    if (!car_legal(v_74)) v_75 = carerror(v_74); else
    v_75 = qcar(v_74);
    v_74 = stack[-5];
    v_74 = cons(v_75, v_74);
    env = stack[-6];
    stack[-5] = v_74;
    goto v_33;
v_33:
v_12:
    v_74 = stack[-4];
    if (!car_legal(v_74)) v_74 = cdrerror(v_74); else
    v_74 = qcdr(v_74);
    stack[-4] = v_74;
    goto v_11;
v_13:
    v_75 = qvalue(basic_elt(env, 2)); // ndims!*
    v_74 = (LispObject)64+TAG_FIXNUM; // 4
    if (v_75 == v_74) goto v_61;
    v_76 = basic_elt(env, 3); // hephys
    v_75 = (LispObject)128+TAG_FIXNUM; // 8
    v_74 = basic_elt(env, 4); // "Gamma5 not allowed unless vecdim is 4"
    fn = basic_elt(env, 5); // rerror
    v_74 = (*qfn3(fn))(fn, v_76, v_75, v_74);
    env = stack[-6];
    goto v_59;
v_61:
v_59:
    v_74 = stack[-1];
    v_74 = (v_74 == nil ? lisp_true : nil);
    stack[-1] = v_74;
    v_74 = stack[-5];
    v_75 = Llength(nil, v_74);
    env = stack[-6];
    v_74 = stack[0];
    v_74 = plus2(v_75, v_74);
    env = stack[-6];
    stack[0] = v_74;
    goto v_12;
    return onevalue(v_74);
}



// Code for fctlength

static LispObject CC_fctlength(LispObject env,
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
    fn = basic_elt(env, 1); // fctargs
    v_7 = (*qfn1(fn))(fn, v_7);
        return Llength(nil, v_7);
}



// Code for talp_invtscsimpl

static LispObject CC_talp_invtscsimpl(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_111, v_112, v_113;
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
    stack[0] = v_2;
// end of prologue
    v_111 = stack[0];
    fn = basic_elt(env, 4); // talp_rnf
    v_111 = (*qfn1(fn))(fn, v_111);
    env = stack[-5];
    stack[0] = v_111;
    v_111 = stack[0];
    if (!consp(v_111)) goto v_11;
    else goto v_12;
v_11:
    v_111 = stack[0];
    goto v_6;
v_12:
    v_111 = stack[0];
    fn = basic_elt(env, 5); // talp_atfp
    v_111 = (*qfn1(fn))(fn, v_111);
    env = stack[-5];
    if (v_111 == nil) goto v_18;
    v_111 = stack[0];
    fn = basic_elt(env, 6); // talp_invtscc
    v_111 = (*qfn1(fn))(fn, v_111);
    env = stack[-5];
    if (v_111 == nil) goto v_24;
    v_111 = stack[0];
    fn = basic_elt(env, 7); // talp_simpat
    v_111 = (*qfn1(fn))(fn, v_111);
    env = stack[-5];
    fn = basic_elt(env, 8); // talp_invtscsimplat
    v_111 = (*qfn1(fn))(fn, v_111);
    env = stack[-5];
    {
        fn = basic_elt(env, 4); // talp_rnf
        return (*qfn1(fn))(fn, v_111);
    }
v_24:
    v_111 = stack[0];
    {
        fn = basic_elt(env, 7); // talp_simpat
        return (*qfn1(fn))(fn, v_111);
    }
    goto v_16;
v_18:
v_16:
    v_111 = stack[0];
    fn = basic_elt(env, 9); // talp_op
    v_111 = (*qfn1(fn))(fn, v_111);
    env = stack[-5];
    v_113 = v_111;
    v_112 = v_113;
    v_111 = basic_elt(env, 1); // or
    if (v_112 == v_111) goto v_43;
    else goto v_44;
v_43:
    v_111 = lisp_true;
    goto v_42;
v_44:
    v_112 = v_113;
    v_111 = basic_elt(env, 2); // and
    v_111 = (v_112 == v_111 ? lisp_true : nil);
    goto v_42;
    v_111 = nil;
v_42:
    if (v_111 == nil) goto v_40;
    stack[-4] = v_113;
    v_111 = stack[0];
    fn = basic_elt(env, 10); // talp_argl
    v_111 = (*qfn1(fn))(fn, v_111);
    env = stack[-5];
    stack[-3] = v_111;
    v_111 = stack[-3];
    if (v_111 == nil) goto v_66;
    else goto v_67;
v_66:
    v_111 = nil;
    goto v_60;
v_67:
    v_111 = stack[-3];
    if (!car_legal(v_111)) v_111 = carerror(v_111); else
    v_111 = qcar(v_111);
    v_111 = CC_talp_invtscsimpl(basic_elt(env, 0), v_111);
    env = stack[-5];
    v_111 = ncons(v_111);
    env = stack[-5];
    stack[-1] = v_111;
    stack[-2] = v_111;
v_61:
    v_111 = stack[-3];
    if (!car_legal(v_111)) v_111 = cdrerror(v_111); else
    v_111 = qcdr(v_111);
    stack[-3] = v_111;
    v_111 = stack[-3];
    if (v_111 == nil) goto v_80;
    else goto v_81;
v_80:
    v_111 = stack[-2];
    goto v_60;
v_81:
    stack[0] = stack[-1];
    v_111 = stack[-3];
    if (!car_legal(v_111)) v_111 = carerror(v_111); else
    v_111 = qcar(v_111);
    v_111 = CC_talp_invtscsimpl(basic_elt(env, 0), v_111);
    env = stack[-5];
    v_111 = ncons(v_111);
    env = stack[-5];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    qcdr(stack[0]) = v_111;
    v_111 = stack[-1];
    if (!car_legal(v_111)) v_111 = cdrerror(v_111); else
    v_111 = qcdr(v_111);
    stack[-1] = v_111;
    goto v_61;
v_60:
    v_111 = cons(stack[-4], v_111);
    env = stack[-5];
    {
        fn = basic_elt(env, 4); // talp_rnf
        return (*qfn1(fn))(fn, v_111);
    }
v_40:
    v_112 = v_113;
    v_111 = basic_elt(env, 3); // (ex all)
    v_111 = Lmemq(nil, v_112, v_111);
    if (v_111 == nil) goto v_95;
    stack[-2] = v_113;
    v_111 = stack[0];
    if (!car_legal(v_111)) v_111 = cdrerror(v_111); else
    v_111 = qcdr(v_111);
    if (!car_legal(v_111)) stack[-1] = carerror(v_111); else
    stack[-1] = qcar(v_111);
    v_111 = stack[0];
    if (!car_legal(v_111)) v_111 = cdrerror(v_111); else
    v_111 = qcdr(v_111);
    if (!car_legal(v_111)) v_111 = cdrerror(v_111); else
    v_111 = qcdr(v_111);
    if (!car_legal(v_111)) v_111 = carerror(v_111); else
    v_111 = qcar(v_111);
    v_111 = CC_talp_invtscsimpl(basic_elt(env, 0), v_111);
    env = stack[-5];
    v_111 = ncons(v_111);
    env = stack[-5];
    v_111 = list2star(stack[-2], stack[-1], v_111);
    env = stack[-5];
    {
        fn = basic_elt(env, 4); // talp_rnf
        return (*qfn1(fn))(fn, v_111);
    }
v_95:
    v_111 = nil;
v_6:
    return onevalue(v_111);
}



// Code for cl_sacatlp

static LispObject CC_cl_sacatlp(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_6, v_7;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_6 = v_3;
    v_7 = v_2;
// end of prologue
    v_6 = lisp_true;
    return onevalue(v_6);
}



// Code for prsubsetrd

static LispObject CC_prsubsetrd(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_19, v_20;
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
    fn = basic_elt(env, 1); // mathml
    v_19 = (*qfn0(fn))(fn);
    env = stack[-1];
    v_20 = v_19;
    v_19 = v_20;
    if (v_19 == nil) goto v_10;
    else goto v_11;
v_10:
    v_19 = nil;
    goto v_9;
v_11:
    stack[0] = v_20;
    v_19 = CC_prsubsetrd(basic_elt(env, 0));
    {
        LispObject v_22 = stack[0];
        return cons(v_22, v_19);
    }
    v_19 = nil;
v_9:
    return onevalue(v_19);
}



// Code for findoptrow

static LispObject CC_findoptrow(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_100, v_101, v_102;
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
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-6] = v_4;
    stack[0] = v_3;
    stack[-7] = v_2;
// end of prologue
    stack[-8] = nil;
    stack[-2] = stack[0];
    stack[-1] = qvalue(basic_elt(env, 1)); // codmat
    v_101 = qvalue(basic_elt(env, 2)); // maxvar
    v_100 = stack[-7];
    v_100 = plus2(v_101, v_100);
    env = stack[-9];
    v_101 = Lgetv(nil, stack[-1], v_100);
    env = stack[-9];
    v_100 = (LispObject)64+TAG_FIXNUM; // 4
    v_100 = Lgetv(nil, v_101, v_100);
    env = stack[-9];
    fn = basic_elt(env, 7); // pnthxzz
    v_100 = (*qfn2(fn))(fn, stack[-2], v_100);
    env = stack[-9];
    if (!car_legal(v_100)) v_100 = carerror(v_100); else
    v_100 = qcar(v_100);
    if (!car_legal(v_100)) v_100 = cdrerror(v_100); else
    v_100 = qcdr(v_100);
    if (!car_legal(v_100)) v_100 = carerror(v_100); else
    v_100 = qcar(v_100);
    stack[-4] = v_100;
    stack[-1] = qvalue(basic_elt(env, 1)); // codmat
    v_101 = qvalue(basic_elt(env, 2)); // maxvar
    v_100 = stack[0];
    v_100 = plus2(v_101, v_100);
    env = stack[-9];
    v_101 = Lgetv(nil, stack[-1], v_100);
    env = stack[-9];
    v_100 = (LispObject)64+TAG_FIXNUM; // 4
    v_100 = Lgetv(nil, v_101, v_100);
    env = stack[-9];
    stack[-3] = v_100;
v_28:
    v_100 = stack[-3];
    if (v_100 == nil) goto v_38;
    else goto v_39;
v_38:
    goto v_27;
v_39:
    v_100 = stack[-3];
    if (!car_legal(v_100)) v_100 = carerror(v_100); else
    v_100 = qcar(v_100);
    stack[0] = v_100;
    stack[-1] = qvalue(basic_elt(env, 1)); // codmat
    v_101 = qvalue(basic_elt(env, 2)); // maxvar
    v_100 = stack[0];
    if (!car_legal(v_100)) v_100 = carerror(v_100); else
    v_100 = qcar(v_100);
    stack[-5] = v_100;
    v_100 = plus2(v_101, v_100);
    env = stack[-9];
    v_101 = Lgetv(nil, stack[-1], v_100);
    env = stack[-9];
    v_100 = (LispObject)0+TAG_FIXNUM; // 0
    v_100 = Lgetv(nil, v_101, v_100);
    env = stack[-9];
    if (v_100 == nil) goto v_48;
    stack[-2] = stack[-5];
    stack[-1] = stack[-7];
    v_100 = stack[0];
    if (!car_legal(v_100)) v_100 = cdrerror(v_100); else
    v_100 = qcdr(v_100);
    if (!car_legal(v_100)) stack[0] = carerror(v_100); else
    stack[0] = qcar(v_100);
    v_100 = stack[-4];
    v_100 = ncons(v_100);
    env = stack[-9];
    fn = basic_elt(env, 8); // testpr
    v_100 = (*qfn4up(fn))(fn, stack[-2], stack[-1], stack[0], v_100);
    env = stack[-9];
    stack[0] = v_100;
    if (!car_legal(v_100)) v_100 = cdrerror(v_100); else
    v_100 = qcdr(v_100);
    if (v_100 == nil) goto v_59;
    else goto v_60;
v_59:
    v_101 = stack[-5];
    v_100 = qvalue(basic_elt(env, 3)); // roccup1
    v_100 = cons(v_101, v_100);
    env = stack[-9];
    qvalue(basic_elt(env, 3)) = v_100; // roccup1
    goto v_58;
v_60:
    v_100 = stack[0];
    v_101 = Llength(nil, v_100);
    env = stack[-9];
    stack[-1] = v_101;
    v_100 = stack[-6];
    v_100 = (LispObject)greaterp2(v_101, v_100);
    v_100 = v_100 ? lisp_true : nil;
    env = stack[-9];
    if (v_100 == nil) goto v_78;
    v_100 = stack[-1];
    stack[-6] = v_100;
    qvalue(basic_elt(env, 4)) = v_100; // newnjsi
    v_100 = stack[-5];
    stack[-8] = v_100;
    v_100 = stack[0];
    qvalue(basic_elt(env, 5)) = v_100; // newjsi
    goto v_76;
v_78:
v_76:
    v_101 = stack[-5];
    v_100 = qvalue(basic_elt(env, 6)); // roccup2
    v_100 = cons(v_101, v_100);
    env = stack[-9];
    qvalue(basic_elt(env, 6)) = v_100; // roccup2
    goto v_58;
v_58:
    stack[0] = qvalue(basic_elt(env, 1)); // codmat
    v_101 = qvalue(basic_elt(env, 2)); // maxvar
    v_100 = stack[-5];
    v_100 = plus2(v_101, v_100);
    env = stack[-9];
    v_102 = Lgetv(nil, stack[0], v_100);
    env = stack[-9];
    v_101 = (LispObject)0+TAG_FIXNUM; // 0
    v_100 = nil;
    v_100 = Lputv(nil, v_102, v_101, v_100);
    env = stack[-9];
    goto v_46;
v_48:
v_46:
    v_100 = stack[-3];
    if (!car_legal(v_100)) v_100 = cdrerror(v_100); else
    v_100 = qcdr(v_100);
    stack[-3] = v_100;
    goto v_28;
v_27:
    v_100 = stack[-8];
    return onevalue(v_100);
}



// Code for evzero

static LispObject CC_evzero(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_27, v_28;
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
    stack[-1] = nil;
    v_27 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_27;
v_9:
    v_27 = qvalue(basic_elt(env, 1)); // dipvars!*
    v_28 = Llength(nil, v_27);
    env = stack[-2];
    v_27 = stack[0];
    v_27 = difference2(v_28, v_27);
    env = stack[-2];
    v_27 = Lminusp(nil, v_27);
    env = stack[-2];
    if (v_27 == nil) goto v_14;
    goto v_8;
v_14:
    v_28 = (LispObject)0+TAG_FIXNUM; // 0
    v_27 = stack[-1];
    v_27 = cons(v_28, v_27);
    env = stack[-2];
    stack[-1] = v_27;
    v_27 = stack[0];
    v_27 = add1(v_27);
    env = stack[-2];
    stack[0] = v_27;
    goto v_9;
v_8:
    v_27 = stack[-1];
    return onevalue(v_27);
}



// Code for listpri

static LispObject CC_listpri(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_65, v_66;
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
    stack[-2] = v_2;
// end of prologue
    v_65 = stack[-2];
    stack[0] = v_65;
    v_65 = stack[-2];
    if (!car_legal(v_65)) v_65 = cdrerror(v_65); else
    v_65 = qcdr(v_65);
    stack[-2] = v_65;
    v_65 = basic_elt(env, 1); // !*lcbkt!*
    if (!symbolp(v_65)) v_65 = nil;
    else { v_65 = qfastgets(v_65);
           if (v_65 != nil) { v_65 = elt(v_65, 37); // prtch
#ifdef RECORD_GET
             if (v_65 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v_65 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v_65 == SPID_NOPROP) v_65 = nil; }}
#endif
    fn = basic_elt(env, 7); // prin2!*
    v_65 = (*qfn1(fn))(fn, v_65);
    env = stack[-4];
    v_65 = qvalue(basic_elt(env, 2)); // orig!*
    stack[-3] = v_65;
    v_66 = qvalue(basic_elt(env, 3)); // posn!*
    v_65 = (LispObject)288+TAG_FIXNUM; // 18
    v_65 = (LispObject)lessp2(v_66, v_65);
    v_65 = v_65 ? lisp_true : nil;
    env = stack[-4];
    if (v_65 == nil) goto v_21;
    v_65 = qvalue(basic_elt(env, 3)); // posn!*
    goto v_19;
v_21:
    v_66 = qvalue(basic_elt(env, 2)); // orig!*
    v_65 = (LispObject)48+TAG_FIXNUM; // 3
    v_65 = plus2(v_66, v_65);
    env = stack[-4];
    goto v_19;
    v_65 = nil;
v_19:
    qvalue(basic_elt(env, 2)) = v_65; // orig!*
    v_65 = stack[-2];
    if (v_65 == nil) goto v_33;
    else goto v_34;
v_33:
    goto v_10;
v_34:
    v_66 = stack[-2];
    v_65 = qvalue(basic_elt(env, 4)); // listpri_depth!*
    fn = basic_elt(env, 8); // treesizep
    v_65 = (*qfn2(fn))(fn, v_66, v_65);
    env = stack[-4];
    stack[-1] = v_65;
v_9:
    v_65 = stack[-2];
    if (!car_legal(v_65)) v_65 = carerror(v_65); else
    v_65 = qcar(v_65);
    fn = basic_elt(env, 9); // negnumberchk
    v_66 = (*qfn1(fn))(fn, v_65);
    env = stack[-4];
    v_65 = (LispObject)0+TAG_FIXNUM; // 0
    fn = basic_elt(env, 10); // maprint
    v_65 = (*qfn2(fn))(fn, v_66, v_65);
    env = stack[-4];
    v_65 = stack[-2];
    if (!car_legal(v_65)) v_65 = cdrerror(v_65); else
    v_65 = qcdr(v_65);
    stack[-2] = v_65;
    v_65 = stack[-2];
    if (v_65 == nil) goto v_48;
    else goto v_49;
v_48:
    goto v_10;
v_49:
    v_65 = basic_elt(env, 5); // !*comma!*
    fn = basic_elt(env, 11); // oprin
    v_65 = (*qfn1(fn))(fn, v_65);
    env = stack[-4];
    v_65 = stack[-1];
    if (v_65 == nil) goto v_56;
    v_65 = lisp_true;
    fn = basic_elt(env, 12); // terpri!*
    v_65 = (*qfn1(fn))(fn, v_65);
    env = stack[-4];
    goto v_54;
v_56:
v_54:
    goto v_9;
v_10:
    v_65 = basic_elt(env, 6); // !*rcbkt!*
    if (!symbolp(v_65)) v_65 = nil;
    else { v_65 = qfastgets(v_65);
           if (v_65 != nil) { v_65 = elt(v_65, 37); // prtch
#ifdef RECORD_GET
             if (v_65 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v_65 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v_65 == SPID_NOPROP) v_65 = nil; }}
#endif
    fn = basic_elt(env, 7); // prin2!*
    v_65 = (*qfn1(fn))(fn, v_65);
    env = stack[-4];
    v_65 = stack[-3];
    qvalue(basic_elt(env, 2)) = v_65; // orig!*
    v_65 = stack[0];
    return onevalue(v_65);
}



// Code for gfdiffer

static LispObject CC_gfdiffer(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_19, v_20, v_21;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20 = v_3;
    v_21 = v_2;
// end of prologue
    v_19 = v_21;
    if (!car_legal(v_19)) v_19 = carerror(v_19); else
    v_19 = qcar(v_19);
    if (!consp(v_19)) goto v_7;
    else goto v_8;
v_7:
    v_19 = v_21;
    {
        fn = basic_elt(env, 1); // gffdiff
        return (*qfn2(fn))(fn, v_19, v_20);
    }
v_8:
    v_19 = v_21;
    {
        fn = basic_elt(env, 2); // gbfdiff
        return (*qfn2(fn))(fn, v_19, v_20);
    }
    v_19 = nil;
    return onevalue(v_19);
}



// Code for ev!-edgeloop

static LispObject CC_evKedgeloop(LispObject env,
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
// copy arguments values to proper place
    v_12 = v_3;
    v_13 = v_2;
// end of prologue
    v_14 = qvalue(basic_elt(env, 1)); // ndim!*
    if (!car_legal(v_13)) v_13 = carerror(v_13); else
    v_13 = qcar(v_13);
    v_12 = Lassoc(nil, v_13, v_12);
    if (!car_legal(v_12)) v_12 = cdrerror(v_12); else
    v_12 = qcdr(v_12);
    {
        fn = basic_elt(env, 2); // binc
        return (*qfn2(fn))(fn, v_14, v_12);
    }
}



// Code for primep27

static LispObject CC_primep27(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_53, v_54;
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
    v_54 = stack[0];
    v_53 = (LispObject)23888+TAG_FIXNUM; // 1493
    if (v_54 == v_53) goto v_10;
    else goto v_11;
v_10:
    v_53 = lisp_true;
    goto v_7;
v_11:
    v_53 = nil;
    fn = basic_elt(env, 1); // set!-modulus
    v_53 = (*qfn1(fn))(fn, v_53);
    env = stack[-2];
    stack[-1] = v_53;
    v_54 = (LispObject)143328+TAG_FIXNUM; // 8958
    v_53 = stack[0];
    fn = basic_elt(env, 2); // miller!-rabin
    v_53 = (*qfn2(fn))(fn, v_54, v_53);
    env = stack[-2];
    if (v_53 == nil) goto v_19;
    else goto v_20;
v_19:
    v_53 = nil;
    goto v_18;
v_20:
    v_54 = (LispObject)75264+TAG_FIXNUM; // 4704
    v_53 = stack[0];
    fn = basic_elt(env, 2); // miller!-rabin
    v_53 = (*qfn2(fn))(fn, v_54, v_53);
    env = stack[-2];
    if (v_53 == nil) goto v_29;
    else goto v_30;
v_29:
    v_53 = nil;
    goto v_28;
v_30:
    v_54 = stack[0];
    v_53 = (LispObject)146102416+TAG_FIXNUM; // 9131401
    if (v_54 == v_53) goto v_39;
    else goto v_40;
v_39:
    v_53 = lisp_true;
    goto v_38;
v_40:
    v_54 = stack[0];
    v_53 = (LispObject)97425136+TAG_FIXNUM; // 6089071
    v_53 = (v_54 == v_53 ? lisp_true : nil);
    goto v_38;
    v_53 = nil;
v_38:
    v_53 = (v_53 == nil ? lisp_true : nil);
    goto v_28;
    v_53 = nil;
v_28:
    goto v_18;
    v_53 = nil;
v_18:
    stack[0] = v_53;
    v_53 = stack[-1];
    fn = basic_elt(env, 1); // set!-modulus
    v_53 = (*qfn1(fn))(fn, v_53);
    v_53 = stack[0];
v_7:
    return onevalue(v_53);
}



// Code for formbool

static LispObject CC_formbool(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_146, v_147, v_148;
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
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_4;
    stack[-3] = v_3;
    stack[-4] = v_2;
// end of prologue
    v_147 = stack[-2];
    v_146 = basic_elt(env, 1); // symbolic
    if (v_147 == v_146) goto v_8;
    else goto v_9;
v_8:
    v_148 = stack[-4];
    v_147 = stack[-3];
    v_146 = stack[-2];
    {
        fn = basic_elt(env, 9); // formc
        return (*qfn3(fn))(fn, v_148, v_147, v_146);
    }
v_9:
    v_146 = stack[-4];
    if (!consp(v_146)) goto v_16;
    else goto v_17;
v_16:
    v_147 = stack[-4];
    v_146 = lisp_true;
    if (v_147 == v_146) goto v_21;
    else goto v_22;
v_21:
    v_146 = stack[-4];
    goto v_20;
v_22:
    v_146 = stack[-4];
    if (symbolp(v_146)) goto v_31;
    v_146 = lisp_true;
    goto v_29;
v_31:
    v_147 = stack[-4];
    v_146 = stack[-3];
    v_146 = Latsoc(nil, v_147, v_146);
    goto v_29;
    v_146 = nil;
v_29:
    if (v_146 == nil) goto v_27;
    v_147 = basic_elt(env, 2); // boolvalue!*
    v_146 = stack[-4];
    return list2(v_147, v_146);
v_27:
    stack[0] = basic_elt(env, 2); // boolvalue!*
    v_148 = stack[-4];
    v_147 = stack[-3];
    v_146 = stack[-2];
    fn = basic_elt(env, 10); // formc!*
    v_146 = (*qfn3(fn))(fn, v_148, v_147, v_146);
    {
        LispObject v_155 = stack[0];
        return list2(v_155, v_146);
    }
    v_146 = nil;
v_20:
    goto v_7;
v_17:
    v_146 = stack[-4];
    if (!car_legal(v_146)) v_147 = cdrerror(v_146); else
    v_147 = qcdr(v_146);
    v_146 = stack[-3];
    fn = basic_elt(env, 11); // intexprlisp
    v_146 = (*qfn2(fn))(fn, v_147, v_146);
    env = stack[-6];
    if (v_146 == nil) goto v_51;
    v_146 = stack[-4];
    if (!car_legal(v_146)) v_147 = carerror(v_146); else
    v_147 = qcar(v_146);
    v_146 = basic_elt(env, 3); // boolfn
    v_146 = get(v_147, v_146);
    env = stack[-6];
    if (v_146 == nil) goto v_51;
    v_146 = stack[-4];
    goto v_7;
v_51:
    v_146 = stack[-4];
    if (!car_legal(v_146)) v_146 = carerror(v_146); else
    v_146 = qcar(v_146);
    if (symbolp(v_146)) goto v_65;
    else goto v_64;
v_65:
    v_146 = stack[-4];
    if (!car_legal(v_146)) v_147 = carerror(v_146); else
    v_147 = qcar(v_146);
    v_146 = basic_elt(env, 3); // boolfn
    v_146 = get(v_147, v_146);
    env = stack[-6];
    if (v_146 == nil) goto v_64;
    v_146 = stack[-4];
    if (!car_legal(v_146)) v_147 = carerror(v_146); else
    v_147 = qcar(v_146);
    v_146 = basic_elt(env, 3); // boolfn
    stack[0] = get(v_147, v_146);
    env = stack[-6];
    v_146 = stack[-4];
    if (!car_legal(v_146)) v_148 = cdrerror(v_146); else
    v_148 = qcdr(v_146);
    v_147 = stack[-3];
    v_146 = stack[-2];
    fn = basic_elt(env, 12); // formclis
    v_146 = (*qfn3(fn))(fn, v_148, v_147, v_146);
    {
        LispObject v_156 = stack[0];
        return cons(v_156, v_146);
    }
v_64:
    v_146 = stack[-4];
    if (!car_legal(v_146)) v_146 = carerror(v_146); else
    v_146 = qcar(v_146);
    if (symbolp(v_146)) goto v_85;
    else goto v_84;
v_85:
    v_146 = stack[-4];
    if (!car_legal(v_146)) v_147 = carerror(v_146); else
    v_147 = qcar(v_146);
    v_146 = basic_elt(env, 4); // boolean
    v_146 = Lflagp(nil, v_147, v_146);
    env = stack[-6];
    if (v_146 == nil) goto v_84;
    v_146 = stack[-4];
    if (!car_legal(v_146)) stack[-1] = carerror(v_146); else
    stack[-1] = qcar(v_146);
    v_146 = stack[-4];
    if (!car_legal(v_146)) stack[0] = cdrerror(v_146); else
    stack[0] = qcdr(v_146);
    v_146 = stack[-4];
    if (!car_legal(v_146)) v_147 = carerror(v_146); else
    v_147 = qcar(v_146);
    v_146 = basic_elt(env, 5); // boolargs
    v_146 = Lflagp(nil, v_147, v_146);
    env = stack[-6];
    v_146 = ncons(v_146);
    env = stack[-6];
    fn = basic_elt(env, 13); // formboollis
    v_146 = (*qfn4up(fn))(fn, stack[0], stack[-3], stack[-2], v_146);
    {
        LispObject v_157 = stack[-1];
        return cons(v_157, v_146);
    }
v_84:
    v_146 = stack[-4];
    if (!car_legal(v_146)) v_147 = carerror(v_146); else
    v_147 = qcar(v_146);
    v_146 = basic_elt(env, 2); // boolvalue!*
    if (v_147 == v_146) goto v_106;
    else goto v_107;
v_106:
    v_146 = basic_elt(env, 6); // "Too many formbools"
    {
        fn = basic_elt(env, 14); // rederr
        return (*qfn1(fn))(fn, v_146);
    }
v_107:
    v_146 = stack[-4];
    if (!car_legal(v_146)) v_147 = carerror(v_146); else
    v_147 = qcar(v_146);
    v_146 = basic_elt(env, 7); // where
    if (v_147 == v_146) goto v_113;
    else goto v_114;
v_113:
    stack[-5] = basic_elt(env, 2); // boolvalue!*
    stack[-1] = basic_elt(env, 7); // where
    stack[0] = basic_elt(env, 8); // bool!-eval
    v_146 = stack[-4];
    if (!car_legal(v_146)) v_146 = cdrerror(v_146); else
    v_146 = qcdr(v_146);
    if (!car_legal(v_146)) v_148 = carerror(v_146); else
    v_148 = qcar(v_146);
    v_147 = stack[-3];
    v_146 = stack[-2];
    v_146 = CC_formbool(basic_elt(env, 0), v_148, v_147, v_146);
    env = stack[-6];
    v_146 = list2(stack[0], v_146);
    env = stack[-6];
    v_147 = Lmkquote(nil, v_146);
    env = stack[-6];
    v_146 = stack[-4];
    if (!car_legal(v_146)) v_146 = cdrerror(v_146); else
    v_146 = qcdr(v_146);
    if (!car_legal(v_146)) v_146 = cdrerror(v_146); else
    v_146 = qcdr(v_146);
    if (!car_legal(v_146)) v_146 = carerror(v_146); else
    v_146 = qcar(v_146);
    v_148 = list3(stack[-1], v_147, v_146);
    env = stack[-6];
    v_147 = stack[-3];
    v_146 = stack[-2];
    fn = basic_elt(env, 10); // formc!*
    v_146 = (*qfn3(fn))(fn, v_148, v_147, v_146);
    {
        LispObject v_158 = stack[-5];
        return list2(v_158, v_146);
    }
v_114:
    stack[0] = basic_elt(env, 2); // boolvalue!*
    v_148 = stack[-4];
    v_147 = stack[-3];
    v_146 = stack[-2];
    fn = basic_elt(env, 10); // formc!*
    v_146 = (*qfn3(fn))(fn, v_148, v_147, v_146);
    {
        LispObject v_159 = stack[0];
        return list2(v_159, v_146);
    }
    v_146 = nil;
v_7:
    return onevalue(v_146);
}



// Code for revalpart

static LispObject CC_revalpart(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_288, v_289, v_290;
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_288 = stack[0];
    if (v_288 == nil) goto v_6;
    else goto v_7;
v_6:
    v_290 = basic_elt(env, 1); // alg
    v_289 = (LispObject)3216+TAG_FIXNUM; // 201
    v_288 = basic_elt(env, 2); // "part called without arguments"
    {
        fn = basic_elt(env, 10); // rerror
        return (*qfn3(fn))(fn, v_290, v_289, v_288);
    }
v_7:
// Binding !*intstr
// FLUIDBIND: reloadenv=11 litvec-offset=3 saveloc=10
{   bind_fluid_stack bind_fluid_var(-11, 3, -10);
    qvalue(basic_elt(env, 3)) = nil; // !*intstr
    stack[-9] = nil;
    v_288 = lisp_true;
    qvalue(basic_elt(env, 3)) = v_288; // !*intstr
    v_288 = stack[0];
    if (!car_legal(v_288)) v_288 = carerror(v_288); else
    v_288 = qcar(v_288);
    fn = basic_elt(env, 11); // getrtype
    v_289 = (*qfn1(fn))(fn, v_288);
    env = stack[-11];
    stack[-6] = v_289;
    v_288 = basic_elt(env, 4); // list
    if (v_289 == v_288) goto v_26;
    else goto v_27;
v_26:
    v_288 = stack[0];
    if (!car_legal(v_288)) v_288 = carerror(v_288); else
    v_288 = qcar(v_288);
    if (!consp(v_288)) goto v_39;
    v_288 = stack[0];
    if (!car_legal(v_288)) v_288 = carerror(v_288); else
    v_288 = qcar(v_288);
    if (!car_legal(v_288)) v_289 = carerror(v_288); else
    v_289 = qcar(v_288);
    v_288 = basic_elt(env, 5); // listfn
    v_288 = get(v_289, v_288);
    env = stack[-11];
    goto v_37;
v_39:
    v_288 = nil;
    goto v_37;
    v_288 = nil;
v_37:
    if (v_288 == nil) goto v_35;
    v_288 = stack[0];
    if (!car_legal(v_288)) v_288 = carerror(v_288); else
    v_288 = qcar(v_288);
    fn = basic_elt(env, 12); // reval
    v_288 = (*qfn1(fn))(fn, v_288);
    env = stack[-11];
    goto v_33;
v_35:
    v_288 = stack[0];
    if (!car_legal(v_288)) v_288 = carerror(v_288); else
    v_288 = qcar(v_288);
    fn = basic_elt(env, 13); // listeval0
    v_288 = (*qfn1(fn))(fn, v_288);
    env = stack[-11];
    goto v_33;
    v_288 = nil;
v_33:
    goto v_25;
v_27:
    v_288 = stack[0];
    if (!car_legal(v_288)) v_288 = carerror(v_288); else
    v_288 = qcar(v_288);
    fn = basic_elt(env, 12); // reval
    v_288 = (*qfn1(fn))(fn, v_288);
    env = stack[-11];
    goto v_25;
    v_288 = nil;
v_25:
    stack[-8] = v_288;
    v_288 = nil;
    qvalue(basic_elt(env, 3)) = v_288; // !*intstr
    v_288 = stack[0];
    if (!car_legal(v_288)) v_288 = cdrerror(v_288); else
    v_288 = qcdr(v_288);
    stack[-7] = v_288;
v_68:
    v_288 = stack[-7];
    if (v_288 == nil) goto v_71;
    else goto v_72;
v_71:
    goto v_67;
v_72:
    stack[-5] = nil;
    stack[-4] = nil;
    v_289 = stack[-8];
    v_288 = basic_elt(env, 6); // !*hold
    v_288 = Leqcar(nil, v_289, v_288);
    env = stack[-11];
    stack[-3] = v_288;
    v_288 = stack[-8];
    if (!consp(v_288)) goto v_85;
    else goto v_86;
v_85:
    v_289 = stack[-8];
    v_288 = stack[-7];
    if (!car_legal(v_288)) v_288 = carerror(v_288); else
    v_288 = qcar(v_288);
    fn = basic_elt(env, 14); // parterr2
    v_288 = (*qfn2(fn))(fn, v_289, v_288);
    env = stack[-11];
    v_288 = lisp_true;
    stack[-9] = v_288;
    goto v_84;
v_86:
    v_288 = stack[-7];
    if (!car_legal(v_288)) v_288 = carerror(v_288); else
    v_288 = qcar(v_288);
    fn = basic_elt(env, 12); // reval
    v_288 = (*qfn1(fn))(fn, v_288);
    env = stack[-11];
    stack[-5] = v_288;
    if (is_number(v_288)) goto v_94;
    stack[-2] = basic_elt(env, 7); // "Invalid argument"
    v_288 = stack[-7];
    if (!car_legal(v_288)) stack[-1] = carerror(v_288); else
    stack[-1] = qcar(v_288);
    stack[0] = basic_elt(env, 8); // "to part"
    v_289 = nil;
    v_288 = lisp_true;
    v_288 = list2(v_289, v_288);
    env = stack[-11];
    fn = basic_elt(env, 15); // msgpri
    v_288 = (*qfn4up(fn))(fn, stack[-2], stack[-1], stack[0], v_288);
    env = stack[-11];
    goto v_84;
v_94:
    v_288 = stack[-8];
    if (!car_legal(v_288)) v_289 = carerror(v_288); else
    v_289 = qcar(v_288);
    v_288 = basic_elt(env, 9); // partop
    v_288 = get(v_289, v_288);
    env = stack[-11];
    stack[-4] = v_288;
    if (v_288 == nil) goto v_107;
    v_290 = stack[-4];
    v_289 = stack[-8];
    v_288 = stack[-5];
    v_288 = Lapply2(nil, v_290, v_289, v_288);
    env = stack[-11];
    stack[-8] = v_288;
    v_288 = stack[-7];
    if (!car_legal(v_288)) v_288 = cdrerror(v_288); else
    v_288 = qcdr(v_288);
    stack[-7] = v_288;
    goto v_79;
v_107:
    v_289 = stack[-5];
    v_288 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_289 == v_288) goto v_118;
    else goto v_119;
v_118:
    v_288 = stack[-8];
    if (!car_legal(v_288)) v_288 = carerror(v_288); else
    v_288 = qcar(v_288);
    stack[0] = v_288;
    v_288 = stack[0];
    fn = basic_elt(env, 11); // getrtype
    v_289 = (*qfn1(fn))(fn, v_288);
    env = stack[-11];
    v_288 = basic_elt(env, 4); // list
    if (v_289 == v_288) goto v_131;
    else goto v_132;
v_131:
    v_288 = basic_elt(env, 4); // list
    stack[-6] = v_288;
    goto v_130;
v_132:
    v_288 = nil;
    goto v_130;
    v_288 = nil;
v_130:
    if (v_288 == nil) goto v_128;
    v_288 = stack[0];
    fn = basic_elt(env, 13); // listeval0
    v_288 = (*qfn1(fn))(fn, v_288);
    env = stack[-11];
    goto v_126;
v_128:
    v_289 = stack[-6];
    v_288 = basic_elt(env, 4); // list
    if (v_289 == v_288) goto v_142;
    else goto v_143;
v_142:
    v_288 = lisp_true;
    qvalue(basic_elt(env, 3)) = v_288; // !*intstr
    v_288 = stack[0];
    fn = basic_elt(env, 12); // reval
    v_288 = (*qfn1(fn))(fn, v_288);
    env = stack[-11];
    stack[0] = v_288;
    v_288 = nil;
    stack[-6] = v_288;
    qvalue(basic_elt(env, 3)) = v_288; // !*intstr
    v_288 = stack[0];
    goto v_126;
v_143:
    v_288 = stack[0];
    goto v_126;
    v_288 = nil;
v_126:
    stack[-8] = v_288;
    v_288 = nil;
    stack[-7] = v_288;
    goto v_79;
v_119:
    v_289 = stack[-5];
    v_288 = (LispObject)0+TAG_FIXNUM; // 0
    v_288 = (LispObject)lessp2(v_289, v_288);
    v_288 = v_288 ? lisp_true : nil;
    env = stack[-11];
    if (v_288 == nil) goto v_156;
    v_288 = stack[-5];
    v_288 = negate(v_288);
    env = stack[-11];
    stack[-5] = v_288;
    v_288 = stack[-8];
    if (!car_legal(v_288)) v_288 = cdrerror(v_288); else
    v_288 = qcdr(v_288);
    v_288 = Lreverse(nil, v_288);
    env = stack[-11];
    stack[-4] = v_288;
    goto v_84;
v_156:
    v_288 = stack[-8];
    if (!car_legal(v_288)) v_288 = cdrerror(v_288); else
    v_288 = qcdr(v_288);
    stack[-4] = v_288;
    goto v_84;
v_84:
    v_288 = stack[-3];
    if (v_288 == nil) goto v_172;
    v_288 = stack[-4];
    if (!car_legal(v_288)) v_288 = carerror(v_288); else
    v_288 = qcar(v_288);
    stack[-4] = v_288;
    v_288 = stack[-4];
    if (!consp(v_288)) goto v_178;
    else goto v_179;
v_178:
    v_289 = stack[-8];
    v_288 = stack[-7];
    if (!car_legal(v_288)) v_288 = carerror(v_288); else
    v_288 = qcar(v_288);
    fn = basic_elt(env, 14); // parterr2
    v_288 = (*qfn2(fn))(fn, v_289, v_288);
    env = stack[-11];
    v_288 = lisp_true;
    stack[-9] = v_288;
    goto v_177;
v_179:
    v_288 = stack[-4];
    if (!car_legal(v_288)) v_288 = cdrerror(v_288); else
    v_288 = qcdr(v_288);
    stack[-4] = v_288;
    goto v_177;
v_177:
    goto v_170;
v_172:
v_170:
    v_288 = stack[-9];
    if (v_288 == nil) goto v_193;
    goto v_191;
v_193:
    v_288 = stack[-4];
    v_289 = Llength(nil, v_288);
    env = stack[-11];
    v_288 = stack[-5];
    v_288 = (LispObject)lessp2(v_289, v_288);
    v_288 = v_288 ? lisp_true : nil;
    env = stack[-11];
    if (v_288 == nil) goto v_197;
    v_289 = stack[-8];
    v_288 = stack[-7];
    if (!car_legal(v_288)) v_288 = carerror(v_288); else
    v_288 = qcar(v_288);
    fn = basic_elt(env, 14); // parterr2
    v_288 = (*qfn2(fn))(fn, v_289, v_288);
    env = stack[-11];
    v_288 = lisp_true;
    stack[-9] = v_288;
    goto v_191;
v_197:
    v_288 = stack[-3];
    if (v_288 == nil) goto v_208;
    v_289 = stack[-4];
    v_288 = stack[-5];
    fn = basic_elt(env, 16); // nth
    v_288 = (*qfn2(fn))(fn, v_289, v_288);
    env = stack[-11];
    stack[-8] = v_288;
    v_288 = stack[-8];
    if (!consp(v_288)) goto v_220;
    v_289 = stack[-8];
    v_288 = basic_elt(env, 6); // !*hold
    v_288 = Leqcar(nil, v_289, v_288);
    env = stack[-11];
    v_288 = (v_288 == nil ? lisp_true : nil);
    goto v_218;
v_220:
    v_288 = nil;
    goto v_218;
    v_288 = nil;
v_218:
    if (v_288 == nil) goto v_216;
    v_289 = basic_elt(env, 6); // !*hold
    v_288 = stack[-8];
    v_288 = list2(v_289, v_288);
    env = stack[-11];
    stack[-8] = v_288;
    goto v_214;
v_216:
v_214:
    goto v_191;
v_208:
    v_289 = stack[-4];
    v_288 = stack[-5];
    fn = basic_elt(env, 16); // nth
    v_288 = (*qfn2(fn))(fn, v_289, v_288);
    env = stack[-11];
    stack[0] = v_288;
    v_288 = stack[0];
    fn = basic_elt(env, 11); // getrtype
    v_289 = (*qfn1(fn))(fn, v_288);
    env = stack[-11];
    v_288 = basic_elt(env, 4); // list
    if (v_289 == v_288) goto v_244;
    else goto v_245;
v_244:
    v_288 = basic_elt(env, 4); // list
    stack[-6] = v_288;
    goto v_243;
v_245:
    v_288 = nil;
    goto v_243;
    v_288 = nil;
v_243:
    if (v_288 == nil) goto v_241;
    v_288 = stack[0];
    fn = basic_elt(env, 13); // listeval0
    v_288 = (*qfn1(fn))(fn, v_288);
    env = stack[-11];
    goto v_239;
v_241:
    v_289 = stack[-6];
    v_288 = basic_elt(env, 4); // list
    if (v_289 == v_288) goto v_255;
    else goto v_256;
v_255:
    v_288 = lisp_true;
    qvalue(basic_elt(env, 3)) = v_288; // !*intstr
    v_288 = stack[0];
    fn = basic_elt(env, 12); // reval
    v_288 = (*qfn1(fn))(fn, v_288);
    env = stack[-11];
    stack[0] = v_288;
    v_288 = nil;
    stack[-6] = v_288;
    qvalue(basic_elt(env, 3)) = v_288; // !*intstr
    v_288 = stack[0];
    goto v_239;
v_256:
    v_288 = stack[0];
    goto v_239;
    v_288 = nil;
v_239:
    stack[-8] = v_288;
    goto v_191;
v_191:
    v_288 = stack[-9];
    if (v_288 == nil) goto v_270;
    v_288 = nil;
    goto v_268;
v_270:
    v_288 = stack[-7];
    if (!car_legal(v_288)) v_288 = cdrerror(v_288); else
    v_288 = qcdr(v_288);
    goto v_268;
    v_288 = nil;
v_268:
    stack[-7] = v_288;
v_79:
    goto v_68;
v_67:
    v_288 = stack[-9];
    if (v_288 == nil) goto v_280;
    v_288 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_278;
v_280:
    v_288 = stack[-8];
    fn = basic_elt(env, 12); // reval
    v_288 = (*qfn1(fn))(fn, v_288);
    goto v_278;
    v_288 = nil;
v_278:
    ;}  // end of a binding scope
    goto v_5;
    v_288 = nil;
v_5:
    return onevalue(v_288);
}



// Code for prepreform1

static LispObject CC_prepreform1(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_160, v_161;
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
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_3;
    stack[0] = v_2;
// end of prologue
v_1:
    v_160 = stack[0];
    if (!consp(v_160)) goto v_11;
    else goto v_12;
v_11:
    v_160 = lisp_true;
    goto v_10;
v_12:
    v_160 = stack[0];
    if (!car_legal(v_160)) v_160 = carerror(v_160); else
    v_160 = qcar(v_160);
    if (!symbolp(v_160)) v_160 = nil;
    else { v_160 = qfastgets(v_160);
           if (v_160 != nil) { v_160 = elt(v_160, 8); // dname
#ifdef RECORD_GET
             if (v_160 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_160 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_160 == SPID_NOPROP) v_160 = nil; }}
#endif
    goto v_10;
    v_160 = nil;
v_10:
    if (v_160 == nil) goto v_8;
    v_160 = stack[0];
    goto v_6;
v_8:
    stack[-6] = nil;
    v_160 = stack[-5];
    stack[-1] = v_160;
v_30:
    v_160 = stack[-6];
    if (v_160 == nil) goto v_37;
    else goto v_38;
v_37:
    v_160 = stack[-1];
    goto v_36;
v_38:
    v_160 = nil;
    goto v_36;
    v_160 = nil;
v_36:
    if (v_160 == nil) goto v_33;
    else goto v_34;
v_33:
    goto v_29;
v_34:
    v_160 = stack[-1];
    if (!car_legal(v_160)) v_161 = carerror(v_160); else
    v_161 = qcar(v_160);
    v_160 = stack[0];
    if (!car_legal(v_160)) v_160 = cdrerror(v_160); else
    v_160 = qcdr(v_160);
    v_160 = Lsmemq(nil, v_161, v_160);
    env = stack[-7];
    if (v_160 == nil) goto v_48;
    v_160 = lisp_true;
    stack[-6] = v_160;
    goto v_46;
v_48:
    v_160 = stack[-1];
    if (!car_legal(v_160)) v_160 = cdrerror(v_160); else
    v_160 = qcdr(v_160);
    stack[-1] = v_160;
    goto v_46;
v_46:
    goto v_30;
v_29:
    v_160 = stack[-6];
    if (v_160 == nil) goto v_61;
    else goto v_62;
v_61:
    v_160 = stack[0];
    goto v_26;
v_62:
    v_160 = stack[0];
    if (!car_legal(v_160)) v_161 = carerror(v_160); else
    v_161 = qcar(v_160);
    v_160 = basic_elt(env, 1); // (plus difference minus times quotient)
    v_160 = Lmemq(nil, v_161, v_160);
    if (v_160 == nil) goto v_69;
    else goto v_67;
v_69:
    v_160 = stack[0];
    if (!car_legal(v_160)) v_160 = carerror(v_160); else
    v_160 = qcar(v_160);
    if (!symbolp(v_160)) v_160 = nil;
    else { v_160 = qfastgets(v_160);
           if (v_160 != nil) { v_160 = elt(v_160, 22); // simpfn
#ifdef RECORD_GET
             if (v_160 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v_160 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v_160 == SPID_NOPROP) v_160 = nil; }}
#endif
    if (v_160 == nil) goto v_67;
    goto v_68;
v_67:
    v_160 = nil;
    stack[-6] = v_160;
    goto v_66;
v_68:
v_66:
    v_160 = stack[0];
    if (!car_legal(v_160)) v_161 = carerror(v_160); else
    v_161 = qcar(v_160);
    v_160 = basic_elt(env, 2); // !*sq
    if (v_161 == v_160) goto v_81;
    else goto v_82;
v_81:
    v_160 = stack[0];
    if (!car_legal(v_160)) v_160 = cdrerror(v_160); else
    v_160 = qcdr(v_160);
    if (!car_legal(v_160)) v_160 = carerror(v_160); else
    v_160 = qcar(v_160);
    fn = basic_elt(env, 3); // sqhorner!*
    v_160 = (*qfn1(fn))(fn, v_160);
    env = stack[-7];
    fn = basic_elt(env, 4); // prepsq!*
    v_161 = (*qfn1(fn))(fn, v_160);
    env = stack[-7];
    v_160 = stack[-5];
    stack[0] = v_161;
    stack[-5] = v_160;
    goto v_1;
v_82:
    v_160 = stack[0];
    if (!car_legal(v_160)) stack[-4] = carerror(v_160); else
    stack[-4] = qcar(v_160);
    v_160 = stack[0];
    if (!car_legal(v_160)) v_160 = cdrerror(v_160); else
    v_160 = qcdr(v_160);
    stack[-3] = v_160;
    v_160 = stack[-3];
    if (v_160 == nil) goto v_108;
    else goto v_109;
v_108:
    v_160 = nil;
    goto v_102;
v_109:
    v_160 = stack[-3];
    if (!car_legal(v_160)) v_160 = carerror(v_160); else
    v_160 = qcar(v_160);
    v_161 = v_160;
    v_160 = stack[-6];
    if (v_160 == nil) goto v_120;
    v_160 = v_161;
    fn = basic_elt(env, 5); // simp!*
    v_160 = (*qfn1(fn))(fn, v_160);
    env = stack[-7];
    fn = basic_elt(env, 3); // sqhorner!*
    v_160 = (*qfn1(fn))(fn, v_160);
    env = stack[-7];
    fn = basic_elt(env, 4); // prepsq!*
    v_160 = (*qfn1(fn))(fn, v_160);
    env = stack[-7];
    v_161 = v_160;
    goto v_118;
v_120:
    v_160 = v_161;
    v_161 = v_160;
    goto v_118;
    v_161 = nil;
v_118:
    v_160 = stack[-5];
    v_160 = CC_prepreform1(basic_elt(env, 0), v_161, v_160);
    env = stack[-7];
    v_160 = ncons(v_160);
    env = stack[-7];
    stack[-1] = v_160;
    stack[-2] = v_160;
v_103:
    v_160 = stack[-3];
    if (!car_legal(v_160)) v_160 = cdrerror(v_160); else
    v_160 = qcdr(v_160);
    stack[-3] = v_160;
    v_160 = stack[-3];
    if (v_160 == nil) goto v_134;
    else goto v_135;
v_134:
    v_160 = stack[-2];
    goto v_102;
v_135:
    stack[0] = stack[-1];
    v_160 = stack[-3];
    if (!car_legal(v_160)) v_160 = carerror(v_160); else
    v_160 = qcar(v_160);
    v_161 = v_160;
    v_160 = stack[-6];
    if (v_160 == nil) goto v_147;
    v_160 = v_161;
    fn = basic_elt(env, 5); // simp!*
    v_160 = (*qfn1(fn))(fn, v_160);
    env = stack[-7];
    fn = basic_elt(env, 3); // sqhorner!*
    v_160 = (*qfn1(fn))(fn, v_160);
    env = stack[-7];
    fn = basic_elt(env, 4); // prepsq!*
    v_160 = (*qfn1(fn))(fn, v_160);
    env = stack[-7];
    v_161 = v_160;
    goto v_145;
v_147:
    v_160 = v_161;
    v_161 = v_160;
    goto v_145;
    v_161 = nil;
v_145:
    v_160 = stack[-5];
    v_160 = CC_prepreform1(basic_elt(env, 0), v_161, v_160);
    env = stack[-7];
    v_160 = ncons(v_160);
    env = stack[-7];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    qcdr(stack[0]) = v_160;
    v_160 = stack[-1];
    if (!car_legal(v_160)) v_160 = cdrerror(v_160); else
    v_160 = qcdr(v_160);
    stack[-1] = v_160;
    goto v_103;
v_102:
    {
        LispObject v_169 = stack[-4];
        return cons(v_169, v_160);
    }
    v_160 = nil;
v_26:
    goto v_6;
    v_160 = nil;
v_6:
    return onevalue(v_160);
}



// Code for extadd

static LispObject CC_extadd(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_113, v_114;
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
    stack[-2] = v_3;
    stack[-3] = v_2;
// end of prologue
    v_113 = stack[-3];
    if (v_113 == nil) goto v_7;
    else goto v_8;
v_7:
    v_113 = stack[-2];
    goto v_6;
v_8:
    v_113 = stack[-2];
    if (v_113 == nil) goto v_11;
    else goto v_12;
v_11:
    v_113 = stack[-3];
    goto v_6;
v_12:
    v_113 = nil;
    v_113 = ncons(v_113);
    env = stack[-5];
    stack[-1] = v_113;
    stack[-4] = v_113;
v_26:
    v_113 = stack[-3];
    if (v_113 == nil) goto v_29;
    v_113 = stack[-2];
    if (v_113 == nil) goto v_29;
    goto v_30;
v_29:
    goto v_25;
v_30:
    v_113 = stack[-2];
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = qcar(v_113);
    if (!car_legal(v_113)) v_114 = carerror(v_113); else
    v_114 = qcar(v_113);
    v_113 = stack[-3];
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = qcar(v_113);
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = qcar(v_113);
    if (equal(v_114, v_113)) goto v_38;
    else goto v_39;
v_38:
    v_113 = stack[-3];
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = qcar(v_113);
    if (!car_legal(v_113)) v_114 = cdrerror(v_113); else
    v_114 = qcdr(v_113);
    v_113 = stack[-2];
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = qcar(v_113);
    if (!car_legal(v_113)) v_113 = cdrerror(v_113); else
    v_113 = qcdr(v_113);
    fn = basic_elt(env, 1); // addf
    v_114 = (*qfn2(fn))(fn, v_114, v_113);
    env = stack[-5];
    v_113 = v_114;
    if (v_114 == nil) goto v_49;
    stack[0] = stack[-1];
    v_114 = stack[-3];
    if (!car_legal(v_114)) v_114 = carerror(v_114); else
    v_114 = qcar(v_114);
    if (!car_legal(v_114)) v_114 = carerror(v_114); else
    v_114 = qcar(v_114);
    v_113 = cons(v_114, v_113);
    env = stack[-5];
    v_113 = ncons(v_113);
    env = stack[-5];
    fn = basic_elt(env, 2); // setcdr
    v_113 = (*qfn2(fn))(fn, stack[0], v_113);
    env = stack[-5];
    v_113 = stack[-1];
    if (!car_legal(v_113)) v_113 = cdrerror(v_113); else
    v_113 = qcdr(v_113);
    stack[-1] = v_113;
    goto v_47;
v_49:
v_47:
    v_113 = stack[-3];
    if (!car_legal(v_113)) v_113 = cdrerror(v_113); else
    v_113 = qcdr(v_113);
    stack[-3] = v_113;
    v_113 = stack[-2];
    if (!car_legal(v_113)) v_113 = cdrerror(v_113); else
    v_113 = qcdr(v_113);
    stack[-2] = v_113;
    goto v_37;
v_39:
    v_113 = stack[-2];
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = qcar(v_113);
    if (!car_legal(v_113)) v_114 = carerror(v_113); else
    v_114 = qcar(v_113);
    v_113 = stack[-3];
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = qcar(v_113);
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = qcar(v_113);
    fn = basic_elt(env, 3); // ordexp
    v_113 = (*qfn2(fn))(fn, v_114, v_113);
    env = stack[-5];
    if (v_113 == nil) goto v_72;
    stack[0] = stack[-1];
    v_113 = stack[-2];
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = qcar(v_113);
    v_113 = ncons(v_113);
    env = stack[-5];
    fn = basic_elt(env, 2); // setcdr
    v_113 = (*qfn2(fn))(fn, stack[0], v_113);
    env = stack[-5];
    v_113 = stack[-2];
    if (!car_legal(v_113)) v_113 = cdrerror(v_113); else
    v_113 = qcdr(v_113);
    stack[-2] = v_113;
    v_113 = stack[-1];
    if (!car_legal(v_113)) v_113 = cdrerror(v_113); else
    v_113 = qcdr(v_113);
    stack[-1] = v_113;
    goto v_37;
v_72:
    stack[0] = stack[-1];
    v_113 = stack[-3];
    if (!car_legal(v_113)) v_113 = carerror(v_113); else
    v_113 = qcar(v_113);
    v_113 = ncons(v_113);
    env = stack[-5];
    fn = basic_elt(env, 2); // setcdr
    v_113 = (*qfn2(fn))(fn, stack[0], v_113);
    env = stack[-5];
    v_113 = stack[-3];
    if (!car_legal(v_113)) v_113 = cdrerror(v_113); else
    v_113 = qcdr(v_113);
    stack[-3] = v_113;
    v_113 = stack[-1];
    if (!car_legal(v_113)) v_113 = cdrerror(v_113); else
    v_113 = qcdr(v_113);
    stack[-1] = v_113;
    goto v_37;
v_37:
    goto v_26;
v_25:
    v_114 = stack[-1];
    v_113 = stack[-3];
    if (v_113 == nil) goto v_105;
    v_113 = stack[-3];
    goto v_103;
v_105:
    v_113 = stack[-2];
    goto v_103;
    v_113 = nil;
v_103:
    fn = basic_elt(env, 2); // setcdr
    v_113 = (*qfn2(fn))(fn, v_114, v_113);
    v_113 = stack[-4];
    if (!car_legal(v_113)) v_113 = cdrerror(v_113); else
    v_113 = qcdr(v_113);
    goto v_6;
    v_113 = nil;
v_6:
    return onevalue(v_113);
}



// Code for read!-comment1

static LispObject CC_readKcomment1(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_48, v_49;
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
    v_48 = v_2;
// end of prologue
// Binding !*lower
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 1, -1);
    qvalue(basic_elt(env, 1)) = nil; // !*lower
// Binding !*raise
// FLUIDBIND: reloadenv=2 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-2, 2, 0);
    qvalue(basic_elt(env, 2)) = nil; // !*raise
    v_48 = nil;
    qvalue(basic_elt(env, 3)) = v_48; // named!-character!*
v_10:
    v_48 = qvalue(basic_elt(env, 3)); // named!-character!*
    if (v_48 == nil) goto v_16;
    else goto v_14;
v_16:
    v_48 = qvalue(basic_elt(env, 4)); // crchar!*
    fn = basic_elt(env, 7); // id2string
    v_48 = (*qfn1(fn))(fn, v_48);
    env = stack[-2];
    fn = basic_elt(env, 8); // string!-length
    v_49 = (*qfn1(fn))(fn, v_48);
    env = stack[-2];
    v_48 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_49 == v_48) goto v_22;
    v_48 = lisp_true;
    goto v_20;
v_22:
    v_48 = qvalue(basic_elt(env, 4)); // crchar!*
    fn = basic_elt(env, 9); // delcp
    v_48 = (*qfn1(fn))(fn, v_48);
    env = stack[-2];
    if (v_48 == nil) goto v_32;
    else goto v_33;
v_32:
    v_48 = lisp_true;
    goto v_31;
v_33:
    v_49 = qvalue(basic_elt(env, 4)); // crchar!*
    v_48 = qvalue(basic_elt(env, 5)); // !$eol!$
    v_48 = (v_49 == v_48 ? lisp_true : nil);
    goto v_31;
    v_48 = nil;
v_31:
    goto v_20;
    v_48 = nil;
v_20:
    if (v_48 == nil) goto v_18;
    else goto v_14;
v_18:
    goto v_15;
v_14:
    v_48 = nil;
    qvalue(basic_elt(env, 3)) = v_48; // named!-character!*
    fn = basic_elt(env, 10); // readch1
    v_48 = (*qfn0(fn))(fn);
    env = stack[-2];
    qvalue(basic_elt(env, 4)) = v_48; // crchar!*
    goto v_10;
v_15:
    v_48 = basic_elt(env, 6); // ! 
    qvalue(basic_elt(env, 4)) = v_48; // crchar!*
    fn = basic_elt(env, 11); // condterpri
    v_48 = (*qfn0(fn))(fn);
    v_48 = nil;
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_48);
}



// Code for subtractinds

static LispObject CC_subtractinds(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_45, v_46;
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
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_4;
    stack[-2] = v_3;
    stack[-3] = v_2;
// end of prologue
v_10:
    v_45 = stack[-2];
    if (v_45 == nil) goto v_13;
    else goto v_14;
v_13:
    v_45 = stack[-1];
        return Lnreverse(nil, v_45);
v_14:
    v_45 = stack[-3];
    if (!car_legal(v_45)) v_46 = carerror(v_45); else
    v_46 = qcar(v_45);
    v_45 = stack[-2];
    if (!car_legal(v_45)) v_45 = carerror(v_45); else
    v_45 = qcar(v_45);
    if (!car_legal(v_45)) v_45 = carerror(v_45); else
    v_45 = qcar(v_45);
    v_46 = difference2(v_46, v_45);
    env = stack[-5];
    v_45 = (LispObject)0+TAG_FIXNUM; // 0
    v_45 = (LispObject)lessp2(v_46, v_45);
    v_45 = v_45 ? lisp_true : nil;
    env = stack[-5];
    if (v_45 == nil) goto v_19;
    v_45 = nil;
    goto v_9;
v_19:
    v_45 = stack[-3];
    if (!car_legal(v_45)) v_45 = cdrerror(v_45); else
    v_45 = qcdr(v_45);
    stack[-4] = v_45;
    v_45 = stack[-2];
    if (!car_legal(v_45)) v_45 = cdrerror(v_45); else
    v_45 = qcdr(v_45);
    stack[0] = v_45;
    v_45 = stack[-3];
    if (!car_legal(v_45)) v_46 = carerror(v_45); else
    v_46 = qcar(v_45);
    v_45 = stack[-2];
    if (!car_legal(v_45)) v_45 = carerror(v_45); else
    v_45 = qcar(v_45);
    if (!car_legal(v_45)) v_45 = carerror(v_45); else
    v_45 = qcar(v_45);
    v_46 = difference2(v_46, v_45);
    env = stack[-5];
    v_45 = stack[-1];
    v_45 = cons(v_46, v_45);
    env = stack[-5];
    stack[-1] = v_45;
    v_45 = stack[0];
    stack[-2] = v_45;
    v_45 = stack[-4];
    stack[-3] = v_45;
    goto v_10;
    v_45 = nil;
v_9:
    return onevalue(v_45);
}



// Code for mk!+equation

static LispObject CC_mkLequation(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_11, v_12, v_13;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11 = v_3;
    v_12 = v_2;
// end of prologue
    v_13 = basic_elt(env, 1); // equal
    return list3(v_13, v_12, v_11);
    return onevalue(v_11);
}



// Code for rl_identity1

static LispObject CC_rl_identity1(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_5;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5 = v_2;
// end of prologue
    return onevalue(v_5);
}



// Code for bc_sum

static LispObject CC_bc_sum(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_64, v_65, v_66, v_67;
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
    v_66 = v_3;
    v_67 = v_2;
// end of prologue
    v_64 = v_67;
    if (!car_legal(v_64)) v_65 = cdrerror(v_64); else
    v_65 = qcdr(v_64);
    v_64 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_65 == v_64) goto v_11;
    else goto v_12;
v_11:
    v_64 = v_67;
    if (!car_legal(v_64)) v_64 = carerror(v_64); else
    v_64 = qcar(v_64);
    if (is_number(v_64)) goto v_19;
    v_64 = nil;
    goto v_17;
v_19:
    v_64 = v_66;
    if (!car_legal(v_64)) v_65 = cdrerror(v_64); else
    v_65 = qcdr(v_64);
    v_64 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_65 == v_64) goto v_27;
    else goto v_28;
v_27:
    v_64 = v_66;
    if (!car_legal(v_64)) v_64 = carerror(v_64); else
    v_64 = qcar(v_64);
    v_64 = (is_number(v_64) ? lisp_true : nil);
    goto v_26;
v_28:
    v_64 = nil;
    goto v_26;
    v_64 = nil;
v_26:
    goto v_17;
    v_64 = nil;
v_17:
    goto v_10;
v_12:
    v_64 = nil;
    goto v_10;
    v_64 = nil;
v_10:
    if (v_64 == nil) goto v_8;
    v_64 = v_67;
    if (!car_legal(v_64)) v_64 = carerror(v_64); else
    v_64 = qcar(v_64);
    v_65 = v_66;
    if (!car_legal(v_65)) v_65 = carerror(v_65); else
    v_65 = qcar(v_65);
    v_65 = plus2(v_64, v_65);
    v_67 = v_65;
    v_64 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_65 == v_64) goto v_43;
    else goto v_44;
v_43:
    v_65 = nil;
    v_64 = (LispObject)16+TAG_FIXNUM; // 1
    return cons(v_65, v_64);
v_44:
    v_65 = v_67;
    v_64 = (LispObject)16+TAG_FIXNUM; // 1
    return cons(v_65, v_64);
    v_64 = nil;
    goto v_6;
v_8:
    v_64 = v_67;
    v_65 = v_66;
    {
        fn = basic_elt(env, 1); // addsq
        return (*qfn2(fn))(fn, v_64, v_65);
    }
    v_64 = nil;
v_6:
    return onevalue(v_64);
}



// Code for ofsf_anegrel

static LispObject CC_ofsf_anegrel(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_15, v_16, v_17;
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
    v_17 = v_2;
// end of prologue
    v_16 = v_17;
    v_15 = basic_elt(env, 1); // ((equal . equal) (neq . neq) (leq . geq) (geq . leq) (lessp . greaterp) (greaterp . lessp))
    v_15 = Latsoc(nil, v_16, v_15);
    if (!car_legal(v_15)) v_15 = cdrerror(v_15); else
    v_15 = qcdr(v_15);
    if (v_15 == nil) goto v_6;
    else goto v_5;
v_6:
    v_15 = basic_elt(env, 2); // "ofsf_anegrel: unknown operator "
    v_16 = v_17;
    v_15 = list2(v_15, v_16);
    env = stack[0];
    {
        fn = basic_elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_15);
    }
v_5:
    return onevalue(v_15);
}



// Code for ciom

static LispObject CC_ciom(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_55, v_56;
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
    v_55 = basic_elt(env, 1); // "<OMATTR>"
    fn = basic_elt(env, 9); // printout
    v_55 = (*qfn1(fn))(fn, v_55);
    env = stack[-1];
    v_55 = lisp_true;
    fn = basic_elt(env, 10); // indent!*
    v_55 = (*qfn1(fn))(fn, v_55);
    env = stack[-1];
    v_55 = basic_elt(env, 2); // "<OMATP>"
    fn = basic_elt(env, 9); // printout
    v_55 = (*qfn1(fn))(fn, v_55);
    env = stack[-1];
    v_55 = lisp_true;
    fn = basic_elt(env, 10); // indent!*
    v_55 = (*qfn1(fn))(fn, v_55);
    env = stack[-1];
    v_55 = basic_elt(env, 3); // "<OMS cd=""typmml"" name=""type"">"
    fn = basic_elt(env, 9); // printout
    v_55 = (*qfn1(fn))(fn, v_55);
    env = stack[-1];
    v_55 = basic_elt(env, 4); // "<OMS cd=""typmml"" name="""
    fn = basic_elt(env, 9); // printout
    v_55 = (*qfn1(fn))(fn, v_55);
    env = stack[-1];
    v_55 = stack[0];
    if (!car_legal(v_55)) v_55 = cdrerror(v_55); else
    v_55 = qcdr(v_55);
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = qcar(v_55);
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = qcar(v_55);
    if (!car_legal(v_55)) v_55 = cdrerror(v_55); else
    v_55 = qcdr(v_55);
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = qcar(v_55);
    v_56 = Lintern(nil, v_55);
    env = stack[-1];
    v_55 = qvalue(basic_elt(env, 5)); // mmltypes!*
    v_55 = Lassoc(nil, v_56, v_55);
    v_55 = Lprinc(nil, v_55);
    env = stack[-1];
    v_55 = stack[0];
    if (!car_legal(v_55)) v_55 = cdrerror(v_55); else
    v_55 = qcdr(v_55);
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = qcar(v_55);
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = qcar(v_55);
    if (!car_legal(v_55)) v_55 = cdrerror(v_55); else
    v_55 = qcdr(v_55);
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = qcar(v_55);
    v_56 = Lintern(nil, v_55);
    env = stack[-1];
    v_55 = qvalue(basic_elt(env, 5)); // mmltypes!*
    v_55 = Lassoc(nil, v_56, v_55);
    if (!car_legal(v_55)) v_55 = cdrerror(v_55); else
    v_55 = qcdr(v_55);
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = qcar(v_55);
    v_55 = Lprinc(nil, v_55);
    env = stack[-1];
    v_55 = basic_elt(env, 6); // """>"
    v_55 = Lprinc(nil, v_55);
    env = stack[-1];
    v_55 = nil;
    fn = basic_elt(env, 10); // indent!*
    v_55 = (*qfn1(fn))(fn, v_55);
    env = stack[-1];
    v_55 = basic_elt(env, 7); // "</OMATP>"
    fn = basic_elt(env, 9); // printout
    v_55 = (*qfn1(fn))(fn, v_55);
    env = stack[-1];
    v_55 = stack[0];
    if (!car_legal(v_55)) v_55 = cdrerror(v_55); else
    v_55 = qcdr(v_55);
    if (!car_legal(v_55)) v_55 = cdrerror(v_55); else
    v_55 = qcdr(v_55);
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = qcar(v_55);
    fn = basic_elt(env, 11); // objectom
    v_55 = (*qfn1(fn))(fn, v_55);
    env = stack[-1];
    v_55 = nil;
    fn = basic_elt(env, 10); // indent!*
    v_55 = (*qfn1(fn))(fn, v_55);
    env = stack[-1];
    v_55 = basic_elt(env, 8); // "</OMATTR>"
    fn = basic_elt(env, 9); // printout
    v_55 = (*qfn1(fn))(fn, v_55);
    v_55 = nil;
    return onevalue(v_55);
}



// Code for letmtr

static LispObject CC_letmtr(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_55, v_56, v_57;
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
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_4;
    stack[-3] = v_3;
    stack[-4] = v_2;
// end of prologue
    stack[-5] = nil;
    v_56 = stack[-2];
    v_55 = basic_elt(env, 1); // mat
    if (!consp(v_56)) goto v_11;
    v_56 = qcar(v_56);
    if (v_56 == v_55) goto v_12;
v_11:
    stack[-1] = basic_elt(env, 2); // matrix
    stack[0] = (LispObject)160+TAG_FIXNUM; // 10
    v_57 = basic_elt(env, 3); // "Matrix"
    v_55 = stack[-4];
    if (!car_legal(v_55)) v_56 = carerror(v_55); else
    v_56 = qcar(v_55);
    v_55 = basic_elt(env, 4); // "not set"
    v_55 = list3(v_57, v_56, v_55);
    env = stack[-6];
    fn = basic_elt(env, 6); // rerror
    v_55 = (*qfn3(fn))(fn, stack[-1], stack[0], v_55);
    env = stack[-6];
    goto v_10;
v_12:
    v_55 = stack[-4];
    if (!car_legal(v_55)) v_55 = cdrerror(v_55); else
    v_55 = qcdr(v_55);
    fn = basic_elt(env, 7); // revlis
    v_55 = (*qfn1(fn))(fn, v_55);
    env = stack[-6];
    stack[-5] = v_55;
    fn = basic_elt(env, 8); // numlis
    v_55 = (*qfn1(fn))(fn, v_55);
    env = stack[-6];
    if (v_55 == nil) goto v_28;
    else goto v_29;
v_28:
    v_55 = lisp_true;
    goto v_27;
v_29:
    v_55 = stack[-5];
    v_56 = Llength(nil, v_55);
    env = stack[-6];
    v_55 = (LispObject)32+TAG_FIXNUM; // 2
    v_55 = Lneq_2(nil, v_56, v_55);
    env = stack[-6];
    goto v_27;
    v_55 = nil;
v_27:
    if (v_55 == nil) goto v_25;
    v_56 = stack[-4];
    v_55 = basic_elt(env, 5); // hold
    {
        fn = basic_elt(env, 9); // errpri2
        return (*qfn2(fn))(fn, v_56, v_55);
    }
v_25:
v_10:
    v_55 = stack[-2];
    if (!car_legal(v_55)) v_56 = cdrerror(v_55); else
    v_56 = qcdr(v_55);
    v_55 = stack[-5];
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = qcar(v_55);
    fn = basic_elt(env, 10); // nth
    v_56 = (*qfn2(fn))(fn, v_56, v_55);
    env = stack[-6];
    v_55 = stack[-5];
    if (!car_legal(v_55)) v_55 = cdrerror(v_55); else
    v_55 = qcdr(v_55);
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = qcar(v_55);
    fn = basic_elt(env, 11); // pnth
    v_56 = (*qfn2(fn))(fn, v_56, v_55);
    v_55 = stack[-3];
    if (!car_legal(v_56)) rplaca_fails(v_56);
    qcar(v_56) = v_55;
    v_55 = nil;
    return onevalue(v_55);
}



// Code for a2vdp

static LispObject CC_a2vdp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_43, v_44, v_45;
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
    v_45 = v_2;
// end of prologue
    v_44 = v_45;
    v_43 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_44 == v_43) goto v_10;
    else goto v_11;
v_10:
    v_43 = lisp_true;
    goto v_9;
v_11:
    v_43 = v_45;
    v_43 = (v_43 == nil ? lisp_true : nil);
    goto v_9;
    v_43 = nil;
v_9:
    if (v_43 == nil) goto v_7;
    stack[-2] = basic_elt(env, 1); // vdp
    stack[-1] = nil;
    v_44 = nil;
    v_43 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = cons(v_44, v_43);
    env = stack[-3];
    v_44 = nil;
    v_43 = nil;
    v_43 = list2(v_44, v_43);
    {
        LispObject v_49 = stack[-2];
        LispObject v_50 = stack[-1];
        LispObject v_51 = stack[0];
        return list3star(v_49, v_50, v_51, v_43);
    }
v_7:
    v_43 = v_45;
    fn = basic_elt(env, 2); // a2dip
    v_43 = (*qfn1(fn))(fn, v_43);
    env = stack[-3];
    v_44 = v_43;
    stack[-2] = basic_elt(env, 1); // vdp
    v_43 = v_44;
    if (!car_legal(v_43)) stack[-1] = carerror(v_43); else
    stack[-1] = qcar(v_43);
    v_43 = v_44;
    if (!car_legal(v_43)) v_43 = cdrerror(v_43); else
    v_43 = qcdr(v_43);
    if (!car_legal(v_43)) stack[0] = carerror(v_43); else
    stack[0] = qcar(v_43);
    v_43 = nil;
    v_43 = list2(v_44, v_43);
    {
        LispObject v_52 = stack[-2];
        LispObject v_53 = stack[-1];
        LispObject v_54 = stack[0];
        return list3star(v_52, v_53, v_54, v_43);
    }
    v_43 = nil;
    return onevalue(v_43);
}



// Code for remove_least_item

static LispObject CC_remove_least_item(LispObject env,
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
// copy arguments values to proper place
    v_28 = v_2;
// end of prologue
v_6:
    v_29 = v_28;
    if (!car_legal(v_29)) v_29 = cdrerror(v_29); else
    v_29 = qcdr(v_29);
    if (v_29 == nil) goto v_9;
    else goto v_10;
v_9:
    v_28 = basic_elt(env, 1); // "How did we get here?"
    {
        fn = basic_elt(env, 2); // rederr
        return (*qfn1(fn))(fn, v_28);
    }
v_10:
    v_29 = v_28;
    if (!car_legal(v_29)) v_29 = cdrerror(v_29); else
    v_29 = qcdr(v_29);
    if (!car_legal(v_29)) v_29 = carerror(v_29); else
    v_29 = qcar(v_29);
    if (!car_legal(v_29)) v_29 = cdrerror(v_29); else
    v_29 = qcdr(v_29);
    if (v_29 == nil) goto v_15;
    else goto v_16;
v_15:
    {
        fn = basic_elt(env, 3); // remove_root_item
        return (*qfn1(fn))(fn, v_28);
    }
v_16:
    if (!car_legal(v_28)) v_28 = cdrerror(v_28); else
    v_28 = qcdr(v_28);
    if (!car_legal(v_28)) v_28 = carerror(v_28); else
    v_28 = qcar(v_28);
    goto v_6;
    v_28 = nil;
    return onevalue(v_28);
}



// Code for mkassign

static LispObject CC_mkassign(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_9, v_10, v_11;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9 = v_3;
    v_10 = v_2;
// end of prologue
    v_11 = basic_elt(env, 1); // setq
    return list3(v_11, v_10, v_9);
}



// Code for strand!-alg!-top

static LispObject CC_strandKalgKtop(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_23, v_24, v_25;
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
    stack[0] = v_4;
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
    v_24 = stack[-2];
    v_23 = stack[0];
    fn = basic_elt(env, 1); // deletez1
    v_23 = (*qfn2(fn))(fn, v_24, v_23);
    env = stack[-3];
    stack[-2] = v_23;
    v_25 = stack[0];
    v_24 = stack[-1];
    v_23 = (LispObject)16+TAG_FIXNUM; // 1
    fn = basic_elt(env, 2); // color!-strand
    v_23 = (*qfn3(fn))(fn, v_25, v_24, v_23);
    env = stack[-3];
    stack[0] = v_23;
    v_24 = stack[-2];
    v_23 = stack[0];
    fn = basic_elt(env, 3); // contract!-strand
    v_23 = (*qfn2(fn))(fn, v_24, v_23);
    env = stack[-3];
    stack[-2] = v_23;
    v_25 = stack[-2];
    v_24 = stack[0];
    v_23 = nil;
    {
        fn = basic_elt(env, 4); // dstr!-to!-alg
        return (*qfn3(fn))(fn, v_25, v_24, v_23);
    }
    return onevalue(v_23);
}



// Code for mchsarg

static LispObject CC_mchsarg(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_124, v_125;
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
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-6] = v_4;
    stack[-7] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_124 = stack[-7];
    fn = basic_elt(env, 2); // mtp
    v_124 = (*qfn1(fn))(fn, v_124);
    env = stack[-9];
    if (v_124 == nil) goto v_10;
    v_125 = stack[-6];
    v_124 = basic_elt(env, 1); // times
    if (v_125 == v_124) goto v_18;
    v_124 = lisp_true;
    goto v_16;
v_18:
    v_124 = stack[-1];
    fn = basic_elt(env, 3); // noncomfree
    v_124 = (*qfn1(fn))(fn, v_124);
    env = stack[-9];
    goto v_16;
    v_124 = nil;
v_16:
    if (v_124 == nil) goto v_10;
    v_124 = stack[-7];
    fn = basic_elt(env, 4); // noncomperm
    v_124 = (*qfn1(fn))(fn, v_124);
    env = stack[-9];
    stack[-4] = v_124;
    v_124 = stack[-4];
    if (v_124 == nil) goto v_36;
    else goto v_37;
v_36:
    v_124 = nil;
    goto v_30;
v_37:
    v_124 = stack[-4];
    if (!car_legal(v_124)) v_124 = carerror(v_124); else
    v_124 = qcar(v_124);
    v_125 = v_124;
    v_124 = stack[-1];
    fn = basic_elt(env, 5); // pair
    v_124 = (*qfn2(fn))(fn, v_125, v_124);
    env = stack[-9];
    v_124 = ncons(v_124);
    env = stack[-9];
    stack[-2] = v_124;
    stack[-3] = v_124;
v_31:
    v_124 = stack[-4];
    if (!car_legal(v_124)) v_124 = cdrerror(v_124); else
    v_124 = qcdr(v_124);
    stack[-4] = v_124;
    v_124 = stack[-4];
    if (v_124 == nil) goto v_51;
    else goto v_52;
v_51:
    v_124 = stack[-3];
    goto v_30;
v_52:
    stack[0] = stack[-2];
    v_124 = stack[-4];
    if (!car_legal(v_124)) v_124 = carerror(v_124); else
    v_124 = qcar(v_124);
    v_125 = v_124;
    v_124 = stack[-1];
    fn = basic_elt(env, 5); // pair
    v_124 = (*qfn2(fn))(fn, v_125, v_124);
    env = stack[-9];
    v_124 = ncons(v_124);
    env = stack[-9];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    qcdr(stack[0]) = v_124;
    v_124 = stack[-2];
    if (!car_legal(v_124)) v_124 = cdrerror(v_124); else
    v_124 = qcdr(v_124);
    stack[-2] = v_124;
    goto v_31;
v_30:
    goto v_8;
v_10:
    v_124 = stack[-1];
    fn = basic_elt(env, 4); // noncomperm
    v_124 = (*qfn1(fn))(fn, v_124);
    env = stack[-9];
    stack[-8] = v_124;
v_73:
    v_124 = stack[-8];
    if (v_124 == nil) goto v_79;
    else goto v_80;
v_79:
    v_124 = nil;
    goto v_72;
v_80:
    v_124 = stack[-8];
    if (!car_legal(v_124)) v_124 = carerror(v_124); else
    v_124 = qcar(v_124);
    stack[-2] = v_124;
    stack[-1] = stack[-7];
    v_124 = nil;
    stack[0] = ncons(v_124);
    env = stack[-9];
    v_124 = stack[-6];
    v_124 = ncons(v_124);
    env = stack[-9];
    fn = basic_elt(env, 6); // mcharg2
    v_124 = (*qfn4up(fn))(fn, stack[-2], stack[-1], stack[0], v_124);
    env = stack[-9];
    stack[-5] = v_124;
    v_124 = stack[-5];
    fn = basic_elt(env, 7); // lastpair
    v_124 = (*qfn1(fn))(fn, v_124);
    env = stack[-9];
    stack[-4] = v_124;
    v_124 = stack[-8];
    if (!car_legal(v_124)) v_124 = cdrerror(v_124); else
    v_124 = qcdr(v_124);
    stack[-8] = v_124;
    v_124 = stack[-4];
    if (!consp(v_124)) goto v_99;
    else goto v_100;
v_99:
    goto v_73;
v_100:
v_74:
    v_124 = stack[-8];
    if (v_124 == nil) goto v_104;
    else goto v_105;
v_104:
    v_124 = stack[-5];
    goto v_72;
v_105:
    stack[-3] = stack[-4];
    v_124 = stack[-8];
    if (!car_legal(v_124)) v_124 = carerror(v_124); else
    v_124 = qcar(v_124);
    stack[-2] = v_124;
    stack[-1] = stack[-7];
    v_124 = nil;
    stack[0] = ncons(v_124);
    env = stack[-9];
    v_124 = stack[-6];
    v_124 = ncons(v_124);
    env = stack[-9];
    fn = basic_elt(env, 6); // mcharg2
    v_124 = (*qfn4up(fn))(fn, stack[-2], stack[-1], stack[0], v_124);
    env = stack[-9];
    if (!car_legal(stack[-3])) rplacd_fails(stack[-3]);
    qcdr(stack[-3]) = v_124;
    v_124 = stack[-4];
    fn = basic_elt(env, 7); // lastpair
    v_124 = (*qfn1(fn))(fn, v_124);
    env = stack[-9];
    stack[-4] = v_124;
    v_124 = stack[-8];
    if (!car_legal(v_124)) v_124 = cdrerror(v_124); else
    v_124 = qcdr(v_124);
    stack[-8] = v_124;
    goto v_74;
v_72:
    goto v_8;
    v_124 = nil;
v_8:
    {
        fn = basic_elt(env, 8); // reversip!*
        return (*qfn1(fn))(fn, v_124);
    }
}



// Code for appr

static LispObject CC_appr(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_24, v_25, v_26;
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
    v_24 = v_3;
    v_25 = v_2;
// end of prologue
v_8:
    v_26 = v_25;
    if (v_26 == nil) goto v_11;
    else goto v_12;
v_11:
    goto v_7;
v_12:
    v_26 = v_25;
    if (!car_legal(v_26)) v_26 = cdrerror(v_26); else
    v_26 = qcdr(v_26);
    stack[0] = v_26;
    if (!car_legal(v_25)) v_25 = carerror(v_25); else
    v_25 = qcar(v_25);
    v_24 = cons(v_25, v_24);
    env = stack[-1];
    v_25 = stack[0];
    goto v_8;
    v_24 = nil;
v_7:
    return onevalue(v_24);
}



// Code for cl_subfof

static LispObject CC_cl_subfof(LispObject env,
                         LispObject v_2, LispObject v_3)
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
        push2(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_3;
    stack[-5] = v_2;
// end of prologue
    stack[-6] = nil;
    stack[-2] = nil;
    v_59 = stack[-5];
    fn = basic_elt(env, 1); // rl_subalchk
    v_59 = (*qfn1(fn))(fn, v_59);
    env = stack[-7];
    v_59 = stack[-5];
    stack[-1] = v_59;
v_15:
    v_59 = stack[-1];
    if (v_59 == nil) goto v_19;
    else goto v_20;
v_19:
    goto v_14;
v_20:
    v_59 = stack[-1];
    if (!car_legal(v_59)) v_59 = carerror(v_59); else
    v_59 = qcar(v_59);
    stack[0] = v_59;
    v_59 = stack[0];
    fn = basic_elt(env, 2); // rl_eqnrhskernels
    v_59 = (*qfn1(fn))(fn, v_59);
    env = stack[-7];
    stack[-3] = v_59;
    v_59 = stack[0];
    if (!car_legal(v_59)) v_60 = carerror(v_59); else
    v_60 = qcar(v_59);
    v_59 = stack[-3];
    v_59 = cons(v_60, v_59);
    env = stack[-7];
    v_60 = ncons(v_59);
    env = stack[-7];
    v_59 = stack[-6];
    v_59 = list2(v_60, v_59);
    env = stack[-7];
    fn = basic_elt(env, 3); // lto_alunion
    v_59 = (*qfn1(fn))(fn, v_59);
    env = stack[-7];
    stack[-6] = v_59;
    v_59 = stack[0];
    if (!car_legal(v_59)) stack[0] = carerror(v_59); else
    stack[0] = qcar(v_59);
    v_60 = stack[-3];
    v_59 = stack[-2];
    v_59 = Lappend_2(nil, v_60, v_59);
    env = stack[-7];
    v_59 = cons(stack[0], v_59);
    env = stack[-7];
    stack[-2] = v_59;
    v_59 = stack[-1];
    if (!car_legal(v_59)) v_59 = cdrerror(v_59); else
    v_59 = qcdr(v_59);
    stack[-1] = v_59;
    goto v_15;
v_14:
    v_59 = stack[-4];
    fn = basic_elt(env, 4); // cl_varl1
    v_59 = (*qfn1(fn))(fn, v_59);
    env = stack[-7];
    stack[-3] = v_59;
    v_61 = stack[-2];
    v_59 = stack[-3];
    if (!car_legal(v_59)) v_60 = carerror(v_59); else
    v_60 = qcar(v_59);
    v_59 = stack[-3];
    if (!car_legal(v_59)) v_59 = cdrerror(v_59); else
    v_59 = qcdr(v_59);
    v_59 = list3(v_61, v_60, v_59);
    env = stack[-7];
    fn = basic_elt(env, 5); // lto_nconcn
    v_59 = (*qfn1(fn))(fn, v_59);
    env = stack[-7];
    stack[-2] = v_59;
    stack[0] = stack[-5];
    stack[-1] = stack[-4];
    stack[-3] = stack[-6];
    v_59 = stack[-2];
    v_59 = ncons(v_59);
    env = stack[-7];
    {
        LispObject v_69 = stack[0];
        LispObject v_70 = stack[-1];
        LispObject v_71 = stack[-3];
        fn = basic_elt(env, 6); // cl_subfof1
        return (*qfn4up(fn))(fn, v_69, v_70, v_71, v_59);
    }
    return onevalue(v_59);
}



// Code for conditionml

static LispObject CC_conditionml(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_17;
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
    v_17 = basic_elt(env, 1); // "<condition>"
    fn = basic_elt(env, 3); // printout
    v_17 = (*qfn1(fn))(fn, v_17);
    env = stack[-1];
    v_17 = lisp_true;
    fn = basic_elt(env, 4); // indent!*
    v_17 = (*qfn1(fn))(fn, v_17);
    env = stack[-1];
    v_17 = stack[0];
    if (!car_legal(v_17)) v_17 = carerror(v_17); else
    v_17 = qcar(v_17);
    fn = basic_elt(env, 5); // expression
    v_17 = (*qfn1(fn))(fn, v_17);
    env = stack[-1];
    v_17 = nil;
    fn = basic_elt(env, 4); // indent!*
    v_17 = (*qfn1(fn))(fn, v_17);
    env = stack[-1];
    v_17 = basic_elt(env, 2); // "</condition>"
    fn = basic_elt(env, 3); // printout
    v_17 = (*qfn1(fn))(fn, v_17);
    v_17 = nil;
    return onevalue(v_17);
}



// Code for f4

static LispObject CC_f4(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_200, v_201;
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
    v_201 = stack[0];
    v_200 = basic_elt(env, 1); // pi
    if (v_201 == v_200) goto v_8;
    else goto v_9;
v_8:
    v_200 = basic_elt(env, 2); // "<pi/>"
    v_200 = Lprinc(nil, v_200);
    goto v_7;
v_9:
    v_201 = stack[0];
    v_200 = basic_elt(env, 3); // euler_gamma
    if (v_201 == v_200) goto v_14;
    else goto v_15;
v_14:
    v_200 = basic_elt(env, 4); // "<eulergamma/>"
    v_200 = Lprinc(nil, v_200);
    goto v_7;
v_15:
    v_201 = stack[0];
    v_200 = basic_elt(env, 5); // true
    if (v_201 == v_200) goto v_20;
    else goto v_21;
v_20:
    v_200 = basic_elt(env, 6); // "<true/>"
    v_200 = Lprinc(nil, v_200);
    goto v_7;
v_21:
    v_201 = stack[0];
    v_200 = basic_elt(env, 7); // false
    if (v_201 == v_200) goto v_26;
    else goto v_27;
v_26:
    v_200 = basic_elt(env, 8); // "<false/>"
    v_200 = Lprinc(nil, v_200);
    goto v_7;
v_27:
    v_201 = stack[0];
    v_200 = basic_elt(env, 9); // !Na!N
    if (v_201 == v_200) goto v_32;
    else goto v_33;
v_32:
    v_200 = basic_elt(env, 10); // "<notanumber/>"
    v_200 = Lprinc(nil, v_200);
    goto v_7;
v_33:
    v_201 = stack[0];
    v_200 = basic_elt(env, 11); // infinity
    if (v_201 == v_200) goto v_38;
    else goto v_39;
v_38:
    v_200 = qvalue(basic_elt(env, 12)); // !*web
    if (v_200 == nil) goto v_44;
    else goto v_45;
v_44:
    v_200 = basic_elt(env, 13); // "<cn type=""constant"">"
    fn = basic_elt(env, 33); // printout
    v_200 = (*qfn1(fn))(fn, v_200);
    env = stack[-1];
    goto v_43;
v_45:
    v_200 = basic_elt(env, 14); // "<cn type=&quot;constant&quot;>"
    fn = basic_elt(env, 33); // printout
    v_200 = (*qfn1(fn))(fn, v_200);
    env = stack[-1];
    goto v_43;
v_43:
    v_200 = basic_elt(env, 15); // "&infin;"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    v_200 = basic_elt(env, 16); // "</cn>"
    v_200 = Lprinc(nil, v_200);
    goto v_7;
v_39:
    v_201 = stack[0];
    v_200 = basic_elt(env, 17); // e
    if (v_201 == v_200) goto v_61;
    else goto v_62;
v_61:
    v_200 = qvalue(basic_elt(env, 12)); // !*web
    if (v_200 == nil) goto v_67;
    else goto v_68;
v_67:
    v_200 = basic_elt(env, 13); // "<cn type=""constant"">"
    fn = basic_elt(env, 33); // printout
    v_200 = (*qfn1(fn))(fn, v_200);
    env = stack[-1];
    goto v_66;
v_68:
    v_200 = basic_elt(env, 14); // "<cn type=&quot;constant&quot;>"
    fn = basic_elt(env, 33); // printout
    v_200 = (*qfn1(fn))(fn, v_200);
    env = stack[-1];
    goto v_66;
v_66:
    v_200 = basic_elt(env, 18); // "&ExponentialE;"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    v_200 = basic_elt(env, 16); // "</cn>"
    v_200 = Lprinc(nil, v_200);
    goto v_60;
v_62:
    v_201 = stack[0];
    v_200 = basic_elt(env, 19); // i
    if (v_201 == v_200) goto v_84;
    else goto v_85;
v_84:
    v_200 = qvalue(basic_elt(env, 12)); // !*web
    if (v_200 == nil) goto v_90;
    else goto v_91;
v_90:
    v_200 = basic_elt(env, 13); // "<cn type=""constant"">"
    fn = basic_elt(env, 33); // printout
    v_200 = (*qfn1(fn))(fn, v_200);
    env = stack[-1];
    goto v_89;
v_91:
    v_200 = basic_elt(env, 14); // "<cn type=&quot;constant&quot;>"
    fn = basic_elt(env, 33); // printout
    v_200 = (*qfn1(fn))(fn, v_200);
    env = stack[-1];
    goto v_89;
v_89:
    v_200 = basic_elt(env, 20); // "&ImaginaryI;"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    v_200 = basic_elt(env, 16); // "</cn>"
    v_200 = Lprinc(nil, v_200);
    goto v_83;
v_85:
    v_200 = stack[0];
    if (is_number(v_200)) goto v_107;
    else goto v_108;
v_107:
    v_200 = basic_elt(env, 21); // "<cn"
    fn = basic_elt(env, 33); // printout
    v_200 = (*qfn1(fn))(fn, v_200);
    env = stack[-1];
    v_200 = stack[0];
    v_200 = Lfloatp(nil, v_200);
    env = stack[-1];
    if (v_200 == nil) goto v_115;
    v_200 = qvalue(basic_elt(env, 12)); // !*web
    if (v_200 == nil) goto v_120;
    else goto v_121;
v_120:
    v_200 = basic_elt(env, 22); // " type=""real"">"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_119;
v_121:
    v_200 = basic_elt(env, 23); // " type=&quot;real&quot;>"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_119;
v_119:
    goto v_113;
v_115:
    v_200 = stack[0];
    v_200 = integerp(v_200);
    if (v_200 == nil) goto v_130;
    v_200 = qvalue(basic_elt(env, 12)); // !*web
    if (v_200 == nil) goto v_135;
    else goto v_136;
v_135:
    v_200 = basic_elt(env, 24); // " type=""integer"">"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_134;
v_136:
    v_200 = basic_elt(env, 25); // " type=&quot;integer&quot;>"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_134;
v_134:
    goto v_113;
v_130:
    v_200 = basic_elt(env, 26); // ">"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_113;
v_113:
    v_200 = stack[0];
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    v_200 = basic_elt(env, 16); // "</cn>"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_106;
v_108:
v_106:
    v_200 = stack[0];
    if (symbolp(v_200)) goto v_154;
    else goto v_155;
v_154:
    v_200 = basic_elt(env, 27); // "<ci"
    fn = basic_elt(env, 33); // printout
    v_200 = (*qfn1(fn))(fn, v_200);
    env = stack[-1];
    v_200 = stack[0];
    fn = basic_elt(env, 34); // listp
    v_200 = (*qfn1(fn))(fn, v_200);
    env = stack[-1];
    if (v_200 == nil) goto v_162;
    v_200 = qvalue(basic_elt(env, 12)); // !*web
    if (v_200 == nil) goto v_167;
    else goto v_168;
v_167:
    v_200 = basic_elt(env, 28); // " type=""list"">"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_166;
v_168:
    v_200 = basic_elt(env, 29); // " type=&quot;list&quot;>"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_166;
v_166:
    goto v_160;
v_162:
    v_200 = stack[0];
    v_200 = Lsimple_vectorp(nil, v_200);
    env = stack[-1];
    if (v_200 == nil) goto v_177;
    v_200 = qvalue(basic_elt(env, 12)); // !*web
    if (v_200 == nil) goto v_182;
    else goto v_183;
v_182:
    v_200 = basic_elt(env, 30); // " type=""vector"">"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_181;
v_183:
    v_200 = basic_elt(env, 31); // " type=&quot;vector&quot;>"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_181;
v_181:
    goto v_160;
v_177:
    v_200 = basic_elt(env, 26); // ">"
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    goto v_160;
v_160:
    v_200 = stack[0];
    v_200 = Lprinc(nil, v_200);
    env = stack[-1];
    v_200 = basic_elt(env, 32); // "</ci>"
    v_200 = Lprinc(nil, v_200);
    goto v_153;
v_155:
v_153:
    goto v_83;
v_83:
    goto v_60;
v_60:
    goto v_7;
v_7:
    v_200 = nil;
    return onevalue(v_200);
}



// Code for dip2a

static LispObject CC_dip2a(LispObject env,
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
    v_16 = v_2;
// end of prologue
    v_15 = v_16;
    if (v_15 == nil) goto v_6;
    else goto v_7;
v_6:
    v_15 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5;
v_7:
    v_15 = v_16;
    fn = basic_elt(env, 1); // dip2a1
    v_15 = (*qfn1(fn))(fn, v_15);
    env = stack[0];
    {
        fn = basic_elt(env, 2); // dipreplus
        return (*qfn1(fn))(fn, v_15);
    }
    v_15 = nil;
v_5:
    return onevalue(v_15);
}



// Code for mv!-compact2

static LispObject CC_mvKcompact2(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_34, v_35, v_36;
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
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_35 = stack[-1];
    v_34 = stack[0];
    fn = basic_elt(env, 1); // equiv!-coeffs
    v_34 = (*qfn2(fn))(fn, v_35, v_34);
    env = stack[-3];
    stack[-2] = v_34;
    v_34 = stack[0];
    fn = basic_elt(env, 2); // mv!-domainlist
    v_34 = (*qfn1(fn))(fn, v_34);
    env = stack[-3];
    v_35 = stack[-2];
    fn = basic_elt(env, 3); // reduce
    v_34 = (*qfn2(fn))(fn, v_35, v_34);
    env = stack[-3];
    v_36 = v_34;
    v_35 = v_36;
    v_34 = stack[-2];
    if (equal(v_35, v_34)) goto v_20;
    else goto v_21;
v_20:
    v_34 = nil;
    goto v_19;
v_21:
    v_35 = v_36;
    v_34 = stack[-2];
    fn = basic_elt(env, 4); // mv!-domainlist!-!-
    v_34 = (*qfn2(fn))(fn, v_35, v_34);
    env = stack[-3];
    fn = basic_elt(env, 5); // mv!-coeff!-replace
    v_35 = (*qfn2(fn))(fn, stack[0], v_34);
    env = stack[-3];
    v_34 = stack[-1];
    {
        fn = basic_elt(env, 6); // mv!-!+
        return (*qfn2(fn))(fn, v_35, v_34);
    }
    v_34 = nil;
v_19:
    return onevalue(v_34);
}



// Code for balance_mod

static LispObject CC_balance_mod(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_20, v_21;
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
    v_21 = stack[-1];
    v_20 = stack[-1];
    v_21 = plus2(v_21, v_20);
    env = stack[-2];
    v_20 = stack[0];
    v_20 = (LispObject)greaterp2(v_21, v_20);
    v_20 = v_20 ? lisp_true : nil;
    if (v_20 == nil) goto v_8;
    v_21 = stack[-1];
    v_20 = stack[0];
    return difference2(v_21, v_20);
v_8:
    v_20 = stack[-1];
    goto v_6;
    v_20 = nil;
v_6:
    return onevalue(v_20);
}



// Code for fctargs

static LispObject CC_fctargs(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_13, v_14;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13 = v_2;
// end of prologue
    v_14 = qvalue(basic_elt(env, 1)); // depl!*
    v_14 = Lassoc(nil, v_13, v_14);
    v_13 = v_14;
    if (v_14 == nil) goto v_7;
    if (!car_legal(v_13)) v_13 = cdrerror(v_13); else
    v_13 = qcdr(v_13);
    goto v_5;
v_7:
    v_13 = nil;
v_5:
    return onevalue(v_13);
}



// Code for simp0

static LispObject CC_simp0(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_88, v_89;
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
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_2;
// end of prologue
// Binding !*factor
// FLUIDBIND: reloadenv=6 litvec-offset=1 saveloc=5
{   bind_fluid_stack bind_fluid_var(-6, 1, -5);
    qvalue(basic_elt(env, 1)) = nil; // !*factor
    v_89 = stack[-4];
    v_88 = basic_elt(env, 2); // !*sq
    if (!consp(v_89)) goto v_14;
    v_89 = qcar(v_89);
    if (v_89 == v_88) goto v_13;
    else goto v_14;
v_13:
    v_88 = stack[-4];
    if (!car_legal(v_88)) v_88 = cdrerror(v_88); else
    v_88 = qcdr(v_88);
    if (!car_legal(v_88)) v_88 = carerror(v_88); else
    v_88 = qcar(v_88);
    fn = basic_elt(env, 7); // prepsq!*
    v_88 = (*qfn1(fn))(fn, v_88);
    env = stack[-6];
    v_88 = CC_simp0(basic_elt(env, 0), v_88);
    goto v_10;
v_14:
    v_89 = stack[-4];
    v_88 = nil;
    fn = basic_elt(env, 8); // frvarsof
    v_88 = (*qfn2(fn))(fn, v_89, v_88);
    env = stack[-6];
    fn = basic_elt(env, 9); // setkorder
    v_88 = (*qfn1(fn))(fn, v_88);
    env = stack[-6];
    stack[-2] = v_88;
    v_89 = qvalue(basic_elt(env, 3)); // subfg!*
    v_88 = qvalue(basic_elt(env, 4)); // !*sub2
    v_88 = cons(v_89, v_88);
    env = stack[-6];
    stack[-3] = v_88;
    v_88 = nil;
    v_88 = ncons(v_88);
    env = stack[-6];
    qvalue(basic_elt(env, 5)) = v_88; // alglist!*
    v_88 = nil;
    qvalue(basic_elt(env, 3)) = v_88; // subfg!*
    v_88 = stack[-4];
    if (!consp(v_88)) goto v_39;
    else goto v_40;
v_39:
    v_88 = lisp_true;
    goto v_38;
v_40:
    v_88 = stack[-4];
    if (!car_legal(v_88)) v_88 = carerror(v_88); else
    v_88 = qcar(v_88);
    if (symbolp(v_88)) goto v_48;
    v_88 = nil;
    goto v_46;
v_48:
    v_88 = stack[-4];
    if (!car_legal(v_88)) v_89 = carerror(v_88); else
    v_89 = qcar(v_88);
    v_88 = basic_elt(env, 6); // simp0fn
    v_88 = Lflagp(nil, v_89, v_88);
    env = stack[-6];
    if (v_88 == nil) goto v_57;
    v_88 = lisp_true;
    goto v_55;
v_57:
    v_88 = stack[-4];
    if (!car_legal(v_88)) v_88 = carerror(v_88); else
    v_88 = qcar(v_88);
    if (!symbolp(v_88)) v_88 = nil;
    else { v_88 = qfastgets(v_88);
           if (v_88 != nil) { v_88 = elt(v_88, 2); // rtype
#ifdef RECORD_GET
             if (v_88 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_88 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_88 == SPID_NOPROP) v_88 = nil; }}
#endif
    goto v_55;
    v_88 = nil;
v_55:
    goto v_46;
    v_88 = nil;
v_46:
    goto v_38;
    v_88 = nil;
v_38:
    if (v_88 == nil) goto v_36;
    v_88 = stack[-4];
    fn = basic_elt(env, 10); // simp
    v_88 = (*qfn1(fn))(fn, v_88);
    env = stack[-6];
    stack[-1] = v_88;
    goto v_34;
v_36:
    v_88 = stack[-4];
    fn = basic_elt(env, 11); // simpiden
    v_88 = (*qfn1(fn))(fn, v_88);
    env = stack[-6];
    stack[-1] = v_88;
    goto v_34;
v_34:
    stack[0] = qvalue(basic_elt(env, 5)); // alglist!*
    v_89 = stack[-4];
    v_88 = qvalue(basic_elt(env, 5)); // alglist!*
    if (!car_legal(v_88)) v_88 = carerror(v_88); else
    v_88 = qcar(v_88);
    fn = basic_elt(env, 12); // delete_from_alglist
    v_88 = (*qfn2(fn))(fn, v_89, v_88);
    env = stack[-6];
    if (!car_legal(stack[0])) rplaca_fails(stack[0]);
    qcar(stack[0]) = v_88;
    v_88 = stack[-3];
    if (!car_legal(v_88)) v_88 = carerror(v_88); else
    v_88 = qcar(v_88);
    qvalue(basic_elt(env, 3)) = v_88; // subfg!*
    v_88 = stack[-3];
    if (!car_legal(v_88)) v_88 = cdrerror(v_88); else
    v_88 = qcdr(v_88);
    qvalue(basic_elt(env, 4)) = v_88; // !*sub2
    v_88 = stack[-2];
    fn = basic_elt(env, 9); // setkorder
    v_88 = (*qfn1(fn))(fn, v_88);
    v_88 = stack[-1];
v_10:
    ;}  // end of a binding scope
    return onevalue(v_88);
}



// Code for expf

static LispObject CC_expf(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_127, v_128, v_129;
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
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_127 = stack[-1];
    if (v_127 == nil) goto v_7;
    else goto v_8;
v_7:
    v_127 = nil;
    goto v_6;
v_8:
    v_128 = stack[-1];
    v_127 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_128 == v_127) goto v_11;
    else goto v_12;
v_11:
    v_127 = stack[-1];
    goto v_6;
v_12:
    v_127 = stack[-1];
    if (!consp(v_127)) goto v_16;
    else goto v_17;
v_16:
    stack[-2] = (LispObject)16+TAG_FIXNUM; // 1
    v_127 = stack[0];
    v_127 = negate(v_127);
    env = stack[-3];
    v_127 = Lexpt(nil, stack[-1], v_127);
    env = stack[-3];
    {
        LispObject v_133 = stack[-2];
        fn = basic_elt(env, 3); // mkrn
        return (*qfn2(fn))(fn, v_133, v_127);
    }
v_17:
    v_127 = stack[-1];
    if (!consp(v_127)) goto v_29;
    else goto v_30;
v_29:
    v_127 = lisp_true;
    goto v_28;
v_30:
    v_127 = stack[-1];
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    v_127 = (consp(v_127) ? nil : lisp_true);
    goto v_28;
    v_127 = nil;
v_28:
    if (v_127 == nil) goto v_26;
    v_128 = stack[-1];
    v_127 = stack[0];
    {
        fn = basic_elt(env, 4); // !:expt
        return (*qfn2(fn))(fn, v_128, v_127);
    }
v_26:
    v_127 = stack[-1];
    if (!car_legal(v_127)) v_127 = cdrerror(v_127); else
    v_127 = qcdr(v_127);
    if (v_127 == nil) goto v_42;
    v_128 = stack[-1];
    v_127 = stack[0];
    {
        fn = basic_elt(env, 5); // mksp!*
        return (*qfn2(fn))(fn, v_128, v_127);
    }
v_42:
    v_127 = stack[-1];
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    if (!car_legal(v_127)) v_128 = cdrerror(v_127); else
    v_128 = qcdr(v_127);
    v_127 = qvalue(basic_elt(env, 1)); // frlis!*
    v_127 = Lmemq(nil, v_128, v_127);
    if (v_127 == nil) goto v_49;
    v_129 = basic_elt(env, 2); // expt
    v_127 = stack[-1];
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    if (!car_legal(v_127)) v_128 = carerror(v_127); else
    v_128 = qcar(v_127);
    v_127 = stack[-1];
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    if (!car_legal(v_127)) v_127 = cdrerror(v_127); else
    v_127 = qcdr(v_127);
    v_127 = list3(v_129, v_128, v_127);
    env = stack[-3];
    fn = basic_elt(env, 6); // fkern
    v_127 = (*qfn1(fn))(fn, v_127);
    env = stack[-3];
    if (!car_legal(v_127)) v_128 = carerror(v_127); else
    v_128 = qcar(v_127);
    v_127 = stack[0];
    fn = basic_elt(env, 7); // to
    stack[-2] = (*qfn2(fn))(fn, v_128, v_127);
    env = stack[-3];
    v_127 = stack[-1];
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    if (!car_legal(v_127)) v_128 = cdrerror(v_127); else
    v_128 = qcdr(v_127);
    v_127 = stack[0];
    v_127 = CC_expf(basic_elt(env, 0), v_128, v_127);
    env = stack[-3];
    v_127 = cons(stack[-2], v_127);
    return ncons(v_127);
v_49:
    v_127 = stack[-1];
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    if (!car_legal(v_127)) v_128 = cdrerror(v_127); else
    v_128 = qcdr(v_127);
    v_127 = stack[0];
    v_127 = times2(v_128, v_127);
    env = stack[-3];
    stack[-2] = v_127;
    v_128 = stack[-2];
    v_127 = (LispObject)0+TAG_FIXNUM; // 0
    v_127 = (LispObject)greaterp2(v_128, v_127);
    v_127 = v_127 ? lisp_true : nil;
    env = stack[-3];
    if (v_127 == nil) goto v_89;
    v_127 = stack[-1];
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    fn = basic_elt(env, 8); // sfp
    v_127 = (*qfn1(fn))(fn, v_127);
    env = stack[-3];
    if (v_127 == nil) goto v_89;
    v_127 = stack[-1];
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    if (!car_legal(v_127)) v_128 = carerror(v_127); else
    v_128 = qcar(v_127);
    v_127 = stack[-2];
    fn = basic_elt(env, 9); // exptf
    stack[-2] = (*qfn2(fn))(fn, v_128, v_127);
    env = stack[-3];
    v_127 = stack[-1];
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    if (!car_legal(v_127)) v_128 = cdrerror(v_127); else
    v_128 = qcdr(v_127);
    v_127 = stack[0];
    v_127 = CC_expf(basic_elt(env, 0), v_128, v_127);
    env = stack[-3];
    {
        LispObject v_134 = stack[-2];
        fn = basic_elt(env, 10); // multf
        return (*qfn2(fn))(fn, v_134, v_127);
    }
v_89:
    v_127 = stack[-1];
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    if (!car_legal(v_127)) v_128 = carerror(v_127); else
    v_128 = qcar(v_127);
    v_127 = stack[-2];
    fn = basic_elt(env, 7); // to
    stack[-2] = (*qfn2(fn))(fn, v_128, v_127);
    env = stack[-3];
    v_127 = stack[-1];
    if (!car_legal(v_127)) v_127 = carerror(v_127); else
    v_127 = qcar(v_127);
    if (!car_legal(v_127)) v_128 = cdrerror(v_127); else
    v_128 = qcdr(v_127);
    v_127 = stack[0];
    v_127 = CC_expf(basic_elt(env, 0), v_128, v_127);
    env = stack[-3];
    v_127 = cons(stack[-2], v_127);
    return ncons(v_127);
    v_127 = nil;
    goto v_6;
    v_127 = nil;
v_6:
    return onevalue(v_127);
}



// Code for change!+int!+to!+sq

static LispObject CC_changeLintLtoLsq(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_9, v_10;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9 = v_2;
// end of prologue
    v_10 = v_9;
    v_9 = (LispObject)16+TAG_FIXNUM; // 1
    return cons(v_10, v_9);
    return onevalue(v_9);
}



// Code for freeof!-dfl

static LispObject CC_freeofKdfl(LispObject env,
                         LispObject v_2, LispObject v_3)
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
    v_28 = stack[-1];
    if (!consp(v_28)) goto v_7;
    else goto v_8;
v_7:
    v_28 = lisp_true;
    goto v_6;
v_8:
    v_28 = stack[-1];
    if (!car_legal(v_28)) v_29 = carerror(v_28); else
    v_29 = qcar(v_28);
    v_28 = stack[0];
    fn = basic_elt(env, 1); // freeof!-df
    v_28 = (*qfn2(fn))(fn, v_29, v_28);
    env = stack[-2];
    if (v_28 == nil) goto v_15;
    else goto v_16;
v_15:
    v_28 = nil;
    goto v_14;
v_16:
    v_28 = stack[-1];
    if (!car_legal(v_28)) v_29 = cdrerror(v_28); else
    v_29 = qcdr(v_28);
    v_28 = stack[0];
    stack[-1] = v_29;
    stack[0] = v_28;
    goto v_1;
    v_28 = nil;
v_14:
    goto v_6;
    v_28 = nil;
v_6:
    return onevalue(v_28);
}



// Code for rl_sacatlp

static LispObject CC_rl_sacatlp(LispObject env,
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
    stack[0] = qvalue(basic_elt(env, 1)); // rl_sacatlp!*
    v_10 = list2(v_11, v_10);
    env = stack[-1];
    {
        LispObject v_13 = stack[0];
        fn = basic_elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_13, v_10);
    }
}



// Code for lto_sgnchg1

static LispObject CC_lto_sgnchg1(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_40;
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
v_6:
    v_40 = stack[0];
    if (v_40 == nil) goto v_13;
    else goto v_14;
v_13:
    v_40 = lisp_true;
    goto v_12;
v_14:
    v_40 = stack[0];
    if (!car_legal(v_40)) v_40 = cdrerror(v_40); else
    v_40 = qcdr(v_40);
    v_40 = (v_40 == nil ? lisp_true : nil);
    goto v_12;
    v_40 = nil;
v_12:
    if (v_40 == nil) goto v_10;
    v_40 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5;
v_10:
    v_40 = stack[0];
    if (!car_legal(v_40)) v_40 = carerror(v_40); else
    v_40 = qcar(v_40);
    fn = basic_elt(env, 1); // sgn
    stack[-1] = (*qfn1(fn))(fn, v_40);
    env = stack[-2];
    v_40 = stack[0];
    if (!car_legal(v_40)) v_40 = cdrerror(v_40); else
    v_40 = qcdr(v_40);
    if (!car_legal(v_40)) v_40 = carerror(v_40); else
    v_40 = qcar(v_40);
    fn = basic_elt(env, 1); // sgn
    v_40 = (*qfn1(fn))(fn, v_40);
    env = stack[-2];
    if (stack[-1] == v_40) goto v_23;
    else goto v_24;
v_23:
    v_40 = stack[0];
    if (!car_legal(v_40)) v_40 = cdrerror(v_40); else
    v_40 = qcdr(v_40);
    stack[0] = v_40;
    goto v_6;
v_24:
    v_40 = stack[0];
    if (!car_legal(v_40)) v_40 = cdrerror(v_40); else
    v_40 = qcdr(v_40);
    v_40 = CC_lto_sgnchg1(basic_elt(env, 0), v_40);
    return add1(v_40);
    v_40 = nil;
v_5:
    return onevalue(v_40);
}



// Code for cgp_greenp

static LispObject CC_cgp_greenp(LispObject env,
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
    fn = basic_elt(env, 1); // cgp_rp
    v_7 = (*qfn1(fn))(fn, v_7);
    v_7 = (v_7 == nil ? lisp_true : nil);
    return onevalue(v_7);
}



// Code for integralir

static LispObject CC_integralir(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_53, v_54;
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
    v_54 = qvalue(basic_elt(env, 1)); // atts
    v_53 = basic_elt(env, 2); // name
    fn = basic_elt(env, 6); // find
    v_53 = (*qfn2(fn))(fn, v_54, v_53);
    env = stack[-3];
    v_53 = Lintern(nil, v_53);
    env = stack[-3];
    stack[-1] = v_53;
    v_53 = basic_elt(env, 3); // (bvar x 1)
    v_53 = ncons(v_53);
    env = stack[-3];
    stack[0] = v_53;
    v_54 = stack[-1];
    v_53 = basic_elt(env, 4); // defint
    if (v_54 == v_53) goto v_18;
    else goto v_19;
v_18:
    fn = basic_elt(env, 7); // lex
    v_53 = (*qfn0(fn))(fn);
    env = stack[-3];
    fn = basic_elt(env, 8); // omobj
    v_53 = (*qfn0(fn))(fn);
    env = stack[-3];
    goto v_17;
v_19:
v_17:
    fn = basic_elt(env, 7); // lex
    v_53 = (*qfn0(fn))(fn);
    env = stack[-3];
    fn = basic_elt(env, 8); // omobj
    v_53 = (*qfn0(fn))(fn);
    env = stack[-3];
    stack[-2] = v_53;
    v_53 = stack[-2];
    v_53 = Lconsp(nil, v_53);
    env = stack[-3];
    if (v_53 == nil) goto v_30;
    v_53 = stack[-2];
    if (!car_legal(v_53)) v_54 = carerror(v_53); else
    v_54 = qcar(v_53);
    v_53 = basic_elt(env, 5); // lambda
    if (v_54 == v_53) goto v_35;
    else goto v_36;
v_35:
    v_53 = stack[-2];
    fn = basic_elt(env, 9); // lambdavar
    v_53 = (*qfn1(fn))(fn, v_53);
    env = stack[-3];
    stack[0] = v_53;
    v_53 = stack[-2];
    fn = basic_elt(env, 10); // lambdafun
    v_53 = (*qfn1(fn))(fn, v_53);
    env = stack[-3];
    stack[-2] = v_53;
    goto v_34;
v_36:
v_34:
    goto v_28;
v_30:
v_28:
    v_54 = stack[-1];
    v_53 = nil;
    stack[-1] = list2(v_54, v_53);
    env = stack[-3];
    v_53 = stack[-2];
    v_53 = ncons(v_53);
    env = stack[-3];
    v_53 = Lappend_2(nil, stack[0], v_53);
    {
        LispObject v_58 = stack[-1];
        return Lappend_2(nil, v_58, v_53);
    }
    return onevalue(v_53);
}



// Code for simpsqrtsq

static LispObject CC_simpsqrtsq(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_11;
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
    v_11 = stack[0];
    if (!car_legal(v_11)) v_11 = carerror(v_11); else
    v_11 = qcar(v_11);
    fn = basic_elt(env, 1); // simpsqrt2
    stack[-1] = (*qfn1(fn))(fn, v_11);
    env = stack[-2];
    v_11 = stack[0];
    if (!car_legal(v_11)) v_11 = cdrerror(v_11); else
    v_11 = qcdr(v_11);
    fn = basic_elt(env, 1); // simpsqrt2
    v_11 = (*qfn1(fn))(fn, v_11);
    {
        LispObject v_14 = stack[-1];
        return cons(v_14, v_11);
    }
}



// Code for mkexpt

static LispObject CC_mkexpt(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_18, v_19, v_20, v_21;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20 = v_3;
    v_21 = v_2;
// end of prologue
    v_19 = v_20;
    v_18 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_19 == v_18) goto v_7;
    else goto v_8;
v_7:
    v_18 = v_21;
    goto v_6;
v_8:
    v_18 = basic_elt(env, 1); // expt
    v_19 = v_21;
    return list3(v_18, v_19, v_20);
    v_18 = nil;
v_6:
    return onevalue(v_18);
}



// Code for rnfix!*

static LispObject CC_rnfixH(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_11, v_12;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11 = v_2;
// end of prologue
    v_12 = v_11;
    if (!car_legal(v_12)) v_12 = cdrerror(v_12); else
    v_12 = qcdr(v_12);
    if (!car_legal(v_12)) v_12 = carerror(v_12); else
    v_12 = qcar(v_12);
    if (!car_legal(v_11)) v_11 = cdrerror(v_11); else
    v_11 = qcdr(v_11);
    if (!car_legal(v_11)) v_11 = cdrerror(v_11); else
    v_11 = qcdr(v_11);
    return quot2(v_12, v_11);
}



// Code for simpu

static LispObject CC_simpu(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_19, v_20;
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
    v_20 = v_2;
// end of prologue
    stack[-1] = basic_elt(env, 1); // u
    v_19 = v_20;
    if (!car_legal(v_19)) stack[0] = carerror(v_19); else
    stack[0] = qcar(v_19);
    v_19 = v_20;
    if (!car_legal(v_19)) v_19 = cdrerror(v_19); else
    v_19 = qcdr(v_19);
    fn = basic_elt(env, 2); // ordn
    v_19 = (*qfn1(fn))(fn, v_19);
    env = stack[-2];
    v_19 = Lreverse(nil, v_19);
    env = stack[-2];
    v_20 = list2star(stack[-1], stack[0], v_19);
    env = stack[-2];
    v_19 = (LispObject)16+TAG_FIXNUM; // 1
    fn = basic_elt(env, 3); // mksp
    v_20 = (*qfn2(fn))(fn, v_20, v_19);
    env = stack[-2];
    v_19 = (LispObject)16+TAG_FIXNUM; // 1
    v_19 = cons(v_20, v_19);
    env = stack[-2];
    v_20 = ncons(v_19);
    v_19 = (LispObject)16+TAG_FIXNUM; // 1
    return cons(v_20, v_19);
}



// Code for specrd!:times

static LispObject CC_specrdTtimes(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_66, v_67;
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
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    stack[-2] = nil;
    v_66 = stack[-1];
    fn = basic_elt(env, 2); // add_minus
    v_66 = (*qfn1(fn))(fn, v_66);
    env = stack[-3];
    stack[-1] = v_66;
    v_66 = stack[0];
    fn = basic_elt(env, 2); // add_minus
    v_66 = (*qfn1(fn))(fn, v_66);
    env = stack[-3];
    stack[0] = v_66;
    v_67 = stack[-1];
    v_66 = basic_elt(env, 1); // minus
    if (!consp(v_67)) goto v_15;
    v_67 = qcar(v_67);
    if (v_67 == v_66) goto v_14;
    else goto v_15;
v_14:
    v_66 = stack[-1];
    if (!car_legal(v_66)) v_66 = cdrerror(v_66); else
    v_66 = qcdr(v_66);
    if (!car_legal(v_66)) v_66 = carerror(v_66); else
    v_66 = qcar(v_66);
    stack[-1] = v_66;
    v_66 = lisp_true;
    stack[-2] = v_66;
    goto v_13;
v_15:
v_13:
    v_67 = stack[0];
    v_66 = basic_elt(env, 1); // minus
    if (!consp(v_67)) goto v_26;
    v_67 = qcar(v_67);
    if (v_67 == v_66) goto v_25;
    else goto v_26;
v_25:
    v_66 = stack[0];
    if (!car_legal(v_66)) v_66 = cdrerror(v_66); else
    v_66 = qcdr(v_66);
    if (!car_legal(v_66)) v_66 = carerror(v_66); else
    v_66 = qcar(v_66);
    stack[0] = v_66;
    v_66 = stack[-2];
    v_66 = (v_66 == nil ? lisp_true : nil);
    stack[-2] = v_66;
    goto v_24;
v_26:
v_24:
    v_66 = stack[-1];
    if (!consp(v_66)) goto v_37;
    else goto v_38;
v_37:
    v_66 = stack[-1];
    v_66 = Lfloat(nil, v_66);
    env = stack[-3];
    fn = basic_elt(env, 3); // mkround
    v_66 = (*qfn1(fn))(fn, v_66);
    env = stack[-3];
    stack[-1] = v_66;
    goto v_36;
v_38:
v_36:
    v_66 = stack[0];
    if (!consp(v_66)) goto v_45;
    else goto v_46;
v_45:
    v_66 = stack[0];
    v_66 = Lfloat(nil, v_66);
    env = stack[-3];
    fn = basic_elt(env, 3); // mkround
    v_66 = (*qfn1(fn))(fn, v_66);
    env = stack[-3];
    stack[0] = v_66;
    goto v_44;
v_46:
v_44:
    v_66 = stack[-2];
    if (v_66 == nil) goto v_54;
    stack[-2] = basic_elt(env, 1); // minus
    v_67 = stack[-1];
    v_66 = stack[0];
    fn = basic_elt(env, 4); // rd!:times
    v_66 = (*qfn2(fn))(fn, v_67, v_66);
    {
        LispObject v_71 = stack[-2];
        return list2(v_71, v_66);
    }
v_54:
    v_67 = stack[-1];
    v_66 = stack[0];
    {
        fn = basic_elt(env, 4); // rd!:times
        return (*qfn2(fn))(fn, v_67, v_66);
    }
    v_66 = nil;
    return onevalue(v_66);
}



// Code for evalmember

static LispObject CC_evalmember(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_9, v_10;
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
    v_9 = v_3;
    v_10 = v_2;
// end of prologue
    stack[0] = v_10;
    fn = basic_elt(env, 1); // getrlist
    v_9 = (*qfn1(fn))(fn, v_9);
    v_9 = Lmember(nil, stack[0], v_9);
    return onevalue(v_9);
}



// Code for markedvarp

static LispObject CC_markedvarp(LispObject env,
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
    v_8 = basic_elt(env, 1); // !*marked!*
        return Lflagp(nil, v_7, v_8);
}



// Code for indexvp

static LispObject CC_indexvp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_15, v_16;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15 = v_2;
// end of prologue
    v_16 = v_15;
    if (!consp(v_16)) goto v_7;
    if (!car_legal(v_15)) v_15 = carerror(v_15); else
    v_15 = qcar(v_15);
    if (!symbolp(v_15)) v_15 = nil;
    else { v_15 = qfastgets(v_15);
           if (v_15 != nil) { v_15 = elt(v_15, 16); // indexvar
#ifdef RECORD_GET
             if (v_15 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v_15 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v_15 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v_15 == SPID_NOPROP) v_15 = nil; else v_15 = lisp_true; }}
#endif
    goto v_5;
v_7:
    v_15 = nil;
    goto v_5;
    v_15 = nil;
v_5:
    return onevalue(v_15);
}



// Code for mk_simpl_map_

static LispObject CC_mk_simpl_map_(LispObject env,
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
    v_7 = nil;
    {
        fn = basic_elt(env, 1); // mk_simpl_map_1
        return (*qfn2(fn))(fn, v_8, v_7);
    }
}



// Code for evalwhereexp

static LispObject CC_evalwhereexp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_19, v_20;
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
    v_20 = v_2;
// end of prologue
    v_19 = v_20;
    if (!car_legal(v_19)) v_19 = carerror(v_19); else
    v_19 = qcar(v_19);
    if (!car_legal(v_19)) stack[-2] = cdrerror(v_19); else
    stack[-2] = qcdr(v_19);
    stack[-1] = basic_elt(env, 1); // aeval
    stack[0] = basic_elt(env, 1); // aeval
    v_19 = v_20;
    if (!car_legal(v_19)) v_20 = cdrerror(v_19); else
    v_20 = qcdr(v_19);
    v_19 = basic_elt(env, 2); // where
    fn = basic_elt(env, 3); // carx
    v_19 = (*qfn2(fn))(fn, v_20, v_19);
    env = stack[-3];
    v_19 = list2(stack[0], v_19);
    env = stack[-3];
    v_19 = Lmkquote(nil, v_19);
    env = stack[-3];
    v_19 = list2(stack[-1], v_19);
    env = stack[-3];
    v_20 = list2(stack[-2], v_19);
    env = stack[-3];
    v_19 = nil;
    {
        fn = basic_elt(env, 4); // evalletsub
        return (*qfn2(fn))(fn, v_20, v_19);
    }
}



// Code for extract_vars

static LispObject CC_extract_vars(LispObject env,
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
    stack[-1] = nil;
v_7:
    v_32 = stack[0];
    if (v_32 == nil) goto v_10;
    else goto v_11;
v_10:
    v_32 = stack[-1];
    {
        fn = basic_elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_32);
    }
v_11:
    v_32 = stack[0];
    if (!car_legal(v_32)) v_32 = carerror(v_32); else
    v_32 = qcar(v_32);
    fn = basic_elt(env, 3); // raiseind!:
    v_33 = (*qfn1(fn))(fn, v_32);
    env = stack[-2];
    v_32 = basic_elt(env, 1); // variable
    v_32 = Lflagp(nil, v_33, v_32);
    env = stack[-2];
    if (v_32 == nil) goto v_16;
    v_32 = stack[0];
    if (!car_legal(v_32)) v_33 = carerror(v_32); else
    v_33 = qcar(v_32);
    v_32 = stack[-1];
    v_32 = cons(v_33, v_32);
    env = stack[-2];
    stack[-1] = v_32;
    v_32 = stack[0];
    if (!car_legal(v_32)) v_32 = cdrerror(v_32); else
    v_32 = qcdr(v_32);
    stack[0] = v_32;
    goto v_7;
v_16:
    v_32 = stack[0];
    if (!car_legal(v_32)) v_32 = cdrerror(v_32); else
    v_32 = qcdr(v_32);
    stack[0] = v_32;
    goto v_7;
    v_32 = nil;
    return onevalue(v_32);
}



// Code for enter!-sorted

static LispObject CC_enterKsorted(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_39, v_40;
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
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    stack[-2] = nil;
v_8:
    v_39 = stack[0];
    if (v_39 == nil) goto v_11;
    else goto v_12;
v_11:
    stack[0] = stack[-2];
    v_39 = stack[-1];
    v_39 = ncons(v_39);
    env = stack[-3];
    {
        LispObject v_44 = stack[0];
        fn = basic_elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_44, v_39);
    }
v_12:
    v_39 = stack[-1];
    if (!car_legal(v_39)) v_40 = carerror(v_39); else
    v_40 = qcar(v_39);
    v_39 = stack[0];
    if (!car_legal(v_39)) v_39 = carerror(v_39); else
    v_39 = qcar(v_39);
    if (!car_legal(v_39)) v_39 = carerror(v_39); else
    v_39 = qcar(v_39);
    fn = basic_elt(env, 2); // taydegree!<
    v_39 = (*qfn2(fn))(fn, v_40, v_39);
    env = stack[-3];
    if (v_39 == nil) goto v_19;
    v_40 = stack[-1];
    v_39 = stack[0];
    v_39 = cons(v_40, v_39);
    env = stack[-3];
    {
        LispObject v_45 = stack[-2];
        fn = basic_elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_45, v_39);
    }
v_19:
    v_39 = stack[0];
    if (!car_legal(v_39)) v_40 = carerror(v_39); else
    v_40 = qcar(v_39);
    v_39 = stack[-2];
    v_39 = cons(v_40, v_39);
    env = stack[-3];
    stack[-2] = v_39;
    v_39 = stack[0];
    if (!car_legal(v_39)) v_39 = cdrerror(v_39); else
    v_39 = qcdr(v_39);
    stack[0] = v_39;
    goto v_8;
    v_39 = nil;
    return onevalue(v_39);
}



// Code for pasf_coeflst

static LispObject CC_pasf_coeflst(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_66, v_67, v_68;
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
    stack[0] = nil;
    v_66 = stack[-1];
    v_66 = ncons(v_66);
    env = stack[-4];
    fn = basic_elt(env, 1); // setkorder
    v_66 = (*qfn1(fn))(fn, v_66);
    env = stack[-4];
    stack[-3] = v_66;
    v_66 = stack[-2];
    fn = basic_elt(env, 2); // reorder
    v_66 = (*qfn1(fn))(fn, v_66);
    env = stack[-4];
    stack[-2] = v_66;
v_17:
    v_66 = stack[-2];
    if (!consp(v_66)) goto v_28;
    else goto v_29;
v_28:
    v_66 = lisp_true;
    goto v_27;
v_29:
    v_66 = stack[-2];
    if (!car_legal(v_66)) v_66 = carerror(v_66); else
    v_66 = qcar(v_66);
    v_66 = (consp(v_66) ? nil : lisp_true);
    goto v_27;
    v_66 = nil;
v_27:
    if (v_66 == nil) goto v_24;
    else goto v_25;
v_24:
    v_66 = stack[-2];
    if (!car_legal(v_66)) v_66 = carerror(v_66); else
    v_66 = qcar(v_66);
    if (!car_legal(v_66)) v_66 = carerror(v_66); else
    v_66 = qcar(v_66);
    if (!car_legal(v_66)) v_67 = carerror(v_66); else
    v_67 = qcar(v_66);
    v_66 = stack[-1];
    v_66 = (v_67 == v_66 ? lisp_true : nil);
    goto v_23;
v_25:
    v_66 = nil;
    goto v_23;
    v_66 = nil;
v_23:
    if (v_66 == nil) goto v_20;
    else goto v_21;
v_20:
    goto v_16;
v_21:
    v_66 = stack[-2];
    if (!car_legal(v_66)) v_66 = carerror(v_66); else
    v_66 = qcar(v_66);
    if (!car_legal(v_66)) v_68 = cdrerror(v_66); else
    v_68 = qcdr(v_66);
    v_66 = stack[-2];
    if (!car_legal(v_66)) v_66 = carerror(v_66); else
    v_66 = qcar(v_66);
    if (!car_legal(v_66)) v_66 = carerror(v_66); else
    v_66 = qcar(v_66);
    if (!car_legal(v_66)) v_67 = cdrerror(v_66); else
    v_67 = qcdr(v_66);
    v_66 = stack[0];
    v_66 = acons(v_68, v_67, v_66);
    env = stack[-4];
    stack[0] = v_66;
    v_66 = stack[-2];
    if (!car_legal(v_66)) v_66 = cdrerror(v_66); else
    v_66 = qcdr(v_66);
    stack[-2] = v_66;
    goto v_17;
v_16:
    v_66 = stack[-3];
    fn = basic_elt(env, 1); // setkorder
    v_66 = (*qfn1(fn))(fn, v_66);
    env = stack[-4];
    v_66 = stack[-2];
    fn = basic_elt(env, 3); // negf
    v_68 = (*qfn1(fn))(fn, v_66);
    env = stack[-4];
    v_67 = (LispObject)0+TAG_FIXNUM; // 0
    v_66 = stack[0];
    v_66 = acons(v_68, v_67, v_66);
        return Lnreverse(nil, v_66);
    return onevalue(v_66);
}



// Code for vdp_mred

static LispObject CC_vdp_mred(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_27, v_28;
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
    v_27 = stack[-1];
    fn = basic_elt(env, 1); // vdp_poly
    v_27 = (*qfn1(fn))(fn, v_27);
    env = stack[-3];
    fn = basic_elt(env, 2); // dip_mred
    v_27 = (*qfn1(fn))(fn, v_27);
    env = stack[-3];
    stack[-2] = v_27;
    v_27 = stack[-2];
    if (v_27 == nil) goto v_12;
    else goto v_13;
v_12:
    {
        fn = basic_elt(env, 3); // vdp_zero
        return (*qfn0(fn))(fn);
    }
v_13:
    v_27 = stack[-2];
    fn = basic_elt(env, 4); // dip_lbc
    stack[0] = (*qfn1(fn))(fn, v_27);
    env = stack[-3];
    v_27 = stack[-2];
    fn = basic_elt(env, 5); // dip_evlmon
    v_28 = (*qfn1(fn))(fn, v_27);
    env = stack[-3];
    v_27 = stack[-2];
    fn = basic_elt(env, 6); // vdp_make
    v_27 = (*qfn3(fn))(fn, stack[0], v_28, v_27);
    env = stack[-3];
    stack[-2] = v_27;
    stack[0] = stack[-2];
    v_27 = stack[-1];
    fn = basic_elt(env, 7); // vdp_sugar
    v_27 = (*qfn1(fn))(fn, v_27);
    env = stack[-3];
    fn = basic_elt(env, 8); // vdp_setsugar
    v_27 = (*qfn2(fn))(fn, stack[0], v_27);
    v_27 = stack[-2];
    return onevalue(v_27);
}



setup_type const u36_setup[] =
{
    {"prepsq*0",                G0W2,     G1W2,     CC_prepsqH0,G3W2,   G4W2},
    {"gadd",                    G0W3,     G1W3,     G2W3,     CC_gadd,  G4W3},
    {"fctlength",               G0W1,     CC_fctlength,G2W1,  G3W1,     G4W1},
    {"talp_invtscsimpl",        G0W1,     CC_talp_invtscsimpl,G2W1,G3W1,G4W1},
    {"cl_sacatlp",              G0W2,     G1W2,     CC_cl_sacatlp,G3W2, G4W2},
    {"prsubsetrd",              CC_prsubsetrd,G1W0, G2W0,     G3W0,     G4W0},
    {"findoptrow",              G0W3,     G1W3,     G2W3,     CC_findoptrow,G4W3},
    {"evzero",                  CC_evzero,G1W0,     G2W0,     G3W0,     G4W0},
    {"listpri",                 G0W1,     CC_listpri,G2W1,    G3W1,     G4W1},
    {"gfdiffer",                G0W2,     G1W2,     CC_gfdiffer,G3W2,   G4W2},
    {"ev-edgeloop",             G0W2,     G1W2,     CC_evKedgeloop,G3W2,G4W2},
    {"primep27",                G0W1,     CC_primep27,G2W1,   G3W1,     G4W1},
    {"formbool",                G0W3,     G1W3,     G2W3,     CC_formbool,G4W3},
    {"revalpart",               G0W1,     CC_revalpart,G2W1,  G3W1,     G4W1},
    {"prepreform1",             G0W2,     G1W2,     CC_prepreform1,G3W2,G4W2},
    {"extadd",                  G0W2,     G1W2,     CC_extadd,G3W2,     G4W2},
    {"read-comment1",           G0W1,     CC_readKcomment1,G2W1,G3W1,   G4W1},
    {"subtractinds",            G0W3,     G1W3,     G2W3,     CC_subtractinds,G4W3},
    {"mk+equation",             G0W2,     G1W2,     CC_mkLequation,G3W2,G4W2},
    {"rl_identity1",            G0W1,     CC_rl_identity1,G2W1,G3W1,    G4W1},
    {"bc_sum",                  G0W2,     G1W2,     CC_bc_sum,G3W2,     G4W2},
    {"ofsf_anegrel",            G0W1,     CC_ofsf_anegrel,G2W1,G3W1,    G4W1},
    {"ciom",                    G0W1,     CC_ciom,  G2W1,     G3W1,     G4W1},
    {"letmtr",                  G0W3,     G1W3,     G2W3,     CC_letmtr,G4W3},
    {"a2vdp",                   G0W1,     CC_a2vdp, G2W1,     G3W1,     G4W1},
    {"remove_least_item",       G0W1,     CC_remove_least_item,G2W1,G3W1,G4W1},
    {"mkassign",                G0W2,     G1W2,     CC_mkassign,G3W2,   G4W2},
    {"strand-alg-top",          G0W3,     G1W3,     G2W3,     CC_strandKalgKtop,G4W3},
    {"mchsarg",                 G0W3,     G1W3,     G2W3,     CC_mchsarg,G4W3},
    {"appr",                    G0W2,     G1W2,     CC_appr,  G3W2,     G4W2},
    {"cl_subfof",               G0W2,     G1W2,     CC_cl_subfof,G3W2,  G4W2},
    {"conditionml",             G0W1,     CC_conditionml,G2W1,G3W1,     G4W1},
    {"f4",                      G0W1,     CC_f4,    G2W1,     G3W1,     G4W1},
    {"dip2a",                   G0W1,     CC_dip2a, G2W1,     G3W1,     G4W1},
    {"mv-compact2",             G0W2,     G1W2,     CC_mvKcompact2,G3W2,G4W2},
    {"balance_mod",             G0W2,     G1W2,     CC_balance_mod,G3W2,G4W2},
    {"fctargs",                 G0W1,     CC_fctargs,G2W1,    G3W1,     G4W1},
    {"simp0",                   G0W1,     CC_simp0, G2W1,     G3W1,     G4W1},
    {"expf",                    G0W2,     G1W2,     CC_expf,  G3W2,     G4W2},
    {"change+int+to+sq",        G0W1,     CC_changeLintLtoLsq,G2W1,G3W1,G4W1},
    {"freeof-dfl",              G0W2,     G1W2,     CC_freeofKdfl,G3W2, G4W2},
    {"rl_sacatlp",              G0W2,     G1W2,     CC_rl_sacatlp,G3W2, G4W2},
    {"lto_sgnchg1",             G0W1,     CC_lto_sgnchg1,G2W1,G3W1,     G4W1},
    {"cgp_greenp",              G0W1,     CC_cgp_greenp,G2W1, G3W1,     G4W1},
    {"integralir",              CC_integralir,G1W0, G2W0,     G3W0,     G4W0},
    {"simpsqrtsq",              G0W1,     CC_simpsqrtsq,G2W1, G3W1,     G4W1},
    {"mkexpt",                  G0W2,     G1W2,     CC_mkexpt,G3W2,     G4W2},
    {"rnfix*",                  G0W1,     CC_rnfixH,G2W1,     G3W1,     G4W1},
    {"simpu",                   G0W1,     CC_simpu, G2W1,     G3W1,     G4W1},
    {"specrd:times",            G0W2,     G1W2,     CC_specrdTtimes,G3W2,G4W2},
    {"evalmember",              G0W2,     G1W2,     CC_evalmember,G3W2, G4W2},
    {"markedvarp",              G0W1,     CC_markedvarp,G2W1, G3W1,     G4W1},
    {"indexvp",                 G0W1,     CC_indexvp,G2W1,    G3W1,     G4W1},
    {"mk_simpl_map_",           G0W1,     CC_mk_simpl_map_,G2W1,G3W1,   G4W1},
    {"evalwhereexp",            G0W1,     CC_evalwhereexp,G2W1,G3W1,    G4W1},
    {"extract_vars",            G0W1,     CC_extract_vars,G2W1,G3W1,    G4W1},
    {"enter-sorted",            G0W2,     G1W2,     CC_enterKsorted,G3W2,G4W2},
    {"pasf_coeflst",            G0W2,     G1W2,     CC_pasf_coeflst,G3W2,G4W2},
    {"vdp_mred",                G0W1,     CC_vdp_mred,G2W1,   G3W1,     G4W1},
    {NULL, (no_args *)"u36", (one_arg *)"155010 9386326 7401176",
        NULL, NULL, NULL}
};

// end of generated code
