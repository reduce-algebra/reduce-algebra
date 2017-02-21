
// $destdir/u40.c        Machine generated C code

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
#ifdef HAVE_STDINT_H
#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
#endif
#include <stdint.h>
#else 
#ifndef HAVE_UINT32_T
#ifdef HAVE_U_INT32_T
typedef u_int32_t uint32_t;
#define HAVE_UINT32_T 1
#endif
#endif
#ifndef HAVE_UINT64_T
#ifdef HAVE_U_INT64_T
typedef u_int64_t uint64_t;
#define HAVE_UINT64_T 1
#endif
#endif
#ifndef HAVE_UINTPTR_T
#ifdef HAVE_U_INTPTR_T
typedef u_intptr_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef unsigned int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef short int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef unsigned short int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef unsigned long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef long long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef unsigned long long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_INT32_T
typedef int32_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_INT64_T
typedef int64_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_UINT32_T
typedef uint32_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_UINT64_T
typedef uint64_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif 
#endif 
#ifndef header_tags_h
#define header_tags_h 1
#if !defined HAVE_STDINT_H || !defined HAVE_INT32_T
#error This system needs a 32-bit integer type.
#endif
#define SIXTY_FOUR_BIT (sizeof(intptr_t) == 8)
#define CSL_IGNORE(x) ((void)(x))
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
typedef intptr_t LispObject;
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
#define is_forward(p) ((((int)(p)) & TAG_BITS) == TAG_FORWARD)
#define is_number(p) ((((int)(p)) & TAG_BITS) >= TAG_NUMBERS)
#define is_float(p) (((0xc040 >> (((int)(p)) & XTAG_BITS)) & 1) != 0)
#define is_immed_or_cons(p) (((0x85 >> (((int)(p)) & TAG_BITS)) & 1) != 0)
#define is_immed_cons_sym(p) (((0x95 >> (((int)(p)) & TAG_BITS)) & 1) != 0)
#define need_more_than_eq(p) (((0x63 >> (((int)(p)) & TAG_BITS)) & 1) != 0)
#define fixnum_of_int(x) ((LispObject)((((uintptr_t)(x))<<4)+TAG_FIXNUM))
#define int_of_fixnum(x) (((intptr_t)(x) & ~(intptr_t)15)/16)
#define valid_as_fixnum(x) (int_of_fixnum(fixnum_of_int(x)) == (x))
#define MOST_POSITIVE_FIXVAL (((intptr_t)1 << (8*sizeof(LispObject)-5)) - 1)
#define MOST_NEGATIVE_FIXVAL (-((intptr_t)1 << (8*sizeof(LispObject)-5)))
#define MOST_POSITIVE_FIXNUM fixnum_of_int(MOST_POSITIVE_FIXVAL)
#define MOST_NEGATIVE_FIXNUM fixnum_of_int(MOST_NEGATIVE_FIXVAL)
#define is_cons(p) ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & XTAG_BITS) == TAG_FIXNUM)
#define is_odds(p) ((((int)(p)) & TAG_BITS) == TAG_HDR_IMMED) 
#define is_sfloat(p) ((((int)(p)) & XTAG_BITS) == XTAG_SFLOAT)
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)
#define consp(p) is_cons(p)
#define symbolp(p) is_symbol(p)
#define car_legal(p) is_cons(p)
typedef struct Cons_Cell
{ LispObject car;
 LispObject cdr;
} Cons_Cell;
#define qcar(p) (((Cons_Cell *) (p))->car)
#define qcdr(p) (((Cons_Cell *) (p))->cdr)
#define car32(p) (*(int32_t *)(p))
#define cdr32(p) (*(int32_t *)(p))[1])
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
#define type_of_header(h) (((unsigned int)(h)) & header_mask)
#define length_of_header(h) ((((size_t)(h)) >> (Tw+7)) << 2)
#define length_of_bitheader(h) ((((size_t)(h)) >> (Tw+2)) - 31)
#define length_of_byteheader(h) ((((size_t)(h)) >> (Tw+5)) - 3)
#define length_of_hwordheader(h) ((((size_t)(h)) >> (Tw+6)) - 1)
#define bitvechdr_(n) (TYPE_BITVEC_1 + ((((n)+31)&31)<<(Tw+2)))
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
#define is_symbol_header(h) (((int)h & (0xf<<Tw)) == TYPE_SYMBOL)
#define is_symbol_header_full_test(h) \
 (((int)h & ((0xf<<Tw) + TAG_BITS)) == (TYPE_SYMBOL + TAG_HDR_IMMED))
#define header_fastget(h) (((h) >> SYM_FASTGET_SHIFT) & 0x3f)
#define is_number_header_full_test(h) \
 (((int)h & ((0x1d<<Tw) + TAG_BITS)) == ((0x1d<<Tw) + TAG_HDR_IMMED))
#define is_vector_header_full_test(h) \
 (is_odds(h) && (((int)h & (0x3<<Tw)) != 0))
#define is_array_header(h) (type_of_header(h) == TYPE_ARRAY)
#define vector_i8(h) (((0x7f070707u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i16(h) (((0x00080008u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i32(h) (((0x00000090u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i64(h) (((0x00007820u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i128(h) (((0x00000040u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_f32(h) (((0x00108000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_f64(h) (((0x00a00000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_f128(h) (((0x80400000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define TYPE_BIGNUM ( 0x1f <<Tw)
#define TYPE_RATNUM ( 0x1d <<Tw)
#define TYPE_COMPLEX_NUM ( 0x3d <<Tw)
#define TYPE_SINGLE_FLOAT ( 0x3f <<Tw)
#define TYPE_DOUBLE_FLOAT ( 0x5f <<Tw)
#define TYPE_LONG_FLOAT ( 0x7f <<Tw)
#define numhdr(v) (*(Header *)((char *)(v) - TAG_NUMBERS))
#define flthdr(v) (*(Header *)((char *)(v) - TAG_BOXFLOAT))
#define is_ratio(n) \
 (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
 (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
#define is_string_header(h) ((type_of_header(h) & (0x1f<<Tw)) == TYPE_STRING_1)
#define is_string(n) is_string_header(vechdr(n))
#define is_vec8_header(h) ((type_of_header(h) & (0x1f<<Tw)) == TYPE_VEC8_1)
#define is_vec8(n) is_vec8_header(vechdr(n))
#define is_bps_header(h) ((type_of_header(h) & (0x1f<<Tw)) == TYPE_BPS_1)
#define is_bps(n) is_bps_header(vechdr(n))
#define is_vec16_header(h) ((type_of_header(h) & (0x3f<<Tw)) == TYPE_VEC16_1)
#define is_vec16(n) is_vec16_header(vechdr(n))
#define is_bitvec_header(h) ((type_of_header(h) & (0x03<<Tw)) == TYPE_BITVEC_1)
#define is_bitvec(n) is_bitvec_header(vechdr(n))
#define vechdr(v) (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n) (*(LispObject *)((char *)(v) + \
 (CELL-TAG_VECTOR) + \
 (((intptr_t)(n))*sizeof(LispObject))))
#define celt(v, n) (*((char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define ucelt(v, n) (*((unsigned char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define scelt(v, n) (*((signed char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define data_of_bps(v) ((unsigned char *)(v) + (CELL-TAG_VECTOR))
#define BPS_DATA_OFFSET (CELL-TAG_VECTOR)
#define vselt(v, n) (*(LispObject *)(((intptr_t)(v) & ~((intptr_t)TAG_BITS)) + \
 ((1 + (intptr_t)(n))*sizeof(LispObject))))
#define helt(v, n) (*(int16_t *)((char *)(v) + \
 (CELL-TAG_VECTOR) + ((intptr_t)(n))*sizeof(int16_t)))
#define sethelt(v, n, x) (*(int16_t *)((char *)(v) + \
 (CELL-TAG_VECTOR) + ((intptr_t)(n))*sizeof(int16_t)) = (x))
#define ielt(v, n) (*(intptr_t *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(intptr_t))))
#define ielt32(v, n) (*(int32_t *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(int32_t))))
#define felt(v, n) (*(float *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(float))))
#define delt(v, n) (*(double *)((char *)(v) + \
 (2*CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(double))))
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
#define TYPE_MAPLEREF ( 0x2f <<Tw) 
 
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
#define is_header(x) (((int)(x) & (0x3<<Tw)) != 0) 
#define is_char(x) (((int)(x) & HDR_IMMED_MASK) == TAG_CHAR)
#define is_spid(x) (((int)(x) & HDR_IMMED_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xfffff) == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#define font_of_char(n) (((int32_t)(n) >> (21+4+Tw)) & 0xf)
#define bits_of_char(n) (0)
#define code_of_char(n) (((int32_t)(n) >> (4+Tw)) & 0x001fffff)
#define pack_char(font, code) \
 ((LispObject)((((uint32_t)(font)) << (21+4+Tw)) | \
 (((uint32_t)(code)) << (4+Tw)) | TAG_CHAR))
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
#define qheader(p) (*(Header *)((char *)(p) + (0*CELL-TAG_SYMBOL)))
#define qvalue(p) (*(LispObject *)((char *)(p) + (1*CELL-TAG_SYMBOL)))
#define qenv(p) (*(LispObject *)((char *)(p) + (2*CELL-TAG_SYMBOL)))
#define qplist(p) (*(LispObject *)((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define qfastgets(p) (*(LispObject *)((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define qpackage(p) (*(LispObject *)((char *)(p) + (5*CELL-TAG_SYMBOL)))
#define qpname(p) (*(LispObject *)((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define ifn0(p) (*(intptr_t *)((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define ifn1(p) (*(intptr_t *)((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define ifn2(p) (*(intptr_t *)((char *)(p) + (9*CELL-TAG_SYMBOL)))
#define ifn3(p) (*(intptr_t *)((char *)(p) + (10*CELL-TAG_SYMBOL)))
#define ifnn(p) (*(intptr_t *)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define ifn4(p) (*(intptr_t *)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define qfn0(p) (*(no_args **)((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfn1(p) (*(one_args **)((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qfn2(p) (*(two_args **)((char *)(p) + (9*CELL-TAG_SYMBOL)))
#define qfn3(p) (*(three_args **)((char *)(p) + (10*CELL-TAG_SYMBOL)))
#define qfnn(p) (*(n_args **)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define qfn4(p) (*(four_args **)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define qcount(p) (*(uint64_t *)((char *)(p) + (12*CELL-TAG_SYMBOL)))
typedef union Float_union
{ float f;
 uint32_t i;
 float32_t f32;
} Float_union;
#define low32(a) ((LispObject)(uint32_t)(a))
typedef struct Big_Number
{
 Header h;
 uint32_t d[1]; 
} Big_Number;
#define bignum_length(b) length_of_header(numhdr(b))
#define bignum_digits(b) \
 ((uint32_t *)((char *)(b) + (CELL-TAG_NUMBERS)))
#define bignum_digits64(b, n) \
 ((int64_t)((int32_t *)((char *)(b)+(CELL-TAG_NUMBERS)))[n])
#define make_bighdr(n) (TAG_HDR_IMMED+TYPE_BIGNUM+(((intptr_t)(n))<<(Tw+7)))
#define pack_hdrlength(n) (((intptr_t)(n))<<(Tw+7))
#define make_padder(n) (pack_hdrlength((n)/4) + TYPE_VEC8_1 + TAG_HDR_IMMED)
typedef struct Rational_Number
{ Header header;
 LispObject num;
 LispObject den;
} Rational_Number;
#define numerator(r) (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->num)
#define denominator(r) (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->den)
typedef struct Complex_Number
{ Header header;
 LispObject real;
 LispObject imag;
} Complex_Number;
#define real_part(r) (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->real)
#define imag_part(r) (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->imag)
typedef struct Single_Float
{ Header header;
 union float_or_int
 { float f;
 float32_t f32;
 int32_t i;
 } f;
} Single_Float;
#define single_float_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#define float32_t_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f32)
#define intfloat32_t_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.i)
#define SIZEOF_DOUBLE_FLOAT 16
#define double_float_addr(v) ((double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define double_float_pad(v) (*(int32_t *)((char *)(v) + \
 (4-TAG_BOXFLOAT)))
#define double_float_val(v) (*(double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define float64_t_val(v) (*(float64_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define intfloat64_t_val(v) (*(int64_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define SIZEOF_LONG_FLOAT 24
#define long_float_addr(v) ((float128_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define long_float_pad(v) (*(int32_t *)((char *)(v) + \
 (4-TAG_BOXFLOAT)))
#define long_float_val(v) (*(float128_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define float128_t_val(v) (*(float128_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define intfloat128_t_val0(v) (*(int64_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define intfloat128_t_val1(v) (*(int64_t *)((char *)(v) + \
 (16-TAG_BOXFLOAT)))
#define word_align_up(n) ((LispObject)(((intptr_t)(n) + 3) & (-4)))
#define doubleword_align_up(n) ((uintptr_t)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((uintptr_t)((intptr_t)(n) & (-8)))
#define object_align_up(n) ((uintptr_t)(((intptr_t)(n) + \
 sizeof(LispObject) - 1) & (-sizeof(LispObject))))
#define quadword_align_up(n) ((uintptr_t)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((uintptr_t)((intptr_t)(n) & (-16)))
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
#define ASL128(a,n) ((int128_t)((uint128_t)(a)<<MAXSHIFT((n),uint128_t)))
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
#define push(a) { *++stack = (a); }
#define push2(a,b) { stack[1] = (a); stack[2] = (b); stack += 2; }
#define push3(a,b,c) { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack += 3; }
#define push4(a,b,c,d) { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack += 4; }
#define push5(a,b,c,d,e){ stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack[5] = (e); stack += 5; }
#define push6(a,b,c,d,e,f) { \
 stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack[5] = (e); stack[6] = (f); \
 stack += 6; }
#define pop(a) { (a) = *stack--; }
#define pop2(a,b) { stack -= 2; (a) = stack[2]; (b) = stack[1]; }
#define pop3(a,b,c) { stack -= 3; (a) = stack[3]; (b) = stack[2]; \
 (c) = stack[1]; }
#define pop4(a,b,c,d) { stack -= 4; (a) = stack[4]; (b) = stack[3]; \
 (c) = stack[2]; (d) = stack[1]; }
#define pop5(a,b,c,d,e) { stack -= 5; (a) = stack[5]; (b) = stack[4]; \
 (c) = stack[3]; (d) = stack[2]; (e) = stack[1]; }
#define pop6(a,b,c,d,e, f) { stack -= 6; \
 (a) = stack[6]; (b) = stack[5]; (c) = stack[4]; \
 (d) = stack[3]; (e) = stack[2]; (f) = stack[1]; }
#define popv(n) stack -= (n)
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK 2
#define GC_CONS 3
#define GC_VEC 4
#define GC_BPS 5
#define GC_PRESERVE 6
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
extern LispObject err_table, progn_symbol;
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
#define LOG2_VECTOR_CHUNK_WORDS 17
#define VECTOR_CHUNK_WORDS ((size_t)(1<<LOG2_VECTOR_CHUNK_WORDS)) 
extern LispObject free_vectors[LOG2_VECTOR_CHUNK_WORDS+1];
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
extern int gc_number;
extern int force_reclaim_method, reclaim_trap_count, reclaim_stack_limit;
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
extern int primep(int32_t);
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
extern LispObject getvector(int tag, int type, size_t length);
extern LispObject getvector_init(size_t n, LispObject v);
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
#define equal(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 need_more_than_eq(a) && \
 equal_fn(a, b)))
#define cl_equal(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 need_more_than_eq(a) && \
 cl_equal_fn(a, b)))
#define eql(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 need_more_than_eq(a) && \
 eql_fn(a, b)))
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
#if defined HAVE___INT128 && !defined __HAVE_INT128_T
typedef __int128 int128_t;
#define HAVE_INT128_T
#endif
#if defined HAVE_UNSIGNED___INT128 && !defined __HAVE_UINT128_T
typedef unsigned __int128 uint128_t;
#define HAVE_UINT128_T
#endif
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
#define floating_edge_case(r) (1.0/(r) == 0.0 || (r) != (r))
#define floating_clear_flags() ((void)0)
#define floating_edge_case128(r) \
 (f128M_infinite(r) || f128M_nan(r))
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
#define bignum_minusp(a) \
 ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
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
extern "C" bool lesspbd(LispObject a, double b);
extern "C" bool lessprd(LispObject a, double b);
extern "C" bool lesspdb(double a, LispObject b);
extern "C" bool lesspdr(double a, LispObject b);
extern LispObject validate_number(const char *s, LispObject a,
 LispObject b, LispObject c);
extern LispObject make_fake_bignum(intptr_t n);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_two_word_bignum(int32_t a, uint32_t b);
extern LispObject make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern LispObject make_four_word_bignum(int32_t a, uint32_t b,
 uint32_t c, uint32_t d);
extern LispObject make_n_word_bignum(int32_t a1, uint32_t a2,
 uint32_t a3, size_t n);
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
{ if (valid_as_fixnum(n)) return fixnum_of_int(n);
 else return make_lisp_integerptr_fn(n);
}
extern LispObject make_lisp_unsignedptr_fn(uintptr_t n);
static inline LispObject make_lisp_unsignedptr(uintptr_t n)
{ if (n < ((uintptr_t)1)<<(8*sizeof(intptr_t)-5))
 return fixnum_of_int((intptr_t)n);
 else return make_lisp_unsignedptr_fn(n);
}
#ifdef HAVE_INT128_T
extern LispObject make_lisp_integer128_fn(int128_t n);
static inline LispObject make_lisp_integer128(int128_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int((intptr_t)n);
 else return make_lisp_integer128_fn(n);
}
#endif
extern LispObject make_sfloat(double d);
extern double float_of_integer(LispObject a);
extern "C" LispObject add1(LispObject p);
extern "C" LispObject sub1(LispObject p);
extern "C" LispObject integerp(LispObject p);
extern double float_of_number(LispObject a);
extern float128_t float128_of_number(LispObject a);
extern LispObject make_boxfloat(double a, int32_t type);
extern LispObject make_boxfloat128(float128_t a);
extern LispObject make_complex(LispObject r, LispObject i);
extern LispObject make_ratio(LispObject p, LispObject q);
extern "C" LispObject ash(LispObject a, LispObject b);
extern "C" LispObject lognot(LispObject a);
extern LispObject logior2(LispObject a, LispObject b);
extern LispObject logxor2(LispObject a, LispObject b);
extern LispObject logand2(LispObject a, LispObject b);
extern LispObject logeqv2(LispObject a, LispObject b);
extern LispObject rationalf(double d);
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
#include <semaphore.h>
#ifdef WIN32
#include <windows.h>
extern HANDLE kara_thread1, kara_thread2;
#define KARARESULT DWORD
#define KARAARG LPVOID
extern KARARESULT WINAPI kara_worker1(KARAARG p);
extern KARARESULT WINAPI kara_worker2(KARAARG p);
#else
#include <pthread.h>
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
extern "C" int f128M_exponent(const float128_t *p);
extern "C" void f128M_set_exponent(float128_t *p, int n);
extern "C" void f128M_ldexp(float128_t *p, int n);
extern "C" bool f128M_infinite(const float128_t *p);
extern "C" bool f128M_nan(const float128_t *x);
extern "C" bool f128M_subnorm(const float128_t *x);
extern "C" bool f128M_negative(const float128_t *x);
extern "C" void f128M_negate(float128_t *x);
extern "C" void f128M_split(
 const float128_t *x, float128_t *yhi, float128_t *ylo);
extern "C" float128_t f128_0, f128_1, f128_10, f128_10_17,
 f128_10_18, f128_r10, f128_N1;
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
extern "C" void f256M_mul(
 const float256_t *x, const float256_t *y, float256_t *z);
extern "C" void f256M_add(
 const float256_t *x, const float256_t *y, float256_t *z);
extern "C" float256_t f256_1, f256_10, f256_r10, f256_5, f256_r5;
extern "C" int f128M_sprint_E(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_sprint_F(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_sprint_G(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_print_E(int width, int precision, float128_t *p);
extern "C" int f128M_print_F(int width, int precision, float128_t *p);
extern "C" int f128M_print_G(int width, int precision, float128_t *p);
extern "C" float128_t atof128(const char *s);
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



// Code for mk!+scal!+mult!+mat

static LispObject CC_mkLscalLmultLmat(LispObject env,
                         LispObject v_22651, LispObject v_22652)
{
    env = qenv(env);
    LispObject v_22835, v_22836;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22651,v_22652);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[0] = v_22652;
    stack[-8] = v_22651;
// end of prologue
    v_22835 = stack[0];
    fn = elt(env, 3); // matrix!+p
    v_22835 = (*qfn1(fn))(fn, v_22835);
    env = stack[-10];
    if (v_22835 == nil) goto v_22662;
    else goto v_22663;
v_22662:
    v_22835 = elt(env, 1); // "no matrix in add"
    fn = elt(env, 4); // rederr
    v_22835 = (*qfn1(fn))(fn, v_22835);
    env = stack[-10];
    goto v_22661;
v_22663:
v_22661:
    v_22835 = stack[0];
    stack[-9] = v_22835;
    v_22835 = stack[-9];
    if (v_22835 == nil) goto v_22677;
    else goto v_22678;
v_22677:
    v_22835 = nil;
    goto v_22672;
v_22678:
    v_22835 = stack[-9];
    v_22835 = qcar(v_22835);
    stack[-4] = v_22835;
    v_22835 = stack[-4];
    if (v_22835 == nil) goto v_22694;
    else goto v_22695;
v_22694:
    v_22835 = nil;
    goto v_22689;
v_22695:
    v_22835 = stack[-4];
    v_22835 = qcar(v_22835);
    goto v_22707;
v_22703:
    v_22836 = stack[-8];
    goto v_22704;
v_22705:
    goto v_22706;
v_22707:
    goto v_22703;
v_22704:
    goto v_22705;
v_22706:
    fn = elt(env, 5); // multsq
    v_22835 = (*qfn2(fn))(fn, v_22836, v_22835);
    env = stack[-10];
    v_22836 = v_22835;
    v_22835 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=10 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-10, 2, 0);
    qvalue(elt(env, 2)) = v_22835; // !*sub2
    v_22835 = v_22836;
    fn = elt(env, 6); // subs2
    v_22835 = (*qfn1(fn))(fn, v_22835);
    env = stack[-10];
    v_22836 = v_22835;
    ;}  // end of a binding scope
    v_22835 = v_22836;
    v_22835 = ncons(v_22835);
    env = stack[-10];
    stack[-2] = v_22835;
    stack[-3] = v_22835;
v_22690:
    v_22835 = stack[-4];
    v_22835 = qcdr(v_22835);
    stack[-4] = v_22835;
    v_22835 = stack[-4];
    if (v_22835 == nil) goto v_22719;
    else goto v_22720;
v_22719:
    v_22835 = stack[-3];
    goto v_22689;
v_22720:
    goto v_22728;
v_22724:
    stack[-1] = stack[-2];
    goto v_22725;
v_22726:
    v_22835 = stack[-4];
    v_22835 = qcar(v_22835);
    goto v_22739;
v_22735:
    v_22836 = stack[-8];
    goto v_22736;
v_22737:
    goto v_22738;
v_22739:
    goto v_22735;
v_22736:
    goto v_22737;
v_22738:
    fn = elt(env, 5); // multsq
    v_22835 = (*qfn2(fn))(fn, v_22836, v_22835);
    env = stack[-10];
    v_22836 = v_22835;
    v_22835 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=10 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-10, 2, 0);
    qvalue(elt(env, 2)) = v_22835; // !*sub2
    v_22835 = v_22836;
    fn = elt(env, 6); // subs2
    v_22835 = (*qfn1(fn))(fn, v_22835);
    env = stack[-10];
    v_22836 = v_22835;
    ;}  // end of a binding scope
    v_22835 = v_22836;
    v_22835 = ncons(v_22835);
    env = stack[-10];
    goto v_22727;
v_22728:
    goto v_22724;
v_22725:
    goto v_22726;
v_22727:
    v_22835 = Lrplacd(nil, stack[-1], v_22835);
    env = stack[-10];
    v_22835 = stack[-2];
    v_22835 = qcdr(v_22835);
    stack[-2] = v_22835;
    goto v_22690;
v_22689:
    v_22835 = ncons(v_22835);
    env = stack[-10];
    stack[-6] = v_22835;
    stack[-7] = v_22835;
v_22673:
    v_22835 = stack[-9];
    v_22835 = qcdr(v_22835);
    stack[-9] = v_22835;
    v_22835 = stack[-9];
    if (v_22835 == nil) goto v_22753;
    else goto v_22754;
v_22753:
    v_22835 = stack[-7];
    goto v_22672;
v_22754:
    goto v_22762;
v_22758:
    stack[-5] = stack[-6];
    goto v_22759;
v_22760:
    v_22835 = stack[-9];
    v_22835 = qcar(v_22835);
    stack[-4] = v_22835;
    v_22835 = stack[-4];
    if (v_22835 == nil) goto v_22777;
    else goto v_22778;
v_22777:
    v_22835 = nil;
    goto v_22772;
v_22778:
    v_22835 = stack[-4];
    v_22835 = qcar(v_22835);
    goto v_22790;
v_22786:
    v_22836 = stack[-8];
    goto v_22787;
v_22788:
    goto v_22789;
v_22790:
    goto v_22786;
v_22787:
    goto v_22788;
v_22789:
    fn = elt(env, 5); // multsq
    v_22835 = (*qfn2(fn))(fn, v_22836, v_22835);
    env = stack[-10];
    v_22836 = v_22835;
    v_22835 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=10 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-10, 2, 0);
    qvalue(elt(env, 2)) = v_22835; // !*sub2
    v_22835 = v_22836;
    fn = elt(env, 6); // subs2
    v_22835 = (*qfn1(fn))(fn, v_22835);
    env = stack[-10];
    v_22836 = v_22835;
    ;}  // end of a binding scope
    v_22835 = v_22836;
    v_22835 = ncons(v_22835);
    env = stack[-10];
    stack[-2] = v_22835;
    stack[-3] = v_22835;
v_22773:
    v_22835 = stack[-4];
    v_22835 = qcdr(v_22835);
    stack[-4] = v_22835;
    v_22835 = stack[-4];
    if (v_22835 == nil) goto v_22802;
    else goto v_22803;
v_22802:
    v_22835 = stack[-3];
    goto v_22772;
v_22803:
    goto v_22811;
