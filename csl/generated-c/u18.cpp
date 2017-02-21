
// $destdir/u18.c        Machine generated C code

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



// Code for exptcompare

static LispObject CC_exptcompare(LispObject env,
                         LispObject v_10238, LispObject v_10239)
{
    env = qenv(env);
    LispObject v_10278, v_10279, v_10280;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10278 = v_10239;
    v_10279 = v_10238;
// end of prologue
    v_10280 = v_10279;
    if (!consp(v_10280)) goto v_10243;
    else goto v_10244;
v_10243:
    v_10280 = v_10278;
    if (!consp(v_10280)) goto v_10248;
    else goto v_10249;
v_10248:
    goto v_10256;
v_10252:
    goto v_10253;
v_10254:
    goto v_10255;
v_10256:
    goto v_10252;
v_10253:
    goto v_10254;
v_10255:
        return Lgreaterp(nil, v_10279, v_10278);
v_10249:
    v_10278 = nil;
    goto v_10247;
    v_10278 = nil;
v_10247:
    goto v_10242;
v_10244:
    v_10280 = v_10278;
    if (!consp(v_10280)) goto v_10262;
    else goto v_10263;
v_10262:
    v_10278 = lisp_true;
    goto v_10242;
v_10263:
    goto v_10273;
v_10269:
    v_10279 = qcar(v_10279);
    goto v_10270;
v_10271:
    v_10278 = qcar(v_10278);
    goto v_10272;
v_10273:
    goto v_10269;
v_10270:
    goto v_10271;
v_10272:
        return Lgreaterp(nil, v_10279, v_10278);
    v_10278 = nil;
v_10242:
    return onevalue(v_10278);
}



// Code for cl_smsimpl!-junct2

static LispObject CC_cl_smsimplKjunct2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10354, v_10355, v_10356, v_10357;
    LispObject fn;
    LispObject v_10243, v_10242, v_10241, v_10240, v_10239, v_10238;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "cl_smsimpl-junct2");
    va_start(aa, nargs);
    v_10238 = va_arg(aa, LispObject);
    v_10239 = va_arg(aa, LispObject);
    v_10240 = va_arg(aa, LispObject);
    v_10241 = va_arg(aa, LispObject);
    v_10242 = va_arg(aa, LispObject);
    v_10243 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_10243,v_10242,v_10241,v_10240,v_10239,v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_10238,v_10239,v_10240,v_10241,v_10242,v_10243);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_10243;
    v_10354 = v_10242;
    v_10355 = v_10241;
    v_10356 = v_10240;
    stack[-2] = v_10239;
    v_10357 = v_10238;
// end of prologue
    goto v_10258;
v_10250:
    goto v_10251;
v_10252:
    goto v_10253;
v_10254:
    goto v_10255;
v_10256:
    goto v_10257;
v_10258:
    goto v_10250;
v_10251:
    goto v_10252;
v_10253:
    goto v_10254;
v_10255:
    goto v_10256;
v_10257:
    fn = elt(env, 6); // rl_smmkatl
    v_10354 = (*qfnn(fn))(fn, 4, v_10357, v_10356, v_10355, v_10354);
    env = stack[-4];
    stack[-3] = v_10354;
    goto v_10271;
v_10267:
    v_10355 = stack[-3];
    goto v_10268;
v_10269:
    v_10354 = stack[-1];
    goto v_10270;
v_10271:
    goto v_10267;
v_10268:
    goto v_10269;
v_10270:
    if (v_10355 == v_10354) goto v_10265;
    else goto v_10266;
v_10265:
    v_10354 = stack[-1];
    return ncons(v_10354);
v_10266:
    v_10354 = qvalue(elt(env, 1)); // !*rlsichk
    if (v_10354 == nil) goto v_10279;
    v_10354 = stack[-2];
    v_10355 = v_10354;
    v_10354 = nil;
    stack[-2] = v_10354;
    v_10354 = v_10355;
    stack[0] = v_10354;
v_10286:
    v_10354 = stack[0];
    if (v_10354 == nil) goto v_10290;
    else goto v_10291;
v_10290:
    goto v_10285;
v_10291:
    v_10354 = stack[0];
    v_10354 = qcar(v_10354);
    goto v_10302;
v_10298:
    v_10355 = v_10354;
    goto v_10299;
v_10300:
    v_10354 = stack[-2];
    goto v_10301;
v_10302:
    goto v_10298;
v_10299:
    goto v_10300;
v_10301:
    fn = elt(env, 7); // lto_insert
    v_10354 = (*qfn2(fn))(fn, v_10355, v_10354);
    env = stack[-4];
    stack[-2] = v_10354;
    v_10354 = stack[0];
    v_10354 = qcdr(v_10354);
    stack[0] = v_10354;
    goto v_10286;
v_10285:
    goto v_10277;
v_10279:
    v_10354 = stack[-2];
    v_10354 = Lnreverse(nil, v_10354);
    env = stack[-4];
    stack[-2] = v_10354;
    goto v_10277;
v_10277:
    v_10354 = qvalue(elt(env, 2)); // !*rlsiso
    if (v_10354 == nil) goto v_10314;
    goto v_10321;
v_10317:
    v_10355 = stack[-3];
    goto v_10318;
v_10319:
    v_10354 = elt(env, 3); // rl_ordatp
    goto v_10320;
v_10321:
    goto v_10317;
v_10318:
    goto v_10319;
v_10320:
    fn = elt(env, 8); // sort
    v_10354 = (*qfn2(fn))(fn, v_10355, v_10354);
    env = stack[-4];
    stack[-3] = v_10354;
    v_10354 = qvalue(elt(env, 4)); // !*rlsisocx
    if (v_10354 == nil) goto v_10327;
    goto v_10334;
v_10330:
    v_10355 = stack[-2];
    goto v_10331;
v_10332:
    v_10354 = elt(env, 5); // cl_sordp
    goto v_10333;
v_10334:
    goto v_10330;
v_10331:
    goto v_10332;
v_10333:
    fn = elt(env, 8); // sort
    v_10354 = (*qfn2(fn))(fn, v_10355, v_10354);
    env = stack[-4];
    stack[-2] = v_10354;
    goto v_10325;
v_10327:
v_10325:
    goto v_10312;
v_10314:
v_10312:
    goto v_10342;
v_10338:
    v_10355 = stack[-3];
    goto v_10339;
v_10340:
    v_10354 = stack[-2];
    goto v_10341;
v_10342:
    goto v_10338;
v_10339:
    goto v_10340;
v_10341:
    v_10354 = Lnconc(nil, v_10355, v_10354);
    env = stack[-4];
    v_10355 = v_10354;
    v_10354 = v_10355;
    if (v_10354 == nil) goto v_10348;
    v_10354 = v_10355;
    goto v_10248;
v_10348:
    v_10354 = stack[-1];
    fn = elt(env, 9); // cl_flip
    v_10354 = (*qfn1(fn))(fn, v_10354);
    return ncons(v_10354);
v_10248:
    return onevalue(v_10354);
}



// Code for variableom

static LispObject CC_variableom(LispObject env,
                         LispObject v_10238)
{
    env = qenv(env);
    LispObject v_10293, v_10294;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10238);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10238;
// end of prologue
    goto v_10247;
v_10243:
    v_10293 = stack[0];
    v_10294 = Lintern(nil, v_10293);
    env = stack[-2];
    goto v_10244;
v_10245:
    v_10293 = qvalue(elt(env, 1)); // constantsom!*
    goto v_10246;
v_10247:
    goto v_10243;
v_10244:
    goto v_10245;
v_10246:
    v_10293 = Lassoc(nil, v_10294, v_10293);
    stack[-1] = v_10293;
    v_10293 = stack[-1];
    if (v_10293 == nil) goto v_10255;
    v_10293 = elt(env, 2); // "<OMS "
    fn = elt(env, 8); // printout
    v_10293 = (*qfn1(fn))(fn, v_10293);
    env = stack[-2];
    v_10293 = elt(env, 3); // "cd="""
    v_10293 = Lprinc(nil, v_10293);
    env = stack[-2];
    v_10293 = stack[-1];
    v_10293 = qcdr(v_10293);
    v_10293 = qcar(v_10293);
    v_10293 = Lprinc(nil, v_10293);
    env = stack[-2];
    v_10293 = elt(env, 4); // """ "
    v_10293 = Lprinc(nil, v_10293);
    env = stack[-2];
    v_10293 = elt(env, 5); // "name="""
    v_10293 = Lprinc(nil, v_10293);
    env = stack[-2];
    v_10293 = stack[-1];
    v_10293 = qcdr(v_10293);
    v_10293 = qcdr(v_10293);
    v_10293 = qcar(v_10293);
    v_10293 = Lprinc(nil, v_10293);
    env = stack[-2];
    v_10293 = elt(env, 6); // """/>"
    v_10293 = Lprinc(nil, v_10293);
    goto v_10253;
v_10255:
    v_10293 = stack[0];
    if (v_10293 == nil) goto v_10282;
    v_10293 = elt(env, 7); // "<OMV "
    fn = elt(env, 8); // printout
    v_10293 = (*qfn1(fn))(fn, v_10293);
    env = stack[-2];
    v_10293 = elt(env, 5); // "name="""
    v_10293 = Lprinc(nil, v_10293);
    env = stack[-2];
    v_10293 = stack[0];
    v_10293 = Lprinc(nil, v_10293);
    env = stack[-2];
    v_10293 = elt(env, 6); // """/>"
    v_10293 = Lprinc(nil, v_10293);
    goto v_10280;
v_10282:
v_10280:
    goto v_10253;
v_10253:
    v_10293 = nil;
    return onevalue(v_10293);
}



// Code for onoff

static LispObject CC_onoff(LispObject env,
                         LispObject v_10238, LispObject v_10239)
{
    env = qenv(env);
    LispObject v_10365, v_10366, v_10367;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10239,v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10238,v_10239);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_10239;
    stack[0] = v_10238;
// end of prologue
    v_10365 = stack[0];
    if (symbolp(v_10365)) goto v_10248;
    goto v_10255;
v_10251:
    v_10366 = stack[0];
    goto v_10252;
v_10253:
    v_10365 = elt(env, 1); // "switch"
    goto v_10254;
v_10255:
    goto v_10251;
v_10252:
    goto v_10253;
v_10254:
    fn = elt(env, 9); // typerr
    v_10365 = (*qfn2(fn))(fn, v_10366, v_10365);
    env = stack[-4];
    goto v_10246;
v_10248:
    v_10365 = stack[0];
    if (!symbolp(v_10365)) v_10365 = nil;
    else { v_10365 = qfastgets(v_10365);
           if (v_10365 != nil) { v_10365 = elt(v_10365, 51); // switch
#ifdef RECORD_GET
             if (v_10365 == SPID_NOPROP)
                record_get(elt(fastget_names, 51), 0),
                v_10365 = nil;
             else record_get(elt(fastget_names, 51), 1),
                v_10365 = lisp_true; }
           else record_get(elt(fastget_names, 51), 0); }
#else
             if (v_10365 == SPID_NOPROP) v_10365 = nil; else v_10365 = lisp_true; }}
#endif
    if (v_10365 == nil) goto v_10258;
    else goto v_10259;
v_10258:
    goto v_10269;
v_10263:
    stack[-3] = elt(env, 2); // rlisp
    goto v_10264;
v_10265:
    stack[-1] = (LispObject)400+TAG_FIXNUM; // 25
    goto v_10266;
v_10267:
    goto v_10277;
v_10273:
    v_10366 = stack[0];
    goto v_10274;
v_10275:
    v_10365 = elt(env, 3); // "not defined as switch"
    goto v_10276;
v_10277:
    goto v_10273;
v_10274:
    goto v_10275;
v_10276:
    v_10365 = list2(v_10366, v_10365);
    env = stack[-4];
    goto v_10268;
v_10269:
    goto v_10263;
v_10264:
    goto v_10265;
v_10266:
    goto v_10267;
v_10268:
    fn = elt(env, 10); // rerror
    v_10365 = (*qfnn(fn))(fn, 3, stack[-3], stack[-1], v_10365);
    env = stack[-4];
    goto v_10246;
v_10259:
v_10246:
    goto v_10287;
v_10283:
    stack[-1] = elt(env, 4); // !*
    goto v_10284;
v_10285:
    v_10365 = stack[0];
    v_10365 = Lexplodec(nil, v_10365);
    env = stack[-4];
    goto v_10286;
v_10287:
    goto v_10283;
v_10284:
    goto v_10285;
v_10286:
    v_10365 = cons(stack[-1], v_10365);
    env = stack[-4];
    fn = elt(env, 11); // list2string
    v_10365 = (*qfn1(fn))(fn, v_10365);
    env = stack[-4];
    v_10365 = Lintern(nil, v_10365);
    env = stack[-4];
    stack[-3] = v_10365;
    v_10365 = qvalue(elt(env, 5)); // !*switchcheck
    if (v_10365 == nil) goto v_10294;
    goto v_10302;
v_10298:
    v_10365 = stack[-3];
    fn = elt(env, 12); // lispeval
    v_10366 = (*qfn1(fn))(fn, v_10365);
    env = stack[-4];
    goto v_10299;
v_10300:
    v_10365 = stack[-2];
    goto v_10301;
v_10302:
    goto v_10298;
v_10299:
    goto v_10300;
v_10301:
    if (v_10366 == v_10365) goto v_10297;
    else goto v_10294;
v_10297:
    v_10365 = nil;
    goto v_10244;
v_10294:
    goto v_10313;
v_10309:
    v_10367 = stack[-2];
    goto v_10310;
v_10311:
    goto v_10320;
v_10316:
    v_10366 = stack[0];
    goto v_10317;
v_10318:
    v_10365 = elt(env, 6); // simpfg
    goto v_10319;
v_10320:
    goto v_10316;
v_10317:
    goto v_10318;
v_10319:
    v_10365 = get(v_10366, v_10365);
    env = stack[-4];
    goto v_10312;
v_10313:
    goto v_10309;
v_10310:
    goto v_10311;
v_10312:
    v_10365 = Latsoc(nil, v_10367, v_10365);
    v_10366 = v_10365;
    if (v_10365 == nil) goto v_10308;
    goto v_10330;
v_10326:
    stack[-1] = elt(env, 7); // progn
    goto v_10327;
v_10328:
    goto v_10337;
v_10333:
    v_10365 = v_10366;
    stack[0] = qcdr(v_10365);
    goto v_10334;
v_10335:
    v_10365 = nil;
    v_10365 = ncons(v_10365);
    env = stack[-4];
    goto v_10336;
v_10337:
    goto v_10333;
v_10334:
    goto v_10335;
v_10336:
    v_10365 = Lappend(nil, stack[0], v_10365);
    env = stack[-4];
    goto v_10329;
v_10330:
    goto v_10326;
v_10327:
    goto v_10328;
v_10329:
    v_10365 = cons(stack[-1], v_10365);
    env = stack[-4];
    fn = elt(env, 12); // lispeval
    v_10365 = (*qfn1(fn))(fn, v_10365);
    env = stack[-4];
    goto v_10292;
v_10308:
v_10292:
    v_10365 = stack[-2];
    if (v_10365 == nil) goto v_10345;
    goto v_10353;
v_10349:
    v_10366 = stack[-3];
    goto v_10350;
v_10351:
    v_10365 = elt(env, 8); // !*raise
    goto v_10352;
v_10353:
    goto v_10349;
v_10350:
    goto v_10351;
v_10352:
    if (v_10366 == v_10365) goto v_10348;
    else goto v_10345;
v_10348:
    v_10365 = elt(env, 8); // !*raise
    stack[-3] = v_10365;
    goto v_10343;
v_10345:
v_10343:
    goto v_10362;
v_10358:
    v_10366 = stack[-3];
    goto v_10359;
v_10360:
    v_10365 = stack[-2];
    goto v_10361;
v_10362:
    goto v_10358;
v_10359:
    goto v_10360;
v_10361:
    v_10365 = Lset(nil, v_10366, v_10365);
    v_10365 = nil;
v_10244:
    return onevalue(v_10365);
}



// Code for unchecked_getmatelem

static LispObject CC_unchecked_getmatelem(LispObject env,
                         LispObject v_10238)
{
    env = qenv(env);
    LispObject v_10301, v_10302, v_10303;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10238);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_10238;
// end of prologue
    goto v_10252;
v_10248:
    v_10301 = stack[-1];
    v_10302 = qcar(v_10301);
    v_10303 = v_10302;
    goto v_10249;
v_10250:
    v_10301 = elt(env, 1); // mat
    goto v_10251;
v_10252:
    goto v_10248;
v_10249:
    goto v_10250;
v_10251:
    if (!consp(v_10302)) goto v_10245;
    v_10302 = qcar(v_10302);
    if (v_10302 == v_10301) goto v_10246;
v_10245:
    goto v_10263;
v_10257:
    stack[-2] = elt(env, 2); // matrix
    goto v_10258;
v_10259:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10260;
v_10261:
    goto v_10273;
v_10267:
    v_10303 = elt(env, 3); // "Matrix"
    goto v_10268;
v_10269:
    v_10301 = stack[-1];
    v_10302 = qcar(v_10301);
    goto v_10270;
v_10271:
    v_10301 = elt(env, 4); // "not set"
    goto v_10272;
v_10273:
    goto v_10267;
v_10268:
    goto v_10269;
v_10270:
    goto v_10271;
v_10272:
    v_10301 = list3(v_10303, v_10302, v_10301);
    env = stack[-3];
    goto v_10262;
v_10263:
    goto v_10257;
v_10258:
    goto v_10259;
v_10260:
    goto v_10261;
v_10262:
    fn = elt(env, 5); // rerror
    v_10301 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_10301);
    goto v_10244;
v_10246:
    goto v_10285;
v_10281:
    goto v_10291;
v_10287:
    v_10301 = v_10303;
    v_10302 = qcdr(v_10301);
    goto v_10288;
v_10289:
    v_10301 = stack[-1];
    v_10301 = qcdr(v_10301);
    v_10301 = qcar(v_10301);
    goto v_10290;
v_10291:
    goto v_10287;
v_10288:
    goto v_10289;
v_10290:
    fn = elt(env, 6); // nth
    v_10302 = (*qfn2(fn))(fn, v_10302, v_10301);
    env = stack[-3];
    goto v_10282;
v_10283:
    v_10301 = stack[-1];
    v_10301 = qcdr(v_10301);
    v_10301 = qcdr(v_10301);
    v_10301 = qcar(v_10301);
    goto v_10284;
v_10285:
    goto v_10281;
v_10282:
    goto v_10283;
v_10284:
    {
        fn = elt(env, 6); // nth
        return (*qfn2(fn))(fn, v_10302, v_10301);
    }
v_10244:
    v_10301 = nil;
    return onevalue(v_10301);
}



// Code for guesspftype

static LispObject CC_guesspftype(LispObject env,
                         LispObject v_10238)
{
    env = qenv(env);
    LispObject v_10282, v_10283;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10238);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10238;
// end of prologue
    v_10282 = stack[0];
    if (!consp(v_10282)) goto v_10242;
    else goto v_10243;
v_10242:
    v_10282 = stack[0];
    goto v_10241;
v_10243:
    goto v_10252;
v_10248:
    v_10282 = stack[0];
    v_10283 = qcar(v_10282);
    goto v_10249;
v_10250:
    v_10282 = elt(env, 1); // (wedge d partdf hodge innerprod liedf)
    goto v_10251;
v_10252:
    goto v_10248;
v_10249:
    goto v_10250;
v_10251:
    v_10282 = Lmemq(nil, v_10283, v_10282);
    if (v_10282 == nil) goto v_10247;
    v_10282 = stack[0];
    goto v_10241;
v_10247:
    goto v_10265;
v_10261:
    v_10282 = stack[0];
    v_10282 = qcdr(v_10282);
    v_10283 = Llength(nil, v_10282);
    env = stack[-1];
    goto v_10262;
v_10263:
    v_10282 = stack[0];
    v_10282 = qcar(v_10282);
    if (!symbolp(v_10282)) v_10282 = nil;
    else { v_10282 = qfastgets(v_10282);
           if (v_10282 != nil) { v_10282 = elt(v_10282, 25); // ifdegree
#ifdef RECORD_GET
             if (v_10282 != SPID_NOPROP)
                record_get(elt(fastget_names, 25), 1);
             else record_get(elt(fastget_names, 25), 0),
                v_10282 = nil; }
           else record_get(elt(fastget_names, 25), 0); }
#else
             if (v_10282 == SPID_NOPROP) v_10282 = nil; }}
#endif
    goto v_10264;
v_10265:
    goto v_10261;
v_10262:
    goto v_10263;
v_10264:
    v_10282 = Lassoc(nil, v_10283, v_10282);
    if (v_10282 == nil) goto v_10259;
    v_10282 = stack[0];
    v_10282 = qcdr(v_10282);
    fn = elt(env, 2); // xvarlistp
    v_10282 = (*qfn1(fn))(fn, v_10282);
    env = stack[-1];
    if (v_10282 == nil) goto v_10273;
    else goto v_10259;
v_10273:
    v_10282 = stack[0];
    goto v_10241;
v_10259:
    v_10282 = stack[0];
    {
        fn = elt(env, 3); // mknwedge
        return (*qfn1(fn))(fn, v_10282);
    }
    v_10282 = nil;
v_10241:
    return onevalue(v_10282);
}



// Code for deleteall

static LispObject CC_deleteall(LispObject env,
                         LispObject v_10238, LispObject v_10239)
{
    env = qenv(env);
    LispObject v_10276, v_10277, v_10278, v_10279;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10239,v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10238,v_10239);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10239;
    stack[-1] = v_10238;
// end of prologue
    v_10278 = nil;
v_10245:
    v_10276 = stack[0];
    if (v_10276 == nil) goto v_10248;
    else goto v_10249;
v_10248:
    v_10276 = v_10278;
    goto v_10244;
v_10249:
    v_10276 = stack[0];
    v_10276 = qcar(v_10276);
    v_10279 = v_10276;
    v_10276 = stack[0];
    v_10276 = qcdr(v_10276);
    stack[0] = v_10276;
    goto v_10264;
v_10260:
    v_10277 = v_10279;
    goto v_10261;
v_10262:
    v_10276 = stack[-1];
    goto v_10263;
v_10264:
    goto v_10260;
v_10261:
    goto v_10262;
v_10263:
    if (equal(v_10277, v_10276)) goto v_10259;
    goto v_10272;
v_10268:
    stack[-2] = v_10278;
    goto v_10269;
v_10270:
    v_10276 = v_10279;
    v_10276 = ncons(v_10276);
    env = stack[-3];
    goto v_10271;
v_10272:
    goto v_10268;
v_10269:
    goto v_10270;
v_10271:
    v_10276 = Lnconc(nil, stack[-2], v_10276);
    env = stack[-3];
    v_10278 = v_10276;
    goto v_10257;
v_10259:
v_10257:
    goto v_10245;
v_10244:
    return onevalue(v_10276);
}



// Code for cstimes

static LispObject CC_cstimes(LispObject env,
                         LispObject v_10238, LispObject v_10239)
{
    env = qenv(env);
    LispObject v_10298, v_10299, v_10300, v_10301;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10239,v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10238,v_10239);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10299 = v_10239;
    v_10300 = v_10238;
