
// $destdir/u37.c        Machine generated C code

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



// Code for sparpri

static LispObject CC_sparpri(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21113, v_21114, v_21115;
    LispObject fn;
    LispObject v_21044, v_21043, v_21042;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sparpri");
    va_start(aa, nargs);
    v_21042 = va_arg(aa, LispObject);
    v_21043 = va_arg(aa, LispObject);
    v_21044 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21044,v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21042,v_21043,v_21044);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_21044;
    v_21113 = v_21043;
    v_21114 = v_21042;
// end of prologue
    stack[-5] = v_21113;
    v_21113 = v_21114;
    stack[-3] = v_21113;
v_21055:
    v_21113 = stack[-3];
    if (v_21113 == nil) goto v_21059;
    else goto v_21060;
v_21059:
    goto v_21054;
v_21060:
    v_21113 = stack[-3];
    v_21113 = qcar(v_21113);
    stack[-2] = v_21113;
    goto v_21071;
v_21067:
    goto v_21077;
v_21073:
    stack[-1] = elt(env, 1); // quote
    goto v_21074;
v_21075:
    goto v_21086;
v_21080:
    stack[0] = elt(env, 2); // setq
    goto v_21081;
v_21082:
    goto v_21095;
v_21089:
    v_21115 = stack[-4];
    goto v_21090;
v_21091:
    v_21114 = stack[-5];
    goto v_21092;
v_21093:
    v_21113 = stack[-2];
    v_21113 = qcar(v_21113);
    goto v_21094;
v_21095:
    goto v_21089;
v_21090:
    goto v_21091;
v_21092:
    goto v_21093;
v_21094:
    v_21114 = list3(v_21115, v_21114, v_21113);
    env = stack[-6];
    goto v_21083;
v_21084:
    v_21113 = stack[-2];
    v_21113 = qcdr(v_21113);
    goto v_21085;
v_21086:
    goto v_21080;
v_21081:
    goto v_21082;
v_21083:
    goto v_21084;
v_21085:
    v_21113 = list3(stack[0], v_21114, v_21113);
    env = stack[-6];
    goto v_21076;
v_21077:
    goto v_21073;
v_21074:
    goto v_21075;
v_21076:
    v_21114 = list2(stack[-1], v_21113);
    env = stack[-6];
    goto v_21068;
v_21069:
    v_21113 = elt(env, 3); // first
    goto v_21070;
v_21071:
    goto v_21067;
v_21068:
    goto v_21069;
v_21070:
    fn = elt(env, 6); // writepri
    v_21113 = (*qfn2(fn))(fn, v_21114, v_21113);
    env = stack[-6];
    goto v_21108;
v_21104:
    v_21114 = elt(env, 4); // (quote !$)
    goto v_21105;
v_21106:
    v_21113 = elt(env, 5); // last
    goto v_21107;
v_21108:
    goto v_21104;
v_21105:
    goto v_21106;
v_21107:
    fn = elt(env, 6); // writepri
    v_21113 = (*qfn2(fn))(fn, v_21114, v_21113);
    env = stack[-6];
    v_21113 = stack[-3];
    v_21113 = qcdr(v_21113);
    stack[-3] = v_21113;
    goto v_21055;
v_21054:
    v_21113 = nil;
    return onevalue(v_21113);
}



// Code for string2bytelist

static LispObject CC_string2bytelist(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21097, v_21098;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_21097 = v_21042;
// end of prologue
    stack[-1] = nil;
    fn = elt(env, 1); // string2list
    v_21097 = (*qfn1(fn))(fn, v_21097);
    env = stack[-2];
    stack[0] = v_21097;
v_21052:
    v_21097 = stack[0];
    if (v_21097 == nil) goto v_21055;
    else goto v_21056;
v_21055:
    goto v_21051;
v_21056:
    v_21097 = stack[0];
    v_21097 = qcar(v_21097);
    v_21097 = Lminusp(nil, v_21097);
    env = stack[-2];
    if (v_21097 == nil) goto v_21062;
    goto v_21071;
v_21067:
    goto v_21077;
v_21073:
    v_21098 = (LispObject)4096+TAG_FIXNUM; // 256
    goto v_21074;
v_21075:
    v_21097 = stack[0];
    v_21097 = qcar(v_21097);
    goto v_21076;
v_21077:
    goto v_21073;
v_21074:
    goto v_21075;
v_21076:
    v_21098 = plus2(v_21098, v_21097);
    env = stack[-2];
    goto v_21068;
v_21069:
    v_21097 = stack[-1];
    goto v_21070;
v_21071:
    goto v_21067;
v_21068:
    goto v_21069;
v_21070:
    v_21097 = cons(v_21098, v_21097);
    env = stack[-2];
    stack[-1] = v_21097;
    goto v_21060;
v_21062:
    goto v_21089;
v_21085:
    v_21097 = stack[0];
    v_21098 = qcar(v_21097);
    goto v_21086;
v_21087:
    v_21097 = stack[-1];
    goto v_21088;
v_21089:
    goto v_21085;
v_21086:
    goto v_21087;
v_21088:
    v_21097 = cons(v_21098, v_21097);
    env = stack[-2];
    stack[-1] = v_21097;
    goto v_21060;
v_21060:
    v_21097 = stack[0];
    v_21097 = qcdr(v_21097);
    stack[0] = v_21097;
    goto v_21052;
v_21051:
    v_21097 = stack[-1];
        return Lnreverse(nil, v_21097);
    return onevalue(v_21097);
}



// Code for sublap

static LispObject CC_sublap(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21132, v_21133;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21043;
    stack[-1] = v_21042;
// end of prologue
    v_21132 = stack[-1];
    if (v_21132 == nil) goto v_21054;
    else goto v_21055;
v_21054:
    v_21132 = lisp_true;
    goto v_21053;
v_21055:
    v_21132 = stack[0];
    v_21132 = (v_21132 == nil ? lisp_true : nil);
    goto v_21053;
    v_21132 = nil;
v_21053:
    if (v_21132 == nil) goto v_21051;
    v_21132 = stack[0];
    goto v_21049;
v_21051:
    v_21132 = stack[0];
    if (!consp(v_21132)) goto v_21063;
    else goto v_21064;
v_21063:
    v_21132 = stack[0];
    if (is_number(v_21132)) goto v_21068;
    else goto v_21069;
v_21068:
    v_21132 = stack[0];
    goto v_21067;
v_21069:
    goto v_21078;
v_21074:
    v_21133 = stack[0];
    goto v_21075;
v_21076:
    v_21132 = stack[-1];
    goto v_21077;
v_21078:
    goto v_21074;
v_21075:
    goto v_21076;
v_21077:
    v_21132 = Latsoc(nil, v_21133, v_21132);
    v_21133 = v_21132;
    if (v_21132 == nil) goto v_21073;
    v_21132 = v_21133;
    v_21132 = qcdr(v_21132);
    goto v_21067;
v_21073:
    v_21132 = stack[0];
    goto v_21067;
    v_21132 = nil;
v_21067:
    goto v_21049;
v_21064:
    goto v_21094;
v_21090:
    v_21132 = stack[0];
    v_21133 = qcar(v_21132);
    goto v_21091;
v_21092:
    v_21132 = elt(env, 1); // app
    goto v_21093;
v_21094:
    goto v_21090;
v_21091:
    goto v_21092;
v_21093:
    v_21132 = Lflagp(nil, v_21133, v_21132);
    env = stack[-3];
    if (v_21132 == nil) goto v_21088;
    goto v_21103;
v_21099:
    v_21133 = stack[-1];
    goto v_21100;
v_21101:
    v_21132 = stack[0];
    goto v_21102;
v_21103:
    goto v_21099;
v_21100:
    goto v_21101;
v_21102:
    {
        fn = elt(env, 2); // sublap1
        return (*qfn2(fn))(fn, v_21133, v_21132);
    }
v_21088:
    goto v_21113;
v_21109:
    goto v_21119;
v_21115:
    v_21133 = stack[-1];
    goto v_21116;
v_21117:
    v_21132 = stack[0];
    v_21132 = qcar(v_21132);
    goto v_21118;
v_21119:
    goto v_21115;
v_21116:
    goto v_21117;
v_21118:
    stack[-2] = CC_sublap(elt(env, 0), v_21133, v_21132);
    env = stack[-3];
    goto v_21110;
v_21111:
    goto v_21128;
v_21124:
    v_21133 = stack[-1];
    goto v_21125;
v_21126:
    v_21132 = stack[0];
    v_21132 = qcdr(v_21132);
    goto v_21127;
v_21128:
    goto v_21124;
v_21125:
    goto v_21126;
v_21127:
    v_21132 = CC_sublap(elt(env, 0), v_21133, v_21132);
    goto v_21112;
v_21113:
    goto v_21109;
v_21110:
    goto v_21111;
v_21112:
    {
        LispObject v_21137 = stack[-2];
        return cons(v_21137, v_21132);
    }
    v_21132 = nil;
v_21049:
    return onevalue(v_21132);
}



// Code for deletez1

static LispObject CC_deletez1(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21090, v_21091, v_21092, v_21093;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21043;
    stack[-1] = v_21042;
// end of prologue
    v_21093 = nil;
v_21048:
    v_21090 = stack[-1];
    if (v_21090 == nil) goto v_21051;
    else goto v_21052;
v_21051:
    v_21090 = v_21093;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_21090);
    }
v_21052:
    goto v_21062;
v_21058:
    v_21092 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21059;
v_21060:
    goto v_21068;
v_21064:
    v_21090 = stack[-1];
    v_21090 = qcar(v_21090);
    v_21091 = qcar(v_21090);
    goto v_21065;
v_21066:
    v_21090 = stack[0];
    goto v_21067;
v_21068:
    goto v_21064;
v_21065:
    goto v_21066;
v_21067:
    v_21090 = Lassoc(nil, v_21091, v_21090);
    v_21090 = qcdr(v_21090);
    goto v_21061;
v_21062:
    goto v_21058;
v_21059:
    goto v_21060;
v_21061:
    if (v_21092 == v_21090) goto v_21056;
    else goto v_21057;
v_21056:
    v_21090 = stack[-1];
    v_21090 = qcdr(v_21090);
    stack[-1] = v_21090;
    goto v_21048;
v_21057:
    goto v_21084;
v_21080:
    v_21090 = stack[-1];
    v_21090 = qcar(v_21090);
    goto v_21081;
v_21082:
    v_21091 = v_21093;
    goto v_21083;
v_21084:
    goto v_21080;
v_21081:
    goto v_21082;
v_21083:
    v_21090 = cons(v_21090, v_21091);
    env = stack[-2];
    v_21093 = v_21090;
    v_21090 = stack[-1];
    v_21090 = qcdr(v_21090);
    stack[-1] = v_21090;
    goto v_21048;
    v_21090 = nil;
    return onevalue(v_21090);
}



// Code for assert_kernelp

static LispObject CC_assert_kernelp(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21088, v_21089;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21088 = v_21042;
// end of prologue
    v_21089 = v_21088;
    if (symbolp(v_21089)) goto v_21049;
    else goto v_21050;
v_21049:
    v_21088 = lisp_true;
    goto v_21046;
v_21050:
    v_21089 = v_21088;
    v_21089 = Lconsp(nil, v_21089);
    env = stack[0];
    if (v_21089 == nil) goto v_21055;
    else goto v_21056;
v_21055:
    v_21088 = nil;
    goto v_21046;
v_21056:
    v_21089 = v_21088;
    v_21089 = qcar(v_21089);
    if (!symbolp(v_21089)) v_21089 = nil;
    else { v_21089 = qfastgets(v_21089);
           if (v_21089 != nil) { v_21089 = elt(v_21089, 38); // fkernfn
#ifdef RECORD_GET
             if (v_21089 != SPID_NOPROP)
                record_get(elt(fastget_names, 38), 1);
             else record_get(elt(fastget_names, 38), 0),
                v_21089 = nil; }
           else record_get(elt(fastget_names, 38), 0); }
#else
             if (v_21089 == SPID_NOPROP) v_21089 = nil; }}
#endif
    if (v_21089 == nil) goto v_21063;
    v_21088 = lisp_true;
    goto v_21046;
v_21063:
    v_21089 = v_21088;
    v_21089 = qcar(v_21089);
    if (!consp(v_21089)) goto v_21070;
    else goto v_21071;
v_21070:
    v_21089 = v_21088;
    v_21089 = qcar(v_21089);
    if (!symbolp(v_21089)) v_21089 = nil;
    else { v_21089 = qfastgets(v_21089);
           if (v_21089 != nil) { v_21089 = elt(v_21089, 24); // klist
#ifdef RECORD_GET
             if (v_21089 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v_21089 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v_21089 == SPID_NOPROP) v_21089 = nil; }}
#endif
    goto v_21069;
v_21071:
    v_21089 = qvalue(elt(env, 1)); // exlist!*
    goto v_21069;
    v_21089 = nil;
v_21069:
    goto v_21084;
v_21080:
    goto v_21081;
v_21082:
    goto v_21083;
v_21084:
    goto v_21080;
v_21081:
    goto v_21082;
v_21083:
    v_21088 = Latsoc(nil, v_21088, v_21089);
v_21046:
    return onevalue(v_21088);
}



// Code for !*!*a2i

static LispObject CC_HHa2i(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21068, v_21069;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21068 = v_21043;
    stack[0] = v_21042;
// end of prologue
    goto v_21054;
v_21050:
    v_21069 = stack[0];
    goto v_21051;
v_21052:
    goto v_21053;
v_21054:
    goto v_21050;
v_21051:
    goto v_21052;
v_21053:
    fn = elt(env, 2); // intexprnp
    v_21068 = (*qfn2(fn))(fn, v_21069, v_21068);
    env = stack[-1];
    if (v_21068 == nil) goto v_21048;
    v_21068 = stack[0];
    goto v_21046;
v_21048:
    goto v_21065;
v_21061:
    v_21069 = elt(env, 1); // ieval
    goto v_21062;
v_21063:
    v_21068 = stack[0];
    goto v_21064;
v_21065:
    goto v_21061;
v_21062:
    goto v_21063;
v_21064:
    return list2(v_21069, v_21068);
    v_21068 = nil;
v_21046:
    return onevalue(v_21068);
}



// Code for gvar1

static LispObject CC_gvar1(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21167, v_21168, v_21169, v_21170;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21170 = v_21043;
    v_21169 = v_21042;
// end of prologue
v_21047:
    v_21167 = v_21169;
    if (v_21167 == nil) goto v_21054;
    else goto v_21055;
v_21054:
    v_21167 = lisp_true;
    goto v_21053;
v_21055:
    v_21167 = v_21169;
    v_21167 = (is_number(v_21167) ? lisp_true : nil);
    if (v_21167 == nil) goto v_21062;
    else goto v_21061;
v_21062:
    goto v_21073;
v_21069:
    v_21168 = v_21169;
    goto v_21070;
v_21071:
    v_21167 = elt(env, 1); // i
    goto v_21072;
v_21073:
    goto v_21069;
v_21070:
    goto v_21071;
v_21072:
    if (v_21168 == v_21167) goto v_21067;
    else goto v_21068;
v_21067:
    v_21167 = qvalue(elt(env, 2)); // !*complex
    goto v_21066;
v_21068:
    v_21167 = nil;
    goto v_21066;
    v_21167 = nil;
v_21066:
v_21061:
    goto v_21053;
    v_21167 = nil;
v_21053:
    if (v_21167 == nil) goto v_21051;
    v_21167 = v_21170;
    goto v_21046;
v_21051:
    v_21167 = v_21169;
    if (!consp(v_21167)) goto v_21081;
    else goto v_21082;
v_21081:
    goto v_21092;
v_21088:
    v_21168 = v_21169;
    goto v_21089;
v_21090:
    v_21167 = v_21170;
    goto v_21091;
v_21092:
    goto v_21088;
v_21089:
    goto v_21090;
v_21091:
    v_21167 = Lmember(nil, v_21168, v_21167);
    if (v_21167 == nil) goto v_21087;
    v_21167 = v_21170;
    goto v_21046;
v_21087:
    goto v_21104;
v_21100:
    v_21167 = v_21169;
    goto v_21101;
v_21102:
    v_21168 = v_21170;
    goto v_21103;
v_21104:
    goto v_21100;
v_21101:
    goto v_21102;
v_21103:
    return cons(v_21167, v_21168);
    goto v_21049;
v_21082:
    v_21167 = v_21169;
    v_21167 = qcar(v_21167);
    if (!symbolp(v_21167)) v_21167 = nil;
    else { v_21167 = qfastgets(v_21167);
           if (v_21167 != nil) { v_21167 = elt(v_21167, 8); // dname
#ifdef RECORD_GET
             if (v_21167 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_21167 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_21167 == SPID_NOPROP) v_21167 = nil; }}
#endif
    if (v_21167 == nil) goto v_21108;
    v_21167 = v_21170;
    goto v_21046;
v_21108:
    goto v_21119;
v_21115:
    v_21167 = v_21169;
    v_21168 = qcar(v_21167);
    goto v_21116;
v_21117:
    v_21167 = elt(env, 3); // (plus times expt difference minus)
    goto v_21118;
v_21119:
    goto v_21115;
v_21116:
    goto v_21117;
v_21118:
    v_21167 = Lmemq(nil, v_21168, v_21167);
    if (v_21167 == nil) goto v_21114;
    goto v_21129;
v_21125:
    v_21167 = v_21169;
    v_21167 = qcdr(v_21167);
    goto v_21126;
v_21127:
    v_21168 = v_21170;
    goto v_21128;
v_21129:
    goto v_21125;
v_21126:
    goto v_21127;
v_21128:
    {
        fn = elt(env, 5); // gvarlis1
        return (*qfn2(fn))(fn, v_21167, v_21168);
    }
v_21114:
    goto v_21139;
v_21135:
    v_21167 = v_21169;
    v_21168 = qcar(v_21167);
    goto v_21136;
v_21137:
    v_21167 = elt(env, 4); // quotient
    goto v_21138;
v_21139:
    goto v_21135;
v_21136:
    goto v_21137;
v_21138:
    if (v_21168 == v_21167) goto v_21133;
    else goto v_21134;
v_21133:
    v_21167 = v_21169;
    v_21167 = qcdr(v_21167);
    v_21167 = qcar(v_21167);
    v_21169 = v_21167;
    goto v_21047;
v_21134:
    goto v_21152;
v_21148:
    v_21168 = v_21169;
    goto v_21149;
v_21150:
    v_21167 = v_21170;
    goto v_21151;
v_21152:
    goto v_21148;
v_21149:
    goto v_21150;
v_21151:
    v_21167 = Lmember(nil, v_21168, v_21167);
    if (v_21167 == nil) goto v_21147;
    v_21167 = v_21170;
    goto v_21046;
v_21147:
    goto v_21164;
v_21160:
    v_21167 = v_21169;
    goto v_21161;
v_21162:
    v_21168 = v_21170;
    goto v_21163;
v_21164:
    goto v_21160;
v_21161:
    goto v_21162;
v_21163:
    return cons(v_21167, v_21168);
v_21049:
    v_21167 = nil;
v_21046:
    return onevalue(v_21167);
}



// Code for drnconv

static LispObject CC_drnconv(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21101, v_21102, v_21103;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21102 = v_21042;
// end of prologue
    v_21101 = v_21102;
    if (v_21101 == nil) goto v_21050;
    else goto v_21051;
v_21050:
    v_21101 = lisp_true;
    goto v_21049;
v_21051:
    v_21101 = v_21102;
    v_21101 = (is_number(v_21101) ? lisp_true : nil);
    if (v_21101 == nil) goto v_21058;
    else goto v_21057;
v_21058:
    goto v_21066;
v_21062:
    v_21103 = v_21102;
    goto v_21063;
v_21064:
    v_21101 = qvalue(elt(env, 1)); // dmd!*
    goto v_21065;
v_21066:
    goto v_21062;
v_21063:
    goto v_21064;
v_21065:
    v_21101 = Leqcar(nil, v_21103, v_21101);
    env = stack[0];
v_21057:
    goto v_21049;
    v_21101 = nil;
v_21049:
    if (v_21101 == nil) goto v_21047;
    v_21101 = v_21102;
    goto v_21045;
v_21047:
    goto v_21077;
v_21073:
    v_21101 = v_21102;
    v_21103 = qcar(v_21101);
    goto v_21074;
v_21075:
    v_21101 = qvalue(elt(env, 1)); // dmd!*
    goto v_21076;
v_21077:
    goto v_21073;
v_21074:
    goto v_21075;
v_21076:
    v_21101 = get(v_21103, v_21101);
    v_21103 = v_21101;
    v_21101 = v_21103;
    if (v_21101 == nil) goto v_21085;
    v_21101 = v_21103;
    if (!consp(v_21101)) goto v_21088;
    else goto v_21085;
v_21088:
    goto v_21095;
v_21091:
    v_21101 = v_21103;
    goto v_21092;
v_21093:
    goto v_21094;
v_21095:
    goto v_21091;
v_21092:
    goto v_21093;
v_21094:
        return Lapply1(nil, v_21101, v_21102);
v_21085:
    v_21101 = v_21102;
    goto v_21083;
    v_21101 = nil;
v_21083:
    goto v_21045;
    v_21101 = nil;
v_21045:
    return onevalue(v_21101);
}



// Code for split!-further

static LispObject CC_splitKfurther(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21255, v_21256, v_21257, v_21258;
    LispObject fn;
    LispObject v_21044, v_21043, v_21042;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "split-further");
    va_start(aa, nargs);
    v_21042 = va_arg(aa, LispObject);
    v_21043 = va_arg(aa, LispObject);
    v_21044 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21044,v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21042,v_21043,v_21044);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_21044;
    stack[-2] = v_21043;
    stack[-3] = v_21042;
// end of prologue
    v_21255 = stack[-3];
    if (v_21255 == nil) goto v_21048;
    else goto v_21049;
v_21048:
    v_21255 = nil;
    return ncons(v_21255);
v_21049:
    goto v_21069;
v_21063:
    v_21255 = stack[-3];
    v_21257 = qcdr(v_21255);
    goto v_21064;
v_21065:
    v_21256 = stack[-2];
    goto v_21066;
v_21067:
    v_21255 = stack[-1];
    goto v_21068;
v_21069:
    goto v_21063;
v_21064:
    goto v_21065;
v_21066:
    goto v_21067;
v_21068:
    v_21255 = CC_splitKfurther(elt(env, 0), 3, v_21257, v_21256, v_21255);
    env = stack[-5];
    stack[-4] = v_21255;
    v_21255 = stack[-4];
    v_21255 = qcdr(v_21255);
    stack[0] = v_21255;
    v_21255 = stack[-4];
    v_21255 = qcar(v_21255);
    stack[-4] = v_21255;
    goto v_21086;
v_21082:
    v_21256 = qvalue(elt(env, 1)); // number!-needed
    goto v_21083;
v_21084:
    v_21255 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21085;
v_21086:
    goto v_21082;
v_21083:
    goto v_21084;
v_21085:
    if (v_21256 == v_21255) goto v_21080;
    else goto v_21081;
v_21080:
    goto v_21061;
v_21081:
    goto v_21096;
v_21090:
    v_21257 = stack[-2];
    goto v_21091;
v_21092:
    v_21256 = stack[-1];
    goto v_21093;
v_21094:
    v_21255 = qvalue(elt(env, 2)); // work!-vector1
    goto v_21095;
v_21096:
    goto v_21090;
v_21091:
    goto v_21092;
v_21093:
    goto v_21094;
v_21095:
    fn = elt(env, 6); // copy!-vector
    v_21255 = (*qfnn(fn))(fn, 3, v_21257, v_21256, v_21255);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_21255; // dwork1
    goto v_21107;
v_21101:
    v_21255 = stack[-3];
    v_21255 = qcar(v_21255);
    v_21257 = qcar(v_21255);
    goto v_21102;
v_21103:
    v_21255 = stack[-3];
    v_21255 = qcar(v_21255);
    v_21256 = qcdr(v_21255);
    goto v_21104;
v_21105:
    v_21255 = qvalue(elt(env, 4)); // work!-vector2
    goto v_21106;
v_21107:
    goto v_21101;
v_21102:
    goto v_21103;
v_21104:
    goto v_21105;
v_21106:
    fn = elt(env, 6); // copy!-vector
    v_21255 = (*qfnn(fn))(fn, 3, v_21257, v_21256, v_21255);
    env = stack[-5];
    qvalue(elt(env, 5)) = v_21255; // dwork2
    goto v_21124;
v_21116:
    v_21258 = qvalue(elt(env, 2)); // work!-vector1
    goto v_21117;
v_21118:
    v_21257 = qvalue(elt(env, 3)); // dwork1
    goto v_21119;
v_21120:
    v_21256 = qvalue(elt(env, 4)); // work!-vector2
    goto v_21121;
v_21122:
    v_21255 = qvalue(elt(env, 5)); // dwork2
    goto v_21123;
v_21124:
    goto v_21116;
v_21117:
    goto v_21118;
v_21119:
    goto v_21120;
v_21121:
    goto v_21122;
