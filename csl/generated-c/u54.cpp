
// $destdir/u54.c        Machine generated C code

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



// Code for simpx1

static LispObject CC_simpx1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_32254, v_32255, v_32256;
    LispObject fn;
    LispObject v_31367, v_31366, v_31365;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "simpx1");
    va_start(aa, nargs);
    v_31365 = va_arg(aa, LispObject);
    v_31366 = va_arg(aa, LispObject);
    v_31367 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31367,v_31366,v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31365,v_31366,v_31367);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_31367;
    stack[-1] = v_31366;
    stack[-4] = v_31365;
// end of prologue
    stack[-6] = nil;
    goto v_31385;
v_31381:
    v_32255 = stack[-4];
    goto v_31382;
v_31383:
    v_32254 = elt(env, 1); // !*minus!*
    goto v_31384;
v_31385:
    goto v_31381;
v_31382:
    goto v_31383;
v_31384:
    if (!consp(v_32255)) goto v_31379;
    v_32255 = qcar(v_32255);
    if (v_32255 == v_32254) goto v_31378;
    else goto v_31379;
v_31378:
    goto v_31401;
v_31397:
    v_32255 = stack[-1];
    goto v_31398;
v_31399:
    v_32254 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31400;
v_31401:
    goto v_31397;
v_31398:
    goto v_31399;
v_31400:
    if (v_32255 == v_32254) goto v_31395;
    else goto v_31396;
v_31395:
    v_32254 = stack[-3];
    v_32254 = integerp(v_32254);
    if (v_32254 == nil) goto v_31406;
    else goto v_31407;
v_31406:
    v_32254 = nil;
    goto v_31405;
v_31407:
    goto v_31417;
v_31413:
    goto v_31423;
v_31419:
    v_32255 = stack[-3];
    goto v_31420;
v_31421:
    v_32254 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31422;
v_31423:
    goto v_31419;
v_31420:
    goto v_31421;
v_31422:
    v_32255 = Cremainder(v_32255, v_32254);
    env = stack[-7];
    goto v_31414;
v_31415:
    v_32254 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31416;
v_31417:
    goto v_31413;
v_31414:
    goto v_31415;
v_31416:
    v_32254 = (v_32255 == v_32254 ? lisp_true : nil);
    goto v_31405;
    v_32254 = nil;
v_31405:
    goto v_31394;
v_31396:
    v_32254 = nil;
    goto v_31394;
    v_32254 = nil;
v_31394:
    if (v_32254 == nil) goto v_31392;
    else goto v_31390;
v_31392:
    goto v_31440;
v_31436:
    v_32255 = stack[-3];
    goto v_31437;
v_31438:
    v_32254 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31439;
v_31440:
    goto v_31436;
v_31437:
    goto v_31438;
v_31439:
    if (v_32255 == v_32254) goto v_31434;
    else goto v_31435;
v_31434:
    goto v_31452;
v_31448:
    v_32255 = stack[-1];
    goto v_31449;
v_31450:
    v_32254 = elt(env, 2); // quotient
    goto v_31451;
v_31452:
    goto v_31448;
v_31449:
    goto v_31450;
v_31451:
    if (!consp(v_32255)) goto v_31446;
    v_32255 = qcar(v_32255);
    if (v_32255 == v_32254) goto v_31445;
    else goto v_31446;
v_31445:
    goto v_31463;
v_31459:
    v_32254 = stack[-1];
    v_32254 = qcdr(v_32254);
    v_32255 = qcar(v_32254);
    goto v_31460;
v_31461:
    v_32254 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31462;
v_31463:
    goto v_31459;
v_31460:
    goto v_31461;
v_31462:
    if (v_32255 == v_32254) goto v_31457;
    else goto v_31458;
v_31457:
    v_32254 = stack[-1];
    v_32254 = qcdr(v_32254);
    v_32254 = qcdr(v_32254);
    v_32254 = qcar(v_32254);
    v_32254 = integerp(v_32254);
    if (v_32254 == nil) goto v_31470;
    else goto v_31471;
v_31470:
    v_32254 = nil;
    goto v_31469;
v_31471:
    goto v_31484;
v_31480:
    goto v_31490;
v_31486:
    v_32254 = stack[-1];
    v_32254 = qcdr(v_32254);
    v_32254 = qcdr(v_32254);
    v_32255 = qcar(v_32254);
    goto v_31487;
v_31488:
    v_32254 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31489;
v_31490:
    goto v_31486;
v_31487:
    goto v_31488;
v_31489:
    v_32255 = Cremainder(v_32255, v_32254);
    env = stack[-7];
    goto v_31481;
v_31482:
    v_32254 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31483;
v_31484:
    goto v_31480;
v_31481:
    goto v_31482;
v_31483:
    v_32254 = (v_32255 == v_32254 ? lisp_true : nil);
    goto v_31469;
    v_32254 = nil;
v_31469:
    goto v_31456;
v_31458:
    v_32254 = nil;
    goto v_31456;
    v_32254 = nil;
v_31456:
    goto v_31444;
v_31446:
    v_32254 = nil;
    goto v_31444;
    v_32254 = nil;
v_31444:
    goto v_31433;
v_31435:
    v_32254 = nil;
    goto v_31433;
    v_32254 = nil;
v_31433:
    if (v_32254 == nil) goto v_31431;
    else goto v_31390;
v_31431:
    goto v_31391;
v_31390:
    goto v_31512;
v_31508:
    goto v_31521;
v_31515:
    stack[-6] = elt(env, 3); // expt
    goto v_31516;
v_31517:
    stack[-5] = elt(env, 4); // i
    goto v_31518;
v_31519:
    goto v_31531;
v_31525:
    stack[-2] = elt(env, 2); // quotient
    goto v_31526;
v_31527:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31528;
v_31529:
    goto v_31539;
v_31535:
    v_32255 = stack[-3];
    goto v_31536;
v_31537:
    v_32254 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31538;
v_31539:
    goto v_31535;
v_31536:
    goto v_31537;
v_31538:
    v_32254 = quot2(v_32255, v_32254);
    env = stack[-7];
    goto v_31530;
v_31531:
    goto v_31525;
v_31526:
    goto v_31527;
v_31528:
    goto v_31529;
v_31530:
    v_32254 = list3(stack[-2], stack[0], v_32254);
    env = stack[-7];
    goto v_31520;
v_31521:
    goto v_31515;
v_31516:
    goto v_31517;
v_31518:
    goto v_31519;
v_31520:
    v_32254 = list3(stack[-6], stack[-5], v_32254);
    env = stack[-7];
    fn = elt(env, 18); // simp
    stack[0] = (*qfn1(fn))(fn, v_32254);
    env = stack[-7];
    goto v_31509;
v_31510:
    goto v_31548;
v_31544:
    v_32254 = stack[-4];
    v_32254 = qcdr(v_32254);
    stack[-2] = qcar(v_32254);
    goto v_31545;
v_31546:
    goto v_31559;
v_31553:
    v_32256 = elt(env, 2); // quotient
    goto v_31554;
v_31555:
    v_32255 = stack[-1];
    goto v_31556;
v_31557:
    v_32254 = stack[-3];
    goto v_31558;
v_31559:
    goto v_31553;
v_31554:
    goto v_31555;
v_31556:
    goto v_31557;
v_31558:
    v_32254 = list3(v_32256, v_32255, v_32254);
    env = stack[-7];
    goto v_31547;
v_31548:
    goto v_31544;
v_31545:
    goto v_31546;
v_31547:
    v_32254 = list2(stack[-2], v_32254);
    env = stack[-7];
    fn = elt(env, 19); // simpexpt
    v_32254 = (*qfn1(fn))(fn, v_32254);
    env = stack[-7];
    goto v_31511;
v_31512:
    goto v_31508;
v_31509:
    goto v_31510;
v_31511:
    {
        LispObject v_32264 = stack[0];
        fn = elt(env, 20); // multsq
        return (*qfn2(fn))(fn, v_32264, v_32254);
    }
v_31391:
    goto v_31573;
v_31569:
    v_32255 = stack[-1];
    goto v_31570;
v_31571:
    v_32254 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31572;
v_31573:
    goto v_31569;
v_31570:
    goto v_31571;
v_31572:
    if (v_32255 == v_32254) goto v_31567;
    else goto v_31568;
v_31567:
    v_32254 = stack[-3];
    v_32254 = integerp(v_32254);
    goto v_31566;
v_31568:
    v_32254 = nil;
    goto v_31566;
    v_32254 = nil;
v_31566:
    if (v_32254 == nil) goto v_31564;
    goto v_31588;
v_31584:
    v_32254 = stack[-4];
    v_32254 = qcdr(v_32254);
    stack[0] = qcar(v_32254);
    goto v_31585;
v_31586:
    goto v_31599;
v_31593:
    v_32256 = elt(env, 2); // quotient
    goto v_31594;
v_31595:
    v_32255 = stack[-1];
    goto v_31596;
v_31597:
    v_32254 = stack[-3];
    goto v_31598;
v_31599:
    goto v_31593;
v_31594:
    goto v_31595;
v_31596:
    goto v_31597;
v_31598:
    v_32254 = list3(v_32256, v_32255, v_32254);
    env = stack[-7];
    goto v_31587;
v_31588:
    goto v_31584;
v_31585:
    goto v_31586;
v_31587:
    v_32254 = list2(stack[0], v_32254);
    env = stack[-7];
    fn = elt(env, 19); // simpexpt
    v_32254 = (*qfn1(fn))(fn, v_32254);
    env = stack[-7];
    {
        fn = elt(env, 21); // negsq
        return (*qfn1(fn))(fn, v_32254);
    }
v_31564:
    goto v_31377;
v_31379:
v_31377:
    v_32254 = stack[-1];
    if (is_number(v_32254)) goto v_31608;
    else goto v_31607;
v_31608:
    v_32254 = stack[-3];
    if (is_number(v_32254)) goto v_31610;
    else goto v_31607;
v_31610:
    goto v_31605;
v_31607:
    goto v_31619;
v_31615:
    v_32255 = qvalue(elt(env, 5)); // frlis!*
    goto v_31616;
v_31617:
    v_32254 = stack[-1];
    goto v_31618;
v_31619:
    goto v_31615;
v_31616:
    goto v_31617;
v_31618:
    fn = elt(env, 22); // smemqlp
    v_32254 = (*qfn2(fn))(fn, v_32255, v_32254);
    env = stack[-7];
    if (v_32254 == nil) goto v_31613;
    else goto v_31612;
v_31613:
    goto v_31628;
v_31624:
    v_32255 = qvalue(elt(env, 5)); // frlis!*
    goto v_31625;
v_31626:
    v_32254 = stack[-3];
    goto v_31627;
v_31628:
    goto v_31624;
v_31625:
    goto v_31626;
v_31627:
    fn = elt(env, 22); // smemqlp
    v_32254 = (*qfn2(fn))(fn, v_32255, v_32254);
    env = stack[-7];
    if (v_32254 == nil) goto v_31622;
    else goto v_31612;
v_31622:
    goto v_31605;
v_31612:
    goto v_31606;
v_31605:
    goto v_31374;
v_31606:
    goto v_31636;
v_31632:
    goto v_31644;
v_31638:
    stack[0] = elt(env, 3); // expt
    goto v_31639;
v_31640:
    stack[-2] = stack[-4];
    goto v_31641;
v_31642:
    goto v_31655;
v_31651:
    v_32255 = stack[-3];
    goto v_31652;
v_31653:
    v_32254 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31654;
v_31655:
    goto v_31651;
v_31652:
    goto v_31653;
v_31654:
    if (v_32255 == v_32254) goto v_31649;
    else goto v_31650;
v_31649:
    v_32254 = stack[-1];
    goto v_31648;
v_31650:
    goto v_31668;
v_31662:
    v_32256 = elt(env, 2); // quotient
    goto v_31663;
v_31664:
    v_32255 = stack[-1];
    goto v_31665;
v_31666:
    v_32254 = stack[-3];
    goto v_31667;
v_31668:
    goto v_31662;
v_31663:
    goto v_31664;
v_31665:
    goto v_31666;
v_31667:
    v_32254 = list3(v_32256, v_32255, v_32254);
    env = stack[-7];
    goto v_31648;
    v_32254 = nil;
v_31648:
    goto v_31643;
v_31644:
    goto v_31638;
v_31639:
    goto v_31640;
v_31641:
    goto v_31642;
v_31643:
    v_32255 = list3(stack[0], stack[-2], v_32254);
    env = stack[-7];
    goto v_31633;
v_31634:
    v_32254 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31635;
v_31636:
    goto v_31632;
v_31633:
    goto v_31634;
v_31635:
    {
        fn = elt(env, 23); // mksq
        return (*qfn2(fn))(fn, v_32255, v_32254);
    }
v_31374:
    v_32254 = stack[-1];
    if (is_number(v_32254)) goto v_31675;
    else goto v_31676;
v_31675:
    v_32254 = stack[-1];
    v_32254 = Lminusp(nil, v_32254);
    env = stack[-7];
    if (v_32254 == nil) goto v_31681;
    v_32254 = stack[-1];
    v_32254 = negate(v_32254);
    env = stack[-7];
    stack[-1] = v_32254;
    goto v_31375;
v_31681:
    v_32254 = stack[-1];
    v_32254 = integerp(v_32254);
    if (v_32254 == nil) goto v_31687;
    v_32254 = stack[-3];
    v_32254 = integerp(v_32254);
    if (v_32254 == nil) goto v_31693;
    v_32254 = stack[-6];
    if (v_32254 == nil) goto v_31699;
    v_32254 = stack[-1];
    v_32254 = negate(v_32254);
    env = stack[-7];
    stack[-1] = v_32254;
    goto v_31697;
v_31699:
v_31697:
    v_32254 = stack[-1];
    stack[-5] = v_32254;
    v_32254 = qvalue(elt(env, 6)); // !*mcd
    if (v_32254 == nil) goto v_31707;
    v_32254 = stack[-4];
    v_32254 = integerp(v_32254);
    if (v_32254 == nil) goto v_31711;
    else goto v_31710;
v_31711:
    v_32254 = qvalue(elt(env, 7)); // !*notseparate
    if (v_32254 == nil) goto v_31710;
    goto v_31707;
v_31710:
    goto v_31721;
v_31717:
    stack[-2] = stack[-5];
    goto v_31718;
v_31719:
    goto v_31728;
v_31724:
    stack[0] = stack[-3];
    goto v_31725;
v_31726:
    goto v_31735;
v_31731:
    v_32255 = stack[-1];
    goto v_31732;
v_31733:
    v_32254 = stack[-3];
    goto v_31734;
v_31735:
    goto v_31731;
v_31732:
    goto v_31733;
v_31734:
    v_32254 = quot2(v_32255, v_32254);
    env = stack[-7];
    stack[-1] = v_32254;
    goto v_31727;
v_31728:
    goto v_31724;
v_31725:
    goto v_31726;
v_31727:
    v_32254 = times2(stack[0], v_32254);
    env = stack[-7];
    goto v_31720;
v_31721:
    goto v_31717;
v_31718:
    goto v_31719;
v_31720:
    v_32254 = difference2(stack[-2], v_32254);
    env = stack[-7];
    stack[-5] = v_32254;
    goto v_31747;
v_31743:
    v_32255 = stack[-5];
    goto v_31744;
v_31745:
    v_32254 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31746;
v_31747:
    goto v_31743;
v_31744:
    goto v_31745;
v_31746:
    v_32254 = (LispObject)lessp2(v_32255, v_32254);
    v_32254 = v_32254 ? lisp_true : nil;
    env = stack[-7];
    if (v_32254 == nil) goto v_31741;
    v_32254 = stack[-1];
    v_32254 = sub1(v_32254);
    env = stack[-7];
    stack[-1] = v_32254;
    goto v_31757;
v_31753:
    v_32255 = stack[-5];
    goto v_31754;
v_31755:
    v_32254 = stack[-3];
    goto v_31756;
v_31757:
    goto v_31753;
v_31754:
    goto v_31755;
v_31756:
    v_32254 = plus2(v_32255, v_32254);
    env = stack[-7];
    stack[-5] = v_32254;
    goto v_31739;
v_31741:
v_31739:
    goto v_31705;
v_31707:
    v_32254 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_32254;
    goto v_31705;
v_31705:
    goto v_31769;
v_31765:
    v_32255 = stack[-4];
    goto v_31766;
v_31767:
    v_32254 = stack[-1];
    goto v_31768;
v_31769:
    goto v_31765;
v_31766:
    goto v_31767;
v_31768:
    v_32254 = list2(v_32255, v_32254);
    env = stack[-7];
    fn = elt(env, 19); // simpexpt
    v_32254 = (*qfn1(fn))(fn, v_32254);
    env = stack[-7];
    stack[0] = v_32254;
    goto v_31780;
v_31776:
    v_32255 = stack[-5];
    goto v_31777;
v_31778:
    v_32254 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31779;
v_31780:
    goto v_31776;
v_31777:
    goto v_31778;
v_31779:
    if (v_32255 == v_32254) goto v_31774;
    else goto v_31775;
v_31774:
    v_32254 = stack[0];
    goto v_31373;
v_31775:
    goto v_31794;
v_31790:
    v_32255 = stack[-3];
    goto v_31791;
v_31792:
    v_32254 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31793;
v_31794:
    goto v_31790;
v_31791:
    goto v_31792;
v_31793:
    if (v_32255 == v_32254) goto v_31788;
    else goto v_31789;
v_31788:
    v_32254 = qvalue(elt(env, 8)); // !*keepsqrts
    goto v_31787;
v_31789:
    v_32254 = nil;
    goto v_31787;
    v_32254 = nil;
v_31787:
    if (v_32254 == nil) goto v_31785;
    goto v_31806;
v_31802:
    stack[-1] = stack[0];
    goto v_31803;
v_31804:
    goto v_31813;
