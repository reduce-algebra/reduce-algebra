
// $destdir/u29.c        Machine generated C code

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



// Code for dipnumcontent

static LispObject CC_dipnumcontent(LispObject env,
                         LispObject v_15752, LispObject v_15753)
{
    env = qenv(env);
    LispObject v_15789, v_15790;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15753,v_15752);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15752,v_15753);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_15753;
    v_15789 = v_15752;
// end of prologue
// Binding d
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = v_15789; // d
v_15762:
    v_15789 = stack[-1];
    fn = elt(env, 2); // bcone!?
    v_15789 = (*qfn1(fn))(fn, v_15789);
    env = stack[-3];
    if (v_15789 == nil) goto v_15767;
    else goto v_15765;
v_15767:
    v_15789 = qvalue(elt(env, 1)); // d
    if (v_15789 == nil) goto v_15765;
    goto v_15766;
v_15765:
    v_15789 = stack[-1];
    goto v_15761;
v_15766:
    v_15789 = qvalue(elt(env, 1)); // d
    v_15789 = qcdr(v_15789);
    v_15789 = qcdr(v_15789);
    stack[0] = v_15789;
    goto v_15783;
v_15779:
    v_15790 = stack[-1];
    goto v_15780;
v_15781:
    v_15789 = qvalue(elt(env, 1)); // d
    v_15789 = qcdr(v_15789);
    v_15789 = qcar(v_15789);
    goto v_15782;
v_15783:
    goto v_15779;
v_15780:
    goto v_15781;
v_15782:
    fn = elt(env, 3); // vbcgcd
    v_15789 = (*qfn2(fn))(fn, v_15790, v_15789);
    env = stack[-3];
    stack[-1] = v_15789;
    v_15789 = stack[0];
    qvalue(elt(env, 1)) = v_15789; // d
    goto v_15762;
    v_15789 = nil;
v_15761:
    ;}  // end of a binding scope
    return onevalue(v_15789);
}



// Code for groebsavelterm

static LispObject CC_groebsavelterm(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15779, v_15780;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15780 = v_15751;
// end of prologue
    v_15779 = qvalue(elt(env, 1)); // !*groelterms
    if (v_15779 == nil) goto v_15756;
    v_15779 = v_15780;
    if (v_15779 == nil) goto v_15762;
    else goto v_15763;
v_15762:
    v_15779 = lisp_true;
    goto v_15761;
v_15763:
    v_15779 = v_15780;
    v_15779 = qcdr(v_15779);
    v_15779 = qcdr(v_15779);
    v_15779 = qcdr(v_15779);
    v_15779 = qcar(v_15779);
    v_15779 = (v_15779 == nil ? lisp_true : nil);
    goto v_15761;
    v_15779 = nil;
v_15761:
    if (v_15779 == nil) goto v_15759;
    else goto v_15756;
v_15759:
    v_15779 = v_15780;
    v_15779 = qcdr(v_15779);
    v_15779 = qcdr(v_15779);
    v_15779 = qcar(v_15779);
    {
        fn = elt(env, 2); // groebsaveltermbc
        return (*qfn1(fn))(fn, v_15779);
    }
v_15756:
    v_15779 = nil;
    return onevalue(v_15779);
}



// Code for vevstrictlydivides!?

static LispObject CC_vevstrictlydividesW(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15776, v_15777, v_15778, v_15779;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15778 = v_15752;
    v_15779 = v_15751;
// end of prologue
    goto v_15762;
v_15758:
    v_15777 = v_15779;
    goto v_15759;
v_15760:
    v_15776 = v_15778;
    goto v_15761;
v_15762:
    goto v_15758;
v_15759:
    goto v_15760;
v_15761:
    if (equal(v_15777, v_15776)) goto v_15757;
    goto v_15770;
v_15766:
    v_15776 = v_15778;
    goto v_15767;
v_15768:
    v_15777 = v_15779;
    goto v_15769;
v_15770:
    goto v_15766;
v_15767:
    goto v_15768;
v_15769:
    {
        fn = elt(env, 1); // vevmtest!?
        return (*qfn2(fn))(fn, v_15776, v_15777);
    }
v_15757:
    v_15776 = nil;
    goto v_15755;
    v_15776 = nil;
v_15755:
    return onevalue(v_15776);
}



// Code for ordexp

static LispObject CC_ordexp(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15800, v_15801, v_15802, v_15803;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15801 = v_15752;
    v_15802 = v_15751;
// end of prologue
v_15756:
    v_15800 = v_15802;
    if (v_15800 == nil) goto v_15759;
    else goto v_15760;
v_15759:
    v_15800 = lisp_true;
    goto v_15755;
v_15760:
    goto v_15769;
v_15765:
    v_15800 = v_15802;
    v_15803 = qcar(v_15800);
    goto v_15766;
v_15767:
    v_15800 = v_15801;
    v_15800 = qcar(v_15800);
    goto v_15768;
v_15769:
    goto v_15765;
v_15766:
    goto v_15767;
v_15768:
    if (v_15803 == v_15800) goto v_15763;
    else goto v_15764;
v_15763:
    v_15800 = v_15802;
    v_15800 = qcdr(v_15800);
    v_15802 = v_15800;
    v_15800 = v_15801;
    v_15800 = qcdr(v_15800);
    v_15801 = v_15800;
    goto v_15756;
v_15764:
    v_15800 = v_15802;
    v_15800 = qcar(v_15800);
    if (v_15800 == nil) goto v_15778;
    else goto v_15779;
v_15778:
    v_15800 = nil;
    goto v_15755;
v_15779:
    v_15800 = v_15801;
    v_15800 = qcar(v_15800);
    if (v_15800 == nil) goto v_15783;
    else goto v_15784;
v_15783:
    v_15800 = lisp_true;
    goto v_15755;
v_15784:
    goto v_15795;
v_15791:
    v_15800 = v_15802;
    v_15800 = qcar(v_15800);
    goto v_15792;
v_15793:
    v_15801 = qcar(v_15801);
    goto v_15794;
v_15795:
    goto v_15791;
v_15792:
    goto v_15793;
v_15794:
    {
        fn = elt(env, 1); // ordop
        return (*qfn2(fn))(fn, v_15800, v_15801);
    }
    v_15800 = nil;
v_15755:
    return onevalue(v_15800);
}



// Code for l!-subst

static LispObject CC_lKsubst(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15799, v_15800, v_15801;
    LispObject fn;
    LispObject v_15753, v_15752, v_15751;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "l-subst");
    va_start(aa, nargs);
    v_15751 = va_arg(aa, LispObject);
    v_15752 = va_arg(aa, LispObject);
    v_15753 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15753,v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15751,v_15752,v_15753);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15753;
    stack[-1] = v_15752;
    stack[-2] = v_15751;
// end of prologue
    v_15801 = nil;
v_15758:
    v_15799 = stack[0];
    if (v_15799 == nil) goto v_15761;
    else goto v_15762;
v_15761:
    v_15799 = v_15801;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_15799);
    }
v_15762:
    goto v_15772;
v_15768:
    v_15800 = stack[-1];
    goto v_15769;
v_15770:
    v_15799 = stack[0];
    v_15799 = qcar(v_15799);
    goto v_15771;
v_15772:
    goto v_15768;
v_15769:
    goto v_15770;
v_15771:
    if (equal(v_15800, v_15799)) goto v_15766;
    else goto v_15767;
v_15766:
    goto v_15781;
v_15777:
    v_15799 = stack[-2];
    goto v_15778;
v_15779:
    v_15800 = v_15801;
    goto v_15780;
v_15781:
    goto v_15777;
v_15778:
    goto v_15779;
v_15780:
    v_15799 = cons(v_15799, v_15800);
    env = stack[-3];
    v_15801 = v_15799;
    v_15799 = stack[0];
    v_15799 = qcdr(v_15799);
    stack[0] = v_15799;
    goto v_15758;
v_15767:
    goto v_15793;
v_15789:
    v_15799 = stack[0];
    v_15799 = qcar(v_15799);
    goto v_15790;
v_15791:
    v_15800 = v_15801;
    goto v_15792;
v_15793:
    goto v_15789;
v_15790:
    goto v_15791;
v_15792:
    v_15799 = cons(v_15799, v_15800);
    env = stack[-3];
    v_15801 = v_15799;
    v_15799 = stack[0];
    v_15799 = qcdr(v_15799);
    stack[0] = v_15799;
    goto v_15758;
    v_15799 = nil;
    return onevalue(v_15799);
}



// Code for formde

static LispObject CC_formde(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15820, v_15821, v_15822;
    LispObject fn;
    LispObject v_15753, v_15752, v_15751;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formde");
    va_start(aa, nargs);
    v_15751 = va_arg(aa, LispObject);
    v_15752 = va_arg(aa, LispObject);
    v_15753 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15753,v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15751,v_15752,v_15753);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_15753;
    stack[-5] = v_15752;
    v_15820 = v_15751;
// end of prologue
    goto v_15762;
v_15756:
    goto v_15772;
v_15764:
    stack[-6] = elt(env, 1); // procedure
    goto v_15765;
v_15766:
    v_15821 = v_15820;
    v_15821 = qcdr(v_15821);
    stack[-3] = qcar(v_15821);
    goto v_15767;
v_15768:
    stack[-2] = elt(env, 2); // symbolic
    goto v_15769;
v_15770:
    goto v_15785;
v_15779:
    stack[-1] = elt(env, 3); // expr
    goto v_15780;
v_15781:
    v_15821 = v_15820;
    v_15821 = qcdr(v_15821);
    v_15821 = qcdr(v_15821);
    stack[0] = qcar(v_15821);
    goto v_15782;
v_15783:
    v_15821 = v_15820;
    v_15821 = qcdr(v_15821);
    v_15821 = qcdr(v_15821);
    v_15821 = qcdr(v_15821);
    v_15821 = qcdr(v_15821);
    if (v_15821 == nil) goto v_15793;
    else goto v_15794;
v_15793:
    v_15820 = qcdr(v_15820);
    v_15820 = qcdr(v_15820);
    v_15820 = qcdr(v_15820);
    v_15820 = qcar(v_15820);
    goto v_15792;
v_15794:
    goto v_15812;
v_15808:
    v_15821 = elt(env, 4); // progn
    goto v_15809;
v_15810:
    v_15820 = qcdr(v_15820);
    v_15820 = qcdr(v_15820);
    v_15820 = qcdr(v_15820);
    goto v_15811;
v_15812:
    goto v_15808;
v_15809:
    goto v_15810;
v_15811:
    v_15820 = cons(v_15821, v_15820);
    env = stack[-7];
    goto v_15792;
    v_15820 = nil;
v_15792:
    goto v_15784;
v_15785:
    goto v_15779;
v_15780:
    goto v_15781;
v_15782:
    goto v_15783;
v_15784:
    v_15820 = list3(stack[-1], stack[0], v_15820);
    env = stack[-7];
    goto v_15771;
v_15772:
    goto v_15764;
v_15765:
    goto v_15766;
v_15767:
    goto v_15768;
v_15769:
    goto v_15770;
v_15771:
    v_15822 = list3star(stack[-6], stack[-3], stack[-2], v_15820);
    env = stack[-7];
    goto v_15757;
v_15758:
    v_15821 = stack[-5];
    goto v_15759;
v_15760:
    v_15820 = stack[-4];
    goto v_15761;
v_15762:
    goto v_15756;
v_15757:
    goto v_15758;
v_15759:
    goto v_15760;
v_15761:
    {
        fn = elt(env, 5); // formproc
        return (*qfnn(fn))(fn, 3, v_15822, v_15821, v_15820);
    }
}



// Code for sqhorner!*

static LispObject CC_sqhornerH(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15784, v_15785;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_15751;
// end of prologue
    v_15784 = qvalue(elt(env, 1)); // !*horner
    if (v_15784 == nil) goto v_15755;
    else goto v_15756;
v_15755:
    v_15784 = stack[-1];
    goto v_15754;
v_15756:
    goto v_15766;
v_15762:
    v_15785 = qvalue(elt(env, 2)); // ordl!*
    goto v_15763;
v_15764:
    v_15784 = qvalue(elt(env, 3)); // kord!*
    goto v_15765;
v_15766:
    goto v_15762;
v_15763:
    goto v_15764;
v_15765:
    v_15784 = Lappend(nil, v_15785, v_15784);
    env = stack[-3];
// Binding kord!*
// FLUIDBIND: reloadenv=3 litvec-offset=3 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 3, -2);
    qvalue(elt(env, 3)) = v_15784; // kord!*
    goto v_15776;
v_15772:
    v_15784 = stack[-1];
    v_15784 = qcar(v_15784);
    fn = elt(env, 4); // reorder
    stack[0] = (*qfn1(fn))(fn, v_15784);
    env = stack[-3];
    goto v_15773;
v_15774:
    v_15784 = stack[-1];
    v_15784 = qcdr(v_15784);
    fn = elt(env, 4); // reorder
    v_15784 = (*qfn1(fn))(fn, v_15784);
    env = stack[-3];
    fn = elt(env, 5); // hornerf
    v_15784 = (*qfn1(fn))(fn, v_15784);
    env = stack[-3];
    goto v_15775;
v_15776:
    goto v_15772;
v_15773:
    goto v_15774;
v_15775:
    v_15784 = cons(stack[0], v_15784);
    env = stack[-3];
    fn = elt(env, 6); // hornersq
    v_15784 = (*qfn1(fn))(fn, v_15784);
    ;}  // end of a binding scope
    goto v_15754;
    v_15784 = nil;
v_15754:
    return onevalue(v_15784);
}



// Code for no_dum_varp

static LispObject CC_no_dum_varp(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15787, v_15788;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_15751;
// end of prologue
    v_15787 = stack[0];
    v_15787 = qcdr(v_15787);
    if (v_15787 == nil) goto v_15759;
    else goto v_15760;
v_15759:
    v_15787 = lisp_true;
    goto v_15758;
v_15760:
    goto v_15770;
v_15766:
    goto v_15776;
v_15772:
    v_15787 = stack[0];
    v_15788 = qcdr(v_15787);
    goto v_15773;
v_15774:
    v_15787 = elt(env, 1); // list
    goto v_15775;
v_15776:
    goto v_15772;
v_15773:
    goto v_15774;
v_15775:
    fn = elt(env, 2); // splitlist!:
    v_15788 = (*qfn2(fn))(fn, v_15788, v_15787);
    goto v_15767;
v_15768:
    v_15787 = stack[0];
    v_15787 = qcdr(v_15787);
    goto v_15769;
v_15770:
    goto v_15766;
v_15767:
    goto v_15768;
v_15769:
    v_15787 = (equal(v_15788, v_15787) ? lisp_true : nil);
    goto v_15758;
    v_15787 = nil;
v_15758:
    if (v_15787 == nil) goto v_15756;
    v_15787 = lisp_true;
    goto v_15754;
v_15756:
    v_15787 = nil;
    goto v_15754;
    v_15787 = nil;
v_15754:
    return onevalue(v_15787);
}



// Code for proper!-simpsqrt

static LispObject CC_properKsimpsqrt(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15762, v_15763;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15762 = v_15751;
// end of prologue
    goto v_15759;
v_15755:
    v_15763 = v_15762;
    goto v_15756;
v_15757:
    v_15762 = elt(env, 0); // proper!-simpsqrt
    goto v_15758;
v_15759:
    goto v_15755;
v_15756:
    goto v_15757;
v_15758:
    fn = elt(env, 1); // carx
    v_15762 = (*qfn2(fn))(fn, v_15763, v_15762);
    env = stack[0];
    {
        fn = elt(env, 2); // simpsqrti
        return (*qfn1(fn))(fn, v_15762);
    }
}



// Code for delasc

static LispObject CC_delasc(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15802, v_15803;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15751,v_15752);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15752;
    stack[-1] = v_15751;
// end of prologue
    stack[-2] = nil;
v_15759:
    v_15802 = stack[0];
    if (v_15802 == nil) goto v_15762;
    else goto v_15763;
v_15762:
    goto v_15758;
v_15763:
    v_15802 = stack[0];
    v_15802 = qcar(v_15802);
    if (!consp(v_15802)) goto v_15772;
    else goto v_15773;
v_15772:
    v_15802 = lisp_true;
    goto v_15771;
v_15773:
    goto v_15784;
v_15780:
    v_15803 = stack[-1];
    goto v_15781;
v_15782:
    v_15802 = stack[0];
    v_15802 = qcar(v_15802);
    v_15802 = qcar(v_15802);
    goto v_15783;
v_15784:
    goto v_15780;
v_15781:
    goto v_15782;
v_15783:
    v_15802 = Lneq(nil, v_15803, v_15802);
    env = stack[-3];
    goto v_15771;
    v_15802 = nil;
v_15771:
    if (v_15802 == nil) goto v_15769;
    goto v_15794;
v_15790:
    v_15802 = stack[0];
    v_15803 = qcar(v_15802);
    goto v_15791;
v_15792:
    v_15802 = stack[-2];
    goto v_15793;
v_15794:
    goto v_15790;
v_15791:
    goto v_15792;
v_15793:
    v_15802 = cons(v_15803, v_15802);
    env = stack[-3];
    stack[-2] = v_15802;
    goto v_15767;
v_15769:
v_15767:
    v_15802 = stack[0];
    v_15802 = qcdr(v_15802);
    stack[0] = v_15802;
    goto v_15759;
v_15758:
    v_15802 = stack[-2];
        return Lnreverse(nil, v_15802);
    return onevalue(v_15802);
}



// Code for sortedtriplelistinsert

static LispObject CC_sortedtriplelistinsert(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15830, v_15831, v_15832;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15751,v_15752);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_15752;
    v_15832 = v_15751;
// end of prologue
    goto v_15762;
v_15758:
    v_15831 = stack[-1];
    goto v_15759;
v_15760:
    v_15830 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15761;
v_15762:
    goto v_15758;
v_15759:
    goto v_15760;
v_15761:
    v_15830 = *(LispObject *)((char *)v_15831 + (CELL-TAG_VECTOR) + (((intptr_t)v_15830-TAG_FIXNUM)/(16/CELL)));
    v_15830 = qcar(v_15830);
    stack[0] = v_15830;
    v_15830 = v_15832;
    stack[-2] = v_15830;
v_15770:
    v_15830 = stack[-2];
    v_15830 = qcar(v_15830);
    if (v_15830 == nil) goto v_15773;
    goto v_15783;
v_15779:
    goto v_15789;
v_15785:
    goto v_15794;
v_15790:
    v_15830 = stack[-2];
    v_15831 = qcar(v_15830);
    goto v_15791;
v_15792:
    v_15830 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15793;
v_15794:
    goto v_15790;
v_15791:
    goto v_15792;
v_15793:
    v_15830 = *(LispObject *)((char *)v_15831 + (CELL-TAG_VECTOR) + (((intptr_t)v_15830-TAG_FIXNUM)/(16/CELL)));
    v_15831 = qcar(v_15830);
    goto v_15786;
v_15787:
    v_15830 = stack[0];
    goto v_15788;
v_15789:
    goto v_15785;
v_15786:
    goto v_15787;
v_15788:
    fn = elt(env, 1); // monomcompare
    v_15831 = (*qfn2(fn))(fn, v_15831, v_15830);
    env = stack[-3];
    goto v_15780;
v_15781:
    v_15830 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15782;
v_15783:
    goto v_15779;
v_15780:
    goto v_15781;
v_15782:
    if (v_15831 == v_15830) goto v_15773;
    goto v_15774;
v_15773:
    goto v_15769;
v_15774:
    v_15830 = stack[-2];
    v_15830 = qcdr(v_15830);
    stack[-2] = v_15830;
    goto v_15770;
v_15769:
    goto v_15811;
v_15807:
    goto v_15817;
v_15813:
    stack[0] = stack[-2];
    goto v_15814;
v_15815:
    goto v_15824;
v_15820:
    v_15830 = stack[-2];
    v_15831 = qcar(v_15830);
    goto v_15821;
v_15822:
    v_15830 = stack[-2];
    v_15830 = qcdr(v_15830);
    goto v_15823;
v_15824:
    goto v_15820;
v_15821:
    goto v_15822;
v_15823:
    v_15830 = cons(v_15831, v_15830);
    env = stack[-3];
    goto v_15816;
v_15817:
    goto v_15813;
v_15814:
    goto v_15815;
v_15816:
    v_15831 = Lrplacd(nil, stack[0], v_15830);
    env = stack[-3];
    goto v_15808;
v_15809:
    v_15830 = stack[-1];
    goto v_15810;
v_15811:
    goto v_15807;
v_15808:
    goto v_15809;
v_15810:
    v_15830 = Lrplaca(nil, v_15831, v_15830);
    v_15830 = nil;
    return onevalue(v_15830);
}



// Code for add!-degrees

static LispObject CC_addKdegrees(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15819, v_15820;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15751,v_15752);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_15752;
    stack[-4] = v_15751;
// end of prologue
    stack[-5] = nil;
v_15762:
    v_15819 = stack[-4];
    if (v_15819 == nil) goto v_15765;
    else goto v_15766;
v_15765:
    goto v_15761;
v_15766:
    v_15819 = stack[-4];
    v_15819 = qcar(v_15819);
    stack[-2] = v_15819;
    v_15819 = stack[-3];
    v_15819 = qcar(v_15819);
    stack[-1] = v_15819;
    v_15819 = nil;
    stack[0] = v_15819;
v_15776:
    v_15819 = stack[-2];
    if (v_15819 == nil) goto v_15779;
    else goto v_15780;
v_15779:
    goto v_15775;
v_15780:
    goto v_15788;
v_15784:
    goto v_15794;
