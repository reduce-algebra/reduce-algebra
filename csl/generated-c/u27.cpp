
// $destdir/u27.c        Machine generated C code

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



// Code for extmult

static LispObject CC_extmult(LispObject env,
                         LispObject v_15125, LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15274, v_15275, v_15276;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15125,v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_15126;
    stack[-4] = v_15125;
// end of prologue
    stack[-5] = nil;
v_15134:
    v_15274 = stack[-4];
    if (v_15274 == nil) goto v_15142;
    else goto v_15143;
v_15142:
    v_15274 = lisp_true;
    goto v_15141;
v_15143:
    v_15274 = stack[-3];
    v_15274 = (v_15274 == nil ? lisp_true : nil);
    goto v_15141;
    v_15274 = nil;
v_15141:
    if (v_15274 == nil) goto v_15139;
    v_15274 = nil;
    stack[0] = v_15274;
    goto v_15135;
v_15139:
    goto v_15158;
v_15152:
    v_15276 = stack[-4];
    goto v_15153;
v_15154:
    v_15275 = stack[-3];
    goto v_15155;
v_15156:
    v_15274 = stack[-5];
    goto v_15157;
v_15158:
    goto v_15152;
v_15153:
    goto v_15154;
v_15155:
    goto v_15156;
v_15157:
    v_15274 = acons(v_15276, v_15275, v_15274);
    env = stack[-6];
    stack[-5] = v_15274;
    v_15274 = stack[-4];
    v_15274 = qcdr(v_15274);
    if (v_15274 == nil) goto v_15165;
    v_15274 = stack[-4];
    v_15274 = qcar(v_15274);
    v_15274 = ncons(v_15274);
    env = stack[-6];
    stack[-4] = v_15274;
    goto v_15163;
v_15165:
v_15163:
    v_15274 = stack[-3];
    v_15274 = qcdr(v_15274);
    stack[-3] = v_15274;
    goto v_15134;
v_15135:
v_15175:
    v_15274 = stack[-5];
    if (v_15274 == nil) goto v_15178;
    else goto v_15179;
v_15178:
    goto v_15174;
v_15179:
    v_15274 = stack[-5];
    v_15274 = qcar(v_15274);
    v_15274 = qcar(v_15274);
    stack[-4] = v_15274;
    v_15274 = stack[-5];
    v_15274 = qcar(v_15274);
    v_15274 = qcdr(v_15274);
    stack[-3] = v_15274;
    v_15274 = stack[-5];
    v_15274 = qcdr(v_15274);
    stack[-5] = v_15274;
    goto v_15195;
v_15191:
    v_15274 = stack[-4];
    v_15274 = qcar(v_15274);
    v_15274 = qcar(v_15274);
    v_15275 = qcar(v_15274);
    goto v_15192;
v_15193:
    v_15274 = stack[-3];
    v_15274 = qcar(v_15274);
    v_15274 = qcar(v_15274);
    goto v_15194;
v_15195:
    goto v_15191;
v_15192:
    goto v_15193;
v_15194:
    fn = elt(env, 1); // ordexn
    v_15274 = (*qfn2(fn))(fn, v_15275, v_15274);
    env = stack[-6];
    stack[-1] = v_15274;
    v_15274 = stack[-1];
    if (v_15274 == nil) goto v_15206;
    goto v_15213;
v_15209:
    v_15274 = stack[-4];
    v_15274 = qcar(v_15274);
    v_15275 = qcdr(v_15274);
    goto v_15210;
v_15211:
    v_15274 = stack[-3];
    v_15274 = qcar(v_15274);
    v_15274 = qcdr(v_15274);
    goto v_15212;
v_15213:
    goto v_15209;
v_15210:
    goto v_15211;
v_15212:
    fn = elt(env, 2); // c!:subs2multf
    v_15274 = (*qfn2(fn))(fn, v_15275, v_15274);
    env = stack[-6];
    v_15275 = v_15274;
    v_15274 = stack[-1];
    v_15274 = qcar(v_15274);
    if (v_15274 == nil) goto v_15223;
    v_15274 = v_15275;
    fn = elt(env, 3); // negf
    v_15274 = (*qfn1(fn))(fn, v_15274);
    env = stack[-6];
    v_15275 = v_15274;
    goto v_15221;
v_15223:
v_15221:
    goto v_15235;
v_15229:
    v_15274 = stack[-1];
    stack[-2] = qcdr(v_15274);
    goto v_15230;
v_15231:
    stack[-1] = v_15275;
    goto v_15232;
v_15233:
    goto v_15244;
v_15240:
    goto v_15241;
v_15242:
    goto v_15251;
v_15247:
    v_15274 = stack[-4];
    v_15275 = qcdr(v_15274);
    goto v_15248;
v_15249:
    v_15274 = stack[-3];
    goto v_15250;
v_15251:
    goto v_15247;
v_15248:
    goto v_15249;
v_15250:
    v_15274 = CC_extmult(elt(env, 0), v_15275, v_15274);
    env = stack[-6];
    goto v_15243;
v_15244:
    goto v_15240;
v_15241:
    goto v_15242;
v_15243:
    fn = elt(env, 4); // extadd
    v_15274 = (*qfn2(fn))(fn, stack[0], v_15274);
    env = stack[-6];
    goto v_15234;
v_15235:
    goto v_15229;
v_15230:
    goto v_15231;
v_15232:
    goto v_15233;
v_15234:
    v_15274 = acons(stack[-2], stack[-1], v_15274);
    env = stack[-6];
    stack[0] = v_15274;
    goto v_15204;
v_15206:
    goto v_15262;
v_15258:
    goto v_15268;
v_15264:
    v_15274 = stack[-4];
    v_15275 = qcdr(v_15274);
    goto v_15265;
v_15266:
    v_15274 = stack[-3];
    goto v_15267;
v_15268:
    goto v_15264;
v_15265:
    goto v_15266;
v_15267:
    v_15275 = CC_extmult(elt(env, 0), v_15275, v_15274);
    env = stack[-6];
    goto v_15259;
v_15260:
    v_15274 = stack[0];
    goto v_15261;
v_15262:
    goto v_15258;
v_15259:
    goto v_15260;
v_15261:
    fn = elt(env, 4); // extadd
    v_15274 = (*qfn2(fn))(fn, v_15275, v_15274);
    env = stack[-6];
    stack[0] = v_15274;
    goto v_15204;
v_15204:
    goto v_15175;
v_15174:
    v_15274 = stack[0];
    return onevalue(v_15274);
}



// Code for formrlis

static LispObject CC_formrlis(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15266, v_15267, v_15268;
    LispObject fn;
    LispObject v_15127, v_15126, v_15125;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formrlis");
    va_start(aa, nargs);
    v_15125 = va_arg(aa, LispObject);
    v_15126 = va_arg(aa, LispObject);
    v_15127 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15127,v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15125,v_15126,v_15127);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_15266 = v_15127;
    stack[-1] = v_15126;
    stack[-2] = v_15125;
// end of prologue
    goto v_15138;
v_15134:
    v_15266 = stack[-2];
    v_15267 = qcar(v_15266);
    goto v_15135;
v_15136:
    v_15266 = elt(env, 1); // flagop
    goto v_15137;
v_15138:
    goto v_15134;
v_15135:
    goto v_15136;
v_15137:
    v_15266 = Lflagp(nil, v_15267, v_15266);
    env = stack[-4];
    if (v_15266 == nil) goto v_15131;
    else goto v_15132;
v_15131:
    goto v_15147;
v_15143:
    v_15266 = stack[-2];
    stack[-3] = qcar(v_15266);
    goto v_15144;
v_15145:
    goto v_15155;
v_15151:
    stack[0] = elt(env, 2); // list
    goto v_15152;
v_15153:
    goto v_15165;
v_15161:
    v_15266 = stack[-2];
    v_15267 = qcar(v_15266);
    goto v_15162;
v_15163:
    v_15266 = elt(env, 3); // share
    goto v_15164;
v_15165:
    goto v_15161;
v_15162:
    goto v_15163;
v_15164:
    if (v_15267 == v_15266) goto v_15159;
    else goto v_15160;
v_15159:
    stack[-1] = nil;
    v_15266 = stack[-2];
    v_15266 = qcdr(v_15266);
    stack[-2] = v_15266;
v_15177:
    v_15266 = stack[-2];
    if (v_15266 == nil) goto v_15180;
    else goto v_15181;
v_15180:
    goto v_15176;
v_15181:
    goto v_15189;
v_15185:
    v_15266 = stack[-2];
    v_15266 = qcar(v_15266);
    v_15267 = Lmkquote(nil, v_15266);
    env = stack[-4];
    goto v_15186;
v_15187:
    v_15266 = stack[-1];
    goto v_15188;
v_15189:
    goto v_15185;
v_15186:
    goto v_15187;
v_15188:
    v_15266 = cons(v_15267, v_15266);
    env = stack[-4];
    stack[-1] = v_15266;
    v_15266 = stack[-2];
    v_15266 = qcdr(v_15266);
    stack[-2] = v_15266;
    goto v_15177;
v_15176:
    v_15266 = stack[-1];
    fn = elt(env, 8); // reversip!*
    v_15266 = (*qfn1(fn))(fn, v_15266);
    env = stack[-4];
    goto v_15158;
v_15160:
    goto v_15207;
v_15201:
    v_15266 = stack[-2];
    v_15268 = qcdr(v_15266);
    goto v_15202;
v_15203:
    v_15267 = stack[-1];
    goto v_15204;
v_15205:
    v_15266 = elt(env, 4); // algebraic
    goto v_15206;
v_15207:
    goto v_15201;
v_15202:
    goto v_15203;
v_15204:
    goto v_15205;
v_15206:
    fn = elt(env, 9); // formlis
    v_15266 = (*qfnn(fn))(fn, 3, v_15268, v_15267, v_15266);
    env = stack[-4];
    goto v_15158;
    v_15266 = nil;
v_15158:
    goto v_15154;
v_15155:
    goto v_15151;
v_15152:
    goto v_15153;
v_15154:
    v_15266 = cons(stack[0], v_15266);
    goto v_15146;
v_15147:
    goto v_15143;
v_15144:
    goto v_15145;
v_15146:
    {
        LispObject v_15273 = stack[-3];
        return list2(v_15273, v_15266);
    }
v_15132:
    v_15266 = stack[-2];
    v_15266 = qcdr(v_15266);
    fn = elt(env, 10); // idlistp
    v_15266 = (*qfn1(fn))(fn, v_15266);
    env = stack[-4];
    if (v_15266 == nil) goto v_15212;
    else goto v_15213;
v_15212:
    goto v_15222;
v_15218:
    goto v_15228;
v_15224:
    v_15267 = elt(env, 5); // !*comma!*
    goto v_15225;
v_15226:
    v_15266 = stack[-2];
    v_15266 = qcdr(v_15266);
    goto v_15227;
v_15228:
    goto v_15224;
v_15225:
    goto v_15226;
v_15227:
    v_15267 = cons(v_15267, v_15266);
    env = stack[-4];
    goto v_15219;
v_15220:
    v_15266 = elt(env, 6); // "identifier list"
    goto v_15221;
v_15222:
    goto v_15218;
v_15219:
    goto v_15220;
v_15221:
    {
        fn = elt(env, 11); // typerr
        return (*qfn2(fn))(fn, v_15267, v_15266);
    }
v_15213:
    goto v_15242;
v_15236:
    stack[-3] = elt(env, 7); // flag
    goto v_15237;
v_15238:
    goto v_15249;
v_15245:
    stack[0] = elt(env, 2); // list
    goto v_15246;
v_15247:
    goto v_15258;
v_15252:
    v_15266 = stack[-2];
    v_15268 = qcdr(v_15266);
    goto v_15253;
v_15254:
    v_15267 = stack[-1];
    goto v_15255;
v_15256:
    v_15266 = elt(env, 4); // algebraic
    goto v_15257;
v_15258:
    goto v_15252;
v_15253:
    goto v_15254;
v_15255:
    goto v_15256;
v_15257:
    fn = elt(env, 9); // formlis
    v_15266 = (*qfnn(fn))(fn, 3, v_15268, v_15267, v_15266);
    env = stack[-4];
    goto v_15248;
v_15249:
    goto v_15245;
v_15246:
    goto v_15247;
v_15248:
    stack[0] = cons(stack[0], v_15266);
    env = stack[-4];
    goto v_15239;
v_15240:
    v_15266 = stack[-2];
    v_15266 = qcar(v_15266);
    v_15266 = Lmkquote(nil, v_15266);
    goto v_15241;
v_15242:
    goto v_15236;
v_15237:
    goto v_15238;
v_15239:
    goto v_15240;
v_15241:
    {
        LispObject v_15274 = stack[-3];
        LispObject v_15275 = stack[0];
        return list3(v_15274, v_15275, v_15266);
    }
    v_15266 = nil;
    return onevalue(v_15266);
}



// Code for smemberlp

static LispObject CC_smemberlp(LispObject env,
                         LispObject v_15125, LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15168, v_15169;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15125,v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15126;
    stack[-1] = v_15125;
// end of prologue
v_15124:
    v_15168 = stack[0];
    if (v_15168 == nil) goto v_15130;
    else goto v_15131;
v_15130:
    v_15168 = nil;
    goto v_15129;
v_15131:
    v_15168 = stack[0];
    if (!consp(v_15168)) goto v_15134;
    else goto v_15135;
v_15134:
    goto v_15141;
v_15137:
    v_15169 = stack[0];
    goto v_15138;
v_15139:
    v_15168 = stack[-1];
    goto v_15140;
v_15141:
    goto v_15137;
v_15138:
    goto v_15139;
v_15140:
    v_15168 = Lmember(nil, v_15169, v_15168);
    goto v_15129;
v_15135:
    goto v_15155;
v_15151:
    v_15169 = stack[-1];
    goto v_15152;
v_15153:
    v_15168 = stack[0];
    v_15168 = qcar(v_15168);
    goto v_15154;
v_15155:
    goto v_15151;
v_15152:
    goto v_15153;
v_15154:
    v_15168 = CC_smemberlp(elt(env, 0), v_15169, v_15168);
    env = stack[-2];
    if (v_15168 == nil) goto v_15149;
    else goto v_15148;
v_15149:
    goto v_15164;
v_15160:
    v_15169 = stack[-1];
    goto v_15161;
v_15162:
    v_15168 = stack[0];
    v_15168 = qcdr(v_15168);
    goto v_15163;
v_15164:
    goto v_15160;
v_15161:
    goto v_15162;
v_15163:
    stack[-1] = v_15169;
    stack[0] = v_15168;
    goto v_15124;
v_15148:
    goto v_15129;
    v_15168 = nil;
v_15129:
    return onevalue(v_15168);
}



// Code for talp_list2vec

static LispObject CC_talp_list2vec(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15170, v_15171, v_15172;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_15125;
// end of prologue
    v_15170 = stack[-1];
    v_15170 = Llength(nil, v_15170);
    env = stack[-3];
    v_15170 = sub1(v_15170);
    env = stack[-3];
    v_15170 = Lmkvect(nil, v_15170);
    env = stack[-3];
    stack[-2] = v_15170;
    v_15170 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_15170;
v_15137:
    goto v_15149;
v_15145:
    v_15170 = stack[-2];
    v_15171 = Lupbv(nil, v_15170);
    env = stack[-3];
    goto v_15146;
v_15147:
    v_15170 = stack[0];
    goto v_15148;
v_15149:
    goto v_15145;
v_15146:
    goto v_15147;
v_15148:
    v_15170 = difference2(v_15171, v_15170);
    env = stack[-3];
    v_15170 = Lminusp(nil, v_15170);
    env = stack[-3];
    if (v_15170 == nil) goto v_15142;
    goto v_15136;
v_15142:
    goto v_15160;
v_15154:
    v_15172 = stack[-2];
    goto v_15155;
v_15156:
    v_15171 = stack[0];
    goto v_15157;
v_15158:
    v_15170 = stack[-1];
    v_15170 = qcar(v_15170);
    goto v_15159;
v_15160:
    goto v_15154;
v_15155:
    goto v_15156;
v_15157:
    goto v_15158;
v_15159:
    *(LispObject *)((char *)v_15172 + (CELL-TAG_VECTOR) + (((intptr_t)v_15171-TAG_FIXNUM)/(16/CELL))) = v_15170;
    v_15170 = stack[-1];
    v_15170 = qcdr(v_15170);
    stack[-1] = v_15170;
    v_15170 = stack[0];
    v_15170 = add1(v_15170);
    env = stack[-3];
    stack[0] = v_15170;
    goto v_15137;
v_15136:
    v_15170 = stack[-2];
    return onevalue(v_15170);
}



// Code for lambdafun

static LispObject CC_lambdafun(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15132;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
// copy arguments values to proper place
    v_15132 = v_15125;
// end of prologue
    v_15132 = Lreverse(nil, v_15132);
    v_15132 = qcar(v_15132);
    return onevalue(v_15132);
}



// Code for setdmode

static LispObject CC_setdmode(LispObject env,
                         LispObject v_15125, LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15290, v_15291, v_15292;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15125,v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_15126;
    stack[-2] = v_15125;
// end of prologue
    v_15290 = stack[-2];
    if (!symbolp(v_15290)) v_15290 = nil;
    else { v_15290 = qfastgets(v_15290);
           if (v_15290 != nil) { v_15290 = elt(v_15290, 8); // dname
#ifdef RECORD_GET
             if (v_15290 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_15290 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_15290 == SPID_NOPROP) v_15290 = nil; }}
#endif
    stack[0] = v_15290;
    if (v_15290 == nil) goto v_15134;
    v_15290 = stack[0];
    stack[-2] = v_15290;
    goto v_15132;
v_15134:
v_15132:
    goto v_15146;
v_15142:
    v_15291 = stack[-2];
    goto v_15143;
v_15144:
    v_15290 = elt(env, 1); // complex!-rational
    goto v_15145;
v_15146:
    goto v_15142;
v_15143:
    goto v_15144;
v_15145:
    if (v_15291 == v_15290) goto v_15140;
    else goto v_15141;
v_15140:
    v_15290 = qvalue(elt(env, 2)); // dmode!*
    stack[0] = v_15290;
    if (v_15290 == nil) goto v_15152;
    v_15290 = stack[0];
    if (!symbolp(v_15290)) v_15290 = nil;
    else { v_15290 = qfastgets(v_15290);
           if (v_15290 != nil) { v_15290 = elt(v_15290, 8); // dname
#ifdef RECORD_GET
             if (v_15290 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_15290 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_15290 == SPID_NOPROP) v_15290 = nil; }}
#endif
    stack[0] = v_15290;
    goto v_15150;
v_15152:
v_15150:
    goto v_15161;
v_15157:
    v_15291 = elt(env, 3); // complex
    goto v_15158;
v_15159:
    v_15290 = stack[-1];
    goto v_15160;
v_15161:
    goto v_15157;
v_15158:
    goto v_15159;
v_15160:
    fn = elt(env, 13); // onoff
    v_15290 = (*qfn2(fn))(fn, v_15291, v_15290);
    env = stack[-4];
    goto v_15169;
v_15165:
    v_15291 = elt(env, 4); // rational
    goto v_15166;
v_15167:
    v_15290 = stack[-1];
    goto v_15168;
v_15169:
    goto v_15165;
v_15166:
    goto v_15167;
v_15168:
    fn = elt(env, 13); // onoff
    v_15290 = (*qfn2(fn))(fn, v_15291, v_15290);
    v_15290 = stack[0];
    goto v_15130;
v_15141:
    goto v_15179;
v_15175:
    v_15291 = stack[-2];
    goto v_15176;
v_15177:
    v_15290 = elt(env, 5); // complex!-rounded
    goto v_15178;
v_15179:
    goto v_15175;
v_15176:
    goto v_15177;
v_15178:
    if (v_15291 == v_15290) goto v_15173;
    else goto v_15174;
v_15173:
    v_15290 = qvalue(elt(env, 2)); // dmode!*
    stack[0] = v_15290;
    if (v_15290 == nil) goto v_15185;
    v_15290 = stack[0];
    if (!symbolp(v_15290)) v_15290 = nil;
    else { v_15290 = qfastgets(v_15290);
           if (v_15290 != nil) { v_15290 = elt(v_15290, 8); // dname
#ifdef RECORD_GET
             if (v_15290 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_15290 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_15290 == SPID_NOPROP) v_15290 = nil; }}
#endif
    stack[0] = v_15290;
    goto v_15183;
v_15185:
v_15183:
    goto v_15194;
v_15190:
    v_15291 = elt(env, 3); // complex
    goto v_15191;
v_15192:
    v_15290 = stack[-1];
    goto v_15193;
v_15194:
    goto v_15190;
v_15191:
    goto v_15192;
v_15193:
    fn = elt(env, 13); // onoff
    v_15290 = (*qfn2(fn))(fn, v_15291, v_15290);
    env = stack[-4];
    goto v_15202;
v_15198:
    v_15291 = elt(env, 6); // rounded
    goto v_15199;
v_15200:
    v_15290 = stack[-1];
    goto v_15201;
v_15202:
    goto v_15198;
v_15199:
    goto v_15200;
v_15201:
    fn = elt(env, 13); // onoff
    v_15290 = (*qfn2(fn))(fn, v_15291, v_15290);
    v_15290 = stack[0];
    goto v_15130;
v_15174:
    goto v_15215;
v_15211:
    v_15291 = stack[-2];
    goto v_15212;
v_15213:
    v_15290 = elt(env, 7); // tag
    goto v_15214;
v_15215:
    goto v_15211;
v_15212:
    goto v_15213;
v_15214:
    v_15290 = get(v_15291, v_15290);
    env = stack[-4];
    if (v_15290 == nil) goto v_15208;
    else goto v_15209;
v_15208:
    goto v_15225;
v_15219:
    stack[-3] = elt(env, 8); // poly
    goto v_15220;
v_15221:
    stack[0] = (LispObject)80+TAG_FIXNUM; // 5
    goto v_15222;
v_15223:
    goto v_15235;
v_15229:
    v_15292 = elt(env, 9); // "Domain mode error:"
    goto v_15230;
v_15231:
    v_15291 = stack[-2];
    goto v_15232;
v_15233:
    v_15290 = elt(env, 10); // "is not a domain mode"
    goto v_15234;
v_15235:
    goto v_15229;
v_15230:
    goto v_15231;
v_15232:
    goto v_15233;
v_15234:
    v_15290 = list3(v_15292, v_15291, v_15290);
    env = stack[-4];
    goto v_15224;
v_15225:
    goto v_15219;
v_15220:
    goto v_15221;
v_15222:
    goto v_15223;
v_15224:
    fn = elt(env, 14); // rerror
    v_15290 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_15290);
    env = stack[-4];
    goto v_15207;