v_31809:
    v_32254 = elt(env, 9); // sqrt
    if (!symbolp(v_32254)) stack[0] = nil;
    else { stack[0] = qfastgets(v_32254);
           if (stack[0] != nil) { stack[0] = elt(stack[0], 22); // simpfn
#ifdef RECORD_GET
             if (stack[0] != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                stack[0] = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (stack[0] == SPID_NOPROP) stack[0] = nil; }}
#endif
    goto v_31810;
v_31811:
    v_32254 = stack[-4];
    v_32254 = ncons(v_32254);
    env = stack[-7];
    goto v_31812;
v_31813:
    goto v_31809;
v_31810:
    goto v_31811;
v_31812:
    v_32254 = Lapply1(nil, stack[0], v_32254);
    env = stack[-7];
    goto v_31805;
v_31806:
    goto v_31802;
v_31803:
    goto v_31804;
v_31805:
    fn = elt(env, 20); // multsq
    v_32254 = (*qfn2(fn))(fn, stack[-1], v_32254);
    env = stack[-7];
    stack[0] = v_32254;
    goto v_31827;
v_31823:
    v_32255 = stack[-5];
    goto v_31824;
v_31825:
    v_32254 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31826;
v_31827:
    goto v_31823;
v_31824:
    goto v_31825;
v_31826:
    v_32254 = (LispObject)lessp2(v_32255, v_32254);
    v_32254 = v_32254 ? lisp_true : nil;
    env = stack[-7];
    if (v_32254 == nil) goto v_31821;
    v_32254 = stack[0];
    fn = elt(env, 24); // invsq
    v_32254 = (*qfn1(fn))(fn, v_32254);
    env = stack[-7];
    stack[0] = v_32254;
    v_32254 = stack[-5];
    v_32254 = negate(v_32254);
    env = stack[-7];
    stack[-5] = v_32254;
    goto v_31819;
v_31821:
v_31819:
    goto v_31839;
v_31835:
    v_32255 = stack[0];
    goto v_31836;
v_31837:
    v_32254 = stack[-5];
    goto v_31838;
v_31839:
    goto v_31835;
v_31836:
    goto v_31837;
v_31838:
    {
        fn = elt(env, 25); // exptsq
        return (*qfn2(fn))(fn, v_32255, v_32254);
    }
v_31785:
    goto v_31849;
v_31845:
    goto v_31846;
v_31847:
    goto v_31856;
v_31852:
    goto v_31862;
v_31858:
    v_32254 = stack[-4];
    fn = elt(env, 26); // simp!*
    v_32255 = (*qfn1(fn))(fn, v_32254);
    env = stack[-7];
    goto v_31859;
v_31860:
    v_32254 = stack[-3];
    goto v_31861;
v_31862:
    goto v_31858;
v_31859:
    goto v_31860;
v_31861:
    fn = elt(env, 27); // simprad
    v_32255 = (*qfn2(fn))(fn, v_32255, v_32254);
    env = stack[-7];
    goto v_31853;
v_31854:
    v_32254 = stack[-5];
    goto v_31855;
v_31856:
    goto v_31852;
v_31853:
    goto v_31854;
v_31855:
    fn = elt(env, 25); // exptsq
    v_32254 = (*qfn2(fn))(fn, v_32255, v_32254);
    env = stack[-7];
    goto v_31848;
v_31849:
    goto v_31845;
v_31846:
    goto v_31847;
v_31848:
    {
        LispObject v_32265 = stack[0];
        fn = elt(env, 20); // multsq
        return (*qfn2(fn))(fn, v_32265, v_32254);
    }
    goto v_31691;
v_31693:
    v_32254 = stack[-1];
    stack[-5] = v_32254;
    v_32254 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_32254;
    goto v_31691;
v_31691:
    goto v_31679;
v_31687:
    v_32254 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_32254;
    goto v_31679;
v_31679:
    goto v_31674;
v_31676:
    v_32254 = stack[-1];
    if (!consp(v_32254)) goto v_31874;
    else goto v_31875;
v_31874:
    v_32254 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_32254;
    goto v_31674;
v_31875:
    goto v_31884;
v_31880:
    v_32254 = stack[-1];
    v_32255 = qcar(v_32254);
    goto v_31881;
v_31882:
    v_32254 = elt(env, 10); // minus
    goto v_31883;
v_31884:
    goto v_31880;
v_31881:
    goto v_31882;
v_31883:
    if (v_32255 == v_32254) goto v_31878;
    else goto v_31879;
v_31878:
    v_32254 = stack[-1];
    v_32254 = qcdr(v_32254);
    v_32254 = qcar(v_32254);
    stack[-1] = v_32254;
    goto v_31375;
v_31879:
    goto v_31901;
v_31897:
    v_32254 = stack[-1];
    v_32255 = qcar(v_32254);
    goto v_31898;
v_31899:
    v_32254 = elt(env, 11); // plus
    goto v_31900;
v_31901:
    goto v_31897;
v_31898:
    goto v_31899;
v_31900:
    if (v_32255 == v_32254) goto v_31895;
    else goto v_31896;
v_31895:
    v_32254 = qvalue(elt(env, 12)); // !*expandexpt
    goto v_31894;
v_31896:
    v_32254 = nil;
    goto v_31894;
    v_32254 = nil;
v_31894:
    if (v_32254 == nil) goto v_31892;
    goto v_31914;
v_31910:
    v_32255 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31911;
v_31912:
    v_32254 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31913;
v_31914:
    goto v_31910;
v_31911:
    goto v_31912;
v_31913:
    v_32254 = cons(v_32255, v_32254);
    env = stack[-7];
    stack[-5] = v_32254;
    v_32254 = stack[-1];
    v_32254 = qcdr(v_32254);
    stack[-2] = v_32254;
v_31920:
    v_32254 = stack[-2];
    if (v_32254 == nil) goto v_31925;
    else goto v_31926;
v_31925:
    goto v_31919;
v_31926:
    v_32254 = stack[-2];
    v_32254 = qcar(v_32254);
    goto v_31937;
v_31933:
    goto v_31944;
v_31940:
    stack[-1] = stack[-4];
    goto v_31941;
v_31942:
    goto v_31953;
v_31947:
    stack[0] = elt(env, 2); // quotient
    goto v_31948;
v_31949:
    v_32255 = stack[-6];
    if (v_32255 == nil) goto v_31958;
    goto v_31965;
v_31961:
    v_32255 = elt(env, 10); // minus
    goto v_31962;
v_31963:
    goto v_31964;
v_31965:
    goto v_31961;
v_31962:
    goto v_31963;
v_31964:
    v_32254 = list2(v_32255, v_32254);
    env = stack[-7];
    v_32255 = v_32254;
    goto v_31956;
v_31958:
    v_32255 = v_32254;
    goto v_31956;
    v_32255 = nil;
v_31956:
    goto v_31950;
v_31951:
    v_32254 = stack[-3];
    goto v_31952;
v_31953:
    goto v_31947;
v_31948:
    goto v_31949;
v_31950:
    goto v_31951;
v_31952:
    v_32254 = list3(stack[0], v_32255, v_32254);
    env = stack[-7];
    goto v_31943;
v_31944:
    goto v_31940;
v_31941:
    goto v_31942;
v_31943:
    v_32254 = list2(stack[-1], v_32254);
    env = stack[-7];
    fn = elt(env, 19); // simpexpt
    v_32255 = (*qfn1(fn))(fn, v_32254);
    env = stack[-7];
    goto v_31934;
v_31935:
    v_32254 = stack[-5];
    goto v_31936;
v_31937:
    goto v_31933;
v_31934:
    goto v_31935;
v_31936:
    fn = elt(env, 20); // multsq
    v_32254 = (*qfn2(fn))(fn, v_32255, v_32254);
    env = stack[-7];
    stack[-5] = v_32254;
    v_32254 = stack[-2];
    v_32254 = qcdr(v_32254);
    stack[-2] = v_32254;
    goto v_31920;
v_31919:
    v_32254 = stack[-5];
    goto v_31373;
v_31892:
    goto v_31986;
v_31982:
    v_32254 = stack[-1];
    v_32255 = qcar(v_32254);
    goto v_31983;
v_31984:
    v_32254 = elt(env, 13); // times
    goto v_31985;
v_31986:
    goto v_31982;
v_31983:
    goto v_31984;
v_31985:
    if (v_32255 == v_32254) goto v_31980;
    else goto v_31981;
v_31980:
    v_32254 = stack[-1];
    v_32254 = qcdr(v_32254);
    v_32254 = qcar(v_32254);
    v_32254 = integerp(v_32254);
    goto v_31979;
v_31981:
    v_32254 = nil;
    goto v_31979;
    v_32254 = nil;
v_31979:
    if (v_32254 == nil) goto v_31977;
    v_32254 = stack[-3];
    if (is_number(v_32254)) goto v_31999;
    else goto v_32000;
v_31999:
    goto v_32007;
v_32003:
    v_32255 = stack[-3];
    goto v_32004;
v_32005:
    v_32254 = stack[-1];
    v_32254 = qcdr(v_32254);
    v_32254 = qcar(v_32254);
    goto v_32006;
v_32007:
    goto v_32003;
v_32004:
    goto v_32005;
v_32006:
    v_32254 = Lgcd(nil, v_32255, v_32254);
    env = stack[-7];
    stack[-5] = v_32254;
    goto v_32017;
v_32013:
    v_32255 = stack[-3];
    goto v_32014;
v_32015:
    v_32254 = stack[-5];
    goto v_32016;
v_32017:
    goto v_32013;
v_32014:
    goto v_32015;
v_32016:
    v_32254 = quot2(v_32255, v_32254);
    env = stack[-7];
    stack[-3] = v_32254;
    goto v_32025;
v_32021:
    v_32254 = stack[-1];
    v_32254 = qcdr(v_32254);
    v_32255 = qcar(v_32254);
    goto v_32022;
v_32023:
    v_32254 = stack[-5];
    goto v_32024;
v_32025:
    goto v_32021;
v_32022:
    goto v_32023;
v_32024:
    v_32254 = quot2(v_32255, v_32254);
    env = stack[-7];
    stack[-5] = v_32254;
    goto v_31998;
v_32000:
    v_32254 = stack[-1];
    v_32254 = qcdr(v_32254);
    v_32254 = qcar(v_32254);
    stack[-5] = v_32254;
    goto v_31998;
v_31998:
    v_32254 = stack[-1];
    v_32254 = qcdr(v_32254);
    v_32254 = qcdr(v_32254);
    v_32254 = qcdr(v_32254);
    if (v_32254 == nil) goto v_32038;
    goto v_32048;
v_32044:
    v_32255 = elt(env, 13); // times
    goto v_32045;
v_32046:
    v_32254 = stack[-1];
    v_32254 = qcdr(v_32254);
    v_32254 = qcdr(v_32254);
    goto v_32047;
v_32048:
    goto v_32044;
v_32045:
    goto v_32046;
v_32047:
    v_32254 = cons(v_32255, v_32254);
    env = stack[-7];
    goto v_32036;
v_32038:
    v_32254 = stack[-1];
    v_32254 = qcdr(v_32254);
    v_32254 = qcdr(v_32254);
    v_32254 = qcar(v_32254);
    goto v_32036;
    v_32254 = nil;
v_32036:
    stack[-1] = v_32254;
    goto v_31674;
v_31977:
    goto v_32069;
v_32065:
    v_32254 = stack[-1];
    v_32255 = qcar(v_32254);
    goto v_32066;
v_32067:
    v_32254 = elt(env, 2); // quotient
    goto v_32068;
v_32069:
    goto v_32065;
v_32066:
    goto v_32067;
v_32068:
    if (v_32255 == v_32254) goto v_32063;
    else goto v_32064;
v_32063:
    goto v_32081;
v_32077:
    v_32255 = stack[-3];
    goto v_32078;
v_32079:
    v_32254 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32080;
v_32081:
    goto v_32077;
v_32078:
    goto v_32079;
v_32080:
    if (v_32255 == v_32254) goto v_32075;
    else goto v_32076;
v_32075:
    v_32254 = qvalue(elt(env, 12)); // !*expandexpt
    goto v_32074;
v_32076:
    v_32254 = nil;
    goto v_32074;
    v_32254 = nil;
v_32074:
    goto v_32062;
v_32064:
    v_32254 = nil;
    goto v_32062;
    v_32254 = nil;
v_32062:
    if (v_32254 == nil) goto v_32060;
    v_32254 = stack[-1];
    v_32254 = qcdr(v_32254);
    v_32254 = qcdr(v_32254);
    v_32254 = qcar(v_32254);
    stack[-3] = v_32254;
    v_32254 = stack[-1];
    v_32254 = qcdr(v_32254);
    v_32254 = qcar(v_32254);
    stack[-1] = v_32254;
    goto v_31374;
v_32060:
    v_32254 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_32254;
    goto v_31674;
v_31674:
    v_32254 = stack[-4];
    if (symbolp(v_32254)) goto v_32105;
    else goto v_32104;
v_32105:
    goto v_32113;
v_32109:
    v_32255 = stack[-4];
    goto v_32110;
v_32111:
    v_32254 = elt(env, 14); // used!*
    goto v_32112;
v_32113:
    goto v_32109;
v_32110:
    goto v_32111;
v_32112:
    v_32254 = Lflagp(nil, v_32255, v_32254);
    env = stack[-7];
    if (v_32254 == nil) goto v_32107;
    else goto v_32104;
v_32107:
    goto v_32121;
v_32117:
    v_32254 = stack[-4];
    v_32255 = ncons(v_32254);
    env = stack[-7];
    goto v_32118;
v_32119:
    v_32254 = elt(env, 14); // used!*
    goto v_32120;
v_32121:
    goto v_32117;
v_32118:
    goto v_32119;
v_32120:
    v_32254 = Lflag(nil, v_32255, v_32254);
    env = stack[-7];
    goto v_32102;
v_32104:
v_32102:
    goto v_32137;
v_32133:
    v_32255 = stack[-4];
    goto v_32134;
v_32135:
    v_32254 = elt(env, 15); // (minus 1)
    goto v_32136;
v_32137:
    goto v_32133;
v_32134:
    goto v_32135;
v_32136:
    if (equal(v_32255, v_32254)) goto v_32131;
    else goto v_32132;
v_32131:
    goto v_32148;
v_32144:
    v_32255 = stack[-3];
    goto v_32145;
v_32146:
    v_32254 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32147;
v_32148:
    goto v_32144;
v_32145:
    goto v_32146;
v_32147:
    if (v_32255 == v_32254) goto v_32142;
    else goto v_32143;
v_32142:
    goto v_32159;
v_32153:
    v_32256 = elt(env, 16); // difference
    goto v_32154;
v_32155:
    v_32255 = stack[-1];
    goto v_32156;
v_32157:
    v_32254 = elt(env, 17); // (quotient 1 2)
    goto v_32158;
v_32159:
    goto v_32153;
v_32154:
    goto v_32155;
v_32156:
    goto v_32157;
v_32158:
    v_32254 = list3(v_32256, v_32255, v_32254);
    env = stack[-7];
    fn = elt(env, 18); // simp
    v_32254 = (*qfn1(fn))(fn, v_32254);
    env = stack[-7];
    v_32254 = qcar(v_32254);
    v_32254 = (v_32254 == nil ? lisp_true : nil);
    goto v_32141;
v_32143:
    v_32254 = nil;
    goto v_32141;
    v_32254 = nil;
v_32141:
    goto v_32130;
v_32132:
    v_32254 = nil;
    goto v_32130;
    v_32254 = nil;
v_32130:
    if (v_32254 == nil) goto v_32128;
    v_32254 = elt(env, 4); // i
    fn = elt(env, 18); // simp
    v_32254 = (*qfn1(fn))(fn, v_32254);
    env = stack[-7];
    stack[-4] = v_32254;
    v_32254 = stack[-6];
    if (v_32254 == nil) goto v_32176;
    v_32254 = stack[-4];
    {
        fn = elt(env, 21); // negsq
        return (*qfn1(fn))(fn, v_32254);
    }
v_32176:
    v_32254 = stack[-4];
    goto v_32174;
    v_32254 = nil;
v_32174:
    goto v_31373;
v_32128:
    goto v_32190;
v_32184:
    stack[0] = elt(env, 3); // expt
    goto v_32185;
v_32186:
    stack[-2] = stack[-4];
    goto v_32187;
v_32188:
    goto v_32201;
v_32197:
    v_32255 = stack[-3];
    goto v_32198;
v_32199:
    v_32254 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32200;
v_32201:
    goto v_32197;
v_32198:
    goto v_32199;
v_32200:
    if (v_32255 == v_32254) goto v_32195;
    else goto v_32196;
v_32195:
    v_32254 = stack[-1];
    goto v_32194;
v_32196:
    goto v_32214;
v_32208:
    v_32256 = elt(env, 2); // quotient
    goto v_32209;
v_32210:
    v_32255 = stack[-1];
    goto v_32211;
v_32212:
    v_32254 = stack[-3];
    goto v_32213;
v_32214:
    goto v_32208;
v_32209:
    goto v_32210;
v_32211:
    goto v_32212;
v_32213:
    v_32254 = list3(v_32256, v_32255, v_32254);
    env = stack[-7];
    goto v_32194;
    v_32254 = nil;
v_32194:
    goto v_32189;
v_32190:
    goto v_32184;
v_32185:
    goto v_32186;
v_32187:
    goto v_32188;
v_32189:
    v_32254 = list3(stack[0], stack[-2], v_32254);
    env = stack[-7];
    stack[-4] = v_32254;
    goto v_32223;
v_32219:
    stack[0] = stack[-4];
    goto v_32220;
v_32221:
    v_32254 = stack[-6];
    if (v_32254 == nil) goto v_32228;
    v_32254 = stack[-5];
    v_32254 = negate(v_32254);
    env = stack[-7];
    goto v_32226;
v_32228:
    v_32254 = stack[-5];
    goto v_32226;
    v_32254 = nil;
v_32226:
    goto v_32222;
v_32223:
    goto v_32219;
v_32220:
    goto v_32221;
v_32222:
    {
        LispObject v_32266 = stack[0];
        fn = elt(env, 23); // mksq
        return (*qfn2(fn))(fn, v_32266, v_32254);
    }
v_31375:
    v_32254 = qvalue(elt(env, 6)); // !*mcd
    if (v_32254 == nil) goto v_32238;
    goto v_32248;
v_32242:
    v_32256 = stack[-4];
    goto v_32243;
v_32244:
    v_32255 = stack[-1];
    goto v_32245;
v_32246:
    v_32254 = stack[-3];
    goto v_32247;
v_32248:
    goto v_32242;
v_32243:
    goto v_32244;
v_32245:
    goto v_32246;
v_32247:
    v_32254 = CC_simpx1(elt(env, 0), 3, v_32256, v_32255, v_32254);
    env = stack[-7];
    {
        fn = elt(env, 24); // invsq
        return (*qfn1(fn))(fn, v_32254);
    }
v_32238:
    v_32254 = stack[-6];
    v_32254 = (v_32254 == nil ? lisp_true : nil);
    stack[-6] = v_32254;
    goto v_31374;
v_31373:
    return onevalue(v_32254);
}



// Code for equal!+matrices!+p

static LispObject CC_equalLmatricesLp(LispObject env,
                         LispObject v_31365, LispObject v_31366)
{
    env = qenv(env);
    LispObject v_31512, v_31513, v_31514;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31366,v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31365,v_31366);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_31366;
    stack[-1] = v_31365;
// end of prologue
    goto v_31387;
v_31383:
    v_31513 = stack[-1];
    goto v_31384;
v_31385:
    v_31512 = stack[0];
    goto v_31386;
v_31387:
    goto v_31383;
v_31384:
    goto v_31385;
v_31386:
    fn = elt(env, 2); // same!+dim!+squared!+p
    v_31512 = (*qfn2(fn))(fn, v_31513, v_31512);
    env = stack[-4];
    if (v_31512 == nil) goto v_31381;
    goto v_31395;
v_31391:
    goto v_31392;
v_31393:
    goto v_31402;
v_31398:
    goto v_31408;
v_31404:
    v_31513 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_31405;
v_31406:
    v_31512 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31407;
v_31408:
    goto v_31404;
v_31405:
    goto v_31406;
v_31407:
    v_31513 = cons(v_31513, v_31512);
    env = stack[-4];
    goto v_31399;
v_31400:
    v_31512 = stack[0];
    goto v_31401;
v_31402:
    goto v_31398;
v_31399:
    goto v_31400;
v_31401:
    fn = elt(env, 3); // mk!+scal!+mult!+mat
    v_31512 = (*qfn2(fn))(fn, v_31513, v_31512);
    env = stack[-4];
    goto v_31394;
v_31395:
    goto v_31391;
v_31392:
    goto v_31393;
v_31394:
    fn = elt(env, 4); // mk!+mat!+plus!+mat
    v_31512 = (*qfn2(fn))(fn, stack[-1], v_31512);
    env = stack[-4];
    stack[0] = v_31512;
    goto v_31417;
v_31413:
    v_31513 = nil;
    goto v_31414;
v_31415:
    v_31512 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31416;
v_31417:
    goto v_31413;
v_31414:
    goto v_31415;
v_31416:
    v_31512 = cons(v_31513, v_31512);
    env = stack[-4];
    v_31514 = v_31512;
    v_31512 = stack[0];
    stack[-3] = v_31512;
v_31423:
    v_31512 = stack[-3];
    if (v_31512 == nil) goto v_31427;
    else goto v_31428;
v_31427:
    goto v_31422;
v_31428:
    v_31512 = stack[-3];
    v_31512 = qcar(v_31512);
    stack[-2] = v_31512;
v_31437:
    v_31512 = stack[-2];
    if (v_31512 == nil) goto v_31441;
    else goto v_31442;
v_31441:
    goto v_31436;
v_31442:
    v_31512 = stack[-2];
    v_31512 = qcar(v_31512);
    v_31513 = v_31512;
    v_31512 = qvalue(elt(env, 1)); // !*complex
    if (v_31512 == nil) goto v_31451;
    goto v_31458;
v_31454:
    stack[-1] = v_31514;
    goto v_31455;
v_31456:
    goto v_31465;
v_31461:
    stack[0] = v_31513;
    goto v_31462;
v_31463:
    v_31512 = v_31513;
    fn = elt(env, 5); // mk!+conjugate!+sq
    v_31512 = (*qfn1(fn))(fn, v_31512);
    env = stack[-4];
    goto v_31464;
v_31465:
    goto v_31461;
v_31462:
    goto v_31463;
v_31464:
    fn = elt(env, 6); // multsq
    v_31512 = (*qfn2(fn))(fn, stack[0], v_31512);
    env = stack[-4];
    goto v_31457;
v_31458:
    goto v_31454;
v_31455:
    goto v_31456;
v_31457:
    fn = elt(env, 7); // addsq
    v_31512 = (*qfn2(fn))(fn, stack[-1], v_31512);
    env = stack[-4];
    v_31514 = v_31512;
    goto v_31449;
v_31451:
    goto v_31476;
v_31472:
    stack[0] = v_31514;
    goto v_31473;
v_31474:
    goto v_31483;
v_31479:
    v_31512 = v_31513;
    goto v_31480;
v_31481:
    goto v_31482;
v_31483:
    goto v_31479;
v_31480:
    goto v_31481;
v_31482:
    fn = elt(env, 6); // multsq
    v_31512 = (*qfn2(fn))(fn, v_31512, v_31513);
    env = stack[-4];
    goto v_31475;