v_15790:
    v_15819 = stack[-2];
    v_15820 = qcar(v_15819);
    goto v_15791;
v_15792:
    v_15819 = stack[-1];
    v_15819 = qcar(v_15819);
    goto v_15793;
v_15794:
    goto v_15790;
v_15791:
    goto v_15792;
v_15793:
    fn = elt(env, 1); // tayexp!-plus2
    v_15820 = (*qfn2(fn))(fn, v_15820, v_15819);
    env = stack[-6];
    goto v_15785;
v_15786:
    v_15819 = stack[0];
    goto v_15787;
v_15788:
    goto v_15784;
v_15785:
    goto v_15786;
v_15787:
    v_15819 = cons(v_15820, v_15819);
    env = stack[-6];
    stack[0] = v_15819;
    v_15819 = stack[-2];
    v_15819 = qcdr(v_15819);
    stack[-2] = v_15819;
    v_15819 = stack[-1];
    v_15819 = qcdr(v_15819);
    stack[-1] = v_15819;
    goto v_15776;
v_15775:
    goto v_15809;
v_15805:
    v_15819 = stack[0];
    v_15820 = Lnreverse(nil, v_15819);
    env = stack[-6];
    goto v_15806;
v_15807:
    v_15819 = stack[-5];
    goto v_15808;
v_15809:
    goto v_15805;
v_15806:
    goto v_15807;
v_15808:
    v_15819 = cons(v_15820, v_15819);
    env = stack[-6];
    stack[-5] = v_15819;
    v_15819 = stack[-4];
    v_15819 = qcdr(v_15819);
    stack[-4] = v_15819;
    v_15819 = stack[-3];
    v_15819 = qcdr(v_15819);
    stack[-3] = v_15819;
    goto v_15762;
v_15761:
    v_15819 = stack[-5];
        return Lnreverse(nil, v_15819);
    return onevalue(v_15819);
}



// Code for qqe_arg!-check!-q

static LispObject CC_qqe_argKcheckKq(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15803;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15751;
// end of prologue
    v_15803 = stack[0];
    fn = elt(env, 1); // qqe_id!-nyt!-branchq
    v_15803 = (*qfn1(fn))(fn, v_15803);
    env = stack[-1];
    if (v_15803 == nil) goto v_15757;
    else goto v_15758;
v_15757:
    v_15803 = nil;
    goto v_15754;
v_15758:
    v_15803 = stack[0];
    if (!consp(v_15803)) goto v_15766;
    else goto v_15767;
v_15766:
    v_15803 = stack[0];
    v_15803 = (is_number(v_15803) ? lisp_true : nil);
    v_15803 = (v_15803 == nil ? lisp_true : nil);
    goto v_15765;
v_15767:
    v_15803 = nil;
    goto v_15765;
    v_15803 = nil;
v_15765:
    if (v_15803 == nil) goto v_15763;
    v_15803 = stack[0];
    fn = elt(env, 2); // qqe_btidp
    v_15803 = (*qfn1(fn))(fn, v_15803);
    env = stack[-1];
    if (v_15803 == nil) goto v_15778;
    v_15803 = nil;
    goto v_15754;
v_15778:
    v_15803 = stack[0];
    fn = elt(env, 3); // qqe_nytidp
    v_15803 = (*qfn1(fn))(fn, v_15803);
    env = stack[-1];
    if (v_15803 == nil) goto v_15783;
    v_15803 = stack[0];
    fn = elt(env, 4); // qqe_qtid
    v_15803 = (*qfn1(fn))(fn, v_15803);
    env = stack[-1];
    v_15803 = stack[0];
    fn = elt(env, 5); // qqe_add2rollbackids
    v_15803 = (*qfn1(fn))(fn, v_15803);
    v_15803 = lisp_true;
    goto v_15754;
v_15783:
    v_15803 = lisp_true;
    goto v_15754;
    goto v_15756;
v_15763:
    v_15803 = stack[0];
    if (is_number(v_15803)) goto v_15797;
    v_15803 = stack[0];
    fn = elt(env, 6); // qqe_arg!-check
    v_15803 = (*qfn1(fn))(fn, v_15803);
    v_15803 = lisp_true;
    goto v_15754;
v_15797:
v_15756:
    v_15803 = nil;
v_15754:
    return onevalue(v_15803);
}



// Code for cl_susiupdknowl

static LispObject CC_cl_susiupdknowl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15814, v_15815, v_15816, v_15817;
    LispObject fn;
    LispObject v_15754, v_15753, v_15752, v_15751;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_susiupdknowl");
    va_start(aa, nargs);
    v_15751 = va_arg(aa, LispObject);
    v_15752 = va_arg(aa, LispObject);
    v_15753 = va_arg(aa, LispObject);
    v_15754 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_15754,v_15753,v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_15751,v_15752,v_15753,v_15754);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15754;
    v_15814 = v_15753;
    stack[-1] = v_15752;
    stack[-2] = v_15751;
// end of prologue
    stack[-3] = nil;
v_15761:
    v_15815 = stack[-1];
    if (v_15815 == nil) goto v_15764;
    else goto v_15765;
v_15764:
    goto v_15760;
v_15765:
    v_15815 = stack[-1];
    v_15815 = qcar(v_15815);
    stack[-3] = v_15815;
    v_15815 = stack[-1];
    v_15815 = qcdr(v_15815);
    stack[-1] = v_15815;
    goto v_15781;
v_15773:
    v_15817 = stack[-2];
    goto v_15774;
v_15775:
    v_15816 = stack[-3];
    goto v_15776;
v_15777:
    v_15815 = v_15814;
    goto v_15778;
v_15779:
    v_15814 = stack[0];
    goto v_15780;
v_15781:
    goto v_15773;
v_15774:
    goto v_15775;
v_15776:
    goto v_15777;
v_15778:
    goto v_15779;
v_15780:
    fn = elt(env, 3); // cl_susiupdknowl1
    v_15814 = (*qfnn(fn))(fn, 4, v_15817, v_15816, v_15815, v_15814);
    env = stack[-4];
    goto v_15794;
v_15790:
    v_15816 = v_15814;
    goto v_15791;
v_15792:
    v_15815 = elt(env, 1); // false
    goto v_15793;
v_15794:
    goto v_15790;
v_15791:
    goto v_15792;
v_15793:
    if (v_15816 == v_15815) goto v_15788;
    else goto v_15789;
v_15788:
    v_15815 = nil;
    stack[-1] = v_15815;
    v_15815 = elt(env, 2); // break
    stack[-3] = v_15815;
    goto v_15787;
v_15789:
v_15787:
    goto v_15761;
v_15760:
    goto v_15807;
v_15803:
    v_15816 = stack[-3];
    goto v_15804;
v_15805:
    v_15815 = elt(env, 2); // break
    goto v_15806;
v_15807:
    goto v_15803;
v_15804:
    goto v_15805;
v_15806:
    if (v_15816 == v_15815) goto v_15801;
    else goto v_15802;
v_15801:
    v_15814 = elt(env, 1); // false
    goto v_15758;
v_15802:
    goto v_15758;
    v_15814 = nil;
v_15758:
    return onevalue(v_15814);
}



// Code for cnrd

static LispObject CC_cnrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15952, v_15953, v_15954;
    LispObject fn;
    argcheck(nargs, 0, "cnrd");
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
    goto v_15766;
v_15762:
    v_15953 = qvalue(elt(env, 1)); // atts
    goto v_15763;
v_15764:
    v_15952 = elt(env, 2); // type
    goto v_15765;
v_15766:
    goto v_15762;
v_15763:
    goto v_15764;
v_15765:
    fn = elt(env, 15); // find
    v_15952 = (*qfn2(fn))(fn, v_15953, v_15952);
    env = stack[-5];
    v_15952 = Lintern(nil, v_15952);
    env = stack[-5];
    stack[-1] = v_15952;
    goto v_15774;
v_15770:
    v_15953 = qvalue(elt(env, 1)); // atts
    goto v_15771;
v_15772:
    v_15952 = elt(env, 3); // base
    goto v_15773;
v_15774:
    goto v_15770;
v_15771:
    goto v_15772;
v_15773:
    fn = elt(env, 15); // find
    v_15952 = (*qfn2(fn))(fn, v_15953, v_15952);
    env = stack[-5];
    stack[0] = v_15952;
    fn = elt(env, 16); // lex
    v_15952 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_15952 = qvalue(elt(env, 4)); // char
    stack[-4] = v_15952;
    fn = elt(env, 16); // lex
    v_15952 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_15788;
v_15784:
    v_15953 = stack[-1];
    goto v_15785;
v_15786:
    v_15952 = elt(env, 5); // constant
    goto v_15787;
v_15788:
    goto v_15784;
v_15785:
    goto v_15786;
v_15787:
    if (v_15953 == v_15952) goto v_15782;
    else goto v_15783;
v_15782:
    v_15952 = stack[-4];
    {
        fn = elt(env, 17); // compress!*
        return (*qfn1(fn))(fn, v_15952);
    }
v_15783:
    v_15952 = stack[-1];
    if (v_15952 == nil) goto v_15795;
    else goto v_15796;
v_15795:
    v_15952 = stack[-4];
    {
        fn = elt(env, 17); // compress!*
        return (*qfn1(fn))(fn, v_15952);
    }
v_15796:
    goto v_15808;
v_15804:
    v_15953 = stack[-1];
    goto v_15805;
v_15806:
    v_15952 = elt(env, 6); // (real integer)
    goto v_15807;
v_15808:
    goto v_15804;
v_15805:
    goto v_15806;
v_15807:
    v_15952 = Lmember(nil, v_15953, v_15952);
    if (v_15952 == nil) goto v_15803;
    v_15952 = stack[0];
    if (v_15952 == nil) goto v_15814;
    else goto v_15815;
v_15814:
    v_15952 = stack[-4];
    {
        fn = elt(env, 17); // compress!*
        return (*qfn1(fn))(fn, v_15952);
    }
v_15815:
    goto v_15828;
v_15822:
    stack[-3] = elt(env, 7); // based_integer
    goto v_15823;
v_15824:
    stack[-2] = nil;
    goto v_15825;
v_15826:
    goto v_15838;
v_15832:
    stack[-1] = stack[0];
    goto v_15833;
v_15834:
    goto v_15847;
v_15841:
    stack[0] = elt(env, 8); // string
    goto v_15842;
v_15843:
    v_15952 = stack[-4];
    fn = elt(env, 17); // compress!*
    v_15953 = (*qfn1(fn))(fn, v_15952);
    env = stack[-5];
    goto v_15844;
v_15845:
    v_15952 = nil;
    goto v_15846;
v_15847:
    goto v_15841;
v_15842:
    goto v_15843;
v_15844:
    goto v_15845;
v_15846:
    v_15953 = list2star(stack[0], v_15953, v_15952);
    env = stack[-5];
    goto v_15835;
v_15836:
    v_15952 = nil;
    goto v_15837;
v_15838:
    goto v_15832;
v_15833:
    goto v_15834;
v_15835:
    goto v_15836;
v_15837:
    v_15952 = list2star(stack[-1], v_15953, v_15952);
    goto v_15827;
v_15828:
    goto v_15822;
v_15823:
    goto v_15824;
v_15825:
    goto v_15826;
v_15827:
    {
        LispObject v_15960 = stack[-3];
        LispObject v_15961 = stack[-2];
        return list2star(v_15960, v_15961, v_15952);
    }
    goto v_15801;
v_15803:
v_15801:
    goto v_15861;
v_15857:
    v_15952 = stack[-1];
    v_15953 = Lintern(nil, v_15952);
    env = stack[-5];
    goto v_15858;
v_15859:
    v_15952 = elt(env, 9); // (rational complex!-cartesian complex!-polar)
    goto v_15860;
v_15861:
    goto v_15857;
v_15858:
    goto v_15859;
v_15860:
    v_15952 = Lmember(nil, v_15953, v_15952);
    if (v_15952 == nil) goto v_15856;
    fn = elt(env, 18); // seprd
    v_15952 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[-2] = v_15952;
    goto v_15875;
v_15871:
    v_15953 = stack[-1];
    goto v_15872;
v_15873:
    v_15952 = elt(env, 10); // rational
    goto v_15874;
v_15875:
    goto v_15871;
v_15872:
    goto v_15873;
v_15874:
    if (v_15953 == v_15952) goto v_15869;
    else goto v_15870;
v_15869:
    fn = elt(env, 16); // lex
    v_15952 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_15884;
v_15880:
    v_15952 = stack[-4];
    fn = elt(env, 17); // compress!*
    v_15953 = (*qfn1(fn))(fn, v_15952);
    env = stack[-5];
    goto v_15881;
v_15882:
    v_15952 = stack[-2];
    goto v_15883;
v_15884:
    goto v_15880;
v_15881:
    goto v_15882;
v_15883:
    {
        fn = elt(env, 10); // rational
        return (*qfn2(fn))(fn, v_15953, v_15952);
    }
v_15870:
    goto v_15894;
v_15890:
    v_15953 = stack[-1];
    goto v_15891;
v_15892:
    v_15952 = elt(env, 11); // complex!-cartesian
    goto v_15893;
v_15894:
    goto v_15890;
v_15891:
    goto v_15892;
v_15893:
    if (v_15953 == v_15952) goto v_15888;
    else goto v_15889;
v_15888:
    fn = elt(env, 16); // lex
    v_15952 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_15905;
v_15899:
    stack[-1] = elt(env, 12); // complex_cartesian
    goto v_15900;
v_15901:
    stack[0] = nil;
    goto v_15902;
v_15903:
    goto v_15915;
v_15909:
    v_15952 = stack[-4];
    fn = elt(env, 17); // compress!*
    v_15954 = (*qfn1(fn))(fn, v_15952);
    env = stack[-5];
    goto v_15910;
v_15911:
    v_15953 = stack[-2];
    goto v_15912;
v_15913:
    v_15952 = nil;
    goto v_15914;
v_15915:
    goto v_15909;
v_15910:
    goto v_15911;
v_15912:
    goto v_15913;
v_15914:
    v_15952 = list2star(v_15954, v_15953, v_15952);
    goto v_15904;
v_15905:
    goto v_15899;
v_15900:
    goto v_15901;
v_15902:
    goto v_15903;
v_15904:
    {
        LispObject v_15962 = stack[-1];
        LispObject v_15963 = stack[0];
        return list2star(v_15962, v_15963, v_15952);
    }
v_15889:
    goto v_15926;
v_15922:
    v_15953 = stack[-1];
    goto v_15923;
v_15924:
    v_15952 = elt(env, 13); // complex!-polar
    goto v_15925;
v_15926:
    goto v_15922;
v_15923:
    goto v_15924;
v_15925:
    if (v_15953 == v_15952) goto v_15920;
    else goto v_15921;
v_15920:
    fn = elt(env, 16); // lex
    v_15952 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_15937;
v_15931:
    stack[-1] = elt(env, 14); // complex_polar
    goto v_15932;
v_15933:
    stack[0] = nil;
    goto v_15934;
v_15935:
    goto v_15947;
v_15941:
    v_15952 = stack[-4];
    fn = elt(env, 17); // compress!*
    v_15954 = (*qfn1(fn))(fn, v_15952);
    env = stack[-5];
    goto v_15942;
v_15943:
    v_15953 = stack[-2];
    goto v_15944;
v_15945:
    v_15952 = nil;
    goto v_15946;
v_15947:
    goto v_15941;
v_15942:
    goto v_15943;
v_15944:
    goto v_15945;
v_15946:
    v_15952 = list2star(v_15954, v_15953, v_15952);
    goto v_15936;
v_15937:
    goto v_15931;
v_15932:
    goto v_15933;
v_15934:
    goto v_15935;
v_15936:
    {
        LispObject v_15964 = stack[-1];
        LispObject v_15965 = stack[0];
        return list2star(v_15964, v_15965, v_15952);
    }
v_15921:
    goto v_15854;
v_15856:
v_15854:
    v_15952 = nil;
    return onevalue(v_15952);
}



// Code for ps!:expression

static LispObject CC_psTexpression(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15794, v_15795, v_15796;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15796 = v_15751;
// end of prologue
    v_15794 = v_15796;
    if (!consp(v_15794)) goto v_15759;
    else goto v_15760;
v_15759:
    v_15794 = lisp_true;
    goto v_15758;
v_15760:
    goto v_15773;
v_15769:
    v_15794 = v_15796;
    v_15795 = qcar(v_15794);
    goto v_15770;
v_15771:
    v_15794 = elt(env, 1); // !:ps!:
    goto v_15772;
v_15773:
    goto v_15769;
v_15770:
    goto v_15771;
v_15772:
    if (v_15795 == v_15794) goto v_15768;
    v_15794 = v_15796;
    v_15794 = qcar(v_15794);
    if (!symbolp(v_15794)) v_15794 = nil;
    else { v_15794 = qfastgets(v_15794);
           if (v_15794 != nil) { v_15794 = elt(v_15794, 8); // dname
#ifdef RECORD_GET
             if (v_15794 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_15794 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_15794 == SPID_NOPROP) v_15794 = nil; }}
#endif
    goto v_15766;
v_15768:
    v_15794 = nil;
    goto v_15766;
    v_15794 = nil;
v_15766:
    goto v_15758;
    v_15794 = nil;
v_15758:
    if (v_15794 == nil) goto v_15756;
    v_15794 = v_15796;
    goto v_15754;
v_15756:
    goto v_15791;
v_15787:
    v_15795 = v_15796;
    goto v_15788;
v_15789:
    v_15794 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_15790;
v_15791:
    goto v_15787;
v_15788:
    goto v_15789;
v_15790:
    {
        fn = elt(env, 2); // ps!:getv
        return (*qfn2(fn))(fn, v_15795, v_15794);
    }
    v_15794 = nil;
v_15754:
    return onevalue(v_15794);
}



// Code for bcfd

static LispObject CC_bcfd(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15796, v_15797, v_15798;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15798 = v_15751;
// end of prologue
    v_15796 = qvalue(elt(env, 1)); // !*grmod!*
    if (v_15796 == nil) goto v_15755;
    else goto v_15756;
v_15755:
    goto v_15763;
v_15759:
    v_15797 = v_15798;
    goto v_15760;
v_15761:
    v_15796 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15762;
v_15763:
    goto v_15759;
v_15760:
    goto v_15761;
v_15762:
    {
        fn = elt(env, 4); // mkbc
        return (*qfn2(fn))(fn, v_15797, v_15796);
    }
v_15756:
    v_15796 = v_15798;
    v_15796 = integerp(v_15796);
    if (v_15796 == nil) goto v_15767;
    v_15796 = v_15798;
    {
        fn = elt(env, 5); // bcfi
        return (*qfn1(fn))(fn, v_15796);
    }
v_15767:
    goto v_15778;
v_15774:
    v_15796 = v_15798;
    v_15797 = qcar(v_15796);
    goto v_15775;
v_15776:
    v_15796 = elt(env, 2); // !:mod!:
    goto v_15777;
v_15778:
    goto v_15774;
v_15775:
    goto v_15776;
v_15777:
    if (v_15797 == v_15796) goto v_15773;
    goto v_15788;
v_15784:
    v_15796 = elt(env, 3); // "Invalid modular coefficient"
    goto v_15785;
v_15786:
    v_15797 = v_15798;
    goto v_15787;
v_15788:
    goto v_15784;
v_15785:
    goto v_15786;
v_15787:
    v_15796 = list2(v_15796, v_15797);
    env = stack[0];
    {
        fn = elt(env, 6); // rederr
        return (*qfn1(fn))(fn, v_15796);
    }
v_15773:
    v_15796 = v_15798;
    v_15796 = qcdr(v_15796);
    {
        fn = elt(env, 5); // bcfi
        return (*qfn1(fn))(fn, v_15796);
    }
    v_15796 = nil;
    return onevalue(v_15796);
}



// Code for critical_element

static LispObject CC_critical_element(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15763, v_15764;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15763 = v_15751;
// end of prologue
    goto v_15758;
v_15754:
    v_15764 = v_15763;
    v_15764 = qcdr(v_15764);
    v_15764 = qcar(v_15764);
    goto v_15755;
v_15756:
    goto v_15757;
v_15758:
    goto v_15754;
v_15755:
    goto v_15756;
v_15757:
        return Lapply1(nil, v_15764, v_15763);
}



// Code for contract!-strand

static LispObject CC_contractKstrand(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15763, v_15764;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15751,v_15752);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_15763 = v_15752;
    v_15764 = v_15751;
// end of prologue
    goto v_15759;
v_15755:
    stack[0] = v_15764;
    goto v_15756;
v_15757:
    fn = elt(env, 1); // zero!-roads
    v_15763 = (*qfn1(fn))(fn, v_15763);
    env = stack[-1];
    goto v_15758;
v_15759:
    goto v_15755;
v_15756:
    goto v_15757;
v_15758:
    {
        LispObject v_15766 = stack[0];
        fn = elt(env, 2); // contr!-strand
        return (*qfn2(fn))(fn, v_15766, v_15763);
    }
}



// Code for assert_declarestat1