v_21123:
    fn = elt(env, 7); // gcd!-in!-vector
    v_21255 = (*qfnn(fn))(fn, 4, v_21258, v_21257, v_21256, v_21255);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_21255; // dwork1
    goto v_21141;
v_21137:
    v_21256 = qvalue(elt(env, 3)); // dwork1
    goto v_21138;
v_21139:
    v_21255 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21140;
v_21141:
    goto v_21137;
v_21138:
    goto v_21139;
v_21140:
    if (v_21256 == v_21255) goto v_21135;
    else goto v_21136;
v_21135:
    v_21255 = lisp_true;
    goto v_21134;
v_21136:
    goto v_21151;
v_21147:
    v_21256 = qvalue(elt(env, 3)); // dwork1
    goto v_21148;
v_21149:
    v_21255 = stack[-3];
    v_21255 = qcar(v_21255);
    v_21255 = qcdr(v_21255);
    goto v_21150;
v_21151:
    goto v_21147;
v_21148:
    goto v_21149;
v_21150:
    v_21255 = (equal(v_21256, v_21255) ? lisp_true : nil);
    goto v_21134;
    v_21255 = nil;
v_21134:
    if (v_21255 == nil) goto v_21132;
    goto v_21061;
v_21132:
    goto v_21164;
v_21158:
    v_21255 = stack[-3];
    v_21255 = qcar(v_21255);
    v_21257 = qcar(v_21255);
    goto v_21159;
v_21160:
    v_21255 = stack[-3];
    v_21255 = qcar(v_21255);
    v_21256 = qcdr(v_21255);
    goto v_21161;
v_21162:
    v_21255 = qvalue(elt(env, 4)); // work!-vector2
    goto v_21163;
v_21164:
    goto v_21158;
v_21159:
    goto v_21160;
v_21161:
    goto v_21162;
v_21163:
    fn = elt(env, 6); // copy!-vector
    v_21255 = (*qfnn(fn))(fn, 3, v_21257, v_21256, v_21255);
    env = stack[-5];
    qvalue(elt(env, 5)) = v_21255; // dwork2
    goto v_21181;
v_21173:
    v_21258 = qvalue(elt(env, 4)); // work!-vector2
    goto v_21174;
v_21175:
    v_21257 = qvalue(elt(env, 5)); // dwork2
    goto v_21176;
v_21177:
    v_21256 = qvalue(elt(env, 2)); // work!-vector1
    goto v_21178;
v_21179:
    v_21255 = qvalue(elt(env, 3)); // dwork1
    goto v_21180;
v_21181:
    goto v_21173;
v_21174:
    goto v_21175;
v_21176:
    goto v_21177;
v_21178:
    goto v_21179;
v_21180:
    fn = elt(env, 8); // quotfail!-in!-vector
    v_21255 = (*qfnn(fn))(fn, 4, v_21258, v_21257, v_21256, v_21255);
    env = stack[-5];
    qvalue(elt(env, 5)) = v_21255; // dwork2
    v_21255 = qvalue(elt(env, 3)); // dwork1
    v_21255 = Lmkvect(nil, v_21255);
    env = stack[-5];
    stack[-1] = v_21255;
    goto v_21195;
v_21189:
    v_21257 = qvalue(elt(env, 2)); // work!-vector1
    goto v_21190;
v_21191:
    v_21256 = qvalue(elt(env, 3)); // dwork1
    goto v_21192;
v_21193:
    v_21255 = stack[-1];
    goto v_21194;
v_21195:
    goto v_21189;
v_21190:
    goto v_21191;
v_21192:
    goto v_21193;
v_21194:
    fn = elt(env, 6); // copy!-vector
    v_21255 = (*qfnn(fn))(fn, 3, v_21257, v_21256, v_21255);
    env = stack[-5];
    goto v_21206;
v_21200:
    v_21257 = stack[-1];
    goto v_21201;
v_21202:
    v_21256 = qvalue(elt(env, 3)); // dwork1
    goto v_21203;
v_21204:
    v_21255 = stack[-4];
    goto v_21205;
v_21206:
    goto v_21200;
v_21201:
    goto v_21202;
v_21203:
    goto v_21204;
v_21205:
    v_21255 = acons(v_21257, v_21256, v_21255);
    env = stack[-5];
    stack[-4] = v_21255;
    goto v_21217;
v_21211:
    stack[-2] = qvalue(elt(env, 4)); // work!-vector2
    goto v_21212;
v_21213:
    stack[-1] = qvalue(elt(env, 5)); // dwork2
    goto v_21214;
v_21215:
    v_21255 = qvalue(elt(env, 5)); // dwork2
    v_21255 = Lmkvect(nil, v_21255);
    env = stack[-5];
    stack[-3] = v_21255;
    goto v_21216;
v_21217:
    goto v_21211;
v_21212:
    goto v_21213;
v_21214:
    goto v_21215;
v_21216:
    fn = elt(env, 6); // copy!-vector
    v_21255 = (*qfnn(fn))(fn, 3, stack[-2], stack[-1], v_21255);
    env = stack[-5];
    goto v_21229;
v_21223:
    v_21257 = stack[-3];
    goto v_21224;
v_21225:
    v_21256 = qvalue(elt(env, 5)); // dwork2
    goto v_21226;
v_21227:
    v_21255 = stack[0];
    goto v_21228;
v_21229:
    goto v_21223;
v_21224:
    goto v_21225;
v_21226:
    goto v_21227;
v_21228:
    v_21255 = acons(v_21257, v_21256, v_21255);
    env = stack[-5];
    stack[0] = v_21255;
    v_21255 = qvalue(elt(env, 1)); // number!-needed
    v_21255 = (LispObject)((intptr_t)(v_21255) - 0x10);
    qvalue(elt(env, 1)) = v_21255; // number!-needed
    goto v_21240;
v_21236:
    v_21256 = stack[-4];
    goto v_21237;
v_21238:
    v_21255 = stack[0];
    goto v_21239;
v_21240:
    goto v_21236;
v_21237:
    goto v_21238;
v_21239:
    return cons(v_21256, v_21255);
v_21061:
    goto v_21250;
v_21244:
    v_21257 = stack[-4];
    goto v_21245;
v_21246:
    v_21255 = stack[-3];
    v_21256 = qcar(v_21255);
    goto v_21247;
v_21248:
    v_21255 = stack[0];
    goto v_21249;
v_21250:
    goto v_21244;
v_21245:
    goto v_21246;
v_21247:
    goto v_21248;
v_21249:
    return list2star(v_21257, v_21256, v_21255);
    goto v_21047;
    v_21255 = nil;
v_21047:
    return onevalue(v_21255);
}



// Code for lex_init

static LispObject CC_lex_init(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21069, v_21070;
    LispObject fn;
    argcheck(nargs, 0, "lex_init");
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
    v_21069 = (LispObject)1024+TAG_FIXNUM; // 64
    v_21069 = Lmkvect(nil, v_21069);
    env = stack[0];
    qvalue(elt(env, 1)) = v_21069; // last64
    v_21069 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 2)) = v_21069; // last64p
    v_21069 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 3)) = v_21069; // which_line
    v_21069 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 4)) = v_21069; // if_depth
    v_21069 = qvalue(elt(env, 5)); // !*tracelex
    if (v_21069 == nil) goto v_21051;
    goto v_21061;
v_21057:
    v_21070 = Lposn(nil, 0);
    env = stack[0];
    goto v_21058;
v_21059:
    v_21069 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21060;
v_21061:
    goto v_21057;
v_21058:
    goto v_21059;
v_21060:
    if (v_21070 == v_21069) goto v_21056;
    v_21069 = Lterpri(nil, 0);
    env = stack[0];
    goto v_21054;
v_21056:
v_21054:
    v_21069 = elt(env, 6); // "yylex initialized"
    v_21069 = Lprintc(nil, v_21069);
    env = stack[0];
    goto v_21049;
v_21051:
v_21049:
    v_21069 = nil;
    qvalue(elt(env, 7)) = v_21069; // lex_peeked
    {
        fn = elt(env, 8); // yyreadch
        return (*qfnn(fn))(fn, 0);
    }
}



// Code for sfto_lmultf

static LispObject CC_sfto_lmultf(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21085, v_21086;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21042;
// end of prologue
    stack[-1] = nil;
v_21048:
    v_21085 = stack[0];
    if (v_21085 == nil) goto v_21053;
    else goto v_21054;
v_21053:
    goto v_21049;
v_21054:
    goto v_21061;
v_21057:
    v_21085 = stack[0];
    v_21086 = qcar(v_21085);
    goto v_21058;
v_21059:
    v_21085 = stack[-1];
    goto v_21060;
v_21061:
    goto v_21057;
v_21058:
    goto v_21059;
v_21060:
    v_21085 = cons(v_21086, v_21085);
    env = stack[-2];
    stack[-1] = v_21085;
    v_21085 = stack[0];
    v_21085 = qcdr(v_21085);
    stack[0] = v_21085;
    goto v_21048;
v_21049:
    v_21085 = (LispObject)16+TAG_FIXNUM; // 1
    v_21086 = v_21085;
v_21050:
    v_21085 = stack[-1];
    if (v_21085 == nil) goto v_21070;
    else goto v_21071;
v_21070:
    v_21085 = v_21086;
    goto v_21047;
v_21071:
    goto v_21079;
v_21075:
    v_21085 = stack[-1];
    v_21085 = qcar(v_21085);
    goto v_21076;
v_21077:
    goto v_21078;
v_21079:
    goto v_21075;
v_21076:
    goto v_21077;
v_21078:
    fn = elt(env, 1); // multf
    v_21085 = (*qfn2(fn))(fn, v_21085, v_21086);
    env = stack[-2];
    v_21086 = v_21085;
    v_21085 = stack[-1];
    v_21085 = qcdr(v_21085);
    stack[-1] = v_21085;
    goto v_21050;
v_21047:
    return onevalue(v_21085);
}



// Code for give!*position

static LispObject CC_giveHposition(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21108, v_21109;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_21043;
    stack[-3] = v_21042;
// end of prologue
    v_21108 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_21108;
    v_21108 = nil;
    stack[-1] = v_21108;
v_21053:
    v_21108 = stack[-1];
    if (v_21108 == nil) goto v_21060;
    else goto v_21061;
v_21060:
    goto v_21068;
v_21064:
    stack[0] = stack[-4];
    goto v_21065;
v_21066:
    v_21108 = stack[-2];
    v_21108 = Llength(nil, v_21108);
    env = stack[-5];
    goto v_21067;
v_21068:
    goto v_21064;
v_21065:
    goto v_21066;
v_21067:
    v_21108 = (LispObject)lesseq2(stack[0], v_21108);
    v_21108 = v_21108 ? lisp_true : nil;
    env = stack[-5];
    goto v_21059;
v_21061:
    v_21108 = nil;
    goto v_21059;
    v_21108 = nil;
v_21059:
    if (v_21108 == nil) goto v_21056;
    else goto v_21057;
v_21056:
    goto v_21052;
v_21057:
    goto v_21084;
v_21080:
    goto v_21090;
v_21086:
    v_21109 = stack[-2];
    goto v_21087;
v_21088:
    v_21108 = stack[-4];
    goto v_21089;
v_21090:
    goto v_21086;
v_21087:
    goto v_21088;
v_21089:
    fn = elt(env, 2); // nth
    v_21109 = (*qfn2(fn))(fn, v_21109, v_21108);
    env = stack[-5];
    goto v_21081;
v_21082:
    v_21108 = stack[-3];
    goto v_21083;
v_21084:
    goto v_21080;
v_21081:
    goto v_21082;
v_21083:
    if (equal(v_21109, v_21108)) goto v_21078;
    else goto v_21079;
v_21078:
    v_21108 = lisp_true;
    stack[-1] = v_21108;
    goto v_21077;
v_21079:
    v_21108 = stack[-4];
    v_21108 = add1(v_21108);
    env = stack[-5];
    stack[-4] = v_21108;
    goto v_21077;
v_21077:
    goto v_21053;
v_21052:
    v_21108 = stack[-1];
    if (v_21108 == nil) goto v_21102;
    else goto v_21103;
v_21102:
    v_21108 = elt(env, 1); // "error in give position"
    fn = elt(env, 3); // rederr
    v_21108 = (*qfn1(fn))(fn, v_21108);
    goto v_21101;
v_21103:
v_21101:
    v_21108 = stack[-4];
    return onevalue(v_21108);
}



// Code for talp_specsub

static LispObject CC_talp_specsub(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21160, v_21161, v_21162;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[0] = v_21043;
    stack[-4] = v_21042;
// end of prologue
    goto v_21061;
v_21057:
    v_21161 = stack[0];
    goto v_21058;
v_21059:
    v_21160 = elt(env, 1); // true
    goto v_21060;
v_21061:
    goto v_21057;
v_21058:
    goto v_21059;
v_21060:
    if (v_21161 == v_21160) goto v_21055;
    else goto v_21056;
v_21055:
    v_21160 = lisp_true;
    goto v_21054;
v_21056:
    goto v_21071;
v_21067:
    v_21161 = stack[0];
    goto v_21068;
v_21069:
    v_21160 = elt(env, 2); // false
    goto v_21070;
v_21071:
    goto v_21067;
v_21068:
    goto v_21069;
v_21070:
    v_21160 = (v_21161 == v_21160 ? lisp_true : nil);
    goto v_21054;
    v_21160 = nil;
v_21054:
    if (v_21160 == nil) goto v_21052;
    v_21160 = stack[0];
    goto v_21048;
v_21052:
    v_21160 = stack[0];
    fn = elt(env, 3); // talp_atfp
    v_21160 = (*qfn1(fn))(fn, v_21160);
    env = stack[-6];
    if (v_21160 == nil) goto v_21079;
    goto v_21089;
v_21083:
    v_21160 = stack[-4];
    v_21162 = qcar(v_21160);
    goto v_21084;
v_21085:
    v_21160 = stack[-4];
    v_21161 = qcdr(v_21160);
    goto v_21086;
v_21087:
    v_21160 = stack[0];
    goto v_21088;
v_21089:
    goto v_21083;
v_21084:
    goto v_21085;
v_21086:
    goto v_21087;
v_21088:
    {
        fn = elt(env, 4); // talp_specsubat
        return (*qfnn(fn))(fn, 3, v_21162, v_21161, v_21160);
    }
v_21079:
    v_21160 = stack[0];
    fn = elt(env, 5); // talp_op
    v_21160 = (*qfn1(fn))(fn, v_21160);
    env = stack[-6];
    goto v_21102;
v_21098:
    stack[-5] = v_21160;
    goto v_21099;
v_21100:
    v_21160 = stack[0];
    fn = elt(env, 6); // talp_argl
    v_21160 = (*qfn1(fn))(fn, v_21160);
    env = stack[-6];
    stack[-3] = v_21160;
    v_21160 = stack[-3];
    if (v_21160 == nil) goto v_21114;
    else goto v_21115;
v_21114:
    v_21160 = nil;
    goto v_21108;
v_21115:
    v_21160 = stack[-3];
    v_21160 = qcar(v_21160);
    goto v_21127;
v_21123:
    v_21161 = stack[-4];
    goto v_21124;
v_21125:
    goto v_21126;
v_21127:
    goto v_21123;
v_21124:
    goto v_21125;
v_21126:
    v_21160 = CC_talp_specsub(elt(env, 0), v_21161, v_21160);
    env = stack[-6];
    v_21160 = ncons(v_21160);
    env = stack[-6];
    stack[-1] = v_21160;
    stack[-2] = v_21160;
v_21109:
    v_21160 = stack[-3];
    v_21160 = qcdr(v_21160);
    stack[-3] = v_21160;
    v_21160 = stack[-3];
    if (v_21160 == nil) goto v_21134;
    else goto v_21135;
v_21134:
    v_21160 = stack[-2];
    goto v_21108;
v_21135:
    goto v_21143;
v_21139:
    stack[0] = stack[-1];
    goto v_21140;
v_21141:
    v_21160 = stack[-3];
    v_21160 = qcar(v_21160);
    goto v_21154;
v_21150:
    v_21161 = stack[-4];
    goto v_21151;
v_21152:
    goto v_21153;
v_21154:
    goto v_21150;
v_21151:
    goto v_21152;
v_21153:
    v_21160 = CC_talp_specsub(elt(env, 0), v_21161, v_21160);
    env = stack[-6];
    v_21160 = ncons(v_21160);
    env = stack[-6];
    goto v_21142;
v_21143:
    goto v_21139;
v_21140:
    goto v_21141;
v_21142:
    v_21160 = Lrplacd(nil, stack[0], v_21160);
    env = stack[-6];
    v_21160 = stack[-1];
    v_21160 = qcdr(v_21160);
    stack[-1] = v_21160;
    goto v_21109;
v_21108:
    goto v_21101;
v_21102:
    goto v_21098;
v_21099:
    goto v_21100;
v_21101:
    {
        LispObject v_21169 = stack[-5];
        return cons(v_21169, v_21160);
    }
v_21048:
    return onevalue(v_21160);
}



// Code for mconv1

static LispObject CC_mconv1(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21092, v_21093;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_21042;
// end of prologue
    stack[-2] = nil;
v_21047:
    v_21092 = stack[-1];
    if (!consp(v_21092)) goto v_21054;
    else goto v_21055;
v_21054:
    v_21092 = lisp_true;
    goto v_21053;
v_21055:
    v_21092 = stack[-1];
    v_21092 = qcar(v_21092);
    v_21092 = (consp(v_21092) ? nil : lisp_true);
    goto v_21053;
    v_21092 = nil;
v_21053:
    if (v_21092 == nil) goto v_21051;
    goto v_21068;
v_21064:
    stack[0] = stack[-2];
    goto v_21065;
v_21066:
    v_21092 = stack[-1];
    fn = elt(env, 1); // drnconv
    v_21092 = (*qfn1(fn))(fn, v_21092);
    env = stack[-3];
    goto v_21067;
v_21068:
    goto v_21064;
v_21065:
    goto v_21066;
v_21067:
    {
        LispObject v_21097 = stack[0];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_21097, v_21092);
    }
v_21051:
    goto v_21081;
v_21075:
    v_21092 = stack[-1];
    v_21092 = qcar(v_21092);
    stack[0] = qcar(v_21092);
    goto v_21076;
v_21077:
    v_21092 = stack[-1];
    v_21092 = qcar(v_21092);
    v_21092 = qcdr(v_21092);
    v_21093 = CC_mconv1(elt(env, 0), v_21092);
    env = stack[-3];
    goto v_21078;
v_21079:
    v_21092 = stack[-2];
    goto v_21080;
v_21081:
    goto v_21075;
v_21076:
    goto v_21077;
v_21078:
    goto v_21079;
v_21080:
    v_21092 = acons(stack[0], v_21093, v_21092);
    env = stack[-3];
    stack[-2] = v_21092;
    v_21092 = stack[-1];
    v_21092 = qcdr(v_21092);
    stack[-1] = v_21092;
    goto v_21047;
    v_21092 = nil;
    return onevalue(v_21092);
}



// Code for pasf_uprap

static LispObject CC_pasf_uprap(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21052, v_21053;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21052 = v_21042;
// end of prologue
    goto v_21049;
v_21045:
    v_21053 = v_21052;
    goto v_21046;
v_21047:
    v_21052 = nil;
    goto v_21048;
v_21049:
    goto v_21045;
v_21046:
    goto v_21047;
v_21048:
    {
        fn = elt(env, 1); // pasf_uprap1
        return (*qfn2(fn))(fn, v_21053, v_21052);
    }
}



// Code for sfto_mvarx

static LispObject CC_sfto_mvarx(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21066, v_21067;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21066 = v_21042;
// end of prologue
    v_21067 = v_21066;
    if (!consp(v_21067)) goto v_21050;
    else goto v_21051;
v_21050:
    v_21067 = lisp_true;
    goto v_21049;
v_21051:
    v_21067 = v_21066;
    v_21067 = qcar(v_21067);
    v_21067 = (consp(v_21067) ? nil : lisp_true);
    goto v_21049;
    v_21067 = nil;
v_21049:
    if (v_21067 == nil) goto v_21047;
    v_21066 = nil;
    goto v_21045;
v_21047:
    v_21066 = qcar(v_21066);
    v_21066 = qcar(v_21066);
    v_21066 = qcar(v_21066);
    goto v_21045;
    v_21066 = nil;
v_21045:
    return onevalue(v_21066);
}



// Code for ciml

static LispObject CC_ciml(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21063, v_21064;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21042;
// end of prologue
    v_21063 = elt(env, 1); // "<ci"
    fn = elt(env, 4); // printout
    v_21063 = (*qfn1(fn))(fn, v_21063);
    env = stack[-1];
    goto v_21053;
v_21049:
    v_21063 = stack[0];
    v_21064 = qcar(v_21063);
    goto v_21050;
v_21051:
    v_21063 = elt(env, 2); // ""
    goto v_21052;
v_21053:
    goto v_21049;
v_21050:
    goto v_21051;
v_21052:
    fn = elt(env, 5); // attributesml
    v_21063 = (*qfn2(fn))(fn, v_21064, v_21063);
    env = stack[-1];
    v_21063 = stack[0];
    v_21063 = qcdr(v_21063);
    v_21063 = qcar(v_21063);
    v_21063 = Lprinc(nil, v_21063);
    env = stack[-1];
    v_21063 = elt(env, 3); // "</ci>"
    v_21063 = Lprinc(nil, v_21063);
    v_21063 = nil;
    return onevalue(v_21063);
}



// Code for matrixp

static LispObject CC_matrixp(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21086, v_21087, v_21088;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21087 = v_21042;
// end of prologue
    v_21086 = v_21087;
    v_21086 = Lconsp(nil, v_21086);
    env = stack[0];
    if (v_21086 == nil) goto v_21048;
    else goto v_21049;
v_21048:
    v_21086 = v_21087;
    fn = elt(env, 3); // reval
    v_21086 = (*qfn1(fn))(fn, v_21086);
    env = stack[0];
    v_21087 = v_21086;
    goto v_21047;
v_21049:
v_21047:
    goto v_21067;
v_21063:
    v_21088 = v_21087;
    goto v_21064;
v_21065:
    v_21086 = elt(env, 1); // mat
    goto v_21066;
v_21067:
    goto v_21063;
v_21064:
    goto v_21065;
v_21066:
    if (!consp(v_21088)) goto v_21060;
    v_21088 = qcar(v_21088);
    if (v_21088 == v_21086) goto v_21061;
v_21060:
    goto v_21075;
v_21071:
    goto v_21072;
v_21073:
    v_21086 = elt(env, 2); // sparsemat
    goto v_21074;
v_21075:
    goto v_21071;
v_21072:
    goto v_21073;
v_21074:
    v_21086 = Leqcar(nil, v_21087, v_21086);
    v_21086 = (v_21086 == nil ? lisp_true : nil);
    goto v_21059;
v_21061:
    v_21086 = nil;
    goto v_21059;
    v_21086 = nil;
v_21059:
    if (v_21086 == nil) goto v_21057;
    v_21086 = nil;
    goto v_21045;
v_21057:
    v_21086 = lisp_true;
    goto v_21045;
    v_21086 = nil;
v_21045:
    return onevalue(v_21086);
}



// Code for evequal

static LispObject CC_evequal(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21100, v_21101, v_21102, v_21103, v_21104;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21102 = v_21043;
    v_21103 = v_21042;
// end of prologue
v_21047:
    v_21100 = v_21103;
    if (v_21100 == nil) goto v_21054;
    else goto v_21055;
v_21054:
    v_21100 = v_21102;
    v_21100 = (v_21100 == nil ? lisp_true : nil);
    goto v_21053;
v_21055:
    v_21100 = nil;
    goto v_21053;
    v_21100 = nil;
v_21053:
    if (v_21100 == nil) goto v_21051;
    v_21100 = lisp_true;
    goto v_21046;
v_21051:
    v_21100 = v_21103;
    if (v_21100 == nil) goto v_21063;
    else goto v_21064;
v_21063:
    v_21100 = elt(env, 1); // (0)
    v_21103 = v_21100;
    goto v_21047;
v_21064:
    v_21100 = v_21102;
    if (v_21100 == nil) goto v_21067;
    else goto v_21068;
v_21067:
    v_21100 = elt(env, 1); // (0)
    v_21102 = v_21100;
    goto v_21047;
v_21068:
    goto v_21081;
v_21077:
    v_21104 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21078;
v_21079:
    goto v_21087;
v_21083:
    v_21100 = v_21103;
    v_21101 = qcar(v_21100);
    goto v_21084;
v_21085:
    v_21100 = v_21102;
    v_21100 = qcar(v_21100);
    goto v_21086;
v_21087:
    goto v_21083;
v_21084:
    goto v_21085;
v_21086:
    v_21100 = (LispObject)(intptr_t)((intptr_t)v_21101 - (intptr_t)v_21100 + TAG_FIXNUM);
    goto v_21080;
v_21081:
    goto v_21077;
v_21078:
    goto v_21079;
v_21080:
    if (v_21104 == v_21100) goto v_21075;
    else goto v_21076;
v_21075:
    v_21100 = v_21103;
    v_21100 = qcdr(v_21100);
    v_21103 = v_21100;
    v_21100 = v_21102;
    v_21100 = qcdr(v_21100);
    v_21102 = v_21100;
    goto v_21047;
v_21076:
    v_21100 = nil;
    goto v_21046;
    goto v_21049;
v_21049:
    v_21100 = nil;
v_21046:
    return onevalue(v_21100);
}



