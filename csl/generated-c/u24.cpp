
// $destdir/u24.c        Machine generated C code

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



// Code for fs!:prin1

static LispObject CC_fsTprin1(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13913, v_13914;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13743);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_13743;
// end of prologue
    v_13913 = lisp_true;
    stack[-3] = v_13913;
    goto v_13759;
v_13755:
    goto v_13764;
v_13760:
    v_13914 = stack[0];
    goto v_13761;
v_13762:
    v_13913 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13763;
v_13764:
    goto v_13760;
v_13761:
    goto v_13762;
v_13763:
    v_13914 = *(LispObject *)((char *)v_13914 + (CELL-TAG_VECTOR) + (((intptr_t)v_13913-TAG_FIXNUM)/(16/CELL)));
    goto v_13756;
v_13757:
    v_13913 = elt(env, 1); // (1 . 1)
    goto v_13758;
v_13759:
    goto v_13755;
v_13756:
    goto v_13757;
v_13758:
    if (equal(v_13914, v_13913)) goto v_13754;
    v_13913 = elt(env, 2); // "("
    fn = elt(env, 10); // prin2!*
    v_13913 = (*qfn1(fn))(fn, v_13913);
    env = stack[-4];
    goto v_13776;
v_13772:
    v_13914 = stack[0];
    goto v_13773;
v_13774:
    v_13913 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13775;
v_13776:
    goto v_13772;
v_13773:
    goto v_13774;
v_13775:
    v_13913 = *(LispObject *)((char *)v_13914 + (CELL-TAG_VECTOR) + (((intptr_t)v_13913-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 11); // sqprint
    v_13913 = (*qfn1(fn))(fn, v_13913);
    env = stack[-4];
    v_13913 = elt(env, 3); // ")"
    fn = elt(env, 10); // prin2!*
    v_13913 = (*qfn1(fn))(fn, v_13913);
    env = stack[-4];
    goto v_13752;
v_13754:
v_13752:
    v_13913 = stack[0];
    fn = elt(env, 12); // fs!:null!-angle
    v_13913 = (*qfn1(fn))(fn, v_13913);
    env = stack[-4];
    if (v_13913 == nil) goto v_13784;
    else goto v_13785;
v_13784:
    goto v_13793;
v_13789:
    v_13914 = stack[0];
    goto v_13790;
v_13791:
    v_13913 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13792;
v_13793:
    goto v_13789;
v_13790:
    goto v_13791;
v_13792:
    v_13913 = *(LispObject *)((char *)v_13914 + (CELL-TAG_VECTOR) + (((intptr_t)v_13913-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 10); // prin2!*
    v_13913 = (*qfn1(fn))(fn, v_13913);
    env = stack[-4];
    v_13913 = elt(env, 4); // "["
    fn = elt(env, 10); // prin2!*
    v_13913 = (*qfn1(fn))(fn, v_13913);
    env = stack[-4];
    goto v_13803;
v_13799:
    v_13914 = stack[0];
    goto v_13800;
v_13801:
    v_13913 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13802;
v_13803:
    goto v_13799;
v_13800:
    goto v_13801;
v_13802:
    v_13913 = *(LispObject *)((char *)v_13914 + (CELL-TAG_VECTOR) + (((intptr_t)v_13913-TAG_FIXNUM)/(16/CELL)));
    stack[-2] = v_13913;
    v_13913 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_13913;
v_13810:
    goto v_13822;
v_13818:
    v_13914 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_13819;
v_13820:
    v_13913 = stack[0];
    goto v_13821;
v_13822:
    goto v_13818;
v_13819:
    goto v_13820;
v_13821:
    v_13913 = difference2(v_13914, v_13913);
    env = stack[-4];
    v_13913 = Lminusp(nil, v_13913);
    env = stack[-4];
    if (v_13913 == nil) goto v_13815;
    goto v_13809;
v_13815:
    goto v_13834;
v_13830:
    goto v_13839;
v_13835:
    v_13914 = stack[-2];
    goto v_13836;
v_13837:
    v_13913 = stack[0];
    goto v_13838;
v_13839:
    goto v_13835;
v_13836:
    goto v_13837;
v_13838:
    v_13914 = *(LispObject *)((char *)v_13914 + (CELL-TAG_VECTOR) + (((intptr_t)v_13913-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_13914;
    goto v_13831;
v_13832:
    v_13913 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13833;
v_13834:
    goto v_13830;
v_13831:
    goto v_13832;
v_13833:
    if (v_13914 == v_13913) goto v_13829;
    goto v_13853;
v_13849:
    v_13914 = stack[-1];
    goto v_13850;
v_13851:
    v_13913 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13852;
v_13853:
    goto v_13849;
v_13850:
    goto v_13851;
v_13852:
    v_13913 = (LispObject)lessp2(v_13914, v_13913);
    v_13913 = v_13913 ? lisp_true : nil;
    env = stack[-4];
    if (v_13913 == nil) goto v_13847;
    v_13913 = lisp_true;
    stack[-3] = v_13913;
    v_13913 = elt(env, 5); // "-"
    fn = elt(env, 10); // prin2!*
    v_13913 = (*qfn1(fn))(fn, v_13913);
    env = stack[-4];
    v_13913 = stack[-1];
    v_13913 = negate(v_13913);
    env = stack[-4];
    stack[-1] = v_13913;
    goto v_13845;
v_13847:
v_13845:
    v_13913 = stack[-3];
    if (v_13913 == nil) goto v_13863;
    else goto v_13864;
v_13863:
    v_13913 = elt(env, 6); // "+"
    fn = elt(env, 10); // prin2!*
    v_13913 = (*qfn1(fn))(fn, v_13913);
    env = stack[-4];
    goto v_13862;
v_13864:
v_13862:
    goto v_13876;
v_13872:
    v_13914 = stack[-1];
    goto v_13873;
v_13874:
    v_13913 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13875;
v_13876:
    goto v_13872;
v_13873:
    goto v_13874;
v_13875:
    if (v_13914 == v_13913) goto v_13871;
    v_13913 = stack[-1];
    fn = elt(env, 10); // prin2!*
    v_13913 = (*qfn1(fn))(fn, v_13913);
    env = stack[-4];
    goto v_13869;
v_13871:
v_13869:
    v_13913 = nil;
    stack[-3] = v_13913;
    goto v_13887;
v_13883:
    v_13914 = qvalue(elt(env, 7)); // fourier!-name!*
    goto v_13884;
v_13885:
    v_13913 = stack[0];
    goto v_13886;
v_13887:
    goto v_13883;
v_13884:
    goto v_13885;
v_13886:
    v_13913 = *(LispObject *)((char *)v_13914 + (CELL-TAG_VECTOR) + (((intptr_t)v_13913-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 10); // prin2!*
    v_13913 = (*qfn1(fn))(fn, v_13913);
    env = stack[-4];
    goto v_13827;
v_13829:
v_13827:
    v_13913 = stack[0];
    v_13913 = add1(v_13913);
    env = stack[-4];
    stack[0] = v_13913;
    goto v_13810;
v_13809:
    v_13913 = elt(env, 8); // "]"
    fn = elt(env, 10); // prin2!*
    v_13913 = (*qfn1(fn))(fn, v_13913);
    goto v_13783;
v_13785:
    goto v_13901;
v_13897:
    goto v_13906;
v_13902:
    v_13914 = stack[0];
    goto v_13903;
v_13904:
    v_13913 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13905;
v_13906:
    goto v_13902;
v_13903:
    goto v_13904;
v_13905:
    v_13914 = *(LispObject *)((char *)v_13914 + (CELL-TAG_VECTOR) + (((intptr_t)v_13913-TAG_FIXNUM)/(16/CELL)));
    goto v_13898;
v_13899:
    v_13913 = elt(env, 1); // (1 . 1)
    goto v_13900;
v_13901:
    goto v_13897;
v_13898:
    goto v_13899;
v_13900:
    if (equal(v_13914, v_13913)) goto v_13895;
    else goto v_13896;
v_13895:
    v_13913 = elt(env, 9); // "1"
    fn = elt(env, 10); // prin2!*
    v_13913 = (*qfn1(fn))(fn, v_13913);
    goto v_13783;
v_13896:
v_13783:
    v_13913 = nil;
    return onevalue(v_13913);
}



// Code for st_sorttree

static LispObject CC_st_sorttree(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13759, v_13760, v_13761;
    LispObject fn;
    LispObject v_13745, v_13744, v_13743;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "st_sorttree");
    va_start(aa, nargs);
    v_13743 = va_arg(aa, LispObject);
    v_13744 = va_arg(aa, LispObject);
    v_13745 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13745,v_13744,v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13743,v_13744,v_13745);
    }
// copy arguments values to proper place
    v_13759 = v_13745;
    v_13760 = v_13744;
    v_13761 = v_13743;
// end of prologue
    goto v_13754;
v_13748:
    goto v_13749;
v_13750:
    goto v_13751;
v_13752:
    goto v_13753;
v_13754:
    goto v_13748;
v_13749:
    goto v_13750;
v_13751:
    goto v_13752;
v_13753:
    fn = elt(env, 1); // st_sorttree1
    v_13759 = (*qfnn(fn))(fn, 3, v_13761, v_13760, v_13759);
    v_13759 = qcdr(v_13759);
    return onevalue(v_13759);
}



// Code for general!-modular!-expt

static LispObject CC_generalKmodularKexpt(LispObject env,
                         LispObject v_13743, LispObject v_13744)
{
    env = qenv(env);
    LispObject v_13911, v_13912, v_13913;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13744,v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13743,v_13744);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13744;
    stack[-1] = v_13743;
// end of prologue
v_13748:
    goto v_13757;
v_13753:
    v_13912 = stack[-1];
    goto v_13754;
v_13755:
    v_13911 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13756;
v_13757:
    goto v_13753;
v_13754:
    goto v_13755;
v_13756:
    if (v_13912 == v_13911) goto v_13751;
    else goto v_13752;
v_13751:
    goto v_13768;
v_13764:
    v_13912 = stack[0];
    goto v_13765;
v_13766:
    v_13911 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13767;
v_13768:
    goto v_13764;
v_13765:
    goto v_13766;
v_13767:
    if (v_13912 == v_13911) goto v_13762;
    else goto v_13763;
v_13762:
    goto v_13778;
v_13772:
    v_13913 = elt(env, 1); // alg
    goto v_13773;
v_13774:
    v_13912 = (LispObject)1616+TAG_FIXNUM; // 101
    goto v_13775;
v_13776:
    v_13911 = elt(env, 2); // "0^0 formed"
    goto v_13777;
v_13778:
    goto v_13772;
v_13773:
    goto v_13774;
v_13775:
    goto v_13776;
v_13777:
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_13913, v_13912, v_13911);
    }
v_13763:
    v_13911 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13747;
    goto v_13750;
v_13752:
    goto v_13791;
v_13787:
    v_13912 = stack[0];
    goto v_13788;
v_13789:
    v_13911 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13790;
v_13791:
    goto v_13787;
v_13788:
    goto v_13789;
v_13790:
    if (v_13912 == v_13911) goto v_13785;
    else goto v_13786;
v_13785:
    v_13911 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13747;
v_13786:
    goto v_13801;
v_13797:
    v_13912 = stack[0];
    goto v_13798;
v_13799:
    v_13911 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13800;
v_13801:
    goto v_13797;
v_13798:
    goto v_13799;
v_13800:
    if (v_13912 == v_13911) goto v_13795;
    else goto v_13796;
v_13795:
    v_13911 = stack[-1];
    goto v_13747;
v_13796:
    goto v_13813;
v_13809:
    stack[-2] = stack[0];
    goto v_13810;
v_13811:
    v_13911 = qvalue(elt(env, 3)); // current!-modulus
    v_13911 = sub1(v_13911);
    env = stack[-3];
    goto v_13812;
v_13813:
    goto v_13809;
v_13810:
    goto v_13811;
v_13812:
    v_13911 = (LispObject)geq2(stack[-2], v_13911);
    v_13911 = v_13911 ? lisp_true : nil;
    env = stack[-3];
    if (v_13911 == nil) goto v_13806;
    v_13911 = qvalue(elt(env, 3)); // current!-modulus
    fn = elt(env, 5); // primep
    v_13911 = (*qfn1(fn))(fn, v_13911);
    env = stack[-3];
    if (v_13911 == nil) goto v_13806;
    goto v_13825;
v_13821:
    goto v_13822;
v_13823:
    v_13911 = qvalue(elt(env, 3)); // current!-modulus
    v_13911 = sub1(v_13911);
    env = stack[-3];
    goto v_13824;
v_13825:
    goto v_13821;
v_13822:
    goto v_13823;
v_13824:
    v_13911 = Cremainder(stack[0], v_13911);
    env = stack[-3];
    stack[0] = v_13911;
    goto v_13748;
v_13806:
v_13837:
    v_13911 = stack[0];
    v_13911 = Levenp(nil, v_13911);
    env = stack[-3];
    if (v_13911 == nil) goto v_13840;
    else goto v_13841;
v_13840:
    goto v_13836;
v_13841:
    goto v_13850;
v_13846:
    v_13912 = stack[0];
    goto v_13847;
v_13848:
    v_13911 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13849;
v_13850:
    goto v_13846;
v_13847:
    goto v_13848;
v_13849:
    v_13911 = quot2(v_13912, v_13911);
    env = stack[-3];
    stack[0] = v_13911;
    goto v_13858;
v_13854:
    v_13912 = stack[-1];
    goto v_13855;
v_13856:
    v_13911 = stack[-1];
    goto v_13857;
v_13858:
    goto v_13854;
v_13855:
    goto v_13856;
v_13857:
    fn = elt(env, 6); // general!-modular!-times
    v_13911 = (*qfn2(fn))(fn, v_13912, v_13911);
    env = stack[-3];
    stack[-1] = v_13911;
    goto v_13837;
v_13836:
    v_13911 = stack[0];
    fn = elt(env, 7); // reverse!-num
    v_13911 = (*qfn1(fn))(fn, v_13911);
    env = stack[-3];
    stack[0] = v_13911;
    v_13911 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_13911;
v_13866:
    goto v_13876;
v_13872:
    v_13912 = stack[0];
    goto v_13873;
v_13874:
    v_13911 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13875;
v_13876:
    goto v_13872;
v_13873:
    goto v_13874;
v_13875:
    v_13911 = (LispObject)greaterp2(v_13912, v_13911);
    v_13911 = v_13911 ? lisp_true : nil;
    env = stack[-3];
    if (v_13911 == nil) goto v_13869;
    else goto v_13870;
v_13869:
    goto v_13865;
v_13870:
    goto v_13885;
v_13881:
    v_13912 = stack[-2];
    goto v_13882;
v_13883:
    v_13911 = stack[-2];
    goto v_13884;
v_13885:
    goto v_13881;
v_13882:
    goto v_13883;
v_13884:
    fn = elt(env, 6); // general!-modular!-times
    v_13911 = (*qfn2(fn))(fn, v_13912, v_13911);
    env = stack[-3];
    stack[-2] = v_13911;
    v_13911 = stack[0];
    v_13911 = Levenp(nil, v_13911);
    env = stack[-3];
    if (v_13911 == nil) goto v_13890;
    else goto v_13891;
v_13890:
    goto v_13899;
v_13895:
    v_13912 = stack[-2];
    goto v_13896;
v_13897:
    v_13911 = stack[-1];
    goto v_13898;
v_13899:
    goto v_13895;
v_13896:
    goto v_13897;
v_13898:
    fn = elt(env, 6); // general!-modular!-times
    v_13911 = (*qfn2(fn))(fn, v_13912, v_13911);
    env = stack[-3];
    stack[-2] = v_13911;
    goto v_13889;
v_13891:
v_13889:
    goto v_13907;
v_13903:
    v_13912 = stack[0];
    goto v_13904;
v_13905:
    v_13911 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13906;
v_13907:
    goto v_13903;
v_13904:
    goto v_13905;
v_13906:
    v_13911 = quot2(v_13912, v_13911);
    env = stack[-3];
    stack[0] = v_13911;
    goto v_13866;
v_13865:
    v_13911 = stack[-2];
    goto v_13747;
v_13750:
    v_13911 = nil;
v_13747:
    return onevalue(v_13911);
}



// Code for random!-teeny!-prime

static LispObject CC_randomKteenyKprime(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13809, v_13810, v_13811;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13743);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13743;
// end of prologue
    goto v_13757;
v_13753:
    v_13810 = stack[0];
    goto v_13754;
v_13755:
    v_13809 = elt(env, 1); // all
    goto v_13756;
v_13757:
    goto v_13753;
v_13754:
    goto v_13755;
v_13756:
    if (v_13810 == v_13809) goto v_13751;
    else goto v_13752;
v_13751:
    v_13809 = lisp_true;
    goto v_13750;
v_13752:
    goto v_13767;
v_13763:
    v_13809 = stack[0];
    v_13810 = Llength(nil, v_13809);
    env = stack[-2];
    goto v_13764;
v_13765:
    v_13809 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_13766;
v_13767:
    goto v_13763;
v_13764:
    goto v_13765;
v_13766:
    v_13809 = (v_13810 == v_13809 ? lisp_true : nil);
    goto v_13750;
    v_13809 = nil;
v_13750:
    if (v_13809 == nil) goto v_13748;
    v_13809 = nil;
    goto v_13746;
v_13748:
v_13780:
    goto v_13785;
v_13781:
    stack[-1] = qvalue(elt(env, 2)); // teeny!-primes
    goto v_13782;
v_13783:
    goto v_13792;
v_13788:
    fn = elt(env, 3); // next!-random!-number
    v_13810 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_13789;
v_13790:
    v_13809 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_13791;
v_13792:
    goto v_13788;
v_13789:
    goto v_13790;
v_13791:
    v_13809 = Cremainder(v_13810, v_13809);
    env = stack[-2];
    goto v_13784;
v_13785:
    goto v_13781;
v_13782:
    goto v_13783;
v_13784:
    v_13809 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_13809-TAG_FIXNUM)/(16/CELL)));
    v_13811 = v_13809;
    goto v_13804;
v_13800:
    v_13810 = v_13811;
    goto v_13801;
v_13802:
    v_13809 = stack[0];
    goto v_13803;
v_13804:
    goto v_13800;
v_13801:
    goto v_13802;
v_13803:
    v_13809 = Lmember(nil, v_13810, v_13809);
    if (v_13809 == nil) goto v_13799;
    goto v_13780;
v_13799:
    v_13809 = v_13811;
    goto v_13746;
    v_13809 = nil;
v_13746:
    return onevalue(v_13809);
}



// Code for refprint

static LispObject CC_refprint(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13840, v_13841;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13743);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_13743;
// end of prologue
    v_13840 = qvalue(elt(env, 1)); // cloc!*
    if (v_13840 == nil) goto v_13752;
    v_13840 = qvalue(elt(env, 1)); // cloc!*
    v_13840 = qcar(v_13840);
    goto v_13750;
v_13752:
    v_13840 = elt(env, 2); // "*TTYINPUT*"
    goto v_13750;
    v_13840 = nil;
v_13750:
    stack[-4] = v_13840;
    goto v_13767;
v_13763:
    v_13841 = stack[-4];
    goto v_13764;
v_13765:
    v_13840 = qvalue(elt(env, 3)); // pfiles!*
    goto v_13766;
v_13767:
    goto v_13763;
v_13764:
    goto v_13765;
v_13766:
    v_13840 = Lassoc(nil, v_13841, v_13840);
    qvalue(elt(env, 4)) = v_13840; // curfun!*
    if (v_13840 == nil) goto v_13762;
    v_13840 = qvalue(elt(env, 4)); // curfun!*
    v_13840 = qcar(v_13840);
    stack[-4] = v_13840;
    v_13840 = qvalue(elt(env, 4)); // curfun!*
    v_13840 = qcdr(v_13840);
    qvalue(elt(env, 4)) = v_13840; // curfun!*
    goto v_13760;
v_13762:
    goto v_13784;
v_13778:
    stack[0] = stack[-4];
    goto v_13779;
v_13780:
    v_13840 = elt(env, 5); // g
    v_13841 = Lgensym1(nil, v_13840);
    env = stack[-5];
    qvalue(elt(env, 4)) = v_13841; // curfun!*
    goto v_13781;
v_13782:
    v_13840 = qvalue(elt(env, 3)); // pfiles!*
    goto v_13783;
v_13784:
    goto v_13778;
v_13779:
    goto v_13780;
v_13781:
    goto v_13782;
v_13783:
    v_13840 = acons(stack[0], v_13841, v_13840);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_13840; // pfiles!*
    v_13840 = stack[-4];
    v_13840 = Lexplode(nil, v_13840);
    env = stack[-5];
    v_13840 = qcdr(v_13840);
    v_13840 = Lnreverse(nil, v_13840);
    env = stack[-5];
    v_13840 = qcdr(v_13840);
    v_13840 = Lnreverse(nil, v_13840);
    env = stack[-5];
    stack[-2] = v_13840;
    goto v_13802;
v_13796:
    stack[-1] = qvalue(elt(env, 4)); // curfun!*
    goto v_13797;
v_13798:
    stack[0] = elt(env, 6); // rccnam
    goto v_13799;
v_13800:
    goto v_13810;
v_13806:
    v_13840 = stack[-2];
    v_13841 = Llength(nil, v_13840);
    env = stack[-5];
    goto v_13807;
v_13808:
    v_13840 = stack[-2];
    goto v_13809;
v_13810:
    goto v_13806;
v_13807:
    goto v_13808;
v_13809:
    v_13840 = cons(v_13841, v_13840);
    env = stack[-5];
    goto v_13801;
v_13802:
    goto v_13796;
v_13797:
    goto v_13798;
v_13799:
    goto v_13800;
v_13801:
    v_13840 = Lputprop(nil, 3, stack[-1], stack[0], v_13840);
    env = stack[-5];
    goto v_13760;
v_13760:
    v_13840 = qvalue(elt(env, 1)); // cloc!*
    if (v_13840 == nil) goto v_13817;
    v_13840 = qvalue(elt(env, 1)); // cloc!*
    v_13840 = qcdr(v_13840);
    if (v_13840 == nil) goto v_13817;
    goto v_13828;
v_13824:
    v_13841 = stack[-4];
    goto v_13825;
v_13826:
    v_13840 = qvalue(elt(env, 1)); // cloc!*
    v_13840 = qcdr(v_13840);
    goto v_13827;
v_13828:
    goto v_13824;
v_13825:
    goto v_13826;
v_13827:
    v_13840 = cons(v_13841, v_13840);
    env = stack[-5];
    goto v_13815;
v_13817:
    v_13840 = nil;
    goto v_13815;
    v_13840 = nil;
v_13815:
    qvalue(elt(env, 7)) = v_13840; // curlin!*
    v_13840 = nil;
    qvalue(elt(env, 8)) = v_13840; // locls!*
    qvalue(elt(env, 9)) = v_13840; // globs!*
    qvalue(elt(env, 10)) = v_13840; // calls!*
    v_13840 = stack[-3];
    fn = elt(env, 11); // anform
    v_13840 = (*qfn1(fn))(fn, v_13840);
    env = stack[-5];
    v_13840 = qvalue(elt(env, 4)); // curfun!*
    fn = elt(env, 12); // outrefend
    v_13840 = (*qfn1(fn))(fn, v_13840);
    v_13840 = nil;
    return onevalue(v_13840);
}



// Code for polynomlistreduce

static LispObject CC_polynomlistreduce(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13858, v_13859, v_13860;
    LispObject fn;
    LispObject v_13745, v_13744, v_13743;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "polynomlistreduce");
    va_start(aa, nargs);
    v_13743 = va_arg(aa, LispObject);
    v_13744 = va_arg(aa, LispObject);
    v_13745 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13745,v_13744,v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13743,v_13744,v_13745);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_13745;
    stack[-2] = v_13744;
    stack[-3] = v_13743;
