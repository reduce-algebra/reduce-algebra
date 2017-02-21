
// $destdir/u33.c        Machine generated C code

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



// Code for expand_rule

static LispObject CC_expand_rule(LispObject env,
                         LispObject v_18442)
{
    env = qenv(env);
    LispObject v_18593, v_18594;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18442);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    v_18594 = v_18442;
// end of prologue
    goto v_18449;
v_18445:
    v_18593 = v_18594;
    stack[-9] = qcar(v_18593);
    goto v_18446;
v_18447:
    v_18593 = v_18594;
    v_18593 = qcdr(v_18593);
    stack[-8] = v_18593;
    v_18593 = stack[-8];
    if (v_18593 == nil) goto v_18462;
    else goto v_18463;
v_18462:
    v_18593 = nil;
    goto v_18456;
v_18463:
    v_18593 = stack[-8];
    v_18593 = qcar(v_18593);
    stack[-4] = v_18593;
    goto v_18475;
v_18471:
    v_18593 = stack[-4];
    v_18593 = qcar(v_18593);
    stack[-3] = v_18593;
    v_18593 = stack[-3];
    if (v_18593 == nil) goto v_18486;
    else goto v_18487;
v_18486:
    v_18593 = nil;
    v_18594 = v_18593;
    goto v_18480;
v_18487:
    v_18593 = stack[-3];
    v_18593 = qcar(v_18593);
    fn = elt(env, 1); // expand_terminal
    v_18593 = (*qfn1(fn))(fn, v_18593);
    env = stack[-10];
    v_18593 = ncons(v_18593);
    env = stack[-10];
    stack[-1] = v_18593;
    stack[-2] = v_18593;
v_18481:
    v_18593 = stack[-3];
    v_18593 = qcdr(v_18593);
    stack[-3] = v_18593;
    v_18593 = stack[-3];
    if (v_18593 == nil) goto v_18500;
    else goto v_18501;
v_18500:
    v_18593 = stack[-2];
    v_18594 = v_18593;
    goto v_18480;
v_18501:
    goto v_18509;
v_18505:
    stack[0] = stack[-1];
    goto v_18506;
v_18507:
    v_18593 = stack[-3];
    v_18593 = qcar(v_18593);
    fn = elt(env, 1); // expand_terminal
    v_18593 = (*qfn1(fn))(fn, v_18593);
    env = stack[-10];
    v_18593 = ncons(v_18593);
    env = stack[-10];
    goto v_18508;
v_18509:
    goto v_18505;
v_18506:
    goto v_18507;
v_18508:
    v_18593 = Lrplacd(nil, stack[0], v_18593);
    env = stack[-10];
    v_18593 = stack[-1];
    v_18593 = qcdr(v_18593);
    stack[-1] = v_18593;
    goto v_18481;
v_18480:
    goto v_18472;
v_18473:
    v_18593 = stack[-4];
    v_18593 = qcdr(v_18593);
    goto v_18474;
v_18475:
    goto v_18471;
v_18472:
    goto v_18473;
v_18474:
    v_18593 = cons(v_18594, v_18593);
    env = stack[-10];
    v_18593 = ncons(v_18593);
    env = stack[-10];
    stack[-6] = v_18593;
    stack[-7] = v_18593;
v_18457:
    v_18593 = stack[-8];
    v_18593 = qcdr(v_18593);
    stack[-8] = v_18593;
    v_18593 = stack[-8];
    if (v_18593 == nil) goto v_18525;
    else goto v_18526;
v_18525:
    v_18593 = stack[-7];
    goto v_18456;
v_18526:
    goto v_18534;
v_18530:
    stack[-5] = stack[-6];
    goto v_18531;
v_18532:
    v_18593 = stack[-8];
    v_18593 = qcar(v_18593);
    stack[-4] = v_18593;
    goto v_18545;
v_18541:
    v_18593 = stack[-4];
    v_18593 = qcar(v_18593);
    stack[-3] = v_18593;
    v_18593 = stack[-3];
    if (v_18593 == nil) goto v_18556;
    else goto v_18557;
v_18556:
    v_18593 = nil;
    v_18594 = v_18593;
    goto v_18550;
v_18557:
    v_18593 = stack[-3];
    v_18593 = qcar(v_18593);
    fn = elt(env, 1); // expand_terminal
    v_18593 = (*qfn1(fn))(fn, v_18593);
    env = stack[-10];
    v_18593 = ncons(v_18593);
    env = stack[-10];
    stack[-1] = v_18593;
    stack[-2] = v_18593;
v_18551:
    v_18593 = stack[-3];
    v_18593 = qcdr(v_18593);
    stack[-3] = v_18593;
    v_18593 = stack[-3];
    if (v_18593 == nil) goto v_18570;
    else goto v_18571;
v_18570:
    v_18593 = stack[-2];
    v_18594 = v_18593;
    goto v_18550;
v_18571:
    goto v_18579;
v_18575:
    stack[0] = stack[-1];
    goto v_18576;
v_18577:
    v_18593 = stack[-3];
    v_18593 = qcar(v_18593);
    fn = elt(env, 1); // expand_terminal
    v_18593 = (*qfn1(fn))(fn, v_18593);
    env = stack[-10];
    v_18593 = ncons(v_18593);
    env = stack[-10];
    goto v_18578;
v_18579:
    goto v_18575;
v_18576:
    goto v_18577;
v_18578:
    v_18593 = Lrplacd(nil, stack[0], v_18593);
    env = stack[-10];
    v_18593 = stack[-1];
    v_18593 = qcdr(v_18593);
    stack[-1] = v_18593;
    goto v_18551;
v_18550:
    goto v_18542;
v_18543:
    v_18593 = stack[-4];
    v_18593 = qcdr(v_18593);
    goto v_18544;
v_18545:
    goto v_18541;
v_18542:
    goto v_18543;
v_18544:
    v_18593 = cons(v_18594, v_18593);
    env = stack[-10];
    v_18593 = ncons(v_18593);
    env = stack[-10];
    goto v_18533;
v_18534:
    goto v_18530;
v_18531:
    goto v_18532;
v_18533:
    v_18593 = Lrplacd(nil, stack[-5], v_18593);
    env = stack[-10];
    v_18593 = stack[-6];
    v_18593 = qcdr(v_18593);
    stack[-6] = v_18593;
    goto v_18457;
v_18456:
    goto v_18448;
v_18449:
    goto v_18445;
v_18446:
    goto v_18447;
v_18448:
    {
        LispObject v_18605 = stack[-9];
        return cons(v_18605, v_18593);
    }
}



// Code for formboollis

static LispObject CC_formboollis(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18508, v_18509, v_18510;
    LispObject fn;
    LispObject v_18445, v_18444, v_18443, v_18442;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "formboollis");
    va_start(aa, nargs);
    v_18442 = va_arg(aa, LispObject);
    v_18443 = va_arg(aa, LispObject);
    v_18444 = va_arg(aa, LispObject);
    v_18445 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_18445,v_18444,v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_18442,v_18443,v_18444,v_18445);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_18445;
    stack[-1] = v_18444;
    stack[-2] = v_18443;
    stack[-3] = v_18442;
// end of prologue
    stack[-4] = nil;
v_18452:
    v_18508 = stack[-3];
    if (v_18508 == nil) goto v_18455;
    else goto v_18456;
v_18455:
    goto v_18451;
v_18456:
    v_18508 = stack[0];
    if (v_18508 == nil) goto v_18462;
    goto v_18469;
v_18465:
    goto v_18477;
v_18471:
    v_18508 = stack[-3];
    v_18510 = qcar(v_18508);
    goto v_18472;
v_18473:
    v_18509 = stack[-2];
    goto v_18474;
v_18475:
    v_18508 = stack[-1];
    goto v_18476;
v_18477:
    goto v_18471;
v_18472:
    goto v_18473;
v_18474:
    goto v_18475;
v_18476:
    fn = elt(env, 1); // formbool
    v_18509 = (*qfnn(fn))(fn, 3, v_18510, v_18509, v_18508);
    env = stack[-5];
    goto v_18466;
v_18467:
    v_18508 = stack[-4];
    goto v_18468;
v_18469:
    goto v_18465;
v_18466:
    goto v_18467;
v_18468:
    v_18508 = cons(v_18509, v_18508);
    env = stack[-5];
    stack[-4] = v_18508;
    goto v_18460;
v_18462:
    goto v_18490;
v_18486:
    goto v_18498;
v_18492:
    v_18508 = stack[-3];
    v_18510 = qcar(v_18508);
    goto v_18493;
v_18494:
    v_18509 = stack[-2];
    goto v_18495;
v_18496:
    v_18508 = stack[-1];
    goto v_18497;
v_18498:
    goto v_18492;
v_18493:
    goto v_18494;
v_18495:
    goto v_18496;
v_18497:
    fn = elt(env, 2); // formc!*
    v_18509 = (*qfnn(fn))(fn, 3, v_18510, v_18509, v_18508);
    env = stack[-5];
    goto v_18487;
v_18488:
    v_18508 = stack[-4];
    goto v_18489;
v_18490:
    goto v_18486;
v_18487:
    goto v_18488;
v_18489:
    v_18508 = cons(v_18509, v_18508);
    env = stack[-5];
    stack[-4] = v_18508;
    goto v_18460;
v_18460:
    v_18508 = stack[-3];
    v_18508 = qcdr(v_18508);
    stack[-3] = v_18508;
    goto v_18452;
v_18451:
    v_18508 = stack[-4];
    {
        fn = elt(env, 3); // reversip!*
        return (*qfn1(fn))(fn, v_18508);
    }
    return onevalue(v_18508);
}



// Code for pasf_dt

static LispObject CC_pasf_dt(LispObject env,
                         LispObject v_18442)
{
    env = qenv(env);
    LispObject v_18813, v_18814, v_18815, v_18816;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18442);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18442;
// end of prologue
    goto v_18460;
v_18456:
    v_18814 = stack[0];
    goto v_18457;
v_18458:
    v_18813 = elt(env, 1); // true
    goto v_18459;
v_18460:
    goto v_18456;
v_18457:
    goto v_18458;
v_18459:
    if (v_18814 == v_18813) goto v_18454;
    else goto v_18455;
v_18454:
    v_18813 = lisp_true;
    goto v_18453;
v_18455:
    goto v_18470;
v_18466:
    v_18814 = stack[0];
    goto v_18467;
v_18468:
    v_18813 = elt(env, 2); // false
    goto v_18469;
v_18470:
    goto v_18466;
v_18467:
    goto v_18468;
v_18469:
    v_18813 = (v_18814 == v_18813 ? lisp_true : nil);
    goto v_18453;
    v_18813 = nil;
v_18453:
    if (v_18813 == nil) goto v_18451;
    v_18813 = stack[0];
    goto v_18447;
v_18451:
    v_18813 = stack[0];
    v_18813 = qcdr(v_18813);
    v_18813 = qcar(v_18813);
    fn = elt(env, 16); // pasf_pdp
    v_18813 = (*qfn1(fn))(fn, v_18813);
    env = stack[-1];
    v_18816 = v_18813;
    goto v_18491;
v_18487:
    v_18814 = stack[0];
    goto v_18488;
v_18489:
    v_18813 = elt(env, 1); // true
    goto v_18490;
v_18491:
    goto v_18487;
v_18488:
    goto v_18489;
v_18490:
    if (v_18814 == v_18813) goto v_18485;
    else goto v_18486;
v_18485:
    v_18813 = lisp_true;
    goto v_18484;
v_18486:
    goto v_18501;
v_18497:
    v_18814 = stack[0];
    goto v_18498;
v_18499:
    v_18813 = elt(env, 2); // false
    goto v_18500;
v_18501:
    goto v_18497;
v_18498:
    goto v_18499;
v_18500:
    v_18813 = (v_18814 == v_18813 ? lisp_true : nil);
    goto v_18484;
    v_18813 = nil;
v_18484:
    if (v_18813 == nil) goto v_18482;
    v_18813 = stack[0];
    goto v_18480;
v_18482:
    v_18813 = stack[0];
    v_18813 = qcar(v_18813);
    v_18813 = Lconsp(nil, v_18813);
    env = stack[-1];
    if (v_18813 == nil) goto v_18507;
    v_18813 = stack[0];
    v_18813 = qcar(v_18813);
    v_18813 = qcar(v_18813);
    goto v_18480;
v_18507:
    v_18813 = stack[0];
    v_18813 = qcar(v_18813);
    goto v_18480;
    v_18813 = nil;
v_18480:
    v_18815 = v_18813;
    goto v_18530;
v_18526:
    v_18814 = v_18816;
    goto v_18527;
v_18528:
    v_18813 = elt(env, 3); // pdef
    goto v_18529;
v_18530:
    goto v_18526;
v_18527:
    goto v_18528;
v_18529:
    if (v_18814 == v_18813) goto v_18524;
    else goto v_18525;
v_18524:
    goto v_18537;
v_18533:
    v_18814 = v_18815;
    goto v_18534;
v_18535:
    v_18813 = elt(env, 4); // (equal lessp leq)
    goto v_18536;
v_18537:
    goto v_18533;
v_18534:
    goto v_18535;
v_18536:
    v_18813 = Lmemq(nil, v_18814, v_18813);
    goto v_18523;
v_18525:
    v_18813 = nil;
    goto v_18523;
    v_18813 = nil;
v_18523:
    if (v_18813 == nil) goto v_18521;
    v_18813 = elt(env, 2); // false
    goto v_18447;
v_18521:
    goto v_18557;
v_18553:
    v_18814 = v_18816;
    goto v_18554;
v_18555:
    v_18813 = elt(env, 5); // ndef
    goto v_18556;
v_18557:
    goto v_18553;
v_18554:
    goto v_18555;
v_18556:
    if (v_18814 == v_18813) goto v_18551;
    else goto v_18552;
v_18551:
    goto v_18564;
v_18560:
    v_18814 = v_18815;
    goto v_18561;
v_18562:
    v_18813 = elt(env, 6); // (equal greaterp geq)
    goto v_18563;
v_18564:
    goto v_18560;
v_18561:
    goto v_18562;
v_18563:
    v_18813 = Lmemq(nil, v_18814, v_18813);
    goto v_18550;
v_18552:
    v_18813 = nil;
    goto v_18550;
    v_18813 = nil;
v_18550:
    if (v_18813 == nil) goto v_18548;
    v_18813 = elt(env, 2); // false
    goto v_18447;
v_18548:
    goto v_18584;
v_18580:
    v_18814 = v_18816;
    goto v_18581;
v_18582:
    v_18813 = elt(env, 3); // pdef
    goto v_18583;
v_18584:
    goto v_18580;
v_18581:
    goto v_18582;
v_18583:
    if (v_18814 == v_18813) goto v_18578;
    else goto v_18579;
v_18578:
    goto v_18591;
v_18587:
    v_18814 = v_18815;
    goto v_18588;
v_18589:
    v_18813 = elt(env, 7); // (neq greaterp geq)
    goto v_18590;
v_18591:
    goto v_18587;
v_18588:
    goto v_18589;
v_18590:
    v_18813 = Lmemq(nil, v_18814, v_18813);
    goto v_18577;
v_18579:
    v_18813 = nil;
    goto v_18577;
    v_18813 = nil;
v_18577:
    if (v_18813 == nil) goto v_18575;
    v_18813 = elt(env, 1); // true
    goto v_18447;
v_18575:
    goto v_18611;
v_18607:
    v_18814 = v_18816;
    goto v_18608;
v_18609:
    v_18813 = elt(env, 5); // ndef
    goto v_18610;
v_18611:
    goto v_18607;
v_18608:
    goto v_18609;
v_18610:
    if (v_18814 == v_18813) goto v_18605;
    else goto v_18606;
v_18605:
    goto v_18618;
v_18614:
    v_18814 = v_18815;
    goto v_18615;
v_18616:
    v_18813 = elt(env, 8); // (neq lessp leq)
    goto v_18617;
v_18618:
    goto v_18614;
v_18615:
    goto v_18616;
v_18617:
    v_18813 = Lmemq(nil, v_18814, v_18813);
    goto v_18604;
v_18606:
    v_18813 = nil;
    goto v_18604;
    v_18813 = nil;
v_18604:
    if (v_18813 == nil) goto v_18602;
    v_18813 = elt(env, 1); // true
    goto v_18447;
v_18602:
    goto v_18638;
v_18634:
    v_18814 = v_18816;
    goto v_18635;
v_18636:
    v_18813 = elt(env, 9); // psdef
    goto v_18637;
v_18638:
    goto v_18634;
v_18635:
    goto v_18636;
v_18637:
    if (v_18814 == v_18813) goto v_18632;
    else goto v_18633;
v_18632:
    goto v_18645;
v_18641:
    v_18814 = v_18815;
    goto v_18642;
v_18643:
    v_18813 = elt(env, 10); // lessp
    goto v_18644;
v_18645:
    goto v_18641;
v_18642:
    goto v_18643;
v_18644:
    v_18813 = (v_18814 == v_18813 ? lisp_true : nil);
    goto v_18631;
v_18633:
    v_18813 = nil;
    goto v_18631;
    v_18813 = nil;
v_18631:
    if (v_18813 == nil) goto v_18629;
    v_18813 = elt(env, 2); // false
    goto v_18447;
v_18629:
    goto v_18665;
v_18661:
    v_18814 = v_18816;
    goto v_18662;
v_18663:
    v_18813 = elt(env, 11); // nsdef
    goto v_18664;
v_18665:
    goto v_18661;
v_18662:
    goto v_18663;
v_18664:
    if (v_18814 == v_18813) goto v_18659;
    else goto v_18660;
v_18659:
    goto v_18672;
v_18668:
    v_18814 = v_18815;
    goto v_18669;
v_18670:
    v_18813 = elt(env, 12); // greaterp
    goto v_18671;
v_18672:
    goto v_18668;
v_18669:
    goto v_18670;
v_18671:
    v_18813 = (v_18814 == v_18813 ? lisp_true : nil);
    goto v_18658;
v_18660:
    v_18813 = nil;
    goto v_18658;
    v_18813 = nil;
v_18658:
    if (v_18813 == nil) goto v_18656;
    v_18813 = elt(env, 2); // false
    goto v_18447;
v_18656:
    goto v_18692;
v_18688:
    v_18814 = v_18816;
    goto v_18689;
v_18690:
    v_18813 = elt(env, 9); // psdef
    goto v_18691;
v_18692:
    goto v_18688;
v_18689:
    goto v_18690;
v_18691:
    if (v_18814 == v_18813) goto v_18686;
    else goto v_18687;
v_18686:
    goto v_18699;
v_18695:
    v_18814 = v_18815;
    goto v_18696;
v_18697:
    v_18813 = elt(env, 13); // geq
    goto v_18698;
v_18699:
    goto v_18695;
v_18696:
    goto v_18697;
v_18698:
    v_18813 = (v_18814 == v_18813 ? lisp_true : nil);
    goto v_18685;
v_18687:
    v_18813 = nil;
    goto v_18685;
    v_18813 = nil;
v_18685:
    if (v_18813 == nil) goto v_18683;
    v_18813 = elt(env, 1); // true
    goto v_18447;
v_18683:
    goto v_18719;
v_18715:
    v_18814 = v_18816;
    goto v_18716;
v_18717:
    v_18813 = elt(env, 11); // nsdef
    goto v_18718;
v_18719:
    goto v_18715;
v_18716:
    goto v_18717;
v_18718:
    if (v_18814 == v_18813) goto v_18713;
    else goto v_18714;
v_18713:
    goto v_18726;
v_18722:
    v_18814 = v_18815;
    goto v_18723;
v_18724:
    v_18813 = elt(env, 14); // leq
    goto v_18725;
v_18726:
    goto v_18722;
v_18723:
    goto v_18724;
v_18725:
    v_18813 = (v_18814 == v_18813 ? lisp_true : nil);
    goto v_18712;
v_18714:
    v_18813 = nil;
    goto v_18712;
    v_18813 = nil;
v_18712:
    if (v_18813 == nil) goto v_18710;
    v_18813 = elt(env, 1); // true
    goto v_18447;
v_18710:
    goto v_18746;
v_18742:
    v_18814 = v_18816;
    goto v_18743;
v_18744:
    v_18813 = elt(env, 9); // psdef
    goto v_18745;
v_18746:
    goto v_18742;
v_18743:
    goto v_18744;
v_18745:
    if (v_18814 == v_18813) goto v_18740;
    else goto v_18741;
v_18740:
    goto v_18753;
v_18749:
    v_18814 = v_18815;
    goto v_18750;
v_18751:
    v_18813 = elt(env, 15); // neq
    goto v_18752;
v_18753:
    goto v_18749;
v_18750:
    goto v_18751;
v_18752:
    v_18813 = (v_18814 == v_18813 ? lisp_true : nil);
    goto v_18739;
v_18741:
    v_18813 = nil;
    goto v_18739;
    v_18813 = nil;
v_18739:
    if (v_18813 == nil) goto v_18737;
    goto v_18767;
v_18761:
    v_18815 = elt(env, 12); // greaterp
    goto v_18762;
v_18763:
    v_18813 = stack[0];
    v_18813 = qcdr(v_18813);
    v_18814 = qcar(v_18813);
    goto v_18764;
v_18765:
    v_18813 = nil;
    goto v_18766;
v_18767:
    goto v_18761;
v_18762:
    goto v_18763;
v_18764:
    goto v_18765;
v_18766:
    return list3(v_18815, v_18814, v_18813);
v_18737:
    goto v_18785;
v_18781:
    v_18814 = v_18816;
    goto v_18782;
v_18783:
    v_18813 = elt(env, 11); // nsdef
    goto v_18784;
v_18785:
    goto v_18781;
v_18782:
    goto v_18783;
v_18784:
    if (v_18814 == v_18813) goto v_18779;
    else goto v_18780;
v_18779:
    goto v_18792;
v_18788:
    v_18814 = v_18815;
    goto v_18789;
v_18790:
    v_18813 = elt(env, 15); // neq
    goto v_18791;
v_18792:
    goto v_18788;
v_18789:
    goto v_18790;
v_18791:
    v_18813 = (v_18814 == v_18813 ? lisp_true : nil);
    goto v_18778;
v_18780:
    v_18813 = nil;
    goto v_18778;
    v_18813 = nil;
v_18778:
    if (v_18813 == nil) goto v_18776;
    goto v_18806;
v_18800:
    v_18815 = elt(env, 10); // lessp
    goto v_18801;
v_18802:
    v_18813 = stack[0];
    v_18813 = qcdr(v_18813);
    v_18814 = qcar(v_18813);
    goto v_18803;
v_18804:
    v_18813 = nil;
    goto v_18805;
v_18806:
    goto v_18800;
v_18801:
    goto v_18802;
v_18803:
    goto v_18804;
v_18805:
    return list3(v_18815, v_18814, v_18813);
v_18776:
    v_18813 = stack[0];
v_18447:
    return onevalue(v_18813);
}



// Code for sfto_vardeg

static LispObject CC_sfto_vardeg(LispObject env,
                         LispObject v_18442, LispObject v_18443)
{
    env = qenv(env);
    LispObject v_18468, v_18469;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18442,v_18443);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18468 = v_18443;
    stack[0] = v_18442;
// end of prologue
    goto v_18454;
v_18450:
    v_18469 = stack[0];
    goto v_18451;
v_18452:
    goto v_18453;
v_18454:
    goto v_18450;
v_18451:
    goto v_18452;
v_18453:
    fn = elt(env, 1); // sfto_mvartest
    v_18468 = (*qfn2(fn))(fn, v_18469, v_18468);
    if (v_18468 == nil) goto v_18448;
    v_18468 = stack[0];
    v_18468 = qcar(v_18468);
    v_18468 = qcar(v_18468);
    v_18468 = qcdr(v_18468);
    goto v_18446;
v_18448:
    v_18468 = stack[0];
    if (v_18468 == nil) goto v_18461;
    else goto v_18462;
v_18461:
    v_18468 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_18446;
v_18462:
    v_18468 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18446;
    v_18468 = nil;
v_18446:
    return onevalue(v_18468);
}



// Code for ev_revgradlexcomp

