
// $destdir/u30.c        Machine generated C code

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



// Code for plubf

static LispObject CC_plubf(LispObject env,
                         LispObject v_16129, LispObject v_16130)
{
    env = qenv(env);
    LispObject v_16381, v_16382, v_16383;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16130,v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16129,v_16130);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-6] = v_16130;
    stack[-7] = v_16129;
// end of prologue
// Binding d
// FLUIDBIND: reloadenv=9 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-9, 1, -2);
    qvalue(elt(env, 1)) = nil; // d
    goto v_16149;
v_16145:
    v_16381 = stack[-7];
    v_16381 = qcdr(v_16381);
    v_16382 = qcar(v_16381);
    stack[-8] = v_16382;
    goto v_16146;
v_16147:
    v_16381 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16148;
v_16149:
    goto v_16145;
v_16146:
    goto v_16147;
v_16148:
    if (v_16382 == v_16381) goto v_16143;
    else goto v_16144;
v_16143:
    v_16381 = stack[-6];
    goto v_16140;
v_16144:
    goto v_16163;
v_16159:
    v_16381 = stack[-6];
    v_16381 = qcdr(v_16381);
    v_16382 = qcar(v_16381);
    stack[-5] = v_16382;
    goto v_16160;
v_16161:
    v_16381 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16162;
v_16163:
    goto v_16159;
v_16160:
    goto v_16161;
v_16162:
    if (v_16382 == v_16381) goto v_16157;
    else goto v_16158;
v_16157:
    v_16381 = stack[-7];
    goto v_16140;
v_16158:
    goto v_16177;
v_16173:
    goto v_16183;
v_16179:
    v_16381 = stack[-7];
    v_16381 = qcdr(v_16381);
    v_16382 = qcdr(v_16381);
    stack[-4] = v_16382;
    goto v_16180;
v_16181:
    v_16381 = stack[-6];
    v_16381 = qcdr(v_16381);
    v_16381 = qcdr(v_16381);
    stack[-3] = v_16381;
    goto v_16182;
v_16183:
    goto v_16179;
v_16180:
    goto v_16181;
v_16182:
    v_16382 = difference2(v_16382, v_16381);
    env = stack[-9];
    qvalue(elt(env, 1)) = v_16382; // d
    goto v_16174;
v_16175:
    v_16381 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16176;
v_16177:
    goto v_16173;
v_16174:
    goto v_16175;
v_16176:
    if (v_16382 == v_16381) goto v_16171;
    else goto v_16172;
v_16171:
    goto v_16198;
v_16192:
    stack[0] = elt(env, 2); // !:rd!:
    goto v_16193;
v_16194:
    goto v_16205;
v_16201:
    v_16382 = stack[-8];
    goto v_16202;
v_16203:
    v_16381 = stack[-5];
    goto v_16204;
v_16205:
    goto v_16201;
v_16202:
    goto v_16203;
v_16204:
    v_16382 = plus2(v_16382, v_16381);
    env = stack[-9];
    goto v_16195;
v_16196:
    v_16381 = stack[-4];
    goto v_16197;
v_16198:
    goto v_16192;
v_16193:
    goto v_16194;
v_16195:
    goto v_16196;
v_16197:
    v_16381 = list2star(stack[0], v_16382, v_16381);
    env = stack[-9];
    goto v_16140;
v_16172:
    goto v_16214;
v_16210:
    stack[-1] = qvalue(elt(env, 1)); // d
    goto v_16211;
v_16212:
    goto v_16221;
v_16217:
    v_16381 = stack[-8];
    v_16381 = Labsval(nil, v_16381);
    env = stack[-9];
    fn = elt(env, 4); // msd
    stack[0] = (*qfn1(fn))(fn, v_16381);
    env = stack[-9];
    goto v_16218;
v_16219:
    v_16381 = stack[-5];
    v_16381 = Labsval(nil, v_16381);
    env = stack[-9];
    fn = elt(env, 4); // msd
    v_16381 = (*qfn1(fn))(fn, v_16381);
    env = stack[-9];
    goto v_16220;
v_16221:
    goto v_16217;
v_16218:
    goto v_16219;
v_16220:
    v_16381 = difference2(stack[0], v_16381);
    env = stack[-9];
    goto v_16213;
v_16214:
    goto v_16210;
v_16211:
    goto v_16212;
v_16213:
    v_16381 = plus2(stack[-1], v_16381);
    env = stack[-9];
    stack[-1] = v_16381;
    v_16381 = qvalue(elt(env, 3)); // !:bprec!:
    v_16381 = add1(v_16381);
    env = stack[-9];
    stack[0] = v_16381;
    goto v_16239;
v_16235:
    v_16382 = stack[-1];
    goto v_16236;
v_16237:
    v_16381 = stack[0];
    goto v_16238;
v_16239:
    goto v_16235;
v_16236:
    goto v_16237;
v_16238:
    v_16381 = (LispObject)greaterp2(v_16382, v_16381);
    v_16381 = v_16381 ? lisp_true : nil;
    env = stack[-9];
    if (v_16381 == nil) goto v_16233;
    v_16381 = stack[-7];
    goto v_16140;
v_16233:
    goto v_16252;
v_16248:
    goto v_16249;
v_16250:
    v_16381 = stack[0];
    v_16381 = negate(v_16381);
    env = stack[-9];
    goto v_16251;
v_16252:
    goto v_16248;
v_16249:
    goto v_16250;
v_16251:
    v_16381 = (LispObject)lessp2(stack[-1], v_16381);
    v_16381 = v_16381 ? lisp_true : nil;
    env = stack[-9];
    if (v_16381 == nil) goto v_16246;
    v_16381 = stack[-6];
    goto v_16140;
v_16246:
    goto v_16266;
v_16262:
    v_16382 = qvalue(elt(env, 1)); // d
    goto v_16263;
v_16264:
    v_16381 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16265;
v_16266:
    goto v_16262;
v_16263:
    goto v_16264;
v_16265:
    v_16381 = (LispObject)greaterp2(v_16382, v_16381);
    v_16381 = v_16381 ? lisp_true : nil;
    env = stack[-9];
    if (v_16381 == nil) goto v_16260;
    goto v_16276;
v_16270:
    stack[0] = elt(env, 2); // !:rd!:
    goto v_16271;
v_16272:
    goto v_16283;
v_16279:
    goto v_16289;
v_16285:
    v_16382 = stack[-8];
    goto v_16286;
v_16287:
    v_16381 = qvalue(elt(env, 1)); // d
    goto v_16288;
v_16289:
    goto v_16285;
v_16286:
    goto v_16287;
v_16288:
    fn = elt(env, 5); // ashift
    v_16382 = (*qfn2(fn))(fn, v_16382, v_16381);
    env = stack[-9];
    goto v_16280;
v_16281:
    v_16381 = stack[-5];
    goto v_16282;
v_16283:
    goto v_16279;
v_16280:
    goto v_16281;
v_16282:
    v_16382 = plus2(v_16382, v_16381);
    env = stack[-9];
    goto v_16273;
v_16274:
    v_16381 = stack[-3];
    goto v_16275;
v_16276:
    goto v_16270;
v_16271:
    goto v_16272;
v_16273:
    goto v_16274;
v_16275:
    v_16381 = list2star(stack[0], v_16382, v_16381);
    env = stack[-9];
    goto v_16140;
v_16260:
    goto v_16303;
v_16297:
    stack[0] = elt(env, 2); // !:rd!:
    goto v_16298;
v_16299:
    goto v_16310;
v_16306:
    stack[-1] = stack[-8];
    goto v_16307;
v_16308:
    goto v_16317;
v_16313:
    stack[-3] = stack[-5];
    goto v_16314;
v_16315:
    v_16381 = qvalue(elt(env, 1)); // d
    v_16381 = negate(v_16381);
    env = stack[-9];
    goto v_16316;
v_16317:
    goto v_16313;
v_16314:
    goto v_16315;
v_16316:
    fn = elt(env, 5); // ashift
    v_16381 = (*qfn2(fn))(fn, stack[-3], v_16381);
    env = stack[-9];
    goto v_16309;
v_16310:
    goto v_16306;
v_16307:
    goto v_16308;
v_16309:
    v_16382 = plus2(stack[-1], v_16381);
    env = stack[-9];
    goto v_16300;
v_16301:
    v_16381 = stack[-4];
    goto v_16302;
v_16303:
    goto v_16297;
v_16298:
    goto v_16299;
v_16300:
    goto v_16301;
v_16302:
    v_16381 = list2star(stack[0], v_16382, v_16381);
    env = stack[-9];
    goto v_16140;
    v_16381 = nil;
v_16140:
    ;}  // end of a binding scope
    stack[-2] = v_16381;
    v_16381 = stack[-2];
    v_16381 = qcdr(v_16381);
    v_16381 = qcar(v_16381);
    v_16383 = v_16381;
    goto v_16337;
v_16333:
    v_16382 = v_16383;
    goto v_16334;
v_16335:
    v_16381 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16336;
v_16337:
    goto v_16333;
v_16334:
    goto v_16335;
v_16336:
    if (v_16382 == v_16381) goto v_16331;
    else goto v_16332;
v_16331:
    goto v_16347;
v_16341:
    v_16383 = elt(env, 2); // !:rd!:
    goto v_16342;
v_16343:
    v_16382 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16344;
v_16345:
    v_16381 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16346;
v_16347:
    goto v_16341;
v_16342:
    goto v_16343;
v_16344:
    goto v_16345;
v_16346:
    return list2star(v_16383, v_16382, v_16381);
v_16332:
    goto v_16356;
v_16352:
    v_16382 = v_16383;
    goto v_16353;
v_16354:
    v_16381 = qvalue(elt(env, 3)); // !:bprec!:
    goto v_16355;
v_16356:
    goto v_16352;
v_16353:
    goto v_16354;
v_16355:
    fn = elt(env, 6); // inorm
    v_16381 = (*qfn2(fn))(fn, v_16382, v_16381);
    env = stack[-9];
    v_16383 = v_16381;
    goto v_16366;
v_16360:
    stack[-1] = elt(env, 2); // !:rd!:
    goto v_16361;
v_16362:
    v_16381 = v_16383;
    stack[0] = qcar(v_16381);
    goto v_16363;
v_16364:
    goto v_16375;
v_16371:
    v_16381 = v_16383;
    v_16382 = qcdr(v_16381);
    goto v_16372;
v_16373:
    v_16381 = stack[-2];
    v_16381 = qcdr(v_16381);
    v_16381 = qcdr(v_16381);
    goto v_16374;
v_16375:
    goto v_16371;
v_16372:
    goto v_16373;
v_16374:
    v_16381 = plus2(v_16382, v_16381);
    goto v_16365;
v_16366:
    goto v_16360;
v_16361:
    goto v_16362;
v_16363:
    goto v_16364;
v_16365:
    {
        LispObject v_16393 = stack[-1];
        LispObject v_16394 = stack[0];
        return list2star(v_16393, v_16394, v_16381);
    }
    return onevalue(v_16381);
}



// Code for unresidp

static LispObject CC_unresidp(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16140, v_16141;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16140 = v_16129;
// end of prologue
    goto v_16135;
v_16131:
    goto v_16132;
v_16133:
    v_16141 = qvalue(elt(env, 1)); // !*reservedops!*
    goto v_16134;
v_16135:
    goto v_16131;
v_16132:
    goto v_16133;
v_16134:
    v_16140 = Lmemq(nil, v_16140, v_16141);
    v_16140 = (v_16140 == nil ? lisp_true : nil);
    return onevalue(v_16140);
}



// Code for log_inlines

static LispObject CC_log_inlines(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16161, v_16162;
    LispObject fn;
    LispObject v_16131, v_16130, v_16129;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "log_inlines");
    va_start(aa, nargs);
    v_16129 = va_arg(aa, LispObject);
    v_16130 = va_arg(aa, LispObject);
    v_16131 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_16131,v_16130,v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_16129,v_16130,v_16131);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_16161 = v_16131;
    stack[0] = v_16130;
    stack[-1] = v_16129;
// end of prologue
    goto v_16144;
v_16140:
    v_16162 = stack[-1];
    goto v_16141;
v_16142:
    v_16161 = stack[0];
    goto v_16143;
v_16144:
    goto v_16140;
v_16141:
    goto v_16142;
v_16143:
    fn = elt(env, 1); // log_assignment
    v_16161 = (*qfn2(fn))(fn, v_16162, v_16161);
    env = stack[-2];
    if (v_16161 == nil) goto v_16138;
    v_16161 = nil;
    goto v_16134;
v_16138:
    goto v_16157;
v_16153:
    v_16162 = stack[-1];
    goto v_16154;
v_16155:
    v_16161 = stack[0];
    goto v_16156;
v_16157:
    goto v_16153;
v_16154:
    goto v_16155;
v_16156:
    fn = elt(env, 2); // log_freevars
    v_16161 = (*qfn2(fn))(fn, v_16162, v_16161);
    if (v_16161 == nil) goto v_16151;
    v_16161 = nil;
    goto v_16134;
v_16151:
    v_16161 = nil;
v_16134:
    return onevalue(v_16161);
}



// Code for quotpri

static LispObject CC_quotpri(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16186, v_16187, v_16188;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16129);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_16187 = v_16129;
// end of prologue
    stack[0] = nil;
    v_16186 = qvalue(elt(env, 1)); // !*ratpri
    if (v_16186 == nil) goto v_16140;
    else goto v_16141;
v_16140:
    v_16186 = lisp_true;
    goto v_16139;
v_16141:
    v_16186 = qvalue(elt(env, 2)); // !*nat
    if (v_16186 == nil) goto v_16148;
    else goto v_16149;
v_16148:
    v_16186 = lisp_true;
    goto v_16147;
v_16149:
    v_16186 = qvalue(elt(env, 3)); // !*fort
    if (v_16186 == nil) goto v_16156;
    else goto v_16155;
v_16156:
    v_16186 = qvalue(elt(env, 4)); // !*list
    if (v_16186 == nil) goto v_16160;
    else goto v_16159;
v_16160:
    v_16186 = qvalue(elt(env, 5)); // !*mcd
    v_16186 = (v_16186 == nil ? lisp_true : nil);
v_16159:
v_16155:
    goto v_16147;
    v_16186 = nil;
v_16147:
    goto v_16139;
    v_16186 = nil;
v_16139:
    if (v_16186 == nil) goto v_16137;
    v_16186 = elt(env, 6); // failed
    goto v_16133;
v_16137:
    goto v_16172;
v_16168:
    v_16188 = qvalue(elt(env, 7)); // dmode!*
    goto v_16169;
v_16170:
    v_16186 = elt(env, 8); // ratmode
    goto v_16171;
v_16172:
    goto v_16168;
v_16169:
    goto v_16170;
v_16171:
    v_16186 = Lflagp(nil, v_16188, v_16186);
    env = stack[-1];
    if (v_16186 == nil) goto v_16166;
    v_16186 = qvalue(elt(env, 7)); // dmode!*
    stack[0] = v_16186;
    v_16186 = nil;
    qvalue(elt(env, 7)) = v_16186; // dmode!*
    goto v_16135;
v_16166:
v_16135:
    v_16186 = v_16187;
    fn = elt(env, 9); // ratfunpri1
    v_16186 = (*qfn1(fn))(fn, v_16186);
    env = stack[-1];
    v_16187 = v_16186;
    v_16186 = stack[0];
    if (v_16186 == nil) goto v_16182;
    v_16186 = stack[0];
    qvalue(elt(env, 7)) = v_16186; // dmode!*
    goto v_16180;
v_16182:
v_16180:
    v_16186 = v_16187;
v_16133:
    return onevalue(v_16186);
}



// Code for mo_2a

static LispObject CC_mo_2a(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16141;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16129);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_16141 = v_16129;
// end of prologue
    goto v_16136;
v_16132:
    stack[0] = qcar(v_16141);
    goto v_16133;
v_16134:
    v_16141 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 2); // ring_all_names
    v_16141 = (*qfn1(fn))(fn, v_16141);
    env = stack[-1];
    goto v_16135;
v_16136:
    goto v_16132;
v_16133:
    goto v_16134;
v_16135:
    {
        LispObject v_16143 = stack[0];
        fn = elt(env, 3); // mo!=expvec2a1
        return (*qfn2(fn))(fn, v_16143, v_16141);
    }
}



// Code for cde_odd_derivatives

static LispObject CC_cde_odd_derivatives(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16234, v_16235, v_16236;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16129);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_16129;
// end of prologue
    goto v_16141;
v_16137:
    v_16235 = qvalue(elt(env, 1)); // n_all_parametric_ext
    goto v_16138;
v_16139:
    v_16234 = qvalue(elt(env, 2)); // n_all_principal_ext
    goto v_16140;
v_16141:
    goto v_16137;
v_16138:
    goto v_16139;
v_16140:
    v_16234 = plus2(v_16235, v_16234);
    env = stack[-8];
    stack[-5] = v_16234;
    v_16234 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_16234;
v_16147:
    goto v_16159;
v_16155:
    v_16235 = stack[-5];
    goto v_16156;
v_16157:
    v_16234 = stack[-4];
    goto v_16158;
v_16159:
    goto v_16155;
v_16156:
    goto v_16157;
v_16158:
    v_16234 = difference2(v_16235, v_16234);
    env = stack[-8];
    v_16234 = Lminusp(nil, v_16234);
    env = stack[-8];
    if (v_16234 == nil) goto v_16152;
    v_16234 = nil;
    goto v_16146;
v_16152:
    goto v_16168;
v_16164:
    v_16235 = elt(env, 3); // svf_ext
    goto v_16165;
v_16166:
    v_16234 = stack[-4];
    goto v_16167;
v_16168:
    goto v_16164;
v_16165:
    goto v_16166;
v_16167:
    fn = elt(env, 4); // mkid
    v_16234 = (*qfn2(fn))(fn, v_16235, v_16234);
    env = stack[-8];
    stack[-7] = v_16234;
    goto v_16178;
v_16172:
    v_16236 = stack[-7];
    goto v_16173;
v_16174:
    v_16235 = nil;
    goto v_16175;
v_16176:
    v_16234 = stack[-6];
    goto v_16177;
v_16178:
    goto v_16172;
v_16173:
    goto v_16174;
v_16175:
    goto v_16176;
v_16177:
    fn = elt(env, 5); // super_vectorfield
    v_16234 = (*qfnn(fn))(fn, 3, v_16236, v_16235, v_16234);
    env = stack[-8];
    v_16234 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_16234;
v_16185:
    goto v_16197;
v_16193:
    v_16235 = stack[-5];
    goto v_16194;
v_16195:
    v_16234 = stack[-3];
    goto v_16196;
v_16197:
    goto v_16193;
v_16194:
    goto v_16195;
v_16196:
    v_16234 = difference2(v_16235, v_16234);
    env = stack[-8];
    v_16234 = Lminusp(nil, v_16234);
    env = stack[-8];
    if (v_16234 == nil) goto v_16190;
    goto v_16184;
v_16190:
    goto v_16210;
v_16202:
    stack[-2] = stack[-7];
    goto v_16203;
v_16204:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16205;
v_16206:
    stack[0] = stack[-3];
    goto v_16207;
v_16208:
    goto v_16223;
v_16219:
    v_16235 = stack[-4];
    goto v_16220;
v_16221:
    v_16234 = stack[-3];
    goto v_16222;
v_16223:
    goto v_16219;
v_16220:
    goto v_16221;
v_16222:
    v_16234 = Leqn(nil, v_16235, v_16234);
    env = stack[-8];
    if (v_16234 == nil) goto v_16217;
    v_16234 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16215;
v_16217:
    v_16234 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16215;
    v_16234 = nil;
v_16215:
    goto v_16209;
v_16210:
    goto v_16202;
v_16203:
    goto v_16204;
v_16205:
    goto v_16206;
v_16207:
    goto v_16208;
v_16209:
    fn = elt(env, 6); // set_svf
    v_16234 = (*qfnn(fn))(fn, 4, stack[-2], stack[-1], stack[0], v_16234);
    env = stack[-8];
    v_16234 = stack[-3];
    v_16234 = add1(v_16234);
    env = stack[-8];
    stack[-3] = v_16234;
    goto v_16185;
v_16184:
    v_16234 = stack[-4];
    v_16234 = add1(v_16234);
    env = stack[-8];
    stack[-4] = v_16234;
    goto v_16147;
v_16146:
    return onevalue(v_16234);
}



// Code for expansion_name

static LispObject CC_expansion_name(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16142;
    argcheck(nargs, 0, "expansion_name");
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
    goto v_16136;
v_16132:
    v_16142 = elt(env, 1); // lalr_internal_
    stack[0] = Lexplode(nil, v_16142);
    env = stack[-1];
    goto v_16133;
v_16134:
    v_16142 = qvalue(elt(env, 2)); // expansion_count
    v_16142 = add1(v_16142);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_16142; // expansion_count
    v_16142 = Lexplode(nil, v_16142);
    env = stack[-1];
    goto v_16135;
v_16136:
    goto v_16132;
v_16133:
    goto v_16134;
v_16135:
    v_16142 = Lappend(nil, stack[0], v_16142);
        return Lcompress(nil, v_16142);
}



// Code for formproc

static LispObject CC_formproc(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16932, v_16933, v_16934, v_16935;
    LispObject fn;
    LispObject v_16131, v_16130, v_16129;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formproc");
    va_start(aa, nargs);
    v_16129 = va_arg(aa, LispObject);
    v_16130 = va_arg(aa, LispObject);
    v_16131 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_16131,v_16130,v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_16129,v_16130,v_16131);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-2] = v_16131;
    stack[-1] = v_16130;
    stack[0] = v_16129;
// end of prologue
// Binding fname!*
// FLUIDBIND: reloadenv=10 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-10, 1, -6);
    qvalue(elt(env, 1)) = nil; // fname!*
    stack[-8] = nil;
    v_16932 = stack[0];
    v_16932 = qcdr(v_16932);
    stack[0] = v_16932;
    v_16932 = stack[0];
    v_16932 = qcar(v_16932);
    qvalue(elt(env, 1)) = v_16932; // fname!*
    stack[-5] = v_16932;
    v_16932 = stack[0];
    v_16932 = qcdr(v_16932);
    v_16932 = qcar(v_16932);
    if (v_16932 == nil) goto v_16152;
    v_16932 = stack[0];
    v_16932 = qcdr(v_16932);
    v_16932 = qcar(v_16932);
    stack[-2] = v_16932;
    goto v_16150;