// Code for exdff0

static LispObject CC_exdff0(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21147, v_21148;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_21042;
// end of prologue
    stack[-3] = nil;
v_21048:
    v_21147 = stack[-2];
    if (!consp(v_21147)) goto v_21057;
    else goto v_21058;
v_21057:
    v_21147 = lisp_true;
    goto v_21056;
v_21058:
    v_21147 = stack[-2];
    v_21147 = qcar(v_21147);
    v_21147 = (consp(v_21147) ? nil : lisp_true);
    goto v_21056;
    v_21147 = nil;
v_21056:
    if (v_21147 == nil) goto v_21054;
    goto v_21049;
v_21054:
    goto v_21071;
v_21067:
    goto v_21077;
v_21073:
    goto v_21083;
v_21079:
    goto v_21089;
v_21085:
    goto v_21096;
v_21092:
    v_21147 = stack[-2];
    v_21147 = qcar(v_21147);
    v_21148 = qcar(v_21147);
    goto v_21093;
v_21094:
    v_21147 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21095;
v_21096:
    goto v_21092;
v_21093:
    goto v_21094;
v_21095:
    v_21147 = cons(v_21148, v_21147);
    env = stack[-4];
    v_21148 = ncons(v_21147);
    env = stack[-4];
    goto v_21086;
v_21087:
    v_21147 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21088;
v_21089:
    goto v_21085;
v_21086:
    goto v_21087;
v_21088:
    stack[0] = cons(v_21148, v_21147);
    env = stack[-4];
    goto v_21080;
v_21081:
    v_21147 = stack[-2];
    v_21147 = qcar(v_21147);
    v_21147 = qcdr(v_21147);
    v_21147 = CC_exdff0(elt(env, 0), v_21147);
    env = stack[-4];
    goto v_21082;
v_21083:
    goto v_21079;
v_21080:
    goto v_21081;
v_21082:
    fn = elt(env, 1); // multsqpf
    stack[-1] = (*qfn2(fn))(fn, stack[0], v_21147);
    env = stack[-4];
    goto v_21074;
v_21075:
    goto v_21111;
v_21107:
    v_21147 = stack[-2];
    v_21147 = qcar(v_21147);
    v_21147 = qcar(v_21147);
    fn = elt(env, 2); // exdfp0
    stack[0] = (*qfn1(fn))(fn, v_21147);
    env = stack[-4];
    goto v_21108;
v_21109:
    goto v_21121;
v_21117:
    v_21147 = stack[-2];
    v_21147 = qcar(v_21147);
    v_21148 = qcdr(v_21147);
    goto v_21118;
v_21119:
    v_21147 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21120;
v_21121:
    goto v_21117;
v_21118:
    goto v_21119;
v_21120:
    v_21147 = cons(v_21148, v_21147);
    env = stack[-4];
    goto v_21110;
v_21111:
    goto v_21107;
v_21108:
    goto v_21109;
v_21110:
    fn = elt(env, 3); // multpfsq
    v_21147 = (*qfn2(fn))(fn, stack[0], v_21147);
    env = stack[-4];
    goto v_21076;
v_21077:
    goto v_21073;
v_21074:
    goto v_21075;
v_21076:
    fn = elt(env, 4); // addpf
    v_21148 = (*qfn2(fn))(fn, stack[-1], v_21147);
    env = stack[-4];
    goto v_21068;
v_21069:
    v_21147 = stack[-3];
    goto v_21070;
v_21071:
    goto v_21067;
v_21068:
    goto v_21069;
v_21070:
    v_21147 = cons(v_21148, v_21147);
    env = stack[-4];
    stack[-3] = v_21147;
    v_21147 = stack[-2];
    v_21147 = qcdr(v_21147);
    stack[-2] = v_21147;
    goto v_21048;
v_21049:
    v_21147 = nil;
    v_21148 = v_21147;
v_21050:
    v_21147 = stack[-3];
    if (v_21147 == nil) goto v_21132;
    else goto v_21133;
v_21132:
    v_21147 = v_21148;
    goto v_21047;
v_21133:
    goto v_21141;
v_21137:
    v_21147 = stack[-3];
    v_21147 = qcar(v_21147);
    goto v_21138;
v_21139:
    goto v_21140;
v_21141:
    goto v_21137;
v_21138:
    goto v_21139;
v_21140:
    fn = elt(env, 4); // addpf
    v_21147 = (*qfn2(fn))(fn, v_21147, v_21148);
    env = stack[-4];
    v_21148 = v_21147;
    v_21147 = stack[-3];
    v_21147 = qcdr(v_21147);
    stack[-3] = v_21147;
    goto v_21050;
v_21047:
    return onevalue(v_21147);
}



// Code for gftimes

static LispObject CC_gftimes(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21069, v_21070, v_21071;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21070 = v_21043;
    v_21071 = v_21042;
// end of prologue
    v_21069 = v_21071;
    v_21069 = qcar(v_21069);
    if (!consp(v_21069)) goto v_21047;
    else goto v_21048;
v_21047:
    goto v_21056;
v_21052:
    v_21069 = v_21071;
    goto v_21053;
v_21054:
    goto v_21055;
v_21056:
    goto v_21052;
v_21053:
    goto v_21054;
v_21055:
    {
        fn = elt(env, 1); // gfftimes
        return (*qfn2(fn))(fn, v_21069, v_21070);
    }
v_21048:
    goto v_21066;
v_21062:
    v_21069 = v_21071;
    goto v_21063;
v_21064:
    goto v_21065;
v_21066:
    goto v_21062;
v_21063:
    goto v_21064;
v_21065:
    {
        fn = elt(env, 2); // gbftimes
        return (*qfn2(fn))(fn, v_21069, v_21070);
    }
    v_21069 = nil;
    return onevalue(v_21069);
}



// Code for getphystypeall

static LispObject CC_getphystypeall(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21084, v_21085;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21042;
// end of prologue
    goto v_21057;
v_21053:
    v_21085 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21054;
v_21055:
    v_21084 = stack[0];
    goto v_21056;
v_21057:
    goto v_21053;
v_21054:
    goto v_21055;
v_21056:
    fn = elt(env, 2); // deleteall
    v_21084 = (*qfn2(fn))(fn, v_21085, v_21084);
    env = stack[-2];
    fn = elt(env, 3); // collectphystype
    v_21084 = (*qfn1(fn))(fn, v_21084);
    env = stack[-2];
    v_21085 = v_21084;
    if (v_21084 == nil) goto v_21049;
    else goto v_21050;
v_21049:
    v_21084 = nil;
    goto v_21046;
v_21050:
    v_21084 = v_21085;
    v_21084 = qcdr(v_21084);
    if (v_21084 == nil) goto v_21062;
    goto v_21070;
v_21066:
    stack[-1] = elt(env, 0); // getphystypeall
    goto v_21067;
v_21068:
    goto v_21077;
v_21073:
    v_21085 = elt(env, 1); // "PHYSOP type mismatch in"
    goto v_21074;
v_21075:
    v_21084 = stack[0];
    goto v_21076;
v_21077:
    goto v_21073;
v_21074:
    goto v_21075;
v_21076:
    v_21084 = list2(v_21085, v_21084);
    env = stack[-2];
    goto v_21069;
v_21070:
    goto v_21066;
v_21067:
    goto v_21068;
v_21069:
    fn = elt(env, 4); // rederr2
    v_21084 = (*qfn2(fn))(fn, stack[-1], v_21084);
    goto v_21048;
v_21062:
    v_21084 = v_21085;
    v_21084 = qcar(v_21084);
    goto v_21046;
v_21048:
    v_21084 = nil;
v_21046:
    return onevalue(v_21084);
}



// Code for groeb!=crita

static LispObject CC_groebMcrita(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21052, v_21053;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21052 = v_21042;
// end of prologue
    goto v_21049;
v_21045:
    v_21053 = v_21052;
    goto v_21046;
v_21047:
    v_21052 = elt(env, 1); // groeb!=testa
    goto v_21048;
v_21049:
    goto v_21045;
v_21046:
    goto v_21047;
v_21048:
    {
        fn = elt(env, 2); // listminimize
        return (*qfn2(fn))(fn, v_21053, v_21052);
    }
}



// Code for taydegree!<

static LispObject CC_taydegreeR(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21101, v_21102;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_21043;
    stack[-2] = v_21042;
// end of prologue
v_21049:
    v_21101 = stack[-2];
    v_21101 = qcar(v_21101);
    stack[-3] = v_21101;
    v_21101 = stack[-1];
    v_21101 = qcar(v_21101);
    stack[0] = v_21101;
v_21050:
    goto v_21064;
v_21060:
    v_21101 = stack[-3];
    v_21102 = qcar(v_21101);
    goto v_21061;
v_21062:
    v_21101 = stack[0];
    v_21101 = qcar(v_21101);
    goto v_21063;
v_21064:
    goto v_21060;
v_21061:
    goto v_21062;
v_21063:
    fn = elt(env, 1); // tayexp!-greaterp
    v_21101 = (*qfn2(fn))(fn, v_21102, v_21101);
    env = stack[-4];
    if (v_21101 == nil) goto v_21058;
    v_21101 = nil;
    goto v_21048;
v_21058:
    goto v_21077;
v_21073:
    v_21101 = stack[-3];
    v_21102 = qcar(v_21101);
    goto v_21074;
v_21075:
    v_21101 = stack[0];
    v_21101 = qcar(v_21101);
    goto v_21076;
v_21077:
    goto v_21073;
v_21074:
    goto v_21075;
v_21076:
    fn = elt(env, 2); // tayexp!-lessp
    v_21101 = (*qfn2(fn))(fn, v_21102, v_21101);
    env = stack[-4];
    if (v_21101 == nil) goto v_21071;
    v_21101 = lisp_true;
    goto v_21048;
v_21071:
    v_21101 = stack[-3];
    v_21101 = qcdr(v_21101);
    stack[-3] = v_21101;
    v_21101 = stack[0];
    v_21101 = qcdr(v_21101);
    stack[0] = v_21101;
    v_21101 = stack[-3];
    if (v_21101 == nil) goto v_21090;
    goto v_21050;
v_21090:
    v_21101 = stack[-2];
    v_21101 = qcdr(v_21101);
    stack[-2] = v_21101;
    v_21101 = stack[-1];
    v_21101 = qcdr(v_21101);
    stack[-1] = v_21101;
    v_21101 = stack[-2];
    if (v_21101 == nil) goto v_21099;
    goto v_21049;
v_21099:
    v_21101 = nil;
v_21048:
    return onevalue(v_21101);
}



// Code for cl_pnf2

static LispObject CC_cl_pnf2(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21357, v_21358, v_21359;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21042;
// end of prologue
    v_21357 = stack[0];
    if (!consp(v_21357)) goto v_21050;
    else goto v_21051;
v_21050:
    v_21357 = stack[0];
    goto v_21049;
v_21051:
    v_21357 = stack[0];
    v_21357 = qcar(v_21357);
    goto v_21049;
    v_21357 = nil;
v_21049:
    stack[-1] = v_21357;
    goto v_21070;
v_21066:
    v_21358 = stack[-1];
    goto v_21067;
v_21068:
    v_21357 = elt(env, 1); // ex
    goto v_21069;
v_21070:
    goto v_21066;
v_21067:
    goto v_21068;
v_21069:
    if (v_21358 == v_21357) goto v_21064;
    else goto v_21065;
v_21064:
    v_21357 = lisp_true;
    goto v_21063;
v_21065:
    goto v_21080;
v_21076:
    v_21358 = stack[-1];
    goto v_21077;
v_21078:
    v_21357 = elt(env, 2); // all
    goto v_21079;
v_21080:
    goto v_21076;
v_21077:
    goto v_21078;
v_21079:
    v_21357 = (v_21358 == v_21357 ? lisp_true : nil);
    goto v_21063;
    v_21357 = nil;
v_21063:
    if (v_21357 == nil) goto v_21061;
    v_21357 = stack[0];
    {
        fn = elt(env, 15); // cl_pnf2!-quantifier
        return (*qfn1(fn))(fn, v_21357);
    }
v_21061:
    goto v_21098;
v_21094:
    v_21358 = stack[-1];
    goto v_21095;
v_21096:
    v_21357 = elt(env, 3); // or
    goto v_21097;
v_21098:
    goto v_21094;
v_21095:
    goto v_21096;
v_21097:
    if (v_21358 == v_21357) goto v_21092;
    else goto v_21093;
v_21092:
    v_21357 = lisp_true;
    goto v_21091;
v_21093:
    goto v_21108;
v_21104:
    v_21358 = stack[-1];
    goto v_21105;
v_21106:
    v_21357 = elt(env, 4); // and
    goto v_21107;
v_21108:
    goto v_21104;
v_21105:
    goto v_21106;
v_21107:
    v_21357 = (v_21358 == v_21357 ? lisp_true : nil);
    goto v_21091;
    v_21357 = nil;
v_21091:
    if (v_21357 == nil) goto v_21089;
    v_21357 = stack[0];
    {
        fn = elt(env, 16); // cl_pnf2!-junctor
        return (*qfn1(fn))(fn, v_21357);
    }
v_21089:
    goto v_21126;
v_21122:
    v_21358 = stack[-1];
    goto v_21123;
v_21124:
    v_21357 = elt(env, 5); // true
    goto v_21125;
v_21126:
    goto v_21122;
v_21123:
    goto v_21124;
v_21125:
    if (v_21358 == v_21357) goto v_21120;
    else goto v_21121;
v_21120:
    v_21357 = lisp_true;
    goto v_21119;
v_21121:
    goto v_21136;
v_21132:
    v_21358 = stack[-1];
    goto v_21133;
v_21134:
    v_21357 = elt(env, 6); // false
    goto v_21135;
v_21136:
    goto v_21132;
v_21133:
    goto v_21134;
v_21135:
    v_21357 = (v_21358 == v_21357 ? lisp_true : nil);
    goto v_21119;
    v_21357 = nil;
v_21119:
    if (v_21357 == nil) goto v_21117;
    v_21357 = stack[0];
    return ncons(v_21357);
v_21117:
    goto v_21151;
v_21147:
    v_21358 = stack[-1];
    goto v_21148;
v_21149:
    v_21357 = elt(env, 0); // cl_pnf2
    goto v_21150;
v_21151:
    goto v_21147;
v_21148:
    goto v_21149;
v_21150:
    fn = elt(env, 17); // rl_external
    v_21357 = (*qfn2(fn))(fn, v_21358, v_21357);
    env = stack[-2];
    v_21358 = v_21357;
    if (v_21357 == nil) goto v_21145;
    goto v_21159;
v_21155:
    stack[-1] = v_21358;
    goto v_21156;
v_21157:
    v_21357 = stack[0];
    v_21357 = ncons(v_21357);
    env = stack[-2];
    goto v_21158;
v_21159:
    goto v_21155;
v_21156:
    goto v_21157;
v_21158:
    {
        LispObject v_21362 = stack[-1];
        fn = elt(env, 18); // apply
        return (*qfn2(fn))(fn, v_21362, v_21357);
    }
v_21145:
    goto v_21179;
v_21175:
    v_21358 = stack[-1];
    goto v_21176;
v_21177:
    v_21357 = elt(env, 5); // true
    goto v_21178;
v_21179:
    goto v_21175;
v_21176:
    goto v_21177;
v_21178:
    if (v_21358 == v_21357) goto v_21173;
    else goto v_21174;
v_21173:
    v_21357 = lisp_true;
    goto v_21172;
v_21174:
    goto v_21189;
v_21185:
    v_21358 = stack[-1];
    goto v_21186;
v_21187:
    v_21357 = elt(env, 6); // false
    goto v_21188;
v_21189:
    goto v_21185;
v_21186:
    goto v_21187;
v_21188:
    v_21357 = (v_21358 == v_21357 ? lisp_true : nil);
    goto v_21172;
    v_21357 = nil;
v_21172:
    if (v_21357 == nil) goto v_21170;
    v_21357 = lisp_true;
    goto v_21168;
v_21170:
    goto v_21216;
v_21212:
    v_21358 = stack[-1];
    goto v_21213;
v_21214:
    v_21357 = elt(env, 3); // or
    goto v_21215;
v_21216:
    goto v_21212;
v_21213:
    goto v_21214;
v_21215:
    if (v_21358 == v_21357) goto v_21210;
    else goto v_21211;
v_21210:
    v_21357 = lisp_true;
    goto v_21209;
v_21211:
    goto v_21226;
v_21222:
    v_21358 = stack[-1];
    goto v_21223;
v_21224:
    v_21357 = elt(env, 4); // and
    goto v_21225;
v_21226:
    goto v_21222;
v_21223:
    goto v_21224;
v_21225:
    v_21357 = (v_21358 == v_21357 ? lisp_true : nil);
    goto v_21209;
    v_21357 = nil;
v_21209:
    if (v_21357 == nil) goto v_21207;
    v_21357 = lisp_true;
    goto v_21205;
v_21207:
    goto v_21237;
v_21233:
    v_21358 = stack[-1];
    goto v_21234;
v_21235:
    v_21357 = elt(env, 7); // not
    goto v_21236;
v_21237:
    goto v_21233;
v_21234:
    goto v_21235;
v_21236:
    v_21357 = (v_21358 == v_21357 ? lisp_true : nil);
    goto v_21205;
    v_21357 = nil;
v_21205:
    if (v_21357 == nil) goto v_21203;
    v_21357 = lisp_true;
    goto v_21201;
v_21203:
    goto v_21252;
v_21248:
    v_21358 = stack[-1];
    goto v_21249;
v_21250:
    v_21357 = elt(env, 8); // impl
    goto v_21251;
v_21252:
    goto v_21248;
v_21249:
    goto v_21250;
v_21251:
    if (v_21358 == v_21357) goto v_21246;
    else goto v_21247;
v_21246:
    v_21357 = lisp_true;
    goto v_21245;
v_21247:
    goto v_21266;
v_21262:
    v_21358 = stack[-1];
    goto v_21263;
v_21264:
    v_21357 = elt(env, 9); // repl
    goto v_21265;
v_21266:
    goto v_21262;
v_21263:
    goto v_21264;
v_21265:
    if (v_21358 == v_21357) goto v_21260;
    else goto v_21261;
v_21260:
    v_21357 = lisp_true;
    goto v_21259;
v_21261:
    goto v_21276;
v_21272:
    v_21358 = stack[-1];
    goto v_21273;
v_21274:
    v_21357 = elt(env, 10); // equiv
    goto v_21275;
v_21276:
    goto v_21272;
v_21273:
    goto v_21274;
v_21275:
    v_21357 = (v_21358 == v_21357 ? lisp_true : nil);
    goto v_21259;
    v_21357 = nil;
v_21259:
    goto v_21245;
    v_21357 = nil;
v_21245:
    goto v_21201;
    v_21357 = nil;
v_21201:
    if (v_21357 == nil) goto v_21199;
    v_21357 = lisp_true;
    goto v_21197;
v_21199:
    goto v_21295;
v_21291:
    v_21358 = stack[-1];
    goto v_21292;
v_21293:
    v_21357 = elt(env, 1); // ex
    goto v_21294;
v_21295:
    goto v_21291;
v_21292:
    goto v_21293;
v_21294:
    if (v_21358 == v_21357) goto v_21289;
    else goto v_21290;
v_21289:
    v_21357 = lisp_true;
    goto v_21288;
v_21290:
    goto v_21305;
v_21301:
    v_21358 = stack[-1];
    goto v_21302;
v_21303:
    v_21357 = elt(env, 2); // all
    goto v_21304;
v_21305:
    goto v_21301;
v_21302:
    goto v_21303;
v_21304:
    v_21357 = (v_21358 == v_21357 ? lisp_true : nil);
    goto v_21288;
    v_21357 = nil;
v_21288:
    if (v_21357 == nil) goto v_21286;
    v_21357 = lisp_true;
    goto v_21284;
v_21286:
    goto v_21324;
v_21320:
    v_21358 = stack[-1];
    goto v_21321;
v_21322:
    v_21357 = elt(env, 11); // bex
    goto v_21323;
v_21324:
    goto v_21320;
v_21321:
    goto v_21322;
v_21323:
    if (v_21358 == v_21357) goto v_21318;
    else goto v_21319;
v_21318:
    v_21357 = lisp_true;
    goto v_21317;
v_21319:
    goto v_21334;
v_21330:
    v_21358 = stack[-1];
    goto v_21331;
v_21332:
    v_21357 = elt(env, 12); // ball
    goto v_21333;
v_21334:
    goto v_21330;
v_21331:
    goto v_21332;
v_21333:
    v_21357 = (v_21358 == v_21357 ? lisp_true : nil);
    goto v_21317;
    v_21357 = nil;
v_21317:
    if (v_21357 == nil) goto v_21315;
    v_21357 = lisp_true;
    goto v_21313;
v_21315:
    v_21357 = stack[-1];
    if (!symbolp(v_21357)) v_21357 = nil;
    else { v_21357 = qfastgets(v_21357);
           if (v_21357 != nil) { v_21357 = elt(v_21357, 21); // rl_external
#ifdef RECORD_GET
             if (v_21357 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_21357 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_21357 == SPID_NOPROP) v_21357 = nil; }}
#endif
    goto v_21313;
    v_21357 = nil;
v_21313:
    goto v_21284;
    v_21357 = nil;
v_21284:
    goto v_21197;
    v_21357 = nil;
v_21197:
    goto v_21168;
    v_21357 = nil;
v_21168:
    if (v_21357 == nil) goto v_21166;
    goto v_21351;
v_21345:
    v_21359 = elt(env, 13); // "cl_pnf2():"
    goto v_21346;
v_21347:
    v_21358 = stack[-1];
    goto v_21348;
v_21349:
    v_21357 = elt(env, 14); // "invalid as operator"
    goto v_21350;
v_21351:
    goto v_21345;
v_21346:
    goto v_21347;
v_21348:
    goto v_21349;
v_21350:
    v_21357 = list3(v_21359, v_21358, v_21357);
    env = stack[-2];
    fn = elt(env, 19); // rederr
    v_21357 = (*qfn1(fn))(fn, v_21357);
    goto v_21164;
v_21166:
v_21164:
    v_21357 = stack[0];
    return ncons(v_21357);
    return onevalue(v_21357);
}



// Code for vdp_setsugar

static LispObject CC_vdp_setsugar(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21064, v_21065, v_21066;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21064 = v_21043;
    v_21066 = v_21042;
// end of prologue
    v_21065 = qvalue(elt(env, 1)); // !*cgbsugar
    if (v_21065 == nil) goto v_21047;
    else goto v_21048;
v_21047:
    v_21064 = v_21066;
    goto v_21046;
v_21048:
    goto v_21060;
v_21054:
    goto v_21055;
v_21056:
    v_21065 = elt(env, 2); // sugar
    goto v_21057;
v_21058:
    goto v_21059;
v_21060:
    goto v_21054;
v_21055:
    goto v_21056;
v_21057:
    goto v_21058;
v_21059:
    {
        fn = elt(env, 3); // vdp_putprop
        return (*qfnn(fn))(fn, 3, v_21066, v_21065, v_21064);
    }
    v_21064 = nil;
v_21046:
    return onevalue(v_21064);
}



// Code for setrd

static LispObject CC_setrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21067, v_21068;
    LispObject fn;
    argcheck(nargs, 0, "setrd");
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
    goto v_21052;
v_21048:
    v_21068 = qvalue(elt(env, 1)); // atts
    goto v_21049;
v_21050:
    v_21067 = elt(env, 2); // (type)
    goto v_21051;
v_21052:
    goto v_21048;
v_21049:
    goto v_21050;
v_21051:
    fn = elt(env, 4); // retattributes
    v_21067 = (*qfn2(fn))(fn, v_21068, v_21067);
    env = stack[-2];
    goto v_21062;
v_21056:
    stack[-1] = elt(env, 3); // set
    goto v_21057;
v_21058:
    stack[0] = v_21067;
    goto v_21059;
v_21060:
    fn = elt(env, 5); // stats_getargs
    v_21067 = (*qfnn(fn))(fn, 0);
    goto v_21061;
v_21062:
    goto v_21056;
v_21057:
    goto v_21058;
v_21059:
    goto v_21060;
v_21061:
    {
        LispObject v_21071 = stack[-1];
        LispObject v_21072 = stack[0];
        return list2star(v_21071, v_21072, v_21067);
    }
    return onevalue(v_21067);
}



// Code for collectphysops_reversed