static LispObject CC_ev_revgradlexcomp(LispObject env,
                         LispObject v_18442, LispObject v_18443)
{
    env = qenv(env);
    LispObject v_18516, v_18517;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18442,v_18443);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_18443;
    stack[-2] = v_18442;
// end of prologue
v_18441:
    v_18516 = stack[-2];
    if (v_18516 == nil) goto v_18451;
    else goto v_18452;
v_18451:
    v_18516 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18448;
v_18452:
    goto v_18464;
v_18460:
    v_18516 = stack[-2];
    v_18517 = qcar(v_18516);
    goto v_18461;
v_18462:
    v_18516 = stack[-1];
    v_18516 = qcar(v_18516);
    goto v_18463;
v_18464:
    goto v_18460;
v_18461:
    goto v_18462;
v_18463:
    fn = elt(env, 1); // iequal
    v_18516 = (*qfn2(fn))(fn, v_18517, v_18516);
    env = stack[-4];
    if (v_18516 == nil) goto v_18458;
    goto v_18474;
v_18470:
    v_18516 = stack[-2];
    v_18517 = qcdr(v_18516);
    goto v_18471;
v_18472:
    v_18516 = stack[-1];
    v_18516 = qcdr(v_18516);
    goto v_18473;
v_18474:
    goto v_18470;
v_18471:
    goto v_18472;
v_18473:
    stack[-2] = v_18517;
    stack[-1] = v_18516;
    goto v_18441;
v_18458:
    v_18516 = stack[-2];
    fn = elt(env, 2); // ev_tdeg
    v_18516 = (*qfn1(fn))(fn, v_18516);
    env = stack[-4];
    stack[-3] = v_18516;
    v_18516 = stack[-1];
    fn = elt(env, 2); // ev_tdeg
    v_18516 = (*qfn1(fn))(fn, v_18516);
    env = stack[-4];
    stack[0] = v_18516;
    goto v_18492;
v_18488:
    v_18517 = stack[-3];
    goto v_18489;
v_18490:
    v_18516 = stack[0];
    goto v_18491;
v_18492:
    goto v_18488;
v_18489:
    goto v_18490;
v_18491:
    fn = elt(env, 1); // iequal
    v_18516 = (*qfn2(fn))(fn, v_18517, v_18516);
    env = stack[-4];
    if (v_18516 == nil) goto v_18486;
    goto v_18500;
v_18496:
    v_18517 = stack[-2];
    goto v_18497;
v_18498:
    v_18516 = stack[-1];
    goto v_18499;
v_18500:
    goto v_18496;
v_18497:
    goto v_18498;
v_18499:
    {
        fn = elt(env, 3); // ev_invlexcomp
        return (*qfn2(fn))(fn, v_18517, v_18516);
    }
v_18486:
    goto v_18511;
v_18507:
    v_18517 = stack[-3];
    goto v_18508;
v_18509:
    v_18516 = stack[0];
    goto v_18510;
v_18511:
    goto v_18507;
v_18508:
    goto v_18509;
v_18510:
    if (((intptr_t)(v_18517)) > ((intptr_t)(v_18516))) goto v_18505;
    else goto v_18506;
v_18505:
    v_18516 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18448;
v_18506:
    v_18516 = (LispObject)-16+TAG_FIXNUM; // -1
v_18448:
    return onevalue(v_18516);
}



// Code for minusml

static LispObject CC_minusml(LispObject env,
                         LispObject v_18442)
{
    env = qenv(env);
    LispObject v_18457;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18442);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18442;
// end of prologue
    v_18457 = elt(env, 1); // "<apply><minus/>"
    fn = elt(env, 3); // printout
    v_18457 = (*qfn1(fn))(fn, v_18457);
    env = stack[-1];
    v_18457 = lisp_true;
    fn = elt(env, 4); // indent!*
    v_18457 = (*qfn1(fn))(fn, v_18457);
    env = stack[-1];
    v_18457 = stack[0];
    v_18457 = qcdr(v_18457);
    fn = elt(env, 5); // multiminus
    v_18457 = (*qfn1(fn))(fn, v_18457);
    env = stack[-1];
    v_18457 = nil;
    fn = elt(env, 4); // indent!*
    v_18457 = (*qfn1(fn))(fn, v_18457);
    env = stack[-1];
    v_18457 = elt(env, 2); // "</apply>"
    fn = elt(env, 3); // printout
    v_18457 = (*qfn1(fn))(fn, v_18457);
    v_18457 = nil;
    return onevalue(v_18457);
}



// Code for f2dip11

static LispObject CC_f2dip11(LispObject env,
                         LispObject v_18442)
{
    env = qenv(env);
    LispObject v_18495, v_18496;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18442);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18442;
// end of prologue
v_18441:
    v_18495 = qvalue(elt(env, 1)); // !*notestparameters
    if (v_18495 == nil) goto v_18446;
    else goto v_18445;
v_18446:
    goto v_18456;
v_18452:
    v_18496 = stack[0];
    goto v_18453;
v_18454:
    v_18495 = qvalue(elt(env, 2)); // vdpvars!*
    goto v_18455;
v_18456:
    goto v_18452;
v_18453:
    goto v_18454;
v_18455:
    v_18495 = Lmember(nil, v_18496, v_18495);
    if (v_18495 == nil) goto v_18451;
    goto v_18466;
v_18462:
    v_18496 = stack[0];
    goto v_18463;
v_18464:
    v_18495 = elt(env, 3); // "occurs in a parameter and is member of the groebner variables."
    goto v_18465;
v_18466:
    goto v_18462;
v_18463:
    goto v_18464;
v_18465:
    v_18495 = list2(v_18496, v_18495);
    env = stack[-1];
    fn = elt(env, 6); // rederr
    v_18495 = (*qfn1(fn))(fn, v_18495);
    env = stack[-1];
    goto v_18449;
v_18451:
v_18449:
    v_18495 = stack[0];
    if (!consp(v_18495)) goto v_18471;
    else goto v_18472;
v_18471:
    goto v_18482;
v_18478:
    v_18496 = stack[0];
    goto v_18479;
v_18480:
    v_18495 = elt(env, 4); // list
    goto v_18481;
v_18482:
    goto v_18478;
v_18479:
    goto v_18480;
v_18481:
    if (v_18496 == v_18495) goto v_18476;
    else goto v_18477;
v_18476:
    v_18495 = elt(env, 5); // "groebner: LIST not allowed."
    {
        fn = elt(env, 6); // rederr
        return (*qfn1(fn))(fn, v_18495);
    }
v_18477:
    v_18495 = nil;
    goto v_18470;
v_18472:
    v_18495 = stack[0];
    v_18495 = qcar(v_18495);
    v_18495 = CC_f2dip11(elt(env, 0), v_18495);
    env = stack[-1];
    v_18495 = stack[0];
    v_18495 = qcdr(v_18495);
    stack[0] = v_18495;
    goto v_18441;
    v_18495 = nil;
v_18470:
v_18445:
    return onevalue(v_18495);
}



// Code for xriterion_1

static LispObject CC_xriterion_1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18623, v_18624, v_18625;
    LispObject fn;
    LispObject v_18444, v_18443, v_18442;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xriterion_1");
    va_start(aa, nargs);
    v_18442 = va_arg(aa, LispObject);
    v_18443 = va_arg(aa, LispObject);
    v_18444 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18444,v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18442,v_18443,v_18444);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_18444;
    stack[-1] = v_18443;
    stack[-2] = v_18442;
// end of prologue
v_18441:
    v_18623 = stack[-1];
    if (v_18623 == nil) goto v_18448;
    else goto v_18449;
v_18448:
    v_18623 = nil;
    goto v_18447;
v_18449:
    goto v_18458;
v_18454:
    v_18623 = stack[-2];
    v_18623 = qcdr(v_18623);
    v_18624 = qcar(v_18623);
    goto v_18455;
v_18456:
    v_18623 = elt(env, 1); // spoly_pair
    goto v_18457;
v_18458:
    goto v_18454;
v_18455:
    goto v_18456;
v_18457:
    if (v_18624 == v_18623) goto v_18453;
    v_18623 = nil;
    goto v_18447;
v_18453:
    v_18623 = stack[-1];
    v_18623 = qcar(v_18623);
    stack[-3] = v_18623;
    goto v_18480;
v_18476:
    v_18624 = stack[-3];
    goto v_18477;
v_18478:
    v_18623 = stack[-2];
    v_18623 = qcdr(v_18623);
    v_18623 = qcdr(v_18623);
    v_18623 = qcar(v_18623);
    goto v_18479;
v_18480:
    goto v_18476;
v_18477:
    goto v_18478;
v_18479:
    if (equal(v_18624, v_18623)) goto v_18475;
    goto v_18494;
v_18490:
    v_18624 = stack[-3];
    goto v_18491;
v_18492:
    v_18623 = stack[-2];
    v_18623 = qcdr(v_18623);
    v_18623 = qcdr(v_18623);
    v_18623 = qcdr(v_18623);
    v_18623 = qcar(v_18623);
    goto v_18493;
v_18494:
    goto v_18490;
v_18491:
    goto v_18492;
v_18493:
    if (equal(v_18624, v_18623)) goto v_18489;
    goto v_18510;
v_18506:
    v_18623 = stack[-3];
    fn = elt(env, 5); // xval
    v_18624 = (*qfn1(fn))(fn, v_18623);
    env = stack[-4];
    goto v_18507;
v_18508:
    v_18623 = stack[-2];
    v_18623 = qcar(v_18623);
    goto v_18509;
v_18510:
    goto v_18506;
v_18507:
    goto v_18508;
v_18509:
    fn = elt(env, 6); // xdiv
    v_18623 = (*qfn2(fn))(fn, v_18624, v_18623);
    env = stack[-4];
    if (v_18623 == nil) goto v_18503;
    else goto v_18504;
v_18503:
    v_18623 = nil;
    goto v_18502;
v_18504:
    goto v_18527;
v_18523:
    v_18624 = stack[-3];
    goto v_18524;
v_18525:
    v_18623 = stack[-2];
    v_18623 = qcdr(v_18623);
    v_18623 = qcdr(v_18623);
    v_18623 = qcar(v_18623);
    goto v_18526;
v_18527:
    goto v_18523;
v_18524:
    goto v_18525;
v_18526:
    fn = elt(env, 7); // make_spoly_pair
    v_18623 = (*qfn2(fn))(fn, v_18624, v_18623);
    env = stack[-4];
    v_18624 = v_18623;
    v_18623 = v_18624;
    if (v_18623 == nil) goto v_18536;
    else goto v_18537;
v_18536:
    v_18623 = lisp_true;
    goto v_18535;
v_18537:
    goto v_18547;
v_18543:
    goto v_18544;
v_18545:
    v_18623 = stack[0];
    goto v_18546;
v_18547:
    goto v_18543;
v_18544:
    goto v_18545;
v_18546:
    fn = elt(env, 8); // find_item
    v_18623 = (*qfn2(fn))(fn, v_18624, v_18623);
    env = stack[-4];
    v_18623 = (v_18623 == nil ? lisp_true : nil);
    goto v_18535;
    v_18623 = nil;
v_18535:
    if (v_18623 == nil) goto v_18520;
    else goto v_18521;
v_18520:
    v_18623 = nil;
    goto v_18519;
v_18521:
    goto v_18563;
v_18559:
    v_18624 = stack[-3];
    goto v_18560;
v_18561:
    v_18623 = stack[-2];
    v_18623 = qcdr(v_18623);
    v_18623 = qcdr(v_18623);
    v_18623 = qcdr(v_18623);
    v_18623 = qcar(v_18623);
    goto v_18562;
v_18563:
    goto v_18559;
v_18560:
    goto v_18561;
v_18562:
    fn = elt(env, 7); // make_spoly_pair
    v_18623 = (*qfn2(fn))(fn, v_18624, v_18623);
    env = stack[-4];
    v_18624 = v_18623;
    v_18623 = v_18624;
    if (v_18623 == nil) goto v_18573;
    else goto v_18574;
v_18573:
    v_18623 = lisp_true;
    goto v_18572;
v_18574:
    goto v_18584;
v_18580:
    goto v_18581;
v_18582:
    v_18623 = stack[0];
    goto v_18583;
v_18584:
    goto v_18580;
v_18581:
    goto v_18582;
v_18583:
    fn = elt(env, 8); // find_item
    v_18623 = (*qfn2(fn))(fn, v_18624, v_18623);
    env = stack[-4];
    v_18623 = (v_18623 == nil ? lisp_true : nil);
    goto v_18572;
    v_18623 = nil;
v_18572:
    if (v_18623 == nil) goto v_18556;
    else goto v_18557;
v_18556:
    v_18623 = nil;
    goto v_18555;
v_18557:
    v_18623 = qvalue(elt(env, 2)); // !*trxideal
    if (v_18623 == nil) goto v_18594;
    goto v_18601;
v_18597:
    v_18624 = elt(env, 3); // "criterion 1 hit"
    goto v_18598;
v_18599:
    v_18623 = elt(env, 4); // last
    goto v_18600;
v_18601:
    goto v_18597;
v_18598:
    goto v_18599;
v_18600:
    fn = elt(env, 9); // writepri
    v_18623 = (*qfn2(fn))(fn, v_18624, v_18623);
    env = stack[-4];
    goto v_18592;
v_18594:
v_18592:
    v_18623 = lisp_true;
    goto v_18555;
    v_18623 = nil;
v_18555:
    goto v_18519;
    v_18623 = nil;
v_18519:
    goto v_18502;
    v_18623 = nil;
v_18502:
    goto v_18487;
v_18489:
    v_18623 = nil;
    goto v_18487;
    v_18623 = nil;
v_18487:
    goto v_18473;
v_18475:
    v_18623 = nil;
    goto v_18473;
    v_18623 = nil;
v_18473:
    if (v_18623 == nil) goto v_18471;
    else goto v_18470;
v_18471:
    goto v_18618;
v_18612:
    v_18625 = stack[-2];
    goto v_18613;
v_18614:
    v_18623 = stack[-1];
    v_18624 = qcdr(v_18623);
    goto v_18615;
v_18616:
    v_18623 = stack[0];
    goto v_18617;
v_18618:
    goto v_18612;
v_18613:
    goto v_18614;
v_18615:
    goto v_18616;
v_18617:
    stack[-2] = v_18625;
    stack[-1] = v_18624;
    stack[0] = v_18623;
    goto v_18441;
v_18470:
    goto v_18447;
    v_18623 = nil;
v_18447:
    return onevalue(v_18623);
}



// Code for eqexpr

static LispObject CC_eqexpr(LispObject env,
                         LispObject v_18442)
{
    env = qenv(env);
    LispObject v_18483, v_18484, v_18485;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18442);
    }
// copy arguments values to proper place
    v_18485 = v_18442;
// end of prologue
    v_18483 = v_18485;
    if (!consp(v_18483)) goto v_18447;
    goto v_18458;
v_18454:
    v_18483 = v_18485;
    v_18484 = qcar(v_18483);
    goto v_18455;
v_18456:
    v_18483 = elt(env, 1); // equalopr
    goto v_18457;
v_18458:
    goto v_18454;
v_18455:
    goto v_18456;
v_18457:
    v_18483 = Lflagp(nil, v_18484, v_18483);
    if (v_18483 == nil) goto v_18452;
    v_18483 = v_18485;
    v_18483 = qcdr(v_18483);
    v_18483 = qcdr(v_18483);
    if (v_18483 == nil) goto v_18464;
    else goto v_18465;
v_18464:
    v_18483 = nil;
    goto v_18463;
v_18465:
    v_18483 = v_18485;
    v_18483 = qcdr(v_18483);
    v_18483 = qcdr(v_18483);
    v_18483 = qcdr(v_18483);
    v_18483 = (v_18483 == nil ? lisp_true : nil);
    goto v_18463;
    v_18483 = nil;
v_18463:
    goto v_18450;
v_18452:
    v_18483 = nil;
    goto v_18450;
    v_18483 = nil;
v_18450:
    goto v_18445;
v_18447:
    v_18483 = nil;
    goto v_18445;
    v_18483 = nil;
v_18445:
    return onevalue(v_18483);
}



// Code for comb

static LispObject CC_comb(LispObject env,
                         LispObject v_18442, LispObject v_18443)
{
    env = qenv(env);
    LispObject v_18552, v_18553, v_18554;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18442,v_18443);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_18443;
    stack[-4] = v_18442;
// end of prologue
    stack[-5] = nil;
    goto v_18459;
v_18455:
    v_18553 = stack[-3];
    goto v_18456;
v_18457:
    v_18552 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18458;
v_18459:
    goto v_18455;
v_18456:
    goto v_18457;
v_18458:
    if (v_18553 == v_18552) goto v_18453;
    else goto v_18454;
v_18453:
    v_18552 = nil;
    return ncons(v_18552);
v_18454:
    goto v_18471;
v_18467:
    goto v_18477;
v_18473:
    v_18552 = stack[-4];
    v_18553 = Llength(nil, v_18552);
    env = stack[-6];
    goto v_18474;
v_18475:
    v_18552 = stack[-3];
    goto v_18476;
v_18477:
    goto v_18473;
v_18474:
    goto v_18475;
v_18476:
    v_18553 = difference2(v_18553, v_18552);
    env = stack[-6];
    stack[-2] = v_18553;
    goto v_18468;
v_18469:
    v_18552 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18470;
v_18471:
    goto v_18467;
v_18468:
    goto v_18469;
v_18470:
    v_18552 = (LispObject)lessp2(v_18553, v_18552);
    v_18552 = v_18552 ? lisp_true : nil;
    env = stack[-6];
    if (v_18552 == nil) goto v_18465;
    v_18552 = nil;
    goto v_18449;
v_18465:
    v_18552 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_18552;
v_18486:
    goto v_18498;
v_18494:
    v_18553 = stack[-2];
    goto v_18495;
v_18496:
    v_18552 = stack[-1];
    goto v_18497;
v_18498:
    goto v_18494;
v_18495:
    goto v_18496;
v_18497:
    v_18552 = difference2(v_18553, v_18552);
    env = stack[-6];
    v_18552 = Lminusp(nil, v_18552);
    env = stack[-6];
    if (v_18552 == nil) goto v_18491;
    goto v_18485;
v_18491:
    goto v_18507;
v_18503:
    v_18552 = stack[-4];
    stack[0] = qcdr(v_18552);
    goto v_18504;
v_18505:
    v_18552 = stack[-3];
    v_18552 = sub1(v_18552);
    env = stack[-6];
    goto v_18506;
v_18507:
    goto v_18503;
v_18504:
    goto v_18505;
v_18506:
    v_18552 = CC_comb(elt(env, 0), stack[0], v_18552);
    env = stack[-6];
    stack[0] = v_18552;
v_18515:
    v_18552 = stack[0];
    if (v_18552 == nil) goto v_18519;
    else goto v_18520;
v_18519:
    goto v_18514;
v_18520:
    v_18552 = stack[0];
    v_18552 = qcar(v_18552);
    goto v_18533;
v_18527:
    v_18553 = stack[-4];
    v_18554 = qcar(v_18553);
    goto v_18528;
v_18529:
    v_18553 = v_18552;
    goto v_18530;
v_18531:
    v_18552 = stack[-5];
    goto v_18532;
v_18533:
    goto v_18527;
v_18528:
    goto v_18529;
v_18530:
    goto v_18531;
v_18532:
    v_18552 = acons(v_18554, v_18553, v_18552);
    env = stack[-6];
    stack[-5] = v_18552;
    v_18552 = stack[0];
    v_18552 = qcdr(v_18552);
    stack[0] = v_18552;
    goto v_18515;
v_18514:
    v_18552 = stack[-4];
    v_18552 = qcdr(v_18552);
    stack[-4] = v_18552;
    v_18552 = stack[-1];
    v_18552 = add1(v_18552);
    env = stack[-6];
    stack[-1] = v_18552;
    goto v_18486;
v_18485:
    goto v_18549;
v_18545:
    v_18553 = stack[-4];
    goto v_18546;
v_18547:
    v_18552 = stack[-5];
    goto v_18548;
v_18549:
    goto v_18545;
v_18546:
    goto v_18547;
v_18548:
    return cons(v_18553, v_18552);
v_18449:
    return onevalue(v_18552);
}



// Code for max!-degree

static LispObject CC_maxKdegree(LispObject env,
                         LispObject v_18442, LispObject v_18443)
{
    env = qenv(env);
    LispObject v_18508, v_18509, v_18510, v_18511;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18442,v_18443);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_18509 = v_18443;
    v_18510 = v_18442;
// end of prologue
v_18448:
    v_18508 = v_18510;
    if (!consp(v_18508)) goto v_18455;
    else goto v_18456;
v_18455:
    v_18508 = lisp_true;
    goto v_18454;
v_18456:
    v_18508 = v_18510;
    v_18508 = qcar(v_18508);
    v_18508 = (consp(v_18508) ? nil : lisp_true);
    goto v_18454;
    v_18508 = nil;
v_18454:
    if (v_18508 == nil) goto v_18452;
    v_18508 = v_18509;
    goto v_18447;
v_18452:
    goto v_18471;
v_18467:
    v_18511 = v_18509;
    goto v_18468;
v_18469:
    v_18508 = v_18510;
    v_18508 = qcar(v_18508);
    v_18508 = qcar(v_18508);
    v_18508 = qcdr(v_18508);
    goto v_18470;
v_18471:
    goto v_18467;
v_18468:
    goto v_18469;
v_18470:
    if (((intptr_t)(v_18511)) > ((intptr_t)(v_18508))) goto v_18465;
    else goto v_18466;
v_18465:
    v_18508 = v_18510;
    v_18508 = qcdr(v_18508);
    stack[0] = v_18508;
    goto v_18484;
v_18480:
    v_18508 = v_18510;
    v_18508 = qcar(v_18508);
    v_18508 = qcdr(v_18508);
    goto v_18481;
v_18482:
    goto v_18483;
v_18484:
    goto v_18480;
v_18481:
    goto v_18482;
v_18483:
    v_18508 = CC_maxKdegree(elt(env, 0), v_18508, v_18509);
    env = stack[-1];
    v_18509 = v_18508;
    v_18508 = stack[0];
    v_18510 = v_18508;
    goto v_18448;
v_18466:
    v_18508 = v_18510;
    v_18508 = qcdr(v_18508);
    stack[0] = v_18508;
    goto v_18499;
v_18495:
    v_18508 = v_18510;
    v_18508 = qcar(v_18508);
    v_18508 = qcdr(v_18508);
    goto v_18496;
v_18497:
    v_18509 = v_18510;
    v_18509 = qcar(v_18509);
    v_18509 = qcar(v_18509);
    v_18509 = qcdr(v_18509);
    goto v_18498;
v_18499:
    goto v_18495;
v_18496:
    goto v_18497;
v_18498:
    v_18508 = CC_maxKdegree(elt(env, 0), v_18508, v_18509);
    env = stack[-1];
    v_18509 = v_18508;
    v_18508 = stack[0];
    v_18510 = v_18508;
    goto v_18448;
    v_18508 = nil;
v_18447:
    return onevalue(v_18508);
}



// Code for chkrn!*

static LispObject CC_chkrnH(LispObject env,
                         LispObject v_18442)
{
    env = qenv(env);
    LispObject v_18454, v_18455;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18455 = v_18442;
// end of prologue
    v_18454 = qvalue(elt(env, 1)); // !*!*roundbf
    if (v_18454 == nil) goto v_18447;
    v_18454 = v_18455;
    goto v_18445;
v_18447:
    v_18454 = v_18455;
    {
        fn = elt(env, 2); // bf2flck
        return (*qfn1(fn))(fn, v_18454);
    }
    v_18454 = nil;
v_18445:
    return onevalue(v_18454);
}



// Code for length_multiindex

static LispObject CC_length_multiindex(LispObject env,
                         LispObject v_18442)
{
    env = qenv(env);
    LispObject v_18470, v_18471;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18442);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_18470 = v_18442;
// end of prologue
    stack[0] = v_18470;
    v_18470 = (LispObject)0+TAG_FIXNUM; // 0
    v_18471 = v_18470;
