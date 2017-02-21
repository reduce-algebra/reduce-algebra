
// $destdir/u50.c        Machine generated C code

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



// Code for st_sorttree1

static LispObject CC_st_sorttree1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30168, v_30169, v_30170;
    LispObject fn;
    LispObject v_29660, v_29659, v_29658;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "st_sorttree1");
    va_start(aa, nargs);
    v_29658 = va_arg(aa, LispObject);
    v_29659 = va_arg(aa, LispObject);
    v_29660 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_29660,v_29659,v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_29658,v_29659,v_29660);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(13);
// copy arguments values to proper place
    stack[-8] = v_29660;
    stack[-9] = v_29659;
    stack[-10] = v_29658;
// end of prologue
    stack[-11] = nil;
    stack[-7] = nil;
    stack[-1] = nil;
    v_30168 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_30168;
    v_30168 = stack[-10];
    v_30168 = qcdr(v_30168);
    v_30168 = qcar(v_30168);
    if (is_number(v_30168)) goto v_29672;
    else goto v_29673;
v_29672:
    goto v_29685;
v_29681:
    v_30168 = stack[-10];
    v_30169 = qcar(v_30168);
    goto v_29682;
v_29683:
    v_30168 = elt(env, 1); // !*
    goto v_29684;
v_29685:
    goto v_29681;
v_29682:
    goto v_29683;
v_29684:
    if (v_30169 == v_30168) goto v_29679;
    else goto v_29680;
v_29679:
    v_30168 = stack[-10];
    v_30168 = qcdr(v_30168);
    stack[-4] = v_30168;
    v_30168 = stack[-4];
    if (v_30168 == nil) goto v_29699;
    else goto v_29700;
v_29699:
    v_30168 = nil;
    goto v_29693;
v_29700:
    v_30168 = stack[-4];
    v_30168 = qcar(v_30168);
    goto v_29711;
v_29707:
    stack[0] = stack[-9];
    goto v_29708;
v_29709:
    v_30168 = sub1(v_30168);
    env = stack[-12];
    goto v_29710;
v_29711:
    goto v_29707;
v_29708:
    goto v_29709;
v_29710:
    v_30168 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_30168-TAG_FIXNUM)/(16/CELL)));
    v_30168 = ncons(v_30168);
    env = stack[-12];
    stack[-2] = v_30168;
    stack[-3] = v_30168;
v_29694:
    v_30168 = stack[-4];
    v_30168 = qcdr(v_30168);
    stack[-4] = v_30168;
    v_30168 = stack[-4];
    if (v_30168 == nil) goto v_29720;
    else goto v_29721;
v_29720:
    v_30168 = stack[-3];
    goto v_29693;
v_29721:
    goto v_29729;
v_29725:
    stack[-1] = stack[-2];
    goto v_29726;
v_29727:
    v_30168 = stack[-4];
    v_30168 = qcar(v_30168);
    goto v_29739;
v_29735:
    stack[0] = stack[-9];
    goto v_29736;
v_29737:
    v_30168 = sub1(v_30168);
    env = stack[-12];
    goto v_29738;
v_29739:
    goto v_29735;
v_29736:
    goto v_29737;
v_29738:
    v_30168 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_30168-TAG_FIXNUM)/(16/CELL)));
    v_30168 = ncons(v_30168);
    env = stack[-12];
    goto v_29728;
v_29729:
    goto v_29725;
v_29726:
    goto v_29727;
v_29728:
    v_30168 = Lrplacd(nil, stack[-1], v_30168);
    env = stack[-12];
    v_30168 = stack[-2];
    v_30168 = qcdr(v_30168);
    stack[-2] = v_30168;
    goto v_29694;
v_29693:
    stack[-11] = v_30168;
    goto v_29753;
v_29747:
    v_30170 = stack[-11];
    goto v_29748;
v_29749:
    v_30169 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29750;
v_29751:
    v_30168 = stack[-10];
    goto v_29752;
v_29753:
    goto v_29747;
v_29748:
    goto v_29749;
v_29750:
    goto v_29751;
v_29752:
    return list2star(v_30170, v_30169, v_30168);
v_29680:
    v_30168 = stack[-10];
    v_30168 = qcdr(v_30168);
    stack[-5] = v_30168;
    v_30168 = stack[-5];
    if (v_30168 == nil) goto v_29767;
    else goto v_29768;
v_29767:
    v_30168 = nil;
    goto v_29761;
v_29768:
    v_30168 = stack[-5];
    v_30168 = qcar(v_30168);
    goto v_29780;
v_29776:
    stack[-1] = v_30168;
    goto v_29777;
v_29778:
    goto v_29786;
v_29782:
    stack[0] = stack[-9];
    goto v_29783;
v_29784:
    v_30168 = sub1(v_30168);
    env = stack[-12];
    goto v_29785;
v_29786:
    goto v_29782;
v_29783:
    goto v_29784;
v_29785:
    v_30168 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_30168-TAG_FIXNUM)/(16/CELL)));
    goto v_29779;
v_29780:
    goto v_29776;
v_29777:
    goto v_29778;
v_29779:
    v_30168 = cons(stack[-1], v_30168);
    env = stack[-12];
    v_30168 = ncons(v_30168);
    env = stack[-12];
    stack[-3] = v_30168;
    stack[-4] = v_30168;
v_29762:
    v_30168 = stack[-5];
    v_30168 = qcdr(v_30168);
    stack[-5] = v_30168;
    v_30168 = stack[-5];
    if (v_30168 == nil) goto v_29795;
    else goto v_29796;
v_29795:
    v_30168 = stack[-4];
    goto v_29761;
v_29796:
    goto v_29804;
v_29800:
    stack[-2] = stack[-3];
    goto v_29801;
v_29802:
    v_30168 = stack[-5];
    v_30168 = qcar(v_30168);
    goto v_29815;
v_29811:
    stack[-1] = v_30168;
    goto v_29812;
v_29813:
    goto v_29821;
v_29817:
    stack[0] = stack[-9];
    goto v_29818;
v_29819:
    v_30168 = sub1(v_30168);
    env = stack[-12];
    goto v_29820;
v_29821:
    goto v_29817;
v_29818:
    goto v_29819;
v_29820:
    v_30168 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_30168-TAG_FIXNUM)/(16/CELL)));
    goto v_29814;
v_29815:
    goto v_29811;
v_29812:
    goto v_29813;
v_29814:
    v_30168 = cons(stack[-1], v_30168);
    env = stack[-12];
    v_30168 = ncons(v_30168);
    env = stack[-12];
    goto v_29803;
v_29804:
    goto v_29800;
v_29801:
    goto v_29802;
v_29803:
    v_30168 = Lrplacd(nil, stack[-2], v_30168);
    env = stack[-12];
    v_30168 = stack[-3];
    v_30168 = qcdr(v_30168);
    stack[-3] = v_30168;
    goto v_29762;
v_29761:
    stack[-1] = v_30168;
    goto v_29671;
v_29673:
    goto v_29839;
v_29835:
    v_30168 = stack[-10];
    v_30169 = qcar(v_30168);
    goto v_29836;
v_29837:
    v_30168 = elt(env, 1); // !*
    goto v_29838;
v_29839:
    goto v_29835;
v_29836:
    goto v_29837;
v_29838:
    if (v_30169 == v_30168) goto v_29833;
    else goto v_29834;
v_29833:
    v_30168 = stack[-10];
    v_30168 = qcdr(v_30168);
    stack[0] = v_30168;
v_29846:
    v_30168 = stack[0];
    if (v_30168 == nil) goto v_29851;
    else goto v_29852;
v_29851:
    goto v_29845;
v_29852:
    v_30168 = stack[0];
    v_30168 = qcar(v_30168);
    v_30170 = v_30168;
    goto v_29866;
v_29862:
    v_30169 = stack[-6];
    goto v_29863;
v_29864:
    v_30168 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29865;
v_29866:
    goto v_29862;
v_29863:
    goto v_29864;
v_29865:
    if (v_30169 == v_30168) goto v_29861;
    goto v_29876;
v_29870:
    goto v_29871;
v_29872:
    v_30169 = stack[-9];
    goto v_29873;
v_29874:
    v_30168 = stack[-8];
    goto v_29875;
v_29876:
    goto v_29870;
v_29871:
    goto v_29872;
v_29873:
    goto v_29874;
v_29875:
    v_30168 = CC_st_sorttree1(elt(env, 0), 3, v_30170, v_30169, v_30168);
    env = stack[-12];
    stack[-2] = v_30168;
    goto v_29885;
v_29881:
    v_30169 = stack[-6];
    goto v_29882;
v_29883:
    v_30168 = stack[-2];
    v_30168 = qcdr(v_30168);
    v_30168 = qcar(v_30168);
    goto v_29884;
v_29885:
    goto v_29881;
v_29882:
    goto v_29883;
v_29884:
    v_30168 = times2(v_30169, v_30168);
    env = stack[-12];
    stack[-6] = v_30168;
    goto v_29895;
v_29891:
    v_30168 = stack[-2];
    v_30169 = qcar(v_30168);
    goto v_29892;
v_29893:
    v_30168 = stack[-11];
    goto v_29894;
v_29895:
    goto v_29891;
v_29892:
    goto v_29893;
v_29894:
    v_30168 = cons(v_30169, v_30168);
    env = stack[-12];
    stack[-11] = v_30168;
    goto v_29904;
v_29900:
    v_30168 = stack[-2];
    v_30168 = qcdr(v_30168);
    v_30169 = qcdr(v_30168);
    goto v_29901;
v_29902:
    v_30168 = stack[-7];
    goto v_29903;
v_29904:
    goto v_29900;
v_29901:
    goto v_29902;
v_29903:
    v_30168 = cons(v_30169, v_30168);
    env = stack[-12];
    stack[-7] = v_30168;
    goto v_29859;
v_29861:
v_29859:
    v_30168 = stack[0];
    v_30168 = qcdr(v_30168);
    stack[0] = v_30168;
    goto v_29846;
v_29845:
    goto v_29920;
v_29916:
    v_30169 = stack[-6];
    goto v_29917;
v_29918:
    v_30168 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29919;
v_29920:
    goto v_29916;
v_29917:
    goto v_29918;
v_29919:
    if (v_30169 == v_30168) goto v_29914;
    else goto v_29915;
v_29914:
    goto v_29930;
v_29924:
    v_30170 = nil;
    goto v_29925;
v_29926:
    v_30169 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29927;
v_29928:
    v_30168 = nil;
    goto v_29929;
v_29930:
    goto v_29924;
v_29925:
    goto v_29926;
v_29927:
    goto v_29928;
v_29929:
    return list2star(v_30170, v_30169, v_30168);
v_29915:
    v_30168 = stack[-7];
    v_30168 = Lreverse(nil, v_30168);
    env = stack[-12];
    stack[-7] = v_30168;
    v_30168 = stack[-11];
    v_30168 = Lreverse(nil, v_30168);
    env = stack[-12];
    stack[-11] = v_30168;
    goto v_29947;
v_29941:
    stack[0] = stack[-11];
    goto v_29942;
v_29943:
    stack[-1] = stack[-6];
    goto v_29944;
v_29945:
    goto v_29955;
v_29951:
    v_30169 = elt(env, 1); // !*
    goto v_29952;
v_29953:
    v_30168 = stack[-7];
    goto v_29954;
v_29955:
    goto v_29951;
v_29952:
    goto v_29953;
v_29954:
    v_30168 = cons(v_30169, v_30168);
    goto v_29946;
v_29947:
    goto v_29941;
v_29942:
    goto v_29943;
v_29944:
    goto v_29945;
v_29946:
    {
        LispObject v_30183 = stack[0];
        LispObject v_30184 = stack[-1];
        return list2star(v_30183, v_30184, v_30168);
    }
    goto v_29832;
v_29834:
v_29832:
    v_30168 = stack[-10];
    v_30168 = qcdr(v_30168);
    stack[0] = v_30168;
v_29962:
    v_30168 = stack[0];
    if (v_30168 == nil) goto v_29967;
    else goto v_29968;
v_29967:
    goto v_29961;
v_29968:
    v_30168 = stack[0];
    v_30168 = qcar(v_30168);
    v_30170 = v_30168;
    goto v_29982;
v_29978:
    v_30169 = stack[-6];
    goto v_29979;
v_29980:
    v_30168 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29981;
v_29982:
    goto v_29978;
v_29979:
    goto v_29980;
v_29981:
    if (v_30169 == v_30168) goto v_29977;
    goto v_29992;
v_29986:
    goto v_29987;
v_29988:
    v_30169 = stack[-9];
    goto v_29989;
v_29990:
    v_30168 = stack[-8];
    goto v_29991;
v_29992:
    goto v_29986;
v_29987:
    goto v_29988;
v_29989:
    goto v_29990;
v_29991:
    v_30168 = CC_st_sorttree1(elt(env, 0), 3, v_30170, v_30169, v_30168);
    env = stack[-12];
    stack[-2] = v_30168;
    goto v_30001;
v_29997:
    v_30169 = stack[-6];
    goto v_29998;
v_29999:
    v_30168 = stack[-2];
    v_30168 = qcdr(v_30168);
    v_30168 = qcar(v_30168);
    goto v_30000;
v_30001:
    goto v_29997;
v_29998:
    goto v_29999;
v_30000:
    v_30168 = times2(v_30169, v_30168);
    env = stack[-12];
    stack[-6] = v_30168;
    goto v_30013;
v_30007:
    v_30168 = stack[-2];
    v_30168 = qcdr(v_30168);
    v_30170 = qcdr(v_30168);
    goto v_30008;
v_30009:
    v_30168 = stack[-2];
    v_30169 = qcar(v_30168);
    goto v_30010;
v_30011:
    v_30168 = stack[-1];
    goto v_30012;
v_30013:
    goto v_30007;
v_30008:
    goto v_30009;
v_30010:
    goto v_30011;
v_30012:
    v_30168 = acons(v_30170, v_30169, v_30168);
    env = stack[-12];
    stack[-1] = v_30168;
    goto v_29975;
v_29977:
v_29975:
    v_30168 = stack[0];
    v_30168 = qcdr(v_30168);
    stack[0] = v_30168;
    goto v_29962;
v_29961:
    goto v_29671;
v_29671:
    goto v_30032;
v_30028:
    v_30169 = stack[-6];
    goto v_30029;
v_30030:
    v_30168 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30031;
v_30032:
    goto v_30028;
v_30029:
    goto v_30030;
v_30031:
    if (v_30169 == v_30168) goto v_30026;
    else goto v_30027;
v_30026:
    goto v_30042;
v_30036:
    v_30170 = nil;
    goto v_30037;
v_30038:
    v_30169 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30039;
v_30040:
    v_30168 = nil;
    goto v_30041;
v_30042:
    goto v_30036;
v_30037:
    goto v_30038;
v_30039:
    goto v_30040;
v_30041:
    return list2star(v_30170, v_30169, v_30168);
v_30027:
    goto v_30054;
v_30050:
    v_30168 = stack[-10];
    v_30169 = qcar(v_30168);
    goto v_30051;
v_30052:
    v_30168 = elt(env, 2); // !+
    goto v_30053;
v_30054:
    goto v_30050;
v_30051:
    goto v_30052;
v_30053:
    if (v_30169 == v_30168) goto v_30048;
    else goto v_30049;
v_30048:
    goto v_30063;
v_30059:
    v_30169 = stack[-1];
    goto v_30060;
v_30061:
    v_30168 = stack[-8];
    goto v_30062;
v_30063:
    goto v_30059;
v_30060:
    goto v_30061;
v_30062:
    fn = elt(env, 3); // cdr_sort
    v_30168 = (*qfn2(fn))(fn, v_30169, v_30168);
    env = stack[-12];
    stack[-1] = v_30168;
    goto v_30047;
v_30049:
    goto v_30073;
v_30069:
    v_30169 = stack[-1];
    goto v_30070;
v_30071:
    v_30168 = stack[-8];
    goto v_30072;
v_30073:
    goto v_30069;
v_30070:
    goto v_30071;
v_30072:
    fn = elt(env, 4); // cdr_signsort
    v_30168 = (*qfn2(fn))(fn, v_30169, v_30168);
    env = stack[-12];
    stack[-1] = v_30168;
    goto v_30084;
v_30080:
    v_30168 = stack[-1];
    v_30169 = qcar(v_30168);
    goto v_30081;
v_30082:
    v_30168 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30083;
v_30084:
    goto v_30080;
v_30081:
    goto v_30082;
v_30083:
    if (v_30169 == v_30168) goto v_30078;
    else goto v_30079;
v_30078:
    goto v_30095;
v_30089:
    v_30170 = nil;
    goto v_30090;
v_30091:
    v_30169 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30092;
v_30093:
    v_30168 = nil;
    goto v_30094;
v_30095:
    goto v_30089;
v_30090:
    goto v_30091;
v_30092:
    goto v_30093;
v_30094:
    return list2star(v_30170, v_30169, v_30168);
v_30079:
    goto v_30106;
v_30102:
    v_30169 = stack[-6];
    goto v_30103;
v_30104:
    v_30168 = stack[-1];
    v_30168 = qcar(v_30168);
    goto v_30105;
v_30106:
    goto v_30102;
v_30103:
    goto v_30104;
v_30105:
    v_30168 = times2(v_30169, v_30168);
    env = stack[-12];
    stack[-6] = v_30168;
    goto v_30077;
v_30077:
    v_30168 = stack[-1];
    v_30168 = qcdr(v_30168);
    stack[-1] = v_30168;
    goto v_30047;
v_30047:
v_30115:
    v_30168 = stack[-1];
    if (v_30168 == nil) goto v_30118;
    else goto v_30119;
v_30118:
    goto v_30114;
v_30119:
    goto v_30127;
v_30123:
    v_30168 = stack[-1];
    v_30168 = qcar(v_30168);
    v_30169 = qcar(v_30168);
    goto v_30124;
v_30125:
    v_30168 = stack[-7];
    goto v_30126;
v_30127:
    goto v_30123;
v_30124:
    goto v_30125;
v_30126:
    v_30168 = cons(v_30169, v_30168);
    env = stack[-12];
    stack[-7] = v_30168;
    goto v_30137;
v_30133:
    v_30168 = stack[-1];
    v_30168 = qcar(v_30168);
    v_30169 = qcdr(v_30168);
    goto v_30134;
v_30135:
    v_30168 = stack[-11];
    goto v_30136;
v_30137:
    goto v_30133;
v_30134:
    goto v_30135;
v_30136:
    v_30168 = cons(v_30169, v_30168);
    env = stack[-12];
    stack[-11] = v_30168;
    v_30168 = stack[-1];
    v_30168 = qcdr(v_30168);
    stack[-1] = v_30168;
    goto v_30115;
v_30114:
    goto v_30150;
v_30146:
    v_30168 = stack[-10];
    stack[0] = qcar(v_30168);
    goto v_30147;
v_30148:
    v_30168 = stack[-7];
    v_30168 = Lreverse(nil, v_30168);
    env = stack[-12];
    goto v_30149;
v_30150:
    goto v_30146;
v_30147:
    goto v_30148;
v_30149:
    v_30168 = cons(stack[0], v_30168);
    env = stack[-12];
    stack[-7] = v_30168;
    v_30168 = stack[-11];
    v_30168 = Lreverse(nil, v_30168);
    stack[-11] = v_30168;
    goto v_30164;
v_30158:
    v_30170 = stack[-11];
    goto v_30159;
v_30160:
    v_30169 = stack[-6];
    goto v_30161;
v_30162:
    v_30168 = stack[-7];
    goto v_30163;
v_30164:
    goto v_30158;
v_30159:
    goto v_30160;
v_30161:
    goto v_30162;
v_30163:
    return list2star(v_30170, v_30169, v_30168);
    return onevalue(v_30168);
}



// Code for evaluate!-in!-vector

static LispObject CC_evaluateKinKvector(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_29711, v_29712, v_29713, v_29714, v_29715, v_29716;
    LispObject v_29660, v_29659, v_29658;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "evaluate-in-vector");
    va_start(aa, nargs);
    v_29658 = va_arg(aa, LispObject);
    v_29659 = va_arg(aa, LispObject);
    v_29660 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_29660,v_29659,v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_29658,v_29659,v_29660);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_29714 = v_29660;
    v_29713 = v_29659;
    v_29715 = v_29658;
// end of prologue
    goto v_29669;
v_29665:
    v_29712 = v_29715;
    goto v_29666;
v_29667:
    v_29711 = v_29713;
    goto v_29668;
v_29669:
    goto v_29665;
v_29666:
    goto v_29667;
v_29668:
    v_29711 = *(LispObject *)((char *)v_29712 + (CELL-TAG_VECTOR) + (((intptr_t)v_29711-TAG_FIXNUM)/(16/CELL)));
    v_29712 = v_29711;
    v_29711 = v_29713;
    v_29711 = (LispObject)((intptr_t)(v_29711) - 0x10);
    v_29716 = v_29711;
v_29676:
    v_29711 = v_29716;
    v_29711 = ((intptr_t)(v_29711) < 0 ? lisp_true : nil);
    if (v_29711 == nil) goto v_29682;
    goto v_29675;
v_29682:
    goto v_29690;
v_29686:
    goto v_29695;
v_29691:
    v_29713 = v_29715;
    goto v_29692;
v_29693:
    v_29711 = v_29716;
    goto v_29694;
v_29695:
    goto v_29691;
v_29692:
    goto v_29693;
v_29694:
    v_29713 = *(LispObject *)((char *)v_29713 + (CELL-TAG_VECTOR) + (((intptr_t)v_29711-TAG_FIXNUM)/(16/CELL)));
    goto v_29687;
v_29688:
    goto v_29704;
v_29700:
    goto v_29701;
v_29702:
    v_29711 = v_29714;
    goto v_29703;
v_29704:
    goto v_29700;
v_29701:
    goto v_29702;
v_29703:
    v_29711 = Lmodular_times(nil, v_29712, v_29711);
    env = stack[0];
    goto v_29689;
v_29690:
    goto v_29686;
v_29687:
    goto v_29688;
v_29689:
    {   intptr_t w = int_of_fixnum(v_29713) + int_of_fixnum(v_29711);
        if (w >= current_modulus) w -= current_modulus;
        v_29711 = fixnum_of_int(w);
    }
    v_29712 = v_29711;
    v_29711 = v_29716;
    v_29711 = (LispObject)((intptr_t)(v_29711) - 0x10);
    v_29716 = v_29711;
    goto v_29676;