v_31476:
    goto v_31472;
v_31473:
    goto v_31474;
v_31475:
    fn = elt(env, 7); // addsq
    v_31512 = (*qfn2(fn))(fn, stack[0], v_31512);
    env = stack[-4];
    v_31514 = v_31512;
    goto v_31449;
v_31449:
    v_31512 = stack[-2];
    v_31512 = qcdr(v_31512);
    stack[-2] = v_31512;
    goto v_31437;
v_31436:
    v_31512 = stack[-3];
    v_31512 = qcdr(v_31512);
    stack[-3] = v_31512;
    goto v_31423;
v_31422:
    v_31512 = v_31514;
    fn = elt(env, 8); // change!+sq!+to!+algnull
    v_31512 = (*qfn1(fn))(fn, v_31512);
    goto v_31500;
v_31496:
    v_31513 = v_31512;
    goto v_31497;
v_31498:
    v_31512 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31499;
v_31500:
    goto v_31496;
v_31497:
    goto v_31498;
v_31499:
    if (v_31513 == v_31512) goto v_31494;
    else goto v_31495;
v_31494:
    v_31512 = lisp_true;
    goto v_31493;
v_31495:
    v_31512 = nil;
    goto v_31493;
v_31493:
    goto v_31379;
v_31381:
    v_31512 = nil;
    goto v_31379;
v_31379:
    return onevalue(v_31512);
}



// Code for talp_try2

static LispObject CC_talp_try2(LispObject env,
                         LispObject v_31365)
{
    env = qenv(env);
    LispObject v_31400, v_31401;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31365);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31365;
// end of prologue
    v_31400 = stack[0];
    fn = elt(env, 1); // cl_bvarl
    v_31400 = (*qfn1(fn))(fn, v_31400);
    env = stack[-2];
    stack[-1] = v_31400;
    v_31400 = stack[0];
    fn = elt(env, 2); // cl_fvarl
    v_31400 = (*qfn1(fn))(fn, v_31400);
    env = stack[-2];
    goto v_31381;
v_31377:
    v_31401 = stack[-1];
    goto v_31378;
v_31379:
    goto v_31380;
v_31381:
    goto v_31377;
v_31378:
    goto v_31379;
v_31380:
    v_31400 = Lappend(nil, v_31401, v_31400);
    env = stack[-2];
    v_31401 = v_31400;
    if (v_31401 == nil) goto v_31387;
    goto v_31394;
v_31390:
    v_31401 = stack[0];
    goto v_31391;
v_31392:
    goto v_31393;
v_31394:
    goto v_31390;
v_31391:
    goto v_31392;
v_31393:
    {
        fn = elt(env, 3); // talp_try3
        return (*qfn2(fn))(fn, v_31401, v_31400);
    }
v_31387:
    v_31400 = stack[0];
    goto v_31385;
    v_31400 = nil;
v_31385:
    return onevalue(v_31400);
}



// Code for ofsf_simpat

static LispObject CC_ofsf_simpat(LispObject env,
                         LispObject v_31365)
{
    env = qenv(env);
    LispObject v_31647, v_31648, v_31649;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31365);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_31365;
// end of prologue
    v_31647 = stack[-2];
    v_31647 = qcar(v_31647);
    stack[-3] = v_31647;
    v_31647 = stack[-2];
    v_31647 = qcdr(v_31647);
    v_31647 = qcar(v_31647);
    fn = elt(env, 9); // simp
    v_31647 = (*qfn1(fn))(fn, v_31647);
    env = stack[-4];
    stack[-1] = v_31647;
    v_31647 = qvalue(elt(env, 1)); // !*rlnzden
    if (v_31647 == nil) goto v_31384;
    else goto v_31383;
v_31384:
    v_31647 = qvalue(elt(env, 2)); // !*rlposden
    if (v_31647 == nil) goto v_31387;
    else goto v_31383;
v_31387:
    v_31647 = stack[-1];
    v_31647 = qcdr(v_31647);
    if (!consp(v_31647)) goto v_31392;
    else goto v_31393;
v_31392:
    v_31647 = lisp_true;
    goto v_31391;
v_31393:
    v_31647 = stack[-1];
    v_31647 = qcdr(v_31647);
    v_31647 = qcar(v_31647);
    v_31647 = (consp(v_31647) ? nil : lisp_true);
    goto v_31391;
    v_31647 = nil;
v_31391:
    if (v_31647 == nil) goto v_31389;
    else goto v_31383;
v_31389:
    goto v_31408;
v_31404:
    v_31648 = stack[-2];
    goto v_31405;
v_31406:
    v_31647 = elt(env, 3); // "atomic formula"
    goto v_31407;
v_31408:
    goto v_31404;
v_31405:
    goto v_31406;
v_31407:
    fn = elt(env, 10); // typerr
    v_31647 = (*qfn2(fn))(fn, v_31648, v_31647);
    env = stack[-4];
    goto v_31381;
v_31383:
v_31381:
    v_31647 = stack[-2];
    v_31647 = qcdr(v_31647);
    v_31647 = qcdr(v_31647);
    v_31647 = qcar(v_31647);
    fn = elt(env, 9); // simp
    v_31647 = (*qfn1(fn))(fn, v_31647);
    env = stack[-4];
    stack[0] = v_31647;
    v_31647 = qvalue(elt(env, 1)); // !*rlnzden
    if (v_31647 == nil) goto v_31420;
    else goto v_31419;
v_31420:
    v_31647 = qvalue(elt(env, 2)); // !*rlposden
    if (v_31647 == nil) goto v_31423;
    else goto v_31419;
v_31423:
    v_31647 = stack[0];
    v_31647 = qcdr(v_31647);
    if (!consp(v_31647)) goto v_31428;
    else goto v_31429;
v_31428:
    v_31647 = lisp_true;
    goto v_31427;
v_31429:
    v_31647 = stack[0];
    v_31647 = qcdr(v_31647);
    v_31647 = qcar(v_31647);
    v_31647 = (consp(v_31647) ? nil : lisp_true);
    goto v_31427;
    v_31647 = nil;
v_31427:
    if (v_31647 == nil) goto v_31425;
    else goto v_31419;
v_31425:
    goto v_31444;
v_31440:
    v_31648 = stack[-2];
    goto v_31441;
v_31442:
    v_31647 = elt(env, 3); // "atomic formula"
    goto v_31443;
v_31444:
    goto v_31440;
v_31441:
    goto v_31442;
v_31443:
    fn = elt(env, 10); // typerr
    v_31647 = (*qfn2(fn))(fn, v_31648, v_31647);
    env = stack[-4];
    goto v_31417;
v_31419:
v_31417:
    goto v_31452;
v_31448:
    goto v_31449;
v_31450:
    v_31647 = stack[0];
    fn = elt(env, 11); // negsq
    v_31647 = (*qfn1(fn))(fn, v_31647);
    env = stack[-4];
    goto v_31451;
v_31452:
    goto v_31448;
v_31449:
    goto v_31450;
v_31451:
    fn = elt(env, 12); // addsq
    v_31647 = (*qfn2(fn))(fn, stack[-1], v_31647);
    env = stack[-4];
    stack[-1] = v_31647;
    v_31647 = stack[-1];
    v_31647 = qcar(v_31647);
    v_31648 = v_31647;
    v_31647 = qvalue(elt(env, 2)); // !*rlposden
    if (v_31647 == nil) goto v_31461;
    v_31647 = stack[-1];
    v_31647 = qcdr(v_31647);
    if (!consp(v_31647)) goto v_31467;
    else goto v_31468;
v_31467:
    v_31647 = lisp_true;
    goto v_31466;
v_31468:
    v_31647 = stack[-1];
    v_31647 = qcdr(v_31647);
    v_31647 = qcar(v_31647);
    v_31647 = (consp(v_31647) ? nil : lisp_true);
    goto v_31466;
    v_31647 = nil;
v_31466:
    if (v_31647 == nil) goto v_31464;
    else goto v_31461;
v_31464:
    goto v_31485;
v_31479:
    v_31649 = stack[-3];
    goto v_31480;
v_31481:
    goto v_31482;
v_31483:
    v_31647 = nil;
    goto v_31484;
v_31485:
    goto v_31479;
v_31480:
    goto v_31481;
v_31482:
    goto v_31483;
v_31484:
    v_31647 = list3(v_31649, v_31648, v_31647);
    env = stack[-4];
    stack[0] = v_31647;
    v_31647 = qvalue(elt(env, 4)); // !*rladdcond
    if (v_31647 == nil) goto v_31492;
    goto v_31502;
v_31498:
    v_31648 = stack[-3];
    goto v_31499;
v_31500:
    v_31647 = elt(env, 5); // (lessp leq greaterp geq)
    goto v_31501;
v_31502:
    goto v_31498;
v_31499:
    goto v_31500;
v_31501:
    v_31647 = Lmemq(nil, v_31648, v_31647);
    if (v_31647 == nil) goto v_31497;
    goto v_31513;
v_31507:
    stack[-2] = elt(env, 6); // and
    goto v_31508;
v_31509:
    goto v_31522;
v_31516:
    v_31649 = elt(env, 7); // greaterp
    goto v_31517;
v_31518:
    v_31647 = stack[-1];
    v_31648 = qcdr(v_31647);
    goto v_31519;
v_31520:
    v_31647 = nil;
    goto v_31521;
v_31522:
    goto v_31516;
v_31517:
    goto v_31518;
v_31519:
    goto v_31520;
v_31521:
    stack[-1] = list3(v_31649, v_31648, v_31647);
    env = stack[-4];
    goto v_31510;
v_31511:
    v_31647 = stack[0];
    v_31647 = ncons(v_31647);
    env = stack[-4];
    goto v_31512;
v_31513:
    goto v_31507;
v_31508:
    goto v_31509;
v_31510:
    goto v_31511;
v_31512:
    v_31647 = list2star(stack[-2], stack[-1], v_31647);
    goto v_31495;
v_31497:
    goto v_31538;
v_31532:
    stack[-2] = elt(env, 6); // and
    goto v_31533;
v_31534:
    goto v_31547;
v_31541:
    v_31649 = elt(env, 8); // neq
    goto v_31542;
v_31543:
    v_31647 = stack[-1];
    v_31648 = qcdr(v_31647);
    goto v_31544;
v_31545:
    v_31647 = nil;
    goto v_31546;
v_31547:
    goto v_31541;
v_31542:
    goto v_31543;
v_31544:
    goto v_31545;
v_31546:
    stack[-1] = list3(v_31649, v_31648, v_31647);
    env = stack[-4];
    goto v_31535;
v_31536:
    v_31647 = stack[0];
    v_31647 = ncons(v_31647);
    env = stack[-4];
    goto v_31537;
v_31538:
    goto v_31532;
v_31533:
    goto v_31534;
v_31535:
    goto v_31536;
v_31537:
    v_31647 = list2star(stack[-2], stack[-1], v_31647);
    goto v_31495;
    v_31647 = nil;
v_31495:
    stack[0] = v_31647;
    goto v_31490;
v_31492:
v_31490:
    v_31647 = stack[0];
    goto v_31373;
v_31461:
    v_31647 = qvalue(elt(env, 1)); // !*rlnzden
    if (v_31647 == nil) goto v_31558;
    v_31647 = stack[-1];
    v_31647 = qcdr(v_31647);
    if (!consp(v_31647)) goto v_31564;
    else goto v_31565;
v_31564:
    v_31647 = lisp_true;
    goto v_31563;
v_31565:
    v_31647 = stack[-1];
    v_31647 = qcdr(v_31647);
    v_31647 = qcar(v_31647);
    v_31647 = (consp(v_31647) ? nil : lisp_true);
    goto v_31563;
    v_31647 = nil;
v_31563:
    if (v_31647 == nil) goto v_31561;
    else goto v_31558;
v_31561:
    goto v_31583;
v_31579:
    v_31649 = stack[-3];
    goto v_31580;
v_31581:
    v_31647 = elt(env, 5); // (lessp leq greaterp geq)
    goto v_31582;
v_31583:
    goto v_31579;
v_31580:
    goto v_31581;
v_31582:
    v_31647 = Lmemq(nil, v_31649, v_31647);
    if (v_31647 == nil) goto v_31578;
    goto v_31592;
v_31588:
    goto v_31589;
v_31590:
    v_31647 = stack[-1];
    v_31647 = qcdr(v_31647);
    goto v_31591;
v_31592:
    goto v_31588;
v_31589:
    goto v_31590;
v_31591:
    fn = elt(env, 13); // multf
    v_31647 = (*qfn2(fn))(fn, v_31648, v_31647);
    env = stack[-4];
    v_31648 = v_31647;
    goto v_31576;
v_31578:
v_31576:
    goto v_31603;
v_31597:
    v_31649 = stack[-3];
    goto v_31598;
v_31599:
    goto v_31600;
v_31601:
    v_31647 = nil;
    goto v_31602;
v_31603:
    goto v_31597;
v_31598:
    goto v_31599;
v_31600:
    goto v_31601;
v_31602:
    v_31647 = list3(v_31649, v_31648, v_31647);
    env = stack[-4];
    stack[0] = v_31647;
    v_31647 = qvalue(elt(env, 4)); // !*rladdcond
    if (v_31647 == nil) goto v_31610;
    goto v_31619;
v_31613:
    stack[-2] = elt(env, 6); // and
    goto v_31614;
v_31615:
    goto v_31628;
v_31622:
    v_31649 = elt(env, 8); // neq
    goto v_31623;
v_31624:
    v_31647 = stack[-1];
    v_31648 = qcdr(v_31647);
    goto v_31625;
v_31626:
    v_31647 = nil;
    goto v_31627;
v_31628:
    goto v_31622;
v_31623:
    goto v_31624;
v_31625:
    goto v_31626;
v_31627:
    stack[-1] = list3(v_31649, v_31648, v_31647);
    env = stack[-4];
    goto v_31616;
v_31617:
    v_31647 = stack[0];
    v_31647 = ncons(v_31647);
    env = stack[-4];
    goto v_31618;
v_31619:
    goto v_31613;
v_31614:
    goto v_31615;
v_31616:
    goto v_31617;
v_31618:
    v_31647 = list2star(stack[-2], stack[-1], v_31647);
    stack[0] = v_31647;
    goto v_31608;
v_31610:
v_31608:
    v_31647 = stack[0];
    goto v_31373;
v_31558:
    goto v_31643;
v_31637:
    v_31649 = stack[-3];
    goto v_31638;
v_31639:
    goto v_31640;
v_31641:
    v_31647 = nil;
    goto v_31642;
v_31643:
    goto v_31637;
v_31638:
    goto v_31639;
v_31640:
    goto v_31641;
v_31642:
    return list3(v_31649, v_31648, v_31647);
v_31373:
    return onevalue(v_31647);
}



// Code for quotfx1

static LispObject CC_quotfx1(LispObject env,
                         LispObject v_31365, LispObject v_31366)
{
    env = qenv(env);
    LispObject v_31745, v_31746, v_31747, v_31748;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31366,v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31365,v_31366);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-7] = v_31366;
    stack[-8] = v_31365;
// end of prologue
    v_31745 = stack[-8];
    if (v_31745 == nil) goto v_31370;
    else goto v_31371;
v_31370:
    goto v_31378;
v_31374:
    v_31746 = stack[-8];
    goto v_31375;
v_31376:
    v_31745 = stack[-7];
    goto v_31377;
v_31378:
    goto v_31374;
v_31375:
    goto v_31376;
v_31377:
    {
        fn = elt(env, 1); // quotfxerr
        return (*qfn2(fn))(fn, v_31746, v_31745);
    }
v_31371:
    goto v_31387;
v_31383:
    v_31746 = stack[-8];
    goto v_31384;
v_31385:
    v_31745 = stack[-7];
    goto v_31386;
v_31387:
    goto v_31383;
v_31384:
    goto v_31385;
v_31386:
    if (equal(v_31746, v_31745)) goto v_31381;
    else goto v_31382;
v_31381:
    v_31745 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31369;
v_31382:
    goto v_31397;
v_31393:
    v_31746 = stack[-7];
    goto v_31394;
v_31395:
    v_31745 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31396;
v_31397:
    goto v_31393;
v_31394:
    goto v_31395;
v_31396:
    if (v_31746 == v_31745) goto v_31391;
    else goto v_31392;
v_31391:
    v_31745 = stack[-8];
    goto v_31369;
v_31392:
    v_31745 = stack[-7];
    if (!consp(v_31745)) goto v_31405;
    else goto v_31406;
v_31405:
    v_31745 = lisp_true;
    goto v_31404;
v_31406:
    v_31745 = stack[-7];
    v_31745 = qcar(v_31745);
    v_31745 = (consp(v_31745) ? nil : lisp_true);
    goto v_31404;
    v_31745 = nil;
v_31404:
    if (v_31745 == nil) goto v_31402;
    goto v_31419;
v_31415:
    v_31746 = stack[-8];
    goto v_31416;
v_31417:
    v_31745 = stack[-7];
    goto v_31418;
v_31419:
    goto v_31415;
v_31416:
    goto v_31417;
v_31418:
    {
        fn = elt(env, 2); // quotfdx
        return (*qfn2(fn))(fn, v_31746, v_31745);
    }
v_31402:
    v_31745 = stack[-8];
    if (!consp(v_31745)) goto v_31426;
    else goto v_31427;
v_31426:
    v_31745 = lisp_true;
    goto v_31425;
v_31427:
    v_31745 = stack[-8];
    v_31745 = qcar(v_31745);
    v_31745 = (consp(v_31745) ? nil : lisp_true);
    goto v_31425;
    v_31745 = nil;
v_31425:
    if (v_31745 == nil) goto v_31423;
    goto v_31440;
v_31436:
    v_31746 = stack[-8];
    goto v_31437;
v_31438:
    v_31745 = stack[-7];
    goto v_31439;
v_31440:
    goto v_31436;
v_31437:
    goto v_31438;
v_31439:
    {
        fn = elt(env, 1); // quotfxerr
        return (*qfn2(fn))(fn, v_31746, v_31745);
    }
v_31423:
    goto v_31449;
v_31445:
    v_31745 = stack[-8];
    v_31745 = qcar(v_31745);
    v_31745 = qcar(v_31745);
    v_31746 = qcar(v_31745);
    goto v_31446;
v_31447:
    v_31745 = stack[-7];
    v_31745 = qcar(v_31745);
    v_31745 = qcar(v_31745);
    v_31745 = qcar(v_31745);
    goto v_31448;
v_31449:
    goto v_31445;
v_31446:
    goto v_31447;
v_31448:
    if (v_31746 == v_31745) goto v_31443;
    else goto v_31444;
v_31443:
    stack[-9] = nil;
    stack[-1] = nil;
    v_31745 = stack[-7];
    v_31745 = qcar(v_31745);
    v_31745 = qcar(v_31745);
    v_31745 = qcdr(v_31745);
    stack[-5] = v_31745;
v_31470:
    goto v_31489;
v_31485:
    v_31745 = stack[-8];
    v_31745 = qcar(v_31745);
    v_31745 = qcar(v_31745);
    v_31746 = qcdr(v_31745);
    stack[-6] = v_31746;
    goto v_31486;
v_31487:
    v_31745 = stack[-5];
    goto v_31488;
v_31489:
    goto v_31485;
v_31486:
    goto v_31487;
v_31488:
    v_31745 = (LispObject)lessp2(v_31746, v_31745);
    v_31745 = v_31745 ? lisp_true : nil;
    env = stack[-10];
    if (v_31745 == nil) goto v_31483;
    goto v_31500;
v_31496:
    v_31746 = stack[-8];
    goto v_31497;
v_31498:
    v_31745 = stack[-7];
    goto v_31499;
v_31500:
    goto v_31496;
v_31497:
    goto v_31498;
v_31499:
    {
        fn = elt(env, 1); // quotfxerr
        return (*qfn2(fn))(fn, v_31746, v_31745);
    }
v_31483:
    v_31745 = stack[-8];
    fn = elt(env, 3); // lt!*
    v_31745 = (*qfn1(fn))(fn, v_31745);
    env = stack[-10];
    stack[0] = v_31745;
    v_31745 = stack[-7];
    fn = elt(env, 3); // lt!*
    v_31745 = (*qfn1(fn))(fn, v_31745);
    env = stack[-10];
    v_31746 = stack[-7];
    v_31746 = qcar(v_31746);
    v_31746 = qcar(v_31746);
    v_31746 = qcar(v_31746);
    stack[-4] = v_31746;
    goto v_31516;
v_31512:
    v_31746 = stack[0];
    v_31746 = qcdr(v_31746);
    goto v_31513;