v_16152:
v_16150:
    v_16932 = stack[0];
    v_16932 = qcdr(v_16932);
    v_16932 = qcdr(v_16932);
    stack[0] = v_16932;
    v_16932 = stack[0];
    v_16932 = qcar(v_16932);
    qvalue(elt(env, 2)) = v_16932; // ftype!*
    stack[-4] = v_16932;
    v_16932 = stack[-5];
    if (!symbolp(v_16932)) v_16932 = nil;
    else { v_16932 = qfastgets(v_16932);
           if (v_16932 != nil) { v_16932 = elt(v_16932, 1); // lose
#ifdef RECORD_GET
             if (v_16932 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v_16932 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v_16932 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v_16932 == SPID_NOPROP) v_16932 = nil; else v_16932 = lisp_true; }}
#endif
    if (v_16932 == nil) goto v_16171;
    v_16932 = qvalue(elt(env, 3)); // !*lose
    if (v_16932 == nil) goto v_16176;
    else goto v_16175;
v_16176:
    v_16932 = qvalue(elt(env, 4)); // !*defn
    v_16932 = (v_16932 == nil ? lisp_true : nil);
v_16175:
    goto v_16169;
v_16171:
    v_16932 = nil;
    goto v_16169;
    v_16932 = nil;
v_16169:
    if (v_16932 == nil) goto v_16167;
    goto v_16189;
v_16185:
    v_16933 = stack[-5];
    goto v_16186;
v_16187:
    v_16932 = elt(env, 5); // "not defined (LOSE flag)"
    goto v_16188;
v_16189:
    goto v_16185;
v_16186:
    goto v_16187;
v_16188:
    v_16932 = list2(v_16933, v_16932);
    env = stack[-10];
    fn = elt(env, 47); // lprim
    v_16932 = (*qfn1(fn))(fn, v_16932);
    env = stack[-10];
    v_16932 = elt(env, 6); // (quote nil)
    goto v_16144;
v_16167:
    v_16932 = qvalue(elt(env, 7)); // !*redeflg!*
    if (v_16932 == nil) goto v_16194;
    v_16932 = stack[-5];
    fn = elt(env, 48); // getd
    v_16932 = (*qfn1(fn))(fn, v_16932);
    env = stack[-10];
    if (v_16932 == nil) goto v_16194;
    goto v_16206;
v_16202:
    v_16933 = stack[-5];
    goto v_16203;
v_16204:
    v_16932 = elt(env, 8); // "redefined"
    goto v_16205;
v_16206:
    goto v_16202;
v_16203:
    goto v_16204;
v_16205:
    v_16932 = list2(v_16933, v_16932);
    env = stack[-10];
    fn = elt(env, 47); // lprim
    v_16932 = (*qfn1(fn))(fn, v_16932);
    env = stack[-10];
    goto v_16165;
v_16194:
v_16165:
    v_16932 = stack[0];
    v_16932 = qcdr(v_16932);
    v_16932 = qcar(v_16932);
    stack[-3] = v_16932;
v_16214:
    v_16932 = stack[-3];
    if (v_16932 == nil) goto v_16217;
    else goto v_16218;
v_16217:
    goto v_16213;
v_16218:
    v_16932 = stack[-3];
    v_16932 = qcar(v_16932);
    if (v_16932 == nil) goto v_16227;
    else goto v_16228;
v_16227:
    v_16932 = lisp_true;
    goto v_16226;
v_16228:
    goto v_16238;
v_16234:
    v_16932 = stack[-3];
    v_16933 = qcar(v_16932);
    goto v_16235;
v_16236:
    v_16932 = lisp_true;
    goto v_16237;
v_16238:
    goto v_16234;
v_16235:
    goto v_16236;
v_16237:
    v_16932 = (v_16933 == v_16932 ? lisp_true : nil);
    goto v_16226;
    v_16932 = nil;
v_16226:
    if (v_16932 == nil) goto v_16224;
    v_16932 = stack[-3];
    v_16932 = qcar(v_16932);
    fn = elt(env, 49); // rsverr
    v_16932 = (*qfn1(fn))(fn, v_16932);
    env = stack[-10];
    goto v_16222;
v_16224:
v_16222:
    v_16932 = stack[-3];
    v_16932 = qcdr(v_16932);
    stack[-3] = v_16932;
    goto v_16214;
v_16213:
    v_16932 = stack[0];
    v_16932 = qcdr(v_16932);
    v_16932 = qcar(v_16932);
    stack[-3] = v_16932;
v_16253:
    v_16932 = stack[-3];
    if (v_16932 == nil) goto v_16256;
    else goto v_16257;
v_16256:
    goto v_16252;
v_16257:
    v_16932 = stack[-3];
    v_16932 = qcar(v_16932);
    v_16932 = Lsymbol_specialp(nil, v_16932);
    env = stack[-10];
    if (v_16932 == nil) goto v_16264;
    else goto v_16262;
v_16264:
    v_16932 = stack[-3];
    v_16932 = qcar(v_16932);
    v_16932 = Lsymbol_globalp(nil, v_16932);
    env = stack[-10];
    if (v_16932 == nil) goto v_16268;
    else goto v_16262;
v_16268:
    goto v_16263;
v_16262:
    goto v_16277;
v_16273:
    v_16932 = stack[-3];
    v_16933 = qcar(v_16932);
    goto v_16274;
v_16275:
    v_16932 = stack[-8];
    goto v_16276;
v_16277:
    goto v_16273;
v_16274:
    goto v_16275;
v_16276:
    v_16932 = cons(v_16933, v_16932);
    env = stack[-10];
    stack[-8] = v_16932;
    goto v_16261;
v_16263:
v_16261:
    v_16932 = stack[-3];
    v_16932 = qcdr(v_16932);
    stack[-3] = v_16932;
    goto v_16253;
v_16252:
    v_16932 = stack[0];
    v_16932 = qcdr(v_16932);
    v_16932 = qcar(v_16932);
    stack[-3] = v_16932;
    v_16932 = stack[0];
    v_16932 = qcdr(v_16932);
    v_16932 = qcdr(v_16932);
    v_16932 = qcar(v_16932);
    stack[-7] = v_16932;
    goto v_16299;
v_16295:
    v_16933 = stack[-7];
    goto v_16296;
v_16297:
    v_16932 = elt(env, 9); // rblock
    goto v_16298;
v_16299:
    goto v_16295;
v_16296:
    goto v_16297;
v_16298:
    if (!consp(v_16933)) goto v_16293;
    v_16933 = qcar(v_16933);
    if (v_16933 == v_16932) goto v_16292;
    else goto v_16293;
v_16292:
    v_16932 = stack[-7];
    v_16932 = qcdr(v_16932);
    v_16932 = qcar(v_16932);
    goto v_16291;
v_16293:
    v_16932 = nil;
    goto v_16291;
    v_16932 = nil;
v_16291:
    stack[0] = v_16932;
    goto v_16317;
v_16309:
    v_16935 = stack[-3];
    goto v_16310;
v_16311:
    v_16934 = stack[0];
    goto v_16312;
v_16313:
    v_16933 = stack[-1];
    goto v_16314;
v_16315:
    v_16932 = stack[-2];
    goto v_16316;
v_16317:
    goto v_16309;
v_16310:
    goto v_16311;
v_16312:
    goto v_16313;
v_16314:
    goto v_16315;
v_16316:
    fn = elt(env, 50); // pairxvars
    v_16932 = (*qfnn(fn))(fn, 4, v_16935, v_16934, v_16933, v_16932);
    env = stack[-10];
    stack[-1] = v_16932;
    v_16932 = stack[0];
    if (v_16932 == nil) goto v_16325;
    goto v_16332;
v_16328:
    v_16932 = stack[-7];
    stack[0] = qcar(v_16932);
    goto v_16329;
v_16330:
    goto v_16340;
v_16336:
    v_16932 = stack[-7];
    v_16933 = qcdr(v_16932);
    goto v_16337;
v_16338:
    v_16932 = stack[-1];
    v_16932 = qcdr(v_16932);
    goto v_16339;
v_16340:
    goto v_16336;
v_16337:
    goto v_16338;
v_16339:
    fn = elt(env, 51); // rplaca!*
    v_16932 = (*qfn2(fn))(fn, v_16933, v_16932);
    env = stack[-10];
    goto v_16331;
v_16332:
    goto v_16328;
v_16329:
    goto v_16330;
v_16331:
    v_16932 = cons(stack[0], v_16932);
    env = stack[-10];
    stack[-7] = v_16932;
    goto v_16323;
v_16325:
v_16323:
    goto v_16354;
v_16350:
    v_16933 = stack[-5];
    goto v_16351;
v_16352:
    v_16932 = elt(env, 10); // formc
    goto v_16353;
v_16354:
    goto v_16350;
v_16351:
    goto v_16352;
v_16353:
    v_16932 = Lflagp(nil, v_16933, v_16932);
    env = stack[-10];
    if (v_16932 == nil) goto v_16348;
    goto v_16364;
v_16358:
    v_16934 = stack[-7];
    goto v_16359;
v_16360:
    v_16932 = stack[-1];
    v_16933 = qcar(v_16932);
    goto v_16361;
v_16362:
    v_16932 = stack[-2];
    goto v_16363;
v_16364:
    goto v_16358;
v_16359:
    goto v_16360;
v_16361:
    goto v_16362;
v_16363:
    fn = elt(env, 10); // formc
    v_16932 = (*qfnn(fn))(fn, 3, v_16934, v_16933, v_16932);
    env = stack[-10];
    goto v_16346;
v_16348:
    goto v_16378;
v_16372:
    v_16934 = stack[-7];
    goto v_16373;
v_16374:
    v_16932 = stack[-1];
    v_16933 = qcar(v_16932);
    goto v_16375;
v_16376:
    v_16932 = stack[-2];
    goto v_16377;
v_16378:
    goto v_16372;
v_16373:
    goto v_16374;
v_16375:
    goto v_16376;
v_16377:
    fn = elt(env, 52); // form1
    v_16932 = (*qfnn(fn))(fn, 3, v_16934, v_16933, v_16932);
    env = stack[-10];
    goto v_16346;
    v_16932 = nil;
v_16346:
    stack[-7] = v_16932;
    v_16932 = qvalue(elt(env, 11)); // !*noinlines
    if (v_16932 == nil) goto v_16386;
    goto v_16394;
v_16390:
    v_16933 = stack[-4];
    goto v_16391;
v_16392:
    v_16932 = elt(env, 12); // inline
    goto v_16393;
v_16394:
    goto v_16390;
v_16391:
    goto v_16392;
v_16393:
    if (v_16933 == v_16932) goto v_16389;
    else goto v_16386;
v_16389:
    v_16932 = elt(env, 13); // expr
    stack[-4] = v_16932;
    goto v_16384;
v_16386:
v_16384:
    v_16932 = stack[-8];
    if (v_16932 == nil) goto v_16401;
    goto v_16409;
v_16405:
    v_16933 = stack[-4];
    goto v_16406;
v_16407:
    v_16932 = elt(env, 14); // (expr fexpr macro)
    goto v_16408;
v_16409:
    goto v_16405;
v_16406:
    goto v_16407;
v_16408:
    v_16932 = Lmemq(nil, v_16933, v_16932);
    if (v_16932 == nil) goto v_16401;
    goto v_16420;
v_16414:
    stack[-1] = elt(env, 15); // progn
    goto v_16415;
v_16416:
    goto v_16427;
v_16423:
    stack[0] = elt(env, 16); // declare
    goto v_16424;
v_16425:
    goto v_16434;
v_16430:
    v_16933 = elt(env, 17); // special
    goto v_16431;
v_16432:
    v_16932 = stack[-8];
    goto v_16433;
v_16434:
    goto v_16430;
v_16431:
    goto v_16432;
v_16433:
    v_16932 = cons(v_16933, v_16932);
    env = stack[-10];
    goto v_16426;
v_16427:
    goto v_16423;
v_16424:
    goto v_16425;
v_16426:
    v_16933 = list2(stack[0], v_16932);
    env = stack[-10];
    goto v_16417;
v_16418:
    v_16932 = stack[-7];
    goto v_16419;
v_16420:
    goto v_16414;
v_16415:
    goto v_16416;
v_16417:
    goto v_16418;
v_16419:
    v_16932 = list3(stack[-1], v_16933, v_16932);
    env = stack[-10];
    stack[-7] = v_16932;
    goto v_16399;
v_16401:
v_16399:
    v_16932 = stack[-7];
    stack[-8] = v_16932;
    goto v_16447;
v_16443:
    v_16933 = stack[-4];
    goto v_16444;
v_16445:
    v_16932 = elt(env, 12); // inline
    goto v_16446;
v_16447:
    goto v_16443;
v_16444:
    goto v_16445;
v_16446:
    if (v_16933 == v_16932) goto v_16441;
    else goto v_16442;
v_16441:
    goto v_16460;
v_16454:
    v_16934 = elt(env, 18); // lambda
    goto v_16455;
v_16456:
    v_16933 = stack[-3];
    goto v_16457;
v_16458:
    v_16932 = stack[-7];
    goto v_16459;
v_16460:
    goto v_16454;
v_16455:
    goto v_16456;
v_16457:
    goto v_16458;
v_16459:
    v_16932 = list3(v_16934, v_16933, v_16932);
    env = stack[-10];
    stack[0] = v_16932;
    goto v_16472;
v_16468:
    v_16934 = stack[0];
    goto v_16469;
v_16470:
    goto v_16479;
v_16475:
    v_16933 = stack[-5];
    goto v_16476;
v_16477:
    v_16932 = elt(env, 12); // inline
    goto v_16478;
v_16479:
    goto v_16475;
v_16476:
    goto v_16477;
v_16478:
    v_16932 = get(v_16933, v_16932);
    env = stack[-10];
    goto v_16471;
v_16472:
    goto v_16468;
v_16469:
    goto v_16470;
v_16471:
    if (equal(v_16934, v_16932)) goto v_16467;
    v_16932 = Lposn(nil, 0);
    env = stack[-10];
    v_16932 = (LispObject)zerop(v_16932);
    v_16932 = v_16932 ? lisp_true : nil;
    env = stack[-10];
    if (v_16932 == nil) goto v_16484;
    else goto v_16485;
v_16484:
    v_16932 = Lterpri(nil, 0);
    env = stack[-10];
    goto v_16483;
v_16485:
v_16483:
    v_16932 = elt(env, 19); // "+++ Record new inline definition:"
    v_16932 = Lprinc(nil, v_16932);
    env = stack[-10];
    v_16932 = Lterpri(nil, 0);
    env = stack[-10];
    goto v_16502;
v_16494:
    v_16935 = elt(env, 20); // de
    goto v_16495;
v_16496:
    v_16934 = stack[-5];
    goto v_16497;
v_16498:
    v_16933 = stack[-3];
    goto v_16499;
v_16500:
    v_16932 = stack[-7];
    goto v_16501;
v_16502:
    goto v_16494;
v_16495:
    goto v_16496;
v_16497:
    goto v_16498;
v_16499:
    goto v_16500;
v_16501:
    v_16932 = list4(v_16935, v_16934, v_16933, v_16932);
    env = stack[-10];
    v_16932 = Lprint(nil, v_16932);
    env = stack[-10];
    goto v_16514;
v_16508:
    v_16934 = stack[-5];
    goto v_16509;
v_16510:
    v_16933 = stack[0];
    goto v_16511;
v_16512:
    v_16932 = qvalue(elt(env, 21)); // new_inline_definitions
    goto v_16513;
v_16514:
    goto v_16508;
v_16509:
    goto v_16510;
v_16511:
    goto v_16512;
v_16513:
    v_16932 = acons(v_16934, v_16933, v_16932);
    env = stack[-10];
    qvalue(elt(env, 21)) = v_16932; // new_inline_definitions
    goto v_16465;
v_16467:
v_16465:
    goto v_16440;
v_16442:
v_16440:
    goto v_16531;
v_16527:
    v_16933 = stack[-4];
    goto v_16528;
v_16529:
    v_16932 = elt(env, 12); // inline
    goto v_16530;
v_16531:
    goto v_16527;
v_16528:
    goto v_16529;
v_16530:
    if (v_16933 == v_16932) goto v_16526;
    goto v_16539;
v_16535:
    v_16933 = stack[-5];
    goto v_16536;
v_16537:
    v_16932 = elt(env, 12); // inline
    goto v_16538;
v_16539:
    goto v_16535;
v_16536:
    goto v_16537;
v_16538:
    v_16932 = get(v_16933, v_16932);
    env = stack[-10];
    goto v_16524;
v_16526:
    v_16932 = nil;
    goto v_16524;
    v_16932 = nil;
v_16524:
    if (v_16932 == nil) goto v_16522;
    else goto v_16520;
v_16522:
    goto v_16554;
v_16550:
    v_16933 = stack[-4];
    goto v_16551;
v_16552:
    v_16932 = elt(env, 22); // smacro
    goto v_16553;
v_16554:
    goto v_16550;
v_16551:
    goto v_16552;
v_16553:
    if (v_16933 == v_16932) goto v_16549;
    goto v_16562;
v_16558:
    v_16933 = stack[-5];
    goto v_16559;
v_16560:
    v_16932 = elt(env, 22); // smacro
    goto v_16561;
v_16562:
    goto v_16558;
v_16559:
    goto v_16560;
v_16561:
    v_16932 = get(v_16933, v_16932);
    env = stack[-10];
    goto v_16547;
v_16549:
    v_16932 = nil;
    goto v_16547;
    v_16932 = nil;
v_16547:
    if (v_16932 == nil) goto v_16545;
    else goto v_16520;
v_16545:
    goto v_16521;
v_16520:
    goto v_16576;
v_16570:
    v_16934 = elt(env, 23); // "SMACRO/INLINE"
    goto v_16571;
v_16572:
    v_16933 = stack[-5];
    goto v_16573;
v_16574:
    v_16932 = elt(env, 8); // "redefined"
    goto v_16575;
v_16576:
    goto v_16570;
v_16571:
    goto v_16572;
v_16573:
    goto v_16574;
v_16575:
    v_16932 = list3(v_16934, v_16933, v_16932);
    env = stack[-10];
    fn = elt(env, 47); // lprim
    v_16932 = (*qfn1(fn))(fn, v_16932);
    env = stack[-10];
    goto v_16519;
v_16521:
v_16519:
    goto v_16587;
v_16581:
    v_16934 = stack[-3];
    goto v_16582;
v_16583:
    v_16933 = stack[-7];
    goto v_16584;
v_16585:
    v_16932 = stack[-2];
    goto v_16586;
v_16587:
    goto v_16581;
v_16582:
    goto v_16583;
v_16584:
    goto v_16585;
v_16586:
    fn = elt(env, 53); // symbvarlst
    v_16932 = (*qfnn(fn))(fn, 3, v_16934, v_16933, v_16932);
    env = stack[-10];
    goto v_16599;
v_16595:
    v_16933 = stack[-4];
    goto v_16596;
v_16597:
    v_16932 = elt(env, 13); // expr
    goto v_16598;
v_16599:
    goto v_16595;
v_16596:
    goto v_16597;
v_16598:
    if (v_16933 == v_16932) goto v_16593;
    else goto v_16594;
v_16593:
    goto v_16611;
v_16603:
    v_16935 = elt(env, 20); // de
    goto v_16604;
v_16605:
    v_16934 = stack[-5];
    goto v_16606;
v_16607:
    v_16933 = stack[-3];
    goto v_16608;
v_16609:
    v_16932 = stack[-7];
    goto v_16610;
v_16611:
    goto v_16603;
v_16604:
    goto v_16605;
v_16606:
    goto v_16607;
v_16608:
    goto v_16609;
v_16610:
    v_16932 = list4(v_16935, v_16934, v_16933, v_16932);
    env = stack[-10];
    stack[-7] = v_16932;
    goto v_16592;
v_16594:
    goto v_16622;
v_16618:
    v_16933 = stack[-4];
    goto v_16619;
v_16620:
    v_16932 = elt(env, 24); // fexpr
    goto v_16621;
v_16622:
    goto v_16618;
v_16619:
    goto v_16620;
v_16621:
    if (v_16933 == v_16932) goto v_16616;
    else goto v_16617;
v_16616:
    goto v_16634;
v_16626:
    v_16935 = elt(env, 25); // df
    goto v_16627;
v_16628:
    v_16934 = stack[-5];
    goto v_16629;
v_16630:
    v_16933 = stack[-3];
    goto v_16631;
v_16632:
    v_16932 = stack[-7];
    goto v_16633;
v_16634:
    goto v_16626;
v_16627:
    goto v_16628;
v_16629:
    goto v_16630;
v_16631:
    goto v_16632;
v_16633:
    v_16932 = list4(v_16935, v_16934, v_16933, v_16932);
    env = stack[-10];
    stack[-7] = v_16932;
    goto v_16592;
v_16617:
    goto v_16645;
v_16641:
    v_16933 = stack[-4];
    goto v_16642;
v_16643:
    v_16932 = elt(env, 26); // macro
    goto v_16644;
v_16645:
    goto v_16641;
v_16642:
    goto v_16643;
v_16644:
    if (v_16933 == v_16932) goto v_16639;
    else goto v_16640;
v_16639:
    goto v_16657;
v_16649:
    v_16935 = elt(env, 27); // dm
    goto v_16650;
v_16651:
    v_16934 = stack[-5];
    goto v_16652;
v_16653:
    v_16933 = stack[-3];
    goto v_16654;
v_16655:
    v_16932 = stack[-7];
    goto v_16656;
v_16657:
    goto v_16649;
v_16650:
    goto v_16651;
v_16652:
    goto v_16653;
v_16654:
    goto v_16655;
v_16656:
    v_16932 = list4(v_16935, v_16934, v_16933, v_16932);
    env = stack[-10];
    stack[-7] = v_16932;
    goto v_16592;
v_16640:
    goto v_16669;
v_16665:
    v_16933 = stack[-4];
    goto v_16666;
v_16667:
    v_16932 = elt(env, 28); // procfn
    goto v_16668;
v_16669:
    goto v_16665;
v_16666:
    goto v_16667;
v_16668:
    v_16932 = get(v_16933, v_16932);
    env = stack[-10];
    stack[0] = v_16932;
    if (v_16932 == nil) goto v_16663;
    goto v_16681;
v_16673:
    v_16935 = stack[0];
    goto v_16674;
v_16675:
    v_16934 = stack[-5];
    goto v_16676;
v_16677:
    v_16933 = stack[-3];
    goto v_16678;
v_16679:
    v_16932 = stack[-7];
    goto v_16680;
v_16681:
    goto v_16673;
v_16674:
    goto v_16675;
v_16676:
    goto v_16677;
v_16678:
    goto v_16679;
v_16680:
    v_16932 = Lapply3(nil, 4, v_16935, v_16934, v_16933, v_16932);
    goto v_16144;
