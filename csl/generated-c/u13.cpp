
// $destdir/u13.c        Machine generated C code

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



// Code for gcdf2

static LispObject CC_gcdf2(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7384, v_7385, v_7386;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_7065;
    stack[-5] = v_7064;
// end of prologue
// Binding asymplis!*
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
    qvalue(elt(env, 1)) = nil; // asymplis!*
    v_7384 = qvalue(elt(env, 2)); // !*anygcd
    if (v_7384 == nil) goto v_7078;
    else goto v_7079;
v_7078:
    v_7384 = lisp_true;
    goto v_7077;
v_7079:
    v_7384 = stack[-5];
    fn = elt(env, 4); // num!-exponents
    v_7384 = (*qfn1(fn))(fn, v_7384);
    env = stack[-7];
    if (v_7384 == nil) goto v_7086;
    else goto v_7087;
v_7086:
    v_7384 = lisp_true;
    goto v_7085;
v_7087:
    v_7384 = stack[-4];
    fn = elt(env, 4); // num!-exponents
    v_7384 = (*qfn1(fn))(fn, v_7384);
    env = stack[-7];
    v_7384 = (v_7384 == nil ? lisp_true : nil);
    goto v_7085;
    v_7384 = nil;
v_7085:
    goto v_7077;
    v_7384 = nil;
v_7077:
    if (v_7384 == nil) goto v_7075;
    v_7384 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7071;
v_7075:
    v_7384 = qvalue(elt(env, 3)); // !*gcd
    if (v_7384 == nil) goto v_7100;
    goto v_7109;
v_7105:
    goto v_7116;
v_7112:
    v_7385 = stack[-5];
    goto v_7113;
v_7114:
    v_7384 = stack[-4];
    goto v_7115;
v_7116:
    goto v_7112;
v_7113:
    goto v_7114;
v_7115:
    fn = elt(env, 5); // kernord
    v_7384 = (*qfn2(fn))(fn, v_7385, v_7384);
    env = stack[-7];
    stack[-3] = v_7384;
    v_7385 = Llength(nil, v_7384);
    env = stack[-7];
    goto v_7106;
v_7107:
    v_7384 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7108;
v_7109:
    goto v_7105;
v_7106:
    goto v_7107;
v_7108:
    v_7384 = (LispObject)greaterp2(v_7385, v_7384);
    v_7384 = v_7384 ? lisp_true : nil;
    env = stack[-7];
    if (v_7384 == nil) goto v_7100;
    v_7384 = stack[-3];
    fn = elt(env, 6); // setkorder
    v_7384 = (*qfn1(fn))(fn, v_7384);
    env = stack[-7];
    v_7384 = ncons(v_7384);
    env = stack[-7];
    stack[-3] = v_7384;
    v_7384 = stack[-5];
    fn = elt(env, 7); // reorder
    v_7384 = (*qfn1(fn))(fn, v_7384);
    env = stack[-7];
    stack[-5] = v_7384;
    v_7384 = stack[-4];
    fn = elt(env, 7); // reorder
    v_7384 = (*qfn1(fn))(fn, v_7384);
    env = stack[-7];
    stack[-4] = v_7384;
    goto v_7098;
v_7100:
    v_7384 = nil;
    stack[-3] = v_7384;
    goto v_7098;
v_7098:
    goto v_7138;
v_7134:
    v_7384 = stack[-5];
    v_7384 = qcar(v_7384);
    v_7384 = qcar(v_7384);
    v_7385 = qcar(v_7384);
    goto v_7135;
v_7136:
    v_7384 = stack[-4];
    v_7384 = qcar(v_7384);
    v_7384 = qcar(v_7384);
    v_7384 = qcar(v_7384);
    goto v_7137;
v_7138:
    goto v_7134;
v_7135:
    goto v_7136;
v_7137:
    if (v_7385 == v_7384) goto v_7132;
    else goto v_7133;
v_7132:
    v_7384 = stack[-5];
    fn = elt(env, 8); // comfac
    v_7384 = (*qfn1(fn))(fn, v_7384);
    env = stack[-7];
    stack[-1] = v_7384;
    v_7384 = stack[-4];
    fn = elt(env, 8); // comfac
    v_7384 = (*qfn1(fn))(fn, v_7384);
    env = stack[-7];
    stack[0] = v_7384;
    goto v_7160;
v_7156:
    v_7384 = stack[-1];
    v_7385 = qcdr(v_7384);
    goto v_7157;
v_7158:
    v_7384 = stack[0];
    v_7384 = qcdr(v_7384);
    goto v_7159;
v_7160:
    goto v_7156;
v_7157:
    goto v_7158;
v_7159:
    fn = elt(env, 9); // gcdf1
    v_7384 = (*qfn2(fn))(fn, v_7385, v_7384);
    env = stack[-7];
    stack[-2] = v_7384;
    goto v_7170;
v_7166:
    goto v_7167;
v_7168:
    v_7384 = stack[-1];
    fn = elt(env, 10); // comfac!-to!-poly
    v_7384 = (*qfn1(fn))(fn, v_7384);
    env = stack[-7];
    goto v_7169;
v_7170:
    goto v_7166;
v_7167:
    goto v_7168;
v_7169:
    fn = elt(env, 11); // quotf1
    v_7384 = (*qfn2(fn))(fn, stack[-5], v_7384);
    env = stack[-7];
    stack[-5] = v_7384;
    goto v_7179;
v_7175:
    goto v_7176;
v_7177:
    v_7384 = stack[0];
    fn = elt(env, 10); // comfac!-to!-poly
    v_7384 = (*qfn1(fn))(fn, v_7384);
    env = stack[-7];
    goto v_7178;
v_7179:
    goto v_7175;
v_7176:
    goto v_7177;
v_7178:
    fn = elt(env, 11); // quotf1
    v_7384 = (*qfn2(fn))(fn, stack[-4], v_7384);
    env = stack[-7];
    stack[-4] = v_7384;
    v_7384 = qvalue(elt(env, 3)); // !*gcd
    if (v_7384 == nil) goto v_7186;
    goto v_7193;
v_7189:
    goto v_7199;
v_7195:
    v_7385 = stack[-5];
    goto v_7196;
v_7197:
    v_7384 = stack[-4];
    goto v_7198;
v_7199:
    goto v_7195;
v_7196:
    goto v_7197;
v_7198:
    fn = elt(env, 12); // gcdk
    v_7385 = (*qfn2(fn))(fn, v_7385, v_7384);
    env = stack[-7];
    goto v_7190;
v_7191:
    v_7384 = stack[-2];
    goto v_7192;
v_7193:
    goto v_7189;
v_7190:
    goto v_7191;
v_7192:
    fn = elt(env, 13); // multf
    v_7384 = (*qfn2(fn))(fn, v_7385, v_7384);
    env = stack[-7];
    stack[-2] = v_7384;
    goto v_7184;
v_7186:
    v_7384 = stack[-4];
    if (v_7384 == nil) goto v_7204;
    goto v_7213;
v_7209:
    v_7385 = stack[-5];
    goto v_7210;
v_7211:
    v_7384 = stack[-4];
    goto v_7212;
v_7213:
    goto v_7209;
v_7210:
    goto v_7211;
v_7212:
    fn = elt(env, 11); // quotf1
    v_7384 = (*qfn2(fn))(fn, v_7385, v_7384);
    env = stack[-7];
    if (v_7384 == nil) goto v_7204;
    goto v_7221;
v_7217:
    v_7385 = stack[-4];
    goto v_7218;
v_7219:
    v_7384 = stack[-2];
    goto v_7220;
v_7221:
    goto v_7217;
v_7218:
    goto v_7219;
v_7220:
    fn = elt(env, 13); // multf
    v_7384 = (*qfn2(fn))(fn, v_7385, v_7384);
    env = stack[-7];
    stack[-2] = v_7384;
    goto v_7184;
v_7204:
    v_7384 = stack[-5];
    if (v_7384 == nil) goto v_7225;
    goto v_7234;
v_7230:
    v_7385 = stack[-4];
    goto v_7231;
v_7232:
    v_7384 = stack[-5];
    goto v_7233;
v_7234:
    goto v_7230;
v_7231:
    goto v_7232;
v_7233:
    fn = elt(env, 11); // quotf1
    v_7384 = (*qfn2(fn))(fn, v_7385, v_7384);
    env = stack[-7];
    if (v_7384 == nil) goto v_7225;
    goto v_7242;
v_7238:
    v_7385 = stack[-5];
    goto v_7239;
v_7240:
    v_7384 = stack[-2];
    goto v_7241;
v_7242:
    goto v_7238;
v_7239:
    goto v_7240;
v_7241:
    fn = elt(env, 13); // multf
    v_7384 = (*qfn2(fn))(fn, v_7385, v_7384);
    env = stack[-7];
    stack[-2] = v_7384;
    goto v_7184;
v_7225:
v_7184:
    v_7384 = stack[-1];
    v_7384 = qcar(v_7384);
    if (v_7384 == nil) goto v_7248;
    v_7384 = stack[0];
    v_7384 = qcar(v_7384);
    if (v_7384 == nil) goto v_7248;
    goto v_7264;
v_7260:
    v_7384 = stack[-1];
    v_7384 = qcar(v_7384);
    v_7385 = qcdr(v_7384);
    goto v_7261;
v_7262:
    v_7384 = stack[0];
    v_7384 = qcar(v_7384);
    v_7384 = qcdr(v_7384);
    goto v_7263;
v_7264:
    goto v_7260;
v_7261:
    goto v_7262;
v_7263:
    v_7384 = (LispObject)greaterp2(v_7385, v_7384);
    v_7384 = v_7384 ? lisp_true : nil;
    env = stack[-7];
    if (v_7384 == nil) goto v_7258;
    goto v_7276;
v_7272:
    goto v_7283;
v_7279:
    v_7384 = stack[0];
    v_7385 = qcar(v_7384);
    goto v_7280;
v_7281:
    v_7384 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7282;
v_7283:
    goto v_7279;
v_7280:
    goto v_7281;
v_7282:
    v_7384 = cons(v_7385, v_7384);
    env = stack[-7];
    v_7385 = ncons(v_7384);
    env = stack[-7];
    goto v_7273;
v_7274:
    v_7384 = stack[-2];
    goto v_7275;
v_7276:
    goto v_7272;
v_7273:
    goto v_7274;
v_7275:
    fn = elt(env, 13); // multf
    v_7384 = (*qfn2(fn))(fn, v_7385, v_7384);
    env = stack[-7];
    stack[-2] = v_7384;
    goto v_7256;
v_7258:
    goto v_7295;
v_7291:
    goto v_7302;
v_7298:
    v_7384 = stack[-1];
    v_7385 = qcar(v_7384);
    goto v_7299;
v_7300:
    v_7384 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7301;
v_7302:
    goto v_7298;
v_7299:
    goto v_7300;
v_7301:
    v_7384 = cons(v_7385, v_7384);
    env = stack[-7];
    v_7385 = ncons(v_7384);
    env = stack[-7];
    goto v_7292;
v_7293:
    v_7384 = stack[-2];
    goto v_7294;
v_7295:
    goto v_7291;
v_7292:
    goto v_7293;
v_7294:
    fn = elt(env, 13); // multf
    v_7384 = (*qfn2(fn))(fn, v_7385, v_7384);
    env = stack[-7];
    stack[-2] = v_7384;
    goto v_7256;
v_7256:
    goto v_7246;
v_7248:
v_7246:
    goto v_7131;
v_7133:
    v_7384 = stack[-5];
    v_7384 = qcar(v_7384);
    v_7384 = qcar(v_7384);
    v_7384 = qcar(v_7384);
    fn = elt(env, 14); // noncomp
    v_7384 = (*qfn1(fn))(fn, v_7384);
    env = stack[-7];
    if (v_7384 == nil) goto v_7308;
    v_7384 = stack[-4];
    v_7384 = qcar(v_7384);
    v_7384 = qcar(v_7384);
    v_7384 = qcar(v_7384);
    fn = elt(env, 14); // noncomp
    v_7384 = (*qfn1(fn))(fn, v_7384);
    env = stack[-7];
    if (v_7384 == nil) goto v_7308;
    goto v_7328;
v_7322:
    v_7386 = stack[-5];
    goto v_7323;
v_7324:
    v_7385 = stack[-4];
    goto v_7325;
v_7326:
    v_7384 = stack[-4];
    v_7384 = qcar(v_7384);
    v_7384 = qcar(v_7384);
    v_7384 = qcar(v_7384);
    goto v_7327;
v_7328:
    goto v_7322;
v_7323:
    goto v_7324;
v_7325:
    goto v_7326;
v_7327:
    fn = elt(env, 15); // gcdfnc
    v_7384 = (*qfnn(fn))(fn, 3, v_7386, v_7385, v_7384);
    env = stack[-7];
    stack[-2] = v_7384;
    goto v_7131;
v_7308:
    goto v_7342;
v_7338:
    v_7384 = stack[-5];
    v_7384 = qcar(v_7384);
    v_7384 = qcar(v_7384);
    v_7385 = qcar(v_7384);
    goto v_7339;
v_7340:
    v_7384 = stack[-4];
    v_7384 = qcar(v_7384);
    v_7384 = qcar(v_7384);
    v_7384 = qcar(v_7384);
    goto v_7341;
v_7342:
    goto v_7338;
v_7339:
    goto v_7340;
v_7341:
    fn = elt(env, 16); // ordop
    v_7384 = (*qfn2(fn))(fn, v_7385, v_7384);
    env = stack[-7];
    if (v_7384 == nil) goto v_7336;
    goto v_7356;
v_7352:
    v_7384 = stack[-5];
    fn = elt(env, 8); // comfac
    v_7384 = (*qfn1(fn))(fn, v_7384);
    env = stack[-7];
    v_7385 = qcdr(v_7384);
    goto v_7353;
v_7354:
    v_7384 = stack[-4];
    goto v_7355;
v_7356:
    goto v_7352;
v_7353:
    goto v_7354;
v_7355:
    fn = elt(env, 9); // gcdf1
    v_7384 = (*qfn2(fn))(fn, v_7385, v_7384);
    env = stack[-7];
    stack[-2] = v_7384;
    goto v_7131;
v_7336:
    goto v_7368;
v_7364:
    v_7384 = stack[-4];
    fn = elt(env, 8); // comfac
    v_7384 = (*qfn1(fn))(fn, v_7384);
    env = stack[-7];
    v_7385 = qcdr(v_7384);
    goto v_7365;
v_7366:
    v_7384 = stack[-5];
    goto v_7367;
v_7368:
    goto v_7364;
v_7365:
    goto v_7366;
v_7367:
    fn = elt(env, 9); // gcdf1
    v_7384 = (*qfn2(fn))(fn, v_7385, v_7384);
    env = stack[-7];
    stack[-2] = v_7384;
    goto v_7131;
v_7131:
    v_7384 = stack[-3];
    if (v_7384 == nil) goto v_7376;
    v_7384 = stack[-3];
    v_7384 = qcar(v_7384);
    fn = elt(env, 6); // setkorder
    v_7384 = (*qfn1(fn))(fn, v_7384);
    env = stack[-7];
    v_7384 = stack[-2];
    fn = elt(env, 7); // reorder
    v_7384 = (*qfn1(fn))(fn, v_7384);
    stack[-2] = v_7384;
    goto v_7374;
v_7376:
v_7374:
    v_7384 = stack[-2];
v_7071:
    ;}  // end of a binding scope
    return onevalue(v_7384);
}



// Code for subs3f1

static LispObject CC_subs3f1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7246, v_7247, v_7248;
    LispObject fn;
    LispObject v_7066, v_7065, v_7064;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "subs3f1");
    va_start(aa, nargs);
    v_7064 = va_arg(aa, LispObject);
    v_7065 = va_arg(aa, LispObject);
    v_7066 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7066,v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7064,v_7065,v_7066);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_7066;
    stack[-1] = v_7065;
    stack[-2] = v_7064;
// end of prologue
    goto v_7080;
v_7076:
    v_7247 = nil;
    goto v_7077;
v_7078:
    v_7246 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7079;
v_7080:
    goto v_7076;
v_7077:
    goto v_7078;
v_7079:
    v_7246 = cons(v_7247, v_7246);
    env = stack[-4];
    stack[-3] = v_7246;
v_7072:
    v_7246 = stack[-2];
    if (v_7246 == nil) goto v_7085;
    else goto v_7086;
v_7085:
    v_7246 = stack[-3];
    goto v_7071;
v_7086:
    v_7246 = stack[-2];
    if (!consp(v_7246)) goto v_7093;
    else goto v_7094;
v_7093:
    v_7246 = lisp_true;
    goto v_7092;
v_7094:
    v_7246 = stack[-2];
    v_7246 = qcar(v_7246);
    v_7246 = (consp(v_7246) ? nil : lisp_true);
    goto v_7092;
    v_7246 = nil;
v_7092:
    if (v_7246 == nil) goto v_7090;
    goto v_7107;
v_7103:
    stack[0] = stack[-3];
    goto v_7104;
v_7105:
    goto v_7114;
v_7110:
    v_7247 = stack[-2];
    goto v_7111;
v_7112:
    v_7246 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7113;
v_7114:
    goto v_7110;
v_7111:
    goto v_7112;
v_7113:
    v_7246 = cons(v_7247, v_7246);
    env = stack[-4];
    goto v_7106;
v_7107:
    goto v_7103;
v_7104:
    goto v_7105;
v_7106:
    {
        LispObject v_7253 = stack[0];
        fn = elt(env, 6); // addsq
        return (*qfn2(fn))(fn, v_7253, v_7246);
    }
v_7090:
    v_7246 = stack[0];
    if (v_7246 == nil) goto v_7118;
    v_7246 = stack[-2];
    v_7246 = qcar(v_7246);
    v_7246 = qcdr(v_7246);
    if (!consp(v_7246)) goto v_7124;
    else goto v_7125;
v_7124:
    v_7246 = lisp_true;
    goto v_7123;
v_7125:
    v_7246 = stack[-2];
    v_7246 = qcar(v_7246);
    v_7246 = qcdr(v_7246);
    v_7246 = qcar(v_7246);
    v_7246 = (consp(v_7246) ? nil : lisp_true);
    goto v_7123;
    v_7246 = nil;
v_7123:
    if (v_7246 == nil) goto v_7118;
    goto v_7074;
v_7118:
    v_7246 = qvalue(elt(env, 1)); // !*mymatch
    if (v_7246 == nil) goto v_7140;
    goto v_7147;
v_7143:
    v_7246 = stack[-2];
    v_7247 = qcar(v_7246);
    goto v_7144;
v_7145:
    v_7246 = stack[-1];
    goto v_7146;
v_7147:
    goto v_7143;
v_7144:
    goto v_7145;
v_7146:
    fn = elt(env, 7); // !*subs3tnc
    v_7246 = (*qfn2(fn))(fn, v_7247, v_7246);
    env = stack[-4];
    goto v_7138;
v_7140:
    goto v_7158;
v_7154:
    v_7246 = stack[-2];
    v_7247 = qcar(v_7246);
    goto v_7155;
v_7156:
    v_7246 = stack[-1];
    goto v_7157;
v_7158:
    goto v_7154;
v_7155:
    goto v_7156;
v_7157:
    fn = elt(env, 8); // subs3t
    v_7246 = (*qfn2(fn))(fn, v_7247, v_7246);
    env = stack[-4];
    goto v_7138;
    v_7246 = nil;
v_7138:
    v_7248 = v_7246;
    v_7246 = stack[0];
    if (v_7246 == nil) goto v_7168;
    else goto v_7169;
v_7168:
    v_7246 = lisp_true;
    goto v_7167;
v_7169:
    v_7246 = qvalue(elt(env, 2)); // mchfg!*
    v_7246 = (v_7246 == nil ? lisp_true : nil);
    goto v_7167;
    v_7246 = nil;
v_7167:
    if (v_7246 == nil) goto v_7165;
    goto v_7073;
v_7165:
    v_7246 = nil;
    qvalue(elt(env, 2)) = v_7246; // mchfg!*
    goto v_7189;
v_7185:
    v_7246 = v_7248;
    v_7247 = qcar(v_7246);
    goto v_7186;
v_7187:
    v_7246 = stack[-2];
    goto v_7188;
v_7189:
    goto v_7185;
v_7186:
    goto v_7187;
v_7188:
    if (equal(v_7247, v_7246)) goto v_7183;
    else goto v_7184;
v_7183:
    goto v_7197;
v_7193:
    v_7246 = v_7248;
    v_7247 = qcdr(v_7246);
    goto v_7194;
v_7195:
    v_7246 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7196;
v_7197:
    goto v_7193;
v_7194:
    goto v_7195;
v_7196:
    v_7246 = (v_7247 == v_7246 ? lisp_true : nil);
    goto v_7182;
v_7184:
    v_7246 = nil;
    goto v_7182;
    v_7246 = nil;
v_7182:
    if (v_7246 == nil) goto v_7180;
    goto v_7210;
v_7206:
    v_7247 = stack[-2];
    goto v_7207;
v_7208:
    v_7246 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7209;
v_7210:
    goto v_7206;
v_7207:
    goto v_7208;
v_7209:
    v_7246 = cons(v_7247, v_7246);
    env = stack[-4];
    v_7248 = v_7246;
    goto v_7073;
v_7180:
    v_7246 = qvalue(elt(env, 3)); // !*resubs
    if (v_7246 == nil) goto v_7213;
    else goto v_7214;
v_7213:
    goto v_7073;
v_7214:
    v_7246 = qvalue(elt(env, 4)); // !*sub2
    if (v_7246 == nil) goto v_7218;
    else goto v_7216;
v_7218:
    v_7246 = qvalue(elt(env, 5)); // powlis1!*
    if (v_7246 == nil) goto v_7220;
    else goto v_7216;
v_7220:
    goto v_7217;
v_7216:
    v_7246 = v_7248;
    fn = elt(env, 9); // subs2q
    v_7246 = (*qfn1(fn))(fn, v_7246);
    env = stack[-4];
    v_7248 = v_7246;
    goto v_7178;
v_7217:
v_7178:
    v_7246 = v_7248;
    fn = elt(env, 10); // subs3q
    v_7246 = (*qfn1(fn))(fn, v_7246);
    env = stack[-4];
    v_7248 = v_7246;
v_7073:
    goto v_7231;
v_7227:
    v_7246 = stack[-3];
    goto v_7228;
v_7229:
    v_7247 = v_7248;
    goto v_7230;
v_7231:
    goto v_7227;
v_7228:
    goto v_7229;
v_7230:
    fn = elt(env, 6); // addsq
    v_7246 = (*qfn2(fn))(fn, v_7246, v_7247);
    env = stack[-4];
    stack[-3] = v_7246;
    v_7246 = stack[-2];
    v_7246 = qcdr(v_7246);
    stack[-2] = v_7246;
    goto v_7072;
v_7074:
    goto v_7241;
v_7237:
    v_7246 = stack[-2];
    v_7246 = qcar(v_7246);
    v_7247 = ncons(v_7246);
    env = stack[-4];
    goto v_7238;