v_18448:
    v_18470 = stack[0];
    if (v_18470 == nil) goto v_18453;
    else goto v_18454;
v_18453:
    v_18470 = v_18471;
    goto v_18447;
v_18454:
    goto v_18462;
v_18458:
    v_18470 = stack[0];
    v_18470 = qcar(v_18470);
    goto v_18459;
v_18460:
    goto v_18461;
v_18462:
    goto v_18458;
v_18459:
    goto v_18460;
v_18461:
    v_18470 = plus2(v_18470, v_18471);
    env = stack[-1];
    v_18471 = v_18470;
    v_18470 = stack[0];
    v_18470 = qcdr(v_18470);
    stack[0] = v_18470;
    goto v_18448;
v_18447:
    return onevalue(v_18470);
}



// Code for sfto_fsub1

static LispObject CC_sfto_fsub1(LispObject env,
                         LispObject v_18442, LispObject v_18443)
{
    env = qenv(env);
    LispObject v_18624, v_18625;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18442,v_18443);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_18443;
    stack[-2] = v_18442;
// end of prologue
    v_18624 = stack[-2];
    if (!consp(v_18624)) goto v_18457;
    else goto v_18458;
v_18457:
    v_18624 = lisp_true;
    goto v_18456;
v_18458:
    v_18624 = stack[-2];
    v_18624 = qcar(v_18624);
    v_18624 = (consp(v_18624) ? nil : lisp_true);
    goto v_18456;
    v_18624 = nil;
v_18456:
    if (v_18624 == nil) goto v_18454;
    v_18624 = stack[-2];
    goto v_18450;
v_18454:
    v_18624 = stack[-2];
    v_18624 = qcar(v_18624);
    v_18624 = qcar(v_18624);
    v_18624 = qcar(v_18624);
    stack[0] = v_18624;
v_18473:
    v_18624 = stack[-1];
    if (v_18624 == nil) goto v_18476;
    goto v_18489;
v_18485:
    v_18624 = stack[-1];
    v_18624 = qcar(v_18624);
    v_18625 = qcar(v_18624);
    goto v_18486;
v_18487:
    v_18624 = stack[0];
    goto v_18488;
v_18489:
    goto v_18485;
v_18486:
    goto v_18487;
v_18488:
    if (equal(v_18625, v_18624)) goto v_18484;
    goto v_18499;
v_18495:
    v_18624 = stack[-1];
    v_18624 = qcar(v_18624);
    v_18625 = qcar(v_18624);
    goto v_18496;
v_18497:
    v_18624 = stack[0];
    goto v_18498;
v_18499:
    goto v_18495;
v_18496:
    goto v_18497;
v_18498:
    fn = elt(env, 1); // ordop
    v_18624 = (*qfn2(fn))(fn, v_18625, v_18624);
    env = stack[-4];
    goto v_18482;
v_18484:
    v_18624 = nil;
    goto v_18482;
    v_18624 = nil;
v_18482:
    if (v_18624 == nil) goto v_18476;
    goto v_18477;
v_18476:
    goto v_18472;
v_18477:
    v_18624 = stack[-1];
    v_18624 = qcdr(v_18624);
    stack[-1] = v_18624;
    goto v_18473;
v_18472:
    v_18624 = stack[-1];
    if (v_18624 == nil) goto v_18512;
    else goto v_18513;
v_18512:
    v_18624 = stack[-2];
    goto v_18450;
v_18513:
    goto v_18521;
v_18517:
    v_18624 = stack[-2];
    v_18625 = qcdr(v_18624);
    goto v_18518;
v_18519:
    v_18624 = stack[-1];
    goto v_18520;
v_18521:
    goto v_18517;
v_18518:
    goto v_18519;
v_18520:
    v_18624 = CC_sfto_fsub1(elt(env, 0), v_18625, v_18624);
    env = stack[-4];
    stack[-3] = v_18624;
    goto v_18533;
v_18529:
    v_18624 = stack[-1];
    v_18624 = qcar(v_18624);
    v_18625 = qcar(v_18624);
    goto v_18530;
v_18531:
    v_18624 = stack[0];
    goto v_18532;
v_18533:
    goto v_18529;
v_18530:
    goto v_18531;
v_18532:
    if (v_18625 == v_18624) goto v_18527;
    else goto v_18528;
v_18527:
    goto v_18543;
v_18539:
    v_18624 = stack[-2];
    v_18624 = qcar(v_18624);
    v_18625 = qcdr(v_18624);
    goto v_18540;
v_18541:
    v_18624 = stack[-1];
    v_18624 = qcdr(v_18624);
    goto v_18542;
v_18543:
    goto v_18539;
v_18540:
    goto v_18541;
v_18542:
    v_18624 = CC_sfto_fsub1(elt(env, 0), v_18625, v_18624);
    env = stack[-4];
    stack[0] = v_18624;
    goto v_18554;
v_18550:
    v_18624 = stack[-1];
    v_18624 = qcar(v_18624);
    v_18625 = qcdr(v_18624);
    goto v_18551;
v_18552:
    v_18624 = stack[-2];
    v_18624 = qcar(v_18624);
    v_18624 = qcar(v_18624);
    v_18624 = qcdr(v_18624);
    goto v_18553;
v_18554:
    goto v_18550;
v_18551:
    goto v_18552;
v_18553:
    fn = elt(env, 2); // exptf
    v_18624 = (*qfn2(fn))(fn, v_18625, v_18624);
    env = stack[-4];
    goto v_18567;
v_18563:
    goto v_18573;
v_18569:
    v_18625 = stack[0];
    goto v_18570;
v_18571:
    goto v_18572;
v_18573:
    goto v_18569;
v_18570:
    goto v_18571;
v_18572:
    fn = elt(env, 3); // multf
    v_18625 = (*qfn2(fn))(fn, v_18625, v_18624);
    env = stack[-4];
    goto v_18564;
v_18565:
    v_18624 = stack[-3];
    goto v_18566;
v_18567:
    goto v_18563;
v_18564:
    goto v_18565;
v_18566:
    {
        fn = elt(env, 4); // addf
        return (*qfn2(fn))(fn, v_18625, v_18624);
    }
v_18528:
    goto v_18582;
v_18578:
    v_18624 = stack[-2];
    v_18624 = qcar(v_18624);
    v_18625 = qcdr(v_18624);
    goto v_18579;
v_18580:
    v_18624 = stack[-1];
    goto v_18581;
v_18582:
    goto v_18578;
v_18579:
    goto v_18580;
v_18581:
    v_18624 = CC_sfto_fsub1(elt(env, 0), v_18625, v_18624);
    env = stack[-4];
    stack[0] = v_18624;
    goto v_18593;
v_18589:
    goto v_18599;
v_18595:
    v_18624 = stack[-2];
    v_18624 = qcar(v_18624);
    v_18624 = qcar(v_18624);
    v_18625 = qcar(v_18624);
    goto v_18596;
v_18597:
    v_18624 = stack[-2];
    v_18624 = qcar(v_18624);
    v_18624 = qcar(v_18624);
    v_18624 = qcdr(v_18624);
    goto v_18598;
v_18599:
    goto v_18595;
v_18596:
    goto v_18597;
v_18598:
    fn = elt(env, 5); // to
    v_18625 = (*qfn2(fn))(fn, v_18625, v_18624);
    env = stack[-4];
    goto v_18590;
v_18591:
    v_18624 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18592;
v_18593:
    goto v_18589;
v_18590:
    goto v_18591;
v_18592:
    v_18624 = cons(v_18625, v_18624);
    env = stack[-4];
    v_18624 = ncons(v_18624);
    env = stack[-4];
    goto v_18614;
v_18610:
    goto v_18620;
v_18616:
    v_18625 = stack[0];
    goto v_18617;
v_18618:
    goto v_18619;
v_18620:
    goto v_18616;
v_18617:
    goto v_18618;
v_18619:
    fn = elt(env, 3); // multf
    v_18625 = (*qfn2(fn))(fn, v_18625, v_18624);
    env = stack[-4];
    goto v_18611;
v_18612:
    v_18624 = stack[-3];
    goto v_18613;
v_18614:
    goto v_18610;
v_18611:
    goto v_18612;
v_18613:
    {
        fn = elt(env, 4); // addf
        return (*qfn2(fn))(fn, v_18625, v_18624);
    }
v_18450:
    return onevalue(v_18624);
}



// Code for ofsf_facequal!*

static LispObject CC_ofsf_facequalH(LispObject env,
                         LispObject v_18442, LispObject v_18443)
{
    env = qenv(env);
    LispObject v_18480, v_18481, v_18482;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18481 = v_18443;
    v_18482 = v_18442;
// end of prologue
    v_18480 = qvalue(elt(env, 1)); // !*rlsifac
    if (v_18480 == nil) goto v_18448;
    v_18480 = qvalue(elt(env, 2)); // !*rlsiexpla
    if (v_18480 == nil) goto v_18452;
    else goto v_18451;
v_18452:
    v_18480 = qvalue(elt(env, 3)); // !*rlsiexpl
    if (v_18480 == nil) goto v_18454;
    goto v_18462;
v_18458:
    goto v_18459;
v_18460:
    v_18480 = elt(env, 4); // or
    goto v_18461;
v_18462:
    goto v_18458;
v_18459:
    goto v_18460;
v_18461:
    if (v_18481 == v_18480) goto v_18457;
    else goto v_18454;
v_18457:
    goto v_18451;
v_18454:
    goto v_18448;
v_18451:
    v_18480 = v_18482;
    {
        fn = elt(env, 6); // ofsf_facequal
        return (*qfn1(fn))(fn, v_18480);
    }
v_18448:
    goto v_18476;
v_18470:
    v_18481 = elt(env, 5); // equal
    goto v_18471;
v_18472:
    goto v_18473;
v_18474:
    v_18480 = nil;
    goto v_18475;
v_18476:
    goto v_18470;
v_18471:
    goto v_18472;
v_18473:
    goto v_18474;
v_18475:
    return list3(v_18481, v_18482, v_18480);
    v_18480 = nil;
    return onevalue(v_18480);
}



// Code for talp_noffcts

static LispObject CC_talp_noffcts(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18479, v_18480;
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
    v_18479 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_18479;
    fn = elt(env, 1); // talp_getl
    v_18479 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[0] = v_18479;
v_18450:
    v_18479 = stack[0];
    if (v_18479 == nil) goto v_18454;
    else goto v_18455;
v_18454:
    goto v_18449;
v_18455:
    v_18479 = stack[0];
    v_18479 = qcar(v_18479);
    goto v_18470;
v_18466:
    v_18480 = qcdr(v_18479);
    goto v_18467;
v_18468:
    v_18479 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18469;
v_18470:
    goto v_18466;
v_18467:
    goto v_18468;
v_18469:
    v_18479 = (LispObject)greaterp2(v_18480, v_18479);
    v_18479 = v_18479 ? lisp_true : nil;
    env = stack[-2];
    if (v_18479 == nil) goto v_18464;
    v_18479 = stack[-1];
    v_18479 = add1(v_18479);
    env = stack[-2];
    stack[-1] = v_18479;
    goto v_18462;
v_18464:
v_18462:
    v_18479 = stack[0];
    v_18479 = qcdr(v_18479);
    stack[0] = v_18479;
    goto v_18450;
v_18449:
    v_18479 = stack[-1];
    return onevalue(v_18479);
}



// Code for pasf_susibinad

static LispObject CC_pasf_susibinad(LispObject env,
                         LispObject v_18442, LispObject v_18443)
{
    env = qenv(env);
    LispObject v_18724, v_18725, v_18726, v_18727, v_18728, v_18729, v_18730;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18442,v_18443);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_18443;
    stack[-4] = v_18442;
// end of prologue
    goto v_18458;
v_18454:
    v_18724 = stack[-4];
    v_18725 = qcdr(v_18724);
    goto v_18455;
v_18456:
    v_18724 = stack[-3];
    v_18724 = qcdr(v_18724);
    goto v_18457;
v_18458:
    goto v_18454;
v_18455:
    goto v_18456;
v_18457:
    fn = elt(env, 5); // cl_susiminlevel
    v_18724 = (*qfn2(fn))(fn, v_18725, v_18724);
    env = stack[-6];
    stack[-1] = v_18724;
    v_18724 = stack[-4];
    v_18724 = qcar(v_18724);
    stack[-4] = v_18724;
    v_18724 = stack[-3];
    v_18724 = qcar(v_18724);
    stack[-3] = v_18724;
    goto v_18477;
v_18473:
    v_18725 = stack[-3];
    goto v_18474;
v_18475:
    v_18724 = elt(env, 1); // false
    goto v_18476;
v_18477:
    goto v_18473;
v_18474:
    goto v_18475;
v_18476:
    if (v_18725 == v_18724) goto v_18471;
    else goto v_18472;
v_18471:
    v_18724 = elt(env, 1); // false
    goto v_18452;
v_18472:
    goto v_18489;
v_18485:
    v_18725 = stack[-3];
    goto v_18486;
v_18487:
    v_18724 = elt(env, 2); // true
    goto v_18488;
v_18489:
    goto v_18485;
v_18486:
    goto v_18487;
v_18488:
    if (v_18725 == v_18724) goto v_18483;
    else goto v_18484;
v_18483:
    v_18724 = elt(env, 3); // (delete . t)
    return ncons(v_18724);
v_18484:
    goto v_18502;
v_18498:
    v_18724 = stack[-4];
    v_18724 = qcdr(v_18724);
    v_18725 = qcar(v_18724);
    goto v_18499;
v_18500:
    v_18724 = stack[-3];
    v_18724 = qcdr(v_18724);
    v_18724 = qcar(v_18724);
    goto v_18501;
v_18502:
    goto v_18498;
v_18499:
    goto v_18500;
v_18501:
    if (equal(v_18725, v_18724)) goto v_18496;
    else goto v_18497;
v_18496:
    goto v_18518;
v_18510:
    v_18724 = stack[-4];
    v_18724 = qcdr(v_18724);
    v_18727 = qcar(v_18724);
    goto v_18511;
v_18512:
    v_18724 = stack[-4];
    v_18726 = qcar(v_18724);
    goto v_18513;
v_18514:
    v_18724 = stack[-3];
    v_18725 = qcar(v_18724);
    goto v_18515;
v_18516:
    v_18724 = stack[-1];
    goto v_18517;
v_18518:
    goto v_18510;
v_18511:
    goto v_18512;
v_18513:
    goto v_18514;
v_18515:
    goto v_18516;
v_18517:
    {
        fn = elt(env, 6); // pasf_susibineq
        return (*qfnn(fn))(fn, 4, v_18727, v_18726, v_18725, v_18724);
    }
v_18497:
    v_18724 = stack[-4];
    v_18724 = qcdr(v_18724);
    v_18724 = qcar(v_18724);
    fn = elt(env, 7); // pasf_dec
    v_18724 = (*qfn1(fn))(fn, v_18724);
    env = stack[-6];
    stack[-5] = v_18724;
    v_18724 = stack[-3];
    v_18724 = qcdr(v_18724);
    v_18724 = qcar(v_18724);
    fn = elt(env, 7); // pasf_dec
    v_18724 = (*qfn1(fn))(fn, v_18724);
    env = stack[-6];
    stack[-2] = v_18724;
    goto v_18543;
v_18539:
    v_18724 = stack[-5];
    v_18725 = qcar(v_18724);
    goto v_18540;
v_18541:
    v_18724 = stack[-2];
    v_18724 = qcar(v_18724);
    goto v_18542;
v_18543:
    goto v_18539;
v_18540:
    goto v_18541;
v_18542:
    if (equal(v_18725, v_18724)) goto v_18537;
    else goto v_18538;
v_18537:
    goto v_18563;
v_18549:
    v_18724 = stack[-4];
    v_18730 = qcar(v_18724);
    goto v_18550;
v_18551:
    v_18724 = stack[-5];
    v_18729 = qcar(v_18724);
    goto v_18552;
v_18553:
    v_18724 = stack[-5];
    v_18724 = qcdr(v_18724);
    if (v_18724 == nil) goto v_18571;
    v_18724 = stack[-5];
    v_18724 = qcdr(v_18724);
    v_18728 = v_18724;
    goto v_18569;
v_18571:
    v_18724 = (LispObject)0+TAG_FIXNUM; // 0
    v_18728 = v_18724;
    goto v_18569;
    v_18728 = nil;
v_18569:
    goto v_18554;
v_18555:
    v_18724 = stack[-3];
    v_18727 = qcar(v_18724);
    goto v_18556;
v_18557:
    v_18724 = stack[-2];
    v_18726 = qcar(v_18724);
    goto v_18558;
v_18559:
    v_18724 = stack[-2];
    v_18724 = qcdr(v_18724);
    if (v_18724 == nil) goto v_18586;
    v_18724 = stack[-2];
    v_18724 = qcdr(v_18724);
    v_18725 = v_18724;
    goto v_18584;
v_18586:
    v_18724 = (LispObject)0+TAG_FIXNUM; // 0
    v_18725 = v_18724;
    goto v_18584;
    v_18725 = nil;
v_18584:
    goto v_18560;
v_18561:
    v_18724 = stack[-1];
    goto v_18562;
v_18563:
    goto v_18549;
v_18550:
    goto v_18551;
v_18552:
    goto v_18553;
v_18554:
    goto v_18555;
v_18556:
    goto v_18557;
v_18558:
    goto v_18559;
v_18560:
    goto v_18561;
v_18562:
    {
        fn = elt(env, 8); // pasf_susibinord
        return (*qfnn(fn))(fn, 7, v_18730, v_18729, v_18728, v_18727, v_18726, v_18725, v_18724);
    }
v_18538:
    v_18724 = stack[-5];
    v_18724 = qcar(v_18724);
    fn = elt(env, 9); // kernels
    v_18724 = (*qfn1(fn))(fn, v_18724);
    env = stack[-6];
    stack[0] = v_18724;
    v_18724 = stack[-2];
    v_18724 = qcar(v_18724);
    fn = elt(env, 9); // kernels
    v_18724 = (*qfn1(fn))(fn, v_18724);
    env = stack[-6];
    v_18726 = v_18724;
    goto v_18613;
v_18609:
    v_18724 = stack[-4];
    v_18725 = qcar(v_18724);
    goto v_18610;
v_18611:
    v_18724 = elt(env, 4); // equal
    goto v_18612;
v_18613:
    goto v_18609;
v_18610:
    goto v_18611;
v_18612:
    if (v_18725 == v_18724) goto v_18607;
    else goto v_18608;
v_18607:
    v_18724 = stack[0];
    v_18724 = qcdr(v_18724);
    if (v_18724 == nil) goto v_18619;
    else goto v_18620;
v_18619:
    goto v_18627;
v_18623:
    v_18724 = stack[0];
    v_18725 = qcar(v_18724);
    goto v_18624;
v_18625:
    v_18724 = v_18726;
    goto v_18626;
v_18627:
    goto v_18623;
v_18624:
    goto v_18625;
v_18626:
    v_18724 = Lmemq(nil, v_18725, v_18724);
    goto v_18618;
v_18620:
    v_18724 = nil;
    goto v_18618;
    v_18724 = nil;
v_18618:
    goto v_18606;
v_18608:
    v_18724 = nil;
    goto v_18606;
    v_18724 = nil;
v_18606:
    if (v_18724 == nil) goto v_18604;
    goto v_18645;
v_18639:
    goto v_18653;
v_18647:
    stack[-2] = stack[-3];
    goto v_18648;
v_18649:
    v_18724 = stack[0];
    stack[0] = qcar(v_18724);
    goto v_18650;
v_18651:
    v_18724 = stack[-5];
    v_18724 = qcdr(v_18724);
    fn = elt(env, 10); // negf
    v_18724 = (*qfn1(fn))(fn, v_18724);
    env = stack[-6];
    goto v_18652;
v_18653:
    goto v_18647;
v_18648:
    goto v_18649;
v_18650:
    goto v_18651;
v_18652:
    fn = elt(env, 11); // pasf_subfof1
    v_18726 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_18724);
    env = stack[-6];
    goto v_18640;
v_18641:
    v_18725 = stack[-1];
    goto v_18642;
v_18643:
    v_18724 = lisp_true;
    goto v_18644;
v_18645:
    goto v_18639;
v_18640:
    goto v_18641;
v_18642:
    goto v_18643;
v_18644:
    {
        fn = elt(env, 12); // pasf_susibinad1
        return (*qfnn(fn))(fn, 3, v_18726, v_18725, v_18724);
    }
v_18604:
    goto v_18674;
v_18670:
    v_18724 = stack[-3];
    v_18725 = qcar(v_18724);
    goto v_18671;
v_18672:
    v_18724 = elt(env, 4); // equal
    goto v_18673;
v_18674:
    goto v_18670;
v_18671:
    goto v_18672;
v_18673:
    if (v_18725 == v_18724) goto v_18668;
    else goto v_18669;
v_18668:
    v_18724 = v_18726;
    v_18724 = qcdr(v_18724);
    if (v_18724 == nil) goto v_18680;
    else goto v_18681;
v_18680:
    goto v_18688;
v_18684:
    v_18724 = v_18726;
    v_18725 = qcar(v_18724);
    goto v_18685;
v_18686:
    v_18724 = stack[0];
    goto v_18687;
v_18688:
    goto v_18684;
v_18685:
    goto v_18686;
v_18687:
    v_18724 = Lmemq(nil, v_18725, v_18724);
    goto v_18679;
v_18681:
    v_18724 = nil;
    goto v_18679;
    v_18724 = nil;
v_18679:
    goto v_18667;
v_18669:
    v_18724 = nil;
    goto v_18667;
    v_18724 = nil;
v_18667:
    if (v_18724 == nil) goto v_18665;
    goto v_18706;
v_18700:
    goto v_18714;
v_18708:
    stack[-3] = stack[-4];
    goto v_18709;
v_18710:
    v_18724 = v_18726;
    stack[0] = qcar(v_18724);
    goto v_18711;
v_18712:
    v_18724 = stack[-2];
    v_18724 = qcdr(v_18724);
    fn = elt(env, 10); // negf
    v_18724 = (*qfn1(fn))(fn, v_18724);
    env = stack[-6];
    goto v_18713;
v_18714:
    goto v_18708;
v_18709:
    goto v_18710;
v_18711:
    goto v_18712;
v_18713:
    fn = elt(env, 11); // pasf_subfof1
    v_18726 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_18724);
    env = stack[-6];
    goto v_18701;
v_18702:
    v_18725 = stack[-1];
    goto v_18703;
v_18704:
    v_18724 = nil;
    goto v_18705;
v_18706:
    goto v_18700;
v_18701:
    goto v_18702;
v_18703:
    goto v_18704;
v_18705:
    {
        fn = elt(env, 12); // pasf_susibinad1
        return (*qfnn(fn))(fn, 3, v_18726, v_18725, v_18724);
    }
v_18665:
    v_18724 = nil;
v_18452:
    return onevalue(v_18724);
}



// Code for ev_sum

static LispObject CC_ev_sum(LispObject env,
                         LispObject v_18442, LispObject v_18443)
{
    env = qenv(env);
    LispObject v_18480, v_18481, v_18482;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18442,v_18443);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18443;
    stack[-1] = v_18442;
// end of prologue
    v_18482 = nil;
v_18450:
    v_18480 = stack[-1];
    if (v_18480 == nil) goto v_18453;
    else goto v_18454;
v_18453:
    goto v_18449;
v_18454:
    goto v_18462;
v_18458:
    goto v_18467;
v_18463:
    v_18480 = stack[-1];
    v_18481 = qcar(v_18480);
    goto v_18464;
v_18465:
    v_18480 = stack[0];
    v_18480 = qcar(v_18480);
    goto v_18466;
v_18467:
    goto v_18463;
v_18464:
    goto v_18465;
v_18466:
    v_18480 = (LispObject)(intptr_t)((intptr_t)v_18481 + (intptr_t)v_18480 - TAG_FIXNUM);
    goto v_18459;
v_18460:
    v_18481 = v_18482;
    goto v_18461;
v_18462:
    goto v_18458;
v_18459:
    goto v_18460;
