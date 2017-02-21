
// $destdir/u55.c        Machine generated C code

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



// Code for liendimcom

static LispObject CC_liendimcom(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_33417, v_33418, v_33419, v_33420;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_32268;
// end of prologue
    v_33417 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-9] = v_33417;
    goto v_32280;
v_32276:
    stack[0] = elt(env, 1); // lie_dim
    goto v_32277;
v_32278:
    v_33417 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 14); // aeval
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32279;
v_32280:
    goto v_32276;
v_32277:
    goto v_32278;
v_32279:
    fn = elt(env, 15); // setk
    v_33417 = (*qfn2(fn))(fn, stack[0], v_33417);
    env = stack[-10];
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_33417;
v_32287:
    goto v_32301;
v_32295:
    stack[0] = elt(env, 2); // difference
    goto v_32296;
v_32297:
    goto v_32311;
v_32305:
    v_33419 = elt(env, 2); // difference
    goto v_32306;
v_32307:
    v_33418 = stack[-8];
    goto v_32308;
v_32309:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32310;
v_32311:
    goto v_32305;
v_32306:
    goto v_32307;
v_32308:
    goto v_32309;
v_32310:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32298;
v_32299:
    v_33417 = stack[-3];
    goto v_32300;
v_32301:
    goto v_32295;
v_32296:
    goto v_32297;
v_32298:
    goto v_32299;
v_32300:
    v_33417 = list3(stack[0], v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_32292;
    goto v_32286;
v_32292:
    v_33417 = stack[-3];
    stack[-2] = v_33417;
v_32320:
    goto v_32334;
v_32328:
    stack[0] = elt(env, 2); // difference
    goto v_32329;
v_32330:
    v_33417 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32331;
v_32332:
    v_33417 = stack[-2];
    goto v_32333;
v_32334:
    goto v_32328;
v_32329:
    goto v_32330;
v_32331:
    goto v_32332;
v_32333:
    v_33417 = list3(stack[0], v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_32325;
    goto v_32319;
v_32325:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_33417;
v_32343:
    goto v_32357;
v_32351:
    stack[0] = elt(env, 2); // difference
    goto v_32352;
v_32353:
    v_33417 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32354;
v_32355:
    v_33417 = stack[-1];
    goto v_32356;
v_32357:
    goto v_32351;
v_32352:
    goto v_32353;
v_32354:
    goto v_32355;
v_32356:
    v_33417 = list3(stack[0], v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_32348;
    goto v_32342;
v_32348:
    goto v_32372;
v_32368:
    goto v_32383;
v_32375:
    v_33420 = elt(env, 3); // lie_cc
    goto v_32376;
v_32377:
    v_33419 = stack[-3];
    goto v_32378;
v_32379:
    v_33418 = stack[-2];
    goto v_32380;
v_32381:
    v_33417 = stack[-1];
    goto v_32382;
v_32383:
    goto v_32375;
v_32376:
    goto v_32377;
v_32378:
    goto v_32379;
v_32380:
    goto v_32381;
v_32382:
    v_33417 = list4(v_33420, v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32369;
v_32370:
    v_33417 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32371;
v_32372:
    goto v_32368;
v_32369:
    goto v_32370;
v_32371:
    fn = elt(env, 18); // evalneq
    v_33417 = (*qfn2(fn))(fn, v_33418, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_32366;
    goto v_32394;
v_32390:
    stack[0] = elt(env, 1); // lie_dim
    goto v_32391;
v_32392:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32393;
v_32394:
    goto v_32390;
v_32391:
    goto v_32392;
v_32393:
    fn = elt(env, 15); // setk
    v_33417 = (*qfn2(fn))(fn, stack[0], v_33417);
    env = stack[-10];
    goto v_32403;
v_32399:
    stack[0] = elt(env, 4); // lie_p
    goto v_32400;
v_32401:
    v_33417 = stack[-3];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32402;
v_32403:
    goto v_32399;
v_32400:
    goto v_32401;
v_32402:
    fn = elt(env, 15); // setk
    v_33417 = (*qfn2(fn))(fn, stack[0], v_33417);
    env = stack[-10];
    goto v_32412;
v_32408:
    stack[0] = elt(env, 5); // lie_q
    goto v_32409;
v_32410:
    v_33417 = stack[-2];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32411;
v_32412:
    goto v_32408;
v_32409:
    goto v_32410;
v_32411:
    fn = elt(env, 15); // setk
    v_33417 = (*qfn2(fn))(fn, stack[0], v_33417);
    env = stack[-10];
    v_33417 = stack[-1];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-9] = v_33417;
    v_33417 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-3] = v_33417;
    goto v_32428;
v_32422:
    v_33419 = elt(env, 6); // plus
    goto v_32423;
v_32424:
    v_33418 = stack[-8];
    goto v_32425;
v_32426:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32427;
v_32428:
    goto v_32422;
v_32423:
    goto v_32424;
v_32425:
    goto v_32426;
v_32427:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-1] = v_33417;
    stack[-2] = v_33417;
    goto v_32364;
v_32366:
v_32364:
    v_33417 = stack[-1];
    goto v_32442;
v_32436:
    v_33419 = elt(env, 6); // plus
    goto v_32437;
v_32438:
    v_33418 = v_33417;
    goto v_32439;
v_32440:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32441;
v_32442:
    goto v_32436;
v_32437:
    goto v_32438;
v_32439:
    goto v_32440;
v_32441:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-1] = v_33417;
    goto v_32343;
v_32342:
    v_33417 = stack[-2];
    goto v_32456;
v_32450:
    v_33419 = elt(env, 6); // plus
    goto v_32451;
v_32452:
    v_33418 = v_33417;
    goto v_32453;
v_32454:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32455;
v_32456:
    goto v_32450;
v_32451:
    goto v_32452;
v_32453:
    goto v_32454;
v_32455:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-2] = v_33417;
    goto v_32320;
v_32319:
    v_33417 = stack[-3];
    goto v_32470;
v_32464:
    v_33419 = elt(env, 6); // plus
    goto v_32465;
v_32466:
    v_33418 = v_33417;
    goto v_32467;
v_32468:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32469;
v_32470:
    goto v_32464;
v_32465:
    goto v_32466;
v_32467:
    goto v_32468;
v_32469:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-3] = v_33417;
    goto v_32287;
v_32286:
    goto v_32483;
v_32479:
    v_33417 = elt(env, 1); // lie_dim
    fn = elt(env, 14); // aeval
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32480;
v_32481:
    v_33417 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32482;
v_32483:
    goto v_32479;
v_32480:
    goto v_32481;
