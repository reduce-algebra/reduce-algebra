
// $destdir/u44.c        Machine generated C code

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



// Code for cl_gand!-col

static LispObject CC_cl_gandKcol(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25179, v_25180, v_25181;
    LispObject fn;
    LispObject v_24982, v_24981, v_24980, v_24979;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_gand-col");
    va_start(aa, nargs);
    v_24979 = va_arg(aa, LispObject);
    v_24980 = va_arg(aa, LispObject);
    v_24981 = va_arg(aa, LispObject);
    v_24982 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_24982,v_24981,v_24980,v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_24979,v_24980,v_24981,v_24982);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-4] = v_24982;
    stack[-5] = v_24981;
    stack[-6] = v_24980;
    stack[-7] = v_24979;
// end of prologue
    stack[-8] = nil;
    goto v_24995;
v_24991:
    v_25181 = elt(env, 1); // true
    goto v_24992;
v_24993:
    goto v_25001;
v_24997:
    v_25180 = stack[-5];
    goto v_24998;
v_24999:
    v_25179 = elt(env, 2); // and
    goto v_25000;
v_25001:
    goto v_24997;
v_24998:
    goto v_24999;
v_25000:
    v_25179 = (v_25180 == v_25179 ? lisp_true : nil);
    goto v_24994;
v_24995:
    goto v_24991;
v_24992:
    goto v_24993;
v_24994:
    fn = elt(env, 4); // cl_cflip
    v_25179 = (*qfn2(fn))(fn, v_25181, v_25179);
    env = stack[-9];
    stack[-3] = v_25179;
    v_25179 = stack[-3];
    fn = elt(env, 5); // cl_flip
    v_25179 = (*qfn1(fn))(fn, v_25179);
    env = stack[-9];
    stack[-2] = v_25179;
v_25009:
    v_25179 = stack[-7];
    if (v_25179 == nil) goto v_25012;
    else goto v_25013;
v_25012:
    goto v_25008;
v_25013:
    goto v_25025;
v_25017:
    v_25179 = stack[-7];
    stack[-1] = qcar(v_25179);
    goto v_25018;
v_25019:
    stack[0] = stack[-4];
    goto v_25020;
v_25021:
    v_25179 = stack[-6];
    v_25180 = sub1(v_25179);
    env = stack[-9];
    goto v_25022;
v_25023:
    v_25179 = stack[-5];
    goto v_25024;
v_25025:
    goto v_25017;
v_25018:
    goto v_25019;
v_25020:
    goto v_25021;
v_25022:
    goto v_25023;
v_25024:
    fn = elt(env, 6); // cl_simpl1
    v_25179 = (*qfnn(fn))(fn, 4, stack[-1], stack[0], v_25180, v_25179);
    env = stack[-9];
    v_25181 = v_25179;
    v_25179 = stack[-7];
    v_25179 = qcdr(v_25179);
    stack[-7] = v_25179;
    goto v_25042;
v_25038:
    v_25180 = v_25181;
    goto v_25039;
v_25040:
    v_25179 = stack[-2];
    goto v_25041;
v_25042:
    goto v_25038;
v_25039:
    goto v_25040;
v_25041:
    if (v_25180 == v_25179) goto v_25036;
    else goto v_25037;
v_25036:
    v_25179 = stack[-2];
    v_25179 = ncons(v_25179);
    env = stack[-9];
    stack[-8] = v_25179;
    v_25179 = nil;
    stack[-7] = v_25179;
    goto v_25035;
v_25037:
    goto v_25054;
v_25050:
    v_25180 = v_25181;
    goto v_25051;
v_25052:
    v_25179 = stack[-3];
    goto v_25053;
v_25054:
    goto v_25050;
v_25051:
    goto v_25052;
v_25053:
    if (equal(v_25180, v_25179)) goto v_25049;
    goto v_25065;
v_25061:
    v_25179 = v_25181;
    if (!consp(v_25179)) goto v_25068;
    else goto v_25069;
v_25068:
    v_25179 = v_25181;
    v_25180 = v_25179;
    goto v_25067;
v_25069:
    v_25179 = v_25181;
    v_25179 = qcar(v_25179);
    v_25180 = v_25179;
    goto v_25067;
    v_25180 = nil;
v_25067:
    goto v_25062;
v_25063:
    v_25179 = stack[-5];
    goto v_25064;
v_25065:
    goto v_25061;
v_25062:
    goto v_25063;
v_25064:
    if (v_25180 == v_25179) goto v_25059;
    else goto v_25060;
v_25059:
    v_25179 = qvalue(elt(env, 3)); // !*rlsichk
    if (v_25179 == nil) goto v_25080;
    v_25179 = v_25181;
    v_25179 = qcdr(v_25179);
    stack[0] = v_25179;
v_25085:
    v_25179 = stack[0];
    if (v_25179 == nil) goto v_25090;
    else goto v_25091;
v_25090:
    goto v_25084;
v_25091:
    v_25179 = stack[0];
    v_25179 = qcar(v_25179);
    v_25181 = v_25179;
    goto v_25105;
v_25101:
    v_25180 = v_25181;
    goto v_25102;
v_25103:
    v_25179 = stack[-8];
    goto v_25104;
v_25105:
    goto v_25101;
v_25102:
    goto v_25103;
v_25104:
    v_25179 = Lmember(nil, v_25180, v_25179);
    if (v_25179 == nil) goto v_25099;
    else goto v_25100;
v_25099:
    goto v_25114;
v_25110:
    v_25180 = v_25181;
    goto v_25111;
v_25112:
    v_25179 = stack[-8];
    goto v_25113;
v_25114:
    goto v_25110;
v_25111:
    goto v_25112;
v_25113:
    v_25179 = cons(v_25180, v_25179);
    env = stack[-9];
    stack[-8] = v_25179;
    goto v_25098;
v_25100:
v_25098:
    v_25179 = stack[0];
    v_25179 = qcdr(v_25179);
    stack[0] = v_25179;
    goto v_25085;
v_25084:
    goto v_25078;
v_25080:
    v_25179 = v_25181;
    v_25179 = qcdr(v_25179);
    stack[0] = v_25179;
v_25124:
    v_25179 = stack[0];
    if (v_25179 == nil) goto v_25129;
    else goto v_25130;
v_25129:
    goto v_25123;
v_25130:
    v_25179 = stack[0];
    v_25179 = qcar(v_25179);
    goto v_25141;
v_25137:
    v_25180 = v_25179;
    goto v_25138;
v_25139:
    v_25179 = stack[-8];
    goto v_25140;
v_25141:
    goto v_25137;
v_25138:
    goto v_25139;
v_25140:
    v_25179 = cons(v_25180, v_25179);
    env = stack[-9];
    stack[-8] = v_25179;
    v_25179 = stack[0];
    v_25179 = qcdr(v_25179);
    stack[0] = v_25179;
    goto v_25124;
v_25123:
    goto v_25078;
v_25078:
    goto v_25058;
v_25060:
    v_25179 = qvalue(elt(env, 3)); // !*rlsichk
    if (v_25179 == nil) goto v_25146;
    goto v_25155;
v_25151:
    v_25180 = v_25181;
    goto v_25152;
v_25153:
    v_25179 = stack[-8];
    goto v_25154;
v_25155:
    goto v_25151;
v_25152:
    goto v_25153;
v_25154:
    v_25179 = Lmember(nil, v_25180, v_25179);
    if (v_25179 == nil) goto v_25146;
    goto v_25147;
v_25146:
    goto v_25164;
v_25160:
    v_25180 = v_25181;
    goto v_25161;
v_25162:
    v_25179 = stack[-8];
    goto v_25163;
v_25164:
    goto v_25160;
v_25161:
    goto v_25162;
v_25163:
    v_25179 = cons(v_25180, v_25179);
    env = stack[-9];
    stack[-8] = v_25179;
    goto v_25058;
v_25147:
v_25058:
    goto v_25035;
v_25049:
v_25035:
    goto v_25009;
v_25008:
    v_25179 = stack[-8];
    if (v_25179 == nil) goto v_25171;
    v_25179 = stack[-8];
        return Lnreverse(nil, v_25179);
v_25171:
    v_25179 = stack[-3];
    return ncons(v_25179);
    v_25179 = nil;
    return onevalue(v_25179);
}



// Code for conditionml

static LispObject CC_conditionml(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_24994;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24979);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24979;
// end of prologue
    v_24994 = elt(env, 1); // "<condition>"
    fn = elt(env, 3); // printout
    v_24994 = (*qfn1(fn))(fn, v_24994);
    env = stack[-1];
    v_24994 = lisp_true;
    fn = elt(env, 4); // indent!*
    v_24994 = (*qfn1(fn))(fn, v_24994);
    env = stack[-1];
    v_24994 = stack[0];
    v_24994 = qcar(v_24994);
    fn = elt(env, 5); // expression
    v_24994 = (*qfn1(fn))(fn, v_24994);
    env = stack[-1];
    v_24994 = nil;
    fn = elt(env, 4); // indent!*
    v_24994 = (*qfn1(fn))(fn, v_24994);
    env = stack[-1];
    v_24994 = elt(env, 2); // "</condition>"
    fn = elt(env, 3); // printout
    v_24994 = (*qfn1(fn))(fn, v_24994);
    v_24994 = nil;
    return onevalue(v_24994);
}



// Code for rnfix!*

static LispObject CC_rnfixH(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_24993, v_24994;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24993 = v_24979;
// end of prologue
    goto v_24986;
v_24982:
    v_24994 = v_24993;
    v_24994 = qcdr(v_24994);
    v_24994 = qcar(v_24994);
    goto v_24983;
v_24984:
    v_24993 = qcdr(v_24993);
    v_24993 = qcdr(v_24993);
    goto v_24985;
v_24986:
    goto v_24982;
v_24983:
    goto v_24984;
v_24985:
    return quot2(v_24994, v_24993);
}



// Code for dip2a

static LispObject CC_dip2a(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_24992, v_24993;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24979);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_24993 = v_24979;
// end of prologue
    v_24992 = v_24993;
    if (v_24992 == nil) goto v_24983;
    else goto v_24984;
v_24983:
    v_24992 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24982;
v_24984:
    v_24992 = v_24993;
    fn = elt(env, 1); // dip2a1
    v_24992 = (*qfn1(fn))(fn, v_24992);
    env = stack[0];
    {
        fn = elt(env, 2); // dipreplus
        return (*qfn1(fn))(fn, v_24992);
    }
    v_24992 = nil;
v_24982:
    return onevalue(v_24992);
}



// Code for mkexdf

static LispObject CC_mkexdf(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_25004, v_25005;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24979);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_25004 = v_24979;
// end of prologue
    goto v_24995;
v_24991:
    v_25005 = elt(env, 1); // d
    goto v_24992;
v_24993:
    goto v_24994;
v_24995:
    goto v_24991;
v_24992:
    goto v_24993;
v_24994:
    v_25004 = list2(v_25005, v_25004);
    env = stack[-1];
    stack[0] = v_25004;
    fn = elt(env, 2); // opmtch
    v_25004 = (*qfn1(fn))(fn, v_25004);
    env = stack[-1];
    v_25005 = v_25004;
    if (v_25004 == nil) goto v_24988;
    v_25004 = v_25005;
    {
        fn = elt(env, 3); // partitop
        return (*qfn1(fn))(fn, v_25004);
    }
v_24988:
    v_25004 = stack[0];
    {
        fn = elt(env, 4); // mkupf
        return (*qfn1(fn))(fn, v_25004);
    }
    v_25004 = nil;
    return onevalue(v_25004);
}



// Code for markedvarp

static LispObject CC_markedvarp(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_24989, v_24990;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24989 = v_24979;
// end of prologue
    goto v_24986;
v_24982:
    goto v_24983;
v_24984:
    v_24990 = elt(env, 1); // !*marked!*
    goto v_24985;
v_24986:
    goto v_24982;
v_24983:
    goto v_24984;
v_24985:
        return Lflagp(nil, v_24989, v_24990);
}



// Code for ev!-edgeloop

static LispObject CC_evKedgeloop(LispObject env,
                         LispObject v_24979, LispObject v_24980)
{
    env = qenv(env);
    LispObject v_24999, v_25000, v_25001;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24999 = v_24980;
    v_25000 = v_24979;
// end of prologue
    goto v_24987;
v_24983:
    v_25001 = qvalue(elt(env, 1)); // ndim!*
    goto v_24984;
v_24985:
    goto v_24993;
v_24989:
    v_25000 = qcar(v_25000);
    goto v_24990;
v_24991:
    goto v_24992;
v_24993:
    goto v_24989;
v_24990:
    goto v_24991;
v_24992:
    v_24999 = Lassoc(nil, v_25000, v_24999);
    v_24999 = qcdr(v_24999);
    goto v_24986;
v_24987:
    goto v_24983;
v_24984:
    goto v_24985;
v_24986:
    {
        fn = elt(env, 2); // binc
        return (*qfn2(fn))(fn, v_25001, v_24999);
    }
}



// Code for applsmacro

static LispObject CC_applsmacro(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25382, v_25383, v_25384;
    LispObject fn;
    LispObject v_24981, v_24980, v_24979;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "applsmacro");
    va_start(aa, nargs);
    v_24979 = va_arg(aa, LispObject);
    v_24980 = va_arg(aa, LispObject);
    v_24981 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24981,v_24980,v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24979,v_24980,v_24981);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-2] = v_24981;
    stack[-7] = v_24980;
    v_25383 = v_24979;
// end of prologue
    stack[-6] = nil;
// Binding inlineinfo
// FLUIDBIND: reloadenv=9 litvec-offset=1 saveloc=5
{   bind_fluid_stack bind_fluid_var(-9, 1, -5);
    qvalue(elt(env, 1)) = nil; // inlineinfo
    v_25382 = v_25383;
    v_25382 = qcdr(v_25382);
    v_25382 = qcar(v_25382);
    stack[-3] = v_25382;
    v_25382 = v_25383;
    v_25382 = qcdr(v_25382);
    v_25382 = qcdr(v_25382);
    v_25382 = qcar(v_25382);
    stack[-8] = v_25382;
    goto v_25004;
v_24998:
    v_25384 = stack[-2];
    goto v_24999;
v_25000:
    v_25383 = stack[-3];
    goto v_25001;
v_25002:
    v_25382 = stack[-8];
    goto v_25003;
v_25004:
    goto v_24998;
v_24999:
    goto v_25000;
v_25001:
    goto v_25002;
v_25003:
    v_25382 = list3(v_25384, v_25383, v_25382);
    env = stack[-9];
    qvalue(elt(env, 1)) = v_25382; // inlineinfo
    goto v_25016;
v_25012:
    v_25382 = stack[-3];
    stack[0] = Llength(nil, v_25382);
    env = stack[-9];
    goto v_25013;
v_25014:
    v_25382 = stack[-7];
    v_25382 = Llength(nil, v_25382);
    env = stack[-9];
    goto v_25015;
v_25016:
    goto v_25012;
v_25013:
    goto v_25014;
v_25015:
    if (equal(stack[0], v_25382)) goto v_25011;
    goto v_25028;
v_25022:
    stack[-1] = elt(env, 2); // rlisp
    goto v_25023;
v_25024:
    stack[0] = (LispObject)240+TAG_FIXNUM; // 15
    goto v_25025;
v_25026:
    goto v_25036;
v_25032:
    v_25383 = elt(env, 3); // "Argument mismatch for SMACRO"
    goto v_25033;
v_25034:
    v_25382 = stack[-2];
    goto v_25035;
v_25036:
    goto v_25032;
v_25033:
    goto v_25034;
v_25035:
    v_25382 = list2(v_25383, v_25382);
    env = stack[-9];
    goto v_25027;
v_25028:
    goto v_25022;
v_25023:
    goto v_25024;
v_25025:
    goto v_25026;
v_25027:
    fn = elt(env, 7); // rerror
    v_25382 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_25382);
    env = stack[-9];
    goto v_25009;
v_25011:
v_25009:
    v_25382 = qvalue(elt(env, 4)); // !*loginlines
    if (v_25382 == nil) goto v_25042;
    goto v_25051;
v_25045:
    v_25384 = stack[-3];
    goto v_25046;
v_25047:
    v_25383 = stack[-8];
    goto v_25048;
v_25049:
    v_25382 = stack[-7];
    goto v_25050;
v_25051:
    goto v_25045;
v_25046:
    goto v_25047;
v_25048:
    goto v_25049;
v_25050:
    fn = elt(env, 8); // log_inlines
    v_25382 = (*qfnn(fn))(fn, 3, v_25384, v_25383, v_25382);
    env = stack[-9];
    goto v_25040;
v_25042:
v_25040:
    v_25382 = stack[-7];
    fn = elt(env, 9); // no!-side!-effect!-listp
    v_25382 = (*qfn1(fn))(fn, v_25382);
    env = stack[-9];
    if (v_25382 == nil) goto v_25059;
    else goto v_25057;
v_25059:
    goto v_25068;
v_25064:
    v_25383 = stack[-3];
    goto v_25065;