v_15209:
v_15207:
    goto v_15248;
v_15244:
    v_15291 = stack[-2];
    goto v_15245;
v_15246:
    v_15290 = elt(env, 11); // package!-name
    goto v_15247;
v_15248:
    goto v_15244;
v_15245:
    goto v_15246;
v_15247:
    v_15290 = get(v_15291, v_15290);
    env = stack[-4];
    stack[0] = v_15290;
    if (v_15290 == nil) goto v_15242;
    v_15290 = stack[0];
    fn = elt(env, 15); // load!-package
    v_15290 = (*qfn1(fn))(fn, v_15290);
    env = stack[-4];
    goto v_15240;
v_15242:
v_15240:
    goto v_15265;
v_15261:
    v_15291 = stack[-2];
    goto v_15262;
v_15263:
    v_15290 = elt(env, 3); // complex
    goto v_15264;
v_15265:
    goto v_15261;
v_15262:
    goto v_15263;
v_15264:
    if (v_15291 == v_15290) goto v_15259;
    else goto v_15260;
v_15259:
    v_15290 = lisp_true;
    goto v_15258;
v_15260:
    v_15290 = qvalue(elt(env, 12)); // !*complex
    goto v_15258;
    v_15290 = nil;
v_15258:
    if (v_15290 == nil) goto v_15256;
    goto v_15277;
v_15273:
    v_15291 = stack[-2];
    goto v_15274;
v_15275:
    v_15290 = stack[-1];
    goto v_15276;
v_15277:
    goto v_15273;
v_15274:
    goto v_15275;
v_15276:
    {
        fn = elt(env, 16); // setcmpxmode
        return (*qfn2(fn))(fn, v_15291, v_15290);
    }
v_15256:
    goto v_15287;
v_15283:
    v_15291 = stack[-2];
    goto v_15284;
v_15285:
    v_15290 = stack[-1];
    goto v_15286;
v_15287:
    goto v_15283;
v_15284:
    goto v_15285;
v_15286:
    {
        fn = elt(env, 17); // setdmode1
        return (*qfn2(fn))(fn, v_15291, v_15290);
    }
    v_15290 = nil;
v_15130:
    return onevalue(v_15290);
}



// Code for random

static LispObject CC_random(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15278, v_15279;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_15125;
// end of prologue
    v_15278 = stack[-3];
    if (is_number(v_15278)) goto v_15138;
    v_15278 = lisp_true;
    goto v_15136;
v_15138:
    goto v_15148;
v_15144:
    v_15279 = stack[-3];
    goto v_15145;
v_15146:
    v_15278 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15147;
v_15148:
    goto v_15144;
v_15145:
    goto v_15146;
v_15147:
    v_15278 = (LispObject)lesseq2(v_15279, v_15278);
    v_15278 = v_15278 ? lisp_true : nil;
    env = stack[-5];
    goto v_15136;
    v_15278 = nil;
v_15136:
    if (v_15278 == nil) goto v_15134;
    goto v_15156;
v_15152:
    v_15279 = stack[-3];
    goto v_15153;
v_15154:
    v_15278 = elt(env, 1); // "positive number"
    goto v_15155;
v_15156:
    goto v_15152;
v_15153:
    goto v_15154;
v_15155:
    fn = elt(env, 4); // typerr
    v_15278 = (*qfn2(fn))(fn, v_15279, v_15278);
    env = stack[-5];
    goto v_15132;
v_15134:
v_15132:
    v_15278 = stack[-3];
    v_15278 = Lfloatp(nil, v_15278);
    env = stack[-5];
    if (v_15278 == nil) goto v_15162;
    goto v_15170;
v_15166:
    fn = elt(env, 5); // next!-random!-number
    v_15278 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_15279 = Lfloat(nil, v_15278);
    env = stack[-5];
    goto v_15167;
v_15168:
    v_15278 = qvalue(elt(env, 2)); // unidev_fac!*
    goto v_15169;
v_15170:
    goto v_15166;
v_15167:
    goto v_15168;
v_15169:
    v_15278 = times2(v_15279, v_15278);
    env = stack[-5];
    stack[-2] = v_15278;
    goto v_15179;
v_15175:
    goto v_15185;
v_15181:
    fn = elt(env, 5); // next!-random!-number
    v_15278 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_15279 = Lfloat(nil, v_15278);
    env = stack[-5];
    goto v_15182;
v_15183:
    v_15278 = stack[-2];
    goto v_15184;
v_15185:
    goto v_15181;
v_15182:
    goto v_15183;
v_15184:
    stack[0] = plus2(v_15279, v_15278);
    env = stack[-5];
    goto v_15176;
v_15177:
    goto v_15194;
v_15190:
    v_15279 = qvalue(elt(env, 2)); // unidev_fac!*
    goto v_15191;
v_15192:
    v_15278 = stack[-3];
    goto v_15193;
v_15194:
    goto v_15190;
v_15191:
    goto v_15192;
v_15193:
    v_15278 = times2(v_15279, v_15278);
    goto v_15178;
v_15179:
    goto v_15175;
v_15176:
    goto v_15177;
v_15178:
    {
        LispObject v_15285 = stack[0];
        return times2(v_15285, v_15278);
    }
v_15162:
v_15201:
    fn = elt(env, 5); // next!-random!-number
    v_15278 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[-2] = v_15278;
    v_15278 = qvalue(elt(env, 3)); // randommodulus!*
    stack[-4] = v_15278;
v_15206:
    goto v_15216;
v_15212:
    v_15279 = stack[-4];
    goto v_15213;
v_15214:
    v_15278 = stack[-3];
    goto v_15215;
v_15216:
    goto v_15212;
v_15213:
    goto v_15214;
v_15215:
    v_15278 = (LispObject)lessp2(v_15279, v_15278);
    v_15278 = v_15278 ? lisp_true : nil;
    env = stack[-5];
    if (v_15278 == nil) goto v_15209;
    else goto v_15210;
v_15209:
    goto v_15205;
v_15210:
    goto v_15225;
v_15221:
    v_15279 = stack[-4];
    goto v_15222;
v_15223:
    v_15278 = qvalue(elt(env, 3)); // randommodulus!*
    goto v_15224;
v_15225:
    goto v_15221;
v_15222:
    goto v_15223;
v_15224:
    v_15278 = times2(v_15279, v_15278);
    env = stack[-5];
    stack[-4] = v_15278;
    goto v_15233;
v_15229:
    goto v_15239;
v_15235:
    v_15279 = qvalue(elt(env, 3)); // randommodulus!*
    goto v_15236;
v_15237:
    v_15278 = stack[-2];
    goto v_15238;
v_15239:
    goto v_15235;
v_15236:
    goto v_15237;
v_15238:
    stack[0] = times2(v_15279, v_15278);
    env = stack[-5];
    goto v_15230;
v_15231:
    fn = elt(env, 5); // next!-random!-number
    v_15278 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_15232;
v_15233:
    goto v_15229;
v_15230:
    goto v_15231;
v_15232:
    v_15278 = plus2(stack[0], v_15278);
    env = stack[-5];
    stack[-2] = v_15278;
    goto v_15206;
v_15205:
    goto v_15253;
v_15249:
    stack[-1] = stack[-2];
    goto v_15250;
v_15251:
    goto v_15260;
v_15256:
    stack[0] = stack[-4];
    goto v_15257;
v_15258:
    goto v_15267;
v_15263:
    v_15279 = stack[-4];
    goto v_15264;
v_15265:
    v_15278 = stack[-3];
    goto v_15266;
v_15267:
    goto v_15263;
v_15264:
    goto v_15265;
v_15266:
    v_15278 = Cremainder(v_15279, v_15278);
    env = stack[-5];
    goto v_15259;
v_15260:
    goto v_15256;
v_15257:
    goto v_15258;
v_15259:
    v_15278 = difference2(stack[0], v_15278);
    env = stack[-5];
    goto v_15252;
v_15253:
    goto v_15249;
v_15250:
    goto v_15251;
v_15252:
    v_15278 = (LispObject)lessp2(stack[-1], v_15278);
    v_15278 = v_15278 ? lisp_true : nil;
    env = stack[-5];
    if (v_15278 == nil) goto v_15246;
    else goto v_15247;
v_15246:
    goto v_15201;
v_15247:
    goto v_15275;
v_15271:
    v_15279 = stack[-2];
    goto v_15272;
v_15273:
    v_15278 = stack[-3];
    goto v_15274;
v_15275:
    goto v_15271;
v_15272:
    goto v_15273;
v_15274:
    return Cremainder(v_15279, v_15278);
    v_15278 = nil;
    return onevalue(v_15278);
}



// Code for assert_install1

static LispObject CC_assert_install1(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15211, v_15212, v_15213;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15125;
// end of prologue
    goto v_15136;
v_15132:
    v_15212 = stack[0];
    goto v_15133;
v_15134:
    v_15211 = elt(env, 1); // assert_installed
    goto v_15135;
v_15136:
    goto v_15132;
v_15133:
    goto v_15134;
v_15135:
    v_15211 = get(v_15212, v_15211);
    env = stack[-1];
    if (v_15211 == nil) goto v_15130;
    goto v_15145;
v_15141:
    v_15212 = elt(env, 2); // "assert already installed for"
    goto v_15142;
v_15143:
    v_15211 = stack[0];
    goto v_15144;
v_15145:
    goto v_15141;
v_15142:
    goto v_15143;
v_15144:
    v_15211 = list2(v_15212, v_15211);
    env = stack[-1];
    {
        fn = elt(env, 7); // lprim
        return (*qfn1(fn))(fn, v_15211);
    }
v_15130:
    goto v_15155;
v_15151:
    v_15211 = stack[0];
    fn = elt(env, 8); // getd
    v_15212 = (*qfn1(fn))(fn, v_15211);
    env = stack[-1];
    goto v_15152;
v_15153:
    v_15211 = elt(env, 3); // expr
    goto v_15154;
v_15155:
    goto v_15151;
v_15152:
    goto v_15153;
v_15154:
    if (!consp(v_15212)) goto v_15148;
    v_15212 = qcar(v_15212);
    if (v_15212 == v_15211) goto v_15149;
v_15148:
    goto v_15165;
v_15161:
    v_15212 = stack[0];
    goto v_15162;
v_15163:
    v_15211 = elt(env, 4); // "is not an expr procedure - ignoring assert"
    goto v_15164;
v_15165:
    goto v_15161;
v_15162:
    goto v_15163;
v_15164:
    v_15211 = list2(v_15212, v_15211);
    env = stack[-1];
    {
        fn = elt(env, 7); // lprim
        return (*qfn1(fn))(fn, v_15211);
    }
v_15149:
    goto v_15175;
v_15171:
    goto v_15181;
v_15177:
    v_15212 = stack[0];
    goto v_15178;
v_15179:
    v_15211 = elt(env, 5); // assert_noassertfn
    goto v_15180;
v_15181:
    goto v_15177;
v_15178:
    goto v_15179;
v_15180:
    v_15212 = get(v_15212, v_15211);
    env = stack[-1];
    goto v_15172;
v_15173:
    v_15211 = stack[0];
    goto v_15174;
v_15175:
    goto v_15171;
v_15172:
    goto v_15173;
v_15174:
    fn = elt(env, 9); // copyd
    v_15211 = (*qfn2(fn))(fn, v_15212, v_15211);
    env = stack[-1];
    goto v_15190;
v_15186:
    v_15213 = stack[0];
    goto v_15187;
v_15188:
    goto v_15197;
v_15193:
    v_15212 = stack[0];
    goto v_15194;
v_15195:
    v_15211 = elt(env, 6); // assert_assertfn
    goto v_15196;
v_15197:
    goto v_15193;
v_15194:
    goto v_15195;
v_15196:
    v_15211 = get(v_15212, v_15211);
    env = stack[-1];
    goto v_15189;
v_15190:
    goto v_15186;
v_15187:
    goto v_15188;
v_15189:
    fn = elt(env, 9); // copyd
    v_15211 = (*qfn2(fn))(fn, v_15213, v_15211);
    env = stack[-1];
    goto v_15207;
v_15201:
    v_15212 = stack[0];
    goto v_15202;
v_15203:
    v_15213 = elt(env, 1); // assert_installed
    goto v_15204;
v_15205:
    v_15211 = lisp_true;
    goto v_15206;
v_15207:
    goto v_15201;
v_15202:
    goto v_15203;
v_15204:
    goto v_15205;
v_15206:
        return Lputprop(nil, 3, v_15212, v_15213, v_15211);
    v_15211 = nil;
    return onevalue(v_15211);
}



// Code for red!=hidelt

static LispObject CC_redMhidelt(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15154;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_15125;
// end of prologue
    v_15154 = stack[-2];
    fn = elt(env, 1); // bas_dpoly
    v_15154 = (*qfn1(fn))(fn, v_15154);
    env = stack[-4];
    stack[-3] = v_15154;
    goto v_15137;
v_15131:
    v_15154 = stack[-2];
    fn = elt(env, 2); // bas_nr
    stack[-1] = (*qfn1(fn))(fn, v_15154);
    env = stack[-4];
    goto v_15132;
v_15133:
    v_15154 = stack[-3];
    stack[0] = qcdr(v_15154);
    goto v_15134;
v_15135:
    goto v_15147;
v_15143:
    v_15154 = stack[-2];
    fn = elt(env, 3); // bas_rep
    stack[-2] = (*qfn1(fn))(fn, v_15154);
    env = stack[-4];
    goto v_15144;
v_15145:
    v_15154 = stack[-3];
    v_15154 = qcar(v_15154);
    v_15154 = ncons(v_15154);
    env = stack[-4];
    fn = elt(env, 4); // red!=hide
    v_15154 = (*qfn1(fn))(fn, v_15154);
    env = stack[-4];
    goto v_15146;
v_15147:
    goto v_15143;
v_15144:
    goto v_15145;
v_15146:
    fn = elt(env, 5); // dp_sum
    v_15154 = (*qfn2(fn))(fn, stack[-2], v_15154);
    env = stack[-4];
    goto v_15136;
v_15137:
    goto v_15131;
v_15132:
    goto v_15133;
v_15134:
    goto v_15135;
v_15136:
    {
        LispObject v_15159 = stack[-1];
        LispObject v_15160 = stack[0];
        fn = elt(env, 6); // bas_make1
        return (*qfnn(fn))(fn, 3, v_15159, v_15160, v_15154);
    }
}



// Code for repeats

static LispObject CC_repeats(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15165, v_15166, v_15167;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15125;
// end of prologue
    v_15167 = nil;
v_15130:
    v_15165 = stack[0];
    if (v_15165 == nil) goto v_15133;
    else goto v_15134;
v_15133:
    v_15165 = v_15167;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_15165);
    }
v_15134:
    goto v_15144;
v_15140:
    v_15165 = stack[0];
    v_15166 = qcar(v_15165);
    goto v_15141;
v_15142:
    v_15165 = stack[0];
    v_15165 = qcdr(v_15165);
    goto v_15143;
v_15144:
    goto v_15140;
v_15141:
    goto v_15142;
v_15143:
    v_15165 = Lmember(nil, v_15166, v_15165);
    if (v_15165 == nil) goto v_15139;
    goto v_15155;
v_15151:
    v_15165 = stack[0];
    v_15165 = qcar(v_15165);
    goto v_15152;
v_15153:
    v_15166 = v_15167;
    goto v_15154;
v_15155:
    goto v_15151;
v_15152:
    goto v_15153;
v_15154:
    v_15165 = cons(v_15165, v_15166);
    env = stack[-1];
    v_15167 = v_15165;
    v_15165 = stack[0];
    v_15165 = qcdr(v_15165);
    stack[0] = v_15165;
    goto v_15130;
v_15139:
    v_15165 = stack[0];
    v_15165 = qcdr(v_15165);
    stack[0] = v_15165;
    goto v_15130;
    v_15165 = nil;
    return onevalue(v_15165);
}



// Code for gf2cr!:

static LispObject CC_gf2crT(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15142;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_15125;
// end of prologue
    goto v_15134;
v_15128:
    stack[-2] = elt(env, 1); // !:cr!:
    goto v_15129;
v_15130:
    v_15142 = stack[-1];
    v_15142 = qcar(v_15142);
    fn = elt(env, 2); // striptag
    stack[0] = (*qfn1(fn))(fn, v_15142);
    env = stack[-3];
    goto v_15131;
v_15132:
    v_15142 = stack[-1];
    v_15142 = qcdr(v_15142);
    fn = elt(env, 2); // striptag
    v_15142 = (*qfn1(fn))(fn, v_15142);
    goto v_15133;
v_15134:
    goto v_15128;
v_15129:
    goto v_15130;
v_15131:
    goto v_15132;
v_15133:
    {
        LispObject v_15146 = stack[-2];
        LispObject v_15147 = stack[0];
        return list2star(v_15146, v_15147, v_15142);
    }
}



// Code for lalr_make_compressed_goto_column

static LispObject CC_lalr_make_compressed_goto_column(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15247, v_15248, v_15249;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_15247 = v_15125;
// end of prologue
    stack[-4] = nil;
    goto v_15143;
v_15139:
    v_15248 = v_15247;
    goto v_15140;
v_15141:
    v_15247 = qvalue(elt(env, 1)); // goto_table
    goto v_15142;
v_15143:
    goto v_15139;
v_15140:
    goto v_15141;
v_15142:
    fn = elt(env, 2); // gethash
    v_15247 = (*qfn2(fn))(fn, v_15248, v_15247);
    env = stack[-5];
    stack[-3] = v_15247;
    v_15247 = stack[-3];
    if (v_15247 == nil) goto v_15148;
    else goto v_15149;
v_15148:
    v_15247 = nil;
    goto v_15136;
v_15149:
    v_15247 = stack[-3];
    v_15247 = qcar(v_15247);
    goto v_15161;
v_15157:
    v_15248 = v_15247;
    v_15248 = qcar(v_15248);
    v_15248 = qcdr(v_15248);
    goto v_15158;
v_15159:
    v_15247 = qcdr(v_15247);
    v_15247 = qcdr(v_15247);
    goto v_15160;
v_15161:
    goto v_15157;
v_15158:
    goto v_15159;
v_15160:
    v_15247 = cons(v_15248, v_15247);
    env = stack[-5];
    v_15247 = ncons(v_15247);
    env = stack[-5];
    stack[-1] = v_15247;
    stack[-2] = v_15247;
v_15137:
    v_15247 = stack[-3];
    v_15247 = qcdr(v_15247);
    stack[-3] = v_15247;
    v_15247 = stack[-3];
    if (v_15247 == nil) goto v_15172;
    else goto v_15173;
v_15172:
    v_15247 = stack[-2];
    goto v_15136;
v_15173:
    goto v_15181;
v_15177:
    stack[0] = stack[-1];
    goto v_15178;
v_15179:
    v_15247 = stack[-3];
    v_15247 = qcar(v_15247);
    goto v_15192;
v_15188:
    v_15248 = v_15247;
    v_15248 = qcar(v_15248);
    v_15248 = qcdr(v_15248);
    goto v_15189;
v_15190:
    v_15247 = qcdr(v_15247);
    v_15247 = qcdr(v_15247);
    goto v_15191;
v_15192:
    goto v_15188;
v_15189:
    goto v_15190;
v_15191:
    v_15247 = cons(v_15248, v_15247);
    env = stack[-5];
    v_15247 = ncons(v_15247);
    env = stack[-5];
    goto v_15180;
v_15181:
    goto v_15177;
v_15178:
    goto v_15179;
v_15180:
    v_15247 = Lrplacd(nil, stack[0], v_15247);
    env = stack[-5];
    v_15247 = stack[-1];
    v_15247 = qcdr(v_15247);
    stack[-1] = v_15247;
    goto v_15137;
v_15136:
    stack[0] = v_15247;
    v_15247 = stack[0];
    fn = elt(env, 3); // lalr_most_common_dest
    v_15247 = (*qfn1(fn))(fn, v_15247);
    env = stack[-5];
    stack[-1] = v_15247;
    v_15247 = stack[0];
    stack[0] = v_15247;
v_15206:
    v_15247 = stack[0];
    if (v_15247 == nil) goto v_15210;
    else goto v_15211;
v_15210:
    goto v_15205;
v_15211:
    v_15247 = stack[0];
    v_15247 = qcar(v_15247);
    v_15249 = v_15247;
    goto v_15225;
v_15221:
    v_15247 = v_15249;
    v_15248 = qcdr(v_15247);
    goto v_15222;
v_15223:
    v_15247 = stack[-1];
    goto v_15224;
v_15225:
    goto v_15221;
v_15222:
    goto v_15223;
v_15224:
    if (equal(v_15248, v_15247)) goto v_15220;
    goto v_15234;
v_15230:
    v_15248 = v_15249;
    goto v_15231;
v_15232:
    v_15247 = stack[-4];
    goto v_15233;
v_15234:
    goto v_15230;
v_15231:
    goto v_15232;
v_15233:
    v_15247 = cons(v_15248, v_15247);
    env = stack[-5];
    stack[-4] = v_15247;
    goto v_15218;
v_15220:
v_15218:
    v_15247 = stack[0];
    v_15247 = qcdr(v_15247);
    stack[0] = v_15247;
    goto v_15206;
v_15205:
    goto v_15244;
v_15240:
    v_15248 = stack[-4];
    goto v_15241;
v_15242:
    v_15247 = stack[-1];
    goto v_15243;
v_15244:
    goto v_15240;
v_15241:
    goto v_15242;
v_15243:
    return cons(v_15248, v_15247);
    return onevalue(v_15247);
}



// Code for comm1