v_18461:
    v_18480 = cons(v_18480, v_18481);
    env = stack[-2];
    v_18482 = v_18480;
    v_18480 = stack[-1];
    v_18480 = qcdr(v_18480);
    stack[-1] = v_18480;
    v_18480 = stack[0];
    v_18480 = qcdr(v_18480);
    stack[0] = v_18480;
    goto v_18450;
v_18449:
    v_18480 = v_18482;
        return Lnreverse(nil, v_18480);
    return onevalue(v_18480);
}



// Code for multiminus

static LispObject CC_multiminus(LispObject env,
                         LispObject v_18442)
{
    env = qenv(env);
    LispObject v_18465, v_18466;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18442);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18442;
// end of prologue
    v_18465 = stack[0];
    v_18465 = qcar(v_18465);
    fn = elt(env, 1); // expression
    v_18465 = (*qfn1(fn))(fn, v_18465);
    env = stack[-1];
    goto v_18457;
v_18453:
    v_18465 = stack[0];
    v_18466 = Llength(nil, v_18465);
    env = stack[-1];
    goto v_18454;
v_18455:
    v_18465 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_18456;
v_18457:
    goto v_18453;
v_18454:
    goto v_18455;
v_18456:
    if (v_18466 == v_18465) goto v_18451;
    else goto v_18452;
v_18451:
    v_18465 = stack[0];
    v_18465 = qcdr(v_18465);
    v_18465 = qcar(v_18465);
    fn = elt(env, 1); // expression
    v_18465 = (*qfn1(fn))(fn, v_18465);
    goto v_18450;
v_18452:
v_18450:
    v_18465 = nil;
    return onevalue(v_18465);
}



// Code for dm!-min

static LispObject CC_dmKmin(LispObject env,
                         LispObject v_18442, LispObject v_18443)
{
    env = qenv(env);
    LispObject v_18461, v_18462;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18442,v_18443);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18443;
    stack[-1] = v_18442;
// end of prologue
    goto v_18454;
v_18450:
    v_18462 = stack[-1];
    goto v_18451;
v_18452:
    v_18461 = stack[0];
    goto v_18453;
v_18454:
    goto v_18450;
v_18451:
    goto v_18452;
v_18453:
    fn = elt(env, 1); // dm!-gt
    v_18461 = (*qfn2(fn))(fn, v_18462, v_18461);
    if (v_18461 == nil) goto v_18448;
    v_18461 = stack[0];
    goto v_18446;
v_18448:
    v_18461 = stack[-1];
    goto v_18446;
    v_18461 = nil;
v_18446:
    return onevalue(v_18461);
}



// Code for !:dmtimeslst

static LispObject CC_Tdmtimeslst(LispObject env,
                         LispObject v_18442)
{
    env = qenv(env);
    LispObject v_18469, v_18470;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18442);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_18470 = v_18442;
// end of prologue
    v_18469 = v_18470;
    if (v_18469 == nil) goto v_18446;
    else goto v_18447;
v_18446:
    v_18469 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18445;
v_18447:
    v_18469 = v_18470;
    v_18469 = qcdr(v_18469);
    if (v_18469 == nil) goto v_18450;
    else goto v_18451;
v_18450:
    v_18469 = v_18470;
    v_18469 = qcar(v_18469);
    goto v_18445;
v_18451:
    goto v_18463;
v_18459:
    v_18469 = v_18470;
    stack[0] = qcar(v_18469);
    goto v_18460;
v_18461:
    v_18469 = v_18470;
    v_18469 = qcdr(v_18469);
    v_18469 = CC_Tdmtimeslst(elt(env, 0), v_18469);
    env = stack[-1];
    goto v_18462;
v_18463:
    goto v_18459;
v_18460:
    goto v_18461;
v_18462:
    {
        LispObject v_18472 = stack[0];
        fn = elt(env, 1); // !:times
        return (*qfn2(fn))(fn, v_18472, v_18469);
    }
    v_18469 = nil;
v_18445:
    return onevalue(v_18469);
}



// Code for sign!-of

static LispObject CC_signKof(LispObject env,
                         LispObject v_18442)
{
    env = qenv(env);
    LispObject v_18458, v_18459;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18442);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18458 = v_18442;
// end of prologue
    v_18458 = ncons(v_18458);
    env = stack[0];
    fn = elt(env, 1); // simp!-sign
    v_18458 = (*qfn1(fn))(fn, v_18458);
    v_18458 = qcar(v_18458);
    v_18459 = v_18458;
    v_18458 = v_18459;
    if (is_number(v_18458)) goto v_18452;
    v_18458 = nil;
    goto v_18450;
v_18452:
    v_18458 = v_18459;
    goto v_18450;
    v_18458 = nil;
v_18450:
    return onevalue(v_18458);
}



// Code for log_assignment

static LispObject CC_log_assignment(LispObject env,
                         LispObject v_18442, LispObject v_18443)
{
    env = qenv(env);
    LispObject v_18559, v_18560, v_18561;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18442,v_18443);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18443;
    v_18560 = v_18442;
// end of prologue
v_18447:
    v_18559 = stack[0];
    if (!consp(v_18559)) goto v_18454;
    else goto v_18455;
v_18454:
    v_18559 = lisp_true;
    goto v_18453;
v_18455:
    goto v_18469;
v_18465:
    v_18561 = stack[0];
    goto v_18466;
v_18467:
    v_18559 = elt(env, 1); // quote
    goto v_18468;
v_18469:
    goto v_18465;
v_18466:
    goto v_18467;
v_18468:
    if (!consp(v_18561)) goto v_18463;
    v_18561 = qcar(v_18561);
    if (v_18561 == v_18559) goto v_18462;
    else goto v_18463;
v_18462:
    v_18559 = lisp_true;
    goto v_18461;
v_18463:
    goto v_18480;
v_18476:
    v_18561 = stack[0];
    goto v_18477;
v_18478:
    v_18559 = elt(env, 2); // function
    goto v_18479;
v_18480:
    goto v_18476;
v_18477:
    goto v_18478;
v_18479:
    v_18559 = Leqcar(nil, v_18561, v_18559);
    env = stack[-1];
    goto v_18461;
    v_18559 = nil;
v_18461:
    goto v_18453;
    v_18559 = nil;
v_18453:
    if (v_18559 == nil) goto v_18451;
    v_18559 = nil;
    goto v_18446;
v_18451:
    goto v_18491;
v_18487:
    v_18561 = stack[0];
    goto v_18488;
v_18489:
    v_18559 = elt(env, 3); // setq
    goto v_18490;
v_18491:
    goto v_18487;
v_18488:
    goto v_18489;
v_18490:
    if (!consp(v_18561)) goto v_18485;
    v_18561 = qcar(v_18561);
    if (v_18561 == v_18559) goto v_18484;
    else goto v_18485;
v_18484:
    goto v_18502;
v_18498:
    v_18559 = stack[0];
    v_18559 = qcdr(v_18559);
    v_18561 = qcar(v_18559);
    goto v_18499;
v_18500:
    v_18559 = v_18560;
    goto v_18501;
v_18502:
    goto v_18498;
v_18499:
    goto v_18500;
v_18501:
    v_18559 = Lmember(nil, v_18561, v_18559);
    if (v_18559 == nil) goto v_18497;
    v_18559 = Lposn(nil, 0);
    env = stack[-1];
    v_18559 = (LispObject)zerop(v_18559);
    v_18559 = v_18559 ? lisp_true : nil;
    env = stack[-1];
    if (v_18559 == nil) goto v_18510;
    else goto v_18511;
v_18510:
    v_18559 = Lterpri(nil, 0);
    env = stack[-1];
    goto v_18509;
v_18511:
v_18509:
    v_18559 = elt(env, 4); // "+++ Assignment to parameter of inline: "
    v_18559 = Lprinc(nil, v_18559);
    env = stack[-1];
    v_18559 = stack[0];
    v_18559 = Lprint(nil, v_18559);
    env = stack[-1];
    v_18559 = elt(env, 5); // "+++ Macro was: "
    v_18559 = Lprinc(nil, v_18559);
    env = stack[-1];
    v_18559 = qvalue(elt(env, 6)); // inlineinfo
    v_18559 = Lprint(nil, v_18559);
    v_18559 = lisp_true;
    goto v_18446;
v_18497:
    v_18559 = stack[0];
    v_18559 = qcdr(v_18559);
    v_18559 = qcdr(v_18559);
    v_18559 = qcar(v_18559);
    stack[0] = v_18559;
    goto v_18447;
    goto v_18449;
v_18485:
    goto v_18537;
v_18533:
    v_18561 = stack[0];
    goto v_18534;
v_18535:
    v_18559 = elt(env, 7); // cond
    goto v_18536;
v_18537:
    goto v_18533;
v_18534:
    goto v_18535;
v_18536:
    if (!consp(v_18561)) goto v_18531;
    v_18561 = qcar(v_18561);
    if (v_18561 == v_18559) goto v_18530;
    else goto v_18531;
v_18530:
    goto v_18545;
v_18541:
    goto v_18542;
v_18543:
    v_18559 = stack[0];
    v_18559 = qcdr(v_18559);
    goto v_18544;
v_18545:
    goto v_18541;
v_18542:
    goto v_18543;
v_18544:
    {
        fn = elt(env, 8); // log_assignment_list_list
        return (*qfn2(fn))(fn, v_18560, v_18559);
    }
v_18531:
    goto v_18556;
v_18552:
    goto v_18553;
v_18554:
    v_18559 = stack[0];
    goto v_18555;
v_18556:
    goto v_18552;
v_18553:
    goto v_18554;
v_18555:
    {
        fn = elt(env, 9); // log_assignment_list
        return (*qfn2(fn))(fn, v_18560, v_18559);
    }
v_18449:
    v_18559 = nil;
v_18446:
    return onevalue(v_18559);
}



// Code for arglength

static LispObject CC_arglength(LispObject env,
                         LispObject v_18442)
{
    env = qenv(env);
    LispObject v_18468, v_18469;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18442);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_18469 = v_18442;
// end of prologue
// Binding !*intstr
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = nil; // !*intstr
    v_18468 = v_18469;
    if (v_18468 == nil) goto v_18450;
    else goto v_18451;
v_18450:
    v_18468 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18447;
v_18451:
    v_18468 = lisp_true;
    qvalue(elt(env, 1)) = v_18468; // !*intstr
    v_18468 = v_18469;
    fn = elt(env, 2); // reval
    v_18468 = (*qfn1(fn))(fn, v_18468);
    env = stack[-1];
    v_18469 = v_18468;
    v_18468 = v_18469;
    if (!consp(v_18468)) goto v_18459;
    else goto v_18460;
v_18459:
    v_18468 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_18458;
v_18460:
    v_18468 = v_18469;
    v_18468 = qcdr(v_18468);
    v_18468 = Llength(nil, v_18468);
    goto v_18458;
    v_18468 = nil;
v_18458:
v_18447:
    ;}  // end of a binding scope
    return onevalue(v_18468);
}



// Code for !*di2q

static LispObject CC_Hdi2q(LispObject env,
                         LispObject v_18443, LispObject v_18444)
{
    env = qenv(env);
    LispObject v_18521, v_18522, v_18523;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18444,v_18443);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18443,v_18444);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_18521 = v_18444;
    v_18522 = v_18443;
// end of prologue
// Binding varlist!*
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = v_18521; // varlist!*
    goto v_18455;
v_18451:
    v_18521 = v_18522;
    stack[-3] = v_18521;
    v_18521 = stack[-3];
    if (v_18521 == nil) goto v_18465;
    else goto v_18466;
v_18465:
    v_18521 = nil;
    v_18522 = v_18521;
    goto v_18460;
v_18466:
    v_18521 = stack[-3];
    v_18521 = qcar(v_18521);
    goto v_18480;
v_18474:
    v_18522 = v_18521;
    v_18523 = qcar(v_18522);
    goto v_18475;
v_18476:
    v_18522 = qcdr(v_18521);
    goto v_18477;
v_18478:
    v_18521 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18479;
v_18480:
    goto v_18474;
v_18475:
    goto v_18476;
v_18477:
    goto v_18478;
v_18479:
    v_18521 = list2star(v_18523, v_18522, v_18521);
    env = stack[-5];
    v_18521 = ncons(v_18521);
    env = stack[-5];
    stack[-1] = v_18521;
    stack[-2] = v_18521;
v_18461:
    v_18521 = stack[-3];
    v_18521 = qcdr(v_18521);
    stack[-3] = v_18521;
    v_18521 = stack[-3];
    if (v_18521 == nil) goto v_18490;
    else goto v_18491;
v_18490:
    v_18521 = stack[-2];
    v_18522 = v_18521;
    goto v_18460;
v_18491:
    goto v_18499;
v_18495:
    stack[0] = stack[-1];
    goto v_18496;
v_18497:
    v_18521 = stack[-3];
    v_18521 = qcar(v_18521);
    goto v_18512;
v_18506:
    v_18522 = v_18521;
    v_18523 = qcar(v_18522);
    goto v_18507;
v_18508:
    v_18522 = qcdr(v_18521);
    goto v_18509;
v_18510:
    v_18521 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18511;
v_18512:
    goto v_18506;
v_18507:
    goto v_18508;
v_18509:
    goto v_18510;
v_18511:
    v_18521 = list2star(v_18523, v_18522, v_18521);
    env = stack[-5];
    v_18521 = ncons(v_18521);
    env = stack[-5];
    goto v_18498;
v_18499:
    goto v_18495;
v_18496:
    goto v_18497;
v_18498:
    v_18521 = Lrplacd(nil, stack[0], v_18521);
    env = stack[-5];
    v_18521 = stack[-1];
    v_18521 = qcdr(v_18521);
    stack[-1] = v_18521;
    goto v_18461;
v_18460:
    goto v_18452;
v_18453:
    v_18521 = qvalue(elt(env, 1)); // varlist!*
    goto v_18454;
v_18455:
    goto v_18451;
v_18452:
    goto v_18453;
v_18454:
    fn = elt(env, 2); // !*di2q0
    v_18521 = (*qfn2(fn))(fn, v_18522, v_18521);
    ;}  // end of a binding scope
    return onevalue(v_18521);
}



// Code for ra_l

static LispObject CC_ra_l(LispObject env,
                         LispObject v_18442)
{
    env = qenv(env);
    LispObject v_18447;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18442);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18447 = v_18442;
// end of prologue
    fn = elt(env, 1); // ra_iv
    v_18447 = (*qfn1(fn))(fn, v_18447);
    env = stack[0];
    {
        fn = elt(env, 2); // riv_l
        return (*qfn1(fn))(fn, v_18447);
    }
}



// Code for lalr_extract_nonterminals

static LispObject CC_lalr_extract_nonterminals(LispObject env,
                         LispObject v_18442)
{
    env = qenv(env);
    LispObject v_18592, v_18593, v_18594;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18442);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_18442;
// end of prologue
    v_18594 = nil;
v_18447:
    v_18592 = stack[-1];
    if (v_18592 == nil) goto v_18450;
    else goto v_18451;
v_18450:
    v_18592 = v_18594;
    {
        fn = elt(env, 7); // nreverse
        return (*qfn1(fn))(fn, v_18592);
    }
v_18451:
    v_18592 = stack[-1];
    if (!consp(v_18592)) goto v_18455;
    else goto v_18456;
v_18455:
    goto v_18463;
v_18459:
    stack[0] = v_18594;
    goto v_18460;
v_18461:
    goto v_18473;
v_18467:
    v_18594 = elt(env, 1); // "Malformed production"
    goto v_18468;
v_18469:
    v_18593 = stack[-1];
    goto v_18470;
v_18471:
    v_18592 = elt(env, 2); // "(RHS should be a list of tokens, not a non-nil atom)"
    goto v_18472;
v_18473:
    goto v_18467;
v_18468:
    goto v_18469;
v_18470:
    goto v_18471;
v_18472:
    v_18592 = list3(v_18594, v_18593, v_18592);
    env = stack[-3];
    fn = elt(env, 8); // rederr
    v_18592 = (*qfn1(fn))(fn, v_18592);
    env = stack[-3];
    goto v_18462;
v_18463:
    goto v_18459;
v_18460:
    goto v_18461;
v_18462:
    {
        LispObject v_18598 = stack[0];
        fn = elt(env, 7); // nreverse
        return (*qfn2(fn))(fn, v_18598, v_18592);
    }
v_18456:
    v_18592 = stack[-1];
    v_18592 = qcar(v_18592);
    v_18592 = Lstringp(nil, v_18592);
    env = stack[-3];
    if (v_18592 == nil) goto v_18478;
    v_18592 = stack[-1];
    v_18592 = qcdr(v_18592);
    stack[-1] = v_18592;
    goto v_18447;
v_18478:
    v_18592 = stack[-1];
    v_18592 = qcar(v_18592);
    if (symbolp(v_18592)) goto v_18484;
    else goto v_18485;
v_18484:
    goto v_18497;
v_18493:
    v_18592 = stack[-1];
    v_18593 = qcar(v_18592);
    goto v_18494;
v_18495:
    v_18592 = elt(env, 3); // lex_fixed_code
    goto v_18496;
v_18497:
    goto v_18493;
v_18494:
    goto v_18495;
v_18496:
    v_18592 = get(v_18593, v_18592);
    env = stack[-3];
    if (v_18592 == nil) goto v_18491;
    v_18592 = stack[-1];
    v_18592 = qcdr(v_18592);
    stack[-1] = v_18592;
    goto v_18447;
v_18491:
    goto v_18510;
v_18506:
    v_18592 = stack[-1];
    v_18592 = qcar(v_18592);
    goto v_18507;
v_18508:
    v_18593 = v_18594;
    goto v_18509;
v_18510:
    goto v_18506;
v_18507:
    goto v_18508;
v_18509:
    v_18592 = cons(v_18592, v_18593);
    env = stack[-3];
    v_18594 = v_18592;
    v_18592 = stack[-1];
    v_18592 = qcdr(v_18592);
    stack[-1] = v_18592;
    goto v_18447;
    goto v_18449;
v_18485:
    v_18592 = stack[-1];
    v_18592 = qcar(v_18592);
    if (!consp(v_18592)) goto v_18516;
    else goto v_18517;
v_18516:
    goto v_18525;
v_18521:
    stack[0] = v_18594;
    goto v_18522;
v_18523:
    goto v_18535;
v_18529:
    v_18594 = elt(env, 1); // "Malformed production"
    goto v_18530;
v_18531:
    v_18593 = stack[-1];
    goto v_18532;
v_18533:
    v_18592 = elt(env, 4); // "(atomic item in token list should be symbol or string)"
    goto v_18534;
v_18535:
    goto v_18529;
v_18530:
    goto v_18531;
v_18532:
    goto v_18533;
v_18534:
    v_18592 = list3(v_18594, v_18593, v_18592);
    env = stack[-3];
    fn = elt(env, 8); // rederr
    v_18592 = (*qfn1(fn))(fn, v_18592);
    env = stack[-3];
    goto v_18524;
v_18525:
    goto v_18521;
v_18522:
    goto v_18523;
v_18524:
    {
        LispObject v_18599 = stack[0];
        fn = elt(env, 7); // nreverse
        return (*qfn2(fn))(fn, v_18599, v_18592);
    }
v_18517:
    goto v_18545;
v_18541:
    v_18592 = stack[-1];
    v_18592 = qcar(v_18592);
    v_18593 = qcar(v_18592);
    goto v_18542;
v_18543:
    v_18592 = elt(env, 5); // (opt seq star plus list listplus or)
    goto v_18544;
v_18545:
    goto v_18541;
v_18542:
    goto v_18543;
v_18544:
    v_18592 = Lmemq(nil, v_18593, v_18592);
    if (v_18592 == nil) goto v_18540;
    goto v_18556;
v_18552:
    stack[-2] = v_18594;
    goto v_18553;
v_18554:
    goto v_18563;
v_18559:
    v_18592 = stack[-1];
    v_18592 = qcar(v_18592);
    v_18592 = qcdr(v_18592);
    stack[0] = CC_lalr_extract_nonterminals(elt(env, 0), v_18592);
    env = stack[-3];
    goto v_18560;
v_18561:
    v_18592 = stack[-1];
    v_18592 = qcdr(v_18592);
    v_18592 = CC_lalr_extract_nonterminals(elt(env, 0), v_18592);
    env = stack[-3];
    goto v_18562;
v_18563:
    goto v_18559;
v_18560:
    goto v_18561;
v_18562:
    v_18592 = Lappend(nil, stack[0], v_18592);
    env = stack[-3];
    goto v_18555;
v_18556:
    goto v_18552;
v_18553:
    goto v_18554;
v_18555:
    {
        LispObject v_18600 = stack[-2];
        fn = elt(env, 7); // nreverse
        return (*qfn2(fn))(fn, v_18600, v_18592);
    }
v_18540:
    goto v_18578;
v_18574:
    stack[0] = v_18594;
    goto v_18575;
v_18576:
    goto v_18588;
v_18582:
    v_18594 = elt(env, 1); // "Malformed production"
    goto v_18583;
v_18584:
    v_18593 = stack[-1];
    goto v_18585;
v_18586:
    v_18592 = elt(env, 6); // "(unrecognised item in rule)"
    goto v_18587;
v_18588:
    goto v_18582;
v_18583:
    goto v_18584;
v_18585:
    goto v_18586;
v_18587:
    v_18592 = list3(v_18594, v_18593, v_18592);
    env = stack[-3];
    fn = elt(env, 8); // rederr
    v_18592 = (*qfn1(fn))(fn, v_18592);
    env = stack[-3];
    goto v_18577;
v_18578:
    goto v_18574;
v_18575:
    goto v_18576;
v_18577:
    {
        LispObject v_18601 = stack[0];
        fn = elt(env, 7); // nreverse
        return (*qfn2(fn))(fn, v_18601, v_18592);
    }
v_18449:
    v_18592 = nil;
    return onevalue(v_18592);
}



// Code for talp_atnum

static LispObject CC_talp_atnum(LispObject env,
                         LispObject v_18442)
{
    env = qenv(env);
    LispObject v_18628, v_18629, v_18630, v_18631;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18442);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_18630 = v_18442;
// end of prologue
v_18441:
    v_18628 = v_18630;
    if (!consp(v_18628)) goto v_18449;
    else goto v_18450;
v_18449:
    v_18628 = v_18630;
    goto v_18448;
v_18450:
    v_18628 = v_18630;
    v_18628 = qcar(v_18628);
    goto v_18448;
    v_18628 = nil;
v_18448:
    v_18631 = v_18628;
    goto v_18477;
v_18473:
    v_18629 = v_18631;
    goto v_18474;
v_18475:
    v_18628 = elt(env, 1); // or
    goto v_18476;
v_18477:
    goto v_18473;
v_18474:
    goto v_18475;
v_18476:
    if (v_18629 == v_18628) goto v_18471;
    else goto v_18472;
v_18471:
    v_18628 = lisp_true;
    goto v_18470;
v_18472:
    goto v_18487;
v_18483:
    v_18629 = v_18631;
    goto v_18484;
v_18485:
    v_18628 = elt(env, 2); // and
    goto v_18486;
v_18487:
    goto v_18483;
v_18484:
    goto v_18485;
v_18486:
    v_18628 = (v_18629 == v_18628 ? lisp_true : nil);
    goto v_18470;
    v_18628 = nil;
v_18470:
    if (v_18628 == nil) goto v_18468;
    v_18628 = lisp_true;
    goto v_18466;
v_18468:
    goto v_18498;
v_18494:
    v_18629 = v_18631;
    goto v_18495;
v_18496:
    v_18628 = elt(env, 3); // not
    goto v_18497;
v_18498:
    goto v_18494;
v_18495:
    goto v_18496;
v_18497:
    v_18628 = (v_18629 == v_18628 ? lisp_true : nil);
    goto v_18466;
    v_18628 = nil;
v_18466:
    if (v_18628 == nil) goto v_18464;
    v_18628 = lisp_true;
    goto v_18462;
v_18464:
    goto v_18513;
v_18509:
    v_18629 = v_18631;
    goto v_18510;