v_31514:
    v_31745 = qcdr(v_31745);
    goto v_31515;
v_31516:
    goto v_31512;
v_31513:
    goto v_31514;
v_31515:
    v_31745 = CC_quotfx1(elt(env, 0), v_31746, v_31745);
    env = stack[-10];
    stack[-3] = v_31745;
    goto v_31525;
v_31521:
    v_31746 = stack[-6];
    goto v_31522;
v_31523:
    v_31745 = stack[-5];
    goto v_31524;
v_31525:
    goto v_31521;
v_31522:
    goto v_31523;
v_31524:
    v_31745 = (LispObject)(intptr_t)((intptr_t)v_31746 - (intptr_t)v_31745 + TAG_FIXNUM);
    stack[0] = v_31745;
    goto v_31537;
v_31533:
    v_31746 = stack[0];
    goto v_31534;
v_31535:
    v_31745 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31536;
v_31537:
    goto v_31533;
v_31534:
    goto v_31535;
v_31536:
    if (v_31746 == v_31745) goto v_31531;
    else goto v_31532;
v_31531:
    goto v_31545;
v_31541:
    v_31746 = stack[-1];
    goto v_31542;
v_31543:
    v_31745 = stack[-3];
    goto v_31544;
v_31545:
    goto v_31541;
v_31542:
    goto v_31543;
v_31544:
    {
        fn = elt(env, 4); // rnconc
        return (*qfn2(fn))(fn, v_31746, v_31745);
    }
v_31532:
    goto v_31553;
v_31549:
    v_31746 = stack[-4];
    goto v_31550;
v_31551:
    v_31745 = stack[0];
    goto v_31552;
v_31553:
    goto v_31549;
v_31550:
    goto v_31551;
v_31552:
    fn = elt(env, 5); // to
    v_31745 = (*qfn2(fn))(fn, v_31746, v_31745);
    env = stack[-10];
    stack[-2] = v_31745;
    v_31745 = stack[-9];
    if (v_31745 == nil) goto v_31558;
    else goto v_31559;
v_31558:
    goto v_31568;
v_31562:
    v_31748 = stack[-8];
    goto v_31563;
v_31564:
    v_31747 = stack[-4];
    goto v_31565;
v_31566:
    goto v_31575;
v_31571:
    v_31746 = stack[-6];
    goto v_31572;
v_31573:
    v_31745 = stack[0];
    goto v_31574;
v_31575:
    goto v_31571;
v_31572:
    goto v_31573;
v_31574:
    v_31745 = (LispObject)(intptr_t)((intptr_t)v_31746 - (intptr_t)v_31745 + TAG_FIXNUM);
    v_31745 = (LispObject)((intptr_t)(v_31745) - 0x10);
    goto v_31567;
v_31568:
    goto v_31562;
v_31563:
    goto v_31564;
v_31565:
    goto v_31566;
v_31567:
    fn = elt(env, 6); // cutf
    v_31745 = (*qfnn(fn))(fn, 3, v_31748, v_31747, v_31745);
    env = stack[-10];
    stack[-8] = v_31745;
    goto v_31557;
v_31559:
v_31557:
    v_31745 = lisp_true;
    stack[-9] = v_31745;
    goto v_31588;
v_31582:
    v_31748 = stack[-7];
    goto v_31583;
v_31584:
    v_31747 = stack[-4];
    goto v_31585;
v_31586:
    goto v_31595;
v_31591:
    v_31746 = stack[-5];
    goto v_31592;
v_31593:
    v_31745 = stack[0];
    goto v_31594;
v_31595:
    goto v_31591;
v_31592:
    goto v_31593;
v_31594:
    v_31745 = (LispObject)(intptr_t)((intptr_t)v_31746 - (intptr_t)v_31745 + TAG_FIXNUM);
    v_31745 = (LispObject)((intptr_t)(v_31745) - 0x10);
    goto v_31587;
v_31588:
    goto v_31582;
v_31583:
    goto v_31584;
v_31585:
    goto v_31586;
v_31587:
    fn = elt(env, 6); // cutf
    v_31745 = (*qfnn(fn))(fn, 3, v_31748, v_31747, v_31745);
    env = stack[-10];
    stack[-7] = v_31745;
    goto v_31605;
v_31601:
    stack[-6] = stack[-8];
    goto v_31602;
v_31603:
    goto v_31612;
v_31608:
    goto v_31621;
v_31617:
    v_31746 = stack[0];
    goto v_31618;
v_31619:
    v_31745 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31620;
v_31621:
    goto v_31617;
v_31618:
    goto v_31619;
v_31620:
    if (v_31746 == v_31745) goto v_31615;
    else goto v_31616;
v_31615:
    v_31745 = stack[-7];
    stack[0] = v_31745;
    goto v_31614;
v_31616:
    goto v_31632;
v_31628:
    goto v_31639;
v_31635:
    v_31746 = stack[-2];
    goto v_31636;
v_31637:
    v_31745 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31638;
v_31639:
    goto v_31635;
v_31636:
    goto v_31637;
v_31638:
    v_31745 = cons(v_31746, v_31745);
    env = stack[-10];
    v_31746 = ncons(v_31745);
    env = stack[-10];
    goto v_31629;
v_31630:
    v_31745 = stack[-7];
    goto v_31631;
v_31632:
    goto v_31628;
v_31629:
    goto v_31630;
v_31631:
    fn = elt(env, 7); // multf
    v_31745 = (*qfn2(fn))(fn, v_31746, v_31745);
    env = stack[-10];
    stack[0] = v_31745;
    goto v_31614;
    stack[0] = nil;
v_31614:
    goto v_31609;
v_31610:
    v_31745 = stack[-3];
    fn = elt(env, 8); // negf
    v_31745 = (*qfn1(fn))(fn, v_31745);
    env = stack[-10];
    goto v_31611;
v_31612:
    goto v_31608;
v_31609:
    goto v_31610;
v_31611:
    fn = elt(env, 7); // multf
    v_31745 = (*qfn2(fn))(fn, stack[0], v_31745);
    env = stack[-10];
    goto v_31604;
v_31605:
    goto v_31601;
v_31602:
    goto v_31603;
v_31604:
    fn = elt(env, 9); // addf
    v_31745 = (*qfn2(fn))(fn, stack[-6], v_31745);
    env = stack[-10];
    stack[-8] = v_31745;
    v_31745 = stack[-8];
    if (v_31745 == nil) goto v_31648;
    v_31745 = stack[-8];
    if (!consp(v_31745)) goto v_31658;
    else goto v_31659;
v_31658:
    v_31745 = lisp_true;
    goto v_31657;
v_31659:
    v_31745 = stack[-8];
    v_31745 = qcar(v_31745);
    v_31745 = (consp(v_31745) ? nil : lisp_true);
    goto v_31657;
    v_31745 = nil;
v_31657:
    if (v_31745 == nil) goto v_31655;
    v_31745 = lisp_true;
    goto v_31653;
v_31655:
    goto v_31674;
v_31670:
    v_31745 = stack[-8];
    v_31745 = qcar(v_31745);
    v_31745 = qcar(v_31745);
    v_31746 = qcar(v_31745);
    goto v_31671;
v_31672:
    v_31745 = stack[-4];
    goto v_31673;
v_31674:
    goto v_31670;
v_31671:
    goto v_31672;
v_31673:
    v_31745 = (v_31746 == v_31745 ? lisp_true : nil);
    v_31745 = (v_31745 == nil ? lisp_true : nil);
    goto v_31653;
    v_31745 = nil;
v_31653:
    if (v_31745 == nil) goto v_31648;
    goto v_31687;
v_31683:
    v_31746 = stack[-8];
    goto v_31684;
v_31685:
    v_31745 = stack[-7];
    goto v_31686;
v_31687:
    goto v_31683;
v_31684:
    goto v_31685;
v_31686:
    {
        fn = elt(env, 1); // quotfxerr
        return (*qfn2(fn))(fn, v_31746, v_31745);
    }
v_31648:
    goto v_31695;
v_31691:
    stack[0] = stack[-1];
    goto v_31692;
v_31693:
    goto v_31702;
v_31698:
    v_31746 = stack[-2];
    goto v_31699;
v_31700:
    v_31745 = stack[-3];
    goto v_31701;
v_31702:
    goto v_31698;
v_31699:
    goto v_31700;
v_31701:
    v_31745 = cons(v_31746, v_31745);
    env = stack[-10];
    goto v_31694;
v_31695:
    goto v_31691;
v_31692:
    goto v_31693;
v_31694:
    fn = elt(env, 10); // aconc!*
    v_31745 = (*qfn2(fn))(fn, stack[0], v_31745);
    env = stack[-10];
    stack[-1] = v_31745;
    v_31745 = stack[-8];
    if (v_31745 == nil) goto v_31707;
    else goto v_31708;
v_31707:
    v_31745 = stack[-1];
    goto v_31469;
v_31708:
    goto v_31470;
v_31469:
    goto v_31369;
v_31444:
    goto v_31718;
v_31714:
    v_31745 = stack[-8];
    v_31745 = qcar(v_31745);
    v_31745 = qcar(v_31745);
    v_31746 = qcar(v_31745);
    goto v_31715;
v_31716:
    v_31745 = stack[-7];
    v_31745 = qcar(v_31745);
    v_31745 = qcar(v_31745);
    v_31745 = qcar(v_31745);
    goto v_31717;
v_31718:
    goto v_31714;
v_31715:
    goto v_31716;
v_31717:
    fn = elt(env, 11); // ordop
    v_31745 = (*qfn2(fn))(fn, v_31746, v_31745);
    env = stack[-10];
    if (v_31745 == nil) goto v_31712;
    goto v_31732;
v_31728:
    v_31746 = stack[-8];
    goto v_31729;
v_31730:
    v_31745 = stack[-7];
    goto v_31731;
v_31732:
    goto v_31728;
v_31729:
    goto v_31730;
v_31731:
    {
        fn = elt(env, 12); // quotkx
        return (*qfn2(fn))(fn, v_31746, v_31745);
    }
v_31712:
    goto v_31742;
v_31738:
    v_31746 = stack[-8];
    goto v_31739;
v_31740:
    v_31745 = stack[-7];
    goto v_31741;
v_31742:
    goto v_31738;
v_31739:
    goto v_31740;
v_31741:
    {
        fn = elt(env, 1); // quotfxerr
        return (*qfn2(fn))(fn, v_31746, v_31745);
    }
    v_31745 = nil;
v_31369:
    return onevalue(v_31745);
}



// Code for sfto_dprpartf1

static LispObject CC_sfto_dprpartf1(LispObject env,
                         LispObject v_31365, LispObject v_31366)
{
    env = qenv(env);
    LispObject v_31388, v_31389;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31366,v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31365,v_31366);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31388 = v_31366;
    v_31389 = v_31365;
// end of prologue
    goto v_31373;
v_31369:
    goto v_31370;
v_31371:
    goto v_31372;
v_31373:
    goto v_31369;
v_31370:
    goto v_31371;
v_31372:
    fn = elt(env, 1); // quotf
    v_31388 = (*qfn2(fn))(fn, v_31389, v_31388);
    env = stack[-1];
    stack[0] = v_31388;
    v_31388 = stack[0];
    fn = elt(env, 2); // minusf
    v_31388 = (*qfn1(fn))(fn, v_31388);
    env = stack[-1];
    if (v_31388 == nil) goto v_31380;
    v_31388 = stack[0];
    {
        fn = elt(env, 3); // negf
        return (*qfn1(fn))(fn, v_31388);
    }
v_31380:
    v_31388 = stack[0];
    goto v_31378;
    v_31388 = nil;
v_31378:
    return onevalue(v_31388);
}



// Code for parseml

static LispObject CC_parseml(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31427, v_31428;
    LispObject fn;
    argcheck(nargs, 0, "parseml");
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
    v_31427 = nil;
    stack[0] = v_31427;
    v_31427 = (LispObject)512+TAG_FIXNUM; // 32
    v_31427 = ncons(v_31427);
    env = stack[-1];
    fn = elt(env, 10); // list2string
    v_31427 = (*qfn1(fn))(fn, v_31427);
    env = stack[-1];
    v_31427 = Lintern(nil, v_31427);
    env = stack[-1];
    qvalue(elt(env, 1)) = v_31427; // space
    v_31427 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 2)) = v_31427; // count
    v_31427 = Lreadch(nil, 0);
    env = stack[-1];
    qvalue(elt(env, 3)) = v_31427; // ch
    v_31427 = nil;
    qvalue(elt(env, 4)) = v_31427; // temp2
    fn = elt(env, 11); // lex
    v_31427 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_31388;
v_31384:
    v_31428 = qvalue(elt(env, 5)); // char
    goto v_31385;
v_31386:
    v_31427 = elt(env, 6); // (m a t h)
    goto v_31387;
v_31388:
    goto v_31384;
v_31385:
    goto v_31386;
v_31387:
    if (equal(v_31428, v_31427)) goto v_31382;
    else goto v_31383;
v_31382:
    fn = elt(env, 12); // mathml
    v_31427 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_31427;
    goto v_31381;
v_31383:
    goto v_31399;
v_31395:
    v_31428 = elt(env, 7); // "<math>"
    goto v_31396;
v_31397:
    v_31427 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31398;
v_31399:
    goto v_31395;
v_31396:
    goto v_31397;
v_31398:
    fn = elt(env, 13); // errorml
    v_31427 = (*qfn2(fn))(fn, v_31428, v_31427);
    env = stack[-1];
    goto v_31381;
v_31381:
    fn = elt(env, 11); // lex
    v_31427 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_31411;
v_31407:
    v_31428 = qvalue(elt(env, 5)); // char
    goto v_31408;
v_31409:
    v_31427 = elt(env, 8); // (!/ m a t h)
    goto v_31410;
v_31411:
    goto v_31407;
v_31408:
    goto v_31409;
v_31410:
    if (equal(v_31428, v_31427)) goto v_31405;
    else goto v_31406;
v_31405:
    v_31427 = Lterpri(nil, 0);
    env = stack[-1];
    goto v_31404;
v_31406:
    goto v_31422;
v_31418:
    v_31428 = elt(env, 9); // "</math>"
    goto v_31419;
v_31420:
    v_31427 = (LispObject)304+TAG_FIXNUM; // 19
    goto v_31421;
v_31422:
    goto v_31418;
v_31419:
    goto v_31420;
v_31421:
    fn = elt(env, 13); // errorml
    v_31427 = (*qfn2(fn))(fn, v_31428, v_31427);
    env = stack[-1];
    goto v_31404;
v_31404:
    v_31427 = stack[0];
    {
        fn = elt(env, 14); // aeval
        return (*qfn1(fn))(fn, v_31427);
    }
    return onevalue(v_31427);
}



// Code for ldf!-pow!-var

static LispObject CC_ldfKpowKvar(LispObject env,
                         LispObject v_31365)
{
    env = qenv(env);
    LispObject v_31452, v_31453, v_31454;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31365);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_31452 = v_31365;
// end of prologue
    v_31453 = nil;
    stack[-2] = nil;
    stack[-1] = v_31452;
v_31374:
    v_31452 = stack[-1];
    if (v_31452 == nil) goto v_31378;
    else goto v_31379;
v_31378:
    goto v_31373;
v_31379:
    v_31452 = stack[-1];
    v_31452 = qcar(v_31452);
    goto v_31390;
v_31386:
    stack[0] = v_31453;
    goto v_31387;
v_31388:
    v_31452 = qcdr(v_31452);
    fn = elt(env, 3); // kernels
    v_31452 = (*qfn1(fn))(fn, v_31452);
    env = stack[-3];
    goto v_31389;
v_31390:
    goto v_31386;
v_31387:
    goto v_31388;
v_31389:
    v_31452 = Lappend(nil, stack[0], v_31452);
    env = stack[-3];
    v_31453 = v_31452;
    v_31452 = stack[-1];
    v_31452 = qcdr(v_31452);
    stack[-1] = v_31452;
    goto v_31374;
v_31373:
    v_31452 = v_31453;
    fn = elt(env, 4); // makeset
    v_31452 = (*qfn1(fn))(fn, v_31452);
    env = stack[-3];
    fn = elt(env, 5); // prlist
    v_31452 = (*qfn1(fn))(fn, v_31452);
    env = stack[-3];
    stack[0] = v_31452;
v_31400:
    v_31452 = stack[0];
    if (v_31452 == nil) goto v_31406;
    else goto v_31407;
v_31406:
    goto v_31399;
v_31407:
    v_31452 = stack[0];
    v_31452 = qcar(v_31452);
    v_31454 = v_31452;
    goto v_31426;
v_31422:
    v_31453 = v_31454;
    goto v_31423;
v_31424:
    v_31452 = elt(env, 1); // x
    goto v_31425;
v_31426:
    goto v_31422;
v_31423:
    goto v_31424;
v_31425:
    if (!consp(v_31453)) goto v_31420;
    v_31453 = qcar(v_31453);
    if (v_31453 == v_31452) goto v_31419;
    else goto v_31420;
v_31419:
    v_31452 = lisp_true;
    goto v_31418;
v_31420:
    goto v_31437;
v_31433:
    v_31453 = v_31454;
    goto v_31434;
v_31435:
    v_31452 = elt(env, 2); // u
    goto v_31436;
v_31437:
    goto v_31433;
v_31434:
    goto v_31435;
v_31436:
    v_31452 = Leqcar(nil, v_31453, v_31452);
    env = stack[-3];
    goto v_31418;
    v_31452 = nil;
v_31418:
    if (v_31452 == nil) goto v_31416;
    goto v_31445;
v_31441:
    v_31453 = v_31454;
    goto v_31442;
v_31443:
    v_31452 = stack[-2];
    goto v_31444;
v_31445:
    goto v_31441;
v_31442:
    goto v_31443;
v_31444:
    v_31452 = cons(v_31453, v_31452);
    env = stack[-3];
    stack[-2] = v_31452;
    goto v_31414;
v_31416:
v_31414:
    v_31452 = stack[0];
    v_31452 = qcdr(v_31452);
    stack[0] = v_31452;
    goto v_31400;
v_31399:
    v_31452 = stack[-2];
    {
        fn = elt(env, 4); // makeset
        return (*qfn1(fn))(fn, v_31452);
    }
    return onevalue(v_31452);
}



// Code for vdpappendmon

static LispObject CC_vdpappendmon(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31449, v_31450, v_31451;
    LispObject fn;
    LispObject v_31367, v_31366, v_31365;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "vdpappendmon");
    va_start(aa, nargs);
    v_31365 = va_arg(aa, LispObject);
    v_31366 = va_arg(aa, LispObject);
    v_31367 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31367,v_31366,v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31365,v_31366,v_31367);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_31367;
    stack[-3] = v_31366;
    stack[-4] = v_31365;
// end of prologue
    v_31449 = stack[-4];
    if (v_31449 == nil) goto v_31375;
    else goto v_31376;
v_31375:
    v_31449 = lisp_true;
    goto v_31374;
v_31376:
    v_31449 = stack[-4];
    v_31449 = qcdr(v_31449);
    v_31449 = qcdr(v_31449);
    v_31449 = qcdr(v_31449);
    v_31449 = qcar(v_31449);
    v_31449 = (v_31449 == nil ? lisp_true : nil);
    goto v_31374;
    v_31449 = nil;
v_31374:
    if (v_31449 == nil) goto v_31372;
    goto v_31392;
v_31388:
    v_31450 = stack[-3];
    goto v_31389;
v_31390:
    v_31449 = stack[-2];
    goto v_31391;
v_31392:
    goto v_31388;
v_31389:
    goto v_31390;
v_31391:
    {
        fn = elt(env, 2); // vdpfmon
        return (*qfn2(fn))(fn, v_31450, v_31449);
    }
v_31372:
    v_31449 = stack[-3];
    fn = elt(env, 3); // vbczero!?
    v_31449 = (*qfn1(fn))(fn, v_31449);
    env = stack[-6];
    if (v_31449 == nil) goto v_31396;
    v_31449 = stack[-4];
    goto v_31370;
v_31396:
    goto v_31411;
v_31403:
    stack[-5] = elt(env, 1); // vdp
    goto v_31404;
v_31405:
    v_31449 = stack[-4];
    v_31449 = qcdr(v_31449);
    stack[-1] = qcar(v_31449);
    goto v_31406;
v_31407:
    v_31449 = stack[-4];
    v_31449 = qcdr(v_31449);
    v_31449 = qcdr(v_31449);
    stack[0] = qcar(v_31449);
    goto v_31408;
v_31409:
    goto v_31425;
v_31421:
    goto v_31431;