// end of prologue
v_10244:
    v_10298 = v_10300;
    if (v_10298 == nil) goto v_10247;
    else goto v_10248;
v_10247:
    v_10298 = v_10299;
    if (v_10298 == nil) goto v_10252;
    else goto v_10253;
v_10252:
    v_10298 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10243;
v_10253:
    v_10298 = v_10299;
    v_10298 = qcdr(v_10298);
    if (v_10298 == nil) goto v_10256;
    else goto v_10257;
v_10256:
    v_10298 = v_10299;
    v_10298 = qcar(v_10298);
    goto v_10243;
v_10257:
    goto v_10269;
v_10265:
    v_10298 = elt(env, 1); // times
    goto v_10266;
v_10267:
    goto v_10268;
v_10269:
    goto v_10265;
v_10266:
    goto v_10267;
v_10268:
    return cons(v_10298, v_10299);
    goto v_10246;
v_10248:
    goto v_10278;
v_10274:
    v_10298 = v_10300;
    v_10301 = qcar(v_10298);
    goto v_10275;
v_10276:
    v_10298 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10277;
v_10278:
    goto v_10274;
v_10275:
    goto v_10276;
v_10277:
    if (v_10301 == v_10298) goto v_10272;
    else goto v_10273;
v_10272:
    v_10298 = v_10300;
    v_10298 = qcdr(v_10298);
    v_10300 = v_10298;
    goto v_10244;
v_10273:
    v_10298 = v_10300;
    v_10298 = qcdr(v_10298);
    stack[0] = v_10298;
    goto v_10293;
v_10289:
    v_10298 = v_10300;
    v_10298 = qcar(v_10298);
    goto v_10290;
v_10291:
    goto v_10292;
v_10293:
    goto v_10289;
v_10290:
    goto v_10291;
v_10292:
    v_10298 = cons(v_10298, v_10299);
    env = stack[-1];
    v_10299 = v_10298;
    v_10298 = stack[0];
    v_10300 = v_10298;
    goto v_10244;
v_10246:
    v_10298 = nil;
v_10243:
    return onevalue(v_10298);
}



// Code for copyd

static LispObject CC_copyd(LispObject env,
                         LispObject v_10238, LispObject v_10239)
{
    env = qenv(env);
    LispObject v_10334, v_10335, v_10336;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10239,v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10238,v_10239);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_10239;
    stack[-2] = v_10238;
// end of prologue
    v_10334 = stack[-1];
    fn = elt(env, 5); // getd
    v_10334 = (*qfn1(fn))(fn, v_10334);
    env = stack[-4];
    v_10335 = v_10334;
    if (v_10335 == nil) goto v_10248;
    else goto v_10249;
v_10248:
    goto v_10259;
v_10255:
    v_10335 = qvalue(elt(env, 1)); // !*savedef
    goto v_10256;
v_10257:
    v_10334 = elt(env, 1); // !*savedef
    goto v_10258;
v_10259:
    goto v_10255;
v_10256:
    goto v_10257;
v_10258:
    if (v_10335 == v_10334) goto v_10254;
    goto v_10269;
v_10263:
    stack[-3] = elt(env, 2); // rlisp
    goto v_10264;
v_10265:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10266;
v_10267:
    goto v_10277;
v_10273:
    v_10335 = stack[-1];
    goto v_10274;
v_10275:
    v_10334 = elt(env, 3); // "has no definition in copyd"
    goto v_10276;
v_10277:
    goto v_10273;
v_10274:
    goto v_10275;
v_10276:
    v_10334 = list2(v_10335, v_10334);
    env = stack[-4];
    goto v_10268;
v_10269:
    goto v_10263;
v_10264:
    goto v_10265;
v_10266:
    goto v_10267;
v_10268:
    fn = elt(env, 6); // rerror
    v_10334 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_10334);
    env = stack[-4];
    goto v_10252;
v_10254:
v_10252:
    goto v_10247;
v_10249:
    goto v_10289;
v_10283:
    v_10336 = stack[-2];
    goto v_10284;
v_10285:
    v_10335 = v_10334;
    v_10335 = qcar(v_10335);
    goto v_10286;
v_10287:
    v_10334 = qcdr(v_10334);
    goto v_10288;
v_10289:
    goto v_10283;
v_10284:
    goto v_10285;
v_10286:
    goto v_10287;
v_10288:
    fn = elt(env, 7); // putd
    v_10334 = (*qfnn(fn))(fn, 3, v_10336, v_10335, v_10334);
    env = stack[-4];
    v_10334 = stack[-1];
    if (!symbolp(v_10334)) v_10334 = nil;
    else { v_10334 = qfastgets(v_10334);
           if (v_10334 != nil) { v_10334 = elt(v_10334, 1); // lose
#ifdef RECORD_GET
             if (v_10334 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v_10334 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v_10334 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v_10334 == SPID_NOPROP) v_10334 = nil; else v_10334 = lisp_true; }}
#endif
    if (v_10334 == nil) goto v_10298;
    goto v_10306;
v_10302:
    v_10334 = stack[-2];
    v_10335 = ncons(v_10334);
    env = stack[-4];
    goto v_10303;
v_10304:
    v_10334 = elt(env, 4); // lose
    goto v_10305;
v_10306:
    goto v_10302;
v_10303:
    goto v_10304;
v_10305:
    v_10334 = Lflag(nil, v_10335, v_10334);
    env = stack[-4];
    goto v_10296;
v_10298:
v_10296:
    goto v_10247;
v_10247:
    goto v_10319;
v_10315:
    v_10335 = stack[-1];
    goto v_10316;
v_10317:
    v_10334 = elt(env, 1); // !*savedef
    goto v_10318;
v_10319:
    goto v_10315;
v_10316:
    goto v_10317;
v_10318:
    v_10335 = get(v_10335, v_10334);
    env = stack[-4];
    v_10334 = v_10335;
    if (v_10335 == nil) goto v_10313;
    goto v_10329;
v_10323:
    v_10336 = stack[-2];
    goto v_10324;
v_10325:
    v_10335 = elt(env, 1); // !*savedef
    goto v_10326;
v_10327:
    goto v_10328;
v_10329:
    goto v_10323;
v_10324:
    goto v_10325;
v_10326:
    goto v_10327;
v_10328:
    v_10334 = Lputprop(nil, 3, v_10336, v_10335, v_10334);
    goto v_10311;
v_10313:
v_10311:
    v_10334 = stack[-2];
    return onevalue(v_10334);
}



// Code for sf_member

static LispObject CC_sf_member(LispObject env,
                         LispObject v_10238, LispObject v_10239)
{
    env = qenv(env);
    LispObject v_10295, v_10296;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10239,v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10238,v_10239);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10239;
    stack[-1] = v_10238;
// end of prologue
v_10237:
    v_10295 = stack[0];
    if (!consp(v_10295)) goto v_10247;
    else goto v_10248;
v_10247:
    v_10295 = lisp_true;
    goto v_10246;
v_10248:
    v_10295 = stack[0];
    v_10295 = qcar(v_10295);
    v_10295 = (consp(v_10295) ? nil : lisp_true);
    goto v_10246;
    v_10295 = nil;
v_10246:
    if (v_10295 == nil) goto v_10243;
    else goto v_10244;
v_10243:
    goto v_10264;
v_10260:
    v_10296 = stack[-1];
    goto v_10261;
v_10262:
    v_10295 = stack[0];
    v_10295 = qcar(v_10295);
    v_10295 = qcar(v_10295);
    v_10295 = qcar(v_10295);
    goto v_10263;
v_10264:
    goto v_10260;
v_10261:
    goto v_10262;
v_10263:
    fn = elt(env, 1); // mvar_member
    v_10295 = (*qfn2(fn))(fn, v_10296, v_10295);
    env = stack[-2];
    if (v_10295 == nil) goto v_10258;
    else goto v_10257;
v_10258:
    goto v_10278;
v_10274:
    v_10296 = stack[-1];
    goto v_10275;
v_10276:
    v_10295 = stack[0];
    v_10295 = qcar(v_10295);
    v_10295 = qcdr(v_10295);
    goto v_10277;
v_10278:
    goto v_10274;
v_10275:
    goto v_10276;
v_10277:
    v_10295 = CC_sf_member(elt(env, 0), v_10296, v_10295);
    env = stack[-2];
    if (v_10295 == nil) goto v_10272;
    else goto v_10271;
v_10272:
    goto v_10288;
v_10284:
    v_10296 = stack[-1];
    goto v_10285;
v_10286:
    v_10295 = stack[0];
    v_10295 = qcdr(v_10295);
    goto v_10287;
v_10288:
    goto v_10284;
v_10285:
    goto v_10286;
v_10287:
    stack[-1] = v_10296;
    stack[0] = v_10295;
    goto v_10237;
v_10271:
v_10257:
    goto v_10242;
v_10244:
    v_10295 = nil;
    goto v_10242;
    v_10295 = nil;
v_10242:
    return onevalue(v_10295);
}



// Code for b!:extadd

static LispObject CC_bTextadd(LispObject env,
                         LispObject v_10238, LispObject v_10239)
{
    env = qenv(env);
    LispObject v_10365, v_10366, v_10367;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10239,v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10238,v_10239);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10239;
    stack[-1] = v_10238;
// end of prologue
    stack[-2] = nil;
v_10246:
    v_10365 = stack[-1];
    if (v_10365 == nil) goto v_10250;
    else goto v_10251;
v_10250:
    v_10365 = stack[0];
    v_10366 = v_10365;
    goto v_10247;
v_10251:
    v_10365 = stack[0];
    if (v_10365 == nil) goto v_10254;
    else goto v_10255;
v_10254:
    v_10365 = stack[-1];
    v_10366 = v_10365;
    goto v_10247;
v_10255:
    goto v_10264;
v_10260:
    v_10365 = stack[-1];
    v_10365 = qcar(v_10365);
    v_10366 = qcar(v_10365);
    goto v_10261;
v_10262:
    v_10365 = stack[0];
    v_10365 = qcar(v_10365);
    v_10365 = qcar(v_10365);
    goto v_10263;
v_10264:
    goto v_10260;
v_10261:
    goto v_10262;
v_10263:
    if (equal(v_10366, v_10365)) goto v_10258;
    else goto v_10259;
v_10258:
    goto v_10276;
v_10272:
    v_10365 = stack[-1];
    v_10365 = qcar(v_10365);
    v_10366 = qcdr(v_10365);
    goto v_10273;
v_10274:
    v_10365 = stack[0];
    v_10365 = qcar(v_10365);
    v_10365 = qcdr(v_10365);
    goto v_10275;
v_10276:
    goto v_10272;
v_10273:
    goto v_10274;
v_10275:
    fn = elt(env, 1); // addf
    v_10365 = (*qfn2(fn))(fn, v_10366, v_10365);
    env = stack[-3];
    v_10366 = v_10365;
    if (v_10366 == nil) goto v_10286;
    goto v_10295;
v_10289:
    v_10366 = stack[-1];
    v_10366 = qcar(v_10366);
    v_10367 = qcar(v_10366);
    goto v_10290;
v_10291:
    v_10366 = v_10365;
    goto v_10292;
v_10293:
    v_10365 = stack[-2];
    goto v_10294;
v_10295:
    goto v_10289;
v_10290:
    goto v_10291;
v_10292:
    goto v_10293;
v_10294:
    v_10365 = acons(v_10367, v_10366, v_10365);
    env = stack[-3];
    stack[-2] = v_10365;
    goto v_10284;
v_10286:
v_10284:
    v_10365 = stack[-1];
    v_10365 = qcdr(v_10365);
    stack[-1] = v_10365;
    v_10365 = stack[0];
    v_10365 = qcdr(v_10365);
    stack[0] = v_10365;
    goto v_10246;
v_10259:
    goto v_10312;
v_10308:
    v_10365 = stack[-1];
    v_10365 = qcar(v_10365);
    v_10366 = qcar(v_10365);
    goto v_10309;
v_10310:
    v_10365 = stack[0];
    v_10365 = qcar(v_10365);
    v_10365 = qcar(v_10365);
    goto v_10311;
v_10312:
    goto v_10308;
v_10309:
    goto v_10310;
v_10311:
    fn = elt(env, 2); // b!:ordexp
    v_10365 = (*qfn2(fn))(fn, v_10366, v_10365);
    env = stack[-3];
    if (v_10365 == nil) goto v_10306;
    goto v_10324;
v_10320:
    v_10365 = stack[-1];
    v_10366 = qcar(v_10365);
    goto v_10321;
v_10322:
    v_10365 = stack[-2];
    goto v_10323;
v_10324:
    goto v_10320;
v_10321:
    goto v_10322;
v_10323:
    v_10365 = cons(v_10366, v_10365);
    env = stack[-3];
    stack[-2] = v_10365;
    v_10365 = stack[-1];
    v_10365 = qcdr(v_10365);
    stack[-1] = v_10365;
    goto v_10246;
v_10306:
    goto v_10337;
v_10333:
    v_10365 = stack[0];
    v_10366 = qcar(v_10365);
    goto v_10334;
v_10335:
    v_10365 = stack[-2];
    goto v_10336;
v_10337:
    goto v_10333;
v_10334:
    goto v_10335;
v_10336:
    v_10365 = cons(v_10366, v_10365);
    env = stack[-3];
    stack[-2] = v_10365;
    v_10365 = stack[0];
    v_10365 = qcdr(v_10365);
    stack[0] = v_10365;
    goto v_10246;
v_10247:
v_10345:
    v_10365 = stack[-2];
    if (v_10365 == nil) goto v_10348;
    else goto v_10349;
v_10348:
    goto v_10344;
v_10349:
    v_10365 = stack[-2];
    v_10365 = qcdr(v_10365);
    stack[-1] = v_10365;
    goto v_10359;
v_10355:
    v_10365 = stack[-2];
    goto v_10356;
v_10357:
    goto v_10358;
v_10359:
    goto v_10355;
v_10356:
    goto v_10357;
v_10358:
    v_10365 = Lrplacd(nil, v_10365, v_10366);
    env = stack[-3];
    v_10365 = stack[-2];
    v_10366 = v_10365;
    v_10365 = stack[-1];
    stack[-2] = v_10365;
    goto v_10345;
v_10344:
    v_10365 = v_10366;
    return onevalue(v_10365);
}



// Code for ra_refine1

static LispObject CC_ra_refine1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10341, v_10342, v_10343;
    LispObject fn;
    LispObject v_10241, v_10240, v_10239, v_10238;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ra_refine1");
    va_start(aa, nargs);
    v_10238 = va_arg(aa, LispObject);
    v_10239 = va_arg(aa, LispObject);
    v_10240 = va_arg(aa, LispObject);
    v_10241 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_10241,v_10240,v_10239,v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_10238,v_10239,v_10240,v_10241);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-2] = v_10241;
    stack[-3] = v_10240;
    stack[-4] = v_10239;
    stack[-5] = v_10238;
// end of prologue
    v_10341 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_10341;
v_10249:
    goto v_10261;
v_10257:
    v_10342 = stack[-2];
    goto v_10258;
v_10259:
    v_10341 = stack[-1];
    goto v_10260;
v_10261:
    goto v_10257;
v_10258:
    goto v_10259;
v_10260:
    v_10341 = difference2(v_10342, v_10341);
    env = stack[-7];
    v_10341 = Lminusp(nil, v_10341);
    env = stack[-7];
    if (v_10341 == nil) goto v_10254;
    goto v_10248;
v_10254:
    goto v_10270;
v_10266:
    v_10342 = stack[-4];
    goto v_10267;
v_10268:
    v_10341 = stack[-3];
    goto v_10269;
v_10270:
    goto v_10266;
v_10267:
    goto v_10268;
v_10269:
    fn = elt(env, 2); // sfto_avgq
    v_10341 = (*qfn2(fn))(fn, v_10342, v_10341);
    env = stack[-7];
    stack[-6] = v_10341;
    goto v_10282;
v_10278:
    stack[0] = stack[-5];
    goto v_10279;
v_10280:
    goto v_10290;
v_10286:
    v_10342 = elt(env, 1); // x
    goto v_10287;
v_10288:
    v_10341 = stack[-6];
    goto v_10289;
v_10290:
    goto v_10286;
v_10287:
    goto v_10288;
v_10289:
    v_10341 = cons(v_10342, v_10341);
    env = stack[-7];
    v_10341 = ncons(v_10341);
    env = stack[-7];
    goto v_10281;
v_10282:
    goto v_10278;
v_10279:
    goto v_10280;
v_10281:
    fn = elt(env, 3); // sfto_qsub1
    v_10341 = (*qfn2(fn))(fn, stack[0], v_10341);
    env = stack[-7];
    v_10341 = qcar(v_10341);
    if (v_10341 == nil) goto v_10275;
    else goto v_10276;
v_10275:
    goto v_10299;
v_10295:
    v_10342 = stack[-4];
    goto v_10296;
v_10297:
    v_10341 = stack[-6];
    goto v_10298;
v_10299:
    goto v_10295;
v_10296:
    goto v_10297;
v_10298:
    fn = elt(env, 2); // sfto_avgq
    v_10341 = (*qfn2(fn))(fn, v_10342, v_10341);
    env = stack[-7];
    stack[-4] = v_10341;
    goto v_10274;
v_10276:
    goto v_10309;
v_10305:
    goto v_10317;
v_10311:
    v_10343 = stack[-5];
    goto v_10312;
v_10313:
    v_10342 = stack[-4];
    goto v_10314;
v_10315:
    v_10341 = stack[-6];
    goto v_10316;
v_10317:
    goto v_10311;
v_10312:
    goto v_10313;
v_10314:
    goto v_10315;
v_10316:
    fn = elt(env, 4); // ra_budancount
    v_10342 = (*qfnn(fn))(fn, 3, v_10343, v_10342, v_10341);
    env = stack[-7];
    goto v_10306;
v_10307:
    v_10341 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10308;
v_10309:
    goto v_10305;
v_10306:
    goto v_10307;
v_10308:
    v_10341 = Leqn(nil, v_10342, v_10341);
    env = stack[-7];
    if (v_10341 == nil) goto v_10303;
    v_10341 = stack[-6];
    stack[-3] = v_10341;
    goto v_10274;
v_10303:
    goto v_10328;
    goto v_10326;
v_10328:
v_10326:
    v_10341 = stack[-6];
    stack[-4] = v_10341;
    goto v_10274;
v_10274:
    v_10341 = stack[-1];
    v_10341 = add1(v_10341);
    env = stack[-7];
    stack[-1] = v_10341;
    goto v_10249;
v_10248:
    goto v_10338;
v_10334:
    v_10342 = stack[-4];
    goto v_10335;
v_10336:
    v_10341 = stack[-3];
    goto v_10337;
v_10338:
    goto v_10334;
v_10335:
    goto v_10336;
v_10337:
    return cons(v_10342, v_10341);
    return onevalue(v_10341);
}



// Code for replus

static LispObject CC_replus(LispObject env,
                         LispObject v_10238)
{
    env = qenv(env);
    LispObject v_10267, v_10268;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10238);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_10268 = v_10238;
// end of prologue
    v_10267 = v_10268;
    if (v_10267 == nil) goto v_10242;
    else goto v_10243;
v_10242:
    v_10267 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10241;
v_10243:
    v_10267 = v_10268;
    if (!consp(v_10267)) goto v_10246;
    else goto v_10247;
v_10246:
    v_10267 = v_10268;
    goto v_10241;
v_10247:
    v_10267 = v_10268;
    v_10267 = qcdr(v_10267);
    if (v_10267 == nil) goto v_10250;
    else goto v_10251;
v_10250:
    v_10267 = v_10268;
    v_10267 = qcar(v_10267);
    goto v_10241;
v_10251:
    goto v_10263;
v_10259:
    stack[0] = elt(env, 1); // plus
    goto v_10260;
v_10261:
    v_10267 = v_10268;
    fn = elt(env, 2); // unplus
    v_10267 = (*qfn1(fn))(fn, v_10267);
    goto v_10262;
v_10263:
    goto v_10259;
v_10260:
    goto v_10261;
v_10262:
    {
        LispObject v_10270 = stack[0];
        return cons(v_10270, v_10267);
    }
    v_10267 = nil;
v_10241:
    return onevalue(v_10267);
}



// Code for mkpartitions1

static LispObject CC_mkpartitions1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10366, v_10367, v_10368, v_10369;
    LispObject v_10243, v_10242, v_10241, v_10240, v_10239, v_10238;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "mkpartitions1");
    va_start(aa, nargs);
    v_10238 = va_arg(aa, LispObject);
    v_10239 = va_arg(aa, LispObject);
    v_10240 = va_arg(aa, LispObject);
    v_10241 = va_arg(aa, LispObject);
    v_10242 = va_arg(aa, LispObject);
    v_10243 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_10243,v_10242,v_10241,v_10240,v_10239,v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_10238,v_10239,v_10240,v_10241,v_10242,v_10243);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-3] = v_10243;
    stack[-4] = v_10242;
    stack[-5] = v_10241;
    stack[-6] = v_10240;
    stack[-7] = v_10239;
    stack[-8] = v_10238;
// end of prologue
v_10251:
    goto v_10260;
v_10256:
    v_10367 = stack[-7];
    goto v_10257;
v_10258:
    v_10366 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10259;
v_10260:
    goto v_10256;
v_10257:
    goto v_10258;
v_10259:
    if (v_10367 == v_10366) goto v_10254;
    else goto v_10255;
v_10254:
    goto v_10272;
v_10268:
    v_10367 = stack[-8];
    goto v_10269;
v_10270:
    v_10366 = stack[-6];
    goto v_10271;
v_10272:
    goto v_10268;
v_10269:
    goto v_10270;
v_10271:
    v_10366 = (LispObject)geq2(v_10367, v_10366);
    v_10366 = v_10366 ? lisp_true : nil;
    env = stack[-10];
    if (v_10366 == nil) goto v_10266;
    goto v_10280;
v_10276:
    goto v_10287;
v_10283:
    v_10367 = stack[-8];
    goto v_10284;
v_10285:
    v_10366 = stack[-4];
    goto v_10286;
v_10287:
    goto v_10283;
v_10284:
    goto v_10285;
v_10286:
    v_10366 = cons(v_10367, v_10366);
    env = stack[-10];
    v_10367 = Lreverse(nil, v_10366);
    goto v_10277;
v_10278:
    v_10366 = stack[-3];
    goto v_10279;
v_10280:
    goto v_10276;
v_10277:
    goto v_10278;
v_10279:
    return cons(v_10367, v_10366);
v_10266:
    v_10366 = stack[-3];
    goto v_10250;
    goto v_10253;
v_10255:
    goto v_10301;
v_10297:
    v_10367 = stack[-6];
    goto v_10298;
v_10299:
    v_10366 = stack[-5];
    goto v_10300;
v_10301:
    goto v_10297;
v_10298:
    goto v_10299;
v_10300:
    v_10366 = (LispObject)greaterp2(v_10367, v_10366);
    v_10366 = v_10366 ? lisp_true : nil;
    env = stack[-10];
    if (v_10366 == nil) goto v_10295;
    v_10366 = stack[-3];
    goto v_10250;
v_10295:
    goto v_10312;