v_22807:
    stack[-1] = stack[-2];
    goto v_22808;
v_22809:
    v_22835 = stack[-4];
    v_22835 = qcar(v_22835);
    goto v_22822;
v_22818:
    v_22836 = stack[-8];
    goto v_22819;
v_22820:
    goto v_22821;
v_22822:
    goto v_22818;
v_22819:
    goto v_22820;
v_22821:
    fn = elt(env, 5); // multsq
    v_22835 = (*qfn2(fn))(fn, v_22836, v_22835);
    env = stack[-10];
    v_22836 = v_22835;
    v_22835 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=10 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-10, 2, 0);
    qvalue(elt(env, 2)) = v_22835; // !*sub2
    v_22835 = v_22836;
    fn = elt(env, 6); // subs2
    v_22835 = (*qfn1(fn))(fn, v_22835);
    env = stack[-10];
    v_22836 = v_22835;
    ;}  // end of a binding scope
    v_22835 = v_22836;
    v_22835 = ncons(v_22835);
    env = stack[-10];
    goto v_22810;
v_22811:
    goto v_22807;
v_22808:
    goto v_22809;
v_22810:
    v_22835 = Lrplacd(nil, stack[-1], v_22835);
    env = stack[-10];
    v_22835 = stack[-2];
    v_22835 = qcdr(v_22835);
    stack[-2] = v_22835;
    goto v_22773;
v_22772:
    v_22835 = ncons(v_22835);
    env = stack[-10];
    goto v_22761;
v_22762:
    goto v_22758;
v_22759:
    goto v_22760;
v_22761:
    v_22835 = Lrplacd(nil, stack[-5], v_22835);
    env = stack[-10];
    v_22835 = stack[-6];
    v_22835 = qcdr(v_22835);
    stack[-6] = v_22835;
    goto v_22673;
v_22672:
    return onevalue(v_22835);
}



// Code for talp_nextt1

static LispObject CC_talp_nextt1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22945, v_22946, v_22947, v_22948, v_22949, v_22950, v_22951, v_22952;
    LispObject fn;
    LispObject v_22658, v_22657, v_22656, v_22655, v_22654, v_22653, v_22652, v_22651;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 8, "talp_nextt1");
    va_start(aa, nargs);
    v_22651 = va_arg(aa, LispObject);
    v_22652 = va_arg(aa, LispObject);
    v_22653 = va_arg(aa, LispObject);
    v_22654 = va_arg(aa, LispObject);
    v_22655 = va_arg(aa, LispObject);
    v_22656 = va_arg(aa, LispObject);
    v_22657 = va_arg(aa, LispObject);
    v_22658 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_22658,v_22657,v_22656,v_22655,v_22654,v_22653);
        push2(v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_22651,v_22652,v_22653,v_22654,v_22655,v_22656);
        pop2(v_22657,v_22658);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(13);
// copy arguments values to proper place
    stack[-3] = v_22658;
    stack[-4] = v_22657;
    stack[-5] = v_22656;
    stack[-6] = v_22655;
    stack[-7] = v_22654;
    stack[-8] = v_22653;
    stack[-9] = v_22652;
    stack[-10] = v_22651;
// end of prologue
    stack[-11] = nil;
    v_22945 = stack[-10];
    if (!consp(v_22945)) goto v_22667;
    else goto v_22668;
v_22667:
    goto v_22687;
v_22671:
    v_22952 = stack[-10];
    goto v_22672;
v_22673:
    v_22951 = stack[-9];
    goto v_22674;
v_22675:
    v_22950 = stack[-8];
    goto v_22676;
v_22677:
    v_22949 = stack[-7];
    goto v_22678;
v_22679:
    v_22948 = stack[-6];
    goto v_22680;
v_22681:
    v_22947 = stack[-5];
    goto v_22682;
v_22683:
    v_22946 = stack[-4];
    goto v_22684;
v_22685:
    v_22945 = stack[-3];
    goto v_22686;
v_22687:
    goto v_22671;
v_22672:
    goto v_22673;
v_22674:
    goto v_22675;
v_22676:
    goto v_22677;
v_22678:
    goto v_22679;
v_22680:
    goto v_22681;
v_22682:
    goto v_22683;
v_22684:
    goto v_22685;
v_22686:
    {
        fn = elt(env, 1); // talp_nextt!-atom
        return (*qfnn(fn))(fn, 8, v_22952, v_22951, v_22950, v_22949, v_22948, v_22947, v_22946, v_22945);
    }
v_22668:
    v_22945 = stack[-10];
    fn = elt(env, 2); // talp_invp
    v_22945 = (*qfn1(fn))(fn, v_22945);
    env = stack[-12];
    if (v_22945 == nil) goto v_22699;
    goto v_22719;
v_22703:
    v_22945 = stack[-10];
    fn = elt(env, 3); // talp_fargl
    v_22945 = (*qfn1(fn))(fn, v_22945);
    env = stack[-12];
    stack[0] = qcar(v_22945);
    goto v_22704;
v_22705:
    v_22945 = stack[-9];
    v_22951 = add1(v_22945);
    env = stack[-12];
    goto v_22706;
v_22707:
    v_22950 = stack[-8];
    goto v_22708;
v_22709:
    v_22949 = stack[-7];
    goto v_22710;
v_22711:
    v_22948 = stack[-6];
    goto v_22712;
v_22713:
    v_22947 = stack[-5];
    goto v_22714;
v_22715:
    v_22946 = stack[-4];
    goto v_22716;
v_22717:
    v_22945 = lisp_true;
    goto v_22718;
v_22719:
    goto v_22703;
v_22704:
    goto v_22705;
v_22706:
    goto v_22707;
v_22708:
    goto v_22709;
v_22710:
    goto v_22711;
v_22712:
    goto v_22713;
v_22714:
    goto v_22715;
v_22716:
    goto v_22717;
v_22718:
    v_22945 = CC_talp_nextt1(elt(env, 0), 8, stack[0], v_22951, v_22950, v_22949, v_22948, v_22947, v_22946, v_22945);
    env = stack[-12];
    v_22946 = v_22945;
    v_22945 = v_22946;
    v_22945 = qcar(v_22945);
    if (v_22945 == nil) goto v_22735;
    goto v_22743;
v_22739:
    stack[0] = stack[-10];
    goto v_22740;
v_22741:
    v_22945 = v_22946;
    v_22945 = qcdr(v_22945);
    v_22945 = ncons(v_22945);
    env = stack[-12];
    goto v_22742;
v_22743:
    goto v_22739;
v_22740:
    goto v_22741;
v_22742:
    fn = elt(env, 4); // setcdr
    v_22945 = (*qfn2(fn))(fn, stack[0], v_22945);
    goto v_22753;
v_22749:
    v_22946 = lisp_true;
    goto v_22750;
v_22751:
    v_22945 = stack[-10];
    goto v_22752;
v_22753:
    goto v_22749;
v_22750:
    goto v_22751;
v_22752:
    return cons(v_22946, v_22945);
v_22735:
    goto v_22697;
v_22699:
    v_22945 = stack[-10];
    fn = elt(env, 3); // talp_fargl
    v_22945 = (*qfn1(fn))(fn, v_22945);
    env = stack[-12];
    stack[-1] = v_22945;
    goto v_22764;
v_22760:
    v_22946 = stack[-7];
    goto v_22761;
v_22762:
    v_22945 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22763;
v_22764:
    goto v_22760;
v_22761:
    goto v_22762;
v_22763:
    v_22945 = *(LispObject *)((char *)v_22946 + (CELL-TAG_VECTOR) + (((intptr_t)v_22945-TAG_FIXNUM)/(16/CELL)));
    stack[-2] = v_22945;
v_22770:
    v_22945 = stack[-1];
    if (v_22945 == nil) goto v_22773;
    v_22945 = stack[-11];
    if (v_22945 == nil) goto v_22777;
    else goto v_22773;
v_22777:
    goto v_22774;
v_22773:
    goto v_22769;
v_22774:
    goto v_22797;
v_22781:
    v_22945 = stack[-1];
    stack[0] = qcar(v_22945);
    goto v_22782;
v_22783:
    v_22945 = stack[-9];
    v_22951 = add1(v_22945);
    env = stack[-12];
    goto v_22784;
v_22785:
    v_22950 = stack[-8];
    goto v_22786;
v_22787:
    v_22949 = stack[-7];
    goto v_22788;
v_22789:
    v_22948 = stack[-6];
    goto v_22790;
v_22791:
    v_22947 = stack[-5];
    goto v_22792;
v_22793:
    v_22946 = stack[-4];
    goto v_22794;
v_22795:
    v_22945 = nil;
    goto v_22796;
v_22797:
    goto v_22781;
v_22782:
    goto v_22783;
v_22784:
    goto v_22785;
v_22786:
    goto v_22787;
v_22788:
    goto v_22789;
v_22790:
    goto v_22791;
v_22792:
    goto v_22793;
v_22794:
    goto v_22795;
v_22796:
    v_22945 = CC_talp_nextt1(elt(env, 0), 8, stack[0], v_22951, v_22950, v_22949, v_22948, v_22947, v_22946, v_22945);
    env = stack[-12];
    v_22946 = v_22945;
    v_22946 = qcar(v_22946);
    if (v_22946 == nil) goto v_22812;
    v_22946 = lisp_true;
    stack[-11] = v_22946;
    goto v_22821;
v_22817:
    v_22946 = stack[-1];
    goto v_22818;
v_22819:
    v_22945 = qcdr(v_22945);
    goto v_22820;
v_22821:
    goto v_22817;
v_22818:
    goto v_22819;
v_22820:
    fn = elt(env, 5); // setcar
    v_22945 = (*qfn2(fn))(fn, v_22946, v_22945);
    env = stack[-12];
    goto v_22810;
v_22812:
    goto v_22832;
v_22828:
    v_22946 = stack[-1];
    goto v_22829;
v_22830:
    v_22945 = stack[-2];
    goto v_22831;
v_22832:
    goto v_22828;
v_22829:
    goto v_22830;
v_22831:
    fn = elt(env, 5); // setcar
    v_22945 = (*qfn2(fn))(fn, v_22946, v_22945);
    env = stack[-12];
    goto v_22810;
v_22810:
    v_22945 = stack[-1];
    v_22945 = qcdr(v_22945);
    stack[-1] = v_22945;
    goto v_22770;
v_22769:
    goto v_22697;
v_22697:
    v_22945 = stack[-11];
    if (v_22945 == nil) goto v_22839;
    else goto v_22840;
v_22839:
    v_22945 = stack[-3];
    if (v_22945 == nil) goto v_22845;
    goto v_22852;
v_22848:
    v_22946 = stack[-10];
    goto v_22849;
v_22850:
    v_22945 = stack[-4];
    goto v_22851;
v_22852:
    goto v_22848;
v_22849:
    goto v_22850;
v_22851:
    fn = elt(env, 6); // talp_get!-idx
    v_22945 = (*qfn2(fn))(fn, v_22946, v_22945);
    env = stack[-12];
    stack[-1] = v_22945;
    goto v_22865;
v_22861:
    stack[0] = stack[-1];
    goto v_22862;
v_22863:
    v_22945 = stack[-4];
    v_22945 = Lupbv(nil, v_22945);
    env = stack[-12];
    goto v_22864;
v_22865:
    goto v_22861;
v_22862:
    goto v_22863;
v_22864:
    v_22945 = (LispObject)lessp2(stack[0], v_22945);
    v_22945 = v_22945 ? lisp_true : nil;
    env = stack[-12];
    if (v_22945 == nil) goto v_22859;
    goto v_22874;
v_22870:
    stack[0] = lisp_true;
    goto v_22871;
v_22872:
    goto v_22885;
v_22877:
    v_22945 = stack[-1];
    v_22948 = add1(v_22945);
    env = stack[-12];
    goto v_22878;
v_22879:
    v_22947 = stack[-4];
    goto v_22880;
v_22881:
    v_22946 = stack[-6];
    goto v_22882;
v_22883:
    v_22945 = stack[-7];
    goto v_22884;
v_22885:
    goto v_22877;
v_22878:
    goto v_22879;
v_22880:
    goto v_22881;
v_22882:
    goto v_22883;
v_22884:
    fn = elt(env, 7); // talp_get!-minfct
    v_22945 = (*qfnn(fn))(fn, 4, v_22948, v_22947, v_22946, v_22945);
    goto v_22873;
v_22874:
    goto v_22870;
v_22871:
    goto v_22872;
v_22873:
    {
        LispObject v_22965 = stack[0];
        return cons(v_22965, v_22945);
    }
v_22859:
    goto v_22843;
v_22845:
    goto v_22898;
v_22894:
    v_22946 = stack[-10];
    goto v_22895;
v_22896:
    v_22945 = stack[-5];
    goto v_22897;
v_22898:
    goto v_22894;
v_22895:
    goto v_22896;
v_22897:
    fn = elt(env, 6); // talp_get!-idx
    v_22945 = (*qfn2(fn))(fn, v_22946, v_22945);
    env = stack[-12];
    stack[-1] = v_22945;
    goto v_22911;
v_22907:
    stack[0] = stack[-1];
    goto v_22908;
v_22909:
    v_22945 = stack[-5];
    v_22945 = Lupbv(nil, v_22945);
    env = stack[-12];
    goto v_22910;
v_22911:
    goto v_22907;
v_22908:
    goto v_22909;
v_22910:
    v_22945 = (LispObject)lessp2(stack[0], v_22945);
    v_22945 = v_22945 ? lisp_true : nil;
    env = stack[-12];
    if (v_22945 == nil) goto v_22905;
    goto v_22920;
v_22916:
    stack[0] = lisp_true;
    goto v_22917;
v_22918:
    goto v_22931;
v_22923:
    v_22945 = stack[-1];
    v_22948 = add1(v_22945);
    env = stack[-12];
    goto v_22924;
v_22925:
    v_22947 = stack[-5];
    goto v_22926;
v_22927:
    v_22946 = stack[-6];
    goto v_22928;
v_22929:
    v_22945 = stack[-7];
    goto v_22930;
v_22931:
    goto v_22923;
v_22924:
    goto v_22925;
v_22926:
    goto v_22927;
v_22928:
    goto v_22929;
v_22930:
    fn = elt(env, 7); // talp_get!-minfct
    v_22945 = (*qfnn(fn))(fn, 4, v_22948, v_22947, v_22946, v_22945);
    goto v_22919;
v_22920:
    goto v_22916;
v_22917:
    goto v_22918;
v_22919:
    {
        LispObject v_22966 = stack[0];
        return cons(v_22966, v_22945);
    }
v_22905:
    goto v_22843;
v_22843:
    goto v_22838;
v_22840:
v_22838:
    goto v_22942;
v_22938:
    v_22946 = stack[-11];
    goto v_22939;
v_22940:
    v_22945 = stack[-10];
    goto v_22941;
v_22942:
    goto v_22938;
v_22939:
    goto v_22940;
v_22941:
    return cons(v_22946, v_22945);
    return onevalue(v_22945);
}



// Code for factor!-prim!-f

static LispObject CC_factorKprimKf(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22856, v_22857, v_22858;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_22651;
// end of prologue
    stack[-3] = nil;
    stack[-1] = nil;
    v_22856 = qvalue(elt(env, 1)); // ncmp!*
    if (v_22856 == nil) goto v_22662;
    goto v_22669;
v_22665:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22666;
v_22667:
    goto v_22676;
v_22672:
    v_22857 = stack[-2];
    goto v_22673;
v_22674:
    v_22856 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22675;
v_22676:
    goto v_22672;
v_22673:
    goto v_22674;
v_22675:
    v_22856 = cons(v_22857, v_22856);
    goto v_22668;
v_22669:
    goto v_22665;
v_22666:
    goto v_22667;
v_22668:
    {
        LispObject v_22863 = stack[0];
        return list2(v_22863, v_22856);
    }
v_22662:
    v_22856 = qvalue(elt(env, 2)); // dmode!*
    if (v_22856 == nil) goto v_22682;
    goto v_22691;
v_22687:
    v_22857 = qvalue(elt(env, 2)); // dmode!*
    goto v_22688;
v_22689:
    v_22856 = elt(env, 3); // sqfrfactorfn
    goto v_22690;
v_22691:
    goto v_22687;
v_22688:
    goto v_22689;
v_22690:
    v_22856 = get(v_22857, v_22856);
    env = stack[-4];
    stack[-1] = v_22856;
    if (v_22856 == nil) goto v_22682;
    v_22856 = qvalue(elt(env, 4)); // !*factor
    if (v_22856 == nil) goto v_22697;
    goto v_22704;
v_22700:
    v_22857 = stack[-1];
    goto v_22701;
v_22702:
    v_22856 = stack[-2];
    goto v_22703;
v_22704:
    goto v_22700;
v_22701:
    goto v_22702;
v_22703:
    v_22856 = Lapply1(nil, v_22857, v_22856);
    env = stack[-4];
    stack[0] = v_22856;
    goto v_22695;
v_22697:
    goto v_22714;
v_22710:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22711;
v_22712:
    goto v_22721;
v_22717:
    v_22857 = stack[-2];
    goto v_22718;
v_22719:
    v_22856 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22720;
v_22721:
    goto v_22717;
v_22718:
    goto v_22719;
v_22720:
    v_22856 = cons(v_22857, v_22856);
    env = stack[-4];
    goto v_22713;
v_22714:
    goto v_22710;
v_22711:
    goto v_22712;
v_22713:
    v_22856 = list2(stack[0], v_22856);
    env = stack[-4];
    stack[0] = v_22856;
    goto v_22695;
v_22695:
    goto v_22680;
v_22682:
    v_22856 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v_22856)) v_22856 = nil;
    else { v_22856 = qfastgets(v_22856);
           if (v_22856 != nil) { v_22856 = elt(v_22856, 3); // field
#ifdef RECORD_GET
             if (v_22856 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_22856 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_22856 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_22856 == SPID_NOPROP) v_22856 = nil; else v_22856 = lisp_true; }}
#endif
    if (v_22856 == nil) goto v_22729;
    goto v_22737;
v_22733:
    v_22856 = stack[-2];
    fn = elt(env, 6); // lnc
    v_22857 = (*qfn1(fn))(fn, v_22856);
    env = stack[-4];
    stack[-3] = v_22857;
    goto v_22734;
v_22735:
    v_22856 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22736;
v_22737:
    goto v_22733;
v_22734:
    goto v_22735;
v_22736:
    v_22856 = Lneq(nil, v_22857, v_22856);
    env = stack[-4];
    goto v_22727;
v_22729:
    v_22856 = nil;
    goto v_22727;
    v_22856 = nil;
v_22727:
    if (v_22856 == nil) goto v_22725;
    goto v_22749;
v_22745:
    stack[0] = stack[-3];
    goto v_22746;
v_22747:
    goto v_22757;
v_22753:
    v_22856 = stack[-3];
    fn = elt(env, 7); // !:recip
    v_22857 = (*qfn1(fn))(fn, v_22856);
    env = stack[-4];
    goto v_22754;
v_22755:
    v_22856 = stack[-2];
    goto v_22756;
v_22757:
    goto v_22753;
v_22754:
    goto v_22755;
v_22756:
    fn = elt(env, 8); // multd
    v_22856 = (*qfn2(fn))(fn, v_22857, v_22856);
    env = stack[-4];
    fn = elt(env, 9); // sqfrf
    v_22856 = (*qfn1(fn))(fn, v_22856);
    env = stack[-4];
    goto v_22748;
v_22749:
    goto v_22745;
v_22746:
    goto v_22747;
v_22748:
    v_22856 = cons(stack[0], v_22856);
    env = stack[-4];
    stack[0] = v_22856;
    goto v_22680;
v_22725:
    v_22856 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v_22856)) v_22856 = nil;
    else { v_22856 = qfastgets(v_22856);
           if (v_22856 != nil) { v_22856 = elt(v_22856, 27); // units
#ifdef RECORD_GET
             if (v_22856 != SPID_NOPROP)
                record_get(elt(fastget_names, 27), 1);
             else record_get(elt(fastget_names, 27), 0),
                v_22856 = nil; }
           else record_get(elt(fastget_names, 27), 0); }
#else
             if (v_22856 == SPID_NOPROP) v_22856 = nil; }}
#endif
    stack[-3] = v_22856;
    if (v_22856 == nil) goto v_22762;
    goto v_22771;
v_22767:
    v_22856 = stack[-2];
    fn = elt(env, 6); // lnc
    v_22857 = (*qfn1(fn))(fn, v_22856);
    env = stack[-4];
    v_22858 = v_22857;
    goto v_22768;
v_22769:
    v_22856 = stack[-3];
    goto v_22770;
v_22771:
    goto v_22767;
v_22768:
    goto v_22769;
v_22770:
    v_22856 = Lassoc(nil, v_22857, v_22856);
    stack[-3] = v_22856;
    if (v_22856 == nil) goto v_22762;
    goto v_22781;
v_22777:
    stack[0] = v_22858;
    goto v_22778;
v_22779:
    goto v_22789;
v_22785:
    v_22856 = stack[-3];
    v_22857 = qcdr(v_22856);
    goto v_22786;
v_22787:
    v_22856 = stack[-2];
    goto v_22788;
v_22789:
    goto v_22785;
v_22786:
    goto v_22787;
v_22788:
    fn = elt(env, 8); // multd
    v_22856 = (*qfn2(fn))(fn, v_22857, v_22856);
    env = stack[-4];
    fn = elt(env, 9); // sqfrf
    v_22856 = (*qfn1(fn))(fn, v_22856);
    env = stack[-4];
    goto v_22780;
v_22781:
    goto v_22777;
v_22778:
    goto v_22779;
v_22780:
    v_22856 = cons(stack[0], v_22856);
    env = stack[-4];
    stack[0] = v_22856;
    goto v_22680;
v_22762:
    goto v_22800;
v_22796:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22797;
v_22798:
    v_22856 = stack[-2];
    fn = elt(env, 9); // sqfrf
    v_22856 = (*qfn1(fn))(fn, v_22856);
    env = stack[-4];
    goto v_22799;
v_22800:
    goto v_22796;
v_22797:
    goto v_22798;
v_22799:
    v_22856 = cons(stack[0], v_22856);
    env = stack[-4];
    stack[0] = v_22856;
    goto v_22680;
v_22680:
    v_22856 = stack[-1];
    if (v_22856 == nil) goto v_22807;
    goto v_22815;
v_22811:
    v_22858 = stack[-1];
    goto v_22812;
v_22813:
    goto v_22822;
v_22818:
    v_22857 = qvalue(elt(env, 2)); // dmode!*
    goto v_22819;
v_22820:
    v_22856 = elt(env, 5); // factorfn
    goto v_22821;
v_22822:
    goto v_22818;
v_22819:
    goto v_22820;
v_22821:
    v_22856 = get(v_22857, v_22856);
    env = stack[-4];
    goto v_22814;
v_22815:
    goto v_22811;
v_22812:
    goto v_22813;
v_22814:
    if (v_22858 == v_22856) goto v_22810;
    else goto v_22807;
v_22810:
    v_22856 = stack[0];
    goto v_22658;
v_22807:
    v_22856 = stack[0];
    v_22856 = qcar(v_22856);
    v_22856 = ncons(v_22856);
    env = stack[-4];
    stack[-3] = v_22856;
    v_22856 = stack[0];
    v_22856 = qcdr(v_22856);
    stack[0] = v_22856;
v_22832:
    v_22856 = stack[0];
    if (v_22856 == nil) goto v_22837;
    else goto v_22838;
v_22837:
    goto v_22831;
v_22838:
    v_22856 = stack[0];
    v_22856 = qcar(v_22856);
    goto v_22849;
v_22845:
    fn = elt(env, 10); // factor!-prim!-sqfree!-f
    v_22857 = (*qfn1(fn))(fn, v_22856);
    env = stack[-4];
    goto v_22846;
v_22847:
    v_22856 = stack[-3];
    goto v_22848;
v_22849:
    goto v_22845;
v_22846:
    goto v_22847;
v_22848:
    fn = elt(env, 11); // fac!-merge
    v_22856 = (*qfn2(fn))(fn, v_22857, v_22856);
    env = stack[-4];
    stack[-3] = v_22856;
    v_22856 = stack[0];
    v_22856 = qcdr(v_22856);
    stack[0] = v_22856;
    goto v_22832;
v_22831:
    v_22856 = stack[-3];
v_22658:
    return onevalue(v_22856);
}



// Code for dvfsf_smcpknowl

static LispObject CC_dvfsf_smcpknowl(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22664, v_22665;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22665 = v_22651;
// end of prologue
    v_22664 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_22664 == nil) goto v_22656;
    v_22664 = v_22665;
    {
        fn = elt(env, 2); // cl_susicpknowl
        return (*qfn1(fn))(fn, v_22664);
    }
v_22656:
    v_22664 = v_22665;
    {
        fn = elt(env, 3); // cl_smcpknowl
        return (*qfn1(fn))(fn, v_22664);
    }
    v_22664 = nil;
    return onevalue(v_22664);
}



// Code for fnom

