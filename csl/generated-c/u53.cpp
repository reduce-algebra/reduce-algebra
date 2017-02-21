
// $destdir/u53.c        Machine generated C code

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



// Code for rule!*

static LispObject CC_ruleH(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31231, v_31232, v_31233, v_31234, v_31235;
    LispObject fn;
    LispObject v_31016, v_31015, v_31014, v_31013, v_31012;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "rule*");
    va_start(aa, nargs);
    v_31012 = va_arg(aa, LispObject);
    v_31013 = va_arg(aa, LispObject);
    v_31014 = va_arg(aa, LispObject);
    v_31015 = va_arg(aa, LispObject);
    v_31016 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_31016,v_31015,v_31014,v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_31012,v_31013,v_31014,v_31015,v_31016);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[0] = v_31016;
    stack[-1] = v_31015;
    stack[-2] = v_31014;
    stack[-3] = v_31013;
    stack[-4] = v_31012;
// end of prologue
    stack[-5] = nil;
    v_31231 = stack[-2];
    qvalue(elt(env, 1)) = v_31231; // frasc!*
    goto v_31030;
v_31026:
    v_31232 = stack[-1];
    goto v_31027;
v_31028:
    v_31231 = lisp_true;
    goto v_31029;
v_31030:
    goto v_31026;
v_31027:
    goto v_31028;
v_31029:
    if (v_31232 == v_31231) goto v_31024;
    else goto v_31025;
v_31024:
    v_31231 = lisp_true;
    goto v_31023;
v_31025:
    goto v_31041;
v_31037:
    v_31232 = stack[-2];
    goto v_31038;
v_31039:
    v_31231 = stack[-1];
    goto v_31040;
v_31041:
    goto v_31037;
v_31038:
    goto v_31039;
v_31040:
    v_31231 = Lsubla(nil, v_31232, v_31231);
    env = stack[-6];
    goto v_31023;
    v_31231 = nil;
v_31023:
    qvalue(elt(env, 2)) = v_31231; // mcond!*
    v_31231 = stack[0];
    if (v_31231 == nil) goto v_31047;
    goto v_31055;
v_31051:
    v_31232 = stack[0];
    goto v_31052;
v_31053:
    v_31231 = elt(env, 3); // old
    goto v_31054;
v_31055:
    goto v_31051;
v_31052:
    goto v_31053;
v_31054:
    if (v_31232 == v_31231) goto v_31047;
    goto v_31067;
v_31059:
    v_31234 = stack[-4];
    goto v_31060;
v_31061:
    v_31233 = stack[-3];
    goto v_31062;
v_31063:
    v_31232 = stack[-2];
    goto v_31064;
v_31065:
    v_31231 = stack[-1];
    goto v_31066;
v_31067:
    goto v_31059;
v_31060:
    goto v_31061;
v_31062:
    goto v_31063;
v_31064:
    goto v_31065;
v_31066:
    v_31231 = list4(v_31234, v_31233, v_31232, v_31231);
    env = stack[-6];
    qvalue(elt(env, 4)) = v_31231; // newrule!*
    v_31231 = stack[-4];
    if (symbolp(v_31231)) goto v_31074;
    else goto v_31075;
v_31074:
    v_31231 = stack[-4];
    if (!symbolp(v_31231)) v_31231 = nil;
    else { v_31231 = qfastgets(v_31231);
           if (v_31231 != nil) { v_31231 = elt(v_31231, 2); // rtype
#ifdef RECORD_GET
             if (v_31231 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_31231 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_31231 == SPID_NOPROP) v_31231 = nil; }}
#endif
    stack[-5] = v_31231;
    if (v_31231 == nil) goto v_31080;
    goto v_31090;
v_31084:
    stack[-1] = stack[-4];
    goto v_31085;
v_31086:
    goto v_31097;
v_31093:
    v_31232 = elt(env, 5); // rtype
    goto v_31094;
v_31095:
    v_31231 = stack[-5];
    goto v_31096;
v_31097:
    goto v_31093;
v_31094:
    goto v_31095;
v_31096:
    v_31232 = cons(v_31232, v_31231);
    env = stack[-6];
    goto v_31087;
v_31088:
    v_31231 = qvalue(elt(env, 6)); // props!*
    goto v_31089;
v_31090:
    goto v_31084;
v_31085:
    goto v_31086;
v_31087:
    goto v_31088;
v_31089:
    v_31231 = acons(stack[-1], v_31232, v_31231);
    env = stack[-6];
    qvalue(elt(env, 6)) = v_31231; // props!*
    goto v_31106;
v_31102:
    v_31232 = stack[-4];
    goto v_31103;
v_31104:
    v_31231 = elt(env, 5); // rtype
    goto v_31105;
v_31106:
    goto v_31102;
v_31103:
    goto v_31104;
v_31105:
    v_31231 = Lremprop(nil, v_31232, v_31231);
    env = stack[-6];
    goto v_31078;
v_31080:
v_31078:
    v_31231 = stack[-4];
    if (!symbolp(v_31231)) v_31231 = nil;
    else { v_31231 = qfastgets(v_31231);
           if (v_31231 != nil) { v_31231 = elt(v_31231, 4); // avalue
#ifdef RECORD_GET
             if (v_31231 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_31231 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_31231 == SPID_NOPROP) v_31231 = nil; }}
#endif
    stack[-5] = v_31231;
    if (v_31231 == nil) goto v_31112;
    goto v_31120;
v_31116:
    v_31232 = stack[-5];
    goto v_31117;
v_31118:
    v_31231 = nil;
    goto v_31119;
v_31120:
    goto v_31116;
v_31117:
    goto v_31118;
v_31119:
    fn = elt(env, 10); // updoldrules
    v_31231 = (*qfn2(fn))(fn, v_31232, v_31231);
    env = stack[-6];
    goto v_31128;
v_31124:
    v_31232 = stack[-4];
    goto v_31125;
v_31126:
    v_31231 = elt(env, 7); // avalue
    goto v_31127;
v_31128:
    goto v_31124;
v_31125:
    goto v_31126;
v_31127:
    v_31231 = Lremprop(nil, v_31232, v_31231);
    env = stack[-6];
    goto v_31110;
v_31112:
v_31110:
    goto v_31073;
v_31075:
v_31073:
    goto v_31143;
v_31139:
    v_31232 = stack[-3];
    goto v_31140;
v_31141:
    v_31231 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31142;
v_31143:
    goto v_31139;
v_31140:
    goto v_31141;
v_31142:
    if (v_31232 == v_31231) goto v_31137;
    else goto v_31138;
v_31137:
    goto v_31155;
v_31151:
    v_31232 = stack[-4];
    goto v_31152;
v_31153:
    v_31231 = elt(env, 8); // expt
    goto v_31154;
v_31155:
    goto v_31151;
v_31152:
    goto v_31153;
v_31154:
    if (!consp(v_31232)) goto v_31149;
    v_31232 = qcar(v_31232);
    if (v_31232 == v_31231) goto v_31148;
    else goto v_31149;
v_31148:
    v_31231 = stack[-4];
    v_31231 = qcdr(v_31231);
    v_31231 = qcar(v_31231);
    if (symbolp(v_31231)) goto v_31161;
    v_31231 = nil;
    goto v_31159;
v_31161:
    v_31231 = stack[-4];
    v_31231 = qcdr(v_31231);
    v_31231 = qcdr(v_31231);
    v_31231 = qcar(v_31231);
    if (is_number(v_31231)) goto v_31171;
    v_31231 = nil;
    goto v_31169;
v_31171:
    goto v_31183;
v_31179:
    v_31231 = stack[-4];
    v_31231 = qcdr(v_31231);
    v_31232 = qcar(v_31231);
    goto v_31180;
v_31181:
    v_31231 = qvalue(elt(env, 9)); // asymplis!*
    goto v_31182;
v_31183:
    goto v_31179;
v_31180:
    goto v_31181;
v_31182:
    v_31231 = Lassoc(nil, v_31232, v_31231);
    stack[-5] = v_31231;
    goto v_31169;
    v_31231 = nil;
v_31169:
    goto v_31159;
    v_31231 = nil;
v_31159:
    goto v_31147;
v_31149:
    v_31231 = nil;
    goto v_31147;
    v_31231 = nil;
v_31147:
    goto v_31136;
v_31138:
    v_31231 = nil;
    goto v_31136;
    v_31231 = nil;
v_31136:
    if (v_31231 == nil) goto v_31134;
    goto v_31200;
v_31196:
    v_31232 = stack[-5];
    goto v_31197;
v_31198:
    v_31231 = nil;
    goto v_31199;
v_31200:
    goto v_31196;
v_31197:
    goto v_31198;
v_31199:
    fn = elt(env, 10); // updoldrules
    v_31231 = (*qfn2(fn))(fn, v_31232, v_31231);
    env = stack[-6];
    goto v_31132;
v_31134:
v_31132:
    goto v_31045;
v_31047:
v_31045:
    goto v_31212;
v_31204:
    v_31235 = stack[-4];
    goto v_31205;
v_31206:
    v_31234 = stack[-3];
    goto v_31207;
v_31208:
    v_31233 = stack[-2];
    goto v_31209;
v_31210:
    goto v_31224;
v_31220:
    v_31232 = stack[0];
    goto v_31221;
v_31222:
    v_31231 = elt(env, 3); // old
    goto v_31223;
v_31224:
    goto v_31220;
v_31221:
    goto v_31222;
v_31223:
    if (v_31232 == v_31231) goto v_31218;
    else goto v_31219;
v_31218:
    v_31231 = lisp_true;
    goto v_31217;
v_31219:
    v_31231 = stack[0];
    goto v_31217;
    v_31231 = nil;
v_31217:
    goto v_31211;
v_31212:
    goto v_31204;
v_31205:
    goto v_31206;
v_31207:
    goto v_31208;
v_31209:
    goto v_31210;
v_31211:
    {
        fn = elt(env, 11); // rule
        return (*qfnn(fn))(fn, 4, v_31235, v_31234, v_31233, v_31231);
    }
    return onevalue(v_31231);
}



// Code for mk_resimp_rep

static LispObject CC_mk_resimp_rep(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31101, v_31102;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31012);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_31012;
// end of prologue
    v_31101 = stack[-5];
    fn = elt(env, 1); // get_group_in
    v_31101 = (*qfn1(fn))(fn, v_31101);
    env = stack[-7];
    stack[-6] = v_31101;
    v_31101 = stack[-6];
    fn = elt(env, 2); // get!*elements
    v_31101 = (*qfn1(fn))(fn, v_31101);
    env = stack[-7];
    stack[-4] = v_31101;
    v_31101 = stack[-4];
    if (v_31101 == nil) goto v_31031;
    else goto v_31032;
v_31031:
    v_31101 = nil;
    goto v_31025;
v_31032:
    v_31101 = stack[-4];
    v_31101 = qcar(v_31101);
    goto v_31044;
v_31040:
    stack[0] = v_31101;
    goto v_31041;
v_31042:
    goto v_31052;
v_31048:
    v_31102 = v_31101;
    goto v_31049;
v_31050:
    v_31101 = stack[-5];
    goto v_31051;
v_31052:
    goto v_31048;
v_31049:
    goto v_31050;
v_31051:
    fn = elt(env, 3); // get_rep_matrix_in
    v_31101 = (*qfn2(fn))(fn, v_31102, v_31101);
    env = stack[-7];
    fn = elt(env, 4); // mk!+resimp!+mat
    v_31101 = (*qfn1(fn))(fn, v_31101);
    env = stack[-7];
    goto v_31043;
v_31044:
    goto v_31040;
v_31041:
    goto v_31042;
v_31043:
    v_31101 = list2(stack[0], v_31101);
    env = stack[-7];
    v_31101 = ncons(v_31101);
    env = stack[-7];
    stack[-2] = v_31101;
    stack[-3] = v_31101;
v_31026:
    v_31101 = stack[-4];
    v_31101 = qcdr(v_31101);
    stack[-4] = v_31101;
    v_31101 = stack[-4];
    if (v_31101 == nil) goto v_31059;
    else goto v_31060;
v_31059:
    v_31101 = stack[-3];
    goto v_31025;
v_31060:
    goto v_31068;
v_31064:
    stack[-1] = stack[-2];
    goto v_31065;
v_31066:
    v_31101 = stack[-4];
    v_31101 = qcar(v_31101);
    goto v_31079;
v_31075:
    stack[0] = v_31101;
    goto v_31076;
v_31077:
    goto v_31087;
v_31083:
    v_31102 = v_31101;
    goto v_31084;
v_31085:
    v_31101 = stack[-5];
    goto v_31086;
v_31087:
    goto v_31083;
v_31084:
    goto v_31085;
v_31086:
    fn = elt(env, 3); // get_rep_matrix_in
    v_31101 = (*qfn2(fn))(fn, v_31102, v_31101);
    env = stack[-7];
    fn = elt(env, 4); // mk!+resimp!+mat
    v_31101 = (*qfn1(fn))(fn, v_31101);
    env = stack[-7];
    goto v_31078;
v_31079:
    goto v_31075;
v_31076:
    goto v_31077;
v_31078:
    v_31101 = list2(stack[0], v_31101);
    env = stack[-7];
    v_31101 = ncons(v_31101);
    env = stack[-7];
    goto v_31067;
v_31068:
    goto v_31064;
v_31065:
    goto v_31066;
v_31067:
    v_31101 = Lrplacd(nil, stack[-1], v_31101);
    env = stack[-7];
    v_31101 = stack[-2];
    v_31101 = qcdr(v_31101);
    stack[-2] = v_31101;
    goto v_31026;
v_31025:
    stack[0] = v_31101;
    goto v_31097;
v_31093:
    v_31101 = stack[-6];
    v_31102 = ncons(v_31101);
    goto v_31094;
v_31095:
    v_31101 = stack[0];
    goto v_31096;
v_31097:
    goto v_31093;
v_31094:
    goto v_31095;
v_31096:
        return Lappend(nil, v_31102, v_31101);
    return onevalue(v_31101);
}



// Code for talp_try1

static LispObject CC_talp_try1(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31239, v_31240, v_31241;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31012);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_31240 = v_31012;
// end of prologue
    v_31239 = v_31240;
    if (!consp(v_31239)) goto v_31020;
    else goto v_31021;
v_31020:
    v_31239 = v_31240;
    goto v_31017;
v_31021:
    v_31239 = v_31240;
    fn = elt(env, 5); // talp_rnf
    v_31239 = (*qfn1(fn))(fn, v_31239);
    env = stack[-5];
    stack[0] = v_31239;
    goto v_31042;
v_31038:
    v_31240 = stack[0];
    goto v_31039;
v_31040:
    v_31239 = elt(env, 1); // true
    goto v_31041;
v_31042:
    goto v_31038;
v_31039:
    goto v_31040;
v_31041:
    if (v_31240 == v_31239) goto v_31036;
    else goto v_31037;
v_31036:
    v_31239 = lisp_true;
    goto v_31035;
v_31037:
    goto v_31052;
v_31048:
    v_31240 = stack[0];
    goto v_31049;
v_31050:
    v_31239 = elt(env, 2); // false
    goto v_31051;
v_31052:
    goto v_31048;
v_31049:
    goto v_31050;
v_31051:
    v_31239 = (v_31240 == v_31239 ? lisp_true : nil);
    goto v_31035;
    v_31239 = nil;
v_31035:
    if (v_31239 == nil) goto v_31033;
    v_31239 = lisp_true;
    goto v_31031;
v_31033:
    v_31239 = stack[0];
    fn = elt(env, 6); // talp_atfp
    v_31239 = (*qfn1(fn))(fn, v_31239);
    env = stack[-5];
    goto v_31031;
    v_31239 = nil;
v_31031:
    if (v_31239 == nil) goto v_31029;
    v_31239 = stack[0];
    goto v_31017;
v_31029:
    v_31239 = stack[0];
    fn = elt(env, 7); // talp_op
    v_31239 = (*qfn1(fn))(fn, v_31239);
    env = stack[-5];
    v_31241 = v_31239;
    goto v_31072;
v_31068:
    v_31240 = v_31241;
    goto v_31069;
v_31070:
    v_31239 = elt(env, 3); // or
    goto v_31071;
v_31072:
    goto v_31068;
v_31069:
    goto v_31070;
v_31071:
    if (v_31240 == v_31239) goto v_31066;
    else goto v_31067;
v_31066:
    goto v_31082;
v_31076:
    goto v_31090;
v_31086:
    stack[-4] = elt(env, 4); // and
    goto v_31087;
v_31088:
    v_31239 = stack[0];
    fn = elt(env, 8); // talp_argl
    v_31239 = (*qfn1(fn))(fn, v_31239);
    env = stack[-5];
    stack[-3] = v_31239;
    v_31239 = stack[-3];
    if (v_31239 == nil) goto v_31102;
    else goto v_31103;
v_31102:
    v_31239 = nil;
    goto v_31096;
v_31103:
    v_31239 = stack[-3];
    v_31239 = qcar(v_31239);
    fn = elt(env, 9); // cl_nnfnot
    v_31239 = (*qfn1(fn))(fn, v_31239);
    env = stack[-5];
    v_31239 = CC_talp_try1(elt(env, 0), v_31239);
    env = stack[-5];
    v_31239 = ncons(v_31239);
    env = stack[-5];
    stack[-1] = v_31239;
    stack[-2] = v_31239;
v_31097:
    v_31239 = stack[-3];
    v_31239 = qcdr(v_31239);
    stack[-3] = v_31239;
    v_31239 = stack[-3];
    if (v_31239 == nil) goto v_31117;
    else goto v_31118;
v_31117:
    v_31239 = stack[-2];
    goto v_31096;
v_31118:
    goto v_31126;
v_31122:
    stack[0] = stack[-1];
    goto v_31123;
v_31124:
    v_31239 = stack[-3];
    v_31239 = qcar(v_31239);
    fn = elt(env, 9); // cl_nnfnot
    v_31239 = (*qfn1(fn))(fn, v_31239);
    env = stack[-5];
    v_31239 = CC_talp_try1(elt(env, 0), v_31239);
    env = stack[-5];
    v_31239 = ncons(v_31239);
    env = stack[-5];
    goto v_31125;
v_31126:
    goto v_31122;
v_31123:
    goto v_31124;
v_31125:
    v_31239 = Lrplacd(nil, stack[0], v_31239);
    env = stack[-5];
    v_31239 = stack[-1];
    v_31239 = qcdr(v_31239);
    stack[-1] = v_31239;
    goto v_31097;
v_31096:
    goto v_31089;
v_31090:
    goto v_31086;
v_31087:
    goto v_31088;
v_31089:
    v_31239 = cons(stack[-4], v_31239);
    env = stack[-5];
    fn = elt(env, 10); // talp_try2
    v_31239 = (*qfn1(fn))(fn, v_31239);
    env = stack[-5];
    fn = elt(env, 9); // cl_nnfnot
    v_31241 = (*qfn1(fn))(fn, v_31239);
    env = stack[-5];
    goto v_31077;
v_31078:
    v_31240 = nil;
    goto v_31079;
v_31080:
    v_31239 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_31081;
v_31082:
    goto v_31076;
v_31077:
    goto v_31078;
v_31079:
    goto v_31080;
v_31081:
    {
        fn = elt(env, 11); // cl_simpl
        return (*qfnn(fn))(fn, 3, v_31241, v_31240, v_31239);
    }
v_31067:
    goto v_31145;
v_31141:
    v_31240 = v_31241;
    goto v_31142;
v_31143:
    v_31239 = elt(env, 4); // and
    goto v_31144;
v_31145:
    goto v_31141;
v_31142:
    goto v_31143;
v_31144:
    if (v_31240 == v_31239) goto v_31139;
    else goto v_31140;
v_31139:
    goto v_31155;
v_31149:
    goto v_31162;
v_31158:
    stack[-4] = v_31241;
    goto v_31159;
v_31160:
    v_31239 = stack[0];
    fn = elt(env, 8); // talp_argl
    v_31239 = (*qfn1(fn))(fn, v_31239);
    env = stack[-5];
    stack[-3] = v_31239;
    v_31239 = stack[-3];
    if (v_31239 == nil) goto v_31174;
    else goto v_31175;
v_31174:
    v_31239 = nil;
    goto v_31168;
v_31175:
    v_31239 = stack[-3];
    v_31239 = qcar(v_31239);
    v_31239 = CC_talp_try1(elt(env, 0), v_31239);
    env = stack[-5];
    v_31239 = ncons(v_31239);
    env = stack[-5];
    stack[-1] = v_31239;
    stack[-2] = v_31239;
v_31169:
    v_31239 = stack[-3];
    v_31239 = qcdr(v_31239);
    stack[-3] = v_31239;
    v_31239 = stack[-3];
    if (v_31239 == nil) goto v_31188;
    else goto v_31189;
v_31188:
    v_31239 = stack[-2];
    goto v_31168;
v_31189:
    goto v_31197;
v_31193:
    stack[0] = stack[-1];
    goto v_31194;
v_31195:
    v_31239 = stack[-3];
    v_31239 = qcar(v_31239);
    v_31239 = CC_talp_try1(elt(env, 0), v_31239);
    env = stack[-5];
    v_31239 = ncons(v_31239);
    env = stack[-5];
    goto v_31196;
v_31197:
    goto v_31193;
v_31194:
    goto v_31195;
v_31196:
    v_31239 = Lrplacd(nil, stack[0], v_31239);
    env = stack[-5];
    v_31239 = stack[-1];
    v_31239 = qcdr(v_31239);
    stack[-1] = v_31239;
    goto v_31169;
v_31168:
    goto v_31161;
v_31162:
    goto v_31158;
v_31159:
    goto v_31160;
v_31161:
    v_31239 = cons(stack[-4], v_31239);
    env = stack[-5];
    fn = elt(env, 10); // talp_try2
    v_31241 = (*qfn1(fn))(fn, v_31239);
    env = stack[-5];
    goto v_31150;
v_31151:
    v_31240 = nil;
    goto v_31152;
v_31153:
    v_31239 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_31154;
v_31155:
    goto v_31149;
v_31150:
    goto v_31151;
v_31152:
    goto v_31153;
v_31154:
    {
        fn = elt(env, 11); // cl_simpl
        return (*qfnn(fn))(fn, 3, v_31241, v_31240, v_31239);
    }
v_31140:
    goto v_31218;
v_31212:
    goto v_31226;
v_31220:
    stack[-2] = v_31241;
    goto v_31221;
v_31222:
    v_31239 = stack[0];
    v_31239 = qcdr(v_31239);
    stack[-1] = qcar(v_31239);
    goto v_31223;
v_31224:
    v_31239 = stack[0];
    v_31239 = qcdr(v_31239);
    v_31239 = qcdr(v_31239);
    v_31239 = qcar(v_31239);
    v_31239 = CC_talp_try1(elt(env, 0), v_31239);
    env = stack[-5];
    v_31239 = ncons(v_31239);
    env = stack[-5];
    goto v_31225;
