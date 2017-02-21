
// $destdir/u59.c        Machine generated C code

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



// Code for nrootnn

static LispObject CC_nrootnn(LispObject env,
                         LispObject v_35525, LispObject v_35526)
{
    env = qenv(env);
    LispObject v_35821, v_35822;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_35525,v_35526);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-6] = v_35526;
    stack[-7] = v_35525;
// end of prologue
    stack[-5] = nil;
    v_35821 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_35821;
    v_35821 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_35821;
    goto v_35555;
v_35551:
    v_35822 = stack[-7];
    goto v_35552;
v_35553:
    v_35821 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35554;
v_35555:
    goto v_35551;
v_35552:
    goto v_35553;
v_35554:
    v_35821 = (LispObject)lessp2(v_35822, v_35821);
    v_35821 = v_35821 ? lisp_true : nil;
    env = stack[-9];
    if (v_35821 == nil) goto v_35549;
    v_35821 = stack[-7];
    v_35821 = negate(v_35821);
    env = stack[-9];
    stack[-7] = v_35821;
    v_35821 = stack[-6];
    v_35821 = Levenp(nil, v_35821);
    env = stack[-9];
    if (v_35821 == nil) goto v_35563;
    v_35821 = lisp_true;
    stack[-5] = v_35821;
    goto v_35561;
v_35563:
    v_35821 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[0] = v_35821;
    goto v_35561;
v_35561:
    goto v_35547;
v_35549:
v_35547:
    v_35821 = qvalue(elt(env, 1)); // !*primelist!*
    stack[-8] = v_35821;
v_35538:
    v_35821 = stack[-8];
    v_35821 = qcar(v_35821);
    stack[-1] = v_35821;
    v_35821 = stack[-8];
    v_35821 = qcdr(v_35821);
    stack[-8] = v_35821;
    v_35821 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_35821;
v_35578:
    goto v_35587;
v_35583:
    goto v_35593;
v_35589:
    v_35822 = stack[-7];
    goto v_35590;
v_35591:
    v_35821 = stack[-1];
    goto v_35592;
v_35593:
    goto v_35589;
v_35590:
    goto v_35591;
v_35592:
    v_35821 = Ldivide(nil, v_35822, v_35821);
    env = stack[-9];
    stack[-4] = v_35821;
    v_35822 = qcdr(v_35821);
    goto v_35584;
v_35585:
    v_35821 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35586;
v_35587:
    goto v_35583;
v_35584:
    goto v_35585;
v_35586:
    if (v_35822 == v_35821) goto v_35582;
    goto v_35577;
v_35582:
    v_35821 = stack[-4];
    v_35821 = qcar(v_35821);
    stack[-7] = v_35821;
    v_35821 = stack[-3];
    v_35821 = (LispObject)((intptr_t)(v_35821) + 0x10);
    stack[-3] = v_35821;
    goto v_35578;
v_35577:
    goto v_35611;
v_35607:
    v_35822 = stack[-3];
    goto v_35608;
v_35609:
    v_35821 = stack[-6];
    goto v_35610;
v_35611:
    goto v_35607;
v_35608:
    goto v_35609;
v_35610:
    if (((intptr_t)(v_35822)) < ((intptr_t)(v_35821))) goto v_35606;
    goto v_35619;
v_35615:
    v_35822 = stack[-3];
    goto v_35616;
v_35617:
    v_35821 = stack[-6];
    goto v_35618;
v_35619:
    goto v_35615;
v_35616:
    goto v_35617;
v_35618:
    v_35821 = Ldivide(nil, v_35822, v_35821);
    env = stack[-9];
    stack[-3] = v_35821;
    goto v_35627;
v_35623:
    goto v_35624;
v_35625:
    goto v_35634;
v_35630:
    v_35822 = stack[-1];
    goto v_35631;
v_35632:
    v_35821 = stack[-3];
    v_35821 = qcar(v_35821);
    goto v_35633;
v_35634:
    goto v_35630;
v_35631:
    goto v_35632;
v_35633:
    v_35821 = Lexpt(nil, v_35822, v_35821);
    env = stack[-9];
    goto v_35626;
v_35627:
    goto v_35623;
v_35624:
    goto v_35625;
v_35626:
    v_35821 = times2(stack[0], v_35821);
    env = stack[-9];
    stack[0] = v_35821;
    v_35821 = stack[-3];
    v_35821 = qcdr(v_35821);
    stack[-3] = v_35821;
    goto v_35604;
v_35606:
v_35604:
v_35642:
    goto v_35651;
v_35647:
    v_35822 = stack[-3];
    goto v_35648;
v_35649:
    v_35821 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35650;
v_35651:
    goto v_35647;
v_35648:
    goto v_35649;
v_35650:
    if (((intptr_t)(v_35822)) > ((intptr_t)(v_35821))) goto v_35646;
    goto v_35641;
v_35646:
    goto v_35660;
v_35656:
    v_35822 = stack[-2];
    goto v_35657;
v_35658:
    v_35821 = stack[-1];
    goto v_35659;
v_35660:
    goto v_35656;
v_35657:
    goto v_35658;
v_35659:
    v_35821 = times2(v_35822, v_35821);
    env = stack[-9];
    stack[-2] = v_35821;
    v_35821 = stack[-3];
    v_35821 = (LispObject)((intptr_t)(v_35821) - 0x10);
    stack[-3] = v_35821;
    goto v_35642;
v_35641:
    goto v_35674;
v_35670:
    v_35821 = stack[-4];
    v_35822 = qcar(v_35821);
    goto v_35671;
v_35672:
    v_35821 = stack[-1];
    goto v_35673;
v_35674:
    goto v_35670;
v_35671:
    goto v_35672;
v_35673:
    v_35821 = (LispObject)lessp2(v_35822, v_35821);
    v_35821 = v_35821 ? lisp_true : nil;
    env = stack[-9];
    if (v_35821 == nil) goto v_35668;
    goto v_35683;
v_35679:
    v_35822 = stack[-7];
    goto v_35680;
v_35681:
    v_35821 = stack[-2];
    goto v_35682;
v_35683:
    goto v_35679;
v_35680:
    goto v_35681;
v_35682:
    v_35821 = times2(v_35822, v_35821);
    env = stack[-9];
    stack[-2] = v_35821;
    goto v_35539;
v_35668:
    v_35821 = stack[-8];
    if (v_35821 == nil) goto v_35689;
    goto v_35538;
v_35689:
    goto v_35700;
v_35696:
    goto v_35706;
v_35702:
    v_35822 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_35703;
v_35704:
    v_35821 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_35705;
v_35706:
    goto v_35702;
v_35703:
    goto v_35704;
v_35705:
    v_35822 = Lexpt(nil, v_35822, v_35821);
    env = stack[-9];
    goto v_35697;
v_35698:
    v_35821 = stack[-7];
    goto v_35699;
v_35700:
    goto v_35696;
v_35697:
    goto v_35698;
v_35699:
    v_35821 = (LispObject)greaterp2(v_35822, v_35821);
    v_35821 = v_35821 ? lisp_true : nil;
    env = stack[-9];
    if (v_35821 == nil) goto v_35694;
    goto v_35715;
v_35711:
    v_35822 = stack[-7];
    goto v_35712;
v_35713:
    v_35821 = nil;
    goto v_35714;
v_35715:
    goto v_35711;
v_35712:
    goto v_35713;
v_35714:
    fn = elt(env, 2); // mcfactor!*
    v_35821 = (*qfn2(fn))(fn, v_35822, v_35821);
    env = stack[-9];
    stack[-3] = v_35821;
    v_35821 = stack[-3];
    stack[-4] = v_35821;
v_35721:
    v_35821 = stack[-4];
    if (v_35821 == nil) goto v_35725;
    else goto v_35726;
v_35725:
    goto v_35720;
v_35726:
    v_35821 = stack[-4];
    v_35821 = qcar(v_35821);
    stack[-1] = v_35821;
    goto v_35737;
v_35733:
    v_35821 = stack[-1];
    v_35822 = qcdr(v_35821);
    goto v_35734;
v_35735:
    v_35821 = stack[-6];
    goto v_35736;
v_35737:
    goto v_35733;
v_35734:
    goto v_35735;
v_35736:
    v_35821 = Ldivide(nil, v_35822, v_35821);
    env = stack[-9];
    stack[-3] = v_35821;
    goto v_35746;
v_35742:
    goto v_35752;
v_35748:
    v_35821 = stack[-1];
    v_35822 = qcar(v_35821);
    goto v_35749;
v_35750:
    v_35821 = stack[-3];
    v_35821 = qcar(v_35821);
    goto v_35751;
v_35752:
    goto v_35748;
v_35749:
    goto v_35750;
v_35751:
    v_35822 = Lexpt(nil, v_35822, v_35821);
    env = stack[-9];
    goto v_35743;
v_35744:
    v_35821 = stack[0];
    goto v_35745;
v_35746:
    goto v_35742;
v_35743:
    goto v_35744;
v_35745:
    v_35821 = times2(v_35822, v_35821);
    env = stack[-9];
    stack[0] = v_35821;
    goto v_35763;
v_35759:
    goto v_35769;
v_35765:
    v_35821 = stack[-1];
    v_35822 = qcar(v_35821);
    goto v_35766;
v_35767:
    v_35821 = stack[-3];
    v_35821 = qcdr(v_35821);
    goto v_35768;
v_35769:
    goto v_35765;
v_35766:
    goto v_35767;
v_35768:
    v_35822 = Lexpt(nil, v_35822, v_35821);
    env = stack[-9];
    goto v_35760;
v_35761:
    v_35821 = stack[-2];
    goto v_35762;
v_35763:
    goto v_35759;
v_35760:
    goto v_35761;
v_35762:
    v_35821 = times2(v_35822, v_35821);
    env = stack[-9];
    stack[-2] = v_35821;
    v_35821 = stack[-4];
    v_35821 = qcdr(v_35821);
    stack[-4] = v_35821;
    goto v_35721;
v_35720:
    goto v_35692;
v_35694:
    goto v_35785;
v_35781:
    v_35822 = stack[-7];
    goto v_35782;
v_35783:
    v_35821 = stack[-6];
    goto v_35784;
v_35785:
    goto v_35781;
v_35782:
    goto v_35783;
v_35784:
    fn = elt(env, 3); // iroot
    v_35821 = (*qfn2(fn))(fn, v_35822, v_35821);
    env = stack[-9];
    stack[-3] = v_35821;
    if (v_35821 == nil) goto v_35779;
    goto v_35793;
v_35789:
    v_35822 = stack[0];
    goto v_35790;
v_35791:
    v_35821 = stack[-3];
    goto v_35792;
v_35793:
    goto v_35789;
v_35790:
    goto v_35791;
v_35792:
    v_35821 = times2(v_35822, v_35821);
    env = stack[-9];
    stack[0] = v_35821;
    goto v_35692;
v_35779:
    goto v_35803;
v_35799:
    v_35822 = stack[-7];
    goto v_35800;
v_35801:
    v_35821 = stack[-2];
    goto v_35802;
v_35803:
    goto v_35799;
v_35800:
    goto v_35801;
v_35802:
    v_35821 = times2(v_35822, v_35821);
    env = stack[-9];
    stack[-2] = v_35821;
    goto v_35692;
v_35692:
v_35539:
    v_35821 = stack[-5];
    if (v_35821 == nil) goto v_35809;
    v_35821 = stack[-2];
    v_35821 = negate(v_35821);
    stack[-2] = v_35821;
    goto v_35807;
v_35809:
v_35807:
    goto v_35818;
v_35814:
    v_35822 = stack[0];
    goto v_35815;
v_35816:
    v_35821 = stack[-2];
    goto v_35817;
v_35818:
    goto v_35814;
v_35815:
    goto v_35816;
v_35817:
    return cons(v_35822, v_35821);
    return onevalue(v_35821);
}



// Code for makecoeffpairs1

static LispObject CC_makecoeffpairs1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_35801, v_35802, v_35803, v_35804;
    LispObject fn;
    LispObject v_35528, v_35527, v_35526, v_35525;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "makecoeffpairs1");
    va_start(aa, nargs);
    v_35525 = va_arg(aa, LispObject);
    v_35526 = va_arg(aa, LispObject);
    v_35527 = va_arg(aa, LispObject);
    v_35528 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_35528,v_35527,v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_35525,v_35526,v_35527,v_35528);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(16);
// copy arguments values to proper place
    stack[-10] = v_35528;
    stack[-11] = v_35527;
    stack[-12] = v_35526;
    stack[-13] = v_35525;
// end of prologue
    v_35801 = stack[-12];
    if (v_35801 == nil) goto v_35532;
    else goto v_35533;
v_35532:
    v_35801 = elt(env, 1); // ((nil))
    goto v_35531;
v_35533:
    goto v_35554;
v_35546:
    v_35801 = stack[-13];
    v_35804 = qcdr(v_35801);
    goto v_35547;
v_35548:
    v_35801 = stack[-12];
    v_35803 = qcdr(v_35801);
    goto v_35549;
v_35550:
    v_35801 = stack[-11];
    v_35802 = qcdr(v_35801);
    goto v_35551;
v_35552:
    v_35801 = stack[-10];
    v_35801 = qcdr(v_35801);
    goto v_35553;
v_35554:
    goto v_35546;
v_35547:
    goto v_35548;
v_35549:
    goto v_35550;
v_35551:
    goto v_35552;
v_35553:
    v_35801 = CC_makecoeffpairs1(elt(env, 0), 4, v_35804, v_35803, v_35802, v_35801);
    env = stack[-15];
    stack[-14] = v_35801;
v_35543:
    v_35801 = stack[-14];
    if (v_35801 == nil) goto v_35565;
    else goto v_35566;
v_35565:
    v_35801 = nil;
    goto v_35542;
v_35566:
    v_35801 = stack[-14];
    v_35801 = qcar(v_35801);
    stack[-6] = v_35801;
    goto v_35587;
v_35579:
    v_35801 = stack[-13];
    stack[-2] = qcar(v_35801);
    goto v_35580;
v_35581:
    v_35801 = stack[-12];
    stack[-1] = qcar(v_35801);
    goto v_35582;
v_35583:
    v_35801 = stack[-11];
    stack[0] = qcar(v_35801);
    goto v_35584;
v_35585:
    v_35801 = stack[-10];
    v_35801 = qcar(v_35801);
    fn = elt(env, 2); // tayexp!-minus
    v_35801 = (*qfn1(fn))(fn, v_35801);
    env = stack[-15];
    goto v_35586;
v_35587:
    goto v_35579;
v_35580:
    goto v_35581;
v_35582:
    goto v_35583;
v_35584:
    goto v_35585;
v_35586:
    fn = elt(env, 3); // makecoeffpairshom
    v_35801 = (*qfnn(fn))(fn, 4, stack[-2], stack[-1], stack[0], v_35801);
    env = stack[-15];
    stack[-5] = v_35801;
    v_35801 = stack[-5];
    if (v_35801 == nil) goto v_35599;
    else goto v_35600;
v_35599:
    v_35801 = nil;
    goto v_35576;
v_35600:
    v_35801 = stack[-5];
    v_35801 = qcar(v_35801);
    v_35802 = v_35801;
    goto v_35614;
v_35608:
    v_35801 = v_35802;
    stack[-1] = qcar(v_35801);
    goto v_35609;
v_35610:
    v_35801 = stack[-6];
    stack[0] = qcar(v_35801);
    goto v_35611;
v_35612:
    goto v_35624;
v_35620:
    v_35801 = v_35802;
    v_35802 = qcdr(v_35801);
    goto v_35621;
v_35622:
    v_35801 = stack[-6];
    v_35801 = qcdr(v_35801);
    goto v_35623;
v_35624:
    goto v_35620;
v_35621:
    goto v_35622;
v_35623:
    v_35801 = cons(v_35802, v_35801);
    env = stack[-15];
    goto v_35613;
v_35614:
    goto v_35608;
v_35609:
    goto v_35610;
v_35611:
    goto v_35612;
v_35613:
    v_35801 = acons(stack[-1], stack[0], v_35801);
    env = stack[-15];
    v_35801 = ncons(v_35801);
    env = stack[-15];
    stack[-3] = v_35801;
    stack[-4] = v_35801;
v_35577:
    v_35801 = stack[-5];
    v_35801 = qcdr(v_35801);
    stack[-5] = v_35801;
    v_35801 = stack[-5];
    if (v_35801 == nil) goto v_35633;
    else goto v_35634;
v_35633:
    v_35801 = stack[-4];
    goto v_35576;
v_35634:
    goto v_35642;
v_35638:
    stack[-2] = stack[-3];
    goto v_35639;
v_35640:
    v_35801 = stack[-5];
    v_35801 = qcar(v_35801);
    v_35802 = v_35801;
    goto v_35655;
v_35649:
    v_35801 = v_35802;
    stack[-1] = qcar(v_35801);
    goto v_35650;
v_35651:
    v_35801 = stack[-6];
    stack[0] = qcar(v_35801);
    goto v_35652;
v_35653:
    goto v_35665;
v_35661:
    v_35801 = v_35802;
    v_35802 = qcdr(v_35801);
    goto v_35662;
v_35663:
    v_35801 = stack[-6];
    v_35801 = qcdr(v_35801);
    goto v_35664;
v_35665:
    goto v_35661;
v_35662:
    goto v_35663;
v_35664:
    v_35801 = cons(v_35802, v_35801);
    env = stack[-15];
    goto v_35654;
v_35655:
    goto v_35649;
v_35650:
    goto v_35651;
v_35652:
    goto v_35653;
v_35654:
    v_35801 = acons(stack[-1], stack[0], v_35801);
    env = stack[-15];
    v_35801 = ncons(v_35801);
    env = stack[-15];
    goto v_35641;
v_35642:
    goto v_35638;
v_35639:
    goto v_35640;
v_35641:
    v_35801 = Lrplacd(nil, stack[-2], v_35801);
    env = stack[-15];
    v_35801 = stack[-3];
    v_35801 = qcdr(v_35801);
    stack[-3] = v_35801;
    goto v_35577;
v_35576:
    stack[-9] = v_35801;
    v_35801 = stack[-9];
    fn = elt(env, 4); // lastpair
    v_35801 = (*qfn1(fn))(fn, v_35801);
    env = stack[-15];
    stack[-8] = v_35801;
    v_35801 = stack[-14];
    v_35801 = qcdr(v_35801);
    stack[-14] = v_35801;
    v_35801 = stack[-8];
    if (!consp(v_35801)) goto v_35678;
    else goto v_35679;
v_35678:
    goto v_35543;
v_35679:
v_35544:
    v_35801 = stack[-14];
    if (v_35801 == nil) goto v_35683;
    else goto v_35684;
v_35683:
    v_35801 = stack[-9];
    goto v_35542;
v_35684:
    goto v_35692;
v_35688:
    stack[-7] = stack[-8];
    goto v_35689;
v_35690:
    v_35801 = stack[-14];
    v_35801 = qcar(v_35801);
    stack[-6] = v_35801;
    goto v_35712;
v_35704:
    v_35801 = stack[-13];
    stack[-2] = qcar(v_35801);
    goto v_35705;
v_35706:
    v_35801 = stack[-12];
    stack[-1] = qcar(v_35801);
    goto v_35707;
v_35708:
    v_35801 = stack[-11];
    stack[0] = qcar(v_35801);
    goto v_35709;
v_35710:
    v_35801 = stack[-10];
    v_35801 = qcar(v_35801);
    fn = elt(env, 2); // tayexp!-minus
    v_35801 = (*qfn1(fn))(fn, v_35801);
    env = stack[-15];
    goto v_35711;
v_35712:
    goto v_35704;
v_35705:
    goto v_35706;
v_35707:
    goto v_35708;
v_35709:
    goto v_35710;
v_35711:
    fn = elt(env, 3); // makecoeffpairshom
    v_35801 = (*qfnn(fn))(fn, 4, stack[-2], stack[-1], stack[0], v_35801);
    env = stack[-15];
    stack[-5] = v_35801;
    v_35801 = stack[-5];
    if (v_35801 == nil) goto v_35724;
    else goto v_35725;
v_35724:
    v_35801 = nil;
    goto v_35701;
v_35725:
    v_35801 = stack[-5];
    v_35801 = qcar(v_35801);
    v_35802 = v_35801;
    goto v_35739;
v_35733:
    v_35801 = v_35802;
    stack[-1] = qcar(v_35801);
    goto v_35734;
v_35735:
    v_35801 = stack[-6];
    stack[0] = qcar(v_35801);
    goto v_35736;
v_35737:
    goto v_35749;
v_35745:
    v_35801 = v_35802;
    v_35802 = qcdr(v_35801);
    goto v_35746;
v_35747:
    v_35801 = stack[-6];
    v_35801 = qcdr(v_35801);
    goto v_35748;
v_35749:
    goto v_35745;
v_35746:
    goto v_35747;
v_35748:
    v_35801 = cons(v_35802, v_35801);
    env = stack[-15];
    goto v_35738;
v_35739:
    goto v_35733;
v_35734:
    goto v_35735;
v_35736:
    goto v_35737;
v_35738:
    v_35801 = acons(stack[-1], stack[0], v_35801);
    env = stack[-15];
    v_35801 = ncons(v_35801);
    env = stack[-15];
    stack[-3] = v_35801;
    stack[-4] = v_35801;