static LispObject CC_fnom(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22694;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_22651;
// end of prologue
    v_22694 = elt(env, 1); // "<OMA>"
    fn = elt(env, 11); // printout
    v_22694 = (*qfn1(fn))(fn, v_22694);
    env = stack[-1];
    v_22694 = lisp_true;
    fn = elt(env, 12); // indent!*
    v_22694 = (*qfn1(fn))(fn, v_22694);
    env = stack[-1];
    v_22694 = elt(env, 2); // "<OMATTR>"
    fn = elt(env, 11); // printout
    v_22694 = (*qfn1(fn))(fn, v_22694);
    env = stack[-1];
    v_22694 = lisp_true;
    fn = elt(env, 12); // indent!*
    v_22694 = (*qfn1(fn))(fn, v_22694);
    env = stack[-1];
    v_22694 = elt(env, 3); // "<OMATP>"
    fn = elt(env, 11); // printout
    v_22694 = (*qfn1(fn))(fn, v_22694);
    env = stack[-1];
    v_22694 = lisp_true;
    fn = elt(env, 12); // indent!*
    v_22694 = (*qfn1(fn))(fn, v_22694);
    env = stack[-1];
    v_22694 = elt(env, 4); // "<OMS cd=""typmml"" name=""type""/>"
    fn = elt(env, 11); // printout
    v_22694 = (*qfn1(fn))(fn, v_22694);
    env = stack[-1];
    v_22694 = elt(env, 5); // "<OMS cd=""typmml"" name="""
    fn = elt(env, 11); // printout
    v_22694 = (*qfn1(fn))(fn, v_22694);
    env = stack[-1];
    v_22694 = elt(env, 6); // "fn_type"
    v_22694 = Lprinc(nil, v_22694);
    env = stack[-1];
    v_22694 = elt(env, 7); // """/>"
    v_22694 = Lprinc(nil, v_22694);
    env = stack[-1];
    v_22694 = nil;
    fn = elt(env, 12); // indent!*
    v_22694 = (*qfn1(fn))(fn, v_22694);
    env = stack[-1];
    v_22694 = elt(env, 8); // "</OMATP>"
    fn = elt(env, 11); // printout
    v_22694 = (*qfn1(fn))(fn, v_22694);
    env = stack[-1];
    v_22694 = stack[0];
    v_22694 = qcar(v_22694);
    fn = elt(env, 13); // objectom
    v_22694 = (*qfn1(fn))(fn, v_22694);
    env = stack[-1];
    v_22694 = nil;
    fn = elt(env, 12); // indent!*
    v_22694 = (*qfn1(fn))(fn, v_22694);
    env = stack[-1];
    v_22694 = elt(env, 9); // "</OMATTR>"
    fn = elt(env, 11); // printout
    v_22694 = (*qfn1(fn))(fn, v_22694);
    env = stack[-1];
    v_22694 = stack[0];
    v_22694 = qcdr(v_22694);
    v_22694 = qcdr(v_22694);
    fn = elt(env, 14); // multiom
    v_22694 = (*qfn1(fn))(fn, v_22694);
    env = stack[-1];
    v_22694 = nil;
    fn = elt(env, 12); // indent!*
    v_22694 = (*qfn1(fn))(fn, v_22694);
    env = stack[-1];
    v_22694 = elt(env, 10); // "</OMA>"
    fn = elt(env, 11); // printout
    v_22694 = (*qfn1(fn))(fn, v_22694);
    v_22694 = nil;
    return onevalue(v_22694);
}



// Code for look_for_substitute

static LispObject CC_look_for_substitute(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22743, v_22744, v_22745;
    LispObject fn;
    LispObject v_22653, v_22652, v_22651;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "look_for_substitute");
    va_start(aa, nargs);
    v_22651 = va_arg(aa, LispObject);
    v_22652 = va_arg(aa, LispObject);
    v_22653 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22653,v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22651,v_22652,v_22653);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_22653;
    stack[-1] = v_22652;
    stack[-2] = v_22651;
// end of prologue
v_22650:
    v_22743 = qvalue(elt(env, 1)); // !*nointsubst
    if (v_22743 == nil) goto v_22658;
    v_22743 = nil;
    goto v_22656;
v_22658:
    v_22743 = stack[0];
    if (!consp(v_22743)) goto v_22668;
    else goto v_22669;
v_22668:
    v_22743 = nil;
    goto v_22665;
v_22669:
    goto v_22681;
v_22675:
    v_22745 = stack[-2];
    goto v_22676;
v_22677:
    v_22744 = stack[-1];
    goto v_22678;
v_22679:
    v_22743 = stack[0];
    goto v_22680;
v_22681:
    goto v_22675;
v_22676:
    goto v_22677;
v_22678:
    goto v_22679;
v_22680:
    fn = elt(env, 2); // look_for_exponential
    v_22743 = (*qfnn(fn))(fn, 3, v_22745, v_22744, v_22743);
    env = stack[-3];
    v_22744 = v_22743;
    if (v_22743 == nil) goto v_22673;
    v_22743 = v_22744;
    goto v_22665;
v_22673:
    goto v_22695;
v_22689:
    v_22745 = stack[-2];
    goto v_22690;
v_22691:
    v_22744 = stack[-1];
    goto v_22692;
v_22693:
    v_22743 = stack[0];
    goto v_22694;
v_22695:
    goto v_22689;
v_22690:
    goto v_22691;
v_22692:
    goto v_22693;
v_22694:
    fn = elt(env, 3); // look_for_rational
    v_22743 = (*qfnn(fn))(fn, 3, v_22745, v_22744, v_22743);
    env = stack[-3];
    v_22744 = v_22743;
    if (v_22743 == nil) goto v_22687;
    v_22743 = v_22744;
    goto v_22665;
v_22687:
    goto v_22709;
v_22703:
    v_22745 = stack[-2];
    goto v_22704;
v_22705:
    v_22744 = stack[-1];
    goto v_22706;
v_22707:
    v_22743 = stack[0];
    goto v_22708;
v_22709:
    goto v_22703;
v_22704:
    goto v_22705;
v_22706:
    goto v_22707;
v_22708:
    fn = elt(env, 4); // look_for_quad
    v_22743 = (*qfnn(fn))(fn, 3, v_22745, v_22744, v_22743);
    env = stack[-3];
    v_22744 = v_22743;
    if (v_22743 == nil) goto v_22701;
    v_22743 = v_22744;
    goto v_22665;
v_22701:
    goto v_22723;
v_22717:
    v_22745 = stack[-2];
    goto v_22718;
v_22719:
    v_22744 = stack[-1];
    goto v_22720;
v_22721:
    v_22743 = stack[0];
    v_22743 = qcar(v_22743);
    goto v_22722;
v_22723:
    goto v_22717;
v_22718:
    goto v_22719;
v_22720:
    goto v_22721;
v_22722:
    v_22743 = CC_look_for_substitute(elt(env, 0), 3, v_22745, v_22744, v_22743);
    env = stack[-3];
    v_22744 = v_22743;
    if (v_22743 == nil) goto v_22715;
    v_22743 = v_22744;
    goto v_22665;
v_22715:
    goto v_22738;
v_22732:
    v_22745 = stack[-2];
    goto v_22733;
v_22734:
    v_22744 = stack[-1];
    goto v_22735;
v_22736:
    v_22743 = stack[0];
    v_22743 = qcdr(v_22743);
    goto v_22737;
v_22738:
    goto v_22732;
v_22733:
    goto v_22734;
v_22735:
    goto v_22736;
v_22737:
    stack[-2] = v_22745;
    stack[-1] = v_22744;
    stack[0] = v_22743;
    goto v_22650;
    v_22743 = nil;
v_22665:
    goto v_22656;
    v_22743 = nil;
v_22656:
    return onevalue(v_22743);
}



// Code for aceq

static LispObject CC_aceq(LispObject env,
                         LispObject v_22651, LispObject v_22652)
{
    env = qenv(env);
    LispObject v_22695, v_22696, v_22697, v_22698;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22651,v_22652);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_22696 = v_22652;
    v_22697 = v_22651;
// end of prologue
v_22657:
    v_22695 = v_22697;
    if (v_22695 == nil) goto v_22660;
    else goto v_22661;
v_22660:
    v_22695 = v_22696;
    v_22695 = (v_22695 == nil ? lisp_true : nil);
    goto v_22656;
v_22661:
    v_22695 = v_22696;
    if (v_22695 == nil) goto v_22665;
    else goto v_22666;
v_22665:
    v_22695 = nil;
    goto v_22656;
v_22666:
    goto v_22675;
v_22671:
    v_22695 = v_22697;
    v_22698 = qcar(v_22695);
    goto v_22672;
v_22673:
    v_22695 = v_22696;
    goto v_22674;
v_22675:
    goto v_22671;
v_22672:
    goto v_22673;
v_22674:
    v_22695 = Lmember(nil, v_22698, v_22695);
    if (v_22695 == nil) goto v_22670;
    v_22695 = v_22697;
    v_22695 = qcdr(v_22695);
    stack[0] = v_22695;
    goto v_22687;
v_22683:
    v_22695 = v_22697;
    v_22695 = qcar(v_22695);
    goto v_22684;
v_22685:
    goto v_22686;
v_22687:
    goto v_22683;
v_22684:
    goto v_22685;
v_22686:
    v_22695 = Ldelete(nil, v_22695, v_22696);
    env = stack[-1];
    v_22696 = v_22695;
    v_22695 = stack[0];
    v_22697 = v_22695;
    goto v_22657;
v_22670:
    v_22695 = nil;
    goto v_22656;
    v_22695 = nil;
v_22656:
    return onevalue(v_22695);
}



// Code for s_world_names

static LispObject CC_s_world_names(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22696;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_22696 = v_22651;
// end of prologue
    v_22696 = qcar(v_22696);
    stack[-3] = v_22696;
    v_22696 = stack[-3];
    if (v_22696 == nil) goto v_22663;
    else goto v_22664;
v_22663:
    v_22696 = nil;
    goto v_22657;
v_22664:
    v_22696 = stack[-3];
    v_22696 = qcar(v_22696);
    v_22696 = qcar(v_22696);
    v_22696 = ncons(v_22696);
    env = stack[-4];
    stack[-1] = v_22696;
    stack[-2] = v_22696;
v_22658:
    v_22696 = stack[-3];
    v_22696 = qcdr(v_22696);
    stack[-3] = v_22696;
    v_22696 = stack[-3];
    if (v_22696 == nil) goto v_22677;
    else goto v_22678;
v_22677:
    v_22696 = stack[-2];
    goto v_22657;
v_22678:
    goto v_22686;
v_22682:
    stack[0] = stack[-1];
    goto v_22683;
v_22684:
    v_22696 = stack[-3];
    v_22696 = qcar(v_22696);
    v_22696 = qcar(v_22696);
    v_22696 = ncons(v_22696);
    env = stack[-4];
    goto v_22685;
v_22686:
    goto v_22682;
v_22683:
    goto v_22684;
v_22685:
    v_22696 = Lrplacd(nil, stack[0], v_22696);
    env = stack[-4];
    v_22696 = stack[-1];
    v_22696 = qcdr(v_22696);
    stack[-1] = v_22696;
    goto v_22658;
v_22657:
    return onevalue(v_22696);
}



// Code for mkimpart

static LispObject CC_mkimpart(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22697, v_22698;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_22651;
// end of prologue
    v_22697 = stack[0];
    fn = elt(env, 2); // realvaluedp
    v_22697 = (*qfn1(fn))(fn, v_22697);
    env = stack[-1];
    if (v_22697 == nil) goto v_22656;
    goto v_22664;
v_22660:
    v_22698 = nil;
    goto v_22661;
v_22662:
    v_22697 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22663;
v_22664:
    goto v_22660;
v_22661:
    goto v_22662;
v_22663:
    return cons(v_22698, v_22697);
v_22656:
    v_22697 = stack[0];
    fn = elt(env, 3); // sfp
    v_22697 = (*qfn1(fn))(fn, v_22697);
    env = stack[-1];
    if (v_22697 == nil) goto v_22668;
    goto v_22677;
v_22673:
    v_22698 = stack[0];
    goto v_22674;
v_22675:
    v_22697 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22676;
v_22677:
    goto v_22673;
v_22674:
    goto v_22675;
v_22676:
    v_22697 = cons(v_22698, v_22697);
    env = stack[-1];
    {
        fn = elt(env, 4); // impartsq
        return (*qfn1(fn))(fn, v_22697);
    }
v_22668:
    goto v_22687;
v_22683:
    goto v_22693;
v_22689:
    v_22698 = elt(env, 1); // impart
    goto v_22690;
v_22691:
    v_22697 = stack[0];
    goto v_22692;
v_22693:
    goto v_22689;
v_22690:
    goto v_22691;
v_22692:
    v_22698 = list2(v_22698, v_22697);
    env = stack[-1];
    goto v_22684;
v_22685:
    v_22697 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22686;
v_22687:
    goto v_22683;
v_22684:
    goto v_22685;
v_22686:
    {
        fn = elt(env, 5); // mksq
        return (*qfn2(fn))(fn, v_22698, v_22697);
    }
    v_22697 = nil;
    return onevalue(v_22697);
}



// Code for xremf

static LispObject CC_xremf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23018, v_23019, v_23020;
    LispObject fn;
    LispObject v_22653, v_22652, v_22651;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xremf");
    va_start(aa, nargs);
    v_22651 = va_arg(aa, LispObject);
    v_22652 = va_arg(aa, LispObject);
    v_22653 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22653,v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22651,v_22652,v_22653);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-5] = v_22653;
    stack[-6] = v_22652;
    stack[-7] = v_22651;
// end of prologue
    stack[-1] = nil;
    v_23018 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-8] = v_23018;
    v_23018 = stack[-6];
    if (!consp(v_23018)) goto v_22673;
    else goto v_22674;
v_22673:
    v_23018 = lisp_true;
    goto v_22672;
v_22674:
    v_23018 = stack[-6];
    v_23018 = qcar(v_23018);
    v_23018 = (consp(v_23018) ? nil : lisp_true);
    goto v_22672;
    v_23018 = nil;
v_22672:
    if (v_23018 == nil) goto v_22670;
    goto v_22688;
v_22684:
    v_23019 = stack[-7];
    goto v_22685;
v_22686:
    v_23018 = stack[-6];
    goto v_22687;
v_22688:
    goto v_22684;
v_22685:
    goto v_22686;
v_22687:
    fn = elt(env, 1); // qremd
    v_23018 = (*qfn2(fn))(fn, v_23019, v_23018);
    v_23018 = qcdr(v_23018);
    return ncons(v_23018);
v_22670:
    v_23018 = stack[-7];
    fn = elt(env, 2); // termsf
    v_23018 = (*qfn1(fn))(fn, v_23018);
    env = stack[-9];
    stack[0] = v_23018;
v_22663:
    goto v_22703;
v_22699:
    v_23019 = stack[-5];
    goto v_22700;
v_22701:
    v_23018 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22702;
v_22703:
    goto v_22699;
v_22700:
    goto v_22701;
v_22702:
    v_23018 = (LispObject)lesseq2(v_23019, v_23018);
    v_23018 = v_23018 ? lisp_true : nil;
    env = stack[-9];
    if (v_23018 == nil) goto v_22697;
    v_23018 = nil;
    goto v_22662;
v_22697:
    v_23018 = stack[-7];
    if (!consp(v_23018)) goto v_22711;
    else goto v_22712;
v_22711:
    v_23018 = lisp_true;
    goto v_22710;
v_22712:
    v_23018 = stack[-7];
    v_23018 = qcar(v_23018);
    v_23018 = (consp(v_23018) ? nil : lisp_true);
    goto v_22710;
    v_23018 = nil;
v_22710:
    if (v_23018 == nil) goto v_22708;
    goto v_22726;
v_22722:
    v_23019 = stack[-1];
    goto v_22723;
v_22724:
    v_23018 = stack[-7];
    goto v_22725;
v_22726:
    goto v_22722;
v_22723:
    goto v_22724;
v_22725:
    fn = elt(env, 3); // addf
    v_23018 = (*qfn2(fn))(fn, v_23019, v_23018);
    return ncons(v_23018);
v_22708:
    goto v_22735;
v_22731:
    v_23018 = stack[-7];
    v_23018 = qcar(v_23018);
    v_23018 = qcar(v_23018);
    v_23019 = qcar(v_23018);
    goto v_22732;
v_22733:
    v_23018 = stack[-6];
    v_23018 = qcar(v_23018);
    v_23018 = qcar(v_23018);
    v_23018 = qcar(v_23018);
    goto v_22734;
v_22735:
    goto v_22731;
v_22732:
    goto v_22733;
v_22734:
    if (v_23019 == v_23018) goto v_22729;
    else goto v_22730;
v_22729:
    goto v_22753;
v_22749:
    goto v_22759;
v_22755:
    v_23018 = stack[-7];
    v_23018 = qcar(v_23018);
    v_23018 = qcar(v_23018);
    v_23019 = qcdr(v_23018);
    goto v_22756;
v_22757:
    v_23018 = stack[-6];
    v_23018 = qcar(v_23018);
    v_23018 = qcar(v_23018);
    v_23018 = qcdr(v_23018);
    goto v_22758;
v_22759:
    goto v_22755;
v_22756:
    goto v_22757;
v_22758:
    v_23019 = difference2(v_23019, v_23018);
    env = stack[-9];
    stack[-4] = v_23019;
    goto v_22750;
v_22751:
    v_23018 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22752;
v_22753:
    goto v_22749;
v_22750:
    goto v_22751;
v_22752:
    v_23018 = (LispObject)lessp2(v_23019, v_23018);
    v_23018 = v_23018 ? lisp_true : nil;
    env = stack[-9];
    if (v_23018 == nil) goto v_22747;
    goto v_22775;
v_22771:
    v_23019 = stack[-1];
    goto v_22772;
v_22773:
    v_23018 = stack[-7];
    goto v_22774;
v_22775:
    goto v_22771;
v_22772:
    goto v_22773;
v_22774:
    fn = elt(env, 3); // addf
    v_23018 = (*qfn2(fn))(fn, v_23019, v_23018);
    return ncons(v_23018);
v_22747:
    goto v_22785;
v_22781:
    v_23018 = stack[-7];
    v_23018 = qcar(v_23018);
    v_23019 = qcdr(v_23018);
    goto v_22782;
v_22783:
    v_23018 = stack[-6];
    v_23018 = qcar(v_23018);
    v_23018 = qcdr(v_23018);
    goto v_22784;
v_22785:
    goto v_22781;
v_22782:
    goto v_22783;
v_22784:
    fn = elt(env, 4); // qremf
    v_23018 = (*qfn2(fn))(fn, v_23019, v_23018);
    env = stack[-9];
    stack[-3] = v_23018;
    goto v_22797;
v_22793:
    goto v_22804;
v_22800:
    v_23018 = stack[-7];
    v_23018 = qcar(v_23018);
    v_23019 = qcar(v_23018);
    goto v_22801;
v_22802:
    v_23018 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22803;
v_22804:
    goto v_22800;
v_22801:
    goto v_22802;
v_22803:
    v_23018 = cons(v_23019, v_23018);
    env = stack[-9];
    v_23019 = ncons(v_23018);
    env = stack[-9];
    goto v_22794;
v_22795:
    v_23018 = stack[-3];
    v_23018 = qcdr(v_23018);
    goto v_22796;
v_22797:
    goto v_22793;
v_22794:
    goto v_22795;
v_22796:
    fn = elt(env, 5); // multf
    v_23018 = (*qfn2(fn))(fn, v_23019, v_23018);
    env = stack[-9];
    stack[-2] = v_23018;
    goto v_22816;
v_22812:
    v_23019 = stack[-5];
    goto v_22813;
v_22814:
    v_23018 = stack[-8];
    goto v_22815;
v_22816:
    goto v_22812;
v_22813:
    goto v_22814;
v_22815:
    v_23018 = plus2(v_23019, v_23018);
    env = stack[-9];
    stack[-5] = v_23018;
    goto v_22824;
v_22820:
    v_23019 = stack[-1];
    goto v_22821;
v_22822:
    v_23018 = stack[-2];
    goto v_22823;
v_22824:
    goto v_22820;
v_22821:
    goto v_22822;
v_22823:
    fn = elt(env, 3); // addf
    v_23018 = (*qfn2(fn))(fn, v_23019, v_23018);
    env = stack[-9];
    stack[-1] = v_23018;
    v_23018 = stack[-1];
    fn = elt(env, 2); // termsf
    v_23018 = (*qfn1(fn))(fn, v_23018);
    env = stack[-9];
    stack[-8] = v_23018;
    goto v_22834;
v_22830:
    goto v_22840;
v_22836:
    v_23019 = stack[-5];
    goto v_22837;
v_22838:
    v_23018 = stack[-8];
    goto v_22839;
v_22840:
    goto v_22836;
v_22837:
    goto v_22838;
v_22839:
    v_23019 = difference2(v_23019, v_23018);
    env = stack[-9];
    goto v_22831;
v_22832:
    v_23018 = stack[0];
    goto v_22833;
v_22834:
    goto v_22830;
v_22831:
    goto v_22832;
v_22833:
    v_23018 = plus2(v_23019, v_23018);
    env = stack[-9];
    stack[-5] = v_23018;
    v_23018 = stack[-3];
    v_23018 = qcar(v_23018);
    if (v_23018 == nil) goto v_22846;
    else goto v_22847;
v_22846:
    v_23018 = stack[-7];
    v_23018 = qcdr(v_23018);
    goto v_22845;
v_22847:
    goto v_22859;
v_22855:
    goto v_22865;
v_22861:
    stack[0] = stack[-7];
    goto v_22862;
v_22863:
    goto v_22872;
v_22868:
    goto v_22881;
v_22877:
    v_23019 = stack[-4];
    goto v_22878;
v_22879:
    v_23018 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22880;
v_22881:
    goto v_22877;
v_22878:
    goto v_22879;
v_22880:
    if (v_23019 == v_23018) goto v_22875;
    else goto v_22876;
v_22875:
    v_23018 = stack[-6];
    stack[-4] = v_23018;
    goto v_22874;
v_22876:
    goto v_22892;
v_22888:
    goto v_22899;
v_22895:
    goto v_22905;
v_22901:
    v_23018 = stack[-7];
    v_23018 = qcar(v_23018);
    v_23018 = qcar(v_23018);
    v_23019 = qcar(v_23018);
    goto v_22902;
v_22903:
    v_23018 = stack[-4];
    goto v_22904;
v_22905:
    goto v_22901;
v_22902:
    goto v_22903;
v_22904:
    fn = elt(env, 6); // to
    v_23019 = (*qfn2(fn))(fn, v_23019, v_23018);
    env = stack[-9];
    goto v_22896;
v_22897:
    v_23018 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22898;
v_22899:
    goto v_22895;
v_22896:
    goto v_22897;
v_22898:
    v_23018 = cons(v_23019, v_23018);
    env = stack[-9];
    v_23019 = ncons(v_23018);
    env = stack[-9];
    goto v_22889;
v_22890:
    v_23018 = stack[-6];
    goto v_22891;
v_22892:
    goto v_22888;
v_22889:
    goto v_22890;
v_22891:
    fn = elt(env, 5); // multf
    v_23018 = (*qfn2(fn))(fn, v_23019, v_23018);
    env = stack[-9];
    stack[-4] = v_23018;
    goto v_22874;
    stack[-4] = nil;
v_22874:
    goto v_22869;
v_22870:
    v_23018 = stack[-3];
    v_23018 = qcar(v_23018);
    fn = elt(env, 7); // negf
    v_23018 = (*qfn1(fn))(fn, v_23018);
    env = stack[-9];
    goto v_22871;
v_22872:
    goto v_22868;
v_22869:
    goto v_22870;
v_22871:
    fn = elt(env, 5); // multf
    v_23018 = (*qfn2(fn))(fn, stack[-4], v_23018);
    env = stack[-9];
    goto v_22864;
v_22865:
    goto v_22861;
v_22862:
    goto v_22863;
v_22864:
    fn = elt(env, 3); // addf
    stack[0] = (*qfn2(fn))(fn, stack[0], v_23018);
    env = stack[-9];
    goto v_22856;
v_22857:
    v_23018 = stack[-2];
    fn = elt(env, 7); // negf
    v_23018 = (*qfn1(fn))(fn, v_23018);
    env = stack[-9];
    goto v_22858;
v_22859:
    goto v_22855;
v_22856:
    goto v_22857;
v_22858:
    fn = elt(env, 3); // addf
    v_23018 = (*qfn2(fn))(fn, stack[0], v_23018);
    env = stack[-9];
    goto v_22845;
    v_23018 = nil;
v_22845:
    stack[-7] = v_23018;
    v_23018 = stack[-7];
    fn = elt(env, 2); // termsf
    v_23018 = (*qfn1(fn))(fn, v_23018);
    env = stack[-9];
    stack[0] = v_23018;
    goto v_22925;
v_22921:
    v_23019 = stack[-5];
    goto v_22922;
v_22923:
    v_23018 = stack[0];
    goto v_22924;
v_22925:
    goto v_22921;
v_22922:
    goto v_22923;
v_22924:
    v_23018 = difference2(v_23019, v_23018);
    env = stack[-9];
    stack[-5] = v_23018;
    goto v_22663;
    goto v_22695;
v_22730:
    goto v_22935;
v_22931:
    v_23018 = stack[-7];
    v_23018 = qcar(v_23018);
    v_23018 = qcar(v_23018);
    v_23019 = qcar(v_23018);
    goto v_22932;
v_22933:
    v_23018 = stack[-6];
    v_23018 = qcar(v_23018);
    v_23018 = qcar(v_23018);
    v_23018 = qcar(v_23018);
    goto v_22934;
v_22935:
    goto v_22931;
v_22932:
    goto v_22933;
v_22934:
    fn = elt(env, 8); // ordop
    v_23018 = (*qfn2(fn))(fn, v_23019, v_23018);
    env = stack[-9];
    if (v_23018 == nil) goto v_22928;
    else goto v_22929;
v_22928:
    goto v_22950;
v_22946:
    v_23019 = stack[-1];
    goto v_22947;
v_22948:
    v_23018 = stack[-7];
    goto v_22949;
v_22950:
    goto v_22946;
v_22947:
    goto v_22948;
v_22949:
    fn = elt(env, 3); // addf
    v_23018 = (*qfn2(fn))(fn, v_23019, v_23018);
    return ncons(v_23018);
v_22929:
v_22695:
    goto v_22958;
v_22954:
    v_23019 = stack[-5];
    goto v_22955;
v_22956:
    v_23018 = stack[-8];
    goto v_22957;
v_22958:
    goto v_22954;
v_22955:
    goto v_22956;
v_22957:
    v_23018 = plus2(v_23019, v_23018);
    env = stack[-9];
    stack[-5] = v_23018;
    goto v_22968;
v_22962:
    v_23018 = stack[-7];
    v_23018 = qcar(v_23018);
    v_23020 = qcdr(v_23018);
    goto v_22963;
v_22964:
    v_23019 = stack[-6];
    goto v_22965;
v_22966:
    v_23018 = stack[-5];
    goto v_22967;
v_22968:
    goto v_22962;
v_22963:
    goto v_22964;
v_22965:
    goto v_22966;
v_22967:
    v_23018 = CC_xremf(elt(env, 0), 3, v_23020, v_23019, v_23018);
    env = stack[-9];
    stack[-3] = v_23018;
    v_23018 = stack[-3];
    if (v_23018 == nil) goto v_22976;
    else goto v_22977;
v_22976:
    v_23018 = nil;
    goto v_22662;
v_22977:
    goto v_22985;
v_22981:
    goto v_22982;
v_22983:
    goto v_22992;
v_22988:
    goto v_22999;