v_31226:
    goto v_31220;
v_31221:
    goto v_31222;
v_31223:
    goto v_31224;
v_31225:
    v_31241 = list2star(stack[-2], stack[-1], v_31239);
    env = stack[-5];
    goto v_31213;
v_31214:
    v_31240 = nil;
    goto v_31215;
v_31216:
    v_31239 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_31217;
v_31218:
    goto v_31212;
v_31213:
    goto v_31214;
v_31215:
    goto v_31216;
v_31217:
    {
        fn = elt(env, 11); // cl_simpl
        return (*qfnn(fn))(fn, 3, v_31241, v_31240, v_31239);
    }
    v_31239 = nil;
v_31017:
    return onevalue(v_31239);
}



// Code for expvec2a1

static LispObject CC_expvec2a1(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31089, v_31090, v_31091;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31012,v_31013);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31013;
    stack[-1] = v_31012;
// end of prologue
    stack[-2] = nil;
v_31018:
    v_31089 = stack[-1];
    if (v_31089 == nil) goto v_31021;
    else goto v_31022;
v_31021:
    v_31089 = stack[-2];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_31089);
    }
v_31022:
    goto v_31032;
v_31028:
    v_31089 = stack[-1];
    v_31090 = qcar(v_31089);
    goto v_31029;
v_31030:
    v_31089 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31031;
v_31032:
    goto v_31028;
v_31029:
    goto v_31030;
v_31031:
    if (v_31090 == v_31089) goto v_31026;
    else goto v_31027;
v_31026:
    v_31089 = stack[-1];
    v_31089 = qcdr(v_31089);
    stack[-1] = v_31089;
    v_31089 = stack[0];
    v_31089 = qcdr(v_31089);
    stack[0] = v_31089;
    goto v_31018;
v_31027:
    goto v_31046;
v_31042:
    v_31089 = stack[-1];
    v_31090 = qcar(v_31089);
    goto v_31043;
v_31044:
    v_31089 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31045;
v_31046:
    goto v_31042;
v_31043:
    goto v_31044;
v_31045:
    if (v_31090 == v_31089) goto v_31040;
    else goto v_31041;
v_31040:
    goto v_31055;
v_31051:
    v_31089 = stack[0];
    v_31090 = qcar(v_31089);
    goto v_31052;
v_31053:
    v_31089 = stack[-2];
    goto v_31054;
v_31055:
    goto v_31051;
v_31052:
    goto v_31053;
v_31054:
    v_31089 = cons(v_31090, v_31089);
    env = stack[-3];
    stack[-2] = v_31089;
    v_31089 = stack[-1];
    v_31089 = qcdr(v_31089);
    stack[-1] = v_31089;
    v_31089 = stack[0];
    v_31089 = qcdr(v_31089);
    stack[0] = v_31089;
    goto v_31018;
v_31041:
    goto v_31070;
v_31066:
    goto v_31078;
v_31072:
    v_31091 = elt(env, 1); // expt
    goto v_31073;
v_31074:
    v_31089 = stack[0];
    v_31090 = qcar(v_31089);
    goto v_31075;
v_31076:
    v_31089 = stack[-1];
    v_31089 = qcar(v_31089);
    goto v_31077;
v_31078:
    goto v_31072;
v_31073:
    goto v_31074;
v_31075:
    goto v_31076;
v_31077:
    v_31090 = list3(v_31091, v_31090, v_31089);
    env = stack[-3];
    goto v_31067;
v_31068:
    v_31089 = stack[-2];
    goto v_31069;
v_31070:
    goto v_31066;
v_31067:
    goto v_31068;
v_31069:
    v_31089 = cons(v_31090, v_31089);
    env = stack[-3];
    stack[-2] = v_31089;
    v_31089 = stack[-1];
    v_31089 = qcdr(v_31089);
    stack[-1] = v_31089;
    v_31089 = stack[0];
    v_31089 = qcdr(v_31089);
    stack[0] = v_31089;
    goto v_31018;
    v_31089 = nil;
    return onevalue(v_31089);
}



// Code for deflate1

static LispObject CC_deflate1(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31099, v_31100, v_31101;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31012,v_31013);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_31013;
    v_31099 = v_31012;
// end of prologue
    stack[-5] = nil;
    fn = elt(env, 1); // ncoeffs
    v_31100 = (*qfn1(fn))(fn, v_31099);
    env = stack[-6];
    v_31099 = v_31100;
    v_31100 = qcar(v_31100);
    stack[-3] = v_31100;
    v_31099 = qcdr(v_31099);
    v_31100 = v_31099;
    v_31100 = qcar(v_31100);
    stack[-2] = v_31100;
    v_31099 = qcdr(v_31099);
    stack[-1] = v_31099;
v_31030:
    v_31099 = stack[-1];
    if (v_31099 == nil) goto v_31035;
    else goto v_31036;
v_31035:
    goto v_31029;
v_31036:
    v_31099 = stack[-1];
    v_31099 = qcar(v_31099);
    stack[0] = v_31099;
    v_31099 = stack[-3];
    v_31099 = sub1(v_31099);
    env = stack[-6];
    stack[-3] = v_31099;
    goto v_31052;
v_31048:
    v_31099 = stack[-2];
    v_31099 = qcdr(v_31099);
    v_31100 = qcar(v_31099);
    goto v_31049;
v_31050:
    v_31099 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31051;
v_31052:
    goto v_31048;
v_31049:
    goto v_31050;
v_31051:
    if (v_31100 == v_31099) goto v_31047;
    goto v_31064;
v_31058:
    v_31101 = stack[-3];
    goto v_31059;
v_31060:
    v_31100 = stack[-2];
    goto v_31061;
v_31062:
    v_31099 = stack[-5];
    goto v_31063;
v_31064:
    goto v_31058;
v_31059:
    goto v_31060;
v_31061:
    goto v_31062;
v_31063:
    v_31099 = acons(v_31101, v_31100, v_31099);
    env = stack[-6];
    stack[-5] = v_31099;
    goto v_31045;
v_31047:
v_31045:
    goto v_31073;
v_31069:
    v_31100 = stack[-4];
    goto v_31070;
v_31071:
    v_31099 = stack[-2];
    goto v_31072;
v_31073:
    goto v_31069;
v_31070:
    goto v_31071;
v_31072:
    fn = elt(env, 2); // times!:
    v_31099 = (*qfn2(fn))(fn, v_31100, v_31099);
    env = stack[-6];
    stack[-2] = v_31099;
    v_31099 = stack[0];
    if (v_31099 == nil) goto v_31079;
    goto v_31086;
v_31082:
    v_31100 = stack[0];
    goto v_31083;
v_31084:
    v_31099 = stack[-2];
    goto v_31085;
v_31086:
    goto v_31082;
v_31083:
    goto v_31084;
v_31085:
    fn = elt(env, 3); // plus!:
    v_31099 = (*qfn2(fn))(fn, v_31100, v_31099);
    env = stack[-6];
    stack[-2] = v_31099;
    goto v_31077;
v_31079:
v_31077:
    v_31099 = stack[-1];
    v_31099 = qcdr(v_31099);
    stack[-1] = v_31099;
    goto v_31030;
v_31029:
    goto v_31096;
v_31092:
    v_31100 = stack[-2];
    goto v_31093;
v_31094:
    v_31099 = stack[-5];
    goto v_31095;
v_31096:
    goto v_31092;
v_31093:
    goto v_31094;
v_31095:
    return cons(v_31100, v_31099);
    return onevalue(v_31099);
}



// Code for rdzchk

static LispObject CC_rdzchk(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31211, v_31212;
    LispObject fn;
    LispObject v_31014, v_31013, v_31012;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "rdzchk");
    va_start(aa, nargs);
    v_31012 = va_arg(aa, LispObject);
    v_31013 = va_arg(aa, LispObject);
    v_31014 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31014,v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31012,v_31013,v_31014);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31014;
    stack[-1] = v_31013;
    stack[-2] = v_31012;
// end of prologue
    v_31211 = stack[-2];
    if (!consp(v_31211)) goto v_31018;
    else goto v_31019;
v_31018:
    goto v_31033;
v_31029:
    v_31212 = stack[-2];
    goto v_31030;
v_31031:
    v_31211 = elt(env, 1); // 0.0
    goto v_31032;
v_31033:
    goto v_31029;
v_31030:
    goto v_31031;
v_31032:
    if (equal(v_31212, v_31211)) goto v_31027;
    else goto v_31028;
v_31027:
    v_31211 = lisp_true;
    goto v_31026;
v_31028:
    goto v_31051;
v_31047:
    v_31212 = stack[-1];
    goto v_31048;
v_31049:
    v_31211 = elt(env, 1); // 0.0
    goto v_31050;
v_31051:
    goto v_31047;
v_31048:
    goto v_31049;
v_31050:
    v_31211 = (LispObject)greaterp2(v_31212, v_31211);
    v_31211 = v_31211 ? lisp_true : nil;
    env = stack[-3];
    if (v_31211 == nil) goto v_31044;
    else goto v_31045;
v_31044:
    v_31211 = nil;
    goto v_31043;
v_31045:
    goto v_31062;
v_31058:
    v_31212 = stack[0];
    goto v_31059;
v_31060:
    v_31211 = elt(env, 1); // 0.0
    goto v_31061;
v_31062:
    goto v_31058;
v_31059:
    goto v_31060;
v_31061:
    v_31211 = (LispObject)greaterp2(v_31212, v_31211);
    v_31211 = v_31211 ? lisp_true : nil;
    env = stack[-3];
    goto v_31043;
    v_31211 = nil;
v_31043:
    if (v_31211 == nil) goto v_31041;
    else goto v_31040;
v_31041:
    goto v_31074;
v_31070:
    v_31212 = stack[-1];
    goto v_31071;
v_31072:
    v_31211 = elt(env, 1); // 0.0
    goto v_31073;
v_31074:
    goto v_31070;
v_31071:
    goto v_31072;
v_31073:
    v_31211 = (LispObject)lessp2(v_31212, v_31211);
    v_31211 = v_31211 ? lisp_true : nil;
    env = stack[-3];
    if (v_31211 == nil) goto v_31067;
    else goto v_31068;
v_31067:
    v_31211 = nil;
    goto v_31066;
v_31068:
    goto v_31085;
v_31081:
    v_31212 = stack[0];
    goto v_31082;
v_31083:
    v_31211 = elt(env, 1); // 0.0
    goto v_31084;
v_31085:
    goto v_31081;
v_31082:
    goto v_31083;
v_31084:
    v_31211 = (LispObject)lessp2(v_31212, v_31211);
    v_31211 = v_31211 ? lisp_true : nil;
    env = stack[-3];
    goto v_31066;
    v_31211 = nil;
v_31066:
v_31040:
    goto v_31026;
    v_31211 = nil;
v_31026:
    if (v_31211 == nil) goto v_31024;
    v_31211 = stack[-2];
    goto v_31022;
v_31024:
    goto v_31096;
v_31092:
    v_31211 = stack[-2];
    stack[0] = Labsval(nil, v_31211);
    env = stack[-3];
    goto v_31093;
v_31094:
    goto v_31104;
v_31100:
    v_31211 = stack[-1];
    v_31212 = Labsval(nil, v_31211);
    env = stack[-3];
    goto v_31101;
v_31102:
    v_31211 = qvalue(elt(env, 2)); // !!fleps1
    goto v_31103;
v_31104:
    goto v_31100;
v_31101:
    goto v_31102;
v_31103:
    v_31211 = times2(v_31212, v_31211);
    env = stack[-3];
    goto v_31095;
v_31096:
    goto v_31092;
v_31093:
    goto v_31094;
v_31095:
    v_31211 = (LispObject)lessp2(stack[0], v_31211);
    v_31211 = v_31211 ? lisp_true : nil;
    env = stack[-3];
    if (v_31211 == nil) goto v_31090;
    v_31211 = elt(env, 1); // 0.0
    goto v_31022;
v_31090:
    v_31211 = stack[-2];
    goto v_31022;
    v_31211 = nil;
v_31022:
    goto v_31017;
v_31019:
    goto v_31122;
v_31118:
    v_31211 = stack[-2];
    v_31211 = qcdr(v_31211);
    v_31212 = qcar(v_31211);
    goto v_31119;
v_31120:
    v_31211 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31121;
v_31122:
    goto v_31118;
v_31119:
    goto v_31120;
v_31121:
    if (v_31212 == v_31211) goto v_31116;
    else goto v_31117;
v_31116:
    v_31211 = lisp_true;
    goto v_31115;
v_31117:
    goto v_31142;
v_31138:
    v_31211 = stack[-1];
    v_31211 = qcdr(v_31211);
    v_31212 = qcar(v_31211);
    goto v_31139;
v_31140:
    v_31211 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31141;
v_31142:
    goto v_31138;
v_31139:
    goto v_31140;
v_31141:
    v_31211 = (LispObject)greaterp2(v_31212, v_31211);
    v_31211 = v_31211 ? lisp_true : nil;
    env = stack[-3];
    if (v_31211 == nil) goto v_31135;
    else goto v_31136;
v_31135:
    v_31211 = nil;
    goto v_31134;
v_31136:
    goto v_31155;
v_31151:
    v_31211 = stack[0];
    v_31211 = qcdr(v_31211);
    v_31212 = qcar(v_31211);
    goto v_31152;
v_31153:
    v_31211 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31154;
v_31155:
    goto v_31151;
v_31152:
    goto v_31153;
v_31154:
    v_31211 = (LispObject)greaterp2(v_31212, v_31211);
    v_31211 = v_31211 ? lisp_true : nil;
    env = stack[-3];
    goto v_31134;
    v_31211 = nil;
v_31134:
    if (v_31211 == nil) goto v_31132;
    else goto v_31131;
v_31132:
    goto v_31169;
v_31165:
    v_31211 = stack[-1];
    v_31211 = qcdr(v_31211);
    v_31212 = qcar(v_31211);
    goto v_31166;
v_31167:
    v_31211 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31168;
v_31169:
    goto v_31165;
v_31166:
    goto v_31167;
v_31168:
    v_31211 = (LispObject)lessp2(v_31212, v_31211);
    v_31211 = v_31211 ? lisp_true : nil;
    env = stack[-3];
    if (v_31211 == nil) goto v_31162;
    else goto v_31163;
v_31162:
    v_31211 = nil;
    goto v_31161;
v_31163:
    goto v_31182;
v_31178:
    v_31211 = stack[0];
    v_31211 = qcdr(v_31211);
    v_31212 = qcar(v_31211);
    goto v_31179;
v_31180:
    v_31211 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31181;
v_31182:
    goto v_31178;
v_31179:
    goto v_31180;
v_31181:
    v_31211 = (LispObject)lessp2(v_31212, v_31211);
    v_31211 = v_31211 ? lisp_true : nil;
    env = stack[-3];
    goto v_31161;
    v_31211 = nil;
v_31161:
v_31131:
    goto v_31115;
    v_31211 = nil;
v_31115:
    if (v_31211 == nil) goto v_31113;
    v_31211 = stack[-2];
    goto v_31017;
v_31113:
    goto v_31195;
v_31191:
    v_31211 = stack[-2];
    fn = elt(env, 5); // abs!:
    stack[0] = (*qfn1(fn))(fn, v_31211);
    env = stack[-3];
    goto v_31192;
v_31193:
    goto v_31203;
v_31199:
    v_31211 = stack[-1];
    fn = elt(env, 5); // abs!:
    v_31212 = (*qfn1(fn))(fn, v_31211);
    env = stack[-3];
    goto v_31200;
v_31201:
    v_31211 = qvalue(elt(env, 3)); // rd!-tolerance!*
    goto v_31202;
v_31203:
    goto v_31199;
v_31200:
    goto v_31201;
v_31202:
    fn = elt(env, 6); // times!:
    v_31211 = (*qfn2(fn))(fn, v_31212, v_31211);
    env = stack[-3];
    goto v_31194;
v_31195:
    goto v_31191;
v_31192:
    goto v_31193;
v_31194:
    fn = elt(env, 7); // lessp!:
    v_31211 = (*qfn2(fn))(fn, stack[0], v_31211);
    env = stack[-3];
    if (v_31211 == nil) goto v_31189;
    v_31211 = qvalue(elt(env, 4)); // bfz!*
    goto v_31017;
v_31189:
    v_31211 = stack[-2];
    goto v_31017;
    v_31211 = nil;
v_31017:
    return onevalue(v_31211);
}



// Code for requote1

static LispObject CC_requote1(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31112, v_31113;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31012);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_31012;
// end of prologue
    stack[-2] = nil;
    stack[0] = nil;
v_31018:
    v_31112 = stack[-1];
    if (v_31112 == nil) goto v_31021;
    else goto v_31022;
v_31021:
    v_31112 = stack[-2];
        return Lnreverse(nil, v_31112);
v_31022:
    v_31112 = stack[-1];
    v_31112 = qcar(v_31112);
    if (is_number(v_31112)) goto v_31026;
    goto v_31036;
v_31032:
    v_31112 = stack[-1];
    v_31113 = qcar(v_31112);
    goto v_31033;
v_31034:
    v_31112 = elt(env, 1); // (nil t)
    goto v_31035;
v_31036:
    goto v_31032;
v_31033:
    goto v_31034;
v_31035:
    v_31112 = Lmemq(nil, v_31113, v_31112);
    if (v_31112 == nil) goto v_31031;
    else goto v_31026;
v_31031:
    goto v_31027;
v_31026:
    goto v_31046;
v_31042:
    v_31112 = stack[-1];
    v_31113 = qcar(v_31112);
    goto v_31043;
v_31044:
    v_31112 = stack[-2];
    goto v_31045;
v_31046:
    goto v_31042;
v_31043:
    goto v_31044;
v_31045:
    v_31112 = cons(v_31113, v_31112);
    env = stack[-3];
    stack[-2] = v_31112;
    goto v_31020;
v_31027:
    v_31112 = stack[-1];
    v_31112 = qcar(v_31112);
    if (!consp(v_31112)) goto v_31050;
    else goto v_31051;
v_31050:
    v_31112 = nil;
    goto v_31017;
v_31051:
    goto v_31061;
v_31057:
    v_31112 = stack[-1];
    v_31112 = qcar(v_31112);
    v_31113 = qcar(v_31112);
    goto v_31058;
v_31059:
    v_31112 = elt(env, 2); // quote
    goto v_31060;
v_31061:
    goto v_31057;
v_31058:
    goto v_31059;
v_31060:
    if (v_31113 == v_31112) goto v_31055;
    else goto v_31056;
v_31055:
    goto v_31071;
v_31067:
    v_31112 = stack[-1];
    v_31112 = qcar(v_31112);
    v_31112 = qcdr(v_31112);
    v_31113 = qcar(v_31112);
    goto v_31068;
v_31069:
    v_31112 = stack[-2];
    goto v_31070;
v_31071:
    goto v_31067;
v_31068:
    goto v_31069;
v_31070:
    v_31112 = cons(v_31113, v_31112);
    env = stack[-3];
    stack[-2] = v_31112;
    goto v_31020;
v_31056:
    goto v_31087;
v_31083:
    v_31112 = stack[-1];
    v_31112 = qcar(v_31112);
    v_31113 = qcar(v_31112);
    goto v_31084;
v_31085:
    v_31112 = elt(env, 3); // list
    goto v_31086;
v_31087:
    goto v_31083;
v_31084:
    goto v_31085;
v_31086:
    if (v_31113 == v_31112) goto v_31081;
    else goto v_31082;
v_31081:
    v_31112 = stack[-1];
    v_31112 = qcar(v_31112);
    v_31112 = qcdr(v_31112);
    v_31112 = CC_requote1(elt(env, 0), v_31112);
    env = stack[-3];
    stack[0] = v_31112;
    goto v_31080;
v_31082:
    v_31112 = nil;
    goto v_31080;
    v_31112 = nil;
v_31080:
    if (v_31112 == nil) goto v_31078;
    goto v_31104;
v_31100:
    v_31113 = stack[0];
    goto v_31101;
v_31102:
    v_31112 = stack[-2];
    goto v_31103;
v_31104:
    goto v_31100;
v_31101:
    goto v_31102;
v_31103:
    v_31112 = cons(v_31113, v_31112);
    env = stack[-3];
    stack[-2] = v_31112;
    goto v_31020;
v_31078:
    v_31112 = nil;
    goto v_31017;
v_31020:
    v_31112 = stack[-1];
    v_31112 = qcdr(v_31112);
    stack[-1] = v_31112;
    goto v_31018;
v_31017:
    return onevalue(v_31112);
}



// Code for denlist

static LispObject CC_denlist(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31075, v_31076;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31012,v_31013);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31013;
    stack[-1] = v_31012;
// end of prologue
    stack[-2] = nil;
v_31018:
    v_31075 = stack[-1];
    if (v_31075 == nil) goto v_31021;
    else goto v_31022;
v_31021:
    v_31075 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_31075);
    }
v_31022:
    goto v_31032;
v_31028:
    v_31075 = stack[-1];
    v_31075 = qcar(v_31075);
    v_31076 = Llength(nil, v_31075);
    env = stack[-3];
    goto v_31029;
v_31030:
    v_31075 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31031;
v_31032:
    goto v_31028;
v_31029:
    goto v_31030;
v_31031:
    if (v_31076 == v_31075) goto v_31026;
    else goto v_31027;
v_31026:
    goto v_31042;
v_31038:
    goto v_31048;
v_31044:
    v_31075 = stack[-1];
    v_31076 = qcar(v_31075);
    goto v_31045;
v_31046:
    v_31075 = stack[0];
    goto v_31047;
v_31048:
    goto v_31044;
v_31045:
    goto v_31046;
v_31047:
    fn = elt(env, 2); // ev!-denom2
    v_31076 = (*qfn2(fn))(fn, v_31076, v_31075);
    env = stack[-3];
    goto v_31039;
v_31040:
    v_31075 = stack[-2];
    goto v_31041;
v_31042:
    goto v_31038;
v_31039:
    goto v_31040;
v_31041:
    v_31075 = cons(v_31076, v_31075);
    env = stack[-3];
    stack[-2] = v_31075;
    v_31075 = stack[-1];
    v_31075 = qcdr(v_31075);
    stack[-1] = v_31075;
    goto v_31018;
v_31027:
    goto v_31062;
v_31058:
    goto v_31068;
v_31064:
    v_31075 = stack[-1];
    v_31076 = qcar(v_31075);
    goto v_31065;
v_31066:
    v_31075 = stack[0];
    goto v_31067;
v_31068:
    goto v_31064;
v_31065:
    goto v_31066;
v_31067:
    fn = elt(env, 3); // ev!-denom3
    v_31076 = (*qfn2(fn))(fn, v_31076, v_31075);
    env = stack[-3];
    goto v_31059;
v_31060:
    v_31075 = stack[-2];
    goto v_31061;