v_7239:
    v_7246 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7240;
v_7241:
    goto v_7237;
v_7238:
    goto v_7239;
v_7240:
    v_7246 = cons(v_7247, v_7246);
    env = stack[-4];
    v_7248 = v_7246;
    goto v_7073;
v_7071:
    return onevalue(v_7246);
}



// Code for get_group_in

static LispObject CC_get_group_in(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7070;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7070 = v_7064;
// end of prologue
    v_7070 = qcar(v_7070);
    return onevalue(v_7070);
}



// Code for qqe_ofsf_prepat

static LispObject CC_qqe_ofsf_prepat(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7079;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7064);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_7064;
// end of prologue
    v_7079 = stack[0];
    fn = elt(env, 1); // qqe_op
    v_7079 = (*qfn1(fn))(fn, v_7079);
    env = stack[-1];
    fn = elt(env, 2); // qqe_rqopp
    v_7079 = (*qfn1(fn))(fn, v_7079);
    env = stack[-1];
    if (v_7079 == nil) goto v_7069;
    v_7079 = stack[0];
    {
        fn = elt(env, 3); // qqe_prepat
        return (*qfn1(fn))(fn, v_7079);
    }
v_7069:
    v_7079 = stack[0];
    {
        fn = elt(env, 4); // ofsf_prepat
        return (*qfn1(fn))(fn, v_7079);
    }
    v_7079 = nil;
    return onevalue(v_7079);
}



// Code for mkzl

static LispObject CC_mkzl(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7095, v_7096;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7064);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7064;
// end of prologue
    stack[-1] = nil;
v_7069:
    goto v_7078;
v_7074:
    v_7096 = stack[0];
    goto v_7075;
v_7076:
    v_7095 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7077;
v_7078:
    goto v_7074;
v_7075:
    goto v_7076;
v_7077:
    if (v_7096 == v_7095) goto v_7072;
    else goto v_7073;
v_7072:
    v_7095 = stack[-1];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_7095);
    }
v_7073:
    goto v_7090;
v_7086:
    v_7096 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7087;
v_7088:
    v_7095 = stack[-1];
    goto v_7089;
v_7090:
    goto v_7086;
v_7087:
    goto v_7088;
v_7089:
    v_7095 = cons(v_7096, v_7095);
    env = stack[-2];
    stack[-1] = v_7095;
    v_7095 = stack[0];
    v_7095 = sub1(v_7095);
    env = stack[-2];
    stack[0] = v_7095;
    goto v_7069;
    v_7095 = nil;
    return onevalue(v_7095);
}



// Code for intexprnp

static LispObject CC_intexprnp(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7141, v_7142, v_7143, v_7144;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7142 = v_7065;
    v_7143 = v_7064;
// end of prologue
    v_7141 = qvalue(elt(env, 1)); // !*revalp
    if (v_7141 == nil) goto v_7069;
    else goto v_7070;
v_7069:
    v_7141 = nil;
    goto v_7068;
v_7070:
    v_7141 = v_7143;
    if (!consp(v_7141)) goto v_7073;
    else goto v_7074;
v_7073:
    v_7141 = v_7143;
    if (is_number(v_7141)) goto v_7078;
    else goto v_7079;
v_7078:
    v_7141 = v_7143;
    v_7141 = integerp(v_7141);
    goto v_7077;
v_7079:
    goto v_7089;
v_7085:
    v_7141 = v_7143;
    goto v_7086;
v_7087:
    goto v_7088;
v_7089:
    goto v_7085;
v_7086:
    goto v_7087;
v_7088:
    v_7141 = Latsoc(nil, v_7141, v_7142);
    v_7143 = v_7141;
    if (v_7141 == nil) goto v_7084;
    goto v_7097;
v_7093:
    v_7141 = v_7143;
    v_7141 = qcdr(v_7141);
    goto v_7094;
v_7095:
    v_7142 = elt(env, 2); // integer
    goto v_7096;
v_7097:
    goto v_7093;
v_7094:
    goto v_7095;
v_7096:
    v_7141 = (v_7141 == v_7142 ? lisp_true : nil);
    goto v_7077;
v_7084:
    v_7141 = nil;
    goto v_7077;
    v_7141 = nil;
v_7077:
    goto v_7068;
v_7074:
    v_7141 = v_7143;
    v_7141 = qcar(v_7141);
    if (symbolp(v_7141)) goto v_7110;
    v_7141 = nil;
    goto v_7108;
v_7110:
    goto v_7125;
v_7121:
    v_7141 = v_7143;
    v_7144 = qcar(v_7141);
    goto v_7122;
v_7123:
    v_7141 = elt(env, 3); // intfn
    goto v_7124;
v_7125:
    goto v_7121;
v_7122:
    goto v_7123;
v_7124:
    v_7141 = Lflagp(nil, v_7144, v_7141);
    env = stack[0];
    if (v_7141 == nil) goto v_7119;
    goto v_7134;
v_7130:
    v_7141 = v_7143;
    v_7141 = qcdr(v_7141);
    goto v_7131;
v_7132:
    goto v_7133;
v_7134:
    goto v_7130;
v_7131:
    goto v_7132;
v_7133:
    {
        fn = elt(env, 4); // intexprlisp
        return (*qfn2(fn))(fn, v_7141, v_7142);
    }
v_7119:
    v_7141 = nil;
    goto v_7117;
    v_7141 = nil;
v_7117:
    goto v_7108;
    v_7141 = nil;
v_7108:
    goto v_7068;
    v_7141 = nil;
v_7068:
    return onevalue(v_7141);
}



// Code for rat_numrn

static LispObject CC_rat_numrn(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7077, v_7078;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7077 = v_7064;
// end of prologue
    v_7078 = v_7077;
    v_7078 = qcar(v_7078);
    if (v_7078 == nil) goto v_7068;
    else goto v_7069;
v_7068:
    v_7077 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7067;
v_7069:
    v_7077 = qcar(v_7077);
    goto v_7067;
    v_7077 = nil;
v_7067:
    return onevalue(v_7077);
}



// Code for naryrd

static LispObject CC_naryrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7085, v_7086;
    LispObject fn;
    argcheck(nargs, 0, "naryrd");
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
    v_7085 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_7086 = v_7085;
    v_7085 = v_7086;
    if (v_7085 == nil) goto v_7071;
    else goto v_7072;
v_7071:
    v_7085 = nil;
    goto v_7070;
v_7072:
    goto v_7082;
v_7078:
    stack[0] = v_7086;
    goto v_7079;
v_7080:
    v_7085 = CC_naryrd(elt(env, 0), 0);
    goto v_7081;
v_7082:
    goto v_7078;
v_7079:
    goto v_7080;
v_7081:
    {
        LispObject v_7088 = stack[0];
        return cons(v_7088, v_7085);
    }
    v_7085 = nil;
v_7070:
    return onevalue(v_7085);
}



// Code for spquotematrix

static LispObject CC_spquotematrix(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7067;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7067 = v_7064;
// end of prologue
    v_7067 = elt(env, 1); // sparse
    return onevalue(v_7067);
}



// Code for fortranop

static LispObject CC_fortranop(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7078, v_7079, v_7080;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7064);
    }
// copy arguments values to proper place
    v_7080 = v_7064;
// end of prologue
    goto v_7074;
v_7070:
    v_7079 = v_7080;
    goto v_7071;
v_7072:
    v_7078 = elt(env, 1); // !*fortranop!*
    goto v_7073;
v_7074:
    goto v_7070;
v_7071:
    goto v_7072;
v_7073:
    v_7078 = get(v_7079, v_7078);
    if (v_7078 == nil) goto v_7068;
    else goto v_7067;
v_7068:
    v_7078 = v_7080;
v_7067:
    return onevalue(v_7078);
}



// Code for red!-ratios1

static LispObject CC_redKratios1(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7106, v_7107, v_7108, v_7109;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7065;
    stack[-1] = v_7064;
// end of prologue
v_7063:
    v_7106 = stack[-1];
    if (v_7106 == nil) goto v_7069;
    else goto v_7070;
v_7069:
    v_7106 = nil;
    goto v_7068;
v_7070:
    goto v_7087;
v_7079:
    v_7106 = stack[-1];
    v_7109 = qcdr(v_7106);
    goto v_7080;
v_7081:
    v_7106 = stack[0];
    v_7108 = qcdr(v_7106);
    goto v_7082;
v_7083:
    v_7106 = stack[-1];
    v_7107 = qcar(v_7106);
    goto v_7084;
v_7085:
    v_7106 = stack[0];
    v_7106 = qcar(v_7106);
    goto v_7086;
v_7087:
    goto v_7079;
v_7080:
    goto v_7081;
v_7082:
    goto v_7083;
v_7084:
    goto v_7085;
v_7086:
    fn = elt(env, 1); // red!-ratios2
    v_7106 = (*qfnn(fn))(fn, 4, v_7109, v_7108, v_7107, v_7106);
    env = stack[-2];
    if (v_7106 == nil) goto v_7077;
    else goto v_7076;
v_7077:
    goto v_7101;
v_7097:
    v_7106 = stack[-1];
    v_7107 = qcdr(v_7106);
    goto v_7098;
v_7099:
    v_7106 = stack[0];
    v_7106 = qcdr(v_7106);
    goto v_7100;
v_7101:
    goto v_7097;
v_7098:
    goto v_7099;
v_7100:
    stack[-1] = v_7107;
    stack[0] = v_7106;
    goto v_7063;
v_7076:
    goto v_7068;
    v_7106 = nil;
v_7068:
    return onevalue(v_7106);
}



// Code for multop

static LispObject CC_multop(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7109, v_7110, v_7111;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_7065;
    v_7111 = v_7064;
// end of prologue
    v_7109 = qvalue(elt(env, 1)); // kord!*
    if (v_7109 == nil) goto v_7069;
    else goto v_7070;
v_7069:
    goto v_7077;
v_7073:
    goto v_7084;
v_7080:
    v_7110 = v_7111;
    goto v_7081;
v_7082:
    v_7109 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7083;
v_7084:
    goto v_7080;
v_7081:
    goto v_7082;
v_7083:
    v_7109 = cons(v_7110, v_7109);
    env = stack[-1];
    v_7110 = ncons(v_7109);
    env = stack[-1];
    goto v_7074;
v_7075:
    v_7109 = stack[0];
    goto v_7076;
v_7077:
    goto v_7073;
v_7074:
    goto v_7075;
v_7076:
    {
        fn = elt(env, 3); // multf
        return (*qfn2(fn))(fn, v_7110, v_7109);
    }
v_7070:
    goto v_7094;
v_7090:
    v_7109 = v_7111;
    v_7110 = qcar(v_7109);
    goto v_7091;
v_7092:
    v_7109 = elt(env, 2); // k!*
    goto v_7093;
v_7094:
    goto v_7090;
v_7091:
    goto v_7092;
v_7093:
    if (v_7110 == v_7109) goto v_7088;
    else goto v_7089;
v_7088:
    v_7109 = stack[0];
    goto v_7068;
v_7089:
    goto v_7106;
v_7102:
    v_7110 = v_7111;
    goto v_7103;
v_7104:
    v_7109 = stack[0];
    goto v_7105;
v_7106:
    goto v_7102;
v_7103:
    goto v_7104;
v_7105:
    {
        fn = elt(env, 4); // rmultpf
        return (*qfn2(fn))(fn, v_7110, v_7109);
    }
    v_7109 = nil;
v_7068:
    return onevalue(v_7109);
}



// Code for dividef

static LispObject CC_dividef(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7116, v_7117, v_7118, v_7119;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
// copy arguments values to proper place
    v_7116 = v_7065;
    v_7117 = v_7064;
// end of prologue
    goto v_7072;
v_7068:
    goto v_7069;
v_7070:
    goto v_7071;
v_7072:
    goto v_7068;
v_7069:
    goto v_7070;
v_7071:
    v_7116 = Ldivide(nil, v_7117, v_7116);
    v_7119 = v_7116;
    goto v_7081;
v_7077:
    goto v_7090;
v_7086:
    v_7116 = v_7119;
    v_7117 = qcar(v_7116);
    goto v_7087;
v_7088:
    v_7116 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7089;
v_7090:
    goto v_7086;
v_7087:
    goto v_7088;
v_7089:
    if (v_7117 == v_7116) goto v_7084;
    else goto v_7085;
v_7084:
    v_7116 = nil;
    v_7118 = v_7116;
    goto v_7083;
v_7085:
    v_7116 = v_7119;
    v_7116 = qcar(v_7116);
    v_7118 = v_7116;
    goto v_7083;
    v_7118 = nil;
v_7083:
    goto v_7078;
v_7079:
    goto v_7107;
v_7103:
    v_7116 = v_7119;
    v_7117 = qcdr(v_7116);
    goto v_7104;
v_7105:
    v_7116 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7106;
v_7107:
    goto v_7103;
v_7104:
    goto v_7105;
v_7106:
    if (v_7117 == v_7116) goto v_7101;
    else goto v_7102;
v_7101:
    v_7116 = nil;
    goto v_7100;
v_7102:
    v_7116 = v_7119;
    v_7116 = qcdr(v_7116);
    goto v_7100;
    v_7116 = nil;
v_7100:
    goto v_7080;
v_7081:
    goto v_7077;
v_7078:
    goto v_7079;
v_7080:
    return cons(v_7118, v_7116);
}



// Code for dl_get

static LispObject CC_dl_get(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7074, v_7075;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7074 = v_7064;
// end of prologue
    goto v_7071;
v_7067:
    v_7075 = v_7074;
    goto v_7068;
v_7069:
    v_7074 = nil;
    goto v_7070;
v_7071:
    goto v_7067;
v_7068:
    goto v_7069;
v_7070:
    {
        fn = elt(env, 1); // dl_get2
        return (*qfn2(fn))(fn, v_7075, v_7074);
    }
}



// Code for crprcd

static LispObject CC_crprcd(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7084, v_7085;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7064);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7064;
// end of prologue
    v_7084 = stack[0];
    v_7084 = qcdr(v_7084);
    v_7084 = qcar(v_7084);
    fn = elt(env, 1); // convprec!*
    stack[-1] = (*qfn1(fn))(fn, v_7084);
    env = stack[-2];
    v_7084 = stack[0];
    v_7084 = qcdr(v_7084);
    v_7084 = qcdr(v_7084);
    fn = elt(env, 1); // convprec!*
    v_7084 = (*qfn1(fn))(fn, v_7084);
    v_7085 = stack[-1];
    goto v_7081;
v_7077:
    goto v_7078;
v_7079:
    goto v_7080;
v_7081:
    goto v_7077;
v_7078:
    goto v_7079;
v_7080:
    return cons(v_7085, v_7084);
}



// Code for !*q2f

static LispObject CC_Hq2f(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7091, v_7092, v_7093;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7064);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7093 = v_7064;
// end of prologue
    goto v_7074;
v_7070:
    v_7091 = v_7093;
    v_7092 = qcdr(v_7091);
    goto v_7071;
v_7072:
    v_7091 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7073;
v_7074:
    goto v_7070;
v_7071:
    goto v_7072;
v_7073:
    if (v_7092 == v_7091) goto v_7068;
    else goto v_7069;
v_7068:
    v_7091 = v_7093;
    v_7091 = qcar(v_7091);
    goto v_7067;
v_7069:
    goto v_7087;
v_7083:
    v_7091 = v_7093;
    fn = elt(env, 2); // prepsq
    v_7092 = (*qfn1(fn))(fn, v_7091);
    env = stack[0];
    goto v_7084;
v_7085:
    v_7091 = elt(env, 1); // polynomial
    goto v_7086;
v_7087:
    goto v_7083;
v_7084:
    goto v_7085;
v_7086:
    {
        fn = elt(env, 3); // typerr
        return (*qfn2(fn))(fn, v_7092, v_7091);
    }
    v_7091 = nil;
v_7067:
    return onevalue(v_7091);
}



// Code for sfto_greaterq

static LispObject CC_sfto_greaterq(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7078, v_7079;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7078 = v_7065;
    v_7079 = v_7064;
// end of prologue
    goto v_7073;
v_7069:
    stack[0] = v_7078;
    goto v_7070;
v_7071:
    v_7078 = v_7079;
    fn = elt(env, 1); // negsq
    v_7078 = (*qfn1(fn))(fn, v_7078);
    env = stack[-1];
    goto v_7072;
v_7073:
    goto v_7069;
v_7070:
    goto v_7071;
v_7072:
    fn = elt(env, 2); // addsq
    v_7078 = (*qfn2(fn))(fn, stack[0], v_7078);
    env = stack[-1];
    v_7078 = qcar(v_7078);
    {
        fn = elt(env, 3); // minusf
        return (*qfn1(fn))(fn, v_7078);
    }
}



// Code for rl_simp

static LispObject CC_rl_simp(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7069;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7064);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7069 = v_7064;
// end of prologue
    fn = elt(env, 1); // rl_simp1
    v_7069 = (*qfn1(fn))(fn, v_7069);
    env = stack[0];
    {
        fn = elt(env, 2); // rl_csimpl
        return (*qfn1(fn))(fn, v_7069);
    }
}



// Code for lto_max

static LispObject CC_lto_max(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7076, v_7077;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7077 = v_7064;
// end of prologue
    v_7076 = v_7077;
    if (v_7076 == nil) goto v_7068;
    else goto v_7069;
v_7068:
    v_7076 = elt(env, 1); // (minus infinity)
    goto v_7067;
v_7069:
    v_7076 = v_7077;
    {
        fn = elt(env, 2); // lto_max1
        return (*qfn1(fn))(fn, v_7076);
    }
    v_7076 = nil;
v_7067:
    return onevalue(v_7076);
}



// Code for qqe_qprefix!-var

static LispObject CC_qqe_qprefixKvar(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7101, v_7102;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7064);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_7064;
// end of prologue
v_7070:
    v_7101 = stack[0];
    if (v_7101 == nil) goto v_7073;
    v_7101 = stack[0];
    if (!consp(v_7101)) goto v_7073;
    goto v_7074;
v_7073:
    goto v_7069;
v_7074:
    goto v_7088;
v_7084:
    v_7101 = stack[0];
    fn = elt(env, 2); // qqe_op
    v_7102 = (*qfn1(fn))(fn, v_7101);
    env = stack[-1];
    goto v_7085;
v_7086:
    v_7101 = elt(env, 1); // (ltail rtail lhead rhead)
    goto v_7087;
v_7088:
    goto v_7084;
v_7085:
    goto v_7086;
v_7087:
    v_7101 = Lmemq(nil, v_7102, v_7101);
    if (v_7101 == nil) goto v_7083;
    v_7101 = stack[0];
    fn = elt(env, 3); // qqe_arg2l
    v_7101 = (*qfn1(fn))(fn, v_7101);
    env = stack[-1];
    stack[0] = v_7101;
    goto v_7081;
v_7083:
    v_7101 = stack[0];
    fn = elt(env, 4); // qqe_arg2r
    v_7101 = (*qfn1(fn))(fn, v_7101);
    env = stack[-1];
    stack[0] = v_7101;
    goto v_7081;
v_7081:
    goto v_7070;
v_7069:
    v_7101 = stack[0];
    return onevalue(v_7101);
}



// Code for quotfx

static LispObject CC_quotfx(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7099, v_7100, v_7101;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7100 = v_7065;
    v_7101 = v_7064;
// end of prologue
    v_7099 = qvalue(elt(env, 1)); // !*exp
    if (v_7099 == nil) goto v_7073;
    else goto v_7074;
v_7073:
    v_7099 = lisp_true;
    goto v_7072;
v_7074:
    v_7099 = qvalue(elt(env, 2)); // !*mcd
    v_7099 = (v_7099 == nil ? lisp_true : nil);
    goto v_7072;
    v_7099 = nil;
v_7072:
    if (v_7099 == nil) goto v_7070;
    goto v_7086;
v_7082:
    v_7099 = v_7101;
    goto v_7083;
v_7084:
    goto v_7085;
v_7086:
    goto v_7082;
v_7083:
    goto v_7084;
v_7085:
    {
        fn = elt(env, 3); // quotf
        return (*qfn2(fn))(fn, v_7099, v_7100);
    }
v_7070:
    goto v_7096;
v_7092:
    v_7099 = v_7101;
    goto v_7093;
v_7094:
    goto v_7095;
v_7096:
    goto v_7092;
v_7093:
    goto v_7094;
v_7095:
    {
        fn = elt(env, 4); // quotfx1
        return (*qfn2(fn))(fn, v_7099, v_7100);
    }
    v_7099 = nil;
    return onevalue(v_7099);
}



// Code for ibalp_hassimple

static LispObject CC_ibalp_hassimple(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7105, v_7106;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7064);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_7105 = v_7064;
// end of prologue
    stack[-1] = nil;
    stack[0] = v_7105;
v_7073:
    v_7105 = stack[0];
    if (v_7105 == nil) goto v_7076;
    v_7105 = stack[-1];
    if (v_7105 == nil) goto v_7080;
    else goto v_7076;
v_7080:
    goto v_7077;
v_7076:
    goto v_7072;
v_7077:
    goto v_7092;
v_7088:
    v_7105 = stack[0];
    v_7105 = qcar(v_7105);
    v_7106 = qcar(v_7105);
    goto v_7089;
v_7090:
    v_7105 = stack[0];
    v_7105 = qcar(v_7105);
    v_7105 = qcdr(v_7105);
    v_7105 = qcar(v_7105);
    goto v_7091;
v_7092:
    goto v_7088;
v_7089:
    goto v_7090;
v_7091:
    fn = elt(env, 1); // ibalp_commonlenisone
    v_7105 = (*qfn2(fn))(fn, v_7106, v_7105);
    env = stack[-2];
    if (v_7105 == nil) goto v_7086;
    v_7105 = stack[0];
    v_7105 = qcar(v_7105);
    stack[-1] = v_7105;
    goto v_7084;
v_7086:
v_7084:
    v_7105 = stack[0];
    v_7105 = qcdr(v_7105);
    stack[0] = v_7105;
    goto v_7073;
v_7072:
    v_7105 = stack[-1];
    return onevalue(v_7105);
}



// Code for sfto_mvartest

static LispObject CC_sfto_mvartest(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7096, v_7097, v_7098;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7096 = v_7065;
    v_7097 = v_7064;
// end of prologue
    v_7098 = v_7097;
    if (!consp(v_7098)) goto v_7073;
    else goto v_7074;
v_7073:
    v_7098 = lisp_true;
    goto v_7072;
v_7074:
    v_7098 = v_7097;
    v_7098 = qcar(v_7098);
    v_7098 = (consp(v_7098) ? nil : lisp_true);
    goto v_7072;
    v_7098 = nil;
v_7072:
    if (v_7098 == nil) goto v_7069;
    else goto v_7070;
v_7069:
    goto v_7086;
v_7082:
    v_7097 = qcar(v_7097);
    v_7097 = qcar(v_7097);
    v_7097 = qcar(v_7097);
    goto v_7083;
v_7084:
    goto v_7085;
v_7086:
    goto v_7082;
v_7083:
    goto v_7084;
v_7085:
    v_7096 = (v_7097 == v_7096 ? lisp_true : nil);
    goto v_7068;
v_7070:
    v_7096 = nil;
    goto v_7068;
    v_7096 = nil;
v_7068:
    return onevalue(v_7096);
}