v_25066:
    v_25382 = stack[-8];
    goto v_25067;
v_25068:
    goto v_25064;
v_25065:
    goto v_25066;
v_25067:
    fn = elt(env, 10); // one!-entry!-listp
    v_25382 = (*qfn2(fn))(fn, v_25383, v_25382);
    env = stack[-9];
    if (v_25382 == nil) goto v_25062;
    else goto v_25057;
v_25062:
    goto v_25058;
v_25057:
    goto v_25076;
v_25072:
    goto v_25082;
v_25078:
    v_25383 = stack[-3];
    goto v_25079;
v_25080:
    v_25382 = stack[-7];
    goto v_25081;
v_25082:
    goto v_25078;
v_25079:
    goto v_25080;
v_25081:
    fn = elt(env, 11); // pair
    v_25383 = (*qfn2(fn))(fn, v_25383, v_25382);
    env = stack[-9];
    goto v_25073;
v_25074:
    v_25382 = stack[-8];
    goto v_25075;
v_25076:
    goto v_25072;
v_25073:
    goto v_25074;
v_25075:
    fn = elt(env, 12); // subla!-q
    v_25382 = (*qfn2(fn))(fn, v_25383, v_25382);
    goto v_24989;
v_25058:
    goto v_25093;
v_25089:
    v_25382 = stack[-3];
    v_25383 = Llength(nil, v_25382);
    env = stack[-9];
    goto v_25090;
v_25091:
    v_25382 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25092;
v_25093:
    goto v_25089;
v_25090:
    goto v_25091;
v_25092:
    v_25382 = (LispObject)greaterp2(v_25383, v_25382);
    v_25382 = v_25382 ? lisp_true : nil;
    env = stack[-9];
    if (v_25382 == nil) goto v_25087;
    v_25382 = stack[-3];
    stack[-4] = v_25382;
    v_25382 = stack[-4];
    if (v_25382 == nil) goto v_25106;
    else goto v_25107;
v_25106:
    v_25382 = nil;
    goto v_25101;
v_25107:
    v_25382 = stack[-4];
    v_25382 = qcar(v_25382);
    goto v_25119;
v_25115:
    stack[0] = v_25382;
    goto v_25116;
v_25117:
    v_25382 = elt(env, 5); // g
    v_25382 = Lgensym1(nil, v_25382);
    env = stack[-9];
    goto v_25118;
v_25119:
    goto v_25115;
v_25116:
    goto v_25117;
v_25118:
    v_25382 = cons(stack[0], v_25382);
    env = stack[-9];
    v_25382 = ncons(v_25382);
    env = stack[-9];
    stack[-2] = v_25382;
    stack[-3] = v_25382;
v_25102:
    v_25382 = stack[-4];
    v_25382 = qcdr(v_25382);
    stack[-4] = v_25382;
    v_25382 = stack[-4];
    if (v_25382 == nil) goto v_25127;
    else goto v_25128;
v_25127:
    v_25382 = stack[-3];
    goto v_25101;
v_25128:
    goto v_25136;
v_25132:
    stack[-1] = stack[-2];
    goto v_25133;
v_25134:
    v_25382 = stack[-4];
    v_25382 = qcar(v_25382);
    goto v_25147;
v_25143:
    stack[0] = v_25382;
    goto v_25144;
v_25145:
    v_25382 = elt(env, 5); // g
    v_25382 = Lgensym1(nil, v_25382);
    env = stack[-9];
    goto v_25146;
v_25147:
    goto v_25143;
v_25144:
    goto v_25145;
v_25146:
    v_25382 = cons(stack[0], v_25382);
    env = stack[-9];
    v_25382 = ncons(v_25382);
    env = stack[-9];
    goto v_25135;
v_25136:
    goto v_25132;
v_25133:
    goto v_25134;
v_25135:
    v_25382 = Lrplacd(nil, stack[-1], v_25382);
    env = stack[-9];
    v_25382 = stack[-2];
    v_25382 = qcdr(v_25382);
    stack[-2] = v_25382;
    goto v_25102;
v_25101:
    stack[0] = v_25382;
    goto v_25158;
v_25154:
    v_25383 = stack[0];
    goto v_25155;
v_25156:
    v_25382 = stack[-8];
    goto v_25157;
v_25158:
    goto v_25154;
v_25155:
    goto v_25156;
v_25157:
    fn = elt(env, 12); // subla!-q
    v_25382 = (*qfn2(fn))(fn, v_25383, v_25382);
    env = stack[-9];
    stack[-8] = v_25382;
    v_25382 = stack[0];
    stack[-3] = v_25382;
    v_25382 = stack[-3];
    if (v_25382 == nil) goto v_25170;
    else goto v_25171;
v_25170:
    v_25382 = nil;
    goto v_25165;
v_25171:
    v_25382 = stack[-3];
    v_25382 = qcar(v_25382);
    v_25382 = qcdr(v_25382);
    v_25382 = ncons(v_25382);
    env = stack[-9];
    stack[-1] = v_25382;
    stack[-2] = v_25382;
v_25166:
    v_25382 = stack[-3];
    v_25382 = qcdr(v_25382);
    stack[-3] = v_25382;
    v_25382 = stack[-3];
    if (v_25382 == nil) goto v_25184;
    else goto v_25185;
v_25184:
    v_25382 = stack[-2];
    goto v_25165;
v_25185:
    goto v_25193;
v_25189:
    stack[0] = stack[-1];
    goto v_25190;
v_25191:
    v_25382 = stack[-3];
    v_25382 = qcar(v_25382);
    v_25382 = qcdr(v_25382);
    v_25382 = ncons(v_25382);
    env = stack[-9];
    goto v_25192;
v_25193:
    goto v_25189;
v_25190:
    goto v_25191;
v_25192:
    v_25382 = Lrplacd(nil, stack[0], v_25382);
    env = stack[-9];
    v_25382 = stack[-1];
    v_25382 = qcdr(v_25382);
    stack[-1] = v_25382;
    goto v_25166;
v_25165:
    stack[-3] = v_25382;
    goto v_25056;
v_25087:
v_25056:
    v_25382 = stack[-7];
    stack[-1] = v_25382;
v_25206:
    v_25382 = stack[-1];
    if (v_25382 == nil) goto v_25210;
    else goto v_25211;
v_25210:
    goto v_25205;
v_25211:
    v_25382 = stack[-1];
    v_25382 = qcar(v_25382);
    stack[0] = v_25382;
    v_25382 = stack[0];
    fn = elt(env, 13); // no!-side!-effectp
    v_25382 = (*qfn1(fn))(fn, v_25382);
    env = stack[-9];
    if (v_25382 == nil) goto v_25221;
    else goto v_25219;
v_25221:
    goto v_25230;
v_25226:
    v_25382 = stack[-3];
    v_25383 = qcar(v_25382);
    goto v_25227;
v_25228:
    v_25382 = stack[-8];
    goto v_25229;
v_25230:
    goto v_25226;
v_25227:
    goto v_25228;
v_25229:
    fn = elt(env, 14); // one!-entryp
    v_25382 = (*qfn2(fn))(fn, v_25383, v_25382);
    env = stack[-9];
    if (v_25382 == nil) goto v_25224;
    else goto v_25219;
v_25224:
    goto v_25220;
v_25219:
    goto v_25239;
v_25235:
    goto v_25246;
v_25242:
    v_25382 = stack[-3];
    v_25383 = qcar(v_25382);
    goto v_25243;
v_25244:
    v_25382 = stack[0];
    goto v_25245;
v_25246:
    goto v_25242;
v_25243:
    goto v_25244;
v_25245:
    v_25382 = cons(v_25383, v_25382);
    env = stack[-9];
    v_25383 = ncons(v_25382);
    env = stack[-9];
    goto v_25236;
v_25237:
    v_25382 = stack[-8];
    goto v_25238;
v_25239:
    goto v_25235;
v_25236:
    goto v_25237;
v_25238:
    fn = elt(env, 12); // subla!-q
    v_25382 = (*qfn2(fn))(fn, v_25383, v_25382);
    env = stack[-9];
    stack[-8] = v_25382;
    goto v_25218;
v_25220:
    goto v_25258;
v_25254:
    stack[-2] = stack[-6];
    goto v_25255;
v_25256:
    goto v_25265;
v_25261:
    v_25382 = stack[-3];
    v_25383 = qcar(v_25382);
    goto v_25262;
v_25263:
    v_25382 = stack[0];
    goto v_25264;
v_25265:
    goto v_25261;
v_25262:
    goto v_25263;
v_25264:
    v_25382 = cons(v_25383, v_25382);
    env = stack[-9];
    goto v_25257;
v_25258:
    goto v_25254;
v_25255:
    goto v_25256;
v_25257:
    fn = elt(env, 15); // aconc
    v_25382 = (*qfn2(fn))(fn, stack[-2], v_25382);
    env = stack[-9];
    stack[-6] = v_25382;
    goto v_25218;
v_25218:
    v_25382 = stack[-3];
    v_25382 = qcdr(v_25382);
    stack[-3] = v_25382;
    v_25382 = stack[-1];
    v_25382 = qcdr(v_25382);
    stack[-1] = v_25382;
    goto v_25206;
v_25205:
    v_25382 = stack[-6];
    if (v_25382 == nil) goto v_25275;
    else goto v_25276;
v_25275:
    v_25382 = stack[-8];
    goto v_24989;
v_25276:
    goto v_25286;
v_25282:
    goto v_25294;
v_25288:
    stack[-4] = elt(env, 6); // lambda
    goto v_25289;
v_25290:
    v_25382 = stack[-6];
    stack[-3] = v_25382;
    v_25382 = stack[-3];
    if (v_25382 == nil) goto v_25305;
    else goto v_25306;
v_25305:
    v_25382 = nil;
    v_25383 = v_25382;
    goto v_25300;
v_25306:
    v_25382 = stack[-3];
    v_25382 = qcar(v_25382);
    v_25382 = qcar(v_25382);
    v_25382 = ncons(v_25382);
    env = stack[-9];
    stack[-1] = v_25382;
    stack[-2] = v_25382;
v_25301:
    v_25382 = stack[-3];
    v_25382 = qcdr(v_25382);
    stack[-3] = v_25382;
    v_25382 = stack[-3];
    if (v_25382 == nil) goto v_25319;
    else goto v_25320;
v_25319:
    v_25382 = stack[-2];
    v_25383 = v_25382;
    goto v_25300;
v_25320:
    goto v_25328;
v_25324:
    stack[0] = stack[-1];
    goto v_25325;
v_25326:
    v_25382 = stack[-3];
    v_25382 = qcar(v_25382);
    v_25382 = qcar(v_25382);
    v_25382 = ncons(v_25382);
    env = stack[-9];
    goto v_25327;
v_25328:
    goto v_25324;
v_25325:
    goto v_25326;
v_25327:
    v_25382 = Lrplacd(nil, stack[0], v_25382);
    env = stack[-9];
    v_25382 = stack[-1];
    v_25382 = qcdr(v_25382);
    stack[-1] = v_25382;
    goto v_25301;
v_25300:
    goto v_25291;
v_25292:
    v_25382 = stack[-8];
    goto v_25293;
v_25294:
    goto v_25288;
v_25289:
    goto v_25290;
v_25291:
    goto v_25292;
v_25293:
    stack[-3] = list3(stack[-4], v_25383, v_25382);
    env = stack[-9];
    goto v_25283;
v_25284:
    v_25382 = stack[-6];
    stack[-4] = v_25382;
    v_25382 = stack[-4];
    if (v_25382 == nil) goto v_25348;
    else goto v_25349;
v_25348:
    v_25382 = nil;
    goto v_25343;
v_25349:
    v_25382 = stack[-4];
    v_25382 = qcar(v_25382);
    v_25382 = qcdr(v_25382);
    v_25382 = ncons(v_25382);
    env = stack[-9];
    stack[-1] = v_25382;
    stack[-2] = v_25382;
v_25344:
    v_25382 = stack[-4];
    v_25382 = qcdr(v_25382);
    stack[-4] = v_25382;
    v_25382 = stack[-4];
    if (v_25382 == nil) goto v_25362;
    else goto v_25363;
v_25362:
    v_25382 = stack[-2];
    goto v_25343;
v_25363:
    goto v_25371;
v_25367:
    stack[0] = stack[-1];
    goto v_25368;
v_25369:
    v_25382 = stack[-4];
    v_25382 = qcar(v_25382);
    v_25382 = qcdr(v_25382);
    v_25382 = ncons(v_25382);
    env = stack[-9];
    goto v_25370;
v_25371:
    goto v_25367;
v_25368:
    goto v_25369;
v_25370:
    v_25382 = Lrplacd(nil, stack[0], v_25382);
    env = stack[-9];
    v_25382 = stack[-1];
    v_25382 = qcdr(v_25382);
    stack[-1] = v_25382;
    goto v_25344;
v_25343:
    goto v_25285;
v_25286:
    goto v_25282;
v_25283:
    goto v_25284;
v_25285:
    v_25382 = cons(stack[-3], v_25382);
    stack[0] = v_25382;
    v_25382 = stack[0];
    goto v_24989;
    v_25382 = nil;
v_24989:
    ;}  // end of a binding scope
    return onevalue(v_25382);
}



// Code for prepsq!*0

static LispObject CC_prepsqH0(LispObject env,
                         LispObject v_24979, LispObject v_24980)
{
    env = qenv(env);
    LispObject v_25052, v_25053, v_25054;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24980,v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24979,v_24980);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_24980;
    stack[-2] = v_24979;
// end of prologue
    v_25052 = stack[-2];
    v_25052 = qcar(v_25052);
    if (v_25052 == nil) goto v_24987;
    else goto v_24988;
v_24987:
    v_25052 = nil;
    goto v_24986;
v_24988:
    goto v_24998;
v_24994:
    goto v_25004;
v_25000:
    v_25052 = stack[-2];
    v_25053 = qcar(v_25052);
    goto v_25001;
v_25002:
    v_25052 = stack[-2];
    v_25052 = qcdr(v_25052);
    goto v_25003;
v_25004:
    goto v_25000;
v_25001:
    goto v_25002;
v_25003:
    fn = elt(env, 1); // gcdf
    v_25053 = (*qfn2(fn))(fn, v_25053, v_25052);
    env = stack[-4];
    stack[-3] = v_25053;
    goto v_24995;
v_24996:
    v_25052 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24997;
v_24998:
    goto v_24994;
v_24995:
    goto v_24996;
v_24997:
    if (v_25053 == v_25052) goto v_24993;
    goto v_25017;
v_25011:
    goto v_25023;
v_25019:
    v_25052 = stack[-2];
    v_25053 = qcar(v_25052);
    goto v_25020;
v_25021:
    v_25052 = stack[-3];
    goto v_25022;
v_25023:
    goto v_25019;
v_25020:
    goto v_25021;
v_25022:
    fn = elt(env, 2); // quotf!-fail
    stack[0] = (*qfn2(fn))(fn, v_25053, v_25052);
    env = stack[-4];
    goto v_25012;
v_25013:
    goto v_25032;
v_25028:
    v_25052 = stack[-2];
    v_25053 = qcdr(v_25052);
    goto v_25029;
v_25030:
    v_25052 = stack[-3];
    goto v_25031;
v_25032:
    goto v_25028;
v_25029:
    goto v_25030;
v_25031:
    fn = elt(env, 2); // quotf!-fail
    v_25053 = (*qfn2(fn))(fn, v_25053, v_25052);
    env = stack[-4];
    goto v_25014;
v_25015:
    v_25052 = stack[-1];
    goto v_25016;
v_25017:
    goto v_25011;
v_25012:
    goto v_25013;
v_25014:
    goto v_25015;
v_25016:
    {
        LispObject v_25059 = stack[0];
        fn = elt(env, 3); // prepsq!*1
        return (*qfnn(fn))(fn, 3, v_25059, v_25053, v_25052);
    }
v_24993:
    goto v_25046;
v_25040:
    v_25052 = stack[-2];
    v_25054 = qcar(v_25052);
    goto v_25041;
v_25042:
    v_25052 = stack[-2];
    v_25053 = qcdr(v_25052);
    goto v_25043;
v_25044:
    v_25052 = stack[-1];
    goto v_25045;
v_25046:
    goto v_25040;
v_25041:
    goto v_25042;
v_25043:
    goto v_25044;
v_25045:
    {
        fn = elt(env, 3); // prepsq!*1
        return (*qfnn(fn))(fn, 3, v_25054, v_25053, v_25052);
    }
    v_25052 = nil;
v_24986:
    return onevalue(v_25052);
}



// Code for change!+int!+to!+sq

static LispObject CC_changeLintLtoLsq(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_24991, v_24992;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24991 = v_24979;
// end of prologue
    goto v_24988;
v_24984:
    v_24992 = v_24991;
    goto v_24985;
v_24986:
    v_24991 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24987;
v_24988:
    goto v_24984;
v_24985:
    goto v_24986;
v_24987:
    return cons(v_24992, v_24991);
    return onevalue(v_24991);
}