static LispObject CC_collectphysops_reversed(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21110, v_21111;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21043;
    stack[-1] = v_21042;
// end of prologue
    v_21110 = stack[-1];
    if (!consp(v_21110)) goto v_21049;
    else goto v_21050;
v_21049:
    v_21110 = stack[-1];
    fn = elt(env, 1); // physopp
    v_21110 = (*qfn1(fn))(fn, v_21110);
    if (v_21110 == nil) goto v_21055;
    goto v_21063;
v_21059:
    v_21111 = stack[-1];
    goto v_21060;
v_21061:
    v_21110 = stack[0];
    goto v_21062;
v_21063:
    goto v_21059;
v_21060:
    goto v_21061;
v_21062:
    return cons(v_21111, v_21110);
v_21055:
    v_21110 = stack[0];
    goto v_21046;
    goto v_21048;
v_21050:
    v_21110 = stack[-1];
    fn = elt(env, 1); // physopp
    v_21110 = (*qfn1(fn))(fn, v_21110);
    env = stack[-3];
    if (v_21110 == nil) goto v_21070;
    goto v_21078;
v_21074:
    goto v_21084;
v_21080:
    stack[-2] = stack[-1];
    goto v_21081;
v_21082:
    v_21110 = stack[-1];
    fn = elt(env, 2); // collectindices
    v_21110 = (*qfn1(fn))(fn, v_21110);
    env = stack[-3];
    goto v_21083;
v_21084:
    goto v_21080;
v_21081:
    goto v_21082;
v_21083:
    fn = elt(env, 3); // removeindices
    v_21111 = (*qfn2(fn))(fn, stack[-2], v_21110);
    goto v_21075;
v_21076:
    v_21110 = stack[0];
    goto v_21077;
v_21078:
    goto v_21074;
v_21075:
    goto v_21076;
v_21077:
    return cons(v_21111, v_21110);
v_21070:
v_21048:
v_21091:
    v_21110 = stack[-1];
    if (!consp(v_21110)) goto v_21094;
    else goto v_21095;
v_21094:
    goto v_21090;
v_21095:
    goto v_21103;
v_21099:
    v_21110 = stack[-1];
    v_21111 = qcar(v_21110);
    goto v_21100;
v_21101:
    v_21110 = stack[0];
    goto v_21102;
v_21103:
    goto v_21099;
v_21100:
    goto v_21101;
v_21102:
    v_21110 = CC_collectphysops_reversed(elt(env, 0), v_21111, v_21110);
    env = stack[-3];
    stack[0] = v_21110;
    v_21110 = stack[-1];
    v_21110 = qcdr(v_21110);
    stack[-1] = v_21110;
    goto v_21091;
v_21090:
    v_21110 = stack[0];
v_21046:
    return onevalue(v_21110);
}



// Code for evalgreaterp

static LispObject CC_evalgreaterp(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21119, v_21120, v_21121;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21120 = v_21043;
    v_21119 = v_21042;
// end of prologue
    goto v_21053;
v_21047:
    v_21121 = elt(env, 1); // difference
    goto v_21048;
v_21049:
    goto v_21050;
v_21051:
    goto v_21052;
v_21053:
    goto v_21047;
v_21048:
    goto v_21049;
v_21050:
    goto v_21051;
v_21052:
    v_21119 = list3(v_21121, v_21120, v_21119);
    env = stack[-1];
    fn = elt(env, 3); // simp!*
    v_21119 = (*qfn1(fn))(fn, v_21119);
    env = stack[-1];
    stack[0] = v_21119;
    v_21119 = stack[0];
    v_21119 = qcdr(v_21119);
    if (!consp(v_21119)) goto v_21065;
    v_21119 = lisp_true;
    goto v_21063;
v_21065:
    v_21119 = stack[0];
    v_21119 = qcar(v_21119);
    if (!consp(v_21119)) goto v_21073;
    else goto v_21074;
v_21073:
    v_21119 = lisp_true;
    goto v_21072;
v_21074:
    v_21119 = stack[0];
    v_21119 = qcar(v_21119);
    v_21119 = qcar(v_21119);
    v_21119 = (consp(v_21119) ? nil : lisp_true);
    goto v_21072;
    v_21119 = nil;
v_21072:
    v_21119 = (v_21119 == nil ? lisp_true : nil);
    goto v_21063;
    v_21119 = nil;
v_21063:
    if (v_21119 == nil) goto v_21061;
    goto v_21090;
v_21086:
    v_21119 = stack[0];
    v_21119 = qcar(v_21119);
    fn = elt(env, 4); // minusf
    v_21119 = (*qfn1(fn))(fn, v_21119);
    env = stack[-1];
    if (v_21119 == nil) goto v_21095;
    v_21119 = stack[0];
    fn = elt(env, 5); // negsq
    v_21119 = (*qfn1(fn))(fn, v_21119);
    env = stack[-1];
    goto v_21093;
v_21095:
    v_21119 = stack[0];
    goto v_21093;
    v_21119 = nil;
v_21093:
    fn = elt(env, 6); // mk!*sq
    v_21120 = (*qfn1(fn))(fn, v_21119);
    env = stack[-1];
    goto v_21087;
v_21088:
    v_21119 = elt(env, 2); // "number"
    goto v_21089;
v_21090:
    goto v_21086;
v_21087:
    goto v_21088;
v_21089:
    {
        fn = elt(env, 7); // typerr
        return (*qfn2(fn))(fn, v_21120, v_21119);
    }
v_21061:
    v_21119 = stack[0];
    v_21119 = qcar(v_21119);
    if (v_21119 == nil) goto v_21109;
    else goto v_21110;
v_21109:
    v_21119 = nil;
    goto v_21108;
v_21110:
    v_21119 = stack[0];
    v_21119 = qcar(v_21119);
    {
        fn = elt(env, 8); // !:minusp
        return (*qfn1(fn))(fn, v_21119);
    }
    v_21119 = nil;
v_21108:
    goto v_21059;
    v_21119 = nil;
v_21059:
    return onevalue(v_21119);
}



// Code for subcare

static LispObject CC_subcare(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21124, v_21125, v_21126;
    LispObject fn;
    LispObject v_21044, v_21043, v_21042;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "subcare");
    va_start(aa, nargs);
    v_21042 = va_arg(aa, LispObject);
    v_21043 = va_arg(aa, LispObject);
    v_21044 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21044,v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21042,v_21043,v_21044);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_21044;
    stack[-1] = v_21043;
    stack[-2] = v_21042;
// end of prologue
    stack[-3] = nil;
v_21049:
    v_21124 = stack[0];
    if (v_21124 == nil) goto v_21052;
    else goto v_21053;
v_21052:
    v_21124 = stack[-3];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_21124);
    }
v_21053:
    goto v_21063;
v_21059:
    v_21125 = stack[-2];
    goto v_21060;
v_21061:
    v_21124 = stack[0];
    goto v_21062;
v_21063:
    goto v_21059;
v_21060:
    goto v_21061;
v_21062:
    if (equal(v_21125, v_21124)) goto v_21057;
    else goto v_21058;
v_21057:
    goto v_21071;
v_21067:
    v_21125 = stack[-3];
    goto v_21068;
v_21069:
    v_21124 = stack[-1];
    goto v_21070;
v_21071:
    goto v_21067;
v_21068:
    goto v_21069;
v_21070:
    {
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_21125, v_21124);
    }
v_21058:
    v_21124 = stack[0];
    if (!consp(v_21124)) goto v_21078;
    else goto v_21079;
v_21078:
    v_21124 = lisp_true;
    goto v_21077;
v_21079:
    goto v_21089;
v_21085:
    v_21124 = stack[0];
    v_21125 = qcar(v_21124);
    goto v_21086;
v_21087:
    v_21124 = elt(env, 1); // subfunc
    goto v_21088;
v_21089:
    goto v_21085;
v_21086:
    goto v_21087;
v_21088:
    v_21124 = get(v_21125, v_21124);
    env = stack[-4];
    goto v_21077;
    v_21124 = nil;
v_21077:
    if (v_21124 == nil) goto v_21075;
    goto v_21098;
v_21094:
    v_21125 = stack[-3];
    goto v_21095;
v_21096:
    v_21124 = stack[0];
    goto v_21097;
v_21098:
    goto v_21094;
v_21095:
    goto v_21096;
v_21097:
    {
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_21125, v_21124);
    }
v_21075:
    goto v_21108;
v_21104:
    goto v_21116;
v_21110:
    v_21126 = stack[-2];
    goto v_21111;
v_21112:
    v_21125 = stack[-1];
    goto v_21113;
v_21114:
    v_21124 = stack[0];
    v_21124 = qcar(v_21124);
    goto v_21115;
v_21116:
    goto v_21110;
v_21111:
    goto v_21112;
v_21113:
    goto v_21114;
v_21115:
    v_21125 = CC_subcare(elt(env, 0), 3, v_21126, v_21125, v_21124);
    env = stack[-4];
    goto v_21105;
v_21106:
    v_21124 = stack[-3];
    goto v_21107;
v_21108:
    goto v_21104;
v_21105:
    goto v_21106;
v_21107:
    v_21124 = cons(v_21125, v_21124);
    env = stack[-4];
    stack[-3] = v_21124;
    v_21124 = stack[0];
    v_21124 = qcdr(v_21124);
    stack[0] = v_21124;
    goto v_21049;
    v_21124 = nil;
    return onevalue(v_21124);
}



// Code for fs!:make!-nullangle

static LispObject CC_fsTmakeKnullangle(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21080, v_21081, v_21082;
    argcheck(nargs, 0, "fs:make-nullangle");
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
    v_21080 = (LispObject)112+TAG_FIXNUM; // 7
    v_21080 = Lmkvect(nil, v_21080);
    env = stack[-2];
    stack[-1] = v_21080;
    v_21080 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_21080;
v_21051:
    goto v_21063;
v_21059:
    v_21081 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_21060;
v_21061:
    v_21080 = stack[0];
    goto v_21062;
v_21063:
    goto v_21059;
v_21060:
    goto v_21061;
v_21062:
    v_21080 = difference2(v_21081, v_21080);
    env = stack[-2];
    v_21080 = Lminusp(nil, v_21080);
    env = stack[-2];
    if (v_21080 == nil) goto v_21056;
    goto v_21050;
v_21056:
    goto v_21073;
v_21067:
    v_21082 = stack[-1];
    goto v_21068;
v_21069:
    v_21081 = stack[0];
    goto v_21070;
v_21071:
    v_21080 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21072;
v_21073:
    goto v_21067;
v_21068:
    goto v_21069;
v_21070:
    goto v_21071;
v_21072:
    *(LispObject *)((char *)v_21082 + (CELL-TAG_VECTOR) + (((intptr_t)v_21081-TAG_FIXNUM)/(16/CELL))) = v_21080;
    v_21080 = stack[0];
    v_21080 = add1(v_21080);
    env = stack[-2];
    stack[0] = v_21080;
    goto v_21051;
v_21050:
    v_21080 = stack[-1];
    return onevalue(v_21080);
}



// Code for ratlessp

static LispObject CC_ratlessp(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21061, v_21062;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
// copy arguments values to proper place
    v_21061 = v_21043;
    v_21062 = v_21042;
// end of prologue
    goto v_21050;
v_21046:
    goto v_21056;
v_21052:
    goto v_21053;
v_21054:
    goto v_21055;
v_21056:
    goto v_21052;
v_21053:
    goto v_21054;
v_21055:
    fn = elt(env, 1); // ratdif
    v_21061 = (*qfn2(fn))(fn, v_21062, v_21061);
    v_21062 = qcar(v_21061);
    goto v_21047;
v_21048:
    v_21061 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21049;
v_21050:
    goto v_21046;
v_21047:
    goto v_21048;
v_21049:
        return Llessp(nil, v_21062, v_21061);
}



// Code for giplus!:

static LispObject CC_giplusT(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21075, v_21076;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21043;
    stack[-1] = v_21042;
// end of prologue
    goto v_21050;
v_21046:
    goto v_21056;
v_21052:
    v_21075 = stack[-1];
    v_21075 = qcdr(v_21075);
    v_21076 = qcar(v_21075);
    goto v_21053;
v_21054:
    v_21075 = stack[0];
    v_21075 = qcdr(v_21075);
    v_21075 = qcar(v_21075);
    goto v_21055;
v_21056:
    goto v_21052;
v_21053:
    goto v_21054;
v_21055:
    stack[-2] = plus2(v_21076, v_21075);
    env = stack[-3];
    goto v_21047;
v_21048:
    goto v_21068;
v_21064:
    v_21075 = stack[-1];
    v_21075 = qcdr(v_21075);
    v_21076 = qcdr(v_21075);
    goto v_21065;
v_21066:
    v_21075 = stack[0];
    v_21075 = qcdr(v_21075);
    v_21075 = qcdr(v_21075);
    goto v_21067;
v_21068:
    goto v_21064;
v_21065:
    goto v_21066;
v_21067:
    v_21075 = plus2(v_21076, v_21075);
    env = stack[-3];
    goto v_21049;
v_21050:
    goto v_21046;
v_21047:
    goto v_21048;
v_21049:
    {
        LispObject v_21080 = stack[-2];
        fn = elt(env, 1); // mkgi
        return (*qfn2(fn))(fn, v_21080, v_21075);
    }
}



// Code for multivariatep

static LispObject CC_multivariatep(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21094, v_21095;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21043;
    stack[-1] = v_21042;
// end of prologue
v_21047:
    v_21094 = stack[-1];
    if (!consp(v_21094)) goto v_21054;
    else goto v_21055;
v_21054:
    v_21094 = lisp_true;
    goto v_21053;
v_21055:
    v_21094 = stack[-1];
    v_21094 = qcar(v_21094);
    v_21094 = (consp(v_21094) ? nil : lisp_true);
    goto v_21053;
    v_21094 = nil;
v_21053:
    if (v_21094 == nil) goto v_21051;
    v_21094 = nil;
    goto v_21046;
v_21051:
    goto v_21070;
v_21066:
    v_21094 = stack[-1];
    v_21094 = qcar(v_21094);
    v_21094 = qcar(v_21094);
    v_21095 = qcar(v_21094);
    goto v_21067;
v_21068:
    v_21094 = stack[0];
    goto v_21069;
v_21070:
    goto v_21066;
v_21067:
    goto v_21068;
v_21069:
    if (v_21095 == v_21094) goto v_21065;
    v_21094 = lisp_true;
    goto v_21046;
v_21065:
    goto v_21084;
v_21080:
    v_21094 = stack[-1];
    v_21094 = qcar(v_21094);
    v_21095 = qcdr(v_21094);
    goto v_21081;
v_21082:
    v_21094 = stack[0];
    goto v_21083;
v_21084:
    goto v_21080;
v_21081:
    goto v_21082;
v_21083:
    v_21094 = CC_multivariatep(elt(env, 0), v_21095, v_21094);
    env = stack[-2];
    if (v_21094 == nil) goto v_21078;
    v_21094 = lisp_true;
    goto v_21046;
v_21078:
    v_21094 = stack[-1];
    v_21094 = qcdr(v_21094);
    stack[-1] = v_21094;
    goto v_21047;
    v_21094 = nil;
v_21046:
    return onevalue(v_21094);
}



// Code for rl_qefsolset

static LispObject CC_rl_qefsolset(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21076, v_21077, v_21078, v_21079, v_21080;
    LispObject fn;
    LispObject v_21046, v_21045, v_21044, v_21043, v_21042;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "rl_qefsolset");
    va_start(aa, nargs);
    v_21042 = va_arg(aa, LispObject);
    v_21043 = va_arg(aa, LispObject);
    v_21044 = va_arg(aa, LispObject);
    v_21045 = va_arg(aa, LispObject);
    v_21046 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_21046,v_21045,v_21044,v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_21042,v_21043,v_21044,v_21045,v_21046);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_21076 = v_21046;
    v_21077 = v_21045;
    v_21078 = v_21044;
    v_21079 = v_21043;
    v_21080 = v_21042;
// end of prologue
    goto v_21053;
v_21049:
    stack[-3] = qvalue(elt(env, 1)); // rl_qefsolset!*
    goto v_21050;
v_21051:
    goto v_21064;
v_21056:
    stack[-2] = v_21080;
    goto v_21057;
v_21058:
    stack[-1] = v_21079;
    goto v_21059;
v_21060:
    stack[0] = v_21078;
    goto v_21061;
v_21062:
    goto v_21073;
v_21069:
    goto v_21070;
v_21071:
    goto v_21072;
v_21073:
    goto v_21069;
v_21070:
    goto v_21071;
v_21072:
    v_21076 = list2(v_21077, v_21076);
    env = stack[-4];
    goto v_21063;
v_21064:
    goto v_21056;
v_21057:
    goto v_21058;
v_21059:
    goto v_21060;
v_21061:
    goto v_21062;
v_21063:
    v_21076 = list3star(stack[-2], stack[-1], stack[0], v_21076);
    env = stack[-4];
    goto v_21052;
v_21053:
    goto v_21049;
v_21050:
    goto v_21051;
v_21052:
    {
        LispObject v_21085 = stack[-3];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_21085, v_21076);
    }
}



// Code for sfto_b!:extadd

static LispObject CC_sfto_bTextadd(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21176, v_21177, v_21178;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_21043;
    stack[-2] = v_21042;
// end of prologue
    stack[0] = nil;
v_21048:
    v_21176 = stack[-2];
    if (v_21176 == nil) goto v_21051;
    else goto v_21052;
v_21051:
    goto v_21059;
v_21055:
    v_21177 = stack[0];
    goto v_21056;
v_21057:
    v_21176 = stack[-1];
    goto v_21058;
v_21059:
    goto v_21055;
v_21056:
    goto v_21057;
v_21058:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_21177, v_21176);
    }
v_21052:
    v_21176 = stack[-1];
    if (v_21176 == nil) goto v_21062;
    else goto v_21063;
v_21062:
    goto v_21070;
v_21066:
    v_21177 = stack[0];
    goto v_21067;
v_21068:
    v_21176 = stack[-2];
    goto v_21069;
v_21070:
    goto v_21066;
v_21067:
    goto v_21068;
v_21069:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_21177, v_21176);
    }
v_21063:
    goto v_21079;
v_21075:
    v_21176 = stack[-2];
    v_21176 = qcar(v_21176);
    v_21177 = qcar(v_21176);
    goto v_21076;
v_21077:
    v_21176 = stack[-1];
    v_21176 = qcar(v_21176);
    v_21176 = qcar(v_21176);
    goto v_21078;
v_21079:
    goto v_21075;
v_21076:
    goto v_21077;
v_21078:
    if (equal(v_21177, v_21176)) goto v_21073;
    else goto v_21074;
v_21073:
    goto v_21091;
v_21087:
    stack[-3] = stack[0];
    goto v_21088;
v_21089:
    goto v_21098;
v_21094:
    v_21176 = stack[-2];
    v_21176 = qcar(v_21176);
    v_21177 = qcdr(v_21176);
    goto v_21095;
v_21096:
    v_21176 = stack[-1];
    v_21176 = qcar(v_21176);
    v_21176 = qcdr(v_21176);
    goto v_21097;
v_21098:
    goto v_21094;
v_21095:
    goto v_21096;
v_21097:
    fn = elt(env, 2); // addf
    stack[0] = (*qfn2(fn))(fn, v_21177, v_21176);
    env = stack[-4];
    goto v_21110;
v_21106:
    v_21176 = stack[-2];
    v_21177 = qcdr(v_21176);
    goto v_21107;
v_21108:
    v_21176 = stack[-1];
    v_21176 = qcdr(v_21176);
    goto v_21109;
v_21110:
    goto v_21106;
v_21107:
    goto v_21108;
v_21109:
    v_21176 = CC_sfto_bTextadd(elt(env, 0), v_21177, v_21176);
    env = stack[-4];
    v_21177 = stack[0];
    v_21178 = v_21177;
    if (v_21178 == nil) goto v_21119;
    else goto v_21120;
v_21119:
    goto v_21118;
v_21120:
    goto v_21132;
v_21126:
    v_21178 = stack[-2];
    v_21178 = qcar(v_21178);
    v_21178 = qcar(v_21178);
    goto v_21127;
v_21128:
    goto v_21129;
v_21130:
    goto v_21131;
v_21132:
    goto v_21126;
v_21127:
    goto v_21128;
v_21129:
    goto v_21130;
v_21131:
    v_21176 = acons(v_21178, v_21177, v_21176);
    env = stack[-4];
    goto v_21118;
    v_21176 = nil;
v_21118:
    goto v_21090;
v_21091:
    goto v_21087;
v_21088:
    goto v_21089;
v_21090:
    {
        LispObject v_21183 = stack[-3];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_21183, v_21176);
    }
v_21074:
    goto v_21145;
v_21141:
    v_21176 = stack[-2];
    v_21176 = qcar(v_21176);
    v_21177 = qcar(v_21176);
    goto v_21142;
v_21143:
    v_21176 = stack[-1];
    v_21176 = qcar(v_21176);
    v_21176 = qcar(v_21176);
    goto v_21144;
v_21145:
    goto v_21141;
v_21142:
    goto v_21143;
v_21144:
    fn = elt(env, 3); // sfto_b!:ordexp
    v_21176 = (*qfn2(fn))(fn, v_21177, v_21176);
    env = stack[-4];
    if (v_21176 == nil) goto v_21139;
    goto v_21157;
v_21153:
    v_21176 = stack[-2];
    v_21177 = qcar(v_21176);
    goto v_21154;
v_21155:
    v_21176 = stack[0];
    goto v_21156;
v_21157:
    goto v_21153;
v_21154:
    goto v_21155;
v_21156:
    v_21176 = cons(v_21177, v_21176);
    env = stack[-4];
    stack[0] = v_21176;
    v_21176 = stack[-2];
    v_21176 = qcdr(v_21176);
    stack[-2] = v_21176;
    goto v_21048;
v_21139:
    goto v_21170;
v_21166:
    v_21176 = stack[-1];
    v_21177 = qcar(v_21176);
    goto v_21167;
v_21168:
    v_21176 = stack[0];
    goto v_21169;
v_21170:
    goto v_21166;
v_21167:
    goto v_21168;
v_21169:
    v_21176 = cons(v_21177, v_21176);
    env = stack[-4];
    stack[0] = v_21176;
    v_21176 = stack[-1];
    v_21176 = qcdr(v_21176);
    stack[-1] = v_21176;
    goto v_21048;
    v_21176 = nil;
    return onevalue(v_21176);
}



// Code for bvarom

static LispObject CC_bvarom(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21074, v_21075;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21042;
// end of prologue
    v_21074 = stack[0];
    v_21074 = qcar(v_21074);
    v_21074 = Lconsp(nil, v_21074);
    env = stack[-1];
    if (v_21074 == nil) goto v_21049;
    goto v_21061;
v_21057:
    v_21074 = stack[0];
    v_21074 = qcar(v_21074);
    v_21075 = qcar(v_21074);
    goto v_21058;
v_21059:
    v_21074 = elt(env, 1); // bvar
    goto v_21060;
v_21061:
    goto v_21057;
v_21058:
    goto v_21059;
v_21060:
    if (v_21075 == v_21074) goto v_21055;
    else goto v_21056;
v_21055:
    v_21074 = stack[0];
    v_21074 = qcar(v_21074);
    v_21074 = qcdr(v_21074);
    v_21074 = qcar(v_21074);
    fn = elt(env, 2); // objectom
    v_21074 = (*qfn1(fn))(fn, v_21074);
    env = stack[-1];
    v_21074 = stack[0];
    v_21074 = qcdr(v_21074);
    v_21074 = CC_bvarom(elt(env, 0), v_21074);
    goto v_21054;
v_21056:
v_21054:
    goto v_21047;
v_21049:
v_21047:
    v_21074 = nil;
    return onevalue(v_21074);
}



// Code for degreef

static LispObject CC_degreef(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21104, v_21105;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21043;
    stack[-1] = v_21042;
// end of prologue
    v_21104 = stack[-1];
    if (!consp(v_21104)) goto v_21051;
    else goto v_21052;
v_21051:
    v_21104 = lisp_true;
    goto v_21050;
v_21052:
    v_21104 = stack[-1];
    v_21104 = qcar(v_21104);
    v_21104 = (consp(v_21104) ? nil : lisp_true);
    goto v_21050;
    v_21104 = nil;
v_21050:
    if (v_21104 == nil) goto v_21048;
    v_21104 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21046;
v_21048:
    goto v_21067;
v_21063:
    v_21104 = stack[-1];
    v_21104 = qcar(v_21104);
    v_21104 = qcar(v_21104);
    v_21105 = qcar(v_21104);
    goto v_21064;
v_21065:
    v_21104 = stack[0];
    goto v_21066;
v_21067:
    goto v_21063;
v_21064:
    goto v_21065;
v_21066:
    if (v_21105 == v_21104) goto v_21061;
    else goto v_21062;
v_21061:
    v_21104 = stack[-1];
    v_21104 = qcar(v_21104);
    v_21104 = qcar(v_21104);
    v_21104 = qcdr(v_21104);
    goto v_21046;
v_21062:
    goto v_21084;
v_21080:
    goto v_21090;
v_21086:
    v_21104 = stack[-1];
    v_21104 = qcar(v_21104);
    v_21105 = qcdr(v_21104);
    goto v_21087;
v_21088:
    v_21104 = stack[0];
    goto v_21089;
v_21090:
    goto v_21086;
v_21087:
    goto v_21088;
v_21089:
    stack[-2] = CC_degreef(elt(env, 0), v_21105, v_21104);
    env = stack[-3];
    goto v_21081;
v_21082:
    goto v_21100;
v_21096:
    v_21104 = stack[-1];
    v_21105 = qcdr(v_21104);
    goto v_21097;
v_21098:
    v_21104 = stack[0];
    goto v_21099;
v_21100:
    goto v_21096;
v_21097:
    goto v_21098;
v_21099:
    v_21104 = CC_degreef(elt(env, 0), v_21105, v_21104);
    env = stack[-3];
    goto v_21083;
v_21084:
    goto v_21080;
v_21081:
    goto v_21082;
v_21083:
    {
        LispObject v_21109 = stack[-2];
        fn = elt(env, 1); // max
        return (*qfn2(fn))(fn, v_21109, v_21104);
    }
    v_21104 = nil;
v_21046:
    return onevalue(v_21104);
}