v_35702:
    v_35801 = stack[-5];
    v_35801 = qcdr(v_35801);
    stack[-5] = v_35801;
    v_35801 = stack[-5];
    if (v_35801 == nil) goto v_35758;
    else goto v_35759;
v_35758:
    v_35801 = stack[-4];
    goto v_35701;
v_35759:
    goto v_35767;
v_35763:
    stack[-2] = stack[-3];
    goto v_35764;
v_35765:
    v_35801 = stack[-5];
    v_35801 = qcar(v_35801);
    v_35802 = v_35801;
    goto v_35780;
v_35774:
    v_35801 = v_35802;
    stack[-1] = qcar(v_35801);
    goto v_35775;
v_35776:
    v_35801 = stack[-6];
    stack[0] = qcar(v_35801);
    goto v_35777;
v_35778:
    goto v_35790;
v_35786:
    v_35801 = v_35802;
    v_35802 = qcdr(v_35801);
    goto v_35787;
v_35788:
    v_35801 = stack[-6];
    v_35801 = qcdr(v_35801);
    goto v_35789;
v_35790:
    goto v_35786;
v_35787:
    goto v_35788;
v_35789:
    v_35801 = cons(v_35802, v_35801);
    env = stack[-15];
    goto v_35779;
v_35780:
    goto v_35774;
v_35775:
    goto v_35776;
v_35777:
    goto v_35778;
v_35779:
    v_35801 = acons(stack[-1], stack[0], v_35801);
    env = stack[-15];
    v_35801 = ncons(v_35801);
    env = stack[-15];
    goto v_35766;
v_35767:
    goto v_35763;
v_35764:
    goto v_35765;
v_35766:
    v_35801 = Lrplacd(nil, stack[-2], v_35801);
    env = stack[-15];
    v_35801 = stack[-3];
    v_35801 = qcdr(v_35801);
    stack[-3] = v_35801;
    goto v_35702;
v_35701:
    goto v_35691;
v_35692:
    goto v_35688;
v_35689:
    goto v_35690;
v_35691:
    v_35801 = Lrplacd(nil, stack[-7], v_35801);
    env = stack[-15];
    v_35801 = stack[-8];
    fn = elt(env, 4); // lastpair
    v_35801 = (*qfn1(fn))(fn, v_35801);
    env = stack[-15];
    stack[-8] = v_35801;
    v_35801 = stack[-14];
    v_35801 = qcdr(v_35801);
    stack[-14] = v_35801;
    goto v_35544;
v_35542:
    goto v_35531;
    v_35801 = nil;
v_35531:
    return onevalue(v_35801);
}



// Code for null!+vec!+p

static LispObject CC_nullLvecLp(LispObject env,
                         LispObject v_35525)
{
    env = qenv(env);
    LispObject v_35537;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35525);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_35537 = v_35525;
// end of prologue
    fn = elt(env, 1); // mk!+squared!+norm
    v_35537 = (*qfn1(fn))(fn, v_35537);
    env = stack[0];
    fn = elt(env, 2); // my!+nullsq!+p
    v_35537 = (*qfn1(fn))(fn, v_35537);
    if (v_35537 == nil) goto v_35532;
    v_35537 = lisp_true;
    goto v_35528;
v_35532:
    v_35537 = nil;
v_35528:
    return onevalue(v_35537);
}



// Code for talp_get!-minfct

static LispObject CC_talp_getKminfct(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_35640, v_35641, v_35642;
    LispObject fn;
    LispObject v_35528, v_35527, v_35526, v_35525;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "talp_get-minfct");
    va_start(aa, nargs);
    v_35525 = va_arg(aa, LispObject);
    v_35526 = va_arg(aa, LispObject);
    v_35527 = va_arg(aa, LispObject);
    v_35528 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_35528,v_35527,v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_35525,v_35526,v_35527,v_35528);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_35528;
    stack[0] = v_35527;
    v_35641 = v_35526;
    v_35640 = v_35525;
// end of prologue
    goto v_35534;
v_35530:
    goto v_35531;
v_35532:
    goto v_35533;
v_35534:
    goto v_35530;
v_35531:
    goto v_35532;
v_35533:
    v_35640 = *(LispObject *)((char *)v_35641 + (CELL-TAG_VECTOR) + (((intptr_t)v_35640-TAG_FIXNUM)/(16/CELL)));
    stack[-6] = v_35640;
    v_35640 = stack[-6];
    fn = elt(env, 1); // talp_invp
    v_35640 = (*qfn1(fn))(fn, v_35640);
    env = stack[-7];
    if (v_35640 == nil) goto v_35542;
    goto v_35552;
v_35546:
    v_35640 = stack[-6];
    fn = elt(env, 2); // talp_fop
    v_35642 = (*qfn1(fn))(fn, v_35640);
    goto v_35547;
v_35548:
    goto v_35559;
v_35555:
    v_35641 = stack[0];
    goto v_35556;
v_35557:
    v_35640 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35558;
v_35559:
    goto v_35555;
v_35556:
    goto v_35557;
v_35558:
    v_35641 = *(LispObject *)((char *)v_35641 + (CELL-TAG_VECTOR) + (((intptr_t)v_35640-TAG_FIXNUM)/(16/CELL)));
    goto v_35549;
v_35550:
    v_35640 = nil;
    goto v_35551;
v_35552:
    goto v_35546;
v_35547:
    goto v_35548;
v_35549:
    goto v_35550;
v_35551:
    return list2star(v_35642, v_35641, v_35640);
v_35542:
    goto v_35571;
v_35567:
    v_35640 = stack[-6];
    fn = elt(env, 2); // talp_fop
    stack[-4] = (*qfn1(fn))(fn, v_35640);
    env = stack[-7];
    goto v_35568;
v_35569:
    v_35640 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_35640;
    goto v_35591;
v_35587:
    v_35640 = stack[-6];
    v_35641 = qcdr(v_35640);
    goto v_35588;
v_35589:
    v_35640 = stack[-3];
    goto v_35590;
v_35591:
    goto v_35587;
v_35588:
    goto v_35589;
v_35590:
    v_35640 = difference2(v_35641, v_35640);
    env = stack[-7];
    v_35640 = Lminusp(nil, v_35640);
    env = stack[-7];
    if (v_35640 == nil) goto v_35584;
    v_35640 = nil;
    goto v_35578;
v_35584:
    goto v_35601;
v_35597:
    v_35641 = stack[-5];
    goto v_35598;
v_35599:
    v_35640 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35600;
v_35601:
    goto v_35597;
v_35598:
    goto v_35599;
v_35600:
    v_35640 = *(LispObject *)((char *)v_35641 + (CELL-TAG_VECTOR) + (((intptr_t)v_35640-TAG_FIXNUM)/(16/CELL)));
    v_35640 = ncons(v_35640);
    env = stack[-7];
    stack[-1] = v_35640;
    stack[-2] = v_35640;
v_35579:
    v_35640 = stack[-3];
    v_35640 = add1(v_35640);
    env = stack[-7];
    stack[-3] = v_35640;
    goto v_35617;
v_35613:
    v_35640 = stack[-6];
    v_35641 = qcdr(v_35640);
    goto v_35614;
v_35615:
    v_35640 = stack[-3];
    goto v_35616;
v_35617:
    goto v_35613;
v_35614:
    goto v_35615;
v_35616:
    v_35640 = difference2(v_35641, v_35640);
    env = stack[-7];
    v_35640 = Lminusp(nil, v_35640);
    env = stack[-7];
    if (v_35640 == nil) goto v_35610;
    v_35640 = stack[-2];
    goto v_35578;
v_35610:
    goto v_35627;
v_35623:
    stack[0] = stack[-1];
    goto v_35624;
v_35625:
    goto v_35634;
v_35630:
    v_35641 = stack[-5];
    goto v_35631;
v_35632:
    v_35640 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35633;
v_35634:
    goto v_35630;
v_35631:
    goto v_35632;
v_35633:
    v_35640 = *(LispObject *)((char *)v_35641 + (CELL-TAG_VECTOR) + (((intptr_t)v_35640-TAG_FIXNUM)/(16/CELL)));
    v_35640 = ncons(v_35640);
    env = stack[-7];
    goto v_35626;
v_35627:
    goto v_35623;
v_35624:
    goto v_35625;
v_35626:
    v_35640 = Lrplacd(nil, stack[0], v_35640);
    env = stack[-7];
    v_35640 = stack[-1];
    v_35640 = qcdr(v_35640);
    stack[-1] = v_35640;
    goto v_35579;
v_35578:
    goto v_35570;
v_35571:
    goto v_35567;
v_35568:
    goto v_35569;
v_35570:
    {
        LispObject v_35650 = stack[-4];
        fn = elt(env, 3); // talp_mktn
        return (*qfn2(fn))(fn, v_35650, v_35640);
    }
    v_35640 = nil;
    return onevalue(v_35640);
}



// Code for rl_b2atl

static LispObject CC_rl_b2atl(LispObject env,
                         LispObject v_35525, LispObject v_35526)
{
    env = qenv(env);
    LispObject v_35543, v_35544;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_35525,v_35526);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_35543 = v_35526;
    v_35544 = v_35525;
// end of prologue
    goto v_35533;
v_35529:
    stack[0] = qvalue(elt(env, 1)); // rl_b2atl!*
    goto v_35530;
v_35531:
    goto v_35540;
v_35536:
    goto v_35537;
v_35538:
    goto v_35539;
v_35540:
    goto v_35536;
v_35537:
    goto v_35538;
v_35539:
    v_35543 = list2(v_35544, v_35543);
    env = stack[-1];
    goto v_35532;
v_35533:
    goto v_35529;
v_35530:
    goto v_35531;
v_35532:
    {
        LispObject v_35546 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_35546, v_35543);
    }
}



// Code for ps!:expt!-erule

static LispObject CC_psTexptKerule(LispObject env,
                         LispObject v_35525, LispObject v_35526)
{
    env = qenv(env);
    LispObject v_35787, v_35788, v_35789;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_35525,v_35526);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_35526;
    v_35788 = v_35525;
// end of prologue
    v_35787 = v_35788;
    v_35787 = qcdr(v_35787);
    v_35787 = qcar(v_35787);
    stack[-10] = v_35787;
    v_35787 = v_35788;
    v_35787 = qcdr(v_35787);
    v_35787 = qcdr(v_35787);
    v_35787 = qcar(v_35787);
    stack[-6] = v_35787;
    v_35787 = v_35788;
    v_35787 = qcdr(v_35787);
    v_35787 = qcdr(v_35787);
    v_35787 = qcdr(v_35787);
    v_35787 = qcar(v_35787);
    stack[-5] = v_35787;
    v_35787 = stack[-10];
    fn = elt(env, 3); // ps!:order
    v_35787 = (*qfn1(fn))(fn, v_35787);
    env = stack[-11];
    stack[-8] = v_35787;
    v_35787 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 3); // ps!:order
    v_35787 = (*qfn1(fn))(fn, v_35787);
    env = stack[-11];
    stack[-7] = v_35787;
    goto v_35560;
v_35556:
    v_35788 = stack[-9];
    goto v_35557;
v_35558:
    v_35787 = stack[-7];
    goto v_35559;
v_35560:
    goto v_35556;
v_35557:
    goto v_35558;
v_35559:
    if (equal(v_35788, v_35787)) goto v_35554;
    else goto v_35555;
v_35554:
    goto v_35571;
v_35567:
    v_35788 = stack[-5];
    goto v_35568;
v_35569:
    v_35787 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35570;
v_35571:
    goto v_35567;
v_35568:
    goto v_35569;
v_35570:
    if (v_35788 == v_35787) goto v_35565;
    else goto v_35566;
v_35565:
    v_35787 = stack[-6];
    stack[0] = v_35787;
    goto v_35564;
v_35566:
    goto v_35584;
v_35578:
    v_35789 = elt(env, 2); // quotient
    goto v_35579;
v_35580:
    v_35788 = stack[-6];
    goto v_35581;
v_35582:
    v_35787 = stack[-5];
    goto v_35583;
v_35584:
    goto v_35578;
v_35579:
    goto v_35580;
v_35581:
    goto v_35582;
v_35583:
    v_35787 = list3(v_35789, v_35788, v_35787);
    env = stack[-11];
    stack[0] = v_35787;
    goto v_35564;
v_35564:
    goto v_35594;
v_35590:
    goto v_35601;
v_35597:
    v_35788 = stack[-10];
    goto v_35598;
v_35599:
    v_35787 = stack[-8];
    goto v_35600;
v_35601:
    goto v_35597;
v_35598:
    goto v_35599;
v_35600:
    fn = elt(env, 4); // ps!:evaluate
    v_35787 = (*qfn2(fn))(fn, v_35788, v_35787);
    env = stack[-11];
    fn = elt(env, 5); // prepsqxx
    v_35788 = (*qfn1(fn))(fn, v_35787);
    env = stack[-11];
    goto v_35591;
v_35592:
    v_35787 = stack[0];
    goto v_35593;
v_35594:
    goto v_35590;
v_35591:
    goto v_35592;
v_35593:
    v_35787 = list2(v_35788, v_35787);
    env = stack[-11];
    {
        fn = elt(env, 6); // simpexpt
        return (*qfn1(fn))(fn, v_35787);
    }
v_35555:
    goto v_35612;
v_35608:
    v_35788 = nil;
    goto v_35609;
v_35610:
    v_35787 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35611;
v_35612:
    goto v_35608;
v_35609:
    goto v_35610;
v_35611:
    v_35787 = cons(v_35788, v_35787);
    env = stack[-11];
    stack[0] = v_35787;
    v_35787 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_35787;
v_35618:
    goto v_35630;
v_35626:
    goto v_35636;
v_35632:
    v_35788 = stack[-9];
    goto v_35633;
v_35634:
    v_35787 = stack[-7];
    goto v_35635;
v_35636:
    goto v_35632;
v_35633:
    goto v_35634;
v_35635:
    v_35788 = difference2(v_35788, v_35787);
    env = stack[-11];
    goto v_35627;
v_35628:
    v_35787 = stack[-4];
    goto v_35629;
v_35630:
    goto v_35626;
v_35627:
    goto v_35628;
v_35629:
    v_35787 = difference2(v_35788, v_35787);
    env = stack[-11];
    v_35787 = Lminusp(nil, v_35787);
    env = stack[-11];
    if (v_35787 == nil) goto v_35623;
    goto v_35617;
v_35623:
    goto v_35646;
v_35642:
    stack[-3] = stack[0];
    goto v_35643;
v_35644:
    goto v_35653;
v_35649:
    goto v_35659;
v_35655:
    goto v_35665;
v_35661:
    goto v_35671;
v_35667:
    v_35788 = stack[-4];
    goto v_35668;
v_35669:
    v_35787 = stack[-6];
    goto v_35670;
v_35671:
    goto v_35667;
v_35668:
    goto v_35669;
v_35670:
    stack[-1] = times2(v_35788, v_35787);
    env = stack[-11];
    goto v_35662;
v_35663:
    goto v_35679;
v_35675:
    stack[0] = stack[-5];
    goto v_35676;
v_35677:
    goto v_35686;
v_35682:
    goto v_35692;
v_35688:
    v_35788 = stack[-4];
    goto v_35689;
v_35690:
    v_35787 = stack[-9];
    goto v_35691;
v_35692:
    goto v_35688;
v_35689:
    goto v_35690;
v_35691:
    v_35788 = difference2(v_35788, v_35787);
    env = stack[-11];
    goto v_35683;
v_35684:
    v_35787 = stack[-7];
    goto v_35685;
v_35686:
    goto v_35682;
v_35683:
    goto v_35684;
v_35685:
    v_35787 = plus2(v_35788, v_35787);
    env = stack[-11];
    goto v_35678;
v_35679:
    goto v_35675;
v_35676:
    goto v_35677;
v_35678:
    v_35787 = times2(stack[0], v_35787);
    env = stack[-11];
    goto v_35664;
v_35665:
    goto v_35661;
v_35662:
    goto v_35663;
v_35664:
    v_35787 = plus2(stack[-1], v_35787);
    env = stack[-11];
    v_35789 = v_35787;
    goto v_35705;
v_35701:
    v_35788 = v_35789;
    goto v_35702;
v_35703:
    v_35787 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35704;
v_35705:
    goto v_35701;
v_35702:
    goto v_35703;
v_35704:
    if (v_35788 == v_35787) goto v_35699;
    else goto v_35700;
v_35699:
    v_35787 = nil;
    v_35788 = v_35787;
    goto v_35698;
v_35700:
    v_35787 = v_35789;
    v_35788 = v_35787;
    goto v_35698;
    v_35788 = nil;
v_35698:
    goto v_35656;
v_35657:
    v_35787 = stack[-5];
    goto v_35658;
v_35659:
    goto v_35655;
v_35656:
    goto v_35657;
v_35658:
    stack[-2] = cons(v_35788, v_35787);
    env = stack[-11];
    goto v_35650;
v_35651:
    goto v_35718;
v_35714:
    goto v_35724;
v_35720:
    stack[0] = stack[-10];
    goto v_35721;
v_35722:
    goto v_35731;
v_35727:
    v_35788 = stack[-4];
    goto v_35728;
v_35729:
    v_35787 = stack[-8];
    goto v_35730;
v_35731:
    goto v_35727;
v_35728:
    goto v_35729;
v_35730:
    v_35787 = plus2(v_35788, v_35787);
    env = stack[-11];
    goto v_35723;
v_35724:
    goto v_35720;
v_35721:
    goto v_35722;
v_35723:
    fn = elt(env, 4); // ps!:evaluate
    stack[-1] = (*qfn2(fn))(fn, stack[0], v_35787);
    env = stack[-11];
    goto v_35715;
v_35716:
    goto v_35739;
v_35735:
    stack[0] = qvalue(elt(env, 1)); // ps
    goto v_35736;
v_35737:
    goto v_35746;
v_35742:
    v_35788 = stack[-9];
    goto v_35743;
v_35744:
    v_35787 = stack[-4];
    goto v_35745;
v_35746:
    goto v_35742;
v_35743:
    goto v_35744;
v_35745:
    v_35787 = difference2(v_35788, v_35787);
    env = stack[-11];
    goto v_35738;
v_35739:
    goto v_35735;
v_35736:
    goto v_35737;
v_35738:
    fn = elt(env, 4); // ps!:evaluate
    v_35787 = (*qfn2(fn))(fn, stack[0], v_35787);
    env = stack[-11];
    goto v_35717;
v_35718:
    goto v_35714;
v_35715:
    goto v_35716;
v_35717:
    fn = elt(env, 7); // multsq
    v_35787 = (*qfn2(fn))(fn, stack[-1], v_35787);
    env = stack[-11];
    goto v_35652;
v_35653:
    goto v_35649;
v_35650:
    goto v_35651;
v_35652:
    fn = elt(env, 7); // multsq
    v_35787 = (*qfn2(fn))(fn, stack[-2], v_35787);
    env = stack[-11];
    goto v_35645;
v_35646:
    goto v_35642;
v_35643:
    goto v_35644;
v_35645:
    fn = elt(env, 8); // addsq
    v_35787 = (*qfn2(fn))(fn, stack[-3], v_35787);
    env = stack[-11];
    stack[0] = v_35787;
    v_35787 = stack[-4];
    v_35787 = add1(v_35787);
    env = stack[-11];
    stack[-4] = v_35787;
    goto v_35618;
v_35617:
    goto v_35756;
v_35752:
    goto v_35753;
v_35754:
    goto v_35763;
v_35759:
    goto v_35769;
v_35765:
    goto v_35775;
v_35771:
    v_35788 = stack[-9];
    goto v_35772;
v_35773:
    v_35787 = stack[-7];
    goto v_35774;
v_35775:
    goto v_35771;
v_35772:
    goto v_35773;
v_35774:
    v_35788 = difference2(v_35788, v_35787);
    env = stack[-11];
    goto v_35766;
v_35767:
    v_35787 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35768;
v_35769:
    goto v_35765;
v_35766:
    goto v_35767;
v_35768:
    stack[-1] = cons(v_35788, v_35787);
    env = stack[-11];
    goto v_35760;
v_35761:
    goto v_35784;
v_35780:
    v_35788 = stack[-10];
    goto v_35781;
v_35782:
    v_35787 = stack[-8];
    goto v_35783;
v_35784:
    goto v_35780;
v_35781:
    goto v_35782;
v_35783:
    fn = elt(env, 4); // ps!:evaluate
    v_35787 = (*qfn2(fn))(fn, v_35788, v_35787);
    env = stack[-11];
    goto v_35762;
v_35763:
    goto v_35759;
v_35760:
    goto v_35761;
v_35762:
    fn = elt(env, 7); // multsq
    v_35787 = (*qfn2(fn))(fn, stack[-1], v_35787);
    env = stack[-11];
    goto v_35755;
v_35756:
    goto v_35752;
v_35753:
    goto v_35754;
v_35755:
    {
        LispObject v_35801 = stack[0];
        fn = elt(env, 9); // quotsq
        return (*qfn2(fn))(fn, v_35801, v_35787);
    }
    v_35787 = nil;
    return onevalue(v_35787);
}



// Code for frlp