v_10308:
    v_10367 = stack[-8];
    goto v_10309;
v_10310:
    v_10366 = stack[-6];
    goto v_10311;
v_10312:
    goto v_10308;
v_10309:
    goto v_10310;
v_10311:
    v_10366 = difference2(v_10367, v_10366);
    env = stack[-10];
    stack[-9] = v_10366;
    v_10366 = stack[-7];
    v_10366 = sub1(v_10366);
    env = stack[-10];
    stack[-2] = v_10366;
    goto v_10322;
v_10318:
    goto v_10328;
v_10324:
    v_10367 = stack[-8];
    goto v_10325;
v_10326:
    v_10366 = stack[-6];
    goto v_10327;
v_10328:
    goto v_10324;
v_10325:
    goto v_10326;
v_10327:
    stack[0] = difference2(v_10367, v_10366);
    env = stack[-10];
    goto v_10319;
v_10320:
    v_10366 = stack[-7];
    v_10366 = sub1(v_10366);
    env = stack[-10];
    goto v_10321;
v_10322:
    goto v_10318;
v_10319:
    goto v_10320;
v_10321:
    v_10366 = quot2(stack[0], v_10366);
    env = stack[-10];
    stack[-1] = v_10366;
    goto v_10338;
v_10334:
    v_10367 = stack[-6];
    goto v_10335;
v_10336:
    v_10366 = stack[-4];
    goto v_10337;
v_10338:
    goto v_10334;
v_10335:
    goto v_10336;
v_10337:
    v_10366 = cons(v_10367, v_10366);
    env = stack[-10];
    stack[0] = v_10366;
    goto v_10354;
v_10342:
    goto v_10343;
v_10344:
    goto v_10345;
v_10346:
    v_10366 = stack[-6];
    v_10369 = add1(v_10366);
    env = stack[-10];
    goto v_10347;
v_10348:
    v_10368 = stack[-5];
    goto v_10349;
v_10350:
    v_10367 = stack[-4];
    goto v_10351;
v_10352:
    v_10366 = stack[-3];
    goto v_10353;
v_10354:
    goto v_10342;
v_10343:
    goto v_10344;
v_10345:
    goto v_10346;
v_10347:
    goto v_10348;
v_10349:
    goto v_10350;
v_10351:
    goto v_10352;
v_10353:
    v_10366 = CC_mkpartitions1(elt(env, 0), 6, stack[-8], stack[-7], v_10369, v_10368, v_10367, v_10366);
    env = stack[-10];
    stack[-3] = v_10366;
    v_10366 = stack[0];
    stack[-4] = v_10366;
    v_10366 = stack[-1];
    stack[-5] = v_10366;
    v_10366 = stack[-2];
    stack[-7] = v_10366;
    v_10366 = stack[-9];
    stack[-8] = v_10366;
    goto v_10251;
v_10253:
    v_10366 = nil;
v_10250:
    return onevalue(v_10366);
}



// Code for wusort

static LispObject CC_wusort(LispObject env,
                         LispObject v_10238)
{
    env = qenv(env);
    LispObject v_10248, v_10249;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10248 = v_10238;
// end of prologue
    goto v_10245;
v_10241:
    v_10249 = v_10248;
    goto v_10242;
v_10243:
    v_10248 = elt(env, 1); // wulessp!*
    goto v_10244;
v_10245:
    goto v_10241;
v_10242:
    goto v_10243;
v_10244:
    {
        fn = elt(env, 2); // sort
        return (*qfn2(fn))(fn, v_10249, v_10248);
    }
}



// Code for expnd1

static LispObject CC_expnd1(LispObject env,
                         LispObject v_10238)
{
    env = qenv(env);
    LispObject v_10364, v_10365;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10238);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_10238;
// end of prologue
    stack[-2] = nil;
v_10244:
    v_10364 = stack[-1];
    if (!consp(v_10364)) goto v_10253;
    else goto v_10254;
v_10253:
    v_10364 = lisp_true;
    goto v_10252;
v_10254:
    v_10364 = stack[-1];
    v_10364 = qcar(v_10364);
    v_10364 = (consp(v_10364) ? nil : lisp_true);
    goto v_10252;
    v_10364 = nil;
v_10252:
    if (v_10364 == nil) goto v_10250;
    goto v_10245;
v_10250:
    goto v_10267;
v_10263:
    v_10364 = stack[-1];
    v_10364 = qcar(v_10364);
    v_10364 = qcar(v_10364);
    v_10364 = qcar(v_10364);
    fn = elt(env, 1); // sfp
    v_10364 = (*qfn1(fn))(fn, v_10364);
    env = stack[-3];
    if (v_10364 == nil) goto v_10274;
    else goto v_10275;
v_10274:
    v_10364 = lisp_true;
    goto v_10273;
v_10275:
    goto v_10289;
v_10285:
    v_10364 = stack[-1];
    v_10364 = qcar(v_10364);
    v_10364 = qcar(v_10364);
    v_10365 = qcdr(v_10364);
    goto v_10286;
v_10287:
    v_10364 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10288;
v_10289:
    goto v_10285;
v_10286:
    goto v_10287;
v_10288:
    v_10364 = (LispObject)lessp2(v_10365, v_10364);
    v_10364 = v_10364 ? lisp_true : nil;
    env = stack[-3];
    goto v_10273;
    v_10364 = nil;
v_10273:
    if (v_10364 == nil) goto v_10271;
    goto v_10300;
v_10296:
    goto v_10307;
v_10303:
    v_10364 = stack[-1];
    v_10364 = qcar(v_10364);
    v_10365 = qcar(v_10364);
    goto v_10304;
v_10305:
    v_10364 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10306;
v_10307:
    goto v_10303;
v_10304:
    goto v_10305;
v_10306:
    v_10364 = cons(v_10365, v_10364);
    env = stack[-3];
    stack[0] = ncons(v_10364);
    env = stack[-3];
    goto v_10297;
v_10298:
    v_10364 = stack[-1];
    v_10364 = qcar(v_10364);
    v_10364 = qcdr(v_10364);
    v_10364 = CC_expnd1(elt(env, 0), v_10364);
    env = stack[-3];
    goto v_10299;
v_10300:
    goto v_10296;
v_10297:
    goto v_10298;
v_10299:
    fn = elt(env, 2); // multf
    v_10364 = (*qfn2(fn))(fn, stack[0], v_10364);
    env = stack[-3];
    v_10365 = v_10364;
    goto v_10269;
v_10271:
    goto v_10323;
v_10319:
    goto v_10329;
v_10325:
    v_10364 = stack[-1];
    v_10364 = qcar(v_10364);
    v_10364 = qcar(v_10364);
    v_10364 = qcar(v_10364);
    v_10365 = CC_expnd1(elt(env, 0), v_10364);
    env = stack[-3];
    goto v_10326;
v_10327:
    v_10364 = stack[-1];
    v_10364 = qcar(v_10364);
    v_10364 = qcar(v_10364);
    v_10364 = qcdr(v_10364);
    goto v_10328;
v_10329:
    goto v_10325;
v_10326:
    goto v_10327;
v_10328:
    fn = elt(env, 3); // exptf
    stack[0] = (*qfn2(fn))(fn, v_10365, v_10364);
    env = stack[-3];
    goto v_10320;
v_10321:
    v_10364 = stack[-1];
    v_10364 = qcar(v_10364);
    v_10364 = qcdr(v_10364);
    v_10364 = CC_expnd1(elt(env, 0), v_10364);
    env = stack[-3];
    goto v_10322;
v_10323:
    goto v_10319;
v_10320:
    goto v_10321;
v_10322:
    fn = elt(env, 2); // multf
    v_10364 = (*qfn2(fn))(fn, stack[0], v_10364);
    env = stack[-3];
    v_10365 = v_10364;
    goto v_10269;
    v_10365 = nil;
v_10269:
    goto v_10264;
v_10265:
    v_10364 = stack[-2];
    goto v_10266;
v_10267:
    goto v_10263;
v_10264:
    goto v_10265;
v_10266:
    v_10364 = cons(v_10365, v_10364);
    env = stack[-3];
    stack[-2] = v_10364;
    v_10364 = stack[-1];
    v_10364 = qcdr(v_10364);
    stack[-1] = v_10364;
    goto v_10244;
v_10245:
    v_10364 = stack[-1];
    v_10365 = v_10364;
v_10246:
    v_10364 = stack[-2];
    if (v_10364 == nil) goto v_10349;
    else goto v_10350;
v_10349:
    v_10364 = v_10365;
    goto v_10243;
v_10350:
    goto v_10358;
v_10354:
    v_10364 = stack[-2];
    v_10364 = qcar(v_10364);
    goto v_10355;
v_10356:
    goto v_10357;
v_10358:
    goto v_10354;
v_10355:
    goto v_10356;
v_10357:
    fn = elt(env, 4); // addf
    v_10364 = (*qfn2(fn))(fn, v_10364, v_10365);
    env = stack[-3];
    v_10365 = v_10364;
    v_10364 = stack[-2];
    v_10364 = qcdr(v_10364);
    stack[-2] = v_10364;
    goto v_10246;
v_10243:
    return onevalue(v_10364);
}



// Code for talp_simplatat

static LispObject CC_talp_simplatat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10365, v_10366, v_10367;
    LispObject fn;
    LispObject v_10240, v_10239, v_10238;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_simplatat");
    va_start(aa, nargs);
    v_10238 = va_arg(aa, LispObject);
    v_10239 = va_arg(aa, LispObject);
    v_10240 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_10240,v_10239,v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_10238,v_10239,v_10240);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_10240;
    stack[-1] = v_10239;
    stack[-2] = v_10238;
// end of prologue
    goto v_10250;
v_10246:
    v_10366 = stack[-1];
    goto v_10247;
v_10248:
    v_10365 = stack[0];
    goto v_10249;
v_10250:
    goto v_10246;
v_10247:
    goto v_10248;
v_10249:
    if (v_10366 == v_10365) goto v_10244;
    else goto v_10245;
v_10244:
    goto v_10257;
v_10253:
    v_10365 = stack[-2];
    goto v_10254;
v_10255:
    v_10366 = elt(env, 1); // equal
    goto v_10256;
v_10257:
    goto v_10253;
v_10254:
    goto v_10255;
v_10256:
    v_10365 = (v_10365 == v_10366 ? lisp_true : nil);
    goto v_10243;
v_10245:
    goto v_10267;
v_10263:
    stack[-3] = stack[-1];
    goto v_10264;
v_10265:
    fn = elt(env, 2); // talp_getl
    v_10365 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_10266;
v_10267:
    goto v_10263;
v_10264:
    goto v_10265;
v_10266:
    v_10365 = Latsoc(nil, stack[-3], v_10365);
    if (v_10365 == nil) goto v_10261;
    else goto v_10262;
v_10261:
    v_10365 = stack[0];
    if (!consp(v_10365)) goto v_10273;
    else goto v_10274;
v_10273:
    goto v_10283;
v_10277:
    v_10367 = stack[-2];
    goto v_10278;
v_10279:
    v_10366 = stack[-1];
    goto v_10280;
v_10281:
    v_10365 = stack[0];
    goto v_10282;
v_10283:
    goto v_10277;
v_10278:
    goto v_10279;
v_10280:
    goto v_10281;
v_10282:
    {
        fn = elt(env, 3); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_10367, v_10366, v_10365);
    }
v_10274:
    goto v_10294;
v_10290:
    v_10366 = stack[-1];
    goto v_10291;
v_10292:
    v_10365 = stack[0];
    goto v_10293;
v_10294:
    goto v_10290;
v_10291:
    goto v_10292;
v_10293:
    fn = elt(env, 4); // talp_telp
    v_10365 = (*qfn2(fn))(fn, v_10366, v_10365);
    env = stack[-4];
    if (v_10365 == nil) goto v_10288;
    goto v_10302;
v_10298:
    v_10365 = stack[-2];
    goto v_10299;
v_10300:
    v_10366 = elt(env, 1); // equal
    goto v_10301;
v_10302:
    goto v_10298;
v_10299:
    goto v_10300;
v_10301:
        return Lneq(nil, v_10365, v_10366);
v_10288:
    goto v_10314;
v_10308:
    v_10367 = stack[-2];
    goto v_10309;
v_10310:
    v_10366 = stack[-1];
    goto v_10311;
v_10312:
    v_10365 = stack[0];
    goto v_10313;
v_10314:
    goto v_10308;
v_10309:
    goto v_10310;
v_10311:
    goto v_10312;
v_10313:
    {
        fn = elt(env, 3); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_10367, v_10366, v_10365);
    }
    v_10365 = nil;
    goto v_10243;
v_10262:
    v_10365 = stack[0];
    if (!consp(v_10365)) goto v_10318;
    else goto v_10319;
v_10318:
    goto v_10329;
v_10325:
    stack[-3] = stack[0];
    goto v_10326;
v_10327:
    fn = elt(env, 2); // talp_getl
    v_10365 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_10328;
v_10329:
    goto v_10325;
v_10326:
    goto v_10327;
v_10328:
    v_10365 = Latsoc(nil, stack[-3], v_10365);
    if (v_10365 == nil) goto v_10323;
    else goto v_10324;
v_10323:
    goto v_10340;
v_10334:
    goto v_10335;
v_10336:
    goto v_10337;
v_10338:
    v_10365 = stack[0];
    fn = elt(env, 5); // talp_simplt
    v_10365 = (*qfn1(fn))(fn, v_10365);
    env = stack[-4];
    goto v_10339;
v_10340:
    goto v_10334;
v_10335:
    goto v_10336;
v_10337:
    goto v_10338;
v_10339:
    {
        LispObject v_10372 = stack[-2];
        LispObject v_10373 = stack[-1];
        fn = elt(env, 3); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_10372, v_10373, v_10365);
    }
v_10324:
    goto v_10352;
v_10348:
    v_10365 = stack[-2];
    goto v_10349;
v_10350:
    v_10366 = elt(env, 1); // equal
    goto v_10351;
v_10352:
    goto v_10348;
v_10349:
    goto v_10350;
v_10351:
        return Lneq(nil, v_10365, v_10366);
    v_10365 = nil;
    goto v_10243;
v_10319:
    goto v_10362;
v_10358:
    v_10365 = stack[-2];
    goto v_10359;
v_10360:
    v_10366 = elt(env, 1); // equal
    goto v_10361;
v_10362:
    goto v_10358;
v_10359:
    goto v_10360;
v_10361:
        return Lneq(nil, v_10365, v_10366);
    v_10365 = nil;
v_10243:
    return onevalue(v_10365);
}



// Code for ibalp_unvar!-unsatlist

static LispObject CC_ibalp_unvarKunsatlist(LispObject env,
                         LispObject v_10238, LispObject v_10239)
{
    env = qenv(env);
    LispObject v_10617, v_10618;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10239,v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10238,v_10239);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_10239;
    v_10617 = v_10238;
// end of prologue
    stack[-5] = v_10617;
v_10247:
    v_10617 = stack[-5];
    if (v_10617 == nil) goto v_10251;
    else goto v_10252;
v_10251:
    goto v_10246;
v_10252:
    v_10617 = stack[-5];
    v_10617 = qcar(v_10617);
    stack[-3] = v_10617;
    goto v_10263;
v_10259:
    v_10617 = stack[-3];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    stack[0] = qcdr(v_10617);
    goto v_10260;
v_10261:
    goto v_10274;
v_10270:
    v_10618 = stack[-4];
    goto v_10271;
v_10272:
    v_10617 = stack[-3];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcar(v_10617);
    goto v_10273;
v_10274:
    goto v_10270;
v_10271:
    goto v_10272;
v_10273:
    fn = elt(env, 1); // delq
    v_10617 = (*qfn2(fn))(fn, v_10618, v_10617);
    env = stack[-6];
    goto v_10262;
v_10263:
    goto v_10259;
v_10260:
    goto v_10261;
v_10262:
    fn = elt(env, 2); // setcar
    v_10617 = (*qfn2(fn))(fn, stack[0], v_10617);
    env = stack[-6];
    v_10617 = stack[-3];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcar(v_10617);
    if (v_10617 == nil) goto v_10284;
    else goto v_10285;
v_10284:
    v_10617 = stack[-3];
    v_10617 = qcar(v_10617);
    stack[-2] = v_10617;
v_10295:
    v_10617 = stack[-2];
    if (v_10617 == nil) goto v_10300;
    else goto v_10301;
v_10300:
    goto v_10294;
v_10301:
    v_10617 = stack[-2];
    v_10617 = qcar(v_10617);
    stack[-1] = v_10617;
    goto v_10312;
v_10308:
    v_10617 = stack[-1];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    stack[0] = qcdr(v_10617);
    goto v_10309;
v_10310:
    v_10617 = stack[-1];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcar(v_10617);
    v_10617 = add1(v_10617);
    env = stack[-6];
    goto v_10311;
v_10312:
    goto v_10308;
v_10309:
    goto v_10310;
v_10311:
    fn = elt(env, 2); // setcar
    v_10617 = (*qfn2(fn))(fn, stack[0], v_10617);
    env = stack[-6];
    goto v_10330;
v_10326:
    v_10617 = stack[-1];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    stack[0] = qcdr(v_10617);
    goto v_10327;
v_10328:
    v_10617 = stack[-1];
    fn = elt(env, 3); // ibalp_calcmom
    v_10617 = (*qfn1(fn))(fn, v_10617);
    env = stack[-6];
    goto v_10329;
v_10330:
    goto v_10326;
v_10327:
    goto v_10328;
v_10329:
    fn = elt(env, 2); // setcar
    v_10617 = (*qfn2(fn))(fn, stack[0], v_10617);
    env = stack[-6];
    v_10617 = stack[-2];
    v_10617 = qcdr(v_10617);
    stack[-2] = v_10617;
    goto v_10295;
v_10294:
    v_10617 = stack[-3];
    v_10617 = qcdr(v_10617);
    v_10617 = qcar(v_10617);
    stack[-2] = v_10617;
v_10350:
    v_10617 = stack[-2];
    if (v_10617 == nil) goto v_10356;
    else goto v_10357;
v_10356:
    goto v_10349;
v_10357:
    v_10617 = stack[-2];
    v_10617 = qcar(v_10617);
    stack[-1] = v_10617;
    goto v_10368;
v_10364:
    v_10617 = stack[-1];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    stack[0] = qcdr(v_10617);
    goto v_10365;
v_10366:
    v_10617 = stack[-1];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcar(v_10617);
    v_10617 = add1(v_10617);
    env = stack[-6];
    goto v_10367;
v_10368:
    goto v_10364;
v_10365:
    goto v_10366;
v_10367:
    fn = elt(env, 2); // setcar
    v_10617 = (*qfn2(fn))(fn, stack[0], v_10617);
    env = stack[-6];
    goto v_10388;
v_10384:
    v_10617 = stack[-1];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    stack[0] = qcdr(v_10617);
    goto v_10385;
v_10386:
    v_10617 = stack[-1];
    fn = elt(env, 3); // ibalp_calcmom
    v_10617 = (*qfn1(fn))(fn, v_10617);
    env = stack[-6];
    goto v_10387;
v_10388:
    goto v_10384;
v_10385:
    goto v_10386;
v_10387:
    fn = elt(env, 2); // setcar
    v_10617 = (*qfn2(fn))(fn, stack[0], v_10617);
    env = stack[-6];
    v_10617 = stack[-2];
    v_10617 = qcdr(v_10617);
    stack[-2] = v_10617;
    goto v_10350;
v_10349:
    v_10617 = stack[-3];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcar(v_10617);
    stack[-1] = v_10617;
v_10408:
    v_10617 = stack[-1];
    if (v_10617 == nil) goto v_10419;
    else goto v_10420;
v_10419:
    goto v_10407;
v_10420:
    v_10617 = stack[-1];
    v_10617 = qcar(v_10617);
    goto v_10431;
v_10427:
    v_10618 = v_10617;
    v_10618 = qcdr(v_10618);
    v_10618 = qcdr(v_10618);
    v_10618 = qcdr(v_10618);
    v_10618 = qcdr(v_10618);
    v_10618 = qcdr(v_10618);
    v_10618 = qcdr(v_10618);
    v_10618 = qcdr(v_10618);
    v_10618 = qcdr(v_10618);
    v_10618 = qcdr(v_10618);
    stack[0] = qcdr(v_10618);
    goto v_10428;
v_10429:
    goto v_10448;
v_10444:
    v_10618 = stack[-3];
    goto v_10445;
v_10446:
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcar(v_10617);
    goto v_10447;
v_10448:
    goto v_10444;
v_10445:
    goto v_10446;
v_10447:
    fn = elt(env, 1); // delq
    v_10617 = (*qfn2(fn))(fn, v_10618, v_10617);
    env = stack[-6];
    goto v_10430;
v_10431:
    goto v_10427;
v_10428:
    goto v_10429;
v_10430:
    fn = elt(env, 2); // setcar
    v_10617 = (*qfn2(fn))(fn, stack[0], v_10617);
    env = stack[-6];
    v_10617 = stack[-1];
    v_10617 = qcdr(v_10617);
    stack[-1] = v_10617;
    goto v_10408;
v_10407:
    goto v_10469;
v_10465:
    v_10617 = stack[-3];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10618 = qcdr(v_10617);
    goto v_10466;
v_10467:
    v_10617 = nil;
    goto v_10468;
v_10469:
    goto v_10465;
v_10466:
    goto v_10467;
v_10468:
    fn = elt(env, 2); // setcar
    v_10617 = (*qfn2(fn))(fn, v_10618, v_10617);
    env = stack[-6];
    v_10617 = stack[-3];
    fn = elt(env, 4); // ibalp_getnewwl
    v_10617 = (*qfn1(fn))(fn, v_10617);
    env = stack[-6];
    stack[-1] = v_10617;
    goto v_10485;
v_10481:
    v_10617 = stack[-3];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    stack[0] = qcdr(v_10617);
    goto v_10482;
v_10483:
    goto v_10498;
v_10494:
    v_10618 = stack[-1];
    goto v_10495;
v_10496:
    v_10617 = stack[-3];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcar(v_10617);
    goto v_10497;
v_10498:
    goto v_10494;
v_10495:
    goto v_10496;
v_10497:
    v_10617 = cons(v_10618, v_10617);
    env = stack[-6];
    goto v_10484;
v_10485:
    goto v_10481;
v_10482:
    goto v_10483;
v_10484:
    fn = elt(env, 2); // setcar
    v_10617 = (*qfn2(fn))(fn, stack[0], v_10617);
    env = stack[-6];
    goto v_10513;
v_10509:
    v_10617 = stack[-1];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    stack[0] = qcdr(v_10617);
    goto v_10510;
v_10511:
    goto v_10530;
v_10526:
    v_10618 = stack[-3];
    goto v_10527;
v_10528:
    v_10617 = stack[-1];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcar(v_10617);
    goto v_10529;
v_10530:
    goto v_10526;
v_10527:
    goto v_10528;
v_10529:
    v_10617 = cons(v_10618, v_10617);
    env = stack[-6];
    goto v_10512;
v_10513:
    goto v_10509;
v_10510:
    goto v_10511;