static LispObject CC_assert_declarestat1(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_16096, v_16097, v_16098, v_16099;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(13);
// copy arguments values to proper place
    stack[-4] = v_15751;
// end of prologue
    stack[-10] = nil;
    v_16096 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_16096;
    v_16096 = stack[-4];
    v_16096 = qcar(v_16096);
    v_16096 = Lexplode(nil, v_16096);
    env = stack[-12];
    stack[0] = v_16096;
    goto v_15778;
v_15774:
    v_16096 = elt(env, 1); // assert!:
    v_16097 = Lexplode(nil, v_16096);
    env = stack[-12];
    goto v_15775;
v_15776:
    v_16096 = stack[0];
    goto v_15777;
v_15778:
    goto v_15774;
v_15775:
    goto v_15776;
v_15777:
    v_16096 = Lnconc(nil, v_16097, v_16096);
    env = stack[-12];
    v_16096 = Lcompress(nil, v_16096);
    env = stack[-12];
    v_16096 = Lintern(nil, v_16096);
    env = stack[-12];
    stack[-9] = v_16096;
    goto v_15789;
v_15785:
    v_16096 = elt(env, 2); // noassert!:
    v_16097 = Lexplode(nil, v_16096);
    env = stack[-12];
    goto v_15786;
v_15787:
    v_16096 = stack[0];
    goto v_15788;
v_15789:
    goto v_15785;
v_15786:
    goto v_15787;
v_15788:
    v_16096 = Lnconc(nil, v_16097, v_16096);
    env = stack[-12];
    v_16096 = Lcompress(nil, v_16096);
    env = stack[-12];
    v_16096 = Lintern(nil, v_16096);
    env = stack[-12];
    stack[-5] = v_16096;
    v_16096 = stack[-4];
    v_16096 = qcdr(v_16096);
    v_16096 = qcar(v_16096);
    stack[-6] = v_16096;
    v_16096 = stack[-6];
    if (v_16096 == nil) goto v_15804;
    else goto v_15805;
v_15804:
    v_16096 = nil;
    goto v_15797;
v_15805:
    goto v_15817;
v_15813:
    stack[0] = elt(env, 3); // a
    goto v_15814;
v_15815:
    v_16096 = stack[-7];
    v_16096 = add1(v_16096);
    env = stack[-12];
    stack[-7] = v_16096;
    goto v_15816;
v_15817:
    goto v_15813;
v_15814:
    goto v_15815;
v_15816:
    fn = elt(env, 18); // mkid
    v_16096 = (*qfn2(fn))(fn, stack[0], v_16096);
    env = stack[-12];
    v_16096 = ncons(v_16096);
    env = stack[-12];
    stack[-2] = v_16096;
    stack[-3] = v_16096;
v_15798:
    v_16096 = stack[-6];
    v_16096 = qcdr(v_16096);
    stack[-6] = v_16096;
    v_16096 = stack[-6];
    if (v_16096 == nil) goto v_15825;
    else goto v_15826;
v_15825:
    v_16096 = stack[-3];
    goto v_15797;
v_15826:
    goto v_15834;
v_15830:
    stack[-1] = stack[-2];
    goto v_15831;
v_15832:
    goto v_15845;
v_15841:
    stack[0] = elt(env, 3); // a
    goto v_15842;
v_15843:
    v_16096 = stack[-7];
    v_16096 = add1(v_16096);
    env = stack[-12];
    stack[-7] = v_16096;
    goto v_15844;
v_15845:
    goto v_15841;
v_15842:
    goto v_15843;
v_15844:
    fn = elt(env, 18); // mkid
    v_16096 = (*qfn2(fn))(fn, stack[0], v_16096);
    env = stack[-12];
    v_16096 = ncons(v_16096);
    env = stack[-12];
    goto v_15833;
v_15834:
    goto v_15830;
v_15831:
    goto v_15832;
v_15833:
    v_16096 = Lrplacd(nil, stack[-1], v_16096);
    env = stack[-12];
    v_16096 = stack[-2];
    v_16096 = qcdr(v_16096);
    stack[-2] = v_16096;
    goto v_15798;
v_15797:
    stack[-3] = v_16096;
    v_16096 = stack[-4];
    v_16096 = qcar(v_16096);
    v_16096 = Lmkquote(nil, v_16096);
    env = stack[-12];
    stack[-8] = v_16096;
    v_16096 = stack[-5];
    v_16096 = Lmkquote(nil, v_16096);
    env = stack[-12];
    stack[-7] = v_16096;
    goto v_15861;
v_15857:
    v_16097 = elt(env, 4); // list
    goto v_15858;
v_15859:
    v_16096 = stack[-3];
    goto v_15860;
v_15861:
    goto v_15857;
v_15858:
    goto v_15859;
v_15860:
    v_16096 = cons(v_16097, v_16096);
    env = stack[-12];
    stack[-6] = v_16096;
    goto v_15869;
v_15865:
    stack[-11] = elt(env, 4); // list
    goto v_15866;
v_15867:
    v_16096 = stack[-4];
    v_16096 = qcdr(v_16096);
    v_16096 = qcar(v_16096);
    stack[-5] = v_16096;
    v_16096 = stack[-5];
    if (v_16096 == nil) goto v_15882;
    else goto v_15883;
v_15882:
    v_16096 = nil;
    goto v_15875;
v_15883:
    v_16096 = stack[-5];
    v_16096 = qcar(v_16096);
    v_16096 = Lmkquote(nil, v_16096);
    env = stack[-12];
    v_16096 = ncons(v_16096);
    env = stack[-12];
    stack[-1] = v_16096;
    stack[-2] = v_16096;
v_15876:
    v_16096 = stack[-5];
    v_16096 = qcdr(v_16096);
    stack[-5] = v_16096;
    v_16096 = stack[-5];
    if (v_16096 == nil) goto v_15896;
    else goto v_15897;
v_15896:
    v_16096 = stack[-2];
    goto v_15875;
v_15897:
    goto v_15905;
v_15901:
    stack[0] = stack[-1];
    goto v_15902;
v_15903:
    v_16096 = stack[-5];
    v_16096 = qcar(v_16096);
    v_16096 = Lmkquote(nil, v_16096);
    env = stack[-12];
    v_16096 = ncons(v_16096);
    env = stack[-12];
    goto v_15904;
v_15905:
    goto v_15901;
v_15902:
    goto v_15903;
v_15904:
    v_16096 = Lrplacd(nil, stack[0], v_16096);
    env = stack[-12];
    v_16096 = stack[-1];
    v_16096 = qcdr(v_16096);
    stack[-1] = v_16096;
    goto v_15876;
v_15875:
    goto v_15868;
v_15869:
    goto v_15865;
v_15866:
    goto v_15867;
v_15868:
    v_16096 = cons(stack[-11], v_16096);
    env = stack[-12];
    stack[-11] = v_16096;
    v_16096 = stack[-4];
    v_16096 = qcdr(v_16096);
    v_16096 = qcdr(v_16096);
    v_16096 = qcar(v_16096);
    v_16096 = Lmkquote(nil, v_16096);
    env = stack[-12];
    goto v_15925;
v_15921:
    goto v_15935;
v_15927:
    stack[-5] = elt(env, 5); // de
    goto v_15928;
v_15929:
    stack[-4] = stack[-9];
    goto v_15930;
v_15931:
    goto v_15932;
v_15933:
    goto v_15948;
v_15940:
    stack[-2] = elt(env, 6); // assert_check1
    goto v_15941;
v_15942:
    stack[-1] = stack[-8];
    goto v_15943;
v_15944:
    stack[0] = stack[-7];
    goto v_15945;
v_15946:
    goto v_15959;
v_15953:
    v_16098 = stack[-6];
    goto v_15954;
v_15955:
    v_16097 = stack[-11];
    goto v_15956;
v_15957:
    goto v_15958;
v_15959:
    goto v_15953;
v_15954:
    goto v_15955;
v_15956:
    goto v_15957;
v_15958:
    v_16096 = list3(v_16098, v_16097, v_16096);
    env = stack[-12];
    goto v_15947;
v_15948:
    goto v_15940;
v_15941:
    goto v_15942;
v_15943:
    goto v_15944;
v_15945:
    goto v_15946;
v_15947:
    v_16096 = list3star(stack[-2], stack[-1], stack[0], v_16096);
    env = stack[-12];
    goto v_15934;
v_15935:
    goto v_15927;
v_15928:
    goto v_15929;
v_15930:
    goto v_15931;
v_15932:
    goto v_15933;
v_15934:
    v_16097 = list4(stack[-5], stack[-4], stack[-3], v_16096);
    env = stack[-12];
    goto v_15922;
v_15923:
    v_16096 = stack[-10];
    goto v_15924;
v_15925:
    goto v_15921;
v_15922:
    goto v_15923;
v_15924:
    v_16096 = cons(v_16097, v_16096);
    env = stack[-12];
    stack[-10] = v_16096;
    goto v_15969;
v_15965:
    goto v_15979;
v_15971:
    stack[-2] = elt(env, 7); // put
    goto v_15972;
v_15973:
    stack[-1] = stack[-8];
    goto v_15974;
v_15975:
    stack[0] = elt(env, 8); // (quote assert_assertfn)
    goto v_15976;
v_15977:
    v_16096 = stack[-9];
    v_16096 = Lmkquote(nil, v_16096);
    env = stack[-12];
    goto v_15978;
v_15979:
    goto v_15971;
v_15972:
    goto v_15973;
v_15974:
    goto v_15975;
v_15976:
    goto v_15977;
v_15978:
    v_16097 = list4(stack[-2], stack[-1], stack[0], v_16096);
    env = stack[-12];
    goto v_15966;
v_15967:
    v_16096 = stack[-10];
    goto v_15968;
v_15969:
    goto v_15965;
v_15966:
    goto v_15967;
v_15968:
    v_16096 = cons(v_16097, v_16096);
    env = stack[-12];
    stack[-10] = v_16096;
    goto v_15991;
v_15987:
    goto v_16001;
v_15993:
    v_16099 = elt(env, 7); // put
    goto v_15994;
v_15995:
    v_16098 = stack[-8];
    goto v_15996;
v_15997:
    v_16097 = elt(env, 9); // (quote assert_noassertfn)
    goto v_15998;
v_15999:
    v_16096 = stack[-7];
    goto v_16000;
v_16001:
    goto v_15993;
v_15994:
    goto v_15995;
v_15996:
    goto v_15997;
v_15998:
    goto v_15999;
v_16000:
    v_16097 = list4(v_16099, v_16098, v_16097, v_16096);
    env = stack[-12];
    goto v_15988;
v_15989:
    v_16096 = stack[-10];
    goto v_15990;
v_15991:
    goto v_15987;
v_15988:
    goto v_15989;
v_15990:
    v_16096 = cons(v_16097, v_16096);
    env = stack[-12];
    stack[-10] = v_16096;
    goto v_16012;
v_16008:
    goto v_16022;
v_16014:
    v_16099 = elt(env, 7); // put
    goto v_16015;
v_16016:
    v_16098 = stack[-8];
    goto v_16017;
v_16018:
    v_16097 = elt(env, 10); // (quote assert_installed)
    goto v_16019;
v_16020:
    v_16096 = nil;
    goto v_16021;
v_16022:
    goto v_16014;
v_16015:
    goto v_16016;
v_16017:
    goto v_16018;
v_16019:
    goto v_16020;
v_16021:
    v_16097 = list4(v_16099, v_16098, v_16097, v_16096);
    env = stack[-12];
    goto v_16009;
v_16010:
    v_16096 = stack[-10];
    goto v_16011;
v_16012:
    goto v_16008;
v_16009:
    goto v_16010;
v_16011:
    v_16096 = cons(v_16097, v_16096);
    env = stack[-12];
    stack[-10] = v_16096;
    goto v_16033;
v_16029:
    goto v_16039;
v_16035:
    stack[-3] = elt(env, 11); // cond
    goto v_16036;
v_16037:
    goto v_16046;
v_16042:
    goto v_16052;
v_16048:
    stack[0] = elt(env, 12); // not
    goto v_16049;
v_16050:
    goto v_16061;
v_16055:
    v_16098 = elt(env, 13); // member
    goto v_16056;
v_16057:
    v_16097 = stack[-8];
    goto v_16058;
v_16059:
    v_16096 = elt(env, 14); // assert_functionl!*
    goto v_16060;
v_16061:
    goto v_16055;
v_16056:
    goto v_16057;
v_16058:
    goto v_16059;
v_16060:
    v_16096 = list3(v_16098, v_16097, v_16096);
    env = stack[-12];
    goto v_16051;
v_16052:
    goto v_16048;
v_16049:
    goto v_16050;
v_16051:
    stack[-2] = list2(stack[0], v_16096);
    env = stack[-12];
    goto v_16043;
v_16044:
    goto v_16072;
v_16066:
    stack[-1] = elt(env, 15); // setq
    goto v_16067;
v_16068:
    stack[0] = elt(env, 14); // assert_functionl!*
    goto v_16069;
v_16070:
    goto v_16082;
v_16076:
    v_16098 = elt(env, 16); // cons
    goto v_16077;
v_16078:
    v_16097 = stack[-8];
    goto v_16079;
v_16080:
    v_16096 = elt(env, 14); // assert_functionl!*
    goto v_16081;
v_16082:
    goto v_16076;
v_16077:
    goto v_16078;
v_16079:
    goto v_16080;
v_16081:
    v_16096 = list3(v_16098, v_16097, v_16096);
    env = stack[-12];
    goto v_16071;
v_16072:
    goto v_16066;
v_16067:
    goto v_16068;
v_16069:
    goto v_16070;
v_16071:
    v_16096 = list3(stack[-1], stack[0], v_16096);
    env = stack[-12];
    goto v_16045;
v_16046:
    goto v_16042;
v_16043:
    goto v_16044;
v_16045:
    v_16096 = list2(stack[-2], v_16096);
    env = stack[-12];
    goto v_16038;
v_16039:
    goto v_16035;
v_16036:
    goto v_16037;
v_16038:
    v_16097 = list2(stack[-3], v_16096);
    env = stack[-12];
    goto v_16030;
v_16031:
    v_16096 = stack[-10];
    goto v_16032;
v_16033:
    goto v_16029;
v_16030:
    goto v_16031;
v_16032:
    v_16096 = cons(v_16097, v_16096);
    env = stack[-12];
    stack[-10] = v_16096;
    goto v_16092;
v_16088:
    v_16097 = elt(env, 17); // progn
    goto v_16089;
v_16090:
    v_16096 = stack[-10];
    v_16096 = Lnreverse(nil, v_16096);
    goto v_16091;
v_16092:
    goto v_16088;
v_16089:
    goto v_16090;
v_16091:
    return cons(v_16097, v_16096);
    return onevalue(v_16096);
}



// Code for sf2mv

static LispObject CC_sf2mv(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15765, v_15766, v_15767;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15765 = v_15752;
    v_15766 = v_15751;
// end of prologue
    goto v_15761;
v_15755:
    v_15767 = v_15766;
    goto v_15756;
v_15757:
    v_15766 = nil;
    goto v_15758;
v_15759:
    goto v_15760;
v_15761:
    goto v_15755;
v_15756:
    goto v_15757;
v_15758:
    goto v_15759;
v_15760:
    {
        fn = elt(env, 1); // sf2mv1
        return (*qfnn(fn))(fn, 3, v_15767, v_15766, v_15765);
    }
}



// Code for fs!:prepfn!:

static LispObject CC_fsTprepfnT(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15754;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15754 = v_15751;
// end of prologue
    return onevalue(v_15754);
}



// Code for st_consolidate

static LispObject CC_st_consolidate(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15902, v_15903;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_15751;
// end of prologue
    stack[-1] = nil;
    v_15902 = stack[-3];
    if (v_15902 == nil) goto v_15760;
    else goto v_15761;
v_15760:
    v_15902 = nil;
    goto v_15757;
v_15761:
    v_15902 = stack[-3];
    v_15902 = qcdr(v_15902);
    v_15902 = qcar(v_15902);
    if (is_number(v_15902)) goto v_15766;
    else goto v_15767;
v_15766:
    v_15902 = stack[-3];
    goto v_15757;
v_15767:
    v_15902 = lisp_true;
    stack[-2] = v_15902;
    v_15902 = stack[-3];
    v_15902 = qcdr(v_15902);
    v_15902 = Lreverse(nil, v_15902);
    env = stack[-5];
    stack[0] = v_15902;
v_15776:
    v_15902 = stack[0];
    if (v_15902 == nil) goto v_15782;
    else goto v_15783;
v_15782:
    goto v_15775;
v_15783:
    v_15902 = stack[0];
    v_15902 = qcar(v_15902);
    v_15902 = CC_st_consolidate(elt(env, 0), v_15902);
    env = stack[-5];
    v_15903 = v_15902;
    if (v_15903 == nil) goto v_15794;
    v_15903 = v_15902;
    v_15903 = qcdr(v_15903);
    v_15903 = qcdr(v_15903);
    if (v_15903 == nil) goto v_15799;
    v_15903 = nil;
    stack[-2] = v_15903;
    goto v_15797;
v_15799:
    goto v_15811;
v_15807:
    v_15903 = elt(env, 1); // !*
    goto v_15808;
v_15809:
    v_15902 = qcdr(v_15902);
    v_15902 = qcar(v_15902);
    goto v_15810;
v_15811:
    goto v_15807;
v_15808:
    goto v_15809;
v_15810:
    v_15902 = list2(v_15903, v_15902);
    env = stack[-5];
    goto v_15797;
v_15797:
    goto v_15821;
v_15817:
    v_15903 = v_15902;
    goto v_15818;
v_15819:
    v_15902 = stack[-1];
    goto v_15820;
v_15821:
    goto v_15817;
v_15818:
    goto v_15819;
v_15820:
    v_15902 = cons(v_15903, v_15902);
    env = stack[-5];
    stack[-1] = v_15902;
    goto v_15792;
v_15794:
v_15792:
    v_15902 = stack[0];
    v_15902 = qcdr(v_15902);
    stack[0] = v_15902;
    goto v_15776;
v_15775:
    v_15902 = stack[-1];
    if (v_15902 == nil) goto v_15831;
    v_15902 = stack[-1];
    v_15902 = qcdr(v_15902);
    if (v_15902 == nil) goto v_15835;
    else goto v_15836;
v_15835:
    v_15902 = stack[-1];
    v_15902 = qcar(v_15902);
    goto v_15757;
v_15836:
    v_15902 = stack[-2];
    if (v_15902 == nil) goto v_15844;
    v_15902 = stack[-1];
    stack[-4] = v_15902;
    v_15902 = stack[-4];
    if (v_15902 == nil) goto v_15855;
    else goto v_15856;
v_15855:
    v_15902 = nil;
    goto v_15850;
v_15856:
    v_15902 = stack[-4];
    v_15902 = qcar(v_15902);
    v_15902 = qcdr(v_15902);
    v_15902 = qcar(v_15902);
    v_15902 = ncons(v_15902);
    env = stack[-5];
    stack[-1] = v_15902;
    stack[-2] = v_15902;
v_15851:
    v_15902 = stack[-4];
    v_15902 = qcdr(v_15902);
    stack[-4] = v_15902;
    v_15902 = stack[-4];
    if (v_15902 == nil) goto v_15870;
    else goto v_15871;
v_15870:
    v_15902 = stack[-2];
    goto v_15850;
v_15871:
    goto v_15879;
v_15875:
    stack[0] = stack[-1];
    goto v_15876;
v_15877:
    v_15902 = stack[-4];
    v_15902 = qcar(v_15902);
    v_15902 = qcdr(v_15902);
    v_15902 = qcar(v_15902);
    v_15902 = ncons(v_15902);
    env = stack[-5];
    goto v_15878;
v_15879:
    goto v_15875;
v_15876:
    goto v_15877;
v_15878:
    v_15902 = Lrplacd(nil, stack[0], v_15902);
    env = stack[-5];
    v_15902 = stack[-1];
    v_15902 = qcdr(v_15902);
    stack[-1] = v_15902;
    goto v_15851;
v_15850:
    stack[-1] = v_15902;
    goto v_15842;
v_15844:
v_15842:
    goto v_15895;
v_15891:
    v_15902 = stack[-3];
    v_15903 = qcar(v_15902);
    goto v_15892;
v_15893:
    v_15902 = stack[-1];
    goto v_15894;
v_15895:
    goto v_15891;
v_15892:
    goto v_15893;
v_15894:
    return cons(v_15903, v_15902);
v_15831:
    v_15902 = nil;
    goto v_15757;
    v_15902 = nil;
v_15757:
    return onevalue(v_15902);
}



// Code for ratminus

static LispObject CC_ratminus(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15764, v_15765;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_15751;
// end of prologue
    goto v_15758;
v_15754:
    v_15764 = stack[0];
    v_15764 = qcar(v_15764);
    v_15765 = negate(v_15764);
    goto v_15755;
v_15756:
    v_15764 = stack[0];
    v_15764 = qcdr(v_15764);
    goto v_15757;
v_15758:
    goto v_15754;
v_15755:
    goto v_15756;
v_15757:
    return cons(v_15765, v_15764);
}



// Code for sfto_lessq

static LispObject CC_sfto_lessq(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15765, v_15766;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15751,v_15752);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_15765 = v_15752;
    v_15766 = v_15751;
// end of prologue
    goto v_15760;
v_15756:
    stack[0] = v_15766;
    goto v_15757;
v_15758:
    fn = elt(env, 1); // negsq
    v_15765 = (*qfn1(fn))(fn, v_15765);
    env = stack[-1];
    goto v_15759;
v_15760:
    goto v_15756;
v_15757:
    goto v_15758;
v_15759:
    fn = elt(env, 2); // addsq
    v_15765 = (*qfn2(fn))(fn, stack[0], v_15765);
    env = stack[-1];
    v_15765 = qcar(v_15765);
    {
        fn = elt(env, 3); // minusf
        return (*qfn1(fn))(fn, v_15765);
    }
}



// Code for lalr_prin_reduction