static LispObject CC_frlp(LispObject env,
                         LispObject v_35525)
{
    env = qenv(env);
    LispObject v_35554, v_35555, v_35556;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_35555 = v_35525;
// end of prologue
v_35524:
    v_35554 = v_35555;
    if (v_35554 == nil) goto v_35529;
    else goto v_35530;
v_35529:
    v_35554 = lisp_true;
    goto v_35528;
v_35530:
    goto v_35543;
v_35539:
    v_35554 = v_35555;
    v_35556 = qcar(v_35554);
    goto v_35540;
v_35541:
    v_35554 = qvalue(elt(env, 1)); // frlis!*
    goto v_35542;
v_35543:
    goto v_35539;
v_35540:
    goto v_35541;
v_35542:
    v_35554 = Lmemq(nil, v_35556, v_35554);
    if (v_35554 == nil) goto v_35537;
    else goto v_35538;
v_35537:
    v_35554 = nil;
    goto v_35536;
v_35538:
    v_35554 = v_35555;
    v_35554 = qcdr(v_35554);
    v_35555 = v_35554;
    goto v_35524;
    v_35554 = nil;
v_35536:
    goto v_35528;
    v_35554 = nil;
v_35528:
    return onevalue(v_35554);
}



// Code for dm!-quotient

static LispObject CC_dmKquotient(LispObject env,
                         LispObject v_35525, LispObject v_35526)
{
    env = qenv(env);
    LispObject v_35554, v_35555;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_35525,v_35526);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_35526;
    v_35555 = v_35525;
// end of prologue
    v_35554 = nil;
    qvalue(elt(env, 1)) = v_35554; // !*noequiv
    goto v_35538;
v_35534:
    v_35554 = v_35555;
    fn = elt(env, 2); // dm!-mkfloat
    stack[-1] = (*qfn1(fn))(fn, v_35554);
    env = stack[-2];
    goto v_35535;
v_35536:
    v_35554 = stack[0];
    fn = elt(env, 2); // dm!-mkfloat
    v_35554 = (*qfn1(fn))(fn, v_35554);
    env = stack[-2];
    goto v_35537;
v_35538:
    goto v_35534;
v_35535:
    goto v_35536;
v_35537:
    fn = elt(env, 3); // !:quotient
    v_35554 = (*qfn2(fn))(fn, stack[-1], v_35554);
    v_35555 = v_35554;
    v_35554 = v_35555;
    if (v_35554 == nil) goto v_35546;
    else goto v_35547;
v_35546:
    v_35554 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35545;
v_35547:
    v_35554 = v_35555;
    goto v_35545;
    v_35554 = nil;
v_35545:
    return onevalue(v_35554);
}



// Code for groebsaveltermbc

static LispObject CC_groebsaveltermbc(LispObject env,
                         LispObject v_35525)
{
    env = qenv(env);
    LispObject v_35588, v_35589, v_35590;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35525);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_35525;
// end of prologue
    v_35588 = stack[0];
    fn = elt(env, 2); // vbc2a
    v_35588 = (*qfn1(fn))(fn, v_35588);
    env = stack[-2];
    stack[0] = v_35588;
    v_35588 = stack[0];
    if (is_number(v_35588)) goto v_35536;
    v_35588 = stack[0];
    fn = elt(env, 3); // constant_exprp
    v_35588 = (*qfn1(fn))(fn, v_35588);
    env = stack[-2];
    v_35588 = (v_35588 == nil ? lisp_true : nil);
    goto v_35534;
v_35536:
    v_35588 = nil;
    goto v_35534;
    v_35588 = nil;
v_35534:
    if (v_35588 == nil) goto v_35532;
    v_35588 = stack[0];
    fn = elt(env, 4); // simp
    v_35588 = (*qfn1(fn))(fn, v_35588);
    env = stack[-2];
    v_35588 = qcar(v_35588);
    fn = elt(env, 5); // fctrf
    v_35588 = (*qfn1(fn))(fn, v_35588);
    env = stack[-2];
    v_35588 = qcdr(v_35588);
    stack[-1] = v_35588;
v_35547:
    v_35588 = stack[-1];
    if (v_35588 == nil) goto v_35555;
    else goto v_35556;
v_35555:
    v_35588 = nil;
    goto v_35546;
v_35556:
    v_35588 = stack[-1];
    v_35588 = qcar(v_35588);
    v_35590 = v_35588;
    v_35588 = v_35590;
    v_35588 = qcar(v_35588);
    fn = elt(env, 6); // prepf
    v_35588 = (*qfn1(fn))(fn, v_35588);
    env = stack[-2];
    v_35590 = v_35588;
    goto v_35573;
v_35569:
    v_35589 = v_35590;
    goto v_35570;
v_35571:
    v_35588 = qvalue(elt(env, 1)); // glterms
    goto v_35572;
v_35573:
    goto v_35569;
v_35570:
    goto v_35571;
v_35572:
    v_35588 = Lmember(nil, v_35589, v_35588);
    if (v_35588 == nil) goto v_35567;
    else goto v_35568;
v_35567:
    goto v_35582;
v_35578:
    stack[0] = qvalue(elt(env, 1)); // glterms
    goto v_35579;
v_35580:
    v_35588 = v_35590;
    v_35588 = ncons(v_35588);
    env = stack[-2];
    goto v_35581;
v_35582:
    goto v_35578;
v_35579:
    goto v_35580;
v_35581:
    v_35588 = Lnconc(nil, stack[0], v_35588);
    env = stack[-2];
    goto v_35566;
v_35568:
v_35566:
    v_35588 = stack[-1];
    v_35588 = qcdr(v_35588);
    stack[-1] = v_35588;
    goto v_35547;
v_35546:
    goto v_35530;
v_35532:
    v_35588 = nil;
v_35530:
    return onevalue(v_35588);
}



// Code for rand!-mons!-dense

static LispObject CC_randKmonsKdense(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_35908, v_35909, v_35910;
    LispObject fn;
    LispObject v_35528, v_35527, v_35526;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "rand-mons-dense");
    va_start(aa, nargs);
    v_35526 = va_arg(aa, LispObject);
    v_35527 = va_arg(aa, LispObject);
    v_35528 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_35528,v_35527,v_35526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_35526,v_35527,v_35528);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(15);
// copy arguments values to proper place
    stack[-11] = v_35528;
    v_35908 = v_35527;
    stack[-12] = v_35526;
// end of prologue
// Binding d
// FLUIDBIND: reloadenv=14 litvec-offset=1 saveloc=13
{   bind_fluid_stack bind_fluid_var(-14, 1, -13);
    qvalue(elt(env, 1)) = v_35908; // d
    v_35908 = stack[-12];
    v_35908 = qcar(v_35908);
    stack[-10] = v_35908;
    v_35908 = stack[-12];
    v_35908 = qcdr(v_35908);
    stack[-12] = v_35908;
    v_35908 = stack[-12];
    if (v_35908 == nil) goto v_35543;
    else goto v_35544;
v_35543:
    goto v_35551;
v_35547:
    goto v_35561;
v_35557:
    v_35909 = stack[-11];
    goto v_35558;
v_35559:
    v_35908 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35560;
v_35561:
    goto v_35557;
v_35558:
    goto v_35559;
v_35560:
    v_35908 = (LispObject)greaterp2(v_35909, v_35908);
    v_35908 = v_35908 ? lisp_true : nil;
    env = stack[-14];
    if (v_35908 == nil) goto v_35555;
    goto v_35569;
v_35565:
    v_35909 = stack[-10];
    goto v_35566;
v_35567:
    v_35908 = stack[-11];
    goto v_35568;
v_35569:
    goto v_35565;
v_35566:
    goto v_35567;
v_35568:
    fn = elt(env, 2); // mksq
    v_35908 = (*qfn2(fn))(fn, v_35909, v_35908);
    env = stack[-14];
    v_35908 = qcar(v_35908);
    stack[-3] = v_35908;
    goto v_35553;
v_35555:
    v_35908 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_35908;
    goto v_35553;
    stack[-3] = nil;
v_35553:
    goto v_35548;
v_35549:
    v_35908 = stack[-11];
    v_35908 = add1(v_35908);
    env = stack[-14];
    stack[-4] = v_35908;
    goto v_35594;
v_35590:
    v_35909 = qvalue(elt(env, 1)); // d
    goto v_35591;
v_35592:
    v_35908 = stack[-4];
    goto v_35593;
v_35594:
    goto v_35590;
v_35591:
    goto v_35592;
v_35593:
    v_35908 = difference2(v_35909, v_35908);
    env = stack[-14];
    v_35908 = Lminusp(nil, v_35908);
    env = stack[-14];
    if (v_35908 == nil) goto v_35587;
    v_35908 = nil;
    goto v_35580;
v_35587:
    goto v_35604;
v_35600:
    v_35909 = stack[-10];
    goto v_35601;
v_35602:
    v_35908 = stack[-4];
    goto v_35603;
v_35604:
    goto v_35600;
v_35601:
    goto v_35602;
v_35603:
    fn = elt(env, 2); // mksq
    v_35908 = (*qfn2(fn))(fn, v_35909, v_35908);
    env = stack[-14];
    v_35908 = qcar(v_35908);
    v_35908 = ncons(v_35908);
    env = stack[-14];
    stack[-1] = v_35908;
    stack[-2] = v_35908;
v_35581:
    v_35908 = stack[-4];
    v_35908 = add1(v_35908);
    env = stack[-14];
    stack[-4] = v_35908;
    goto v_35620;
v_35616:
    v_35909 = qvalue(elt(env, 1)); // d
    goto v_35617;
v_35618:
    v_35908 = stack[-4];
    goto v_35619;
v_35620:
    goto v_35616;
v_35617:
    goto v_35618;
v_35619:
    v_35908 = difference2(v_35909, v_35908);
    env = stack[-14];
    v_35908 = Lminusp(nil, v_35908);
    env = stack[-14];
    if (v_35908 == nil) goto v_35613;
    v_35908 = stack[-2];
    goto v_35580;
v_35613:
    goto v_35629;
v_35625:
    stack[0] = stack[-1];
    goto v_35626;
v_35627:
    goto v_35637;
v_35633:
    v_35909 = stack[-10];
    goto v_35634;
v_35635:
    v_35908 = stack[-4];
    goto v_35636;
v_35637:
    goto v_35633;
v_35634:
    goto v_35635;
v_35636:
    fn = elt(env, 2); // mksq
    v_35908 = (*qfn2(fn))(fn, v_35909, v_35908);
    env = stack[-14];
    v_35908 = qcar(v_35908);
    v_35908 = ncons(v_35908);
    env = stack[-14];
    goto v_35628;
v_35629:
    goto v_35625;
v_35626:
    goto v_35627;
v_35628:
    v_35908 = Lrplacd(nil, stack[0], v_35908);
    env = stack[-14];
    v_35908 = stack[-1];
    v_35908 = qcdr(v_35908);
    stack[-1] = v_35908;
    goto v_35581;
v_35580:
    goto v_35550;
v_35551:
    goto v_35547;
v_35548:
    goto v_35549;
v_35550:
    v_35908 = cons(stack[-3], v_35908);
    goto v_35542;
v_35544:
    goto v_35650;
v_35646:
    goto v_35658;
v_35652:
    v_35910 = stack[-12];
    goto v_35653;
v_35654:
    v_35909 = qvalue(elt(env, 1)); // d
    goto v_35655;
v_35656:
    v_35908 = stack[-11];
    goto v_35657;
v_35658:
    goto v_35652;
v_35653:
    goto v_35654;
v_35655:
    goto v_35656;
v_35657:
    stack[-9] = CC_randKmonsKdense(elt(env, 0), 3, v_35910, v_35909, v_35908);
    env = stack[-14];
    goto v_35647;
v_35648:
    v_35908 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_35908;
v_35667:
    goto v_35680;
v_35676:
    v_35909 = qvalue(elt(env, 1)); // d
    goto v_35677;
v_35678:
    v_35908 = stack[-8];
    goto v_35679;
v_35680:
    goto v_35676;
v_35677:
    goto v_35678;
v_35679:
    v_35908 = difference2(v_35909, v_35908);
    env = stack[-14];
    v_35908 = Lminusp(nil, v_35908);
    env = stack[-14];
    if (v_35908 == nil) goto v_35673;
    v_35908 = nil;
    goto v_35666;
v_35673:
    goto v_35689;
v_35685:
    v_35909 = stack[-10];
    goto v_35686;
v_35687:
    v_35908 = stack[-8];
    goto v_35688;
v_35689:
    goto v_35685;
v_35686:
    goto v_35687;
v_35688:
    fn = elt(env, 2); // mksq
    v_35908 = (*qfn2(fn))(fn, v_35909, v_35908);
    env = stack[-14];
    v_35908 = qcar(v_35908);
    stack[-4] = v_35908;
    goto v_35707;
v_35701:
    stack[-2] = stack[-12];
    goto v_35702;
v_35703:
    goto v_35714;
v_35710:
    v_35909 = qvalue(elt(env, 1)); // d
    goto v_35711;
v_35712:
    v_35908 = stack[-8];
    goto v_35713;
v_35714:
    goto v_35710;
v_35711:
    goto v_35712;
v_35713:
    stack[-1] = difference2(v_35909, v_35908);
    env = stack[-14];
    goto v_35704;
v_35705:
    goto v_35722;
v_35718:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35719;
v_35720:
    goto v_35729;
v_35725:
    v_35909 = stack[-11];
    goto v_35726;
v_35727:
    v_35908 = stack[-8];
    goto v_35728;
v_35729:
    goto v_35725;
v_35726:
    goto v_35727;
v_35728:
    v_35908 = difference2(v_35909, v_35908);
    env = stack[-14];
    goto v_35721;
v_35722:
    goto v_35718;
v_35719:
    goto v_35720;
v_35721:
    fn = elt(env, 3); // max
    v_35908 = (*qfn2(fn))(fn, stack[0], v_35908);
    env = stack[-14];
    goto v_35706;
v_35707:
    goto v_35701;
v_35702:
    goto v_35703;
v_35704:
    goto v_35705;
v_35706:
    v_35908 = CC_randKmonsKdense(elt(env, 0), 3, stack[-2], stack[-1], v_35908);
    env = stack[-14];
    stack[-3] = v_35908;
    v_35908 = stack[-3];
    if (v_35908 == nil) goto v_35734;
    else goto v_35735;
v_35734:
    v_35908 = nil;
    goto v_35698;
v_35735:
    v_35908 = stack[-3];
    v_35908 = qcar(v_35908);
    goto v_35747;
v_35743:
    v_35909 = stack[-4];
    goto v_35744;
v_35745:
    goto v_35746;
v_35747:
    goto v_35743;
v_35744:
    goto v_35745;
v_35746:
    fn = elt(env, 4); // multf
    v_35908 = (*qfn2(fn))(fn, v_35909, v_35908);
    env = stack[-14];
    v_35908 = ncons(v_35908);
    env = stack[-14];
    stack[-1] = v_35908;
    stack[-2] = v_35908;
v_35699:
    v_35908 = stack[-3];
    v_35908 = qcdr(v_35908);
    stack[-3] = v_35908;
    v_35908 = stack[-3];
    if (v_35908 == nil) goto v_35754;
    else goto v_35755;
v_35754:
    v_35908 = stack[-2];
    goto v_35698;
v_35755:
    goto v_35763;
v_35759:
    stack[0] = stack[-1];
    goto v_35760;
v_35761:
    v_35908 = stack[-3];
    v_35908 = qcar(v_35908);
    goto v_35774;
v_35770:
    v_35909 = stack[-4];
    goto v_35771;
v_35772:
    goto v_35773;
v_35774:
    goto v_35770;
v_35771:
    goto v_35772;
v_35773:
    fn = elt(env, 4); // multf
    v_35908 = (*qfn2(fn))(fn, v_35909, v_35908);
    env = stack[-14];
    v_35908 = ncons(v_35908);
    env = stack[-14];
    goto v_35762;
v_35763:
    goto v_35759;
v_35760:
    goto v_35761;
v_35762:
    v_35908 = Lrplacd(nil, stack[0], v_35908);
    env = stack[-14];
    v_35908 = stack[-1];
    v_35908 = qcdr(v_35908);
    stack[-1] = v_35908;
    goto v_35699;
v_35698:
    stack[-7] = v_35908;
    v_35908 = stack[-7];
    fn = elt(env, 5); // lastpair
    v_35908 = (*qfn1(fn))(fn, v_35908);
    env = stack[-14];
    stack[-6] = v_35908;
    v_35908 = stack[-8];
    v_35908 = add1(v_35908);
    env = stack[-14];
    stack[-8] = v_35908;
    v_35908 = stack[-6];
    if (!consp(v_35908)) goto v_35785;
    else goto v_35786;
v_35785:
    goto v_35667;
v_35786:
v_35668:
    goto v_35798;
v_35794:
    v_35909 = qvalue(elt(env, 1)); // d
    goto v_35795;
v_35796:
    v_35908 = stack[-8];
    goto v_35797;
v_35798:
    goto v_35794;
v_35795:
    goto v_35796;
v_35797:
    v_35908 = difference2(v_35909, v_35908);
    env = stack[-14];
    v_35908 = Lminusp(nil, v_35908);
    env = stack[-14];
    if (v_35908 == nil) goto v_35791;
    v_35908 = stack[-7];
    goto v_35666;
v_35791:
    goto v_35807;
v_35803:
    stack[-5] = stack[-6];
    goto v_35804;
v_35805:
    goto v_35814;
v_35810:
    v_35909 = stack[-10];
    goto v_35811;
v_35812:
    v_35908 = stack[-8];
    goto v_35813;
v_35814:
    goto v_35810;
v_35811:
    goto v_35812;
v_35813:
    fn = elt(env, 2); // mksq
    v_35908 = (*qfn2(fn))(fn, v_35909, v_35908);
    env = stack[-14];
    v_35908 = qcar(v_35908);
    stack[-4] = v_35908;
    goto v_35832;
v_35826:
    stack[-2] = stack[-12];
    goto v_35827;
v_35828:
    goto v_35839;
v_35835:
    v_35909 = qvalue(elt(env, 1)); // d
    goto v_35836;
v_35837:
    v_35908 = stack[-8];
    goto v_35838;
v_35839:
    goto v_35835;
v_35836:
    goto v_35837;
v_35838:
    stack[-1] = difference2(v_35909, v_35908);
    env = stack[-14];
    goto v_35829;
v_35830:
    goto v_35847;
v_35843:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35844;
v_35845:
    goto v_35854;
v_35850:
    v_35909 = stack[-11];
    goto v_35851;
v_35852:
    v_35908 = stack[-8];
    goto v_35853;
v_35854:
    goto v_35850;
v_35851:
    goto v_35852;
v_35853:
    v_35908 = difference2(v_35909, v_35908);
    env = stack[-14];
    goto v_35846;
v_35847:
    goto v_35843;
v_35844:
    goto v_35845;
v_35846:
    fn = elt(env, 3); // max
    v_35908 = (*qfn2(fn))(fn, stack[0], v_35908);
    env = stack[-14];
    goto v_35831;
v_35832:
    goto v_35826;
v_35827:
    goto v_35828;
v_35829:
    goto v_35830;
v_35831:
    v_35908 = CC_randKmonsKdense(elt(env, 0), 3, stack[-2], stack[-1], v_35908);
    env = stack[-14];
    stack[-3] = v_35908;
    v_35908 = stack[-3];
    if (v_35908 == nil) goto v_35859;
    else goto v_35860;
v_35859:
    v_35908 = nil;
    goto v_35823;
v_35860:
    v_35908 = stack[-3];
    v_35908 = qcar(v_35908);
    goto v_35872;
v_35868:
    v_35909 = stack[-4];
    goto v_35869;
v_35870:
    goto v_35871;
v_35872:
    goto v_35868;
v_35869:
    goto v_35870;
v_35871:
    fn = elt(env, 4); // multf
    v_35908 = (*qfn2(fn))(fn, v_35909, v_35908);
    env = stack[-14];
    v_35908 = ncons(v_35908);
    env = stack[-14];
    stack[-1] = v_35908;
    stack[-2] = v_35908;
v_35824:
    v_35908 = stack[-3];
    v_35908 = qcdr(v_35908);
    stack[-3] = v_35908;
    v_35908 = stack[-3];
    if (v_35908 == nil) goto v_35879;
    else goto v_35880;
v_35879:
    v_35908 = stack[-2];
    goto v_35823;
v_35880:
    goto v_35888;
v_35884:
    stack[0] = stack[-1];
    goto v_35885;
v_35886:
    v_35908 = stack[-3];
    v_35908 = qcar(v_35908);
    goto v_35899;
v_35895:
    v_35909 = stack[-4];
    goto v_35896;
v_35897:
    goto v_35898;
v_35899:
    goto v_35895;
v_35896:
    goto v_35897;
v_35898:
    fn = elt(env, 4); // multf
    v_35908 = (*qfn2(fn))(fn, v_35909, v_35908);
    env = stack[-14];
    v_35908 = ncons(v_35908);
    env = stack[-14];
    goto v_35887;
v_35888:
    goto v_35884;
v_35885:
    goto v_35886;
v_35887:
    v_35908 = Lrplacd(nil, stack[0], v_35908);
    env = stack[-14];
    v_35908 = stack[-1];
    v_35908 = qcdr(v_35908);
    stack[-1] = v_35908;
    goto v_35824;
v_35823:
    goto v_35806;
v_35807:
    goto v_35803;
v_35804:
    goto v_35805;
v_35806:
    v_35908 = Lrplacd(nil, stack[-5], v_35908);
    env = stack[-14];
    v_35908 = stack[-6];
    fn = elt(env, 5); // lastpair
    v_35908 = (*qfn1(fn))(fn, v_35908);
    env = stack[-14];
    stack[-6] = v_35908;
    v_35908 = stack[-8];
    v_35908 = add1(v_35908);
    env = stack[-14];
    stack[-8] = v_35908;
    goto v_35668;
v_35666:
    goto v_35649;
v_35650:
    goto v_35646;
v_35647:
    goto v_35648;
v_35649:
    v_35908 = Lappend(nil, stack[-9], v_35908);
    goto v_35542;
    v_35908 = nil;
v_35542:
    ;}  // end of a binding scope
    return onevalue(v_35908);
}