static LispObject CC_comm1(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15211, v_15212;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15125;
// end of prologue
    stack[-1] = nil;
    goto v_15138;
v_15134:
    v_15212 = stack[0];
    goto v_15135;
v_15136:
    v_15211 = elt(env, 1); // end
    goto v_15137;
v_15138:
    goto v_15134;
v_15135:
    goto v_15136;
v_15137:
    if (v_15212 == v_15211) goto v_15132;
    else goto v_15133;
v_15132:
    fn = elt(env, 6); // scan
    v_15211 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_15131;
v_15133:
v_15131:
v_15144:
    goto v_15157;
v_15153:
    v_15212 = qvalue(elt(env, 2)); // cursym!*
    goto v_15154;
v_15155:
    v_15211 = elt(env, 3); // !*semicol!*
    goto v_15156;
v_15157:
    goto v_15153;
v_15154:
    goto v_15155;
v_15156:
    if (v_15212 == v_15211) goto v_15151;
    else goto v_15152;
v_15151:
    v_15211 = lisp_true;
    goto v_15150;
v_15152:
    goto v_15171;
v_15167:
    v_15212 = stack[0];
    goto v_15168;
v_15169:
    v_15211 = elt(env, 1); // end
    goto v_15170;
v_15171:
    goto v_15167;
v_15168:
    goto v_15169;
v_15170:
    if (v_15212 == v_15211) goto v_15165;
    else goto v_15166;
v_15165:
    goto v_15178;
v_15174:
    v_15212 = qvalue(elt(env, 2)); // cursym!*
    goto v_15175;
v_15176:
    v_15211 = elt(env, 4); // (end else then until !*rpar!* !*rsqbkt!*)
    goto v_15177;
v_15178:
    goto v_15174;
v_15175:
    goto v_15176;
v_15177:
    v_15211 = Lmemq(nil, v_15212, v_15211);
    goto v_15164;
v_15166:
    v_15211 = nil;
    goto v_15164;
    v_15211 = nil;
v_15164:
    goto v_15150;
    v_15211 = nil;
v_15150:
    if (v_15211 == nil) goto v_15148;
    goto v_15143;
v_15148:
    goto v_15198;
v_15194:
    v_15212 = stack[0];
    goto v_15195;
v_15196:
    v_15211 = elt(env, 1); // end
    goto v_15197;
v_15198:
    goto v_15194;
v_15195:
    goto v_15196;
v_15197:
    if (v_15212 == v_15211) goto v_15192;
    else goto v_15193;
v_15192:
    v_15211 = stack[-1];
    v_15211 = (v_15211 == nil ? lisp_true : nil);
    goto v_15191;
v_15193:
    v_15211 = nil;
    goto v_15191;
    v_15211 = nil;
v_15191:
    if (v_15211 == nil) goto v_15189;
    v_15211 = elt(env, 5); // "END-COMMENT NO LONGER SUPPORTED"
    v_15211 = ncons(v_15211);
    env = stack[-2];
    fn = elt(env, 7); // lprim
    v_15211 = (*qfn1(fn))(fn, v_15211);
    env = stack[-2];
    v_15211 = lisp_true;
    stack[-1] = v_15211;
    goto v_15187;
v_15189:
v_15187:
    fn = elt(env, 6); // scan
    v_15211 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_15144;
v_15143:
    v_15211 = nil;
    return onevalue(v_15211);
}



// Code for simpcv

static LispObject CC_simpcv(LispObject env,
                         LispObject v_15125, LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15201, v_15202;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15125,v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15126;
    stack[-1] = v_15125;
// end of prologue
    goto v_15136;
v_15132:
    v_15201 = stack[-1];
    v_15202 = Llength(nil, v_15201);
    env = stack[-2];
    goto v_15133;
v_15134:
    v_15201 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_15135;
v_15136:
    goto v_15132;
v_15133:
    goto v_15134;
v_15135:
    if (v_15202 == v_15201) goto v_15131;
    goto v_15146;
v_15142:
    v_15202 = elt(env, 1); // "Invalid number of edges in vertex"
    goto v_15143;
v_15144:
    v_15201 = stack[-1];
    goto v_15145;
v_15146:
    goto v_15142;
v_15143:
    goto v_15144;
v_15145:
    v_15201 = list2(v_15202, v_15201);
    env = stack[-2];
    {
        fn = elt(env, 4); // cerror
        return (*qfn1(fn))(fn, v_15201);
    }
v_15131:
    goto v_15159;
v_15155:
    v_15202 = elt(env, 2); // simpcgraph
    goto v_15156;
v_15157:
    v_15201 = qvalue(elt(env, 3)); // mul!*
    goto v_15158;
v_15159:
    goto v_15155;
v_15156:
    goto v_15157;
v_15158:
    v_15201 = Lmemq(nil, v_15202, v_15201);
    if (v_15201 == nil) goto v_15153;
    else goto v_15154;
v_15153:
    goto v_15168;
v_15164:
    v_15202 = qvalue(elt(env, 3)); // mul!*
    goto v_15165;
v_15166:
    v_15201 = elt(env, 2); // simpcgraph
    goto v_15167;
v_15168:
    goto v_15164;
v_15165:
    goto v_15166;
v_15167:
    fn = elt(env, 5); // aconc!*
    v_15201 = (*qfn2(fn))(fn, v_15202, v_15201);
    env = stack[-2];
    qvalue(elt(env, 3)) = v_15201; // mul!*
    goto v_15152;
v_15154:
v_15152:
    goto v_15176;
v_15172:
    goto v_15183;
v_15179:
    goto v_15189;
v_15185:
    goto v_15195;
v_15191:
    v_15202 = stack[0];
    goto v_15192;
v_15193:
    v_15201 = stack[-1];
    goto v_15194;
v_15195:
    goto v_15191;
v_15192:
    goto v_15193;
v_15194:
    v_15202 = cons(v_15202, v_15201);
    env = stack[-2];
    goto v_15186;
v_15187:
    v_15201 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15188;
v_15189:
    goto v_15185;
v_15186:
    goto v_15187;
v_15188:
    fn = elt(env, 6); // to
    v_15202 = (*qfn2(fn))(fn, v_15202, v_15201);
    env = stack[-2];
    goto v_15180;
v_15181:
    v_15201 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15182;
v_15183:
    goto v_15179;
v_15180:
    goto v_15181;
v_15182:
    v_15201 = cons(v_15202, v_15201);
    env = stack[-2];
    v_15202 = ncons(v_15201);
    goto v_15173;
v_15174:
    v_15201 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15175;
v_15176:
    goto v_15172;
v_15173:
    goto v_15174;
v_15175:
    return cons(v_15202, v_15201);
    v_15201 = nil;
    return onevalue(v_15201);
}



// Code for matrixrowom

static LispObject CC_matrixrowom(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15151;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15125;
// end of prologue
    v_15151 = stack[0];
    if (v_15151 == nil) goto v_15132;
    v_15151 = elt(env, 1); // "<OMA>"
    fn = elt(env, 4); // printout
    v_15151 = (*qfn1(fn))(fn, v_15151);
    env = stack[-1];
    v_15151 = lisp_true;
    fn = elt(env, 5); // indent!*
    v_15151 = (*qfn1(fn))(fn, v_15151);
    env = stack[-1];
    v_15151 = elt(env, 2); // "<OMS cd=""linalg1"" name=""matrixrow""/>"
    fn = elt(env, 4); // printout
    v_15151 = (*qfn1(fn))(fn, v_15151);
    env = stack[-1];
    v_15151 = stack[0];
    v_15151 = qcar(v_15151);
    fn = elt(env, 6); // multiom
    v_15151 = (*qfn1(fn))(fn, v_15151);
    env = stack[-1];
    v_15151 = nil;
    fn = elt(env, 5); // indent!*
    v_15151 = (*qfn1(fn))(fn, v_15151);
    env = stack[-1];
    v_15151 = elt(env, 3); // "</OMA>"
    fn = elt(env, 4); // printout
    v_15151 = (*qfn1(fn))(fn, v_15151);
    env = stack[-1];
    v_15151 = stack[0];
    v_15151 = qcdr(v_15151);
    v_15151 = CC_matrixrowom(elt(env, 0), v_15151);
    goto v_15130;
v_15132:
v_15130:
    v_15151 = nil;
    return onevalue(v_15151);
}



// Code for ft!:zerop

static LispObject CC_ftTzerop(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15168, v_15169;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_15168 = v_15125;
// end of prologue
    goto v_15135;
v_15131:
    stack[0] = v_15168;
    goto v_15132;
v_15133:
    goto v_15142;
v_15138:
    v_15169 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_15139;
v_15140:
    v_15168 = qvalue(elt(env, 1)); // !:prec!:
    goto v_15141;
v_15142:
    goto v_15138;
v_15139:
    goto v_15140;
v_15141:
    v_15168 = Lexpt(nil, v_15169, v_15168);
    env = stack[-1];
    goto v_15134;
v_15135:
    goto v_15131;
v_15132:
    goto v_15133;
v_15134:
    v_15168 = times2(stack[0], v_15168);
    env = stack[-1];
    stack[0] = v_15168;
    goto v_15154;
v_15150:
    v_15169 = stack[0];
    goto v_15151;
v_15152:
    v_15168 = (LispObject)-800+TAG_FIXNUM; // -50
    goto v_15153;
v_15154:
    goto v_15150;
v_15151:
    goto v_15152;
v_15153:
    v_15168 = (LispObject)greaterp2(v_15169, v_15168);
    v_15168 = v_15168 ? lisp_true : nil;
    if (v_15168 == nil) goto v_15147;
    else goto v_15148;
v_15147:
    v_15168 = nil;
    goto v_15146;
v_15148:
    goto v_15165;
v_15161:
    v_15169 = stack[0];
    goto v_15162;
v_15163:
    v_15168 = (LispObject)800+TAG_FIXNUM; // 50
    goto v_15164;
v_15165:
    goto v_15161;
v_15162:
    goto v_15163;
v_15164:
        return Llessp(nil, v_15169, v_15168);
    v_15168 = nil;
v_15146:
    return onevalue(v_15168);
}



// Code for vdpequal

static LispObject CC_vdpequal(LispObject env,
                         LispObject v_15125, LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15195, v_15196, v_15197;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15125,v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15126;
    stack[-1] = v_15125;
// end of prologue
    goto v_15136;
v_15132:
    v_15196 = stack[-1];
    goto v_15133;
v_15134:
    v_15195 = stack[0];
    goto v_15135;
v_15136:
    goto v_15132;
v_15133:
    goto v_15134;
v_15135:
    if (v_15196 == v_15195) goto v_15130;
    else goto v_15131;
v_15130:
    v_15195 = lisp_true;
    goto v_15129;
v_15131:
    goto v_15147;
v_15143:
    v_15196 = stack[-1];
    goto v_15144;
v_15145:
    v_15195 = elt(env, 1); // number
    goto v_15146;
v_15147:
    goto v_15143;
v_15144:
    goto v_15145;
v_15146:
    fn = elt(env, 2); // vdpgetprop
    stack[-2] = (*qfn2(fn))(fn, v_15196, v_15195);
    env = stack[-3];
    goto v_15155;
v_15151:
    v_15196 = stack[0];
    goto v_15152;
v_15153:
    v_15195 = elt(env, 1); // number
    goto v_15154;
v_15155:
    goto v_15151;
v_15152:
    goto v_15153;
v_15154:
    fn = elt(env, 2); // vdpgetprop
    v_15195 = (*qfn2(fn))(fn, v_15196, v_15195);
    env = stack[-3];
    v_15197 = stack[-2];
    v_15196 = v_15195;
    v_15195 = v_15197;
    if (v_15195 == nil) goto v_15165;
    else goto v_15166;
v_15165:
    v_15195 = nil;
    goto v_15164;
v_15166:
    goto v_15175;
v_15171:
    v_15195 = v_15197;
    goto v_15172;
v_15173:
    goto v_15174;
v_15175:
    goto v_15171;
v_15172:
    goto v_15173;
v_15174:
    v_15195 = (equal(v_15195, v_15196) ? lisp_true : nil);
    goto v_15164;
    v_15195 = nil;
v_15164:
    if (v_15195 == nil) goto v_15162;
    else goto v_15161;
v_15162:
    goto v_15184;
v_15180:
    v_15195 = stack[-1];
    v_15195 = qcdr(v_15195);
    v_15195 = qcdr(v_15195);
    v_15195 = qcdr(v_15195);
    v_15196 = qcar(v_15195);
    goto v_15181;
v_15182:
    v_15195 = stack[0];
    v_15195 = qcdr(v_15195);
    v_15195 = qcdr(v_15195);
    v_15195 = qcdr(v_15195);
    v_15195 = qcar(v_15195);
    goto v_15183;
v_15184:
    goto v_15180;
v_15181:
    goto v_15182;
v_15183:
    {
        fn = elt(env, 3); // dipequal
        return (*qfn2(fn))(fn, v_15196, v_15195);
    }
v_15161:
    goto v_15129;
    v_15195 = nil;
v_15129:
    return onevalue(v_15195);
}



// Code for freeoff

static LispObject CC_freeoff(LispObject env,
                         LispObject v_15125, LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15230, v_15231;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15125,v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15126;
    stack[-1] = v_15125;
// end of prologue
v_15130:
    v_15230 = stack[-1];
    if (!consp(v_15230)) goto v_15137;
    else goto v_15138;
v_15137:
    v_15230 = lisp_true;
    goto v_15136;
v_15138:
    v_15230 = stack[-1];
    v_15230 = qcar(v_15230);
    v_15230 = (consp(v_15230) ? nil : lisp_true);
    goto v_15136;
    v_15230 = nil;
v_15136:
    if (v_15230 == nil) goto v_15134;
    v_15230 = lisp_true;
    goto v_15129;
v_15134:
    v_15230 = stack[-1];
    v_15230 = qcar(v_15230);
    v_15230 = qcar(v_15230);
    v_15230 = qcar(v_15230);
    fn = elt(env, 1); // sfp
    v_15230 = (*qfn1(fn))(fn, v_15230);
    env = stack[-2];
    if (v_15230 == nil) goto v_15148;
    goto v_15163;
v_15159:
    v_15230 = stack[-1];
    v_15230 = qcar(v_15230);
    v_15230 = qcar(v_15230);
    v_15231 = qcar(v_15230);
    goto v_15160;
v_15161:
    v_15230 = stack[0];
    goto v_15162;
v_15163:
    goto v_15159;
v_15160:
    goto v_15161;
v_15162:
    v_15230 = CC_freeoff(elt(env, 0), v_15231, v_15230);
    env = stack[-2];
    if (v_15230 == nil) goto v_15157;
    goto v_15178;
v_15174:
    v_15230 = stack[-1];
    v_15230 = qcar(v_15230);
    v_15231 = qcdr(v_15230);
    goto v_15175;
v_15176:
    v_15230 = stack[0];
    goto v_15177;
v_15178:
    goto v_15174;
v_15175:
    goto v_15176;
v_15177:
    v_15230 = CC_freeoff(elt(env, 0), v_15231, v_15230);
    env = stack[-2];
    if (v_15230 == nil) goto v_15172;
    v_15230 = stack[-1];
    v_15230 = qcdr(v_15230);
    stack[-1] = v_15230;
    goto v_15130;
v_15172:
    v_15230 = nil;
    goto v_15129;
    goto v_15155;
v_15157:
    v_15230 = nil;
    goto v_15129;
v_15155:
    goto v_15132;
v_15148:
    goto v_15202;
v_15198:
    v_15230 = stack[-1];
    v_15230 = qcar(v_15230);
    v_15230 = qcar(v_15230);
    v_15231 = qcar(v_15230);
    goto v_15199;
v_15200:
    v_15230 = stack[0];
    goto v_15201;
v_15202:
    goto v_15198;
v_15199:
    goto v_15200;
v_15201:
    fn = elt(env, 2); // ndepends
    v_15230 = (*qfn2(fn))(fn, v_15231, v_15230);
    env = stack[-2];
    if (v_15230 == nil) goto v_15195;
    else goto v_15196;
v_15195:
    goto v_15217;
v_15213:
    v_15230 = stack[-1];
    v_15230 = qcar(v_15230);
    v_15231 = qcdr(v_15230);
    goto v_15214;
v_15215:
    v_15230 = stack[0];
    goto v_15216;
v_15217:
    goto v_15213;
v_15214:
    goto v_15215;
v_15216:
    v_15230 = CC_freeoff(elt(env, 0), v_15231, v_15230);
    env = stack[-2];
    if (v_15230 == nil) goto v_15211;
    v_15230 = stack[-1];
    v_15230 = qcdr(v_15230);
    stack[-1] = v_15230;
    goto v_15130;
v_15211:
    v_15230 = nil;
    goto v_15129;
    goto v_15194;
v_15196:
    v_15230 = nil;
    goto v_15129;
v_15194:
    goto v_15132;
v_15132:
    v_15230 = nil;
v_15129:
    return onevalue(v_15230);
}



// Code for oprinla

static LispObject CC_oprinla(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15168, v_15169, v_15170;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15169 = v_15125;
// end of prologue
    goto v_15139;
v_15135:
    v_15170 = v_15169;
    goto v_15136;
v_15137:
    v_15168 = elt(env, 1); // lapr
    goto v_15138;
v_15139:
    goto v_15135;
v_15136:
    goto v_15137;
v_15138:
    v_15168 = get(v_15170, v_15168);
    env = stack[0];
    v_15170 = v_15168;
    if (v_15168 == nil) goto v_15133;
    v_15168 = v_15170;
    fn = elt(env, 4); // prin2la
    v_15168 = (*qfn1(fn))(fn, v_15168);
    goto v_15131;
v_15133:
    v_15168 = v_15169;
    if (!symbolp(v_15168)) v_15168 = nil;
    else { v_15168 = qfastgets(v_15168);
           if (v_15168 != nil) { v_15168 = elt(v_15168, 37); // prtch
#ifdef RECORD_GET
             if (v_15168 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v_15168 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v_15168 == SPID_NOPROP) v_15168 = nil; }}
#endif
    v_15170 = v_15168;
    if (v_15168 == nil) goto v_15145;
    v_15168 = v_15170;
    fn = elt(env, 4); // prin2la
    v_15168 = (*qfn1(fn))(fn, v_15168);
    goto v_15131;
v_15145:
    goto v_15157;
v_15153:
    v_15170 = v_15169;
    goto v_15154;
v_15155:
    v_15168 = elt(env, 2); // lapop
    goto v_15156;
v_15157:
    goto v_15153;
v_15154:
    goto v_15155;
v_15156:
    v_15168 = get(v_15170, v_15168);
    env = stack[0];
    v_15170 = v_15168;
    if (v_15168 == nil) goto v_15151;
    v_15168 = v_15170;
    fn = elt(env, 4); // prin2la
    v_15168 = (*qfn1(fn))(fn, v_15168);
    env = stack[0];
    v_15168 = elt(env, 3); // ! 
    fn = elt(env, 4); // prin2la
    v_15168 = (*qfn1(fn))(fn, v_15168);
    goto v_15131;
v_15151:
    v_15168 = v_15169;
    fn = elt(env, 5); // prinlatom
    v_15168 = (*qfn1(fn))(fn, v_15168);
    goto v_15131;
v_15131:
    v_15168 = nil;
    return onevalue(v_15168);
}



// Code for physopordchk!*

static LispObject CC_physopordchkH(LispObject env,
                         LispObject v_15125, LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15273, v_15274;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15125,v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_15126;
    stack[-1] = v_15125;
// end of prologue
v_15124:
    v_15273 = stack[-1];
    v_15273 = qcar(v_15273);
    stack[-4] = v_15273;
    v_15273 = stack[-1];
    v_15273 = qcdr(v_15273);
    stack[-1] = v_15273;
    v_15273 = stack[-1];
    if (v_15273 == nil) goto v_15139;
    else goto v_15140;
v_15139:
    v_15273 = stack[0];
    v_15273 = qcdr(v_15273);
    if (v_15273 == nil) goto v_15144;
    else goto v_15145;
v_15144:
    goto v_15157;
v_15153:
    v_15274 = stack[-4];
    goto v_15154;
v_15155:
    v_15273 = stack[0];
    v_15273 = qcar(v_15273);
    goto v_15156;
v_15157:
    goto v_15153;
v_15154:
    goto v_15155;
v_15156:
    fn = elt(env, 1); // ncmpchk
    v_15273 = (*qfn2(fn))(fn, v_15274, v_15273);
    env = stack[-5];
    if (v_15273 == nil) goto v_15150;
    else goto v_15151;
v_15150:
    v_15273 = nil;
    goto v_15149;
v_15151:
    goto v_15168;
v_15164:
    v_15273 = stack[-4];
    fn = elt(env, 2); // invp
    v_15274 = (*qfn1(fn))(fn, v_15273);
    goto v_15165;
v_15166:
    v_15273 = stack[0];
    v_15273 = qcar(v_15273);
    goto v_15167;
v_15168:
    goto v_15164;
v_15165:
    goto v_15166;
v_15167:
    v_15273 = (equal(v_15274, v_15273) ? lisp_true : nil);
    v_15273 = (v_15273 == nil ? lisp_true : nil);
    goto v_15149;
    v_15273 = nil;
v_15149:
    goto v_15132;
v_15145:
    v_15273 = stack[0];
    stack[-3] = v_15273;
    v_15273 = stack[-3];
    if (v_15273 == nil) goto v_15186;
    else goto v_15187;
v_15186:
    v_15273 = nil;
    goto v_15181;
v_15187:
    v_15273 = stack[-3];
    v_15273 = qcar(v_15273);
    goto v_15199;
v_15195:
    v_15274 = stack[-4];
    goto v_15196;
v_15197:
    goto v_15198;
v_15199:
    goto v_15195;
v_15196:
    goto v_15197;
v_15198:
    fn = elt(env, 1); // ncmpchk
    v_15273 = (*qfn2(fn))(fn, v_15274, v_15273);
    env = stack[-5];
    v_15273 = ncons(v_15273);
    env = stack[-5];
    stack[-1] = v_15273;
    stack[-2] = v_15273;
v_15182:
    v_15273 = stack[-3];
    v_15273 = qcdr(v_15273);
    stack[-3] = v_15273;
    v_15273 = stack[-3];
    if (v_15273 == nil) goto v_15206;
    else goto v_15207;
v_15206:
    v_15273 = stack[-2];
    goto v_15181;
v_15207:
    goto v_15215;
v_15211:
    stack[0] = stack[-1];
    goto v_15212;
v_15213:
    v_15273 = stack[-3];
    v_15273 = qcar(v_15273);
    goto v_15226;
v_15222:
    v_15274 = stack[-4];
    goto v_15223;
v_15224:
    goto v_15225;
v_15226:
    goto v_15222;
v_15223:
    goto v_15224;
v_15225:
    fn = elt(env, 1); // ncmpchk
    v_15273 = (*qfn2(fn))(fn, v_15274, v_15273);
    env = stack[-5];
    v_15273 = ncons(v_15273);
    env = stack[-5];
    goto v_15214;
v_15215:
    goto v_15211;
v_15212:
    goto v_15213;
v_15214:
    v_15273 = Lrplacd(nil, stack[0], v_15273);
    env = stack[-5];
    v_15273 = stack[-1];
    v_15273 = qcdr(v_15273);
    stack[-1] = v_15273;
    goto v_15182;
v_15181:
    goto v_15239;
v_15235:
    v_15274 = nil;
    goto v_15236;
v_15237:
    goto v_15238;
v_15239:
    goto v_15235;
v_15236:
    goto v_15237;
v_15238:
    v_15273 = Lmember(nil, v_15274, v_15273);
    if (v_15273 == nil) goto v_15234;
    v_15273 = nil;
    goto v_15132;
v_15234:
    v_15273 = lisp_true;
    goto v_15132;
    goto v_15143;
v_15143:
    goto v_15138;
v_15140:
    goto v_15258;
v_15254:
    v_15273 = stack[-4];
    v_15274 = ncons(v_15273);
    env = stack[-5];
    goto v_15255;
v_15256:
    v_15273 = stack[0];
    goto v_15257;
v_15258:
    goto v_15254;
v_15255:
    goto v_15256;
v_15257:
    v_15273 = CC_physopordchkH(elt(env, 0), v_15274, v_15273);
    env = stack[-5];
    if (v_15273 == nil) goto v_15251;
    else goto v_15252;
v_15251:
    v_15273 = nil;
    goto v_15250;
v_15252:
    goto v_15270;
v_15266:
    v_15274 = stack[-1];
    goto v_15267;
v_15268:
    v_15273 = stack[0];
    goto v_15269;
v_15270:
    goto v_15266;
v_15267:
    goto v_15268;
v_15269:
    stack[-1] = v_15274;
    stack[0] = v_15273;
    goto v_15124;
    v_15273 = nil;
v_15250:
    goto v_15132;
v_15138:
    v_15273 = nil;
v_15132:
    return onevalue(v_15273);
}