v_32482:
    fn = elt(env, 18); // evalneq
    v_33417 = (*qfn2(fn))(fn, v_33418, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_32477;
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_33417;
v_32490:
    goto v_32504;
v_32498:
    stack[0] = elt(env, 2); // difference
    goto v_32499;
v_32500:
    goto v_32514;
v_32508:
    v_33419 = elt(env, 2); // difference
    goto v_32509;
v_32510:
    v_33418 = stack[-8];
    goto v_32511;
v_32512:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32513;
v_32514:
    goto v_32508;
v_32509:
    goto v_32510;
v_32511:
    goto v_32512;
v_32513:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32501;
v_32502:
    v_33417 = stack[-5];
    goto v_32503;
v_32504:
    goto v_32498;
v_32499:
    goto v_32500;
v_32501:
    goto v_32502;
v_32503:
    v_33417 = list3(stack[0], v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_32495;
    goto v_32489;
v_32495:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_33417;
v_32523:
    goto v_32537;
v_32531:
    stack[0] = elt(env, 2); // difference
    goto v_32532;
v_32533:
    v_33417 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32534;
v_32535:
    v_33417 = stack[-4];
    goto v_32536;
v_32537:
    goto v_32531;
v_32532:
    goto v_32533;
v_32534:
    goto v_32535;
v_32536:
    v_33417 = list3(stack[0], v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_32528;
    goto v_32522;
v_32528:
    goto v_32551;
v_32545:
    stack[-1] = elt(env, 7); // quotient
    goto v_32546;
v_32547:
    goto v_32562;
v_32554:
    v_33420 = elt(env, 3); // lie_cc
    goto v_32555;
v_32556:
    v_33419 = stack[-5];
    goto v_32557;
v_32558:
    v_33418 = stack[-4];
    goto v_32559;
v_32560:
    v_33417 = stack[-9];
    goto v_32561;
v_32562:
    goto v_32554;
v_32555:
    goto v_32556;
v_32557:
    goto v_32558;
v_32559:
    goto v_32560;
v_32561:
    stack[0] = list4(v_33420, v_33419, v_33418, v_33417);
    env = stack[-10];
    goto v_32548;
v_32549:
    goto v_32576;
v_32568:
    v_33420 = elt(env, 3); // lie_cc
    goto v_32569;
v_32570:
    v_33419 = elt(env, 4); // lie_p
    goto v_32571;
v_32572:
    v_33418 = elt(env, 5); // lie_q
    goto v_32573;
v_32574:
    v_33417 = stack[-9];
    goto v_32575;
v_32576:
    goto v_32568;
v_32569:
    goto v_32570;
v_32571:
    goto v_32572;
v_32573:
    goto v_32574;
v_32575:
    v_33417 = list4(v_33420, v_33419, v_33418, v_33417);
    env = stack[-10];
    goto v_32550;
v_32551:
    goto v_32545;
v_32546:
    goto v_32547;
v_32548:
    goto v_32549;
v_32550:
    v_33417 = list3(stack[-1], stack[0], v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-6] = v_33417;
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_33417;
v_32584:
    goto v_32598;
v_32592:
    stack[0] = elt(env, 2); // difference
    goto v_32593;
v_32594:
    v_33417 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32595;
v_32596:
    v_33417 = stack[-3];
    goto v_32597;
v_32598:
    goto v_32592;
v_32593:
    goto v_32594;
v_32595:
    goto v_32596;
v_32597:
    v_33417 = list3(stack[0], v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_32589;
    goto v_32583;
v_32589:
    goto v_32613;
v_32609:
    goto v_32624;
v_32616:
    v_33420 = elt(env, 3); // lie_cc
    goto v_32617;
v_32618:
    v_33419 = stack[-5];
    goto v_32619;
v_32620:
    v_33418 = stack[-4];
    goto v_32621;
v_32622:
    v_33417 = stack[-3];
    goto v_32623;
v_32624:
    goto v_32616;
v_32617:
    goto v_32618;
v_32619:
    goto v_32620;
v_32621:
    goto v_32622;
v_32623:
    v_33417 = list4(v_33420, v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    stack[-2] = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32610;
v_32611:
    goto v_32637;
v_32631:
    stack[-1] = elt(env, 8); // times
    goto v_32632;
v_32633:
    stack[0] = stack[-6];
    goto v_32634;
v_32635:
    goto v_32649;
v_32641:
    v_33420 = elt(env, 3); // lie_cc
    goto v_32642;
v_32643:
    v_33419 = elt(env, 4); // lie_p
    goto v_32644;
v_32645:
    v_33418 = elt(env, 5); // lie_q
    goto v_32646;
v_32647:
    v_33417 = stack[-3];
    goto v_32648;
v_32649:
    goto v_32641;
v_32642:
    goto v_32643;
v_32644:
    goto v_32645;
v_32646:
    goto v_32647;
v_32648:
    v_33417 = list4(v_33420, v_33419, v_33418, v_33417);
    env = stack[-10];
    goto v_32636;
v_32637:
    goto v_32631;
v_32632:
    goto v_32633;
v_32634:
    goto v_32635;
v_32636:
    v_33417 = list3(stack[-1], stack[0], v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32612;
v_32613:
    goto v_32609;
v_32610:
    goto v_32611;
v_32612:
    fn = elt(env, 18); // evalneq
    v_33417 = (*qfn2(fn))(fn, stack[-2], v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_32607;
    goto v_32659;
v_32655:
    stack[0] = elt(env, 1); // lie_dim
    goto v_32656;
v_32657:
    v_33417 = (LispObject)32+TAG_FIXNUM; // 2
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32658;
v_32659:
    goto v_32655;
v_32656:
    goto v_32657;
v_32658:
    fn = elt(env, 15); // setk
    v_33417 = (*qfn2(fn))(fn, stack[0], v_33417);
    env = stack[-10];
    v_33417 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-5] = v_33417;
    goto v_32673;
v_32667:
    v_33419 = elt(env, 6); // plus
    goto v_32668;
v_32669:
    v_33418 = stack[-8];
    goto v_32670;
v_32671:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32672;
v_32673:
    goto v_32667;
v_32668:
    goto v_32669;
v_32670:
    goto v_32671;
v_32672:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-4] = v_33417;
    goto v_32685;
v_32679:
    v_33419 = elt(env, 6); // plus
    goto v_32680;
v_32681:
    v_33418 = stack[-8];
    goto v_32682;
v_32683:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32684;
v_32685:
    goto v_32679;
v_32680:
    goto v_32681;
v_32682:
    goto v_32683;
v_32684:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-3] = v_33417;
    goto v_32605;
v_32607:
v_32605:
    v_33417 = stack[-3];
    goto v_32699;
v_32693:
    v_33419 = elt(env, 6); // plus
    goto v_32694;
v_32695:
    v_33418 = v_33417;
    goto v_32696;
v_32697:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32698;
v_32699:
    goto v_32693;
v_32694:
    goto v_32695;
v_32696:
    goto v_32697;
v_32698:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-3] = v_33417;
    goto v_32584;
v_32583:
    v_33417 = stack[-4];
    goto v_32713;
v_32707:
    v_33419 = elt(env, 6); // plus
    goto v_32708;
v_32709:
    v_33418 = v_33417;
    goto v_32710;
v_32711:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32712;
v_32713:
    goto v_32707;
v_32708:
    goto v_32709;
v_32710:
    goto v_32711;
v_32712:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-4] = v_33417;
    goto v_32523;
v_32522:
    v_33417 = stack[-5];
    goto v_32727;
v_32721:
    v_33419 = elt(env, 6); // plus
    goto v_32722;
v_32723:
    v_33418 = v_33417;
    goto v_32724;
v_32725:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32726;
v_32727:
    goto v_32721;
v_32722:
    goto v_32723;
v_32724:
    goto v_32725;
v_32726:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-5] = v_33417;
    goto v_32490;
v_32489:
    goto v_32740;
v_32736:
    v_33417 = elt(env, 1); // lie_dim
    fn = elt(env, 14); // aeval
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32737;
v_32738:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32739;
v_32740:
    goto v_32736;
v_32737:
    goto v_32738;
v_32739:
    fn = elt(env, 19); // evalequal
    v_33417 = (*qfn2(fn))(fn, v_33418, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_32734;
    goto v_32749;
v_32745:
    stack[0] = elt(env, 9); // lie_help
    goto v_32746;
v_32747:
    v_33417 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 14); // aeval
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32748;
v_32749:
    goto v_32745;
v_32746:
    goto v_32747;
v_32748:
    fn = elt(env, 15); // setk
    v_33417 = (*qfn2(fn))(fn, stack[0], v_33417);
    env = stack[-10];
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_33417;
v_32756:
    goto v_32770;
v_32764:
    stack[0] = elt(env, 2); // difference
    goto v_32765;
v_32766:
    v_33417 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32767;
v_32768:
    v_33417 = stack[-6];
    goto v_32769;
v_32770:
    goto v_32764;
v_32765:
    goto v_32766;
v_32767:
    goto v_32768;
v_32769:
    v_33417 = list3(stack[0], v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_32761;
    goto v_32755;
v_32761:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_33417;
v_32779:
    goto v_32793;
v_32787:
    stack[0] = elt(env, 2); // difference
    goto v_32788;
v_32789:
    v_33417 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32790;
v_32791:
    v_33417 = stack[-5];
    goto v_32792;
v_32793:
    goto v_32787;
v_32788:
    goto v_32789;
v_32790:
    goto v_32791;
v_32792:
    v_33417 = list3(stack[0], v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_32784;
    goto v_32778;
v_32784:
    goto v_32808;
v_32804:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_33417;
    v_33417 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_33417;
v_32813:
    goto v_32828;
v_32822:
    stack[0] = elt(env, 2); // difference
    goto v_32823;
v_32824:
    v_33417 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32825;
v_32826:
    v_33417 = stack[-4];
    goto v_32827;
v_32828:
    goto v_32822;
v_32823:
    goto v_32824;
v_32825:
    goto v_32826;
v_32827:
    v_33417 = list3(stack[0], v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_32819;
    v_33417 = stack[-3];
    v_33418 = v_33417;
    goto v_32812;
v_32819:
    goto v_32842;
v_32836:
    stack[-2] = elt(env, 6); // plus
    goto v_32837;
v_32838:
    goto v_32852;
v_32846:
    stack[-1] = elt(env, 8); // times
    goto v_32847;
v_32848:
    goto v_32863;
v_32855:
    v_33420 = elt(env, 3); // lie_cc
    goto v_32856;
v_32857:
    v_33419 = elt(env, 4); // lie_p
    goto v_32858;
v_32859:
    v_33418 = elt(env, 5); // lie_q
    goto v_32860;
v_32861:
    v_33417 = stack[-4];
    goto v_32862;
v_32863:
    goto v_32855;
v_32856:
    goto v_32857;
v_32858:
    goto v_32859;
v_32860:
    goto v_32861;
v_32862:
    stack[0] = list4(v_33420, v_33419, v_33418, v_33417);
    env = stack[-10];
    goto v_32849;
v_32850:
    goto v_32877;
v_32869:
    v_33420 = elt(env, 3); // lie_cc
    goto v_32870;
v_32871:
    v_33419 = stack[-4];
    goto v_32872;
v_32873:
    v_33418 = stack[-6];
    goto v_32874;
v_32875:
    v_33417 = stack[-5];
    goto v_32876;
v_32877:
    goto v_32869;
v_32870:
    goto v_32871;
v_32872:
    goto v_32873;
v_32874:
    goto v_32875;
v_32876:
    v_33417 = list4(v_33420, v_33419, v_33418, v_33417);
    env = stack[-10];
    goto v_32851;
v_32852:
    goto v_32846;
v_32847:
    goto v_32848;
v_32849:
    goto v_32850;
v_32851:
    v_33417 = list3(stack[-1], stack[0], v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32839;
v_32840:
    v_33417 = stack[-3];
    goto v_32841;
v_32842:
    goto v_32836;
v_32837:
    goto v_32838;
v_32839:
    goto v_32840;
v_32841:
    v_33417 = list3(stack[-2], v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-3] = v_33417;
    v_33417 = stack[-4];
    goto v_32893;
v_32887:
    v_33419 = elt(env, 6); // plus
    goto v_32888;
v_32889:
    v_33418 = v_33417;
    goto v_32890;
v_32891:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32892;
v_32893:
    goto v_32887;
v_32888:
    goto v_32889;
v_32890:
    goto v_32891;
v_32892:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-4] = v_33417;
    goto v_32813;
v_32812:
    goto v_32805;
v_32806:
    v_33417 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32807;
v_32808:
    goto v_32804;
v_32805:
    goto v_32806;
v_32807:
    fn = elt(env, 18); // evalneq
    v_33417 = (*qfn2(fn))(fn, v_33418, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_32802;
    goto v_32903;
v_32899:
    stack[0] = elt(env, 9); // lie_help
    goto v_32900;
v_32901:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32902;
v_32903:
    goto v_32899;
v_32900:
    goto v_32901;
v_32902:
    fn = elt(env, 15); // setk
    v_33417 = (*qfn2(fn))(fn, stack[0], v_33417);
    env = stack[-10];
    goto v_32912;
v_32908:
    stack[0] = elt(env, 10); // lie_s
    goto v_32909;
v_32910:
    v_33417 = stack[-6];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32911;
v_32912:
    goto v_32908;
v_32909:
    goto v_32910;
v_32911:
    fn = elt(env, 15); // setk
    v_33417 = (*qfn2(fn))(fn, stack[0], v_33417);
    env = stack[-10];
    v_33417 = stack[-5];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-9] = v_33417;
    goto v_32926;
v_32920:
    v_33419 = elt(env, 6); // plus
    goto v_32921;
v_32922:
    v_33418 = stack[-8];
    goto v_32923;
v_32924:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32925;
v_32926:
    goto v_32920;
v_32921:
    goto v_32922;
v_32923:
    goto v_32924;
v_32925:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-5] = v_33417;
    stack[-6] = v_33417;
    goto v_32800;
v_32802:
v_32800:
    v_33417 = stack[-5];
    goto v_32940;
v_32934:
    v_33419 = elt(env, 6); // plus
    goto v_32935;
v_32936:
    v_33418 = v_33417;
    goto v_32937;
v_32938:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32939;
v_32940:
    goto v_32934;
v_32935:
    goto v_32936;
v_32937:
    goto v_32938;
v_32939:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-5] = v_33417;
    goto v_32779;
v_32778:
    v_33417 = stack[-6];
    goto v_32954;
v_32948:
    v_33419 = elt(env, 6); // plus
    goto v_32949;
v_32950:
    v_33418 = v_33417;
    goto v_32951;
v_32952:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32953;
v_32954:
    goto v_32948;
v_32949:
    goto v_32950;
v_32951:
    goto v_32952;
v_32953:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-6] = v_33417;
    goto v_32756;
v_32755:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_33417;
v_32961:
    goto v_32975;
v_32969:
    stack[0] = elt(env, 2); // difference
    goto v_32970;
v_32971:
    v_33417 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32972;
v_32973:
    v_33417 = stack[-1];
    goto v_32974;
v_32975:
    goto v_32969;
v_32970:
    goto v_32971;
v_32972:
    goto v_32973;
v_32974:
    v_33417 = list3(stack[0], v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_32966;
    goto v_32960;
v_32966:
    goto v_32986;
v_32982:
    goto v_32994;
v_32988:
    v_33419 = elt(env, 11); // lientrans
    goto v_32989;
v_32990:
    v_33418 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32991;
v_32992:
    v_33417 = stack[-1];
    goto v_32993;
v_32994:
    goto v_32988;
v_32989:
    goto v_32990;
v_32991:
    goto v_32992;
v_32993:
    stack[0] = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    goto v_32983;
v_32984:
    goto v_33008;
v_33000:
    v_33420 = elt(env, 3); // lie_cc
    goto v_33001;
v_33002:
    v_33419 = elt(env, 4); // lie_p
    goto v_33003;
v_33004:
    v_33418 = elt(env, 5); // lie_q
    goto v_33005;
v_33006:
    v_33417 = stack[-1];
    goto v_33007;
v_33008:
    goto v_33000;
v_33001:
    goto v_33002;
v_33003:
    goto v_33004;
v_33005:
    goto v_33006;
v_33007:
    v_33417 = list4(v_33420, v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_32985;
v_32986:
    goto v_32982;
v_32983:
    goto v_32984;
v_32985:
    fn = elt(env, 15); // setk
    v_33417 = (*qfn2(fn))(fn, stack[0], v_33417);
    env = stack[-10];
    v_33417 = stack[-1];
    goto v_33023;
v_33017:
    v_33419 = elt(env, 6); // plus
    goto v_33018;
v_33019:
    v_33418 = v_33417;
    goto v_33020;
v_33021:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33022;
v_33023:
    goto v_33017;
v_33018:
    goto v_33019;
v_33020:
    goto v_33021;
v_33022:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-1] = v_33417;
    goto v_32961;
v_32960:
    goto v_33036;
v_33032:
    v_33417 = elt(env, 9); // lie_help
    fn = elt(env, 14); // aeval
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_33033;
v_33034:
    v_33417 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33035;
v_33036:
    goto v_33032;
v_33033:
    goto v_33034;
v_33035:
    fn = elt(env, 19); // evalequal
    v_33417 = (*qfn2(fn))(fn, v_33418, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_33030;
    goto v_33045;
v_33041:
    goto v_33053;
v_33047:
    v_33419 = elt(env, 11); // lientrans
    goto v_33048;
v_33049:
    v_33418 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_33050;
v_33051:
    v_33417 = elt(env, 4); // lie_p
    goto v_33052;
v_33053:
    goto v_33047;
v_33048:
    goto v_33049;
v_33050:
    goto v_33051;
v_33052:
    stack[-1] = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    goto v_33042;
v_33043:
    goto v_33062;
v_33058:
    goto v_33070;
v_33064:
    v_33419 = elt(env, 11); // lientrans
    goto v_33065;
v_33066:
    v_33418 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_33067;
v_33068:
    v_33417 = elt(env, 5); // lie_q
    goto v_33069;
v_33070:
    goto v_33064;
v_33065:
    goto v_33066;
v_33067:
    goto v_33068;
v_33069:
    stack[0] = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    goto v_33059;
v_33060:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 14); // aeval
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_33061;
v_33062:
    goto v_33058;
v_33059:
    goto v_33060;
v_33061:
    fn = elt(env, 15); // setk
    v_33417 = (*qfn2(fn))(fn, stack[0], v_33417);
    env = stack[-10];
    goto v_33044;
v_33045:
    goto v_33041;
v_33042:
    goto v_33043;
v_33044:
    fn = elt(env, 15); // setk
    v_33417 = (*qfn2(fn))(fn, stack[-1], v_33417);
    env = stack[-10];
    goto v_33081;
v_33077:
    stack[0] = elt(env, 12); // lie_kk!*
    goto v_33078;
v_33079:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 14); // aeval
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_33080;
v_33081:
    goto v_33077;
v_33078:
    goto v_33079;
v_33080:
    fn = elt(env, 15); // setk
    v_33417 = (*qfn2(fn))(fn, stack[0], v_33417);
    env = stack[-10];
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_33417;
v_33088:
    goto v_33102;
v_33096:
    stack[0] = elt(env, 2); // difference
    goto v_33097;
v_33098:
    v_33417 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_33099;
v_33100:
    v_33417 = stack[-1];
    goto v_33101;
v_33102:
    goto v_33096;
v_33097:
    goto v_33098;
v_33099:
    goto v_33100;
v_33101:
    v_33417 = list3(stack[0], v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_33093;
    goto v_33087;
v_33093:
    goto v_33118;
v_33114:
    goto v_33129;
v_33121:
    v_33420 = elt(env, 3); // lie_cc
    goto v_33122;
v_33123:
    v_33419 = elt(env, 4); // lie_p
    goto v_33124;
v_33125:
    v_33418 = elt(env, 5); // lie_q
    goto v_33126;
v_33127:
    v_33417 = stack[-1];
    goto v_33128;
v_33129:
    goto v_33121;
v_33122:
    goto v_33123;
v_33124:
    goto v_33125;
v_33126:
    goto v_33127;
v_33128:
    v_33417 = list4(v_33420, v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_33115;
v_33116:
    v_33417 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33117;
v_33118:
    goto v_33114;
v_33115:
    goto v_33116;
v_33117:
    fn = elt(env, 18); // evalneq
    v_33417 = (*qfn2(fn))(fn, v_33418, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_33111;
    goto v_33142;
v_33138:
    stack[0] = stack[-1];
    goto v_33139;
v_33140:
    v_33417 = elt(env, 4); // lie_p
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_33141;
v_33142:
    goto v_33138;
v_33139:
    goto v_33140;
v_33141:
    fn = elt(env, 18); // evalneq
    v_33417 = (*qfn2(fn))(fn, stack[0], v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_33111;
    goto v_33152;
v_33148:
    stack[0] = stack[-1];
    goto v_33149;
v_33150:
    v_33417 = elt(env, 5); // lie_q
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_33151;
v_33152:
    goto v_33148;
v_33149:
    goto v_33150;
v_33151:
    fn = elt(env, 18); // evalneq
    v_33417 = (*qfn2(fn))(fn, stack[0], v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_33111;
    goto v_33161;
v_33157:
    stack[0] = elt(env, 13); // lie_tt
    goto v_33158;
v_33159:
    v_33417 = stack[-1];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_33160;
v_33161:
    goto v_33157;
v_33158:
    goto v_33159;
v_33160:
    fn = elt(env, 15); // setk
    v_33417 = (*qfn2(fn))(fn, stack[0], v_33417);
    env = stack[-10];
    goto v_33173;
v_33167:
    v_33419 = elt(env, 6); // plus
    goto v_33168;
v_33169:
    v_33418 = stack[-8];
    goto v_33170;
v_33171:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33172;
v_33173:
    goto v_33167;
v_33168:
    goto v_33169;
v_33170:
    goto v_33171;
v_33172:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-1] = v_33417;
    goto v_33109;
v_33111:
v_33109:
    v_33417 = stack[-1];
    goto v_33187;
v_33181:
    v_33419 = elt(env, 6); // plus
    goto v_33182;
v_33183:
    v_33418 = v_33417;
    goto v_33184;
v_33185:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33186;
v_33187:
    goto v_33181;
v_33182:
    goto v_33183;
v_33184:
    goto v_33185;
v_33186:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-1] = v_33417;
    goto v_33088;
v_33087:
    goto v_33028;
v_33030:
    goto v_33198;
v_33194:
    goto v_33206;
v_33200:
    v_33419 = elt(env, 11); // lientrans
    goto v_33201;
v_33202:
    v_33418 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_33203;
v_33204:
    v_33417 = elt(env, 10); // lie_s
    goto v_33205;
v_33206:
    goto v_33200;
v_33201:
    goto v_33202;
v_33203:
    goto v_33204;
v_33205:
    stack[-7] = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    goto v_33195;
v_33196:
    goto v_33218;
v_33212:
    stack[-6] = elt(env, 7); // quotient
    goto v_33213;
v_33214:
    goto v_33229;
v_33221:
    v_33420 = elt(env, 3); // lie_cc
    goto v_33222;
v_33223:
    v_33419 = elt(env, 4); // lie_p
    goto v_33224;
v_33225:
    v_33418 = elt(env, 5); // lie_q
    goto v_33226;
v_33227:
    v_33417 = stack[-9];
    goto v_33228;
v_33229:
    goto v_33221;
v_33222:
    goto v_33223;
v_33224:
    goto v_33225;
v_33226:
    goto v_33227;
v_33228:
    stack[-5] = list4(v_33420, v_33419, v_33418, v_33417);
    env = stack[-10];
    goto v_33215;
v_33216:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_33417;
    v_33417 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_33417;
v_33238:
    goto v_33253;
v_33247:
    stack[0] = elt(env, 2); // difference
    goto v_33248;
v_33249:
    v_33417 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_33250;
v_33251:
    v_33417 = stack[-4];
    goto v_33252;
v_33253:
    goto v_33247;
v_33248:
    goto v_33249;
v_33250:
    goto v_33251;
v_33252:
    v_33417 = list3(stack[0], v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_33244;
    v_33417 = stack[-3];
    goto v_33237;
v_33244:
    goto v_33267;
v_33261:
    stack[-2] = elt(env, 6); // plus
    goto v_33262;
v_33263:
    goto v_33277;
v_33271:
    stack[-1] = elt(env, 8); // times
    goto v_33272;
v_33273:
    goto v_33288;
v_33280:
    v_33420 = elt(env, 3); // lie_cc
    goto v_33281;
v_33282:
    v_33419 = elt(env, 4); // lie_p
    goto v_33283;
v_33284:
    v_33418 = elt(env, 5); // lie_q
    goto v_33285;
v_33286:
    v_33417 = stack[-4];
    goto v_33287;
v_33288:
    goto v_33280;
v_33281:
    goto v_33282;
v_33283:
    goto v_33284;
v_33285:
    goto v_33286;
v_33287:
    stack[0] = list4(v_33420, v_33419, v_33418, v_33417);
    env = stack[-10];
    goto v_33274;
v_33275:
    goto v_33302;
v_33294:
    v_33420 = elt(env, 3); // lie_cc
    goto v_33295;
v_33296:
    v_33419 = stack[-4];
    goto v_33297;
v_33298:
    v_33418 = elt(env, 10); // lie_s
    goto v_33299;
v_33300:
    v_33417 = stack[-9];
    goto v_33301;
v_33302:
    goto v_33294;
v_33295:
    goto v_33296;
v_33297:
    goto v_33298;
v_33299:
    goto v_33300;
v_33301:
    v_33417 = list4(v_33420, v_33419, v_33418, v_33417);
    env = stack[-10];
    goto v_33276;
v_33277:
    goto v_33271;
v_33272:
    goto v_33273;
v_33274:
    goto v_33275;
v_33276:
    v_33417 = list3(stack[-1], stack[0], v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_33264;
v_33265:
    v_33417 = stack[-3];
    goto v_33266;
v_33267:
    goto v_33261;
v_33262:
    goto v_33263;
v_33264:
    goto v_33265;
v_33266:
    v_33417 = list3(stack[-2], v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-3] = v_33417;
    v_33417 = stack[-4];
    goto v_33318;
v_33312:
    v_33419 = elt(env, 6); // plus
    goto v_33313;
v_33314:
    v_33418 = v_33417;
    goto v_33315;
v_33316:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33317;
v_33318:
    goto v_33312;
v_33313:
    goto v_33314;
v_33315:
    goto v_33316;
v_33317:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-4] = v_33417;
    goto v_33238;
v_33237:
    goto v_33217;
v_33218:
    goto v_33212;
v_33213:
    goto v_33214;
v_33215:
    goto v_33216;
v_33217:
    v_33417 = list3(stack[-6], stack[-5], v_33417);
    env = stack[-10];
    fn = elt(env, 14); // aeval
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_33197;
v_33198:
    goto v_33194;
v_33195:
    goto v_33196;
v_33197:
    fn = elt(env, 15); // setk
    v_33417 = (*qfn2(fn))(fn, stack[-7], v_33417);
    env = stack[-10];
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_33417;
v_33325:
    goto v_33339;
v_33333:
    stack[0] = elt(env, 2); // difference
    goto v_33334;
v_33335:
    v_33417 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_33336;
v_33337:
    v_33417 = stack[-1];
    goto v_33338;
v_33339:
    goto v_33333;
v_33334:
    goto v_33335;
v_33336:
    goto v_33337;
v_33338:
    v_33417 = list3(stack[0], v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_33330;
    goto v_33324;
v_33330:
    goto v_33355;
v_33351:
    goto v_33366;
v_33358:
    v_33420 = elt(env, 3); // lie_cc
    goto v_33359;
v_33360:
    v_33419 = elt(env, 4); // lie_p
    goto v_33361;
v_33362:
    v_33418 = elt(env, 5); // lie_q
    goto v_33363;
v_33364:
    v_33417 = stack[-1];
    goto v_33365;
v_33366:
    goto v_33358;
v_33359:
    goto v_33360;
v_33361:
    goto v_33362;
v_33363:
    goto v_33364;
v_33365:
    v_33417 = list4(v_33420, v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33418 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_33352;
v_33353:
    v_33417 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33354;
v_33355:
    goto v_33351;
v_33352:
    goto v_33353;
v_33354:
    fn = elt(env, 18); // evalneq
    v_33417 = (*qfn2(fn))(fn, v_33418, v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_33348;
    goto v_33378;
v_33374:
    stack[0] = stack[-1];
    goto v_33375;
v_33376:
    v_33417 = elt(env, 10); // lie_s
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_33377;
v_33378:
    goto v_33374;
v_33375:
    goto v_33376;
v_33377:
    fn = elt(env, 18); // evalneq
    v_33417 = (*qfn2(fn))(fn, stack[0], v_33417);
    env = stack[-10];
    if (v_33417 == nil) goto v_33348;
    goto v_33387;
v_33383:
    stack[0] = elt(env, 13); // lie_tt
    goto v_33384;
v_33385:
    v_33417 = stack[-1];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    goto v_33386;
v_33387:
    goto v_33383;
v_33384:
    goto v_33385;
v_33386:
    fn = elt(env, 15); // setk
    v_33417 = (*qfn2(fn))(fn, stack[0], v_33417);
    env = stack[-10];
    goto v_33399;
v_33393:
    v_33419 = elt(env, 6); // plus
    goto v_33394;
v_33395:
    v_33418 = stack[-8];
    goto v_33396;
v_33397:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33398;
v_33399:
    goto v_33393;
v_33394:
    goto v_33395;
v_33396:
    goto v_33397;
v_33398:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-1] = v_33417;
    goto v_33346;
v_33348:
v_33346:
    v_33417 = stack[-1];
    goto v_33413;
v_33407:
    v_33419 = elt(env, 6); // plus
    goto v_33408;
v_33409:
    v_33418 = v_33417;
    goto v_33410;
v_33411:
    v_33417 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33412;
v_33413:
    goto v_33407;
v_33408:
    goto v_33409;
v_33410:
    goto v_33411;
v_33412:
    v_33417 = list3(v_33419, v_33418, v_33417);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33417 = (*qfn1(fn))(fn, v_33417);
    env = stack[-10];
    stack[-1] = v_33417;
    goto v_33325;
v_33324:
    goto v_33028;
v_33028:
    goto v_32732;
v_32734:
v_32732:
    goto v_32475;
v_32477:
v_32475:
    v_33417 = nil;
    return onevalue(v_33417);
}



// Code for dpmat_gbtag

static LispObject CC_dpmat_gbtag(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32278, v_32279;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_32278 = v_32268;
// end of prologue
    goto v_32275;
v_32271:
    v_32279 = v_32278;
    goto v_32272;
v_32273:
    v_32278 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_32274;
v_32275:
    goto v_32271;
v_32272:
    goto v_32273;
v_32274:
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(fn, v_32279, v_32278);
    }
}



// Code for st_extract_symcells1

static LispObject CC_st_extract_symcells1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_32437, v_32438, v_32439;
    LispObject fn;
    LispObject v_32270, v_32269, v_32268;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "st_extract_symcells1");
    va_start(aa, nargs);
    v_32268 = va_arg(aa, LispObject);
    v_32269 = va_arg(aa, LispObject);
    v_32270 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_32270,v_32269,v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_32268,v_32269,v_32270);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_32270;
    stack[-5] = v_32269;
    stack[0] = v_32268;
// end of prologue
    v_32437 = stack[0];
    v_32437 = qcdr(v_32437);
    v_32437 = qcar(v_32437);
    fn = elt(env, 2); // listp
    v_32437 = (*qfn1(fn))(fn, v_32437);
    env = stack[-7];
    if (v_32437 == nil) goto v_32278;
    else goto v_32279;
v_32278:
    goto v_32291;
v_32285:
    stack[-1] = stack[-4];
    goto v_32286;
v_32287:
    goto v_32298;
v_32294:
    v_32438 = stack[0];
    goto v_32295;
v_32296:
    v_32437 = stack[-5];
    goto v_32297;
v_32298:
    goto v_32294;
v_32295:
    goto v_32296;
v_32297:
    stack[0] = cons(v_32438, v_32437);
    env = stack[-7];
    goto v_32288;
v_32289:
    v_32437 = stack[-4];
    v_32437 = add1(v_32437);
    goto v_32290;
v_32291:
    goto v_32285;
v_32286:
    goto v_32287;
v_32288:
    goto v_32289;
v_32290:
    {
        LispObject v_32447 = stack[-1];
        LispObject v_32448 = stack[0];
        return list3(v_32447, v_32448, v_32437);
    }
v_32279:
    goto v_32310;
v_32306:
    v_32437 = stack[0];
    stack[-6] = qcar(v_32437);
    goto v_32307;
v_32308:
    v_32437 = stack[0];
    v_32437 = qcdr(v_32437);
    stack[-3] = v_32437;
    v_32437 = stack[-3];
    if (v_32437 == nil) goto v_32323;
    else goto v_32324;
v_32323:
    v_32437 = nil;
    goto v_32317;
v_32324:
    v_32437 = stack[-3];
    v_32437 = qcar(v_32437);
    goto v_32338;
v_32332:
    v_32439 = v_32437;
    goto v_32333;
v_32334:
    v_32438 = stack[-5];
    goto v_32335;
v_32336:
    v_32437 = stack[-4];
    goto v_32337;
v_32338:
    goto v_32332;
v_32333:
    goto v_32334;
v_32335:
    goto v_32336;
v_32337:
    v_32437 = CC_st_extract_symcells1(elt(env, 0), 3, v_32439, v_32438, v_32437);
    env = stack[-7];
    v_32438 = v_32437;
    v_32438 = qcdr(v_32438);
    v_32438 = qcar(v_32438);
    stack[-5] = v_32438;
    v_32438 = v_32437;
    v_32438 = qcdr(v_32438);
    v_32438 = qcdr(v_32438);
    v_32438 = qcar(v_32438);
    stack[-4] = v_32438;
    v_32438 = v_32437;
    v_32438 = qcar(v_32438);
    if (is_number(v_32438)) goto v_32351;
    else goto v_32352;
v_32351:
    goto v_32360;
v_32356:
    v_32438 = elt(env, 1); // !*
    goto v_32357;
v_32358:
    v_32437 = qcar(v_32437);
    goto v_32359;
v_32360:
    goto v_32356;
v_32357:
    goto v_32358;
v_32359:
    v_32437 = list2(v_32438, v_32437);
    env = stack[-7];
    goto v_32350;
v_32352:
    v_32437 = qcar(v_32437);
    goto v_32350;
    v_32437 = nil;
v_32350:
    v_32437 = ncons(v_32437);
    env = stack[-7];
    stack[-1] = v_32437;
    stack[-2] = v_32437;
v_32318:
    v_32437 = stack[-3];
    v_32437 = qcdr(v_32437);
    stack[-3] = v_32437;
    v_32437 = stack[-3];
    if (v_32437 == nil) goto v_32372;
    else goto v_32373;
v_32372:
    v_32437 = stack[-2];
    goto v_32317;
v_32373:
    goto v_32381;
v_32377:
    stack[0] = stack[-1];
    goto v_32378;
v_32379:
    v_32437 = stack[-3];
    v_32437 = qcar(v_32437);
    goto v_32394;
v_32388:
    v_32439 = v_32437;
    goto v_32389;
v_32390:
    v_32438 = stack[-5];
    goto v_32391;
v_32392:
    v_32437 = stack[-4];
    goto v_32393;
v_32394:
    goto v_32388;
v_32389:
    goto v_32390;
v_32391:
    goto v_32392;
v_32393:
    v_32437 = CC_st_extract_symcells1(elt(env, 0), 3, v_32439, v_32438, v_32437);
    env = stack[-7];
    v_32438 = v_32437;
    v_32438 = qcdr(v_32438);
    v_32438 = qcar(v_32438);
    stack[-5] = v_32438;
    v_32438 = v_32437;
    v_32438 = qcdr(v_32438);
    v_32438 = qcdr(v_32438);
    v_32438 = qcar(v_32438);
    stack[-4] = v_32438;
    v_32438 = v_32437;
    v_32438 = qcar(v_32438);
    if (is_number(v_32438)) goto v_32407;
    else goto v_32408;
v_32407:
    goto v_32416;
v_32412:
    v_32438 = elt(env, 1); // !*
    goto v_32413;
v_32414:
    v_32437 = qcar(v_32437);
    goto v_32415;
v_32416:
    goto v_32412;
v_32413:
    goto v_32414;
v_32415:
    v_32437 = list2(v_32438, v_32437);
    env = stack[-7];
    goto v_32406;
v_32408:
    v_32437 = qcar(v_32437);
    goto v_32406;
    v_32437 = nil;
v_32406:
    v_32437 = ncons(v_32437);
    env = stack[-7];
    goto v_32380;
v_32381:
    goto v_32377;
v_32378:
    goto v_32379;
v_32380:
    v_32437 = Lrplacd(nil, stack[0], v_32437);
    env = stack[-7];
    v_32437 = stack[-1];
    v_32437 = qcdr(v_32437);
    stack[-1] = v_32437;
    goto v_32318;
v_32317:
    goto v_32309;
v_32310:
    goto v_32306;
v_32307:
    goto v_32308;
v_32309:
    v_32437 = cons(stack[-6], v_32437);
    goto v_32433;
v_32427:
    v_32439 = v_32437;
    goto v_32428;
v_32429:
    v_32438 = stack[-5];
    goto v_32430;
v_32431:
    v_32437 = stack[-4];
    goto v_32432;
v_32433:
    goto v_32427;
v_32428:
    goto v_32429;
v_32430:
    goto v_32431;
v_32432:
    return list3(v_32439, v_32438, v_32437);
    v_32437 = nil;
    return onevalue(v_32437);
}



// Code for addcoeffs

static LispObject CC_addcoeffs(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_32394, v_32395, v_32396, v_32397;
    LispObject fn;
    LispObject v_32271, v_32270, v_32269, v_32268;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "addcoeffs");
    va_start(aa, nargs);
    v_32268 = va_arg(aa, LispObject);
    v_32269 = va_arg(aa, LispObject);
    v_32270 = va_arg(aa, LispObject);
    v_32271 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_32271,v_32270,v_32269,v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_32268,v_32269,v_32270,v_32271);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_32271;
    stack[-2] = v_32270;
    stack[-3] = v_32269;
    stack[-4] = v_32268;
// end of prologue
    goto v_32282;
v_32278:
    v_32395 = nil;
    goto v_32279;
v_32280:
    v_32394 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32281;
v_32282:
    goto v_32278;
v_32279:
    goto v_32280;
v_32281:
    v_32394 = cons(v_32395, v_32394);
    env = stack[-6];
    stack[0] = v_32394;
    goto v_32290;
v_32286:
    v_32394 = stack[-4];
    fn = elt(env, 1); // smallest!-increment
    stack[-5] = (*qfn1(fn))(fn, v_32394);
    env = stack[-6];
    goto v_32287;
v_32288:
    v_32394 = stack[-3];
    fn = elt(env, 1); // smallest!-increment
    v_32394 = (*qfn1(fn))(fn, v_32394);
    env = stack[-6];
    goto v_32289;
v_32290:
    goto v_32286;
v_32287:
    goto v_32288;
v_32289:
    fn = elt(env, 2); // common!-increment
    v_32394 = (*qfn2(fn))(fn, stack[-5], v_32394);
    env = stack[-6];
    goto v_32308;
v_32300:
    v_32397 = stack[-2];
    goto v_32301;
v_32302:
    v_32396 = stack[-1];
    goto v_32303;
v_32304:
    v_32395 = stack[-3];
    v_32395 = qcar(v_32395);
    v_32395 = qcar(v_32395);
    goto v_32305;
v_32306:
    goto v_32307;
v_32308:
    goto v_32300;
v_32301:
    goto v_32302;
v_32303:
    goto v_32304;
v_32305:
    goto v_32306;
v_32307:
    fn = elt(env, 3); // makecoeffpairs
    v_32394 = (*qfnn(fn))(fn, 4, v_32397, v_32396, v_32395, v_32394);
    env = stack[-6];
    stack[-5] = v_32394;
v_32298:
    v_32394 = stack[-5];
    if (v_32394 == nil) goto v_32317;
    else goto v_32318;
v_32317:
    goto v_32297;
v_32318:
    v_32394 = stack[-5];
    v_32394 = qcar(v_32394);
    stack[-2] = v_32394;
    goto v_32329;
v_32325:
    stack[-1] = stack[0];
    goto v_32326;
v_32327:
    goto v_32336;
v_32332:
    goto v_32341;
v_32337:
    v_32394 = stack[-2];
    v_32395 = qcar(v_32394);
    goto v_32338;
v_32339:
    v_32394 = stack[-4];
    goto v_32340;
v_32341:
    goto v_32337;
v_32338:
    goto v_32339;
v_32340:
    v_32394 = Lassoc(nil, v_32395, v_32394);
    v_32395 = v_32394;
    v_32394 = v_32395;
    if (v_32394 == nil) goto v_32349;
    else goto v_32350;
v_32349:
    goto v_32357;
v_32353:
    v_32395 = nil;
    goto v_32354;
v_32355:
    v_32394 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32356;
v_32357:
    goto v_32353;
v_32354:
    goto v_32355;
v_32356:
    v_32394 = cons(v_32395, v_32394);
    env = stack[-6];
    stack[0] = v_32394;
    goto v_32348;
v_32350:
    v_32394 = v_32395;
    v_32394 = qcdr(v_32394);
    stack[0] = v_32394;
    goto v_32348;
    stack[0] = nil;
v_32348:
    goto v_32333;
v_32334:
    goto v_32368;
v_32364:
    v_32394 = stack[-2];
    v_32395 = qcdr(v_32394);
    goto v_32365;
v_32366:
    v_32394 = stack[-3];
    goto v_32367;
v_32368:
    goto v_32364;
v_32365:
    goto v_32366;
v_32367:
    v_32394 = Lassoc(nil, v_32395, v_32394);
    v_32395 = v_32394;
    v_32394 = v_32395;
    if (v_32394 == nil) goto v_32376;
    else goto v_32377;
v_32376:
    goto v_32384;
v_32380:
    v_32395 = nil;
    goto v_32381;
v_32382:
    v_32394 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32383;
v_32384:
    goto v_32380;
v_32381:
    goto v_32382;
v_32383:
    v_32394 = cons(v_32395, v_32394);
    env = stack[-6];
    goto v_32375;
v_32377:
    v_32394 = v_32395;
    v_32394 = qcdr(v_32394);
    goto v_32375;
    v_32394 = nil;
v_32375:
    goto v_32335;
v_32336:
    goto v_32332;
v_32333:
    goto v_32334;
v_32335:
    fn = elt(env, 4); // multsq
    v_32394 = (*qfn2(fn))(fn, stack[0], v_32394);
    env = stack[-6];
    goto v_32328;
v_32329:
    goto v_32325;
v_32326:
    goto v_32327;
v_32328:
    fn = elt(env, 5); // addsq
    v_32394 = (*qfn2(fn))(fn, stack[-1], v_32394);
    env = stack[-6];
    stack[0] = v_32394;
    v_32394 = stack[-5];
    v_32394 = qcdr(v_32394);
    stack[-5] = v_32394;
    goto v_32298;
v_32297:
    v_32394 = stack[0];
    return onevalue(v_32394);
}



