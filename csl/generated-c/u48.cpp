
// $destdir/u48.c        Machine generated C code

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



// Code for cl_rename!-vars1

static LispObject CC_cl_renameKvars1(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_28527, v_28528, v_28529, v_28530;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27890,v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27889,v_27890);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_27890;
    stack[0] = v_27889;
// end of prologue
    stack[-3] = nil;
    v_28527 = stack[0];
    if (!consp(v_28527)) goto v_27901;
    else goto v_27902;
v_27901:
    v_28527 = stack[0];
    goto v_27900;
v_27902:
    v_28527 = stack[0];
    v_28527 = qcar(v_28527);
    goto v_27900;
    v_28527 = nil;
v_27900:
    stack[-5] = v_28527;
    goto v_27929;
v_27925:
    v_28528 = stack[-5];
    goto v_27926;
v_27927:
    v_28527 = elt(env, 1); // or
    goto v_27928;
v_27929:
    goto v_27925;
v_27926:
    goto v_27927;
v_27928:
    if (v_28528 == v_28527) goto v_27923;
    else goto v_27924;
v_27923:
    v_28527 = lisp_true;
    goto v_27922;
v_27924:
    goto v_27939;
v_27935:
    v_28528 = stack[-5];
    goto v_27936;
v_27937:
    v_28527 = elt(env, 2); // and
    goto v_27938;
v_27939:
    goto v_27935;
v_27936:
    goto v_27937;
v_27938:
    v_28527 = (v_28528 == v_28527 ? lisp_true : nil);
    goto v_27922;
    v_28527 = nil;
v_27922:
    if (v_28527 == nil) goto v_27920;
    v_28527 = lisp_true;
    goto v_27918;
v_27920:
    goto v_27950;
v_27946:
    v_28528 = stack[-5];
    goto v_27947;
v_27948:
    v_28527 = elt(env, 3); // not
    goto v_27949;
v_27950:
    goto v_27946;
v_27947:
    goto v_27948;
v_27949:
    v_28527 = (v_28528 == v_28527 ? lisp_true : nil);
    goto v_27918;
    v_28527 = nil;
v_27918:
    if (v_28527 == nil) goto v_27916;
    v_28527 = lisp_true;
    goto v_27914;
v_27916:
    goto v_27965;
v_27961:
    v_28528 = stack[-5];
    goto v_27962;
v_27963:
    v_28527 = elt(env, 4); // impl
    goto v_27964;
v_27965:
    goto v_27961;
v_27962:
    goto v_27963;
v_27964:
    if (v_28528 == v_28527) goto v_27959;
    else goto v_27960;
v_27959:
    v_28527 = lisp_true;
    goto v_27958;
v_27960:
    goto v_27979;
v_27975:
    v_28528 = stack[-5];
    goto v_27976;
v_27977:
    v_28527 = elt(env, 5); // repl
    goto v_27978;
v_27979:
    goto v_27975;
v_27976:
    goto v_27977;
v_27978:
    if (v_28528 == v_28527) goto v_27973;
    else goto v_27974;
v_27973:
    v_28527 = lisp_true;
    goto v_27972;
v_27974:
    goto v_27989;
v_27985:
    v_28528 = stack[-5];
    goto v_27986;
v_27987:
    v_28527 = elt(env, 6); // equiv
    goto v_27988;
v_27989:
    goto v_27985;
v_27986:
    goto v_27987;
v_27988:
    v_28527 = (v_28528 == v_28527 ? lisp_true : nil);
    goto v_27972;
    v_28527 = nil;
v_27972:
    goto v_27958;
    v_28527 = nil;
v_27958:
    goto v_27914;
    v_28527 = nil;
v_27914:
    if (v_28527 == nil) goto v_27912;
    v_28527 = stack[0];
    v_28527 = qcdr(v_28527);
    stack[0] = v_28527;
v_27996:
    v_28527 = stack[0];
    if (v_28527 == nil) goto v_28001;
    else goto v_28002;
v_28001:
    goto v_27995;
v_28002:
    v_28527 = stack[0];
    v_28527 = qcar(v_28527);
    goto v_28016;
v_28012:
    v_28528 = v_28527;
    goto v_28013;
v_28014:
    v_28527 = stack[-4];
    goto v_28015;
v_28016:
    goto v_28012;
v_28013:
    goto v_28014;
v_28015:
    v_28527 = CC_cl_renameKvars1(elt(env, 0), v_28528, v_28527);
    env = stack[-7];
    v_28528 = v_28527;
    v_28527 = v_28528;
    v_28527 = qcar(v_28527);
    stack[-1] = v_28527;
    v_28527 = v_28528;
    v_28527 = qcdr(v_28527);
    stack[-4] = v_28527;
    goto v_28029;
v_28025:
    v_28528 = stack[-1];
    goto v_28026;
v_28027:
    v_28527 = stack[-3];
    goto v_28028;
v_28029:
    goto v_28025;
v_28026:
    goto v_28027;
v_28028:
    v_28527 = cons(v_28528, v_28527);
    env = stack[-7];
    stack[-3] = v_28527;
    v_28527 = stack[0];
    v_28527 = qcdr(v_28527);
    stack[0] = v_28527;
    goto v_27996;
v_27995:
    goto v_28042;
v_28036:
    v_28528 = stack[-5];
    goto v_28037;
v_28038:
    v_28527 = stack[-3];
    v_28529 = Lnreverse(nil, v_28527);
    goto v_28039;
v_28040:
    v_28527 = stack[-4];
    goto v_28041;
v_28042:
    goto v_28036;
v_28037:
    goto v_28038;
v_28039:
    goto v_28040;
v_28041:
    return acons(v_28528, v_28529, v_28527);
v_27912:
    goto v_28059;
v_28055:
    v_28528 = stack[-5];
    goto v_28056;
v_28057:
    v_28527 = elt(env, 7); // ex
    goto v_28058;
v_28059:
    goto v_28055;
v_28056:
    goto v_28057;
v_28058:
    if (v_28528 == v_28527) goto v_28053;
    else goto v_28054;
v_28053:
    v_28527 = lisp_true;
    goto v_28052;
v_28054:
    goto v_28069;
v_28065:
    v_28528 = stack[-5];
    goto v_28066;
v_28067:
    v_28527 = elt(env, 8); // all
    goto v_28068;
v_28069:
    goto v_28065;
v_28066:
    goto v_28067;
v_28068:
    v_28527 = (v_28528 == v_28527 ? lisp_true : nil);
    goto v_28052;
    v_28527 = nil;
v_28052:
    if (v_28527 == nil) goto v_28050;
    goto v_28081;
v_28077:
    v_28527 = stack[0];
    v_28527 = qcdr(v_28527);
    v_28527 = qcdr(v_28527);
    v_28528 = qcar(v_28527);
    goto v_28078;
v_28079:
    v_28527 = stack[-4];
    goto v_28080;
v_28081:
    goto v_28077;
v_28078:
    goto v_28079;
v_28080:
    v_28527 = CC_cl_renameKvars1(elt(env, 0), v_28528, v_28527);
    env = stack[-7];
    v_28528 = v_28527;
    v_28527 = v_28528;
    v_28527 = qcar(v_28527);
    stack[-1] = v_28527;
    v_28527 = v_28528;
    v_28527 = qcdr(v_28527);
    stack[-4] = v_28527;
    goto v_28096;
v_28092:
    v_28527 = stack[0];
    v_28527 = qcdr(v_28527);
    v_28528 = qcar(v_28527);
    goto v_28093;
v_28094:
    v_28527 = stack[-4];
    v_28527 = qcdr(v_28527);
    goto v_28095;
v_28096:
    goto v_28092;
v_28093:
    goto v_28094;
v_28095:
    v_28527 = Lassoc(nil, v_28528, v_28527);
    stack[-3] = v_28527;
    v_28527 = stack[-3];
    if (v_28527 == nil) goto v_28106;
    goto v_28117;
v_28113:
    v_28527 = stack[-3];
    v_28528 = qcdr(v_28527);
    goto v_28114;
v_28115:
    v_28527 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28116;
v_28117:
    goto v_28113;
v_28114:
    goto v_28115;
v_28116:
    v_28527 = Leqn(nil, v_28528, v_28527);
    env = stack[-7];
    if (v_28527 == nil) goto v_28111;
    goto v_28126;
v_28122:
    v_28528 = stack[-3];
    goto v_28123;
v_28124:
    v_28527 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28125;
v_28126:
    goto v_28122;
v_28123:
    goto v_28124;
v_28125:
    fn = elt(env, 12); // setcdr
    v_28527 = (*qfn2(fn))(fn, v_28528, v_28527);
    env = stack[-7];
    goto v_28134;
v_28130:
    goto v_28142;
v_28136:
    v_28529 = stack[-5];
    goto v_28137;
v_28138:
    v_28527 = stack[0];
    v_28527 = qcdr(v_28527);
    v_28528 = qcar(v_28527);
    goto v_28139;
v_28140:
    v_28527 = stack[-1];
    goto v_28141;
v_28142:
    goto v_28136;
v_28137:
    goto v_28138;
v_28139:
    goto v_28140;
v_28141:
    v_28528 = list3(v_28529, v_28528, v_28527);
    goto v_28131;
v_28132:
    v_28527 = stack[-4];
    goto v_28133;
v_28134:
    goto v_28130;
v_28131:
    goto v_28132;
v_28133:
    return cons(v_28528, v_28527);
v_28111:
v_28151:
    goto v_28157;
v_28153:
    v_28527 = stack[-3];
    v_28528 = qcar(v_28527);
    goto v_28154;
v_28155:
    v_28527 = stack[-3];
    v_28527 = qcdr(v_28527);
    goto v_28156;
v_28157:
    goto v_28153;
v_28154:
    goto v_28155;
v_28156:
    fn = elt(env, 13); // mkid
    v_28527 = (*qfn2(fn))(fn, v_28528, v_28527);
    env = stack[-7];
    stack[-2] = v_28527;
    goto v_28167;
v_28163:
    stack[0] = stack[-3];
    goto v_28164;
v_28165:
    v_28527 = stack[-3];
    v_28527 = qcdr(v_28527);
    v_28527 = add1(v_28527);
    env = stack[-7];
    goto v_28166;
v_28167:
    goto v_28163;
v_28164:
    goto v_28165;
v_28166:
    fn = elt(env, 12); // setcdr
    v_28527 = (*qfn2(fn))(fn, stack[0], v_28527);
    env = stack[-7];
    goto v_28181;
v_28177:
    v_28528 = stack[-2];
    goto v_28178;
v_28179:
    v_28527 = stack[-4];
    v_28527 = qcar(v_28527);
    goto v_28180;
v_28181:
    goto v_28177;
v_28178:
    goto v_28179;
v_28180:
    v_28527 = Lmemq(nil, v_28528, v_28527);
    if (v_28527 == nil) goto v_28176;
    else goto v_28174;
v_28176:
    v_28527 = stack[-2];
    if (!symbolp(v_28527)) v_28527 = nil;
    else { v_28527 = qfastgets(v_28527);
           if (v_28527 != nil) { v_28527 = elt(v_28527, 4); // avalue
#ifdef RECORD_GET
             if (v_28527 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_28527 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_28527 == SPID_NOPROP) v_28527 = nil; }}
#endif
    if (v_28527 == nil) goto v_28186;
    else goto v_28174;
v_28186:
    goto v_28175;
v_28174:
    goto v_28151;
v_28175:
    goto v_28194;
v_28190:
    stack[0] = stack[-4];
    goto v_28191;
v_28192:
    goto v_28201;
v_28197:
    v_28528 = stack[-2];
    goto v_28198;
v_28199:
    v_28527 = stack[-4];
    v_28527 = qcar(v_28527);
    goto v_28200;
v_28201:
    goto v_28197;
v_28198:
    goto v_28199;
v_28200:
    v_28527 = cons(v_28528, v_28527);
    env = stack[-7];
    goto v_28193;
v_28194:
    goto v_28190;
v_28191:
    goto v_28192;
v_28193:
    fn = elt(env, 14); // setcar
    v_28527 = (*qfn2(fn))(fn, stack[0], v_28527);
    env = stack[-7];
    goto v_28213;
v_28207:
    goto v_28208;
v_28209:
    stack[0] = elt(env, 9); // rl_varsubstat
    goto v_28210;
v_28211:
    goto v_28221;
v_28217:
    v_28528 = stack[-2];
    goto v_28218;
v_28219:
    v_28527 = stack[-3];
    v_28527 = qcar(v_28527);
    goto v_28220;
v_28221:
    goto v_28217;
v_28218:
    goto v_28219;
v_28220:
    v_28527 = list2(v_28528, v_28527);
    env = stack[-7];
    goto v_28212;
v_28213:
    goto v_28207;
v_28208:
    goto v_28209;
v_28210:
    goto v_28211;
v_28212:
    fn = elt(env, 15); // cl_apply2ats1
    v_28527 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_28527);
    env = stack[-7];
    stack[-1] = v_28527;
    goto v_28230;
v_28226:
    goto v_28238;
v_28232:
    v_28529 = stack[-5];
    goto v_28233;
v_28234:
    v_28528 = stack[-2];
    goto v_28235;
v_28236:
    v_28527 = stack[-1];
    goto v_28237;
v_28238:
    goto v_28232;
v_28233:
    goto v_28234;
v_28235:
    goto v_28236;
v_28237:
    v_28528 = list3(v_28529, v_28528, v_28527);
    goto v_28227;
v_28228:
    v_28527 = stack[-4];
    goto v_28229;
v_28230:
    goto v_28226;
v_28227:
    goto v_28228;
v_28229:
    return cons(v_28528, v_28527);
v_28106:
    goto v_28248;
v_28244:
    goto v_28256;
v_28250:
    v_28529 = stack[-5];
    goto v_28251;
v_28252:
    v_28527 = stack[0];
    v_28527 = qcdr(v_28527);
    v_28528 = qcar(v_28527);
    goto v_28253;
v_28254:
    v_28527 = stack[-1];
    goto v_28255;
v_28256:
    goto v_28250;
v_28251:
    goto v_28252;
v_28253:
    goto v_28254;
v_28255:
    v_28528 = list3(v_28529, v_28528, v_28527);
    goto v_28245;
v_28246:
    v_28527 = stack[-4];
    goto v_28247;
v_28248:
    goto v_28244;
v_28245:
    goto v_28246;
v_28247:
    return cons(v_28528, v_28527);
v_28050:
    goto v_28275;
v_28271:
    v_28528 = stack[-5];
    goto v_28272;
v_28273:
    v_28527 = elt(env, 10); // bex
    goto v_28274;
v_28275:
    goto v_28271;
v_28272:
    goto v_28273;
v_28274:
    if (v_28528 == v_28527) goto v_28269;
    else goto v_28270;
v_28269:
    v_28527 = lisp_true;
    goto v_28268;
v_28270:
    goto v_28285;
v_28281:
    v_28528 = stack[-5];
    goto v_28282;
v_28283:
    v_28527 = elt(env, 11); // ball
    goto v_28284;
v_28285:
    goto v_28281;
v_28282:
    goto v_28283;
v_28284:
    v_28527 = (v_28528 == v_28527 ? lisp_true : nil);
    goto v_28268;
    v_28527 = nil;
v_28268:
    if (v_28527 == nil) goto v_28266;
    goto v_28297;
v_28293:
    v_28527 = stack[0];
    v_28527 = qcdr(v_28527);
    v_28527 = qcdr(v_28527);
    v_28528 = qcar(v_28527);
    goto v_28294;
v_28295:
    v_28527 = stack[-4];
    goto v_28296;
v_28297:
    goto v_28293;
v_28294:
    goto v_28295;
v_28296:
    v_28527 = CC_cl_renameKvars1(elt(env, 0), v_28528, v_28527);
    env = stack[-7];
    v_28528 = v_28527;
    v_28527 = v_28528;
    v_28527 = qcar(v_28527);
    stack[-1] = v_28527;
    v_28527 = v_28528;
    v_28527 = qcdr(v_28527);
    stack[-4] = v_28527;
    goto v_28312;
v_28308:
    v_28527 = stack[0];
    v_28527 = qcdr(v_28527);
    v_28528 = qcar(v_28527);
    goto v_28309;
v_28310:
    v_28527 = stack[-4];
    v_28527 = qcdr(v_28527);
    goto v_28311;
v_28312:
    goto v_28308;
v_28309:
    goto v_28310;
v_28311:
    v_28527 = Lassoc(nil, v_28528, v_28527);
    stack[-3] = v_28527;
    v_28527 = stack[-3];
    if (v_28527 == nil) goto v_28322;
    goto v_28333;
v_28329:
    v_28527 = stack[-3];
    v_28528 = qcdr(v_28527);
    goto v_28330;
v_28331:
    v_28527 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28332;
v_28333:
    goto v_28329;
v_28330:
    goto v_28331;
v_28332:
    v_28527 = Leqn(nil, v_28528, v_28527);
    env = stack[-7];
    if (v_28527 == nil) goto v_28327;
    goto v_28342;
v_28338:
    v_28528 = stack[-3];
    goto v_28339;
v_28340:
    v_28527 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28341;
v_28342:
    goto v_28338;
v_28339:
    goto v_28340;
v_28341:
    fn = elt(env, 12); // setcdr
    v_28527 = (*qfn2(fn))(fn, v_28528, v_28527);
    env = stack[-7];
    goto v_28350;
v_28346:
    goto v_28360;
v_28352:
    v_28530 = stack[-5];
    goto v_28353;
v_28354:
    v_28527 = stack[0];
    v_28527 = qcdr(v_28527);
    v_28529 = qcar(v_28527);
    goto v_28355;
v_28356:
    v_28528 = stack[-1];
    goto v_28357;
v_28358:
    v_28527 = stack[0];
    v_28527 = qcdr(v_28527);
    v_28527 = qcdr(v_28527);
    v_28527 = qcdr(v_28527);
    v_28527 = qcar(v_28527);
    goto v_28359;
v_28360:
    goto v_28352;
v_28353:
    goto v_28354;
v_28355:
    goto v_28356;
v_28357:
    goto v_28358;
v_28359:
    v_28528 = list4(v_28530, v_28529, v_28528, v_28527);
    goto v_28347;
v_28348:
    v_28527 = stack[-4];
    goto v_28349;
v_28350:
    goto v_28346;
v_28347:
    goto v_28348;
v_28349:
    return cons(v_28528, v_28527);
v_28327:
v_28374:
    goto v_28380;
v_28376:
    v_28527 = stack[-3];
    v_28528 = qcar(v_28527);
    goto v_28377;
v_28378:
    v_28527 = stack[-3];
    v_28527 = qcdr(v_28527);
    goto v_28379;
v_28380:
    goto v_28376;
v_28377:
    goto v_28378;
v_28379:
    fn = elt(env, 13); // mkid
    v_28527 = (*qfn2(fn))(fn, v_28528, v_28527);
    env = stack[-7];
    stack[-2] = v_28527;
    goto v_28390;
v_28386:
    stack[-6] = stack[-3];
    goto v_28387;
v_28388:
    v_28527 = stack[-3];
    v_28527 = qcdr(v_28527);
    v_28527 = add1(v_28527);
    env = stack[-7];
    goto v_28389;
v_28390:
    goto v_28386;
v_28387:
    goto v_28388;
v_28389:
    fn = elt(env, 12); // setcdr
    v_28527 = (*qfn2(fn))(fn, stack[-6], v_28527);
    env = stack[-7];
    goto v_28404;
v_28400:
    v_28528 = stack[-2];
    goto v_28401;
v_28402:
    v_28527 = stack[-4];
    v_28527 = qcar(v_28527);
    goto v_28403;
v_28404:
    goto v_28400;
v_28401:
    goto v_28402;
v_28403:
    v_28527 = Lmemq(nil, v_28528, v_28527);
    if (v_28527 == nil) goto v_28399;
    else goto v_28397;
v_28399:
    v_28527 = stack[-2];
    if (!symbolp(v_28527)) v_28527 = nil;
    else { v_28527 = qfastgets(v_28527);
           if (v_28527 != nil) { v_28527 = elt(v_28527, 4); // avalue
#ifdef RECORD_GET
             if (v_28527 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_28527 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_28527 == SPID_NOPROP) v_28527 = nil; }}
#endif
    if (v_28527 == nil) goto v_28409;
    else goto v_28397;
v_28409:
    goto v_28398;
v_28397:
    goto v_28374;
v_28398:
    goto v_28417;
v_28413:
    stack[-6] = stack[-4];
    goto v_28414;
v_28415:
    goto v_28424;
v_28420:
    v_28528 = stack[-2];
    goto v_28421;
v_28422:
    v_28527 = stack[-4];
    v_28527 = qcar(v_28527);
    goto v_28423;
v_28424:
    goto v_28420;
v_28421:
    goto v_28422;
v_28423:
    v_28527 = cons(v_28528, v_28527);
    env = stack[-7];
    goto v_28416;
v_28417:
    goto v_28413;
v_28414:
    goto v_28415;
v_28416:
    fn = elt(env, 14); // setcar
    v_28527 = (*qfn2(fn))(fn, stack[-6], v_28527);
    env = stack[-7];
    goto v_28436;
v_28430:
    v_28527 = stack[0];
    v_28527 = qcdr(v_28527);
    v_28527 = qcdr(v_28527);
    v_28527 = qcdr(v_28527);
    stack[-6] = qcar(v_28527);
    goto v_28431;
v_28432:
    stack[0] = elt(env, 9); // rl_varsubstat
    goto v_28433;
v_28434:
    goto v_28448;
v_28444:
    v_28528 = stack[-2];
    goto v_28445;
v_28446:
    v_28527 = stack[-3];
    v_28527 = qcar(v_28527);
    goto v_28447;
v_28448:
    goto v_28444;
v_28445:
    goto v_28446;
v_28447:
    v_28527 = list2(v_28528, v_28527);
    env = stack[-7];
    goto v_28435;
v_28436:
    goto v_28430;
v_28431:
    goto v_28432;
v_28433:
    goto v_28434;
v_28435:
    fn = elt(env, 15); // cl_apply2ats1
    v_28527 = (*qfnn(fn))(fn, 3, stack[-6], stack[0], v_28527);
    env = stack[-7];
    stack[-6] = v_28527;
    goto v_28459;
v_28453:
    goto v_28454;
v_28455:
    stack[0] = elt(env, 9); // rl_varsubstat
    goto v_28456;