static LispObject CC_lalr_prin_reduction(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15812, v_15813;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_15751;
// end of prologue
    v_15812 = qvalue(elt(env, 1)); // reduction_info
    v_15812 = qcar(v_15812);
    stack[-3] = v_15812;
    v_15812 = qvalue(elt(env, 1)); // reduction_info
    v_15812 = qcdr(v_15812);
    v_15812 = qcar(v_15812);
    stack[-1] = v_15812;
    v_15812 = qvalue(elt(env, 1)); // reduction_info
    v_15812 = qcdr(v_15812);
    v_15812 = qcdr(v_15812);
    v_15812 = qcar(v_15812);
    stack[0] = v_15812;
    v_15812 = elt(env, 2); // "reduce by #"
    v_15812 = Lprinc(nil, v_15812);
    env = stack[-4];
    v_15812 = stack[-2];
    v_15812 = Lprin(nil, v_15812);
    env = stack[-4];
    v_15812 = elt(env, 3); // ": "
    v_15812 = Lprinc(nil, v_15812);
    env = stack[-4];
    goto v_15780;
v_15776:
    v_15813 = stack[0];
    goto v_15777;
v_15778:
    v_15812 = stack[-2];
    goto v_15779;
v_15780:
    goto v_15776;
v_15777:
    goto v_15778;
v_15779:
    fn = elt(env, 6); // getv16
    v_15812 = (*qfn2(fn))(fn, v_15813, v_15812);
    env = stack[-4];
    fn = elt(env, 7); // lalr_prin_nonterminal
    v_15812 = (*qfn1(fn))(fn, v_15812);
    env = stack[-4];
    v_15812 = elt(env, 4); // " -> ["
    v_15812 = Lprinc(nil, v_15812);
    env = stack[-4];
    goto v_15791;
v_15787:
    v_15813 = stack[-1];
    goto v_15788;
v_15789:
    v_15812 = stack[-2];
    goto v_15790;
v_15791:
    goto v_15787;
v_15788:
    goto v_15789;
v_15790:
    fn = elt(env, 8); // getv8
    v_15812 = (*qfn2(fn))(fn, v_15813, v_15812);
    env = stack[-4];
    v_15812 = Lprin(nil, v_15812);
    env = stack[-4];
    v_15812 = elt(env, 5); // " symbols] "
    v_15812 = Lprinc(nil, v_15812);
    env = stack[-4];
    goto v_15804;
v_15800:
    v_15813 = stack[-3];
    goto v_15801;
v_15802:
    v_15812 = stack[-2];
    goto v_15803;
v_15804:
    goto v_15800;
v_15801:
    goto v_15802;
v_15803:
    v_15812 = *(LispObject *)((char *)v_15813 + (CELL-TAG_VECTOR) + (((intptr_t)v_15812-TAG_FIXNUM)/(16/CELL)));
    v_15813 = v_15812;
    if (v_15812 == nil) goto v_15799;
    v_15812 = v_15813;
    fn = elt(env, 9); // getd
    v_15812 = (*qfn1(fn))(fn, v_15812);
    env = stack[-4];
    v_15812 = qcdr(v_15812);
    fn = elt(env, 10); // prin_with_margin
    v_15812 = (*qfn1(fn))(fn, v_15812);
    goto v_15797;
v_15799:
v_15797:
    v_15812 = nil;
    return onevalue(v_15812);
}



// Code for gcref_off

static LispObject CC_gcref_off(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15851, v_15852, v_15853;
    LispObject fn;
    argcheck(nargs, 0, "gcref_off");
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
    fn = elt(env, 7); // gcref_off1
    v_15851 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_15761;
v_15757:
    v_15852 = Ltime(nil, 0);
    env = stack[-5];
    goto v_15758;
v_15759:
    v_15851 = qvalue(elt(env, 1)); // btime!*
    goto v_15760;
v_15761:
    goto v_15757;
v_15758:
    goto v_15759;
v_15760:
    v_15851 = difference2(v_15852, v_15851);
    env = stack[-5];
    v_15851 = qvalue(elt(env, 2)); // pfiles!*
    stack[-4] = v_15851;
    v_15851 = stack[-4];
    if (v_15851 == nil) goto v_15773;
    else goto v_15774;
v_15773:
    v_15851 = nil;
    goto v_15768;
v_15774:
    v_15851 = stack[-4];
    v_15851 = qcar(v_15851);
    stack[0] = v_15851;
    goto v_15788;
v_15782:
    v_15851 = stack[0];
    v_15853 = qcdr(v_15851);
    goto v_15783;
v_15784:
    v_15852 = elt(env, 3); // cref_name
    goto v_15785;
v_15786:
    v_15851 = stack[0];
    v_15851 = qcar(v_15851);
    goto v_15787;
v_15788:
    goto v_15782;
v_15783:
    goto v_15784;
v_15785:
    goto v_15786;
v_15787:
    v_15851 = Lputprop(nil, 3, v_15853, v_15852, v_15851);
    env = stack[-5];
    v_15851 = stack[0];
    v_15851 = qcdr(v_15851);
    v_15851 = ncons(v_15851);
    env = stack[-5];
    stack[-2] = v_15851;
    stack[-3] = v_15851;
v_15769:
    v_15851 = stack[-4];
    v_15851 = qcdr(v_15851);
    stack[-4] = v_15851;
    v_15851 = stack[-4];
    if (v_15851 == nil) goto v_15800;
    else goto v_15801;
v_15800:
    v_15851 = stack[-3];
    goto v_15768;
v_15801:
    goto v_15809;
v_15805:
    stack[-1] = stack[-2];
    goto v_15806;
v_15807:
    v_15851 = stack[-4];
    v_15851 = qcar(v_15851);
    stack[0] = v_15851;
    goto v_15822;
v_15816:
    v_15851 = stack[0];
    v_15853 = qcdr(v_15851);
    goto v_15817;
v_15818:
    v_15852 = elt(env, 3); // cref_name
    goto v_15819;
v_15820:
    v_15851 = stack[0];
    v_15851 = qcar(v_15851);
    goto v_15821;
v_15822:
    goto v_15816;
v_15817:
    goto v_15818;
v_15819:
    goto v_15820;
v_15821:
    v_15851 = Lputprop(nil, 3, v_15853, v_15852, v_15851);
    env = stack[-5];
    v_15851 = stack[0];
    v_15851 = qcdr(v_15851);
    v_15851 = ncons(v_15851);
    env = stack[-5];
    goto v_15808;
v_15809:
    goto v_15805;
v_15806:
    goto v_15807;
v_15808:
    v_15851 = Lrplacd(nil, stack[-1], v_15851);
    env = stack[-5];
    v_15851 = stack[-2];
    v_15851 = qcdr(v_15851);
    stack[-2] = v_15851;
    goto v_15769;
v_15768:
    qvalue(elt(env, 2)) = v_15851; // pfiles!*
    v_15851 = qvalue(elt(env, 4)); // !*gcrefall
    if (v_15851 == nil) goto v_15835;
    v_15851 = qvalue(elt(env, 5)); // seen!*
    fn = elt(env, 8); // gcref_select
    v_15851 = (*qfn1(fn))(fn, v_15851);
    env = stack[-5];
    fn = elt(env, 9); // gcref_mkgraph
    v_15851 = (*qfn1(fn))(fn, v_15851);
    env = stack[-5];
    goto v_15833;
v_15835:
    v_15851 = qvalue(elt(env, 5)); // seen!*
    fn = elt(env, 10); // gcref_eselect
    v_15851 = (*qfn1(fn))(fn, v_15851);
    env = stack[-5];
    fn = elt(env, 11); // gcref_mkegraph
    v_15851 = (*qfn1(fn))(fn, v_15851);
    env = stack[-5];
    goto v_15833;
v_15833:
    v_15851 = qvalue(elt(env, 6)); // !*saveprops
    if (v_15851 == nil) goto v_15847;
    else goto v_15848;
v_15847:
    fn = elt(env, 12); // gcref_remprops
    v_15851 = (*qfnn(fn))(fn, 0);
    goto v_15846;
v_15848:
v_15846:
    v_15851 = nil;
    return onevalue(v_15851);
}



// Code for ofsf_posvarp

static LispObject CC_ofsf_posvarp(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_16007, v_16008, v_16009, v_16010;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15751,v_15752);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15752;
    stack[-1] = v_15751;
// end of prologue
    v_16009 = nil;
    v_16007 = stack[-1];
    if (!consp(v_16007)) goto v_15762;
    else goto v_15763;
v_15762:
    v_16007 = stack[-1];
    goto v_15761;
v_15763:
    v_16007 = stack[-1];
    v_16007 = qcar(v_16007);
    goto v_15761;
    v_16007 = nil;
v_15761:
    goto v_15778;
v_15774:
    v_16008 = v_16007;
    goto v_15775;
v_15776:
    v_16007 = elt(env, 1); // and
    goto v_15777;
v_15778:
    goto v_15774;
v_15775:
    goto v_15776;
v_15777:
    if (v_16008 == v_16007) goto v_15772;
    else goto v_15773;
v_15772:
    v_16007 = stack[-1];
    v_16007 = qcdr(v_16007);
    stack[-2] = v_16007;
v_15785:
    v_16007 = v_16009;
    if (v_16007 == nil) goto v_15792;
    else goto v_15793;
v_15792:
    v_16007 = stack[-2];
    goto v_15791;
v_15793:
    v_16007 = nil;
    goto v_15791;
    v_16007 = nil;
v_15791:
    if (v_16007 == nil) goto v_15788;
    else goto v_15789;
v_15788:
    goto v_15784;
v_15789:
    v_16007 = stack[-2];
    v_16007 = qcar(v_16007);
    v_16008 = v_16007;
    v_16007 = stack[-2];
    v_16007 = qcdr(v_16007);
    stack[-2] = v_16007;
    v_16007 = v_16008;
    v_16010 = v_16007;
    goto v_15825;
v_15821:
    v_16008 = stack[-1];
    goto v_15822;
v_15823:
    v_16007 = elt(env, 2); // true
    goto v_15824;
v_15825:
    goto v_15821;
v_15822:
    goto v_15823;
v_15824:
    if (v_16008 == v_16007) goto v_15819;
    else goto v_15820;
v_15819:
    v_16007 = lisp_true;
    goto v_15818;
v_15820:
    goto v_15835;
v_15831:
    v_16008 = stack[-1];
    goto v_15832;
v_15833:
    v_16007 = elt(env, 3); // false
    goto v_15834;
v_15835:
    goto v_15831;
v_15832:
    goto v_15833;
v_15834:
    v_16007 = (v_16008 == v_16007 ? lisp_true : nil);
    goto v_15818;
    v_16007 = nil;
v_15818:
    if (v_16007 == nil) goto v_15816;
    v_16007 = lisp_true;
    goto v_15814;
v_15816:
    goto v_15862;
v_15858:
    v_16008 = stack[-1];
    goto v_15859;
v_15860:
    v_16007 = elt(env, 4); // or
    goto v_15861;
v_15862:
    goto v_15858;
v_15859:
    goto v_15860;
v_15861:
    if (v_16008 == v_16007) goto v_15856;
    else goto v_15857;
v_15856:
    v_16007 = lisp_true;
    goto v_15855;
v_15857:
    goto v_15872;
v_15868:
    v_16008 = stack[-1];
    goto v_15869;
v_15870:
    v_16007 = elt(env, 1); // and
    goto v_15871;
v_15872:
    goto v_15868;
v_15869:
    goto v_15870;
v_15871:
    v_16007 = (v_16008 == v_16007 ? lisp_true : nil);
    goto v_15855;
    v_16007 = nil;
v_15855:
    if (v_16007 == nil) goto v_15853;
    v_16007 = lisp_true;
    goto v_15851;
v_15853:
    goto v_15883;
v_15879:
    v_16008 = stack[-1];
    goto v_15880;
v_15881:
    v_16007 = elt(env, 5); // not
    goto v_15882;
v_15883:
    goto v_15879;
v_15880:
    goto v_15881;
v_15882:
    v_16007 = (v_16008 == v_16007 ? lisp_true : nil);
    goto v_15851;
    v_16007 = nil;
v_15851:
    if (v_16007 == nil) goto v_15849;
    v_16007 = lisp_true;
    goto v_15847;
v_15849:
    goto v_15898;
v_15894:
    v_16008 = stack[-1];
    goto v_15895;
v_15896:
    v_16007 = elt(env, 6); // impl
    goto v_15897;
v_15898:
    goto v_15894;
v_15895:
    goto v_15896;
v_15897:
    if (v_16008 == v_16007) goto v_15892;
    else goto v_15893;
v_15892:
    v_16007 = lisp_true;
    goto v_15891;
v_15893:
    goto v_15912;
v_15908:
    v_16008 = stack[-1];
    goto v_15909;
v_15910:
    v_16007 = elt(env, 7); // repl
    goto v_15911;
v_15912:
    goto v_15908;
v_15909:
    goto v_15910;
v_15911:
    if (v_16008 == v_16007) goto v_15906;
    else goto v_15907;
v_15906:
    v_16007 = lisp_true;
    goto v_15905;
v_15907:
    goto v_15922;
v_15918:
    v_16008 = stack[-1];
    goto v_15919;
v_15920:
    v_16007 = elt(env, 8); // equiv
    goto v_15921;
v_15922:
    goto v_15918;
v_15919:
    goto v_15920;
v_15921:
    v_16007 = (v_16008 == v_16007 ? lisp_true : nil);
    goto v_15905;
    v_16007 = nil;
v_15905:
    goto v_15891;
    v_16007 = nil;
v_15891:
    goto v_15847;
    v_16007 = nil;
v_15847:
    if (v_16007 == nil) goto v_15845;
    v_16007 = lisp_true;
    goto v_15843;
v_15845:
    goto v_15941;
v_15937:
    v_16008 = stack[-1];
    goto v_15938;
v_15939:
    v_16007 = elt(env, 9); // ex
    goto v_15940;
v_15941:
    goto v_15937;
v_15938:
    goto v_15939;
v_15940:
    if (v_16008 == v_16007) goto v_15935;
    else goto v_15936;
v_15935:
    v_16007 = lisp_true;
    goto v_15934;
v_15936:
    goto v_15951;
v_15947:
    v_16008 = stack[-1];
    goto v_15948;
v_15949:
    v_16007 = elt(env, 10); // all
    goto v_15950;
v_15951:
    goto v_15947;
v_15948:
    goto v_15949;
v_15950:
    v_16007 = (v_16008 == v_16007 ? lisp_true : nil);
    goto v_15934;
    v_16007 = nil;
v_15934:
    if (v_16007 == nil) goto v_15932;
    v_16007 = lisp_true;
    goto v_15930;
v_15932:
    goto v_15970;
v_15966:
    v_16008 = stack[-1];
    goto v_15967;
v_15968:
    v_16007 = elt(env, 11); // bex
    goto v_15969;
v_15970:
    goto v_15966;
v_15967:
    goto v_15968;
v_15969:
    if (v_16008 == v_16007) goto v_15964;
    else goto v_15965;
v_15964:
    v_16007 = lisp_true;
    goto v_15963;
v_15965:
    goto v_15980;
v_15976:
    v_16008 = stack[-1];
    goto v_15977;
v_15978:
    v_16007 = elt(env, 12); // ball
    goto v_15979;
v_15980:
    goto v_15976;
v_15977:
    goto v_15978;
v_15979:
    v_16007 = (v_16008 == v_16007 ? lisp_true : nil);
    goto v_15963;
    v_16007 = nil;
v_15963:
    if (v_16007 == nil) goto v_15961;
    v_16007 = lisp_true;
    goto v_15959;
v_15961:
    v_16007 = stack[-1];
    if (!symbolp(v_16007)) v_16007 = nil;
    else { v_16007 = qfastgets(v_16007);
           if (v_16007 != nil) { v_16007 = elt(v_16007, 21); // rl_external
#ifdef RECORD_GET
             if (v_16007 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_16007 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_16007 == SPID_NOPROP) v_16007 = nil; }}
#endif
    goto v_15959;
    v_16007 = nil;
v_15959:
    goto v_15930;
    v_16007 = nil;
v_15930:
    goto v_15843;
    v_16007 = nil;
v_15843:
    goto v_15814;
    v_16007 = nil;
v_15814:
    if (v_16007 == nil) goto v_15811;
    else goto v_15812;
v_15811:
    goto v_15994;
v_15990:
    v_16008 = v_16010;
    goto v_15991;
v_15992:
    v_16007 = stack[0];
    goto v_15993;
v_15994:
    goto v_15990;
v_15991:
    goto v_15992;
v_15993:
    fn = elt(env, 13); // ofsf_posvarpat
    v_16007 = (*qfn2(fn))(fn, v_16008, v_16007);
    env = stack[-3];
    v_16009 = v_16007;
    goto v_15810;
v_15812:
v_15810:
    goto v_15785;
v_15784:
    v_16007 = v_16009;
    goto v_15759;
v_15773:
    goto v_16004;
v_16000:
    v_16008 = stack[-1];
    goto v_16001;
v_16002:
    v_16007 = stack[0];
    goto v_16003;
v_16004:
    goto v_16000;
v_16001:
    goto v_16002;
v_16003:
    {
        fn = elt(env, 13); // ofsf_posvarpat
        return (*qfn2(fn))(fn, v_16008, v_16007);
    }
v_15759:
    return onevalue(v_16007);
}



// Code for cquotegex

static LispObject CC_cquotegex(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15759;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15759 = v_15751;
// end of prologue
    v_15759 = qvalue(elt(env, 1)); // !*guardian
    if (v_15759 == nil) goto v_15756;
    v_15759 = elt(env, 2); // gex
    goto v_15754;
v_15756:
    v_15759 = nil;
v_15754:
    return onevalue(v_15759);
}



// Code for simpexpt11

static LispObject CC_simpexpt11(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15875, v_15876, v_15877;
    LispObject fn;
    LispObject v_15753, v_15752, v_15751;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "simpexpt11");
    va_start(aa, nargs);
    v_15751 = va_arg(aa, LispObject);
    v_15752 = va_arg(aa, LispObject);
    v_15753 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15753,v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15751,v_15752,v_15753);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_15753;
    stack[-2] = v_15752;
    stack[-3] = v_15751;
// end of prologue
    stack[-4] = nil;
    v_15875 = qvalue(elt(env, 1)); // !*precise_complex
    if (v_15875 == nil) goto v_15761;
    goto v_15770;
v_15764:
    v_15877 = stack[-3];
    goto v_15765;
v_15766:
    v_15876 = stack[-2];
    goto v_15767;
v_15768:
    v_15875 = stack[-1];
    goto v_15769;
v_15770:
    goto v_15764;
v_15765:
    goto v_15766;
v_15767:
    goto v_15768;
v_15769:
    {
        fn = elt(env, 2); // simpexpt2
        return (*qfnn(fn))(fn, 3, v_15877, v_15876, v_15875);
    }
v_15761:
    v_15875 = stack[-2];
    v_15875 = qcdr(v_15875);
    if (!consp(v_15875)) goto v_15782;
    else goto v_15783;
v_15782:
    v_15875 = lisp_true;
    goto v_15781;
v_15783:
    v_15875 = stack[-2];
    v_15875 = qcdr(v_15875);
    v_15875 = qcar(v_15875);
    v_15875 = (consp(v_15875) ? nil : lisp_true);
    goto v_15781;
    v_15875 = nil;
v_15781:
    if (v_15875 == nil) goto v_15779;
    v_15875 = lisp_true;
    goto v_15777;
v_15779:
    goto v_15805;
v_15801:
    v_15875 = stack[-2];
    v_15876 = qcar(v_15875);
    goto v_15802;
v_15803:
    v_15875 = stack[-2];
    v_15875 = qcdr(v_15875);
    goto v_15804;
v_15805:
    goto v_15801;
v_15802:
    goto v_15803;
v_15804:
    fn = elt(env, 3); // qremf
    v_15875 = (*qfn2(fn))(fn, v_15876, v_15875);
    env = stack[-5];
    stack[-4] = v_15875;
    v_15875 = qcar(v_15875);
    if (v_15875 == nil) goto v_15798;
    else goto v_15799;
v_15798:
    v_15875 = nil;
    goto v_15797;
v_15799:
    v_15875 = stack[-4];
    v_15875 = qcdr(v_15875);
    goto v_15797;
    v_15875 = nil;
v_15797:
    v_15875 = (v_15875 == nil ? lisp_true : nil);
    goto v_15777;
    v_15875 = nil;
v_15777:
    if (v_15875 == nil) goto v_15775;
    goto v_15824;
v_15818:
    v_15877 = stack[-3];
    goto v_15819;
v_15820:
    v_15876 = stack[-2];
    goto v_15821;
v_15822:
    v_15875 = stack[-1];
    goto v_15823;
v_15824:
    goto v_15818;
v_15819:
    goto v_15820;
v_15821:
    goto v_15822;
v_15823:
    {
        fn = elt(env, 2); // simpexpt2
        return (*qfnn(fn))(fn, 3, v_15877, v_15876, v_15875);
    }
v_15775:
    goto v_15835;
v_15831:
    goto v_15843;
v_15837:
    stack[0] = stack[-3];
    goto v_15838;
v_15839:
    goto v_15850;
v_15846:
    v_15875 = stack[-4];
    v_15876 = qcar(v_15875);
    goto v_15847;
v_15848:
    v_15875 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15849;
v_15850:
    goto v_15846;
v_15847:
    goto v_15848;
v_15849:
    v_15876 = cons(v_15876, v_15875);
    env = stack[-5];
    goto v_15840;
v_15841:
    v_15875 = stack[-1];
    goto v_15842;
v_15843:
    goto v_15837;
v_15838:
    goto v_15839;
v_15840:
    goto v_15841;
v_15842:
    fn = elt(env, 4); // simpexpt1
    stack[0] = (*qfnn(fn))(fn, 3, stack[0], v_15876, v_15875);
    env = stack[-5];
    goto v_15832;
v_15833:
    goto v_15862;