// Code for lispcondp

static LispObject CC_lispcondp(LispObject env,
                         LispObject v_35525)
{
    env = qenv(env);
    LispObject v_35535, v_35536;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_35535 = v_35525;
// end of prologue
    goto v_35532;
v_35528:
    goto v_35529;
v_35530:
    v_35536 = elt(env, 1); // cond
    goto v_35531;
v_35532:
    goto v_35528;
v_35529:
    goto v_35530;
v_35531:
        return Leqcar(nil, v_35535, v_35536);
}



// Code for formclear

static LispObject CC_formclear(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_35548, v_35549, v_35550;
    LispObject fn;
    LispObject v_35527, v_35526, v_35525;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formclear");
    va_start(aa, nargs);
    v_35525 = va_arg(aa, LispObject);
    v_35526 = va_arg(aa, LispObject);
    v_35527 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_35527,v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_35525,v_35526,v_35527);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_35548 = v_35527;
    v_35549 = v_35526;
    v_35550 = v_35525;
// end of prologue
    goto v_35534;
v_35530:
    stack[0] = elt(env, 1); // clear
    goto v_35531;
v_35532:
    goto v_35543;
v_35537:
    v_35550 = qcdr(v_35550);
    goto v_35538;
v_35539:
    goto v_35540;
v_35541:
    goto v_35542;
v_35543:
    goto v_35537;
v_35538:
    goto v_35539;
v_35540:
    goto v_35541;
v_35542:
    fn = elt(env, 2); // formclear1
    v_35548 = (*qfnn(fn))(fn, 3, v_35550, v_35549, v_35548);
    goto v_35533;
v_35534:
    goto v_35530;
v_35531:
    goto v_35532;
v_35533:
    {
        LispObject v_35552 = stack[0];
        return list2(v_35552, v_35548);
    }
}



// Code for cdr_signsort

static LispObject CC_cdr_signsort(LispObject env,
                         LispObject v_35525, LispObject v_35526)
{
    env = qenv(env);
    LispObject v_35719, v_35720;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_35525,v_35526);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_35526;
    v_35719 = v_35525;
// end of prologue
    fn = elt(env, 1); // copy
    v_35719 = (*qfn1(fn))(fn, v_35719);
    env = stack[-7];
    stack[-6] = v_35719;
    v_35719 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_35719;
    v_35719 = nil;
    stack[-4] = v_35719;
v_35542:
    v_35719 = stack[-6];
    if (v_35719 == nil) goto v_35545;
    else goto v_35546;
v_35545:
    goto v_35541;
v_35546:
    v_35719 = stack[-4];
    if (v_35719 == nil) goto v_35551;
    else goto v_35552;
v_35551:
    goto v_35559;
v_35555:
    v_35719 = stack[-6];
    v_35720 = qcar(v_35719);
    goto v_35556;
v_35557:
    v_35719 = stack[-4];
    goto v_35558;
v_35559:
    goto v_35555;
v_35556:
    goto v_35557;
v_35558:
    v_35719 = cons(v_35720, v_35719);
    env = stack[-7];
    stack[-4] = v_35719;
    v_35719 = stack[-6];
    v_35719 = qcdr(v_35719);
    stack[-6] = v_35719;
    goto v_35550;
v_35552:
    goto v_35572;
v_35568:
    v_35719 = stack[-6];
    v_35719 = qcar(v_35719);
    v_35720 = qcdr(v_35719);
    goto v_35569;
v_35570:
    v_35719 = stack[-4];
    v_35719 = qcar(v_35719);
    v_35719 = qcdr(v_35719);
    goto v_35571;
v_35572:
    goto v_35568;
v_35569:
    goto v_35570;
v_35571:
    if (equal(v_35720, v_35719)) goto v_35566;
    else goto v_35567;
v_35566:
    v_35719 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_35719;
    v_35719 = nil;
    stack[-6] = v_35719;
    stack[-4] = v_35719;
    goto v_35550;
v_35567:
    goto v_35589;
v_35585:
    stack[0] = stack[-5];
    goto v_35586;
v_35587:
    goto v_35596;
v_35592:
    v_35719 = stack[-4];
    v_35719 = qcar(v_35719);
    v_35720 = qcdr(v_35719);
    goto v_35593;
v_35594:
    v_35719 = stack[-6];
    v_35719 = qcar(v_35719);
    v_35719 = qcdr(v_35719);
    goto v_35595;
v_35596:
    goto v_35592;
v_35593:
    goto v_35594;
v_35595:
    v_35719 = list2(v_35720, v_35719);
    env = stack[-7];
    goto v_35588;
v_35589:
    goto v_35585;
v_35586:
    goto v_35587;
v_35588:
    fn = elt(env, 2); // apply
    v_35719 = (*qfn2(fn))(fn, stack[0], v_35719);
    env = stack[-7];
    if (v_35719 == nil) goto v_35583;
    goto v_35608;
v_35604:
    v_35719 = stack[-6];
    v_35720 = qcar(v_35719);
    goto v_35605;
v_35606:
    v_35719 = stack[-4];
    goto v_35607;
v_35608:
    goto v_35604;
v_35605:
    goto v_35606;
v_35607:
    v_35719 = cons(v_35720, v_35719);
    env = stack[-7];
    stack[-4] = v_35719;
    v_35719 = stack[-6];
    v_35719 = qcdr(v_35719);
    stack[-6] = v_35719;
    goto v_35550;
v_35583:
    v_35719 = stack[-1];
    v_35719 = negate(v_35719);
    env = stack[-7];
    stack[-1] = v_35719;
    v_35719 = stack[-4];
    stack[-3] = v_35719;
    v_35719 = lisp_true;
    stack[-2] = v_35719;
v_35623:
    v_35719 = stack[-2];
    if (v_35719 == nil) goto v_35626;
    else goto v_35627;
v_35626:
    goto v_35622;
v_35627:
    v_35719 = stack[-3];
    v_35719 = qcdr(v_35719);
    if (v_35719 == nil) goto v_35632;
    else goto v_35633;
v_35632:
    v_35719 = nil;
    stack[-2] = v_35719;
    goto v_35631;
v_35633:
    goto v_35643;
v_35639:
    v_35719 = stack[-3];
    v_35719 = qcdr(v_35719);
    v_35719 = qcar(v_35719);
    v_35720 = qcdr(v_35719);
    goto v_35640;
v_35641:
    v_35719 = stack[-6];
    v_35719 = qcar(v_35719);
    v_35719 = qcdr(v_35719);
    goto v_35642;
v_35643:
    goto v_35639;
v_35640:
    goto v_35641;
v_35642:
    if (equal(v_35720, v_35719)) goto v_35637;
    else goto v_35638;
v_35637:
    v_35719 = nil;
    stack[-2] = v_35719;
    v_35719 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_35719;
    v_35719 = nil;
    stack[-6] = v_35719;
    stack[-4] = v_35719;
    goto v_35631;
v_35638:
    goto v_35662;
v_35658:
    stack[0] = stack[-5];
    goto v_35659;
v_35660:
    goto v_35669;
v_35665:
    v_35719 = stack[-3];
    v_35719 = qcdr(v_35719);
    v_35719 = qcar(v_35719);
    v_35720 = qcdr(v_35719);
    goto v_35666;
v_35667:
    v_35719 = stack[-6];
    v_35719 = qcar(v_35719);
    v_35719 = qcdr(v_35719);
    goto v_35668;
v_35669:
    goto v_35665;
v_35666:
    goto v_35667;
v_35668:
    v_35719 = list2(v_35720, v_35719);
    env = stack[-7];
    goto v_35661;
v_35662:
    goto v_35658;
v_35659:
    goto v_35660;
v_35661:
    fn = elt(env, 2); // apply
    v_35719 = (*qfn2(fn))(fn, stack[0], v_35719);
    env = stack[-7];
    if (v_35719 == nil) goto v_35655;
    else goto v_35656;
v_35655:
    v_35719 = stack[-3];
    v_35719 = qcdr(v_35719);
    stack[-3] = v_35719;
    v_35719 = stack[-1];
    v_35719 = negate(v_35719);
    env = stack[-7];
    stack[-1] = v_35719;
    goto v_35631;
v_35656:
    v_35719 = nil;
    stack[-2] = v_35719;
    goto v_35631;
v_35631:
    goto v_35623;
v_35622:
    v_35719 = stack[-6];
    if (v_35719 == nil) goto v_35688;
    goto v_35695;
v_35691:
    stack[0] = stack[-3];
    goto v_35692;
v_35693:
    goto v_35702;
v_35698:
    v_35719 = stack[-6];
    v_35720 = qcar(v_35719);
    goto v_35699;
v_35700:
    v_35719 = stack[-3];
    v_35719 = qcdr(v_35719);
    goto v_35701;
v_35702:
    goto v_35698;
v_35699:
    goto v_35700;
v_35701:
    v_35719 = cons(v_35720, v_35719);
    env = stack[-7];
    goto v_35694;
v_35695:
    goto v_35691;
v_35692:
    goto v_35693;
v_35694:
    v_35719 = Lrplacd(nil, stack[0], v_35719);
    env = stack[-7];
    v_35719 = stack[-6];
    v_35719 = qcdr(v_35719);
    stack[-6] = v_35719;
    goto v_35686;
v_35688:
v_35686:
    goto v_35550;
v_35550:
    goto v_35542;
v_35541:
    goto v_35715;
v_35711:
    stack[0] = stack[-1];
    goto v_35712;
v_35713:
    v_35719 = stack[-4];
    v_35719 = Lreverse(nil, v_35719);
    goto v_35714;
v_35715:
    goto v_35711;
v_35712:
    goto v_35713;
v_35714:
    {
        LispObject v_35728 = stack[0];
        return cons(v_35728, v_35719);
    }
    return onevalue(v_35719);
}



// Code for extodd

static LispObject CC_extodd(LispObject env,
                         LispObject v_35525)
{
    env = qenv(env);
    LispObject v_35617, v_35618;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35525);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_35525;
// end of prologue
    goto v_35539;
v_35535:
    v_35617 = stack[0];
    v_35618 = qcar(v_35617);
    goto v_35536;
v_35537:
    v_35617 = elt(env, 1); // ext
    goto v_35538;
v_35539:
    goto v_35535;
v_35536:
    goto v_35537;
v_35538:
    if (v_35618 == v_35617) goto v_35534;
    v_35617 = elt(env, 2); // "the argument of extodd must be an ext variable"
    fn = elt(env, 6); // rederr
    v_35617 = (*qfn1(fn))(fn, v_35617);
    env = stack[-2];
    goto v_35532;
v_35534:
v_35532:
    v_35617 = stack[0];
    v_35617 = qcdr(v_35617);
    v_35617 = qcar(v_35617);
    stack[-1] = v_35617;
    v_35617 = stack[-1];
    if (is_number(v_35617)) goto v_35550;
    else goto v_35551;
v_35550:
    goto v_35562;
v_35558:
    v_35618 = stack[-1];
    goto v_35559;
v_35560:
    v_35617 = qvalue(elt(env, 3)); // n_all_parametric_ext
    goto v_35561;
v_35562:
    goto v_35558;
v_35559:
    goto v_35560;
v_35561:
    v_35617 = (LispObject)greaterp2(v_35618, v_35617);
    v_35617 = v_35617 ? lisp_true : nil;
    env = stack[-2];
    if (v_35617 == nil) goto v_35556;
    goto v_35570;
v_35566:
    stack[0] = qvalue(elt(env, 4)); // all_principal_odd!*
    goto v_35567;
v_35568:
    goto v_35577;
v_35573:
    v_35618 = stack[-1];
    goto v_35574;
v_35575:
    v_35617 = qvalue(elt(env, 3)); // n_all_parametric_ext
    goto v_35576;
v_35577:
    goto v_35573;
v_35574:
    goto v_35575;
v_35576:
    v_35617 = difference2(v_35618, v_35617);
    env = stack[-2];
    goto v_35569;
v_35570:
    goto v_35566;
v_35567:
    goto v_35568;
v_35569:
    {
        LispObject v_35621 = stack[0];
        fn = elt(env, 7); // nth
        return (*qfn2(fn))(fn, v_35621, v_35617);
    }
v_35556:
    goto v_35587;
v_35583:
    v_35618 = qvalue(elt(env, 5)); // all_parametric_odd!*
    goto v_35584;
v_35585:
    v_35617 = stack[-1];
    goto v_35586;
v_35587:
    goto v_35583;
v_35584:
    goto v_35585;
v_35586:
    {
        fn = elt(env, 7); // nth
        return (*qfn2(fn))(fn, v_35618, v_35617);
    }
    v_35617 = nil;
    goto v_35529;
v_35551:
    goto v_35599;
v_35595:
    v_35618 = stack[-1];
    goto v_35596;
v_35597:
    v_35617 = qvalue(elt(env, 5)); // all_parametric_odd!*
    goto v_35598;
v_35599:
    goto v_35595;
v_35596:
    goto v_35597;
v_35598:
    v_35617 = Lmember(nil, v_35618, v_35617);
    if (v_35617 == nil) goto v_35594;
    else goto v_35592;
v_35594:
    goto v_35608;
v_35604:
    v_35618 = stack[-1];
    goto v_35605;
v_35606:
    v_35617 = qvalue(elt(env, 4)); // all_principal_odd!*
    goto v_35607;
v_35608:
    goto v_35604;
v_35605:
    goto v_35606;
v_35607:
    v_35617 = Lmember(nil, v_35618, v_35617);
    if (v_35617 == nil) goto v_35603;
    else goto v_35592;
v_35603:
    goto v_35593;
v_35592:
    v_35617 = stack[-1];
    goto v_35529;
v_35593:
    v_35617 = elt(env, 2); // "the argument of extodd must be an ext variable"
    fn = elt(env, 6); // rederr
    v_35617 = (*qfn1(fn))(fn, v_35617);
    goto v_35591;
v_35591:
    v_35617 = nil;
v_35529:
    return onevalue(v_35617);
}



// Code for sfto_mindeg1

static LispObject CC_sfto_mindeg1(LispObject env,
                         LispObject v_35525, LispObject v_35526)
{
    env = qenv(env);
    LispObject v_35577, v_35578;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_35525,v_35526);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_35526;
    stack[-1] = v_35525;
// end of prologue
v_35530:
    v_35577 = stack[-1];
    if (!consp(v_35577)) goto v_35541;
    else goto v_35542;
v_35541:
    v_35577 = lisp_true;
    goto v_35540;
v_35542:
    v_35577 = stack[-1];
    v_35577 = qcar(v_35577);
    v_35577 = (consp(v_35577) ? nil : lisp_true);
    goto v_35540;
    v_35577 = nil;
v_35540:
    if (v_35577 == nil) goto v_35538;
    v_35577 = lisp_true;
    goto v_35536;
v_35538:
    goto v_35558;
v_35554:
    v_35577 = stack[-1];
    v_35577 = qcar(v_35577);
    v_35577 = qcar(v_35577);
    v_35578 = qcar(v_35577);
    goto v_35555;
v_35556:
    v_35577 = stack[0];
    goto v_35557;
v_35558:
    goto v_35554;
v_35555:
    goto v_35556;
v_35557:
    v_35577 = Lneq(nil, v_35578, v_35577);
    env = stack[-2];
    goto v_35536;
    v_35577 = nil;
v_35536:
    if (v_35577 == nil) goto v_35534;
    v_35577 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35529;
v_35534:
    v_35577 = stack[-1];
    v_35577 = qcdr(v_35577);
    if (v_35577 == nil) goto v_35566;
    v_35577 = stack[-1];
    v_35577 = qcdr(v_35577);
    stack[-1] = v_35577;
    goto v_35530;
v_35566:
    v_35577 = stack[-1];
    v_35577 = qcar(v_35577);
    v_35577 = qcar(v_35577);
    v_35577 = qcdr(v_35577);
    goto v_35529;
    v_35577 = nil;
v_35529:
    return onevalue(v_35577);
}



// Code for let0

static LispObject CC_let0(LispObject env,
                         LispObject v_35525)
{
    env = qenv(env);
    LispObject v_35531, v_35532;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35525);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_35532 = v_35525;
// end of prologue
    v_35531 = nil;
// Binding frasc!*
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_35531; // frasc!*
    v_35531 = v_35532;
    fn = elt(env, 2); // let00
    v_35531 = (*qfn1(fn))(fn, v_35531);
    ;}  // end of a binding scope
    return onevalue(v_35531);
}



// Code for talp_gaussand

static LispObject CC_talp_gaussand(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_35637, v_35638, v_35639;
    LispObject fn;
    LispObject v_35527, v_35526, v_35525;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_gaussand");
    va_start(aa, nargs);
    v_35525 = va_arg(aa, LispObject);
    v_35526 = va_arg(aa, LispObject);
    v_35527 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_35527,v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_35525,v_35526,v_35527);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_35527;
    stack[-3] = v_35526;
    stack[-4] = v_35525;
// end of prologue
    stack[0] = nil;
    goto v_35541;
v_35535:
    v_35639 = stack[-4];
    goto v_35536;
v_35537:
    v_35637 = stack[-3];
    v_35638 = qcar(v_35637);
    goto v_35538;
v_35539:
    v_35637 = stack[-2];
    goto v_35540;
v_35541:
    goto v_35535;
v_35536:
    goto v_35537;
v_35538:
    goto v_35539;
v_35540:
    fn = elt(env, 3); // talp_trygaussvar
    v_35637 = (*qfnn(fn))(fn, 3, v_35639, v_35638, v_35637);
    env = stack[-6];
    stack[-1] = v_35637;
    goto v_35558;
v_35554:
    v_35638 = stack[-1];
    goto v_35555;
v_35556:
    v_35637 = elt(env, 1); // failed
    goto v_35557;
v_35558:
    goto v_35554;
v_35555:
    goto v_35556;
v_35557:
    if (v_35638 == v_35637) goto v_35552;
    else goto v_35553;
v_35552:
    v_35637 = lisp_true;
    goto v_35551;
v_35553:
    goto v_35568;
v_35564:
    v_35638 = stack[-1];
    goto v_35565;
v_35566:
    v_35637 = elt(env, 2); // ignore
    goto v_35567;
v_35568:
    goto v_35564;
v_35565:
    goto v_35566;
v_35567:
    v_35637 = (v_35638 == v_35637 ? lisp_true : nil);
    goto v_35551;
    v_35637 = nil;
v_35551:
    if (v_35637 == nil) goto v_35549;
    v_35637 = stack[-3];
    v_35637 = qcdr(v_35637);
    stack[-3] = v_35637;
v_35576:
    v_35637 = stack[-3];
    if (v_35637 == nil) goto v_35579;
    v_35637 = stack[0];
    if (v_35637 == nil) goto v_35583;
    else goto v_35579;
v_35583:
    goto v_35580;
v_35579:
    goto v_35575;
v_35580:
    goto v_35593;
v_35587:
    v_35639 = stack[-4];
    goto v_35588;
v_35589:
    v_35637 = stack[-3];
    v_35638 = qcar(v_35637);
    goto v_35590;
v_35591:
    v_35637 = stack[-2];
    goto v_35592;
v_35593:
    goto v_35587;
v_35588:
    goto v_35589;
v_35590:
    goto v_35591;
v_35592:
    fn = elt(env, 3); // talp_trygaussvar
    v_35637 = (*qfnn(fn))(fn, 3, v_35639, v_35638, v_35637);
    env = stack[-6];
    stack[-5] = v_35637;
    goto v_35610;
v_35606:
    v_35638 = stack[-5];
    goto v_35607;
v_35608:
    v_35637 = elt(env, 1); // failed
    goto v_35609;
v_35610:
    goto v_35606;
v_35607:
    goto v_35608;
v_35609:
    if (v_35638 == v_35637) goto v_35605;
    goto v_35618;
v_35614:
    v_35638 = stack[-5];
    goto v_35615;
v_35616:
    v_35637 = elt(env, 2); // ignore
    goto v_35617;
v_35618:
    goto v_35614;
v_35615:
    goto v_35616;
v_35617:
    v_35637 = Lneq(nil, v_35638, v_35637);
    env = stack[-6];
    goto v_35603;
v_35605:
    v_35637 = nil;
    goto v_35603;
    v_35637 = nil;
v_35603:
    if (v_35637 == nil) goto v_35601;
    v_35637 = lisp_true;
    stack[0] = v_35637;
    v_35637 = stack[-5];
    stack[-1] = v_35637;
    goto v_35599;