v_28457:
    goto v_28467;
v_28463:
    v_28528 = stack[-2];
    goto v_28464;
v_28465:
    v_28527 = stack[-3];
    v_28527 = qcar(v_28527);
    goto v_28466;
v_28467:
    goto v_28463;
v_28464:
    goto v_28465;
v_28466:
    v_28527 = list2(v_28528, v_28527);
    env = stack[-7];
    goto v_28458;
v_28459:
    goto v_28453;
v_28454:
    goto v_28455;
v_28456:
    goto v_28457;
v_28458:
    fn = elt(env, 15); // cl_apply2ats1
    v_28527 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_28527);
    env = stack[-7];
    stack[-1] = v_28527;
    goto v_28476;
v_28472:
    goto v_28486;
v_28478:
    v_28530 = stack[-5];
    goto v_28479;
v_28480:
    v_28529 = stack[-2];
    goto v_28481;
v_28482:
    v_28528 = stack[-1];
    goto v_28483;
v_28484:
    v_28527 = stack[-6];
    goto v_28485;
v_28486:
    goto v_28478;
v_28479:
    goto v_28480;
v_28481:
    goto v_28482;
v_28483:
    goto v_28484;
v_28485:
    v_28528 = list4(v_28530, v_28529, v_28528, v_28527);
    goto v_28473;
v_28474:
    v_28527 = stack[-4];
    goto v_28475;
v_28476:
    goto v_28472;
v_28473:
    goto v_28474;
v_28475:
    return cons(v_28528, v_28527);
v_28322:
    goto v_28497;
v_28493:
    goto v_28507;
v_28499:
    v_28530 = stack[-5];
    goto v_28500;
v_28501:
    v_28527 = stack[0];
    v_28527 = qcdr(v_28527);
    v_28529 = qcar(v_28527);
    goto v_28502;
v_28503:
    v_28528 = stack[-1];
    goto v_28504;
v_28505:
    v_28527 = stack[0];
    v_28527 = qcdr(v_28527);
    v_28527 = qcdr(v_28527);
    v_28527 = qcdr(v_28527);
    v_28527 = qcar(v_28527);
    goto v_28506;
v_28507:
    goto v_28499;
v_28500:
    goto v_28501;
v_28502:
    goto v_28503;
v_28504:
    goto v_28505;
v_28506:
    v_28528 = list4(v_28530, v_28529, v_28528, v_28527);
    goto v_28494;
v_28495:
    v_28527 = stack[-4];
    goto v_28496;
v_28497:
    goto v_28493;
v_28494:
    goto v_28495;
v_28496:
    return cons(v_28528, v_28527);
v_28266:
    goto v_28524;
v_28520:
    v_28528 = stack[0];
    goto v_28521;
v_28522:
    v_28527 = stack[-4];
    goto v_28523;
v_28524:
    goto v_28520;
v_28521:
    goto v_28522;
v_28523:
    return cons(v_28528, v_28527);
    return onevalue(v_28527);
}



// Code for rl_sacat

static LispObject CC_rl_sacat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27911, v_27912, v_27913;
    LispObject fn;
    LispObject v_27891, v_27890, v_27889;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "rl_sacat");
    va_start(aa, nargs);
    v_27889 = va_arg(aa, LispObject);
    v_27890 = va_arg(aa, LispObject);
    v_27891 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27891,v_27890,v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27889,v_27890,v_27891);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_27911 = v_27891;
    v_27912 = v_27890;
    v_27913 = v_27889;
// end of prologue
    goto v_27898;
v_27894:
    stack[0] = qvalue(elt(env, 1)); // rl_sacat!*
    goto v_27895;
v_27896:
    goto v_27907;
v_27901:
    goto v_27902;
v_27903:
    goto v_27904;
v_27905:
    goto v_27906;
v_27907:
    goto v_27901;
v_27902:
    goto v_27903;
v_27904:
    goto v_27905;
v_27906:
    v_27911 = list3(v_27913, v_27912, v_27911);
    env = stack[-1];
    goto v_27897;
v_27898:
    goto v_27894;
v_27895:
    goto v_27896;
v_27897:
    {
        LispObject v_27915 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_27915, v_27911);
    }
}



// Code for dvfsf_susipost

static LispObject CC_dvfsf_susipost(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_27893, v_27894;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27893 = v_27890;
    v_27894 = v_27889;
// end of prologue
    v_27893 = v_27894;
    return onevalue(v_27893);
}



// Code for asymmetrize!-inds

static LispObject CC_asymmetrizeKinds(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_28226, v_28227;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27890,v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27889,v_27890);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-8] = v_27890;
    stack[-9] = v_27889;
// end of prologue
    v_28226 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-10] = v_28226;
    v_28226 = stack[-9];
    stack[-7] = v_28226;
    v_28226 = stack[-7];
    if (v_28226 == nil) goto v_27910;
    else goto v_27911;
v_27910:
    v_28226 = nil;
    goto v_27905;
v_27911:
    v_28226 = stack[-7];
    v_28226 = qcar(v_28226);
    v_28227 = v_28226;
    if (!consp(v_28227)) goto v_27920;
    else goto v_27921;
v_27920:
    goto v_27928;
v_27924:
    v_28227 = stack[-8];
    goto v_27925;
v_27926:
    goto v_27927;
v_27928:
    goto v_27924;
v_27925:
    goto v_27926;
v_27927:
    fn = elt(env, 1); // nth
    v_28226 = (*qfn2(fn))(fn, v_28227, v_28226);
    env = stack[-11];
    goto v_27919;
v_27921:
    stack[-3] = v_28226;
    v_28226 = stack[-3];
    if (v_28226 == nil) goto v_27942;
    else goto v_27943;
v_27942:
    v_28226 = nil;
    goto v_27937;
v_27943:
    v_28226 = stack[-3];
    v_28226 = qcar(v_28226);
    goto v_27955;
v_27951:
    v_28227 = stack[-8];
    goto v_27952;
v_27953:
    goto v_27954;
v_27955:
    goto v_27951;
v_27952:
    goto v_27953;
v_27954:
    fn = elt(env, 1); // nth
    v_28226 = (*qfn2(fn))(fn, v_28227, v_28226);
    env = stack[-11];
    v_28226 = ncons(v_28226);
    env = stack[-11];
    stack[-1] = v_28226;
    stack[-2] = v_28226;
v_27938:
    v_28226 = stack[-3];
    v_28226 = qcdr(v_28226);
    stack[-3] = v_28226;
    v_28226 = stack[-3];
    if (v_28226 == nil) goto v_27962;
    else goto v_27963;
v_27962:
    v_28226 = stack[-2];
    goto v_27937;
v_27963:
    goto v_27971;
v_27967:
    stack[0] = stack[-1];
    goto v_27968;
v_27969:
    v_28226 = stack[-3];
    v_28226 = qcar(v_28226);
    goto v_27982;
v_27978:
    v_28227 = stack[-8];
    goto v_27979;
v_27980:
    goto v_27981;
v_27982:
    goto v_27978;
v_27979:
    goto v_27980;
v_27981:
    fn = elt(env, 1); // nth
    v_28226 = (*qfn2(fn))(fn, v_28227, v_28226);
    env = stack[-11];
    v_28226 = ncons(v_28226);
    env = stack[-11];
    goto v_27970;
v_27971:
    goto v_27967;
v_27968:
    goto v_27969;
v_27970:
    v_28226 = Lrplacd(nil, stack[0], v_28226);
    env = stack[-11];
    v_28226 = stack[-1];
    v_28226 = qcdr(v_28226);
    stack[-1] = v_28226;
    goto v_27938;
v_27937:
    goto v_27919;
    v_28226 = nil;
v_27919:
    v_28226 = ncons(v_28226);
    env = stack[-11];
    stack[-5] = v_28226;
    stack[-6] = v_28226;
v_27906:
    v_28226 = stack[-7];
    v_28226 = qcdr(v_28226);
    stack[-7] = v_28226;
    v_28226 = stack[-7];
    if (v_28226 == nil) goto v_27991;
    else goto v_27992;
v_27991:
    v_28226 = stack[-6];
    goto v_27905;
v_27992:
    goto v_28000;
v_27996:
    stack[-4] = stack[-5];
    goto v_27997;
v_27998:
    v_28226 = stack[-7];
    v_28226 = qcar(v_28226);
    v_28227 = v_28226;
    if (!consp(v_28227)) goto v_28008;
    else goto v_28009;
v_28008:
    goto v_28016;
v_28012:
    v_28227 = stack[-8];
    goto v_28013;
v_28014:
    goto v_28015;
v_28016:
    goto v_28012;
v_28013:
    goto v_28014;
v_28015:
    fn = elt(env, 1); // nth
    v_28226 = (*qfn2(fn))(fn, v_28227, v_28226);
    env = stack[-11];
    goto v_28007;
v_28009:
    stack[-3] = v_28226;
    v_28226 = stack[-3];
    if (v_28226 == nil) goto v_28030;
    else goto v_28031;
v_28030:
    v_28226 = nil;
    goto v_28025;
v_28031:
    v_28226 = stack[-3];
    v_28226 = qcar(v_28226);
    goto v_28043;
v_28039:
    v_28227 = stack[-8];
    goto v_28040;
v_28041:
    goto v_28042;
v_28043:
    goto v_28039;
v_28040:
    goto v_28041;
v_28042:
    fn = elt(env, 1); // nth
    v_28226 = (*qfn2(fn))(fn, v_28227, v_28226);
    env = stack[-11];
    v_28226 = ncons(v_28226);
    env = stack[-11];
    stack[-1] = v_28226;
    stack[-2] = v_28226;
v_28026:
    v_28226 = stack[-3];
    v_28226 = qcdr(v_28226);
    stack[-3] = v_28226;
    v_28226 = stack[-3];
    if (v_28226 == nil) goto v_28050;
    else goto v_28051;
v_28050:
    v_28226 = stack[-2];
    goto v_28025;
v_28051:
    goto v_28059;
v_28055:
    stack[0] = stack[-1];
    goto v_28056;
v_28057:
    v_28226 = stack[-3];
    v_28226 = qcar(v_28226);
    goto v_28070;
v_28066:
    v_28227 = stack[-8];
    goto v_28067;
v_28068:
    goto v_28069;
v_28070:
    goto v_28066;
v_28067:
    goto v_28068;
v_28069:
    fn = elt(env, 1); // nth
    v_28226 = (*qfn2(fn))(fn, v_28227, v_28226);
    env = stack[-11];
    v_28226 = ncons(v_28226);
    env = stack[-11];
    goto v_28058;
v_28059:
    goto v_28055;
v_28056:
    goto v_28057;
v_28058:
    v_28226 = Lrplacd(nil, stack[0], v_28226);
    env = stack[-11];
    v_28226 = stack[-1];
    v_28226 = qcdr(v_28226);
    stack[-1] = v_28226;
    goto v_28026;
v_28025:
    goto v_28007;
    v_28226 = nil;
v_28007:
    v_28226 = ncons(v_28226);
    env = stack[-11];
    goto v_27999;
v_28000:
    goto v_27996;
v_27997:
    goto v_27998;
v_27999:
    v_28226 = Lrplacd(nil, stack[-4], v_28226);
    env = stack[-11];
    v_28226 = stack[-5];
    v_28226 = qcdr(v_28226);
    stack[-5] = v_28226;
    goto v_27906;
v_27905:
    stack[0] = v_28226;
    v_28226 = stack[0];
    fn = elt(env, 2); // repeats
    v_28226 = (*qfn1(fn))(fn, v_28226);
    env = stack[-11];
    if (v_28226 == nil) goto v_28080;
    v_28226 = nil;
    goto v_27898;
v_28080:
    goto v_28093;
v_28089:
    v_28226 = stack[0];
    v_28226 = qcar(v_28226);
    if (!consp(v_28226)) goto v_28096;
    else goto v_28097;
v_28096:
    v_28226 = stack[0];
    fn = elt(env, 3); // indordn
    v_28226 = (*qfn1(fn))(fn, v_28226);
    env = stack[-11];
    v_28227 = v_28226;
    goto v_28095;
v_28097:
    v_28226 = stack[0];
    fn = elt(env, 4); // indordln
    v_28226 = (*qfn1(fn))(fn, v_28226);
    env = stack[-11];
    v_28227 = v_28226;
    goto v_28095;
    v_28227 = nil;
v_28095:
    stack[-5] = v_28227;
    goto v_28090;
v_28091:
    v_28226 = stack[0];
    goto v_28092;
v_28093:
    goto v_28089;
v_28090:
    goto v_28091;
v_28092:
    fn = elt(env, 5); // permp
    v_28226 = (*qfn2(fn))(fn, v_28227, v_28226);
    env = stack[-11];
    if (v_28226 == nil) goto v_28087;
    v_28226 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28085;
v_28087:
    v_28226 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_28085;
    v_28226 = nil;
v_28085:
    stack[0] = v_28226;
    v_28226 = stack[-9];
    v_28226 = qcar(v_28226);
    if (!consp(v_28226)) goto v_28114;
    v_28226 = stack[-9];
    fn = elt(env, 6); // flatindl
    v_28226 = (*qfn1(fn))(fn, v_28226);
    env = stack[-11];
    stack[-9] = v_28226;
    v_28226 = stack[-5];
    fn = elt(env, 6); // flatindl
    v_28226 = (*qfn1(fn))(fn, v_28226);
    env = stack[-11];
    stack[-5] = v_28226;
    goto v_28112;
v_28114:
v_28112:
    goto v_28126;
v_28122:
    v_28227 = stack[-9];
    goto v_28123;
v_28124:
    v_28226 = stack[-5];
    goto v_28125;
v_28126:
    goto v_28122;
v_28123:
    goto v_28124;
v_28125:
    fn = elt(env, 7); // pair
    v_28226 = (*qfn2(fn))(fn, v_28227, v_28226);
    env = stack[-11];
    stack[-5] = v_28226;
    goto v_28134;
v_28130:
    stack[-6] = stack[0];
    goto v_28131;
v_28132:
    v_28226 = stack[-8];
    stack[-7] = v_28226;
    v_28226 = stack[-7];
    if (v_28226 == nil) goto v_28145;
    else goto v_28146;
v_28145:
    v_28226 = nil;
    goto v_28140;
v_28146:
    v_28226 = stack[-7];
    v_28226 = qcar(v_28226);
    stack[-1] = v_28226;
    v_28226 = stack[-5];
    if (v_28226 == nil) goto v_28156;
    goto v_28164;
v_28160:
    v_28226 = stack[-5];
    v_28226 = qcar(v_28226);
    stack[0] = qcar(v_28226);
    goto v_28161;
v_28162:
    v_28226 = stack[-10];
    v_28226 = add1(v_28226);
    env = stack[-11];
    stack[-10] = v_28226;
    goto v_28163;
v_28164:
    goto v_28160;
v_28161:
    goto v_28162;
v_28163:
    if (equal(stack[0], v_28226)) goto v_28159;
    else goto v_28156;
v_28159:
    v_28226 = stack[-5];
    v_28226 = qcar(v_28226);
    v_28226 = qcdr(v_28226);
    v_28227 = v_28226;
    v_28226 = stack[-5];
    v_28226 = qcdr(v_28226);
    stack[-5] = v_28226;
    v_28226 = v_28227;
    goto v_28154;
v_28156:
    v_28226 = stack[-1];
    goto v_28154;
    v_28226 = nil;
v_28154:
    v_28226 = ncons(v_28226);
    env = stack[-11];
    stack[-3] = v_28226;
    stack[-4] = v_28226;
v_28141:
    v_28226 = stack[-7];
    v_28226 = qcdr(v_28226);
    stack[-7] = v_28226;
    v_28226 = stack[-7];
    if (v_28226 == nil) goto v_28183;
    else goto v_28184;
v_28183:
    v_28226 = stack[-4];
    goto v_28140;
v_28184:
    goto v_28192;
v_28188:
    stack[-2] = stack[-3];
    goto v_28189;
v_28190:
    v_28226 = stack[-7];
    v_28226 = qcar(v_28226);
    stack[-1] = v_28226;
    v_28226 = stack[-5];
    if (v_28226 == nil) goto v_28201;
    goto v_28209;
v_28205:
    v_28226 = stack[-5];
    v_28226 = qcar(v_28226);
    stack[0] = qcar(v_28226);
    goto v_28206;
v_28207:
    v_28226 = stack[-10];
    v_28226 = add1(v_28226);
    env = stack[-11];
    stack[-10] = v_28226;
    goto v_28208;
v_28209:
    goto v_28205;
v_28206:
    goto v_28207;
v_28208:
    if (equal(stack[0], v_28226)) goto v_28204;
    else goto v_28201;
v_28204:
    v_28226 = stack[-5];
    v_28226 = qcar(v_28226);
    v_28226 = qcdr(v_28226);
    v_28227 = v_28226;
    v_28226 = stack[-5];
    v_28226 = qcdr(v_28226);
    stack[-5] = v_28226;
    v_28226 = v_28227;
    goto v_28199;
v_28201:
    v_28226 = stack[-1];
    goto v_28199;
    v_28226 = nil;
v_28199:
    v_28226 = ncons(v_28226);
    env = stack[-11];
    goto v_28191;
v_28192:
    goto v_28188;
v_28189:
    goto v_28190;
v_28191:
    v_28226 = Lrplacd(nil, stack[-2], v_28226);
    env = stack[-11];
    v_28226 = stack[-3];
    v_28226 = qcdr(v_28226);
    stack[-3] = v_28226;
    goto v_28141;
v_28140:
    goto v_28133;
v_28134:
    goto v_28130;
v_28131:
    goto v_28132;
v_28133:
    {
        LispObject v_28239 = stack[-6];
        return cons(v_28239, v_28226);
    }
v_27898:
    return onevalue(v_28226);
}



// Code for defined_all_edge

static LispObject CC_defined_all_edge(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27966, v_27967, v_27968;
    LispObject fn;
    LispObject v_27891, v_27890, v_27889;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "defined_all_edge");
    va_start(aa, nargs);
    v_27889 = va_arg(aa, LispObject);
    v_27890 = va_arg(aa, LispObject);
    v_27891 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27891,v_27890,v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27889,v_27890,v_27891);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_27891;
    stack[-1] = v_27890;
    stack[-2] = v_27889;
// end of prologue
v_27896:
    v_27966 = stack[-2];
    if (v_27966 == nil) goto v_27899;
    else goto v_27900;
v_27899:
    v_27966 = nil;
    goto v_27895;
v_27900:
    goto v_27910;
v_27906:
    v_27966 = stack[-2];
    v_27967 = qcar(v_27966);
    goto v_27907;
v_27908:
    v_27966 = stack[0];
    goto v_27909;
v_27910:
    goto v_27906;
v_27907:
    goto v_27908;
v_27909:
    fn = elt(env, 1); // def_edge
    v_27966 = (*qfn2(fn))(fn, v_27967, v_27966);
    env = stack[-4];
    if (v_27966 == nil) goto v_27904;
    v_27966 = stack[-2];
    v_27966 = qcar(v_27966);
    fn = elt(env, 2); // p_def_edge
    v_27966 = (*qfn1(fn))(fn, v_27966);
    env = stack[-4];
    if (v_27966 == nil) goto v_27917;
    v_27966 = lisp_true;
    goto v_27895;
v_27917:
    goto v_27929;
v_27925:
    goto v_27935;
v_27931:
    v_27967 = stack[-1];
    goto v_27932;
v_27933:
    v_27966 = stack[-2];
    goto v_27934;
v_27935:
    goto v_27931;
v_27932:
    goto v_27933;
v_27934:
    stack[0] = Lnconc(nil, v_27967, v_27966);
    env = stack[-4];
    goto v_27926;
v_27927:
    goto v_27945;
v_27939:
    v_27966 = stack[-2];
    v_27966 = qcar(v_27966);
    v_27966 = qcdr(v_27966);
    v_27968 = qcar(v_27966);
    goto v_27940;
v_27941:
    v_27967 = lisp_true;
    goto v_27942;
v_27943:
    v_27966 = nil;
    goto v_27944;
v_27945:
    goto v_27939;
v_27940:
    goto v_27941;
v_27942:
    goto v_27943;
v_27944:
    v_27966 = list2star(v_27968, v_27967, v_27966);
    env = stack[-4];
    goto v_27928;
v_27929:
    goto v_27925;
v_27926:
    goto v_27927;
v_27928:
    {
        LispObject v_27973 = stack[0];
        fn = elt(env, 3); // rep_edge_prop_
        return (*qfn2(fn))(fn, v_27973, v_27966);
    }
    goto v_27898;
v_27904:
    v_27966 = stack[-2];
    v_27966 = qcdr(v_27966);
    stack[-3] = v_27966;
    goto v_27961;
v_27957:
    v_27966 = stack[-2];
    v_27967 = qcar(v_27966);
    goto v_27958;
v_27959:
    v_27966 = stack[-1];
    goto v_27960;
v_27961:
    goto v_27957;
v_27958:
    goto v_27959;
v_27960:
    v_27966 = cons(v_27967, v_27966);
    env = stack[-4];
    stack[-1] = v_27966;
    v_27966 = stack[-3];
    stack[-2] = v_27966;
    goto v_27896;
v_27898:
    v_27966 = nil;
v_27895:
    return onevalue(v_27966);
}



// Code for mapcarcar

static LispObject CC_mapcarcar(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_27933;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27889);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_27933 = v_27889;
// end of prologue
    stack[-3] = v_27933;
    v_27933 = stack[-3];
    if (v_27933 == nil) goto v_27900;
    else goto v_27901;
v_27900:
    v_27933 = nil;
    goto v_27895;
v_27901:
    v_27933 = stack[-3];
    v_27933 = qcar(v_27933);
    v_27933 = qcar(v_27933);
    v_27933 = ncons(v_27933);
    env = stack[-4];
    stack[-1] = v_27933;
    stack[-2] = v_27933;
v_27896:
    v_27933 = stack[-3];
    v_27933 = qcdr(v_27933);
    stack[-3] = v_27933;
    v_27933 = stack[-3];
    if (v_27933 == nil) goto v_27914;
    else goto v_27915;
v_27914:
    v_27933 = stack[-2];
    goto v_27895;
v_27915:
    goto v_27923;
v_27919:
    stack[0] = stack[-1];
    goto v_27920;