v_10512:
    fn = elt(env, 2); // setcar
    v_10617 = (*qfn2(fn))(fn, stack[0], v_10617);
    env = stack[-6];
    v_10617 = stack[-3];
    fn = elt(env, 4); // ibalp_getnewwl
    v_10617 = (*qfn1(fn))(fn, v_10617);
    env = stack[-6];
    stack[-1] = v_10617;
    v_10617 = stack[-1];
    if (v_10617 == nil) goto v_10549;
    goto v_10556;
v_10552:
    v_10617 = stack[-3];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    stack[0] = qcdr(v_10617);
    goto v_10553;
v_10554:
    goto v_10569;
v_10565:
    v_10618 = stack[-1];
    goto v_10566;
v_10567:
    v_10617 = stack[-3];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcar(v_10617);
    goto v_10568;
v_10569:
    goto v_10565;
v_10566:
    goto v_10567;
v_10568:
    v_10617 = cons(v_10618, v_10617);
    env = stack[-6];
    goto v_10555;
v_10556:
    goto v_10552;
v_10553:
    goto v_10554;
v_10555:
    fn = elt(env, 2); // setcar
    v_10617 = (*qfn2(fn))(fn, stack[0], v_10617);
    env = stack[-6];
    goto v_10584;
v_10580:
    v_10617 = stack[-1];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    stack[0] = qcdr(v_10617);
    goto v_10581;
v_10582:
    goto v_10601;
v_10597:
    v_10618 = stack[-3];
    goto v_10598;
v_10599:
    v_10617 = stack[-1];
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcdr(v_10617);
    v_10617 = qcar(v_10617);
    goto v_10600;
v_10601:
    goto v_10597;
v_10598:
    goto v_10599;
v_10600:
    v_10617 = cons(v_10618, v_10617);
    env = stack[-6];
    goto v_10583;
v_10584:
    goto v_10580;
v_10581:
    goto v_10582;
v_10583:
    fn = elt(env, 2); // setcar
    v_10617 = (*qfn2(fn))(fn, stack[0], v_10617);
    env = stack[-6];
    goto v_10547;
v_10549:
v_10547:
    goto v_10283;
v_10285:
v_10283:
    v_10617 = stack[-5];
    v_10617 = qcdr(v_10617);
    stack[-5] = v_10617;
    goto v_10247;
v_10246:
    v_10617 = nil;
    return onevalue(v_10617);
}



// Code for mml2om

static LispObject CC_mml2om(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10253;
    LispObject fn;
    argcheck(nargs, 0, "mml2om");
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
    fn = elt(env, 2); // mml2ir
    v_10253 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_10253;
    v_10253 = lisp_true;
    fn = elt(env, 3); // terpri!*
    v_10253 = (*qfn1(fn))(fn, v_10253);
    env = stack[-1];
    v_10253 = elt(env, 1); // "Intermediate representation: "
    v_10253 = Lprinc(nil, v_10253);
    env = stack[-1];
    v_10253 = lisp_true;
    fn = elt(env, 3); // terpri!*
    v_10253 = (*qfn1(fn))(fn, v_10253);
    env = stack[-1];
    v_10253 = stack[0];
    v_10253 = Lprint(nil, v_10253);
    env = stack[-1];
    v_10253 = stack[0];
    fn = elt(env, 4); // ir2om
    v_10253 = (*qfn1(fn))(fn, v_10253);
    v_10253 = nil;
    return onevalue(v_10253);
}



// Code for lesspcdr

static LispObject CC_lesspcdr(LispObject env,
                         LispObject v_10238, LispObject v_10239)
{
    env = qenv(env);
    LispObject v_10251, v_10252;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10251 = v_10239;
    v_10252 = v_10238;
// end of prologue
    goto v_10246;
v_10242:
    v_10252 = qcdr(v_10252);
    goto v_10243;
v_10244:
    v_10251 = qcdr(v_10251);
    goto v_10245;
v_10246:
    goto v_10242;
v_10243:
    goto v_10244;
v_10245:
        return Llessp(nil, v_10252, v_10251);
}



// Code for command

static LispObject CC_command(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10554, v_10555, v_10556, v_10557;
    LispObject fn;
    argcheck(nargs, 0, "command");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// end of prologue
// Binding errmsg!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = nil; // errmsg!*
// Binding loopdelimslist!*
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-3, 2, -1);
    qvalue(elt(env, 2)) = nil; // loopdelimslist!*
    v_10554 = qvalue(elt(env, 3)); // !*demo
    if (v_10554 == nil) goto v_10252;
    v_10554 = qvalue(elt(env, 4)); // ifl!*
    if (v_10554 == nil) goto v_10252;
    fn = elt(env, 27); // commdemo
    v_10554 = (*qfnn(fn))(fn, 0);
    goto v_10245;
v_10252:
    v_10554 = qvalue(elt(env, 5)); // !*slin
    if (v_10554 == nil) goto v_10262;
    else goto v_10263;
v_10262:
    v_10554 = lisp_true;
    goto v_10261;
v_10263:
    v_10554 = qvalue(elt(env, 6)); // !*reduce4
    goto v_10261;
    v_10554 = nil;
v_10261:
    if (v_10554 == nil) goto v_10259;
    goto v_10246;
v_10259:
    fn = elt(env, 28); // setcloc!*
    v_10554 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    v_10554 = qvalue(elt(env, 7)); // lreadfn!*
    if (v_10554 == nil) goto v_10273;
    goto v_10280;
v_10276:
    v_10555 = qvalue(elt(env, 7)); // lreadfn!*
    goto v_10277;
v_10278:
    v_10554 = nil;
    goto v_10279;
v_10280:
    goto v_10276;
v_10277:
    goto v_10278;
v_10279:
    fn = elt(env, 29); // lispapply
    v_10554 = (*qfn2(fn))(fn, v_10555, v_10554);
    env = stack[-3];
    goto v_10271;
v_10273:
    v_10554 = Lread(nil, 0);
    env = stack[-3];
    goto v_10271;
    v_10554 = nil;
v_10271:
    stack[0] = v_10554;
    goto v_10247;
v_10246:
    fn = elt(env, 30); // readch1
    v_10554 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    qvalue(elt(env, 8)) = v_10554; // crchar!*
    goto v_10295;
v_10291:
    v_10555 = qvalue(elt(env, 8)); // crchar!*
    goto v_10292;
v_10293:
    v_10554 = qvalue(elt(env, 9)); // !$eol!$
    goto v_10294;
v_10295:
    goto v_10291;
v_10292:
    goto v_10293;
v_10294:
    if (equal(v_10555, v_10554)) goto v_10289;
    else goto v_10290;
v_10289:
    goto v_10246;
v_10290:
    fn = elt(env, 31); // command1
    v_10554 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[0] = v_10554;
v_10247:
    v_10554 = qvalue(elt(env, 6)); // !*reduce4
    if (v_10554 == nil) goto v_10302;
    goto v_10248;
v_10302:
    v_10554 = qvalue(elt(env, 10)); // !*struct
    if (v_10554 == nil) goto v_10305;
    v_10554 = stack[0];
    fn = elt(env, 32); // structchk
    v_10554 = (*qfn1(fn))(fn, v_10554);
    env = stack[-3];
    stack[0] = v_10554;
    goto v_10300;
v_10305:
v_10300:
    v_10554 = qvalue(elt(env, 11)); // !*pret
    if (v_10554 == nil) goto v_10312;
    v_10554 = stack[0];
    if (!consp(v_10554)) goto v_10318;
    else goto v_10319;
v_10318:
    v_10554 = lisp_true;
    goto v_10317;
v_10319:
    goto v_10328;
v_10324:
    v_10554 = stack[0];
    v_10555 = qcar(v_10554);
    goto v_10325;
v_10326:
    v_10554 = elt(env, 12); // (in out shut)
    goto v_10327;
v_10328:
    goto v_10324;
v_10325:
    goto v_10326;
v_10327:
    v_10554 = Lmemq(nil, v_10555, v_10554);
    v_10554 = (v_10554 == nil ? lisp_true : nil);
    goto v_10317;
    v_10554 = nil;
v_10317:
    if (v_10554 == nil) goto v_10312;
    v_10554 = stack[0];
    if (v_10554 == nil) goto v_10340;
    else goto v_10341;
v_10340:
    goto v_10347;
v_10343:
    v_10555 = qvalue(elt(env, 13)); // cursym!*
    goto v_10344;
v_10345:
    v_10554 = elt(env, 14); // end
    goto v_10346;
v_10347:
    goto v_10343;
v_10344:
    goto v_10345;
v_10346:
    v_10554 = (v_10555 == v_10554 ? lisp_true : nil);
    goto v_10339;
v_10341:
    v_10554 = nil;
    goto v_10339;
    v_10554 = nil;
v_10339:
    if (v_10554 == nil) goto v_10337;
    v_10554 = elt(env, 14); // end
    fn = elt(env, 33); // rprint
    v_10554 = (*qfn1(fn))(fn, v_10554);
    env = stack[-3];
    goto v_10335;
v_10337:
    v_10554 = stack[0];
    fn = elt(env, 33); // rprint
    v_10554 = (*qfn1(fn))(fn, v_10554);
    env = stack[-3];
    v_10554 = Lterpri(nil, 0);
    env = stack[-3];
    goto v_10335;
v_10335:
    goto v_10310;
v_10312:
v_10310:
    v_10554 = qvalue(elt(env, 5)); // !*slin
    if (v_10554 == nil) goto v_10364;
    goto v_10371;
v_10367:
    v_10555 = elt(env, 15); // symbolic
    goto v_10368;
v_10369:
    v_10554 = stack[0];
    goto v_10370;
v_10371:
    goto v_10367;
v_10368:
    goto v_10369;
v_10370:
    v_10554 = list2(v_10555, v_10554);
    goto v_10245;
v_10364:
    v_10554 = stack[0];
    fn = elt(env, 34); // form
    v_10554 = (*qfn1(fn))(fn, v_10554);
    env = stack[-3];
    v_10555 = v_10554;
    v_10554 = qvalue(elt(env, 16)); // key!*
    if (!symbolp(v_10554)) v_10554 = nil;
    else { v_10554 = qfastgets(v_10554);
           if (v_10554 != nil) { v_10554 = elt(v_10554, 48); // modefn
#ifdef RECORD_GET
             if (v_10554 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v_10554 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v_10554 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v_10554 == SPID_NOPROP) v_10554 = nil; else v_10554 = lisp_true; }}
#endif
    if (v_10554 == nil) goto v_10379;
    v_10554 = qvalue(elt(env, 16)); // key!*
    goto v_10377;
v_10379:
    v_10554 = v_10555;
    if (!consp(v_10554)) goto v_10388;
    goto v_10398;
v_10394:
    v_10554 = v_10555;
    v_10556 = qcar(v_10554);
    goto v_10395;
v_10396:
    v_10554 = elt(env, 17); // quote
    goto v_10397;
v_10398:
    goto v_10394;
v_10395:
    goto v_10396;
v_10397:
    if (v_10556 == v_10554) goto v_10393;
    v_10554 = v_10555;
    v_10554 = qcar(v_10554);
    if (symbolp(v_10554)) goto v_10406;
    else goto v_10404;
v_10406:
    goto v_10419;
v_10415:
    v_10554 = v_10555;
    v_10556 = qcar(v_10554);
    goto v_10416;
v_10417:
    v_10554 = elt(env, 18); // nochange
    goto v_10418;
v_10419:
    goto v_10415;
v_10416:
    goto v_10417;
v_10418:
    v_10554 = Lflagp(nil, v_10556, v_10554);
    env = stack[-3];
    if (v_10554 == nil) goto v_10413;
    v_10554 = lisp_true;
    goto v_10411;
v_10413:
    goto v_10435;
v_10431:
    v_10554 = v_10555;
    v_10556 = qcar(v_10554);
    goto v_10432;
v_10433:
    v_10554 = elt(env, 19); // intfn
    goto v_10434;
v_10435:
    goto v_10431;
v_10432:
    goto v_10433;
v_10434:
    v_10554 = Lflagp(nil, v_10556, v_10554);
    env = stack[-3];
    if (v_10554 == nil) goto v_10429;
    v_10554 = lisp_true;
    goto v_10427;
v_10429:
    goto v_10446;
v_10442:
    v_10554 = v_10555;
    v_10556 = qcar(v_10554);
    goto v_10443;
v_10444:
    v_10554 = elt(env, 20); // list
    goto v_10445;
v_10446:
    goto v_10442;
v_10443:
    goto v_10444;
v_10445:
    v_10554 = (v_10556 == v_10554 ? lisp_true : nil);
    goto v_10427;
    v_10554 = nil;
v_10427:
    goto v_10411;
    v_10554 = nil;
v_10411:
    if (v_10554 == nil) goto v_10404;
    goto v_10405;
v_10404:
    v_10554 = lisp_true;
    goto v_10403;
v_10405:
    goto v_10462;
v_10458:
    v_10554 = v_10555;
    v_10556 = qcar(v_10554);
    goto v_10459;
v_10460:
    v_10554 = elt(env, 21); // (setq setel setf)
    goto v_10461;
v_10462:
    goto v_10458;
v_10459:
    goto v_10460;
v_10461:
    v_10554 = Lmemq(nil, v_10556, v_10554);
    if (v_10554 == nil) goto v_10456;
    else goto v_10457;
v_10456:
    v_10554 = nil;
    goto v_10455;
v_10457:
    goto v_10475;
v_10471:
    v_10554 = v_10555;
    v_10554 = qcdr(v_10554);
    v_10554 = qcdr(v_10554);
    v_10556 = qcar(v_10554);
    goto v_10472;
v_10473:
    v_10554 = elt(env, 17); // quote
    goto v_10474;
v_10475:
    goto v_10471;
v_10472:
    goto v_10473;
v_10474:
    v_10554 = Leqcar(nil, v_10556, v_10554);
    env = stack[-3];
    goto v_10455;
    v_10554 = nil;
v_10455:
    goto v_10403;
    v_10554 = nil;
v_10403:
    goto v_10391;
v_10393:
    v_10554 = nil;
    goto v_10391;
    v_10554 = nil;
v_10391:
    goto v_10386;
v_10388:
    v_10554 = nil;
    goto v_10386;
    v_10554 = nil;
v_10386:
    if (v_10554 == nil) goto v_10384;
    v_10554 = elt(env, 15); // symbolic
    goto v_10377;
v_10384:
    v_10554 = qvalue(elt(env, 22)); // !*mode
    goto v_10377;
v_10377:
    goto v_10496;
v_10492:
    stack[0] = v_10554;
    goto v_10493;
v_10494:
    goto v_10507;
v_10499:
    v_10557 = v_10555;
    goto v_10500;
v_10501:
    v_10556 = nil;
    goto v_10502;
v_10503:
    v_10555 = elt(env, 15); // symbolic
    goto v_10504;
v_10505:
    goto v_10506;
v_10507:
    goto v_10499;
v_10500:
    goto v_10501;
v_10502:
    goto v_10503;
v_10504:
    goto v_10505;
v_10506:
    fn = elt(env, 35); // convertmode1
    v_10554 = (*qfnn(fn))(fn, 4, v_10557, v_10556, v_10555, v_10554);
    env = stack[-3];
    goto v_10495;
v_10496:
    goto v_10492;
v_10493:
    goto v_10494;
v_10495:
    v_10554 = list2(stack[0], v_10554);
    goto v_10245;
v_10248:
    v_10554 = qvalue(elt(env, 23)); // !*debug
    if (v_10554 == nil) goto v_10515;
    v_10554 = elt(env, 24); // "Parse: "
    v_10554 = Lprinc(nil, v_10554);
    env = stack[-3];
    v_10554 = stack[0];
    fn = elt(env, 36); // prettyprint
    v_10554 = (*qfn1(fn))(fn, v_10554);
    env = stack[-3];
    goto v_10513;
v_10515:
v_10513:
    goto v_10529;
v_10525:
    v_10555 = qvalue(elt(env, 16)); // key!*
    goto v_10526;
v_10527:
    v_10554 = elt(env, 25); // !*semicol!*
    goto v_10528;
v_10529:
    goto v_10525;
v_10526:
    goto v_10527;
v_10528:
    if (v_10555 == v_10554) goto v_10523;
    else goto v_10524;
v_10523:
    goto v_10246;
v_10524:
    v_10554 = qvalue(elt(env, 6)); // !*reduce4
    if (v_10554 == nil) goto v_10534;
    else goto v_10535;
v_10534:
    v_10554 = stack[0];
    fn = elt(env, 34); // form
    v_10554 = (*qfn1(fn))(fn, v_10554);
    env = stack[-3];
    stack[0] = v_10554;
    goto v_10533;
v_10535:
    v_10554 = stack[0];
    fn = elt(env, 37); // n_form
    v_10554 = (*qfn1(fn))(fn, v_10554);
    env = stack[-3];
    stack[0] = v_10554;
    goto v_10533;
v_10533:
    v_10554 = qvalue(elt(env, 23)); // !*debug
    if (v_10554 == nil) goto v_10546;
    v_10554 = Lterpri(nil, 0);
    env = stack[-3];
    v_10554 = elt(env, 26); // "Form: "
    v_10554 = Lprinc(nil, v_10554);
    env = stack[-3];
    v_10554 = stack[0];
    fn = elt(env, 36); // prettyprint
    v_10554 = (*qfn1(fn))(fn, v_10554);
    goto v_10544;
v_10546:
v_10544:
    v_10554 = stack[0];
v_10245:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_10554);
}



// Code for ord2

static LispObject CC_ord2(LispObject env,
                         LispObject v_10238, LispObject v_10239)
{
    env = qenv(env);
    LispObject v_10271, v_10272;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10239,v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10238,v_10239);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10239;
    stack[-1] = v_10238;
// end of prologue
    goto v_10250;
v_10246:
    v_10272 = stack[-1];
    goto v_10247;
v_10248:
    v_10271 = stack[0];
    goto v_10249;
v_10250:
    goto v_10246;
v_10247:
    goto v_10248;
v_10249:
    fn = elt(env, 1); // ordp
    v_10271 = (*qfn2(fn))(fn, v_10272, v_10271);
    if (v_10271 == nil) goto v_10244;
    goto v_10258;
v_10254:
    v_10272 = stack[-1];
    goto v_10255;
v_10256:
    v_10271 = stack[0];
    goto v_10257;
v_10258:
    goto v_10254;
v_10255:
    goto v_10256;
v_10257:
    return list2(v_10272, v_10271);
v_10244:
    goto v_10268;
v_10264:
    v_10272 = stack[0];
    goto v_10265;
v_10266:
    v_10271 = stack[-1];
    goto v_10267;
v_10268:
    goto v_10264;
v_10265:
    goto v_10266;
v_10267:
    return list2(v_10272, v_10271);
    v_10271 = nil;
    return onevalue(v_10271);
}



// Code for general!-reduce!-degree!-mod!-p

static LispObject CC_generalKreduceKdegreeKmodKp(LispObject env,
                         LispObject v_10238, LispObject v_10239)
{
    env = qenv(env);
    LispObject v_10336, v_10337, v_10338;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10239,v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10238,v_10239);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10239;
    stack[-1] = v_10238;
// end of prologue
    goto v_10250;
v_10246:
    v_10336 = stack[-1];
    v_10336 = qcar(v_10336);
    v_10336 = qcdr(v_10336);
    fn = elt(env, 1); // general!-modular!-minus
    v_10337 = (*qfn1(fn))(fn, v_10336);
    env = stack[-3];
    goto v_10247;
v_10248:
    v_10336 = stack[0];
    v_10336 = qcar(v_10336);
    v_10336 = qcdr(v_10336);
    goto v_10249;
v_10250:
    goto v_10246;
v_10247:
    goto v_10248;
v_10249:
    fn = elt(env, 2); // general!-modular!-quotient
    v_10336 = (*qfn2(fn))(fn, v_10337, v_10336);
    env = stack[-3];
    stack[-2] = v_10336;
    goto v_10262;
v_10258:
    v_10336 = stack[-1];
    v_10336 = qcar(v_10336);
    v_10336 = qcar(v_10336);
    v_10337 = qcdr(v_10336);
    goto v_10259;
v_10260:
    v_10336 = stack[0];
    v_10336 = qcar(v_10336);
    v_10336 = qcar(v_10336);
    v_10336 = qcdr(v_10336);
    goto v_10261;
v_10262:
    goto v_10258;
v_10259:
    goto v_10260;
v_10261:
    v_10336 = (LispObject)(intptr_t)((intptr_t)v_10337 - (intptr_t)v_10336 + TAG_FIXNUM);
    v_10338 = v_10336;
    goto v_10280;
v_10276:
    v_10337 = v_10338;
    goto v_10277;
v_10278:
    v_10336 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10279;
v_10280:
    goto v_10276;
v_10277:
    goto v_10278;
v_10279:
    if (v_10337 == v_10336) goto v_10274;
    else goto v_10275;
v_10274:
    goto v_10288;
v_10284:
    v_10336 = stack[-1];
    stack[-1] = qcdr(v_10336);
    goto v_10285;
v_10286:
    goto v_10296;
v_10292:
    v_10336 = stack[0];
    v_10337 = qcdr(v_10336);
    goto v_10293;
v_10294:
    v_10336 = stack[-2];
    goto v_10295;
v_10296:
    goto v_10292;
v_10293:
    goto v_10294;
v_10295:
    fn = elt(env, 3); // general!-multiply!-by!-constant!-mod!-p
    v_10336 = (*qfn2(fn))(fn, v_10337, v_10336);
    env = stack[-3];
    goto v_10287;
v_10288:
    goto v_10284;
v_10285:
    goto v_10286;
v_10287:
    {
        LispObject v_10342 = stack[-1];
        fn = elt(env, 4); // general!-plus!-mod!-p
        return (*qfn2(fn))(fn, v_10342, v_10336);
    }
v_10275:
    goto v_10307;
v_10303:
    v_10336 = stack[-1];
    stack[-1] = qcdr(v_10336);
    goto v_10304;
v_10305:
    goto v_10315;
v_10311:
    goto v_10321;
v_10317:
    goto v_10327;
v_10323:
    v_10336 = stack[0];
    v_10336 = qcar(v_10336);
    v_10336 = qcar(v_10336);
    v_10336 = qcar(v_10336);
    goto v_10324;
v_10325:
    v_10337 = v_10338;
    goto v_10326;
v_10327:
    goto v_10323;
v_10324:
    goto v_10325;
v_10326:
    fn = elt(env, 5); // mksp
    v_10337 = (*qfn2(fn))(fn, v_10336, v_10337);
    env = stack[-3];
    goto v_10318;
v_10319:
    v_10336 = stack[-2];
    goto v_10320;
v_10321:
    goto v_10317;
v_10318:
    goto v_10319;
v_10320:
    v_10337 = cons(v_10337, v_10336);
    env = stack[-3];
    goto v_10312;
v_10313:
    v_10336 = stack[0];
    v_10336 = qcdr(v_10336);
    goto v_10314;
v_10315:
    goto v_10311;
v_10312:
    goto v_10313;
v_10314:
    fn = elt(env, 6); // general!-times!-term!-mod!-p
    v_10336 = (*qfn2(fn))(fn, v_10337, v_10336);
    env = stack[-3];
    goto v_10306;
v_10307:
    goto v_10303;