// Code for qqe_simpat

static LispObject CC_qqe_simpat(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32271;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_32271 = v_32268;
// end of prologue
    return onevalue(v_32271);
}



// Code for bc_minus!?

static LispObject CC_bc_minusW(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32291, v_32292;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_32292 = v_32268;
// end of prologue
    v_32291 = v_32292;
    v_32291 = qcar(v_32291);
    v_32291 = integerp(v_32291);
    if (v_32291 == nil) goto v_32273;
    goto v_32282;
v_32278:
    v_32291 = v_32292;
    v_32292 = qcar(v_32291);
    goto v_32279;
v_32280:
    v_32291 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32281;
v_32282:
    goto v_32278;
v_32279:
    goto v_32280;
v_32281:
        return Llessp(nil, v_32292, v_32291);
v_32273:
    v_32291 = v_32292;
    v_32291 = qcar(v_32291);
    {
        fn = elt(env, 1); // minusf
        return (*qfn1(fn))(fn, v_32291);
    }
    v_32291 = nil;
    return onevalue(v_32291);
}



// Code for crprimp

static LispObject CC_crprimp(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32312, v_32313, v_32314;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_32314 = v_32268;
// end of prologue
    goto v_32278;
v_32274:
    v_32313 = v_32314;
    goto v_32275;
v_32276:
    v_32312 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32277;
v_32278:
    goto v_32274;
v_32275:
    goto v_32276;
v_32277:
    if (v_32313 == v_32312) goto v_32272;
    else goto v_32273;
v_32272:
    v_32312 = elt(env, 1); // i
    goto v_32271;
v_32273:
    goto v_32288;
v_32284:
    v_32313 = v_32314;
    goto v_32285;
v_32286:
    v_32312 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_32287;
v_32288:
    goto v_32284;
v_32285:
    goto v_32286;
v_32287:
    if (v_32313 == v_32312) goto v_32282;
    else goto v_32283;
v_32282:
    goto v_32296;
v_32292:
    v_32312 = elt(env, 2); // minus
    goto v_32293;
v_32294:
    v_32313 = elt(env, 1); // i
    goto v_32295;
v_32296:
    goto v_32292;
v_32293:
    goto v_32294;
v_32295:
    return list2(v_32312, v_32313);
v_32283:
    goto v_32308;
v_32302:
    v_32312 = elt(env, 3); // times
    goto v_32303;
v_32304:
    v_32313 = v_32314;
    goto v_32305;
v_32306:
    v_32314 = elt(env, 1); // i
    goto v_32307;
v_32308:
    goto v_32302;
v_32303:
    goto v_32304;
v_32305:
    goto v_32306;
v_32307:
    return list3(v_32312, v_32313, v_32314);
    v_32312 = nil;
v_32271:
    return onevalue(v_32312);
}



// Code for remove_critical_pairs

static LispObject CC_remove_critical_pairs(LispObject env,
                         LispObject v_32268, LispObject v_32269)
{
    env = qenv(env);
    LispObject v_32285, v_32286;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_32269,v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_32268,v_32269);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_32269;
    v_32285 = v_32268;
// end of prologue
    v_32286 = v_32285;
    if (v_32286 == nil) goto v_32274;
    goto v_32281;
v_32277:
    v_32286 = stack[0];
    goto v_32278;
v_32279:
    goto v_32280;
v_32281:
    goto v_32277;
v_32278:
    goto v_32279;
v_32280:
    fn = elt(env, 1); // remove_items
    v_32285 = (*qfn2(fn))(fn, v_32286, v_32285);
    goto v_32272;
v_32274:
v_32272:
    v_32285 = stack[0];
    return onevalue(v_32285);
}



// Code for acmemb

static LispObject CC_acmemb(LispObject env,
                         LispObject v_32268, LispObject v_32269)
{
    env = qenv(env);
    LispObject v_32297, v_32298;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_32269,v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_32268,v_32269);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_32269;
    stack[-1] = v_32268;
// end of prologue
v_32273:
    v_32297 = stack[0];
    if (v_32297 == nil) goto v_32276;
    else goto v_32277;
v_32276:
    v_32297 = nil;
    goto v_32272;
v_32277:
    goto v_32287;
v_32283:
    v_32298 = stack[-1];
    goto v_32284;
v_32285:
    v_32297 = stack[0];
    v_32297 = qcar(v_32297);
    goto v_32286;
v_32287:
    goto v_32283;
v_32284:
    goto v_32285;
v_32286:
    fn = elt(env, 1); // aceq
    v_32297 = (*qfn2(fn))(fn, v_32298, v_32297);
    env = stack[-2];
    if (v_32297 == nil) goto v_32281;
    v_32297 = stack[0];
    v_32297 = qcar(v_32297);
    goto v_32272;
v_32281:
    v_32297 = stack[0];
    v_32297 = qcdr(v_32297);
    stack[0] = v_32297;
    goto v_32273;
    v_32297 = nil;
v_32272:
    return onevalue(v_32297);
}



// Code for physopplus

static LispObject CC_physopplus(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32339, v_32340;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_32268;
// end of prologue
    v_32339 = stack[0];
    v_32339 = qcar(v_32339);
    fn = elt(env, 2); // physopsim!*
    v_32339 = (*qfn1(fn))(fn, v_32339);
    env = stack[-4];
    stack[-3] = v_32339;
    v_32339 = stack[0];
    v_32339 = qcdr(v_32339);
    stack[0] = v_32339;
v_32282:
    v_32339 = stack[0];
    if (v_32339 == nil) goto v_32287;
    else goto v_32288;
v_32287:
    goto v_32281;
v_32288:
    v_32339 = stack[0];
    v_32339 = qcar(v_32339);
    fn = elt(env, 2); // physopsim!*
    v_32339 = (*qfn1(fn))(fn, v_32339);
    env = stack[-4];
    stack[-2] = v_32339;
    v_32339 = stack[-3];
    fn = elt(env, 3); // getphystype
    v_32339 = (*qfn1(fn))(fn, v_32339);
    env = stack[-4];
    stack[-1] = v_32339;
    v_32339 = stack[-2];
    fn = elt(env, 3); // getphystype
    v_32339 = (*qfn1(fn))(fn, v_32339);
    env = stack[-4];
    v_32340 = v_32339;
    if (v_32340 == nil) goto v_32303;
    v_32340 = stack[-1];
    if (v_32340 == nil) goto v_32303;
    goto v_32314;
v_32310:
    v_32340 = stack[-1];
    goto v_32311;
v_32312:
    goto v_32313;
v_32314:
    goto v_32310;
v_32311:
    goto v_32312;
v_32313:
    if (v_32340 == v_32339) goto v_32303;
    goto v_32322;
v_32318:
    v_32340 = elt(env, 0); // physopplus
    goto v_32319;
v_32320:
    v_32339 = elt(env, 1); // "type mismatch in plus "
    goto v_32321;
v_32322:
    goto v_32318;
v_32319:
    goto v_32320;
v_32321:
    fn = elt(env, 4); // rederr2
    v_32339 = (*qfn2(fn))(fn, v_32340, v_32339);
    env = stack[-4];
    goto v_32301;
v_32303:
v_32301:
    goto v_32331;
v_32327:
    v_32339 = stack[-3];
    fn = elt(env, 5); // physop2sq
    stack[-1] = (*qfn1(fn))(fn, v_32339);
    env = stack[-4];
    goto v_32328;
v_32329:
    v_32339 = stack[-2];
    fn = elt(env, 5); // physop2sq
    v_32339 = (*qfn1(fn))(fn, v_32339);
    env = stack[-4];
    goto v_32330;
v_32331:
    goto v_32327;
v_32328:
    goto v_32329;
v_32330:
    fn = elt(env, 6); // addsq
    v_32339 = (*qfn2(fn))(fn, stack[-1], v_32339);
    env = stack[-4];
    fn = elt(env, 7); // mk!*sq
    v_32339 = (*qfn1(fn))(fn, v_32339);
    env = stack[-4];
    stack[-3] = v_32339;
    v_32339 = stack[0];
    v_32339 = qcdr(v_32339);
    stack[0] = v_32339;
    goto v_32282;
v_32281:
    v_32339 = stack[-3];
    return onevalue(v_32339);
}



// Code for bassoc

static LispObject CC_bassoc(LispObject env,
                         LispObject v_32268, LispObject v_32269)
{
    env = qenv(env);
    LispObject v_32297, v_32298;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_32269,v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_32268,v_32269);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_32269;
    stack[-1] = v_32268;
// end of prologue
v_32273:
    v_32297 = stack[0];
    if (v_32297 == nil) goto v_32276;
    else goto v_32277;
v_32276:
    v_32297 = nil;
    goto v_32272;
v_32277:
    goto v_32287;
v_32283:
    v_32298 = stack[-1];
    goto v_32284;
v_32285:
    v_32297 = stack[0];
    v_32297 = qcar(v_32297);
    v_32297 = qcar(v_32297);
    goto v_32286;
v_32287:
    goto v_32283;
v_32284:
    goto v_32285;
v_32286:
    fn = elt(env, 1); // th_match
    v_32297 = (*qfn2(fn))(fn, v_32298, v_32297);
    env = stack[-2];
    if (v_32297 == nil) goto v_32281;
    v_32297 = stack[0];
    goto v_32272;
v_32281:
    v_32297 = stack[0];
    v_32297 = qcdr(v_32297);
    stack[0] = v_32297;
    goto v_32273;
    v_32297 = nil;
v_32272:
    return onevalue(v_32297);
}



// Code for !*sq2fourier

static LispObject CC_Hsq2fourier(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32339, v_32340, v_32341;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_32268;
// end of prologue
    v_32339 = stack[0];
    v_32339 = qcar(v_32339);
    if (v_32339 == nil) goto v_32272;
    else goto v_32273;
v_32272:
    v_32339 = nil;
    goto v_32271;
v_32273:
    v_32339 = (LispObject)48+TAG_FIXNUM; // 3
    v_32339 = Lmkvect(nil, v_32339);
    env = stack[-3];
    stack[-2] = v_32339;
    goto v_32290;
v_32284:
    v_32341 = stack[-2];
    goto v_32285;
v_32286:
    v_32340 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32287;
v_32288:
    v_32339 = stack[0];
    goto v_32289;
v_32290:
    goto v_32284;
v_32285:
    goto v_32286;
v_32287:
    goto v_32288;
v_32289:
    *(LispObject *)((char *)v_32341 + (CELL-TAG_VECTOR) + (((intptr_t)v_32340-TAG_FIXNUM)/(16/CELL))) = v_32339;
    goto v_32300;
v_32294:
    v_32341 = stack[-2];
    goto v_32295;
v_32296:
    v_32340 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32297;
v_32298:
    v_32339 = elt(env, 1); // cos
    goto v_32299;
v_32300:
    goto v_32294;
v_32295:
    goto v_32296;
v_32297:
    goto v_32298;
v_32299:
    *(LispObject *)((char *)v_32341 + (CELL-TAG_VECTOR) + (((intptr_t)v_32340-TAG_FIXNUM)/(16/CELL))) = v_32339;
    goto v_32310;
v_32304:
    stack[-1] = stack[-2];
    goto v_32305;
v_32306:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_32307;
v_32308:
    fn = elt(env, 4); // fs!:make!-nullangle
    v_32339 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_32309;
v_32310:
    goto v_32304;
v_32305:
    goto v_32306;
v_32307:
    goto v_32308;
v_32309:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_32339;
    goto v_32320;
v_32314:
    v_32341 = stack[-2];
    goto v_32315;
v_32316:
    v_32340 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_32317;
v_32318:
    v_32339 = nil;
    goto v_32319;
v_32320:
    goto v_32314;
v_32315:
    goto v_32316;
v_32317:
    goto v_32318;
v_32319:
    *(LispObject *)((char *)v_32341 + (CELL-TAG_VECTOR) + (((intptr_t)v_32340-TAG_FIXNUM)/(16/CELL))) = v_32339;
    goto v_32329;
v_32325:
    goto v_32335;
v_32331:
    v_32340 = elt(env, 2); // fourier
    goto v_32332;
v_32333:
    v_32339 = elt(env, 3); // tag
    goto v_32334;
v_32335:
    goto v_32331;
v_32332:
    goto v_32333;
v_32334:
    v_32340 = get(v_32340, v_32339);
    goto v_32326;
v_32327:
    v_32339 = stack[-2];
    goto v_32328;
v_32329:
    goto v_32325;
v_32326:
    goto v_32327;
v_32328:
    return cons(v_32340, v_32339);
    goto v_32271;
    v_32339 = nil;
v_32271:
    return onevalue(v_32339);
}



// Code for all_index_lst