v_27921:
    v_27933 = stack[-3];
    v_27933 = qcar(v_27933);
    v_27933 = qcar(v_27933);
    v_27933 = ncons(v_27933);
    env = stack[-4];
    goto v_27922;
v_27923:
    goto v_27919;
v_27920:
    goto v_27921;
v_27922:
    v_27933 = Lrplacd(nil, stack[0], v_27933);
    env = stack[-4];
    v_27933 = stack[-1];
    v_27933 = qcdr(v_27933);
    stack[-1] = v_27933;
    goto v_27896;
v_27895:
    return onevalue(v_27933);
}



// Code for !*a2kwoweight

static LispObject CC_Ha2kwoweight(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_27919, v_27920;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27889);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_27889;
// end of prologue
    v_27920 = lisp_true;
    v_27919 = nil;
// Binding !*uncached
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = v_27920; // !*uncached
// Binding wtl!*
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 2, -1);
    qvalue(elt(env, 2)) = v_27919; // wtl!*
    v_27919 = stack[-2];
    fn = elt(env, 4); // simp!*
    v_27919 = (*qfn1(fn))(fn, v_27919);
    env = stack[-4];
    stack[0] = v_27919;
    v_27919 = stack[0];
    fn = elt(env, 5); // kernp
    v_27919 = (*qfn1(fn))(fn, v_27919);
    env = stack[-4];
    if (v_27919 == nil) goto v_27901;
    v_27919 = stack[0];
    v_27919 = qcar(v_27919);
    v_27919 = qcar(v_27919);
    v_27919 = qcar(v_27919);
    v_27919 = qcar(v_27919);
    goto v_27899;
v_27901:
    goto v_27916;
v_27912:
    v_27920 = stack[-2];
    goto v_27913;
v_27914:
    v_27919 = elt(env, 3); // kernel
    goto v_27915;
v_27916:
    goto v_27912;
v_27913:
    goto v_27914;
v_27915:
    fn = elt(env, 6); // typerr
    v_27919 = (*qfn2(fn))(fn, v_27920, v_27919);
    goto v_27899;
    v_27919 = nil;
v_27899:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_27919);
}



// Code for polynomreduceby

static LispObject CC_polynomreduceby(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_27971, v_27972;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27890,v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27889,v_27890);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_27890;
    stack[-2] = v_27889;
// end of prologue
    stack[-3] = nil;
v_27899:
    v_27971 = stack[-3];
    if (v_27971 == nil) goto v_27903;
    goto v_27898;
v_27903:
    v_27971 = stack[-2];
    stack[0] = v_27971;
v_27909:
    v_27971 = stack[0];
    v_27971 = qcar(v_27971);
    if (v_27971 == nil) goto v_27912;
    goto v_27923;
v_27919:
    v_27971 = stack[0];
    v_27972 = qcar(v_27971);
    goto v_27920;
v_27921:
    v_27971 = stack[-1];
    v_27971 = qcar(v_27971);
    goto v_27922;
v_27923:
    goto v_27919;
v_27920:
    goto v_27921;
v_27922:
    fn = elt(env, 2); // monomisdivisibleby
    v_27971 = (*qfn2(fn))(fn, v_27972, v_27971);
    env = stack[-4];
    if (v_27971 == nil) goto v_27917;
    else goto v_27912;
v_27917:
    goto v_27913;
v_27912:
    goto v_27908;
v_27913:
    v_27971 = stack[0];
    v_27971 = qcdr(v_27971);
    stack[0] = v_27971;
    goto v_27909;
v_27908:
    v_27971 = stack[0];
    v_27971 = qcar(v_27971);
    if (v_27971 == nil) goto v_27934;
    else goto v_27935;
v_27934:
    v_27971 = lisp_true;
    stack[-3] = v_27971;
    goto v_27933;
v_27935:
    goto v_27947;
v_27943:
    v_27971 = stack[0];
    v_27972 = qcar(v_27971);
    goto v_27944;
v_27945:
    v_27971 = stack[-1];
    v_27971 = qcar(v_27971);
    goto v_27946;
v_27947:
    goto v_27943;
v_27944:
    goto v_27945;
v_27946:
    fn = elt(env, 3); // monomdivide
    v_27971 = (*qfn2(fn))(fn, v_27972, v_27971);
    env = stack[-4];
    goto v_27957;
v_27953:
    stack[0] = stack[-2];
    goto v_27954;
v_27955:
    goto v_27964;
v_27960:
    v_27972 = stack[-1];
    goto v_27961;
v_27962:
    goto v_27963;
v_27964:
    goto v_27960;
v_27961:
    goto v_27962;
v_27963:
    fn = elt(env, 4); // polynommultiplybymonom
    v_27971 = (*qfn2(fn))(fn, v_27972, v_27971);
    env = stack[-4];
    goto v_27956;
v_27957:
    goto v_27953;
v_27954:
    goto v_27955;
v_27956:
    fn = elt(env, 5); // polynomadd
    v_27971 = (*qfn2(fn))(fn, stack[0], v_27971);
    env = stack[-4];
    goto v_27933;
v_27933:
    goto v_27899;
v_27898:
    v_27971 = qvalue(elt(env, 1)); // fluidbibasisreductionsmade
    v_27971 = (LispObject)((intptr_t)(v_27971) + 0x10);
    qvalue(elt(env, 1)) = v_27971; // fluidbibasisreductionsmade
    v_27971 = nil;
    return onevalue(v_27971);
}



// Code for ofsf_smeqtable

static LispObject CC_ofsf_smeqtable(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_27930, v_27931, v_27932, v_27933, v_27934, v_27935;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27933 = v_27890;
    v_27934 = v_27889;
// end of prologue
    v_27930 = elt(env, 1); // ((equal (equal . equal) (neq . false) (geq . equal) (leq . equal) (greaterp . false) (lessp . false)) (neq (neq . neq) (geq
// . greaterp) (leq . lessp) (greaterp . greaterp) (lessp . lessp)) (geq (geq . geq) (leq . equal) (greaterp . greaterp) (lessp
// . false)) (leq (leq . leq) (greaterp . false) (lessp . lessp)) (greaterp (greaterp . greaterp) (lessp . false)) (lessp (lessp
// . lessp)))
    v_27935 = v_27930;
    goto v_27903;
v_27899:
    v_27932 = v_27933;
    goto v_27900;
v_27901:
    goto v_27909;
v_27905:
    v_27931 = v_27934;
    goto v_27906;
v_27907:
    v_27930 = v_27935;
    goto v_27908;
v_27909:
    goto v_27905;
v_27906:
    goto v_27907;
v_27908:
    v_27930 = Latsoc(nil, v_27931, v_27930);
    goto v_27902;
v_27903:
    goto v_27899;
v_27900:
    goto v_27901;
v_27902:
    v_27930 = Latsoc(nil, v_27932, v_27930);
    if (v_27930 == nil) goto v_27898;
    else goto v_27897;
v_27898:
    goto v_27918;
v_27914:
    v_27930 = v_27934;
    goto v_27915;
v_27916:
    goto v_27924;
v_27920:
    v_27931 = v_27933;
    goto v_27921;
v_27922:
    v_27932 = v_27935;
    goto v_27923;
v_27924:
    goto v_27920;
v_27921:
    goto v_27922;
v_27923:
    v_27931 = Latsoc(nil, v_27931, v_27932);
    goto v_27917;
v_27918:
    goto v_27914;
v_27915:
    goto v_27916;
v_27917:
    v_27930 = Latsoc(nil, v_27930, v_27931);
v_27897:
    v_27930 = qcdr(v_27930);
    return onevalue(v_27930);
}



// Code for girationalize!:

static LispObject CC_girationalizeT(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_27988, v_27989, v_27990;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27889);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_27889;
// end of prologue
    stack[-5] = nil;
// Binding !*gcd
// FLUIDBIND: reloadenv=6 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-6, 1, -3);
    qvalue(elt(env, 1)) = nil; // !*gcd
    v_27988 = lisp_true;
    qvalue(elt(env, 1)) = v_27988; // !*gcd
    goto v_27905;
v_27901:
    stack[-1] = stack[-5];
    goto v_27902;
v_27903:
    v_27988 = stack[-4];
    v_27988 = qcdr(v_27988);
    stack[-5] = v_27988;
    fn = elt(env, 3); // conjgd
    v_27988 = (*qfn1(fn))(fn, v_27988);
    env = stack[-6];
    stack[0] = v_27988;
    goto v_27904;
v_27905:
    goto v_27901;
v_27902:
    goto v_27903;
v_27904:
    if (equal(stack[-1], v_27988)) goto v_27899;
    else goto v_27900;
v_27899:
    v_27988 = stack[-4];
    goto v_27895;
v_27900:
    goto v_27916;
v_27912:
    stack[-2] = stack[0];
    goto v_27913;
v_27914:
    goto v_27923;
v_27919:
    goto v_27929;
v_27925:
    goto v_27935;
v_27931:
    v_27989 = stack[-5];
    goto v_27932;
v_27933:
    v_27988 = stack[0];
    goto v_27934;
v_27935:
    goto v_27931;
v_27932:
    goto v_27933;
v_27934:
    fn = elt(env, 4); // addf
    stack[-1] = (*qfn2(fn))(fn, v_27989, v_27988);
    env = stack[-6];
    goto v_27926;
v_27927:
    goto v_27943;
v_27939:
    goto v_27949;
v_27945:
    goto v_27946;
v_27947:
    v_27988 = stack[-5];
    fn = elt(env, 5); // negf
    v_27988 = (*qfn1(fn))(fn, v_27988);
    env = stack[-6];
    goto v_27948;
v_27949:
    goto v_27945;
v_27946:
    goto v_27947;
v_27948:
    fn = elt(env, 4); // addf
    stack[0] = (*qfn2(fn))(fn, stack[0], v_27988);
    env = stack[-6];
    goto v_27940;
v_27941:
    goto v_27960;
v_27954:
    v_27990 = elt(env, 2); // !:gi!:
    goto v_27955;
v_27956:
    v_27989 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27957;
v_27958:
    v_27988 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27959;
v_27960:
    goto v_27954;
v_27955:
    goto v_27956;
v_27957:
    goto v_27958;
v_27959:
    v_27988 = list2star(v_27990, v_27989, v_27988);
    env = stack[-6];
    goto v_27942;
v_27943:
    goto v_27939;
v_27940:
    goto v_27941;
v_27942:
    fn = elt(env, 6); // multf
    v_27988 = (*qfn2(fn))(fn, stack[0], v_27988);
    env = stack[-6];
    goto v_27928;
v_27929:
    goto v_27925;
v_27926:
    goto v_27927;
v_27928:
    fn = elt(env, 7); // gcdf
    v_27989 = (*qfn2(fn))(fn, stack[-1], v_27988);
    env = stack[-6];
    goto v_27920;
v_27921:
    v_27988 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_27922;
v_27923:
    goto v_27919;
v_27920:
    goto v_27921;
v_27922:
    fn = elt(env, 8); // quotf
    v_27988 = (*qfn2(fn))(fn, v_27989, v_27988);
    env = stack[-6];
    goto v_27915;
v_27916:
    goto v_27912;
v_27913:
    goto v_27914;
v_27915:
    fn = elt(env, 9); // quotf!-fail
    v_27988 = (*qfn2(fn))(fn, stack[-2], v_27988);
    env = stack[-6];
    stack[0] = v_27988;
    goto v_27970;
v_27966:
    goto v_27976;
v_27972:
    v_27988 = stack[-4];
    v_27989 = qcar(v_27988);
    goto v_27973;
v_27974:
    v_27988 = stack[0];
    goto v_27975;
v_27976:
    goto v_27972;
v_27973:
    goto v_27974;
v_27975:
    fn = elt(env, 6); // multf
    stack[-1] = (*qfn2(fn))(fn, v_27989, v_27988);
    env = stack[-6];
    goto v_27967;
v_27968:
    goto v_27985;
v_27981:
    v_27989 = stack[-5];
    goto v_27982;
v_27983:
    v_27988 = stack[0];
    goto v_27984;
v_27985:
    goto v_27981;
v_27982:
    goto v_27983;
v_27984:
    fn = elt(env, 6); // multf
    v_27988 = (*qfn2(fn))(fn, v_27989, v_27988);
    env = stack[-6];
    goto v_27969;
v_27970:
    goto v_27966;
v_27967:
    goto v_27968;
v_27969:
    fn = elt(env, 10); // gigcdsq
    v_27988 = (*qfn2(fn))(fn, stack[-1], v_27988);
v_27895:
    ;}  // end of a binding scope
    return onevalue(v_27988);
}



// Code for rat_abs

static LispObject CC_rat_abs(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_27902, v_27903;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27889);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_27889;
// end of prologue
    goto v_27896;
v_27892:
    v_27902 = stack[0];
    v_27902 = qcar(v_27902);
    fn = elt(env, 1); // absf
    v_27903 = (*qfn1(fn))(fn, v_27902);
    goto v_27893;
v_27894:
    v_27902 = stack[0];
    v_27902 = qcdr(v_27902);
    goto v_27895;
v_27896:
    goto v_27892;
v_27893:
    goto v_27894;
v_27895:
    return cons(v_27903, v_27902);
}



// Code for copy_vect

static LispObject CC_copy_vect(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_27921, v_27922, v_27923;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27890,v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27889,v_27890);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27890;
    stack[-1] = v_27889;
// end of prologue
    v_27921 = stack[-1];
    v_27921 = qcdr(v_27921);
    v_27921 = qcar(v_27921);
    fn = elt(env, 2); // fullcopy
    v_27921 = (*qfn1(fn))(fn, v_27921);
    env = stack[-2];
    v_27922 = stack[0];
    if (v_27922 == nil) goto v_27903;
    else goto v_27904;
v_27903:
    v_27922 = stack[-1];
    v_27922 = qcdr(v_27922);
    v_27922 = qcdr(v_27922);
    v_27922 = qcar(v_27922);
    stack[0] = v_27922;
    goto v_27902;
v_27904:
v_27902:
    goto v_27917;
v_27911:
    v_27923 = elt(env, 1); // sparsemat
    goto v_27912;
v_27913:
    v_27922 = v_27921;
    goto v_27914;
v_27915:
    v_27921 = stack[0];
    goto v_27916;
v_27917:
    goto v_27911;
v_27912:
    goto v_27913;
v_27914:
    goto v_27915;
v_27916:
    return list3(v_27923, v_27922, v_27921);
    return onevalue(v_27921);
}



// Code for nestzerop!:

static LispObject CC_nestzeropT(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_27907, v_27908;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27889);
    }
// copy arguments values to proper place
    v_27908 = v_27889;
// end of prologue
    v_27907 = v_27908;
    v_27907 = integerp(v_27907);
    if (v_27907 == nil) goto v_27894;
    v_27907 = v_27908;
    fn = elt(env, 1); // simp
    v_27907 = (*qfn1(fn))(fn, v_27907);
    goto v_27892;
v_27894:
    v_27907 = v_27908;
    v_27907 = qcdr(v_27907);
    v_27907 = qcdr(v_27907);
    v_27907 = qcdr(v_27907);
    goto v_27892;
    v_27907 = nil;
v_27892:
    v_27907 = qcar(v_27907);
    v_27907 = (v_27907 == nil ? lisp_true : nil);
    return onevalue(v_27907);
}



// Code for dipretimes

static LispObject CC_dipretimes(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_27933, v_27934, v_27935;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27934 = v_27889;
// end of prologue
v_27893:
    goto v_27902;
v_27898:
    v_27933 = v_27934;
    v_27935 = qcar(v_27933);
    goto v_27899;
v_27900:
    v_27933 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27901;
v_27902:
    goto v_27898;
v_27899:
    goto v_27900;
v_27901:
    if (v_27935 == v_27933) goto v_27896;
    else goto v_27897;
v_27896:
    v_27933 = v_27934;
    v_27933 = qcdr(v_27933);
    if (v_27933 == nil) goto v_27909;
    v_27933 = v_27934;
    v_27933 = qcdr(v_27933);
    v_27934 = v_27933;
    goto v_27893;
v_27909:
    v_27933 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27892;
    goto v_27895;
v_27897:
    v_27933 = v_27934;
    v_27933 = qcdr(v_27933);
    if (v_27933 == nil) goto v_27917;
    else goto v_27918;
v_27917:
    v_27933 = v_27934;
    v_27933 = qcar(v_27933);
    goto v_27892;
v_27918:
    goto v_27930;
v_27926:
    v_27933 = elt(env, 1); // times
    goto v_27927;
v_27928:
    goto v_27929;
v_27930:
    goto v_27926;
v_27927:
    goto v_27928;
v_27929:
    return cons(v_27933, v_27934);
v_27895:
    v_27933 = nil;
v_27892:
    return onevalue(v_27933);
}



// Code for natnump

static LispObject CC_natnump(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_27908, v_27909;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27908 = v_27889;
// end of prologue
    v_27909 = v_27908;
    v_27909 = integerp(v_27909);
    if (v_27909 == nil) goto v_27893;
    else goto v_27894;
v_27893:
    v_27908 = nil;
    goto v_27892;
v_27894:
    goto v_27905;
v_27901:
    v_27909 = v_27908;
    goto v_27902;
v_27903:
    v_27908 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27904;
v_27905:
    goto v_27901;
v_27902:
    goto v_27903;
v_27904:
        return Lgeq(nil, v_27909, v_27908);
    v_27908 = nil;
v_27892:
    return onevalue(v_27908);
}



// Code for physopsubs

static LispObject CC_physopsubs(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_28010, v_28011, v_28012;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27889);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_27889;
// end of prologue
// Binding alglist!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = nil; // alglist!*
    v_28010 = nil;
    v_28010 = ncons(v_28010);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_28010; // alglist!*
    v_28010 = stack[-1];
    fn = elt(env, 10); // physop2sq
    v_28010 = (*qfn1(fn))(fn, v_28010);
    env = stack[-3];
    stack[-1] = v_28010;
    v_28010 = qvalue(elt(env, 2)); // physoplist!*
    stack[0] = v_28010;
v_27903:
    v_28010 = stack[0];
    if (v_28010 == nil) goto v_27907;
    else goto v_27908;
v_27907:
    goto v_27902;
v_27908:
    v_28010 = stack[0];
    v_28010 = qcar(v_28010);
    v_28012 = v_28010;
    goto v_27919;
v_27915:
    v_28011 = v_28012;
    goto v_27916;
v_27917:
    v_28010 = elt(env, 3); // rtype
    goto v_27918;
v_27919:
    goto v_27915;
v_27916:
    goto v_27917;
v_27918:
    v_28010 = Lremprop(nil, v_28011, v_28010);
    env = stack[-3];
    goto v_27929;
v_27923:
    goto v_27924;
v_27925:
    v_28011 = elt(env, 4); // simpfn
    goto v_27926;
v_27927:
    v_28010 = elt(env, 5); // simpiden
    goto v_27928;
v_27929:
    goto v_27923;
v_27924:
    goto v_27925;
v_27926:
    goto v_27927;
v_27928:
    v_28010 = Lputprop(nil, 3, v_28012, v_28011, v_28010);
    env = stack[-3];
    v_28010 = stack[0];
    v_28010 = qcdr(v_28010);
    stack[0] = v_28010;
    goto v_27903;
v_27902:
    goto v_27940;
v_27936:
    v_28011 = elt(env, 6); // (dot)
    goto v_27937;
v_27938:
    v_28010 = elt(env, 7); // physopfn
    goto v_27939;
v_27940:
    goto v_27936;
v_27937:
    goto v_27938;
v_27939:
    v_28010 = Lremflag(nil, v_28011, v_28010);
    env = stack[-3];
    goto v_27950;
v_27944:
    v_28012 = elt(env, 8); // dot
    goto v_27945;
v_27946:
    v_28011 = elt(env, 4); // simpfn
    goto v_27947;
v_27948:
    v_28010 = elt(env, 5); // simpiden
    goto v_27949;
v_27950:
    goto v_27944;
v_27945:
    goto v_27946;
v_27947:
    goto v_27948;
v_27949:
    v_28010 = Lputprop(nil, 3, v_28012, v_28011, v_28010);
    env = stack[-3];
    v_28010 = stack[-1];
    fn = elt(env, 11); // subs2
    v_28010 = (*qfn1(fn))(fn, v_28010);
    env = stack[-3];
    stack[-1] = v_28010;
    v_28010 = stack[-1];
    fn = elt(env, 12); // !*q2a
    v_28010 = (*qfn1(fn))(fn, v_28010);
    env = stack[-3];
    stack[-1] = v_28010;
    v_28010 = qvalue(elt(env, 2)); // physoplist!*
    stack[0] = v_28010;
v_27961:
    v_28010 = stack[0];
    if (v_28010 == nil) goto v_27965;
    else goto v_27966;
v_27965:
    goto v_27960;
v_27966:
    v_28010 = stack[0];
    v_28010 = qcar(v_28010);
    v_28012 = v_28010;
    goto v_27977;
v_27973:
    v_28011 = v_28012;
    goto v_27974;
v_27975:
    v_28010 = elt(env, 4); // simpfn
    goto v_27976;
v_27977:
    goto v_27973;
v_27974:
    goto v_27975;
v_27976:
    v_28010 = Lremprop(nil, v_28011, v_28010);
    env = stack[-3];
    goto v_27987;
v_27981:
    goto v_27982;
v_27983:
    v_28011 = elt(env, 3); // rtype
    goto v_27984;
v_27985:
    v_28010 = elt(env, 9); // physop
    goto v_27986;
v_27987:
    goto v_27981;
v_27982:
    goto v_27983;
v_27984:
    goto v_27985;
v_27986:
    v_28010 = Lputprop(nil, 3, v_28012, v_28011, v_28010);
    env = stack[-3];
    v_28010 = stack[0];
    v_28010 = qcdr(v_28010);
    stack[0] = v_28010;
    goto v_27961;
v_27960:
    goto v_27998;
v_27994:
    v_28011 = elt(env, 8); // dot
    goto v_27995;
v_27996:
    v_28010 = elt(env, 4); // simpfn
    goto v_27997;
v_27998:
    goto v_27994;
v_27995:
    goto v_27996;
v_27997:
    v_28010 = Lremprop(nil, v_28011, v_28010);
    env = stack[-3];
    goto v_28006;
v_28002:
    v_28011 = elt(env, 6); // (dot)
    goto v_28003;