v_18511:
    v_18628 = elt(env, 4); // impl
    goto v_18512;
v_18513:
    goto v_18509;
v_18510:
    goto v_18511;
v_18512:
    if (v_18629 == v_18628) goto v_18507;
    else goto v_18508;
v_18507:
    v_18628 = lisp_true;
    goto v_18506;
v_18508:
    goto v_18527;
v_18523:
    v_18629 = v_18631;
    goto v_18524;
v_18525:
    v_18628 = elt(env, 5); // repl
    goto v_18526;
v_18527:
    goto v_18523;
v_18524:
    goto v_18525;
v_18526:
    if (v_18629 == v_18628) goto v_18521;
    else goto v_18522;
v_18521:
    v_18628 = lisp_true;
    goto v_18520;
v_18522:
    goto v_18537;
v_18533:
    v_18629 = v_18631;
    goto v_18534;
v_18535:
    v_18628 = elt(env, 6); // equiv
    goto v_18536;
v_18537:
    goto v_18533;
v_18534:
    goto v_18535;
v_18536:
    v_18628 = (v_18629 == v_18628 ? lisp_true : nil);
    goto v_18520;
    v_18628 = nil;
v_18520:
    goto v_18506;
    v_18628 = nil;
v_18506:
    goto v_18462;
    v_18628 = nil;
v_18462:
    if (v_18628 == nil) goto v_18460;
    v_18628 = v_18630;
    v_18628 = qcdr(v_18628);
    stack[-1] = v_18628;
    v_18628 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_18628;
v_18545:
    v_18628 = stack[-1];
    if (v_18628 == nil) goto v_18551;
    else goto v_18552;
v_18551:
    v_18628 = stack[0];
    goto v_18544;
v_18552:
    goto v_18560;
v_18556:
    v_18628 = stack[-1];
    v_18628 = qcar(v_18628);
    v_18629 = CC_talp_atnum(elt(env, 0), v_18628);
    env = stack[-2];
    goto v_18557;
v_18558:
    v_18628 = stack[0];
    goto v_18559;
v_18560:
    goto v_18556;
v_18557:
    goto v_18558;
v_18559:
    v_18628 = plus2(v_18629, v_18628);
    env = stack[-2];
    stack[0] = v_18628;
    v_18628 = stack[-1];
    v_18628 = qcdr(v_18628);
    stack[-1] = v_18628;
    goto v_18545;
v_18544:
    goto v_18446;
v_18460:
    goto v_18581;
v_18577:
    v_18629 = v_18631;
    goto v_18578;
v_18579:
    v_18628 = elt(env, 7); // ex
    goto v_18580;
v_18581:
    goto v_18577;
v_18578:
    goto v_18579;
v_18580:
    if (v_18629 == v_18628) goto v_18575;
    else goto v_18576;
v_18575:
    v_18628 = lisp_true;
    goto v_18574;
v_18576:
    goto v_18591;
v_18587:
    v_18629 = v_18631;
    goto v_18588;
v_18589:
    v_18628 = elt(env, 8); // all
    goto v_18590;
v_18591:
    goto v_18587;
v_18588:
    goto v_18589;
v_18590:
    v_18628 = (v_18629 == v_18628 ? lisp_true : nil);
    goto v_18574;
    v_18628 = nil;
v_18574:
    if (v_18628 == nil) goto v_18572;
    v_18628 = v_18630;
    v_18628 = qcdr(v_18628);
    v_18628 = qcdr(v_18628);
    v_18628 = qcar(v_18628);
    v_18630 = v_18628;
    goto v_18441;
v_18572:
    goto v_18612;
v_18608:
    v_18629 = v_18631;
    goto v_18609;
v_18610:
    v_18628 = elt(env, 9); // true
    goto v_18611;
v_18612:
    goto v_18608;
v_18609:
    goto v_18610;
v_18611:
    if (v_18629 == v_18628) goto v_18606;
    else goto v_18607;
v_18606:
    v_18628 = lisp_true;
    goto v_18605;
v_18607:
    goto v_18622;
v_18618:
    v_18628 = v_18631;
    goto v_18619;
v_18620:
    v_18629 = elt(env, 10); // false
    goto v_18621;
v_18622:
    goto v_18618;
v_18619:
    goto v_18620;
v_18621:
    v_18628 = (v_18628 == v_18629 ? lisp_true : nil);
    goto v_18605;
    v_18628 = nil;
v_18605:
    if (v_18628 == nil) goto v_18603;
    v_18628 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18446;
v_18603:
    v_18628 = (LispObject)16+TAG_FIXNUM; // 1
v_18446:
    return onevalue(v_18628);
}



// Code for pasf_sisub

static LispObject CC_pasf_sisub(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18893, v_18894, v_18895, v_18896, v_18897, v_18898;
    LispObject fn;
    LispObject v_18444, v_18443, v_18442;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pasf_sisub");
    va_start(aa, nargs);
    v_18442 = va_arg(aa, LispObject);
    v_18443 = va_arg(aa, LispObject);
    v_18444 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18444,v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18442,v_18443,v_18444);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_18444;
    stack[-5] = v_18443;
    stack[-1] = v_18442;
// end of prologue
    v_18893 = stack[-1];
    if (!consp(v_18893)) goto v_18451;
    else goto v_18452;
v_18451:
    v_18893 = stack[-1];
    goto v_18450;
v_18452:
    v_18893 = stack[-1];
    v_18893 = qcar(v_18893);
    goto v_18450;
    v_18893 = nil;
v_18450:
    stack[-6] = v_18893;
    goto v_18471;
v_18467:
    v_18894 = stack[-6];
    goto v_18468;
v_18469:
    v_18893 = elt(env, 1); // ex
    goto v_18470;
v_18471:
    goto v_18467;
v_18468:
    goto v_18469;
v_18470:
    if (v_18894 == v_18893) goto v_18465;
    else goto v_18466;
v_18465:
    v_18893 = lisp_true;
    goto v_18464;
v_18466:
    goto v_18481;
v_18477:
    v_18894 = stack[-6];
    goto v_18478;
v_18479:
    v_18893 = elt(env, 2); // all
    goto v_18480;
v_18481:
    goto v_18477;
v_18478:
    goto v_18479;
v_18480:
    v_18893 = (v_18894 == v_18893 ? lisp_true : nil);
    goto v_18464;
    v_18893 = nil;
v_18464:
    if (v_18893 == nil) goto v_18462;
    goto v_18492;
v_18486:
    stack[-2] = stack[-6];
    goto v_18487;
v_18488:
    v_18893 = stack[-1];
    v_18893 = qcdr(v_18893);
    stack[0] = qcar(v_18893);
    goto v_18489;
v_18490:
    goto v_18504;
v_18498:
    v_18893 = stack[-1];
    v_18893 = qcdr(v_18893);
    v_18893 = qcdr(v_18893);
    v_18895 = qcar(v_18893);
    goto v_18499;
v_18500:
    v_18894 = stack[-5];
    goto v_18501;
v_18502:
    v_18893 = stack[-4];
    goto v_18503;
v_18504:
    goto v_18498;
v_18499:
    goto v_18500;
v_18501:
    goto v_18502;
v_18503:
    v_18893 = CC_pasf_sisub(elt(env, 0), 3, v_18895, v_18894, v_18893);
    goto v_18491;
v_18492:
    goto v_18486;
v_18487:
    goto v_18488;
v_18489:
    goto v_18490;
v_18491:
    {
        LispObject v_18906 = stack[-2];
        LispObject v_18907 = stack[0];
        return list3(v_18906, v_18907, v_18893);
    }
v_18462:
    goto v_18523;
v_18519:
    v_18894 = stack[-6];
    goto v_18520;
v_18521:
    v_18893 = elt(env, 3); // bex
    goto v_18522;
v_18523:
    goto v_18519;
v_18520:
    goto v_18521;
v_18522:
    if (v_18894 == v_18893) goto v_18517;
    else goto v_18518;
v_18517:
    v_18893 = lisp_true;
    goto v_18516;
v_18518:
    goto v_18533;
v_18529:
    v_18894 = stack[-6];
    goto v_18530;
v_18531:
    v_18893 = elt(env, 4); // ball
    goto v_18532;
v_18533:
    goto v_18529;
v_18530:
    goto v_18531;
v_18532:
    v_18893 = (v_18894 == v_18893 ? lisp_true : nil);
    goto v_18516;
    v_18893 = nil;
v_18516:
    if (v_18893 == nil) goto v_18514;
    goto v_18546;
v_18538:
    stack[-3] = stack[-6];
    goto v_18539;
v_18540:
    v_18893 = stack[-1];
    v_18893 = qcdr(v_18893);
    stack[-2] = qcar(v_18893);
    goto v_18541;
v_18542:
    goto v_18558;
v_18552:
    v_18893 = stack[-1];
    v_18893 = qcdr(v_18893);
    v_18893 = qcdr(v_18893);
    v_18895 = qcar(v_18893);
    goto v_18553;
v_18554:
    v_18894 = stack[-5];
    goto v_18555;
v_18556:
    v_18893 = stack[-4];
    goto v_18557;
v_18558:
    goto v_18552;
v_18553:
    goto v_18554;
v_18555:
    goto v_18556;
v_18557:
    stack[0] = CC_pasf_sisub(elt(env, 0), 3, v_18895, v_18894, v_18893);
    env = stack[-7];
    goto v_18543;
v_18544:
    goto v_18572;
v_18566:
    v_18893 = stack[-1];
    v_18893 = qcdr(v_18893);
    v_18893 = qcdr(v_18893);
    v_18893 = qcdr(v_18893);
    v_18895 = qcar(v_18893);
    goto v_18567;
v_18568:
    v_18894 = stack[-5];
    goto v_18569;
v_18570:
    v_18893 = stack[-4];
    goto v_18571;
v_18572:
    goto v_18566;
v_18567:
    goto v_18568;
v_18569:
    goto v_18570;
v_18571:
    v_18893 = CC_pasf_sisub(elt(env, 0), 3, v_18895, v_18894, v_18893);
    goto v_18545;
v_18546:
    goto v_18538;
v_18539:
    goto v_18540;
v_18541:
    goto v_18542;
v_18543:
    goto v_18544;
v_18545:
    {
        LispObject v_18908 = stack[-3];
        LispObject v_18909 = stack[-2];
        LispObject v_18910 = stack[0];
        return list4(v_18908, v_18909, v_18910, v_18893);
    }
v_18514:
    goto v_18588;
v_18584:
    v_18894 = stack[-6];
    goto v_18585;
v_18586:
    v_18893 = elt(env, 5); // and
    goto v_18587;
v_18588:
    goto v_18584;
v_18585:
    goto v_18586;
v_18587:
    if (v_18894 == v_18893) goto v_18582;
    else goto v_18583;
v_18582:
    goto v_18604;
v_18592:
    v_18898 = elt(env, 5); // and
    goto v_18593;
v_18594:
    v_18893 = stack[-1];
    v_18897 = qcdr(v_18893);
    goto v_18595;
v_18596:
    v_18896 = stack[-5];
    goto v_18597;
v_18598:
    v_18895 = stack[-4];
    goto v_18599;
v_18600:
    v_18894 = elt(env, 6); // true
    goto v_18601;
v_18602:
    v_18893 = elt(env, 7); // false
    goto v_18603;
v_18604:
    goto v_18592;
v_18593:
    goto v_18594;
v_18595:
    goto v_18596;
v_18597:
    goto v_18598;
v_18599:
    goto v_18600;
v_18601:
    goto v_18602;
v_18603:
    {
        fn = elt(env, 13); // pasf_sisub!-gand
        return (*qfnn(fn))(fn, 6, v_18898, v_18897, v_18896, v_18895, v_18894, v_18893);
    }
v_18583:
    goto v_18620;
v_18616:
    v_18894 = stack[-6];
    goto v_18617;
v_18618:
    v_18893 = elt(env, 8); // or
    goto v_18619;
v_18620:
    goto v_18616;
v_18617:
    goto v_18618;
v_18619:
    if (v_18894 == v_18893) goto v_18614;
    else goto v_18615;
v_18614:
    goto v_18636;
v_18624:
    v_18898 = elt(env, 8); // or
    goto v_18625;
v_18626:
    v_18893 = stack[-1];
    v_18897 = qcdr(v_18893);
    goto v_18627;
v_18628:
    v_18896 = stack[-5];
    goto v_18629;
v_18630:
    v_18895 = stack[-4];
    goto v_18631;
v_18632:
    v_18894 = elt(env, 7); // false
    goto v_18633;
v_18634:
    v_18893 = elt(env, 6); // true
    goto v_18635;
v_18636:
    goto v_18624;
v_18625:
    goto v_18626;
v_18627:
    goto v_18628;
v_18629:
    goto v_18630;
v_18631:
    goto v_18632;
v_18633:
    goto v_18634;
v_18635:
    {
        fn = elt(env, 13); // pasf_sisub!-gand
        return (*qfnn(fn))(fn, 6, v_18898, v_18897, v_18896, v_18895, v_18894, v_18893);
    }
v_18615:
    goto v_18664;
v_18660:
    v_18894 = stack[-6];
    goto v_18661;
v_18662:
    v_18893 = elt(env, 8); // or
    goto v_18663;
v_18664:
    goto v_18660;
v_18661:
    goto v_18662;
v_18663:
    if (v_18894 == v_18893) goto v_18658;
    else goto v_18659;
v_18658:
    v_18893 = lisp_true;
    goto v_18657;
v_18659:
    goto v_18674;
v_18670:
    v_18894 = stack[-6];
    goto v_18671;
v_18672:
    v_18893 = elt(env, 5); // and
    goto v_18673;
v_18674:
    goto v_18670;
v_18671:
    goto v_18672;
v_18673:
    v_18893 = (v_18894 == v_18893 ? lisp_true : nil);
    goto v_18657;
    v_18893 = nil;
v_18657:
    if (v_18893 == nil) goto v_18655;
    v_18893 = lisp_true;
    goto v_18653;
v_18655:
    goto v_18685;
v_18681:
    v_18894 = stack[-6];
    goto v_18682;
v_18683:
    v_18893 = elt(env, 9); // not
    goto v_18684;
v_18685:
    goto v_18681;
v_18682:
    goto v_18683;
v_18684:
    v_18893 = (v_18894 == v_18893 ? lisp_true : nil);
    goto v_18653;
    v_18893 = nil;
v_18653:
    if (v_18893 == nil) goto v_18651;
    v_18893 = lisp_true;
    goto v_18649;
v_18651:
    goto v_18700;
v_18696:
    v_18894 = stack[-6];
    goto v_18697;
v_18698:
    v_18893 = elt(env, 10); // impl
    goto v_18699;
v_18700:
    goto v_18696;
v_18697:
    goto v_18698;
v_18699:
    if (v_18894 == v_18893) goto v_18694;
    else goto v_18695;
v_18694:
    v_18893 = lisp_true;
    goto v_18693;
v_18695:
    goto v_18714;
v_18710:
    v_18894 = stack[-6];
    goto v_18711;
v_18712:
    v_18893 = elt(env, 11); // repl
    goto v_18713;
v_18714:
    goto v_18710;
v_18711:
    goto v_18712;
v_18713:
    if (v_18894 == v_18893) goto v_18708;
    else goto v_18709;
v_18708:
    v_18893 = lisp_true;
    goto v_18707;
v_18709:
    goto v_18724;
v_18720:
    v_18894 = stack[-6];
    goto v_18721;
v_18722:
    v_18893 = elt(env, 12); // equiv
    goto v_18723;
v_18724:
    goto v_18720;
v_18721:
    goto v_18722;
v_18723:
    v_18893 = (v_18894 == v_18893 ? lisp_true : nil);
    goto v_18707;
    v_18893 = nil;
v_18707:
    goto v_18693;
    v_18893 = nil;
v_18693:
    goto v_18649;
    v_18893 = nil;
v_18649:
    if (v_18893 == nil) goto v_18647;
    v_18893 = stack[-1];
    v_18893 = qcdr(v_18893);
    stack[-3] = v_18893;
    v_18893 = stack[-3];
    if (v_18893 == nil) goto v_18738;
    else goto v_18739;
v_18738:
    v_18893 = nil;
    goto v_18732;
v_18739:
    v_18893 = stack[-3];
    v_18893 = qcar(v_18893);
    goto v_18753;
v_18747:
    v_18895 = v_18893;
    goto v_18748;
v_18749:
    v_18894 = stack[-5];
    goto v_18750;
v_18751:
    v_18893 = stack[-4];
    goto v_18752;
v_18753:
    goto v_18747;
v_18748:
    goto v_18749;
v_18750:
    goto v_18751;
v_18752:
    v_18893 = CC_pasf_sisub(elt(env, 0), 3, v_18895, v_18894, v_18893);
    env = stack[-7];
    v_18893 = ncons(v_18893);
    env = stack[-7];
    stack[-1] = v_18893;
    stack[-2] = v_18893;
v_18733:
    v_18893 = stack[-3];
    v_18893 = qcdr(v_18893);
    stack[-3] = v_18893;
    v_18893 = stack[-3];
    if (v_18893 == nil) goto v_18761;
    else goto v_18762;
v_18761:
    v_18893 = stack[-2];
    goto v_18732;
v_18762:
    goto v_18770;
v_18766:
    stack[0] = stack[-1];
    goto v_18767;
v_18768:
    v_18893 = stack[-3];
    v_18893 = qcar(v_18893);
    goto v_18783;
v_18777:
    v_18895 = v_18893;
    goto v_18778;
v_18779:
    v_18894 = stack[-5];
    goto v_18780;
v_18781:
    v_18893 = stack[-4];
    goto v_18782;
v_18783:
    goto v_18777;
v_18778:
    goto v_18779;
v_18780:
    goto v_18781;
v_18782:
    v_18893 = CC_pasf_sisub(elt(env, 0), 3, v_18895, v_18894, v_18893);
    env = stack[-7];
    v_18893 = ncons(v_18893);
    env = stack[-7];
    goto v_18769;
v_18770:
    goto v_18766;
v_18767:
    goto v_18768;
v_18769:
    v_18893 = Lrplacd(nil, stack[0], v_18893);
    env = stack[-7];
    v_18893 = stack[-1];
    v_18893 = qcdr(v_18893);
    stack[-1] = v_18893;
    goto v_18733;
v_18732:
    v_18894 = v_18893;
    v_18893 = v_18894;
    if (v_18893 == nil) goto v_18793;
    v_18893 = v_18894;
    v_18893 = qcdr(v_18893);
    if (v_18893 == nil) goto v_18793;
    goto v_18804;
v_18800:
    v_18893 = stack[-6];
    goto v_18801;
v_18802:
    goto v_18803;
v_18804:
    goto v_18800;
v_18801:
    goto v_18802;
v_18803:
    return cons(v_18893, v_18894);
v_18793:
    v_18893 = v_18894;
    if (v_18893 == nil) goto v_18807;
    else goto v_18808;
v_18807:
    goto v_18818;
v_18814:
    v_18894 = stack[-6];
    goto v_18815;
v_18816:
    v_18893 = elt(env, 5); // and
    goto v_18817;
v_18818:
    goto v_18814;
v_18815:
    goto v_18816;
v_18817:
    if (v_18894 == v_18893) goto v_18812;
    else goto v_18813;
v_18812:
    v_18893 = elt(env, 6); // true
    goto v_18811;
v_18813:
    v_18893 = elt(env, 7); // false
    goto v_18811;
    v_18893 = nil;
v_18811:
    goto v_18791;
v_18808:
    v_18893 = v_18894;
    v_18893 = qcar(v_18893);
    goto v_18791;
    v_18893 = nil;
v_18791:
    goto v_18448;
v_18647:
    goto v_18841;
v_18837:
    v_18894 = stack[-6];
    goto v_18838;
v_18839:
    v_18893 = elt(env, 6); // true
    goto v_18840;
v_18841:
    goto v_18837;
v_18838:
    goto v_18839;
v_18840:
    if (v_18894 == v_18893) goto v_18835;
    else goto v_18836;
v_18835:
    v_18893 = lisp_true;
    goto v_18834;
v_18836:
    goto v_18851;
v_18847:
    v_18894 = stack[-6];
    goto v_18848;
v_18849:
    v_18893 = elt(env, 7); // false
    goto v_18850;
v_18851:
    goto v_18847;
v_18848:
    goto v_18849;
v_18850:
    v_18893 = (v_18894 == v_18893 ? lisp_true : nil);
    goto v_18834;
    v_18893 = nil;
v_18834:
    if (v_18893 == nil) goto v_18832;
    v_18893 = stack[-1];
    goto v_18448;
v_18832:
    goto v_18861;
v_18857:
    goto v_18869;
v_18863:
    v_18893 = stack[-1];
    stack[0] = qcar(v_18893);
    goto v_18864;
v_18865:
    goto v_18877;
v_18873:
    v_18893 = stack[-1];
    v_18893 = qcdr(v_18893);
    stack[-1] = qcar(v_18893);
    goto v_18874;
v_18875:
    goto v_18887;
v_18883:
    v_18894 = stack[-5];
    goto v_18884;
v_18885:
    v_18893 = stack[-4];
    goto v_18886;
v_18887:
    goto v_18883;
v_18884:
    goto v_18885;
v_18886:
    v_18893 = cons(v_18894, v_18893);
    env = stack[-7];
    v_18893 = ncons(v_18893);
    env = stack[-7];
    goto v_18876;
v_18877:
    goto v_18873;
v_18874:
    goto v_18875;
v_18876:
    fn = elt(env, 14); // subf
    v_18893 = (*qfn2(fn))(fn, stack[-1], v_18893);
    env = stack[-7];
    v_18894 = qcar(v_18893);
    goto v_18866;
v_18867:
    v_18893 = nil;
    goto v_18868;
v_18869:
    goto v_18863;
v_18864:
    goto v_18865;
v_18866:
    goto v_18867;
v_18868:
    v_18894 = list3(stack[0], v_18894, v_18893);
    env = stack[-7];
    goto v_18858;
v_18859:
    v_18893 = stack[-6];
    goto v_18860;
v_18861:
    goto v_18857;
v_18858:
    goto v_18859;
v_18860:
    {
        fn = elt(env, 15); // pasf_simplat1
        return (*qfn2(fn))(fn, v_18894, v_18893);
    }
v_18448:
    return onevalue(v_18893);
}



// Code for innprodp2

static LispObject CC_innprodp2(LispObject env,
                         LispObject v_18442, LispObject v_18443)
{
    env = qenv(env);
    LispObject v_18487, v_18488, v_18489, v_18490;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18442,v_18443);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_18489 = v_18443;
    stack[0] = v_18442;
// end of prologue
    goto v_18452;
v_18448:
    v_18487 = nil;
    goto v_18449;
v_18450:
    v_18488 = v_18489;
    goto v_18451;
v_18452:
    goto v_18448;
v_18449:
    goto v_18450;
v_18451:
    v_18487 = cons(v_18487, v_18488);
    env = stack[-1];
    v_18489 = v_18487;
v_18457:
    v_18487 = stack[0];
    if (v_18487 == nil) goto v_18460;
    v_18487 = v_18489;
    if (v_18487 == nil) goto v_18460;
    goto v_18461;
v_18460:
    goto v_18456;
v_18461:
    goto v_18476;
v_18468:
    v_18490 = nil;
    goto v_18469;
v_18470:
    v_18487 = stack[0];
    v_18488 = qcar(v_18487);
    goto v_18471;
v_18472:
    v_18487 = v_18489;
    v_18487 = qcdr(v_18487);
    goto v_18473;
v_18474:
    v_18489 = qcar(v_18489);
    goto v_18475;
v_18476:
    goto v_18468;
v_18469:
    goto v_18470;
v_18471:
    goto v_18472;
v_18473:
    goto v_18474;
v_18475:
    fn = elt(env, 1); // innprodkp
    v_18487 = (*qfnn(fn))(fn, 4, v_18490, v_18488, v_18487, v_18489);
    env = stack[-1];
    v_18489 = v_18487;
    v_18487 = stack[0];
    v_18487 = qcdr(v_18487);
    stack[0] = v_18487;
    goto v_18457;