static LispObject CC_all_index_lst(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32336, v_32337;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_32268;
// end of prologue
    stack[-2] = nil;
v_32274:
    v_32336 = stack[-1];
    if (v_32336 == nil) goto v_32279;
    else goto v_32280;
v_32279:
    goto v_32275;
v_32280:
    goto v_32287;
v_32283:
    v_32336 = stack[-1];
    v_32336 = qcar(v_32336);
    v_32336 = qcdr(v_32336);
    stack[0] = v_32336;
    v_32336 = stack[0];
    v_32336 = qcar(v_32336);
    fn = elt(env, 2); // listp
    v_32336 = (*qfn1(fn))(fn, v_32336);
    env = stack[-3];
    if (v_32336 == nil) goto v_32295;
    goto v_32305;
v_32301:
    v_32336 = stack[0];
    v_32336 = qcar(v_32336);
    v_32337 = qcar(v_32336);
    goto v_32302;
v_32303:
    v_32336 = elt(env, 1); // list
    goto v_32304;
v_32305:
    goto v_32301;
v_32302:
    goto v_32303;
v_32304:
    if (v_32337 == v_32336) goto v_32300;
    else goto v_32295;
v_32300:
    v_32336 = stack[0];
    v_32336 = qcdr(v_32336);
    v_32337 = v_32336;
    goto v_32293;
v_32295:
    v_32336 = stack[0];
    v_32337 = v_32336;
    goto v_32293;
    v_32337 = nil;
v_32293:
    goto v_32284;
v_32285:
    v_32336 = stack[-2];
    goto v_32286;
v_32287:
    goto v_32283;
v_32284:
    goto v_32285;
v_32286:
    v_32336 = cons(v_32337, v_32336);
    env = stack[-3];
    stack[-2] = v_32336;
    v_32336 = stack[-1];
    v_32336 = qcdr(v_32336);
    stack[-1] = v_32336;
    goto v_32274;
v_32275:
    v_32336 = nil;
    v_32337 = v_32336;
v_32276:
    v_32336 = stack[-2];
    if (v_32336 == nil) goto v_32321;
    else goto v_32322;
v_32321:
    v_32336 = v_32337;
    goto v_32273;
v_32322:
    goto v_32330;
v_32326:
    v_32336 = stack[-2];
    v_32336 = qcar(v_32336);
    goto v_32327;
v_32328:
    goto v_32329;
v_32330:
    goto v_32326;
v_32327:
    goto v_32328;
v_32329:
    v_32336 = Lappend(nil, v_32336, v_32337);
    env = stack[-3];
    v_32337 = v_32336;
    v_32336 = stack[-2];
    v_32336 = qcdr(v_32336);
    stack[-2] = v_32336;
    goto v_32276;
v_32273:
    return onevalue(v_32336);
}



// Code for sc_create

static LispObject CC_sc_create(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32315, v_32316;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_32268;
// end of prologue
    stack[-2] = nil;
    v_32315 = stack[-1];
    stack[0] = v_32315;
v_32278:
    v_32315 = stack[0];
    v_32315 = sub1(v_32315);
    env = stack[-3];
    v_32315 = Lminusp(nil, v_32315);
    env = stack[-3];
    if (v_32315 == nil) goto v_32283;
    goto v_32277;
v_32283:
    goto v_32293;
v_32289:
    v_32316 = stack[0];
    goto v_32290;
v_32291:
    v_32315 = stack[-2];
    goto v_32292;
v_32293:
    goto v_32289;
v_32290:
    goto v_32291;
v_32292:
    v_32315 = cons(v_32316, v_32315);
    env = stack[-3];
    stack[-2] = v_32315;
    v_32315 = stack[0];
    v_32315 = sub1(v_32315);
    env = stack[-3];
    stack[0] = v_32315;
    goto v_32278;
v_32277:
    goto v_32303;
v_32299:
    goto v_32309;
v_32305:
    v_32316 = stack[-2];
    goto v_32306;
v_32307:
    v_32315 = elt(env, 1); // symbolic
    goto v_32308;
v_32309:
    goto v_32305;
v_32306:
    goto v_32307;
v_32308:
    fn = elt(env, 2); // list2vect!*
    stack[0] = (*qfn2(fn))(fn, v_32316, v_32315);
    env = stack[-3];
    goto v_32300;
v_32301:
    v_32315 = stack[-1];
    v_32315 = sub1(v_32315);
    env = stack[-3];
    v_32315 = Lmkvect(nil, v_32315);
    goto v_32302;
v_32303:
    goto v_32299;
v_32300:
    goto v_32301;
v_32302:
    {
        LispObject v_32320 = stack[0];
        return cons(v_32320, v_32315);
    }
    return onevalue(v_32315);
}



// Code for ofsf_exploitknowl

static LispObject CC_ofsf_exploitknowl(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32635, v_32636, v_32637, v_32638;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(13);
// copy arguments values to proper place
    v_32635 = v_32268;
// end of prologue
    stack[-11] = nil;
    stack[-10] = nil;
    stack[-9] = nil;
    stack[-8] = nil;
    stack[-7] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-1] = v_32635;
v_32287:
    v_32635 = stack[-1];
    if (v_32635 == nil) goto v_32291;
    else goto v_32292;
v_32291:
    goto v_32286;
v_32292:
    v_32635 = stack[-1];
    v_32635 = qcar(v_32635);
    stack[0] = v_32635;
    v_32635 = stack[0];
    v_32635 = qcar(v_32635);
    fn = elt(env, 8); // sfto_varp
    v_32635 = (*qfn1(fn))(fn, v_32635);
    env = stack[-12];
    stack[-4] = v_32635;
    if (v_32635 == nil) goto v_32301;
    v_32635 = stack[0];
    v_32635 = qcdr(v_32635);
    stack[0] = v_32635;
v_32308:
    v_32635 = stack[0];
    if (v_32635 == nil) goto v_32313;
    else goto v_32314;
v_32313:
    goto v_32307;
v_32314:
    v_32635 = stack[0];
    v_32635 = qcar(v_32635);
    v_32635 = qcdr(v_32635);
    v_32636 = v_32635;
    v_32635 = v_32636;
    v_32635 = qcar(v_32635);
    stack[-3] = v_32635;
    v_32635 = v_32636;
    v_32635 = qcdr(v_32635);
    v_32636 = v_32635;
    v_32635 = v_32636;
    fn = elt(env, 9); // negsq
    v_32635 = (*qfn1(fn))(fn, v_32635);
    env = stack[-12];
    v_32636 = v_32635;
    v_32635 = v_32636;
    v_32635 = qcar(v_32635);
    if (v_32635 == nil) goto v_32334;
    else goto v_32333;
v_32334:
    v_32635 = (LispObject)0+TAG_FIXNUM; // 0
v_32333:
    stack[-2] = v_32635;
    goto v_32346;
v_32342:
    v_32637 = stack[-3];
    goto v_32343;
v_32344:
    v_32635 = elt(env, 1); // equal
    goto v_32345;
v_32346:
    goto v_32342;
v_32343:
    goto v_32344;
v_32345:
    if (v_32637 == v_32635) goto v_32340;
    else goto v_32341;
v_32340:
    v_32635 = qvalue(elt(env, 2)); // !*rlsippsubst
    if (v_32635 == nil) goto v_32352;
    goto v_32361;
v_32355:
    v_32637 = stack[-4];
    goto v_32356;
v_32357:
    goto v_32358;
v_32359:
    v_32635 = stack[-11];
    goto v_32360;
v_32361:
    goto v_32355;
v_32356:
    goto v_32357;
v_32358:
    goto v_32359;
v_32360:
    v_32635 = acons(v_32637, v_32636, v_32635);
    env = stack[-12];
    stack[-11] = v_32635;
    goto v_32350;
v_32352:
    goto v_32376;
v_32372:
    v_32636 = stack[-2];
    goto v_32373;
v_32374:
    v_32635 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32375;
v_32376:
    goto v_32372;
v_32373:
    goto v_32374;
v_32375:
    v_32635 = (LispObject)greaterp2(v_32636, v_32635);
    v_32635 = v_32635 ? lisp_true : nil;
    env = stack[-12];
    if (v_32635 == nil) goto v_32370;
    goto v_32384;
v_32380:
    v_32636 = stack[-4];
    goto v_32381;
v_32382:
    v_32635 = stack[-9];
    goto v_32383;
v_32384:
    goto v_32380;
v_32381:
    goto v_32382;
v_32383:
    fn = elt(env, 10); // lto_insertq
    v_32635 = (*qfn2(fn))(fn, v_32636, v_32635);
    env = stack[-12];
    stack[-9] = v_32635;
    goto v_32368;
v_32370:
    goto v_32394;
v_32390:
    v_32636 = stack[-2];
    goto v_32391;
v_32392:
    v_32635 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32393;
v_32394:
    goto v_32390;
v_32391:
    goto v_32392;
v_32393:
    v_32635 = (LispObject)lessp2(v_32636, v_32635);
    v_32635 = v_32635 ? lisp_true : nil;
    env = stack[-12];
    if (v_32635 == nil) goto v_32388;
    goto v_32402;
v_32398:
    v_32636 = stack[-4];
    goto v_32399;
v_32400:
    v_32635 = stack[-8];
    goto v_32401;
v_32402:
    goto v_32398;
v_32399:
    goto v_32400;
v_32401:
    fn = elt(env, 10); // lto_insertq
    v_32635 = (*qfn2(fn))(fn, v_32636, v_32635);
    env = stack[-12];
    stack[-8] = v_32635;
    goto v_32368;
v_32388:
    goto v_32412;
v_32408:
    v_32636 = stack[-2];
    goto v_32409;
v_32410:
    v_32635 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32411;
v_32412:
    goto v_32408;
v_32409:
    goto v_32410;
v_32411:
    v_32635 = Leqn(nil, v_32636, v_32635);
    env = stack[-12];
    if (v_32635 == nil) goto v_32406;
    goto v_32420;
v_32416:
    v_32636 = stack[-4];
    goto v_32417;
v_32418:
    v_32635 = stack[-10];
    goto v_32419;
v_32420:
    goto v_32416;
v_32417:
    goto v_32418;
v_32419:
    fn = elt(env, 10); // lto_insertq
    v_32635 = (*qfn2(fn))(fn, v_32636, v_32635);
    env = stack[-12];
    stack[-10] = v_32635;
    goto v_32368;
v_32406:
v_32368:
    goto v_32350;
v_32350:
    goto v_32339;
v_32341:
    goto v_32429;
v_32425:
    v_32636 = stack[-3];
    goto v_32426;
v_32427:
    v_32635 = elt(env, 3); // greaterp
    goto v_32428;
v_32429:
    goto v_32425;
v_32426:
    goto v_32427;
v_32428:
    if (v_32636 == v_32635) goto v_32423;
    else goto v_32424;
v_32423:
    goto v_32441;
v_32437:
    v_32636 = stack[-2];
    goto v_32438;
v_32439:
    v_32635 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32440;
v_32441:
    goto v_32437;
v_32438:
    goto v_32439;
v_32440:
    v_32635 = (LispObject)geq2(v_32636, v_32635);
    v_32635 = v_32635 ? lisp_true : nil;
    env = stack[-12];
    if (v_32635 == nil) goto v_32435;
    goto v_32449;
v_32445:
    v_32636 = stack[-4];
    goto v_32446;
v_32447:
    v_32635 = stack[-9];
    goto v_32448;
v_32449:
    goto v_32445;
v_32446:
    goto v_32447;
v_32448:
    fn = elt(env, 10); // lto_insertq
    v_32635 = (*qfn2(fn))(fn, v_32636, v_32635);
    env = stack[-12];
    stack[-9] = v_32635;
    goto v_32433;
v_32435:
v_32433:
    goto v_32339;
v_32424:
    goto v_32458;
v_32454:
    v_32636 = stack[-3];
    goto v_32455;
v_32456:
    v_32635 = elt(env, 4); // geq
    goto v_32457;
v_32458:
    goto v_32454;
v_32455:
    goto v_32456;
v_32457:
    if (v_32636 == v_32635) goto v_32452;
    else goto v_32453;
v_32452:
    goto v_32470;
v_32466:
    v_32636 = stack[-2];
    goto v_32467;
v_32468:
    v_32635 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32469;
v_32470:
    goto v_32466;
v_32467:
    goto v_32468;
v_32469:
    v_32635 = (LispObject)greaterp2(v_32636, v_32635);
    v_32635 = v_32635 ? lisp_true : nil;
    env = stack[-12];
    if (v_32635 == nil) goto v_32464;
    goto v_32478;
v_32474:
    v_32636 = stack[-4];
    goto v_32475;
v_32476:
    v_32635 = stack[-9];
    goto v_32477;
v_32478:
    goto v_32474;
v_32475:
    goto v_32476;
v_32477:
    fn = elt(env, 10); // lto_insertq
    v_32635 = (*qfn2(fn))(fn, v_32636, v_32635);
    env = stack[-12];
    stack[-9] = v_32635;
    goto v_32462;
v_32464:
    goto v_32488;
v_32484:
    v_32636 = stack[-2];
    goto v_32485;
v_32486:
    v_32635 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32487;
v_32488:
    goto v_32484;
v_32485:
    goto v_32486;
v_32487:
    v_32635 = Leqn(nil, v_32636, v_32635);
    env = stack[-12];
    if (v_32635 == nil) goto v_32482;
    goto v_32496;
v_32492:
    v_32636 = stack[-4];
    goto v_32493;
v_32494:
    v_32635 = stack[-7];
    goto v_32495;
v_32496:
    goto v_32492;
v_32493:
    goto v_32494;
v_32495:
    fn = elt(env, 10); // lto_insertq
    v_32635 = (*qfn2(fn))(fn, v_32636, v_32635);
    env = stack[-12];
    stack[-7] = v_32635;
    goto v_32462;
v_32482:
v_32462:
    goto v_32339;
v_32453:
    goto v_32505;
v_32501:
    v_32636 = stack[-3];
    goto v_32502;
v_32503:
    v_32635 = elt(env, 5); // lessp
    goto v_32504;
v_32505:
    goto v_32501;
v_32502:
    goto v_32503;
v_32504:
    if (v_32636 == v_32635) goto v_32499;
    else goto v_32500;
v_32499:
    goto v_32517;
v_32513:
    v_32636 = stack[-2];
    goto v_32514;
v_32515:
    v_32635 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32516;
v_32517:
    goto v_32513;
v_32514:
    goto v_32515;
v_32516:
    v_32635 = (LispObject)lesseq2(v_32636, v_32635);
    v_32635 = v_32635 ? lisp_true : nil;
    env = stack[-12];
    if (v_32635 == nil) goto v_32511;
    goto v_32525;
v_32521:
    v_32636 = stack[-4];
    goto v_32522;
v_32523:
    v_32635 = stack[-8];
    goto v_32524;
v_32525:
    goto v_32521;
v_32522:
    goto v_32523;
v_32524:
    fn = elt(env, 10); // lto_insertq
    v_32635 = (*qfn2(fn))(fn, v_32636, v_32635);
    env = stack[-12];
    stack[-8] = v_32635;
    goto v_32509;
v_32511:
v_32509:
    goto v_32339;
v_32500:
    goto v_32534;
v_32530:
    v_32636 = stack[-3];
    goto v_32531;
v_32532:
    v_32635 = elt(env, 6); // leq
    goto v_32533;
v_32534:
    goto v_32530;
v_32531:
    goto v_32532;
v_32533:
    if (v_32636 == v_32635) goto v_32528;
    else goto v_32529;
v_32528:
    goto v_32546;
v_32542:
    v_32636 = stack[-2];
    goto v_32543;
v_32544:
    v_32635 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32545;
v_32546:
    goto v_32542;
v_32543:
    goto v_32544;
v_32545:
    v_32635 = (LispObject)lessp2(v_32636, v_32635);
    v_32635 = v_32635 ? lisp_true : nil;
    env = stack[-12];
    if (v_32635 == nil) goto v_32540;
    goto v_32554;
v_32550:
    v_32636 = stack[-4];
    goto v_32551;
v_32552:
    v_32635 = stack[-8];
    goto v_32553;
v_32554:
    goto v_32550;
v_32551:
    goto v_32552;
v_32553:
    fn = elt(env, 10); // lto_insertq
    v_32635 = (*qfn2(fn))(fn, v_32636, v_32635);
    env = stack[-12];
    stack[-8] = v_32635;
    goto v_32538;
v_32540:
    goto v_32564;
v_32560:
    v_32636 = stack[-2];
    goto v_32561;
v_32562:
    v_32635 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32563;
v_32564:
    goto v_32560;
v_32561:
    goto v_32562;
v_32563:
    v_32635 = Leqn(nil, v_32636, v_32635);
    env = stack[-12];
    if (v_32635 == nil) goto v_32558;
    goto v_32572;
v_32568:
    v_32636 = stack[-4];
    goto v_32569;
v_32570:
    v_32635 = stack[-6];
    goto v_32571;
v_32572:
    goto v_32568;
v_32569:
    goto v_32570;
v_32571:
    fn = elt(env, 10); // lto_insertq
    v_32635 = (*qfn2(fn))(fn, v_32636, v_32635);
    env = stack[-12];
    stack[-6] = v_32635;
    goto v_32538;
v_32558:
v_32538:
    goto v_32339;
v_32529:
    goto v_32581;
v_32577:
    v_32636 = stack[-3];
    goto v_32578;
v_32579:
    v_32635 = elt(env, 7); // neq
    goto v_32580;
v_32581:
    goto v_32577;
v_32578:
    goto v_32579;
v_32580:
    if (v_32636 == v_32635) goto v_32575;
    else goto v_32576;
v_32575:
    goto v_32593;
v_32589:
    v_32636 = stack[-2];
    goto v_32590;
v_32591:
    v_32635 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32592;
v_32593:
    goto v_32589;
v_32590:
    goto v_32591;
v_32592:
    v_32635 = Leqn(nil, v_32636, v_32635);
    env = stack[-12];
    if (v_32635 == nil) goto v_32587;
    goto v_32601;
v_32597:
    v_32636 = stack[-4];
    goto v_32598;
v_32599:
    v_32635 = stack[-5];
    goto v_32600;
v_32601:
    goto v_32597;
v_32598:
    goto v_32599;
v_32600:
    fn = elt(env, 10); // lto_insertq
    v_32635 = (*qfn2(fn))(fn, v_32636, v_32635);
    env = stack[-12];
    stack[-5] = v_32635;
    goto v_32585;
v_32587:
v_32585:
    goto v_32339;
v_32576:
v_32339:
    v_32635 = stack[0];
    v_32635 = qcdr(v_32635);
    stack[0] = v_32635;
    goto v_32308;
v_32307:
    goto v_32299;
v_32301:
v_32299:
    v_32635 = stack[-1];
    v_32635 = qcdr(v_32635);
    stack[-1] = v_32635;
    goto v_32287;
v_32286:
    goto v_32617;
v_32609:
    stack[0] = stack[-11];
    goto v_32610;
v_32611:
    stack[-1] = stack[-10];
    goto v_32612;
v_32613:
    stack[-2] = stack[-9];
    goto v_32614;
v_32615:
    goto v_32630;
v_32622:
    v_32638 = stack[-8];
    goto v_32623;
v_32624:
    v_32637 = stack[-7];
    goto v_32625;
v_32626:
    v_32636 = stack[-6];
    goto v_32627;
v_32628:
    v_32635 = stack[-5];
    goto v_32629;
v_32630:
    goto v_32622;
v_32623:
    goto v_32624;
v_32625:
    goto v_32626;
v_32627:
    goto v_32628;
v_32629:
    v_32635 = list4(v_32638, v_32637, v_32636, v_32635);
    goto v_32616;
v_32617:
    goto v_32609;
v_32610:
    goto v_32611;
v_32612:
    goto v_32613;
v_32614:
    goto v_32615;
v_32616:
    {
        LispObject v_32651 = stack[0];
        LispObject v_32652 = stack[-1];
        LispObject v_32653 = stack[-2];
        return list3star(v_32651, v_32652, v_32653, v_32635);
    }
    return onevalue(v_32635);
}



// Code for uterm

static LispObject CC_uterm(LispObject env,
                         LispObject v_32269, LispObject v_32270)
{
    env = qenv(env);
    LispObject v_32358, v_32359;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_32270,v_32269);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_32269,v_32270);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_32358 = v_32270;
    stack[-1] = v_32269;
// end of prologue
// Binding rhs!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = v_32358; // rhs!*
    v_32358 = qvalue(elt(env, 1)); // rhs!*
    if (v_32358 == nil) goto v_32278;
    else goto v_32279;
v_32278:
    v_32358 = nil;
    goto v_32277;
v_32279:
    goto v_32293;
v_32289:
    v_32359 = stack[-1];
    goto v_32290;
v_32291:
    v_32358 = qvalue(elt(env, 1)); // rhs!*
    v_32358 = qcar(v_32358);
    v_32358 = qcar(v_32358);
    goto v_32292;
v_32293:
    goto v_32289;
v_32290:
    goto v_32291;