// Code for pasf_coeflst

static LispObject CC_pasf_coeflst(LispObject env,
                         LispObject v_24979, LispObject v_24980)
{
    env = qenv(env);
    LispObject v_25062, v_25063, v_25064;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24980,v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24979,v_24980);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_24980;
    stack[-2] = v_24979;
// end of prologue
    stack[0] = nil;
    v_25062 = stack[-1];
    v_25062 = ncons(v_25062);
    env = stack[-4];
    fn = elt(env, 1); // setkorder
    v_25062 = (*qfn1(fn))(fn, v_25062);
    env = stack[-4];
    stack[-3] = v_25062;
    v_25062 = stack[-2];
    fn = elt(env, 2); // reorder
    v_25062 = (*qfn1(fn))(fn, v_25062);
    env = stack[-4];
    stack[-2] = v_25062;
v_24994:
    v_25062 = stack[-2];
    if (!consp(v_25062)) goto v_25005;
    else goto v_25006;
v_25005:
    v_25062 = lisp_true;
    goto v_25004;
v_25006:
    v_25062 = stack[-2];
    v_25062 = qcar(v_25062);
    v_25062 = (consp(v_25062) ? nil : lisp_true);
    goto v_25004;
    v_25062 = nil;
v_25004:
    if (v_25062 == nil) goto v_25001;
    else goto v_25002;
v_25001:
    goto v_25018;
v_25014:
    v_25062 = stack[-2];
    v_25062 = qcar(v_25062);
    v_25062 = qcar(v_25062);
    v_25063 = qcar(v_25062);
    goto v_25015;
v_25016:
    v_25062 = stack[-1];
    goto v_25017;
v_25018:
    goto v_25014;
v_25015:
    goto v_25016;
v_25017:
    v_25062 = (v_25063 == v_25062 ? lisp_true : nil);
    goto v_25000;
v_25002:
    v_25062 = nil;
    goto v_25000;
    v_25062 = nil;
v_25000:
    if (v_25062 == nil) goto v_24997;
    else goto v_24998;
v_24997:
    goto v_24993;
v_24998:
    goto v_25036;
v_25030:
    v_25062 = stack[-2];
    v_25062 = qcar(v_25062);
    v_25064 = qcdr(v_25062);
    goto v_25031;
v_25032:
    v_25062 = stack[-2];
    v_25062 = qcar(v_25062);
    v_25062 = qcar(v_25062);
    v_25063 = qcdr(v_25062);
    goto v_25033;
v_25034:
    v_25062 = stack[0];
    goto v_25035;
v_25036:
    goto v_25030;
v_25031:
    goto v_25032;
v_25033:
    goto v_25034;
v_25035:
    v_25062 = acons(v_25064, v_25063, v_25062);
    env = stack[-4];
    stack[0] = v_25062;
    v_25062 = stack[-2];
    v_25062 = qcdr(v_25062);
    stack[-2] = v_25062;
    goto v_24994;
v_24993:
    v_25062 = stack[-3];
    fn = elt(env, 1); // setkorder
    v_25062 = (*qfn1(fn))(fn, v_25062);
    env = stack[-4];
    goto v_25057;
v_25051:
    v_25062 = stack[-2];
    fn = elt(env, 3); // negf
    v_25064 = (*qfn1(fn))(fn, v_25062);
    env = stack[-4];
    goto v_25052;
v_25053:
    v_25063 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25054;
v_25055:
    v_25062 = stack[0];
    goto v_25056;
v_25057:
    goto v_25051;
v_25052:
    goto v_25053;
v_25054:
    goto v_25055;
v_25056:
    v_25062 = acons(v_25064, v_25063, v_25062);
        return Lnreverse(nil, v_25062);
    return onevalue(v_25062);
}



// Code for lto_sgnchg1

static LispObject CC_lto_sgnchg1(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_25022;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24979);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24979;
// end of prologue
v_24983:
    v_25022 = stack[0];
    if (v_25022 == nil) goto v_24990;
    else goto v_24991;
v_24990:
    v_25022 = lisp_true;
    goto v_24989;
v_24991:
    v_25022 = stack[0];
    v_25022 = qcdr(v_25022);
    v_25022 = (v_25022 == nil ? lisp_true : nil);
    goto v_24989;
    v_25022 = nil;
v_24989:
    if (v_25022 == nil) goto v_24987;
    v_25022 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24982;
v_24987:
    goto v_25006;
v_25002:
    v_25022 = stack[0];
    v_25022 = qcar(v_25022);
    fn = elt(env, 1); // sgn
    stack[-1] = (*qfn1(fn))(fn, v_25022);
    env = stack[-2];
    goto v_25003;
v_25004:
    v_25022 = stack[0];
    v_25022 = qcdr(v_25022);
    v_25022 = qcar(v_25022);
    fn = elt(env, 1); // sgn
    v_25022 = (*qfn1(fn))(fn, v_25022);
    env = stack[-2];
    goto v_25005;
v_25006:
    goto v_25002;
v_25003:
    goto v_25004;
v_25005:
    if (stack[-1] == v_25022) goto v_25000;
    else goto v_25001;
v_25000:
    v_25022 = stack[0];
    v_25022 = qcdr(v_25022);
    stack[0] = v_25022;
    goto v_24983;
v_25001:
    v_25022 = stack[0];
    v_25022 = qcdr(v_25022);
    v_25022 = CC_lto_sgnchg1(elt(env, 0), v_25022);
    return add1(v_25022);
    v_25022 = nil;
v_24982:
    return onevalue(v_25022);
}



// Code for numir

static LispObject CC_numir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25192, v_25193, v_25194;
    LispObject fn;
    argcheck(nargs, 0, "numir");
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
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// end of prologue
    goto v_24992;
v_24988:
    v_25193 = qvalue(elt(env, 1)); // atts
    goto v_24989;
v_24990:
    v_25192 = elt(env, 2); // name
    goto v_24991;
v_24992:
    goto v_24988;
v_24989:
    goto v_24990;
v_24991:
    fn = elt(env, 11); // find
    v_25192 = (*qfn2(fn))(fn, v_25193, v_25192);
    env = stack[-7];
    v_25192 = Lintern(nil, v_25192);
    env = stack[-7];
    stack[-1] = v_25192;
    fn = elt(env, 12); // lex
    v_25192 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    fn = elt(env, 13); // omobj
    v_25192 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    stack[0] = v_25192;
    fn = elt(env, 12); // lex
    v_25192 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    fn = elt(env, 13); // omobj
    v_25192 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    goto v_25007;
v_25003:
    v_25194 = stack[-1];
    goto v_25004;
v_25005:
    v_25193 = elt(env, 3); // complex_cartesian
    goto v_25006;
v_25007:
    goto v_25003;
v_25004:
    goto v_25005;
v_25006:
    if (v_25194 == v_25193) goto v_25001;
    else goto v_25002;
v_25001:
    v_25193 = stack[0];
    if (symbolp(v_25193)) goto v_25012;
    v_25193 = v_25192;
    if (symbolp(v_25193)) goto v_25012;
    goto v_25013;
v_25012:
    goto v_25025;
v_25019:
    stack[-4] = elt(env, 4); // plus
    goto v_25020;
v_25021:
    stack[-3] = nil;
    goto v_25022;
v_25023:
    goto v_25035;
v_25029:
    stack[-2] = stack[0];
    goto v_25030;
v_25031:
    goto v_25044;
v_25038:
    stack[-1] = elt(env, 5); // times
    goto v_25039;
v_25040:
    stack[0] = nil;
    goto v_25041;
v_25042:
    goto v_25054;
v_25048:
    v_25194 = v_25192;
    goto v_25049;
v_25050:
    v_25193 = elt(env, 6); // !&imaginaryi!;
    goto v_25051;
v_25052:
    v_25192 = nil;
    goto v_25053;
v_25054:
    goto v_25048;
v_25049:
    goto v_25050;
v_25051:
    goto v_25052;
v_25053:
    v_25192 = list2star(v_25194, v_25193, v_25192);
    env = stack[-7];
    goto v_25043;
v_25044:
    goto v_25038;
v_25039:
    goto v_25040;
v_25041:
    goto v_25042;
v_25043:
    v_25193 = list2star(stack[-1], stack[0], v_25192);
    env = stack[-7];
    goto v_25032;
v_25033:
    v_25192 = nil;
    goto v_25034;
v_25035:
    goto v_25029;
v_25030:
    goto v_25031;
v_25032:
    goto v_25033;
v_25034:
    v_25192 = list2star(stack[-2], v_25193, v_25192);
    goto v_25024;
v_25025:
    goto v_25019;
v_25020:
    goto v_25021;
v_25022:
    goto v_25023;
v_25024:
    {
        LispObject v_25202 = stack[-4];
        LispObject v_25203 = stack[-3];
        return list2star(v_25202, v_25203, v_25192);
    }
v_25013:
    goto v_25000;
v_25002:
v_25000:
    goto v_25067;
v_25063:
    v_25194 = stack[-1];
    goto v_25064;
v_25065:
    v_25193 = elt(env, 7); // complex_polar
    goto v_25066;
v_25067:
    goto v_25063;
v_25064:
    goto v_25065;
v_25066:
    if (v_25194 == v_25193) goto v_25061;
    else goto v_25062;
v_25061:
    v_25193 = stack[0];
    if (symbolp(v_25193)) goto v_25072;
    v_25193 = v_25192;
    if (symbolp(v_25193)) goto v_25072;
    goto v_25073;
v_25072:
    goto v_25085;
v_25079:
    stack[-6] = elt(env, 5); // times
    goto v_25080;
v_25081:
    stack[-5] = nil;
    goto v_25082;
v_25083:
    goto v_25095;
v_25089:
    stack[-4] = stack[0];
    goto v_25090;
v_25091:
    goto v_25104;
v_25098:
    stack[-3] = elt(env, 8); // exp
    goto v_25099;
v_25100:
    stack[-2] = nil;
    goto v_25101;
v_25102:
    goto v_25115;
v_25109:
    stack[-1] = elt(env, 5); // times
    goto v_25110;
v_25111:
    stack[0] = nil;
    goto v_25112;
v_25113:
    goto v_25125;
v_25119:
    v_25194 = v_25192;
    goto v_25120;
v_25121:
    v_25193 = elt(env, 6); // !&imaginaryi!;
    goto v_25122;
v_25123:
    v_25192 = nil;
    goto v_25124;
v_25125:
    goto v_25119;
v_25120:
    goto v_25121;
v_25122:
    goto v_25123;
v_25124:
    v_25192 = list2star(v_25194, v_25193, v_25192);
    env = stack[-7];
    goto v_25114;
v_25115:
    goto v_25109;
v_25110:
    goto v_25111;
v_25112:
    goto v_25113;
v_25114:
    v_25192 = list2star(stack[-1], stack[0], v_25192);
    env = stack[-7];
    v_25192 = ncons(v_25192);
    env = stack[-7];
    goto v_25103;
v_25104:
    goto v_25098;
v_25099:
    goto v_25100;
v_25101:
    goto v_25102;
v_25103:
    v_25193 = list2star(stack[-3], stack[-2], v_25192);
    env = stack[-7];
    goto v_25092;
v_25093:
    v_25192 = nil;
    goto v_25094;
v_25095:
    goto v_25089;
v_25090:
    goto v_25091;
v_25092:
    goto v_25093;
v_25094:
    v_25192 = list2star(stack[-4], v_25193, v_25192);
    goto v_25084;
v_25085:
    goto v_25079;
v_25080:
    goto v_25081;
v_25082:
    goto v_25083;
v_25084:
    {
        LispObject v_25204 = stack[-6];
        LispObject v_25205 = stack[-5];
        return list2star(v_25204, v_25205, v_25192);
    }
v_25073:
    goto v_25060;
v_25062:
v_25060:
    goto v_25138;
v_25134:
    v_25194 = stack[-1];
    goto v_25135;
v_25136:
    v_25193 = elt(env, 9); // rational
    goto v_25137;
v_25138:
    goto v_25134;
v_25135:
    goto v_25136;
v_25137:
    if (v_25194 == v_25193) goto v_25132;
    else goto v_25133;
v_25132:
    v_25193 = stack[0];
    if (symbolp(v_25193)) goto v_25143;
    v_25193 = v_25192;
    if (symbolp(v_25193)) goto v_25143;
    goto v_25144;
v_25143:
    goto v_25156;
v_25150:
    stack[-2] = elt(env, 10); // divide
    goto v_25151;
v_25152:
    stack[-1] = nil;
    goto v_25153;
v_25154:
    goto v_25166;
v_25160:
    v_25194 = stack[0];
    goto v_25161;
v_25162:
    v_25193 = v_25192;
    goto v_25163;
v_25164:
    v_25192 = nil;
    goto v_25165;
v_25166:
    goto v_25160;
v_25161:
    goto v_25162;
v_25163:
    goto v_25164;
v_25165:
    v_25192 = list2star(v_25194, v_25193, v_25192);
    goto v_25155;
v_25156:
    goto v_25150;
v_25151:
    goto v_25152;
v_25153:
    goto v_25154;
v_25155:
    {
        LispObject v_25206 = stack[-2];
        LispObject v_25207 = stack[-1];
        return list2star(v_25206, v_25207, v_25192);
    }
v_25144:
    goto v_25131;
v_25133:
v_25131:
    goto v_25178;
v_25172:
    stack[-2] = stack[-1];
    goto v_25173;
v_25174:
    stack[-1] = nil;
    goto v_25175;
v_25176:
    goto v_25188;
v_25182:
    v_25194 = stack[0];
    goto v_25183;
v_25184:
    v_25193 = v_25192;
    goto v_25185;
v_25186:
    v_25192 = nil;
    goto v_25187;
v_25188:
    goto v_25182;
v_25183:
    goto v_25184;
v_25185:
    goto v_25186;
v_25187:
    v_25192 = list2star(v_25194, v_25193, v_25192);
    goto v_25177;
v_25178:
    goto v_25172;
v_25173:
    goto v_25174;
v_25175:
    goto v_25176;
v_25177:
    {
        LispObject v_25208 = stack[-2];
        LispObject v_25209 = stack[-1];
        return list2star(v_25208, v_25209, v_25192);
    }
    return onevalue(v_25192);
}



// Code for mkexpt

static LispObject CC_mkexpt(LispObject env,
                         LispObject v_24979, LispObject v_24980)
{
    env = qenv(env);
    LispObject v_25007, v_25008, v_25009, v_25010;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_25009 = v_24980;
    v_25010 = v_24979;
// end of prologue
    goto v_24990;
v_24986:
    v_25008 = v_25009;
    goto v_24987;
v_24988:
    v_25007 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24989;
v_24990:
    goto v_24986;
v_24987:
    goto v_24988;
v_24989:
    if (v_25008 == v_25007) goto v_24984;
    else goto v_24985;
v_24984:
    v_25007 = v_25010;
    goto v_24983;
v_24985:
    goto v_25003;
v_24997:
    v_25007 = elt(env, 1); // expt
    goto v_24998;
v_24999:
    v_25008 = v_25010;
    goto v_25000;
v_25001:
    goto v_25002;
v_25003:
    goto v_24997;
v_24998:
    goto v_24999;
v_25000:
    goto v_25001;
v_25002:
    return list3(v_25007, v_25008, v_25009);
    v_25007 = nil;
v_24983:
    return onevalue(v_25007);
}



// Code for evalmember

static LispObject CC_evalmember(LispObject env,
                         LispObject v_24979, LispObject v_24980)
{
    env = qenv(env);
    LispObject v_24991, v_24992;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24980,v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24979,v_24980);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_24991 = v_24980;
    v_24992 = v_24979;
// end of prologue
    goto v_24986;
v_24982:
    stack[0] = v_24992;
    goto v_24983;
v_24984:
    fn = elt(env, 1); // getrlist
    v_24991 = (*qfn1(fn))(fn, v_24991);
    goto v_24985;
v_24986:
    goto v_24982;
v_24983:
    goto v_24984;
v_24985:
    v_24991 = Lmember(nil, stack[0], v_24991);
    return onevalue(v_24991);
}



// Code for e!*

static LispObject CC_eH(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24982;
    LispObject fn;
    argcheck(nargs, 0, "e*");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_24982 = qvalue(elt(env, 1)); // !:bprec!:
    {
        fn = elt(env, 2); // !:e
        return (*qfn1(fn))(fn, v_24982);
    }
}



// Code for gpargp

static LispObject CC_gpargp(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_24993;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24979);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24979;
// end of prologue
    v_24993 = stack[0];
    v_24993 = Lstringp(nil, v_24993);
    env = stack[-1];
    if (v_24993 == nil) goto v_24983;
    else goto v_24982;
v_24983:
    v_24993 = stack[0];
    fn = elt(env, 1); // gpexpp
    v_24993 = (*qfn1(fn))(fn, v_24993);
    env = stack[-1];
    if (v_24993 == nil) goto v_24988;
    else goto v_24987;