// end of prologue
    v_13858 = nil;
    v_13858 = ncons(v_13858);
    env = stack[-5];
    stack[-4] = v_13858;
    v_13858 = stack[-2];
    v_13858 = qcar(v_13858);
    if (v_13858 == nil) goto v_13755;
    else goto v_13756;
v_13755:
    v_13858 = stack[-4];
    goto v_13750;
v_13756:
v_13763:
    v_13858 = stack[-2];
    v_13858 = qcar(v_13858);
    if (v_13858 == nil) goto v_13766;
    else goto v_13767;
v_13766:
    goto v_13762;
v_13767:
    goto v_13778;
v_13772:
    v_13860 = stack[-3];
    goto v_13773;
v_13774:
    v_13859 = stack[-2];
    goto v_13775;
v_13776:
    v_13858 = stack[-1];
    goto v_13777;
v_13778:
    goto v_13772;
v_13773:
    goto v_13774;
v_13775:
    goto v_13776;
v_13777:
    fn = elt(env, 1); // polynomlistfinddivisor
    v_13858 = (*qfnn(fn))(fn, 3, v_13860, v_13859, v_13858);
    env = stack[-5];
v_13784:
    v_13859 = v_13858;
    if (v_13859 == nil) goto v_13787;
    else goto v_13788;
v_13787:
    goto v_13783;
v_13788:
    goto v_13796;
v_13792:
    v_13859 = stack[-2];
    goto v_13793;
v_13794:
    goto v_13795;
v_13796:
    goto v_13792;
v_13793:
    goto v_13794;
v_13795:
    fn = elt(env, 2); // polynomreduceby
    v_13858 = (*qfn2(fn))(fn, v_13859, v_13858);
    env = stack[-5];
    goto v_13806;
v_13800:
    v_13860 = stack[-3];
    goto v_13801;
v_13802:
    v_13859 = stack[-2];
    goto v_13803;
v_13804:
    v_13858 = stack[-1];
    goto v_13805;
v_13806:
    goto v_13800;
v_13801:
    goto v_13802;
v_13803:
    goto v_13804;
v_13805:
    fn = elt(env, 1); // polynomlistfinddivisor
    v_13858 = (*qfnn(fn))(fn, 3, v_13860, v_13859, v_13858);
    env = stack[-5];
    goto v_13784;
v_13783:
    v_13858 = stack[-2];
    v_13858 = qcar(v_13858);
    if (v_13858 == nil) goto v_13814;
    goto v_13822;
v_13818:
    stack[0] = stack[-4];
    goto v_13819;
v_13820:
    goto v_13831;
v_13825:
    v_13858 = stack[-2];
    v_13860 = qcar(v_13858);
    goto v_13826;
v_13827:
    v_13859 = nil;
    goto v_13828;
v_13829:
    v_13858 = nil;
    goto v_13830;
v_13831:
    goto v_13825;
v_13826:
    goto v_13827;
v_13828:
    goto v_13829;
v_13830:
    v_13858 = list2star(v_13860, v_13859, v_13858);
    env = stack[-5];
    goto v_13821;
v_13822:
    goto v_13818;
v_13819:
    goto v_13820;
v_13821:
    fn = elt(env, 3); // polynomadd
    v_13858 = (*qfn2(fn))(fn, stack[0], v_13858);
    env = stack[-5];
    goto v_13841;
v_13837:
    goto v_13847;
v_13843:
    v_13859 = stack[-2];
    goto v_13844;
v_13845:
    v_13858 = stack[-2];
    v_13858 = qcdr(v_13858);
    v_13858 = qcar(v_13858);
    goto v_13846;
v_13847:
    goto v_13843;
v_13844:
    goto v_13845;
v_13846:
    v_13859 = Lrplaca(nil, v_13859, v_13858);
    env = stack[-5];
    goto v_13838;
v_13839:
    v_13858 = stack[-2];
    v_13858 = qcdr(v_13858);
    v_13858 = qcdr(v_13858);
    goto v_13840;
v_13841:
    goto v_13837;
v_13838:
    goto v_13839;
v_13840:
    v_13858 = Lrplacd(nil, v_13859, v_13858);
    env = stack[-5];
    goto v_13812;
v_13814:
v_13812:
    goto v_13763;
v_13762:
    v_13858 = stack[-4];
v_13750:
    return onevalue(v_13858);
}



// Code for pasf_sacat

static LispObject CC_pasf_sacat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13748, v_13749, v_13750;
    LispObject v_13745, v_13744, v_13743;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pasf_sacat");
    va_start(aa, nargs);
    v_13743 = va_arg(aa, LispObject);
    v_13744 = va_arg(aa, LispObject);
    v_13745 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13748 = v_13745;
    v_13749 = v_13744;
    v_13750 = v_13743;
// end of prologue
    v_13748 = nil;
    return onevalue(v_13748);
}



// Code for unaryrd

static LispObject CC_unaryrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13751;
    LispObject fn;
    argcheck(nargs, 0, "unaryrd");
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
    v_13751 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_13751;
    fn = elt(env, 2); // lex
    v_13751 = (*qfnn(fn))(fn, 0);
    v_13751 = stack[0];
    return ncons(v_13751);
    return onevalue(v_13751);
}



// Code for groedeletip

static LispObject CC_groedeletip(LispObject env,
                         LispObject v_13743, LispObject v_13744)
{
    env = qenv(env);
    LispObject v_13815, v_13816;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13744,v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13743,v_13744);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13744;
    stack[-1] = v_13743;
// end of prologue
v_13751:
    v_13815 = stack[0];
    if (v_13815 == nil) goto v_13754;
    goto v_13763;
v_13759:
    v_13816 = stack[-1];
    goto v_13760;
v_13761:
    v_13815 = stack[0];
    v_13815 = qcar(v_13815);
    goto v_13762;
v_13763:
    goto v_13759;
v_13760:
    goto v_13761;
v_13762:
    if (equal(v_13816, v_13815)) goto v_13758;
    else goto v_13754;
v_13758:
    goto v_13755;
v_13754:
    goto v_13750;
v_13755:
    v_13815 = stack[0];
    v_13815 = qcdr(v_13815);
    stack[0] = v_13815;
    goto v_13751;
v_13750:
    v_13815 = stack[0];
    if (v_13815 == nil) goto v_13772;
    else goto v_13773;
v_13772:
    v_13815 = nil;
    goto v_13748;
v_13773:
    v_13815 = stack[0];
    stack[-2] = v_13815;
v_13779:
    v_13815 = stack[0];
    v_13815 = qcdr(v_13815);
    if (v_13815 == nil) goto v_13782;
    else goto v_13783;
v_13782:
    goto v_13778;
v_13783:
    goto v_13795;
v_13791:
    v_13816 = stack[-1];
    goto v_13792;
v_13793:
    v_13815 = stack[0];
    v_13815 = qcdr(v_13815);
    v_13815 = qcar(v_13815);
    goto v_13794;
v_13795:
    goto v_13791;
v_13792:
    goto v_13793;
v_13794:
    if (equal(v_13816, v_13815)) goto v_13789;
    else goto v_13790;
v_13789:
    goto v_13805;
v_13801:
    v_13816 = stack[0];
    goto v_13802;
v_13803:
    v_13815 = stack[0];
    v_13815 = qcdr(v_13815);
    v_13815 = qcdr(v_13815);
    goto v_13804;
v_13805:
    goto v_13801;
v_13802:
    goto v_13803;
v_13804:
    fn = elt(env, 1); // setcdr
    v_13815 = (*qfn2(fn))(fn, v_13816, v_13815);
    env = stack[-3];
    goto v_13788;
v_13790:
    v_13815 = stack[0];
    v_13815 = qcdr(v_13815);
    stack[0] = v_13815;
    goto v_13788;
v_13788:
    goto v_13779;
v_13778:
    v_13815 = stack[-2];
v_13748:
    return onevalue(v_13815);
}



// Code for mktails

static LispObject CC_mktails(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13810, v_13811, v_13812;
    LispObject fn;
    LispObject v_13745, v_13744, v_13743;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mktails");
    va_start(aa, nargs);
    v_13743 = va_arg(aa, LispObject);
    v_13744 = va_arg(aa, LispObject);
    v_13745 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13745,v_13744,v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13743,v_13744,v_13745);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_13811 = v_13745;
    stack[-2] = v_13744;
    v_13812 = v_13743;
// end of prologue
    stack[0] = nil;
    v_13810 = v_13812;
    if (v_13810 == nil) goto v_13755;
    else goto v_13756;
v_13755:
    goto v_13763;
v_13759:
    v_13810 = nil;
    goto v_13760;
v_13761:
    goto v_13762;
v_13763:
    goto v_13759;
v_13760:
    goto v_13761;
v_13762:
    return cons(v_13810, v_13811);
v_13756:
    v_13810 = v_13812;
    stack[-3] = v_13810;
    v_13810 = v_13811;
    stack[-1] = v_13810;
v_13770:
    v_13810 = stack[-3];
    if (v_13810 == nil) goto v_13773;
    else goto v_13774;
v_13773:
    goto v_13769;
v_13774:
    goto v_13784;
v_13778:
    v_13810 = stack[-3];
    v_13812 = qcar(v_13810);
    goto v_13779;
v_13780:
    v_13811 = stack[-2];
    goto v_13781;
v_13782:
    v_13810 = stack[-1];
    goto v_13783;
v_13784:
    goto v_13778;
v_13779:
    goto v_13780;
v_13781:
    goto v_13782;
v_13783:
    fn = elt(env, 1); // mktails1
    v_13810 = (*qfnn(fn))(fn, 3, v_13812, v_13811, v_13810);
    env = stack[-4];
    v_13811 = v_13810;
    v_13810 = v_13811;
    v_13810 = qcdr(v_13810);
    stack[-1] = v_13810;
    goto v_13796;
v_13792:
    v_13810 = v_13811;
    v_13811 = qcar(v_13810);
    goto v_13793;
v_13794:
    v_13810 = stack[0];
    goto v_13795;
v_13796:
    goto v_13792;
v_13793:
    goto v_13794;
v_13795:
    v_13810 = Lappend(nil, v_13811, v_13810);
    env = stack[-4];
    stack[0] = v_13810;
    v_13810 = stack[-3];
    v_13810 = qcdr(v_13810);
    stack[-3] = v_13810;
    goto v_13770;
v_13769:
    goto v_13807;
v_13803:
    v_13811 = stack[0];
    goto v_13804;
v_13805:
    v_13810 = stack[-1];
    goto v_13806;
v_13807:
    goto v_13803;
v_13804:
    goto v_13805;
v_13806:
    return cons(v_13811, v_13810);
    return onevalue(v_13810);
}



// Code for numlist_ordp

static LispObject CC_numlist_ordp(LispObject env,
                         LispObject v_13743, LispObject v_13744)
{
    env = qenv(env);
    LispObject v_13757, v_13758, v_13759;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13757 = v_13744;
    v_13758 = v_13743;
// end of prologue
    goto v_13753;
v_13747:
    v_13759 = v_13758;
    goto v_13748;
v_13749:
    v_13758 = v_13757;
    goto v_13750;
v_13751:
    v_13757 = elt(env, 1); // lambda_ygm6np4pcqv31
    goto v_13752;
v_13753:
    goto v_13747;
v_13748:
    goto v_13749;
v_13750:
    goto v_13751;
v_13752:
    {
        fn = elt(env, 2); // cons_ordp
        return (*qfnn(fn))(fn, 3, v_13759, v_13758, v_13757);
    }
}



// Code for lambda_ygm6np4pcqv31

static LispObject CC_lambda_ygm6np4pcqv31(LispObject env,
                         LispObject v_13743, LispObject v_13744)
{
    env = qenv(env);
    LispObject v_13754, v_13755;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13754 = v_13744;
    v_13755 = v_13743;
// end of prologue
    goto v_13751;
v_13747:
    goto v_13748;
v_13749:
    goto v_13750;
v_13751:
    goto v_13747;
v_13748:
    goto v_13749;
v_13750:
        return Lleq(nil, v_13755, v_13754);
}



// Code for subf

static LispObject CC_subf(LispObject env,
                         LispObject v_13743, LispObject v_13744)
{
    env = qenv(env);
    LispObject v_13940, v_13941;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13744,v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13743,v_13744);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-6] = v_13744;
    stack[-7] = v_13743;
// end of prologue
// Binding alglist!*
// FLUIDBIND: reloadenv=9 litvec-offset=1 saveloc=8
{   bind_fluid_stack bind_fluid_var(-9, 1, -8);
    qvalue(elt(env, 1)) = nil; // alglist!*
    stack[-5] = nil;
    stack[-4] = nil;
    v_13940 = nil;
    v_13940 = ncons(v_13940);
    env = stack[-9];
    qvalue(elt(env, 1)) = v_13940; // alglist!*
    v_13940 = stack[-7];
    if (!consp(v_13940)) goto v_13760;
    else goto v_13761;
v_13760:
    v_13940 = lisp_true;
    goto v_13759;
v_13761:
    v_13940 = stack[-7];
    v_13940 = qcar(v_13940);
    v_13940 = (consp(v_13940) ? nil : lisp_true);
    goto v_13759;
    v_13940 = nil;
v_13759:
    if (v_13940 == nil) goto v_13757;
    v_13940 = stack[-7];
    fn = elt(env, 5); // !*d2q
    v_13940 = (*qfn1(fn))(fn, v_13940);
    goto v_13751;
v_13757:
    v_13940 = qvalue(elt(env, 2)); // ncmp!*
    if (v_13940 == nil) goto v_13772;
    v_13940 = stack[-7];
    fn = elt(env, 6); // noncomexpf
    v_13940 = (*qfn1(fn))(fn, v_13940);
    env = stack[-9];
    if (v_13940 == nil) goto v_13772;
    goto v_13783;
v_13779:
    v_13941 = stack[-7];
    goto v_13780;
v_13781:
    v_13940 = stack[-6];
    goto v_13782;
v_13783:
    goto v_13779;
v_13780:
    goto v_13781;
v_13782:
    fn = elt(env, 7); // subf1
    v_13940 = (*qfn2(fn))(fn, v_13941, v_13940);
    goto v_13751;
v_13772:
    goto v_13792;
v_13788:
    v_13940 = stack[-6];
    stack[-3] = v_13940;
    v_13940 = stack[-3];
    if (v_13940 == nil) goto v_13802;
    else goto v_13803;
v_13802:
    v_13940 = nil;
    stack[0] = v_13940;
    goto v_13797;
v_13803:
    v_13940 = stack[-3];
    v_13940 = qcar(v_13940);
    v_13940 = qcar(v_13940);
    v_13940 = ncons(v_13940);
    env = stack[-9];
    stack[-1] = v_13940;
    stack[-2] = v_13940;
v_13798:
    v_13940 = stack[-3];
    v_13940 = qcdr(v_13940);
    stack[-3] = v_13940;
    v_13940 = stack[-3];
    if (v_13940 == nil) goto v_13816;
    else goto v_13817;
v_13816:
    v_13940 = stack[-2];
    stack[0] = v_13940;
    goto v_13797;
v_13817:
    goto v_13825;
v_13821:
    stack[0] = stack[-1];
    goto v_13822;
v_13823:
    v_13940 = stack[-3];
    v_13940 = qcar(v_13940);
    v_13940 = qcar(v_13940);
    v_13940 = ncons(v_13940);
    env = stack[-9];
    goto v_13824;
v_13825:
    goto v_13821;
v_13822:
    goto v_13823;
v_13824:
    v_13940 = Lrplacd(nil, stack[0], v_13940);
    env = stack[-9];
    v_13940 = stack[-1];
    v_13940 = qcdr(v_13940);
    stack[-1] = v_13940;
    goto v_13798;
v_13797:
    goto v_13789;
v_13790:
    goto v_13840;
v_13836:
    v_13941 = stack[-7];
    goto v_13837;
v_13838:
    v_13940 = nil;
    goto v_13839;
v_13840:
    goto v_13836;
v_13837:
    goto v_13838;
v_13839:
    fn = elt(env, 8); // kernord
    v_13940 = (*qfn2(fn))(fn, v_13941, v_13940);
    env = stack[-9];
    goto v_13791;
v_13792:
    goto v_13788;
v_13789:
    goto v_13790;
v_13791:
    fn = elt(env, 9); // intersection
    v_13940 = (*qfn2(fn))(fn, stack[0], v_13940);
    env = stack[-9];
    v_13940 = Lreverse(nil, v_13940);
    env = stack[-9];
    stack[0] = v_13940;
    v_13940 = stack[0];
    fn = elt(env, 10); // setkorder
    v_13940 = (*qfn1(fn))(fn, v_13940);
    env = stack[-9];
    stack[0] = v_13940;
    goto v_13850;
v_13846:
    v_13940 = stack[-7];
    fn = elt(env, 11); // reorder
    v_13941 = (*qfn1(fn))(fn, v_13940);
    env = stack[-9];
    goto v_13847;
v_13848:
    v_13940 = stack[-6];
    goto v_13849;
v_13850:
    goto v_13846;
v_13847:
    goto v_13848;
v_13849:
    fn = elt(env, 7); // subf1
    v_13940 = (*qfn2(fn))(fn, v_13941, v_13940);
    env = stack[-9];
    stack[-7] = v_13940;
v_13856:
    goto v_13869;
v_13865:
    v_13941 = stack[-7];
    goto v_13866;
v_13867:
    v_13940 = stack[-4];
    goto v_13868;
v_13869:
    goto v_13865;
v_13866:
    goto v_13867;
v_13868:
    v_13940 = Lmember(nil, v_13941, v_13940);
    if (v_13940 == nil) goto v_13863;
    else goto v_13864;
v_13863:
    goto v_13882;
v_13878:
    stack[-1] = elt(env, 3); // expt
    goto v_13879;
v_13880:
    v_13940 = stack[-7];
    v_13940 = qcar(v_13940);
    fn = elt(env, 12); // kernels
    v_13940 = (*qfn1(fn))(fn, v_13940);
    env = stack[-9];
    goto v_13881;
v_13882:
    goto v_13878;
v_13879:
    goto v_13880;
v_13881:
    v_13940 = Latsoc(nil, stack[-1], v_13940);
    if (v_13940 == nil) goto v_13877;
    else goto v_13876;
v_13877:
    goto v_13893;
v_13889:
    stack[-1] = elt(env, 3); // expt
    goto v_13890;
v_13891:
    v_13940 = stack[-7];
    v_13940 = qcdr(v_13940);
    fn = elt(env, 12); // kernels
    v_13940 = (*qfn1(fn))(fn, v_13940);
    env = stack[-9];
    goto v_13892;
v_13893:
    goto v_13889;
v_13890:
    goto v_13891;
v_13892:
    v_13940 = Latsoc(nil, stack[-1], v_13940);
    if (v_13940 == nil) goto v_13888;
    else goto v_13876;
v_13888:
    v_13940 = nil;
    goto v_13874;
v_13876:
    goto v_13906;
v_13902:
    v_13940 = stack[-7];
    fn = elt(env, 13); // prepsq
    v_13941 = (*qfn1(fn))(fn, v_13940);
    env = stack[-9];
    stack[-5] = v_13941;
    goto v_13903;
v_13904:
    v_13940 = qvalue(elt(env, 4)); // varstack!*
    goto v_13905;
v_13906:
    goto v_13902;
v_13903:
    goto v_13904;
v_13905:
    v_13940 = Lmember(nil, v_13941, v_13940);
    v_13940 = (v_13940 == nil ? lisp_true : nil);
    goto v_13874;
    v_13940 = nil;
v_13874:
    goto v_13862;
v_13864:
    v_13940 = nil;
    goto v_13862;
    v_13940 = nil;
v_13862:
    if (v_13940 == nil) goto v_13859;
    else goto v_13860;
v_13859:
    goto v_13855;
v_13860:
    goto v_13921;
v_13917:
    v_13941 = stack[-7];
    goto v_13918;
v_13919:
    v_13940 = stack[-4];
    goto v_13920;
v_13921:
    goto v_13917;
v_13918:
    goto v_13919;
v_13920:
    v_13940 = cons(v_13941, v_13940);
    env = stack[-9];
    stack[-4] = v_13940;
    v_13940 = stack[-5];
    fn = elt(env, 14); // simp
    v_13940 = (*qfn1(fn))(fn, v_13940);
    env = stack[-9];
    stack[-7] = v_13940;
    goto v_13856;
v_13855:
    v_13940 = stack[0];
    fn = elt(env, 10); // setkorder
    v_13940 = (*qfn1(fn))(fn, v_13940);
    env = stack[-9];
    goto v_13933;
v_13929:
    v_13940 = stack[-7];
    v_13940 = qcar(v_13940);
    fn = elt(env, 11); // reorder
    stack[0] = (*qfn1(fn))(fn, v_13940);
    env = stack[-9];
    goto v_13930;
v_13931:
    v_13940 = stack[-7];
    v_13940 = qcdr(v_13940);
    fn = elt(env, 11); // reorder
    v_13940 = (*qfn1(fn))(fn, v_13940);
    env = stack[-9];
    goto v_13932;
v_13933:
    goto v_13929;
v_13930:
    goto v_13931;
v_13932:
    v_13940 = cons(stack[0], v_13940);
v_13751:
    ;}  // end of a binding scope
    return onevalue(v_13940);
}



// Code for lalr_prin_production

static LispObject CC_lalr_prin_production(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13753;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13743);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_13743;
// end of prologue
    v_13753 = stack[0];
    v_13753 = qcar(v_13753);
    fn = elt(env, 2); // lalr_prin_symbol
    v_13753 = (*qfn1(fn))(fn, v_13753);
    env = stack[-1];
    v_13753 = elt(env, 1); // " -> "
    v_13753 = Lprinc(nil, v_13753);
    env = stack[-1];
    v_13753 = stack[0];
    v_13753 = qcdr(v_13753);
    {
        fn = elt(env, 3); // lalr_prin_rhs
        return (*qfn1(fn))(fn, v_13753);
    }
}



// Code for cl_pnf

static LispObject CC_cl_pnf(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13748;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13743);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_13748 = v_13743;
// end of prologue
    fn = elt(env, 1); // rl_nnf
    v_13748 = (*qfn1(fn))(fn, v_13748);
    env = stack[0];
    {
        fn = elt(env, 2); // cl_pnf1
        return (*qfn1(fn))(fn, v_13748);
    }
}



// Code for poly!-multfnc

static LispObject CC_polyKmultfnc(LispObject env,
                         LispObject v_13743, LispObject v_13744)
{
    env = qenv(env);
    LispObject v_13969, v_13970, v_13971;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13744,v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13743,v_13744);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_13744;
    stack[-2] = v_13743;
// end of prologue
    v_13969 = qvalue(elt(env, 1)); // !*sstools!-loaded
    if (v_13969 == nil) goto v_13749;
    goto v_13756;
v_13752:
    v_13970 = stack[-2];
    goto v_13753;
v_13754:
    v_13969 = stack[-1];
    goto v_13755;
v_13756:
    goto v_13752;
v_13753:
    goto v_13754;
v_13755:
    {
        fn = elt(env, 3); // sstools!-multfnc
        return (*qfn2(fn))(fn, v_13970, v_13969);
    }
v_13749:
    goto v_13770;
v_13766:
    v_13969 = stack[-2];
    v_13969 = qcar(v_13969);
    stack[0] = qcdr(v_13969);
    goto v_13767;
v_13768:
    v_13969 = stack[-1];
    v_13969 = qcar(v_13969);
    v_13969 = ncons(v_13969);
    env = stack[-4];
    goto v_13769;