v_35601:
v_35599:
    v_35637 = stack[-3];
    v_35637 = qcdr(v_35637);
    stack[-3] = v_35637;
    goto v_35576;
v_35575:
    goto v_35547;
v_35549:
v_35547:
    v_35637 = stack[-1];
    if (v_35637 == nil) goto v_35631;
    v_35637 = stack[-1];
    goto v_35629;
v_35631:
    v_35637 = elt(env, 1); // failed
    goto v_35629;
    v_35637 = nil;
v_35629:
    return onevalue(v_35637);
}



// Code for mri_dettype

static LispObject CC_mri_dettype(LispObject env,
                         LispObject v_35525)
{
    env = qenv(env);
    LispObject v_35587, v_35588;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35525);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_35587 = v_35525;
// end of prologue
    stack[-1] = nil;
    stack[0] = nil;
    fn = elt(env, 3); // mri_arg2l
    v_35587 = (*qfn1(fn))(fn, v_35587);
    env = stack[-4];
    fn = elt(env, 4); // kernels
    v_35587 = (*qfn1(fn))(fn, v_35587);
    env = stack[-4];
    stack[-3] = v_35587;
    v_35587 = stack[-3];
    if (v_35587 == nil) goto v_35539;
    else goto v_35540;
v_35539:
    v_35587 = elt(env, 1); // int
    goto v_35533;
v_35540:
    v_35587 = lisp_true;
    stack[-2] = v_35587;
v_35546:
    v_35587 = stack[-2];
    if (v_35587 == nil) goto v_35549;
    v_35587 = stack[-3];
    if (v_35587 == nil) goto v_35549;
    goto v_35550;
v_35549:
    goto v_35545;
v_35550:
    v_35587 = stack[-3];
    v_35587 = qcar(v_35587);
    v_35588 = v_35587;
    v_35587 = stack[-3];
    v_35587 = qcdr(v_35587);
    stack[-3] = v_35587;
    v_35587 = v_35588;
    fn = elt(env, 5); // mri_realvarp
    v_35587 = (*qfn1(fn))(fn, v_35587);
    env = stack[-4];
    if (v_35587 == nil) goto v_35563;
    v_35587 = stack[0];
    if (v_35587 == nil) goto v_35569;
    v_35587 = nil;
    stack[-1] = v_35587;
    stack[0] = v_35587;
    stack[-2] = v_35587;
    goto v_35567;
v_35569:
    v_35587 = elt(env, 2); // real
    stack[-1] = v_35587;
    goto v_35567;
v_35567:
    goto v_35561;
v_35563:
    v_35587 = stack[-1];
    if (v_35587 == nil) goto v_35576;
    v_35587 = nil;
    stack[-1] = v_35587;
    stack[0] = v_35587;
    stack[-2] = v_35587;
    goto v_35561;
v_35576:
    v_35587 = elt(env, 1); // int
    stack[0] = v_35587;
    goto v_35561;
v_35561:
    goto v_35546;
v_35545:
    v_35587 = stack[0];
    if (v_35587 == nil) goto v_35584;
    else goto v_35583;
v_35584:
    v_35587 = stack[-1];
v_35583:
v_35533:
    return onevalue(v_35587);
}



// Code for qqe_length!-graph!-remove!-mark

static LispObject CC_qqe_lengthKgraphKremoveKmark(LispObject env,
                         LispObject v_35525, LispObject v_35526)
{
    env = qenv(env);
    LispObject v_35553, v_35554, v_35555, v_35556;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_35525,v_35526);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_35555 = v_35526;
    v_35553 = v_35525;
// end of prologue
    v_35556 = v_35553;
v_35531:
    v_35553 = v_35556;
    if (v_35553 == nil) goto v_35535;
    else goto v_35536;
v_35535:
    v_35553 = nil;
    goto v_35530;
v_35536:
    v_35553 = v_35556;
    v_35553 = qcar(v_35553);
    goto v_35547;
v_35543:
    v_35554 = v_35553;
    goto v_35544;
v_35545:
    v_35553 = v_35555;
    goto v_35546;
v_35547:
    goto v_35543;
v_35544:
    goto v_35545;
v_35546:
    v_35553 = Lremprop(nil, v_35554, v_35553);
    env = stack[0];
    v_35553 = v_35556;
    v_35553 = qcdr(v_35553);
    v_35556 = v_35553;
    goto v_35531;
v_35530:
    return onevalue(v_35553);
}



// Code for rat_leq

static LispObject CC_rat_leq(LispObject env,
                         LispObject v_35525, LispObject v_35526)
{
    env = qenv(env);
    LispObject v_35545, v_35546;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_35525,v_35526);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_35545 = v_35526;
    v_35546 = v_35525;
// end of prologue
    goto v_35533;
v_35529:
    goto v_35540;
v_35536:
    stack[0] = v_35546;
    goto v_35537;
v_35538:
    fn = elt(env, 1); // negsq
    v_35545 = (*qfn1(fn))(fn, v_35545);
    env = stack[-1];
    goto v_35539;
v_35540:
    goto v_35536;
v_35537:
    goto v_35538;
v_35539:
    fn = elt(env, 2); // addsq
    v_35545 = (*qfn2(fn))(fn, stack[0], v_35545);
    env = stack[-1];
    fn = elt(env, 3); // rat_sgn
    v_35546 = (*qfn1(fn))(fn, v_35545);
    goto v_35530;
v_35531:
    v_35545 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35532;
v_35533:
    goto v_35529;
v_35530:
    goto v_35531;
v_35532:
        return Llessp(nil, v_35546, v_35545);
}



// Code for cd_ordatp

static LispObject CC_cd_ordatp(LispObject env,
                         LispObject v_35525, LispObject v_35526)
{
    env = qenv(env);
    LispObject v_35598, v_35599, v_35600, v_35601;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_35600 = v_35526;
    v_35601 = v_35525;
// end of prologue
    goto v_35540;
v_35536:
    v_35598 = v_35601;
    v_35599 = qcar(v_35598);
    goto v_35537;
v_35538:
    v_35598 = elt(env, 1); // neq
    goto v_35539;
v_35540:
    goto v_35536;
v_35537:
    goto v_35538;
v_35539:
    if (v_35599 == v_35598) goto v_35534;
    else goto v_35535;
v_35534:
    goto v_35548;
v_35544:
    v_35598 = v_35600;
    v_35599 = qcar(v_35598);
    goto v_35545;
v_35546:
    v_35598 = elt(env, 2); // equal
    goto v_35547;
v_35548:
    goto v_35544;
v_35545:
    goto v_35546;
v_35547:
    v_35598 = (v_35599 == v_35598 ? lisp_true : nil);
    goto v_35533;
v_35535:
    v_35598 = nil;
    goto v_35533;
    v_35598 = nil;
v_35533:
    if (v_35598 == nil) goto v_35531;
    v_35598 = lisp_true;
    goto v_35529;
v_35531:
    goto v_35567;
v_35563:
    v_35598 = v_35601;
    v_35599 = qcar(v_35598);
    goto v_35564;
v_35565:
    v_35598 = elt(env, 2); // equal
    goto v_35566;
v_35567:
    goto v_35563;
v_35564:
    goto v_35565;
v_35566:
    if (v_35599 == v_35598) goto v_35561;
    else goto v_35562;
v_35561:
    goto v_35575;
v_35571:
    v_35598 = v_35600;
    v_35599 = qcar(v_35598);
    goto v_35572;
v_35573:
    v_35598 = elt(env, 1); // neq
    goto v_35574;
v_35575:
    goto v_35571;
v_35572:
    goto v_35573;
v_35574:
    v_35598 = (v_35599 == v_35598 ? lisp_true : nil);
    goto v_35560;
v_35562:
    v_35598 = nil;
    goto v_35560;
    v_35598 = nil;
v_35560:
    if (v_35598 == nil) goto v_35558;
    v_35598 = nil;
    goto v_35529;
v_35558:
    goto v_35591;
v_35587:
    v_35598 = v_35601;
    v_35598 = qcdr(v_35598);
    v_35598 = qcar(v_35598);
    goto v_35588;
v_35589:
    v_35599 = v_35600;
    v_35599 = qcdr(v_35599);
    v_35599 = qcar(v_35599);
    goto v_35590;
v_35591:
    goto v_35587;
v_35588:
    goto v_35589;
v_35590:
    {
        fn = elt(env, 3); // ordp
        return (*qfn2(fn))(fn, v_35598, v_35599);
    }
    v_35598 = nil;
v_35529:
    return onevalue(v_35598);
}



// Code for applyml

static LispObject CC_applyml(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_35601, v_35602;
    LispObject fn;
    argcheck(nargs, 0, "applyml");
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
    fn = elt(env, 6); // lex
    v_35601 = (*qfnn(fn))(fn, 0);
    env = stack[0];
    goto v_35538;
v_35534:
    v_35601 = qvalue(elt(env, 1)); // char
    fn = elt(env, 7); // compress!*
    v_35602 = (*qfn1(fn))(fn, v_35601);
    env = stack[0];
    goto v_35535;
v_35536:
    v_35601 = qvalue(elt(env, 2)); // rdlist!*
    goto v_35537;
v_35538:
    goto v_35534;
v_35535:
    goto v_35536;
v_35537:
    v_35602 = Lassoc(nil, v_35602, v_35601);
    v_35601 = v_35602;
    if (v_35602 == nil) goto v_35533;
    goto v_35548;
v_35544:
    v_35602 = v_35601;
    v_35602 = qcdr(v_35602);
    v_35602 = qcar(v_35602);
    goto v_35545;
v_35546:
    v_35601 = qcdr(v_35601);
    v_35601 = qcdr(v_35601);
    goto v_35547;
v_35548:
    goto v_35544;
v_35545:
    goto v_35546;
v_35547:
    {
        fn = elt(env, 8); // apply
        return (*qfn2(fn))(fn, v_35602, v_35601);
    }
v_35533:
    goto v_35565;
v_35561:
    v_35602 = qvalue(elt(env, 1)); // char
    goto v_35562;
v_35563:
    v_35601 = elt(env, 3); // (i d e n t !/)
    goto v_35564;
v_35565:
    goto v_35561;
v_35562:
    goto v_35563;
v_35564:
    if (equal(v_35602, v_35601)) goto v_35559;
    else goto v_35560;
v_35559:
    v_35601 = lisp_true;
    goto v_35558;
v_35560:
    goto v_35575;
v_35571:
    v_35602 = qvalue(elt(env, 1)); // char
    goto v_35572;
v_35573:
    v_35601 = elt(env, 4); // (c o m p o s e !/)
    goto v_35574;
v_35575:
    goto v_35571;
v_35572:
    goto v_35573;
v_35574:
    v_35601 = (equal(v_35602, v_35601) ? lisp_true : nil);
    goto v_35558;
    v_35601 = nil;
v_35558:
    if (v_35601 == nil) goto v_35556;
    v_35601 = nil;
    goto v_35528;
v_35556:
    goto v_35586;
v_35582:
    v_35602 = qvalue(elt(env, 1)); // char
    goto v_35583;
v_35584:
    v_35601 = elt(env, 5); // (i n v e r s e !/)
    goto v_35585;
v_35586:
    goto v_35582;
v_35583:
    goto v_35584;
v_35585:
    if (equal(v_35602, v_35601)) goto v_35580;
    else goto v_35581;
v_35580:
    v_35601 = lisp_true;
    goto v_35528;
v_35581:
    goto v_35597;
v_35593:
    v_35601 = qvalue(elt(env, 1)); // char
    fn = elt(env, 7); // compress!*
    v_35602 = (*qfn1(fn))(fn, v_35601);
    env = stack[0];
    goto v_35594;
v_35595:
    v_35601 = (LispObject)272+TAG_FIXNUM; // 17
    goto v_35596;
v_35597:
    goto v_35593;
v_35594:
    goto v_35595;
v_35596:
    fn = elt(env, 9); // errorml
    v_35601 = (*qfn2(fn))(fn, v_35602, v_35601);
    goto v_35531;
v_35531:
    v_35601 = nil;
v_35528:
    return onevalue(v_35601);
}



// Code for ps!:find!-order

static LispObject CC_psTfindKorder(LispObject env,
                         LispObject v_35526)
{
    env = qenv(env);
    LispObject v_35620, v_35621, v_35622;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35526);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_35620 = v_35526;
// end of prologue
// Binding ps
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_35620; // ps
    v_35620 = qvalue(elt(env, 1)); // ps
    if (v_35620 == nil) goto v_35534;
    else goto v_35535;
v_35534:
    v_35620 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35533;
v_35535:
    v_35620 = qvalue(elt(env, 1)); // ps
    if (symbolp(v_35620)) goto v_35538;
    else goto v_35539;
v_35538:
    v_35620 = qvalue(elt(env, 1)); // ps
    goto v_35533;
v_35539:
    v_35620 = qvalue(elt(env, 1)); // ps
    v_35622 = v_35620;
    v_35620 = v_35622;
    v_35620 = (is_number(v_35620) ? lisp_true : nil);
    if (v_35620 == nil) goto v_35548;
    else goto v_35547;
v_35548:
    v_35620 = v_35622;
    v_35620 = Lconsp(nil, v_35620);
    env = stack[-1];
    if (v_35620 == nil) goto v_35553;
    else goto v_35554;
v_35553:
    v_35620 = nil;
    goto v_35552;
v_35554:
    goto v_35568;
v_35564:
    v_35620 = v_35622;
    v_35621 = qcar(v_35620);
    goto v_35565;
v_35566:
    v_35620 = elt(env, 2); // !:ps!:
    goto v_35567;
v_35568:
    goto v_35564;
v_35565:
    goto v_35566;
v_35567:
    if (v_35621 == v_35620) goto v_35563;
    v_35620 = v_35622;
    v_35620 = qcar(v_35620);
    if (!symbolp(v_35620)) v_35620 = nil;
    else { v_35620 = qfastgets(v_35620);
           if (v_35620 != nil) { v_35620 = elt(v_35620, 8); // dname
#ifdef RECORD_GET
             if (v_35620 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_35620 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_35620 == SPID_NOPROP) v_35620 = nil; }}
#endif
    goto v_35561;
v_35563:
    v_35620 = nil;
    goto v_35561;
    v_35620 = nil;
v_35561:
    goto v_35552;
    v_35620 = nil;
v_35552:
v_35547:
    if (v_35620 == nil) goto v_35543;
    v_35620 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35533;
v_35543:
    goto v_35586;
v_35582:
    v_35621 = qvalue(elt(env, 1)); // ps
    goto v_35583;
v_35584:
    v_35620 = elt(env, 2); // !:ps!:
    goto v_35585;
v_35586:
    goto v_35582;
v_35583:
    goto v_35584;
v_35585:
    if (!consp(v_35621)) goto v_35580;
    v_35621 = qcar(v_35621);
    if (v_35621 == v_35620) goto v_35579;
    else goto v_35580;
v_35579:
    v_35620 = qvalue(elt(env, 1)); // ps
    v_35620 = qcdr(v_35620);
    if (symbolp(v_35620)) goto v_35591;
    else goto v_35592;
v_35591:
    v_35620 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 5); // ps!:unknown!-order
    v_35620 = (*qfn1(fn))(fn, v_35620);
    goto v_35590;
v_35592:
    v_35620 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 6); // ps!:expression
    v_35620 = (*qfn1(fn))(fn, v_35620);
    env = stack[-1];
    if (!consp(v_35620)) goto v_35597;
    else goto v_35598;
v_35597:
    v_35620 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 7); // ps!:order
    v_35620 = (*qfn1(fn))(fn, v_35620);
    goto v_35590;
v_35598:
    v_35620 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 8); // ps!:find!-order1
    v_35620 = (*qfn1(fn))(fn, v_35620);
    goto v_35590;
    v_35620 = nil;
v_35590:
    goto v_35533;
v_35580:
    goto v_35616;
v_35610:
    v_35622 = elt(env, 3); // tps
    goto v_35611;
v_35612:
    v_35621 = (LispObject)336+TAG_FIXNUM; // 21
    goto v_35613;
v_35614:
    v_35620 = elt(env, 4); // "Unexpected form in ps!:find!-order"
    goto v_35615;
v_35616:
    goto v_35610;
v_35611:
    goto v_35612;
v_35613:
    goto v_35614;
v_35615:
    fn = elt(env, 9); // rerror
    v_35620 = (*qfnn(fn))(fn, 3, v_35622, v_35621, v_35620);
    goto v_35533;
    v_35620 = nil;
v_35533:
    ;}  // end of a binding scope
    return onevalue(v_35620);
}



// Code for subsqnew

static LispObject CC_subsqnew(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_35571, v_35572;
    LispObject fn;
    LispObject v_35527, v_35526, v_35525;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "subsqnew");
    va_start(aa, nargs);
    v_35525 = va_arg(aa, LispObject);
    v_35526 = va_arg(aa, LispObject);
    v_35527 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_35527,v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_35525,v_35526,v_35527);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_35527;
    v_35571 = v_35526;
    stack[-1] = v_35525;
// end of prologue
    fn = elt(env, 1); // prepsq
    v_35571 = (*qfn1(fn))(fn, v_35571);
    env = stack[-3];
    goto v_35541;
v_35537:
    v_35572 = stack[0];
    goto v_35538;
v_35539:
    goto v_35540;
v_35541:
    goto v_35537;
v_35538:
    goto v_35539;
v_35540:
    v_35571 = cons(v_35572, v_35571);
    env = stack[-3];
    stack[-2] = v_35571;
    goto v_35549;
v_35545:
    goto v_35555;
v_35551:
    v_35571 = stack[-1];
    stack[0] = qcar(v_35571);
    goto v_35552;
v_35553:
    v_35571 = stack[-2];
    v_35571 = ncons(v_35571);
    env = stack[-3];
    goto v_35554;
v_35555:
    goto v_35551;
v_35552:
    goto v_35553;
v_35554:
    fn = elt(env, 2); // subf
    stack[0] = (*qfn2(fn))(fn, stack[0], v_35571);
    env = stack[-3];
    goto v_35546;
v_35547:
    goto v_35565;
v_35561:
    v_35571 = stack[-1];
    stack[-1] = qcdr(v_35571);
    goto v_35562;
v_35563:
    v_35571 = stack[-2];
    v_35571 = ncons(v_35571);
    env = stack[-3];
    goto v_35564;
v_35565:
    goto v_35561;
v_35562:
    goto v_35563;
v_35564:
    fn = elt(env, 2); // subf
    v_35571 = (*qfn2(fn))(fn, stack[-1], v_35571);
    env = stack[-3];
    goto v_35548;
v_35549:
    goto v_35545;
v_35546:
    goto v_35547;
v_35548:
    {
        LispObject v_35576 = stack[0];
        fn = elt(env, 3); // quotsq
        return (*qfn2(fn))(fn, v_35576, v_35571);
    }
    return onevalue(v_35571);
}



// Code for groebsimpcontnormalform

static LispObject CC_groebsimpcontnormalform(LispObject env,
                         LispObject v_35525)
{
    env = qenv(env);
    LispObject v_35604, v_35605;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35525);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_35525;
// end of prologue
    v_35604 = stack[-2];
    if (v_35604 == nil) goto v_35533;
    else goto v_35534;
v_35533:
    v_35604 = lisp_true;
    goto v_35532;
v_35534:
    v_35604 = stack[-2];
    v_35604 = qcdr(v_35604);
    v_35604 = qcdr(v_35604);
    v_35604 = qcdr(v_35604);
    v_35604 = qcar(v_35604);
    v_35604 = (v_35604 == nil ? lisp_true : nil);
    goto v_35532;
    v_35604 = nil;
v_35532:
    if (v_35604 == nil) goto v_35530;
    v_35604 = stack[-2];
    goto v_35528;
v_35530:
    v_35604 = stack[-2];
    fn = elt(env, 3); // gsugar
    v_35604 = (*qfn1(fn))(fn, v_35604);
    env = stack[-4];
    stack[0] = v_35604;
    v_35604 = stack[-2];
    v_35604 = qcdr(v_35604);
    v_35604 = qcdr(v_35604);
    v_35604 = qcar(v_35604);
    stack[-3] = v_35604;
    v_35604 = stack[-2];
    fn = elt(env, 4); // vdpsimpcont
    v_35604 = (*qfn1(fn))(fn, v_35604);
    env = stack[-4];
    stack[-2] = v_35604;
    goto v_35565;
v_35561:
    v_35605 = stack[-2];
    goto v_35562;
v_35563:
    v_35604 = stack[0];
    goto v_35564;
v_35565:
    goto v_35561;
v_35562:
    goto v_35563;
v_35564:
    fn = elt(env, 5); // gsetsugar
    v_35604 = (*qfn2(fn))(fn, v_35605, v_35604);
    env = stack[-4];
    v_35604 = qvalue(elt(env, 1)); // !*groebprot
    if (v_35604 == nil) goto v_35571;
    goto v_35579;
v_35575:
    v_35605 = stack[-3];
    goto v_35576;
v_35577:
    v_35604 = stack[-2];
    v_35604 = qcdr(v_35604);
    v_35604 = qcdr(v_35604);
    v_35604 = qcar(v_35604);
    goto v_35578;
v_35579:
    goto v_35575;
v_35576:
    goto v_35577;
v_35578:
    if (equal(v_35605, v_35604)) goto v_35571;
    goto v_35594;