v_22995:
    v_23018 = stack[-7];
    v_23018 = qcar(v_23018);
    v_23019 = qcar(v_23018);
    goto v_22996;
v_22997:
    v_23018 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22998;
v_22999:
    goto v_22995;
v_22996:
    goto v_22997;
v_22998:
    v_23018 = cons(v_23019, v_23018);
    env = stack[-9];
    v_23019 = ncons(v_23018);
    env = stack[-9];
    goto v_22989;
v_22990:
    v_23018 = stack[-3];
    v_23018 = qcar(v_23018);
    goto v_22991;
v_22992:
    goto v_22988;
v_22989:
    goto v_22990;
v_22991:
    fn = elt(env, 5); // multf
    v_23018 = (*qfn2(fn))(fn, v_23019, v_23018);
    env = stack[-9];
    goto v_22984;
v_22985:
    goto v_22981;
v_22982:
    goto v_22983;
v_22984:
    fn = elt(env, 3); // addf
    v_23018 = (*qfn2(fn))(fn, stack[-1], v_23018);
    env = stack[-9];
    stack[-1] = v_23018;
    v_23018 = stack[-1];
    fn = elt(env, 2); // termsf
    v_23018 = (*qfn1(fn))(fn, v_23018);
    env = stack[-9];
    stack[-8] = v_23018;
    goto v_23013;
v_23009:
    v_23019 = stack[-5];
    goto v_23010;
v_23011:
    v_23018 = stack[-8];
    goto v_23012;
v_23013:
    goto v_23009;
v_23010:
    goto v_23011;
v_23012:
    v_23018 = difference2(v_23019, v_23018);
    env = stack[-9];
    stack[-5] = v_23018;
    v_23018 = stack[-7];
    v_23018 = qcdr(v_23018);
    stack[-7] = v_23018;
    goto v_22663;
v_22662:
    return onevalue(v_23018);
}



// Code for solvealgdepends

static LispObject CC_solvealgdepends(LispObject env,
                         LispObject v_22651, LispObject v_22652)
{
    env = qenv(env);
    LispObject v_22735, v_22736;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22651,v_22652);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22652;
    stack[-1] = v_22651;
// end of prologue
v_22657:
    goto v_22666;
v_22662:
    v_22736 = stack[-1];
    goto v_22663;
v_22664:
    v_22735 = stack[0];
    goto v_22665;
v_22666:
    goto v_22662;
v_22663:
    goto v_22664;
v_22665:
    if (equal(v_22736, v_22735)) goto v_22660;
    else goto v_22661;
v_22660:
    v_22735 = lisp_true;
    goto v_22656;
v_22661:
    v_22735 = stack[-1];
    if (!consp(v_22735)) goto v_22670;
    else goto v_22671;
v_22670:
    v_22735 = nil;
    goto v_22656;
v_22671:
    goto v_22681;
v_22677:
    v_22736 = stack[-1];
    goto v_22678;
v_22679:
    v_22735 = elt(env, 1); // root_of
    goto v_22680;
v_22681:
    goto v_22677;
v_22678:
    goto v_22679;
v_22680:
    if (!consp(v_22736)) goto v_22675;
    v_22736 = qcar(v_22736);
    if (v_22736 == v_22735) goto v_22674;
    else goto v_22675;
v_22674:
    goto v_22692;
v_22688:
    v_22736 = stack[0];
    goto v_22689;
v_22690:
    v_22735 = stack[-1];
    v_22735 = qcdr(v_22735);
    v_22735 = qcdr(v_22735);
    v_22735 = qcar(v_22735);
    goto v_22691;
v_22692:
    goto v_22688;
v_22689:
    goto v_22690;
v_22691:
    if (equal(v_22736, v_22735)) goto v_22686;
    else goto v_22687;
v_22686:
    v_22735 = nil;
    goto v_22656;
v_22687:
    v_22735 = stack[-1];
    v_22735 = qcdr(v_22735);
    v_22735 = qcar(v_22735);
    stack[-1] = v_22735;
    goto v_22657;
    goto v_22659;
v_22675:
    goto v_22715;
v_22711:
    v_22735 = stack[-1];
    v_22736 = qcar(v_22735);
    goto v_22712;
v_22713:
    v_22735 = stack[0];
    goto v_22714;
v_22715:
    goto v_22711;
v_22712:
    goto v_22713;
v_22714:
    v_22735 = CC_solvealgdepends(elt(env, 0), v_22736, v_22735);
    env = stack[-2];
    v_22736 = v_22735;
    if (v_22735 == nil) goto v_22709;
    v_22735 = v_22736;
    goto v_22656;
v_22709:
    goto v_22727;
v_22723:
    v_22735 = stack[-1];
    v_22736 = qcdr(v_22735);
    goto v_22724;
v_22725:
    v_22735 = stack[0];
    goto v_22726;
v_22727:
    goto v_22723;
v_22724:
    goto v_22725;
v_22726:
    v_22735 = CC_solvealgdepends(elt(env, 0), v_22736, v_22735);
    v_22736 = v_22735;
    if (v_22735 == nil) goto v_22721;
    v_22735 = v_22736;
    goto v_22656;
v_22721:
    v_22735 = nil;
    goto v_22656;
    goto v_22659;
v_22659:
    v_22735 = nil;
v_22656:
    return onevalue(v_22735);
}



// Code for lalr_augment_grammar

static LispObject CC_lalr_augment_grammar(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22687, v_22688;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22651;
// end of prologue
    goto v_22661;
v_22657:
    v_22688 = elt(env, 1); // !S!'
    goto v_22658;
v_22659:
    v_22687 = stack[0];
    goto v_22660;
v_22661:
    goto v_22657;
v_22658:
    goto v_22659;
v_22660:
    v_22687 = Lassoc(nil, v_22688, v_22687);
    if (v_22687 == nil) goto v_22656;
    v_22687 = stack[0];
    goto v_22654;
v_22656:
    goto v_22673;
v_22669:
    goto v_22679;
v_22675:
    stack[-1] = elt(env, 1); // !S!'
    goto v_22676;
v_22677:
    v_22687 = stack[0];
    v_22687 = qcar(v_22687);
    v_22687 = qcar(v_22687);
    v_22687 = ncons(v_22687);
    env = stack[-2];
    v_22687 = ncons(v_22687);
    env = stack[-2];
    goto v_22678;
v_22679:
    goto v_22675;
v_22676:
    goto v_22677;
v_22678:
    v_22688 = list2(stack[-1], v_22687);
    goto v_22670;
v_22671:
    v_22687 = stack[0];
    goto v_22672;
v_22673:
    goto v_22669;
v_22670:
    goto v_22671;
v_22672:
    return cons(v_22688, v_22687);
    v_22687 = nil;
v_22654:
    return onevalue(v_22687);
}



// Code for sfto_subfwd

static LispObject CC_sfto_subfwd(LispObject env,
                         LispObject v_22651, LispObject v_22652)
{
    env = qenv(env);
    LispObject v_22747, v_22748;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22651,v_22652);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_22652;
    stack[-3] = v_22651;
// end of prologue
// Binding d
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = nil; // d
    v_22747 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_22747; // d
    v_22747 = stack[-3];
    if (!consp(v_22747)) goto v_22665;
    else goto v_22666;
v_22665:
    v_22747 = lisp_true;
    goto v_22664;
v_22666:
    v_22747 = stack[-3];
    v_22747 = qcar(v_22747);
    v_22747 = (consp(v_22747) ? nil : lisp_true);
    goto v_22664;
    v_22747 = nil;
v_22664:
    if (v_22747 == nil) goto v_22662;
    v_22747 = stack[-3];
    goto v_22657;
v_22662:
    goto v_22679;
v_22675:
    v_22747 = stack[-3];
    v_22747 = qcar(v_22747);
    v_22747 = qcar(v_22747);
    v_22748 = qcar(v_22747);
    goto v_22676;
v_22677:
    v_22747 = stack[-2];
    goto v_22678;
v_22679:
    goto v_22675;
v_22676:
    goto v_22677;
v_22678:
    v_22747 = Latsoc(nil, v_22748, v_22747);
    v_22748 = v_22747;
    if (v_22748 == nil) goto v_22689;
    goto v_22696;
v_22692:
    v_22748 = stack[-3];
    v_22748 = qcar(v_22748);
    v_22748 = qcar(v_22748);
    v_22748 = qcdr(v_22748);
    goto v_22693;
v_22694:
    v_22747 = qcdr(v_22747);
    goto v_22695;
v_22696:
    goto v_22692;
v_22693:
    goto v_22694;
v_22695:
    v_22747 = quot2(v_22748, v_22747);
    env = stack[-5];
    goto v_22687;
v_22689:
    v_22747 = stack[-3];
    v_22747 = qcar(v_22747);
    v_22747 = qcar(v_22747);
    v_22747 = qcdr(v_22747);
    goto v_22687;
    v_22747 = nil;
v_22687:
    qvalue(elt(env, 1)) = v_22747; // d
    goto v_22716;
v_22710:
    goto v_22722;
v_22718:
    v_22747 = stack[-3];
    v_22747 = qcar(v_22747);
    v_22747 = qcar(v_22747);
    v_22748 = qcar(v_22747);
    goto v_22719;
v_22720:
    v_22747 = qvalue(elt(env, 1)); // d
    goto v_22721;
v_22722:
    goto v_22718;
v_22719:
    goto v_22720;
v_22721:
    fn = elt(env, 2); // to
    stack[-1] = (*qfn2(fn))(fn, v_22748, v_22747);
    env = stack[-5];
    goto v_22711;
v_22712:
    goto v_22733;
v_22729:
    v_22747 = stack[-3];
    v_22747 = qcar(v_22747);
    v_22748 = qcdr(v_22747);
    goto v_22730;
v_22731:
    v_22747 = stack[-2];
    goto v_22732;
v_22733:
    goto v_22729;
v_22730:
    goto v_22731;
v_22732:
    stack[0] = CC_sfto_subfwd(elt(env, 0), v_22748, v_22747);
    env = stack[-5];
    goto v_22713;
v_22714:
    goto v_22743;
v_22739:
    v_22747 = stack[-3];
    v_22748 = qcdr(v_22747);
    goto v_22740;
v_22741:
    v_22747 = stack[-2];
    goto v_22742;
v_22743:
    goto v_22739;
v_22740:
    goto v_22741;
v_22742:
    v_22747 = CC_sfto_subfwd(elt(env, 0), v_22748, v_22747);
    env = stack[-5];
    goto v_22715;
v_22716:
    goto v_22710;
v_22711:
    goto v_22712;
v_22713:
    goto v_22714;
v_22715:
    v_22747 = acons(stack[-1], stack[0], v_22747);
v_22657:
    ;}  // end of a binding scope
    return onevalue(v_22747);
}



// Code for vectorrd

static LispObject CC_vectorrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22678, v_22679, v_22680;
    LispObject fn;
    argcheck(nargs, 0, "vectorrd");
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
    goto v_22661;
v_22657:
    v_22679 = qvalue(elt(env, 1)); // atts
    goto v_22658;
v_22659:
    v_22678 = elt(env, 2); // (type other)
    goto v_22660;
v_22661:
    goto v_22657;
v_22658:
    goto v_22659;
v_22660:
    fn = elt(env, 4); // retattributes
    v_22678 = (*qfn2(fn))(fn, v_22679, v_22678);
    env = stack[-1];
    stack[0] = v_22678;
    fn = elt(env, 5); // matrixrowrd
    v_22678 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_22679 = v_22678;
    goto v_22673;
v_22667:
    v_22680 = elt(env, 3); // vectorml
    goto v_22668;
v_22669:
    v_22678 = stack[0];
    goto v_22670;
v_22671:
    goto v_22672;
v_22673:
    goto v_22667;
v_22668:
    goto v_22669;
v_22670:
    goto v_22671;
v_22672:
    return list2star(v_22680, v_22678, v_22679);
    return onevalue(v_22678);
}



// Code for genexp

static LispObject CC_genexp(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22671;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_22651;
// end of prologue
v_22650:
    v_22671 = stack[0];
    if (!consp(v_22671)) goto v_22655;
    else goto v_22656;
v_22655:
    v_22671 = stack[0];
    {
        fn = elt(env, 1); // genp
        return (*qfn1(fn))(fn, v_22671);
    }
v_22656:
    v_22671 = stack[0];
    v_22671 = qcar(v_22671);
    v_22671 = CC_genexp(elt(env, 0), v_22671);
    env = stack[-1];
    if (v_22671 == nil) goto v_22664;
    else goto v_22663;
v_22664:
    v_22671 = stack[0];
    v_22671 = qcdr(v_22671);
    stack[0] = v_22671;
    goto v_22650;
v_22663:
    goto v_22654;
    v_22671 = nil;
v_22654:
    return onevalue(v_22671);
}



// Code for simp_without_resimp

static LispObject CC_simp_without_resimp(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22657, v_22658;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_22658 = v_22651;
// end of prologue
    v_22657 = nil;
// Binding !*resimp
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_22657; // !*resimp
    v_22657 = v_22658;
    fn = elt(env, 2); // simp
    v_22657 = (*qfn1(fn))(fn, v_22657);
    ;}  // end of a binding scope
    return onevalue(v_22657);
}



// Code for sc_columnscalarproduct

static LispObject CC_sc_columnscalarproduct(LispObject env,
                         LispObject v_22651, LispObject v_22652)
{
    env = qenv(env);
    LispObject v_22717, v_22718, v_22719;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22651,v_22652);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_22652;
    stack[-3] = v_22651;
// end of prologue
    v_22717 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 1); // sc_simp
    v_22717 = (*qfn1(fn))(fn, v_22717);
    env = stack[-5];
    stack[0] = v_22717;
    v_22717 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_22717;
v_22662:
    goto v_22674;
v_22670:
    v_22717 = stack[-3];
    fn = elt(env, 2); // fast!-row!-dim
    v_22718 = (*qfn1(fn))(fn, v_22717);
    env = stack[-5];
    goto v_22671;
v_22672:
    v_22717 = stack[-4];
    goto v_22673;
v_22674:
    goto v_22670;
v_22671:
    goto v_22672;
v_22673:
    v_22717 = difference2(v_22718, v_22717);
    env = stack[-5];
    v_22717 = Lminusp(nil, v_22717);
    env = stack[-5];
    if (v_22717 == nil) goto v_22667;
    goto v_22661;
v_22667:
    goto v_22684;
v_22680:
    stack[-1] = stack[0];
    goto v_22681;
v_22682:
    goto v_22691;
v_22687:
    goto v_22699;
v_22693:
    v_22719 = stack[-3];
    goto v_22694;
v_22695:
    v_22718 = stack[-4];
    goto v_22696;
v_22697:
    v_22717 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22698;
v_22699:
    goto v_22693;
v_22694:
    goto v_22695;
v_22696:
    goto v_22697;
v_22698:
    fn = elt(env, 3); // sc_getmat
    stack[0] = (*qfnn(fn))(fn, 3, v_22719, v_22718, v_22717);
    env = stack[-5];
    goto v_22688;
v_22689:
    goto v_22710;
v_22704:
    v_22719 = stack[-2];
    goto v_22705;
v_22706:
    v_22718 = stack[-4];
    goto v_22707;
v_22708:
    v_22717 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22709;
v_22710:
    goto v_22704;
v_22705:
    goto v_22706;
v_22707:
    goto v_22708;
v_22709:
    fn = elt(env, 3); // sc_getmat
    v_22717 = (*qfnn(fn))(fn, 3, v_22719, v_22718, v_22717);
    env = stack[-5];
    goto v_22690;
v_22691:
    goto v_22687;
v_22688:
    goto v_22689;
v_22690:
    fn = elt(env, 4); // sc_multsq
    v_22717 = (*qfn2(fn))(fn, stack[0], v_22717);
    env = stack[-5];
    goto v_22683;
v_22684:
    goto v_22680;
v_22681:
    goto v_22682;
v_22683:
    fn = elt(env, 5); // sc_addsq
    v_22717 = (*qfn2(fn))(fn, stack[-1], v_22717);
    env = stack[-5];
    stack[0] = v_22717;
    v_22717 = stack[-4];
    v_22717 = add1(v_22717);
    env = stack[-5];
    stack[-4] = v_22717;
    goto v_22662;
v_22661:
    v_22717 = stack[0];
    return onevalue(v_22717);
}



// Code for simpunion

static LispObject CC_simpunion(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22726, v_22727, v_22728;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_22726 = v_22651;
// end of prologue
    goto v_22658;
v_22654:
    v_22727 = elt(env, 1); // union
    goto v_22655;
v_22656:
    goto v_22657;
v_22658:
    goto v_22654;
v_22655:
    goto v_22656;
v_22657:
    fn = elt(env, 3); // applysetop
    v_22726 = (*qfn2(fn))(fn, v_22727, v_22726);
    env = stack[-1];
    v_22728 = v_22726;
    goto v_22667;
v_22663:
    goto v_22674;
v_22670:
    goto v_22680;
v_22676:
    goto v_22689;
v_22685:
    v_22726 = v_22728;
    v_22727 = qcar(v_22726);
    goto v_22686;
v_22687:
    v_22726 = elt(env, 1); // union
    goto v_22688;
v_22689:
    goto v_22685;
v_22686:
    goto v_22687;
v_22688:
    if (v_22727 == v_22726) goto v_22683;
    else goto v_22684;
v_22683:
    goto v_22702;
v_22698:
    v_22726 = qvalue(elt(env, 2)); // empty_set
    goto v_22699;
v_22700:
    v_22727 = v_22728;
    v_22727 = qcdr(v_22727);
    goto v_22701;
v_22702:
    goto v_22698;
v_22699:
    goto v_22700;
v_22701:
    v_22726 = Ldelete(nil, v_22726, v_22727);
    env = stack[-1];
    v_22728 = v_22726;
    v_22726 = qcdr(v_22726);
    if (v_22726 == nil) goto v_22696;
    goto v_22712;
v_22708:
    stack[0] = elt(env, 1); // union
    goto v_22709;
v_22710:
    v_22726 = v_22728;
    fn = elt(env, 4); // ordn
    v_22726 = (*qfn1(fn))(fn, v_22726);
    env = stack[-1];
    goto v_22711;
v_22712:
    goto v_22708;
v_22709:
    goto v_22710;
v_22711:
    v_22726 = cons(stack[0], v_22726);
    env = stack[-1];
    goto v_22694;
v_22696:
    v_22726 = v_22728;
    v_22726 = qcar(v_22726);
    goto v_22694;
    v_22726 = nil;
v_22694:
    v_22727 = v_22726;
    goto v_22682;
v_22684:
    v_22726 = v_22728;
    v_22727 = v_22726;
    goto v_22682;
    v_22727 = nil;
v_22682:
    goto v_22677;
v_22678:
    v_22726 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22679;
v_22680:
    goto v_22676;
v_22677:
    goto v_22678;
v_22679:
    fn = elt(env, 5); // mksp
    v_22727 = (*qfn2(fn))(fn, v_22727, v_22726);
    env = stack[-1];
    goto v_22671;
v_22672:
    v_22726 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22673;
v_22674:
    goto v_22670;
v_22671:
    goto v_22672;
v_22673:
    v_22726 = cons(v_22727, v_22726);
    env = stack[-1];
    v_22727 = ncons(v_22726);
    goto v_22664;
v_22665:
    v_22726 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22666;
v_22667:
    goto v_22663;
v_22664:
    goto v_22665;
v_22666:
    return cons(v_22727, v_22726);
}



// Code for gfplus

static LispObject CC_gfplus(LispObject env,
                         LispObject v_22651, LispObject v_22652)
{
    env = qenv(env);
    LispObject v_22678, v_22679, v_22680;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22679 = v_22652;
    v_22680 = v_22651;
// end of prologue
    v_22678 = v_22680;
    v_22678 = qcar(v_22678);
    if (!consp(v_22678)) goto v_22656;
    else goto v_22657;
v_22656:
    goto v_22665;
v_22661:
    v_22678 = v_22680;
    goto v_22662;
v_22663:
    goto v_22664;
v_22665:
    goto v_22661;
v_22662:
    goto v_22663;
v_22664:
    {
        fn = elt(env, 1); // gffplus
        return (*qfn2(fn))(fn, v_22678, v_22679);
    }
v_22657:
    goto v_22675;
v_22671:
    v_22678 = v_22680;
    goto v_22672;
v_22673:
    goto v_22674;
v_22675:
    goto v_22671;
v_22672:
    goto v_22673;
v_22674:
    {
        fn = elt(env, 2); // gbfplus
        return (*qfn2(fn))(fn, v_22678, v_22679);
    }
    v_22678 = nil;
    return onevalue(v_22678);
}



// Code for getupper

static LispObject CC_getupper(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22662, v_22663;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22662 = v_22651;
// end of prologue
    goto v_22657;
v_22653:
    goto v_22654;
v_22655:
    v_22663 = qvalue(elt(env, 1)); // metricu!*
    goto v_22656;
v_22657:
    goto v_22653;
v_22654:
    goto v_22655;
v_22656:
    v_22662 = Latsoc(nil, v_22662, v_22663);
    v_22662 = qcdr(v_22662);
    return onevalue(v_22662);
}



// Code for s_noparents

static LispObject CC_s_noparents(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22684, v_22685;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22651;
// end of prologue
    stack[-1] = nil;
v_22656:
    v_22684 = stack[0];
    if (v_22684 == nil) goto v_22659;
    else goto v_22660;
v_22659:
    v_22684 = stack[-1];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_22684);
    }
v_22660:
    v_22684 = stack[0];
    v_22684 = qcar(v_22684);
    fn = elt(env, 2); // has_parents
    v_22684 = (*qfn1(fn))(fn, v_22684);
    env = stack[-2];
    if (v_22684 == nil) goto v_22665;
    v_22684 = stack[0];
    v_22684 = qcdr(v_22684);
    stack[0] = v_22684;
    goto v_22656;
v_22665:
    goto v_22678;
v_22674:
    v_22684 = stack[0];
    v_22685 = qcar(v_22684);
    goto v_22675;
v_22676:
    v_22684 = stack[-1];
    goto v_22677;
v_22678:
    goto v_22674;
v_22675:
    goto v_22676;
v_22677:
    v_22684 = cons(v_22685, v_22684);
    env = stack[-2];
    stack[-1] = v_22684;
    v_22684 = stack[0];
    v_22684 = qcdr(v_22684);
    stack[0] = v_22684;
    goto v_22656;
    v_22684 = nil;
    return onevalue(v_22684);
}



// Code for reduce

static LispObject CC_reduce(LispObject env,
                         LispObject v_22651, LispObject v_22652)
{
    env = qenv(env);
    LispObject v_22707, v_22708, v_22709;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22651,v_22652);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_22652;
    v_22707 = v_22651;
// end of prologue
    stack[0] = v_22707;
    v_22707 = qvalue(elt(env, 1)); // !*yyy
    if (v_22707 == nil) goto v_22662;
    goto v_22669;
v_22665:
    v_22708 = stack[0];
    goto v_22666;
v_22667:
    v_22707 = stack[-1];
    goto v_22668;
v_22669:
    goto v_22665;
v_22666:
    goto v_22667;
v_22668:
    fn = elt(env, 3); // reduce!-ratios
    v_22707 = (*qfn2(fn))(fn, v_22708, v_22707);
    env = stack[-3];
    stack[0] = v_22707;
    goto v_22660;
v_22662:
v_22660:
    v_22707 = stack[-1];
    fn = elt(env, 4); // set!-weights
    v_22707 = (*qfn1(fn))(fn, v_22707);
    env = stack[-3];
    stack[-2] = v_22707;
    v_22707 = qvalue(elt(env, 2)); // !*xxx
    if (v_22707 == nil) goto v_22677;
    goto v_22686;
v_22680:
    v_22709 = stack[0];
    goto v_22681;
v_22682:
    v_22708 = stack[-1];
    goto v_22683;
v_22684:
    v_22707 = stack[-2];
    goto v_22685;
v_22686:
    goto v_22680;
v_22681:
    goto v_22682;
v_22683:
    goto v_22684;
v_22685:
    fn = elt(env, 5); // reduce!-columns
    v_22707 = (*qfnn(fn))(fn, 3, v_22709, v_22708, v_22707);
    env = stack[-3];
    stack[0] = v_22707;
    goto v_22675;
v_22677:
v_22675:
    v_22707 = qvalue(elt(env, 2)); // !*xxx
    if (v_22707 == nil) goto v_22693;
    goto v_22702;
v_22696:
    v_22709 = stack[0];
    goto v_22697;
v_22698:
    v_22708 = stack[-1];
    goto v_22699;
v_22700:
    v_22707 = stack[-2];
    goto v_22701;
v_22702:
    goto v_22696;
v_22697:
    goto v_22698;
v_22699:
    goto v_22700;
v_22701:
    fn = elt(env, 6); // reduce!-weights
    v_22707 = (*qfnn(fn))(fn, 3, v_22709, v_22708, v_22707);
    stack[0] = v_22707;
    goto v_22691;
v_22693:
v_22691:
    v_22707 = stack[0];
    return onevalue(v_22707);
}



// Code for cali!=min

static LispObject CC_caliMmin(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22708, v_22709, v_22710;
    LispObject fn;
    LispObject v_22653, v_22652, v_22651;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cali=min");
    va_start(aa, nargs);
    v_22651 = va_arg(aa, LispObject);
    v_22652 = va_arg(aa, LispObject);
    v_22653 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22653,v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22651,v_22652,v_22653);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_22653;
    stack[-1] = v_22652;
    stack[-2] = v_22651;
// end of prologue
v_22657:
    v_22708 = stack[-1];
    if (v_22708 == nil) goto v_22660;
    else goto v_22661;
v_22660:
    v_22708 = stack[-2];
    goto v_22656;
v_22661:
    goto v_22674;
v_22668:
    v_22710 = stack[-2];
    goto v_22669;
v_22670:
    v_22708 = stack[-1];
    v_22709 = qcar(v_22708);
    goto v_22671;
v_22672:
    v_22708 = stack[0];
    goto v_22673;
v_22674:
    goto v_22668;
v_22669:
    goto v_22670;
v_22671:
    goto v_22672;
v_22673:
    fn = elt(env, 1); // listtest
    v_22708 = (*qfnn(fn))(fn, 3, v_22710, v_22709, v_22708);
    env = stack[-3];
    if (v_22708 == nil) goto v_22666;
    else goto v_22664;
v_22666:
    goto v_22687;