v_32292:
    fn = elt(env, 2); // addinds
    v_32358 = (*qfn2(fn))(fn, v_32359, v_32358);
    env = stack[-3];
    stack[0] = v_32358;
    goto v_32303;
v_32299:
    v_32358 = qvalue(elt(env, 1)); // rhs!*
    v_32358 = qcar(v_32358);
    v_32358 = qcdr(v_32358);
    v_32359 = qcar(v_32358);
    goto v_32300;
v_32301:
    v_32358 = stack[-1];
    goto v_32302;
v_32303:
    goto v_32299;
v_32300:
    goto v_32301;
v_32302:
    fn = elt(env, 3); // evaluatecoeffts
    v_32358 = (*qfn2(fn))(fn, v_32359, v_32358);
    env = stack[-3];
    v_32359 = v_32358;
    if (v_32359 == nil) goto v_32311;
    else goto v_32312;
v_32311:
    goto v_32319;
v_32315:
    v_32359 = stack[-1];
    goto v_32316;
v_32317:
    v_32358 = qvalue(elt(env, 1)); // rhs!*
    v_32358 = qcdr(v_32358);
    goto v_32318;
v_32319:
    goto v_32315;
v_32316:
    goto v_32317;
v_32318:
    v_32358 = CC_uterm(elt(env, 0), v_32359, v_32358);
    goto v_32287;
v_32312:
    goto v_32328;
v_32324:
    v_32359 = v_32358;
    goto v_32325;
v_32326:
    v_32358 = qvalue(elt(env, 1)); // rhs!*
    v_32358 = qcar(v_32358);
    v_32358 = qcdr(v_32358);
    v_32358 = qcdr(v_32358);
    goto v_32327;
v_32328:
    goto v_32324;
v_32325:
    goto v_32326;
v_32327:
    v_32358 = cons(v_32359, v_32358);
    env = stack[-3];
    goto v_32339;
v_32335:
    goto v_32346;
v_32342:
    v_32359 = stack[0];
    goto v_32343;
v_32344:
    goto v_32345;
v_32346:
    goto v_32342;
v_32343:
    goto v_32344;
v_32345:
    v_32358 = cons(v_32359, v_32358);
    env = stack[-3];
    stack[0] = ncons(v_32358);
    env = stack[-3];
    goto v_32336;
v_32337:
    goto v_32354;
v_32350:
    v_32359 = stack[-1];
    goto v_32351;
v_32352:
    v_32358 = qvalue(elt(env, 1)); // rhs!*
    v_32358 = qcdr(v_32358);
    goto v_32353;
v_32354:
    goto v_32350;
v_32351:
    goto v_32352;
v_32353:
    v_32358 = CC_uterm(elt(env, 0), v_32359, v_32358);
    env = stack[-3];
    goto v_32338;
v_32339:
    goto v_32335;
v_32336:
    goto v_32337;
v_32338:
    fn = elt(env, 4); // plusdf
    v_32358 = (*qfn2(fn))(fn, stack[0], v_32358);
v_32287:
    goto v_32277;
    v_32358 = nil;
v_32277:
    ;}  // end of a binding scope
    return onevalue(v_32358);
}



// Code for change!+sq!+to!+int

static LispObject CC_changeLsqLtoLint(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32294, v_32295, v_32296;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_32294 = v_32268;
// end of prologue
    fn = elt(env, 2); // prepsq
    v_32294 = (*qfn1(fn))(fn, v_32294);
    env = stack[0];
    fn = elt(env, 3); // simp!*
    v_32294 = (*qfn1(fn))(fn, v_32294);
    env = stack[0];
    v_32296 = v_32294;
    goto v_32284;
v_32280:
    v_32294 = v_32296;
    v_32295 = qcdr(v_32294);
    goto v_32281;
v_32282:
    v_32294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32283;
v_32284:
    goto v_32280;
v_32281:
    goto v_32282;
v_32283:
    if (v_32295 == v_32294) goto v_32278;
    else goto v_32279;
v_32278:
    v_32294 = v_32296;
    v_32294 = qcar(v_32294);
    goto v_32272;
v_32279:
    v_32294 = elt(env, 1); // "no integer in change!+sq!+to!+int"
    fn = elt(env, 4); // rederr
    v_32294 = (*qfn1(fn))(fn, v_32294);
    goto v_32277;
v_32277:
    v_32294 = nil;
v_32272:
    return onevalue(v_32294);
}



// Code for ofsf_factsf

static LispObject CC_ofsf_factsf(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32324, v_32325;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_32268;
// end of prologue
    stack[-1] = nil;
v_32274:
    goto v_32286;
v_32282:
    v_32325 = stack[0];
    goto v_32283;
v_32284:
    v_32324 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32285;
v_32286:
    goto v_32282;
v_32283:
    goto v_32284;
v_32285:
    v_32324 = (LispObject)lesseq2(v_32325, v_32324);
    v_32324 = v_32324 ? lisp_true : nil;
    env = stack[-2];
    if (v_32324 == nil) goto v_32280;
    goto v_32275;
v_32280:
    goto v_32294;
v_32290:
    v_32325 = stack[0];
    goto v_32291;
v_32292:
    v_32324 = stack[-1];
    goto v_32293;
v_32294:
    goto v_32290;
v_32291:
    goto v_32292;
v_32293:
    v_32324 = cons(v_32325, v_32324);
    env = stack[-2];
    stack[-1] = v_32324;
    goto v_32302;
v_32298:
    goto v_32299;
v_32300:
    v_32324 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 1); // negf
    v_32324 = (*qfn1(fn))(fn, v_32324);
    env = stack[-2];
    goto v_32301;
v_32302:
    goto v_32298;
v_32299:
    goto v_32300;
v_32301:
    fn = elt(env, 2); // addf
    v_32324 = (*qfn2(fn))(fn, stack[0], v_32324);
    env = stack[-2];
    stack[0] = v_32324;
    goto v_32274;
v_32275:
    v_32324 = (LispObject)16+TAG_FIXNUM; // 1
    v_32325 = v_32324;
v_32276:
    v_32324 = stack[-1];
    if (v_32324 == nil) goto v_32309;
    else goto v_32310;
v_32309:
    v_32324 = v_32325;
    goto v_32273;
v_32310:
    goto v_32318;
v_32314:
    v_32324 = stack[-1];
    v_32324 = qcar(v_32324);
    goto v_32315;
v_32316:
    goto v_32317;
v_32318:
    goto v_32314;
v_32315:
    goto v_32316;
v_32317:
    fn = elt(env, 3); // multf
    v_32324 = (*qfn2(fn))(fn, v_32324, v_32325);
    env = stack[-2];
    v_32325 = v_32324;
    v_32324 = stack[-1];
    v_32324 = qcdr(v_32324);
    stack[-1] = v_32324;
    goto v_32276;
v_32273:
    return onevalue(v_32324);
}



// Code for operator

static LispObject CC_operator(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32288;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_32288 = v_32268;
// end of prologue
    stack[0] = v_32288;
v_32273:
    v_32288 = stack[0];
    if (v_32288 == nil) goto v_32277;
    else goto v_32278;
v_32277:
    v_32288 = nil;
    goto v_32272;
v_32278:
    v_32288 = stack[0];
    v_32288 = qcar(v_32288);
    fn = elt(env, 1); // mkop
    v_32288 = (*qfn1(fn))(fn, v_32288);
    env = stack[-1];
    v_32288 = stack[0];
    v_32288 = qcdr(v_32288);
    stack[0] = v_32288;
    goto v_32273;
v_32272:
    return onevalue(v_32288);
}



// Code for look_for_rational

static LispObject CC_look_for_rational(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_32427, v_32428, v_32429;
    LispObject fn;
    LispObject v_32270, v_32269, v_32268;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "look_for_rational");
    va_start(aa, nargs);
    v_32268 = va_arg(aa, LispObject);
    v_32269 = va_arg(aa, LispObject);
    v_32270 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_32270,v_32269,v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_32268,v_32269,v_32270);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_32270;
    stack[-1] = v_32269;
    stack[-2] = v_32268;
// end of prologue
    goto v_32281;
v_32277:
    v_32428 = stack[-1];
    goto v_32278;
v_32279:
    v_32427 = elt(env, 1); // look_for_exponential
    goto v_32280;
v_32281:
    goto v_32277;
v_32278:
    goto v_32279;
v_32280:
    v_32427 = get(v_32428, v_32427);
    env = stack[-3];
    if (v_32427 == nil) goto v_32275;
    v_32427 = nil;
    goto v_32273;
v_32275:
    goto v_32295;
v_32291:
    v_32427 = stack[0];
    v_32428 = qcar(v_32427);
    goto v_32292;
v_32293:
    v_32427 = elt(env, 2); // sqrt
    goto v_32294;
v_32295:
    goto v_32291;
v_32292:
    goto v_32293;
v_32294:
    if (v_32428 == v_32427) goto v_32289;
    else goto v_32290;
v_32289:
    goto v_32303;
v_32299:
    v_32427 = stack[0];
    v_32427 = qcdr(v_32427);
    v_32428 = qcar(v_32427);
    goto v_32300;
v_32301:
    v_32427 = stack[-1];
    goto v_32302;
v_32303:
    goto v_32299;
v_32300:
    goto v_32301;
v_32302:
    v_32427 = (equal(v_32428, v_32427) ? lisp_true : nil);
    goto v_32288;
v_32290:
    v_32427 = nil;
    goto v_32288;
    v_32427 = nil;
v_32288:
    if (v_32427 == nil) goto v_32286;
    goto v_32319;
v_32313:
    v_32429 = stack[-2];
    goto v_32314;
v_32315:
    v_32428 = stack[-1];
    goto v_32316;
v_32317:
    v_32427 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_32318;
v_32319:
    goto v_32313;
v_32314:
    goto v_32315;
v_32316:
    goto v_32317;
v_32318:
    {
        fn = elt(env, 5); // look_for_rational1
        return (*qfnn(fn))(fn, 3, v_32429, v_32428, v_32427);
    }
v_32286:
    goto v_32333;
v_32329:
    v_32427 = stack[0];
    v_32428 = qcar(v_32427);
    goto v_32330;
v_32331:
    v_32427 = elt(env, 3); // expt
    goto v_32332;
v_32333:
    goto v_32329;
v_32330:
    goto v_32331;
v_32332:
    if (v_32428 == v_32427) goto v_32327;
    else goto v_32328;
v_32327:
    goto v_32345;
v_32341:
    v_32427 = stack[0];
    v_32427 = qcdr(v_32427);
    v_32428 = qcar(v_32427);
    goto v_32342;
v_32343:
    v_32427 = stack[-1];
    goto v_32344;
v_32345:
    goto v_32341;
v_32342:
    goto v_32343;
v_32344:
    if (equal(v_32428, v_32427)) goto v_32339;
    else goto v_32340;
v_32339:
    v_32427 = stack[0];
    v_32427 = qcdr(v_32427);
    v_32427 = qcdr(v_32427);
    v_32427 = qcar(v_32427);
    fn = elt(env, 6); // listp
    v_32427 = (*qfn1(fn))(fn, v_32427);
    env = stack[-3];
    if (v_32427 == nil) goto v_32352;
    else goto v_32353;
v_32352:
    v_32427 = nil;
    goto v_32351;
v_32353:
    goto v_32370;
v_32366:
    v_32427 = stack[0];
    v_32427 = qcdr(v_32427);
    v_32427 = qcdr(v_32427);
    v_32427 = qcar(v_32427);
    v_32428 = qcar(v_32427);
    goto v_32367;
v_32368:
    v_32427 = elt(env, 4); // quotient
    goto v_32369;
v_32370:
    goto v_32366;
v_32367:
    goto v_32368;
v_32369:
    if (v_32428 == v_32427) goto v_32364;
    else goto v_32365;
v_32364:
    v_32427 = stack[0];
    v_32427 = qcdr(v_32427);
    v_32427 = qcdr(v_32427);
    v_32427 = qcar(v_32427);
    v_32427 = qcdr(v_32427);
    v_32427 = qcar(v_32427);
    if (is_number(v_32427)) goto v_32380;
    v_32427 = nil;
    goto v_32378;
v_32380:
    v_32427 = stack[0];
    v_32427 = qcdr(v_32427);
    v_32427 = qcdr(v_32427);
    v_32427 = qcar(v_32427);
    v_32427 = qcdr(v_32427);
    v_32427 = qcdr(v_32427);
    v_32427 = qcar(v_32427);
    v_32427 = (is_number(v_32427) ? lisp_true : nil);
    goto v_32378;
    v_32427 = nil;
v_32378:
    goto v_32363;
v_32365:
    v_32427 = nil;
    goto v_32363;
    v_32427 = nil;
v_32363:
    goto v_32351;
    v_32427 = nil;
v_32351:
    goto v_32338;
v_32340:
    v_32427 = nil;
    goto v_32338;
    v_32427 = nil;
v_32338:
    goto v_32326;
v_32328:
    v_32427 = nil;
    goto v_32326;
    v_32427 = nil;
v_32326:
    if (v_32427 == nil) goto v_32324;
    goto v_32414;
v_32408:
    v_32429 = stack[-2];
    goto v_32409;
v_32410:
    v_32428 = stack[-1];
    goto v_32411;
v_32412:
    v_32427 = stack[0];
    v_32427 = qcdr(v_32427);
    v_32427 = qcdr(v_32427);
    v_32427 = qcar(v_32427);
    v_32427 = qcdr(v_32427);
    v_32427 = qcdr(v_32427);
    v_32427 = qcar(v_32427);
    goto v_32413;
v_32414:
    goto v_32408;
v_32409:
    goto v_32410;
v_32411:
    goto v_32412;
v_32413:
    {
        fn = elt(env, 5); // look_for_rational1
        return (*qfnn(fn))(fn, 3, v_32429, v_32428, v_32427);
    }
v_32324:
    v_32427 = nil;
    goto v_32273;
    v_32427 = nil;
v_32273:
    return onevalue(v_32427);
}



// Code for vevzero!?1

static LispObject CC_vevzeroW1(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32322, v_32323, v_32324;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_32323 = v_32268;
// end of prologue
v_32267:
    v_32322 = v_32323;
    if (v_32322 == nil) goto v_32272;
    else goto v_32273;
v_32272:
    v_32322 = lisp_true;
    goto v_32271;
v_32273:
    goto v_32286;
v_32282:
    v_32322 = v_32323;
    v_32324 = qcar(v_32322);
    goto v_32283;
v_32284:
    v_32322 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32285;
v_32286:
    goto v_32282;
v_32283:
    goto v_32284;
v_32285:
    if (v_32324 == v_32322) goto v_32280;
    else goto v_32281;
v_32280:
    v_32322 = v_32323;
    v_32322 = qcdr(v_32322);
    if (v_32322 == nil) goto v_32292;
    else goto v_32293;
v_32292:
    v_32322 = lisp_true;
    goto v_32291;
v_32293:
    goto v_32307;
v_32303:
    v_32322 = v_32323;
    v_32322 = qcdr(v_32322);
    v_32324 = qcar(v_32322);
    goto v_32304;
v_32305:
    v_32322 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32306;
v_32307:
    goto v_32303;
v_32304:
    goto v_32305;
v_32306:
    if (v_32324 == v_32322) goto v_32301;
    else goto v_32302;
v_32301:
    v_32322 = v_32323;
    v_32322 = qcdr(v_32322);
    v_32322 = qcdr(v_32322);
    v_32323 = v_32322;
    goto v_32267;
v_32302:
    v_32322 = nil;
    goto v_32300;
    v_32322 = nil;
v_32300:
    goto v_32291;
    v_32322 = nil;
v_32291:
    goto v_32279;
v_32281:
    v_32322 = nil;
    goto v_32279;
    v_32322 = nil;
v_32279:
    goto v_32271;
    v_32322 = nil;
v_32271:
    return onevalue(v_32322);
}



// Code for xpndwedge

static LispObject CC_xpndwedge(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32316, v_32317;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_32268;
// end of prologue
    stack[-1] = nil;
v_32274:
    v_32316 = stack[0];
    v_32316 = qcdr(v_32316);
    if (v_32316 == nil) goto v_32279;
    else goto v_32280;
v_32279:
    goto v_32275;
v_32280:
    goto v_32288;
v_32284:
    v_32316 = stack[0];
    v_32316 = qcar(v_32316);
    fn = elt(env, 1); // partitop
    v_32317 = (*qfn1(fn))(fn, v_32316);
    env = stack[-2];
    goto v_32285;
v_32286:
    v_32316 = stack[-1];
    goto v_32287;
v_32288:
    goto v_32284;
v_32285:
    goto v_32286;
v_32287:
    v_32316 = cons(v_32317, v_32316);
    env = stack[-2];
    stack[-1] = v_32316;
    v_32316 = stack[0];
    v_32316 = qcdr(v_32316);
    stack[0] = v_32316;
    goto v_32274;
v_32275:
    v_32316 = stack[0];
    v_32316 = qcar(v_32316);
    fn = elt(env, 1); // partitop
    v_32316 = (*qfn1(fn))(fn, v_32316);
    env = stack[-2];
    fn = elt(env, 2); // mkunarywedge
    v_32316 = (*qfn1(fn))(fn, v_32316);
    env = stack[-2];
    v_32317 = v_32316;
v_32276:
    v_32316 = stack[-1];
    if (v_32316 == nil) goto v_32301;
    else goto v_32302;
v_32301:
    v_32316 = v_32317;
    goto v_32273;
v_32302:
    goto v_32310;
v_32306:
    v_32316 = stack[-1];
    v_32316 = qcar(v_32316);
    goto v_32307;
v_32308:
    goto v_32309;
v_32310:
    goto v_32306;
v_32307:
    goto v_32308;
v_32309:
    fn = elt(env, 3); // wedgepf2
    v_32316 = (*qfn2(fn))(fn, v_32316, v_32317);
    env = stack[-2];
    v_32317 = v_32316;
    v_32316 = stack[-1];
    v_32316 = qcdr(v_32316);
    stack[-1] = v_32316;
    goto v_32276;
v_32273:
    return onevalue(v_32316);
}



// Code for unshift

static LispObject CC_unshift(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32332, v_32333, v_32334, v_32335;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_32335 = v_32268;
// end of prologue
    v_32332 = qvalue(elt(env, 1)); // !*xo
    v_32334 = v_32332;
    v_32332 = v_32334;
    v_32332 = qcar(v_32332);
    if (!consp(v_32332)) goto v_32279;
    goto v_32290;
v_32286:
    v_32332 = v_32334;
    v_32332 = qcar(v_32332);
    v_32332 = qcdr(v_32332);
    v_32333 = qcar(v_32332);
    goto v_32287;
v_32288:
    v_32332 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32289;
v_32290:
    goto v_32286;
v_32287:
    goto v_32288;
v_32289:
    if (v_32333 == v_32332) goto v_32284;
    else goto v_32285;
v_32284:
    goto v_32300;
v_32296:
    v_32332 = v_32334;
    v_32332 = qcdr(v_32332);
    v_32332 = qcdr(v_32332);
    v_32333 = qcar(v_32332);
    goto v_32297;
v_32298:
    v_32332 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32299;
v_32300:
    goto v_32296;
v_32297:
    goto v_32298;
v_32299:
    v_32332 = (v_32333 == v_32332 ? lisp_true : nil);
    goto v_32283;
v_32285:
    v_32332 = nil;
    goto v_32283;
    v_32332 = nil;
v_32283:
    goto v_32277;
v_32279:
    goto v_32316;
v_32312:
    v_32333 = v_32334;
    goto v_32313;
v_32314:
    v_32332 = elt(env, 2); // (0.0 . 0.0)
    goto v_32315;
v_32316:
    goto v_32312;
v_32313:
    goto v_32314;
v_32315:
    v_32332 = (equal(v_32333, v_32332) ? lisp_true : nil);
    goto v_32277;
    v_32332 = nil;
v_32277:
    if (v_32332 == nil) goto v_32273;
    v_32332 = v_32335;
    goto v_32271;
v_32273:
    goto v_32329;
v_32325:
    v_32333 = v_32335;
    goto v_32326;
v_32327:
    v_32332 = qvalue(elt(env, 1)); // !*xo
    goto v_32328;
v_32329:
    goto v_32325;
v_32326:
    goto v_32327;
v_32328:
    fn = elt(env, 3); // gfplus
    v_32332 = (*qfn2(fn))(fn, v_32333, v_32332);
    env = stack[0];
    {
        fn = elt(env, 4); // gfadjust
        return (*qfn1(fn))(fn, v_32332);
    }
    v_32332 = nil;
v_32271:
    return onevalue(v_32332);
}



// Code for r2speclist