v_13770:
    goto v_13766;
v_13767:
    goto v_13768;
v_13769:
    fn = elt(env, 4); // poly!-multf
    v_13969 = (*qfn2(fn))(fn, stack[0], v_13969);
    env = stack[-4];
    stack[-3] = v_13969;
    v_13969 = stack[-3];
    if (v_13969 == nil) goto v_13779;
    else goto v_13780;
v_13779:
    goto v_13778;
v_13780:
    v_13969 = stack[-3];
    if (!consp(v_13969)) goto v_13791;
    else goto v_13792;
v_13791:
    v_13969 = lisp_true;
    goto v_13790;
v_13792:
    v_13969 = stack[-3];
    v_13969 = qcar(v_13969);
    v_13969 = (consp(v_13969) ? nil : lisp_true);
    goto v_13790;
    v_13969 = nil;
v_13790:
    if (v_13969 == nil) goto v_13787;
    else goto v_13788;
v_13787:
    goto v_13804;
v_13800:
    v_13969 = stack[-3];
    v_13969 = qcar(v_13969);
    v_13969 = qcar(v_13969);
    v_13970 = qcar(v_13969);
    goto v_13801;
v_13802:
    v_13969 = stack[-2];
    v_13969 = qcar(v_13969);
    v_13969 = qcar(v_13969);
    v_13969 = qcar(v_13969);
    goto v_13803;
v_13804:
    goto v_13800;
v_13801:
    goto v_13802;
v_13803:
    v_13969 = (v_13970 == v_13969 ? lisp_true : nil);
    goto v_13786;
v_13788:
    v_13969 = nil;
    goto v_13786;
    v_13969 = nil;
v_13786:
    if (v_13969 == nil) goto v_13784;
    goto v_13822;
v_13818:
    goto v_13832;
v_13828:
    v_13969 = stack[-2];
    v_13969 = qcar(v_13969);
    v_13969 = qcar(v_13969);
    stack[0] = qcar(v_13969);
    goto v_13829;
v_13830:
    goto v_13842;
v_13838:
    v_13969 = stack[-2];
    v_13969 = qcar(v_13969);
    v_13969 = qcar(v_13969);
    v_13970 = qcdr(v_13969);
    goto v_13839;
v_13840:
    v_13969 = stack[-3];
    v_13969 = qcar(v_13969);
    v_13969 = qcar(v_13969);
    v_13969 = qcdr(v_13969);
    goto v_13841;
v_13842:
    goto v_13838;
v_13839:
    goto v_13840;
v_13841:
    v_13969 = plus2(v_13970, v_13969);
    env = stack[-4];
    goto v_13831;
v_13832:
    goto v_13828;
v_13829:
    goto v_13830;
v_13831:
    fn = elt(env, 5); // mkspm
    v_13969 = (*qfn2(fn))(fn, stack[0], v_13969);
    env = stack[-4];
    v_13971 = v_13969;
    if (v_13969 == nil) goto v_13825;
    else goto v_13826;
v_13825:
    v_13969 = nil;
    stack[0] = v_13969;
    goto v_13824;
v_13826:
    goto v_13858;
v_13854:
    v_13970 = v_13971;
    goto v_13855;
v_13856:
    v_13969 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13857;
v_13858:
    goto v_13854;
v_13855:
    goto v_13856;
v_13857:
    if (v_13970 == v_13969) goto v_13852;
    else goto v_13853;
v_13852:
    v_13969 = stack[-3];
    v_13969 = qcar(v_13969);
    v_13969 = qcdr(v_13969);
    stack[0] = v_13969;
    goto v_13824;
v_13853:
    goto v_13872;
v_13868:
    v_13970 = v_13971;
    goto v_13869;
v_13870:
    v_13969 = stack[-3];
    v_13969 = qcar(v_13969);
    v_13969 = qcdr(v_13969);
    goto v_13871;
v_13872:
    goto v_13868;
v_13869:
    goto v_13870;
v_13871:
    v_13969 = cons(v_13970, v_13969);
    env = stack[-4];
    v_13969 = ncons(v_13969);
    env = stack[-4];
    stack[0] = v_13969;
    goto v_13824;
    stack[0] = nil;
v_13824:
    goto v_13819;
v_13820:
    goto v_13882;
v_13878:
    goto v_13889;
v_13885:
    v_13969 = stack[-2];
    v_13969 = qcar(v_13969);
    v_13970 = qcar(v_13969);
    goto v_13886;
v_13887:
    v_13969 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13888;
v_13889:
    goto v_13885;
v_13886:
    goto v_13887;
v_13888:
    v_13969 = cons(v_13970, v_13969);
    env = stack[-4];
    v_13970 = ncons(v_13969);
    env = stack[-4];
    goto v_13879;
v_13880:
    v_13969 = stack[-3];
    v_13969 = qcdr(v_13969);
    goto v_13881;
v_13882:
    goto v_13878;
v_13879:
    goto v_13880;
v_13881:
    fn = elt(env, 4); // poly!-multf
    v_13969 = (*qfn2(fn))(fn, v_13970, v_13969);
    env = stack[-4];
    goto v_13821;
v_13822:
    goto v_13818;
v_13819:
    goto v_13820;
v_13821:
    fn = elt(env, 6); // addf
    v_13969 = (*qfn2(fn))(fn, stack[0], v_13969);
    env = stack[-4];
    stack[-3] = v_13969;
    goto v_13778;
v_13784:
    v_13969 = stack[-2];
    v_13969 = qcar(v_13969);
    v_13969 = qcar(v_13969);
    v_13969 = qcar(v_13969);
    fn = elt(env, 7); // noncomp
    v_13969 = (*qfn1(fn))(fn, v_13969);
    env = stack[-4];
    if (v_13969 == nil) goto v_13897;
    goto v_13909;
v_13905:
    v_13969 = stack[-2];
    v_13969 = qcar(v_13969);
    v_13970 = qcar(v_13969);
    goto v_13906;
v_13907:
    v_13969 = stack[-3];
    goto v_13908;
v_13909:
    goto v_13905;
v_13906:
    goto v_13907;
v_13908:
    v_13969 = cons(v_13970, v_13969);
    env = stack[-4];
    v_13969 = ncons(v_13969);
    env = stack[-4];
    stack[-3] = v_13969;
    goto v_13778;
v_13897:
    v_13969 = lisp_true;
// Binding !*!*processed
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 2, 0);
    qvalue(elt(env, 2)) = v_13969; // !*!*processed
    goto v_13923;
v_13919:
    goto v_13930;
v_13926:
    v_13969 = stack[-2];
    v_13969 = qcar(v_13969);
    v_13970 = qcar(v_13969);
    goto v_13927;
v_13928:
    v_13969 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13929;
v_13930:
    goto v_13926;
v_13927:
    goto v_13928;
v_13929:
    v_13969 = cons(v_13970, v_13969);
    env = stack[-4];
    v_13970 = ncons(v_13969);
    env = stack[-4];
    goto v_13920;
v_13921:
    v_13969 = stack[-3];
    goto v_13922;
v_13923:
    goto v_13919;
v_13920:
    goto v_13921;
v_13922:
    fn = elt(env, 4); // poly!-multf
    v_13969 = (*qfn2(fn))(fn, v_13970, v_13969);
    env = stack[-4];
    stack[-3] = v_13969;
    ;}  // end of a binding scope
    goto v_13778;
v_13778:
    goto v_13941;
v_13937:
    goto v_13938;
v_13939:
    goto v_13948;
v_13944:
    goto v_13954;
v_13950:
    v_13969 = stack[-2];
    v_13970 = qcdr(v_13969);
    goto v_13951;
v_13952:
    v_13969 = stack[-1];
    goto v_13953;
v_13954:
    goto v_13950;
v_13951:
    goto v_13952;
v_13953:
    fn = elt(env, 4); // poly!-multf
    stack[0] = (*qfn2(fn))(fn, v_13970, v_13969);
    env = stack[-4];
    goto v_13945;
v_13946:
    goto v_13963;
v_13959:
    v_13969 = stack[-2];
    v_13969 = qcar(v_13969);
    v_13970 = ncons(v_13969);
    env = stack[-4];
    goto v_13960;
v_13961:
    v_13969 = stack[-1];
    v_13969 = qcdr(v_13969);
    goto v_13962;
v_13963:
    goto v_13959;
v_13960:
    goto v_13961;
v_13962:
    fn = elt(env, 4); // poly!-multf
    v_13969 = (*qfn2(fn))(fn, v_13970, v_13969);
    env = stack[-4];
    goto v_13947;
v_13948:
    goto v_13944;
v_13945:
    goto v_13946;
v_13947:
    fn = elt(env, 6); // addf
    v_13969 = (*qfn2(fn))(fn, stack[0], v_13969);
    env = stack[-4];
    goto v_13940;
v_13941:
    goto v_13937;
v_13938:
    goto v_13939;
v_13940:
    {
        LispObject v_13976 = stack[-3];
        fn = elt(env, 6); // addf
        return (*qfn2(fn))(fn, v_13976, v_13969);
    }
    goto v_13747;
    v_13969 = nil;
v_13747:
    return onevalue(v_13969);
}



// Code for lto_nconcn

static LispObject CC_lto_nconcn(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13766, v_13767;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13743);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_13767 = v_13743;
// end of prologue
    v_13766 = v_13767;
    v_13766 = qcdr(v_13766);
    if (v_13766 == nil) goto v_13748;
    goto v_13756;
v_13752:
    v_13766 = v_13767;
    stack[0] = qcar(v_13766);
    goto v_13753;
v_13754:
    v_13766 = v_13767;
    v_13766 = qcdr(v_13766);
    v_13766 = CC_lto_nconcn(elt(env, 0), v_13766);
    goto v_13755;
v_13756:
    goto v_13752;
v_13753:
    goto v_13754;
v_13755:
    {
        LispObject v_13769 = stack[0];
        return Lnconc(nil, v_13769, v_13766);
    }
v_13748:
    v_13766 = v_13767;
    v_13766 = qcar(v_13766);
    goto v_13746;
    v_13766 = nil;
v_13746:
    return onevalue(v_13766);
}



// Code for inprint

static LispObject CC_inprint(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_14184, v_14185, v_14186;
    LispObject fn;
    LispObject v_13745, v_13744, v_13743;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "inprint");
    va_start(aa, nargs);
    v_13743 = va_arg(aa, LispObject);
    v_13744 = va_arg(aa, LispObject);
    v_13745 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13745,v_13744,v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13743,v_13744,v_13745);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_13745;
    stack[-2] = v_13744;
    stack[-3] = v_13743;
// end of prologue
    stack[-4] = nil;
    stack[0] = nil;
    goto v_13764;
v_13760:
    v_14185 = stack[-3];
    goto v_13761;
v_13762:
    v_14184 = elt(env, 1); // times
    goto v_13763;
v_13764:
    goto v_13760;
v_13761:
    goto v_13762;
v_13763:
    if (v_14185 == v_14184) goto v_13758;
    else goto v_13759;
v_13758:
    v_14184 = qvalue(elt(env, 2)); // !*nat
    if (v_14184 == nil) goto v_13769;
    else goto v_13770;
v_13769:
    v_14184 = nil;
    goto v_13768;
v_13770:
    v_14184 = qvalue(elt(env, 3)); // !*asterisk
    v_14184 = (v_14184 == nil ? lisp_true : nil);
    goto v_13768;
    v_14184 = nil;
v_13768:
    goto v_13757;
v_13759:
    v_14184 = nil;
    goto v_13757;
    v_14184 = nil;
v_13757:
    if (v_14184 == nil) goto v_13755;
    v_14184 = elt(env, 4); // times2
    stack[-3] = v_14184;
    goto v_13788;
v_13782:
    v_14186 = elt(env, 4); // times2
    goto v_13783;
v_13784:
    v_14185 = elt(env, 5); // infix
    goto v_13785;
v_13786:
    v_14184 = elt(env, 1); // times
    if (!symbolp(v_14184)) v_14184 = nil;
    else { v_14184 = qfastgets(v_14184);
           if (v_14184 != nil) { v_14184 = elt(v_14184, 23); // infix
#ifdef RECORD_GET
             if (v_14184 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_14184 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_14184 == SPID_NOPROP) v_14184 = nil; }}
#endif
    goto v_13787;
v_13788:
    goto v_13782;
v_13783:
    goto v_13784;
v_13785:
    goto v_13786;
v_13787:
    v_14184 = Lputprop(nil, 3, v_14186, v_14185, v_14184);
    env = stack[-5];
    goto v_13800;
v_13794:
    v_14186 = elt(env, 4); // times2
    goto v_13795;
v_13796:
    v_14185 = elt(env, 6); // prtch
    goto v_13797;
v_13798:
    v_14184 = elt(env, 7); // " "
    goto v_13799;
v_13800:
    goto v_13794;
v_13795:
    goto v_13796;
v_13797:
    goto v_13798;
v_13799:
    v_14184 = Lputprop(nil, 3, v_14186, v_14185, v_14184);
    env = stack[-5];
    goto v_13753;
v_13755:
v_13753:
    goto v_13816;
v_13812:
    v_14185 = stack[-3];
    goto v_13813;
v_13814:
    v_14184 = elt(env, 8); // plus
    goto v_13815;
v_13816:
    goto v_13812;
v_13813:
    goto v_13814;
v_13815:
    if (v_14185 == v_14184) goto v_13810;
    else goto v_13811;
v_13810:
    v_14184 = qvalue(elt(env, 9)); // !*revpri
    goto v_13809;
v_13811:
    v_14184 = nil;
    goto v_13809;
    v_14184 = nil;
v_13809:
    if (v_14184 == nil) goto v_13807;
    v_14184 = stack[-1];
    v_14184 = Lreverse(nil, v_14184);
    env = stack[-5];
    stack[-1] = v_14184;
    goto v_13805;
v_13807:
v_13805:
    v_14184 = stack[-3];
    if (!symbolp(v_14184)) v_14184 = nil;
    else { v_14184 = qfastgets(v_14184);
           if (v_14184 != nil) { v_14184 = elt(v_14184, 49); // alt
#ifdef RECORD_GET
             if (v_14184 != SPID_NOPROP)
                record_get(elt(fastget_names, 49), 1);
             else record_get(elt(fastget_names, 49), 0),
                v_14184 = nil; }
           else record_get(elt(fastget_names, 49), 0); }
#else
             if (v_14184 == SPID_NOPROP) v_14184 = nil; }}
#endif
    if (v_14184 == nil) goto v_13827;
    else goto v_13828;
v_13827:
    goto v_13839;
v_13835:
    v_14185 = stack[-3];
    goto v_13836;
v_13837:
    v_14184 = elt(env, 10); // not
    goto v_13838;
v_13839:
    goto v_13835;
v_13836:
    goto v_13837;
v_13838:
    if (v_14185 == v_14184) goto v_13833;
    else goto v_13834;
v_13833:
    v_14184 = stack[-3];
    fn = elt(env, 20); // oprin
    v_14184 = (*qfn1(fn))(fn, v_14184);
    env = stack[-5];
    goto v_13832;
v_13834:
    goto v_13854;
v_13850:
    v_14185 = stack[-3];
    goto v_13851;
v_13852:
    v_14184 = elt(env, 11); // setq
    goto v_13853;
v_13854:
    goto v_13850;
v_13851:
    goto v_13852;
v_13853:
    if (v_14185 == v_14184) goto v_13848;
    else goto v_13849;
v_13848:
    v_14184 = stack[-1];
    v_14184 = Lreverse(nil, v_14184);
    env = stack[-5];
    v_14184 = qcar(v_14184);
    stack[-4] = v_14184;
    if (!consp(v_14184)) goto v_13860;
    v_14184 = stack[-4];
    v_14184 = qcar(v_14184);
    if (symbolp(v_14184)) goto v_13867;
    v_14184 = nil;
    goto v_13865;
v_13867:
    v_14184 = stack[-4];
    fn = elt(env, 21); // getrtype
    v_14184 = (*qfn1(fn))(fn, v_14184);
    env = stack[-5];
    stack[0] = v_14184;
    if (v_14184 == nil) goto v_13875;
    else goto v_13876;
v_13875:
    v_14184 = nil;
    goto v_13874;
v_13876:
    goto v_13887;
v_13883:
    goto v_13893;
v_13889:
    v_14185 = stack[0];
    goto v_13890;
v_13891:
    v_14184 = elt(env, 12); // tag
    goto v_13892;
v_13893:
    goto v_13889;
v_13890:
    goto v_13891;
v_13892:
    v_14185 = get(v_14185, v_14184);
    env = stack[-5];
    goto v_13884;
v_13885:
    v_14184 = elt(env, 13); // setprifn
    goto v_13886;
v_13887:
    goto v_13883;
v_13884:
    goto v_13885;
v_13886:
    v_14184 = get(v_14185, v_14184);
    env = stack[-5];
    stack[0] = v_14184;
    goto v_13874;
    v_14184 = nil;
v_13874:
    goto v_13865;
    v_14184 = nil;
v_13865:
    goto v_13858;
v_13860:
    v_14184 = nil;
    goto v_13858;
    v_14184 = nil;
v_13858:
    goto v_13847;
v_13849:
    v_14184 = nil;
    goto v_13847;
    v_14184 = nil;
v_13847:
    if (v_14184 == nil) goto v_13845;
    goto v_13910;
v_13904:
    v_14186 = stack[0];
    goto v_13905;
v_13906:
    v_14184 = stack[-1];
    v_14185 = qcar(v_14184);
    goto v_13907;
v_13908:
    v_14184 = stack[-4];
    goto v_13909;
v_13910:
    goto v_13904;
v_13905:
    goto v_13906;
v_13907:
    goto v_13908;
v_13909:
        return Lapply2(nil, 3, v_14186, v_14185, v_14184);
v_13845:
v_13832:
    v_14184 = stack[-1];
    v_14184 = qcar(v_14184);
    if (!consp(v_14184)) goto v_13922;
    v_14184 = stack[-1];
    v_14184 = qcar(v_14184);
    v_14184 = qcar(v_14184);
    if (symbolp(v_14184)) goto v_13928;
    v_14184 = nil;
    goto v_13926;
v_13928:
    v_14184 = qvalue(elt(env, 2)); // !*nat
    if (v_14184 == nil) goto v_13937;
    else goto v_13938;
v_13937:
    v_14184 = nil;
    goto v_13936;
v_13938:
    v_14184 = stack[-1];
    v_14184 = qcar(v_14184);
    v_14184 = qcar(v_14184);
    if (!symbolp(v_14184)) v_14184 = nil;
    else { v_14184 = qfastgets(v_14184);
           if (v_14184 != nil) { v_14184 = elt(v_14184, 57); // prifn
#ifdef RECORD_GET
             if (v_14184 != SPID_NOPROP)
                record_get(elt(fastget_names, 57), 1);
             else record_get(elt(fastget_names, 57), 0),
                v_14184 = nil; }
           else record_get(elt(fastget_names, 57), 0); }
#else
             if (v_14184 == SPID_NOPROP) v_14184 = nil; }}
#endif
    stack[-4] = v_14184;
    if (v_14184 == nil) goto v_13947;
    else goto v_13946;
v_13947:
    v_14184 = stack[-1];
    v_14184 = qcar(v_14184);
    v_14184 = qcar(v_14184);
    if (!symbolp(v_14184)) v_14184 = nil;
    else { v_14184 = qfastgets(v_14184);
           if (v_14184 != nil) { v_14184 = elt(v_14184, 60); // pprifn
#ifdef RECORD_GET
             if (v_14184 != SPID_NOPROP)
                record_get(elt(fastget_names, 60), 1);
             else record_get(elt(fastget_names, 60), 0),
                v_14184 = nil; }
           else record_get(elt(fastget_names, 60), 0); }
#else
             if (v_14184 == SPID_NOPROP) v_14184 = nil; }}
#endif
    stack[-4] = v_14184;
    if (v_14184 == nil) goto v_13952;
    else goto v_13946;
v_13952:
    v_14184 = nil;
    goto v_13944;
v_13946:
    goto v_13964;
v_13960:
    goto v_13970;
v_13966:
    v_14185 = stack[-4];
    goto v_13967;
v_13968:
    v_14184 = stack[-3];
    goto v_13969;
v_13970:
    goto v_13966;
v_13967:
    goto v_13968;
v_13969:
    v_14185 = get(v_14185, v_14184);
    env = stack[-5];
    goto v_13961;
v_13962:
    v_14184 = elt(env, 14); // inbrackets
    goto v_13963;
v_13964:
    goto v_13960;
v_13961:
    goto v_13962;
v_13963:
    v_14184 = (v_14185 == v_14184 ? lisp_true : nil);
    goto v_13944;
    v_14184 = nil;
v_13944:
    goto v_13936;
    v_14184 = nil;
v_13936:
    goto v_13926;
    v_14184 = nil;
v_13926:
    goto v_13920;
v_13922:
    v_14184 = nil;
    goto v_13920;
    v_14184 = nil;
v_13920:
    if (v_14184 == nil) goto v_13918;
    v_14184 = elt(env, 15); // "("
    fn = elt(env, 22); // prin2!*
    v_14184 = (*qfn1(fn))(fn, v_14184);
    env = stack[-5];
    goto v_13985;
v_13981:
    v_14184 = stack[-1];
    v_14185 = qcar(v_14184);
    goto v_13982;
v_13983:
    v_14184 = stack[-2];
    goto v_13984;
v_13985:
    goto v_13981;
v_13982:
    goto v_13983;
v_13984:
    fn = elt(env, 23); // maprint
    v_14184 = (*qfn2(fn))(fn, v_14185, v_14184);
    env = stack[-5];
    v_14184 = elt(env, 16); // ")"
    fn = elt(env, 22); // prin2!*
    v_14184 = (*qfn1(fn))(fn, v_14184);
    env = stack[-5];
    goto v_13916;
v_13918:
    v_14184 = qvalue(elt(env, 17)); // !*nosplit
    if (v_14184 == nil) goto v_13992;
    v_14184 = qvalue(elt(env, 18)); // testing!-width!*
    if (v_14184 == nil) goto v_13995;
    else goto v_13992;
v_13995:
    goto v_14004;
v_13998:
    v_14184 = stack[-1];
    v_14186 = qcar(v_14184);
    goto v_13999;
v_14000:
    v_14185 = stack[-2];
    goto v_14001;
v_14002:
    v_14184 = nil;
    goto v_14003;
v_14004:
    goto v_13998;
v_13999:
    goto v_14000;
v_14001:
    goto v_14002;
v_14003:
    fn = elt(env, 24); // prinfit
    v_14184 = (*qfnn(fn))(fn, 3, v_14186, v_14185, v_14184);
    env = stack[-5];
    goto v_13916;
v_13992:
    goto v_14016;
v_14012:
    v_14184 = stack[-1];
    v_14185 = qcar(v_14184);
    goto v_14013;
v_14014:
    v_14184 = stack[-2];
    goto v_14015;
v_14016:
    goto v_14012;
v_14013:
    goto v_14014;
v_14015:
    fn = elt(env, 23); // maprint
    v_14184 = (*qfn2(fn))(fn, v_14185, v_14184);
    env = stack[-5];
    goto v_13916;
v_13916:
    v_14184 = stack[-1];
    v_14184 = qcdr(v_14184);
    stack[-1] = v_14184;
    goto v_13826;
v_13828:
v_13826:
    v_14184 = qvalue(elt(env, 17)); // !*nosplit
    if (v_14184 == nil) goto v_14025;
    v_14184 = qvalue(elt(env, 18)); // testing!-width!*
    if (v_14184 == nil) goto v_14028;
    else goto v_14025;
v_14028:
    v_14184 = stack[-1];
    stack[-1] = v_14184;