v_29675:
    v_29711 = v_29712;
    return onevalue(v_29711);
}



// Code for bfrsq

static LispObject CC_bfrsq(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29717, v_29718;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29658);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_29718 = v_29658;
// end of prologue
    v_29717 = v_29718;
    v_29717 = qcar(v_29717);
    v_29718 = qcdr(v_29718);
    stack[-1] = v_29718;
    v_29718 = v_29717;
    if (!consp(v_29718)) goto v_29668;
    else goto v_29669;
v_29668:
    goto v_29676;
v_29672:
    goto v_29682;
v_29678:
    v_29718 = v_29717;
    goto v_29679;
v_29680:
    goto v_29681;
v_29682:
    goto v_29678;
v_29679:
    goto v_29680;
v_29681:
    stack[0] = times2(v_29718, v_29717);
    env = stack[-2];
    goto v_29673;
v_29674:
    goto v_29690;
v_29686:
    v_29718 = stack[-1];
    goto v_29687;
v_29688:
    v_29717 = stack[-1];
    goto v_29689;
v_29690:
    goto v_29686;
v_29687:
    goto v_29688;
v_29689:
    v_29717 = times2(v_29718, v_29717);
    goto v_29675;
v_29676:
    goto v_29672;
v_29673:
    goto v_29674;
v_29675:
    {
        LispObject v_29721 = stack[0];
        return plus2(v_29721, v_29717);
    }
v_29669:
    goto v_29700;
v_29696:
    goto v_29706;
v_29702:
    v_29718 = v_29717;
    goto v_29703;
v_29704:
    goto v_29705;
v_29706:
    goto v_29702;
v_29703:
    goto v_29704;
v_29705:
    fn = elt(env, 1); // csl_timbf
    stack[0] = (*qfn2(fn))(fn, v_29718, v_29717);
    env = stack[-2];
    goto v_29697;
v_29698:
    goto v_29714;
v_29710:
    v_29718 = stack[-1];
    goto v_29711;
v_29712:
    v_29717 = stack[-1];
    goto v_29713;
v_29714:
    goto v_29710;
v_29711:
    goto v_29712;
v_29713:
    fn = elt(env, 1); // csl_timbf
    v_29717 = (*qfn2(fn))(fn, v_29718, v_29717);
    env = stack[-2];
    goto v_29699;
v_29700:
    goto v_29696;
v_29697:
    goto v_29698;
v_29699:
    {
        LispObject v_29722 = stack[0];
        fn = elt(env, 2); // plubf
        return (*qfn2(fn))(fn, v_29722, v_29717);
    }
    v_29717 = nil;
    return onevalue(v_29717);
}



// Code for nextu

static LispObject CC_nextu(LispObject env,
                         LispObject v_29658, LispObject v_29659)
{
    env = qenv(env);
    LispObject v_29735, v_29736, v_29737;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29659,v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29658,v_29659);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_29736 = v_29659;
    stack[0] = v_29658;
// end of prologue
    v_29735 = stack[0];
    if (v_29735 == nil) goto v_29663;
    else goto v_29664;
v_29663:
    v_29735 = nil;
    goto v_29662;
v_29664:
    goto v_29680;
v_29674:
    v_29737 = v_29736;
    goto v_29675;
v_29676:
    v_29735 = stack[0];
    v_29736 = qcar(v_29735);
    goto v_29677;
v_29678:
    v_29735 = nil;
    goto v_29679;
v_29680:
    goto v_29674;
v_29675:
    goto v_29676;
v_29677:
    goto v_29678;
v_29679:
    fn = elt(env, 1); // subtractinds
    v_29735 = (*qfnn(fn))(fn, 3, v_29737, v_29736, v_29735);
    env = stack[-2];
    stack[-1] = v_29735;
    v_29735 = stack[-1];
    if (v_29735 == nil) goto v_29687;
    else goto v_29688;
v_29687:
    v_29735 = nil;
    goto v_29672;
v_29688:
    goto v_29696;
v_29692:
    v_29735 = stack[0];
    v_29735 = qcdr(v_29735);
    v_29736 = qcar(v_29735);
    goto v_29693;
v_29694:
    v_29735 = stack[-1];
    goto v_29695;
v_29696:
    goto v_29692;
v_29693:
    goto v_29694;
v_29695:
    fn = elt(env, 2); // evaluatecoeffts
    v_29735 = (*qfn2(fn))(fn, v_29736, v_29735);
    v_29736 = v_29735;
    v_29735 = v_29736;
    if (v_29735 == nil) goto v_29707;
    else goto v_29708;
v_29707:
    v_29735 = lisp_true;
    goto v_29706;
v_29708:
    goto v_29717;
v_29713:
    v_29737 = v_29736;
    goto v_29714;
v_29715:
    v_29735 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29716;
v_29717:
    goto v_29713;
v_29714:
    goto v_29715;
v_29716:
    v_29735 = (v_29737 == v_29735 ? lisp_true : nil);
    goto v_29706;
    v_29735 = nil;
v_29706:
    if (v_29735 == nil) goto v_29704;
    v_29735 = nil;
    goto v_29672;
v_29704:
    goto v_29729;
v_29723:
    v_29737 = stack[-1];
    goto v_29724;
v_29725:
    goto v_29726;
v_29727:
    v_29735 = stack[0];
    v_29735 = qcdr(v_29735);
    v_29735 = qcdr(v_29735);
    goto v_29728;
v_29729:
    goto v_29723;
v_29724:
    goto v_29725;
v_29726:
    goto v_29727;
v_29728:
    return list2star(v_29737, v_29736, v_29735);
v_29672:
    goto v_29662;
    v_29735 = nil;
v_29662:
    return onevalue(v_29735);
}



// Code for talp_get!-idx

static LispObject CC_talp_getKidx(LispObject env,
                         LispObject v_29658, LispObject v_29659)
{
    env = qenv(env);
    LispObject v_29804, v_29805;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29659,v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29658,v_29659);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_29659;
    stack[-4] = v_29658;
// end of prologue
    stack[-5] = nil;
    v_29804 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_29804;
v_29668:
    goto v_29679;
v_29675:
    stack[0] = stack[-2];
    goto v_29676;
v_29677:
    v_29804 = stack[-3];
    v_29804 = Lupbv(nil, v_29804);
    env = stack[-6];
    goto v_29678;
v_29679:
    goto v_29675;
v_29676:
    goto v_29677;
v_29678:
    v_29804 = (LispObject)lesseq2(stack[0], v_29804);
    v_29804 = v_29804 ? lisp_true : nil;
    env = stack[-6];
    if (v_29804 == nil) goto v_29671;
    v_29804 = stack[-5];
    if (v_29804 == nil) goto v_29683;
    else goto v_29671;
v_29683:
    goto v_29672;
v_29671:
    goto v_29667;
v_29672:
    v_29804 = stack[-4];
    if (!consp(v_29804)) goto v_29688;
    else goto v_29689;
v_29688:
    goto v_29699;
v_29695:
    goto v_29704;
v_29700:
    v_29805 = stack[-3];
    goto v_29701;
v_29702:
    v_29804 = stack[-2];
    goto v_29703;
v_29704:
    goto v_29700;
v_29701:
    goto v_29702;
v_29703:
    v_29805 = *(LispObject *)((char *)v_29805 + (CELL-TAG_VECTOR) + (((intptr_t)v_29804-TAG_FIXNUM)/(16/CELL)));
    goto v_29696;
v_29697:
    v_29804 = stack[-4];
    goto v_29698;
v_29699:
    goto v_29695;
v_29696:
    goto v_29697;
v_29698:
    if (v_29805 == v_29804) goto v_29693;
    else goto v_29694;
v_29693:
    v_29804 = lisp_true;
    stack[-5] = v_29804;
    goto v_29692;
v_29694:
    v_29804 = stack[-2];
    v_29804 = add1(v_29804);
    env = stack[-6];
    stack[-2] = v_29804;
    goto v_29692;
v_29692:
    goto v_29687;
v_29689:
    v_29804 = stack[-4];
    fn = elt(env, 1); // talp_fop
    v_29804 = (*qfn1(fn))(fn, v_29804);
    env = stack[-6];
    v_29804 = Lconsp(nil, v_29804);
    env = stack[-6];
    if (v_29804 == nil) goto v_29715;
    goto v_29723;
v_29719:
    v_29805 = stack[-3];
    goto v_29720;
v_29721:
    v_29804 = stack[-2];
    goto v_29722;
v_29723:
    goto v_29719;
v_29720:
    goto v_29721;