v_18456:
    v_18487 = v_18489;
    return onevalue(v_18487);
}



// Code for omatpir

static LispObject CC_omatpir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18468, v_18469, v_18470;
    LispObject fn;
    argcheck(nargs, 0, "omatpir");
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
    fn = elt(env, 2); // lex
    v_18468 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    fn = elt(env, 3); // omsir
    v_18468 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_18468 = qcar(v_18468);
    stack[-1] = v_18468;
    fn = elt(env, 2); // lex
    v_18468 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    fn = elt(env, 4); // omobj
    v_18468 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_18468 = qcar(v_18468);
    stack[0] = v_18468;
    fn = elt(env, 2); // lex
    v_18468 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_18468 = elt(env, 1); // (!/ o m a t p)
    fn = elt(env, 5); // checktag
    v_18468 = (*qfn1(fn))(fn, v_18468);
    env = stack[-2];
    goto v_18464;
v_18458:
    v_18470 = stack[-1];
    goto v_18459;
v_18460:
    v_18469 = stack[0];
    goto v_18461;
v_18462:
    v_18468 = nil;
    goto v_18463;
v_18464:
    goto v_18458;
v_18459:
    goto v_18460;
v_18461:
    goto v_18462;
v_18463:
    v_18468 = list2star(v_18470, v_18469, v_18468);
    return ncons(v_18468);
    return onevalue(v_18468);
}



// Code for mkempspmat

static LispObject CC_mkempspmat(LispObject env,
                         LispObject v_18442, LispObject v_18443)
{
    env = qenv(env);
    LispObject v_18461, v_18462;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18442,v_18443);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18443;
    v_18461 = v_18442;
// end of prologue
    goto v_18455;
v_18449:
    stack[-1] = elt(env, 1); // sparsemat
    goto v_18450;
v_18451:
    v_18462 = Lmkvect(nil, v_18461);
    goto v_18452;
v_18453:
    v_18461 = stack[0];
    goto v_18454;
v_18455:
    goto v_18449;
v_18450:
    goto v_18451;
v_18452:
    goto v_18453;
v_18454:
    {
        LispObject v_18465 = stack[-1];
        return list3(v_18465, v_18462, v_18461);
    }
    return onevalue(v_18461);
}



// Code for suchp

static LispObject CC_suchp(LispObject env,
                         LispObject v_18442)
{
    env = qenv(env);
    LispObject v_18461, v_18462;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18462 = v_18442;
// end of prologue
    v_18461 = v_18462;
    if (!consp(v_18461)) goto v_18447;
    goto v_18453;
v_18449:
    v_18461 = v_18462;
    v_18461 = qcar(v_18461);
    goto v_18450;
v_18451:
    v_18462 = elt(env, 1); // such!-that
    goto v_18452;
v_18453:
    goto v_18449;
v_18450:
    goto v_18451;
v_18452:
    v_18461 = (v_18461 == v_18462 ? lisp_true : nil);
    goto v_18445;
v_18447:
    v_18461 = nil;
    goto v_18445;
    v_18461 = nil;
v_18445:
    return onevalue(v_18461);
}



// Code for dipequal

static LispObject CC_dipequal(LispObject env,
                         LispObject v_18442, LispObject v_18443)
{
    env = qenv(env);
    LispObject v_18502, v_18503;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18442,v_18443);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18443;
    stack[-1] = v_18442;
// end of prologue
v_18447:
    v_18502 = stack[-1];
    if (v_18502 == nil) goto v_18450;
    else goto v_18451;
v_18450:
    v_18502 = stack[0];
    v_18502 = (v_18502 == nil ? lisp_true : nil);
    goto v_18446;
v_18451:
    v_18502 = stack[0];
    if (v_18502 == nil) goto v_18455;
    else goto v_18456;
v_18455:
    v_18502 = nil;
    goto v_18446;
v_18456:
    goto v_18469;
v_18465:
    v_18502 = stack[-1];
    v_18502 = qcdr(v_18502);
    v_18503 = qcar(v_18502);
    goto v_18466;
v_18467:
    v_18502 = stack[0];
    v_18502 = qcdr(v_18502);
    v_18502 = qcar(v_18502);
    goto v_18468;
v_18469:
    goto v_18465;
v_18466:
    goto v_18467;
v_18468:
    if (equal(v_18503, v_18502)) goto v_18463;
    else goto v_18464;
v_18463:
    goto v_18485;
v_18481:
    v_18502 = stack[-1];
    v_18503 = qcar(v_18502);
    goto v_18482;
v_18483:
    v_18502 = stack[0];
    v_18502 = qcar(v_18502);
    goto v_18484;
v_18485:
    goto v_18481;
v_18482:
    goto v_18483;
v_18484:
    fn = elt(env, 1); // evequal
    v_18502 = (*qfn2(fn))(fn, v_18503, v_18502);
    env = stack[-2];
    if (v_18502 == nil) goto v_18479;
    v_18502 = stack[-1];
    v_18502 = qcdr(v_18502);
    v_18502 = qcdr(v_18502);
    stack[-1] = v_18502;
    v_18502 = stack[0];
    v_18502 = qcdr(v_18502);
    v_18502 = qcdr(v_18502);
    stack[0] = v_18502;
    goto v_18447;
v_18479:
    v_18502 = nil;
    goto v_18446;
    goto v_18462;
v_18464:
    v_18502 = nil;
    goto v_18446;
v_18462:
    goto v_18449;
v_18449:
    v_18502 = nil;
v_18446:
    return onevalue(v_18502);
}



// Code for !*xadd

static LispObject CC_Hxadd(LispObject env,
                         LispObject v_18442, LispObject v_18443)
{
    env = qenv(env);
    LispObject v_18495, v_18496, v_18497, v_18498;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18442,v_18443);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18498 = v_18443;
    stack[0] = v_18442;
// end of prologue
    v_18495 = v_18498;
    v_18497 = v_18495;
v_18451:
    v_18495 = v_18497;
    if (v_18495 == nil) goto v_18454;
    goto v_18463;
v_18459:
    v_18495 = stack[0];
    v_18496 = qcar(v_18495);
    goto v_18460;
v_18461:
    v_18495 = v_18497;
    v_18495 = qcar(v_18495);
    v_18495 = qcar(v_18495);
    goto v_18462;
v_18463:
    goto v_18459;
v_18460:
    goto v_18461;
v_18462:
    if (equal(v_18496, v_18495)) goto v_18454;
    goto v_18455;
v_18454:
    goto v_18450;
v_18455:
    v_18495 = v_18497;
    v_18495 = qcdr(v_18495);
    v_18497 = v_18495;
    goto v_18451;
v_18450:
    v_18495 = v_18497;
    if (v_18495 == nil) goto v_18475;
    goto v_18482;
v_18478:
    v_18495 = v_18497;
    v_18495 = qcar(v_18495);
    goto v_18479;
v_18480:
    v_18496 = v_18498;
    goto v_18481;
v_18482:
    goto v_18478;
v_18479:
    goto v_18480;
v_18481:
    v_18495 = Ldelete(nil, v_18495, v_18496);
    v_18498 = v_18495;
    goto v_18473;
v_18475:
v_18473:
    goto v_18491;
v_18487:
    v_18495 = stack[0];
    goto v_18488;
v_18489:
    v_18496 = v_18498;
    goto v_18490;
v_18491:
    goto v_18487;
v_18488:
    goto v_18489;
v_18490:
    return cons(v_18495, v_18496);
    return onevalue(v_18495);
}



// Code for simp!-prop1

static LispObject CC_simpKprop1(LispObject env,
                         LispObject v_18442, LispObject v_18443)
{
    env = qenv(env);
    LispObject v_18940, v_18941, v_18942;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18442,v_18443);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_18443;
    stack[-4] = v_18442;
// end of prologue
v_18441:
    v_18940 = stack[-4];
    if (!consp(v_18940)) goto v_18452;
    else goto v_18453;
v_18452:
    goto v_18448;
v_18453:
    goto v_18468;
v_18464:
    v_18940 = stack[-4];
    v_18941 = qcar(v_18940);
    goto v_18465;
v_18466:
    v_18940 = qvalue(elt(env, 1)); // !'and
    goto v_18467;
v_18468:
    goto v_18464;
v_18465:
    goto v_18466;
v_18467:
    if (equal(v_18941, v_18940)) goto v_18462;
    else goto v_18463;
v_18462:
    v_18940 = stack[-3];
    goto v_18461;
v_18463:
    v_18940 = nil;
    goto v_18461;
    v_18940 = nil;
v_18461:
    if (v_18940 == nil) goto v_18459;
    else goto v_18457;
v_18459:
    goto v_18485;
v_18481:
    v_18940 = stack[-4];
    v_18941 = qcar(v_18940);
    goto v_18482;
v_18483:
    v_18940 = qvalue(elt(env, 2)); // !'or
    goto v_18484;
v_18485:
    goto v_18481;
v_18482:
    goto v_18483;
v_18484:
    if (equal(v_18941, v_18940)) goto v_18479;
    else goto v_18480;
v_18479:
    v_18940 = stack[-3];
    v_18940 = (v_18940 == nil ? lisp_true : nil);
    goto v_18478;
v_18480:
    v_18940 = nil;
    goto v_18478;
    v_18940 = nil;
v_18478:
    if (v_18940 == nil) goto v_18476;
    else goto v_18457;
v_18476:
    goto v_18458;
v_18457:
    v_18940 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_18940;
    v_18940 = stack[-4];
    v_18940 = qcdr(v_18940);
    stack[-1] = v_18940;
v_18498:
    v_18940 = stack[-1];
    if (v_18940 == nil) goto v_18503;
    else goto v_18504;
v_18503:
    goto v_18497;
v_18504:
    v_18940 = stack[-1];
    v_18940 = qcar(v_18940);
    goto v_18515;
v_18511:
    goto v_18512;
v_18513:
    goto v_18522;
v_18518:
    v_18941 = v_18940;
    goto v_18519;
v_18520:
    v_18940 = stack[-3];
    goto v_18521;
v_18522:
    goto v_18518;
v_18519:
    goto v_18520;
v_18521:
    v_18940 = CC_simpKprop1(elt(env, 0), v_18941, v_18940);
    env = stack[-6];
    goto v_18514;
v_18515:
    goto v_18511;
v_18512:
    goto v_18513;
v_18514:
    fn = elt(env, 16); // multf
    v_18940 = (*qfn2(fn))(fn, stack[0], v_18940);
    env = stack[-6];
    stack[0] = v_18940;
    v_18940 = stack[-1];
    v_18940 = qcdr(v_18940);
    stack[-1] = v_18940;
    goto v_18498;
v_18497:
    goto v_18456;
v_18458:
    goto v_18538;
v_18534:
    v_18940 = stack[-4];
    v_18941 = qcar(v_18940);
    goto v_18535;
v_18536:
    v_18940 = qvalue(elt(env, 2)); // !'or
    goto v_18537;
v_18538:
    goto v_18534;
v_18535:
    goto v_18536;
v_18537:
    if (equal(v_18941, v_18940)) goto v_18532;
    else goto v_18533;
v_18532:
    v_18940 = stack[-3];
    goto v_18531;
v_18533:
    v_18940 = nil;
    goto v_18531;
    v_18940 = nil;
v_18531:
    if (v_18940 == nil) goto v_18529;
    else goto v_18527;
v_18529:
    goto v_18555;
v_18551:
    v_18940 = stack[-4];
    v_18941 = qcar(v_18940);
    goto v_18552;
v_18553:
    v_18940 = qvalue(elt(env, 1)); // !'and
    goto v_18554;
v_18555:
    goto v_18551;
v_18552:
    goto v_18553;
v_18554:
    if (equal(v_18941, v_18940)) goto v_18549;
    else goto v_18550;
v_18549:
    v_18940 = stack[-3];
    v_18940 = (v_18940 == nil ? lisp_true : nil);
    goto v_18548;
v_18550:
    v_18940 = nil;
    goto v_18548;
    v_18940 = nil;
v_18548:
    if (v_18940 == nil) goto v_18546;
    else goto v_18527;
v_18546:
    goto v_18528;
v_18527:
    v_18940 = nil;
    stack[0] = v_18940;
    v_18940 = stack[-4];
    v_18940 = qcdr(v_18940);
    stack[-1] = v_18940;
v_18568:
    v_18940 = stack[-1];
    if (v_18940 == nil) goto v_18573;
    else goto v_18574;
v_18573:
    goto v_18567;
v_18574:
    v_18940 = stack[-1];
    v_18940 = qcar(v_18940);
    goto v_18585;
v_18581:
    goto v_18582;
v_18583:
    goto v_18592;
v_18588:
    v_18941 = v_18940;
    goto v_18589;
v_18590:
    v_18940 = stack[-3];
    goto v_18591;
v_18592:
    goto v_18588;
v_18589:
    goto v_18590;
v_18591:
    v_18940 = CC_simpKprop1(elt(env, 0), v_18941, v_18940);
    env = stack[-6];
    goto v_18584;
v_18585:
    goto v_18581;
v_18582:
    goto v_18583;
v_18584:
    fn = elt(env, 17); // addf
    v_18940 = (*qfn2(fn))(fn, stack[0], v_18940);
    env = stack[-6];
    stack[0] = v_18940;
    v_18940 = stack[-1];
    v_18940 = qcdr(v_18940);
    stack[-1] = v_18940;
    goto v_18568;
v_18567:
    goto v_18456;
v_18528:
    goto v_18603;
v_18599:
    v_18940 = stack[-4];
    v_18941 = qcar(v_18940);
    goto v_18600;
v_18601:
    v_18940 = elt(env, 3); // not
    goto v_18602;
v_18603:
    goto v_18599;
v_18600:
    goto v_18601;
v_18602:
    if (v_18941 == v_18940) goto v_18597;
    else goto v_18598;
v_18597:
    goto v_18612;
v_18608:
    v_18940 = stack[-4];
    v_18940 = qcdr(v_18940);
    v_18941 = qcar(v_18940);
    goto v_18609;
v_18610:
    v_18940 = stack[-3];
    v_18940 = (v_18940 == nil ? lisp_true : nil);
    goto v_18611;
v_18612:
    goto v_18608;
v_18609:
    goto v_18610;
v_18611:
    v_18940 = CC_simpKprop1(elt(env, 0), v_18941, v_18940);
    stack[0] = v_18940;
    goto v_18456;
v_18598:
    goto v_18624;
v_18620:
    v_18940 = stack[-4];
    v_18941 = qcar(v_18940);
    goto v_18621;
v_18622:
    v_18940 = elt(env, 4); // implies
    goto v_18623;
v_18624:
    goto v_18620;
v_18621:
    goto v_18622;
v_18623:
    if (v_18941 == v_18940) goto v_18618;
    else goto v_18619;
v_18618:
    v_18940 = stack[-3];
    if (v_18940 == nil) goto v_18631;
    goto v_18638;
v_18634:
    goto v_18646;
v_18640:
    stack[0] = elt(env, 5); // or
    goto v_18641;
v_18642:
    goto v_18653;
v_18649:
    v_18941 = elt(env, 3); // not
    goto v_18650;
v_18651:
    v_18940 = stack[-4];
    v_18940 = qcdr(v_18940);
    v_18940 = qcar(v_18940);
    goto v_18652;
v_18653:
    goto v_18649;
v_18650:
    goto v_18651;
v_18652:
    v_18941 = list2(v_18941, v_18940);
    env = stack[-6];
    goto v_18643;
v_18644:
    v_18940 = stack[-4];
    v_18940 = qcdr(v_18940);
    v_18940 = qcdr(v_18940);
    v_18940 = qcar(v_18940);
    goto v_18645;
v_18646:
    goto v_18640;
v_18641:
    goto v_18642;
v_18643:
    goto v_18644;
v_18645:
    v_18941 = list3(stack[0], v_18941, v_18940);
    env = stack[-6];
    goto v_18635;
v_18636:
    v_18940 = lisp_true;
    goto v_18637;
v_18638:
    goto v_18634;
v_18635:
    goto v_18636;
v_18637:
    v_18940 = CC_simpKprop1(elt(env, 0), v_18941, v_18940);
    stack[0] = v_18940;
    goto v_18629;
v_18631:
    goto v_18670;
v_18666:
    goto v_18678;
v_18672:
    stack[0] = elt(env, 5); // or
    goto v_18673;
v_18674:
    goto v_18685;
v_18681:
    v_18941 = elt(env, 3); // not
    goto v_18682;
v_18683:
    v_18940 = stack[-4];
    v_18940 = qcdr(v_18940);
    v_18940 = qcdr(v_18940);
    v_18940 = qcar(v_18940);
    goto v_18684;
v_18685:
    goto v_18681;
v_18682:
    goto v_18683;
v_18684:
    v_18941 = list2(v_18941, v_18940);
    env = stack[-6];
    goto v_18675;
v_18676:
    v_18940 = stack[-4];
    v_18940 = qcdr(v_18940);
    v_18940 = qcar(v_18940);
    goto v_18677;
v_18678:
    goto v_18672;
v_18673:
    goto v_18674;
v_18675:
    goto v_18676;
v_18677:
    v_18941 = list3(stack[0], v_18941, v_18940);
    env = stack[-6];
    goto v_18667;
v_18668:
    v_18940 = lisp_true;
    goto v_18669;
v_18670:
    goto v_18666;
v_18667:
    goto v_18668;
v_18669:
    v_18940 = CC_simpKprop1(elt(env, 0), v_18941, v_18940);
    stack[0] = v_18940;
    goto v_18629;
v_18629:
    goto v_18456;
v_18619:
    goto v_18701;
v_18697:
    v_18940 = stack[-4];
    v_18941 = qcar(v_18940);
    goto v_18698;
v_18699:
    v_18940 = elt(env, 6); // equiv
    goto v_18700;
v_18701:
    goto v_18697;
v_18698:
    goto v_18699;
v_18700:
    if (v_18941 == v_18940) goto v_18695;
    else goto v_18696;
v_18695:
    goto v_18710;
v_18706:
    goto v_18718;
v_18712:
    stack[-5] = elt(env, 5); // or
    goto v_18713;
v_18714:
    goto v_18727;
v_18721:
    v_18942 = elt(env, 7); // and
    goto v_18722;
v_18723:
    v_18940 = stack[-4];
    v_18940 = qcdr(v_18940);
    v_18941 = qcar(v_18940);
    goto v_18724;
v_18725:
    v_18940 = stack[-4];
    v_18940 = qcdr(v_18940);
    v_18940 = qcdr(v_18940);
    v_18940 = qcar(v_18940);
    goto v_18726;
v_18727:
    goto v_18721;
v_18722:
    goto v_18723;
v_18724:
    goto v_18725;
v_18726:
    stack[-2] = list3(v_18942, v_18941, v_18940);
    env = stack[-6];
    goto v_18715;
v_18716:
    goto v_18743;
v_18737:
    stack[-1] = elt(env, 7); // and
    goto v_18738;
v_18739:
    goto v_18750;
v_18746:
    v_18941 = elt(env, 3); // not
    goto v_18747;
v_18748:
    v_18940 = stack[-4];
    v_18940 = qcdr(v_18940);
    v_18940 = qcar(v_18940);
    goto v_18749;
v_18750:
    goto v_18746;
v_18747:
    goto v_18748;
v_18749:
    stack[0] = list2(v_18941, v_18940);
    env = stack[-6];
    goto v_18740;
v_18741:
    goto v_18760;
v_18756:
    v_18941 = elt(env, 3); // not
    goto v_18757;
v_18758:
    v_18940 = stack[-4];
    v_18940 = qcdr(v_18940);
    v_18940 = qcdr(v_18940);
    v_18940 = qcar(v_18940);
    goto v_18759;
v_18760:
    goto v_18756;
v_18757:
    goto v_18758;
v_18759:
    v_18940 = list2(v_18941, v_18940);
    env = stack[-6];
    goto v_18742;
v_18743:
    goto v_18737;
v_18738:
    goto v_18739;
v_18740:
    goto v_18741;
v_18742:
    v_18940 = list3(stack[-1], stack[0], v_18940);
    env = stack[-6];
    goto v_18717;
v_18718:
    goto v_18712;
v_18713:
    goto v_18714;
v_18715:
    goto v_18716;
v_18717:
    v_18941 = list3(stack[-5], stack[-2], v_18940);
    env = stack[-6];
    goto v_18707;
v_18708:
    v_18940 = stack[-3];
    goto v_18709;
v_18710:
    goto v_18706;
v_18707:
    goto v_18708;
v_18709:
    v_18940 = CC_simpKprop1(elt(env, 0), v_18941, v_18940);
    stack[0] = v_18940;
    goto v_18456;
v_18696:
    goto v_18449;
v_18456:
    v_18940 = stack[0];
    goto v_18447;
v_18448:
    goto v_18782;
v_18778:
    v_18941 = stack[-4];
    goto v_18779;
v_18780:
    v_18940 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18781;
v_18782:
    goto v_18778;
v_18779:
    goto v_18780;
v_18781:
    if (v_18941 == v_18940) goto v_18776;
    else goto v_18777;
v_18776:
    v_18940 = lisp_true;
    goto v_18775;
v_18777:
    goto v_18796;
v_18792:
    v_18941 = stack[-4];
    goto v_18793;
v_18794:
    v_18940 = lisp_true;
    goto v_18795;
v_18796:
    goto v_18792;
v_18793:
    goto v_18794;
v_18795:
    if (equal(v_18941, v_18940)) goto v_18790;
    else goto v_18791;
v_18790:
    v_18940 = lisp_true;
    goto v_18789;
v_18791:
    goto v_18806;
v_18802:
    v_18941 = stack[-4];
    goto v_18803;
v_18804:
    v_18940 = elt(env, 8); // true
    goto v_18805;
v_18806:
    goto v_18802;
v_18803:
    goto v_18804;
v_18805:
    v_18940 = (v_18941 == v_18940 ? lisp_true : nil);
    goto v_18789;
    v_18940 = nil;
v_18789:
    goto v_18775;
    v_18940 = nil;
v_18775:
    if (v_18940 == nil) goto v_18773;
    v_18940 = stack[-3];
    stack[-4] = v_18940;
    goto v_18771;
v_18773:
    goto v_18821;
v_18817:
    v_18941 = stack[-4];
    goto v_18818;
v_18819:
    v_18940 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18820;
v_18821:
    goto v_18817;
v_18818:
    goto v_18819;
v_18820:
    if (v_18941 == v_18940) goto v_18815;
    else goto v_18816;
v_18815:
    v_18940 = lisp_true;
    goto v_18814;
v_18816:
    v_18940 = stack[-4];
    if (v_18940 == nil) goto v_18829;
    else goto v_18830;
v_18829:
    v_18940 = lisp_true;
    goto v_18828;
v_18830:
    goto v_18839;
v_18835:
    v_18941 = stack[-4];
    goto v_18836;
v_18837:
    v_18940 = elt(env, 9); // false
    goto v_18838;
v_18839:
    goto v_18835;
v_18836:
    goto v_18837;
v_18838:
    v_18940 = (v_18941 == v_18940 ? lisp_true : nil);
    goto v_18828;
    v_18940 = nil;
v_18828:
    goto v_18814;
    v_18940 = nil;
v_18814:
    if (v_18940 == nil) goto v_18812;
    v_18940 = stack[-3];
    v_18940 = (v_18940 == nil ? lisp_true : nil);
    stack[-4] = v_18940;
    goto v_18771;
v_18812:
v_18771:
    goto v_18853;
v_18849:
    v_18941 = stack[-4];
    goto v_18850;
v_18851:
    v_18940 = lisp_true;
    goto v_18852;
v_18853:
    goto v_18849;
v_18850:
    goto v_18851;
v_18852:
    if (equal(v_18941, v_18940)) goto v_18847;
    else goto v_18848;
v_18847:
    goto v_18861;
v_18857:
    v_18941 = elt(env, 10); // (or !*true (not !*true))
    goto v_18858;
v_18859:
    v_18940 = lisp_true;
    goto v_18860;
v_18861:
    goto v_18857;
v_18858:
    goto v_18859;