// Code for sub_math

static LispObject CC_sub_math(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7209, v_7210;
    LispObject fn;
    argcheck(nargs, 0, "sub_math");
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
    goto v_7078;
v_7074:
    v_7210 = qvalue(elt(env, 1)); // char
    goto v_7075;
v_7076:
    v_7209 = elt(env, 2); // (i d e n t !/)
    goto v_7077;
v_7078:
    goto v_7074;
v_7075:
    goto v_7076;
v_7077:
    if (equal(v_7210, v_7209)) goto v_7072;
    else goto v_7073;
v_7072:
    v_7209 = elt(env, 3); // ident
    return ncons(v_7209);
v_7073:
    goto v_7091;
v_7087:
    v_7210 = qvalue(elt(env, 1)); // char
    goto v_7088;
v_7089:
    v_7209 = elt(env, 4); // (v e c t o r)
    goto v_7090;
v_7091:
    goto v_7087;
v_7088:
    goto v_7089;
v_7090:
    if (equal(v_7210, v_7209)) goto v_7085;
    else goto v_7086;
v_7085:
    fn = elt(env, 10); // vectorrd
    v_7209 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_7209;
    goto v_7103;
v_7099:
    v_7210 = qvalue(elt(env, 1)); // char
    goto v_7100;
v_7101:
    v_7209 = elt(env, 5); // (!/ v e c t o r)
    goto v_7102;
v_7103:
    goto v_7099;
v_7100:
    goto v_7101;
v_7102:
    if (equal(v_7210, v_7209)) goto v_7098;
    goto v_7111;
v_7107:
    v_7210 = elt(env, 6); // "</vector>"
    goto v_7108;
v_7109:
    v_7209 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_7110;
v_7111:
    goto v_7107;
v_7108:
    goto v_7109;
v_7110:
    fn = elt(env, 11); // errorml
    v_7209 = (*qfn2(fn))(fn, v_7210, v_7209);
    goto v_7096;
v_7098:
v_7096:
    v_7209 = stack[-1];
    goto v_7068;
v_7086:
    goto v_7123;
v_7119:
    v_7209 = qvalue(elt(env, 1)); // char
    fn = elt(env, 12); // compress!*
    v_7210 = (*qfn1(fn))(fn, v_7209);
    env = stack[-2];
    goto v_7120;
v_7121:
    v_7209 = qvalue(elt(env, 7)); // constructors!*
    goto v_7122;
v_7123:
    goto v_7119;
v_7120:
    goto v_7121;
v_7122:
    v_7209 = Lassoc(nil, v_7210, v_7209);
    stack[0] = v_7209;
    if (v_7209 == nil) goto v_7118;
    goto v_7133;
v_7129:
    v_7209 = stack[0];
    v_7209 = qcdr(v_7209);
    v_7210 = qcar(v_7209);
    goto v_7130;
v_7131:
    v_7209 = nil;
    goto v_7132;
v_7133:
    goto v_7129;
v_7130:
    goto v_7131;
v_7132:
    fn = elt(env, 13); // apply
    v_7209 = (*qfn2(fn))(fn, v_7210, v_7209);
    env = stack[-2];
    stack[-1] = v_7209;
    v_7209 = stack[-1];
    v_7209 = Lconsp(nil, v_7209);
    env = stack[-2];
    if (v_7209 == nil) goto v_7141;
    goto v_7152;
v_7148:
    v_7209 = stack[-1];
    v_7210 = qcar(v_7209);
    goto v_7149;
v_7150:
    v_7209 = elt(env, 8); // csymbol
    goto v_7151;
v_7152:
    goto v_7148;
v_7149:
    goto v_7150;
v_7151:
    if (v_7210 == v_7209) goto v_7146;
    else goto v_7147;
v_7146:
    v_7209 = stack[-1];
    v_7209 = qcdr(v_7209);
    v_7209 = qcdr(v_7209);
    stack[-1] = v_7209;
    goto v_7145;
v_7147:
v_7145:
    goto v_7139;
v_7141:
v_7139:
    v_7209 = stack[-1];
    v_7209 = Lconsp(nil, v_7209);
    env = stack[-2];
    if (v_7209 == nil) goto v_7162;
    goto v_7173;
v_7169:
    v_7209 = stack[-1];
    v_7210 = qcar(v_7209);
    goto v_7170;
v_7171:
    v_7209 = elt(env, 9); // fn
    goto v_7172;
v_7173:
    goto v_7169;
v_7170:
    goto v_7171;
v_7172:
    if (v_7210 == v_7209) goto v_7167;
    else goto v_7168;
v_7167:
    v_7209 = stack[-1];
    v_7209 = qcdr(v_7209);
    v_7209 = qcdr(v_7209);
    stack[-1] = v_7209;
    goto v_7166;
v_7168:
v_7166:
    goto v_7160;
v_7162:
v_7160:
    goto v_7188;
v_7184:
    v_7209 = qvalue(elt(env, 1)); // char
    fn = elt(env, 12); // compress!*
    v_7210 = (*qfn1(fn))(fn, v_7209);
    env = stack[-2];
    goto v_7185;
v_7186:
    v_7209 = stack[0];
    v_7209 = qcdr(v_7209);
    v_7209 = qcdr(v_7209);
    v_7209 = qcar(v_7209);
    goto v_7187;
v_7188:
    goto v_7184;
v_7185:
    goto v_7186;
v_7187:
    if (equal(v_7210, v_7209)) goto v_7183;
    goto v_7200;
v_7196:
    v_7209 = stack[0];
    v_7209 = qcdr(v_7209);
    v_7209 = qcdr(v_7209);
    v_7209 = qcdr(v_7209);
    v_7210 = qcar(v_7209);
    goto v_7197;
v_7198:
    v_7209 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_7199;
v_7200:
    goto v_7196;
v_7197:
    goto v_7198;
v_7199:
    fn = elt(env, 11); // errorml
    v_7209 = (*qfn2(fn))(fn, v_7210, v_7209);
    goto v_7181;
v_7183:
v_7181:
    v_7209 = stack[-1];
    goto v_7068;
v_7118:
    v_7209 = nil;
v_7068:
    return onevalue(v_7209);
}



// Code for zeropp

static LispObject CC_zeropp(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7088, v_7089, v_7090;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7090 = v_7064;
// end of prologue
    v_7088 = v_7090;
    if (!consp(v_7088)) goto v_7068;
    else goto v_7069;
v_7068:
    v_7088 = v_7090;
        return Lzerop(nil, v_7088);
v_7069:
    goto v_7079;
v_7075:
    v_7088 = v_7090;
    v_7089 = qcar(v_7088);
    goto v_7076;
v_7077:
    v_7088 = elt(env, 1); // !:rd!:
    goto v_7078;
v_7079:
    goto v_7075;
v_7076:
    goto v_7077;
v_7078:
    if (v_7089 == v_7088) goto v_7073;
    else goto v_7074;
v_7073:
    v_7088 = v_7090;
    {
        fn = elt(env, 2); // rd!:zerop
        return (*qfn1(fn))(fn, v_7088);
    }
v_7074:
    v_7088 = nil;
    goto v_7067;
    v_7088 = nil;
v_7067:
    return onevalue(v_7088);
}



// Code for unbind

static LispObject CC_unbind(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7079, v_7080, v_7081;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7080 = v_7064;
// end of prologue
    goto v_7073;
v_7067:
    v_7079 = v_7080;
    goto v_7068;
v_7069:
    v_7081 = elt(env, 1); // binding
    goto v_7070;
v_7071:
    if (!symbolp(v_7080)) v_7080 = nil;
    else { v_7080 = qfastgets(v_7080);
           if (v_7080 != nil) { v_7080 = elt(v_7080, 13); // binding
#ifdef RECORD_GET
             if (v_7080 != SPID_NOPROP)
                record_get(elt(fastget_names, 13), 1);
             else record_get(elt(fastget_names, 13), 0),
                v_7080 = nil; }
           else record_get(elt(fastget_names, 13), 0); }
#else
             if (v_7080 == SPID_NOPROP) v_7080 = nil; }}
#endif
    v_7080 = qcdr(v_7080);
    goto v_7072;
v_7073:
    goto v_7067;
v_7068:
    goto v_7069;
v_7070:
    goto v_7071;
v_7072:
        return Lputprop(nil, 3, v_7079, v_7081, v_7080);
}



// Code for sc_null

static LispObject CC_sc_null(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7069;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7069 = v_7064;
// end of prologue
    v_7069 = qcar(v_7069);
    v_7069 = (v_7069 == nil ? lisp_true : nil);
    return onevalue(v_7069);
}



// Code for assert_dyntypep

static LispObject CC_assert_dyntypep(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7082, v_7083;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7083 = v_7064;
// end of prologue
    v_7082 = v_7083;
    if (symbolp(v_7082)) goto v_7069;
    v_7082 = nil;
    goto v_7067;
v_7069:
    goto v_7079;
v_7075:
    v_7082 = v_7083;
    goto v_7076;
v_7077:
    v_7083 = elt(env, 1); // assert_dyntype
    goto v_7078;
v_7079:
    goto v_7075;
v_7076:
    goto v_7077;
v_7078:
        return Lflagp(nil, v_7082, v_7083);
    v_7082 = nil;
v_7067:
    return onevalue(v_7082);
}



// Code for simptimes

static LispObject CC_simptimes(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7181, v_7182;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7064);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_7064;
// end of prologue
    stack[-2] = nil;
    v_7181 = stack[-1];
    if (v_7181 == nil) goto v_7076;
    else goto v_7077;
v_7076:
    goto v_7084;
v_7080:
    v_7182 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7081;
v_7082:
    v_7181 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7083;
v_7084:
    goto v_7080;
v_7081:
    goto v_7082;
v_7083:
    return cons(v_7182, v_7181);
v_7077:
    goto v_7099;
v_7095:
    v_7182 = qvalue(elt(env, 1)); // tstack!*
    goto v_7096;
v_7097:
    v_7181 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7098;
v_7099:
    goto v_7095;
v_7096:
    goto v_7097;
v_7098:
    if (v_7182 == v_7181) goto v_7094;
    v_7181 = lisp_true;
    goto v_7092;
v_7094:
    v_7181 = qvalue(elt(env, 2)); // mul!*
    v_7181 = (v_7181 == nil ? lisp_true : nil);
    goto v_7092;
    v_7181 = nil;
v_7092:
    if (v_7181 == nil) goto v_7090;
    goto v_7070;
v_7090:
    v_7181 = qvalue(elt(env, 2)); // mul!*
    stack[-2] = v_7181;
    v_7181 = nil;
    qvalue(elt(env, 2)) = v_7181; // mul!*
v_7070:
    v_7181 = qvalue(elt(env, 1)); // tstack!*
    v_7181 = add1(v_7181);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_7181; // tstack!*
    v_7181 = stack[-1];
    fn = elt(env, 4); // simpcar
    v_7181 = (*qfn1(fn))(fn, v_7181);
    env = stack[-3];
    stack[0] = v_7181;
v_7071:
    v_7181 = stack[-1];
    v_7181 = qcdr(v_7181);
    stack[-1] = v_7181;
    v_7181 = stack[0];
    v_7181 = qcar(v_7181);
    if (v_7181 == nil) goto v_7117;
    else goto v_7118;
v_7117:
    goto v_7073;
v_7118:
    v_7181 = stack[-1];
    if (v_7181 == nil) goto v_7121;
    else goto v_7122;
v_7121:
    goto v_7072;
v_7122:
    goto v_7129;
v_7125:
    goto v_7126;
v_7127:
    v_7181 = stack[-1];
    fn = elt(env, 4); // simpcar
    v_7181 = (*qfn1(fn))(fn, v_7181);
    env = stack[-3];
    goto v_7128;
v_7129:
    goto v_7125;
v_7126:
    goto v_7127;
v_7128:
    fn = elt(env, 5); // multsq
    v_7181 = (*qfn2(fn))(fn, stack[0], v_7181);
    env = stack[-3];
    stack[0] = v_7181;
    goto v_7071;
v_7072:
    v_7181 = qvalue(elt(env, 2)); // mul!*
    if (v_7181 == nil) goto v_7139;
    else goto v_7140;
v_7139:
    v_7181 = lisp_true;
    goto v_7138;
v_7140:
    goto v_7150;
v_7146:
    v_7182 = qvalue(elt(env, 1)); // tstack!*
    goto v_7147;
v_7148:
    v_7181 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7149;
v_7150:
    goto v_7146;
v_7147:
    goto v_7148;
v_7149:
    v_7181 = (LispObject)greaterp2(v_7182, v_7181);
    v_7181 = v_7181 ? lisp_true : nil;
    env = stack[-3];
    goto v_7138;
    v_7181 = nil;
v_7138:
    if (v_7181 == nil) goto v_7136;
    goto v_7073;
v_7136:
    goto v_7158;
v_7154:
    v_7181 = qvalue(elt(env, 2)); // mul!*
    v_7182 = qcar(v_7181);
    goto v_7155;
v_7156:
    v_7181 = stack[0];
    goto v_7157;
v_7158:
    goto v_7154;
v_7155:
    goto v_7156;
v_7157:
    v_7181 = Lapply1(nil, v_7182, v_7181);
    env = stack[-3];
    stack[0] = v_7181;
    v_7181 = nil;
    v_7181 = ncons(v_7181);
    env = stack[-3];
    qvalue(elt(env, 3)) = v_7181; // alglist!*
    v_7181 = qvalue(elt(env, 2)); // mul!*
    v_7181 = qcdr(v_7181);
    qvalue(elt(env, 2)) = v_7181; // mul!*
    goto v_7072;
v_7073:
    v_7181 = qvalue(elt(env, 1)); // tstack!*
    v_7181 = sub1(v_7181);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_7181; // tstack!*
    goto v_7176;
v_7172:
    v_7182 = qvalue(elt(env, 1)); // tstack!*
    goto v_7173;
v_7174:
    v_7181 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7175;
v_7176:
    goto v_7172;
v_7173:
    goto v_7174;
v_7175:
    if (v_7182 == v_7181) goto v_7170;
    else goto v_7171;
v_7170:
    v_7181 = stack[-2];
    qvalue(elt(env, 2)) = v_7181; // mul!*
    goto v_7169;
v_7171:
v_7169:
    v_7181 = stack[0];
    return onevalue(v_7181);
}



// Code for pdif

static LispObject CC_pdif(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7076, v_7077;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7076 = v_7065;
    v_7077 = v_7064;
// end of prologue
    goto v_7072;
v_7068:
    stack[0] = v_7077;
    goto v_7069;
v_7070:
    fn = elt(env, 1); // pneg
    v_7076 = (*qfn1(fn))(fn, v_7076);
    env = stack[-1];
    goto v_7071;
v_7072:
    goto v_7068;
v_7069:
    goto v_7070;
v_7071:
    {
        LispObject v_7079 = stack[0];
        fn = elt(env, 2); // psum
        return (*qfn2(fn))(fn, v_7079, v_7076);
    }
}



// Code for lalr_most_common_reduction

static LispObject CC_lalr_most_common_reduction(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7201, v_7202, v_7203;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7064);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_7201 = v_7064;
// end of prologue
    stack[-3] = nil;
    stack[-1] = v_7201;
v_7074:
    v_7201 = stack[-1];
    if (v_7201 == nil) goto v_7078;
    else goto v_7079;
v_7078:
    goto v_7073;
v_7079:
    v_7201 = stack[-1];
    v_7201 = qcar(v_7201);
    v_7202 = v_7201;
    goto v_7097;
v_7093:
    v_7201 = v_7202;
    v_7201 = qcdr(v_7201);
    v_7201 = qcar(v_7201);
    v_7203 = qcar(v_7201);
    goto v_7094;
v_7095:
    v_7201 = elt(env, 1); // reduce
    goto v_7096;
v_7097:
    goto v_7093;
v_7094:
    goto v_7095;
v_7096:
    if (v_7203 == v_7201) goto v_7091;
    else goto v_7092;
v_7091:
    v_7201 = lisp_true;
    goto v_7090;
v_7092:
    goto v_7110;
v_7106:
    v_7201 = v_7202;
    v_7201 = qcdr(v_7201);
    v_7201 = qcar(v_7201);
    v_7203 = qcar(v_7201);
    goto v_7107;
v_7108:
    v_7201 = elt(env, 2); // accept
    goto v_7109;
v_7110:
    goto v_7106;
v_7107:
    goto v_7108;
v_7109:
    v_7201 = (v_7203 == v_7201 ? lisp_true : nil);
    goto v_7090;
    v_7201 = nil;
v_7090:
    if (v_7201 == nil) goto v_7088;
    v_7201 = v_7202;
    v_7201 = qcdr(v_7201);
    v_7201 = qcar(v_7201);
    v_7203 = v_7201;
    goto v_7128;
v_7124:
    goto v_7125;
v_7126:
    v_7201 = v_7203;
    goto v_7127;
v_7128:
    goto v_7124;
v_7125:
    goto v_7126;
v_7127:
    v_7201 = Lassoc(nil, v_7202, v_7201);
    stack[-2] = v_7201;
    if (v_7201 == nil) goto v_7123;
    goto v_7137;
v_7133:
    stack[0] = stack[-2];
    goto v_7134;
v_7135:
    v_7201 = stack[-2];
    v_7201 = qcdr(v_7201);
    v_7201 = add1(v_7201);
    env = stack[-4];
    goto v_7136;
v_7137:
    goto v_7133;
v_7134:
    goto v_7135;
v_7136:
    v_7201 = Lrplacd(nil, stack[0], v_7201);
    env = stack[-4];
    goto v_7121;
v_7123:
    goto v_7151;
v_7145:
    goto v_7146;
v_7147:
    v_7202 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7148;
v_7149:
    v_7201 = stack[-3];
    goto v_7150;
v_7151:
    goto v_7145;
v_7146:
    goto v_7147;
v_7148:
    goto v_7149;
v_7150:
    v_7201 = acons(v_7203, v_7202, v_7201);
    env = stack[-4];
    stack[-3] = v_7201;
    goto v_7121;
v_7121:
    goto v_7086;
v_7088:
v_7086:
    v_7201 = stack[-1];
    v_7201 = qcdr(v_7201);
    stack[-1] = v_7201;
    goto v_7074;
v_7073:
    v_7201 = stack[-3];
    if (v_7201 == nil) goto v_7160;
    v_7201 = stack[-3];
    v_7201 = qcar(v_7201);
    stack[-2] = v_7201;
    v_7201 = stack[-3];
    v_7201 = qcdr(v_7201);
    stack[-1] = v_7201;
v_7167:
    v_7201 = stack[-1];
    if (v_7201 == nil) goto v_7172;
    else goto v_7173;
v_7172:
    goto v_7166;
v_7173:
    v_7201 = stack[-1];
    v_7201 = qcar(v_7201);
    stack[0] = v_7201;
    goto v_7188;
v_7184:
    v_7201 = stack[0];
    v_7202 = qcdr(v_7201);
    goto v_7185;
v_7186:
    v_7201 = stack[-2];
    v_7201 = qcdr(v_7201);
    goto v_7187;
v_7188:
    goto v_7184;
v_7185:
    goto v_7186;
v_7187:
    v_7201 = (LispObject)greaterp2(v_7202, v_7201);
    v_7201 = v_7201 ? lisp_true : nil;
    env = stack[-4];
    if (v_7201 == nil) goto v_7182;
    v_7201 = stack[0];
    stack[-2] = v_7201;
    goto v_7180;
v_7182:
v_7180:
    v_7201 = stack[-1];
    v_7201 = qcdr(v_7201);
    stack[-1] = v_7201;
    goto v_7167;
v_7166:
    v_7201 = stack[-2];
    v_7201 = qcar(v_7201);
    goto v_7070;
v_7160:
    v_7201 = nil;
    goto v_7070;
    v_7201 = nil;
v_7070:
    return onevalue(v_7201);
}



// Code for wtchk

static LispObject CC_wtchk(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7130, v_7131, v_7132;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_7065;
    stack[-2] = v_7064;
// end of prologue
    v_7130 = stack[-1];
    if (v_7130 == nil) goto v_7069;
    else goto v_7070;
v_7069:
    v_7130 = stack[-2];
    goto v_7068;
v_7070:
    goto v_7080;
v_7076:
    v_7130 = stack[-2];
    stack[-3] = ncons(v_7130);
    env = stack[-4];
    goto v_7077;
v_7078:
    goto v_7089;
v_7085:
    goto v_7095;
v_7091:
    stack[0] = elt(env, 1); // k!*
    goto v_7092;
v_7093:
    goto v_7102;
v_7098:
    v_7131 = stack[-1];
    goto v_7099;
v_7100:
    v_7130 = stack[-2];
    v_7130 = qcar(v_7130);
    v_7130 = qcdr(v_7130);
    goto v_7101;
v_7102:
    goto v_7098;
v_7099:
    goto v_7100;
v_7101:
    v_7130 = times2(v_7131, v_7130);
    env = stack[-4];
    goto v_7094;
v_7095:
    goto v_7091;
v_7092:
    goto v_7093;
v_7094:
    fn = elt(env, 3); // to
    v_7131 = (*qfn2(fn))(fn, stack[0], v_7130);
    env = stack[-4];
    goto v_7086;
v_7087:
    v_7130 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7088;
v_7089:
    goto v_7085;
v_7086:
    goto v_7087;
v_7088:
    v_7130 = cons(v_7131, v_7130);
    env = stack[-4];
    v_7130 = ncons(v_7130);
    env = stack[-4];
    goto v_7079;
v_7080:
    goto v_7076;
v_7077:
    goto v_7078;
v_7079:
    fn = elt(env, 4); // quotf
    v_7130 = (*qfn2(fn))(fn, stack[-3], v_7130);
    env = stack[-4];
    v_7131 = v_7130;
    v_7130 = v_7131;
    if (v_7130 == nil) goto v_7111;
    else goto v_7112;
v_7111:
    goto v_7122;
v_7116:
    v_7132 = elt(env, 2); // "weight confusion"
    goto v_7117;
v_7118:
    v_7131 = stack[-2];
    goto v_7119;
v_7120:
    v_7130 = stack[-1];
    goto v_7121;
v_7122:
    goto v_7116;
v_7117:
    goto v_7118;
v_7119:
    goto v_7120;
v_7121:
    v_7130 = list3(v_7132, v_7131, v_7130);
    env = stack[-4];
    {
        fn = elt(env, 5); // errach
        return (*qfn1(fn))(fn, v_7130);
    }
v_7112:
    v_7130 = v_7131;
    v_7130 = qcar(v_7130);
    goto v_7110;
    v_7130 = nil;
v_7110:
    goto v_7068;
    v_7130 = nil;
v_7068:
    return onevalue(v_7130);
}



// Code for mk!+mat!+mult!+mat