v_35588:
    stack[-1] = elt(env, 2); // quotient
    goto v_35589;
v_35590:
    v_35604 = stack[-2];
    v_35604 = qcdr(v_35604);
    v_35604 = qcdr(v_35604);
    v_35604 = qcar(v_35604);
    fn = elt(env, 6); // vbc2a
    stack[0] = (*qfn1(fn))(fn, v_35604);
    env = stack[-4];
    goto v_35591;
v_35592:
    v_35604 = stack[-3];
    fn = elt(env, 6); // vbc2a
    v_35604 = (*qfn1(fn))(fn, v_35604);
    env = stack[-4];
    goto v_35593;
v_35594:
    goto v_35588;
v_35589:
    goto v_35590;
v_35591:
    goto v_35592;
v_35593:
    v_35604 = list3(stack[-1], stack[0], v_35604);
    env = stack[-4];
    fn = elt(env, 7); // reval
    v_35604 = (*qfn1(fn))(fn, v_35604);
    env = stack[-4];
    fn = elt(env, 8); // groebreductionprotocol2
    v_35604 = (*qfn1(fn))(fn, v_35604);
    goto v_35569;
v_35571:
v_35569:
    v_35604 = stack[-2];
    goto v_35528;
    v_35604 = nil;
v_35528:
    return onevalue(v_35604);
}



// Code for tot!-asym!-indp

static LispObject CC_totKasymKindp(LispObject env,
                         LispObject v_35525)
{
    env = qenv(env);
    LispObject v_35614, v_35615;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35525);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_35525;
// end of prologue
v_35524:
    v_35614 = stack[0];
    if (v_35614 == nil) goto v_35529;
    else goto v_35530;
v_35529:
    v_35614 = lisp_true;
    goto v_35528;
v_35530:
    v_35614 = stack[0];
    v_35614 = qcdr(v_35614);
    if (v_35614 == nil) goto v_35537;
    else goto v_35538;
v_35537:
    v_35614 = lisp_true;
    goto v_35536;
v_35538:
    goto v_35556;
v_35552:
    v_35614 = stack[0];
    v_35615 = qcar(v_35614);
    goto v_35553;
v_35554:
    v_35614 = stack[0];
    v_35614 = qcdr(v_35614);
    v_35614 = qcar(v_35614);
    goto v_35555;
v_35556:
    goto v_35552;
v_35553:
    goto v_35554;
v_35555:
    if (equal(v_35615, v_35614)) goto v_35551;
    v_35614 = stack[0];
    v_35614 = qcar(v_35614);
    if (!consp(v_35614)) goto v_35564;
    else goto v_35565;
v_35564:
    goto v_35573;
v_35569:
    v_35614 = stack[0];
    v_35615 = qcar(v_35614);
    goto v_35570;
v_35571:
    v_35614 = stack[0];
    v_35614 = qcdr(v_35614);
    v_35614 = qcar(v_35614);
    goto v_35572;
v_35573:
    goto v_35569;
v_35570:
    goto v_35571;
v_35572:
    fn = elt(env, 1); // indordp
    v_35614 = (*qfn2(fn))(fn, v_35615, v_35614);
    env = stack[-1];
    goto v_35563;
v_35565:
    v_35614 = stack[0];
    v_35614 = qcar(v_35614);
    fn = elt(env, 2); // indxchk
    v_35614 = (*qfn1(fn))(fn, v_35614);
    env = stack[-1];
    if (v_35614 == nil) goto v_35583;
    else goto v_35582;
v_35583:
    v_35614 = stack[0];
    v_35614 = qcdr(v_35614);
    v_35614 = qcar(v_35614);
    fn = elt(env, 2); // indxchk
    v_35614 = (*qfn1(fn))(fn, v_35614);
    env = stack[-1];
    if (v_35614 == nil) goto v_35589;
    else goto v_35588;
v_35589:
    goto v_35599;
v_35595:
    v_35614 = stack[0];
    v_35615 = qcar(v_35614);
    goto v_35596;
v_35597:
    v_35614 = stack[0];
    v_35614 = qcdr(v_35614);
    v_35614 = qcar(v_35614);
    goto v_35598;
v_35599:
    goto v_35595;
v_35596:
    goto v_35597;
v_35598:
    fn = elt(env, 3); // indordlp
    v_35614 = (*qfn2(fn))(fn, v_35615, v_35614);
    env = stack[-1];
v_35588:
v_35582:
    goto v_35563;
    v_35614 = nil;
v_35563:
    goto v_35549;
v_35551:
    v_35614 = nil;
    goto v_35549;
    v_35614 = nil;
v_35549:
    if (v_35614 == nil) goto v_35546;
    else goto v_35547;
v_35546:
    v_35614 = nil;
    goto v_35545;
v_35547:
    v_35614 = stack[0];
    v_35614 = qcdr(v_35614);
    stack[0] = v_35614;
    goto v_35524;
    v_35614 = nil;
v_35545:
    goto v_35536;
    v_35614 = nil;
v_35536:
    goto v_35528;
    v_35614 = nil;
v_35528:
    return onevalue(v_35614);
}



// Code for calc_map_tar

static LispObject CC_calc_map_tar(LispObject env,
                         LispObject v_35525, LispObject v_35526)
{
    env = qenv(env);
    LispObject v_35608, v_35609, v_35610;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_35525,v_35526);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_35526;
    v_35609 = v_35525;
// end of prologue
    v_35608 = v_35609;
    v_35608 = qcar(v_35608);
    stack[-4] = v_35608;
    v_35608 = v_35609;
    v_35608 = qcdr(v_35608);
    v_35608 = qcar(v_35608);
    stack[-2] = v_35608;
    v_35608 = v_35609;
    v_35608 = qcdr(v_35608);
    v_35608 = qcdr(v_35608);
    v_35608 = qcar(v_35608);
    stack[0] = v_35608;
    v_35608 = v_35609;
    v_35608 = qcdr(v_35608);
    v_35608 = qcdr(v_35608);
    v_35608 = qcdr(v_35608);
    v_35608 = qcar(v_35608);
    stack[-1] = v_35608;
    v_35608 = v_35609;
    v_35608 = qcdr(v_35608);
    v_35608 = qcdr(v_35608);
    v_35608 = qcdr(v_35608);
    v_35608 = qcdr(v_35608);
    v_35608 = qcar(v_35608);
    goto v_35565;
v_35561:
    v_35609 = v_35608;
    goto v_35562;
v_35563:
    v_35608 = stack[-3];
    goto v_35564;
v_35565:
    goto v_35561;
v_35562:
    goto v_35563;
v_35564:
    fn = elt(env, 1); // ev!-poles
    v_35608 = (*qfn2(fn))(fn, v_35609, v_35608);
    env = stack[-5];
    if (v_35608 == nil) goto v_35559;
    v_35608 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35535;
v_35559:
    goto v_35577;
v_35571:
    v_35608 = stack[-1];
    fn = elt(env, 2); // constimes
    stack[-1] = (*qfn1(fn))(fn, v_35608);
    env = stack[-5];
    goto v_35572;
v_35573:
    goto v_35586;
v_35582:
    v_35609 = stack[0];
    goto v_35583;
v_35584:
    v_35608 = stack[-3];
    goto v_35585;
v_35586:
    goto v_35582;
v_35583:
    goto v_35584;
v_35585:
    fn = elt(env, 3); // ev!-tades
    v_35608 = (*qfn2(fn))(fn, v_35609, v_35608);
    env = stack[-5];
    fn = elt(env, 2); // constimes
    stack[0] = (*qfn1(fn))(fn, v_35608);
    env = stack[-5];
    goto v_35574;
v_35575:
    v_35608 = stack[-2];
    if (v_35608 == nil) goto v_35591;
    else goto v_35592;
v_35591:
    v_35608 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35590;
v_35592:
    goto v_35604;
v_35598:
    v_35610 = stack[-4];
    goto v_35599;
v_35600:
    v_35609 = stack[-2];
    goto v_35601;
v_35602:
    v_35608 = stack[-3];
    goto v_35603;
v_35604:
    goto v_35598;
v_35599:
    goto v_35600;
v_35601:
    goto v_35602;
v_35603:
    fn = elt(env, 4); // strand!-alg!-top
    v_35608 = (*qfnn(fn))(fn, 3, v_35610, v_35609, v_35608);
    env = stack[-5];
    goto v_35590;
    v_35608 = nil;
v_35590:
    goto v_35576;
v_35577:
    goto v_35571;
v_35572:
    goto v_35573;
v_35574:
    goto v_35575;
v_35576:
    v_35608 = list3(stack[-1], stack[0], v_35608);
    env = stack[-5];
    {
        fn = elt(env, 2); // constimes
        return (*qfn1(fn))(fn, v_35608);
    }
v_35535:
    return onevalue(v_35608);
}



// Code for invbase!*