v_14033:
    v_14184 = stack[-1];
    if (v_14184 == nil) goto v_14037;
    else goto v_14038;
v_14037:
    goto v_14032;
v_14038:
    v_14184 = stack[-1];
    v_14184 = qcar(v_14184);
    stack[0] = v_14184;
    v_14184 = stack[0];
    if (!consp(v_14184)) goto v_14050;
    else goto v_14051;
v_14050:
    v_14184 = lisp_true;
    goto v_14049;
v_14051:
    goto v_14060;
v_14056:
    v_14185 = stack[-3];
    goto v_14057;
v_14058:
    v_14184 = stack[0];
    v_14184 = qcar(v_14184);
    if (!symbolp(v_14184)) v_14184 = nil;
    else { v_14184 = qfastgets(v_14184);
           if (v_14184 != nil) { v_14184 = elt(v_14184, 49); // alt
#ifdef RECORD_GET
             if (v_14184 != SPID_NOPROP)
                record_get(elt(fastget_names, 49), 1);
             else record_get(elt(fastget_names, 49), 0),
                v_14184 = nil; }
           else record_get(elt(fastget_names, 49), 0); }
#else
             if (v_14184 == SPID_NOPROP) v_14184 = nil; }}
#endif
    goto v_14059;
v_14060:
    goto v_14056;
v_14057:
    goto v_14058;
v_14059:
    v_14184 = (v_14185 == v_14184 ? lisp_true : nil);
    v_14184 = (v_14184 == nil ? lisp_true : nil);
    goto v_14049;
    v_14184 = nil;
v_14049:
    if (v_14184 == nil) goto v_14047;
    goto v_14075;
v_14071:
    v_14185 = stack[-3];
    goto v_14072;
v_14073:
    v_14184 = elt(env, 19); // (setq !*comma!*)
    goto v_14074;
v_14075:
    goto v_14071;
v_14072:
    goto v_14073;
v_14074:
    v_14184 = Lmemq(nil, v_14185, v_14184);
    if (v_14184 == nil) goto v_14070;
    v_14184 = stack[-3];
    fn = elt(env, 20); // oprin
    v_14184 = (*qfn1(fn))(fn, v_14184);
    env = stack[-5];
    goto v_14088;
v_14082:
    v_14184 = stack[0];
    fn = elt(env, 25); // negnumberchk
    v_14186 = (*qfn1(fn))(fn, v_14184);
    env = stack[-5];
    goto v_14083;
v_14084:
    v_14185 = stack[-2];
    goto v_14085;
v_14086:
    v_14184 = nil;
    goto v_14087;
v_14088:
    goto v_14082;
v_14083:
    goto v_14084;
v_14085:
    goto v_14086;
v_14087:
    fn = elt(env, 24); // prinfit
    v_14184 = (*qfnn(fn))(fn, 3, v_14186, v_14185, v_14184);
    env = stack[-5];
    goto v_14068;
v_14070:
    goto v_14102;
v_14096:
    v_14184 = stack[0];
    fn = elt(env, 25); // negnumberchk
    v_14186 = (*qfn1(fn))(fn, v_14184);
    env = stack[-5];
    goto v_14097;
v_14098:
    v_14185 = stack[-2];
    goto v_14099;
v_14100:
    v_14184 = stack[-3];
    goto v_14101;
v_14102:
    goto v_14096;
v_14097:
    goto v_14098;
v_14099:
    goto v_14100;
v_14101:
    fn = elt(env, 24); // prinfit
    v_14184 = (*qfnn(fn))(fn, 3, v_14186, v_14185, v_14184);
    env = stack[-5];
    goto v_14068;
v_14068:
    goto v_14045;
v_14047:
    goto v_14116;
v_14110:
    v_14186 = stack[0];
    goto v_14111;
v_14112:
    v_14185 = stack[-2];
    goto v_14113;
v_14114:
    v_14184 = nil;
    goto v_14115;
v_14116:
    goto v_14110;
v_14111:
    goto v_14112;
v_14113:
    goto v_14114;
v_14115:
    fn = elt(env, 24); // prinfit
    v_14184 = (*qfnn(fn))(fn, 3, v_14186, v_14185, v_14184);
    env = stack[-5];
    goto v_14045;
v_14045:
    v_14184 = stack[-1];
    v_14184 = qcdr(v_14184);
    stack[-1] = v_14184;
    goto v_14033;
v_14032:
    goto v_14023;
v_14025:
    v_14184 = stack[-1];
    stack[-1] = v_14184;
v_14127:
    v_14184 = stack[-1];
    if (v_14184 == nil) goto v_14131;
    else goto v_14132;
v_14131:
    goto v_14126;
v_14132:
    v_14184 = stack[-1];
    v_14184 = qcar(v_14184);
    stack[0] = v_14184;
    v_14184 = stack[0];
    if (!consp(v_14184)) goto v_14144;
    else goto v_14145;
v_14144:
    v_14184 = lisp_true;
    goto v_14143;
v_14145:
    goto v_14154;
v_14150:
    v_14185 = stack[-3];
    goto v_14151;
v_14152:
    v_14184 = stack[0];
    v_14184 = qcar(v_14184);
    if (!symbolp(v_14184)) v_14184 = nil;
    else { v_14184 = qfastgets(v_14184);
           if (v_14184 != nil) { v_14184 = elt(v_14184, 49); // alt
#ifdef RECORD_GET
             if (v_14184 != SPID_NOPROP)
                record_get(elt(fastget_names, 49), 1);
             else record_get(elt(fastget_names, 49), 0),
                v_14184 = nil; }
           else record_get(elt(fastget_names, 49), 0); }
#else
             if (v_14184 == SPID_NOPROP) v_14184 = nil; }}
#endif
    goto v_14153;
v_14154:
    goto v_14150;
v_14151:
    goto v_14152;
v_14153:
    v_14184 = (v_14185 == v_14184 ? lisp_true : nil);
    v_14184 = (v_14184 == nil ? lisp_true : nil);
    goto v_14143;
    v_14184 = nil;
v_14143:
    if (v_14184 == nil) goto v_14141;
    v_14184 = stack[-3];
    fn = elt(env, 20); // oprin
    v_14184 = (*qfn1(fn))(fn, v_14184);
    env = stack[-5];
    goto v_14168;
v_14164:
    v_14184 = stack[0];
    fn = elt(env, 25); // negnumberchk
    v_14185 = (*qfn1(fn))(fn, v_14184);
    env = stack[-5];
    goto v_14165;
v_14166:
    v_14184 = stack[-2];
    goto v_14167;
v_14168:
    goto v_14164;
v_14165:
    goto v_14166;
v_14167:
    fn = elt(env, 23); // maprint
    v_14184 = (*qfn2(fn))(fn, v_14185, v_14184);
    env = stack[-5];
    goto v_14139;
v_14141:
    goto v_14179;
v_14175:
    v_14185 = stack[0];
    goto v_14176;
v_14177:
    v_14184 = stack[-2];
    goto v_14178;
v_14179:
    goto v_14175;
v_14176:
    goto v_14177;
v_14178:
    fn = elt(env, 23); // maprint
    v_14184 = (*qfn2(fn))(fn, v_14185, v_14184);
    env = stack[-5];
    goto v_14139;
v_14139:
    v_14184 = stack[-1];
    v_14184 = qcdr(v_14184);
    stack[-1] = v_14184;
    goto v_14127;
v_14126:
    goto v_14023;
v_14023:
    v_14184 = nil;
    return onevalue(v_14184);
}



// Code for row

static LispObject CC_row(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13759;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13743);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_13743;
// end of prologue
    v_13759 = stack[0];
    if (v_13759 == nil) goto v_13750;
    v_13759 = stack[0];
    v_13759 = qcar(v_13759);
    fn = elt(env, 1); // expression
    v_13759 = (*qfn1(fn))(fn, v_13759);
    env = stack[-1];
    v_13759 = stack[0];
    v_13759 = qcdr(v_13759);
    v_13759 = CC_row(elt(env, 0), v_13759);
    goto v_13748;
v_13750:
v_13748:
    v_13759 = nil;
    return onevalue(v_13759);
}



// Code for my_letmtr

static LispObject CC_my_letmtr(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13898, v_13899, v_13900;
    LispObject fn;
    LispObject v_13745, v_13744, v_13743;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "my_letmtr");
    va_start(aa, nargs);
    v_13743 = va_arg(aa, LispObject);
    v_13744 = va_arg(aa, LispObject);
    v_13745 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13745,v_13744,v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13743,v_13744,v_13745);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_13745;
    stack[-4] = v_13744;
    stack[-5] = v_13743;
// end of prologue
    stack[-2] = nil;
    goto v_13759;
v_13755:
    v_13899 = stack[-3];
    goto v_13756;
v_13757:
    v_13898 = elt(env, 1); // mat
    goto v_13758;
v_13759:
    goto v_13755;
v_13756:
    goto v_13757;
v_13758:
    if (!consp(v_13899)) goto v_13752;
    v_13899 = qcar(v_13899);
    if (v_13899 == v_13898) goto v_13753;
v_13752:
    goto v_13769;
v_13763:
    stack[-1] = elt(env, 2); // matrix
    goto v_13764;
v_13765:
    stack[0] = (LispObject)160+TAG_FIXNUM; // 10
    goto v_13766;
v_13767:
    goto v_13779;
v_13773:
    v_13900 = elt(env, 3); // "Matrix"
    goto v_13774;
v_13775:
    v_13898 = stack[-5];
    v_13899 = qcar(v_13898);
    goto v_13776;
v_13777:
    v_13898 = elt(env, 4); // "not set"
    goto v_13778;
v_13779:
    goto v_13773;
v_13774:
    goto v_13775;
v_13776:
    goto v_13777;
v_13778:
    v_13898 = list3(v_13900, v_13899, v_13898);
    env = stack[-7];
    goto v_13768;
v_13769:
    goto v_13763;
v_13764:
    goto v_13765;
v_13766:
    goto v_13767;
v_13768:
    fn = elt(env, 6); // rerror
    v_13898 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_13898);
    env = stack[-7];
    goto v_13751;
v_13753:
    v_13898 = stack[-5];
    v_13898 = qcdr(v_13898);
    stack[-6] = v_13898;
    v_13898 = stack[-6];
    if (v_13898 == nil) goto v_13801;
    else goto v_13802;
v_13801:
    v_13898 = nil;
    goto v_13795;
v_13802:
    v_13898 = stack[-6];
    v_13898 = qcar(v_13898);
    v_13899 = v_13898;
    v_13898 = v_13899;
    v_13898 = integerp(v_13898);
    if (v_13898 == nil) goto v_13812;
    v_13898 = v_13899;
    goto v_13810;
v_13812:
    v_13898 = v_13899;
    fn = elt(env, 7); // reval
    v_13898 = (*qfn1(fn))(fn, v_13898);
    env = stack[-7];
    goto v_13810;
    v_13898 = nil;
v_13810:
    v_13898 = ncons(v_13898);
    env = stack[-7];
    stack[-1] = v_13898;
    stack[-2] = v_13898;
v_13796:
    v_13898 = stack[-6];
    v_13898 = qcdr(v_13898);
    stack[-6] = v_13898;
    v_13898 = stack[-6];
    if (v_13898 == nil) goto v_13824;
    else goto v_13825;
v_13824:
    v_13898 = stack[-2];
    goto v_13795;
v_13825:
    goto v_13833;
v_13829:
    stack[0] = stack[-1];
    goto v_13830;
v_13831:
    v_13898 = stack[-6];
    v_13898 = qcar(v_13898);
    v_13899 = v_13898;
    v_13898 = v_13899;
    v_13898 = integerp(v_13898);
    if (v_13898 == nil) goto v_13842;
    v_13898 = v_13899;
    goto v_13840;
v_13842:
    v_13898 = v_13899;
    fn = elt(env, 7); // reval
    v_13898 = (*qfn1(fn))(fn, v_13898);
    env = stack[-7];
    goto v_13840;
    v_13898 = nil;
v_13840:
    v_13898 = ncons(v_13898);
    env = stack[-7];
    goto v_13832;
v_13833:
    goto v_13829;
v_13830:
    goto v_13831;
v_13832:
    v_13898 = Lrplacd(nil, stack[0], v_13898);
    env = stack[-7];
    v_13898 = stack[-1];
    v_13898 = qcdr(v_13898);
    stack[-1] = v_13898;
    goto v_13796;
v_13795:
    stack[-2] = v_13898;
    fn = elt(env, 8); // numlis
    v_13898 = (*qfn1(fn))(fn, v_13898);
    env = stack[-7];
    if (v_13898 == nil) goto v_13788;
    else goto v_13789;
v_13788:
    v_13898 = lisp_true;
    goto v_13787;
v_13789:
    goto v_13860;
v_13856:
    v_13898 = stack[-2];
    v_13899 = Llength(nil, v_13898);
    env = stack[-7];
    goto v_13857;
v_13858:
    v_13898 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13859;
v_13860:
    goto v_13856;
v_13857:
    goto v_13858;
v_13859:
    v_13898 = Lneq(nil, v_13899, v_13898);
    env = stack[-7];
    goto v_13787;
    v_13898 = nil;
v_13787:
    if (v_13898 == nil) goto v_13785;
    goto v_13869;
v_13865:
    v_13899 = stack[-5];
    goto v_13866;
v_13867:
    v_13898 = elt(env, 5); // hold
    goto v_13868;
v_13869:
    goto v_13865;
v_13866:
    goto v_13867;
v_13868:
    {
        fn = elt(env, 9); // errpri2
        return (*qfn2(fn))(fn, v_13899, v_13898);
    }
v_13785:
v_13751:
    goto v_13877;
v_13873:
    goto v_13883;
v_13879:
    goto v_13889;
v_13885:
    v_13898 = stack[-3];
    v_13899 = qcdr(v_13898);
    goto v_13886;
v_13887:
    v_13898 = stack[-2];
    v_13898 = qcar(v_13898);
    goto v_13888;
v_13889:
    goto v_13885;
v_13886:
    goto v_13887;
v_13888:
    fn = elt(env, 10); // nth
    v_13899 = (*qfn2(fn))(fn, v_13899, v_13898);
    env = stack[-7];
    goto v_13880;
v_13881:
    v_13898 = stack[-2];
    v_13898 = qcdr(v_13898);
    v_13898 = qcar(v_13898);
    goto v_13882;
v_13883:
    goto v_13879;
v_13880:
    goto v_13881;
v_13882:
    fn = elt(env, 11); // pnth
    v_13899 = (*qfn2(fn))(fn, v_13899, v_13898);
    env = stack[-7];
    goto v_13874;
v_13875:
    v_13898 = stack[-4];
    goto v_13876;
v_13877:
    goto v_13873;
v_13874:
    goto v_13875;
v_13876:
    v_13898 = Lrplaca(nil, v_13899, v_13898);
    v_13898 = nil;
    return onevalue(v_13898);
}



// Code for gbfdot

static LispObject CC_gbfdot(LispObject env,
                         LispObject v_13743, LispObject v_13744)
{
    env = qenv(env);
    LispObject v_13772, v_13773;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13744,v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13743,v_13744);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13744;
    stack[-1] = v_13743;
// end of prologue
    goto v_13751;
v_13747:
    goto v_13757;
v_13753:
    v_13772 = stack[-1];
    v_13773 = qcar(v_13772);
    goto v_13754;
v_13755:
    v_13772 = stack[0];
    v_13772 = qcar(v_13772);
    goto v_13756;
v_13757:
    goto v_13753;
v_13754:
    goto v_13755;
v_13756:
    fn = elt(env, 1); // csl_timbf
    stack[-2] = (*qfn2(fn))(fn, v_13773, v_13772);
    env = stack[-3];
    goto v_13748;
v_13749:
    goto v_13767;
v_13763:
    v_13772 = stack[-1];
    v_13773 = qcdr(v_13772);
    goto v_13764;
v_13765:
    v_13772 = stack[0];
    v_13772 = qcdr(v_13772);
    goto v_13766;
v_13767:
    goto v_13763;
v_13764:
    goto v_13765;
v_13766:
    fn = elt(env, 1); // csl_timbf
    v_13772 = (*qfn2(fn))(fn, v_13773, v_13772);
    env = stack[-3];
    goto v_13750;
v_13751:
    goto v_13747;
v_13748:
    goto v_13749;
v_13750:
    {
        LispObject v_13777 = stack[-2];
        fn = elt(env, 2); // plubf
        return (*qfn2(fn))(fn, v_13777, v_13772);
    }
}



// Code for build!-null!-vector

static LispObject CC_buildKnullKvector(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13813, v_13814, v_13815, v_13816, v_13817, v_13818, v_13819, v_13820;
    LispObject v_13745, v_13744, v_13743;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "build-null-vector");
    va_start(aa, nargs);
    v_13743 = va_arg(aa, LispObject);
    v_13744 = va_arg(aa, LispObject);
    v_13745 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13817 = v_13745;
    v_13818 = v_13744;
    v_13819 = v_13743;
// end of prologue
    v_13813 = (LispObject)16+TAG_FIXNUM; // 1
    v_13820 = v_13813;
v_13752:
    goto v_13762;
v_13758:
    v_13813 = v_13819;
    v_13814 = (LispObject)((intptr_t)(v_13813) - 0x10);
    goto v_13759;
v_13760:
    v_13813 = v_13820;
    goto v_13761;
v_13762:
    goto v_13758;
v_13759:
    goto v_13760;
v_13761:
    v_13813 = (LispObject)(intptr_t)((intptr_t)v_13814 - (intptr_t)v_13813 + TAG_FIXNUM);
    v_13813 = ((intptr_t)(v_13813) < 0 ? lisp_true : nil);
    if (v_13813 == nil) goto v_13757;
    goto v_13751;
v_13757:
    goto v_13775;
v_13769:
    v_13816 = v_13818;
    goto v_13770;
v_13771:
    v_13815 = v_13820;
    goto v_13772;
v_13773:
    goto v_13782;
v_13778:
    goto v_13787;
v_13783:
    v_13814 = v_13817;
    goto v_13784;
v_13785:
    v_13813 = v_13820;
    goto v_13786;
v_13787:
    goto v_13783;
v_13784:
    goto v_13785;
v_13786:
    v_13814 = *(LispObject *)((char *)v_13814 + (CELL-TAG_VECTOR) + (((intptr_t)v_13813-TAG_FIXNUM)/(16/CELL)));
    goto v_13779;
v_13780:
    v_13813 = v_13819;
    goto v_13781;
v_13782:
    goto v_13778;
v_13779:
    goto v_13780;
v_13781:
    v_13813 = *(LispObject *)((char *)v_13814 + (CELL-TAG_VECTOR) + (((intptr_t)v_13813-TAG_FIXNUM)/(16/CELL)));
    goto v_13774;
v_13775:
    goto v_13769;
v_13770:
    goto v_13771;
v_13772:
    goto v_13773;
v_13774:
    *(LispObject *)((char *)v_13816 + (CELL-TAG_VECTOR) + (((intptr_t)v_13815-TAG_FIXNUM)/(16/CELL))) = v_13813;
    v_13813 = v_13820;
    v_13813 = (LispObject)((intptr_t)(v_13813) + 0x10);
    v_13820 = v_13813;
    goto v_13752;
v_13751:
    goto v_13801;
v_13795:
    v_13815 = v_13818;
    goto v_13796;
v_13797:
    v_13814 = v_13819;
    goto v_13798;
v_13799:
    v_13813 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13800;
v_13801:
    goto v_13795;
v_13796:
    goto v_13797;
v_13798:
    goto v_13799;
v_13800:
    *(LispObject *)((char *)v_13815 + (CELL-TAG_VECTOR) + (((intptr_t)v_13814-TAG_FIXNUM)/(16/CELL))) = v_13813;
    goto v_13810;
v_13806:
    v_13813 = v_13818;
    goto v_13807;
v_13808:
    v_13814 = v_13819;
    goto v_13809;
v_13810:
    goto v_13806;
v_13807:
    goto v_13808;
v_13809:
    return cons(v_13813, v_13814);
    return onevalue(v_13813);
}



// Code for lex_cleanup

static LispObject CC_lex_cleanup(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13781, v_13782, v_13783, v_13784;
    argcheck(nargs, 0, "lex_cleanup");
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
    v_13781 = qvalue(elt(env, 1)); // lex_keyword_names
    v_13784 = v_13781;
v_13749:
    v_13781 = v_13784;
    if (v_13781 == nil) goto v_13753;
    else goto v_13754;
v_13753:
    goto v_13748;
v_13754:
    v_13781 = v_13784;
    v_13781 = qcar(v_13781);
    v_13783 = v_13781;
    goto v_13765;
v_13761:
    v_13782 = v_13783;
    goto v_13762;
v_13763:
    v_13781 = elt(env, 2); // lex_code
    goto v_13764;
v_13765:
    goto v_13761;
v_13762:
    goto v_13763;
v_13764:
    v_13781 = Lremprop(nil, v_13782, v_13781);
    env = stack[0];
    goto v_13773;
v_13769:
    v_13782 = v_13783;
    goto v_13770;
v_13771:
    v_13781 = elt(env, 3); // lex_dipthong
    goto v_13772;
v_13773:
    goto v_13769;
v_13770:
    goto v_13771;
v_13772:
    v_13781 = Lremprop(nil, v_13782, v_13781);
    env = stack[0];
    v_13781 = v_13784;
    v_13781 = qcdr(v_13781);
    v_13784 = v_13781;
    goto v_13749;
v_13748:
    v_13781 = nil;
    qvalue(elt(env, 1)) = v_13781; // lex_keyword_names
    v_13781 = qvalue(elt(env, 4)); // lex_initial_next_code
    qvalue(elt(env, 5)) = v_13781; // lex_next_code
    v_13781 = qvalue(elt(env, 6)); // initial_codename
    qvalue(elt(env, 7)) = v_13781; // lex_codename
    v_13781 = nil;
    return onevalue(v_13781);
}



// Code for tripleisprolongedby

static LispObject CC_tripleisprolongedby(LispObject env,
                         LispObject v_13743, LispObject v_13744)
{
    env = qenv(env);
    LispObject v_13803, v_13804;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13744,v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13743,v_13744);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13744;
    v_13803 = v_13743;
// end of prologue
    goto v_13753;
v_13749:
    v_13804 = v_13803;
    goto v_13750;
v_13751:
    v_13803 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_13752;
v_13753:
    goto v_13749;
v_13750:
    goto v_13751;