static LispObject CC_mkLmatLmultLmat(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7534, v_7535, v_7536;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(17);
// copy arguments values to proper place
    stack[-13] = v_7065;
    stack[-14] = v_7064;
// end of prologue
    v_7534 = stack[-14];
    fn = elt(env, 4); // matrix!+p
    v_7534 = (*qfn1(fn))(fn, v_7534);
    env = stack[-16];
    if (v_7534 == nil) goto v_7079;
    else goto v_7080;
v_7079:
    v_7534 = elt(env, 1); // "no matrix in mult"
    fn = elt(env, 5); // rederr
    v_7534 = (*qfn1(fn))(fn, v_7534);
    env = stack[-16];
    goto v_7078;
v_7080:
v_7078:
    v_7534 = stack[-13];
    fn = elt(env, 4); // matrix!+p
    v_7534 = (*qfn1(fn))(fn, v_7534);
    env = stack[-16];
    if (v_7534 == nil) goto v_7087;
    else goto v_7088;
v_7087:
    v_7534 = elt(env, 1); // "no matrix in mult"
    fn = elt(env, 5); // rederr
    v_7534 = (*qfn1(fn))(fn, v_7534);
    env = stack[-16];
    goto v_7086;
v_7088:
v_7086:
    v_7534 = stack[-14];
    fn = elt(env, 6); // get!+col!+nr
    v_7534 = (*qfn1(fn))(fn, v_7534);
    env = stack[-16];
    stack[-15] = v_7534;
    v_7534 = stack[-14];
    fn = elt(env, 7); // get!+row!+nr
    v_7534 = (*qfn1(fn))(fn, v_7534);
    env = stack[-16];
    stack[-12] = v_7534;
    v_7534 = stack[-13];
    fn = elt(env, 6); // get!+col!+nr
    v_7534 = (*qfn1(fn))(fn, v_7534);
    env = stack[-16];
    stack[-11] = v_7534;
    goto v_7107;
v_7103:
    stack[0] = stack[-15];
    goto v_7104;
v_7105:
    v_7534 = stack[-13];
    fn = elt(env, 7); // get!+row!+nr
    v_7534 = (*qfn1(fn))(fn, v_7534);
    env = stack[-16];
    goto v_7106;
v_7107:
    goto v_7103;
v_7104:
    goto v_7105;
v_7106:
    if (equal(stack[0], v_7534)) goto v_7102;
    v_7534 = elt(env, 2); // "matrices can not be multiplied"
    fn = elt(env, 5); // rederr
    v_7534 = (*qfn1(fn))(fn, v_7534);
    env = stack[-16];
    goto v_7100;
v_7102:
v_7100:
    v_7534 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-10] = v_7534;
    goto v_7130;
v_7126:
    v_7535 = stack[-12];
    goto v_7127;
v_7128:
    v_7534 = stack[-10];
    goto v_7129;
v_7130:
    goto v_7126;
v_7127:
    goto v_7128;
v_7129:
    v_7534 = difference2(v_7535, v_7534);
    env = stack[-16];
    v_7534 = Lminusp(nil, v_7534);
    env = stack[-16];
    if (v_7534 == nil) goto v_7123;
    v_7534 = nil;
    goto v_7117;
v_7123:
    v_7534 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_7534;
    goto v_7152;
v_7148:
    v_7535 = stack[-11];
    goto v_7149;
v_7150:
    v_7534 = stack[-5];
    goto v_7151;
v_7152:
    goto v_7148;
v_7149:
    goto v_7150;
v_7151:
    v_7534 = difference2(v_7535, v_7534);
    env = stack[-16];
    v_7534 = Lminusp(nil, v_7534);
    env = stack[-16];
    if (v_7534 == nil) goto v_7145;
    v_7534 = nil;
    goto v_7139;
v_7145:
    goto v_7162;
v_7158:
    v_7535 = nil;
    goto v_7159;
v_7160:
    v_7534 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7161;
v_7162:
    goto v_7158;
v_7159:
    goto v_7160;
v_7161:
    v_7534 = cons(v_7535, v_7534);
    env = stack[-16];
    stack[0] = v_7534;
    v_7534 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_7534;
v_7168:
    goto v_7180;
v_7176:
    v_7535 = stack[-15];
    goto v_7177;
v_7178:
    v_7534 = stack[-1];
    goto v_7179;
v_7180:
    goto v_7176;
v_7177:
    goto v_7178;
v_7179:
    v_7534 = difference2(v_7535, v_7534);
    env = stack[-16];
    v_7534 = Lminusp(nil, v_7534);
    env = stack[-16];
    if (v_7534 == nil) goto v_7173;
    goto v_7167;
v_7173:
    goto v_7189;
v_7185:
    stack[-2] = stack[0];
    goto v_7186;
v_7187:
    goto v_7196;
v_7192:
    goto v_7204;
v_7198:
    v_7536 = stack[-14];
    goto v_7199;
v_7200:
    v_7535 = stack[-10];
    goto v_7201;
v_7202:
    v_7534 = stack[-1];
    goto v_7203;
v_7204:
    goto v_7198;
v_7199:
    goto v_7200;
v_7201:
    goto v_7202;
v_7203:
    fn = elt(env, 8); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(fn, 3, v_7536, v_7535, v_7534);
    env = stack[-16];
    goto v_7193;
v_7194:
    goto v_7215;
v_7209:
    v_7536 = stack[-13];
    goto v_7210;
v_7211:
    v_7535 = stack[-1];
    goto v_7212;
v_7213:
    v_7534 = stack[-5];
    goto v_7214;
v_7215:
    goto v_7209;
v_7210:
    goto v_7211;
v_7212:
    goto v_7213;
v_7214:
    fn = elt(env, 8); // get!+mat!+entry
    v_7534 = (*qfnn(fn))(fn, 3, v_7536, v_7535, v_7534);
    env = stack[-16];
    goto v_7195;
v_7196:
    goto v_7192;
v_7193:
    goto v_7194;
v_7195:
    fn = elt(env, 9); // multsq
    v_7534 = (*qfn2(fn))(fn, stack[0], v_7534);
    env = stack[-16];
    goto v_7188;
v_7189:
    goto v_7185;
v_7186:
    goto v_7187;
v_7188:
    fn = elt(env, 10); // addsq
    v_7534 = (*qfn2(fn))(fn, stack[-2], v_7534);
    env = stack[-16];
    stack[0] = v_7534;
    v_7534 = stack[-1];
    v_7534 = add1(v_7534);
    env = stack[-16];
    stack[-1] = v_7534;
    goto v_7168;
v_7167:
    v_7534 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=16 litvec-offset=3 saveloc=1
{   bind_fluid_stack bind_fluid_var(-16, 3, -1);
    qvalue(elt(env, 3)) = v_7534; // !*sub2
    v_7534 = stack[0];
    fn = elt(env, 11); // subs2
    v_7534 = (*qfn1(fn))(fn, v_7534);
    env = stack[-16];
    stack[0] = v_7534;
    ;}  // end of a binding scope
    v_7534 = stack[0];
    v_7534 = ncons(v_7534);
    env = stack[-16];
    stack[-3] = v_7534;
    stack[-4] = v_7534;
v_7140:
    v_7534 = stack[-5];
    v_7534 = add1(v_7534);
    env = stack[-16];
    stack[-5] = v_7534;
    goto v_7238;
v_7234:
    v_7535 = stack[-11];
    goto v_7235;
v_7236:
    v_7534 = stack[-5];
    goto v_7237;
v_7238:
    goto v_7234;
v_7235:
    goto v_7236;
v_7237:
    v_7534 = difference2(v_7535, v_7534);
    env = stack[-16];
    v_7534 = Lminusp(nil, v_7534);
    env = stack[-16];
    if (v_7534 == nil) goto v_7231;
    v_7534 = stack[-4];
    goto v_7139;
v_7231:
    goto v_7247;
v_7243:
    stack[-2] = stack[-3];
    goto v_7244;
v_7245:
    goto v_7255;
v_7251:
    v_7535 = nil;
    goto v_7252;
v_7253:
    v_7534 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7254;
v_7255:
    goto v_7251;
v_7252:
    goto v_7253;
v_7254:
    v_7534 = cons(v_7535, v_7534);
    env = stack[-16];
    stack[0] = v_7534;
    v_7534 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_7534;
v_7261:
    goto v_7273;
v_7269:
    v_7535 = stack[-15];
    goto v_7270;
v_7271:
    v_7534 = stack[-1];
    goto v_7272;
v_7273:
    goto v_7269;
v_7270:
    goto v_7271;
v_7272:
    v_7534 = difference2(v_7535, v_7534);
    env = stack[-16];
    v_7534 = Lminusp(nil, v_7534);
    env = stack[-16];
    if (v_7534 == nil) goto v_7266;
    goto v_7260;
v_7266:
    goto v_7282;
v_7278:
    stack[-6] = stack[0];
    goto v_7279;
v_7280:
    goto v_7289;
v_7285:
    goto v_7297;
v_7291:
    v_7536 = stack[-14];
    goto v_7292;
v_7293:
    v_7535 = stack[-10];
    goto v_7294;
v_7295:
    v_7534 = stack[-1];
    goto v_7296;
v_7297:
    goto v_7291;
v_7292:
    goto v_7293;
v_7294:
    goto v_7295;
v_7296:
    fn = elt(env, 8); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(fn, 3, v_7536, v_7535, v_7534);
    env = stack[-16];
    goto v_7286;
v_7287:
    goto v_7308;
v_7302:
    v_7536 = stack[-13];
    goto v_7303;
v_7304:
    v_7535 = stack[-1];
    goto v_7305;
v_7306:
    v_7534 = stack[-5];
    goto v_7307;
v_7308:
    goto v_7302;
v_7303:
    goto v_7304;
v_7305:
    goto v_7306;
v_7307:
    fn = elt(env, 8); // get!+mat!+entry
    v_7534 = (*qfnn(fn))(fn, 3, v_7536, v_7535, v_7534);
    env = stack[-16];
    goto v_7288;
v_7289:
    goto v_7285;
v_7286:
    goto v_7287;
v_7288:
    fn = elt(env, 9); // multsq
    v_7534 = (*qfn2(fn))(fn, stack[0], v_7534);
    env = stack[-16];
    goto v_7281;
v_7282:
    goto v_7278;
v_7279:
    goto v_7280;
v_7281:
    fn = elt(env, 10); // addsq
    v_7534 = (*qfn2(fn))(fn, stack[-6], v_7534);
    env = stack[-16];
    stack[0] = v_7534;
    v_7534 = stack[-1];
    v_7534 = add1(v_7534);
    env = stack[-16];
    stack[-1] = v_7534;
    goto v_7261;
v_7260:
    v_7534 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=16 litvec-offset=3 saveloc=1
{   bind_fluid_stack bind_fluid_var(-16, 3, -1);
    qvalue(elt(env, 3)) = v_7534; // !*sub2
    v_7534 = stack[0];
    fn = elt(env, 11); // subs2
    v_7534 = (*qfn1(fn))(fn, v_7534);
    env = stack[-16];
    stack[0] = v_7534;
    ;}  // end of a binding scope
    v_7534 = stack[0];
    v_7534 = ncons(v_7534);
    env = stack[-16];
    goto v_7246;
v_7247:
    goto v_7243;
v_7244:
    goto v_7245;
v_7246:
    v_7534 = Lrplacd(nil, stack[-2], v_7534);
    env = stack[-16];
    v_7534 = stack[-3];
    v_7534 = qcdr(v_7534);
    stack[-3] = v_7534;
    goto v_7140;
v_7139:
    v_7534 = ncons(v_7534);
    env = stack[-16];
    stack[-8] = v_7534;
    stack[-9] = v_7534;
v_7118:
    v_7534 = stack[-10];
    v_7534 = add1(v_7534);
    env = stack[-16];
    stack[-10] = v_7534;
    goto v_7333;
v_7329:
    v_7535 = stack[-12];
    goto v_7330;
v_7331:
    v_7534 = stack[-10];
    goto v_7332;
v_7333:
    goto v_7329;
v_7330:
    goto v_7331;
v_7332:
    v_7534 = difference2(v_7535, v_7534);
    env = stack[-16];
    v_7534 = Lminusp(nil, v_7534);
    env = stack[-16];
    if (v_7534 == nil) goto v_7326;
    v_7534 = stack[-9];
    goto v_7117;
v_7326:
    goto v_7342;
v_7338:
    stack[-7] = stack[-8];
    goto v_7339;
v_7340:
    v_7534 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_7534;
    goto v_7362;
v_7358:
    v_7535 = stack[-11];
    goto v_7359;
v_7360:
    v_7534 = stack[-6];
    goto v_7361;
v_7362:
    goto v_7358;
v_7359:
    goto v_7360;
v_7361:
    v_7534 = difference2(v_7535, v_7534);
    env = stack[-16];
    v_7534 = Lminusp(nil, v_7534);
    env = stack[-16];
    if (v_7534 == nil) goto v_7355;
    v_7534 = nil;
    goto v_7349;
v_7355:
    goto v_7372;
v_7368:
    v_7535 = nil;
    goto v_7369;
v_7370:
    v_7534 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7371;
v_7372:
    goto v_7368;
v_7369:
    goto v_7370;
v_7371:
    v_7534 = cons(v_7535, v_7534);
    env = stack[-16];
    stack[0] = v_7534;
    v_7534 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_7534;
v_7378:
    goto v_7390;
v_7386:
    v_7535 = stack[-15];
    goto v_7387;
v_7388:
    v_7534 = stack[-1];
    goto v_7389;
v_7390:
    goto v_7386;
v_7387:
    goto v_7388;
v_7389:
    v_7534 = difference2(v_7535, v_7534);
    env = stack[-16];
    v_7534 = Lminusp(nil, v_7534);
    env = stack[-16];
    if (v_7534 == nil) goto v_7383;
    goto v_7377;
v_7383:
    goto v_7399;
v_7395:
    stack[-2] = stack[0];
    goto v_7396;
v_7397:
    goto v_7406;
v_7402:
    goto v_7414;
v_7408:
    v_7536 = stack[-14];
    goto v_7409;
v_7410:
    v_7535 = stack[-10];
    goto v_7411;
v_7412:
    v_7534 = stack[-1];
    goto v_7413;
v_7414:
    goto v_7408;
v_7409:
    goto v_7410;
v_7411:
    goto v_7412;
v_7413:
    fn = elt(env, 8); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(fn, 3, v_7536, v_7535, v_7534);
    env = stack[-16];
    goto v_7403;
v_7404:
    goto v_7425;
v_7419:
    v_7536 = stack[-13];
    goto v_7420;
v_7421:
    v_7535 = stack[-1];
    goto v_7422;
v_7423:
    v_7534 = stack[-6];
    goto v_7424;
v_7425:
    goto v_7419;
v_7420:
    goto v_7421;
v_7422:
    goto v_7423;
v_7424:
    fn = elt(env, 8); // get!+mat!+entry
    v_7534 = (*qfnn(fn))(fn, 3, v_7536, v_7535, v_7534);
    env = stack[-16];
    goto v_7405;
v_7406:
    goto v_7402;
v_7403:
    goto v_7404;
v_7405:
    fn = elt(env, 9); // multsq
    v_7534 = (*qfn2(fn))(fn, stack[0], v_7534);
    env = stack[-16];
    goto v_7398;
v_7399:
    goto v_7395;
v_7396:
    goto v_7397;
v_7398:
    fn = elt(env, 10); // addsq
    v_7534 = (*qfn2(fn))(fn, stack[-2], v_7534);
    env = stack[-16];
    stack[0] = v_7534;
    v_7534 = stack[-1];
    v_7534 = add1(v_7534);
    env = stack[-16];
    stack[-1] = v_7534;
    goto v_7378;
v_7377:
    v_7534 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=16 litvec-offset=3 saveloc=1
{   bind_fluid_stack bind_fluid_var(-16, 3, -1);
    qvalue(elt(env, 3)) = v_7534; // !*sub2
    v_7534 = stack[0];
    fn = elt(env, 11); // subs2
    v_7534 = (*qfn1(fn))(fn, v_7534);
    env = stack[-16];
    stack[0] = v_7534;
    ;}  // end of a binding scope
    v_7534 = stack[0];
    v_7534 = ncons(v_7534);
    env = stack[-16];
    stack[-4] = v_7534;
    stack[-5] = v_7534;
v_7350:
    v_7534 = stack[-6];
    v_7534 = add1(v_7534);
    env = stack[-16];
    stack[-6] = v_7534;
    goto v_7448;
v_7444:
    v_7535 = stack[-11];
    goto v_7445;
v_7446:
    v_7534 = stack[-6];
    goto v_7447;
v_7448:
    goto v_7444;
v_7445:
    goto v_7446;
v_7447:
    v_7534 = difference2(v_7535, v_7534);
    env = stack[-16];
    v_7534 = Lminusp(nil, v_7534);
    env = stack[-16];
    if (v_7534 == nil) goto v_7441;
    v_7534 = stack[-5];
    goto v_7349;
v_7441:
    goto v_7457;
v_7453:
    stack[-3] = stack[-4];
    goto v_7454;
v_7455:
    goto v_7465;
v_7461:
    v_7535 = nil;
    goto v_7462;
v_7463:
    v_7534 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7464;
v_7465:
    goto v_7461;
v_7462:
    goto v_7463;
v_7464:
    v_7534 = cons(v_7535, v_7534);
    env = stack[-16];
    stack[0] = v_7534;
    v_7534 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_7534;
v_7471:
    goto v_7483;
v_7479:
    v_7535 = stack[-15];
    goto v_7480;
v_7481:
    v_7534 = stack[-2];
    goto v_7482;
v_7483:
    goto v_7479;
v_7480:
    goto v_7481;
v_7482:
    v_7534 = difference2(v_7535, v_7534);
    env = stack[-16];
    v_7534 = Lminusp(nil, v_7534);
    env = stack[-16];
    if (v_7534 == nil) goto v_7476;
    goto v_7470;
v_7476:
    goto v_7492;
v_7488:
    stack[-1] = stack[0];
    goto v_7489;
v_7490:
    goto v_7499;
v_7495:
    goto v_7507;
v_7501:
    v_7536 = stack[-14];
    goto v_7502;
v_7503:
    v_7535 = stack[-10];
    goto v_7504;
v_7505:
    v_7534 = stack[-2];
    goto v_7506;
v_7507:
    goto v_7501;
v_7502:
    goto v_7503;
v_7504:
    goto v_7505;
v_7506:
    fn = elt(env, 8); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(fn, 3, v_7536, v_7535, v_7534);
    env = stack[-16];
    goto v_7496;
v_7497:
    goto v_7518;
v_7512:
    v_7536 = stack[-13];
    goto v_7513;
v_7514:
    v_7535 = stack[-2];
    goto v_7515;
v_7516:
    v_7534 = stack[-6];
    goto v_7517;
v_7518:
    goto v_7512;
v_7513:
    goto v_7514;
v_7515:
    goto v_7516;
v_7517:
    fn = elt(env, 8); // get!+mat!+entry
    v_7534 = (*qfnn(fn))(fn, 3, v_7536, v_7535, v_7534);
    env = stack[-16];
    goto v_7498;
v_7499:
    goto v_7495;
v_7496:
    goto v_7497;
v_7498:
    fn = elt(env, 9); // multsq
    v_7534 = (*qfn2(fn))(fn, stack[0], v_7534);
    env = stack[-16];
    goto v_7491;
v_7492:
    goto v_7488;
v_7489:
    goto v_7490;
v_7491:
    fn = elt(env, 10); // addsq
    v_7534 = (*qfn2(fn))(fn, stack[-1], v_7534);
    env = stack[-16];
    stack[0] = v_7534;
    v_7534 = stack[-2];
    v_7534 = add1(v_7534);
    env = stack[-16];
    stack[-2] = v_7534;
    goto v_7471;
v_7470:
    v_7534 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=16 litvec-offset=3 saveloc=1
{   bind_fluid_stack bind_fluid_var(-16, 3, -1);
    qvalue(elt(env, 3)) = v_7534; // !*sub2
    v_7534 = stack[0];
    fn = elt(env, 11); // subs2
    v_7534 = (*qfn1(fn))(fn, v_7534);
    env = stack[-16];
    stack[0] = v_7534;
    ;}  // end of a binding scope
    v_7534 = stack[0];
    v_7534 = ncons(v_7534);
    env = stack[-16];
    goto v_7456;
v_7457:
    goto v_7453;
v_7454:
    goto v_7455;
v_7456:
    v_7534 = Lrplacd(nil, stack[-3], v_7534);
    env = stack[-16];
    v_7534 = stack[-4];
    v_7534 = qcdr(v_7534);
    stack[-4] = v_7534;
    goto v_7350;
v_7349:
    v_7534 = ncons(v_7534);
    env = stack[-16];
    goto v_7341;
v_7342:
    goto v_7338;
v_7339:
    goto v_7340;
v_7341:
    v_7534 = Lrplacd(nil, stack[-7], v_7534);
    env = stack[-16];
    v_7534 = stack[-8];
    v_7534 = qcdr(v_7534);
    stack[-8] = v_7534;
    goto v_7118;
v_7117:
    return onevalue(v_7534);
}



// Code for talp_chkknowl

static LispObject CC_talp_chkknowl(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7206, v_7207;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-1] = v_7065;
    stack[-2] = v_7064;
// end of prologue
    stack[-4] = nil;
    stack[0] = nil;
    v_7206 = stack[-2];
    fn = elt(env, 3); // talp_candp
    v_7206 = (*qfn1(fn))(fn, v_7206);
    env = stack[-8];
    if (v_7206 == nil) goto v_7080;
    v_7206 = stack[-2];
    fn = elt(env, 4); // talp_arg2l
    v_7206 = (*qfn1(fn))(fn, v_7206);
    env = stack[-8];
    if (!consp(v_7206)) goto v_7085;
    else goto v_7086;
v_7085:
    v_7206 = stack[-2];
    fn = elt(env, 4); // talp_arg2l
    v_7206 = (*qfn1(fn))(fn, v_7206);
    env = stack[-8];
    stack[-5] = v_7206;
    v_7206 = stack[-2];
    fn = elt(env, 5); // talp_arg2r
    v_7206 = (*qfn1(fn))(fn, v_7206);
    env = stack[-8];
    goto v_7084;
v_7086:
    v_7206 = stack[-2];
    fn = elt(env, 5); // talp_arg2r
    v_7206 = (*qfn1(fn))(fn, v_7206);
    env = stack[-8];
    stack[-5] = v_7206;
    v_7206 = stack[-2];
    fn = elt(env, 4); // talp_arg2l
    v_7206 = (*qfn1(fn))(fn, v_7206);
    env = stack[-8];
    goto v_7084;
    v_7206 = nil;
v_7084:
    stack[-7] = v_7206;
    v_7206 = stack[-7];
    fn = elt(env, 6); // talp_invf
    v_7206 = (*qfn1(fn))(fn, v_7206);
    env = stack[-8];
    stack[-6] = v_7206;
    v_7206 = stack[-2];
    fn = elt(env, 7); // talp_op
    v_7206 = (*qfn1(fn))(fn, v_7206);
    env = stack[-8];
    stack[-2] = v_7206;
    v_7206 = stack[-1];
    stack[-1] = v_7206;