// Code for fieldconv

static LispObject CC_fieldconv(LispObject env,
                         LispObject v_15125, LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15360, v_15361, v_15362;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15125,v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_15126;
    stack[-2] = v_15125;
// end of prologue
// Binding d
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = nil; // d
    v_15360 = stack[-1];
    v_15360 = qcar(v_15360);
    stack[0] = v_15360;
    v_15360 = stack[-1];
    v_15360 = qcdr(v_15360);
    qvalue(elt(env, 1)) = v_15360; // d
    v_15360 = qvalue(elt(env, 2)); // dmode!*
    if (v_15360 == nil) goto v_15139;
    else goto v_15140;
v_15139:
    goto v_15151;
v_15147:
    v_15361 = stack[-2];
    goto v_15148;
v_15149:
    v_15360 = elt(env, 3); // !:rn!:
    goto v_15150;
v_15151:
    goto v_15147;
v_15148:
    goto v_15149;
v_15150:
    if (!consp(v_15361)) goto v_15144;
    v_15361 = qcar(v_15361);
    if (v_15361 == v_15360) goto v_15145;
v_15144:
    goto v_15164;
v_15160:
    v_15360 = stack[-2];
    v_15361 = qcar(v_15360);
    goto v_15161;
v_15162:
    v_15360 = elt(env, 3); // !:rn!:
    goto v_15163;
v_15164:
    goto v_15160;
v_15161:
    goto v_15162;
v_15163:
    v_15360 = get(v_15361, v_15360);
    env = stack[-4];
    v_15361 = v_15360;
    if (v_15360 == nil) goto v_15157;
    v_15360 = v_15361;
    if (!consp(v_15360)) goto v_15168;
    else goto v_15157;
v_15168:
    goto v_15175;
v_15171:
    goto v_15172;
v_15173:
    v_15360 = stack[-2];
    goto v_15174;
v_15175:
    goto v_15171;
v_15172:
    goto v_15173;
v_15174:
    v_15360 = Lapply1(nil, v_15361, v_15360);
    env = stack[-4];
    stack[-2] = v_15360;
    goto v_15155;
v_15157:
    goto v_15185;
v_15181:
    v_15360 = stack[-2];
    v_15361 = qcar(v_15360);
    goto v_15182;
v_15183:
    v_15360 = elt(env, 4); // quotient
    goto v_15184;
v_15185:
    goto v_15181;
v_15182:
    goto v_15183;
v_15184:
    v_15360 = get(v_15361, v_15360);
    env = stack[-4];
    if (v_15360 == nil) goto v_15179;
    goto v_15196;
v_15190:
    v_15362 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15191;
v_15192:
    v_15361 = stack[-2];
    goto v_15193;
v_15194:
    v_15360 = elt(env, 4); // quotient
    goto v_15195;
v_15196:
    goto v_15190;
v_15191:
    goto v_15192;
v_15193:
    goto v_15194;
v_15195:
    fn = elt(env, 6); // dcombine
    v_15360 = (*qfnn(fn))(fn, 3, v_15362, v_15361, v_15360);
    env = stack[-4];
    stack[-2] = v_15360;
    goto v_15205;
v_15201:
    goto v_15211;
v_15207:
    v_15361 = stack[-2];
    goto v_15208;
v_15209:
    v_15360 = stack[-1];
    v_15360 = qcar(v_15360);
    goto v_15210;
v_15211:
    goto v_15207;
v_15208:
    goto v_15209;
v_15210:
    fn = elt(env, 7); // multd
    stack[0] = (*qfn2(fn))(fn, v_15361, v_15360);
    env = stack[-4];
    goto v_15202;
v_15203:
    goto v_15220;
v_15216:
    v_15361 = stack[-2];
    goto v_15217;
v_15218:
    v_15360 = stack[-1];
    v_15360 = qcdr(v_15360);
    goto v_15219;
v_15220:
    goto v_15216;
v_15217:
    goto v_15218;
v_15219:
    fn = elt(env, 7); // multd
    v_15360 = (*qfn2(fn))(fn, v_15361, v_15360);
    env = stack[-4];
    goto v_15204;
v_15205:
    goto v_15201;
v_15202:
    goto v_15203;
v_15204:
    v_15360 = cons(stack[0], v_15360);
    goto v_15132;
v_15179:
    goto v_15232;
v_15228:
    v_15361 = elt(env, 5); // "field conversion"
    goto v_15229;
v_15230:
    v_15360 = stack[-2];
    goto v_15231;
v_15232:
    goto v_15228;
v_15229:
    goto v_15230;
v_15231:
    v_15360 = list2(v_15361, v_15360);
    env = stack[-4];
    fn = elt(env, 8); // errach
    v_15360 = (*qfn1(fn))(fn, v_15360);
    env = stack[-4];
    goto v_15155;
v_15155:
    goto v_15143;
v_15145:
v_15143:
    goto v_15242;
v_15236:
    v_15360 = stack[-2];
    v_15362 = qcar(v_15360);
    goto v_15237;
v_15238:
    v_15360 = stack[-2];
    v_15360 = qcdr(v_15360);
    v_15361 = qcdr(v_15360);
    goto v_15239;
v_15240:
    v_15360 = stack[-2];
    v_15360 = qcdr(v_15360);
    v_15360 = qcar(v_15360);
    goto v_15241;
v_15242:
    goto v_15236;
v_15237:
    goto v_15238;
v_15239:
    goto v_15240;
v_15241:
    v_15360 = list2star(v_15362, v_15361, v_15360);
    env = stack[-4];
    stack[-2] = v_15360;
    v_15360 = qvalue(elt(env, 1)); // d
    if (!consp(v_15360)) goto v_15258;
    else goto v_15259;
v_15258:
    v_15360 = lisp_true;
    goto v_15257;
v_15259:
    v_15360 = qvalue(elt(env, 1)); // d
    v_15360 = qcar(v_15360);
    v_15360 = (consp(v_15360) ? nil : lisp_true);
    goto v_15257;
    v_15360 = nil;
v_15257:
    if (v_15360 == nil) goto v_15255;
    goto v_15272;
v_15268:
    goto v_15278;
v_15274:
    v_15361 = stack[-2];
    goto v_15275;
v_15276:
    v_15360 = stack[0];
    goto v_15277;
v_15278:
    goto v_15274;
v_15275:
    goto v_15276;
v_15277:
    fn = elt(env, 7); // multd
    v_15361 = (*qfn2(fn))(fn, v_15361, v_15360);
    env = stack[-4];
    goto v_15269;
v_15270:
    v_15360 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15271;
v_15272:
    goto v_15268;
v_15269:
    goto v_15270;
v_15271:
    v_15360 = cons(v_15361, v_15360);
    env = stack[-4];
    goto v_15253;
v_15255:
    goto v_15289;
v_15285:
    goto v_15295;
v_15291:
    v_15361 = stack[-2];
    goto v_15292;
v_15293:
    v_15360 = stack[0];
    goto v_15294;
v_15295:
    goto v_15291;
v_15292:
    goto v_15293;
v_15294:
    fn = elt(env, 7); // multd
    stack[0] = (*qfn2(fn))(fn, v_15361, v_15360);
    env = stack[-4];
    goto v_15286;
v_15287:
    goto v_15303;
v_15299:
    v_15361 = stack[-2];
    goto v_15300;
v_15301:
    v_15360 = qvalue(elt(env, 1)); // d
    goto v_15302;
v_15303:
    goto v_15299;
v_15300:
    goto v_15301;
v_15302:
    fn = elt(env, 7); // multd
    v_15360 = (*qfn2(fn))(fn, v_15361, v_15360);
    env = stack[-4];
    goto v_15288;
v_15289:
    goto v_15285;
v_15286:
    goto v_15287;
v_15288:
    v_15360 = cons(stack[0], v_15360);
    env = stack[-4];
    goto v_15253;
    v_15360 = nil;
v_15253:
    fn = elt(env, 9); // simpgd
    v_15360 = (*qfn1(fn))(fn, v_15360);
    goto v_15132;
v_15140:
    v_15360 = qvalue(elt(env, 1)); // d
    if (!consp(v_15360)) goto v_15312;
    else goto v_15313;
v_15312:
    v_15360 = lisp_true;
    goto v_15311;
v_15313:
    v_15360 = qvalue(elt(env, 1)); // d
    v_15360 = qcar(v_15360);
    v_15360 = (consp(v_15360) ? nil : lisp_true);
    goto v_15311;
    v_15360 = nil;
v_15311:
    if (v_15360 == nil) goto v_15309;
    goto v_15326;
v_15322:
    goto v_15332;
v_15328:
    v_15361 = stack[0];
    goto v_15329;
v_15330:
    v_15360 = qvalue(elt(env, 1)); // d
    goto v_15331;
v_15332:
    goto v_15328;
v_15329:
    goto v_15330;
v_15331:
    fn = elt(env, 10); // divd
    v_15361 = (*qfn2(fn))(fn, v_15361, v_15360);
    env = stack[-4];
    goto v_15323;
v_15324:
    v_15360 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15325;
v_15326:
    goto v_15322;
v_15323:
    goto v_15324;
v_15325:
    v_15360 = cons(v_15361, v_15360);
    goto v_15307;
v_15309:
    goto v_15343;
v_15339:
    goto v_15349;
v_15345:
    v_15361 = stack[0];
    goto v_15346;
v_15347:
    v_15360 = stack[-2];
    goto v_15348;
v_15349:
    goto v_15345;
v_15346:
    goto v_15347;
v_15348:
    fn = elt(env, 10); // divd
    stack[0] = (*qfn2(fn))(fn, v_15361, v_15360);
    env = stack[-4];
    goto v_15340;
v_15341:
    goto v_15357;
v_15353:
    v_15361 = qvalue(elt(env, 1)); // d
    goto v_15354;
v_15355:
    v_15360 = stack[-2];
    goto v_15356;
v_15357:
    goto v_15353;
v_15354:
    goto v_15355;
v_15356:
    fn = elt(env, 10); // divd
    v_15360 = (*qfn2(fn))(fn, v_15361, v_15360);
    env = stack[-4];
    goto v_15342;
v_15343:
    goto v_15339;
v_15340:
    goto v_15341;
v_15342:
    v_15360 = cons(stack[0], v_15360);
    goto v_15307;
    v_15360 = nil;
v_15307:
v_15132:
    ;}  // end of a binding scope
    return onevalue(v_15360);
}



// Code for mod_eval_uni_poly

static LispObject CC_mod_eval_uni_poly(LispObject env,
                         LispObject v_15125, LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15245, v_15246;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15125,v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_15126;
    stack[-3] = v_15125;
// end of prologue
    v_15245 = stack[-3];
    if (!consp(v_15245)) goto v_15130;
    else goto v_15131;
v_15130:
    v_15245 = stack[-3];
    {
        fn = elt(env, 3); // mod!#
        return (*qfn1(fn))(fn, v_15245);
    }
v_15131:
// Binding d
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = nil; // d
    v_15245 = stack[-3];
    v_15245 = qcar(v_15245);
    v_15245 = qcdr(v_15245);
    fn = elt(env, 3); // mod!#
    v_15245 = (*qfn1(fn))(fn, v_15245);
    env = stack[-5];
    v_15246 = v_15245;
    v_15245 = stack[-3];
    v_15245 = qcar(v_15245);
    v_15245 = qcar(v_15245);
    v_15245 = qcdr(v_15245);
    qvalue(elt(env, 1)) = v_15245; // d
    v_15245 = stack[-3];
    v_15245 = qcdr(v_15245);
    stack[-3] = v_15245;
v_15153:
    v_15245 = stack[-3];
    if (!consp(v_15245)) goto v_15156;
    else goto v_15157;
v_15156:
    goto v_15152;
v_15157:
    goto v_15165;
v_15161:
    goto v_15171;
v_15167:
    goto v_15177;
v_15173:
    stack[-1] = v_15246;
    goto v_15174;
v_15175:
    goto v_15184;
v_15180:
    stack[0] = stack[-2];
    goto v_15181;
v_15182:
    goto v_15191;
v_15187:
    v_15246 = qvalue(elt(env, 1)); // d
    goto v_15188;
v_15189:
    v_15245 = stack[-3];
    v_15245 = qcar(v_15245);
    v_15245 = qcar(v_15245);
    v_15245 = qcdr(v_15245);
    goto v_15190;
v_15191:
    goto v_15187;
v_15188:
    goto v_15189;
v_15190:
    v_15245 = difference2(v_15246, v_15245);
    env = stack[-5];
    goto v_15183;
v_15184:
    goto v_15180;
v_15181:
    goto v_15182;
v_15183:
    fn = elt(env, 4); // general!-modular!-expt
    v_15245 = (*qfn2(fn))(fn, stack[0], v_15245);
    env = stack[-5];
    goto v_15176;
v_15177:
    goto v_15173;
v_15174:
    goto v_15175;
v_15176:
    v_15246 = times2(stack[-1], v_15245);
    env = stack[-5];
    goto v_15168;
v_15169:
    v_15245 = qvalue(elt(env, 2)); // current!-modulus
    goto v_15170;
v_15171:
    goto v_15167;
v_15168:
    goto v_15169;
v_15170:
    stack[0] = Cremainder(v_15246, v_15245);
    env = stack[-5];
    goto v_15162;
v_15163:
    v_15245 = stack[-3];
    v_15245 = qcar(v_15245);
    v_15245 = qcdr(v_15245);
    fn = elt(env, 3); // mod!#
    v_15245 = (*qfn1(fn))(fn, v_15245);
    env = stack[-5];
    goto v_15164;
v_15165:
    goto v_15161;
v_15162:
    goto v_15163;
v_15164:
    fn = elt(env, 5); // general!-modular!-plus
    v_15245 = (*qfn2(fn))(fn, stack[0], v_15245);
    env = stack[-5];
    v_15246 = v_15245;
    v_15245 = stack[-3];
    v_15245 = qcar(v_15245);
    v_15245 = qcar(v_15245);
    v_15245 = qcdr(v_15245);
    qvalue(elt(env, 1)) = v_15245; // d
    v_15245 = stack[-3];
    v_15245 = qcdr(v_15245);
    stack[-3] = v_15245;
    goto v_15153;
v_15152:
    goto v_15213;
v_15209:
    goto v_15219;
v_15215:
    stack[0] = v_15246;
    goto v_15216;
v_15217:
    goto v_15226;
v_15222:
    v_15246 = stack[-2];
    goto v_15223;
v_15224:
    v_15245 = qvalue(elt(env, 1)); // d
    goto v_15225;
v_15226:
    goto v_15222;
v_15223:
    goto v_15224;
v_15225:
    fn = elt(env, 4); // general!-modular!-expt
    v_15245 = (*qfn2(fn))(fn, v_15246, v_15245);
    env = stack[-5];
    goto v_15218;
v_15219:
    goto v_15215;
v_15216:
    goto v_15217;
v_15218:
    v_15246 = times2(stack[0], v_15245);
    env = stack[-5];
    goto v_15210;
v_15211:
    v_15245 = qvalue(elt(env, 2)); // current!-modulus
    goto v_15212;
v_15213:
    goto v_15209;
v_15210:
    goto v_15211;
v_15212:
    v_15245 = Cremainder(v_15246, v_15245);
    env = stack[-5];
    v_15246 = v_15245;
    v_15245 = stack[-3];
    if (v_15245 == nil) goto v_15233;
    goto v_15240;
v_15236:
    stack[0] = v_15246;
    goto v_15237;
v_15238:
    v_15245 = stack[-3];
    fn = elt(env, 3); // mod!#
    v_15245 = (*qfn1(fn))(fn, v_15245);
    env = stack[-5];
    goto v_15239;
v_15240:
    goto v_15236;
v_15237:
    goto v_15238;
v_15239:
    fn = elt(env, 5); // general!-modular!-plus
    v_15245 = (*qfn2(fn))(fn, stack[0], v_15245);
    v_15246 = v_15245;
    goto v_15231;
v_15233:
v_15231:
    v_15245 = v_15246;
    ;}  // end of a binding scope
    goto v_15129;
    v_15245 = nil;
v_15129:
    return onevalue(v_15245);
}



// Code for reduce!-mod!-p!*

static LispObject CC_reduceKmodKpH(LispObject env,
                         LispObject v_15125, LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15132, v_15133;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15125,v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_15132 = v_15126;
    v_15133 = v_15125;
// end of prologue
// Binding current!-modulus
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_15132; // current!-modulus
    v_15132 = v_15133;
    fn = elt(env, 2); // general!-reduce!-mod!-p
    v_15132 = (*qfn1(fn))(fn, v_15132);
    ;}  // end of a binding scope
    return onevalue(v_15132);
}



// Code for string!-of!-list

static LispObject CC_stringKofKlist(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15201, v_15202;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_15202 = v_15125;
// end of prologue
    v_15201 = v_15202;
    if (v_15201 == nil) goto v_15129;
    else goto v_15130;
v_15129:
    v_15201 = elt(env, 1); // ""
    goto v_15128;
v_15130:
    v_15201 = v_15202;
    stack[-4] = v_15201;
v_15141:
    v_15201 = stack[-4];
    if (v_15201 == nil) goto v_15146;
    else goto v_15147;
v_15146:
    v_15201 = nil;
    goto v_15140;
v_15147:
    v_15201 = stack[-4];
    v_15201 = qcar(v_15201);
    goto v_15158;
v_15154:
    stack[0] = elt(env, 2); // !;
    goto v_15155;
v_15156:
    v_15201 = Lexplode(nil, v_15201);
    env = stack[-5];
    goto v_15157;
v_15158:
    goto v_15154;
v_15155:
    goto v_15156;
v_15157:
    v_15201 = cons(stack[0], v_15201);
    env = stack[-5];
    stack[-3] = v_15201;
    v_15201 = stack[-3];
    fn = elt(env, 3); // lastpair
    v_15201 = (*qfn1(fn))(fn, v_15201);
    env = stack[-5];
    stack[-2] = v_15201;
    v_15201 = stack[-4];
    v_15201 = qcdr(v_15201);
    stack[-4] = v_15201;
    v_15201 = stack[-2];
    if (!consp(v_15201)) goto v_15168;
    else goto v_15169;
v_15168:
    goto v_15141;
v_15169:
v_15142:
    v_15201 = stack[-4];
    if (v_15201 == nil) goto v_15173;
    else goto v_15174;
v_15173:
    v_15201 = stack[-3];
    goto v_15140;
v_15174:
    goto v_15182;
v_15178:
    stack[-1] = stack[-2];
    goto v_15179;
v_15180:
    v_15201 = stack[-4];
    v_15201 = qcar(v_15201);
    goto v_15192;
v_15188:
    stack[0] = elt(env, 2); // !;
    goto v_15189;
v_15190:
    v_15201 = Lexplode(nil, v_15201);
    env = stack[-5];
    goto v_15191;
v_15192:
    goto v_15188;
v_15189:
    goto v_15190;
v_15191:
    v_15201 = cons(stack[0], v_15201);
    env = stack[-5];
    goto v_15181;
v_15182:
    goto v_15178;
v_15179:
    goto v_15180;
v_15181:
    v_15201 = Lrplacd(nil, stack[-1], v_15201);
    env = stack[-5];
    v_15201 = stack[-2];
    fn = elt(env, 3); // lastpair
    v_15201 = (*qfn1(fn))(fn, v_15201);
    env = stack[-5];
    stack[-2] = v_15201;
    v_15201 = stack[-4];
    v_15201 = qcdr(v_15201);
    stack[-4] = v_15201;
    goto v_15142;
v_15140:
    v_15201 = qcdr(v_15201);
    {
        fn = elt(env, 4); // list2string
        return (*qfn1(fn))(fn, v_15201);
    }
    v_15201 = nil;
v_15128:
    return onevalue(v_15201);
}