v_29722:
    v_29804 = *(LispObject *)((char *)v_29805 + (CELL-TAG_VECTOR) + (((intptr_t)v_29804-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_29804;
    v_29804 = stack[-1];
    fn = elt(env, 1); // talp_fop
    v_29804 = (*qfn1(fn))(fn, v_29804);
    env = stack[-6];
    v_29804 = Lconsp(nil, v_29804);
    env = stack[-6];
    if (v_29804 == nil) goto v_29731;
    goto v_29745;
v_29741:
    v_29804 = stack[-1];
    fn = elt(env, 1); // talp_fop
    v_29804 = (*qfn1(fn))(fn, v_29804);
    env = stack[-6];
    fn = elt(env, 2); // talp_invf
    stack[0] = (*qfn1(fn))(fn, v_29804);
    env = stack[-6];
    goto v_29742;
v_29743:
    v_29804 = stack[-4];
    fn = elt(env, 1); // talp_fop
    v_29804 = (*qfn1(fn))(fn, v_29804);
    env = stack[-6];
    fn = elt(env, 2); // talp_invf
    v_29804 = (*qfn1(fn))(fn, v_29804);
    env = stack[-6];
    goto v_29744;
v_29745:
    goto v_29741;
v_29742:
    goto v_29743;
v_29744:
    if (stack[0] == v_29804) goto v_29739;
    else goto v_29740;
v_29739:
    goto v_29756;
v_29752:
    v_29804 = stack[-1];
    fn = elt(env, 1); // talp_fop
    v_29804 = (*qfn1(fn))(fn, v_29804);
    env = stack[-6];
    fn = elt(env, 3); // talp_invn
    stack[0] = (*qfn1(fn))(fn, v_29804);
    env = stack[-6];
    goto v_29753;
v_29754:
    v_29804 = stack[-4];
    fn = elt(env, 1); // talp_fop
    v_29804 = (*qfn1(fn))(fn, v_29804);
    env = stack[-6];
    fn = elt(env, 3); // talp_invn
    v_29804 = (*qfn1(fn))(fn, v_29804);
    env = stack[-6];
    goto v_29755;
v_29756:
    goto v_29752;
v_29753:
    goto v_29754;
v_29755:
    v_29804 = (stack[0] == v_29804 ? lisp_true : nil);
    goto v_29738;
v_29740:
    v_29804 = nil;
    goto v_29738;
    v_29804 = nil;
v_29738:
    if (v_29804 == nil) goto v_29731;
    v_29804 = lisp_true;
    stack[-5] = v_29804;
    goto v_29729;
v_29731:
    v_29804 = stack[-2];
    v_29804 = add1(v_29804);
    env = stack[-6];
    stack[-2] = v_29804;
    goto v_29729;
v_29729:
    goto v_29687;
v_29715:
    goto v_29778;
v_29774:
    goto v_29784;
v_29780:
    v_29805 = stack[-3];
    goto v_29781;
v_29782:
    v_29804 = stack[-2];
    goto v_29783;
v_29784:
    goto v_29780;
v_29781:
    goto v_29782;
v_29783:
    v_29804 = *(LispObject *)((char *)v_29805 + (CELL-TAG_VECTOR) + (((intptr_t)v_29804-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 1); // talp_fop
    stack[0] = (*qfn1(fn))(fn, v_29804);
    env = stack[-6];
    goto v_29775;
v_29776:
    v_29804 = stack[-4];
    fn = elt(env, 1); // talp_fop
    v_29804 = (*qfn1(fn))(fn, v_29804);
    env = stack[-6];
    goto v_29777;
v_29778:
    goto v_29774;
v_29775:
    goto v_29776;
v_29777:
    if (stack[0] == v_29804) goto v_29772;
    else goto v_29773;
v_29772:
    v_29804 = lisp_true;
    stack[-5] = v_29804;
    goto v_29687;
v_29773:
    v_29804 = stack[-2];
    v_29804 = add1(v_29804);
    env = stack[-6];
    stack[-2] = v_29804;
    goto v_29687;
v_29687:
    goto v_29668;
v_29667:
    v_29804 = stack[-5];
    if (v_29804 == nil) goto v_29798;
    v_29804 = stack[-2];
    goto v_29796;
v_29798:
    v_29804 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_29796;
    v_29804 = nil;
v_29796:
    return onevalue(v_29804);
}



// Code for qqe_length!-graph!-neighbor!-edge

static LispObject CC_qqe_lengthKgraphKneighborKedge(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29664;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29664 = v_29658;
// end of prologue
    v_29664 = qcdr(v_29664);
    v_29664 = qcdr(v_29664);
    v_29664 = qcar(v_29664);
    return onevalue(v_29664);
}



// Code for pasf_dnf

static LispObject CC_pasf_dnf(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29684, v_29685;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29658);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_29658;
// end of prologue
    goto v_29669;
v_29665:
    v_29685 = stack[0];
    goto v_29666;
v_29667:
    v_29684 = elt(env, 1); // and
    goto v_29668;
v_29669:
    goto v_29665;
v_29666:
    goto v_29667;
v_29668:
    fn = elt(env, 3); // pasf_puregconp
    v_29684 = (*qfn2(fn))(fn, v_29685, v_29684);
    env = stack[-1];
    if (v_29684 == nil) goto v_29663;
    v_29684 = stack[0];
    goto v_29661;
v_29663:
    goto v_29680;
v_29676:
    v_29684 = stack[0];
    fn = elt(env, 4); // pasf_pnf
    v_29685 = (*qfn1(fn))(fn, v_29684);
    env = stack[-1];
    goto v_29677;
v_29678:
    v_29684 = elt(env, 2); // dnf
    goto v_29679;
v_29680:
    goto v_29676;
v_29677:
    goto v_29678;
v_29679:
    {
        fn = elt(env, 5); // pasf_pbnf
        return (*qfn2(fn))(fn, v_29685, v_29684);
    }
    v_29684 = nil;
v_29661:
    return onevalue(v_29684);
}



// Code for ofsf_pop

static LispObject CC_ofsf_pop(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29661;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29661 = v_29658;
// end of prologue
    return onevalue(v_29661);
}



// Code for ezgcd!-comfac

static LispObject CC_ezgcdKcomfac(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29826, v_29827, v_29828;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29658);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_29658;
// end of prologue
    v_29826 = stack[-1];
    if (!consp(v_29826)) goto v_29666;
    else goto v_29667;
v_29666:
    v_29826 = lisp_true;
    goto v_29665;
v_29667:
    v_29826 = stack[-1];
    v_29826 = qcar(v_29826);
    v_29826 = (consp(v_29826) ? nil : lisp_true);
    goto v_29665;
    v_29826 = nil;
v_29665:
    if (v_29826 == nil) goto v_29663;
    goto v_29680;
v_29676:
    stack[0] = nil;
    goto v_29677;
v_29678:
    v_29826 = stack[-1];
    fn = elt(env, 1); // poly!-abs
    v_29826 = (*qfn1(fn))(fn, v_29826);
    goto v_29679;
v_29680:
    goto v_29676;
v_29677:
    goto v_29678;
v_29679:
    {
        LispObject v_29832 = stack[0];
        return cons(v_29832, v_29826);
    }
v_29663:
    v_29826 = stack[-1];
    v_29826 = qcdr(v_29826);
    if (v_29826 == nil) goto v_29684;
    else goto v_29685;
v_29684:
    goto v_29693;
v_29689:
    v_29826 = stack[-1];
    v_29826 = qcar(v_29826);
    stack[0] = qcar(v_29826);
    goto v_29690;
v_29691:
    v_29826 = stack[-1];
    v_29826 = qcar(v_29826);
    v_29826 = qcdr(v_29826);
    fn = elt(env, 1); // poly!-abs
    v_29826 = (*qfn1(fn))(fn, v_29826);
    goto v_29692;
v_29693:
    goto v_29689;
v_29690:
    goto v_29691;
v_29692:
    {
        LispObject v_29833 = stack[0];
        return cons(v_29833, v_29826);
    }
v_29685:
    stack[-2] = nil;
    v_29828 = nil;
    v_29826 = stack[-1];
    v_29826 = qcar(v_29826);
    v_29826 = qcar(v_29826);
    v_29826 = qcar(v_29826);
    stack[0] = v_29826;
v_29714:
    goto v_29727;
v_29723:
    v_29826 = stack[-1];
    v_29826 = qcar(v_29826);
    v_29826 = qcar(v_29826);
    v_29827 = qcar(v_29826);
    goto v_29724;
v_29725:
    v_29826 = stack[0];
    goto v_29726;
v_29727:
    goto v_29723;
v_29724:
    goto v_29725;
v_29726:
    if (equal(v_29827, v_29826)) goto v_29721;
    else goto v_29722;
v_29721:
    v_29826 = stack[-1];
    v_29826 = qcdr(v_29826);
    if (!consp(v_29826)) goto v_29735;
    else goto v_29736;
v_29735:
    v_29826 = lisp_true;
    goto v_29734;
v_29736:
    v_29826 = stack[-1];
    v_29826 = qcdr(v_29826);
    v_29826 = qcar(v_29826);
    v_29826 = (consp(v_29826) ? nil : lisp_true);
    goto v_29734;
    v_29826 = nil;
v_29734:
    v_29826 = (v_29826 == nil ? lisp_true : nil);
    goto v_29720;
v_29722:
    v_29826 = nil;
    goto v_29720;
    v_29826 = nil;
v_29720:
    if (v_29826 == nil) goto v_29717;
    else goto v_29718;
v_29717:
    goto v_29713;
v_29718:
    goto v_29756;
v_29752:
    v_29826 = stack[-1];
    v_29826 = qcar(v_29826);
    v_29826 = qcdr(v_29826);
    goto v_29753;
v_29754:
    v_29827 = v_29828;
    goto v_29755;
v_29756:
    goto v_29752;
v_29753:
    goto v_29754;
v_29755:
    v_29826 = cons(v_29826, v_29827);
    env = stack[-3];
    v_29828 = v_29826;
    v_29826 = stack[-1];
    v_29826 = qcdr(v_29826);
    stack[-1] = v_29826;
    goto v_29714;
v_29713:
    goto v_29771;
v_29767:
    v_29826 = stack[-1];
    v_29826 = qcar(v_29826);
    v_29826 = qcar(v_29826);
    v_29827 = qcar(v_29826);
    goto v_29768;
v_29769:
    v_29826 = stack[0];
    goto v_29770;
v_29771:
    goto v_29767;
v_29768:
    goto v_29769;
v_29770:
    if (equal(v_29827, v_29826)) goto v_29765;
    else goto v_29766;
v_29765:
    goto v_29782;
v_29778:
    v_29826 = stack[-1];
    v_29826 = qcar(v_29826);
    v_29826 = qcdr(v_29826);
    goto v_29779;
v_29780:
    v_29827 = v_29828;
    goto v_29781;
v_29782:
    goto v_29778;
v_29779:
    goto v_29780;
v_29781:
    v_29826 = cons(v_29826, v_29827);
    env = stack[-3];
    v_29828 = v_29826;
    v_29826 = stack[-1];
    v_29826 = qcdr(v_29826);
    if (v_29826 == nil) goto v_29789;
    else goto v_29790;
v_29789:
    v_29826 = stack[-1];
    v_29826 = qcar(v_29826);
    v_29826 = qcar(v_29826);
    stack[-2] = v_29826;
    goto v_29788;
v_29790:
    goto v_29803;
v_29799:
    v_29826 = stack[-1];
    v_29826 = qcdr(v_29826);
    goto v_29800;
v_29801:
    v_29827 = v_29828;
    goto v_29802;
v_29803:
    goto v_29799;
v_29800:
    goto v_29801;
v_29802:
    v_29826 = cons(v_29826, v_29827);
    env = stack[-3];
    v_29828 = v_29826;
    goto v_29788;
v_29788:
    goto v_29764;
v_29766:
    goto v_29814;
v_29810:
    v_29826 = stack[-1];
    goto v_29811;
v_29812:
    v_29827 = v_29828;
    goto v_29813;
v_29814:
    goto v_29810;
v_29811:
    goto v_29812;
v_29813:
    v_29826 = cons(v_29826, v_29827);
    env = stack[-3];
    v_29828 = v_29826;
    goto v_29764;
v_29764:
    goto v_29822;
v_29818:
    stack[0] = stack[-2];
    goto v_29819;
v_29820:
    v_29826 = v_29828;
    fn = elt(env, 2); // gcdlist
    v_29826 = (*qfn1(fn))(fn, v_29826);
    goto v_29821;
v_29822:
    goto v_29818;
v_29819:
    goto v_29820;
v_29821:
    {
        LispObject v_29834 = stack[0];
        return cons(v_29834, v_29826);
    }
    goto v_29661;
    v_29826 = nil;
v_29661:
    return onevalue(v_29826);
}



// Code for dipcontenti

static LispObject CC_dipcontenti(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29720, v_29721, v_29722, v_29723;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29723 = v_29658;
// end of prologue
    v_29720 = v_29723;
    if (v_29720 == nil) goto v_29662;
    else goto v_29663;
v_29662:
    v_29720 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29661;
v_29663:
    v_29720 = v_29723;
    v_29720 = qcdr(v_29720);
    v_29720 = qcdr(v_29720);
    v_29722 = v_29720;
    v_29720 = v_29722;
    if (v_29720 == nil) goto v_29674;
    else goto v_29675;
v_29674:
    goto v_29682;
v_29678:
    v_29720 = v_29723;
    v_29720 = qcdr(v_29720);
    v_29720 = qcar(v_29720);
    goto v_29679;
v_29680:
    v_29721 = qvalue(elt(env, 1)); // !*groebrm
    if (v_29721 == nil) goto v_29689;
    v_29721 = v_29723;
    v_29721 = qcar(v_29721);
    goto v_29687;
v_29689:
    v_29721 = nil;
    goto v_29687;
    v_29721 = nil;
v_29687:
    goto v_29681;
v_29682:
    goto v_29678;
v_29679:
    goto v_29680;
v_29681:
    return cons(v_29720, v_29721);
v_29675:
    goto v_29705;
v_29699:
    v_29720 = v_29723;
    v_29720 = qcdr(v_29720);
    v_29721 = qcar(v_29720);
    goto v_29700;
v_29701:
    v_29720 = qvalue(elt(env, 1)); // !*groebrm
    if (v_29720 == nil) goto v_29712;
    v_29720 = v_29723;
    v_29720 = qcar(v_29720);
    goto v_29710;
v_29712:
    v_29720 = nil;
    goto v_29710;
    v_29720 = nil;
v_29710:
    goto v_29702;
v_29703:
    goto v_29704;
v_29705:
    goto v_29699;
v_29700:
    goto v_29701;
v_29702:
    goto v_29703;
v_29704:
    {
        fn = elt(env, 2); // dipcontenti1
        return (*qfnn(fn))(fn, 3, v_29721, v_29720, v_29722);
    }
    v_29720 = nil;
    goto v_29661;
    v_29720 = nil;
v_29661:
    return onevalue(v_29720);
}



// Code for ratmean

static LispObject CC_ratmean(LispObject env,
                         LispObject v_29658, LispObject v_29659)
{
    env = qenv(env);
    LispObject v_29672, v_29673, v_29674;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29672 = v_29659;
    v_29673 = v_29658;
// end of prologue
    goto v_29668;
v_29662:
    v_29674 = v_29673;
    goto v_29663;
v_29664:
    v_29673 = v_29672;
    goto v_29665;
v_29666:
    v_29672 = lisp_true;
    goto v_29667;
v_29668:
    goto v_29662;
v_29663:
    goto v_29664;
v_29665:
    goto v_29666;
v_29667:
    {
        fn = elt(env, 1); // ratplusm
        return (*qfnn(fn))(fn, 3, v_29674, v_29673, v_29672);
    }
}



// Code for lispcodeexp

static LispObject CC_lispcodeexp(LispObject env,
                         LispObject v_29658, LispObject v_29659)
{
    env = qenv(env);
    LispObject v_30210, v_30211, v_30212;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29659,v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29658,v_29659);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_29659;
    stack[-2] = v_29658;
// end of prologue
v_29657:
    v_30210 = stack[-2];
    if (is_number(v_30210)) goto v_29665;
    else goto v_29666;
v_29665:
    v_30210 = stack[-3];
    if (v_30210 == nil) goto v_29671;
    v_30210 = stack[-2];
        return Lfloat(nil, v_30210);
v_29671:
    v_30210 = stack[-2];
    goto v_29669;
    v_30210 = nil;
v_29669:
    goto v_29664;
v_29666:
    goto v_29684;
v_29680:
    v_30211 = stack[-2];
    goto v_29681;
v_29682:
    v_30210 = elt(env, 1); // e
    goto v_29683;
v_29684:
    goto v_29680;
v_29681:
    goto v_29682;
v_29683:
    if (v_30211 == v_30210) goto v_29678;
    else goto v_29679;
v_29678:
    goto v_29692;
v_29688:
    goto v_29698;
v_29694:
    v_30211 = elt(env, 2); // exp
    goto v_29695;
v_29696:
    v_30210 = elt(env, 3); // 1.0
    goto v_29697;
v_29698:
    goto v_29694;
v_29695:
    goto v_29696;
v_29697:
    v_30211 = list2(v_30211, v_30210);
    env = stack[-5];
    goto v_29689;
v_29690:
    v_30210 = stack[-3];
    goto v_29691;
v_29692:
    goto v_29688;
v_29689:
    goto v_29690;
v_29691:
    stack[-2] = v_30211;
    stack[-3] = v_30210;
    goto v_29657;
v_29679:
    v_30210 = stack[-2];
    if (!consp(v_30210)) goto v_29706;
    else goto v_29707;
v_29706:
    v_30210 = lisp_true;
    goto v_29705;
v_29707:
    goto v_29716;
v_29712:
    v_30210 = stack[-2];
    v_30211 = qcar(v_30210);
    goto v_29713;
v_29714:
    v_30210 = elt(env, 4); // (!:rd!: !:cr!: !:crn!: !:gi!:)
    goto v_29715;
v_29716:
    goto v_29712;
v_29713:
    goto v_29714;
v_29715:
    v_30210 = Lmemq(nil, v_30211, v_30210);
    goto v_29705;
    v_30210 = nil;
v_29705:
    if (v_30210 == nil) goto v_29703;
    v_30210 = qvalue(elt(env, 5)); // irena!-constants
    if (v_30210 == nil) goto v_29724;
    v_30210 = stack[-2];
    if (v_30210 == nil) goto v_29724;
    v_30210 = stack[-2];
    v_30210 = Lstringp(nil, v_30210);
    env = stack[-5];
    if (v_30210 == nil) goto v_29730;
    else goto v_29724;
v_29730:
    v_30210 = stack[-2];
    fn = elt(env, 19); // check!-for!-irena!-constants
    v_30210 = (*qfn1(fn))(fn, v_30210);
    goto v_29722;
v_29724:
v_29722:
    v_30210 = stack[-2];
    goto v_29664;
v_29703:
    goto v_29742;
v_29738:
    v_30210 = stack[-2];
    v_30211 = qcar(v_30210);
    goto v_29739;
v_29740:
    v_30210 = elt(env, 6); // expt
    goto v_29741;
v_29742:
    goto v_29738;
v_29739:
    goto v_29740;
v_29741:
    if (v_30211 == v_30210) goto v_29736;
    else goto v_29737;
v_29736:
    goto v_29754;
v_29750:
    v_30210 = stack[-2];
    v_30210 = qcdr(v_30210);
    v_30211 = qcar(v_30210);
    goto v_29751;
v_29752:
    v_30210 = elt(env, 1); // e
    goto v_29753;
v_29754:
    goto v_29750;
v_29751:
    goto v_29752;
v_29753:
    if (v_30211 == v_30210) goto v_29748;
    else goto v_29749;
v_29748:
    goto v_29764;
v_29760:
    goto v_29770;
v_29766:
    v_30211 = elt(env, 2); // exp
    goto v_29767;
v_29768:
    v_30210 = stack[-2];
    v_30210 = qcdr(v_30210);
    v_30210 = qcdr(v_30210);
    v_30210 = qcar(v_30210);
    goto v_29769;
v_29770:
    goto v_29766;
v_29767:
    goto v_29768;
v_29769:
    v_30211 = list2(v_30211, v_30210);
    env = stack[-5];
    goto v_29761;
v_29762:
    v_30210 = stack[-3];
    goto v_29763;
v_29764:
    goto v_29760;
v_29761:
    goto v_29762;
v_29763:
    stack[-2] = v_30211;
    stack[-3] = v_30210;
    goto v_29657;
v_29749:
    goto v_29783;
v_29779:
    v_30210 = stack[-2];
    v_30210 = qcdr(v_30210);
    v_30210 = qcdr(v_30210);
    v_30211 = qcar(v_30210);
    goto v_29780;
v_29781:
    v_30210 = elt(env, 7); // (quotient 1 2)
    goto v_29782;
v_29783:
    goto v_29779;
v_29780:
    goto v_29781;
v_29782:
    if (equal(v_30211, v_30210)) goto v_29777;
    else goto v_29778;
v_29777:
    goto v_29794;
v_29790:
    goto v_29800;
v_29796:
    v_30211 = elt(env, 8); // sqrt
    goto v_29797;
v_29798:
    v_30210 = stack[-2];
    v_30210 = qcdr(v_30210);
    v_30210 = qcar(v_30210);
    goto v_29799;
v_29800:
    goto v_29796;
v_29797:
    goto v_29798;
v_29799:
    v_30211 = list2(v_30211, v_30210);
    env = stack[-5];
    goto v_29791;
v_29792:
    v_30210 = stack[-3];
    goto v_29793;
v_29794:
    goto v_29790;
v_29791:
    goto v_29792;
v_29793:
    stack[-2] = v_30211;
    stack[-3] = v_30210;
    goto v_29657;
v_29778:
    goto v_29813;
v_29809:
    v_30210 = stack[-2];
    v_30210 = qcdr(v_30210);
    v_30210 = qcdr(v_30210);
    v_30211 = qcar(v_30210);
    goto v_29810;
v_29811:
    v_30210 = elt(env, 9); // !:rd!:
    goto v_29812;
v_29813:
    goto v_29809;
v_29810:
    goto v_29811;
v_29812:
    if (!consp(v_30211)) goto v_29807;
    v_30211 = qcar(v_30211);
    if (v_30211 == v_30210) goto v_29806;
    else goto v_29807;
v_29806:
    v_30210 = stack[-2];
    v_30210 = qcdr(v_30210);
    v_30210 = qcdr(v_30210);
    v_30210 = qcar(v_30210);
    fn = elt(env, 20); // realrat
    v_30210 = (*qfn1(fn))(fn, v_30210);
    env = stack[-5];
    stack[-1] = v_30210;
    goto v_29835;
v_29831:
    v_30211 = stack[-1];
    goto v_29832;
v_29833:
    v_30210 = elt(env, 10); // (1 . 2)
    goto v_29834;
v_29835:
    goto v_29831;
v_29832:
    goto v_29833;
v_29834:
    if (equal(v_30211, v_30210)) goto v_29829;
    else goto v_29830;
v_29829:
    goto v_29843;
v_29839:
    stack[0] = elt(env, 8); // sqrt
    goto v_29840;
v_29841:
    goto v_29850;
v_29846:
    v_30210 = stack[-2];
    v_30210 = qcdr(v_30210);
    v_30211 = qcar(v_30210);
    goto v_29847;
v_29848:
    v_30210 = stack[-3];
    goto v_29849;
v_29850:
    goto v_29846;
v_29847:
    goto v_29848;
v_29849:
    v_30210 = CC_lispcodeexp(elt(env, 0), v_30211, v_30210);
    goto v_29842;
v_29843:
    goto v_29839;
v_29840:
    goto v_29841;
v_29842:
    {
        LispObject v_30218 = stack[0];
        return list2(v_30218, v_30210);
    }
v_29830:
    goto v_29864;
v_29858:
    stack[0] = elt(env, 6); // expt
    goto v_29859;
v_29860:
    goto v_29871;
v_29867:
    v_30210 = stack[-2];
    v_30210 = qcdr(v_30210);
    v_30211 = qcar(v_30210);
    goto v_29868;
v_29869:
    v_30210 = stack[-3];
    goto v_29870;
v_29871:
    goto v_29867;
v_29868:
    goto v_29869;
v_29870:
    stack[-2] = CC_lispcodeexp(elt(env, 0), v_30211, v_30210);
    env = stack[-5];
    goto v_29861;
v_29862:
    goto v_29881;
v_29877:
    goto v_29889;
v_29883:
    v_30212 = elt(env, 11); // quotient
    goto v_29884;
v_29885:
    v_30210 = stack[-1];
    v_30211 = qcar(v_30210);
    goto v_29886;
v_29887:
    v_30210 = stack[-1];
    v_30210 = qcdr(v_30210);
    goto v_29888;
v_29889:
    goto v_29883;
v_29884:
    goto v_29885;
v_29886:
    goto v_29887;
v_29888:
    v_30211 = list3(v_30212, v_30211, v_30210);
    env = stack[-5];
    goto v_29878;
v_29879:
    v_30210 = nil;
    goto v_29880;
v_29881:
    goto v_29877;
v_29878:
    goto v_29879;
v_29880:
    v_30210 = CC_lispcodeexp(elt(env, 0), v_30211, v_30210);
    goto v_29863;
v_29864:
    goto v_29858;
v_29859:
    goto v_29860;
v_29861:
    goto v_29862;
v_29863:
    {
        LispObject v_30219 = stack[0];
        LispObject v_30220 = stack[-2];
        return list3(v_30219, v_30220, v_30210);
    }
    v_30210 = nil;
    goto v_29747;
v_29807:
    goto v_29905;
v_29899:
    stack[0] = elt(env, 6); // expt
    goto v_29900;
v_29901:
    goto v_29912;
v_29908:
    v_30210 = stack[-2];
    v_30210 = qcdr(v_30210);
    v_30211 = qcar(v_30210);
    goto v_29909;
v_29910:
    v_30210 = stack[-3];
    goto v_29911;
v_29912:
    goto v_29908;
v_29909:
    goto v_29910;
v_29911:
    stack[-1] = CC_lispcodeexp(elt(env, 0), v_30211, v_30210);
    env = stack[-5];
    goto v_29902;
v_29903:
    goto v_29922;
v_29918:
    v_30210 = stack[-2];
    v_30210 = qcdr(v_30210);
    v_30210 = qcdr(v_30210);
    v_30211 = qcar(v_30210);
    goto v_29919;
v_29920:
    v_30210 = nil;
    goto v_29921;
v_29922:
    goto v_29918;
v_29919:
    goto v_29920;
v_29921:
    v_30210 = CC_lispcodeexp(elt(env, 0), v_30211, v_30210);
    goto v_29904;
v_29905:
    goto v_29899;
v_29900:
    goto v_29901;
v_29902:
    goto v_29903;
v_29904:
    {
        LispObject v_30221 = stack[0];
        LispObject v_30222 = stack[-1];
        return list3(v_30221, v_30222, v_30210);
    }
    v_30210 = nil;
v_29747:
    goto v_29664;
v_29737:
    goto v_29934;
v_29930:
    v_30210 = stack[-2];
    v_30211 = qcar(v_30210);
    goto v_29931;
v_29932:
    v_30210 = elt(env, 11); // quotient
    goto v_29933;
v_29934:
    goto v_29930;
v_29931:
    goto v_29932;
v_29933:
    if (v_30211 == v_30210) goto v_29928;
    else goto v_29929;
v_29928:
    goto v_29945;
v_29939:
    stack[-1] = elt(env, 11); // quotient
    goto v_29940;
v_29941:
    goto v_29952;
v_29948:
    v_30210 = stack[-2];
    v_30210 = qcdr(v_30210);
    v_30211 = qcar(v_30210);
    goto v_29949;
v_29950:
    v_30210 = lisp_true;
    goto v_29951;
v_29952:
    goto v_29948;
v_29949:
    goto v_29950;
v_29951:
    stack[0] = CC_lispcodeexp(elt(env, 0), v_30211, v_30210);
    env = stack[-5];
    goto v_29942;
v_29943:
    goto v_29962;
v_29958:
    v_30210 = stack[-2];
    v_30210 = qcdr(v_30210);
    v_30210 = qcdr(v_30210);
    v_30211 = qcar(v_30210);
    goto v_29959;
v_29960:
    v_30210 = lisp_true;
    goto v_29961;
v_29962:
    goto v_29958;
v_29959:
    goto v_29960;
v_29961:
    v_30210 = CC_lispcodeexp(elt(env, 0), v_30211, v_30210);
    goto v_29944;
v_29945:
    goto v_29939;
v_29940:
    goto v_29941;
v_29942:
    goto v_29943;
v_29944:
    {
        LispObject v_30223 = stack[-1];
        LispObject v_30224 = stack[0];
        return list3(v_30223, v_30224, v_30210);
    }
v_29929:
    goto v_29974;
v_29970:
    v_30210 = stack[-2];
    v_30211 = qcar(v_30210);
    goto v_29971;
v_29972:
    v_30210 = elt(env, 12); // recip
    goto v_29973;
v_29974:
    goto v_29970;
v_29971:
    goto v_29972;
v_29973:
    if (v_30211 == v_30210) goto v_29968;
    else goto v_29969;
v_29968:
    v_30210 = qvalue(elt(env, 13)); // !*period
    if (v_30210 == nil) goto v_29981;
    goto v_29990;
v_29984:
    stack[-1] = elt(env, 11); // quotient
    goto v_29985;
v_29986:
    stack[0] = elt(env, 3); // 1.0
    goto v_29987;
v_29988:
    goto v_29998;
v_29994:
    v_30210 = stack[-2];
    v_30210 = qcdr(v_30210);
    v_30211 = qcar(v_30210);
    goto v_29995;
v_29996:
    v_30210 = stack[-3];
    goto v_29997;
v_29998:
    goto v_29994;
v_29995:
    goto v_29996;
v_29997:
    v_30210 = CC_lispcodeexp(elt(env, 0), v_30211, v_30210);
    goto v_29989;
v_29990:
    goto v_29984;
v_29985:
    goto v_29986;
v_29987:
    goto v_29988;
v_29989:
    {
        LispObject v_30225 = stack[-1];
        LispObject v_30226 = stack[0];
        return list3(v_30225, v_30226, v_30210);
    }
v_29981:
    goto v_30012;
v_30006:
    stack[-1] = elt(env, 11); // quotient
    goto v_30007;
v_30008:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30009;
v_30010:
    goto v_30020;
v_30016:
    v_30210 = stack[-2];
    v_30210 = qcdr(v_30210);
    v_30211 = qcar(v_30210);
    goto v_30017;
v_30018:
    v_30210 = stack[-3];
    goto v_30019;
v_30020:
    goto v_30016;
v_30017:
    goto v_30018;
v_30019:
    v_30210 = CC_lispcodeexp(elt(env, 0), v_30211, v_30210);
    goto v_30011;
v_30012:
    goto v_30006;
v_30007:
    goto v_30008;
v_30009:
    goto v_30010;
v_30011:
    {
        LispObject v_30227 = stack[-1];
        LispObject v_30228 = stack[0];
        return list3(v_30227, v_30228, v_30210);
    }
    v_30210 = nil;
    goto v_29664;
v_29969:
    goto v_30031;
v_30027:
    v_30210 = stack[-2];
    v_30211 = qcar(v_30210);
    goto v_30028;
v_30029:
    v_30210 = elt(env, 14); // difference
    goto v_30030;
v_30031:
    goto v_30027;
v_30028:
    goto v_30029;
v_30030:
    if (v_30211 == v_30210) goto v_30025;
    else goto v_30026;
v_30025:
    goto v_30042;
v_30036:
    stack[-4] = elt(env, 15); // plus
    goto v_30037;
v_30038:
    goto v_30049;
v_30045:
    v_30210 = stack[-2];
    v_30210 = qcdr(v_30210);
    v_30211 = qcar(v_30210);
    goto v_30046;
v_30047:
    v_30210 = stack[-3];
    goto v_30048;
v_30049:
    goto v_30045;
v_30046:
    goto v_30047;
v_30048:
    stack[-1] = CC_lispcodeexp(elt(env, 0), v_30211, v_30210);
    env = stack[-5];
    goto v_30039;
v_30040:
    goto v_30059;
v_30055:
    stack[0] = elt(env, 16); // minus
    goto v_30056;
v_30057:
    goto v_30066;
v_30062:
    v_30210 = stack[-2];
    v_30210 = qcdr(v_30210);
    v_30210 = qcdr(v_30210);
    v_30211 = qcar(v_30210);
    goto v_30063;
v_30064:
    v_30210 = stack[-3];
    goto v_30065;
v_30066:
    goto v_30062;
v_30063:
    goto v_30064;
v_30065:
    v_30210 = CC_lispcodeexp(elt(env, 0), v_30211, v_30210);
    env = stack[-5];
    goto v_30058;
v_30059:
    goto v_30055;
v_30056:
    goto v_30057;
v_30058:
    v_30210 = list2(stack[0], v_30210);
    goto v_30041;
v_30042:
    goto v_30036;
v_30037:
    goto v_30038;
v_30039:
    goto v_30040;
v_30041:
    {
        LispObject v_30229 = stack[-4];
        LispObject v_30230 = stack[-1];
        return list3(v_30229, v_30230, v_30210);
    }
v_30026:
    goto v_30082;
v_30078:
    v_30210 = stack[-2];
    v_30211 = qcar(v_30210);
    goto v_30079;
v_30080:
    v_30210 = qvalue(elt(env, 17)); // !*lisparithexpops!*
    goto v_30081;
v_30082:
    goto v_30078;
v_30079:
    goto v_30080;
v_30081:
    v_30210 = Lmemq(nil, v_30211, v_30210);
    if (v_30210 == nil) goto v_30076;
    else goto v_30077;
v_30076:
    goto v_30091;
v_30087:
    v_30210 = stack[-2];
    v_30211 = qcar(v_30210);
    goto v_30088;
v_30089:
    v_30210 = qvalue(elt(env, 18)); // !*lisplogexpops!*
    goto v_30090;
v_30091:
    goto v_30087;
v_30088:
    goto v_30089;
v_30090:
    v_30210 = Lmemq(nil, v_30211, v_30210);
    v_30210 = (v_30210 == nil ? lisp_true : nil);
    goto v_30075;
v_30077:
    v_30210 = nil;
    goto v_30075;
    v_30210 = nil;
v_30075:
    if (v_30210 == nil) goto v_30073;
    v_30210 = stack[-2];
    stack[-3] = v_30210;
    v_30210 = stack[-3];
    if (v_30210 == nil) goto v_30109;
    else goto v_30110;
v_30109:
    v_30210 = nil;
    goto v_30104;
v_30110:
    v_30210 = stack[-3];
    v_30210 = qcar(v_30210);
    goto v_30122;
v_30118:
    v_30211 = v_30210;
    goto v_30119;
v_30120:
    v_30210 = nil;
    goto v_30121;
v_30122:
    goto v_30118;
v_30119:
    goto v_30120;
v_30121:
    v_30210 = CC_lispcodeexp(elt(env, 0), v_30211, v_30210);
    env = stack[-5];
    v_30210 = ncons(v_30210);
    env = stack[-5];
    stack[-1] = v_30210;
    stack[-2] = v_30210;
v_30105:
    v_30210 = stack[-3];
    v_30210 = qcdr(v_30210);
    stack[-3] = v_30210;
    v_30210 = stack[-3];
    if (v_30210 == nil) goto v_30129;
    else goto v_30130;
v_30129:
    v_30210 = stack[-2];
    goto v_30104;
v_30130:
    goto v_30138;
v_30134:
    stack[0] = stack[-1];
    goto v_30135;
v_30136:
    v_30210 = stack[-3];
    v_30210 = qcar(v_30210);
    goto v_30149;
v_30145:
    v_30211 = v_30210;
    goto v_30146;
v_30147:
    v_30210 = nil;
    goto v_30148;
v_30149:
    goto v_30145;
v_30146:
    goto v_30147;
v_30148:
    v_30210 = CC_lispcodeexp(elt(env, 0), v_30211, v_30210);
    env = stack[-5];
    v_30210 = ncons(v_30210);
    env = stack[-5];
    goto v_30137;
v_30138:
    goto v_30134;
v_30135:
    goto v_30136;
v_30137:
    v_30210 = Lrplacd(nil, stack[0], v_30210);
    env = stack[-5];
    v_30210 = stack[-1];
    v_30210 = qcdr(v_30210);
    stack[-1] = v_30210;
    goto v_30105;
v_30104:
    goto v_29664;
v_30073:
    v_30210 = stack[-2];
    stack[-4] = v_30210;
    v_30210 = stack[-4];
    if (v_30210 == nil) goto v_30165;
    else goto v_30166;
v_30165:
    v_30210 = nil;
    goto v_30160;
v_30166:
    v_30210 = stack[-4];
    v_30210 = qcar(v_30210);
    goto v_30178;
v_30174:
    v_30211 = v_30210;
    goto v_30175;
v_30176:
    v_30210 = stack[-3];
    goto v_30177;
v_30178:
    goto v_30174;
v_30175:
    goto v_30176;
v_30177:
    v_30210 = CC_lispcodeexp(elt(env, 0), v_30211, v_30210);
    env = stack[-5];
    v_30210 = ncons(v_30210);
    env = stack[-5];
    stack[-1] = v_30210;
    stack[-2] = v_30210;
v_30161:
    v_30210 = stack[-4];
    v_30210 = qcdr(v_30210);
    stack[-4] = v_30210;
    v_30210 = stack[-4];
    if (v_30210 == nil) goto v_30185;
    else goto v_30186;
v_30185:
    v_30210 = stack[-2];
    goto v_30160;
v_30186:
    goto v_30194;
v_30190:
    stack[0] = stack[-1];
    goto v_30191;
v_30192:
    v_30210 = stack[-4];
    v_30210 = qcar(v_30210);
    goto v_30205;
v_30201:
    v_30211 = v_30210;
    goto v_30202;
v_30203:
    v_30210 = stack[-3];
    goto v_30204;
v_30205:
    goto v_30201;
v_30202:
    goto v_30203;
v_30204:
    v_30210 = CC_lispcodeexp(elt(env, 0), v_30211, v_30210);
    env = stack[-5];
    v_30210 = ncons(v_30210);
    env = stack[-5];
    goto v_30193;
v_30194:
    goto v_30190;
v_30191:
    goto v_30192;
v_30193:
    v_30210 = Lrplacd(nil, stack[0], v_30210);
    env = stack[-5];
    v_30210 = stack[-1];
    v_30210 = qcdr(v_30210);
    stack[-1] = v_30210;
    goto v_30161;
v_30160:
    goto v_29664;
    v_30210 = nil;
v_29664:
    return onevalue(v_30210);
}



// Code for defined_vertex

static LispObject CC_defined_vertex(LispObject env,
                         LispObject v_29658, LispObject v_29659)
{
    env = qenv(env);
    LispObject v_29690, v_29691;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29659,v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29658,v_29659);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_29659;
    stack[-1] = v_29658;
// end of prologue
v_29663:
    v_29690 = stack[-1];
    if (v_29690 == nil) goto v_29666;
    else goto v_29667;
v_29666:
    v_29690 = lisp_true;
    goto v_29662;
v_29667:
    goto v_29681;
v_29677:
    v_29690 = stack[-1];
    v_29691 = qcar(v_29690);
    goto v_29678;
v_29679:
    v_29690 = stack[0];
    goto v_29680;
v_29681:
    goto v_29677;
v_29678:
    goto v_29679;
v_29680:
    fn = elt(env, 1); // memq_edgelist
    v_29690 = (*qfn2(fn))(fn, v_29691, v_29690);
    env = stack[-2];
    if (v_29690 == nil) goto v_29675;
    v_29690 = stack[-1];
    v_29690 = qcdr(v_29690);
    stack[-1] = v_29690;
    goto v_29663;
v_29675:
    v_29690 = nil;
    goto v_29662;
    goto v_29665;
v_29665:
    v_29690 = nil;
v_29662:
    return onevalue(v_29690);
}