v_7106:
    v_7206 = stack[-1];
    if (v_7206 == nil) goto v_7109;
    v_7206 = stack[-4];
    if (v_7206 == nil) goto v_7113;
    else goto v_7109;
v_7113:
    goto v_7110;
v_7109:
    goto v_7105;
v_7110:
    v_7206 = stack[-1];
    v_7206 = qcar(v_7206);
    v_7206 = qcar(v_7206);
    stack[-3] = v_7206;
    v_7206 = stack[-3];
    fn = elt(env, 3); // talp_candp
    v_7206 = (*qfn1(fn))(fn, v_7206);
    env = stack[-8];
    if (v_7206 == nil) goto v_7122;
    v_7206 = stack[-3];
    fn = elt(env, 4); // talp_arg2l
    v_7206 = (*qfn1(fn))(fn, v_7206);
    env = stack[-8];
    fn = elt(env, 8); // talp_invp
    v_7206 = (*qfn1(fn))(fn, v_7206);
    env = stack[-8];
    if (v_7206 == nil) goto v_7128;
    v_7206 = stack[-3];
    fn = elt(env, 4); // talp_arg2l
    v_7206 = (*qfn1(fn))(fn, v_7206);
    env = stack[-8];
    goto v_7126;
v_7128:
    v_7206 = stack[-3];
    fn = elt(env, 5); // talp_arg2r
    v_7206 = (*qfn1(fn))(fn, v_7206);
    env = stack[-8];
    goto v_7126;
    v_7206 = nil;
v_7126:
    stack[-7] = v_7206;
    goto v_7146;
v_7142:
    v_7206 = stack[-7];
    fn = elt(env, 9); // talp_invarg
    v_7207 = (*qfn1(fn))(fn, v_7206);
    env = stack[-8];
    goto v_7143;
v_7144:
    v_7206 = stack[-5];
    goto v_7145;
v_7146:
    goto v_7142;
v_7143:
    goto v_7144;
v_7145:
    if (v_7207 == v_7206) goto v_7140;
    else goto v_7141;
v_7140:
    goto v_7162;
v_7158:
    v_7206 = stack[-3];
    if (!consp(v_7206)) goto v_7165;
    else goto v_7166;
v_7165:
    v_7206 = stack[-3];
    v_7207 = v_7206;
    goto v_7164;
v_7166:
    v_7206 = stack[-3];
    v_7206 = qcar(v_7206);
    v_7207 = v_7206;
    goto v_7164;
    v_7207 = nil;
v_7164:
    goto v_7159;
v_7160:
    v_7206 = stack[-2];
    goto v_7161;
v_7162:
    goto v_7158;
v_7159:
    goto v_7160;
v_7161:
    if (v_7207 == v_7206) goto v_7156;
    else goto v_7157;
v_7156:
    goto v_7178;
v_7174:
    v_7207 = stack[-2];
    goto v_7175;
v_7176:
    v_7206 = elt(env, 1); // neq
    goto v_7177;
v_7178:
    goto v_7174;
v_7175:
    goto v_7176;
v_7177:
    v_7206 = (v_7207 == v_7206 ? lisp_true : nil);
    goto v_7155;
v_7157:
    v_7206 = nil;
    goto v_7155;
    v_7206 = nil;
v_7155:
    if (v_7206 == nil) goto v_7153;
    goto v_7193;
v_7189:
    v_7206 = stack[-7];
    fn = elt(env, 6); // talp_invf
    v_7207 = (*qfn1(fn))(fn, v_7206);
    env = stack[-8];
    goto v_7190;
v_7191:
    v_7206 = stack[-6];
    goto v_7192;
v_7193:
    goto v_7189;
v_7190:
    goto v_7191;
v_7192:
    if (equal(v_7207, v_7206)) goto v_7188;
    v_7206 = elt(env, 2); // true
    stack[0] = v_7206;
    v_7206 = lisp_true;
    stack[-4] = v_7206;
    goto v_7186;
v_7188:
v_7186:
    goto v_7151;
v_7153:
v_7151:
    goto v_7139;
v_7141:
v_7139:
    goto v_7120;
v_7122:
v_7120:
    v_7206 = stack[-1];
    v_7206 = qcdr(v_7206);
    stack[-1] = v_7206;
    goto v_7106;
v_7105:
    goto v_7078;
v_7080:
    v_7206 = nil;
    goto v_7076;
v_7078:
    v_7206 = stack[0];
v_7076:
    return onevalue(v_7206);
}



// Code for rl_susitf

static LispObject CC_rl_susitf(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7082, v_7083;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7082 = v_7065;
    v_7083 = v_7064;
// end of prologue
    goto v_7072;
v_7068:
    stack[0] = qvalue(elt(env, 1)); // rl_susitf!*
    goto v_7069;
v_7070:
    goto v_7079;
v_7075:
    goto v_7076;
v_7077:
    goto v_7078;
v_7079:
    goto v_7075;
v_7076:
    goto v_7077;
v_7078:
    v_7082 = list2(v_7083, v_7082);
    env = stack[-1];
    goto v_7071;
v_7072:
    goto v_7068;
v_7069:
    goto v_7070;
v_7071:
    {
        LispObject v_7085 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_7085, v_7082);
    }
}



// Code for cgb_buch!-ev_divides!?

static LispObject CC_cgb_buchKev_dividesW(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7075, v_7076;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7076 = v_7065;
    v_7075 = v_7064;
// end of prologue
    goto v_7072;
v_7068:
    goto v_7069;
v_7070:
    goto v_7071;
v_7072:
    goto v_7068;
v_7069:
    goto v_7070;
v_7071:
    {
        fn = elt(env, 1); // ev_mtest!?
        return (*qfn2(fn))(fn, v_7076, v_7075);
    }
}



// Code for ev_tdeg

static LispObject CC_ev_tdeg(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7091, v_7092, v_7093;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7092 = v_7064;
// end of prologue
    v_7091 = (LispObject)0+TAG_FIXNUM; // 0
v_7072:
    v_7093 = v_7092;
    if (v_7093 == nil) goto v_7075;
    else goto v_7076;
v_7075:
    goto v_7071;
v_7076:
    goto v_7083;
v_7079:
    v_7093 = v_7092;
    v_7093 = qcar(v_7093);
    goto v_7080;
v_7081:
    goto v_7082;
v_7083:
    goto v_7079;
v_7080:
    goto v_7081;
v_7082:
    v_7091 = (LispObject)(intptr_t)((intptr_t)v_7093 + (intptr_t)v_7091 - TAG_FIXNUM);
    v_7092 = qcdr(v_7092);
    goto v_7072;
v_7071:
    return onevalue(v_7091);
}



// Code for vevlcm

static LispObject CC_vevlcm(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7139, v_7140, v_7141;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7065;
    stack[-1] = v_7064;
// end of prologue
    v_7141 = nil;
v_7072:
    v_7139 = stack[-1];
    if (v_7139 == nil) goto v_7075;
    v_7139 = stack[0];
    if (v_7139 == nil) goto v_7075;
    goto v_7076;
v_7075:
    goto v_7071;
v_7076:
    goto v_7087;
v_7083:
    goto v_7096;
v_7092:
    v_7139 = stack[-1];
    v_7140 = qcar(v_7139);
    goto v_7093;
v_7094:
    v_7139 = stack[0];
    v_7139 = qcar(v_7139);
    goto v_7095;
v_7096:
    goto v_7092;
v_7093:
    goto v_7094;
v_7095:
    if (((intptr_t)(v_7140)) > ((intptr_t)(v_7139))) goto v_7090;
    else goto v_7091;
v_7090:
    v_7139 = stack[-1];
    v_7139 = qcar(v_7139);
    goto v_7089;
v_7091:
    v_7139 = stack[0];
    v_7139 = qcar(v_7139);
    goto v_7089;
    v_7139 = nil;
v_7089:
    goto v_7084;
v_7085:
    v_7140 = v_7141;
    goto v_7086;
v_7087:
    goto v_7083;
v_7084:
    goto v_7085;
v_7086:
    v_7139 = cons(v_7139, v_7140);
    env = stack[-2];
    v_7141 = v_7139;
    v_7139 = stack[-1];
    v_7139 = qcdr(v_7139);
    stack[-1] = v_7139;
    v_7139 = stack[0];
    v_7139 = qcdr(v_7139);
    stack[0] = v_7139;
    goto v_7072;
v_7071:
    v_7139 = v_7141;
    v_7139 = Lnreverse(nil, v_7139);
    env = stack[-2];
    v_7141 = v_7139;
    v_7139 = stack[-1];
    if (v_7139 == nil) goto v_7117;
    goto v_7124;
v_7120:
    v_7140 = v_7141;
    goto v_7121;
v_7122:
    v_7139 = stack[-1];
    goto v_7123;
v_7124:
    goto v_7120;
v_7121:
    goto v_7122;
v_7123:
    v_7139 = Lnconc(nil, v_7140, v_7139);
    v_7141 = v_7139;
    goto v_7115;
v_7117:
    v_7139 = stack[0];
    if (v_7139 == nil) goto v_7128;
    goto v_7135;
v_7131:
    v_7140 = v_7141;
    goto v_7132;
v_7133:
    v_7139 = stack[0];
    goto v_7134;
v_7135:
    goto v_7131;
v_7132:
    goto v_7133;
v_7134:
    v_7139 = Lnconc(nil, v_7140, v_7139);
    v_7141 = v_7139;
    goto v_7115;
v_7128:
v_7115:
    v_7139 = v_7141;
    return onevalue(v_7139);
}



// Code for listdiff

static LispObject CC_listdiff(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7093, v_7094;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_7065;
    v_7093 = v_7064;
// end of prologue
v_7069:
    v_7094 = stack[0];
    if (v_7094 == nil) goto v_7072;
    else goto v_7073;
v_7072:
    goto v_7068;
v_7073:
    v_7094 = v_7093;
    if (v_7094 == nil) goto v_7076;
    else goto v_7077;
v_7076:
    v_7093 = nil;
    goto v_7068;
v_7077:
    goto v_7087;
v_7083:
    v_7094 = stack[0];
    v_7094 = qcar(v_7094);
    goto v_7084;
v_7085:
    goto v_7086;
v_7087:
    goto v_7083;
v_7084:
    goto v_7085;
v_7086:
    v_7093 = Ldelete(nil, v_7094, v_7093);
    env = stack[-1];
    v_7094 = stack[0];
    v_7094 = qcdr(v_7094);
    stack[0] = v_7094;
    goto v_7069;
    v_7093 = nil;
v_7068:
    return onevalue(v_7093);
}



// Code for deletemult!*

static LispObject CC_deletemultH(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7118, v_7119, v_7120;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7064);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7064;
// end of prologue
    v_7118 = stack[0];
    if (v_7118 == nil) goto v_7071;
    else goto v_7072;
v_7071:
    v_7118 = stack[0];
    goto v_7068;
v_7072:
    v_7118 = stack[0];
    v_7118 = qcar(v_7118);
    v_7118 = ncons(v_7118);
    env = stack[-3];
    stack[-2] = v_7118;
    v_7118 = stack[0];
    v_7118 = qcdr(v_7118);
    stack[0] = v_7118;
    v_7118 = stack[0];
    stack[-1] = v_7118;
v_7083:
    v_7118 = stack[-1];
    if (v_7118 == nil) goto v_7087;
    else goto v_7088;
v_7087:
    goto v_7082;
v_7088:
    v_7118 = stack[-1];
    v_7118 = qcar(v_7118);
    v_7120 = v_7118;
    goto v_7102;
v_7098:
    v_7119 = v_7120;
    goto v_7099;
v_7100:
    v_7118 = stack[-2];
    goto v_7101;
v_7102:
    goto v_7098;
v_7099:
    goto v_7100;
v_7101:
    v_7118 = Lmember(nil, v_7119, v_7118);
    if (v_7118 == nil) goto v_7096;
    else goto v_7097;
v_7096:
    goto v_7111;
v_7107:
    stack[0] = stack[-2];
    goto v_7108;
v_7109:
    v_7118 = v_7120;
    v_7118 = ncons(v_7118);
    env = stack[-3];
    goto v_7110;
v_7111:
    goto v_7107;
v_7108:
    goto v_7109;
v_7110:
    v_7118 = Lnconc(nil, stack[0], v_7118);
    env = stack[-3];
    goto v_7095;
v_7097:
v_7095:
    v_7118 = stack[-1];
    v_7118 = qcdr(v_7118);
    stack[-1] = v_7118;
    goto v_7083;
v_7082:
    v_7118 = stack[-2];
v_7068:
    return onevalue(v_7118);
}



// Code for chknewnam

static LispObject CC_chknewnam(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7099, v_7100, v_7101, v_7102;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7101 = v_7064;
// end of prologue
v_7063:
    v_7099 = v_7101;
    if (!symbolp(v_7099)) v_7099 = nil;
    else { v_7099 = qfastgets(v_7099);
           if (v_7099 != nil) { v_7099 = elt(v_7099, 28); // newnam
#ifdef RECORD_GET
             if (v_7099 != SPID_NOPROP)
                record_get(elt(fastget_names, 28), 1);
             else record_get(elt(fastget_names, 28), 0),
                v_7099 = nil; }
           else record_get(elt(fastget_names, 28), 0); }
#else
             if (v_7099 == SPID_NOPROP) v_7099 = nil; }}
#endif
    v_7102 = v_7099;
    if (v_7099 == nil) goto v_7075;
    else goto v_7076;
v_7075:
    v_7099 = lisp_true;
    goto v_7074;
v_7076:
    goto v_7086;
v_7082:
    v_7100 = v_7102;
    goto v_7083;
v_7084:
    v_7099 = v_7101;
    goto v_7085;
v_7086:
    goto v_7082;
v_7083:
    goto v_7084;
v_7085:
    v_7099 = (v_7100 == v_7099 ? lisp_true : nil);
    goto v_7074;
    v_7099 = nil;
v_7074:
    if (v_7099 == nil) goto v_7072;
    v_7099 = v_7101;
    goto v_7070;
v_7072:
    v_7099 = v_7102;
    if (symbolp(v_7099)) goto v_7091;
    else goto v_7092;
v_7091:
    v_7099 = v_7102;
    v_7101 = v_7099;
    goto v_7063;
v_7092:
    v_7099 = v_7102;
    goto v_7070;
    v_7099 = nil;
v_7070:
    return onevalue(v_7099);
}



// Code for aminusp!:

static LispObject CC_aminuspT(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7124, v_7125;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7064);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_7064;
// end of prologue
    stack[-2] = nil;
    v_7124 = qvalue(elt(env, 1)); // !*modular
    if (v_7124 == nil) goto v_7073;
    goto v_7080;
v_7076:
    v_7125 = elt(env, 2); // modular
    goto v_7077;
v_7078:
    v_7124 = nil;
    goto v_7079;
v_7080:
    goto v_7076;
v_7077:
    goto v_7078;
v_7079:
    fn = elt(env, 5); // setdmode
    v_7124 = (*qfn2(fn))(fn, v_7125, v_7124);
    env = stack[-3];
    stack[-2] = v_7124;
    goto v_7071;
v_7073:
v_7071:
    goto v_7089;
v_7085:
    stack[0] = elt(env, 3); // aminusp!:1
    goto v_7086;
v_7087:
    v_7124 = stack[-1];
    v_7124 = Lmkquote(nil, v_7124);
    env = stack[-3];
    goto v_7088;
v_7089:
    goto v_7085;
v_7086:
    goto v_7087;
v_7088:
    v_7124 = list2(stack[0], v_7124);
    env = stack[-3];
    fn = elt(env, 6); // errorset2
    v_7124 = (*qfn1(fn))(fn, v_7124);
    env = stack[-3];
    stack[0] = v_7124;
    v_7124 = stack[-2];
    if (v_7124 == nil) goto v_7096;
    goto v_7103;
v_7099:
    v_7125 = elt(env, 2); // modular
    goto v_7100;
v_7101:
    v_7124 = lisp_true;
    goto v_7102;
v_7103:
    goto v_7099;
v_7100:
    goto v_7101;
v_7102:
    fn = elt(env, 5); // setdmode
    v_7124 = (*qfn2(fn))(fn, v_7125, v_7124);
    env = stack[-3];
    goto v_7094;
v_7096:
v_7094:
    v_7124 = stack[0];
    fn = elt(env, 7); // errorp
    v_7124 = (*qfn1(fn))(fn, v_7124);
    env = stack[-3];
    if (v_7124 == nil) goto v_7109;
    goto v_7117;
v_7113:
    v_7125 = stack[-1];
    goto v_7114;
v_7115:
    v_7124 = elt(env, 4); // "arithmetic expression"
    goto v_7116;
v_7117:
    goto v_7113;
v_7114:
    goto v_7115;
v_7116:
    fn = elt(env, 8); // typerr
    v_7124 = (*qfn2(fn))(fn, v_7125, v_7124);
    goto v_7107;
v_7109:
    v_7124 = stack[0];
    v_7124 = qcar(v_7124);
    goto v_7069;
v_7107:
    v_7124 = nil;
v_7069:
    return onevalue(v_7124);
}



// Code for pv_times3

static LispObject CC_pv_times3(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7093, v_7094;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7065;
    stack[-1] = v_7064;
// end of prologue
    goto v_7072;
v_7068:
    goto v_7078;
v_7074:
    v_7093 = stack[-1];
    v_7094 = qcar(v_7093);
    goto v_7075;
v_7076:
    v_7093 = stack[0];
    v_7093 = qcar(v_7093);
    goto v_7077;
v_7078:
    goto v_7074;
v_7075:
    goto v_7076;
v_7077:
    stack[-2] = times2(v_7094, v_7093);
    env = stack[-3];
    goto v_7069;
v_7070:
    goto v_7088;
v_7084:
    v_7093 = stack[-1];
    v_7094 = qcdr(v_7093);
    goto v_7085;
v_7086:
    v_7093 = stack[0];
    v_7093 = qcdr(v_7093);
    goto v_7087;
v_7088:
    goto v_7084;
v_7085:
    goto v_7086;
v_7087:
    fn = elt(env, 1); // pappend
    v_7093 = (*qfn2(fn))(fn, v_7094, v_7093);
    goto v_7071;
v_7072:
    goto v_7068;
v_7069:
    goto v_7070;
v_7071:
    {
        LispObject v_7098 = stack[-2];
        return cons(v_7098, v_7093);
    }
}



// Code for b!:ordexn

static LispObject CC_bTordexn(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7162, v_7163;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_7065;
    stack[-2] = v_7064;
// end of prologue
    stack[0] = nil;
    stack[-3] = nil;
v_7073:
    v_7162 = stack[-1];
    if (v_7162 == nil) goto v_7076;
    goto v_7086;
v_7082:
    v_7163 = stack[-2];
    goto v_7083;
v_7084:
    v_7162 = stack[-1];
    v_7162 = qcar(v_7162);
    goto v_7085;
v_7086:
    goto v_7082;
v_7083:
    goto v_7084;
v_7085:
    v_7162 = (LispObject)lessp2(v_7163, v_7162);
    v_7162 = v_7162 ? lisp_true : nil;
    env = stack[-4];
    if (v_7162 == nil) goto v_7076;
    goto v_7077;
v_7076:
    goto v_7072;
v_7077:
    goto v_7096;
v_7092:
    v_7162 = stack[-1];
    v_7163 = qcar(v_7162);
    goto v_7093;
v_7094:
    v_7162 = stack[-3];
    goto v_7095;
v_7096:
    goto v_7092;
v_7093:
    goto v_7094;
v_7095:
    v_7162 = cons(v_7163, v_7162);
    env = stack[-4];
    stack[-3] = v_7162;
    v_7162 = stack[-1];
    v_7162 = qcdr(v_7162);
    stack[-1] = v_7162;
    v_7162 = stack[0];
    v_7162 = (v_7162 == nil ? lisp_true : nil);
    stack[0] = v_7162;
    goto v_7073;
v_7072:
    v_7162 = stack[-1];
    if (v_7162 == nil) goto v_7106;
    else goto v_7107;
v_7106:
    goto v_7114;
v_7110:
    goto v_7111;
v_7112:
    goto v_7122;
v_7118:
    v_7163 = stack[-2];
    goto v_7119;
v_7120:
    v_7162 = stack[-3];
    goto v_7121;
v_7122:
    goto v_7118;
v_7119:
    goto v_7120;
v_7121:
    v_7162 = cons(v_7163, v_7162);
    env = stack[-4];
    v_7162 = Lnreverse(nil, v_7162);
    goto v_7113;
v_7114:
    goto v_7110;
v_7111:
    goto v_7112;
v_7113:
    {
        LispObject v_7168 = stack[0];
        return cons(v_7168, v_7162);
    }
v_7107:
    goto v_7134;
v_7130:
    v_7163 = stack[-2];
    goto v_7131;
v_7132:
    v_7162 = stack[-1];
    v_7162 = qcar(v_7162);
    goto v_7133;
v_7134:
    goto v_7130;
v_7131:
    goto v_7132;
v_7133:
    v_7162 = Leqn(nil, v_7163, v_7162);
    env = stack[-4];
    if (v_7162 == nil) goto v_7128;
    v_7162 = nil;
    goto v_7070;
v_7128:
    goto v_7144;
v_7140:
    goto v_7141;
v_7142:
    goto v_7151;
v_7147:
    goto v_7158;
v_7154:
    v_7163 = stack[-2];
    goto v_7155;
v_7156:
    v_7162 = stack[-3];
    goto v_7157;
v_7158:
    goto v_7154;
v_7155:
    goto v_7156;
v_7157:
    v_7162 = cons(v_7163, v_7162);
    env = stack[-4];
    v_7163 = Lnreverse(nil, v_7162);
    env = stack[-4];
    goto v_7148;
v_7149:
    v_7162 = stack[-1];
    goto v_7150;
v_7151:
    goto v_7147;
v_7148:
    goto v_7149;
v_7150:
    v_7162 = Lnconc(nil, v_7163, v_7162);
    goto v_7143;
v_7144:
    goto v_7140;
v_7141:
    goto v_7142;
v_7143:
    {
        LispObject v_7169 = stack[0];
        return cons(v_7169, v_7162);
    }
v_7070:
    return onevalue(v_7162);
}



// Code for cde_lassoc2

static LispObject CC_cde_lassoc2(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7099, v_7100, v_7101, v_7102;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7101 = v_7065;
    v_7102 = v_7064;
// end of prologue
v_7069:
    v_7099 = v_7101;
    if (v_7099 == nil) goto v_7072;
    else goto v_7073;
v_7072:
    v_7099 = nil;
    goto v_7068;
v_7073:
    v_7099 = v_7101;
    v_7099 = qcar(v_7099);
    if (!consp(v_7099)) goto v_7076;
    else goto v_7077;
v_7076:
    v_7099 = elt(env, 1); // "Error: bad alist"
    {
        fn = elt(env, 2); // rederr
        return (*qfn1(fn))(fn, v_7099);
    }
v_7077:
    goto v_7088;
v_7084:
    v_7100 = v_7102;
    goto v_7085;
v_7086:
    v_7099 = v_7101;
    v_7099 = qcar(v_7099);
    v_7099 = qcdr(v_7099);
    goto v_7087;
v_7088:
    goto v_7084;
v_7085:
    goto v_7086;
v_7087:
    if (equal(v_7100, v_7099)) goto v_7082;
    else goto v_7083;
v_7082:
    v_7099 = v_7101;
    v_7099 = qcar(v_7099);
    goto v_7068;
v_7083:
    v_7099 = v_7101;
    v_7099 = qcdr(v_7099);
    v_7101 = v_7099;
    goto v_7069;
    v_7099 = nil;
v_7068:
    return onevalue(v_7099);
}