v_16663:
    goto v_16697;
v_16689:
    stack[-9] = elt(env, 29); // putc
    goto v_16690;
v_16691:
    v_16932 = stack[-5];
    stack[-1] = Lmkquote(nil, v_16932);
    env = stack[-10];
    goto v_16692;
v_16693:
    v_16932 = stack[-4];
    stack[0] = Lmkquote(nil, v_16932);
    env = stack[-10];
    goto v_16694;
v_16695:
    goto v_16711;
v_16705:
    v_16934 = elt(env, 18); // lambda
    goto v_16706;
v_16707:
    v_16933 = stack[-3];
    goto v_16708;
v_16709:
    v_16932 = stack[-7];
    goto v_16710;
v_16711:
    goto v_16705;
v_16706:
    goto v_16707;
v_16708:
    goto v_16709;
v_16710:
    v_16932 = list3(v_16934, v_16933, v_16932);
    env = stack[-10];
    v_16932 = Lmkquote(nil, v_16932);
    env = stack[-10];
    goto v_16696;
v_16697:
    goto v_16689;
v_16690:
    goto v_16691;
v_16692:
    goto v_16693;
v_16694:
    goto v_16695;
v_16696:
    v_16932 = list4(stack[-9], stack[-1], stack[0], v_16932);
    env = stack[-10];
    stack[-7] = v_16932;
    goto v_16592;
v_16592:
    goto v_16723;
v_16719:
    v_16933 = stack[-2];
    goto v_16720;
v_16721:
    v_16932 = elt(env, 30); // symbolic
    goto v_16722;
v_16723:
    goto v_16719;
v_16720:
    goto v_16721;
v_16722:
    if (v_16933 == v_16932) goto v_16718;
    goto v_16731;
v_16727:
    goto v_16739;
v_16733:
    stack[-1] = elt(env, 31); // flag
    goto v_16734;
v_16735:
    v_16932 = stack[-5];
    v_16932 = ncons(v_16932);
    env = stack[-10];
    stack[0] = Lmkquote(nil, v_16932);
    env = stack[-10];
    goto v_16736;
v_16737:
    v_16932 = elt(env, 32); // opfn
    v_16932 = Lmkquote(nil, v_16932);
    env = stack[-10];
    goto v_16738;
v_16739:
    goto v_16733;
v_16734:
    goto v_16735;
v_16736:
    goto v_16737;
v_16738:
    v_16933 = list3(stack[-1], stack[0], v_16932);
    env = stack[-10];
    goto v_16728;
v_16729:
    v_16932 = stack[-7];
    goto v_16730;
v_16731:
    goto v_16727;
v_16728:
    goto v_16729;
v_16730:
    fn = elt(env, 54); // mkprogn
    v_16932 = (*qfn2(fn))(fn, v_16933, v_16932);
    env = stack[-10];
    stack[-7] = v_16932;
    goto v_16716;
v_16718:
v_16716:
    v_16932 = qvalue(elt(env, 33)); // !*argnochk
    if (v_16932 == nil) goto v_16750;
    goto v_16758;
v_16754:
    v_16933 = stack[-4];
    goto v_16755;
v_16756:
    v_16932 = elt(env, 34); // (expr inline smacro)
    goto v_16757;
v_16758:
    goto v_16754;
v_16755:
    goto v_16756;
v_16757:
    v_16932 = Lmemq(nil, v_16933, v_16932);
    if (v_16932 == nil) goto v_16750;
    v_16932 = stack[-5];
    if (!symbolp(v_16932)) v_16932 = nil;
    else { v_16932 = qfastgets(v_16932);
           if (v_16932 != nil) { v_16932 = elt(v_16932, 42); // number!-of!-args
#ifdef RECORD_GET
             if (v_16932 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v_16932 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v_16932 == SPID_NOPROP) v_16932 = nil; }}
#endif
    stack[-9] = v_16932;
    if (v_16932 == nil) goto v_16765;
    goto v_16779;
v_16775:
    v_16933 = stack[-5];
    goto v_16776;
v_16777:
    v_16932 = elt(env, 35); // variadic
    goto v_16778;
v_16779:
    goto v_16775;
v_16776:
    goto v_16777;
v_16778:
    v_16932 = Lflagp(nil, v_16933, v_16932);
    env = stack[-10];
    if (v_16932 == nil) goto v_16772;
    else goto v_16773;
v_16772:
    goto v_16787;
v_16783:
    stack[0] = stack[-9];
    goto v_16784;
v_16785:
    v_16932 = stack[-3];
    v_16932 = Llength(nil, v_16932);
    env = stack[-10];
    goto v_16786;
v_16787:
    goto v_16783;
v_16784:
    goto v_16785;
v_16786:
    v_16932 = Lneq(nil, stack[0], v_16932);
    env = stack[-10];
    goto v_16771;
v_16773:
    v_16932 = nil;
    goto v_16771;
    v_16932 = nil;
v_16771:
    if (v_16932 == nil) goto v_16765;
    v_16932 = qvalue(elt(env, 36)); // !*strict_argcount
    if (v_16932 == nil) goto v_16797;
    goto v_16807;
v_16801:
    v_16934 = elt(env, 37); // "Definition of"
    goto v_16802;
v_16803:
    v_16933 = stack[-5];
    goto v_16804;
v_16805:
    v_16932 = elt(env, 38); // "different count from args previously called with"
    goto v_16806;
v_16807:
    goto v_16801;
v_16802:
    goto v_16803;
v_16804:
    goto v_16805;
v_16806:
    v_16932 = list3(v_16934, v_16933, v_16932);
    env = stack[-10];
    fn = elt(env, 55); // lprie
    v_16932 = (*qfn1(fn))(fn, v_16932);
    env = stack[-10];
    goto v_16795;
v_16797:
    goto v_16823;
v_16815:
    stack[-2] = stack[-5];
    goto v_16816;
v_16817:
    stack[-1] = elt(env, 39); // "defined with"
    goto v_16818;
v_16819:
    v_16932 = stack[-3];
    stack[0] = Llength(nil, v_16932);
    env = stack[-10];
    goto v_16820;
v_16821:
    goto v_16835;
v_16829:
    v_16934 = elt(env, 40); // "but previously called with"
    goto v_16830;
v_16831:
    v_16933 = stack[-9];
    goto v_16832;
v_16833:
    v_16932 = elt(env, 41); // "arguments"
    goto v_16834;
v_16835:
    goto v_16829;
v_16830:
    goto v_16831;
v_16832:
    goto v_16833;
v_16834:
    v_16932 = list3(v_16934, v_16933, v_16932);
    env = stack[-10];
    goto v_16822;
v_16823:
    goto v_16815;
v_16816:
    goto v_16817;
v_16818:
    goto v_16819;
v_16820:
    goto v_16821;
v_16822:
    v_16932 = list3star(stack[-2], stack[-1], stack[0], v_16932);
    env = stack[-10];
    fn = elt(env, 47); // lprim
    v_16932 = (*qfn1(fn))(fn, v_16932);
    env = stack[-10];
    goto v_16795;
v_16795:
    goto v_16763;
v_16765:
v_16763:
    goto v_16844;
v_16840:
    goto v_16854;
v_16846:
    stack[-2] = elt(env, 42); // put
    goto v_16847;
v_16848:
    v_16932 = stack[-5];
    stack[-1] = Lmkquote(nil, v_16932);
    env = stack[-10];
    goto v_16849;
v_16850:
    v_16932 = elt(env, 43); // number!-of!-args
    stack[0] = Lmkquote(nil, v_16932);
    env = stack[-10];
    goto v_16851;
v_16852:
    v_16932 = stack[-3];
    v_16932 = Llength(nil, v_16932);
    env = stack[-10];
    goto v_16853;
v_16854:
    goto v_16846;
v_16847:
    goto v_16848;
v_16849:
    goto v_16850;
v_16851:
    goto v_16852;
v_16853:
    v_16933 = list4(stack[-2], stack[-1], stack[0], v_16932);
    env = stack[-10];
    goto v_16841;
v_16842:
    v_16932 = stack[-7];
    goto v_16843;
v_16844:
    goto v_16840;
v_16841:
    goto v_16842;
v_16843:
    fn = elt(env, 54); // mkprogn
    v_16932 = (*qfn2(fn))(fn, v_16933, v_16932);
    env = stack[-10];
    stack[-7] = v_16932;
    goto v_16748;
v_16750:
v_16748:
    v_16932 = qvalue(elt(env, 4)); // !*defn
    if (v_16932 == nil) goto v_16866;
    goto v_16874;
v_16870:
    v_16933 = stack[-4];
    goto v_16871;
v_16872:
    v_16932 = elt(env, 44); // (fexpr macro inline smacro)
    goto v_16873;
v_16874:
    goto v_16870;
v_16871:
    goto v_16872;
v_16873:
    v_16932 = Lmemq(nil, v_16933, v_16932);
    if (v_16932 == nil) goto v_16866;
    v_16932 = stack[-7];
    fn = elt(env, 56); // lispeval
    v_16932 = (*qfn1(fn))(fn, v_16932);
    env = stack[-10];
    goto v_16864;
v_16866:
v_16864:
    goto v_16888;
v_16884:
    v_16933 = stack[-4];
    goto v_16885;
v_16886:
    v_16932 = elt(env, 12); // inline
    goto v_16887;
v_16888:
    goto v_16884;
v_16885:
    goto v_16886;
v_16887:
    if (v_16933 == v_16932) goto v_16882;
    else goto v_16883;
v_16882:
    goto v_16897;
v_16893:
    goto v_16907;
v_16899:
    v_16935 = elt(env, 20); // de
    goto v_16900;
v_16901:
    v_16934 = stack[-5];
    goto v_16902;
v_16903:
    v_16933 = stack[-3];
    goto v_16904;
v_16905:
    v_16932 = stack[-8];
    goto v_16906;
v_16907:
    goto v_16899;
v_16900:
    goto v_16901;
v_16902:
    goto v_16903;
v_16904:
    goto v_16905;
v_16906:
    v_16933 = list4(v_16935, v_16934, v_16933, v_16932);
    env = stack[-10];
    goto v_16894;
v_16895:
    v_16932 = stack[-7];
    goto v_16896;
v_16897:
    goto v_16893;
v_16894:
    goto v_16895;
v_16896:
    fn = elt(env, 54); // mkprogn
    v_16932 = (*qfn2(fn))(fn, v_16933, v_16932);
    env = stack[-10];
    v_16932 = Lprint(nil, v_16932);
    env = stack[-10];
    stack[-7] = v_16932;
    goto v_16881;
v_16883:
v_16881:
    v_16932 = qvalue(elt(env, 45)); // !*micro!-version
    if (v_16932 == nil) goto v_16916;
    goto v_16924;
v_16920:
    v_16932 = stack[-4];
    goto v_16921;
v_16922:
    v_16933 = elt(env, 46); // (fexpr macro smacro)
    goto v_16923;
v_16924:
    goto v_16920;
v_16921:
    goto v_16922;
v_16923:
    v_16932 = Lmemq(nil, v_16932, v_16933);
    if (v_16932 == nil) goto v_16916;
    v_16932 = nil;
    goto v_16914;
v_16916:
    v_16932 = stack[-7];
    goto v_16914;
    v_16932 = nil;
v_16914:
v_16144:
    ;}  // end of a binding scope
    return onevalue(v_16932);
}



// Code for pushback

static LispObject CC_pushback(LispObject env,
                         LispObject v_16129, LispObject v_16130)
{
    env = qenv(env);
    LispObject v_16173, v_16174;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16130,v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16129,v_16130);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_16130;
    v_16173 = v_16129;
// end of prologue
v_16138:
    v_16174 = v_16173;
    v_16174 = qcar(v_16174);
    if (v_16174 == nil) goto v_16141;
    else goto v_16142;
v_16141:
    goto v_16137;
v_16142:
    v_16173 = qcdr(v_16173);
    goto v_16138;
v_16137:
    goto v_16154;
v_16150:
    goto v_16160;
v_16156:
    stack[-1] = v_16173;
    goto v_16157;
v_16158:
    goto v_16167;
v_16163:
    v_16174 = v_16173;
    v_16174 = qcar(v_16174);
    goto v_16164;
v_16165:
    v_16173 = qcdr(v_16173);
    goto v_16166;
v_16167:
    goto v_16163;
v_16164:
    goto v_16165;
v_16166:
    v_16173 = cons(v_16174, v_16173);
    env = stack[-2];
    goto v_16159;
v_16160:
    goto v_16156;
v_16157:
    goto v_16158;
v_16159:
    v_16174 = Lrplacd(nil, stack[-1], v_16173);
    env = stack[-2];
    goto v_16151;
v_16152:
    v_16173 = stack[0];
    goto v_16153;
v_16154:
    goto v_16150;
v_16151:
    goto v_16152;
v_16153:
    v_16173 = Lrplaca(nil, v_16174, v_16173);
    v_16173 = nil;
    return onevalue(v_16173);
}



// Code for cl_rename!-vars

static LispObject CC_cl_renameKvars(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16141;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16129);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_16141 = v_16129;
// end of prologue
    goto v_16136;
v_16132:
    stack[0] = v_16141;
    goto v_16133;
v_16134:
    fn = elt(env, 1); // cl_replace!-varl
    v_16141 = (*qfn1(fn))(fn, v_16141);
    env = stack[-1];
    goto v_16135;
v_16136:
    goto v_16132;
v_16133:
    goto v_16134;
v_16135:
    fn = elt(env, 2); // cl_rename!-vars1
    v_16141 = (*qfn2(fn))(fn, stack[0], v_16141);
    v_16141 = qcar(v_16141);
    return onevalue(v_16141);
}



// Code for pasf_pdp

static LispObject CC_pasf_pdp(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16350, v_16351, v_16352;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16129);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_16129;
// end of prologue
    v_16350 = stack[0];
    if (!consp(v_16350)) goto v_16141;
    else goto v_16142;
v_16141:
    v_16350 = lisp_true;
    goto v_16140;
v_16142:
    v_16350 = stack[0];
    v_16350 = qcar(v_16350);
    v_16350 = (consp(v_16350) ? nil : lisp_true);
    goto v_16140;
    v_16350 = nil;
v_16140:
    if (v_16350 == nil) goto v_16138;
    v_16350 = stack[0];
    if (v_16350 == nil) goto v_16152;
    else goto v_16153;
v_16152:
    v_16350 = elt(env, 1); // indef
    goto v_16151;
v_16153:
    goto v_16163;
v_16159:
    v_16351 = stack[0];
    goto v_16160;
v_16161:
    v_16350 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16162;
v_16163:
    goto v_16159;
v_16160:
    goto v_16161;
v_16162:
    v_16350 = (LispObject)lessp2(v_16351, v_16350);
    v_16350 = v_16350 ? lisp_true : nil;
    env = stack[-2];
    if (v_16350 == nil) goto v_16157;
    v_16350 = elt(env, 2); // ndef
    goto v_16151;
v_16157:
    goto v_16174;
v_16170:
    v_16351 = stack[0];
    goto v_16171;
v_16172:
    v_16350 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16173;
v_16174:
    goto v_16170;
v_16171:
    goto v_16172;
v_16173:
    v_16350 = (LispObject)greaterp2(v_16351, v_16350);
    v_16350 = v_16350 ? lisp_true : nil;
    env = stack[-2];
    if (v_16350 == nil) goto v_16168;
    v_16350 = elt(env, 3); // pdef
    goto v_16151;
v_16168:
    v_16350 = elt(env, 1); // indef
    goto v_16151;
    v_16350 = nil;
v_16151:
    goto v_16134;
v_16138:
    v_16350 = stack[0];
    v_16350 = qcar(v_16350);
    v_16350 = qcar(v_16350);
    v_16350 = qcdr(v_16350);
    v_16350 = Levenp(nil, v_16350);
    env = stack[-2];
    if (v_16350 == nil) goto v_16184;
    v_16350 = stack[0];
    v_16350 = qcar(v_16350);
    v_16350 = qcdr(v_16350);
    v_16350 = CC_pasf_pdp(elt(env, 0), v_16350);
    env = stack[-2];
    stack[-1] = v_16350;
    v_16350 = stack[0];
    v_16350 = qcdr(v_16350);
    v_16350 = CC_pasf_pdp(elt(env, 0), v_16350);
    env = stack[-2];
    v_16352 = v_16350;
    v_16350 = v_16352;
    if (v_16350 == nil) goto v_16203;
    else goto v_16204;
v_16203:
    goto v_16214;
v_16210:
    v_16351 = stack[-1];
    goto v_16211;
v_16212:
    v_16350 = elt(env, 4); // psdef
    goto v_16213;
v_16214:
    goto v_16210;
v_16211:
    goto v_16212;
v_16213:
    if (v_16351 == v_16350) goto v_16208;
    else goto v_16209;
v_16208:
    v_16350 = lisp_true;
    goto v_16207;
v_16209:
    goto v_16224;
v_16220:
    v_16351 = stack[-1];
    goto v_16221;
v_16222:
    v_16350 = elt(env, 3); // pdef
    goto v_16223;
v_16224:
    goto v_16220;
v_16221:
    goto v_16222;
v_16223:
    v_16350 = (v_16351 == v_16350 ? lisp_true : nil);
    goto v_16207;
    v_16350 = nil;
v_16207:
    goto v_16202;
v_16204:
    v_16350 = nil;
    goto v_16202;
    v_16350 = nil;
v_16202:
    if (v_16350 == nil) goto v_16200;
    v_16350 = elt(env, 4); // psdef
    goto v_16134;
v_16200:
    v_16350 = v_16352;
    if (v_16350 == nil) goto v_16238;
    else goto v_16239;
v_16238:
    goto v_16249;
v_16245:
    v_16351 = stack[-1];
    goto v_16246;
v_16247:
    v_16350 = elt(env, 5); // nsdef
    goto v_16248;
v_16249:
    goto v_16245;
v_16246:
    goto v_16247;
v_16248:
    if (v_16351 == v_16350) goto v_16243;
    else goto v_16244;
v_16243:
    v_16350 = lisp_true;
    goto v_16242;
v_16244:
    goto v_16259;
v_16255:
    v_16351 = stack[-1];
    goto v_16256;
v_16257:
    v_16350 = elt(env, 2); // ndef
    goto v_16258;
v_16259:
    goto v_16255;
v_16256:
    goto v_16257;
v_16258:
    v_16350 = (v_16351 == v_16350 ? lisp_true : nil);
    goto v_16242;
    v_16350 = nil;
v_16242:
    goto v_16237;
v_16239:
    v_16350 = nil;
    goto v_16237;
    v_16350 = nil;
v_16237:
    if (v_16350 == nil) goto v_16235;
    v_16350 = elt(env, 5); // nsdef
    goto v_16134;
v_16235:
    goto v_16279;
v_16275:
    v_16351 = v_16352;
    goto v_16276;
v_16277:
    v_16350 = elt(env, 3); // pdef
    goto v_16278;
v_16279:
    goto v_16275;
v_16276:
    goto v_16277;
v_16278:
    if (v_16351 == v_16350) goto v_16273;
    else goto v_16274;
v_16273:
    goto v_16290;
v_16286:
    v_16351 = stack[-1];
    goto v_16287;
v_16288:
    v_16350 = elt(env, 4); // psdef
    goto v_16289;
v_16290:
    goto v_16286;
v_16287:
    goto v_16288;
v_16289:
    if (v_16351 == v_16350) goto v_16284;
    else goto v_16285;
v_16284:
    v_16350 = lisp_true;
    goto v_16283;
v_16285:
    goto v_16300;
v_16296:
    v_16351 = stack[-1];
    goto v_16297;
v_16298:
    v_16350 = elt(env, 3); // pdef
    goto v_16299;
v_16300:
    goto v_16296;
v_16297:
    goto v_16298;
v_16299:
    v_16350 = (v_16351 == v_16350 ? lisp_true : nil);
    goto v_16283;
    v_16350 = nil;
v_16283:
    goto v_16272;
v_16274:
    v_16350 = nil;
    goto v_16272;
    v_16350 = nil;
v_16272:
    if (v_16350 == nil) goto v_16270;
    v_16350 = elt(env, 3); // pdef
    goto v_16134;
v_16270:
    goto v_16320;
v_16316:
    v_16351 = v_16352;
    goto v_16317;
v_16318:
    v_16350 = elt(env, 2); // ndef
    goto v_16319;
v_16320:
    goto v_16316;
v_16317:
    goto v_16318;
v_16319:
    if (v_16351 == v_16350) goto v_16314;
    else goto v_16315;
v_16314:
    goto v_16331;
v_16327:
    v_16351 = stack[-1];
    goto v_16328;
v_16329:
    v_16350 = elt(env, 5); // nsdef
    goto v_16330;
v_16331:
    goto v_16327;
v_16328:
    goto v_16329;
v_16330:
    if (v_16351 == v_16350) goto v_16325;
    else goto v_16326;
v_16325:
    v_16350 = lisp_true;
    goto v_16324;
v_16326:
    goto v_16341;
v_16337:
    v_16351 = stack[-1];
    goto v_16338;
v_16339:
    v_16350 = elt(env, 2); // ndef
    goto v_16340;
v_16341:
    goto v_16337;
v_16338:
    goto v_16339;
v_16340:
    v_16350 = (v_16351 == v_16350 ? lisp_true : nil);
    goto v_16324;
    v_16350 = nil;
v_16324:
    goto v_16313;
v_16315:
    v_16350 = nil;
    goto v_16313;
    v_16350 = nil;
v_16313:
    if (v_16350 == nil) goto v_16311;
    v_16350 = elt(env, 2); // ndef
    goto v_16134;
v_16311:
    goto v_16182;
v_16184:
v_16182:
    v_16350 = elt(env, 1); // indef
v_16134:
    return onevalue(v_16350);
}



// Code for omfir

static LispObject CC_omfir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16162, v_16163;
    LispObject fn;
    argcheck(nargs, 0, "omfir");
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
    goto v_16138;
v_16134:
    v_16163 = qvalue(elt(env, 1)); // atts
    goto v_16135;
v_16136:
    v_16162 = elt(env, 2); // dec
    goto v_16137;
v_16138:
    goto v_16134;
v_16135:
    goto v_16136;
v_16137:
    fn = elt(env, 5); // find
    v_16162 = (*qfn2(fn))(fn, v_16163, v_16162);
    env = stack[-1];
    stack[0] = v_16162;
    goto v_16150;
v_16146:
    v_16163 = qvalue(elt(env, 1)); // atts
    goto v_16147;
v_16148:
    v_16162 = elt(env, 3); // name
    goto v_16149;
v_16150:
    goto v_16146;