v_15856:
    goto v_15857;
v_15858:
    goto v_15869;
v_15865:
    v_15875 = stack[-4];
    v_15876 = qcdr(v_15875);
    goto v_15866;
v_15867:
    v_15875 = stack[-2];
    v_15875 = qcdr(v_15875);
    goto v_15868;
v_15869:
    goto v_15865;
v_15866:
    goto v_15867;
v_15868:
    v_15876 = cons(v_15876, v_15875);
    env = stack[-5];
    goto v_15859;
v_15860:
    v_15875 = stack[-1];
    goto v_15861;
v_15862:
    goto v_15856;
v_15857:
    goto v_15858;
v_15859:
    goto v_15860;
v_15861:
    fn = elt(env, 4); // simpexpt1
    v_15875 = (*qfnn(fn))(fn, 3, stack[-3], v_15876, v_15875);
    env = stack[-5];
    goto v_15834;
v_15835:
    goto v_15831;
v_15832:
    goto v_15833;
v_15834:
    {
        LispObject v_15883 = stack[0];
        fn = elt(env, 5); // multsq
        return (*qfn2(fn))(fn, v_15883, v_15875);
    }
    v_15875 = nil;
    return onevalue(v_15875);
}



// Code for rndifference!:

static LispObject CC_rndifferenceT(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15802, v_15803;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15751,v_15752);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15752;
    stack[-1] = v_15751;
// end of prologue
    goto v_15759;
v_15755:
    goto v_15765;
v_15761:
    goto v_15771;
v_15767:
    v_15802 = stack[-1];
    v_15802 = qcdr(v_15802);
    v_15803 = qcar(v_15802);
    goto v_15768;
v_15769:
    v_15802 = stack[0];
    v_15802 = qcdr(v_15802);
    v_15802 = qcdr(v_15802);
    goto v_15770;
v_15771:
    goto v_15767;
v_15768:
    goto v_15769;
v_15770:
    stack[-2] = times2(v_15803, v_15802);
    env = stack[-3];
    goto v_15762;
v_15763:
    goto v_15783;
v_15779:
    v_15802 = stack[-1];
    v_15802 = qcdr(v_15802);
    v_15803 = qcdr(v_15802);
    goto v_15780;
v_15781:
    v_15802 = stack[0];
    v_15802 = qcdr(v_15802);
    v_15802 = qcar(v_15802);
    goto v_15782;
v_15783:
    goto v_15779;
v_15780:
    goto v_15781;
v_15782:
    v_15802 = times2(v_15803, v_15802);
    env = stack[-3];
    goto v_15764;
v_15765:
    goto v_15761;
v_15762:
    goto v_15763;
v_15764:
    stack[-2] = difference2(stack[-2], v_15802);
    env = stack[-3];
    goto v_15756;
v_15757:
    goto v_15795;
v_15791:
    v_15802 = stack[-1];
    v_15802 = qcdr(v_15802);
    v_15803 = qcdr(v_15802);
    goto v_15792;
v_15793:
    v_15802 = stack[0];
    v_15802 = qcdr(v_15802);
    v_15802 = qcdr(v_15802);
    goto v_15794;
v_15795:
    goto v_15791;
v_15792:
    goto v_15793;
v_15794:
    v_15802 = times2(v_15803, v_15802);
    env = stack[-3];
    goto v_15758;
v_15759:
    goto v_15755;
v_15756:
    goto v_15757;
v_15758:
    {
        LispObject v_15807 = stack[-2];
        fn = elt(env, 1); // mkrn
        return (*qfn2(fn))(fn, v_15807, v_15802);
    }
}



// Code for mk!+trace

static LispObject CC_mkLtrace(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15818, v_15819, v_15820;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_15751;
// end of prologue
    v_15818 = stack[-1];
    fn = elt(env, 3); // squared!+matrix!+p
    v_15818 = (*qfn1(fn))(fn, v_15818);
    env = stack[-3];
    if (v_15818 == nil) goto v_15759;
    else goto v_15760;
v_15759:
    v_15818 = elt(env, 1); // "no square matrix in add"
    fn = elt(env, 4); // rederr
    v_15818 = (*qfn1(fn))(fn, v_15818);
    env = stack[-3];
    goto v_15758;
v_15760:
v_15758:
    goto v_15770;
v_15766:
    v_15819 = nil;
    goto v_15767;
v_15768:
    v_15818 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15769;
v_15770:
    goto v_15766;
v_15767:
    goto v_15768;
v_15769:
    v_15818 = cons(v_15819, v_15818);
    env = stack[-3];
    stack[0] = v_15818;
    v_15818 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_15818;
v_15776:
    goto v_15788;
v_15784:
    v_15818 = stack[-1];
    fn = elt(env, 5); // get!+row!+nr
    v_15819 = (*qfn1(fn))(fn, v_15818);
    env = stack[-3];
    goto v_15785;
v_15786:
    v_15818 = stack[-2];
    goto v_15787;
v_15788:
    goto v_15784;
v_15785:
    goto v_15786;
v_15787:
    v_15818 = difference2(v_15819, v_15818);
    env = stack[-3];
    v_15818 = Lminusp(nil, v_15818);
    env = stack[-3];
    if (v_15818 == nil) goto v_15781;
    goto v_15775;
v_15781:
    goto v_15798;
v_15794:
    goto v_15795;
v_15796:
    goto v_15807;
v_15801:
    v_15820 = stack[-1];
    goto v_15802;
v_15803:
    v_15819 = stack[-2];
    goto v_15804;
v_15805:
    v_15818 = stack[-2];
    goto v_15806;
v_15807:
    goto v_15801;
v_15802:
    goto v_15803;
v_15804:
    goto v_15805;
v_15806:
    fn = elt(env, 6); // get!+mat!+entry
    v_15818 = (*qfnn(fn))(fn, 3, v_15820, v_15819, v_15818);
    env = stack[-3];
    goto v_15797;
v_15798:
    goto v_15794;
v_15795:
    goto v_15796;
v_15797:
    fn = elt(env, 7); // addsq
    v_15818 = (*qfn2(fn))(fn, stack[0], v_15818);
    env = stack[-3];
    stack[0] = v_15818;
    v_15818 = stack[-2];
    v_15818 = add1(v_15818);
    env = stack[-3];
    stack[-2] = v_15818;
    goto v_15776;
v_15775:
    v_15818 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-3, 2, -1);
    qvalue(elt(env, 2)) = v_15818; // !*sub2
    v_15818 = stack[0];
    fn = elt(env, 8); // subs2
    v_15818 = (*qfn1(fn))(fn, v_15818);
    stack[0] = v_15818;
    ;}  // end of a binding scope
    v_15818 = stack[0];
    return onevalue(v_15818);
}



// Code for cl_atl1

static LispObject CC_cl_atl1(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15796;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_15796 = v_15751;
// end of prologue
    fn = elt(env, 1); // cl_atml1
    v_15796 = (*qfn1(fn))(fn, v_15796);
    env = stack[-4];
    stack[-3] = v_15796;
    v_15796 = stack[-3];
    if (v_15796 == nil) goto v_15763;
    else goto v_15764;
v_15763:
    v_15796 = nil;
    goto v_15757;
v_15764:
    v_15796 = stack[-3];
    v_15796 = qcar(v_15796);
    v_15796 = qcar(v_15796);
    v_15796 = ncons(v_15796);
    env = stack[-4];
    stack[-1] = v_15796;
    stack[-2] = v_15796;
v_15758:
    v_15796 = stack[-3];
    v_15796 = qcdr(v_15796);
    stack[-3] = v_15796;
    v_15796 = stack[-3];
    if (v_15796 == nil) goto v_15777;
    else goto v_15778;
v_15777:
    v_15796 = stack[-2];
    goto v_15757;
v_15778:
    goto v_15786;
v_15782:
    stack[0] = stack[-1];
    goto v_15783;
v_15784:
    v_15796 = stack[-3];
    v_15796 = qcar(v_15796);
    v_15796 = qcar(v_15796);
    v_15796 = ncons(v_15796);
    env = stack[-4];
    goto v_15785;
v_15786:
    goto v_15782;
v_15783:
    goto v_15784;
v_15785:
    v_15796 = Lrplacd(nil, stack[0], v_15796);
    env = stack[-4];
    v_15796 = stack[-1];
    v_15796 = qcdr(v_15796);
    stack[-1] = v_15796;
    goto v_15758;
v_15757:
    return onevalue(v_15796);
}



// Code for aex_bvarl

static LispObject CC_aex_bvarl(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15756;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15756 = v_15751;
// end of prologue
    fn = elt(env, 1); // aex_ctx
    v_15756 = (*qfn1(fn))(fn, v_15756);
    env = stack[0];
    {
        fn = elt(env, 2); // ctx_idl
        return (*qfn1(fn))(fn, v_15756);
    }
}



// Code for opfneval

static LispObject CC_opfneval(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15840, v_15841, v_15842;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_15840 = v_15751;
// end of prologue
    goto v_15759;
v_15755:
    v_15841 = v_15840;
    stack[-4] = qcar(v_15841);
    goto v_15756;
v_15757:
    goto v_15777;
v_15773:
    v_15841 = v_15840;
    v_15842 = qcar(v_15841);
    goto v_15774;
v_15775:
    v_15841 = elt(env, 1); // noval
    goto v_15776;
v_15777:
    goto v_15773;
v_15774:
    goto v_15775;
v_15776:
    v_15841 = Lflagp(nil, v_15842, v_15841);
    env = stack[-5];
    if (v_15841 == nil) goto v_15771;
    v_15840 = qcdr(v_15840);
    goto v_15769;
v_15771:
    goto v_15792;
v_15786:
    v_15841 = v_15840;
    v_15841 = qcdr(v_15841);
    goto v_15787;
v_15788:
    goto v_15800;
v_15796:
    v_15842 = qcar(v_15840);
    goto v_15797;
v_15798:
    v_15840 = elt(env, 2); // nosimp
    goto v_15799;
v_15800:
    goto v_15796;
v_15797:
    goto v_15798;
v_15799:
    v_15842 = get(v_15842, v_15840);
    env = stack[-5];
    goto v_15789;
v_15790:
    v_15840 = lisp_true;
    goto v_15791;
v_15792:
    goto v_15786;
v_15787:
    goto v_15788;
v_15789:
    goto v_15790;
v_15791:
    fn = elt(env, 3); // fnreval
    v_15840 = (*qfnn(fn))(fn, 3, v_15841, v_15842, v_15840);
    env = stack[-5];
    goto v_15769;
    v_15840 = nil;
v_15769:
    stack[-3] = v_15840;
    v_15840 = stack[-3];
    if (v_15840 == nil) goto v_15807;
    else goto v_15808;
v_15807:
    v_15840 = nil;
    goto v_15766;
v_15808:
    v_15840 = stack[-3];
    v_15840 = qcar(v_15840);
    v_15840 = Lmkquote(nil, v_15840);
    env = stack[-5];
    v_15840 = ncons(v_15840);
    env = stack[-5];
    stack[-1] = v_15840;
    stack[-2] = v_15840;
v_15767:
    v_15840 = stack[-3];
    v_15840 = qcdr(v_15840);
    stack[-3] = v_15840;
    v_15840 = stack[-3];
    if (v_15840 == nil) goto v_15821;
    else goto v_15822;
v_15821:
    v_15840 = stack[-2];
    goto v_15766;
v_15822:
    goto v_15830;
v_15826:
    stack[0] = stack[-1];
    goto v_15827;
v_15828:
    v_15840 = stack[-3];
    v_15840 = qcar(v_15840);
    v_15840 = Lmkquote(nil, v_15840);
    env = stack[-5];
    v_15840 = ncons(v_15840);
    env = stack[-5];
    goto v_15829;
v_15830:
    goto v_15826;
v_15827:
    goto v_15828;
v_15829:
    v_15840 = Lrplacd(nil, stack[0], v_15840);
    env = stack[-5];
    v_15840 = stack[-1];
    v_15840 = qcdr(v_15840);
    stack[-1] = v_15840;
    goto v_15767;
v_15766:
    goto v_15758;
v_15759:
    goto v_15755;
v_15756:
    goto v_15757;
v_15758:
    v_15840 = cons(stack[-4], v_15840);
    env = stack[-5];
    {
        fn = elt(env, 4); // lispeval
        return (*qfn1(fn))(fn, v_15840);
    }
}



// Code for doublep

static LispObject CC_doublep(LispObject env,
                         LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15776, v_15777;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15752);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15752);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_15776 = v_15752;
// end of prologue
// Binding d
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_15776; // d
    goto v_15767;
v_15763:
    v_15777 = qvalue(elt(env, 1)); // d
    goto v_15764;
v_15765:
    v_15776 = elt(env, 2); // !:rd!:
    goto v_15766;
v_15767:
    goto v_15763;
v_15764:
    goto v_15765;
v_15766:
    if (!consp(v_15777)) goto v_15761;
    v_15777 = qcar(v_15777);
    if (v_15777 == v_15776) goto v_15760;
    else goto v_15761;
v_15760:
    v_15776 = qvalue(elt(env, 1)); // d
    v_15776 = qcdr(v_15776);
    v_15776 = Lconsp(nil, v_15776);
    goto v_15759;
v_15761:
    v_15776 = nil;
    goto v_15759;
    v_15776 = nil;
v_15759:
    ;}  // end of a binding scope
    return onevalue(v_15776);
}



// Code for sc_geq

static LispObject CC_sc_geq(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15764, v_15765;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15751,v_15752);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15764 = v_15752;
    v_15765 = v_15751;
// end of prologue
    goto v_15760;
v_15756:
    goto v_15757;
v_15758:
    goto v_15759;
v_15760:
    goto v_15756;
v_15757:
    goto v_15758;
v_15759:
    fn = elt(env, 1); // sc_subtrsq
    v_15764 = (*qfn2(fn))(fn, v_15765, v_15764);
    env = stack[0];
    fn = elt(env, 2); // sc_minussq
    v_15764 = (*qfn1(fn))(fn, v_15764);
    v_15764 = (v_15764 == nil ? lisp_true : nil);
    return onevalue(v_15764);
}



// Code for evrevgradlexcomp

static LispObject CC_evrevgradlexcomp(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15824, v_15825;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15751,v_15752);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_15752;
    stack[-2] = v_15751;
// end of prologue
v_15756:
    v_15824 = stack[-2];
    if (v_15824 == nil) goto v_15759;
    else goto v_15760;
v_15759:
    v_15824 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15755;
v_15760:
    v_15824 = stack[-1];
    if (v_15824 == nil) goto v_15763;
    else goto v_15764;
v_15763:
    v_15824 = elt(env, 1); // (0)
    stack[-1] = v_15824;
    goto v_15756;
v_15764:
    goto v_15774;
v_15770:
    v_15824 = stack[-2];
    v_15825 = qcar(v_15824);
    goto v_15771;
v_15772:
    v_15824 = stack[-1];
    v_15824 = qcar(v_15824);
    goto v_15773;
v_15774:
    goto v_15770;
v_15771:
    goto v_15772;
v_15773:
    fn = elt(env, 2); // iequal
    v_15824 = (*qfn2(fn))(fn, v_15825, v_15824);
    env = stack[-4];
    if (v_15824 == nil) goto v_15768;
    v_15824 = stack[-2];
    v_15824 = qcdr(v_15824);
    stack[-2] = v_15824;
    v_15824 = stack[-1];
    v_15824 = qcdr(v_15824);
    stack[-1] = v_15824;
    goto v_15756;
v_15768:
    v_15824 = stack[-2];
    fn = elt(env, 3); // evtdeg
    stack[0] = (*qfn1(fn))(fn, v_15824);
    env = stack[-4];
    v_15824 = stack[-1];
    fn = elt(env, 3); // evtdeg
    v_15824 = (*qfn1(fn))(fn, v_15824);
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v_15824;
    goto v_15800;
v_15796:
    v_15825 = stack[-3];
    goto v_15797;
v_15798:
    v_15824 = stack[0];
    goto v_15799;
v_15800:
    goto v_15796;
v_15797:
    goto v_15798;
v_15799:
    fn = elt(env, 2); // iequal
    v_15824 = (*qfn2(fn))(fn, v_15825, v_15824);
    env = stack[-4];
    if (v_15824 == nil) goto v_15794;
    goto v_15808;
v_15804:
    v_15825 = stack[-2];
    goto v_15805;
v_15806:
    v_15824 = stack[-1];
    goto v_15807;
v_15808:
    goto v_15804;
v_15805:
    goto v_15806;
v_15807:
    {
        fn = elt(env, 4); // evinvlexcomp
        return (*qfn2(fn))(fn, v_15825, v_15824);
    }
v_15794:
    goto v_15817;
v_15813:
    v_15825 = stack[-3];
    goto v_15814;
v_15815:
    v_15824 = stack[0];
    goto v_15816;
v_15817:
    goto v_15813;
v_15814:
    goto v_15815;
v_15816:
    if (((intptr_t)(v_15825)) > ((intptr_t)(v_15824))) goto v_15811;
    else goto v_15812;
v_15811:
    v_15824 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15792;
v_15812:
    v_15824 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_15792;
    v_15824 = nil;
v_15792:
    goto v_15755;
    v_15824 = nil;
v_15755:
    return onevalue(v_15824);
}



// Code for physop!-multfnc

static LispObject CC_physopKmultfnc(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_16120, v_16121, v_16122;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15751,v_15752);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_15752;
    stack[-2] = v_15751;
// end of prologue
    goto v_15763;
v_15759:
    v_16120 = stack[-2];
    v_16120 = qcar(v_16120);
    stack[0] = qcdr(v_16120);
    goto v_15760;
v_15761:
    v_16120 = stack[-1];
    v_16120 = qcar(v_16120);
    v_16120 = ncons(v_16120);
    env = stack[-4];
    goto v_15762;
v_15763:
    goto v_15759;
v_15760:
    goto v_15761;
v_15762:
    fn = elt(env, 3); // physop!-multf
    v_16120 = (*qfn2(fn))(fn, stack[0], v_16120);
    env = stack[-4];
    stack[-3] = v_16120;
    v_16120 = stack[-3];
    if (v_16120 == nil) goto v_15772;
    else goto v_15773;
v_15772:
    goto v_15771;
v_15773:
    v_16120 = stack[-3];
    if (!consp(v_16120)) goto v_15784;
    else goto v_15785;
v_15784:
    v_16120 = lisp_true;
    goto v_15783;
v_15785:
    v_16120 = stack[-3];
    v_16120 = qcar(v_16120);
    v_16120 = (consp(v_16120) ? nil : lisp_true);
    goto v_15783;
    v_16120 = nil;
v_15783:
    if (v_16120 == nil) goto v_15780;
    else goto v_15781;
v_15780:
    goto v_15801;
v_15797:
    v_16120 = stack[-3];
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    v_16121 = qcar(v_16120);
    goto v_15798;
v_15799:
    v_16120 = stack[-2];
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    goto v_15800;
v_15801:
    goto v_15797;
v_15798:
    goto v_15799;
v_15800:
    if (v_16121 == v_16120) goto v_15795;
    else goto v_15796;
v_15795:
    v_16120 = stack[-3];
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    fn = elt(env, 4); // physopp
    v_16120 = (*qfn1(fn))(fn, v_16120);
    env = stack[-4];
    if (v_16120 == nil) goto v_15812;
    else goto v_15813;
v_15812:
    v_16120 = lisp_true;
    goto v_15811;
v_15813:
    v_16120 = qvalue(elt(env, 1)); // !*contract2
    goto v_15811;
    v_16120 = nil;
v_15811:
    goto v_15794;
v_15796:
    v_16120 = nil;
    goto v_15794;
    v_16120 = nil;
v_15794:
    goto v_15779;
v_15781:
    v_16120 = nil;
    goto v_15779;
    v_16120 = nil;
v_15779:
    if (v_16120 == nil) goto v_15777;
    goto v_15834;
v_15830:
    goto v_15844;
v_15840:
    v_16120 = stack[-2];
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    stack[0] = qcar(v_16120);
    goto v_15841;
v_15842:
    goto v_15854;
v_15850:
    v_16120 = stack[-2];
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    v_16121 = qcdr(v_16120);
    goto v_15851;
v_15852:
    v_16120 = stack[-3];
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    v_16120 = qcdr(v_16120);
    goto v_15853;
v_15854:
    goto v_15850;
v_15851:
    goto v_15852;
v_15853:
    v_16120 = plus2(v_16121, v_16120);
    env = stack[-4];
    goto v_15843;
v_15844:
    goto v_15840;
v_15841:
    goto v_15842;
v_15843:
    fn = elt(env, 5); // mkspm
    v_16120 = (*qfn2(fn))(fn, stack[0], v_16120);
    env = stack[-4];
    v_16122 = v_16120;
    if (v_16120 == nil) goto v_15837;
    else goto v_15838;
v_15837:
    v_16120 = nil;
    stack[0] = v_16120;
    goto v_15836;
v_15838:
    goto v_15870;
v_15866:
    v_16121 = v_16122;
    goto v_15867;
v_15868:
    v_16120 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15869;
v_15870:
    goto v_15866;
v_15867:
    goto v_15868;
v_15869:
    if (v_16121 == v_16120) goto v_15864;
    else goto v_15865;
v_15864:
    v_16120 = stack[-3];
    v_16120 = qcar(v_16120);
    v_16120 = qcdr(v_16120);
    stack[0] = v_16120;
    goto v_15836;
v_15865:
    goto v_15884;
v_15880:
    v_16121 = v_16122;
    goto v_15881;
v_15882:
    v_16120 = stack[-3];
    v_16120 = qcar(v_16120);
    v_16120 = qcdr(v_16120);
    goto v_15883;