v_22681:
    v_22708 = stack[-1];
    v_22710 = qcdr(v_22708);
    goto v_22682;
v_22683:
    v_22708 = stack[-1];
    v_22709 = qcar(v_22708);
    goto v_22684;
v_22685:
    v_22708 = stack[0];
    goto v_22686;
v_22687:
    goto v_22681;
v_22682:
    goto v_22683;
v_22684:
    goto v_22685;
v_22686:
    fn = elt(env, 1); // listtest
    v_22708 = (*qfnn(fn))(fn, 3, v_22710, v_22709, v_22708);
    env = stack[-3];
    if (v_22708 == nil) goto v_22679;
    else goto v_22664;
v_22679:
    goto v_22665;
v_22664:
    v_22708 = stack[-1];
    v_22708 = qcdr(v_22708);
    stack[-1] = v_22708;
    goto v_22657;
v_22665:
    goto v_22702;
v_22698:
    v_22708 = stack[-1];
    v_22709 = qcar(v_22708);
    goto v_22699;
v_22700:
    v_22708 = stack[-2];
    goto v_22701;
v_22702:
    goto v_22698;
v_22699:
    goto v_22700;
v_22701:
    v_22708 = cons(v_22709, v_22708);
    env = stack[-3];
    stack[-2] = v_22708;
    v_22708 = stack[-1];
    v_22708 = qcdr(v_22708);
    stack[-1] = v_22708;
    goto v_22657;
    v_22708 = nil;
v_22656:
    return onevalue(v_22708);
}



// Code for !*multf

static LispObject CC_Hmultf(LispObject env,
                         LispObject v_22651, LispObject v_22652)
{
    env = qenv(env);
    LispObject v_23267, v_23268, v_23269;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22651,v_22652);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_22652;
    stack[-3] = v_22651;
// end of prologue
    v_23267 = stack[-3];
    if (v_23267 == nil) goto v_22666;
    else goto v_22667;
v_22666:
    v_23267 = lisp_true;
    goto v_22665;
v_22667:
    v_23267 = stack[-2];
    v_23267 = (v_23267 == nil ? lisp_true : nil);
    goto v_22665;
    v_23267 = nil;
v_22665:
    if (v_23267 == nil) goto v_22663;
    v_23267 = nil;
    goto v_22657;
v_22663:
    goto v_22681;
v_22677:
    v_23268 = stack[-3];
    goto v_22678;
v_22679:
    v_23267 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22680;
v_22681:
    goto v_22677;
v_22678:
    goto v_22679;
v_22680:
    if (v_23268 == v_23267) goto v_22675;
    else goto v_22676;
v_22675:
    v_23267 = stack[-2];
    {
        fn = elt(env, 5); // squashsqrt
        return (*qfn1(fn))(fn, v_23267);
    }
v_22676:
    goto v_22692;
v_22688:
    v_23268 = stack[-2];
    goto v_22689;
v_22690:
    v_23267 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22691;
v_22692:
    goto v_22688;
v_22689:
    goto v_22690;
v_22691:
    if (v_23268 == v_23267) goto v_22686;
    else goto v_22687;
v_22686:
    v_23267 = stack[-3];
    {
        fn = elt(env, 5); // squashsqrt
        return (*qfn1(fn))(fn, v_23267);
    }
v_22687:
    v_23267 = stack[-3];
    if (!consp(v_23267)) goto v_22701;
    else goto v_22702;
v_22701:
    v_23267 = lisp_true;
    goto v_22700;
v_22702:
    v_23267 = stack[-3];
    v_23267 = qcar(v_23267);
    v_23267 = (consp(v_23267) ? nil : lisp_true);
    goto v_22700;
    v_23267 = nil;
v_22700:
    if (v_23267 == nil) goto v_22698;
    goto v_22715;
v_22711:
    stack[0] = stack[-3];
    goto v_22712;
v_22713:
    v_23267 = stack[-2];
    fn = elt(env, 5); // squashsqrt
    v_23267 = (*qfn1(fn))(fn, v_23267);
    env = stack[-5];
    goto v_22714;
v_22715:
    goto v_22711;
v_22712:
    goto v_22713;
v_22714:
    {
        LispObject v_23275 = stack[0];
        fn = elt(env, 6); // multd
        return (*qfn2(fn))(fn, v_23275, v_23267);
    }
v_22698:
    v_23267 = stack[-2];
    if (!consp(v_23267)) goto v_22723;
    else goto v_22724;
v_22723:
    v_23267 = lisp_true;
    goto v_22722;
v_22724:
    v_23267 = stack[-2];
    v_23267 = qcar(v_23267);
    v_23267 = (consp(v_23267) ? nil : lisp_true);
    goto v_22722;
    v_23267 = nil;
v_22722:
    if (v_23267 == nil) goto v_22720;
    goto v_22737;
v_22733:
    stack[0] = stack[-2];
    goto v_22734;
v_22735:
    v_23267 = stack[-3];
    fn = elt(env, 5); // squashsqrt
    v_23267 = (*qfn1(fn))(fn, v_23267);
    env = stack[-5];
    goto v_22736;
v_22737:
    goto v_22733;
v_22734:
    goto v_22735;
v_22736:
    {
        LispObject v_23276 = stack[0];
        fn = elt(env, 6); // multd
        return (*qfn2(fn))(fn, v_23276, v_23267);
    }
v_22720:
    v_23267 = qvalue(elt(env, 1)); // !*noncomp
    if (v_23267 == nil) goto v_22742;
    goto v_22749;
v_22745:
    v_23268 = stack[-3];
    goto v_22746;
v_22747:
    v_23267 = stack[-2];
    goto v_22748;
v_22749:
    goto v_22745;
v_22746:
    goto v_22747;
v_22748:
    {
        fn = elt(env, 7); // multf
        return (*qfn2(fn))(fn, v_23268, v_23267);
    }
v_22742:
    v_23267 = stack[-3];
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    stack[0] = v_23267;
    v_23267 = stack[-2];
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    stack[-1] = v_23267;
    goto v_22768;
v_22764:
    v_23268 = stack[0];
    goto v_22765;
v_22766:
    v_23267 = stack[-1];
    goto v_22767;
v_22768:
    goto v_22764;
v_22765:
    goto v_22766;
v_22767:
    if (v_23268 == v_23267) goto v_22762;
    else goto v_22763;
v_22762:
    goto v_22659;
v_22763:
    goto v_22778;
v_22774:
    v_23268 = stack[0];
    goto v_22775;
v_22776:
    v_23267 = stack[-1];
    goto v_22777;
v_22778:
    goto v_22774;
v_22775:
    goto v_22776;
v_22777:
    fn = elt(env, 8); // ordop
    v_23267 = (*qfn2(fn))(fn, v_23268, v_23267);
    env = stack[-5];
    if (v_23267 == nil) goto v_22772;
    goto v_22658;
v_22772:
    goto v_22786;
v_22782:
    v_23268 = stack[-3];
    goto v_22783;
v_22784:
    v_23267 = stack[-2];
    v_23267 = qcar(v_23267);
    v_23267 = qcdr(v_23267);
    goto v_22785;
v_22786:
    goto v_22782;
v_22783:
    goto v_22784;
v_22785:
    v_23267 = CC_Hmultf(elt(env, 0), v_23268, v_23267);
    env = stack[-5];
    stack[0] = v_23267;
    goto v_22796;
v_22792:
    v_23268 = stack[-3];
    goto v_22793;
v_22794:
    v_23267 = stack[-2];
    v_23267 = qcdr(v_23267);
    goto v_22795;
v_22796:
    goto v_22792;
v_22793:
    goto v_22794;
v_22795:
    v_23267 = CC_Hmultf(elt(env, 0), v_23268, v_23267);
    env = stack[-5];
    stack[-1] = v_23267;
    v_23267 = stack[0];
    if (v_23267 == nil) goto v_22802;
    else goto v_22803;
v_22802:
    v_23267 = stack[-1];
    goto v_22801;
v_22803:
    v_23267 = stack[-2];
    v_23267 = qcar(v_23267);
    v_23267 = qcdr(v_23267);
    if (!consp(v_23267)) goto v_22814;
    else goto v_22815;
v_22814:
    v_23267 = lisp_true;
    goto v_22813;
v_22815:
    v_23267 = stack[-2];
    v_23267 = qcar(v_23267);
    v_23267 = qcdr(v_23267);
    v_23267 = qcar(v_23267);
    v_23267 = (consp(v_23267) ? nil : lisp_true);
    goto v_22813;
    v_23267 = nil;
v_22813:
    if (v_23267 == nil) goto v_22810;
    else goto v_22811;
v_22810:
    goto v_22835;
v_22831:
    v_23267 = stack[-3];
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    v_23268 = qcar(v_23267);
    goto v_22832;
v_22833:
    v_23267 = stack[-2];
    v_23267 = qcar(v_23267);
    v_23267 = qcdr(v_23267);
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    goto v_22834;
v_22835:
    goto v_22831;
v_22832:
    goto v_22833;
v_22834:
    if (v_23268 == v_23267) goto v_22829;
    else goto v_22830;
v_22829:
    v_23267 = stack[-3];
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    if (!consp(v_23267)) goto v_22849;
    goto v_22858;
v_22854:
    v_23267 = stack[-3];
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    v_23268 = qcar(v_23267);
    goto v_22855;
v_22856:
    v_23267 = elt(env, 2); // (expt sqrt)
    goto v_22857;
v_22858:
    goto v_22854;
v_22855:
    goto v_22856;
v_22857:
    v_23267 = Lmemq(nil, v_23268, v_23267);
    goto v_22847;
v_22849:
    v_23267 = nil;
    goto v_22847;
    v_23267 = nil;
v_22847:
    goto v_22828;
v_22830:
    v_23267 = nil;
    goto v_22828;
    v_23267 = nil;
v_22828:
    goto v_22809;
v_22811:
    v_23267 = nil;
    goto v_22809;
    v_23267 = nil;
v_22809:
    if (v_23267 == nil) goto v_22807;
    goto v_22880;
v_22876:
    goto v_22886;
v_22882:
    goto v_22883;
v_22884:
    goto v_22894;
v_22890:
    v_23267 = stack[-2];
    v_23267 = qcar(v_23267);
    v_23268 = qcar(v_23267);
    goto v_22891;
v_22892:
    v_23267 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22893;
v_22894:
    goto v_22890;
v_22891:
    goto v_22892;
v_22893:
    v_23267 = cons(v_23268, v_23267);
    env = stack[-5];
    v_23267 = ncons(v_23267);
    env = stack[-5];
    goto v_22885;
v_22886:
    goto v_22882;
v_22883:
    goto v_22884;
v_22885:
    v_23268 = CC_Hmultf(elt(env, 0), stack[0], v_23267);
    env = stack[-5];
    goto v_22877;
v_22878:
    v_23267 = stack[-1];
    goto v_22879;
v_22880:
    goto v_22876;
v_22877:
    goto v_22878;
v_22879:
    {
        fn = elt(env, 9); // addf
        return (*qfn2(fn))(fn, v_23268, v_23267);
    }
v_22807:
    goto v_22909;
v_22903:
    v_23267 = stack[-2];
    v_23267 = qcar(v_23267);
    v_23269 = qcar(v_23267);
    goto v_22904;
v_22905:
    v_23268 = stack[0];
    goto v_22906;
v_22907:
    v_23267 = stack[-1];
    goto v_22908;
v_22909:
    goto v_22903;
v_22904:
    goto v_22905;
v_22906:
    goto v_22907;
v_22908:
    {
        fn = elt(env, 10); // makeupsf
        return (*qfnn(fn))(fn, 3, v_23269, v_23268, v_23267);
    }
    v_23267 = nil;
v_22801:
    goto v_22657;
v_22658:
    goto v_22920;
v_22916:
    v_23267 = stack[-3];
    v_23267 = qcar(v_23267);
    v_23268 = qcdr(v_23267);
    goto v_22917;
v_22918:
    v_23267 = stack[-2];
    goto v_22919;
v_22920:
    goto v_22916;
v_22917:
    goto v_22918;
v_22919:
    v_23267 = CC_Hmultf(elt(env, 0), v_23268, v_23267);
    env = stack[-5];
    stack[0] = v_23267;
    goto v_22930;
v_22926:
    v_23267 = stack[-3];
    v_23268 = qcdr(v_23267);
    goto v_22927;
v_22928:
    v_23267 = stack[-2];
    goto v_22929;
v_22930:
    goto v_22926;
v_22927:
    goto v_22928;
v_22929:
    v_23267 = CC_Hmultf(elt(env, 0), v_23268, v_23267);
    env = stack[-5];
    stack[-1] = v_23267;
    v_23267 = stack[0];
    if (v_23267 == nil) goto v_22936;
    else goto v_22937;
v_22936:
    v_23267 = stack[-1];
    goto v_22935;
v_22937:
    v_23267 = stack[-3];
    v_23267 = qcar(v_23267);
    v_23267 = qcdr(v_23267);
    if (!consp(v_23267)) goto v_22948;
    else goto v_22949;
v_22948:
    v_23267 = lisp_true;
    goto v_22947;
v_22949:
    v_23267 = stack[-3];
    v_23267 = qcar(v_23267);
    v_23267 = qcdr(v_23267);
    v_23267 = qcar(v_23267);
    v_23267 = (consp(v_23267) ? nil : lisp_true);
    goto v_22947;
    v_23267 = nil;
v_22947:
    if (v_23267 == nil) goto v_22944;
    else goto v_22945;
v_22944:
    goto v_22969;
v_22965:
    v_23267 = stack[-3];
    v_23267 = qcar(v_23267);
    v_23267 = qcdr(v_23267);
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    v_23268 = qcar(v_23267);
    goto v_22966;
v_22967:
    v_23267 = stack[-2];
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    goto v_22968;
v_22969:
    goto v_22965;
v_22966:
    goto v_22967;
v_22968:
    if (v_23268 == v_23267) goto v_22963;
    else goto v_22964;
v_22963:
    v_23267 = stack[-2];
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    if (!consp(v_23267)) goto v_22983;
    goto v_22992;
v_22988:
    v_23267 = stack[-2];
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    v_23268 = qcar(v_23267);
    goto v_22989;
v_22990:
    v_23267 = elt(env, 2); // (expt sqrt)
    goto v_22991;
v_22992:
    goto v_22988;
v_22989:
    goto v_22990;
v_22991:
    v_23267 = Lmemq(nil, v_23268, v_23267);
    goto v_22981;
v_22983:
    v_23267 = nil;
    goto v_22981;
    v_23267 = nil;
v_22981:
    goto v_22962;
v_22964:
    v_23267 = nil;
    goto v_22962;
    v_23267 = nil;
v_22962:
    goto v_22943;
v_22945:
    v_23267 = nil;
    goto v_22943;
    v_23267 = nil;
v_22943:
    if (v_23267 == nil) goto v_22941;
    goto v_23014;
v_23010:
    goto v_23020;
v_23016:
    goto v_23027;
v_23023:
    v_23267 = stack[-3];
    v_23267 = qcar(v_23267);
    v_23268 = qcar(v_23267);
    goto v_23024;
v_23025:
    v_23267 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23026;
v_23027:
    goto v_23023;
v_23024:
    goto v_23025;
v_23026:
    v_23267 = cons(v_23268, v_23267);
    env = stack[-5];
    v_23268 = ncons(v_23267);
    env = stack[-5];
    goto v_23017;
v_23018:
    v_23267 = stack[0];
    goto v_23019;
v_23020:
    goto v_23016;
v_23017:
    goto v_23018;
v_23019:
    v_23268 = CC_Hmultf(elt(env, 0), v_23268, v_23267);
    env = stack[-5];
    goto v_23011;
v_23012:
    v_23267 = stack[-1];
    goto v_23013;
v_23014:
    goto v_23010;
v_23011:
    goto v_23012;
v_23013:
    {
        fn = elt(env, 9); // addf
        return (*qfn2(fn))(fn, v_23268, v_23267);
    }
v_22941:
    goto v_23043;
v_23037:
    v_23267 = stack[-3];
    v_23267 = qcar(v_23267);
    v_23269 = qcar(v_23267);
    goto v_23038;
v_23039:
    v_23268 = stack[0];
    goto v_23040;
v_23041:
    v_23267 = stack[-1];
    goto v_23042;
v_23043:
    goto v_23037;
v_23038:
    goto v_23039;
v_23040:
    goto v_23041;
v_23042:
    {
        fn = elt(env, 10); // makeupsf
        return (*qfnn(fn))(fn, 3, v_23269, v_23268, v_23267);
    }
    v_23267 = nil;
v_22935:
    goto v_22657;
v_22659:
    goto v_23054;
v_23050:
    goto v_23060;
v_23056:
    v_23267 = stack[-3];
    v_23267 = qcar(v_23267);
    v_23268 = ncons(v_23267);
    env = stack[-5];
    goto v_23057;
v_23058:
    v_23267 = stack[-2];
    v_23267 = qcdr(v_23267);
    goto v_23059;
v_23060:
    goto v_23056;
v_23057:
    goto v_23058;
v_23059:
    stack[-1] = CC_Hmultf(elt(env, 0), v_23268, v_23267);
    env = stack[-5];
    goto v_23051;
v_23052:
    goto v_23071;
v_23067:
    v_23267 = stack[-3];
    v_23268 = qcdr(v_23267);
    goto v_23068;
v_23069:
    v_23267 = stack[-2];
    goto v_23070;
v_23071:
    goto v_23067;
v_23068:
    goto v_23069;
v_23070:
    v_23267 = CC_Hmultf(elt(env, 0), v_23268, v_23267);
    env = stack[-5];
    goto v_23053;
v_23054:
    goto v_23050;
v_23051:
    goto v_23052;
v_23053:
    fn = elt(env, 9); // addf
    v_23267 = (*qfn2(fn))(fn, stack[-1], v_23267);
    env = stack[-5];
    stack[-1] = v_23267;
    goto v_23084;
v_23080:
    v_23268 = stack[0];
    goto v_23081;
v_23082:
    v_23267 = elt(env, 3); // sqrt
    goto v_23083;
v_23084:
    goto v_23080;
v_23081:
    goto v_23082;
v_23083:
    if (!consp(v_23268)) goto v_23078;
    v_23268 = qcar(v_23268);
    if (v_23268 == v_23267) goto v_23077;
    else goto v_23078;
v_23077:
    goto v_23092;
v_23088:
    v_23267 = stack[-1];
    fn = elt(env, 5); // squashsqrt
    stack[-4] = (*qfn1(fn))(fn, v_23267);
    env = stack[-5];
    goto v_23089;
v_23090:
    goto v_23102;
v_23096:
    stack[-1] = stack[0];
    goto v_23097;
v_23098:
    goto v_23109;
v_23105:
    v_23267 = stack[-3];
    v_23267 = qcar(v_23267);
    v_23268 = qcdr(v_23267);
    goto v_23106;
v_23107:
    v_23267 = stack[-2];
    v_23267 = qcar(v_23267);
    v_23267 = qcdr(v_23267);
    goto v_23108;
v_23109:
    goto v_23105;
v_23106:
    goto v_23107;
v_23108:
    stack[0] = CC_Hmultf(elt(env, 0), v_23268, v_23267);
    env = stack[-5];
    goto v_23099;
v_23100:
    goto v_23121;
v_23117:
    v_23267 = stack[-3];
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    v_23268 = qcdr(v_23267);
    goto v_23118;
v_23119:
    v_23267 = stack[-2];
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    v_23267 = qcdr(v_23267);
    goto v_23120;
v_23121:
    goto v_23117;
v_23118:
    goto v_23119;
v_23120:
    v_23267 = plus2(v_23268, v_23267);
    env = stack[-5];
    goto v_23101;
v_23102:
    goto v_23096;
v_23097:
    goto v_23098;
v_23099:
    goto v_23100;
v_23101:
    fn = elt(env, 11); // !*multfsqrt
    v_23267 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_23267);
    env = stack[-5];
    goto v_23091;
v_23092:
    goto v_23088;
v_23089:
    goto v_23090;
v_23091:
    {
        LispObject v_23277 = stack[-4];
        fn = elt(env, 9); // addf
        return (*qfn2(fn))(fn, v_23277, v_23267);
    }
v_23078:
    goto v_23141;
v_23137:
    v_23268 = stack[0];
    goto v_23138;
v_23139:
    v_23267 = elt(env, 4); // expt
    goto v_23140;
v_23141:
    goto v_23137;
v_23138:
    goto v_23139;
v_23140:
    if (!consp(v_23268)) goto v_23135;
    v_23268 = qcar(v_23268);
    if (v_23268 == v_23267) goto v_23134;
    else goto v_23135;
v_23134:
    v_23267 = stack[0];
    v_23267 = qcdr(v_23267);
    v_23267 = qcdr(v_23267);
    v_23267 = qcar(v_23267);
    fn = elt(env, 12); // prefix!-rational!-numberp
    v_23267 = (*qfn1(fn))(fn, v_23267);
    env = stack[-5];
    goto v_23133;
v_23135:
    v_23267 = nil;
    goto v_23133;
    v_23267 = nil;
v_23133:
    if (v_23267 == nil) goto v_23131;
    goto v_23157;
v_23153:
    v_23267 = stack[-1];
    fn = elt(env, 5); // squashsqrt
    stack[-4] = (*qfn1(fn))(fn, v_23267);
    env = stack[-5];
    goto v_23154;
v_23155:
    goto v_23167;
v_23161:
    stack[-1] = stack[0];
    goto v_23162;
v_23163:
    goto v_23174;
v_23170:
    v_23267 = stack[-3];
    v_23267 = qcar(v_23267);
    v_23268 = qcdr(v_23267);
    goto v_23171;
v_23172:
    v_23267 = stack[-2];
    v_23267 = qcar(v_23267);
    v_23267 = qcdr(v_23267);
    goto v_23173;
v_23174:
    goto v_23170;
v_23171:
    goto v_23172;
v_23173:
    stack[0] = CC_Hmultf(elt(env, 0), v_23268, v_23267);
    env = stack[-5];
    goto v_23164;
v_23165:
    goto v_23186;
v_23182:
    v_23267 = stack[-3];
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    v_23268 = qcdr(v_23267);
    goto v_23183;
v_23184:
    v_23267 = stack[-2];
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    v_23267 = qcdr(v_23267);
    goto v_23185;
v_23186:
    goto v_23182;
v_23183:
    goto v_23184;
v_23185:
    v_23267 = plus2(v_23268, v_23267);
    env = stack[-5];
    goto v_23166;
v_23167:
    goto v_23161;
v_23162:
    goto v_23163;
v_23164:
    goto v_23165;
v_23166:
    fn = elt(env, 13); // !*multfexpt
    v_23267 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_23267);
    env = stack[-5];
    goto v_23156;
v_23157:
    goto v_23153;
v_23154:
    goto v_23155;
v_23156:
    {
        LispObject v_23278 = stack[-4];
        fn = elt(env, 9); // addf
        return (*qfn2(fn))(fn, v_23278, v_23267);
    }
v_23131:
    goto v_23200;
v_23196:
    goto v_23197;
v_23198:
    goto v_23207;
v_23203:
    v_23267 = stack[-3];
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    v_23268 = qcdr(v_23267);
    goto v_23204;
v_23205:
    v_23267 = stack[-2];
    v_23267 = qcar(v_23267);
    v_23267 = qcar(v_23267);
    v_23267 = qcdr(v_23267);
    goto v_23206;
v_23207:
    goto v_23203;
v_23204:
    goto v_23205;
v_23206:
    v_23267 = plus2(v_23268, v_23267);
    env = stack[-5];
    goto v_23199;
v_23200:
    goto v_23196;
v_23197:
    goto v_23198;
v_23199:
    fn = elt(env, 14); // mkspm
    v_23267 = (*qfn2(fn))(fn, stack[0], v_23267);
    env = stack[-5];
    stack[0] = v_23267;
    v_23267 = stack[0];
    if (v_23267 == nil) goto v_23222;
    else goto v_23223;
v_23222:
    v_23267 = lisp_true;
    goto v_23221;
v_23223:
    goto v_23233;
v_23229:
    v_23267 = stack[-3];
    v_23267 = qcar(v_23267);
    v_23268 = qcdr(v_23267);
    goto v_23230;
v_23231:
    v_23267 = stack[-2];
    v_23267 = qcar(v_23267);
    v_23267 = qcdr(v_23267);
    goto v_23232;
v_23233:
    goto v_23229;
v_23230:
    goto v_23231;
v_23232:
    v_23267 = CC_Hmultf(elt(env, 0), v_23268, v_23267);
    env = stack[-5];
    stack[-3] = v_23267;
    v_23267 = (v_23267 == nil ? lisp_true : nil);
    goto v_23221;
    v_23267 = nil;
v_23221:
    if (v_23267 == nil) goto v_23219;
    v_23267 = stack[-1];
    goto v_23217;
v_23219:
    goto v_23249;
v_23245:
    goto v_23255;
v_23251:
    goto v_23262;
v_23258:
    v_23268 = stack[0];
    goto v_23259;
v_23260:
    v_23267 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23261;
v_23262:
    goto v_23258;
v_23259:
    goto v_23260;
v_23261:
    v_23267 = cons(v_23268, v_23267);
    env = stack[-5];
    v_23268 = ncons(v_23267);
    env = stack[-5];
    goto v_23252;
v_23253:
    v_23267 = stack[-3];
    goto v_23254;
v_23255:
    goto v_23251;
v_23252:
    goto v_23253;
v_23254:
    fn = elt(env, 7); // multf
    v_23268 = (*qfn2(fn))(fn, v_23268, v_23267);
    env = stack[-5];
    goto v_23246;
v_23247:
    v_23267 = stack[-1];
    goto v_23248;
v_23249:
    goto v_23245;
v_23246:
    goto v_23247;
v_23248:
    {
        fn = elt(env, 9); // addf
        return (*qfn2(fn))(fn, v_23268, v_23267);
    }
    v_23267 = nil;
v_23217:
v_22657:
    return onevalue(v_23267);
}



// Code for oddext

static LispObject CC_oddext(LispObject env,
                         LispObject v_22652)
{
    env = qenv(env);
    LispObject v_22721, v_22722;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22652);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22652);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_22721 = v_22652;
// end of prologue
// Binding odd_var
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = v_22721; // odd_var
    goto v_22666;
v_22662:
    v_22722 = qvalue(elt(env, 1)); // odd_var
    goto v_22663;