static LispObject CC_r2speclist(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32330, v_32331, v_32332;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_32331 = v_32268;
// end of prologue
    goto v_32279;
v_32275:
    v_32332 = v_32331;
    goto v_32276;
v_32277:
    v_32330 = elt(env, 1); // plus
    goto v_32278;
v_32279:
    goto v_32275;
v_32276:
    goto v_32277;
v_32278:
    if (!consp(v_32332)) goto v_32273;
    v_32332 = qcar(v_32332);
    if (v_32332 == v_32330) goto v_32272;
    else goto v_32273;
v_32272:
    v_32330 = v_32331;
    v_32330 = qcdr(v_32330);
    goto v_32271;
v_32273:
    v_32330 = v_32331;
    v_32330 = ncons(v_32330);
    env = stack[-4];
    goto v_32271;
    v_32330 = nil;
v_32271:
    v_32331 = v_32330;
    v_32330 = v_32331;
    stack[-3] = v_32330;
    v_32330 = stack[-3];
    if (v_32330 == nil) goto v_32297;
    else goto v_32298;
v_32297:
    v_32330 = nil;
    goto v_32292;
v_32298:
    v_32330 = stack[-3];
    v_32330 = qcar(v_32330);
    fn = elt(env, 2); // r2speclist1
    v_32330 = (*qfn1(fn))(fn, v_32330);
    env = stack[-4];
    v_32330 = ncons(v_32330);
    env = stack[-4];
    stack[-1] = v_32330;
    stack[-2] = v_32330;
v_32293:
    v_32330 = stack[-3];
    v_32330 = qcdr(v_32330);
    stack[-3] = v_32330;
    v_32330 = stack[-3];
    if (v_32330 == nil) goto v_32311;
    else goto v_32312;
v_32311:
    v_32330 = stack[-2];
    goto v_32292;
v_32312:
    goto v_32320;
v_32316:
    stack[0] = stack[-1];
    goto v_32317;
v_32318:
    v_32330 = stack[-3];
    v_32330 = qcar(v_32330);
    fn = elt(env, 2); // r2speclist1
    v_32330 = (*qfn1(fn))(fn, v_32330);
    env = stack[-4];
    v_32330 = ncons(v_32330);
    env = stack[-4];
    goto v_32319;
v_32320:
    goto v_32316;
v_32317:
    goto v_32318;
v_32319:
    v_32330 = Lrplacd(nil, stack[0], v_32330);
    env = stack[-4];
    v_32330 = stack[-1];
    v_32330 = qcdr(v_32330);
    stack[-1] = v_32330;
    goto v_32293;
v_32292:
    return onevalue(v_32330);
}



// Code for noncom1

static LispObject CC_noncom1(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32280, v_32281;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_32281 = v_32268;
// end of prologue
    v_32280 = lisp_true;
    qvalue(elt(env, 1)) = v_32280; // !*ncmp
    goto v_32276;
v_32272:
    v_32280 = v_32281;
    v_32280 = ncons(v_32280);
    env = stack[0];
    goto v_32273;
v_32274:
    v_32281 = elt(env, 2); // noncom
    goto v_32275;
v_32276:
    goto v_32272;
v_32273:
    goto v_32274;
v_32275:
        return Lflag(nil, v_32280, v_32281);
}



// Code for rationalizef

static LispObject CC_rationalizef(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32493, v_32494;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_32268;
// end of prologue
    v_32493 = stack[-2];
    fn = elt(env, 8); // kernels
    v_32493 = (*qfn1(fn))(fn, v_32493);
    env = stack[-4];
    stack[0] = v_32493;
    stack[-3] = v_32493;
v_32275:
    v_32493 = stack[-3];
    if (v_32493 == nil) goto v_32280;
    else goto v_32281;
v_32280:
    v_32493 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32274;
v_32281:
    v_32493 = stack[-3];
    v_32493 = qcar(v_32493);
    stack[-1] = v_32493;
    goto v_32299;
v_32295:
    v_32494 = stack[-1];
    goto v_32296;
v_32297:
    v_32493 = elt(env, 1); // expt
    goto v_32298;
v_32299:
    goto v_32295;
v_32296:
    goto v_32297;
v_32298:
    if (!consp(v_32494)) goto v_32293;
    v_32494 = qcar(v_32494);
    if (v_32494 == v_32493) goto v_32292;
    else goto v_32293;
v_32292:
    goto v_32311;
v_32307:
    v_32493 = stack[-1];
    v_32493 = qcdr(v_32493);
    v_32493 = qcdr(v_32493);
    v_32494 = qcar(v_32493);
    goto v_32308;
v_32309:
    v_32493 = elt(env, 2); // quotient
    goto v_32310;
v_32311:
    goto v_32307;
v_32308:
    goto v_32309;
v_32310:
    if (!consp(v_32494)) goto v_32305;
    v_32494 = qcar(v_32494);
    if (v_32494 == v_32493) goto v_32304;
    else goto v_32305;
v_32304:
    goto v_32322;
v_32318:
    v_32494 = stack[0];
    goto v_32319;
v_32320:
    v_32493 = stack[-1];
    v_32493 = qcdr(v_32493);
    goto v_32321;
v_32322:
    goto v_32318;
v_32319:
    goto v_32320;
v_32321:
    fn = elt(env, 9); // lowertowerp
    v_32493 = (*qfn2(fn))(fn, v_32494, v_32493);
    env = stack[-4];
    goto v_32303;
v_32305:
    v_32493 = nil;
    goto v_32303;
    v_32493 = nil;
v_32303:
    goto v_32291;
v_32293:
    v_32493 = nil;
    goto v_32291;
    v_32493 = nil;
v_32291:
    if (v_32493 == nil) goto v_32289;
    goto v_32287;
v_32289:
    goto v_32343;
v_32339:
    v_32494 = stack[-1];
    goto v_32340;
v_32341:
    v_32493 = elt(env, 3); // i
    goto v_32342;
v_32343:
    goto v_32339;
v_32340:
    goto v_32341;
v_32342:
    if (v_32494 == v_32493) goto v_32337;
    else goto v_32338;
v_32337:
    v_32493 = lisp_true;
    goto v_32336;
v_32338:
    goto v_32362;
v_32358:
    v_32494 = stack[-1];
    goto v_32359;
v_32360:
    v_32493 = elt(env, 1); // expt
    goto v_32361;
v_32362:
    goto v_32358;
v_32359:
    goto v_32360;
v_32361:
    if (!consp(v_32494)) goto v_32356;
    v_32494 = qcar(v_32494);
    if (v_32494 == v_32493) goto v_32355;
    else goto v_32356;
v_32355:
    goto v_32369;
v_32365:
    v_32493 = stack[-1];
    v_32493 = qcdr(v_32493);
    v_32493 = qcdr(v_32493);
    v_32494 = qcar(v_32493);
    goto v_32366;
v_32367:
    v_32493 = elt(env, 4); // (quotient 1 2)
    goto v_32368;
v_32369:
    goto v_32365;
v_32366:
    goto v_32367;
v_32368:
    v_32493 = (equal(v_32494, v_32493) ? lisp_true : nil);
    goto v_32354;
v_32356:
    v_32493 = nil;
    goto v_32354;
    v_32493 = nil;
v_32354:
    if (v_32493 == nil) goto v_32352;
    v_32493 = lisp_true;
    goto v_32350;
v_32352:
    goto v_32387;
v_32383:
    v_32494 = stack[-1];
    goto v_32384;
v_32385:
    v_32493 = elt(env, 5); // sqrt
    goto v_32386;
v_32387:
    goto v_32383;
v_32384:
    goto v_32385;
v_32386:
    v_32493 = Leqcar(nil, v_32494, v_32493);
    env = stack[-4];
    goto v_32350;
    v_32493 = nil;
v_32350:
    goto v_32336;
    v_32493 = nil;
v_32336:
    if (v_32493 == nil) goto v_32334;
    goto v_32395;
v_32391:
    goto v_32401;
v_32397:
    v_32494 = stack[-2];
    goto v_32398;
v_32399:
    v_32493 = stack[-1];
    goto v_32400;
v_32401:
    goto v_32397;
v_32398:
    goto v_32399;
v_32400:
    fn = elt(env, 10); // mkmain
    v_32494 = (*qfn2(fn))(fn, v_32494, v_32493);
    env = stack[-4];
    goto v_32392;
v_32393:
    v_32493 = stack[-1];
    goto v_32394;
v_32395:
    goto v_32391;
v_32392:
    goto v_32393;
v_32394:
    {
        fn = elt(env, 11); // conjquadratic
        return (*qfn2(fn))(fn, v_32494, v_32493);
    }
v_32334:
    goto v_32416;
v_32412:
    v_32494 = stack[-1];
    goto v_32413;
v_32414:
    v_32493 = elt(env, 1); // expt
    goto v_32415;
v_32416:
    goto v_32412;
v_32413:
    goto v_32414;
v_32415:
    if (!consp(v_32494)) goto v_32410;
    v_32494 = qcar(v_32494);
    if (v_32494 == v_32493) goto v_32409;
    else goto v_32410;
v_32409:
    goto v_32423;
v_32419:
    v_32493 = stack[-1];
    v_32493 = qcdr(v_32493);
    v_32493 = qcdr(v_32493);
    v_32494 = qcar(v_32493);
    goto v_32420;
v_32421:
    v_32493 = elt(env, 6); // (quotient 1 3)
    goto v_32422;
v_32423:
    goto v_32419;
v_32420:
    goto v_32421;
v_32422:
    v_32493 = (equal(v_32494, v_32493) ? lisp_true : nil);
    goto v_32408;
v_32410:
    v_32493 = nil;
    goto v_32408;
    v_32493 = nil;
v_32408:
    if (v_32493 == nil) goto v_32406;
    goto v_32438;
v_32434:
    goto v_32444;
v_32440:
    v_32494 = stack[-2];
    goto v_32441;
v_32442:
    v_32493 = stack[-1];
    goto v_32443;
v_32444:
    goto v_32440;
v_32441:
    goto v_32442;
v_32443:
    fn = elt(env, 10); // mkmain
    v_32494 = (*qfn2(fn))(fn, v_32494, v_32493);
    env = stack[-4];
    goto v_32435;
v_32436:
    v_32493 = stack[-1];
    goto v_32437;
v_32438:
    goto v_32434;
v_32435:
    goto v_32436;
v_32437:
    {
        fn = elt(env, 12); // conjcubic
        return (*qfn2(fn))(fn, v_32494, v_32493);
    }
v_32406:
    goto v_32459;
v_32455:
    v_32494 = stack[-1];
    goto v_32456;
v_32457:
    v_32493 = elt(env, 1); // expt
    goto v_32458;
v_32459:
    goto v_32455;
v_32456:
    goto v_32457;
v_32458:
    if (!consp(v_32494)) goto v_32453;
    v_32494 = qcar(v_32494);
    if (v_32494 == v_32493) goto v_32452;
    else goto v_32453;
v_32452:
    goto v_32466;
v_32462:
    v_32493 = stack[-1];
    v_32493 = qcdr(v_32493);
    v_32493 = qcdr(v_32493);
    v_32494 = qcar(v_32493);
    goto v_32463;
v_32464:
    v_32493 = elt(env, 7); // (quotient 1 4)
    goto v_32465;
v_32466:
    goto v_32462;
v_32463:
    goto v_32464;
v_32465:
    v_32493 = (equal(v_32494, v_32493) ? lisp_true : nil);
    goto v_32451;
v_32453:
    v_32493 = nil;
    goto v_32451;
    v_32493 = nil;
v_32451:
    if (v_32493 == nil) goto v_32449;
    goto v_32481;
v_32477:
    goto v_32487;
v_32483:
    v_32494 = stack[-2];
    goto v_32484;
v_32485:
    v_32493 = stack[-1];
    goto v_32486;
v_32487:
    goto v_32483;
v_32484:
    goto v_32485;
v_32486:
    fn = elt(env, 10); // mkmain
    v_32494 = (*qfn2(fn))(fn, v_32494, v_32493);
    env = stack[-4];
    goto v_32478;
v_32479:
    v_32493 = stack[-1];
    goto v_32480;
v_32481:
    goto v_32477;
v_32478:
    goto v_32479;
v_32480:
    {
        fn = elt(env, 13); // conjquartic
        return (*qfn2(fn))(fn, v_32494, v_32493);
    }
v_32449:
v_32287:
    v_32493 = stack[-3];
    v_32493 = qcdr(v_32493);
    stack[-3] = v_32493;
    goto v_32275;
v_32274:
    return onevalue(v_32493);
}



// Code for lowestdeg

static LispObject CC_lowestdeg(LispObject env,
                         LispObject v_32268, LispObject v_32269)
{
    env = qenv(env);
    LispObject v_32363, v_32364;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_32269,v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_32268,v_32269);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_32269;
    v_32363 = v_32268;
// end of prologue
    fn = elt(env, 3); // simp!*
    v_32363 = (*qfn1(fn))(fn, v_32363);
    env = stack[-4];
    stack[-1] = v_32363;
    v_32363 = stack[-1];
    if (!consp(v_32363)) goto v_32285;
    else goto v_32286;
v_32285:
    v_32363 = lisp_true;
    goto v_32284;
v_32286:
    v_32363 = stack[-1];
    v_32363 = qcar(v_32363);
    v_32363 = (consp(v_32363) ? nil : lisp_true);
    goto v_32284;
    v_32363 = nil;
v_32284:
    if (v_32363 == nil) goto v_32282;
    v_32363 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32276;
v_32282:
    v_32363 = stack[-1];
    fn = elt(env, 4); // !*q2f
    v_32363 = (*qfn1(fn))(fn, v_32363);
    env = stack[-4];
    stack[-1] = v_32363;
    v_32363 = stack[-1];
    fn = elt(env, 5); // erase_pol_cst
    v_32363 = (*qfn1(fn))(fn, v_32363);
    env = stack[-4];
    stack[0] = v_32363;
    goto v_32307;
v_32303:
    v_32364 = stack[0];
    goto v_32304;
v_32305:
    v_32363 = stack[-1];
    goto v_32306;
v_32307:
    goto v_32303;
v_32304:
    goto v_32305;
v_32306:
    if (equal(v_32364, v_32363)) goto v_32302;
    v_32363 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32276;
v_32302:
    v_32363 = stack[-2];
    fn = elt(env, 6); // !*a2k
    v_32363 = (*qfn1(fn))(fn, v_32363);
    env = stack[-4];
    stack[0] = v_32363;
    v_32363 = stack[-2];
    v_32363 = ncons(v_32363);
    env = stack[-4];
    fn = elt(env, 7); // setkorder
    v_32363 = (*qfn1(fn))(fn, v_32363);
    env = stack[-4];
    stack[-3] = v_32363;
    v_32363 = stack[-1];
    fn = elt(env, 8); // reorder
    v_32363 = (*qfn1(fn))(fn, v_32363);
    env = stack[-4];
    stack[-2] = v_32363;
    v_32363 = stack[-3];
    fn = elt(env, 7); // setkorder
    v_32363 = (*qfn1(fn))(fn, v_32363);
    env = stack[-4];
    v_32363 = stack[-2];
    v_32363 = Lreverse(nil, v_32363);
    env = stack[-4];
    stack[-2] = v_32363;
    v_32363 = stack[-2];
    v_32363 = qcar(v_32363);
    v_32363 = qcar(v_32363);
    v_32363 = qcar(v_32363);
    stack[-1] = v_32363;
    v_32363 = stack[-1];
    if (!consp(v_32363)) goto v_32329;
    goto v_32339;
v_32335:
    v_32363 = stack[-1];
    v_32364 = qcar(v_32363);
    goto v_32336;
v_32337:
    v_32363 = elt(env, 1); // expt
    goto v_32338;
v_32339:
    goto v_32335;
v_32336:
    goto v_32337;
v_32338:
    if (v_32364 == v_32363) goto v_32333;
    else goto v_32334;
v_32333:
    v_32363 = elt(env, 2); // "exponents must be integers"
    fn = elt(env, 9); // rederr
    v_32363 = (*qfn1(fn))(fn, v_32363);
    goto v_32332;
v_32334:
v_32332:
    goto v_32327;
v_32329:
v_32327:
    goto v_32353;
v_32349:
    v_32364 = stack[-1];
    goto v_32350;
v_32351:
    v_32363 = stack[0];
    goto v_32352;
v_32353:
    goto v_32349;
v_32350:
    goto v_32351;
v_32352:
    if (equal(v_32364, v_32363)) goto v_32348;
    v_32363 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32276;
v_32348:
    v_32363 = stack[-2];
    v_32363 = qcar(v_32363);
    v_32363 = qcar(v_32363);
    v_32363 = qcdr(v_32363);
    goto v_32276;
    v_32363 = nil;
v_32276:
    return onevalue(v_32363);
}



// Code for simprd

static LispObject CC_simprd(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32282, v_32283;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_32283 = v_32268;
// end of prologue
    v_32282 = v_32283;
    if (!consp(v_32282)) goto v_32272;
    else goto v_32273;
v_32272:
    v_32282 = nil;
    goto v_32271;
v_32273:
    v_32282 = elt(env, 1); // !:rd!:
// Binding dmode!*
// FLUIDBIND: reloadenv=1 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 2, 0);
    qvalue(elt(env, 2)) = v_32282; // dmode!*
    v_32282 = v_32283;
    fn = elt(env, 3); // simplist
    v_32282 = (*qfn1(fn))(fn, v_32282);
    ;}  // end of a binding scope
    goto v_32271;
    v_32282 = nil;
v_32271:
    return onevalue(v_32282);
}



// Code for add!-to!-sorted!-tree

static LispObject CC_addKtoKsortedKtree(LispObject env,
                         LispObject v_32268, LispObject v_32269)
{
    env = qenv(env);
    LispObject v_32377, v_32378, v_32379;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_32269,v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_32268,v_32269);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_32269;
    stack[-1] = v_32268;
// end of prologue
    stack[-2] = nil;
v_32274:
    v_32377 = stack[0];
    if (v_32377 == nil) goto v_32277;
    else goto v_32278;
v_32277:
    goto v_32285;
v_32281:
    stack[0] = stack[-2];
    goto v_32282;
v_32283:
    goto v_32294;
v_32288:
    v_32379 = nil;
    goto v_32289;
v_32290:
    v_32378 = stack[-1];
    goto v_32291;
v_32292:
    v_32377 = nil;
    goto v_32293;
v_32294:
    goto v_32288;
v_32289:
    goto v_32290;
v_32291:
    goto v_32292;
v_32293:
    v_32377 = list2star(v_32379, v_32378, v_32377);
    env = stack[-3];
    goto v_32284;
v_32285:
    goto v_32281;
v_32282:
    goto v_32283;
v_32284:
    {
        LispObject v_32383 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_32383, v_32377);
    }
v_32278:
    goto v_32304;
v_32300:
    v_32378 = stack[-1];
    goto v_32301;
v_32302:
    v_32377 = stack[0];
    v_32377 = qcdr(v_32377);
    v_32377 = qcar(v_32377);
    goto v_32303;
v_32304:
    goto v_32300;
v_32301:
    goto v_32302;
v_32303:
    if (equal(v_32378, v_32377)) goto v_32298;
    else goto v_32299;
v_32298:
    goto v_32314;
v_32310:
    v_32378 = stack[-2];
    goto v_32311;
v_32312:
    v_32377 = stack[0];
    goto v_32313;
v_32314:
    goto v_32310;
v_32311:
    goto v_32312;
v_32313:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_32378, v_32377);
    }
v_32299:
    goto v_32324;
v_32320:
    v_32378 = stack[-1];
    goto v_32321;
v_32322:
    v_32377 = stack[0];
    v_32377 = qcdr(v_32377);
    v_32377 = qcar(v_32377);
    goto v_32323;
v_32324:
    goto v_32320;
v_32321:
    goto v_32322;
v_32323:
    v_32377 = Lorderp(nil, v_32378, v_32377);
    env = stack[-3];
    if (v_32377 == nil) goto v_32318;
    goto v_32334;
v_32330:
    goto v_32331;
v_32332:
    goto v_32341;
v_32337:
    goto v_32347;
v_32343:
    v_32378 = stack[-1];
    goto v_32344;
v_32345:
    v_32377 = stack[0];
    v_32377 = qcar(v_32377);
    goto v_32346;
v_32347:
    goto v_32343;
v_32344:
    goto v_32345;
v_32346:
    v_32378 = CC_addKtoKsortedKtree(elt(env, 0), v_32378, v_32377);
    env = stack[-3];
    goto v_32338;
v_32339:
    v_32377 = stack[0];
    v_32377 = qcdr(v_32377);
    goto v_32340;
v_32341:
    goto v_32337;
v_32338:
    goto v_32339;
v_32340:
    v_32377 = cons(v_32378, v_32377);
    env = stack[-3];
    goto v_32333;
v_32334:
    goto v_32330;
v_32331:
    goto v_32332;
v_32333:
    {
        LispObject v_32384 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_32384, v_32377);
    }
v_32318:
    goto v_32360;
v_32356:
    v_32377 = stack[0];
    v_32378 = qcar(v_32377);
    goto v_32357;
v_32358:
    v_32377 = stack[-2];
    goto v_32359;
v_32360:
    goto v_32356;