v_24988:
    v_24993 = stack[0];
    {
        fn = elt(env, 2); // gplogexpp
        return (*qfn1(fn))(fn, v_24993);
    }
v_24987:
v_24982:
    return onevalue(v_24993);
}



// Code for indexvp

static LispObject CC_indexvp(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_24992, v_24993;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24992 = v_24979;
// end of prologue
    v_24993 = v_24992;
    if (!consp(v_24993)) goto v_24984;
    v_24992 = qcar(v_24992);
    if (!symbolp(v_24992)) v_24992 = nil;
    else { v_24992 = qfastgets(v_24992);
           if (v_24992 != nil) { v_24992 = elt(v_24992, 16); // indexvar
#ifdef RECORD_GET
             if (v_24992 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v_24992 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v_24992 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v_24992 == SPID_NOPROP) v_24992 = nil; else v_24992 = lisp_true; }}
#endif
    goto v_24982;
v_24984:
    v_24992 = nil;
    goto v_24982;
    v_24992 = nil;
v_24982:
    return onevalue(v_24992);
}



// Code for extract_vars

static LispObject CC_extract_vars(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_25019, v_25020;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24979);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24979;
// end of prologue
    stack[-1] = nil;
v_24984:
    v_25019 = stack[0];
    if (v_25019 == nil) goto v_24987;
    else goto v_24988;
v_24987:
    v_25019 = stack[-1];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_25019);
    }
v_24988:
    goto v_24999;
v_24995:
    v_25019 = stack[0];
    v_25019 = qcar(v_25019);
    fn = elt(env, 3); // raiseind!:
    v_25020 = (*qfn1(fn))(fn, v_25019);
    env = stack[-2];
    goto v_24996;
v_24997:
    v_25019 = elt(env, 1); // variable
    goto v_24998;
v_24999:
    goto v_24995;
v_24996:
    goto v_24997;
v_24998:
    v_25019 = Lflagp(nil, v_25020, v_25019);
    env = stack[-2];
    if (v_25019 == nil) goto v_24993;
    goto v_25009;
v_25005:
    v_25019 = stack[0];
    v_25020 = qcar(v_25019);
    goto v_25006;
v_25007:
    v_25019 = stack[-1];
    goto v_25008;
v_25009:
    goto v_25005;
v_25006:
    goto v_25007;
v_25008:
    v_25019 = cons(v_25020, v_25019);
    env = stack[-2];
    stack[-1] = v_25019;
    v_25019 = stack[0];
    v_25019 = qcdr(v_25019);
    stack[0] = v_25019;
    goto v_24984;
v_24993:
    v_25019 = stack[0];
    v_25019 = qcdr(v_25019);
    stack[0] = v_25019;
    goto v_24984;
    v_25019 = nil;
    return onevalue(v_25019);
}



// Code for ev_mtest!?

static LispObject CC_ev_mtestW(LispObject env,
                         LispObject v_24979, LispObject v_24980)
{
    env = qenv(env);
    LispObject v_25019, v_25020, v_25021, v_25022, v_25023;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_25021 = v_24980;
    v_25022 = v_24979;
// end of prologue
    v_25019 = lisp_true;
    v_25023 = v_25019;
v_24988:
    v_25019 = v_25022;
    if (v_25019 == nil) goto v_24991;
    v_25019 = v_25023;
    if (v_25019 == nil) goto v_24991;
    goto v_24992;
v_24991:
    goto v_24987;
v_24992:
    goto v_25006;
v_25002:
    v_25019 = v_25022;
    v_25020 = qcar(v_25019);
    goto v_25003;
v_25004:
    v_25019 = v_25021;
    v_25019 = qcar(v_25019);
    goto v_25005;
v_25006:
    goto v_25002;
v_25003:
    goto v_25004;
v_25005:
    if (((intptr_t)(v_25020)) < ((intptr_t)(v_25019))) goto v_25000;
    else goto v_25001;
v_25000:
    v_25019 = nil;
    v_25023 = v_25019;
    v_25022 = v_25019;
    goto v_24999;
v_25001:
    v_25019 = v_25022;
    v_25019 = qcdr(v_25019);
    v_25022 = v_25019;
    v_25019 = v_25021;
    v_25019 = qcdr(v_25019);
    v_25021 = v_25019;
    goto v_24999;
v_24999:
    goto v_24988;
v_24987:
    v_25019 = v_25023;
    return onevalue(v_25019);
}



// Code for cgp_greenp

static LispObject CC_cgp_greenp(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_24984;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24979);
    }
// copy arguments values to proper place
    v_24984 = v_24979;
// end of prologue
    fn = elt(env, 1); // cgp_rp
    v_24984 = (*qfn1(fn))(fn, v_24984);
    v_24984 = (v_24984 == nil ? lisp_true : nil);
    return onevalue(v_24984);
}



// Code for matrixml

static LispObject CC_matrixml(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_25026, v_25027;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24979);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24979;
// end of prologue
    v_25026 = elt(env, 1); // "<matrix"
    fn = elt(env, 5); // printout
    v_25026 = (*qfn1(fn))(fn, v_25026);
    env = stack[-1];
    goto v_24990;
v_24986:
    v_25026 = stack[0];
    v_25027 = qcar(v_25026);
    goto v_24987;
v_24988:
    v_25026 = elt(env, 2); // ""
    goto v_24989;
v_24990:
    goto v_24986;
v_24987:
    goto v_24988;
v_24989:
    fn = elt(env, 6); // attributesml
    v_25026 = (*qfn2(fn))(fn, v_25027, v_25026);
    env = stack[-1];
    v_25026 = lisp_true;
    fn = elt(env, 7); // indent!*
    v_25026 = (*qfn1(fn))(fn, v_25026);
    env = stack[-1];
    goto v_25004;
v_25000:
    v_25026 = stack[0];
    v_25026 = qcdr(v_25026);
    v_25027 = qcar(v_25026);
    goto v_25001;
v_25002:
    v_25026 = elt(env, 3); // matrixrow
    goto v_25003;
v_25004:
    goto v_25000;
v_25001:
    goto v_25002;
v_25003:
    if (v_25027 == v_25026) goto v_24998;
    else goto v_24999;
v_24998:
    v_25026 = stack[0];
    v_25026 = qcdr(v_25026);
    v_25026 = qcdr(v_25026);
    v_25026 = qcar(v_25026);
    fn = elt(env, 8); // matrix_rows
    v_25026 = (*qfn1(fn))(fn, v_25026);
    env = stack[-1];
    goto v_24997;
v_24999:
    v_25026 = stack[0];
    v_25026 = qcdr(v_25026);
    v_25026 = qcdr(v_25026);
    v_25026 = qcar(v_25026);
    fn = elt(env, 9); // cols2rows
    v_25026 = (*qfn1(fn))(fn, v_25026);
    env = stack[-1];
    fn = elt(env, 8); // matrix_rows
    v_25026 = (*qfn1(fn))(fn, v_25026);
    env = stack[-1];
    goto v_24997;
v_24997:
    v_25026 = nil;
    fn = elt(env, 7); // indent!*
    v_25026 = (*qfn1(fn))(fn, v_25026);
    env = stack[-1];
    v_25026 = elt(env, 4); // "</matrix>"
    fn = elt(env, 5); // printout
    v_25026 = (*qfn1(fn))(fn, v_25026);
    v_25026 = nil;
    return onevalue(v_25026);
}



// Code for ps!:arg!-values

static LispObject CC_psTargKvalues(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_25130, v_25131, v_25132;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24979);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_25131 = v_24979;
// end of prologue
    goto v_24986;
v_24982:
    v_25130 = v_25131;
    stack[-4] = qcar(v_25130);
    goto v_24983;
v_24984:
    v_25130 = v_25131;
    v_25130 = qcdr(v_25130);
    stack[-3] = v_25130;
    v_25130 = stack[-3];
    if (v_25130 == nil) goto v_24999;
    else goto v_25000;
v_24999:
    v_25130 = nil;
    goto v_24993;
v_25000:
    v_25130 = stack[-3];
    v_25130 = qcar(v_25130);
    v_25132 = v_25130;
    v_25130 = v_25132;
    if (!consp(v_25130)) goto v_25013;
    else goto v_25014;
v_25013:
    v_25130 = lisp_true;
    goto v_25012;
v_25014:
    goto v_25027;
v_25023:
    v_25130 = v_25132;
    v_25131 = qcar(v_25130);
    goto v_25024;
v_25025:
    v_25130 = elt(env, 1); // !:ps!:
    goto v_25026;
v_25027:
    goto v_25023;
v_25024:
    goto v_25025;
v_25026:
    if (v_25131 == v_25130) goto v_25022;
    v_25130 = v_25132;
    v_25130 = qcar(v_25130);
    if (!symbolp(v_25130)) v_25130 = nil;
    else { v_25130 = qfastgets(v_25130);
           if (v_25130 != nil) { v_25130 = elt(v_25130, 8); // dname
#ifdef RECORD_GET
             if (v_25130 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_25130 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_25130 == SPID_NOPROP) v_25130 = nil; }}
#endif
    goto v_25020;
v_25022:
    v_25130 = nil;
    goto v_25020;
    v_25130 = nil;
v_25020:
    goto v_25012;
    v_25130 = nil;
v_25012:
    if (v_25130 == nil) goto v_25010;
    v_25130 = v_25132;
    goto v_25008;
v_25010:
    v_25130 = v_25132;
    v_25130 = Lconsp(nil, v_25130);
    env = stack[-5];
    if (v_25130 == nil) goto v_25039;
    goto v_25048;
v_25044:
    v_25130 = v_25132;
    v_25131 = qcar(v_25130);
    goto v_25045;
v_25046:
    v_25130 = elt(env, 1); // !:ps!:
    goto v_25047;
v_25048:
    goto v_25044;
v_25045:
    goto v_25046;
v_25047:
    if (v_25131 == v_25130) goto v_25043;
    else goto v_25039;
v_25043:
    v_25130 = v_25132;
    fn = elt(env, 2); // ps!:value
    v_25130 = (*qfn1(fn))(fn, v_25130);
    env = stack[-5];
    goto v_25008;
v_25039:
    v_25130 = v_25132;
    v_25130 = CC_psTargKvalues(elt(env, 0), v_25130);
    env = stack[-5];
    goto v_25008;
    v_25130 = nil;
v_25008:
    v_25130 = ncons(v_25130);
    env = stack[-5];
    stack[-1] = v_25130;
    stack[-2] = v_25130;
v_24994:
    v_25130 = stack[-3];
    v_25130 = qcdr(v_25130);
    stack[-3] = v_25130;
    v_25130 = stack[-3];
    if (v_25130 == nil) goto v_25062;
    else goto v_25063;
v_25062:
    v_25130 = stack[-2];
    goto v_24993;
v_25063:
    goto v_25071;
v_25067:
    stack[0] = stack[-1];
    goto v_25068;
v_25069:
    v_25130 = stack[-3];
    v_25130 = qcar(v_25130);
    v_25132 = v_25130;
    v_25130 = v_25132;
    if (!consp(v_25130)) goto v_25083;
    else goto v_25084;
v_25083:
    v_25130 = lisp_true;
    goto v_25082;
v_25084:
    goto v_25097;
v_25093:
    v_25130 = v_25132;
    v_25131 = qcar(v_25130);
    goto v_25094;
v_25095:
    v_25130 = elt(env, 1); // !:ps!:
    goto v_25096;
v_25097:
    goto v_25093;
v_25094:
    goto v_25095;
v_25096:
    if (v_25131 == v_25130) goto v_25092;
    v_25130 = v_25132;
    v_25130 = qcar(v_25130);
    if (!symbolp(v_25130)) v_25130 = nil;
    else { v_25130 = qfastgets(v_25130);
           if (v_25130 != nil) { v_25130 = elt(v_25130, 8); // dname
#ifdef RECORD_GET
             if (v_25130 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_25130 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_25130 == SPID_NOPROP) v_25130 = nil; }}
#endif
    goto v_25090;
v_25092:
    v_25130 = nil;
    goto v_25090;
    v_25130 = nil;
v_25090:
    goto v_25082;
    v_25130 = nil;
v_25082:
    if (v_25130 == nil) goto v_25080;
    v_25130 = v_25132;
    goto v_25078;
v_25080:
    v_25130 = v_25132;
    v_25130 = Lconsp(nil, v_25130);
    env = stack[-5];
    if (v_25130 == nil) goto v_25109;
    goto v_25118;
v_25114:
    v_25130 = v_25132;
    v_25131 = qcar(v_25130);
    goto v_25115;
v_25116:
    v_25130 = elt(env, 1); // !:ps!:
    goto v_25117;
v_25118:
    goto v_25114;
v_25115:
    goto v_25116;
v_25117:
    if (v_25131 == v_25130) goto v_25113;
    else goto v_25109;
v_25113:
    v_25130 = v_25132;
    fn = elt(env, 2); // ps!:value
    v_25130 = (*qfn1(fn))(fn, v_25130);
    env = stack[-5];
    goto v_25078;
v_25109:
    v_25130 = v_25132;
    v_25130 = CC_psTargKvalues(elt(env, 0), v_25130);
    env = stack[-5];
    goto v_25078;
    v_25130 = nil;
v_25078:
    v_25130 = ncons(v_25130);
    env = stack[-5];
    goto v_25070;
v_25071:
    goto v_25067;
v_25068:
    goto v_25069;
v_25070:
    v_25130 = Lrplacd(nil, stack[0], v_25130);
    env = stack[-5];
    v_25130 = stack[-1];
    v_25130 = qcdr(v_25130);
    stack[-1] = v_25130;
    goto v_24994;
v_24993:
    goto v_24985;
v_24986:
    goto v_24982;
v_24983:
    goto v_24984;
v_24985:
    {
        LispObject v_25138 = stack[-4];
        return cons(v_25138, v_25130);
    }
}



// Code for diford

static LispObject CC_diford(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_24985;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24985 = v_24979;
// end of prologue
    v_24985 = qcdr(v_24985);
    v_24985 = qcdr(v_24985);
    {
        fn = elt(env, 1); // lengthn
        return (*qfn1(fn))(fn, v_24985);
    }
}



// Code for specrd!:times

static LispObject CC_specrdTtimes(LispObject env,
                         LispObject v_24979, LispObject v_24980)
{
    env = qenv(env);
    LispObject v_25068, v_25069;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24980,v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24979,v_24980);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_24980;
    stack[-1] = v_24979;
// end of prologue
    stack[-2] = nil;
    v_25068 = stack[-1];
    fn = elt(env, 2); // add_minus
    v_25068 = (*qfn1(fn))(fn, v_25068);
    env = stack[-3];
    stack[-1] = v_25068;
    v_25068 = stack[0];
    fn = elt(env, 2); // add_minus
    v_25068 = (*qfn1(fn))(fn, v_25068);
    env = stack[-3];
    stack[0] = v_25068;
    goto v_24998;
v_24994:
    v_25069 = stack[-1];
    goto v_24995;
v_24996:
    v_25068 = elt(env, 1); // minus
    goto v_24997;
v_24998:
    goto v_24994;
v_24995:
    goto v_24996;
v_24997:
    if (!consp(v_25069)) goto v_24992;
    v_25069 = qcar(v_25069);
    if (v_25069 == v_25068) goto v_24991;
    else goto v_24992;
v_24991:
    v_25068 = stack[-1];
    v_25068 = qcdr(v_25068);
    v_25068 = qcar(v_25068);
    stack[-1] = v_25068;
    v_25068 = lisp_true;
    stack[-2] = v_25068;
    goto v_24990;
v_24992:
v_24990:
    goto v_25014;
v_25010:
    v_25069 = stack[0];
    goto v_25011;
v_25012:
    v_25068 = elt(env, 1); // minus
    goto v_25013;
v_25014:
    goto v_25010;
v_25011:
    goto v_25012;
v_25013:
    if (!consp(v_25069)) goto v_25008;
    v_25069 = qcar(v_25069);
    if (v_25069 == v_25068) goto v_25007;
    else goto v_25008;
v_25007:
    v_25068 = stack[0];
    v_25068 = qcdr(v_25068);
    v_25068 = qcar(v_25068);
    stack[0] = v_25068;
    v_25068 = stack[-2];
    v_25068 = (v_25068 == nil ? lisp_true : nil);
    stack[-2] = v_25068;
    goto v_25006;
v_25008:
v_25006:
    v_25068 = stack[-1];
    if (!consp(v_25068)) goto v_25024;
    else goto v_25025;
v_25024:
    v_25068 = stack[-1];
    v_25068 = Lfloat(nil, v_25068);
    env = stack[-3];
    fn = elt(env, 3); // mkround
    v_25068 = (*qfn1(fn))(fn, v_25068);
    env = stack[-3];
    stack[-1] = v_25068;
    goto v_25023;
v_25025:
v_25023:
    v_25068 = stack[0];
    if (!consp(v_25068)) goto v_25032;
    else goto v_25033;