v_13752:
    v_13803 = *(LispObject *)((char *)v_13804 + (CELL-TAG_VECTOR) + (((intptr_t)v_13803-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_13803;
v_13759:
    v_13803 = stack[-1];
    v_13803 = qcar(v_13803);
    if (v_13803 == nil) goto v_13762;
    goto v_13773;
v_13769:
    v_13803 = stack[-1];
    v_13804 = qcar(v_13803);
    goto v_13770;
v_13771:
    v_13803 = stack[0];
    goto v_13772;
v_13773:
    goto v_13769;
v_13770:
    goto v_13771;
v_13772:
    v_13803 = (LispObject)greaterp2(v_13804, v_13803);
    v_13803 = v_13803 ? lisp_true : nil;
    env = stack[-2];
    if (v_13803 == nil) goto v_13762;
    goto v_13763;
v_13762:
    goto v_13758;
v_13763:
    v_13803 = stack[-1];
    v_13803 = qcdr(v_13803);
    stack[-1] = v_13803;
    goto v_13759;
v_13758:
    v_13803 = stack[-1];
    v_13803 = qcar(v_13803);
    if (v_13803 == nil) goto v_13784;
    goto v_13793;
v_13789:
    v_13803 = stack[-1];
    v_13804 = qcar(v_13803);
    goto v_13790;
v_13791:
    v_13803 = stack[0];
    goto v_13792;
v_13793:
    goto v_13789;
v_13790:
    goto v_13791;
v_13792:
    if (equal(v_13804, v_13803)) goto v_13788;
    else goto v_13784;
v_13788:
    v_13803 = lisp_true;
    goto v_13748;
v_13784:
    v_13803 = nil;
    goto v_13748;
    v_13803 = nil;
v_13748:
    return onevalue(v_13803);
}



// Code for ofsf_smupdknowl

static LispObject CC_ofsf_smupdknowl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13846, v_13847, v_13848;
    LispObject fn;
    LispObject v_13746, v_13745, v_13744, v_13743;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ofsf_smupdknowl");
    va_start(aa, nargs);
    v_13743 = va_arg(aa, LispObject);
    v_13744 = va_arg(aa, LispObject);
    v_13745 = va_arg(aa, LispObject);
    v_13746 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_13746,v_13745,v_13744,v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_13743,v_13744,v_13745,v_13746);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_13746;
    stack[-2] = v_13745;
    stack[-3] = v_13744;
    stack[-4] = v_13743;
// end of prologue
v_13755:
    v_13846 = stack[-3];
    if (v_13846 == nil) goto v_13758;
    else goto v_13759;
v_13758:
    goto v_13754;
v_13759:
    goto v_13770;
v_13766:
    v_13847 = stack[-4];
    goto v_13767;
v_13768:
    v_13846 = elt(env, 1); // and
    goto v_13769;
v_13770:
    goto v_13766;
v_13767:
    goto v_13768;
v_13769:
    if (v_13847 == v_13846) goto v_13764;
    else goto v_13765;
v_13764:
    v_13846 = stack[-3];
    v_13846 = qcar(v_13846);
    goto v_13763;
v_13765:
    v_13846 = stack[-3];
    v_13846 = qcar(v_13846);
    fn = elt(env, 3); // ofsf_negateat
    v_13846 = (*qfn1(fn))(fn, v_13846);
    env = stack[-6];
    goto v_13763;
    v_13846 = nil;
v_13763:
    v_13847 = v_13846;
    v_13846 = stack[-3];
    v_13846 = qcdr(v_13846);
    stack[-3] = v_13846;
    goto v_13787;
v_13783:
    goto v_13784;
v_13785:
    v_13846 = stack[-1];
    goto v_13786;
v_13787:
    goto v_13783;
v_13784:
    goto v_13785;
v_13786:
    fn = elt(env, 4); // ofsf_at2ir
    v_13846 = (*qfn2(fn))(fn, v_13847, v_13846);
    env = stack[-6];
    v_13848 = v_13846;
    goto v_13798;
v_13794:
    v_13846 = v_13848;
    v_13847 = qcar(v_13846);
    goto v_13795;
v_13796:
    v_13846 = stack[-2];
    goto v_13797;
v_13798:
    goto v_13794;
v_13795:
    goto v_13796;
v_13797:
    v_13846 = Lassoc(nil, v_13847, v_13846);
    stack[-5] = v_13846;
    if (v_13846 == nil) goto v_13793;
    goto v_13808;
v_13804:
    stack[0] = stack[-5];
    goto v_13805;
v_13806:
    goto v_13815;
v_13811:
    v_13846 = v_13848;
    v_13846 = qcdr(v_13846);
    v_13847 = qcar(v_13846);
    goto v_13812;
v_13813:
    v_13846 = stack[-5];
    v_13846 = qcdr(v_13846);
    goto v_13814;
v_13815:
    goto v_13811;
v_13812:
    goto v_13813;
v_13814:
    fn = elt(env, 5); // ofsf_sminsert
    v_13846 = (*qfn2(fn))(fn, v_13847, v_13846);
    env = stack[-6];
    goto v_13807;
v_13808:
    goto v_13804;
v_13805:
    goto v_13806;
v_13807:
    fn = elt(env, 6); // setcdr
    v_13846 = (*qfn2(fn))(fn, stack[0], v_13846);
    env = stack[-6];
    goto v_13829;
v_13825:
    v_13846 = stack[-5];
    v_13847 = qcdr(v_13846);
    goto v_13826;
v_13827:
    v_13846 = elt(env, 2); // false
    goto v_13828;
v_13829:
    goto v_13825;
v_13826:
    goto v_13827;
v_13828:
    if (v_13847 == v_13846) goto v_13823;
    else goto v_13824;
v_13823:
    v_13846 = nil;
    stack[-3] = v_13846;
    v_13846 = elt(env, 2); // false
    stack[-2] = v_13846;
    goto v_13822;
v_13824:
v_13822:
    goto v_13791;
v_13793:
    goto v_13842;
v_13838:
    v_13847 = v_13848;
    goto v_13839;
v_13840:
    v_13846 = stack[-2];
    goto v_13841;
v_13842:
    goto v_13838;
v_13839:
    goto v_13840;
v_13841:
    v_13846 = cons(v_13847, v_13846);
    env = stack[-6];
    stack[-2] = v_13846;
    goto v_13791;
v_13791:
    goto v_13755;
v_13754:
    v_13846 = stack[-2];
    return onevalue(v_13846);
}



// Code for rl_subalchk

static LispObject CC_rl_subalchk(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13754;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13743);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_13754 = v_13743;
// end of prologue
    goto v_13750;
v_13746:
    stack[0] = qvalue(elt(env, 1)); // rl_subalchk!*
    goto v_13747;
v_13748:
    v_13754 = ncons(v_13754);
    env = stack[-1];
    goto v_13749;
v_13750:
    goto v_13746;
v_13747:
    goto v_13748;
v_13749:
    {
        LispObject v_13756 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_13756, v_13754);
    }
}



// Code for pasf_smwcpknowl

static LispObject CC_pasf_smwcpknowl(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13756, v_13757;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13757 = v_13743;
// end of prologue
    v_13756 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_13756 == nil) goto v_13748;
    v_13756 = v_13757;
    {
        fn = elt(env, 2); // cl_susicpknowl
        return (*qfn1(fn))(fn, v_13756);
    }
v_13748:
    v_13756 = v_13757;
    {
        fn = elt(env, 3); // cl_smcpknowl
        return (*qfn1(fn))(fn, v_13756);
    }
    v_13756 = nil;
    return onevalue(v_13756);
}



// Code for bvarml

static LispObject CC_bvarml(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13777, v_13778;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13743);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_13743;
// end of prologue
    v_13777 = elt(env, 1); // "<bvar>"
    fn = elt(env, 3); // printout
    v_13777 = (*qfn1(fn))(fn, v_13777);
    env = stack[-1];
    v_13777 = lisp_true;
    fn = elt(env, 4); // indent!*
    v_13777 = (*qfn1(fn))(fn, v_13777);
    env = stack[-1];
    v_13777 = stack[0];
    v_13777 = qcar(v_13777);
    fn = elt(env, 5); // expression
    v_13777 = (*qfn1(fn))(fn, v_13777);
    env = stack[-1];
    goto v_13762;
v_13758:
    v_13777 = stack[0];
    v_13777 = qcdr(v_13777);
    v_13778 = qcar(v_13777);
    goto v_13759;
v_13760:
    v_13777 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13761;
v_13762:
    goto v_13758;
v_13759:
    goto v_13760;
v_13761:
    if (v_13778 == v_13777) goto v_13757;
    v_13777 = stack[0];
    v_13777 = qcdr(v_13777);
    v_13777 = qcar(v_13777);
    v_13777 = ncons(v_13777);
    env = stack[-1];
    fn = elt(env, 6); // degreeml
    v_13777 = (*qfn1(fn))(fn, v_13777);
    env = stack[-1];
    goto v_13755;
v_13757:
v_13755:
    v_13777 = nil;
    fn = elt(env, 4); // indent!*
    v_13777 = (*qfn1(fn))(fn, v_13777);
    env = stack[-1];
    v_13777 = elt(env, 2); // "</bvar>"
    fn = elt(env, 3); // printout
    v_13777 = (*qfn1(fn))(fn, v_13777);
    v_13777 = nil;
    return onevalue(v_13777);
}



// Code for ps!:get!-term

static LispObject CC_psTgetKterm(LispObject env,
                         LispObject v_13743, LispObject v_13744)
{
    env = qenv(env);
    LispObject v_13871, v_13872, v_13873;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13744,v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13743,v_13744);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_13744;
    stack[-2] = v_13743;
// end of prologue
    v_13871 = stack[-2];
    fn = elt(env, 2); // ps!:order
    stack[0] = (*qfn1(fn))(fn, v_13871);
    env = stack[-4];
    v_13871 = stack[-2];
    fn = elt(env, 3); // ps!:last!-term
    v_13871 = (*qfn1(fn))(fn, v_13871);
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v_13871;
    goto v_13761;
v_13757:
    v_13872 = stack[-1];
    goto v_13758;
v_13759:
    v_13871 = stack[-3];
    goto v_13760;
v_13761:
    goto v_13757;
v_13758:
    goto v_13759;
v_13760:
    v_13871 = (LispObject)lessp2(v_13872, v_13871);
    v_13871 = v_13871 ? lisp_true : nil;
    env = stack[-4];
    if (v_13871 == nil) goto v_13755;
    goto v_13769;
v_13765:
    v_13872 = nil;
    goto v_13766;
v_13767:
    v_13871 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13768;
v_13769:
    goto v_13765;
v_13766:
    goto v_13767;
v_13768:
    return cons(v_13872, v_13871);
v_13755:
    goto v_13779;
v_13775:
    v_13872 = stack[-1];
    goto v_13776;
v_13777:
    v_13871 = stack[0];
    goto v_13778;
v_13779:
    goto v_13775;
v_13776:
    goto v_13777;
v_13778:
    v_13871 = (LispObject)greaterp2(v_13872, v_13871);
    v_13871 = v_13871 ? lisp_true : nil;
    env = stack[-4];
    if (v_13871 == nil) goto v_13773;
    v_13871 = nil;
    goto v_13753;
v_13773:
    goto v_13792;
v_13788:
    goto v_13798;
v_13794:
    v_13872 = stack[-1];
    goto v_13795;
v_13796:
    v_13871 = stack[-3];
    goto v_13797;
v_13798:
    goto v_13794;
v_13795:
    goto v_13796;
v_13797:
    stack[0] = difference2(v_13872, v_13871);
    env = stack[-4];
    goto v_13789;
v_13790:
    v_13871 = stack[-2];
    if (!consp(v_13871)) goto v_13807;
    else goto v_13808;
v_13807:
    v_13871 = lisp_true;
    goto v_13806;
v_13808:
    goto v_13821;
v_13817:
    v_13871 = stack[-2];
    v_13872 = qcar(v_13871);
    goto v_13818;
v_13819:
    v_13871 = elt(env, 1); // !:ps!:
    goto v_13820;
v_13821:
    goto v_13817;
v_13818:
    goto v_13819;
v_13820:
    if (v_13872 == v_13871) goto v_13816;
    v_13871 = stack[-2];
    v_13871 = qcar(v_13871);
    if (!symbolp(v_13871)) v_13871 = nil;
    else { v_13871 = qfastgets(v_13871);
           if (v_13871 != nil) { v_13871 = elt(v_13871, 8); // dname
#ifdef RECORD_GET
             if (v_13871 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_13871 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_13871 == SPID_NOPROP) v_13871 = nil; }}
#endif
    goto v_13814;
v_13816:
    v_13871 = nil;
    goto v_13814;
    v_13871 = nil;
v_13814:
    goto v_13806;
    v_13871 = nil;
v_13806:
    if (v_13871 == nil) goto v_13804;
    goto v_13839;
v_13833:
    v_13873 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13834;
v_13835:
    v_13872 = stack[-2];
    goto v_13836;
v_13837:
    v_13871 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13838;
v_13839:
    goto v_13833;
v_13834:
    goto v_13835;
v_13836:
    goto v_13837;
v_13838:
    v_13871 = list2star(v_13873, v_13872, v_13871);
    env = stack[-4];
    v_13871 = ncons(v_13871);
    goto v_13802;
v_13804:
    goto v_13850;
v_13846:
    v_13872 = stack[-2];
    goto v_13847;
v_13848:
    v_13871 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_13849;
v_13850:
    goto v_13846;
v_13847:
    goto v_13848;
v_13849:
    fn = elt(env, 4); // ps!:getv
    v_13871 = (*qfn2(fn))(fn, v_13872, v_13871);
    goto v_13802;
    v_13871 = nil;
v_13802:
    goto v_13791;
v_13792:
    goto v_13788;
v_13789:
    goto v_13790;
v_13791:
    v_13871 = Lassoc(nil, stack[0], v_13871);
    v_13872 = v_13871;
    v_13871 = v_13872;
    if (v_13871 == nil) goto v_13857;
    v_13871 = v_13872;
    v_13871 = qcdr(v_13871);
    goto v_13855;
v_13857:
    goto v_13868;
v_13864:
    v_13872 = nil;
    goto v_13865;
v_13866:
    v_13871 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13867;
v_13868:
    goto v_13864;
v_13865:
    goto v_13866;
v_13867:
    return cons(v_13872, v_13871);
    v_13871 = nil;
v_13855:
    goto v_13753;
    v_13871 = nil;
v_13753:
    return onevalue(v_13871);
}



// Code for rd!:zerop!:

static LispObject CC_rdTzeropT(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13759, v_13760;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13743);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_13760 = v_13743;
// end of prologue
    v_13759 = v_13760;
    v_13759 = qcdr(v_13759);
    if (!consp(v_13759)) goto v_13747;
    else goto v_13748;
v_13747:
    v_13759 = v_13760;
    v_13759 = qcdr(v_13759);
    {
        fn = elt(env, 1); // ft!:zerop
        return (*qfn1(fn))(fn, v_13759);
    }
v_13748:
    v_13759 = v_13760;
    fn = elt(env, 2); // round!*
    v_13759 = (*qfn1(fn))(fn, v_13759);
    env = stack[0];
    {
        fn = elt(env, 3); // bfzerop!:
        return (*qfn1(fn))(fn, v_13759);
    }
    v_13759 = nil;
    return onevalue(v_13759);
}



// Code for mktails1

static LispObject CC_mktails1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13881, v_13882, v_13883;
    LispObject fn;
    LispObject v_13745, v_13744, v_13743;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mktails1");
    va_start(aa, nargs);
    v_13743 = va_arg(aa, LispObject);
    v_13744 = va_arg(aa, LispObject);
    v_13745 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13745,v_13744,v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13743,v_13744,v_13745);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13745;
    v_13881 = v_13744;
    stack[-1] = v_13743;
// end of prologue
    goto v_13757;
v_13753:
    v_13882 = stack[-1];
    goto v_13754;
v_13755:
    goto v_13756;
v_13757:
    goto v_13753;
v_13754:
    goto v_13755;
v_13756:
    fn = elt(env, 2); // getroad
    v_13881 = (*qfn2(fn))(fn, v_13882, v_13881);
    env = stack[-3];
    v_13882 = v_13881;
    goto v_13768;
v_13764:
    v_13883 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13765;
v_13766:
    v_13881 = v_13882;
    goto v_13767;
v_13768:
    goto v_13764;
v_13765:
    goto v_13766;
v_13767:
    if (v_13883 == v_13881) goto v_13762;
    else goto v_13763;
v_13762:
    goto v_13776;
v_13772:
    v_13882 = nil;
    goto v_13773;
v_13774:
    v_13881 = stack[0];
    goto v_13775;
v_13776:
    goto v_13772;
v_13773:
    goto v_13774;
v_13775:
    return cons(v_13882, v_13881);
v_13763:
    goto v_13787;
v_13783:
    v_13883 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13784;
v_13785:
    v_13881 = stack[-1];
    v_13881 = qcdr(v_13881);
    goto v_13786;
v_13787:
    goto v_13783;
v_13784:
    goto v_13785;
v_13786:
    if (v_13883 == v_13881) goto v_13781;
    else goto v_13782;
v_13781:
    goto v_13796;
v_13792:
    goto v_13806;
v_13802:
    v_13881 = stack[-1];
    v_13882 = qcar(v_13881);
    goto v_13803;
v_13804:
    v_13881 = elt(env, 1); // replace_by_vector
    goto v_13805;
v_13806:
    goto v_13802;
v_13803:
    goto v_13804;
v_13805:
    v_13881 = get(v_13882, v_13881);
    env = stack[-3];
    if (v_13881 == nil) goto v_13800;
    else goto v_13799;
v_13800:
    v_13881 = stack[-1];
    v_13881 = qcar(v_13881);
v_13799:
    v_13882 = ncons(v_13881);
    goto v_13793;
v_13794:
    v_13881 = stack[0];
    goto v_13795;
v_13796:
    goto v_13792;
v_13793:
    goto v_13794;
v_13795:
    return cons(v_13882, v_13881);
v_13782:
    goto v_13817;
v_13813:
    v_13883 = stack[-1];
    goto v_13814;
v_13815:
    v_13881 = stack[0];
    goto v_13816;
v_13817:
    goto v_13813;
v_13814:
    goto v_13815;
v_13816:
    v_13881 = Lassoc(nil, v_13883, v_13881);
    v_13883 = v_13881;
    v_13881 = v_13883;
    if (v_13881 == nil) goto v_13824;
    v_13881 = v_13883;
    v_13881 = qcdr(v_13881);
    v_13881 = qcdr(v_13881);
    if (v_13881 == nil) goto v_13828;
    else goto v_13829;
v_13828:
    goto v_13838;
v_13834:
    v_13881 = v_13883;
    v_13882 = qcdr(v_13881);
    goto v_13835;
v_13836:
    v_13881 = stack[0];
    goto v_13837;
v_13838:
    goto v_13834;
v_13835:
    goto v_13836;
v_13837:
    return cons(v_13882, v_13881);
v_13829:
    goto v_13849;
v_13845:
    v_13881 = v_13883;
    v_13881 = qcdr(v_13881);
    v_13882 = Lreverse(nil, v_13881);
    goto v_13846;
v_13847:
    v_13881 = stack[0];
    goto v_13848;
v_13849:
    goto v_13845;
v_13846:
    goto v_13847;
v_13848:
    return cons(v_13882, v_13881);
    v_13881 = nil;
    goto v_13751;
v_13824:
    v_13881 = stack[-1];
    goto v_13860;
v_13856:
    goto v_13857;
v_13858:
    goto v_13859;
v_13860:
    goto v_13856;
v_13857:
    goto v_13858;
v_13859:
    fn = elt(env, 3); // mkinds
    v_13881 = (*qfn2(fn))(fn, v_13881, v_13882);
    env = stack[-3];
    v_13883 = v_13881;
    goto v_13870;
v_13864:
    stack[-2] = v_13883;
    goto v_13865;
v_13866:
    goto v_13877;
v_13873:
    v_13881 = stack[-1];
    goto v_13874;
v_13875:
    v_13882 = v_13883;
    goto v_13876;
v_13877:
    goto v_13873;
v_13874:
    goto v_13875;
v_13876:
    v_13882 = cons(v_13881, v_13882);
    goto v_13867;
v_13868:
    v_13881 = stack[0];
    goto v_13869;
v_13870:
    goto v_13864;
v_13865:
    goto v_13866;
v_13867:
    goto v_13868;
v_13869:
    {
        LispObject v_13887 = stack[-2];
        return list2star(v_13887, v_13882, v_13881);
    }
v_13751:
    return onevalue(v_13881);
}



// Code for splitcomplex

static LispObject CC_splitcomplex(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13798, v_13799;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13743);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_13743;
// end of prologue
    v_13799 = qvalue(elt(env, 1)); // kord!*
    v_13798 = lisp_true;
// Binding kord!*
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = v_13799; // kord!*
// Binding !*exp
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=2
{   bind_fluid_stack bind_fluid_var(-4, 2, -2);
    qvalue(elt(env, 2)) = v_13798; // !*exp
    v_13798 = elt(env, 3); // i
    if (!symbolp(v_13798)) v_13798 = nil;
    else { v_13798 = qfastgets(v_13798);
           if (v_13798 != nil) { v_13798 = elt(v_13798, 56); // idvalfn
#ifdef RECORD_GET
             if (v_13798 != SPID_NOPROP)
                record_get(elt(fastget_names, 56), 1);
             else record_get(elt(fastget_names, 56), 0),
                v_13798 = nil; }
           else record_get(elt(fastget_names, 56), 0); }
#else
             if (v_13798 == SPID_NOPROP) v_13798 = nil; }}
#endif
    if (v_13798 == nil) goto v_13755;
    v_13798 = stack[0];
    fn = elt(env, 4); // expand!-imrepart
    v_13798 = (*qfn1(fn))(fn, v_13798);
    env = stack[-4];
    goto v_13753;
v_13755:
    goto v_13771;
v_13767:
    v_13799 = elt(env, 3); // i
    goto v_13768;
v_13769:
    v_13798 = stack[0];
    goto v_13770;
v_13771:
    goto v_13767;
v_13768:
    goto v_13769;
v_13770:
    v_13798 = Lsmemq(nil, v_13799, v_13798);
    env = stack[-4];
    if (v_13798 == nil) goto v_13765;
    goto v_13780;
v_13776:
    v_13799 = elt(env, 3); // i
    goto v_13777;
v_13778:
    v_13798 = qvalue(elt(env, 1)); // kord!*
    goto v_13779;
v_13780:
    goto v_13776;
v_13777:
    goto v_13778;
v_13779:
    v_13798 = cons(v_13799, v_13798);
    env = stack[-4];
    fn = elt(env, 5); // setkorder
    v_13798 = (*qfn1(fn))(fn, v_13798);
    env = stack[-4];
    v_13798 = stack[0];
    fn = elt(env, 6); // reorder
    v_13798 = (*qfn1(fn))(fn, v_13798);
    env = stack[-4];
    stack[0] = v_13798;
    goto v_13763;
v_13765:
v_13763:
    v_13798 = stack[0];
    fn = elt(env, 4); // expand!-imrepart
    v_13798 = (*qfn1(fn))(fn, v_13798);
    env = stack[-4];
    fn = elt(env, 7); // subs2
    v_13798 = (*qfn1(fn))(fn, v_13798);
    env = stack[-4];
    goto v_13753;
    v_13798 = nil;
v_13753:
    stack[-1] = v_13798;
    goto v_13793;
v_13789:
    v_13798 = stack[-1];
    fn = elt(env, 8); // take!-realpart
    stack[0] = (*qfn1(fn))(fn, v_13798);
    env = stack[-4];
    goto v_13790;
v_13791:
    v_13798 = stack[-1];
    fn = elt(env, 9); // take!-impart
    v_13798 = (*qfn1(fn))(fn, v_13798);
    env = stack[-4];
    goto v_13792;
v_13793:
    goto v_13789;
v_13790:
    goto v_13791;
v_13792:
    v_13798 = cons(stack[0], v_13798);
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_13798);
}



// Code for red_totalred

static LispObject CC_red_totalred(LispObject env,
                         LispObject v_13743, LispObject v_13744)
{
    env = qenv(env);
    LispObject v_13761, v_13762;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13744,v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13743,v_13744);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_13761 = v_13744;
    v_13762 = v_13743;
// end of prologue
    goto v_13751;
v_13747:
    stack[0] = v_13762;
    goto v_13748;
v_13749:
    goto v_13758;
v_13754:
    goto v_13755;
v_13756:
    goto v_13757;
v_13758:
    goto v_13754;
v_13755:
    goto v_13756;
v_13757:
    fn = elt(env, 1); // red_topred
    v_13761 = (*qfn2(fn))(fn, v_13762, v_13761);
    env = stack[-1];
    goto v_13750;
v_13751:
    goto v_13747;
v_13748:
    goto v_13749;