// Code for mo!=expvec2a1

static LispObject CC_moMexpvec2a1(LispObject env,
                         LispObject v_29658, LispObject v_29659)
{
    env = qenv(env);
    LispObject v_29735, v_29736, v_29737;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29659,v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29658,v_29659);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_29659;
    stack[-1] = v_29658;
// end of prologue
    stack[-2] = nil;
v_29664:
    v_29735 = stack[-1];
    if (v_29735 == nil) goto v_29667;
    else goto v_29668;
v_29667:
    v_29735 = stack[-2];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_29735);
    }
v_29668:
    goto v_29678;
v_29674:
    v_29735 = stack[-1];
    v_29736 = qcar(v_29735);
    goto v_29675;
v_29676:
    v_29735 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29677;
v_29678:
    goto v_29674;
v_29675:
    goto v_29676;
v_29677:
    if (v_29736 == v_29735) goto v_29672;
    else goto v_29673;
v_29672:
    v_29735 = stack[-1];
    v_29735 = qcdr(v_29735);
    stack[-1] = v_29735;
    v_29735 = stack[0];
    v_29735 = qcdr(v_29735);
    stack[0] = v_29735;
    goto v_29664;
v_29673:
    goto v_29692;
v_29688:
    v_29735 = stack[-1];
    v_29736 = qcar(v_29735);
    goto v_29689;
v_29690:
    v_29735 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29691;
v_29692:
    goto v_29688;
v_29689:
    goto v_29690;
v_29691:
    if (v_29736 == v_29735) goto v_29686;
    else goto v_29687;
v_29686:
    goto v_29701;
v_29697:
    v_29735 = stack[0];
    v_29736 = qcar(v_29735);
    goto v_29698;
v_29699:
    v_29735 = stack[-2];
    goto v_29700;
v_29701:
    goto v_29697;
v_29698:
    goto v_29699;
v_29700:
    v_29735 = cons(v_29736, v_29735);
    env = stack[-3];
    stack[-2] = v_29735;
    v_29735 = stack[-1];
    v_29735 = qcdr(v_29735);
    stack[-1] = v_29735;
    v_29735 = stack[0];
    v_29735 = qcdr(v_29735);
    stack[0] = v_29735;
    goto v_29664;
v_29687:
    goto v_29716;
v_29712:
    goto v_29724;
v_29718:
    v_29737 = elt(env, 1); // expt
    goto v_29719;
v_29720:
    v_29735 = stack[0];
    v_29736 = qcar(v_29735);
    goto v_29721;
v_29722:
    v_29735 = stack[-1];
    v_29735 = qcar(v_29735);
    goto v_29723;
v_29724:
    goto v_29718;
v_29719:
    goto v_29720;
v_29721:
    goto v_29722;
v_29723:
    v_29736 = list3(v_29737, v_29736, v_29735);
    env = stack[-3];
    goto v_29713;
v_29714:
    v_29735 = stack[-2];
    goto v_29715;
v_29716:
    goto v_29712;
v_29713:
    goto v_29714;
v_29715:
    v_29735 = cons(v_29736, v_29735);
    env = stack[-3];
    stack[-2] = v_29735;
    v_29735 = stack[-1];
    v_29735 = qcdr(v_29735);
    stack[-1] = v_29735;
    v_29735 = stack[0];
    v_29735 = qcdr(v_29735);
    stack[0] = v_29735;
    goto v_29664;
    v_29735 = nil;
    return onevalue(v_29735);
}



// Code for impartsq

static LispObject CC_impartsq(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29732, v_29733, v_29734, v_29735;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29658);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_29658;
// end of prologue
    v_29732 = stack[0];
    v_29732 = qcar(v_29732);
    fn = elt(env, 1); // splitcomplex
    stack[-1] = (*qfn1(fn))(fn, v_29732);
    env = stack[-4];
    v_29732 = stack[0];
    v_29732 = qcdr(v_29732);
    fn = elt(env, 1); // splitcomplex
    v_29732 = (*qfn1(fn))(fn, v_29732);
    env = stack[-4];
    v_29733 = stack[-1];
    v_29734 = v_29733;
    v_29735 = qcar(v_29734);
    v_29734 = qcdr(v_29733);
    v_29733 = v_29732;
    v_29733 = qcar(v_29733);
    v_29732 = qcdr(v_29732);
    stack[-3] = v_29735;
    stack[-2] = v_29733;
    stack[-1] = v_29732;
    goto v_29685;
v_29681:
    goto v_29691;
v_29687:
    goto v_29697;
v_29693:
    v_29733 = v_29734;
    goto v_29694;
v_29695:
    v_29732 = stack[-2];
    goto v_29696;
v_29697:
    goto v_29693;
v_29694:
    goto v_29695;
v_29696:
    fn = elt(env, 2); // multsq
    stack[0] = (*qfn2(fn))(fn, v_29733, v_29732);
    env = stack[-4];
    goto v_29688;
v_29689:
    goto v_29706;
v_29702:
    v_29733 = stack[-3];
    goto v_29703;
v_29704:
    v_29732 = stack[-1];
    goto v_29705;
v_29706:
    goto v_29702;
v_29703:
    goto v_29704;
v_29705:
    fn = elt(env, 2); // multsq
    v_29732 = (*qfn2(fn))(fn, v_29733, v_29732);
    env = stack[-4];
    fn = elt(env, 3); // negsq
    v_29732 = (*qfn1(fn))(fn, v_29732);
    env = stack[-4];
    goto v_29690;
v_29691:
    goto v_29687;
v_29688:
    goto v_29689;
v_29690:
    fn = elt(env, 4); // addsq
    stack[0] = (*qfn2(fn))(fn, stack[0], v_29732);
    env = stack[-4];
    goto v_29682;
v_29683:
    goto v_29715;
v_29711:
    goto v_29721;
v_29717:
    v_29733 = stack[-2];
    goto v_29718;
v_29719:
    v_29732 = stack[-2];
    goto v_29720;
v_29721:
    goto v_29717;
v_29718:
    goto v_29719;
v_29720:
    fn = elt(env, 2); // multsq
    stack[-2] = (*qfn2(fn))(fn, v_29733, v_29732);
    env = stack[-4];
    goto v_29712;
v_29713:
    goto v_29729;
v_29725:
    v_29733 = stack[-1];
    goto v_29726;
v_29727:
    v_29732 = stack[-1];
    goto v_29728;
v_29729:
    goto v_29725;
v_29726:
    goto v_29727;
v_29728:
    fn = elt(env, 2); // multsq
    v_29732 = (*qfn2(fn))(fn, v_29733, v_29732);
    env = stack[-4];
    goto v_29714;
v_29715:
    goto v_29711;
v_29712:
    goto v_29713;
v_29714:
    fn = elt(env, 4); // addsq
    v_29732 = (*qfn2(fn))(fn, stack[-2], v_29732);
    env = stack[-4];
    fn = elt(env, 5); // invsq
    v_29732 = (*qfn1(fn))(fn, v_29732);
    env = stack[-4];
    goto v_29684;
v_29685:
    goto v_29681;
v_29682:
    goto v_29683;
v_29684:
    {
        LispObject v_29740 = stack[0];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_29740, v_29732);
    }
}



// Code for talp_qesolset

static LispObject CC_talp_qesolset(LispObject env,
                         LispObject v_29658, LispObject v_29659)
{
    env = qenv(env);
    LispObject v_29787, v_29788;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29659,v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29658,v_29659);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_29659;
    stack[-2] = v_29658;
// end of prologue
    v_29787 = stack[-1];
    fn = elt(env, 4); // talp_arg2l
    v_29787 = (*qfn1(fn))(fn, v_29787);
    env = stack[-4];
    stack[-3] = v_29787;
    v_29787 = stack[-1];
    fn = elt(env, 5); // talp_arg2r
    v_29787 = (*qfn1(fn))(fn, v_29787);
    env = stack[-4];
    stack[0] = v_29787;
    goto v_29680;
v_29676:
    v_29788 = stack[-3];
    goto v_29677;
v_29678:
    v_29787 = stack[-2];
    goto v_29679;
v_29680:
    goto v_29676;
v_29677:
    goto v_29678;
v_29679:
    fn = elt(env, 6); // talp_contains
    v_29787 = (*qfn2(fn))(fn, v_29788, v_29787);
    env = stack[-4];
    if (v_29787 == nil) goto v_29674;
    else goto v_29673;
v_29674:
    goto v_29689;
v_29685:
    v_29788 = stack[0];
    goto v_29686;
v_29687:
    v_29787 = stack[-2];
    goto v_29688;
v_29689:
    goto v_29685;
v_29686:
    goto v_29687;
v_29688:
    fn = elt(env, 6); // talp_contains
    v_29787 = (*qfn2(fn))(fn, v_29788, v_29787);
    env = stack[-4];
    if (v_29787 == nil) goto v_29683;
    else goto v_29673;
v_29683:
    v_29787 = elt(env, 1); // ignore
    goto v_29665;
v_29673:
    goto v_29701;
v_29697:
    v_29787 = stack[-1];
    if (!consp(v_29787)) goto v_29704;
    else goto v_29705;
v_29704:
    v_29787 = stack[-1];
    v_29788 = v_29787;
    goto v_29703;
v_29705:
    v_29787 = stack[-1];
    v_29787 = qcar(v_29787);
    v_29788 = v_29787;
    goto v_29703;
    v_29788 = nil;
v_29703:
    goto v_29698;
v_29699:
    v_29787 = elt(env, 2); // equal
    goto v_29700;
v_29701:
    goto v_29697;
v_29698:
    goto v_29699;
v_29700:
    if (v_29788 == v_29787) goto v_29696;
    v_29787 = elt(env, 3); // failed
    goto v_29665;
v_29696:
    goto v_29724;
v_29720:
    v_29788 = stack[-3];
    goto v_29721;
v_29722:
    v_29787 = stack[-2];
    goto v_29723;
v_29724:
    goto v_29720;
v_29721:
    goto v_29722;
v_29723:
    fn = elt(env, 6); // talp_contains
    v_29787 = (*qfn2(fn))(fn, v_29788, v_29787);
    env = stack[-4];
    if (v_29787 == nil) goto v_29717;
    goto v_29733;
v_29729:
    v_29788 = stack[0];
    goto v_29730;
v_29731:
    v_29787 = stack[-2];
    goto v_29732;
v_29733:
    goto v_29729;
v_29730:
    goto v_29731;
v_29732:
    fn = elt(env, 6); // talp_contains
    v_29787 = (*qfn2(fn))(fn, v_29788, v_29787);
    env = stack[-4];
    if (v_29787 == nil) goto v_29717;
    v_29787 = elt(env, 3); // failed
    goto v_29665;
v_29717:
    goto v_29749;
v_29745:
    v_29788 = stack[-3];
    goto v_29746;
v_29747:
    v_29787 = stack[-2];
    goto v_29748;
v_29749:
    goto v_29745;
v_29746:
    goto v_29747;
v_29748:
    if (equal(v_29788, v_29787)) goto v_29744;
    goto v_29757;
v_29753:
    v_29788 = stack[0];
    goto v_29754;
v_29755:
    v_29787 = stack[-2];
    goto v_29756;
v_29757:
    goto v_29753;
v_29754:
    goto v_29755;
v_29756:
    v_29787 = Lneq(nil, v_29788, v_29787);
    env = stack[-4];
    goto v_29742;
v_29744:
    v_29787 = nil;
    goto v_29742;
    v_29787 = nil;
v_29742:
    if (v_29787 == nil) goto v_29740;
    v_29787 = elt(env, 3); // failed
    goto v_29665;
v_29740:
    goto v_29772;
v_29768:
    v_29788 = stack[-3];
    goto v_29769;
v_29770:
    v_29787 = stack[-2];
    goto v_29771;
v_29772:
    goto v_29768;
v_29769:
    goto v_29770;
v_29771:
    if (v_29788 == v_29787) goto v_29766;
    else goto v_29767;
v_29766:
    v_29787 = stack[0];
    goto v_29765;
v_29767:
    v_29787 = stack[-3];
    goto v_29765;
    v_29787 = nil;
v_29765:
    goto v_29784;
v_29780:
    v_29788 = stack[-2];
    goto v_29781;
v_29782:
    goto v_29783;
v_29784:
    goto v_29780;
v_29781:
    goto v_29782;
v_29783:
    return cons(v_29788, v_29787);
v_29665:
    return onevalue(v_29787);
}



// Code for mri_irsplit1

static LispObject CC_mri_irsplit1(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29796, v_29797;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29658);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_29658;
// end of prologue
// Binding d
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 1, -1);
    qvalue(elt(env, 1)) = nil; // d
    v_29796 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_29796; // d
    v_29796 = stack[0];
    if (!consp(v_29796)) goto v_29673;
    else goto v_29674;
v_29673:
    v_29796 = lisp_true;
    goto v_29672;
v_29674:
    v_29796 = stack[0];
    v_29796 = qcar(v_29796);
    v_29796 = (consp(v_29796) ? nil : lisp_true);
    goto v_29672;
    v_29796 = nil;
v_29672:
    if (v_29796 == nil) goto v_29670;
    v_29796 = stack[0];
    v_29796 = ncons(v_29796);
    goto v_29665;
v_29670:
    v_29796 = stack[0];
    v_29796 = qcdr(v_29796);
    v_29796 = CC_mri_irsplit1(elt(env, 0), v_29796);
    env = stack[-5];
    stack[-3] = v_29796;
    v_29796 = stack[0];
    v_29796 = qcar(v_29796);
    v_29796 = qcar(v_29796);
    v_29796 = qcdr(v_29796);
    qvalue(elt(env, 1)) = v_29796; // d
    goto v_29696;
v_29692:
    goto v_29703;
v_29699:
    goto v_29709;
v_29705:
    v_29796 = stack[0];
    v_29796 = qcar(v_29796);
    v_29796 = qcar(v_29796);
    v_29797 = qcar(v_29796);
    goto v_29706;
v_29707:
    v_29796 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29708;
v_29709:
    goto v_29705;
v_29706:
    goto v_29707;
v_29708:
    fn = elt(env, 2); // to
    v_29797 = (*qfn2(fn))(fn, v_29797, v_29796);
    env = stack[-5];
    goto v_29700;
v_29701:
    v_29796 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29702;
v_29703:
    goto v_29699;
v_29700:
    goto v_29701;
v_29702:
    v_29796 = cons(v_29797, v_29796);
    env = stack[-5];
    v_29797 = ncons(v_29796);
    env = stack[-5];
    goto v_29693;
v_29694:
    v_29796 = qvalue(elt(env, 1)); // d
    goto v_29695;
v_29696:
    goto v_29692;
v_29693:
    goto v_29694;
v_29695:
    fn = elt(env, 3); // exptf
    v_29796 = (*qfn2(fn))(fn, v_29797, v_29796);
    env = stack[-5];
    stack[-2] = v_29796;
    v_29796 = stack[-2];
    v_29796 = qcar(v_29796);
    v_29796 = qcar(v_29796);
    v_29796 = qcar(v_29796);
    fn = elt(env, 4); // mri_realvarp
    v_29796 = (*qfn1(fn))(fn, v_29796);
    env = stack[-5];
    if (v_29796 == nil) goto v_29720;
    goto v_29731;
v_29727:
    v_29796 = stack[-3];
    stack[-4] = qcar(v_29796);
    goto v_29728;
v_29729:
    goto v_29739;
v_29735:
    goto v_29745;
v_29741:
    v_29796 = stack[0];
    v_29796 = qcar(v_29796);
    v_29797 = qcdr(v_29796);
    goto v_29742;
v_29743:
    v_29796 = stack[-2];
    goto v_29744;
v_29745:
    goto v_29741;
v_29742:
    goto v_29743;
v_29744:
    fn = elt(env, 5); // multf
    v_29797 = (*qfn2(fn))(fn, v_29797, v_29796);
    env = stack[-5];
    goto v_29736;
v_29737:
    v_29796 = stack[-3];
    v_29796 = qcdr(v_29796);
    goto v_29738;
v_29739:
    goto v_29735;
v_29736:
    goto v_29737;
v_29738:
    fn = elt(env, 6); // addf
    v_29796 = (*qfn2(fn))(fn, v_29797, v_29796);
    env = stack[-5];
    goto v_29730;
v_29731:
    goto v_29727;
v_29728:
    goto v_29729;
v_29730:
    v_29796 = cons(stack[-4], v_29796);
    goto v_29665;
v_29720:
    v_29796 = stack[0];
    v_29796 = qcar(v_29796);
    v_29796 = qcdr(v_29796);
    v_29796 = CC_mri_irsplit1(elt(env, 0), v_29796);
    env = stack[-5];
    stack[-4] = v_29796;
    goto v_29761;
v_29757:
    goto v_29767;
v_29763:
    goto v_29773;
v_29769:
    v_29796 = stack[-4];
    v_29797 = qcar(v_29796);
    goto v_29770;
v_29771:
    v_29796 = stack[-2];
    goto v_29772;
v_29773:
    goto v_29769;
v_29770:
    goto v_29771;
v_29772:
    fn = elt(env, 5); // multf
    v_29797 = (*qfn2(fn))(fn, v_29797, v_29796);
    env = stack[-5];
    goto v_29764;
v_29765:
    v_29796 = stack[-3];
    v_29796 = qcar(v_29796);
    goto v_29766;
v_29767:
    goto v_29763;
v_29764:
    goto v_29765;
v_29766:
    fn = elt(env, 6); // addf
    stack[0] = (*qfn2(fn))(fn, v_29797, v_29796);
    env = stack[-5];
    goto v_29758;
v_29759:
    goto v_29784;
v_29780:
    goto v_29790;
v_29786:
    v_29796 = stack[-4];
    v_29797 = qcdr(v_29796);
    goto v_29787;
v_29788:
    v_29796 = stack[-2];
    goto v_29789;
v_29790:
    goto v_29786;
v_29787:
    goto v_29788;
v_29789:
    fn = elt(env, 5); // multf
    v_29797 = (*qfn2(fn))(fn, v_29797, v_29796);
    env = stack[-5];
    goto v_29781;
v_29782:
    v_29796 = stack[-3];
    v_29796 = qcdr(v_29796);
    goto v_29783;
v_29784:
    goto v_29780;
v_29781:
    goto v_29782;
v_29783:
    fn = elt(env, 6); // addf
    v_29796 = (*qfn2(fn))(fn, v_29797, v_29796);
    env = stack[-5];
    goto v_29760;
v_29761:
    goto v_29757;
v_29758:
    goto v_29759;
v_29760:
    v_29796 = cons(stack[0], v_29796);
v_29665:
    ;}  // end of a binding scope
    return onevalue(v_29796);
}



// Code for sqfrf