v_15884:
    goto v_15880;
v_15881:
    goto v_15882;
v_15883:
    v_16120 = cons(v_16121, v_16120);
    env = stack[-4];
    v_16120 = ncons(v_16120);
    env = stack[-4];
    stack[0] = v_16120;
    goto v_15836;
    stack[0] = nil;
v_15836:
    goto v_15831;
v_15832:
    goto v_15894;
v_15890:
    goto v_15901;
v_15897:
    v_16120 = stack[-2];
    v_16120 = qcar(v_16120);
    v_16121 = qcar(v_16120);
    goto v_15898;
v_15899:
    v_16120 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15900;
v_15901:
    goto v_15897;
v_15898:
    goto v_15899;
v_15900:
    v_16120 = cons(v_16121, v_16120);
    env = stack[-4];
    v_16121 = ncons(v_16120);
    env = stack[-4];
    goto v_15891;
v_15892:
    v_16120 = stack[-3];
    v_16120 = qcdr(v_16120);
    goto v_15893;
v_15894:
    goto v_15890;
v_15891:
    goto v_15892;
v_15893:
    fn = elt(env, 3); // physop!-multf
    v_16120 = (*qfn2(fn))(fn, v_16121, v_16120);
    env = stack[-4];
    goto v_15833;
v_15834:
    goto v_15830;
v_15831:
    goto v_15832;
v_15833:
    fn = elt(env, 6); // addf
    v_16120 = (*qfn2(fn))(fn, stack[0], v_16120);
    env = stack[-4];
    stack[-3] = v_16120;
    goto v_15771;
v_15777:
    v_16120 = stack[-2];
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    if (!consp(v_16120)) goto v_15912;
    else goto v_15913;
v_15912:
    v_16120 = stack[-2];
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    if (!symbolp(v_16120)) v_16120 = nil;
    else { v_16120 = qfastgets(v_16120);
           if (v_16120 != nil) { v_16120 = elt(v_16120, 0); // noncom
#ifdef RECORD_GET
             if (v_16120 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_16120 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_16120 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_16120 == SPID_NOPROP) v_16120 = nil; else v_16120 = lisp_true; }}
#endif
    goto v_15911;
v_15913:
    v_16120 = stack[-2];
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    if (!symbolp(v_16120)) v_16120 = nil;
    else { v_16120 = qfastgets(v_16120);
           if (v_16120 != nil) { v_16120 = elt(v_16120, 0); // noncom
#ifdef RECORD_GET
             if (v_16120 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_16120 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_16120 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_16120 == SPID_NOPROP) v_16120 = nil; else v_16120 = lisp_true; }}
#endif
    goto v_15911;
    v_16120 = nil;
v_15911:
    if (v_16120 == nil) goto v_15909;
    goto v_15944;
v_15940:
    v_16120 = stack[-2];
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    v_16121 = qcar(v_16120);
    goto v_15941;
v_15942:
    v_16120 = stack[-3];
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    goto v_15943;
v_15944:
    goto v_15940;
v_15941:
    goto v_15942;
v_15943:
    fn = elt(env, 7); // noncommuting
    v_16120 = (*qfn2(fn))(fn, v_16121, v_16120);
    env = stack[-4];
    if (v_16120 == nil) goto v_15937;
    else goto v_15938;
v_15937:
    goto v_15958;
v_15954:
    v_16120 = stack[-2];
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    v_16121 = qcar(v_16120);
    goto v_15955;
v_15956:
    v_16120 = stack[-3];
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    goto v_15957;
v_15958:
    goto v_15954;
v_15955:
    goto v_15956;
v_15957:
    fn = elt(env, 8); // physop!-ordop
    v_16120 = (*qfn2(fn))(fn, v_16121, v_16120);
    env = stack[-4];
    v_16120 = (v_16120 == nil ? lisp_true : nil);
    goto v_15936;
v_15938:
    v_16120 = nil;
    goto v_15936;
    v_16120 = nil;
v_15936:
    if (v_16120 == nil) goto v_15934;
    goto v_15980;
v_15976:
    goto v_15987;
v_15983:
    v_16120 = stack[-2];
    v_16120 = qcar(v_16120);
    v_16121 = qcar(v_16120);
    goto v_15984;
v_15985:
    v_16120 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15986;
v_15987:
    goto v_15983;
v_15984:
    goto v_15985;
v_15986:
    v_16120 = cons(v_16121, v_16120);
    env = stack[-4];
    v_16121 = ncons(v_16120);
    env = stack[-4];
    goto v_15977;
v_15978:
    v_16120 = stack[-3];
    v_16120 = qcar(v_16120);
    v_16120 = qcdr(v_16120);
    goto v_15979;
v_15980:
    goto v_15976;
v_15977:
    goto v_15978;
v_15979:
    fn = elt(env, 3); // physop!-multf
    v_16120 = (*qfn2(fn))(fn, v_16121, v_16120);
    env = stack[-4];
    v_16122 = v_16120;
    if (v_16120 == nil) goto v_15973;
    else goto v_15974;
v_15973:
    goto v_16000;
v_15996:
    goto v_16007;
v_16003:
    v_16120 = stack[-2];
    v_16120 = qcar(v_16120);
    v_16121 = qcar(v_16120);
    goto v_16004;
v_16005:
    v_16120 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16006;
v_16007:
    goto v_16003;
v_16004:
    goto v_16005;
v_16006:
    v_16120 = cons(v_16121, v_16120);
    env = stack[-4];
    v_16121 = ncons(v_16120);
    env = stack[-4];
    goto v_15997;
v_15998:
    v_16120 = stack[-3];
    v_16120 = qcdr(v_16120);
    goto v_15999;
v_16000:
    goto v_15996;
v_15997:
    goto v_15998;
v_15999:
    fn = elt(env, 3); // physop!-multf
    v_16120 = (*qfn2(fn))(fn, v_16121, v_16120);
    env = stack[-4];
    stack[-3] = v_16120;
    goto v_15972;
v_15974:
    goto v_16021;
v_16017:
    goto v_16028;
v_16024:
    v_16120 = stack[-3];
    v_16120 = qcar(v_16120);
    v_16120 = qcar(v_16120);
    goto v_16025;
v_16026:
    v_16121 = v_16122;
    goto v_16027;
v_16028:
    goto v_16024;
v_16025:
    goto v_16026;
v_16027:
    v_16120 = cons(v_16120, v_16121);
    env = stack[-4];
    stack[0] = ncons(v_16120);
    env = stack[-4];
    goto v_16018;
v_16019:
    goto v_16038;
v_16034:
    goto v_16045;
v_16041:
    v_16120 = stack[-2];
    v_16120 = qcar(v_16120);
    v_16121 = qcar(v_16120);
    goto v_16042;
v_16043:
    v_16120 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16044;
v_16045:
    goto v_16041;
v_16042:
    goto v_16043;
v_16044:
    v_16120 = cons(v_16121, v_16120);
    env = stack[-4];
    v_16121 = ncons(v_16120);
    env = stack[-4];
    goto v_16035;
v_16036:
    v_16120 = stack[-3];
    v_16120 = qcdr(v_16120);
    goto v_16037;
v_16038:
    goto v_16034;
v_16035:
    goto v_16036;
v_16037:
    fn = elt(env, 3); // physop!-multf
    v_16120 = (*qfn2(fn))(fn, v_16121, v_16120);
    env = stack[-4];
    goto v_16020;
v_16021:
    goto v_16017;
v_16018:
    goto v_16019;
v_16020:
    fn = elt(env, 6); // addf
    v_16120 = (*qfn2(fn))(fn, stack[0], v_16120);
    env = stack[-4];
    stack[-3] = v_16120;
    goto v_15972;
v_15972:
    goto v_15932;
v_15934:
    goto v_16060;
v_16056:
    v_16120 = stack[-2];
    v_16120 = qcar(v_16120);
    v_16121 = qcar(v_16120);
    goto v_16057;
v_16058:
    v_16120 = stack[-3];
    goto v_16059;
v_16060:
    goto v_16056;
v_16057:
    goto v_16058;
v_16059:
    v_16120 = cons(v_16121, v_16120);
    env = stack[-4];
    v_16120 = ncons(v_16120);
    env = stack[-4];
    stack[-3] = v_16120;
    goto v_15932;
v_15932:
    goto v_15771;
v_15909:
    v_16120 = lisp_true;
// Binding !*!*processed
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 2, 0);
    qvalue(elt(env, 2)) = v_16120; // !*!*processed
    goto v_16074;
v_16070:
    goto v_16081;
v_16077:
    v_16120 = stack[-2];
    v_16120 = qcar(v_16120);
    v_16121 = qcar(v_16120);
    goto v_16078;
v_16079:
    v_16120 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16080;
v_16081:
    goto v_16077;
v_16078:
    goto v_16079;
v_16080:
    v_16120 = cons(v_16121, v_16120);
    env = stack[-4];
    v_16121 = ncons(v_16120);
    env = stack[-4];
    goto v_16071;
v_16072:
    v_16120 = stack[-3];
    goto v_16073;
v_16074:
    goto v_16070;
v_16071:
    goto v_16072;
v_16073:
    fn = elt(env, 3); // physop!-multf
    v_16120 = (*qfn2(fn))(fn, v_16121, v_16120);
    env = stack[-4];
    stack[-3] = v_16120;
    ;}  // end of a binding scope
    goto v_15771;
v_15771:
    goto v_16092;
v_16088:
    goto v_16089;
v_16090:
    goto v_16099;
v_16095:
    goto v_16105;
v_16101:
    v_16120 = stack[-2];
    v_16121 = qcdr(v_16120);
    goto v_16102;
v_16103:
    v_16120 = stack[-1];
    goto v_16104;
v_16105:
    goto v_16101;
v_16102:
    goto v_16103;
v_16104:
    fn = elt(env, 3); // physop!-multf
    stack[0] = (*qfn2(fn))(fn, v_16121, v_16120);
    env = stack[-4];
    goto v_16096;
v_16097:
    goto v_16114;
v_16110:
    v_16120 = stack[-2];
    v_16120 = qcar(v_16120);
    v_16121 = ncons(v_16120);
    env = stack[-4];
    goto v_16111;
v_16112:
    v_16120 = stack[-1];
    v_16120 = qcdr(v_16120);
    goto v_16113;
v_16114:
    goto v_16110;
v_16111:
    goto v_16112;
v_16113:
    fn = elt(env, 3); // physop!-multf
    v_16120 = (*qfn2(fn))(fn, v_16121, v_16120);
    env = stack[-4];
    goto v_16098;
v_16099:
    goto v_16095;
v_16096:
    goto v_16097;
v_16098:
    fn = elt(env, 6); // addf
    v_16120 = (*qfn2(fn))(fn, stack[0], v_16120);
    env = stack[-4];
    goto v_16091;
v_16092:
    goto v_16088;
v_16089:
    goto v_16090;
v_16091:
    {
        LispObject v_16127 = stack[-3];
        fn = elt(env, 6); // addf
        return (*qfn2(fn))(fn, v_16127, v_16120);
    }
    return onevalue(v_16120);
}



// Code for no!-side!-effect!-listp

static LispObject CC_noKsideKeffectKlistp(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15774;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15751;
// end of prologue
v_15750:
    v_15774 = stack[0];
    if (v_15774 == nil) goto v_15755;
    else goto v_15756;
v_15755:
    v_15774 = lisp_true;
    goto v_15754;
v_15756:
    v_15774 = stack[0];
    v_15774 = qcar(v_15774);
    fn = elt(env, 1); // no!-side!-effectp
    v_15774 = (*qfn1(fn))(fn, v_15774);
    env = stack[-1];
    if (v_15774 == nil) goto v_15763;
    else goto v_15764;
v_15763:
    v_15774 = nil;
    goto v_15762;
v_15764:
    v_15774 = stack[0];
    v_15774 = qcdr(v_15774);
    stack[0] = v_15774;
    goto v_15750;
    v_15774 = nil;
v_15762:
    goto v_15754;
    v_15774 = nil;
v_15754:
    return onevalue(v_15774);
}



// Code for red_tailred

static LispObject CC_red_tailred(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15783, v_15784, v_15785;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15783 = v_15752;
    v_15785 = v_15751;
// end of prologue
    v_15784 = qvalue(elt(env, 1)); // !*noetherian
    if (v_15784 == nil) goto v_15757;
    goto v_15766;
v_15760:
    goto v_15761;
v_15762:
    v_15784 = v_15783;
    goto v_15763;
v_15764:
    v_15783 = elt(env, 2); // red_topred
    goto v_15765;
v_15766:
    goto v_15760;
v_15761:
    goto v_15762;
v_15763:
    goto v_15764;
v_15765:
    {
        fn = elt(env, 4); // red_tailreddriver
        return (*qfnn(fn))(fn, 3, v_15785, v_15784, v_15783);
    }
v_15757:
    goto v_15779;
v_15773:
    goto v_15774;
v_15775:
    v_15784 = v_15783;
    goto v_15776;
v_15777:
    v_15783 = elt(env, 3); // red_topredbe
    goto v_15778;
v_15779:
    goto v_15773;
v_15774:
    goto v_15775;
v_15776:
    goto v_15777;
v_15778:
    {
        fn = elt(env, 4); // red_tailreddriver
        return (*qfnn(fn))(fn, 3, v_15785, v_15784, v_15783);
    }
    v_15783 = nil;
    return onevalue(v_15783);
}



// Code for all_sml_opchar

static LispObject CC_all_sml_opchar(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15796, v_15797;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15751;
// end of prologue
v_15750:
    v_15796 = stack[0];
    if (v_15796 == nil) goto v_15755;
    else goto v_15756;
v_15755:
    v_15796 = lisp_true;
    goto v_15754;
v_15756:
    goto v_15775;
v_15771:
    v_15797 = qvalue(elt(env, 1)); // lexer_style!*
    goto v_15772;
v_15773:
    v_15796 = (LispObject)2097152+TAG_FIXNUM; // 131072
    goto v_15774;
v_15775:
    goto v_15771;
v_15772:
    goto v_15773;
v_15774:
    fn = elt(env, 3); // land
    v_15796 = (*qfn2(fn))(fn, v_15797, v_15796);
    env = stack[-1];
    v_15796 = (LispObject)zerop(v_15796);
    v_15796 = v_15796 ? lisp_true : nil;
    env = stack[-1];
    if (v_15796 == nil) goto v_15767;
    else goto v_15768;
v_15767:
    goto v_15783;
v_15779:
    v_15796 = stack[0];
    v_15797 = qcar(v_15796);
    goto v_15780;
v_15781:
    v_15796 = elt(env, 2); // sml_opchar
    goto v_15782;
v_15783:
    goto v_15779;
v_15780:
    goto v_15781;
v_15782:
    v_15796 = Lflagp(nil, v_15797, v_15796);
    env = stack[-1];
    goto v_15766;
v_15768:
    v_15796 = nil;
    goto v_15766;
    v_15796 = nil;
v_15766:
    if (v_15796 == nil) goto v_15764;
    v_15796 = stack[0];
    v_15796 = qcdr(v_15796);
    stack[0] = v_15796;
    goto v_15750;
v_15764:
    v_15796 = nil;
    goto v_15762;
    v_15796 = nil;
v_15762:
    goto v_15754;
    v_15796 = nil;
v_15754:
    return onevalue(v_15796);
}



// Code for tayexp!-minus

static LispObject CC_tayexpKminus(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15764, v_15765;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15765 = v_15751;
// end of prologue
    v_15764 = v_15765;
    if (!consp(v_15764)) goto v_15755;
    else goto v_15756;
v_15755:
    v_15764 = v_15765;
    return negate(v_15764);
v_15756:
    v_15764 = v_15765;
    {
        fn = elt(env, 1); // rnminus!:
        return (*qfn1(fn))(fn, v_15764);
    }
    v_15764 = nil;
    return onevalue(v_15764);
}



// Code for talp_copy

static LispObject CC_talp_copy(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15823, v_15824;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_15824 = v_15751;
// end of prologue
    v_15823 = v_15824;
    if (!consp(v_15823)) goto v_15758;
    else goto v_15759;
v_15758:
    v_15823 = v_15824;
    goto v_15757;
v_15759:
    v_15823 = v_15824;
    stack[-3] = v_15823;
    v_15823 = stack[-3];
    if (v_15823 == nil) goto v_15773;
    else goto v_15774;
v_15773:
    v_15823 = nil;
    goto v_15768;
v_15774:
    v_15823 = stack[-3];
    v_15823 = qcar(v_15823);
    v_15824 = v_15823;
    v_15823 = v_15824;
    if (!consp(v_15823)) goto v_15783;
    else goto v_15784;
v_15783:
    v_15823 = v_15824;
    goto v_15782;
v_15784:
    v_15823 = v_15824;
    v_15823 = CC_talp_copy(elt(env, 0), v_15823);
    env = stack[-4];
    goto v_15782;
    v_15823 = nil;
v_15782:
    v_15823 = ncons(v_15823);
    env = stack[-4];
    stack[-1] = v_15823;
    stack[-2] = v_15823;
v_15769:
    v_15823 = stack[-3];
    v_15823 = qcdr(v_15823);
    stack[-3] = v_15823;
    v_15823 = stack[-3];
    if (v_15823 == nil) goto v_15795;
    else goto v_15796;
v_15795:
    v_15823 = stack[-2];
    goto v_15768;
v_15796:
    goto v_15804;
v_15800:
    stack[0] = stack[-1];
    goto v_15801;
v_15802:
    v_15823 = stack[-3];
    v_15823 = qcar(v_15823);
    v_15824 = v_15823;
    v_15823 = v_15824;
    if (!consp(v_15823)) goto v_15812;
    else goto v_15813;
v_15812:
    v_15823 = v_15824;
    goto v_15811;
v_15813:
    v_15823 = v_15824;
    v_15823 = CC_talp_copy(elt(env, 0), v_15823);
    env = stack[-4];
    goto v_15811;
    v_15823 = nil;
v_15811:
    v_15823 = ncons(v_15823);
    env = stack[-4];
    goto v_15803;
v_15804:
    goto v_15800;
v_15801:
    goto v_15802;
v_15803:
    v_15823 = Lrplacd(nil, stack[0], v_15823);
    env = stack[-4];
    v_15823 = stack[-1];
    v_15823 = qcdr(v_15823);
    stack[-1] = v_15823;
    goto v_15769;
v_15768:
    goto v_15757;
v_15757:
    return onevalue(v_15823);
}



// Code for qqe_arg!-check!-lb!-rb

static LispObject CC_qqe_argKcheckKlbKrb(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15796, v_15797;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15751;
// end of prologue
    v_15796 = stack[0];
    v_15796 = qcdr(v_15796);
    v_15796 = qcar(v_15796);
    v_15797 = v_15796;
    v_15796 = stack[0];
    v_15796 = qcdr(v_15796);
    v_15796 = qcdr(v_15796);
    v_15796 = qcar(v_15796);
    stack[-1] = v_15796;
    v_15796 = v_15797;
    fn = elt(env, 2); // qqe_arg!-check!-b
    v_15796 = (*qfn1(fn))(fn, v_15796);
    env = stack[-2];
    if (v_15796 == nil) goto v_15766;
    else goto v_15767;
v_15766:
    fn = elt(env, 3); // qqe_arg!-check!-marked!-ids!-rollback
    v_15796 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_15776;
v_15772:
    v_15797 = stack[0];
    goto v_15773;
v_15774:
    v_15796 = elt(env, 1); // "type conflict: arguments don't fit
//             binary op with basic type args"
    goto v_15775;
v_15776:
    goto v_15772;
v_15773:
    goto v_15774;
v_15775:
    fn = elt(env, 4); // typerr
    v_15796 = (*qfn2(fn))(fn, v_15797, v_15796);
    env = stack[-2];
    goto v_15765;
v_15767:
v_15765:
    v_15796 = stack[-1];
    fn = elt(env, 2); // qqe_arg!-check!-b
    v_15796 = (*qfn1(fn))(fn, v_15796);
    env = stack[-2];
    if (v_15796 == nil) goto v_15782;
    else goto v_15783;
v_15782:
    fn = elt(env, 3); // qqe_arg!-check!-marked!-ids!-rollback
    v_15796 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_15792;
v_15788:
    v_15797 = stack[0];
    goto v_15789;
v_15790:
    v_15796 = elt(env, 1); // "type conflict: arguments don't fit
//             binary op with basic type args"
    goto v_15791;
v_15792:
    goto v_15788;
v_15789:
    goto v_15790;
v_15791:
    fn = elt(env, 4); // typerr
    v_15796 = (*qfn2(fn))(fn, v_15797, v_15796);
    goto v_15781;
v_15783:
v_15781:
    v_15796 = nil;
    return onevalue(v_15796);
}



// Code for pasf_sisub!-gand

static LispObject CC_pasf_sisubKgand(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15871, v_15872, v_15873;
    LispObject fn;
    LispObject v_15756, v_15755, v_15754, v_15753, v_15752, v_15751;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "pasf_sisub-gand");
    va_start(aa, nargs);
    v_15751 = va_arg(aa, LispObject);
    v_15752 = va_arg(aa, LispObject);
    v_15753 = va_arg(aa, LispObject);
    v_15754 = va_arg(aa, LispObject);
    v_15755 = va_arg(aa, LispObject);
    v_15756 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_15756,v_15755,v_15754,v_15753,v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_15751,v_15752,v_15753,v_15754,v_15755,v_15756);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-1] = v_15756;
    stack[-2] = v_15755;
    stack[-3] = v_15754;
    stack[-4] = v_15753;
    stack[-5] = v_15752;
    stack[-6] = v_15751;
// end of prologue
    stack[0] = nil;
    v_15871 = lisp_true;
    stack[-7] = v_15871;