// Code for r2findindex1

static LispObject CC_r2findindex1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21073, v_21074, v_21075;
    LispObject fn;
    LispObject v_21044, v_21043, v_21042;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "r2findindex1");
    va_start(aa, nargs);
    v_21042 = va_arg(aa, LispObject);
    v_21043 = va_arg(aa, LispObject);
    v_21044 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21044,v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21042,v_21043,v_21044);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_21074 = v_21044;
    stack[0] = v_21043;
    stack[-1] = v_21042;
// end of prologue
v_21048:
    v_21073 = stack[0];
    if (v_21073 == nil) goto v_21051;
    else goto v_21052;
v_21051:
    v_21073 = elt(env, 1); // "index not found"
    {
        fn = elt(env, 2); // rederr
        return (*qfn1(fn))(fn, v_21073);
    }
v_21052:
    goto v_21062;
v_21058:
    v_21075 = stack[-1];
    goto v_21059;
v_21060:
    v_21073 = stack[0];
    v_21073 = qcar(v_21073);
    goto v_21061;
v_21062:
    goto v_21058;
v_21059:
    goto v_21060;
v_21061:
    if (equal(v_21075, v_21073)) goto v_21056;
    else goto v_21057;
v_21056:
    v_21073 = v_21074;
    goto v_21047;
v_21057:
    v_21073 = stack[0];
    v_21073 = qcdr(v_21073);
    stack[0] = v_21073;
    v_21073 = v_21074;
    v_21073 = add1(v_21073);
    env = stack[-2];
    v_21074 = v_21073;
    goto v_21048;
    v_21073 = nil;
v_21047:
    return onevalue(v_21073);
}



// Code for apply_e

static LispObject CC_apply_e(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21062, v_21063;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21062 = v_21042;
// end of prologue
    goto v_21053;
v_21049:
    v_21063 = v_21062;
    goto v_21050;
v_21051:
    v_21062 = nil;
    goto v_21052;
v_21053:
    goto v_21049;
v_21050:
    goto v_21051;
v_21052:
    fn = elt(env, 2); // apply
    v_21063 = (*qfn2(fn))(fn, v_21063, v_21062);
    env = stack[0];
    v_21062 = v_21063;
    v_21063 = integerp(v_21063);
    if (v_21063 == nil) goto v_21047;
    goto v_21045;
v_21047:
    v_21062 = elt(env, 1); // "randpoly expons function must return an integer"
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_21062);
    }
    v_21062 = nil;
v_21045:
    return onevalue(v_21062);
}



// Code for sqprint

static LispObject CC_sqprint(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21182, v_21183, v_21184;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_21042;
// end of prologue
// Binding !*prin!#
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-3, 1, 0);
    qvalue(elt(env, 1)) = nil; // !*prin!#
    v_21182 = lisp_true;
    qvalue(elt(env, 1)) = v_21182; // !*prin!#
    v_21182 = qvalue(elt(env, 2)); // orig!*
    stack[-2] = v_21182;
    v_21182 = qvalue(elt(env, 3)); // !*nat
    if (v_21182 == nil) goto v_21054;
    goto v_21063;
v_21059:
    v_21183 = qvalue(elt(env, 4)); // posn!*
    goto v_21060;
v_21061:
    v_21182 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_21062;
v_21063:
    goto v_21059;
v_21060:
    goto v_21061;
v_21062:
    v_21182 = (LispObject)lessp2(v_21183, v_21182);
    v_21182 = v_21182 ? lisp_true : nil;
    env = stack[-3];
    if (v_21182 == nil) goto v_21054;
    v_21182 = qvalue(elt(env, 4)); // posn!*
    qvalue(elt(env, 2)) = v_21182; // orig!*
    goto v_21052;
v_21054:
v_21052:
    v_21182 = qvalue(elt(env, 5)); // !*pri
    if (v_21182 == nil) goto v_21071;
    else goto v_21069;
v_21071:
    v_21182 = qvalue(elt(env, 6)); // wtl!*
    if (v_21182 == nil) goto v_21073;
    else goto v_21069;
v_21073:
    goto v_21070;
v_21069:
    v_21182 = stack[-1];
    fn = elt(env, 8); // sqhorner!*
    v_21182 = (*qfn1(fn))(fn, v_21182);
    env = stack[-3];
    fn = elt(env, 9); // prepsq!*
    v_21182 = (*qfn1(fn))(fn, v_21182);
    env = stack[-3];
    fn = elt(env, 10); // prepreform
    v_21182 = (*qfn1(fn))(fn, v_21182);
    env = stack[-3];
    fn = elt(env, 11); // maprin
    v_21182 = (*qfn1(fn))(fn, v_21182);
    env = stack[-3];
    goto v_21068;
v_21070:
    goto v_21086;
v_21082:
    v_21182 = stack[-1];
    v_21183 = qcdr(v_21182);
    goto v_21083;
v_21084:
    v_21182 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21085;
v_21086:
    goto v_21082;
v_21083:
    goto v_21084;
v_21085:
    if (v_21183 == v_21182) goto v_21081;
    v_21182 = stack[-1];
    v_21182 = qcar(v_21182);
    if (!consp(v_21182)) goto v_21096;
    else goto v_21097;
v_21096:
    v_21182 = lisp_true;
    goto v_21095;
v_21097:
    v_21182 = stack[-1];
    v_21182 = qcar(v_21182);
    v_21182 = qcar(v_21182);
    v_21182 = (consp(v_21182) ? nil : lisp_true);
    goto v_21095;
    v_21182 = nil;
v_21095:
    if (v_21182 == nil) goto v_21092;
    else goto v_21093;
v_21092:
    v_21182 = stack[-1];
    v_21182 = qcar(v_21182);
    v_21182 = qcdr(v_21182);
    goto v_21091;
v_21093:
    v_21182 = nil;
    goto v_21091;
    v_21182 = nil;
v_21091:
    goto v_21120;
v_21114:
    v_21183 = stack[-1];
    v_21184 = qcar(v_21183);
    goto v_21115;
v_21116:
    v_21183 = v_21182;
    goto v_21117;
v_21118:
    v_21182 = nil;
    goto v_21119;
v_21120:
    goto v_21114;
v_21115:
    goto v_21116;
v_21117:
    goto v_21118;
v_21119:
    fn = elt(env, 12); // xprinf
    v_21182 = (*qfnn(fn))(fn, 3, v_21184, v_21183, v_21182);
    env = stack[-3];
    v_21182 = elt(env, 7); // " / "
    fn = elt(env, 13); // prin2!*
    v_21182 = (*qfn1(fn))(fn, v_21182);
    env = stack[-3];
    v_21182 = stack[-1];
    v_21182 = qcdr(v_21182);
    if (!consp(v_21182)) goto v_21133;
    else goto v_21134;
v_21133:
    v_21182 = lisp_true;
    goto v_21132;
v_21134:
    v_21182 = stack[-1];
    v_21182 = qcdr(v_21182);
    v_21182 = qcar(v_21182);
    v_21182 = (consp(v_21182) ? nil : lisp_true);
    goto v_21132;
    v_21182 = nil;
v_21132:
    if (v_21182 == nil) goto v_21129;
    else goto v_21130;
v_21129:
    v_21182 = stack[-1];
    v_21182 = qcdr(v_21182);
    v_21182 = qcdr(v_21182);
    if (v_21182 == nil) goto v_21146;
    else goto v_21145;
v_21146:
    goto v_21155;
v_21151:
    v_21182 = stack[-1];
    v_21182 = qcdr(v_21182);
    v_21182 = qcar(v_21182);
    v_21183 = qcdr(v_21182);
    goto v_21152;
v_21153:
    v_21182 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21154;
v_21155:
    goto v_21151;
v_21152:
    goto v_21153;
v_21154:
    v_21182 = Lneq(nil, v_21183, v_21182);
    env = stack[-3];
v_21145:
    goto v_21128;
v_21130:
    v_21182 = nil;
    goto v_21128;
    v_21182 = nil;
v_21128:
    goto v_21171;
v_21165:
    v_21183 = stack[-1];
    v_21184 = qcdr(v_21183);
    goto v_21166;
v_21167:
    v_21183 = v_21182;
    goto v_21168;
v_21169:
    v_21182 = nil;
    goto v_21170;
v_21171:
    goto v_21165;
v_21166:
    goto v_21167;
v_21168:
    goto v_21169;
v_21170:
    fn = elt(env, 12); // xprinf
    v_21182 = (*qfnn(fn))(fn, 3, v_21184, v_21183, v_21182);
    env = stack[-3];
    goto v_21068;
v_21081:
    v_21182 = stack[-1];
    v_21182 = qcar(v_21182);
    fn = elt(env, 14); // xprinf2
    v_21182 = (*qfn1(fn))(fn, v_21182);
    env = stack[-3];
    goto v_21068;
v_21068:
    v_21182 = stack[-2];
    qvalue(elt(env, 2)) = v_21182; // orig!*
    ;}  // end of a binding scope
    return onevalue(v_21182);
}



// Code for reduce!-eival!-powers

static LispObject CC_reduceKeivalKpowers(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21106, v_21107, v_21108, v_21109;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21108 = v_21043;
    v_21109 = v_21042;
// end of prologue
    v_21106 = v_21108;
    if (!consp(v_21106)) goto v_21055;
    else goto v_21056;
v_21055:
    v_21106 = lisp_true;
    goto v_21054;
v_21056:
    v_21106 = v_21108;
    v_21106 = qcar(v_21106);
    v_21106 = (consp(v_21106) ? nil : lisp_true);
    goto v_21054;
    v_21106 = nil;
v_21054:
    if (v_21106 == nil) goto v_21052;
    v_21106 = lisp_true;
    goto v_21050;
v_21052:
    goto v_21071;
v_21067:
    v_21106 = v_21108;
    v_21106 = qcar(v_21106);
    v_21106 = qcar(v_21106);
    v_21107 = qcar(v_21106);
    goto v_21068;
v_21069:
    v_21106 = v_21109;
    v_21106 = qcar(v_21106);
    v_21106 = qcar(v_21106);
    goto v_21070;
v_21071:
    goto v_21067;
v_21068:
    goto v_21069;
v_21070:
    v_21106 = (v_21107 == v_21106 ? lisp_true : nil);
    v_21106 = (v_21106 == nil ? lisp_true : nil);
    goto v_21050;
    v_21106 = nil;
v_21050:
    if (v_21106 == nil) goto v_21048;
    goto v_21086;
v_21082:
    v_21107 = v_21108;
    goto v_21083;
v_21084:
    v_21106 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21085;
v_21086:
    goto v_21082;
v_21083:
    goto v_21084;
v_21085:
    return cons(v_21107, v_21106);
v_21048:
    goto v_21096;
v_21092:
    stack[0] = v_21109;
    goto v_21093;
v_21094:
    goto v_21103;
v_21099:
    v_21107 = v_21108;
    goto v_21100;
v_21101:
    v_21106 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21102;
v_21103:
    goto v_21099;
v_21100:
    goto v_21101;
v_21102:
    v_21106 = cons(v_21107, v_21106);
    env = stack[-1];
    goto v_21095;
v_21096:
    goto v_21092;
v_21093:
    goto v_21094;
v_21095:
    {
        LispObject v_21111 = stack[0];
        fn = elt(env, 1); // reduce!-eival!-powers1
        return (*qfn2(fn))(fn, v_21111, v_21106);
    }
    v_21106 = nil;
    return onevalue(v_21106);
}



// Code for make!-image

static LispObject CC_makeKimage(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21127, v_21128, v_21129;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21043;
    stack[-1] = v_21042;
// end of prologue
    v_21127 = stack[-1];
    if (!consp(v_21127)) goto v_21051;
    else goto v_21052;
v_21051:
    v_21127 = lisp_true;
    goto v_21050;
v_21052:
    v_21127 = stack[-1];
    v_21127 = qcar(v_21127);
    v_21127 = (consp(v_21127) ? nil : lisp_true);
    goto v_21050;
    v_21127 = nil;
v_21050:
    if (v_21127 == nil) goto v_21048;
    v_21127 = stack[-1];
    goto v_21046;
v_21048:
    goto v_21067;
v_21063:
    v_21127 = stack[-1];
    v_21127 = qcar(v_21127);
    v_21127 = qcar(v_21127);
    v_21128 = qcar(v_21127);
    goto v_21064;
v_21065:
    v_21127 = qvalue(elt(env, 1)); // m!-image!-variable
    goto v_21066;
v_21067:
    goto v_21063;
v_21064:
    goto v_21065;
v_21066:
    if (equal(v_21128, v_21127)) goto v_21061;
    else goto v_21062;
v_21061:
    goto v_21079;
v_21075:
    v_21127 = stack[-1];
    v_21127 = qcar(v_21127);
    v_21128 = qcdr(v_21127);
    goto v_21076;
v_21077:
    v_21127 = stack[0];
    goto v_21078;
v_21079:
    goto v_21075;
v_21076:
    goto v_21077;
v_21078:
    fn = elt(env, 2); // evaluate!-in!-order
    v_21127 = (*qfn2(fn))(fn, v_21128, v_21127);
    env = stack[-3];
    fn = elt(env, 3); // !*n2f
    stack[-2] = (*qfn1(fn))(fn, v_21127);
    env = stack[-3];
    goto v_21089;
v_21085:
    v_21127 = stack[-1];
    v_21128 = qcdr(v_21127);
    goto v_21086;
v_21087:
    v_21127 = stack[0];
    goto v_21088;
v_21089:
    goto v_21085;
v_21086:
    goto v_21087;
v_21088:
    v_21127 = CC_makeKimage(elt(env, 0), v_21128, v_21127);
    v_21128 = stack[-2];
    v_21129 = v_21128;
    if (v_21129 == nil) goto v_21097;
    else goto v_21098;
v_21097:
    goto v_21096;
v_21098:
    goto v_21110;
v_21104:
    v_21129 = stack[-1];
    v_21129 = qcar(v_21129);
    v_21129 = qcar(v_21129);
    goto v_21105;
v_21106:
    goto v_21107;
v_21108:
    goto v_21109;
v_21110:
    goto v_21104;
v_21105:
    goto v_21106;
v_21107:
    goto v_21108;
v_21109:
    return acons(v_21129, v_21128, v_21127);
    v_21127 = nil;
v_21096:
    goto v_21046;
v_21062:
    goto v_21124;
v_21120:
    v_21128 = stack[-1];
    goto v_21121;
v_21122:
    v_21127 = stack[0];
    goto v_21123;
v_21124:
    goto v_21120;
v_21121:
    goto v_21122;
v_21123:
    fn = elt(env, 2); // evaluate!-in!-order
    v_21127 = (*qfn2(fn))(fn, v_21128, v_21127);
    env = stack[-3];
    {
        fn = elt(env, 3); // !*n2f
        return (*qfn1(fn))(fn, v_21127);
    }
    v_21127 = nil;
v_21046:
    return onevalue(v_21127);
}



// Code for freeoflist

static LispObject CC_freeoflist(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21070, v_21071;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21043;
    stack[-1] = v_21042;
// end of prologue
v_21047:
    v_21070 = stack[0];
    if (v_21070 == nil) goto v_21050;
    else goto v_21051;
v_21050:
    v_21070 = lisp_true;
    goto v_21046;
v_21051:
    goto v_21061;
v_21057:
    v_21071 = stack[-1];
    goto v_21058;
v_21059:
    v_21070 = stack[0];
    v_21070 = qcar(v_21070);
    goto v_21060;
v_21061:
    goto v_21057;
v_21058:
    goto v_21059;
v_21060:
    fn = elt(env, 1); // freeof
    v_21070 = (*qfn2(fn))(fn, v_21071, v_21070);
    env = stack[-2];
    if (v_21070 == nil) goto v_21055;
    v_21070 = stack[0];
    v_21070 = qcdr(v_21070);
    stack[0] = v_21070;
    goto v_21047;
v_21055:
    v_21070 = nil;
    goto v_21046;
    v_21070 = nil;
v_21046:
    return onevalue(v_21070);
}



// Code for ofsf_sippsubst1

static LispObject CC_ofsf_sippsubst1(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21075, v_21076, v_21077;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21076 = v_21043;
    v_21077 = v_21042;
// end of prologue
    goto v_21052;
v_21046:
    v_21075 = v_21077;
    if (!consp(v_21075)) goto v_21055;
    else goto v_21056;
v_21055:
    v_21075 = v_21077;
    stack[0] = v_21075;
    goto v_21054;
v_21056:
    v_21075 = v_21077;
    v_21075 = qcar(v_21075);
    stack[0] = v_21075;
    goto v_21054;
    stack[0] = nil;
v_21054:
    goto v_21047;
v_21048:
    goto v_21068;
v_21064:
    v_21075 = v_21077;
    v_21075 = qcdr(v_21075);
    v_21075 = qcar(v_21075);
    goto v_21065;
v_21066:
    goto v_21067;
v_21068:
    goto v_21064;
v_21065:
    goto v_21066;
v_21067:
    fn = elt(env, 1); // ofsf_siatsubf
    v_21075 = (*qfn2(fn))(fn, v_21075, v_21076);
    v_21076 = qcar(v_21075);
    goto v_21049;
v_21050:
    v_21075 = nil;
    goto v_21051;
v_21052:
    goto v_21046;
v_21047:
    goto v_21048;
v_21049:
    goto v_21050;
v_21051:
    {
        LispObject v_21079 = stack[0];
        return list3(v_21079, v_21076, v_21075);
    }
}



// Code for talp_maxd

static LispObject CC_talp_maxd(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21099, v_21100;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_21100 = v_21042;
// end of prologue
    v_21099 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_21099;
    v_21099 = v_21100;
    if (!consp(v_21099)) goto v_21053;
    else goto v_21054;
v_21053:
    v_21099 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21048;
v_21054:
    v_21099 = v_21100;
    fn = elt(env, 1); // rl_atl
    v_21099 = (*qfn1(fn))(fn, v_21099);
    env = stack[-3];
    stack[-2] = v_21099;
v_21061:
    v_21099 = stack[-2];
    if (v_21099 == nil) goto v_21064;
    else goto v_21065;
v_21064:
    goto v_21060;
v_21065:
    goto v_21073;
v_21069:
    v_21099 = stack[-2];
    v_21099 = qcar(v_21099);
    fn = elt(env, 2); // talp_arg2l
    v_21099 = (*qfn1(fn))(fn, v_21099);
    env = stack[-3];
    fn = elt(env, 3); // talp_td
    stack[0] = (*qfn1(fn))(fn, v_21099);
    env = stack[-3];
    goto v_21070;
v_21071:
    v_21099 = stack[-2];
    v_21099 = qcar(v_21099);
    fn = elt(env, 4); // talp_arg2r
    v_21099 = (*qfn1(fn))(fn, v_21099);
    env = stack[-3];
    fn = elt(env, 3); // talp_td
    v_21099 = (*qfn1(fn))(fn, v_21099);
    env = stack[-3];
    goto v_21072;
v_21073:
    goto v_21069;
v_21070:
    goto v_21071;
v_21072:
    v_21099 = Lmax2(nil, stack[0], v_21099);
    env = stack[-3];
    stack[0] = v_21099;
    goto v_21091;
v_21087:
    v_21100 = stack[0];
    goto v_21088;
v_21089:
    v_21099 = stack[-1];
    goto v_21090;
v_21091:
    goto v_21087;
v_21088:
    goto v_21089;
v_21090:
    v_21099 = (LispObject)greaterp2(v_21100, v_21099);
    v_21099 = v_21099 ? lisp_true : nil;
    env = stack[-3];
    if (v_21099 == nil) goto v_21085;
    v_21099 = stack[0];
    stack[-1] = v_21099;
    goto v_21083;
v_21085:
v_21083:
    v_21099 = stack[-2];
    v_21099 = qcdr(v_21099);
    stack[-2] = v_21099;
    goto v_21061;
v_21060:
    v_21099 = stack[-1];
v_21048:
    return onevalue(v_21099);
}



// Code for ctx_filter

static LispObject CC_ctx_filter(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21129, v_21130, v_21131;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_21129 = v_21043;
    stack[-4] = v_21042;
// end of prologue
    goto v_21050;
v_21046:
    stack[-5] = elt(env, 1); // ctx
    goto v_21047;
v_21048:
    fn = elt(env, 2); // ctx_ial
    v_21129 = (*qfn1(fn))(fn, v_21129);
    env = stack[-6];
    stack[-3] = v_21129;
v_21057:
    v_21129 = stack[-3];
    if (v_21129 == nil) goto v_21063;
    else goto v_21064;
v_21063:
    v_21129 = nil;
    goto v_21056;
v_21064:
    v_21129 = stack[-3];
    v_21129 = qcar(v_21129);
    v_21131 = v_21129;
    goto v_21078;
v_21074:
    v_21129 = v_21131;
    v_21130 = qcar(v_21129);
    goto v_21075;
v_21076:
    v_21129 = stack[-4];
    goto v_21077;
v_21078:
    goto v_21074;
v_21075:
    goto v_21076;
v_21077:
    v_21129 = Lmemq(nil, v_21130, v_21129);
    if (v_21129 == nil) goto v_21073;
    v_21129 = v_21131;
    v_21129 = ncons(v_21129);
    env = stack[-6];
    goto v_21071;
v_21073:
    v_21129 = nil;
v_21071:
    stack[-2] = v_21129;
    v_21129 = stack[-2];
    fn = elt(env, 3); // lastpair
    v_21129 = (*qfn1(fn))(fn, v_21129);
    env = stack[-6];
    stack[-1] = v_21129;
    v_21129 = stack[-3];
    v_21129 = qcdr(v_21129);
    stack[-3] = v_21129;
    v_21129 = stack[-1];
    if (!consp(v_21129)) goto v_21091;
    else goto v_21092;
v_21091:
    goto v_21057;
v_21092:
v_21058:
    v_21129 = stack[-3];
    if (v_21129 == nil) goto v_21096;
    else goto v_21097;
v_21096:
    v_21129 = stack[-2];
    goto v_21056;
v_21097:
    goto v_21105;
v_21101:
    stack[0] = stack[-1];
    goto v_21102;
v_21103:
    v_21129 = stack[-3];
    v_21129 = qcar(v_21129);
    v_21131 = v_21129;
    goto v_21118;
v_21114:
    v_21129 = v_21131;
    v_21130 = qcar(v_21129);
    goto v_21115;
v_21116:
    v_21129 = stack[-4];
    goto v_21117;
v_21118:
    goto v_21114;
v_21115:
    goto v_21116;
v_21117:
    v_21129 = Lmemq(nil, v_21130, v_21129);
    if (v_21129 == nil) goto v_21113;
    v_21129 = v_21131;
    v_21129 = ncons(v_21129);
    env = stack[-6];
    goto v_21111;
v_21113:
    v_21129 = nil;
v_21111:
    goto v_21104;
v_21105:
    goto v_21101;
v_21102:
    goto v_21103;
v_21104:
    v_21129 = Lrplacd(nil, stack[0], v_21129);
    env = stack[-6];
    v_21129 = stack[-1];
    fn = elt(env, 3); // lastpair
    v_21129 = (*qfn1(fn))(fn, v_21129);
    env = stack[-6];
    stack[-1] = v_21129;
    v_21129 = stack[-3];
    v_21129 = qcdr(v_21129);
    stack[-3] = v_21129;
    goto v_21058;
v_21056:
    goto v_21049;
v_21050:
    goto v_21046;
v_21047:
    goto v_21048;
v_21049:
    {
        LispObject v_21138 = stack[-5];
        return list2(v_21138, v_21129);
    }
}



// Code for containerom