v_10304:
    goto v_10305;
v_10306:
    {
        LispObject v_10343 = stack[-1];
        fn = elt(env, 4); // general!-plus!-mod!-p
        return (*qfn2(fn))(fn, v_10343, v_10336);
    }
    v_10336 = nil;
    return onevalue(v_10336);
}



// Code for simpiden

static LispObject CC_simpiden(LispObject env,
                         LispObject v_10238)
{
    env = qenv(env);
    LispObject v_10745, v_10746, v_10747;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10238);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[0] = v_10238;
// end of prologue
    stack[-5] = nil;
    stack[-4] = nil;
    v_10745 = stack[0];
    v_10745 = qcar(v_10745);
    stack[-7] = v_10745;
    v_10745 = stack[0];
    v_10745 = qcdr(v_10745);
    stack[0] = v_10745;
    goto v_10262;
v_10258:
    v_10746 = stack[-7];
    goto v_10259;
v_10260:
    v_10745 = stack[0];
    goto v_10261;
v_10262:
    goto v_10258;
v_10259:
    goto v_10260;
v_10261:
    fn = elt(env, 12); // valuechk
    v_10745 = (*qfn2(fn))(fn, v_10746, v_10745);
    env = stack[-8];
    stack[-6] = v_10745;
    if (v_10745 == nil) goto v_10256;
    v_10745 = stack[-6];
    goto v_10247;
v_10256:
    v_10745 = stack[0];
    if (v_10745 == nil) goto v_10273;
    goto v_10280;
v_10276:
    v_10745 = stack[0];
    v_10746 = qcar(v_10745);
    goto v_10277;
v_10278:
    v_10745 = elt(env, 1); // list
    goto v_10279;
v_10280:
    goto v_10276;
v_10277:
    goto v_10278;
v_10279:
    v_10745 = Leqcar(nil, v_10746, v_10745);
    env = stack[-8];
    goto v_10271;
v_10273:
    v_10745 = nil;
    goto v_10271;
    v_10745 = nil;
v_10271:
    if (v_10745 == nil) goto v_10269;
    goto v_10292;
v_10288:
    goto v_10298;
v_10294:
    stack[-1] = stack[-7];
    goto v_10295;
v_10296:
    v_10745 = stack[0];
    v_10745 = qcar(v_10745);
    fn = elt(env, 13); // aeval
    v_10745 = (*qfn1(fn))(fn, v_10745);
    env = stack[-8];
    goto v_10297;
v_10298:
    goto v_10294;
v_10295:
    goto v_10296;
v_10297:
    v_10746 = list2(stack[-1], v_10745);
    env = stack[-8];
    goto v_10289;
v_10290:
    v_10745 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10291;
v_10292:
    goto v_10288;
v_10289:
    goto v_10290;
v_10291:
    {
        fn = elt(env, 14); // mksq
        return (*qfn2(fn))(fn, v_10746, v_10745);
    }
v_10269:
    goto v_10311;
v_10305:
    v_10746 = stack[0];
    goto v_10306;
v_10307:
    goto v_10318;
v_10314:
    v_10747 = stack[-7];
    goto v_10315;
v_10316:
    v_10745 = elt(env, 2); // nosimp
    goto v_10317;
v_10318:
    goto v_10314;
v_10315:
    goto v_10316;
v_10317:
    v_10747 = get(v_10747, v_10745);
    env = stack[-8];
    goto v_10308;
v_10309:
    v_10745 = nil;
    goto v_10310;
v_10311:
    goto v_10305;
v_10306:
    goto v_10307;
v_10308:
    goto v_10309;
v_10310:
    fn = elt(env, 15); // fnreval
    v_10745 = (*qfnn(fn))(fn, 3, v_10746, v_10747, v_10745);
    env = stack[-8];
    stack[-6] = v_10745;
    v_10745 = stack[-6];
    stack[-3] = v_10745;
    v_10745 = stack[-3];
    if (v_10745 == nil) goto v_10331;
    else goto v_10332;
v_10331:
    v_10745 = nil;
    goto v_10326;
v_10332:
    v_10745 = stack[-3];
    v_10745 = qcar(v_10745);
    v_10747 = v_10745;
    goto v_10348;
v_10344:
    v_10746 = v_10747;
    goto v_10345;
v_10346:
    v_10745 = elt(env, 3); // !*sq
    goto v_10347;
v_10348:
    goto v_10344;
v_10345:
    goto v_10346;
v_10347:
    if (!consp(v_10746)) goto v_10342;
    v_10746 = qcar(v_10746);
    if (v_10746 == v_10745) goto v_10341;
    else goto v_10342;
v_10341:
    v_10745 = v_10747;
    v_10745 = qcdr(v_10745);
    v_10745 = qcar(v_10745);
    fn = elt(env, 16); // prepsqxx
    v_10745 = (*qfn1(fn))(fn, v_10745);
    env = stack[-8];
    goto v_10340;
v_10342:
    v_10745 = v_10747;
    if (is_number(v_10745)) goto v_10355;
    else goto v_10356;
v_10355:
    v_10745 = v_10747;
    goto v_10340;
v_10356:
    v_10745 = v_10747;
    goto v_10340;
    v_10745 = nil;
v_10340:
    v_10745 = ncons(v_10745);
    env = stack[-8];
    stack[-1] = v_10745;
    stack[-2] = v_10745;
v_10327:
    v_10745 = stack[-3];
    v_10745 = qcdr(v_10745);
    stack[-3] = v_10745;
    v_10745 = stack[-3];
    if (v_10745 == nil) goto v_10367;
    else goto v_10368;
v_10367:
    v_10745 = stack[-2];
    goto v_10326;
v_10368:
    goto v_10376;
v_10372:
    stack[0] = stack[-1];
    goto v_10373;
v_10374:
    v_10745 = stack[-3];
    v_10745 = qcar(v_10745);
    v_10747 = v_10745;
    goto v_10391;
v_10387:
    v_10746 = v_10747;
    goto v_10388;
v_10389:
    v_10745 = elt(env, 3); // !*sq
    goto v_10390;
v_10391:
    goto v_10387;
v_10388:
    goto v_10389;
v_10390:
    if (!consp(v_10746)) goto v_10385;
    v_10746 = qcar(v_10746);
    if (v_10746 == v_10745) goto v_10384;
    else goto v_10385;
v_10384:
    v_10745 = v_10747;
    v_10745 = qcdr(v_10745);
    v_10745 = qcar(v_10745);
    fn = elt(env, 16); // prepsqxx
    v_10745 = (*qfn1(fn))(fn, v_10745);
    env = stack[-8];
    goto v_10383;
v_10385:
    v_10745 = v_10747;
    if (is_number(v_10745)) goto v_10398;
    else goto v_10399;
v_10398:
    v_10745 = v_10747;
    goto v_10383;
v_10399:
    v_10745 = v_10747;
    goto v_10383;
    v_10745 = nil;
v_10383:
    v_10745 = ncons(v_10745);
    env = stack[-8];
    goto v_10375;
v_10376:
    goto v_10372;
v_10373:
    goto v_10374;
v_10375:
    v_10745 = Lrplacd(nil, stack[0], v_10745);
    env = stack[-8];
    v_10745 = stack[-1];
    v_10745 = qcdr(v_10745);
    stack[-1] = v_10745;
    goto v_10327;
v_10326:
    stack[0] = v_10745;
    v_10745 = stack[0];
    if (v_10745 == nil) goto v_10411;
    goto v_10423;
v_10419:
    v_10745 = stack[0];
    v_10746 = qcar(v_10745);
    goto v_10420;
v_10421:
    v_10745 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10422;
v_10423:
    goto v_10419;
v_10420:
    goto v_10421;
v_10422:
    if (v_10746 == v_10745) goto v_10417;
    else goto v_10418;
v_10417:
    goto v_10436;
v_10432:
    v_10746 = stack[-7];
    goto v_10433;
v_10434:
    v_10745 = elt(env, 4); // odd
    goto v_10435;
v_10436:
    goto v_10432;
v_10433:
    goto v_10434;
v_10435:
    v_10745 = Lflagp(nil, v_10746, v_10745);
    env = stack[-8];
    if (v_10745 == nil) goto v_10430;
    goto v_10444;
v_10440:
    v_10746 = stack[-7];
    goto v_10441;
v_10442:
    v_10745 = elt(env, 5); // nonzero
    goto v_10443;
v_10444:
    goto v_10440;
v_10441:
    goto v_10442;
v_10443:
    v_10745 = Lflagp(nil, v_10746, v_10745);
    env = stack[-8];
    v_10745 = (v_10745 == nil ? lisp_true : nil);
    goto v_10428;
v_10430:
    v_10745 = nil;
    goto v_10428;
    v_10745 = nil;
v_10428:
    goto v_10416;
v_10418:
    v_10745 = nil;
    goto v_10416;
    v_10745 = nil;
v_10416:
    if (v_10745 == nil) goto v_10411;
    goto v_10459;
v_10455:
    v_10746 = nil;
    goto v_10456;
v_10457:
    v_10745 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10458;
v_10459:
    goto v_10455;
v_10456:
    goto v_10457;
v_10458:
    return cons(v_10746, v_10745);
v_10411:
    goto v_10467;
v_10463:
    v_10746 = stack[-7];
    goto v_10464;
v_10465:
    v_10745 = stack[0];
    goto v_10466;
v_10467:
    goto v_10463;
v_10464:
    goto v_10465;
v_10466:
    v_10745 = cons(v_10746, v_10745);
    env = stack[-8];
    stack[0] = v_10745;
    v_10745 = stack[-7];
    if (!symbolp(v_10745)) v_10745 = nil;
    else { v_10745 = qfastgets(v_10745);
           if (v_10745 != nil) { v_10745 = elt(v_10745, 0); // noncom
#ifdef RECORD_GET
             if (v_10745 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_10745 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_10745 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_10745 == SPID_NOPROP) v_10745 = nil; else v_10745 = lisp_true; }}
#endif
    if (v_10745 == nil) goto v_10473;
    v_10745 = lisp_true;
    qvalue(elt(env, 6)) = v_10745; // ncmp!*
    goto v_10471;
v_10473:
v_10471:
    v_10745 = qvalue(elt(env, 7)); // subfg!*
    if (v_10745 == nil) goto v_10479;
    else goto v_10480;
v_10479:
    goto v_10248;
v_10480:
    goto v_10493;
v_10489:
    v_10746 = stack[-7];
    goto v_10490;
v_10491:
    v_10745 = elt(env, 8); // linear
    goto v_10492;
v_10493:
    goto v_10489;
v_10490:
    goto v_10491;
v_10492:
    v_10745 = Lflagp(nil, v_10746, v_10745);
    env = stack[-8];
    if (v_10745 == nil) goto v_10487;
    goto v_10501;
v_10497:
    v_10745 = stack[0];
    fn = elt(env, 17); // formlnr
    v_10746 = (*qfn1(fn))(fn, v_10745);
    env = stack[-8];
    stack[-4] = v_10746;
    goto v_10498;
v_10499:
    v_10745 = stack[0];
    goto v_10500;
v_10501:
    goto v_10497;
v_10498:
    goto v_10499;
v_10500:
    v_10745 = Lneq(nil, v_10746, v_10745);
    env = stack[-8];
    goto v_10485;
v_10487:
    v_10745 = nil;
    goto v_10485;
    v_10745 = nil;
v_10485:
    if (v_10745 == nil) goto v_10483;
    v_10745 = stack[-4];
    {
        fn = elt(env, 18); // simp
        return (*qfn1(fn))(fn, v_10745);
    }
v_10483:
    v_10745 = stack[0];
    fn = elt(env, 19); // opmtch
    v_10745 = (*qfn1(fn))(fn, v_10745);
    env = stack[-8];
    stack[-4] = v_10745;
    if (v_10745 == nil) goto v_10511;
    v_10745 = stack[-4];
    {
        fn = elt(env, 18); // simp
        return (*qfn1(fn))(fn, v_10745);
    }
v_10511:
    goto v_10523;
v_10519:
    v_10745 = stack[0];
    v_10746 = qcar(v_10745);
    goto v_10520;
v_10521:
    v_10745 = elt(env, 9); // opvalfn
    goto v_10522;
v_10523:
    goto v_10519;
v_10520:
    goto v_10521;
v_10522:
    v_10745 = get(v_10746, v_10745);
    env = stack[-8];
    stack[-4] = v_10745;
    if (v_10745 == nil) goto v_10517;
    goto v_10532;
v_10528:
    v_10746 = stack[-4];
    goto v_10529;
v_10530:
    v_10745 = stack[0];
    goto v_10531;
v_10532:
    goto v_10528;
v_10529:
    goto v_10530;
v_10531:
        return Lapply1(nil, v_10746, v_10745);
v_10517:
v_10248:
    v_10745 = stack[-7];
    if (!symbolp(v_10745)) v_10745 = nil;
    else { v_10745 = qfastgets(v_10745);
           if (v_10745 != nil) { v_10745 = elt(v_10745, 43); // symmetric
#ifdef RECORD_GET
             if (v_10745 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v_10745 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v_10745 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v_10745 == SPID_NOPROP) v_10745 = nil; else v_10745 = lisp_true; }}
#endif
    if (v_10745 == nil) goto v_10538;
    goto v_10546;
v_10542:
    stack[-1] = stack[-7];
    goto v_10543;
v_10544:
    v_10745 = stack[0];
    v_10745 = qcdr(v_10745);
    fn = elt(env, 20); // ordn
    v_10745 = (*qfn1(fn))(fn, v_10745);
    env = stack[-8];
    goto v_10545;
v_10546:
    goto v_10542;
v_10543:
    goto v_10544;
v_10545:
    v_10745 = cons(stack[-1], v_10745);
    env = stack[-8];
    stack[0] = v_10745;
    goto v_10536;
v_10538:
    goto v_10558;
v_10554:
    v_10746 = stack[-7];
    goto v_10555;
v_10556:
    v_10745 = elt(env, 10); // antisymmetric
    goto v_10557;
v_10558:
    goto v_10554;
v_10555:
    goto v_10556;
v_10557:
    v_10745 = Lflagp(nil, v_10746, v_10745);
    env = stack[-8];
    if (v_10745 == nil) goto v_10552;
    v_10745 = stack[0];
    v_10745 = qcdr(v_10745);
    fn = elt(env, 21); // repeats
    v_10745 = (*qfn1(fn))(fn, v_10745);
    env = stack[-8];
    if (v_10745 == nil) goto v_10564;
    goto v_10573;
v_10569:
    v_10746 = nil;
    goto v_10570;
v_10571:
    v_10745 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10572;
v_10573:
    goto v_10569;
v_10570:
    goto v_10571;
v_10572:
    return cons(v_10746, v_10745);
v_10564:
    goto v_10583;
v_10579:
    v_10745 = stack[0];
    v_10745 = qcdr(v_10745);
    fn = elt(env, 20); // ordn
    v_10746 = (*qfn1(fn))(fn, v_10745);
    env = stack[-8];
    stack[-4] = v_10746;
    goto v_10580;
v_10581:
    v_10745 = stack[0];
    v_10745 = qcdr(v_10745);
    goto v_10582;
v_10583:
    goto v_10579;
v_10580:
    goto v_10581;
v_10582:
    fn = elt(env, 22); // permp
    v_10745 = (*qfn2(fn))(fn, v_10746, v_10745);
    env = stack[-8];
    if (v_10745 == nil) goto v_10576;
    else goto v_10577;
v_10576:
    v_10745 = lisp_true;
    stack[-5] = v_10745;
    goto v_10562;
v_10577:
v_10562:
    goto v_10595;
v_10591:
    v_10745 = stack[0];
    v_10746 = qcar(v_10745);
    goto v_10592;
v_10593:
    v_10745 = stack[-4];
    goto v_10594;
v_10595:
    goto v_10591;
v_10592:
    goto v_10593;
v_10594:
    v_10745 = cons(v_10746, v_10745);
    env = stack[-8];
    stack[-7] = v_10745;
    goto v_10611;
v_10607:
    v_10746 = stack[-4];
    goto v_10608;
v_10609:
    v_10745 = stack[0];
    v_10745 = qcdr(v_10745);
    goto v_10610;
v_10611:
    goto v_10607;
v_10608:
    goto v_10609;
v_10610:
    if (equal(v_10746, v_10745)) goto v_10606;
    v_10745 = stack[-7];
    fn = elt(env, 19); // opmtch
    v_10745 = (*qfn1(fn))(fn, v_10745);
    env = stack[-8];
    stack[-4] = v_10745;
    goto v_10604;
v_10606:
    v_10745 = nil;
    goto v_10604;
    v_10745 = nil;
v_10604:
    if (v_10745 == nil) goto v_10602;
    v_10745 = stack[-5];
    if (v_10745 == nil) goto v_10623;
    v_10745 = stack[-4];
    fn = elt(env, 18); // simp
    v_10745 = (*qfn1(fn))(fn, v_10745);
    env = stack[-8];
    {
        fn = elt(env, 23); // negsq
        return (*qfn1(fn))(fn, v_10745);
    }
v_10623:
    v_10745 = stack[-4];
    {
        fn = elt(env, 18); // simp
        return (*qfn1(fn))(fn, v_10745);
    }
    v_10745 = nil;
    goto v_10247;
v_10602:
    v_10745 = stack[-7];
    stack[0] = v_10745;
    goto v_10536;
v_10552:
v_10536:
    goto v_10650;
v_10646:
    v_10746 = stack[-7];
    goto v_10647;
v_10648:
    v_10745 = elt(env, 11); // even
    goto v_10649;
v_10650:
    goto v_10646;
v_10647:
    goto v_10648;
v_10649:
    v_10745 = Lflagp(nil, v_10746, v_10745);
    env = stack[-8];
    if (v_10745 == nil) goto v_10644;
    v_10745 = lisp_true;
    goto v_10642;
v_10644:
    goto v_10661;
v_10657:
    v_10746 = stack[-7];
    goto v_10658;
v_10659:
    v_10745 = elt(env, 4); // odd
    goto v_10660;
v_10661:
    goto v_10657;
v_10658:
    goto v_10659;
v_10660:
    v_10745 = Lflagp(nil, v_10746, v_10745);
    env = stack[-8];
    goto v_10642;
    v_10745 = nil;
v_10642:
    if (v_10745 == nil) goto v_10640;
    v_10745 = stack[-6];
    if (v_10745 == nil) goto v_10666;
    else goto v_10667;
v_10666:
    v_10745 = nil;
    goto v_10665;
v_10667:
    v_10745 = stack[-6];
    v_10745 = qcar(v_10745);
    fn = elt(env, 18); // simp
    v_10745 = (*qfn1(fn))(fn, v_10745);
    env = stack[-8];
    stack[-6] = v_10745;
    v_10745 = qcar(v_10745);
    fn = elt(env, 24); // minusf
    v_10745 = (*qfn1(fn))(fn, v_10745);
    env = stack[-8];
    goto v_10665;
    v_10745 = nil;
v_10665:
    goto v_10638;
v_10640:
    v_10745 = nil;
    goto v_10638;
    v_10745 = nil;
v_10638:
    if (v_10745 == nil) goto v_10636;
    goto v_10689;
v_10685:
    v_10746 = stack[-7];
    goto v_10686;
v_10687:
    v_10745 = elt(env, 4); // odd
    goto v_10688;
v_10689:
    goto v_10685;
v_10686:
    goto v_10687;
v_10688:
    v_10745 = Lflagp(nil, v_10746, v_10745);
    env = stack[-8];
    if (v_10745 == nil) goto v_10683;
    v_10745 = stack[-5];
    v_10745 = (v_10745 == nil ? lisp_true : nil);
    stack[-5] = v_10745;
    goto v_10681;
v_10683:
v_10681:
    goto v_10701;
v_10695:
    stack[-1] = stack[-7];
    goto v_10696;
v_10697:
    v_10745 = stack[-6];
    fn = elt(env, 23); // negsq
    v_10745 = (*qfn1(fn))(fn, v_10745);
    env = stack[-8];
    fn = elt(env, 16); // prepsqxx
    v_10746 = (*qfn1(fn))(fn, v_10745);
    env = stack[-8];
    goto v_10698;
v_10699:
    v_10745 = stack[0];
    v_10745 = qcdr(v_10745);
    v_10745 = qcdr(v_10745);
    goto v_10700;
v_10701:
    goto v_10695;
v_10696:
    goto v_10697;
v_10698:
    goto v_10699;
v_10700:
    v_10745 = list2star(stack[-1], v_10746, v_10745);
    env = stack[-8];
    stack[0] = v_10745;
    v_10745 = stack[0];
    fn = elt(env, 19); // opmtch
    v_10745 = (*qfn1(fn))(fn, v_10745);
    env = stack[-8];
    stack[-4] = v_10745;
    if (v_10745 == nil) goto v_10712;
    v_10745 = stack[-5];
    if (v_10745 == nil) goto v_10718;
    v_10745 = stack[-4];
    fn = elt(env, 18); // simp
    v_10745 = (*qfn1(fn))(fn, v_10745);
    env = stack[-8];
    {
        fn = elt(env, 23); // negsq
        return (*qfn1(fn))(fn, v_10745);
    }
v_10718:
    v_10745 = stack[-4];
    {
        fn = elt(env, 18); // simp
        return (*qfn1(fn))(fn, v_10745);
    }
    v_10745 = nil;
    goto v_10247;
v_10712:
    goto v_10634;
v_10636:
v_10634:
    goto v_10732;
v_10728:
    v_10746 = stack[0];
    goto v_10729;
v_10730:
    v_10745 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10731;
v_10732:
    goto v_10728;
v_10729:
    goto v_10730;
v_10731:
    fn = elt(env, 14); // mksq
    v_10745 = (*qfn2(fn))(fn, v_10746, v_10745);
    env = stack[-8];
    stack[0] = v_10745;
    v_10745 = stack[-5];
    if (v_10745 == nil) goto v_10738;
    v_10745 = stack[0];
    {
        fn = elt(env, 23); // negsq
        return (*qfn1(fn))(fn, v_10745);
    }
v_10738:
    v_10745 = stack[0];
    goto v_10736;
    v_10745 = nil;
v_10736:
v_10247:
    return onevalue(v_10745);
}



// Code for lexer_word_starter

static LispObject CC_lexer_word_starter(LispObject env,
                         LispObject v_10238)
{
    env = qenv(env);
    LispObject v_10331, v_10332;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10238);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10238;
// end of prologue
    v_10331 = stack[0];
    v_10331 = Lalpha_char_p(nil, v_10331);
    env = stack[-1];
    if (v_10331 == nil) goto v_10242;
    else goto v_10241;
v_10242:
    goto v_10257;
v_10253:
    v_10332 = stack[0];
    goto v_10254;
v_10255:
    v_10331 = elt(env, 1); // !_
    goto v_10256;
v_10257:
    goto v_10253;
v_10254:
    goto v_10255;
v_10256:
    if (v_10332 == v_10331) goto v_10251;
    else goto v_10252;
v_10251:
    goto v_10266;
v_10262:
    v_10332 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_10263;
v_10264:
    v_10331 = (LispObject)32768+TAG_FIXNUM; // 2048
    goto v_10265;
v_10266:
    goto v_10262;
v_10263:
    goto v_10264;