v_16147:
    goto v_16148;
v_16149:
    fn = elt(env, 5); // find
    v_16162 = (*qfn2(fn))(fn, v_16163, v_16162);
    env = stack[-1];
    if (v_16162 == nil) goto v_16144;
    goto v_16158;
v_16154:
    v_16163 = elt(env, 4); // "wrong att"
    goto v_16155;
v_16156:
    v_16162 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_16157;
v_16158:
    goto v_16154;
v_16155:
    goto v_16156;
v_16157:
    fn = elt(env, 6); // errorml
    v_16162 = (*qfn2(fn))(fn, v_16163, v_16162);
    goto v_16142;
v_16144:
v_16142:
    v_16162 = stack[0];
    return onevalue(v_16162);
}



// Code for initarg

static LispObject CC_initarg(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16350, v_16351;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16129);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_16129;
// end of prologue
    v_16350 = qvalue(elt(env, 1)); // op
    if (!symbolp(v_16350)) v_16350 = nil;
    else { v_16350 = qfastgets(v_16350);
           if (v_16350 != nil) { v_16350 = elt(v_16350, 43); // symmetric
#ifdef RECORD_GET
             if (v_16350 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v_16350 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v_16350 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v_16350 == SPID_NOPROP) v_16350 = nil; else v_16350 = lisp_true; }}
#endif
    qvalue(elt(env, 2)) = v_16350; // symm
    goto v_16149;
v_16145:
    v_16350 = qvalue(elt(env, 3)); // p
    stack[0] = Llength(nil, v_16350);
    env = stack[-6];
    goto v_16146;
v_16147:
    v_16350 = qvalue(elt(env, 4)); // r
    v_16350 = Llength(nil, v_16350);
    env = stack[-6];
    goto v_16148;
v_16149:
    goto v_16145;
v_16146:
    goto v_16147;
v_16148:
    v_16350 = difference2(stack[0], v_16350);
    env = stack[-6];
    v_16350 = add1(v_16350);
    env = stack[-6];
    stack[-1] = v_16350;
    v_16350 = qvalue(elt(env, 1)); // op
    fn = elt(env, 14); // ident
    v_16350 = (*qfn1(fn))(fn, v_16350);
    env = stack[-6];
    qvalue(elt(env, 5)) = v_16350; // identity
    v_16350 = qvalue(elt(env, 4)); // r
    v_16350 = qcar(v_16350);
    fn = elt(env, 15); // mgenp
    v_16350 = (*qfn1(fn))(fn, v_16350);
    env = stack[-6];
    stack[-3] = v_16350;
    v_16350 = qvalue(elt(env, 4)); // r
    v_16350 = qcdr(v_16350);
    fn = elt(env, 16); // list!-mgen
    v_16350 = (*qfn1(fn))(fn, v_16350);
    env = stack[-6];
    stack[0] = v_16350;
    goto v_16171;
v_16167:
    v_16351 = qvalue(elt(env, 1)); // op
    goto v_16168;
v_16169:
    v_16350 = elt(env, 6); // assoc
    goto v_16170;
v_16171:
    goto v_16167;
v_16168:
    goto v_16169;
v_16170:
    v_16350 = Lflagp(nil, v_16351, v_16350);
    env = stack[-6];
    if (v_16350 == nil) goto v_16165;
    v_16350 = qvalue(elt(env, 2)); // symm
    if (v_16350 == nil) goto v_16176;
    else goto v_16177;
v_16176:
    v_16350 = nil;
    goto v_16175;
v_16177:
    goto v_16191;
v_16187:
    v_16351 = stack[0];
    goto v_16188;
v_16189:
    v_16350 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16190;
v_16191:
    goto v_16187;
v_16188:
    goto v_16189;
v_16190:
    v_16350 = (LispObject)greaterp2(v_16351, v_16350);
    v_16350 = v_16350 ? lisp_true : nil;
    env = stack[-6];
    if (v_16350 == nil) goto v_16184;
    else goto v_16185;
v_16184:
    v_16350 = nil;
    goto v_16183;
v_16185:
    v_16350 = qvalue(elt(env, 7)); // !*sym!-assoc
    v_16350 = (v_16350 == nil ? lisp_true : nil);
    goto v_16183;
    v_16350 = nil;
v_16183:
    goto v_16175;
    v_16350 = nil;
v_16175:
    v_16350 = (v_16350 == nil ? lisp_true : nil);
    goto v_16163;
v_16165:
    v_16350 = nil;
    goto v_16163;
    v_16350 = nil;
v_16163:
    stack[-5] = v_16350;
    goto v_16212;
v_16208:
    v_16350 = qvalue(elt(env, 4)); // r
    v_16351 = Llength(nil, v_16350);
    env = stack[-6];
    goto v_16209;
v_16210:
    v_16350 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16211;
v_16212:
    goto v_16208;
v_16209:
    goto v_16210;
v_16211:
    v_16350 = (LispObject)greaterp2(v_16351, v_16350);
    v_16350 = v_16350 ? lisp_true : nil;
    env = stack[-6];
    if (v_16350 == nil) goto v_16205;
    else goto v_16206;
v_16205:
    v_16350 = nil;
    goto v_16204;
v_16206:
    v_16350 = stack[-5];
    if (v_16350 == nil) goto v_16221;
    else goto v_16220;
v_16221:
    v_16350 = stack[0];
v_16220:
    goto v_16204;
    v_16350 = nil;
v_16204:
    stack[-2] = v_16350;
    goto v_16232;
v_16228:
    v_16351 = stack[-1];
    goto v_16229;
v_16230:
    v_16350 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16231;
v_16232:
    goto v_16228;
v_16229:
    goto v_16230;
v_16231:
    v_16350 = (LispObject)greaterp2(v_16351, v_16350);
    v_16350 = v_16350 ? lisp_true : nil;
    env = stack[-6];
    if (v_16350 == nil) goto v_16226;
    else goto v_16225;
v_16226:
    v_16350 = qvalue(elt(env, 5)); // identity
    if (v_16350 == nil) goto v_16237;
    else goto v_16238;
v_16237:
    v_16350 = nil;
    goto v_16236;
v_16238:
    goto v_16248;
v_16244:
    v_16350 = qvalue(elt(env, 3)); // p
    v_16351 = Llength(nil, v_16350);
    env = stack[-6];
    goto v_16245;
v_16246:
    v_16350 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16247;
v_16248:
    goto v_16244;
v_16245:
    goto v_16246;
v_16247:
    v_16350 = (LispObject)greaterp2(v_16351, v_16350);
    v_16350 = v_16350 ? lisp_true : nil;
    env = stack[-6];
    goto v_16236;
    v_16350 = nil;
v_16236:
v_16225:
    v_16351 = v_16350;
    v_16350 = stack[-3];
    if (v_16350 == nil) goto v_16254;
    else goto v_16255;
v_16254:
    v_16350 = nil;
    goto v_16253;
v_16255:
    v_16350 = v_16351;
    goto v_16253;
    v_16350 = nil;
v_16253:
    qvalue(elt(env, 8)) = v_16350; // mcontract
    v_16350 = stack[-5];
    if (v_16350 == nil) goto v_16263;
    else goto v_16264;
v_16263:
    v_16350 = nil;
    goto v_16262;
v_16264:
    v_16350 = v_16351;
    if (v_16350 == nil) goto v_16271;
    else goto v_16272;
v_16271:
    v_16350 = nil;
    goto v_16270;
v_16272:
    v_16350 = stack[-3];
    v_16350 = (v_16350 == nil ? lisp_true : nil);
    goto v_16270;
    v_16350 = nil;
v_16270:
    goto v_16262;
    v_16350 = nil;
v_16262:
    qvalue(elt(env, 9)) = v_16350; // acontract
    v_16350 = qvalue(elt(env, 5)); // identity
    if (v_16350 == nil) goto v_16281;
    else goto v_16282;
v_16281:
    v_16350 = nil;
    goto v_16280;
v_16282:
    goto v_16295;
v_16291:
    v_16351 = stack[-1];
    goto v_16292;
v_16293:
    v_16350 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16294;
v_16295:
    goto v_16291;
v_16292:
    goto v_16293;
v_16294:
    v_16350 = (LispObject)lessp2(v_16351, v_16350);
    v_16350 = v_16350 ? lisp_true : nil;
    env = stack[-6];
    if (v_16350 == nil) goto v_16289;
    else goto v_16288;
v_16289:
    v_16350 = stack[-2];
v_16288:
    goto v_16280;
    v_16350 = nil;
v_16280:
    qvalue(elt(env, 10)) = v_16350; // expand
    v_16350 = stack[-2];
    if (v_16350 == nil) goto v_16303;
    else goto v_16301;
v_16303:
    goto v_16311;
v_16307:
    v_16351 = stack[-1];
    goto v_16308;
v_16309:
    v_16350 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16310;
v_16311:
    goto v_16307;
v_16308:
    goto v_16309;
v_16310:
    v_16350 = (LispObject)lessp2(v_16351, v_16350);
    v_16350 = v_16350 ? lisp_true : nil;
    env = stack[-6];
    if (v_16350 == nil) goto v_16305;
    else goto v_16301;
v_16305:
    goto v_16302;
v_16301:
    v_16350 = stack[-3];
    if (v_16350 == nil) goto v_16317;
    v_16350 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16315;
v_16317:
    v_16350 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16315;
    v_16350 = nil;
v_16315:
    goto v_16300;
v_16302:
    v_16350 = stack[-1];
    goto v_16300;
    v_16350 = nil;
v_16300:
    qvalue(elt(env, 11)) = v_16350; // i
    v_16350 = qvalue(elt(env, 5)); // identity
    if (v_16350 == nil) goto v_16329;
    v_16350 = qvalue(elt(env, 3)); // p
    v_16350 = Llength(nil, v_16350);
    env = stack[-6];
    goto v_16327;
v_16329:
    goto v_16340;
v_16336:
    v_16351 = stack[-1];
    goto v_16337;
v_16338:
    v_16350 = stack[0];
    goto v_16339;
v_16340:
    goto v_16336;
v_16337:
    goto v_16338;
v_16339:
    v_16350 = plus2(v_16351, v_16350);
    env = stack[-6];
    goto v_16327;
    v_16350 = nil;
v_16327:
    qvalue(elt(env, 12)) = v_16350; // upb
    v_16350 = qvalue(elt(env, 2)); // symm
    if (v_16350 == nil) goto v_16346;
    v_16350 = stack[-4];
    fn = elt(env, 17); // initcomb
    v_16350 = (*qfn1(fn))(fn, v_16350);
    env = stack[-6];
    qvalue(elt(env, 13)) = v_16350; // comb
    goto v_16344;
v_16346:
v_16344:
    v_16350 = nil;
    return onevalue(v_16350);
}



// Code for vdpcondense

static LispObject CC_vdpcondense(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16137;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16137 = v_16129;
// end of prologue
    v_16137 = qcdr(v_16137);
    v_16137 = qcdr(v_16137);
    v_16137 = qcdr(v_16137);
    v_16137 = qcar(v_16137);
    {
        fn = elt(env, 1); // dipcondense
        return (*qfn1(fn))(fn, v_16137);
    }
}



// Code for edge_new_parents

static LispObject CC_edge_new_parents(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16162, v_16163, v_16164;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16129);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_16164 = v_16129;
// end of prologue
    goto v_16139;
v_16135:
    v_16162 = v_16164;
    v_16163 = qcar(v_16162);
    goto v_16136;
v_16137:
    v_16162 = qvalue(elt(env, 1)); // old_edge_list
    goto v_16138;
v_16139:
    goto v_16135;
v_16136:
    goto v_16137;
v_16138:
    v_16162 = Lassoc(nil, v_16163, v_16162);
    if (v_16162 == nil) goto v_16134;
    v_16162 = nil;
    goto v_16132;
v_16134:
    v_16162 = v_16164;
    v_16162 = qcdr(v_16162);
    v_16162 = qcar(v_16162);
    goto v_16157;
v_16153:
    v_16163 = v_16162;
    v_16163 = qcar(v_16163);
    goto v_16154;
v_16155:
    v_16162 = qcdr(v_16162);
    goto v_16156;
v_16157:
    goto v_16153;
v_16154:
    goto v_16155;
v_16156:
    v_16162 = list2(v_16163, v_16162);
    env = stack[0];
    {
        fn = elt(env, 2); // edge_new_parent
        return (*qfn1(fn))(fn, v_16162);
    }
    v_16162 = nil;
v_16132:
    return onevalue(v_16162);
}



// Code for idtomind

static LispObject CC_idtomind(LispObject env,
                         LispObject v_16129, LispObject v_16130)
{
    env = qenv(env);
    LispObject v_16163, v_16164, v_16165;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16165 = v_16130;
    v_16163 = v_16129;
// end of prologue
    goto v_16140;
v_16136:
    v_16164 = v_16163;
    goto v_16137;
v_16138:
    v_16163 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16139;
v_16140:
    goto v_16136;
v_16137:
    goto v_16138;
v_16139:
    if (v_16164 == v_16163) goto v_16134;
    else goto v_16135;
v_16134:
    goto v_16147;
v_16143:
    v_16163 = v_16165;
    goto v_16144;
v_16145:
    v_16164 = qvalue(elt(env, 1)); // i2m_jetspace!*
    goto v_16146;
v_16147:
    goto v_16143;
v_16144:
    goto v_16145;
v_16146:
    v_16163 = Lassoc(nil, v_16163, v_16164);
    v_16163 = qcdr(v_16163);
    goto v_16133;
v_16135:
    goto v_16158;
v_16154:
    v_16163 = v_16165;
    goto v_16155;
v_16156:
    v_16164 = qvalue(elt(env, 2)); // i2m_jetspace_odd!*
    goto v_16157;
v_16158:
    goto v_16154;
v_16155:
    goto v_16156;
v_16157:
    v_16163 = Lassoc(nil, v_16163, v_16164);
    v_16163 = qcdr(v_16163);
    goto v_16133;
    v_16163 = nil;
v_16133:
    return onevalue(v_16163);
}



// Code for gcref_off1

static LispObject CC_gcref_off1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16359, v_16360, v_16361;
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
    v_16359 = nil;
    qvalue(elt(env, 1)) = v_16359; // dfprint!*
    v_16359 = nil;
    qvalue(elt(env, 2)) = v_16359; // !*defn
    v_16359 = qvalue(elt(env, 3)); // !*algebraics
    if (v_16359 == nil) goto v_16137;
    else goto v_16138;
v_16137:
    goto v_16145;
v_16141:
    v_16360 = elt(env, 4); // algebraic
    goto v_16142;
v_16143:
    v_16359 = elt(env, 5); // newnam
    goto v_16144;
v_16145:
    goto v_16141;
v_16142:
    goto v_16143;
v_16144:
    v_16359 = Lremprop(nil, v_16360, v_16359);
    env = stack[-8];
    goto v_16136;
v_16138:
v_16136:
    v_16359 = qvalue(elt(env, 6)); // seen!*
    stack[-1] = v_16359;
v_16151:
    v_16359 = stack[-1];
    if (v_16359 == nil) goto v_16155;
    else goto v_16156;
v_16155:
    goto v_16150;
v_16156:
    v_16359 = stack[-1];
    v_16359 = qcar(v_16359);
    stack[0] = v_16359;
    goto v_16171;
v_16167:
    v_16360 = stack[0];
    goto v_16168;
v_16169:
    v_16359 = elt(env, 7); // calledby
    goto v_16170;
v_16171:
    goto v_16167;
v_16168:
    goto v_16169;
v_16170:
    v_16359 = get(v_16360, v_16359);
    env = stack[-8];
    if (v_16359 == nil) goto v_16164;
    else goto v_16165;
v_16164:
    goto v_16179;
v_16175:
    v_16360 = stack[0];
    goto v_16176;
v_16177:
    v_16359 = qvalue(elt(env, 8)); // entpts!*
    goto v_16178;
v_16179:
    goto v_16175;
v_16176:
    goto v_16177;
v_16178:
    v_16359 = cons(v_16360, v_16359);
    env = stack[-8];
    qvalue(elt(env, 8)) = v_16359; // entpts!*
    goto v_16163;
v_16165:
v_16163:
    v_16359 = stack[0];
    fn = elt(env, 16); // undefdchk
    v_16359 = (*qfn1(fn))(fn, v_16359);
    env = stack[-8];
    v_16359 = stack[-1];
    v_16359 = qcdr(v_16359);
    stack[-1] = v_16359;
    goto v_16151;
v_16150:
    v_16359 = qvalue(elt(env, 9)); // tseen!*
    fn = elt(env, 17); // idsort
    v_16359 = (*qfn1(fn))(fn, v_16359);
    env = stack[-8];
    stack[-6] = v_16359;
    v_16359 = stack[-6];
    if (v_16359 == nil) goto v_16196;
    else goto v_16197;
v_16196:
    v_16359 = nil;
    goto v_16190;
v_16197:
    v_16359 = stack[-6];
    v_16359 = qcar(v_16359);
    stack[-2] = v_16359;
    goto v_16209;
v_16205:
    v_16360 = stack[-2];
    goto v_16206;
v_16207:
    v_16359 = elt(env, 10); // tseen
    goto v_16208;
v_16209:
    goto v_16205;
v_16206:
    goto v_16207;
v_16208:
    v_16359 = Lremprop(nil, v_16360, v_16359);
    env = stack[-8];
    goto v_16221;
v_16217:
    v_16360 = stack[-2];
    goto v_16218;
v_16219:
    v_16359 = elt(env, 11); // funs
    goto v_16220;
v_16221:
    goto v_16217;
v_16218:
    goto v_16219;
v_16220:
    v_16359 = get(v_16360, v_16359);
    env = stack[-8];
    stack[-7] = v_16359;
    stack[-1] = v_16359;
v_16215:
    v_16359 = stack[-1];
    if (v_16359 == nil) goto v_16226;
    else goto v_16227;
v_16226:
    goto v_16214;
v_16227:
    v_16359 = stack[-1];
    v_16359 = qcar(v_16359);
    stack[0] = v_16359;
    v_16359 = stack[0];
    fn = elt(env, 16); // undefdchk
    v_16359 = (*qfn1(fn))(fn, v_16359);
    env = stack[-8];
    goto v_16240;
v_16236:
    v_16360 = stack[0];
    goto v_16237;
v_16238:
    v_16359 = elt(env, 12); // rccnam
    goto v_16239;
v_16240:
    goto v_16236;
v_16237:
    goto v_16238;
v_16239:
    v_16359 = Lremprop(nil, v_16360, v_16359);
    env = stack[-8];
    v_16359 = stack[-1];
    v_16359 = qcdr(v_16359);
    stack[-1] = v_16359;
    goto v_16215;
v_16214:
    goto v_16250;
v_16246:
    v_16360 = stack[-2];
    goto v_16247;
v_16248:
    v_16359 = stack[-7];
    goto v_16249;
v_16250:
    goto v_16246;
v_16247:
    goto v_16248;
v_16249:
    v_16359 = cons(v_16360, v_16359);
    env = stack[-8];
    v_16359 = ncons(v_16359);
    env = stack[-8];
    stack[-4] = v_16359;
    stack[-5] = v_16359;
v_16191:
    v_16359 = stack[-6];
    v_16359 = qcdr(v_16359);
    stack[-6] = v_16359;
    v_16359 = stack[-6];
    if (v_16359 == nil) goto v_16257;
    else goto v_16258;
v_16257:
    v_16359 = stack[-5];
    goto v_16190;
v_16258:
    goto v_16266;
v_16262:
    stack[-3] = stack[-4];
    goto v_16263;
v_16264:
    v_16359 = stack[-6];
    v_16359 = qcar(v_16359);
    stack[-2] = v_16359;
    goto v_16277;
v_16273:
    v_16360 = stack[-2];
    goto v_16274;
v_16275:
    v_16359 = elt(env, 10); // tseen
    goto v_16276;
v_16277:
    goto v_16273;
v_16274:
    goto v_16275;
v_16276:
    v_16359 = Lremprop(nil, v_16360, v_16359);
    env = stack[-8];
    goto v_16289;
v_16285:
    v_16360 = stack[-2];
    goto v_16286;
v_16287:
    v_16359 = elt(env, 11); // funs
    goto v_16288;
v_16289:
    goto v_16285;
v_16286:
    goto v_16287;
v_16288:
    v_16359 = get(v_16360, v_16359);
    env = stack[-8];
    stack[-7] = v_16359;
    stack[-1] = v_16359;
v_16283:
    v_16359 = stack[-1];
    if (v_16359 == nil) goto v_16294;
    else goto v_16295;
v_16294:
    goto v_16282;
v_16295:
    v_16359 = stack[-1];
    v_16359 = qcar(v_16359);
    stack[0] = v_16359;
    v_16359 = stack[0];
    fn = elt(env, 16); // undefdchk
    v_16359 = (*qfn1(fn))(fn, v_16359);
    env = stack[-8];
    goto v_16308;
v_16304:
    v_16360 = stack[0];
    goto v_16305;
v_16306:
    v_16359 = elt(env, 12); // rccnam
    goto v_16307;
v_16308:
    goto v_16304;
v_16305:
    goto v_16306;
v_16307:
    v_16359 = Lremprop(nil, v_16360, v_16359);
    env = stack[-8];
    v_16359 = stack[-1];
    v_16359 = qcdr(v_16359);
    stack[-1] = v_16359;
    goto v_16283;
v_16282:
    goto v_16318;
v_16314:
    v_16360 = stack[-2];
    goto v_16315;
v_16316:
    v_16359 = stack[-7];
    goto v_16317;
v_16318:
    goto v_16314;
v_16315:
    goto v_16316;
v_16317:
    v_16359 = cons(v_16360, v_16359);
    env = stack[-8];
    v_16359 = ncons(v_16359);
    env = stack[-8];
    goto v_16265;
v_16266:
    goto v_16262;
v_16263:
    goto v_16264;
v_16265:
    v_16359 = Lrplacd(nil, stack[-3], v_16359);
    env = stack[-8];
    v_16359 = stack[-4];
    v_16359 = qcdr(v_16359);
    stack[-4] = v_16359;
    goto v_16191;
v_16190:
    qvalue(elt(env, 9)) = v_16359; // tseen!*
    v_16359 = qvalue(elt(env, 13)); // gseen!*
    stack[0] = v_16359;
v_16326:
    v_16359 = stack[0];
    if (v_16359 == nil) goto v_16330;
    else goto v_16331;
v_16330:
    goto v_16325;
v_16331:
    v_16359 = stack[0];
    v_16359 = qcar(v_16359);
    v_16361 = v_16359;
    goto v_16346;
v_16342:
    v_16360 = v_16361;
    goto v_16343;