static LispObject CC_containerom(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21170, v_21171;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_21042;
// end of prologue
    v_21170 = stack[-2];
    v_21170 = qcdr(v_21170);
    v_21170 = qcar(v_21170);
    stack[-1] = v_21170;
    v_21170 = stack[-2];
    v_21170 = qcar(v_21170);
    stack[0] = v_21170;
    v_21170 = elt(env, 1); // "<OMA>"
    fn = elt(env, 13); // printout
    v_21170 = (*qfn1(fn))(fn, v_21170);
    env = stack[-4];
    v_21170 = lisp_true;
    fn = elt(env, 14); // indent!*
    v_21170 = (*qfn1(fn))(fn, v_21170);
    env = stack[-4];
    goto v_21066;
v_21062:
    v_21171 = stack[0];
    goto v_21063;
v_21064:
    v_21170 = elt(env, 2); // vectorml
    goto v_21065;
v_21066:
    goto v_21062;
v_21063:
    goto v_21064;
v_21065:
    if (v_21171 == v_21170) goto v_21060;
    else goto v_21061;
v_21060:
    v_21170 = elt(env, 3); // vector
    stack[0] = v_21170;
    goto v_21059;
v_21061:
v_21059:
    goto v_21074;
v_21070:
    v_21171 = stack[0];
    goto v_21071;
v_21072:
    v_21170 = qvalue(elt(env, 4)); // valid_om!*
    goto v_21073;
v_21074:
    goto v_21070;
v_21071:
    goto v_21072;
v_21073:
    v_21170 = Lassoc(nil, v_21171, v_21170);
    v_21170 = qcdr(v_21170);
    v_21170 = qcar(v_21170);
    stack[-3] = v_21170;
    goto v_21092;
v_21088:
    v_21170 = stack[-2];
    v_21171 = qcar(v_21170);
    goto v_21089;
v_21090:
    v_21170 = elt(env, 5); // set
    goto v_21091;
v_21092:
    goto v_21088;
v_21089:
    goto v_21090;
v_21091:
    if (v_21171 == v_21170) goto v_21086;
    else goto v_21087;
v_21086:
    v_21170 = stack[-1];
    v_21170 = Lconsp(nil, v_21170);
    env = stack[-4];
    goto v_21085;
v_21087:
    v_21170 = nil;
    goto v_21085;
    v_21170 = nil;
v_21085:
    if (v_21170 == nil) goto v_21083;
    goto v_21109;
v_21105:
    v_21170 = stack[-1];
    v_21170 = qcar(v_21170);
    v_21170 = qcdr(v_21170);
    v_21170 = qcar(v_21170);
    v_21171 = Lintern(nil, v_21170);
    env = stack[-4];
    goto v_21106;
v_21107:
    v_21170 = elt(env, 6); // multiset
    goto v_21108;
v_21109:
    goto v_21105;
v_21106:
    goto v_21107;
v_21108:
    if (v_21171 == v_21170) goto v_21103;
    else goto v_21104;
v_21103:
    v_21170 = elt(env, 7); // multiset1
    stack[-3] = v_21170;
    goto v_21102;
v_21104:
v_21102:
    goto v_21081;
v_21083:
v_21081:
    goto v_21126;
v_21122:
    v_21170 = stack[-2];
    v_21171 = qcar(v_21170);
    goto v_21123;
v_21124:
    v_21170 = elt(env, 2); // vectorml
    goto v_21125;
v_21126:
    goto v_21122;
v_21123:
    goto v_21124;
v_21125:
    if (v_21171 == v_21170) goto v_21120;
    else goto v_21121;
v_21120:
    v_21170 = elt(env, 8); // "vector"
    stack[0] = v_21170;
    goto v_21119;
v_21121:
v_21119:
    goto v_21139;
v_21135:
    v_21170 = stack[-2];
    v_21171 = qcar(v_21170);
    goto v_21136;
v_21137:
    v_21170 = elt(env, 2); // vectorml
    goto v_21138;
v_21139:
    goto v_21135;
v_21136:
    goto v_21137;
v_21138:
    if (v_21171 == v_21170) goto v_21133;
    else goto v_21134;
v_21133:
    goto v_21148;
v_21144:
    v_21171 = elt(env, 3); // vector
    goto v_21145;
v_21146:
    v_21170 = stack[-2];
    v_21170 = qcdr(v_21170);
    goto v_21147;
v_21148:
    goto v_21144;
v_21145:
    goto v_21146;
v_21147:
    v_21170 = cons(v_21171, v_21170);
    env = stack[-4];
    stack[-2] = v_21170;
    goto v_21132;
v_21134:
v_21132:
    v_21170 = elt(env, 9); // "<OMS cd="""
    fn = elt(env, 13); // printout
    v_21170 = (*qfn1(fn))(fn, v_21170);
    env = stack[-4];
    v_21170 = stack[-3];
    v_21170 = Lprinc(nil, v_21170);
    env = stack[-4];
    v_21170 = elt(env, 10); // """ name="""
    v_21170 = Lprinc(nil, v_21170);
    env = stack[-4];
    v_21170 = stack[0];
    v_21170 = Lprinc(nil, v_21170);
    env = stack[-4];
    v_21170 = elt(env, 11); // """/>"
    v_21170 = Lprinc(nil, v_21170);
    env = stack[-4];
    v_21170 = stack[-2];
    v_21170 = qcdr(v_21170);
    v_21170 = qcdr(v_21170);
    fn = elt(env, 15); // multiom
    v_21170 = (*qfn1(fn))(fn, v_21170);
    env = stack[-4];
    v_21170 = nil;
    fn = elt(env, 14); // indent!*
    v_21170 = (*qfn1(fn))(fn, v_21170);
    env = stack[-4];
    v_21170 = elt(env, 12); // "</OMA>"
    fn = elt(env, 13); // printout
    v_21170 = (*qfn1(fn))(fn, v_21170);
    v_21170 = nil;
    return onevalue(v_21170);
}



// Code for s!-nextarg

static LispObject CC_sKnextarg(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21258, v_21259, v_21260;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21042;
// end of prologue
    v_21258 = qvalue(elt(env, 1)); // !*udebug
    if (v_21258 == nil) goto v_21051;
    v_21258 = nil;
    fn = elt(env, 12); // uprint
    v_21258 = (*qfn1(fn))(fn, v_21258);
    env = stack[-2];
    goto v_21049;
v_21051:
v_21049:
    v_21258 = qvalue(elt(env, 2)); // comb
    if (v_21258 == nil) goto v_21057;
    else goto v_21058;
v_21057:
    v_21258 = qvalue(elt(env, 3)); // i
    v_21258 = add1(v_21258);
    env = stack[-2];
    qvalue(elt(env, 3)) = v_21258; // i
    v_21258 = stack[0];
    fn = elt(env, 13); // initcomb
    v_21258 = (*qfn1(fn))(fn, v_21258);
    env = stack[-2];
    qvalue(elt(env, 2)) = v_21258; // comb
    goto v_21056;
v_21058:
v_21056:
    goto v_21073;
v_21069:
    v_21259 = stack[0];
    goto v_21070;
v_21071:
    v_21258 = qvalue(elt(env, 2)); // comb
    goto v_21072;
v_21073:
    goto v_21069;
v_21070:
    goto v_21071;
v_21072:
    fn = elt(env, 14); // getcomb
    v_21258 = (*qfn2(fn))(fn, v_21259, v_21258);
    env = stack[-2];
    stack[-1] = v_21258;
    if (v_21258 == nil) goto v_21067;
    goto v_21088;
v_21084:
    v_21259 = qvalue(elt(env, 3)); // i
    goto v_21085;
v_21086:
    v_21258 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21087;
v_21088:
    goto v_21084;
v_21085:
    goto v_21086;
v_21087:
    if (v_21259 == v_21258) goto v_21082;
    else goto v_21083;
v_21082:
    goto v_21096;
v_21092:
    v_21259 = qvalue(elt(env, 3)); // i
    goto v_21093;
v_21094:
    v_21258 = qvalue(elt(env, 4)); // upb
    goto v_21095;
v_21096:
    goto v_21092;
v_21093:
    goto v_21094;
v_21095:
    v_21258 = (LispObject)lesseq2(v_21259, v_21258);
    v_21258 = v_21258 ? lisp_true : nil;
    env = stack[-2];
    goto v_21081;
v_21083:
    v_21258 = nil;
    goto v_21081;
    v_21258 = nil;
v_21081:
    if (v_21258 == nil) goto v_21079;
    goto v_21107;
v_21103:
    v_21258 = stack[-1];
    v_21258 = qcar(v_21258);
    v_21259 = qcar(v_21258);
    goto v_21104;
v_21105:
    v_21258 = stack[-1];
    v_21258 = qcdr(v_21258);
    goto v_21106;
v_21107:
    goto v_21103;
v_21104:
    goto v_21105;
v_21106:
    return cons(v_21259, v_21258);
v_21079:
    goto v_21123;
v_21119:
    v_21259 = qvalue(elt(env, 3)); // i
    goto v_21120;
v_21121:
    v_21258 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21122;
v_21123:
    goto v_21119;
v_21120:
    goto v_21121;
v_21122:
    if (v_21259 == v_21258) goto v_21117;
    else goto v_21118;
v_21117:
    goto v_21131;
v_21127:
    v_21259 = qvalue(elt(env, 3)); // i
    goto v_21128;
v_21129:
    v_21258 = qvalue(elt(env, 4)); // upb
    goto v_21130;
v_21131:
    goto v_21127;
v_21128:
    goto v_21129;
v_21130:
    v_21258 = (LispObject)lesseq2(v_21259, v_21258);
    v_21258 = v_21258 ? lisp_true : nil;
    env = stack[-2];
    goto v_21116;
v_21118:
    v_21258 = nil;
    goto v_21116;
    v_21258 = nil;
v_21116:
    if (v_21258 == nil) goto v_21114;
    goto v_21142;
v_21138:
    v_21259 = elt(env, 5); // (null!-fn)
    goto v_21139;
v_21140:
    v_21258 = stack[0];
    goto v_21141;
v_21142:
    goto v_21138;
v_21139:
    goto v_21140;
v_21141:
    return cons(v_21259, v_21258);
v_21114:
    v_21258 = qvalue(elt(env, 6)); // acontract
    if (v_21258 == nil) goto v_21146;
    goto v_21155;
v_21151:
    v_21259 = qvalue(elt(env, 3)); // i
    goto v_21152;
v_21153:
    v_21258 = qvalue(elt(env, 4)); // upb
    goto v_21154;
v_21155:
    goto v_21151;
v_21152:
    goto v_21153;
v_21154:
    v_21258 = (LispObject)lesseq2(v_21259, v_21258);
    v_21258 = v_21258 ? lisp_true : nil;
    env = stack[-2];
    if (v_21258 == nil) goto v_21146;
    goto v_21166;
v_21160:
    v_21260 = qvalue(elt(env, 7)); // op
    goto v_21161;
v_21162:
    v_21258 = stack[-1];
    v_21259 = qcar(v_21258);
    goto v_21163;
v_21164:
    v_21258 = stack[-1];
    v_21258 = qcdr(v_21258);
    goto v_21165;
v_21166:
    goto v_21160;
v_21161:
    goto v_21162;
v_21163:
    goto v_21164;
v_21165:
    v_21258 = acons(v_21260, v_21259, v_21258);
    env = stack[-2];
    {
        fn = elt(env, 15); // mval
        return (*qfn1(fn))(fn, v_21258);
    }
v_21146:
    v_21258 = qvalue(elt(env, 8)); // mcontract
    if (v_21258 == nil) goto v_21173;
    goto v_21182;
v_21178:
    v_21259 = qvalue(elt(env, 3)); // i
    goto v_21179;
v_21180:
    v_21258 = qvalue(elt(env, 4)); // upb
    goto v_21181;
v_21182:
    goto v_21178;
v_21179:
    goto v_21180;
v_21181:
    v_21258 = (LispObject)lesseq2(v_21259, v_21258);
    v_21258 = v_21258 ? lisp_true : nil;
    env = stack[-2];
    if (v_21258 == nil) goto v_21173;
    goto v_21192;
v_21186:
    v_21260 = elt(env, 9); // null!-fn
    goto v_21187;
v_21188:
    v_21258 = stack[-1];
    v_21259 = qcar(v_21258);
    goto v_21189;
v_21190:
    v_21258 = stack[-1];
    v_21258 = qcdr(v_21258);
    goto v_21191;
v_21192:
    goto v_21186;
v_21187:
    goto v_21188;
v_21189:
    goto v_21190;
v_21191:
    return acons(v_21260, v_21259, v_21258);
v_21173:
    v_21258 = qvalue(elt(env, 10)); // expand
    if (v_21258 == nil) goto v_21199;
    v_21258 = nil;
    qvalue(elt(env, 10)) = v_21258; // expand
    goto v_21207;
v_21203:
    v_21259 = qvalue(elt(env, 11)); // identity
    goto v_21204;
v_21205:
    v_21258 = stack[0];
    goto v_21206;
v_21207:
    goto v_21203;
v_21204:
    goto v_21205;
v_21206:
    return cons(v_21259, v_21258);
v_21199:
    v_21258 = nil;
    goto v_21077;
    v_21258 = nil;
v_21077:
    goto v_21065;
v_21067:
    goto v_21223;
v_21219:
    v_21259 = qvalue(elt(env, 3)); // i
    goto v_21220;
v_21221:
    v_21258 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21222;
v_21223:
    goto v_21219;
v_21220:
    goto v_21221;
v_21222:
    if (v_21259 == v_21258) goto v_21217;
    else goto v_21218;
v_21217:
    goto v_21231;
v_21227:
    v_21259 = qvalue(elt(env, 3)); // i
    goto v_21228;
v_21229:
    v_21258 = qvalue(elt(env, 4)); // upb
    goto v_21230;
v_21231:
    goto v_21227;
v_21228:
    goto v_21229;
v_21230:
    v_21258 = (LispObject)lesseq2(v_21259, v_21258);
    v_21258 = v_21258 ? lisp_true : nil;
    env = stack[-2];
    goto v_21216;
v_21218:
    v_21258 = nil;
    goto v_21216;
    v_21258 = nil;
v_21216:
    if (v_21258 == nil) goto v_21214;
    goto v_21242;
v_21238:
    v_21259 = elt(env, 5); // (null!-fn)
    goto v_21239;
v_21240:
    v_21258 = stack[0];
    goto v_21241;
v_21242:
    goto v_21238;
v_21239:
    goto v_21240;
v_21241:
    return cons(v_21259, v_21258);
v_21214:
    v_21258 = qvalue(elt(env, 10)); // expand
    if (v_21258 == nil) goto v_21246;
    v_21258 = nil;
    qvalue(elt(env, 10)) = v_21258; // expand
    goto v_21254;
v_21250:
    v_21259 = qvalue(elt(env, 11)); // identity
    goto v_21251;
v_21252:
    v_21258 = stack[0];
    goto v_21253;
v_21254:
    goto v_21250;
v_21251:
    goto v_21252;
v_21253:
    return cons(v_21259, v_21258);
v_21246:
    v_21258 = nil;
v_21065:
    return onevalue(v_21258);
}



// Code for wedgef

static LispObject CC_wedgef(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21276, v_21277, v_21278;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_21042;
// end of prologue
    v_21276 = stack[-1];
    fn = elt(env, 6); // dim!<deg
    v_21276 = (*qfn1(fn))(fn, v_21276);
    env = stack[-3];
    if (v_21276 == nil) goto v_21047;
    v_21276 = nil;
    goto v_21045;
v_21047:
    goto v_21058;
v_21054:
    v_21276 = stack[-1];
    v_21277 = qcar(v_21276);
    goto v_21055;
v_21056:
    v_21276 = elt(env, 1); // hodge
    goto v_21057;
v_21058:
    goto v_21054;
v_21055:
    goto v_21056;
v_21057:
    if (!consp(v_21277)) goto v_21052;
    v_21277 = qcar(v_21277);
    if (v_21277 == v_21276) goto v_21051;
    else goto v_21052;
v_21051:
    v_21276 = stack[-1];
    v_21276 = qcar(v_21276);
    v_21276 = qcdr(v_21276);
    v_21276 = qcar(v_21276);
    fn = elt(env, 7); // deg!*form
    v_21276 = (*qfn1(fn))(fn, v_21276);
    env = stack[-3];
    stack[-2] = v_21276;
    goto v_21076;
v_21072:
    stack[0] = stack[-2];
    goto v_21073;
v_21074:
    v_21276 = stack[-1];
    v_21276 = qcdr(v_21276);
    fn = elt(env, 8); // deg!*farg
    v_21276 = (*qfn1(fn))(fn, v_21276);
    env = stack[-3];
    goto v_21075;
v_21076:
    goto v_21072;
v_21073:
    goto v_21074;
v_21075:
    if (equal(stack[0], v_21276)) goto v_21070;
    else goto v_21071;
v_21070:
    goto v_21086;
v_21082:
    goto v_21092;
v_21088:
    goto v_21101;
v_21095:
    v_21276 = stack[-1];
    v_21276 = qcar(v_21276);
    v_21276 = qcdr(v_21276);
    v_21278 = qcar(v_21276);
    goto v_21096;
v_21097:
    v_21277 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21098;
v_21099:
    v_21276 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21100;
v_21101:
    goto v_21095;
v_21096:
    goto v_21097;
v_21098:
    goto v_21099;
v_21100:
    v_21276 = list2star(v_21278, v_21277, v_21276);
    env = stack[-3];
    stack[0] = ncons(v_21276);
    env = stack[-3];
    goto v_21089;
v_21090:
    v_21276 = stack[-1];
    v_21276 = qcdr(v_21276);
    v_21276 = qcdr(v_21276);
    if (v_21276 == nil) goto v_21113;
    v_21276 = stack[-1];
    v_21276 = qcdr(v_21276);
    fn = elt(env, 9); // mkuniquewedge1
    v_21276 = (*qfn1(fn))(fn, v_21276);
    env = stack[-3];
    goto v_21111;
v_21113:
    goto v_21130;
v_21124:
    v_21276 = stack[-1];
    v_21276 = qcdr(v_21276);
    v_21278 = qcar(v_21276);
    goto v_21125;
v_21126:
    v_21277 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21127;
v_21128:
    v_21276 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21129;
v_21130:
    goto v_21124;
v_21125:
    goto v_21126;
v_21127:
    goto v_21128;
v_21129:
    v_21276 = list2star(v_21278, v_21277, v_21276);
    env = stack[-3];
    v_21276 = ncons(v_21276);
    env = stack[-3];
    goto v_21111;
    v_21276 = nil;
v_21111:
    fn = elt(env, 10); // hodgepf
    v_21276 = (*qfn1(fn))(fn, v_21276);
    env = stack[-3];
    fn = elt(env, 11); // mkunarywedge
    v_21276 = (*qfn1(fn))(fn, v_21276);
    env = stack[-3];
    goto v_21091;
v_21092:
    goto v_21088;
v_21089:
    goto v_21090;
v_21091:
    fn = elt(env, 12); // wedgepf2
    stack[-1] = (*qfn2(fn))(fn, stack[0], v_21276);
    env = stack[-3];
    goto v_21083;
v_21084:
    goto v_21142;
v_21138:
    stack[0] = stack[-2];
    goto v_21139;
v_21140:
    goto v_21149;
v_21145:
    goto v_21146;
v_21147:
    v_21276 = qvalue(elt(env, 2)); // dimex!*
    fn = elt(env, 13); // negf
    v_21276 = (*qfn1(fn))(fn, v_21276);
    env = stack[-3];
    goto v_21148;
v_21149:
    goto v_21145;
v_21146:
    goto v_21147;
v_21148:
    fn = elt(env, 14); // addf
    v_21276 = (*qfn2(fn))(fn, stack[-2], v_21276);
    env = stack[-3];
    goto v_21141;
v_21142:
    goto v_21138;
v_21139:
    goto v_21140;
v_21141:
    fn = elt(env, 15); // multf
    v_21276 = (*qfn2(fn))(fn, stack[0], v_21276);
    env = stack[-3];
    fn = elt(env, 16); // mksgnsq
    v_21276 = (*qfn1(fn))(fn, v_21276);
    env = stack[-3];
    goto v_21085;
v_21086:
    goto v_21082;
v_21083:
    goto v_21084;
v_21085:
    {
        LispObject v_21282 = stack[-1];
        fn = elt(env, 17); // multpfsq
        return (*qfn2(fn))(fn, v_21282, v_21276);
    }
v_21071:
    v_21276 = stack[-1];
    {
        fn = elt(env, 18); // mkwedge
        return (*qfn1(fn))(fn, v_21276);
    }
    v_21276 = nil;
    goto v_21045;
v_21052:
    goto v_21168;
v_21164:
    v_21276 = stack[-1];
    v_21277 = qcar(v_21276);
    goto v_21165;
v_21166:
    v_21276 = elt(env, 3); // d
    goto v_21167;
v_21168:
    goto v_21164;
v_21165:
    goto v_21166;
v_21167:
    if (!consp(v_21277)) goto v_21162;
    v_21277 = qcar(v_21277);
    if (v_21277 == v_21276) goto v_21161;
    else goto v_21162;
v_21161:
    goto v_21181;
v_21177:
    v_21277 = elt(env, 3); // d
    goto v_21178;
v_21179:
    v_21276 = elt(env, 4); // noxpnd
    goto v_21180;
v_21181:
    goto v_21177;
v_21178:
    goto v_21179;
v_21180:
    v_21276 = Lflagp(nil, v_21277, v_21276);
    env = stack[-3];
    if (v_21276 == nil) goto v_21175;
    v_21276 = lisp_true;
    goto v_21173;
v_21175:
    goto v_21192;
v_21188:
    v_21277 = qvalue(elt(env, 5)); // lftshft!*
    goto v_21189;
v_21190:
    v_21276 = stack[-1];
    v_21276 = qcar(v_21276);
    v_21276 = qcdr(v_21276);
    v_21276 = qcar(v_21276);
    goto v_21191;
v_21192:
    goto v_21188;
v_21189:
    goto v_21190;
v_21191:
    fn = elt(env, 19); // smemqlp
    v_21276 = (*qfn2(fn))(fn, v_21277, v_21276);
    env = stack[-3];
    goto v_21173;
    v_21276 = nil;
v_21173:
    goto v_21160;
v_21162:
    v_21276 = nil;
    goto v_21160;
    v_21276 = nil;
v_21160:
    if (v_21276 == nil) goto v_21158;
    goto v_21206;
v_21202:
    goto v_21214;
v_21210:
    v_21276 = stack[-1];
    v_21276 = qcar(v_21276);
    v_21276 = qcdr(v_21276);
    v_21277 = qcar(v_21276);
    goto v_21211;
v_21212:
    v_21276 = stack[-1];
    v_21276 = qcdr(v_21276);
    goto v_21213;
v_21214:
    goto v_21210;
v_21211:
    goto v_21212;
v_21213:
    v_21276 = cons(v_21277, v_21276);
    env = stack[-3];
    fn = elt(env, 20); // dwedge
    v_21276 = (*qfn1(fn))(fn, v_21276);
    env = stack[-3];
    fn = elt(env, 11); // mkunarywedge
    stack[-2] = (*qfn1(fn))(fn, v_21276);
    env = stack[-3];
    goto v_21203;
v_21204:
    goto v_21226;
v_21222:
    goto v_21232;
v_21228:
    goto v_21241;
v_21235:
    v_21276 = stack[-1];
    v_21276 = qcar(v_21276);
    v_21276 = qcdr(v_21276);
    v_21278 = qcar(v_21276);
    goto v_21236;
v_21237:
    v_21277 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21238;
v_21239:
    v_21276 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21240;
v_21241:
    goto v_21235;
v_21236:
    goto v_21237;
v_21238:
    goto v_21239;
v_21240:
    v_21276 = list2star(v_21278, v_21277, v_21276);
    env = stack[-3];
    stack[0] = ncons(v_21276);
    env = stack[-3];
    goto v_21229;
v_21230:
    v_21276 = stack[-1];
    v_21276 = qcdr(v_21276);
    v_21276 = qcdr(v_21276);
    if (v_21276 == nil) goto v_21252;
    v_21276 = stack[-1];
    v_21276 = qcdr(v_21276);
    fn = elt(env, 20); // dwedge
    v_21276 = (*qfn1(fn))(fn, v_21276);
    env = stack[-3];
    goto v_21250;
v_21252:
    v_21276 = stack[-1];
    v_21276 = qcdr(v_21276);
    v_21276 = qcar(v_21276);
    fn = elt(env, 21); // exdfk
    v_21276 = (*qfn1(fn))(fn, v_21276);
    env = stack[-3];
    goto v_21250;
    v_21276 = nil;
v_21250:
    fn = elt(env, 11); // mkunarywedge
    v_21276 = (*qfn1(fn))(fn, v_21276);
    env = stack[-3];
    goto v_21231;
v_21232:
    goto v_21228;
v_21229:
    goto v_21230;
v_21231:
    fn = elt(env, 12); // wedgepf2
    stack[0] = (*qfn2(fn))(fn, stack[0], v_21276);
    env = stack[-3];
    goto v_21223;
v_21224:
    v_21276 = stack[-1];
    v_21276 = qcar(v_21276);
    v_21276 = qcdr(v_21276);
    v_21276 = qcar(v_21276);
    fn = elt(env, 7); // deg!*form
    v_21276 = (*qfn1(fn))(fn, v_21276);
    env = stack[-3];
    fn = elt(env, 16); // mksgnsq
    v_21276 = (*qfn1(fn))(fn, v_21276);
    env = stack[-3];
    fn = elt(env, 22); // negsq
    v_21276 = (*qfn1(fn))(fn, v_21276);
    env = stack[-3];
    goto v_21225;
v_21226:
    goto v_21222;
v_21223:
    goto v_21224;
v_21225:
    fn = elt(env, 17); // multpfsq
    v_21276 = (*qfn2(fn))(fn, stack[0], v_21276);
    env = stack[-3];
    goto v_21205;
v_21206:
    goto v_21202;
v_21203:
    goto v_21204;
v_21205:
    {
        LispObject v_21283 = stack[-2];
        fn = elt(env, 23); // addpf
        return (*qfn2(fn))(fn, v_21283, v_21276);
    }
v_21158:
    v_21276 = stack[-1];
    {
        fn = elt(env, 18); // mkwedge
        return (*qfn1(fn))(fn, v_21276);
    }
    v_21276 = nil;
v_21045:
    return onevalue(v_21276);
}