v_32357:
    goto v_32358;
v_32359:
    v_32377 = cons(v_32378, v_32377);
    env = stack[-3];
    stack[-2] = v_32377;
    goto v_32369;
v_32365:
    v_32377 = stack[0];
    v_32377 = qcdr(v_32377);
    v_32378 = qcar(v_32377);
    goto v_32366;
v_32367:
    v_32377 = stack[-2];
    goto v_32368;
v_32369:
    goto v_32365;
v_32366:
    goto v_32367;
v_32368:
    v_32377 = cons(v_32378, v_32377);
    env = stack[-3];
    stack[-2] = v_32377;
    v_32377 = stack[0];
    v_32377 = qcdr(v_32377);
    v_32377 = qcdr(v_32377);
    stack[0] = v_32377;
    goto v_32274;
    v_32377 = nil;
    return onevalue(v_32377);
}



// Code for get!*nr!*real!*irred!*reps

static LispObject CC_getHnrHrealHirredHreps(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32280, v_32281;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_32280 = v_32268;
// end of prologue
    goto v_32277;
v_32273:
    goto v_32274;
v_32275:
    v_32281 = elt(env, 1); // realrepnumber
    goto v_32276;
v_32277:
    goto v_32273;
v_32274:
    goto v_32275;
v_32276:
    return get(v_32280, v_32281);
    return onevalue(v_32280);
}



// Code for pasf_ceeq

static LispObject CC_pasf_ceeq(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32381, v_32382;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_32268;
// end of prologue
    goto v_32289;
v_32285:
    v_32382 = stack[0];
    goto v_32286;
v_32287:
    v_32381 = elt(env, 1); // true
    goto v_32288;
v_32289:
    goto v_32285;
v_32286:
    goto v_32287;
v_32288:
    if (v_32382 == v_32381) goto v_32283;
    else goto v_32284;
v_32283:
    v_32381 = lisp_true;
    goto v_32282;
v_32284:
    goto v_32299;
v_32295:
    v_32382 = stack[0];
    goto v_32296;
v_32297:
    v_32381 = elt(env, 2); // false
    goto v_32298;
v_32299:
    goto v_32295;
v_32296:
    goto v_32297;
v_32298:
    v_32381 = (v_32382 == v_32381 ? lisp_true : nil);
    goto v_32282;
    v_32381 = nil;
v_32282:
    if (v_32381 == nil) goto v_32280;
    v_32381 = lisp_true;
    goto v_32278;
v_32280:
    goto v_32310;
v_32306:
    goto v_32323;
v_32319:
    v_32382 = stack[0];
    goto v_32320;
v_32321:
    v_32381 = elt(env, 1); // true
    goto v_32322;
v_32323:
    goto v_32319;
v_32320:
    goto v_32321;
v_32322:
    if (v_32382 == v_32381) goto v_32317;
    else goto v_32318;
v_32317:
    v_32381 = lisp_true;
    goto v_32316;
v_32318:
    goto v_32333;
v_32329:
    v_32382 = stack[0];
    goto v_32330;
v_32331:
    v_32381 = elt(env, 2); // false
    goto v_32332;
v_32333:
    goto v_32329;
v_32330:
    goto v_32331;
v_32332:
    v_32381 = (v_32382 == v_32381 ? lisp_true : nil);
    goto v_32316;
    v_32381 = nil;
v_32316:
    if (v_32381 == nil) goto v_32314;
    v_32381 = stack[0];
    v_32382 = v_32381;
    goto v_32312;
v_32314:
    v_32381 = stack[0];
    v_32381 = qcar(v_32381);
    v_32381 = Lconsp(nil, v_32381);
    env = stack[-2];
    if (v_32381 == nil) goto v_32339;
    v_32381 = stack[0];
    v_32381 = qcar(v_32381);
    v_32381 = qcar(v_32381);
    v_32382 = v_32381;
    goto v_32312;
v_32339:
    v_32381 = stack[0];
    v_32381 = qcar(v_32381);
    v_32382 = v_32381;
    goto v_32312;
    v_32382 = nil;
v_32312:
    goto v_32307;
v_32308:
    v_32381 = elt(env, 3); // (equal neq)
    goto v_32309;
v_32310:
    goto v_32306;
v_32307:
    goto v_32308;
v_32309:
    v_32381 = Lmemq(nil, v_32382, v_32381);
    v_32381 = (v_32381 == nil ? lisp_true : nil);
    goto v_32278;
    v_32381 = nil;
v_32278:
    if (v_32381 == nil) goto v_32276;
    v_32381 = stack[0];
    goto v_32272;
v_32276:
    v_32381 = stack[0];
    v_32381 = qcdr(v_32381);
    v_32381 = qcar(v_32381);
    fn = elt(env, 4); // sfto_dcontentf
    v_32381 = (*qfn1(fn))(fn, v_32381);
    env = stack[-2];
    v_32382 = v_32381;
    goto v_32365;
v_32359:
    v_32381 = stack[0];
    stack[-1] = qcar(v_32381);
    goto v_32360;
v_32361:
    goto v_32373;
v_32369:
    v_32381 = stack[0];
    v_32381 = qcdr(v_32381);
    stack[0] = qcar(v_32381);
    goto v_32370;
v_32371:
    v_32381 = v_32382;
    fn = elt(env, 5); // simp
    v_32381 = (*qfn1(fn))(fn, v_32381);
    env = stack[-2];
    v_32381 = qcar(v_32381);
    goto v_32372;
v_32373:
    goto v_32369;
v_32370:
    goto v_32371;
v_32372:
    fn = elt(env, 6); // quotfx
    v_32382 = (*qfn2(fn))(fn, stack[0], v_32381);
    goto v_32362;
v_32363:
    v_32381 = nil;
    goto v_32364;
v_32365:
    goto v_32359;
v_32360:
    goto v_32361;
v_32362:
    goto v_32363;
v_32364:
    {
        LispObject v_32385 = stack[-1];
        return list3(v_32385, v_32382, v_32381);
    }
v_32272:
    return onevalue(v_32381);
}



// Code for matrix_input_test

static LispObject CC_matrix_input_test(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32299, v_32300, v_32301;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_32300 = v_32268;
// end of prologue
    goto v_32281;
v_32277:
    v_32301 = v_32300;
    goto v_32278;
v_32279:
    v_32299 = elt(env, 1); // mat
    goto v_32280;
v_32281:
    goto v_32277;
v_32278:
    goto v_32279;
v_32280:
    if (!consp(v_32301)) goto v_32274;
    v_32301 = qcar(v_32301);
    if (v_32301 == v_32299) goto v_32275;
v_32274:
    goto v_32292;
v_32286:
    v_32301 = elt(env, 2); // "ERROR: `"
    goto v_32287;
v_32288:
    goto v_32289;
v_32290:
    v_32299 = elt(env, 3); // "' is non matrix input."
    goto v_32291;
v_32292:
    goto v_32286;
v_32287:
    goto v_32288;
v_32289:
    goto v_32290;
v_32291:
    v_32299 = list3(v_32301, v_32300, v_32299);
    env = stack[0];
    fn = elt(env, 4); // rederr
    v_32299 = (*qfn1(fn))(fn, v_32299);
    goto v_32273;
v_32275:
    v_32299 = v_32300;
    goto v_32271;
v_32273:
    v_32299 = nil;
v_32271:
    return onevalue(v_32299);
}



// Code for dip!-nc!-ev!-prod

static LispObject CC_dipKncKevKprod(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_32301, v_32302, v_32303, v_32304;
    LispObject fn;
    LispObject v_32271, v_32270, v_32269, v_32268;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "dip-nc-ev-prod");
    va_start(aa, nargs);
    v_32268 = va_arg(aa, LispObject);
    v_32269 = va_arg(aa, LispObject);
    v_32270 = va_arg(aa, LispObject);
    v_32271 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_32271,v_32270,v_32269,v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_32268,v_32269,v_32270,v_32271);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_32301 = v_32271;
    v_32302 = v_32270;
    v_32303 = v_32269;
    v_32304 = v_32268;
// end of prologue
    goto v_32280;
v_32274:
    stack[-2] = v_32303;
    goto v_32275;
v_32276:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32277;
v_32278:
    goto v_32290;
v_32284:
    stack[0] = v_32301;
    goto v_32285;
v_32286:
    goto v_32297;
v_32293:
    v_32301 = v_32304;
    goto v_32294;
v_32295:
    goto v_32296;
v_32297:
    goto v_32293;
v_32294:
    goto v_32295;
v_32296:
    fn = elt(env, 1); // bcprod
    v_32302 = (*qfn2(fn))(fn, v_32301, v_32302);
    env = stack[-3];
    goto v_32287;
v_32288:
    v_32301 = nil;
    goto v_32289;
v_32290:
    goto v_32284;
v_32285:
    goto v_32286;
v_32287:
    goto v_32288;
v_32289:
    v_32301 = list2star(stack[0], v_32302, v_32301);
    env = stack[-3];
    goto v_32279;
v_32280:
    goto v_32274;
v_32275:
    goto v_32276;
v_32277:
    goto v_32278;
v_32279:
    {
        LispObject v_32308 = stack[-2];
        LispObject v_32309 = stack[-1];
        fn = elt(env, 2); // dip!-nc!-ev!-prod1
        return (*qfnn(fn))(fn, 3, v_32308, v_32309, v_32301);
    }
}



// Code for row_dim

static LispObject CC_row_dim(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32292;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_32268;
// end of prologue
    v_32292 = qvalue(elt(env, 1)); // !*fast_la
    if (v_32292 == nil) goto v_32278;
    else goto v_32279;
v_32278:
    v_32292 = stack[0];
    fn = elt(env, 3); // matrixp
    v_32292 = (*qfn1(fn))(fn, v_32292);
    env = stack[-1];
    v_32292 = (v_32292 == nil ? lisp_true : nil);
    goto v_32277;
v_32279:
    v_32292 = nil;
    goto v_32277;
    v_32292 = nil;
v_32277:
    if (v_32292 == nil) goto v_32275;
    v_32292 = elt(env, 2); // "Error in row_dim: input should be a matrix."
    fn = elt(env, 4); // rederr
    v_32292 = (*qfn1(fn))(fn, v_32292);
    env = stack[-1];
    goto v_32273;
v_32275:
v_32273:
    v_32292 = stack[0];
    fn = elt(env, 5); // size_of_matrix
    v_32292 = (*qfn1(fn))(fn, v_32292);
    v_32292 = qcar(v_32292);
    return onevalue(v_32292);
}



// Code for all_defined

static LispObject CC_all_defined(LispObject env,
                         LispObject v_32268, LispObject v_32269)
{
    env = qenv(env);
    LispObject v_32287, v_32288;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_32269,v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_32268,v_32269);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_32269;
    v_32287 = v_32268;
// end of prologue
    goto v_32276;
v_32272:
    stack[-1] = v_32287;
    goto v_32273;
v_32274:
    goto v_32283;
v_32279:
    fn = elt(env, 1); // map__edges
    v_32288 = (*qfn1(fn))(fn, v_32287);
    env = stack[-2];
    goto v_32280;
v_32281:
    v_32287 = stack[0];
    goto v_32282;
v_32283:
    goto v_32279;
v_32280:
    goto v_32281;
v_32282:
    fn = elt(env, 2); // defined_append
    v_32287 = (*qfn2(fn))(fn, v_32288, v_32287);
    env = stack[-2];
    goto v_32275;
v_32276:
    goto v_32272;
v_32273:
    goto v_32274;
v_32275:
    {
        LispObject v_32291 = stack[-1];
        fn = elt(env, 3); // all_defined_map_
        return (*qfn2(fn))(fn, v_32291, v_32287);
    }
}



// Code for radd

static LispObject CC_radd(LispObject env,
                         LispObject v_32268, LispObject v_32269)
{
    env = qenv(env);
    LispObject v_32398, v_32399;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_32269,v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_32268,v_32269);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_32269;
    stack[-1] = v_32268;
// end of prologue
    stack[-2] = nil;
    v_32398 = stack[-1];
    if (!consp(v_32398)) goto v_32279;
    goto v_32286;
v_32282:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32283;
v_32284:
    v_32398 = stack[-1];
    fn = elt(env, 3); // prepf
    v_32398 = (*qfn1(fn))(fn, v_32398);
    goto v_32285;
v_32286:
    goto v_32282;
v_32283:
    goto v_32284;
v_32285:
    {
        LispObject v_32403 = stack[0];
        return list2(v_32403, v_32398);
    }
v_32279:
    goto v_32300;
v_32296:
    v_32399 = stack[-1];
    goto v_32297;
v_32298:
    v_32398 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32299;
v_32300:
    goto v_32296;
v_32297:
    goto v_32298;
v_32299:
    v_32398 = (LispObject)lessp2(v_32399, v_32398);
    v_32398 = v_32398 ? lisp_true : nil;
    env = stack[-3];
    if (v_32398 == nil) goto v_32293;
    v_32398 = stack[0];
    v_32398 = Levenp(nil, v_32398);
    env = stack[-3];
    if (v_32398 == nil) goto v_32293;
    v_32398 = lisp_true;
    stack[-2] = v_32398;
    v_32398 = stack[-1];
    v_32398 = negate(v_32398);
    env = stack[-3];
    stack[-1] = v_32398;
    goto v_32291;
v_32293:
v_32291:
    goto v_32314;
v_32310:
    v_32399 = stack[-1];
    goto v_32311;
v_32312:
    v_32398 = stack[0];
    goto v_32313;
v_32314:
    goto v_32310;
v_32311:
    goto v_32312;
v_32313:
    fn = elt(env, 4); // nrootnn
    v_32398 = (*qfn2(fn))(fn, v_32399, v_32398);
    env = stack[-3];
    stack[-1] = v_32398;
    v_32398 = stack[-2];
    if (v_32398 == nil) goto v_32320;
    v_32398 = qvalue(elt(env, 1)); // !*reduced
    if (v_32398 == nil) goto v_32325;
    goto v_32333;
v_32329:
    v_32399 = stack[0];
    goto v_32330;
v_32331:
    v_32398 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_32332;
v_32333:
    goto v_32329;
v_32330:
    goto v_32331;
v_32332:
    if (v_32399 == v_32398) goto v_32328;
    else goto v_32325;
v_32328:
    goto v_32341;
v_32337:
    v_32398 = stack[-1];
    stack[0] = qcar(v_32398);
    goto v_32338;
v_32339:
    goto v_32350;
v_32346:
    goto v_32356;
v_32352:
    v_32399 = elt(env, 2); // i
    goto v_32353;
v_32354:
    v_32398 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32355;
v_32356:
    goto v_32352;
v_32353:
    goto v_32354;
v_32355:
    fn = elt(env, 5); // to
    v_32399 = (*qfn2(fn))(fn, v_32399, v_32398);
    env = stack[-3];
    goto v_32347;
v_32348:
    v_32398 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32349;
v_32350:
    goto v_32346;
v_32347:
    goto v_32348;
v_32349:
    v_32398 = cons(v_32399, v_32398);
    env = stack[-3];
    v_32398 = ncons(v_32398);
    env = stack[-3];
    goto v_32340;
v_32341:
    goto v_32337;
v_32338:
    goto v_32339;
v_32340:
    fn = elt(env, 6); // multd
    v_32398 = (*qfn2(fn))(fn, stack[0], v_32398);
    stack[0] = v_32398;
    v_32398 = stack[-1];
    v_32398 = qcdr(v_32398);
    stack[-1] = v_32398;
    goto v_32323;
v_32325:
    v_32398 = stack[-1];
    v_32398 = qcar(v_32398);
    stack[0] = v_32398;
    v_32398 = stack[-1];
    v_32398 = qcdr(v_32398);
    v_32398 = negate(v_32398);
    stack[-1] = v_32398;
    goto v_32323;
v_32323:
    goto v_32318;
v_32320:
    v_32398 = stack[-1];
    v_32398 = qcar(v_32398);
    stack[0] = v_32398;
    v_32398 = stack[-1];
    v_32398 = qcdr(v_32398);
    stack[-1] = v_32398;
    goto v_32318;
v_32318:
    goto v_32383;
v_32379:
    v_32399 = stack[-1];
    goto v_32380;
v_32381:
    v_32398 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32382;
v_32383:
    goto v_32379;
v_32380:
    goto v_32381;
v_32382:
    if (v_32399 == v_32398) goto v_32377;
    else goto v_32378;
v_32377:
    v_32398 = stack[0];
    return ncons(v_32398);
v_32378:
    goto v_32395;
v_32391:
    v_32399 = stack[0];
    goto v_32392;
v_32393:
    v_32398 = stack[-1];
    goto v_32394;
v_32395:
    goto v_32391;
v_32392:
    goto v_32393;
v_32394:
    return list2(v_32399, v_32398);
    v_32398 = nil;
    return onevalue(v_32398);
}



// Code for gak

static LispObject CC_gak(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_32366, v_32367, v_32368, v_32369, v_32370;
    LispObject fn;
    LispObject v_32270, v_32269, v_32268;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "gak");
    va_start(aa, nargs);
    v_32268 = va_arg(aa, LispObject);
    v_32269 = va_arg(aa, LispObject);
    v_32270 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_32270,v_32269,v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_32268,v_32269,v_32270);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_32367 = v_32270;
    v_32368 = v_32269;
    v_32369 = v_32268;
// end of prologue
v_32267:
    v_32366 = v_32369;
    if (!consp(v_32366)) goto v_32278;
    else goto v_32279;
v_32278:
    v_32366 = lisp_true;
    goto v_32277;
v_32279:
    v_32366 = v_32369;
    v_32366 = qcar(v_32366);
    v_32366 = (consp(v_32366) ? nil : lisp_true);
    goto v_32277;
    v_32366 = nil;
v_32277:
    if (v_32366 == nil) goto v_32275;
    v_32366 = v_32367;
    goto v_32273;
v_32275:
    v_32366 = v_32369;
    v_32366 = qcar(v_32366);
    v_32366 = qcar(v_32366);
    v_32366 = qcar(v_32366);
    v_32370 = v_32366;
    goto v_32302;
v_32296:
    v_32366 = v_32369;
    stack[-3] = qcdr(v_32366);
    goto v_32297;
v_32298:
    stack[-2] = v_32368;
    goto v_32299;
v_32300:
    goto v_32313;
v_32307:
    v_32366 = v_32369;
    v_32366 = qcar(v_32366);
    stack[-1] = qcdr(v_32366);
    goto v_32308;
v_32309:
    stack[0] = v_32368;
    goto v_32310;
v_32311:
    v_32366 = v_32370;
    if (!consp(v_32366)) goto v_32325;
    goto v_32335;
v_32331:
    v_32366 = v_32370;
    v_32366 = qcar(v_32366);
    goto v_32332;
v_32333:
    goto v_32334;
v_32335:
    goto v_32331;
v_32332:
    goto v_32333;
v_32334:
    v_32366 = Lmember(nil, v_32366, v_32368);
    if (v_32366 == nil) goto v_32329;
    else goto v_32330;
v_32329:
    v_32366 = nil;
    goto v_32328;
v_32330:
    goto v_32347;
v_32343:
    v_32368 = v_32370;
    goto v_32344;
v_32345:
    v_32366 = v_32367;
    goto v_32346;
v_32347:
    goto v_32343;
v_32344:
    goto v_32345;
v_32346:
    v_32366 = Lmember(nil, v_32368, v_32366);
    v_32366 = (v_32366 == nil ? lisp_true : nil);
    goto v_32328;
    v_32366 = nil;
v_32328:
    goto v_32323;
v_32325:
    v_32366 = nil;
    goto v_32323;
    v_32366 = nil;
v_32323:
    if (v_32366 == nil) goto v_32321;
    goto v_32360;
v_32356:
    v_32366 = v_32367;
    goto v_32357;
v_32358:
    v_32367 = v_32370;
    goto v_32359;
v_32360:
    goto v_32356;
v_32357:
    goto v_32358;
v_32359:
    fn = elt(env, 1); // aconc
    v_32366 = (*qfn2(fn))(fn, v_32366, v_32367);
    env = stack[-4];
    goto v_32319;
v_32321:
    v_32366 = v_32367;
    goto v_32319;
    v_32366 = nil;
v_32319:
    goto v_32312;
v_32313:
    goto v_32307;
v_32308:
    goto v_32309;
v_32310:
    goto v_32311;
v_32312:
    v_32366 = CC_gak(elt(env, 0), 3, stack[-1], stack[0], v_32366);
    env = stack[-4];
    goto v_32301;
v_32302:
    goto v_32296;
v_32297:
    goto v_32298;
v_32299:
    goto v_32300;
v_32301:
    v_32369 = stack[-3];
    v_32368 = stack[-2];
    v_32367 = v_32366;
    goto v_32267;
    v_32366 = nil;
v_32273:
    return onevalue(v_32366);
}



// Code for resetparser