static LispObject CC_sqfrf(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_30098, v_30099, v_30100, v_30101;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29658);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_29658;
// end of prologue
// Binding !*gcd
// FLUIDBIND: reloadenv=11 litvec-offset=1 saveloc=8
{   bind_fluid_stack bind_fluid_var(-11, 1, -8);
    qvalue(elt(env, 1)) = nil; // !*gcd
    stack[-7] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
// Binding !*msg
// FLUIDBIND: reloadenv=11 litvec-offset=2 saveloc=5
{   bind_fluid_stack bind_fluid_var(-11, 2, -5);
    qvalue(elt(env, 2)) = nil; // !*msg
    v_30098 = lisp_true;
    qvalue(elt(env, 1)) = v_30098; // !*gcd
    v_30098 = qvalue(elt(env, 3)); // !*rounded
    stack[-1] = v_30098;
    if (v_30098 == nil) goto v_29677;
    v_30098 = elt(env, 4); // rational
    v_30098 = ncons(v_30098);
    env = stack[-11];
    fn = elt(env, 10); // on
    v_30098 = (*qfn1(fn))(fn, v_30098);
    env = stack[-11];
    goto v_29688;
v_29684:
    v_30099 = stack[-9];
    goto v_29685;
v_29686:
    v_30098 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29687;
v_29688:
    goto v_29684;
v_29685:
    goto v_29686;
v_29687:
    v_30098 = cons(v_30099, v_30098);
    env = stack[-11];
    fn = elt(env, 11); // resimp
    v_30098 = (*qfn1(fn))(fn, v_30098);
    env = stack[-11];
    v_30098 = qcar(v_30098);
    stack[-9] = v_30098;
    goto v_29675;
v_29677:
v_29675:
    v_30098 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-10] = v_30098;
    v_30098 = stack[-9];
    v_30098 = qcar(v_30098);
    v_30098 = qcar(v_30098);
    v_30098 = qcar(v_30098);
    stack[-4] = v_30098;
    v_30098 = lisp_true;
// Binding !*ezgcd
// FLUIDBIND: reloadenv=11 litvec-offset=5 saveloc=0
{   bind_fluid_stack bind_fluid_var(-11, 5, 0);
    qvalue(elt(env, 5)) = v_30098; // !*ezgcd
    goto v_29704;
v_29700:
    stack[-6] = stack[-9];
    goto v_29701;
v_29702:
    goto v_29711;
v_29707:
    v_30099 = stack[-9];
    goto v_29708;
v_29709:
    v_30098 = stack[-4];
    goto v_29710;
v_29711:
    goto v_29707;
v_29708:
    goto v_29709;
v_29710:
    fn = elt(env, 12); // diff
    v_30098 = (*qfn2(fn))(fn, v_30099, v_30098);
    env = stack[-11];
    goto v_29703;
v_29704:
    goto v_29700;
v_29701:
    goto v_29702;
v_29703:
    fn = elt(env, 13); // gcdf
    v_30098 = (*qfn2(fn))(fn, stack[-6], v_30098);
    env = stack[-11];
    stack[-6] = v_30098;
    ;}  // end of a binding scope
    goto v_29719;
v_29715:
    v_30099 = stack[-9];
    goto v_29716;
v_29717:
    v_30098 = stack[-6];
    goto v_29718;
v_29719:
    goto v_29715;
v_29716:
    goto v_29717;
v_29718:
    fn = elt(env, 14); // quotf!-fail
    v_30098 = (*qfn2(fn))(fn, v_30099, v_30098);
    env = stack[-11];
    stack[-9] = v_30098;
    v_30098 = qvalue(elt(env, 6)); // dmode!*
    if (!symbolp(v_30098)) v_30098 = nil;
    else { v_30098 = qfastgets(v_30098);
           if (v_30098 != nil) { v_30098 = elt(v_30098, 3); // field
#ifdef RECORD_GET
             if (v_30098 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_30098 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_30098 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_30098 == SPID_NOPROP) v_30098 = nil; else v_30098 = lisp_true; }}
#endif
    if (v_30098 == nil) goto v_29729;
    goto v_29737;
v_29733:
    v_30098 = stack[-9];
    fn = elt(env, 15); // lnc
    v_30099 = (*qfn1(fn))(fn, v_30098);
    env = stack[-11];
    stack[-3] = v_30099;
    goto v_29734;
v_29735:
    v_30098 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29736;
v_29737:
    goto v_29733;
v_29734:
    goto v_29735;
v_29736:
    v_30098 = Lneq(nil, v_30099, v_30098);
    env = stack[-11];
    goto v_29727;
v_29729:
    v_30098 = nil;
    goto v_29727;
    v_30098 = nil;
v_29727:
    if (v_30098 == nil) goto v_29725;
    goto v_29749;
v_29745:
    v_30098 = stack[-3];
    fn = elt(env, 16); // !:recip
    v_30099 = (*qfn1(fn))(fn, v_30098);
    env = stack[-11];
    goto v_29746;
v_29747:
    v_30098 = stack[-9];
    goto v_29748;
v_29749:
    goto v_29745;
v_29746:
    goto v_29747;
v_29748:
    fn = elt(env, 17); // multd
    v_30098 = (*qfn2(fn))(fn, v_30099, v_30098);
    env = stack[-11];
    stack[-9] = v_30098;
    goto v_29758;
v_29754:
    v_30099 = stack[-3];
    goto v_29755;
v_29756:
    v_30098 = stack[-6];
    goto v_29757;
v_29758:
    goto v_29754;
v_29755:
    goto v_29756;
v_29757:
    fn = elt(env, 17); // multd
    v_30098 = (*qfn2(fn))(fn, v_30099, v_30098);
    env = stack[-11];
    stack[-6] = v_30098;
    goto v_29723;
v_29725:
v_29723:
v_29763:
    goto v_29773;
v_29769:
    goto v_29779;
v_29775:
    v_30099 = stack[-6];
    goto v_29776;
v_29777:
    v_30098 = stack[-4];
    goto v_29778;
v_29779:
    goto v_29775;
v_29776:
    goto v_29777;
v_29778:
    fn = elt(env, 18); // degr
    v_30099 = (*qfn2(fn))(fn, v_30099, v_30098);
    env = stack[-11];
    goto v_29770;
v_29771:
    v_30098 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29772;
v_29773:
    goto v_29769;
v_29770:
    goto v_29771;
v_29772:
    v_30098 = (LispObject)greaterp2(v_30099, v_30098);
    v_30098 = v_30098 ? lisp_true : nil;
    env = stack[-11];
    if (v_30098 == nil) goto v_29766;
    else goto v_29767;
v_29766:
    goto v_29762;
v_29767:
    goto v_29789;
v_29785:
    v_30099 = stack[-6];
    goto v_29786;
v_29787:
    v_30098 = stack[-9];
    goto v_29788;
v_29789:
    goto v_29785;
v_29786:
    goto v_29787;
v_29788:
    fn = elt(env, 13); // gcdf
    v_30098 = (*qfn2(fn))(fn, v_30099, v_30098);
    env = stack[-11];
    stack[0] = v_30098;
    goto v_29800;
v_29796:
    v_30099 = stack[-9];
    goto v_29797;
v_29798:
    v_30098 = stack[0];
    goto v_29799;
v_29800:
    goto v_29796;
v_29797:
    goto v_29798;
v_29799:
    if (equal(v_30099, v_30098)) goto v_29795;
    goto v_29810;
v_29804:
    goto v_29816;
v_29812:
    v_30099 = stack[-9];
    goto v_29813;
v_29814:
    v_30098 = stack[0];
    goto v_29815;
v_29816:
    goto v_29812;
v_29813:
    goto v_29814;
v_29815:
    fn = elt(env, 19); // quotf
    v_30100 = (*qfn2(fn))(fn, v_30099, v_30098);
    env = stack[-11];
    goto v_29805;
v_29806:
    v_30099 = stack[-10];
    goto v_29807;
v_29808:
    v_30098 = stack[-2];
    goto v_29809;
v_29810:
    goto v_29804;
v_29805:
    goto v_29806;
v_29807:
    goto v_29808;
v_29809:
    v_30098 = acons(v_30100, v_30099, v_30098);
    env = stack[-11];
    stack[-2] = v_30098;
    goto v_29793;
v_29795:
v_29793:
    goto v_29826;
v_29822:
    v_30099 = stack[-6];
    goto v_29823;
v_29824:
    v_30098 = stack[0];
    goto v_29825;
v_29826:
    goto v_29822;
v_29823:
    goto v_29824;
v_29825:
    fn = elt(env, 19); // quotf
    v_30098 = (*qfn2(fn))(fn, v_30099, v_30098);
    env = stack[-11];
    stack[-6] = v_30098;
    v_30098 = stack[0];
    stack[-9] = v_30098;
    v_30098 = stack[-10];
    v_30098 = add1(v_30098);
    env = stack[-11];
    stack[-10] = v_30098;
    goto v_29763;
v_29762:
    v_30098 = stack[-1];
    if (v_30098 == nil) goto v_29835;
    v_30098 = elt(env, 7); // rounded
    v_30098 = ncons(v_30098);
    env = stack[-11];
    fn = elt(env, 10); // on
    v_30098 = (*qfn1(fn))(fn, v_30098);
    env = stack[-11];
    goto v_29846;
v_29842:
    v_30099 = stack[-9];
    goto v_29843;
v_29844:
    v_30098 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29845;
v_29846:
    goto v_29842;
v_29843:
    goto v_29844;
v_29845:
    v_30098 = cons(v_30099, v_30098);
    env = stack[-11];
    fn = elt(env, 11); // resimp
    v_30098 = (*qfn1(fn))(fn, v_30098);
    env = stack[-11];
    v_30098 = qcar(v_30098);
    stack[-9] = v_30098;
    v_30098 = stack[-2];
    stack[-4] = v_30098;
    v_30098 = stack[-4];
    if (v_30098 == nil) goto v_29859;
    else goto v_29860;
v_29859:
    v_30098 = nil;
    goto v_29854;
v_29860:
    v_30098 = stack[-4];
    v_30098 = qcar(v_30098);
    stack[0] = v_30098;
    goto v_29872;
v_29868:
    goto v_29879;
v_29875:
    v_30098 = stack[0];
    v_30099 = qcar(v_30098);
    goto v_29876;
v_29877:
    v_30098 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29878;
v_29879:
    goto v_29875;
v_29876:
    goto v_29877;
v_29878:
    v_30098 = cons(v_30099, v_30098);
    env = stack[-11];
    fn = elt(env, 11); // resimp
    v_30098 = (*qfn1(fn))(fn, v_30098);
    env = stack[-11];
    v_30099 = qcar(v_30098);
    goto v_29869;
v_29870:
    v_30098 = stack[0];
    v_30098 = qcdr(v_30098);
    goto v_29871;
v_29872:
    goto v_29868;
v_29869:
    goto v_29870;
v_29871:
    v_30098 = cons(v_30099, v_30098);
    env = stack[-11];
    v_30098 = ncons(v_30098);
    env = stack[-11];
    stack[-2] = v_30098;
    stack[-3] = v_30098;
v_29855:
    v_30098 = stack[-4];
    v_30098 = qcdr(v_30098);
    stack[-4] = v_30098;
    v_30098 = stack[-4];
    if (v_30098 == nil) goto v_29890;
    else goto v_29891;
v_29890:
    v_30098 = stack[-3];
    goto v_29854;
v_29891:
    goto v_29899;
v_29895:
    stack[-1] = stack[-2];
    goto v_29896;
v_29897:
    v_30098 = stack[-4];
    v_30098 = qcar(v_30098);
    stack[0] = v_30098;
    goto v_29910;
v_29906:
    goto v_29917;
v_29913:
    v_30098 = stack[0];
    v_30099 = qcar(v_30098);
    goto v_29914;
v_29915:
    v_30098 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29916;
v_29917:
    goto v_29913;
v_29914:
    goto v_29915;
v_29916:
    v_30098 = cons(v_30099, v_30098);
    env = stack[-11];
    fn = elt(env, 11); // resimp
    v_30098 = (*qfn1(fn))(fn, v_30098);
    env = stack[-11];
    v_30099 = qcar(v_30098);
    goto v_29907;
v_29908:
    v_30098 = stack[0];
    v_30098 = qcdr(v_30098);
    goto v_29909;
v_29910:
    goto v_29906;
v_29907:
    goto v_29908;
v_29909:
    v_30098 = cons(v_30099, v_30098);
    env = stack[-11];
    v_30098 = ncons(v_30098);
    env = stack[-11];
    goto v_29898;
v_29899:
    goto v_29895;
v_29896:
    goto v_29897;
v_29898:
    v_30098 = Lrplacd(nil, stack[-1], v_30098);
    env = stack[-11];
    v_30098 = stack[-2];
    v_30098 = qcdr(v_30098);
    stack[-2] = v_30098;
    goto v_29855;
v_29854:
    stack[-2] = v_30098;
    goto v_29833;
v_29835:
v_29833:
    goto v_29938;
v_29934:
    v_30099 = stack[-6];
    goto v_29935;
v_29936:
    v_30098 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29937;
v_29938:
    goto v_29934;
v_29935:
    goto v_29936;
v_29937:
    if (v_30099 == v_30098) goto v_29933;
    goto v_29945;
v_29941:
    v_30099 = stack[-6];
    goto v_29942;
v_29943:
    v_30098 = stack[-7];
    goto v_29944;
v_29945:
    goto v_29941;
v_29942:
    goto v_29943;
v_29944:
    v_30098 = Lassoc(nil, v_30099, v_30098);
    goto v_29931;
v_29933:
    v_30098 = nil;
    goto v_29931;
    v_30098 = nil;
v_29931:
    if (v_30098 == nil) goto v_29929;
    v_30098 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_30098;
    goto v_29927;
v_29929:
v_29927:
    goto v_29961;
v_29957:
    v_30099 = stack[-6];
    goto v_29958;
v_29959:
    v_30098 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29960;
v_29961:
    goto v_29957;
v_29958:
    goto v_29959;
v_29960:
    if (v_30099 == v_30098) goto v_29956;
    goto v_29972;
v_29968:
    v_30099 = stack[-10];
    goto v_29969;
v_29970:
    v_30098 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29971;
v_29972:
    goto v_29968;
v_29969:
    goto v_29970;
v_29971:
    if (v_30099 == v_30098) goto v_29966;
    else goto v_29967;
v_29966:
    goto v_29980;
v_29976:
    v_30099 = stack[-6];
    goto v_29977;
v_29978:
    v_30098 = stack[-9];
    goto v_29979;
v_29980:
    goto v_29976;
v_29977:
    goto v_29978;
v_29979:
    fn = elt(env, 20); // multf
    v_30098 = (*qfn2(fn))(fn, v_30099, v_30098);
    env = stack[-11];
    stack[-9] = v_30098;
    goto v_29965;
v_29967:
    goto v_29990;
v_29986:
    v_30099 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29987;
v_29988:
    v_30098 = stack[-2];
    goto v_29989;
v_29990:
    goto v_29986;
v_29987:
    goto v_29988;
v_29989:
    fn = elt(env, 21); // rassoc
    v_30098 = (*qfn2(fn))(fn, v_30099, v_30098);
    env = stack[-11];
    stack[0] = v_30098;
    if (v_30098 == nil) goto v_29984;
    goto v_29998;
v_29994:
    stack[-1] = stack[0];
    goto v_29995;
v_29996:
    goto v_30005;
v_30001:
    v_30099 = stack[-6];
    goto v_30002;
v_30003:
    v_30098 = stack[0];
    v_30098 = qcar(v_30098);
    goto v_30004;
v_30005:
    goto v_30001;
v_30002:
    goto v_30003;
v_30004:
    fn = elt(env, 20); // multf
    v_30098 = (*qfn2(fn))(fn, v_30099, v_30098);
    env = stack[-11];
    goto v_29997;
v_29998:
    goto v_29994;
v_29995:
    goto v_29996;
v_29997:
    v_30098 = Lrplaca(nil, stack[-1], v_30098);
    env = stack[-11];
    goto v_29965;
v_29984:
    v_30098 = stack[-2];
    if (v_30098 == nil) goto v_30013;
    else goto v_30014;
v_30013:
    goto v_30021;
v_30017:
    goto v_30027;
v_30023:
    v_30099 = stack[-6];
    goto v_30024;
v_30025:
    v_30098 = stack[-10];
    goto v_30026;
v_30027:
    goto v_30023;
v_30024:
    goto v_30025;
v_30026:
    fn = elt(env, 22); // rootxf
    v_30099 = (*qfn2(fn))(fn, v_30099, v_30098);
    env = stack[-11];
    stack[0] = v_30099;
    goto v_30018;
v_30019:
    v_30098 = elt(env, 8); // failed
    goto v_30020;
v_30021:
    goto v_30017;
v_30018:
    goto v_30019;
v_30020:
    v_30098 = Lneq(nil, v_30099, v_30098);
    env = stack[-11];
    goto v_30012;
v_30014:
    v_30098 = nil;
    goto v_30012;
    v_30098 = nil;
v_30012:
    if (v_30098 == nil) goto v_30010;
    goto v_30039;
v_30035:
    v_30099 = stack[0];
    goto v_30036;
v_30037:
    v_30098 = stack[-9];
    goto v_30038;
v_30039:
    goto v_30035;
v_30036:
    goto v_30037;
v_30038:
    fn = elt(env, 20); // multf
    v_30098 = (*qfn2(fn))(fn, v_30099, v_30098);
    env = stack[-11];
    stack[-9] = v_30098;
    goto v_29965;
v_30010:
    v_30098 = stack[-6];
    if (!consp(v_30098)) goto v_30046;
    else goto v_30047;
v_30046:
    v_30098 = lisp_true;
    goto v_30045;
v_30047:
    v_30098 = stack[-6];
    v_30098 = qcar(v_30098);
    v_30098 = (consp(v_30098) ? nil : lisp_true);
    goto v_30045;
    v_30098 = nil;
v_30045:
    if (v_30098 == nil) goto v_30042;
    else goto v_30043;
v_30042:
    goto v_30060;
v_30056:
    stack[0] = stack[-2];
    goto v_30057;
v_30058:
    goto v_30067;
v_30063:
    v_30099 = stack[-6];
    goto v_30064;
v_30065:
    v_30098 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30066;
v_30067:
    goto v_30063;
v_30064:
    goto v_30065;
v_30066:
    v_30098 = cons(v_30099, v_30098);
    env = stack[-11];
    goto v_30059;
v_30060:
    goto v_30056;
v_30057:
    goto v_30058;
v_30059:
    fn = elt(env, 23); // aconc
    v_30098 = (*qfn2(fn))(fn, stack[0], v_30098);
    env = stack[-11];
    stack[-2] = v_30098;
    goto v_29965;
v_30043:
    goto v_30082;
v_30074:
    v_30101 = elt(env, 9); // "sqfrf failure"
    goto v_30075;
v_30076:
    v_30100 = stack[-9];
    goto v_30077;
v_30078:
    v_30099 = stack[-10];
    goto v_30079;
v_30080:
    v_30098 = stack[-2];
    goto v_30081;
v_30082:
    goto v_30074;
v_30075:
    goto v_30076;
v_30077:
    goto v_30078;
v_30079:
    goto v_30080;
v_30081:
    v_30098 = list4(v_30101, v_30100, v_30099, v_30098);
    env = stack[-11];
    fn = elt(env, 24); // errach
    v_30098 = (*qfn1(fn))(fn, v_30098);
    env = stack[-11];
    goto v_29965;
v_29965:
    goto v_29954;
v_29956:
v_29954:
    goto v_30094;
v_30088:
    v_30100 = stack[-9];
    goto v_30089;
v_30090:
    v_30099 = stack[-10];
    goto v_30091;
v_30092:
    v_30098 = stack[-2];
    goto v_30093;
v_30094:
    goto v_30088;
v_30089:
    goto v_30090;
v_30091:
    goto v_30092;
v_30093:
    v_30098 = acons(v_30100, v_30099, v_30098);
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_30098);
}



// Code for ctx_get

static LispObject CC_ctx_get(LispObject env,
                         LispObject v_29658, LispObject v_29659)
{
    env = qenv(env);
    LispObject v_29698, v_29699, v_29700;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29659,v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29658,v_29659);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_29659;
    v_29698 = v_29658;
// end of prologue
    stack[-1] = nil;
    fn = elt(env, 1); // ctx_ial
    v_29698 = (*qfn1(fn))(fn, v_29698);
    v_29700 = v_29698;
v_29669:
    v_29698 = v_29700;
    if (v_29698 == nil) goto v_29672;
    v_29698 = stack[-1];
    if (v_29698 == nil) goto v_29676;
    else goto v_29672;
v_29676:
    goto v_29673;
v_29672:
    goto v_29668;
v_29673:
    goto v_29687;
v_29683:
    v_29698 = v_29700;
    v_29698 = qcar(v_29698);
    v_29699 = qcar(v_29698);
    goto v_29684;
v_29685:
    v_29698 = stack[0];
    goto v_29686;
v_29687:
    goto v_29683;
v_29684:
    goto v_29685;
v_29686:
    if (v_29699 == v_29698) goto v_29681;
    else goto v_29682;
v_29681:
    v_29698 = v_29700;
    v_29698 = qcar(v_29698);
    v_29698 = qcdr(v_29698);
    stack[-1] = v_29698;
    goto v_29680;
v_29682:
v_29680:
    v_29698 = v_29700;
    v_29698 = qcdr(v_29698);
    v_29700 = v_29698;
    goto v_29669;
v_29668:
    v_29698 = stack[-1];
    return onevalue(v_29698);
}



// Code for subs2pf

static LispObject CC_subs2pf(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29696, v_29697, v_29698;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29658);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_29658;
// end of prologue
v_29657:
    v_29696 = stack[0];
    if (v_29696 == nil) goto v_29663;
    v_29696 = stack[0];
    v_29696 = qcar(v_29696);
    v_29696 = qcdr(v_29696);
    fn = elt(env, 1); // resimp
    v_29696 = (*qfn1(fn))(fn, v_29696);
    env = stack[-1];
    fn = elt(env, 2); // subs2
    v_29696 = (*qfn1(fn))(fn, v_29696);
    env = stack[-1];
    v_29697 = v_29696;
    v_29697 = qcar(v_29697);
    if (v_29697 == nil) goto v_29674;
    goto v_29684;
v_29678:
    v_29697 = stack[0];
    v_29697 = qcar(v_29697);
    v_29698 = qcar(v_29697);
    goto v_29679;
v_29680:
    v_29697 = v_29696;
    goto v_29681;