v_31062:
    goto v_31058;
v_31059:
    goto v_31060;
v_31061:
    v_31075 = cons(v_31076, v_31075);
    env = stack[-3];
    stack[-2] = v_31075;
    v_31075 = stack[-1];
    v_31075 = qcdr(v_31075);
    stack[-1] = v_31075;
    goto v_31018;
    v_31075 = nil;
    return onevalue(v_31075);
}



// Code for baglistp

static LispObject CC_baglistp(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31046, v_31047, v_31048;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31048 = v_31012;
// end of prologue
    v_31046 = v_31048;
    if (!consp(v_31046)) goto v_31017;
    goto v_31027;
v_31023:
    v_31046 = v_31048;
    v_31047 = qcar(v_31046);
    goto v_31024;
v_31025:
    v_31046 = elt(env, 1); // list
    goto v_31026;
v_31027:
    goto v_31023;
v_31024:
    goto v_31025;
v_31026:
    if (v_31047 == v_31046) goto v_31021;
    else goto v_31022;
v_31021:
    v_31046 = lisp_true;
    goto v_31020;
v_31022:
    goto v_31039;
v_31035:
    v_31046 = v_31048;
    v_31046 = qcar(v_31046);
    goto v_31036;
v_31037:
    v_31047 = elt(env, 2); // bag
    goto v_31038;
v_31039:
    goto v_31035;
v_31036:
    goto v_31037;
v_31038:
        return Lflagp(nil, v_31046, v_31047);
    v_31046 = nil;
v_31020:
    goto v_31015;
v_31017:
    v_31046 = nil;
    goto v_31015;
    v_31046 = nil;
v_31015:
    return onevalue(v_31046);
}



// Code for coeff_totder

static LispObject CC_coeff_totder(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31110, v_31111, v_31112, v_31113;
    LispObject fn;
    LispObject v_31014, v_31013, v_31012;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "coeff_totder");
    va_start(aa, nargs);
    v_31012 = va_arg(aa, LispObject);
    v_31013 = va_arg(aa, LispObject);
    v_31014 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31014,v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31012,v_31013,v_31014);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31014;
    v_31110 = v_31013;
    stack[-1] = v_31012;
// end of prologue
    goto v_31026;
v_31022:
    v_31111 = stack[-1];
    goto v_31023;
v_31024:
    goto v_31025;
v_31026:
    goto v_31022;
v_31023:
    goto v_31024;
v_31025:
    fn = elt(env, 5); // idtomind
    v_31110 = (*qfn2(fn))(fn, v_31111, v_31110);
    env = stack[-2];
    v_31111 = v_31110;
    v_31111 = qcar(v_31111);
    v_31113 = v_31111;
    goto v_31035;
v_31031:
    v_31110 = qcdr(v_31110);
    v_31111 = qcar(v_31110);
    goto v_31032;
v_31033:
    v_31110 = qvalue(elt(env, 1)); // all_mind_table!*
    goto v_31034;
v_31035:
    goto v_31031;
v_31032:
    goto v_31033;
v_31034:
    v_31110 = Lassoc(nil, v_31111, v_31110);
    v_31110 = qcdr(v_31110);
    v_31110 = qcar(v_31110);
    v_31112 = v_31110;
    v_31110 = v_31112;
    if (v_31110 == nil) goto v_31046;
    goto v_31056;
v_31052:
    v_31111 = stack[-1];
    goto v_31053;
v_31054:
    v_31110 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31055;
v_31056:
    goto v_31052;
v_31053:
    goto v_31054;
v_31055:
    if (v_31111 == v_31110) goto v_31050;
    else goto v_31051;
v_31050:
    goto v_31064;
v_31060:
    goto v_31070;
v_31066:
    stack[-1] = v_31113;
    goto v_31067;
v_31068:
    goto v_31077;
v_31073:
    v_31111 = v_31112;
    goto v_31074;
v_31075:
    v_31110 = stack[0];
    goto v_31076;
v_31077:
    goto v_31073;
v_31074:
    goto v_31075;
v_31076:
    fn = elt(env, 6); // nth
    v_31110 = (*qfn2(fn))(fn, v_31111, v_31110);
    env = stack[-2];
    goto v_31069;
v_31070:
    goto v_31066;
v_31067:
    goto v_31068;
v_31069:
    v_31111 = list2(stack[-1], v_31110);
    env = stack[-2];
    goto v_31061;
v_31062:
    v_31110 = qvalue(elt(env, 2)); // i2m_jetspace!*
    goto v_31063;
v_31064:
    goto v_31060;
v_31061:
    goto v_31062;
v_31063:
    fn = elt(env, 7); // cde_lassoc2
    v_31110 = (*qfn2(fn))(fn, v_31111, v_31110);
    v_31110 = qcar(v_31110);
    goto v_31020;
v_31051:
    goto v_31089;
v_31085:
    goto v_31095;
v_31091:
    stack[-1] = v_31113;
    goto v_31092;
v_31093:
    goto v_31102;
v_31098:
    v_31111 = v_31112;
    goto v_31099;
v_31100:
    v_31110 = stack[0];
    goto v_31101;
v_31102:
    goto v_31098;
v_31099:
    goto v_31100;
v_31101:
    fn = elt(env, 6); // nth
    v_31110 = (*qfn2(fn))(fn, v_31111, v_31110);
    env = stack[-2];
    goto v_31094;
v_31095:
    goto v_31091;
v_31092:
    goto v_31093;
v_31094:
    v_31111 = list2(stack[-1], v_31110);
    env = stack[-2];
    goto v_31086;
v_31087:
    v_31110 = qvalue(elt(env, 3)); // i2m_jetspace_odd!*
    goto v_31088;
v_31089:
    goto v_31085;
v_31086:
    goto v_31087;
v_31088:
    fn = elt(env, 7); // cde_lassoc2
    v_31110 = (*qfn2(fn))(fn, v_31111, v_31110);
    v_31110 = qcar(v_31110);
    goto v_31020;
    goto v_31044;
v_31046:
    v_31110 = elt(env, 4); // letop
    goto v_31020;
v_31044:
    v_31110 = nil;
v_31020:
    return onevalue(v_31110);
}



// Code for qqe_dfs

static LispObject CC_qqe_dfs(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31093, v_31094;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31012,v_31013);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_31013;
    v_31094 = v_31012;
// end of prologue
    v_31093 = lisp_true;
    stack[0] = v_31093;
    v_31093 = v_31094;
    if (!consp(v_31093)) goto v_31022;
    else goto v_31023;
v_31022:
    goto v_31033;
v_31029:
    goto v_31030;
v_31031:
    v_31093 = stack[-1];
    goto v_31032;
v_31033:
    goto v_31029;
v_31030:
    goto v_31031;
v_31032:
    if (v_31094 == v_31093) goto v_31027;
    else goto v_31028;
v_31027:
    v_31093 = lisp_true;
    goto v_31018;
v_31028:
    v_31093 = nil;
    goto v_31018;
    goto v_31021;
v_31023:
v_31021:
    v_31093 = v_31094;
    stack[-2] = v_31093;
v_31044:
    v_31093 = stack[-2];
    if (v_31093 == nil) goto v_31047;
    v_31093 = stack[0];
    if (v_31093 == nil) goto v_31047;
    goto v_31048;
v_31047:
    goto v_31043;
v_31048:
    goto v_31062;
v_31058:
    v_31093 = stack[-2];
    v_31094 = qcar(v_31093);
    goto v_31059;
v_31060:
    v_31093 = stack[-1];
    goto v_31061;
v_31062:
    goto v_31058;
v_31059:
    goto v_31060;
v_31061:
    if (v_31094 == v_31093) goto v_31056;
    else goto v_31057;
v_31056:
    v_31093 = nil;
    stack[0] = v_31093;
    goto v_31055;
v_31057:
v_31055:
    goto v_31076;
v_31072:
    v_31093 = stack[-2];
    v_31094 = qcar(v_31093);
    goto v_31073;
v_31074:
    v_31093 = stack[-1];
    goto v_31075;
v_31076:
    goto v_31072;
v_31073:
    goto v_31074;
v_31075:
    v_31093 = CC_qqe_dfs(elt(env, 0), v_31094, v_31093);
    env = stack[-3];
    if (v_31093 == nil) goto v_31070;
    v_31093 = nil;
    stack[0] = v_31093;
    goto v_31068;
v_31070:
v_31068:
    v_31093 = stack[-2];
    v_31093 = qcdr(v_31093);
    stack[-2] = v_31093;
    goto v_31044;
v_31043:
    v_31093 = stack[0];
    if (v_31093 == nil) goto v_31087;
    v_31093 = nil;
    goto v_31018;
v_31087:
    v_31093 = lisp_true;
    goto v_31018;
    v_31093 = nil;
v_31018:
    return onevalue(v_31093);
}



// Code for rl_simplb

static LispObject CC_rl_simplb(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31030, v_31031;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31012,v_31013);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31030 = v_31013;
    v_31031 = v_31012;
// end of prologue
    goto v_31020;
v_31016:
    stack[0] = qvalue(elt(env, 1)); // rl_simplb!*
    goto v_31017;
v_31018:
    goto v_31027;
v_31023:
    goto v_31024;
v_31025:
    goto v_31026;
v_31027:
    goto v_31023;
v_31024:
    goto v_31025;
v_31026:
    v_31030 = list2(v_31031, v_31030);
    env = stack[-1];
    goto v_31019;
v_31020:
    goto v_31016;
v_31017:
    goto v_31018;
v_31019:
    {
        LispObject v_31033 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_31033, v_31030);
    }
}



// Code for !*s2i

static LispObject CC_Hs2i(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31031, v_31032;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31032 = v_31012;
// end of prologue
    v_31031 = v_31032;
    v_31031 = integerp(v_31031);
    if (v_31031 == nil) goto v_31017;
    v_31031 = v_31032;
    goto v_31015;
v_31017:
    goto v_31028;
v_31024:
    goto v_31025;
v_31026:
    v_31031 = elt(env, 1); // "integer"
    goto v_31027;
v_31028:
    goto v_31024;
v_31025:
    goto v_31026;
v_31027:
    {
        fn = elt(env, 2); // typerr
        return (*qfn2(fn))(fn, v_31032, v_31031);
    }
    v_31031 = nil;
v_31015:
    return onevalue(v_31031);
}



// Code for cr!:zerop

static LispObject CC_crTzerop(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31105, v_31106;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31012);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_31012;
// end of prologue
    v_31105 = stack[0];
    v_31105 = qcdr(v_31105);
    v_31105 = qcar(v_31105);
    if (!consp(v_31105)) goto v_31020;
    else goto v_31021;
v_31020:
    v_31105 = stack[0];
    v_31105 = qcdr(v_31105);
    v_31105 = qcar(v_31105);
    goto v_31019;
v_31021:
    goto v_31035;
v_31031:
    v_31106 = elt(env, 1); // !:rd!:
    goto v_31032;
v_31033:
    v_31105 = stack[0];
    v_31105 = qcdr(v_31105);
    v_31105 = qcar(v_31105);
    goto v_31034;
v_31035:
    goto v_31031;
v_31032:
    goto v_31033;
v_31034:
    v_31105 = cons(v_31106, v_31105);
    env = stack[-1];
    goto v_31019;
    v_31105 = nil;
v_31019:
    v_31106 = v_31105;
    v_31105 = v_31106;
    if (!consp(v_31105)) goto v_31043;
    else goto v_31044;
v_31043:
    v_31105 = v_31106;
    v_31105 = (LispObject)zerop(v_31105);
    v_31105 = v_31105 ? lisp_true : nil;
    env = stack[-1];
    goto v_31042;
v_31044:
    goto v_31054;
v_31050:
    v_31105 = v_31106;
    v_31105 = qcdr(v_31105);
    v_31106 = qcar(v_31105);
    goto v_31051;
v_31052:
    v_31105 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31053;
v_31054:
    goto v_31050;
v_31051:
    goto v_31052;
v_31053:
    v_31105 = (v_31106 == v_31105 ? lisp_true : nil);
    goto v_31042;
    v_31105 = nil;
v_31042:
    if (v_31105 == nil) goto v_31016;
    else goto v_31017;
v_31016:
    v_31105 = nil;
    goto v_31015;
v_31017:
    v_31105 = stack[0];
    v_31105 = qcdr(v_31105);
    v_31105 = qcdr(v_31105);
    if (!consp(v_31105)) goto v_31065;
    else goto v_31066;
v_31065:
    v_31105 = stack[0];
    v_31105 = qcdr(v_31105);
    v_31105 = qcdr(v_31105);
    goto v_31064;
v_31066:
    goto v_31080;
v_31076:
    v_31106 = elt(env, 1); // !:rd!:
    goto v_31077;
v_31078:
    v_31105 = stack[0];
    v_31105 = qcdr(v_31105);
    v_31105 = qcdr(v_31105);
    goto v_31079;
v_31080:
    goto v_31076;
v_31077:
    goto v_31078;
v_31079:
    v_31105 = cons(v_31106, v_31105);
    goto v_31064;
    v_31105 = nil;
v_31064:
    v_31106 = v_31105;
    v_31105 = v_31106;
    if (!consp(v_31105)) goto v_31088;
    else goto v_31089;
v_31088:
    v_31105 = v_31106;
        return Lzerop(nil, v_31105);
v_31089:
    goto v_31099;
v_31095:
    v_31105 = v_31106;
    v_31105 = qcdr(v_31105);
    v_31106 = qcar(v_31105);
    goto v_31096;
v_31097:
    v_31105 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31098;
v_31099:
    goto v_31095;
v_31096:
    goto v_31097;
v_31098:
    v_31105 = (v_31106 == v_31105 ? lisp_true : nil);
    goto v_31087;
    v_31105 = nil;
v_31087:
    goto v_31015;
    v_31105 = nil;
v_31015:
    return onevalue(v_31105);
}



// Code for splitrec

static LispObject CC_splitrec(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31196, v_31197, v_31198, v_31199;
    LispObject fn;
    LispObject v_31015, v_31014, v_31013, v_31012;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "splitrec");
    va_start(aa, nargs);
    v_31012 = va_arg(aa, LispObject);
    v_31013 = va_arg(aa, LispObject);
    v_31014 = va_arg(aa, LispObject);
    v_31015 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_31015,v_31014,v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_31012,v_31013,v_31014,v_31015);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-2] = v_31015;
    stack[-3] = v_31014;
    stack[-4] = v_31013;
    stack[-5] = v_31012;
// end of prologue
    v_31196 = stack[-5];
    if (!consp(v_31196)) goto v_31023;
    else goto v_31024;
v_31023:
    v_31196 = lisp_true;
    goto v_31022;
v_31024:
    v_31196 = stack[-5];
    v_31196 = qcar(v_31196);
    v_31196 = (consp(v_31196) ? nil : lisp_true);
    goto v_31022;
    v_31196 = nil;
v_31022:
    if (v_31196 == nil) goto v_31020;
    goto v_31040;
v_31036:
    v_31197 = stack[-5];
    goto v_31037;
v_31038:
    v_31196 = stack[-3];
    goto v_31039;
v_31040:
    goto v_31036;
v_31037:
    goto v_31038;
v_31039:
    fn = elt(env, 2); // multf
    v_31196 = (*qfn2(fn))(fn, v_31197, v_31196);
    env = stack[-7];
    stack[-3] = v_31196;
    goto v_31051;
v_31047:
    v_31197 = stack[-2];
    goto v_31048;
v_31049:
    v_31196 = qvalue(elt(env, 1)); // list!-pq
    goto v_31050;
v_31051:
    goto v_31047;
v_31048:
    goto v_31049;
v_31050:
    v_31196 = Lassoc(nil, v_31197, v_31196);
    v_31197 = v_31196;
    if (v_31196 == nil) goto v_31046;
    goto v_31060;
v_31056:
    stack[0] = v_31197;
    goto v_31057;
v_31058:
    goto v_31067;
v_31063:
    v_31196 = v_31197;
    v_31197 = qcdr(v_31196);
    goto v_31064;
v_31065:
    v_31196 = stack[-3];
    goto v_31066;
v_31067:
    goto v_31063;
v_31064:
    goto v_31065;
v_31066:
    fn = elt(env, 3); // addf
    v_31196 = (*qfn2(fn))(fn, v_31197, v_31196);
    env = stack[-7];
    goto v_31059;
v_31060:
    goto v_31056;
v_31057:
    goto v_31058;
v_31059:
    v_31196 = Lrplacd(nil, stack[0], v_31196);
    goto v_31044;
v_31046:
    goto v_31080;
v_31074:
    v_31198 = stack[-2];
    goto v_31075;
v_31076:
    v_31197 = stack[-3];
    goto v_31077;
v_31078:
    v_31196 = qvalue(elt(env, 1)); // list!-pq
    goto v_31079;
v_31080:
    goto v_31074;
v_31075:
    goto v_31076;
v_31077:
    goto v_31078;
v_31079:
    v_31196 = acons(v_31198, v_31197, v_31196);
    env = stack[-7];
    qvalue(elt(env, 1)) = v_31196; // list!-pq
    goto v_31044;
v_31044:
    v_31196 = nil;
    goto v_31018;
v_31020:
    goto v_31101;
v_31097:
    v_31196 = stack[-5];
    v_31196 = qcar(v_31196);
    v_31196 = qcar(v_31196);
    v_31197 = qcar(v_31196);
    goto v_31098;
v_31099:
    v_31196 = stack[-4];
    goto v_31100;
v_31101:
    goto v_31097;
v_31098:
    goto v_31099;
v_31100:
    if (!consp(v_31197)) goto v_31095;
    v_31197 = qcar(v_31197);
    if (v_31197 == v_31196) goto v_31094;
    else goto v_31095;
v_31094:
    goto v_31112;
v_31108:
    v_31196 = stack[-5];
    v_31196 = qcar(v_31196);
    v_31196 = qcar(v_31196);
    v_31196 = qcar(v_31196);
    v_31197 = Llength(nil, v_31196);
    env = stack[-7];
    goto v_31109;
v_31110:
    v_31196 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31111;
v_31112:
    goto v_31108;
v_31109:
    goto v_31110;
v_31111:
    v_31196 = (LispObject)greaterp2(v_31197, v_31196);
    v_31196 = v_31196 ? lisp_true : nil;
    env = stack[-7];
    goto v_31093;
v_31095:
    v_31196 = nil;
    goto v_31093;
    v_31196 = nil;
v_31093:
    if (v_31196 == nil) goto v_31091;
    goto v_31131;
v_31123:
    v_31196 = stack[-5];
    v_31196 = qcar(v_31196);
    stack[-6] = qcdr(v_31196);
    goto v_31124;
v_31125:
    stack[-1] = stack[-4];
    goto v_31126;
v_31127:
    stack[0] = stack[-3];
    goto v_31128;
v_31129:
    goto v_31142;
v_31138:
    v_31196 = stack[-5];
    v_31196 = qcar(v_31196);
    v_31197 = qcar(v_31196);
    goto v_31139;
v_31140:
    v_31196 = stack[-2];
    goto v_31141;
v_31142:
    goto v_31138;
v_31139:
    goto v_31140;
v_31141:
    v_31196 = cons(v_31197, v_31196);
    env = stack[-7];
    goto v_31130;
v_31131:
    goto v_31123;
v_31124:
    goto v_31125;
v_31126:
    goto v_31127;
v_31128:
    goto v_31129;
v_31130:
    v_31196 = CC_splitrec(elt(env, 0), 4, stack[-6], stack[-1], stack[0], v_31196);
    env = stack[-7];
    goto v_31089;
v_31091:
    goto v_31158;
v_31150:
    v_31196 = stack[-5];
    v_31196 = qcar(v_31196);
    stack[-1] = qcdr(v_31196);
    goto v_31151;
v_31152:
    stack[0] = stack[-4];
    goto v_31153;
v_31154:
    goto v_31169;
v_31165:
    v_31196 = stack[-5];
    v_31196 = qcar(v_31196);
    v_31197 = qcar(v_31196);
    goto v_31166;
v_31167:
    v_31196 = stack[-3];
    goto v_31168;
v_31169:
    goto v_31165;
v_31166:
    goto v_31167;
v_31168:
    v_31196 = cons(v_31197, v_31196);
    env = stack[-7];
    v_31197 = ncons(v_31196);
    env = stack[-7];
    goto v_31155;
v_31156:
    v_31196 = stack[-2];
    goto v_31157;
v_31158:
    goto v_31150;
v_31151:
    goto v_31152;
v_31153:
    goto v_31154;
v_31155:
    goto v_31156;
v_31157:
    v_31196 = CC_splitrec(elt(env, 0), 4, stack[-1], stack[0], v_31197, v_31196);
    env = stack[-7];
    goto v_31089;
v_31089:
    v_31196 = stack[-5];
    v_31196 = qcdr(v_31196);
    if (v_31196 == nil) goto v_31178;
    goto v_31190;
v_31182:
    v_31196 = stack[-5];
    v_31199 = qcdr(v_31196);
    goto v_31183;
v_31184:
    v_31198 = stack[-4];
    goto v_31185;
v_31186:
    v_31197 = stack[-3];
    goto v_31187;
v_31188:
    v_31196 = stack[-2];
    goto v_31189;
v_31190:
    goto v_31182;
v_31183:
    goto v_31184;
v_31185:
    goto v_31186;
v_31187:
    goto v_31188;
v_31189:
    v_31196 = CC_splitrec(elt(env, 0), 4, v_31199, v_31198, v_31197, v_31196);
    goto v_31176;
v_31178:
v_31176:
    v_31196 = nil;
    goto v_31018;
    v_31196 = nil;
v_31018:
    return onevalue(v_31196);
}



// Code for multsqpf

static LispObject CC_multsqpf(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31062, v_31063;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31012,v_31013);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_31013;
    stack[-2] = v_31012;
// end of prologue
    stack[-3] = nil;
v_31018:
    v_31062 = stack[-1];
    if (v_31062 == nil) goto v_31025;
    else goto v_31026;
v_31025:
    v_31062 = lisp_true;
    goto v_31024;
v_31026:
    v_31062 = stack[-2];
    v_31062 = qcar(v_31062);
    v_31062 = (v_31062 == nil ? lisp_true : nil);
    goto v_31024;
    v_31062 = nil;
v_31024:
    if (v_31062 == nil) goto v_31022;
    v_31062 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_31062);
    }
v_31022:
    goto v_31045;
v_31039:
    v_31062 = stack[-1];
    v_31062 = qcar(v_31062);
    stack[0] = qcar(v_31062);
    goto v_31040;
v_31041:
    goto v_31054;
v_31050:
    v_31063 = stack[-2];
    goto v_31051;
v_31052:
    v_31062 = stack[-1];
    v_31062 = qcar(v_31062);
    v_31062 = qcdr(v_31062);
    goto v_31053;
v_31054:
    goto v_31050;
v_31051:
    goto v_31052;