v_16344:
    v_16359 = elt(env, 14); // usedunby
    goto v_16345;
v_16346:
    goto v_16342;
v_16343:
    goto v_16344;
v_16345:
    v_16359 = get(v_16360, v_16359);
    env = stack[-8];
    if (v_16359 == nil) goto v_16340;
    goto v_16354;
v_16350:
    v_16360 = v_16361;
    goto v_16351;
v_16352:
    v_16359 = qvalue(elt(env, 15)); // undefg!*
    goto v_16353;
v_16354:
    goto v_16350;
v_16351:
    goto v_16352;
v_16353:
    v_16359 = cons(v_16360, v_16359);
    env = stack[-8];
    qvalue(elt(env, 15)) = v_16359; // undefg!*
    goto v_16338;
v_16340:
v_16338:
    v_16359 = stack[0];
    v_16359 = qcdr(v_16359);
    stack[0] = v_16359;
    goto v_16326;
v_16325:
    v_16359 = nil;
    return onevalue(v_16359);
}



// Code for talp_getinvfsym

static LispObject CC_talp_getinvfsym(LispObject env,
                         LispObject v_16129, LispObject v_16130)
{
    env = qenv(env);
    LispObject v_16181, v_16182;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16130,v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16129,v_16130);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16130;
    stack[-1] = v_16129;
// end of prologue
    fn = elt(env, 1); // talp_getextl
    v_16181 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-2] = v_16181;
v_16138:
    goto v_16147;
v_16143:
    v_16181 = stack[-2];
    v_16181 = qcar(v_16181);
    v_16182 = qcar(v_16181);
    goto v_16144;
v_16145:
    v_16181 = stack[-1];
    goto v_16146;
v_16147:
    goto v_16143;
v_16144:
    goto v_16145;
v_16146:
    if (equal(v_16182, v_16181)) goto v_16141;
    else goto v_16142;
v_16141:
    goto v_16137;
v_16142:
    v_16181 = stack[-2];
    v_16181 = qcdr(v_16181);
    stack[-2] = v_16181;
    goto v_16138;
v_16137:
    v_16181 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_16181;
v_16158:
    goto v_16170;
v_16166:
    v_16182 = stack[0];
    goto v_16167;
v_16168:
    v_16181 = stack[-1];
    goto v_16169;
v_16170:
    goto v_16166;
v_16167:
    goto v_16168;
v_16169:
    v_16181 = difference2(v_16182, v_16181);
    env = stack[-3];
    v_16181 = Lminusp(nil, v_16181);
    env = stack[-3];
    if (v_16181 == nil) goto v_16163;
    goto v_16157;
v_16163:
    v_16181 = stack[-2];
    v_16181 = qcdr(v_16181);
    stack[-2] = v_16181;
    v_16181 = stack[-1];
    v_16181 = add1(v_16181);
    env = stack[-3];
    stack[-1] = v_16181;
    goto v_16158;
v_16157:
    v_16181 = stack[-2];
    v_16181 = qcar(v_16181);
    v_16181 = qcar(v_16181);
    return onevalue(v_16181);
}



// Code for qqe_eta!-in!-term1

static LispObject CC_qqe_etaKinKterm1(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16162, v_16163;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16129);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_16129;
// end of prologue
    v_16162 = stack[0];
    v_16162 = qcdr(v_16162);
    v_16162 = qcar(v_16162);
    fn = elt(env, 2); // qqe_simplterm
    v_16162 = (*qfn1(fn))(fn, v_16162);
    env = stack[-2];
    stack[-1] = v_16162;
    goto v_16143;
v_16139:
    v_16162 = stack[0];
    fn = elt(env, 3); // qqe_op
    v_16163 = (*qfn1(fn))(fn, v_16162);
    env = stack[-2];
    goto v_16140;
v_16141:
    v_16162 = stack[-1];
    goto v_16142;
v_16143:
    goto v_16139;
v_16140:
    goto v_16141;
v_16142:
    v_16162 = cons(v_16163, v_16162);
    env = stack[-2];
    goto v_16155;
v_16151:
    v_16162 = stack[-1];
    goto v_16152;
v_16153:
    v_16163 = elt(env, 1); // qepsilon
    goto v_16154;
v_16155:
    goto v_16151;
v_16152:
    goto v_16153;
v_16154:
    if (v_16162 == v_16163) goto v_16149;
    else goto v_16150;
v_16149:
    v_16162 = lisp_true;
    goto v_16133;
v_16150:
    v_16162 = nil;
    goto v_16133;
    v_16162 = nil;
v_16133:
    return onevalue(v_16162);
}



// Code for get!-height

static LispObject CC_getKheight(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16157;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16129);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_16129;
// end of prologue
    v_16157 = stack[0];
    if (v_16157 == nil) goto v_16133;
    else goto v_16134;
v_16133:
    v_16157 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16132;
v_16134:
    v_16157 = stack[0];
    if (is_number(v_16157)) goto v_16137;
    else goto v_16138;
v_16137:
    v_16157 = stack[0];
        return Labsval(nil, v_16157);
v_16138:
    goto v_16149;
v_16145:
    v_16157 = stack[0];
    v_16157 = qcar(v_16157);
    v_16157 = qcdr(v_16157);
    stack[-1] = CC_getKheight(elt(env, 0), v_16157);
    env = stack[-2];
    goto v_16146;
v_16147:
    v_16157 = stack[0];
    v_16157 = qcdr(v_16157);
    v_16157 = CC_getKheight(elt(env, 0), v_16157);
    env = stack[-2];
    goto v_16148;
v_16149:
    goto v_16145;
v_16146:
    goto v_16147;
v_16148:
    {
        LispObject v_16160 = stack[-1];
        fn = elt(env, 1); // max
        return (*qfn2(fn))(fn, v_16160, v_16157);
    }
    v_16157 = nil;
v_16132:
    return onevalue(v_16157);
}



// Code for lambdaom

static LispObject CC_lambdaom(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16166, v_16167;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16129);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_16167 = v_16129;
// end of prologue
    v_16166 = v_16167;
    v_16166 = qcdr(v_16166);
    v_16166 = qcdr(v_16166);
    v_16166 = qcar(v_16166);
    v_16166 = qcdr(v_16166);
    v_16166 = qcar(v_16166);
    stack[-1] = v_16166;
    v_16166 = v_16167;
    v_16166 = Lreverse(nil, v_16166);
    env = stack[-2];
    v_16166 = qcar(v_16166);
    stack[0] = v_16166;
    v_16166 = elt(env, 1); // "<OMBIND>"
    fn = elt(env, 6); // printout
    v_16166 = (*qfn1(fn))(fn, v_16166);
    env = stack[-2];
    v_16166 = lisp_true;
    fn = elt(env, 7); // indent!*
    v_16166 = (*qfn1(fn))(fn, v_16166);
    env = stack[-2];
    v_16166 = elt(env, 2); // "<OMS cd=""fns1"" name=""lambda""/>"
    fn = elt(env, 6); // printout
    v_16166 = (*qfn1(fn))(fn, v_16166);
    env = stack[-2];
    v_16166 = elt(env, 3); // "<OMBVAR>"
    fn = elt(env, 6); // printout
    v_16166 = (*qfn1(fn))(fn, v_16166);
    env = stack[-2];
    v_16166 = lisp_true;
    fn = elt(env, 7); // indent!*
    v_16166 = (*qfn1(fn))(fn, v_16166);
    env = stack[-2];
    v_16166 = stack[-1];
    fn = elt(env, 8); // objectom
    v_16166 = (*qfn1(fn))(fn, v_16166);
    env = stack[-2];
    v_16166 = nil;
    fn = elt(env, 7); // indent!*
    v_16166 = (*qfn1(fn))(fn, v_16166);
    env = stack[-2];
    v_16166 = elt(env, 4); // "</OMBVAR>"
    fn = elt(env, 6); // printout
    v_16166 = (*qfn1(fn))(fn, v_16166);
    env = stack[-2];
    v_16166 = stack[0];
    fn = elt(env, 8); // objectom
    v_16166 = (*qfn1(fn))(fn, v_16166);
    env = stack[-2];
    v_16166 = nil;
    fn = elt(env, 7); // indent!*
    v_16166 = (*qfn1(fn))(fn, v_16166);
    env = stack[-2];
    v_16166 = elt(env, 5); // "</OMBIND>"
    fn = elt(env, 6); // printout
    v_16166 = (*qfn1(fn))(fn, v_16166);
    v_16166 = nil;
    return onevalue(v_16166);
}



// Code for dipsum

static LispObject CC_dipsum(LispObject env,
                         LispObject v_16129, LispObject v_16130)
{
    env = qenv(env);
    LispObject v_16308, v_16309, v_16310;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16130,v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16129,v_16130);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_16130;
    stack[-6] = v_16129;
// end of prologue
    v_16308 = stack[-6];
    if (v_16308 == nil) goto v_16134;
    else goto v_16135;
v_16134:
    v_16308 = stack[-5];
    goto v_16133;
v_16135:
    v_16308 = stack[-5];
    if (v_16308 == nil) goto v_16138;
    else goto v_16139;
v_16138:
    v_16308 = stack[-6];
    goto v_16133;
v_16139:
    stack[-7] = nil;
    stack[-2] = nil;
    stack[0] = nil;
v_16156:
    v_16308 = stack[-7];
    if (v_16308 == nil) goto v_16160;
    goto v_16155;
v_16160:
    v_16308 = stack[-6];
    if (v_16308 == nil) goto v_16165;
    else goto v_16166;
v_16165:
    v_16308 = stack[-5];
    stack[-1] = v_16308;
    v_16308 = lisp_true;
    stack[-7] = v_16308;
    goto v_16164;
v_16166:
    v_16308 = stack[-5];
    if (v_16308 == nil) goto v_16170;
    else goto v_16171;
v_16170:
    v_16308 = stack[-6];
    stack[-1] = v_16308;
    v_16308 = lisp_true;
    stack[-7] = v_16308;
    goto v_16164;
v_16171:
    v_16308 = stack[-6];
    v_16308 = qcar(v_16308);
    stack[-4] = v_16308;
    v_16308 = stack[-5];
    v_16308 = qcar(v_16308);
    stack[-3] = v_16308;
    goto v_16186;
v_16182:
    v_16309 = stack[-4];
    goto v_16183;
v_16184:
    v_16308 = stack[-3];
    goto v_16185;
v_16186:
    goto v_16182;
v_16183:
    goto v_16184;
v_16185:
    fn = elt(env, 1); // evcomp
    v_16308 = (*qfn2(fn))(fn, v_16309, v_16308);
    env = stack[-8];
    stack[-1] = v_16308;
    goto v_16198;
v_16194:
    v_16309 = stack[-1];
    goto v_16195;
v_16196:
    v_16308 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16197;
v_16198:
    goto v_16194;
v_16195:
    goto v_16196;
v_16197:
    fn = elt(env, 2); // iequal
    v_16308 = (*qfn2(fn))(fn, v_16309, v_16308);
    env = stack[-8];
    if (v_16308 == nil) goto v_16192;
    goto v_16208;
v_16202:
    v_16310 = stack[-4];
    goto v_16203;
v_16204:
    v_16308 = stack[-6];
    v_16308 = qcdr(v_16308);
    v_16309 = qcar(v_16308);
    goto v_16205;
v_16206:
    v_16308 = nil;
    goto v_16207;
v_16208:
    goto v_16202;
v_16203:
    goto v_16204;
v_16205:
    goto v_16206;
v_16207:
    v_16308 = list2star(v_16310, v_16309, v_16308);
    env = stack[-8];
    stack[-1] = v_16308;
    v_16308 = stack[-6];
    v_16308 = qcdr(v_16308);
    v_16308 = qcdr(v_16308);
    stack[-6] = v_16308;
    goto v_16190;
v_16192:
    goto v_16224;
v_16220:
    v_16309 = stack[-1];
    goto v_16221;
v_16222:
    v_16308 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_16223;
v_16224:
    goto v_16220;
v_16221:
    goto v_16222;
v_16223:
    fn = elt(env, 2); // iequal
    v_16308 = (*qfn2(fn))(fn, v_16309, v_16308);
    env = stack[-8];
    if (v_16308 == nil) goto v_16218;
    goto v_16234;
v_16228:
    v_16310 = stack[-3];
    goto v_16229;
v_16230:
    v_16308 = stack[-5];
    v_16308 = qcdr(v_16308);
    v_16309 = qcar(v_16308);
    goto v_16231;
v_16232:
    v_16308 = nil;
    goto v_16233;
v_16234:
    goto v_16228;
v_16229:
    goto v_16230;
v_16231:
    goto v_16232;
v_16233:
    v_16308 = list2star(v_16310, v_16309, v_16308);
    env = stack[-8];
    stack[-1] = v_16308;
    v_16308 = stack[-5];
    v_16308 = qcdr(v_16308);
    v_16308 = qcdr(v_16308);
    stack[-5] = v_16308;
    goto v_16190;
v_16218:
    goto v_16250;
v_16246:
    v_16308 = stack[-6];
    v_16308 = qcdr(v_16308);
    v_16309 = qcar(v_16308);
    goto v_16247;
v_16248:
    v_16308 = stack[-5];
    v_16308 = qcdr(v_16308);
    v_16308 = qcar(v_16308);
    goto v_16249;
v_16250:
    goto v_16246;
v_16247:
    goto v_16248;
v_16249:
    fn = elt(env, 3); // bcsum
    v_16308 = (*qfn2(fn))(fn, v_16309, v_16308);
    env = stack[-8];
    stack[-1] = v_16308;
    v_16308 = stack[-1];
    fn = elt(env, 4); // bczero!?
    v_16308 = (*qfn1(fn))(fn, v_16308);
    env = stack[-8];
    if (v_16308 == nil) goto v_16259;
    else goto v_16260;
v_16259:
    goto v_16270;
v_16264:
    v_16310 = stack[-4];
    goto v_16265;
v_16266:
    v_16309 = stack[-1];
    goto v_16267;
v_16268:
    v_16308 = nil;
    goto v_16269;
v_16270:
    goto v_16264;
v_16265:
    goto v_16266;
v_16267:
    goto v_16268;
v_16269:
    v_16308 = list2star(v_16310, v_16309, v_16308);
    env = stack[-8];
    goto v_16258;
v_16260:
    v_16308 = nil;
    goto v_16258;
    v_16308 = nil;
v_16258:
    stack[-1] = v_16308;
    v_16308 = stack[-6];
    v_16308 = qcdr(v_16308);
    v_16308 = qcdr(v_16308);
    stack[-6] = v_16308;
    v_16308 = stack[-5];
    v_16308 = qcdr(v_16308);
    v_16308 = qcdr(v_16308);
    stack[-5] = v_16308;
    goto v_16190;
v_16190:
    goto v_16164;
v_16164:
    v_16308 = stack[-1];
    if (v_16308 == nil) goto v_16286;
    v_16308 = stack[0];
    if (v_16308 == nil) goto v_16290;
    else goto v_16291;
v_16290:
    v_16308 = stack[-1];
    stack[-2] = v_16308;
    stack[0] = v_16308;
    goto v_16289;
v_16291:
    goto v_16301;
v_16297:
    v_16308 = stack[-2];
    v_16309 = qcdr(v_16308);
    goto v_16298;
v_16299:
    v_16308 = stack[-1];
    goto v_16300;
v_16301:
    goto v_16297;
v_16298:
    goto v_16299;
v_16300:
    fn = elt(env, 5); // setcdr
    v_16308 = (*qfn2(fn))(fn, v_16309, v_16308);
    env = stack[-8];
    v_16308 = stack[-1];
    stack[-2] = v_16308;
    goto v_16289;
v_16289:
    goto v_16284;
v_16286:
v_16284:
    goto v_16156;
v_16155:
    v_16308 = stack[0];
    goto v_16133;
    v_16308 = nil;
v_16133:
    return onevalue(v_16308);
}



// Code for prop!-simp2

static LispObject CC_propKsimp2(LispObject env,
                         LispObject v_16129, LispObject v_16130)
{
    env = qenv(env);
    LispObject v_16189, v_16190;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16130,v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16129,v_16130);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_16130;
    stack[-3] = v_16129;
// end of prologue
    v_16189 = stack[-2];
    if (!consp(v_16189)) goto v_16141;
    else goto v_16142;
v_16141:
    v_16189 = nil;
    goto v_16140;
v_16142:
    goto v_16151;
v_16147:
    v_16190 = stack[-2];
    goto v_16148;
v_16149:
    v_16189 = stack[-3];
    goto v_16150;
v_16151:
    goto v_16147;
v_16148:
    goto v_16149;
v_16150:
    v_16189 = Lmember(nil, v_16190, v_16189);
    goto v_16140;
    v_16189 = nil;
v_16140:
    stack[-4] = v_16189;
    if (v_16189 == nil) goto v_16138;
    goto v_16160;
v_16156:
    goto v_16166;
v_16162:
    stack[-1] = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_16163;
v_16164:
    goto v_16173;
v_16169:
    v_16189 = stack[-3];
    stack[0] = Llength(nil, v_16189);
    env = stack[-5];
    goto v_16170;
v_16171:
    v_16189 = stack[-4];
    v_16189 = Llength(nil, v_16189);
    env = stack[-5];
    goto v_16172;
v_16173:
    goto v_16169;
v_16170:
    goto v_16171;
v_16172:
    v_16189 = difference2(stack[0], v_16189);
    env = stack[-5];
    goto v_16165;
v_16166:
    goto v_16162;
v_16163:
    goto v_16164;
v_16165:
    stack[0] = Lexpt(nil, stack[-1], v_16189);
    env = stack[-5];
    goto v_16157;
v_16158:
    goto v_16183;
v_16179:
    v_16190 = stack[-2];
    goto v_16180;
v_16181:
    v_16189 = stack[-3];
    goto v_16182;
v_16183:
    goto v_16179;
v_16180:
    goto v_16181;
v_16182:
    v_16189 = Ldelete(nil, v_16190, v_16189);
    goto v_16159;
v_16160:
    goto v_16156;
v_16157:
    goto v_16158;
v_16159:
    {
        LispObject v_16196 = stack[0];
        return cons(v_16196, v_16189);
    }
v_16138:
    v_16189 = nil;
    goto v_16134;
    v_16189 = nil;
v_16134:
    return onevalue(v_16189);
}



// Code for boolvalue!*

static LispObject CC_boolvalueH(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16148, v_16149;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16148 = v_16129;
// end of prologue
    v_16149 = v_16148;
    if (v_16149 == nil) goto v_16133;
    else goto v_16134;
v_16133:
    v_16148 = nil;
    goto v_16132;
v_16134:
    goto v_16143;
v_16139:
    v_16149 = v_16148;
    goto v_16140;
v_16141:
    v_16148 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16142;
v_16143:
    goto v_16139;
v_16140:
    goto v_16141;
v_16142:
    v_16148 = (v_16149 == v_16148 ? lisp_true : nil);
    v_16148 = (v_16148 == nil ? lisp_true : nil);
    goto v_16132;
    v_16148 = nil;
v_16132:
    return onevalue(v_16148);
}



// Code for generic!-sub

static LispObject CC_genericKsub(LispObject env,
                         LispObject v_16129, LispObject v_16130)
{
    env = qenv(env);
    LispObject v_16151, v_16152;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16130,v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16129,v_16130);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_16151 = v_16130;
    v_16152 = v_16129;
// end of prologue
    goto v_16137;
v_16133:
    stack[-2] = v_16152;
    goto v_16134;
v_16135:
    goto v_16146;
v_16140:
    stack[-1] = elt(env, 1); // dfp
    goto v_16141;
v_16142:
    stack[0] = v_16151;
    goto v_16143;
v_16144:
    v_16151 = elt(env, 2); // list
    v_16151 = ncons(v_16151);
    env = stack[-3];
    goto v_16145;
v_16146:
    goto v_16140;
v_16141:
    goto v_16142;
v_16143:
    goto v_16144;
v_16145:
    v_16151 = list3(stack[-1], stack[0], v_16151);
    env = stack[-3];
    goto v_16136;
v_16137:
    goto v_16133;
v_16134:
    goto v_16135;
v_16136:
    {
        LispObject v_16156 = stack[-2];
        fn = elt(env, 3); // dfp!-sub
        return (*qfn2(fn))(fn, v_16156, v_16151);
    }
}



// Code for arminusp!:

static LispObject CC_arminuspT(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16134;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16134 = v_16129;
// end of prologue
    v_16134 = qcdr(v_16134);
    {
        fn = elt(env, 1); // minusf
        return (*qfn1(fn))(fn, v_16134);
    }
}



// Code for sgn1

static LispObject CC_sgn1(LispObject env,
                         LispObject v_16129, LispObject v_16130)
{
    env = qenv(env);
    LispObject v_16197, v_16198;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16130,v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16129,v_16130);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_16198 = v_16130;
    stack[-4] = v_16129;
// end of prologue
    v_16197 = stack[-4];
    if (!consp(v_16197)) goto v_16134;
    else goto v_16135;
v_16134:
    v_16197 = stack[-4];
    {
        fn = elt(env, 2); // sgn
        return (*qfn1(fn))(fn, v_16197);
    }
v_16135:
// Binding d
// FLUIDBIND: reloadenv=6 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-6, 1, -1);
    qvalue(elt(env, 1)) = nil; // d
    v_16197 = v_16198;
    v_16197 = qcar(v_16197);
    stack[-2] = v_16197;
    v_16197 = v_16198;
    v_16197 = qcdr(v_16197);
    qvalue(elt(env, 1)) = v_16197; // d
    v_16197 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_16197;
    v_16197 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_16197;
    v_16197 = stack[-4];
    v_16197 = qcdr(v_16197);
    stack[-4] = v_16197;
v_16157:
    goto v_16163;
v_16159:
    goto v_16169;
v_16165:
    v_16198 = stack[-5];
    goto v_16166;
v_16167:
    v_16197 = stack[-4];
    v_16197 = qcar(v_16197);
    goto v_16168;
v_16169:
    goto v_16165;
v_16166:
    goto v_16167;
v_16168:
    stack[0] = times2(v_16198, v_16197);
    env = stack[-6];
    goto v_16160;
v_16161:
    goto v_16178;
v_16174:
    v_16198 = stack[-2];
    goto v_16175;
v_16176:
    v_16197 = stack[-3];
    goto v_16177;
v_16178:
    goto v_16174;
v_16175:
    goto v_16176;
v_16177:
    v_16197 = times2(v_16198, v_16197);
    env = stack[-6];
    goto v_16162;
v_16163:
    goto v_16159;
v_16160:
    goto v_16161;