v_25032:
    v_25068 = stack[0];
    v_25068 = Lfloat(nil, v_25068);
    env = stack[-3];
    fn = elt(env, 3); // mkround
    v_25068 = (*qfn1(fn))(fn, v_25068);
    env = stack[-3];
    stack[0] = v_25068;
    goto v_25031;
v_25033:
v_25031:
    v_25068 = stack[-2];
    if (v_25068 == nil) goto v_25041;
    goto v_25048;
v_25044:
    stack[-2] = elt(env, 1); // minus
    goto v_25045;
v_25046:
    goto v_25055;
v_25051:
    v_25069 = stack[-1];
    goto v_25052;
v_25053:
    v_25068 = stack[0];
    goto v_25054;
v_25055:
    goto v_25051;
v_25052:
    goto v_25053;
v_25054:
    fn = elt(env, 4); // rd!:times
    v_25068 = (*qfn2(fn))(fn, v_25069, v_25068);
    goto v_25047;
v_25048:
    goto v_25044;
v_25045:
    goto v_25046;
v_25047:
    {
        LispObject v_25073 = stack[-2];
        return list2(v_25073, v_25068);
    }
v_25041:
    goto v_25065;
v_25061:
    v_25069 = stack[-1];
    goto v_25062;
v_25063:
    v_25068 = stack[0];
    goto v_25064;
v_25065:
    goto v_25061;
v_25062:
    goto v_25063;
v_25064:
    {
        fn = elt(env, 4); // rd!:times
        return (*qfn2(fn))(fn, v_25069, v_25068);
    }
    v_25068 = nil;
    return onevalue(v_25068);
}



// Code for remdiff

static LispObject CC_remdiff(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_25083, v_25084;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24979);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_24979;
// end of prologue
    v_25083 = stack[-1];
    if (symbolp(v_25083)) goto v_24983;
    v_25083 = stack[-1];
    fn = elt(env, 4); // constp
    v_25083 = (*qfn1(fn))(fn, v_25083);
    env = stack[-5];
    if (v_25083 == nil) goto v_24987;
    else goto v_24983;
v_24987:
    goto v_24984;
v_24983:
    v_25083 = stack[-1];
    goto v_24982;
v_24984:
    goto v_25001;
v_24997:
    v_25083 = stack[-1];
    v_25084 = qcar(v_25083);
    goto v_24998;
v_24999:
    v_25083 = elt(env, 1); // difference
    goto v_25000;
v_25001:
    goto v_24997;
v_24998:
    goto v_24999;
v_25000:
    if (v_25084 == v_25083) goto v_24995;
    else goto v_24996;
v_24995:
    goto v_25012;
v_25006:
    stack[-3] = elt(env, 2); // plus
    goto v_25007;
v_25008:
    v_25083 = stack[-1];
    v_25083 = qcdr(v_25083);
    v_25083 = qcar(v_25083);
    stack[-2] = CC_remdiff(elt(env, 0), v_25083);
    env = stack[-5];
    goto v_25009;
v_25010:
    goto v_25023;
v_25019:
    stack[0] = elt(env, 3); // minus
    goto v_25020;
v_25021:
    v_25083 = stack[-1];
    v_25083 = qcdr(v_25083);
    v_25083 = qcdr(v_25083);
    v_25083 = qcar(v_25083);
    v_25083 = CC_remdiff(elt(env, 0), v_25083);
    env = stack[-5];
    goto v_25022;
v_25023:
    goto v_25019;
v_25020:
    goto v_25021;
v_25022:
    v_25083 = list2(stack[0], v_25083);
    env = stack[-5];
    goto v_25011;
v_25012:
    goto v_25006;
v_25007:
    goto v_25008;
v_25009:
    goto v_25010;
v_25011:
    v_25083 = list3(stack[-3], stack[-2], v_25083);
    goto v_24994;
v_24996:
    goto v_25037;
v_25033:
    v_25083 = stack[-1];
    stack[-4] = qcar(v_25083);
    goto v_25034;
v_25035:
    v_25083 = stack[-1];
    v_25083 = qcdr(v_25083);
    stack[-3] = v_25083;
    v_25083 = stack[-3];
    if (v_25083 == nil) goto v_25050;
    else goto v_25051;
v_25050:
    v_25083 = nil;
    goto v_25044;
v_25051:
    v_25083 = stack[-3];
    v_25083 = qcar(v_25083);
    v_25083 = CC_remdiff(elt(env, 0), v_25083);
    env = stack[-5];
    v_25083 = ncons(v_25083);
    env = stack[-5];
    stack[-1] = v_25083;
    stack[-2] = v_25083;
v_25045:
    v_25083 = stack[-3];
    v_25083 = qcdr(v_25083);
    stack[-3] = v_25083;
    v_25083 = stack[-3];
    if (v_25083 == nil) goto v_25064;
    else goto v_25065;
v_25064:
    v_25083 = stack[-2];
    goto v_25044;
v_25065:
    goto v_25073;
v_25069:
    stack[0] = stack[-1];
    goto v_25070;
v_25071:
    v_25083 = stack[-3];
    v_25083 = qcar(v_25083);
    v_25083 = CC_remdiff(elt(env, 0), v_25083);
    env = stack[-5];
    v_25083 = ncons(v_25083);
    env = stack[-5];
    goto v_25072;
v_25073:
    goto v_25069;
v_25070:
    goto v_25071;
v_25072:
    v_25083 = Lrplacd(nil, stack[0], v_25083);
    env = stack[-5];
    v_25083 = stack[-1];
    v_25083 = qcdr(v_25083);
    stack[-1] = v_25083;
    goto v_25045;
v_25044:
    goto v_25036;
v_25037:
    goto v_25033;
v_25034:
    goto v_25035;
v_25036:
    {
        LispObject v_25090 = stack[-4];
        return cons(v_25090, v_25083);
    }
    v_25083 = nil;
v_24994:
    goto v_24982;
    v_25083 = nil;
v_24982:
    return onevalue(v_25083);
}



// Code for remove_least_item

static LispObject CC_remove_least_item(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_25005, v_25006;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_25005 = v_24979;
// end of prologue
v_24983:
    v_25006 = v_25005;
    v_25006 = qcdr(v_25006);
    if (v_25006 == nil) goto v_24986;
    else goto v_24987;
v_24986:
    v_25005 = elt(env, 1); // "How did we get here?"
    {
        fn = elt(env, 2); // rederr
        return (*qfn1(fn))(fn, v_25005);
    }
v_24987:
    v_25006 = v_25005;
    v_25006 = qcdr(v_25006);
    v_25006 = qcar(v_25006);
    v_25006 = qcdr(v_25006);
    if (v_25006 == nil) goto v_24992;
    else goto v_24993;
v_24992:
    {
        fn = elt(env, 3); // remove_root_item
        return (*qfn1(fn))(fn, v_25005);
    }
v_24993:
    v_25005 = qcdr(v_25005);
    v_25005 = qcar(v_25005);
    goto v_24983;
    v_25005 = nil;
    return onevalue(v_25005);
}



// Code for nspaces

static LispObject CC_nspaces(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_25019, v_25020, v_25021;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24979);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_24979;
// end of prologue
    stack[-2] = nil;
    v_25019 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_25019;
v_24987:
    goto v_24999;
v_24995:
    v_25020 = stack[-1];
    goto v_24996;
v_24997:
    v_25019 = stack[0];
    goto v_24998;
v_24999:
    goto v_24995;
v_24996:
    goto v_24997;
v_24998:
    v_25019 = difference2(v_25020, v_25019);
    env = stack[-3];
    v_25019 = Lminusp(nil, v_25019);
    env = stack[-3];
    if (v_25019 == nil) goto v_24992;
    goto v_24986;
v_24992:
    goto v_25010;
v_25004:
    v_25021 = elt(env, 1); // !!
    goto v_25005;
v_25006:
    v_25020 = elt(env, 2); // ! 
    goto v_25007;
v_25008:
    v_25019 = stack[-2];
    goto v_25009;
v_25010:
    goto v_25004;
v_25005:
    goto v_25006;
v_25007:
    goto v_25008;
v_25009:
    v_25019 = list2star(v_25021, v_25020, v_25019);
    env = stack[-3];
    stack[-2] = v_25019;
    v_25019 = stack[0];
    v_25019 = add1(v_25019);
    env = stack[-3];
    stack[0] = v_25019;
    goto v_24987;
v_24986:
    v_25019 = stack[-2];
    v_25019 = Lcompress(nil, v_25019);
        return Lintern(nil, v_25019);
    return onevalue(v_25019);
}



// Code for mk_simpl_map_

static LispObject CC_mk_simpl_map_(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_24989, v_24990;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24989 = v_24979;
// end of prologue
    goto v_24986;
v_24982:
    v_24990 = v_24989;
    goto v_24983;
v_24984:
    v_24989 = nil;
    goto v_24985;
v_24986:
    goto v_24982;
v_24983:
    goto v_24984;
v_24985:
    {
        fn = elt(env, 1); // mk_simpl_map_1
        return (*qfn2(fn))(fn, v_24990, v_24989);
    }
}



// Code for mk_dummy_ids

static LispObject CC_mk_dummy_ids(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_25020, v_25021;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24979);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_25020 = v_24979;
// end of prologue
    goto v_24990;
v_24986:
    v_25021 = v_25020;
    v_25021 = qcar(v_25021);
    goto v_24987;
v_24988:
    v_25020 = qcdr(v_25020);
    v_25020 = qcar(v_25020);
    goto v_24989;
v_24990:
    goto v_24986;
v_24987:
    goto v_24988;
v_24989:
    fn = elt(env, 4); // intersection
    v_25020 = (*qfn2(fn))(fn, v_25021, v_25020);
    env = stack[-1];
    fn = elt(env, 5); // clean_numid
    v_25020 = (*qfn1(fn))(fn, v_25020);
    env = stack[-1];
    stack[0] = v_25020;
    goto v_25001;
v_24997:
    v_25021 = stack[0];
    goto v_24998;
v_24999:
    v_25020 = elt(env, 1); // dummy
    goto v_25000;
v_25001:
    goto v_24997;
v_24998:
    goto v_24999;
v_25000:
    v_25020 = Lflag(nil, v_25021, v_25020);
    env = stack[-1];
    goto v_25009;
v_25005:
    v_25021 = stack[0];
    goto v_25006;
v_25007:
    v_25020 = elt(env, 2); // reserved
    goto v_25008;
v_25009:
    goto v_25005;
v_25006:
    goto v_25007;
v_25008:
    v_25020 = Lflag(nil, v_25021, v_25020);
    env = stack[-1];
    goto v_25017;
v_25013:
    v_25021 = stack[0];
    goto v_25014;
v_25015:
    v_25020 = qvalue(elt(env, 3)); // dummy_id!*
    goto v_25016;
v_25017:
    goto v_25013;
v_25014:
    goto v_25015;
v_25016:
    fn = elt(env, 6); // union
    v_25020 = (*qfn2(fn))(fn, v_25021, v_25020);
    env = stack[-1];
    qvalue(elt(env, 3)) = v_25020; // dummy_id!*
    v_25020 = nil;
    return onevalue(v_25020);
}



// Code for createtriple

static LispObject CC_createtriple(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_25030, v_25031, v_25032;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24979);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_24979;
// end of prologue
    v_25030 = (LispObject)48+TAG_FIXNUM; // 3
    v_25030 = Lmkvect(nil, v_25030);
    env = stack[-3];
    stack[-2] = v_25030;
    goto v_24992;
v_24986:
    v_25032 = stack[-2];
    goto v_24987;
v_24988:
    v_25031 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24989;
v_24990:
    v_25030 = qvalue(elt(env, 1)); // fluidbibasistripleid
    goto v_24991;
v_24992:
    goto v_24986;
v_24987:
    goto v_24988;
v_24989:
    goto v_24990;
v_24991:
    *(LispObject *)((char *)v_25032 + (CELL-TAG_VECTOR) + (((intptr_t)v_25031-TAG_FIXNUM)/(16/CELL))) = v_25030;
    goto v_25002;
v_24996:
    v_25032 = stack[-2];
    goto v_24997;
v_24998:
    v_25031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24999;
v_25000:
    v_25030 = stack[0];
    goto v_25001;
v_25002:
    goto v_24996;
v_24997:
    goto v_24998;
v_24999:
    goto v_25000;
v_25001:
    *(LispObject *)((char *)v_25032 + (CELL-TAG_VECTOR) + (((intptr_t)v_25031-TAG_FIXNUM)/(16/CELL))) = v_25030;
    goto v_25012;
v_25006:
    v_25032 = stack[-2];
    goto v_25007;
v_25008:
    v_25031 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_25009;
v_25010:
    v_25030 = qvalue(elt(env, 1)); // fluidbibasistripleid
    goto v_25011;
v_25012:
    goto v_25006;
v_25007:
    goto v_25008;
v_25009:
    goto v_25010;
v_25011:
    *(LispObject *)((char *)v_25032 + (CELL-TAG_VECTOR) + (((intptr_t)v_25031-TAG_FIXNUM)/(16/CELL))) = v_25030;
    goto v_25022;
v_25016:
    stack[-1] = stack[-2];
    goto v_25017;
v_25018:
    stack[0] = (LispObject)48+TAG_FIXNUM; // 3
    goto v_25019;
v_25020:
    v_25030 = nil;
    v_25030 = ncons(v_25030);
    env = stack[-3];
    goto v_25021;
v_25022:
    goto v_25016;
v_25017:
    goto v_25018;
v_25019:
    goto v_25020;
v_25021:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_25030;
    v_25030 = qvalue(elt(env, 1)); // fluidbibasistripleid
    v_25030 = (LispObject)((intptr_t)(v_25030) + 0x10);
    qvalue(elt(env, 1)) = v_25030; // fluidbibasistripleid
    v_25030 = stack[-2];
    return onevalue(v_25030);
}



// Code for totalcompareconstants

static LispObject CC_totalcompareconstants(LispObject env,
                         LispObject v_24979, LispObject v_24980)
{
    env = qenv(env);
    LispObject v_25150, v_25151, v_25152;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24980,v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24979,v_24980);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_24980;
    stack[-2] = v_24979;
// end of prologue
    goto v_24990;
v_24986:
    v_25151 = stack[-2];
    goto v_24987;
v_24988:
    v_25150 = stack[-1];
    goto v_24989;
v_24990:
    goto v_24986;
v_24987:
    goto v_24988;
v_24989:
    if (equal(v_25151, v_25150)) goto v_24984;
    else goto v_24985;
v_24984:
    v_25150 = elt(env, 1); // equal
    goto v_24983;
v_24985:
    v_25150 = stack[-2];
    if (!consp(v_25150)) goto v_24998;
    else goto v_24999;
v_24998:
    v_25150 = lisp_true;
    goto v_24997;
v_24999:
    v_25150 = stack[-2];
    v_25150 = qcar(v_25150);
    v_25150 = (consp(v_25150) ? nil : lisp_true);
    goto v_24997;
    v_25150 = nil;
v_24997:
    if (v_25150 == nil) goto v_24995;
    v_25150 = stack[-1];
    if (!consp(v_25150)) goto v_25013;
    else goto v_25014;
v_25013:
    v_25150 = lisp_true;
    goto v_25012;
v_25014:
    v_25150 = stack[-1];
    v_25150 = qcar(v_25150);
    v_25150 = (consp(v_25150) ? nil : lisp_true);
    goto v_25012;
    v_25150 = nil;
v_25012:
    if (v_25150 == nil) goto v_25010;
    goto v_25031;
v_25027:
    v_25150 = stack[-2];
    if (v_25150 == nil) goto v_25034;
    else goto v_25035;
v_25034:
    v_25150 = (LispObject)0+TAG_FIXNUM; // 0
    v_25151 = v_25150;
    goto v_25033;
v_25035:
    v_25150 = stack[-2];
    v_25151 = v_25150;
    goto v_25033;
    v_25151 = nil;
v_25033:
    goto v_25028;
v_25029:
    v_25150 = stack[-1];
    if (v_25150 == nil) goto v_25043;
    else goto v_25044;
v_25043:
    v_25150 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25042;
v_25044:
    v_25150 = stack[-1];
    goto v_25042;
    v_25150 = nil;
v_25042:
    goto v_25030;
v_25031:
    goto v_25027;
v_25028:
    goto v_25029;
v_25030:
    v_25150 = (LispObject)lessp2(v_25151, v_25150);
    v_25150 = v_25150 ? lisp_true : nil;
    env = stack[-4];
    if (v_25150 == nil) goto v_25025;
    v_25150 = elt(env, 2); // less
    goto v_25023;
v_25025:
    v_25150 = elt(env, 3); // greater
    goto v_25023;
    v_25150 = nil;
v_25023:
    goto v_25008;
v_25010:
    v_25150 = elt(env, 2); // less
    goto v_25008;
    v_25150 = nil;
v_25008:
    goto v_24983;
v_24995:
    v_25150 = stack[-1];
    if (!consp(v_25150)) goto v_25061;
    else goto v_25062;
v_25061:
    v_25150 = lisp_true;
    goto v_25060;