v_18860:
    stack[-4] = v_18941;
    stack[-3] = v_18940;
    goto v_18441;
v_18848:
    v_18940 = stack[-4];
    if (v_18940 == nil) goto v_18866;
    else goto v_18867;
v_18866:
    goto v_18874;
v_18870:
    v_18941 = elt(env, 11); // (and !*true (not !*true))
    goto v_18871;
v_18872:
    v_18940 = lisp_true;
    goto v_18873;
v_18874:
    goto v_18870;
v_18871:
    goto v_18872;
v_18873:
    stack[-4] = v_18941;
    stack[-3] = v_18940;
    goto v_18441;
v_18867:
v_18449:
    v_18940 = stack[-4];
    fn = elt(env, 18); // reval
    v_18940 = (*qfn1(fn))(fn, v_18940);
    env = stack[-6];
    stack[-4] = v_18940;
    goto v_18888;
v_18884:
    v_18941 = stack[-4];
    goto v_18885;
v_18886:
    v_18940 = elt(env, 12); // boolean
    goto v_18887;
v_18888:
    goto v_18884;
v_18885:
    goto v_18886;
v_18887:
    if (!consp(v_18941)) goto v_18882;
    v_18941 = qcar(v_18941);
    if (v_18941 == v_18940) goto v_18881;
    else goto v_18882;
v_18881:
    goto v_18896;
v_18892:
    v_18940 = stack[-4];
    v_18940 = qcdr(v_18940);
    v_18941 = qcar(v_18940);
    goto v_18893;
v_18894:
    v_18940 = stack[-3];
    goto v_18895;
v_18896:
    goto v_18892;
v_18893:
    goto v_18894;
v_18895:
    stack[-4] = v_18941;
    stack[-3] = v_18940;
    goto v_18441;
v_18882:
    goto v_18907;
v_18903:
    v_18940 = stack[-3];
    if (v_18940 == nil) goto v_18911;
    v_18940 = elt(env, 13); // prop!*
    v_18941 = v_18940;
    goto v_18909;
v_18911:
    v_18940 = elt(env, 14); // not_prop!*
    v_18941 = v_18940;
    goto v_18909;
    v_18941 = nil;
v_18909:
    goto v_18904;
v_18905:
    v_18940 = stack[-4];
    goto v_18906;
v_18907:
    goto v_18903;
v_18904:
    goto v_18905;
v_18906:
    v_18940 = list2(v_18941, v_18940);
    env = stack[-6];
    fn = elt(env, 19); // simp
    v_18940 = (*qfn1(fn))(fn, v_18940);
    env = stack[-6];
    v_18940 = qcar(v_18940);
    stack[0] = v_18940;
    goto v_18927;
v_18923:
    v_18941 = stack[-4];
    goto v_18924;
v_18925:
    v_18940 = qvalue(elt(env, 15)); // propvars!*
    goto v_18926;
v_18927:
    goto v_18923;
v_18924:
    goto v_18925;
v_18926:
    v_18940 = Lmember(nil, v_18941, v_18940);
    if (v_18940 == nil) goto v_18921;
    else goto v_18922;
v_18921:
    goto v_18936;
v_18932:
    v_18941 = stack[-4];
    goto v_18933;
v_18934:
    v_18940 = qvalue(elt(env, 15)); // propvars!*
    goto v_18935;
v_18936:
    goto v_18932;
v_18933:
    goto v_18934;
v_18935:
    v_18940 = cons(v_18941, v_18940);
    env = stack[-6];
    qvalue(elt(env, 15)) = v_18940; // propvars!*
    goto v_18920;
v_18922:
v_18920:
    v_18940 = stack[0];
v_18447:
    return onevalue(v_18940);
}



// Code for split_cov_cont_ids

static LispObject CC_split_cov_cont_ids(LispObject env,
                         LispObject v_18442)
{
    env = qenv(env);
    LispObject v_18504, v_18505, v_18506;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18442);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_18442;
// end of prologue
    stack[-2] = nil;
    stack[0] = nil;
v_18450:
    v_18504 = stack[-1];
    if (v_18504 == nil) goto v_18453;
    else goto v_18454;
v_18453:
    goto v_18449;
v_18454:
    v_18504 = stack[-1];
    v_18504 = qcar(v_18504);
    v_18506 = v_18504;
    goto v_18469;
v_18465:
    v_18505 = v_18506;
    goto v_18466;
v_18467:
    v_18504 = elt(env, 1); // minus
    goto v_18468;
v_18469:
    goto v_18465;
v_18466:
    goto v_18467;
v_18468:
    if (!consp(v_18505)) goto v_18463;
    v_18505 = qcar(v_18505);
    if (v_18505 == v_18504) goto v_18462;
    else goto v_18463;
v_18462:
    goto v_18477;
v_18473:
    v_18504 = v_18506;
    v_18504 = qcdr(v_18504);
    v_18505 = qcar(v_18504);
    goto v_18474;
v_18475:
    v_18504 = stack[-2];
    goto v_18476;
v_18477:
    goto v_18473;
v_18474:
    goto v_18475;
v_18476:
    v_18504 = cons(v_18505, v_18504);
    env = stack[-3];
    stack[-2] = v_18504;
    goto v_18461;
v_18463:
    goto v_18489;
v_18485:
    v_18505 = v_18506;
    goto v_18486;
v_18487:
    v_18504 = stack[0];
    goto v_18488;
v_18489:
    goto v_18485;
v_18486:
    goto v_18487;
v_18488:
    v_18504 = cons(v_18505, v_18504);
    env = stack[-3];
    stack[0] = v_18504;
    goto v_18461;
v_18461:
    v_18504 = stack[-1];
    v_18504 = qcdr(v_18504);
    stack[-1] = v_18504;
    goto v_18450;
v_18449:
    goto v_18499;
v_18495:
    v_18504 = stack[-2];
    v_18505 = Lnreverse(nil, v_18504);
    env = stack[-3];
    goto v_18496;
v_18497:
    v_18504 = stack[0];
    v_18504 = Lnreverse(nil, v_18504);
    goto v_18498;
v_18499:
    goto v_18495;
v_18496:
    goto v_18497;
v_18498:
    return list2(v_18505, v_18504);
    return onevalue(v_18504);
}



// Code for st_ad_numsorttree

static LispObject CC_st_ad_numsorttree(LispObject env,
                         LispObject v_18442)
{
    env = qenv(env);
    LispObject v_18460, v_18461;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18442);
    }
// copy arguments values to proper place
    v_18460 = v_18442;
// end of prologue
    fn = elt(env, 1); // st_ad_numsorttree1
    v_18460 = (*qfn1(fn))(fn, v_18460);
    goto v_18454;
v_18450:
    v_18461 = v_18460;
    v_18461 = qcar(v_18461);
    goto v_18451;
v_18452:
    v_18460 = qcdr(v_18460);
    v_18460 = qcar(v_18460);
    goto v_18453;
v_18454:
    goto v_18450;
v_18451:
    goto v_18452;
v_18453:
    return cons(v_18461, v_18460);
    return onevalue(v_18460);
}



// Code for general!-horner!-rule!-mod!-p

static LispObject CC_generalKhornerKruleKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18598, v_18599, v_18600, v_18601, v_18602;
    LispObject fn;
    LispObject v_18446, v_18445, v_18444, v_18443, v_18442;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "general-horner-rule-mod-p");
    va_start(aa, nargs);
    v_18442 = va_arg(aa, LispObject);
    v_18443 = va_arg(aa, LispObject);
    v_18444 = va_arg(aa, LispObject);
    v_18445 = va_arg(aa, LispObject);
    v_18446 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_18446,v_18445,v_18444,v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_18442,v_18443,v_18444,v_18445,v_18446);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_18446;
    stack[-3] = v_18445;
    stack[-4] = v_18444;
    v_18600 = v_18443;
    v_18601 = v_18442;
// end of prologue
v_18441:
    v_18598 = stack[-4];
    if (!consp(v_18598)) goto v_18458;
    else goto v_18459;
v_18458:
    v_18598 = lisp_true;
    goto v_18457;
v_18459:
    v_18598 = stack[-4];
    v_18598 = qcar(v_18598);
    v_18598 = (consp(v_18598) ? nil : lisp_true);
    goto v_18457;
    v_18598 = nil;
v_18457:
    if (v_18598 == nil) goto v_18455;
    v_18598 = lisp_true;
    goto v_18453;
v_18455:
    goto v_18474;
v_18470:
    v_18598 = stack[-4];
    v_18598 = qcar(v_18598);
    v_18598 = qcar(v_18598);
    v_18599 = qcar(v_18598);
    goto v_18471;
v_18472:
    v_18598 = stack[-2];
    goto v_18473;
v_18474:
    goto v_18470;
v_18471:
    goto v_18472;
v_18473:
    v_18598 = (equal(v_18599, v_18598) ? lisp_true : nil);
    v_18598 = (v_18598 == nil ? lisp_true : nil);
    goto v_18453;
    v_18598 = nil;
v_18453:
    if (v_18598 == nil) goto v_18451;
    v_18598 = stack[-3];
    if (v_18598 == nil) goto v_18488;
    else goto v_18489;
v_18488:
    v_18598 = lisp_true;
    goto v_18487;
v_18489:
    v_18598 = stack[-3];
    v_18598 = (LispObject)zerop(v_18598);
    v_18598 = v_18598 ? lisp_true : nil;
    env = stack[-6];
    goto v_18487;
    v_18598 = nil;
v_18487:
    if (v_18598 == nil) goto v_18485;
    v_18598 = stack[-4];
    goto v_18483;
v_18485:
    goto v_18504;
v_18500:
    stack[0] = v_18601;
    goto v_18501;
v_18502:
    goto v_18511;
v_18507:
    v_18598 = stack[-3];
    goto v_18508;
v_18509:
    v_18599 = v_18600;
    goto v_18510;
v_18511:
    goto v_18507;
v_18508:
    goto v_18509;
v_18510:
    fn = elt(env, 1); // general!-expt!-mod!-p
    v_18598 = (*qfn2(fn))(fn, v_18598, v_18599);
    env = stack[-6];
    goto v_18503;
v_18504:
    goto v_18500;
v_18501:
    goto v_18502;
v_18503:
    fn = elt(env, 2); // general!-times!-mod!-p
    v_18598 = (*qfn2(fn))(fn, stack[0], v_18598);
    env = stack[-6];
    v_18601 = v_18598;
    goto v_18519;
v_18515:
    v_18598 = stack[-4];
    goto v_18516;
v_18517:
    v_18599 = v_18601;
    goto v_18518;
v_18519:
    goto v_18515;
v_18516:
    goto v_18517;
v_18518:
    {
        fn = elt(env, 3); // general!-plus!-mod!-p
        return (*qfn2(fn))(fn, v_18598, v_18599);
    }
    v_18598 = nil;
v_18483:
    goto v_18449;
v_18451:
    v_18598 = stack[-4];
    v_18598 = qcar(v_18598);
    v_18598 = qcar(v_18598);
    v_18598 = qcdr(v_18598);
    stack[-5] = v_18598;
    goto v_18542;
v_18532:
    v_18598 = stack[-3];
    if (v_18598 == nil) goto v_18549;
    else goto v_18550;
v_18549:
    v_18598 = lisp_true;
    goto v_18548;
v_18550:
    v_18598 = stack[-3];
    v_18598 = (LispObject)zerop(v_18598);
    v_18598 = v_18598 ? lisp_true : nil;
    env = stack[-6];
    goto v_18548;
    v_18598 = nil;
v_18548:
    if (v_18598 == nil) goto v_18546;
    v_18598 = stack[-4];
    v_18598 = qcar(v_18598);
    v_18598 = qcdr(v_18598);
    v_18601 = v_18598;
    goto v_18544;
v_18546:
    goto v_18567;
v_18563:
    v_18598 = stack[-4];
    v_18598 = qcar(v_18598);
    stack[-1] = qcdr(v_18598);
    goto v_18564;
v_18565:
    goto v_18576;
v_18572:
    stack[0] = v_18601;
    goto v_18573;
v_18574:
    goto v_18583;
v_18579:
    v_18599 = stack[-3];
    goto v_18580;
v_18581:
    goto v_18589;
v_18585:
    goto v_18586;
v_18587:
    v_18598 = stack[-5];
    goto v_18588;
v_18589:
    goto v_18585;
v_18586:
    goto v_18587;
v_18588:
    v_18598 = (LispObject)(intptr_t)((intptr_t)v_18600 - (intptr_t)v_18598 + TAG_FIXNUM);
    goto v_18582;
v_18583:
    goto v_18579;
v_18580:
    goto v_18581;
v_18582:
    fn = elt(env, 1); // general!-expt!-mod!-p
    v_18598 = (*qfn2(fn))(fn, v_18599, v_18598);
    env = stack[-6];
    goto v_18575;
v_18576:
    goto v_18572;
v_18573:
    goto v_18574;
v_18575:
    fn = elt(env, 2); // general!-times!-mod!-p
    v_18598 = (*qfn2(fn))(fn, stack[0], v_18598);
    env = stack[-6];
    goto v_18566;
v_18567:
    goto v_18563;
v_18564:
    goto v_18565;
v_18566:
    fn = elt(env, 3); // general!-plus!-mod!-p
    v_18598 = (*qfn2(fn))(fn, stack[-1], v_18598);
    env = stack[-6];
    v_18601 = v_18598;
    goto v_18544;
    v_18601 = nil;
v_18544:
    goto v_18533;
v_18534:
    v_18600 = stack[-5];
    goto v_18535;
v_18536:
    v_18598 = stack[-4];
    v_18602 = qcdr(v_18598);
    goto v_18537;
v_18538:
    v_18599 = stack[-3];
    goto v_18539;
v_18540:
    v_18598 = stack[-2];
    goto v_18541;
v_18542:
    goto v_18532;
v_18533:
    goto v_18534;
v_18535:
    goto v_18536;
v_18537:
    goto v_18538;
v_18539:
    goto v_18540;
v_18541:
    stack[-4] = v_18602;
    stack[-3] = v_18599;
    stack[-2] = v_18598;
    goto v_18441;
    goto v_18449;
    v_18598 = nil;
v_18449:
    return onevalue(v_18598);
}



// Code for gitimes!:

static LispObject CC_gitimesT(LispObject env,
                         LispObject v_18442, LispObject v_18443)
{
    env = qenv(env);
    LispObject v_18511, v_18512, v_18513, v_18514;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18442,v_18443);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_18511 = v_18443;
    v_18512 = v_18442;
// end of prologue
    v_18513 = v_18512;
    v_18513 = qcdr(v_18513);
    v_18514 = qcar(v_18513);
    v_18512 = qcdr(v_18512);
    v_18513 = qcdr(v_18512);
    v_18512 = v_18511;
    v_18512 = qcdr(v_18512);
    v_18512 = qcar(v_18512);
    v_18511 = qcdr(v_18511);
    v_18511 = qcdr(v_18511);
    stack[-4] = v_18514;
    stack[-3] = v_18513;
    stack[-2] = v_18512;
    stack[-1] = v_18511;
    goto v_18466;
v_18462:
    goto v_18472;
v_18468:
    goto v_18478;
v_18474:
    v_18512 = stack[-4];
    goto v_18475;
v_18476:
    v_18511 = stack[-2];
    goto v_18477;
v_18478:
    goto v_18474;
v_18475:
    goto v_18476;
v_18477:
    stack[0] = times2(v_18512, v_18511);
    env = stack[-5];
    goto v_18469;
v_18470:
    goto v_18486;
v_18482:
    v_18512 = stack[-3];
    goto v_18483;
v_18484:
    v_18511 = stack[-1];
    goto v_18485;
v_18486:
    goto v_18482;
v_18483:
    goto v_18484;
v_18485:
    v_18511 = times2(v_18512, v_18511);
    env = stack[-5];
    goto v_18471;
v_18472:
    goto v_18468;
v_18469:
    goto v_18470;
v_18471:
    stack[0] = difference2(stack[0], v_18511);
    env = stack[-5];
    goto v_18463;
v_18464:
    goto v_18494;
v_18490:
    goto v_18500;
v_18496:
    v_18512 = stack[-4];
    goto v_18497;
v_18498:
    v_18511 = stack[-1];
    goto v_18499;
v_18500:
    goto v_18496;
v_18497:
    goto v_18498;
v_18499:
    stack[-1] = times2(v_18512, v_18511);
    env = stack[-5];
    goto v_18491;
v_18492:
    goto v_18508;
v_18504:
    v_18512 = stack[-2];
    goto v_18505;
v_18506:
    v_18511 = stack[-3];
    goto v_18507;
v_18508:
    goto v_18504;
v_18505:
    goto v_18506;
v_18507:
    v_18511 = times2(v_18512, v_18511);
    env = stack[-5];
    goto v_18493;
v_18494:
    goto v_18490;
v_18491:
    goto v_18492;
v_18493:
    v_18511 = plus2(stack[-1], v_18511);
    env = stack[-5];
    goto v_18465;
v_18466:
    goto v_18462;
v_18463:
    goto v_18464;
v_18465:
    {
        LispObject v_18520 = stack[0];
        fn = elt(env, 1); // mkgi
        return (*qfn2(fn))(fn, v_18520, v_18511);
    }
}



// Code for !*a2f

static LispObject CC_Ha2f(LispObject env,
                         LispObject v_18442)
{
    env = qenv(env);
    LispObject v_18447;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18442);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18447 = v_18442;
// end of prologue
    fn = elt(env, 1); // simp!*
    v_18447 = (*qfn1(fn))(fn, v_18447);
    env = stack[0];
    {
        fn = elt(env, 2); // !*q2f
        return (*qfn1(fn))(fn, v_18447);
    }
}



// Code for letexprn

static LispObject CC_letexprn(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_19015, v_19016, v_19017;
    LispObject fn;
    LispObject v_18447, v_18446, v_18445, v_18444, v_18443, v_18442;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "letexprn");
    va_start(aa, nargs);
    v_18442 = va_arg(aa, LispObject);
    v_18443 = va_arg(aa, LispObject);
    v_18444 = va_arg(aa, LispObject);
    v_18445 = va_arg(aa, LispObject);
    v_18446 = va_arg(aa, LispObject);
    v_18447 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_18447,v_18446,v_18445,v_18444,v_18443,v_18442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_18442,v_18443,v_18444,v_18445,v_18446,v_18447);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-1] = v_18447;
    stack[-2] = v_18446;
    stack[-3] = v_18445;
    stack[-4] = v_18444;
    stack[-5] = v_18443;
    stack[-6] = v_18442;
// end of prologue
    goto v_18461;
v_18457:
    v_19015 = stack[-3];
    v_19016 = qcdr(v_19015);
    goto v_18458;
v_18459:
    v_19015 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18460;
v_18461:
    goto v_18457;
v_18458:
    goto v_18459;
v_18460:
    if (v_19016 == v_19015) goto v_18456;
    goto v_18474;
v_18466:
    v_19015 = stack[-3];
    v_19015 = qcar(v_19015);
    fn = elt(env, 14); // let!-prepf
    stack[-1] = (*qfn1(fn))(fn, v_19015);
    env = stack[-8];
    goto v_18467;
v_18468:
    goto v_18485;
v_18479:
    stack[0] = elt(env, 1); // times
    goto v_18480;
v_18481:
    v_19015 = stack[-3];
    v_19015 = qcdr(v_19015);
    fn = elt(env, 14); // let!-prepf
    v_19016 = (*qfn1(fn))(fn, v_19015);
    env = stack[-8];
    goto v_18482;
v_18483:
    v_19015 = stack[-5];
    goto v_18484;
v_18485:
    goto v_18479;
v_18480:
    goto v_18481;
v_18482:
    goto v_18483;
v_18484:
    v_19017 = list3(stack[0], v_19016, v_19015);
    env = stack[-8];
    goto v_18469;
v_18470:
    v_19016 = stack[-4];
    goto v_18471;
v_18472:
    v_19015 = stack[-2];
    goto v_18473;
v_18474:
    goto v_18466;
v_18467:
    goto v_18468;
v_18469:
    goto v_18470;
v_18471:
    goto v_18472;
v_18473:
    {
        LispObject v_19026 = stack[-1];
        fn = elt(env, 15); // let2
        return (*qfnn(fn))(fn, 4, v_19026, v_19017, v_19016, v_19015);
    }
v_18456:
    v_19015 = stack[-3];
    v_19015 = qcar(v_19015);
    stack[-3] = v_19015;
    v_19015 = qcdr(v_19015);
    if (v_19015 == nil) goto v_18494;
    goto v_18507;
v_18499:
    v_19015 = stack[-3];
    v_19015 = qcar(v_19015);
    v_19015 = ncons(v_19015);
    env = stack[-8];
    fn = elt(env, 14); // let!-prepf
    stack[-1] = (*qfn1(fn))(fn, v_19015);
    env = stack[-8];
    goto v_18500;
v_18501:
    goto v_18519;
v_18513:
    stack[0] = elt(env, 2); // difference
    goto v_18514;
v_18515:
    goto v_18516;
v_18517:
    v_19015 = stack[-3];
    v_19015 = qcdr(v_19015);
    fn = elt(env, 14); // let!-prepf
    v_19015 = (*qfn1(fn))(fn, v_19015);
    env = stack[-8];
    goto v_18518;
v_18519:
    goto v_18513;
v_18514:
    goto v_18515;
v_18516:
    goto v_18517;
v_18518:
    v_19017 = list3(stack[0], stack[-5], v_19015);
    env = stack[-8];
    goto v_18502;
v_18503:
    v_19016 = stack[-4];
    goto v_18504;
v_18505:
    v_19015 = stack[-2];
    goto v_18506;
v_18507:
    goto v_18499;
v_18500:
    goto v_18501;
v_18502:
    goto v_18503;
v_18504:
    goto v_18505;
v_18506:
    {
        LispObject v_19027 = stack[-1];
        fn = elt(env, 15); // let2
        return (*qfnn(fn))(fn, 4, v_19027, v_19017, v_19016, v_19015);
    }
v_18494:
    v_19015 = stack[-3];
    fn = elt(env, 16); // kernlp
    v_19015 = (*qfn1(fn))(fn, v_19015);
    env = stack[-8];
    stack[0] = v_19015;
    if (v_19015 == nil) goto v_18527;
    else goto v_18528;
v_18527:
    v_19015 = stack[-3];
    fn = elt(env, 17); // term!-split
    v_19015 = (*qfn1(fn))(fn, v_19015);
    env = stack[-8];
    stack[0] = v_19015;
    goto v_18542;
v_18534:
    v_19015 = stack[0];
    v_19015 = qcar(v_19015);
    fn = elt(env, 14); // let!-prepf
    stack[-3] = (*qfn1(fn))(fn, v_19015);
    env = stack[-8];
    goto v_18535;
v_18536:
    goto v_18553;
v_18547:
    stack[-1] = elt(env, 2); // difference
    goto v_18548;
v_18549:
    goto v_18550;
v_18551:
    v_19015 = stack[0];
    v_19015 = qcdr(v_19015);
    fn = elt(env, 14); // let!-prepf
    v_19015 = (*qfn1(fn))(fn, v_19015);
    env = stack[-8];
    goto v_18552;
v_18553:
    goto v_18547;
v_18548:
    goto v_18549;
v_18550:
    goto v_18551;
v_18552:
    v_19017 = list3(stack[-1], stack[-5], v_19015);
    env = stack[-8];
    goto v_18537;
v_18538:
    v_19016 = stack[-4];
    goto v_18539;
v_18540:
    v_19015 = stack[-2];
    goto v_18541;
v_18542:
    goto v_18534;
v_18535:
    goto v_18536;
v_18537:
    goto v_18538;
v_18539:
    goto v_18540;
v_18541:
    {
        LispObject v_19028 = stack[-3];
        fn = elt(env, 15); // let2
        return (*qfnn(fn))(fn, 4, v_19028, v_19017, v_19016, v_19015);
    }
v_18528:
    goto v_18567;
v_18563:
    v_19016 = stack[0];
    goto v_18564;
v_18565:
    v_19015 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18566;
v_18567:
    goto v_18563;
v_18564:
    goto v_18565;