v_15767:
    v_15871 = stack[-7];
    if (v_15871 == nil) goto v_15770;
    v_15871 = stack[-5];
    if (v_15871 == nil) goto v_15770;
    goto v_15771;
v_15770:
    goto v_15766;
v_15771:
    v_15871 = stack[-5];
    v_15871 = qcar(v_15871);
    v_15872 = v_15871;
    v_15871 = stack[-5];
    v_15871 = qcdr(v_15871);
    stack[-5] = v_15871;
    v_15871 = v_15872;
    goto v_15793;
v_15787:
    v_15873 = v_15871;
    goto v_15788;
v_15789:
    v_15872 = stack[-4];
    goto v_15790;
v_15791:
    v_15871 = stack[-3];
    goto v_15792;
v_15793:
    goto v_15787;
v_15788:
    goto v_15789;
v_15790:
    goto v_15791;
v_15792:
    fn = elt(env, 4); // pasf_sisub
    v_15871 = (*qfnn(fn))(fn, 3, v_15873, v_15872, v_15871);
    env = stack[-8];
    v_15873 = v_15871;
    goto v_15805;
v_15801:
    v_15872 = v_15873;
    goto v_15802;
v_15803:
    v_15871 = stack[-1];
    goto v_15804;
v_15805:
    goto v_15801;
v_15802:
    goto v_15803;
v_15804:
    if (v_15872 == v_15871) goto v_15799;
    else goto v_15800;
v_15799:
    v_15871 = nil;
    stack[-7] = v_15871;
    goto v_15798;
v_15800:
    goto v_15815;
v_15811:
    v_15872 = v_15873;
    goto v_15812;
v_15813:
    v_15871 = stack[-2];
    goto v_15814;
v_15815:
    goto v_15811;
v_15812:
    goto v_15813;
v_15814:
    if (equal(v_15872, v_15871)) goto v_15810;
    goto v_15823;
v_15819:
    v_15872 = v_15873;
    goto v_15820;
v_15821:
    v_15871 = stack[0];
    goto v_15822;
v_15823:
    goto v_15819;
v_15820:
    goto v_15821;
v_15822:
    v_15871 = cons(v_15872, v_15871);
    env = stack[-8];
    stack[0] = v_15871;
    goto v_15798;
v_15810:
v_15798:
    goto v_15767;
v_15766:
    v_15871 = stack[-7];
    if (v_15871 == nil) goto v_15828;
    else goto v_15829;
v_15828:
    v_15871 = stack[-1];
    goto v_15763;
v_15829:
    v_15871 = stack[0];
    if (v_15871 == nil) goto v_15835;
    v_15871 = stack[0];
    v_15871 = qcdr(v_15871);
    if (v_15871 == nil) goto v_15835;
    goto v_15846;
v_15842:
    v_15872 = stack[-6];
    goto v_15843;
v_15844:
    v_15871 = stack[0];
    goto v_15845;
v_15846:
    goto v_15842;
v_15843:
    goto v_15844;
v_15845:
    return cons(v_15872, v_15871);
v_15835:
    v_15871 = stack[0];
    if (v_15871 == nil) goto v_15849;
    else goto v_15850;
v_15849:
    goto v_15860;
v_15856:
    v_15872 = stack[-6];
    goto v_15857;
v_15858:
    v_15871 = elt(env, 1); // and
    goto v_15859;
v_15860:
    goto v_15856;
v_15857:
    goto v_15858;
v_15859:
    if (v_15872 == v_15871) goto v_15854;
    else goto v_15855;
v_15854:
    v_15871 = elt(env, 2); // true
    goto v_15853;
v_15855:
    v_15871 = elt(env, 3); // false
    goto v_15853;
    v_15871 = nil;
v_15853:
    goto v_15833;
v_15850:
    v_15871 = stack[0];
    v_15871 = qcar(v_15871);
    goto v_15833;
    v_15871 = nil;
v_15833:
v_15763:
    return onevalue(v_15871);
}



// Code for dm!-mkfloat

static LispObject CC_dmKmkfloat(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15771, v_15772;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15771 = v_15751;
// end of prologue
    v_15772 = v_15771;
    v_15772 = Lintegerp(nil, v_15772);
    env = stack[0];
    if (v_15772 == nil) goto v_15756;
    goto v_15764;
v_15760:
    v_15772 = elt(env, 1); // !:rd!:
    if (!symbolp(v_15772)) v_15772 = nil;
    else { v_15772 = qfastgets(v_15772);
           if (v_15772 != nil) { v_15772 = elt(v_15772, 34); // i2d
#ifdef RECORD_GET
             if (v_15772 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_15772 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_15772 == SPID_NOPROP) v_15772 = nil; }}
#endif
    goto v_15761;
v_15762:
    goto v_15763;
v_15764:
    goto v_15760;
v_15761:
    goto v_15762;
v_15763:
        return Lapply1(nil, v_15772, v_15771);
v_15756:
    goto v_15754;
    v_15771 = nil;
v_15754:
    return onevalue(v_15771);
}



// Code for rd!:times

static LispObject CC_rdTtimes(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15931, v_15932, v_15933;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15751,v_15752);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15752;
    stack[-1] = v_15751;
// end of prologue
    v_15931 = nil;
    stack[-2] = v_15931;
    v_15931 = qvalue(elt(env, 1)); // !*!*roundbf
    if (v_15931 == nil) goto v_15762;
    else goto v_15763;
v_15762:
    v_15931 = stack[-1];
    v_15931 = qcdr(v_15931);
    if (!consp(v_15931)) goto v_15767;
    else goto v_15768;
v_15767:
    v_15931 = stack[0];
    v_15931 = qcdr(v_15931);
    if (!consp(v_15931)) goto v_15773;
    else goto v_15774;
v_15773:
    goto v_15782;
v_15778:
    v_15931 = stack[-1];
    v_15932 = qcdr(v_15931);
    goto v_15779;
v_15780:
    v_15931 = stack[0];
    v_15931 = qcdr(v_15931);
    goto v_15781;
v_15782:
    goto v_15778;
v_15779:
    goto v_15780;
v_15781:
    fn = elt(env, 4); // safe!-fp!-times
    v_15931 = (*qfn2(fn))(fn, v_15932, v_15931);
    env = stack[-3];
    stack[-2] = v_15931;
    goto v_15772;
v_15774:
    v_15931 = nil;
    goto v_15772;
    v_15931 = nil;
v_15772:
    goto v_15766;
v_15768:
    v_15931 = nil;
    goto v_15766;
    v_15931 = nil;
v_15766:
    goto v_15761;
v_15763:
    v_15931 = nil;
    goto v_15761;
    v_15931 = nil;
v_15761:
    if (v_15931 == nil) goto v_15759;
    goto v_15801;
v_15797:
    v_15932 = elt(env, 2); // !:rd!:
    goto v_15798;
v_15799:
    v_15931 = stack[-2];
    goto v_15800;
v_15801:
    goto v_15797;
v_15798:
    goto v_15799;
v_15800:
    return cons(v_15932, v_15931);
v_15759:
    goto v_15815;
v_15811:
    v_15932 = stack[-1];
    goto v_15812;
v_15813:
    v_15931 = stack[0];
    goto v_15814;
v_15815:
    goto v_15811;
v_15812:
    goto v_15813;
v_15814:
    fn = elt(env, 5); // convprc2
    v_15931 = (*qfn2(fn))(fn, v_15932, v_15931);
    env = stack[-3];
    stack[-1] = v_15931;
    v_15931 = qvalue(elt(env, 3)); // yy!!
    stack[0] = v_15931;
    v_15931 = stack[-1];
    if (!consp(v_15931)) goto v_15823;
    goto v_15830;
v_15826:
    v_15932 = stack[-1];
    goto v_15827;
v_15828:
    v_15931 = stack[0];
    goto v_15829;
v_15830:
    goto v_15826;
v_15827:
    goto v_15828;
v_15829:
    fn = elt(env, 6); // csl_timbf
    v_15931 = (*qfn2(fn))(fn, v_15932, v_15931);
    env = stack[-3];
    goto v_15821;
v_15823:
    goto v_15840;
v_15836:
    v_15932 = stack[-1];
    goto v_15837;
v_15838:
    v_15931 = stack[0];
    goto v_15839;
v_15840:
    goto v_15836;
v_15837:
    goto v_15838;
v_15839:
    v_15931 = times2(v_15932, v_15931);
    env = stack[-3];
    stack[-2] = v_15931;
    v_15931 = stack[-2];
    fn = elt(env, 7); // fp!-infinite
    v_15931 = (*qfn1(fn))(fn, v_15931);
    env = stack[-3];
    if (v_15931 == nil) goto v_15846;
    fn = elt(env, 8); // rndbfon
    v_15931 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_15855;
v_15851:
    v_15931 = stack[-1];
    v_15931 = Lfloatp(nil, v_15931);
    env = stack[-3];
    if (v_15931 == nil) goto v_15859;
    v_15931 = stack[-1];
    fn = elt(env, 9); // fl2bf
    v_15931 = (*qfn1(fn))(fn, v_15931);
    env = stack[-3];
    stack[-1] = v_15931;
    goto v_15857;
v_15859:
    v_15931 = stack[-1];
    if (!consp(v_15931)) goto v_15870;
    v_15931 = stack[-1];
    goto v_15868;
v_15870:
    v_15931 = stack[-1];
    v_15931 = integerp(v_15931);
    if (v_15931 == nil) goto v_15874;
    goto v_15884;
v_15878:
    v_15933 = elt(env, 2); // !:rd!:
    goto v_15879;
v_15880:
    v_15932 = stack[-1];
    goto v_15881;
v_15882:
    v_15931 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15883;
v_15884:
    goto v_15878;
v_15879:
    goto v_15880;
v_15881:
    goto v_15882;
v_15883:
    v_15931 = list2star(v_15933, v_15932, v_15931);
    env = stack[-3];
    goto v_15868;
v_15874:
    v_15931 = stack[-1];
    fn = elt(env, 10); // read!:num
    v_15931 = (*qfn1(fn))(fn, v_15931);
    env = stack[-3];
    goto v_15868;
    v_15931 = nil;
v_15868:
    fn = elt(env, 11); // normbf
    v_15931 = (*qfn1(fn))(fn, v_15931);
    env = stack[-3];
    stack[-1] = v_15931;
    goto v_15857;
    stack[-1] = nil;
v_15857:
    goto v_15852;
v_15853:
    v_15931 = stack[0];
    v_15931 = Lfloatp(nil, v_15931);
    env = stack[-3];
    if (v_15931 == nil) goto v_15895;
    v_15931 = stack[0];
    fn = elt(env, 9); // fl2bf
    v_15931 = (*qfn1(fn))(fn, v_15931);
    env = stack[-3];
    goto v_15893;
v_15895:
    v_15931 = stack[0];
    if (!consp(v_15931)) goto v_15906;
    v_15931 = stack[0];
    goto v_15904;
v_15906:
    v_15931 = stack[0];
    v_15931 = integerp(v_15931);
    if (v_15931 == nil) goto v_15910;
    goto v_15920;
v_15914:
    v_15933 = elt(env, 2); // !:rd!:
    goto v_15915;
v_15916:
    v_15932 = stack[0];
    goto v_15917;
v_15918:
    v_15931 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15919;
v_15920:
    goto v_15914;
v_15915:
    goto v_15916;
v_15917:
    goto v_15918;
v_15919:
    v_15931 = list2star(v_15933, v_15932, v_15931);
    env = stack[-3];
    goto v_15904;
v_15910:
    v_15931 = stack[0];
    fn = elt(env, 10); // read!:num
    v_15931 = (*qfn1(fn))(fn, v_15931);
    env = stack[-3];
    goto v_15904;
    v_15931 = nil;
v_15904:
    fn = elt(env, 11); // normbf
    v_15931 = (*qfn1(fn))(fn, v_15931);
    env = stack[-3];
    goto v_15893;
    v_15931 = nil;
v_15893:
    goto v_15854;
v_15855:
    goto v_15851;
v_15852:
    goto v_15853;
v_15854:
    fn = elt(env, 6); // csl_timbf
    v_15931 = (*qfn2(fn))(fn, stack[-1], v_15931);
    env = stack[-3];
    goto v_15844;
v_15846:
    v_15931 = stack[-2];
    goto v_15844;
    v_15931 = nil;
v_15844:
    goto v_15821;
    v_15931 = nil;
v_15821:
    {
        fn = elt(env, 12); // mkround
        return (*qfn1(fn))(fn, v_15931);
    }
    goto v_15757;
    v_15931 = nil;
v_15757:
    return onevalue(v_15931);
}



// Code for permp

static LispObject CC_permp(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15803, v_15804, v_15805, v_15806;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15751,v_15752);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_15804 = v_15752;
    v_15805 = v_15751;
// end of prologue
v_15756:
    v_15803 = v_15805;
    if (v_15803 == nil) goto v_15759;
    else goto v_15760;
v_15759:
    v_15803 = lisp_true;
    goto v_15755;
v_15760:
    goto v_15769;
v_15765:
    v_15803 = v_15805;
    v_15806 = qcar(v_15803);
    goto v_15766;
v_15767:
    v_15803 = v_15804;
    v_15803 = qcar(v_15803);
    goto v_15768;
v_15769:
    goto v_15765;
v_15766:
    goto v_15767;
v_15768:
    if (equal(v_15806, v_15803)) goto v_15763;
    else goto v_15764;
v_15763:
    v_15803 = v_15805;
    v_15803 = qcdr(v_15803);
    v_15805 = v_15803;
    v_15803 = v_15804;
    v_15803 = qcdr(v_15803);
    v_15804 = v_15803;
    goto v_15756;
v_15764:
    goto v_15785;
v_15781:
    v_15803 = v_15805;
    stack[0] = qcdr(v_15803);
    goto v_15782;
v_15783:
    goto v_15795;
v_15789:
    v_15803 = v_15804;
    v_15803 = qcar(v_15803);
    goto v_15790;
v_15791:
    v_15805 = qcar(v_15805);
    goto v_15792;
v_15793:
    v_15804 = qcdr(v_15804);
    goto v_15794;
v_15795:
    goto v_15789;
v_15790:
    goto v_15791;
v_15792:
    goto v_15793;
v_15794:
    v_15803 = Lsubst(nil, 3, v_15803, v_15805, v_15804);
    env = stack[-1];
    goto v_15784;
v_15785:
    goto v_15781;
v_15782:
    goto v_15783;
v_15784:
    v_15803 = CC_permp(elt(env, 0), stack[0], v_15803);
    v_15803 = (v_15803 == nil ? lisp_true : nil);
    goto v_15755;
    v_15803 = nil;
v_15755:
    return onevalue(v_15803);
}



// Code for subla!-q

static LispObject CC_sublaKq(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15933, v_15934;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15751,v_15752);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15752;
    stack[-1] = v_15751;
// end of prologue
    v_15933 = stack[-1];
    if (v_15933 == nil) goto v_15763;
    else goto v_15764;
v_15763:
    v_15933 = lisp_true;
    goto v_15762;
v_15764:
    v_15933 = stack[0];
    v_15933 = (v_15933 == nil ? lisp_true : nil);
    goto v_15762;
    v_15933 = nil;
v_15762:
    if (v_15933 == nil) goto v_15760;
    v_15933 = stack[0];
    goto v_15756;
v_15760:
    v_15933 = stack[0];
    if (!consp(v_15933)) goto v_15772;
    else goto v_15773;
v_15772:
    goto v_15783;
v_15779:
    v_15934 = stack[0];
    goto v_15780;
v_15781:
    v_15933 = stack[-1];
    goto v_15782;
v_15783:
    goto v_15779;
v_15780:
    goto v_15781;
v_15782:
    v_15934 = Latsoc(nil, v_15934, v_15933);
    v_15933 = v_15934;
    if (v_15934 == nil) goto v_15778;
    v_15933 = qcdr(v_15933);
    goto v_15776;
v_15778:
    v_15933 = stack[0];
    goto v_15776;
    v_15933 = nil;
v_15776:
    goto v_15756;
v_15773:
    goto v_15802;
v_15798:
    v_15933 = stack[0];
    v_15934 = qcar(v_15933);
    goto v_15799;
v_15800:
    v_15933 = elt(env, 1); // quote
    goto v_15801;
v_15802:
    goto v_15798;
v_15799:
    goto v_15800;
v_15801:
    if (v_15934 == v_15933) goto v_15796;
    else goto v_15797;
v_15796:
    v_15933 = lisp_true;
    goto v_15795;
v_15797:
    goto v_15813;
v_15809:
    v_15933 = stack[0];
    v_15934 = qcar(v_15933);
    goto v_15810;
v_15811:
    v_15933 = elt(env, 2); // go
    goto v_15812;
v_15813:
    goto v_15809;
v_15810:
    goto v_15811;
v_15812:
    v_15933 = (v_15934 == v_15933 ? lisp_true : nil);
    goto v_15795;
    v_15933 = nil;
v_15795:
    if (v_15933 == nil) goto v_15793;
    v_15933 = stack[0];
    goto v_15756;
v_15793:
    goto v_15834;
v_15830:
    v_15934 = stack[0];
    goto v_15831;
v_15832:
    v_15933 = elt(env, 3); // lambda
    goto v_15833;
v_15834:
    goto v_15830;
v_15831:
    goto v_15832;
v_15833:
    if (!consp(v_15934)) goto v_15828;
    v_15934 = qcar(v_15934);
    if (v_15934 == v_15933) goto v_15827;
    else goto v_15828;
v_15827:
    v_15933 = lisp_true;
    goto v_15826;
v_15828:
    goto v_15845;
v_15841:
    v_15934 = stack[0];
    goto v_15842;
v_15843:
    v_15933 = elt(env, 4); // prog
    goto v_15844;
v_15845:
    goto v_15841;
v_15842:
    goto v_15843;
v_15844:
    v_15933 = Leqcar(nil, v_15934, v_15933);
    env = stack[-3];
    goto v_15826;
    v_15933 = nil;
v_15826:
    if (v_15933 == nil) goto v_15824;
    v_15933 = stack[0];
    v_15933 = qcdr(v_15933);
    v_15933 = (consp(v_15933) ? nil : lisp_true);
    v_15933 = (v_15933 == nil ? lisp_true : nil);
    goto v_15822;
v_15824:
    v_15933 = nil;
    goto v_15822;
    v_15933 = nil;
v_15822:
    if (v_15933 == nil) goto v_15820;
    v_15933 = stack[0];
    v_15933 = qcdr(v_15933);
    v_15933 = qcar(v_15933);
    stack[-2] = v_15933;
v_15861:
    v_15933 = stack[-2];
    if (v_15933 == nil) goto v_15865;
    else goto v_15866;
v_15865:
    goto v_15860;
v_15866:
    v_15933 = stack[-2];
    v_15933 = qcar(v_15933);
    goto v_15877;
v_15873:
    v_15934 = v_15933;
    goto v_15874;
v_15875:
    v_15933 = stack[-1];
    goto v_15876;
v_15877:
    goto v_15873;
v_15874:
    goto v_15875;
v_15876:
    fn = elt(env, 5); // delasc
    v_15933 = (*qfn2(fn))(fn, v_15934, v_15933);
    env = stack[-3];
    stack[-1] = v_15933;
    v_15933 = stack[-2];
    v_15933 = qcdr(v_15933);
    stack[-2] = v_15933;
    goto v_15861;
v_15860:
    goto v_15887;
v_15883:
    goto v_15893;
v_15889:
    v_15934 = stack[-1];
    goto v_15890;
v_15891:
    v_15933 = stack[0];
    v_15933 = qcar(v_15933);
    goto v_15892;
v_15893:
    goto v_15889;
v_15890:
    goto v_15891;
v_15892:
    stack[-2] = CC_sublaKq(elt(env, 0), v_15934, v_15933);
    env = stack[-3];
    goto v_15884;
v_15885:
    goto v_15902;
v_15898:
    v_15934 = stack[-1];
    goto v_15899;
v_15900:
    v_15933 = stack[0];
    v_15933 = qcdr(v_15933);
    goto v_15901;
v_15902:
    goto v_15898;
v_15899:
    goto v_15900;
v_15901:
    v_15933 = CC_sublaKq(elt(env, 0), v_15934, v_15933);
    goto v_15886;
v_15887:
    goto v_15883;
v_15884:
    goto v_15885;
v_15886:
    {
        LispObject v_15938 = stack[-2];
        return cons(v_15938, v_15933);
    }
v_15820:
    goto v_15914;
v_15910:
    goto v_15920;
v_15916:
    v_15934 = stack[-1];
    goto v_15917;
v_15918:
    v_15933 = stack[0];
    v_15933 = qcar(v_15933);
    goto v_15919;
v_15920:
    goto v_15916;
v_15917:
    goto v_15918;
v_15919:
    stack[-2] = CC_sublaKq(elt(env, 0), v_15934, v_15933);
    env = stack[-3];
    goto v_15911;
v_15912:
    goto v_15929;
v_15925:
    v_15934 = stack[-1];
    goto v_15926;
v_15927:
    v_15933 = stack[0];
    v_15933 = qcdr(v_15933);
    goto v_15928;
v_15929:
    goto v_15925;
v_15926:
    goto v_15927;
v_15928:
    v_15933 = CC_sublaKq(elt(env, 0), v_15934, v_15933);
    goto v_15913;
v_15914:
    goto v_15910;
v_15911:
    goto v_15912;
v_15913:
    {
        LispObject v_15939 = stack[-2];
        return cons(v_15939, v_15933);
    }
    v_15933 = nil;
v_15756:
    return onevalue(v_15933);
}



// Code for groeb!=rf1