// Code for idsort

static LispObject CC_idsort(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7074, v_7075;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7074 = v_7064;
// end of prologue
    goto v_7071;
v_7067:
    v_7075 = v_7074;
    goto v_7068;
v_7069:
    v_7074 = elt(env, 1); // idcompare
    goto v_7070;
v_7071:
    goto v_7067;
v_7068:
    goto v_7069;
v_7070:
    {
        fn = elt(env, 2); // sort
        return (*qfn2(fn))(fn, v_7075, v_7074);
    }
}



// Code for removeg1

static LispObject CC_removeg1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7482, v_7483, v_7484, v_7485;
    LispObject fn;
    LispObject v_7066, v_7065, v_7064;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "removeg1");
    va_start(aa, nargs);
    v_7064 = va_arg(aa, LispObject);
    v_7065 = va_arg(aa, LispObject);
    v_7066 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7066,v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7064,v_7065,v_7066);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_7066;
    stack[-4] = v_7065;
    stack[-5] = v_7064;
// end of prologue
    goto v_7079;
v_7075:
    v_7483 = stack[-5];
    goto v_7076;
v_7077:
    v_7482 = stack[-4];
    goto v_7078;
v_7079:
    goto v_7075;
v_7076:
    goto v_7077;
v_7078:
    fn = elt(env, 7); // removev
    v_7482 = (*qfn2(fn))(fn, v_7483, v_7482);
    env = stack[-7];
    goto v_7087;
v_7083:
    v_7483 = stack[-5];
    goto v_7084;
v_7085:
    v_7482 = stack[-3];
    goto v_7086;
v_7087:
    goto v_7083;
v_7084:
    goto v_7085;
v_7086:
    fn = elt(env, 7); // removev
    v_7482 = (*qfn2(fn))(fn, v_7483, v_7482);
    env = stack[-7];
    goto v_7102;
v_7098:
    v_7482 = stack[-4];
    v_7482 = qcdr(v_7482);
    v_7483 = qcar(v_7482);
    goto v_7099;
v_7100:
    v_7482 = stack[-3];
    v_7482 = qcdr(v_7482);
    v_7482 = qcdr(v_7482);
    v_7482 = qcar(v_7482);
    goto v_7101;
v_7102:
    goto v_7098;
v_7099:
    goto v_7100;
v_7101:
    if (v_7483 == v_7482) goto v_7096;
    else goto v_7097;
v_7096:
    goto v_7114;
v_7110:
    v_7482 = stack[-4];
    v_7482 = qcdr(v_7482);
    v_7482 = qcdr(v_7482);
    v_7483 = qcar(v_7482);
    goto v_7111;
v_7112:
    v_7482 = stack[-3];
    v_7482 = qcdr(v_7482);
    v_7482 = qcar(v_7482);
    goto v_7113;
v_7114:
    goto v_7110;
v_7111:
    goto v_7112;
v_7113:
    v_7482 = (v_7483 == v_7482 ? lisp_true : nil);
    goto v_7095;
v_7097:
    v_7482 = nil;
    goto v_7095;
    v_7482 = nil;
v_7095:
    if (v_7482 == nil) goto v_7093;
    goto v_7132;
v_7128:
    goto v_7138;
v_7134:
    v_7483 = qvalue(elt(env, 1)); // n!*!*2!-1
    goto v_7135;
v_7136:
    v_7482 = stack[-5];
    v_7482 = qcar(v_7482);
    goto v_7137;
v_7138:
    goto v_7134;
v_7135:
    goto v_7136;
v_7137:
    fn = elt(env, 8); // multsq
    v_7483 = (*qfn2(fn))(fn, v_7483, v_7482);
    env = stack[-7];
    goto v_7129;
v_7130:
    v_7482 = stack[-5];
    v_7482 = qcdr(v_7482);
    goto v_7131;
v_7132:
    goto v_7128;
v_7129:
    goto v_7130;
v_7131:
    v_7482 = cons(v_7483, v_7482);
    return ncons(v_7482);
v_7093:
    goto v_7149;
v_7145:
    v_7482 = stack[-5];
    v_7483 = qcdr(v_7482);
    goto v_7146;
v_7147:
    v_7482 = stack[-4];
    v_7482 = qcdr(v_7482);
    v_7482 = qcdr(v_7482);
    v_7482 = qcar(v_7482);
    goto v_7148;
v_7149:
    goto v_7145;
v_7146:
    goto v_7147;
v_7148:
    fn = elt(env, 9); // finde
    v_7482 = (*qfn2(fn))(fn, v_7483, v_7482);
    env = stack[-7];
    stack[-6] = v_7482;
    goto v_7164;
v_7160:
    v_7482 = stack[-4];
    v_7482 = qcdr(v_7482);
    v_7483 = qcar(v_7482);
    goto v_7161;
v_7162:
    v_7482 = stack[-3];
    v_7482 = qcdr(v_7482);
    v_7482 = qcdr(v_7482);
    v_7482 = qcar(v_7482);
    goto v_7163;
v_7164:
    goto v_7160;
v_7161:
    goto v_7162;
v_7163:
    if (v_7483 == v_7482) goto v_7158;
    else goto v_7159;
v_7158:
    v_7482 = stack[-6];
    if (v_7482 == nil) goto v_7175;
    goto v_7182;
v_7178:
    v_7482 = stack[-6];
    v_7482 = qcar(v_7482);
    v_7483 = qcdr(v_7482);
    goto v_7179;
v_7180:
    v_7482 = stack[-3];
    v_7482 = qcdr(v_7482);
    v_7482 = qcar(v_7482);
    goto v_7181;
v_7182:
    goto v_7178;
v_7179:
    goto v_7180;
v_7181:
    v_7482 = Lrplaca(nil, v_7483, v_7482);
    env = stack[-7];
    goto v_7173;
v_7175:
    goto v_7201;
v_7193:
    v_7485 = elt(env, 2); // "Free edge"
    goto v_7194;
v_7195:
    v_7482 = stack[-4];
    v_7482 = qcdr(v_7482);
    v_7482 = qcdr(v_7482);
    v_7484 = qcar(v_7482);
    goto v_7196;
v_7197:
    v_7483 = elt(env, 3); // "in vertex"
    goto v_7198;
v_7199:
    v_7482 = stack[-4];
    goto v_7200;
v_7201:
    goto v_7193;
v_7194:
    goto v_7195;
v_7196:
    goto v_7197;
v_7198:
    goto v_7199;
v_7200:
    v_7482 = list4(v_7485, v_7484, v_7483, v_7482);
    env = stack[-7];
    fn = elt(env, 10); // cerror
    v_7482 = (*qfn1(fn))(fn, v_7482);
    env = stack[-7];
    goto v_7173;
v_7173:
    goto v_7215;
v_7211:
    goto v_7221;
v_7217:
    goto v_7227;
v_7223:
    v_7483 = qvalue(elt(env, 1)); // n!*!*2!-1
    goto v_7224;
v_7225:
    v_7482 = qvalue(elt(env, 4)); // su_order
    goto v_7226;
v_7227:
    goto v_7223;
v_7224:
    goto v_7225;
v_7226:
    fn = elt(env, 11); // quotsq
    v_7483 = (*qfn2(fn))(fn, v_7483, v_7482);
    env = stack[-7];
    goto v_7218;
v_7219:
    v_7482 = stack[-5];
    v_7482 = qcar(v_7482);
    goto v_7220;
v_7221:
    goto v_7217;
v_7218:
    goto v_7219;
v_7220:
    fn = elt(env, 8); // multsq
    v_7483 = (*qfn2(fn))(fn, v_7483, v_7482);
    env = stack[-7];
    goto v_7212;
v_7213:
    v_7482 = stack[-5];
    v_7482 = qcdr(v_7482);
    goto v_7214;
v_7215:
    goto v_7211;
v_7212:
    goto v_7213;
v_7214:
    v_7482 = cons(v_7483, v_7482);
    return ncons(v_7482);
v_7159:
    goto v_7240;
v_7236:
    v_7482 = stack[-5];
    v_7483 = qcdr(v_7482);
    goto v_7237;
v_7238:
    v_7482 = stack[-3];
    v_7482 = qcdr(v_7482);
    v_7482 = qcdr(v_7482);
    v_7482 = qcar(v_7482);
    goto v_7239;
v_7240:
    goto v_7236;
v_7237:
    goto v_7238;
v_7239:
    fn = elt(env, 9); // finde
    v_7482 = (*qfn2(fn))(fn, v_7483, v_7482);
    env = stack[-7];
    stack[-2] = v_7482;
    goto v_7255;
v_7251:
    v_7482 = stack[-4];
    v_7482 = qcdr(v_7482);
    v_7482 = qcdr(v_7482);
    v_7483 = qcar(v_7482);
    goto v_7252;
v_7253:
    v_7482 = stack[-3];
    v_7482 = qcdr(v_7482);
    v_7482 = qcar(v_7482);
    goto v_7254;
v_7255:
    goto v_7251;
v_7252:
    goto v_7253;
v_7254:
    if (v_7483 == v_7482) goto v_7249;
    else goto v_7250;
v_7249:
    v_7482 = stack[-2];
    if (v_7482 == nil) goto v_7266;
    goto v_7273;
v_7269:
    v_7482 = stack[-2];
    v_7482 = qcar(v_7482);
    v_7483 = qcdr(v_7482);
    goto v_7270;
v_7271:
    v_7482 = stack[-4];
    v_7482 = qcdr(v_7482);
    v_7482 = qcar(v_7482);
    goto v_7272;
v_7273:
    goto v_7269;
v_7270:
    goto v_7271;
v_7272:
    v_7482 = Lrplaca(nil, v_7483, v_7482);
    env = stack[-7];
    goto v_7264;
v_7266:
    goto v_7292;
v_7284:
    v_7485 = elt(env, 2); // "Free edge"
    goto v_7285;
v_7286:
    v_7482 = stack[-3];
    v_7482 = qcdr(v_7482);
    v_7482 = qcdr(v_7482);
    v_7484 = qcar(v_7482);
    goto v_7287;
v_7288:
    v_7483 = elt(env, 3); // "in vertex"
    goto v_7289;
v_7290:
    v_7482 = stack[-3];
    goto v_7291;
v_7292:
    goto v_7284;
v_7285:
    goto v_7286;
v_7287:
    goto v_7288;
v_7289:
    goto v_7290;
v_7291:
    v_7482 = list4(v_7485, v_7484, v_7483, v_7482);
    env = stack[-7];
    fn = elt(env, 10); // cerror
    v_7482 = (*qfn1(fn))(fn, v_7482);
    env = stack[-7];
    goto v_7264;
v_7264:
    goto v_7306;
v_7302:
    goto v_7312;
v_7308:
    goto v_7318;
v_7314:
    v_7483 = qvalue(elt(env, 1)); // n!*!*2!-1
    goto v_7315;
v_7316:
    v_7482 = qvalue(elt(env, 4)); // su_order
    goto v_7317;
v_7318:
    goto v_7314;
v_7315:
    goto v_7316;
v_7317:
    fn = elt(env, 11); // quotsq
    v_7483 = (*qfn2(fn))(fn, v_7483, v_7482);
    env = stack[-7];
    goto v_7309;
v_7310:
    v_7482 = stack[-5];
    v_7482 = qcar(v_7482);
    goto v_7311;
v_7312:
    goto v_7308;
v_7309:
    goto v_7310;
v_7311:
    fn = elt(env, 8); // multsq
    v_7483 = (*qfn2(fn))(fn, v_7483, v_7482);
    env = stack[-7];
    goto v_7303;
v_7304:
    v_7482 = stack[-5];
    v_7482 = qcdr(v_7482);
    goto v_7305;
v_7306:
    goto v_7302;
v_7303:
    goto v_7304;
v_7305:
    v_7482 = cons(v_7483, v_7482);
    return ncons(v_7482);
v_7250:
    v_7482 = stack[-6];
    if (v_7482 == nil) goto v_7332;
    else goto v_7333;
v_7332:
    v_7482 = lisp_true;
    goto v_7331;
v_7333:
    v_7482 = stack[-2];
    v_7482 = (v_7482 == nil ? lisp_true : nil);
    goto v_7331;
    v_7482 = nil;
v_7331:
    if (v_7482 == nil) goto v_7329;
    goto v_7346;
v_7342:
    stack[0] = elt(env, 5); // "Invalid structure of c-graph"
    goto v_7343;
v_7344:
    v_7482 = stack[-5];
    if (v_7482 == nil) goto v_7350;
    else goto v_7351;
v_7350:
    v_7482 = nil;
    goto v_7349;
v_7351:
    v_7482 = stack[-5];
    v_7482 = qcdr(v_7482);
    if (v_7482 == nil) goto v_7354;
    else goto v_7355;
v_7354:
    v_7482 = stack[-5];
    v_7482 = qcar(v_7482);
    goto v_7349;
v_7355:
    goto v_7367;
v_7363:
    v_7483 = elt(env, 6); // times
    goto v_7364;
v_7365:
    v_7482 = stack[-5];
    goto v_7366;
v_7367:
    goto v_7363;
v_7364:
    goto v_7365;
v_7366:
    v_7482 = cons(v_7483, v_7482);
    env = stack[-7];
    goto v_7349;
    v_7482 = nil;
v_7349:
    goto v_7345;
v_7346:
    goto v_7342;
v_7343:
    goto v_7344;
v_7345:
    v_7482 = list2(stack[0], v_7482);
    env = stack[-7];
    fn = elt(env, 10); // cerror
    v_7482 = (*qfn1(fn))(fn, v_7482);
    env = stack[-7];
    goto v_7327;
v_7329:
v_7327:
    v_7482 = stack[-6];
    v_7482 = qcar(v_7482);
    stack[-6] = v_7482;
    v_7482 = stack[-2];
    v_7482 = qcar(v_7482);
    stack[-2] = v_7482;
    goto v_7379;
v_7375:
    v_7482 = stack[-6];
    v_7483 = qcdr(v_7482);
    goto v_7376;
v_7377:
    v_7482 = stack[-3];
    v_7482 = qcdr(v_7482);
    v_7482 = qcar(v_7482);
    goto v_7378;
v_7379:
    goto v_7375;
v_7376:
    goto v_7377;
v_7378:
    v_7482 = Lrplaca(nil, v_7483, v_7482);
    env = stack[-7];
    goto v_7390;
v_7386:
    v_7482 = stack[-2];
    v_7483 = qcdr(v_7482);
    goto v_7387;
v_7388:
    v_7482 = stack[-4];
    v_7482 = qcdr(v_7482);
    v_7482 = qcar(v_7482);
    goto v_7389;
v_7390:
    goto v_7386;
v_7387:
    goto v_7388;
v_7389:
    v_7482 = Lrplaca(nil, v_7483, v_7482);
    env = stack[-7];
    goto v_7401;
v_7397:
    v_7482 = stack[-5];
    stack[0] = qcar(v_7482);
    goto v_7398;
v_7399:
    v_7482 = stack[-5];
    v_7482 = qcdr(v_7482);
    fn = elt(env, 12); // mkcopy
    v_7482 = (*qfn1(fn))(fn, v_7482);
    env = stack[-7];
    goto v_7400;
v_7401:
    goto v_7397;
v_7398:
    goto v_7399;
v_7400:
    v_7482 = cons(stack[0], v_7482);
    env = stack[-7];
    stack[-1] = v_7482;
    v_7482 = stack[-1];
    v_7482 = qcdr(v_7482);
    stack[0] = v_7482;
    goto v_7413;
v_7409:
    v_7483 = stack[-6];
    goto v_7410;
v_7411:
    v_7482 = stack[0];
    goto v_7412;
v_7413:
    goto v_7409;
v_7410:
    goto v_7411;
v_7412:
    v_7482 = Lmember(nil, v_7483, v_7482);
    v_7482 = qcar(v_7482);
    stack[-6] = v_7482;
    goto v_7422;
v_7418:
    v_7483 = stack[-2];
    goto v_7419;
v_7420:
    v_7482 = stack[0];
    goto v_7421;
v_7422:
    goto v_7418;
v_7419:
    goto v_7420;
v_7421:
    v_7482 = Lmember(nil, v_7483, v_7482);
    v_7482 = qcar(v_7482);
    stack[-2] = v_7482;
    goto v_7432;
v_7428:
    v_7482 = stack[-6];
    v_7483 = qcdr(v_7482);
    goto v_7429;
v_7430:
    v_7482 = stack[-4];
    v_7482 = qcdr(v_7482);
    v_7482 = qcar(v_7482);
    goto v_7431;
v_7432:
    goto v_7428;
v_7429:
    goto v_7430;
v_7431:
    v_7482 = Lrplaca(nil, v_7483, v_7482);
    env = stack[-7];
    goto v_7443;
v_7439:
    v_7482 = stack[-2];
    v_7483 = qcdr(v_7482);
    goto v_7440;
v_7441:
    v_7482 = stack[-3];
    v_7482 = qcdr(v_7482);
    v_7482 = qcar(v_7482);
    goto v_7442;
v_7443:
    goto v_7439;
v_7440:
    goto v_7441;
v_7442:
    v_7482 = Lrplaca(nil, v_7483, v_7482);
    env = stack[-7];
    goto v_7456;
v_7450:
    stack[-2] = stack[-5];
    goto v_7451;
v_7452:
    goto v_7463;
v_7459:
    goto v_7469;
v_7465:
    goto v_7475;
v_7471:
    v_7483 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_7472;
v_7473:
    v_7482 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7474;
v_7475:
    goto v_7471;
v_7472:
    goto v_7473;
v_7474:
    v_7483 = cons(v_7483, v_7482);
    env = stack[-7];
    goto v_7466;
v_7467:
    v_7482 = qvalue(elt(env, 4)); // su_order
    goto v_7468;
v_7469:
    goto v_7465;
v_7466:
    goto v_7467;
v_7468:
    fn = elt(env, 11); // quotsq
    v_7483 = (*qfn2(fn))(fn, v_7483, v_7482);
    env = stack[-7];
    goto v_7460;
v_7461:
    v_7482 = stack[-1];
    v_7482 = qcar(v_7482);
    goto v_7462;
v_7463:
    goto v_7459;
v_7460:
    goto v_7461;
v_7462:
    fn = elt(env, 8); // multsq
    v_7483 = (*qfn2(fn))(fn, v_7483, v_7482);
    goto v_7453;
v_7454:
    v_7482 = stack[0];
    goto v_7455;
v_7456:
    goto v_7450;
v_7451:
    goto v_7452;
v_7453:
    goto v_7454;
v_7455:
    {
        LispObject v_7493 = stack[-2];
        return list2star(v_7493, v_7483, v_7482);
    }
    return onevalue(v_7482);
}



// Code for talp_simplatrinv

static LispObject CC_talp_simplatrinv(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7170, v_7171, v_7172;
    LispObject fn;
    LispObject v_7066, v_7065, v_7064;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_simplatrinv");
    va_start(aa, nargs);
    v_7064 = va_arg(aa, LispObject);
    v_7065 = va_arg(aa, LispObject);
    v_7066 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7066,v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7064,v_7065,v_7066);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7066;
    stack[-1] = v_7065;
    stack[-2] = v_7064;
// end of prologue
    v_7170 = stack[0];
    fn = elt(env, 2); // talp_simplt
    v_7170 = (*qfn1(fn))(fn, v_7170);
    env = stack[-3];
    stack[0] = v_7170;
    v_7170 = stack[0];
    fn = elt(env, 3); // talp_invp
    v_7170 = (*qfn1(fn))(fn, v_7170);
    env = stack[-3];
    if (v_7170 == nil) goto v_7073;
    v_7170 = stack[-1];
    fn = elt(env, 3); // talp_invp
    v_7170 = (*qfn1(fn))(fn, v_7170);
    env = stack[-3];
    if (v_7170 == nil) goto v_7079;
    v_7170 = stack[-1];
    fn = elt(env, 2); // talp_simplt
    v_7170 = (*qfn1(fn))(fn, v_7170);
    env = stack[-3];
    stack[-1] = v_7170;
    v_7170 = stack[-1];
    fn = elt(env, 3); // talp_invp
    v_7170 = (*qfn1(fn))(fn, v_7170);
    env = stack[-3];
    if (v_7170 == nil) goto v_7087;
    goto v_7099;
v_7095:
    v_7171 = stack[-1];
    goto v_7096;
v_7097:
    v_7170 = stack[0];
    goto v_7098;
v_7099:
    goto v_7095;
v_7096:
    goto v_7097;
v_7098:
    fn = elt(env, 4); // talp_eqtp
    v_7170 = (*qfn2(fn))(fn, v_7171, v_7170);
    env = stack[-3];
    if (v_7170 == nil) goto v_7093;
    goto v_7110;
v_7106:
    v_7170 = stack[-2];
    goto v_7107;
v_7108:
    v_7171 = elt(env, 1); // equal
    goto v_7109;
v_7110:
    goto v_7106;
v_7107:
    goto v_7108;
v_7109:
    if (v_7170 == v_7171) goto v_7104;
    else goto v_7105;
v_7104:
    v_7170 = lisp_true;
    goto v_7103;
v_7105:
    v_7170 = nil;
    goto v_7103;
    v_7170 = nil;
v_7103:
    goto v_7091;
v_7093:
    goto v_7126;
v_7120:
    v_7172 = stack[-2];
    goto v_7121;
v_7122:
    v_7171 = stack[-1];
    goto v_7123;
v_7124:
    v_7170 = stack[0];
    goto v_7125;
v_7126:
    goto v_7120;
v_7121:
    goto v_7122;
v_7123:
    goto v_7124;
v_7125:
    {
        fn = elt(env, 5); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_7172, v_7171, v_7170);
    }
    v_7170 = nil;
v_7091:
    goto v_7085;
v_7087:
    goto v_7139;
v_7133:
    v_7172 = stack[-2];
    goto v_7134;
v_7135:
    v_7171 = stack[-1];
    goto v_7136;
v_7137:
    v_7170 = stack[0];
    goto v_7138;
v_7139:
    goto v_7133;
v_7134:
    goto v_7135;
v_7136:
    goto v_7137;
v_7138:
    {
        fn = elt(env, 6); // talp_simplat2
        return (*qfnn(fn))(fn, 3, v_7172, v_7171, v_7170);
    }
    v_7170 = nil;
v_7085:
    goto v_7077;
v_7079:
    goto v_7152;
v_7146:
    goto v_7147;