v_29682:
    v_29696 = stack[0];
    v_29696 = qcdr(v_29696);
    goto v_29683;
v_29684:
    goto v_29678;
v_29679:
    goto v_29680;
v_29681:
    goto v_29682;
v_29683:
    return acons(v_29698, v_29697, v_29696);
v_29674:
    v_29696 = stack[0];
    v_29696 = qcdr(v_29696);
    stack[0] = v_29696;
    goto v_29657;
    v_29696 = nil;
    goto v_29661;
v_29663:
    v_29696 = nil;
v_29661:
    return onevalue(v_29696);
}



// Code for newvar

static LispObject CC_newvar(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29686, v_29687;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29658);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_29658;
// end of prologue
    v_29686 = stack[0];
    if (symbolp(v_29686)) goto v_29663;
    goto v_29670;
v_29666:
    v_29687 = stack[0];
    goto v_29667;
v_29668:
    v_29686 = elt(env, 1); // "free variable"
    goto v_29669;
v_29670:
    goto v_29666;
v_29667:
    goto v_29668;
v_29669:
    {
        fn = elt(env, 3); // typerr
        return (*qfn2(fn))(fn, v_29687, v_29686);
    }
v_29663:
    goto v_29681;
v_29677:
    v_29686 = elt(env, 2); // !=
    fn = elt(env, 4); // id2bytelist
    stack[-1] = (*qfn1(fn))(fn, v_29686);
    env = stack[-2];
    goto v_29678;
v_29679:
    v_29686 = stack[0];
    fn = elt(env, 4); // id2bytelist
    v_29686 = (*qfn1(fn))(fn, v_29686);
    env = stack[-2];
    goto v_29680;
v_29681:
    goto v_29677;
v_29678:
    goto v_29679;
v_29680:
    v_29686 = Lappend(nil, stack[-1], v_29686);
    env = stack[-2];
    {
        fn = elt(env, 5); // bytelist2id
        return (*qfn1(fn))(fn, v_29686);
    }
    v_29686 = nil;
    return onevalue(v_29686);
}



// Code for reddom_zeros

static LispObject CC_reddom_zeros(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29687, v_29688, v_29689;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29658);
    }
// copy arguments values to proper place
    v_29688 = v_29658;
// end of prologue
v_29662:
    v_29687 = v_29688;
    if (v_29687 == nil) goto v_29665;
    else goto v_29666;
v_29665:
    v_29687 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29661;
v_29666:
    goto v_29675;
v_29671:
    v_29687 = v_29688;
    v_29689 = qcar(v_29687);
    goto v_29672;
v_29673:
    v_29687 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29674;
v_29675:
    goto v_29671;
v_29672:
    goto v_29673;
v_29674:
    if (v_29689 == v_29687) goto v_29669;
    else goto v_29670;
v_29669:
    v_29687 = v_29688;
    v_29687 = qcdr(v_29687);
    v_29687 = CC_reddom_zeros(elt(env, 0), v_29687);
    return add1(v_29687);
v_29670:
    v_29687 = v_29688;
    v_29687 = qcdr(v_29687);
    v_29688 = v_29687;
    goto v_29662;
    v_29687 = nil;
v_29661:
    return onevalue(v_29687);
}



// Code for get!-all!-kernels

static LispObject CC_getKallKkernels(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29715, v_29716;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29658);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_29658;
// end of prologue
    stack[-3] = nil;
v_29664:
    v_29715 = stack[-2];
    if (!consp(v_29715)) goto v_29669;
    else goto v_29670;
v_29669:
    goto v_29665;
v_29670:
    goto v_29677;
v_29673:
    v_29715 = stack[-2];
    v_29715 = qcar(v_29715);
    fn = elt(env, 1); // simp
    v_29715 = (*qfn1(fn))(fn, v_29715);
    env = stack[-4];
    stack[-1] = v_29715;
    goto v_29687;
v_29683:
    v_29715 = stack[-1];
    v_29715 = qcar(v_29715);
    fn = elt(env, 2); // kernels
    stack[0] = (*qfn1(fn))(fn, v_29715);
    env = stack[-4];
    goto v_29684;
v_29685:
    v_29715 = stack[-1];
    v_29715 = qcdr(v_29715);
    fn = elt(env, 2); // kernels
    v_29715 = (*qfn1(fn))(fn, v_29715);
    env = stack[-4];
    goto v_29686;
v_29687:
    goto v_29683;
v_29684:
    goto v_29685;
v_29686:
    fn = elt(env, 3); // union
    v_29716 = (*qfn2(fn))(fn, stack[0], v_29715);
    env = stack[-4];
    goto v_29674;
v_29675:
    v_29715 = stack[-3];
    goto v_29676;
v_29677:
    goto v_29673;
v_29674:
    goto v_29675;
v_29676:
    v_29715 = cons(v_29716, v_29715);
    env = stack[-4];
    stack[-3] = v_29715;
    v_29715 = stack[-2];
    v_29715 = qcdr(v_29715);
    stack[-2] = v_29715;
    goto v_29664;
v_29665:
    v_29715 = nil;
    v_29716 = v_29715;
v_29666:
    v_29715 = stack[-3];
    if (v_29715 == nil) goto v_29700;
    else goto v_29701;
v_29700:
    v_29715 = v_29716;
    goto v_29663;
v_29701:
    goto v_29709;
v_29705:
    v_29715 = stack[-3];
    v_29715 = qcar(v_29715);
    goto v_29706;
v_29707:
    goto v_29708;
v_29709:
    goto v_29705;
v_29706:
    goto v_29707;
v_29708:
    fn = elt(env, 3); // union
    v_29715 = (*qfn2(fn))(fn, v_29715, v_29716);
    env = stack[-4];
    v_29716 = v_29715;
    v_29715 = stack[-3];
    v_29715 = qcdr(v_29715);
    stack[-3] = v_29715;
    goto v_29666;
v_29663:
    return onevalue(v_29715);
}



// Code for dp!=retimes

static LispObject CC_dpMretimes(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29702, v_29703, v_29704;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29703 = v_29658;
// end of prologue
v_29662:
    goto v_29671;
v_29667:
    v_29702 = v_29703;
    v_29704 = qcar(v_29702);
    goto v_29668;
v_29669:
    v_29702 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29670;
v_29671:
    goto v_29667;
v_29668:
    goto v_29669;
v_29670:
    if (v_29704 == v_29702) goto v_29665;
    else goto v_29666;
v_29665:
    v_29702 = v_29703;
    v_29702 = qcdr(v_29702);
    if (v_29702 == nil) goto v_29678;
    v_29702 = v_29703;
    v_29702 = qcdr(v_29702);
    v_29703 = v_29702;
    goto v_29662;
v_29678:
    v_29702 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29661;
    goto v_29664;
v_29666:
    v_29702 = v_29703;
    v_29702 = qcdr(v_29702);
    if (v_29702 == nil) goto v_29686;
    else goto v_29687;
v_29686:
    v_29702 = v_29703;
    v_29702 = qcar(v_29702);
    goto v_29661;
v_29687:
    goto v_29699;
v_29695:
    v_29702 = elt(env, 1); // times
    goto v_29696;
v_29697:
    goto v_29698;
v_29699:
    goto v_29695;
v_29696:
    goto v_29697;
v_29698:
    return cons(v_29702, v_29703);
v_29664:
    v_29702 = nil;
v_29661:
    return onevalue(v_29702);
}



// Code for pa_part2list

static LispObject CC_pa_part2list(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29792;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29658);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_29658;
// end of prologue
    v_29792 = stack[-6];
    v_29792 = qcdr(v_29792);
    fn = elt(env, 1); // upbve
    v_29792 = (*qfn1(fn))(fn, v_29792);
    env = stack[-8];
    stack[0] = v_29792;
    v_29792 = stack[0];
    v_29792 = sub1(v_29792);
    env = stack[-8];
    v_29792 = Lmkvect(nil, v_29792);
    env = stack[-8];
    stack[-7] = v_29792;
    v_29792 = stack[0];
    stack[-4] = v_29792;
v_29676:
    v_29792 = stack[-4];
    v_29792 = sub1(v_29792);
    env = stack[-8];
    v_29792 = Lminusp(nil, v_29792);
    env = stack[-8];
    if (v_29792 == nil) goto v_29681;
    goto v_29675;
v_29681:
    goto v_29690;
v_29686:
    v_29792 = stack[-6];
    stack[0] = qcdr(v_29792);
    goto v_29687;
v_29688:
    v_29792 = stack[-4];
    v_29792 = sub1(v_29792);
    env = stack[-8];
    goto v_29689;
v_29690:
    goto v_29686;
v_29687:
    goto v_29688;
v_29689:
    v_29792 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_29792-TAG_FIXNUM)/(16/CELL)));
    stack[-5] = v_29792;
    goto v_29702;
v_29696:
    stack[-3] = stack[-7];
    goto v_29697;
v_29698:
    v_29792 = stack[-5];
    stack[-2] = sub1(v_29792);
    env = stack[-8];
    goto v_29699;
v_29700:
    goto v_29711;
v_29707:
    stack[-1] = stack[-4];
    goto v_29708;
v_29709:
    goto v_29717;
v_29713:
    stack[0] = stack[-7];
    goto v_29714;
v_29715:
    v_29792 = stack[-5];
    v_29792 = sub1(v_29792);
    env = stack[-8];
    goto v_29716;
v_29717:
    goto v_29713;
v_29714:
    goto v_29715;
v_29716:
    v_29792 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_29792-TAG_FIXNUM)/(16/CELL)));
    goto v_29710;
v_29711:
    goto v_29707;
v_29708:
    goto v_29709;
v_29710:
    v_29792 = cons(stack[-1], v_29792);
    env = stack[-8];
    goto v_29701;
v_29702:
    goto v_29696;
v_29697:
    goto v_29698;
v_29699:
    goto v_29700;
v_29701:
    *(LispObject *)((char *)stack[-3] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-2]-TAG_FIXNUM)/(16/CELL))) = v_29792;
    v_29792 = stack[-4];
    v_29792 = sub1(v_29792);
    env = stack[-8];
    stack[-4] = v_29792;
    goto v_29676;
v_29675:
    v_29792 = stack[-6];
    v_29792 = qcar(v_29792);
    stack[-4] = v_29792;
v_29730:
    v_29792 = stack[-4];
    if (v_29792 == nil) goto v_29736;
    else goto v_29737;
v_29736:
    v_29792 = nil;
    goto v_29729;
v_29737:
    v_29792 = stack[-4];
    v_29792 = qcar(v_29792);
    goto v_29748;
v_29744:
    stack[0] = stack[-7];
    goto v_29745;
v_29746:
    v_29792 = sub1(v_29792);
    env = stack[-8];
    goto v_29747;
v_29748:
    goto v_29744;
v_29745:
    goto v_29746;
v_29747:
    v_29792 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_29792-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 2); // copy
    v_29792 = (*qfn1(fn))(fn, v_29792);
    env = stack[-8];
    stack[-3] = v_29792;
    v_29792 = stack[-3];
    fn = elt(env, 3); // lastpair
    v_29792 = (*qfn1(fn))(fn, v_29792);
    env = stack[-8];
    stack[-2] = v_29792;
    v_29792 = stack[-4];
    v_29792 = qcdr(v_29792);
    stack[-4] = v_29792;
    v_29792 = stack[-2];
    if (!consp(v_29792)) goto v_29759;
    else goto v_29760;
v_29759:
    goto v_29730;
v_29760:
v_29731:
    v_29792 = stack[-4];
    if (v_29792 == nil) goto v_29764;
    else goto v_29765;
v_29764:
    v_29792 = stack[-3];
    goto v_29729;
v_29765:
    goto v_29773;
v_29769:
    stack[-1] = stack[-2];
    goto v_29770;
v_29771:
    v_29792 = stack[-4];
    v_29792 = qcar(v_29792);
    goto v_29783;
v_29779:
    stack[0] = stack[-7];
    goto v_29780;
v_29781:
    v_29792 = sub1(v_29792);
    env = stack[-8];
    goto v_29782;
v_29783:
    goto v_29779;
v_29780:
    goto v_29781;
v_29782:
    v_29792 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_29792-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 2); // copy
    v_29792 = (*qfn1(fn))(fn, v_29792);
    env = stack[-8];
    goto v_29772;
v_29773:
    goto v_29769;
v_29770:
    goto v_29771;
v_29772:
    v_29792 = Lrplacd(nil, stack[-1], v_29792);
    env = stack[-8];
    v_29792 = stack[-2];
    fn = elt(env, 3); // lastpair
    v_29792 = (*qfn1(fn))(fn, v_29792);
    env = stack[-8];
    stack[-2] = v_29792;
    v_29792 = stack[-4];
    v_29792 = qcdr(v_29792);
    stack[-4] = v_29792;
    goto v_29731;
v_29729:
    return onevalue(v_29792);
}



// Code for derivative!-mod!-p

static LispObject CC_derivativeKmodKp(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29704, v_29705, v_29706;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29706 = v_29658;
// end of prologue
    v_29704 = v_29706;
    if (!consp(v_29704)) goto v_29666;
    else goto v_29667;
v_29666:
    v_29704 = lisp_true;
    goto v_29665;
v_29667:
    v_29704 = v_29706;
    v_29704 = qcar(v_29704);
    v_29704 = (consp(v_29704) ? nil : lisp_true);
    goto v_29665;
    v_29704 = nil;
v_29665:
    if (v_29704 == nil) goto v_29663;
    v_29704 = nil;
    goto v_29661;
v_29663:
    goto v_29682;
v_29678:
    v_29704 = v_29706;
    v_29704 = qcar(v_29704);
    v_29704 = qcar(v_29704);
    v_29705 = qcdr(v_29704);
    goto v_29679;
v_29680:
    v_29704 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29681;
v_29682:
    goto v_29678;
v_29679:
    goto v_29680;
v_29681:
    if (v_29705 == v_29704) goto v_29676;
    else goto v_29677;
v_29676:
    v_29704 = v_29706;
    v_29704 = qcar(v_29704);
    v_29704 = qcdr(v_29704);
    goto v_29661;
v_29677:
    goto v_29698;
v_29694:
    v_29704 = v_29706;
    goto v_29695;
v_29696:
    v_29705 = v_29706;
    v_29705 = qcar(v_29705);
    v_29705 = qcar(v_29705);
    v_29705 = qcar(v_29705);
    goto v_29697;
v_29698:
    goto v_29694;
v_29695:
    goto v_29696;
v_29697:
    {
        fn = elt(env, 1); // derivative!-mod!-p!-1
        return (*qfn2(fn))(fn, v_29704, v_29705);
    }
    v_29704 = nil;
v_29661:
    return onevalue(v_29704);
}



// Code for ofsf_sippatl

static LispObject CC_ofsf_sippatl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_29899, v_29900, v_29901, v_29902, v_29903, v_29904, v_29905;
    LispObject fn;
    LispObject v_29660, v_29659, v_29658;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_sippatl");
    va_start(aa, nargs);
    v_29658 = va_arg(aa, LispObject);
    v_29659 = va_arg(aa, LispObject);
    v_29660 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_29660,v_29659,v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_29658,v_29659,v_29660);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(16);
// copy arguments values to proper place
    stack[0] = v_29660;
    stack[-12] = v_29659;
    stack[-13] = v_29658;
// end of prologue
    stack[-1] = nil;
    goto v_29681;
v_29677:
    v_29901 = elt(env, 1); // true
    goto v_29678;
v_29679:
    goto v_29687;
v_29683:
    v_29900 = stack[-13];
    goto v_29684;
v_29685:
    v_29899 = elt(env, 2); // and
    goto v_29686;
v_29687:
    goto v_29683;
v_29684:
    goto v_29685;
v_29686:
    v_29899 = (v_29900 == v_29899 ? lisp_true : nil);
    goto v_29680;
v_29681:
    goto v_29677;
v_29678:
    goto v_29679;
v_29680:
    fn = elt(env, 8); // cl_cflip
    v_29899 = (*qfn2(fn))(fn, v_29901, v_29899);
    env = stack[-15];
    stack[-14] = v_29899;
    goto v_29696;
v_29692:
    v_29901 = elt(env, 3); // false
    goto v_29693;
v_29694:
    goto v_29702;
v_29698:
    v_29900 = stack[-13];
    goto v_29699;
v_29700:
    v_29899 = elt(env, 2); // and
    goto v_29701;
v_29702:
    goto v_29698;
v_29699:
    goto v_29700;
v_29701:
    v_29899 = (v_29900 == v_29899 ? lisp_true : nil);
    goto v_29695;
v_29696:
    goto v_29692;
v_29693:
    goto v_29694;
v_29695:
    fn = elt(env, 8); // cl_cflip
    v_29899 = (*qfn2(fn))(fn, v_29901, v_29899);
    env = stack[-15];
    stack[-11] = v_29899;
    goto v_29711;
v_29707:
    v_29901 = elt(env, 4); // equal
    goto v_29708;
v_29709:
    goto v_29717;
v_29713:
    v_29900 = stack[-13];
    goto v_29714;
v_29715:
    v_29899 = elt(env, 2); // and
    goto v_29716;
v_29717:
    goto v_29713;
v_29714:
    goto v_29715;
v_29716:
    v_29899 = (v_29900 == v_29899 ? lisp_true : nil);
    goto v_29710;
v_29711:
    goto v_29707;
v_29708:
    goto v_29709;
v_29710:
    fn = elt(env, 9); // ofsf_clnegrel
    v_29899 = (*qfn2(fn))(fn, v_29901, v_29899);
    env = stack[-15];
    stack[-10] = v_29899;
    v_29899 = stack[0];
    fn = elt(env, 10); // ofsf_exploitknowl
    v_29899 = (*qfn1(fn))(fn, v_29899);
    env = stack[-15];
    v_29900 = v_29899;
    v_29899 = v_29900;
    v_29899 = qcar(v_29899);
    stack[-9] = v_29899;
    v_29899 = v_29900;
    v_29899 = qcdr(v_29899);
    v_29900 = v_29899;
    v_29899 = v_29900;
    v_29899 = qcar(v_29899);
    stack[-8] = v_29899;
    v_29899 = v_29900;
    v_29899 = qcdr(v_29899);
    v_29900 = v_29899;
    v_29899 = v_29900;
    v_29899 = qcar(v_29899);
    stack[-7] = v_29899;
    v_29899 = v_29900;
    v_29899 = qcdr(v_29899);
    v_29900 = v_29899;
    v_29899 = v_29900;
    v_29899 = qcar(v_29899);
    stack[-6] = v_29899;
    v_29899 = v_29900;
    v_29899 = qcdr(v_29899);
    v_29900 = v_29899;
    v_29899 = v_29900;
    v_29899 = qcar(v_29899);
    stack[-5] = v_29899;
    v_29899 = v_29900;
    v_29899 = qcdr(v_29899);
    v_29900 = v_29899;
    v_29899 = v_29900;
    v_29899 = qcar(v_29899);
    stack[-4] = v_29899;
    v_29899 = v_29900;
    v_29899 = qcdr(v_29899);
    v_29900 = v_29899;
    v_29899 = v_29900;
    v_29899 = qcar(v_29899);
    stack[-3] = v_29899;
v_29759:
    v_29899 = stack[-12];
    if (v_29899 == nil) goto v_29762;
    else goto v_29763;
v_29762:
    goto v_29758;
v_29763:
    v_29899 = stack[-12];
    v_29899 = qcar(v_29899);
    v_29900 = v_29899;
    v_29899 = stack[-12];
    v_29899 = qcdr(v_29899);
    stack[-12] = v_29899;
    v_29899 = v_29900;
    stack[-2] = v_29899;
    v_29899 = qvalue(elt(env, 5)); // !*rlsippsubst
    if (v_29899 == nil) goto v_29778;
    goto v_29787;
v_29783:
    v_29900 = stack[-10];
    goto v_29784;
v_29785:
    v_29899 = stack[-2];
    goto v_29786;
v_29787:
    goto v_29783;
v_29784:
    goto v_29785;
v_29786:
    fn = elt(env, 11); // ofsf_vareqnp
    v_29899 = (*qfn2(fn))(fn, v_29900, v_29899);
    env = stack[-15];
    if (v_29899 == nil) goto v_29781;
    else goto v_29778;
v_29781:
    goto v_29795;
v_29791:
    v_29900 = stack[-2];
    goto v_29792;
v_29793:
    v_29899 = stack[-9];
    goto v_29794;
v_29795:
    goto v_29791;
v_29792:
    goto v_29793;
v_29794:
    fn = elt(env, 12); // ofsf_sippsubst
    v_29899 = (*qfn2(fn))(fn, v_29900, v_29899);
    env = stack[-15];
    stack[-2] = v_29899;
    v_29899 = nil;
// Binding !*rlsiatadv
// FLUIDBIND: reloadenv=15 litvec-offset=6 saveloc=0
{   bind_fluid_stack bind_fluid_var(-15, 6, 0);
    qvalue(elt(env, 6)) = v_29899; // !*rlsiatadv
    goto v_29805;
v_29801:
    v_29900 = stack[-2];
    goto v_29802;
v_29803:
    v_29899 = stack[-13];
    goto v_29804;
v_29805:
    goto v_29801;
v_29802:
    goto v_29803;
v_29804:
    fn = elt(env, 13); // ofsf_simplat1
    v_29899 = (*qfn2(fn))(fn, v_29900, v_29899);
    env = stack[-15];
    stack[-2] = v_29899;
    ;}  // end of a binding scope
    goto v_29776;
v_29778:
v_29776:
    goto v_29820;
v_29816:
    v_29900 = stack[-2];
    goto v_29817;
v_29818:
    v_29899 = elt(env, 1); // true
    goto v_29819;
v_29820:
    goto v_29816;
v_29817:
    goto v_29818;
v_29819:
    if (v_29900 == v_29899) goto v_29814;
    else goto v_29815;
v_29814:
    v_29899 = lisp_true;
    goto v_29813;
v_29815:
    goto v_29830;
v_29826:
    v_29900 = stack[-2];
    goto v_29827;
v_29828:
    v_29899 = elt(env, 3); // false
    goto v_29829;
v_29830:
    goto v_29826;
v_29827:
    goto v_29828;
v_29829:
    v_29899 = (v_29900 == v_29899 ? lisp_true : nil);
    goto v_29813;
    v_29899 = nil;
v_29813:
    if (v_29899 == nil) goto v_29810;
    else goto v_29811;