v_28004:
    v_28010 = elt(env, 7); // physopfn
    goto v_28005;
v_28006:
    goto v_28002;
v_28003:
    goto v_28004;
v_28005:
    v_28010 = Lflag(nil, v_28011, v_28010);
    v_28010 = stack[-1];
    ;}  // end of a binding scope
    return onevalue(v_28010);
}



// Code for monomcomparelex

static LispObject CC_monomcomparelex(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_28031, v_28032, v_28033;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27890,v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27889,v_27890);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27890;
    v_28031 = v_27889;
// end of prologue
    goto v_27904;
v_27900:
    v_28033 = nil;
    goto v_27901;
v_27902:
    goto v_27910;
v_27906:
    v_28032 = v_28031;
    goto v_27907;
v_27908:
    v_28031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27909;
v_27910:
    goto v_27906;
v_27907:
    goto v_27908;
v_27909:
    v_28031 = *(LispObject *)((char *)v_28032 + (CELL-TAG_VECTOR) + (((intptr_t)v_28031-TAG_FIXNUM)/(16/CELL)));
    goto v_27903;
v_27904:
    goto v_27900;
v_27901:
    goto v_27902;
v_27903:
    v_28031 = cons(v_28033, v_28031);
    env = stack[-3];
    v_28031 = Lreverse(nil, v_28031);
    env = stack[-3];
    v_28031 = qcdr(v_28031);
    stack[-2] = v_28031;
    goto v_27921;
v_27917:
    v_28033 = nil;
    goto v_27918;
v_27919:
    goto v_27927;
v_27923:
    v_28032 = stack[0];
    goto v_27924;
v_27925:
    v_28031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27926;
v_27927:
    goto v_27923;
v_27924:
    goto v_27925;
v_27926:
    v_28031 = *(LispObject *)((char *)v_28032 + (CELL-TAG_VECTOR) + (((intptr_t)v_28031-TAG_FIXNUM)/(16/CELL)));
    goto v_27920;
v_27921:
    goto v_27917;
v_27918:
    goto v_27919;
v_27920:
    v_28031 = cons(v_28033, v_28031);
    env = stack[-3];
    v_28031 = Lreverse(nil, v_28031);
    env = stack[-3];
    v_28031 = qcdr(v_28031);
    stack[-1] = v_28031;
    v_28031 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_28031;
v_27935:
    v_28031 = stack[-2];
    v_28031 = qcar(v_28031);
    if (v_28031 == nil) goto v_27938;
    v_28031 = stack[-1];
    v_28031 = qcar(v_28031);
    if (v_28031 == nil) goto v_27938;
    goto v_27939;
v_27938:
    goto v_27934;
v_27939:
    goto v_27956;
v_27952:
    v_28031 = stack[-2];
    v_28032 = qcar(v_28031);
    goto v_27953;
v_27954:
    v_28031 = stack[-1];
    v_28031 = qcar(v_28031);
    goto v_27955;
v_27956:
    goto v_27952;
v_27953:
    goto v_27954;
v_27955:
    v_28031 = (LispObject)lessp2(v_28032, v_28031);
    v_28031 = v_28031 ? lisp_true : nil;
    env = stack[-3];
    if (v_28031 == nil) goto v_27950;
    v_28031 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_28031;
    v_28031 = nil;
    v_28031 = ncons(v_28031);
    env = stack[-3];
    stack[-2] = v_28031;
    goto v_27948;
v_27950:
    goto v_27972;
v_27968:
    v_28031 = stack[-2];
    v_28032 = qcar(v_28031);
    goto v_27969;
v_27970:
    v_28031 = stack[-1];
    v_28031 = qcar(v_28031);
    goto v_27971;
v_27972:
    goto v_27968;
v_27969:
    goto v_27970;
v_27971:
    v_28031 = (LispObject)greaterp2(v_28032, v_28031);
    v_28031 = v_28031 ? lisp_true : nil;
    env = stack[-3];
    if (v_28031 == nil) goto v_27966;
    v_28031 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[0] = v_28031;
    v_28031 = nil;
    v_28031 = ncons(v_28031);
    env = stack[-3];
    stack[-2] = v_28031;
    goto v_27948;
v_27966:
    v_28031 = stack[-2];
    v_28031 = qcdr(v_28031);
    stack[-2] = v_28031;
    v_28031 = stack[-1];
    v_28031 = qcdr(v_28031);
    stack[-1] = v_28031;
    goto v_27948;
v_27948:
    goto v_27935;
v_27934:
    goto v_28000;
v_27996:
    v_28032 = stack[0];
    goto v_27997;
v_27998:
    v_28031 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27999;
v_28000:
    goto v_27996;
v_27997:
    goto v_27998;
v_27999:
    if (v_28032 == v_28031) goto v_27994;
    else goto v_27995;
v_27994:
    v_28031 = stack[-2];
    v_28031 = qcar(v_28031);
    goto v_27993;
v_27995:
    v_28031 = nil;
    goto v_27993;
    v_28031 = nil;
v_27993:
    if (v_28031 == nil) goto v_27991;
    v_28031 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_28031;
    goto v_27989;
v_27991:
    goto v_28020;
v_28016:
    v_28032 = stack[0];
    goto v_28017;
v_28018:
    v_28031 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28019;
v_28020:
    goto v_28016;
v_28017:
    goto v_28018;
v_28019:
    if (v_28032 == v_28031) goto v_28014;
    else goto v_28015;
v_28014:
    v_28031 = stack[-1];
    v_28031 = qcar(v_28031);
    goto v_28013;
v_28015:
    v_28031 = nil;
    goto v_28013;
    v_28031 = nil;
v_28013:
    if (v_28031 == nil) goto v_28011;
    v_28031 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[0] = v_28031;
    goto v_27989;
v_28011:
v_27989:
    v_28031 = stack[0];
    return onevalue(v_28031);
}



// Code for my_freeof

static LispObject CC_my_freeof(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_27918, v_27919, v_27920;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27890,v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27889,v_27890);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27890;
    stack[-1] = v_27889;
// end of prologue
    goto v_27901;
v_27897:
    v_27919 = stack[0];
    goto v_27898;
v_27899:
    v_27918 = stack[-1];
    goto v_27900;
v_27901:
    goto v_27897;
v_27898:
    goto v_27899;
v_27900:
    fn = elt(env, 2); // smember
    v_27918 = (*qfn2(fn))(fn, v_27919, v_27918);
    env = stack[-2];
    if (v_27918 == nil) goto v_27894;
    else goto v_27895;
v_27894:
    goto v_27911;
v_27905:
    v_27920 = qvalue(elt(env, 1)); // depl!*
    goto v_27906;
v_27907:
    v_27919 = stack[-1];
    goto v_27908;
v_27909:
    v_27918 = stack[0];
    goto v_27910;
v_27911:
    goto v_27905;
v_27906:
    goto v_27907;
v_27908:
    goto v_27909;
v_27910:
    {
        fn = elt(env, 3); // freeofdepl
        return (*qfnn(fn))(fn, 3, v_27920, v_27919, v_27918);
    }
v_27895:
    v_27918 = nil;
    goto v_27893;
    v_27918 = nil;
v_27893:
    return onevalue(v_27918);
}



// Code for dvfsf_ppolyp

static LispObject CC_dvfsf_ppolyp(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_27930, v_27931;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27889);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_27931 = v_27889;
// end of prologue
    v_27930 = v_27931;
    if (!consp(v_27930)) goto v_27900;
    else goto v_27901;
v_27900:
    v_27930 = lisp_true;
    goto v_27899;
v_27901:
    v_27930 = v_27931;
    v_27930 = qcar(v_27930);
    v_27930 = (consp(v_27930) ? nil : lisp_true);
    goto v_27899;
    v_27930 = nil;
v_27899:
    if (v_27930 == nil) goto v_27897;
    v_27930 = lisp_true;
    goto v_27893;
v_27897:
    v_27930 = v_27931;
    fn = elt(env, 2); // kernels
    v_27930 = (*qfn1(fn))(fn, v_27930);
    env = stack[0];
    v_27931 = v_27930;
    v_27930 = v_27931;
    v_27930 = qcdr(v_27930);
    if (v_27930 == nil) goto v_27914;
    else goto v_27915;
v_27914:
    goto v_27922;
v_27918:
    v_27930 = v_27931;
    v_27930 = qcar(v_27930);
    goto v_27919;
v_27920:
    v_27931 = elt(env, 1); // p
    goto v_27921;
v_27922:
    goto v_27918;
v_27919:
    goto v_27920;
v_27921:
    v_27930 = (v_27930 == v_27931 ? lisp_true : nil);
    goto v_27913;
v_27915:
    v_27930 = nil;
    goto v_27913;
    v_27930 = nil;
v_27913:
v_27893:
    return onevalue(v_27930);
}



// Code for parfool

static LispObject CC_parfool(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_27932, v_27933, v_27934;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27889);
    }
// copy arguments values to proper place
    v_27934 = v_27889;
// end of prologue
    v_27932 = v_27934;
    v_27932 = qcar(v_27932);
    if (v_27932 == nil) goto v_27893;
    else goto v_27894;
v_27893:
    v_27932 = lisp_true;
    goto v_27892;
v_27894:
    v_27932 = v_27934;
    v_27932 = qcar(v_27932);
    if (is_number(v_27932)) goto v_27900;
    else goto v_27899;
v_27900:
    goto v_27912;
v_27908:
    v_27932 = v_27934;
    v_27933 = qcdr(v_27932);
    goto v_27909;
v_27910:
    v_27932 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27911;
v_27912:
    goto v_27908;
v_27909:
    goto v_27910;
v_27911:
    if (v_27933 == v_27932) goto v_27906;
    else goto v_27907;
v_27906:
    goto v_27921;
v_27917:
    v_27932 = v_27934;
    v_27933 = qcar(v_27932);
    goto v_27918;
v_27919:
    v_27932 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27920;
v_27921:
    goto v_27917;
v_27918:
    goto v_27919;
v_27920:
    v_27932 = (LispObject)lessp2(v_27933, v_27932);
    v_27932 = v_27932 ? lisp_true : nil;
    goto v_27905;
v_27907:
    v_27932 = nil;
    goto v_27905;
    v_27932 = nil;
v_27905:
    if (v_27932 == nil) goto v_27899;
    v_27932 = lisp_true;
    goto v_27892;
v_27899:
    v_27932 = nil;
    goto v_27892;
    v_27932 = nil;
v_27892:
    return onevalue(v_27932);
}



// Code for groebcplistmerge

static LispObject CC_groebcplistmerge(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_27960, v_27961;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27890,v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27889,v_27890);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_27890;
    stack[-2] = v_27889;
// end of prologue
    v_27960 = stack[-2];
    if (v_27960 == nil) goto v_27899;
    else goto v_27900;
v_27899:
    v_27960 = stack[-1];
    goto v_27896;
v_27900:
    v_27960 = stack[-1];
    if (v_27960 == nil) goto v_27905;
    else goto v_27906;
v_27905:
    v_27960 = stack[-2];
    goto v_27896;
v_27906:
    v_27960 = stack[-2];
    v_27960 = qcar(v_27960);
    stack[-3] = v_27960;
    v_27960 = stack[-1];
    v_27960 = qcar(v_27960);
    stack[0] = v_27960;
    goto v_27918;
v_27914:
    v_27961 = stack[-3];
    goto v_27915;
v_27916:
    v_27960 = stack[0];
    goto v_27917;
v_27918:
    goto v_27914;
v_27915:
    goto v_27916;
v_27917:
    fn = elt(env, 1); // groebcpcompless!?
    v_27960 = (*qfn2(fn))(fn, v_27961, v_27960);
    env = stack[-4];
    if (v_27960 == nil) goto v_27924;
    goto v_27931;
v_27927:
    stack[0] = stack[-3];
    goto v_27928;
v_27929:
    goto v_27938;
v_27934:
    v_27960 = stack[-2];
    v_27961 = qcdr(v_27960);
    goto v_27935;
v_27936:
    v_27960 = stack[-1];
    goto v_27937;
v_27938:
    goto v_27934;
v_27935:
    goto v_27936;
v_27937:
    v_27960 = CC_groebcplistmerge(elt(env, 0), v_27961, v_27960);
    goto v_27930;
v_27931:
    goto v_27927;
v_27928:
    goto v_27929;
v_27930:
    {
        LispObject v_27966 = stack[0];
        return cons(v_27966, v_27960);
    }
v_27924:
    goto v_27949;
v_27945:
    goto v_27946;
v_27947:
    goto v_27956;
v_27952:
    v_27961 = stack[-2];
    goto v_27953;
v_27954:
    v_27960 = stack[-1];
    v_27960 = qcdr(v_27960);
    goto v_27955;
v_27956:
    goto v_27952;
v_27953:
    goto v_27954;
v_27955:
    v_27960 = CC_groebcplistmerge(elt(env, 0), v_27961, v_27960);
    goto v_27948;
v_27949:
    goto v_27945;
v_27946:
    goto v_27947;
v_27948:
    {
        LispObject v_27967 = stack[0];
        return cons(v_27967, v_27960);
    }
    v_27960 = nil;
v_27896:
    return onevalue(v_27960);
}



// Code for gfquotient

static LispObject CC_gfquotient(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_27916, v_27917, v_27918;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27917 = v_27890;
    v_27918 = v_27889;
// end of prologue
    v_27916 = v_27918;
    v_27916 = qcar(v_27916);
    if (!consp(v_27916)) goto v_27894;
    else goto v_27895;
v_27894:
    goto v_27903;
v_27899:
    v_27916 = v_27918;
    goto v_27900;
v_27901:
    goto v_27902;
v_27903:
    goto v_27899;
v_27900:
    goto v_27901;
v_27902:
    {
        fn = elt(env, 1); // gffquot
        return (*qfn2(fn))(fn, v_27916, v_27917);
    }
v_27895:
    goto v_27913;
v_27909:
    v_27916 = v_27918;
    goto v_27910;
v_27911:
    goto v_27912;
v_27913:
    goto v_27909;
v_27910:
    goto v_27911;
v_27912:
    {
        fn = elt(env, 2); // gbfquot
        return (*qfn2(fn))(fn, v_27916, v_27917);
    }
    v_27916 = nil;
    return onevalue(v_27916);
}



// Code for mkdmoderr

static LispObject CC_mkdmoderr(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_27915;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27890,v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27889,v_27890);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_27890;
    v_27915 = v_27889;
// end of prologue
    goto v_27899;
v_27893:
    stack[-4] = elt(env, 1); // lambda
    goto v_27894;
v_27895:
    stack[-2] = elt(env, 2); // (!*x!*)
    goto v_27896;
v_27897:
    goto v_27909;
v_27903:
    stack[-1] = elt(env, 3); // dmoderr
    goto v_27904;
v_27905:
    stack[0] = Lmkquote(nil, v_27915);
    env = stack[-5];
    goto v_27906;
v_27907:
    v_27915 = stack[-3];
    v_27915 = Lmkquote(nil, v_27915);
    env = stack[-5];
    goto v_27908;
v_27909:
    goto v_27903;
v_27904:
    goto v_27905;
v_27906:
    goto v_27907;
v_27908:
    v_27915 = list3(stack[-1], stack[0], v_27915);
    goto v_27898;
v_27899:
    goto v_27893;
v_27894:
    goto v_27895;
v_27896:
    goto v_27897;
v_27898:
    {
        LispObject v_27921 = stack[-4];
        LispObject v_27922 = stack[-2];
        return list3(v_27921, v_27922, v_27915);
    }
}



// Code for indordln

static LispObject CC_indordln(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_27931, v_27932;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27889);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_27932 = v_27889;
// end of prologue
    v_27931 = v_27932;
    if (v_27931 == nil) goto v_27893;
    else goto v_27894;
v_27893:
    v_27931 = nil;
    goto v_27892;
v_27894:
    v_27931 = v_27932;
    v_27931 = qcdr(v_27931);
    if (v_27931 == nil) goto v_27897;
    else goto v_27898;
v_27897:
    v_27931 = v_27932;
    goto v_27892;
v_27898:
    v_27931 = v_27932;
    v_27931 = qcdr(v_27931);
    v_27931 = qcdr(v_27931);
    if (v_27931 == nil) goto v_27902;
    else goto v_27903;
v_27902:
    goto v_27912;
v_27908:
    v_27931 = v_27932;
    v_27931 = qcar(v_27931);
    goto v_27909;
v_27910:
    v_27932 = qcdr(v_27932);
    v_27932 = qcar(v_27932);
    goto v_27911;
v_27912:
    goto v_27908;
v_27909:
    goto v_27910;
v_27911:
    {
        fn = elt(env, 1); // indordl2
        return (*qfn2(fn))(fn, v_27931, v_27932);
    }
v_27903:
    goto v_27925;
v_27921:
    v_27931 = v_27932;
    stack[0] = qcar(v_27931);
    goto v_27922;
v_27923:
    v_27931 = v_27932;
    v_27931 = qcdr(v_27931);
    v_27931 = CC_indordln(elt(env, 0), v_27931);
    env = stack[-1];
    goto v_27924;
v_27925:
    goto v_27921;
v_27922:
    goto v_27923;
v_27924:
    {
        LispObject v_27934 = stack[0];
        fn = elt(env, 2); // indordlad
        return (*qfn2(fn))(fn, v_27934, v_27931);
    }
    v_27931 = nil;
v_27892:
    return onevalue(v_27931);
}



// Code for listquotient

static LispObject CC_listquotient(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_28109, v_28110, v_28111;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27890,v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27889,v_27890);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_27890;
    stack[0] = v_27889;
// end of prologue
    goto v_27901;
v_27897:
    v_28109 = stack[0];
    v_28110 = qcar(v_28109);
    goto v_27898;
v_27899:
    v_28109 = stack[-4];
    goto v_27900;
v_27901:
    goto v_27897;
v_27898:
    goto v_27899;
v_27900:
    fn = elt(env, 3); // reval1
    v_28109 = (*qfn2(fn))(fn, v_28110, v_28109);
    env = stack[-7];
    stack[-3] = v_28109;
    goto v_27910;
v_27906:
    v_28109 = stack[0];
    v_28109 = qcdr(v_28109);
    v_28110 = qcar(v_28109);
    goto v_27907;
v_27908:
    v_28109 = stack[-4];
    goto v_27909;
v_27910:
    goto v_27906;
v_27907:
    goto v_27908;
v_27909:
    fn = elt(env, 3); // reval1
    v_28109 = (*qfn2(fn))(fn, v_28110, v_28109);
    env = stack[-7];
    stack[-6] = v_28109;
    goto v_27920;
v_27916:
    stack[-5] = elt(env, 1); // list
    goto v_27917;
v_27918:
    goto v_27931;
v_27927:
    v_28110 = stack[-3];
    goto v_27928;
v_27929:
    v_28109 = elt(env, 1); // list
    goto v_27930;
v_27931:
    goto v_27927;
v_27928:
    goto v_27929;
v_27930:
    if (!consp(v_28110)) goto v_27924;
    v_28110 = qcar(v_28110);
    if (v_28110 == v_28109) goto v_27925;
v_27924:
    v_28109 = stack[-6];
    v_28109 = qcdr(v_28109);
    stack[-6] = v_28109;
    v_28109 = stack[-6];
    if (v_28109 == nil) goto v_27944;
    else goto v_27945;
v_27944:
    v_28109 = nil;
    goto v_27938;
v_27945:
    v_28109 = stack[-6];
    v_28109 = qcar(v_28109);
    goto v_27957;
v_27953:
    goto v_27965;
v_27959:
    v_28111 = elt(env, 2); // quotient
    goto v_27960;
v_27961:
    v_28110 = stack[-3];
    goto v_27962;
v_27963:
    goto v_27964;
v_27965:
    goto v_27959;
v_27960:
    goto v_27961;
v_27962:
    goto v_27963;
v_27964:
    v_28110 = list3(v_28111, v_28110, v_28109);
    env = stack[-7];
    goto v_27954;
v_27955:
    v_28109 = stack[-4];
    goto v_27956;
v_27957:
    goto v_27953;
v_27954:
    goto v_27955;
v_27956:
    fn = elt(env, 3); // reval1
    v_28109 = (*qfn2(fn))(fn, v_28110, v_28109);
    env = stack[-7];
    v_28109 = ncons(v_28109);
    env = stack[-7];
    stack[-1] = v_28109;
    stack[-2] = v_28109;
v_27939:
    v_28109 = stack[-6];
    v_28109 = qcdr(v_28109);
    stack[-6] = v_28109;
    v_28109 = stack[-6];
    if (v_28109 == nil) goto v_27974;
    else goto v_27975;
v_27974:
    v_28109 = stack[-2];
    goto v_27938;
v_27975:
    goto v_27983;
v_27979:
    stack[0] = stack[-1];
    goto v_27980;
v_27981:
    v_28109 = stack[-6];
    v_28109 = qcar(v_28109);
    goto v_27994;
v_27990:
    goto v_28002;
v_27996:
    v_28111 = elt(env, 2); // quotient
    goto v_27997;
v_27998:
    v_28110 = stack[-3];
    goto v_27999;
v_28000:
    goto v_28001;
v_28002:
    goto v_27996;
v_27997:
    goto v_27998;
v_27999:
    goto v_28000;
v_28001:
    v_28110 = list3(v_28111, v_28110, v_28109);
    env = stack[-7];
    goto v_27991;
v_27992:
    v_28109 = stack[-4];
    goto v_27993;
v_27994:
    goto v_27990;
v_27991:
    goto v_27992;
v_27993:
    fn = elt(env, 3); // reval1
    v_28109 = (*qfn2(fn))(fn, v_28110, v_28109);
    env = stack[-7];
    v_28109 = ncons(v_28109);
    env = stack[-7];
    goto v_27982;
v_27983:
    goto v_27979;
v_27980:
    goto v_27981;
v_27982:
    v_28109 = Lrplacd(nil, stack[0], v_28109);
    env = stack[-7];
    v_28109 = stack[-1];
    v_28109 = qcdr(v_28109);
    stack[-1] = v_28109;
    goto v_27939;
v_27938:
    goto v_27923;
v_27925:
    goto v_28016;
v_28012:
    v_28110 = stack[-6];
    goto v_28013;
v_28014:
    v_28109 = elt(env, 1); // list
    goto v_28015;
v_28016:
    goto v_28012;
v_28013:
    goto v_28014;