// Code for yylex

static LispObject CC_yylex(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15317, v_15318, v_15319;
    LispObject fn;
    argcheck(nargs, 0, "yylex");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// end of prologue
    stack[-2] = nil;
    fn = elt(env, 14); // lex_basic_token
    v_15317 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[0] = v_15317;
v_15134:
    v_15317 = stack[-2];
    if (v_15317 == nil) goto v_15141;
    else goto v_15142;
v_15141:
    goto v_15152;
v_15148:
    v_15318 = stack[0];
    goto v_15149;
v_15150:
    v_15317 = qvalue(elt(env, 1)); // lex_symbol_code
    goto v_15151;
v_15152:
    goto v_15148;
v_15149:
    goto v_15150;
v_15151:
    if (equal(v_15318, v_15317)) goto v_15146;
    else goto v_15147;
v_15146:
    v_15317 = qvalue(elt(env, 2)); // lex_escaped
    if (v_15317 == nil) goto v_15157;
    else goto v_15158;
v_15157:
    goto v_15166;
v_15162:
    v_15318 = qvalue(elt(env, 3)); // lexer_style!*
    goto v_15163;
v_15164:
    v_15317 = (LispObject)1024+TAG_FIXNUM; // 64
    goto v_15165;
v_15166:
    goto v_15162;
v_15163:
    goto v_15164;
v_15165:
    fn = elt(env, 15); // land
    v_15317 = (*qfn2(fn))(fn, v_15318, v_15317);
    env = stack[-4];
    v_15317 = (LispObject)zerop(v_15317);
    v_15317 = v_15317 ? lisp_true : nil;
    env = stack[-4];
    v_15317 = (v_15317 == nil ? lisp_true : nil);
    goto v_15156;
v_15158:
    v_15317 = nil;
    goto v_15156;
    v_15317 = nil;
v_15156:
    goto v_15145;
v_15147:
    v_15317 = nil;
    goto v_15145;
    v_15317 = nil;
v_15145:
    goto v_15140;
v_15142:
    v_15317 = nil;
    goto v_15140;
    v_15317 = nil;
v_15140:
    if (v_15317 == nil) goto v_15137;
    else goto v_15138;
v_15137:
    goto v_15133;
v_15138:
    fn = elt(env, 16); // lex_process_directive
    v_15317 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    if (v_15317 == nil) goto v_15183;
    fn = elt(env, 14); // lex_basic_token
    v_15317 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[0] = v_15317;
    goto v_15181;
v_15183:
    goto v_15192;
v_15188:
    v_15318 = qvalue(elt(env, 4)); // yylval
    goto v_15189;
v_15190:
    v_15317 = elt(env, 5); // !#define
    goto v_15191;
v_15192:
    goto v_15188;
v_15189:
    goto v_15190;
v_15191:
    if (v_15318 == v_15317) goto v_15186;
    else goto v_15187;
v_15186:
    fn = elt(env, 17); // read_s_expression
    v_15317 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    v_15317 = qvalue(elt(env, 4)); // yylval
    stack[0] = v_15317;
    fn = elt(env, 17); // read_s_expression
    v_15317 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    v_15317 = qvalue(elt(env, 4)); // yylval
    stack[-3] = v_15317;
    v_15317 = stack[0];
    if (symbolp(v_15317)) goto v_15203;
    else goto v_15202;
v_15203:
    v_15317 = stack[-3];
    if (symbolp(v_15317)) goto v_15205;
    v_15317 = stack[-3];
    if (is_number(v_15317)) goto v_15205;
    v_15317 = stack[-3];
    v_15317 = Lstringp(nil, v_15317);
    env = stack[-4];
    if (v_15317 == nil) goto v_15211;
    else goto v_15205;
v_15211:
    goto v_15202;
v_15205:
    v_15317 = Lposn(nil, 0);
    env = stack[-4];
    v_15317 = (LispObject)zerop(v_15317);
    v_15317 = v_15317 ? lisp_true : nil;
    env = stack[-4];
    if (v_15317 == nil) goto v_15216;
    else goto v_15217;
v_15216:
    v_15317 = Lterpri(nil, 0);
    env = stack[-4];
    goto v_15215;
v_15217:
v_15215:
    v_15317 = elt(env, 6); // "+++ "
    v_15317 = Lprinc(nil, v_15317);
    env = stack[-4];
    v_15317 = stack[0];
    v_15317 = Lprin(nil, v_15317);
    env = stack[-4];
    v_15317 = elt(env, 7); // " => "
    v_15317 = Lprinc(nil, v_15317);
    env = stack[-4];
    v_15317 = stack[-3];
    v_15317 = Lprint(nil, v_15317);
    env = stack[-4];
    goto v_15236;
v_15230:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15231;
v_15232:
    stack[0] = elt(env, 5); // !#define
    goto v_15233;
v_15234:
    v_15317 = stack[-3];
    v_15317 = ncons(v_15317);
    env = stack[-4];
    goto v_15235;
v_15236:
    goto v_15230;
v_15231:
    goto v_15232;
v_15233:
    goto v_15234;
v_15235:
    v_15317 = Lputprop(nil, 3, stack[-1], stack[0], v_15317);
    env = stack[-4];
    goto v_15200;
v_15202:
v_15200:
    fn = elt(env, 14); // lex_basic_token
    v_15317 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[0] = v_15317;
    goto v_15181;
v_15187:
    goto v_15248;
v_15244:
    v_15318 = qvalue(elt(env, 4)); // yylval
    goto v_15245;
v_15246:
    v_15317 = elt(env, 8); // !#eval
    goto v_15247;
v_15248:
    goto v_15244;
v_15245:
    goto v_15246;
v_15247:
    if (v_15318 == v_15317) goto v_15242;
    else goto v_15243;
v_15242:
    fn = elt(env, 17); // read_s_expression
    v_15317 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_15259;
v_15253:
    v_15319 = qvalue(elt(env, 4)); // yylval
    goto v_15254;
v_15255:
    v_15318 = nil;
    goto v_15256;
v_15257:
    v_15317 = nil;
    goto v_15258;
v_15259:
    goto v_15253;
v_15254:
    goto v_15255;
v_15256:
    goto v_15257;
v_15258:
    fn = elt(env, 18); // errorset
    v_15317 = (*qfnn(fn))(fn, 3, v_15319, v_15318, v_15317);
    env = stack[-4];
    fn = elt(env, 14); // lex_basic_token
    v_15317 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[0] = v_15317;
    goto v_15181;
v_15243:
    goto v_15271;
v_15267:
    v_15318 = qvalue(elt(env, 4)); // yylval
    goto v_15268;
v_15269:
    v_15317 = elt(env, 5); // !#define
    goto v_15270;
v_15271:
    goto v_15267;
v_15268:
    goto v_15269;
v_15270:
    v_15317 = get(v_15318, v_15317);
    env = stack[-4];
    stack[-3] = v_15317;
    if (v_15317 == nil) goto v_15265;
    v_15317 = stack[-3];
    v_15317 = qcar(v_15317);
    qvalue(elt(env, 4)) = v_15317; // yylval
    v_15317 = stack[-3];
    if (is_number(v_15317)) goto v_15278;
    else goto v_15279;
v_15278:
    v_15317 = qvalue(elt(env, 9)); // lex_number_code
    stack[0] = v_15317;
    goto v_15277;
v_15279:
    v_15317 = stack[-3];
    v_15317 = Lstringp(nil, v_15317);
    env = stack[-4];
    if (v_15317 == nil) goto v_15283;
    v_15317 = qvalue(elt(env, 10)); // lex_string_code
    stack[0] = v_15317;
    goto v_15277;
v_15283:
v_15277:
    v_15317 = lisp_true;
    stack[-2] = v_15317;
    goto v_15181;
v_15265:
    v_15317 = lisp_true;
    stack[-2] = v_15317;
    goto v_15181;
v_15181:
    goto v_15134;
v_15133:
    v_15317 = qvalue(elt(env, 11)); // !*tracelex
    if (v_15317 == nil) goto v_15294;
    goto v_15304;
v_15300:
    v_15318 = Lposn(nil, 0);
    env = stack[-4];
    goto v_15301;
v_15302:
    v_15317 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15303;
v_15304:
    goto v_15300;
v_15301:
    goto v_15302;
v_15303:
    if (v_15318 == v_15317) goto v_15299;
    v_15317 = Lterpri(nil, 0);
    env = stack[-4];
    goto v_15297;
v_15299:
v_15297:
    v_15317 = elt(env, 12); // "yylex = "
    v_15317 = Lprinc(nil, v_15317);
    env = stack[-4];
    v_15317 = qvalue(elt(env, 4)); // yylval
    v_15317 = Lprin(nil, v_15317);
    env = stack[-4];
    v_15317 = elt(env, 13); // " type "
    v_15317 = Lprinc(nil, v_15317);
    env = stack[-4];
    v_15317 = stack[0];
    v_15317 = Lprint(nil, v_15317);
    goto v_15292;
v_15294:
v_15292:
    v_15317 = stack[0];
    return onevalue(v_15317);
}



// Code for gcref_remprops

static LispObject CC_gcref_remprops(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15192, v_15193, v_15194;
    LispObject fn;
    argcheck(nargs, 0, "gcref_remprops");
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
    goto v_15131;
v_15127:
    v_15193 = qvalue(elt(env, 1)); // seen!*
    goto v_15128;
v_15129:
    v_15192 = elt(env, 2); // (gall calls globs calledby alsois sameas)
    goto v_15130;
v_15131:
    goto v_15127;
v_15128:
    goto v_15129;
v_15130:
    fn = elt(env, 12); // rempropss
    v_15192 = (*qfn2(fn))(fn, v_15193, v_15192);
    env = stack[0];
    goto v_15139;
v_15135:
    v_15193 = qvalue(elt(env, 1)); // seen!*
    goto v_15136;
v_15137:
    v_15192 = elt(env, 3); // (seen cinthis defd)
    goto v_15138;
v_15139:
    goto v_15135;
v_15136:
    goto v_15137;
v_15138:
    fn = elt(env, 13); // remflagss
    v_15192 = (*qfn2(fn))(fn, v_15193, v_15192);
    env = stack[0];
    goto v_15147;
v_15143:
    v_15193 = qvalue(elt(env, 4)); // gcref_exportl!*
    goto v_15144;
v_15145:
    v_15192 = elt(env, 5); // (exported)
    goto v_15146;
v_15147:
    goto v_15143;
v_15144:
    goto v_15145;
v_15146:
    fn = elt(env, 13); // remflagss
    v_15192 = (*qfn2(fn))(fn, v_15193, v_15192);
    env = stack[0];
    goto v_15155;
v_15151:
    v_15193 = qvalue(elt(env, 6)); // gseen!*
    goto v_15152;
v_15153:
    v_15192 = elt(env, 7); // (usedby usedunby boundby setby)
    goto v_15154;
v_15155:
    goto v_15151;
v_15152:
    goto v_15153;
v_15154:
    fn = elt(env, 12); // rempropss
    v_15192 = (*qfn2(fn))(fn, v_15193, v_15192);
    env = stack[0];
    goto v_15163;
v_15159:
    v_15193 = qvalue(elt(env, 6)); // gseen!*
    goto v_15160;
v_15161:
    v_15192 = elt(env, 8); // (dclglb gseen glb2rf glb2bd glb2st)
    goto v_15162;
v_15163:
    goto v_15159;
v_15160:
    goto v_15161;
v_15162:
    fn = elt(env, 13); // remflagss
    v_15192 = (*qfn2(fn))(fn, v_15193, v_15192);
    env = stack[0];
    v_15192 = qvalue(elt(env, 9)); // tseen!*
    v_15194 = v_15192;
v_15169:
    v_15192 = v_15194;
    if (v_15192 == nil) goto v_15173;
    else goto v_15174;
v_15173:
    goto v_15168;
v_15174:
    v_15192 = v_15194;
    v_15192 = qcar(v_15192);
    goto v_15185;
v_15181:
    v_15193 = qcar(v_15192);
    goto v_15182;
v_15183:
    v_15192 = elt(env, 10); // funs
    goto v_15184;
v_15185:
    goto v_15181;
v_15182:
    goto v_15183;
v_15184:
    v_15192 = Lremprop(nil, v_15193, v_15192);
    env = stack[0];
    v_15192 = v_15194;
    v_15192 = qcdr(v_15192);
    v_15194 = v_15192;
    goto v_15169;
v_15168:
    v_15192 = nil;
    qvalue(elt(env, 9)) = v_15192; // tseen!*
    qvalue(elt(env, 1)) = v_15192; // seen!*
    qvalue(elt(env, 6)) = v_15192; // gseen!*
    qvalue(elt(env, 11)) = v_15192; // haveargs!*
    return onevalue(v_15192);
}



// Code for ofsf_smmkatl

static LispObject CC_ofsf_smmkatl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15175, v_15176, v_15177, v_15178;
    LispObject fn;
    LispObject v_15128, v_15127, v_15126, v_15125;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ofsf_smmkatl");
    va_start(aa, nargs);
    v_15125 = va_arg(aa, LispObject);
    v_15126 = va_arg(aa, LispObject);
    v_15127 = va_arg(aa, LispObject);
    v_15128 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_15128,v_15127,v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_15125,v_15126,v_15127,v_15128);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_15175 = v_15128;
    stack[0] = v_15127;
    v_15176 = v_15126;
    v_15178 = v_15125;
// end of prologue
    v_15177 = qvalue(elt(env, 1)); // !*rlsippatl
    if (v_15177 == nil) goto v_15133;
    goto v_15142;
v_15136:
    stack[-1] = v_15178;
    goto v_15137;
v_15138:
    goto v_15153;
v_15145:
    goto v_15146;
v_15147:
    v_15177 = v_15176;
    goto v_15148;
v_15149:
    v_15176 = stack[0];
    goto v_15150;
v_15151:
    goto v_15152;
v_15153:
    goto v_15145;
v_15146:
    goto v_15147;
v_15148:
    goto v_15149;
v_15150:
    goto v_15151;
v_15152:
    fn = elt(env, 2); // ofsf_smmkatl1
    v_15176 = (*qfnn(fn))(fn, 4, v_15178, v_15177, v_15176, v_15175);
    env = stack[-2];
    goto v_15139;
v_15140:
    v_15175 = stack[0];
    goto v_15141;
v_15142:
    goto v_15136;
v_15137:
    goto v_15138;
v_15139:
    goto v_15140;
v_15141:
    {
        LispObject v_15181 = stack[-1];
        fn = elt(env, 3); // ofsf_sippatl
        return (*qfnn(fn))(fn, 3, v_15181, v_15176, v_15175);
    }
v_15133:
    goto v_15170;
v_15162:
    goto v_15163;
v_15164:
    v_15177 = v_15176;
    goto v_15165;
v_15166:
    v_15176 = stack[0];
    goto v_15167;
v_15168:
    goto v_15169;
v_15170:
    goto v_15162;
v_15163:
    goto v_15164;
v_15165:
    goto v_15166;
v_15167:
    goto v_15168;
v_15169:
    {
        fn = elt(env, 2); // ofsf_smmkatl1
        return (*qfnn(fn))(fn, 4, v_15178, v_15177, v_15176, v_15175);
    }
    v_15175 = nil;
    return onevalue(v_15175);
}



// Code for talp_subat

static LispObject CC_talp_subat(LispObject env,
                         LispObject v_15125, LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15156;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15125,v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_15126;
    stack[-2] = v_15125;
// end of prologue
    goto v_15135;
v_15129:
    v_15156 = stack[-1];
    fn = elt(env, 1); // talp_op
    stack[-3] = (*qfn1(fn))(fn, v_15156);
    env = stack[-4];
    goto v_15130;
v_15131:
    goto v_15143;
v_15139:
    stack[0] = stack[-2];
    goto v_15140;
v_15141:
    v_15156 = stack[-1];
    fn = elt(env, 2); // talp_arg2l
    v_15156 = (*qfn1(fn))(fn, v_15156);
    env = stack[-4];
    goto v_15142;
v_15143:
    goto v_15139;
v_15140:
    goto v_15141;
v_15142:
    fn = elt(env, 3); // talp_subt
    stack[0] = (*qfn2(fn))(fn, stack[0], v_15156);
    env = stack[-4];
    goto v_15132;
v_15133:
    goto v_15152;
v_15148:
    goto v_15149;
v_15150:
    v_15156 = stack[-1];
    fn = elt(env, 4); // talp_arg2r
    v_15156 = (*qfn1(fn))(fn, v_15156);
    env = stack[-4];
    goto v_15151;
v_15152:
    goto v_15148;
v_15149:
    goto v_15150;
v_15151:
    fn = elt(env, 3); // talp_subt
    v_15156 = (*qfn2(fn))(fn, stack[-2], v_15156);
    env = stack[-4];
    goto v_15134;
v_15135:
    goto v_15129;
v_15130:
    goto v_15131;
v_15132:
    goto v_15133;
v_15134:
    {
        LispObject v_15161 = stack[-3];
        LispObject v_15162 = stack[0];
        fn = elt(env, 5); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_15161, v_15162, v_15156);
    }
}



// Code for vsl_subatsq

static LispObject CC_vsl_subatsq(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15154, v_15155, v_15156, v_15157;
    LispObject fn;
    LispObject v_15127, v_15126, v_15125;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "vsl_subatsq");
    va_start(aa, nargs);
    v_15125 = va_arg(aa, LispObject);
    v_15126 = va_arg(aa, LispObject);
    v_15127 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15127,v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15125,v_15126,v_15127);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15155 = v_15127;
    v_15156 = v_15126;
    v_15157 = v_15125;
// end of prologue
    goto v_15136;
v_15130:
    v_15154 = v_15157;
    stack[0] = qcar(v_15154);
    goto v_15131;
v_15132:
    goto v_15146;
v_15140:
    v_15154 = v_15157;
    v_15154 = qcdr(v_15154);
    v_15154 = qcar(v_15154);
    goto v_15141;
v_15142:
    goto v_15143;
v_15144:
    goto v_15145;
v_15146:
    goto v_15140;
v_15141:
    goto v_15142;
v_15143:
    goto v_15144;
v_15145:
    fn = elt(env, 1); // ofsf_subf
    v_15154 = (*qfnn(fn))(fn, 3, v_15154, v_15156, v_15155);
    v_15155 = qcar(v_15154);
    goto v_15133;
v_15134:
    v_15154 = nil;
    goto v_15135;
v_15136:
    goto v_15130;
v_15131:
    goto v_15132;
v_15133:
    goto v_15134;
v_15135:
    {
        LispObject v_15159 = stack[0];
        return list3(v_15159, v_15155, v_15154);
    }
}



// Code for unaryir

static LispObject CC_unaryir(LispObject env,
                         LispObject v_15125, LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15164, v_15165;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15125,v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15126;
    stack[-1] = v_15125;
// end of prologue
    goto v_15138;
v_15134:
    v_15165 = qvalue(elt(env, 1)); // atts
    goto v_15135;
v_15136:
    v_15164 = elt(env, 2); // name
    goto v_15137;
v_15138:
    goto v_15134;
v_15135:
    goto v_15136;
v_15137:
    fn = elt(env, 4); // find
    v_15164 = (*qfn2(fn))(fn, v_15165, v_15164);
    env = stack[-3];
    v_15164 = Lintern(nil, v_15164);
    env = stack[-3];
    stack[-2] = v_15164;
    goto v_15147;
v_15143:
    v_15165 = qvalue(elt(env, 1)); // atts
    goto v_15144;
v_15145:
    v_15164 = elt(env, 3); // cd
    goto v_15146;
v_15147:
    goto v_15143;
v_15144:
    goto v_15145;
v_15146:
    fn = elt(env, 4); // find
    v_15164 = (*qfn2(fn))(fn, v_15165, v_15164);
    env = stack[-3];
    v_15164 = Lintern(nil, v_15164);
    env = stack[-3];
    goto v_15158;
v_15154:
    v_15165 = v_15164;
    goto v_15155;
v_15156:
    v_15164 = stack[-1];
    goto v_15157;
v_15158:
    goto v_15154;
v_15155:
    goto v_15156;
v_15157:
    if (equal(v_15165, v_15164)) goto v_15153;
    v_15164 = stack[-2];
    {
        fn = elt(env, 5); // encodeir
        return (*qfn1(fn))(fn, v_15164);
    }
v_15153:
    v_15164 = stack[0];
    return onevalue(v_15164);
}



// Code for rootextractsq

static LispObject CC_rootextractsq(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15151, v_15152;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_15152 = v_15125;
// end of prologue
    v_15151 = v_15152;
    v_15151 = qcar(v_15151);
    if (v_15151 == nil) goto v_15129;
    else goto v_15130;
v_15129:
    v_15151 = v_15152;
    goto v_15128;
v_15130:
    v_15151 = v_15152;
    fn = elt(env, 1); // subs2q
    v_15151 = (*qfn1(fn))(fn, v_15151);
    env = stack[-2];
    stack[-1] = v_15151;
    goto v_15144;
v_15140:
    v_15151 = stack[-1];
    v_15151 = qcar(v_15151);
    fn = elt(env, 2); // rootextractf
    stack[0] = (*qfn1(fn))(fn, v_15151);
    env = stack[-2];
    goto v_15141;
v_15142:
    v_15151 = stack[-1];
    v_15151 = qcdr(v_15151);
    fn = elt(env, 2); // rootextractf
    v_15151 = (*qfn1(fn))(fn, v_15151);
    goto v_15143;
v_15144:
    goto v_15140;
v_15141:
    goto v_15142;
v_15143:
    {
        LispObject v_15155 = stack[0];
        return cons(v_15155, v_15151);
    }
    v_15151 = nil;
v_15128:
    return onevalue(v_15151);
}



// Code for can_be_proved