v_22664:
    v_22721 = qvalue(elt(env, 2)); // all_parametric_odd!*
    goto v_22665;
v_22666:
    goto v_22662;
v_22663:
    goto v_22664;
v_22665:
    v_22721 = Lmember(nil, v_22722, v_22721);
    if (v_22721 == nil) goto v_22661;
    goto v_22675;
v_22671:
    stack[0] = elt(env, 3); // ext
    goto v_22672;
v_22673:
    goto v_22682;
v_22678:
    v_22722 = qvalue(elt(env, 1)); // odd_var
    goto v_22679;
v_22680:
    v_22721 = qvalue(elt(env, 2)); // all_parametric_odd!*
    goto v_22681;
v_22682:
    goto v_22678;
v_22679:
    goto v_22680;
v_22681:
    fn = elt(env, 7); // cde_position
    v_22721 = (*qfn2(fn))(fn, v_22722, v_22721);
    env = stack[-3];
    goto v_22674;
v_22675:
    goto v_22671;
v_22672:
    goto v_22673;
v_22674:
    v_22721 = list2(stack[0], v_22721);
    goto v_22659;
v_22661:
    goto v_22691;
v_22687:
    v_22722 = qvalue(elt(env, 1)); // odd_var
    goto v_22688;
v_22689:
    v_22721 = qvalue(elt(env, 4)); // all_principal_odd!*
    goto v_22690;
v_22691:
    goto v_22687;
v_22688:
    goto v_22689;
v_22690:
    v_22721 = Lmember(nil, v_22722, v_22721);
    if (v_22721 == nil) goto v_22686;
    goto v_22700;
v_22696:
    stack[-1] = elt(env, 3); // ext
    goto v_22697;
v_22698:
    goto v_22707;
v_22703:
    stack[0] = qvalue(elt(env, 5)); // n_all_parametric_ext
    goto v_22704;
v_22705:
    goto v_22714;
v_22710:
    v_22722 = qvalue(elt(env, 1)); // odd_var
    goto v_22711;
v_22712:
    v_22721 = qvalue(elt(env, 4)); // all_principal_odd!*
    goto v_22713;
v_22714:
    goto v_22710;
v_22711:
    goto v_22712;
v_22713:
    fn = elt(env, 7); // cde_position
    v_22721 = (*qfn2(fn))(fn, v_22722, v_22721);
    env = stack[-3];
    goto v_22706;
v_22707:
    goto v_22703;
v_22704:
    goto v_22705;
v_22706:
    v_22721 = plus2(stack[0], v_22721);
    env = stack[-3];
    goto v_22699;
v_22700:
    goto v_22696;
v_22697:
    goto v_22698;
v_22699:
    v_22721 = list2(stack[-1], v_22721);
    goto v_22659;
v_22686:
    v_22721 = elt(env, 6); // "the argument of oddext must be an odd variable"
    fn = elt(env, 8); // rederr
    v_22721 = (*qfn1(fn))(fn, v_22721);
    goto v_22659;
    v_22721 = nil;
v_22659:
    ;}  // end of a binding scope
    return onevalue(v_22721);
}



// Code for ra_intequiv0

static LispObject CC_ra_intequiv0(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22810, v_22811, v_22812, v_22813;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_22651;
// end of prologue
    v_22810 = stack[-3];
    fn = elt(env, 2); // ra_zerop
    v_22810 = (*qfn1(fn))(fn, v_22810);
    env = stack[-5];
    if (v_22810 == nil) goto v_22662;
    v_22810 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22658;
v_22662:
    v_22810 = stack[-3];
    fn = elt(env, 3); // ra_f
    v_22810 = (*qfn1(fn))(fn, v_22810);
    env = stack[-5];
    stack[-4] = v_22810;
    goto v_22678;
v_22674:
    v_22810 = stack[-4];
    v_22810 = qcar(v_22810);
    v_22810 = qcar(v_22810);
    v_22811 = qcdr(v_22810);
    goto v_22675;
v_22676:
    v_22810 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22677;
v_22678:
    goto v_22674;
v_22675:
    goto v_22676;
v_22677:
    v_22810 = Leqn(nil, v_22811, v_22810);
    env = stack[-5];
    if (v_22810 == nil) goto v_22671;
    goto v_22690;
v_22686:
    v_22810 = stack[-4];
    v_22810 = qcar(v_22810);
    v_22811 = qcdr(v_22810);
    goto v_22687;
v_22688:
    v_22810 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22689;
v_22690:
    goto v_22686;
v_22687:
    goto v_22688;
v_22689:
    v_22810 = Leqn(nil, v_22811, v_22810);
    env = stack[-5];
    if (v_22810 == nil) goto v_22671;
    v_22810 = stack[-4];
    v_22810 = qcdr(v_22810);
    {
        fn = elt(env, 4); // negf
        return (*qfn1(fn))(fn, v_22810);
    }
v_22671:
    v_22810 = stack[-3];
    fn = elt(env, 5); // ra_iv
    v_22810 = (*qfn1(fn))(fn, v_22810);
    env = stack[-5];
    fn = elt(env, 6); // riv_l
    v_22810 = (*qfn1(fn))(fn, v_22810);
    env = stack[-5];
    stack[-2] = v_22810;
    v_22810 = stack[-3];
    fn = elt(env, 5); // ra_iv
    v_22810 = (*qfn1(fn))(fn, v_22810);
    env = stack[-5];
    fn = elt(env, 7); // riv_u
    v_22810 = (*qfn1(fn))(fn, v_22810);
    env = stack[-5];
    stack[-1] = v_22810;
v_22706:
    goto v_22716;
v_22712:
    goto v_22722;
v_22718:
    stack[0] = stack[-1];
    goto v_22719;
v_22720:
    v_22810 = stack[-2];
    fn = elt(env, 8); // negsq
    v_22810 = (*qfn1(fn))(fn, v_22810);
    env = stack[-5];
    goto v_22721;
v_22722:
    goto v_22718;
v_22719:
    goto v_22720;
v_22721:
    fn = elt(env, 9); // addsq
    stack[0] = (*qfn2(fn))(fn, stack[0], v_22810);
    env = stack[-5];
    goto v_22713;
v_22714:
    goto v_22731;
v_22727:
    v_22811 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22728;
v_22729:
    v_22810 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22730;
v_22731:
    goto v_22727;
v_22728:
    goto v_22729;
v_22730:
    v_22810 = cons(v_22811, v_22810);
    env = stack[-5];
    goto v_22715;
v_22716:
    goto v_22712;
v_22713:
    goto v_22714;
v_22715:
    fn = elt(env, 10); // sfto_greaterq
    v_22810 = (*qfn2(fn))(fn, stack[0], v_22810);
    env = stack[-5];
    if (v_22810 == nil) goto v_22709;
    else goto v_22710;
v_22709:
    goto v_22705;
v_22710:
    goto v_22747;
v_22739:
    v_22813 = stack[-4];
    goto v_22740;
v_22741:
    v_22812 = stack[-2];
    goto v_22742;
v_22743:
    v_22811 = stack[-1];
    goto v_22744;
v_22745:
    v_22810 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22746;
v_22747:
    goto v_22739;
v_22740:
    goto v_22741;
v_22742:
    goto v_22743;
v_22744:
    goto v_22745;
v_22746:
    fn = elt(env, 11); // ra_refine1
    v_22810 = (*qfnn(fn))(fn, 4, v_22813, v_22812, v_22811, v_22810);
    env = stack[-5];
    v_22811 = v_22810;
    v_22810 = v_22811;
    v_22810 = qcar(v_22810);
    stack[-2] = v_22810;
    v_22810 = v_22811;
    v_22810 = qcdr(v_22810);
    stack[-1] = v_22810;
    goto v_22706;
v_22705:
    goto v_22762;
v_22758:
    v_22810 = stack[-2];
    fn = elt(env, 12); // sfto_floorq
    v_22810 = (*qfn1(fn))(fn, v_22810);
    env = stack[-5];
    v_22811 = qcar(v_22810);
    goto v_22759;
v_22760:
    v_22810 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22761;
v_22762:
    goto v_22758;
v_22759:
    goto v_22760;
v_22761:
    fn = elt(env, 13); // addf
    v_22810 = (*qfn2(fn))(fn, v_22811, v_22810);
    env = stack[-5];
    stack[0] = v_22810;
    goto v_22777;
v_22773:
    goto v_22783;
v_22779:
    v_22811 = stack[0];
    goto v_22780;
v_22781:
    v_22810 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22782;
v_22783:
    goto v_22779;
v_22780:
    goto v_22781;
v_22782:
    v_22811 = cons(v_22811, v_22810);
    env = stack[-5];
    goto v_22774;
v_22775:
    v_22810 = stack[-1];
    goto v_22776;
v_22777:
    goto v_22773;
v_22774:
    goto v_22775;
v_22776:
    fn = elt(env, 14); // sfto_lessq
    v_22810 = (*qfn2(fn))(fn, v_22811, v_22810);
    env = stack[-5];
    if (v_22810 == nil) goto v_22770;
    goto v_22793;
v_22789:
    stack[-1] = stack[-4];
    goto v_22790;
v_22791:
    goto v_22801;
v_22797:
    v_22811 = elt(env, 1); // x
    goto v_22798;
v_22799:
    v_22810 = stack[0];
    goto v_22800;
v_22801:
    goto v_22797;
v_22798:
    goto v_22799;
v_22800:
    v_22810 = cons(v_22811, v_22810);
    env = stack[-5];
    v_22810 = ncons(v_22810);
    env = stack[-5];
    goto v_22792;
v_22793:
    goto v_22789;
v_22790:
    goto v_22791;
v_22792:
    fn = elt(env, 15); // sfto_fsub1
    v_22810 = (*qfn2(fn))(fn, stack[-1], v_22810);
    if (v_22810 == nil) goto v_22787;
    else goto v_22770;
v_22787:
    v_22810 = stack[0];
    if (v_22810 == nil) goto v_22806;
    else goto v_22805;
v_22806:
    v_22810 = (LispObject)0+TAG_FIXNUM; // 0
v_22805:
    goto v_22658;
v_22770:
    v_22810 = stack[-3];
v_22658:
    return onevalue(v_22810);
}



// Code for lalr_collect_nonterminals

static LispObject CC_lalr_collect_nonterminals(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22698;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_22698 = v_22651;
// end of prologue
    stack[-3] = v_22698;
    v_22698 = stack[-3];
    if (v_22698 == nil) goto v_22663;
    else goto v_22664;
v_22663:
    v_22698 = nil;
    goto v_22658;
v_22664:
    v_22698 = stack[-3];
    v_22698 = qcar(v_22698);
    v_22698 = qcar(v_22698);
    v_22698 = Lintern(nil, v_22698);
    env = stack[-4];
    v_22698 = ncons(v_22698);
    env = stack[-4];
    stack[-1] = v_22698;
    stack[-2] = v_22698;
v_22659:
    v_22698 = stack[-3];
    v_22698 = qcdr(v_22698);
    stack[-3] = v_22698;
    v_22698 = stack[-3];
    if (v_22698 == nil) goto v_22678;
    else goto v_22679;
v_22678:
    v_22698 = stack[-2];
    goto v_22658;
v_22679:
    goto v_22687;
v_22683:
    stack[0] = stack[-1];
    goto v_22684;
v_22685:
    v_22698 = stack[-3];
    v_22698 = qcar(v_22698);
    v_22698 = qcar(v_22698);
    v_22698 = Lintern(nil, v_22698);
    env = stack[-4];
    v_22698 = ncons(v_22698);
    env = stack[-4];
    goto v_22686;
v_22687:
    goto v_22683;
v_22684:
    goto v_22685;
v_22686:
    v_22698 = Lrplacd(nil, stack[0], v_22698);
    env = stack[-4];
    v_22698 = stack[-1];
    v_22698 = qcdr(v_22698);
    stack[-1] = v_22698;
    goto v_22659;
v_22658:
    {
        fn = elt(env, 1); // lalr_remove_duplicates
        return (*qfn1(fn))(fn, v_22698);
    }
}



// Code for createsinglevariablemonom

static LispObject CC_createsinglevariablemonom(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22689, v_22690, v_22691;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_22651;
// end of prologue
    v_22689 = (LispObject)16+TAG_FIXNUM; // 1
    v_22689 = Lmkvect(nil, v_22689);
    env = stack[-4];
    stack[-3] = v_22689;
    goto v_22664;
v_22658:
    v_22691 = stack[-3];
    goto v_22659;
v_22660:
    v_22690 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22661;
v_22662:
    v_22689 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22663;
v_22664:
    goto v_22658;
v_22659:
    goto v_22660;
v_22661:
    goto v_22662;
v_22663:
    *(LispObject *)((char *)v_22691 + (CELL-TAG_VECTOR) + (((intptr_t)v_22690-TAG_FIXNUM)/(16/CELL))) = v_22689;
    goto v_22674;
v_22668:
    stack[-1] = stack[-3];
    goto v_22669;
v_22670:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22671;
v_22672:
    goto v_22684;
v_22678:
    v_22691 = stack[-2];
    goto v_22679;
v_22680:
    v_22690 = nil;
    goto v_22681;
v_22682:
    v_22689 = nil;
    goto v_22683;
v_22684:
    goto v_22678;
v_22679:
    goto v_22680;
v_22681:
    goto v_22682;
v_22683:
    v_22689 = list2star(v_22691, v_22690, v_22689);
    goto v_22673;
v_22674:
    goto v_22668;
v_22669:
    goto v_22670;
v_22671:
    goto v_22672;
v_22673:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_22689;
    v_22689 = stack[-3];
    return onevalue(v_22689);
}



// Code for cl_pnf1

static LispObject CC_cl_pnf1(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22690;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_22690 = v_22651;
// end of prologue
    fn = elt(env, 1); // cl_rename!-vars
    v_22690 = (*qfn1(fn))(fn, v_22690);
    env = stack[-2];
    fn = elt(env, 2); // cl_pnf2
    v_22690 = (*qfn1(fn))(fn, v_22690);
    env = stack[-2];
    stack[-1] = v_22690;
    v_22690 = stack[-1];
    v_22690 = qcdr(v_22690);
    if (v_22690 == nil) goto v_22663;
    else goto v_22664;
v_22663:
    v_22690 = lisp_true;
    goto v_22662;
v_22664:
    goto v_22675;
v_22671:
    v_22690 = stack[-1];
    v_22690 = qcar(v_22690);
    fn = elt(env, 3); // cl_qb
    stack[0] = (*qfn1(fn))(fn, v_22690);
    env = stack[-2];
    goto v_22672;
v_22673:
    v_22690 = stack[-1];
    v_22690 = qcdr(v_22690);
    v_22690 = qcar(v_22690);
    fn = elt(env, 3); // cl_qb
    v_22690 = (*qfn1(fn))(fn, v_22690);
    env = stack[-2];
    goto v_22674;
v_22675:
    goto v_22671;
v_22672:
    goto v_22673;
v_22674:
    v_22690 = (LispObject)lessp2(stack[0], v_22690);
    v_22690 = v_22690 ? lisp_true : nil;
    goto v_22662;
    v_22690 = nil;
v_22662:
    if (v_22690 == nil) goto v_22660;
    v_22690 = stack[-1];
    v_22690 = qcar(v_22690);
    goto v_22658;
v_22660:
    v_22690 = stack[-1];
    v_22690 = qcdr(v_22690);
    v_22690 = qcar(v_22690);
    goto v_22658;
    v_22690 = nil;
v_22658:
    return onevalue(v_22690);
}



// Code for pasf_smordtable

static LispObject CC_pasf_smordtable(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22699, v_22700;
    LispObject fn;
    LispObject v_22654, v_22653, v_22652, v_22651;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "pasf_smordtable");
    va_start(aa, nargs);
    v_22651 = va_arg(aa, LispObject);
    v_22652 = va_arg(aa, LispObject);
    v_22653 = va_arg(aa, LispObject);
    v_22654 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_22654,v_22653,v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_22651,v_22652,v_22653,v_22654);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_22654;
    stack[-1] = v_22653;
    stack[-2] = v_22652;
    stack[-3] = v_22651;
// end of prologue
    goto v_22665;
v_22661:
    v_22700 = stack[-1];
    goto v_22662;
v_22663:
    v_22699 = stack[0];
    goto v_22664;
v_22665:
    goto v_22661;
v_22662:
    goto v_22663;
v_22664:
    v_22699 = (LispObject)lessp2(v_22700, v_22699);
    v_22699 = v_22699 ? lisp_true : nil;
    env = stack[-4];
    if (v_22699 == nil) goto v_22659;
    goto v_22673;
v_22669:
    v_22700 = stack[-3];
    goto v_22670;
v_22671:
    v_22699 = stack[-2];
    goto v_22672;
v_22673:
    goto v_22669;
v_22670:
    goto v_22671;
v_22672:
    {
        fn = elt(env, 2); // pasf_smordtable2
        return (*qfn2(fn))(fn, v_22700, v_22699);
    }
v_22659:
    goto v_22683;
v_22679:
    v_22700 = stack[-1];
    goto v_22680;
v_22681:
    v_22699 = stack[0];
    goto v_22682;
v_22683:
    goto v_22679;
v_22680:
    goto v_22681;
v_22682:
    v_22699 = (LispObject)greaterp2(v_22700, v_22699);
    v_22699 = v_22699 ? lisp_true : nil;
    env = stack[-4];
    if (v_22699 == nil) goto v_22677;
    goto v_22691;
v_22687:
    v_22700 = stack[-3];
    goto v_22688;
v_22689:
    v_22699 = stack[-2];
    goto v_22690;
v_22691:
    goto v_22687;
v_22688:
    goto v_22689;
v_22690:
    {
        fn = elt(env, 3); // pasf_smordtable1
        return (*qfn2(fn))(fn, v_22700, v_22699);
    }
v_22677:
    v_22699 = elt(env, 1); // "abused smordtable"
    v_22699 = ncons(v_22699);
    env = stack[-4];
    {
        fn = elt(env, 4); // rederr
        return (*qfn1(fn))(fn, v_22699);
    }
    v_22699 = nil;
    return onevalue(v_22699);
}



// Code for ofsf_updsignvar

static LispObject CC_ofsf_updsignvar(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22730, v_22731, v_22732, v_22733, v_22734, v_22735, v_22736, v_22737;
    LispObject v_22657, v_22656, v_22655, v_22654, v_22653, v_22652, v_22651;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 7, "ofsf_updsignvar");
    va_start(aa, nargs);
    v_22651 = va_arg(aa, LispObject);
    v_22652 = va_arg(aa, LispObject);
    v_22653 = va_arg(aa, LispObject);
    v_22654 = va_arg(aa, LispObject);
    v_22655 = va_arg(aa, LispObject);
    v_22656 = va_arg(aa, LispObject);
    v_22657 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22732 = v_22657;
    v_22733 = v_22656;
    v_22734 = v_22655;
    v_22735 = v_22654;
    v_22736 = v_22653;
    v_22730 = v_22652;
    v_22737 = v_22651;
// end of prologue
    goto v_22667;
v_22663:
    v_22731 = v_22737;
    goto v_22664;
v_22665:
    goto v_22666;
v_22667:
    goto v_22663;
v_22664:
    goto v_22665;
v_22666:
    v_22730 = Lmemq(nil, v_22731, v_22730);
    if (v_22730 == nil) goto v_22662;
    v_22730 = elt(env, 1); // equal
    goto v_22660;
v_22662:
    goto v_22678;
v_22674:
    v_22730 = v_22737;
    goto v_22675;
v_22676:
    v_22731 = v_22736;
    goto v_22677;
v_22678:
    goto v_22674;
v_22675:
    goto v_22676;
v_22677:
    v_22730 = Lmemq(nil, v_22730, v_22731);
    if (v_22730 == nil) goto v_22673;
    v_22730 = elt(env, 2); // greaterp
    goto v_22660;
v_22673:
    goto v_22689;
v_22685:
    v_22730 = v_22737;
    goto v_22686;
v_22687:
    v_22731 = v_22735;
    goto v_22688;
v_22689:
    goto v_22685;
v_22686:
    goto v_22687;
v_22688:
    v_22730 = Lmemq(nil, v_22730, v_22731);
    if (v_22730 == nil) goto v_22684;
    v_22730 = elt(env, 3); // lessp
    goto v_22660;
v_22684:
    goto v_22700;
v_22696:
    v_22730 = v_22737;
    goto v_22697;
v_22698:
    v_22731 = v_22734;
    goto v_22699;
v_22700:
    goto v_22696;
v_22697:
    goto v_22698;
v_22699:
    v_22730 = Lmemq(nil, v_22730, v_22731);
    if (v_22730 == nil) goto v_22695;
    v_22730 = elt(env, 4); // geq
    goto v_22660;
v_22695:
    goto v_22711;
v_22707:
    v_22730 = v_22737;
    goto v_22708;
v_22709:
    v_22731 = v_22733;
    goto v_22710;
v_22711:
    goto v_22707;
v_22708:
    goto v_22709;
v_22710:
    v_22730 = Lmemq(nil, v_22730, v_22731);
    if (v_22730 == nil) goto v_22706;
    v_22730 = elt(env, 5); // leq
    goto v_22660;
v_22706:
    goto v_22722;
v_22718:
    v_22730 = v_22737;
    goto v_22719;
v_22720:
    v_22731 = v_22732;
    goto v_22721;
v_22722:
    goto v_22718;
v_22719:
    goto v_22720;
v_22721:
    v_22730 = Lmemq(nil, v_22730, v_22731);
    if (v_22730 == nil) goto v_22717;
    v_22730 = elt(env, 6); // neq
    goto v_22660;
v_22717:
    v_22730 = elt(env, 7); // unknown
    goto v_22660;
    v_22730 = nil;
v_22660:
    return onevalue(v_22730);
}



// Code for make!-modular!-symmetric

static LispObject CC_makeKmodularKsymmetric(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22728, v_22729, v_22730;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22651;
// end of prologue
    v_22728 = stack[0];
    if (v_22728 == nil) goto v_22655;
    else goto v_22656;
v_22655:
    v_22728 = nil;
    goto v_22654;
v_22656:
    v_22728 = stack[0];
    if (!consp(v_22728)) goto v_22663;
    else goto v_22664;
v_22663:
    v_22728 = lisp_true;
    goto v_22662;
v_22664:
    v_22728 = stack[0];
    v_22728 = qcar(v_22728);
    v_22728 = (consp(v_22728) ? nil : lisp_true);
    goto v_22662;
    v_22728 = nil;
v_22662:
    if (v_22728 == nil) goto v_22660;
    goto v_22681;
v_22677:
    v_22729 = stack[0];
    goto v_22678;
v_22679:
    v_22728 = qvalue(elt(env, 1)); // modulus!/2
    goto v_22680;
v_22681:
    goto v_22677;
v_22678:
    goto v_22679;
v_22680:
    v_22728 = (LispObject)greaterp2(v_22729, v_22728);
    v_22728 = v_22728 ? lisp_true : nil;
    env = stack[-2];
    if (v_22728 == nil) goto v_22675;
    goto v_22690;
v_22686:
    v_22729 = stack[0];
    goto v_22687;
v_22688:
    v_22728 = qvalue(elt(env, 2)); // current!-modulus
    goto v_22689;
v_22690:
    goto v_22686;
v_22687:
    goto v_22688;
v_22689:
    v_22728 = difference2(v_22729, v_22728);
    env = stack[-2];
    {
        fn = elt(env, 3); // !*n2f
        return (*qfn1(fn))(fn, v_22728);
    }
v_22675:
    v_22728 = stack[0];
    goto v_22673;
    v_22728 = nil;
v_22673:
    goto v_22654;
v_22660:
    v_22728 = stack[0];
    v_22728 = qcar(v_22728);
    v_22728 = qcdr(v_22728);
    stack[-1] = CC_makeKmodularKsymmetric(elt(env, 0), v_22728);
    env = stack[-2];
    v_22728 = stack[0];
    v_22728 = qcdr(v_22728);
    v_22728 = CC_makeKmodularKsymmetric(elt(env, 0), v_22728);
    v_22729 = stack[-1];
    v_22730 = v_22729;
    if (v_22730 == nil) goto v_22709;
    else goto v_22710;
v_22709:
    goto v_22708;
v_22710:
    goto v_22722;
v_22716:
    v_22730 = stack[0];
    v_22730 = qcar(v_22730);
    v_22730 = qcar(v_22730);
    goto v_22717;
v_22718:
    goto v_22719;
v_22720:
    goto v_22721;
v_22722:
    goto v_22716;
v_22717:
    goto v_22718;
v_22719:
    goto v_22720;
v_22721:
    return acons(v_22730, v_22729, v_22728);
    v_22728 = nil;
v_22708:
    goto v_22654;
    v_22728 = nil;
v_22654:
    return onevalue(v_22728);
}



// Code for lowupperlimitrd

static LispObject CC_lowupperlimitrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22692, v_22693;
    LispObject fn;
    argcheck(nargs, 0, "lowupperlimitrd");
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
    stack[-2] = nil;
    fn = elt(env, 5); // mathml
    v_22692 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[0] = v_22692;
    fn = elt(env, 6); // lex
    v_22692 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_22666;
v_22662:
    v_22693 = qvalue(elt(env, 1)); // char
    goto v_22663;
v_22664:
    v_22692 = elt(env, 2); // (!/ l o w l i m i t)
    goto v_22665;
v_22666:
    goto v_22662;
v_22663:
    goto v_22664;
v_22665:
    if (equal(v_22693, v_22692)) goto v_22660;
    else goto v_22661;
v_22660:
    fn = elt(env, 7); // upperlimitrd
    v_22692 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-2] = v_22692;
    goto v_22659;
v_22661:
    goto v_22677;
v_22673:
    v_22693 = elt(env, 3); // "</lowlimit>"
    goto v_22674;
v_22675:
    v_22692 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_22676;
v_22677:
    goto v_22673;
v_22674:
    goto v_22675;
v_22676:
    fn = elt(env, 8); // errorml
    v_22692 = (*qfn2(fn))(fn, v_22693, v_22692);
    env = stack[-3];
    goto v_22659;
v_22659:
    goto v_22687;
v_22681:
    stack[-1] = elt(env, 4); // lowupperlimit
    goto v_22682;
v_22683:
    goto v_22684;
v_22685:
    v_22692 = stack[-2];
    v_22692 = ncons(v_22692);
    goto v_22686;
v_22687:
    goto v_22681;