v_31427:
    v_31449 = stack[-4];
    v_31449 = qcdr(v_31449);
    v_31449 = qcdr(v_31449);
    v_31449 = qcdr(v_31449);
    stack[-4] = qcar(v_31449);
    goto v_31428;
v_31429:
    goto v_31444;
v_31438:
    v_31451 = stack[-2];
    goto v_31439;
v_31440:
    v_31450 = stack[-3];
    goto v_31441;
v_31442:
    v_31449 = nil;
    goto v_31443;
v_31444:
    goto v_31438;
v_31439:
    goto v_31440;
v_31441:
    goto v_31442;
v_31443:
    v_31449 = list2star(v_31451, v_31450, v_31449);
    env = stack[-6];
    goto v_31430;
v_31431:
    goto v_31427;
v_31428:
    goto v_31429;
v_31430:
    fn = elt(env, 4); // dipsum
    v_31450 = (*qfn2(fn))(fn, stack[-4], v_31449);
    env = stack[-6];
    goto v_31422;
v_31423:
    v_31449 = nil;
    goto v_31424;
v_31425:
    goto v_31421;
v_31422:
    goto v_31423;
v_31424:
    v_31449 = list2(v_31450, v_31449);
    goto v_31410;
v_31411:
    goto v_31403;
v_31404:
    goto v_31405;
v_31406:
    goto v_31407;
v_31408:
    goto v_31409;
v_31410:
    {
        LispObject v_31458 = stack[-5];
        LispObject v_31459 = stack[-1];
        LispObject v_31460 = stack[0];
        return list3star(v_31458, v_31459, v_31460, v_31449);
    }
    v_31449 = nil;
v_31370:
    return onevalue(v_31449);
}



// Code for fast!-augment!-columns

static LispObject CC_fastKaugmentKcolumns(LispObject env,
                         LispObject v_31365, LispObject v_31366)
{
    env = qenv(env);
    LispObject v_31541, v_31542, v_31543;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31366,v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31365,v_31366);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(13);
// copy arguments values to proper place
    stack[-9] = v_31366;
    stack[-10] = v_31365;
// end of prologue
    v_31541 = stack[-10];
    fn = elt(env, 1); // fast!-row!-dim
    v_31541 = (*qfn1(fn))(fn, v_31541);
    env = stack[-12];
    stack[-8] = v_31541;
    v_31541 = stack[-9];
    v_31541 = Llength(nil, v_31541);
    env = stack[-12];
    stack[-6] = v_31541;
    v_31541 = stack[-8];
    v_31541 = sub1(v_31541);
    env = stack[-12];
    v_31541 = Lmkvect(nil, v_31541);
    env = stack[-12];
    stack[-11] = v_31541;
    v_31541 = stack[-9];
    if (!consp(v_31541)) goto v_31384;
    else goto v_31385;
v_31384:
    v_31541 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_31541;
v_31390:
    goto v_31402;
v_31398:
    v_31541 = stack[-8];
    v_31542 = sub1(v_31541);
    env = stack[-12];
    goto v_31399;
v_31400:
    v_31541 = stack[-3];
    goto v_31401;
v_31402:
    goto v_31398;
v_31399:
    goto v_31400;
v_31401:
    v_31541 = difference2(v_31542, v_31541);
    env = stack[-12];
    v_31541 = Lminusp(nil, v_31541);
    env = stack[-12];
    if (v_31541 == nil) goto v_31395;
    goto v_31389;
v_31395:
    v_31541 = (LispObject)0+TAG_FIXNUM; // 0
    v_31541 = Lmkvect(nil, v_31541);
    env = stack[-12];
    stack[-7] = v_31541;
    goto v_31416;
v_31410:
    stack[-2] = stack[-7];
    goto v_31411;
v_31412:
    stack[-1] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31413;
v_31414:
    goto v_31426;
v_31420:
    stack[0] = stack[-10];
    goto v_31421;
v_31422:
    v_31541 = stack[-3];
    v_31542 = add1(v_31541);
    env = stack[-12];
    goto v_31423;
v_31424:
    v_31541 = stack[-9];
    goto v_31425;
v_31426:
    goto v_31420;
v_31421:
    goto v_31422;
v_31423:
    goto v_31424;
v_31425:
    fn = elt(env, 2); // sc_getmat
    v_31541 = (*qfnn(fn))(fn, 3, stack[0], v_31542, v_31541);
    env = stack[-12];
    goto v_31415;
v_31416:
    goto v_31410;
v_31411:
    goto v_31412;
v_31413:
    goto v_31414;
v_31415:
    fn = elt(env, 3); // sc_iputv
    v_31541 = (*qfnn(fn))(fn, 3, stack[-2], stack[-1], v_31541);
    env = stack[-12];
    goto v_31438;
v_31432:
    v_31543 = stack[-11];
    goto v_31433;
v_31434:
    v_31542 = stack[-3];
    goto v_31435;
v_31436:
    v_31541 = stack[-7];
    goto v_31437;
v_31438:
    goto v_31432;
v_31433:
    goto v_31434;
v_31435:
    goto v_31436;
v_31437:
    fn = elt(env, 3); // sc_iputv
    v_31541 = (*qfnn(fn))(fn, 3, v_31543, v_31542, v_31541);
    env = stack[-12];
    v_31541 = stack[-3];
    v_31541 = add1(v_31541);
    env = stack[-12];
    stack[-3] = v_31541;
    goto v_31390;
v_31389:
    goto v_31383;
v_31385:
    v_31541 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_31541;
v_31449:
    goto v_31461;
v_31457:
    v_31541 = stack[-8];
    v_31542 = sub1(v_31541);
    env = stack[-12];
    goto v_31458;
v_31459:
    v_31541 = stack[-5];
    goto v_31460;
v_31461:
    goto v_31457;
v_31458:
    goto v_31459;
v_31460:
    v_31541 = difference2(v_31542, v_31541);
    env = stack[-12];
    v_31541 = Lminusp(nil, v_31541);
    env = stack[-12];
    if (v_31541 == nil) goto v_31454;
    goto v_31448;
v_31454:
    v_31541 = stack[-6];
    v_31541 = sub1(v_31541);
    env = stack[-12];
    v_31541 = Lmkvect(nil, v_31541);
    env = stack[-12];
    stack[-7] = v_31541;
    v_31541 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_31541;
v_31472:
    goto v_31484;
v_31480:
    v_31541 = stack[-6];
    v_31542 = sub1(v_31541);
    env = stack[-12];
    goto v_31481;
v_31482:
    v_31541 = stack[-4];
    goto v_31483;
v_31484:
    goto v_31480;
v_31481:
    goto v_31482;
v_31483:
    v_31541 = difference2(v_31542, v_31541);
    env = stack[-12];
    v_31541 = Lminusp(nil, v_31541);
    env = stack[-12];
    if (v_31541 == nil) goto v_31477;
    goto v_31471;
v_31477:
    goto v_31494;
v_31490:
    stack[0] = stack[-10];
    goto v_31491;
v_31492:
    v_31541 = stack[-5];
    v_31541 = add1(v_31541);
    env = stack[-12];
    goto v_31493;
v_31494:
    goto v_31490;
v_31491:
    goto v_31492;
v_31493:
    fn = elt(env, 4); // sc_getrow
    v_31541 = (*qfn2(fn))(fn, stack[0], v_31541);
    env = stack[-12];
    goto v_31505;
v_31499:
    stack[-3] = stack[-7];
    goto v_31500;
v_31501:
    stack[-2] = stack[-4];
    goto v_31502;
v_31503:
    goto v_31513;
v_31509:
    stack[-1] = v_31541;
    goto v_31510;
v_31511:
    goto v_31521;
v_31517:
    stack[0] = stack[-9];
    goto v_31518;
v_31519:
    v_31541 = stack[-4];
    v_31541 = add1(v_31541);
    env = stack[-12];
    goto v_31520;
v_31521:
    goto v_31517;
v_31518:
    goto v_31519;
v_31520:
    fn = elt(env, 5); // nth
    v_31541 = (*qfn2(fn))(fn, stack[0], v_31541);
    env = stack[-12];
    v_31541 = sub1(v_31541);
    env = stack[-12];
    goto v_31512;
v_31513:
    goto v_31509;
v_31510:
    goto v_31511;
v_31512:
    fn = elt(env, 6); // sc_igetv
    v_31541 = (*qfn2(fn))(fn, stack[-1], v_31541);
    env = stack[-12];
    goto v_31504;
v_31505:
    goto v_31499;
v_31500:
    goto v_31501;
v_31502:
    goto v_31503;
v_31504:
    fn = elt(env, 3); // sc_iputv
    v_31541 = (*qfnn(fn))(fn, 3, stack[-3], stack[-2], v_31541);
    env = stack[-12];
    v_31541 = stack[-4];
    v_31541 = add1(v_31541);
    env = stack[-12];
    stack[-4] = v_31541;
    goto v_31472;
v_31471:
    goto v_31534;
v_31528:
    v_31543 = stack[-11];
    goto v_31529;
v_31530:
    v_31542 = stack[-5];
    goto v_31531;
v_31532:
    v_31541 = stack[-7];
    goto v_31533;
v_31534:
    goto v_31528;
v_31529:
    goto v_31530;
v_31531:
    goto v_31532;
v_31533:
    fn = elt(env, 3); // sc_iputv
    v_31541 = (*qfnn(fn))(fn, 3, v_31543, v_31542, v_31541);
    env = stack[-12];
    v_31541 = stack[-5];
    v_31541 = add1(v_31541);
    env = stack[-12];
    stack[-5] = v_31541;
    goto v_31449;
v_31448:
    goto v_31383;
v_31383:
    v_31541 = stack[-11];
    return onevalue(v_31541);
}



// Code for atlas_edges

static LispObject CC_atlas_edges(LispObject env,
                         LispObject v_31365)
{
    env = qenv(env);
    LispObject v_31391;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31365);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31365;
// end of prologue
    goto v_31372;
v_31368:
    goto v_31378;
v_31374:
    v_31391 = stack[0];
    v_31391 = qcar(v_31391);
    fn = elt(env, 1); // map__edges
    stack[-1] = (*qfn1(fn))(fn, v_31391);
    env = stack[-2];
    goto v_31375;
v_31376:
    v_31391 = stack[0];
    v_31391 = qcdr(v_31391);
    v_31391 = qcdr(v_31391);
    v_31391 = qcar(v_31391);
    fn = elt(env, 2); // den__edges
    v_31391 = (*qfn1(fn))(fn, v_31391);
    env = stack[-2];
    goto v_31377;
v_31378:
    goto v_31374;
v_31375:
    goto v_31376;
v_31377:
    fn = elt(env, 3); // union_edges
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_31391);
    env = stack[-2];
    goto v_31369;
v_31370:
    v_31391 = stack[0];
    v_31391 = qcdr(v_31391);
    v_31391 = qcar(v_31391);
    fn = elt(env, 4); // coeff_edges
    v_31391 = (*qfn1(fn))(fn, v_31391);
    env = stack[-2];
    goto v_31371;
v_31372:
    goto v_31368;
v_31369:
    goto v_31370;
v_31371:
    {
        LispObject v_31394 = stack[-1];
        fn = elt(env, 3); // union_edges
        return (*qfn2(fn))(fn, v_31394, v_31391);
    }
}



// Code for compactf3

static LispObject CC_compactf3(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31398, v_31399, v_31400;
    LispObject fn;
    LispObject v_31367, v_31366, v_31365;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "compactf3");
    va_start(aa, nargs);
    v_31365 = va_arg(aa, LispObject);
    v_31366 = va_arg(aa, LispObject);
    v_31367 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31367,v_31366,v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31365,v_31366,v_31367);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31367;
    stack[-1] = v_31366;
    v_31399 = v_31365;
// end of prologue
// Binding mv!-vars!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = nil; // mv!-vars!*
    v_31398 = stack[0];
    qvalue(elt(env, 1)) = v_31398; // mv!-vars!*
    goto v_31378;
v_31374:
    goto v_31386;
v_31380:
    goto v_31392;
v_31388:
    goto v_31389;
v_31390:
    v_31398 = stack[0];
    goto v_31391;
v_31392:
    goto v_31388;
v_31389:
    goto v_31390;
v_31391:
    fn = elt(env, 2); // sf2mv
    v_31400 = (*qfn2(fn))(fn, v_31399, v_31398);
    env = stack[-3];
    goto v_31381;
v_31382:
    v_31399 = stack[-1];
    goto v_31383;
v_31384:
    v_31398 = nil;
    goto v_31385;
v_31386:
    goto v_31380;
v_31381:
    goto v_31382;
v_31383:
    goto v_31384;
v_31385:
    fn = elt(env, 3); // mv!-compact
    v_31399 = (*qfnn(fn))(fn, 3, v_31400, v_31399, v_31398);
    env = stack[-3];
    goto v_31375;
v_31376:
    v_31398 = stack[0];
    goto v_31377;
v_31378:
    goto v_31374;
v_31375:
    goto v_31376;
v_31377:
    fn = elt(env, 4); // mv2sf
    v_31398 = (*qfn2(fn))(fn, v_31399, v_31398);
    ;}  // end of a binding scope
    return onevalue(v_31398);
}



// Code for mo!=pair

static LispObject CC_moMpair(LispObject env,
                         LispObject v_31365, LispObject v_31366)
{
    env = qenv(env);
    LispObject v_31407, v_31408, v_31409;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31366,v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31365,v_31366);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31366;
    stack[-1] = v_31365;
// end of prologue
    v_31407 = nil;
v_31371:
    v_31408 = stack[-1];
    if (v_31408 == nil) goto v_31378;
    else goto v_31379;
v_31378:
    v_31408 = lisp_true;
    goto v_31377;
v_31379:
    v_31408 = stack[0];
    v_31408 = (v_31408 == nil ? lisp_true : nil);
    goto v_31377;
    v_31408 = nil;
v_31377:
    if (v_31408 == nil) goto v_31375;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_31407);
    }
v_31375:
    goto v_31397;
v_31391:
    v_31408 = stack[-1];
    v_31409 = qcar(v_31408);
    goto v_31392;
v_31393:
    v_31408 = stack[0];
    v_31408 = qcar(v_31408);
    goto v_31394;
v_31395:
    goto v_31396;
v_31397:
    goto v_31391;
v_31392:
    goto v_31393;
v_31394:
    goto v_31395;
v_31396:
    v_31407 = acons(v_31409, v_31408, v_31407);
    env = stack[-2];
    v_31408 = stack[-1];
    v_31408 = qcdr(v_31408);
    stack[-1] = v_31408;
    v_31408 = stack[0];
    v_31408 = qcdr(v_31408);
    stack[0] = v_31408;
    goto v_31371;
    v_31407 = nil;
    return onevalue(v_31407);
}



// Code for !*v2j

static LispObject CC_Hv2j(LispObject env,
                         LispObject v_31365)
{
    env = qenv(env);
    LispObject v_31403, v_31404, v_31405;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31365);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31405 = v_31365;
// end of prologue
    goto v_31375;
v_31371:
    v_31404 = qvalue(elt(env, 1)); // ordering
    goto v_31372;
v_31373:
    v_31403 = elt(env, 2); // lex
    goto v_31374;
v_31375:
    goto v_31371;
v_31372:
    goto v_31373;
v_31374:
    if (v_31404 == v_31403) goto v_31369;
    else goto v_31370;
v_31369:
    goto v_31383;
v_31379:
    v_31404 = v_31405;
    goto v_31380;
v_31381:
    v_31403 = qvalue(elt(env, 3)); // varlist!*
    goto v_31382;
v_31383:
    goto v_31379;
v_31380:
    goto v_31381;
v_31382:
    {
        fn = elt(env, 4); // sub01
        return (*qfn2(fn))(fn, v_31404, v_31403);
    }
v_31370:
    goto v_31393;
v_31389:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31390;
v_31391:
    goto v_31400;
v_31396:
    v_31404 = v_31405;
    goto v_31397;
v_31398:
    v_31403 = qvalue(elt(env, 3)); // varlist!*
    goto v_31399;
v_31400:
    goto v_31396;
v_31397:
    goto v_31398;
v_31399:
    fn = elt(env, 4); // sub01
    v_31403 = (*qfn2(fn))(fn, v_31404, v_31403);
    goto v_31392;
v_31393:
    goto v_31389;
v_31390:
    goto v_31391;
v_31392:
    {
        LispObject v_31407 = stack[0];
        return cons(v_31407, v_31403);
    }
    v_31403 = nil;
    return onevalue(v_31403);
}



// Code for dummy_nam

static LispObject CC_dummy_nam(LispObject env,
                         LispObject v_31365)
{
    env = qenv(env);
    LispObject v_31377, v_31378;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31365);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31377 = v_31365;
// end of prologue
    goto v_31372;
v_31368:
    fn = elt(env, 3); // ordn
    v_31378 = (*qfn1(fn))(fn, v_31377);
    env = stack[0];
    goto v_31369;
v_31370:
    v_31377 = elt(env, 1); // symbolic
    goto v_31371;
v_31372:
    goto v_31368;
v_31369:
    goto v_31370;
v_31371:
    fn = elt(env, 4); // list2vect!*
    v_31377 = (*qfn2(fn))(fn, v_31378, v_31377);
    env = stack[0];
    qvalue(elt(env, 2)) = v_31377; // g_dvnames
    v_31377 = lisp_true;
    return onevalue(v_31377);
}



// Code for general!-negate!-term

static LispObject CC_generalKnegateKterm(LispObject env,
                         LispObject v_31365)
{
    env = qenv(env);
    LispObject v_31378, v_31379;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31365);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31379 = v_31365;
// end of prologue
    goto v_31372;
v_31368:
    v_31378 = v_31379;
    stack[0] = qcar(v_31378);
    goto v_31369;
v_31370:
    v_31378 = v_31379;
    v_31378 = qcdr(v_31378);
    fn = elt(env, 1); // general!-minus!-mod!-p
    v_31378 = (*qfn1(fn))(fn, v_31378);
    goto v_31371;
v_31372:
    goto v_31368;
v_31369:
    goto v_31370;
v_31371:
    {
        LispObject v_31381 = stack[0];
        return cons(v_31381, v_31378);
    }
}



// Code for initmonomials

static LispObject CC_initmonomials(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31406, v_31407;
    LispObject fn;
    argcheck(nargs, 0, "initmonomials");
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
    v_31406 = qvalue(elt(env, 1)); // fluidbibasisvariables
    v_31406 = Llength(nil, v_31406);
    env = stack[-3];
    qvalue(elt(env, 2)) = v_31406; // fluidbibasisnumberofvariables
    v_31406 = qvalue(elt(env, 2)); // fluidbibasisnumberofvariables
    v_31406 = Lmkvect(nil, v_31406);
    env = stack[-3];
    qvalue(elt(env, 3)) = v_31406; // fluidbibasissinglevariablemonomialss
    v_31406 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_31406;
v_31375:
    goto v_31387;
v_31383:
    v_31407 = qvalue(elt(env, 2)); // fluidbibasisnumberofvariables
    goto v_31384;
v_31385:
    v_31406 = stack[-2];
    goto v_31386;
v_31387:
    goto v_31383;
v_31384:
    goto v_31385;
v_31386:
    v_31406 = difference2(v_31407, v_31406);
    env = stack[-3];
    v_31406 = Lminusp(nil, v_31406);
    env = stack[-3];
    if (v_31406 == nil) goto v_31380;
    goto v_31374;
v_31380:
    goto v_31397;
v_31391:
    stack[-1] = qvalue(elt(env, 3)); // fluidbibasissinglevariablemonomialss
    goto v_31392;
v_31393:
    stack[0] = stack[-2];
    goto v_31394;
v_31395:
    v_31406 = stack[-2];
    fn = elt(env, 5); // createsinglevariablemonom
    v_31406 = (*qfn1(fn))(fn, v_31406);
    env = stack[-3];
    goto v_31396;
v_31397:
    goto v_31391;
v_31392:
    goto v_31393;
v_31394:
    goto v_31395;
v_31396:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_31406;
    v_31406 = stack[-2];
    v_31406 = add1(v_31406);
    env = stack[-3];
    stack[-2] = v_31406;
    goto v_31375;
v_31374:
    v_31406 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 4)) = v_31406; // fluidbibasistripleid
    v_31406 = nil;
    return onevalue(v_31406);
}



// Code for rl_ex

static LispObject CC_rl_ex(LispObject env,
                         LispObject v_31365, LispObject v_31366)
{
    env = qenv(env);
    LispObject v_31383, v_31384;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31366,v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31365,v_31366);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31383 = v_31366;
    v_31384 = v_31365;
// end of prologue
    goto v_31373;