static LispObject CC_can_be_proved(LispObject env,
                         LispObject v_15125, LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15153, v_15154;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15125,v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15126;
    stack[-1] = v_15125;
// end of prologue
v_15130:
    v_15153 = stack[-1];
    if (v_15153 == nil) goto v_15133;
    else goto v_15134;
v_15133:
    v_15153 = lisp_true;
    goto v_15129;
v_15134:
    goto v_15144;
v_15140:
    v_15153 = stack[-1];
    v_15154 = qcar(v_15153);
    goto v_15141;
v_15142:
    v_15153 = stack[0];
    goto v_15143;
v_15144:
    goto v_15140;
v_15141:
    goto v_15142;
v_15143:
    fn = elt(env, 1); // can_be_p
    v_15153 = (*qfn2(fn))(fn, v_15154, v_15153);
    env = stack[-2];
    if (v_15153 == nil) goto v_15138;
    v_15153 = stack[-1];
    v_15153 = qcdr(v_15153);
    stack[-1] = v_15153;
    goto v_15130;
v_15138:
    v_15153 = nil;
    goto v_15129;
    v_15153 = nil;
v_15129:
    return onevalue(v_15153);
}



// Code for extract_dummy_ids

static LispObject CC_extract_dummy_ids(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15164, v_15165, v_15166;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15125;
// end of prologue
    v_15166 = nil;
v_15130:
    v_15164 = stack[0];
    if (v_15164 == nil) goto v_15133;
    else goto v_15134;
v_15133:
    v_15164 = v_15166;
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_15164);
    }
v_15134:
    goto v_15144;
v_15140:
    v_15164 = stack[0];
    v_15165 = qcar(v_15164);
    goto v_15141;
v_15142:
    v_15164 = qvalue(elt(env, 1)); // dummy_id!*
    goto v_15143;
v_15144:
    goto v_15140;
v_15141:
    goto v_15142;
v_15143:
    v_15164 = Lmemq(nil, v_15165, v_15164);
    if (v_15164 == nil) goto v_15139;
    goto v_15154;
v_15150:
    v_15164 = stack[0];
    v_15164 = qcar(v_15164);
    goto v_15151;
v_15152:
    v_15165 = v_15166;
    goto v_15153;
v_15154:
    goto v_15150;
v_15151:
    goto v_15152;
v_15153:
    v_15164 = cons(v_15164, v_15165);
    env = stack[-1];
    v_15166 = v_15164;
    v_15164 = stack[0];
    v_15164 = qcdr(v_15164);
    stack[0] = v_15164;
    goto v_15130;
v_15139:
    v_15164 = stack[0];
    v_15164 = qcdr(v_15164);
    stack[0] = v_15164;
    goto v_15130;
    v_15164 = nil;
    return onevalue(v_15164);
}



// Code for evaluate!-mod!-p

static LispObject CC_evaluateKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15248, v_15249, v_15250, v_15251, v_15252;
    LispObject fn;
    LispObject v_15127, v_15126, v_15125;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "evaluate-mod-p");
    va_start(aa, nargs);
    v_15125 = va_arg(aa, LispObject);
    v_15126 = va_arg(aa, LispObject);
    v_15127 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15127,v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15125,v_15126,v_15127);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15127;
    stack[-1] = v_15126;
    stack[-2] = v_15125;
// end of prologue
v_15131:
    v_15248 = stack[-2];
    if (!consp(v_15248)) goto v_15138;
    else goto v_15139;
v_15138:
    v_15248 = lisp_true;
    goto v_15137;
v_15139:
    v_15248 = stack[-2];
    v_15248 = qcar(v_15248);
    v_15248 = (consp(v_15248) ? nil : lisp_true);
    goto v_15137;
    v_15248 = nil;
v_15137:
    if (v_15248 == nil) goto v_15135;
    v_15248 = stack[-2];
    goto v_15130;
v_15135:
    goto v_15154;
v_15150:
    v_15249 = stack[0];
    goto v_15151;
v_15152:
    v_15248 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15153;
v_15154:
    goto v_15150;
v_15151:
    goto v_15152;
v_15153:
    if (v_15249 == v_15248) goto v_15148;
    else goto v_15149;
v_15148:
    v_15248 = nil;
    stack[0] = v_15248;
    goto v_15131;
v_15149:
    v_15248 = stack[-1];
    if (v_15248 == nil) goto v_15158;
    else goto v_15159;
v_15158:
    v_15248 = elt(env, 1); // "Variable=NIL in evaluate-mod-p"
    {
        fn = elt(env, 2); // errorf
        return (*qfn1(fn))(fn, v_15248);
    }
v_15159:
    goto v_15169;
v_15165:
    v_15248 = stack[-2];
    v_15248 = qcar(v_15248);
    v_15248 = qcar(v_15248);
    v_15249 = qcar(v_15248);
    goto v_15166;
v_15167:
    v_15248 = stack[-1];
    goto v_15168;
v_15169:
    goto v_15165;
v_15166:
    goto v_15167;
v_15168:
    if (equal(v_15249, v_15248)) goto v_15163;
    else goto v_15164;
v_15163:
    goto v_15186;
v_15176:
    v_15248 = stack[-2];
    v_15248 = qcar(v_15248);
    v_15252 = qcdr(v_15248);
    goto v_15177;
v_15178:
    v_15248 = stack[-2];
    v_15248 = qcar(v_15248);
    v_15248 = qcar(v_15248);
    v_15251 = qcdr(v_15248);
    goto v_15179;
v_15180:
    v_15248 = stack[-2];
    v_15250 = qcdr(v_15248);
    goto v_15181;
v_15182:
    v_15249 = stack[0];
    goto v_15183;
v_15184:
    v_15248 = stack[-1];
    goto v_15185;
v_15186:
    goto v_15176;
v_15177:
    goto v_15178;
v_15179:
    goto v_15180;
v_15181:
    goto v_15182;
v_15183:
    goto v_15184;
v_15185:
    {
        fn = elt(env, 3); // horner!-rule!-mod!-p
        return (*qfnn(fn))(fn, 5, v_15252, v_15251, v_15250, v_15249, v_15248);
    }
v_15164:
    goto v_15207;
v_15201:
    v_15248 = stack[-2];
    v_15248 = qcar(v_15248);
    v_15250 = qcdr(v_15248);
    goto v_15202;
v_15203:
    v_15249 = stack[-1];
    goto v_15204;
v_15205:
    v_15248 = stack[0];
    goto v_15206;
v_15207:
    goto v_15201;
v_15202:
    goto v_15203;
v_15204:
    goto v_15205;
v_15206:
    stack[-3] = CC_evaluateKmodKp(elt(env, 0), 3, v_15250, v_15249, v_15248);
    env = stack[-4];
    goto v_15220;
v_15214:
    v_15248 = stack[-2];
    v_15250 = qcdr(v_15248);
    goto v_15215;
v_15216:
    v_15249 = stack[-1];
    goto v_15217;
v_15218:
    v_15248 = stack[0];
    goto v_15219;
v_15220:
    goto v_15214;
v_15215:
    goto v_15216;
v_15217:
    goto v_15218;
v_15219:
    v_15248 = CC_evaluateKmodKp(elt(env, 0), 3, v_15250, v_15249, v_15248);
    v_15249 = stack[-3];
    v_15250 = v_15249;
    if (v_15250 == nil) goto v_15229;
    else goto v_15230;
v_15229:
    goto v_15228;
v_15230:
    goto v_15242;
v_15236:
    v_15250 = stack[-2];
    v_15250 = qcar(v_15250);
    v_15250 = qcar(v_15250);
    goto v_15237;
v_15238:
    goto v_15239;
v_15240:
    goto v_15241;
v_15242:
    goto v_15236;
v_15237:
    goto v_15238;
v_15239:
    goto v_15240;
v_15241:
    return acons(v_15250, v_15249, v_15248);
    v_15248 = nil;
v_15228:
    goto v_15130;
    v_15248 = nil;
v_15130:
    return onevalue(v_15248);
}



// Code for hasarg

static LispObject CC_hasarg(LispObject env,
                         LispObject v_15125, LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15184, v_15185, v_15186;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15125,v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15126;
    stack[-1] = v_15125;
// end of prologue
    goto v_15133;
v_15129:
    v_15185 = stack[-1];
    goto v_15130;
v_15131:
    v_15184 = qvalue(elt(env, 1)); // haveargs!*
    goto v_15132;
v_15133:
    goto v_15129;
v_15130:
    goto v_15131;
v_15132:
    v_15184 = cons(v_15185, v_15184);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_15184; // haveargs!*
    goto v_15145;
v_15141:
    v_15185 = stack[0];
    goto v_15142;
v_15143:
    v_15184 = qvalue(elt(env, 2)); // maxarg!*
    goto v_15144;
v_15145:
    goto v_15141;
v_15142:
    goto v_15143;
v_15144:
    v_15184 = (LispObject)greaterp2(v_15185, v_15184);
    v_15184 = v_15184 ? lisp_true : nil;
    env = stack[-2];
    if (v_15184 == nil) goto v_15139;
    v_15184 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 8); // qerline
    v_15184 = (*qfn1(fn))(fn, v_15184);
    env = stack[-2];
    v_15184 = elt(env, 3); // "**** "
    v_15184 = Lprinc(nil, v_15184);
    env = stack[-2];
    v_15184 = stack[-1];
    v_15184 = Lprin(nil, v_15184);
    env = stack[-2];
    v_15184 = elt(env, 4); // " has "
    v_15184 = Lprinc(nil, v_15184);
    env = stack[-2];
    v_15184 = stack[0];
    v_15184 = Lprinc(nil, v_15184);
    env = stack[-2];
    v_15184 = elt(env, 5); // " arguments"
    v_15184 = Lprinc(nil, v_15184);
    env = stack[-2];
    v_15184 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 9); // newline
    v_15184 = (*qfn1(fn))(fn, v_15184);
    env = stack[-2];
    goto v_15137;
v_15139:
v_15137:
    goto v_15170;
v_15166:
    v_15185 = stack[-1];
    goto v_15167;
v_15168:
    v_15184 = elt(env, 6); // bldmsg
    goto v_15169;
v_15170:
    goto v_15166;
v_15167:
    goto v_15168;
v_15169:
    if (v_15185 == v_15184) goto v_15165;
    goto v_15180;
v_15174:
    v_15185 = stack[-1];
    goto v_15175;
v_15176:
    v_15186 = elt(env, 7); // number!-of!-args
    goto v_15177;
v_15178:
    v_15184 = stack[0];
    goto v_15179;
v_15180:
    goto v_15174;
v_15175:
    goto v_15176;
v_15177:
    goto v_15178;
v_15179:
        return Lputprop(nil, 3, v_15185, v_15186, v_15184);
v_15165:
    v_15184 = nil;
    return onevalue(v_15184);
}



// Code for createtriplewithancestor

static LispObject CC_createtriplewithancestor(LispObject env,
                         LispObject v_15125, LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15177, v_15178, v_15179;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15125,v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15126;
    stack[-1] = v_15125;
// end of prologue
    v_15177 = (LispObject)48+TAG_FIXNUM; // 3
    v_15177 = Lmkvect(nil, v_15177);
    env = stack[-3];
    stack[-2] = v_15177;
    goto v_15139;
v_15133:
    v_15179 = stack[-2];
    goto v_15134;
v_15135:
    v_15178 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15136;
v_15137:
    v_15177 = qvalue(elt(env, 1)); // fluidbibasistripleid
    goto v_15138;
v_15139:
    goto v_15133;
v_15134:
    goto v_15135;
v_15136:
    goto v_15137;
v_15138:
    *(LispObject *)((char *)v_15179 + (CELL-TAG_VECTOR) + (((intptr_t)v_15178-TAG_FIXNUM)/(16/CELL))) = v_15177;
    goto v_15149;
v_15143:
    v_15179 = stack[-2];
    goto v_15144;
v_15145:
    v_15178 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15146;
v_15147:
    v_15177 = stack[-1];
    goto v_15148;
v_15149:
    goto v_15143;
v_15144:
    goto v_15145;
v_15146:
    goto v_15147;
v_15148:
    *(LispObject *)((char *)v_15179 + (CELL-TAG_VECTOR) + (((intptr_t)v_15178-TAG_FIXNUM)/(16/CELL))) = v_15177;
    goto v_15159;
v_15153:
    v_15179 = stack[-2];
    goto v_15154;
v_15155:
    v_15178 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_15156;
v_15157:
    v_15177 = stack[0];
    goto v_15158;
v_15159:
    goto v_15153;
v_15154:
    goto v_15155;
v_15156:
    goto v_15157;
v_15158:
    *(LispObject *)((char *)v_15179 + (CELL-TAG_VECTOR) + (((intptr_t)v_15178-TAG_FIXNUM)/(16/CELL))) = v_15177;
    goto v_15169;
v_15163:
    stack[-1] = stack[-2];
    goto v_15164;
v_15165:
    stack[0] = (LispObject)48+TAG_FIXNUM; // 3
    goto v_15166;
v_15167:
    v_15177 = nil;
    v_15177 = ncons(v_15177);
    env = stack[-3];
    goto v_15168;
v_15169:
    goto v_15163;
v_15164:
    goto v_15165;
v_15166:
    goto v_15167;
v_15168:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_15177;
    v_15177 = qvalue(elt(env, 1)); // fluidbibasistripleid
    v_15177 = (LispObject)((intptr_t)(v_15177) + 0x10);
    qvalue(elt(env, 1)) = v_15177; // fluidbibasistripleid
    v_15177 = stack[-2];
    return onevalue(v_15177);
}



// Code for ofsf_negateat

static LispObject CC_ofsf_negateat(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15157, v_15158, v_15159;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15125;
// end of prologue
    goto v_15132;
v_15128:
    v_15157 = stack[0];
    v_15157 = qcdr(v_15157);
    v_15158 = qcar(v_15157);
    goto v_15129;
v_15130:
    v_15157 = stack[0];
    v_15157 = qcdr(v_15157);
    v_15157 = qcdr(v_15157);
    v_15157 = qcar(v_15157);
    goto v_15131;
v_15132:
    goto v_15128;
v_15129:
    goto v_15130;
v_15131:
    v_15157 = list2(v_15158, v_15157);
    env = stack[-2];
    stack[-1] = v_15157;
    goto v_15148;
v_15142:
    v_15157 = stack[0];
    v_15157 = qcar(v_15157);
    fn = elt(env, 1); // ofsf_lnegrel
    v_15159 = (*qfn1(fn))(fn, v_15157);
    goto v_15143;
v_15144:
    v_15157 = stack[-1];
    v_15158 = qcar(v_15157);
    goto v_15145;
v_15146:
    v_15157 = stack[-1];
    v_15157 = qcdr(v_15157);
    v_15157 = qcar(v_15157);
    goto v_15147;
v_15148:
    goto v_15142;
v_15143:
    goto v_15144;
v_15145:
    goto v_15146;
v_15147:
    return list3(v_15159, v_15158, v_15157);
}



// Code for get!-free!-form

static LispObject CC_getKfreeKform(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15202, v_15203, v_15204;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_15125;
// end of prologue
    stack[-2] = nil;
    goto v_15139;
v_15135:
    v_15203 = stack[-1];
    goto v_15136;
v_15137:
    v_15202 = qvalue(elt(env, 1)); // frasc!*
    goto v_15138;
v_15139:
    goto v_15135;
v_15136:
    goto v_15137;
v_15138:
    v_15202 = Latsoc(nil, v_15203, v_15202);
    stack[0] = v_15202;
    if (v_15202 == nil) goto v_15134;
    v_15202 = stack[0];
    v_15202 = qcdr(v_15202);
    goto v_15130;
v_15134:
    goto v_15154;
v_15150:
    v_15203 = stack[-1];
    goto v_15151;
v_15152:
    v_15202 = elt(env, 2); // !~
    goto v_15153;
v_15154:
    goto v_15150;
v_15151:
    goto v_15152;
v_15153:
    if (!consp(v_15203)) goto v_15148;
    v_15203 = qcar(v_15203);
    if (v_15203 == v_15202) goto v_15147;
    else goto v_15148;
v_15147:
    v_15202 = stack[-1];
    v_15202 = qcdr(v_15202);
    v_15202 = qcar(v_15202);
    stack[-1] = v_15202;
    v_15202 = elt(env, 3); // (!! !~ !! !~)
    stack[0] = v_15202;
    v_15202 = lisp_true;
    stack[-2] = v_15202;
    goto v_15146;
v_15148:
    v_15202 = elt(env, 4); // (!! !~)
    stack[0] = v_15202;
    goto v_15146;
v_15146:
    goto v_15172;
v_15168:
    goto v_15169;
v_15170:
    v_15202 = stack[-1];
    v_15202 = Lexplode(nil, v_15202);
    env = stack[-3];
    goto v_15171;
v_15172:
    goto v_15168;
v_15169:
    goto v_15170;
v_15171:
    v_15202 = Lappend(nil, stack[0], v_15202);
    env = stack[-3];
    v_15202 = Lcompress(nil, v_15202);
    env = stack[-3];
    v_15202 = Lintern(nil, v_15202);
    env = stack[-3];
    stack[0] = v_15202;
    goto v_15183;
v_15177:
    v_15204 = stack[-1];
    goto v_15178;
v_15179:
    v_15203 = stack[0];
    goto v_15180;
v_15181:
    v_15202 = qvalue(elt(env, 1)); // frasc!*
    goto v_15182;
v_15183:
    goto v_15177;
v_15178:
    goto v_15179;
v_15180:
    goto v_15181;
v_15182:
    v_15202 = acons(v_15204, v_15203, v_15202);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_15202; // frasc!*
    v_15202 = stack[-2];
    if (v_15202 == nil) goto v_15190;
    goto v_15197;
v_15193:
    v_15202 = stack[0];
    v_15203 = ncons(v_15202);
    env = stack[-3];
    goto v_15194;
v_15195:
    v_15202 = elt(env, 5); // optional
    goto v_15196;
v_15197:
    goto v_15193;
v_15194:
    goto v_15195;
v_15196:
    v_15202 = Lflag(nil, v_15203, v_15202);
    goto v_15188;
v_15190:
v_15188:
    v_15202 = stack[0];
v_15130:
    return onevalue(v_15202);
}



// Code for matpri

static LispObject CC_matpri(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15136, v_15137;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15136 = v_15125;
// end of prologue
    goto v_15132;
v_15128:
    v_15137 = qcdr(v_15136);
    goto v_15129;
v_15130:
    v_15136 = nil;
    goto v_15131;
v_15132:
    goto v_15128;
v_15129:
    goto v_15130;
v_15131:
    {
        fn = elt(env, 1); // matpri1
        return (*qfn2(fn))(fn, v_15137, v_15136);
    }
}



// Code for talp_telp

static LispObject CC_talp_telp(LispObject env,
                         LispObject v_15125, LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15179, v_15180;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15125,v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15126;
    stack[-1] = v_15125;
// end of prologue
    stack[-2] = nil;
    v_15179 = stack[0];
    if (!consp(v_15179)) goto v_15133;
    else goto v_15134;
v_15133:
    goto v_15140;
v_15136:
    v_15180 = stack[-1];
    goto v_15137;
v_15138:
    v_15179 = stack[0];
    goto v_15139;
v_15140:
    goto v_15136;
v_15137:
    goto v_15138;
v_15139:
    v_15179 = (v_15180 == v_15179 ? lisp_true : nil);
    goto v_15130;
v_15134:
    v_15179 = stack[0];
    fn = elt(env, 1); // talp_invp
    v_15179 = (*qfn1(fn))(fn, v_15179);
    env = stack[-3];
    if (v_15179 == nil) goto v_15144;
    else goto v_15145;
v_15144:
    v_15179 = stack[0];
    fn = elt(env, 2); // talp_fargl
    v_15179 = (*qfn1(fn))(fn, v_15179);
    env = stack[-3];
    stack[0] = v_15179;
v_15152:
    v_15179 = stack[-2];
    if (v_15179 == nil) goto v_15159;
    else goto v_15160;
v_15159:
    v_15179 = stack[0];
    goto v_15158;
v_15160:
    v_15179 = nil;
    goto v_15158;
    v_15179 = nil;
v_15158:
    if (v_15179 == nil) goto v_15155;
    else goto v_15156;
v_15155:
    goto v_15151;
v_15156:
    goto v_15172;
v_15168:
    v_15180 = stack[-1];
    goto v_15169;
v_15170:
    v_15179 = stack[0];
    v_15179 = qcar(v_15179);
    goto v_15171;
v_15172:
    goto v_15168;
v_15169:
    goto v_15170;
v_15171:
    v_15179 = CC_talp_telp(elt(env, 0), v_15180, v_15179);
    env = stack[-3];
    stack[-2] = v_15179;
    v_15179 = stack[0];
    v_15179 = qcdr(v_15179);
    stack[0] = v_15179;
    goto v_15152;
v_15151:
    v_15179 = stack[-2];
    goto v_15130;
v_15145:
    v_15179 = nil;
v_15130:
    return onevalue(v_15179);
}



// Code for fctrf1

static LispObject CC_fctrf1(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15365, v_15366;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_15125;
// end of prologue
    stack[-1] = nil;
    v_15365 = stack[-3];
    if (!consp(v_15365)) goto v_15138;
    else goto v_15139;
v_15138:
    v_15365 = lisp_true;
    goto v_15137;
v_15139:
    v_15365 = stack[-3];
    v_15365 = qcar(v_15365);
    v_15365 = (consp(v_15365) ? nil : lisp_true);
    goto v_15137;
    v_15365 = nil;
v_15137:
    if (v_15365 == nil) goto v_15135;
    v_15365 = stack[-3];
    return ncons(v_15365);
v_15135:
    v_15365 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_15365)) v_15365 = nil;
    else { v_15365 = qfastgets(v_15365);
           if (v_15365 != nil) { v_15365 = elt(v_15365, 3); // field
#ifdef RECORD_GET
             if (v_15365 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_15365 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_15365 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_15365 == SPID_NOPROP) v_15365 = nil; else v_15365 = lisp_true; }}
#endif
    if (v_15365 == nil) goto v_15156;
    goto v_15164;
v_15160:
    v_15365 = stack[-3];
    fn = elt(env, 3); // lnc
    v_15366 = (*qfn1(fn))(fn, v_15365);
    env = stack[-5];
    stack[-1] = v_15366;
    goto v_15161;
v_15162:
    v_15365 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15163;
v_15164:
    goto v_15160;
v_15161:
    goto v_15162;