v_31053:
    fn = elt(env, 2); // multsq
    v_31063 = (*qfn2(fn))(fn, v_31063, v_31062);
    env = stack[-4];
    goto v_31042;
v_31043:
    v_31062 = stack[-3];
    goto v_31044;
v_31045:
    goto v_31039;
v_31040:
    goto v_31041;
v_31042:
    goto v_31043;
v_31044:
    v_31062 = acons(stack[0], v_31063, v_31062);
    env = stack[-4];
    stack[-3] = v_31062;
    v_31062 = stack[-1];
    v_31062 = qcdr(v_31062);
    stack[-1] = v_31062;
    goto v_31018;
    v_31062 = nil;
    return onevalue(v_31062);
}



// Code for sqprla

static LispObject CC_sqprla(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31025, v_31026;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31012,v_31013);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_31013;
    v_31025 = v_31012;
// end of prologue
    goto v_31020;
v_31016:
    v_31025 = qcar(v_31025);
    fn = elt(env, 1); // prepsq!*
    v_31026 = (*qfn1(fn))(fn, v_31025);
    env = stack[-1];
    goto v_31017;
v_31018:
    v_31025 = stack[0];
    goto v_31019;
v_31020:
    goto v_31016;
v_31017:
    goto v_31018;
v_31019:
    {
        fn = elt(env, 2); // maprintla
        return (*qfn2(fn))(fn, v_31026, v_31025);
    }
}



// Code for gffdot

static LispObject CC_gffdot(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31041, v_31042;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31012,v_31013);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31013;
    stack[-1] = v_31012;
// end of prologue
    goto v_31020;
v_31016:
    goto v_31026;
v_31022:
    v_31041 = stack[-1];
    v_31042 = qcar(v_31041);
    goto v_31023;
v_31024:
    v_31041 = stack[0];
    v_31041 = qcar(v_31041);
    goto v_31025;
v_31026:
    goto v_31022;
v_31023:
    goto v_31024;
v_31025:
    stack[-2] = times2(v_31042, v_31041);
    env = stack[-3];
    goto v_31017;
v_31018:
    goto v_31036;
v_31032:
    v_31041 = stack[-1];
    v_31042 = qcdr(v_31041);
    goto v_31033;
v_31034:
    v_31041 = stack[0];
    v_31041 = qcdr(v_31041);
    goto v_31035;
v_31036:
    goto v_31032;
v_31033:
    goto v_31034;
v_31035:
    v_31041 = times2(v_31042, v_31041);
    goto v_31019;
v_31020:
    goto v_31016;
v_31017:
    goto v_31018;
v_31019:
    {
        LispObject v_31046 = stack[-2];
        return plus2(v_31046, v_31041);
    }
}



// Code for red_redpol

static LispObject CC_red_redpol(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31044, v_31045;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31012,v_31013);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31044 = v_31013;
    stack[0] = v_31012;
// end of prologue
    fn = elt(env, 2); // red_prepare
    v_31044 = (*qfn1(fn))(fn, v_31044);
    env = stack[-1];
    v_31045 = qvalue(elt(env, 1)); // !*red_total
    if (v_31045 == nil) goto v_31024;
    goto v_31031;
v_31027:
    v_31045 = stack[0];
    goto v_31028;
v_31029:
    goto v_31030;
v_31031:
    goto v_31027;
v_31028:
    goto v_31029;
v_31030:
    fn = elt(env, 3); // red_totalred
    v_31044 = (*qfn2(fn))(fn, v_31045, v_31044);
    env = stack[-1];
    goto v_31022;
v_31024:
    goto v_31041;
v_31037:
    v_31045 = stack[0];
    goto v_31038;
v_31039:
    goto v_31040;
v_31041:
    goto v_31037;
v_31038:
    goto v_31039;
v_31040:
    fn = elt(env, 4); // red_topred
    v_31044 = (*qfn2(fn))(fn, v_31045, v_31044);
    env = stack[-1];
    goto v_31022;
    v_31044 = nil;
v_31022:
    {
        fn = elt(env, 5); // red_extract
        return (*qfn1(fn))(fn, v_31044);
    }
    return onevalue(v_31044);
}



// Code for eval_uni_poly

static LispObject CC_eval_uni_poly(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31114, v_31115;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31012,v_31013);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_31013;
    stack[-3] = v_31012;
// end of prologue
    v_31114 = stack[-3];
    if (!consp(v_31114)) goto v_31017;
    else goto v_31018;
v_31017:
    v_31114 = stack[-3];
    goto v_31016;
v_31018:
// Binding d
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = nil; // d
    v_31114 = stack[-3];
    v_31114 = qcar(v_31114);
    v_31114 = qcdr(v_31114);
    v_31115 = v_31114;
    v_31114 = stack[-3];
    v_31114 = qcar(v_31114);
    v_31114 = qcar(v_31114);
    v_31114 = qcdr(v_31114);
    qvalue(elt(env, 1)) = v_31114; // d
    v_31114 = stack[-3];
    v_31114 = qcdr(v_31114);
    stack[-3] = v_31114;
v_31038:
    v_31114 = stack[-3];
    if (!consp(v_31114)) goto v_31041;
    else goto v_31042;
v_31041:
    goto v_31037;
v_31042:
    goto v_31050;
v_31046:
    goto v_31056;
v_31052:
    stack[-1] = v_31115;
    goto v_31053;
v_31054:
    goto v_31063;
v_31059:
    stack[0] = stack[-2];
    goto v_31060;
v_31061:
    goto v_31070;
v_31066:
    v_31115 = qvalue(elt(env, 1)); // d
    goto v_31067;
v_31068:
    v_31114 = stack[-3];
    v_31114 = qcar(v_31114);
    v_31114 = qcar(v_31114);
    v_31114 = qcdr(v_31114);
    goto v_31069;
v_31070:
    goto v_31066;
v_31067:
    goto v_31068;
v_31069:
    v_31114 = difference2(v_31115, v_31114);
    env = stack[-5];
    goto v_31062;
v_31063:
    goto v_31059;
v_31060:
    goto v_31061;
v_31062:
    v_31114 = Lexpt(nil, stack[0], v_31114);
    env = stack[-5];
    goto v_31055;
v_31056:
    goto v_31052;
v_31053:
    goto v_31054;
v_31055:
    v_31115 = times2(stack[-1], v_31114);
    env = stack[-5];
    goto v_31047;
v_31048:
    v_31114 = stack[-3];
    v_31114 = qcar(v_31114);
    v_31114 = qcdr(v_31114);
    goto v_31049;
v_31050:
    goto v_31046;
v_31047:
    goto v_31048;
v_31049:
    v_31114 = plus2(v_31115, v_31114);
    env = stack[-5];
    v_31115 = v_31114;
    v_31114 = stack[-3];
    v_31114 = qcar(v_31114);
    v_31114 = qcar(v_31114);
    v_31114 = qcdr(v_31114);
    qvalue(elt(env, 1)) = v_31114; // d
    v_31114 = stack[-3];
    v_31114 = qcdr(v_31114);
    stack[-3] = v_31114;
    goto v_31038;
v_31037:
    goto v_31090;
v_31086:
    stack[0] = v_31115;
    goto v_31087;
v_31088:
    goto v_31097;
v_31093:
    v_31115 = stack[-2];
    goto v_31094;
v_31095:
    v_31114 = qvalue(elt(env, 1)); // d
    goto v_31096;
v_31097:
    goto v_31093;
v_31094:
    goto v_31095;
v_31096:
    v_31114 = Lexpt(nil, v_31115, v_31114);
    env = stack[-5];
    goto v_31089;
v_31090:
    goto v_31086;
v_31087:
    goto v_31088;
v_31089:
    v_31114 = times2(stack[0], v_31114);
    env = stack[-5];
    v_31115 = v_31114;
    v_31114 = stack[-3];
    if (v_31114 == nil) goto v_31103;
    goto v_31110;
v_31106:
    goto v_31107;
v_31108:
    v_31114 = stack[-3];
    goto v_31109;
v_31110:
    goto v_31106;
v_31107:
    goto v_31108;
v_31109:
    v_31114 = plus2(v_31115, v_31114);
    v_31115 = v_31114;
    goto v_31101;
v_31103:
v_31101:
    v_31114 = v_31115;
    ;}  // end of a binding scope
    goto v_31016;
    v_31114 = nil;
v_31016:
    return onevalue(v_31114);
}



// Code for precision1

static LispObject CC_precision1(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31160, v_31161, v_31162;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31012,v_31013);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_31162 = v_31013;
    stack[0] = v_31012;
// end of prologue
    goto v_31026;
v_31022:
    v_31161 = stack[0];
    goto v_31023;
v_31024:
    v_31160 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31025;
v_31026:
    goto v_31022;
v_31023:
    goto v_31024;
v_31025:
    if (v_31161 == v_31160) goto v_31020;
    else goto v_31021;
v_31020:
    v_31160 = qvalue(elt(env, 1)); // !!rdprec
    goto v_31017;
v_31021:
    v_31160 = v_31162;
    if (v_31160 == nil) goto v_31033;
    fn = elt(env, 13); // rmsubs
    v_31160 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_31031;
v_31033:
v_31031:
    v_31160 = qvalue(elt(env, 1)); // !!rdprec
    stack[-3] = v_31160;
    goto v_31042;
v_31038:
    v_31160 = qvalue(elt(env, 2)); // !*roundbf
    if (v_31160 == nil) goto v_31046;
    v_31160 = stack[0];
    v_31161 = v_31160;
    goto v_31044;
v_31046:
    goto v_31056;
v_31052:
    v_31161 = stack[0];
    goto v_31053;
v_31054:
    v_31160 = qvalue(elt(env, 3)); // minprec!#
    goto v_31055;
v_31056:
    goto v_31052;
v_31053:
    goto v_31054;
v_31055:
    fn = elt(env, 14); // max
    v_31160 = (*qfn2(fn))(fn, v_31161, v_31160);
    env = stack[-4];
    v_31161 = v_31160;
    goto v_31044;
    v_31161 = nil;
v_31044:
    qvalue(elt(env, 1)) = v_31161; // !!rdprec
    goto v_31039;
v_31040:
    v_31160 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31041;
v_31042:
    goto v_31038;
v_31039:
    goto v_31040;
v_31041:
    v_31160 = plus2(v_31161, v_31160);
    env = stack[-4];
    qvalue(elt(env, 4)) = v_31160; // !:prec!:
    v_31160 = qvalue(elt(env, 5)); // !:print!-prec!:
    if (v_31160 == nil) goto v_31063;
    goto v_31072;
v_31068:
    goto v_31069;
v_31070:
    goto v_31079;
v_31075:
    v_31161 = qvalue(elt(env, 5)); // !:print!-prec!:
    goto v_31076;
v_31077:
    v_31160 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31078;
v_31079:
    goto v_31075;
v_31076:
    goto v_31077;
v_31078:
    v_31160 = plus2(v_31161, v_31160);
    env = stack[-4];
    goto v_31071;
v_31072:
    goto v_31068;
v_31069:
    goto v_31070;
v_31071:
    v_31160 = (LispObject)lessp2(stack[0], v_31160);
    v_31160 = v_31160 ? lisp_true : nil;
    env = stack[-4];
    if (v_31160 == nil) goto v_31063;
    v_31160 = nil;
    qvalue(elt(env, 5)) = v_31160; // !:print!-prec!:
    goto v_31061;
v_31063:
v_31061:
    v_31160 = qvalue(elt(env, 4)); // !:prec!:
    fn = elt(env, 15); // decprec2internal
    v_31160 = (*qfn1(fn))(fn, v_31160);
    env = stack[-4];
    qvalue(elt(env, 6)) = v_31160; // !:bprec!:
    goto v_31092;
v_31086:
    stack[-1] = elt(env, 7); // !:rd!:
    goto v_31087;
v_31088:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31089;
v_31090:
    goto v_31101;
v_31097:
    v_31161 = qvalue(elt(env, 6)); // !:bprec!:
    goto v_31098;
v_31099:
    v_31160 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31100;
v_31101:
    goto v_31097;
v_31098:
    goto v_31099;
v_31100:
    v_31160 = quot2(v_31161, v_31160);
    env = stack[-4];
    v_31160 = negate(v_31160);
    env = stack[-4];
    goto v_31091;
v_31092:
    goto v_31086;
v_31087:
    goto v_31088;
v_31089:
    goto v_31090;
v_31091:
    v_31160 = list2star(stack[-1], stack[0], v_31160);
    env = stack[-4];
    qvalue(elt(env, 8)) = v_31160; // epsqrt!*
    goto v_31111;
v_31105:
    stack[-1] = elt(env, 7); // !:rd!:
    goto v_31106;
v_31107:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31108;
v_31109:
    goto v_31119;
v_31115:
    v_31161 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_31116;
v_31117:
    v_31160 = qvalue(elt(env, 6)); // !:bprec!:
    goto v_31118;
v_31119:
    goto v_31115;
v_31116:
    goto v_31117;
v_31118:
    v_31160 = difference2(v_31161, v_31160);
    env = stack[-4];
    goto v_31110;
v_31111:
    goto v_31105;
v_31106:
    goto v_31107;
v_31108:
    goto v_31109;
v_31110:
    v_31160 = list2star(stack[-1], stack[0], v_31160);
    env = stack[-4];
    qvalue(elt(env, 9)) = v_31160; // rd!-tolerance!*
    goto v_31129;
v_31123:
    stack[-2] = elt(env, 7); // !:rd!:
    goto v_31124;
v_31125:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31126;
v_31127:
    goto v_31137;
v_31133:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31134;
v_31135:
    goto v_31144;
v_31140:
    v_31161 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_31141;
v_31142:
    v_31160 = qvalue(elt(env, 6)); // !:bprec!:
    goto v_31143;
v_31144:
    goto v_31140;
v_31141:
    goto v_31142;
v_31143:
    v_31160 = difference2(v_31161, v_31160);
    env = stack[-4];
    goto v_31136;
v_31137:
    goto v_31133;
v_31134:
    goto v_31135;
v_31136:
    v_31160 = times2(stack[0], v_31160);
    env = stack[-4];
    goto v_31128;
v_31129:
    goto v_31123;
v_31124:
    goto v_31125;
v_31126:
    goto v_31127;
v_31128:
    v_31160 = list2star(stack[-2], stack[-1], v_31160);
    env = stack[-4];
    qvalue(elt(env, 10)) = v_31160; // cr!-tolerance!*
    goto v_31155;
v_31151:
    v_31161 = qvalue(elt(env, 1)); // !!rdprec
    goto v_31152;
v_31153:
    v_31160 = qvalue(elt(env, 11)); // !!flprec
    goto v_31154;
v_31155:
    goto v_31151;
v_31152:
    goto v_31153;
v_31154:
    v_31160 = (LispObject)greaterp2(v_31161, v_31160);
    v_31160 = v_31160 ? lisp_true : nil;
    env = stack[-4];
    if (v_31160 == nil) goto v_31149;
    else goto v_31148;
v_31149:
    v_31160 = qvalue(elt(env, 2)); // !*roundbf
v_31148:
    qvalue(elt(env, 12)) = v_31160; // !*!*roundbf
    v_31160 = stack[-3];
v_31017:
    return onevalue(v_31160);
}



// Code for ofsf_irl2atl

static LispObject CC_ofsf_irl2atl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31084, v_31085, v_31086;
    LispObject fn;
    LispObject v_31014, v_31013, v_31012;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_irl2atl");
    va_start(aa, nargs);
    v_31012 = va_arg(aa, LispObject);
    v_31013 = va_arg(aa, LispObject);
    v_31014 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31014,v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31012,v_31013,v_31014);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_31014;
    v_31084 = v_31013;
    stack[-4] = v_31012;
// end of prologue
    stack[-5] = v_31084;
v_31021:
    v_31084 = stack[-5];
    if (v_31084 == nil) goto v_31026;
    else goto v_31027;
v_31026:
    v_31084 = nil;
    goto v_31020;
v_31027:
    v_31084 = stack[-5];
    v_31084 = qcar(v_31084);
    goto v_31040;
v_31034:
    v_31086 = stack[-4];
    goto v_31035;
v_31036:
    v_31085 = v_31084;
    goto v_31037;
v_31038:
    v_31084 = stack[-3];
    goto v_31039;
v_31040:
    goto v_31034;
v_31035:
    goto v_31036;
v_31037:
    goto v_31038;
v_31039:
    fn = elt(env, 1); // ofsf_ir2atl
    v_31084 = (*qfnn(fn))(fn, 3, v_31086, v_31085, v_31084);
    env = stack[-6];
    stack[-2] = v_31084;
    v_31084 = stack[-2];
    fn = elt(env, 2); // lastpair
    v_31084 = (*qfn1(fn))(fn, v_31084);
    env = stack[-6];
    stack[-1] = v_31084;
    v_31084 = stack[-5];
    v_31084 = qcdr(v_31084);
    stack[-5] = v_31084;
    v_31084 = stack[-1];
    if (!consp(v_31084)) goto v_31050;
    else goto v_31051;
v_31050:
    goto v_31021;
v_31051:
v_31022:
    v_31084 = stack[-5];
    if (v_31084 == nil) goto v_31055;
    else goto v_31056;
v_31055:
    v_31084 = stack[-2];
    goto v_31020;
v_31056:
    goto v_31064;
v_31060:
    stack[0] = stack[-1];
    goto v_31061;
v_31062:
    v_31084 = stack[-5];
    v_31084 = qcar(v_31084);
    goto v_31076;
v_31070:
    v_31086 = stack[-4];
    goto v_31071;
v_31072:
    v_31085 = v_31084;
    goto v_31073;
v_31074:
    v_31084 = stack[-3];
    goto v_31075;
v_31076:
    goto v_31070;
v_31071:
    goto v_31072;
v_31073:
    goto v_31074;
v_31075:
    fn = elt(env, 1); // ofsf_ir2atl
    v_31084 = (*qfnn(fn))(fn, 3, v_31086, v_31085, v_31084);
    env = stack[-6];
    goto v_31063;
v_31064:
    goto v_31060;
v_31061:
    goto v_31062;
v_31063:
    v_31084 = Lrplacd(nil, stack[0], v_31084);
    env = stack[-6];
    v_31084 = stack[-1];
    fn = elt(env, 2); // lastpair
    v_31084 = (*qfn1(fn))(fn, v_31084);
    env = stack[-6];
    stack[-1] = v_31084;
    v_31084 = stack[-5];
    v_31084 = qcdr(v_31084);
    stack[-5] = v_31084;
    goto v_31022;
v_31020:
    return onevalue(v_31084);
}



// Code for ofsf_smmkatl!-or1

static LispObject CC_ofsf_smmkatlKor1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31192, v_31193, v_31194;
    LispObject fn;
    LispObject v_31014, v_31013, v_31012;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_smmkatl-or1");
    va_start(aa, nargs);
    v_31012 = va_arg(aa, LispObject);
    v_31013 = va_arg(aa, LispObject);
    v_31014 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31014,v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31012,v_31013,v_31014);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_31014;
    stack[0] = v_31013;
    stack[-6] = v_31012;
// end of prologue
    goto v_31025;
v_31021:
    v_31192 = stack[0];
    v_31193 = qcar(v_31192);
    goto v_31022;
v_31023:
    v_31192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31024;
v_31025:
    goto v_31021;
v_31022:
    goto v_31023;
v_31024:
    v_31192 = cons(v_31193, v_31192);
    env = stack[-8];
    stack[-7] = v_31192;
    v_31192 = stack[0];
    v_31192 = qcdr(v_31192);
    stack[-4] = v_31192;
v_31034:
    v_31192 = stack[-4];
    if (v_31192 == nil) goto v_31040;
    else goto v_31041;
v_31040:
    v_31192 = nil;
    goto v_31033;
v_31041:
    v_31192 = stack[-4];
    v_31192 = qcar(v_31192);
    stack[0] = v_31192;
    goto v_31055;
v_31051:
    v_31192 = stack[0];
    v_31193 = qcar(v_31192);
    goto v_31052;
v_31053:
    v_31192 = stack[-5];
    goto v_31054;
v_31055:
    goto v_31051;
v_31052:
    goto v_31053;
v_31054:
    if (equal(v_31193, v_31192)) goto v_31049;
    else goto v_31050;
v_31049:
    goto v_31068;
v_31064:
    v_31192 = stack[0];
    v_31192 = qcdr(v_31192);
    v_31193 = qcar(v_31192);
    goto v_31065;
v_31066:
    v_31192 = elt(env, 1); // (lessp greaterp equal)
    goto v_31067;
v_31068:
    goto v_31064;
v_31065:
    goto v_31066;
v_31067:
    v_31192 = Lmemq(nil, v_31193, v_31192);
    if (v_31192 == nil) goto v_31062;
    goto v_31082;
v_31076:
    v_31192 = stack[-6];
    v_31194 = qcdr(v_31192);
    goto v_31077;
v_31078:
    v_31192 = stack[0];
    v_31193 = qcdr(v_31192);
    goto v_31079;
v_31080:
    v_31192 = stack[-7];
    goto v_31081;
v_31082:
    goto v_31076;
v_31077:
    goto v_31078;
v_31079:
    goto v_31080;
v_31081:
    fn = elt(env, 3); // ofsf_smmkat!-or2
    v_31192 = (*qfnn(fn))(fn, 3, v_31194, v_31193, v_31192);
    env = stack[-8];
    v_31193 = v_31192;
    if (v_31192 == nil) goto v_31062;
    v_31192 = v_31193;
    v_31192 = ncons(v_31192);
    env = stack[-8];
    goto v_31060;
v_31062:
    goto v_31100;
v_31094:
    v_31194 = elt(env, 2); // or
    goto v_31095;
v_31096:
    v_31192 = stack[0];
    v_31193 = qcdr(v_31192);
    goto v_31097;
v_31098:
    v_31192 = stack[-7];
    goto v_31099;
v_31100:
    goto v_31094;
v_31095:
    goto v_31096;
v_31097:
    goto v_31098;
v_31099:
    fn = elt(env, 4); // ofsf_entry2at
    v_31192 = (*qfnn(fn))(fn, 3, v_31194, v_31193, v_31192);
    env = stack[-8];
    v_31192 = ncons(v_31192);
    env = stack[-8];
    goto v_31060;
    v_31192 = nil;
v_31060:
    goto v_31048;
v_31050:
    v_31192 = nil;
v_31048:
    stack[-3] = v_31192;
    v_31192 = stack[-3];
    fn = elt(env, 5); // lastpair
    v_31192 = (*qfn1(fn))(fn, v_31192);
    env = stack[-8];
    stack[-2] = v_31192;
    v_31192 = stack[-4];
    v_31192 = qcdr(v_31192);
    stack[-4] = v_31192;
    v_31192 = stack[-2];
    if (!consp(v_31192)) goto v_31111;
    else goto v_31112;
v_31111:
    goto v_31034;