static LispObject CC_resetparser(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_32276;
    LispObject fn;
    argcheck(nargs, 0, "resetparser");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_32276 = qvalue(elt(env, 1)); // !*slin
    if (v_32276 == nil) goto v_32271;
    else goto v_32272;
v_32271:
    v_32276 = lisp_true;
    {
        fn = elt(env, 2); // comm1
        return (*qfn1(fn))(fn, v_32276);
    }
v_32272:
    v_32276 = nil;
    return onevalue(v_32276);
}



// Code for giminusp!:

static LispObject CC_giminuspT(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32293, v_32294, v_32295;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_32294 = v_32268;
// end of prologue
    goto v_32278;
v_32274:
    v_32293 = v_32294;
    v_32293 = qcdr(v_32293);
    v_32295 = qcar(v_32293);
    goto v_32275;
v_32276:
    v_32293 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32277;
v_32278:
    goto v_32274;
v_32275:
    goto v_32276;
v_32277:
    if (v_32295 == v_32293) goto v_32272;
    else goto v_32273;
v_32272:
    v_32293 = v_32294;
    v_32293 = qcdr(v_32293);
    v_32293 = qcdr(v_32293);
        return Lminusp(nil, v_32293);
v_32273:
    v_32293 = v_32294;
    v_32293 = qcdr(v_32293);
    v_32293 = qcar(v_32293);
        return Lminusp(nil, v_32293);
    v_32293 = nil;
    return onevalue(v_32293);
}



// Code for opfchk!!

static LispObject CC_opfchkB(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32554, v_32555;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_32268;
// end of prologue
    stack[-3] = nil;
    stack[-2] = nil;
    v_32554 = stack[-6];
    v_32554 = qcar(v_32554);
    stack[-7] = v_32554;
    stack[-5] = v_32554;
    v_32554 = stack[-6];
    v_32554 = qcdr(v_32554);
    stack[-6] = v_32554;
    goto v_32295;
v_32291:
    v_32555 = stack[-7];
    goto v_32292;
v_32293:
    v_32554 = elt(env, 1); // integer
    goto v_32294;
v_32295:
    goto v_32291;
v_32292:
    goto v_32293;
v_32294:
    v_32554 = Lflagp(nil, v_32555, v_32554);
    env = stack[-8];
    if (v_32554 == nil) goto v_32289;
    v_32554 = lisp_true;
    stack[-3] = v_32554;
    goto v_32304;
v_32300:
    v_32555 = stack[-7];
    goto v_32301;
v_32302:
    v_32554 = elt(env, 2); // !:rn!:
    goto v_32303;
v_32304:
    goto v_32300;
v_32301:
    goto v_32302;
v_32303:
    v_32554 = get(v_32555, v_32554);
    env = stack[-8];
    goto v_32287;
v_32289:
    v_32554 = qvalue(elt(env, 3)); // !*numval
    if (v_32554 == nil) goto v_32308;
    goto v_32316;
v_32312:
    v_32555 = qvalue(elt(env, 4)); // dmode!*
    goto v_32313;
v_32314:
    v_32554 = elt(env, 5); // (!:rd!: !:cr!:)
    goto v_32315;
v_32316:
    goto v_32312;
v_32313:
    goto v_32314;
v_32315:
    v_32554 = Lmemq(nil, v_32555, v_32554);
    if (v_32554 == nil) goto v_32308;
    goto v_32325;
v_32321:
    v_32555 = stack[-7];
    goto v_32322;
v_32323:
    v_32554 = elt(env, 6); // !:rd!:
    goto v_32324;
v_32325:
    goto v_32321;
v_32322:
    goto v_32323;
v_32324:
    v_32554 = get(v_32555, v_32554);
    env = stack[-8];
    goto v_32287;
v_32308:
    v_32554 = nil;
v_32287:
    stack[-7] = v_32554;
    v_32554 = stack[-7];
    if (v_32554 == nil) goto v_32330;
    else goto v_32331;
v_32330:
    v_32554 = nil;
    goto v_32277;
v_32331:
    v_32554 = stack[-3];
    if (v_32554 == nil) goto v_32337;
    v_32554 = elt(env, 7); // simprn
    goto v_32335;
v_32337:
    goto v_32347;
v_32343:
    v_32555 = stack[-7];
    goto v_32344;
v_32345:
    v_32554 = elt(env, 8); // simparg
    goto v_32346;
v_32347:
    goto v_32343;
v_32344:
    goto v_32345;
v_32346:
    v_32554 = get(v_32555, v_32554);
    env = stack[-8];
    stack[-4] = v_32554;
    if (v_32554 == nil) goto v_32341;
    v_32554 = stack[-4];
    goto v_32335;
v_32341:
    v_32554 = elt(env, 9); // simprd
    goto v_32335;
    v_32554 = nil;
v_32335:
    stack[-4] = v_32554;
    v_32554 = stack[-3];
    if (v_32554 == nil) goto v_32358;
    else goto v_32356;
v_32358:
    v_32554 = qvalue(elt(env, 10)); // !*complex
    if (v_32554 == nil) goto v_32356;
    goto v_32357;
v_32356:
    goto v_32280;
v_32357:
    goto v_32371;
v_32367:
    v_32554 = stack[-6];
    v_32555 = qcar(v_32554);
    goto v_32368;
v_32369:
    v_32554 = elt(env, 11); // list
    goto v_32370;
v_32371:
    goto v_32367;
v_32368:
    goto v_32369;
v_32370:
    if (!consp(v_32555)) goto v_32365;
    v_32555 = qcar(v_32555);
    if (v_32555 == v_32554) goto v_32364;
    else goto v_32365;
v_32364:
    v_32554 = stack[-6];
    v_32554 = qcar(v_32554);
    v_32554 = qcdr(v_32554);
    fn = elt(env, 17); // revlis
    v_32554 = (*qfn1(fn))(fn, v_32554);
    env = stack[-8];
    fn = elt(env, 18); // simpcr
    v_32554 = (*qfn1(fn))(fn, v_32554);
    env = stack[-8];
    v_32555 = v_32554;
    if (v_32554 == nil) goto v_32378;
    goto v_32391;
v_32387:
    goto v_32388;
v_32389:
    v_32554 = nil;
    goto v_32390;
v_32391:
    goto v_32387;
v_32388:
    goto v_32389;
v_32390:
    if (!consp(v_32555)) goto v_32378;
    v_32555 = qcar(v_32555);
    if (v_32555 == v_32554) goto v_32385;
    else goto v_32378;
v_32385:
    goto v_32279;
v_32378:
    goto v_32280;
    goto v_32363;
v_32365:
v_32363:
    v_32554 = stack[-6];
    fn = elt(env, 17); // revlis
    v_32554 = (*qfn1(fn))(fn, v_32554);
    env = stack[-8];
    fn = elt(env, 18); // simpcr
    v_32554 = (*qfn1(fn))(fn, v_32554);
    env = stack[-8];
    stack[-6] = v_32554;
    if (v_32554 == nil) goto v_32398;
    else goto v_32399;
v_32398:
    v_32554 = nil;
    goto v_32277;
v_32399:
    goto v_32415;
v_32411:
    v_32555 = stack[-6];
    goto v_32412;
v_32413:
    v_32554 = nil;
    goto v_32414;
v_32415:
    goto v_32411;
v_32412:
    goto v_32413;
v_32414:
    if (!consp(v_32555)) goto v_32409;
    v_32555 = qcar(v_32555);
    if (v_32555 == v_32554) goto v_32408;
    else goto v_32409;
v_32408:
    v_32554 = lisp_true;
    goto v_32407;
v_32409:
    goto v_32429;
v_32425:
    v_32555 = stack[-5];
    goto v_32426;
v_32427:
    v_32554 = elt(env, 12); // expt
    goto v_32428;
v_32429:
    goto v_32425;
v_32426:
    goto v_32427;
v_32428:
    if (v_32555 == v_32554) goto v_32423;
    else goto v_32424;
v_32423:
    v_32554 = stack[-6];
    v_32554 = qcar(v_32554);
    v_32554 = qcar(v_32554);
    fn = elt(env, 19); // rd!:minusp
    v_32554 = (*qfn1(fn))(fn, v_32554);
    env = stack[-8];
    goto v_32422;
v_32424:
    v_32554 = nil;
    goto v_32422;
    v_32554 = nil;
v_32422:
    goto v_32407;
    v_32554 = nil;
v_32407:
    if (v_32554 == nil) goto v_32405;
    v_32554 = stack[-6];
    v_32554 = qcdr(v_32554);
    stack[-6] = v_32554;
    goto v_32397;
v_32405:
    v_32554 = stack[-6];
    v_32554 = qcdr(v_32554);
    stack[-2] = v_32554;
    v_32554 = stack[-6];
    v_32554 = qcar(v_32554);
    stack[-6] = v_32554;
    goto v_32280;
v_32397:
v_32278:
    goto v_32456;
v_32452:
    v_32555 = stack[-5];
    goto v_32453;
v_32454:
    v_32554 = elt(env, 13); // !:cr!:
    goto v_32455;
v_32456:
    goto v_32452;
v_32453:
    goto v_32454;
v_32455:
    v_32554 = get(v_32555, v_32554);
    env = stack[-8];
    stack[-7] = v_32554;
    if (v_32554 == nil) goto v_32450;
    goto v_32281;
v_32450:
v_32279:
    goto v_32466;
v_32460:
    stack[-1] = elt(env, 14); // alg
    goto v_32461;
v_32462:
    stack[0] = (LispObject)288+TAG_FIXNUM; // 18
    goto v_32463;
v_32464:
    goto v_32474;
v_32470:
    v_32555 = stack[-5];
    goto v_32471;
v_32472:
    v_32554 = elt(env, 15); // "is not defined as complex function"
    goto v_32473;
v_32474:
    goto v_32470;
v_32471:
    goto v_32472;
v_32473:
    v_32554 = list2(v_32555, v_32554);
    env = stack[-8];
    goto v_32465;
v_32466:
    goto v_32460;
v_32461:
    goto v_32462;
v_32463:
    goto v_32464;
v_32465:
    fn = elt(env, 20); // rerror
    v_32554 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_32554);
    env = stack[-8];
v_32280:
    goto v_32486;
v_32482:
    stack[0] = stack[-4];
    goto v_32483;
v_32484:
    v_32554 = stack[-6];
    fn = elt(env, 17); // revlis
    v_32554 = (*qfn1(fn))(fn, v_32554);
    env = stack[-8];
    goto v_32485;
v_32486:
    goto v_32482;
v_32483:
    goto v_32484;
v_32485:
    v_32554 = Lapply1(nil, stack[0], v_32554);
    env = stack[-8];
    stack[-6] = v_32554;
    if (v_32554 == nil) goto v_32479;
    else goto v_32480;
v_32479:
    v_32554 = nil;
    goto v_32277;
v_32480:
v_32281:
    goto v_32499;
v_32493:
    stack[0] = elt(env, 16); // apply
    goto v_32494;
v_32495:
    v_32554 = stack[-7];
    stack[-1] = Lmkquote(nil, v_32554);
    env = stack[-8];
    goto v_32496;
v_32497:
    v_32554 = stack[-6];
    v_32554 = Lmkquote(nil, v_32554);
    env = stack[-8];
    goto v_32498;
v_32499:
    goto v_32493;
v_32494:
    goto v_32495;
v_32496:
    goto v_32497;
v_32498:
    v_32554 = list3(stack[0], stack[-1], v_32554);
    env = stack[-8];
    fn = elt(env, 21); // errorset2
    v_32554 = (*qfn1(fn))(fn, v_32554);
    env = stack[-8];
    stack[-6] = v_32554;
    v_32554 = stack[-6];
    fn = elt(env, 22); // errorp
    v_32554 = (*qfn1(fn))(fn, v_32554);
    env = stack[-8];
    if (v_32554 == nil) goto v_32509;
    else goto v_32507;
v_32509:
    goto v_32522;
v_32518:
    v_32554 = stack[-6];
    v_32555 = qcar(v_32554);
    stack[-6] = v_32555;
    goto v_32519;
v_32520:
    v_32554 = elt(env, 6); // !:rd!:
    goto v_32521;
v_32522:
    goto v_32518;
v_32519:
    goto v_32520;
v_32521:
    if (!consp(v_32555)) goto v_32516;
    v_32555 = qcar(v_32555);
    if (v_32555 == v_32554) goto v_32515;
    else goto v_32516;
v_32515:
    v_32554 = stack[-6];
    v_32554 = qcdr(v_32554);
    fn = elt(env, 23); // complexp
    v_32554 = (*qfn1(fn))(fn, v_32554);
    env = stack[-8];
    goto v_32514;
v_32516:
    v_32554 = nil;
    goto v_32514;
    v_32554 = nil;
v_32514:
    if (v_32554 == nil) goto v_32512;
    else goto v_32507;
v_32512:
    goto v_32508;
v_32507:
    v_32554 = stack[-2];
    if (v_32554 == nil) goto v_32535;
    v_32554 = stack[-2];
    stack[-6] = v_32554;
    v_32554 = nil;
    stack[-2] = v_32554;
    goto v_32278;
v_32535:
    v_32554 = nil;
    goto v_32277;
    goto v_32506;
v_32508:
    v_32554 = stack[-3];
    if (v_32554 == nil) goto v_32547;
    v_32554 = stack[-6];
    {
        fn = elt(env, 24); // intconv
        return (*qfn1(fn))(fn, v_32554);
    }
v_32547:
    v_32554 = stack[-6];
    goto v_32545;
    v_32554 = nil;
v_32545:
    goto v_32277;
v_32506:
    v_32554 = nil;
v_32277:
    return onevalue(v_32554);
}



// Code for constant_expr_listp

static LispObject CC_constant_expr_listp(LispObject env,
                         LispObject v_32268)
{
    env = qenv(env);
    LispObject v_32338, v_32339;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_32268);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_32268);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_32268;
// end of prologue
v_32273:
    v_32338 = stack[0];
    if (!consp(v_32338)) goto v_32276;
    else goto v_32277;
v_32276:
    v_32338 = stack[0];
    v_32338 = (v_32338 == nil ? lisp_true : nil);
    v_32339 = v_32338;
    if (v_32338 == nil) goto v_32282;
    v_32338 = v_32339;
    goto v_32272;
v_32282:
    v_32338 = stack[0];
    v_32338 = (is_number(v_32338) ? lisp_true : nil);
    v_32339 = v_32338;
    if (v_32338 == nil) goto v_32287;
    v_32338 = v_32339;
    goto v_32272;
v_32287:
    goto v_32298;
v_32294:
    v_32339 = stack[0];
    goto v_32295;
v_32296:
    v_32338 = elt(env, 1); // constant
    goto v_32297;
v_32298:
    goto v_32294;
v_32295:
    goto v_32296;
v_32297:
    v_32338 = Lflagp(nil, v_32339, v_32338);
    env = stack[-1];
    v_32339 = v_32338;
    if (v_32338 == nil) goto v_32292;
    v_32338 = v_32339;
    goto v_32272;
v_32292:
    goto v_32312;
v_32308:
    v_32339 = stack[0];
    goto v_32309;
v_32310:
    v_32338 = elt(env, 2); // i
    goto v_32311;
v_32312:
    goto v_32308;
v_32309:
    goto v_32310;
v_32311:
    if (v_32339 == v_32338) goto v_32306;
    else goto v_32307;
v_32306:
    v_32338 = elt(env, 2); // i
    if (!symbolp(v_32338)) v_32338 = nil;
    else { v_32338 = qfastgets(v_32338);
           if (v_32338 != nil) { v_32338 = elt(v_32338, 56); // idvalfn
#ifdef RECORD_GET
             if (v_32338 != SPID_NOPROP)
                record_get(elt(fastget_names, 56), 1);
             else record_get(elt(fastget_names, 56), 0),
                v_32338 = nil; }
           else record_get(elt(fastget_names, 56), 0); }
#else
             if (v_32338 == SPID_NOPROP) v_32338 = nil; }}
#endif
    goto v_32305;
v_32307:
    v_32338 = nil;
    goto v_32305;
    v_32338 = nil;
v_32305:
    v_32339 = v_32338;
    if (v_32338 == nil) goto v_32303;
    v_32338 = v_32339;
    goto v_32272;
v_32303:
    v_32338 = nil;
    goto v_32272;
    goto v_32275;
v_32277:
    v_32338 = stack[0];
    v_32338 = qcar(v_32338);
    fn = elt(env, 3); // constant_exprp
    v_32338 = (*qfn1(fn))(fn, v_32338);
    env = stack[-1];
    if (v_32338 == nil) goto v_32329;
    v_32338 = stack[0];
    v_32338 = qcdr(v_32338);
    stack[0] = v_32338;
    goto v_32273;
v_32329:
    v_32338 = nil;
    goto v_32272;
    goto v_32275;
v_32275:
    v_32338 = nil;
v_32272:
    return onevalue(v_32338);
}



setup_type const u55_setup[] =
{
    {"liendimcom",              CC_liendimcom,  TOO_MANY_1,    WRONG_NO_1},
    {"dpmat_gbtag",             CC_dpmat_gbtag, TOO_MANY_1,    WRONG_NO_1},
    {"st_extract_symcells1",    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_st_extract_symcells1},
    {"addcoeffs",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_addcoeffs},
    {"qqe_simpat",              CC_qqe_simpat,  TOO_MANY_1,    WRONG_NO_1},
    {"bc_minus?",               CC_bc_minusW,   TOO_MANY_1,    WRONG_NO_1},
    {"crprimp",                 CC_crprimp,     TOO_MANY_1,    WRONG_NO_1},
    {"remove_critical_pairs",   TOO_FEW_2,      CC_remove_critical_pairs,WRONG_NO_2},
    {"acmemb",                  TOO_FEW_2,      CC_acmemb,     WRONG_NO_2},
    {"physopplus",              CC_physopplus,  TOO_MANY_1,    WRONG_NO_1},
    {"bassoc",                  TOO_FEW_2,      CC_bassoc,     WRONG_NO_2},
    {"*sq2fourier",             CC_Hsq2fourier, TOO_MANY_1,    WRONG_NO_1},
    {"all_index_lst",           CC_all_index_lst,TOO_MANY_1,   WRONG_NO_1},
    {"sc_create",               CC_sc_create,   TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_exploitknowl",       CC_ofsf_exploitknowl,TOO_MANY_1,WRONG_NO_1},
    {"uterm",                   TOO_FEW_2,      CC_uterm,      WRONG_NO_2},
    {"change+sq+to+int",        CC_changeLsqLtoLint,TOO_MANY_1,WRONG_NO_1},
    {"ofsf_factsf",             CC_ofsf_factsf, TOO_MANY_1,    WRONG_NO_1},
    {"operator",                CC_operator,    TOO_MANY_1,    WRONG_NO_1},
    {"look_for_rational",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_look_for_rational},
    {"vevzero?1",               CC_vevzeroW1,   TOO_MANY_1,    WRONG_NO_1},
    {"xpndwedge",               CC_xpndwedge,   TOO_MANY_1,    WRONG_NO_1},
    {"unshift",                 CC_unshift,     TOO_MANY_1,    WRONG_NO_1},
    {"r2speclist",              CC_r2speclist,  TOO_MANY_1,    WRONG_NO_1},
    {"noncom1",                 CC_noncom1,     TOO_MANY_1,    WRONG_NO_1},
    {"rationalizef",            CC_rationalizef,TOO_MANY_1,    WRONG_NO_1},
    {"lowestdeg",               TOO_FEW_2,      CC_lowestdeg,  WRONG_NO_2},
    {"simprd",                  CC_simprd,      TOO_MANY_1,    WRONG_NO_1},
    {"add-to-sorted-tree",      TOO_FEW_2,      CC_addKtoKsortedKtree,WRONG_NO_2},
    {"get*nr*real*irred*reps",  CC_getHnrHrealHirredHreps,TOO_MANY_1,WRONG_NO_1},
    {"pasf_ceeq",               CC_pasf_ceeq,   TOO_MANY_1,    WRONG_NO_1},
    {"matrix_input_test",       CC_matrix_input_test,TOO_MANY_1,WRONG_NO_1},
    {"dip-nc-ev-prod",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dipKncKevKprod},
    {"row_dim",                 CC_row_dim,     TOO_MANY_1,    WRONG_NO_1},
    {"all_defined",             TOO_FEW_2,      CC_all_defined,WRONG_NO_2},
    {"radd",                    TOO_FEW_2,      CC_radd,       WRONG_NO_2},
    {"gak",                     WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gak},
    {"resetparser",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_resetparser},
    {"giminusp:",               CC_giminuspT,   TOO_MANY_1,    WRONG_NO_1},
    {"opfchk!",                 CC_opfchkB,     TOO_MANY_1,    WRONG_NO_1},
    {"constant_expr_listp",     CC_constant_expr_listp,TOO_MANY_1,WRONG_NO_1},
    {NULL, (one_args *)"u55", (two_args *)"160663 6719845 7763379", 0}
};

// end of generated code