v_10265:
    fn = elt(env, 5); // land
    v_10331 = (*qfn2(fn))(fn, v_10332, v_10331);
    env = stack[-1];
    v_10331 = (LispObject)zerop(v_10331);
    v_10331 = v_10331 ? lisp_true : nil;
    env = stack[-1];
    v_10331 = (v_10331 == nil ? lisp_true : nil);
    goto v_10250;
v_10252:
    v_10331 = nil;
    goto v_10250;
    v_10331 = nil;
v_10250:
    if (v_10331 == nil) goto v_10248;
    v_10331 = lisp_true;
    goto v_10246;
v_10248:
    goto v_10288;
v_10284:
    v_10332 = stack[0];
    goto v_10285;
v_10286:
    v_10331 = elt(env, 3); // !'
    goto v_10287;
v_10288:
    goto v_10284;
v_10285:
    goto v_10286;
v_10287:
    if (v_10332 == v_10331) goto v_10282;
    else goto v_10283;
v_10282:
    goto v_10297;
v_10293:
    v_10332 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_10294;
v_10295:
    v_10331 = (LispObject)131072+TAG_FIXNUM; // 8192
    goto v_10296;
v_10297:
    goto v_10293;
v_10294:
    goto v_10295;
v_10296:
    fn = elt(env, 5); // land
    v_10331 = (*qfn2(fn))(fn, v_10332, v_10331);
    env = stack[-1];
    v_10331 = (LispObject)zerop(v_10331);
    v_10331 = v_10331 ? lisp_true : nil;
    env = stack[-1];
    v_10331 = (v_10331 == nil ? lisp_true : nil);
    goto v_10281;
v_10283:
    v_10331 = nil;
    goto v_10281;
    v_10331 = nil;
v_10281:
    if (v_10331 == nil) goto v_10279;
    v_10331 = lisp_true;
    goto v_10277;
v_10279:
    goto v_10315;
v_10311:
    v_10332 = stack[0];
    goto v_10312;
v_10313:
    v_10331 = elt(env, 4); // !\ (backslash)
    goto v_10314;
v_10315:
    goto v_10311;
v_10312:
    goto v_10313;
v_10314:
    if (v_10332 == v_10331) goto v_10309;
    else goto v_10310;
v_10309:
    goto v_10324;
v_10320:
    v_10332 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_10321;
v_10322:
    v_10331 = (LispObject)65536+TAG_FIXNUM; // 4096
    goto v_10323;
v_10324:
    goto v_10320;
v_10321:
    goto v_10322;
v_10323:
    fn = elt(env, 5); // land
    v_10331 = (*qfn2(fn))(fn, v_10332, v_10331);
    env = stack[-1];
    v_10331 = (LispObject)zerop(v_10331);
    v_10331 = v_10331 ? lisp_true : nil;
    v_10331 = (v_10331 == nil ? lisp_true : nil);
    goto v_10308;
v_10310:
    v_10331 = nil;
    goto v_10308;
    v_10331 = nil;
v_10308:
    goto v_10277;
    v_10331 = nil;
v_10277:
    goto v_10246;
    v_10331 = nil;
v_10246:
v_10241:
    return onevalue(v_10331);
}



// Code for gcref_select

static LispObject CC_gcref_select(LispObject env,
                         LispObject v_10238)
{
    env = qenv(env);
    LispObject v_10346, v_10347, v_10348;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10238);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_10346 = v_10238;
// end of prologue
    stack[-3] = v_10346;
v_10245:
    v_10346 = stack[-3];
    if (v_10346 == nil) goto v_10250;
    else goto v_10251;
v_10250:
    v_10346 = nil;
    goto v_10244;
v_10251:
    v_10346 = stack[-3];
    v_10346 = qcar(v_10346);
    v_10348 = v_10346;
    goto v_10270;
v_10266:
    v_10347 = v_10348;
    goto v_10267;
v_10268:
    v_10346 = elt(env, 1); // defd
    goto v_10269;
v_10270:
    goto v_10266;
v_10267:
    goto v_10268;
v_10269:
    v_10346 = Lflagp(nil, v_10347, v_10346);
    env = stack[-4];
    if (v_10346 == nil) goto v_10264;
    goto v_10277;
v_10273:
    v_10347 = v_10348;
    goto v_10274;
v_10275:
    v_10346 = qvalue(elt(env, 2)); // gcref_nolist!*
    goto v_10276;
v_10277:
    goto v_10273;
v_10274:
    goto v_10275;
v_10276:
    v_10346 = Lmemq(nil, v_10347, v_10346);
    v_10346 = (v_10346 == nil ? lisp_true : nil);
    goto v_10262;
v_10264:
    v_10346 = nil;
    goto v_10262;
    v_10346 = nil;
v_10262:
    if (v_10346 == nil) goto v_10260;
    v_10346 = v_10348;
    v_10346 = ncons(v_10346);
    env = stack[-4];
    goto v_10258;
v_10260:
    v_10346 = nil;
v_10258:
    stack[-2] = v_10346;
    v_10346 = stack[-2];
    fn = elt(env, 3); // lastpair
    v_10346 = (*qfn1(fn))(fn, v_10346);
    env = stack[-4];
    stack[-1] = v_10346;
    v_10346 = stack[-3];
    v_10346 = qcdr(v_10346);
    stack[-3] = v_10346;
    v_10346 = stack[-1];
    if (!consp(v_10346)) goto v_10293;
    else goto v_10294;
v_10293:
    goto v_10245;
v_10294:
v_10246:
    v_10346 = stack[-3];
    if (v_10346 == nil) goto v_10298;
    else goto v_10299;
v_10298:
    v_10346 = stack[-2];
    goto v_10244;
v_10299:
    goto v_10307;
v_10303:
    stack[0] = stack[-1];
    goto v_10304;
v_10305:
    v_10346 = stack[-3];
    v_10346 = qcar(v_10346);
    v_10348 = v_10346;
    goto v_10325;
v_10321:
    v_10347 = v_10348;
    goto v_10322;
v_10323:
    v_10346 = elt(env, 1); // defd
    goto v_10324;
v_10325:
    goto v_10321;
v_10322:
    goto v_10323;
v_10324:
    v_10346 = Lflagp(nil, v_10347, v_10346);
    env = stack[-4];
    if (v_10346 == nil) goto v_10319;
    goto v_10332;
v_10328:
    v_10347 = v_10348;
    goto v_10329;
v_10330:
    v_10346 = qvalue(elt(env, 2)); // gcref_nolist!*
    goto v_10331;
v_10332:
    goto v_10328;
v_10329:
    goto v_10330;
v_10331:
    v_10346 = Lmemq(nil, v_10347, v_10346);
    v_10346 = (v_10346 == nil ? lisp_true : nil);
    goto v_10317;
v_10319:
    v_10346 = nil;
    goto v_10317;
    v_10346 = nil;
v_10317:
    if (v_10346 == nil) goto v_10315;
    v_10346 = v_10348;
    v_10346 = ncons(v_10346);
    env = stack[-4];
    goto v_10313;
v_10315:
    v_10346 = nil;
v_10313:
    goto v_10306;
v_10307:
    goto v_10303;
v_10304:
    goto v_10305;
v_10306:
    v_10346 = Lrplacd(nil, stack[0], v_10346);
    env = stack[-4];
    v_10346 = stack[-1];
    fn = elt(env, 3); // lastpair
    v_10346 = (*qfn1(fn))(fn, v_10346);
    env = stack[-4];
    stack[-1] = v_10346;
    v_10346 = stack[-3];
    v_10346 = qcdr(v_10346);
    stack[-3] = v_10346;
    goto v_10246;
v_10244:
    return onevalue(v_10346);
}



// Code for mksq

static LispObject CC_mksq(LispObject env,
                         LispObject v_10238, LispObject v_10239)
{
    env = qenv(env);
    LispObject v_10567, v_10568;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10239,v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10238,v_10239);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_10239;
    stack[-4] = v_10238;
// end of prologue
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v_10567 = qvalue(elt(env, 1)); // subfg!*
    if (v_10567 == nil) goto v_10252;
    else goto v_10253;
v_10252:
    goto v_10247;
v_10253:
    goto v_10262;
v_10258:
    v_10568 = stack[-4];
    goto v_10259;
v_10260:
    v_10567 = qvalue(elt(env, 2)); // wtl!*
    goto v_10261;
v_10262:
    goto v_10258;
v_10259:
    goto v_10260;
v_10261:
    v_10567 = Lassoc(nil, v_10568, v_10567);
    stack[-2] = v_10567;
    if (v_10567 == nil) goto v_10256;
    goto v_10272;
v_10268:
    stack[0] = elt(env, 3); // k!*
    goto v_10269;
v_10270:
    goto v_10279;
v_10275:
    v_10568 = stack[-3];
    goto v_10276;
v_10277:
    v_10567 = stack[-2];
    v_10567 = qcdr(v_10567);
    goto v_10278;
v_10279:
    goto v_10275;
v_10276:
    goto v_10277;
v_10278:
    v_10567 = times2(v_10568, v_10567);
    env = stack[-6];
    goto v_10271;
v_10272:
    goto v_10268;
v_10269:
    goto v_10270;
v_10271:
    v_10567 = CC_mksq(elt(env, 0), stack[0], v_10567);
    env = stack[-6];
    stack[-2] = v_10567;
    v_10567 = qcar(v_10567);
    if (v_10567 == nil) goto v_10266;
    else goto v_10256;
v_10266:
    v_10567 = stack[-2];
    goto v_10245;
v_10256:
    v_10567 = stack[-4];
    if (!consp(v_10567)) goto v_10286;
    goto v_10248;
v_10286:
    v_10567 = qvalue(elt(env, 4)); // !*nosubs
    if (v_10567 == nil) goto v_10292;
    else goto v_10293;
v_10292:
    v_10567 = stack[-4];
    if (!symbolp(v_10567)) v_10567 = nil;
    else { v_10567 = qfastgets(v_10567);
           if (v_10567 != nil) { v_10567 = elt(v_10567, 4); // avalue
#ifdef RECORD_GET
             if (v_10567 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_10567 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_10567 == SPID_NOPROP) v_10567 = nil; }}
#endif
    stack[-1] = v_10567;
    goto v_10291;
v_10293:
    v_10567 = nil;
    goto v_10291;
    v_10567 = nil;
v_10291:
    if (v_10567 == nil) goto v_10289;
    goto v_10249;
v_10289:
    v_10567 = stack[-4];
    if (symbolp(v_10567)) goto v_10302;
    else goto v_10303;
v_10302:
    goto v_10310;
v_10306:
    v_10567 = stack[-4];
    v_10568 = ncons(v_10567);
    env = stack[-6];
    goto v_10307;
v_10308:
    v_10567 = elt(env, 5); // used!*
    goto v_10309;
v_10310:
    goto v_10306;
v_10307:
    goto v_10308;
v_10309:
    v_10567 = Lflag(nil, v_10568, v_10567);
    env = stack[-6];
    goto v_10301;
v_10303:
v_10301:
v_10246:
    v_10567 = qvalue(elt(env, 4)); // !*nosubs
    if (v_10567 == nil) goto v_10318;
    else goto v_10316;
v_10318:
    goto v_10325;
v_10321:
    v_10568 = stack[-3];
    goto v_10322;
v_10323:
    v_10567 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10324;
v_10325:
    goto v_10321;
v_10322:
    goto v_10323;
v_10324:
    if (v_10568 == v_10567) goto v_10316;
    goto v_10317;
v_10316:
    goto v_10247;
v_10317:
    goto v_10335;
v_10331:
    v_10568 = stack[-4];
    goto v_10332;
v_10333:
    v_10567 = qvalue(elt(env, 6)); // asymplis!*
    goto v_10334;
v_10335:
    goto v_10331;
v_10332:
    goto v_10333;
v_10334:
    v_10567 = Lassoc(nil, v_10568, v_10567);
    stack[-1] = v_10567;
    if (v_10567 == nil) goto v_10329;
    goto v_10345;
v_10341:
    v_10567 = stack[-1];
    v_10568 = qcdr(v_10567);
    goto v_10342;
v_10343:
    v_10567 = stack[-3];
    goto v_10344;
v_10345:
    goto v_10341;
v_10342:
    goto v_10343;
v_10344:
    v_10567 = (LispObject)lesseq2(v_10568, v_10567);
    v_10567 = v_10567 ? lisp_true : nil;
    env = stack[-6];
    if (v_10567 == nil) goto v_10329;
    goto v_10354;
v_10350:
    v_10568 = nil;
    goto v_10351;
v_10352:
    v_10567 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10353;
v_10354:
    goto v_10350;
v_10351:
    goto v_10352;
v_10353:
    return cons(v_10568, v_10567);
v_10329:
    goto v_10365;
v_10361:
    v_10568 = stack[-4];
    goto v_10362;
v_10363:
    v_10567 = qvalue(elt(env, 7)); // powlis!*
    goto v_10364;
v_10365:
    goto v_10361;
v_10362:
    goto v_10363;
v_10364:
    v_10567 = Lassoc(nil, v_10568, v_10567);
    stack[-1] = v_10567;
    if (v_10567 == nil) goto v_10360;
    else goto v_10359;
v_10360:
    v_10567 = stack[-4];
    if (!consp(v_10567)) goto v_10373;
    goto v_10383;
v_10379:
    v_10567 = stack[-4];
    v_10568 = qcar(v_10567);
    goto v_10380;
v_10381:
    v_10567 = elt(env, 8); // (expt sqrt)
    goto v_10382;
v_10383:
    goto v_10379;
v_10380:
    goto v_10381;
v_10382:
    v_10567 = Lmemq(nil, v_10568, v_10567);
    if (v_10567 == nil) goto v_10377;
    else goto v_10378;
v_10377:
    v_10567 = nil;
    goto v_10376;
v_10378:
    goto v_10395;
v_10391:
    v_10567 = stack[-4];
    v_10567 = qcdr(v_10567);
    v_10568 = qcar(v_10567);
    goto v_10392;
v_10393:
    v_10567 = qvalue(elt(env, 7)); // powlis!*
    goto v_10394;
v_10395:
    goto v_10391;
v_10392:
    goto v_10393;
v_10394:
    v_10567 = Lassoc(nil, v_10568, v_10567);
    stack[-1] = v_10567;
    goto v_10376;
    v_10567 = nil;
v_10376:
    goto v_10371;
v_10373:
    v_10567 = nil;
    goto v_10371;
    v_10567 = nil;
v_10371:
    if (v_10567 == nil) goto v_10369;
    else goto v_10359;
v_10369:
    goto v_10358;
v_10359:
    goto v_10410;
v_10406:
    goto v_10416;
v_10412:
    v_10568 = stack[-3];
    goto v_10413;
v_10414:
    v_10567 = stack[-1];
    v_10567 = qcdr(v_10567);
    v_10567 = qcar(v_10567);
    goto v_10415;
v_10416:
    goto v_10412;
v_10413:
    goto v_10414;
v_10415:
    v_10568 = times2(v_10568, v_10567);
    env = stack[-6];
    goto v_10407;
v_10408:
    v_10567 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10409;
v_10410:
    goto v_10406;
v_10407:
    goto v_10408;
v_10409:
    v_10567 = (LispObject)lessp2(v_10568, v_10567);
    v_10567 = v_10567 ? lisp_true : nil;
    env = stack[-6];
    if (v_10567 == nil) goto v_10404;
    else goto v_10358;
v_10404:
    v_10567 = lisp_true;
    qvalue(elt(env, 9)) = v_10567; // !*sub2
    goto v_10315;
v_10358:
v_10315:
v_10247:
    v_10567 = stack[-5];
    if (v_10567 == nil) goto v_10425;
    else goto v_10426;
v_10425:
    v_10567 = stack[-4];
    fn = elt(env, 12); // fkern
    v_10567 = (*qfn1(fn))(fn, v_10567);
    env = stack[-6];
    stack[-5] = v_10567;
    goto v_10424;
v_10426:
v_10424:
    goto v_10435;
v_10431:
    goto v_10442;
v_10438:
    goto v_10448;
v_10444:
    v_10568 = stack[-5];
    goto v_10445;
v_10446:
    v_10567 = stack[-3];
    goto v_10447;
v_10448:
    goto v_10444;
v_10445:
    goto v_10446;
v_10447:
    fn = elt(env, 13); // getpower
    v_10568 = (*qfn2(fn))(fn, v_10568, v_10567);
    env = stack[-6];
    goto v_10439;
v_10440:
    v_10567 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10441;
v_10442:
    goto v_10438;
v_10439:
    goto v_10440;
v_10441:
    v_10567 = cons(v_10568, v_10567);
    env = stack[-6];
    v_10568 = ncons(v_10567);
    env = stack[-6];
    goto v_10432;
v_10433:
    v_10567 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10434;
v_10435:
    goto v_10431;
v_10432:
    goto v_10433;
v_10434:
    v_10567 = cons(v_10568, v_10567);
    env = stack[-6];
    stack[-5] = v_10567;
    v_10567 = stack[-2];
    if (v_10567 == nil) goto v_10456;
    goto v_10463;
v_10459:
    v_10568 = stack[-2];
    goto v_10460;
v_10461:
    v_10567 = stack[-5];
    goto v_10462;
v_10463:
    goto v_10459;
v_10460:
    goto v_10461;
v_10462:
    {
        fn = elt(env, 14); // multsq
        return (*qfn2(fn))(fn, v_10568, v_10567);
    }
v_10456:
    v_10567 = stack[-5];
    goto v_10454;
    v_10567 = nil;
v_10454:
    goto v_10245;
v_10248:
    v_10567 = qvalue(elt(env, 4)); // !*nosubs
    if (v_10567 == nil) goto v_10475;
    else goto v_10476;
v_10475:
    v_10567 = stack[-4];
    v_10567 = qcar(v_10567);
    if (!consp(v_10567)) goto v_10480;
    else goto v_10481;
v_10480:
    goto v_10496;
v_10492:
    v_10567 = stack[-4];
    v_10568 = qcar(v_10567);
    goto v_10493;
v_10494:
    v_10567 = elt(env, 10); // mksqsubfn
    goto v_10495;
v_10496:
    goto v_10492;
v_10493:
    goto v_10494;
v_10495:
    v_10567 = get(v_10568, v_10567);
    env = stack[-6];
    stack[-1] = v_10567;
    if (v_10567 == nil) goto v_10489;
    else goto v_10490;
v_10489:
    v_10567 = nil;
    goto v_10488;
v_10490:
    goto v_10508;
v_10504:
    v_10568 = stack[-1];
    goto v_10505;
v_10506:
    v_10567 = stack[-4];
    goto v_10507;
v_10508:
    goto v_10504;
v_10505:
    goto v_10506;
v_10507:
    v_10567 = Lapply1(nil, v_10568, v_10567);
    env = stack[-6];
    stack[-1] = v_10567;
    goto v_10488;
    v_10567 = nil;
v_10488:
    if (v_10567 == nil) goto v_10486;
    else goto v_10485;
v_10486:
    goto v_10515;
v_10511:
    v_10568 = stack[-4];
    goto v_10512;
v_10513:
    v_10567 = stack[-4];
    v_10567 = qcar(v_10567);
    if (!symbolp(v_10567)) v_10567 = nil;
    else { v_10567 = qfastgets(v_10567);
           if (v_10567 != nil) { v_10567 = elt(v_10567, 50); // kvalue
#ifdef RECORD_GET
             if (v_10567 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v_10567 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v_10567 == SPID_NOPROP) v_10567 = nil; }}
#endif
    goto v_10514;
v_10515:
    goto v_10511;
v_10512:
    goto v_10513;
v_10514:
    v_10567 = Lassoc(nil, v_10568, v_10567);
    stack[-1] = v_10567;
v_10485:
    goto v_10479;
v_10481:
    v_10567 = nil;
    goto v_10479;
    v_10567 = nil;
v_10479:
    goto v_10474;
v_10476:
    v_10567 = nil;
    goto v_10474;
    v_10567 = nil;
v_10474:
    if (v_10567 == nil) goto v_10472;
    goto v_10249;
v_10472:
    goto v_10533;
v_10529:
    stack[0] = elt(env, 5); // used!*
    goto v_10530;
v_10531:
    v_10567 = stack[-4];
    fn = elt(env, 12); // fkern
    v_10567 = (*qfn1(fn))(fn, v_10567);
    env = stack[-6];
    stack[-5] = v_10567;
    v_10567 = qcdr(v_10567);
    v_10567 = qcdr(v_10567);
    goto v_10532;
v_10533:
    goto v_10529;
v_10530:
    goto v_10531;
v_10532:
    v_10567 = Lmemq(nil, stack[0], v_10567);
    if (v_10567 == nil) goto v_10527;
    else goto v_10528;
v_10527:
    goto v_10545;
v_10541:
    v_10568 = stack[-5];
    goto v_10542;
v_10543:
    v_10567 = elt(env, 5); // used!*
    goto v_10544;
v_10545:
    goto v_10541;
v_10542:
    goto v_10543;
v_10544:
    fn = elt(env, 15); // aconc
    v_10567 = (*qfn2(fn))(fn, v_10568, v_10567);
    env = stack[-6];
    goto v_10470;
v_10528:
v_10470:
    goto v_10246;
v_10249:
    v_10567 = stack[-1];
    v_10567 = qcdr(v_10567);
    stack[-1] = v_10567;
    v_10567 = qvalue(elt(env, 11)); // !*resubs
    if (v_10567 == nil) goto v_10552;
    else goto v_10553;
v_10552:
    v_10567 = lisp_true;
    qvalue(elt(env, 4)) = v_10567; // !*nosubs
    goto v_10551;
v_10553:
v_10551:
    v_10567 = stack[-1];
    fn = elt(env, 16); // simpcar
    v_10567 = (*qfn1(fn))(fn, v_10567);
    env = stack[-6];
    stack[-5] = v_10567;
    v_10567 = nil;
    qvalue(elt(env, 4)) = v_10567; // !*nosubs
    goto v_10564;
v_10560:
    v_10568 = stack[-5];
    goto v_10561;
v_10562:
    v_10567 = stack[-3];
    goto v_10563;
v_10564:
    goto v_10560;
v_10561:
    goto v_10562;
v_10563:
    {
        fn = elt(env, 17); // exptsq
        return (*qfn2(fn))(fn, v_10568, v_10567);
    }
v_10245:
    return onevalue(v_10567);
}



// Code for rl_subat

static LispObject CC_rl_subat(LispObject env,
                         LispObject v_10238, LispObject v_10239)
{
    env = qenv(env);
    LispObject v_10256, v_10257;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10239,v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10238,v_10239);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10256 = v_10239;
    v_10257 = v_10238;
// end of prologue
    goto v_10246;
v_10242:
    stack[0] = qvalue(elt(env, 1)); // rl_subat!*
    goto v_10243;
v_10244:
    goto v_10253;
v_10249:
    goto v_10250;
v_10251:
    goto v_10252;
v_10253:
    goto v_10249;
v_10250:
    goto v_10251;
v_10252:
    v_10256 = list2(v_10257, v_10256);
    env = stack[-1];
    goto v_10245;
v_10246:
    goto v_10242;
v_10243:
    goto v_10244;