v_31112:
v_31035:
    v_31192 = stack[-4];
    if (v_31192 == nil) goto v_31116;
    else goto v_31117;
v_31116:
    v_31192 = stack[-3];
    goto v_31033;
v_31117:
    goto v_31125;
v_31121:
    stack[-1] = stack[-2];
    goto v_31122;
v_31123:
    v_31192 = stack[-4];
    v_31192 = qcar(v_31192);
    stack[0] = v_31192;
    goto v_31138;
v_31134:
    v_31192 = stack[0];
    v_31193 = qcar(v_31192);
    goto v_31135;
v_31136:
    v_31192 = stack[-5];
    goto v_31137;
v_31138:
    goto v_31134;
v_31135:
    goto v_31136;
v_31137:
    if (equal(v_31193, v_31192)) goto v_31132;
    else goto v_31133;
v_31132:
    goto v_31151;
v_31147:
    v_31192 = stack[0];
    v_31192 = qcdr(v_31192);
    v_31193 = qcar(v_31192);
    goto v_31148;
v_31149:
    v_31192 = elt(env, 1); // (lessp greaterp equal)
    goto v_31150;
v_31151:
    goto v_31147;
v_31148:
    goto v_31149;
v_31150:
    v_31192 = Lmemq(nil, v_31193, v_31192);
    if (v_31192 == nil) goto v_31145;
    goto v_31165;
v_31159:
    v_31192 = stack[-6];
    v_31194 = qcdr(v_31192);
    goto v_31160;
v_31161:
    v_31192 = stack[0];
    v_31193 = qcdr(v_31192);
    goto v_31162;
v_31163:
    v_31192 = stack[-7];
    goto v_31164;
v_31165:
    goto v_31159;
v_31160:
    goto v_31161;
v_31162:
    goto v_31163;
v_31164:
    fn = elt(env, 3); // ofsf_smmkat!-or2
    v_31192 = (*qfnn(fn))(fn, 3, v_31194, v_31193, v_31192);
    env = stack[-8];
    v_31193 = v_31192;
    if (v_31192 == nil) goto v_31145;
    v_31192 = v_31193;
    v_31192 = ncons(v_31192);
    env = stack[-8];
    goto v_31143;
v_31145:
    goto v_31183;
v_31177:
    v_31194 = elt(env, 2); // or
    goto v_31178;
v_31179:
    v_31192 = stack[0];
    v_31193 = qcdr(v_31192);
    goto v_31180;
v_31181:
    v_31192 = stack[-7];
    goto v_31182;
v_31183:
    goto v_31177;
v_31178:
    goto v_31179;
v_31180:
    goto v_31181;
v_31182:
    fn = elt(env, 4); // ofsf_entry2at
    v_31192 = (*qfnn(fn))(fn, 3, v_31194, v_31193, v_31192);
    env = stack[-8];
    v_31192 = ncons(v_31192);
    env = stack[-8];
    goto v_31143;
    v_31192 = nil;
v_31143:
    goto v_31131;
v_31133:
    v_31192 = nil;
v_31131:
    goto v_31124;
v_31125:
    goto v_31121;
v_31122:
    goto v_31123;
v_31124:
    v_31192 = Lrplacd(nil, stack[-1], v_31192);
    env = stack[-8];
    v_31192 = stack[-2];
    fn = elt(env, 5); // lastpair
    v_31192 = (*qfn1(fn))(fn, v_31192);
    env = stack[-8];
    stack[-2] = v_31192;
    v_31192 = stack[-4];
    v_31192 = qcdr(v_31192);
    stack[-4] = v_31192;
    goto v_31035;
v_31033:
    return onevalue(v_31192);
}



// Code for sfpf

static LispObject CC_sfpf(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31037, v_31038;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31038 = v_31012;
// end of prologue
    v_31037 = v_31038;
    if (!consp(v_31037)) goto v_31020;
    else goto v_31021;
v_31020:
    v_31037 = lisp_true;
    goto v_31019;
v_31021:
    v_31037 = v_31038;
    v_31037 = qcar(v_31037);
    v_31037 = (consp(v_31037) ? nil : lisp_true);
    goto v_31019;
    v_31037 = nil;
v_31019:
    if (v_31037 == nil) goto v_31016;
    else goto v_31017;
v_31016:
    v_31037 = v_31038;
    v_31037 = qcar(v_31037);
    v_31037 = qcar(v_31037);
    v_31037 = qcar(v_31037);
    {
        fn = elt(env, 1); // sfp
        return (*qfn1(fn))(fn, v_31037);
    }
v_31017:
    v_31037 = nil;
    goto v_31015;
    v_31037 = nil;
v_31015:
    return onevalue(v_31037);
}



// Code for constant_exprp

static LispObject CC_constant_exprp(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31149, v_31150, v_31151;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31012);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31150 = v_31012;
// end of prologue
    v_31149 = v_31150;
    if (!consp(v_31149)) goto v_31016;
    else goto v_31017;
v_31016:
    v_31149 = v_31150;
    v_31149 = (is_number(v_31149) ? lisp_true : nil);
    if (v_31149 == nil) goto v_31021;
    else goto v_31020;
v_31021:
    goto v_31033;
v_31029:
    v_31151 = v_31150;
    goto v_31030;
v_31031:
    v_31149 = elt(env, 1); // constant
    goto v_31032;
v_31033:
    goto v_31029;
v_31030:
    goto v_31031;
v_31032:
    v_31149 = Lflagp(nil, v_31151, v_31149);
    env = stack[0];
    if (v_31149 == nil) goto v_31027;
    v_31149 = lisp_true;
    goto v_31025;
v_31027:
    goto v_31047;
v_31043:
    goto v_31044;
v_31045:
    v_31149 = elt(env, 2); // i
    goto v_31046;
v_31047:
    goto v_31043;
v_31044:
    goto v_31045;
v_31046:
    if (v_31150 == v_31149) goto v_31041;
    else goto v_31042;
v_31041:
    v_31149 = elt(env, 2); // i
    if (!symbolp(v_31149)) v_31149 = nil;
    else { v_31149 = qfastgets(v_31149);
           if (v_31149 != nil) { v_31149 = elt(v_31149, 56); // idvalfn
#ifdef RECORD_GET
             if (v_31149 != SPID_NOPROP)
                record_get(elt(fastget_names, 56), 1);
             else record_get(elt(fastget_names, 56), 0),
                v_31149 = nil; }
           else record_get(elt(fastget_names, 56), 0); }
#else
             if (v_31149 == SPID_NOPROP) v_31149 = nil; }}
#endif
    goto v_31040;
v_31042:
    v_31149 = nil;
    goto v_31040;
    v_31149 = nil;
v_31040:
    goto v_31025;
    v_31149 = nil;
v_31025:
v_31020:
    goto v_31015;
v_31017:
    goto v_31070;
v_31066:
    v_31149 = v_31150;
    v_31151 = qcar(v_31149);
    goto v_31067;
v_31068:
    v_31149 = elt(env, 3); // realvalued
    goto v_31069;
v_31070:
    goto v_31066;
v_31067:
    goto v_31068;
v_31069:
    v_31149 = Lflagp(nil, v_31151, v_31149);
    env = stack[0];
    if (v_31149 == nil) goto v_31064;
    v_31149 = lisp_true;
    goto v_31062;
v_31064:
    goto v_31086;
v_31082:
    v_31149 = v_31150;
    v_31151 = qcar(v_31149);
    goto v_31083;
v_31084:
    v_31149 = elt(env, 4); // alwaysrealvalued
    goto v_31085;
v_31086:
    goto v_31082;
v_31083:
    goto v_31084;
v_31085:
    v_31149 = Lflagp(nil, v_31151, v_31149);
    env = stack[0];
    if (v_31149 == nil) goto v_31080;
    v_31149 = lisp_true;
    goto v_31078;
v_31080:
    goto v_31100;
v_31096:
    v_31149 = v_31150;
    v_31151 = qcar(v_31149);
    goto v_31097;
v_31098:
    v_31149 = elt(env, 5); // (plus minus difference times quotient)
    goto v_31099;
v_31100:
    goto v_31096;
v_31097:
    goto v_31098;
v_31099:
    v_31149 = Lmemq(nil, v_31151, v_31149);
    if (v_31149 == nil) goto v_31095;
    else goto v_31094;
v_31095:
    goto v_31113;
v_31109:
    v_31149 = v_31150;
    v_31151 = qcar(v_31149);
    goto v_31110;
v_31111:
    v_31149 = elt(env, 6); // !:rd!:
    goto v_31112;
v_31113:
    goto v_31109;
v_31110:
    goto v_31111;
v_31112:
    v_31149 = get(v_31151, v_31149);
    env = stack[0];
    if (v_31149 == nil) goto v_31107;
    else goto v_31106;
v_31107:
    v_31149 = qvalue(elt(env, 7)); // !*complex
    if (v_31149 == nil) goto v_31119;
    else goto v_31120;
v_31119:
    v_31149 = nil;
    goto v_31118;
v_31120:
    goto v_31130;
v_31126:
    v_31149 = v_31150;
    v_31151 = qcar(v_31149);
    goto v_31127;
v_31128:
    v_31149 = elt(env, 8); // !:cr!:
    goto v_31129;
v_31130:
    goto v_31126;
v_31127:
    goto v_31128;
v_31129:
    v_31149 = get(v_31151, v_31149);
    env = stack[0];
    goto v_31118;
    v_31149 = nil;
v_31118:
v_31106:
v_31094:
    goto v_31078;
    v_31149 = nil;
v_31078:
    goto v_31062;
    v_31149 = nil;
v_31062:
    if (v_31149 == nil) goto v_31059;
    else goto v_31060;
v_31059:
    v_31149 = nil;
    goto v_31058;
v_31060:
    v_31149 = v_31150;
    v_31149 = qcdr(v_31149);
    if (!consp(v_31149)) goto v_31140;
    v_31149 = v_31150;
    v_31149 = qcdr(v_31149);
    {
        fn = elt(env, 9); // constant_expr_listp
        return (*qfn1(fn))(fn, v_31149);
    }
v_31140:
    v_31149 = nil;
    goto v_31138;
    v_31149 = nil;
v_31138:
    goto v_31058;
    v_31149 = nil;
v_31058:
    goto v_31015;
    v_31149 = nil;
v_31015:
    return onevalue(v_31149);
}



// Code for talp_mk!-invs

static LispObject CC_talp_mkKinvs(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31113, v_31114;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31012,v_31013);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_31013;
    v_31113 = v_31012;
// end of prologue
    if (v_31113 == nil) goto v_31018;
    goto v_31025;
v_31021:
    stack[-5] = stack[-4];
    goto v_31022;
v_31023:
    v_31113 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_31113;
    goto v_31044;
v_31040:
    v_31113 = stack[-4];
    v_31114 = qcdr(v_31113);
    goto v_31041;
v_31042:
    v_31113 = stack[-3];
    goto v_31043;
v_31044:
    goto v_31040;
v_31041:
    goto v_31042;
v_31043:
    v_31113 = difference2(v_31114, v_31113);
    env = stack[-6];
    v_31113 = Lminusp(nil, v_31113);
    env = stack[-6];
    if (v_31113 == nil) goto v_31037;
    v_31113 = nil;
    goto v_31031;
v_31037:
    goto v_31055;
v_31051:
    goto v_31061;
v_31057:
    v_31113 = stack[-4];
    v_31114 = qcar(v_31113);
    goto v_31058;
v_31059:
    v_31113 = stack[-3];
    goto v_31060;
v_31061:
    goto v_31057;
v_31058:
    goto v_31059;
v_31060:
    fn = elt(env, 1); // talp_mkinvop
    v_31114 = (*qfn2(fn))(fn, v_31114, v_31113);
    env = stack[-6];
    goto v_31052;
v_31053:
    v_31113 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31054;
v_31055:
    goto v_31051;
v_31052:
    goto v_31053;
v_31054:
    v_31113 = cons(v_31114, v_31113);
    env = stack[-6];
    v_31113 = ncons(v_31113);
    env = stack[-6];
    stack[-1] = v_31113;
    stack[-2] = v_31113;
v_31032:
    v_31113 = stack[-3];
    v_31113 = add1(v_31113);
    env = stack[-6];
    stack[-3] = v_31113;
    goto v_31078;
v_31074:
    v_31113 = stack[-4];
    v_31114 = qcdr(v_31113);
    goto v_31075;
v_31076:
    v_31113 = stack[-3];
    goto v_31077;
v_31078:
    goto v_31074;
v_31075:
    goto v_31076;
v_31077:
    v_31113 = difference2(v_31114, v_31113);
    env = stack[-6];
    v_31113 = Lminusp(nil, v_31113);
    env = stack[-6];
    if (v_31113 == nil) goto v_31071;
    v_31113 = stack[-2];
    goto v_31031;
v_31071:
    goto v_31088;
v_31084:
    stack[0] = stack[-1];
    goto v_31085;
v_31086:
    goto v_31096;
v_31092:
    goto v_31102;
v_31098:
    v_31113 = stack[-4];
    v_31114 = qcar(v_31113);
    goto v_31099;
v_31100:
    v_31113 = stack[-3];
    goto v_31101;
v_31102:
    goto v_31098;
v_31099:
    goto v_31100;
v_31101:
    fn = elt(env, 1); // talp_mkinvop
    v_31114 = (*qfn2(fn))(fn, v_31114, v_31113);
    env = stack[-6];
    goto v_31093;
v_31094:
    v_31113 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31095;
v_31096:
    goto v_31092;
v_31093:
    goto v_31094;
v_31095:
    v_31113 = cons(v_31114, v_31113);
    env = stack[-6];
    v_31113 = ncons(v_31113);
    env = stack[-6];
    goto v_31087;
v_31088:
    goto v_31084;
v_31085:
    goto v_31086;
v_31087:
    v_31113 = Lrplacd(nil, stack[0], v_31113);
    env = stack[-6];
    v_31113 = stack[-1];
    v_31113 = qcdr(v_31113);
    stack[-1] = v_31113;
    goto v_31032;
v_31031:
    goto v_31024;
v_31025:
    goto v_31021;
v_31022:
    goto v_31023;
v_31024:
    {
        LispObject v_31121 = stack[-5];
        return cons(v_31121, v_31113);
    }
v_31018:
    v_31113 = stack[-4];
    return ncons(v_31113);
    v_31113 = nil;
    return onevalue(v_31113);
}



// Code for aex_simplenumberp

static LispObject CC_aex_simplenumberp(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31017;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31012);
    }
// copy arguments values to proper place
    v_31017 = v_31012;
// end of prologue
    fn = elt(env, 1); // aex_fvarl
    v_31017 = (*qfn1(fn))(fn, v_31017);
    v_31017 = (v_31017 == nil ? lisp_true : nil);
    return onevalue(v_31017);
}



// Code for arprep!:

static LispObject CC_arprepT(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31027, v_31028;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31012);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31028 = v_31012;
// end of prologue
    v_31027 = qvalue(elt(env, 1)); // !*reexpress
    if (v_31027 == nil) goto v_31018;
    v_31027 = v_31028;
    v_31027 = qcdr(v_31027);
    fn = elt(env, 2); // express!-in!-arvars
    v_31027 = (*qfn1(fn))(fn, v_31027);
    env = stack[0];
    goto v_31016;
v_31018:
    v_31027 = v_31028;
    v_31027 = qcdr(v_31027);
    goto v_31016;
    v_31027 = nil;
v_31016:
    {
        fn = elt(env, 3); // prepf
        return (*qfn1(fn))(fn, v_31027);
    }
}



// Code for xpartitk

static LispObject CC_xpartitk(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31070, v_31071, v_31072;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31012);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_31012;
// end of prologue
    goto v_31023;
v_31019:
    v_31071 = stack[0];
    goto v_31020;
v_31021:
    v_31070 = elt(env, 1); // (wedge partdf)
    goto v_31022;
v_31023:
    goto v_31019;
v_31020:
    goto v_31021;
v_31022:
    fn = elt(env, 2); // memqcar
    v_31070 = (*qfn2(fn))(fn, v_31071, v_31070);
    env = stack[-1];
    if (v_31070 == nil) goto v_31017;
    v_31070 = stack[0];
    fn = elt(env, 3); // reval
    v_31070 = (*qfn1(fn))(fn, v_31070);
    env = stack[-1];
    v_31072 = v_31070;
    goto v_31037;
v_31033:
    v_31071 = v_31072;
    goto v_31034;
v_31035:
    v_31070 = stack[0];
    goto v_31036;
v_31037:
    goto v_31033;
v_31034:
    goto v_31035;
v_31036:
    if (equal(v_31071, v_31070)) goto v_31031;
    else goto v_31032;
v_31031:
    goto v_31048;
v_31042:
    v_31072 = stack[0];
    goto v_31043;
v_31044:
    v_31071 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31045;
v_31046:
    v_31070 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31047;
v_31048:
    goto v_31042;
v_31043:
    goto v_31044;
v_31045:
    goto v_31046;
v_31047:
    v_31070 = list2star(v_31072, v_31071, v_31070);
    return ncons(v_31070);
v_31032:
    v_31070 = v_31072;
    {
        fn = elt(env, 4); // xpartitop
        return (*qfn1(fn))(fn, v_31070);
    }
    v_31070 = nil;
    goto v_31015;
v_31017:
    goto v_31066;
v_31060:
    v_31072 = stack[0];
    goto v_31061;
v_31062:
    v_31071 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31063;
v_31064:
    v_31070 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31065;
v_31066:
    goto v_31060;
v_31061:
    goto v_31062;
v_31063:
    goto v_31064;
v_31065:
    v_31070 = list2star(v_31072, v_31071, v_31070);
    return ncons(v_31070);
    v_31070 = nil;
v_31015:
    return onevalue(v_31070);
}



// Code for minprec

static LispObject CC_minprec(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31022;
    argcheck(nargs, 0, "minprec");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_31022 = qvalue(elt(env, 1)); // !*bftag
    if (v_31022 == nil) goto v_31016;
    v_31022 = qvalue(elt(env, 2)); // !:prec!:
    goto v_31014;
v_31016:
    v_31022 = qvalue(elt(env, 3)); // !!nfpd
    goto v_31014;
    v_31022 = nil;
v_31014:
    return onevalue(v_31022);
}



// Code for r2oreaction

static LispObject CC_r2oreaction(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31175, v_31176, v_31177;
    LispObject fn;
    LispObject v_31015, v_31014, v_31013, v_31012;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "r2oreaction");
    va_start(aa, nargs);
    v_31012 = va_arg(aa, LispObject);
    v_31013 = va_arg(aa, LispObject);
    v_31014 = va_arg(aa, LispObject);
    v_31015 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_31015,v_31014,v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_31012,v_31013,v_31014,v_31015);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_31015;
    v_31175 = v_31014;
    stack[-5] = v_31013;
    stack[-1] = v_31012;
// end of prologue
    stack[-6] = v_31175;
    v_31175 = stack[-1];
    stack[-2] = v_31175;
v_31025:
    v_31175 = stack[-2];
    if (v_31175 == nil) goto v_31029;
    else goto v_31030;
v_31029:
    goto v_31024;
v_31030:
    v_31175 = stack[-2];
    v_31175 = qcar(v_31175);
    goto v_31044;
v_31038:
    stack[0] = elt(env, 1); // times
    goto v_31039;
v_31040:
    stack[-3] = stack[-6];
    goto v_31041;
v_31042:
    goto v_31054;
v_31048:
    v_31177 = elt(env, 2); // expt
    goto v_31049;
v_31050:
    v_31176 = v_31175;
    v_31176 = qcdr(v_31176);
    goto v_31051;
v_31052:
    v_31175 = qcar(v_31175);
    goto v_31053;
v_31054:
    goto v_31048;
v_31049:
    goto v_31050;
v_31051:
    goto v_31052;
v_31053:
    v_31175 = list3(v_31177, v_31176, v_31175);
    env = stack[-7];
    goto v_31043;
v_31044:
    goto v_31038;
v_31039:
    goto v_31040;
v_31041:
    goto v_31042;
v_31043:
    v_31175 = list3(stack[0], stack[-3], v_31175);
    env = stack[-7];
    fn = elt(env, 5); // aeval
    v_31175 = (*qfn1(fn))(fn, v_31175);
    env = stack[-7];
    stack[-6] = v_31175;
    v_31175 = stack[-2];
    v_31175 = qcdr(v_31175);
    stack[-2] = v_31175;
    goto v_31025;
v_31024:
    v_31175 = stack[-1];
    stack[-3] = v_31175;
v_31065:
    v_31175 = stack[-3];
    if (v_31175 == nil) goto v_31069;
    else goto v_31070;
v_31069:
    goto v_31064;
v_31070:
    v_31175 = stack[-3];
    v_31175 = qcar(v_31175);
    goto v_31080;
v_31076:
    v_31176 = v_31175;
    v_31177 = qcdr(v_31176);
    goto v_31077;
v_31078:
    v_31176 = stack[-4];
    goto v_31079;
v_31080:
    goto v_31076;
v_31077:
    goto v_31078;
v_31079:
    v_31176 = Lassoc(nil, v_31177, v_31176);
    goto v_31090;
v_31086:
    stack[-2] = v_31176;
    goto v_31087;
v_31088:
    goto v_31100;
v_31094:
    stack[-1] = elt(env, 3); // difference
    goto v_31095;
v_31096:
    stack[0] = qcdr(v_31176);
    goto v_31097;
v_31098:
    goto v_31111;
v_31105:
    v_31177 = elt(env, 1); // times
    goto v_31106;
v_31107:
    v_31176 = stack[-6];
    goto v_31108;
v_31109:
    v_31175 = qcar(v_31175);
    goto v_31110;
v_31111:
    goto v_31105;
v_31106:
    goto v_31107;
v_31108:
    goto v_31109;
v_31110:
    v_31175 = list3(v_31177, v_31176, v_31175);
    env = stack[-7];
    goto v_31099;
v_31100:
    goto v_31094;
v_31095:
    goto v_31096;
v_31097:
    goto v_31098;
v_31099:
    v_31175 = list3(stack[-1], stack[0], v_31175);
    env = stack[-7];
    fn = elt(env, 6); // reval
    v_31175 = (*qfn1(fn))(fn, v_31175);
    env = stack[-7];
    goto v_31089;
v_31090:
    goto v_31086;
v_31087:
    goto v_31088;
v_31089:
    v_31175 = Lrplacd(nil, stack[-2], v_31175);
    env = stack[-7];
    v_31175 = stack[-3];
    v_31175 = qcdr(v_31175);
    stack[-3] = v_31175;
    goto v_31065;
v_31064:
    v_31175 = stack[-5];
    stack[-3] = v_31175;
v_31121:
    v_31175 = stack[-3];
    if (v_31175 == nil) goto v_31125;
    else goto v_31126;
v_31125:
    goto v_31120;
v_31126:
    v_31175 = stack[-3];
    v_31175 = qcar(v_31175);
    goto v_31136;