static LispObject CC_groebMrf1(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15769, v_15770;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15751,v_15752);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_15752;
    v_15769 = v_15751;
// end of prologue
    goto v_15759;
v_15755:
    goto v_15765;
v_15761:
    v_15770 = stack[0];
    goto v_15762;
v_15763:
    goto v_15764;
v_15765:
    goto v_15761;
v_15762:
    goto v_15763;
v_15764:
    fn = elt(env, 1); // red_totalred
    v_15770 = (*qfn2(fn))(fn, v_15770, v_15769);
    goto v_15756;
v_15757:
    v_15769 = stack[0];
    goto v_15758;
v_15759:
    goto v_15755;
v_15756:
    goto v_15757;
v_15758:
    return list2(v_15770, v_15769);
}



// Code for qtypnm

static LispObject CC_qtypnm(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15932, v_15933, v_15934;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15751,v_15752);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_15752;
    stack[-4] = v_15751;
// end of prologue
    goto v_15763;
v_15759:
    v_15933 = stack[-3];
    goto v_15760;
v_15761:
    v_15932 = elt(env, 1); // function
    goto v_15762;
v_15763:
    goto v_15759;
v_15760:
    goto v_15761;
v_15762:
    v_15932 = Lflagp(nil, v_15933, v_15932);
    env = stack[-6];
    if (v_15932 == nil) goto v_15757;
    goto v_15775;
v_15771:
    v_15933 = stack[-4];
    goto v_15772;
v_15773:
    v_15932 = elt(env, 2); // seen
    goto v_15774;
v_15775:
    goto v_15771;
v_15772:
    goto v_15773;
v_15774:
    v_15932 = Lflagp(nil, v_15933, v_15932);
    env = stack[-6];
    if (v_15932 == nil) goto v_15768;
    else goto v_15769;
v_15768:
    goto v_15783;
v_15779:
    v_15932 = stack[-4];
    v_15933 = ncons(v_15932);
    env = stack[-6];
    goto v_15780;
v_15781:
    v_15932 = elt(env, 2); // seen
    goto v_15782;
v_15783:
    goto v_15779;
v_15780:
    goto v_15781;
v_15782:
    v_15932 = Lflag(nil, v_15933, v_15932);
    env = stack[-6];
    goto v_15792;
v_15788:
    v_15933 = stack[-4];
    goto v_15789;
v_15790:
    v_15932 = qvalue(elt(env, 3)); // seen!*
    goto v_15791;
v_15792:
    goto v_15788;
v_15789:
    goto v_15790;
v_15791:
    v_15932 = cons(v_15933, v_15932);
    env = stack[-6];
    qvalue(elt(env, 3)) = v_15932; // seen!*
    goto v_15767;
v_15769:
v_15767:
    v_15932 = stack[-4];
    goto v_15755;
v_15757:
    goto v_15813;
v_15809:
    v_15933 = stack[-3];
    goto v_15810;
v_15811:
    v_15932 = elt(env, 4); // tseen
    goto v_15812;
v_15813:
    goto v_15809;
v_15810:
    goto v_15811;
v_15812:
    v_15932 = get(v_15933, v_15932);
    env = stack[-6];
    stack[-2] = v_15932;
    if (v_15932 == nil) goto v_15806;
    goto v_15821;
v_15817:
    v_15933 = stack[-4];
    goto v_15818;
v_15819:
    v_15932 = stack[-2];
    v_15932 = qcdr(v_15932);
    goto v_15820;
v_15821:
    goto v_15817;
v_15818:
    goto v_15819;
v_15820:
    v_15932 = Latsoc(nil, v_15933, v_15932);
    stack[-5] = v_15932;
    if (v_15932 == nil) goto v_15806;
    v_15932 = stack[-5];
    v_15932 = qcdr(v_15932);
    goto v_15802;
v_15806:
    v_15932 = stack[-2];
    if (v_15932 == nil) goto v_15830;
    else goto v_15831;
v_15830:
    goto v_15839;
v_15835:
    stack[-1] = elt(env, 5); // !(
    goto v_15836;
v_15837:
    goto v_15846;
v_15842:
    v_15932 = stack[-3];
    stack[0] = Lexplode(nil, v_15932);
    env = stack[-6];
    goto v_15843;
v_15844:
    v_15932 = elt(env, 6); // !)
    v_15932 = ncons(v_15932);
    env = stack[-6];
    goto v_15845;
v_15846:
    goto v_15842;
v_15843:
    goto v_15844;
v_15845:
    v_15932 = Lnconc(nil, stack[0], v_15932);
    env = stack[-6];
    goto v_15838;
v_15839:
    goto v_15835;
v_15836:
    goto v_15837;
v_15838:
    v_15932 = cons(stack[-1], v_15932);
    env = stack[-6];
    v_15932 = ncons(v_15932);
    env = stack[-6];
    stack[-2] = v_15932;
    goto v_15858;
v_15852:
    v_15934 = stack[-3];
    goto v_15853;
v_15854:
    v_15933 = elt(env, 4); // tseen
    goto v_15855;
v_15856:
    v_15932 = stack[-2];
    goto v_15857;
v_15858:
    goto v_15852;
v_15853:
    goto v_15854;
v_15855:
    goto v_15856;
v_15857:
    v_15932 = Lputprop(nil, 3, v_15934, v_15933, v_15932);
    env = stack[-6];
    goto v_15867;
v_15863:
    v_15933 = stack[-3];
    goto v_15864;
v_15865:
    v_15932 = qvalue(elt(env, 7)); // tseen!*
    goto v_15866;
v_15867:
    goto v_15863;
v_15864:
    goto v_15865;
v_15866:
    v_15932 = cons(v_15933, v_15932);
    env = stack[-6];
    qvalue(elt(env, 7)) = v_15932; // tseen!*
    goto v_15829;
v_15831:
v_15829:
    v_15932 = stack[-4];
    v_15932 = Lexplode(nil, v_15932);
    env = stack[-6];
    stack[-1] = v_15932;
    v_15932 = Lcompress(nil, v_15932);
    env = stack[-6];
    stack[-5] = v_15932;
    goto v_15878;
v_15874:
    stack[0] = stack[-2];
    goto v_15875;
v_15876:
    goto v_15887;
v_15881:
    v_15934 = stack[-4];
    goto v_15882;
v_15883:
    v_15933 = stack[-5];
    goto v_15884;
v_15885:
    v_15932 = stack[-2];
    v_15932 = qcdr(v_15932);
    goto v_15886;
v_15887:
    goto v_15881;
v_15882:
    goto v_15883;
v_15884:
    goto v_15885;
v_15886:
    v_15932 = acons(v_15934, v_15933, v_15932);
    env = stack[-6];
    goto v_15877;
v_15878:
    goto v_15874;
v_15875:
    goto v_15876;
v_15877:
    v_15932 = Lrplacd(nil, stack[0], v_15932);
    env = stack[-6];
    goto v_15897;
v_15893:
    v_15932 = stack[-2];
    v_15933 = qcar(v_15932);
    goto v_15894;
v_15895:
    v_15932 = stack[-1];
    goto v_15896;
v_15897:
    goto v_15893;
v_15894:
    goto v_15895;
v_15896:
    v_15932 = Lappend(nil, v_15933, v_15932);
    env = stack[-6];
    stack[-2] = v_15932;
    goto v_15908;
v_15902:
    stack[-1] = stack[-5];
    goto v_15903;
v_15904:
    stack[0] = elt(env, 8); // rccnam
    goto v_15905;
v_15906:
    goto v_15916;
v_15912:
    v_15932 = stack[-2];
    v_15933 = Llength(nil, v_15932);
    env = stack[-6];
    goto v_15913;
v_15914:
    v_15932 = stack[-2];
    goto v_15915;
v_15916:
    goto v_15912;
v_15913:
    goto v_15914;
v_15915:
    v_15932 = cons(v_15933, v_15932);
    env = stack[-6];
    goto v_15907;
v_15908:
    goto v_15902;
v_15903:
    goto v_15904;
v_15905:
    goto v_15906;
v_15907:
    v_15932 = Lputprop(nil, 3, stack[-1], stack[0], v_15932);
    env = stack[-6];
    goto v_15927;
v_15921:
    v_15934 = stack[-3];
    goto v_15922;
v_15923:
    v_15933 = elt(env, 9); // funs
    goto v_15924;
v_15925:
    v_15932 = stack[-5];
    goto v_15926;
v_15927:
    goto v_15921;
v_15922:
    goto v_15923;
v_15924:
    goto v_15925;
v_15926:
    fn = elt(env, 10); // traput
    v_15932 = (*qfnn(fn))(fn, 3, v_15934, v_15933, v_15932);
    v_15932 = stack[-5];
v_15802:
    goto v_15755;
    v_15932 = nil;
v_15755:
    return onevalue(v_15932);
}



// Code for negind

static LispObject CC_negind(LispObject env,
                         LispObject v_15751, LispObject v_15752)
{
    env = qenv(env);
    LispObject v_15793, v_15794;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15751,v_15752);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15752;
    stack[-1] = v_15751;
// end of prologue
v_15750:
    v_15793 = stack[-1];
    if (v_15793 == nil) goto v_15756;
    else goto v_15757;
v_15756:
    v_15793 = nil;
    goto v_15755;
v_15757:
    goto v_15770;
v_15766:
    goto v_15776;
v_15772:
    v_15793 = stack[-1];
    v_15794 = qcar(v_15793);
    goto v_15773;
v_15774:
    v_15793 = stack[0];
    v_15793 = qcar(v_15793);
    v_15793 = qcar(v_15793);
    goto v_15775;
v_15776:
    goto v_15772;
v_15773:
    goto v_15774;
v_15775:
    v_15794 = plus2(v_15794, v_15793);
    env = stack[-2];
    goto v_15767;
v_15768:
    v_15793 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15769;
v_15770:
    goto v_15766;
v_15767:
    goto v_15768;
v_15769:
    v_15793 = (LispObject)lessp2(v_15794, v_15793);
    v_15793 = v_15793 ? lisp_true : nil;
    env = stack[-2];
    if (v_15793 == nil) goto v_15764;
    else goto v_15763;
v_15764:
    goto v_15788;
v_15784:
    v_15793 = stack[-1];
    v_15794 = qcdr(v_15793);
    goto v_15785;
v_15786:
    v_15793 = stack[0];
    v_15793 = qcdr(v_15793);
    goto v_15787;
v_15788:
    goto v_15784;
v_15785:
    goto v_15786;
v_15787:
    stack[-1] = v_15794;
    stack[0] = v_15793;
    goto v_15750;
v_15763:
    goto v_15755;
    v_15793 = nil;
v_15755:
    return onevalue(v_15793);
}



// Code for talp_specsubat

static LispObject CC_talp_specsubat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15790;
    LispObject fn;
    LispObject v_15753, v_15752, v_15751;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_specsubat");
    va_start(aa, nargs);
    v_15751 = va_arg(aa, LispObject);
    v_15752 = va_arg(aa, LispObject);
    v_15753 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15753,v_15752,v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15751,v_15752,v_15753);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_15753;
    stack[-3] = v_15752;
    stack[-4] = v_15751;
// end of prologue
    goto v_15763;
v_15757:
    v_15790 = stack[-2];
    fn = elt(env, 1); // talp_op
    stack[-5] = (*qfn1(fn))(fn, v_15790);
    env = stack[-6];
    goto v_15758;
v_15759:
    goto v_15773;
v_15767:
    stack[-1] = stack[-4];
    goto v_15768;
v_15769:
    stack[0] = stack[-3];
    goto v_15770;
v_15771:
    v_15790 = stack[-2];
    fn = elt(env, 2); // talp_arg2l
    v_15790 = (*qfn1(fn))(fn, v_15790);
    env = stack[-6];
    goto v_15772;
v_15773:
    goto v_15767;
v_15768:
    goto v_15769;
v_15770:
    goto v_15771;
v_15772:
    fn = elt(env, 3); // talp_specsubt
    stack[0] = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_15790);
    env = stack[-6];
    goto v_15760;
v_15761:
    goto v_15785;
v_15779:
    stack[-1] = stack[-4];
    goto v_15780;
v_15781:
    goto v_15782;
v_15783:
    v_15790 = stack[-2];
    fn = elt(env, 4); // talp_arg2r
    v_15790 = (*qfn1(fn))(fn, v_15790);
    env = stack[-6];
    goto v_15784;
v_15785:
    goto v_15779;
v_15780:
    goto v_15781;
v_15782:
    goto v_15783;
v_15784:
    fn = elt(env, 3); // talp_specsubt
    v_15790 = (*qfnn(fn))(fn, 3, stack[-1], stack[-3], v_15790);
    env = stack[-6];
    goto v_15762;
v_15763:
    goto v_15757;
v_15758:
    goto v_15759;
v_15760:
    goto v_15761;
v_15762:
    fn = elt(env, 5); // talp_mk2
    v_15790 = (*qfnn(fn))(fn, 3, stack[-5], stack[0], v_15790);
    env = stack[-6];
    {
        fn = elt(env, 6); // talp_simpat
        return (*qfn1(fn))(fn, v_15790);
    }
}



// Code for qqe_ofsf_simpat

static LispObject CC_qqe_ofsf_simpat(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15782, v_15783;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15751;
// end of prologue
    v_15782 = stack[0];
    fn = elt(env, 2); // qqe_arg2l
    v_15782 = (*qfn1(fn))(fn, v_15782);
    env = stack[-1];
    fn = elt(env, 3); // qqe_ofsf_chsimpterm
    v_15782 = (*qfn1(fn))(fn, v_15782);
    env = stack[-1];
    v_15782 = stack[0];
    fn = elt(env, 4); // qqe_arg2r
    v_15782 = (*qfn1(fn))(fn, v_15782);
    env = stack[-1];
    fn = elt(env, 3); // qqe_ofsf_chsimpterm
    v_15782 = (*qfn1(fn))(fn, v_15782);
    env = stack[-1];
    v_15782 = stack[0];
    fn = elt(env, 5); // qqe_arg!-check
    v_15782 = (*qfn1(fn))(fn, v_15782);
    env = stack[-1];
    goto v_15771;
v_15767:
    v_15782 = stack[0];
    fn = elt(env, 6); // qqe_op
    v_15783 = (*qfn1(fn))(fn, v_15782);
    env = stack[-1];
    goto v_15768;
v_15769:
    v_15782 = elt(env, 1); // (qequal qneq)
    goto v_15770;
v_15771:
    goto v_15767;
v_15768:
    goto v_15769;
v_15770:
    v_15782 = Lmemq(nil, v_15783, v_15782);
    if (v_15782 == nil) goto v_15766;
    v_15782 = stack[0];
    {
        fn = elt(env, 7); // qqe_simpat
        return (*qfn1(fn))(fn, v_15782);
    }
v_15766:
    v_15782 = stack[0];
    {
        fn = elt(env, 8); // ofsf_simpat
        return (*qfn1(fn))(fn, v_15782);
    }
    v_15782 = nil;
    return onevalue(v_15782);
}



// Code for getdec

static LispObject CC_getdec(LispObject env,
                         LispObject v_15751)
{
    env = qenv(env);
    LispObject v_15772, v_15773;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15751);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15751);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15751;
// end of prologue
    goto v_15761;
v_15757:
    v_15773 = nil;
    goto v_15758;
v_15759:
    v_15772 = stack[0];
    goto v_15760;
v_15761:
    goto v_15757;
v_15758:
    goto v_15759;
v_15760:
    fn = elt(env, 1); // symtabget
    v_15772 = (*qfn2(fn))(fn, v_15773, v_15772);
    env = stack[-1];
    v_15773 = v_15772;
    v_15772 = v_15773;
    if (v_15772 == nil) goto v_15766;
    else goto v_15767;
v_15766:
    v_15772 = stack[0];
    fn = elt(env, 2); // implicitdec
    v_15772 = (*qfn1(fn))(fn, v_15772);
    v_15773 = v_15772;
    goto v_15765;
v_15767:
v_15765:
    v_15772 = v_15773;
    return onevalue(v_15772);
}



setup_type const u29_setup[] =
{
    {"dipnumcontent",           TOO_FEW_2,      CC_dipnumcontent,WRONG_NO_2},
    {"groebsavelterm",          CC_groebsavelterm,TOO_MANY_1,  WRONG_NO_1},
    {"vevstrictlydivides?",     TOO_FEW_2,      CC_vevstrictlydividesW,WRONG_NO_2},
    {"ordexp",                  TOO_FEW_2,      CC_ordexp,     WRONG_NO_2},
    {"l-subst",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lKsubst},
    {"formde",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formde},
    {"sqhorner*",               CC_sqhornerH,   TOO_MANY_1,    WRONG_NO_1},
    {"no_dum_varp",             CC_no_dum_varp, TOO_MANY_1,    WRONG_NO_1},
    {"proper-simpsqrt",         CC_properKsimpsqrt,TOO_MANY_1, WRONG_NO_1},
    {"delasc",                  TOO_FEW_2,      CC_delasc,     WRONG_NO_2},
    {"sortedtriplelistinsert",  TOO_FEW_2,      CC_sortedtriplelistinsert,WRONG_NO_2},
    {"add-degrees",             TOO_FEW_2,      CC_addKdegrees,WRONG_NO_2},
    {"qqe_arg-check-q",         CC_qqe_argKcheckKq,TOO_MANY_1, WRONG_NO_1},
    {"cl_susiupdknowl",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_susiupdknowl},
    {"cnrd",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cnrd},
    {"ps:expression",           CC_psTexpression,TOO_MANY_1,   WRONG_NO_1},
    {"bcfd",                    CC_bcfd,        TOO_MANY_1,    WRONG_NO_1},
    {"critical_element",        CC_critical_element,TOO_MANY_1,WRONG_NO_1},
    {"contract-strand",         TOO_FEW_2,      CC_contractKstrand,WRONG_NO_2},
    {"assert_declarestat1",     CC_assert_declarestat1,TOO_MANY_1,WRONG_NO_1},
    {"sf2mv",                   TOO_FEW_2,      CC_sf2mv,      WRONG_NO_2},
    {"fs:prepfn:",              CC_fsTprepfnT,  TOO_MANY_1,    WRONG_NO_1},
    {"st_consolidate",          CC_st_consolidate,TOO_MANY_1,  WRONG_NO_1},
    {"ratminus",                CC_ratminus,    TOO_MANY_1,    WRONG_NO_1},
    {"sfto_lessq",              TOO_FEW_2,      CC_sfto_lessq, WRONG_NO_2},
    {"lalr_prin_reduction",     CC_lalr_prin_reduction,TOO_MANY_1,WRONG_NO_1},
    {"gcref_off",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gcref_off},
    {"ofsf_posvarp",            TOO_FEW_2,      CC_ofsf_posvarp,WRONG_NO_2},
    {"cquotegex",               CC_cquotegex,   TOO_MANY_1,    WRONG_NO_1},
    {"simpexpt11",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_simpexpt11},
    {"rndifference:",           TOO_FEW_2,      CC_rndifferenceT,WRONG_NO_2},
    {"mk+trace",                CC_mkLtrace,    TOO_MANY_1,    WRONG_NO_1},
    {"cl_atl1",                 CC_cl_atl1,     TOO_MANY_1,    WRONG_NO_1},
    {"aex_bvarl",               CC_aex_bvarl,   TOO_MANY_1,    WRONG_NO_1},
    {"opfneval",                CC_opfneval,    TOO_MANY_1,    WRONG_NO_1},
    {"doublep",                 CC_doublep,     TOO_MANY_1,    WRONG_NO_1},
    {"sc_geq",                  TOO_FEW_2,      CC_sc_geq,     WRONG_NO_2},
    {"evrevgradlexcomp",        TOO_FEW_2,      CC_evrevgradlexcomp,WRONG_NO_2},
    {"physop-multfnc",          TOO_FEW_2,      CC_physopKmultfnc,WRONG_NO_2},
    {"no-side-effect-listp",    CC_noKsideKeffectKlistp,TOO_MANY_1,WRONG_NO_1},
    {"red_tailred",             TOO_FEW_2,      CC_red_tailred,WRONG_NO_2},
    {"all_sml_opchar",          CC_all_sml_opchar,TOO_MANY_1,  WRONG_NO_1},
    {"tayexp-minus",            CC_tayexpKminus,TOO_MANY_1,    WRONG_NO_1},
    {"talp_copy",               CC_talp_copy,   TOO_MANY_1,    WRONG_NO_1},
    {"qqe_arg-check-lb-rb",     CC_qqe_argKcheckKlbKrb,TOO_MANY_1,WRONG_NO_1},
    {"pasf_sisub-gand",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pasf_sisubKgand},
    {"dm-mkfloat",              CC_dmKmkfloat,  TOO_MANY_1,    WRONG_NO_1},
    {"rd:times",                TOO_FEW_2,      CC_rdTtimes,   WRONG_NO_2},
    {"permp",                   TOO_FEW_2,      CC_permp,      WRONG_NO_2},
    {"subla-q",                 TOO_FEW_2,      CC_sublaKq,    WRONG_NO_2},
    {"groeb=rf1",               TOO_FEW_2,      CC_groebMrf1,  WRONG_NO_2},
    {"qtypnm",                  TOO_FEW_2,      CC_qtypnm,     WRONG_NO_2},
    {"negind",                  TOO_FEW_2,      CC_negind,     WRONG_NO_2},
    {"talp_specsubat",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_specsubat},
    {"qqe_ofsf_simpat",         CC_qqe_ofsf_simpat,TOO_MANY_1, WRONG_NO_1},
    {"getdec",                  CC_getdec,      TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u29", (two_args *)"48475 4769976 1722301", 0}
};

// end of generated code