v_22682:
    goto v_22683;
v_22684:
    goto v_22685;
v_22686:
    {
        LispObject v_22697 = stack[-1];
        LispObject v_22698 = stack[0];
        return list2star(v_22697, v_22698, v_22692);
    }
    return onevalue(v_22692);
}



// Code for ldf!-simp

static LispObject CC_ldfKsimp(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22721, v_22722;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_22722 = v_22651;
// end of prologue
    v_22721 = v_22722;
    if (v_22721 == nil) goto v_22655;
    else goto v_22656;
v_22655:
    v_22721 = nil;
    goto v_22654;
v_22656:
    v_22721 = v_22722;
    v_22721 = qcdr(v_22721);
    if (v_22721 == nil) goto v_22659;
    else goto v_22660;
v_22659:
    goto v_22671;
v_22667:
    goto v_22677;
v_22673:
    v_22721 = v_22722;
    v_22721 = qcar(v_22721);
    v_22721 = qcar(v_22721);
    v_22722 = qcar(v_22721);
    goto v_22674;
v_22675:
    v_22721 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22676;
v_22677:
    goto v_22673;
v_22674:
    goto v_22675;
v_22676:
    fn = elt(env, 1); // to
    v_22722 = (*qfn2(fn))(fn, v_22722, v_22721);
    env = stack[-1];
    goto v_22668;
v_22669:
    v_22721 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22670;
v_22671:
    goto v_22667;
v_22668:
    goto v_22669;
v_22670:
    v_22721 = cons(v_22722, v_22721);
    env = stack[-1];
    v_22721 = ncons(v_22721);
    env = stack[-1];
    fn = elt(env, 2); // prepf
    v_22721 = (*qfn1(fn))(fn, v_22721);
    env = stack[-1];
    fn = elt(env, 3); // simp
    v_22721 = (*qfn1(fn))(fn, v_22721);
    v_22721 = qcar(v_22721);
    goto v_22654;
v_22660:
    v_22721 = v_22722;
    fn = elt(env, 2); // prepf
    v_22721 = (*qfn1(fn))(fn, v_22721);
    env = stack[-1];
    fn = elt(env, 3); // simp
    v_22721 = (*qfn1(fn))(fn, v_22721);
    env = stack[-1];
    v_22721 = qcar(v_22721);
    v_22722 = v_22721;
    v_22721 = v_22722;
    if (!consp(v_22721)) goto v_22700;
    else goto v_22701;
v_22700:
    v_22721 = lisp_true;
    goto v_22699;
v_22701:
    v_22721 = v_22722;
    v_22721 = qcar(v_22721);
    v_22721 = (consp(v_22721) ? nil : lisp_true);
    goto v_22699;
    v_22721 = nil;
v_22699:
    if (v_22721 == nil) goto v_22696;
    else goto v_22697;
v_22696:
    goto v_22714;
v_22710:
    stack[0] = v_22722;
    goto v_22711;
v_22712:
    v_22721 = v_22722;
    fn = elt(env, 4); // comfac
    v_22721 = (*qfn1(fn))(fn, v_22721);
    env = stack[-1];
    v_22721 = qcdr(v_22721);
    goto v_22713;
v_22714:
    goto v_22710;
v_22711:
    goto v_22712;
v_22713:
    fn = elt(env, 5); // quotf
    v_22721 = (*qfn2(fn))(fn, stack[0], v_22721);
    env = stack[-1];
    v_22722 = v_22721;
    goto v_22695;
v_22697:
v_22695:
    v_22721 = v_22722;
    {
        fn = elt(env, 6); // absf
        return (*qfn1(fn))(fn, v_22721);
    }
    goto v_22654;
    v_22721 = nil;
v_22654:
    return onevalue(v_22721);
}



// Code for simpimpart

static LispObject CC_simpimpart(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22659, v_22660;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_22660 = v_22651;
// end of prologue
    v_22659 = nil;
// Binding !*factor
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_22659; // !*factor
    v_22659 = v_22660;
    v_22659 = qcar(v_22659);
    fn = elt(env, 2); // simp!*
    v_22659 = (*qfn1(fn))(fn, v_22659);
    env = stack[-1];
    fn = elt(env, 3); // impartsq
    v_22659 = (*qfn1(fn))(fn, v_22659);
    ;}  // end of a binding scope
    return onevalue(v_22659);
}



// Code for suspend

static LispObject CC_suspend(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22711, v_22712, v_22713, v_22714;
    LispObject fn;
    LispObject v_22658, v_22657, v_22656, v_22655, v_22654;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "suspend");
    va_start(aa, nargs);
    v_22654 = va_arg(aa, LispObject);
    v_22655 = va_arg(aa, LispObject);
    v_22656 = va_arg(aa, LispObject);
    v_22657 = va_arg(aa, LispObject);
    v_22658 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_22658,v_22657,v_22656,v_22655,v_22654);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_22654,v_22655,v_22656,v_22657,v_22658);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_22658;
    v_22712 = v_22657;
    v_22713 = v_22656;
    v_22714 = v_22655;
    v_22711 = v_22654;
// end of prologue
// Binding op
// FLUIDBIND: reloadenv=9 litvec-offset=1 saveloc=8
{   bind_fluid_stack bind_fluid_var(-9, 1, -8);
// Binding r
// FLUIDBIND: reloadenv=9 litvec-offset=2 saveloc=6
{   bind_fluid_stack bind_fluid_var(-9, 2, -6);
// Binding p
// FLUIDBIND: reloadenv=9 litvec-offset=3 saveloc=5
{   bind_fluid_stack bind_fluid_var(-9, 3, -5);
    qvalue(elt(env, 1)) = v_22711; // op
    v_22711 = v_22714;
    qvalue(elt(env, 2)) = v_22711; // r
    v_22711 = v_22713;
    qvalue(elt(env, 3)) = v_22711; // p
    goto v_22677;
v_22669:
    v_22711 = qvalue(elt(env, 2)); // r
    stack[-4] = qcar(v_22711);
    goto v_22670;
v_22671:
    v_22711 = qvalue(elt(env, 3)); // p
    stack[-3] = qcar(v_22711);
    goto v_22672;
v_22673:
    stack[-2] = v_22712;
    goto v_22674;
v_22675:
    goto v_22688;
v_22684:
    goto v_22696;
v_22690:
    stack[-1] = qvalue(elt(env, 1)); // op
    goto v_22691;
v_22692:
    v_22711 = qvalue(elt(env, 2)); // r
    stack[0] = qcdr(v_22711);
    goto v_22693;
v_22694:
    goto v_22706;
v_22702:
    v_22712 = qvalue(elt(env, 1)); // op
    goto v_22703;
v_22704:
    v_22711 = qvalue(elt(env, 3)); // p
    v_22711 = qcdr(v_22711);
    goto v_22705;
v_22706:
    goto v_22702;
v_22703:
    goto v_22704;
v_22705:
    v_22711 = cons(v_22712, v_22711);
    env = stack[-9];
    v_22711 = ncons(v_22711);
    env = stack[-9];
    goto v_22695;
v_22696:
    goto v_22690;
v_22691:
    goto v_22692;
v_22693:
    goto v_22694;
v_22695:
    v_22712 = acons(stack[-1], stack[0], v_22711);
    env = stack[-9];
    goto v_22685;
v_22686:
    v_22711 = stack[-7];
    goto v_22687;
v_22688:
    goto v_22684;
v_22685:
    goto v_22686;
v_22687:
    v_22711 = cons(v_22712, v_22711);
    env = stack[-9];
    goto v_22676;
v_22677:
    goto v_22669;
v_22670:
    goto v_22671;
v_22672:
    goto v_22673;
v_22674:
    goto v_22675;
v_22676:
    fn = elt(env, 4); // amatch
    v_22711 = (*qfnn(fn))(fn, 4, stack[-4], stack[-3], stack[-2], v_22711);
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_22711);
}



// Code for evinsert

static LispObject CC_evinsert(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22717, v_22718, v_22719;
    LispObject fn;
    LispObject v_22654, v_22653, v_22652, v_22651;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "evinsert");
    va_start(aa, nargs);
    v_22651 = va_arg(aa, LispObject);
    v_22652 = va_arg(aa, LispObject);
    v_22653 = va_arg(aa, LispObject);
    v_22654 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_22654,v_22653,v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_22651,v_22652,v_22653,v_22654);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_22654;
    stack[-1] = v_22653;
    stack[-2] = v_22652;
    stack[-3] = v_22651;
// end of prologue
    v_22719 = nil;
v_22659:
    v_22717 = stack[-3];
    if (v_22717 == nil) goto v_22666;
    else goto v_22667;
v_22666:
    v_22717 = lisp_true;
    goto v_22665;
v_22667:
    v_22717 = stack[0];
    v_22717 = (v_22717 == nil ? lisp_true : nil);
    goto v_22665;
    v_22717 = nil;
v_22665:
    if (v_22717 == nil) goto v_22663;
    v_22717 = v_22719;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_22717);
    }
v_22663:
    goto v_22682;
v_22678:
    v_22717 = stack[0];
    v_22718 = qcar(v_22717);
    goto v_22679;
v_22680:
    v_22717 = stack[-2];
    goto v_22681;
v_22682:
    goto v_22678;
v_22679:
    goto v_22680;
v_22681:
    if (equal(v_22718, v_22717)) goto v_22676;
    else goto v_22677;
v_22676:
    goto v_22691;
v_22687:
    stack[0] = v_22719;
    goto v_22688;
v_22689:
    goto v_22698;
v_22694:
    v_22718 = stack[-1];
    goto v_22695;
v_22696:
    v_22717 = stack[-3];
    v_22717 = qcdr(v_22717);
    goto v_22697;
v_22698:
    goto v_22694;
v_22695:
    goto v_22696;
v_22697:
    v_22717 = cons(v_22718, v_22717);
    env = stack[-4];
    goto v_22690;
v_22691:
    goto v_22687;
v_22688:
    goto v_22689;
v_22690:
    {
        LispObject v_22724 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_22724, v_22717);
    }
v_22677:
    goto v_22709;
v_22705:
    v_22717 = stack[-3];
    v_22717 = qcar(v_22717);
    goto v_22706;
v_22707:
    v_22718 = v_22719;
    goto v_22708;
v_22709:
    goto v_22705;
v_22706:
    goto v_22707;
v_22708:
    v_22717 = cons(v_22717, v_22718);
    env = stack[-4];
    v_22719 = v_22717;
    v_22717 = stack[-3];
    v_22717 = qcdr(v_22717);
    stack[-3] = v_22717;
    v_22717 = stack[0];
    v_22717 = qcdr(v_22717);
    stack[0] = v_22717;
    goto v_22659;
    v_22717 = nil;
    return onevalue(v_22717);
}



// Code for simpwedge

static LispObject CC_simpwedge(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22656;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_22656 = v_22651;
// end of prologue
    fn = elt(env, 1); // partitwedge
    v_22656 = (*qfn1(fn))(fn, v_22656);
    env = stack[0];
    {
        fn = elt(env, 2); // !*pf2sq
        return (*qfn1(fn))(fn, v_22656);
    }
}



// Code for calc_atlas

static LispObject CC_calc_atlas(LispObject env,
                         LispObject v_22651, LispObject v_22652)
{
    env = qenv(env);
    LispObject v_22674, v_22675, v_22676, v_22677;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22674 = v_22652;
    v_22675 = v_22651;
// end of prologue
    goto v_22663;
v_22655:
    v_22676 = v_22675;
    v_22677 = qcar(v_22676);
    goto v_22656;
v_22657:
    v_22676 = v_22675;
    v_22676 = qcdr(v_22676);
    v_22676 = qcdr(v_22676);
    v_22676 = qcar(v_22676);
    goto v_22658;
v_22659:
    v_22675 = qcdr(v_22675);
    v_22675 = qcar(v_22675);
    goto v_22660;
v_22661:
    goto v_22662;
v_22663:
    goto v_22655;
v_22656:
    goto v_22657;
v_22658:
    goto v_22659;
v_22660:
    goto v_22661;
v_22662:
    {
        fn = elt(env, 1); // calc_map_2d
        return (*qfnn(fn))(fn, 4, v_22677, v_22676, v_22675, v_22674);
    }
}



// Code for fs!:minusp!:

static LispObject CC_fsTminuspT(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22656;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22656 = v_22651;
// end of prologue
    v_22656 = qcdr(v_22656);
    {
        fn = elt(env, 1); // fs!:minusp
        return (*qfn1(fn))(fn, v_22656);
    }
}



// Code for pst_subpst

static LispObject CC_pst_subpst(LispObject env,
                         LispObject v_22651, LispObject v_22652)
{
    env = qenv(env);
    LispObject v_22664, v_22665;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22651,v_22652);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_22665 = v_22652;
    v_22664 = v_22651;
// end of prologue
    goto v_22658;
v_22654:
    stack[0] = qcdr(v_22664);
    goto v_22655;
v_22656:
    v_22664 = v_22665;
    v_22664 = sub1(v_22664);
    goto v_22657;
v_22658:
    goto v_22654;
v_22655:
    goto v_22656;
v_22657:
    v_22664 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_22664-TAG_FIXNUM)/(16/CELL)));
    return onevalue(v_22664);
}



// Code for lpos

static LispObject CC_lpos(LispObject env,
                         LispObject v_22651, LispObject v_22652)
{
    env = qenv(env);
    LispObject v_22679, v_22680, v_22681, v_22682;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22651,v_22652);
    }
// copy arguments values to proper place
    v_22681 = v_22652;
    v_22682 = v_22651;
// end of prologue
    goto v_22662;
v_22658:
    v_22680 = v_22682;
    goto v_22659;
v_22660:
    v_22679 = v_22681;
    v_22679 = qcar(v_22679);
    goto v_22661;
v_22662:
    goto v_22658;
v_22659:
    goto v_22660;
v_22661:
    if (v_22680 == v_22679) goto v_22656;
    else goto v_22657;
v_22656:
    v_22679 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22655;
v_22657:
    goto v_22675;
v_22671:
    v_22679 = v_22682;
    goto v_22672;
v_22673:
    v_22680 = v_22681;
    v_22680 = qcdr(v_22680);
    goto v_22674;
v_22675:
    goto v_22671;
v_22672:
    goto v_22673;
v_22674:
    v_22679 = CC_lpos(elt(env, 0), v_22679, v_22680);
    return add1(v_22679);
    v_22679 = nil;
v_22655:
    return onevalue(v_22679);
}



// Code for read!-comment1

static LispObject CC_readKcomment1(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22703, v_22704;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_22703 = v_22651;
// end of prologue
// Binding !*lower
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 1, -1);
    qvalue(elt(env, 1)) = nil; // !*lower
// Binding !*raise
// FLUIDBIND: reloadenv=2 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-2, 2, 0);
    qvalue(elt(env, 2)) = nil; // !*raise
    v_22703 = nil;
    qvalue(elt(env, 3)) = v_22703; // named!-character!*
v_22657:
    v_22703 = qvalue(elt(env, 3)); // named!-character!*
    if (v_22703 == nil) goto v_22663;
    else goto v_22661;
v_22663:
    goto v_22674;
v_22670:
    v_22703 = qvalue(elt(env, 4)); // crchar!*
    fn = elt(env, 7); // id2string
    v_22703 = (*qfn1(fn))(fn, v_22703);
    env = stack[-2];
    fn = elt(env, 8); // string!-length
    v_22704 = (*qfn1(fn))(fn, v_22703);
    env = stack[-2];
    goto v_22671;
v_22672:
    v_22703 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22673;
v_22674:
    goto v_22670;
v_22671:
    goto v_22672;
v_22673:
    if (v_22704 == v_22703) goto v_22669;
    v_22703 = lisp_true;
    goto v_22667;
v_22669:
    v_22703 = qvalue(elt(env, 4)); // crchar!*
    fn = elt(env, 9); // delcp
    v_22703 = (*qfn1(fn))(fn, v_22703);
    env = stack[-2];
    if (v_22703 == nil) goto v_22684;
    else goto v_22685;
v_22684:
    v_22703 = lisp_true;
    goto v_22683;
v_22685:
    goto v_22695;
v_22691:
    v_22704 = qvalue(elt(env, 4)); // crchar!*
    goto v_22692;
v_22693:
    v_22703 = qvalue(elt(env, 5)); // !$eol!$
    goto v_22694;
v_22695:
    goto v_22691;
v_22692:
    goto v_22693;
v_22694:
    v_22703 = (v_22704 == v_22703 ? lisp_true : nil);
    goto v_22683;
    v_22703 = nil;
v_22683:
    goto v_22667;
    v_22703 = nil;
v_22667:
    if (v_22703 == nil) goto v_22665;
    else goto v_22661;
v_22665:
    goto v_22662;
v_22661:
    v_22703 = nil;
    qvalue(elt(env, 3)) = v_22703; // named!-character!*
    fn = elt(env, 10); // readch1
    v_22703 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    qvalue(elt(env, 4)) = v_22703; // crchar!*
    goto v_22657;
v_22662:
    v_22703 = elt(env, 6); // ! 
    qvalue(elt(env, 4)) = v_22703; // crchar!*
    fn = elt(env, 11); // condterpri
    v_22703 = (*qfnn(fn))(fn, 0);
    v_22703 = nil;
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_22703);
}



// Code for ra_intequiv

static LispObject CC_ra_intequiv(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22662;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_22662 = v_22651;
// end of prologue
    goto v_22658;
v_22654:
    stack[0] = elt(env, 1); // ra_intequiv0
    goto v_22655;
v_22656:
    v_22662 = ncons(v_22662);
    env = stack[-1];
    goto v_22657;
v_22658:
    goto v_22654;
v_22655:
    goto v_22656;
v_22657:
    {
        LispObject v_22664 = stack[0];
        fn = elt(env, 2); // ra_wrapper
        return (*qfn2(fn))(fn, v_22664, v_22662);
    }
}



// Code for giintgcd

static LispObject CC_giintgcd(LispObject env,
                         LispObject v_22652, LispObject v_22653)
{
    env = qenv(env);
    LispObject v_22734, v_22735, v_22736;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22653,v_22652);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22652,v_22653);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_22734 = v_22653;
    v_22735 = v_22652;
// end of prologue
// Binding d
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 1, -1);
    qvalue(elt(env, 1)) = v_22734; // d
v_22662:
    goto v_22671;
v_22667:
    v_22736 = qvalue(elt(env, 1)); // d
    goto v_22668;
v_22669:
    v_22734 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22670;
v_22671:
    goto v_22667;
v_22668:
    goto v_22669;
v_22670:
    if (v_22736 == v_22734) goto v_22665;
    else goto v_22666;
v_22665:
    v_22734 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22661;
v_22666:
    v_22734 = v_22735;
    if (v_22734 == nil) goto v_22675;
    else goto v_22676;
v_22675:
    v_22734 = qvalue(elt(env, 1)); // d
    goto v_22661;
v_22676:
    v_22734 = v_22735;
    if (!consp(v_22734)) goto v_22679;
    else goto v_22680;
v_22679:
    goto v_22687;
v_22683:
    goto v_22684;
v_22685:
    v_22734 = qvalue(elt(env, 1)); // d
    goto v_22686;
v_22687:
    goto v_22683;
v_22684:
    goto v_22685;
v_22686:
    v_22734 = Lgcd(nil, v_22735, v_22734);
    goto v_22661;
v_22680:
    goto v_22697;
v_22693:
    v_22736 = v_22735;
    goto v_22694;
v_22695:
    v_22734 = elt(env, 2); // !:gi!:
    goto v_22696;
v_22697:
    goto v_22693;
v_22694:
    goto v_22695;
v_22696:
    if (!consp(v_22736)) goto v_22691;
    v_22736 = qcar(v_22736);
    if (v_22736 == v_22734) goto v_22690;
    else goto v_22691;
v_22690:
    goto v_22705;
v_22701:
    v_22734 = v_22735;
    v_22734 = qcdr(v_22734);
    stack[0] = qcar(v_22734);
    goto v_22702;
v_22703:
    goto v_22714;
v_22710:
    v_22734 = v_22735;
    v_22734 = qcdr(v_22734);
    v_22735 = qcdr(v_22734);
    goto v_22711;
v_22712:
    v_22734 = qvalue(elt(env, 1)); // d
    goto v_22713;
v_22714:
    goto v_22710;
v_22711:
    goto v_22712;
v_22713:
    v_22734 = Lgcd(nil, v_22735, v_22734);
    env = stack[-2];
    goto v_22704;
v_22705:
    goto v_22701;
v_22702:
    goto v_22703;
v_22704:
    v_22734 = Lgcd(nil, stack[0], v_22734);
    goto v_22661;
v_22691:
    v_22734 = v_22735;
    v_22734 = qcar(v_22734);
    v_22734 = qcdr(v_22734);
    stack[0] = v_22734;
    goto v_22729;
v_22725:
    v_22734 = v_22735;
    v_22735 = qcdr(v_22734);
    goto v_22726;
v_22727:
    v_22734 = qvalue(elt(env, 1)); // d
    goto v_22728;
v_22729:
    goto v_22725;
v_22726:
    goto v_22727;
v_22728:
    v_22734 = CC_giintgcd(elt(env, 0), v_22735, v_22734);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_22734; // d
    v_22734 = stack[0];
    v_22735 = v_22734;
    goto v_22662;
    v_22734 = nil;
v_22661:
    ;}  // end of a binding scope
    return onevalue(v_22734);
}



// Code for orddf

static LispObject CC_orddf(LispObject env,
                         LispObject v_22651, LispObject v_22652)
{
    env = qenv(env);
    LispObject v_22710, v_22711;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22651,v_22652);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22652;
    stack[-1] = v_22651;
// end of prologue
v_22656:
    v_22710 = stack[-1];
    if (v_22710 == nil) goto v_22659;
    else goto v_22660;
v_22659:
    v_22710 = stack[0];
    if (v_22710 == nil) goto v_22664;
    else goto v_22665;
v_22664:
    v_22710 = elt(env, 1); // "Orddf = case"
    {
        fn = elt(env, 4); // interr
        return (*qfn1(fn))(fn, v_22710);
    }
v_22665:
    v_22710 = elt(env, 2); // "Orddf v longer than u"
    {
        fn = elt(env, 4); // interr
        return (*qfn1(fn))(fn, v_22710);
    }
    goto v_22658;
v_22660:
    v_22710 = stack[0];
    if (v_22710 == nil) goto v_22673;
    else goto v_22674;
v_22673:
    v_22710 = elt(env, 3); // "Orddf u longer than v"
    {
        fn = elt(env, 4); // interr
        return (*qfn1(fn))(fn, v_22710);
    }
v_22674:
    goto v_22685;
v_22681:
    v_22710 = stack[-1];
    v_22711 = qcar(v_22710);
    goto v_22682;
v_22683:
    v_22710 = stack[0];
    v_22710 = qcar(v_22710);
    goto v_22684;
v_22685:
    goto v_22681;
v_22682:
    goto v_22683;
v_22684:
    fn = elt(env, 5); // exptcompare
    v_22710 = (*qfn2(fn))(fn, v_22711, v_22710);
    env = stack[-2];
    if (v_22710 == nil) goto v_22679;
    v_22710 = lisp_true;
    goto v_22655;
v_22679:
    goto v_22698;
v_22694:
    v_22710 = stack[0];
    v_22711 = qcar(v_22710);
    goto v_22695;
v_22696:
    v_22710 = stack[-1];
    v_22710 = qcar(v_22710);
    goto v_22697;
v_22698:
    goto v_22694;
v_22695:
    goto v_22696;
v_22697:
    fn = elt(env, 5); // exptcompare
    v_22710 = (*qfn2(fn))(fn, v_22711, v_22710);
    env = stack[-2];
    if (v_22710 == nil) goto v_22692;
    v_22710 = nil;
    goto v_22655;
v_22692:
    v_22710 = stack[-1];
    v_22710 = qcdr(v_22710);
    stack[-1] = v_22710;
    v_22710 = stack[0];
    v_22710 = qcdr(v_22710);
    stack[0] = v_22710;
    goto v_22656;
v_22658:
    v_22710 = nil;
v_22655:
    return onevalue(v_22710);
}



// Code for rl_mk!*fof

static LispObject CC_rl_mkHfof(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22656;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_22656 = v_22651;
// end of prologue
    fn = elt(env, 1); // rl_csimpl
    v_22656 = (*qfn1(fn))(fn, v_22656);
    env = stack[0];
    {
        fn = elt(env, 2); // rl_mk!*fof1
        return (*qfn1(fn))(fn, v_22656);
    }
}



// Code for mri_2ofsfat

static LispObject CC_mri_2ofsfat(LispObject env,
                         LispObject v_22651)
{
    env = qenv(env);
    LispObject v_22666, v_22667;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22651);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22651;
// end of prologue
    goto v_22660;
v_22654:
    v_22666 = stack[0];
    fn = elt(env, 1); // mri_op
    stack[-1] = (*qfn1(fn))(fn, v_22666);
    env = stack[-2];
    goto v_22655;
v_22656:
    v_22666 = stack[0];
    fn = elt(env, 2); // mri_arg2l
    v_22667 = (*qfn1(fn))(fn, v_22666);
    goto v_22657;
v_22658:
    v_22666 = nil;
    goto v_22659;
v_22660:
    goto v_22654;
v_22655:
    goto v_22656;
v_22657:
    goto v_22658;
v_22659:
    {
        LispObject v_22670 = stack[-1];
        return list3(v_22670, v_22667, v_22666);
    }
}



// Code for degree!-order