v_16162:
    v_16197 = plus2(stack[0], v_16197);
    env = stack[-6];
    stack[-3] = v_16197;
    goto v_16186;
v_16182:
    v_16198 = stack[-5];
    goto v_16183;
v_16184:
    v_16197 = qvalue(elt(env, 1)); // d
    goto v_16185;
v_16186:
    goto v_16182;
v_16183:
    goto v_16184;
v_16185:
    v_16197 = times2(v_16198, v_16197);
    env = stack[-6];
    stack[-5] = v_16197;
    v_16197 = stack[-4];
    v_16197 = qcdr(v_16197);
    stack[-4] = v_16197;
    if (v_16197 == nil) goto v_16192;
    goto v_16157;
v_16192:
    v_16197 = stack[-3];
    fn = elt(env, 2); // sgn
    v_16197 = (*qfn1(fn))(fn, v_16197);
    ;}  // end of a binding scope
    goto v_16133;
    v_16197 = nil;
v_16133:
    return onevalue(v_16197);
}



// Code for lalr_cleanup

static LispObject CC_lalr_cleanup(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16184, v_16185, v_16186;
    argcheck(nargs, 0, "lalr_cleanup");
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
    v_16184 = qvalue(elt(env, 1)); // symbols
    stack[-1] = v_16184;
v_16133:
    v_16184 = stack[-1];
    if (v_16184 == nil) goto v_16137;
    else goto v_16138;
v_16137:
    v_16184 = nil;
    goto v_16132;
v_16138:
    v_16184 = stack[-1];
    v_16184 = qcar(v_16184);
    stack[0] = v_16184;
    v_16184 = stack[0];
    if (symbolp(v_16184)) goto v_16146;
    else goto v_16147;
v_16146:
    goto v_16156;
v_16150:
    v_16186 = stack[0];
    goto v_16151;
v_16152:
    v_16185 = elt(env, 2); // lalr_produces
    goto v_16153;
v_16154:
    v_16184 = nil;
    goto v_16155;
v_16156:
    goto v_16150;
v_16151:
    goto v_16152;
v_16153:
    goto v_16154;
v_16155:
    v_16184 = Lputprop(nil, 3, v_16186, v_16185, v_16184);
    env = stack[-2];
    goto v_16167;
v_16161:
    v_16186 = stack[0];
    goto v_16162;
v_16163:
    v_16185 = elt(env, 3); // lalr_first
    goto v_16164;
v_16165:
    v_16184 = nil;
    goto v_16166;
v_16167:
    goto v_16161;
v_16162:
    goto v_16163;
v_16164:
    goto v_16165;
v_16166:
    v_16184 = Lputprop(nil, 3, v_16186, v_16185, v_16184);
    env = stack[-2];
    goto v_16178;
v_16172:
    v_16186 = stack[0];
    goto v_16173;
v_16174:
    v_16185 = elt(env, 4); // lalr_nonterminal_code
    goto v_16175;
v_16176:
    v_16184 = nil;
    goto v_16177;
v_16178:
    goto v_16172;
v_16173:
    goto v_16174;
v_16175:
    goto v_16176;
v_16177:
    v_16184 = Lputprop(nil, 3, v_16186, v_16185, v_16184);
    env = stack[-2];
    goto v_16145;
v_16147:
v_16145:
    v_16184 = stack[-1];
    v_16184 = qcdr(v_16184);
    stack[-1] = v_16184;
    goto v_16133;
v_16132:
    return onevalue(v_16184);
}



// Code for in_list1a

static LispObject CC_in_list1a(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16426, v_16427, v_16428;
    LispObject fn;
    LispObject v_16131, v_16130, v_16129;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "in_list1a");
    va_start(aa, nargs);
    v_16129 = va_arg(aa, LispObject);
    v_16130 = va_arg(aa, LispObject);
    v_16131 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_16131,v_16130,v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_16129,v_16130,v_16131);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_16131;
    stack[-3] = v_16130;
    stack[-4] = v_16129;
// end of prologue
    stack[0] = nil;
    v_16426 = qvalue(elt(env, 1)); // !*echo
    stack[-5] = v_16426;
    v_16426 = qvalue(elt(env, 2)); // !*reduce4
    if (v_16426 == nil) goto v_16145;
    goto v_16155;
v_16151:
    v_16426 = stack[-4];
    fn = elt(env, 17); // type
    v_16427 = (*qfn1(fn))(fn, v_16426);
    env = stack[-6];
    goto v_16152;
v_16153:
    v_16426 = elt(env, 3); // string
    goto v_16154;
v_16155:
    goto v_16151;
v_16152:
    goto v_16153;
v_16154:
    if (v_16427 == v_16426) goto v_16150;
    goto v_16164;
v_16160:
    v_16427 = stack[-4];
    goto v_16161;
v_16162:
    v_16426 = elt(env, 3); // string
    goto v_16163;
v_16164:
    goto v_16160;
v_16161:
    goto v_16162;
v_16163:
    fn = elt(env, 18); // typerr
    v_16426 = (*qfn2(fn))(fn, v_16427, v_16426);
    env = stack[-6];
    goto v_16148;
v_16150:
    v_16426 = stack[-4];
    fn = elt(env, 19); // value
    v_16426 = (*qfn1(fn))(fn, v_16426);
    env = stack[-6];
    stack[-4] = v_16426;
    goto v_16148;
v_16148:
    goto v_16143;
v_16145:
v_16143:
    v_16426 = stack[-4];
    fn = elt(env, 20); // mkfil!*
    v_16426 = (*qfn1(fn))(fn, v_16426);
    env = stack[-6];
    stack[-4] = v_16426;
    v_16426 = stack[-4];
    v_16426 = Lexplodec(nil, v_16426);
    env = stack[-6];
    stack[-1] = v_16426;
    goto v_16184;
v_16180:
    v_16427 = stack[-1];
    goto v_16181;
v_16182:
    v_16426 = elt(env, 4); // !|
    goto v_16183;
v_16184:
    goto v_16180;
v_16181:
    goto v_16182;
v_16183:
    if (!consp(v_16427)) goto v_16178;
    v_16427 = qcar(v_16427);
    if (v_16427 == v_16426) goto v_16177;
    else goto v_16178;
v_16177:
    v_16426 = lisp_true;
    stack[0] = v_16426;
    v_16426 = stack[-1];
    v_16426 = qcdr(v_16426);
    fn = elt(env, 21); // list2string
    v_16426 = (*qfn1(fn))(fn, v_16426);
    env = stack[-6];
    stack[-4] = v_16426;
    goto v_16176;
v_16178:
    goto v_16202;
v_16198:
    v_16427 = stack[-1];
    goto v_16199;
v_16200:
    v_16426 = elt(env, 5); // !$
    goto v_16201;
v_16202:
    goto v_16198;
v_16199:
    goto v_16200;
v_16201:
    if (!consp(v_16427)) goto v_16196;
    v_16427 = qcar(v_16427);
    if (v_16427 == v_16426) goto v_16195;
    else goto v_16196;
v_16195:
    goto v_16214;
v_16210:
    v_16426 = stack[-1];
    v_16427 = qcdr(v_16426);
    goto v_16211;
v_16212:
    v_16426 = elt(env, 6); // !/
    goto v_16213;
v_16214:
    goto v_16210;
v_16211:
    goto v_16212;
v_16213:
    if (!consp(v_16427)) goto v_16208;
    v_16427 = qcar(v_16427);
    if (v_16427 == v_16426) goto v_16207;
    else goto v_16208;
v_16207:
    v_16426 = lisp_true;
    goto v_16206;
v_16208:
    goto v_16226;
v_16222:
    v_16426 = stack[-1];
    v_16427 = qcdr(v_16426);
    goto v_16223;
v_16224:
    v_16426 = elt(env, 7); // !\ (backslash)
    goto v_16225;
v_16226:
    goto v_16222;
v_16223:
    goto v_16224;
v_16225:
    v_16426 = Leqcar(nil, v_16427, v_16426);
    env = stack[-6];
    goto v_16206;
    v_16426 = nil;
v_16206:
    goto v_16194;
v_16196:
    v_16426 = nil;
    goto v_16194;
    v_16426 = nil;
v_16194:
    if (v_16426 == nil) goto v_16192;
    v_16426 = qvalue(elt(env, 8)); // ifl!*
    if (v_16426 == nil) goto v_16235;
    else goto v_16236;
v_16235:
    goto v_16244;
v_16240:
    v_16427 = elt(env, 9); // !.
    goto v_16241;
v_16242:
    v_16426 = stack[-1];
    v_16426 = qcdr(v_16426);
    goto v_16243;
v_16244:
    goto v_16240;
v_16241:
    goto v_16242;
v_16243:
    v_16426 = cons(v_16427, v_16426);
    env = stack[-6];
    fn = elt(env, 21); // list2string
    v_16426 = (*qfn1(fn))(fn, v_16426);
    env = stack[-6];
    stack[-4] = v_16426;
    goto v_16234;
v_16236:
    v_16426 = qvalue(elt(env, 8)); // ifl!*
    v_16426 = qcar(v_16426);
    v_16426 = Lexplodec(nil, v_16426);
    env = stack[-6];
    v_16426 = Lreverse(nil, v_16426);
    env = stack[-6];
    v_16428 = v_16426;
v_16256:
    v_16426 = v_16428;
    if (v_16426 == nil) goto v_16259;
    goto v_16273;
v_16269:
    v_16427 = v_16428;
    goto v_16270;
v_16271:
    v_16426 = elt(env, 6); // !/
    goto v_16272;
v_16273:
    goto v_16269;
v_16270:
    goto v_16271;
v_16272:
    if (!consp(v_16427)) goto v_16267;
    v_16427 = qcar(v_16427);
    if (v_16427 == v_16426) goto v_16266;
    else goto v_16267;
v_16266:
    v_16426 = lisp_true;
    goto v_16265;
v_16267:
    goto v_16284;
v_16280:
    v_16427 = v_16428;
    goto v_16281;
v_16282:
    v_16426 = elt(env, 7); // !\ (backslash)
    goto v_16283;
v_16284:
    goto v_16280;
v_16281:
    goto v_16282;
v_16283:
    v_16426 = Leqcar(nil, v_16427, v_16426);
    env = stack[-6];
    goto v_16265;
    v_16426 = nil;
v_16265:
    if (v_16426 == nil) goto v_16263;
    else goto v_16259;
v_16263:
    goto v_16260;
v_16259:
    goto v_16255;
v_16260:
    v_16426 = v_16428;
    v_16426 = qcdr(v_16426);
    v_16428 = v_16426;
    goto v_16256;
v_16255:
    v_16426 = v_16428;
    if (v_16426 == nil) goto v_16292;
    else goto v_16293;
v_16292:
    v_16426 = elt(env, 10); // (!/ !.)
    v_16428 = v_16426;
    goto v_16291;
v_16293:
v_16291:
    goto v_16301;
v_16297:
    v_16426 = v_16428;
    v_16427 = Lreverse(nil, v_16426);
    env = stack[-6];
    goto v_16298;
v_16299:
    v_16426 = stack[-1];
    v_16426 = qcdr(v_16426);
    v_16426 = qcdr(v_16426);
    goto v_16300;
v_16301:
    goto v_16297;
v_16298:
    goto v_16299;
v_16300:
    v_16426 = Lappend(nil, v_16427, v_16426);
    env = stack[-6];
    stack[-1] = v_16426;
    v_16426 = stack[-1];
    fn = elt(env, 21); // list2string
    v_16426 = (*qfn1(fn))(fn, v_16426);
    env = stack[-6];
    stack[-4] = v_16426;
    goto v_16234;
v_16234:
    goto v_16176;
v_16192:
v_16176:
    v_16426 = stack[0];
    if (v_16426 == nil) goto v_16312;
    goto v_16319;
v_16315:
    v_16427 = stack[-4];
    goto v_16316;
v_16317:
    v_16426 = elt(env, 11); // input
    goto v_16318;
v_16319:
    goto v_16315;
v_16316:
    goto v_16317;
v_16318:
    fn = elt(env, 22); // pipe!-open
    v_16426 = (*qfn2(fn))(fn, v_16427, v_16426);
    env = stack[-6];
    goto v_16310;
v_16312:
    goto v_16329;
v_16325:
    v_16427 = stack[-4];
    goto v_16326;
v_16327:
    v_16426 = elt(env, 11); // input
    goto v_16328;
v_16329:
    goto v_16325;
v_16326:
    goto v_16327;
v_16328:
    fn = elt(env, 23); // open
    v_16426 = (*qfn2(fn))(fn, v_16427, v_16426);
    env = stack[-6];
    goto v_16310;
    v_16426 = nil;
v_16310:
    stack[-1] = v_16426;
    v_16426 = stack[-1];
    v_16426 = Lrds(nil, v_16426);
    env = stack[-6];
    stack[0] = v_16426;
    goto v_16342;
v_16338:
    v_16427 = stack[-4];
    goto v_16339;
v_16340:
    v_16426 = qvalue(elt(env, 12)); // linelist!*
    goto v_16341;
v_16342:
    goto v_16338;
v_16339:
    goto v_16340;
v_16341:
    v_16426 = Lassoc(nil, v_16427, v_16426);
    if (v_16426 == nil) goto v_16337;
    goto v_16335;
v_16337:
v_16335:
    v_16426 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 13)) = v_16426; // curline!*
    goto v_16355;
v_16349:
    v_16428 = stack[-4];
    goto v_16350;
v_16351:
    v_16427 = stack[-1];
    goto v_16352;
v_16353:
    v_16426 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16354;
v_16355:
    goto v_16349;
v_16350:
    goto v_16351;
v_16352:
    goto v_16353;
v_16354:
    v_16426 = list3(v_16428, v_16427, v_16426);
    env = stack[-6];
    qvalue(elt(env, 8)) = v_16426; // ifl!*
    goto v_16364;
v_16360:
    v_16427 = qvalue(elt(env, 8)); // ifl!*
    goto v_16361;
v_16362:
    v_16426 = qvalue(elt(env, 14)); // ipl!*
    goto v_16363;
v_16364:
    goto v_16360;
v_16361:
    goto v_16362;
v_16363:
    v_16426 = cons(v_16427, v_16426);
    env = stack[-6];
    qvalue(elt(env, 14)) = v_16426; // ipl!*
    v_16426 = stack[-3];
    qvalue(elt(env, 1)) = v_16426; // !*echo
    v_16426 = stack[-2];
    fn = elt(env, 24); // begin1a
    v_16426 = (*qfn1(fn))(fn, v_16426);
    env = stack[-6];
    v_16426 = stack[0];
    v_16426 = Lrds(nil, v_16426);
    env = stack[-6];
    v_16426 = stack[-1];
    v_16426 = Lclose(nil, v_16426);
    env = stack[-6];
    v_16426 = stack[-5];
    qvalue(elt(env, 1)) = v_16426; // !*echo
    v_16426 = qvalue(elt(env, 14)); // ipl!*
    if (v_16426 == nil) goto v_16381;
    else goto v_16382;
v_16381:
    v_16426 = qvalue(elt(env, 15)); // contl!*
    goto v_16380;
v_16382:
    v_16426 = nil;
    goto v_16380;
    v_16426 = nil;
v_16380:
    if (v_16426 == nil) goto v_16378;
    v_16426 = nil;
    goto v_16140;
v_16378:
    v_16426 = qvalue(elt(env, 14)); // ipl!*
    if (v_16426 == nil) goto v_16393;
    else goto v_16394;
v_16393:
    v_16426 = lisp_true;
    goto v_16392;
v_16394:
    goto v_16403;
v_16399:
    v_16427 = stack[-4];
    goto v_16400;
v_16401:
    v_16426 = qvalue(elt(env, 14)); // ipl!*
    v_16426 = qcar(v_16426);
    v_16426 = qcar(v_16426);
    goto v_16402;
v_16403:
    goto v_16399;
v_16400:
    goto v_16401;
v_16402:
    v_16426 = (v_16427 == v_16426 ? lisp_true : nil);
    v_16426 = (v_16426 == nil ? lisp_true : nil);
    goto v_16392;
    v_16426 = nil;
v_16392:
    if (v_16426 == nil) goto v_16390;
    goto v_16418;
v_16412:
    v_16428 = elt(env, 16); // "FILE STACK CONFUSION"
    goto v_16413;
v_16414:
    v_16427 = stack[-4];
    goto v_16415;
v_16416:
    v_16426 = qvalue(elt(env, 14)); // ipl!*
    goto v_16417;
v_16418:
    goto v_16412;
v_16413:
    goto v_16414;
v_16415:
    goto v_16416;
v_16417:
    v_16426 = list3(v_16428, v_16427, v_16426);
    env = stack[-6];
    fn = elt(env, 25); // rederr
    v_16426 = (*qfn1(fn))(fn, v_16426);
    goto v_16376;
v_16390:
    v_16426 = qvalue(elt(env, 14)); // ipl!*
    v_16426 = qcdr(v_16426);
    qvalue(elt(env, 14)) = v_16426; // ipl!*
    goto v_16376;
v_16376:
    v_16426 = nil;
v_16140:
    return onevalue(v_16426);
}



// Code for cl_sordpl

static LispObject CC_cl_sordpl(LispObject env,
                         LispObject v_16129, LispObject v_16130)
{
    env = qenv(env);
    LispObject v_16172, v_16173, v_16174, v_16175;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16173 = v_16130;
    v_16174 = v_16129;
// end of prologue
v_16134:
    v_16172 = v_16173;
    if (v_16172 == nil) goto v_16137;
    else goto v_16138;
v_16137:
    v_16172 = nil;
    goto v_16133;
v_16138:
    v_16172 = v_16174;
    if (v_16172 == nil) goto v_16141;
    else goto v_16142;
v_16141:
    v_16172 = lisp_true;
    goto v_16133;
v_16142:
    goto v_16151;
v_16147:
    v_16172 = v_16174;
    v_16175 = qcar(v_16172);
    goto v_16148;
v_16149:
    v_16172 = v_16173;
    v_16172 = qcar(v_16172);
    goto v_16150;
v_16151:
    goto v_16147;
v_16148:
    goto v_16149;
v_16150:
    if (equal(v_16175, v_16172)) goto v_16146;
    goto v_16161;
v_16157:
    v_16172 = v_16174;
    v_16172 = qcar(v_16172);
    goto v_16158;
v_16159:
    v_16173 = qcar(v_16173);
    goto v_16160;
v_16161:
    goto v_16157;
v_16158:
    goto v_16159;
v_16160:
    {
        fn = elt(env, 1); // cl_sordp
        return (*qfn2(fn))(fn, v_16172, v_16173);
    }
v_16146:
    v_16172 = v_16174;
    v_16172 = qcdr(v_16172);
    v_16174 = v_16172;
    v_16172 = v_16173;
    v_16172 = qcdr(v_16172);
    v_16173 = v_16172;
    goto v_16134;
    v_16172 = nil;
v_16133:
    return onevalue(v_16172);
}



// Code for qqe_simplterm!-tail

static LispObject CC_qqe_simpltermKtail(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16267, v_16268, v_16269;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16129);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_16129;
// end of prologue
    v_16267 = stack[-2];
    fn = elt(env, 7); // qqe_arg2l
    v_16267 = (*qfn1(fn))(fn, v_16267);
    env = stack[-4];
    stack[-3] = v_16267;
    goto v_16148;
v_16144:
    v_16268 = stack[-3];
    goto v_16145;
v_16146:
    v_16267 = elt(env, 1); // qepsilon
    goto v_16147;
v_16148:
    goto v_16144;
v_16145:
    goto v_16146;
v_16147:
    if (v_16268 == v_16267) goto v_16142;
    else goto v_16143;
v_16142:
    v_16267 = elt(env, 1); // qepsilon
    goto v_16137;
v_16143:
    v_16267 = stack[-3];
    if (!consp(v_16267)) goto v_16154;
    else goto v_16155;
v_16154:
    v_16267 = stack[-2];
    goto v_16137;
v_16155:
    v_16267 = stack[-2];
    fn = elt(env, 8); // qqe_op
    v_16267 = (*qfn1(fn))(fn, v_16267);
    env = stack[-4];
    stack[-1] = v_16267;
    v_16267 = stack[-3];
    fn = elt(env, 8); // qqe_op
    v_16267 = (*qfn1(fn))(fn, v_16267);
    env = stack[-4];
    stack[0] = v_16267;
    goto v_16170;
v_16166:
    v_16268 = stack[0];
    goto v_16167;
v_16168:
    v_16267 = elt(env, 2); // (ladd radd)
    goto v_16169;
v_16170:
    goto v_16166;
v_16167:
    goto v_16168;
v_16169:
    v_16267 = Lmemq(nil, v_16268, v_16267);
    if (v_16267 == nil) goto v_16165;
    v_16267 = stack[-3];
    fn = elt(env, 9); // qqe_arg2r
    v_16267 = (*qfn1(fn))(fn, v_16267);
    env = stack[-4];
    v_16269 = v_16267;
    goto v_16184;
v_16180:
    v_16268 = v_16269;
    goto v_16181;
v_16182:
    v_16267 = elt(env, 1); // qepsilon
    goto v_16183;
v_16184:
    goto v_16180;
v_16181:
    goto v_16182;
v_16183:
    if (v_16268 == v_16267) goto v_16178;
    else goto v_16179;
v_16178:
    v_16267 = elt(env, 1); // qepsilon
    goto v_16137;
v_16179:
    goto v_16204;
v_16200:
    v_16268 = stack[-1];
    goto v_16201;
v_16202:
    v_16267 = elt(env, 3); // ltail
    goto v_16203;
v_16204:
    goto v_16200;
v_16201:
    goto v_16202;
v_16203:
    if (v_16268 == v_16267) goto v_16198;
    else goto v_16199;
v_16198:
    goto v_16211;
v_16207:
    v_16268 = stack[0];
    goto v_16208;
v_16209:
    v_16267 = elt(env, 4); // radd
    goto v_16210;
v_16211:
    goto v_16207;
v_16208:
    goto v_16209;
v_16210:
    v_16267 = (v_16268 == v_16267 ? lisp_true : nil);
    goto v_16197;
v_16199:
    v_16267 = nil;
    goto v_16197;
    v_16267 = nil;
v_16197:
    if (v_16267 == nil) goto v_16195;
    v_16267 = lisp_true;
    goto v_16193;
v_16195:
    goto v_16229;
v_16225:
    v_16268 = stack[-1];
    goto v_16226;
v_16227:
    v_16267 = elt(env, 5); // rtail
    goto v_16228;
v_16229:
    goto v_16225;
v_16226:
    goto v_16227;
v_16228:
    if (v_16268 == v_16267) goto v_16223;
    else goto v_16224;