v_15163:
    v_15365 = Lneq(nil, v_15366, v_15365);
    env = stack[-5];
    goto v_15154;
v_15156:
    v_15365 = nil;
    goto v_15154;
    v_15365 = nil;
v_15154:
    if (v_15365 == nil) goto v_15152;
    goto v_15176;
v_15172:
    v_15365 = stack[-1];
    fn = elt(env, 4); // !:recip
    v_15366 = (*qfn1(fn))(fn, v_15365);
    env = stack[-5];
    goto v_15173;
v_15174:
    v_15365 = stack[-3];
    goto v_15175;
v_15176:
    goto v_15172;
v_15173:
    goto v_15174;
v_15175:
    fn = elt(env, 5); // multd
    v_15365 = (*qfn2(fn))(fn, v_15366, v_15365);
    env = stack[-5];
    stack[-3] = v_15365;
    goto v_15150;
v_15152:
    v_15365 = qvalue(elt(env, 1)); // dmode!*
    if (v_15365 == nil) goto v_15181;
    goto v_15190;
v_15186:
    v_15366 = qvalue(elt(env, 1)); // dmode!*
    goto v_15187;
v_15188:
    v_15365 = elt(env, 2); // unitsfn
    goto v_15189;
v_15190:
    goto v_15186;
v_15187:
    goto v_15188;
v_15189:
    v_15365 = get(v_15366, v_15365);
    env = stack[-5];
    stack[-2] = v_15365;
    if (v_15365 == nil) goto v_15181;
    goto v_15200;
v_15194:
    stack[-1] = stack[-2];
    goto v_15195;
v_15196:
    goto v_15207;
v_15203:
    v_15366 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15204;
v_15205:
    v_15365 = stack[-3];
    goto v_15206;
v_15207:
    goto v_15203;
v_15204:
    goto v_15205;
v_15206:
    stack[0] = cons(v_15366, v_15365);
    env = stack[-5];
    goto v_15197;
v_15198:
    v_15365 = stack[-3];
    fn = elt(env, 3); // lnc
    v_15365 = (*qfn1(fn))(fn, v_15365);
    env = stack[-5];
    goto v_15199;
v_15200:
    goto v_15194;
v_15195:
    goto v_15196;
v_15197:
    goto v_15198;
v_15199:
    v_15365 = Lapply2(nil, 3, stack[-1], stack[0], v_15365);
    env = stack[-5];
    stack[-4] = v_15365;
    v_15365 = stack[-4];
    v_15365 = qcdr(v_15365);
    stack[-3] = v_15365;
    v_15365 = stack[-4];
    v_15365 = qcar(v_15365);
    fn = elt(env, 4); // !:recip
    v_15365 = (*qfn1(fn))(fn, v_15365);
    env = stack[-5];
    stack[-1] = v_15365;
    goto v_15150;
v_15181:
v_15150:
    v_15365 = stack[-3];
    fn = elt(env, 6); // comfac
    v_15365 = (*qfn1(fn))(fn, v_15365);
    env = stack[-5];
    stack[-4] = v_15365;
    goto v_15224;
v_15220:
    stack[0] = stack[-3];
    goto v_15221;
v_15222:
    v_15365 = stack[-4];
    fn = elt(env, 7); // comfac!-to!-poly
    v_15365 = (*qfn1(fn))(fn, v_15365);
    env = stack[-5];
    goto v_15223;
v_15224:
    goto v_15220;
v_15221:
    goto v_15222;
v_15223:
    fn = elt(env, 8); // quotf
    v_15365 = (*qfn2(fn))(fn, stack[0], v_15365);
    env = stack[-5];
    stack[-3] = v_15365;
    v_15365 = stack[-4];
    v_15365 = qcdr(v_15365);
    v_15365 = CC_fctrf1(elt(env, 0), v_15365);
    env = stack[-5];
    stack[-2] = v_15365;
    v_15365 = stack[-4];
    v_15365 = qcar(v_15365);
    if (v_15365 == nil) goto v_15234;
    goto v_15244;
v_15238:
    v_15365 = stack[-2];
    stack[0] = qcar(v_15365);
    goto v_15239;
v_15240:
    goto v_15252;
v_15248:
    goto v_15259;
v_15255:
    goto v_15265;
v_15261:
    v_15365 = stack[-4];
    v_15365 = qcar(v_15365);
    v_15366 = qcar(v_15365);
    goto v_15262;
v_15263:
    v_15365 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15264;
v_15265:
    goto v_15261;
v_15262:
    goto v_15263;
v_15264:
    fn = elt(env, 9); // to
    v_15366 = (*qfn2(fn))(fn, v_15366, v_15365);
    env = stack[-5];
    goto v_15256;
v_15257:
    v_15365 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15258;
v_15259:
    goto v_15255;
v_15256:
    goto v_15257;
v_15258:
    v_15365 = cons(v_15366, v_15365);
    env = stack[-5];
    v_15366 = ncons(v_15365);
    env = stack[-5];
    goto v_15249;
v_15250:
    v_15365 = stack[-4];
    v_15365 = qcar(v_15365);
    v_15365 = qcdr(v_15365);
    goto v_15251;
v_15252:
    goto v_15248;
v_15249:
    goto v_15250;
v_15251:
    v_15366 = cons(v_15366, v_15365);
    env = stack[-5];
    goto v_15241;
v_15242:
    v_15365 = stack[-2];
    v_15365 = qcdr(v_15365);
    goto v_15243;
v_15244:
    goto v_15238;
v_15239:
    goto v_15240;
v_15241:
    goto v_15242;
v_15243:
    v_15365 = list2star(stack[0], v_15366, v_15365);
    env = stack[-5];
    stack[-2] = v_15365;
    goto v_15232;
v_15234:
v_15232:
    v_15365 = stack[-1];
    if (v_15365 == nil) goto v_15279;
    goto v_15287;
v_15283:
    v_15366 = stack[-1];
    goto v_15284;
v_15285:
    v_15365 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15286;
v_15287:
    goto v_15283;
v_15284:
    goto v_15285;
v_15286:
    if (v_15366 == v_15365) goto v_15279;
    goto v_15295;
v_15291:
    goto v_15301;
v_15297:
    v_15366 = stack[-1];
    goto v_15298;
v_15299:
    v_15365 = stack[-2];
    v_15365 = qcar(v_15365);
    goto v_15300;
v_15301:
    goto v_15297;
v_15298:
    goto v_15299;
v_15300:
    fn = elt(env, 5); // multd
    v_15366 = (*qfn2(fn))(fn, v_15366, v_15365);
    env = stack[-5];
    goto v_15292;
v_15293:
    v_15365 = stack[-2];
    v_15365 = qcdr(v_15365);
    goto v_15294;
v_15295:
    goto v_15291;
v_15292:
    goto v_15293;
v_15294:
    v_15365 = cons(v_15366, v_15365);
    env = stack[-5];
    stack[-2] = v_15365;
    goto v_15277;
v_15279:
v_15277:
    v_15365 = stack[-3];
    if (!consp(v_15365)) goto v_15313;
    else goto v_15314;
v_15313:
    v_15365 = lisp_true;
    goto v_15312;
v_15314:
    v_15365 = stack[-3];
    v_15365 = qcar(v_15365);
    v_15365 = (consp(v_15365) ? nil : lisp_true);
    goto v_15312;
    v_15365 = nil;
v_15312:
    if (v_15365 == nil) goto v_15310;
    goto v_15327;
v_15323:
    goto v_15333;
v_15329:
    v_15366 = stack[-3];
    goto v_15330;
v_15331:
    v_15365 = stack[-2];
    v_15365 = qcar(v_15365);
    goto v_15332;
v_15333:
    goto v_15329;
v_15330:
    goto v_15331;
v_15332:
    fn = elt(env, 10); // multf
    v_15366 = (*qfn2(fn))(fn, v_15366, v_15365);
    goto v_15324;
v_15325:
    v_15365 = stack[-2];
    v_15365 = qcdr(v_15365);
    goto v_15326;
v_15327:
    goto v_15323;
v_15324:
    goto v_15325;
v_15326:
    return cons(v_15366, v_15365);
v_15310:
    v_15365 = stack[-3];
    fn = elt(env, 11); // minusf
    v_15365 = (*qfn1(fn))(fn, v_15365);
    env = stack[-5];
    if (v_15365 == nil) goto v_15340;
    v_15365 = stack[-3];
    fn = elt(env, 12); // negf
    v_15365 = (*qfn1(fn))(fn, v_15365);
    env = stack[-5];
    stack[-3] = v_15365;
    goto v_15350;
v_15346:
    v_15365 = stack[-2];
    v_15365 = qcar(v_15365);
    fn = elt(env, 12); // negf
    v_15366 = (*qfn1(fn))(fn, v_15365);
    env = stack[-5];
    goto v_15347;
v_15348:
    v_15365 = stack[-2];
    v_15365 = qcdr(v_15365);
    goto v_15349;
v_15350:
    goto v_15346;
v_15347:
    goto v_15348;
v_15349:
    v_15365 = cons(v_15366, v_15365);
    env = stack[-5];
    stack[-2] = v_15365;
    goto v_15308;
v_15340:
v_15308:
    goto v_15361;
v_15357:
    v_15365 = stack[-3];
    fn = elt(env, 13); // factor!-prim!-f
    v_15366 = (*qfn1(fn))(fn, v_15365);
    env = stack[-5];
    goto v_15358;
v_15359:
    v_15365 = stack[-2];
    goto v_15360;
v_15361:
    goto v_15357;
v_15358:
    goto v_15359;
v_15360:
    {
        fn = elt(env, 14); // fac!-merge
        return (*qfn2(fn))(fn, v_15366, v_15365);
    }
    return onevalue(v_15365);
}



// Code for ofsf_updsigndom

static LispObject CC_ofsf_updsigndom(LispObject env,
                         LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15171, v_15172;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15126);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_15171 = v_15126;
// end of prologue
// Binding d
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_15171; // d
    v_15171 = qvalue(elt(env, 1)); // d
    if (v_15171 == nil) goto v_15134;
    else goto v_15135;
v_15134:
    v_15171 = elt(env, 2); // equal
    goto v_15133;
v_15135:
    goto v_15145;
v_15141:
    v_15172 = qvalue(elt(env, 1)); // d
    goto v_15142;
v_15143:
    v_15171 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15144;
v_15145:
    goto v_15141;
v_15142:
    goto v_15143;
v_15144:
    v_15171 = (LispObject)greaterp2(v_15172, v_15171);
    v_15171 = v_15171 ? lisp_true : nil;
    env = stack[-1];
    if (v_15171 == nil) goto v_15139;
    v_15171 = elt(env, 3); // greaterp
    goto v_15133;
v_15139:
    goto v_15156;
v_15152:
    v_15172 = qvalue(elt(env, 1)); // d
    goto v_15153;
v_15154:
    v_15171 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15155;
v_15156:
    goto v_15152;
v_15153:
    goto v_15154;
v_15155:
    v_15171 = (LispObject)lessp2(v_15172, v_15171);
    v_15171 = v_15171 ? lisp_true : nil;
    env = stack[-1];
    if (v_15171 == nil) goto v_15150;
    v_15171 = elt(env, 4); // lessp
    goto v_15133;
v_15150:
    goto v_15168;
v_15164:
    v_15172 = elt(env, 5); // "something wrong in ofsf_updSignDom:"
    goto v_15165;
v_15166:
    v_15171 = qvalue(elt(env, 1)); // d
    goto v_15167;
v_15168:
    goto v_15164;
v_15165:
    goto v_15166;
v_15167:
    v_15171 = list2(v_15172, v_15171);
    env = stack[-1];
    fn = elt(env, 6); // rederr
    v_15171 = (*qfn1(fn))(fn, v_15171);
    goto v_15133;
    v_15171 = nil;
v_15133:
    ;}  // end of a binding scope
    return onevalue(v_15171);
}



// Code for oldmtch

static LispObject CC_oldmtch(LispObject env,
                         LispObject v_15125, LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15198, v_15199, v_15200;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15125,v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_15126;
    stack[-2] = v_15125;
// end of prologue
    stack[-3] = nil;
    goto v_15139;
v_15133:
    v_15198 = stack[-2];
    v_15200 = qcdr(v_15198);
    goto v_15134;
v_15135:
    v_15198 = stack[-1];
    v_15199 = qcar(v_15198);
    goto v_15136;
v_15137:
    v_15198 = stack[-2];
    v_15198 = qcar(v_15198);
    goto v_15138;
v_15139:
    goto v_15133;
v_15134:
    goto v_15135;
v_15136:
    goto v_15137;
v_15138:
    fn = elt(env, 1); // mcharg
    v_15198 = (*qfnn(fn))(fn, 3, v_15200, v_15199, v_15198);
    env = stack[-4];
    stack[0] = v_15198;
v_15148:
    v_15198 = stack[0];
    if (v_15198 == nil) goto v_15151;
    v_15198 = stack[-3];
    if (v_15198 == nil) goto v_15155;
    else goto v_15151;
v_15155:
    goto v_15152;
v_15151:
    goto v_15147;
v_15152:
    goto v_15168;
v_15164:
    v_15198 = stack[0];
    v_15199 = qcar(v_15198);
    goto v_15165;
v_15166:
    v_15198 = stack[-1];
    v_15198 = qcdr(v_15198);
    v_15198 = qcar(v_15198);
    v_15198 = qcdr(v_15198);
    goto v_15167;
v_15168:
    goto v_15164;
v_15165:
    goto v_15166;
v_15167:
    v_15198 = Lsubla(nil, v_15199, v_15198);
    env = stack[-4];
    fn = elt(env, 2); // eval
    v_15198 = (*qfn1(fn))(fn, v_15198);
    env = stack[-4];
    if (v_15198 == nil) goto v_15161;
    goto v_15180;
v_15176:
    v_15198 = stack[0];
    v_15199 = qcar(v_15198);
    goto v_15177;
v_15178:
    v_15198 = stack[-1];
    v_15198 = qcdr(v_15198);
    v_15198 = qcdr(v_15198);
    v_15198 = qcar(v_15198);
    goto v_15179;
v_15180:
    goto v_15176;
v_15177:
    goto v_15178;
v_15179:
    v_15198 = Lsubla(nil, v_15199, v_15198);
    env = stack[-4];
    goto v_15159;
v_15161:
    v_15198 = nil;
v_15159:
    stack[-3] = v_15198;
    v_15198 = stack[0];
    v_15198 = qcdr(v_15198);
    stack[0] = v_15198;
    goto v_15148;
v_15147:
    v_15198 = stack[-3];
    if (v_15198 == nil) goto v_15192;
    v_15198 = stack[-3];
    goto v_15190;
v_15192:
    v_15198 = stack[-2];
    goto v_15190;
    v_15198 = nil;
v_15190:
    return onevalue(v_15198);
}



// Code for indxchk

static LispObject CC_indxchk(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15198, v_15199;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_15198 = v_15125;
// end of prologue
    stack[-1] = v_15198;
    goto v_15138;
v_15134:
    v_15199 = qvalue(elt(env, 1)); // indxl!*
    goto v_15135;
v_15136:
    v_15198 = qvalue(elt(env, 2)); // nosuml!*
    goto v_15137;
v_15138:
    goto v_15134;
v_15135:
    goto v_15136;
v_15137:
    fn = elt(env, 3); // union
    v_15198 = (*qfn2(fn))(fn, v_15199, v_15198);
    env = stack[-2];
    stack[0] = v_15198;
v_15131:
    v_15198 = stack[-1];
    if (v_15198 == nil) goto v_15143;
    else goto v_15144;
v_15143:
    v_15198 = nil;
    goto v_15130;
v_15144:
    goto v_15155;
v_15151:
    v_15198 = stack[-1];
    v_15198 = qcar(v_15198);
    if (!consp(v_15198)) goto v_15158;
    else goto v_15159;
v_15158:
    v_15198 = stack[-1];
    v_15198 = qcar(v_15198);
    if (is_number(v_15198)) goto v_15164;
    else goto v_15165;
v_15164:
    v_15198 = stack[-1];
    v_15198 = qcar(v_15198);
    v_15198 = Labsval(nil, v_15198);
    env = stack[-2];
    fn = elt(env, 4); // !*num2id
    v_15198 = (*qfn1(fn))(fn, v_15198);
    env = stack[-2];
    goto v_15163;
v_15165:
    v_15198 = stack[-1];
    v_15198 = qcar(v_15198);
    goto v_15163;
    v_15198 = nil;
v_15163:
    v_15199 = v_15198;
    goto v_15157;
v_15159:
    v_15198 = stack[-1];
    v_15198 = qcar(v_15198);
    v_15198 = qcdr(v_15198);
    v_15198 = qcar(v_15198);
    if (is_number(v_15198)) goto v_15176;
    else goto v_15177;
v_15176:
    v_15198 = stack[-1];
    v_15198 = qcar(v_15198);
    v_15198 = qcdr(v_15198);
    v_15198 = qcar(v_15198);
    fn = elt(env, 4); // !*num2id
    v_15198 = (*qfn1(fn))(fn, v_15198);
    env = stack[-2];
    v_15199 = v_15198;
    goto v_15157;
v_15177:
    v_15198 = stack[-1];
    v_15198 = qcar(v_15198);
    v_15198 = qcdr(v_15198);
    v_15198 = qcar(v_15198);
    v_15199 = v_15198;
    goto v_15157;
    v_15199 = nil;
v_15157:
    goto v_15152;
v_15153:
    v_15198 = stack[0];
    goto v_15154;
v_15155:
    goto v_15151;
v_15152:
    goto v_15153;
v_15154:
    v_15198 = Lmemq(nil, v_15199, v_15198);
    if (v_15198 == nil) goto v_15149;
    else goto v_15150;
v_15149:
    v_15198 = lisp_true;
    goto v_15130;
v_15150:
    v_15198 = stack[-1];
    v_15198 = qcdr(v_15198);
    stack[-1] = v_15198;
    goto v_15131;
v_15130:
    return onevalue(v_15198);
}



// Code for edge_new_parent

static LispObject CC_edge_new_parent(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15165, v_15166, v_15167;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15166 = v_15125;
// end of prologue
v_15124:
    v_15165 = v_15166;
    if (v_15165 == nil) goto v_15129;
    else goto v_15130;
v_15129:
    v_15165 = nil;
    goto v_15128;
v_15130:
    goto v_15139;
v_15135:
    v_15165 = v_15166;
    v_15167 = qcar(v_15165);
    goto v_15136;
v_15137:
    v_15165 = qvalue(elt(env, 1)); // new_edge_list
    goto v_15138;
v_15139:
    goto v_15135;
v_15136:
    goto v_15137;
v_15138:
    v_15165 = Lassoc(nil, v_15167, v_15165);
    v_15167 = v_15165;
    v_15165 = v_15167;
    if (v_15165 == nil) goto v_15148;
    goto v_15155;
v_15151:
    stack[0] = v_15167;
    goto v_15152;
v_15153:
    v_15165 = v_15166;
    v_15165 = qcdr(v_15165);
    v_15165 = CC_edge_new_parent(elt(env, 0), v_15165);
    goto v_15154;
v_15155:
    goto v_15151;
v_15152:
    goto v_15153;
v_15154:
    {
        LispObject v_15169 = stack[0];
        return cons(v_15169, v_15165);
    }
v_15148:
    v_15165 = v_15166;
    v_15165 = qcdr(v_15165);
    v_15166 = v_15165;
    goto v_15124;
    v_15165 = nil;
    goto v_15128;
    v_15165 = nil;
v_15128:
    return onevalue(v_15165);
}



// Code for pcdiv

static LispObject CC_pcdiv(LispObject env,
                         LispObject v_15125, LispObject v_15126)
{
    env = qenv(env);
    LispObject v_15200, v_15201;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15125,v_15126);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_15126;
    v_15200 = v_15125;
// end of prologue
    stack[-5] = v_15200;
    v_15200 = stack[-5];
    if (v_15200 == nil) goto v_15137;
    else goto v_15138;
v_15137:
    v_15200 = nil;
    goto v_15132;
v_15138:
    v_15200 = stack[-5];
    v_15200 = qcar(v_15200);
    v_15201 = v_15200;
    goto v_15150;
v_15146:
    v_15200 = v_15201;
    stack[0] = qcar(v_15200);
    goto v_15147;
v_15148:
    goto v_15158;
v_15154:
    v_15200 = v_15201;
    v_15201 = qcdr(v_15200);
    goto v_15155;
v_15156:
    v_15200 = stack[-4];
    goto v_15157;
v_15158:
    goto v_15154;
v_15155:
    goto v_15156;
v_15157:
    fn = elt(env, 1); // cdiv
    v_15200 = (*qfn2(fn))(fn, v_15201, v_15200);
    env = stack[-6];
    goto v_15149;
v_15150:
    goto v_15146;
v_15147:
    goto v_15148;
v_15149:
    v_15200 = cons(stack[0], v_15200);
    env = stack[-6];
    v_15200 = ncons(v_15200);
    env = stack[-6];
    stack[-2] = v_15200;
    stack[-3] = v_15200;
v_15133:
    v_15200 = stack[-5];
    v_15200 = qcdr(v_15200);
    stack[-5] = v_15200;
    v_15200 = stack[-5];
    if (v_15200 == nil) goto v_15166;
    else goto v_15167;
v_15166:
    v_15200 = stack[-3];
    goto v_15132;
v_15167:
    goto v_15175;
v_15171:
    stack[-1] = stack[-2];
    goto v_15172;
v_15173:
    v_15200 = stack[-5];
    v_15200 = qcar(v_15200);
    v_15201 = v_15200;
    goto v_15186;
v_15182:
    v_15200 = v_15201;
    stack[0] = qcar(v_15200);
    goto v_15183;
v_15184:
    goto v_15194;
v_15190:
    v_15200 = v_15201;
    v_15201 = qcdr(v_15200);
    goto v_15191;
v_15192:
    v_15200 = stack[-4];
    goto v_15193;
v_15194:
    goto v_15190;
v_15191:
    goto v_15192;
v_15193:
    fn = elt(env, 1); // cdiv
    v_15200 = (*qfn2(fn))(fn, v_15201, v_15200);
    env = stack[-6];
    goto v_15185;
v_15186:
    goto v_15182;
v_15183:
    goto v_15184;