v_18566:
    if (v_19016 == v_19015) goto v_18562;
    goto v_18579;
v_18571:
    goto v_18586;
v_18582:
    v_19016 = stack[-3];
    goto v_18583;
v_18584:
    v_19015 = stack[0];
    goto v_18585;
v_18586:
    goto v_18582;
v_18583:
    goto v_18584;
v_18585:
    fn = elt(env, 18); // quotf!*
    v_19015 = (*qfn2(fn))(fn, v_19016, v_19015);
    env = stack[-8];
    fn = elt(env, 14); // let!-prepf
    stack[-3] = (*qfn1(fn))(fn, v_19015);
    env = stack[-8];
    goto v_18572;
v_18573:
    goto v_18596;
v_18590:
    stack[-1] = elt(env, 3); // quotient
    goto v_18591;
v_18592:
    goto v_18593;
v_18594:
    v_19015 = stack[0];
    fn = elt(env, 14); // let!-prepf
    v_19015 = (*qfn1(fn))(fn, v_19015);
    env = stack[-8];
    goto v_18595;
v_18596:
    goto v_18590;
v_18591:
    goto v_18592;
v_18593:
    goto v_18594;
v_18595:
    v_19017 = list3(stack[-1], stack[-5], v_19015);
    env = stack[-8];
    goto v_18574;
v_18575:
    v_19016 = stack[-4];
    goto v_18576;
v_18577:
    v_19015 = stack[-2];
    goto v_18578;
v_18579:
    goto v_18571;
v_18572:
    goto v_18573;
v_18574:
    goto v_18575;
v_18576:
    goto v_18577;
v_18578:
    {
        LispObject v_19029 = stack[-3];
        fn = elt(env, 15); // let2
        return (*qfnn(fn))(fn, 4, v_19029, v_19017, v_19016, v_19015);
    }
v_18562:
    v_19015 = stack[-3];
    fn = elt(env, 19); // klistt
    v_19015 = (*qfn1(fn))(fn, v_19015);
    env = stack[-8];
    stack[-3] = v_19015;
    goto v_18612;
v_18606:
    stack[-7] = stack[-4];
    goto v_18607;
v_18608:
    v_19015 = qvalue(elt(env, 4)); // mcond!*
    if (v_19015 == nil) goto v_18617;
    v_19015 = qvalue(elt(env, 4)); // mcond!*
    stack[0] = v_19015;
    goto v_18615;
v_18617:
    v_19015 = lisp_true;
    stack[0] = v_19015;
    goto v_18615;
    stack[0] = nil;
v_18615:
    goto v_18609;
v_18610:
    goto v_18628;
v_18624:
    v_19016 = stack[-5];
    goto v_18625;
v_18626:
    v_19015 = nil;
    goto v_18627;
v_18628:
    goto v_18624;
v_18625:
    goto v_18626;
v_18627:
    v_19015 = list2(v_19016, v_19015);
    env = stack[-8];
    goto v_18611;
v_18612:
    goto v_18606;
v_18607:
    goto v_18608;
v_18609:
    goto v_18610;
v_18611:
    v_19015 = acons(stack[-7], stack[0], v_19015);
    env = stack[-8];
    stack[0] = v_19015;
    v_19015 = stack[-3];
    v_19015 = qcdr(v_19015);
    if (v_19015 == nil) goto v_18634;
    fn = elt(env, 20); // rmsubs
    v_19015 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_18645;
v_18639:
    goto v_18651;
v_18647:
    v_19016 = stack[-3];
    goto v_18648;
v_18649:
    v_19015 = stack[0];
    goto v_18650;
v_18651:
    goto v_18647;
v_18648:
    goto v_18649;
v_18650:
    v_19017 = cons(v_19016, v_19015);
    env = stack[-8];
    goto v_18640;
v_18641:
    v_19016 = qvalue(elt(env, 5)); // !*match
    goto v_18642;
v_18643:
    v_19015 = stack[-2];
    goto v_18644;
v_18645:
    goto v_18639;
v_18640:
    goto v_18641;
v_18642:
    goto v_18643;
v_18644:
    fn = elt(env, 21); // xadd!*
    v_19015 = (*qfnn(fn))(fn, 3, v_19017, v_19016, v_19015);
    env = stack[-8];
    qvalue(elt(env, 5)) = v_19015; // !*match
    goto v_18452;
v_18634:
    v_19015 = stack[-4];
    if (v_19015 == nil) goto v_18660;
    else goto v_18661;
v_18660:
    goto v_18667;
v_18663:
    v_19015 = stack[-3];
    v_19015 = qcar(v_19015);
    v_19016 = qcdr(v_19015);
    goto v_18664;
v_18665:
    v_19015 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18666;
v_18667:
    goto v_18663;
v_18664:
    goto v_18665;
v_18666:
    v_19015 = (v_19016 == v_19015 ? lisp_true : nil);
    goto v_18659;
v_18661:
    v_19015 = nil;
    goto v_18659;
    v_19015 = nil;
v_18659:
    if (v_19015 == nil) goto v_18657;
    v_19015 = stack[-3];
    v_19015 = qcar(v_19015);
    v_19015 = qcar(v_19015);
    stack[-3] = v_19015;
    v_19015 = stack[-1];
    if (v_19015 == nil) goto v_18685;
    else goto v_18686;
v_18685:
    v_19015 = qvalue(elt(env, 4)); // mcond!*
    if (v_19015 == nil) goto v_18690;
    else goto v_18691;
v_18690:
    v_19015 = lisp_true;
    goto v_18689;
v_18691:
    goto v_18704;
v_18700:
    v_19016 = qvalue(elt(env, 4)); // mcond!*
    goto v_18701;
v_18702:
    v_19015 = lisp_true;
    goto v_18703;
v_18704:
    goto v_18700;
v_18701:
    goto v_18702;
v_18703:
    if (v_19016 == v_19015) goto v_18698;
    else goto v_18699;
v_18698:
    v_19015 = lisp_true;
    goto v_18697;
v_18699:
    goto v_18715;
v_18711:
    v_19016 = stack[-3];
    goto v_18712;
v_18713:
    v_19015 = qvalue(elt(env, 4)); // mcond!*
    goto v_18714;
v_18715:
    goto v_18711;
v_18712:
    goto v_18713;
v_18714:
    fn = elt(env, 22); // smember
    v_19015 = (*qfn2(fn))(fn, v_19016, v_19015);
    env = stack[-8];
    v_19015 = (v_19015 == nil ? lisp_true : nil);
    goto v_18697;
    v_19015 = nil;
v_18697:
    goto v_18689;
    v_19015 = nil;
v_18689:
    goto v_18684;
v_18686:
    v_19015 = nil;
    goto v_18684;
    v_19015 = nil;
v_18684:
    if (v_19015 == nil) goto v_18682;
    v_19015 = stack[-3];
    if (!consp(v_19015)) goto v_18724;
    else goto v_18725;
v_18724:
    goto v_18736;
v_18732:
    v_19016 = stack[-3];
    goto v_18733;
v_18734:
    v_19015 = elt(env, 6); // used!*
    goto v_18735;
v_18736:
    goto v_18732;
v_18733:
    goto v_18734;
v_18735:
    v_19015 = Lflagp(nil, v_19016, v_19015);
    env = stack[-8];
    if (v_19015 == nil) goto v_18730;
    fn = elt(env, 20); // rmsubs
    v_19015 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_18728;
v_18730:
    goto v_18728;
v_18728:
    goto v_18723;
v_18725:
    goto v_18750;
v_18746:
    stack[0] = elt(env, 6); // used!*
    goto v_18747;
v_18748:
    v_19015 = stack[-3];
    fn = elt(env, 23); // fkern
    v_19015 = (*qfn1(fn))(fn, v_19015);
    env = stack[-8];
    v_19015 = qcdr(v_19015);
    v_19015 = qcdr(v_19015);
    goto v_18749;
v_18750:
    goto v_18746;
v_18747:
    goto v_18748;
v_18749:
    v_19015 = Lmemq(nil, stack[0], v_19015);
    if (v_19015 == nil) goto v_18745;
    else goto v_18743;
v_18745:
    goto v_18762;
v_18758:
    v_19015 = stack[-3];
    v_19016 = qcar(v_19015);
    goto v_18759;
v_18760:
    v_19015 = elt(env, 7); // df
    goto v_18761;
v_18762:
    goto v_18758;
v_18759:
    goto v_18760;
v_18761:
    if (v_19016 == v_19015) goto v_18743;
    goto v_18744;
v_18743:
    fn = elt(env, 20); // rmsubs
    v_19015 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_18723;
v_18744:
v_18723:
    goto v_18774;
v_18768:
    v_19017 = stack[-3];
    goto v_18769;
v_18770:
    v_19016 = stack[-5];
    goto v_18771;
v_18772:
    v_19015 = stack[-2];
    goto v_18773;
v_18774:
    goto v_18768;
v_18769:
    goto v_18770;
v_18771:
    goto v_18772;
v_18773:
    fn = elt(env, 24); // setk1
    v_19015 = (*qfnn(fn))(fn, 3, v_19017, v_19016, v_19015);
    goto v_18680;
v_18682:
    v_19015 = stack[-3];
    if (!consp(v_19015)) goto v_18778;
    else goto v_18779;
v_18778:
    v_19015 = stack[-6];
    {
        fn = elt(env, 25); // errpri1
        return (*qfn1(fn))(fn, v_19015);
    }
v_18779:
    fn = elt(env, 20); // rmsubs
    v_19015 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_18793;
v_18787:
    v_19015 = stack[-3];
    stack[-4] = qcar(v_19015);
    goto v_18788;
v_18789:
    stack[-1] = elt(env, 8); // opmtch
    goto v_18790;
v_18791:
    goto v_18804;
v_18798:
    goto v_18810;
v_18806:
    v_19015 = stack[-3];
    v_19016 = qcdr(v_19015);
    goto v_18807;
v_18808:
    v_19015 = stack[0];
    goto v_18809;
v_18810:
    goto v_18806;
v_18807:
    goto v_18808;
v_18809:
    v_19017 = cons(v_19016, v_19015);
    env = stack[-8];
    goto v_18799;
v_18800:
    v_19015 = stack[-3];
    v_19015 = qcar(v_19015);
    if (!symbolp(v_19015)) v_19016 = nil;
    else { v_19016 = qfastgets(v_19015);
           if (v_19016 != nil) { v_19016 = elt(v_19016, 9); // opmtch
#ifdef RECORD_GET
             if (v_19016 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_19016 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_19016 == SPID_NOPROP) v_19016 = nil; }}
#endif
    goto v_18801;
v_18802:
    v_19015 = stack[-2];
    goto v_18803;
v_18804:
    goto v_18798;
v_18799:
    goto v_18800;
v_18801:
    goto v_18802;
v_18803:
    fn = elt(env, 21); // xadd!*
    v_19015 = (*qfnn(fn))(fn, 3, v_19017, v_19016, v_19015);
    env = stack[-8];
    goto v_18792;
v_18793:
    goto v_18787;
v_18788:
    goto v_18789;
v_18790:
    goto v_18791;
v_18792:
    v_19015 = Lputprop(nil, 3, stack[-4], stack[-1], v_19015);
    goto v_18680;
v_18680:
    goto v_18632;
v_18657:
    fn = elt(env, 20); // rmsubs
    v_19015 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_18833;
v_18829:
    v_19016 = stack[-5];
    goto v_18830;
v_18831:
    v_19015 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18832;
v_18833:
    goto v_18829;
v_18830:
    goto v_18831;
v_18832:
    if (v_19016 == v_19015) goto v_18827;
    else goto v_18828;
v_18827:
    v_19015 = stack[-4];
    if (v_19015 == nil) goto v_18838;
    else goto v_18839;
v_18838:
    v_19015 = stack[-1];
    v_19015 = (v_19015 == nil ? lisp_true : nil);
    goto v_18837;
v_18839:
    v_19015 = nil;
    goto v_18837;
    v_19015 = nil;
v_18837:
    goto v_18826;
v_18828:
    v_19015 = nil;
    goto v_18826;
    v_19015 = nil;
v_18826:
    if (v_19015 == nil) goto v_18824;
    goto v_18856;
v_18850:
    v_19015 = stack[-3];
    v_19017 = qcar(v_19015);
    goto v_18851;
v_18852:
    v_19016 = qvalue(elt(env, 9)); // asymplis!*
    goto v_18853;
v_18854:
    v_19015 = stack[-2];
    goto v_18855;
v_18856:
    goto v_18850;
v_18851:
    goto v_18852;
v_18853:
    goto v_18854;
v_18855:
    fn = elt(env, 26); // xadd
    v_19015 = (*qfnn(fn))(fn, 3, v_19017, v_19016, v_19015);
    env = stack[-8];
    qvalue(elt(env, 9)) = v_19015; // asymplis!*
    goto v_18868;
v_18862:
    goto v_18876;
v_18870:
    v_19015 = stack[-3];
    v_19015 = qcar(v_19015);
    v_19017 = qcar(v_19015);
    goto v_18871;
v_18872:
    v_19015 = stack[-3];
    v_19015 = qcar(v_19015);
    v_19016 = qcdr(v_19015);
    goto v_18873;
v_18874:
    v_19015 = stack[0];
    goto v_18875;
v_18876:
    goto v_18870;
v_18871:
    goto v_18872;
v_18873:
    goto v_18874;
v_18875:
    v_19017 = list2star(v_19017, v_19016, v_19015);
    env = stack[-8];
    goto v_18863;
v_18864:
    v_19016 = qvalue(elt(env, 10)); // powlis!*
    goto v_18865;
v_18866:
    v_19015 = elt(env, 11); // replace
    goto v_18867;
v_18868:
    goto v_18862;
v_18863:
    goto v_18864;
v_18865:
    goto v_18866;
v_18867:
    fn = elt(env, 26); // xadd
    v_19015 = (*qfnn(fn))(fn, 3, v_19017, v_19016, v_19015);
    env = stack[-8];
    qvalue(elt(env, 10)) = v_19015; // powlis!*
    goto v_18822;
v_18824:
    v_19015 = stack[-4];
    if (v_19015 == nil) goto v_18888;
    else goto v_18886;
v_18888:
    goto v_18899;
v_18895:
    v_19015 = stack[0];
    v_19015 = qcar(v_19015);
    v_19016 = qcdr(v_19015);
    goto v_18896;
v_18897:
    v_19015 = lisp_true;
    goto v_18898;
v_18899:
    goto v_18895;
v_18896:
    goto v_18897;
v_18898:
    if (v_19016 == v_19015) goto v_18894;
    v_19015 = lisp_true;
    goto v_18892;
v_18894:
    v_19015 = qvalue(elt(env, 12)); // frasc!*
    goto v_18892;
    v_19015 = nil;
v_18892:
    if (v_19015 == nil) goto v_18890;
    else goto v_18886;
v_18890:
    goto v_18887;
v_18886:
    goto v_18915;
v_18909:
    goto v_18921;
v_18917:
    v_19015 = stack[-3];
    v_19016 = qcar(v_19015);
    goto v_18918;
v_18919:
    v_19015 = stack[0];
    goto v_18920;
v_18921:
    goto v_18917;
v_18918:
    goto v_18919;
v_18920:
    v_19017 = cons(v_19016, v_19015);
    env = stack[-8];
    goto v_18910;
v_18911:
    v_19016 = qvalue(elt(env, 13)); // powlis1!*
    goto v_18912;
v_18913:
    v_19015 = stack[-2];
    goto v_18914;
v_18915:
    goto v_18909;
v_18910:
    goto v_18911;
v_18912:
    goto v_18913;
v_18914:
    fn = elt(env, 26); // xadd
    v_19015 = (*qfnn(fn))(fn, 3, v_19017, v_19016, v_19015);
    env = stack[-8];
    qvalue(elt(env, 13)) = v_19015; // powlis1!*
    goto v_18822;
v_18887:
    v_19015 = stack[-2];
    if (v_19015 == nil) goto v_18931;
    else goto v_18932;
v_18931:
    goto v_18942;
v_18938:
    v_19015 = stack[-3];
    v_19015 = qcar(v_19015);
    v_19016 = qcar(v_19015);
    goto v_18939;
v_18940:
    v_19015 = qvalue(elt(env, 9)); // asymplis!*
    goto v_18941;
v_18942:
    goto v_18938;
v_18939:
    goto v_18940;
v_18941:
    v_19015 = Lassoc(nil, v_19016, v_19015);
    v_19016 = v_19015;
    if (v_19015 == nil) goto v_18936;
    else goto v_18937;
v_18936:
    v_19015 = nil;
    goto v_18935;
v_18937:
    goto v_18955;
v_18951:
    goto v_18952;
v_18953:
    v_19015 = stack[-3];
    v_19015 = qcar(v_19015);
    goto v_18954;
v_18955:
    goto v_18951;
v_18952:
    goto v_18953;
v_18954:
    v_19015 = (equal(v_19016, v_19015) ? lisp_true : nil);
    goto v_18935;
    v_19015 = nil;
v_18935:
    goto v_18930;
v_18932:
    v_19015 = nil;
    goto v_18930;
    v_19015 = nil;
v_18930:
    if (v_19015 == nil) goto v_18928;
    goto v_18968;
v_18964:
    v_19015 = stack[-3];
    v_19015 = qcar(v_19015);
    v_19016 = qcar(v_19015);
    goto v_18965;
v_18966:
    v_19015 = qvalue(elt(env, 9)); // asymplis!*
    goto v_18967;
v_18968:
    goto v_18964;
v_18965:
    goto v_18966;
v_18967:
    fn = elt(env, 27); // delasc
    v_19015 = (*qfn2(fn))(fn, v_19016, v_19015);
    env = stack[-8];
    qvalue(elt(env, 9)) = v_19015; // asymplis!*
    goto v_18822;
v_18928:
    goto v_18982;
v_18976:
    goto v_18990;
v_18984:
    v_19015 = stack[-3];
    v_19015 = qcar(v_19015);
    v_19017 = qcar(v_19015);
    goto v_18985;
v_18986:
    v_19015 = stack[-3];
    v_19015 = qcar(v_19015);
    v_19016 = qcdr(v_19015);
    goto v_18987;
v_18988:
    v_19015 = stack[0];
    goto v_18989;
v_18990:
    goto v_18984;
v_18985:
    goto v_18986;
v_18987:
    goto v_18988;
v_18989:
    v_19017 = list2star(v_19017, v_19016, v_19015);
    env = stack[-8];
    goto v_18977;
v_18978:
    v_19016 = qvalue(elt(env, 10)); // powlis!*
    goto v_18979;
v_18980:
    v_19015 = stack[-2];
    goto v_18981;
v_18982:
    goto v_18976;
v_18977:
    goto v_18978;
v_18979:
    goto v_18980;
v_18981:
    fn = elt(env, 26); // xadd
    v_19015 = (*qfnn(fn))(fn, 3, v_19017, v_19016, v_19015);
    env = stack[-8];
    qvalue(elt(env, 10)) = v_19015; // powlis!*
    v_19015 = stack[-2];
    if (v_19015 == nil) goto v_19003;
    goto v_19010;
v_19006:
    v_19015 = stack[-3];
    v_19015 = qcar(v_19015);
    v_19016 = qcar(v_19015);
    goto v_19007;
v_19008:
    v_19015 = qvalue(elt(env, 9)); // asymplis!*
    goto v_19009;
v_19010:
    goto v_19006;
v_19007:
    goto v_19008;
v_19009:
    fn = elt(env, 27); // delasc
    v_19015 = (*qfn2(fn))(fn, v_19016, v_19015);
    env = stack[-8];
    qvalue(elt(env, 9)) = v_19015; // asymplis!*
    goto v_19001;
v_19003:
v_19001:
    goto v_18822;
v_18822:
    goto v_18632;
v_18632:
    v_19015 = nil;
v_18452:
    return onevalue(v_19015);
}



setup_type const u33_setup[] =
{
    {"expand_rule",             CC_expand_rule, TOO_MANY_1,    WRONG_NO_1},
    {"formboollis",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formboollis},
    {"pasf_dt",                 CC_pasf_dt,     TOO_MANY_1,    WRONG_NO_1},
    {"sfto_vardeg",             TOO_FEW_2,      CC_sfto_vardeg,WRONG_NO_2},
    {"ev_revgradlexcomp",       TOO_FEW_2,      CC_ev_revgradlexcomp,WRONG_NO_2},
    {"minusml",                 CC_minusml,     TOO_MANY_1,    WRONG_NO_1},
    {"f2dip11",                 CC_f2dip11,     TOO_MANY_1,    WRONG_NO_1},
    {"xriterion_1",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xriterion_1},
    {"eqexpr",                  CC_eqexpr,      TOO_MANY_1,    WRONG_NO_1},
    {"comb",                    TOO_FEW_2,      CC_comb,       WRONG_NO_2},
    {"max-degree",              TOO_FEW_2,      CC_maxKdegree, WRONG_NO_2},
    {"chkrn*",                  CC_chkrnH,      TOO_MANY_1,    WRONG_NO_1},
    {"length_multiindex",       CC_length_multiindex,TOO_MANY_1,WRONG_NO_1},
    {"sfto_fsub1",              TOO_FEW_2,      CC_sfto_fsub1, WRONG_NO_2},
    {"ofsf_facequal*",          TOO_FEW_2,      CC_ofsf_facequalH,WRONG_NO_2},
    {"talp_noffcts",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_noffcts},
    {"pasf_susibinad",          TOO_FEW_2,      CC_pasf_susibinad,WRONG_NO_2},
    {"ev_sum",                  TOO_FEW_2,      CC_ev_sum,     WRONG_NO_2},
    {"multiminus",              CC_multiminus,  TOO_MANY_1,    WRONG_NO_1},
    {"dm-min",                  TOO_FEW_2,      CC_dmKmin,     WRONG_NO_2},
    {":dmtimeslst",             CC_Tdmtimeslst, TOO_MANY_1,    WRONG_NO_1},
    {"sign-of",                 CC_signKof,     TOO_MANY_1,    WRONG_NO_1},
    {"log_assignment",          TOO_FEW_2,      CC_log_assignment,WRONG_NO_2},
    {"arglength",               CC_arglength,   TOO_MANY_1,    WRONG_NO_1},
    {"*di2q",                   TOO_FEW_2,      CC_Hdi2q,      WRONG_NO_2},
    {"ra_l",                    CC_ra_l,        TOO_MANY_1,    WRONG_NO_1},
    {"lalr_extract_nonterminals",CC_lalr_extract_nonterminals,TOO_MANY_1,WRONG_NO_1},
    {"talp_atnum",              CC_talp_atnum,  TOO_MANY_1,    WRONG_NO_1},
    {"pasf_sisub",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pasf_sisub},
    {"innprodp2",               TOO_FEW_2,      CC_innprodp2,  WRONG_NO_2},
    {"omatpir",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_omatpir},
    {"mkempspmat",              TOO_FEW_2,      CC_mkempspmat, WRONG_NO_2},
    {"suchp",                   CC_suchp,       TOO_MANY_1,    WRONG_NO_1},
    {"dipequal",                TOO_FEW_2,      CC_dipequal,   WRONG_NO_2},
    {"*xadd",                   TOO_FEW_2,      CC_Hxadd,      WRONG_NO_2},
    {"simp-prop1",              TOO_FEW_2,      CC_simpKprop1, WRONG_NO_2},
    {"split_cov_cont_ids",      CC_split_cov_cont_ids,TOO_MANY_1,WRONG_NO_1},
    {"st_ad_numsorttree",       CC_st_ad_numsorttree,TOO_MANY_1,WRONG_NO_1},
    {"general-horner-rule-mod-p",WRONG_NO_NA,   WRONG_NO_NB,   (n_args *)CC_generalKhornerKruleKmodKp},
    {"gitimes:",                TOO_FEW_2,      CC_gitimesT,   WRONG_NO_2},
    {"*a2f",                    CC_Ha2f,        TOO_MANY_1,    WRONG_NO_1},
    {"letexprn",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_letexprn},
    {NULL, (one_args *)"u33", (two_args *)"113596 2658571 4027770", 0}
};

// end of generated code