v_31132:
    v_31176 = v_31175;
    v_31177 = qcdr(v_31176);
    goto v_31133;
v_31134:
    v_31176 = stack[-4];
    goto v_31135;
v_31136:
    goto v_31132;
v_31133:
    goto v_31134;
v_31135:
    v_31176 = Lassoc(nil, v_31177, v_31176);
    goto v_31146;
v_31142:
    stack[-2] = v_31176;
    goto v_31143;
v_31144:
    goto v_31156;
v_31150:
    stack[-1] = elt(env, 4); // plus
    goto v_31151;
v_31152:
    stack[0] = qcdr(v_31176);
    goto v_31153;
v_31154:
    goto v_31167;
v_31161:
    v_31177 = elt(env, 1); // times
    goto v_31162;
v_31163:
    v_31176 = stack[-6];
    goto v_31164;
v_31165:
    v_31175 = qcar(v_31175);
    goto v_31166;
v_31167:
    goto v_31161;
v_31162:
    goto v_31163;
v_31164:
    goto v_31165;
v_31166:
    v_31175 = list3(v_31177, v_31176, v_31175);
    env = stack[-7];
    goto v_31155;
v_31156:
    goto v_31150;
v_31151:
    goto v_31152;
v_31153:
    goto v_31154;
v_31155:
    v_31175 = list3(stack[-1], stack[0], v_31175);
    env = stack[-7];
    fn = elt(env, 6); // reval
    v_31175 = (*qfn1(fn))(fn, v_31175);
    env = stack[-7];
    goto v_31145;
v_31146:
    goto v_31142;
v_31143:
    goto v_31144;
v_31145:
    v_31175 = Lrplacd(nil, stack[-2], v_31175);
    env = stack[-7];
    v_31175 = stack[-3];
    v_31175 = qcdr(v_31175);
    stack[-3] = v_31175;
    goto v_31121;
v_31120:
    v_31175 = stack[-4];
    return onevalue(v_31175);
}



// Code for rand!-mons!-sparse

static LispObject CC_randKmonsKsparse(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31351, v_31352;
    LispObject fn;
    LispObject v_31017, v_31016, v_31015, v_31014, v_31013;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "rand-mons-sparse");
    va_start(aa, nargs);
    v_31013 = va_arg(aa, LispObject);
    v_31014 = va_arg(aa, LispObject);
    v_31015 = va_arg(aa, LispObject);
    v_31016 = va_arg(aa, LispObject);
    v_31017 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_31017,v_31016,v_31015,v_31014,v_31013);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_31013,v_31014,v_31015,v_31016,v_31017);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[0] = v_31017;
    stack[-2] = v_31016;
    v_31351 = v_31015;
    stack[-1] = v_31014;
    stack[-9] = v_31013;
// end of prologue
// Binding d
// FLUIDBIND: reloadenv=11 litvec-offset=1 saveloc=10
{   bind_fluid_stack bind_fluid_var(-11, 1, -10);
    qvalue(elt(env, 1)) = v_31351; // d
    stack[-8] = nil;
    stack[-7] = nil;
    v_31351 = stack[0];
    if (v_31351 == nil) goto v_31033;
    goto v_31040;
v_31036:
    stack[-3] = qvalue(elt(env, 1)); // d
    goto v_31037;
v_31038:
    goto v_31047;
v_31043:
    v_31352 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31044;
v_31045:
    v_31351 = stack[-2];
    goto v_31046;
v_31047:
    goto v_31043;
v_31044:
    goto v_31045;
v_31046:
    v_31351 = difference2(v_31352, v_31351);
    env = stack[-11];
    goto v_31039;
v_31040:
    goto v_31036;
v_31037:
    goto v_31038;
v_31039:
    v_31351 = plus2(stack[-3], v_31351);
    env = stack[-11];
    goto v_31031;
v_31033:
    v_31351 = stack[-9];
    v_31351 = Llength(nil, v_31351);
    env = stack[-11];
    stack[-8] = v_31351;
    v_31351 = stack[-2];
    v_31351 = (LispObject)zerop(v_31351);
    v_31351 = v_31351 ? lisp_true : nil;
    env = stack[-11];
    if (v_31351 == nil) goto v_31059;
    v_31351 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31057;
v_31059:
    goto v_31070;
v_31066:
    goto v_31076;
v_31072:
    stack[-3] = stack[-8];
    goto v_31073;
v_31074:
    v_31351 = stack[-2];
    v_31351 = sub1(v_31351);
    env = stack[-11];
    goto v_31075;
v_31076:
    goto v_31072;
v_31073:
    goto v_31074;
v_31075:
    v_31352 = plus2(stack[-3], v_31351);
    env = stack[-11];
    goto v_31067;
v_31068:
    v_31351 = stack[-8];
    goto v_31069;
v_31070:
    goto v_31066;
v_31067:
    goto v_31068;
v_31069:
    fn = elt(env, 2); // binomial
    v_31351 = (*qfn2(fn))(fn, v_31352, v_31351);
    env = stack[-11];
    goto v_31057;
    v_31351 = nil;
v_31057:
    stack[-7] = v_31351;
    goto v_31086;
v_31082:
    goto v_31092;
v_31088:
    goto v_31098;
v_31094:
    v_31352 = stack[-8];
    goto v_31095;
v_31096:
    v_31351 = qvalue(elt(env, 1)); // d
    goto v_31097;
v_31098:
    goto v_31094;
v_31095:
    goto v_31096;
v_31097:
    v_31352 = plus2(v_31352, v_31351);
    env = stack[-11];
    goto v_31089;
v_31090:
    v_31351 = stack[-8];
    goto v_31091;
v_31092:
    goto v_31088;
v_31089:
    goto v_31090;
v_31091:
    fn = elt(env, 2); // binomial
    v_31352 = (*qfn2(fn))(fn, v_31352, v_31351);
    env = stack[-11];
    goto v_31083;
v_31084:
    v_31351 = stack[-7];
    goto v_31085;
v_31086:
    goto v_31082;
v_31083:
    goto v_31084;
v_31085:
    v_31351 = difference2(v_31352, v_31351);
    env = stack[-11];
    goto v_31031;
v_31031:
    goto v_31108;
v_31104:
    stack[-3] = v_31351;
    goto v_31105;
v_31106:
    goto v_31115;
v_31111:
    v_31352 = v_31351;
    goto v_31112;
v_31113:
    v_31351 = stack[-1];
    goto v_31114;
v_31115:
    goto v_31111;
v_31112:
    goto v_31113;
v_31114:
    fn = elt(env, 3); // min
    v_31351 = (*qfn2(fn))(fn, v_31352, v_31351);
    env = stack[-11];
    goto v_31107;
v_31108:
    goto v_31104;
v_31105:
    goto v_31106;
v_31107:
    fn = elt(env, 4); // rand!-comb
    v_31351 = (*qfn2(fn))(fn, stack[-3], v_31351);
    env = stack[-11];
    v_31352 = v_31351;
    v_31351 = stack[0];
    if (v_31351 == nil) goto v_31121;
    v_31351 = v_31352;
    stack[-5] = v_31351;
    v_31351 = stack[-5];
    if (v_31351 == nil) goto v_31132;
    else goto v_31133;
v_31132:
    v_31351 = nil;
    goto v_31127;
v_31133:
    v_31351 = stack[-5];
    v_31351 = qcar(v_31351);
    goto v_31145;
v_31141:
    stack[0] = stack[-9];
    goto v_31142;
v_31143:
    goto v_31152;
v_31148:
    v_31352 = v_31351;
    goto v_31149;
v_31150:
    v_31351 = stack[-2];
    goto v_31151;
v_31152:
    goto v_31148;
v_31149:
    goto v_31150;
v_31151:
    v_31351 = plus2(v_31352, v_31351);
    env = stack[-11];
    goto v_31144;
v_31145:
    goto v_31141;
v_31142:
    goto v_31143;
v_31144:
    fn = elt(env, 5); // !*kp2f
    v_31351 = (*qfn2(fn))(fn, stack[0], v_31351);
    env = stack[-11];
    v_31351 = ncons(v_31351);
    env = stack[-11];
    stack[-3] = v_31351;
    stack[-4] = v_31351;
v_31128:
    v_31351 = stack[-5];
    v_31351 = qcdr(v_31351);
    stack[-5] = v_31351;
    v_31351 = stack[-5];
    if (v_31351 == nil) goto v_31159;
    else goto v_31160;
v_31159:
    v_31351 = stack[-4];
    goto v_31127;
v_31160:
    goto v_31168;
v_31164:
    stack[-1] = stack[-3];
    goto v_31165;
v_31166:
    v_31351 = stack[-5];
    v_31351 = qcar(v_31351);
    goto v_31179;
v_31175:
    stack[0] = stack[-9];
    goto v_31176;
v_31177:
    goto v_31186;
v_31182:
    v_31352 = v_31351;
    goto v_31183;
v_31184:
    v_31351 = stack[-2];
    goto v_31185;
v_31186:
    goto v_31182;
v_31183:
    goto v_31184;
v_31185:
    v_31351 = plus2(v_31352, v_31351);
    env = stack[-11];
    goto v_31178;
v_31179:
    goto v_31175;
v_31176:
    goto v_31177;
v_31178:
    fn = elt(env, 5); // !*kp2f
    v_31351 = (*qfn2(fn))(fn, stack[0], v_31351);
    env = stack[-11];
    v_31351 = ncons(v_31351);
    env = stack[-11];
    goto v_31167;
v_31168:
    goto v_31164;
v_31165:
    goto v_31166;
v_31167:
    v_31351 = Lrplacd(nil, stack[-1], v_31351);
    env = stack[-11];
    v_31351 = stack[-3];
    v_31351 = qcdr(v_31351);
    stack[-3] = v_31351;
    goto v_31128;
v_31127:
    goto v_31119;
v_31121:
    v_31351 = v_31352;
    stack[-6] = v_31351;
    v_31351 = stack[-6];
    if (v_31351 == nil) goto v_31202;
    else goto v_31203;
v_31202:
    v_31351 = nil;
    goto v_31197;
v_31203:
    v_31351 = stack[-6];
    v_31351 = qcar(v_31351);
    stack[-2] = v_31351;
    v_31351 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_31351;
    goto v_31219;
v_31215:
    stack[0] = nil;
    goto v_31216;
v_31217:
    goto v_31226;
v_31222:
    goto v_31232;
v_31228:
    v_31352 = stack[-2];
    goto v_31229;
v_31230:
    v_31351 = stack[-7];
    goto v_31231;
v_31232:
    goto v_31228;
v_31229:
    goto v_31230;
v_31231:
    v_31352 = plus2(v_31352, v_31351);
    env = stack[-11];
    goto v_31223;
v_31224:
    v_31351 = stack[-8];
    goto v_31225;
v_31226:
    goto v_31222;
v_31223:
    goto v_31224;
v_31225:
    fn = elt(env, 6); // inttovec
    v_31351 = (*qfn2(fn))(fn, v_31352, v_31351);
    env = stack[-11];
    goto v_31218;
v_31219:
    goto v_31215;
v_31216:
    goto v_31217;
v_31218:
    v_31351 = cons(stack[0], v_31351);
    env = stack[-11];
    stack[-2] = v_31351;
    v_31351 = stack[-9];
    stack[0] = v_31351;
v_31239:
    v_31351 = stack[0];
    if (v_31351 == nil) goto v_31243;
    else goto v_31244;
v_31243:
    goto v_31238;
v_31244:
    v_31351 = stack[0];
    v_31351 = qcar(v_31351);
    goto v_31255;
v_31251:
    goto v_31261;
v_31257:
    v_31352 = v_31351;
    goto v_31258;
v_31259:
    v_31351 = stack[-2];
    v_31351 = qcdr(v_31351);
    stack[-2] = v_31351;
    v_31351 = qcar(v_31351);
    goto v_31260;
v_31261:
    goto v_31257;
v_31258:
    goto v_31259;
v_31260:
    fn = elt(env, 5); // !*kp2f
    v_31352 = (*qfn2(fn))(fn, v_31352, v_31351);
    env = stack[-11];
    goto v_31252;
v_31253:
    v_31351 = stack[-1];
    goto v_31254;
v_31255:
    goto v_31251;
v_31252:
    goto v_31253;
v_31254:
    fn = elt(env, 7); // multf
    v_31351 = (*qfn2(fn))(fn, v_31352, v_31351);
    env = stack[-11];
    stack[-1] = v_31351;
    v_31351 = stack[0];
    v_31351 = qcdr(v_31351);
    stack[0] = v_31351;
    goto v_31239;
v_31238:
    v_31351 = stack[-1];
    v_31351 = ncons(v_31351);
    env = stack[-11];
    stack[-4] = v_31351;
    stack[-5] = v_31351;
v_31198:
    v_31351 = stack[-6];
    v_31351 = qcdr(v_31351);
    stack[-6] = v_31351;
    v_31351 = stack[-6];
    if (v_31351 == nil) goto v_31274;
    else goto v_31275;
v_31274:
    v_31351 = stack[-5];
    goto v_31197;
v_31275:
    goto v_31283;
v_31279:
    stack[-3] = stack[-4];
    goto v_31280;
v_31281:
    v_31351 = stack[-6];
    v_31351 = qcar(v_31351);
    stack[-2] = v_31351;
    v_31351 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_31351;
    goto v_31298;
v_31294:
    stack[0] = nil;
    goto v_31295;
v_31296:
    goto v_31305;
v_31301:
    goto v_31311;
v_31307:
    v_31352 = stack[-2];
    goto v_31308;
v_31309:
    v_31351 = stack[-7];
    goto v_31310;
v_31311:
    goto v_31307;
v_31308:
    goto v_31309;
v_31310:
    v_31352 = plus2(v_31352, v_31351);
    env = stack[-11];
    goto v_31302;
v_31303:
    v_31351 = stack[-8];
    goto v_31304;
v_31305:
    goto v_31301;
v_31302:
    goto v_31303;
v_31304:
    fn = elt(env, 6); // inttovec
    v_31351 = (*qfn2(fn))(fn, v_31352, v_31351);
    env = stack[-11];
    goto v_31297;
v_31298:
    goto v_31294;
v_31295:
    goto v_31296;
v_31297:
    v_31351 = cons(stack[0], v_31351);
    env = stack[-11];
    stack[-2] = v_31351;
    v_31351 = stack[-9];
    stack[0] = v_31351;
v_31318:
    v_31351 = stack[0];
    if (v_31351 == nil) goto v_31322;
    else goto v_31323;
v_31322:
    goto v_31317;
v_31323:
    v_31351 = stack[0];
    v_31351 = qcar(v_31351);
    goto v_31334;
v_31330:
    goto v_31340;
v_31336:
    v_31352 = v_31351;
    goto v_31337;
v_31338:
    v_31351 = stack[-2];
    v_31351 = qcdr(v_31351);
    stack[-2] = v_31351;
    v_31351 = qcar(v_31351);
    goto v_31339;
v_31340:
    goto v_31336;
v_31337:
    goto v_31338;
v_31339:
    fn = elt(env, 5); // !*kp2f
    v_31352 = (*qfn2(fn))(fn, v_31352, v_31351);
    env = stack[-11];
    goto v_31331;
v_31332:
    v_31351 = stack[-1];
    goto v_31333;
v_31334:
    goto v_31330;
v_31331:
    goto v_31332;
v_31333:
    fn = elt(env, 7); // multf
    v_31351 = (*qfn2(fn))(fn, v_31352, v_31351);
    env = stack[-11];
    stack[-1] = v_31351;
    v_31351 = stack[0];
    v_31351 = qcdr(v_31351);
    stack[0] = v_31351;
    goto v_31318;
v_31317:
    v_31351 = stack[-1];
    v_31351 = ncons(v_31351);
    env = stack[-11];
    goto v_31282;
v_31283:
    goto v_31279;
v_31280:
    goto v_31281;
v_31282:
    v_31351 = Lrplacd(nil, stack[-3], v_31351);
    env = stack[-11];
    v_31351 = stack[-4];
    v_31351 = qcdr(v_31351);
    stack[-4] = v_31351;
    goto v_31198;
v_31197:
    goto v_31119;
    v_31351 = nil;
v_31119:
    ;}  // end of a binding scope
    return onevalue(v_31351);
}



// Code for redassignp

static LispObject CC_redassignp(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31034, v_31035, v_31036;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31036 = v_31012;
// end of prologue
    goto v_31023;
v_31019:
    v_31035 = v_31036;
    goto v_31020;
v_31021:
    v_31034 = elt(env, 1); // setq
    goto v_31022;
v_31023:
    goto v_31019;
v_31020:
    goto v_31021;
v_31022:
    if (!consp(v_31035)) goto v_31017;
    v_31035 = qcar(v_31035);
    if (v_31035 == v_31034) goto v_31016;
    else goto v_31017;
v_31016:
    v_31034 = v_31036;
    v_31034 = qcdr(v_31034);
    v_31034 = qcdr(v_31034);
    v_31034 = qcar(v_31034);
    {
        fn = elt(env, 2); // redassign1p
        return (*qfn1(fn))(fn, v_31034);
    }
v_31017:
    v_31034 = nil;
    goto v_31015;
    v_31034 = nil;
v_31015:
    return onevalue(v_31034);
}



// Code for coeff1_calc

static LispObject CC_coeff1_calc(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31057, v_31058, v_31059;
    LispObject fn;
    LispObject v_31014, v_31013, v_31012;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "coeff1_calc");
    va_start(aa, nargs);
    v_31012 = va_arg(aa, LispObject);
    v_31013 = va_arg(aa, LispObject);
    v_31014 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31014,v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31012,v_31013,v_31014);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_31014;
    stack[-1] = v_31013;
    stack[-2] = v_31012;
// end of prologue
    stack[-3] = nil;
v_31019:
    v_31057 = stack[0];
    if (v_31057 == nil) goto v_31022;
    else goto v_31023;
v_31022:
    goto v_31030;
v_31026:
    stack[0] = stack[-3];
    goto v_31027;
v_31028:
    v_31057 = (LispObject)0+TAG_FIXNUM; // 0
    v_31057 = ncons(v_31057);
    env = stack[-4];
    goto v_31029;
v_31030:
    goto v_31026;
v_31027:
    goto v_31028;
v_31029:
    {
        LispObject v_31064 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_31064, v_31057);
    }
v_31023:
    goto v_31041;
v_31037:
    goto v_31049;
v_31043:
    v_31059 = stack[-2];
    goto v_31044;
v_31045:
    v_31058 = stack[-1];
    goto v_31046;
v_31047:
    v_31057 = stack[0];
    v_31057 = qcar(v_31057);
    goto v_31048;
v_31049:
    goto v_31043;
v_31044:
    goto v_31045;
v_31046:
    goto v_31047;
v_31048:
    fn = elt(env, 2); // calc_coeffmap_
    v_31058 = (*qfnn(fn))(fn, 3, v_31059, v_31058, v_31057);
    env = stack[-4];
    goto v_31038;
v_31039:
    v_31057 = stack[-3];
    goto v_31040;
v_31041:
    goto v_31037;
v_31038:
    goto v_31039;
v_31040:
    v_31057 = cons(v_31058, v_31057);
    env = stack[-4];
    stack[-3] = v_31057;
    v_31057 = stack[0];
    v_31057 = qcdr(v_31057);
    stack[0] = v_31057;
    goto v_31019;
    v_31057 = nil;
    return onevalue(v_31057);
}



// Code for clogsq

static LispObject CC_clogsq(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31026;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31012);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31012;
// end of prologue
    goto v_31019;
v_31015:
    v_31026 = stack[0];
    v_31026 = qcar(v_31026);
    fn = elt(env, 1); // clogf
    stack[-1] = (*qfn1(fn))(fn, v_31026);
    env = stack[-2];
    goto v_31016;
v_31017:
    v_31026 = stack[0];
    v_31026 = qcdr(v_31026);
    fn = elt(env, 1); // clogf
    v_31026 = (*qfn1(fn))(fn, v_31026);
    goto v_31018;
v_31019:
    goto v_31015;
v_31016:
    goto v_31017;
v_31018:
    {
        LispObject v_31029 = stack[-1];
        return cons(v_31029, v_31026);
    }
}



// Code for dp_2a

static LispObject CC_dp_2a(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31025, v_31026;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31012);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31026 = v_31012;
// end of prologue
    v_31025 = v_31026;
    if (v_31025 == nil) goto v_31016;
    else goto v_31017;
v_31016:
    v_31025 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31015;
v_31017:
    v_31025 = v_31026;
    fn = elt(env, 1); // dp!=2a
    v_31025 = (*qfn1(fn))(fn, v_31025);
    env = stack[0];
    {
        fn = elt(env, 2); // dp!=replus
        return (*qfn1(fn))(fn, v_31025);
    }
    v_31025 = nil;
v_31015:
    return onevalue(v_31025);
}



// Code for mod!/

static LispObject CC_modV(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31043, v_31044, v_31045, v_31046;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31012,v_31013);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31043 = v_31013;
    v_31044 = v_31012;
// end of prologue
    goto v_31020;
v_31016:
    goto v_31026;
v_31022:
    stack[0] = v_31044;
    goto v_31023;
v_31024:
    goto v_31037;
v_31029:
    v_31046 = qvalue(elt(env, 1)); // current!-modulus
    goto v_31030;
v_31031:
    v_31045 = v_31043;
    goto v_31032;
v_31033:
    v_31044 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31034;
v_31035:
    v_31043 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31036;
v_31037:
    goto v_31029;
v_31030:
    goto v_31031;
v_31032:
    goto v_31033;
v_31034:
    goto v_31035;
v_31036:
    fn = elt(env, 2); // general!-reciprocal!-by!-gcd
    v_31043 = (*qfnn(fn))(fn, 4, v_31046, v_31045, v_31044, v_31043);
    env = stack[-1];
    goto v_31025;
v_31026:
    goto v_31022;
v_31023:
    goto v_31024;
v_31025:
    v_31043 = times2(stack[0], v_31043);
    env = stack[-1];
    goto v_31017;
v_31018:
    v_31044 = qvalue(elt(env, 1)); // current!-modulus
    goto v_31019;
v_31020:
    goto v_31016;
v_31017:
    goto v_31018;
v_31019:
    return Cremainder(v_31043, v_31044);
}



// Code for cde_alglistp

static LispObject CC_cde_alglistp(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31032, v_31033;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31012);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_31012;
// end of prologue
    v_31032 = stack[0];
    fn = elt(env, 2); // listp
    v_31032 = (*qfn1(fn))(fn, v_31032);
    env = stack[-1];
    if (v_31032 == nil) goto v_31016;
    else goto v_31017;
v_31016:
    v_31032 = nil;
    goto v_31015;
v_31017:
    goto v_31027;
v_31023:
    v_31032 = stack[0];
    v_31032 = qcar(v_31032);
    goto v_31024;