v_15185:
    v_15200 = cons(stack[0], v_15200);
    env = stack[-6];
    v_15200 = ncons(v_15200);
    env = stack[-6];
    goto v_15174;
v_15175:
    goto v_15171;
v_15172:
    goto v_15173;
v_15174:
    v_15200 = Lrplacd(nil, stack[-1], v_15200);
    env = stack[-6];
    v_15200 = stack[-2];
    v_15200 = qcdr(v_15200);
    stack[-2] = v_15200;
    goto v_15133;
v_15132:
    return onevalue(v_15200);
}



// Code for sc_rep

static LispObject CC_sc_rep(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15138;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15138 = v_15125;
// end of prologue
    goto v_15131;
v_15127:
    stack[0] = qvalue(elt(env, 1)); // g_sc_ve
    goto v_15128;
v_15129:
    v_15138 = sub1(v_15138);
    goto v_15130;
v_15131:
    goto v_15127;
v_15128:
    goto v_15129;
v_15130:
    v_15138 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_15138-TAG_FIXNUM)/(16/CELL)));
    v_15138 = qcdr(v_15138);
    v_15138 = qcar(v_15138);
    return onevalue(v_15138);
}



// Code for gcd!-in!-vector

static LispObject CC_gcdKinKvector(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15402, v_15403, v_15404, v_15405, v_15406, v_15407;
    LispObject fn;
    LispObject v_15128, v_15127, v_15126, v_15125;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "gcd-in-vector");
    va_start(aa, nargs);
    v_15125 = va_arg(aa, LispObject);
    v_15126 = va_arg(aa, LispObject);
    v_15127 = va_arg(aa, LispObject);
    v_15128 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_15128,v_15127,v_15126,v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_15125,v_15126,v_15127,v_15128);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15128;
    stack[-1] = v_15127;
    stack[-2] = v_15126;
    stack[-3] = v_15125;
// end of prologue
    goto v_15146;
v_15142:
    v_15403 = stack[-2];
    goto v_15143;
v_15144:
    v_15402 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15145;
v_15146:
    goto v_15142;
v_15143:
    goto v_15144;
v_15145:
    if (v_15403 == v_15402) goto v_15140;
    else goto v_15141;
v_15140:
    v_15402 = lisp_true;
    goto v_15139;
v_15141:
    goto v_15156;
v_15152:
    v_15403 = stack[0];
    goto v_15153;
v_15154:
    v_15402 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15155;
v_15156:
    goto v_15152;
v_15153:
    goto v_15154;
v_15155:
    v_15402 = (v_15403 == v_15402 ? lisp_true : nil);
    goto v_15139;
    v_15402 = nil;
v_15139:
    if (v_15402 == nil) goto v_15137;
    goto v_15166;
v_15160:
    v_15404 = stack[-3];
    goto v_15161;
v_15162:
    v_15403 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15163;
v_15164:
    v_15402 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15165;
v_15166:
    goto v_15160;
v_15161:
    goto v_15162;
v_15163:
    goto v_15164;
v_15165:
    *(LispObject *)((char *)v_15404 + (CELL-TAG_VECTOR) + (((intptr_t)v_15403-TAG_FIXNUM)/(16/CELL))) = v_15402;
    v_15402 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15132;
v_15137:
    goto v_15178;
v_15174:
    v_15403 = stack[-2];
    goto v_15175;
v_15176:
    v_15402 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15177;
v_15178:
    goto v_15174;
v_15175:
    goto v_15176;
v_15177:
    if (((intptr_t)(v_15403)) < ((intptr_t)(v_15402))) goto v_15171;
    goto v_15186;
v_15182:
    v_15403 = stack[0];
    goto v_15183;
v_15184:
    v_15402 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15185;
v_15186:
    goto v_15182;
v_15183:
    goto v_15184;
v_15185:
    if (((intptr_t)(v_15403)) < ((intptr_t)(v_15402))) goto v_15171;
    goto v_15172;
v_15171:
    v_15402 = elt(env, 1); // "GCD with zero not allowed"
    fn = elt(env, 2); // errorf
    v_15402 = (*qfn1(fn))(fn, v_15402);
    env = stack[-4];
    goto v_15135;
v_15172:
v_15135:
v_15133:
    goto v_15200;
v_15192:
    v_15405 = stack[-3];
    goto v_15193;
v_15194:
    v_15404 = stack[-2];
    goto v_15195;
v_15196:
    v_15403 = stack[-1];
    goto v_15197;
v_15198:
    v_15402 = stack[0];
    goto v_15199;
v_15200:
    goto v_15192;
v_15193:
    goto v_15194;
v_15195:
    goto v_15196;
v_15197:
    goto v_15198;
v_15199:
    fn = elt(env, 3); // remainder!-in!-vector
    v_15402 = (*qfnn(fn))(fn, 4, v_15405, v_15404, v_15403, v_15402);
    env = stack[-4];
    stack[-2] = v_15402;
    goto v_15213;
v_15209:
    v_15403 = stack[-2];
    goto v_15210;
v_15211:
    v_15402 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15212;
v_15213:
    goto v_15209;
v_15210:
    goto v_15211;
v_15212:
    if (v_15403 == v_15402) goto v_15207;
    else goto v_15208;
v_15207:
    goto v_15222;
v_15216:
    v_15404 = stack[-3];
    goto v_15217;
v_15218:
    v_15403 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15219;
v_15220:
    v_15402 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15221;
v_15222:
    goto v_15216;
v_15217:
    goto v_15218;
v_15219:
    goto v_15220;
v_15221:
    *(LispObject *)((char *)v_15404 + (CELL-TAG_VECTOR) + (((intptr_t)v_15403-TAG_FIXNUM)/(16/CELL))) = v_15402;
    v_15402 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15132;
v_15208:
    goto v_15233;
v_15229:
    v_15403 = stack[-2];
    goto v_15230;
v_15231:
    v_15402 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_15232;
v_15233:
    goto v_15229;
v_15230:
    goto v_15231;
v_15232:
    if (v_15403 == v_15402) goto v_15227;
    else goto v_15228;
v_15227:
    goto v_15241;
v_15237:
    v_15403 = stack[-1];
    goto v_15238;
v_15239:
    v_15402 = stack[0];
    goto v_15240;
v_15241:
    goto v_15237;
v_15238:
    goto v_15239;
v_15240:
    v_15402 = *(LispObject *)((char *)v_15403 + (CELL-TAG_VECTOR) + (((intptr_t)v_15402-TAG_FIXNUM)/(16/CELL)));
    v_15402 = Lmodular_reciprocal(nil, v_15402);
    env = stack[-4];
    v_15407 = v_15402;
    v_15402 = (LispObject)0+TAG_FIXNUM; // 0
    v_15406 = v_15402;
v_15248:
    goto v_15258;
v_15254:
    v_15403 = stack[0];
    goto v_15255;
v_15256:
    v_15402 = v_15406;
    goto v_15257;
v_15258:
    goto v_15254;
v_15255:
    goto v_15256;
v_15257:
    v_15402 = (LispObject)(intptr_t)((intptr_t)v_15403 - (intptr_t)v_15402 + TAG_FIXNUM);
    v_15402 = ((intptr_t)(v_15402) < 0 ? lisp_true : nil);
    if (v_15402 == nil) goto v_15253;
    goto v_15247;
v_15253:
    goto v_15270;
v_15264:
    v_15405 = stack[-3];
    goto v_15265;
v_15266:
    v_15404 = v_15406;
    goto v_15267;
v_15268:
    goto v_15278;
v_15274:
    goto v_15283;
v_15279:
    v_15403 = stack[-1];
    goto v_15280;
v_15281:
    v_15402 = v_15406;
    goto v_15282;
v_15283:
    goto v_15279;
v_15280:
    goto v_15281;
v_15282:
    v_15403 = *(LispObject *)((char *)v_15403 + (CELL-TAG_VECTOR) + (((intptr_t)v_15402-TAG_FIXNUM)/(16/CELL)));
    goto v_15275;
v_15276:
    v_15402 = v_15407;
    goto v_15277;
v_15278:
    goto v_15274;
v_15275:
    goto v_15276;
v_15277:
    v_15402 = Lmodular_times(nil, v_15403, v_15402);
    env = stack[-4];
    goto v_15269;
v_15270:
    goto v_15264;
v_15265:
    goto v_15266;
v_15267:
    goto v_15268;
v_15269:
    *(LispObject *)((char *)v_15405 + (CELL-TAG_VECTOR) + (((intptr_t)v_15404-TAG_FIXNUM)/(16/CELL))) = v_15402;
    v_15402 = v_15406;
    v_15402 = (LispObject)((intptr_t)(v_15402) + 0x10);
    v_15406 = v_15402;
    goto v_15248;
v_15247:
    v_15402 = stack[0];
    goto v_15132;
v_15228:
    goto v_15300;
v_15292:
    v_15405 = stack[-1];
    goto v_15293;
v_15294:
    v_15404 = stack[0];
    goto v_15295;
v_15296:
    v_15403 = stack[-3];
    goto v_15297;
v_15298:
    v_15402 = stack[-2];
    goto v_15299;
v_15300:
    goto v_15292;
v_15293:
    goto v_15294;
v_15295:
    goto v_15296;
v_15297:
    goto v_15298;
v_15299:
    fn = elt(env, 3); // remainder!-in!-vector
    v_15402 = (*qfnn(fn))(fn, 4, v_15405, v_15404, v_15403, v_15402);
    env = stack[-4];
    stack[0] = v_15402;
    goto v_15313;
v_15309:
    v_15403 = stack[0];
    goto v_15310;
v_15311:
    v_15402 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15312;
v_15313:
    goto v_15309;
v_15310:
    goto v_15311;
v_15312:
    if (v_15403 == v_15402) goto v_15307;
    else goto v_15308;
v_15307:
    goto v_15322;
v_15316:
    v_15404 = stack[-3];
    goto v_15317;
v_15318:
    v_15403 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15319;
v_15320:
    v_15402 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15321;
v_15322:
    goto v_15316;
v_15317:
    goto v_15318;
v_15319:
    goto v_15320;
v_15321:
    *(LispObject *)((char *)v_15404 + (CELL-TAG_VECTOR) + (((intptr_t)v_15403-TAG_FIXNUM)/(16/CELL))) = v_15402;
    v_15402 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15132;
v_15308:
    goto v_15333;
v_15329:
    v_15403 = stack[0];
    goto v_15330;
v_15331:
    v_15402 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_15332;
v_15333:
    goto v_15329;
v_15330:
    goto v_15331;
v_15332:
    if (v_15403 == v_15402) goto v_15327;
    else goto v_15328;
v_15327:
    goto v_15341;
v_15337:
    v_15403 = stack[-3];
    goto v_15338;
v_15339:
    v_15402 = stack[-2];
    goto v_15340;
v_15341:
    goto v_15337;
v_15338:
    goto v_15339;
v_15340:
    v_15402 = *(LispObject *)((char *)v_15403 + (CELL-TAG_VECTOR) + (((intptr_t)v_15402-TAG_FIXNUM)/(16/CELL)));
    v_15402 = Lmodular_reciprocal(nil, v_15402);
    env = stack[-4];
    v_15407 = v_15402;
    goto v_15353;
v_15349:
    v_15403 = v_15407;
    goto v_15350;
v_15351:
    v_15402 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15352;
v_15353:
    goto v_15349;
v_15350:
    goto v_15351;
v_15352:
    if (v_15403 == v_15402) goto v_15348;
    v_15402 = (LispObject)0+TAG_FIXNUM; // 0
    v_15406 = v_15402;
v_15359:
    goto v_15369;
v_15365:
    v_15403 = stack[-2];
    goto v_15366;
v_15367:
    v_15402 = v_15406;
    goto v_15368;
v_15369:
    goto v_15365;
v_15366:
    goto v_15367;
v_15368:
    v_15402 = (LispObject)(intptr_t)((intptr_t)v_15403 - (intptr_t)v_15402 + TAG_FIXNUM);
    v_15402 = ((intptr_t)(v_15402) < 0 ? lisp_true : nil);
    if (v_15402 == nil) goto v_15364;
    goto v_15358;
v_15364:
    goto v_15381;
v_15375:
    v_15405 = stack[-3];
    goto v_15376;
v_15377:
    v_15404 = v_15406;
    goto v_15378;
v_15379:
    goto v_15389;
v_15385:
    goto v_15394;
v_15390:
    v_15403 = stack[-3];
    goto v_15391;
v_15392:
    v_15402 = v_15406;
    goto v_15393;
v_15394:
    goto v_15390;
v_15391:
    goto v_15392;
v_15393:
    v_15403 = *(LispObject *)((char *)v_15403 + (CELL-TAG_VECTOR) + (((intptr_t)v_15402-TAG_FIXNUM)/(16/CELL)));
    goto v_15386;
v_15387:
    v_15402 = v_15407;
    goto v_15388;
v_15389:
    goto v_15385;
v_15386:
    goto v_15387;
v_15388:
    v_15402 = Lmodular_times(nil, v_15403, v_15402);
    env = stack[-4];
    goto v_15380;
v_15381:
    goto v_15375;
v_15376:
    goto v_15377;
v_15378:
    goto v_15379;
v_15380:
    *(LispObject *)((char *)v_15405 + (CELL-TAG_VECTOR) + (((intptr_t)v_15404-TAG_FIXNUM)/(16/CELL))) = v_15402;
    v_15402 = v_15406;
    v_15402 = (LispObject)((intptr_t)(v_15402) + 0x10);
    v_15406 = v_15402;
    goto v_15359;
v_15358:
    goto v_15346;
v_15348:
v_15346:
    v_15402 = stack[-2];
    goto v_15132;
v_15328:
    goto v_15133;
v_15132:
    return onevalue(v_15402);
}



// Code for lalr_most_common_dest

static LispObject CC_lalr_most_common_dest(LispObject env,
                         LispObject v_15125)
{
    env = qenv(env);
    LispObject v_15220, v_15221, v_15222;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15125);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15125);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_15220 = v_15125;
// end of prologue
    stack[-3] = nil;
    stack[-1] = v_15220;
v_15134:
    v_15220 = stack[-1];
    if (v_15220 == nil) goto v_15138;
    else goto v_15139;
v_15138:
    goto v_15133;
v_15139:
    v_15220 = stack[-1];
    v_15220 = qcar(v_15220);
    v_15222 = v_15220;
    goto v_15153;
v_15149:
    v_15220 = v_15222;
    v_15221 = qcdr(v_15220);
    goto v_15150;
v_15151:
    v_15220 = stack[-3];
    goto v_15152;
v_15153:
    goto v_15149;
v_15150:
    goto v_15151;
v_15152:
    v_15220 = Lassoc(nil, v_15221, v_15220);
    stack[-2] = v_15220;
    if (v_15220 == nil) goto v_15148;
    goto v_15163;
v_15159:
    stack[0] = stack[-2];
    goto v_15160;
v_15161:
    v_15220 = stack[-2];
    v_15220 = qcdr(v_15220);
    v_15220 = add1(v_15220);
    env = stack[-4];
    goto v_15162;
v_15163:
    goto v_15159;
v_15160:
    goto v_15161;
v_15162:
    v_15220 = Lrplacd(nil, stack[0], v_15220);
    env = stack[-4];
    goto v_15146;
v_15148:
    goto v_15177;
v_15171:
    v_15220 = v_15222;
    v_15222 = qcdr(v_15220);
    goto v_15172;
v_15173:
    v_15221 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15174;
v_15175:
    v_15220 = stack[-3];
    goto v_15176;
v_15177:
    goto v_15171;
v_15172:
    goto v_15173;
v_15174:
    goto v_15175;
v_15176:
    v_15220 = acons(v_15222, v_15221, v_15220);
    env = stack[-4];
    stack[-3] = v_15220;
    goto v_15146;
v_15146:
    v_15220 = stack[-1];
    v_15220 = qcdr(v_15220);
    stack[-1] = v_15220;
    goto v_15134;
v_15133:
    v_15220 = stack[-3];
    v_15220 = qcar(v_15220);
    stack[-2] = v_15220;
    v_15220 = stack[-3];
    v_15220 = qcdr(v_15220);
    stack[-1] = v_15220;
v_15189:
    v_15220 = stack[-1];
    if (v_15220 == nil) goto v_15194;
    else goto v_15195;
v_15194:
    goto v_15188;
v_15195:
    v_15220 = stack[-1];
    v_15220 = qcar(v_15220);
    stack[0] = v_15220;
    goto v_15210;
v_15206:
    v_15220 = stack[0];
    v_15221 = qcdr(v_15220);
    goto v_15207;
v_15208:
    v_15220 = stack[-2];
    v_15220 = qcdr(v_15220);
    goto v_15209;
v_15210:
    goto v_15206;
v_15207:
    goto v_15208;
v_15209:
    v_15220 = (LispObject)greaterp2(v_15221, v_15220);
    v_15220 = v_15220 ? lisp_true : nil;
    env = stack[-4];
    if (v_15220 == nil) goto v_15204;
    v_15220 = stack[0];
    stack[-2] = v_15220;
    goto v_15202;
v_15204:
v_15202:
    v_15220 = stack[-1];
    v_15220 = qcdr(v_15220);
    stack[-1] = v_15220;
    goto v_15189;
v_15188:
    v_15220 = stack[-2];
    v_15220 = qcar(v_15220);
    return onevalue(v_15220);
}



setup_type const u27_setup[] =
{
    {"extmult",                 TOO_FEW_2,      CC_extmult,    WRONG_NO_2},
    {"formrlis",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formrlis},
    {"smemberlp",               TOO_FEW_2,      CC_smemberlp,  WRONG_NO_2},
    {"talp_list2vec",           CC_talp_list2vec,TOO_MANY_1,   WRONG_NO_1},
    {"lambdafun",               CC_lambdafun,   TOO_MANY_1,    WRONG_NO_1},
    {"setdmode",                TOO_FEW_2,      CC_setdmode,   WRONG_NO_2},
    {"random",                  CC_random,      TOO_MANY_1,    WRONG_NO_1},
    {"assert_install1",         CC_assert_install1,TOO_MANY_1, WRONG_NO_1},
    {"red=hidelt",              CC_redMhidelt,  TOO_MANY_1,    WRONG_NO_1},
    {"repeats",                 CC_repeats,     TOO_MANY_1,    WRONG_NO_1},
    {"gf2cr:",                  CC_gf2crT,      TOO_MANY_1,    WRONG_NO_1},
    {"lalr_make_compressed_goto_column",CC_lalr_make_compressed_goto_column,TOO_MANY_1,WRONG_NO_1},
    {"comm1",                   CC_comm1,       TOO_MANY_1,    WRONG_NO_1},
    {"simpcv",                  TOO_FEW_2,      CC_simpcv,     WRONG_NO_2},
    {"matrixrowom",             CC_matrixrowom, TOO_MANY_1,    WRONG_NO_1},
    {"ft:zerop",                CC_ftTzerop,    TOO_MANY_1,    WRONG_NO_1},
    {"vdpequal",                TOO_FEW_2,      CC_vdpequal,   WRONG_NO_2},
    {"freeoff",                 TOO_FEW_2,      CC_freeoff,    WRONG_NO_2},
    {"oprinla",                 CC_oprinla,     TOO_MANY_1,    WRONG_NO_1},
    {"physopordchk*",           TOO_FEW_2,      CC_physopordchkH,WRONG_NO_2},
    {"fieldconv",               TOO_FEW_2,      CC_fieldconv,  WRONG_NO_2},
    {"mod_eval_uni_poly",       TOO_FEW_2,      CC_mod_eval_uni_poly,WRONG_NO_2},
    {"reduce-mod-p*",           TOO_FEW_2,      CC_reduceKmodKpH,WRONG_NO_2},
    {"string-of-list",          CC_stringKofKlist,TOO_MANY_1,  WRONG_NO_1},
    {"yylex",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_yylex},
    {"gcref_remprops",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gcref_remprops},
    {"ofsf_smmkatl",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smmkatl},
    {"talp_subat",              TOO_FEW_2,      CC_talp_subat, WRONG_NO_2},
    {"vsl_subatsq",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vsl_subatsq},
    {"unaryir",                 TOO_FEW_2,      CC_unaryir,    WRONG_NO_2},
    {"rootextractsq",           CC_rootextractsq,TOO_MANY_1,   WRONG_NO_1},
    {"can_be_proved",           TOO_FEW_2,      CC_can_be_proved,WRONG_NO_2},
    {"extract_dummy_ids",       CC_extract_dummy_ids,TOO_MANY_1,WRONG_NO_1},
    {"evaluate-mod-p",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_evaluateKmodKp},
    {"hasarg",                  TOO_FEW_2,      CC_hasarg,     WRONG_NO_2},
    {"createtriplewithancestor",TOO_FEW_2,      CC_createtriplewithancestor,WRONG_NO_2},
    {"ofsf_negateat",           CC_ofsf_negateat,TOO_MANY_1,   WRONG_NO_1},
    {"get-free-form",           CC_getKfreeKform,TOO_MANY_1,   WRONG_NO_1},
    {"matpri",                  CC_matpri,      TOO_MANY_1,    WRONG_NO_1},
    {"talp_telp",               TOO_FEW_2,      CC_talp_telp,  WRONG_NO_2},
    {"fctrf1",                  CC_fctrf1,      TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_updsigndom",         CC_ofsf_updsigndom,TOO_MANY_1, WRONG_NO_1},
    {"oldmtch",                 TOO_FEW_2,      CC_oldmtch,    WRONG_NO_2},
    {"indxchk",                 CC_indxchk,     TOO_MANY_1,    WRONG_NO_1},
    {"edge_new_parent",         CC_edge_new_parent,TOO_MANY_1, WRONG_NO_1},
    {"pcdiv",                   TOO_FEW_2,      CC_pcdiv,      WRONG_NO_2},
    {"sc_rep",                  CC_sc_rep,      TOO_MANY_1,    WRONG_NO_1},
    {"gcd-in-vector",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gcdKinKvector},
    {"lalr_most_common_dest",   CC_lalr_most_common_dest,TOO_MANY_1,WRONG_NO_1},
    {NULL, (one_args *)"u27", (two_args *)"167482 6370819 5652261", 0}
};

// end of generated code