v_16223:
    goto v_16236;
v_16232:
    v_16268 = stack[0];
    goto v_16233;
v_16234:
    v_16267 = elt(env, 6); // ladd
    goto v_16235;
v_16236:
    goto v_16232;
v_16233:
    goto v_16234;
v_16235:
    v_16267 = (v_16268 == v_16267 ? lisp_true : nil);
    goto v_16222;
v_16224:
    v_16267 = nil;
    goto v_16222;
    v_16267 = nil;
v_16222:
    goto v_16193;
    v_16267 = nil;
v_16193:
    if (v_16267 == nil) goto v_16191;
    v_16267 = v_16269;
    goto v_16137;
v_16191:
    goto v_16163;
v_16165:
v_16163:
    v_16267 = stack[-3];
    fn = elt(env, 10); // qqe_simplterm
    v_16267 = (*qfn1(fn))(fn, v_16267);
    env = stack[-4];
    v_16269 = v_16267;
    goto v_16254;
v_16250:
    v_16268 = v_16269;
    goto v_16251;
v_16252:
    v_16267 = stack[-3];
    goto v_16253;
v_16254:
    goto v_16250;
v_16251:
    goto v_16252;
v_16253:
    if (equal(v_16268, v_16267)) goto v_16248;
    else goto v_16249;
v_16248:
    v_16267 = stack[-2];
    goto v_16137;
v_16249:
    goto v_16264;
v_16260:
    v_16267 = stack[-1];
    goto v_16261;
v_16262:
    v_16268 = v_16269;
    goto v_16263;
v_16264:
    goto v_16260;
v_16261:
    goto v_16262;
v_16263:
    v_16267 = list2(v_16267, v_16268);
    env = stack[-4];
    {
        fn = elt(env, 10); // qqe_simplterm
        return (*qfn1(fn))(fn, v_16267);
    }
v_16137:
    return onevalue(v_16267);
}



// Code for pasf_simplat1

static LispObject CC_pasf_simplat1(LispObject env,
                         LispObject v_16129, LispObject v_16130)
{
    env = qenv(env);
    LispObject v_16392, v_16393, v_16394;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16130,v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16129,v_16130);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_16392 = v_16130;
    v_16393 = v_16129;
// end of prologue
    v_16392 = v_16393;
    fn = elt(env, 6); // pasf_zcong
    v_16392 = (*qfn1(fn))(fn, v_16392);
    env = stack[0];
    fn = elt(env, 7); // pasf_mkpos
    v_16392 = (*qfn1(fn))(fn, v_16392);
    env = stack[0];
    fn = elt(env, 8); // pasf_dt
    v_16392 = (*qfn1(fn))(fn, v_16392);
    env = stack[0];
    fn = elt(env, 9); // pasf_vf
    v_16392 = (*qfn1(fn))(fn, v_16392);
    env = stack[0];
    v_16393 = v_16392;
    goto v_16151;
v_16147:
    v_16394 = v_16393;
    goto v_16148;
v_16149:
    v_16392 = elt(env, 1); // true
    goto v_16150;
v_16151:
    goto v_16147;
v_16148:
    goto v_16149;
v_16150:
    if (v_16394 == v_16392) goto v_16145;
    else goto v_16146;
v_16145:
    v_16392 = lisp_true;
    goto v_16144;
v_16146:
    goto v_16161;
v_16157:
    v_16394 = v_16393;
    goto v_16158;
v_16159:
    v_16392 = elt(env, 2); // false
    goto v_16160;
v_16161:
    goto v_16157;
v_16158:
    goto v_16159;
v_16160:
    v_16392 = (v_16394 == v_16392 ? lisp_true : nil);
    goto v_16144;
    v_16392 = nil;
v_16144:
    if (v_16392 == nil) goto v_16142;
    v_16392 = v_16393;
    goto v_16133;
v_16142:
    v_16392 = v_16393;
    v_16392 = Lconsp(nil, v_16392);
    env = stack[0];
    if (v_16392 == nil) goto v_16169;
    v_16392 = v_16393;
    v_16392 = qcar(v_16392);
    v_16392 = Lconsp(nil, v_16392);
    env = stack[0];
    if (v_16392 == nil) goto v_16169;
    goto v_16183;
v_16179:
    v_16392 = v_16393;
    v_16392 = qcar(v_16392);
    v_16394 = qcar(v_16392);
    goto v_16180;
v_16181:
    v_16392 = elt(env, 3); // (cong ncong)
    goto v_16182;
v_16183:
    goto v_16179;
v_16180:
    goto v_16181;
v_16182:
    v_16392 = Lmemq(nil, v_16394, v_16392);
    if (v_16392 == nil) goto v_16169;
    v_16392 = v_16393;
    fn = elt(env, 10); // pasf_mr
    v_16392 = (*qfn1(fn))(fn, v_16392);
    env = stack[0];
    fn = elt(env, 9); // pasf_vf
    v_16392 = (*qfn1(fn))(fn, v_16392);
    env = stack[0];
    fn = elt(env, 11); // pasf_cecong
    v_16392 = (*qfn1(fn))(fn, v_16392);
    env = stack[0];
    v_16393 = v_16392;
    goto v_16167;
v_16169:
    goto v_16203;
v_16199:
    goto v_16216;
v_16212:
    v_16394 = v_16393;
    goto v_16213;
v_16214:
    v_16392 = elt(env, 1); // true
    goto v_16215;
v_16216:
    goto v_16212;
v_16213:
    goto v_16214;
v_16215:
    if (v_16394 == v_16392) goto v_16210;
    else goto v_16211;
v_16210:
    v_16392 = lisp_true;
    goto v_16209;
v_16211:
    goto v_16226;
v_16222:
    v_16394 = v_16393;
    goto v_16223;
v_16224:
    v_16392 = elt(env, 2); // false
    goto v_16225;
v_16226:
    goto v_16222;
v_16223:
    goto v_16224;
v_16225:
    v_16392 = (v_16394 == v_16392 ? lisp_true : nil);
    goto v_16209;
    v_16392 = nil;
v_16209:
    if (v_16392 == nil) goto v_16207;
    v_16392 = v_16393;
    v_16394 = v_16392;
    goto v_16205;
v_16207:
    v_16392 = v_16393;
    v_16392 = qcar(v_16392);
    v_16392 = Lconsp(nil, v_16392);
    env = stack[0];
    if (v_16392 == nil) goto v_16232;
    v_16392 = v_16393;
    v_16392 = qcar(v_16392);
    v_16392 = qcar(v_16392);
    v_16394 = v_16392;
    goto v_16205;
v_16232:
    v_16392 = v_16393;
    v_16392 = qcar(v_16392);
    v_16394 = v_16392;
    goto v_16205;
    v_16394 = nil;
v_16205:
    goto v_16200;
v_16201:
    v_16392 = elt(env, 4); // (equal neq)
    goto v_16202;
v_16203:
    goto v_16199;
v_16200:
    goto v_16201;
v_16202:
    v_16392 = Lmemq(nil, v_16394, v_16392);
    if (v_16392 == nil) goto v_16198;
    v_16392 = v_16393;
    fn = elt(env, 12); // pasf_ceeq
    v_16392 = (*qfn1(fn))(fn, v_16392);
    env = stack[0];
    v_16393 = v_16392;
    goto v_16196;
v_16198:
    v_16392 = v_16393;
    fn = elt(env, 13); // pasf_cein
    v_16392 = (*qfn1(fn))(fn, v_16392);
    env = stack[0];
    v_16393 = v_16392;
    goto v_16196;
v_16196:
    goto v_16167;
v_16167:
    goto v_16263;
v_16259:
    v_16394 = v_16393;
    goto v_16260;
v_16261:
    v_16392 = elt(env, 1); // true
    goto v_16262;
v_16263:
    goto v_16259;
v_16260:
    goto v_16261;
v_16262:
    if (v_16394 == v_16392) goto v_16257;
    else goto v_16258;
v_16257:
    v_16392 = lisp_true;
    goto v_16256;
v_16258:
    goto v_16273;
v_16269:
    v_16394 = v_16393;
    goto v_16270;
v_16271:
    v_16392 = elt(env, 2); // false
    goto v_16272;
v_16273:
    goto v_16269;
v_16270:
    goto v_16271;
v_16272:
    v_16392 = (v_16394 == v_16392 ? lisp_true : nil);
    goto v_16256;
    v_16392 = nil;
v_16256:
    if (v_16392 == nil) goto v_16254;
    v_16392 = v_16393;
    goto v_16133;
v_16254:
    goto v_16286;
v_16282:
    goto v_16299;
v_16295:
    v_16394 = v_16393;
    goto v_16296;
v_16297:
    v_16392 = elt(env, 1); // true
    goto v_16298;
v_16299:
    goto v_16295;
v_16296:
    goto v_16297;
v_16298:
    if (v_16394 == v_16392) goto v_16293;
    else goto v_16294;
v_16293:
    v_16392 = lisp_true;
    goto v_16292;
v_16294:
    goto v_16309;
v_16305:
    v_16394 = v_16393;
    goto v_16306;
v_16307:
    v_16392 = elt(env, 2); // false
    goto v_16308;
v_16309:
    goto v_16305;
v_16306:
    goto v_16307;
v_16308:
    v_16392 = (v_16394 == v_16392 ? lisp_true : nil);
    goto v_16292;
    v_16392 = nil;
v_16292:
    if (v_16392 == nil) goto v_16290;
    v_16392 = v_16393;
    v_16394 = v_16392;
    goto v_16288;
v_16290:
    v_16392 = v_16393;
    v_16392 = qcar(v_16392);
    v_16392 = Lconsp(nil, v_16392);
    env = stack[0];
    if (v_16392 == nil) goto v_16315;
    v_16392 = v_16393;
    v_16392 = qcar(v_16392);
    v_16392 = qcar(v_16392);
    v_16394 = v_16392;
    goto v_16288;
v_16315:
    v_16392 = v_16393;
    v_16392 = qcar(v_16392);
    v_16394 = v_16392;
    goto v_16288;
    v_16394 = nil;
v_16288:
    goto v_16283;
v_16284:
    v_16392 = elt(env, 3); // (cong ncong)
    goto v_16285;
v_16286:
    goto v_16282;
v_16283:
    goto v_16284;
v_16285:
    v_16392 = Lmemq(nil, v_16394, v_16392);
    if (v_16392 == nil) goto v_16281;
    v_16392 = v_16393;
    fn = elt(env, 14); // pasf_sc
    v_16392 = (*qfn1(fn))(fn, v_16392);
    env = stack[0];
    goto v_16279;
v_16281:
    goto v_16336;
v_16332:
    goto v_16349;
v_16345:
    v_16394 = v_16393;
    goto v_16346;
v_16347:
    v_16392 = elt(env, 1); // true
    goto v_16348;
v_16349:
    goto v_16345;
v_16346:
    goto v_16347;
v_16348:
    if (v_16394 == v_16392) goto v_16343;
    else goto v_16344;
v_16343:
    v_16392 = lisp_true;
    goto v_16342;
v_16344:
    goto v_16359;
v_16355:
    v_16394 = v_16393;
    goto v_16356;
v_16357:
    v_16392 = elt(env, 2); // false
    goto v_16358;
v_16359:
    goto v_16355;
v_16356:
    goto v_16357;
v_16358:
    v_16392 = (v_16394 == v_16392 ? lisp_true : nil);
    goto v_16342;
    v_16392 = nil;
v_16342:
    if (v_16392 == nil) goto v_16340;
    v_16392 = v_16393;
    v_16394 = v_16392;
    goto v_16338;
v_16340:
    v_16392 = v_16393;
    v_16392 = qcar(v_16392);
    v_16392 = Lconsp(nil, v_16392);
    env = stack[0];
    if (v_16392 == nil) goto v_16365;
    v_16392 = v_16393;
    v_16392 = qcar(v_16392);
    v_16392 = qcar(v_16392);
    v_16394 = v_16392;
    goto v_16338;
v_16365:
    v_16392 = v_16393;
    v_16392 = qcar(v_16392);
    v_16394 = v_16392;
    goto v_16338;
    v_16394 = nil;
v_16338:
    goto v_16333;
v_16334:
    v_16392 = elt(env, 4); // (equal neq)
    goto v_16335;
v_16336:
    goto v_16332;
v_16333:
    goto v_16334;
v_16335:
    v_16392 = Lmemq(nil, v_16394, v_16392);
    if (v_16392 == nil) goto v_16331;
    v_16392 = v_16393;
    fn = elt(env, 15); // pasf_se
    v_16392 = (*qfn1(fn))(fn, v_16392);
    env = stack[0];
    goto v_16279;
v_16331:
    v_16392 = v_16393;
    fn = elt(env, 16); // pasf_or
    v_16392 = (*qfn1(fn))(fn, v_16392);
    env = stack[0];
    goto v_16279;
    v_16392 = nil;
v_16279:
    v_16393 = v_16392;
    v_16392 = qvalue(elt(env, 5)); // !*rlsifac
    if (v_16392 == nil) goto v_16386;
    else goto v_16387;
v_16386:
    v_16392 = v_16393;
    goto v_16133;
v_16387:
    v_16392 = v_16393;
    {
        fn = elt(env, 17); // pasf_fact
        return (*qfn1(fn))(fn, v_16392);
    }
v_16133:
    return onevalue(v_16392);
}



// Code for bc_fd

static LispObject CC_bc_fd(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16139, v_16140;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16139 = v_16129;
// end of prologue
    goto v_16136;
v_16132:
    v_16140 = v_16139;
    goto v_16133;
v_16134:
    v_16139 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16135;
v_16136:
    goto v_16132;
v_16133:
    goto v_16134;
v_16135:
    return cons(v_16140, v_16139);
}



// Code for dvfsf_0mk2

static LispObject CC_dvfsf_0mk2(LispObject env,
                         LispObject v_16129, LispObject v_16130)
{
    env = qenv(env);
    LispObject v_16143, v_16144, v_16145;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16143 = v_16130;
    v_16144 = v_16129;
// end of prologue
    goto v_16139;
v_16133:
    v_16145 = v_16144;
    goto v_16134;
v_16135:
    v_16144 = v_16143;
    goto v_16136;
v_16137:
    v_16143 = nil;
    goto v_16138;
v_16139:
    goto v_16133;
v_16134:
    goto v_16135;
v_16136:
    goto v_16137;
v_16138:
    return list3(v_16145, v_16144, v_16143);
}



// Code for sfto_b!:ordexn

static LispObject CC_sfto_bTordexn(LispObject env,
                         LispObject v_16129, LispObject v_16130)
{
    env = qenv(env);
    LispObject v_16221, v_16222;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16130,v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16129,v_16130);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_16130;
    stack[-2] = v_16129;
// end of prologue
    stack[0] = nil;
    stack[-3] = nil;
v_16136:
    v_16221 = stack[-1];
    if (v_16221 == nil) goto v_16139;
    else goto v_16140;
v_16139:
    goto v_16147;
v_16143:
    goto v_16144;
v_16145:
    goto v_16155;
v_16151:
    v_16222 = stack[-2];
    goto v_16152;
v_16153:
    v_16221 = stack[-3];
    goto v_16154;
v_16155:
    goto v_16151;
v_16152:
    goto v_16153;
v_16154:
    v_16221 = cons(v_16222, v_16221);
    env = stack[-4];
    v_16221 = Lreverse(nil, v_16221);
    goto v_16146;
v_16147:
    goto v_16143;
v_16144:
    goto v_16145;
v_16146:
    {
        LispObject v_16227 = stack[0];
        return cons(v_16227, v_16221);
    }
v_16140:
    goto v_16164;
v_16160:
    v_16222 = stack[-2];
    goto v_16161;
v_16162:
    v_16221 = stack[-1];
    v_16221 = qcar(v_16221);
    goto v_16163;
v_16164:
    goto v_16160;
v_16161:
    goto v_16162;
v_16163:
    if (equal(v_16222, v_16221)) goto v_16158;
    else goto v_16159;
v_16158:
    v_16221 = nil;
    goto v_16135;
v_16159:
    v_16221 = stack[-2];
    if (v_16221 == nil) goto v_16170;
    goto v_16179;
v_16175:
    v_16222 = stack[-2];
    goto v_16176;
v_16177:
    v_16221 = stack[-1];
    v_16221 = qcar(v_16221);
    goto v_16178;
v_16179:
    goto v_16175;
v_16176:
    goto v_16177;
v_16178:
    v_16221 = (LispObject)greaterp2(v_16222, v_16221);
    v_16221 = v_16221 ? lisp_true : nil;
    env = stack[-4];
    if (v_16221 == nil) goto v_16170;
    goto v_16188;
v_16184:
    goto v_16185;
v_16186:
    goto v_16195;
v_16191:
    goto v_16202;
v_16198:
    v_16222 = stack[-2];
    goto v_16199;
v_16200:
    v_16221 = stack[-3];
    goto v_16201;
v_16202:
    goto v_16198;
v_16199:
    goto v_16200;
v_16201:
    v_16221 = cons(v_16222, v_16221);
    env = stack[-4];
    v_16222 = Lreverse(nil, v_16221);
    env = stack[-4];
    goto v_16192;
v_16193:
    v_16221 = stack[-1];
    goto v_16194;
v_16195:
    goto v_16191;
v_16192:
    goto v_16193;
v_16194:
    v_16221 = Lappend(nil, v_16222, v_16221);
    goto v_16187;
v_16188:
    goto v_16184;
v_16185:
    goto v_16186;
v_16187:
    {
        LispObject v_16228 = stack[0];
        return cons(v_16228, v_16221);
    }
v_16170:
    goto v_16213;
v_16209:
    v_16221 = stack[-1];
    v_16222 = qcar(v_16221);
    goto v_16210;
v_16211:
    v_16221 = stack[-3];
    goto v_16212;
v_16213:
    goto v_16209;
v_16210:
    goto v_16211;
v_16212:
    v_16221 = cons(v_16222, v_16221);
    env = stack[-4];
    stack[-3] = v_16221;
    v_16221 = stack[-1];
    v_16221 = qcdr(v_16221);
    stack[-1] = v_16221;
    v_16221 = stack[0];
    v_16221 = (v_16221 == nil ? lisp_true : nil);
    stack[0] = v_16221;
    goto v_16138;
v_16138:
    goto v_16136;
v_16135:
    return onevalue(v_16221);
}



// Code for testpr

static LispObject CC_testpr(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16284, v_16285, v_16286;
    LispObject fn;
    LispObject v_16132, v_16131, v_16130, v_16129;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "testpr");
    va_start(aa, nargs);
    v_16129 = va_arg(aa, LispObject);
    v_16130 = va_arg(aa, LispObject);
    v_16131 = va_arg(aa, LispObject);
    v_16132 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_16132,v_16131,v_16130,v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_16129,v_16130,v_16131,v_16132);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_16132;
    stack[-6] = v_16131;
    stack[0] = v_16130;
    v_16284 = v_16129;
// end of prologue
    stack[-3] = nil;
    v_16285 = qvalue(elt(env, 1)); // jsi
    stack[-2] = v_16285;
    goto v_16148;
v_16144:
    goto v_16153;
v_16149:
    stack[-1] = qvalue(elt(env, 2)); // codmat
    goto v_16150;
v_16151:
    goto v_16160;
v_16156:
    v_16285 = qvalue(elt(env, 3)); // maxvar
    goto v_16157;
v_16158:
    goto v_16159;
v_16160:
    goto v_16156;
v_16157:
    goto v_16158;
v_16159:
    v_16284 = plus2(v_16285, v_16284);
    env = stack[-8];
    goto v_16152;
v_16153:
    goto v_16149;
v_16150:
    goto v_16151;
v_16152:
    v_16285 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_16284-TAG_FIXNUM)/(16/CELL)));
    goto v_16145;
v_16146:
    v_16284 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_16147;
v_16148:
    goto v_16144;
v_16145:
    goto v_16146;
v_16147:
    v_16284 = *(LispObject *)((char *)v_16285 + (CELL-TAG_VECTOR) + (((intptr_t)v_16284-TAG_FIXNUM)/(16/CELL)));
    stack[-7] = v_16284;
    goto v_16170;
v_16166:
    goto v_16175;
v_16171:
    stack[-1] = qvalue(elt(env, 2)); // codmat
    goto v_16172;
v_16173:
    goto v_16182;
v_16178:
    v_16285 = qvalue(elt(env, 3)); // maxvar
    goto v_16179;
v_16180:
    v_16284 = stack[0];
    goto v_16181;
v_16182:
    goto v_16178;
v_16179:
    goto v_16180;
v_16181:
    v_16284 = plus2(v_16285, v_16284);
    env = stack[-8];
    goto v_16174;
v_16175:
    goto v_16171;
v_16172:
    goto v_16173;
v_16174:
    v_16285 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_16284-TAG_FIXNUM)/(16/CELL)));
    goto v_16167;
v_16168:
    v_16284 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_16169;
v_16170:
    goto v_16166;
v_16167:
    goto v_16168;
v_16169:
    v_16284 = *(LispObject *)((char *)v_16285 + (CELL-TAG_VECTOR) + (((intptr_t)v_16284-TAG_FIXNUM)/(16/CELL)));
    stack[-4] = v_16284;
v_16190:
    v_16284 = stack[-2];
    if (v_16284 == nil) goto v_16193;
    v_16284 = stack[-7];
    if (v_16284 == nil) goto v_16193;
    goto v_16194;
v_16193:
    goto v_16189;
v_16194:
    goto v_16208;
v_16204:
    v_16284 = stack[-2];
    v_16285 = qcar(v_16284);
    stack[-1] = v_16285;
    goto v_16205;
v_16206:
    v_16284 = stack[-7];
    v_16284 = qcar(v_16284);
    v_16284 = qcar(v_16284);
    v_16286 = v_16284;
    goto v_16207;
v_16208:
    goto v_16204;
v_16205:
    goto v_16206;
v_16207:
    if (equal(v_16285, v_16284)) goto v_16202;
    else goto v_16203;
v_16202:
    goto v_16219;
v_16215:
    v_16285 = stack[-1];
    goto v_16216;
v_16217:
    v_16284 = stack[-4];
    goto v_16218;
v_16219:
    goto v_16215;
v_16216:
    goto v_16217;
v_16218:
    fn = elt(env, 4); // pnthxzz
    v_16284 = (*qfn2(fn))(fn, v_16285, v_16284);
    env = stack[-8];
    stack[-4] = v_16284;
    goto v_16232;
v_16228:
    goto v_16238;
v_16234:
    v_16284 = stack[-7];
    v_16284 = qcar(v_16284);
    v_16284 = qcdr(v_16284);
    v_16285 = qcar(v_16284);
    goto v_16235;