v_29810:
    v_29899 = qvalue(elt(env, 7)); // !*rlsippsignchk
    if (v_29899 == nil) goto v_29837;
    v_29899 = stack[-2];
    v_29899 = qcdr(v_29899);
    v_29899 = qcar(v_29899);
    fn = elt(env, 14); // sfto_varisnump
    v_29899 = (*qfn1(fn))(fn, v_29899);
    env = stack[-15];
    if (v_29899 == nil) goto v_29840;
    else goto v_29837;
v_29840:
    goto v_29860;
v_29846:
    v_29905 = stack[-2];
    goto v_29847;
v_29848:
    v_29904 = stack[-8];
    goto v_29849;
v_29850:
    v_29903 = stack[-7];
    goto v_29851;
v_29852:
    v_29902 = stack[-6];
    goto v_29853;
v_29854:
    v_29901 = stack[-5];
    goto v_29855;
v_29856:
    v_29900 = stack[-4];
    goto v_29857;
v_29858:
    v_29899 = stack[-3];
    goto v_29859;
v_29860:
    goto v_29846;
v_29847:
    goto v_29848;
v_29849:
    goto v_29850;
v_29851:
    goto v_29852;
v_29853:
    goto v_29854;
v_29855:
    goto v_29856;
v_29857:
    goto v_29858;
v_29859:
    fn = elt(env, 15); // ofsf_sippsignchk
    v_29899 = (*qfnn(fn))(fn, 7, v_29905, v_29904, v_29903, v_29902, v_29901, v_29900, v_29899);
    env = stack[-15];
    stack[-2] = v_29899;
    goto v_29835;
v_29837:
v_29835:
    goto v_29809;
v_29811:
v_29809:
    goto v_29876;
v_29872:
    v_29900 = stack[-2];
    goto v_29873;
v_29874:
    v_29899 = stack[-11];
    goto v_29875;
v_29876:
    goto v_29872;
v_29873:
    goto v_29874;
v_29875:
    if (v_29900 == v_29899) goto v_29870;
    else goto v_29871;
v_29870:
    v_29899 = stack[-11];
    stack[-1] = v_29899;
    v_29899 = nil;
    stack[-12] = v_29899;
    goto v_29869;
v_29871:
    goto v_29887;
v_29883:
    v_29900 = stack[-2];
    goto v_29884;
v_29885:
    v_29899 = stack[-14];
    goto v_29886;
v_29887:
    goto v_29883;
v_29884:
    goto v_29885;
v_29886:
    if (equal(v_29900, v_29899)) goto v_29882;
    goto v_29895;
v_29891:
    v_29900 = stack[-2];
    goto v_29892;
v_29893:
    v_29899 = stack[-1];
    goto v_29894;
v_29895:
    goto v_29891;
v_29892:
    goto v_29893;
v_29894:
    fn = elt(env, 16); // lto_insert
    v_29899 = (*qfn2(fn))(fn, v_29900, v_29899);
    env = stack[-15];
    stack[-1] = v_29899;
    goto v_29869;
v_29882:
v_29869:
    goto v_29759;
v_29758:
    v_29899 = stack[-1];
    return onevalue(v_29899);
}



// Code for get_dimension_in

static LispObject CC_get_dimension_in(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29672, v_29673;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29658);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_29672 = v_29658;
// end of prologue
    goto v_29669;
v_29665:
    v_29673 = elt(env, 1); // id
    goto v_29666;
v_29667:
    goto v_29668;
v_29669:
    goto v_29665;
v_29666:
    goto v_29667;
v_29668:
    fn = elt(env, 2); // get_rep_matrix_in
    v_29672 = (*qfn2(fn))(fn, v_29673, v_29672);
    env = stack[0];
    fn = elt(env, 3); // mk!+trace
    v_29672 = (*qfn1(fn))(fn, v_29672);
    env = stack[0];
    {
        fn = elt(env, 4); // change!+sq!+to!+int
        return (*qfn1(fn))(fn, v_29672);
    }
    return onevalue(v_29672);
}



// Code for pasf_leqp

static LispObject CC_pasf_leqp(LispObject env,
                         LispObject v_29658, LispObject v_29659)
{
    env = qenv(env);
    LispObject v_29744, v_29745, v_29746, v_29747;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29659,v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29658,v_29659);
    }
// copy arguments values to proper place
    v_29745 = v_29659;
    v_29746 = v_29658;
// end of prologue
    v_29744 = v_29746;
    if (v_29744 == nil) goto v_29665;
    else goto v_29666;
v_29665:
    v_29744 = (LispObject)0+TAG_FIXNUM; // 0
    v_29746 = v_29744;
    goto v_29664;
v_29666:
v_29664:
    v_29744 = v_29745;
    if (v_29744 == nil) goto v_29671;
    else goto v_29672;
v_29671:
    v_29744 = (LispObject)0+TAG_FIXNUM; // 0
    v_29745 = v_29744;
    goto v_29670;
v_29672:
v_29670:
    goto v_29687;
v_29683:
    v_29747 = v_29746;
    goto v_29684;
v_29685:
    v_29744 = elt(env, 1); // minf
    goto v_29686;
v_29687:
    goto v_29683;
v_29684:
    goto v_29685;
v_29686:
    if (v_29747 == v_29744) goto v_29681;
    else goto v_29682;
v_29681:
    v_29744 = lisp_true;
    goto v_29680;
v_29682:
    goto v_29701;
v_29697:
    v_29747 = v_29745;
    goto v_29698;
v_29699:
    v_29744 = elt(env, 2); // pinf
    goto v_29700;
v_29701:
    goto v_29697;
v_29698:
    goto v_29699;
v_29700:
    if (v_29747 == v_29744) goto v_29695;
    else goto v_29696;
v_29695:
    v_29744 = lisp_true;
    goto v_29694;
v_29696:
    goto v_29715;
v_29711:
    v_29747 = v_29746;
    goto v_29712;
v_29713:
    v_29744 = elt(env, 2); // pinf
    goto v_29714;
v_29715:
    goto v_29711;
v_29712:
    goto v_29713;
v_29714:
    if (v_29747 == v_29744) goto v_29710;
    goto v_29726;
v_29722:
    v_29747 = v_29745;
    goto v_29723;
v_29724:
    v_29744 = elt(env, 1); // minf
    goto v_29725;
v_29726:
    goto v_29722;
v_29723:
    goto v_29724;
v_29725:
    if (v_29747 == v_29744) goto v_29721;
    goto v_29734;
v_29730:
    v_29744 = v_29746;
    goto v_29731;
v_29732:
    goto v_29733;
v_29734:
    goto v_29730;
v_29731:
    goto v_29732;
v_29733:
    v_29744 = (LispObject)lesseq2(v_29744, v_29745);
    v_29744 = v_29744 ? lisp_true : nil;
    goto v_29719;
v_29721:
    v_29744 = nil;
    goto v_29719;
    v_29744 = nil;
v_29719:
    goto v_29708;
v_29710:
    v_29744 = nil;
    goto v_29708;
    v_29744 = nil;
v_29708:
    goto v_29694;
    v_29744 = nil;
v_29694:
    goto v_29680;
    v_29744 = nil;
v_29680:
    if (v_29744 == nil) goto v_29678;
    v_29744 = lisp_true;
    goto v_29676;
v_29678:
    v_29744 = nil;
v_29676:
    return onevalue(v_29744);
}



// Code for prload

static LispObject CC_prload(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_29660;
    argcheck(nargs, 0, "prload");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_29660 = nil;
    return onevalue(v_29660);
}



// Code for dm!-lt

static LispObject CC_dmKlt(LispObject env,
                         LispObject v_29658, LispObject v_29659)
{
    env = qenv(env);
    LispObject v_29670, v_29671;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29659,v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29658,v_29659);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_29670 = v_29659;
    v_29671 = v_29658;
// end of prologue
    goto v_29667;
v_29663:
    goto v_29664;
v_29665:
    goto v_29666;
v_29667:
    goto v_29663;
v_29664:
    goto v_29665;
v_29666:
    fn = elt(env, 1); // dm!-difference
    v_29670 = (*qfn2(fn))(fn, v_29671, v_29670);
    env = stack[0];
    {
        fn = elt(env, 2); // !:minusp
        return (*qfn1(fn))(fn, v_29670);
    }
}



// Code for vdpsimpcont

static LispObject CC_vdpsimpcont(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29722, v_29723, v_29724;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29658);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_29658;
// end of prologue
    v_29722 = stack[-1];
    v_29722 = qcdr(v_29722);
    v_29722 = qcdr(v_29722);
    v_29722 = qcdr(v_29722);
    v_29722 = qcar(v_29722);
    stack[0] = v_29722;
    v_29722 = stack[0];
    if (v_29722 == nil) goto v_29671;
    else goto v_29672;
v_29671:
    v_29722 = stack[-1];
    goto v_29663;
v_29672:
    v_29722 = stack[0];
    fn = elt(env, 2); // dipsimpcont
    v_29722 = (*qfn1(fn))(fn, v_29722);
    env = stack[-3];
    stack[-2] = v_29722;
    v_29722 = stack[-2];
    v_29722 = qcdr(v_29722);
    fn = elt(env, 3); // dip2vdp
    v_29722 = (*qfn1(fn))(fn, v_29722);
    env = stack[-3];
    stack[-1] = v_29722;
    v_29722 = stack[-2];
    v_29722 = qcar(v_29722);
    stack[-2] = v_29722;
    v_29722 = stack[-2];
    fn = elt(env, 4); // evzero!?
    v_29722 = (*qfn1(fn))(fn, v_29722);
    env = stack[-3];
    if (v_29722 == nil) goto v_29688;
    else goto v_29689;
v_29688:
    v_29722 = stack[0];
    v_29722 = qcdr(v_29722);
    v_29722 = qcdr(v_29722);
    if (v_29722 == nil) goto v_29694;
    else goto v_29693;
v_29694:
    goto v_29703;
v_29699:
    v_29722 = stack[-2];
    fn = elt(env, 5); // evtdeg
    v_29723 = (*qfn1(fn))(fn, v_29722);
    env = stack[-3];
    goto v_29700;
v_29701:
    v_29722 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29702;
v_29703:
    goto v_29699;
v_29700:
    goto v_29701;
v_29702:
    v_29722 = (LispObject)greaterp2(v_29723, v_29722);
    v_29722 = v_29722 ? lisp_true : nil;
    env = stack[-3];
v_29693:
    goto v_29687;
v_29689:
    v_29722 = nil;
    goto v_29687;
    v_29722 = nil;
v_29687:
    if (v_29722 == nil) goto v_29685;
    goto v_29717;
v_29711:
    v_29724 = stack[-1];
    goto v_29712;
v_29713:
    v_29723 = elt(env, 1); // monfac
    goto v_29714;
v_29715:
    v_29722 = stack[-2];
    goto v_29716;
v_29717:
    goto v_29711;
v_29712:
    goto v_29713;
v_29714:
    goto v_29715;
v_29716:
    fn = elt(env, 6); // vdpputprop
    v_29722 = (*qfnn(fn))(fn, 3, v_29724, v_29723, v_29722);
    goto v_29683;
v_29685:
v_29683:
    v_29722 = stack[-1];
v_29663:
    return onevalue(v_29722);
}



// Code for mk_world1

static LispObject CC_mk_world1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_29674, v_29675, v_29676;
    LispObject fn;
    LispObject v_29660, v_29659, v_29658;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mk_world1");
    va_start(aa, nargs);
    v_29658 = va_arg(aa, LispObject);
    v_29659 = va_arg(aa, LispObject);
    v_29660 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_29660,v_29659,v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_29658,v_29659,v_29660);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_29660;
    stack[-1] = v_29659;
    v_29674 = v_29658;
// end of prologue
    goto v_29669;
v_29663:
    fn = elt(env, 1); // map_2_from_map_1
    v_29676 = (*qfn1(fn))(fn, v_29674);
    goto v_29664;
v_29665:
    v_29675 = stack[-1];
    goto v_29666;
v_29667:
    v_29674 = stack[0];
    goto v_29668;
v_29669:
    goto v_29663;
v_29664:
    goto v_29665;
v_29666:
    goto v_29667;
v_29668:
    return list3(v_29676, v_29675, v_29674);
}



// Code for red_prepare

static LispObject CC_red_prepare(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29682;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29658);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_29658;
// end of prologue
    goto v_29667;
v_29661:
    v_29682 = stack[-1];
    fn = elt(env, 1); // bas_nr
    stack[-2] = (*qfn1(fn))(fn, v_29682);
    env = stack[-3];
    goto v_29662;
v_29663:
    v_29682 = stack[-1];
    fn = elt(env, 2); // bas_dpoly
    stack[0] = (*qfn1(fn))(fn, v_29682);
    env = stack[-3];
    goto v_29664;
v_29665:
    goto v_29677;
v_29673:
    v_29682 = stack[-1];
    fn = elt(env, 3); // bas_rep
    stack[-1] = (*qfn1(fn))(fn, v_29682);
    env = stack[-3];
    goto v_29674;
v_29675:
    v_29682 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 4); // dp_from_ei
    v_29682 = (*qfn1(fn))(fn, v_29682);
    env = stack[-3];
    goto v_29676;
v_29677:
    goto v_29673;
v_29674:
    goto v_29675;
v_29676:
    fn = elt(env, 5); // dp_sum
    v_29682 = (*qfn2(fn))(fn, stack[-1], v_29682);
    env = stack[-3];
    goto v_29666;
v_29667:
    goto v_29661;
v_29662:
    goto v_29663;
v_29664:
    goto v_29665;
v_29666:
    {
        LispObject v_29686 = stack[-2];
        LispObject v_29687 = stack[0];
        fn = elt(env, 6); // bas_make1
        return (*qfnn(fn))(fn, 3, v_29686, v_29687, v_29682);
    }
}



// Code for bagp

static LispObject CC_bagp(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29677, v_29678;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29678 = v_29658;
// end of prologue
    v_29677 = v_29678;
    if (!consp(v_29677)) goto v_29663;
    goto v_29670;
v_29666:
    v_29677 = v_29678;
    v_29677 = qcar(v_29677);
    goto v_29667;
v_29668:
    v_29678 = elt(env, 1); // bag
    goto v_29669;
v_29670:
    goto v_29666;
v_29667:
    goto v_29668;
v_29669:
        return Lflagp(nil, v_29677, v_29678);
v_29663:
    v_29677 = nil;
    goto v_29661;
    v_29677 = nil;
v_29661:
    return onevalue(v_29677);
}



// Code for sort_according_to

static LispObject CC_sort_according_to(LispObject env,
                         LispObject v_29658, LispObject v_29659)
{
    env = qenv(env);
    LispObject v_29703, v_29704, v_29705, v_29706;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29659,v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29658,v_29659);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_29703 = v_29659;
    stack[0] = v_29658;
// end of prologue
    v_29706 = nil;
    stack[-1] = v_29703;
v_29668:
    v_29703 = stack[-1];
    if (v_29703 == nil) goto v_29672;
    else goto v_29673;
v_29672:
    goto v_29667;
v_29673:
    v_29703 = stack[-1];
    v_29703 = qcar(v_29703);
    v_29705 = v_29703;
    goto v_29687;
v_29683:
    v_29704 = v_29705;
    goto v_29684;
v_29685:
    v_29703 = stack[0];
    goto v_29686;
v_29687:
    goto v_29683;
v_29684:
    goto v_29685;
v_29686:
    v_29703 = Lmember(nil, v_29704, v_29703);
    if (v_29703 == nil) goto v_29682;
    goto v_29696;
v_29692:
    v_29703 = v_29705;
    goto v_29693;
v_29694:
    v_29704 = v_29706;
    goto v_29695;
v_29696:
    goto v_29692;
v_29693:
    goto v_29694;
v_29695:
    v_29703 = cons(v_29703, v_29704);
    env = stack[-2];
    v_29706 = v_29703;
    goto v_29680;
v_29682:
v_29680:
    v_29703 = stack[-1];
    v_29703 = qcdr(v_29703);
    stack[-1] = v_29703;
    goto v_29668;
v_29667:
    v_29703 = v_29706;
        return Lreverse(nil, v_29703);
    return onevalue(v_29703);
}



// Code for gd_simpl

static LispObject CC_gd_simpl(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29679, v_29680, v_29681, v_29682;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29658);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_29682 = v_29658;
// end of prologue
    v_29681 = nil;
    v_29680 = lisp_true;
    v_29679 = nil;
// Binding !*guardian
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = v_29681; // !*guardian
// Binding !*rlnzden
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-3, 2, -1);
    qvalue(elt(env, 2)) = v_29680; // !*rlnzden
// Binding !*rladdcond
// FLUIDBIND: reloadenv=3 litvec-offset=3 saveloc=0
{   bind_fluid_stack bind_fluid_var(-3, 3, 0);
    qvalue(elt(env, 3)) = v_29679; // !*rladdcond
    goto v_29674;
v_29668:
    v_29679 = v_29682;
    fn = elt(env, 4); // rl_simp
    v_29681 = (*qfn1(fn))(fn, v_29679);
    env = stack[-3];
    goto v_29669;
v_29670:
    v_29680 = nil;
    goto v_29671;
v_29672:
    v_29679 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_29673;
v_29674:
    goto v_29668;
v_29669:
    goto v_29670;
v_29671:
    goto v_29672;
v_29673:
    fn = elt(env, 5); // rl_simpl
    v_29679 = (*qfnn(fn))(fn, 3, v_29681, v_29680, v_29679);
    env = stack[-3];
    fn = elt(env, 6); // rl_prepfof
    v_29679 = (*qfn1(fn))(fn, v_29679);
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_29679);
}



// Code for ofsf_smdbgetrel

static LispObject CC_ofsf_smdbgetrel(LispObject env,
                         LispObject v_29658, LispObject v_29659)
{
    env = qenv(env);
    LispObject v_29691, v_29692, v_29693, v_29694;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29692 = v_29659;
    v_29693 = v_29658;
// end of prologue
v_29663:
    goto v_29672;
v_29668:
    v_29694 = v_29693;
    goto v_29669;
v_29670:
    v_29691 = v_29692;
    v_29691 = qcar(v_29691);
    v_29691 = qcdr(v_29691);
    v_29691 = qcdr(v_29691);
    goto v_29671;
v_29672:
    goto v_29668;
v_29669:
    goto v_29670;
v_29671:
    if (equal(v_29694, v_29691)) goto v_29666;
    else goto v_29667;
v_29666:
    v_29691 = v_29692;
    v_29691 = qcar(v_29691);
    v_29691 = qcdr(v_29691);
    v_29691 = qcar(v_29691);
    goto v_29662;
v_29667:
    v_29691 = v_29692;
    v_29691 = qcdr(v_29691);
    if (v_29691 == nil) goto v_29683;
    v_29691 = v_29692;
    v_29691 = qcdr(v_29691);
    v_29692 = v_29691;
    goto v_29663;
v_29683:
    v_29691 = nil;
    goto v_29662;
    v_29691 = nil;
v_29662:
    return onevalue(v_29691);
}



// Code for !*ff2a

static LispObject CC_Hff2a(LispObject env,
                         LispObject v_29658, LispObject v_29659)
{
    env = qenv(env);
    LispObject v_29682, v_29683;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29659,v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29658,v_29659);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_29682 = v_29659;
    v_29683 = v_29658;
// end of prologue
    goto v_29667;
v_29663:
    goto v_29664;
v_29665:
    goto v_29666;
v_29667:
    goto v_29663;
v_29664:
    goto v_29665;
v_29666:
    v_29682 = cons(v_29683, v_29682);
    env = stack[0];
    fn = elt(env, 2); // cancel
    v_29682 = (*qfn1(fn))(fn, v_29682);
    env = stack[0];
    v_29683 = v_29682;
    v_29682 = qvalue(elt(env, 1)); // wtl!*
    if (v_29682 == nil) goto v_29674;
    v_29682 = v_29683;
    {
        fn = elt(env, 3); // prepsq
        return (*qfn1(fn))(fn, v_29682);
    }
v_29674:
    v_29682 = v_29683;
    {
        fn = elt(env, 4); // mk!*sq
        return (*qfn1(fn))(fn, v_29682);
    }
    v_29682 = nil;
    return onevalue(v_29682);
}



// Code for mktag

static LispObject CC_mktag(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_29746, v_29747, v_29748;
    LispObject fn;
    LispObject v_29660, v_29659, v_29658;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mktag");
    va_start(aa, nargs);
    v_29658 = va_arg(aa, LispObject);
    v_29659 = va_arg(aa, LispObject);
    v_29660 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_29660,v_29659,v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_29658,v_29659,v_29660);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_29660;
    stack[-2] = v_29659;
    v_29746 = v_29658;
// end of prologue
    v_29747 = v_29746;
    if (v_29747 == nil) goto v_29664;
    else goto v_29665;
v_29664:
    v_29746 = nil;
    goto v_29663;
v_29665:
    v_29747 = v_29746;
    if (!consp(v_29747)) goto v_29668;
    else goto v_29669;
v_29668:
    {
        fn = elt(env, 4); // texexplode
        return (*qfn1(fn))(fn, v_29746);
    }
v_29669:
    goto v_29687;
v_29683:
    v_29747 = v_29746;
    v_29748 = qcar(v_29747);
    goto v_29684;
v_29685:
    v_29747 = elt(env, 1); // texprec
    goto v_29686;
v_29687:
    goto v_29683;
v_29684:
    goto v_29685;
v_29686:
    v_29747 = get(v_29748, v_29747);
    env = stack[-4];
    if (v_29747 == nil) goto v_29681;
    else goto v_29680;
v_29681:
    v_29747 = (LispObject)15984+TAG_FIXNUM; // 999
v_29680:
    stack[-3] = v_29747;
    goto v_29699;
v_29693:
    v_29747 = v_29746;
    v_29748 = qcar(v_29747);
    goto v_29694;
v_29695:
    v_29747 = qcdr(v_29746);
    goto v_29696;
v_29697:
    v_29746 = stack[-3];
    goto v_29698;
v_29699:
    goto v_29693;
v_29694:
    goto v_29695;
v_29696:
    goto v_29697;
v_29698:
    fn = elt(env, 5); // makefunc
    v_29746 = (*qfnn(fn))(fn, 3, v_29748, v_29747, v_29746);
    env = stack[-4];
    stack[0] = v_29746;
    v_29746 = stack[-1];
    if (v_29746 == nil) goto v_29709;
    goto v_29717;
v_29713:
    v_29747 = stack[-2];
    goto v_29714;
v_29715:
    v_29746 = stack[-3];
    goto v_29716;
v_29717:
    goto v_29713;