v_31369:
    stack[0] = qvalue(elt(env, 1)); // rl_ex!*
    goto v_31370;
v_31371:
    goto v_31380;
v_31376:
    goto v_31377;
v_31378:
    goto v_31379;
v_31380:
    goto v_31376;
v_31377:
    goto v_31378;
v_31379:
    v_31383 = list2(v_31384, v_31383);
    env = stack[-1];
    goto v_31372;
v_31373:
    goto v_31369;
v_31370:
    goto v_31371;
v_31372:
    {
        LispObject v_31386 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_31386, v_31383);
    }
}



// Code for !*invsq

static LispObject CC_Hinvsq(LispObject env,
                         LispObject v_31365)
{
    env = qenv(env);
    LispObject v_31379, v_31380;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31365);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31380 = v_31365;
// end of prologue
    v_31379 = qvalue(elt(env, 1)); // sqrtflag
    if (v_31379 == nil) goto v_31370;
    v_31379 = v_31380;
    fn = elt(env, 2); // invsq
    v_31379 = (*qfn1(fn))(fn, v_31379);
    env = stack[0];
    {
        fn = elt(env, 3); // sqrt2top
        return (*qfn1(fn))(fn, v_31379);
    }
v_31370:
    v_31379 = v_31380;
    {
        fn = elt(env, 2); // invsq
        return (*qfn1(fn))(fn, v_31379);
    }
    v_31379 = nil;
    return onevalue(v_31379);
}



// Code for multtaylorsq

static LispObject CC_multtaylorsq(LispObject env,
                         LispObject v_31365, LispObject v_31366)
{
    env = qenv(env);
    LispObject v_31518, v_31519;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31366,v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31365,v_31366);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_31366;
    stack[-6] = v_31365;
// end of prologue
    v_31518 = stack[-6];
    if (v_31518 == nil) goto v_31374;
    else goto v_31375;
v_31374:
    v_31518 = lisp_true;
    goto v_31373;
v_31375:
    v_31518 = stack[-5];
    v_31518 = qcar(v_31518);
    v_31518 = (v_31518 == nil ? lisp_true : nil);
    goto v_31373;
    v_31518 = nil;
v_31373:
    if (v_31518 == nil) goto v_31371;
    v_31518 = nil;
    goto v_31369;
v_31371:
    goto v_31395;
v_31387:
    stack[-7] = elt(env, 1); // taylor!*
    goto v_31388;
v_31389:
    v_31518 = stack[-6];
    v_31518 = qcdr(v_31518);
    v_31518 = qcar(v_31518);
    stack[-4] = v_31518;
    v_31518 = stack[-4];
    if (v_31518 == nil) goto v_31408;
    else goto v_31409;
v_31408:
    v_31518 = nil;
    stack[-1] = v_31518;
    goto v_31401;
v_31409:
    v_31518 = stack[-4];
    v_31518 = qcar(v_31518);
    v_31519 = v_31518;
    goto v_31421;
v_31417:
    v_31518 = v_31519;
    stack[0] = qcar(v_31518);
    goto v_31418;
v_31419:
    goto v_31431;
v_31427:
    v_31518 = v_31519;
    v_31519 = qcdr(v_31518);
    goto v_31428;
v_31429:
    v_31518 = stack[-5];
    goto v_31430;
v_31431:
    goto v_31427;
v_31428:
    goto v_31429;
v_31430:
    fn = elt(env, 3); // multsq
    v_31518 = (*qfn2(fn))(fn, v_31519, v_31518);
    env = stack[-8];
    fn = elt(env, 4); // subs2!*
    v_31518 = (*qfn1(fn))(fn, v_31518);
    env = stack[-8];
    fn = elt(env, 5); // resimp
    v_31518 = (*qfn1(fn))(fn, v_31518);
    env = stack[-8];
    goto v_31420;
v_31421:
    goto v_31417;
v_31418:
    goto v_31419;
v_31420:
    v_31518 = cons(stack[0], v_31518);
    env = stack[-8];
    v_31518 = ncons(v_31518);
    env = stack[-8];
    stack[-2] = v_31518;
    stack[-3] = v_31518;
v_31402:
    v_31518 = stack[-4];
    v_31518 = qcdr(v_31518);
    stack[-4] = v_31518;
    v_31518 = stack[-4];
    if (v_31518 == nil) goto v_31439;
    else goto v_31440;
v_31439:
    v_31518 = stack[-3];
    stack[-1] = v_31518;
    goto v_31401;
v_31440:
    goto v_31448;
v_31444:
    stack[-1] = stack[-2];
    goto v_31445;
v_31446:
    v_31518 = stack[-4];
    v_31518 = qcar(v_31518);
    v_31519 = v_31518;
    goto v_31459;
v_31455:
    v_31518 = v_31519;
    stack[0] = qcar(v_31518);
    goto v_31456;
v_31457:
    goto v_31469;
v_31465:
    v_31518 = v_31519;
    v_31519 = qcdr(v_31518);
    goto v_31466;
v_31467:
    v_31518 = stack[-5];
    goto v_31468;
v_31469:
    goto v_31465;
v_31466:
    goto v_31467;
v_31468:
    fn = elt(env, 3); // multsq
    v_31518 = (*qfn2(fn))(fn, v_31519, v_31518);
    env = stack[-8];
    fn = elt(env, 4); // subs2!*
    v_31518 = (*qfn1(fn))(fn, v_31518);
    env = stack[-8];
    fn = elt(env, 5); // resimp
    v_31518 = (*qfn1(fn))(fn, v_31518);
    env = stack[-8];
    goto v_31458;
v_31459:
    goto v_31455;
v_31456:
    goto v_31457;
v_31458:
    v_31518 = cons(stack[0], v_31518);
    env = stack[-8];
    v_31518 = ncons(v_31518);
    env = stack[-8];
    goto v_31447;
v_31448:
    goto v_31444;
v_31445:
    goto v_31446;
v_31447:
    v_31518 = Lrplacd(nil, stack[-1], v_31518);
    env = stack[-8];
    v_31518 = stack[-2];
    v_31518 = qcdr(v_31518);
    stack[-2] = v_31518;
    goto v_31402;
v_31401:
    goto v_31390;
v_31391:
    v_31518 = stack[-6];
    v_31518 = qcdr(v_31518);
    v_31518 = qcdr(v_31518);
    stack[0] = qcar(v_31518);
    goto v_31392;
v_31393:
    goto v_31484;
v_31480:
    v_31518 = qvalue(elt(env, 2)); // !*taylorkeeporiginal
    if (v_31518 == nil) goto v_31488;
    v_31518 = stack[-6];
    v_31518 = qcdr(v_31518);
    v_31518 = qcdr(v_31518);
    v_31518 = qcdr(v_31518);
    v_31518 = qcar(v_31518);
    if (v_31518 == nil) goto v_31488;
    goto v_31502;
v_31498:
    v_31519 = stack[-5];
    goto v_31499;
v_31500:
    v_31518 = stack[-6];
    v_31518 = qcdr(v_31518);
    v_31518 = qcdr(v_31518);
    v_31518 = qcdr(v_31518);
    v_31518 = qcar(v_31518);
    goto v_31501;
v_31502:
    goto v_31498;
v_31499:
    goto v_31500;
v_31501:
    fn = elt(env, 3); // multsq
    v_31518 = (*qfn2(fn))(fn, v_31519, v_31518);
    env = stack[-8];
    v_31519 = v_31518;
    goto v_31486;
v_31488:
    v_31518 = nil;
    v_31519 = v_31518;
    goto v_31486;
    v_31519 = nil;
v_31486:
    goto v_31481;
v_31482:
    v_31518 = stack[-6];
    v_31518 = qcdr(v_31518);
    v_31518 = qcdr(v_31518);
    v_31518 = qcdr(v_31518);
    v_31518 = qcdr(v_31518);
    v_31518 = qcar(v_31518);
    goto v_31483;
v_31484:
    goto v_31480;
v_31481:
    goto v_31482;
v_31483:
    v_31518 = list2(v_31519, v_31518);
    goto v_31394;
v_31395:
    goto v_31387;
v_31388:
    goto v_31389;
v_31390:
    goto v_31391;
v_31392:
    goto v_31393;
v_31394:
    {
        LispObject v_31528 = stack[-7];
        LispObject v_31529 = stack[-1];
        LispObject v_31530 = stack[0];
        return list3star(v_31528, v_31529, v_31530, v_31518);
    }
    v_31518 = nil;
v_31369:
    return onevalue(v_31518);
}



// Code for depend!-p

static LispObject CC_dependKp(LispObject env,
                         LispObject v_31365, LispObject v_31366)
{
    env = qenv(env);
    LispObject v_31427, v_31428, v_31429, v_31430;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31429 = v_31366;
    v_31430 = v_31365;
// end of prologue
    goto v_31376;
v_31372:
    v_31428 = v_31430;
    goto v_31373;
v_31374:
    v_31427 = v_31429;
    goto v_31375;
v_31376:
    goto v_31372;
v_31373:
    goto v_31374;
v_31375:
    if (v_31428 == v_31427) goto v_31370;
    else goto v_31371;
v_31370:
    v_31427 = lisp_true;
    goto v_31369;
v_31371:
    v_31427 = v_31430;
    if (!consp(v_31427)) goto v_31380;
    else goto v_31381;
v_31380:
    v_31427 = nil;
    goto v_31369;
v_31381:
    v_31427 = v_31430;
    v_31427 = qcar(v_31427);
    if (!consp(v_31427)) goto v_31385;
    goto v_31393;
v_31389:
    v_31427 = v_31430;
    goto v_31390;
v_31391:
    v_31428 = v_31429;
    goto v_31392;
v_31393:
    goto v_31389;
v_31390:
    goto v_31391;
v_31392:
    {
        fn = elt(env, 2); // depend!-f
        return (*qfn2(fn))(fn, v_31427, v_31428);
    }
v_31385:
    goto v_31402;
v_31398:
    v_31427 = v_31430;
    v_31428 = qcar(v_31427);
    goto v_31399;
v_31400:
    v_31427 = elt(env, 1); // !*sq
    goto v_31401;
v_31402:
    goto v_31398;
v_31399:
    goto v_31400;
v_31401:
    if (v_31428 == v_31427) goto v_31396;
    else goto v_31397;
v_31396:
    goto v_31411;
v_31407:
    v_31427 = v_31430;
    v_31427 = qcdr(v_31427);
    v_31427 = qcar(v_31427);
    goto v_31408;
v_31409:
    v_31428 = v_31429;
    goto v_31410;
v_31411:
    goto v_31407;
v_31408:
    goto v_31409;
v_31410:
    {
        fn = elt(env, 3); // depend!-sq
        return (*qfn2(fn))(fn, v_31427, v_31428);
    }
v_31397:
    goto v_31423;
v_31419:
    v_31427 = v_31430;
    v_31427 = qcdr(v_31427);
    goto v_31420;
v_31421:
    v_31428 = v_31429;
    goto v_31422;
v_31423:
    goto v_31419;
v_31420:
    goto v_31421;
v_31422:
    {
        fn = elt(env, 4); // depend!-l
        return (*qfn2(fn))(fn, v_31427, v_31428);
    }
    v_31427 = nil;
v_31369:
    return onevalue(v_31427);
}



// Code for qqe_length!-graph!-bterm

static LispObject CC_qqe_lengthKgraphKbterm(LispObject env,
                         LispObject v_31365, LispObject v_31366)
{
    env = qenv(env);
    LispObject v_31434, v_31435;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31366,v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31365,v_31366);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31366;
    stack[-1] = v_31365;
// end of prologue
    v_31434 = stack[-1];
    if (v_31434 == nil) goto v_31376;
    else goto v_31377;
v_31376:
    v_31434 = lisp_true;
    goto v_31375;
v_31377:
    v_31434 = stack[-1];
    v_31434 = (consp(v_31434) ? nil : lisp_true);
    goto v_31375;
    v_31434 = nil;
v_31375:
    if (v_31434 == nil) goto v_31373;
    v_31434 = stack[0];
    goto v_31369;
v_31373:
    goto v_31393;
v_31389:
    v_31434 = stack[-1];
    fn = elt(env, 2); // qqe_op
    v_31435 = (*qfn1(fn))(fn, v_31434);
    env = stack[-2];
    goto v_31390;
v_31391:
    v_31434 = elt(env, 1); // (lhead rhead)
    goto v_31392;
v_31393:
    goto v_31389;
v_31390:
    goto v_31391;
v_31392:
    v_31434 = Lmemq(nil, v_31435, v_31434);
    if (v_31434 == nil) goto v_31388;
    goto v_31403;
v_31399:
    v_31435 = stack[-1];
    goto v_31400;
v_31401:
    v_31434 = stack[0];
    goto v_31402;
v_31403:
    goto v_31399;
v_31400:
    goto v_31401;
v_31402:
    fn = elt(env, 3); // qqe_length!-graph!-bterm!-update!-headmin
    v_31434 = (*qfn2(fn))(fn, v_31435, v_31434);
    stack[0] = v_31434;
    goto v_31386;
v_31388:
    v_31434 = stack[-1];
    v_31434 = qcdr(v_31434);
    stack[-1] = v_31434;
v_31411:
    v_31434 = stack[-1];
    if (v_31434 == nil) goto v_31416;
    else goto v_31417;
v_31416:
    goto v_31410;
v_31417:
    v_31434 = stack[-1];
    v_31434 = qcar(v_31434);
    goto v_31428;
v_31424:
    v_31435 = v_31434;
    goto v_31425;
v_31426:
    v_31434 = stack[0];
    goto v_31427;
v_31428:
    goto v_31424;
v_31425:
    goto v_31426;
v_31427:
    v_31434 = CC_qqe_lengthKgraphKbterm(elt(env, 0), v_31435, v_31434);
    env = stack[-2];
    stack[0] = v_31434;
    v_31434 = stack[-1];
    v_31434 = qcdr(v_31434);
    stack[-1] = v_31434;
    goto v_31411;
v_31410:
    goto v_31386;
v_31386:
    v_31434 = stack[0];
v_31369:
    return onevalue(v_31434);
}



// Code for pasf_exprng

static LispObject CC_pasf_exprng(LispObject env,
                         LispObject v_31365)
{
    env = qenv(env);
    LispObject v_31691, v_31692, v_31693, v_31694, v_31695, v_31696;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31365);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_31691 = v_31365;
// end of prologue
// Binding !*rlsism
// FLUIDBIND: reloadenv=6 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-6, 1, -4);
    qvalue(elt(env, 1)) = nil; // !*rlsism
    v_31692 = v_31691;
    if (!consp(v_31692)) goto v_31374;
    else goto v_31375;
v_31374:
    v_31692 = v_31691;
    goto v_31373;
v_31375:
    v_31692 = v_31691;
    v_31692 = qcar(v_31692);
    goto v_31373;
    v_31692 = nil;
v_31373:
    stack[-5] = v_31692;
    goto v_31390;
v_31386:
    v_31693 = stack[-5];
    goto v_31387;
v_31388:
    v_31692 = elt(env, 2); // and
    goto v_31389;
v_31390:
    goto v_31386;
v_31387:
    goto v_31388;
v_31389:
    if (v_31693 == v_31692) goto v_31384;
    else goto v_31385;
v_31384:
    goto v_31402;
v_31394:
    v_31693 = elt(env, 2); // and
    goto v_31395;
v_31396:
    v_31694 = qcdr(v_31691);
    goto v_31397;
v_31398:
    v_31692 = elt(env, 3); // true
    goto v_31399;
v_31400:
    v_31691 = elt(env, 4); // false
    goto v_31401;
v_31402:
    goto v_31394;
v_31395:
    goto v_31396;
v_31397:
    goto v_31398;
v_31399:
    goto v_31400;
v_31401:
    fn = elt(env, 12); // pasf_exprng!-gand
    v_31691 = (*qfnn(fn))(fn, 4, v_31693, v_31694, v_31692, v_31691);
    goto v_31371;
v_31385:
    goto v_31416;
v_31412:
    v_31693 = stack[-5];
    goto v_31413;
v_31414:
    v_31692 = elt(env, 5); // or
    goto v_31415;
v_31416:
    goto v_31412;
v_31413:
    goto v_31414;
v_31415:
    if (v_31693 == v_31692) goto v_31410;
    else goto v_31411;
v_31410:
    goto v_31428;
v_31420:
    v_31693 = elt(env, 5); // or
    goto v_31421;
v_31422:
    v_31694 = qcdr(v_31691);
    goto v_31423;
v_31424:
    v_31692 = elt(env, 4); // false
    goto v_31425;
v_31426:
    v_31691 = elt(env, 3); // true
    goto v_31427;
v_31428:
    goto v_31420;
v_31421:
    goto v_31422;
v_31423:
    goto v_31424;
v_31425:
    goto v_31426;
v_31427:
    fn = elt(env, 12); // pasf_exprng!-gand
    v_31691 = (*qfnn(fn))(fn, 4, v_31693, v_31694, v_31692, v_31691);
    goto v_31371;
v_31411:
    goto v_31442;
v_31438:
    v_31693 = stack[-5];
    goto v_31439;
v_31440:
    v_31692 = elt(env, 6); // ball
    goto v_31441;
v_31442:
    goto v_31438;
v_31439:
    goto v_31440;
v_31441:
    if (v_31693 == v_31692) goto v_31436;
    else goto v_31437;
v_31436:
    goto v_31458;
v_31446:
    v_31692 = v_31691;
    v_31692 = qcdr(v_31692);
    v_31696 = qcar(v_31692);
    goto v_31447;
v_31448:
    v_31692 = v_31691;
    v_31692 = qcdr(v_31692);
    v_31692 = qcdr(v_31692);
    v_31692 = qcdr(v_31692);
    v_31695 = qcar(v_31692);
    goto v_31449;
v_31450:
    v_31691 = qcdr(v_31691);
    v_31691 = qcdr(v_31691);
    v_31694 = qcar(v_31691);
    goto v_31451;
v_31452:
    v_31693 = elt(env, 2); // and
    goto v_31453;
v_31454:
    v_31692 = elt(env, 3); // true
    goto v_31455;
v_31456:
    v_31691 = elt(env, 4); // false
    goto v_31457;
v_31458:
    goto v_31446;
v_31447:
    goto v_31448;
v_31449:
    goto v_31450;
v_31451:
    goto v_31452;
v_31453:
    goto v_31454;
v_31455:
    goto v_31456;
v_31457:
    fn = elt(env, 13); // pasf_exprng!-gball
    v_31691 = (*qfnn(fn))(fn, 6, v_31696, v_31695, v_31694, v_31693, v_31692, v_31691);
    goto v_31371;
v_31437:
    goto v_31482;
v_31478:
    v_31693 = stack[-5];
    goto v_31479;
v_31480:
    v_31692 = elt(env, 7); // bex
    goto v_31481;
v_31482:
    goto v_31478;
v_31479:
    goto v_31480;
v_31481:
    if (v_31693 == v_31692) goto v_31476;
    else goto v_31477;
v_31476:
    goto v_31498;
v_31486:
    v_31692 = v_31691;
    v_31692 = qcdr(v_31692);
    v_31696 = qcar(v_31692);
    goto v_31487;
v_31488:
    v_31692 = v_31691;
    v_31692 = qcdr(v_31692);
    v_31692 = qcdr(v_31692);
    v_31692 = qcdr(v_31692);
    v_31695 = qcar(v_31692);
    goto v_31489;
v_31490:
    v_31691 = qcdr(v_31691);
    v_31691 = qcdr(v_31691);
    v_31694 = qcar(v_31691);
    goto v_31491;
v_31492:
    v_31693 = elt(env, 5); // or
    goto v_31493;
v_31494:
    v_31692 = elt(env, 4); // false
    goto v_31495;
v_31496:
    v_31691 = elt(env, 3); // true
    goto v_31497;
v_31498:
    goto v_31486;
v_31487:
    goto v_31488;
v_31489:
    goto v_31490;
v_31491:
    goto v_31492;
v_31493:
    goto v_31494;
v_31495:
    goto v_31496;
v_31497:
    fn = elt(env, 13); // pasf_exprng!-gball
    v_31691 = (*qfnn(fn))(fn, 6, v_31696, v_31695, v_31694, v_31693, v_31692, v_31691);
    goto v_31371;
v_31477:
    goto v_31534;
v_31530:
    v_31693 = stack[-5];
    goto v_31531;
v_31532:
    v_31692 = elt(env, 5); // or
    goto v_31533;
v_31534:
    goto v_31530;
v_31531:
    goto v_31532;
v_31533:
    if (v_31693 == v_31692) goto v_31528;
    else goto v_31529;
v_31528:
    v_31692 = lisp_true;
    goto v_31527;