v_31025:
    v_31033 = elt(env, 1); // list
    goto v_31026;
v_31027:
    goto v_31023;
v_31024:
    goto v_31025;
v_31026:
    v_31032 = (v_31032 == v_31033 ? lisp_true : nil);
    goto v_31015;
    v_31032 = nil;
v_31015:
    return onevalue(v_31032);
}



// Code for ofsf_sminsert

static LispObject CC_ofsf_sminsert(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31227, v_31228, v_31229, v_31230, v_31231;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31012,v_31013);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_31013;
    stack[-4] = v_31012;
// end of prologue
    stack[-5] = nil;
v_31023:
    goto v_31035;
v_31025:
    v_31227 = stack[-3];
    v_31227 = qcar(v_31227);
    v_31227 = qcdr(v_31227);
    v_31231 = qcar(v_31227);
    goto v_31026;
v_31027:
    v_31227 = stack[-3];
    v_31227 = qcar(v_31227);
    v_31227 = qcdr(v_31227);
    v_31230 = qcdr(v_31227);
    goto v_31028;
v_31029:
    v_31227 = stack[-4];
    v_31227 = qcdr(v_31227);
    v_31229 = qcar(v_31227);
    goto v_31030;
v_31031:
    v_31227 = stack[-4];
    v_31227 = qcdr(v_31227);
    v_31228 = qcdr(v_31227);
    goto v_31032;
v_31033:
    v_31227 = stack[-4];
    v_31227 = qcar(v_31227);
    goto v_31034;
v_31035:
    goto v_31025;
v_31026:
    goto v_31027;
v_31028:
    goto v_31029;
v_31030:
    goto v_31031;
v_31032:
    goto v_31033;
v_31034:
    fn = elt(env, 3); // ofsf_sminsert1
    v_31227 = (*qfnn(fn))(fn, 5, v_31231, v_31230, v_31229, v_31228, v_31227);
    env = stack[-6];
    stack[-2] = v_31227;
    v_31227 = stack[-2];
    if (v_31227 == nil) goto v_31055;
    v_31227 = stack[-2];
    if (symbolp(v_31227)) goto v_31055;
    v_31227 = stack[-3];
    v_31227 = qcdr(v_31227);
    stack[-3] = v_31227;
    v_31227 = stack[-2];
    stack[-4] = v_31227;
    goto v_31053;
v_31055:
v_31053:
    v_31227 = stack[-2];
    if (v_31227 == nil) goto v_31069;
    else goto v_31070;
v_31069:
    v_31227 = lisp_true;
    goto v_31068;
v_31070:
    v_31227 = stack[-2];
    v_31227 = Lsymbolp(nil, v_31227);
    env = stack[-6];
    if (v_31227 == nil) goto v_31077;
    else goto v_31076;
v_31077:
    v_31227 = stack[-3];
    v_31227 = (v_31227 == nil ? lisp_true : nil);
v_31076:
    goto v_31068;
    v_31227 = nil;
v_31068:
    if (v_31227 == nil) goto v_31065;
    else goto v_31066;
v_31065:
    goto v_31023;
v_31066:
    goto v_31090;
v_31086:
    v_31228 = stack[-2];
    goto v_31087;
v_31088:
    v_31227 = elt(env, 1); // false
    goto v_31089;
v_31090:
    goto v_31086;
v_31087:
    goto v_31088;
v_31089:
    if (v_31228 == v_31227) goto v_31084;
    else goto v_31085;
v_31084:
    v_31227 = elt(env, 1); // false
    goto v_31020;
v_31085:
    goto v_31102;
v_31098:
    v_31228 = stack[-2];
    goto v_31099;
v_31100:
    v_31227 = elt(env, 2); // true
    goto v_31101;
v_31102:
    goto v_31098;
v_31099:
    goto v_31100;
v_31101:
    if (v_31228 == v_31227) goto v_31096;
    else goto v_31097;
v_31096:
    v_31227 = stack[-3];
    goto v_31020;
v_31097:
    v_31227 = stack[-3];
    if (v_31227 == nil) goto v_31108;
    else goto v_31109;
v_31108:
    v_31227 = stack[-4];
    return ncons(v_31227);
v_31109:
    v_31227 = stack[-3];
    stack[0] = v_31227;
    v_31227 = stack[-3];
    v_31227 = qcdr(v_31227);
    stack[-1] = v_31227;
v_31118:
    v_31227 = stack[-1];
    if (v_31227 == nil) goto v_31121;
    else goto v_31122;
v_31121:
    goto v_31117;
v_31122:
    v_31227 = stack[-1];
    v_31227 = qcar(v_31227);
    stack[-5] = v_31227;
    v_31227 = stack[-1];
    v_31227 = qcdr(v_31227);
    stack[-1] = v_31227;
    goto v_31140;
v_31130:
    v_31227 = stack[-5];
    v_31227 = qcdr(v_31227);
    v_31231 = qcar(v_31227);
    goto v_31131;
v_31132:
    v_31227 = stack[-5];
    v_31227 = qcdr(v_31227);
    v_31230 = qcdr(v_31227);
    goto v_31133;
v_31134:
    v_31227 = stack[-4];
    v_31227 = qcdr(v_31227);
    v_31229 = qcar(v_31227);
    goto v_31135;
v_31136:
    v_31227 = stack[-4];
    v_31227 = qcdr(v_31227);
    v_31228 = qcdr(v_31227);
    goto v_31137;
v_31138:
    v_31227 = stack[-4];
    v_31227 = qcar(v_31227);
    goto v_31139;
v_31140:
    goto v_31130;
v_31131:
    goto v_31132;
v_31133:
    goto v_31134;
v_31135:
    goto v_31136;
v_31137:
    goto v_31138;
v_31139:
    fn = elt(env, 3); // ofsf_sminsert1
    v_31227 = (*qfnn(fn))(fn, 5, v_31231, v_31230, v_31229, v_31228, v_31227);
    env = stack[-6];
    stack[-2] = v_31227;
    goto v_31163;
v_31159:
    v_31228 = stack[-2];
    goto v_31160;
v_31161:
    v_31227 = elt(env, 2); // true
    goto v_31162;
v_31163:
    goto v_31159;
v_31160:
    goto v_31161;
v_31162:
    if (v_31228 == v_31227) goto v_31157;
    else goto v_31158;
v_31157:
    v_31227 = nil;
    stack[-1] = v_31227;
    v_31227 = elt(env, 2); // true
    stack[-5] = v_31227;
    goto v_31156;
v_31158:
    goto v_31174;
v_31170:
    v_31228 = stack[-2];
    goto v_31171;
v_31172:
    v_31227 = elt(env, 1); // false
    goto v_31173;
v_31174:
    goto v_31170;
v_31171:
    goto v_31172;
v_31173:
    if (v_31228 == v_31227) goto v_31168;
    else goto v_31169;
v_31168:
    v_31227 = nil;
    stack[-1] = v_31227;
    v_31227 = elt(env, 1); // false
    stack[-5] = v_31227;
    goto v_31156;
v_31169:
    v_31227 = stack[-2];
    if (v_31227 == nil) goto v_31180;
    goto v_31187;
v_31183:
    v_31228 = stack[0];
    goto v_31184;
v_31185:
    v_31227 = stack[-1];
    goto v_31186;
v_31187:
    goto v_31183;
v_31184:
    goto v_31185;
v_31186:
    fn = elt(env, 4); // setcdr
    v_31227 = (*qfn2(fn))(fn, v_31228, v_31227);
    env = stack[-6];
    v_31227 = stack[-2];
    stack[-4] = v_31227;
    goto v_31156;
v_31180:
    v_31227 = stack[0];
    v_31227 = qcdr(v_31227);
    stack[0] = v_31227;
    goto v_31156;
v_31156:
    goto v_31118;
v_31117:
    goto v_31203;
v_31199:
    v_31228 = stack[-5];
    goto v_31200;
v_31201:
    v_31227 = elt(env, 1); // false
    goto v_31202;
v_31203:
    goto v_31199;
v_31200:
    goto v_31201;
v_31202:
    if (v_31228 == v_31227) goto v_31197;
    else goto v_31198;
v_31197:
    v_31227 = elt(env, 1); // false
    goto v_31020;
v_31198:
    goto v_31215;
v_31211:
    v_31227 = stack[-5];
    goto v_31212;
v_31213:
    v_31228 = elt(env, 2); // true
    goto v_31214;
v_31215:
    goto v_31211;
v_31212:
    goto v_31213;
v_31214:
    if (v_31227 == v_31228) goto v_31209;
    else goto v_31210;
v_31209:
    v_31227 = stack[-3];
    goto v_31020;
v_31210:
    goto v_31224;
v_31220:
    v_31228 = stack[-4];
    goto v_31221;
v_31222:
    v_31227 = stack[-3];
    goto v_31223;
v_31224:
    goto v_31220;
v_31221:
    goto v_31222;
v_31223:
    return cons(v_31228, v_31227);
v_31020:
    return onevalue(v_31227);
}



// Code for addfactors

static LispObject CC_addfactors(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31077, v_31078, v_31079, v_31080;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31012,v_31013);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_31079 = v_31013;
    v_31080 = v_31012;
// end of prologue
    goto v_31023;
v_31019:
    v_31078 = v_31080;
    goto v_31020;
v_31021:
    v_31077 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31022;
v_31023:
    goto v_31019;
v_31020:
    goto v_31021;
v_31022:
    if (v_31078 == v_31077) goto v_31017;
    else goto v_31018;
v_31017:
    v_31077 = v_31079;
    {
        fn = elt(env, 2); // prepf
        return (*qfn1(fn))(fn, v_31077);
    }
v_31018:
    goto v_31034;
v_31030:
    v_31078 = v_31079;
    goto v_31031;
v_31032:
    v_31077 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31033;
v_31034:
    goto v_31030;
v_31031:
    goto v_31032;
v_31033:
    if (v_31078 == v_31077) goto v_31028;
    else goto v_31029;
v_31028:
    v_31077 = v_31080;
    goto v_31016;
v_31029:
    goto v_31045;
v_31041:
    v_31078 = v_31080;
    goto v_31042;
v_31043:
    v_31077 = elt(env, 1); // times
    goto v_31044;
v_31045:
    goto v_31041;
v_31042:
    goto v_31043;
v_31044:
    if (!consp(v_31078)) goto v_31039;
    v_31078 = qcar(v_31078);
    if (v_31078 == v_31077) goto v_31038;
    else goto v_31039;
v_31038:
    goto v_31053;
v_31049:
    stack[-1] = elt(env, 1); // times
    goto v_31050;
v_31051:
    goto v_31060;
v_31056:
    v_31077 = v_31080;
    stack[0] = qcdr(v_31077);
    goto v_31057;
v_31058:
    v_31077 = v_31079;
    fn = elt(env, 2); // prepf
    v_31077 = (*qfn1(fn))(fn, v_31077);
    env = stack[-2];
    goto v_31059;
v_31060:
    goto v_31056;
v_31057:
    goto v_31058;
v_31059:
    fn = elt(env, 3); // aconc!*
    v_31077 = (*qfn2(fn))(fn, stack[0], v_31077);
    goto v_31052;
v_31053:
    goto v_31049;
v_31050:
    goto v_31051;
v_31052:
    {
        LispObject v_31083 = stack[-1];
        return cons(v_31083, v_31077);
    }
v_31039:
    goto v_31073;
v_31069:
    stack[0] = v_31080;
    goto v_31070;
v_31071:
    v_31077 = v_31079;
    fn = elt(env, 2); // prepf
    v_31077 = (*qfn1(fn))(fn, v_31077);
    env = stack[-2];
    goto v_31072;
v_31073:
    goto v_31069;
v_31070:
    goto v_31071;
v_31072:
    v_31077 = list2(stack[0], v_31077);
    env = stack[-2];
    {
        fn = elt(env, 4); // retimes
        return (*qfn1(fn))(fn, v_31077);
    }
    v_31077 = nil;
v_31016:
    return onevalue(v_31077);
}



// Code for subdf

static LispObject CC_subdf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31123, v_31124, v_31125;
    LispObject fn;
    LispObject v_31014, v_31013, v_31012;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "subdf");
    va_start(aa, nargs);
    v_31012 = va_arg(aa, LispObject);
    v_31013 = va_arg(aa, LispObject);
    v_31014 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31014,v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31012,v_31013,v_31014);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_31014;
    stack[-3] = v_31013;
    stack[-4] = v_31012;
// end of prologue
v_31011:
    v_31123 = stack[-4];
    if (v_31123 == nil) goto v_31018;
    else goto v_31019;
v_31018:
    v_31123 = nil;
    goto v_31017;
v_31019:
    goto v_31033;
v_31029:
    v_31123 = stack[-4];
    v_31123 = qcar(v_31123);
    v_31123 = qcdr(v_31123);
    stack[0] = qcar(v_31123);
    goto v_31030;
v_31031:
    goto v_31044;
v_31040:
    v_31124 = stack[-2];
    goto v_31041;
v_31042:
    v_31123 = stack[-3];
    goto v_31043;
v_31044:
    goto v_31040;
v_31041:
    goto v_31042;
v_31043:
    v_31123 = cons(v_31124, v_31123);
    env = stack[-6];
    v_31123 = ncons(v_31123);
    env = stack[-6];
    goto v_31032;
v_31033:
    goto v_31029;
v_31030:
    goto v_31031;
v_31032:
    fn = elt(env, 1); // subf
    v_31123 = (*qfn2(fn))(fn, stack[0], v_31123);
    env = stack[-6];
    fn = elt(env, 2); // subs2q
    v_31123 = (*qfn1(fn))(fn, v_31123);
    env = stack[-6];
    stack[-5] = v_31123;
    goto v_31055;
v_31051:
    stack[0] = stack[-5];
    goto v_31052;
v_31053:
    goto v_31062;
v_31058:
    v_31124 = nil;
    goto v_31059;
v_31060:
    v_31123 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31061;
v_31062:
    goto v_31058;
v_31059:
    goto v_31060;
v_31061:
    v_31123 = cons(v_31124, v_31123);
    env = stack[-6];
    goto v_31054;
v_31055:
    goto v_31051;
v_31052:
    goto v_31053;
v_31054:
    if (equal(stack[0], v_31123)) goto v_31049;
    else goto v_31050;
v_31049:
    goto v_31072;
v_31066:
    v_31123 = stack[-4];
    v_31125 = qcdr(v_31123);
    goto v_31067;
v_31068:
    v_31124 = stack[-3];
    goto v_31069;
v_31070:
    v_31123 = stack[-2];
    goto v_31071;
v_31072:
    goto v_31066;
v_31067:
    goto v_31068;
v_31069:
    goto v_31070;
v_31071:
    stack[-4] = v_31125;
    stack[-3] = v_31124;
    stack[-2] = v_31123;
    goto v_31011;
v_31050:
    goto v_31084;
v_31080:
    goto v_31093;
v_31087:
    v_31123 = stack[-4];
    v_31123 = qcar(v_31123);
    stack[-1] = qcar(v_31123);
    goto v_31088;
v_31089:
    v_31123 = stack[-5];
    stack[0] = qcar(v_31123);
    goto v_31090;
v_31091:
    goto v_31104;
v_31100:
    v_31123 = stack[-5];
    v_31124 = qcdr(v_31123);
    goto v_31101;
v_31102:
    v_31123 = stack[-4];
    v_31123 = qcar(v_31123);
    v_31123 = qcdr(v_31123);
    v_31123 = qcdr(v_31123);
    goto v_31103;
v_31104:
    goto v_31100;
v_31101:
    goto v_31102;
v_31103:
    fn = elt(env, 3); // !*multf
    v_31123 = (*qfn2(fn))(fn, v_31124, v_31123);
    env = stack[-6];
    goto v_31092;
v_31093:
    goto v_31087;
v_31088:
    goto v_31089;
v_31090:
    goto v_31091;
v_31092:
    v_31123 = list2star(stack[-1], stack[0], v_31123);
    env = stack[-6];
    stack[0] = ncons(v_31123);
    env = stack[-6];
    goto v_31081;
v_31082:
    goto v_31118;
v_31112:
    v_31123 = stack[-4];
    v_31125 = qcdr(v_31123);
    goto v_31113;
v_31114:
    v_31124 = stack[-3];
    goto v_31115;
v_31116:
    v_31123 = stack[-2];
    goto v_31117;
v_31118:
    goto v_31112;
v_31113:
    goto v_31114;
v_31115:
    goto v_31116;
v_31117:
    v_31123 = CC_subdf(elt(env, 0), 3, v_31125, v_31124, v_31123);
    env = stack[-6];
    goto v_31083;
v_31084:
    goto v_31080;
v_31081:
    goto v_31082;
v_31083:
    {
        LispObject v_31132 = stack[0];
        fn = elt(env, 4); // plusdf
        return (*qfn2(fn))(fn, v_31132, v_31123);
    }
    v_31123 = nil;
    goto v_31017;
    v_31123 = nil;
v_31017:
    return onevalue(v_31123);
}



// Code for cl_strict!-gdnf

static LispObject CC_cl_strictKgdnf(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31051, v_31052, v_31053;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31012,v_31013);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_31013;
    v_31051 = v_31012;
// end of prologue
    goto v_31023;
v_31019:
    goto v_31031;
v_31025:
    goto v_31037;
v_31033:
    v_31052 = v_31051;
    goto v_31034;
v_31035:
    v_31051 = stack[0];
    goto v_31036;
v_31037:
    goto v_31033;
v_31034:
    goto v_31035;
v_31036:
    fn = elt(env, 1); // cl_strict!-gdnf1
    v_31053 = (*qfn2(fn))(fn, v_31052, v_31051);
    env = stack[-1];
    goto v_31026;
v_31027:
    v_31052 = nil;
    goto v_31028;
v_31029:
    v_31051 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_31030;
v_31031:
    goto v_31025;
v_31026:
    goto v_31027;
v_31028:
    goto v_31029;
v_31030:
    fn = elt(env, 2); // rl_simpl
    v_31052 = (*qfnn(fn))(fn, 3, v_31053, v_31052, v_31051);
    env = stack[-1];
    goto v_31020;
v_31021:
    v_31051 = stack[0];
    goto v_31022;
v_31023:
    goto v_31019;
v_31020:
    goto v_31021;
v_31022:
    fn = elt(env, 3); // cl_mkstrict
    v_31051 = (*qfn2(fn))(fn, v_31052, v_31051);
    env = stack[-1];
    goto v_31048;
v_31044:
    v_31052 = v_31051;
    goto v_31045;
v_31046:
    v_31051 = stack[0];
    goto v_31047;
v_31048:
    goto v_31044;
v_31045:
    goto v_31046;
v_31047:
    {
        fn = elt(env, 4); // rl_bnfsimpl
        return (*qfn2(fn))(fn, v_31052, v_31051);
    }
    return onevalue(v_31051);
}



// Code for make!-image!-mod!-p

static LispObject CC_makeKimageKmodKp(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31054, v_31055;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31012,v_31013);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31013;
    stack[-1] = v_31012;
// end of prologue
    goto v_31023;
v_31019:
    v_31055 = stack[-1];
    goto v_31020;
v_31021:
    v_31054 = stack[0];
    goto v_31022;
v_31023:
    goto v_31019;
v_31020:
    goto v_31021;
v_31022:
    fn = elt(env, 2); // degree!-in!-variable
    v_31054 = (*qfn2(fn))(fn, v_31055, v_31054);
    env = stack[-3];
    stack[-2] = v_31054;
    goto v_31031;
v_31027:
    v_31055 = stack[-1];
    goto v_31028;
v_31029:
    v_31054 = stack[0];
    goto v_31030;
v_31031:
    goto v_31027;
v_31028:
    goto v_31029;
v_31030:
    fn = elt(env, 3); // make!-univariate!-image!-mod!-p
    v_31054 = (*qfn2(fn))(fn, v_31055, v_31054);
    env = stack[-3];
    stack[-1] = v_31054;
    goto v_31042;
v_31038:
    goto v_31048;
v_31044:
    v_31055 = stack[-1];
    goto v_31045;
v_31046:
    v_31054 = stack[0];
    goto v_31047;
v_31048:
    goto v_31044;
v_31045:
    goto v_31046;
v_31047:
    fn = elt(env, 2); // degree!-in!-variable
    v_31055 = (*qfn2(fn))(fn, v_31055, v_31054);
    env = stack[-3];
    goto v_31039;
v_31040:
    v_31054 = stack[-2];
    goto v_31041;
v_31042:
    goto v_31038;
v_31039:
    goto v_31040;
v_31041:
    if (equal(v_31055, v_31054)) goto v_31037;
    v_31054 = lisp_true;
    qvalue(elt(env, 1)) = v_31054; // unlucky!-case
    goto v_31035;
v_31037:
v_31035:
    v_31054 = stack[-1];
    return onevalue(v_31054);
}



// Code for getvariables

static LispObject CC_getvariables(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31031, v_31032;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31012);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31032 = v_31012;
// end of prologue
    goto v_31019;
v_31015:
    v_31031 = v_31032;
    stack[0] = qcar(v_31031);
    goto v_31016;
v_31017:
    goto v_31027;
v_31023:
    v_31031 = v_31032;
    v_31032 = qcdr(v_31031);
    goto v_31024;
v_31025:
    v_31031 = nil;
    goto v_31026;
v_31027:
    goto v_31023;
v_31024:
    goto v_31025;
v_31026:
    fn = elt(env, 1); // varsinsf
    v_31031 = (*qfn2(fn))(fn, v_31032, v_31031);
    env = stack[-1];
    goto v_31018;
v_31019:
    goto v_31015;
v_31016:
    goto v_31017;
v_31018:
    {
        LispObject v_31034 = stack[0];
        fn = elt(env, 1); // varsinsf
        return (*qfn2(fn))(fn, v_31034, v_31031);
    }
}



// Code for indordlp