v_29714:
    goto v_29715;
v_29716:
    if (equal(v_29747, v_29746)) goto v_29712;
    else goto v_29709;
v_29712:
    goto v_29707;
v_29709:
    goto v_29726;
v_29722:
    v_29747 = stack[-3];
    goto v_29723;
v_29724:
    v_29746 = stack[-2];
    goto v_29725;
v_29726:
    goto v_29722;
v_29723:
    goto v_29724;
v_29725:
    v_29746 = (LispObject)lessp2(v_29747, v_29746);
    v_29746 = v_29746 ? lisp_true : nil;
    env = stack[-4];
    if (v_29746 == nil) goto v_29720;
    else goto v_29707;
v_29720:
    goto v_29708;
v_29707:
    goto v_29734;
v_29730:
    goto v_29740;
v_29736:
    v_29747 = elt(env, 2); // !\!(
    goto v_29737;
v_29738:
    v_29746 = stack[0];
    goto v_29739;
v_29740:
    goto v_29736;
v_29737:
    goto v_29738;
v_29739:
    stack[0] = cons(v_29747, v_29746);
    env = stack[-4];
    goto v_29731;
v_29732:
    v_29746 = elt(env, 3); // !\!)
    v_29746 = ncons(v_29746);
    env = stack[-4];
    goto v_29733;
v_29734:
    goto v_29730;
v_29731:
    goto v_29732;
v_29733:
    v_29746 = Lnconc(nil, stack[0], v_29746);
    stack[0] = v_29746;
    goto v_29706;
v_29708:
v_29706:
    v_29746 = stack[0];
    goto v_29663;
    v_29746 = nil;
v_29663:
    return onevalue(v_29746);
}



// Code for qqe_length!-graph!-neighbors

static LispObject CC_qqe_lengthKgraphKneighbors(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29668, v_29669;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29668 = v_29658;
// end of prologue
    goto v_29665;
v_29661:
    goto v_29662;
v_29663:
    v_29669 = elt(env, 1); // neighbors
    goto v_29664;
v_29665:
    goto v_29661;
v_29662:
    goto v_29663;
v_29664:
    return get(v_29668, v_29669);
}



// Code for pasf_subfof

static LispObject CC_pasf_subfof(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_29680, v_29681, v_29682;
    LispObject fn;
    LispObject v_29660, v_29659, v_29658;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pasf_subfof");
    va_start(aa, nargs);
    v_29658 = va_arg(aa, LispObject);
    v_29659 = va_arg(aa, LispObject);
    v_29660 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_29660,v_29659,v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_29658,v_29659,v_29660);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_29680 = v_29660;
    v_29681 = v_29659;
    v_29682 = v_29658;
// end of prologue
    goto v_29669;
v_29663:
    stack[-1] = v_29680;
    goto v_29664;
v_29665:
    stack[0] = elt(env, 1); // pasf_subfof1
    goto v_29666;
v_29667:
    goto v_29677;
v_29673:
    v_29680 = v_29682;
    goto v_29674;
v_29675:
    goto v_29676;
v_29677:
    goto v_29673;
v_29674:
    goto v_29675;
v_29676:
    v_29680 = list2(v_29680, v_29681);
    env = stack[-2];
    goto v_29668;
v_29669:
    goto v_29663;
v_29664:
    goto v_29665;
v_29666:
    goto v_29667;
v_29668:
    {
        LispObject v_29685 = stack[-1];
        LispObject v_29686 = stack[0];
        fn = elt(env, 2); // cl_apply2ats1
        return (*qfnn(fn))(fn, 3, v_29685, v_29686, v_29680);
    }
}



// Code for vdp_sugar

static LispObject CC_vdp_sugar(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29684, v_29685;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29658);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_29658;
// end of prologue
    v_29684 = stack[0];
    fn = elt(env, 3); // vdp_zero!?
    v_29684 = (*qfn1(fn))(fn, v_29684);
    env = stack[-1];
    if (v_29684 == nil) goto v_29664;
    else goto v_29662;
v_29664:
    v_29684 = qvalue(elt(env, 1)); // !*cgbsugar
    if (v_29684 == nil) goto v_29662;
    goto v_29663;
v_29662:
    v_29684 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29661;
v_29663:
    goto v_29680;
v_29676:
    v_29685 = stack[0];
    goto v_29677;
v_29678:
    v_29684 = elt(env, 2); // sugar
    goto v_29679;
v_29680:
    goto v_29676;
v_29677:
    goto v_29678;
v_29679:
    fn = elt(env, 4); // vdp_getprop
    v_29684 = (*qfn2(fn))(fn, v_29685, v_29684);
    if (v_29684 == nil) goto v_29674;
    else goto v_29673;
v_29674:
    v_29684 = (LispObject)0+TAG_FIXNUM; // 0
v_29673:
    goto v_29661;
    v_29684 = nil;
v_29661:
    return onevalue(v_29684);
}



// Code for intconv

static LispObject CC_intconv(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29692, v_29693, v_29694;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29694 = v_29658;
// end of prologue
    v_29692 = qvalue(elt(env, 1)); // dmode!*
    if (v_29692 == nil) goto v_29666;
    else goto v_29667;
v_29666:
    v_29692 = lisp_true;
    goto v_29665;
v_29667:
    goto v_29676;
v_29672:
    v_29693 = qvalue(elt(env, 1)); // dmode!*
    goto v_29673;
v_29674:
    v_29692 = elt(env, 2); // (!:rd!: !:cr!:)
    goto v_29675;
v_29676:
    goto v_29672;
v_29673:
    goto v_29674;
v_29675:
    v_29692 = Lmemq(nil, v_29693, v_29692);
    goto v_29665;
    v_29692 = nil;
v_29665:
    if (v_29692 == nil) goto v_29663;
    v_29692 = v_29694;
    goto v_29661;
v_29663:
    goto v_29688;
v_29684:
    v_29692 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_29692)) v_29692 = nil;
    else { v_29692 = qfastgets(v_29692);
           if (v_29692 != nil) { v_29692 = elt(v_29692, 34); // i2d
#ifdef RECORD_GET
             if (v_29692 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_29692 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_29692 == SPID_NOPROP) v_29692 = nil; }}
#endif
    goto v_29685;
v_29686:
    v_29693 = v_29694;
    goto v_29687;
v_29688:
    goto v_29684;
v_29685:
    goto v_29686;
v_29687:
        return Lapply1(nil, v_29692, v_29693);
    v_29692 = nil;
v_29661:
    return onevalue(v_29692);
}



// Code for qsimpcomb_standard_integer_part_sf

static LispObject CC_qsimpcomb_standard_integer_part_sf(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29741, v_29742, v_29743;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29658);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_29658;
// end of prologue
    v_29741 = nil;
    stack[-3] = v_29741;
v_29668:
    v_29741 = stack[-2];
    v_29741 = Lconsp(nil, v_29741);
    env = stack[-4];
    if (v_29741 == nil) goto v_29671;
    else goto v_29672;
v_29671:
    goto v_29667;
v_29672:
    v_29741 = stack[-2];
    v_29741 = qcar(v_29741);
    v_29741 = qcdr(v_29741);
    v_29741 = CC_qsimpcomb_standard_integer_part_sf(elt(env, 0), v_29741);
    env = stack[-4];
    stack[-1] = v_29741;
    goto v_29685;
v_29681:
    v_29741 = stack[-2];
    v_29741 = qcar(v_29741);
    v_29741 = qcar(v_29741);
    v_29742 = qcar(v_29741);
    goto v_29682;
v_29683:
    v_29741 = stack[-2];
    v_29741 = qcar(v_29741);
    v_29741 = qcar(v_29741);
    v_29741 = qcdr(v_29741);
    goto v_29684;
v_29685:
    goto v_29681;
v_29682:
    goto v_29683;
v_29684:
    v_29741 = cons(v_29742, v_29741);
    env = stack[-4];
    stack[0] = v_29741;
v_29696:
    goto v_29704;
v_29698:
    goto v_29710;
v_29706:
    v_29742 = stack[0];
    goto v_29707;
v_29708:
    v_29741 = stack[-1];
    v_29741 = qcar(v_29741);
    goto v_29709;
v_29710:
    goto v_29706;
v_29707:
    goto v_29708;
v_29709:
    v_29743 = cons(v_29742, v_29741);
    env = stack[-4];
    goto v_29699;
v_29700:
    v_29742 = nil;
    goto v_29701;
v_29702:
    v_29741 = stack[-3];
    goto v_29703;
v_29704:
    goto v_29698;
v_29699:
    goto v_29700;
v_29701:
    goto v_29702;
v_29703:
    v_29741 = acons(v_29743, v_29742, v_29741);
    env = stack[-4];
    stack[-3] = v_29741;
    v_29741 = stack[-1];
    v_29741 = qcdr(v_29741);
    stack[-1] = v_29741;
    v_29741 = stack[-1];
    if (v_29741 == nil) goto v_29722;
    goto v_29696;
v_29722:
    v_29741 = stack[-2];
    v_29741 = qcdr(v_29741);
    stack[-2] = v_29741;
    goto v_29668;
v_29667:
    v_29741 = stack[-2];
    if (v_29741 == nil) goto v_29730;
    goto v_29737;
v_29733:
    v_29742 = stack[-2];
    goto v_29734;
v_29735:
    v_29741 = stack[-3];
    goto v_29736;
v_29737:
    goto v_29733;
v_29734:
    goto v_29735;
v_29736:
    v_29741 = cons(v_29742, v_29741);
    stack[-3] = v_29741;
    goto v_29728;
v_29730:
v_29728:
    v_29741 = stack[-3];
    return onevalue(v_29741);
}



// Code for force!-to!-dm

static LispObject CC_forceKtoKdm(LispObject env,
                         LispObject v_29658)
{
    env = qenv(env);
    LispObject v_29765, v_29766, v_29767;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29658);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_29766 = v_29658;
// end of prologue
v_29662:
    v_29765 = v_29766;
    if (!consp(v_29765)) goto v_29669;
    else goto v_29670;
v_29669:
    v_29765 = lisp_true;
    goto v_29668;
v_29670:
    v_29765 = v_29766;
    v_29765 = qcar(v_29765);
    v_29765 = (consp(v_29765) ? nil : lisp_true);
    goto v_29668;
    v_29765 = nil;
v_29668:
    if (v_29765 == nil) goto v_29665;
    else goto v_29666;
v_29665:
    goto v_29683;
v_29679:
    v_29765 = v_29766;
    fn = elt(env, 4); // prepf
    v_29766 = (*qfn1(fn))(fn, v_29765);
    env = stack[-1];
    goto v_29680;
v_29681:
    v_29765 = elt(env, 1); // "number"
    goto v_29682;
v_29683:
    goto v_29679;
v_29680:
    goto v_29681;
v_29682:
    {
        fn = elt(env, 5); // typerr
        return (*qfn2(fn))(fn, v_29766, v_29765);
    }
v_29666:
    v_29765 = v_29766;
    if (v_29765 == nil) goto v_29687;
    else goto v_29688;
v_29687:
    v_29765 = (LispObject)0+TAG_FIXNUM; // 0
    v_29766 = v_29765;
    goto v_29662;
v_29688:
    v_29765 = v_29766;
    if (is_number(v_29765)) goto v_29691;
    else goto v_29692;
v_29691:
    goto v_29699;
v_29695:
    v_29765 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v_29765)) stack[0] = nil;
    else { stack[0] = qfastgets(v_29765);
           if (stack[0] != nil) { stack[0] = elt(stack[0], 34); // i2d
#ifdef RECORD_GET
             if (stack[0] != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                stack[0] = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (stack[0] == SPID_NOPROP) stack[0] = nil; }}
#endif
    goto v_29696;
v_29697:
    v_29765 = v_29766;
    v_29765 = ncons(v_29765);
    env = stack[-1];
    goto v_29698;
v_29699:
    goto v_29695;
v_29696:
    goto v_29697;
v_29698:
    {
        LispObject v_29769 = stack[0];
        fn = elt(env, 6); // apply
        return (*qfn2(fn))(fn, v_29769, v_29765);
    }
v_29692:
    v_29765 = v_29766;
    v_29765 = Lconsp(nil, v_29765);
    env = stack[-1];
    if (v_29765 == nil) goto v_29705;
    goto v_29714;
v_29710:
    v_29765 = v_29766;
    v_29767 = qcar(v_29765);
    goto v_29711;
v_29712:
    v_29765 = qvalue(elt(env, 2)); // dmode!*
    goto v_29713;
v_29714:
    goto v_29710;
v_29711:
    goto v_29712;
v_29713:
    if (equal(v_29767, v_29765)) goto v_29709;
    else goto v_29705;
v_29709:
    v_29765 = v_29766;
    goto v_29661;
v_29705:
    v_29765 = v_29766;
    v_29765 = Lconsp(nil, v_29765);
    env = stack[-1];
    if (v_29765 == nil) goto v_29723;
    else goto v_29724;
v_29723:
    v_29765 = nil;
    goto v_29722;
v_29724:
    goto v_29735;
v_29731:
    v_29765 = v_29766;
    v_29767 = qcar(v_29765);
    goto v_29732;
v_29733:
    v_29765 = qvalue(elt(env, 2)); // dmode!*
    goto v_29734;
v_29735:
    goto v_29731;
v_29732:
    goto v_29733;
v_29734:
    v_29765 = get(v_29767, v_29765);
    env = stack[-1];
    goto v_29722;
    v_29765 = nil;
v_29722:
    v_29767 = v_29765;
    v_29765 = v_29767;
    if (v_29765 == nil) goto v_29743;
    goto v_29750;
v_29746:
    stack[0] = v_29767;
    goto v_29747;
v_29748:
    v_29765 = v_29766;
    v_29765 = ncons(v_29765);
    env = stack[-1];
    goto v_29749;
v_29750:
    goto v_29746;
v_29747:
    goto v_29748;
v_29749:
    {
        LispObject v_29770 = stack[0];
        fn = elt(env, 6); // apply
        return (*qfn2(fn))(fn, v_29770, v_29765);
    }
v_29743:
    goto v_29762;
v_29758:
    v_29765 = elt(env, 3); // "conversion error with "
    goto v_29759;
v_29760:
    goto v_29761;
v_29762:
    goto v_29758;
v_29759:
    goto v_29760;
v_29761:
    v_29765 = list2(v_29765, v_29766);
    env = stack[-1];
    {
        fn = elt(env, 7); // rederr
        return (*qfn1(fn))(fn, v_29765);
    }
    v_29765 = nil;
    goto v_29661;
    v_29765 = nil;
v_29661:
    return onevalue(v_29765);
}



// Code for cali_bc_power

static LispObject CC_cali_bc_power(LispObject env,
                         LispObject v_29658, LispObject v_29659)
{
    env = qenv(env);
    LispObject v_29670, v_29671;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29659,v_29658);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29658,v_29659);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_29670 = v_29659;
    v_29671 = v_29658;
// end of prologue
    goto v_29667;
v_29663:
    goto v_29664;
v_29665:
    goto v_29666;
v_29667:
    goto v_29663;
v_29664:
    goto v_29665;
v_29666:
    fn = elt(env, 1); // exptf
    v_29670 = (*qfn2(fn))(fn, v_29671, v_29670);
    env = stack[0];
    {
        fn = elt(env, 2); // bc!=simp
        return (*qfn1(fn))(fn, v_29670);
    }
}



// Code for remainder!-mod!-p

static LispObject CC_remainderKmodKp(LispObject env,
                         LispObject v_29658, LispObject v_29659)
{
    env = qenv(env);
    LispObject v_29712, v_29713, v_29714;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29712 = v_29659;
    v_29714 = v_29658;
// end of prologue
    v_29713 = v_29712;
    if (v_29713 == nil) goto v_29663;
    else goto v_29664;
v_29663:
    v_29712 = elt(env, 1); // "b=0 in remainder-mod-p"
    {
        fn = elt(env, 2); // errorf
        return (*qfn1(fn))(fn, v_29712);
    }
v_29664:
    v_29713 = v_29712;
    if (!consp(v_29713)) goto v_29672;
    else goto v_29673;
v_29672:
    v_29713 = lisp_true;
    goto v_29671;
v_29673:
    v_29713 = v_29712;
    v_29713 = qcar(v_29713);
    v_29713 = (consp(v_29713) ? nil : lisp_true);
    goto v_29671;
    v_29713 = nil;
v_29671:
    if (v_29713 == nil) goto v_29669;
    v_29712 = nil;
    goto v_29662;
v_29669:
    v_29713 = v_29714;
    if (!consp(v_29713)) goto v_29686;
    else goto v_29687;
v_29686:
    v_29713 = lisp_true;
    goto v_29685;
v_29687:
    v_29713 = v_29714;
    v_29713 = qcar(v_29713);
    v_29713 = (consp(v_29713) ? nil : lisp_true);
    goto v_29685;
    v_29713 = nil;
v_29685:
    if (v_29713 == nil) goto v_29683;
    v_29712 = v_29714;
    goto v_29662;
v_29683:
    goto v_29705;
v_29699:
    goto v_29700;
v_29701:
    v_29713 = v_29712;
    goto v_29702;
v_29703:
    v_29712 = qcar(v_29712);
    v_29712 = qcar(v_29712);
    v_29712 = qcar(v_29712);
    goto v_29704;
v_29705:
    goto v_29699;
v_29700:
    goto v_29701;
v_29702:
    goto v_29703;
v_29704:
    {
        fn = elt(env, 3); // xremainder!-mod!-p
        return (*qfnn(fn))(fn, 3, v_29714, v_29713, v_29712);
    }
    v_29712 = nil;
v_29662:
    return onevalue(v_29712);
}



setup_type const u50_setup[] =
{
    {"st_sorttree1",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_st_sorttree1},
    {"evaluate-in-vector",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_evaluateKinKvector},
    {"bfrsq",                   CC_bfrsq,       TOO_MANY_1,    WRONG_NO_1},
    {"nextu",                   TOO_FEW_2,      CC_nextu,      WRONG_NO_2},
    {"talp_get-idx",            TOO_FEW_2,      CC_talp_getKidx,WRONG_NO_2},
    {"qqe_length-graph-neighbor-edge",CC_qqe_lengthKgraphKneighborKedge,TOO_MANY_1,WRONG_NO_1},
    {"pasf_dnf",                CC_pasf_dnf,    TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_pop",                CC_ofsf_pop,    TOO_MANY_1,    WRONG_NO_1},
    {"ezgcd-comfac",            CC_ezgcdKcomfac,TOO_MANY_1,    WRONG_NO_1},
    {"dipcontenti",             CC_dipcontenti, TOO_MANY_1,    WRONG_NO_1},
    {"ratmean",                 TOO_FEW_2,      CC_ratmean,    WRONG_NO_2},
    {"lispcodeexp",             TOO_FEW_2,      CC_lispcodeexp,WRONG_NO_2},
    {"defined_vertex",          TOO_FEW_2,      CC_defined_vertex,WRONG_NO_2},
    {"mo=expvec2a1",            TOO_FEW_2,      CC_moMexpvec2a1,WRONG_NO_2},
    {"impartsq",                CC_impartsq,    TOO_MANY_1,    WRONG_NO_1},
    {"talp_qesolset",           TOO_FEW_2,      CC_talp_qesolset,WRONG_NO_2},
    {"mri_irsplit1",            CC_mri_irsplit1,TOO_MANY_1,    WRONG_NO_1},
    {"sqfrf",                   CC_sqfrf,       TOO_MANY_1,    WRONG_NO_1},
    {"ctx_get",                 TOO_FEW_2,      CC_ctx_get,    WRONG_NO_2},
    {"subs2pf",                 CC_subs2pf,     TOO_MANY_1,    WRONG_NO_1},
    {"newvar",                  CC_newvar,      TOO_MANY_1,    WRONG_NO_1},
    {"reddom_zeros",            CC_reddom_zeros,TOO_MANY_1,    WRONG_NO_1},
    {"get-all-kernels",         CC_getKallKkernels,TOO_MANY_1, WRONG_NO_1},
    {"dp=retimes",              CC_dpMretimes,  TOO_MANY_1,    WRONG_NO_1},
    {"pa_part2list",            CC_pa_part2list,TOO_MANY_1,    WRONG_NO_1},
    {"derivative-mod-p",        CC_derivativeKmodKp,TOO_MANY_1,WRONG_NO_1},
    {"ofsf_sippatl",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_sippatl},
    {"get_dimension_in",        CC_get_dimension_in,TOO_MANY_1,WRONG_NO_1},
    {"pasf_leqp",               TOO_FEW_2,      CC_pasf_leqp,  WRONG_NO_2},
    {"prload",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_prload},
    {"dm-lt",                   TOO_FEW_2,      CC_dmKlt,      WRONG_NO_2},
    {"vdpsimpcont",             CC_vdpsimpcont, TOO_MANY_1,    WRONG_NO_1},
    {"mk_world1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mk_world1},
    {"red_prepare",             CC_red_prepare, TOO_MANY_1,    WRONG_NO_1},
    {"bagp",                    CC_bagp,        TOO_MANY_1,    WRONG_NO_1},
    {"sort_according_to",       TOO_FEW_2,      CC_sort_according_to,WRONG_NO_2},
    {"gd_simpl",                CC_gd_simpl,    TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_smdbgetrel",         TOO_FEW_2,      CC_ofsf_smdbgetrel,WRONG_NO_2},
    {"*ff2a",                   TOO_FEW_2,      CC_Hff2a,      WRONG_NO_2},
    {"mktag",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mktag},
    {"qqe_length-graph-neighbors",CC_qqe_lengthKgraphKneighbors,TOO_MANY_1,WRONG_NO_1},
    {"pasf_subfof",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pasf_subfof},
    {"vdp_sugar",               CC_vdp_sugar,   TOO_MANY_1,    WRONG_NO_1},
    {"intconv",                 CC_intconv,     TOO_MANY_1,    WRONG_NO_1},
    {"qsimpcomb_standard_integer_part_sf",CC_qsimpcomb_standard_integer_part_sf,TOO_MANY_1,WRONG_NO_1},
    {"force-to-dm",             CC_forceKtoKdm, TOO_MANY_1,    WRONG_NO_1},
    {"cali_bc_power",           TOO_FEW_2,      CC_cali_bc_power,WRONG_NO_2},
    {"remainder-mod-p",         TOO_FEW_2,      CC_remainderKmodKp,WRONG_NO_2},
    {NULL, (one_args *)"u50", (two_args *)"94346 1948065 6574081", 0}
};

// end of generated code