v_13750:
    {
        LispObject v_13764 = stack[0];
        fn = elt(env, 2); // red_tailred
        return (*qfn2(fn))(fn, v_13764, v_13761);
    }
}



// Code for gcdout

static LispObject CC_gcdout(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13829, v_13830, v_13831;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13743);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13743;
// end of prologue
    v_13829 = qvalue(elt(env, 1)); // !*modular
    if (v_13829 == nil) goto v_13748;
    v_13829 = stack[0];
    goto v_13746;
v_13748:
    v_13829 = stack[0];
    if (v_13829 == nil) goto v_13751;
    else goto v_13752;
v_13751:
    v_13829 = nil;
    goto v_13746;
v_13752:
    goto v_13761;
v_13757:
    v_13829 = stack[0];
    fn = elt(env, 2); // ljet
    v_13829 = (*qfn1(fn))(fn, v_13829);
    env = stack[-2];
    fn = elt(env, 3); // ord
    v_13830 = (*qfn1(fn))(fn, v_13829);
    env = stack[-2];
    goto v_13758;
v_13759:
    v_13829 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13760;
v_13761:
    goto v_13757;
v_13758:
    goto v_13759;
v_13760:
    if (v_13830 == v_13829) goto v_13755;
    else goto v_13756;
v_13755:
    v_13829 = stack[0];
    goto v_13746;
v_13756:
    v_13829 = stack[0];
    stack[-1] = v_13829;
    v_13829 = stack[-1];
    v_13829 = qcar(v_13829);
    v_13829 = qcdr(v_13829);
    v_13831 = v_13829;
v_13779:
    v_13829 = stack[-1];
    if (v_13829 == nil) goto v_13782;
    goto v_13791;
v_13787:
    v_13830 = v_13831;
    goto v_13788;
v_13789:
    v_13829 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13790;
v_13791:
    goto v_13787;
v_13788:
    goto v_13789;
v_13790:
    if (v_13830 == v_13829) goto v_13782;
    goto v_13783;
v_13782:
    goto v_13778;
v_13783:
    goto v_13800;
v_13796:
    v_13830 = v_13831;
    goto v_13797;
v_13798:
    v_13829 = stack[-1];
    v_13829 = qcar(v_13829);
    v_13829 = qcdr(v_13829);
    goto v_13799;
v_13800:
    goto v_13796;
v_13797:
    goto v_13798;
v_13799:
    fn = elt(env, 4); // gcdf!*
    v_13829 = (*qfn2(fn))(fn, v_13830, v_13829);
    env = stack[-2];
    v_13831 = v_13829;
    v_13829 = stack[-1];
    v_13829 = qcdr(v_13829);
    stack[-1] = v_13829;
    goto v_13779;
v_13778:
    goto v_13815;
v_13811:
    v_13830 = v_13831;
    goto v_13812;
v_13813:
    v_13829 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13814;
v_13815:
    goto v_13811;
v_13812:
    goto v_13813;
v_13814:
    if (v_13830 == v_13829) goto v_13809;
    else goto v_13810;
v_13809:
    v_13829 = stack[0];
    goto v_13808;
v_13810:
    goto v_13826;
v_13822:
    v_13829 = stack[0];
    goto v_13823;
v_13824:
    v_13830 = v_13831;
    goto v_13825;
v_13826:
    goto v_13822;
v_13823:
    goto v_13824;
v_13825:
    {
        fn = elt(env, 5); // pcdiv
        return (*qfn2(fn))(fn, v_13829, v_13830);
    }
    v_13829 = nil;
v_13808:
    goto v_13746;
    v_13829 = nil;
v_13746:
    return onevalue(v_13829);
}



// Code for ilog2

static LispObject CC_ilog2(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13870, v_13871;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13743);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_13743;
// end of prologue
    goto v_13759;
v_13755:
    v_13871 = stack[-2];
    goto v_13756;
v_13757:
    v_13870 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13758;
v_13759:
    goto v_13755;
v_13756:
    goto v_13757;
v_13758:
    v_13870 = (LispObject)lesseq2(v_13871, v_13870);
    v_13870 = v_13870 ? lisp_true : nil;
    env = stack[-4];
    if (v_13870 == nil) goto v_13753;
    goto v_13767;
v_13763:
    v_13871 = stack[-2];
    goto v_13764;
v_13765:
    v_13870 = elt(env, 0); // ilog2
    goto v_13766;
v_13767:
    goto v_13763;
v_13764:
    goto v_13765;
v_13766:
    fn = elt(env, 1); // terrlst
    v_13870 = (*qfn2(fn))(fn, v_13871, v_13870);
    env = stack[-4];
    goto v_13751;
v_13753:
v_13751:
    v_13870 = (LispObject)32+TAG_FIXNUM; // 2
    stack[0] = v_13870;
    v_13870 = stack[0];
    v_13870 = ncons(v_13870);
    env = stack[-4];
    stack[-1] = v_13870;
v_13775:
    goto v_13785;
v_13781:
    v_13871 = stack[-2];
    goto v_13782;
v_13783:
    v_13870 = stack[0];
    goto v_13784;
v_13785:
    goto v_13781;
v_13782:
    goto v_13783;
v_13784:
    v_13870 = (LispObject)greaterp2(v_13871, v_13870);
    v_13870 = v_13870 ? lisp_true : nil;
    env = stack[-4];
    if (v_13870 == nil) goto v_13778;
    else goto v_13779;
v_13778:
    goto v_13774;
v_13779:
    goto v_13794;
v_13790:
    v_13871 = stack[0];
    goto v_13791;
v_13792:
    v_13870 = stack[-1];
    goto v_13793;
v_13794:
    goto v_13790;
v_13791:
    goto v_13792;
v_13793:
    v_13870 = cons(v_13871, v_13870);
    env = stack[-4];
    stack[-1] = v_13870;
    goto v_13802;
v_13798:
    v_13871 = stack[0];
    goto v_13799;
v_13800:
    v_13870 = stack[0];
    goto v_13801;
v_13802:
    goto v_13798;
v_13799:
    goto v_13800;
v_13801:
    v_13870 = times2(v_13871, v_13870);
    env = stack[-4];
    stack[0] = v_13870;
    goto v_13775;
v_13774:
    v_13870 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_13870;
v_13808:
    goto v_13817;
v_13813:
    v_13870 = stack[-1];
    v_13871 = qcar(v_13870);
    stack[0] = v_13871;
    goto v_13814;
v_13815:
    v_13870 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13816;
v_13817:
    goto v_13813;
v_13814:
    goto v_13815;
v_13816:
    if (v_13871 == v_13870) goto v_13811;
    else goto v_13812;
v_13811:
    goto v_13807;
v_13812:
    v_13870 = stack[-1];
    v_13870 = qcdr(v_13870);
    stack[-1] = v_13870;
    goto v_13833;
v_13829:
    v_13871 = stack[-2];
    goto v_13830;
v_13831:
    v_13870 = stack[0];
    goto v_13832;
v_13833:
    goto v_13829;
v_13830:
    goto v_13831;
v_13832:
    v_13870 = (LispObject)geq2(v_13871, v_13870);
    v_13870 = v_13870 ? lisp_true : nil;
    env = stack[-4];
    if (v_13870 == nil) goto v_13827;
    goto v_13841;
v_13837:
    v_13871 = stack[-2];
    goto v_13838;
v_13839:
    v_13870 = stack[0];
    goto v_13840;
v_13841:
    goto v_13837;
v_13838:
    goto v_13839;
v_13840:
    v_13870 = quot2(v_13871, v_13870);
    env = stack[-4];
    stack[-2] = v_13870;
    v_13870 = stack[-3];
    v_13870 = add1(v_13870);
    env = stack[-4];
    stack[-3] = v_13870;
    goto v_13825;
v_13827:
v_13825:
    goto v_13852;
v_13848:
    v_13871 = stack[-3];
    goto v_13849;
v_13850:
    v_13870 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13851;
v_13852:
    goto v_13848;
v_13849:
    goto v_13850;
v_13851:
    v_13870 = times2(v_13871, v_13870);
    env = stack[-4];
    stack[-3] = v_13870;
    goto v_13808;
v_13807:
    goto v_13864;
v_13860:
    v_13871 = stack[-2];
    goto v_13861;
v_13862:
    v_13870 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13863;
v_13864:
    goto v_13860;
v_13861:
    goto v_13862;
v_13863:
    v_13870 = (LispObject)geq2(v_13871, v_13870);
    v_13870 = v_13870 ? lisp_true : nil;
    env = stack[-4];
    if (v_13870 == nil) goto v_13858;
    v_13870 = stack[-3];
    v_13870 = add1(v_13870);
    stack[-3] = v_13870;
    goto v_13856;
v_13858:
v_13856:
    v_13870 = stack[-3];
    return onevalue(v_13870);
}



// Code for let2

static LispObject CC_let2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_14045, v_14046, v_14047, v_14048, v_14049;
    LispObject fn;
    LispObject v_13746, v_13745, v_13744, v_13743;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "let2");
    va_start(aa, nargs);
    v_13743 = va_arg(aa, LispObject);
    v_13744 = va_arg(aa, LispObject);
    v_13745 = va_arg(aa, LispObject);
    v_13746 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_13746,v_13745,v_13744,v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_13743,v_13744,v_13745,v_13746);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-3] = v_13746;
    stack[-4] = v_13745;
    stack[-5] = v_13744;
    stack[-6] = v_13743;
// end of prologue
    stack[-7] = nil;
    v_14045 = stack[-6];
    fn = elt(env, 12); // getrtype
    v_14045 = (*qfn1(fn))(fn, v_14045);
    env = stack[-8];
    stack[-1] = v_14045;
    if (v_14045 == nil) goto v_13757;
    goto v_13768;
v_13764:
    v_14046 = stack[-1];
    goto v_13765;
v_13766:
    v_14045 = elt(env, 1); // typeletfn
    goto v_13767;
v_13768:
    goto v_13764;
v_13765:
    goto v_13766;
v_13767:
    v_14045 = get(v_14046, v_14045);
    env = stack[-8];
    v_14047 = v_14045;
    if (v_14045 == nil) goto v_13757;
    goto v_13777;
v_13773:
    v_14046 = v_14047;
    goto v_13774;
v_13775:
    v_14045 = elt(env, 2); // direct
    goto v_13776;
v_13777:
    goto v_13773;
v_13774:
    goto v_13775;
v_13776:
    v_14045 = Lflagp(nil, v_14046, v_14045);
    env = stack[-8];
    if (v_14045 == nil) goto v_13757;
    goto v_13785;
v_13781:
    stack[-2] = v_14047;
    goto v_13782;
v_13783:
    goto v_13796;
v_13788:
    stack[-4] = stack[-6];
    goto v_13789;
v_13790:
    stack[0] = stack[-5];
    goto v_13791;
v_13792:
    goto v_13793;
v_13794:
    goto v_13805;
v_13801:
    goto v_13802;
v_13803:
    v_14045 = stack[-5];
    fn = elt(env, 12); // getrtype
    v_14045 = (*qfn1(fn))(fn, v_14045);
    env = stack[-8];
    goto v_13804;
v_13805:
    goto v_13801;
v_13802:
    goto v_13803;
v_13804:
    v_14045 = list2(stack[-3], v_14045);
    env = stack[-8];
    goto v_13795;
v_13796:
    goto v_13788;
v_13789:
    goto v_13790;
v_13791:
    goto v_13792;
v_13793:
    goto v_13794;
v_13795:
    v_14045 = list3star(stack[-4], stack[0], stack[-1], v_14045);
    env = stack[-8];
    goto v_13784;
v_13785:
    goto v_13781;
v_13782:
    goto v_13783;
v_13784:
    {
        LispObject v_14058 = stack[-2];
        fn = elt(env, 13); // lispapply
        return (*qfn2(fn))(fn, v_14058, v_14045);
    }
v_13757:
    v_14045 = stack[-5];
    fn = elt(env, 12); // getrtype
    v_14045 = (*qfn1(fn))(fn, v_14045);
    env = stack[-8];
    stack[-1] = v_14045;
    if (v_14045 == nil) goto v_13810;
    goto v_13821;
v_13817:
    v_14046 = stack[-1];
    goto v_13818;
v_13819:
    v_14045 = elt(env, 1); // typeletfn
    goto v_13820;
v_13821:
    goto v_13817;
v_13818:
    goto v_13819;
v_13820:
    v_14045 = get(v_14046, v_14045);
    env = stack[-8];
    v_14047 = v_14045;
    if (v_14045 == nil) goto v_13810;
    goto v_13830;
v_13826:
    v_14046 = v_14047;
    goto v_13827;
v_13828:
    v_14045 = elt(env, 2); // direct
    goto v_13829;
v_13830:
    goto v_13826;
v_13827:
    goto v_13828;
v_13829:
    v_14045 = Lflagp(nil, v_14046, v_14045);
    env = stack[-8];
    if (v_14045 == nil) goto v_13810;
    goto v_13838;
v_13834:
    stack[-2] = v_14047;
    goto v_13835;
v_13836:
    goto v_13849;
v_13841:
    stack[-4] = stack[-6];
    goto v_13842;
v_13843:
    goto v_13844;
v_13845:
    stack[0] = nil;
    goto v_13846;
v_13847:
    goto v_13858;
v_13854:
    v_14046 = stack[-3];
    goto v_13855;
v_13856:
    v_14045 = stack[-1];
    goto v_13857;
v_13858:
    goto v_13854;
v_13855:
    goto v_13856;
v_13857:
    v_14045 = list2(v_14046, v_14045);
    env = stack[-8];
    goto v_13848;
v_13849:
    goto v_13841;
v_13842:
    goto v_13843;
v_13844:
    goto v_13845;
v_13846:
    goto v_13847;
v_13848:
    v_14045 = list3star(stack[-4], stack[-5], stack[0], v_14045);
    env = stack[-8];
    goto v_13837;
v_13838:
    goto v_13834;
v_13835:
    goto v_13836;
v_13837:
    {
        LispObject v_14059 = stack[-2];
        fn = elt(env, 13); // lispapply
        return (*qfn2(fn))(fn, v_14059, v_14045);
    }
v_13810:
    goto v_13866;
v_13862:
    v_14046 = qvalue(elt(env, 3)); // frasc!*
    goto v_13863;
v_13864:
    v_14045 = stack[-6];
    goto v_13865;
v_13866:
    goto v_13862;
v_13863:
    goto v_13864;
v_13865:
    v_14045 = Lsubla(nil, v_14046, v_14045);
    env = stack[-8];
    stack[-2] = v_14045;
    goto v_13877;
v_13873:
    v_14046 = stack[-2];
    goto v_13874;
v_13875:
    v_14045 = stack[-6];
    goto v_13876;
v_13877:
    goto v_13873;
v_13874:
    goto v_13875;
v_13876:
    if (equal(v_14046, v_14045)) goto v_13872;
    v_14045 = stack[-2];
    if (!consp(v_14045)) goto v_13882;
    else goto v_13883;
v_13882:
    v_14045 = stack[-6];
    {
        fn = elt(env, 14); // errpri1
        return (*qfn1(fn))(fn, v_14045);
    }
v_13883:
    v_14045 = lisp_true;
    stack[-7] = v_14045;
    v_14045 = stack[-2];
    stack[-6] = v_14045;
    goto v_13881;
v_13881:
    goto v_13870;
v_13872:
v_13870:
    goto v_13896;
v_13892:
    v_14046 = qvalue(elt(env, 3)); // frasc!*
    goto v_13893;
v_13894:
    v_14045 = stack[-5];
    goto v_13895;
v_13896:
    goto v_13892;
v_13893:
    goto v_13894;
v_13895:
    v_14045 = Lsubla(nil, v_14046, v_14045);
    env = stack[-8];
    stack[-2] = v_14045;
    goto v_13907;
v_13903:
    v_14046 = stack[-2];
    goto v_13904;
v_13905:
    v_14045 = stack[-5];
    goto v_13906;
v_13907:
    goto v_13903;
v_13904:
    goto v_13905;
v_13906:
    if (equal(v_14046, v_14045)) goto v_13902;
    v_14045 = stack[-2];
    stack[-5] = v_14045;
    goto v_13920;
v_13916:
    v_14046 = stack[-5];
    goto v_13917;
v_13918:
    v_14045 = elt(env, 4); // !*sq!*
    goto v_13919;
v_13920:
    goto v_13916;
v_13917:
    goto v_13918;
v_13919:
    if (!consp(v_14046)) goto v_13914;
    v_14046 = qcar(v_14046);
    if (v_14046 == v_14045) goto v_13913;
    else goto v_13914;
v_13913:
    v_14045 = stack[-5];
    v_14045 = qcdr(v_14045);
    v_14045 = qcar(v_14045);
    fn = elt(env, 15); // prepsq!*
    v_14045 = (*qfn1(fn))(fn, v_14045);
    env = stack[-8];
    stack[-5] = v_14045;
    goto v_13912;
v_13914:
v_13912:
    goto v_13900;
v_13902:
v_13900:
    goto v_13932;
v_13928:
    v_14046 = qvalue(elt(env, 5)); // frlis!*
    goto v_13929;
v_13930:
    v_14045 = qvalue(elt(env, 6)); // mcond!*
    goto v_13931;
v_13932:
    goto v_13928;
v_13929:
    goto v_13930;
v_13931:
    fn = elt(env, 16); // smemql
    v_14045 = (*qfn2(fn))(fn, v_14046, v_14045);
    env = stack[-8];
    stack[-2] = v_14045;
    goto v_13940;
v_13936:
    v_14046 = qvalue(elt(env, 5)); // frlis!*
    goto v_13937;
v_13938:
    v_14045 = stack[-6];
    goto v_13939;
v_13940:
    goto v_13936;
v_13937:
    goto v_13938;
v_13939:
    fn = elt(env, 16); // smemql
    v_14045 = (*qfn2(fn))(fn, v_14046, v_14045);
    env = stack[-8];
    stack[-1] = v_14045;
    goto v_13953;
v_13949:
    v_14046 = stack[-2];
    goto v_13950;
v_13951:
    v_14045 = stack[-1];
    goto v_13952;
v_13953:
    goto v_13949;
v_13950:
    goto v_13951;
v_13952:
    fn = elt(env, 17); // setdiff
    v_14045 = (*qfn2(fn))(fn, v_14046, v_14045);
    env = stack[-8];
    v_14047 = v_14045;
    if (v_14045 == nil) goto v_13947;
    else goto v_13945;
v_13947:
    goto v_13962;
v_13958:
    goto v_13968;
v_13964:
    goto v_13974;
v_13970:
    v_14046 = qvalue(elt(env, 5)); // frlis!*
    goto v_13971;
v_13972:
    v_14045 = stack[-5];
    goto v_13973;
v_13974:
    goto v_13970;
v_13971:
    goto v_13972;
v_13973:
    fn = elt(env, 16); // smemql
    v_14046 = (*qfn2(fn))(fn, v_14046, v_14045);
    env = stack[-8];
    goto v_13965;
v_13966:
    v_14045 = stack[-2];
    goto v_13967;
v_13968:
    goto v_13964;
v_13965:
    goto v_13966;
v_13967:
    fn = elt(env, 17); // setdiff
    stack[0] = (*qfn2(fn))(fn, v_14046, v_14045);
    env = stack[-8];
    goto v_13959;
v_13960:
    goto v_13983;
v_13979:
    v_14046 = stack[-1];
    goto v_13980;
v_13981:
    v_14045 = stack[-2];
    goto v_13982;
v_13983:
    goto v_13979;
v_13980:
    goto v_13981;
v_13982:
    fn = elt(env, 17); // setdiff
    v_14045 = (*qfn2(fn))(fn, v_14046, v_14045);
    env = stack[-8];
    goto v_13961;
v_13962:
    goto v_13958;
v_13959:
    goto v_13960;
v_13961:
    fn = elt(env, 17); // setdiff
    v_14045 = (*qfn2(fn))(fn, stack[0], v_14045);
    env = stack[-8];
    v_14047 = v_14045;
    if (v_14045 == nil) goto v_13956;
    else goto v_13945;
v_13956:
    goto v_13946;
v_13945:
    goto v_13992;
v_13988:
    v_14045 = elt(env, 7); // "Unmatched free variable(s)"
    goto v_13989;
v_13990:
    v_14046 = v_14047;
    goto v_13991;
v_13992:
    goto v_13988;
v_13989:
    goto v_13990;
v_13991:
    v_14045 = cons(v_14045, v_14046);
    env = stack[-8];
    fn = elt(env, 18); // lprie
    v_14045 = (*qfn1(fn))(fn, v_14045);
    env = stack[-8];
    v_14045 = elt(env, 8); // hold
    qvalue(elt(env, 9)) = v_14045; // erfg!*
    v_14045 = nil;
    goto v_13753;
v_13946:
    v_14045 = stack[-6];
    if (!consp(v_14045)) goto v_13997;
    else goto v_13998;
v_13997:
    goto v_13944;
v_13998:
    goto v_14007;
v_14003:
    v_14045 = stack[-6];
    v_14046 = qcar(v_14045);
    goto v_14004;
v_14005:
    v_14045 = elt(env, 10); // getel
    goto v_14006;
v_14007:
    goto v_14003;
v_14004:
    goto v_14005;
v_14006:
    if (v_14046 == v_14045) goto v_14001;
    else goto v_14002;
v_14001:
    v_14045 = stack[-6];
    v_14045 = qcdr(v_14045);
    v_14045 = qcar(v_14045);
    fn = elt(env, 19); // lispeval
    v_14045 = (*qfn1(fn))(fn, v_14045);
    env = stack[-8];
    stack[-6] = v_14045;
    goto v_13944;
v_14002:
    goto v_14022;
v_14018:
    v_14045 = stack[-6];
    v_14046 = qcar(v_14045);
    goto v_14019;
v_14020:
    v_14045 = elt(env, 11); // immediate
    goto v_14021;
v_14022:
    goto v_14018;
v_14019:
    goto v_14020;
v_14021:
    v_14045 = Lflagp(nil, v_14046, v_14045);
    env = stack[-8];
    if (v_14045 == nil) goto v_14016;
    v_14045 = stack[-6];
    fn = elt(env, 20); // reval
    v_14045 = (*qfn1(fn))(fn, v_14045);
    env = stack[-8];
    stack[-6] = v_14045;
    goto v_13944;
v_14016:
v_13944:
    goto v_14039;
v_14029:
    v_14049 = stack[-6];
    goto v_14030;
v_14031:
    v_14048 = stack[-5];
    goto v_14032;
v_14033:
    v_14047 = stack[-4];
    goto v_14034;
v_14035:
    v_14046 = stack[-3];
    goto v_14036;
v_14037:
    v_14045 = stack[-7];
    goto v_14038;
v_14039:
    goto v_14029;
v_14030:
    goto v_14031;
v_14032:
    goto v_14033;
v_14034:
    goto v_14035;
v_14036:
    goto v_14037;
v_14038:
    {
        fn = elt(env, 21); // let3
        return (*qfnn(fn))(fn, 5, v_14049, v_14048, v_14047, v_14046, v_14045);
    }
v_13753:
    return onevalue(v_14045);
}



// Code for riv_mk

static LispObject CC_riv_mk(LispObject env,
                         LispObject v_13743, LispObject v_13744)
{
    env = qenv(env);
    LispObject v_13757, v_13758, v_13759;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13757 = v_13744;
    v_13758 = v_13743;
// end of prologue
    goto v_13753;
v_13747:
    v_13759 = elt(env, 1); // iv
    goto v_13748;
v_13749:
    goto v_13750;
v_13751:
    goto v_13752;
v_13753:
    goto v_13747;
v_13748:
    goto v_13749;
v_13750:
    goto v_13751;
v_13752:
    return list3(v_13759, v_13758, v_13757);
}