v_25062:
    v_25150 = stack[-1];
    v_25150 = qcar(v_25150);
    v_25150 = (consp(v_25150) ? nil : lisp_true);
    goto v_25060;
    v_25150 = nil;
v_25060:
    if (v_25150 == nil) goto v_25058;
    v_25150 = elt(env, 3); // greater
    goto v_24983;
v_25058:
// Binding wukord!*
// FLUIDBIND: reloadenv=4 litvec-offset=4 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 4, -3);
    qvalue(elt(env, 4)) = nil; // wukord!*
// Binding wuvarlist!*
// FLUIDBIND: reloadenv=4 litvec-offset=5 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 5, 0);
    qvalue(elt(env, 5)) = nil; // wuvarlist!*
    goto v_25087;
v_25083:
    v_25150 = stack[-2];
    v_25150 = qcar(v_25150);
    v_25150 = qcar(v_25150);
    v_25151 = qcar(v_25150);
    goto v_25084;
v_25085:
    v_25150 = stack[-1];
    v_25150 = qcar(v_25150);
    v_25150 = qcar(v_25150);
    v_25150 = qcar(v_25150);
    goto v_25086;
v_25087:
    goto v_25083;
v_25084:
    goto v_25085;
v_25086:
    fn = elt(env, 6); // symbollessp
    v_25150 = (*qfn2(fn))(fn, v_25151, v_25150);
    env = stack[-4];
    if (v_25150 == nil) goto v_25081;
    v_25150 = elt(env, 2); // less
    goto v_25077;
v_25081:
    goto v_25104;
v_25100:
    v_25150 = stack[-1];
    v_25150 = qcar(v_25150);
    v_25150 = qcar(v_25150);
    v_25151 = qcar(v_25150);
    goto v_25101;
v_25102:
    v_25150 = stack[-2];
    v_25150 = qcar(v_25150);
    v_25150 = qcar(v_25150);
    v_25150 = qcar(v_25150);
    goto v_25103;
v_25104:
    goto v_25100;
v_25101:
    goto v_25102;
v_25103:
    fn = elt(env, 6); // symbollessp
    v_25150 = (*qfn2(fn))(fn, v_25151, v_25150);
    env = stack[-4];
    if (v_25150 == nil) goto v_25098;
    v_25150 = elt(env, 3); // greater
    goto v_25077;
v_25098:
    goto v_25121;
v_25117:
    v_25150 = stack[-2];
    v_25150 = qcar(v_25150);
    v_25151 = qcdr(v_25150);
    goto v_25118;
v_25119:
    v_25150 = stack[-1];
    v_25150 = qcar(v_25150);
    v_25150 = qcdr(v_25150);
    goto v_25120;
v_25121:
    goto v_25117;
v_25118:
    goto v_25119;
v_25120:
    v_25150 = CC_totalcompareconstants(elt(env, 0), v_25151, v_25150);
    env = stack[-4];
    v_25152 = v_25150;
    goto v_25079;
v_25079:
    goto v_25136;
v_25132:
    v_25151 = v_25152;
    goto v_25133;
v_25134:
    v_25150 = elt(env, 1); // equal
    goto v_25135;
v_25136:
    goto v_25132;
v_25133:
    goto v_25134;
v_25135:
    if (v_25151 == v_25150) goto v_25131;
    v_25150 = v_25152;
    goto v_25077;
v_25131:
    goto v_25145;
v_25141:
    v_25150 = stack[-2];
    v_25151 = qcdr(v_25150);
    goto v_25142;
v_25143:
    v_25150 = stack[-1];
    v_25150 = qcdr(v_25150);
    goto v_25144;
v_25145:
    goto v_25141;
v_25142:
    goto v_25143;
v_25144:
    v_25150 = CC_totalcompareconstants(elt(env, 0), v_25151, v_25150);
v_25077:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_24983;
    v_25150 = nil;
v_24983:
    return onevalue(v_25150);
}



// Code for gigcdsq

static LispObject CC_gigcdsq(LispObject env,
                         LispObject v_24979, LispObject v_24980)
{
    env = qenv(env);
    LispObject v_25053, v_25054;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24980,v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24979,v_24980);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_24980;
    stack[-1] = v_24979;
// end of prologue
    v_25053 = stack[-1];
    if (v_25053 == nil) goto v_24985;
    goto v_24992;
v_24988:
    v_25054 = stack[0];
    goto v_24989;
v_24990:
    v_25053 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24991;
v_24992:
    goto v_24988;
v_24989:
    goto v_24990;
v_24991:
    fn = elt(env, 2); // giintgcd
    v_25053 = (*qfn2(fn))(fn, v_25054, v_25053);
    env = stack[-3];
// Binding d
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = v_25053; // d
    goto v_25008;
v_25004:
    v_25054 = qvalue(elt(env, 1)); // d
    goto v_25005;
v_25006:
    v_25053 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25007;
v_25008:
    goto v_25004;
v_25005:
    goto v_25006;
v_25007:
    if (v_25054 == v_25053) goto v_25003;
    goto v_25016;
v_25012:
    goto v_25022;
v_25018:
    v_25054 = stack[-1];
    goto v_25019;
v_25020:
    v_25053 = qvalue(elt(env, 1)); // d
    goto v_25021;
v_25022:
    goto v_25018;
v_25019:
    goto v_25020;
v_25021:
    fn = elt(env, 2); // giintgcd
    v_25054 = (*qfn2(fn))(fn, v_25054, v_25053);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_25054; // d
    goto v_25013;
v_25014:
    v_25053 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25015;
v_25016:
    goto v_25012;
v_25013:
    goto v_25014;
v_25015:
    v_25053 = Lneq(nil, v_25054, v_25053);
    env = stack[-3];
    goto v_25001;
v_25003:
    v_25053 = nil;
    goto v_25001;
    v_25053 = nil;
v_25001:
    if (v_25053 == nil) goto v_24999;
    goto v_25034;
v_25030:
    v_25054 = stack[-1];
    goto v_25031;
v_25032:
    v_25053 = qvalue(elt(env, 1)); // d
    goto v_25033;
v_25034:
    goto v_25030;
v_25031:
    goto v_25032;
v_25033:
    fn = elt(env, 3); // quotf
    v_25053 = (*qfn2(fn))(fn, v_25054, v_25053);
    env = stack[-3];
    stack[-1] = v_25053;
    goto v_25042;
v_25038:
    v_25054 = stack[0];
    goto v_25039;
v_25040:
    v_25053 = qvalue(elt(env, 1)); // d
    goto v_25041;
v_25042:
    goto v_25038;
v_25039:
    goto v_25040;
v_25041:
    fn = elt(env, 3); // quotf
    v_25053 = (*qfn2(fn))(fn, v_25054, v_25053);
    stack[0] = v_25053;
    goto v_24997;
v_24999:
v_24997:
    ;}  // end of a binding scope
    goto v_24983;
v_24985:
v_24983:
    goto v_25050;
v_25046:
    v_25054 = stack[-1];
    goto v_25047;
v_25048:
    v_25053 = stack[0];
    goto v_25049;
v_25050:
    goto v_25046;
v_25047:
    goto v_25048;
v_25049:
    return cons(v_25054, v_25053);
}



// Code for simpexpt2

static LispObject CC_simpexpt2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25623, v_25624, v_25625;
    LispObject fn;
    LispObject v_24981, v_24980, v_24979;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "simpexpt2");
    va_start(aa, nargs);
    v_24979 = va_arg(aa, LispObject);
    v_24980 = va_arg(aa, LispObject);
    v_24981 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24981,v_24980,v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24979,v_24980,v_24981);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_24981;
    stack[-2] = v_24980;
    stack[-3] = v_24979;
// end of prologue
v_24978:
    stack[0] = nil;
    goto v_24996;
v_24992:
    v_25624 = stack[-3];
    goto v_24993;
v_24994:
    v_25623 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24995;
v_24996:
    goto v_24992;
v_24993:
    goto v_24994;
v_24995:
    if (v_25624 == v_25623) goto v_24990;
    else goto v_24991;
v_24990:
    goto v_25004;
v_25000:
    v_25624 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25001;
v_25002:
    v_25623 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25003;
v_25004:
    goto v_25000;
v_25001:
    goto v_25002;
v_25003:
    return cons(v_25624, v_25623);
v_24991:
    v_25623 = stack[-2];
    v_25623 = qcar(v_25623);
    stack[-4] = v_25623;
    v_25623 = stack[-3];
    v_25623 = Lconsp(nil, v_25623);
    env = stack[-5];
    if (v_25623 == nil) goto v_25012;
    goto v_25027;
v_25023:
    v_25623 = stack[-3];
    v_25624 = qcar(v_25623);
    goto v_25024;
v_25025:
    v_25623 = elt(env, 1); // expt
    goto v_25026;
v_25027:
    goto v_25023;
v_25024:
    goto v_25025;
v_25026:
    if (v_25624 == v_25623) goto v_25021;
    else goto v_25022;
v_25021:
    v_25623 = qvalue(elt(env, 2)); // !*precise_complex
    v_25623 = (v_25623 == nil ? lisp_true : nil);
    goto v_25020;
v_25022:
    v_25623 = nil;
    goto v_25020;
    v_25623 = nil;
v_25020:
    if (v_25623 == nil) goto v_25018;
    goto v_25041;
v_25037:
    v_25623 = stack[-3];
    v_25623 = qcdr(v_25623);
    v_25623 = qcdr(v_25623);
    v_25623 = qcar(v_25623);
    fn = elt(env, 14); // simp
    v_25624 = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    stack[-4] = v_25624;
    goto v_25038;
v_25039:
    v_25623 = stack[-2];
    goto v_25040;
v_25041:
    goto v_25037;
v_25038:
    goto v_25039;
v_25040:
    fn = elt(env, 15); // multsq
    v_25623 = (*qfn2(fn))(fn, v_25624, v_25623);
    env = stack[-5];
    stack[-2] = v_25623;
    v_25623 = qvalue(elt(env, 3)); // !*precise
    if (v_25623 == nil) goto v_25051;
    v_25623 = stack[-4];
    v_25623 = qcar(v_25623);
    if (is_number(v_25623)) goto v_25055;
    else goto v_25051;
v_25055:
    v_25623 = stack[-4];
    v_25623 = qcar(v_25623);
    v_25623 = Levenp(nil, v_25623);
    env = stack[-5];
    if (v_25623 == nil) goto v_25051;
    goto v_25067;
v_25063:
    v_25624 = elt(env, 4); // abs
    goto v_25064;
v_25065:
    v_25623 = stack[-3];
    v_25623 = qcdr(v_25623);
    v_25623 = qcar(v_25623);
    goto v_25066;
v_25067:
    goto v_25063;
v_25064:
    goto v_25065;
v_25066:
    v_25623 = list2(v_25624, v_25623);
    env = stack[-5];
    stack[-3] = v_25623;
    goto v_25049;
v_25051:
    v_25623 = stack[-3];
    v_25623 = qcdr(v_25623);
    v_25623 = qcar(v_25623);
    stack[-3] = v_25623;
    goto v_25049;
v_25049:
    goto v_25084;
v_25078:
    v_25625 = stack[-3];
    goto v_25079;
v_25080:
    v_25624 = stack[-2];
    goto v_25081;
v_25082:
    v_25623 = stack[-1];
    goto v_25083;
v_25084:
    goto v_25078;
v_25079:
    goto v_25080;
v_25081:
    goto v_25082;
v_25083:
    {
        fn = elt(env, 16); // simpexpt1
        return (*qfnn(fn))(fn, 3, v_25625, v_25624, v_25623);
    }
v_25018:
    goto v_25098;
v_25094:
    v_25623 = stack[-3];
    v_25624 = qcar(v_25623);
    goto v_25095;
v_25096:
    v_25623 = elt(env, 5); // sqrt
    goto v_25097;
v_25098:
    goto v_25094;
v_25095:
    goto v_25096;
v_25097:
    if (v_25624 == v_25623) goto v_25092;
    else goto v_25093;
v_25092:
    v_25623 = qvalue(elt(env, 6)); // !*keepsqrts
    v_25623 = (v_25623 == nil ? lisp_true : nil);
    goto v_25091;
v_25093:
    v_25623 = nil;
    goto v_25091;
    v_25623 = nil;
v_25091:
    if (v_25623 == nil) goto v_25089;
    goto v_25114;
v_25108:
    v_25623 = stack[-3];
    v_25623 = qcdr(v_25623);
    stack[0] = qcar(v_25623);
    goto v_25109;
v_25110:
    goto v_25123;
v_25119:
    goto v_25129;
v_25125:
    v_25624 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25126;
v_25127:
    v_25623 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_25128;
v_25129:
    goto v_25125;
v_25126:
    goto v_25127;
v_25128:
    v_25624 = cons(v_25624, v_25623);
    env = stack[-5];
    goto v_25120;
v_25121:
    v_25623 = stack[-2];
    goto v_25122;
v_25123:
    goto v_25119;
v_25120:
    goto v_25121;
v_25122:
    fn = elt(env, 15); // multsq
    v_25624 = (*qfn2(fn))(fn, v_25624, v_25623);
    env = stack[-5];
    goto v_25111;
v_25112:
    v_25623 = stack[-1];
    goto v_25113;
v_25114:
    goto v_25108;
v_25109:
    goto v_25110;
v_25111:
    goto v_25112;
v_25113:
    stack[-3] = stack[0];
    stack[-2] = v_25624;
    stack[-1] = v_25623;
    goto v_24978;
v_25089:
    goto v_25144;
v_25140:
    v_25623 = stack[-3];
    v_25624 = qcar(v_25623);
    goto v_25141;
v_25142:
    v_25623 = elt(env, 7); // times
    goto v_25143;
v_25144:
    goto v_25140;
v_25141:
    goto v_25142;
v_25143:
    if (v_25624 == v_25623) goto v_25138;
    else goto v_25139;
v_25138:
    v_25623 = qvalue(elt(env, 3)); // !*precise
    if (v_25623 == nil) goto v_25150;
    else goto v_25151;
v_25150:
    v_25623 = qvalue(elt(env, 8)); // !*modular
    v_25623 = (v_25623 == nil ? lisp_true : nil);
    goto v_25149;
v_25151:
    v_25623 = nil;
    goto v_25149;
    v_25623 = nil;
v_25149:
    goto v_25137;
v_25139:
    v_25623 = nil;
    goto v_25137;
    v_25623 = nil;
v_25137:
    if (v_25623 == nil) goto v_25135;
    goto v_25166;
v_25162:
    v_25624 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25163;
v_25164:
    v_25623 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25165;
v_25166:
    goto v_25162;
v_25163:
    goto v_25164;
v_25165:
    v_25623 = cons(v_25624, v_25623);
    env = stack[-5];
    stack[-4] = v_25623;
    v_25623 = stack[-3];
    v_25623 = qcdr(v_25623);
    stack[0] = v_25623;
v_25172:
    v_25623 = stack[0];
    if (v_25623 == nil) goto v_25177;
    else goto v_25178;
v_25177:
    goto v_25171;
v_25178:
    v_25623 = stack[0];
    v_25623 = qcar(v_25623);
    goto v_25189;
v_25185:
    goto v_25197;
v_25191:
    v_25625 = v_25623;
    goto v_25192;
v_25193:
    v_25624 = stack[-2];
    goto v_25194;
v_25195:
    v_25623 = stack[-1];
    goto v_25196;
v_25197:
    goto v_25191;
v_25192:
    goto v_25193;
v_25194:
    goto v_25195;
v_25196:
    fn = elt(env, 16); // simpexpt1
    v_25624 = (*qfnn(fn))(fn, 3, v_25625, v_25624, v_25623);
    env = stack[-5];
    goto v_25186;
v_25187:
    v_25623 = stack[-4];
    goto v_25188;
v_25189:
    goto v_25185;
v_25186:
    goto v_25187;
v_25188:
    fn = elt(env, 15); // multsq
    v_25623 = (*qfn2(fn))(fn, v_25624, v_25623);
    env = stack[-5];
    stack[-4] = v_25623;
    v_25623 = stack[0];
    v_25623 = qcdr(v_25623);
    stack[0] = v_25623;
    goto v_25172;
v_25171:
    v_25623 = stack[-4];
    goto v_24987;
v_25135:
    goto v_25215;
v_25211:
    v_25623 = stack[-3];
    v_25624 = qcar(v_25623);
    goto v_25212;
v_25213:
    v_25623 = elt(env, 7); // times
    goto v_25214;
v_25215:
    goto v_25211;
v_25212:
    goto v_25213;
v_25214:
    if (v_25624 == v_25623) goto v_25209;
    else goto v_25210;
v_25209:
    v_25623 = stack[-3];
    v_25623 = qcdr(v_25623);
    fn = elt(env, 17); // split!-sign
    v_25623 = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    stack[0] = v_25623;
    if (v_25623 == nil) goto v_25221;
    else goto v_25222;
v_25221:
    v_25623 = nil;
    goto v_25220;