static LispObject CC_indordlp(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31087, v_31088, v_31089, v_31090;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31088 = v_31013;
    v_31089 = v_31012;
// end of prologue
v_31017:
    v_31087 = v_31089;
    if (v_31087 == nil) goto v_31020;
    else goto v_31021;
v_31020:
    v_31087 = nil;
    goto v_31016;
v_31021:
    v_31087 = v_31088;
    if (v_31087 == nil) goto v_31024;
    else goto v_31025;
v_31024:
    v_31087 = lisp_true;
    goto v_31016;
v_31025:
    goto v_31034;
v_31030:
    v_31087 = v_31089;
    v_31090 = qcar(v_31087);
    goto v_31031;
v_31032:
    v_31087 = v_31088;
    v_31087 = qcar(v_31087);
    goto v_31033;
v_31034:
    goto v_31030;
v_31031:
    goto v_31032;
v_31033:
    if (equal(v_31090, v_31087)) goto v_31028;
    else goto v_31029;
v_31028:
    v_31087 = v_31089;
    v_31087 = qcdr(v_31087);
    v_31089 = v_31087;
    v_31087 = v_31088;
    v_31087 = qcdr(v_31087);
    v_31088 = v_31087;
    goto v_31017;
v_31029:
    v_31087 = v_31089;
    v_31087 = qcar(v_31087);
    if (!consp(v_31087)) goto v_31043;
    else goto v_31044;
v_31043:
    v_31087 = v_31088;
    v_31087 = qcar(v_31087);
    if (!consp(v_31087)) goto v_31049;
    else goto v_31050;
v_31049:
    goto v_31058;
v_31054:
    v_31087 = v_31089;
    v_31087 = qcar(v_31087);
    goto v_31055;
v_31056:
    v_31088 = qcar(v_31088);
    goto v_31057;
v_31058:
    goto v_31054;
v_31055:
    goto v_31056;
v_31057:
    {
        fn = elt(env, 1); // indordp
        return (*qfn2(fn))(fn, v_31087, v_31088);
    }
v_31050:
    v_31087 = lisp_true;
    goto v_31016;
    goto v_31019;
v_31044:
    v_31087 = v_31088;
    v_31087 = qcar(v_31087);
    if (!consp(v_31087)) goto v_31066;
    else goto v_31067;
v_31066:
    v_31087 = nil;
    goto v_31016;
v_31067:
    goto v_31078;
v_31074:
    v_31087 = v_31089;
    v_31087 = qcar(v_31087);
    v_31087 = qcdr(v_31087);
    v_31087 = qcar(v_31087);
    goto v_31075;
v_31076:
    v_31088 = qcar(v_31088);
    v_31088 = qcdr(v_31088);
    v_31088 = qcar(v_31088);
    goto v_31077;
v_31078:
    goto v_31074;
v_31075:
    goto v_31076;
v_31077:
    {
        fn = elt(env, 1); // indordp
        return (*qfn2(fn))(fn, v_31087, v_31088);
    }
v_31019:
    v_31087 = nil;
v_31016:
    return onevalue(v_31087);
}



// Code for adjp

static LispObject CC_adjp(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31112, v_31113;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31012);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_31012;
// end of prologue
    goto v_31022;
v_31018:
    v_31113 = stack[-1];
    goto v_31019;
v_31020:
    v_31112 = elt(env, 1); // unit
    goto v_31021;
v_31022:
    goto v_31018;
v_31019:
    goto v_31020;
v_31021:
    if (v_31113 == v_31112) goto v_31016;
    else goto v_31017;
v_31016:
    v_31112 = stack[-1];
    goto v_31015;
v_31017:
    v_31112 = stack[-1];
    if (!consp(v_31112)) goto v_31026;
    else goto v_31027;
v_31026:
    goto v_31034;
v_31030:
    v_31112 = stack[-1];
    goto v_31031;
v_31032:
    v_31113 = elt(env, 2); // adjoint
    goto v_31033;
v_31034:
    goto v_31030;
v_31031:
    goto v_31032;
v_31033:
    return get(v_31112, v_31113);
v_31027:
    goto v_31043;
v_31039:
    v_31112 = stack[-1];
    v_31113 = qcar(v_31112);
    goto v_31040;
v_31041:
    v_31112 = elt(env, 3); // comm
    goto v_31042;
v_31043:
    goto v_31039;
v_31040:
    goto v_31041;
v_31042:
    if (v_31113 == v_31112) goto v_31037;
    else goto v_31038;
v_31037:
    goto v_31054;
v_31048:
    stack[-2] = elt(env, 3); // comm
    goto v_31049;
v_31050:
    v_31112 = stack[-1];
    v_31112 = qcdr(v_31112);
    v_31112 = qcdr(v_31112);
    v_31112 = qcar(v_31112);
    stack[0] = CC_adjp(elt(env, 0), v_31112);
    env = stack[-3];
    goto v_31051;
v_31052:
    v_31112 = stack[-1];
    v_31112 = qcdr(v_31112);
    v_31112 = qcar(v_31112);
    v_31112 = CC_adjp(elt(env, 0), v_31112);
    goto v_31053;
v_31054:
    goto v_31048;
v_31049:
    goto v_31050;
v_31051:
    goto v_31052;
v_31053:
    {
        LispObject v_31117 = stack[-2];
        LispObject v_31118 = stack[0];
        return list3(v_31117, v_31118, v_31112);
    }
v_31038:
    goto v_31071;
v_31067:
    v_31112 = stack[-1];
    v_31113 = qcar(v_31112);
    goto v_31068;
v_31069:
    v_31112 = elt(env, 4); // anticomm
    goto v_31070;
v_31071:
    goto v_31067;
v_31068:
    goto v_31069;
v_31070:
    if (v_31113 == v_31112) goto v_31065;
    else goto v_31066;
v_31065:
    goto v_31082;
v_31076:
    stack[-2] = elt(env, 4); // anticomm
    goto v_31077;
v_31078:
    v_31112 = stack[-1];
    v_31112 = qcdr(v_31112);
    v_31112 = qcar(v_31112);
    stack[0] = CC_adjp(elt(env, 0), v_31112);
    env = stack[-3];
    goto v_31079;
v_31080:
    v_31112 = stack[-1];
    v_31112 = qcdr(v_31112);
    v_31112 = qcdr(v_31112);
    v_31112 = qcar(v_31112);
    v_31112 = CC_adjp(elt(env, 0), v_31112);
    goto v_31081;
v_31082:
    goto v_31076;
v_31077:
    goto v_31078;
v_31079:
    goto v_31080;
v_31081:
    {
        LispObject v_31119 = stack[-2];
        LispObject v_31120 = stack[0];
        return list3(v_31119, v_31120, v_31112);
    }
v_31066:
    goto v_31100;
v_31096:
    goto v_31106;
v_31102:
    v_31112 = stack[-1];
    v_31113 = qcar(v_31112);
    goto v_31103;
v_31104:
    v_31112 = elt(env, 2); // adjoint
    goto v_31105;
v_31106:
    goto v_31102;
v_31103:
    goto v_31104;
v_31105:
    v_31113 = get(v_31113, v_31112);
    goto v_31097;
v_31098:
    v_31112 = stack[-1];
    v_31112 = qcdr(v_31112);
    goto v_31099;
v_31100:
    goto v_31096;
v_31097:
    goto v_31098;
v_31099:
    return cons(v_31113, v_31112);
    v_31112 = nil;
v_31015:
    return onevalue(v_31112);
}



// Code for store_edges

static LispObject CC_store_edges(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31072, v_31073;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31012);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_31072 = v_31012;
// end of prologue
    stack[-3] = v_31072;
    v_31072 = stack[-3];
    if (v_31072 == nil) goto v_31023;
    else goto v_31024;
v_31023:
    v_31072 = nil;
    goto v_31018;
v_31024:
    v_31072 = stack[-3];
    v_31072 = qcar(v_31072);
    goto v_31036;
v_31032:
    v_31073 = v_31072;
    v_31073 = qcar(v_31073);
    goto v_31033;
v_31034:
    v_31072 = qcdr(v_31072);
    goto v_31035;
v_31036:
    goto v_31032;
v_31033:
    goto v_31034;
v_31035:
    v_31072 = cons(v_31073, v_31072);
    env = stack[-4];
    v_31072 = ncons(v_31072);
    env = stack[-4];
    stack[-1] = v_31072;
    stack[-2] = v_31072;
v_31019:
    v_31072 = stack[-3];
    v_31072 = qcdr(v_31072);
    stack[-3] = v_31072;
    v_31072 = stack[-3];
    if (v_31072 == nil) goto v_31045;
    else goto v_31046;
v_31045:
    v_31072 = stack[-2];
    goto v_31018;
v_31046:
    goto v_31054;
v_31050:
    stack[0] = stack[-1];
    goto v_31051;
v_31052:
    v_31072 = stack[-3];
    v_31072 = qcar(v_31072);
    goto v_31065;
v_31061:
    v_31073 = v_31072;
    v_31073 = qcar(v_31073);
    goto v_31062;
v_31063:
    v_31072 = qcdr(v_31072);
    goto v_31064;
v_31065:
    goto v_31061;
v_31062:
    goto v_31063;
v_31064:
    v_31072 = cons(v_31073, v_31072);
    env = stack[-4];
    v_31072 = ncons(v_31072);
    env = stack[-4];
    goto v_31053;
v_31054:
    goto v_31050;
v_31051:
    goto v_31052;
v_31053:
    v_31072 = Lrplacd(nil, stack[0], v_31072);
    env = stack[-4];
    v_31072 = stack[-1];
    v_31072 = qcdr(v_31072);
    stack[-1] = v_31072;
    goto v_31019;
v_31018:
    return onevalue(v_31072);
}



// Code for lchk

static LispObject CC_lchk(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31075, v_31076;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31012);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31012;
// end of prologue
    v_31075 = stack[0];
    if (v_31075 == nil) goto v_31024;
    else goto v_31025;
v_31024:
    v_31075 = lisp_true;
    goto v_31023;
v_31025:
    v_31075 = stack[0];
    v_31075 = qcar(v_31075);
    v_31075 = (consp(v_31075) ? nil : lisp_true);
    goto v_31023;
    v_31075 = nil;
v_31023:
    if (v_31075 == nil) goto v_31021;
    v_31075 = nil;
    goto v_31016;
v_31021:
    v_31075 = stack[0];
    v_31075 = qcar(v_31075);
    v_31075 = Llength(nil, v_31075);
    env = stack[-2];
    stack[-1] = v_31075;
v_31039:
    v_31075 = stack[0];
    v_31075 = qcdr(v_31075);
    stack[0] = v_31075;
    v_31075 = stack[0];
    if (v_31075 == nil) goto v_31048;
    else goto v_31049;
v_31048:
    v_31075 = lisp_true;
    goto v_31047;
v_31049:
    v_31075 = stack[0];
    v_31075 = qcar(v_31075);
    if (!consp(v_31075)) goto v_31056;
    else goto v_31057;
v_31056:
    v_31075 = lisp_true;
    goto v_31055;
v_31057:
    goto v_31068;
v_31064:
    v_31075 = stack[0];
    v_31075 = qcar(v_31075);
    v_31076 = Llength(nil, v_31075);
    env = stack[-2];
    goto v_31065;
v_31066:
    v_31075 = stack[-1];
    goto v_31067;
v_31068:
    goto v_31064;
v_31065:
    goto v_31066;
v_31067:
    v_31075 = Lneq(nil, v_31076, v_31075);
    env = stack[-2];
    goto v_31055;
    v_31075 = nil;
v_31055:
    goto v_31047;
    v_31075 = nil;
v_31047:
    if (v_31075 == nil) goto v_31044;
    else goto v_31045;
v_31044:
    goto v_31039;
v_31045:
    v_31075 = stack[0];
    v_31075 = (v_31075 == nil ? lisp_true : nil);
v_31016:
    return onevalue(v_31075);
}



// Code for cr2rderr

static LispObject CC_cr2rderr(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31021, v_31022;
    LispObject fn;
    argcheck(nargs, 0, "cr2rderr");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    goto v_31018;
v_31014:
    v_31022 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31015;
v_31016:
    v_31021 = elt(env, 1); // "complex to real type conversion requires zero imaginary part"
    goto v_31017;
v_31018:
    goto v_31014;
v_31015:
    goto v_31016;
v_31017:
    {
        fn = elt(env, 2); // error
        return (*qfn2(fn))(fn, v_31022, v_31021);
    }
}



// Code for cde_list2id

static LispObject CC_cde_list2id(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31075, v_31076;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31012);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_31076 = v_31012;
// end of prologue
    v_31075 = v_31076;
    if (!consp(v_31075)) goto v_31016;
    else goto v_31017;
v_31016:
    v_31075 = elt(env, 1); // "argument for cde_list2id must be a list"
    {
        fn = elt(env, 2); // rederr
        return (*qfn1(fn))(fn, v_31075);
    }
v_31017:
    v_31075 = v_31076;
    stack[-3] = v_31075;
v_31030:
    v_31075 = stack[-3];
    if (v_31075 == nil) goto v_31035;
    else goto v_31036;
v_31035:
    v_31075 = nil;
    goto v_31029;
v_31036:
    v_31075 = stack[-3];
    v_31075 = qcar(v_31075);
    v_31075 = Lexplode(nil, v_31075);
    env = stack[-4];
    stack[-2] = v_31075;
    v_31075 = stack[-2];
    fn = elt(env, 3); // lastpair
    v_31075 = (*qfn1(fn))(fn, v_31075);
    env = stack[-4];
    stack[-1] = v_31075;
    v_31075 = stack[-3];
    v_31075 = qcdr(v_31075);
    stack[-3] = v_31075;
    v_31075 = stack[-1];
    if (!consp(v_31075)) goto v_31050;
    else goto v_31051;
v_31050:
    goto v_31030;
v_31051:
v_31031:
    v_31075 = stack[-3];
    if (v_31075 == nil) goto v_31055;
    else goto v_31056;
v_31055:
    v_31075 = stack[-2];
    goto v_31029;
v_31056:
    goto v_31064;
v_31060:
    stack[0] = stack[-1];
    goto v_31061;
v_31062:
    v_31075 = stack[-3];
    v_31075 = qcar(v_31075);
    v_31075 = Lexplode(nil, v_31075);
    env = stack[-4];
    goto v_31063;
v_31064:
    goto v_31060;
v_31061:
    goto v_31062;
v_31063:
    v_31075 = Lrplacd(nil, stack[0], v_31075);
    env = stack[-4];
    v_31075 = stack[-1];
    fn = elt(env, 3); // lastpair
    v_31075 = (*qfn1(fn))(fn, v_31075);
    env = stack[-4];
    stack[-1] = v_31075;
    v_31075 = stack[-3];
    v_31075 = qcdr(v_31075);
    stack[-3] = v_31075;
    goto v_31031;
v_31029:
    v_31075 = Lcompress(nil, v_31075);
        return Lintern(nil, v_31075);
    v_31075 = nil;
    return onevalue(v_31075);
}



// Code for sfto_deggcd1

static LispObject CC_sfto_deggcd1(LispObject env,
                         LispObject v_31012, LispObject v_31013)
{
    env = qenv(env);
    LispObject v_31104, v_31105, v_31106;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31013,v_31012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31012,v_31013);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_31013;
    stack[-2] = v_31012;
// end of prologue
    v_31104 = (LispObject)0+TAG_FIXNUM; // 0
    v_31106 = v_31104;
    v_31104 = lisp_true;
    stack[-3] = v_31104;
v_31023:
    v_31104 = stack[-3];
    if (v_31104 == nil) goto v_31026;
    goto v_31035;
v_31031:
    v_31105 = v_31106;
    goto v_31032;
v_31033:
    v_31104 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31034;
v_31035:
    goto v_31031;
v_31032:
    goto v_31033;
v_31034:
    if (v_31105 == v_31104) goto v_31026;
    goto v_31027;
v_31026:
    goto v_31022;
v_31027:
    v_31104 = stack[-2];
    if (!consp(v_31104)) goto v_31045;
    else goto v_31046;
v_31045:
    v_31104 = lisp_true;
    goto v_31044;
v_31046:
    v_31104 = stack[-2];
    v_31104 = qcar(v_31104);
    v_31104 = (consp(v_31104) ? nil : lisp_true);
    goto v_31044;
    v_31104 = nil;
v_31044:
    if (v_31104 == nil) goto v_31042;
    v_31104 = nil;
    stack[-3] = v_31104;
    goto v_31040;
v_31042:
    goto v_31065;
v_31061:
    v_31104 = stack[-2];
    v_31104 = qcar(v_31104);
    v_31104 = qcar(v_31104);
    v_31105 = qcar(v_31104);
    goto v_31062;
v_31063:
    v_31104 = stack[-1];
    goto v_31064;
v_31065:
    goto v_31061;
v_31062:
    goto v_31063;
v_31064:
    if (v_31105 == v_31104) goto v_31059;
    else goto v_31060;
v_31059:
    goto v_31076;
v_31072:
    v_31105 = v_31106;
    goto v_31073;
v_31074:
    v_31104 = stack[-2];
    v_31104 = qcar(v_31104);
    v_31104 = qcar(v_31104);
    v_31104 = qcdr(v_31104);
    goto v_31075;
v_31076:
    goto v_31072;
v_31073:
    goto v_31074;
v_31075:
    v_31104 = Lgcd(nil, v_31105, v_31104);
    env = stack[-4];
    v_31106 = v_31104;
    goto v_31058;
v_31060:
    goto v_31089;
v_31085:
    stack[0] = v_31106;
    goto v_31086;
v_31087:
    goto v_31096;
v_31092:
    v_31104 = stack[-2];
    v_31104 = qcar(v_31104);
    v_31105 = qcdr(v_31104);
    goto v_31093;
v_31094:
    v_31104 = stack[-1];
    goto v_31095;
v_31096:
    goto v_31092;
v_31093:
    goto v_31094;
v_31095:
    v_31104 = CC_sfto_deggcd1(elt(env, 0), v_31105, v_31104);
    env = stack[-4];
    goto v_31088;
v_31089:
    goto v_31085;
v_31086:
    goto v_31087;
v_31088:
    v_31104 = Lgcd(nil, stack[0], v_31104);
    env = stack[-4];
    v_31106 = v_31104;
    goto v_31058;
v_31058:
    v_31104 = stack[-2];
    v_31104 = qcdr(v_31104);
    stack[-2] = v_31104;
    goto v_31040;
v_31040:
    goto v_31023;
v_31022:
    v_31104 = v_31106;
    return onevalue(v_31104);
}



// Code for preptaylor!*!*

static LispObject CC_preptaylorHH(LispObject env,
                         LispObject v_31012)
{
    env = qenv(env);
    LispObject v_31024, v_31025;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31025 = v_31012;
// end of prologue
    v_31024 = qvalue(elt(env, 1)); // convert!-taylor!*
    if (v_31024 == nil) goto v_31016;
    else goto v_31017;
v_31016:
    v_31024 = v_31025;
    goto v_31015;
v_31017:
    v_31024 = v_31025;
    {
        fn = elt(env, 2); // preptaylor!*
        return (*qfn1(fn))(fn, v_31024);
    }
    v_31024 = nil;
v_31015:
    return onevalue(v_31024);
}



setup_type const u53_setup[] =
{
    {"rule*",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ruleH},
    {"mk_resimp_rep",           CC_mk_resimp_rep,TOO_MANY_1,   WRONG_NO_1},
    {"talp_try1",               CC_talp_try1,   TOO_MANY_1,    WRONG_NO_1},
    {"expvec2a1",               TOO_FEW_2,      CC_expvec2a1,  WRONG_NO_2},
    {"deflate1",                TOO_FEW_2,      CC_deflate1,   WRONG_NO_2},
    {"rdzchk",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rdzchk},
    {"requote1",                CC_requote1,    TOO_MANY_1,    WRONG_NO_1},
    {"denlist",                 TOO_FEW_2,      CC_denlist,    WRONG_NO_2},
    {"baglistp",                CC_baglistp,    TOO_MANY_1,    WRONG_NO_1},
    {"coeff_totder",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_coeff_totder},
    {"qqe_dfs",                 TOO_FEW_2,      CC_qqe_dfs,    WRONG_NO_2},
    {"rl_simplb",               TOO_FEW_2,      CC_rl_simplb,  WRONG_NO_2},
    {"*s2i",                    CC_Hs2i,        TOO_MANY_1,    WRONG_NO_1},
    {"cr:zerop",                CC_crTzerop,    TOO_MANY_1,    WRONG_NO_1},
    {"splitrec",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_splitrec},
    {"multsqpf",                TOO_FEW_2,      CC_multsqpf,   WRONG_NO_2},
    {"sqprla",                  TOO_FEW_2,      CC_sqprla,     WRONG_NO_2},
    {"gffdot",                  TOO_FEW_2,      CC_gffdot,     WRONG_NO_2},
    {"red_redpol",              TOO_FEW_2,      CC_red_redpol, WRONG_NO_2},
    {"eval_uni_poly",           TOO_FEW_2,      CC_eval_uni_poly,WRONG_NO_2},
    {"precision1",              TOO_FEW_2,      CC_precision1, WRONG_NO_2},
    {"ofsf_irl2atl",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_irl2atl},
    {"ofsf_smmkatl-or1",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smmkatlKor1},
    {"sfpf",                    CC_sfpf,        TOO_MANY_1,    WRONG_NO_1},
    {"constant_exprp",          CC_constant_exprp,TOO_MANY_1,  WRONG_NO_1},
    {"talp_mk-invs",            TOO_FEW_2,      CC_talp_mkKinvs,WRONG_NO_2},
    {"aex_simplenumberp",       CC_aex_simplenumberp,TOO_MANY_1,WRONG_NO_1},
    {"arprep:",                 CC_arprepT,     TOO_MANY_1,    WRONG_NO_1},
    {"xpartitk",                CC_xpartitk,    TOO_MANY_1,    WRONG_NO_1},
    {"minprec",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_minprec},
    {"r2oreaction",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_r2oreaction},
    {"rand-mons-sparse",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_randKmonsKsparse},
    {"redassignp",              CC_redassignp,  TOO_MANY_1,    WRONG_NO_1},
    {"coeff1_calc",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_coeff1_calc},
    {"clogsq",                  CC_clogsq,      TOO_MANY_1,    WRONG_NO_1},
    {"dp_2a",                   CC_dp_2a,       TOO_MANY_1,    WRONG_NO_1},
    {"mod/",                    TOO_FEW_2,      CC_modV,       WRONG_NO_2},
    {"cde_alglistp",            CC_cde_alglistp,TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_sminsert",           TOO_FEW_2,      CC_ofsf_sminsert,WRONG_NO_2},
    {"addfactors",              TOO_FEW_2,      CC_addfactors, WRONG_NO_2},
    {"subdf",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_subdf},
    {"cl_strict-gdnf",          TOO_FEW_2,      CC_cl_strictKgdnf,WRONG_NO_2},
    {"make-image-mod-p",        TOO_FEW_2,      CC_makeKimageKmodKp,WRONG_NO_2},
    {"getvariables",            CC_getvariables,TOO_MANY_1,    WRONG_NO_1},
    {"indordlp",                TOO_FEW_2,      CC_indordlp,   WRONG_NO_2},
    {"adjp",                    CC_adjp,        TOO_MANY_1,    WRONG_NO_1},
    {"store_edges",             CC_store_edges, TOO_MANY_1,    WRONG_NO_1},
    {"lchk",                    CC_lchk,        TOO_MANY_1,    WRONG_NO_1},
    {"cr2rderr",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cr2rderr},
    {"cde_list2id",             CC_cde_list2id, TOO_MANY_1,    WRONG_NO_1},
    {"sfto_deggcd1",            TOO_FEW_2,      CC_sfto_deggcd1,WRONG_NO_2},
    {"preptaylor**",            CC_preptaylorHH,TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u53", (two_args *)"153001 9979575 2917963", 0}
};

// end of generated code