// Code for outrefend

static LispObject CC_outrefend(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_14045, v_14046, v_14047;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13743);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_13743;
// end of prologue
    v_14045 = qvalue(elt(env, 1)); // calls!*
    v_14046 = v_14045;
    v_14045 = v_14046;
    if (v_14045 == nil) goto v_13750;
    goto v_13759;
v_13753:
    stack[-1] = stack[-2];
    goto v_13754;
v_13755:
    stack[0] = elt(env, 2); // calls
    goto v_13756;
v_13757:
    v_14045 = qvalue(elt(env, 3)); // toplv!*
    if (v_14045 == nil) goto v_13765;
    goto v_13772;
v_13768:
    v_14047 = v_14046;
    goto v_13769;
v_13770:
    goto v_13779;
v_13775:
    v_14046 = stack[-2];
    goto v_13776;
v_13777:
    v_14045 = elt(env, 2); // calls
    goto v_13778;
v_13779:
    goto v_13775;
v_13776:
    goto v_13777;
v_13778:
    v_14045 = get(v_14046, v_14045);
    env = stack[-4];
    goto v_13771;
v_13772:
    goto v_13768;
v_13769:
    goto v_13770;
v_13771:
    fn = elt(env, 20); // union
    v_14045 = (*qfn2(fn))(fn, v_14047, v_14045);
    env = stack[-4];
    goto v_13763;
v_13765:
    v_14045 = v_14046;
    goto v_13763;
    v_14045 = nil;
v_13763:
    goto v_13758;
v_13759:
    goto v_13753;
v_13754:
    goto v_13755;
v_13756:
    goto v_13757;
v_13758:
    v_14045 = Lputprop(nil, 3, stack[-1], stack[0], v_14045);
    env = stack[-4];
    goto v_13748;
v_13750:
v_13748:
    v_14045 = qvalue(elt(env, 1)); // calls!*
    stack[-1] = v_14045;
v_13788:
    v_14045 = stack[-1];
    if (v_14045 == nil) goto v_13792;
    else goto v_13793;
v_13792:
    goto v_13787;
v_13793:
    v_14045 = stack[-1];
    v_14045 = qcar(v_14045);
    stack[0] = v_14045;
    goto v_13804;
v_13800:
    v_14045 = stack[0];
    v_14046 = ncons(v_14045);
    env = stack[-4];
    goto v_13801;
v_13802:
    v_14045 = elt(env, 4); // cinthis
    goto v_13803;
v_13804:
    goto v_13800;
v_13801:
    goto v_13802;
v_13803:
    v_14045 = Lremflag(nil, v_14046, v_14045);
    env = stack[-4];
    goto v_13816;
v_13812:
    v_14046 = stack[0];
    goto v_13813;
v_13814:
    v_14045 = stack[-2];
    goto v_13815;
v_13816:
    goto v_13812;
v_13813:
    goto v_13814;
v_13815:
    if (v_14046 == v_14045) goto v_13811;
    goto v_13828;
v_13824:
    v_14046 = stack[0];
    goto v_13825;
v_13826:
    v_14045 = elt(env, 5); // seen
    goto v_13827;
v_13828:
    goto v_13824;
v_13825:
    goto v_13826;
v_13827:
    v_14045 = Lflagp(nil, v_14046, v_14045);
    env = stack[-4];
    if (v_14045 == nil) goto v_13821;
    else goto v_13822;
v_13821:
    goto v_13836;
v_13832:
    v_14045 = stack[0];
    v_14046 = ncons(v_14045);
    env = stack[-4];
    goto v_13833;
v_13834:
    v_14045 = elt(env, 5); // seen
    goto v_13835;
v_13836:
    goto v_13832;
v_13833:
    goto v_13834;
v_13835:
    v_14045 = Lflag(nil, v_14046, v_14045);
    env = stack[-4];
    goto v_13845;
v_13841:
    v_14046 = stack[0];
    goto v_13842;
v_13843:
    v_14045 = qvalue(elt(env, 6)); // seen!*
    goto v_13844;
v_13845:
    goto v_13841;
v_13842:
    goto v_13843;
v_13844:
    v_14045 = cons(v_14046, v_14045);
    env = stack[-4];
    qvalue(elt(env, 6)) = v_14045; // seen!*
    goto v_13820;
v_13822:
v_13820:
    goto v_13855;
v_13849:
    v_14047 = stack[0];
    goto v_13850;
v_13851:
    v_14046 = elt(env, 7); // calledby
    goto v_13852;
v_13853:
    v_14045 = stack[-2];
    goto v_13854;
v_13855:
    goto v_13849;
v_13850:
    goto v_13851;
v_13852:
    goto v_13853;
v_13854:
    fn = elt(env, 21); // traput
    v_14045 = (*qfnn(fn))(fn, 3, v_14047, v_14046, v_14045);
    env = stack[-4];
    goto v_13809;
v_13811:
v_13809:
    v_14045 = stack[-1];
    v_14045 = qcdr(v_14045);
    stack[-1] = v_14045;
    goto v_13788;
v_13787:
    v_14045 = qvalue(elt(env, 8)); // globs!*
    v_14046 = v_14045;
    v_14045 = v_14046;
    if (v_14045 == nil) goto v_13866;
    goto v_13875;
v_13869:
    stack[-1] = stack[-2];
    goto v_13870;
v_13871:
    stack[0] = elt(env, 9); // globs
    goto v_13872;
v_13873:
    v_14045 = qvalue(elt(env, 3)); // toplv!*
    if (v_14045 == nil) goto v_13881;
    goto v_13888;
v_13884:
    v_14047 = v_14046;
    goto v_13885;
v_13886:
    goto v_13895;
v_13891:
    v_14046 = stack[-2];
    goto v_13892;
v_13893:
    v_14045 = elt(env, 9); // globs
    goto v_13894;
v_13895:
    goto v_13891;
v_13892:
    goto v_13893;
v_13894:
    v_14045 = get(v_14046, v_14045);
    env = stack[-4];
    goto v_13887;
v_13888:
    goto v_13884;
v_13885:
    goto v_13886;
v_13887:
    fn = elt(env, 20); // union
    v_14045 = (*qfn2(fn))(fn, v_14047, v_14045);
    env = stack[-4];
    goto v_13879;
v_13881:
    v_14045 = v_14046;
    goto v_13879;
    v_14045 = nil;
v_13879:
    goto v_13874;
v_13875:
    goto v_13869;
v_13870:
    goto v_13871;
v_13872:
    goto v_13873;
v_13874:
    v_14045 = Lputprop(nil, 3, stack[-1], stack[0], v_14045);
    env = stack[-4];
    goto v_13864;
v_13866:
v_13864:
    v_14045 = qvalue(elt(env, 8)); // globs!*
    stack[-3] = v_14045;
v_13904:
    v_14045 = stack[-3];
    if (v_14045 == nil) goto v_13908;
    else goto v_13909;
v_13908:
    v_14045 = nil;
    goto v_13903;
v_13909:
    v_14045 = stack[-3];
    v_14045 = qcar(v_14045);
    stack[-1] = v_14045;
    goto v_13922;
v_13916:
    stack[0] = stack[-1];
    goto v_13917;
v_13918:
    goto v_13933;
v_13929:
    v_14046 = stack[-1];
    goto v_13930;
v_13931:
    v_14045 = elt(env, 10); // dclglb
    goto v_13932;
v_13933:
    goto v_13929;
v_13930:
    goto v_13931;
v_13932:
    v_14045 = Lflagp(nil, v_14046, v_14045);
    env = stack[-4];
    if (v_14045 == nil) goto v_13927;
    v_14045 = elt(env, 11); // usedby
    v_14046 = v_14045;
    goto v_13925;
v_13927:
    goto v_13948;
v_13944:
    v_14046 = stack[-1];
    goto v_13945;
v_13946:
    v_14045 = elt(env, 12); // gseen
    goto v_13947;
v_13948:
    goto v_13944;
v_13945:
    goto v_13946;
v_13947:
    v_14045 = Lflagp(nil, v_14046, v_14045);
    env = stack[-4];
    if (v_14045 == nil) goto v_13941;
    else goto v_13942;
v_13941:
    goto v_13956;
v_13952:
    v_14046 = stack[-1];
    goto v_13953;
v_13954:
    v_14045 = qvalue(elt(env, 13)); // gseen!*
    goto v_13955;
v_13956:
    goto v_13952;
v_13953:
    goto v_13954;
v_13955:
    v_14045 = cons(v_14046, v_14045);
    env = stack[-4];
    qvalue(elt(env, 13)) = v_14045; // gseen!*
    goto v_13964;
v_13960:
    v_14045 = stack[-1];
    v_14046 = ncons(v_14045);
    env = stack[-4];
    goto v_13961;
v_13962:
    v_14045 = elt(env, 12); // gseen
    goto v_13963;
v_13964:
    goto v_13960;
v_13961:
    goto v_13962;
v_13963:
    v_14045 = Lflag(nil, v_14046, v_14045);
    env = stack[-4];
    goto v_13940;
v_13942:
v_13940:
    v_14045 = elt(env, 14); // usedunby
    v_14046 = v_14045;
    goto v_13925;
    v_14046 = nil;
v_13925:
    goto v_13919;
v_13920:
    v_14045 = stack[-2];
    goto v_13921;
v_13922:
    goto v_13916;
v_13917:
    goto v_13918;
v_13919:
    goto v_13920;
v_13921:
    fn = elt(env, 21); // traput
    v_14045 = (*qfnn(fn))(fn, 3, stack[0], v_14046, v_14045);
    env = stack[-4];
    goto v_13975;
v_13971:
    v_14045 = stack[-1];
    v_14046 = ncons(v_14045);
    env = stack[-4];
    goto v_13972;
v_13973:
    v_14045 = elt(env, 15); // glb2rf
    goto v_13974;
v_13975:
    goto v_13971;
v_13972:
    goto v_13973;
v_13974:
    v_14045 = Lremflag(nil, v_14046, v_14045);
    env = stack[-4];
    goto v_13988;
v_13984:
    v_14046 = stack[-1];
    goto v_13985;
v_13986:
    v_14045 = elt(env, 16); // glb2bd
    goto v_13987;
v_13988:
    goto v_13984;
v_13985:
    goto v_13986;
v_13987:
    v_14045 = Lflagp(nil, v_14046, v_14045);
    env = stack[-4];
    if (v_14045 == nil) goto v_13982;
    goto v_13996;
v_13992:
    v_14045 = stack[-1];
    v_14046 = ncons(v_14045);
    env = stack[-4];
    goto v_13993;
v_13994:
    v_14045 = elt(env, 16); // glb2bd
    goto v_13995;
v_13996:
    goto v_13992;
v_13993:
    goto v_13994;
v_13995:
    v_14045 = Lremflag(nil, v_14046, v_14045);
    env = stack[-4];
    goto v_14007;
v_14001:
    v_14047 = stack[-1];
    goto v_14002;
v_14003:
    v_14046 = elt(env, 17); // boundby
    goto v_14004;
v_14005:
    v_14045 = stack[-2];
    goto v_14006;
v_14007:
    goto v_14001;
v_14002:
    goto v_14003;
v_14004:
    goto v_14005;
v_14006:
    fn = elt(env, 21); // traput
    v_14045 = (*qfnn(fn))(fn, 3, v_14047, v_14046, v_14045);
    env = stack[-4];
    goto v_13980;
v_13982:
v_13980:
    goto v_14020;
v_14016:
    v_14046 = stack[-1];
    goto v_14017;
v_14018:
    v_14045 = elt(env, 18); // glb2st
    goto v_14019;
v_14020:
    goto v_14016;
v_14017:
    goto v_14018;
v_14019:
    v_14045 = Lflagp(nil, v_14046, v_14045);
    env = stack[-4];
    if (v_14045 == nil) goto v_14014;
    goto v_14028;
v_14024:
    v_14045 = stack[-1];
    v_14046 = ncons(v_14045);
    env = stack[-4];
    goto v_14025;
v_14026:
    v_14045 = elt(env, 18); // glb2st
    goto v_14027;
v_14028:
    goto v_14024;
v_14025:
    goto v_14026;
v_14027:
    v_14045 = Lremflag(nil, v_14046, v_14045);
    env = stack[-4];
    goto v_14039;
v_14033:
    v_14047 = stack[-1];
    goto v_14034;
v_14035:
    v_14046 = elt(env, 19); // setby
    goto v_14036;
v_14037:
    v_14045 = stack[-2];
    goto v_14038;
v_14039:
    goto v_14033;
v_14034:
    goto v_14035;
v_14036:
    goto v_14037;
v_14038:
    fn = elt(env, 21); // traput
    v_14045 = (*qfnn(fn))(fn, 3, v_14047, v_14046, v_14045);
    env = stack[-4];
    goto v_14012;
v_14014:
v_14012:
    v_14045 = stack[-3];
    v_14045 = qcdr(v_14045);
    stack[-3] = v_14045;
    goto v_13904;
v_13903:
    return onevalue(v_14045);
}



// Code for ofsf_ignshift

static LispObject CC_ofsf_ignshift(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13832, v_13833, v_13834;
    LispObject fn;
    LispObject v_13745, v_13744, v_13743;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_ignshift");
    va_start(aa, nargs);
    v_13743 = va_arg(aa, LispObject);
    v_13744 = va_arg(aa, LispObject);
    v_13745 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13745,v_13744,v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13743,v_13744,v_13745);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13745;
    stack[-1] = v_13744;
    stack[-2] = v_13743;
// end of prologue
    goto v_13755;
v_13751:
    v_13832 = stack[-2];
    v_13832 = qcdr(v_13832);
    v_13833 = qcar(v_13832);
    goto v_13752;
v_13753:
    v_13832 = stack[-1];
    goto v_13754;
v_13755:
    goto v_13751;
v_13752:
    goto v_13753;
v_13754:
    fn = elt(env, 5); // sfto_reorder
    v_13832 = (*qfn2(fn))(fn, v_13833, v_13832);
    env = stack[-3];
    v_13834 = v_13832;
    v_13832 = v_13834;
    if (!consp(v_13832)) goto v_13770;
    else goto v_13771;
v_13770:
    v_13832 = lisp_true;
    goto v_13769;
v_13771:
    v_13832 = v_13834;
    v_13832 = qcar(v_13832);
    v_13832 = (consp(v_13832) ? nil : lisp_true);
    goto v_13769;
    v_13832 = nil;
v_13769:
    if (v_13832 == nil) goto v_13766;
    else goto v_13767;
v_13766:
    v_13832 = v_13834;
    v_13832 = qcdr(v_13832);
    if (v_13832 == nil) goto v_13781;
    else goto v_13782;
v_13781:
    goto v_13789;
v_13785:
    v_13832 = v_13834;
    v_13832 = qcar(v_13832);
    v_13832 = qcar(v_13832);
    v_13833 = qcar(v_13832);
    goto v_13786;
v_13787:
    v_13832 = stack[-1];
    goto v_13788;
v_13789:
    goto v_13785;
v_13786:
    goto v_13787;
v_13788:
    v_13832 = (v_13833 == v_13832 ? lisp_true : nil);
    goto v_13780;
v_13782:
    v_13832 = nil;
    goto v_13780;
    v_13832 = nil;
v_13780:
    goto v_13765;
v_13767:
    v_13832 = nil;
    goto v_13765;
    v_13832 = nil;
v_13765:
    if (v_13832 == nil) goto v_13763;
    v_13832 = qvalue(elt(env, 1)); // !*rlpos
    if (v_13832 == nil) goto v_13806;
    else goto v_13804;
v_13806:
    v_13832 = stack[0];
    if (v_13832 == nil) goto v_13809;
    else goto v_13804;
v_13809:
    goto v_13817;
v_13813:
    v_13832 = stack[-2];
    v_13833 = qcar(v_13832);
    goto v_13814;
v_13815:
    v_13832 = elt(env, 2); // (equal neq)
    goto v_13816;
v_13817:
    goto v_13813;
v_13814:
    goto v_13815;
v_13816:
    v_13832 = Lmemq(nil, v_13833, v_13832);
    if (v_13832 == nil) goto v_13812;
    else goto v_13804;
v_13812:
    v_13832 = v_13834;
    v_13832 = qcar(v_13832);
    v_13832 = qcar(v_13832);
    v_13832 = qcdr(v_13832);
    v_13832 = Levenp(nil, v_13832);
    env = stack[-3];
    if (v_13832 == nil) goto v_13822;
    else goto v_13804;
v_13822:
    goto v_13805;
v_13804:
    v_13832 = elt(env, 3); // ignore
    goto v_13749;
v_13805:
    v_13832 = elt(env, 4); // odd
    goto v_13749;
    goto v_13761;
v_13763:
v_13761:
    v_13832 = nil;
v_13749:
    return onevalue(v_13832);
}



// Code for settinsert

static LispObject CC_settinsert(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13757, v_13758;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13743);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_13743;
// end of prologue
    v_13757 = stack[0];
    fn = elt(env, 2); // janettreeinsert
    v_13757 = (*qfn1(fn))(fn, v_13757);
    env = stack[-1];
    goto v_13754;
v_13750:
    v_13758 = stack[0];
    goto v_13751;
v_13752:
    v_13757 = qvalue(elt(env, 1)); // fluidbibasissett
    goto v_13753;
v_13754:
    goto v_13750;
v_13751:
    goto v_13752;
v_13753:
    v_13757 = cons(v_13758, v_13757);
    env = stack[-1];
    qvalue(elt(env, 1)) = v_13757; // fluidbibasissett
    v_13757 = nil;
    return onevalue(v_13757);
}



// Code for rl_eqnrhskernels

static LispObject CC_rl_eqnrhskernels(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13754;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13743);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_13754 = v_13743;
// end of prologue
    goto v_13750;
v_13746:
    stack[0] = qvalue(elt(env, 1)); // rl_eqnrhskernels!*
    goto v_13747;
v_13748:
    v_13754 = ncons(v_13754);
    env = stack[-1];
    goto v_13749;
v_13750:
    goto v_13746;
v_13747:
    goto v_13748;
v_13749:
    {
        LispObject v_13756 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_13756, v_13754);
    }
}



// Code for pasf_smwupdknowl

static LispObject CC_pasf_smwupdknowl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13783, v_13784, v_13785, v_13786, v_13787;
    LispObject fn;
    LispObject v_13746, v_13745, v_13744, v_13743;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "pasf_smwupdknowl");
    va_start(aa, nargs);
    v_13743 = va_arg(aa, LispObject);
    v_13744 = va_arg(aa, LispObject);
    v_13745 = va_arg(aa, LispObject);
    v_13746 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13784 = v_13746;
    v_13785 = v_13745;
    v_13786 = v_13744;
    v_13787 = v_13743;
// end of prologue
    v_13783 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_13783 == nil) goto v_13751;
    goto v_13762;
v_13754:
    v_13783 = v_13787;
    goto v_13755;
v_13756:
    goto v_13757;
v_13758:
    goto v_13759;
v_13760:
    goto v_13761;
v_13762:
    goto v_13754;
v_13755:
    goto v_13756;
v_13757:
    goto v_13758;
v_13759:
    goto v_13760;
v_13761:
    {
        fn = elt(env, 2); // cl_susiupdknowl
        return (*qfnn(fn))(fn, 4, v_13783, v_13786, v_13785, v_13784);
    }
v_13751:
    goto v_13778;
v_13770:
    v_13783 = v_13787;
    goto v_13771;
v_13772:
    goto v_13773;
v_13774:
    goto v_13775;
v_13776:
    goto v_13777;
v_13778:
    goto v_13770;
v_13771:
    goto v_13772;
v_13773:
    goto v_13774;
v_13775:
    goto v_13776;
v_13777:
    {
        fn = elt(env, 3); // cl_smupdknowl
        return (*qfnn(fn))(fn, 4, v_13783, v_13786, v_13785, v_13784);
    }
    v_13783 = nil;
    return onevalue(v_13783);
}



// Code for rl_updcache

static LispObject CC_rl_updcache(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13860, v_13861;
    argcheck(nargs, 0, "rl_updcache");
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
    v_13860 = qvalue(elt(env, 1)); // rl_bbl!*
    stack[0] = v_13860;
v_13747:
    v_13860 = stack[0];
    if (v_13860 == nil) goto v_13751;
    else goto v_13752;
v_13751:
    goto v_13746;
v_13752:
    v_13860 = stack[0];
    v_13860 = qcar(v_13860);
    goto v_13763;
v_13759:
    v_13861 = v_13860;
    goto v_13760;
v_13761:
    v_13860 = nil;
    goto v_13762;
v_13763:
    goto v_13759;
v_13760:
    goto v_13761;
v_13762:
    v_13860 = Lset(nil, v_13861, v_13860);
    env = stack[-1];
    v_13860 = stack[0];
    v_13860 = qcdr(v_13860);
    stack[0] = v_13860;
    goto v_13747;
v_13746:
    goto v_13777;
v_13773:
    v_13860 = qvalue(elt(env, 2)); // rl_cid!*
    v_13861 = qcar(v_13860);
    goto v_13774;
v_13775:
    v_13860 = elt(env, 3); // rl_params
    goto v_13776;
v_13777:
    goto v_13773;
v_13774:
    goto v_13775;
v_13776:
    v_13860 = get(v_13861, v_13860);
    env = stack[-1];
    stack[0] = v_13860;
v_13771:
    v_13860 = stack[0];
    if (v_13860 == nil) goto v_13783;
    else goto v_13784;
v_13783:
    goto v_13770;
v_13784:
    v_13860 = stack[0];
    v_13860 = qcar(v_13860);
    goto v_13795;
v_13791:
    v_13861 = v_13860;
    v_13861 = qcar(v_13861);
    goto v_13792;
v_13793:
    v_13860 = qcdr(v_13860);
    goto v_13794;
v_13795:
    goto v_13791;
v_13792:
    goto v_13793;
v_13794:
    v_13860 = Lset(nil, v_13861, v_13860);
    env = stack[-1];
    v_13860 = stack[0];
    v_13860 = qcdr(v_13860);
    stack[0] = v_13860;
    goto v_13771;
v_13770:
    v_13860 = qvalue(elt(env, 4)); // rl_servl!*
    stack[0] = v_13860;
v_13805:
    v_13860 = stack[0];
    if (v_13860 == nil) goto v_13809;
    else goto v_13810;
v_13809:
    goto v_13804;
v_13810:
    v_13860 = stack[0];
    v_13860 = qcar(v_13860);
    goto v_13821;
v_13817:
    v_13861 = v_13860;
    goto v_13818;
v_13819:
    v_13860 = nil;
    goto v_13820;
v_13821:
    goto v_13817;
v_13818:
    goto v_13819;
v_13820:
    v_13860 = Lset(nil, v_13861, v_13860);
    env = stack[-1];
    v_13860 = stack[0];
    v_13860 = qcdr(v_13860);
    stack[0] = v_13860;
    goto v_13805;
v_13804:
    goto v_13835;
v_13831:
    v_13860 = qvalue(elt(env, 2)); // rl_cid!*
    v_13861 = qcar(v_13860);
    goto v_13832;
v_13833:
    v_13860 = elt(env, 5); // rl_services
    goto v_13834;
v_13835:
    goto v_13831;
v_13832:
    goto v_13833;
v_13834:
    v_13860 = get(v_13861, v_13860);
    env = stack[-1];
    stack[0] = v_13860;
v_13829:
    v_13860 = stack[0];
    if (v_13860 == nil) goto v_13841;
    else goto v_13842;
v_13841:
    v_13860 = nil;
    goto v_13828;
v_13842:
    v_13860 = stack[0];
    v_13860 = qcar(v_13860);
    goto v_13853;
v_13849:
    v_13861 = v_13860;
    v_13861 = qcar(v_13861);
    goto v_13850;
v_13851:
    v_13860 = qcdr(v_13860);
    goto v_13852;
v_13853:
    goto v_13849;
v_13850:
    goto v_13851;
v_13852:
    v_13860 = Lset(nil, v_13861, v_13860);
    env = stack[-1];
    v_13860 = stack[0];
    v_13860 = qcdr(v_13860);
    stack[0] = v_13860;
    goto v_13829;
v_13828:
    return onevalue(v_13860);
}