v_25222:
    v_25623 = stack[0];
    v_25623 = qcar(v_25623);
    goto v_25220;
    v_25623 = nil;
v_25220:
    goto v_25208;
v_25210:
    v_25623 = nil;
    goto v_25208;
    v_25623 = nil;
v_25208:
    if (v_25623 == nil) goto v_25206;
    goto v_25241;
v_25235:
    goto v_25248;
v_25244:
    v_25623 = stack[0];
    v_25623 = qcdr(v_25623);
    v_25624 = qcar(v_25623);
    goto v_25245;
v_25246:
    v_25623 = stack[0];
    v_25623 = qcdr(v_25623);
    v_25623 = qcdr(v_25623);
    goto v_25247;
v_25248:
    goto v_25244;
v_25245:
    goto v_25246;
v_25247:
    v_25623 = Lappend(nil, v_25624, v_25623);
    env = stack[-5];
    fn = elt(env, 18); // retimes
    v_25625 = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    goto v_25236;
v_25237:
    v_25624 = stack[-2];
    goto v_25238;
v_25239:
    v_25623 = stack[-1];
    goto v_25240;
v_25241:
    goto v_25235;
v_25236:
    goto v_25237;
v_25238:
    goto v_25239;
v_25240:
    fn = elt(env, 16); // simpexpt1
    v_25623 = (*qfnn(fn))(fn, 3, v_25625, v_25624, v_25623);
    env = stack[-5];
    stack[-4] = v_25623;
    v_25623 = stack[0];
    v_25623 = qcar(v_25623);
    stack[0] = v_25623;
v_25260:
    v_25623 = stack[0];
    if (v_25623 == nil) goto v_25265;
    else goto v_25266;
v_25265:
    goto v_25259;
v_25266:
    v_25623 = stack[0];
    v_25623 = qcar(v_25623);
    goto v_25277;
v_25273:
    goto v_25285;
v_25279:
    v_25625 = v_25623;
    goto v_25280;
v_25281:
    v_25624 = stack[-2];
    goto v_25282;
v_25283:
    v_25623 = stack[-1];
    goto v_25284;
v_25285:
    goto v_25279;
v_25280:
    goto v_25281;
v_25282:
    goto v_25283;
v_25284:
    fn = elt(env, 16); // simpexpt1
    v_25624 = (*qfnn(fn))(fn, 3, v_25625, v_25624, v_25623);
    env = stack[-5];
    goto v_25274;
v_25275:
    v_25623 = stack[-4];
    goto v_25276;
v_25277:
    goto v_25273;
v_25274:
    goto v_25275;
v_25276:
    fn = elt(env, 15); // multsq
    v_25623 = (*qfn2(fn))(fn, v_25624, v_25623);
    env = stack[-5];
    stack[-4] = v_25623;
    v_25623 = stack[0];
    v_25623 = qcdr(v_25623);
    stack[0] = v_25623;
    goto v_25260;
v_25259:
    v_25623 = stack[-4];
    goto v_24987;
v_25206:
    goto v_25303;
v_25299:
    v_25623 = stack[-3];
    v_25624 = qcar(v_25623);
    goto v_25300;
v_25301:
    v_25623 = elt(env, 9); // quotient
    goto v_25302;
v_25303:
    goto v_25299;
v_25300:
    goto v_25301;
v_25302:
    if (v_25624 == v_25623) goto v_25297;
    else goto v_25298;
v_25297:
    v_25623 = qvalue(elt(env, 3)); // !*precise
    if (v_25623 == nil) goto v_25309;
    else goto v_25310;
v_25309:
    v_25623 = lisp_true;
    goto v_25308;
v_25310:
    v_25623 = stack[-3];
    v_25623 = qcdr(v_25623);
    v_25623 = qcdr(v_25623);
    v_25623 = qcar(v_25623);
    fn = elt(env, 19); // posnump
    v_25623 = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    if (v_25623 == nil) goto v_25317;
    else goto v_25318;
v_25317:
    v_25623 = nil;
    goto v_25316;
v_25318:
    v_25623 = stack[-2];
    fn = elt(env, 20); // prepsq
    v_25623 = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    fn = elt(env, 19); // posnump
    v_25623 = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    goto v_25316;
    v_25623 = nil;
v_25316:
    goto v_25308;
    v_25623 = nil;
v_25308:
    goto v_25296;
v_25298:
    v_25623 = nil;
    goto v_25296;
    v_25623 = nil;
v_25296:
    if (v_25623 == nil) goto v_25294;
    v_25623 = stack[-1];
    if (v_25623 == nil) goto v_25339;
    else goto v_25340;
v_25339:
    v_25623 = qvalue(elt(env, 10)); // !*mcd
    goto v_25338;
v_25340:
    v_25623 = nil;
    goto v_25338;
    v_25623 = nil;
v_25338:
    if (v_25623 == nil) goto v_25336;
    goto v_25353;
v_25347:
    v_25623 = stack[-3];
    fn = elt(env, 21); // simp!*
    v_25623 = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    fn = elt(env, 20); // prepsq
    v_25625 = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    goto v_25348;
v_25349:
    v_25624 = stack[-2];
    goto v_25350;
v_25351:
    v_25623 = lisp_true;
    goto v_25352;
v_25353:
    goto v_25347;
v_25348:
    goto v_25349;
v_25350:
    goto v_25351;
v_25352:
    {
        fn = elt(env, 16); // simpexpt1
        return (*qfnn(fn))(fn, 3, v_25625, v_25624, v_25623);
    }
v_25336:
    v_25623 = stack[-2];
    fn = elt(env, 20); // prepsq
    v_25623 = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    stack[-2] = v_25623;
    goto v_25366;
v_25362:
    goto v_25373;
v_25369:
    v_25623 = stack[-3];
    v_25623 = qcdr(v_25623);
    v_25624 = qcar(v_25623);
    goto v_25370;
v_25371:
    v_25623 = stack[-2];
    goto v_25372;
v_25373:
    goto v_25369;
v_25370:
    goto v_25371;
v_25372:
    v_25623 = list2(v_25624, v_25623);
    env = stack[-5];
    fn = elt(env, 22); // simpexpt
    stack[0] = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    goto v_25363;
v_25364:
    goto v_25384;
v_25380:
    v_25623 = stack[-3];
    v_25623 = qcdr(v_25623);
    v_25623 = qcdr(v_25623);
    v_25624 = qcar(v_25623);
    goto v_25381;
v_25382:
    v_25623 = stack[-2];
    goto v_25383;
v_25384:
    goto v_25380;
v_25381:
    goto v_25382;
v_25383:
    v_25623 = list2(v_25624, v_25623);
    env = stack[-5];
    fn = elt(env, 22); // simpexpt
    v_25623 = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    goto v_25365;
v_25366:
    goto v_25362;
v_25363:
    goto v_25364;
v_25365:
    {
        LispObject v_25631 = stack[0];
        fn = elt(env, 23); // quotsq
        return (*qfn2(fn))(fn, v_25631, v_25623);
    }
v_25294:
    goto v_25400;
v_25396:
    v_25623 = stack[-3];
    v_25624 = qcar(v_25623);
    goto v_25397;
v_25398:
    v_25623 = elt(env, 11); // minus
    goto v_25399;
v_25400:
    goto v_25396;
v_25397:
    goto v_25398;
v_25399:
    if (v_25624 == v_25623) goto v_25394;
    else goto v_25395;
v_25394:
    v_25623 = qvalue(elt(env, 3)); // !*precise
    if (v_25623 == nil) goto v_25406;
    else goto v_25407;
v_25406:
    goto v_25413;
v_25409:
    v_25623 = stack[-3];
    v_25623 = qcdr(v_25623);
    v_25624 = qcar(v_25623);
    goto v_25410;
v_25411:
    v_25623 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25412;
v_25413:
    goto v_25409;
v_25410:
    goto v_25411;
v_25412:
    v_25623 = (v_25624 == v_25623 ? lisp_true : nil);
    v_25623 = (v_25623 == nil ? lisp_true : nil);
    goto v_25405;
v_25407:
    v_25623 = nil;
    goto v_25405;
    v_25623 = nil;
v_25405:
    goto v_25393;
v_25395:
    v_25623 = nil;
    goto v_25393;
    v_25623 = nil;
v_25393:
    if (v_25623 == nil) goto v_25391;
    v_25623 = stack[-2];
    fn = elt(env, 20); // prepsq
    v_25623 = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    stack[-1] = v_25623;
    goto v_25434;
v_25430:
    goto v_25441;
v_25437:
    v_25624 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_25438;
v_25439:
    v_25623 = stack[-1];
    goto v_25440;
v_25441:
    goto v_25437;
v_25438:
    goto v_25439;
v_25440:
    v_25623 = list2(v_25624, v_25623);
    env = stack[-5];
    fn = elt(env, 22); // simpexpt
    stack[0] = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    goto v_25431;
v_25432:
    goto v_25450;
v_25446:
    v_25623 = stack[-3];
    v_25623 = qcdr(v_25623);
    v_25624 = qcar(v_25623);
    goto v_25447;
v_25448:
    v_25623 = stack[-1];
    goto v_25449;
v_25450:
    goto v_25446;
v_25447:
    goto v_25448;
v_25449:
    v_25623 = list2(v_25624, v_25623);
    env = stack[-5];
    fn = elt(env, 22); // simpexpt
    v_25623 = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    goto v_25433;
v_25434:
    goto v_25430;
v_25431:
    goto v_25432;
v_25433:
    {
        LispObject v_25632 = stack[0];
        fn = elt(env, 15); // multsq
        return (*qfn2(fn))(fn, v_25632, v_25623);
    }
v_25391:
    goto v_25010;
v_25012:
v_25010:
    v_25623 = stack[-1];
    if (v_25623 == nil) goto v_25457;
    else goto v_25458;
v_25457:
    v_25623 = qvalue(elt(env, 12)); // dmode!*
    if (v_25623 == nil) goto v_25462;
    v_25623 = stack[-3];
    if (symbolp(v_25623)) goto v_25467;
    else goto v_25462;
v_25467:
    goto v_25475;
v_25471:
    v_25624 = stack[-3];
    goto v_25472;
v_25473:
    v_25623 = qvalue(elt(env, 12)); // dmode!*
    goto v_25474;
v_25475:
    goto v_25471;
v_25472:
    goto v_25473;
v_25474:
    v_25623 = get(v_25624, v_25623);
    env = stack[-5];
    if (v_25623 == nil) goto v_25462;
    goto v_25463;
v_25462:
    v_25623 = stack[-3];
    fn = elt(env, 21); // simp!*
    v_25623 = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    fn = elt(env, 20); // prepsq
    v_25623 = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    stack[-3] = v_25623;
    goto v_25461;
v_25463:
v_25461:
    goto v_25488;
v_25482:
    v_25625 = stack[-3];
    goto v_25483;
v_25484:
    v_25624 = stack[-2];
    goto v_25485;
v_25486:
    v_25623 = lisp_true;
    goto v_25487;
v_25488:
    goto v_25482;
v_25483:
    goto v_25484;
v_25485:
    goto v_25486;
v_25487:
    {
        fn = elt(env, 16); // simpexpt1
        return (*qfnn(fn))(fn, 3, v_25625, v_25624, v_25623);
    }
v_25458:
    v_25623 = stack[-3];
    if (is_number(v_25623)) goto v_25494;
    else goto v_25493;
v_25494:
    v_25623 = stack[-3];
    v_25623 = (LispObject)zerop(v_25623);
    v_25623 = v_25623 ? lisp_true : nil;
    env = stack[-5];
    if (v_25623 == nil) goto v_25493;
    goto v_25504;
v_25500:
    v_25624 = nil;
    goto v_25501;
v_25502:
    v_25623 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25503;
v_25504:
    goto v_25500;
v_25501:
    goto v_25502;
v_25503:
    return cons(v_25624, v_25623);
v_25493:
    v_25623 = stack[-4];
    if (is_number(v_25623)) goto v_25508;
    v_25623 = stack[-4];
    fn = elt(env, 24); // prepf
    v_25623 = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    stack[-4] = v_25623;
    goto v_25456;
v_25508:
v_25456:
    v_25623 = stack[-2];
    v_25623 = qcdr(v_25623);
    fn = elt(env, 24); // prepf
    v_25623 = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    stack[-2] = v_25623;
    goto v_25524;
v_25520:
    v_25624 = stack[-4];
    goto v_25521;
v_25522:
    v_25623 = qvalue(elt(env, 13)); // frlis!*
    goto v_25523;
v_25524:
    goto v_25520;
v_25521:
    goto v_25522;
v_25523:
    v_25623 = Lmemq(nil, v_25624, v_25623);
    if (v_25623 == nil) goto v_25518;
    goto v_25533;
v_25529:
    v_25624 = stack[-2];
    goto v_25530;
v_25531:
    v_25623 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25532;
v_25533:
    goto v_25529;
v_25530:
    goto v_25531;
v_25532:
    if (v_25624 == v_25623) goto v_25528;
    else goto v_25518;
v_25528:
    goto v_25541;
v_25537:
    goto v_25550;
v_25544:
    v_25625 = stack[-3];
    goto v_25545;
v_25546:
    v_25624 = stack[-4];
    goto v_25547;
v_25548:
    v_25623 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25549;
v_25550:
    goto v_25544;
v_25545:
    goto v_25546;
v_25547:
    goto v_25548;
v_25549:
    v_25623 = acons(v_25625, v_25624, v_25623);
    env = stack[-5];
    v_25624 = ncons(v_25623);
    goto v_25538;
v_25539:
    v_25623 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25540;
v_25541:
    goto v_25537;
v_25538:
    goto v_25539;
v_25540:
    return cons(v_25624, v_25623);
v_25518:
    v_25623 = qvalue(elt(env, 10)); // !*mcd
    if (v_25623 == nil) goto v_25559;
    else goto v_25557;
v_25559:
    v_25623 = stack[-4];
    if (is_number(v_25623)) goto v_25565;
    v_25623 = lisp_true;
    goto v_25563;
v_25565:
    goto v_25578;
v_25574:
    v_25624 = stack[-2];
    goto v_25575;
v_25576:
    v_25623 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25577;
v_25578:
    goto v_25574;
v_25575:
    goto v_25576;
v_25577:
    if (v_25624 == v_25623) goto v_25573;
    v_25623 = lisp_true;
    goto v_25571;
v_25573:
    v_25623 = stack[-3];
    if (!consp(v_25623)) goto v_25586;
    else goto v_25587;
v_25586:
    v_25623 = lisp_true;
    goto v_25585;
v_25587:
    goto v_25597;
v_25593:
    v_25623 = stack[-3];
    fn = elt(env, 21); // simp!*
    v_25623 = (*qfn1(fn))(fn, v_25623);
    env = stack[-5];
    v_25624 = qcdr(v_25623);
    goto v_25594;
v_25595:
    v_25623 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25596;
v_25597:
    goto v_25593;
v_25594:
    goto v_25595;
v_25596:
    v_25623 = Lneq(nil, v_25624, v_25623);
    env = stack[-5];
    goto v_25585;
    v_25623 = nil;
v_25585:
    goto v_25571;
    v_25623 = nil;
v_25571:
    goto v_25563;
    v_25623 = nil;
v_25563:
    if (v_25623 == nil) goto v_25561;
    else goto v_25557;
v_25561:
    goto v_25558;
v_25557:
    goto v_25609;
v_25603:
    v_25625 = stack[-3];
    goto v_25604;
v_25605:
    v_25624 = stack[-4];
    goto v_25606;
v_25607:
    v_25623 = stack[-2];
    goto v_25608;
v_25609:
    goto v_25603;
v_25604:
    goto v_25605;
v_25606:
    goto v_25607;
v_25608:
    {
        fn = elt(env, 25); // simpx1
        return (*qfnn(fn))(fn, 3, v_25625, v_25624, v_25623);
    }
v_25558:
    goto v_25620;
v_25616:
    v_25624 = stack[-3];
    goto v_25617;
v_25618:
    v_25623 = stack[-4];
    goto v_25619;
v_25620:
    goto v_25616;
v_25617:
    goto v_25618;
v_25619:
    {
        fn = elt(env, 26); // mksq
        return (*qfn2(fn))(fn, v_25624, v_25623);
    }
    v_25623 = nil;
v_24987:
    return onevalue(v_25623);
}



// Code for mk!+resimp!+mat

static LispObject CC_mkLresimpLmat(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_25109;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24979);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    v_25109 = v_24979;
// end of prologue
    stack[-7] = v_25109;
    v_25109 = stack[-7];
    if (v_25109 == nil) goto v_24995;
    else goto v_24996;
v_24995:
    v_25109 = nil;
    goto v_24990;
v_24996:
    v_25109 = stack[-7];
    v_25109 = qcar(v_25109);
    stack[-3] = v_25109;
    v_25109 = stack[-3];
    if (v_25109 == nil) goto v_25012;
    else goto v_25013;
v_25012:
    v_25109 = nil;
    goto v_25007;