v_28015:
    if (!consp(v_28110)) goto v_28010;
    v_28110 = qcar(v_28110);
    if (v_28110 == v_28109) goto v_28009;
    else goto v_28010;
v_28009:
    goto v_28026;
v_28020:
    v_28109 = stack[-3];
    v_28111 = qcdr(v_28109);
    goto v_28021;
v_28022:
    v_28109 = stack[-6];
    v_28110 = qcdr(v_28109);
    goto v_28023;
v_28024:
    v_28109 = stack[-4];
    goto v_28025;
v_28026:
    goto v_28020;
v_28021:
    goto v_28022;
v_28023:
    goto v_28024;
v_28025:
    fn = elt(env, 4); // listquotient2
    v_28109 = (*qfnn(fn))(fn, 3, v_28111, v_28110, v_28109);
    goto v_27923;
v_28010:
    v_28109 = stack[-3];
    v_28109 = qcdr(v_28109);
    stack[-3] = v_28109;
    v_28109 = stack[-3];
    if (v_28109 == nil) goto v_28044;
    else goto v_28045;
v_28044:
    v_28109 = nil;
    goto v_28038;
v_28045:
    v_28109 = stack[-3];
    v_28109 = qcar(v_28109);
    goto v_28057;
v_28053:
    goto v_28065;
v_28059:
    v_28111 = elt(env, 2); // quotient
    goto v_28060;
v_28061:
    v_28110 = v_28109;
    goto v_28062;
v_28063:
    v_28109 = stack[-6];
    goto v_28064;
v_28065:
    goto v_28059;
v_28060:
    goto v_28061;
v_28062:
    goto v_28063;
v_28064:
    v_28110 = list3(v_28111, v_28110, v_28109);
    env = stack[-7];
    goto v_28054;
v_28055:
    v_28109 = stack[-4];
    goto v_28056;
v_28057:
    goto v_28053;
v_28054:
    goto v_28055;
v_28056:
    fn = elt(env, 3); // reval1
    v_28109 = (*qfn2(fn))(fn, v_28110, v_28109);
    env = stack[-7];
    v_28109 = ncons(v_28109);
    env = stack[-7];
    stack[-1] = v_28109;
    stack[-2] = v_28109;
v_28039:
    v_28109 = stack[-3];
    v_28109 = qcdr(v_28109);
    stack[-3] = v_28109;
    v_28109 = stack[-3];
    if (v_28109 == nil) goto v_28074;
    else goto v_28075;
v_28074:
    v_28109 = stack[-2];
    goto v_28038;
v_28075:
    goto v_28083;
v_28079:
    stack[0] = stack[-1];
    goto v_28080;
v_28081:
    v_28109 = stack[-3];
    v_28109 = qcar(v_28109);
    goto v_28094;
v_28090:
    goto v_28102;
v_28096:
    v_28111 = elt(env, 2); // quotient
    goto v_28097;
v_28098:
    v_28110 = v_28109;
    goto v_28099;
v_28100:
    v_28109 = stack[-6];
    goto v_28101;
v_28102:
    goto v_28096;
v_28097:
    goto v_28098;
v_28099:
    goto v_28100;
v_28101:
    v_28110 = list3(v_28111, v_28110, v_28109);
    env = stack[-7];
    goto v_28091;
v_28092:
    v_28109 = stack[-4];
    goto v_28093;
v_28094:
    goto v_28090;
v_28091:
    goto v_28092;
v_28093:
    fn = elt(env, 3); // reval1
    v_28109 = (*qfn2(fn))(fn, v_28110, v_28109);
    env = stack[-7];
    v_28109 = ncons(v_28109);
    env = stack[-7];
    goto v_28082;
v_28083:
    goto v_28079;
v_28080:
    goto v_28081;
v_28082:
    v_28109 = Lrplacd(nil, stack[0], v_28109);
    env = stack[-7];
    v_28109 = stack[-1];
    v_28109 = qcdr(v_28109);
    stack[-1] = v_28109;
    goto v_28039;
v_28038:
    goto v_27923;
    v_28109 = nil;
v_27923:
    goto v_27919;
v_27920:
    goto v_27916;
v_27917:
    goto v_27918;
v_27919:
    {
        LispObject v_28119 = stack[-5];
        return cons(v_28119, v_28109);
    }
    return onevalue(v_28109);
}



// Code for fs!:prin!:

static LispObject CC_fsTprinT(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_27898;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27889);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27889;
// end of prologue
    v_27898 = elt(env, 1); // "["
    fn = elt(env, 3); // prin2!*
    v_27898 = (*qfn1(fn))(fn, v_27898);
    env = stack[-1];
    v_27898 = stack[0];
    v_27898 = qcdr(v_27898);
    fn = elt(env, 4); // fs!:prin
    v_27898 = (*qfn1(fn))(fn, v_27898);
    env = stack[-1];
    v_27898 = elt(env, 2); // "]"
    {
        fn = elt(env, 3); // prin2!*
        return (*qfn1(fn))(fn, v_27898);
    }
}



// Code for groeb!=testb

static LispObject CC_groebMtestb(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_28000, v_28001;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27890,v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27889,v_27890);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27890;
    stack[-1] = v_27889;
// end of prologue
    goto v_27900;
v_27896:
    v_28000 = stack[-1];
    fn = elt(env, 1); // mo_comp
    v_28001 = (*qfn1(fn))(fn, v_28000);
    env = stack[-3];
    goto v_27897;
v_27898:
    v_28000 = stack[0];
    v_28000 = qcar(v_28000);
    goto v_27899;
v_27900:
    goto v_27896;
v_27897:
    goto v_27898;
v_27899:
    if (equal(v_28001, v_28000)) goto v_27894;
    else goto v_27895;
v_27894:
    goto v_27914;
v_27910:
    stack[-2] = stack[-1];
    goto v_27911;
v_27912:
    goto v_27921;
v_27917:
    v_28001 = stack[0];
    goto v_27918;
v_27919:
    v_28000 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_27920;
v_27921:
    goto v_27917;
v_27918:
    goto v_27919;
v_27920:
    fn = elt(env, 2); // nth
    v_28000 = (*qfn2(fn))(fn, v_28001, v_28000);
    env = stack[-3];
    goto v_27913;
v_27914:
    goto v_27910;
v_27911:
    goto v_27912;
v_27913:
    fn = elt(env, 3); // mo_divides!?
    v_28000 = (*qfn2(fn))(fn, stack[-2], v_28000);
    env = stack[-3];
    if (v_28000 == nil) goto v_27907;
    else goto v_27908;
v_27907:
    v_28000 = nil;
    goto v_27906;
v_27908:
    goto v_27936;
v_27932:
    goto v_27942;
v_27938:
    goto v_27950;
v_27946:
    v_28001 = stack[0];
    goto v_27947;
v_27948:
    v_28000 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_27949;
v_27950:
    goto v_27946;
v_27947:
    goto v_27948;
v_27949:
    fn = elt(env, 2); // nth
    v_28000 = (*qfn2(fn))(fn, v_28001, v_28000);
    env = stack[-3];
    fn = elt(env, 4); // bas_dpoly
    v_28000 = (*qfn1(fn))(fn, v_28000);
    env = stack[-3];
    fn = elt(env, 5); // dp_lmon
    v_28001 = (*qfn1(fn))(fn, v_28000);
    env = stack[-3];
    goto v_27939;
v_27940:
    v_28000 = stack[-1];
    goto v_27941;
v_27942:
    goto v_27938;
v_27939:
    goto v_27940;
v_27941:
    fn = elt(env, 6); // mo_lcm
    stack[-2] = (*qfn2(fn))(fn, v_28001, v_28000);
    env = stack[-3];
    goto v_27933;
v_27934:
    goto v_27959;
v_27955:
    v_28001 = stack[0];
    goto v_27956;
v_27957:
    v_28000 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_27958;
v_27959:
    goto v_27955;
v_27956:
    goto v_27957;
v_27958:
    fn = elt(env, 2); // nth
    v_28000 = (*qfn2(fn))(fn, v_28001, v_28000);
    env = stack[-3];
    goto v_27935;
v_27936:
    goto v_27932;
v_27933:
    goto v_27934;
v_27935:
    fn = elt(env, 7); // mo_equal!?
    v_28000 = (*qfn2(fn))(fn, stack[-2], v_28000);
    env = stack[-3];
    if (v_28000 == nil) goto v_27929;
    else goto v_27930;
v_27929:
    goto v_27967;
v_27963:
    goto v_27973;
v_27969:
    goto v_27981;
v_27977:
    v_28001 = stack[0];
    goto v_27978;
v_27979:
    v_28000 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_27980;
v_27981:
    goto v_27977;
v_27978:
    goto v_27979;
v_27980:
    fn = elt(env, 2); // nth
    v_28000 = (*qfn2(fn))(fn, v_28001, v_28000);
    env = stack[-3];
    fn = elt(env, 4); // bas_dpoly
    v_28000 = (*qfn1(fn))(fn, v_28000);
    env = stack[-3];
    fn = elt(env, 5); // dp_lmon
    v_28001 = (*qfn1(fn))(fn, v_28000);
    env = stack[-3];
    goto v_27970;
v_27971:
    v_28000 = stack[-1];
    goto v_27972;
v_27973:
    goto v_27969;
v_27970:
    goto v_27971;
v_27972:
    fn = elt(env, 6); // mo_lcm
    stack[-1] = (*qfn2(fn))(fn, v_28001, v_28000);
    env = stack[-3];
    goto v_27964;
v_27965:
    goto v_27990;
v_27986:
    v_28001 = stack[0];
    goto v_27987;
v_27988:
    v_28000 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_27989;
v_27990:
    goto v_27986;
v_27987:
    goto v_27988;
v_27989:
    fn = elt(env, 2); // nth
    v_28000 = (*qfn2(fn))(fn, v_28001, v_28000);
    env = stack[-3];
    goto v_27966;
v_27967:
    goto v_27963;
v_27964:
    goto v_27965;
v_27966:
    fn = elt(env, 7); // mo_equal!?
    v_28000 = (*qfn2(fn))(fn, stack[-1], v_28000);
    v_28000 = (v_28000 == nil ? lisp_true : nil);
    goto v_27928;
v_27930:
    v_28000 = nil;
    goto v_27928;
    v_28000 = nil;
v_27928:
    goto v_27906;
    v_28000 = nil;
v_27906:
    goto v_27893;
v_27895:
    v_28000 = nil;
    goto v_27893;
    v_28000 = nil;
v_27893:
    return onevalue(v_28000);
}



// Code for verify_tens_ids

static LispObject CC_verify_tens_ids(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_27943, v_27944;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27889);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_27889;
// end of prologue
    v_27943 = stack[-1];
    v_27943 = qcar(v_27943);
    v_27944 = v_27943;
    v_27943 = stack[-1];
    v_27943 = qcdr(v_27943);
    v_27943 = qcar(v_27943);
    stack[0] = v_27943;
    v_27943 = v_27944;
    fn = elt(env, 3); // extract_dummy_ids
    v_27943 = (*qfn1(fn))(fn, v_27943);
    env = stack[-3];
    fn = elt(env, 4); // repeats
    v_27943 = (*qfn1(fn))(fn, v_27943);
    env = stack[-3];
    if (v_27943 == nil) goto v_27904;
    else goto v_27902;
v_27904:
    v_27943 = stack[0];
    fn = elt(env, 3); // extract_dummy_ids
    v_27943 = (*qfn1(fn))(fn, v_27943);
    env = stack[-3];
    fn = elt(env, 4); // repeats
    v_27943 = (*qfn1(fn))(fn, v_27943);
    env = stack[-3];
    if (v_27943 == nil) goto v_27908;
    else goto v_27902;
v_27908:
    goto v_27903;
v_27902:
    goto v_27919;
v_27913:
    stack[-2] = elt(env, 1); // cantens
    goto v_27914;
v_27915:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_27916;
v_27917:
    goto v_27927;
v_27923:
    goto v_27933;
v_27929:
    v_27943 = stack[-1];
    v_27944 = qcar(v_27943);
    goto v_27930;
v_27931:
    v_27943 = stack[-1];
    v_27943 = qcdr(v_27943);
    v_27943 = qcar(v_27943);
    goto v_27932;
v_27933:
    goto v_27929;
v_27930:
    goto v_27931;
v_27932:
    v_27944 = list2(v_27944, v_27943);
    env = stack[-3];
    goto v_27924;
v_27925:
    v_27943 = elt(env, 2); // "are inconsistent lists of indices"
    goto v_27926;
v_27927:
    goto v_27923;
v_27924:
    goto v_27925;
v_27926:
    v_27943 = list2(v_27944, v_27943);
    env = stack[-3];
    goto v_27918;
v_27919:
    goto v_27913;
v_27914:
    goto v_27915;
v_27916:
    goto v_27917;
v_27918:
    fn = elt(env, 5); // rerror
    v_27943 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_27943);
    goto v_27901;
v_27903:
    v_27943 = lisp_true;
    goto v_27894;
v_27901:
    v_27943 = nil;
v_27894:
    return onevalue(v_27943);
}



// Code for nonlnr

static LispObject CC_nonlnr(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_28003, v_28004;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27890,v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27889,v_27890);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27890;
    stack[-1] = v_27889;
// end of prologue
v_27888:
    v_28003 = stack[-1];
    if (!consp(v_28003)) goto v_27898;
    else goto v_27899;
v_27898:
    v_28003 = lisp_true;
    goto v_27897;
v_27899:
    v_28003 = stack[-1];
    v_28003 = qcar(v_28003);
    v_28003 = (consp(v_28003) ? nil : lisp_true);
    goto v_27897;
    v_28003 = nil;
v_27897:
    if (v_28003 == nil) goto v_27895;
    v_28003 = nil;
    goto v_27893;
v_27895:
    goto v_27914;
v_27910:
    v_28003 = stack[-1];
    v_28003 = qcar(v_28003);
    v_28003 = qcar(v_28003);
    v_28004 = qcar(v_28003);
    goto v_27911;
v_27912:
    v_28003 = stack[0];
    goto v_27913;
v_27914:
    goto v_27910;
v_27911:
    goto v_27912;
v_27913:
    v_28003 = Lmember(nil, v_28004, v_28003);
    if (v_28003 == nil) goto v_27909;
    goto v_27929;
v_27925:
    v_28003 = stack[-1];
    v_28003 = qcar(v_28003);
    v_28003 = qcar(v_28003);
    v_28004 = qcdr(v_28003);
    goto v_27926;
v_27927:
    v_28003 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27928;
v_27929:
    goto v_27925;
v_27926:
    goto v_27927;
v_27928:
    v_28003 = (LispObject)greaterp2(v_28004, v_28003);
    v_28003 = v_28003 ? lisp_true : nil;
    env = stack[-2];
    if (v_28003 == nil) goto v_27923;
    else goto v_27922;
v_27923:
    goto v_27944;
v_27940:
    v_28003 = stack[-1];
    v_28003 = qcar(v_28003);
    v_28004 = qcdr(v_28003);
    goto v_27941;
v_27942:
    v_28003 = stack[0];
    goto v_27943;
v_27944:
    goto v_27940;
v_27941:
    goto v_27942;
v_27943:
    fn = elt(env, 1); // freeofl
    v_28003 = (*qfn2(fn))(fn, v_28004, v_28003);
    env = stack[-2];
    if (v_28003 == nil) goto v_27937;
    else goto v_27938;
v_27937:
    v_28003 = lisp_true;
    goto v_27936;
v_27938:
    goto v_27957;
v_27953:
    v_28003 = stack[-1];
    v_28004 = qcdr(v_28003);
    goto v_27954;
v_27955:
    v_28003 = stack[0];
    goto v_27956;
v_27957:
    goto v_27953;
v_27954:
    goto v_27955;
v_27956:
    stack[-1] = v_28004;
    stack[0] = v_28003;
    goto v_27888;
    v_28003 = nil;
v_27936:
v_27922:
    goto v_27893;
v_27909:
    goto v_27972;
v_27968:
    v_28003 = stack[-1];
    v_28003 = qcar(v_28003);
    v_28003 = qcar(v_28003);
    v_28004 = qcar(v_28003);
    goto v_27969;
v_27970:
    v_28003 = stack[0];
    goto v_27971;
v_27972:
    goto v_27968;
v_27969:
    goto v_27970;
v_27971:
    fn = elt(env, 1); // freeofl
    v_28003 = (*qfn2(fn))(fn, v_28004, v_28003);
    env = stack[-2];
    if (v_28003 == nil) goto v_27965;
    else goto v_27966;
v_27965:
    v_28003 = lisp_true;
    goto v_27964;
v_27966:
    goto v_27989;
v_27985:
    v_28003 = stack[-1];
    v_28003 = qcar(v_28003);
    v_28004 = qcdr(v_28003);
    goto v_27986;
v_27987:
    v_28003 = stack[0];
    goto v_27988;
v_27989:
    goto v_27985;
v_27986:
    goto v_27987;
v_27988:
    v_28003 = CC_nonlnr(elt(env, 0), v_28004, v_28003);
    env = stack[-2];
    if (v_28003 == nil) goto v_27983;
    else goto v_27982;
v_27983:
    goto v_27999;
v_27995:
    v_28003 = stack[-1];
    v_28004 = qcdr(v_28003);
    goto v_27996;
v_27997:
    v_28003 = stack[0];
    goto v_27998;
v_27999:
    goto v_27995;
v_27996:
    goto v_27997;
v_27998:
    stack[-1] = v_28004;
    stack[0] = v_28003;
    goto v_27888;
v_27982:
    goto v_27964;
    v_28003 = nil;
v_27964:
    goto v_27893;
    v_28003 = nil;
v_27893:
    return onevalue(v_28003);
}



// Code for bfminus

static LispObject CC_bfminus(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_27902, v_27903;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27903 = v_27889;
// end of prologue
    v_27902 = v_27903;
    if (!consp(v_27902)) goto v_27893;
    else goto v_27894;
v_27893:
    v_27902 = v_27903;
    return negate(v_27902);
v_27894:
    v_27902 = v_27903;
    {
        fn = elt(env, 1); // minus!:
        return (*qfn1(fn))(fn, v_27902);
    }
    v_27902 = nil;
    return onevalue(v_27902);
}



// Code for no_of_tm_sf_limited

static LispObject CC_no_of_tm_sf_limited(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_27960, v_27961;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27890,v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27889,v_27890);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27890;
    stack[-1] = v_27889;
// end of prologue
    v_27960 = stack[-1];
    if (v_27960 == nil) goto v_27894;
    else goto v_27895;
v_27894:
    v_27960 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27893;
v_27895:
    v_27960 = stack[-1];
    v_27960 = Lconsp(nil, v_27960);
    env = stack[-3];
    if (v_27960 == nil) goto v_27902;
    else goto v_27903;
v_27902:
    v_27960 = lisp_true;
    goto v_27901;
v_27903:
    v_27960 = stack[-1];
    v_27960 = qcar(v_27960);
    v_27960 = Lconsp(nil, v_27960);
    env = stack[-3];
    v_27960 = (v_27960 == nil ? lisp_true : nil);
    goto v_27901;
    v_27960 = nil;
v_27901:
    if (v_27960 == nil) goto v_27899;
    v_27960 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27893;
v_27899:
    goto v_27924;
v_27920:
    v_27960 = stack[-1];
    v_27960 = qcar(v_27960);
    v_27961 = qcdr(v_27960);
    goto v_27921;
v_27922:
    v_27960 = stack[0];
    goto v_27923;
v_27924:
    goto v_27920;
v_27921:
    goto v_27922;
v_27923:
    v_27960 = CC_no_of_tm_sf_limited(elt(env, 0), v_27961, v_27960);
    env = stack[-3];
    stack[-2] = v_27960;
    goto v_27938;
v_27934:
    v_27961 = stack[-2];
    goto v_27935;
v_27936:
    v_27960 = stack[0];
    goto v_27937;
v_27938:
    goto v_27934;
v_27935:
    goto v_27936;
v_27937:
    v_27960 = (LispObject)greaterp2(v_27961, v_27960);
    v_27960 = v_27960 ? lisp_true : nil;
    env = stack[-3];
    if (v_27960 == nil) goto v_27932;
    v_27960 = stack[-2];
    goto v_27930;
v_27932:
    goto v_27949;
v_27945:
    goto v_27946;
v_27947:
    goto v_27956;
v_27952:
    v_27960 = stack[-1];
    v_27961 = qcdr(v_27960);
    goto v_27953;
v_27954:
    v_27960 = stack[0];
    goto v_27955;
v_27956:
    goto v_27952;
v_27953:
    goto v_27954;
v_27955:
    v_27960 = CC_no_of_tm_sf_limited(elt(env, 0), v_27961, v_27960);
    goto v_27948;
v_27949:
    goto v_27945;
v_27946:
    goto v_27947;
v_27948:
    {
        LispObject v_27965 = stack[-2];
        return plus2(v_27965, v_27960);
    }
    v_27960 = nil;
v_27930:
    goto v_27893;
    v_27960 = nil;
v_27893:
    return onevalue(v_27960);
}



// Code for dfdeg

static LispObject CC_dfdeg(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_27927, v_27928;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27927 = v_27890;
    v_27928 = v_27889;
// end of prologue
    goto v_27900;
v_27896:
    goto v_27897;
v_27898:
    goto v_27899;
v_27900:
    goto v_27896;
v_27897:
    goto v_27898;
v_27899:
    v_27927 = Lmember(nil, v_27927, v_27928);
    v_27928 = v_27927;
    if (v_27927 == nil) goto v_27894;
    else goto v_27895;
v_27894:
    v_27927 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27893;
v_27895:
    v_27927 = v_27928;
    v_27927 = qcdr(v_27927);
    if (v_27927 == nil) goto v_27909;
    else goto v_27910;
v_27909:
    v_27927 = lisp_true;
    goto v_27908;
v_27910:
    v_27927 = v_27928;
    v_27927 = qcdr(v_27927);
    v_27927 = qcar(v_27927);
    v_27927 = integerp(v_27927);
    v_27927 = (v_27927 == nil ? lisp_true : nil);
    goto v_27908;
    v_27927 = nil;
v_27908:
    if (v_27927 == nil) goto v_27906;
    v_27927 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27893;
v_27906:
    v_27927 = v_27928;
    v_27927 = qcdr(v_27927);
    v_27927 = qcar(v_27927);
    goto v_27893;
    v_27927 = nil;
v_27893:
    return onevalue(v_27927);
}