static LispObject CC_invbaseH(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_36149, v_36150, v_36151, v_36152;
    LispObject fn;
    argcheck(nargs, 0, "invbase*");
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
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(17);
// end of prologue
// Binding thirdway!*
// FLUIDBIND: reloadenv=16 litvec-offset=1 saveloc=14
{   bind_fluid_stack bind_fluid_var(-16, 1, -14);
    qvalue(elt(env, 1)) = nil; // thirdway!*
// Binding shortway!*
// FLUIDBIND: reloadenv=16 litvec-offset=2 saveloc=13
{   bind_fluid_stack bind_fluid_var(-16, 2, -13);
    qvalue(elt(env, 2)) = nil; // shortway!*
    stack[-12] = nil;
    v_36149 = qvalue(elt(env, 3)); // !*trinvbase
    if (v_36149 == nil) goto v_35545;
    v_36149 = Lterpri(nil, 0);
    env = stack[-16];
    goto v_35543;
v_35545:
v_35543:
    v_36149 = (LispObject)-16+TAG_FIXNUM; // -1
    qvalue(elt(env, 4)) = v_36149; // maxord!*
    stack[-11] = v_36149;
    v_36149 = qvalue(elt(env, 5)); // path
    if (v_36149 == nil) goto v_35552;
    v_36149 = Lterpri(nil, 0);
    env = stack[-16];
    goto v_35550;
v_35552:
v_35550:
    goto v_35562;
v_35556:
    v_36151 = nil;
    goto v_35557;
v_35558:
    v_36150 = qvalue(elt(env, 6)); // gg!*
    goto v_35559;
v_35560:
    v_36149 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35561;
v_35562:
    goto v_35556;
v_35557:
    goto v_35558;
v_35559:
    goto v_35560;
v_35561:
    fn = elt(env, 18); // redall
    v_36149 = (*qfnn(fn))(fn, 3, v_36151, v_36150, v_36149);
    env = stack[-16];
    qvalue(elt(env, 6)) = v_36149; // gg!*
    goto v_35571;
v_35567:
    v_36150 = qvalue(elt(env, 6)); // gg!*
    goto v_35568;
v_35569:
    v_36149 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35570;
v_35571:
    goto v_35567;
v_35568:
    goto v_35569;
v_35570:
    fn = elt(env, 19); // newbasis
    v_36149 = (*qfn2(fn))(fn, v_36150, v_36149);
    env = stack[-16];
    v_36149 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-10] = v_36149;
    v_36149 = qvalue(elt(env, 6)); // gg!*
    stack[0] = v_36149;
v_35578:
    v_36149 = stack[0];
    if (v_36149 == nil) goto v_35582;
    else goto v_35583;
v_35582:
    goto v_35577;
v_35583:
    v_36149 = stack[0];
    v_36149 = qcar(v_36149);
    goto v_35594;
v_35590:
    stack[-1] = stack[-10];
    goto v_35591;
v_35592:
    v_36149 = qcdr(v_36149);
    fn = elt(env, 20); // ord
    v_36149 = (*qfn1(fn))(fn, v_36149);
    env = stack[-16];
    goto v_35593;
v_35594:
    goto v_35590;
v_35591:
    goto v_35592;
v_35593:
    v_36149 = plus2(stack[-1], v_36149);
    env = stack[-16];
    stack[-10] = v_36149;
    v_36149 = stack[0];
    v_36149 = qcdr(v_36149);
    stack[0] = v_36149;
    goto v_35578;
v_35577:
    goto v_35606;
v_35602:
    stack[0] = stack[-10];
    goto v_35603;
v_35604:
    v_36149 = qvalue(elt(env, 7)); // varlist!*
    v_36149 = Llength(nil, v_36149);
    env = stack[-16];
    v_36149 = sub1(v_36149);
    env = stack[-16];
    goto v_35605;
v_35606:
    goto v_35602;
v_35603:
    goto v_35604;
v_35605:
    v_36149 = plus2(stack[0], v_36149);
    env = stack[-16];
    stack[-10] = v_36149;
v_35540:
    v_36149 = qvalue(elt(env, 6)); // gg!*
    v_36149 = Lreverse(nil, v_36149);
    env = stack[-16];
    stack[-15] = v_36149;
v_35615:
    v_36149 = stack[-15];
    if (v_36149 == nil) goto v_35618;
    goto v_35627;
v_35623:
    v_36150 = qvalue(elt(env, 8)); // bv!*
    goto v_35624;
v_35625:
    v_36149 = stack[-15];
    v_36149 = qcar(v_36149);
    v_36149 = qcar(v_36149);
    goto v_35626;
v_35627:
    goto v_35623;
v_35624:
    goto v_35625;
v_35626:
    v_36149 = *(LispObject *)((char *)v_36150 + (CELL-TAG_VECTOR) + (((intptr_t)v_36149-TAG_FIXNUM)/(16/CELL)));
    if (v_36149 == nil) goto v_35622;
    else goto v_35618;
v_35622:
    goto v_35619;
v_35618:
    goto v_35614;
v_35619:
    v_36149 = stack[-15];
    v_36149 = qcdr(v_36149);
    stack[-15] = v_36149;
    goto v_35615;
v_35614:
    v_36149 = stack[-15];
    if (v_36149 == nil) goto v_35639;
    goto v_35649;
v_35645:
    v_36149 = stack[-15];
    v_36149 = qcar(v_36149);
    v_36149 = qcdr(v_36149);
    v_36150 = qcar(v_36149);
    goto v_35646;
v_35647:
    v_36149 = qvalue(elt(env, 6)); // gg!*
    v_36149 = qcar(v_36149);
    v_36149 = qcdr(v_36149);
    v_36149 = qcar(v_36149);
    goto v_35648;
v_35649:
    goto v_35645;
v_35646:
    goto v_35647;
v_35648:
    if (equal(v_36150, v_36149)) goto v_35643;
    else goto v_35644;
v_35643:
    v_36149 = stack[-11];
    v_36150 = stack[-15];
    v_36150 = qcar(v_36150);
    v_36150 = qcdr(v_36150);
    v_36150 = qcar(v_36150);
    stack[-11] = v_36150;
    v_36150 = qvalue(elt(env, 3)); // !*trinvbase
    if (v_36150 == nil) goto v_35666;
    goto v_35675;
v_35671:
    v_36150 = stack[-11];
    goto v_35672;
v_35673:
    goto v_35674;
v_35675:
    goto v_35671;
v_35672:
    goto v_35673;
v_35674:
    v_36149 = (LispObject)greaterp2(v_36150, v_36149);
    v_36149 = v_36149 ? lisp_true : nil;
    env = stack[-16];
    if (v_36149 == nil) goto v_35666;
    v_36149 = Lterpri(nil, 0);
    env = stack[-16];
    v_36149 = elt(env, 9); // "---------- ORDER = "
    v_36149 = Lprinc(nil, v_36149);
    env = stack[-16];
    v_36149 = qvalue(elt(env, 6)); // gg!*
    v_36149 = qcar(v_36149);
    v_36149 = qcdr(v_36149);
    v_36149 = qcar(v_36149);
    v_36149 = Lprinc(nil, v_36149);
    env = stack[-16];
    v_36149 = elt(env, 10); // " ----------"
    v_36149 = Lprinc(nil, v_36149);
    env = stack[-16];
    v_36149 = Lterpri(nil, 0);
    env = stack[-16];
    v_36149 = Lterpri(nil, 0);
    env = stack[-16];
    goto v_35664;
v_35666:
v_35664:
    goto v_35701;
v_35697:
    v_36150 = stack[-11];
    goto v_35698;
v_35699:
    v_36149 = stack[-10];
    goto v_35700;
v_35701:
    goto v_35697;
v_35698:
    goto v_35699;
v_35700:
    v_36149 = (LispObject)greaterp2(v_36150, v_36149);
    v_36149 = v_36149 ? lisp_true : nil;
    env = stack[-16];
    if (v_36149 == nil) goto v_35695;
    goto v_35711;
v_35705:
    v_36151 = nil;
    goto v_35706;
v_35707:
    v_36150 = qvalue(elt(env, 6)); // gg!*
    goto v_35708;
v_35709:
    v_36149 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35710;
v_35711:
    goto v_35705;
v_35706:
    goto v_35707;
v_35708:
    goto v_35709;
v_35710:
    fn = elt(env, 18); // redall
    v_36149 = (*qfnn(fn))(fn, 3, v_36151, v_36150, v_36149);
    env = stack[-16];
    qvalue(elt(env, 6)) = v_36149; // gg!*
    goto v_35720;
v_35716:
    v_36150 = qvalue(elt(env, 6)); // gg!*
    goto v_35717;
v_35718:
    v_36149 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35719;
v_35720:
    goto v_35716;
v_35717:
    goto v_35718;
v_35719:
    fn = elt(env, 19); // newbasis
    v_36149 = (*qfn2(fn))(fn, v_36150, v_36149);
    env = stack[-16];
    v_36149 = nil;
    v_36149 = ncons(v_36149);
    env = stack[-16];
    qvalue(elt(env, 11)) = v_36149; // alglist!*
    goto v_35730;
v_35726:
    stack[-9] = elt(env, 12); // list
    goto v_35727;
v_35728:
    v_36149 = qvalue(elt(env, 6)); // gg!*
    stack[-8] = v_36149;
    v_36149 = stack[-8];
    if (v_36149 == nil) goto v_35741;
    else goto v_35742;
v_35741:
    v_36149 = nil;
    goto v_35736;
v_35742:
    v_36149 = stack[-8];
    v_36149 = qcar(v_36149);
    goto v_35754;
v_35750:
    stack[-4] = elt(env, 13); // plus
    goto v_35751;
v_35752:
    goto v_35766;
v_35762:
    v_36150 = qvalue(elt(env, 14)); // gv!*
    goto v_35763;
v_35764:
    v_36149 = qcar(v_36149);
    goto v_35765;
v_35766:
    goto v_35762;
v_35763:
    goto v_35764;
v_35765:
    v_36149 = *(LispObject *)((char *)v_36150 + (CELL-TAG_VECTOR) + (((intptr_t)v_36149-TAG_FIXNUM)/(16/CELL)));
    stack[-3] = v_36149;
    v_36149 = stack[-3];
    if (v_36149 == nil) goto v_35773;
    else goto v_35774;
v_35773:
    v_36149 = nil;
    goto v_35760;
v_35774:
    v_36149 = stack[-3];
    v_36149 = qcar(v_36149);
    goto v_35787;
v_35783:
    v_36150 = ncons(v_36149);
    env = stack[-16];
    goto v_35784;
v_35785:
    v_36149 = qvalue(elt(env, 7)); // varlist!*
    goto v_35786;
v_35787:
    goto v_35783;
v_35784:
    goto v_35785;
v_35786:
    fn = elt(env, 21); // !*di2q
    v_36149 = (*qfn2(fn))(fn, v_36150, v_36149);
    env = stack[-16];
    fn = elt(env, 22); // prepsq
    v_36149 = (*qfn1(fn))(fn, v_36149);
    env = stack[-16];
    v_36149 = ncons(v_36149);
    env = stack[-16];
    stack[-1] = v_36149;
    stack[-2] = v_36149;
v_35761:
    v_36149 = stack[-3];
    v_36149 = qcdr(v_36149);
    stack[-3] = v_36149;
    v_36149 = stack[-3];
    if (v_36149 == nil) goto v_35795;
    else goto v_35796;
v_35795:
    v_36149 = stack[-2];
    goto v_35760;
v_35796:
    goto v_35804;
v_35800:
    stack[0] = stack[-1];
    goto v_35801;
v_35802:
    v_36149 = stack[-3];
    v_36149 = qcar(v_36149);
    goto v_35816;
v_35812:
    v_36150 = ncons(v_36149);
    env = stack[-16];
    goto v_35813;
v_35814:
    v_36149 = qvalue(elt(env, 7)); // varlist!*
    goto v_35815;
v_35816:
    goto v_35812;
v_35813:
    goto v_35814;
v_35815:
    fn = elt(env, 21); // !*di2q
    v_36149 = (*qfn2(fn))(fn, v_36150, v_36149);
    env = stack[-16];
    fn = elt(env, 22); // prepsq
    v_36149 = (*qfn1(fn))(fn, v_36149);
    env = stack[-16];
    v_36149 = ncons(v_36149);
    env = stack[-16];
    goto v_35803;
v_35804:
    goto v_35800;
v_35801:
    goto v_35802;
v_35803:
    v_36149 = Lrplacd(nil, stack[0], v_36149);
    env = stack[-16];
    v_36149 = stack[-1];
    v_36149 = qcdr(v_36149);
    stack[-1] = v_36149;
    goto v_35761;
v_35760:
    goto v_35753;
v_35754:
    goto v_35750;
v_35751:
    goto v_35752;
v_35753:
    v_36149 = cons(stack[-4], v_36149);
    env = stack[-16];
    v_36149 = ncons(v_36149);
    env = stack[-16];
    stack[-6] = v_36149;
    stack[-7] = v_36149;
v_35737:
    v_36149 = stack[-8];
    v_36149 = qcdr(v_36149);
    stack[-8] = v_36149;
    v_36149 = stack[-8];
    if (v_36149 == nil) goto v_35826;
    else goto v_35827;
v_35826:
    v_36149 = stack[-7];
    goto v_35736;
v_35827:
    goto v_35835;
v_35831:
    stack[-5] = stack[-6];
    goto v_35832;
v_35833:
    v_36149 = stack[-8];
    v_36149 = qcar(v_36149);
    goto v_35846;
v_35842:
    stack[-4] = elt(env, 13); // plus
    goto v_35843;
v_35844:
    goto v_35858;
v_35854:
    v_36150 = qvalue(elt(env, 14)); // gv!*
    goto v_35855;
v_35856:
    v_36149 = qcar(v_36149);
    goto v_35857;
v_35858:
    goto v_35854;
v_35855:
    goto v_35856;
v_35857:
    v_36149 = *(LispObject *)((char *)v_36150 + (CELL-TAG_VECTOR) + (((intptr_t)v_36149-TAG_FIXNUM)/(16/CELL)));
    stack[-3] = v_36149;
    v_36149 = stack[-3];
    if (v_36149 == nil) goto v_35865;
    else goto v_35866;
v_35865:
    v_36149 = nil;
    goto v_35852;
v_35866:
    v_36149 = stack[-3];
    v_36149 = qcar(v_36149);
    goto v_35879;
v_35875:
    v_36150 = ncons(v_36149);
    env = stack[-16];
    goto v_35876;
v_35877:
    v_36149 = qvalue(elt(env, 7)); // varlist!*
    goto v_35878;
v_35879:
    goto v_35875;
v_35876:
    goto v_35877;
v_35878:
    fn = elt(env, 21); // !*di2q
    v_36149 = (*qfn2(fn))(fn, v_36150, v_36149);
    env = stack[-16];
    fn = elt(env, 22); // prepsq
    v_36149 = (*qfn1(fn))(fn, v_36149);
    env = stack[-16];
    v_36149 = ncons(v_36149);
    env = stack[-16];
    stack[-1] = v_36149;
    stack[-2] = v_36149;
v_35853:
    v_36149 = stack[-3];
    v_36149 = qcdr(v_36149);
    stack[-3] = v_36149;
    v_36149 = stack[-3];
    if (v_36149 == nil) goto v_35887;
    else goto v_35888;
v_35887:
    v_36149 = stack[-2];
    goto v_35852;
v_35888:
    goto v_35896;
v_35892:
    stack[0] = stack[-1];
    goto v_35893;
v_35894:
    v_36149 = stack[-3];
    v_36149 = qcar(v_36149);
    goto v_35908;
v_35904:
    v_36150 = ncons(v_36149);
    env = stack[-16];
    goto v_35905;
v_35906:
    v_36149 = qvalue(elt(env, 7)); // varlist!*
    goto v_35907;
v_35908:
    goto v_35904;
v_35905:
    goto v_35906;
v_35907:
    fn = elt(env, 21); // !*di2q
    v_36149 = (*qfn2(fn))(fn, v_36150, v_36149);
    env = stack[-16];
    fn = elt(env, 22); // prepsq
    v_36149 = (*qfn1(fn))(fn, v_36149);
    env = stack[-16];
    v_36149 = ncons(v_36149);
    env = stack[-16];
    goto v_35895;
v_35896:
    goto v_35892;
v_35893:
    goto v_35894;
v_35895:
    v_36149 = Lrplacd(nil, stack[0], v_36149);
    env = stack[-16];
    v_36149 = stack[-1];
    v_36149 = qcdr(v_36149);
    stack[-1] = v_36149;
    goto v_35853;
v_35852:
    goto v_35845;
v_35846:
    goto v_35842;
v_35843:
    goto v_35844;
v_35845:
    v_36149 = cons(stack[-4], v_36149);
    env = stack[-16];
    v_36149 = ncons(v_36149);
    env = stack[-16];
    goto v_35834;
v_35835:
    goto v_35831;
v_35832:
    goto v_35833;
v_35834:
    v_36149 = Lrplacd(nil, stack[-5], v_36149);
    env = stack[-16];
    v_36149 = stack[-6];
    v_36149 = qcdr(v_36149);
    stack[-6] = v_36149;
    goto v_35737;
v_35736:
    goto v_35729;
v_35730:
    goto v_35726;
v_35727:
    goto v_35728;
v_35729:
    v_36149 = cons(stack[-9], v_36149);
    env = stack[-16];
    qvalue(elt(env, 15)) = v_36149; // invtempbasis
    v_36149 = elt(env, 16); // "Maximum degree bound exceeded."
    fn = elt(env, 23); // rederr
    v_36149 = (*qfn1(fn))(fn, v_36149);
    env = stack[-16];
    goto v_35693;
v_35695:
v_35693:
    goto v_35924;
v_35920:
    v_36150 = qvalue(elt(env, 4)); // maxord!*
    goto v_35921;
v_35922:
    v_36149 = qvalue(elt(env, 6)); // gg!*
    v_36149 = qcar(v_36149);
    v_36149 = qcdr(v_36149);
    v_36149 = qcar(v_36149);
    goto v_35923;
v_35924:
    goto v_35920;
v_35921:
    goto v_35922;
v_35923:
    fn = elt(env, 24); // max
    v_36149 = (*qfn2(fn))(fn, v_36150, v_36149);
    env = stack[-16];
    qvalue(elt(env, 4)) = v_36149; // maxord!*
    goto v_35939;
v_35935:
    v_36149 = qvalue(elt(env, 6)); // gg!*
    v_36149 = qcar(v_36149);
    v_36149 = qcdr(v_36149);
    v_36150 = qcar(v_36149);
    goto v_35936;
v_35937:
    v_36149 = qvalue(elt(env, 4)); // maxord!*
    goto v_35938;
v_35939:
    goto v_35935;
v_35936:
    goto v_35937;
v_35938:
    v_36149 = (LispObject)lessp2(v_36150, v_36149);
    v_36149 = v_36149 ? lisp_true : nil;
    env = stack[-16];
    if (v_36149 == nil) goto v_35933;
    v_36149 = lisp_true;
    stack[-12] = v_36149;
    goto v_35931;
v_35933:
v_35931:
    goto v_35642;
v_35644:
v_35642:
    v_36149 = stack[-12];
    if (v_36149 == nil) goto v_35950;
    goto v_35541;
v_35950:
    v_36149 = stack[-15];
    v_36149 = qcar(v_36149);
    v_36149 = qcar(v_36149);
    v_36150 = v_36149;
    goto v_35959;
v_35955:
    v_36151 = qvalue(elt(env, 14)); // gv!*
    goto v_35956;
v_35957:
    v_36149 = v_36150;
    goto v_35958;
v_35959:
    goto v_35955;
v_35956:
    goto v_35957;
v_35958:
    v_36149 = *(LispObject *)((char *)v_36151 + (CELL-TAG_VECTOR) + (((intptr_t)v_36149-TAG_FIXNUM)/(16/CELL)));
    stack[-6] = v_36149;
    goto v_35969;
v_35963:
    v_36151 = qvalue(elt(env, 8)); // bv!*
    goto v_35964;
v_35965:
    goto v_35966;
v_35967:
    v_36149 = nil;
    goto v_35968;
v_35969:
    goto v_35963;
v_35964:
    goto v_35965;
v_35966:
    goto v_35967;
v_35968:
    *(LispObject *)((char *)v_36151 + (CELL-TAG_VECTOR) + (((intptr_t)v_36150-TAG_FIXNUM)/(16/CELL))) = v_36149;
    v_36149 = stack[-6];
    fn = elt(env, 25); // ljet
    v_36149 = (*qfn1(fn))(fn, v_36149);
    env = stack[-16];
    fn = elt(env, 26); // class
    v_36149 = (*qfn1(fn))(fn, v_36149);
    env = stack[-16];
    fn = elt(env, 27); // nonmult
    v_36149 = (*qfn1(fn))(fn, v_36149);
    env = stack[-16];
    stack[-5] = v_36149;
v_35980:
    v_36149 = stack[-5];
    if (v_36149 == nil) goto v_35984;
    else goto v_35985;
v_35984:
    goto v_35979;
v_35985:
    v_36149 = stack[-5];
    v_36149 = qcar(v_36149);
    stack[0] = v_36149;
    v_36149 = qvalue(elt(env, 17)); // ng!*
    v_36149 = add1(v_36149);
    env = stack[-16];
    qvalue(elt(env, 17)) = v_36149; // ng!*
    goto v_35998;
v_35994:
    v_36150 = stack[-6];
    goto v_35995;
v_35996:
    v_36149 = stack[0];
    goto v_35997;
v_35998:
    goto v_35994;
v_35995:
    goto v_35996;
v_35997:
    fn = elt(env, 28); // pdmult
    v_36149 = (*qfn2(fn))(fn, v_36150, v_36149);
    env = stack[-16];
    v_36152 = v_36149;
    goto v_36007;
v_36001:
    v_36151 = qvalue(elt(env, 14)); // gv!*
    goto v_36002;
v_36003:
    v_36150 = qvalue(elt(env, 17)); // ng!*
    goto v_36004;
v_36005:
    v_36149 = v_36152;
    goto v_36006;
v_36007:
    goto v_36001;
v_36002:
    goto v_36003;
v_36004:
    goto v_36005;
v_36006:
    *(LispObject *)((char *)v_36151 + (CELL-TAG_VECTOR) + (((intptr_t)v_36150-TAG_FIXNUM)/(16/CELL))) = v_36149;
    goto v_36017;
v_36011:
    v_36151 = qvalue(elt(env, 8)); // bv!*
    goto v_36012;
v_36013:
    v_36150 = qvalue(elt(env, 17)); // ng!*
    goto v_36014;
v_36015:
    v_36149 = lisp_true;
    goto v_36016;
v_36017:
    goto v_36011;
v_36012:
    goto v_36013;
v_36014:
    goto v_36015;
v_36016:
    *(LispObject *)((char *)v_36151 + (CELL-TAG_VECTOR) + (((intptr_t)v_36150-TAG_FIXNUM)/(16/CELL))) = v_36149;
    goto v_36028;
v_36022:
    stack[-1] = qvalue(elt(env, 6)); // gg!*
    goto v_36023;
v_36024:
    goto v_36036;
v_36032:
    stack[0] = qvalue(elt(env, 17)); // ng!*
    goto v_36033;
v_36034:
    v_36149 = v_36152;
    fn = elt(env, 25); // ljet
    v_36149 = (*qfn1(fn))(fn, v_36149);
    env = stack[-16];
    goto v_36035;
v_36036:
    goto v_36032;
v_36033:
    goto v_36034;
v_36035:
    v_36149 = cons(stack[0], v_36149);
    env = stack[-16];
    v_36150 = ncons(v_36149);
    env = stack[-16];
    goto v_36025;
v_36026:
    v_36149 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36027;
v_36028:
    goto v_36022;
v_36023:
    goto v_36024;
v_36025:
    goto v_36026;
v_36027:
    fn = elt(env, 18); // redall
    v_36149 = (*qfnn(fn))(fn, 3, stack[-1], v_36150, v_36149);
    env = stack[-16];
    qvalue(elt(env, 6)) = v_36149; // gg!*
    v_36149 = qvalue(elt(env, 1)); // thirdway!*
    if (v_36149 == nil) goto v_36044;
    goto v_36051;
v_36047:
    v_36150 = qvalue(elt(env, 6)); // gg!*
    goto v_36048;
v_36049:
    v_36149 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36050;
v_36051:
    goto v_36047;
v_36048:
    goto v_36049;
v_36050:
    fn = elt(env, 19); // newbasis
    v_36149 = (*qfn2(fn))(fn, v_36150, v_36149);
    env = stack[-16];
    goto v_36042;
v_36044:
    v_36149 = qvalue(elt(env, 2)); // shortway!*
    if (v_36149 == nil) goto v_36055;
    v_36149 = qvalue(elt(env, 6)); // gg!*
    stack[-4] = v_36149;
v_36060:
    v_36149 = stack[-4];
    if (v_36149 == nil) goto v_36064;
    else goto v_36065;
v_36064:
    goto v_36059;
v_36065:
    v_36149 = stack[-4];
    v_36149 = qcar(v_36149);
    v_36151 = v_36149;
    goto v_36079;
v_36075:
    v_36149 = v_36151;
    v_36150 = qcar(v_36149);
    goto v_36076;
v_36077:
    v_36149 = qvalue(elt(env, 17)); // ng!*
    goto v_36078;
v_36079:
    goto v_36075;
v_36076:
    goto v_36077;
v_36078:
    if (equal(v_36150, v_36149)) goto v_36074;
    goto v_36089;
v_36083:
    stack[-3] = qvalue(elt(env, 14)); // gv!*
    goto v_36084;
v_36085:
    v_36149 = v_36151;
    stack[-2] = qcar(v_36149);
    goto v_36086;
v_36087:
    goto v_36100;
v_36094:
    goto v_36105;
v_36101:
    v_36149 = qvalue(elt(env, 14)); // gv!*
    goto v_36102;
v_36103:
    v_36150 = v_36151;
    v_36150 = qcar(v_36150);
    goto v_36104;
v_36105:
    goto v_36101;
v_36102:
    goto v_36103;
v_36104:
    stack[-1] = *(LispObject *)((char *)v_36149 + (CELL-TAG_VECTOR) + (((intptr_t)v_36150-TAG_FIXNUM)/(16/CELL)));
    goto v_36095;
v_36096:
    goto v_36116;
v_36112:
    stack[0] = qvalue(elt(env, 17)); // ng!*
    goto v_36113;
v_36114:
    goto v_36123;
v_36119:
    v_36150 = qvalue(elt(env, 14)); // gv!*
    goto v_36120;
v_36121:
    v_36149 = qvalue(elt(env, 17)); // ng!*
    goto v_36122;
v_36123:
    goto v_36119;
v_36120:
    goto v_36121;
v_36122:
    v_36149 = *(LispObject *)((char *)v_36150 + (CELL-TAG_VECTOR) + (((intptr_t)v_36149-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 25); // ljet
    v_36149 = (*qfn1(fn))(fn, v_36149);
    env = stack[-16];
    goto v_36115;
v_36116:
    goto v_36112;
v_36113:
    goto v_36114;
v_36115:
    v_36149 = cons(stack[0], v_36149);
    env = stack[-16];
    v_36150 = ncons(v_36149);
    env = stack[-16];
    goto v_36097;
v_36098:
    v_36149 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36099;
v_36100:
    goto v_36094;
v_36095:
    goto v_36096;
v_36097:
    goto v_36098;
v_36099:
    fn = elt(env, 29); // nf
    v_36149 = (*qfnn(fn))(fn, 3, stack[-1], v_36150, v_36149);
    env = stack[-16];
    goto v_36088;
v_36089:
    goto v_36083;
v_36084:
    goto v_36085;
v_36086:
    goto v_36087;
v_36088:
    *(LispObject *)((char *)stack[-3] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-2]-TAG_FIXNUM)/(16/CELL))) = v_36149;
    goto v_36072;
v_36074:
v_36072:
    v_36149 = stack[-4];
    v_36149 = qcdr(v_36149);
    stack[-4] = v_36149;
    goto v_36060;
v_36059:
    goto v_36042;
v_36055:
v_36042:
    v_36149 = stack[-5];
    v_36149 = qcdr(v_36149);
    stack[-5] = v_36149;
    goto v_35980;
v_35979:
    goto v_35540;
v_35639:
v_35541:
    fn = elt(env, 30); // stat
    v_36149 = (*qfnn(fn))(fn, 0);
    env = stack[-16];
    goto v_36144;
v_36140:
    v_36150 = stack[-11];
    goto v_36141;
v_36142:
    v_36149 = stack[-10];
    goto v_36143;
v_36144:
    goto v_36140;
v_36141:
    goto v_36142;
v_36143:
    v_36149 = (LispObject)lesseq2(v_36150, v_36149);
    v_36149 = v_36149 ? lisp_true : nil;
    env = stack[-16];
    if (v_36149 == nil) goto v_36138;
    v_36149 = qvalue(elt(env, 6)); // gg!*
    fn = elt(env, 31); // dim
    v_36149 = (*qfn1(fn))(fn, v_36149);
    goto v_36136;
v_36138:
v_36136:
    v_36149 = nil;
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_36149);
}



// Code for distri_pol

static LispObject CC_distri_pol(LispObject env,
                         LispObject v_35525)
{
    env = qenv(env);
    LispObject v_35646, v_35647;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35525);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_35525;
// end of prologue
    v_35646 = stack[-1];
    if (v_35646 == nil) goto v_35529;
    else goto v_35530;
v_35529:
    v_35646 = nil;
    goto v_35528;
v_35530:
    v_35646 = stack[-1];
    if (!consp(v_35646)) goto v_35533;
    else goto v_35534;
v_35533:
    v_35646 = stack[-1];
    goto v_35528;
v_35534:
    v_35646 = stack[-1];
    v_35646 = qcdr(v_35646);
    if (v_35646 == nil) goto v_35538;
    goto v_35546;
v_35542:
    v_35646 = stack[-1];
    v_35646 = qcar(v_35646);
    v_35646 = ncons(v_35646);
    env = stack[-3];
    stack[0] = CC_distri_pol(elt(env, 0), v_35646);
    env = stack[-3];
    goto v_35543;
v_35544:
    v_35646 = stack[-1];
    v_35646 = qcdr(v_35646);
    v_35646 = CC_distri_pol(elt(env, 0), v_35646);
    env = stack[-3];
    goto v_35545;
v_35546:
    goto v_35542;
v_35543:
    goto v_35544;
v_35545:
    {
        LispObject v_35651 = stack[0];
        fn = elt(env, 1); // addfd
        return (*qfn2(fn))(fn, v_35651, v_35646);
    }
v_35538:
    v_35646 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_35646;
    v_35646 = stack[-1];
    stack[-2] = v_35646;
v_35564:
    v_35646 = stack[-2];
    if (!consp(v_35646)) goto v_35572;
    v_35646 = stack[-2];
    v_35646 = qcdr(v_35646);
    v_35646 = (v_35646 == nil ? lisp_true : nil);
    goto v_35570;
v_35572:
    v_35646 = nil;
    goto v_35570;
    v_35646 = nil;
v_35570:
    if (v_35646 == nil) goto v_35567;
    else goto v_35568;
v_35567:
    goto v_35563;
v_35568:
    goto v_35586;
v_35582:
    goto v_35583;
v_35584:
    goto v_35594;
v_35590:
    v_35646 = stack[-2];
    v_35646 = qcar(v_35646);
    v_35647 = qcar(v_35646);
    goto v_35591;
v_35592:
    v_35646 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35593;
v_35594:
    goto v_35590;
v_35591:
    goto v_35592;
v_35593:
    v_35646 = cons(v_35647, v_35646);
    env = stack[-3];
    v_35646 = ncons(v_35646);
    env = stack[-3];
    goto v_35585;
v_35586:
    goto v_35582;
v_35583:
    goto v_35584;
v_35585:
    fn = elt(env, 2); // multf
    v_35646 = (*qfn2(fn))(fn, stack[0], v_35646);
    env = stack[-3];
    stack[0] = v_35646;
    v_35646 = stack[-2];
    v_35646 = qcar(v_35646);
    v_35646 = qcdr(v_35646);
    stack[-2] = v_35646;
    goto v_35564;
v_35563:
    v_35646 = stack[-2];
    if (!consp(v_35646)) goto v_35604;
    else goto v_35605;
v_35604:
    goto v_35612;
v_35608:
    v_35647 = stack[0];
    goto v_35609;
v_35610:
    v_35646 = stack[-2];
    goto v_35611;
v_35612:
    goto v_35608;
v_35609:
    goto v_35610;
v_35611:
    {
        fn = elt(env, 2); // multf
        return (*qfn2(fn))(fn, v_35647, v_35646);
    }
v_35605:
    goto v_35622;
v_35618:
    goto v_35629;
v_35625:
    stack[-1] = stack[0];
    goto v_35626;
v_35627:
    v_35646 = stack[-2];
    v_35646 = qcar(v_35646);
    v_35646 = ncons(v_35646);
    env = stack[-3];
    v_35646 = CC_distri_pol(elt(env, 0), v_35646);
    env = stack[-3];
    goto v_35628;
v_35629:
    goto v_35625;
v_35626:
    goto v_35627;
v_35628:
    fn = elt(env, 2); // multf
    v_35646 = (*qfn2(fn))(fn, stack[-1], v_35646);
    env = stack[-3];
    stack[-1] = CC_distri_pol(elt(env, 0), v_35646);
    env = stack[-3];
    goto v_35619;
v_35620:
    goto v_35641;
v_35637:
    goto v_35638;
v_35639:
    v_35646 = stack[-2];
    v_35646 = qcdr(v_35646);
    v_35646 = CC_distri_pol(elt(env, 0), v_35646);
    env = stack[-3];
    goto v_35640;