// Code for gbfplus

static LispObject CC_gbfplus(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21071, v_21072;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21043;
    stack[-1] = v_21042;
// end of prologue
    goto v_21050;
v_21046:
    goto v_21056;
v_21052:
    v_21071 = stack[-1];
    v_21072 = qcar(v_21071);
    goto v_21053;
v_21054:
    v_21071 = stack[0];
    v_21071 = qcar(v_21071);
    goto v_21055;
v_21056:
    goto v_21052;
v_21053:
    goto v_21054;
v_21055:
    fn = elt(env, 1); // plubf
    stack[-2] = (*qfn2(fn))(fn, v_21072, v_21071);
    env = stack[-3];
    goto v_21047;
v_21048:
    goto v_21066;
v_21062:
    v_21071 = stack[-1];
    v_21072 = qcdr(v_21071);
    goto v_21063;
v_21064:
    v_21071 = stack[0];
    v_21071 = qcdr(v_21071);
    goto v_21065;
v_21066:
    goto v_21062;
v_21063:
    goto v_21064;
v_21065:
    fn = elt(env, 1); // plubf
    v_21071 = (*qfn2(fn))(fn, v_21072, v_21071);
    goto v_21049;
v_21050:
    goto v_21046;
v_21047:
    goto v_21048;
v_21049:
    {
        LispObject v_21076 = stack[-2];
        return cons(v_21076, v_21071);
    }
}



// Code for !:!:quotient

static LispObject CC_TTquotient(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21063, v_21064;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21064 = v_21043;
    v_21063 = v_21042;
// end of prologue
    goto v_21050;
v_21046:
    stack[0] = v_21063;
    goto v_21047;
v_21048:
    v_21063 = v_21064;
    v_21063 = integerp(v_21063);
    if (v_21063 == nil) goto v_21055;
    v_21063 = v_21064;
    fn = elt(env, 1); // i2rd!*
    v_21063 = (*qfn1(fn))(fn, v_21063);
    env = stack[-1];
    goto v_21053;
v_21055:
    v_21063 = v_21064;
    goto v_21053;
    v_21063 = nil;
v_21053:
    goto v_21049;
v_21050:
    goto v_21046;
v_21047:
    goto v_21048;
v_21049:
    {
        LispObject v_21066 = stack[0];
        fn = elt(env, 2); // !:quotient
        return (*qfn2(fn))(fn, v_21066, v_21063);
    }
}



// Code for contr2

static LispObject CC_contr2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21108, v_21109;
    LispObject fn;
    LispObject v_21044, v_21043, v_21042;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "contr2");
    va_start(aa, nargs);
    v_21042 = va_arg(aa, LispObject);
    v_21043 = va_arg(aa, LispObject);
    v_21044 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21044,v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21042,v_21043,v_21044);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_21044;
    stack[-1] = v_21043;
    stack[-2] = v_21042;
// end of prologue
    stack[-3] = nil;
v_21049:
    v_21108 = stack[-1];
    if (v_21108 == nil) goto v_21052;
    else goto v_21053;
v_21052:
    goto v_21060;
v_21056:
    stack[-1] = stack[-3];
    goto v_21057;
v_21058:
    goto v_21067;
v_21063:
    v_21109 = stack[-2];
    goto v_21064;
v_21065:
    v_21108 = stack[0];
    goto v_21066;
v_21067:
    goto v_21063;
v_21064:
    goto v_21065;
v_21066:
    fn = elt(env, 1); // contr
    v_21108 = (*qfn2(fn))(fn, v_21109, v_21108);
    env = stack[-4];
    goto v_21059;
v_21060:
    goto v_21056;
v_21057:
    goto v_21058;
v_21059:
    {
        LispObject v_21114 = stack[-1];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_21114, v_21108);
    }
v_21053:
    v_21108 = stack[0];
    if (v_21108 == nil) goto v_21070;
    else goto v_21071;
v_21070:
    goto v_21078;
v_21074:
    stack[0] = stack[-3];
    goto v_21075;
v_21076:
    goto v_21085;
v_21081:
    v_21109 = stack[-2];
    goto v_21082;
v_21083:
    v_21108 = stack[-1];
    goto v_21084;
v_21085:
    goto v_21081;
v_21082:
    goto v_21083;
v_21084:
    fn = elt(env, 1); // contr
    v_21108 = (*qfn2(fn))(fn, v_21109, v_21108);
    env = stack[-4];
    goto v_21077;
v_21078:
    goto v_21074;
v_21075:
    goto v_21076;
v_21077:
    {
        LispObject v_21115 = stack[0];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_21115, v_21108);
    }
v_21071:
    goto v_21095;
v_21091:
    goto v_21101;
v_21097:
    v_21109 = stack[-2];
    goto v_21098;
v_21099:
    v_21108 = stack[-1];
    v_21108 = qcar(v_21108);
    goto v_21100;
v_21101:
    goto v_21097;
v_21098:
    goto v_21099;
v_21100:
    fn = elt(env, 3); // split!-road
    v_21109 = (*qfn2(fn))(fn, v_21109, v_21108);
    env = stack[-4];
    goto v_21092;
v_21093:
    v_21108 = stack[-3];
    goto v_21094;
v_21095:
    goto v_21091;
v_21092:
    goto v_21093;
v_21094:
    v_21108 = cons(v_21109, v_21108);
    env = stack[-4];
    stack[-3] = v_21108;
    v_21108 = stack[-1];
    v_21108 = qcdr(v_21108);
    stack[-1] = v_21108;
    goto v_21049;
    v_21108 = nil;
    return onevalue(v_21108);
}



// Code for innprodpex

static LispObject CC_innprodpex(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21114, v_21115;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_21043;
    stack[-2] = v_21042;
// end of prologue
v_21041:
    v_21114 = stack[-1];
    if (v_21114 == nil) goto v_21047;
    else goto v_21048;
v_21047:
    v_21114 = nil;
    goto v_21046;
v_21048:
    goto v_21058;
v_21054:
    v_21115 = stack[-2];
    goto v_21055;
v_21056:
    v_21114 = stack[-1];
    v_21114 = qcar(v_21114);
    v_21114 = qcar(v_21114);
    goto v_21057;
v_21058:
    goto v_21054;
v_21055:
    goto v_21056;
v_21057:
    fn = elt(env, 1); // innprodp2
    v_21114 = (*qfn2(fn))(fn, v_21115, v_21114);
    env = stack[-4];
    v_21115 = v_21114;
    v_21114 = v_21115;
    if (v_21114 == nil) goto v_21067;
    goto v_21076;
v_21070:
    v_21114 = v_21115;
    stack[-3] = qcdr(v_21114);
    goto v_21071;
v_21072:
    v_21114 = v_21115;
    v_21114 = qcar(v_21114);
    if (v_21114 == nil) goto v_21082;
    v_21114 = stack[-1];
    v_21114 = qcar(v_21114);
    v_21114 = qcdr(v_21114);
    fn = elt(env, 2); // negf
    v_21114 = (*qfn1(fn))(fn, v_21114);
    env = stack[-4];
    stack[0] = v_21114;
    goto v_21080;
v_21082:
    v_21114 = stack[-1];
    v_21114 = qcar(v_21114);
    v_21114 = qcdr(v_21114);
    stack[0] = v_21114;
    goto v_21080;
    stack[0] = nil;
v_21080:
    goto v_21073;
v_21074:
    goto v_21099;
v_21095:
    v_21115 = stack[-2];
    goto v_21096;
v_21097:
    v_21114 = stack[-1];
    v_21114 = qcdr(v_21114);
    goto v_21098;
v_21099:
    goto v_21095;
v_21096:
    goto v_21097;
v_21098:
    v_21114 = CC_innprodpex(elt(env, 0), v_21115, v_21114);
    goto v_21075;
v_21076:
    goto v_21070;
v_21071:
    goto v_21072;
v_21073:
    goto v_21074;
v_21075:
    {
        LispObject v_21120 = stack[-3];
        LispObject v_21121 = stack[0];
        return acons(v_21120, v_21121, v_21114);
    }
v_21067:
    goto v_21110;
v_21106:
    v_21115 = stack[-2];
    goto v_21107;
v_21108:
    v_21114 = stack[-1];
    v_21114 = qcdr(v_21114);
    goto v_21109;
v_21110:
    goto v_21106;
v_21107:
    goto v_21108;
v_21109:
    stack[-2] = v_21115;
    stack[-1] = v_21114;
    goto v_21041;
    v_21114 = nil;
    goto v_21046;
    v_21114 = nil;
v_21046:
    return onevalue(v_21114);
}



// Code for listeval0

static LispObject CC_listeval0(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21124, v_21125, v_21126;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21042;
// end of prologue
    goto v_21056;
v_21052:
    v_21124 = qvalue(elt(env, 1)); // simpcount!*
    v_21125 = add1(v_21124);
    env = stack[-1];
    qvalue(elt(env, 1)) = v_21125; // simpcount!*
    goto v_21053;
v_21054:
    v_21124 = qvalue(elt(env, 2)); // simplimit!*
    goto v_21055;
v_21056:
    goto v_21052;
v_21053:
    goto v_21054;
v_21055:
    v_21124 = (LispObject)greaterp2(v_21125, v_21124);
    v_21124 = v_21124 ? lisp_true : nil;
    env = stack[-1];
    if (v_21124 == nil) goto v_21050;
    v_21124 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_21124; // simpcount!*
    goto v_21068;
v_21062:
    v_21126 = elt(env, 3); // rlisp
    goto v_21063;
v_21064:
    v_21125 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_21065;
v_21066:
    v_21124 = elt(env, 4); // "Simplification recursion too deep"
    goto v_21067;
v_21068:
    goto v_21062;
v_21063:
    goto v_21064;
v_21065:
    goto v_21066;
v_21067:
    fn = elt(env, 6); // rerror
    v_21124 = (*qfnn(fn))(fn, 3, v_21126, v_21125, v_21124);
    env = stack[-1];
    goto v_21048;
v_21050:
v_21048:
    v_21124 = stack[0];
    if (symbolp(v_21124)) goto v_21074;
    else goto v_21075;
v_21074:
    v_21124 = stack[0];
    if (!symbolp(v_21124)) v_21124 = nil;
    else { v_21124 = qfastgets(v_21124);
           if (v_21124 != nil) { v_21124 = elt(v_21124, 17); // share
#ifdef RECORD_GET
             if (v_21124 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v_21124 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v_21124 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v_21124 == SPID_NOPROP) v_21124 = nil; else v_21124 = lisp_true; }}
#endif
    if (v_21124 == nil) goto v_21080;
    v_21124 = stack[0];
    fn = elt(env, 7); // eval
    v_21124 = (*qfn1(fn))(fn, v_21124);
    env = stack[-1];
    v_21124 = CC_listeval0(elt(env, 0), v_21124);
    env = stack[-1];
    stack[0] = v_21124;
    goto v_21078;
v_21080:
    v_21124 = stack[0];
    if (!symbolp(v_21124)) v_21124 = nil;
    else { v_21124 = qfastgets(v_21124);
           if (v_21124 != nil) { v_21124 = elt(v_21124, 4); // avalue
#ifdef RECORD_GET
             if (v_21124 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_21124 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_21124 == SPID_NOPROP) v_21124 = nil; }}
#endif
    v_21126 = v_21124;
    if (v_21124 == nil) goto v_21087;
    goto v_21096;
v_21092:
    v_21124 = v_21126;
    v_21124 = qcdr(v_21124);
    v_21125 = qcar(v_21124);
    goto v_21093;
v_21094:
    v_21124 = stack[0];
    goto v_21095;
v_21096:
    goto v_21092;
v_21093:
    goto v_21094;
v_21095:
    if (equal(v_21125, v_21124)) goto v_21087;
    v_21124 = v_21126;
    v_21124 = qcdr(v_21124);
    v_21124 = qcar(v_21124);
    v_21124 = CC_listeval0(elt(env, 0), v_21124);
    env = stack[-1];
    stack[0] = v_21124;
    goto v_21078;
v_21087:
v_21078:
    goto v_21073;
v_21075:
v_21073:
    goto v_21113;
v_21109:
    v_21124 = stack[0];
    v_21124 = qcar(v_21124);
    fn = elt(env, 8); // getrtype
    v_21125 = (*qfn1(fn))(fn, v_21124);
    env = stack[-1];
    goto v_21110;
v_21111:
    v_21124 = elt(env, 5); // array
    goto v_21112;
v_21113:
    goto v_21109;
v_21110:
    goto v_21111;
v_21112:
    if (v_21125 == v_21124) goto v_21107;
    else goto v_21108;
v_21107:
    v_21124 = stack[0];
    fn = elt(env, 9); // getelv
    v_21124 = (*qfn1(fn))(fn, v_21124);
    env = stack[-1];
    v_21124 = CC_listeval0(elt(env, 0), v_21124);
    env = stack[-1];
    stack[0] = v_21124;
    goto v_21106;
v_21108:
v_21106:
    v_21124 = qvalue(elt(env, 1)); // simpcount!*
    v_21124 = sub1(v_21124);
    env = stack[-1];
    qvalue(elt(env, 1)) = v_21124; // simpcount!*
    v_21124 = stack[0];
    return onevalue(v_21124);
}



// Code for bas_make

static LispObject CC_bas_make(LispObject env,
                         LispObject v_21042, LispObject v_21043)
{
    env = qenv(env);
    LispObject v_21068, v_21069;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21042,v_21043);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_21043;
    v_21068 = v_21042;
// end of prologue
    goto v_21054;
v_21046:
    stack[-3] = v_21068;
    goto v_21047;
v_21048:
    stack[-1] = stack[-2];
    goto v_21049;
v_21050:
    v_21068 = stack[-2];
    stack[0] = Llength(nil, v_21068);
    env = stack[-4];
    goto v_21051;
v_21052:
    goto v_21064;
v_21060:
    v_21068 = stack[-2];
    fn = elt(env, 1); // dp_ecart
    v_21069 = (*qfn1(fn))(fn, v_21068);
    env = stack[-4];
    goto v_21061;
v_21062:
    v_21068 = nil;
    goto v_21063;
v_21064:
    goto v_21060;
v_21061:
    goto v_21062;
v_21063:
    v_21068 = list2(v_21069, v_21068);
    goto v_21053;
v_21054:
    goto v_21046;
v_21047:
    goto v_21048;
v_21049:
    goto v_21050;
v_21051:
    goto v_21052;
v_21053:
    {
        LispObject v_21074 = stack[-3];
        LispObject v_21075 = stack[-1];
        LispObject v_21076 = stack[0];
        return list3star(v_21074, v_21075, v_21076, v_21068);
    }
}



// Code for rootextractf

static LispObject CC_rootextractf(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21356, v_21357, v_21358;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_21042;
// end of prologue
    v_21356 = stack[-3];
    if (!consp(v_21356)) goto v_21050;
    else goto v_21051;
v_21050:
    v_21356 = lisp_true;
    goto v_21049;
v_21051:
    v_21356 = stack[-3];
    v_21356 = qcar(v_21356);
    v_21356 = (consp(v_21356) ? nil : lisp_true);
    goto v_21049;
    v_21356 = nil;
v_21049:
    if (v_21356 == nil) goto v_21047;
    v_21356 = stack[-3];
    goto v_21045;
v_21047:
    v_21356 = stack[-3];
    v_21356 = qcar(v_21356);
    v_21356 = qcar(v_21356);
    v_21356 = qcar(v_21356);
    stack[-4] = v_21356;
    v_21356 = stack[-3];
    v_21356 = qcar(v_21356);
    v_21356 = qcar(v_21356);
    v_21356 = qcdr(v_21356);
    stack[0] = v_21356;
    v_21356 = stack[-3];
    v_21356 = qcdr(v_21356);
    v_21356 = CC_rootextractf(elt(env, 0), v_21356);
    env = stack[-5];
    stack[-2] = v_21356;
    v_21356 = stack[-3];
    v_21356 = qcar(v_21356);
    v_21356 = qcdr(v_21356);
    v_21356 = CC_rootextractf(elt(env, 0), v_21356);
    env = stack[-5];
    stack[-1] = v_21356;
    v_21356 = stack[-1];
    if (v_21356 == nil) goto v_21086;
    else goto v_21087;
v_21086:
    v_21356 = stack[-2];
    goto v_21068;
v_21087:
    v_21356 = stack[-4];
    if (!consp(v_21356)) goto v_21090;
    else goto v_21091;
v_21090:
    goto v_21100;
v_21094:
    v_21356 = stack[-3];
    v_21356 = qcar(v_21356);
    v_21358 = qcar(v_21356);
    goto v_21095;
v_21096:
    v_21357 = stack[-1];
    goto v_21097;
v_21098:
    v_21356 = stack[-2];
    goto v_21099;
v_21100:
    goto v_21094;
v_21095:
    goto v_21096;
v_21097:
    goto v_21098;
v_21099:
    return acons(v_21358, v_21357, v_21356);
v_21091:
    goto v_21116;
v_21112:
    v_21356 = stack[-4];
    v_21357 = qcar(v_21356);
    goto v_21113;
v_21114:
    v_21356 = elt(env, 1); // sqrt
    goto v_21115;
v_21116:
    goto v_21112;
v_21113:
    goto v_21114;
v_21115:
    if (v_21357 == v_21356) goto v_21110;
    else goto v_21111;
v_21110:
    v_21356 = lisp_true;
    goto v_21109;
v_21111:
    goto v_21131;
v_21127:
    v_21356 = stack[-4];
    v_21357 = qcar(v_21356);
    goto v_21128;
v_21129:
    v_21356 = elt(env, 2); // expt
    goto v_21130;
v_21131:
    goto v_21127;
v_21128:
    goto v_21129;
v_21130:
    if (v_21357 == v_21356) goto v_21125;
    else goto v_21126;
v_21125:
    goto v_21144;
v_21140:
    v_21356 = stack[-4];
    v_21356 = qcdr(v_21356);
    v_21356 = qcdr(v_21356);
    v_21357 = qcar(v_21356);
    goto v_21141;
v_21142:
    v_21356 = elt(env, 3); // quotient
    goto v_21143;
v_21144:
    goto v_21140;
v_21141:
    goto v_21142;
v_21143:
    if (!consp(v_21357)) goto v_21138;
    v_21357 = qcar(v_21357);
    if (v_21357 == v_21356) goto v_21137;
    else goto v_21138;
v_21137:
    goto v_21158;
v_21154:
    v_21356 = stack[-4];
    v_21356 = qcdr(v_21356);
    v_21356 = qcdr(v_21356);
    v_21356 = qcar(v_21356);
    v_21356 = qcdr(v_21356);
    v_21357 = qcar(v_21356);
    goto v_21155;
v_21156:
    v_21356 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21157;
v_21158:
    goto v_21154;
v_21155:
    goto v_21156;
v_21157:
    if (v_21357 == v_21356) goto v_21152;
    else goto v_21153;
v_21152:
    v_21356 = stack[-4];
    v_21356 = qcdr(v_21356);
    v_21356 = qcdr(v_21356);
    v_21356 = qcar(v_21356);
    v_21356 = qcdr(v_21356);
    v_21356 = qcdr(v_21356);
    v_21356 = qcar(v_21356);
    v_21356 = (is_number(v_21356) ? lisp_true : nil);
    goto v_21151;
v_21153:
    v_21356 = nil;
    goto v_21151;
    v_21356 = nil;
v_21151:
    goto v_21136;
v_21138:
    v_21356 = nil;
    goto v_21136;
    v_21356 = nil;
v_21136:
    goto v_21124;
v_21126:
    v_21356 = nil;
    goto v_21124;
    v_21356 = nil;
v_21124:
    goto v_21109;
    v_21356 = nil;
v_21109:
    if (v_21356 == nil) goto v_21107;
    goto v_21188;
v_21184:
    v_21358 = stack[0];
    goto v_21185;
v_21186:
    goto v_21198;
v_21194:
    v_21356 = stack[-4];
    v_21357 = qcar(v_21356);
    goto v_21195;
v_21196:
    v_21356 = elt(env, 1); // sqrt
    goto v_21197;
v_21198:
    goto v_21194;
v_21195:
    goto v_21196;
v_21197:
    if (v_21357 == v_21356) goto v_21192;
    else goto v_21193;
v_21192:
    v_21356 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_21191;
v_21193:
    v_21356 = stack[-4];
    v_21356 = qcdr(v_21356);
    v_21356 = qcdr(v_21356);
    v_21356 = qcar(v_21356);
    v_21356 = qcdr(v_21356);
    v_21356 = qcdr(v_21356);
    v_21356 = qcar(v_21356);
    goto v_21191;
    v_21356 = nil;
v_21191:
    goto v_21187;
v_21188:
    goto v_21184;
v_21185:
    goto v_21186;
v_21187:
    v_21356 = Ldivide(nil, v_21358, v_21356);
    env = stack[-5];
    stack[0] = v_21356;
    goto v_21220;
v_21216:
    v_21356 = stack[0];
    v_21357 = qcar(v_21356);
    goto v_21217;
v_21218:
    v_21356 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21219;
v_21220:
    goto v_21216;
v_21217:
    goto v_21218;
v_21219:
    if (v_21357 == v_21356) goto v_21214;
    else goto v_21215;
v_21214:
    v_21356 = stack[-1];
    if (v_21356 == nil) goto v_21226;
    else goto v_21227;
v_21226:
    v_21356 = stack[-2];
    goto v_21225;
v_21227:
    goto v_21239;
v_21233:
    v_21356 = stack[-3];
    v_21356 = qcar(v_21356);
    v_21358 = qcar(v_21356);
    goto v_21234;
v_21235:
    v_21357 = stack[-1];
    goto v_21236;
v_21237:
    v_21356 = stack[-2];
    goto v_21238;
v_21239:
    goto v_21233;
v_21234:
    goto v_21235;
v_21236:
    goto v_21237;
v_21238:
    return acons(v_21358, v_21357, v_21356);
    v_21356 = nil;
v_21225:
    goto v_21068;
v_21215:
    v_21356 = stack[-4];
    v_21356 = qcdr(v_21356);
    v_21356 = qcar(v_21356);
    if (is_number(v_21356)) goto v_21245;
    else goto v_21246;
v_21245:
    goto v_21255;
v_21251:
    goto v_21261;
v_21257:
    v_21356 = stack[-4];
    v_21356 = qcdr(v_21356);
    v_21357 = qcar(v_21356);
    goto v_21258;
v_21259:
    v_21356 = stack[0];
    v_21356 = qcar(v_21356);
    goto v_21260;
v_21261:
    goto v_21257;
v_21258:
    goto v_21259;
v_21260:
    v_21357 = Lexpt(nil, v_21357, v_21356);
    env = stack[-5];
    goto v_21252;
v_21253:
    v_21356 = stack[-1];
    goto v_21254;
v_21255:
    goto v_21251;
v_21252:
    goto v_21253;
v_21254:
    fn = elt(env, 4); // multd
    v_21356 = (*qfn2(fn))(fn, v_21357, v_21356);
    env = stack[-5];
    stack[-1] = v_21356;
    v_21356 = stack[0];
    v_21356 = qcdr(v_21356);
    stack[0] = v_21356;
    goto v_21213;
v_21246:
    goto v_21278;
v_21274:
    v_21356 = stack[-4];
    v_21356 = qcdr(v_21356);
    v_21357 = qcar(v_21356);
    goto v_21275;
v_21276:
    v_21356 = stack[0];
    v_21356 = qcar(v_21356);
    goto v_21277;
v_21278:
    goto v_21274;
v_21275:
    goto v_21276;
v_21277:
    v_21356 = list2(v_21357, v_21356);
    env = stack[-5];
    fn = elt(env, 5); // simpexpt
    v_21356 = (*qfn1(fn))(fn, v_21356);
    env = stack[-5];
    v_21358 = v_21356;
    goto v_21292;
v_21288:
    v_21356 = v_21358;
    v_21357 = qcdr(v_21356);
    goto v_21289;
v_21290:
    v_21356 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21291;
v_21292:
    goto v_21288;
v_21289:
    goto v_21290;
v_21291:
    if (v_21357 == v_21356) goto v_21286;
    else goto v_21287;
v_21286:
    goto v_21301;
v_21297:
    v_21356 = v_21358;
    v_21357 = qcar(v_21356);
    goto v_21298;
v_21299:
    v_21356 = stack[-1];
    goto v_21300;
v_21301:
    goto v_21297;
v_21298:
    goto v_21299;
v_21300:
    fn = elt(env, 6); // multf
    v_21356 = (*qfn2(fn))(fn, v_21357, v_21356);
    env = stack[-5];
    stack[-1] = v_21356;
    v_21356 = stack[0];
    v_21356 = qcdr(v_21356);
    stack[0] = v_21356;
    goto v_21285;
v_21287:
    v_21356 = stack[-3];
    v_21356 = qcar(v_21356);
    v_21356 = qcar(v_21356);
    v_21356 = qcdr(v_21356);
    stack[0] = v_21356;
    goto v_21285;
v_21285:
    goto v_21213;
v_21213:
    goto v_21085;
v_21107:
v_21085:
    goto v_21321;
v_21317:
    v_21357 = stack[0];
    goto v_21318;
v_21319:
    v_21356 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21320;
v_21321:
    goto v_21317;
v_21318:
    goto v_21319;
v_21320:
    if (v_21357 == v_21356) goto v_21315;
    else goto v_21316;
v_21315:
    goto v_21329;
v_21325:
    v_21357 = stack[-1];
    goto v_21326;
v_21327:
    v_21356 = stack[-2];
    goto v_21328;
v_21329:
    goto v_21325;
v_21326:
    goto v_21327;
v_21328:
    {
        fn = elt(env, 7); // addf
        return (*qfn2(fn))(fn, v_21357, v_21356);
    }
v_21316:
    v_21356 = stack[-1];
    if (v_21356 == nil) goto v_21332;
    else goto v_21333;
v_21332:
    v_21356 = stack[-2];
    goto v_21314;
v_21333:
    goto v_21345;
v_21339:
    goto v_21351;
v_21347:
    v_21357 = stack[-4];
    goto v_21348;
v_21349:
    v_21356 = stack[0];
    goto v_21350;
v_21351:
    goto v_21347;
v_21348:
    goto v_21349;
v_21350:
    fn = elt(env, 8); // to
    v_21358 = (*qfn2(fn))(fn, v_21357, v_21356);
    goto v_21340;
v_21341:
    v_21357 = stack[-1];
    goto v_21342;
v_21343:
    v_21356 = stack[-2];
    goto v_21344;
v_21345:
    goto v_21339;
v_21340:
    goto v_21341;
v_21342:
    goto v_21343;
v_21344:
    return acons(v_21358, v_21357, v_21356);
    v_21356 = nil;
v_21314:
v_21068:
    goto v_21045;
    v_21356 = nil;
v_21045:
    return onevalue(v_21356);
}