v_16236:
    v_16284 = stack[-5];
    goto v_16237;
v_16238:
    goto v_16234;
v_16235:
    goto v_16236;
v_16237:
    fn = elt(env, 5); // dm!-times
    stack[0] = (*qfn2(fn))(fn, v_16285, v_16284);
    env = stack[-8];
    goto v_16229;
v_16230:
    goto v_16249;
v_16245:
    v_16284 = stack[-4];
    v_16284 = qcar(v_16284);
    v_16284 = qcdr(v_16284);
    v_16285 = qcar(v_16284);
    goto v_16246;
v_16247:
    v_16284 = stack[-6];
    goto v_16248;
v_16249:
    goto v_16245;
v_16246:
    goto v_16247;
v_16248:
    fn = elt(env, 5); // dm!-times
    v_16284 = (*qfn2(fn))(fn, v_16285, v_16284);
    env = stack[-8];
    goto v_16231;
v_16232:
    goto v_16228;
v_16229:
    goto v_16230;
v_16231:
    fn = elt(env, 6); // dm!-difference
    v_16284 = (*qfn2(fn))(fn, stack[0], v_16284);
    env = stack[-8];
    fn = elt(env, 7); // zeropp
    v_16284 = (*qfn1(fn))(fn, v_16284);
    env = stack[-8];
    if (v_16284 == nil) goto v_16225;
    goto v_16260;
v_16256:
    v_16285 = stack[-1];
    goto v_16257;
v_16258:
    v_16284 = stack[-3];
    goto v_16259;
v_16260:
    goto v_16256;
v_16257:
    goto v_16258;
v_16259:
    v_16284 = cons(v_16285, v_16284);
    env = stack[-8];
    stack[-3] = v_16284;
    goto v_16223;
v_16225:
v_16223:
    v_16284 = stack[-2];
    v_16284 = qcdr(v_16284);
    stack[-2] = v_16284;
    v_16284 = stack[-7];
    v_16284 = qcdr(v_16284);
    stack[-7] = v_16284;
    goto v_16201;
v_16203:
    goto v_16274;
v_16270:
    v_16284 = stack[-1];
    goto v_16271;
v_16272:
    v_16285 = v_16286;
    goto v_16273;
v_16274:
    goto v_16270;
v_16271:
    goto v_16272;
v_16273:
    v_16284 = (LispObject)greaterp2(v_16284, v_16285);
    v_16284 = v_16284 ? lisp_true : nil;
    env = stack[-8];
    if (v_16284 == nil) goto v_16268;
    v_16284 = stack[-7];
    v_16284 = qcdr(v_16284);
    stack[-7] = v_16284;
    goto v_16201;
v_16268:
    v_16284 = stack[-2];
    v_16284 = qcdr(v_16284);
    stack[-2] = v_16284;
    goto v_16201;
v_16201:
    goto v_16190;
v_16189:
    v_16284 = stack[-3];
    return onevalue(v_16284);
}



// Code for embed!-null!-fn

static LispObject CC_embedKnullKfn(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16235, v_16236, v_16237;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16129);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_16236 = v_16129;
// end of prologue
    v_16235 = v_16236;
    if (!consp(v_16235)) goto v_16133;
    else goto v_16134;
v_16133:
    v_16235 = v_16236;
    goto v_16132;
v_16134:
    v_16235 = v_16236;
    stack[-3] = v_16235;
v_16144:
    v_16235 = stack[-3];
    if (v_16235 == nil) goto v_16149;
    else goto v_16150;
v_16149:
    v_16235 = nil;
    goto v_16143;
v_16150:
    v_16235 = stack[-3];
    v_16235 = qcar(v_16235);
    v_16237 = v_16235;
    v_16235 = v_16237;
    if (!consp(v_16235)) goto v_16158;
    else goto v_16159;
v_16158:
    v_16235 = v_16237;
    v_16235 = ncons(v_16235);
    env = stack[-4];
    goto v_16157;
v_16159:
    goto v_16169;
v_16165:
    v_16235 = v_16237;
    v_16236 = qcar(v_16235);
    goto v_16166;
v_16167:
    v_16235 = elt(env, 1); // null!-fn
    goto v_16168;
v_16169:
    goto v_16165;
v_16166:
    goto v_16167;
v_16168:
    if (v_16236 == v_16235) goto v_16163;
    else goto v_16164;
v_16163:
    v_16235 = v_16237;
    v_16235 = qcdr(v_16235);
    v_16235 = CC_embedKnullKfn(elt(env, 0), v_16235);
    env = stack[-4];
    goto v_16157;
v_16164:
    v_16235 = v_16237;
    v_16235 = CC_embedKnullKfn(elt(env, 0), v_16235);
    env = stack[-4];
    v_16235 = ncons(v_16235);
    env = stack[-4];
    goto v_16157;
    v_16235 = nil;
v_16157:
    stack[-2] = v_16235;
    v_16235 = stack[-2];
    fn = elt(env, 2); // lastpair
    v_16235 = (*qfn1(fn))(fn, v_16235);
    env = stack[-4];
    stack[-1] = v_16235;
    v_16235 = stack[-3];
    v_16235 = qcdr(v_16235);
    stack[-3] = v_16235;
    v_16235 = stack[-1];
    if (!consp(v_16235)) goto v_16187;
    else goto v_16188;
v_16187:
    goto v_16144;
v_16188:
v_16145:
    v_16235 = stack[-3];
    if (v_16235 == nil) goto v_16192;
    else goto v_16193;
v_16192:
    v_16235 = stack[-2];
    goto v_16143;
v_16193:
    goto v_16201;
v_16197:
    stack[0] = stack[-1];
    goto v_16198;
v_16199:
    v_16235 = stack[-3];
    v_16235 = qcar(v_16235);
    v_16237 = v_16235;
    v_16235 = v_16237;
    if (!consp(v_16235)) goto v_16208;
    else goto v_16209;
v_16208:
    v_16235 = v_16237;
    v_16235 = ncons(v_16235);
    env = stack[-4];
    goto v_16207;
v_16209:
    goto v_16219;
v_16215:
    v_16235 = v_16237;
    v_16236 = qcar(v_16235);
    goto v_16216;
v_16217:
    v_16235 = elt(env, 1); // null!-fn
    goto v_16218;
v_16219:
    goto v_16215;
v_16216:
    goto v_16217;
v_16218:
    if (v_16236 == v_16235) goto v_16213;
    else goto v_16214;
v_16213:
    v_16235 = v_16237;
    v_16235 = qcdr(v_16235);
    v_16235 = CC_embedKnullKfn(elt(env, 0), v_16235);
    env = stack[-4];
    goto v_16207;
v_16214:
    v_16235 = v_16237;
    v_16235 = CC_embedKnullKfn(elt(env, 0), v_16235);
    env = stack[-4];
    v_16235 = ncons(v_16235);
    env = stack[-4];
    goto v_16207;
    v_16235 = nil;
v_16207:
    goto v_16200;
v_16201:
    goto v_16197;
v_16198:
    goto v_16199;
v_16200:
    v_16235 = Lrplacd(nil, stack[0], v_16235);
    env = stack[-4];
    v_16235 = stack[-1];
    fn = elt(env, 2); // lastpair
    v_16235 = (*qfn1(fn))(fn, v_16235);
    env = stack[-4];
    stack[-1] = v_16235;
    v_16235 = stack[-3];
    v_16235 = qcdr(v_16235);
    stack[-3] = v_16235;
    goto v_16145;
v_16143:
    goto v_16132;
    v_16235 = nil;
v_16132:
    return onevalue(v_16235);
}



// Code for !*pf2sq

static LispObject CC_Hpf2sq(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16226, v_16227;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16129);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_16129;
// end of prologue
    goto v_16139;
v_16135:
    v_16227 = nil;
    goto v_16136;
v_16137:
    v_16226 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16138;
v_16139:
    goto v_16135;
v_16136:
    goto v_16137;
v_16138:
    v_16226 = cons(v_16227, v_16226);
    env = stack[-2];
    stack[-1] = v_16226;
    v_16226 = stack[0];
    if (v_16226 == nil) goto v_16144;
    else goto v_16145;
v_16144:
    v_16226 = stack[-1];
    goto v_16133;
v_16145:
    v_16226 = stack[0];
    stack[0] = v_16226;
v_16151:
    v_16226 = stack[0];
    if (v_16226 == nil) goto v_16155;
    else goto v_16156;
v_16155:
    goto v_16150;
v_16156:
    goto v_16164;
v_16160:
    goto v_16170;
v_16166:
    goto v_16179;
v_16175:
    v_16226 = stack[0];
    v_16226 = qcar(v_16226);
    v_16227 = qcar(v_16226);
    goto v_16176;
v_16177:
    v_16226 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16178;
v_16179:
    goto v_16175;
v_16176:
    goto v_16177;
v_16178:
    if (v_16227 == v_16226) goto v_16173;
    else goto v_16174;
v_16173:
    goto v_16189;
v_16185:
    v_16227 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16186;
v_16187:
    v_16226 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16188;
v_16189:
    goto v_16185;
v_16186:
    goto v_16187;
v_16188:
    v_16226 = cons(v_16227, v_16226);
    env = stack[-2];
    v_16227 = v_16226;
    goto v_16172;
v_16174:
    goto v_16199;
v_16195:
    goto v_16206;
v_16202:
    goto v_16212;
v_16208:
    v_16226 = stack[0];
    v_16226 = qcar(v_16226);
    v_16227 = qcar(v_16226);
    goto v_16209;
v_16210:
    v_16226 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16211;
v_16212:
    goto v_16208;
v_16209:
    goto v_16210;
v_16211:
    fn = elt(env, 1); // to
    v_16227 = (*qfn2(fn))(fn, v_16227, v_16226);
    env = stack[-2];
    goto v_16203;
v_16204:
    v_16226 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16205;
v_16206:
    goto v_16202;
v_16203:
    goto v_16204;
v_16205:
    v_16226 = cons(v_16227, v_16226);
    env = stack[-2];
    v_16227 = ncons(v_16226);
    env = stack[-2];
    goto v_16196;
v_16197:
    v_16226 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16198;
v_16199:
    goto v_16195;
v_16196:
    goto v_16197;
v_16198:
    v_16226 = cons(v_16227, v_16226);
    env = stack[-2];
    v_16227 = v_16226;
    goto v_16172;
    v_16227 = nil;
v_16172:
    goto v_16167;
v_16168:
    v_16226 = stack[0];
    v_16226 = qcar(v_16226);
    v_16226 = qcdr(v_16226);
    goto v_16169;
v_16170:
    goto v_16166;
v_16167:
    goto v_16168;
v_16169:
    fn = elt(env, 2); // multsq
    v_16227 = (*qfn2(fn))(fn, v_16227, v_16226);
    env = stack[-2];
    goto v_16161;
v_16162:
    v_16226 = stack[-1];
    goto v_16163;
v_16164:
    goto v_16160;
v_16161:
    goto v_16162;
v_16163:
    fn = elt(env, 3); // addsq
    v_16226 = (*qfn2(fn))(fn, v_16227, v_16226);
    env = stack[-2];
    stack[-1] = v_16226;
    v_16226 = stack[0];
    v_16226 = qcdr(v_16226);
    stack[0] = v_16226;
    goto v_16151;
v_16150:
    v_16226 = stack[-1];
v_16133:
    return onevalue(v_16226);
}



// Code for inprinla

static LispObject CC_inprinla(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16212, v_16213;
    LispObject fn;
    LispObject v_16131, v_16130, v_16129;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "inprinla");
    va_start(aa, nargs);
    v_16129 = va_arg(aa, LispObject);
    v_16130 = va_arg(aa, LispObject);
    v_16131 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_16131,v_16130,v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_16129,v_16130,v_16131);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_16131;
    stack[-1] = v_16130;
    stack[-2] = v_16129;
// end of prologue
    v_16212 = stack[-2];
    if (!symbolp(v_16212)) v_16212 = nil;
    else { v_16212 = qfastgets(v_16212);
           if (v_16212 != nil) { v_16212 = elt(v_16212, 49); // alt
#ifdef RECORD_GET
             if (v_16212 != SPID_NOPROP)
                record_get(elt(fastget_names, 49), 1);
             else record_get(elt(fastget_names, 49), 0),
                v_16212 = nil; }
           else record_get(elt(fastget_names, 49), 0); }
#else
             if (v_16212 == SPID_NOPROP) v_16212 = nil; }}
#endif
    if (v_16212 == nil) goto v_16140;
    goto v_16136;
v_16140:
    goto v_16148;
v_16144:
    v_16212 = stack[0];
    v_16213 = qcar(v_16212);
    goto v_16145;
v_16146:
    v_16212 = stack[-1];
    goto v_16147;
v_16148:
    goto v_16144;
v_16145:
    goto v_16146;
v_16147:
    fn = elt(env, 2); // maprintla
    v_16212 = (*qfn2(fn))(fn, v_16213, v_16212);
    env = stack[-4];
v_16135:
    v_16212 = stack[0];
    v_16212 = qcdr(v_16212);
    stack[0] = v_16212;
v_16136:
    v_16212 = stack[0];
    if (v_16212 == nil) goto v_16156;
    else goto v_16157;
v_16156:
    v_16212 = nil;
    goto v_16134;
v_16157:
    v_16212 = stack[0];
    v_16212 = qcar(v_16212);
    if (!consp(v_16212)) goto v_16164;
    else goto v_16165;
v_16164:
    v_16212 = lisp_true;
    goto v_16163;
v_16165:
    goto v_16175;
v_16171:
    stack[-3] = stack[-2];
    goto v_16172;
v_16173:
    goto v_16182;
v_16178:
    v_16212 = stack[0];
    v_16212 = qcar(v_16212);
    v_16213 = qcar(v_16212);
    goto v_16179;
v_16180:
    v_16212 = elt(env, 1); // alt
    goto v_16181;
v_16182:
    goto v_16178;
v_16179:
    goto v_16180;
v_16181:
    v_16212 = Lget(nil, v_16213, v_16212);
    env = stack[-4];
    goto v_16174;
v_16175:
    goto v_16171;
v_16172:
    goto v_16173;
v_16174:
    v_16212 = (stack[-3] == v_16212 ? lisp_true : nil);
    v_16212 = (v_16212 == nil ? lisp_true : nil);
    goto v_16163;
    v_16212 = nil;
v_16163:
    if (v_16212 == nil) goto v_16161;
    v_16212 = stack[-2];
    fn = elt(env, 3); // oprinla
    v_16212 = (*qfn1(fn))(fn, v_16212);
    env = stack[-4];
    goto v_16196;
v_16192:
    v_16212 = stack[0];
    v_16212 = qcar(v_16212);
    fn = elt(env, 4); // negnumberchk
    v_16213 = (*qfn1(fn))(fn, v_16212);
    env = stack[-4];
    goto v_16193;
v_16194:
    v_16212 = stack[-1];
    goto v_16195;
v_16196:
    goto v_16192;
v_16193:
    goto v_16194;
v_16195:
    fn = elt(env, 2); // maprintla
    v_16212 = (*qfn2(fn))(fn, v_16213, v_16212);
    env = stack[-4];
    goto v_16155;
v_16161:
    goto v_16208;
v_16204:
    v_16212 = stack[0];
    v_16213 = qcar(v_16212);
    goto v_16205;
v_16206:
    v_16212 = stack[-1];
    goto v_16207;
v_16208:
    goto v_16204;
v_16205:
    goto v_16206;
v_16207:
    fn = elt(env, 2); // maprintla
    v_16212 = (*qfn2(fn))(fn, v_16213, v_16212);
    env = stack[-4];
    goto v_16155;
v_16155:
    goto v_16135;
v_16134:
    return onevalue(v_16212);
}



// Code for getphystypetimes

static LispObject CC_getphystypetimes(LispObject env,
                         LispObject v_16129)
{
    env = qenv(env);
    LispObject v_16171, v_16172;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16129);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16129);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_16129;
// end of prologue
    goto v_16143;
v_16139:
    stack[-1] = nil;
    goto v_16140;
v_16141:
    v_16171 = stack[0];
    fn = elt(env, 2); // collectphystype
    v_16171 = (*qfn1(fn))(fn, v_16171);
    env = stack[-2];
    goto v_16142;
v_16143:
    goto v_16139;
v_16140:
    goto v_16141;
v_16142:
    fn = elt(env, 3); // deleteall
    v_16171 = (*qfn2(fn))(fn, stack[-1], v_16171);
    env = stack[-2];
    v_16172 = v_16171;
    if (v_16171 == nil) goto v_16136;
    else goto v_16137;
v_16136:
    v_16171 = nil;
    goto v_16133;
v_16137:
    v_16171 = v_16172;
    v_16171 = qcdr(v_16171);
    if (v_16171 == nil) goto v_16148;
    else goto v_16149;
v_16148:
    v_16171 = v_16172;
    v_16171 = qcar(v_16171);
    goto v_16133;
v_16149:
    goto v_16161;
v_16157:
    stack[-1] = elt(env, 0); // getphystypetimes
    goto v_16158;
v_16159:
    goto v_16168;
v_16164:
    v_16172 = elt(env, 1); // "PHYSOP type mismatch in"
    goto v_16165;
v_16166:
    v_16171 = stack[0];
    goto v_16167;
v_16168:
    goto v_16164;
v_16165:
    goto v_16166;
v_16167:
    v_16171 = list2(v_16172, v_16171);
    env = stack[-2];
    goto v_16160;
v_16161:
    goto v_16157;
v_16158:
    goto v_16159;
v_16160:
    fn = elt(env, 4); // rederr2
    v_16171 = (*qfn2(fn))(fn, stack[-1], v_16171);
    goto v_16135;
v_16135:
    v_16171 = nil;
v_16133:
    return onevalue(v_16171);
}



// Code for all_defined_vertex

static LispObject CC_all_defined_vertex(LispObject env,
                         LispObject v_16129, LispObject v_16130)
{
    env = qenv(env);
    LispObject v_16146, v_16147, v_16148, v_16149;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16146 = v_16130;
    v_16147 = v_16129;
// end of prologue
    goto v_16141;
v_16133:
    v_16149 = v_16147;
    goto v_16134;
v_16135:
    v_16148 = nil;
    goto v_16136;
v_16137:
    v_16147 = nil;
    goto v_16138;
v_16139:
    goto v_16140;
v_16141:
    goto v_16133;
v_16134:
    goto v_16135;
v_16136:
    goto v_16137;
v_16138:
    goto v_16139;
v_16140:
    {
        fn = elt(env, 1); // al1_defined_vertex
        return (*qfnn(fn))(fn, 4, v_16149, v_16148, v_16147, v_16146);
    }
}



setup_type const u30_setup[] =
{
    {"plubf",                   TOO_FEW_2,      CC_plubf,      WRONG_NO_2},
    {"unresidp",                CC_unresidp,    TOO_MANY_1,    WRONG_NO_1},
    {"log_inlines",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_log_inlines},
    {"quotpri",                 CC_quotpri,     TOO_MANY_1,    WRONG_NO_1},
    {"mo_2a",                   CC_mo_2a,       TOO_MANY_1,    WRONG_NO_1},
    {"cde_odd_derivatives",     CC_cde_odd_derivatives,TOO_MANY_1,WRONG_NO_1},
    {"expansion_name",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_expansion_name},
    {"formproc",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formproc},
    {"pushback",                TOO_FEW_2,      CC_pushback,   WRONG_NO_2},
    {"cl_rename-vars",          CC_cl_renameKvars,TOO_MANY_1,  WRONG_NO_1},
    {"pasf_pdp",                CC_pasf_pdp,    TOO_MANY_1,    WRONG_NO_1},
    {"omfir",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_omfir},
    {"initarg",                 CC_initarg,     TOO_MANY_1,    WRONG_NO_1},
    {"vdpcondense",             CC_vdpcondense, TOO_MANY_1,    WRONG_NO_1},
    {"edge_new_parents",        CC_edge_new_parents,TOO_MANY_1,WRONG_NO_1},
    {"idtomind",                TOO_FEW_2,      CC_idtomind,   WRONG_NO_2},
    {"gcref_off1",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gcref_off1},
    {"talp_getinvfsym",         TOO_FEW_2,      CC_talp_getinvfsym,WRONG_NO_2},
    {"qqe_eta-in-term1",        CC_qqe_etaKinKterm1,TOO_MANY_1,WRONG_NO_1},
    {"get-height",              CC_getKheight,  TOO_MANY_1,    WRONG_NO_1},
    {"lambdaom",                CC_lambdaom,    TOO_MANY_1,    WRONG_NO_1},
    {"dipsum",                  TOO_FEW_2,      CC_dipsum,     WRONG_NO_2},
    {"prop-simp2",              TOO_FEW_2,      CC_propKsimp2, WRONG_NO_2},
    {"boolvalue*",              CC_boolvalueH,  TOO_MANY_1,    WRONG_NO_1},
    {"generic-sub",             TOO_FEW_2,      CC_genericKsub,WRONG_NO_2},
    {"arminusp:",               CC_arminuspT,   TOO_MANY_1,    WRONG_NO_1},
    {"sgn1",                    TOO_FEW_2,      CC_sgn1,       WRONG_NO_2},
    {"lalr_cleanup",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lalr_cleanup},
    {"in_list1a",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_in_list1a},
    {"cl_sordpl",               TOO_FEW_2,      CC_cl_sordpl,  WRONG_NO_2},
    {"qqe_simplterm-tail",      CC_qqe_simpltermKtail,TOO_MANY_1,WRONG_NO_1},
    {"pasf_simplat1",           TOO_FEW_2,      CC_pasf_simplat1,WRONG_NO_2},
    {"bc_fd",                   CC_bc_fd,       TOO_MANY_1,    WRONG_NO_1},
    {"dvfsf_0mk2",              TOO_FEW_2,      CC_dvfsf_0mk2, WRONG_NO_2},
    {"sfto_b:ordexn",           TOO_FEW_2,      CC_sfto_bTordexn,WRONG_NO_2},
    {"testpr",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_testpr},
    {"embed-null-fn",           CC_embedKnullKfn,TOO_MANY_1,   WRONG_NO_1},
    {"*pf2sq",                  CC_Hpf2sq,      TOO_MANY_1,    WRONG_NO_1},
    {"inprinla",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_inprinla},
    {"getphystypetimes",        CC_getphystypetimes,TOO_MANY_1,WRONG_NO_1},
    {"all_defined_vertex",      TOO_FEW_2,      CC_all_defined_vertex,WRONG_NO_2},
    {NULL, (one_args *)"u30", (two_args *)"124354 7248754 6244482", 0}
};

// end of generated code