v_31529:
    goto v_31544;
v_31540:
    v_31693 = stack[-5];
    goto v_31541;
v_31542:
    v_31692 = elt(env, 2); // and
    goto v_31543;
v_31544:
    goto v_31540;
v_31541:
    goto v_31542;
v_31543:
    v_31692 = (v_31693 == v_31692 ? lisp_true : nil);
    goto v_31527;
    v_31692 = nil;
v_31527:
    if (v_31692 == nil) goto v_31525;
    v_31692 = lisp_true;
    goto v_31523;
v_31525:
    goto v_31555;
v_31551:
    v_31693 = stack[-5];
    goto v_31552;
v_31553:
    v_31692 = elt(env, 8); // not
    goto v_31554;
v_31555:
    goto v_31551;
v_31552:
    goto v_31553;
v_31554:
    v_31692 = (v_31693 == v_31692 ? lisp_true : nil);
    goto v_31523;
    v_31692 = nil;
v_31523:
    if (v_31692 == nil) goto v_31521;
    v_31692 = lisp_true;
    goto v_31519;
v_31521:
    goto v_31570;
v_31566:
    v_31693 = stack[-5];
    goto v_31567;
v_31568:
    v_31692 = elt(env, 9); // impl
    goto v_31569;
v_31570:
    goto v_31566;
v_31567:
    goto v_31568;
v_31569:
    if (v_31693 == v_31692) goto v_31564;
    else goto v_31565;
v_31564:
    v_31692 = lisp_true;
    goto v_31563;
v_31565:
    goto v_31584;
v_31580:
    v_31693 = stack[-5];
    goto v_31581;
v_31582:
    v_31692 = elt(env, 10); // repl
    goto v_31583;
v_31584:
    goto v_31580;
v_31581:
    goto v_31582;
v_31583:
    if (v_31693 == v_31692) goto v_31578;
    else goto v_31579;
v_31578:
    v_31692 = lisp_true;
    goto v_31577;
v_31579:
    goto v_31594;
v_31590:
    v_31693 = stack[-5];
    goto v_31591;
v_31592:
    v_31692 = elt(env, 11); // equiv
    goto v_31593;
v_31594:
    goto v_31590;
v_31591:
    goto v_31592;
v_31593:
    v_31692 = (v_31693 == v_31692 ? lisp_true : nil);
    goto v_31577;
    v_31692 = nil;
v_31577:
    goto v_31563;
    v_31692 = nil;
v_31563:
    goto v_31519;
    v_31692 = nil;
v_31519:
    if (v_31692 == nil) goto v_31517;
    v_31691 = qcdr(v_31691);
    stack[-3] = v_31691;
    v_31691 = stack[-3];
    if (v_31691 == nil) goto v_31608;
    else goto v_31609;
v_31608:
    v_31691 = nil;
    goto v_31602;
v_31609:
    v_31691 = stack[-3];
    v_31691 = qcar(v_31691);
    v_31691 = CC_pasf_exprng(elt(env, 0), v_31691);
    env = stack[-6];
    v_31691 = ncons(v_31691);
    env = stack[-6];
    stack[-1] = v_31691;
    stack[-2] = v_31691;
v_31603:
    v_31691 = stack[-3];
    v_31691 = qcdr(v_31691);
    stack[-3] = v_31691;
    v_31691 = stack[-3];
    if (v_31691 == nil) goto v_31622;
    else goto v_31623;
v_31622:
    v_31691 = stack[-2];
    goto v_31602;
v_31623:
    goto v_31631;
v_31627:
    stack[0] = stack[-1];
    goto v_31628;
v_31629:
    v_31691 = stack[-3];
    v_31691 = qcar(v_31691);
    v_31691 = CC_pasf_exprng(elt(env, 0), v_31691);
    env = stack[-6];
    v_31691 = ncons(v_31691);
    env = stack[-6];
    goto v_31630;
v_31631:
    goto v_31627;
v_31628:
    goto v_31629;
v_31630:
    v_31691 = Lrplacd(nil, stack[0], v_31691);
    env = stack[-6];
    v_31691 = stack[-1];
    v_31691 = qcdr(v_31691);
    stack[-1] = v_31691;
    goto v_31603;
v_31602:
    v_31692 = v_31691;
    goto v_31648;
v_31642:
    v_31691 = v_31692;
    if (v_31691 == nil) goto v_31652;
    v_31691 = v_31692;
    v_31691 = qcdr(v_31691);
    if (v_31691 == nil) goto v_31652;
    goto v_31663;
v_31659:
    v_31691 = stack[-5];
    goto v_31660;
v_31661:
    goto v_31662;
v_31663:
    goto v_31659;
v_31660:
    goto v_31661;
v_31662:
    v_31691 = cons(v_31691, v_31692);
    env = stack[-6];
    v_31693 = v_31691;
    goto v_31650;
v_31652:
    v_31691 = v_31692;
    if (v_31691 == nil) goto v_31666;
    else goto v_31667;
v_31666:
    goto v_31677;
v_31673:
    v_31692 = stack[-5];
    goto v_31674;
v_31675:
    v_31691 = elt(env, 2); // and
    goto v_31676;
v_31677:
    goto v_31673;
v_31674:
    goto v_31675;
v_31676:
    if (v_31692 == v_31691) goto v_31671;
    else goto v_31672;
v_31671:
    v_31691 = elt(env, 3); // true
    goto v_31670;
v_31672:
    v_31691 = elt(env, 4); // false
    goto v_31670;
    v_31691 = nil;
v_31670:
    v_31693 = v_31691;
    goto v_31650;
v_31667:
    v_31691 = v_31692;
    v_31691 = qcar(v_31691);
    v_31693 = v_31691;
    goto v_31650;
    v_31693 = nil;
v_31650:
    goto v_31643;
v_31644:
    v_31692 = nil;
    goto v_31645;
v_31646:
    v_31691 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_31647;
v_31648:
    goto v_31642;
v_31643:
    goto v_31644;
v_31645:
    goto v_31646;
v_31647:
    fn = elt(env, 14); // cl_simpl
    v_31691 = (*qfnn(fn))(fn, 3, v_31693, v_31692, v_31691);
    goto v_31371;
v_31517:
v_31371:
    ;}  // end of a binding scope
    return onevalue(v_31691);
}



// Code for aex_neg

static LispObject CC_aex_neg(LispObject env,
                         LispObject v_31365)
{
    env = qenv(env);
    LispObject v_31378;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31365);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31365;
// end of prologue
    goto v_31372;
v_31368:
    v_31378 = stack[0];
    fn = elt(env, 1); // aex_ex
    v_31378 = (*qfn1(fn))(fn, v_31378);
    env = stack[-2];
    fn = elt(env, 2); // negsq
    stack[-1] = (*qfn1(fn))(fn, v_31378);
    env = stack[-2];
    goto v_31369;
v_31370:
    v_31378 = stack[0];
    fn = elt(env, 3); // aex_ctx
    v_31378 = (*qfn1(fn))(fn, v_31378);
    env = stack[-2];
    goto v_31371;
v_31372:
    goto v_31368;
v_31369:
    goto v_31370;
v_31371:
    {
        LispObject v_31381 = stack[-1];
        fn = elt(env, 4); // aex_mk
        return (*qfn2(fn))(fn, v_31381, v_31378);
    }
}



// Code for varsinsf

static LispObject CC_varsinsf(LispObject env,
                         LispObject v_31365, LispObject v_31366)
{
    env = qenv(env);
    LispObject v_31431, v_31432;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31366,v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31365,v_31366);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_31431 = v_31366;
    stack[-1] = v_31365;
// end of prologue
    v_31432 = stack[-1];
    if (!consp(v_31432)) goto v_31374;
    else goto v_31375;
v_31374:
    v_31432 = lisp_true;
    goto v_31373;
v_31375:
    v_31432 = stack[-1];
    v_31432 = qcar(v_31432);
    v_31432 = (consp(v_31432) ? nil : lisp_true);
    goto v_31373;
    v_31432 = nil;
v_31373:
    if (v_31432 == nil) goto v_31371;
    goto v_31369;
v_31371:
v_31390:
    v_31432 = stack[-1];
    if (!consp(v_31432)) goto v_31397;
    else goto v_31398;
v_31397:
    v_31432 = lisp_true;
    goto v_31396;
v_31398:
    v_31432 = stack[-1];
    v_31432 = qcar(v_31432);
    v_31432 = (consp(v_31432) ? nil : lisp_true);
    goto v_31396;
    v_31432 = nil;
v_31396:
    if (v_31432 == nil) goto v_31394;
    goto v_31389;
v_31394:
    goto v_31412;
v_31408:
    v_31432 = stack[-1];
    v_31432 = qcar(v_31432);
    stack[-2] = qcdr(v_31432);
    goto v_31409;
v_31410:
    goto v_31421;
v_31417:
    stack[0] = v_31431;
    goto v_31418;
v_31419:
    v_31431 = stack[-1];
    v_31431 = qcar(v_31431);
    v_31431 = qcar(v_31431);
    v_31431 = qcar(v_31431);
    v_31431 = ncons(v_31431);
    env = stack[-3];
    goto v_31420;
v_31421:
    goto v_31417;
v_31418:
    goto v_31419;
v_31420:
    fn = elt(env, 1); // union
    v_31431 = (*qfn2(fn))(fn, stack[0], v_31431);
    env = stack[-3];
    goto v_31411;
v_31412:
    goto v_31408;
v_31409:
    goto v_31410;
v_31411:
    v_31431 = CC_varsinsf(elt(env, 0), stack[-2], v_31431);
    env = stack[-3];
    v_31432 = stack[-1];
    v_31432 = qcdr(v_31432);
    stack[-1] = v_31432;
    goto v_31390;
v_31389:
    goto v_31369;
    v_31431 = nil;
v_31369:
    return onevalue(v_31431);
}



// Code for mkratnum

static LispObject CC_mkratnum(LispObject env,
                         LispObject v_31365)
{
    env = qenv(env);
    LispObject v_31417, v_31418, v_31419;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31365);
    }
// copy arguments values to proper place
    v_31419 = v_31365;
// end of prologue
    v_31417 = v_31419;
    if (!consp(v_31417)) goto v_31369;
    else goto v_31370;
v_31369:
    v_31417 = v_31419;
    {
        fn = elt(env, 4); // !*i2rn
        return (*qfn1(fn))(fn, v_31417);
    }
v_31370:
    goto v_31380;
v_31376:
    v_31417 = v_31419;
    v_31418 = qcar(v_31417);
    goto v_31377;
v_31378:
    v_31417 = elt(env, 1); // !:gi!:
    goto v_31379;
v_31380:
    goto v_31376;
v_31377:
    goto v_31378;
v_31379:
    if (v_31418 == v_31417) goto v_31374;
    else goto v_31375;
v_31374:
    goto v_31389;
v_31385:
    goto v_31395;
v_31391:
    v_31418 = elt(env, 1); // !:gi!:
    goto v_31392;
v_31393:
    v_31417 = elt(env, 2); // !:crn!:
    goto v_31394;
v_31395:
    goto v_31391;
v_31392:
    goto v_31393;
v_31394:
    v_31417 = get(v_31418, v_31417);
    goto v_31386;
v_31387:
    v_31418 = v_31419;
    goto v_31388;
v_31389:
    goto v_31385;
v_31386:
    goto v_31387;
v_31388:
        return Lapply1(nil, v_31417, v_31418);
v_31375:
    goto v_31406;
v_31402:
    goto v_31412;
v_31408:
    v_31417 = v_31419;
    v_31418 = qcar(v_31417);
    goto v_31409;
v_31410:
    v_31417 = elt(env, 3); // !:rn!:
    goto v_31411;
v_31412:
    goto v_31408;
v_31409:
    goto v_31410;
v_31411:
    v_31417 = get(v_31418, v_31417);
    goto v_31403;
v_31404:
    v_31418 = v_31419;
    goto v_31405;
v_31406:
    goto v_31402;
v_31403:
    goto v_31404;
v_31405:
        return Lapply1(nil, v_31417, v_31418);
    v_31417 = nil;
    return onevalue(v_31417);
}



// Code for xpartitsq

static LispObject CC_xpartitsq(LispObject env,
                         LispObject v_31365)
{
    env = qenv(env);
    LispObject v_31546, v_31547, v_31548;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31365);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_31548 = v_31365;
// end of prologue
    v_31546 = v_31548;
    v_31547 = qcar(v_31546);
    v_31546 = v_31548;
    v_31546 = qcdr(v_31546);
    stack[-2] = v_31547;
    stack[-1] = v_31546;
    v_31546 = stack[-2];
    if (v_31546 == nil) goto v_31375;
    else goto v_31376;
v_31375:
    v_31546 = nil;
    goto v_31374;
v_31376:
    v_31546 = stack[-2];
    if (!consp(v_31546)) goto v_31383;
    else goto v_31384;
v_31383:
    v_31546 = lisp_true;
    goto v_31382;
v_31384:
    v_31546 = stack[-2];
    v_31546 = qcar(v_31546);
    v_31546 = (consp(v_31546) ? nil : lisp_true);
    goto v_31382;
    v_31546 = nil;
v_31382:
    if (v_31546 == nil) goto v_31380;
    goto v_31398;
v_31394:
    v_31546 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31395;
v_31396:
    v_31547 = v_31548;
    goto v_31397;
v_31398:
    goto v_31394;
v_31395:
    goto v_31396;
v_31397:
    v_31546 = cons(v_31546, v_31547);
    return ncons(v_31546);
v_31380:
    goto v_31408;
v_31404:
    v_31546 = stack[-2];
    v_31546 = qcar(v_31546);
    v_31546 = qcar(v_31546);
    v_31546 = qcar(v_31546);
    fn = elt(env, 1); // sfp
    v_31546 = (*qfn1(fn))(fn, v_31546);
    env = stack[-3];
    if (v_31546 == nil) goto v_31412;
    goto v_31423;
v_31419:
    goto v_31429;
v_31425:
    goto v_31436;
v_31432:
    v_31546 = stack[-2];
    v_31546 = qcar(v_31546);
    v_31546 = qcar(v_31546);
    v_31547 = qcar(v_31546);
    goto v_31433;
v_31434:
    v_31546 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31435;
v_31436:
    goto v_31432;
v_31433:
    goto v_31434;
v_31435:
    v_31546 = cons(v_31547, v_31546);
    env = stack[-3];
    v_31547 = CC_xpartitsq(elt(env, 0), v_31546);
    env = stack[-3];
    goto v_31426;
v_31427:
    v_31546 = stack[-2];
    v_31546 = qcar(v_31546);
    v_31546 = qcar(v_31546);
    v_31546 = qcdr(v_31546);
    goto v_31428;
v_31429:
    goto v_31425;
v_31426:
    goto v_31427;
v_31428:
    fn = elt(env, 2); // xexptpf
    stack[0] = (*qfn2(fn))(fn, v_31547, v_31546);
    env = stack[-3];
    goto v_31420;
v_31421:
    goto v_31453;
v_31449:
    v_31546 = stack[-2];
    v_31546 = qcar(v_31546);
    v_31547 = qcdr(v_31546);
    goto v_31450;
v_31451:
    v_31546 = stack[-1];
    goto v_31452;
v_31453:
    goto v_31449;
v_31450:
    goto v_31451;
v_31452:
    v_31546 = cons(v_31547, v_31546);
    env = stack[-3];
    fn = elt(env, 3); // cancel
    v_31546 = (*qfn1(fn))(fn, v_31546);
    env = stack[-3];
    v_31546 = CC_xpartitsq(elt(env, 0), v_31546);
    env = stack[-3];
    goto v_31422;
v_31423:
    goto v_31419;
v_31420:
    goto v_31421;
v_31422:
    fn = elt(env, 4); // wedgepf
    v_31546 = (*qfn2(fn))(fn, stack[0], v_31546);
    env = stack[-3];
    stack[0] = v_31546;
    goto v_31410;
v_31412:
    v_31546 = stack[-2];
    v_31546 = qcar(v_31546);
    v_31546 = qcar(v_31546);
    v_31546 = qcar(v_31546);
    fn = elt(env, 5); // xvarp
    v_31546 = (*qfn1(fn))(fn, v_31546);
    env = stack[-3];
    if (v_31546 == nil) goto v_31459;
    goto v_31470;
v_31466:
    goto v_31476;
v_31472:
    v_31546 = stack[-2];
    v_31546 = qcar(v_31546);
    v_31546 = qcar(v_31546);
    v_31546 = qcar(v_31546);
    fn = elt(env, 6); // xpartitk
    v_31547 = (*qfn1(fn))(fn, v_31546);
    env = stack[-3];
    goto v_31473;
v_31474:
    v_31546 = stack[-2];
    v_31546 = qcar(v_31546);
    v_31546 = qcar(v_31546);
    v_31546 = qcdr(v_31546);
    goto v_31475;
v_31476:
    goto v_31472;
v_31473:
    goto v_31474;
v_31475:
    fn = elt(env, 2); // xexptpf
    stack[0] = (*qfn2(fn))(fn, v_31547, v_31546);
    env = stack[-3];
    goto v_31467;
v_31468:
    goto v_31493;
v_31489:
    v_31546 = stack[-2];
    v_31546 = qcar(v_31546);
    v_31547 = qcdr(v_31546);
    goto v_31490;
v_31491:
    v_31546 = stack[-1];
    goto v_31492;
v_31493:
    goto v_31489;
v_31490:
    goto v_31491;
v_31492:
    v_31546 = cons(v_31547, v_31546);
    env = stack[-3];
    fn = elt(env, 3); // cancel
    v_31546 = (*qfn1(fn))(fn, v_31546);
    env = stack[-3];
    v_31546 = CC_xpartitsq(elt(env, 0), v_31546);
    env = stack[-3];
    goto v_31469;
v_31470:
    goto v_31466;
v_31467:
    goto v_31468;
v_31469:
    fn = elt(env, 4); // wedgepf
    v_31546 = (*qfn2(fn))(fn, stack[0], v_31546);
    env = stack[-3];
    stack[0] = v_31546;
    goto v_31410;
v_31459:
    goto v_31505;
v_31501:
    goto v_31513;
v_31509:
    v_31546 = stack[-2];
    v_31546 = qcar(v_31546);
    v_31547 = qcdr(v_31546);
    goto v_31510;
v_31511:
    v_31546 = stack[-1];
    goto v_31512;
v_31513:
    goto v_31509;
v_31510:
    goto v_31511;
v_31512:
    v_31546 = cons(v_31547, v_31546);
    env = stack[-3];
    fn = elt(env, 3); // cancel
    v_31546 = (*qfn1(fn))(fn, v_31546);
    env = stack[-3];
    stack[0] = CC_xpartitsq(elt(env, 0), v_31546);
    env = stack[-3];
    goto v_31502;
v_31503:
    goto v_31523;
v_31519:
    goto v_31530;
v_31526:
    v_31546 = stack[-2];
    v_31546 = qcar(v_31546);
    v_31547 = qcar(v_31546);
    goto v_31527;
v_31528:
    v_31546 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31529;
v_31530:
    goto v_31526;
v_31527:
    goto v_31528;
v_31529:
    v_31546 = cons(v_31547, v_31546);
    env = stack[-3];
    v_31547 = ncons(v_31546);
    env = stack[-3];
    goto v_31520;
v_31521:
    v_31546 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31522;
v_31523:
    goto v_31519;
v_31520:
    goto v_31521;
v_31522:
    v_31546 = cons(v_31547, v_31546);
    env = stack[-3];
    goto v_31504;
v_31505:
    goto v_31501;
v_31502:
    goto v_31503;
v_31504:
    fn = elt(env, 7); // multpfsq
    v_31546 = (*qfn2(fn))(fn, stack[0], v_31546);
    env = stack[-3];
    stack[0] = v_31546;
    goto v_31410;
    stack[0] = nil;
v_31410:
    goto v_31405;
v_31406:
    goto v_31542;
v_31538:
    v_31546 = stack[-2];
    v_31547 = qcdr(v_31546);
    goto v_31539;
v_31540:
    v_31546 = stack[-1];
    goto v_31541;
v_31542:
    goto v_31538;
v_31539:
    goto v_31540;
v_31541:
    v_31546 = cons(v_31547, v_31546);
    env = stack[-3];
    v_31546 = CC_xpartitsq(elt(env, 0), v_31546);
    env = stack[-3];
    goto v_31407;
v_31408:
    goto v_31404;
v_31405:
    goto v_31406;
v_31407:
    {
        LispObject v_31552 = stack[0];
        fn = elt(env, 8); // addpf
        return (*qfn2(fn))(fn, v_31552, v_31546);
    }
    v_31546 = nil;