v_10245:
    {
        LispObject v_10259 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_10259, v_10256);
    }
}



// Code for qqe_simplterm

static LispObject CC_qqe_simplterm(LispObject env,
                         LispObject v_10238)
{
    env = qenv(env);
    LispObject v_10292, v_10293, v_10294;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10238);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10238;
// end of prologue
    v_10292 = stack[0];
    if (!consp(v_10292)) goto v_10245;
    else goto v_10246;
v_10245:
    v_10292 = stack[0];
    goto v_10242;
v_10246:
    v_10292 = stack[0];
    fn = elt(env, 4); // qqe_op
    v_10292 = (*qfn1(fn))(fn, v_10292);
    env = stack[-1];
    v_10294 = v_10292;
    goto v_10259;
v_10255:
    v_10293 = v_10294;
    goto v_10256;
v_10257:
    v_10292 = elt(env, 1); // (ltail rtail)
    goto v_10258;
v_10259:
    goto v_10255;
v_10256:
    goto v_10257;
v_10258:
    v_10292 = Lmemq(nil, v_10293, v_10292);
    if (v_10292 == nil) goto v_10254;
    v_10292 = stack[0];
    {
        fn = elt(env, 5); // qqe_simplterm!-tail
        return (*qfn1(fn))(fn, v_10292);
    }
v_10254:
    goto v_10271;
v_10267:
    v_10293 = v_10294;
    goto v_10268;
v_10269:
    v_10292 = elt(env, 2); // (lhead rhead)
    goto v_10270;
v_10271:
    goto v_10267;
v_10268:
    goto v_10269;
v_10270:
    v_10292 = Lmemq(nil, v_10293, v_10292);
    if (v_10292 == nil) goto v_10266;
    v_10292 = stack[0];
    {
        fn = elt(env, 6); // qqe_simplterm!-head
        return (*qfn1(fn))(fn, v_10292);
    }
v_10266:
    goto v_10283;
v_10279:
    v_10293 = v_10294;
    goto v_10280;
v_10281:
    v_10292 = elt(env, 3); // (ladd radd)
    goto v_10282;
v_10283:
    goto v_10279;
v_10280:
    goto v_10281;
v_10282:
    v_10292 = Lmemq(nil, v_10293, v_10292);
    if (v_10292 == nil) goto v_10278;
    v_10292 = stack[0];
    {
        fn = elt(env, 7); // qqe_simplterm!-add
        return (*qfn1(fn))(fn, v_10292);
    }
v_10278:
    v_10292 = stack[0];
    goto v_10242;
    v_10292 = nil;
v_10242:
    return onevalue(v_10292);
}



// Code for sf2ss

static LispObject CC_sf2ss(LispObject env,
                         LispObject v_10238)
{
    env = qenv(env);
    LispObject v_10291, v_10292;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10238);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_10238;
// end of prologue
    v_10291 = stack[-1];
    if (!consp(v_10291)) goto v_10250;
    else goto v_10251;
v_10250:
    v_10291 = lisp_true;
    goto v_10249;
v_10251:
    v_10291 = stack[-1];
    v_10291 = qcar(v_10291);
    v_10291 = (consp(v_10291) ? nil : lisp_true);
    goto v_10249;
    v_10291 = nil;
v_10249:
    if (v_10291 == nil) goto v_10247;
    v_10291 = stack[-1];
    goto v_10243;
v_10247:
    v_10291 = stack[-1];
    fn = elt(env, 1); // searchpl
    v_10291 = (*qfn1(fn))(fn, v_10291);
    env = stack[-3];
    stack[-2] = v_10291;
    goto v_10267;
v_10263:
    v_10291 = stack[-2];
    fn = elt(env, 2); // qsort
    stack[0] = (*qfn1(fn))(fn, v_10291);
    env = stack[-3];
    goto v_10264;
v_10265:
    v_10291 = stack[-2];
    v_10291 = Llength(nil, v_10291);
    env = stack[-3];
    goto v_10266;
v_10267:
    goto v_10263;
v_10264:
    goto v_10265;
v_10266:
    v_10291 = cons(stack[0], v_10291);
    env = stack[-3];
    goto v_10280;
v_10274:
    stack[0] = v_10291;
    goto v_10275;
v_10276:
    goto v_10287;
v_10283:
    v_10292 = stack[-1];
    goto v_10284;
v_10285:
    goto v_10286;
v_10287:
    goto v_10283;
v_10284:
    goto v_10285;
v_10286:
    fn = elt(env, 3); // sq2sspl
    v_10292 = (*qfn2(fn))(fn, v_10292, v_10291);
    env = stack[-3];
    goto v_10277;
v_10278:
    v_10291 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10279;
v_10280:
    goto v_10274;
v_10275:
    goto v_10276;
v_10277:
    goto v_10278;
v_10279:
    v_10291 = list2star(stack[0], v_10292, v_10291);
    env = stack[-3];
    {
        fn = elt(env, 4); // lx2xx
        return (*qfn1(fn))(fn, v_10291);
    }
v_10243:
    return onevalue(v_10291);
}



// Code for rl_simp1

static LispObject CC_rl_simp1(LispObject env,
                         LispObject v_10238)
{
    env = qenv(env);
    LispObject v_10520, v_10521, v_10522, v_10523;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10238);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_10238;
// end of prologue
v_10237:
    v_10520 = qvalue(elt(env, 1)); // rl_cid!*
    if (v_10520 == nil) goto v_10246;
    else goto v_10247;
v_10246:
    v_10520 = elt(env, 2); // "select a context"
    v_10520 = ncons(v_10520);
    env = stack[-5];
    fn = elt(env, 10); // rederr
    v_10520 = (*qfn1(fn))(fn, v_10520);
    env = stack[-5];
    goto v_10245;
v_10247:
v_10245:
    v_10520 = stack[0];
    if (!consp(v_10520)) goto v_10254;
    else goto v_10255;
v_10254:
    v_10520 = stack[0];
    {
        fn = elt(env, 11); // rl_simpatom
        return (*qfn1(fn))(fn, v_10520);
    }
v_10255:
    v_10520 = lisp_true;
// Binding !*strict_argcount
// FLUIDBIND: reloadenv=5 litvec-offset=3 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 3, -1);
    qvalue(elt(env, 3)) = v_10520; // !*strict_argcount
    v_10520 = stack[0];
    fn = elt(env, 12); // argnochk
    v_10520 = (*qfn1(fn))(fn, v_10520);
    env = stack[-5];
    ;}  // end of a binding scope
    goto v_10272;
v_10268:
    v_10520 = stack[0];
    v_10521 = qcar(v_10520);
    goto v_10269;
v_10270:
    v_10520 = elt(env, 4); // rl_simpfn
    goto v_10271;
v_10272:
    goto v_10268;
v_10269:
    goto v_10270;
v_10271:
    v_10520 = get(v_10521, v_10520);
    env = stack[-5];
    v_10521 = v_10520;
    if (v_10520 == nil) goto v_10266;
    v_10520 = v_10521;
    if (!symbolp(v_10520)) v_10520 = nil;
    else { v_10520 = qfastgets(v_10520);
           if (v_10520 != nil) { v_10520 = elt(v_10520, 62); // full
#ifdef RECORD_GET
             if (v_10520 == SPID_NOPROP)
                record_get(elt(fastget_names, 62), 0),
                v_10520 = nil;
             else record_get(elt(fastget_names, 62), 1),
                v_10520 = lisp_true; }
           else record_get(elt(fastget_names, 62), 0); }
#else
             if (v_10520 == SPID_NOPROP) v_10520 = nil; else v_10520 = lisp_true; }}
#endif
    if (v_10520 == nil) goto v_10279;
    goto v_10287;
v_10283:
    stack[-1] = v_10521;
    goto v_10284;
v_10285:
    v_10520 = stack[0];
    v_10520 = ncons(v_10520);
    env = stack[-5];
    goto v_10286;
v_10287:
    goto v_10283;
v_10284:
    goto v_10285;
v_10286:
    {
        LispObject v_10529 = stack[-1];
        fn = elt(env, 13); // apply
        return (*qfn2(fn))(fn, v_10529, v_10520);
    }
v_10279:
    goto v_10298;
v_10294:
    stack[-1] = v_10521;
    goto v_10295;
v_10296:
    v_10520 = stack[0];
    v_10520 = qcdr(v_10520);
    v_10520 = ncons(v_10520);
    env = stack[-5];
    goto v_10297;
v_10298:
    goto v_10294;
v_10295:
    goto v_10296;
v_10297:
    {
        LispObject v_10530 = stack[-1];
        fn = elt(env, 13); // apply
        return (*qfn2(fn))(fn, v_10530, v_10520);
    }
    v_10520 = nil;
    goto v_10243;
v_10266:
    goto v_10312;
v_10308:
    v_10520 = stack[0];
    v_10522 = qcar(v_10520);
    goto v_10309;
v_10310:
    goto v_10320;
v_10316:
    v_10520 = qvalue(elt(env, 1)); // rl_cid!*
    v_10521 = qcar(v_10520);
    goto v_10317;
v_10318:
    v_10520 = elt(env, 5); // simpfnname
    goto v_10319;
v_10320:
    goto v_10316;
v_10317:
    goto v_10318;
v_10319:
    v_10520 = get(v_10521, v_10520);
    env = stack[-5];
    goto v_10311;
v_10312:
    goto v_10308;
v_10309:
    goto v_10310;
v_10311:
    v_10520 = get(v_10522, v_10520);
    env = stack[-5];
    v_10521 = v_10520;
    if (v_10520 == nil) goto v_10306;
    v_10520 = v_10521;
    if (!symbolp(v_10520)) v_10520 = nil;
    else { v_10520 = qfastgets(v_10520);
           if (v_10520 != nil) { v_10520 = elt(v_10520, 62); // full
#ifdef RECORD_GET
             if (v_10520 == SPID_NOPROP)
                record_get(elt(fastget_names, 62), 0),
                v_10520 = nil;
             else record_get(elt(fastget_names, 62), 1),
                v_10520 = lisp_true; }
           else record_get(elt(fastget_names, 62), 0); }
#else
             if (v_10520 == SPID_NOPROP) v_10520 = nil; else v_10520 = lisp_true; }}
#endif
    if (v_10520 == nil) goto v_10327;
    goto v_10335;
v_10331:
    stack[-1] = v_10521;
    goto v_10332;
v_10333:
    v_10520 = stack[0];
    v_10520 = ncons(v_10520);
    env = stack[-5];
    goto v_10334;
v_10335:
    goto v_10331;
v_10332:
    goto v_10333;
v_10334:
    {
        LispObject v_10531 = stack[-1];
        fn = elt(env, 13); // apply
        return (*qfn2(fn))(fn, v_10531, v_10520);
    }
v_10327:
    goto v_10346;
v_10342:
    stack[-1] = v_10521;
    goto v_10343;
v_10344:
    v_10520 = stack[0];
    v_10520 = qcdr(v_10520);
    v_10520 = ncons(v_10520);
    env = stack[-5];
    goto v_10345;
v_10346:
    goto v_10342;
v_10343:
    goto v_10344;
v_10345:
    {
        LispObject v_10532 = stack[-1];
        fn = elt(env, 13); // apply
        return (*qfn2(fn))(fn, v_10532, v_10520);
    }
    v_10520 = nil;
    goto v_10243;
v_10306:
    v_10520 = stack[0];
    v_10520 = qcar(v_10520);
    if (!symbolp(v_10520)) v_10520 = nil;
    else { v_10520 = qfastgets(v_10520);
           if (v_10520 != nil) { v_10520 = elt(v_10520, 45); // psopfn
#ifdef RECORD_GET
             if (v_10520 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v_10520 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v_10520 == SPID_NOPROP) v_10520 = nil; }}
#endif
    v_10521 = v_10520;
    if (v_10520 == nil) goto v_10354;
    goto v_10363;
v_10359:
    goto v_10360;
v_10361:
    v_10520 = stack[0];
    v_10520 = qcdr(v_10520);
    goto v_10362;
v_10363:
    goto v_10359;
v_10360:
    goto v_10361;
v_10362:
    v_10520 = Lapply1(nil, v_10521, v_10520);
    env = stack[-5];
    stack[-1] = v_10520;
    goto v_10375;
v_10371:
    v_10521 = stack[-1];
    goto v_10372;
v_10373:
    v_10520 = stack[0];
    goto v_10374;
v_10375:
    goto v_10371;
v_10372:
    goto v_10373;
v_10374:
    if (equal(v_10521, v_10520)) goto v_10370;
    v_10520 = stack[-1];
    stack[0] = v_10520;
    goto v_10237;
v_10370:
    goto v_10352;
v_10354:
v_10352:
    v_10520 = stack[0];
    v_10520 = qcar(v_10520);
    if (!symbolp(v_10520)) v_10520 = nil;
    else { v_10520 = qfastgets(v_10520);
           if (v_10520 != nil) { v_10520 = elt(v_10520, 59); // opfn
#ifdef RECORD_GET
             if (v_10520 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v_10520 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v_10520 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v_10520 == SPID_NOPROP) v_10520 = nil; else v_10520 = lisp_true; }}
#endif
    if (v_10520 == nil) goto v_10383;
    goto v_10393;
v_10389:
    v_10520 = stack[0];
    stack[-4] = qcar(v_10520);
    goto v_10390;
v_10391:
    v_10520 = stack[0];
    v_10520 = qcdr(v_10520);
    stack[-3] = v_10520;
    v_10520 = stack[-3];
    if (v_10520 == nil) goto v_10406;
    else goto v_10407;
v_10406:
    v_10520 = nil;
    goto v_10400;
v_10407:
    v_10520 = stack[-3];
    v_10520 = qcar(v_10520);
    fn = elt(env, 14); // reval
    v_10520 = (*qfn1(fn))(fn, v_10520);
    env = stack[-5];
    v_10520 = ncons(v_10520);
    env = stack[-5];
    stack[-1] = v_10520;
    stack[-2] = v_10520;
v_10401:
    v_10520 = stack[-3];
    v_10520 = qcdr(v_10520);
    stack[-3] = v_10520;
    v_10520 = stack[-3];
    if (v_10520 == nil) goto v_10420;
    else goto v_10421;
v_10420:
    v_10520 = stack[-2];
    goto v_10400;
v_10421:
    goto v_10429;
v_10425:
    stack[0] = stack[-1];
    goto v_10426;
v_10427:
    v_10520 = stack[-3];
    v_10520 = qcar(v_10520);
    fn = elt(env, 14); // reval
    v_10520 = (*qfn1(fn))(fn, v_10520);
    env = stack[-5];
    v_10520 = ncons(v_10520);
    env = stack[-5];
    goto v_10428;
v_10429:
    goto v_10425;
v_10426:
    goto v_10427;
v_10428:
    v_10520 = Lrplacd(nil, stack[0], v_10520);
    env = stack[-5];
    v_10520 = stack[-1];
    v_10520 = qcdr(v_10520);
    stack[-1] = v_10520;
    goto v_10401;
v_10400:
    goto v_10392;
v_10393:
    goto v_10389;
v_10390:
    goto v_10391;
v_10392:
    fn = elt(env, 13); // apply
    v_10520 = (*qfn2(fn))(fn, stack[-4], v_10520);
    env = stack[-5];
    stack[0] = v_10520;
    goto v_10237;
v_10383:
    v_10520 = stack[0];
    v_10520 = qcar(v_10520);
    if (!symbolp(v_10520)) v_10520 = nil;
    else { v_10520 = qfastgets(v_10520);
           if (v_10520 != nil) { v_10520 = elt(v_10520, 44); // prepfn2
#ifdef RECORD_GET
             if (v_10520 != SPID_NOPROP)
                record_get(elt(fastget_names, 44), 1);
             else record_get(elt(fastget_names, 44), 0),
                v_10520 = nil; }
           else record_get(elt(fastget_names, 44), 0); }
#else
             if (v_10520 == SPID_NOPROP) v_10520 = nil; }}
#endif
    v_10521 = v_10520;
    if (v_10520 == nil) goto v_10442;
    goto v_10452;
v_10448:
    stack[-1] = v_10521;
    goto v_10449;
v_10450:
    v_10520 = stack[0];
    v_10520 = ncons(v_10520);
    env = stack[-5];
    goto v_10451;
v_10452:
    goto v_10448;
v_10449:
    goto v_10450;
v_10451:
    fn = elt(env, 13); // apply
    v_10520 = (*qfn2(fn))(fn, stack[-1], v_10520);
    env = stack[-5];
    stack[0] = v_10520;
    goto v_10237;
v_10442:
    v_10520 = stack[0];
    v_10520 = qcar(v_10520);
    fn = elt(env, 15); // ioto_form2str
    v_10520 = (*qfn1(fn))(fn, v_10520);
    env = stack[-5];
    stack[-1] = v_10520;
    v_10520 = stack[0];
    v_10520 = qcar(v_10520);
    if (!symbolp(v_10520)) v_10520 = nil;
    else { v_10520 = qfastgets(v_10520);
           if (v_10520 != nil) { v_10520 = elt(v_10520, 37); // prtch
#ifdef RECORD_GET
             if (v_10520 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v_10520 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v_10520 == SPID_NOPROP) v_10520 = nil; }}
#endif
    v_10521 = v_10520;
    if (v_10520 == nil) goto v_10462;
    goto v_10476;
v_10468:
    v_10520 = v_10521;
    fn = elt(env, 15); // ioto_form2str
    v_10523 = (*qfn1(fn))(fn, v_10520);
    env = stack[-5];
    goto v_10469;
v_10470:
    v_10522 = elt(env, 6); // " ("
    goto v_10471;
v_10472:
    v_10521 = stack[-1];
    goto v_10473;
v_10474:
    v_10520 = elt(env, 7); // ")"
    goto v_10475;
v_10476:
    goto v_10468;
v_10469:
    goto v_10470;
v_10471:
    goto v_10472;
v_10473:
    goto v_10474;
v_10475:
    v_10520 = list4(v_10523, v_10522, v_10521, v_10520);
    env = stack[-5];
    fn = elt(env, 16); // lto_sconcat
    v_10520 = (*qfn1(fn))(fn, v_10520);
    env = stack[-5];
    stack[-1] = v_10520;
    goto v_10460;
v_10462:
v_10460:
    goto v_10487;
v_10483:
    v_10521 = stack[-1];
    goto v_10484;
v_10485:
    v_10520 = elt(env, 8); // "predicate"
    goto v_10486;
v_10487:
    goto v_10483;
v_10484:
    goto v_10485;
v_10486:
    fn = elt(env, 17); // redmsg
    v_10520 = (*qfn2(fn))(fn, v_10521, v_10520);
    env = stack[-5];
    goto v_10497;
v_10491:
    v_10520 = stack[0];
    v_10523 = qcar(v_10520);
    goto v_10492;
v_10493:
    goto v_10505;
v_10501:
    v_10520 = qvalue(elt(env, 1)); // rl_cid!*
    v_10521 = qcar(v_10520);
    goto v_10502;
v_10503:
    v_10520 = elt(env, 5); // simpfnname
    goto v_10504;
v_10505:
    goto v_10501;
v_10502:
    goto v_10503;
v_10504:
    v_10522 = get(v_10521, v_10520);
    env = stack[-5];
    goto v_10494;
v_10495:
    goto v_10514;
v_10510:
    v_10520 = qvalue(elt(env, 1)); // rl_cid!*
    v_10521 = qcar(v_10520);
    goto v_10511;
v_10512:
    v_10520 = elt(env, 9); // simpdefault
    goto v_10513;
v_10514:
    goto v_10510;
v_10511:
    goto v_10512;
v_10513:
    v_10520 = get(v_10521, v_10520);
    env = stack[-5];
    goto v_10496;
v_10497:
    goto v_10491;
v_10492:
    goto v_10493;
v_10494:
    goto v_10495;
v_10496:
    v_10520 = Lputprop(nil, 3, v_10523, v_10522, v_10520);
    env = stack[-5];
    v_10520 = stack[0];
    stack[0] = v_10520;
    goto v_10237;
v_10243:
    return onevalue(v_10520);
}



// Code for aex_simplenullp

static LispObject CC_aex_simplenullp(LispObject env,
                         LispObject v_10238)
{
    env = qenv(env);
    LispObject v_10244;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10238);
    }
// copy arguments values to proper place
    v_10244 = v_10238;
// end of prologue
    fn = elt(env, 1); // aex_ex
    v_10244 = (*qfn1(fn))(fn, v_10244);
    v_10244 = qcar(v_10244);
    v_10244 = (v_10244 == nil ? lisp_true : nil);
    return onevalue(v_10244);
}



// Code for vdpputprop

static LispObject CC_vdpputprop(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10361, v_10362, v_10363, v_10364;
    LispObject fn;
    LispObject v_10240, v_10239, v_10238;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "vdpputprop");
    va_start(aa, nargs);
    v_10238 = va_arg(aa, LispObject);
    v_10239 = va_arg(aa, LispObject);
    v_10240 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_10240,v_10239,v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_10238,v_10239,v_10240);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_10240;
    stack[-3] = v_10239;
    stack[-4] = v_10238;
// end of prologue
    stack[-5] = nil;
    v_10361 = stack[-4];
    v_10361 = Lconsp(nil, v_10361);
    env = stack[-6];
    if (v_10361 == nil) goto v_10252;
    else goto v_10253;
v_10252:
    v_10361 = lisp_true;
    goto v_10251;
v_10253:
    v_10361 = stack[-4];
    v_10361 = qcdr(v_10361);
    stack[-5] = v_10361;
    v_10361 = Lconsp(nil, v_10361);
    env = stack[-6];
    if (v_10361 == nil) goto v_10261;
    else goto v_10262;
v_10261:
    v_10361 = lisp_true;
    goto v_10260;
v_10262:
    v_10361 = stack[-5];
    v_10361 = qcdr(v_10361);
    stack[-5] = v_10361;
    v_10361 = Lconsp(nil, v_10361);
    env = stack[-6];
    if (v_10361 == nil) goto v_10271;
    else goto v_10272;
v_10271:
    v_10361 = lisp_true;
    goto v_10270;
v_10272:
    v_10361 = stack[-5];
    v_10361 = qcdr(v_10361);
    stack[-5] = v_10361;
    v_10361 = Lconsp(nil, v_10361);
    env = stack[-6];
    if (v_10361 == nil) goto v_10281;
    else goto v_10282;
v_10281:
    v_10361 = lisp_true;
    goto v_10280;
v_10282:
    v_10361 = stack[-5];
    v_10361 = qcdr(v_10361);
    stack[-5] = v_10361;
    v_10361 = Lconsp(nil, v_10361);
    env = stack[-6];
    v_10361 = (v_10361 == nil ? lisp_true : nil);
    goto v_10280;
    v_10361 = nil;
v_10280:
    goto v_10270;
    v_10361 = nil;
v_10270:
    goto v_10260;
    v_10361 = nil;
v_10260:
    goto v_10251;
    v_10361 = nil;
v_10251:
    if (v_10361 == nil) goto v_10249;
    goto v_10300;
v_10294:
    stack[-1] = elt(env, 1); // dipoly
    goto v_10295;
v_10296:
    stack[0] = (LispObject)96+TAG_FIXNUM; // 6
    goto v_10297;