// Code for makecoeffpairs

static LispObject CC_makecoeffpairs(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27910, v_27911, v_27912, v_27913;
    LispObject fn;
    LispObject v_27892, v_27891, v_27890, v_27889;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "makecoeffpairs");
    va_start(aa, nargs);
    v_27889 = va_arg(aa, LispObject);
    v_27890 = va_arg(aa, LispObject);
    v_27891 = va_arg(aa, LispObject);
    v_27892 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_27892,v_27891,v_27890,v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_27889,v_27890,v_27891,v_27892);
    }
// copy arguments values to proper place
    v_27910 = v_27892;
    v_27911 = v_27891;
    v_27912 = v_27890;
    v_27913 = v_27889;
// end of prologue
    goto v_27904;
v_27896:
    goto v_27897;
v_27898:
    goto v_27899;
v_27900:
    goto v_27901;
v_27902:
    goto v_27903;
v_27904:
    goto v_27896;
v_27897:
    goto v_27898;
v_27899:
    goto v_27900;
v_27901:
    goto v_27902;
v_27903:
    fn = elt(env, 1); // makecoeffpairs1
    v_27910 = (*qfnn(fn))(fn, 4, v_27913, v_27912, v_27911, v_27910);
    v_27910 = qcdr(v_27910);
        return Lnreverse(nil, v_27910);
}



// Code for cl_sordp

static LispObject CC_cl_sordp(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_29278, v_29279, v_29280, v_29281;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27890,v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27889,v_27890);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27890;
    stack[-1] = v_27889;
// end of prologue
v_27888:
    v_29278 = stack[-1];
    if (!consp(v_29278)) goto v_27898;
    else goto v_27899;
v_27898:
    v_29278 = stack[-1];
    goto v_27897;
v_27899:
    v_29278 = stack[-1];
    v_29278 = qcar(v_29278);
    goto v_27897;
    v_29278 = nil;
v_27897:
    v_29281 = v_29278;
    v_29278 = stack[0];
    if (!consp(v_29278)) goto v_27908;
    else goto v_27909;
v_27908:
    v_29278 = stack[0];
    goto v_27907;
v_27909:
    v_29278 = stack[0];
    v_29278 = qcar(v_29278);
    goto v_27907;
    v_29278 = nil;
v_27907:
    v_29280 = v_29278;
    goto v_27936;
v_27932:
    v_29279 = v_29281;
    goto v_27933;
v_27934:
    v_29278 = elt(env, 1); // true
    goto v_27935;
v_27936:
    goto v_27932;
v_27933:
    goto v_27934;
v_27935:
    if (v_29279 == v_29278) goto v_27930;
    else goto v_27931;
v_27930:
    v_29278 = lisp_true;
    goto v_27929;
v_27931:
    goto v_27946;
v_27942:
    v_29279 = v_29281;
    goto v_27943;
v_27944:
    v_29278 = elt(env, 2); // false
    goto v_27945;
v_27946:
    goto v_27942;
v_27943:
    goto v_27944;
v_27945:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_27929;
    v_29278 = nil;
v_27929:
    if (v_29278 == nil) goto v_27927;
    v_29278 = lisp_true;
    goto v_27925;
v_27927:
    goto v_27973;
v_27969:
    v_29279 = v_29281;
    goto v_27970;
v_27971:
    v_29278 = elt(env, 3); // or
    goto v_27972;
v_27973:
    goto v_27969;
v_27970:
    goto v_27971;
v_27972:
    if (v_29279 == v_29278) goto v_27967;
    else goto v_27968;
v_27967:
    v_29278 = lisp_true;
    goto v_27966;
v_27968:
    goto v_27983;
v_27979:
    v_29279 = v_29281;
    goto v_27980;
v_27981:
    v_29278 = elt(env, 4); // and
    goto v_27982;
v_27983:
    goto v_27979;
v_27980:
    goto v_27981;
v_27982:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_27966;
    v_29278 = nil;
v_27966:
    if (v_29278 == nil) goto v_27964;
    v_29278 = lisp_true;
    goto v_27962;
v_27964:
    goto v_27994;
v_27990:
    v_29279 = v_29281;
    goto v_27991;
v_27992:
    v_29278 = elt(env, 5); // not
    goto v_27993;
v_27994:
    goto v_27990;
v_27991:
    goto v_27992;
v_27993:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_27962;
    v_29278 = nil;
v_27962:
    if (v_29278 == nil) goto v_27960;
    v_29278 = lisp_true;
    goto v_27958;
v_27960:
    goto v_28009;
v_28005:
    v_29279 = v_29281;
    goto v_28006;
v_28007:
    v_29278 = elt(env, 6); // impl
    goto v_28008;
v_28009:
    goto v_28005;
v_28006:
    goto v_28007;
v_28008:
    if (v_29279 == v_29278) goto v_28003;
    else goto v_28004;
v_28003:
    v_29278 = lisp_true;
    goto v_28002;
v_28004:
    goto v_28023;
v_28019:
    v_29279 = v_29281;
    goto v_28020;
v_28021:
    v_29278 = elt(env, 7); // repl
    goto v_28022;
v_28023:
    goto v_28019;
v_28020:
    goto v_28021;
v_28022:
    if (v_29279 == v_29278) goto v_28017;
    else goto v_28018;
v_28017:
    v_29278 = lisp_true;
    goto v_28016;
v_28018:
    goto v_28033;
v_28029:
    v_29279 = v_29281;
    goto v_28030;
v_28031:
    v_29278 = elt(env, 8); // equiv
    goto v_28032;
v_28033:
    goto v_28029;
v_28030:
    goto v_28031;
v_28032:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28016;
    v_29278 = nil;
v_28016:
    goto v_28002;
    v_29278 = nil;
v_28002:
    goto v_27958;
    v_29278 = nil;
v_27958:
    if (v_29278 == nil) goto v_27956;
    v_29278 = lisp_true;
    goto v_27954;
v_27956:
    goto v_28052;
v_28048:
    v_29279 = v_29281;
    goto v_28049;
v_28050:
    v_29278 = elt(env, 9); // ex
    goto v_28051;
v_28052:
    goto v_28048;
v_28049:
    goto v_28050;
v_28051:
    if (v_29279 == v_29278) goto v_28046;
    else goto v_28047;
v_28046:
    v_29278 = lisp_true;
    goto v_28045;
v_28047:
    goto v_28062;
v_28058:
    v_29279 = v_29281;
    goto v_28059;
v_28060:
    v_29278 = elt(env, 10); // all
    goto v_28061;
v_28062:
    goto v_28058;
v_28059:
    goto v_28060;
v_28061:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28045;
    v_29278 = nil;
v_28045:
    if (v_29278 == nil) goto v_28043;
    v_29278 = lisp_true;
    goto v_28041;
v_28043:
    goto v_28081;
v_28077:
    v_29279 = v_29281;
    goto v_28078;
v_28079:
    v_29278 = elt(env, 11); // bex
    goto v_28080;
v_28081:
    goto v_28077;
v_28078:
    goto v_28079;
v_28080:
    if (v_29279 == v_29278) goto v_28075;
    else goto v_28076;
v_28075:
    v_29278 = lisp_true;
    goto v_28074;
v_28076:
    goto v_28091;
v_28087:
    v_29279 = v_29281;
    goto v_28088;
v_28089:
    v_29278 = elt(env, 12); // ball
    goto v_28090;
v_28091:
    goto v_28087;
v_28088:
    goto v_28089;
v_28090:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28074;
    v_29278 = nil;
v_28074:
    if (v_29278 == nil) goto v_28072;
    v_29278 = lisp_true;
    goto v_28070;
v_28072:
    v_29278 = v_29281;
    if (!symbolp(v_29278)) v_29278 = nil;
    else { v_29278 = qfastgets(v_29278);
           if (v_29278 != nil) { v_29278 = elt(v_29278, 21); // rl_external
#ifdef RECORD_GET
             if (v_29278 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_29278 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_29278 == SPID_NOPROP) v_29278 = nil; }}
#endif
    goto v_28070;
    v_29278 = nil;
v_28070:
    goto v_28041;
    v_29278 = nil;
v_28041:
    goto v_27954;
    v_29278 = nil;
v_27954:
    goto v_27925;
    v_29278 = nil;
v_27925:
    if (v_29278 == nil) goto v_27922;
    else goto v_27923;
v_27922:
    goto v_28112;
v_28108:
    v_29279 = v_29280;
    goto v_28109;
v_28110:
    v_29278 = elt(env, 1); // true
    goto v_28111;
v_28112:
    goto v_28108;
v_28109:
    goto v_28110;
v_28111:
    if (v_29279 == v_29278) goto v_28106;
    else goto v_28107;
v_28106:
    v_29278 = lisp_true;
    goto v_28105;
v_28107:
    goto v_28122;
v_28118:
    v_29279 = v_29280;
    goto v_28119;
v_28120:
    v_29278 = elt(env, 2); // false
    goto v_28121;
v_28122:
    goto v_28118;
v_28119:
    goto v_28120;
v_28121:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28105;
    v_29278 = nil;
v_28105:
    if (v_29278 == nil) goto v_28103;
    v_29278 = lisp_true;
    goto v_28101;
v_28103:
    goto v_28149;
v_28145:
    v_29279 = v_29280;
    goto v_28146;
v_28147:
    v_29278 = elt(env, 3); // or
    goto v_28148;
v_28149:
    goto v_28145;
v_28146:
    goto v_28147;
v_28148:
    if (v_29279 == v_29278) goto v_28143;
    else goto v_28144;
v_28143:
    v_29278 = lisp_true;
    goto v_28142;
v_28144:
    goto v_28159;
v_28155:
    v_29279 = v_29280;
    goto v_28156;
v_28157:
    v_29278 = elt(env, 4); // and
    goto v_28158;
v_28159:
    goto v_28155;
v_28156:
    goto v_28157;
v_28158:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28142;
    v_29278 = nil;
v_28142:
    if (v_29278 == nil) goto v_28140;
    v_29278 = lisp_true;
    goto v_28138;
v_28140:
    goto v_28170;
v_28166:
    v_29279 = v_29280;
    goto v_28167;
v_28168:
    v_29278 = elt(env, 5); // not
    goto v_28169;
v_28170:
    goto v_28166;
v_28167:
    goto v_28168;
v_28169:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28138;
    v_29278 = nil;
v_28138:
    if (v_29278 == nil) goto v_28136;
    v_29278 = lisp_true;
    goto v_28134;
v_28136:
    goto v_28185;
v_28181:
    v_29279 = v_29280;
    goto v_28182;
v_28183:
    v_29278 = elt(env, 6); // impl
    goto v_28184;
v_28185:
    goto v_28181;
v_28182:
    goto v_28183;
v_28184:
    if (v_29279 == v_29278) goto v_28179;
    else goto v_28180;
v_28179:
    v_29278 = lisp_true;
    goto v_28178;
v_28180:
    goto v_28199;
v_28195:
    v_29279 = v_29280;
    goto v_28196;
v_28197:
    v_29278 = elt(env, 7); // repl
    goto v_28198;
v_28199:
    goto v_28195;
v_28196:
    goto v_28197;
v_28198:
    if (v_29279 == v_29278) goto v_28193;
    else goto v_28194;
v_28193:
    v_29278 = lisp_true;
    goto v_28192;
v_28194:
    goto v_28209;
v_28205:
    v_29279 = v_29280;
    goto v_28206;
v_28207:
    v_29278 = elt(env, 8); // equiv
    goto v_28208;
v_28209:
    goto v_28205;
v_28206:
    goto v_28207;
v_28208:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28192;
    v_29278 = nil;
v_28192:
    goto v_28178;
    v_29278 = nil;
v_28178:
    goto v_28134;
    v_29278 = nil;
v_28134:
    if (v_29278 == nil) goto v_28132;
    v_29278 = lisp_true;
    goto v_28130;
v_28132:
    goto v_28228;
v_28224:
    v_29279 = v_29280;
    goto v_28225;
v_28226:
    v_29278 = elt(env, 9); // ex
    goto v_28227;
v_28228:
    goto v_28224;
v_28225:
    goto v_28226;
v_28227:
    if (v_29279 == v_29278) goto v_28222;
    else goto v_28223;
v_28222:
    v_29278 = lisp_true;
    goto v_28221;
v_28223:
    goto v_28238;
v_28234:
    v_29279 = v_29280;
    goto v_28235;
v_28236:
    v_29278 = elt(env, 10); // all
    goto v_28237;
v_28238:
    goto v_28234;
v_28235:
    goto v_28236;
v_28237:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28221;
    v_29278 = nil;
v_28221:
    if (v_29278 == nil) goto v_28219;
    v_29278 = lisp_true;
    goto v_28217;
v_28219:
    goto v_28257;
v_28253:
    v_29279 = v_29280;
    goto v_28254;
v_28255:
    v_29278 = elt(env, 11); // bex
    goto v_28256;
v_28257:
    goto v_28253;
v_28254:
    goto v_28255;
v_28256:
    if (v_29279 == v_29278) goto v_28251;
    else goto v_28252;
v_28251:
    v_29278 = lisp_true;
    goto v_28250;
v_28252:
    goto v_28267;
v_28263:
    v_29279 = v_29280;
    goto v_28264;
v_28265:
    v_29278 = elt(env, 12); // ball
    goto v_28266;
v_28267:
    goto v_28263;
v_28264:
    goto v_28265;
v_28266:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28250;
    v_29278 = nil;
v_28250:
    if (v_29278 == nil) goto v_28248;
    v_29278 = lisp_true;
    goto v_28246;
v_28248:
    v_29278 = v_29280;
    if (!symbolp(v_29278)) v_29278 = nil;
    else { v_29278 = qfastgets(v_29278);
           if (v_29278 != nil) { v_29278 = elt(v_29278, 21); // rl_external
#ifdef RECORD_GET
             if (v_29278 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_29278 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_29278 == SPID_NOPROP) v_29278 = nil; }}
#endif
    goto v_28246;
    v_29278 = nil;
v_28246:
    goto v_28217;
    v_29278 = nil;
v_28217:
    goto v_28130;
    v_29278 = nil;
v_28130:
    goto v_28101;
    v_29278 = nil;
v_28101:
    v_29278 = (v_29278 == nil ? lisp_true : nil);
    goto v_27921;
v_27923:
    v_29278 = nil;
    goto v_27921;
    v_29278 = nil;
v_27921:
    if (v_29278 == nil) goto v_27919;
    goto v_28285;
v_28281:
    v_29279 = stack[-1];
    goto v_28282;
v_28283:
    v_29278 = stack[0];
    goto v_28284;
v_28285:
    goto v_28281;
v_28282:
    goto v_28283;
v_28284:
    {
        fn = elt(env, 13); // rl_ordatp
        return (*qfn2(fn))(fn, v_29279, v_29278);
    }
v_27919:
    goto v_28308;
v_28304:
    v_29279 = v_29281;
    goto v_28305;
v_28306:
    v_29278 = elt(env, 1); // true
    goto v_28307;
v_28308:
    goto v_28304;
v_28305:
    goto v_28306;
v_28307:
    if (v_29279 == v_29278) goto v_28302;
    else goto v_28303;
v_28302:
    v_29278 = lisp_true;
    goto v_28301;
v_28303:
    goto v_28318;
v_28314:
    v_29279 = v_29281;
    goto v_28315;
v_28316:
    v_29278 = elt(env, 2); // false
    goto v_28317;
v_28318:
    goto v_28314;
v_28315:
    goto v_28316;
v_28317:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28301;
    v_29278 = nil;
v_28301:
    if (v_29278 == nil) goto v_28299;
    v_29278 = lisp_true;
    goto v_28297;
v_28299:
    goto v_28345;
v_28341:
    v_29279 = v_29281;
    goto v_28342;
v_28343:
    v_29278 = elt(env, 3); // or
    goto v_28344;
v_28345:
    goto v_28341;
v_28342:
    goto v_28343;
v_28344:
    if (v_29279 == v_29278) goto v_28339;
    else goto v_28340;
v_28339:
    v_29278 = lisp_true;
    goto v_28338;
v_28340:
    goto v_28355;
v_28351:
    v_29279 = v_29281;
    goto v_28352;
v_28353:
    v_29278 = elt(env, 4); // and
    goto v_28354;
v_28355:
    goto v_28351;
v_28352:
    goto v_28353;
v_28354:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28338;
    v_29278 = nil;
v_28338:
    if (v_29278 == nil) goto v_28336;
    v_29278 = lisp_true;
    goto v_28334;
v_28336:
    goto v_28366;
v_28362:
    v_29279 = v_29281;
    goto v_28363;
v_28364:
    v_29278 = elt(env, 5); // not
    goto v_28365;
v_28366:
    goto v_28362;
v_28363:
    goto v_28364;
v_28365:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28334;
    v_29278 = nil;
v_28334:
    if (v_29278 == nil) goto v_28332;
    v_29278 = lisp_true;
    goto v_28330;
v_28332:
    goto v_28381;
v_28377:
    v_29279 = v_29281;
    goto v_28378;
v_28379:
    v_29278 = elt(env, 6); // impl
    goto v_28380;
v_28381:
    goto v_28377;
v_28378:
    goto v_28379;
v_28380:
    if (v_29279 == v_29278) goto v_28375;
    else goto v_28376;
v_28375:
    v_29278 = lisp_true;
    goto v_28374;
v_28376:
    goto v_28395;
v_28391:
    v_29279 = v_29281;
    goto v_28392;
v_28393:
    v_29278 = elt(env, 7); // repl
    goto v_28394;
v_28395:
    goto v_28391;
v_28392:
    goto v_28393;
v_28394:
    if (v_29279 == v_29278) goto v_28389;
    else goto v_28390;
v_28389:
    v_29278 = lisp_true;
    goto v_28388;
v_28390:
    goto v_28405;
v_28401:
    v_29279 = v_29281;
    goto v_28402;
v_28403:
    v_29278 = elt(env, 8); // equiv
    goto v_28404;
v_28405:
    goto v_28401;
v_28402:
    goto v_28403;
v_28404:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28388;
    v_29278 = nil;
v_28388:
    goto v_28374;
    v_29278 = nil;
v_28374:
    goto v_28330;
    v_29278 = nil;
v_28330:
    if (v_29278 == nil) goto v_28328;
    v_29278 = lisp_true;
    goto v_28326;
v_28328:
    goto v_28424;
v_28420:
    v_29279 = v_29281;
    goto v_28421;
v_28422:
    v_29278 = elt(env, 9); // ex
    goto v_28423;
v_28424:
    goto v_28420;
v_28421:
    goto v_28422;
v_28423:
    if (v_29279 == v_29278) goto v_28418;
    else goto v_28419;
v_28418:
    v_29278 = lisp_true;
    goto v_28417;
v_28419:
    goto v_28434;
v_28430:
    v_29279 = v_29281;
    goto v_28431;
v_28432:
    v_29278 = elt(env, 10); // all
    goto v_28433;
v_28434:
    goto v_28430;
v_28431:
    goto v_28432;
v_28433:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28417;
    v_29278 = nil;
v_28417:
    if (v_29278 == nil) goto v_28415;
    v_29278 = lisp_true;
    goto v_28413;
v_28415:
    goto v_28453;
v_28449:
    v_29279 = v_29281;
    goto v_28450;
v_28451:
    v_29278 = elt(env, 11); // bex
    goto v_28452;
v_28453:
    goto v_28449;
v_28450:
    goto v_28451;
v_28452:
    if (v_29279 == v_29278) goto v_28447;
    else goto v_28448;
v_28447:
    v_29278 = lisp_true;
    goto v_28446;
v_28448:
    goto v_28463;
v_28459:
    v_29279 = v_29281;
    goto v_28460;
v_28461:
    v_29278 = elt(env, 12); // ball
    goto v_28462;
v_28463:
    goto v_28459;
v_28460:
    goto v_28461;
v_28462:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28446;
    v_29278 = nil;
v_28446:
    if (v_29278 == nil) goto v_28444;
    v_29278 = lisp_true;
    goto v_28442;
v_28444:
    v_29278 = v_29281;
    if (!symbolp(v_29278)) v_29278 = nil;
    else { v_29278 = qfastgets(v_29278);
           if (v_29278 != nil) { v_29278 = elt(v_29278, 21); // rl_external
#ifdef RECORD_GET
             if (v_29278 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_29278 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_29278 == SPID_NOPROP) v_29278 = nil; }}
#endif
    goto v_28442;
    v_29278 = nil;
v_28442:
    goto v_28413;
    v_29278 = nil;
v_28413:
    goto v_28326;
    v_29278 = nil;
v_28326:
    goto v_28297;
    v_29278 = nil;
v_28297:
    if (v_29278 == nil) goto v_28294;
    else goto v_28295;
v_28294:
    goto v_28484;
v_28480:
    v_29279 = v_29280;
    goto v_28481;
v_28482:
    v_29278 = elt(env, 1); // true
    goto v_28483;
v_28484:
    goto v_28480;
v_28481:
    goto v_28482;
v_28483:
    if (v_29279 == v_29278) goto v_28478;
    else goto v_28479;
v_28478:
    v_29278 = lisp_true;
    goto v_28477;
v_28479:
    goto v_28494;
v_28490:
    v_29279 = v_29280;
    goto v_28491;
v_28492:
    v_29278 = elt(env, 2); // false
    goto v_28493;
v_28494:
    goto v_28490;
v_28491:
    goto v_28492;
v_28493:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28477;
    v_29278 = nil;
v_28477:
    if (v_29278 == nil) goto v_28475;
    v_29278 = lisp_true;
    goto v_28473;
v_28475:
    goto v_28521;
v_28517:
    v_29279 = v_29280;
    goto v_28518;
v_28519:
    v_29278 = elt(env, 3); // or
    goto v_28520;
v_28521:
    goto v_28517;
v_28518:
    goto v_28519;
v_28520:
    if (v_29279 == v_29278) goto v_28515;
    else goto v_28516;
v_28515:
    v_29278 = lisp_true;
    goto v_28514;
v_28516:
    goto v_28531;
v_28527:
    v_29279 = v_29280;
    goto v_28528;
v_28529:
    v_29278 = elt(env, 4); // and
    goto v_28530;
v_28531:
    goto v_28527;
v_28528:
    goto v_28529;
v_28530:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28514;
    v_29278 = nil;