v_31374:
    return onevalue(v_31546);
}



// Code for binc

static LispObject CC_binc(LispObject env,
                         LispObject v_31365, LispObject v_31366)
{
    env = qenv(env);
    LispObject v_31402, v_31403, v_31404;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31366,v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31365,v_31366);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31366;
    v_31404 = v_31365;
// end of prologue
    goto v_31376;
v_31372:
    v_31403 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31373;
v_31374:
    v_31402 = stack[0];
    goto v_31375;
v_31376:
    goto v_31372;
v_31373:
    goto v_31374;
v_31375:
    if (v_31403 == v_31402) goto v_31370;
    else goto v_31371;
v_31370:
    v_31402 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31369;
v_31371:
    goto v_31387;
v_31383:
    goto v_31396;
v_31390:
    goto v_31391;
v_31392:
    v_31403 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31393;
v_31394:
    v_31402 = stack[0];
    goto v_31395;
v_31396:
    goto v_31390;
v_31391:
    goto v_31392;
v_31393:
    goto v_31394;
v_31395:
    fn = elt(env, 1); // mk!-numr
    v_31402 = (*qfnn(fn))(fn, 3, v_31404, v_31403, v_31402);
    env = stack[-2];
    fn = elt(env, 2); // constimes
    stack[-1] = (*qfn1(fn))(fn, v_31402);
    env = stack[-2];
    goto v_31384;
v_31385:
    v_31402 = stack[0];
    fn = elt(env, 3); // factorial
    v_31402 = (*qfn1(fn))(fn, v_31402);
    env = stack[-2];
    goto v_31386;
v_31387:
    goto v_31383;
v_31384:
    goto v_31385;
v_31386:
    {
        LispObject v_31407 = stack[-1];
        fn = elt(env, 4); // listquotient
        return (*qfn2(fn))(fn, v_31407, v_31402);
    }
    v_31402 = nil;
v_31369:
    return onevalue(v_31402);
}



// Code for gi

static LispObject CC_gi(LispObject env,
                         LispObject v_31366, LispObject v_31367)
{
    env = qenv(env);
    LispObject v_31414, v_31415;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31367,v_31366);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31366,v_31367);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_31367;
    v_31414 = v_31366;
// end of prologue
// Binding gg!*
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = v_31414; // gg!*
    stack[-2] = nil;
    v_31414 = qvalue(elt(env, 1)); // gg!*
    stack[-1] = v_31414;
v_31379:
    v_31414 = stack[-1];
    if (v_31414 == nil) goto v_31383;
    else goto v_31384;
v_31383:
    goto v_31378;
v_31384:
    v_31414 = stack[-1];
    v_31414 = qcar(v_31414);
    stack[0] = v_31414;
    goto v_31398;
v_31394:
    v_31414 = stack[0];
    v_31414 = qcdr(v_31414);
    fn = elt(env, 2); // class
    v_31415 = (*qfn1(fn))(fn, v_31414);
    env = stack[-5];
    goto v_31395;
v_31396:
    v_31414 = stack[-3];
    goto v_31397;
v_31398:
    goto v_31394;
v_31395:
    goto v_31396;
v_31397:
    if (equal(v_31415, v_31414)) goto v_31392;
    else goto v_31393;
v_31392:
    goto v_31408;
v_31404:
    v_31415 = stack[0];
    goto v_31405;
v_31406:
    v_31414 = stack[-2];
    goto v_31407;
v_31408:
    goto v_31404;
v_31405:
    goto v_31406;
v_31407:
    v_31414 = cons(v_31415, v_31414);
    env = stack[-5];
    stack[-2] = v_31414;
    goto v_31391;
v_31393:
v_31391:
    v_31414 = stack[-1];
    v_31414 = qcdr(v_31414);
    stack[-1] = v_31414;
    goto v_31379;
v_31378:
    v_31414 = stack[-2];
    ;}  // end of a binding scope
    return onevalue(v_31414);
}



// Code for exports

static LispObject CC_exports(LispObject env,
                         LispObject v_31365)
{
    env = qenv(env);
    LispObject v_31377, v_31378;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31365);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31377 = v_31365;
// end of prologue
    goto v_31374;
v_31370:
    v_31378 = v_31377;
    goto v_31371;
v_31372:
    v_31377 = qvalue(elt(env, 1)); // exportslist!*
    goto v_31373;
v_31374:
    goto v_31370;
v_31371:
    goto v_31372;
v_31373:
    fn = elt(env, 2); // union
    v_31377 = (*qfn2(fn))(fn, v_31378, v_31377);
    env = stack[0];
    qvalue(elt(env, 1)) = v_31377; // exportslist!*
    v_31377 = nil;
    return onevalue(v_31377);
}



// Code for square!-free!-mod!-p

static LispObject CC_squareKfreeKmodKp(LispObject env,
                         LispObject v_31365)
{
    env = qenv(env);
    LispObject v_31406, v_31407;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31365);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31407 = v_31365;
// end of prologue
    v_31406 = v_31407;
    if (!consp(v_31406)) goto v_31373;
    else goto v_31374;
v_31373:
    v_31406 = lisp_true;
    goto v_31372;
v_31374:
    v_31406 = v_31407;
    v_31406 = qcar(v_31406);
    v_31406 = (consp(v_31406) ? nil : lisp_true);
    goto v_31372;
    v_31406 = nil;
v_31372:
    if (v_31406 == nil) goto v_31370;
    v_31406 = lisp_true;
    goto v_31368;
v_31370:
    goto v_31390;
v_31386:
    stack[0] = v_31407;
    goto v_31387;
v_31388:
    v_31406 = v_31407;
    fn = elt(env, 1); // derivative!-mod!-p
    v_31406 = (*qfn1(fn))(fn, v_31406);
    env = stack[-1];
    goto v_31389;
v_31390:
    goto v_31386;
v_31387:
    goto v_31388;
v_31389:
    fn = elt(env, 2); // gcd!-mod!-p
    v_31406 = (*qfn2(fn))(fn, stack[0], v_31406);
    v_31407 = v_31406;
    v_31406 = v_31407;
    if (!consp(v_31406)) goto v_31397;
    else goto v_31398;
v_31397:
    v_31406 = lisp_true;
    goto v_31396;
v_31398:
    v_31406 = v_31407;
    v_31406 = qcar(v_31406);
    v_31406 = (consp(v_31406) ? nil : lisp_true);
    goto v_31396;
    v_31406 = nil;
v_31396:
    goto v_31368;
    v_31406 = nil;
v_31368:
    return onevalue(v_31406);
}



// Code for addinds

static LispObject CC_addinds(LispObject env,
                         LispObject v_31365, LispObject v_31366)
{
    env = qenv(env);
    LispObject v_31431, v_31432;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31366,v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31365,v_31366);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31366;
    stack[-1] = v_31365;
// end of prologue
    stack[-2] = nil;
v_31371:
    v_31431 = stack[-1];
    if (v_31431 == nil) goto v_31374;
    else goto v_31375;
v_31374:
    v_31431 = stack[0];
    if (v_31431 == nil) goto v_31379;
    else goto v_31380;
v_31379:
    v_31431 = stack[-2];
    {
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(fn, v_31431);
    }
v_31380:
    goto v_31391;
v_31387:
    stack[0] = stack[-2];
    goto v_31388;
v_31389:
    v_31431 = elt(env, 1); // "Powrhs too long"
    fn = elt(env, 4); // interr
    v_31431 = (*qfn1(fn))(fn, v_31431);
    env = stack[-3];
    goto v_31390;
v_31391:
    goto v_31387;
v_31388:
    goto v_31389;
v_31390:
    {
        LispObject v_31436 = stack[0];
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(fn, v_31436, v_31431);
    }
    goto v_31373;
v_31375:
    v_31431 = stack[0];
    if (v_31431 == nil) goto v_31395;
    else goto v_31396;
v_31395:
    goto v_31403;
v_31399:
    stack[0] = stack[-2];
    goto v_31400;
v_31401:
    v_31431 = elt(env, 2); // "Powu too long"
    fn = elt(env, 4); // interr
    v_31431 = (*qfn1(fn))(fn, v_31431);
    env = stack[-3];
    goto v_31402;
v_31403:
    goto v_31399;
v_31400:
    goto v_31401;
v_31402:
    {
        LispObject v_31437 = stack[0];
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(fn, v_31437, v_31431);
    }
v_31396:
    goto v_31414;
v_31410:
    goto v_31420;
v_31416:
    v_31431 = stack[-1];
    v_31432 = qcar(v_31431);
    goto v_31417;
v_31418:
    v_31431 = stack[0];
    v_31431 = qcar(v_31431);
    v_31431 = qcar(v_31431);
    goto v_31419;
v_31420:
    goto v_31416;
v_31417:
    goto v_31418;
v_31419:
    v_31432 = plus2(v_31432, v_31431);
    env = stack[-3];
    goto v_31411;
v_31412:
    v_31431 = stack[-2];
    goto v_31413;
v_31414:
    goto v_31410;
v_31411:
    goto v_31412;
v_31413:
    v_31431 = cons(v_31432, v_31431);
    env = stack[-3];
    stack[-2] = v_31431;
    v_31431 = stack[-1];
    v_31431 = qcdr(v_31431);
    stack[-1] = v_31431;
    v_31431 = stack[0];
    v_31431 = qcdr(v_31431);
    stack[0] = v_31431;
    goto v_31371;
v_31373:
    v_31431 = nil;
    return onevalue(v_31431);
}



// Code for subscriptedvarp2

static LispObject CC_subscriptedvarp2(LispObject env,
                         LispObject v_31365)
{
    env = qenv(env);
    LispObject v_31383, v_31384;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31365);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31383 = v_31365;
// end of prologue
    goto v_31372;
v_31368:
    goto v_31379;
v_31375:
    v_31384 = nil;
    goto v_31376;
v_31377:
    goto v_31378;
v_31379:
    goto v_31375;
v_31376:
    goto v_31377;
v_31378:
    fn = elt(env, 1); // symtabget
    v_31383 = (*qfn2(fn))(fn, v_31384, v_31383);
    env = stack[0];
    v_31384 = Llength(nil, v_31383);
    goto v_31369;
v_31370:
    v_31383 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31371;
v_31372:
    goto v_31368;
v_31369:
    goto v_31370;
v_31371:
        return Lgreaterp(nil, v_31384, v_31383);
}



// Code for evalsubset

static LispObject CC_evalsubset(LispObject env,
                         LispObject v_31365, LispObject v_31366)
{
    env = qenv(env);
    LispObject v_31390, v_31391, v_31392;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31366,v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31365,v_31366);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31390 = v_31366;
    v_31391 = v_31365;
// end of prologue
    goto v_31375;
v_31369:
    v_31392 = elt(env, 1); // subset
    goto v_31370;
v_31371:
    goto v_31372;
v_31373:
    goto v_31374;
v_31375:
    goto v_31369;
v_31370:
    goto v_31371;
v_31372:
    goto v_31373;
v_31374:
    fn = elt(env, 2); // evalsetbool
    v_31390 = (*qfnn(fn))(fn, 3, v_31392, v_31391, v_31390);
    env = stack[0];
    v_31391 = v_31390;
    v_31390 = v_31391;
    if (!consp(v_31390)) goto v_31382;
    else goto v_31383;
v_31382:
    v_31390 = v_31391;
    goto v_31381;
v_31383:
    v_31390 = v_31391;
    {
        fn = elt(env, 3); // evalsymsubset
        return (*qfn1(fn))(fn, v_31390);
    }
    v_31390 = nil;
v_31381:
    return onevalue(v_31390);
}



// Code for !*kp2q

static LispObject CC_Hkp2q(LispObject env,
                         LispObject v_31365, LispObject v_31366)
{
    env = qenv(env);
    LispObject v_31418, v_31419;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31366,v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31365,v_31366);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31366;
    stack[-1] = v_31365;
// end of prologue
    goto v_31377;
v_31373:
    v_31419 = stack[0];
    goto v_31374;
v_31375:
    v_31418 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31376;
v_31377:
    goto v_31373;
v_31374:
    goto v_31375;
v_31376:
    v_31418 = (LispObject)greaterp2(v_31419, v_31418);
    v_31418 = v_31418 ? lisp_true : nil;
    env = stack[-2];
    if (v_31418 == nil) goto v_31371;
    goto v_31385;
v_31381:
    v_31419 = stack[-1];
    goto v_31382;
v_31383:
    v_31418 = stack[0];
    goto v_31384;
v_31385:
    goto v_31381;
v_31382:
    goto v_31383;
v_31384:
    {
        fn = elt(env, 2); // mksq
        return (*qfn2(fn))(fn, v_31419, v_31418);
    }
v_31371:
    v_31418 = stack[0];
    v_31418 = (LispObject)zerop(v_31418);
    v_31418 = v_31418 ? lisp_true : nil;
    env = stack[-2];
    if (v_31418 == nil) goto v_31389;
    goto v_31397;
v_31393:
    v_31419 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31394;
v_31395:
    v_31418 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31396;
v_31397:
    goto v_31393;
v_31394:
    goto v_31395;
v_31396:
    return cons(v_31419, v_31418);
v_31389:
    goto v_31407;
v_31403:
    goto v_31404;
v_31405:
    v_31418 = stack[0];
    v_31418 = negate(v_31418);
    env = stack[-2];
    goto v_31406;
v_31407:
    goto v_31403;
v_31404:
    goto v_31405;
v_31406:
    fn = elt(env, 2); // mksq
    v_31418 = (*qfn2(fn))(fn, stack[-1], v_31418);
    env = stack[-2];
    stack[-1] = v_31418;
    v_31418 = qcar(v_31418);
    if (v_31418 == nil) goto v_31400;
    else goto v_31401;
v_31400:
    v_31418 = elt(env, 1); // "Zero divisor"
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_31418);
    }
v_31401:
    v_31418 = stack[-1];
    {
        fn = elt(env, 4); // revpr
        return (*qfn1(fn))(fn, v_31418);
    }
    v_31418 = nil;
    return onevalue(v_31418);
}



// Code for calc_world

static LispObject CC_calc_world(LispObject env,
                         LispObject v_31365, LispObject v_31366)
{
    env = qenv(env);
    LispObject v_31429, v_31430;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31366,v_31365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31365,v_31366);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_31366;
    stack[-2] = v_31365;
// end of prologue
    goto v_31377;
v_31373:
    stack[0] = stack[-1];
    goto v_31374;
v_31375:
    v_31429 = stack[-2];
    fn = elt(env, 1); // s_world_names
    v_31429 = (*qfn1(fn))(fn, v_31429);
    env = stack[-4];
    goto v_31376;
v_31377:
    goto v_31373;
v_31374:
    goto v_31375;
v_31376:
    fn = elt(env, 2); // actual_alst
    v_31429 = (*qfn2(fn))(fn, stack[0], v_31429);
    env = stack[-4];
    stack[-1] = v_31429;
    v_31429 = stack[-2];
    v_31429 = qcdr(v_31429);
    v_31429 = qcar(v_31429);
    stack[0] = v_31429;
    goto v_31388;
v_31384:
    v_31430 = stack[-1];
    goto v_31385;
v_31386:
    v_31429 = stack[0];
    v_31429 = qcdr(v_31429);
    goto v_31387;
v_31388:
    goto v_31384;
v_31385:
    goto v_31386;
v_31387:
    v_31429 = Lassoc(nil, v_31430, v_31429);
    stack[-3] = v_31429;
    v_31429 = stack[-3];
    if (v_31429 == nil) goto v_31396;
    v_31429 = stack[-3];
    v_31429 = qcdr(v_31429);
    goto v_31371;
v_31396:
    goto v_31406;
v_31402:
    v_31429 = stack[-2];
    v_31429 = qcdr(v_31429);
    v_31429 = qcdr(v_31429);
    v_31430 = qcar(v_31429);
    goto v_31403;
v_31404:
    v_31429 = stack[-1];
    goto v_31405;
v_31406:
    goto v_31402;
v_31403:
    goto v_31404;
v_31405:
    fn = elt(env, 3); // calc_atlas
    v_31429 = (*qfn2(fn))(fn, v_31430, v_31429);
    env = stack[-4];
    fn = elt(env, 4); // reval
    v_31429 = (*qfn1(fn))(fn, v_31429);
    env = stack[-4];
    stack[-3] = v_31429;
    goto v_31417;
v_31413:
    goto v_31414;
v_31415:
    goto v_31425;
v_31421:
    v_31430 = stack[-1];
    goto v_31422;
v_31423:
    v_31429 = stack[-3];
    goto v_31424;
v_31425:
    goto v_31421;
v_31422:
    goto v_31423;
v_31424:
    v_31429 = cons(v_31430, v_31429);
    env = stack[-4];
    v_31429 = ncons(v_31429);
    env = stack[-4];
    goto v_31416;
v_31417:
    goto v_31413;
v_31414:
    goto v_31415;
v_31416:
    v_31429 = Lnconc(nil, stack[0], v_31429);
    v_31429 = stack[-3];
v_31371:
    return onevalue(v_31429);
}



setup_type const u54_setup[] =
{
    {"simpx1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_simpx1},
    {"equal+matrices+p",        TOO_FEW_2,      CC_equalLmatricesLp,WRONG_NO_2},
    {"talp_try2",               CC_talp_try2,   TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_simpat",             CC_ofsf_simpat, TOO_MANY_1,    WRONG_NO_1},
    {"quotfx1",                 TOO_FEW_2,      CC_quotfx1,    WRONG_NO_2},
    {"sfto_dprpartf1",          TOO_FEW_2,      CC_sfto_dprpartf1,WRONG_NO_2},
    {"parseml",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_parseml},
    {"ldf-pow-var",             CC_ldfKpowKvar, TOO_MANY_1,    WRONG_NO_1},
    {"vdpappendmon",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vdpappendmon},
    {"fast-augment-columns",    TOO_FEW_2,      CC_fastKaugmentKcolumns,WRONG_NO_2},
    {"atlas_edges",             CC_atlas_edges, TOO_MANY_1,    WRONG_NO_1},
    {"compactf3",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_compactf3},
    {"mo=pair",                 TOO_FEW_2,      CC_moMpair,    WRONG_NO_2},
    {"*v2j",                    CC_Hv2j,        TOO_MANY_1,    WRONG_NO_1},
    {"dummy_nam",               CC_dummy_nam,   TOO_MANY_1,    WRONG_NO_1},
    {"general-negate-term",     CC_generalKnegateKterm,TOO_MANY_1,WRONG_NO_1},
    {"initmonomials",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_initmonomials},
    {"rl_ex",                   TOO_FEW_2,      CC_rl_ex,      WRONG_NO_2},
    {"*invsq",                  CC_Hinvsq,      TOO_MANY_1,    WRONG_NO_1},
    {"multtaylorsq",            TOO_FEW_2,      CC_multtaylorsq,WRONG_NO_2},
    {"depend-p",                TOO_FEW_2,      CC_dependKp,   WRONG_NO_2},
    {"qqe_length-graph-bterm",  TOO_FEW_2,      CC_qqe_lengthKgraphKbterm,WRONG_NO_2},
    {"pasf_exprng",             CC_pasf_exprng, TOO_MANY_1,    WRONG_NO_1},
    {"aex_neg",                 CC_aex_neg,     TOO_MANY_1,    WRONG_NO_1},
    {"varsinsf",                TOO_FEW_2,      CC_varsinsf,   WRONG_NO_2},
    {"mkratnum",                CC_mkratnum,    TOO_MANY_1,    WRONG_NO_1},
    {"xpartitsq",               CC_xpartitsq,   TOO_MANY_1,    WRONG_NO_1},
    {"binc",                    TOO_FEW_2,      CC_binc,       WRONG_NO_2},
    {"gi",                      TOO_FEW_2,      CC_gi,         WRONG_NO_2},
    {"exports",                 CC_exports,     TOO_MANY_1,    WRONG_NO_1},
    {"square-free-mod-p",       CC_squareKfreeKmodKp,TOO_MANY_1,WRONG_NO_1},
    {"addinds",                 TOO_FEW_2,      CC_addinds,    WRONG_NO_2},
    {"subscriptedvarp2",        CC_subscriptedvarp2,TOO_MANY_1,WRONG_NO_1},
    {"evalsubset",              TOO_FEW_2,      CC_evalsubset, WRONG_NO_2},
    {"*kp2q",                   TOO_FEW_2,      CC_Hkp2q,      WRONG_NO_2},
    {"calc_world",              TOO_FEW_2,      CC_calc_world, WRONG_NO_2},
    {NULL, (one_args *)"u54", (two_args *)"165586 3852540 3856699", 0}
};

// end of generated code