v_7148:
    v_7170 = stack[-1];
    fn = elt(env, 2); // talp_simplt
    v_7171 = (*qfn1(fn))(fn, v_7170);
    env = stack[-3];
    goto v_7149;
v_7150:
    v_7170 = stack[0];
    goto v_7151;
v_7152:
    goto v_7146;
v_7147:
    goto v_7148;
v_7149:
    goto v_7150;
v_7151:
    {
        LispObject v_7176 = stack[-2];
        fn = elt(env, 5); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_7176, v_7171, v_7170);
    }
    v_7170 = nil;
v_7077:
    goto v_7071;
v_7073:
    goto v_7166;
v_7160:
    v_7172 = stack[-2];
    goto v_7161;
v_7162:
    v_7171 = stack[-1];
    goto v_7163;
v_7164:
    v_7170 = stack[0];
    goto v_7165;
v_7166:
    goto v_7160;
v_7161:
    goto v_7162;
v_7163:
    goto v_7164;
v_7165:
    {
        fn = elt(env, 6); // talp_simplat2
        return (*qfnn(fn))(fn, 3, v_7172, v_7171, v_7170);
    }
    v_7170 = nil;
v_7071:
    return onevalue(v_7170);
}



// Code for terpri!*

static LispObject CC_terpriH(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7142, v_7143, v_7144;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7064);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7064;
// end of prologue
    v_7142 = qvalue(elt(env, 1)); // outputhandler!*
    if (v_7142 == nil) goto v_7073;
    goto v_7082;
v_7076:
    v_7143 = qvalue(elt(env, 1)); // outputhandler!*
    goto v_7077;
v_7078:
    v_7144 = elt(env, 2); // terpri
    goto v_7079;
v_7080:
    v_7142 = stack[0];
    goto v_7081;
v_7082:
    goto v_7076;
v_7077:
    goto v_7078;
v_7079:
    goto v_7080;
v_7081:
        return Lapply2(nil, 3, v_7143, v_7144, v_7142);
v_7073:
    v_7142 = qvalue(elt(env, 3)); // testing!-width!*
    if (v_7142 == nil) goto v_7087;
    v_7142 = lisp_true;
    qvalue(elt(env, 4)) = v_7142; // overflowed!*
    goto v_7068;
v_7087:
    v_7142 = qvalue(elt(env, 5)); // !*fort
    if (v_7142 == nil) goto v_7091;
    v_7142 = stack[0];
    {
        fn = elt(env, 13); // fterpri
        return (*qfn1(fn))(fn, v_7142);
    }
v_7091:
    v_7142 = qvalue(elt(env, 6)); // !*nat
    if (v_7142 == nil) goto v_7096;
    v_7142 = qvalue(elt(env, 7)); // pline!*
    if (v_7142 == nil) goto v_7096;
    v_7142 = qvalue(elt(env, 7)); // pline!*
    v_7142 = Lreverse(nil, v_7142);
    env = stack[-2];
    qvalue(elt(env, 7)) = v_7142; // pline!*
    v_7142 = qvalue(elt(env, 8)); // ymax!*
    stack[-1] = v_7142;
v_7106:
    goto v_7118;
v_7114:
    v_7143 = stack[-1];
    goto v_7115;
v_7116:
    v_7142 = qvalue(elt(env, 9)); // ymin!*
    goto v_7117;
v_7118:
    goto v_7114;
v_7115:
    goto v_7116;
v_7117:
    v_7142 = difference2(v_7143, v_7142);
    env = stack[-2];
    v_7142 = Lminusp(nil, v_7142);
    env = stack[-2];
    if (v_7142 == nil) goto v_7111;
    goto v_7105;
v_7111:
    goto v_7127;
v_7123:
    v_7143 = qvalue(elt(env, 7)); // pline!*
    goto v_7124;
v_7125:
    v_7142 = stack[-1];
    goto v_7126;
v_7127:
    goto v_7123;
v_7124:
    goto v_7125;
v_7126:
    fn = elt(env, 14); // scprint
    v_7142 = (*qfn2(fn))(fn, v_7143, v_7142);
    env = stack[-2];
    v_7142 = Lterpri(nil, 0);
    env = stack[-2];
    v_7142 = stack[-1];
    v_7142 = sub1(v_7142);
    env = stack[-2];
    stack[-1] = v_7142;
    goto v_7106;
v_7105:
    v_7142 = nil;
    qvalue(elt(env, 7)) = v_7142; // pline!*
    goto v_7071;
v_7096:
v_7071:
    v_7142 = stack[0];
    if (v_7142 == nil) goto v_7137;
    v_7142 = Lterpri(nil, 0);
    env = stack[-2];
    goto v_7135;
v_7137:
v_7135:
    v_7142 = qvalue(elt(env, 10)); // orig!*
    qvalue(elt(env, 11)) = v_7142; // posn!*
    v_7142 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 9)) = v_7142; // ymin!*
    qvalue(elt(env, 8)) = v_7142; // ymax!*
    qvalue(elt(env, 12)) = v_7142; // ycoord!*
    v_7142 = nil;
v_7068:
    return onevalue(v_7142);
}



// Code for rd!:minus

static LispObject CC_rdTminus(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7086, v_7087;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7064);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7087 = v_7064;
// end of prologue
    v_7086 = v_7087;
    v_7086 = qcdr(v_7086);
    if (!consp(v_7086)) goto v_7068;
    else goto v_7069;
v_7068:
    goto v_7077;
v_7073:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_7074;
v_7075:
    v_7086 = v_7087;
    v_7086 = qcdr(v_7086);
    fn = elt(env, 2); // safe!-fp!-minus
    v_7086 = (*qfn1(fn))(fn, v_7086);
    goto v_7076;
v_7077:
    goto v_7073;
v_7074:
    goto v_7075;
v_7076:
    {
        LispObject v_7089 = stack[0];
        return cons(v_7089, v_7086);
    }
v_7069:
    v_7086 = v_7087;
    {
        fn = elt(env, 3); // minus!:
        return (*qfn1(fn))(fn, v_7086);
    }
    v_7086 = nil;
    return onevalue(v_7086);
}



// Code for groebcpcompless!?

static LispObject CC_groebcpcomplessW(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7178, v_7179, v_7180;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_7065;
    stack[-2] = v_7064;
// end of prologue
    v_7178 = qvalue(elt(env, 1)); // !*gsugar
    if (v_7178 == nil) goto v_7070;
    goto v_7077;
v_7073:
    v_7178 = stack[-2];
    v_7178 = qcdr(v_7178);
    v_7178 = qcdr(v_7178);
    v_7178 = qcdr(v_7178);
    v_7179 = qcar(v_7178);
    goto v_7074;
v_7075:
    v_7178 = stack[-1];
    v_7178 = qcdr(v_7178);
    v_7178 = qcdr(v_7178);
    v_7178 = qcdr(v_7178);
    v_7178 = qcar(v_7178);
    goto v_7076;
v_7077:
    goto v_7073;
v_7074:
    goto v_7075;
v_7076:
    stack[-3] = difference2(v_7179, v_7178);
    env = stack[-4];
    goto v_7093;
v_7089:
    v_7178 = stack[-2];
    v_7179 = qcar(v_7178);
    goto v_7090;
v_7091:
    v_7178 = stack[-1];
    v_7178 = qcar(v_7178);
    goto v_7092;
v_7093:
    goto v_7089;
v_7090:
    goto v_7091;
v_7092:
    fn = elt(env, 4); // vevcomp
    v_7178 = (*qfn2(fn))(fn, v_7179, v_7178);
    env = stack[-4];
// Binding d
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 2, 0);
    qvalue(elt(env, 2)) = stack[-3]; // d
    v_7180 = v_7178;
    goto v_7108;
v_7104:
    v_7179 = qvalue(elt(env, 2)); // d
    goto v_7105;
v_7106:
    v_7178 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7107;
v_7108:
    goto v_7104;
v_7105:
    goto v_7106;
v_7107:
    if (v_7179 == v_7178) goto v_7103;
    goto v_7116;
v_7112:
    v_7179 = qvalue(elt(env, 2)); // d
    goto v_7113;
v_7114:
    v_7178 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7115;
v_7116:
    goto v_7112;
v_7113:
    goto v_7114;
v_7115:
    v_7178 = (LispObject)lessp2(v_7179, v_7178);
    v_7178 = v_7178 ? lisp_true : nil;
    goto v_7101;
v_7103:
    goto v_7125;
v_7121:
    v_7179 = v_7180;
    goto v_7122;
v_7123:
    v_7178 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7124;
v_7125:
    goto v_7121;
v_7122:
    goto v_7123;
v_7124:
    if (v_7179 == v_7178) goto v_7120;
    goto v_7133;
v_7129:
    v_7179 = v_7180;
    goto v_7130;
v_7131:
    v_7178 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7132;
v_7133:
    goto v_7129;
v_7130:
    goto v_7131;
v_7132:
    v_7178 = (LispObject)lessp2(v_7179, v_7178);
    v_7178 = v_7178 ? lisp_true : nil;
    goto v_7101;
v_7120:
    goto v_7143;
v_7139:
    goto v_7149;
v_7145:
    v_7178 = stack[-2];
    v_7178 = qcdr(v_7178);
    v_7178 = qcdr(v_7178);
    v_7179 = qcar(v_7178);
    goto v_7146;
v_7147:
    v_7178 = elt(env, 3); // number
    goto v_7148;
v_7149:
    goto v_7145;
v_7146:
    goto v_7147;
v_7148:
    fn = elt(env, 5); // vdpgetprop
    stack[-2] = (*qfn2(fn))(fn, v_7179, v_7178);
    env = stack[-4];
    goto v_7140;
v_7141:
    goto v_7160;
v_7156:
    v_7178 = stack[-1];
    v_7178 = qcdr(v_7178);
    v_7178 = qcdr(v_7178);
    v_7179 = qcar(v_7178);
    goto v_7157;
v_7158:
    v_7178 = elt(env, 3); // number
    goto v_7159;
v_7160:
    goto v_7156;
v_7157:
    goto v_7158;
v_7159:
    fn = elt(env, 5); // vdpgetprop
    v_7178 = (*qfn2(fn))(fn, v_7179, v_7178);
    env = stack[-4];
    goto v_7142;
v_7143:
    goto v_7139;
v_7140:
    goto v_7141;
v_7142:
    v_7178 = (LispObject)lessp2(stack[-2], v_7178);
    v_7178 = v_7178 ? lisp_true : nil;
    goto v_7101;
    v_7178 = nil;
v_7101:
    ;}  // end of a binding scope
    goto v_7068;
v_7070:
    goto v_7173;
v_7169:
    v_7178 = stack[-2];
    v_7179 = qcar(v_7178);
    goto v_7170;
v_7171:
    v_7178 = stack[-1];
    v_7178 = qcar(v_7178);
    goto v_7172;
v_7173:
    goto v_7169;
v_7170:
    goto v_7171;
v_7172:
    {
        fn = elt(env, 6); // vevcompless!?
        return (*qfn2(fn))(fn, v_7179, v_7178);
    }
    v_7178 = nil;
v_7068:
    return onevalue(v_7178);
}



// Code for wedget2

static LispObject CC_wedget2(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7160, v_7161, v_7162;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7065;
    stack[-1] = v_7064;
// end of prologue
    goto v_7075;
v_7071:
    v_7160 = stack[-1];
    v_7161 = qcar(v_7160);
    goto v_7072;
v_7073:
    v_7160 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7074;
v_7075:
    goto v_7071;
v_7072:
    goto v_7073;
v_7074:
    if (v_7161 == v_7160) goto v_7069;
    else goto v_7070;
v_7069:
    goto v_7085;
v_7081:
    v_7160 = stack[0];
    stack[-2] = qcar(v_7160);
    goto v_7082;
v_7083:
    goto v_7093;
v_7089:
    v_7160 = stack[-1];
    v_7161 = qcdr(v_7160);
    goto v_7090;
v_7091:
    v_7160 = stack[0];
    v_7160 = qcdr(v_7160);
    goto v_7092;
v_7093:
    goto v_7089;
v_7090:
    goto v_7091;
v_7092:
    fn = elt(env, 1); // multsq
    v_7160 = (*qfn2(fn))(fn, v_7161, v_7160);
    env = stack[-3];
    goto v_7084;
v_7085:
    goto v_7081;
v_7082:
    goto v_7083;
v_7084:
    v_7160 = cons(stack[-2], v_7160);
    return ncons(v_7160);
v_7070:
    goto v_7104;
v_7100:
    v_7160 = stack[0];
    v_7160 = qcar(v_7160);
    v_7161 = qcar(v_7160);
    goto v_7101;
v_7102:
    v_7160 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7103;
v_7104:
    goto v_7100;
v_7101:
    goto v_7102;
v_7103:
    if (v_7161 == v_7160) goto v_7098;
    else goto v_7099;
v_7098:
    goto v_7115;
v_7111:
    v_7160 = stack[-1];
    v_7160 = qcar(v_7160);
    stack[-2] = ncons(v_7160);
    env = stack[-3];
    goto v_7112;
v_7113:
    goto v_7124;
v_7120:
    v_7160 = stack[-1];
    v_7161 = qcdr(v_7160);
    goto v_7121;
v_7122:
    v_7160 = stack[0];
    v_7160 = qcdr(v_7160);
    goto v_7123;
v_7124:
    goto v_7120;
v_7121:
    goto v_7122;
v_7123:
    fn = elt(env, 1); // multsq
    v_7160 = (*qfn2(fn))(fn, v_7161, v_7160);
    env = stack[-3];
    goto v_7114;
v_7115:
    goto v_7111;
v_7112:
    goto v_7113;
v_7114:
    v_7160 = cons(stack[-2], v_7160);
    return ncons(v_7160);
v_7099:
    goto v_7136;
v_7132:
    goto v_7144;
v_7138:
    v_7160 = stack[-1];
    v_7162 = qcar(v_7160);
    goto v_7139;
v_7140:
    v_7160 = stack[0];
    v_7161 = qcar(v_7160);
    goto v_7141;
v_7142:
    v_7160 = nil;
    goto v_7143;
v_7144:
    goto v_7138;
v_7139:
    goto v_7140;
v_7141:
    goto v_7142;
v_7143:
    fn = elt(env, 2); // wedgek2
    stack[-2] = (*qfnn(fn))(fn, 3, v_7162, v_7161, v_7160);
    env = stack[-3];
    goto v_7133;
v_7134:
    goto v_7155;
v_7151:
    v_7160 = stack[-1];
    v_7161 = qcdr(v_7160);
    goto v_7152;
v_7153:
    v_7160 = stack[0];
    v_7160 = qcdr(v_7160);
    goto v_7154;
v_7155:
    goto v_7151;
v_7152:
    goto v_7153;
v_7154:
    fn = elt(env, 1); // multsq
    v_7160 = (*qfn2(fn))(fn, v_7161, v_7160);
    env = stack[-3];
    goto v_7135;
v_7136:
    goto v_7132;
v_7133:
    goto v_7134;
v_7135:
    {
        LispObject v_7166 = stack[-2];
        fn = elt(env, 3); // multpfsq
        return (*qfn2(fn))(fn, v_7166, v_7160);
    }
    v_7160 = nil;
    return onevalue(v_7160);
}



// Code for form

static LispObject CC_form(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7190, v_7191, v_7192;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7064);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7191 = v_7064;
// end of prologue
    v_7190 = v_7191;
    if (!consp(v_7190)) goto v_7073;
    goto v_7080;
v_7076:
    v_7190 = v_7191;
    v_7192 = qcar(v_7190);
    goto v_7077;
v_7078:
    v_7190 = elt(env, 1); // always_nform
    goto v_7079;
v_7080:
    goto v_7076;
v_7077:
    goto v_7078;
v_7079:
    v_7190 = Lflagp(nil, v_7192, v_7190);
    env = stack[0];
    goto v_7071;
v_7073:
    v_7190 = nil;
    goto v_7071;
    v_7190 = nil;
v_7071:
    if (v_7190 == nil) goto v_7069;
    v_7190 = v_7191;
    {
        fn = elt(env, 9); // n_form
        return (*qfn1(fn))(fn, v_7190);
    }
v_7069:
    v_7190 = qvalue(elt(env, 2)); // !*rlisp88
    if (v_7190 == nil) goto v_7089;
    else goto v_7090;
v_7089:
    goto v_7099;
v_7093:
    v_7192 = v_7191;
    goto v_7094;
v_7095:
    v_7191 = qvalue(elt(env, 3)); // !*vars!*
    goto v_7096;
v_7097:
    v_7190 = qvalue(elt(env, 4)); // !*mode
    goto v_7098;
v_7099:
    goto v_7093;
v_7094:
    goto v_7095;
v_7096:
    goto v_7097;
v_7098:
    {
        fn = elt(env, 10); // form1
        return (*qfnn(fn))(fn, 3, v_7192, v_7191, v_7190);
    }
v_7090:
    goto v_7113;
v_7109:
    v_7192 = qvalue(elt(env, 4)); // !*mode
    goto v_7110;
v_7111:
    v_7190 = elt(env, 5); // symbolic
    goto v_7112;
v_7113:
    goto v_7109;
v_7110:
    goto v_7111;
v_7112:
    if (v_7192 == v_7190) goto v_7108;
    v_7190 = lisp_true;
    goto v_7106;
v_7108:
    v_7190 = v_7191;
    if (!symbolp(v_7190)) v_7190 = nil;
    else { v_7190 = qfastgets(v_7190);
           if (v_7190 != nil) { v_7190 = elt(v_7190, 48); // modefn
#ifdef RECORD_GET
             if (v_7190 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v_7190 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v_7190 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v_7190 == SPID_NOPROP) v_7190 = nil; else v_7190 = lisp_true; }}
#endif
    if (v_7190 == nil) goto v_7126;
    goto v_7133;
v_7129:
    v_7192 = v_7191;
    goto v_7130;
v_7131:
    v_7190 = elt(env, 5); // symbolic
    goto v_7132;
v_7133:
    goto v_7129;
v_7130:
    goto v_7131;
v_7132:
    v_7190 = (v_7192 == v_7190 ? lisp_true : nil);
    v_7190 = (v_7190 == nil ? lisp_true : nil);
    goto v_7124;
v_7126:
    v_7190 = nil;
    goto v_7124;
    v_7190 = nil;
v_7124:
    if (v_7190 == nil) goto v_7122;
    v_7190 = lisp_true;
    goto v_7120;
v_7122:
    goto v_7153;
v_7149:
    v_7192 = v_7191;
    goto v_7150;
v_7151:
    v_7190 = elt(env, 6); // modefn
    goto v_7152;
v_7153:
    goto v_7149;
v_7150:
    goto v_7151;
v_7152:
    v_7190 = Lflagpcar(nil, v_7192, v_7190);
    env = stack[0];
    if (v_7190 == nil) goto v_7146;
    else goto v_7147;
v_7146:
    v_7190 = nil;
    goto v_7145;
v_7147:
    goto v_7163;
v_7159:
    v_7190 = v_7191;
    v_7192 = qcar(v_7190);
    goto v_7160;
v_7161:
    v_7190 = elt(env, 5); // symbolic
    goto v_7162;
v_7163:
    goto v_7159;
v_7160:
    goto v_7161;
v_7162:
    v_7190 = (v_7192 == v_7190 ? lisp_true : nil);
    v_7190 = (v_7190 == nil ? lisp_true : nil);
    goto v_7145;
    v_7190 = nil;
v_7145:
    goto v_7120;
    v_7190 = nil;
v_7120:
    goto v_7106;
    v_7190 = nil;
v_7106:
    if (v_7190 == nil) goto v_7104;
    goto v_7174;
v_7170:
    v_7191 = elt(env, 7); // "algebraic expression"
    goto v_7171;
v_7172:
    v_7190 = elt(env, 8); // "Rlisp88 form"
    goto v_7173;
v_7174:
    goto v_7170;
v_7171:
    goto v_7172;
v_7173:
    {
        fn = elt(env, 11); // typerr
        return (*qfn2(fn))(fn, v_7191, v_7190);
    }
v_7104:
    goto v_7186;
v_7180:
    v_7192 = v_7191;
    goto v_7181;
v_7182:
    v_7191 = qvalue(elt(env, 3)); // !*vars!*
    goto v_7183;
v_7184:
    v_7190 = qvalue(elt(env, 4)); // !*mode
    goto v_7185;
v_7186:
    goto v_7180;
v_7181:
    goto v_7182;
v_7183:
    goto v_7184;
v_7185:
    {
        fn = elt(env, 10); // form1
        return (*qfnn(fn))(fn, 3, v_7192, v_7191, v_7190);
    }
    v_7190 = nil;
    return onevalue(v_7190);
}



// Code for mo!=revlexcomp

static LispObject CC_moMrevlexcomp(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7106;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7065;
    stack[-1] = v_7064;
// end of prologue
    goto v_7075;
v_7071:
    v_7106 = stack[-1];
    stack[-2] = Llength(nil, v_7106);
    env = stack[-3];
    goto v_7072;
v_7073:
    v_7106 = stack[0];
    v_7106 = Llength(nil, v_7106);
    env = stack[-3];
    goto v_7074;
v_7075:
    goto v_7071;
v_7072:
    goto v_7073;
v_7074:
    if (((intptr_t)(stack[-2])) > ((intptr_t)(v_7106))) goto v_7069;
    else goto v_7070;
v_7069:
    v_7106 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_7068;
v_7070:
    goto v_7087;
v_7083:
    v_7106 = stack[0];
    stack[-2] = Llength(nil, v_7106);
    env = stack[-3];
    goto v_7084;
v_7085:
    v_7106 = stack[-1];
    v_7106 = Llength(nil, v_7106);
    env = stack[-3];
    goto v_7086;
v_7087:
    goto v_7083;
v_7084:
    goto v_7085;
v_7086:
    if (((intptr_t)(stack[-2])) > ((intptr_t)(v_7106))) goto v_7081;
    else goto v_7082;
v_7081:
    v_7106 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7068;
v_7082:
    goto v_7101;
v_7097:
    v_7106 = stack[-1];
    stack[-1] = Lreverse(nil, v_7106);
    env = stack[-3];
    goto v_7098;
v_7099:
    v_7106 = stack[0];
    v_7106 = Lreverse(nil, v_7106);
    env = stack[-3];
    goto v_7100;
v_7101:
    goto v_7097;
v_7098:
    goto v_7099;
v_7100:
    fn = elt(env, 1); // mo!=degcomp
    v_7106 = (*qfn2(fn))(fn, stack[-1], v_7106);
    return negate(v_7106);
    v_7106 = nil;
v_7068:
    return onevalue(v_7106);
}



// Code for dd