v_35641:
    goto v_35637;
v_35638:
    goto v_35639;
v_35640:
    fn = elt(env, 2); // multf
    v_35646 = (*qfn2(fn))(fn, stack[0], v_35646);
    env = stack[-3];
    v_35646 = CC_distri_pol(elt(env, 0), v_35646);
    env = stack[-3];
    goto v_35621;
v_35622:
    goto v_35618;
v_35619:
    goto v_35620;
v_35621:
    {
        LispObject v_35652 = stack[-1];
        fn = elt(env, 1); // addfd
        return (*qfn2(fn))(fn, v_35652, v_35646);
    }
    v_35646 = nil;
    goto v_35528;
    v_35646 = nil;
v_35528:
    return onevalue(v_35646);
}



// Code for ofsf_ordrelp

static LispObject CC_ofsf_ordrelp(LispObject env,
                         LispObject v_35525, LispObject v_35526)
{
    env = qenv(env);
    LispObject v_35544, v_35545, v_35546;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_35545 = v_35526;
    v_35544 = v_35525;
// end of prologue
    goto v_35532;
v_35528:
    goto v_35529;
v_35530:
    goto v_35538;
v_35534:
    goto v_35535;
v_35536:
    v_35546 = elt(env, 1); // (equal neq leq lessp geq greaterp)
    goto v_35537;
v_35538:
    goto v_35534;
v_35535:
    goto v_35536;
v_35537:
    v_35544 = Lmemq(nil, v_35544, v_35546);
    v_35544 = qcdr(v_35544);
    goto v_35531;
v_35532:
    goto v_35528;
v_35529:
    goto v_35530;
v_35531:
    v_35544 = Lmemq(nil, v_35545, v_35544);
    return onevalue(v_35544);
}



// Code for yetunknowntypeeval

static LispObject CC_yetunknowntypeeval(LispObject env,
                         LispObject v_35525, LispObject v_35526)
{
    env = qenv(env);
    LispObject v_35543, v_35544;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_35525,v_35526);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_35526;
    v_35543 = v_35525;
// end of prologue
    goto v_35533;
v_35529:
    goto v_35539;
v_35535:
    v_35544 = v_35543;
    goto v_35536;
v_35537:
    v_35543 = stack[0];
    goto v_35538;
v_35539:
    goto v_35535;
v_35536:
    goto v_35537;
v_35538:
    fn = elt(env, 1); // eval!-yetunknowntypeexpr
    v_35544 = (*qfn2(fn))(fn, v_35544, v_35543);
    env = stack[-1];
    goto v_35530;
v_35531:
    v_35543 = stack[0];
    goto v_35532;
v_35533:
    goto v_35529;
v_35530:
    goto v_35531;
v_35532:
    {
        fn = elt(env, 2); // reval1
        return (*qfn2(fn))(fn, v_35544, v_35543);
    }
}



// Code for depend!-l

static LispObject CC_dependKl(LispObject env,
                         LispObject v_35525, LispObject v_35526)
{
    env = qenv(env);
    LispObject v_35554, v_35555;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_35525,v_35526);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_35526;
    stack[-1] = v_35525;
// end of prologue
v_35530:
    v_35554 = stack[-1];
    if (v_35554 == nil) goto v_35533;
    else goto v_35534;
v_35533:
    v_35554 = nil;
    goto v_35529;
v_35534:
    goto v_35544;
v_35540:
    v_35554 = stack[-1];
    v_35554 = qcar(v_35554);
    fn = elt(env, 1); // simp
    v_35555 = (*qfn1(fn))(fn, v_35554);
    env = stack[-2];
    goto v_35541;
v_35542:
    v_35554 = stack[0];
    goto v_35543;
v_35544:
    goto v_35540;
v_35541:
    goto v_35542;
v_35543:
    fn = elt(env, 2); // depend!-sq
    v_35554 = (*qfn2(fn))(fn, v_35555, v_35554);
    env = stack[-2];
    if (v_35554 == nil) goto v_35538;
    v_35554 = lisp_true;
    goto v_35529;
v_35538:
    v_35554 = stack[-1];
    v_35554 = qcdr(v_35554);
    stack[-1] = v_35554;
    goto v_35530;
    v_35554 = nil;
v_35529:
    return onevalue(v_35554);
}



// Code for rl_print!*fof

static LispObject CC_rl_printHfof(LispObject env,
                         LispObject v_35525)
{
    env = qenv(env);
    LispObject v_35530;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35525);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_35530 = v_35525;
// end of prologue
    fn = elt(env, 1); // reval
    v_35530 = (*qfn1(fn))(fn, v_35530);
    env = stack[0];
    {
        fn = elt(env, 2); // maprin
        return (*qfn1(fn))(fn, v_35530);
    }
}



// Code for unary

static LispObject CC_unary(LispObject env,
                         LispObject v_35525, LispObject v_35526)
{
    env = qenv(env);
    LispObject v_35559, v_35560;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_35525,v_35526);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_35526;
    stack[-1] = v_35525;
// end of prologue
    v_35559 = elt(env, 1); // "<apply>"
    fn = elt(env, 6); // printout
    v_35559 = (*qfn1(fn))(fn, v_35559);
    env = stack[-2];
    v_35559 = elt(env, 2); // "<"
    v_35559 = Lprinc(nil, v_35559);
    env = stack[-2];
    v_35559 = stack[0];
    v_35559 = Lprinc(nil, v_35559);
    env = stack[-2];
    v_35559 = elt(env, 3); // "/>"
    v_35559 = Lprinc(nil, v_35559);
    env = stack[-2];
    goto v_35543;
v_35539:
    v_35560 = qvalue(elt(env, 4)); // indent
    goto v_35540;
v_35541:
    v_35559 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_35542;
v_35543:
    goto v_35539;
v_35540:
    goto v_35541;
v_35542:
    v_35559 = plus2(v_35560, v_35559);
    env = stack[-2];
    qvalue(elt(env, 4)) = v_35559; // indent
    v_35559 = stack[-1];
    v_35559 = qcar(v_35559);
    fn = elt(env, 7); // expression
    v_35559 = (*qfn1(fn))(fn, v_35559);
    env = stack[-2];
    goto v_35554;
v_35550:
    v_35560 = qvalue(elt(env, 4)); // indent
    goto v_35551;
v_35552:
    v_35559 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_35553;
v_35554:
    goto v_35550;
v_35551:
    goto v_35552;
v_35553:
    v_35559 = difference2(v_35560, v_35559);
    env = stack[-2];
    qvalue(elt(env, 4)) = v_35559; // indent
    v_35559 = elt(env, 5); // "</apply>"
    fn = elt(env, 6); // printout
    v_35559 = (*qfn1(fn))(fn, v_35559);
    v_35559 = nil;
    return onevalue(v_35559);
}



// Code for xpwrlcmp

static LispObject CC_xpwrlcmp(LispObject env,
                         LispObject v_35525, LispObject v_35526)
{
    env = qenv(env);
    LispObject v_35612, v_35613;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_35525,v_35526);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_35526;
    stack[-1] = v_35525;
// end of prologue
    v_35612 = stack[-1];
    if (!consp(v_35612)) goto v_35530;
    else goto v_35531;
v_35530:
    v_35612 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35529;
v_35531:
    goto v_35545;
v_35541:
    v_35613 = stack[-1];
    goto v_35542;
v_35543:
    v_35612 = elt(env, 1); // expt
    goto v_35544;
v_35545:
    goto v_35541;
v_35542:
    goto v_35543;
v_35544:
    if (!consp(v_35613)) goto v_35539;
    v_35613 = qcar(v_35613);
    if (v_35613 == v_35612) goto v_35538;
    else goto v_35539;
v_35538:
    goto v_35552;
v_35548:
    v_35612 = stack[-1];
    v_35612 = qcdr(v_35612);
    v_35613 = qcar(v_35612);
    goto v_35549;
v_35550:
    v_35612 = stack[0];
    goto v_35551;
v_35552:
    goto v_35548;
v_35549:
    goto v_35550;
v_35551:
    v_35612 = (equal(v_35613, v_35612) ? lisp_true : nil);
    goto v_35537;
v_35539:
    v_35612 = nil;
    goto v_35537;
    v_35612 = nil;
v_35537:
    if (v_35612 == nil) goto v_35535;
    v_35612 = stack[-1];
    v_35612 = qcdr(v_35612);
    v_35612 = qcdr(v_35612);
    v_35612 = qcar(v_35612);
    {
        fn = elt(env, 3); // getdenom
        return (*qfn1(fn))(fn, v_35612);
    }
v_35535:
    goto v_35573;
v_35569:
    v_35613 = stack[-1];
    goto v_35570;
v_35571:
    v_35612 = elt(env, 2); // sqrt
    goto v_35572;
v_35573:
    goto v_35569;
v_35570:
    goto v_35571;
v_35572:
    if (!consp(v_35613)) goto v_35567;
    v_35613 = qcar(v_35613);
    if (v_35613 == v_35612) goto v_35566;
    else goto v_35567;
v_35566:
    goto v_35581;
v_35577:
    v_35612 = stack[-1];
    v_35612 = qcdr(v_35612);
    v_35613 = qcar(v_35612);
    goto v_35578;
v_35579:
    v_35612 = stack[0];
    goto v_35580;
v_35581:
    goto v_35577;
v_35578:
    goto v_35579;
v_35580:
    {
        fn = elt(env, 4); // getdenomx
        return (*qfn2(fn))(fn, v_35613, v_35612);
    }
v_35567:
    goto v_35593;
v_35589:
    goto v_35599;
v_35595:
    v_35612 = stack[-1];
    v_35613 = qcar(v_35612);
    goto v_35596;
v_35597:
    v_35612 = stack[0];
    goto v_35598;
v_35599:
    goto v_35595;
v_35596:
    goto v_35597;
v_35598:
    stack[-2] = CC_xpwrlcmp(elt(env, 0), v_35613, v_35612);
    env = stack[-3];
    goto v_35590;
v_35591:
    goto v_35608;
v_35604:
    v_35612 = stack[-1];
    v_35613 = qcdr(v_35612);
    goto v_35605;
v_35606:
    v_35612 = stack[0];
    goto v_35607;
v_35608:
    goto v_35604;
v_35605:
    goto v_35606;
v_35607:
    v_35612 = CC_xpwrlcmp(elt(env, 0), v_35613, v_35612);
    env = stack[-3];
    goto v_35592;
v_35593:
    goto v_35589;
v_35590:
    goto v_35591;
v_35592:
    {
        LispObject v_35617 = stack[-2];
        fn = elt(env, 5); // lcm
        return (*qfn2(fn))(fn, v_35617, v_35612);
    }
    v_35612 = nil;
v_35529:
    return onevalue(v_35612);
}



// Code for ps!:expansion!-point

static LispObject CC_psTexpansionKpoint(LispObject env,
                         LispObject v_35525)
{
    env = qenv(env);
    LispObject v_35568, v_35569, v_35570;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_35570 = v_35525;
// end of prologue
    v_35568 = v_35570;
    if (!consp(v_35568)) goto v_35533;
    else goto v_35534;
v_35533:
    v_35568 = lisp_true;
    goto v_35532;
v_35534:
    goto v_35547;
v_35543:
    v_35568 = v_35570;
    v_35569 = qcar(v_35568);
    goto v_35544;
v_35545:
    v_35568 = elt(env, 1); // !:ps!:
    goto v_35546;
v_35547:
    goto v_35543;
v_35544:
    goto v_35545;
v_35546:
    if (v_35569 == v_35568) goto v_35542;
    v_35568 = v_35570;
    v_35568 = qcar(v_35568);
    if (!symbolp(v_35568)) v_35568 = nil;
    else { v_35568 = qfastgets(v_35568);
           if (v_35568 != nil) { v_35568 = elt(v_35568, 8); // dname
#ifdef RECORD_GET
             if (v_35568 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_35568 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_35568 == SPID_NOPROP) v_35568 = nil; }}
#endif
    goto v_35540;
v_35542:
    v_35568 = nil;
    goto v_35540;
    v_35568 = nil;
v_35540:
    goto v_35532;
    v_35568 = nil;
v_35532:
    if (v_35568 == nil) goto v_35530;
    v_35568 = nil;
    goto v_35528;
v_35530:
    goto v_35565;
v_35561:
    v_35569 = v_35570;
    goto v_35562;
v_35563:
    v_35568 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_35564;
v_35565:
    goto v_35561;
v_35562:
    goto v_35563;
v_35564:
    {
        fn = elt(env, 2); // ps!:getv
        return (*qfn2(fn))(fn, v_35569, v_35568);
    }
    v_35568 = nil;
v_35528:
    return onevalue(v_35568);
}



// Code for appends

static LispObject CC_appends(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_35544, v_35545, v_35546;
    LispObject v_35527, v_35526, v_35525;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "appends");
    va_start(aa, nargs);
    v_35525 = va_arg(aa, LispObject);
    v_35526 = va_arg(aa, LispObject);
    v_35527 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_35527,v_35526,v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_35525,v_35526,v_35527);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_35544 = v_35527;
    v_35545 = v_35526;
    v_35546 = v_35525;
// end of prologue
    goto v_35534;
v_35530:
    stack[0] = v_35546;
    goto v_35531;
v_35532:
    goto v_35541;
v_35537:
    goto v_35538;
v_35539:
    goto v_35540;
v_35541:
    goto v_35537;
v_35538:
    goto v_35539;
v_35540:
    v_35544 = Lappend(nil, v_35545, v_35544);
    goto v_35533;
v_35534:
    goto v_35530;
v_35531:
    goto v_35532;
v_35533:
    {
        LispObject v_35548 = stack[0];
        return Lappend(nil, v_35548, v_35544);
    }
}



// Code for pm!:gensym

static LispObject CC_pmTgensym(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_35540;
    argcheck(nargs, 0, "pm:gensym");
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
    goto v_35534;
v_35528:
    stack[-1] = elt(env, 1); // !?
    goto v_35529;
v_35530:
    stack[0] = elt(env, 2); // !_
    goto v_35531;
v_35532:
    v_35540 = qvalue(elt(env, 3)); // pm!:gensym!-count!*
    v_35540 = add1(v_35540);
    env = stack[-2];
    qvalue(elt(env, 3)) = v_35540; // pm!:gensym!-count!*
    v_35540 = Lexplode(nil, v_35540);
    env = stack[-2];
    goto v_35533;
v_35534:
    goto v_35528;
v_35529:
    goto v_35530;
v_35531:
    goto v_35532;
v_35533:
    v_35540 = list2star(stack[-1], stack[0], v_35540);
        return Lcompress(nil, v_35540);
}



// Code for partitpartdf

static LispObject CC_partitpartdf(LispObject env,
                         LispObject v_35525)
{
    env = qenv(env);
    LispObject v_35549, v_35550;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35525);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35525);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_35550 = v_35525;
// end of prologue
    v_35549 = v_35550;
    v_35549 = qcdr(v_35549);
    if (v_35549 == nil) goto v_35529;
    else goto v_35530;
v_35529:
    v_35549 = v_35550;
    v_35549 = qcar(v_35549);
    fn = elt(env, 1); // !*a2k
    v_35549 = (*qfn1(fn))(fn, v_35549);
    env = stack[-1];
    {
        fn = elt(env, 2); // mknatvec
        return (*qfn1(fn))(fn, v_35549);
    }
v_35530:
    goto v_35545;
v_35541:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35542;
v_35543:
    v_35549 = v_35550;
    fn = elt(env, 3); // simppartdf0
    v_35549 = (*qfn1(fn))(fn, v_35549);
    env = stack[-1];
    goto v_35544;
v_35545:
    goto v_35541;
v_35542:
    goto v_35543;
v_35544:
    v_35549 = cons(stack[0], v_35549);
    return ncons(v_35549);
    v_35549 = nil;
    return onevalue(v_35549);
}



// Code for p_eq_vertex

static LispObject CC_p_eq_vertex(LispObject env,
                         LispObject v_35525, LispObject v_35526)
{
    env = qenv(env);
    LispObject v_35562, v_35563, v_35564, v_35565;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_35563 = v_35526;
    v_35564 = v_35525;
// end of prologue
v_35530:
    v_35562 = v_35564;
    if (v_35562 == nil) goto v_35533;
    else goto v_35534;
v_35533:
    v_35562 = v_35563;
    v_35562 = (v_35562 == nil ? lisp_true : nil);
    goto v_35529;
v_35534:
    v_35562 = v_35563;
    if (v_35562 == nil) goto v_35538;
    else goto v_35539;
v_35538:
    v_35562 = nil;
    goto v_35529;
v_35539:
    goto v_35548;
v_35544:
    v_35562 = v_35564;
    v_35562 = qcar(v_35562);
    v_35565 = qcar(v_35562);
    goto v_35545;
v_35546:
    v_35562 = v_35563;
    v_35562 = qcar(v_35562);
    v_35562 = qcar(v_35562);
    goto v_35547;
v_35548:
    goto v_35544;
v_35545:
    goto v_35546;
v_35547:
    if (v_35565 == v_35562) goto v_35542;
    else goto v_35543;
v_35542:
    v_35562 = v_35564;
    v_35562 = qcdr(v_35562);
    v_35564 = v_35562;
    v_35562 = v_35563;
    v_35562 = qcdr(v_35562);
    v_35563 = v_35562;
    goto v_35530;
v_35543:
    v_35562 = nil;
    goto v_35529;
    v_35562 = nil;
v_35529:
    return onevalue(v_35562);
}



setup_type const u59_setup[] =
{
    {"nrootnn",                 TOO_FEW_2,      CC_nrootnn,    WRONG_NO_2},
    {"makecoeffpairs1",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_makecoeffpairs1},
    {"null+vec+p",              CC_nullLvecLp,  TOO_MANY_1,    WRONG_NO_1},
    {"talp_get-minfct",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_getKminfct},
    {"rl_b2atl",                TOO_FEW_2,      CC_rl_b2atl,   WRONG_NO_2},
    {"ps:expt-erule",           TOO_FEW_2,      CC_psTexptKerule,WRONG_NO_2},
    {"frlp",                    CC_frlp,        TOO_MANY_1,    WRONG_NO_1},
    {"dm-quotient",             TOO_FEW_2,      CC_dmKquotient,WRONG_NO_2},
    {"groebsaveltermbc",        CC_groebsaveltermbc,TOO_MANY_1,WRONG_NO_1},
    {"rand-mons-dense",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_randKmonsKdense},
    {"lispcondp",               CC_lispcondp,   TOO_MANY_1,    WRONG_NO_1},
    {"formclear",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formclear},
    {"cdr_signsort",            TOO_FEW_2,      CC_cdr_signsort,WRONG_NO_2},
    {"extodd",                  CC_extodd,      TOO_MANY_1,    WRONG_NO_1},
    {"sfto_mindeg1",            TOO_FEW_2,      CC_sfto_mindeg1,WRONG_NO_2},
    {"let0",                    CC_let0,        TOO_MANY_1,    WRONG_NO_1},
    {"talp_gaussand",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_gaussand},
    {"mri_dettype",             CC_mri_dettype, TOO_MANY_1,    WRONG_NO_1},
    {"qqe_length-graph-remove-mark",TOO_FEW_2,  CC_qqe_lengthKgraphKremoveKmark,WRONG_NO_2},
    {"rat_leq",                 TOO_FEW_2,      CC_rat_leq,    WRONG_NO_2},
    {"cd_ordatp",               TOO_FEW_2,      CC_cd_ordatp,  WRONG_NO_2},
    {"applyml",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_applyml},
    {"ps:find-order",           CC_psTfindKorder,TOO_MANY_1,   WRONG_NO_1},
    {"subsqnew",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_subsqnew},
    {"groebsimpcontnormalform", CC_groebsimpcontnormalform,TOO_MANY_1,WRONG_NO_1},
    {"tot-asym-indp",           CC_totKasymKindp,TOO_MANY_1,   WRONG_NO_1},
    {"calc_map_tar",            TOO_FEW_2,      CC_calc_map_tar,WRONG_NO_2},
    {"invbase*",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_invbaseH},
    {"distri_pol",              CC_distri_pol,  TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_ordrelp",            TOO_FEW_2,      CC_ofsf_ordrelp,WRONG_NO_2},
    {"yetunknowntypeeval",      TOO_FEW_2,      CC_yetunknowntypeeval,WRONG_NO_2},
    {"depend-l",                TOO_FEW_2,      CC_dependKl,   WRONG_NO_2},
    {"rl_print*fof",            CC_rl_printHfof,TOO_MANY_1,    WRONG_NO_1},
    {"unary",                   TOO_FEW_2,      CC_unary,      WRONG_NO_2},
    {"xpwrlcmp",                TOO_FEW_2,      CC_xpwrlcmp,   WRONG_NO_2},
    {"ps:expansion-point",      CC_psTexpansionKpoint,TOO_MANY_1,WRONG_NO_1},
    {"appends",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_appends},
    {"pm:gensym",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pmTgensym},
    {"partitpartdf",            CC_partitpartdf,TOO_MANY_1,    WRONG_NO_1},
    {"p_eq_vertex",             TOO_FEW_2,      CC_p_eq_vertex,WRONG_NO_2},
    {NULL, (one_args *)"u59", (two_args *)"50441 2886634 6628104", 0}
};

// end of generated code