// Code for ra_u

static LispObject CC_ra_u(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21047;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21047 = v_21042;
// end of prologue
    fn = elt(env, 1); // ra_iv
    v_21047 = (*qfn1(fn))(fn, v_21047);
    env = stack[0];
    {
        fn = elt(env, 2); // riv_u
        return (*qfn1(fn))(fn, v_21047);
    }
}



// Code for lastcar

static LispObject CC_lastcar(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21063, v_21064;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21063 = v_21042;
// end of prologue
v_21046:
    v_21064 = v_21063;
    if (v_21064 == nil) goto v_21049;
    else goto v_21050;
v_21049:
    v_21063 = nil;
    goto v_21045;
v_21050:
    v_21064 = v_21063;
    v_21064 = qcdr(v_21064);
    if (v_21064 == nil) goto v_21053;
    else goto v_21054;
v_21053:
    v_21063 = qcar(v_21063);
    goto v_21045;
v_21054:
    v_21063 = qcdr(v_21063);
    goto v_21046;
    v_21063 = nil;
v_21045:
    return onevalue(v_21063);
}



// Code for ofsf_decdeg2

static LispObject CC_ofsf_decdeg2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21260, v_21261, v_21262;
    LispObject fn;
    LispObject v_21044, v_21043, v_21042;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_decdeg2");
    va_start(aa, nargs);
    v_21042 = va_arg(aa, LispObject);
    v_21043 = va_arg(aa, LispObject);
    v_21044 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21044,v_21043,v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21042,v_21043,v_21044);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_21044;
    stack[-5] = v_21043;
    stack[-3] = v_21042;
// end of prologue
// Binding !*gcd
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-7, 1, -2);
    qvalue(elt(env, 1)) = nil; // !*gcd
    stack[-1] = nil;
    v_21260 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_21260;
    v_21260 = lisp_true;
    qvalue(elt(env, 1)) = v_21260; // !*gcd
    v_21260 = qvalue(elt(env, 2)); // !*rlbrkcxk
    if (v_21260 == nil) goto v_21059;
    goto v_21066;
v_21062:
    v_21261 = stack[-3];
    goto v_21063;
v_21064:
    v_21260 = stack[-5];
    goto v_21065;
v_21066:
    goto v_21062;
v_21063:
    goto v_21064;
v_21065:
    fn = elt(env, 4); // ofsf_cxkdgcd
    v_21260 = (*qfn2(fn))(fn, v_21261, v_21260);
    env = stack[-7];
    stack[0] = v_21260;
    goto v_21057;
v_21059:
v_21057:
    v_21260 = stack[-3];
    fn = elt(env, 5); // cl_atl1
    v_21260 = (*qfn1(fn))(fn, v_21260);
    env = stack[-7];
    stack[-3] = v_21260;
v_21073:
    v_21260 = stack[-3];
    if (v_21260 == nil) goto v_21076;
    goto v_21086;
v_21082:
    v_21261 = stack[0];
    goto v_21083;
v_21084:
    v_21260 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21085;
v_21086:
    goto v_21082;
v_21083:
    goto v_21084;
v_21085:
    v_21260 = Leqn(nil, v_21261, v_21260);
    env = stack[-7];
    if (v_21260 == nil) goto v_21080;
    else goto v_21076;
v_21080:
    goto v_21077;
v_21076:
    goto v_21072;
v_21077:
    v_21260 = stack[-3];
    v_21260 = qcar(v_21260);
    v_21261 = v_21260;
    v_21260 = stack[-3];
    v_21260 = qcdr(v_21260);
    stack[-3] = v_21260;
    v_21260 = v_21261;
    stack[-6] = v_21260;
    goto v_21106;
v_21100:
    v_21262 = stack[-6];
    goto v_21101;
v_21102:
    v_21261 = stack[-5];
    goto v_21103;
v_21104:
    v_21260 = stack[-4];
    goto v_21105;
v_21106:
    goto v_21100;
v_21101:
    goto v_21102;
v_21103:
    goto v_21104;
v_21105:
    fn = elt(env, 6); // ofsf_ignshift
    v_21260 = (*qfnn(fn))(fn, 3, v_21262, v_21261, v_21260);
    env = stack[-7];
    v_21262 = v_21260;
    goto v_21122;
v_21118:
    v_21261 = v_21262;
    goto v_21119;
v_21120:
    v_21260 = elt(env, 3); // odd
    goto v_21121;
v_21122:
    goto v_21118;
v_21119:
    goto v_21120;
v_21121:
    if (v_21261 == v_21260) goto v_21116;
    else goto v_21117;
v_21116:
    v_21260 = stack[-1];
    v_21260 = (v_21260 == nil ? lisp_true : nil);
    goto v_21115;
v_21117:
    v_21260 = nil;
    goto v_21115;
    v_21260 = nil;
v_21115:
    if (v_21260 == nil) goto v_21113;
    v_21260 = elt(env, 3); // odd
    stack[-1] = v_21260;
    goto v_21111;
v_21113:
    v_21260 = v_21262;
    if (v_21260 == nil) goto v_21131;
    else goto v_21132;
v_21131:
    goto v_21139;
v_21135:
    v_21260 = stack[-6];
    v_21260 = qcdr(v_21260);
    v_21261 = qcar(v_21260);
    goto v_21136;
v_21137:
    v_21260 = stack[-5];
    goto v_21138;
v_21139:
    goto v_21135;
v_21136:
    goto v_21137;
v_21138:
    fn = elt(env, 7); // sfto_reorder
    v_21260 = (*qfn2(fn))(fn, v_21261, v_21260);
    env = stack[-7];
    stack[-6] = v_21260;
v_21146:
    v_21260 = stack[-6];
    if (!consp(v_21260)) goto v_21157;
    else goto v_21158;
v_21157:
    v_21260 = lisp_true;
    goto v_21156;
v_21158:
    v_21260 = stack[-6];
    v_21260 = qcar(v_21260);
    v_21260 = (consp(v_21260) ? nil : lisp_true);
    goto v_21156;
    v_21260 = nil;
v_21156:
    if (v_21260 == nil) goto v_21153;
    else goto v_21154;
v_21153:
    goto v_21174;
v_21170:
    v_21260 = stack[-6];
    v_21260 = qcar(v_21260);
    v_21260 = qcar(v_21260);
    v_21261 = qcar(v_21260);
    goto v_21171;
v_21172:
    v_21260 = stack[-5];
    goto v_21173;
v_21174:
    goto v_21170;
v_21171:
    goto v_21172;
v_21173:
    if (v_21261 == v_21260) goto v_21168;
    else goto v_21169;
v_21168:
    goto v_21185;
v_21181:
    v_21261 = stack[0];
    goto v_21182;
v_21183:
    v_21260 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21184;
v_21185:
    goto v_21181;
v_21182:
    goto v_21183;
v_21184:
    v_21260 = Lneq(nil, v_21261, v_21260);
    env = stack[-7];
    goto v_21167;
v_21169:
    v_21260 = nil;
    goto v_21167;
    v_21260 = nil;
v_21167:
    goto v_21152;
v_21154:
    v_21260 = nil;
    goto v_21152;
    v_21260 = nil;
v_21152:
    if (v_21260 == nil) goto v_21149;
    else goto v_21150;
v_21149:
    goto v_21145;
v_21150:
    goto v_21200;
v_21196:
    v_21261 = stack[0];
    goto v_21197;
v_21198:
    v_21260 = stack[-6];
    v_21260 = qcar(v_21260);
    v_21260 = qcar(v_21260);
    v_21260 = qcdr(v_21260);
    goto v_21199;
v_21200:
    goto v_21196;
v_21197:
    goto v_21198;
v_21199:
    fn = elt(env, 8); // gcdf
    v_21260 = (*qfn2(fn))(fn, v_21261, v_21260);
    env = stack[-7];
    stack[0] = v_21260;
    v_21260 = stack[-6];
    v_21260 = qcdr(v_21260);
    stack[-6] = v_21260;
    goto v_21146;
v_21145:
    goto v_21111;
v_21132:
v_21111:
    goto v_21218;
v_21214:
    v_21261 = stack[0];
    goto v_21215;
v_21216:
    v_21260 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21217;
v_21218:
    goto v_21214;
v_21215:
    goto v_21216;
v_21217:
    v_21260 = (LispObject)greaterp2(v_21261, v_21260);
    v_21260 = v_21260 ? lisp_true : nil;
    env = stack[-7];
    if (v_21260 == nil) goto v_21211;
    goto v_21226;
v_21222:
    v_21261 = stack[-1];
    goto v_21223;
v_21224:
    v_21260 = elt(env, 3); // odd
    goto v_21225;
v_21226:
    goto v_21222;
v_21223:
    goto v_21224;
v_21225:
    if (v_21261 == v_21260) goto v_21221;
    else goto v_21211;
v_21221:
    v_21260 = lisp_true;
    stack[-1] = v_21260;
v_21232:
    goto v_21242;
v_21238:
    v_21261 = stack[0];
    goto v_21239;
v_21240:
    v_21260 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_21241;
v_21242:
    goto v_21238;
v_21239:
    goto v_21240;
v_21241:
    fn = elt(env, 9); // quotf
    v_21260 = (*qfn2(fn))(fn, v_21261, v_21260);
    env = stack[-7];
    v_21262 = v_21260;
    if (v_21260 == nil) goto v_21235;
    else goto v_21236;
v_21235:
    goto v_21231;
v_21236:
    v_21260 = v_21262;
    stack[0] = v_21260;
    goto v_21232;
v_21231:
    goto v_21209;
v_21211:
v_21209:
    goto v_21073;
v_21072:
    goto v_21255;
v_21251:
    v_21261 = stack[0];
    goto v_21252;
v_21253:
    v_21260 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21254;
v_21255:
    goto v_21251;
v_21252:
    goto v_21253;
v_21254:
    if (v_21261 == v_21260) goto v_21249;
    else goto v_21250;
v_21249:
    v_21260 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21053;
v_21250:
    v_21260 = stack[0];
v_21053:
    ;}  // end of a binding scope
    return onevalue(v_21260);
}



// Code for settcollectnonmultiprolongations

static LispObject CC_settcollectnonmultiprolongations(LispObject env,
                         LispObject v_21042)
{
    env = qenv(env);
    LispObject v_21180, v_21181, v_21182;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21042);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21042);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_21042;
// end of prologue
    v_21180 = qvalue(elt(env, 1)); // fluidbibasissett
    v_21180 = qcar(v_21180);
    if (v_21180 == nil) goto v_21047;
    v_21180 = qvalue(elt(env, 1)); // fluidbibasissett
    v_21180 = qcar(v_21180);
    stack[-4] = v_21180;
    goto v_21064;
v_21060:
    v_21181 = stack[-4];
    goto v_21061;
v_21062:
    v_21180 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21063;
v_21064:
    goto v_21060;
v_21061:
    goto v_21062;
v_21063:
    v_21180 = *(LispObject *)((char *)v_21181 + (CELL-TAG_VECTOR) + (((intptr_t)v_21180-TAG_FIXNUM)/(16/CELL)));
    v_21180 = qcar(v_21180);
    fn = elt(env, 3); // monomgetfirstmultivar
    v_21180 = (*qfn1(fn))(fn, v_21180);
    env = stack[-5];
    v_21180 = (LispObject)((intptr_t)(v_21180) - 0x10);
    stack[-1] = v_21180;
    v_21180 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_21180;
v_21073:
    goto v_21085;
v_21081:
    v_21181 = stack[-1];
    goto v_21082;
v_21083:
    v_21180 = stack[0];
    goto v_21084;
v_21085:
    goto v_21081;
v_21082:
    goto v_21083;
v_21084:
    v_21180 = difference2(v_21181, v_21180);
    env = stack[-5];
    v_21180 = Lminusp(nil, v_21180);
    env = stack[-5];
    if (v_21180 == nil) goto v_21078;
    goto v_21072;
v_21078:
    goto v_21098;
v_21094:
    v_21181 = stack[-4];
    goto v_21095;
v_21096:
    v_21180 = stack[0];
    goto v_21097;
v_21098:
    goto v_21094;
v_21095:
    goto v_21096;
v_21097:
    fn = elt(env, 4); // tripleisprolongedby
    v_21180 = (*qfn2(fn))(fn, v_21181, v_21180);
    env = stack[-5];
    if (v_21180 == nil) goto v_21091;
    else goto v_21092;
v_21091:
    goto v_21106;
v_21102:
    goto v_21111;
v_21107:
    v_21181 = stack[-4];
    goto v_21108;
v_21109:
    v_21180 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21110;
v_21111:
    goto v_21107;
v_21108:
    goto v_21109;
v_21110:
    v_21182 = *(LispObject *)((char *)v_21181 + (CELL-TAG_VECTOR) + (((intptr_t)v_21180-TAG_FIXNUM)/(16/CELL)));
    goto v_21103;
v_21104:
    goto v_21119;
v_21115:
    v_21181 = qvalue(elt(env, 2)); // fluidbibasissinglevariablemonomialss
    goto v_21116;
v_21117:
    v_21180 = stack[0];
    goto v_21118;
v_21119:
    goto v_21115;
v_21116:
    goto v_21117;
v_21118:
    v_21180 = *(LispObject *)((char *)v_21181 + (CELL-TAG_VECTOR) + (((intptr_t)v_21180-TAG_FIXNUM)/(16/CELL)));
    goto v_21105;
v_21106:
    goto v_21102;
v_21103:
    goto v_21104;
v_21105:
    fn = elt(env, 5); // polynommultiplybymonom
    v_21180 = (*qfn2(fn))(fn, v_21182, v_21180);
    env = stack[-5];
    stack[-2] = v_21180;
    goto v_21128;
v_21124:
    v_21181 = stack[-4];
    goto v_21125;
v_21126:
    v_21180 = stack[0];
    goto v_21127;
v_21128:
    goto v_21124;
v_21125:
    goto v_21126;
v_21127:
    fn = elt(env, 6); // triplesetprolongedby
    v_21180 = (*qfn2(fn))(fn, v_21181, v_21180);
    env = stack[-5];
    v_21180 = stack[-2];
    v_21180 = qcar(v_21180);
    if (v_21180 == nil) goto v_21134;
    goto v_21142;
v_21138:
    v_21182 = stack[-2];
    goto v_21139;
v_21140:
    goto v_21148;
v_21144:
    v_21181 = stack[-4];
    goto v_21145;
v_21146:
    v_21180 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_21147;
v_21148:
    goto v_21144;
v_21145:
    goto v_21146;
v_21147:
    v_21180 = *(LispObject *)((char *)v_21181 + (CELL-TAG_VECTOR) + (((intptr_t)v_21180-TAG_FIXNUM)/(16/CELL)));
    goto v_21141;
v_21142:
    goto v_21138;
v_21139:
    goto v_21140;
v_21141:
    fn = elt(env, 7); // createtriplewithancestor
    v_21180 = (*qfn2(fn))(fn, v_21182, v_21180);
    env = stack[-5];
    stack[-2] = v_21180;
    goto v_21157;
v_21153:
    v_21182 = stack[-2];
    goto v_21154;
v_21155:
    goto v_21163;
v_21159:
    v_21181 = stack[-4];
    goto v_21160;
v_21161:
    v_21180 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_21162;
v_21163:
    goto v_21159;
v_21160:
    goto v_21161;
v_21162:
    v_21180 = *(LispObject *)((char *)v_21181 + (CELL-TAG_VECTOR) + (((intptr_t)v_21180-TAG_FIXNUM)/(16/CELL)));
    goto v_21156;
v_21157:
    goto v_21153;
v_21154:
    goto v_21155;
v_21156:
    fn = elt(env, 8); // triplesetprolongset
    v_21180 = (*qfn2(fn))(fn, v_21182, v_21180);
    env = stack[-5];
    goto v_21172;
v_21168:
    v_21181 = stack[-3];
    goto v_21169;
v_21170:
    v_21180 = stack[-2];
    goto v_21171;
v_21172:
    goto v_21168;
v_21169:
    goto v_21170;
v_21171:
    fn = elt(env, 9); // sortedtriplelistinsert
    v_21180 = (*qfn2(fn))(fn, v_21181, v_21180);
    env = stack[-5];
    goto v_21132;
v_21134:
v_21132:
    goto v_21090;
v_21092:
v_21090:
    v_21180 = stack[0];
    v_21180 = add1(v_21180);
    env = stack[-5];
    stack[0] = v_21180;
    goto v_21073;
v_21072:
    v_21180 = nil;
    goto v_21045;
v_21047:
    v_21180 = nil;
v_21045:
    return onevalue(v_21180);
}



setup_type const u37_setup[] =
{
    {"sparpri",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_sparpri},
    {"string2bytelist",         CC_string2bytelist,TOO_MANY_1, WRONG_NO_1},
    {"sublap",                  TOO_FEW_2,      CC_sublap,     WRONG_NO_2},
    {"deletez1",                TOO_FEW_2,      CC_deletez1,   WRONG_NO_2},
    {"assert_kernelp",          CC_assert_kernelp,TOO_MANY_1,  WRONG_NO_1},
    {"**a2i",                   TOO_FEW_2,      CC_HHa2i,      WRONG_NO_2},
    {"gvar1",                   TOO_FEW_2,      CC_gvar1,      WRONG_NO_2},
    {"drnconv",                 CC_drnconv,     TOO_MANY_1,    WRONG_NO_1},
    {"split-further",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_splitKfurther},
    {"lex_init",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex_init},
    {"sfto_lmultf",             CC_sfto_lmultf, TOO_MANY_1,    WRONG_NO_1},
    {"give*position",           TOO_FEW_2,      CC_giveHposition,WRONG_NO_2},
    {"talp_specsub",            TOO_FEW_2,      CC_talp_specsub,WRONG_NO_2},
    {"mconv1",                  CC_mconv1,      TOO_MANY_1,    WRONG_NO_1},
    {"pasf_uprap",              CC_pasf_uprap,  TOO_MANY_1,    WRONG_NO_1},
    {"sfto_mvarx",              CC_sfto_mvarx,  TOO_MANY_1,    WRONG_NO_1},
    {"ciml",                    CC_ciml,        TOO_MANY_1,    WRONG_NO_1},
    {"matrixp",                 CC_matrixp,     TOO_MANY_1,    WRONG_NO_1},
    {"evequal",                 TOO_FEW_2,      CC_evequal,    WRONG_NO_2},
    {"exdff0",                  CC_exdff0,      TOO_MANY_1,    WRONG_NO_1},
    {"gftimes",                 TOO_FEW_2,      CC_gftimes,    WRONG_NO_2},
    {"getphystypeall",          CC_getphystypeall,TOO_MANY_1,  WRONG_NO_1},
    {"groeb=crita",             CC_groebMcrita, TOO_MANY_1,    WRONG_NO_1},
    {"taydegree<",              TOO_FEW_2,      CC_taydegreeR, WRONG_NO_2},
    {"cl_pnf2",                 CC_cl_pnf2,     TOO_MANY_1,    WRONG_NO_1},
    {"vdp_setsugar",            TOO_FEW_2,      CC_vdp_setsugar,WRONG_NO_2},
    {"setrd",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setrd},
    {"collectphysops_reversed", TOO_FEW_2,      CC_collectphysops_reversed,WRONG_NO_2},
    {"evalgreaterp",            TOO_FEW_2,      CC_evalgreaterp,WRONG_NO_2},
    {"subcare",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_subcare},
    {"fs:make-nullangle",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_fsTmakeKnullangle},
    {"ratlessp",                TOO_FEW_2,      CC_ratlessp,   WRONG_NO_2},
    {"giplus:",                 TOO_FEW_2,      CC_giplusT,    WRONG_NO_2},
    {"multivariatep",           TOO_FEW_2,      CC_multivariatep,WRONG_NO_2},
    {"rl_qefsolset",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rl_qefsolset},
    {"sfto_b:extadd",           TOO_FEW_2,      CC_sfto_bTextadd,WRONG_NO_2},
    {"bvarom",                  CC_bvarom,      TOO_MANY_1,    WRONG_NO_1},
    {"degreef",                 TOO_FEW_2,      CC_degreef,    WRONG_NO_2},
    {"r2findindex1",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_r2findindex1},
    {"apply_e",                 CC_apply_e,     TOO_MANY_1,    WRONG_NO_1},
    {"sqprint",                 CC_sqprint,     TOO_MANY_1,    WRONG_NO_1},
    {"reduce-eival-powers",     TOO_FEW_2,      CC_reduceKeivalKpowers,WRONG_NO_2},
    {"make-image",              TOO_FEW_2,      CC_makeKimage, WRONG_NO_2},
    {"freeoflist",              TOO_FEW_2,      CC_freeoflist, WRONG_NO_2},
    {"ofsf_sippsubst1",         TOO_FEW_2,      CC_ofsf_sippsubst1,WRONG_NO_2},
    {"talp_maxd",               CC_talp_maxd,   TOO_MANY_1,    WRONG_NO_1},
    {"ctx_filter",              TOO_FEW_2,      CC_ctx_filter, WRONG_NO_2},
    {"containerom",             CC_containerom, TOO_MANY_1,    WRONG_NO_1},
    {"s-nextarg",               CC_sKnextarg,   TOO_MANY_1,    WRONG_NO_1},
    {"wedgef",                  CC_wedgef,      TOO_MANY_1,    WRONG_NO_1},
    {"gbfplus",                 TOO_FEW_2,      CC_gbfplus,    WRONG_NO_2},
    {"::quotient",              TOO_FEW_2,      CC_TTquotient, WRONG_NO_2},
    {"contr2",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_contr2},
    {"innprodpex",              TOO_FEW_2,      CC_innprodpex, WRONG_NO_2},
    {"listeval0",               CC_listeval0,   TOO_MANY_1,    WRONG_NO_1},
    {"bas_make",                TOO_FEW_2,      CC_bas_make,   WRONG_NO_2},
    {"rootextractf",            CC_rootextractf,TOO_MANY_1,    WRONG_NO_1},
    {"ra_u",                    CC_ra_u,        TOO_MANY_1,    WRONG_NO_1},
    {"lastcar",                 CC_lastcar,     TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_decdeg2",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_decdeg2},
    {"settcollectnonmultiprolongations",CC_settcollectnonmultiprolongations,TOO_MANY_1,WRONG_NO_1},
    {NULL, (one_args *)"u37", (two_args *)"155891 7047946 6586320", 0}
};

// end of generated code