v_28514:
    if (v_29278 == nil) goto v_28512;
    v_29278 = lisp_true;
    goto v_28510;
v_28512:
    goto v_28542;
v_28538:
    v_29279 = v_29280;
    goto v_28539;
v_28540:
    v_29278 = elt(env, 5); // not
    goto v_28541;
v_28542:
    goto v_28538;
v_28539:
    goto v_28540;
v_28541:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28510;
    v_29278 = nil;
v_28510:
    if (v_29278 == nil) goto v_28508;
    v_29278 = lisp_true;
    goto v_28506;
v_28508:
    goto v_28557;
v_28553:
    v_29279 = v_29280;
    goto v_28554;
v_28555:
    v_29278 = elt(env, 6); // impl
    goto v_28556;
v_28557:
    goto v_28553;
v_28554:
    goto v_28555;
v_28556:
    if (v_29279 == v_29278) goto v_28551;
    else goto v_28552;
v_28551:
    v_29278 = lisp_true;
    goto v_28550;
v_28552:
    goto v_28571;
v_28567:
    v_29279 = v_29280;
    goto v_28568;
v_28569:
    v_29278 = elt(env, 7); // repl
    goto v_28570;
v_28571:
    goto v_28567;
v_28568:
    goto v_28569;
v_28570:
    if (v_29279 == v_29278) goto v_28565;
    else goto v_28566;
v_28565:
    v_29278 = lisp_true;
    goto v_28564;
v_28566:
    goto v_28581;
v_28577:
    v_29279 = v_29280;
    goto v_28578;
v_28579:
    v_29278 = elt(env, 8); // equiv
    goto v_28580;
v_28581:
    goto v_28577;
v_28578:
    goto v_28579;
v_28580:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28564;
    v_29278 = nil;
v_28564:
    goto v_28550;
    v_29278 = nil;
v_28550:
    goto v_28506;
    v_29278 = nil;
v_28506:
    if (v_29278 == nil) goto v_28504;
    v_29278 = lisp_true;
    goto v_28502;
v_28504:
    goto v_28600;
v_28596:
    v_29279 = v_29280;
    goto v_28597;
v_28598:
    v_29278 = elt(env, 9); // ex
    goto v_28599;
v_28600:
    goto v_28596;
v_28597:
    goto v_28598;
v_28599:
    if (v_29279 == v_29278) goto v_28594;
    else goto v_28595;
v_28594:
    v_29278 = lisp_true;
    goto v_28593;
v_28595:
    goto v_28610;
v_28606:
    v_29279 = v_29280;
    goto v_28607;
v_28608:
    v_29278 = elt(env, 10); // all
    goto v_28609;
v_28610:
    goto v_28606;
v_28607:
    goto v_28608;
v_28609:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28593;
    v_29278 = nil;
v_28593:
    if (v_29278 == nil) goto v_28591;
    v_29278 = lisp_true;
    goto v_28589;
v_28591:
    goto v_28629;
v_28625:
    v_29279 = v_29280;
    goto v_28626;
v_28627:
    v_29278 = elt(env, 11); // bex
    goto v_28628;
v_28629:
    goto v_28625;
v_28626:
    goto v_28627;
v_28628:
    if (v_29279 == v_29278) goto v_28623;
    else goto v_28624;
v_28623:
    v_29278 = lisp_true;
    goto v_28622;
v_28624:
    goto v_28639;
v_28635:
    v_29279 = v_29280;
    goto v_28636;
v_28637:
    v_29278 = elt(env, 12); // ball
    goto v_28638;
v_28639:
    goto v_28635;
v_28636:
    goto v_28637;
v_28638:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28622;
    v_29278 = nil;
v_28622:
    if (v_29278 == nil) goto v_28620;
    v_29278 = lisp_true;
    goto v_28618;
v_28620:
    v_29278 = v_29280;
    if (!symbolp(v_29278)) v_29278 = nil;
    else { v_29278 = qfastgets(v_29278);
           if (v_29278 != nil) { v_29278 = elt(v_29278, 21); // rl_external
#ifdef RECORD_GET
             if (v_29278 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_29278 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_29278 == SPID_NOPROP) v_29278 = nil; }}
#endif
    goto v_28618;
    v_29278 = nil;
v_28618:
    goto v_28589;
    v_29278 = nil;
v_28589:
    goto v_28502;
    v_29278 = nil;
v_28502:
    goto v_28473;
    v_29278 = nil;
v_28473:
    goto v_28293;
v_28295:
    v_29278 = nil;
    goto v_28293;
    v_29278 = nil;
v_28293:
    if (v_29278 == nil) goto v_28291;
    v_29278 = lisp_true;
    goto v_27895;
v_28291:
    goto v_28669;
v_28665:
    v_29279 = v_29281;
    goto v_28666;
v_28667:
    v_29278 = elt(env, 1); // true
    goto v_28668;
v_28669:
    goto v_28665;
v_28666:
    goto v_28667;
v_28668:
    if (v_29279 == v_29278) goto v_28663;
    else goto v_28664;
v_28663:
    v_29278 = lisp_true;
    goto v_28662;
v_28664:
    goto v_28679;
v_28675:
    v_29279 = v_29281;
    goto v_28676;
v_28677:
    v_29278 = elt(env, 2); // false
    goto v_28678;
v_28679:
    goto v_28675;
v_28676:
    goto v_28677;
v_28678:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28662;
    v_29278 = nil;
v_28662:
    if (v_29278 == nil) goto v_28660;
    v_29278 = lisp_true;
    goto v_28658;
v_28660:
    goto v_28706;
v_28702:
    v_29279 = v_29281;
    goto v_28703;
v_28704:
    v_29278 = elt(env, 3); // or
    goto v_28705;
v_28706:
    goto v_28702;
v_28703:
    goto v_28704;
v_28705:
    if (v_29279 == v_29278) goto v_28700;
    else goto v_28701;
v_28700:
    v_29278 = lisp_true;
    goto v_28699;
v_28701:
    goto v_28716;
v_28712:
    v_29279 = v_29281;
    goto v_28713;
v_28714:
    v_29278 = elt(env, 4); // and
    goto v_28715;
v_28716:
    goto v_28712;
v_28713:
    goto v_28714;
v_28715:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28699;
    v_29278 = nil;
v_28699:
    if (v_29278 == nil) goto v_28697;
    v_29278 = lisp_true;
    goto v_28695;
v_28697:
    goto v_28727;
v_28723:
    v_29279 = v_29281;
    goto v_28724;
v_28725:
    v_29278 = elt(env, 5); // not
    goto v_28726;
v_28727:
    goto v_28723;
v_28724:
    goto v_28725;
v_28726:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28695;
    v_29278 = nil;
v_28695:
    if (v_29278 == nil) goto v_28693;
    v_29278 = lisp_true;
    goto v_28691;
v_28693:
    goto v_28742;
v_28738:
    v_29279 = v_29281;
    goto v_28739;
v_28740:
    v_29278 = elt(env, 6); // impl
    goto v_28741;
v_28742:
    goto v_28738;
v_28739:
    goto v_28740;
v_28741:
    if (v_29279 == v_29278) goto v_28736;
    else goto v_28737;
v_28736:
    v_29278 = lisp_true;
    goto v_28735;
v_28737:
    goto v_28756;
v_28752:
    v_29279 = v_29281;
    goto v_28753;
v_28754:
    v_29278 = elt(env, 7); // repl
    goto v_28755;
v_28756:
    goto v_28752;
v_28753:
    goto v_28754;
v_28755:
    if (v_29279 == v_29278) goto v_28750;
    else goto v_28751;
v_28750:
    v_29278 = lisp_true;
    goto v_28749;
v_28751:
    goto v_28766;
v_28762:
    v_29279 = v_29281;
    goto v_28763;
v_28764:
    v_29278 = elt(env, 8); // equiv
    goto v_28765;
v_28766:
    goto v_28762;
v_28763:
    goto v_28764;
v_28765:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28749;
    v_29278 = nil;
v_28749:
    goto v_28735;
    v_29278 = nil;
v_28735:
    goto v_28691;
    v_29278 = nil;
v_28691:
    if (v_29278 == nil) goto v_28689;
    v_29278 = lisp_true;
    goto v_28687;
v_28689:
    goto v_28785;
v_28781:
    v_29279 = v_29281;
    goto v_28782;
v_28783:
    v_29278 = elt(env, 9); // ex
    goto v_28784;
v_28785:
    goto v_28781;
v_28782:
    goto v_28783;
v_28784:
    if (v_29279 == v_29278) goto v_28779;
    else goto v_28780;
v_28779:
    v_29278 = lisp_true;
    goto v_28778;
v_28780:
    goto v_28795;
v_28791:
    v_29279 = v_29281;
    goto v_28792;
v_28793:
    v_29278 = elt(env, 10); // all
    goto v_28794;
v_28795:
    goto v_28791;
v_28792:
    goto v_28793;
v_28794:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28778;
    v_29278 = nil;
v_28778:
    if (v_29278 == nil) goto v_28776;
    v_29278 = lisp_true;
    goto v_28774;
v_28776:
    goto v_28814;
v_28810:
    v_29279 = v_29281;
    goto v_28811;
v_28812:
    v_29278 = elt(env, 11); // bex
    goto v_28813;
v_28814:
    goto v_28810;
v_28811:
    goto v_28812;
v_28813:
    if (v_29279 == v_29278) goto v_28808;
    else goto v_28809;
v_28808:
    v_29278 = lisp_true;
    goto v_28807;
v_28809:
    goto v_28824;
v_28820:
    v_29279 = v_29281;
    goto v_28821;
v_28822:
    v_29278 = elt(env, 12); // ball
    goto v_28823;
v_28824:
    goto v_28820;
v_28821:
    goto v_28822;
v_28823:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28807;
    v_29278 = nil;
v_28807:
    if (v_29278 == nil) goto v_28805;
    v_29278 = lisp_true;
    goto v_28803;
v_28805:
    v_29278 = v_29281;
    if (!symbolp(v_29278)) v_29278 = nil;
    else { v_29278 = qfastgets(v_29278);
           if (v_29278 != nil) { v_29278 = elt(v_29278, 21); // rl_external
#ifdef RECORD_GET
             if (v_29278 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_29278 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_29278 == SPID_NOPROP) v_29278 = nil; }}
#endif
    goto v_28803;
    v_29278 = nil;
v_28803:
    goto v_28774;
    v_29278 = nil;
v_28774:
    goto v_28687;
    v_29278 = nil;
v_28687:
    goto v_28658;
    v_29278 = nil;
v_28658:
    if (v_29278 == nil) goto v_28655;
    goto v_28846;
v_28842:
    v_29279 = v_29280;
    goto v_28843;
v_28844:
    v_29278 = elt(env, 1); // true
    goto v_28845;
v_28846:
    goto v_28842;
v_28843:
    goto v_28844;
v_28845:
    if (v_29279 == v_29278) goto v_28840;
    else goto v_28841;
v_28840:
    v_29278 = lisp_true;
    goto v_28839;
v_28841:
    goto v_28856;
v_28852:
    v_29279 = v_29280;
    goto v_28853;
v_28854:
    v_29278 = elt(env, 2); // false
    goto v_28855;
v_28856:
    goto v_28852;
v_28853:
    goto v_28854;
v_28855:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28839;
    v_29278 = nil;
v_28839:
    if (v_29278 == nil) goto v_28837;
    v_29278 = lisp_true;
    goto v_28835;
v_28837:
    goto v_28883;
v_28879:
    v_29279 = v_29280;
    goto v_28880;
v_28881:
    v_29278 = elt(env, 3); // or
    goto v_28882;
v_28883:
    goto v_28879;
v_28880:
    goto v_28881;
v_28882:
    if (v_29279 == v_29278) goto v_28877;
    else goto v_28878;
v_28877:
    v_29278 = lisp_true;
    goto v_28876;
v_28878:
    goto v_28893;
v_28889:
    v_29279 = v_29280;
    goto v_28890;
v_28891:
    v_29278 = elt(env, 4); // and
    goto v_28892;
v_28893:
    goto v_28889;
v_28890:
    goto v_28891;
v_28892:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28876;
    v_29278 = nil;
v_28876:
    if (v_29278 == nil) goto v_28874;
    v_29278 = lisp_true;
    goto v_28872;
v_28874:
    goto v_28904;
v_28900:
    v_29279 = v_29280;
    goto v_28901;
v_28902:
    v_29278 = elt(env, 5); // not
    goto v_28903;
v_28904:
    goto v_28900;
v_28901:
    goto v_28902;
v_28903:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28872;
    v_29278 = nil;
v_28872:
    if (v_29278 == nil) goto v_28870;
    v_29278 = lisp_true;
    goto v_28868;
v_28870:
    goto v_28919;
v_28915:
    v_29279 = v_29280;
    goto v_28916;
v_28917:
    v_29278 = elt(env, 6); // impl
    goto v_28918;
v_28919:
    goto v_28915;
v_28916:
    goto v_28917;
v_28918:
    if (v_29279 == v_29278) goto v_28913;
    else goto v_28914;
v_28913:
    v_29278 = lisp_true;
    goto v_28912;
v_28914:
    goto v_28933;
v_28929:
    v_29279 = v_29280;
    goto v_28930;
v_28931:
    v_29278 = elt(env, 7); // repl
    goto v_28932;
v_28933:
    goto v_28929;
v_28930:
    goto v_28931;
v_28932:
    if (v_29279 == v_29278) goto v_28927;
    else goto v_28928;
v_28927:
    v_29278 = lisp_true;
    goto v_28926;
v_28928:
    goto v_28943;
v_28939:
    v_29279 = v_29280;
    goto v_28940;
v_28941:
    v_29278 = elt(env, 8); // equiv
    goto v_28942;
v_28943:
    goto v_28939;
v_28940:
    goto v_28941;
v_28942:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28926;
    v_29278 = nil;
v_28926:
    goto v_28912;
    v_29278 = nil;
v_28912:
    goto v_28868;
    v_29278 = nil;
v_28868:
    if (v_29278 == nil) goto v_28866;
    v_29278 = lisp_true;
    goto v_28864;
v_28866:
    goto v_28962;
v_28958:
    v_29279 = v_29280;
    goto v_28959;
v_28960:
    v_29278 = elt(env, 9); // ex
    goto v_28961;
v_28962:
    goto v_28958;
v_28959:
    goto v_28960;
v_28961:
    if (v_29279 == v_29278) goto v_28956;
    else goto v_28957;
v_28956:
    v_29278 = lisp_true;
    goto v_28955;
v_28957:
    goto v_28972;
v_28968:
    v_29279 = v_29280;
    goto v_28969;
v_28970:
    v_29278 = elt(env, 10); // all
    goto v_28971;
v_28972:
    goto v_28968;
v_28969:
    goto v_28970;
v_28971:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28955;
    v_29278 = nil;
v_28955:
    if (v_29278 == nil) goto v_28953;
    v_29278 = lisp_true;
    goto v_28951;
v_28953:
    goto v_28991;
v_28987:
    v_29279 = v_29280;
    goto v_28988;
v_28989:
    v_29278 = elt(env, 11); // bex
    goto v_28990;
v_28991:
    goto v_28987;
v_28988:
    goto v_28989;
v_28990:
    if (v_29279 == v_29278) goto v_28985;
    else goto v_28986;
v_28985:
    v_29278 = lisp_true;
    goto v_28984;
v_28986:
    goto v_29001;
v_28997:
    v_29279 = v_29280;
    goto v_28998;
v_28999:
    v_29278 = elt(env, 12); // ball
    goto v_29000;
v_29001:
    goto v_28997;
v_28998:
    goto v_28999;
v_29000:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_28984;
    v_29278 = nil;
v_28984:
    if (v_29278 == nil) goto v_28982;
    v_29278 = lisp_true;
    goto v_28980;
v_28982:
    v_29278 = v_29280;
    if (!symbolp(v_29278)) v_29278 = nil;
    else { v_29278 = qfastgets(v_29278);
           if (v_29278 != nil) { v_29278 = elt(v_29278, 21); // rl_external
#ifdef RECORD_GET
             if (v_29278 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_29278 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_29278 == SPID_NOPROP) v_29278 = nil; }}
#endif
    goto v_28980;
    v_29278 = nil;
v_28980:
    goto v_28951;
    v_29278 = nil;
v_28951:
    goto v_28864;
    v_29278 = nil;
v_28864:
    goto v_28835;
    v_29278 = nil;
v_28835:
    if (v_29278 == nil) goto v_28833;
    else goto v_28655;
v_28833:
    v_29278 = nil;
    goto v_27895;
v_28655:
    goto v_29019;
v_29015:
    v_29279 = v_29281;
    goto v_29016;
v_29017:
    v_29278 = v_29280;
    goto v_29018;
v_29019:
    goto v_29015;
v_29016:
    goto v_29017;
v_29018:
    if (equal(v_29279, v_29278)) goto v_29014;
    goto v_29027;
v_29023:
    v_29278 = v_29281;
    goto v_29024;
v_29025:
    v_29279 = v_29280;
    goto v_29026;
v_29027:
    goto v_29023;
v_29024:
    goto v_29025;
v_29026:
    {
        fn = elt(env, 14); // cl_ordopp
        return (*qfn2(fn))(fn, v_29278, v_29279);
    }
v_29014:
    goto v_29042;
v_29038:
    v_29279 = v_29281;
    goto v_29039;
v_29040:
    v_29278 = elt(env, 1); // true
    goto v_29041;
v_29042:
    goto v_29038;
v_29039:
    goto v_29040;
v_29041:
    if (v_29279 == v_29278) goto v_29036;
    else goto v_29037;
v_29036:
    v_29278 = lisp_true;
    goto v_29035;
v_29037:
    goto v_29052;
v_29048:
    v_29279 = v_29281;
    goto v_29049;
v_29050:
    v_29278 = elt(env, 2); // false
    goto v_29051;
v_29052:
    goto v_29048;
v_29049:
    goto v_29050;
v_29051:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_29035;
    v_29278 = nil;
v_29035:
    if (v_29278 == nil) goto v_29033;
    v_29278 = lisp_true;
    goto v_27895;
v_29033:
    goto v_29069;
v_29065:
    v_29279 = v_29281;
    goto v_29066;
v_29067:
    v_29278 = elt(env, 9); // ex
    goto v_29068;
v_29069:
    goto v_29065;
v_29066:
    goto v_29067;
v_29068:
    if (v_29279 == v_29278) goto v_29063;
    else goto v_29064;
v_29063:
    v_29278 = lisp_true;
    goto v_29062;
v_29064:
    goto v_29079;
v_29075:
    v_29279 = v_29281;
    goto v_29076;
v_29077:
    v_29278 = elt(env, 10); // all
    goto v_29078;
v_29079:
    goto v_29075;
v_29076:
    goto v_29077;
v_29078:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_29062;
    v_29278 = nil;
v_29062:
    if (v_29278 == nil) goto v_29060;
    goto v_29091;
v_29087:
    v_29278 = stack[-1];
    v_29278 = qcdr(v_29278);
    v_29279 = qcar(v_29278);
    goto v_29088;
v_29089:
    v_29278 = stack[0];
    v_29278 = qcdr(v_29278);
    v_29278 = qcar(v_29278);
    goto v_29090;
v_29091:
    goto v_29087;
v_29088:
    goto v_29089;
v_29090:
    if (equal(v_29279, v_29278)) goto v_29086;
    goto v_29107;
v_29103:
    v_29278 = stack[-1];
    v_29278 = qcdr(v_29278);
    v_29279 = qcar(v_29278);
    goto v_29104;
v_29105:
    v_29278 = stack[0];
    v_29278 = qcdr(v_29278);
    v_29278 = qcar(v_29278);
    goto v_29106;
v_29107:
    goto v_29103;
v_29104:
    goto v_29105;
v_29106:
    fn = elt(env, 15); // ordp
    v_29278 = (*qfn2(fn))(fn, v_29279, v_29278);
    env = stack[-2];
    if (v_29278 == nil) goto v_29100;
    else goto v_29101;
v_29100:
    v_29278 = nil;
    goto v_29099;
v_29101:
    goto v_29122;
v_29118:
    v_29278 = stack[-1];
    v_29278 = qcdr(v_29278);
    v_29279 = qcar(v_29278);
    goto v_29119;
v_29120:
    v_29278 = stack[0];
    v_29278 = qcdr(v_29278);
    v_29278 = qcar(v_29278);
    goto v_29121;
v_29122:
    goto v_29118;
v_29119:
    goto v_29120;
v_29121:
    v_29278 = Lneq(nil, v_29279, v_29278);
    goto v_29099;
    v_29278 = nil;
v_29099:
    v_29278 = (v_29278 == nil ? lisp_true : nil);
    goto v_27895;
v_29086:
    goto v_29137;
v_29133:
    v_29278 = stack[-1];
    v_29278 = qcdr(v_29278);
    v_29278 = qcdr(v_29278);
    v_29279 = qcar(v_29278);
    goto v_29134;
v_29135:
    v_29278 = stack[0];
    v_29278 = qcdr(v_29278);
    v_29278 = qcdr(v_29278);
    v_29278 = qcar(v_29278);
    goto v_29136;
v_29137:
    goto v_29133;
v_29134:
    goto v_29135;
v_29136:
    stack[-1] = v_29279;
    stack[0] = v_29278;
    goto v_27888;
    goto v_29058;
v_29060:
v_29058:
    goto v_29158;
v_29154:
    v_29279 = v_29281;
    goto v_29155;
v_29156:
    v_29278 = elt(env, 11); // bex
    goto v_29157;
v_29158:
    goto v_29154;
v_29155:
    goto v_29156;
v_29157:
    if (v_29279 == v_29278) goto v_29152;
    else goto v_29153;
v_29152:
    v_29278 = lisp_true;
    goto v_29151;
v_29153:
    goto v_29168;
v_29164:
    v_29279 = v_29281;
    goto v_29165;
v_29166:
    v_29278 = elt(env, 12); // ball
    goto v_29167;
v_29168:
    goto v_29164;
v_29165:
    goto v_29166;
v_29167:
    v_29278 = (v_29279 == v_29278 ? lisp_true : nil);
    goto v_29151;
    v_29278 = nil;
v_29151:
    if (v_29278 == nil) goto v_29149;
    goto v_29180;