v_25013:
    v_25109 = stack[-3];
    v_25109 = qcar(v_25109);
    fn = elt(env, 1); // resimp
    v_25109 = (*qfn1(fn))(fn, v_25109);
    env = stack[-8];
    v_25109 = ncons(v_25109);
    env = stack[-8];
    stack[-1] = v_25109;
    stack[-2] = v_25109;
v_25008:
    v_25109 = stack[-3];
    v_25109 = qcdr(v_25109);
    stack[-3] = v_25109;
    v_25109 = stack[-3];
    if (v_25109 == nil) goto v_25026;
    else goto v_25027;
v_25026:
    v_25109 = stack[-2];
    goto v_25007;
v_25027:
    goto v_25035;
v_25031:
    stack[0] = stack[-1];
    goto v_25032;
v_25033:
    v_25109 = stack[-3];
    v_25109 = qcar(v_25109);
    fn = elt(env, 1); // resimp
    v_25109 = (*qfn1(fn))(fn, v_25109);
    env = stack[-8];
    v_25109 = ncons(v_25109);
    env = stack[-8];
    goto v_25034;
v_25035:
    goto v_25031;
v_25032:
    goto v_25033;
v_25034:
    v_25109 = Lrplacd(nil, stack[0], v_25109);
    env = stack[-8];
    v_25109 = stack[-1];
    v_25109 = qcdr(v_25109);
    stack[-1] = v_25109;
    goto v_25008;
v_25007:
    v_25109 = ncons(v_25109);
    env = stack[-8];
    stack[-5] = v_25109;
    stack[-6] = v_25109;
v_24991:
    v_25109 = stack[-7];
    v_25109 = qcdr(v_25109);
    stack[-7] = v_25109;
    v_25109 = stack[-7];
    if (v_25109 == nil) goto v_25049;
    else goto v_25050;
v_25049:
    v_25109 = stack[-6];
    goto v_24990;
v_25050:
    goto v_25058;
v_25054:
    stack[-4] = stack[-5];
    goto v_25055;
v_25056:
    v_25109 = stack[-7];
    v_25109 = qcar(v_25109);
    stack[-3] = v_25109;
    v_25109 = stack[-3];
    if (v_25109 == nil) goto v_25073;
    else goto v_25074;
v_25073:
    v_25109 = nil;
    goto v_25068;
v_25074:
    v_25109 = stack[-3];
    v_25109 = qcar(v_25109);
    fn = elt(env, 1); // resimp
    v_25109 = (*qfn1(fn))(fn, v_25109);
    env = stack[-8];
    v_25109 = ncons(v_25109);
    env = stack[-8];
    stack[-1] = v_25109;
    stack[-2] = v_25109;
v_25069:
    v_25109 = stack[-3];
    v_25109 = qcdr(v_25109);
    stack[-3] = v_25109;
    v_25109 = stack[-3];
    if (v_25109 == nil) goto v_25087;
    else goto v_25088;
v_25087:
    v_25109 = stack[-2];
    goto v_25068;
v_25088:
    goto v_25096;
v_25092:
    stack[0] = stack[-1];
    goto v_25093;
v_25094:
    v_25109 = stack[-3];
    v_25109 = qcar(v_25109);
    fn = elt(env, 1); // resimp
    v_25109 = (*qfn1(fn))(fn, v_25109);
    env = stack[-8];
    v_25109 = ncons(v_25109);
    env = stack[-8];
    goto v_25095;
v_25096:
    goto v_25092;
v_25093:
    goto v_25094;
v_25095:
    v_25109 = Lrplacd(nil, stack[0], v_25109);
    env = stack[-8];
    v_25109 = stack[-1];
    v_25109 = qcdr(v_25109);
    stack[-1] = v_25109;
    goto v_25069;
v_25068:
    v_25109 = ncons(v_25109);
    env = stack[-8];
    goto v_25057;
v_25058:
    goto v_25054;
v_25055:
    goto v_25056;
v_25057:
    v_25109 = Lrplacd(nil, stack[-4], v_25109);
    env = stack[-8];
    v_25109 = stack[-5];
    v_25109 = qcdr(v_25109);
    stack[-5] = v_25109;
    goto v_24991;
v_24990:
    return onevalue(v_25109);
}



// Code for talp_invtscsimpl

static LispObject CC_talp_invtscsimpl(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_25120, v_25121, v_25122;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24979);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_24979;
// end of prologue
    v_25120 = stack[0];
    fn = elt(env, 4); // talp_rnf
    v_25120 = (*qfn1(fn))(fn, v_25120);
    env = stack[-5];
    stack[0] = v_25120;
    v_25120 = stack[0];
    if (!consp(v_25120)) goto v_24988;
    else goto v_24989;
v_24988:
    v_25120 = stack[0];
    goto v_24983;
v_24989:
    v_25120 = stack[0];
    fn = elt(env, 5); // talp_atfp
    v_25120 = (*qfn1(fn))(fn, v_25120);
    env = stack[-5];
    if (v_25120 == nil) goto v_24995;
    v_25120 = stack[0];
    fn = elt(env, 6); // talp_invtscc
    v_25120 = (*qfn1(fn))(fn, v_25120);
    env = stack[-5];
    if (v_25120 == nil) goto v_25001;
    v_25120 = stack[0];
    fn = elt(env, 7); // talp_simpat
    v_25120 = (*qfn1(fn))(fn, v_25120);
    env = stack[-5];
    fn = elt(env, 8); // talp_invtscsimplat
    v_25120 = (*qfn1(fn))(fn, v_25120);
    env = stack[-5];
    {
        fn = elt(env, 4); // talp_rnf
        return (*qfn1(fn))(fn, v_25120);
    }
v_25001:
    v_25120 = stack[0];
    {
        fn = elt(env, 7); // talp_simpat
        return (*qfn1(fn))(fn, v_25120);
    }
    goto v_24993;
v_24995:
v_24993:
    v_25120 = stack[0];
    fn = elt(env, 9); // talp_op
    v_25120 = (*qfn1(fn))(fn, v_25120);
    env = stack[-5];
    v_25122 = v_25120;
    goto v_25026;
v_25022:
    v_25121 = v_25122;
    goto v_25023;
v_25024:
    v_25120 = elt(env, 1); // or
    goto v_25025;
v_25026:
    goto v_25022;
v_25023:
    goto v_25024;
v_25025:
    if (v_25121 == v_25120) goto v_25020;
    else goto v_25021;
v_25020:
    v_25120 = lisp_true;
    goto v_25019;
v_25021:
    goto v_25036;
v_25032:
    v_25121 = v_25122;
    goto v_25033;
v_25034:
    v_25120 = elt(env, 2); // and
    goto v_25035;
v_25036:
    goto v_25032;
v_25033:
    goto v_25034;
v_25035:
    v_25120 = (v_25121 == v_25120 ? lisp_true : nil);
    goto v_25019;
    v_25120 = nil;
v_25019:
    if (v_25120 == nil) goto v_25017;
    goto v_25046;
v_25042:
    stack[-4] = v_25122;
    goto v_25043;
v_25044:
    v_25120 = stack[0];
    fn = elt(env, 10); // talp_argl
    v_25120 = (*qfn1(fn))(fn, v_25120);
    env = stack[-5];
    stack[-3] = v_25120;
    v_25120 = stack[-3];
    if (v_25120 == nil) goto v_25058;
    else goto v_25059;
v_25058:
    v_25120 = nil;
    goto v_25052;
v_25059:
    v_25120 = stack[-3];
    v_25120 = qcar(v_25120);
    v_25120 = CC_talp_invtscsimpl(elt(env, 0), v_25120);
    env = stack[-5];
    v_25120 = ncons(v_25120);
    env = stack[-5];
    stack[-1] = v_25120;
    stack[-2] = v_25120;
v_25053:
    v_25120 = stack[-3];
    v_25120 = qcdr(v_25120);
    stack[-3] = v_25120;
    v_25120 = stack[-3];
    if (v_25120 == nil) goto v_25072;
    else goto v_25073;
v_25072:
    v_25120 = stack[-2];
    goto v_25052;
v_25073:
    goto v_25081;
v_25077:
    stack[0] = stack[-1];
    goto v_25078;
v_25079:
    v_25120 = stack[-3];
    v_25120 = qcar(v_25120);
    v_25120 = CC_talp_invtscsimpl(elt(env, 0), v_25120);
    env = stack[-5];
    v_25120 = ncons(v_25120);
    env = stack[-5];
    goto v_25080;
v_25081:
    goto v_25077;
v_25078:
    goto v_25079;
v_25080:
    v_25120 = Lrplacd(nil, stack[0], v_25120);
    env = stack[-5];
    v_25120 = stack[-1];
    v_25120 = qcdr(v_25120);
    stack[-1] = v_25120;
    goto v_25053;
v_25052:
    goto v_25045;
v_25046:
    goto v_25042;
v_25043:
    goto v_25044;
v_25045:
    v_25120 = cons(stack[-4], v_25120);
    env = stack[-5];
    {
        fn = elt(env, 4); // talp_rnf
        return (*qfn1(fn))(fn, v_25120);
    }
v_25017:
    goto v_25097;
v_25093:
    v_25121 = v_25122;
    goto v_25094;
v_25095:
    v_25120 = elt(env, 3); // (ex all)
    goto v_25096;
v_25097:
    goto v_25093;
v_25094:
    goto v_25095;
v_25096:
    v_25120 = Lmemq(nil, v_25121, v_25120);
    if (v_25120 == nil) goto v_25092;
    goto v_25109;
v_25103:
    stack[-2] = v_25122;
    goto v_25104;
v_25105:
    v_25120 = stack[0];
    v_25120 = qcdr(v_25120);
    stack[-1] = qcar(v_25120);
    goto v_25106;
v_25107:
    v_25120 = stack[0];
    v_25120 = qcdr(v_25120);
    v_25120 = qcdr(v_25120);
    v_25120 = qcar(v_25120);
    v_25120 = CC_talp_invtscsimpl(elt(env, 0), v_25120);
    env = stack[-5];
    v_25120 = ncons(v_25120);
    env = stack[-5];
    goto v_25108;
v_25109:
    goto v_25103;
v_25104:
    goto v_25105;
v_25106:
    goto v_25107;
v_25108:
    v_25120 = list2star(stack[-2], stack[-1], v_25120);
    env = stack[-5];
    {
        fn = elt(env, 4); // talp_rnf
        return (*qfn1(fn))(fn, v_25120);
    }
v_25092:
    v_25120 = nil;
v_24983:
    return onevalue(v_25120);
}



// Code for conditionrd

static LispObject CC_conditionrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25015, v_25016, v_25017;
    LispObject fn;
    argcheck(nargs, 0, "conditionrd");
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
    fn = elt(env, 5); // mathml
    v_25015 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_25015;
    fn = elt(env, 6); // lex
    v_25015 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_24993;
v_24989:
    v_25016 = qvalue(elt(env, 1)); // char
    goto v_24990;
v_24991:
    v_25015 = elt(env, 2); // (!/ c o n d i t i o n)
    goto v_24992;
v_24993:
    goto v_24989;
v_24990:
    goto v_24991;
v_24992:
    if (equal(v_25016, v_25015)) goto v_24988;
    goto v_25001;
v_24997:
    v_25016 = elt(env, 3); // "</condition>"
    goto v_24998;
v_24999:
    v_25015 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_25000;
v_25001:
    goto v_24997;
v_24998:
    goto v_24999;
v_25000:
    fn = elt(env, 7); // errorml
    v_25015 = (*qfn2(fn))(fn, v_25016, v_25015);
    env = stack[-1];
    goto v_24986;
v_24988:
v_24986:
    goto v_25011;
v_25005:
    v_25017 = elt(env, 4); // condition
    goto v_25006;
v_25007:
    v_25016 = stack[0];
    goto v_25008;
v_25009:
    v_25015 = nil;
    goto v_25010;
v_25011:
    goto v_25005;
v_25006:
    goto v_25007;
v_25008:
    goto v_25009;
v_25010:
    return list2star(v_25017, v_25016, v_25015);
    return onevalue(v_25015);
}



// Code for ieval

static LispObject CC_ieval(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_24984;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24979);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_24984 = v_24979;
// end of prologue
    fn = elt(env, 1); // reval
    v_24984 = (*qfn1(fn))(fn, v_24984);
    env = stack[0];
    {
        fn = elt(env, 2); // !*s2i
        return (*qfn1(fn))(fn, v_24984);
    }
}



// Code for znumrnil

static LispObject CC_znumrnil(LispObject env,
                         LispObject v_24979)
{
    env = qenv(env);
    LispObject v_24998, v_24999;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24979);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24979);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_24979;
// end of prologue
    v_24998 = stack[0];
    fn = elt(env, 1); // znumr
    v_24998 = (*qfn1(fn))(fn, v_24998);
    if (v_24998 == nil) goto v_24984;
    goto v_24992;
v_24988:
    v_24999 = nil;
    goto v_24989;
v_24990:
    v_24998 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24991;
v_24992:
    goto v_24988;
v_24989:
    goto v_24990;
v_24991:
    return cons(v_24999, v_24998);
v_24984:
    v_24998 = stack[0];
    goto v_24982;
    v_24998 = nil;
v_24982:
    return onevalue(v_24998);
}



setup_type const u44_setup[] =
{
    {"cl_gand-col",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_gandKcol},
    {"conditionml",             CC_conditionml, TOO_MANY_1,    WRONG_NO_1},
    {"rnfix*",                  CC_rnfixH,      TOO_MANY_1,    WRONG_NO_1},
    {"dip2a",                   CC_dip2a,       TOO_MANY_1,    WRONG_NO_1},
    {"mkexdf",                  CC_mkexdf,      TOO_MANY_1,    WRONG_NO_1},
    {"markedvarp",              CC_markedvarp,  TOO_MANY_1,    WRONG_NO_1},
    {"ev-edgeloop",             TOO_FEW_2,      CC_evKedgeloop,WRONG_NO_2},
    {"applsmacro",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_applsmacro},
    {"prepsq*0",                TOO_FEW_2,      CC_prepsqH0,   WRONG_NO_2},
    {"change+int+to+sq",        CC_changeLintLtoLsq,TOO_MANY_1,WRONG_NO_1},
    {"pasf_coeflst",            TOO_FEW_2,      CC_pasf_coeflst,WRONG_NO_2},
    {"lto_sgnchg1",             CC_lto_sgnchg1, TOO_MANY_1,    WRONG_NO_1},
    {"numir",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_numir},
    {"mkexpt",                  TOO_FEW_2,      CC_mkexpt,     WRONG_NO_2},
    {"evalmember",              TOO_FEW_2,      CC_evalmember, WRONG_NO_2},
    {"e*",                      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_eH},
    {"gpargp",                  CC_gpargp,      TOO_MANY_1,    WRONG_NO_1},
    {"indexvp",                 CC_indexvp,     TOO_MANY_1,    WRONG_NO_1},
    {"extract_vars",            CC_extract_vars,TOO_MANY_1,    WRONG_NO_1},
    {"ev_mtest?",               TOO_FEW_2,      CC_ev_mtestW,  WRONG_NO_2},
    {"cgp_greenp",              CC_cgp_greenp,  TOO_MANY_1,    WRONG_NO_1},
    {"matrixml",                CC_matrixml,    TOO_MANY_1,    WRONG_NO_1},
    {"ps:arg-values",           CC_psTargKvalues,TOO_MANY_1,   WRONG_NO_1},
    {"diford",                  CC_diford,      TOO_MANY_1,    WRONG_NO_1},
    {"specrd:times",            TOO_FEW_2,      CC_specrdTtimes,WRONG_NO_2},
    {"remdiff",                 CC_remdiff,     TOO_MANY_1,    WRONG_NO_1},
    {"remove_least_item",       CC_remove_least_item,TOO_MANY_1,WRONG_NO_1},
    {"nspaces",                 CC_nspaces,     TOO_MANY_1,    WRONG_NO_1},
    {"mk_simpl_map_",           CC_mk_simpl_map_,TOO_MANY_1,   WRONG_NO_1},
    {"mk_dummy_ids",            CC_mk_dummy_ids,TOO_MANY_1,    WRONG_NO_1},
    {"createtriple",            CC_createtriple,TOO_MANY_1,    WRONG_NO_1},
    {"totalcompareconstants",   TOO_FEW_2,      CC_totalcompareconstants,WRONG_NO_2},
    {"gigcdsq",                 TOO_FEW_2,      CC_gigcdsq,    WRONG_NO_2},
    {"simpexpt2",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_simpexpt2},
    {"mk+resimp+mat",           CC_mkLresimpLmat,TOO_MANY_1,   WRONG_NO_1},
    {"talp_invtscsimpl",        CC_talp_invtscsimpl,TOO_MANY_1,WRONG_NO_1},
    {"conditionrd",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_conditionrd},
    {"ieval",                   CC_ieval,       TOO_MANY_1,    WRONG_NO_1},
    {"znumrnil",                CC_znumrnil,    TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u44", (two_args *)"64989 6754151 9191832", 0}
};

// end of generated code