v_10298:
    goto v_10312;
v_10304:
    v_10364 = elt(env, 2); // "vdpputprop given a non-vdp as 1st parameter"
    goto v_10305;
v_10306:
    v_10363 = stack[-4];
    goto v_10307;
v_10308:
    v_10362 = stack[-3];
    goto v_10309;
v_10310:
    v_10361 = stack[-2];
    goto v_10311;
v_10312:
    goto v_10304;
v_10305:
    goto v_10306;
v_10307:
    goto v_10308;
v_10309:
    goto v_10310;
v_10311:
    v_10361 = list4(v_10364, v_10363, v_10362, v_10361);
    env = stack[-6];
    goto v_10299;
v_10300:
    goto v_10294;
v_10295:
    goto v_10296;
v_10297:
    goto v_10298;
v_10299:
    fn = elt(env, 3); // rerror
    v_10361 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_10361);
    env = stack[-6];
    goto v_10247;
v_10249:
v_10247:
    goto v_10321;
v_10317:
    v_10362 = stack[-3];
    goto v_10318;
v_10319:
    v_10361 = stack[-5];
    v_10361 = qcar(v_10361);
    goto v_10320;
v_10321:
    goto v_10317;
v_10318:
    goto v_10319;
v_10320:
    v_10361 = Lassoc(nil, v_10362, v_10361);
    v_10362 = v_10361;
    v_10361 = v_10362;
    if (v_10361 == nil) goto v_10329;
    goto v_10336;
v_10332:
    goto v_10333;
v_10334:
    v_10361 = stack[-2];
    goto v_10335;
v_10336:
    goto v_10332;
v_10333:
    goto v_10334;
v_10335:
    v_10361 = Lrplacd(nil, v_10362, v_10361);
    goto v_10327;
v_10329:
    goto v_10346;
v_10342:
    stack[0] = stack[-5];
    goto v_10343;
v_10344:
    goto v_10355;
v_10349:
    v_10363 = stack[-3];
    goto v_10350;
v_10351:
    v_10362 = stack[-2];
    goto v_10352;
v_10353:
    v_10361 = stack[-5];
    v_10361 = qcar(v_10361);
    goto v_10354;
v_10355:
    goto v_10349;
v_10350:
    goto v_10351;
v_10352:
    goto v_10353;
v_10354:
    v_10361 = acons(v_10363, v_10362, v_10361);
    env = stack[-6];
    goto v_10345;
v_10346:
    goto v_10342;
v_10343:
    goto v_10344;
v_10345:
    v_10361 = Lrplaca(nil, stack[0], v_10361);
    goto v_10327;
v_10327:
    v_10361 = stack[-4];
    return onevalue(v_10361);
}



// Code for equalreplaceby

static LispObject CC_equalreplaceby(LispObject env,
                         LispObject v_10238)
{
    env = qenv(env);
    LispObject v_10248, v_10249;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10248 = v_10238;
// end of prologue
    goto v_10245;
v_10241:
    v_10249 = elt(env, 1); // replaceby
    goto v_10242;
v_10243:
    goto v_10244;
v_10245:
    goto v_10241;
v_10242:
    goto v_10243;
v_10244:
    return cons(v_10249, v_10248);
}



// Code for gpexp1p

static LispObject CC_gpexp1p(LispObject env,
                         LispObject v_10238)
{
    env = qenv(env);
    LispObject v_10261;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10238);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10238;
// end of prologue
v_10237:
    v_10261 = stack[0];
    if (v_10261 == nil) goto v_10242;
    else goto v_10243;
v_10242:
    v_10261 = lisp_true;
    goto v_10241;
v_10243:
    v_10261 = stack[0];
    v_10261 = qcar(v_10261);
    fn = elt(env, 1); // gpexpp
    v_10261 = (*qfn1(fn))(fn, v_10261);
    env = stack[-1];
    if (v_10261 == nil) goto v_10250;
    else goto v_10251;
v_10250:
    v_10261 = nil;
    goto v_10249;
v_10251:
    v_10261 = stack[0];
    v_10261 = qcdr(v_10261);
    stack[0] = v_10261;
    goto v_10237;
    v_10261 = nil;
v_10249:
    goto v_10241;
    v_10261 = nil;
v_10241:
    return onevalue(v_10261);
}



// Code for add2resultbuf

static LispObject CC_add2resultbuf(LispObject env,
                         LispObject v_10238, LispObject v_10239)
{
    env = qenv(env);
    LispObject v_10379, v_10380, v_10381;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10239,v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10238,v_10239);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10239;
    stack[-1] = v_10238;
// end of prologue
    v_10379 = qvalue(elt(env, 1)); // !*libreduce_active
    if (v_10379 == nil) goto v_10246;
    fn = elt(env, 13); // lr_result
    v_10379 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_10257;
v_10253:
    v_10380 = qvalue(elt(env, 2)); // semic!*
    goto v_10254;
v_10255:
    v_10379 = elt(env, 3); // !$
    goto v_10256;
v_10257:
    goto v_10253;
v_10254:
    goto v_10255;
v_10256:
    if (v_10380 == v_10379) goto v_10252;
    goto v_10265;
v_10261:
    v_10380 = stack[-1];
    goto v_10262;
v_10263:
    v_10379 = stack[0];
    goto v_10264;
v_10265:
    goto v_10261;
v_10262:
    goto v_10263;
v_10264:
    fn = elt(env, 14); // lr_printer
    v_10379 = (*qfn2(fn))(fn, v_10380, v_10379);
    env = stack[-2];
    goto v_10250;
v_10252:
v_10250:
    fn = elt(env, 15); // lr_statcounter
    v_10379 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_10379 = qvalue(elt(env, 4)); // statcounter
    v_10379 = Lprinc(nil, v_10379);
    env = stack[-2];
    fn = elt(env, 16); // lr_mode
    v_10379 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_10281;
v_10277:
    v_10380 = qvalue(elt(env, 5)); // !*mode
    goto v_10278;
v_10279:
    v_10379 = elt(env, 6); // symbolic
    goto v_10280;
v_10281:
    goto v_10277;
v_10278:
    goto v_10279;
v_10280:
    if (v_10380 == v_10379) goto v_10275;
    else goto v_10276;
v_10275:
    v_10379 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10274;
v_10276:
    v_10379 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10274;
    v_10379 = nil;
v_10274:
    v_10379 = Lprinc(nil, v_10379);
    env = stack[-2];
    fn = elt(env, 17); // lr_posttext
    v_10379 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_10379 = Lterpri(nil, 0);
    env = stack[-2];
    goto v_10244;
v_10246:
v_10244:
    goto v_10302;
v_10298:
    v_10380 = stack[0];
    goto v_10299;
v_10300:
    v_10379 = elt(env, 6); // symbolic
    goto v_10301;
v_10302:
    goto v_10298;
v_10299:
    goto v_10300;
v_10301:
    if (v_10380 == v_10379) goto v_10296;
    else goto v_10297;
v_10296:
    v_10379 = lisp_true;
    goto v_10295;
v_10297:
    v_10379 = stack[-1];
    if (v_10379 == nil) goto v_10314;
    else goto v_10315;
v_10314:
    v_10379 = qvalue(elt(env, 7)); // !*reduce4
    if (v_10379 == nil) goto v_10319;
    else goto v_10320;
v_10319:
    v_10379 = lisp_true;
    goto v_10318;
v_10320:
    goto v_10329;
v_10325:
    v_10380 = stack[0];
    goto v_10326;
v_10327:
    v_10379 = elt(env, 8); // empty_list
    goto v_10328;
v_10329:
    goto v_10325;
v_10326:
    goto v_10327;
v_10328:
    v_10379 = (v_10380 == v_10379 ? lisp_true : nil);
    v_10379 = (v_10379 == nil ? lisp_true : nil);
    goto v_10318;
    v_10379 = nil;
v_10318:
    goto v_10313;
v_10315:
    v_10379 = nil;
    goto v_10313;
    v_10379 = nil;
v_10313:
    if (v_10379 == nil) goto v_10311;
    v_10379 = lisp_true;
    goto v_10309;
v_10311:
    v_10379 = qvalue(elt(env, 9)); // !*nosave!*
    goto v_10309;
    v_10379 = nil;
v_10309:
    goto v_10295;
    v_10379 = nil;
v_10295:
    if (v_10379 == nil) goto v_10293;
    v_10379 = nil;
    goto v_10242;
v_10293:
    v_10379 = qvalue(elt(env, 7)); // !*reduce4
    if (v_10379 == nil) goto v_10345;
    goto v_10354;
v_10348:
    v_10381 = elt(env, 10); // ws
    goto v_10349;
v_10350:
    v_10380 = stack[-1];
    goto v_10351;
v_10352:
    v_10379 = stack[0];
    goto v_10353;
v_10354:
    goto v_10348;
v_10349:
    goto v_10350;
v_10351:
    goto v_10352;
v_10353:
    fn = elt(env, 18); // putobject
    v_10379 = (*qfnn(fn))(fn, 3, v_10381, v_10380, v_10379);
    env = stack[-2];
    goto v_10343;
v_10345:
    v_10379 = nil;
    v_10379 = ncons(v_10379);
    env = stack[-2];
    qvalue(elt(env, 11)) = v_10379; // alglist!*
    v_10379 = stack[-1];
    qvalue(elt(env, 10)) = v_10379; // ws
    goto v_10343;
v_10343:
    fn = elt(env, 19); // terminalp
    v_10379 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_10379 == nil) goto v_10366;
    goto v_10375;
v_10369:
    v_10381 = qvalue(elt(env, 4)); // statcounter
    goto v_10370;
v_10371:
    v_10380 = stack[-1];
    goto v_10372;
v_10373:
    v_10379 = qvalue(elt(env, 12)); // resultbuflis!*
    goto v_10374;
v_10375:
    goto v_10369;
v_10370:
    goto v_10371;
v_10372:
    goto v_10373;
v_10374:
    v_10379 = acons(v_10381, v_10380, v_10379);
    env = stack[-2];
    qvalue(elt(env, 12)) = v_10379; // resultbuflis!*
    goto v_10364;
v_10366:
v_10364:
    v_10379 = nil;
v_10242:
    return onevalue(v_10379);
}



// Code for class

static LispObject CC_class(LispObject env,
                         LispObject v_10238)
{
    env = qenv(env);
    LispObject v_10274, v_10275;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10238);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10238;
// end of prologue
    goto v_10248;
v_10244:
    v_10274 = stack[0];
    fn = elt(env, 3); // ord
    v_10275 = (*qfn1(fn))(fn, v_10274);
    env = stack[-1];
    goto v_10245;
v_10246:
    v_10274 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10247;
v_10248:
    goto v_10244;
v_10245:
    goto v_10246;
v_10247:
    if (v_10275 == v_10274) goto v_10242;
    else goto v_10243;
v_10242:
    v_10274 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10241;
v_10243:
    goto v_10265;
v_10261:
    v_10275 = qvalue(elt(env, 1)); // ordering
    goto v_10262;
v_10263:
    v_10274 = elt(env, 2); // lex
    goto v_10264;
v_10265:
    goto v_10261;
v_10262:
    goto v_10263;
v_10264:
    if (v_10275 == v_10274) goto v_10259;
    else goto v_10260;
v_10259:
    v_10274 = stack[0];
    goto v_10258;
v_10260:
    v_10274 = stack[0];
    v_10274 = qcdr(v_10274);
    goto v_10258;
    v_10274 = nil;
v_10258:
    v_10274 = Lreverse(nil, v_10274);
    env = stack[-1];
    fn = elt(env, 4); // leftzeros
    v_10274 = (*qfn1(fn))(fn, v_10274);
    v_10274 = (LispObject)((intptr_t)(v_10274) + 0x10);
    goto v_10241;
    v_10274 = nil;
v_10241:
    return onevalue(v_10274);
}



// Code for moduntag

static LispObject CC_moduntag(LispObject env,
                         LispObject v_10238)
{
    env = qenv(env);
    LispObject v_10290, v_10291;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10238);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10238;
// end of prologue
    stack[-1] = nil;
v_10243:
    goto v_10253;
v_10249:
    v_10291 = stack[0];
    goto v_10250;
v_10251:
    v_10290 = elt(env, 1); // !:mod!:
    goto v_10252;
v_10253:
    goto v_10249;
v_10250:
    goto v_10251;
v_10252:
    if (!consp(v_10291)) goto v_10247;
    v_10291 = qcar(v_10291);
    if (v_10291 == v_10290) goto v_10246;
    else goto v_10247;
v_10246:
    goto v_10261;
v_10257:
    v_10291 = stack[-1];
    goto v_10258;
v_10259:
    v_10290 = stack[0];
    v_10290 = qcdr(v_10290);
    goto v_10260;
v_10261:
    goto v_10257;
v_10258:
    goto v_10259;
v_10260:
    {
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_10291, v_10290);
    }
v_10247:
    v_10290 = stack[0];
    if (!consp(v_10290)) goto v_10265;
    else goto v_10266;
v_10265:
    goto v_10273;
v_10269:
    v_10291 = stack[-1];
    goto v_10270;
v_10271:
    v_10290 = stack[0];
    goto v_10272;
v_10273:
    goto v_10269;
v_10270:
    goto v_10271;
v_10272:
    {
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_10291, v_10290);
    }
v_10266:
    goto v_10283;
v_10279:
    v_10290 = stack[0];
    v_10290 = qcar(v_10290);
    v_10291 = CC_moduntag(elt(env, 0), v_10290);
    env = stack[-2];
    goto v_10280;
v_10281:
    v_10290 = stack[-1];
    goto v_10282;
v_10283:
    goto v_10279;
v_10280:
    goto v_10281;
v_10282:
    v_10290 = cons(v_10291, v_10290);
    env = stack[-2];
    stack[-1] = v_10290;
    v_10290 = stack[0];
    v_10290 = qcdr(v_10290);
    stack[0] = v_10290;
    goto v_10243;
    v_10290 = nil;
    return onevalue(v_10290);
}



// Code for rrdls

static LispObject CC_rrdls(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10334, v_10335, v_10336;
    LispObject fn;
    argcheck(nargs, 0, "rrdls");
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
    stack[0] = nil;
v_10244:
    fn = elt(env, 7); // rread1
    v_10334 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_10334;
    goto v_10255;
v_10251:
    v_10335 = qvalue(elt(env, 1)); // ttype!*
    goto v_10252;
v_10253:
    v_10334 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_10254;
v_10255:
    goto v_10251;
v_10252:
    goto v_10253;
v_10254:
    if (v_10335 == v_10334) goto v_10250;
    goto v_10245;
v_10250:
    goto v_10264;
v_10260:
    v_10335 = stack[-1];
    goto v_10261;
v_10262:
    v_10334 = elt(env, 2); // !)
    goto v_10263;
v_10264:
    goto v_10260;
v_10261:
    goto v_10262;
v_10263:
    if (v_10335 == v_10334) goto v_10258;
    else goto v_10259;
v_10258:
    v_10334 = stack[0];
    goto v_10243;
v_10259:
    goto v_10274;
v_10270:
    v_10335 = stack[-1];
    goto v_10271;
v_10272:
    v_10334 = elt(env, 3); // !.
    goto v_10273;
v_10274:
    goto v_10270;
v_10271:
    goto v_10272;
v_10273:
    if (v_10335 == v_10334) goto v_10269;
    goto v_10245;
v_10269:
    fn = elt(env, 7); // rread1
    v_10334 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_10334;
    fn = elt(env, 8); // ptoken
    v_10334 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_10336 = v_10334;
    goto v_10291;
v_10287:
    v_10335 = qvalue(elt(env, 1)); // ttype!*
    goto v_10288;
v_10289:
    v_10334 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_10290;
v_10291:
    goto v_10287;
v_10288:
    goto v_10289;
v_10290:
    if (v_10335 == v_10334) goto v_10286;
    v_10334 = lisp_true;
    goto v_10284;
v_10286:
    goto v_10301;
v_10297:
    v_10335 = v_10336;
    goto v_10298;
v_10299:
    v_10334 = elt(env, 2); // !)
    goto v_10300;
v_10301:
    goto v_10297;
v_10298:
    goto v_10299;
v_10300:
    v_10334 = (v_10335 == v_10334 ? lisp_true : nil);
    v_10334 = (v_10334 == nil ? lisp_true : nil);
    goto v_10284;
    v_10334 = nil;
v_10284:
    if (v_10334 == nil) goto v_10282;
    v_10334 = elt(env, 4); // " "
    qvalue(elt(env, 5)) = v_10334; // nxtsym!*
    goto v_10312;
v_10308:
    v_10335 = elt(env, 6); // "Invalid S-expression"
    goto v_10309;
v_10310:
    v_10334 = nil;
    goto v_10311;
v_10312:
    goto v_10308;
v_10309:
    goto v_10310;
v_10311:
    fn = elt(env, 9); // symerr
    v_10334 = (*qfn2(fn))(fn, v_10335, v_10334);
    env = stack[-2];
    goto v_10280;
v_10282:
    goto v_10322;
v_10318:
    v_10335 = stack[0];
    goto v_10319;
v_10320:
    v_10334 = stack[-1];
    goto v_10321;
v_10322:
    goto v_10318;
v_10319:
    goto v_10320;
v_10321:
        return Lnconc(nil, v_10335, v_10334);
v_10280:
v_10245:
    goto v_10330;
v_10326:
    goto v_10327;
v_10328:
    v_10334 = stack[-1];
    v_10334 = ncons(v_10334);
    env = stack[-2];
    goto v_10329;
v_10330:
    goto v_10326;
v_10327:
    goto v_10328;
v_10329:
    v_10334 = Lnconc(nil, stack[0], v_10334);
    env = stack[-2];
    stack[0] = v_10334;
    goto v_10244;
v_10243:
    return onevalue(v_10334);
}



// Code for rl_nnf

static LispObject CC_rl_nnf(LispObject env,
                         LispObject v_10238)
{
    env = qenv(env);
    LispObject v_10249;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10238);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10249 = v_10238;
// end of prologue
    goto v_10245;
v_10241:
    stack[0] = qvalue(elt(env, 1)); // rl_nnf!*
    goto v_10242;
v_10243:
    v_10249 = ncons(v_10249);
    env = stack[-1];
    goto v_10244;
v_10245:
    goto v_10241;
v_10242:
    goto v_10243;
v_10244:
    {
        LispObject v_10251 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_10251, v_10249);
    }
}



// Code for rl_susipost

static LispObject CC_rl_susipost(LispObject env,
                         LispObject v_10238, LispObject v_10239)
{
    env = qenv(env);
    LispObject v_10256, v_10257;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10239,v_10238);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10238,v_10239);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10256 = v_10239;
    v_10257 = v_10238;
// end of prologue
    goto v_10246;
v_10242:
    stack[0] = qvalue(elt(env, 1)); // rl_susipost!*
    goto v_10243;
v_10244:
    goto v_10253;
v_10249:
    goto v_10250;
v_10251:
    goto v_10252;
v_10253:
    goto v_10249;
v_10250:
    goto v_10251;
v_10252:
    v_10256 = list2(v_10257, v_10256);
    env = stack[-1];
    goto v_10245;
v_10246:
    goto v_10242;
v_10243:
    goto v_10244;
v_10245:
    {
        LispObject v_10259 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_10259, v_10256);
    }
}



setup_type const u18_setup[] =
{
    {"exptcompare",             TOO_FEW_2,      CC_exptcompare,WRONG_NO_2},
    {"cl_smsimpl-junct2",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_smsimplKjunct2},
    {"variableom",              CC_variableom,  TOO_MANY_1,    WRONG_NO_1},
    {"onoff",                   TOO_FEW_2,      CC_onoff,      WRONG_NO_2},
    {"unchecked_getmatelem",    CC_unchecked_getmatelem,TOO_MANY_1,WRONG_NO_1},
    {"guesspftype",             CC_guesspftype, TOO_MANY_1,    WRONG_NO_1},
    {"deleteall",               TOO_FEW_2,      CC_deleteall,  WRONG_NO_2},
    {"cstimes",                 TOO_FEW_2,      CC_cstimes,    WRONG_NO_2},
    {"copyd",                   TOO_FEW_2,      CC_copyd,      WRONG_NO_2},
    {"sf_member",               TOO_FEW_2,      CC_sf_member,  WRONG_NO_2},
    {"b:extadd",                TOO_FEW_2,      CC_bTextadd,   WRONG_NO_2},
    {"ra_refine1",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ra_refine1},
    {"replus",                  CC_replus,      TOO_MANY_1,    WRONG_NO_1},
    {"mkpartitions1",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mkpartitions1},
    {"wusort",                  CC_wusort,      TOO_MANY_1,    WRONG_NO_1},
    {"expnd1",                  CC_expnd1,      TOO_MANY_1,    WRONG_NO_1},
    {"talp_simplatat",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_simplatat},
    {"ibalp_unvar-unsatlist",   TOO_FEW_2,      CC_ibalp_unvarKunsatlist,WRONG_NO_2},
    {"mml2om",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mml2om},
    {"lesspcdr",                TOO_FEW_2,      CC_lesspcdr,   WRONG_NO_2},
    {"command",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_command},
    {"ord2",                    TOO_FEW_2,      CC_ord2,       WRONG_NO_2},
    {"general-reduce-degree-mod-p",TOO_FEW_2,   CC_generalKreduceKdegreeKmodKp,WRONG_NO_2},
    {"simpiden",                CC_simpiden,    TOO_MANY_1,    WRONG_NO_1},
    {"lexer_word_starter",      CC_lexer_word_starter,TOO_MANY_1,WRONG_NO_1},
    {"gcref_select",            CC_gcref_select,TOO_MANY_1,    WRONG_NO_1},
    {"mksq",                    TOO_FEW_2,      CC_mksq,       WRONG_NO_2},
    {"rl_subat",                TOO_FEW_2,      CC_rl_subat,   WRONG_NO_2},
    {"qqe_simplterm",           CC_qqe_simplterm,TOO_MANY_1,   WRONG_NO_1},
    {"sf2ss",                   CC_sf2ss,       TOO_MANY_1,    WRONG_NO_1},
    {"rl_simp1",                CC_rl_simp1,    TOO_MANY_1,    WRONG_NO_1},
    {"aex_simplenullp",         CC_aex_simplenullp,TOO_MANY_1, WRONG_NO_1},
    {"vdpputprop",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vdpputprop},
    {"equalreplaceby",          CC_equalreplaceby,TOO_MANY_1,  WRONG_NO_1},
    {"gpexp1p",                 CC_gpexp1p,     TOO_MANY_1,    WRONG_NO_1},
    {"add2resultbuf",           TOO_FEW_2,      CC_add2resultbuf,WRONG_NO_2},
    {"class",                   CC_class,       TOO_MANY_1,    WRONG_NO_1},
    {"moduntag",                CC_moduntag,    TOO_MANY_1,    WRONG_NO_1},
    {"rrdls",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rrdls},
    {"rl_nnf",                  CC_rl_nnf,      TOO_MANY_1,    WRONG_NO_1},
    {"rl_susipost",             TOO_FEW_2,      CC_rl_susipost,WRONG_NO_2},
    {NULL, (one_args *)"u18", (two_args *)"267 7875121 255701", 0}
};

// end of generated code