v_29176:
    v_29278 = stack[-1];
    v_29278 = qcdr(v_29278);
    v_29279 = qcar(v_29278);
    goto v_29177;
v_29178:
    v_29278 = stack[0];
    v_29278 = qcdr(v_29278);
    v_29278 = qcar(v_29278);
    goto v_29179;
v_29180:
    goto v_29176;
v_29177:
    goto v_29178;
v_29179:
    if (equal(v_29279, v_29278)) goto v_29175;
    goto v_29196;
v_29192:
    v_29278 = stack[-1];
    v_29278 = qcdr(v_29278);
    v_29279 = qcar(v_29278);
    goto v_29193;
v_29194:
    v_29278 = stack[0];
    v_29278 = qcdr(v_29278);
    v_29278 = qcar(v_29278);
    goto v_29195;
v_29196:
    goto v_29192;
v_29193:
    goto v_29194;
v_29195:
    fn = elt(env, 15); // ordp
    v_29278 = (*qfn2(fn))(fn, v_29279, v_29278);
    env = stack[-2];
    if (v_29278 == nil) goto v_29189;
    else goto v_29190;
v_29189:
    v_29278 = nil;
    goto v_29188;
v_29190:
    goto v_29211;
v_29207:
    v_29278 = stack[-1];
    v_29278 = qcdr(v_29278);
    v_29279 = qcar(v_29278);
    goto v_29208;
v_29209:
    v_29278 = stack[0];
    v_29278 = qcdr(v_29278);
    v_29278 = qcar(v_29278);
    goto v_29210;
v_29211:
    goto v_29207;
v_29208:
    goto v_29209;
v_29210:
    v_29278 = Lneq(nil, v_29279, v_29278);
    goto v_29188;
    v_29278 = nil;
v_29188:
    v_29278 = (v_29278 == nil ? lisp_true : nil);
    goto v_27895;
v_29175:
    goto v_29225;
v_29221:
    v_29278 = stack[-1];
    v_29278 = qcdr(v_29278);
    v_29278 = qcdr(v_29278);
    v_29278 = qcdr(v_29278);
    v_29279 = qcar(v_29278);
    goto v_29222;
v_29223:
    v_29278 = stack[0];
    v_29278 = qcdr(v_29278);
    v_29278 = qcdr(v_29278);
    v_29278 = qcdr(v_29278);
    v_29278 = qcar(v_29278);
    goto v_29224;
v_29225:
    goto v_29221;
v_29222:
    goto v_29223;
v_29224:
    if (equal(v_29279, v_29278)) goto v_29220;
    goto v_29241;
v_29237:
    v_29278 = stack[-1];
    v_29278 = qcdr(v_29278);
    v_29278 = qcdr(v_29278);
    v_29278 = qcdr(v_29278);
    v_29279 = qcar(v_29278);
    goto v_29238;
v_29239:
    v_29278 = stack[0];
    v_29278 = qcdr(v_29278);
    v_29278 = qcdr(v_29278);
    v_29278 = qcdr(v_29278);
    v_29278 = qcar(v_29278);
    goto v_29240;
v_29241:
    goto v_29237;
v_29238:
    goto v_29239;
v_29240:
    stack[-1] = v_29279;
    stack[0] = v_29278;
    goto v_27888;
v_29220:
    goto v_29259;
v_29255:
    v_29278 = stack[-1];
    v_29278 = qcdr(v_29278);
    v_29278 = qcdr(v_29278);
    v_29279 = qcar(v_29278);
    goto v_29256;
v_29257:
    v_29278 = stack[0];
    v_29278 = qcdr(v_29278);
    v_29278 = qcdr(v_29278);
    v_29278 = qcar(v_29278);
    goto v_29258;
v_29259:
    goto v_29255;
v_29256:
    goto v_29257;
v_29258:
    stack[-1] = v_29279;
    stack[0] = v_29278;
    goto v_27888;
    goto v_29147;
v_29149:
v_29147:
    goto v_29273;
v_29269:
    v_29278 = stack[-1];
    v_29279 = qcdr(v_29278);
    goto v_29270;
v_29271:
    v_29278 = stack[0];
    v_29278 = qcdr(v_29278);
    goto v_29272;
v_29273:
    goto v_29269;
v_29270:
    goto v_29271;
v_29272:
    {
        fn = elt(env, 16); // cl_sordpl
        return (*qfn2(fn))(fn, v_29279, v_29278);
    }
v_27895:
    return onevalue(v_29278);
}



// Code for matsm!*

static LispObject CC_matsmH(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_27895, v_27896;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27890,v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27889,v_27890);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_27895 = v_27890;
    v_27896 = v_27889;
// end of prologue
    v_27895 = v_27896;
    fn = elt(env, 1); // matsm
    v_27895 = (*qfn1(fn))(fn, v_27895);
    env = stack[0];
    {
        fn = elt(env, 2); // matsm!*1
        return (*qfn1(fn))(fn, v_27895);
    }
}



// Code for vdplsort

static LispObject CC_vdplsort(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_27899, v_27900;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27899 = v_27889;
// end of prologue
    goto v_27896;
v_27892:
    v_27900 = v_27899;
    goto v_27893;
v_27894:
    v_27899 = elt(env, 1); // vdpvevlcomp
    goto v_27895;
v_27896:
    goto v_27892;
v_27893:
    goto v_27894;
v_27895:
    {
        fn = elt(env, 2); // sort
        return (*qfn2(fn))(fn, v_27900, v_27899);
    }
}



// Code for reset_opnums

static LispObject CC_reset_opnums(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27957, v_27958, v_27959;
    LispObject fn;
    argcheck(nargs, 0, "reset_opnums");
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
    v_27957 = qvalue(elt(env, 1)); // oporder!*
    stack[-4] = v_27957;
    v_27957 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_27957;
v_27897:
    v_27957 = stack[-4];
    if (v_27957 == nil) goto v_27902;
    else goto v_27903;
v_27902:
    v_27957 = nil;
    goto v_27896;
v_27903:
    v_27957 = stack[-4];
    v_27957 = qcar(v_27957);
    v_27958 = v_27957;
    v_27957 = stack[-4];
    v_27957 = qcdr(v_27957);
    stack[-4] = v_27957;
    v_27957 = v_27958;
    if (symbolp(v_27957)) goto v_27912;
    else goto v_27913;
v_27912:
    v_27957 = v_27958;
    stack[-2] = v_27957;
    v_27957 = nil;
    goto v_27911;
v_27913:
    v_27957 = v_27958;
    v_27957 = qcar(v_27957);
    stack[-2] = v_27957;
    v_27957 = v_27958;
    v_27957 = qcdr(v_27957);
    goto v_27911;
v_27911:
    goto v_27930;
v_27924:
    stack[-1] = stack[-2];
    goto v_27925;
v_27926:
    stack[0] = elt(env, 2); // opnum
    goto v_27927;
v_27928:
    goto v_27938;
v_27934:
    goto v_27944;
v_27940:
    v_27958 = v_27957;
    goto v_27941;
v_27942:
    v_27957 = stack[-3];
    goto v_27943;
v_27944:
    goto v_27940;
v_27941:
    goto v_27942;
v_27943:
    v_27959 = cons(v_27958, v_27957);
    env = stack[-5];
    goto v_27935;
v_27936:
    goto v_27952;
v_27948:
    v_27958 = stack[-2];
    goto v_27949;
v_27950:
    v_27957 = elt(env, 2); // opnum
    goto v_27951;
v_27952:
    goto v_27948;
v_27949:
    goto v_27950;
v_27951:
    v_27957 = get(v_27958, v_27957);
    env = stack[-5];
    goto v_27937;
v_27938:
    goto v_27934;
v_27935:
    goto v_27936;
v_27937:
    fn = elt(env, 3); // !*xadd
    v_27957 = (*qfn2(fn))(fn, v_27959, v_27957);
    env = stack[-5];
    goto v_27929;
v_27930:
    goto v_27924;
v_27925:
    goto v_27926;
v_27927:
    goto v_27928;
v_27929:
    v_27957 = Lputprop(nil, 3, stack[-1], stack[0], v_27957);
    env = stack[-5];
    v_27957 = stack[-3];
    v_27957 = add1(v_27957);
    env = stack[-5];
    stack[-3] = v_27957;
    goto v_27897;
v_27896:
    return onevalue(v_27957);
}



// Code for free

static LispObject CC_free(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_27907;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27889);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27889;
// end of prologue
    v_27907 = stack[0];
    v_27907 = qcdr(v_27907);
    v_27907 = qcar(v_27907);
    fn = elt(env, 1); // freeind
    v_27907 = (*qfn1(fn))(fn, v_27907);
    env = stack[-1];
    if (v_27907 == nil) goto v_27893;
    else goto v_27894;
v_27893:
    v_27907 = nil;
    goto v_27892;
v_27894:
    v_27907 = stack[0];
    v_27907 = qcdr(v_27907);
    v_27907 = qcdr(v_27907);
    v_27907 = qcar(v_27907);
    {
        fn = elt(env, 1); // freeind
        return (*qfn1(fn))(fn, v_27907);
    }
    v_27907 = nil;
v_27892:
    return onevalue(v_27907);
}



// Code for expand!-imrepartpow

static LispObject CC_expandKimrepartpow(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_27996, v_27997;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27889);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_27889;
// end of prologue
// Binding !*exp
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = nil; // !*exp
    v_27996 = lisp_true;
    qvalue(elt(env, 1)) = v_27996; // !*exp
    v_27996 = stack[-2];
    v_27996 = qcar(v_27996);
    if (symbolp(v_27996)) goto v_27899;
    goto v_27907;
v_27903:
    v_27996 = stack[-2];
    v_27996 = qcar(v_27996);
    v_27997 = qcar(v_27996);
    goto v_27904;
v_27905:
    v_27996 = elt(env, 2); // cmpxsplitfn
    goto v_27906;
v_27907:
    goto v_27903;
v_27904:
    goto v_27905;
v_27906:
    v_27996 = get(v_27997, v_27996);
    env = stack[-4];
    goto v_27897;
v_27899:
    v_27996 = nil;
    goto v_27897;
    v_27996 = nil;
v_27897:
    v_27997 = v_27996;
    goto v_27920;
v_27916:
    v_27996 = v_27997;
    if (v_27996 == nil) goto v_27923;
    else goto v_27924;
v_27923:
    goto v_27934;
v_27930:
    v_27996 = stack[-2];
    v_27997 = qcar(v_27996);
    goto v_27931;
v_27932:
    v_27996 = elt(env, 3); // i
    goto v_27933;
v_27934:
    goto v_27930;
v_27931:
    goto v_27932;
v_27933:
    if (v_27997 == v_27996) goto v_27928;
    else goto v_27929;
v_27928:
    goto v_27943;
v_27939:
    goto v_27950;
v_27946:
    goto v_27956;
v_27952:
    v_27997 = elt(env, 3); // i
    goto v_27953;
v_27954:
    v_27996 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27955;
v_27956:
    goto v_27952;
v_27953:
    goto v_27954;
v_27955:
    fn = elt(env, 4); // to
    v_27997 = (*qfn2(fn))(fn, v_27997, v_27996);
    env = stack[-4];
    goto v_27947;
v_27948:
    v_27996 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27949;
v_27950:
    goto v_27946;
v_27947:
    goto v_27948;
v_27949:
    v_27996 = cons(v_27997, v_27996);
    env = stack[-4];
    v_27997 = ncons(v_27996);
    env = stack[-4];
    goto v_27940;
v_27941:
    v_27996 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27942;
v_27943:
    goto v_27939;
v_27940:
    goto v_27941;
v_27942:
    v_27996 = cons(v_27997, v_27996);
    env = stack[-4];
    goto v_27927;
v_27929:
    goto v_27968;
v_27964:
    v_27996 = stack[-2];
    v_27996 = qcar(v_27996);
    fn = elt(env, 5); // mkrepart
    stack[-1] = (*qfn1(fn))(fn, v_27996);
    env = stack[-4];
    goto v_27965;
v_27966:
    goto v_27977;
v_27973:
    v_27996 = elt(env, 3); // i
    fn = elt(env, 6); // simp
    stack[0] = (*qfn1(fn))(fn, v_27996);
    env = stack[-4];
    goto v_27974;
v_27975:
    v_27996 = stack[-2];
    v_27996 = qcar(v_27996);
    fn = elt(env, 7); // mkimpart
    v_27996 = (*qfn1(fn))(fn, v_27996);
    env = stack[-4];
    goto v_27976;
v_27977:
    goto v_27973;
v_27974:
    goto v_27975;
v_27976:
    fn = elt(env, 8); // multsq
    v_27996 = (*qfn2(fn))(fn, stack[0], v_27996);
    env = stack[-4];
    goto v_27967;
v_27968:
    goto v_27964;
v_27965:
    goto v_27966;
v_27967:
    fn = elt(env, 9); // addsq
    v_27996 = (*qfn2(fn))(fn, stack[-1], v_27996);
    env = stack[-4];
    goto v_27927;
    v_27996 = nil;
v_27927:
    v_27997 = v_27996;
    goto v_27922;
v_27924:
    goto v_27990;
v_27986:
    goto v_27987;
v_27988:
    v_27996 = stack[-2];
    v_27996 = qcar(v_27996);
    goto v_27989;
v_27990:
    goto v_27986;
v_27987:
    goto v_27988;
v_27989:
    v_27996 = Lapply1(nil, v_27997, v_27996);
    env = stack[-4];
    v_27997 = v_27996;
    goto v_27922;
    v_27997 = nil;
v_27922:
    goto v_27917;
v_27918:
    v_27996 = stack[-2];
    v_27996 = qcdr(v_27996);
    goto v_27919;
v_27920:
    goto v_27916;
v_27917:
    goto v_27918;
v_27919:
    fn = elt(env, 10); // exptsq
    v_27996 = (*qfn2(fn))(fn, v_27997, v_27996);
    ;}  // end of a binding scope
    return onevalue(v_27996);
}



// Code for generic_arguments

static LispObject CC_generic_arguments(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_27907, v_27908, v_27909;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27889);
    }
// copy arguments values to proper place
    v_27907 = v_27889;
// end of prologue
    goto v_27896;
v_27892:
    v_27909 = elt(env, 1); // list
    goto v_27893;
v_27894:
    goto v_27903;
v_27899:
    v_27908 = qcar(v_27907);
    goto v_27900;
v_27901:
    v_27907 = elt(env, 2); // generic_function
    goto v_27902;
v_27903:
    goto v_27899;
v_27900:
    goto v_27901;
v_27902:
    v_27907 = get(v_27908, v_27907);
    goto v_27895;
v_27896:
    goto v_27892;
v_27893:
    goto v_27894;
v_27895:
    return cons(v_27909, v_27907);
}



// Code for njets

static LispObject CC_njets(LispObject env,
                         LispObject v_27889, LispObject v_27890)
{
    env = qenv(env);
    LispObject v_27908, v_27909;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27890,v_27889);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27889,v_27890);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_27908 = v_27890;
    v_27909 = v_27889;
// end of prologue
    goto v_27897;
v_27893:
    stack[-1] = v_27908;
    goto v_27894;
v_27895:
    goto v_27904;
v_27900:
    stack[0] = v_27908;
    goto v_27901;
v_27902:
    v_27908 = v_27909;
    v_27908 = sub1(v_27908);
    env = stack[-2];
    goto v_27903;
v_27904:
    goto v_27900;
v_27901:
    goto v_27902;
v_27903:
    v_27908 = plus2(stack[0], v_27908);
    env = stack[-2];
    goto v_27896;
v_27897:
    goto v_27893;
v_27894:
    goto v_27895;
v_27896:
    {
        LispObject v_27912 = stack[-1];
        fn = elt(env, 1); // combin
        return (*qfn2(fn))(fn, v_27912, v_27908);
    }
}



// Code for domainp_list

static LispObject CC_domainp_list(LispObject env,
                         LispObject v_27889)
{
    env = qenv(env);
    LispObject v_27922, v_27923;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27922 = v_27889;
// end of prologue
v_27888:
    v_27923 = v_27922;
    if (v_27923 == nil) goto v_27893;
    else goto v_27894;
v_27893:
    v_27922 = lisp_true;
    goto v_27892;
v_27894:
    v_27923 = v_27922;
    v_27923 = qcar(v_27923);
    if (!consp(v_27923)) goto v_27905;
    else goto v_27906;
v_27905:
    v_27923 = lisp_true;
    goto v_27904;
v_27906:
    v_27923 = v_27922;
    v_27923 = qcar(v_27923);
    v_27923 = qcar(v_27923);
    v_27923 = (consp(v_27923) ? nil : lisp_true);
    goto v_27904;
    v_27923 = nil;
v_27904:
    if (v_27923 == nil) goto v_27902;
    v_27922 = qcdr(v_27922);
    goto v_27888;
v_27902:
    v_27922 = nil;
    goto v_27900;
    v_27922 = nil;
v_27900:
    goto v_27892;
    v_27922 = nil;
v_27892:
    return onevalue(v_27922);
}



// Code for random!-small!-prime

static LispObject CC_randomKsmallKprime(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27912;
    LispObject fn;
    argcheck(nargs, 0, "random-small-prime");
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
v_27895:
    fn = elt(env, 1); // small!-random!-number
    v_27912 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_27912;
    v_27912 = stack[0];
    v_27912 = Levenp(nil, v_27912);
    env = stack[-1];
    if (v_27912 == nil) goto v_27900;
    v_27912 = stack[0];
    v_27912 = (LispObject)((intptr_t)(v_27912) + 0x10);
    stack[0] = v_27912;
    goto v_27898;
v_27900:
v_27898:
    v_27912 = stack[0];
    fn = elt(env, 2); // primep
    v_27912 = (*qfn1(fn))(fn, v_27912);
    env = stack[-1];
    if (v_27912 == nil) goto v_27907;
    else goto v_27908;
v_27907:
    goto v_27895;
v_27908:
    v_27912 = stack[0];
    return onevalue(v_27912);
}



setup_type const u48_setup[] =
{
    {"cl_rename-vars1",         TOO_FEW_2,      CC_cl_renameKvars1,WRONG_NO_2},
    {"rl_sacat",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rl_sacat},
    {"dvfsf_susipost",          TOO_FEW_2,      CC_dvfsf_susipost,WRONG_NO_2},
    {"asymmetrize-inds",        TOO_FEW_2,      CC_asymmetrizeKinds,WRONG_NO_2},
    {"defined_all_edge",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_defined_all_edge},
    {"mapcarcar",               CC_mapcarcar,   TOO_MANY_1,    WRONG_NO_1},
    {"*a2kwoweight",            CC_Ha2kwoweight,TOO_MANY_1,    WRONG_NO_1},
    {"polynomreduceby",         TOO_FEW_2,      CC_polynomreduceby,WRONG_NO_2},
    {"ofsf_smeqtable",          TOO_FEW_2,      CC_ofsf_smeqtable,WRONG_NO_2},
    {"girationalize:",          CC_girationalizeT,TOO_MANY_1,  WRONG_NO_1},
    {"rat_abs",                 CC_rat_abs,     TOO_MANY_1,    WRONG_NO_1},
    {"copy_vect",               TOO_FEW_2,      CC_copy_vect,  WRONG_NO_2},
    {"nestzerop:",              CC_nestzeropT,  TOO_MANY_1,    WRONG_NO_1},
    {"dipretimes",              CC_dipretimes,  TOO_MANY_1,    WRONG_NO_1},
    {"natnump",                 CC_natnump,     TOO_MANY_1,    WRONG_NO_1},
    {"physopsubs",              CC_physopsubs,  TOO_MANY_1,    WRONG_NO_1},
    {"monomcomparelex",         TOO_FEW_2,      CC_monomcomparelex,WRONG_NO_2},
    {"my_freeof",               TOO_FEW_2,      CC_my_freeof,  WRONG_NO_2},
    {"dvfsf_ppolyp",            CC_dvfsf_ppolyp,TOO_MANY_1,    WRONG_NO_1},
    {"parfool",                 CC_parfool,     TOO_MANY_1,    WRONG_NO_1},
    {"groebcplistmerge",        TOO_FEW_2,      CC_groebcplistmerge,WRONG_NO_2},
    {"gfquotient",              TOO_FEW_2,      CC_gfquotient, WRONG_NO_2},
    {"mkdmoderr",               TOO_FEW_2,      CC_mkdmoderr,  WRONG_NO_2},
    {"indordln",                CC_indordln,    TOO_MANY_1,    WRONG_NO_1},
    {"listquotient",            TOO_FEW_2,      CC_listquotient,WRONG_NO_2},
    {"fs:prin:",                CC_fsTprinT,    TOO_MANY_1,    WRONG_NO_1},
    {"groeb=testb",             TOO_FEW_2,      CC_groebMtestb,WRONG_NO_2},
    {"verify_tens_ids",         CC_verify_tens_ids,TOO_MANY_1, WRONG_NO_1},
    {"nonlnr",                  TOO_FEW_2,      CC_nonlnr,     WRONG_NO_2},
    {"bfminus",                 CC_bfminus,     TOO_MANY_1,    WRONG_NO_1},
    {"no_of_tm_sf_limited",     TOO_FEW_2,      CC_no_of_tm_sf_limited,WRONG_NO_2},
    {"dfdeg",                   TOO_FEW_2,      CC_dfdeg,      WRONG_NO_2},
    {"makecoeffpairs",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_makecoeffpairs},
    {"cl_sordp",                TOO_FEW_2,      CC_cl_sordp,   WRONG_NO_2},
    {"matsm*",                  TOO_FEW_2,      CC_matsmH,     WRONG_NO_2},
    {"vdplsort",                CC_vdplsort,    TOO_MANY_1,    WRONG_NO_1},
    {"reset_opnums",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_reset_opnums},
    {"free",                    CC_free,        TOO_MANY_1,    WRONG_NO_1},
    {"expand-imrepartpow",      CC_expandKimrepartpow,TOO_MANY_1,WRONG_NO_1},
    {"generic_arguments",       CC_generic_arguments,TOO_MANY_1,WRONG_NO_1},
    {"njets",                   TOO_FEW_2,      CC_njets,      WRONG_NO_2},
    {"domainp_list",            CC_domainp_list,TOO_MANY_1,    WRONG_NO_1},
    {"random-small-prime",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_randomKsmallKprime},
    {NULL, (one_args *)"u48", (two_args *)"8876 5465663 8992417", 0}
};

// end of generated code