static LispObject CC_degreeKorder(LispObject env,
                         LispObject v_22651, LispObject v_22652)
{
    env = qenv(env);
    LispObject v_22700, v_22701, v_22702;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22700 = v_22652;
    v_22701 = v_22651;
// end of prologue
    v_22702 = v_22701;
    if (!consp(v_22702)) goto v_22660;
    else goto v_22661;
v_22660:
    v_22702 = lisp_true;
    goto v_22659;
v_22661:
    v_22702 = v_22701;
    v_22702 = qcar(v_22702);
    v_22702 = (consp(v_22702) ? nil : lisp_true);
    goto v_22659;
    v_22702 = nil;
v_22659:
    if (v_22702 == nil) goto v_22657;
    v_22700 = lisp_true;
    goto v_22655;
v_22657:
    v_22702 = v_22700;
    if (!consp(v_22702)) goto v_22674;
    else goto v_22675;
v_22674:
    v_22702 = lisp_true;
    goto v_22673;
v_22675:
    v_22702 = v_22700;
    v_22702 = qcar(v_22702);
    v_22702 = (consp(v_22702) ? nil : lisp_true);
    goto v_22673;
    v_22702 = nil;
v_22673:
    if (v_22702 == nil) goto v_22671;
    v_22700 = nil;
    goto v_22655;
v_22671:
    goto v_22691;
v_22687:
    v_22701 = qcar(v_22701);
    v_22701 = qcar(v_22701);
    v_22701 = qcdr(v_22701);
    goto v_22688;
v_22689:
    v_22700 = qcar(v_22700);
    v_22700 = qcar(v_22700);
    v_22700 = qcdr(v_22700);
    goto v_22690;
v_22691:
    goto v_22687;
v_22688:
    goto v_22689;
v_22690:
        return Llessp(nil, v_22701, v_22700);
    v_22700 = nil;
v_22655:
    return onevalue(v_22700);
}



// Code for matrixrd

static LispObject CC_matrixrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22758, v_22759, v_22760;
    LispObject fn;
    argcheck(nargs, 0, "matrixrd");
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
    goto v_22663;
v_22659:
    v_22759 = qvalue(elt(env, 1)); // atts
    goto v_22660;
v_22661:
    v_22758 = elt(env, 2); // (type)
    goto v_22662;
v_22663:
    goto v_22659;
v_22660:
    goto v_22661;
v_22662:
    fn = elt(env, 9); // retattributes
    v_22758 = (*qfn2(fn))(fn, v_22759, v_22758);
    env = stack[-3];
    stack[0] = v_22758;
    v_22758 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_22758;
    v_22758 = nil;
    stack[-2] = v_22758;
v_22671:
    goto v_22680;
v_22676:
    v_22759 = stack[-1];
    goto v_22677;
v_22678:
    v_22758 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22679;
v_22680:
    goto v_22676;
v_22677:
    goto v_22678;
v_22679:
    if (v_22759 == v_22758) goto v_22675;
    goto v_22670;
v_22675:
    fn = elt(env, 10); // lex
    v_22758 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_22693;
v_22689:
    v_22759 = qvalue(elt(env, 3)); // char
    goto v_22690;
v_22691:
    v_22758 = elt(env, 4); // (m a t r i x r o w)
    goto v_22692;
v_22693:
    goto v_22689;
v_22690:
    goto v_22691;
v_22692:
    if (equal(v_22759, v_22758)) goto v_22687;
    else goto v_22688;
v_22687:
    fn = elt(env, 11); // matrixrowrd
    v_22758 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    v_22759 = v_22758;
    v_22758 = stack[-2];
    if (v_22758 == nil) goto v_22700;
    goto v_22707;
v_22703:
    goto v_22704;
v_22705:
    v_22758 = v_22759;
    v_22758 = ncons(v_22758);
    env = stack[-3];
    goto v_22706;
v_22707:
    goto v_22703;
v_22704:
    goto v_22705;
v_22706:
    v_22758 = Lappend(nil, stack[-2], v_22758);
    env = stack[-3];
    stack[-2] = v_22758;
    goto v_22698;
v_22700:
    v_22758 = v_22759;
    v_22758 = ncons(v_22758);
    env = stack[-3];
    stack[-2] = v_22758;
    goto v_22698;
v_22698:
    goto v_22723;
v_22719:
    v_22759 = qvalue(elt(env, 3)); // char
    goto v_22720;
v_22721:
    v_22758 = elt(env, 5); // (!/ m a t r i x r o w)
    goto v_22722;
v_22723:
    goto v_22719;
v_22720:
    goto v_22721;
v_22722:
    if (equal(v_22759, v_22758)) goto v_22718;
    goto v_22731;
v_22727:
    v_22759 = elt(env, 6); // "</matrixrow>"
    goto v_22728;
v_22729:
    v_22758 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_22730;
v_22731:
    goto v_22727;
v_22728:
    goto v_22729;
v_22730:
    fn = elt(env, 12); // errorml
    v_22758 = (*qfn2(fn))(fn, v_22759, v_22758);
    env = stack[-3];
    goto v_22716;
v_22718:
v_22716:
    goto v_22686;
v_22688:
    v_22758 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_22758;
    goto v_22686;
v_22686:
    goto v_22671;
v_22670:
    goto v_22744;
v_22738:
    stack[-1] = elt(env, 7); // matrix
    goto v_22739;
v_22740:
    goto v_22741;
v_22742:
    goto v_22754;
v_22748:
    v_22760 = elt(env, 8); // matrixrow
    goto v_22749;
v_22750:
    v_22759 = stack[-2];
    goto v_22751;
v_22752:
    v_22758 = nil;
    goto v_22753;
v_22754:
    goto v_22748;
v_22749:
    goto v_22750;
v_22751:
    goto v_22752;
v_22753:
    v_22758 = list2star(v_22760, v_22759, v_22758);
    goto v_22743;
v_22744:
    goto v_22738;
v_22739:
    goto v_22740;
v_22741:
    goto v_22742;
v_22743:
    {
        LispObject v_22764 = stack[-1];
        LispObject v_22765 = stack[0];
        return list2star(v_22764, v_22765, v_22758);
    }
    return onevalue(v_22758);
}



// Code for reduceroots

static LispObject CC_reduceroots(LispObject env,
                         LispObject v_22651, LispObject v_22652)
{
    env = qenv(env);
    LispObject v_22696, v_22697, v_22698;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22651,v_22652);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22652;
    stack[-1] = v_22651;
// end of prologue
    v_22696 = nil;
v_22659:
    v_22697 = stack[-1];
    if (v_22697 == nil) goto v_22662;
    else goto v_22663;
v_22662:
    goto v_22658;
v_22663:
    goto v_22675;
v_22671:
    v_22697 = stack[0];
    v_22698 = qcar(v_22697);
    goto v_22672;
v_22673:
    v_22697 = elt(env, 1); // sqrt
    goto v_22674;
v_22675:
    goto v_22671;
v_22672:
    goto v_22673;
v_22674:
    if (!consp(v_22698)) goto v_22669;
    v_22698 = qcar(v_22698);
    if (v_22698 == v_22697) goto v_22668;
    else goto v_22669;
v_22668:
    goto v_22686;
v_22680:
    v_22698 = stack[-1];
    goto v_22681;
v_22682:
    v_22697 = stack[0];
    v_22697 = qcar(v_22697);
    goto v_22683;
v_22684:
    goto v_22685;
v_22686:
    goto v_22680;
v_22681:
    goto v_22682;
v_22683:
    goto v_22684;
v_22685:
    fn = elt(env, 2); // tryreduction
    v_22696 = (*qfnn(fn))(fn, 3, v_22698, v_22697, v_22696);
    env = stack[-2];
    goto v_22667;
v_22669:
v_22667:
    v_22697 = stack[-1];
    v_22697 = qcdr(v_22697);
    stack[-1] = v_22697;
    v_22697 = stack[0];
    v_22697 = qcdr(v_22697);
    stack[0] = v_22697;
    goto v_22659;
v_22658:
    return onevalue(v_22696);
}



// Code for compl

static LispObject CC_compl(LispObject env,
                         LispObject v_22651, LispObject v_22652)
{
    env = qenv(env);
    LispObject v_22691, v_22692, v_22693;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22651,v_22652);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22652;
    stack[-1] = v_22651;
// end of prologue
    v_22693 = nil;
v_22657:
    v_22691 = stack[-1];
    if (v_22691 == nil) goto v_22660;
    else goto v_22661;
v_22660:
    v_22691 = v_22693;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_22691);
    }
v_22661:
    goto v_22671;
v_22667:
    v_22691 = stack[-1];
    v_22692 = qcar(v_22691);
    goto v_22668;
v_22669:
    v_22691 = stack[0];
    goto v_22670;
v_22671:
    goto v_22667;
v_22668:
    goto v_22669;
v_22670:
    v_22691 = Lmember(nil, v_22692, v_22691);
    if (v_22691 == nil) goto v_22666;
    v_22691 = stack[-1];
    v_22691 = qcdr(v_22691);
    stack[-1] = v_22691;
    goto v_22657;
v_22666:
    goto v_22685;
v_22681:
    v_22691 = stack[-1];
    v_22691 = qcar(v_22691);
    goto v_22682;
v_22683:
    v_22692 = v_22693;
    goto v_22684;
v_22685:
    goto v_22681;
v_22682:
    goto v_22683;
v_22684:
    v_22691 = cons(v_22691, v_22692);
    env = stack[-2];
    v_22693 = v_22691;
    v_22691 = stack[-1];
    v_22691 = qcdr(v_22691);
    stack[-1] = v_22691;
    goto v_22657;
    v_22691 = nil;
    return onevalue(v_22691);
}



// Code for assgnpri

static LispObject CC_assgnpri(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22925, v_22926, v_22927;
    LispObject fn;
    LispObject v_22653, v_22652, v_22651;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "assgnpri");
    va_start(aa, nargs);
    v_22651 = va_arg(aa, LispObject);
    v_22652 = va_arg(aa, LispObject);
    v_22653 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22653,v_22652,v_22651);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22651,v_22652,v_22653);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_22653;
    stack[-2] = v_22652;
    stack[-3] = v_22651;
// end of prologue
    stack[-4] = nil;
    v_22925 = nil;
    qvalue(elt(env, 1)) = v_22925; // overflowed!*
    qvalue(elt(env, 2)) = v_22925; // testing!-width!*
    v_22925 = stack[-3];
    if (v_22925 == nil) goto v_22662;
    else goto v_22663;
v_22662:
    v_22925 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_22925;
    goto v_22661;
v_22663:
v_22661:
    v_22925 = qvalue(elt(env, 3)); // !*nero
    if (v_22925 == nil) goto v_22669;
    goto v_22677;
v_22673:
    v_22926 = stack[-3];
    goto v_22674;
v_22675:
    v_22925 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22676;
v_22677:
    goto v_22673;
v_22674:
    goto v_22675;
v_22676:
    if (v_22926 == v_22925) goto v_22672;
    else goto v_22669;
v_22672:
    v_22925 = nil;
    goto v_22658;
v_22669:
    v_22925 = qvalue(elt(env, 4)); // !*tex
    if (v_22925 == nil) goto v_22684;
    goto v_22693;
v_22687:
    v_22927 = stack[-3];
    goto v_22688;
v_22689:
    v_22926 = stack[-2];
    goto v_22690;
v_22691:
    v_22925 = stack[-1];
    goto v_22692;
v_22693:
    goto v_22687;
v_22688:
    goto v_22689;
v_22690:
    goto v_22691;
v_22692:
    {
        fn = elt(env, 20); // texpri
        return (*qfnn(fn))(fn, 3, v_22927, v_22926, v_22925);
    }
v_22684:
    v_22925 = elt(env, 5); // vecp
    fn = elt(env, 21); // getd
    v_22925 = (*qfn1(fn))(fn, v_22925);
    env = stack[-5];
    if (v_22925 == nil) goto v_22698;
    v_22925 = stack[-3];
    fn = elt(env, 5); // vecp
    v_22925 = (*qfn1(fn))(fn, v_22925);
    env = stack[-5];
    if (v_22925 == nil) goto v_22698;
    goto v_22710;
v_22706:
    v_22926 = stack[-3];
    goto v_22707;
v_22708:
    v_22925 = elt(env, 6); // mat
    goto v_22709;
v_22710:
    goto v_22706;
v_22707:
    goto v_22708;
v_22709:
    {
        fn = elt(env, 22); // vecpri
        return (*qfn2(fn))(fn, v_22926, v_22925);
    }
v_22698:
    goto v_22722;
v_22718:
    v_22926 = elt(env, 7); // csl
    goto v_22719;
v_22720:
    v_22925 = qvalue(elt(env, 8)); // lispsystem!*
    goto v_22721;
v_22722:
    goto v_22718;
v_22719:
    goto v_22720;
v_22721:
    v_22925 = Lmemq(nil, v_22926, v_22925);
    if (v_22925 == nil) goto v_22716;
    v_22925 = elt(env, 9); // math!-display
    fn = elt(env, 21); // getd
    v_22925 = (*qfn1(fn))(fn, v_22925);
    env = stack[-5];
    if (v_22925 == nil) goto v_22716;
    v_22925 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 9); // math!-display
    v_22925 = (*qfn1(fn))(fn, v_22925);
    env = stack[-5];
    if (v_22925 == nil) goto v_22716;
    goto v_22743;
v_22739:
    v_22926 = qvalue(elt(env, 10)); // outputhandler!*
    goto v_22740;
v_22741:
    v_22925 = elt(env, 11); // fancy!-output
    goto v_22742;
v_22743:
    goto v_22739;
v_22740:
    goto v_22741;
v_22742:
    if (v_22926 == v_22925) goto v_22737;
    else goto v_22738;
v_22737:
    v_22925 = stack[-3];
    fn = elt(env, 23); // would!-be!-huge
    v_22925 = (*qfn1(fn))(fn, v_22925);
    env = stack[-5];
    goto v_22736;
v_22738:
    v_22925 = nil;
    goto v_22736;
    v_22925 = nil;
v_22736:
    if (v_22925 == nil) goto v_22716;
    v_22925 = nil;
    fn = elt(env, 24); // fmp!-switch
    v_22925 = (*qfn1(fn))(fn, v_22925);
    env = stack[-5];
    v_22925 = lisp_true;
    stack[-4] = v_22925;
    goto v_22714;
v_22716:
v_22714:
    v_22925 = stack[-3];
    fn = elt(env, 25); // getrtype
    v_22925 = (*qfn1(fn))(fn, v_22925);
    env = stack[-5];
    v_22927 = v_22925;
    if (v_22925 == nil) goto v_22757;
    goto v_22771;
v_22767:
    v_22926 = v_22927;
    goto v_22768;
v_22769:
    v_22925 = elt(env, 12); // sprifn
    goto v_22770;
v_22771:
    goto v_22767;
v_22768:
    goto v_22769;
v_22770:
    v_22925 = Lflagp(nil, v_22926, v_22925);
    env = stack[-5];
    if (v_22925 == nil) goto v_22765;
    v_22925 = qvalue(elt(env, 10)); // outputhandler!*
    v_22925 = (v_22925 == nil ? lisp_true : nil);
    goto v_22763;
v_22765:
    v_22925 = nil;
    goto v_22763;
    v_22925 = nil;
v_22763:
    if (v_22925 == nil) goto v_22757;
    v_22925 = stack[-2];
    if (v_22925 == nil) goto v_22781;
    else goto v_22782;
v_22781:
    goto v_22789;
v_22785:
    goto v_22796;
v_22792:
    v_22926 = v_22927;
    goto v_22793;
v_22794:
    v_22925 = elt(env, 13); // tag
    goto v_22795;
v_22796:
    goto v_22792;
v_22793:
    goto v_22794;
v_22795:
    v_22925 = get(v_22926, v_22925);
    env = stack[-5];
    if (!symbolp(v_22925)) v_22926 = nil;
    else { v_22926 = qfastgets(v_22925);
           if (v_22926 != nil) { v_22926 = elt(v_22926, 57); // prifn
#ifdef RECORD_GET
             if (v_22926 != SPID_NOPROP)
                record_get(elt(fastget_names, 57), 1);
             else record_get(elt(fastget_names, 57), 0),
                v_22926 = nil; }
           else record_get(elt(fastget_names, 57), 0); }
#else
             if (v_22926 == SPID_NOPROP) v_22926 = nil; }}
#endif
    goto v_22786;
v_22787:
    v_22925 = stack[-3];
    goto v_22788;
v_22789:
    goto v_22785;
v_22786:
    goto v_22787;
v_22788:
    v_22925 = Lapply1(nil, v_22926, v_22925);
    env = stack[-5];
    goto v_22780;
v_22782:
    goto v_22810;
v_22804:
    v_22927 = elt(env, 14); // setq
    goto v_22805;
v_22806:
    v_22925 = stack[-2];
    v_22926 = qcar(v_22925);
    goto v_22807;
v_22808:
    v_22925 = stack[-3];
    goto v_22809;
v_22810:
    goto v_22804;
v_22805:
    goto v_22806;
v_22807:
    goto v_22808;
v_22809:
    v_22925 = list3(v_22927, v_22926, v_22925);
    env = stack[-5];
    fn = elt(env, 26); // maprin
    v_22925 = (*qfn1(fn))(fn, v_22925);
    env = stack[-5];
    goto v_22780;
v_22780:
    goto v_22755;
v_22757:
    goto v_22825;
v_22821:
    v_22926 = stack[-1];
    goto v_22822;
v_22823:
    v_22925 = elt(env, 15); // (first only)
    goto v_22824;
v_22825:
    goto v_22821;
v_22822:
    goto v_22823;
v_22824:
    v_22925 = Lmemq(nil, v_22926, v_22925);
    if (v_22925 == nil) goto v_22820;
    v_22925 = lisp_true;
    fn = elt(env, 27); // terpri!*
    v_22925 = (*qfn1(fn))(fn, v_22925);
    env = stack[-5];
    goto v_22818;
v_22820:
v_22818:
    v_22925 = stack[-2];
    fn = elt(env, 28); // evalvars
    v_22925 = (*qfn1(fn))(fn, v_22925);
    env = stack[-5];
    stack[-2] = v_22925;
    v_22925 = qvalue(elt(env, 16)); // !*fort
    if (v_22925 == nil) goto v_22836;
    goto v_22845;
v_22839:
    v_22927 = stack[-3];
    goto v_22840;
v_22841:
    v_22926 = stack[-2];
    goto v_22842;
v_22843:
    v_22925 = stack[-1];
    goto v_22844;
v_22845:
    goto v_22839;
v_22840:
    goto v_22841;
v_22842:
    goto v_22843;
v_22844:
    fn = elt(env, 29); // fvarpri
    v_22925 = (*qfnn(fn))(fn, 3, v_22927, v_22926, v_22925);
    env = stack[-5];
    v_22925 = stack[-4];
    if (v_22925 == nil) goto v_22852;
    v_22925 = lisp_true;
    fn = elt(env, 24); // fmp!-switch
    v_22925 = (*qfn1(fn))(fn, v_22925);
    goto v_22850;
v_22852:
v_22850:
    v_22925 = nil;
    goto v_22658;
v_22836:
    v_22925 = stack[-2];
    if (v_22925 == nil) goto v_22861;
    goto v_22868;
v_22864:
    stack[0] = elt(env, 14); // setq
    goto v_22865;
v_22866:
    goto v_22875;
v_22871:
    v_22926 = stack[-2];
    goto v_22872;
v_22873:
    v_22925 = stack[-3];
    goto v_22874;
v_22875:
    goto v_22871;
v_22872:
    goto v_22873;
v_22874:
    fn = elt(env, 30); // aconc
    v_22925 = (*qfn2(fn))(fn, v_22926, v_22925);
    env = stack[-5];
    goto v_22867;
v_22868:
    goto v_22864;
v_22865:
    goto v_22866;
v_22867:
    v_22925 = cons(stack[0], v_22925);
    env = stack[-5];
    goto v_22859;
v_22861:
    v_22925 = stack[-3];
    goto v_22859;
    v_22925 = nil;
v_22859:
    fn = elt(env, 26); // maprin
    v_22925 = (*qfn1(fn))(fn, v_22925);
    env = stack[-5];
    v_22925 = stack[-1];
    if (v_22925 == nil) goto v_22887;
    else goto v_22888;
v_22887:
    v_22925 = lisp_true;
    goto v_22886;
v_22888:
    goto v_22897;
v_22893:
    v_22926 = stack[-1];
    goto v_22894;
v_22895:
    v_22925 = elt(env, 17); // first
    goto v_22896;
v_22897:
    goto v_22893;
v_22894:
    goto v_22895;
v_22896:
    v_22925 = (v_22926 == v_22925 ? lisp_true : nil);
    goto v_22886;
    v_22925 = nil;
v_22886:
    if (v_22925 == nil) goto v_22884;
    v_22925 = stack[-4];
    if (v_22925 == nil) goto v_22904;
    v_22925 = lisp_true;
    fn = elt(env, 24); // fmp!-switch
    v_22925 = (*qfn1(fn))(fn, v_22925);
    goto v_22902;
v_22904:
v_22902:
    v_22925 = nil;
    goto v_22658;
v_22884:
    v_22925 = qvalue(elt(env, 18)); // !*nat
    if (v_22925 == nil) goto v_22909;
    else goto v_22910;
v_22909:
    v_22925 = elt(env, 19); // "$"
    fn = elt(env, 31); // prin2!*
    v_22925 = (*qfn1(fn))(fn, v_22925);
    env = stack[-5];
    goto v_22882;
v_22910:
v_22882:
    v_22925 = qvalue(elt(env, 18)); // !*nat
    v_22925 = (v_22925 == nil ? lisp_true : nil);
    fn = elt(env, 27); // terpri!*
    v_22925 = (*qfn1(fn))(fn, v_22925);
    env = stack[-5];
    goto v_22755;
v_22755:
    v_22925 = stack[-4];
    if (v_22925 == nil) goto v_22920;
    v_22925 = lisp_true;
    fn = elt(env, 24); // fmp!-switch
    v_22925 = (*qfn1(fn))(fn, v_22925);
    goto v_22918;
v_22920:
v_22918:
    v_22925 = nil;
v_22658:
    return onevalue(v_22925);
}



setup_type const u40_setup[] =
{
    {"mk+scal+mult+mat",        TOO_FEW_2,      CC_mkLscalLmultLmat,WRONG_NO_2},
    {"talp_nextt1",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_nextt1},
    {"factor-prim-f",           CC_factorKprimKf,TOO_MANY_1,   WRONG_NO_1},
    {"dvfsf_smcpknowl",         CC_dvfsf_smcpknowl,TOO_MANY_1, WRONG_NO_1},
    {"fnom",                    CC_fnom,        TOO_MANY_1,    WRONG_NO_1},
    {"look_for_substitute",     WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_look_for_substitute},
    {"aceq",                    TOO_FEW_2,      CC_aceq,       WRONG_NO_2},
    {"s_world_names",           CC_s_world_names,TOO_MANY_1,   WRONG_NO_1},
    {"mkimpart",                CC_mkimpart,    TOO_MANY_1,    WRONG_NO_1},
    {"xremf",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xremf},
    {"solvealgdepends",         TOO_FEW_2,      CC_solvealgdepends,WRONG_NO_2},
    {"lalr_augment_grammar",    CC_lalr_augment_grammar,TOO_MANY_1,WRONG_NO_1},
    {"sfto_subfwd",             TOO_FEW_2,      CC_sfto_subfwd,WRONG_NO_2},
    {"vectorrd",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vectorrd},
    {"genexp",                  CC_genexp,      TOO_MANY_1,    WRONG_NO_1},
    {"simp_without_resimp",     CC_simp_without_resimp,TOO_MANY_1,WRONG_NO_1},
    {"sc_columnscalarproduct",  TOO_FEW_2,      CC_sc_columnscalarproduct,WRONG_NO_2},
    {"simpunion",               CC_simpunion,   TOO_MANY_1,    WRONG_NO_1},
    {"gfplus",                  TOO_FEW_2,      CC_gfplus,     WRONG_NO_2},
    {"getupper",                CC_getupper,    TOO_MANY_1,    WRONG_NO_1},
    {"s_noparents",             CC_s_noparents, TOO_MANY_1,    WRONG_NO_1},
    {"reduce",                  TOO_FEW_2,      CC_reduce,     WRONG_NO_2},
    {"cali=min",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_caliMmin},
    {"*multf",                  TOO_FEW_2,      CC_Hmultf,     WRONG_NO_2},
    {"oddext",                  CC_oddext,      TOO_MANY_1,    WRONG_NO_1},
    {"ra_intequiv0",            CC_ra_intequiv0,TOO_MANY_1,    WRONG_NO_1},
    {"lalr_collect_nonterminals",CC_lalr_collect_nonterminals,TOO_MANY_1,WRONG_NO_1},
    {"createsinglevariablemonom",CC_createsinglevariablemonom,TOO_MANY_1,WRONG_NO_1},
    {"cl_pnf1",                 CC_cl_pnf1,     TOO_MANY_1,    WRONG_NO_1},
    {"pasf_smordtable",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pasf_smordtable},
    {"ofsf_updsignvar",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_updsignvar},
    {"make-modular-symmetric",  CC_makeKmodularKsymmetric,TOO_MANY_1,WRONG_NO_1},
    {"lowupperlimitrd",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lowupperlimitrd},
    {"ldf-simp",                CC_ldfKsimp,    TOO_MANY_1,    WRONG_NO_1},
    {"simpimpart",              CC_simpimpart,  TOO_MANY_1,    WRONG_NO_1},
    {"suspend",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_suspend},
    {"evinsert",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_evinsert},
    {"simpwedge",               CC_simpwedge,   TOO_MANY_1,    WRONG_NO_1},
    {"calc_atlas",              TOO_FEW_2,      CC_calc_atlas, WRONG_NO_2},
    {"fs:minusp:",              CC_fsTminuspT,  TOO_MANY_1,    WRONG_NO_1},
    {"pst_subpst",              TOO_FEW_2,      CC_pst_subpst, WRONG_NO_2},
    {"lpos",                    TOO_FEW_2,      CC_lpos,       WRONG_NO_2},
    {"read-comment1",           CC_readKcomment1,TOO_MANY_1,   WRONG_NO_1},
    {"ra_intequiv",             CC_ra_intequiv, TOO_MANY_1,    WRONG_NO_1},
    {"giintgcd",                TOO_FEW_2,      CC_giintgcd,   WRONG_NO_2},
    {"orddf",                   TOO_FEW_2,      CC_orddf,      WRONG_NO_2},
    {"rl_mk*fof",               CC_rl_mkHfof,   TOO_MANY_1,    WRONG_NO_1},
    {"mri_2ofsfat",             CC_mri_2ofsfat, TOO_MANY_1,    WRONG_NO_1},
    {"degree-order",            TOO_FEW_2,      CC_degreeKorder,WRONG_NO_2},
    {"matrixrd",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_matrixrd},
    {"reduceroots",             TOO_FEW_2,      CC_reduceroots,WRONG_NO_2},
    {"compl",                   TOO_FEW_2,      CC_compl,      WRONG_NO_2},
    {"assgnpri",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_assgnpri},
    {NULL, (one_args *)"u40", (two_args *)"172985 8523068 1629223", 0}
};

// end of generated code