static LispObject CC_dd(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7170, v_7171, v_7172;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_7065;
    stack[-2] = v_7064;
// end of prologue
    goto v_7076;
v_7072:
    v_7171 = stack[0];
    goto v_7073;
v_7074:
    v_7170 = stack[-2];
    goto v_7075;
v_7076:
    goto v_7072;
v_7073:
    goto v_7074;
v_7075:
    fn = elt(env, 5); // dquot
    v_7170 = (*qfn2(fn))(fn, v_7171, v_7170);
    env = stack[-4];
    v_7172 = v_7170;
    v_7170 = v_7172;
    if (v_7170 == nil) goto v_7081;
    else goto v_7082;
v_7081:
    goto v_7093;
v_7089:
    v_7171 = stack[-2];
    goto v_7090;
v_7091:
    v_7170 = stack[0];
    goto v_7092;
v_7093:
    goto v_7089;
v_7090:
    goto v_7091;
v_7092:
    fn = elt(env, 6); // dless
    v_7170 = (*qfn2(fn))(fn, v_7171, v_7170);
    if (v_7170 == nil) goto v_7087;
    v_7170 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7085;
v_7087:
    v_7170 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7085;
    v_7170 = nil;
v_7085:
    goto v_7070;
v_7082:
    goto v_7108;
v_7104:
    v_7171 = qvalue(elt(env, 1)); // ordering
    goto v_7105;
v_7106:
    v_7170 = elt(env, 2); // lex
    goto v_7107;
v_7108:
    goto v_7104;
v_7105:
    goto v_7106;
v_7107:
    if (v_7171 == v_7170) goto v_7103;
    v_7170 = v_7172;
    v_7170 = qcdr(v_7170);
    v_7172 = v_7170;
    goto v_7101;
v_7103:
v_7101:
    v_7170 = v_7172;
    fn = elt(env, 7); // leftzeros
    v_7170 = (*qfn1(fn))(fn, v_7170);
    env = stack[-4];
    stack[-3] = v_7170;
    v_7170 = qvalue(elt(env, 3)); // nc!*
    if (v_7170 == nil) goto v_7121;
    else goto v_7122;
v_7121:
    goto v_7128;
v_7124:
    stack[-1] = stack[-3];
    goto v_7125;
v_7126:
    goto v_7134;
v_7130:
    v_7170 = qvalue(elt(env, 4)); // varlist!*
    stack[0] = Llength(nil, v_7170);
    env = stack[-4];
    goto v_7131;
v_7132:
    v_7170 = stack[-2];
    fn = elt(env, 8); // class
    v_7170 = (*qfn1(fn))(fn, v_7170);
    env = stack[-4];
    goto v_7133;
v_7134:
    goto v_7130;
v_7131:
    goto v_7132;
v_7133:
    v_7170 = (LispObject)(intptr_t)((intptr_t)stack[0] - (intptr_t)v_7170 + TAG_FIXNUM);
    goto v_7127;
v_7128:
    goto v_7124;
v_7125:
    goto v_7126;
v_7127:
    v_7170 = ((intptr_t)stack[-1] < (intptr_t)v_7170) ? lisp_true : nil;
    v_7170 = (v_7170 == nil ? lisp_true : nil);
    goto v_7120;
v_7122:
    v_7170 = nil;
    goto v_7120;
    v_7170 = nil;
v_7120:
    if (v_7170 == nil) goto v_7118;
    v_7170 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_7116;
v_7118:
    v_7170 = qvalue(elt(env, 3)); // nc!*
    if (v_7170 == nil) goto v_7147;
    goto v_7155;
v_7151:
    stack[0] = stack[-3];
    goto v_7152;
v_7153:
    goto v_7161;
v_7157:
    v_7170 = qvalue(elt(env, 4)); // varlist!*
    v_7170 = Llength(nil, v_7170);
    env = stack[-4];
    goto v_7158;
v_7159:
    v_7171 = qvalue(elt(env, 3)); // nc!*
    goto v_7160;
v_7161:
    goto v_7157;
v_7158:
    goto v_7159;
v_7160:
    v_7170 = (LispObject)(intptr_t)((intptr_t)v_7170 - (intptr_t)v_7171 + TAG_FIXNUM);
    goto v_7154;
v_7155:
    goto v_7151;
v_7152:
    goto v_7153;
v_7154:
    if (((intptr_t)(stack[0])) < ((intptr_t)(v_7170))) goto v_7147;
    v_7170 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_7116;
v_7147:
    v_7170 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_7116;
    v_7170 = nil;
v_7116:
v_7070:
    return onevalue(v_7170);
}



// Code for noncomperm

static LispObject CC_noncomperm(LispObject env,
                         LispObject v_7064)
{
    env = qenv(env);
    LispObject v_7185, v_7186, v_7187;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7064);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_7064;
// end of prologue
    v_7185 = stack[-4];
    if (v_7185 == nil) goto v_7068;
    else goto v_7069;
v_7068:
    v_7185 = stack[-4];
    return ncons(v_7185);
v_7069:
    v_7185 = stack[-4];
    stack[-5] = v_7185;
v_7080:
    v_7185 = stack[-5];
    if (v_7185 == nil) goto v_7085;
    else goto v_7086;
v_7085:
    v_7185 = nil;
    goto v_7079;
v_7086:
    v_7185 = stack[-5];
    v_7185 = qcar(v_7185);
    stack[0] = v_7185;
    goto v_7097;
v_7093:
    v_7186 = stack[0];
    goto v_7094;
v_7095:
    v_7185 = stack[-4];
    goto v_7096;
v_7097:
    goto v_7093;
v_7094:
    goto v_7095;
v_7096:
    fn = elt(env, 2); // noncomdel
    v_7185 = (*qfn2(fn))(fn, v_7186, v_7185);
    env = stack[-6];
    v_7187 = v_7185;
    goto v_7109;
v_7105:
    v_7186 = v_7187;
    goto v_7106;
v_7107:
    v_7185 = elt(env, 1); // failed
    goto v_7108;
v_7109:
    goto v_7105;
v_7106:
    goto v_7107;
v_7108:
    if (v_7186 == v_7185) goto v_7103;
    else goto v_7104;
v_7103:
    v_7185 = nil;
    goto v_7102;
v_7104:
    goto v_7120;
v_7116:
    v_7185 = v_7187;
    v_7186 = CC_noncomperm(elt(env, 0), v_7185);
    env = stack[-6];
    goto v_7117;
v_7118:
    v_7185 = stack[0];
    goto v_7119;
v_7120:
    goto v_7116;
v_7117:
    goto v_7118;
v_7119:
    fn = elt(env, 3); // mapcons
    v_7185 = (*qfn2(fn))(fn, v_7186, v_7185);
    env = stack[-6];
    goto v_7102;
    v_7185 = nil;
v_7102:
    stack[-3] = v_7185;
    v_7185 = stack[-3];
    fn = elt(env, 4); // lastpair
    v_7185 = (*qfn1(fn))(fn, v_7185);
    env = stack[-6];
    stack[-2] = v_7185;
    v_7185 = stack[-5];
    v_7185 = qcdr(v_7185);
    stack[-5] = v_7185;
    v_7185 = stack[-2];
    if (!consp(v_7185)) goto v_7130;
    else goto v_7131;
v_7130:
    goto v_7080;
v_7131:
v_7081:
    v_7185 = stack[-5];
    if (v_7185 == nil) goto v_7135;
    else goto v_7136;
v_7135:
    v_7185 = stack[-3];
    goto v_7079;
v_7136:
    goto v_7144;
v_7140:
    stack[-1] = stack[-2];
    goto v_7141;
v_7142:
    v_7185 = stack[-5];
    v_7185 = qcar(v_7185);
    stack[0] = v_7185;
    goto v_7154;
v_7150:
    v_7186 = stack[0];
    goto v_7151;
v_7152:
    v_7185 = stack[-4];
    goto v_7153;
v_7154:
    goto v_7150;
v_7151:
    goto v_7152;
v_7153:
    fn = elt(env, 2); // noncomdel
    v_7185 = (*qfn2(fn))(fn, v_7186, v_7185);
    env = stack[-6];
    v_7187 = v_7185;
    goto v_7166;
v_7162:
    v_7186 = v_7187;
    goto v_7163;
v_7164:
    v_7185 = elt(env, 1); // failed
    goto v_7165;
v_7166:
    goto v_7162;
v_7163:
    goto v_7164;
v_7165:
    if (v_7186 == v_7185) goto v_7160;
    else goto v_7161;
v_7160:
    v_7185 = nil;
    goto v_7159;
v_7161:
    goto v_7177;
v_7173:
    v_7185 = v_7187;
    v_7186 = CC_noncomperm(elt(env, 0), v_7185);
    env = stack[-6];
    goto v_7174;
v_7175:
    v_7185 = stack[0];
    goto v_7176;
v_7177:
    goto v_7173;
v_7174:
    goto v_7175;
v_7176:
    fn = elt(env, 3); // mapcons
    v_7185 = (*qfn2(fn))(fn, v_7186, v_7185);
    env = stack[-6];
    goto v_7159;
    v_7185 = nil;
v_7159:
    goto v_7143;
v_7144:
    goto v_7140;
v_7141:
    goto v_7142;
v_7143:
    v_7185 = Lrplacd(nil, stack[-1], v_7185);
    env = stack[-6];
    v_7185 = stack[-2];
    fn = elt(env, 4); // lastpair
    v_7185 = (*qfn1(fn))(fn, v_7185);
    env = stack[-6];
    stack[-2] = v_7185;
    v_7185 = stack[-5];
    v_7185 = qcdr(v_7185);
    stack[-5] = v_7185;
    goto v_7081;
v_7079:
    goto v_7067;
    v_7185 = nil;
v_7067:
    return onevalue(v_7185);
}



// Code for put!-kvalue

static LispObject CC_putKkvalue(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7134, v_7135;
    LispObject fn;
    LispObject v_7067, v_7066, v_7065, v_7064;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "put-kvalue");
    va_start(aa, nargs);
    v_7064 = va_arg(aa, LispObject);
    v_7065 = va_arg(aa, LispObject);
    v_7066 = va_arg(aa, LispObject);
    v_7067 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_7067,v_7066,v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_7064,v_7065,v_7066,v_7067);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_7067;
    stack[-2] = v_7066;
    stack[-3] = v_7065;
    stack[0] = v_7064;
// end of prologue
    goto v_7082;
v_7078:
    v_7135 = stack[-1];
    goto v_7079;
v_7080:
    v_7134 = elt(env, 1); // !*sq
    goto v_7081;
v_7082:
    goto v_7078;
v_7079:
    goto v_7080;
v_7081:
    if (!consp(v_7135)) goto v_7076;
    v_7135 = qcar(v_7135);
    if (v_7135 == v_7134) goto v_7075;
    else goto v_7076;
v_7075:
    goto v_7090;
v_7086:
    v_7135 = stack[-2];
    goto v_7087;
v_7088:
    v_7134 = stack[-1];
    v_7134 = qcdr(v_7134);
    v_7134 = qcar(v_7134);
    goto v_7089;
v_7090:
    goto v_7086;
v_7087:
    goto v_7088;
v_7089:
    fn = elt(env, 3); // sq_member
    v_7134 = (*qfn2(fn))(fn, v_7135, v_7134);
    env = stack[-5];
    goto v_7074;
v_7076:
    goto v_7102;
v_7098:
    v_7135 = stack[-2];
    goto v_7099;
v_7100:
    v_7134 = stack[-1];
    goto v_7101;
v_7102:
    goto v_7098;
v_7099:
    goto v_7100;
v_7101:
    fn = elt(env, 4); // smember
    v_7134 = (*qfn2(fn))(fn, v_7135, v_7134);
    env = stack[-5];
    goto v_7074;
    v_7134 = nil;
v_7074:
    if (v_7134 == nil) goto v_7072;
    v_7134 = stack[-2];
    {
        fn = elt(env, 5); // recursiveerror
        return (*qfn1(fn))(fn, v_7134);
    }
v_7072:
    goto v_7116;
v_7110:
    stack[-4] = stack[0];
    goto v_7111;
v_7112:
    stack[0] = elt(env, 2); // kvalue
    goto v_7113;
v_7114:
    goto v_7124;
v_7120:
    goto v_7121;
v_7122:
    goto v_7131;
v_7127:
    v_7135 = stack[-2];
    goto v_7128;
v_7129:
    v_7134 = stack[-1];
    goto v_7130;
v_7131:
    goto v_7127;
v_7128:
    goto v_7129;
v_7130:
    v_7134 = list2(v_7135, v_7134);
    env = stack[-5];
    goto v_7123;
v_7124:
    goto v_7120;
v_7121:
    goto v_7122;
v_7123:
    fn = elt(env, 6); // aconc
    v_7134 = (*qfn2(fn))(fn, stack[-3], v_7134);
    goto v_7115;
v_7116:
    goto v_7110;
v_7111:
    goto v_7112;
v_7113:
    goto v_7114;
v_7115:
    {
        LispObject v_7141 = stack[-4];
        LispObject v_7142 = stack[0];
        return Lputprop(nil, 3, v_7141, v_7142, v_7134);
    }
    v_7134 = nil;
    return onevalue(v_7134);
}



// Code for p_princ

static LispObject CC_p_princ(LispObject env,
                         LispObject v_7064, LispObject v_7065)
{
    env = qenv(env);
    LispObject v_7166, v_7167;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7065,v_7064);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7064,v_7065);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7065;
    stack[-1] = v_7064;
// end of prologue
    v_7166 = stack[-1];
    v_7166 = Lexplodec(nil, v_7166);
    env = stack[-3];
    stack[-2] = v_7166;
    v_7166 = qvalue(elt(env, 1)); // bldmsg_chars!*
    if (v_7166 == nil) goto v_7075;
    v_7166 = stack[0];
    if (v_7166 == nil) goto v_7080;
    goto v_7087;
v_7083:
    v_7167 = elt(env, 2); // ! 
    goto v_7084;
v_7085:
    v_7166 = qvalue(elt(env, 1)); // bldmsg_chars!*
    goto v_7086;
v_7087:
    goto v_7083;
v_7084:
    goto v_7085;
v_7086:
    v_7166 = cons(v_7167, v_7166);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_7166; // bldmsg_chars!*
    goto v_7078;
v_7080:
v_7078:
    v_7166 = stack[-2];
    stack[0] = v_7166;
v_7093:
    v_7166 = stack[0];
    if (v_7166 == nil) goto v_7097;
    else goto v_7098;
v_7097:
    goto v_7092;
v_7098:
    v_7166 = stack[0];
    v_7166 = qcar(v_7166);
    goto v_7109;
v_7105:
    v_7167 = v_7166;
    goto v_7106;
v_7107:
    v_7166 = qvalue(elt(env, 1)); // bldmsg_chars!*
    goto v_7108;
v_7109:
    goto v_7105;
v_7106:
    goto v_7107;
v_7108:
    v_7166 = cons(v_7167, v_7166);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_7166; // bldmsg_chars!*
    v_7166 = stack[0];
    v_7166 = qcdr(v_7166);
    stack[0] = v_7166;
    goto v_7093;
v_7092:
    goto v_7073;
v_7075:
    v_7166 = stack[0];
    if (v_7166 == nil) goto v_7119;
    goto v_7130;
v_7126:
    goto v_7136;
v_7132:
    stack[0] = Lposn(nil, 0);
    env = stack[-3];
    goto v_7133;
v_7134:
    v_7166 = stack[-2];
    v_7166 = Llength(nil, v_7166);
    env = stack[-3];
    v_7166 = add1(v_7166);
    env = stack[-3];
    goto v_7135;
v_7136:
    goto v_7132;
v_7133:
    goto v_7134;
v_7135:
    v_7167 = plus2(stack[0], v_7166);
    env = stack[-3];
    goto v_7127;
v_7128:
    v_7166 = qvalue(elt(env, 3)); // !*ll!*
    goto v_7129;
v_7130:
    goto v_7126;
v_7127:
    goto v_7128;
v_7129:
    v_7166 = (LispObject)greaterp2(v_7167, v_7166);
    v_7166 = v_7166 ? lisp_true : nil;
    env = stack[-3];
    if (v_7166 == nil) goto v_7124;
    v_7166 = Lterpri(nil, 0);
    env = stack[-3];
    goto v_7122;
v_7124:
v_7122:
    v_7166 = elt(env, 4); // " "
    v_7166 = Lprinc(nil, v_7166);
    env = stack[-3];
    goto v_7117;
v_7119:
    goto v_7152;
v_7148:
    goto v_7158;
v_7154:
    stack[0] = Lposn(nil, 0);
    env = stack[-3];
    goto v_7155;
v_7156:
    v_7166 = stack[-2];
    v_7166 = Llength(nil, v_7166);
    env = stack[-3];
    goto v_7157;
v_7158:
    goto v_7154;
v_7155:
    goto v_7156;
v_7157:
    v_7167 = plus2(stack[0], v_7166);
    env = stack[-3];
    goto v_7149;
v_7150:
    v_7166 = qvalue(elt(env, 3)); // !*ll!*
    goto v_7151;
v_7152:
    goto v_7148;
v_7149:
    goto v_7150;
v_7151:
    v_7166 = (LispObject)greaterp2(v_7167, v_7166);
    v_7166 = v_7166 ? lisp_true : nil;
    env = stack[-3];
    if (v_7166 == nil) goto v_7146;
    v_7166 = Lterpri(nil, 0);
    env = stack[-3];
    goto v_7117;
v_7146:
v_7117:
    v_7166 = stack[-1];
    v_7166 = Lprinc(nil, v_7166);
    goto v_7073;
v_7073:
    v_7166 = nil;
    return onevalue(v_7166);
}



setup_type const u13_setup[] =
{
    {"gcdf2",                   TOO_FEW_2,      CC_gcdf2,      WRONG_NO_2},
    {"subs3f1",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_subs3f1},
    {"get_group_in",            CC_get_group_in,TOO_MANY_1,    WRONG_NO_1},
    {"qqe_ofsf_prepat",         CC_qqe_ofsf_prepat,TOO_MANY_1, WRONG_NO_1},
    {"mkzl",                    CC_mkzl,        TOO_MANY_1,    WRONG_NO_1},
    {"intexprnp",               TOO_FEW_2,      CC_intexprnp,  WRONG_NO_2},
    {"rat_numrn",               CC_rat_numrn,   TOO_MANY_1,    WRONG_NO_1},
    {"naryrd",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_naryrd},
    {"spquotematrix",           CC_spquotematrix,TOO_MANY_1,   WRONG_NO_1},
    {"fortranop",               CC_fortranop,   TOO_MANY_1,    WRONG_NO_1},
    {"red-ratios1",             TOO_FEW_2,      CC_redKratios1,WRONG_NO_2},
    {"multop",                  TOO_FEW_2,      CC_multop,     WRONG_NO_2},
    {"dividef",                 TOO_FEW_2,      CC_dividef,    WRONG_NO_2},
    {"dl_get",                  CC_dl_get,      TOO_MANY_1,    WRONG_NO_1},
    {"crprcd",                  CC_crprcd,      TOO_MANY_1,    WRONG_NO_1},
    {"*q2f",                    CC_Hq2f,        TOO_MANY_1,    WRONG_NO_1},
    {"sfto_greaterq",           TOO_FEW_2,      CC_sfto_greaterq,WRONG_NO_2},
    {"rl_simp",                 CC_rl_simp,     TOO_MANY_1,    WRONG_NO_1},
    {"lto_max",                 CC_lto_max,     TOO_MANY_1,    WRONG_NO_1},
    {"qqe_qprefix-var",         CC_qqe_qprefixKvar,TOO_MANY_1, WRONG_NO_1},
    {"quotfx",                  TOO_FEW_2,      CC_quotfx,     WRONG_NO_2},
    {"ibalp_hassimple",         CC_ibalp_hassimple,TOO_MANY_1, WRONG_NO_1},
    {"sfto_mvartest",           TOO_FEW_2,      CC_sfto_mvartest,WRONG_NO_2},
    {"sub_math",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_sub_math},
    {"zeropp",                  CC_zeropp,      TOO_MANY_1,    WRONG_NO_1},
    {"unbind",                  CC_unbind,      TOO_MANY_1,    WRONG_NO_1},
    {"sc_null",                 CC_sc_null,     TOO_MANY_1,    WRONG_NO_1},
    {"assert_dyntypep",         CC_assert_dyntypep,TOO_MANY_1, WRONG_NO_1},
    {"simptimes",               CC_simptimes,   TOO_MANY_1,    WRONG_NO_1},
    {"pdif",                    TOO_FEW_2,      CC_pdif,       WRONG_NO_2},
    {"lalr_most_common_reduction",CC_lalr_most_common_reduction,TOO_MANY_1,WRONG_NO_1},
    {"wtchk",                   TOO_FEW_2,      CC_wtchk,      WRONG_NO_2},
    {"mk+mat+mult+mat",         TOO_FEW_2,      CC_mkLmatLmultLmat,WRONG_NO_2},
    {"talp_chkknowl",           TOO_FEW_2,      CC_talp_chkknowl,WRONG_NO_2},
    {"rl_susitf",               TOO_FEW_2,      CC_rl_susitf,  WRONG_NO_2},
    {"cgb_buch-ev_divides?",    TOO_FEW_2,      CC_cgb_buchKev_dividesW,WRONG_NO_2},
    {"ev_tdeg",                 CC_ev_tdeg,     TOO_MANY_1,    WRONG_NO_1},
    {"vevlcm",                  TOO_FEW_2,      CC_vevlcm,     WRONG_NO_2},
    {"listdiff",                TOO_FEW_2,      CC_listdiff,   WRONG_NO_2},
    {"deletemult*",             CC_deletemultH, TOO_MANY_1,    WRONG_NO_1},
    {"chknewnam",               CC_chknewnam,   TOO_MANY_1,    WRONG_NO_1},
    {"aminusp:",                CC_aminuspT,    TOO_MANY_1,    WRONG_NO_1},
    {"pv_times3",               TOO_FEW_2,      CC_pv_times3,  WRONG_NO_2},
    {"b:ordexn",                TOO_FEW_2,      CC_bTordexn,   WRONG_NO_2},
    {"cde_lassoc2",             TOO_FEW_2,      CC_cde_lassoc2,WRONG_NO_2},
    {"idsort",                  CC_idsort,      TOO_MANY_1,    WRONG_NO_1},
    {"removeg1",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_removeg1},
    {"talp_simplatrinv",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_simplatrinv},
    {"terpri*",                 CC_terpriH,     TOO_MANY_1,    WRONG_NO_1},
    {"rd:minus",                CC_rdTminus,    TOO_MANY_1,    WRONG_NO_1},
    {"groebcpcompless?",        TOO_FEW_2,      CC_groebcpcomplessW,WRONG_NO_2},
    {"wedget2",                 TOO_FEW_2,      CC_wedget2,    WRONG_NO_2},
    {"form",                    CC_form,        TOO_MANY_1,    WRONG_NO_1},
    {"mo=revlexcomp",           TOO_FEW_2,      CC_moMrevlexcomp,WRONG_NO_2},
    {"dd",                      TOO_FEW_2,      CC_dd,         WRONG_NO_2},
    {"noncomperm",              CC_noncomperm,  TOO_MANY_1,    WRONG_NO_1},
    {"put-kvalue",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_putKkvalue},
    {"p_princ",                 TOO_FEW_2,      CC_p_princ,    WRONG_NO_2},
    {NULL, (one_args *)"u13", (two_args *)"86227 1525242 4050241", 0}
};

// end of generated code