// Code for diff!-k!-times!-mod!-p

static LispObject CC_diffKkKtimesKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13928, v_13929, v_13930;
    LispObject fn;
    LispObject v_13745, v_13744, v_13743;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "diff-k-times-mod-p");
    va_start(aa, nargs);
    v_13743 = va_arg(aa, LispObject);
    v_13744 = va_arg(aa, LispObject);
    v_13745 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13745,v_13744,v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13743,v_13744,v_13745);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_13745;
    stack[-2] = v_13744;
    stack[-3] = v_13743;
// end of prologue
    v_13928 = stack[-3];
    if (!consp(v_13928)) goto v_13753;
    else goto v_13754;
v_13753:
    v_13928 = lisp_true;
    goto v_13752;
v_13754:
    v_13928 = stack[-3];
    v_13928 = qcar(v_13928);
    v_13928 = (consp(v_13928) ? nil : lisp_true);
    goto v_13752;
    v_13928 = nil;
v_13752:
    if (v_13928 == nil) goto v_13750;
    v_13928 = nil;
    goto v_13748;
v_13750:
    goto v_13769;
v_13765:
    v_13928 = stack[-3];
    v_13928 = qcar(v_13928);
    v_13928 = qcar(v_13928);
    v_13929 = qcar(v_13928);
    goto v_13766;
v_13767:
    v_13928 = stack[-1];
    goto v_13768;
v_13769:
    goto v_13765;
v_13766:
    goto v_13767;
v_13768:
    if (equal(v_13929, v_13928)) goto v_13763;
    else goto v_13764;
v_13763:
    goto v_13784;
v_13780:
    v_13928 = stack[-3];
    v_13928 = qcar(v_13928);
    v_13928 = qcar(v_13928);
    v_13929 = qcdr(v_13928);
    goto v_13781;
v_13782:
    v_13928 = stack[-2];
    goto v_13783;
v_13784:
    goto v_13780;
v_13781:
    goto v_13782;
v_13783:
    v_13928 = (LispObject)lessp2(v_13929, v_13928);
    v_13928 = v_13928 ? lisp_true : nil;
    env = stack[-5];
    if (v_13928 == nil) goto v_13778;
    v_13928 = nil;
    goto v_13776;
v_13778:
    goto v_13797;
v_13793:
    v_13928 = stack[-3];
    v_13928 = qcar(v_13928);
    v_13928 = qcar(v_13928);
    v_13929 = qcdr(v_13928);
    goto v_13794;
v_13795:
    v_13928 = stack[-2];
    goto v_13796;
v_13797:
    goto v_13793;
v_13794:
    goto v_13795;
v_13796:
    if (equal(v_13929, v_13928)) goto v_13791;
    else goto v_13792;
v_13791:
    v_13928 = stack[-3];
    v_13928 = qcar(v_13928);
    v_13928 = qcdr(v_13928);
    goto v_13776;
v_13792:
    goto v_13813;
v_13809:
    goto v_13819;
v_13815:
    v_13928 = stack[-3];
    v_13928 = qcar(v_13928);
    v_13928 = qcar(v_13928);
    v_13929 = qcdr(v_13928);
    goto v_13816;
v_13817:
    v_13928 = stack[-2];
    goto v_13818;
v_13819:
    goto v_13815;
v_13816:
    goto v_13817;
v_13818:
    fn = elt(env, 1); // binomial!-coefft!-mod!-p
    v_13929 = (*qfn2(fn))(fn, v_13929, v_13928);
    env = stack[-5];
    goto v_13810;
v_13811:
    v_13928 = stack[-3];
    v_13928 = qcar(v_13928);
    v_13928 = qcdr(v_13928);
    goto v_13812;
v_13813:
    goto v_13809;
v_13810:
    goto v_13811;
v_13812:
    fn = elt(env, 2); // times!-mod!-p
    stack[0] = (*qfn2(fn))(fn, v_13929, v_13928);
    env = stack[-5];
    goto v_13835;
v_13829:
    v_13928 = stack[-3];
    v_13930 = qcdr(v_13928);
    goto v_13830;
v_13831:
    v_13929 = stack[-2];
    goto v_13832;
v_13833:
    v_13928 = stack[-1];
    goto v_13834;
v_13835:
    goto v_13829;
v_13830:
    goto v_13831;
v_13832:
    goto v_13833;
v_13834:
    v_13928 = CC_diffKkKtimesKmodKp(elt(env, 0), 3, v_13930, v_13929, v_13928);
    env = stack[-5];
    stack[-4] = stack[0];
    stack[0] = v_13928;
    v_13928 = stack[-4];
    if (v_13928 == nil) goto v_13844;
    else goto v_13845;
v_13844:
    v_13928 = stack[0];
    goto v_13843;
v_13845:
    goto v_13857;
v_13851:
    goto v_13863;
v_13859:
    goto v_13860;
v_13861:
    goto v_13870;
v_13866:
    v_13928 = stack[-3];
    v_13928 = qcar(v_13928);
    v_13928 = qcar(v_13928);
    v_13929 = qcdr(v_13928);
    goto v_13867;
v_13868:
    v_13928 = stack[-2];
    goto v_13869;
v_13870:
    goto v_13866;
v_13867:
    goto v_13868;
v_13869:
    v_13928 = difference2(v_13929, v_13928);
    env = stack[-5];
    goto v_13862;
v_13863:
    goto v_13859;
v_13860:
    goto v_13861;
v_13862:
    fn = elt(env, 3); // mksp
    v_13930 = (*qfn2(fn))(fn, stack[-1], v_13928);
    goto v_13852;
v_13853:
    v_13929 = stack[-4];
    goto v_13854;
v_13855:
    v_13928 = stack[0];
    goto v_13856;
v_13857:
    goto v_13851;
v_13852:
    goto v_13853;
v_13854:
    goto v_13855;
v_13856:
    return acons(v_13930, v_13929, v_13928);
    v_13928 = nil;
v_13843:
    goto v_13776;
    v_13928 = nil;
v_13776:
    goto v_13748;
v_13764:
    goto v_13887;
v_13881:
    v_13928 = stack[-3];
    v_13928 = qcar(v_13928);
    v_13930 = qcdr(v_13928);
    goto v_13882;
v_13883:
    v_13929 = stack[-2];
    goto v_13884;
v_13885:
    v_13928 = stack[-1];
    goto v_13886;
v_13887:
    goto v_13881;
v_13882:
    goto v_13883;
v_13884:
    goto v_13885;
v_13886:
    stack[0] = CC_diffKkKtimesKmodKp(elt(env, 0), 3, v_13930, v_13929, v_13928);
    env = stack[-5];
    goto v_13900;
v_13894:
    v_13928 = stack[-3];
    v_13930 = qcdr(v_13928);
    goto v_13895;
v_13896:
    v_13929 = stack[-2];
    goto v_13897;
v_13898:
    v_13928 = stack[-1];
    goto v_13899;
v_13900:
    goto v_13894;
v_13895:
    goto v_13896;
v_13897:
    goto v_13898;
v_13899:
    v_13928 = CC_diffKkKtimesKmodKp(elt(env, 0), 3, v_13930, v_13929, v_13928);
    v_13929 = stack[0];
    v_13930 = v_13929;
    if (v_13930 == nil) goto v_13909;
    else goto v_13910;
v_13909:
    goto v_13908;
v_13910:
    goto v_13922;
v_13916:
    v_13930 = stack[-3];
    v_13930 = qcar(v_13930);
    v_13930 = qcar(v_13930);
    goto v_13917;
v_13918:
    goto v_13919;
v_13920:
    goto v_13921;
v_13922:
    goto v_13916;
v_13917:
    goto v_13918;
v_13919:
    goto v_13920;
v_13921:
    return acons(v_13930, v_13929, v_13928);
    v_13928 = nil;
v_13908:
    goto v_13748;
    v_13928 = nil;
v_13748:
    return onevalue(v_13928);
}



// Code for om2ir

static LispObject CC_om2ir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13806, v_13807;
    LispObject fn;
    argcheck(nargs, 0, "om2ir");
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
    v_13806 = nil;
    stack[0] = v_13806;
    v_13806 = elt(env, 1); // (safe_atts char ch atts count temp space temp2)
    fn = elt(env, 11); // fluid
    v_13806 = (*qfn1(fn))(fn, v_13806);
    env = stack[-1];
    v_13806 = (LispObject)512+TAG_FIXNUM; // 32
    v_13806 = ncons(v_13806);
    env = stack[-1];
    fn = elt(env, 12); // list2string
    v_13806 = (*qfn1(fn))(fn, v_13806);
    env = stack[-1];
    v_13806 = Lintern(nil, v_13806);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_13806; // space
    v_13806 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 3)) = v_13806; // count
    v_13806 = Lreadch(nil, 0);
    env = stack[-1];
    qvalue(elt(env, 4)) = v_13806; // ch
    v_13806 = nil;
    qvalue(elt(env, 5)) = v_13806; // temp2
    fn = elt(env, 13); // lex
    v_13806 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_13766;
v_13762:
    v_13807 = qvalue(elt(env, 6)); // char
    goto v_13763;
v_13764:
    v_13806 = elt(env, 7); // (o m o b j)
    goto v_13765;
v_13766:
    goto v_13762;
v_13763:
    goto v_13764;
v_13765:
    if (equal(v_13807, v_13806)) goto v_13760;
    else goto v_13761;
v_13760:
    fn = elt(env, 13); // lex
    v_13806 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    fn = elt(env, 14); // omobj
    v_13806 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_13806;
    goto v_13759;
v_13761:
    goto v_13779;
v_13775:
    v_13807 = elt(env, 8); // "<omobj>"
    goto v_13776;
v_13777:
    v_13806 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13778;
v_13779:
    goto v_13775;
v_13776:
    goto v_13777;
v_13778:
    fn = elt(env, 15); // errorml
    v_13806 = (*qfn2(fn))(fn, v_13807, v_13806);
    env = stack[-1];
    goto v_13759;
v_13759:
    fn = elt(env, 13); // lex
    v_13806 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_13791;
v_13787:
    v_13807 = qvalue(elt(env, 6)); // char
    goto v_13788;
v_13789:
    v_13806 = elt(env, 9); // (!/ o m o b j)
    goto v_13790;
v_13791:
    goto v_13787;
v_13788:
    goto v_13789;
v_13790:
    if (equal(v_13807, v_13806)) goto v_13785;
    else goto v_13786;
v_13785:
    v_13806 = Lterpri(nil, 0);
    goto v_13784;
v_13786:
    goto v_13802;
v_13798:
    v_13807 = elt(env, 10); // "</omobj>"
    goto v_13799;
v_13800:
    v_13806 = (LispObject)304+TAG_FIXNUM; // 19
    goto v_13801;
v_13802:
    goto v_13798;
v_13799:
    goto v_13800;
v_13801:
    fn = elt(env, 15); // errorml
    v_13806 = (*qfn2(fn))(fn, v_13807, v_13806);
    goto v_13784;
v_13784:
    v_13806 = stack[0];
    return onevalue(v_13806);
}



// Code for rationalizesq

static LispObject CC_rationalizesq(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13857, v_13858;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13743);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_13743;
// end of prologue
// Binding !*structure
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = nil; // !*structure
// Binding !*sub2
// FLUIDBIND: reloadenv=5 litvec-offset=2 saveloc=2
{   bind_fluid_stack bind_fluid_var(-5, 2, -2);
    qvalue(elt(env, 2)) = nil; // !*sub2
    goto v_13760;
v_13756:
    v_13858 = qvalue(elt(env, 3)); // dmode!*
    goto v_13757;
v_13758:
    v_13857 = elt(env, 4); // rationalizefn
    goto v_13759;
v_13760:
    goto v_13756;
v_13757:
    goto v_13758;
v_13759:
    v_13857 = get(v_13858, v_13857);
    env = stack[-5];
    stack[0] = v_13857;
    if (v_13857 == nil) goto v_13754;
    goto v_13768;
v_13764:
    v_13858 = stack[0];
    goto v_13765;
v_13766:
    v_13857 = stack[-3];
    goto v_13767;
v_13768:
    goto v_13764;
v_13765:
    goto v_13766;
v_13767:
    v_13857 = Lapply1(nil, v_13858, v_13857);
    env = stack[-5];
    stack[-3] = v_13857;
    goto v_13752;
v_13754:
v_13752:
    goto v_13776;
v_13772:
    v_13858 = elt(env, 5); // (i 2 (nil . t) -1 nil)
    goto v_13773;
v_13774:
    v_13857 = qvalue(elt(env, 6)); // powlis!*
    goto v_13775;
v_13776:
    goto v_13772;
v_13773:
    goto v_13774;
v_13775:
    v_13857 = cons(v_13858, v_13857);
    env = stack[-5];
    qvalue(elt(env, 6)) = v_13857; // powlis!*
    v_13857 = stack[-3];
    fn = elt(env, 9); // subs2q
    v_13857 = (*qfn1(fn))(fn, v_13857);
    env = stack[-5];
    stack[-1] = v_13857;
    v_13857 = qvalue(elt(env, 6)); // powlis!*
    v_13857 = qcdr(v_13857);
    qvalue(elt(env, 6)) = v_13857; // powlis!*
    v_13857 = stack[-1];
    v_13857 = qcdr(v_13857);
    if (!consp(v_13857)) goto v_13789;
    else goto v_13790;
v_13789:
    v_13857 = lisp_true;
    goto v_13788;
v_13790:
    v_13857 = stack[-1];
    v_13857 = qcdr(v_13857);
    v_13857 = qcar(v_13857);
    v_13857 = (consp(v_13857) ? nil : lisp_true);
    goto v_13788;
    v_13857 = nil;
v_13788:
    if (v_13857 == nil) goto v_13786;
    v_13857 = stack[-1];
    goto v_13784;
v_13786:
    goto v_13807;
v_13803:
    v_13857 = stack[-1];
    v_13857 = qcdr(v_13857);
    fn = elt(env, 10); // rationalizef
    v_13858 = (*qfn1(fn))(fn, v_13857);
    env = stack[-5];
    stack[0] = v_13858;
    goto v_13804;
v_13805:
    v_13857 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13806;
v_13807:
    goto v_13803;
v_13804:
    goto v_13805;
v_13806:
    if (v_13858 == v_13857) goto v_13802;
    goto v_13817;
v_13813:
    goto v_13823;
v_13819:
    v_13857 = stack[-1];
    v_13858 = qcar(v_13857);
    goto v_13820;
v_13821:
    v_13857 = stack[0];
    goto v_13822;
v_13823:
    goto v_13819;
v_13820:
    goto v_13821;
v_13822:
    fn = elt(env, 11); // multf
    stack[-3] = (*qfn2(fn))(fn, v_13858, v_13857);
    env = stack[-5];
    goto v_13814;
v_13815:
    goto v_13832;
v_13828:
    v_13857 = stack[-1];
    v_13858 = qcdr(v_13857);
    goto v_13829;
v_13830:
    v_13857 = stack[0];
    goto v_13831;
v_13832:
    goto v_13828;
v_13829:
    goto v_13830;
v_13831:
    fn = elt(env, 11); // multf
    v_13857 = (*qfn2(fn))(fn, v_13858, v_13857);
    env = stack[-5];
    goto v_13816;
v_13817:
    goto v_13813;
v_13814:
    goto v_13815;
v_13816:
    v_13857 = cons(stack[-3], v_13857);
    env = stack[-5];
    stack[-1] = v_13857;
    v_13857 = qvalue(elt(env, 7)); // !*algint
    if (v_13857 == nil) goto v_13842;
    else goto v_13843;
v_13842:
    v_13857 = qvalue(elt(env, 8)); // !*rationalize
    v_13857 = (v_13857 == nil ? lisp_true : nil);
    goto v_13841;
v_13843:
    v_13857 = nil;
    goto v_13841;
    v_13857 = nil;
v_13841:
    if (v_13857 == nil) goto v_13839;
    v_13857 = stack[-1];
    fn = elt(env, 12); // gcdchk
    v_13857 = (*qfn1(fn))(fn, v_13857);
    env = stack[-5];
    stack[-1] = v_13857;
    goto v_13837;
v_13839:
v_13837:
    v_13857 = stack[-1];
    fn = elt(env, 9); // subs2q
    v_13857 = (*qfn1(fn))(fn, v_13857);
    goto v_13784;
v_13802:
    v_13857 = stack[-3];
    goto v_13784;
    v_13857 = nil;
v_13784:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_13857);
}



// Code for quoteequation

static LispObject CC_quoteequation(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13746;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13746 = v_13743;
// end of prologue
    v_13746 = elt(env, 1); // equation
    return onevalue(v_13746);
}



// Code for cos!*

static LispObject CC_cosH(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13753, v_13754;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13753 = v_13743;
// end of prologue
    goto v_13750;
v_13746:
    v_13754 = v_13753;
    goto v_13747;
v_13748:
    v_13753 = qvalue(elt(env, 1)); // !:bprec!:
    goto v_13749;
v_13750:
    goto v_13746;
v_13747:
    goto v_13748;
v_13749:
    {
        fn = elt(env, 2); // cos!:
        return (*qfn2(fn))(fn, v_13754, v_13753);
    }
}



// Code for flatindl

static LispObject CC_flatindl(LispObject env,
                         LispObject v_13743)
{
    env = qenv(env);
    LispObject v_13786, v_13787;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13743);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13743);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13743;
// end of prologue
    stack[-1] = nil;
v_13749:
    v_13786 = stack[0];
    if (v_13786 == nil) goto v_13754;
    else goto v_13755;
v_13754:
    goto v_13750;
v_13755:
    goto v_13762;
v_13758:
    v_13786 = stack[0];
    v_13787 = qcar(v_13786);
    goto v_13759;
v_13760:
    v_13786 = stack[-1];
    goto v_13761;
v_13762:
    goto v_13758;
v_13759:
    goto v_13760;
v_13761:
    v_13786 = cons(v_13787, v_13786);
    env = stack[-2];
    stack[-1] = v_13786;
    v_13786 = stack[0];
    v_13786 = qcdr(v_13786);
    stack[0] = v_13786;
    goto v_13749;
v_13750:
    v_13786 = nil;
    v_13787 = v_13786;
v_13751:
    v_13786 = stack[-1];
    if (v_13786 == nil) goto v_13771;
    else goto v_13772;
v_13771:
    v_13786 = v_13787;
    goto v_13748;
v_13772:
    goto v_13780;
v_13776:
    v_13786 = stack[-1];
    v_13786 = qcar(v_13786);
    goto v_13777;
v_13778:
    goto v_13779;
v_13780:
    goto v_13776;
v_13777:
    goto v_13778;
v_13779:
    v_13786 = Lappend(nil, v_13786, v_13787);
    env = stack[-2];
    v_13787 = v_13786;
    v_13786 = stack[-1];
    v_13786 = qcdr(v_13786);
    stack[-1] = v_13786;
    goto v_13751;
v_13748:
    return onevalue(v_13786);
}



setup_type const u24_setup[] =
{
    {"fs:prin1",                CC_fsTprin1,    TOO_MANY_1,    WRONG_NO_1},
    {"st_sorttree",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_st_sorttree},
    {"general-modular-expt",    TOO_FEW_2,      CC_generalKmodularKexpt,WRONG_NO_2},
    {"random-teeny-prime",      CC_randomKteenyKprime,TOO_MANY_1,WRONG_NO_1},
    {"refprint",                CC_refprint,    TOO_MANY_1,    WRONG_NO_1},
    {"polynomlistreduce",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_polynomlistreduce},
    {"pasf_sacat",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pasf_sacat},
    {"unaryrd",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_unaryrd},
    {"groedeletip",             TOO_FEW_2,      CC_groedeletip,WRONG_NO_2},
    {"mktails",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mktails},
    {"numlist_ordp",            TOO_FEW_2,      CC_numlist_ordp,WRONG_NO_2},
    {"lambda_ygm6np4pcqv31",    TOO_FEW_2,      CC_lambda_ygm6np4pcqv31,WRONG_NO_2},
    {"subf",                    TOO_FEW_2,      CC_subf,       WRONG_NO_2},
    {"lalr_prin_production",    CC_lalr_prin_production,TOO_MANY_1,WRONG_NO_1},
    {"cl_pnf",                  CC_cl_pnf,      TOO_MANY_1,    WRONG_NO_1},
    {"poly-multfnc",            TOO_FEW_2,      CC_polyKmultfnc,WRONG_NO_2},
    {"lto_nconcn",              CC_lto_nconcn,  TOO_MANY_1,    WRONG_NO_1},
    {"inprint",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_inprint},
    {"row",                     CC_row,         TOO_MANY_1,    WRONG_NO_1},
    {"my_letmtr",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_my_letmtr},
    {"gbfdot",                  TOO_FEW_2,      CC_gbfdot,     WRONG_NO_2},
    {"build-null-vector",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_buildKnullKvector},
    {"lex_cleanup",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex_cleanup},
    {"tripleisprolongedby",     TOO_FEW_2,      CC_tripleisprolongedby,WRONG_NO_2},
    {"ofsf_smupdknowl",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smupdknowl},
    {"rl_subalchk",             CC_rl_subalchk, TOO_MANY_1,    WRONG_NO_1},
    {"pasf_smwcpknowl",         CC_pasf_smwcpknowl,TOO_MANY_1, WRONG_NO_1},
    {"bvarml",                  CC_bvarml,      TOO_MANY_1,    WRONG_NO_1},
    {"ps:get-term",             TOO_FEW_2,      CC_psTgetKterm,WRONG_NO_2},
    {"rd:zerop:",               CC_rdTzeropT,   TOO_MANY_1,    WRONG_NO_1},
    {"mktails1",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mktails1},
    {"splitcomplex",            CC_splitcomplex,TOO_MANY_1,    WRONG_NO_1},
    {"red_totalred",            TOO_FEW_2,      CC_red_totalred,WRONG_NO_2},
    {"gcdout",                  CC_gcdout,      TOO_MANY_1,    WRONG_NO_1},
    {"ilog2",                   CC_ilog2,       TOO_MANY_1,    WRONG_NO_1},
    {"let2",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_let2},
    {"riv_mk",                  TOO_FEW_2,      CC_riv_mk,     WRONG_NO_2},
    {"outrefend",               CC_outrefend,   TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_ignshift",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_ignshift},
    {"settinsert",              CC_settinsert,  TOO_MANY_1,    WRONG_NO_1},
    {"rl_eqnrhskernels",        CC_rl_eqnrhskernels,TOO_MANY_1,WRONG_NO_1},
    {"pasf_smwupdknowl",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pasf_smwupdknowl},
    {"rl_updcache",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rl_updcache},
    {"diff-k-times-mod-p",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_diffKkKtimesKmodKp},
    {"om2ir",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_om2ir},
    {"rationalizesq",           CC_rationalizesq,TOO_MANY_1,   WRONG_NO_1},
    {"quoteequation",           CC_quoteequation,TOO_MANY_1,   WRONG_NO_1},
    {"cos*",                    CC_cosH,        TOO_MANY_1,    WRONG_NO_1},
    {"flatindl",                CC_flatindl,    TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u24", (two_args *)"174657 6676070 1844823", 0}
};

// end of generated code
