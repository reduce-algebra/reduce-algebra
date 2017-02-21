
// $destdir/u22.c        Machine generated C code

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



// Code for exc

static LispObject CC_exc(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12702, v_12703;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12702 = v_12689;
    v_12703 = v_12688;
// end of prologue
    v_12703 = qcdr(v_12703);
    if (v_12703 == nil) goto v_12693;
    else goto v_12694;
v_12693:
    goto v_12692;
v_12694:
    v_12702 = (v_12702 == nil ? lisp_true : nil);
    goto v_12692;
    v_12702 = nil;
v_12692:
    return onevalue(v_12702);
}



// Code for yypeek

static LispObject CC_yypeek(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12699;
    LispObject fn;
    argcheck(nargs, 0, "yypeek");
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
// Binding lex_char
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = nil; // lex_char
    v_12699 = qvalue(elt(env, 2)); // lex_peek_char
    if (v_12699 == nil) goto v_12694;
    else goto v_12695;
v_12694:
    fn = elt(env, 3); // yyreadch
    v_12699 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_12699; // lex_peek_char
    goto v_12693;
v_12695:
v_12693:
    v_12699 = qvalue(elt(env, 2)); // lex_peek_char
    ;}  // end of a binding scope
    return onevalue(v_12699);
}



// Code for defineargs

static LispObject CC_defineargs(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12756, v_12757, v_12758, v_12759;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12689;
    stack[-1] = v_12688;
// end of prologue
    v_12756 = stack[-1];
    if (!symbolp(v_12756)) v_12756 = nil;
    else { v_12756 = qfastgets(v_12756);
           if (v_12756 != nil) { v_12756 = elt(v_12756, 42); // number!-of!-args
#ifdef RECORD_GET
             if (v_12756 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v_12756 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v_12756 == SPID_NOPROP) v_12756 = nil; }}
#endif
    v_12757 = v_12756;
    v_12756 = v_12757;
    if (v_12756 == nil) goto v_12699;
    else goto v_12700;
v_12699:
    goto v_12707;
v_12703:
    v_12757 = stack[-1];
    goto v_12704;
v_12705:
    v_12756 = stack[0];
    goto v_12706;
v_12707:
    goto v_12703;
v_12704:
    goto v_12705;
v_12706:
    {
        fn = elt(env, 2); // hasarg
        return (*qfn2(fn))(fn, v_12757, v_12756);
    }
v_12700:
    goto v_12718;
v_12714:
    v_12758 = stack[0];
    goto v_12715;
v_12716:
    v_12756 = v_12757;
    goto v_12717;
v_12718:
    goto v_12714;
v_12715:
    goto v_12716;
v_12717:
    if (equal(v_12758, v_12756)) goto v_12712;
    else goto v_12713;
v_12712:
    v_12756 = nil;
    goto v_12694;
v_12713:
    goto v_12731;
v_12727:
    v_12758 = stack[-1];
    goto v_12728;
v_12729:
    v_12756 = elt(env, 1); // calledby
    goto v_12730;
v_12731:
    goto v_12727;
v_12728:
    goto v_12729;
v_12730:
    v_12758 = get(v_12758, v_12756);
    env = stack[-2];
    v_12756 = v_12758;
    if (v_12758 == nil) goto v_12725;
    goto v_12743;
v_12735:
    v_12759 = stack[-1];
    goto v_12736;
v_12737:
    v_12758 = stack[0];
    goto v_12738;
v_12739:
    goto v_12740;
v_12741:
    goto v_12742;
v_12743:
    goto v_12735;
v_12736:
    goto v_12737;
v_12738:
    goto v_12739;
v_12740:
    goto v_12741;
v_12742:
    fn = elt(env, 3); // instdof
    v_12756 = (*qfnn(fn))(fn, 4, v_12759, v_12758, v_12757, v_12756);
    env = stack[-2];
    goto v_12723;
v_12725:
v_12723:
    goto v_12753;
v_12749:
    v_12757 = stack[-1];
    goto v_12750;
v_12751:
    v_12756 = stack[0];
    goto v_12752;
v_12753:
    goto v_12749;
v_12750:
    goto v_12751;
v_12752:
    fn = elt(env, 2); // hasarg
    v_12756 = (*qfn2(fn))(fn, v_12757, v_12756);
    v_12756 = nil;
v_12694:
    return onevalue(v_12756);
}



// Code for mk!+unit!+mat

static LispObject CC_mkLunitLmat(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12694;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12694 = v_12688;
// end of prologue
    {
        fn = elt(env, 1); // gen!+can!+bas
        return (*qfn1(fn))(fn, v_12694);
    }
    return onevalue(v_12694);
}



// Code for cl_flip

static LispObject CC_cl_flip(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12783, v_12784, v_12785;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12785 = v_12688;
// end of prologue
    goto v_12698;
v_12694:
    v_12784 = v_12785;
    goto v_12695;
v_12696:
    v_12783 = elt(env, 1); // and
    goto v_12697;
v_12698:
    goto v_12694;
v_12695:
    goto v_12696;
v_12697:
    if (v_12784 == v_12783) goto v_12692;
    else goto v_12693;
v_12692:
    v_12783 = elt(env, 2); // or
    goto v_12691;
v_12693:
    goto v_12708;
v_12704:
    v_12784 = v_12785;
    goto v_12705;
v_12706:
    v_12783 = elt(env, 2); // or
    goto v_12707;
v_12708:
    goto v_12704;
v_12705:
    goto v_12706;
v_12707:
    if (v_12784 == v_12783) goto v_12702;
    else goto v_12703;
v_12702:
    v_12783 = elt(env, 1); // and
    goto v_12691;
v_12703:
    goto v_12718;
v_12714:
    v_12784 = v_12785;
    goto v_12715;
v_12716:
    v_12783 = elt(env, 3); // all
    goto v_12717;
v_12718:
    goto v_12714;
v_12715:
    goto v_12716;
v_12717:
    if (v_12784 == v_12783) goto v_12712;
    else goto v_12713;
v_12712:
    v_12783 = elt(env, 4); // ex
    goto v_12691;
v_12713:
    goto v_12728;
v_12724:
    v_12784 = v_12785;
    goto v_12725;
v_12726:
    v_12783 = elt(env, 4); // ex
    goto v_12727;
v_12728:
    goto v_12724;
v_12725:
    goto v_12726;
v_12727:
    if (v_12784 == v_12783) goto v_12722;
    else goto v_12723;
v_12722:
    v_12783 = elt(env, 3); // all
    goto v_12691;
v_12723:
    goto v_12738;
v_12734:
    v_12784 = v_12785;
    goto v_12735;
v_12736:
    v_12783 = elt(env, 5); // ball
    goto v_12737;
v_12738:
    goto v_12734;
v_12735:
    goto v_12736;
v_12737:
    if (v_12784 == v_12783) goto v_12732;
    else goto v_12733;
v_12732:
    v_12783 = elt(env, 6); // bex
    goto v_12691;
v_12733:
    goto v_12748;
v_12744:
    v_12784 = v_12785;
    goto v_12745;
v_12746:
    v_12783 = elt(env, 6); // bex
    goto v_12747;
v_12748:
    goto v_12744;
v_12745:
    goto v_12746;
v_12747:
    if (v_12784 == v_12783) goto v_12742;
    else goto v_12743;
v_12742:
    v_12783 = elt(env, 5); // ball
    goto v_12691;
v_12743:
    goto v_12758;
v_12754:
    v_12784 = v_12785;
    goto v_12755;
v_12756:
    v_12783 = elt(env, 7); // true
    goto v_12757;
v_12758:
    goto v_12754;
v_12755:
    goto v_12756;
v_12757:
    if (v_12784 == v_12783) goto v_12752;
    else goto v_12753;
v_12752:
    v_12783 = elt(env, 8); // false
    goto v_12691;
v_12753:
    goto v_12768;
v_12764:
    v_12784 = v_12785;
    goto v_12765;
v_12766:
    v_12783 = elt(env, 8); // false
    goto v_12767;
v_12768:
    goto v_12764;
v_12765:
    goto v_12766;
v_12767:
    if (v_12784 == v_12783) goto v_12762;
    else goto v_12763;
v_12762:
    v_12783 = elt(env, 7); // true
    goto v_12691;
v_12763:
    goto v_12780;
v_12776:
    v_12783 = elt(env, 9); // "cl_flip(): don't know"
    goto v_12777;
v_12778:
    v_12784 = v_12785;
    goto v_12779;
v_12780:
    goto v_12776;
v_12777:
    goto v_12778;
v_12779:
    v_12783 = list2(v_12783, v_12784);
    env = stack[0];
    {
        fn = elt(env, 10); // rederr
        return (*qfn1(fn))(fn, v_12783);
    }
    v_12783 = nil;
v_12691:
    return onevalue(v_12783);
}



// Code for ibalp_negateat

static LispObject CC_ibalp_negateat(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12705;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_12688;
// end of prologue
    goto v_12697;
v_12691:
    v_12705 = stack[-1];
    fn = elt(env, 1); // ibalp_op
    stack[-2] = (*qfn1(fn))(fn, v_12705);
    env = stack[-3];
    goto v_12692;
v_12693:
    v_12705 = stack[-1];
    fn = elt(env, 2); // ibalp_arg2l
    stack[0] = (*qfn1(fn))(fn, v_12705);
    env = stack[-3];
    goto v_12694;
v_12695:
    v_12705 = stack[-1];
    fn = elt(env, 3); // ibalp_arg2r
    v_12705 = (*qfn1(fn))(fn, v_12705);
    env = stack[-3];
    fn = elt(env, 4); // ibalp_negatet
    v_12705 = (*qfn1(fn))(fn, v_12705);
    env = stack[-3];
    goto v_12696;
v_12697:
    goto v_12691;
v_12692:
    goto v_12693;
v_12694:
    goto v_12695;
v_12696:
    {
        LispObject v_12709 = stack[-2];
        LispObject v_12710 = stack[0];
        fn = elt(env, 5); // ibalp_mk2
        return (*qfnn(fn))(fn, 3, v_12709, v_12710, v_12705);
    }
}



// Code for aex_deg

static LispObject CC_aex_deg(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12701, v_12702;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_12689;
    v_12701 = v_12688;
// end of prologue
    goto v_12696;
v_12692:
    fn = elt(env, 1); // aex_ex
    v_12701 = (*qfn1(fn))(fn, v_12701);
    env = stack[-1];
    v_12702 = qcar(v_12701);
    goto v_12693;
v_12694:
    v_12701 = stack[0];
    goto v_12695;
v_12696:
    goto v_12692;
v_12693:
    goto v_12694;
v_12695:
    {
        fn = elt(env, 2); // sfto_vardeg
        return (*qfn2(fn))(fn, v_12702, v_12701);
    }
}



// Code for simprecip

static LispObject CC_simprecip(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12723, v_12724;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12724 = v_12688;
// end of prologue
    v_12723 = qvalue(elt(env, 1)); // !*mcd
    if (v_12723 == nil) goto v_12692;
    else goto v_12693;
v_12692:
    goto v_12701;
v_12697:
    goto v_12707;
v_12703:
    goto v_12704;
v_12705:
    v_12723 = elt(env, 2); // recip
    goto v_12706;
v_12707:
    goto v_12703;
v_12704:
    goto v_12705;
v_12706:
    fn = elt(env, 3); // carx
    v_12724 = (*qfn2(fn))(fn, v_12724, v_12723);
    env = stack[0];
    goto v_12698;
v_12699:
    v_12723 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_12700;
v_12701:
    goto v_12697;
v_12698:
    goto v_12699;
v_12700:
    v_12723 = list2(v_12724, v_12723);
    env = stack[0];
    {
        fn = elt(env, 4); // simpexpt
        return (*qfn1(fn))(fn, v_12723);
    }
v_12693:
    goto v_12720;
v_12716:
    goto v_12717;
v_12718:
    v_12723 = elt(env, 2); // recip
    goto v_12719;
v_12720:
    goto v_12716;
v_12717:
    goto v_12718;
v_12719:
    fn = elt(env, 3); // carx
    v_12723 = (*qfn2(fn))(fn, v_12724, v_12723);
    env = stack[0];
    fn = elt(env, 5); // simp
    v_12723 = (*qfn1(fn))(fn, v_12723);
    env = stack[0];
    {
        fn = elt(env, 6); // invsq
        return (*qfn1(fn))(fn, v_12723);
    }
    v_12723 = nil;
    return onevalue(v_12723);
}



// Code for coordp

static LispObject CC_coordp(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12698, v_12699;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12698 = v_12688;
// end of prologue
    goto v_12694;
v_12690:
    goto v_12691;
v_12692:
    v_12699 = qvalue(elt(env, 1)); // coord!*
    goto v_12693;
v_12694:
    goto v_12690;
v_12691:
    goto v_12692;
v_12693:
    v_12698 = Lmemq(nil, v_12698, v_12699);
    return onevalue(v_12698);
}



// Code for begin11

static LispObject CC_begin11(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_13230, v_13231;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_12688;
// end of prologue
// Binding errmsg!*
// FLUIDBIND: reloadenv=6 litvec-offset=1 saveloc=5
{   bind_fluid_stack bind_fluid_var(-6, 1, -5);
    qvalue(elt(env, 1)) = nil; // errmsg!*
    stack[-3] = nil;
// Binding newrule!*
// FLUIDBIND: reloadenv=6 litvec-offset=2 saveloc=2
{   bind_fluid_stack bind_fluid_var(-6, 2, -2);
    qvalue(elt(env, 2)) = nil; // newrule!*
    goto v_12704;
v_12700:
    v_13231 = qvalue(elt(env, 3)); // cursym!*
    goto v_12701;
v_12702:
    v_13230 = elt(env, 4); // end
    goto v_12703;
v_12704:
    goto v_12700;
v_12701:
    goto v_12702;
v_12703:
    if (v_13231 == v_13230) goto v_12698;
    else goto v_12699;
v_12698:
    fn = elt(env, 47); // terminalp
    v_13230 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    if (v_13230 == nil) goto v_12710;
    v_13230 = qvalue(elt(env, 5)); // !*lisp_hook
    if (v_13230 == nil) goto v_12713;
    else goto v_12710;
v_12713:
    v_13230 = elt(env, 6); // !*semicol!*
    qvalue(elt(env, 3)) = v_13230; // cursym!*
    v_13230 = nil;
    qvalue(elt(env, 7)) = v_13230; // curescaped!*
    v_13230 = lisp_true;
    qvalue(elt(env, 8)) = v_13230; // !*nosave!*
    v_13230 = nil;
    goto v_12695;
v_12710:
    v_13230 = elt(env, 4); // end
    fn = elt(env, 48); // comm1
    v_13230 = (*qfn1(fn))(fn, v_13230);
    env = stack[-6];
    v_13230 = elt(env, 4); // end
    goto v_12695;
    goto v_12697;
v_12699:
    goto v_12731;
v_12727:
    v_13230 = qvalue(elt(env, 9)); // !*reduce4
    if (v_13230 == nil) goto v_12735;
    v_13230 = stack[-4];
    v_13231 = v_13230;
    goto v_12733;
v_12735:
    v_13230 = stack[-4];
    v_13230 = qcdr(v_13230);
    v_13230 = qcar(v_13230);
    v_13231 = v_13230;
    goto v_12733;
    v_13231 = nil;
v_12733:
    goto v_12728;
v_12729:
    v_13230 = elt(env, 10); // retry
    goto v_12730;
v_12731:
    goto v_12727;
v_12728:
    goto v_12729;
v_12730:
    if (!consp(v_13231)) goto v_12725;
    v_13231 = qcar(v_13231);
    if (v_13231 == v_13230) goto v_12724;
    else goto v_12725;
v_12724:
    v_13230 = qvalue(elt(env, 11)); // programl!*
    if (v_13230 == nil) goto v_12747;
    v_13230 = qvalue(elt(env, 11)); // programl!*
    stack[-4] = v_13230;
    goto v_12745;
v_12747:
    v_13230 = elt(env, 12); // "No previous expression"
    fn = elt(env, 49); // lprim
    v_13230 = (*qfn1(fn))(fn, v_13230);
    v_13230 = nil;
    goto v_12695;
v_12745:
    goto v_12697;
v_12725:
v_12697:
    v_13230 = qvalue(elt(env, 9)); // !*reduce4
    if (v_13230 == nil) goto v_12757;
    else goto v_12758;
v_12757:
    v_13230 = stack[-4];
    v_13230 = qcar(v_13230);
    stack[-3] = v_13230;
    v_13230 = stack[-4];
    v_13230 = qcdr(v_13230);
    v_13230 = qcar(v_13230);
    stack[-4] = v_13230;
    goto v_12756;
v_12758:
v_12756:
    v_13230 = stack[-4];
    qvalue(elt(env, 13)) = v_13230; // program!*
    fn = elt(env, 50); // eofcheck
    v_13230 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    if (v_13230 == nil) goto v_12769;
    v_13230 = elt(env, 14); // c
    goto v_12695;
v_12769:
    v_13230 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 15)) = v_13230; // eof!*
    goto v_12767;
v_12767:
    goto v_12780;
v_12776:
    v_13231 = stack[-4];
    goto v_12777;
v_12778:
    v_13230 = qvalue(elt(env, 9)); // !*reduce4
    if (v_13230 == nil) goto v_12785;
    v_13230 = nil;
    goto v_12783;
v_12785:
    v_13230 = stack[-3];
    goto v_12783;
    v_13230 = nil;
v_12783:
    goto v_12779;
v_12780:
    goto v_12776;
v_12777:
    goto v_12778;
v_12779:
    fn = elt(env, 51); // add2inputbuf
    v_13230 = (*qfn2(fn))(fn, v_13231, v_13230);
    env = stack[-6];
    v_13230 = stack[-4];
    if (!consp(v_13230)) goto v_12798;
    goto v_12804;
v_12800:
    v_13230 = stack[-4];
    v_13231 = qcar(v_13230);
    goto v_12801;
v_12802:
    v_13230 = elt(env, 16); // (bye quit)
    goto v_12803;
v_12804:
    goto v_12800;
v_12801:
    goto v_12802;
v_12803:
    v_13230 = Lmemq(nil, v_13231, v_13230);
    goto v_12796;
v_12798:
    v_13230 = nil;
    goto v_12796;
    v_13230 = nil;
v_12796:
    if (v_13230 == nil) goto v_12794;
    v_13230 = elt(env, 17); // bye
    fn = elt(env, 52); // getd
    v_13230 = (*qfn1(fn))(fn, v_13230);
    env = stack[-6];
    if (v_13230 == nil) goto v_12815;
    v_13230 = stack[-4];
    fn = elt(env, 53); // lispeval
    v_13230 = (*qfn1(fn))(fn, v_13230);
    env = stack[-6];
    v_13230 = lisp_true;
    qvalue(elt(env, 8)) = v_13230; // !*nosave!*
    v_13230 = nil;
    goto v_12695;
v_12815:
    v_13230 = lisp_true;
    qvalue(elt(env, 18)) = v_13230; // !*byeflag!*
    v_13230 = nil;
    goto v_12695;
    goto v_12792;
v_12794:
    v_13230 = qvalue(elt(env, 9)); // !*reduce4
    if (v_13230 == nil) goto v_12830;
    else goto v_12831;
v_12830:
    goto v_12838;
v_12834:
    v_13231 = stack[-4];
    goto v_12835;
v_12836:
    v_13230 = elt(env, 19); // ed
    goto v_12837;
v_12838:
    goto v_12834;
v_12835:
    goto v_12836;
v_12837:
    v_13230 = Leqcar(nil, v_13231, v_13230);
    env = stack[-6];
    goto v_12829;
v_12831:
    v_13230 = nil;
    goto v_12829;
    v_13230 = nil;
v_12829:
    if (v_13230 == nil) goto v_12827;
    v_13230 = elt(env, 20); // cedit
    fn = elt(env, 52); // getd
    v_13230 = (*qfn1(fn))(fn, v_13230);
    env = stack[-6];
    if (v_13230 == nil) goto v_12847;
    fn = elt(env, 47); // terminalp
    v_13230 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    if (v_13230 == nil) goto v_12847;
    v_13230 = stack[-4];
    v_13230 = qcdr(v_13230);
    fn = elt(env, 20); // cedit
    v_13230 = (*qfn1(fn))(fn, v_13230);
    env = stack[-6];
    goto v_12845;
v_12847:
    v_13230 = elt(env, 21); // "ED not supported"
    fn = elt(env, 49); // lprim
    v_13230 = (*qfn1(fn))(fn, v_13230);
    env = stack[-6];
    goto v_12845;
v_12845:
    v_13230 = lisp_true;
    qvalue(elt(env, 8)) = v_13230; // !*nosave!*
    v_13230 = nil;
    goto v_12695;
v_12827:
    v_13230 = qvalue(elt(env, 22)); // !*defn
    if (v_13230 == nil) goto v_12863;
    v_13230 = qvalue(elt(env, 23)); // erfg!*
    if (v_13230 == nil) goto v_12868;
    v_13230 = nil;
    goto v_12695;
v_12868:
    goto v_12882;
v_12878:
    v_13231 = qvalue(elt(env, 24)); // key!*
    goto v_12879;
v_12880:
    v_13230 = elt(env, 25); // ignore
    goto v_12881;
v_12882:
    goto v_12878;
v_12879:
    goto v_12880;
v_12881:
    v_13230 = Lflagp(nil, v_13231, v_13230);
    env = stack[-6];
    if (v_13230 == nil) goto v_12875;
    else goto v_12876;
v_12875:
    goto v_12890;
v_12886:
    v_13231 = stack[-4];
    goto v_12887;
v_12888:
    v_13230 = elt(env, 26); // quote
    goto v_12889;
v_12890:
    goto v_12886;
v_12887:
    goto v_12888;
v_12889:
    v_13230 = Leqcar(nil, v_13231, v_13230);
    env = stack[-6];
    v_13230 = (v_13230 == nil ? lisp_true : nil);
    goto v_12874;
v_12876:
    v_13230 = nil;
    goto v_12874;
    v_13230 = nil;
v_12874:
    if (v_13230 == nil) goto v_12872;
    v_13230 = stack[-4];
    if (v_13230 == nil) goto v_12900;
    v_13230 = stack[-4];
    fn = elt(env, 54); // dfprint
    v_13230 = (*qfn1(fn))(fn, v_13230);
    env = stack[-6];
    goto v_12898;
v_12900:
    goto v_12898;
v_12898:
    goto v_12916;
v_12912:
    v_13231 = qvalue(elt(env, 24)); // key!*
    goto v_12913;
v_12914:
    v_13230 = elt(env, 27); // eval
    goto v_12915;
v_12916:
    goto v_12912;
v_12913:
    goto v_12914;
v_12915:
    v_13230 = Lflagp(nil, v_13231, v_13230);
    env = stack[-6];
    if (v_13230 == nil) goto v_12909;
    else goto v_12910;
v_12909:
    v_13230 = nil;
    goto v_12695;
v_12910:
    goto v_12866;
v_12872:
v_12866:
    goto v_12792;
v_12863:
v_12792:
    v_13230 = qvalue(elt(env, 28)); // !*output
    if (v_13230 == nil) goto v_12923;
    v_13230 = qvalue(elt(env, 29)); // ifl!*
    if (v_13230 == nil) goto v_12923;
    v_13230 = qvalue(elt(env, 30)); // !*echo
    if (v_13230 == nil) goto v_12923;
    v_13230 = qvalue(elt(env, 31)); // !*lessspace
    if (v_13230 == nil) goto v_12932;
    else goto v_12923;
v_12932:
    v_13230 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_12921;
v_12923:
v_12921:
    v_13230 = qvalue(elt(env, 32)); // ulimit!*
    v_13230 = integerp(v_13230);
    if (v_13230 == nil) goto v_12938;
    goto v_12946;
v_12942:
    v_13231 = qvalue(elt(env, 32)); // ulimit!*
    goto v_12943;
v_12944:
    v_13230 = stack[-4];
    goto v_12945;
v_12946:
    goto v_12942;
v_12943:
    goto v_12944;
v_12945:
    fn = elt(env, 55); // errorset_with_timeout
    v_13230 = (*qfn2(fn))(fn, v_13231, v_13230);
    env = stack[-6];
    stack[0] = v_13230;
    v_13230 = stack[0];
    if (!consp(v_13230)) goto v_12952;
    v_13230 = stack[0];
    v_13230 = qcar(v_13230);
    stack[0] = v_13230;
    goto v_12950;
v_12952:
v_12950:
    goto v_12936;
v_12938:
    goto v_12963;
v_12959:
    v_13231 = stack[-4];
    goto v_12960;
v_12961:
    v_13230 = lisp_true;
    goto v_12962;
v_12963:
    goto v_12959;
v_12960:
    goto v_12961;
v_12962:
    fn = elt(env, 56); // errorset!*
    v_13230 = (*qfn2(fn))(fn, v_13231, v_13230);
    env = stack[-6];
    stack[0] = v_13230;
    goto v_12936;
v_12936:
    v_13230 = stack[0];
    fn = elt(env, 57); // errorp
    v_13230 = (*qfn1(fn))(fn, v_13230);
    env = stack[-6];
    if (v_13230 == nil) goto v_12970;
    else goto v_12968;
v_12970:
    v_13230 = qvalue(elt(env, 23)); // erfg!*
    if (v_13230 == nil) goto v_12973;
    else goto v_12968;
v_12973:
    goto v_12969;
v_12968:
    goto v_12980;
v_12976:
    v_13231 = stack[-3];
    goto v_12977;
v_12978:
    v_13230 = stack[-4];
    goto v_12979;
v_12980:
    goto v_12976;
v_12977:
    goto v_12978;
v_12979:
    v_13230 = list2(v_13231, v_13230);
    env = stack[-6];
    qvalue(elt(env, 11)) = v_13230; // programl!*
    v_13230 = elt(env, 33); // err2
    goto v_12695;
v_12969:
    v_13230 = qvalue(elt(env, 22)); // !*defn
    if (v_13230 == nil) goto v_12985;
    v_13230 = nil;
    goto v_12695;
v_12985:
    v_13230 = qvalue(elt(env, 9)); // !*reduce4
    if (v_13230 == nil) goto v_12990;
    else goto v_12991;
v_12990:
    goto v_13001;
v_12997:
    v_13231 = stack[-3];
    goto v_12998;
v_12999:
    v_13230 = elt(env, 34); // symbolic
    goto v_13000;
v_13001:
    goto v_12997;
v_12998:
    goto v_12999;
v_13000:
    if (v_13231 == v_13230) goto v_12996;
    v_13230 = stack[-4];
    fn = elt(env, 58); // getsetvars
    v_13230 = (*qfn1(fn))(fn, v_13230);
    env = stack[-6];
    stack[-4] = v_13230;
    goto v_12994;
v_12996:
    goto v_12994;
v_12994:
    goto v_12989;
v_12991:
    v_13230 = stack[0];
    v_13230 = qcar(v_13230);
    stack[0] = v_13230;
    v_13230 = stack[0];
    if (v_13230 == nil) goto v_13015;
    else goto v_13016;
v_13015:
    goto v_13023;
v_13019:
    v_13231 = nil;
    goto v_13020;
v_13021:
    v_13230 = elt(env, 35); // noval
    goto v_13022;
v_13023:
    goto v_13019;
v_13020:
    goto v_13021;
v_13022:
    fn = elt(env, 59); // mkobject
    v_13230 = (*qfn2(fn))(fn, v_13231, v_13230);
    env = stack[-6];
    stack[0] = v_13230;
    goto v_13014;
v_13016:
v_13014:
    v_13230 = stack[0];
    fn = elt(env, 60); // type
    v_13230 = (*qfn1(fn))(fn, v_13230);
    env = stack[-6];
    stack[-3] = v_13230;
    v_13230 = stack[0];
    fn = elt(env, 61); // value
    v_13230 = (*qfn1(fn))(fn, v_13230);
    env = stack[-6];
    stack[0] = v_13230;
    goto v_12989;
v_12989:
    goto v_13035;
v_13031:
    v_13230 = qvalue(elt(env, 9)); // !*reduce4
    if (v_13230 == nil) goto v_13038;
    else goto v_13039;
v_13038:
    v_13230 = stack[0];
    v_13230 = qcar(v_13230);
    v_13231 = v_13230;
    goto v_13037;
v_13039:
    v_13230 = stack[0];
    v_13231 = v_13230;
    goto v_13037;
    v_13231 = nil;
v_13037:
    goto v_13032;
v_13033:
    v_13230 = stack[-3];
    goto v_13034;
v_13035:
    goto v_13031;
v_13032:
    goto v_13033;
v_13034:
    fn = elt(env, 62); // add2resultbuf
    v_13230 = (*qfn2(fn))(fn, v_13231, v_13230);
    env = stack[-6];
    v_13230 = qvalue(elt(env, 28)); // !*output
    if (v_13230 == nil) goto v_13049;
    else goto v_13050;
v_13049:
    v_13230 = nil;
    goto v_12695;
v_13050:
    goto v_13059;
v_13055:
    v_13231 = qvalue(elt(env, 36)); // semic!*
    goto v_13056;
v_13057:
    v_13230 = elt(env, 37); // !$
    goto v_13058;
v_13059:
    goto v_13055;
v_13056:
    goto v_13057;
v_13058:
    if (v_13231 == v_13230) goto v_13054;
    v_13230 = qvalue(elt(env, 9)); // !*reduce4
    if (v_13230 == nil) goto v_13065;
    v_13230 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_13078;
v_13074:
    v_13231 = stack[-3];
    goto v_13075;
v_13076:
    v_13230 = elt(env, 35); // noval
    goto v_13077;
v_13078:
    goto v_13074;
v_13075:
    goto v_13076;
v_13077:
    if (v_13231 == v_13230) goto v_13072;
    else goto v_13073;
v_13072:
    goto v_13068;
v_13073:
    v_13230 = qvalue(elt(env, 38)); // !*debug
    if (v_13230 == nil) goto v_13083;
    v_13230 = elt(env, 39); // "Value:"
    fn = elt(env, 63); // prin2t
    v_13230 = (*qfn1(fn))(fn, v_13230);
    env = stack[-6];
    goto v_13071;
v_13083:
v_13071:
    goto v_13092;
v_13088:
    stack[-1] = elt(env, 40); // print
    goto v_13089;
v_13090:
    goto v_13100;
v_13096:
    v_13231 = stack[-3];
    goto v_13097;
v_13098:
    v_13230 = stack[0];
    goto v_13099;
v_13100:
    goto v_13096;
v_13097:
    goto v_13098;
v_13099:
    v_13230 = list2(v_13231, v_13230);
    env = stack[-6];
    v_13230 = ncons(v_13230);
    env = stack[-6];
    goto v_13091;
v_13092:
    goto v_13088;
v_13089:
    goto v_13090;
v_13091:
    fn = elt(env, 64); // rapply1
    v_13230 = (*qfn2(fn))(fn, stack[-1], v_13230);
    env = stack[-6];
v_13068:
    goto v_13063;
v_13065:
    goto v_13109;
v_13105:
    v_13231 = stack[-3];
    goto v_13106;
v_13107:
    v_13230 = elt(env, 34); // symbolic
    goto v_13108;
v_13109:
    goto v_13105;
v_13106:
    goto v_13107;
v_13108:
    if (v_13231 == v_13230) goto v_13103;
    else goto v_13104;
v_13103:
    v_13230 = stack[0];
    v_13230 = qcar(v_13230);
    if (v_13230 == nil) goto v_13118;
    else goto v_13119;
v_13118:
    goto v_13126;
v_13122:
    v_13231 = qvalue(elt(env, 41)); // !*mode
    goto v_13123;
v_13124:
    v_13230 = elt(env, 34); // symbolic
    goto v_13125;
v_13126:
    goto v_13122;
v_13123:
    goto v_13124;
v_13125:
    v_13230 = (v_13231 == v_13230 ? lisp_true : nil);
    v_13230 = (v_13230 == nil ? lisp_true : nil);
    goto v_13117;
v_13119:
    v_13230 = nil;
    goto v_13117;
    v_13230 = nil;
v_13117:
    if (v_13230 == nil) goto v_13115;
    goto v_13113;
v_13115:
    v_13230 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_13145;
v_13141:
    goto v_13151;
v_13147:
    stack[-1] = elt(env, 40); // print
    goto v_13148;
v_13149:
    v_13230 = stack[0];
    v_13230 = qcar(v_13230);
    v_13230 = Lmkquote(nil, v_13230);
    env = stack[-6];
    goto v_13150;
v_13151:
    goto v_13147;
v_13148:
    goto v_13149;
v_13150:
    v_13231 = list2(stack[-1], v_13230);
    env = stack[-6];
    goto v_13142;
v_13143:
    v_13230 = lisp_true;
    goto v_13144;
v_13145:
    goto v_13141;
v_13142:
    goto v_13143;
v_13144:
    fn = elt(env, 56); // errorset!*
    v_13230 = (*qfn2(fn))(fn, v_13231, v_13230);
    env = stack[-6];
    stack[0] = v_13230;
    goto v_13113;
v_13113:
    goto v_13063;
v_13104:
    v_13230 = stack[0];
    v_13230 = qcar(v_13230);
    if (v_13230 == nil) goto v_13158;
    goto v_13166;
v_13162:
    goto v_13176;
v_13168:
    stack[-1] = elt(env, 42); // assgnpri
    goto v_13169;
v_13170:
    v_13230 = stack[0];
    v_13230 = qcar(v_13230);
    stack[0] = Lmkquote(nil, v_13230);
    env = stack[-6];
    goto v_13171;
v_13172:
    v_13230 = stack[-4];
    if (v_13230 == nil) goto v_13184;
    goto v_13191;
v_13187:
    v_13231 = elt(env, 43); // list
    goto v_13188;
v_13189:
    v_13230 = stack[-4];
    goto v_13190;
v_13191:
    goto v_13187;
v_13188:
    goto v_13189;
v_13190:
    v_13230 = cons(v_13231, v_13230);
    env = stack[-6];
    stack[-4] = v_13230;
    goto v_13182;
v_13184:
    v_13230 = nil;
    stack[-4] = v_13230;
    goto v_13182;
    stack[-4] = nil;
v_13182:
    goto v_13173;
v_13174:
    v_13230 = elt(env, 44); // only
    v_13230 = Lmkquote(nil, v_13230);
    env = stack[-6];
    goto v_13175;
v_13176:
    goto v_13168;
v_13169:
    goto v_13170;
v_13171:
    goto v_13172;
v_13173:
    goto v_13174;
v_13175:
    v_13231 = list4(stack[-1], stack[0], stack[-4], v_13230);
    env = stack[-6];
    goto v_13163;
v_13164:
    v_13230 = lisp_true;
    goto v_13165;
v_13166:
    goto v_13162;
v_13163:
    goto v_13164;
v_13165:
    fn = elt(env, 56); // errorset!*
    v_13230 = (*qfn2(fn))(fn, v_13231, v_13230);
    env = stack[-6];
    stack[0] = v_13230;
    goto v_13063;
v_13158:
v_13063:
    goto v_13048;
v_13054:
v_13048:
    v_13230 = qvalue(elt(env, 9)); // !*reduce4
    if (v_13230 == nil) goto v_13202;
    else goto v_13203;
v_13202:
    v_13230 = stack[0];
    fn = elt(env, 57); // errorp
    v_13230 = (*qfn1(fn))(fn, v_13230);
    env = stack[-6];
    if (v_13230 == nil) goto v_13208;
    v_13230 = elt(env, 45); // err3
    goto v_13206;
v_13208:
    v_13230 = nil;
    goto v_13206;
    v_13230 = nil;
v_13206:
    goto v_12695;
v_13203:
    goto v_13221;
v_13217:
    v_13231 = qvalue(elt(env, 41)); // !*mode
    goto v_13218;
v_13219:
    v_13230 = elt(env, 35); // noval
    goto v_13220;
v_13221:
    goto v_13217;
v_13218:
    goto v_13219;
v_13220:
    if (v_13231 == v_13230) goto v_13216;
    v_13230 = Lterpri(nil, 0);
    env = stack[-6];
    v_13230 = elt(env, 46); // "of type: "
    v_13230 = Lprinc(nil, v_13230);
    env = stack[-6];
    v_13230 = stack[-3];
    v_13230 = Lprint(nil, v_13230);
    goto v_13201;
v_13216:
v_13201:
    v_13230 = nil;
v_12695:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_13230);
}



// Code for lienjactest

static LispObject CC_lienjactest(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_13102, v_13103, v_13104, v_13105;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(14);
// copy arguments values to proper place
    stack[-11] = v_12688;
// end of prologue
    goto v_12697;
v_12693:
    stack[0] = elt(env, 1); // lie_jtest
    goto v_12694;
v_12695:
    v_13102 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 6); // aeval
    v_13102 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    goto v_12696;
v_12697:
    goto v_12693;
v_12694:
    goto v_12695;
v_12696:
    fn = elt(env, 7); // setk
    v_13102 = (*qfn2(fn))(fn, stack[0], v_13102);
    env = stack[-13];
    v_13102 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-12] = v_13102;
v_12704:
    goto v_12718;
v_12712:
    stack[0] = elt(env, 2); // difference
    goto v_12713;
v_12714:
    goto v_12728;
v_12722:
    v_13104 = elt(env, 2); // difference
    goto v_12723;
v_12724:
    v_13103 = stack[-11];
    goto v_12725;
v_12726:
    v_13102 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_12727;
v_12728:
    goto v_12722;
v_12723:
    goto v_12724;
v_12725:
    goto v_12726;
v_12727:
    v_13102 = list3(v_13104, v_13103, v_13102);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13103 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    goto v_12715;
v_12716:
    v_13102 = stack[-12];
    goto v_12717;
v_12718:
    goto v_12712;
v_12713:
    goto v_12714;
v_12715:
    goto v_12716;
v_12717:
    v_13102 = list3(stack[0], v_13103, v_13102);
    env = stack[-13];
    fn = elt(env, 9); // aminusp!:
    v_13102 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    if (v_13102 == nil) goto v_12709;
    goto v_12703;
v_12709:
    v_13102 = stack[-12];
    v_13102 = add1(v_13102);
    env = stack[-13];
    stack[-10] = v_13102;
v_12737:
    goto v_12752;
v_12746:
    stack[0] = elt(env, 2); // difference
    goto v_12747;
v_12748:
    goto v_12762;
v_12756:
    v_13104 = elt(env, 2); // difference
    goto v_12757;
v_12758:
    v_13103 = stack[-11];
    goto v_12759;
v_12760:
    v_13102 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12761;
v_12762:
    goto v_12756;
v_12757:
    goto v_12758;
v_12759:
    goto v_12760;
v_12761:
    v_13102 = list3(v_13104, v_13103, v_13102);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13103 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    goto v_12749;
v_12750:
    v_13102 = stack[-10];
    goto v_12751;
v_12752:
    goto v_12746;
v_12747:
    goto v_12748;
v_12749:
    goto v_12750;
v_12751:
    v_13102 = list3(stack[0], v_13103, v_13102);
    env = stack[-13];
    fn = elt(env, 9); // aminusp!:
    v_13102 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    if (v_13102 == nil) goto v_12743;
    goto v_12736;
v_12743:
    v_13102 = stack[-10];
    v_13102 = add1(v_13102);
    env = stack[-13];
    stack[-9] = v_13102;
v_12771:
    goto v_12786;
v_12780:
    stack[0] = elt(env, 2); // difference
    goto v_12781;
v_12782:
    v_13102 = stack[-11];
    fn = elt(env, 8); // aeval!*
    v_13103 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    goto v_12783;
v_12784:
    v_13102 = stack[-9];
    goto v_12785;
v_12786:
    goto v_12780;
v_12781:
    goto v_12782;
v_12783:
    goto v_12784;
v_12785:
    v_13102 = list3(stack[0], v_13103, v_13102);
    env = stack[-13];
    fn = elt(env, 9); // aminusp!:
    v_13102 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    if (v_13102 == nil) goto v_12777;
    goto v_12770;
v_12777:
    v_13102 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_13102;
v_12795:
    goto v_12809;
v_12803:
    stack[0] = elt(env, 2); // difference
    goto v_12804;
v_12805:
    v_13102 = stack[-11];
    fn = elt(env, 8); // aeval!*
    v_13103 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    goto v_12806;
v_12807:
    v_13102 = stack[-8];
    goto v_12808;
v_12809:
    goto v_12803;
v_12804:
    goto v_12805;
v_12806:
    goto v_12807;
v_12808:
    v_13102 = list3(stack[0], v_13103, v_13102);
    env = stack[-13];
    fn = elt(env, 9); // aminusp!:
    v_13102 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    if (v_13102 == nil) goto v_12800;
    goto v_12794;
v_12800:
    goto v_12824;
v_12820:
    v_13102 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-7] = v_13102;
    v_13102 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_13102;
v_12829:
    goto v_12844;
v_12838:
    stack[0] = elt(env, 2); // difference
    goto v_12839;
v_12840:
    v_13102 = stack[-11];
    fn = elt(env, 8); // aeval!*
    v_13103 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    goto v_12841;
v_12842:
    v_13102 = stack[-7];
    goto v_12843;
v_12844:
    goto v_12838;
v_12839:
    goto v_12840;
v_12841:
    goto v_12842;
v_12843:
    v_13102 = list3(stack[0], v_13103, v_13102);
    env = stack[-13];
    fn = elt(env, 9); // aminusp!:
    v_13102 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    if (v_13102 == nil) goto v_12835;
    v_13102 = stack[-6];
    v_13103 = v_13102;
    goto v_12828;
v_12835:
    goto v_12858;
v_12852:
    stack[-5] = elt(env, 3); // plus
    goto v_12853;
v_12854:
    goto v_12870;
v_12862:
    stack[-4] = elt(env, 3); // plus
    goto v_12863;
v_12864:
    goto v_12879;
v_12873:
    stack[-1] = elt(env, 4); // times
    goto v_12874;
v_12875:
    goto v_12890;
v_12882:
    v_13105 = elt(env, 5); // lie_cc
    goto v_12883;
v_12884:
    v_13104 = stack[-10];
    goto v_12885;
v_12886:
    v_13103 = stack[-9];
    goto v_12887;
v_12888:
    v_13102 = stack[-7];
    goto v_12889;
v_12890:
    goto v_12882;
v_12883:
    goto v_12884;
v_12885:
    goto v_12886;
v_12887:
    goto v_12888;
v_12889:
    stack[0] = list4(v_13105, v_13104, v_13103, v_13102);
    env = stack[-13];
    goto v_12876;
v_12877:
    goto v_12904;
v_12896:
    v_13105 = elt(env, 5); // lie_cc
    goto v_12897;
v_12898:
    v_13104 = stack[-12];
    goto v_12899;
v_12900:
    v_13103 = stack[-7];
    goto v_12901;
v_12902:
    v_13102 = stack[-8];
    goto v_12903;
v_12904:
    goto v_12896;
v_12897:
    goto v_12898;
v_12899:
    goto v_12900;
v_12901:
    goto v_12902;
v_12903:
    v_13102 = list4(v_13105, v_13104, v_13103, v_13102);
    env = stack[-13];
    goto v_12878;
v_12879:
    goto v_12873;
v_12874:
    goto v_12875;
v_12876:
    goto v_12877;
v_12878:
    stack[-3] = list3(stack[-1], stack[0], v_13102);
    env = stack[-13];
    goto v_12865;
v_12866:
    goto v_12916;
v_12910:
    stack[-1] = elt(env, 4); // times
    goto v_12911;
v_12912:
    goto v_12927;
v_12919:
    v_13105 = elt(env, 5); // lie_cc
    goto v_12920;
v_12921:
    v_13104 = stack[-12];
    goto v_12922;
v_12923:
    v_13103 = stack[-10];
    goto v_12924;
v_12925:
    v_13102 = stack[-7];
    goto v_12926;
v_12927:
    goto v_12919;
v_12920:
    goto v_12921;
v_12922:
    goto v_12923;
v_12924:
    goto v_12925;
v_12926:
    stack[0] = list4(v_13105, v_13104, v_13103, v_13102);
    env = stack[-13];
    goto v_12913;
v_12914:
    goto v_12941;
v_12933:
    v_13105 = elt(env, 5); // lie_cc
    goto v_12934;
v_12935:
    v_13104 = stack[-9];
    goto v_12936;
v_12937:
    v_13103 = stack[-7];
    goto v_12938;
v_12939:
    v_13102 = stack[-8];
    goto v_12940;
v_12941:
    goto v_12933;
v_12934:
    goto v_12935;
v_12936:
    goto v_12937;
v_12938:
    goto v_12939;
v_12940:
    v_13102 = list4(v_13105, v_13104, v_13103, v_13102);
    env = stack[-13];
    goto v_12915;
v_12916:
    goto v_12910;
v_12911:
    goto v_12912;
v_12913:
    goto v_12914;
v_12915:
    stack[-2] = list3(stack[-1], stack[0], v_13102);
    env = stack[-13];
    goto v_12867;
v_12868:
    goto v_12953;
v_12947:
    stack[-1] = elt(env, 4); // times
    goto v_12948;
v_12949:
    goto v_12964;
v_12956:
    v_13105 = elt(env, 5); // lie_cc
    goto v_12957;
v_12958:
    v_13104 = stack[-9];
    goto v_12959;
v_12960:
    v_13103 = stack[-12];
    goto v_12961;
v_12962:
    v_13102 = stack[-7];
    goto v_12963;
v_12964:
    goto v_12956;
v_12957:
    goto v_12958;
v_12959:
    goto v_12960;
v_12961:
    goto v_12962;
v_12963:
    stack[0] = list4(v_13105, v_13104, v_13103, v_13102);
    env = stack[-13];
    goto v_12950;
v_12951:
    goto v_12978;
v_12970:
    v_13105 = elt(env, 5); // lie_cc
    goto v_12971;
v_12972:
    v_13104 = stack[-10];
    goto v_12973;
v_12974:
    v_13103 = stack[-7];
    goto v_12975;
v_12976:
    v_13102 = stack[-8];
    goto v_12977;
v_12978:
    goto v_12970;
v_12971:
    goto v_12972;
v_12973:
    goto v_12974;
v_12975:
    goto v_12976;
v_12977:
    v_13102 = list4(v_13105, v_13104, v_13103, v_13102);
    env = stack[-13];
    goto v_12952;
v_12953:
    goto v_12947;
v_12948:
    goto v_12949;
v_12950:
    goto v_12951;
v_12952:
    v_13102 = list3(stack[-1], stack[0], v_13102);
    env = stack[-13];
    goto v_12869;
v_12870:
    goto v_12862;
v_12863:
    goto v_12864;
v_12865:
    goto v_12866;
v_12867:
    goto v_12868;
v_12869:
    v_13102 = list4(stack[-4], stack[-3], stack[-2], v_13102);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13103 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    goto v_12855;
v_12856:
    v_13102 = stack[-6];
    goto v_12857;
v_12858:
    goto v_12852;
v_12853:
    goto v_12854;
v_12855:
    goto v_12856;
v_12857:
    v_13102 = list3(stack[-5], v_13103, v_13102);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13102 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    stack[-6] = v_13102;
    v_13102 = stack[-7];
    goto v_12994;
v_12988:
    v_13104 = elt(env, 3); // plus
    goto v_12989;
v_12990:
    v_13103 = v_13102;
    goto v_12991;
v_12992:
    v_13102 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12993;
v_12994:
    goto v_12988;
v_12989:
    goto v_12990;
v_12991:
    goto v_12992;
v_12993:
    v_13102 = list3(v_13104, v_13103, v_13102);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13102 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    stack[-7] = v_13102;
    goto v_12829;
v_12828:
    goto v_12821;
v_12822:
    v_13102 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12823;
v_12824:
    goto v_12820;
v_12821:
    goto v_12822;
v_12823:
    fn = elt(env, 10); // evalneq
    v_13102 = (*qfn2(fn))(fn, v_13103, v_13102);
    env = stack[-13];
    if (v_13102 == nil) goto v_12818;
    goto v_13004;
v_13000:
    stack[0] = elt(env, 1); // lie_jtest
    goto v_13001;
v_13002:
    v_13102 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 8); // aeval!*
    v_13102 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    goto v_13003;
v_13004:
    goto v_13000;
v_13001:
    goto v_13002;
v_13003:
    fn = elt(env, 7); // setk
    v_13102 = (*qfn2(fn))(fn, stack[0], v_13102);
    env = stack[-13];
    goto v_13016;
v_13010:
    v_13104 = elt(env, 2); // difference
    goto v_13011;
v_13012:
    v_13103 = stack[-11];
    goto v_13013;
v_13014:
    v_13102 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13015;
v_13016:
    goto v_13010;
v_13011:
    goto v_13012;
v_13013:
    goto v_13014;
v_13015:
    v_13102 = list3(v_13104, v_13103, v_13102);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13102 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    stack[-12] = v_13102;
    v_13102 = stack[-11];
    fn = elt(env, 8); // aeval!*
    v_13102 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    stack[-10] = v_13102;
    goto v_13030;
v_13024:
    v_13104 = elt(env, 3); // plus
    goto v_13025;
v_13026:
    v_13103 = stack[-11];
    goto v_13027;
v_13028:
    v_13102 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13029;
v_13030:
    goto v_13024;
v_13025:
    goto v_13026;
v_13027:
    goto v_13028;
v_13029:
    v_13102 = list3(v_13104, v_13103, v_13102);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13102 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    stack[-9] = v_13102;
    goto v_13042;
v_13036:
    v_13104 = elt(env, 3); // plus
    goto v_13037;
v_13038:
    v_13103 = stack[-11];
    goto v_13039;
v_13040:
    v_13102 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13041;
v_13042:
    goto v_13036;
v_13037:
    goto v_13038;
v_13039:
    goto v_13040;
v_13041:
    v_13102 = list3(v_13104, v_13103, v_13102);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13102 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    stack[-8] = v_13102;
    goto v_12816;
v_12818:
v_12816:
    v_13102 = stack[-8];
    goto v_13056;
v_13050:
    v_13104 = elt(env, 3); // plus
    goto v_13051;
v_13052:
    v_13103 = v_13102;
    goto v_13053;
v_13054:
    v_13102 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13055;
v_13056:
    goto v_13050;
v_13051:
    goto v_13052;
v_13053:
    goto v_13054;
v_13055:
    v_13102 = list3(v_13104, v_13103, v_13102);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13102 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    stack[-8] = v_13102;
    goto v_12795;
v_12794:
    v_13102 = stack[-9];
    goto v_13070;
v_13064:
    v_13104 = elt(env, 3); // plus
    goto v_13065;
v_13066:
    v_13103 = v_13102;
    goto v_13067;
v_13068:
    v_13102 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13069;
v_13070:
    goto v_13064;
v_13065:
    goto v_13066;
v_13067:
    goto v_13068;
v_13069:
    v_13102 = list3(v_13104, v_13103, v_13102);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13102 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    stack[-9] = v_13102;
    goto v_12771;
v_12770:
    v_13102 = stack[-10];
    goto v_13084;
v_13078:
    v_13104 = elt(env, 3); // plus
    goto v_13079;
v_13080:
    v_13103 = v_13102;
    goto v_13081;
v_13082:
    v_13102 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13083;
v_13084:
    goto v_13078;
v_13079:
    goto v_13080;
v_13081:
    goto v_13082;
v_13083:
    v_13102 = list3(v_13104, v_13103, v_13102);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13102 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    stack[-10] = v_13102;
    goto v_12737;
v_12736:
    v_13102 = stack[-12];
    goto v_13098;
v_13092:
    v_13104 = elt(env, 3); // plus
    goto v_13093;
v_13094:
    v_13103 = v_13102;
    goto v_13095;
v_13096:
    v_13102 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13097;
v_13098:
    goto v_13092;
v_13093:
    goto v_13094;
v_13095:
    goto v_13096;
v_13097:
    v_13102 = list3(v_13104, v_13103, v_13102);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13102 = (*qfn1(fn))(fn, v_13102);
    env = stack[-13];
    stack[-12] = v_13102;
    goto v_12704;
v_12703:
    v_13102 = nil;
    return onevalue(v_13102);
}



// Code for mv!-pow!-mv!-!+

static LispObject CC_mvKpowKmvKL(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12722, v_12723;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12689;
    stack[-1] = v_12688;
// end of prologue
    stack[-2] = nil;
v_12694:
    v_12722 = stack[0];
    if (v_12722 == nil) goto v_12697;
    else goto v_12698;
v_12697:
    v_12722 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12722);
    }
v_12698:
    goto v_12709;
v_12705:
    goto v_12715;
v_12711:
    v_12723 = stack[-1];
    goto v_12712;
v_12713:
    v_12722 = stack[0];
    v_12722 = qcar(v_12722);
    goto v_12714;
v_12715:
    goto v_12711;
v_12712:
    goto v_12713;
v_12714:
    fn = elt(env, 2); // mv!-pow!-mv!-term!-!+
    v_12723 = (*qfn2(fn))(fn, v_12723, v_12722);
    env = stack[-3];
    goto v_12706;
v_12707:
    v_12722 = stack[-2];
    goto v_12708;
v_12709:
    goto v_12705;
v_12706:
    goto v_12707;
v_12708:
    v_12722 = cons(v_12723, v_12722);
    env = stack[-3];
    stack[-2] = v_12722;
    v_12722 = stack[0];
    v_12722 = qcdr(v_12722);
    stack[0] = v_12722;
    goto v_12694;
    v_12722 = nil;
    return onevalue(v_12722);
}



// Code for ilcm

static LispObject CC_ilcm(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12762, v_12763, v_12764, v_12765;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_12764 = v_12689;
    v_12765 = v_12688;
// end of prologue
    goto v_12703;
v_12699:
    v_12763 = v_12765;
    goto v_12700;
v_12701:
    v_12762 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12702;
v_12703:
    goto v_12699;
v_12700:
    goto v_12701;
v_12702:
    if (v_12763 == v_12762) goto v_12697;
    else goto v_12698;
v_12697:
    v_12762 = lisp_true;
    goto v_12696;
v_12698:
    goto v_12713;
v_12709:
    v_12763 = v_12764;
    goto v_12710;
v_12711:
    v_12762 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12712;
v_12713:
    goto v_12709;
v_12710:
    goto v_12711;
v_12712:
    v_12762 = (v_12763 == v_12762 ? lisp_true : nil);
    goto v_12696;
    v_12762 = nil;
v_12696:
    if (v_12762 == nil) goto v_12694;
    v_12762 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12692;
v_12694:
    goto v_12724;
v_12720:
    v_12763 = v_12765;
    goto v_12721;
v_12722:
    v_12762 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12723;
v_12724:
    goto v_12720;
v_12721:
    goto v_12722;
v_12723:
    if (v_12763 == v_12762) goto v_12718;
    else goto v_12719;
v_12718:
    v_12762 = v_12764;
    goto v_12692;
v_12719:
    goto v_12734;
v_12730:
    v_12763 = v_12764;
    goto v_12731;
v_12732:
    v_12762 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12733;
v_12734:
    goto v_12730;
v_12731:
    goto v_12732;
v_12733:
    if (v_12763 == v_12762) goto v_12728;
    else goto v_12729;
v_12728:
    v_12762 = v_12765;
    goto v_12692;
v_12729:
    goto v_12745;
v_12741:
    stack[-1] = v_12765;
    goto v_12742;
v_12743:
    goto v_12752;
v_12748:
    stack[0] = v_12764;
    goto v_12749;
v_12750:
    goto v_12759;
v_12755:
    v_12762 = v_12765;
    goto v_12756;
v_12757:
    v_12763 = v_12764;
    goto v_12758;
v_12759:
    goto v_12755;
v_12756:
    goto v_12757;
v_12758:
    v_12762 = Lgcd(nil, v_12762, v_12763);
    env = stack[-2];
    goto v_12751;
v_12752:
    goto v_12748;
v_12749:
    goto v_12750;
v_12751:
    v_12762 = quot2(stack[0], v_12762);
    goto v_12744;
v_12745:
    goto v_12741;
v_12742:
    goto v_12743;
v_12744:
    {
        LispObject v_12768 = stack[-1];
        return times2(v_12768, v_12762);
    }
    v_12762 = nil;
v_12692:
    return onevalue(v_12762);
}



// Code for symbvarlst

static LispObject CC_symbvarlst(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12795, v_12796, v_12797;
    LispObject fn;
    LispObject v_12690, v_12689, v_12688;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "symbvarlst");
    va_start(aa, nargs);
    v_12688 = va_arg(aa, LispObject);
    v_12689 = va_arg(aa, LispObject);
    v_12690 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12690,v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12688,v_12689,v_12690);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_12795 = v_12690;
    stack[-3] = v_12689;
    v_12797 = v_12688;
// end of prologue
    goto v_12704;
v_12700:
    v_12796 = v_12795;
    goto v_12701;
v_12702:
    v_12795 = elt(env, 1); // symbolic
    goto v_12703;
v_12704:
    goto v_12700;
v_12701:
    goto v_12702;
v_12703:
    if (v_12796 == v_12795) goto v_12699;
    v_12795 = nil;
    goto v_12695;
v_12699:
    v_12795 = v_12797;
    stack[-4] = v_12795;
v_12711:
    v_12795 = stack[-4];
    if (v_12795 == nil) goto v_12714;
    else goto v_12715;
v_12714:
    goto v_12710;
v_12715:
    v_12795 = stack[-4];
    v_12795 = qcar(v_12795);
    v_12795 = Lconsp(nil, v_12795);
    env = stack[-5];
    if (v_12795 == nil) goto v_12721;
    v_12795 = stack[-4];
    v_12795 = qcar(v_12795);
    v_12795 = qcar(v_12795);
    goto v_12719;
v_12721:
    v_12795 = stack[-4];
    v_12795 = qcar(v_12795);
    goto v_12719;
    v_12795 = nil;
v_12719:
    stack[0] = v_12795;
    v_12795 = stack[0];
    v_12795 = Lsymbol_specialp(nil, v_12795);
    env = stack[-5];
    if (v_12795 == nil) goto v_12738;
    else goto v_12739;
v_12738:
    v_12795 = stack[0];
    v_12795 = Lsymbol_globalp(nil, v_12795);
    env = stack[-5];
    if (v_12795 == nil) goto v_12744;
    else goto v_12745;
v_12744:
    goto v_12757;
v_12753:
    v_12796 = stack[0];
    goto v_12754;
v_12755:
    v_12795 = stack[-3];
    goto v_12756;
v_12757:
    goto v_12753;
v_12754:
    goto v_12755;
v_12756:
    v_12795 = Lsmemq(nil, v_12796, v_12795);
    env = stack[-5];
    if (v_12795 == nil) goto v_12750;
    else goto v_12751;
v_12750:
    v_12795 = qvalue(elt(env, 2)); // !*novarmsg
    v_12795 = (v_12795 == nil ? lisp_true : nil);
    goto v_12749;
v_12751:
    v_12795 = nil;
    goto v_12749;
    v_12795 = nil;
v_12749:
    goto v_12743;
v_12745:
    v_12795 = nil;
    goto v_12743;
    v_12795 = nil;
v_12743:
    goto v_12737;
v_12739:
    v_12795 = nil;
    goto v_12737;
    v_12795 = nil;
v_12737:
    if (v_12795 == nil) goto v_12735;
    goto v_12781;
v_12773:
    stack[-2] = elt(env, 3); // "local variable"
    goto v_12774;
v_12775:
    stack[-1] = stack[0];
    goto v_12776;
v_12777:
    stack[0] = elt(env, 4); // "in procedure"
    goto v_12778;
v_12779:
    goto v_12790;
v_12786:
    v_12796 = qvalue(elt(env, 5)); // fname!*
    goto v_12787;
v_12788:
    v_12795 = elt(env, 6); // "not used"
    goto v_12789;
v_12790:
    goto v_12786;
v_12787:
    goto v_12788;
v_12789:
    v_12795 = list2(v_12796, v_12795);
    env = stack[-5];
    goto v_12780;
v_12781:
    goto v_12773;
v_12774:
    goto v_12775;
v_12776:
    goto v_12777;
v_12778:
    goto v_12779;
v_12780:
    v_12795 = list3star(stack[-2], stack[-1], stack[0], v_12795);
    env = stack[-5];
    fn = elt(env, 7); // lprim
    v_12795 = (*qfn1(fn))(fn, v_12795);
    env = stack[-5];
    goto v_12733;
v_12735:
v_12733:
    v_12795 = stack[-4];
    v_12795 = qcdr(v_12795);
    stack[-4] = v_12795;
    goto v_12711;
v_12710:
    v_12795 = nil;
v_12695:
    return onevalue(v_12795);
}



// Code for ezgcdf1

static LispObject CC_ezgcdf1(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12703, v_12704, v_12705;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_12704 = v_12689;
    v_12705 = v_12688;
// end of prologue
    v_12703 = (LispObject)0+TAG_FIXNUM; // 0
// Binding factor!-level
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_12703; // factor!-level
    goto v_12700;
v_12696:
    v_12703 = v_12705;
    goto v_12697;
v_12698:
    goto v_12699;
v_12700:
    goto v_12696;
v_12697:
    goto v_12698;
v_12699:
    v_12703 = list2(v_12703, v_12704);
    env = stack[-1];
    fn = elt(env, 2); // gcdlist
    v_12703 = (*qfn1(fn))(fn, v_12703);
    env = stack[-1];
    fn = elt(env, 3); // poly!-abs
    v_12703 = (*qfn1(fn))(fn, v_12703);
    ;}  // end of a binding scope
    return onevalue(v_12703);
}



// Code for talp_eqnrhskernels

static LispObject CC_talp_eqnrhskernels(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12693;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12693 = v_12688;
// end of prologue
    v_12693 = qcdr(v_12693);
    {
        fn = elt(env, 1); // talp_varlt
        return (*qfn1(fn))(fn, v_12693);
    }
}



// Code for qqe_arg!-check

static LispObject CC_qqe_argKcheck(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12776, v_12777;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12688;
// end of prologue
    v_12776 = stack[0];
    v_12776 = qcar(v_12776);
    stack[-1] = v_12776;
    v_12776 = stack[-1];
    fn = elt(env, 3); // qqe_rqopp
    v_12776 = (*qfn1(fn))(fn, v_12776);
    env = stack[-2];
    if (v_12776 == nil) goto v_12696;
    v_12776 = stack[0];
    fn = elt(env, 4); // qqe_arg!-check!-lq!-rq
    v_12776 = (*qfn1(fn))(fn, v_12776);
    goto v_12694;
v_12696:
    v_12776 = stack[-1];
    fn = elt(env, 5); // qqe_rbopp
    v_12776 = (*qfn1(fn))(fn, v_12776);
    env = stack[-2];
    if (v_12776 == nil) goto v_12702;
    v_12776 = stack[0];
    fn = elt(env, 6); // qqe_arg!-check!-lb!-rb
    v_12776 = (*qfn1(fn))(fn, v_12776);
    goto v_12694;
v_12702:
    v_12776 = stack[-1];
    fn = elt(env, 7); // qqe_qopheadp
    v_12776 = (*qfn1(fn))(fn, v_12776);
    env = stack[-2];
    if (v_12776 == nil) goto v_12709;
    else goto v_12707;
v_12709:
    v_12776 = stack[-1];
    fn = elt(env, 8); // qqe_qoptailp
    v_12776 = (*qfn1(fn))(fn, v_12776);
    env = stack[-2];
    if (v_12776 == nil) goto v_12712;
    else goto v_12707;
v_12712:
    goto v_12708;
v_12707:
    v_12776 = stack[0];
    v_12776 = qcdr(v_12776);
    v_12776 = qcar(v_12776);
    fn = elt(env, 9); // qqe_arg!-check!-q
    v_12776 = (*qfn1(fn))(fn, v_12776);
    env = stack[-2];
    if (v_12776 == nil) goto v_12717;
    else goto v_12718;
v_12717:
    fn = elt(env, 10); // qqe_arg!-check!-marked!-ids!-rollback
    v_12776 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_12729;
v_12725:
    v_12777 = stack[0];
    goto v_12726;
v_12727:
    v_12776 = elt(env, 1); // "some arguments are not of queue type"
    goto v_12728;
v_12729:
    goto v_12725;
v_12726:
    goto v_12727;
v_12728:
    fn = elt(env, 11); // typerr
    v_12776 = (*qfn2(fn))(fn, v_12777, v_12776);
    goto v_12716;
v_12718:
v_12716:
    goto v_12694;
v_12708:
    v_12776 = stack[-1];
    fn = elt(env, 12); // qqe_qopaddp
    v_12776 = (*qfn1(fn))(fn, v_12776);
    env = stack[-2];
    if (v_12776 == nil) goto v_12735;
    v_12776 = stack[0];
    fn = elt(env, 13); // qqe_arg!-check!-lb!-rq
    v_12776 = (*qfn1(fn))(fn, v_12776);
    goto v_12694;
v_12735:
    v_12776 = stack[0];
    v_12776 = qcdr(v_12776);
    stack[-1] = v_12776;
v_12745:
    v_12776 = stack[-1];
    if (v_12776 == nil) goto v_12750;
    else goto v_12751;
v_12750:
    goto v_12744;
v_12751:
    v_12776 = stack[-1];
    v_12776 = qcar(v_12776);
    fn = elt(env, 14); // qqe_arg!-check!-b
    v_12776 = (*qfn1(fn))(fn, v_12776);
    env = stack[-2];
    if (v_12776 == nil) goto v_12759;
    else goto v_12760;
v_12759:
    fn = elt(env, 10); // qqe_arg!-check!-marked!-ids!-rollback
    v_12776 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_12769;
v_12765:
    v_12777 = stack[0];
    goto v_12766;
v_12767:
    v_12776 = elt(env, 2); // "some arguments are not of basic type"
    goto v_12768;
v_12769:
    goto v_12765;
v_12766:
    goto v_12767;
v_12768:
    fn = elt(env, 11); // typerr
    v_12776 = (*qfn2(fn))(fn, v_12777, v_12776);
    env = stack[-2];
    goto v_12758;
v_12760:
v_12758:
    v_12776 = stack[-1];
    v_12776 = qcdr(v_12776);
    stack[-1] = v_12776;
    goto v_12745;
v_12744:
    goto v_12694;
v_12694:
    v_12776 = nil;
    return onevalue(v_12776);
}



// Code for delet

static LispObject CC_delet(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12760, v_12761, v_12762;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12689;
    stack[-1] = v_12688;
// end of prologue
    v_12762 = nil;
v_12694:
    v_12760 = stack[-1];
    if (v_12760 == nil) goto v_12697;
    else goto v_12698;
v_12697:
    goto v_12705;
v_12701:
    v_12761 = v_12762;
    goto v_12702;
v_12703:
    v_12760 = stack[0];
    goto v_12704;
v_12705:
    goto v_12701;
v_12702:
    goto v_12703;
v_12704:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_12761, v_12760);
    }
v_12698:
    v_12760 = stack[0];
    if (v_12760 == nil) goto v_12712;
    else goto v_12713;
v_12712:
    v_12760 = lisp_true;
    goto v_12711;
v_12713:
    goto v_12722;
v_12718:
    v_12761 = stack[-1];
    goto v_12719;
v_12720:
    v_12760 = stack[0];
    goto v_12721;
v_12722:
    goto v_12718;
v_12719:
    goto v_12720;
v_12721:
    v_12760 = (equal(v_12761, v_12760) ? lisp_true : nil);
    goto v_12711;
    v_12760 = nil;
v_12711:
    if (v_12760 == nil) goto v_12709;
    v_12760 = v_12762;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12760);
    }
v_12709:
    goto v_12734;
v_12730:
    v_12761 = stack[-1];
    goto v_12731;
v_12732:
    v_12760 = stack[0];
    v_12760 = qcar(v_12760);
    goto v_12733;
v_12734:
    goto v_12730;
v_12731:
    goto v_12732;
v_12733:
    if (equal(v_12761, v_12760)) goto v_12728;
    else goto v_12729;
v_12728:
    goto v_12743;
v_12739:
    v_12761 = v_12762;
    goto v_12740;
v_12741:
    v_12760 = stack[0];
    v_12760 = qcdr(v_12760);
    goto v_12742;
v_12743:
    goto v_12739;
v_12740:
    goto v_12741;
v_12742:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_12761, v_12760);
    }
v_12729:
    goto v_12754;
v_12750:
    v_12760 = stack[0];
    v_12760 = qcar(v_12760);
    goto v_12751;
v_12752:
    v_12761 = v_12762;
    goto v_12753;
v_12754:
    goto v_12750;
v_12751:
    goto v_12752;
v_12753:
    v_12760 = cons(v_12760, v_12761);
    env = stack[-2];
    v_12762 = v_12760;
    v_12760 = stack[0];
    v_12760 = qcdr(v_12760);
    stack[0] = v_12760;
    goto v_12694;
    v_12760 = nil;
    return onevalue(v_12760);
}



// Code for cl_qb

static LispObject CC_cl_qb(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12756, v_12757, v_12758, v_12759, v_12760;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12688;
// end of prologue
    v_12760 = nil;
    v_12756 = (LispObject)0+TAG_FIXNUM; // 0
    v_12759 = v_12756;
v_12698:
    v_12756 = stack[0];
    if (!consp(v_12756)) goto v_12705;
    else goto v_12706;
v_12705:
    v_12756 = stack[0];
    goto v_12704;
v_12706:
    v_12756 = stack[0];
    v_12756 = qcar(v_12756);
    goto v_12704;
    v_12756 = nil;
v_12704:
    stack[-1] = v_12756;
    v_12758 = v_12756;
    goto v_12722;
v_12718:
    v_12757 = v_12758;
    goto v_12719;
v_12720:
    v_12756 = elt(env, 1); // ex
    goto v_12721;
v_12722:
    goto v_12718;
v_12719:
    goto v_12720;
v_12721:
    if (v_12757 == v_12756) goto v_12716;
    else goto v_12717;
v_12716:
    v_12756 = lisp_true;
    goto v_12715;
v_12717:
    goto v_12732;
v_12728:
    v_12757 = v_12758;
    goto v_12729;
v_12730:
    v_12756 = elt(env, 2); // all
    goto v_12731;
v_12732:
    goto v_12728;
v_12729:
    goto v_12730;
v_12731:
    v_12756 = (v_12757 == v_12756 ? lisp_true : nil);
    goto v_12715;
    v_12756 = nil;
v_12715:
    if (v_12756 == nil) goto v_12701;
    else goto v_12702;
v_12701:
    goto v_12697;
v_12702:
    goto v_12745;
v_12741:
    v_12757 = stack[-1];
    goto v_12742;
v_12743:
    v_12756 = v_12760;
    goto v_12744;
v_12745:
    goto v_12741;
v_12742:
    goto v_12743;
v_12744:
    if (equal(v_12757, v_12756)) goto v_12740;
    v_12756 = v_12759;
    v_12756 = add1(v_12756);
    env = stack[-2];
    v_12759 = v_12756;
    v_12756 = stack[-1];
    v_12760 = v_12756;
    goto v_12738;
v_12740:
v_12738:
    v_12756 = stack[0];
    v_12756 = qcdr(v_12756);
    v_12756 = qcdr(v_12756);
    v_12756 = qcar(v_12756);
    stack[0] = v_12756;
    goto v_12698;
v_12697:
    v_12756 = v_12759;
    return onevalue(v_12756);
}



// Code for horner!-rule!-mod!-p

static LispObject CC_hornerKruleKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12844, v_12845, v_12846, v_12847, v_12848;
    LispObject fn;
    LispObject v_12692, v_12691, v_12690, v_12689, v_12688;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "horner-rule-mod-p");
    va_start(aa, nargs);
    v_12688 = va_arg(aa, LispObject);
    v_12689 = va_arg(aa, LispObject);
    v_12690 = va_arg(aa, LispObject);
    v_12691 = va_arg(aa, LispObject);
    v_12692 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_12692,v_12691,v_12690,v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_12688,v_12689,v_12690,v_12691,v_12692);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_12692;
    stack[-3] = v_12691;
    stack[-4] = v_12690;
    v_12846 = v_12689;
    v_12847 = v_12688;
// end of prologue
v_12687:
    v_12844 = stack[-4];
    if (!consp(v_12844)) goto v_12704;
    else goto v_12705;
v_12704:
    v_12844 = lisp_true;
    goto v_12703;
v_12705:
    v_12844 = stack[-4];
    v_12844 = qcar(v_12844);
    v_12844 = (consp(v_12844) ? nil : lisp_true);
    goto v_12703;
    v_12844 = nil;
v_12703:
    if (v_12844 == nil) goto v_12701;
    v_12844 = lisp_true;
    goto v_12699;
v_12701:
    goto v_12720;
v_12716:
    v_12844 = stack[-4];
    v_12844 = qcar(v_12844);
    v_12844 = qcar(v_12844);
    v_12845 = qcar(v_12844);
    goto v_12717;
v_12718:
    v_12844 = stack[-2];
    goto v_12719;
v_12720:
    goto v_12716;
v_12717:
    goto v_12718;
v_12719:
    v_12844 = (equal(v_12845, v_12844) ? lisp_true : nil);
    v_12844 = (v_12844 == nil ? lisp_true : nil);
    goto v_12699;
    v_12844 = nil;
v_12699:
    if (v_12844 == nil) goto v_12697;
    v_12844 = stack[-3];
    if (v_12844 == nil) goto v_12734;
    else goto v_12735;
v_12734:
    v_12844 = lisp_true;
    goto v_12733;
v_12735:
    v_12844 = stack[-3];
    v_12844 = (LispObject)zerop(v_12844);
    v_12844 = v_12844 ? lisp_true : nil;
    env = stack[-6];
    goto v_12733;
    v_12844 = nil;
v_12733:
    if (v_12844 == nil) goto v_12731;
    v_12844 = stack[-4];
    goto v_12729;
v_12731:
    goto v_12750;
v_12746:
    stack[0] = v_12847;
    goto v_12747;
v_12748:
    goto v_12757;
v_12753:
    v_12844 = stack[-3];
    goto v_12754;
v_12755:
    v_12845 = v_12846;
    goto v_12756;
v_12757:
    goto v_12753;
v_12754:
    goto v_12755;
v_12756:
    fn = elt(env, 1); // expt!-mod!-p
    v_12844 = (*qfn2(fn))(fn, v_12844, v_12845);
    env = stack[-6];
    goto v_12749;
v_12750:
    goto v_12746;
v_12747:
    goto v_12748;
v_12749:
    fn = elt(env, 2); // times!-mod!-p
    v_12844 = (*qfn2(fn))(fn, stack[0], v_12844);
    env = stack[-6];
    v_12847 = v_12844;
    goto v_12765;
v_12761:
    v_12844 = stack[-4];
    goto v_12762;
v_12763:
    v_12845 = v_12847;
    goto v_12764;
v_12765:
    goto v_12761;
v_12762:
    goto v_12763;
v_12764:
    {
        fn = elt(env, 3); // plus!-mod!-p
        return (*qfn2(fn))(fn, v_12844, v_12845);
    }
    v_12844 = nil;
v_12729:
    goto v_12695;
v_12697:
    v_12844 = stack[-4];
    v_12844 = qcar(v_12844);
    v_12844 = qcar(v_12844);
    v_12844 = qcdr(v_12844);
    stack[-5] = v_12844;
    goto v_12788;
v_12778:
    v_12844 = stack[-3];
    if (v_12844 == nil) goto v_12795;
    else goto v_12796;
v_12795:
    v_12844 = lisp_true;
    goto v_12794;
v_12796:
    v_12844 = stack[-3];
    v_12844 = (LispObject)zerop(v_12844);
    v_12844 = v_12844 ? lisp_true : nil;
    env = stack[-6];
    goto v_12794;
    v_12844 = nil;
v_12794:
    if (v_12844 == nil) goto v_12792;
    v_12844 = stack[-4];
    v_12844 = qcar(v_12844);
    v_12844 = qcdr(v_12844);
    v_12847 = v_12844;
    goto v_12790;
v_12792:
    goto v_12813;
v_12809:
    v_12844 = stack[-4];
    v_12844 = qcar(v_12844);
    stack[-1] = qcdr(v_12844);
    goto v_12810;
v_12811:
    goto v_12822;
v_12818:
    stack[0] = v_12847;
    goto v_12819;
v_12820:
    goto v_12829;
v_12825:
    v_12845 = stack[-3];
    goto v_12826;
v_12827:
    goto v_12835;
v_12831:
    goto v_12832;
v_12833:
    v_12844 = stack[-5];
    goto v_12834;
v_12835:
    goto v_12831;
v_12832:
    goto v_12833;
v_12834:
    v_12844 = (LispObject)(intptr_t)((intptr_t)v_12846 - (intptr_t)v_12844 + TAG_FIXNUM);
    goto v_12828;
v_12829:
    goto v_12825;
v_12826:
    goto v_12827;
v_12828:
    fn = elt(env, 1); // expt!-mod!-p
    v_12844 = (*qfn2(fn))(fn, v_12845, v_12844);
    env = stack[-6];
    goto v_12821;
v_12822:
    goto v_12818;
v_12819:
    goto v_12820;
v_12821:
    fn = elt(env, 2); // times!-mod!-p
    v_12844 = (*qfn2(fn))(fn, stack[0], v_12844);
    env = stack[-6];
    goto v_12812;
v_12813:
    goto v_12809;
v_12810:
    goto v_12811;
v_12812:
    fn = elt(env, 3); // plus!-mod!-p
    v_12844 = (*qfn2(fn))(fn, stack[-1], v_12844);
    env = stack[-6];
    v_12847 = v_12844;
    goto v_12790;
    v_12847 = nil;
v_12790:
    goto v_12779;
v_12780:
    v_12846 = stack[-5];
    goto v_12781;
v_12782:
    v_12844 = stack[-4];
    v_12848 = qcdr(v_12844);
    goto v_12783;
v_12784:
    v_12845 = stack[-3];
    goto v_12785;
v_12786:
    v_12844 = stack[-2];
    goto v_12787;
v_12788:
    goto v_12778;
v_12779:
    goto v_12780;
v_12781:
    goto v_12782;
v_12783:
    goto v_12784;
v_12785:
    goto v_12786;
v_12787:
    stack[-4] = v_12848;
    stack[-3] = v_12845;
    stack[-2] = v_12844;
    goto v_12687;
    goto v_12695;
    v_12844 = nil;
v_12695:
    return onevalue(v_12844);
}



// Code for getsetvars

static LispObject CC_getsetvars(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12756, v_12757;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12688;
// end of prologue
    stack[-1] = nil;
v_12693:
    v_12756 = stack[0];
    if (!consp(v_12756)) goto v_12696;
    else goto v_12697;
v_12696:
    v_12756 = stack[-1];
    {
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(fn, v_12756);
    }
v_12697:
    goto v_12707;
v_12703:
    v_12756 = stack[0];
    v_12757 = qcar(v_12756);
    goto v_12704;
v_12705:
    v_12756 = elt(env, 1); // (setel setk)
    goto v_12706;
v_12707:
    goto v_12703;
v_12704:
    goto v_12705;
v_12706:
    v_12756 = Lmemq(nil, v_12757, v_12756);
    if (v_12756 == nil) goto v_12702;
    goto v_12717;
v_12713:
    v_12756 = stack[0];
    v_12756 = qcdr(v_12756);
    v_12756 = qcar(v_12756);
    fn = elt(env, 4); // getsetvarlis
    v_12757 = (*qfn1(fn))(fn, v_12756);
    env = stack[-2];
    goto v_12714;
v_12715:
    v_12756 = stack[-1];
    goto v_12716;
v_12717:
    goto v_12713;
v_12714:
    goto v_12715;
v_12716:
    v_12756 = cons(v_12757, v_12756);
    env = stack[-2];
    stack[-1] = v_12756;
    v_12756 = stack[0];
    v_12756 = qcdr(v_12756);
    v_12756 = qcdr(v_12756);
    v_12756 = qcar(v_12756);
    stack[0] = v_12756;
    goto v_12693;
v_12702:
    goto v_12733;
v_12729:
    v_12756 = stack[0];
    v_12757 = qcar(v_12756);
    goto v_12730;
v_12731:
    v_12756 = elt(env, 2); // setq
    goto v_12732;
v_12733:
    goto v_12729;
v_12730:
    goto v_12731;
v_12732:
    if (v_12757 == v_12756) goto v_12727;
    else goto v_12728;
v_12727:
    goto v_12742;
v_12738:
    v_12756 = stack[0];
    v_12756 = qcdr(v_12756);
    v_12756 = qcar(v_12756);
    v_12757 = Lmkquote(nil, v_12756);
    env = stack[-2];
    goto v_12739;
v_12740:
    v_12756 = stack[-1];
    goto v_12741;
v_12742:
    goto v_12738;
v_12739:
    goto v_12740;
v_12741:
    v_12756 = cons(v_12757, v_12756);
    env = stack[-2];
    stack[-1] = v_12756;
    v_12756 = stack[0];
    v_12756 = qcdr(v_12756);
    v_12756 = qcdr(v_12756);
    v_12756 = qcar(v_12756);
    stack[0] = v_12756;
    goto v_12693;
v_12728:
    v_12756 = stack[-1];
    {
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(fn, v_12756);
    }
    v_12756 = nil;
    return onevalue(v_12756);
}



// Code for mchkopt1

static LispObject CC_mchkopt1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12875, v_12876, v_12877;
    LispObject fn;
    LispObject v_12690, v_12689, v_12688;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mchkopt1");
    va_start(aa, nargs);
    v_12688 = va_arg(aa, LispObject);
    v_12689 = va_arg(aa, LispObject);
    v_12690 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12690,v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12688,v_12689,v_12690);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_12690;
    v_12875 = v_12689;
    v_12877 = v_12688;
// end of prologue
    v_12875 = qcdr(v_12875);
    v_12876 = v_12875;
    if (v_12875 == nil) goto v_12699;
    else goto v_12700;
v_12699:
    v_12875 = nil;
    goto v_12696;
v_12700:
    v_12875 = v_12876;
    v_12875 = qcar(v_12875);
    stack[-3] = v_12875;
    v_12875 = v_12876;
    v_12875 = qcdr(v_12875);
    v_12876 = v_12875;
    if (v_12875 == nil) goto v_12708;
    else goto v_12709;
v_12708:
    v_12875 = nil;
    goto v_12696;
v_12709:
    v_12875 = v_12876;
    v_12875 = qcar(v_12875);
    stack[-5] = v_12875;
    v_12875 = v_12876;
    v_12875 = qcdr(v_12875);
    if (v_12875 == nil) goto v_12718;
    v_12875 = nil;
    goto v_12696;
v_12718:
    v_12875 = stack[-3];
    if (!symbolp(v_12875)) v_12875 = nil;
    else { v_12875 = qfastgets(v_12875);
           if (v_12875 != nil) { v_12875 = elt(v_12875, 6); // optional
#ifdef RECORD_GET
             if (v_12875 == SPID_NOPROP)
                record_get(elt(fastget_names, 6), 0),
                v_12875 = nil;
             else record_get(elt(fastget_names, 6), 1),
                v_12875 = lisp_true; }
           else record_get(elt(fastget_names, 6), 0); }
#else
             if (v_12875 == SPID_NOPROP) v_12875 = nil; else v_12875 = lisp_true; }}
#endif
    if (v_12875 == nil) goto v_12725;
    goto v_12739;
v_12735:
    v_12876 = v_12877;
    goto v_12736;
v_12737:
    v_12875 = stack[-5];
    goto v_12738;
v_12739:
    goto v_12735;
v_12736:
    goto v_12737;
v_12738:
    fn = elt(env, 1); // mchk
    v_12875 = (*qfn2(fn))(fn, v_12876, v_12875);
    env = stack[-6];
    stack[-5] = v_12875;
    v_12875 = stack[-5];
    if (v_12875 == nil) goto v_12744;
    else goto v_12745;
v_12744:
    v_12875 = nil;
    goto v_12732;
v_12745:
    v_12875 = stack[-5];
    v_12875 = qcar(v_12875);
    goto v_12759;
v_12753:
    v_12877 = stack[-3];
    goto v_12754;
v_12755:
    v_12876 = stack[-4];
    v_12876 = qcar(v_12876);
    goto v_12756;
v_12757:
    goto v_12758;
v_12759:
    goto v_12753;
v_12754:
    goto v_12755;
v_12756:
    goto v_12757;
v_12758:
    v_12875 = acons(v_12877, v_12876, v_12875);
    env = stack[-6];
    v_12875 = ncons(v_12875);
    env = stack[-6];
    stack[-1] = v_12875;
    stack[-2] = v_12875;
v_12733:
    v_12875 = stack[-5];
    v_12875 = qcdr(v_12875);
    stack[-5] = v_12875;
    v_12875 = stack[-5];
    if (v_12875 == nil) goto v_12768;
    else goto v_12769;
v_12768:
    v_12875 = stack[-2];
    goto v_12732;
v_12769:
    goto v_12777;
v_12773:
    stack[0] = stack[-1];
    goto v_12774;
v_12775:
    v_12875 = stack[-5];
    v_12875 = qcar(v_12875);
    goto v_12790;
v_12784:
    v_12877 = stack[-3];
    goto v_12785;
v_12786:
    v_12876 = stack[-4];
    v_12876 = qcar(v_12876);
    goto v_12787;
v_12788:
    goto v_12789;
v_12790:
    goto v_12784;
v_12785:
    goto v_12786;
v_12787:
    goto v_12788;
v_12789:
    v_12875 = acons(v_12877, v_12876, v_12875);
    env = stack[-6];
    v_12875 = ncons(v_12875);
    env = stack[-6];
    goto v_12776;
v_12777:
    goto v_12773;
v_12774:
    goto v_12775;
v_12776:
    v_12875 = Lrplacd(nil, stack[0], v_12875);
    env = stack[-6];
    v_12875 = stack[-1];
    v_12875 = qcdr(v_12875);
    stack[-1] = v_12875;
    goto v_12733;
v_12732:
    goto v_12723;
v_12725:
    v_12875 = stack[-5];
    if (!symbolp(v_12875)) v_12875 = nil;
    else { v_12875 = qfastgets(v_12875);
           if (v_12875 != nil) { v_12875 = elt(v_12875, 6); // optional
#ifdef RECORD_GET
             if (v_12875 == SPID_NOPROP)
                record_get(elt(fastget_names, 6), 0),
                v_12875 = nil;
             else record_get(elt(fastget_names, 6), 1),
                v_12875 = lisp_true; }
           else record_get(elt(fastget_names, 6), 0); }
#else
             if (v_12875 == SPID_NOPROP) v_12875 = nil; else v_12875 = lisp_true; }}
#endif
    if (v_12875 == nil) goto v_12798;
    goto v_12812;
v_12808:
    v_12876 = v_12877;
    goto v_12809;
v_12810:
    v_12875 = stack[-3];
    goto v_12811;
v_12812:
    goto v_12808;
v_12809:
    goto v_12810;
v_12811:
    fn = elt(env, 1); // mchk
    v_12875 = (*qfn2(fn))(fn, v_12876, v_12875);
    env = stack[-6];
    stack[-3] = v_12875;
    v_12875 = stack[-3];
    if (v_12875 == nil) goto v_12817;
    else goto v_12818;
v_12817:
    v_12875 = nil;
    goto v_12805;
v_12818:
    v_12875 = stack[-3];
    v_12875 = qcar(v_12875);
    goto v_12832;
v_12826:
    v_12877 = stack[-5];
    goto v_12827;
v_12828:
    v_12876 = stack[-4];
    v_12876 = qcdr(v_12876);
    v_12876 = qcar(v_12876);
    goto v_12829;
v_12830:
    goto v_12831;
v_12832:
    goto v_12826;
v_12827:
    goto v_12828;
v_12829:
    goto v_12830;
v_12831:
    v_12875 = acons(v_12877, v_12876, v_12875);
    env = stack[-6];
    v_12875 = ncons(v_12875);
    env = stack[-6];
    stack[-1] = v_12875;
    stack[-2] = v_12875;
v_12806:
    v_12875 = stack[-3];
    v_12875 = qcdr(v_12875);
    stack[-3] = v_12875;
    v_12875 = stack[-3];
    if (v_12875 == nil) goto v_12842;
    else goto v_12843;
v_12842:
    v_12875 = stack[-2];
    goto v_12805;
v_12843:
    goto v_12851;
v_12847:
    stack[0] = stack[-1];
    goto v_12848;
v_12849:
    v_12875 = stack[-3];
    v_12875 = qcar(v_12875);
    goto v_12864;
v_12858:
    v_12877 = stack[-5];
    goto v_12859;
v_12860:
    v_12876 = stack[-4];
    v_12876 = qcdr(v_12876);
    v_12876 = qcar(v_12876);
    goto v_12861;
v_12862:
    goto v_12863;
v_12864:
    goto v_12858;
v_12859:
    goto v_12860;
v_12861:
    goto v_12862;
v_12863:
    v_12875 = acons(v_12877, v_12876, v_12875);
    env = stack[-6];
    v_12875 = ncons(v_12875);
    env = stack[-6];
    goto v_12850;
v_12851:
    goto v_12847;
v_12848:
    goto v_12849;
v_12850:
    v_12875 = Lrplacd(nil, stack[0], v_12875);
    env = stack[-6];
    v_12875 = stack[-1];
    v_12875 = qcdr(v_12875);
    stack[-1] = v_12875;
    goto v_12806;
v_12805:
    goto v_12723;
v_12798:
    v_12875 = nil;
    goto v_12723;
    v_12875 = nil;
v_12723:
v_12696:
    return onevalue(v_12875);
}



// Code for ps!:evaluate

static LispObject CC_psTevaluate(LispObject env,
                         LispObject v_12689, LispObject v_12690)
{
    env = qenv(env);
    LispObject v_12745, v_12746;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12690,v_12689);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12689,v_12690);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_12690;
    v_12745 = v_12689;
// end of prologue
// Binding ps
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = v_12745; // ps
    goto v_12704;
v_12700:
    v_12746 = qvalue(elt(env, 1)); // ps
    goto v_12701;
v_12702:
    v_12745 = stack[-2];
    goto v_12703;
v_12704:
    goto v_12700;
v_12701:
    goto v_12702;
v_12703:
    fn = elt(env, 2); // ps!:get!-term
    v_12745 = (*qfn2(fn))(fn, v_12746, v_12745);
    env = stack[-4];
    stack[-1] = v_12745;
    v_12745 = stack[-1];
    if (v_12745 == nil) goto v_12710;
    v_12745 = stack[-1];
    goto v_12698;
v_12710:
    v_12745 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 3); // ps!:last!-term
    v_12745 = (*qfn1(fn))(fn, v_12745);
    env = stack[-4];
    v_12745 = add1(v_12745);
    env = stack[-4];
    stack[0] = v_12745;
v_12716:
    goto v_12730;
v_12726:
    v_12746 = stack[-2];
    goto v_12727;
v_12728:
    v_12745 = stack[0];
    goto v_12729;
v_12730:
    goto v_12726;
v_12727:
    goto v_12728;
v_12729:
    v_12745 = difference2(v_12746, v_12745);
    env = stack[-4];
    v_12745 = Lminusp(nil, v_12745);
    env = stack[-4];
    if (v_12745 == nil) goto v_12723;
    goto v_12715;
v_12723:
    goto v_12739;
v_12735:
    v_12746 = qvalue(elt(env, 1)); // ps
    goto v_12736;
v_12737:
    v_12745 = stack[0];
    goto v_12738;
v_12739:
    goto v_12735;
v_12736:
    goto v_12737;
v_12738:
    fn = elt(env, 4); // ps!:evaluate!-next
    v_12745 = (*qfn2(fn))(fn, v_12746, v_12745);
    env = stack[-4];
    stack[-1] = v_12745;
    v_12745 = stack[0];
    v_12745 = add1(v_12745);
    env = stack[-4];
    stack[0] = v_12745;
    goto v_12716;
v_12715:
    v_12745 = stack[-1];
v_12698:
    ;}  // end of a binding scope
    return onevalue(v_12745);
}



// Code for reform!-minus

static LispObject CC_reformKminus(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12800, v_12801, v_12802;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12689;
    stack[-1] = v_12688;
// end of prologue
    v_12800 = stack[0];
    if (v_12800 == nil) goto v_12697;
    else goto v_12698;
v_12697:
    v_12800 = lisp_true;
    goto v_12696;
v_12698:
    v_12800 = stack[-1];
    v_12800 = (v_12800 == nil ? lisp_true : nil);
    goto v_12696;
    v_12800 = nil;
v_12696:
    if (v_12800 == nil) goto v_12694;
    v_12800 = stack[-1];
    goto v_12692;
v_12694:
    v_12800 = stack[-1];
    v_12800 = qcar(v_12800);
    goto v_12716;
v_12712:
    goto v_12730;
v_12726:
    v_12801 = stack[0];
    v_12802 = qcar(v_12801);
    goto v_12727;
v_12728:
    v_12801 = elt(env, 1); // minus
    goto v_12729;
v_12730:
    goto v_12726;
v_12727:
    goto v_12728;
v_12729:
    if (!consp(v_12802)) goto v_12724;
    v_12802 = qcar(v_12802);
    if (v_12802 == v_12801) goto v_12723;
    else goto v_12724;
v_12723:
    goto v_12743;
v_12739:
    v_12802 = v_12800;
    goto v_12740;
v_12741:
    v_12801 = elt(env, 2); // quotient
    goto v_12742;
v_12743:
    goto v_12739;
v_12740:
    goto v_12741;
v_12742:
    if (!consp(v_12802)) goto v_12737;
    v_12802 = qcar(v_12802);
    if (v_12802 == v_12801) goto v_12736;
    else goto v_12737;
v_12736:
    goto v_12751;
v_12747:
    v_12801 = v_12800;
    v_12801 = qcdr(v_12801);
    v_12802 = qcar(v_12801);
    goto v_12748;
v_12749:
    v_12801 = elt(env, 1); // minus
    goto v_12750;
v_12751:
    goto v_12747;
v_12748:
    goto v_12749;
v_12750:
    v_12801 = Leqcar(nil, v_12802, v_12801);
    env = stack[-3];
    goto v_12735;
v_12737:
    v_12801 = nil;
    goto v_12735;
    v_12801 = nil;
v_12735:
    goto v_12722;
v_12724:
    v_12801 = nil;
    goto v_12722;
    v_12801 = nil;
v_12722:
    if (v_12801 == nil) goto v_12720;
    goto v_12767;
v_12763:
    stack[-2] = elt(env, 1); // minus
    goto v_12764;
v_12765:
    goto v_12776;
v_12770:
    v_12802 = elt(env, 2); // quotient
    goto v_12771;
v_12772:
    v_12801 = v_12800;
    v_12801 = qcdr(v_12801);
    v_12801 = qcar(v_12801);
    v_12801 = qcdr(v_12801);
    v_12801 = qcar(v_12801);
    goto v_12773;
v_12774:
    v_12800 = qcdr(v_12800);
    v_12800 = qcdr(v_12800);
    v_12800 = qcar(v_12800);
    goto v_12775;
v_12776:
    goto v_12770;
v_12771:
    goto v_12772;
v_12773:
    goto v_12774;
v_12775:
    v_12800 = list3(v_12802, v_12801, v_12800);
    env = stack[-3];
    goto v_12766;
v_12767:
    goto v_12763;
v_12764:
    goto v_12765;
v_12766:
    v_12800 = list2(stack[-2], v_12800);
    env = stack[-3];
    stack[-2] = v_12800;
    goto v_12718;
v_12720:
    stack[-2] = v_12800;
    goto v_12718;
    stack[-2] = nil;
v_12718:
    goto v_12713;
v_12714:
    goto v_12795;
v_12791:
    v_12800 = stack[-1];
    v_12801 = qcdr(v_12800);
    goto v_12792;
v_12793:
    v_12800 = stack[0];
    v_12800 = qcdr(v_12800);
    goto v_12794;
v_12795:
    goto v_12791;
v_12792:
    goto v_12793;
v_12794:
    v_12800 = CC_reformKminus(elt(env, 0), v_12801, v_12800);
    goto v_12715;
v_12716:
    goto v_12712;
v_12713:
    goto v_12714;
v_12715:
    {
        LispObject v_12806 = stack[-2];
        return cons(v_12806, v_12800);
    }
    v_12800 = nil;
v_12692:
    return onevalue(v_12800);
}



// Code for setmat

static LispObject CC_setmat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12747, v_12748, v_12749;
    LispObject fn;
    LispObject v_12691, v_12690, v_12689, v_12688;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "setmat");
    va_start(aa, nargs);
    v_12688 = va_arg(aa, LispObject);
    v_12689 = va_arg(aa, LispObject);
    v_12690 = va_arg(aa, LispObject);
    v_12691 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_12691,v_12690,v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_12688,v_12689,v_12690,v_12691);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_12691;
    stack[-1] = v_12690;
    stack[-2] = v_12689;
    stack[-3] = v_12688;
// end of prologue
    v_12747 = qvalue(elt(env, 1)); // !*modular
    if (v_12747 == nil) goto v_12696;
    v_12747 = elt(env, 2); // modular
    v_12747 = ncons(v_12747);
    env = stack[-4];
    fn = elt(env, 5); // off
    v_12747 = (*qfn1(fn))(fn, v_12747);
    env = stack[-4];
    v_12747 = elt(env, 3); // mod_was_on
    v_12747 = ncons(v_12747);
    env = stack[-4];
    fn = elt(env, 6); // on
    v_12747 = (*qfn1(fn))(fn, v_12747);
    env = stack[-4];
    goto v_12694;
v_12696:
v_12694:
    v_12747 = stack[-2];
    fn = elt(env, 7); // reval
    v_12747 = (*qfn1(fn))(fn, v_12747);
    env = stack[-4];
    stack[-2] = v_12747;
    v_12747 = stack[-1];
    fn = elt(env, 7); // reval
    v_12747 = (*qfn1(fn))(fn, v_12747);
    env = stack[-4];
    stack[-1] = v_12747;
    v_12747 = stack[0];
    fn = elt(env, 7); // reval
    v_12747 = (*qfn1(fn))(fn, v_12747);
    env = stack[-4];
    fn = elt(env, 8); // simp
    v_12747 = (*qfn1(fn))(fn, v_12747);
    env = stack[-4];
    fn = elt(env, 9); // mk!*sq
    v_12747 = (*qfn1(fn))(fn, v_12747);
    env = stack[-4];
    stack[0] = v_12747;
    goto v_12720;
v_12714:
    goto v_12728;
v_12722:
    v_12749 = stack[-3];
    goto v_12723;
v_12724:
    v_12748 = stack[-2];
    goto v_12725;
v_12726:
    v_12747 = stack[-1];
    goto v_12727;
v_12728:
    goto v_12722;
v_12723:
    goto v_12724;
v_12725:
    goto v_12726;
v_12727:
    v_12749 = list3(v_12749, v_12748, v_12747);
    env = stack[-4];
    goto v_12715;
v_12716:
    v_12748 = stack[0];
    goto v_12717;
v_12718:
    v_12747 = stack[-3];
    goto v_12719;
v_12720:
    goto v_12714;
v_12715:
    goto v_12716;
v_12717:
    goto v_12718;
v_12719:
    fn = elt(env, 10); // letmtr
    v_12747 = (*qfnn(fn))(fn, 3, v_12749, v_12748, v_12747);
    env = stack[-4];
    v_12747 = qvalue(elt(env, 4)); // !*mod_was_on
    if (v_12747 == nil) goto v_12737;
    v_12747 = elt(env, 2); // modular
    v_12747 = ncons(v_12747);
    env = stack[-4];
    fn = elt(env, 6); // on
    v_12747 = (*qfn1(fn))(fn, v_12747);
    env = stack[-4];
    v_12747 = elt(env, 3); // mod_was_on
    v_12747 = ncons(v_12747);
    env = stack[-4];
    fn = elt(env, 5); // off
    v_12747 = (*qfn1(fn))(fn, v_12747);
    goto v_12735;
v_12737:
v_12735:
    v_12747 = stack[-3];
    return onevalue(v_12747);
}



// Code for freeoffl

static LispObject CC_freeoffl(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12724, v_12725;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12689;
    stack[-1] = v_12688;
// end of prologue
v_12687:
    v_12724 = stack[0];
    if (v_12724 == nil) goto v_12693;
    else goto v_12694;
v_12693:
    v_12724 = lisp_true;
    goto v_12692;
v_12694:
    goto v_12708;
v_12704:
    v_12725 = stack[-1];
    goto v_12705;
v_12706:
    v_12724 = stack[0];
    v_12724 = qcar(v_12724);
    goto v_12707;
v_12708:
    goto v_12704;
v_12705:
    goto v_12706;
v_12707:
    fn = elt(env, 1); // freeoff
    v_12724 = (*qfn2(fn))(fn, v_12725, v_12724);
    env = stack[-2];
    if (v_12724 == nil) goto v_12701;
    else goto v_12702;
v_12701:
    v_12724 = nil;
    goto v_12700;
v_12702:
    goto v_12720;
v_12716:
    v_12725 = stack[-1];
    goto v_12717;
v_12718:
    v_12724 = stack[0];
    v_12724 = qcdr(v_12724);
    goto v_12719;
v_12720:
    goto v_12716;
v_12717:
    goto v_12718;
v_12719:
    stack[-1] = v_12725;
    stack[0] = v_12724;
    goto v_12687;
    v_12724 = nil;
v_12700:
    goto v_12692;
    v_12724 = nil;
v_12692:
    return onevalue(v_12724);
}



// Code for fortexp

static LispObject CC_fortexp(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12698, v_12699;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12698 = v_12688;
// end of prologue
    goto v_12695;
v_12691:
    v_12699 = v_12698;
    goto v_12692;
v_12693:
    v_12698 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12694;
v_12695:
    goto v_12691;
v_12692:
    goto v_12693;
v_12694:
    {
        fn = elt(env, 1); // fortexp1
        return (*qfn2(fn))(fn, v_12699, v_12698);
    }
}



// Code for indordp

static LispObject CC_indordp(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12748, v_12749, v_12750, v_12751, v_12752;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12750 = v_12689;
    v_12751 = v_12688;
// end of prologue
    v_12748 = qvalue(elt(env, 1)); // indxl!*
    v_12752 = v_12748;
    goto v_12704;
v_12700:
    v_12749 = v_12751;
    goto v_12701;
v_12702:
    v_12748 = v_12752;
    goto v_12703;
v_12704:
    goto v_12700;
v_12701:
    goto v_12702;
v_12703:
    v_12748 = Lmemq(nil, v_12749, v_12748);
    if (v_12748 == nil) goto v_12698;
    else goto v_12699;
v_12698:
    v_12748 = lisp_true;
    goto v_12693;
v_12699:
v_12694:
    v_12748 = v_12752;
    if (v_12748 == nil) goto v_12711;
    else goto v_12712;
v_12711:
    goto v_12719;
v_12715:
    v_12748 = v_12751;
    goto v_12716;
v_12717:
    v_12749 = v_12750;
    goto v_12718;
v_12719:
    goto v_12715;
v_12716:
    goto v_12717;
v_12718:
        return Lorderp(nil, v_12748, v_12749);
v_12712:
    goto v_12730;
v_12726:
    v_12749 = v_12751;
    goto v_12727;
v_12728:
    v_12748 = v_12752;
    v_12748 = qcar(v_12748);
    goto v_12729;
v_12730:
    goto v_12726;
v_12727:
    goto v_12728;
v_12729:
    if (v_12749 == v_12748) goto v_12724;
    else goto v_12725;
v_12724:
    v_12748 = lisp_true;
    goto v_12693;
v_12725:
    goto v_12741;
v_12737:
    v_12749 = v_12750;
    goto v_12738;
v_12739:
    v_12748 = v_12752;
    v_12748 = qcar(v_12748);
    goto v_12740;
v_12741:
    goto v_12737;
v_12738:
    goto v_12739;
v_12740:
    if (v_12749 == v_12748) goto v_12735;
    else goto v_12736;
v_12735:
    v_12748 = nil;
    goto v_12693;
v_12736:
    v_12748 = v_12752;
    v_12748 = qcdr(v_12748);
    v_12752 = v_12748;
    goto v_12694;
v_12693:
    return onevalue(v_12748);
}



// Code for lpriw

static LispObject CC_lpriw(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12752, v_12753;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_12753 = v_12689;
    stack[0] = v_12688;
// end of prologue
    goto v_12698;
v_12694:
    goto v_12695;
v_12696:
    v_12752 = v_12753;
    if (v_12752 == nil) goto v_12703;
    v_12752 = v_12753;
    if (!consp(v_12752)) goto v_12706;
    else goto v_12703;
v_12706:
    v_12752 = v_12753;
    v_12752 = ncons(v_12752);
    env = stack[-1];
    goto v_12701;
v_12703:
    v_12752 = v_12753;
    goto v_12701;
    v_12752 = nil;
v_12701:
    goto v_12697;
v_12698:
    goto v_12694;
v_12695:
    goto v_12696;
v_12697:
    v_12752 = cons(stack[0], v_12752);
    env = stack[-1];
    stack[0] = v_12752;
    v_12752 = qvalue(elt(env, 1)); // ofl!*
    if (v_12752 == nil) goto v_12715;
    else goto v_12716;
v_12715:
    v_12752 = Lterpri(nil, 0);
    env = stack[-1];
    v_12752 = stack[0];
    fn = elt(env, 5); // lpri
    v_12752 = (*qfn1(fn))(fn, v_12752);
    env = stack[-1];
    v_12752 = Lterpri(nil, 0);
    goto v_12714;
v_12716:
    v_12752 = qvalue(elt(env, 2)); // !*fort
    if (v_12752 == nil) goto v_12728;
    else goto v_12727;
v_12728:
    v_12752 = qvalue(elt(env, 3)); // !*nat
    if (v_12752 == nil) goto v_12733;
    else goto v_12734;
v_12733:
    v_12752 = lisp_true;
    goto v_12732;
v_12734:
    v_12752 = qvalue(elt(env, 4)); // !*defn
    goto v_12732;
    v_12752 = nil;
v_12732:
    if (v_12752 == nil) goto v_12730;
    else goto v_12727;
v_12730:
    v_12752 = Lterpri(nil, 0);
    env = stack[-1];
    v_12752 = stack[0];
    fn = elt(env, 5); // lpri
    v_12752 = (*qfn1(fn))(fn, v_12752);
    env = stack[-1];
    v_12752 = Lterpri(nil, 0);
    env = stack[-1];
    goto v_12725;
v_12727:
v_12725:
    v_12752 = nil;
    v_12752 = Lwrs(nil, v_12752);
    env = stack[-1];
    v_12752 = stack[0];
    fn = elt(env, 5); // lpri
    v_12752 = (*qfn1(fn))(fn, v_12752);
    env = stack[-1];
    v_12752 = Lterpri(nil, 0);
    env = stack[-1];
    v_12752 = qvalue(elt(env, 1)); // ofl!*
    v_12752 = qcdr(v_12752);
    v_12752 = Lwrs(nil, v_12752);
    goto v_12714;
v_12714:
    v_12752 = nil;
    return onevalue(v_12752);
}



// Code for mv!-domainlist!-!+

static LispObject CC_mvKdomainlistKL(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12725, v_12726;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12689;
    stack[-1] = v_12688;
// end of prologue
    stack[-2] = nil;
v_12694:
    v_12725 = stack[-1];
    if (v_12725 == nil) goto v_12697;
    else goto v_12698;
v_12697:
    v_12725 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12725);
    }
v_12698:
    goto v_12709;
v_12705:
    goto v_12715;
v_12711:
    v_12725 = stack[-1];
    v_12726 = qcar(v_12725);
    goto v_12712;
v_12713:
    v_12725 = stack[0];
    v_12725 = qcar(v_12725);
    goto v_12714;
v_12715:
    goto v_12711;
v_12712:
    goto v_12713;
v_12714:
    v_12726 = plus2(v_12726, v_12725);
    env = stack[-3];
    goto v_12706;
v_12707:
    v_12725 = stack[-2];
    goto v_12708;
v_12709:
    goto v_12705;
v_12706:
    goto v_12707;
v_12708:
    v_12725 = cons(v_12726, v_12725);
    env = stack[-3];
    stack[-2] = v_12725;
    v_12725 = stack[-1];
    v_12725 = qcdr(v_12725);
    stack[-1] = v_12725;
    v_12725 = stack[0];
    v_12725 = qcdr(v_12725);
    stack[0] = v_12725;
    goto v_12694;
    v_12725 = nil;
    return onevalue(v_12725);
}



// Code for mo_lcm

static LispObject CC_mo_lcm(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12769, v_12770;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_12770 = v_12689;
    v_12769 = v_12688;
// end of prologue
    stack[-2] = nil;
    v_12769 = qcar(v_12769);
    stack[-1] = v_12769;
    v_12769 = v_12770;
    v_12769 = qcar(v_12769);
    stack[0] = v_12769;
v_12702:
    v_12769 = stack[-1];
    if (v_12769 == nil) goto v_12705;
    v_12769 = stack[0];
    if (v_12769 == nil) goto v_12705;
    goto v_12706;
v_12705:
    goto v_12701;
v_12706:
    goto v_12717;
v_12713:
    goto v_12726;
v_12722:
    v_12769 = stack[-1];
    v_12770 = qcar(v_12769);
    goto v_12723;
v_12724:
    v_12769 = stack[0];
    v_12769 = qcar(v_12769);
    goto v_12725;
v_12726:
    goto v_12722;
v_12723:
    goto v_12724;
v_12725:
    if (((intptr_t)(v_12770)) > ((intptr_t)(v_12769))) goto v_12720;
    else goto v_12721;
v_12720:
    v_12769 = stack[-1];
    v_12769 = qcar(v_12769);
    v_12770 = v_12769;
    goto v_12719;
v_12721:
    v_12769 = stack[0];
    v_12769 = qcar(v_12769);
    v_12770 = v_12769;
    goto v_12719;
    v_12770 = nil;
v_12719:
    goto v_12714;
v_12715:
    v_12769 = stack[-2];
    goto v_12716;
v_12717:
    goto v_12713;
v_12714:
    goto v_12715;
v_12716:
    v_12769 = cons(v_12770, v_12769);
    env = stack[-3];
    stack[-2] = v_12769;
    v_12769 = stack[-1];
    v_12769 = qcdr(v_12769);
    stack[-1] = v_12769;
    v_12769 = stack[0];
    v_12769 = qcdr(v_12769);
    stack[0] = v_12769;
    goto v_12702;
v_12701:
    goto v_12747;
v_12743:
    v_12769 = stack[-2];
    v_12770 = Lnreverse(nil, v_12769);
    env = stack[-3];
    goto v_12744;
v_12745:
    v_12769 = stack[-1];
    if (v_12769 == nil) goto v_12753;
    v_12769 = stack[-1];
    goto v_12751;
v_12753:
    v_12769 = stack[0];
    goto v_12751;
    v_12769 = nil;
v_12751:
    goto v_12746;
v_12747:
    goto v_12743;
v_12744:
    goto v_12745;
v_12746:
    v_12769 = Lappend(nil, v_12770, v_12769);
    env = stack[-3];
    stack[-2] = v_12769;
    goto v_12764;
v_12760:
    v_12769 = stack[-2];
    fn = elt(env, 1); // mo!=shorten
    stack[0] = (*qfn1(fn))(fn, v_12769);
    env = stack[-3];
    goto v_12761;
v_12762:
    v_12769 = stack[-2];
    fn = elt(env, 2); // mo!=deglist
    v_12769 = (*qfn1(fn))(fn, v_12769);
    goto v_12763;
v_12764:
    goto v_12760;
v_12761:
    goto v_12762;
v_12763:
    {
        LispObject v_12774 = stack[0];
        return cons(v_12774, v_12769);
    }
    return onevalue(v_12769);
}



// Code for arglist_member

static LispObject CC_arglist_member(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12720, v_12721;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12689;
    stack[-1] = v_12688;
// end of prologue
v_12687:
    v_12720 = stack[0];
    if (!consp(v_12720)) goto v_12694;
    goto v_12704;
v_12700:
    v_12721 = stack[-1];
    goto v_12701;
v_12702:
    v_12720 = stack[0];
    v_12720 = qcar(v_12720);
    goto v_12703;
v_12704:
    goto v_12700;
v_12701:
    goto v_12702;
v_12703:
    fn = elt(env, 1); // mvar_member
    v_12720 = (*qfn2(fn))(fn, v_12721, v_12720);
    env = stack[-2];
    if (v_12720 == nil) goto v_12698;
    else goto v_12697;
v_12698:
    goto v_12713;
v_12709:
    v_12721 = stack[-1];
    goto v_12710;
v_12711:
    v_12720 = stack[0];
    v_12720 = qcdr(v_12720);
    goto v_12712;
v_12713:
    goto v_12709;
v_12710:
    goto v_12711;
v_12712:
    stack[-1] = v_12721;
    stack[0] = v_12720;
    goto v_12687;
v_12697:
    goto v_12692;
v_12694:
    v_12720 = nil;
    goto v_12692;
    v_12720 = nil;
v_12692:
    return onevalue(v_12720);
}



// Code for drop_rl_with

static LispObject CC_drop_rl_with(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12716, v_12717, v_12718;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_12716 = v_12689;
    v_12717 = v_12688;
// end of prologue
    goto v_12698;
v_12692:
    stack[-1] = v_12716;
    goto v_12693;
v_12694:
    stack[0] = elt(env, 1); // rl_with
    goto v_12695;
v_12696:
    goto v_12706;
v_12702:
    v_12718 = v_12717;
    goto v_12703;
v_12704:
    goto v_12713;
v_12709:
    v_12717 = v_12716;
    goto v_12710;
v_12711:
    v_12716 = elt(env, 1); // rl_with
    goto v_12712;
v_12713:
    goto v_12709;
v_12710:
    goto v_12711;
v_12712:
    v_12716 = get(v_12717, v_12716);
    env = stack[-2];
    goto v_12705;
v_12706:
    goto v_12702;
v_12703:
    goto v_12704;
v_12705:
    v_12716 = Ldelete(nil, v_12718, v_12716);
    goto v_12697;
v_12698:
    goto v_12692;
v_12693:
    goto v_12694;
v_12695:
    goto v_12696;
v_12697:
    {
        LispObject v_12721 = stack[-1];
        LispObject v_12722 = stack[0];
        return Lputprop(nil, 3, v_12721, v_12722, v_12716);
    }
}



// Code for remlocs

static LispObject CC_remlocs(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12786, v_12787;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_12787 = v_12688;
// end of prologue
    v_12786 = qvalue(elt(env, 1)); // !*globals
    if (v_12786 == nil) goto v_12696;
    v_12786 = v_12787;
    stack[-2] = v_12786;
v_12701:
    v_12786 = stack[-2];
    if (v_12786 == nil) goto v_12705;
    else goto v_12706;
v_12705:
    goto v_12700;
v_12706:
    v_12786 = stack[-2];
    v_12786 = qcar(v_12786);
    stack[-1] = v_12786;
    goto v_12716;
v_12712:
    v_12787 = stack[-1];
    goto v_12713;
v_12714:
    v_12786 = qvalue(elt(env, 2)); // locls!*
    goto v_12715;
v_12716:
    goto v_12712;
v_12713:
    goto v_12714;
v_12715:
    v_12786 = Lassoc(nil, v_12787, v_12786);
    stack[-3] = v_12786;
    v_12786 = stack[-3];
    if (v_12786 == nil) goto v_12722;
    else goto v_12723;
v_12722:
    v_12786 = elt(env, 3); // begin
    fn = elt(env, 5); // getd
    v_12786 = (*qfn1(fn))(fn, v_12786);
    env = stack[-4];
    if (v_12786 == nil) goto v_12728;
    goto v_12737;
v_12733:
    v_12787 = elt(env, 4); // " Lvar confused"
    goto v_12734;
v_12735:
    v_12786 = stack[-1];
    goto v_12736;
v_12737:
    goto v_12733;
v_12734:
    goto v_12735;
v_12736:
    v_12786 = list2(v_12787, v_12786);
    env = stack[-4];
    fn = elt(env, 6); // rederr
    v_12786 = (*qfn1(fn))(fn, v_12786);
    env = stack[-4];
    goto v_12726;
v_12728:
    goto v_12747;
v_12743:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12744;
v_12745:
    goto v_12754;
v_12750:
    v_12787 = elt(env, 4); // " Lvar confused"
    goto v_12751;
v_12752:
    v_12786 = stack[-1];
    goto v_12753;
v_12754:
    goto v_12750;
v_12751:
    goto v_12752;
v_12753:
    v_12786 = list2(v_12787, v_12786);
    env = stack[-4];
    goto v_12746;
v_12747:
    goto v_12743;
v_12744:
    goto v_12745;
v_12746:
    fn = elt(env, 7); // error
    v_12786 = (*qfn2(fn))(fn, stack[0], v_12786);
    env = stack[-4];
    goto v_12726;
v_12726:
    goto v_12721;
v_12723:
v_12721:
    v_12786 = stack[-3];
    v_12786 = qcdr(v_12786);
    v_12786 = qcdr(v_12786);
    if (v_12786 == nil) goto v_12760;
    goto v_12769;
v_12765:
    v_12787 = stack[-3];
    goto v_12766;
v_12767:
    v_12786 = stack[-3];
    v_12786 = qcdr(v_12786);
    v_12786 = qcdr(v_12786);
    goto v_12768;
v_12769:
    goto v_12765;
v_12766:
    goto v_12767;
v_12768:
    v_12786 = Lrplacd(nil, v_12787, v_12786);
    env = stack[-4];
    goto v_12758;
v_12760:
    goto v_12781;
v_12777:
    v_12787 = stack[-3];
    goto v_12778;
v_12779:
    v_12786 = qvalue(elt(env, 2)); // locls!*
    goto v_12780;
v_12781:
    goto v_12777;
v_12778:
    goto v_12779;
v_12780:
    fn = elt(env, 8); // efface1
    v_12786 = (*qfn2(fn))(fn, v_12787, v_12786);
    env = stack[-4];
    qvalue(elt(env, 2)) = v_12786; // locls!*
    goto v_12758;
v_12758:
    v_12786 = stack[-2];
    v_12786 = qcdr(v_12786);
    stack[-2] = v_12786;
    goto v_12701;
v_12700:
    goto v_12694;
v_12696:
v_12694:
    v_12786 = nil;
    return onevalue(v_12786);
}



// Code for setqget

static LispObject CC_setqget(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12716, v_12717;
    argcheck(nargs, 0, "setqget");
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
    v_12716 = qvalue(elt(env, 1)); // fluidbibasissetq
    v_12716 = qcar(v_12716);
    stack[-1] = v_12716;
    v_12716 = qvalue(elt(env, 1)); // fluidbibasissetq
    stack[0] = v_12716;
    goto v_12701;
v_12697:
    goto v_12707;
v_12703:
    v_12717 = stack[0];
    goto v_12704;
v_12705:
    v_12716 = stack[0];
    v_12716 = qcdr(v_12716);
    v_12716 = qcar(v_12716);
    goto v_12706;
v_12707:
    goto v_12703;
v_12704:
    goto v_12705;
v_12706:
    v_12717 = Lrplaca(nil, v_12717, v_12716);
    env = stack[-2];
    goto v_12698;
v_12699:
    v_12716 = stack[0];
    v_12716 = qcdr(v_12716);
    v_12716 = qcdr(v_12716);
    goto v_12700;
v_12701:
    goto v_12697;
v_12698:
    goto v_12699;
v_12700:
    v_12716 = Lrplacd(nil, v_12717, v_12716);
    v_12716 = stack[-1];
    return onevalue(v_12716);
}



// Code for ofsf_surep

static LispObject CC_ofsf_surep(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12709, v_12710, v_12711;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12709 = v_12689;
    v_12710 = v_12688;
// end of prologue
    goto v_12695;
v_12691:
    goto v_12703;
v_12697:
    v_12711 = v_12710;
    goto v_12698;
v_12699:
    v_12710 = v_12709;
    goto v_12700;
v_12701:
    v_12709 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_12702;
v_12703:
    goto v_12697;
v_12698:
    goto v_12699;
v_12700:
    goto v_12701;
v_12702:
    fn = elt(env, 2); // cl_simpl
    v_12709 = (*qfnn(fn))(fn, 3, v_12711, v_12710, v_12709);
    env = stack[0];
    goto v_12692;
v_12693:
    v_12710 = elt(env, 1); // true
    goto v_12694;
v_12695:
    goto v_12691;
v_12692:
    goto v_12693;
v_12694:
    v_12709 = (v_12709 == v_12710 ? lisp_true : nil);
    return onevalue(v_12709);
}



// Code for ibalp_negatet

static LispObject CC_ibalp_negatet(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12722, v_12723, v_12724;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12724 = v_12688;
// end of prologue
    goto v_12698;
v_12694:
    v_12723 = v_12724;
    goto v_12695;
v_12696:
    v_12722 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12697;
v_12698:
    goto v_12694;
v_12695:
    goto v_12696;
v_12697:
    if (v_12723 == v_12722) goto v_12692;
    else goto v_12693;
v_12692:
    v_12722 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12691;
v_12693:
    goto v_12708;
v_12704:
    v_12723 = v_12724;
    goto v_12705;
v_12706:
    v_12722 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12707;
v_12708:
    goto v_12704;
v_12705:
    goto v_12706;
v_12707:
    if (v_12723 == v_12722) goto v_12702;
    else goto v_12703;
v_12702:
    v_12722 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12691;
v_12703:
    goto v_12719;
v_12715:
    v_12722 = elt(env, 1); // bnot
    goto v_12716;
v_12717:
    v_12723 = v_12724;
    goto v_12718;
v_12719:
    goto v_12715;
v_12716:
    goto v_12717;
v_12718:
    return list2(v_12722, v_12723);
    v_12722 = nil;
v_12691:
    return onevalue(v_12722);
}



// Code for sfto_dprpartksf

static LispObject CC_sfto_dprpartksf(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12699;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_12699 = v_12688;
// end of prologue
    goto v_12695;
v_12691:
    stack[0] = v_12699;
    goto v_12692;
v_12693:
    fn = elt(env, 1); // sfto_dcontentf
    v_12699 = (*qfn1(fn))(fn, v_12699);
    env = stack[-1];
    goto v_12694;
v_12695:
    goto v_12691;
v_12692:
    goto v_12693;
v_12694:
    {
        LispObject v_12701 = stack[0];
        fn = elt(env, 2); // quotf
        return (*qfn2(fn))(fn, v_12701, v_12699);
    }
}



// Code for reln

static LispObject CC_reln(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12717, v_12718;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12689;
    stack[-1] = v_12688;
// end of prologue
    v_12717 = elt(env, 1); // "<apply>"
    fn = elt(env, 5); // printout
    v_12717 = (*qfn1(fn))(fn, v_12717);
    env = stack[-2];
    v_12717 = elt(env, 2); // "<"
    v_12717 = Lprinc(nil, v_12717);
    env = stack[-2];
    v_12717 = stack[0];
    v_12717 = Lprinc(nil, v_12717);
    env = stack[-2];
    goto v_12704;
v_12700:
    v_12717 = stack[-1];
    v_12718 = qcar(v_12717);
    goto v_12701;
v_12702:
    v_12717 = elt(env, 3); // "/"
    goto v_12703;
v_12704:
    goto v_12700;
v_12701:
    goto v_12702;
v_12703:
    fn = elt(env, 6); // attributesml
    v_12717 = (*qfn2(fn))(fn, v_12718, v_12717);
    env = stack[-2];
    v_12717 = lisp_true;
    fn = elt(env, 7); // indent!*
    v_12717 = (*qfn1(fn))(fn, v_12717);
    env = stack[-2];
    v_12717 = stack[-1];
    v_12717 = qcdr(v_12717);
    fn = elt(env, 8); // multi_elem
    v_12717 = (*qfn1(fn))(fn, v_12717);
    env = stack[-2];
    v_12717 = nil;
    fn = elt(env, 7); // indent!*
    v_12717 = (*qfn1(fn))(fn, v_12717);
    env = stack[-2];
    v_12717 = elt(env, 4); // "</apply>"
    fn = elt(env, 5); // printout
    v_12717 = (*qfn1(fn))(fn, v_12717);
    v_12717 = nil;
    return onevalue(v_12717);
}



// Code for diffsq

static LispObject CC_diffsq(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12738, v_12739;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_12689;
    stack[-2] = v_12688;
// end of prologue
    goto v_12696;
v_12692:
    goto v_12702;
v_12698:
    goto v_12708;
v_12704:
    v_12738 = stack[-2];
    v_12739 = qcar(v_12738);
    goto v_12705;
v_12706:
    v_12738 = stack[-1];
    goto v_12707;
v_12708:
    goto v_12704;
v_12705:
    goto v_12706;
v_12707:
    fn = elt(env, 1); // difff
    stack[-3] = (*qfn2(fn))(fn, v_12739, v_12738);
    env = stack[-4];
    goto v_12699;
v_12700:
    goto v_12718;
v_12714:
    stack[0] = stack[-2];
    goto v_12715;
v_12716:
    goto v_12725;
v_12721:
    v_12738 = stack[-2];
    v_12739 = qcdr(v_12738);
    goto v_12722;
v_12723:
    v_12738 = stack[-1];
    goto v_12724;
v_12725:
    goto v_12721;
v_12722:
    goto v_12723;
v_12724:
    fn = elt(env, 1); // difff
    v_12738 = (*qfn2(fn))(fn, v_12739, v_12738);
    env = stack[-4];
    goto v_12717;
v_12718:
    goto v_12714;
v_12715:
    goto v_12716;
v_12717:
    fn = elt(env, 2); // multsq
    v_12738 = (*qfn2(fn))(fn, stack[0], v_12738);
    env = stack[-4];
    fn = elt(env, 3); // negsq
    v_12738 = (*qfn1(fn))(fn, v_12738);
    env = stack[-4];
    goto v_12701;
v_12702:
    goto v_12698;
v_12699:
    goto v_12700;
v_12701:
    fn = elt(env, 4); // addsq
    stack[0] = (*qfn2(fn))(fn, stack[-3], v_12738);
    env = stack[-4];
    goto v_12693;
v_12694:
    goto v_12734;
v_12730:
    v_12739 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12731;
v_12732:
    v_12738 = stack[-2];
    v_12738 = qcdr(v_12738);
    goto v_12733;
v_12734:
    goto v_12730;
v_12731:
    goto v_12732;
v_12733:
    v_12738 = cons(v_12739, v_12738);
    env = stack[-4];
    goto v_12695;
v_12696:
    goto v_12692;
v_12693:
    goto v_12694;
v_12695:
    {
        LispObject v_12744 = stack[0];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_12744, v_12738);
    }
}



// Code for xdegreecheck

static LispObject CC_xdegreecheck(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12707, v_12708;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12708 = v_12688;
// end of prologue
    v_12707 = qvalue(elt(env, 1)); // xtruncate!*
    if (v_12707 == nil) goto v_12692;
    else goto v_12693;
v_12692:
    v_12707 = nil;
    goto v_12691;
v_12693:
    goto v_12703;
v_12699:
    v_12707 = v_12708;
    fn = elt(env, 2); // xdegree
    v_12707 = (*qfn1(fn))(fn, v_12707);
    env = stack[0];
    goto v_12700;
v_12701:
    v_12708 = qvalue(elt(env, 1)); // xtruncate!*
    goto v_12702;
v_12703:
    goto v_12699;
v_12700:
    goto v_12701;
v_12702:
        return Lgreaterp(nil, v_12707, v_12708);
    v_12707 = nil;
v_12691:
    return onevalue(v_12707);
}



// Code for physopsm!*

static LispObject CC_physopsmH(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12955, v_12956, v_12957, v_12958;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_12688;
// end of prologue
    stack[0] = nil;
    v_12955 = stack[-3];
    if (v_12955 == nil) goto v_12703;
    else goto v_12704;
v_12703:
    v_12955 = lisp_true;
    goto v_12702;
v_12704:
    v_12955 = stack[-3];
    v_12955 = (is_number(v_12955) ? lisp_true : nil);
    goto v_12702;
    v_12955 = nil;
v_12702:
    if (v_12955 == nil) goto v_12700;
    v_12955 = stack[-3];
    stack[0] = v_12955;
    goto v_12698;
v_12700:
    v_12955 = stack[-3];
    fn = elt(env, 11); // physopp
    v_12955 = (*qfn1(fn))(fn, v_12955);
    env = stack[-5];
    if (v_12955 == nil) goto v_12713;
    v_12955 = stack[-3];
    if (!symbolp(v_12955)) v_12955 = nil;
    else { v_12955 = qfastgets(v_12955);
           if (v_12955 != nil) { v_12955 = elt(v_12955, 46); // rvalue
#ifdef RECORD_GET
             if (v_12955 != SPID_NOPROP)
                record_get(elt(fastget_names, 46), 1);
             else record_get(elt(fastget_names, 46), 0),
                v_12955 = nil; }
           else record_get(elt(fastget_names, 46), 0); }
#else
             if (v_12955 == SPID_NOPROP) v_12955 = nil; }}
#endif
    stack[-1] = v_12955;
    if (v_12955 == nil) goto v_12719;
    v_12955 = stack[-1];
    fn = elt(env, 12); // physopaeval
    v_12955 = (*qfn1(fn))(fn, v_12955);
    goto v_12717;
v_12719:
    v_12955 = stack[-3];
    if (symbolp(v_12955)) goto v_12724;
    else goto v_12725;
v_12724:
    v_12955 = stack[-3];
    goto v_12717;
v_12725:
    goto v_12735;
v_12731:
    v_12955 = stack[-3];
    v_12956 = qcar(v_12955);
    goto v_12732;
v_12733:
    v_12955 = elt(env, 1); // psimpfn
    goto v_12734;
v_12735:
    goto v_12731;
v_12732:
    goto v_12733;
v_12734:
    v_12955 = get(v_12956, v_12955);
    env = stack[-5];
    stack[-1] = v_12955;
    if (v_12955 == nil) goto v_12729;
    goto v_12744;
v_12740:
    v_12956 = stack[-1];
    goto v_12741;
v_12742:
    v_12955 = stack[-3];
    goto v_12743;
v_12744:
    goto v_12740;
v_12741:
    goto v_12742;
v_12743:
    v_12955 = Lapply1(nil, v_12956, v_12955);
    goto v_12717;
v_12729:
    v_12955 = stack[-3];
    v_12955 = qcar(v_12955);
    if (!symbolp(v_12955)) v_12955 = nil;
    else { v_12955 = qfastgets(v_12955);
           if (v_12955 != nil) { v_12955 = elt(v_12955, 9); // opmtch
#ifdef RECORD_GET
             if (v_12955 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_12955 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_12955 == SPID_NOPROP) v_12955 = nil; }}
#endif
    if (v_12955 == nil) goto v_12748;
    v_12955 = stack[-3];
    fn = elt(env, 13); // opmtch!*
    v_12955 = (*qfn1(fn))(fn, v_12955);
    stack[-1] = v_12955;
    if (v_12955 == nil) goto v_12748;
    v_12955 = stack[-1];
    goto v_12717;
v_12748:
    v_12955 = stack[-3];
    goto v_12717;
    v_12955 = nil;
v_12717:
    stack[0] = v_12955;
    goto v_12698;
v_12713:
    v_12955 = stack[-3];
    if (!consp(v_12955)) goto v_12760;
    else goto v_12761;
v_12760:
    v_12955 = stack[-3];
    fn = elt(env, 14); // aeval
    v_12955 = (*qfn1(fn))(fn, v_12955);
    stack[0] = v_12955;
    goto v_12698;
v_12761:
    v_12955 = stack[-3];
    v_12955 = qcar(v_12955);
    stack[-4] = v_12955;
    v_12955 = stack[-3];
    v_12955 = qcdr(v_12955);
    stack[-2] = v_12955;
    goto v_12780;
v_12776:
    v_12956 = stack[-4];
    goto v_12777;
v_12778:
    v_12955 = elt(env, 2); // physopfunction
    goto v_12779;
v_12780:
    goto v_12776;
v_12777:
    goto v_12778;
v_12779:
    v_12955 = get(v_12956, v_12955);
    env = stack[-5];
    stack[-1] = v_12955;
    if (v_12955 == nil) goto v_12774;
    goto v_12792;
v_12788:
    v_12956 = stack[-4];
    goto v_12789;
v_12790:
    v_12955 = elt(env, 3); // physoparith
    goto v_12791;
v_12792:
    goto v_12788;
v_12789:
    goto v_12790;
v_12791:
    v_12955 = Lflagp(nil, v_12956, v_12955);
    env = stack[-5];
    if (v_12955 == nil) goto v_12786;
    v_12955 = stack[-2];
    fn = elt(env, 15); // hasonephysop
    v_12955 = (*qfn1(fn))(fn, v_12955);
    env = stack[-5];
    if (v_12955 == nil) goto v_12798;
    goto v_12806;
v_12802:
    stack[0] = stack[-1];
    goto v_12803;
v_12804:
    v_12955 = stack[-2];
    v_12955 = ncons(v_12955);
    env = stack[-5];
    goto v_12805;
v_12806:
    goto v_12802;
v_12803:
    goto v_12804;
v_12805:
    fn = elt(env, 16); // apply
    v_12955 = (*qfn2(fn))(fn, stack[0], v_12955);
    stack[0] = v_12955;
    goto v_12796;
v_12798:
    goto v_12818;
v_12814:
    v_12956 = stack[-4];
    goto v_12815;
v_12816:
    v_12955 = stack[-2];
    goto v_12817;
v_12818:
    goto v_12814;
v_12815:
    goto v_12816;
v_12817:
    v_12955 = cons(v_12956, v_12955);
    env = stack[-5];
    fn = elt(env, 17); // reval3
    v_12955 = (*qfn1(fn))(fn, v_12955);
    stack[0] = v_12955;
    goto v_12796;
v_12796:
    goto v_12784;
v_12786:
    goto v_12828;
v_12824:
    v_12956 = stack[-4];
    goto v_12825;
v_12826:
    v_12955 = elt(env, 4); // physopfn
    goto v_12827;
v_12828:
    goto v_12824;
v_12825:
    goto v_12826;
v_12827:
    v_12955 = Lflagp(nil, v_12956, v_12955);
    env = stack[-5];
    if (v_12955 == nil) goto v_12822;
    v_12955 = stack[-2];
    fn = elt(env, 18); // areallphysops
    v_12955 = (*qfn1(fn))(fn, v_12955);
    env = stack[-5];
    if (v_12955 == nil) goto v_12834;
    goto v_12842;
v_12838:
    stack[0] = stack[-1];
    goto v_12839;
v_12840:
    v_12955 = stack[-2];
    v_12955 = ncons(v_12955);
    env = stack[-5];
    goto v_12841;
v_12842:
    goto v_12838;
v_12839:
    goto v_12840;
v_12841:
    fn = elt(env, 16); // apply
    v_12955 = (*qfn2(fn))(fn, stack[0], v_12955);
    stack[0] = v_12955;
    goto v_12832;
v_12834:
    goto v_12853;
v_12849:
    stack[-1] = elt(env, 0); // physopsm!*
    goto v_12850;
v_12851:
    goto v_12864;
v_12856:
    v_12958 = elt(env, 5); // "invalid call of "
    goto v_12857;
v_12858:
    v_12957 = stack[-4];
    goto v_12859;
v_12860:
    v_12956 = elt(env, 6); // " with args: "
    goto v_12861;
v_12862:
    v_12955 = stack[-2];
    goto v_12863;
v_12864:
    goto v_12856;
v_12857:
    goto v_12858;
v_12859:
    goto v_12860;
v_12861:
    goto v_12862;
v_12863:
    v_12955 = list4(v_12958, v_12957, v_12956, v_12955);
    env = stack[-5];
    goto v_12852;
v_12853:
    goto v_12849;
v_12850:
    goto v_12851;
v_12852:
    fn = elt(env, 19); // rederr2
    v_12955 = (*qfn2(fn))(fn, stack[-1], v_12955);
    goto v_12832;
v_12832:
    goto v_12784;
v_12822:
    goto v_12876;
v_12872:
    stack[-1] = elt(env, 0); // physopsm!*
    goto v_12873;
v_12874:
    goto v_12885;
v_12879:
    v_12957 = stack[-4];
    goto v_12880;
v_12881:
    v_12956 = elt(env, 7); // " has been flagged Physopfunction"
    goto v_12882;
v_12883:
    v_12955 = elt(env, 8); // " but is not defined"
    goto v_12884;
v_12885:
    goto v_12879;
v_12880:
    goto v_12881;
v_12882:
    goto v_12883;
v_12884:
    v_12955 = list3(v_12957, v_12956, v_12955);
    env = stack[-5];
    goto v_12875;
v_12876:
    goto v_12872;
v_12873:
    goto v_12874;
v_12875:
    fn = elt(env, 19); // rederr2
    v_12955 = (*qfn2(fn))(fn, stack[-1], v_12955);
    goto v_12784;
v_12784:
    goto v_12772;
v_12774:
    goto v_12900;
v_12896:
    v_12956 = stack[-4];
    goto v_12897;
v_12898:
    v_12955 = elt(env, 9); // physopmapping
    goto v_12899;
v_12900:
    goto v_12896;
v_12897:
    goto v_12898;
v_12899:
    v_12955 = Lflagp(nil, v_12956, v_12955);
    env = stack[-5];
    if (v_12955 == nil) goto v_12894;
    v_12955 = stack[-2];
    fn = elt(env, 20); // !*physopp!*
    v_12955 = (*qfn1(fn))(fn, v_12955);
    env = stack[-5];
    goto v_12892;
v_12894:
    v_12955 = nil;
    goto v_12892;
    v_12955 = nil;
v_12892:
    if (v_12955 == nil) goto v_12890;
    goto v_12914;
v_12910:
    goto v_12921;
v_12917:
    goto v_12927;
v_12923:
    goto v_12933;
v_12929:
    v_12956 = stack[-4];
    goto v_12930;
v_12931:
    v_12955 = stack[-2];
    goto v_12932;
v_12933:
    goto v_12929;
v_12930:
    goto v_12931;
v_12932:
    v_12956 = cons(v_12956, v_12955);
    env = stack[-5];
    goto v_12924;
v_12925:
    v_12955 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12926;
v_12927:
    goto v_12923;
v_12924:
    goto v_12925;
v_12926:
    fn = elt(env, 21); // to
    v_12956 = (*qfn2(fn))(fn, v_12956, v_12955);
    env = stack[-5];
    goto v_12918;
v_12919:
    v_12955 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12920;
v_12921:
    goto v_12917;
v_12918:
    goto v_12919;
v_12920:
    v_12955 = cons(v_12956, v_12955);
    env = stack[-5];
    v_12956 = ncons(v_12955);
    env = stack[-5];
    goto v_12911;
v_12912:
    v_12955 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12913;
v_12914:
    goto v_12910;
v_12911:
    goto v_12912;
v_12913:
    v_12955 = cons(v_12956, v_12955);
    env = stack[-5];
    fn = elt(env, 22); // mk!*sq
    v_12955 = (*qfn1(fn))(fn, v_12955);
    stack[0] = v_12955;
    goto v_12772;
v_12890:
    goto v_12945;
v_12941:
    v_12956 = stack[-4];
    goto v_12942;
v_12943:
    v_12955 = elt(env, 10); // prog
    goto v_12944;
v_12945:
    goto v_12941;
v_12942:
    goto v_12943;
v_12944:
    if (v_12956 == v_12955) goto v_12939;
    else goto v_12940;
v_12939:
    v_12955 = stack[-2];
    fn = elt(env, 23); // physopprog
    v_12955 = (*qfn1(fn))(fn, v_12955);
    stack[0] = v_12955;
    goto v_12772;
v_12940:
    v_12955 = stack[-3];
    fn = elt(env, 14); // aeval
    v_12955 = (*qfn1(fn))(fn, v_12955);
    stack[0] = v_12955;
    goto v_12772;
v_12772:
    goto v_12698;
v_12698:
    v_12955 = stack[0];
    return onevalue(v_12955);
}



// Code for prepd1

static LispObject CC_prepd1(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12714, v_12715, v_12716;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
// copy arguments values to proper place
    v_12716 = v_12688;
// end of prologue
    v_12714 = v_12716;
    if (!consp(v_12714)) goto v_12692;
    else goto v_12693;
v_12692:
    v_12714 = v_12716;
    goto v_12691;
v_12693:
    goto v_12703;
v_12699:
    goto v_12709;
v_12705:
    v_12714 = v_12716;
    v_12715 = qcar(v_12714);
    goto v_12706;
v_12707:
    v_12714 = elt(env, 1); // prepfn
    goto v_12708;
v_12709:
    goto v_12705;
v_12706:
    goto v_12707;
v_12708:
    v_12714 = get(v_12715, v_12714);
    goto v_12700;
v_12701:
    v_12715 = v_12716;
    goto v_12702;
v_12703:
    goto v_12699;
v_12700:
    goto v_12701;
v_12702:
        return Lapply1(nil, v_12714, v_12715);
    v_12714 = nil;
v_12691:
    return onevalue(v_12714);
}



// Code for ad_numsort

static LispObject CC_ad_numsort(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12698, v_12699;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12698 = v_12688;
// end of prologue
    goto v_12695;
v_12691:
    v_12699 = v_12698;
    goto v_12692;
v_12693:
    v_12698 = elt(env, 1); // lambda_ygm6np4pcqv31
    goto v_12694;
v_12695:
    goto v_12691;
v_12692:
    goto v_12693;
v_12694:
    {
        fn = elt(env, 2); // sort
        return (*qfn2(fn))(fn, v_12699, v_12698);
    }
}



// Code for lambda_ygm6np4pcqv31

static LispObject CC_lambda_ygm6np4pcqv31(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12699, v_12700;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12699 = v_12689;
    v_12700 = v_12688;
// end of prologue
    goto v_12696;
v_12692:
    goto v_12693;
v_12694:
    goto v_12695;
v_12696:
    goto v_12692;
v_12693:
    goto v_12694;
v_12695:
        return Lleq(nil, v_12700, v_12699);
}



// Code for rlis

static LispObject CC_rlis(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12739, v_12740;
    LispObject fn;
    argcheck(nargs, 0, "rlis");
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
    v_12739 = qvalue(elt(env, 1)); // cursym!*
    stack[0] = v_12739;
    fn = elt(env, 5); // scan
    v_12739 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (!symbolp(v_12739)) v_12739 = nil;
    else { v_12739 = qfastgets(v_12739);
           if (v_12739 != nil) { v_12739 = elt(v_12739, 55); // delim
#ifdef RECORD_GET
             if (v_12739 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v_12739 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v_12739 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v_12739 == SPID_NOPROP) v_12739 = nil; else v_12739 = lisp_true; }}
#endif
    if (v_12739 == nil) goto v_12696;
    goto v_12704;
v_12700:
    v_12740 = stack[0];
    goto v_12701;
v_12702:
    v_12739 = nil;
    goto v_12703;
v_12704:
    goto v_12700;
v_12701:
    goto v_12702;
v_12703:
    return list2(v_12740, v_12739);
v_12696:
    v_12739 = qvalue(elt(env, 2)); // !*reduce4
    if (v_12739 == nil) goto v_12708;
    goto v_12715;
v_12711:
    stack[-1] = stack[0];
    goto v_12712;
v_12713:
    goto v_12722;
v_12718:
    stack[0] = elt(env, 3); // list
    goto v_12719;
v_12720:
    v_12739 = elt(env, 4); // lambda
    fn = elt(env, 6); // xread1
    v_12739 = (*qfn1(fn))(fn, v_12739);
    env = stack[-2];
    fn = elt(env, 7); // remcomma
    v_12739 = (*qfn1(fn))(fn, v_12739);
    env = stack[-2];
    goto v_12721;
v_12722:
    goto v_12718;
v_12719:
    goto v_12720;
v_12721:
    v_12739 = cons(stack[0], v_12739);
    goto v_12714;
v_12715:
    goto v_12711;
v_12712:
    goto v_12713;
v_12714:
    {
        LispObject v_12743 = stack[-1];
        return list2(v_12743, v_12739);
    }
v_12708:
    goto v_12734;
v_12730:
    goto v_12731;
v_12732:
    v_12739 = elt(env, 4); // lambda
    fn = elt(env, 6); // xread1
    v_12739 = (*qfn1(fn))(fn, v_12739);
    env = stack[-2];
    fn = elt(env, 7); // remcomma
    v_12739 = (*qfn1(fn))(fn, v_12739);
    goto v_12733;
v_12734:
    goto v_12730;
v_12731:
    goto v_12732;
v_12733:
    {
        LispObject v_12744 = stack[0];
        return cons(v_12744, v_12739);
    }
    v_12739 = nil;
    return onevalue(v_12739);
}



// Code for ibalp_isinminclause

static LispObject CC_ibalp_isinminclause(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12821, v_12822;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_12689;
    stack[-2] = v_12688;
// end of prologue
    stack[0] = nil;
    v_12821 = stack[-2];
    v_12821 = qcdr(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcar(v_12821);
    stack[-3] = v_12821;
v_12701:
    v_12821 = stack[-3];
    if (v_12821 == nil) goto v_12704;
    v_12821 = stack[0];
    if (v_12821 == nil) goto v_12708;
    else goto v_12704;
v_12708:
    goto v_12705;
v_12704:
    goto v_12700;
v_12705:
    v_12821 = stack[-3];
    v_12821 = qcar(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcar(v_12821);
    if (v_12821 == nil) goto v_12717;
    else goto v_12718;
v_12717:
    goto v_12731;
v_12727:
    goto v_12737;
v_12733:
    v_12821 = stack[-3];
    v_12821 = qcar(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcdr(v_12821);
    v_12822 = qcar(v_12821);
    goto v_12734;
v_12735:
    v_12821 = stack[-3];
    v_12821 = qcar(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcar(v_12821);
    goto v_12736;
v_12737:
    goto v_12733;
v_12734:
    goto v_12735;
v_12736:
    v_12822 = plus2(v_12822, v_12821);
    env = stack[-4];
    goto v_12728;
v_12729:
    v_12821 = stack[-1];
    goto v_12730;
v_12731:
    goto v_12727;
v_12728:
    goto v_12729;
v_12730:
    v_12821 = Leqn(nil, v_12822, v_12821);
    env = stack[-4];
    goto v_12716;
v_12718:
    v_12821 = nil;
    goto v_12716;
    v_12821 = nil;
v_12716:
    if (v_12821 == nil) goto v_12714;
    v_12821 = lisp_true;
    stack[0] = v_12821;
    goto v_12712;
v_12714:
v_12712:
    v_12821 = stack[-3];
    v_12821 = qcdr(v_12821);
    stack[-3] = v_12821;
    goto v_12701;
v_12700:
    v_12821 = stack[-2];
    v_12821 = qcdr(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcar(v_12821);
    stack[-3] = v_12821;
v_12764:
    v_12821 = stack[-3];
    if (v_12821 == nil) goto v_12767;
    v_12821 = stack[0];
    if (v_12821 == nil) goto v_12771;
    else goto v_12767;
v_12771:
    goto v_12768;
v_12767:
    goto v_12763;
v_12768:
    v_12821 = stack[-3];
    v_12821 = qcar(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcar(v_12821);
    if (v_12821 == nil) goto v_12780;
    else goto v_12781;
v_12780:
    goto v_12794;
v_12790:
    goto v_12800;
v_12796:
    v_12821 = stack[-3];
    v_12821 = qcar(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcdr(v_12821);
    v_12822 = qcar(v_12821);
    goto v_12797;
v_12798:
    v_12821 = stack[-3];
    v_12821 = qcar(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcdr(v_12821);
    v_12821 = qcar(v_12821);
    goto v_12799;
v_12800:
    goto v_12796;
v_12797:
    goto v_12798;
v_12799:
    v_12822 = plus2(v_12822, v_12821);
    env = stack[-4];
    goto v_12791;
v_12792:
    v_12821 = stack[-1];
    goto v_12793;
v_12794:
    goto v_12790;
v_12791:
    goto v_12792;
v_12793:
    v_12821 = Leqn(nil, v_12822, v_12821);
    env = stack[-4];
    goto v_12779;
v_12781:
    v_12821 = nil;
    goto v_12779;
    v_12821 = nil;
v_12779:
    if (v_12821 == nil) goto v_12777;
    v_12821 = lisp_true;
    stack[0] = v_12821;
    goto v_12775;
v_12777:
v_12775:
    v_12821 = stack[-3];
    v_12821 = qcdr(v_12821);
    stack[-3] = v_12821;
    goto v_12764;
v_12763:
    v_12821 = stack[0];
    return onevalue(v_12821);
}



// Code for !*!*a2s

static LispObject CC_HHa2s(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12774, v_12775;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_12774 = v_12689;
    stack[-3] = v_12688;
// end of prologue
    v_12774 = stack[-3];
    if (v_12774 == nil) goto v_12693;
    else goto v_12694;
v_12693:
    v_12774 = elt(env, 1); // "tell Hearn!!"
    {
        fn = elt(env, 10); // rederr
        return (*qfn1(fn))(fn, v_12774);
    }
v_12694:
    goto v_12706;
v_12702:
    v_12775 = stack[-3];
    goto v_12703;
v_12704:
    v_12774 = elt(env, 2); // nochange
    goto v_12705;
v_12706:
    goto v_12702;
v_12703:
    goto v_12704;
v_12705:
    v_12774 = Lflagpcar(nil, v_12775, v_12774);
    env = stack[-5];
    if (v_12774 == nil) goto v_12699;
    goto v_12714;
v_12710:
    v_12774 = stack[-3];
    v_12775 = qcar(v_12774);
    goto v_12711;
v_12712:
    v_12774 = elt(env, 3); // getel
    goto v_12713;
v_12714:
    goto v_12710;
v_12711:
    goto v_12712;
v_12713:
    if (v_12775 == v_12774) goto v_12699;
    v_12774 = stack[-3];
    goto v_12692;
v_12699:
    goto v_12726;
v_12722:
    v_12775 = elt(env, 4); // random
    goto v_12723;
v_12724:
    v_12774 = stack[-3];
    goto v_12725;
v_12726:
    goto v_12722;
v_12723:
    goto v_12724;
v_12725:
    fn = elt(env, 11); // smember
    v_12774 = (*qfn2(fn))(fn, v_12775, v_12774);
    env = stack[-5];
    if (v_12774 == nil) goto v_12720;
    goto v_12734;
v_12730:
    goto v_12742;
v_12736:
    stack[-4] = elt(env, 5); // lambda
    goto v_12737;
v_12738:
    stack[-2] = elt(env, 6); // (!*uncached)
    goto v_12739;
v_12740:
    goto v_12752;
v_12746:
    stack[-1] = elt(env, 7); // progn
    goto v_12747;
v_12748:
    stack[0] = elt(env, 8); // (declare (special !*uncached))
    goto v_12749;
v_12750:
    goto v_12760;
v_12756:
    v_12775 = qvalue(elt(env, 9)); // !*!*a2sfn
    goto v_12757;
v_12758:
    v_12774 = stack[-3];
    goto v_12759;
v_12760:
    goto v_12756;
v_12757:
    goto v_12758;
v_12759:
    v_12774 = list2(v_12775, v_12774);
    env = stack[-5];
    goto v_12751;
v_12752:
    goto v_12746;
v_12747:
    goto v_12748;
v_12749:
    goto v_12750;
v_12751:
    v_12774 = list3(stack[-1], stack[0], v_12774);
    env = stack[-5];
    goto v_12741;
v_12742:
    goto v_12736;
v_12737:
    goto v_12738;
v_12739:
    goto v_12740;
v_12741:
    v_12775 = list3(stack[-4], stack[-2], v_12774);
    goto v_12731;
v_12732:
    v_12774 = lisp_true;
    goto v_12733;
v_12734:
    goto v_12730;
v_12731:
    goto v_12732;
v_12733:
    return list2(v_12775, v_12774);
v_12720:
    goto v_12771;
v_12767:
    v_12775 = qvalue(elt(env, 9)); // !*!*a2sfn
    goto v_12768;
v_12769:
    v_12774 = stack[-3];
    goto v_12770;
v_12771:
    goto v_12767;
v_12768:
    goto v_12769;
v_12770:
    return list2(v_12775, v_12774);
    v_12774 = nil;
v_12692:
    return onevalue(v_12774);
}



// Code for ps!:prepfn!:

static LispObject CC_psTprepfnT(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12691;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12691 = v_12688;
// end of prologue
    return onevalue(v_12691);
}



// Code for dm!-minus

static LispObject CC_dmKminus(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12702, v_12703;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
// copy arguments values to proper place
    v_12702 = v_12688;
// end of prologue
    fn = elt(env, 1); // !:minus
    v_12702 = (*qfn1(fn))(fn, v_12702);
    v_12703 = v_12702;
    v_12702 = v_12703;
    if (v_12702 == nil) goto v_12695;
    else goto v_12696;
v_12695:
    v_12702 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12694;
v_12696:
    v_12702 = v_12703;
    goto v_12694;
    v_12702 = nil;
v_12694:
    return onevalue(v_12702);
}



// Code for groebcplistsortin1

static LispObject CC_groebcplistsortin1(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12749, v_12750;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12689;
    stack[-1] = v_12688;
// end of prologue
v_12693:
    goto v_12703;
v_12699:
    v_12749 = stack[0];
    v_12750 = qcar(v_12749);
    goto v_12700;
v_12701:
    v_12749 = stack[-1];
    goto v_12702;
v_12703:
    goto v_12699;
v_12700:
    goto v_12701;
v_12702:
    fn = elt(env, 1); // groebcpcompless!?
    v_12749 = (*qfn2(fn))(fn, v_12750, v_12749);
    env = stack[-3];
    if (v_12749 == nil) goto v_12696;
    else goto v_12697;
v_12696:
    goto v_12712;
v_12708:
    stack[-2] = stack[0];
    goto v_12709;
v_12710:
    goto v_12719;
v_12715:
    v_12749 = stack[0];
    v_12750 = qcar(v_12749);
    goto v_12716;
v_12717:
    v_12749 = stack[0];
    v_12749 = qcdr(v_12749);
    goto v_12718;
v_12719:
    goto v_12715;
v_12716:
    goto v_12717;
v_12718:
    v_12749 = cons(v_12750, v_12749);
    env = stack[-3];
    goto v_12711;
v_12712:
    goto v_12708;
v_12709:
    goto v_12710;
v_12711:
    v_12749 = Lrplacd(nil, stack[-2], v_12749);
    goto v_12729;
v_12725:
    v_12750 = stack[0];
    goto v_12726;
v_12727:
    v_12749 = stack[-1];
    goto v_12728;
v_12729:
    goto v_12725;
v_12726:
    goto v_12727;
v_12728:
        return Lrplaca(nil, v_12750, v_12749);
v_12697:
    v_12749 = stack[0];
    v_12749 = qcdr(v_12749);
    if (v_12749 == nil) goto v_12732;
    else goto v_12733;
v_12732:
    goto v_12741;
v_12737:
    goto v_12738;
v_12739:
    v_12749 = stack[-1];
    v_12749 = ncons(v_12749);
    goto v_12740;
v_12741:
    goto v_12737;
v_12738:
    goto v_12739;
v_12740:
    {
        LispObject v_12754 = stack[0];
        return Lrplacd(nil, v_12754, v_12749);
    }
v_12733:
    v_12749 = stack[0];
    v_12749 = qcdr(v_12749);
    stack[0] = v_12749;
    goto v_12693;
    v_12749 = nil;
    return onevalue(v_12749);
}



// Code for bytelist2id

static LispObject CC_bytelist2id(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12693;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
// copy arguments values to proper place
    v_12693 = v_12688;
// end of prologue
    fn = elt(env, 1); // list2string
    v_12693 = (*qfn1(fn))(fn, v_12693);
        return Lintern(nil, v_12693);
}



// Code for gfdot

static LispObject CC_gfdot(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12715, v_12716, v_12717;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12716 = v_12689;
    v_12717 = v_12688;
// end of prologue
    v_12715 = v_12717;
    v_12715 = qcar(v_12715);
    if (!consp(v_12715)) goto v_12693;
    else goto v_12694;
v_12693:
    goto v_12702;
v_12698:
    v_12715 = v_12717;
    goto v_12699;
v_12700:
    goto v_12701;
v_12702:
    goto v_12698;
v_12699:
    goto v_12700;
v_12701:
    {
        fn = elt(env, 1); // gffdot
        return (*qfn2(fn))(fn, v_12715, v_12716);
    }
v_12694:
    goto v_12712;
v_12708:
    v_12715 = v_12717;
    goto v_12709;
v_12710:
    goto v_12711;
v_12712:
    goto v_12708;
v_12709:
    goto v_12710;
v_12711:
    {
        fn = elt(env, 2); // gbfdot
        return (*qfn2(fn))(fn, v_12715, v_12716);
    }
    v_12715 = nil;
    return onevalue(v_12715);
}



// Code for rdcos!*

static LispObject CC_rdcosH(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12705, v_12706;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12705 = v_12688;
// end of prologue
    fn = elt(env, 1); // convprec
    v_12705 = (*qfn1(fn))(fn, v_12705);
    env = stack[0];
    v_12706 = v_12705;
    v_12705 = v_12706;
    if (!consp(v_12705)) goto v_12696;
    else goto v_12697;
v_12696:
    v_12705 = v_12706;
    fn = elt(env, 2); // cos
    v_12705 = (*qfn1(fn))(fn, v_12705);
    env = stack[0];
    goto v_12695;
v_12697:
    v_12705 = v_12706;
    fn = elt(env, 3); // cos!*
    v_12705 = (*qfn1(fn))(fn, v_12705);
    env = stack[0];
    goto v_12695;
    v_12705 = nil;
v_12695:
    {
        fn = elt(env, 4); // mkround
        return (*qfn1(fn))(fn, v_12705);
    }
}



// Code for mkfortterpri

static LispObject CC_mkfortterpri(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12691;
    argcheck(nargs, 0, "mkfortterpri");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_12691 = elt(env, 1); // fortterpri
    return ncons(v_12691);
}



// Code for trwrite

static LispObject CC_trwrite(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12729;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_12688;
// end of prologue
    v_12729 = stack[0];
    v_12729 = qcar(v_12729);
    if (!symbolp(v_12729)) v_12729 = nil;
    else { v_12729 = qfastgets(v_12729);
           if (v_12729 != nil) { v_12729 = elt(v_12729, 53); // tracing
#ifdef RECORD_GET
             if (v_12729 == SPID_NOPROP)
                record_get(elt(fastget_names, 53), 0),
                v_12729 = nil;
             else record_get(elt(fastget_names, 53), 1),
                v_12729 = lisp_true; }
           else record_get(elt(fastget_names, 53), 0); }
#else
             if (v_12729 == SPID_NOPROP) v_12729 = nil; else v_12729 = lisp_true; }}
#endif
    if (v_12729 == nil) goto v_12695;
    else goto v_12696;
v_12695:
    v_12729 = nil;
    goto v_12692;
v_12696:
    v_12729 = elt(env, 1); // "**in procedure: "
    v_12729 = Lprinc(nil, v_12729);
    env = stack[-1];
    v_12729 = stack[0];
    v_12729 = qcar(v_12729);
    v_12729 = Lprinc(nil, v_12729);
    env = stack[-1];
    v_12729 = Lterpri(nil, 0);
    env = stack[-1];
    v_12729 = stack[0];
    v_12729 = qcdr(v_12729);
    stack[0] = v_12729;
v_12711:
    v_12729 = stack[0];
    if (v_12729 == nil) goto v_12716;
    else goto v_12717;
v_12716:
    goto v_12710;
v_12717:
    v_12729 = stack[0];
    v_12729 = qcar(v_12729);
    v_12729 = Lprinc(nil, v_12729);
    env = stack[-1];
    v_12729 = stack[0];
    v_12729 = qcdr(v_12729);
    stack[0] = v_12729;
    goto v_12711;
v_12710:
    v_12729 = Lterpri(nil, 0);
    v_12729 = nil;
v_12692:
    return onevalue(v_12729);
}



// Code for one!-entry!-listp

static LispObject CC_oneKentryKlistp(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12724, v_12725;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12689;
    stack[-1] = v_12688;
// end of prologue
v_12687:
    v_12724 = stack[-1];
    if (v_12724 == nil) goto v_12693;
    else goto v_12694;
v_12693:
    v_12724 = lisp_true;
    goto v_12692;
v_12694:
    goto v_12708;
v_12704:
    v_12724 = stack[-1];
    v_12725 = qcar(v_12724);
    goto v_12705;
v_12706:
    v_12724 = stack[0];
    goto v_12707;
v_12708:
    goto v_12704;
v_12705:
    goto v_12706;
v_12707:
    fn = elt(env, 1); // one!-entryp
    v_12724 = (*qfn2(fn))(fn, v_12725, v_12724);
    env = stack[-2];
    if (v_12724 == nil) goto v_12701;
    else goto v_12702;
v_12701:
    v_12724 = nil;
    goto v_12700;
v_12702:
    goto v_12720;
v_12716:
    v_12724 = stack[-1];
    v_12725 = qcdr(v_12724);
    goto v_12717;
v_12718:
    v_12724 = stack[0];
    goto v_12719;
v_12720:
    goto v_12716;
v_12717:
    goto v_12718;
v_12719:
    stack[-1] = v_12725;
    stack[0] = v_12724;
    goto v_12687;
    v_12724 = nil;
v_12700:
    goto v_12692;
    v_12724 = nil;
v_12692:
    return onevalue(v_12724);
}



// Code for fs!:times

static LispObject CC_fsTtimes(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12736, v_12737;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12689;
    stack[-1] = v_12688;
// end of prologue
    v_12736 = stack[-1];
    if (v_12736 == nil) goto v_12693;
    else goto v_12694;
v_12693:
    v_12736 = nil;
    goto v_12692;
v_12694:
    v_12736 = stack[0];
    if (v_12736 == nil) goto v_12697;
    else goto v_12698;
v_12697:
    v_12736 = nil;
    goto v_12692;
v_12698:
    goto v_12711;
v_12707:
    v_12737 = stack[-1];
    goto v_12708;
v_12709:
    v_12736 = stack[0];
    goto v_12710;
v_12711:
    goto v_12707;
v_12708:
    goto v_12709;
v_12710:
    fn = elt(env, 1); // fs!:timesterm
    v_12736 = (*qfn2(fn))(fn, v_12737, v_12736);
    env = stack[-3];
    goto v_12719;
v_12715:
    stack[-2] = v_12736;
    goto v_12716;
v_12717:
    goto v_12726;
v_12722:
    goto v_12731;
v_12727:
    v_12737 = stack[-1];
    goto v_12728;
v_12729:
    v_12736 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_12730;
v_12731:
    goto v_12727;
v_12728:
    goto v_12729;
v_12730:
    v_12737 = *(LispObject *)((char *)v_12737 + (CELL-TAG_VECTOR) + (((intptr_t)v_12736-TAG_FIXNUM)/(16/CELL)));
    goto v_12723;
v_12724:
    v_12736 = stack[0];
    goto v_12725;
v_12726:
    goto v_12722;
v_12723:
    goto v_12724;
v_12725:
    v_12736 = CC_fsTtimes(elt(env, 0), v_12737, v_12736);
    env = stack[-3];
    goto v_12718;
v_12719:
    goto v_12715;
v_12716:
    goto v_12717;
v_12718:
    {
        LispObject v_12741 = stack[-2];
        fn = elt(env, 2); // fs!:plus
        return (*qfn2(fn))(fn, v_12741, v_12736);
    }
    goto v_12692;
    v_12736 = nil;
v_12692:
    return onevalue(v_12736);
}



// Code for moid_member

static LispObject CC_moid_member(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12720, v_12721;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12689;
    stack[-1] = v_12688;
// end of prologue
v_12687:
    v_12720 = stack[0];
    if (v_12720 == nil) goto v_12693;
    else goto v_12694;
v_12693:
    v_12720 = nil;
    goto v_12692;
v_12694:
    goto v_12707;
v_12703:
    v_12720 = stack[0];
    v_12721 = qcar(v_12720);
    goto v_12704;
v_12705:
    v_12720 = stack[-1];
    goto v_12706;
v_12707:
    goto v_12703;
v_12704:
    goto v_12705;
v_12706:
    fn = elt(env, 1); // mo_vdivides!?
    v_12720 = (*qfn2(fn))(fn, v_12721, v_12720);
    env = stack[-2];
    if (v_12720 == nil) goto v_12701;
    else goto v_12700;
v_12701:
    goto v_12716;
v_12712:
    v_12721 = stack[-1];
    goto v_12713;
v_12714:
    v_12720 = stack[0];
    v_12720 = qcdr(v_12720);
    goto v_12715;
v_12716:
    goto v_12712;
v_12713:
    goto v_12714;
v_12715:
    stack[-1] = v_12721;
    stack[0] = v_12720;
    goto v_12687;
v_12700:
    goto v_12692;
    v_12720 = nil;
v_12692:
    return onevalue(v_12720);
}



// Code for splitlist!:

static LispObject CC_splitlistT(LispObject env,
                         LispObject v_12688, LispObject v_12689)
{
    env = qenv(env);
    LispObject v_12728, v_12729, v_12730;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12688,v_12689);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12689;
    stack[-1] = v_12688;
// end of prologue
    v_12730 = nil;
v_12694:
    v_12728 = stack[-1];
    if (v_12728 == nil) goto v_12697;
    else goto v_12698;
v_12697:
    v_12728 = v_12730;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12728);
    }
v_12698:
    goto v_12709;
v_12705:
    v_12728 = stack[-1];
    v_12729 = qcar(v_12728);
    goto v_12706;
v_12707:
    v_12728 = stack[0];
    goto v_12708;
v_12709:
    goto v_12705;
v_12706:
    goto v_12707;
v_12708:
    if (!consp(v_12729)) goto v_12703;
    v_12729 = qcar(v_12729);
    if (v_12729 == v_12728) goto v_12702;
    else goto v_12703;
v_12702:
    goto v_12718;
v_12714:
    v_12728 = stack[-1];
    v_12728 = qcar(v_12728);
    goto v_12715;
v_12716:
    v_12729 = v_12730;
    goto v_12717;
v_12718:
    goto v_12714;
v_12715:
    goto v_12716;
v_12717:
    v_12728 = cons(v_12728, v_12729);
    env = stack[-2];
    v_12730 = v_12728;
    v_12728 = stack[-1];
    v_12728 = qcdr(v_12728);
    stack[-1] = v_12728;
    goto v_12694;
v_12703:
    v_12728 = stack[-1];
    v_12728 = qcdr(v_12728);
    stack[-1] = v_12728;
    goto v_12694;
    v_12728 = nil;
    return onevalue(v_12728);
}



// Code for resimpf

static LispObject CC_resimpf(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12701, v_12702;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_12702 = v_12688;
// end of prologue
    v_12701 = nil;
// Binding varstack!*
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_12701; // varstack!*
    goto v_12697;
v_12693:
    goto v_12694;
v_12695:
    v_12701 = nil;
    goto v_12696;
v_12697:
    goto v_12693;
v_12694:
    goto v_12695;
v_12696:
    fn = elt(env, 2); // subf1
    v_12701 = (*qfn2(fn))(fn, v_12702, v_12701);
    v_12701 = qcar(v_12701);
    ;}  // end of a binding scope
    return onevalue(v_12701);
}



// Code for gfk

static LispObject CC_gfk(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12766, v_12767, v_12768, v_12769, v_12770, v_12771;
    LispObject v_12690, v_12689, v_12688;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "gfk");
    va_start(aa, nargs);
    v_12688 = va_arg(aa, LispObject);
    v_12689 = va_arg(aa, LispObject);
    v_12690 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12690,v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12688,v_12689,v_12690);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_12769 = v_12690;
    v_12770 = v_12689;
    v_12766 = v_12688;
// end of prologue
v_12687:
    v_12767 = v_12769;
    if (v_12767 == nil) goto v_12696;
    else goto v_12694;
v_12696:
    v_12767 = v_12766;
    if (!consp(v_12767)) goto v_12701;
    else goto v_12702;
v_12701:
    v_12767 = lisp_true;
    goto v_12700;
v_12702:
    v_12767 = v_12766;
    v_12767 = qcar(v_12767);
    v_12767 = (consp(v_12767) ? nil : lisp_true);
    goto v_12700;
    v_12767 = nil;
v_12700:
    if (v_12767 == nil) goto v_12698;
    else goto v_12694;
v_12698:
    goto v_12695;
v_12694:
    v_12766 = v_12769;
    goto v_12693;
v_12695:
    v_12767 = v_12766;
    v_12767 = qcar(v_12767);
    v_12767 = qcar(v_12767);
    v_12767 = qcar(v_12767);
    v_12771 = v_12767;
    goto v_12725;
v_12719:
    v_12767 = v_12766;
    stack[-1] = qcdr(v_12767);
    goto v_12720;
v_12721:
    stack[0] = v_12770;
    goto v_12722;
v_12723:
    goto v_12736;
v_12730:
    v_12766 = qcar(v_12766);
    v_12768 = qcdr(v_12766);
    goto v_12731;
v_12732:
    v_12767 = v_12770;
    goto v_12733;
v_12734:
    v_12766 = v_12771;
    if (!consp(v_12766)) goto v_12748;
    goto v_12754;
v_12750:
    v_12766 = v_12771;
    v_12766 = qcar(v_12766);
    goto v_12751;
v_12752:
    goto v_12753;
v_12754:
    goto v_12750;
v_12751:
    goto v_12752;
v_12753:
    v_12766 = Lmember(nil, v_12766, v_12770);
    goto v_12746;
v_12748:
    v_12766 = nil;
    goto v_12746;
    v_12766 = nil;
v_12746:
    if (v_12766 == nil) goto v_12744;
    v_12766 = v_12771;
    goto v_12742;
v_12744:
    v_12766 = v_12769;
    goto v_12742;
    v_12766 = nil;
v_12742:
    goto v_12735;
v_12736:
    goto v_12730;
v_12731:
    goto v_12732;
v_12733:
    goto v_12734;
v_12735:
    v_12767 = CC_gfk(elt(env, 0), 3, v_12768, v_12767, v_12766);
    env = stack[-2];
    goto v_12724;
v_12725:
    goto v_12719;
v_12720:
    goto v_12721;
v_12722:
    goto v_12723;
v_12724:
    v_12766 = stack[-1];
    v_12770 = stack[0];
    v_12769 = v_12767;
    goto v_12687;
    v_12766 = nil;
v_12693:
    return onevalue(v_12766);
}



// Code for gcref_mkgraph!-tgf

static LispObject CC_gcref_mkgraphKtgf(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12742, v_12743;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12688;
// end of prologue
    v_12742 = stack[0];
    stack[-1] = v_12742;
v_12693:
    v_12742 = stack[-1];
    if (v_12742 == nil) goto v_12697;
    else goto v_12698;
v_12697:
    goto v_12692;
v_12698:
    v_12742 = stack[-1];
    v_12742 = qcar(v_12742);
    fn = elt(env, 3); // gcref_mknode!-tgf
    v_12742 = (*qfn1(fn))(fn, v_12742);
    env = stack[-2];
    v_12742 = stack[-1];
    v_12742 = qcdr(v_12742);
    stack[-1] = v_12742;
    goto v_12693;
v_12692:
    v_12742 = elt(env, 1); // "#"
    fn = elt(env, 4); // prin2t
    v_12742 = (*qfn1(fn))(fn, v_12742);
    env = stack[-2];
    v_12742 = stack[0];
    stack[-1] = v_12742;
v_12713:
    v_12742 = stack[-1];
    if (v_12742 == nil) goto v_12717;
    else goto v_12718;
v_12717:
    v_12742 = nil;
    goto v_12712;
v_12718:
    v_12742 = stack[-1];
    v_12742 = qcar(v_12742);
    goto v_12729;
v_12725:
    stack[0] = v_12742;
    goto v_12726;
v_12727:
    goto v_12737;
v_12733:
    v_12743 = v_12742;
    goto v_12734;
v_12735:
    v_12742 = elt(env, 2); // calls
    goto v_12736;
v_12737:
    goto v_12733;
v_12734:
    goto v_12735;
v_12736:
    v_12742 = get(v_12743, v_12742);
    env = stack[-2];
    fn = elt(env, 5); // gcref_select
    v_12742 = (*qfn1(fn))(fn, v_12742);
    env = stack[-2];
    goto v_12728;
v_12729:
    goto v_12725;
v_12726:
    goto v_12727;
v_12728:
    fn = elt(env, 6); // gcref_mkedges!-tgf
    v_12742 = (*qfn2(fn))(fn, stack[0], v_12742);
    env = stack[-2];
    v_12742 = stack[-1];
    v_12742 = qcdr(v_12742);
    stack[-1] = v_12742;
    goto v_12713;
v_12712:
    return onevalue(v_12742);
}



// Code for rl_atnum

static LispObject CC_rl_atnum(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12699;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_12699 = v_12688;
// end of prologue
    goto v_12695;
v_12691:
    stack[0] = qvalue(elt(env, 1)); // rl_atnum!*
    goto v_12692;
v_12693:
    v_12699 = ncons(v_12699);
    env = stack[-1];
    goto v_12694;
v_12695:
    goto v_12691;
v_12692:
    goto v_12693;
v_12694:
    {
        LispObject v_12701 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_12701, v_12699);
    }
}



// Code for ofsf_subf

static LispObject CC_ofsf_subf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12818, v_12819, v_12820;
    LispObject fn;
    LispObject v_12690, v_12689, v_12688;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_subf");
    va_start(aa, nargs);
    v_12688 = va_arg(aa, LispObject);
    v_12689 = va_arg(aa, LispObject);
    v_12690 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12690,v_12689,v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12688,v_12689,v_12690);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_12690;
    stack[-1] = v_12689;
    stack[-2] = v_12688;
// end of prologue
    v_12818 = stack[-2];
    if (!consp(v_12818)) goto v_12701;
    else goto v_12702;
v_12701:
    v_12818 = lisp_true;
    goto v_12700;
v_12702:
    v_12818 = stack[-2];
    v_12818 = qcar(v_12818);
    v_12818 = (consp(v_12818) ? nil : lisp_true);
    goto v_12700;
    v_12818 = nil;
v_12700:
    if (v_12818 == nil) goto v_12698;
    goto v_12715;
v_12711:
    v_12819 = stack[-2];
    goto v_12712;
v_12713:
    v_12818 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12714;
v_12715:
    goto v_12711;
v_12712:
    goto v_12713;
v_12714:
    return cons(v_12819, v_12818);
v_12698:
    goto v_12725;
v_12719:
    v_12818 = stack[-2];
    v_12820 = qcdr(v_12818);
    goto v_12720;
v_12721:
    v_12819 = stack[-1];
    goto v_12722;
v_12723:
    v_12818 = stack[0];
    goto v_12724;
v_12725:
    goto v_12719;
v_12720:
    goto v_12721;
v_12722:
    goto v_12723;
v_12724:
    v_12818 = CC_ofsf_subf(elt(env, 0), 3, v_12820, v_12819, v_12818);
    env = stack[-4];
    stack[-3] = v_12818;
    goto v_12738;
v_12734:
    v_12818 = stack[-2];
    v_12818 = qcar(v_12818);
    v_12818 = qcar(v_12818);
    v_12819 = qcar(v_12818);
    goto v_12735;
v_12736:
    v_12818 = stack[-1];
    goto v_12737;
v_12738:
    goto v_12734;
v_12735:
    goto v_12736;
v_12737:
    if (v_12819 == v_12818) goto v_12732;
    else goto v_12733;
v_12732:
    goto v_12749;
v_12745:
    goto v_12755;
v_12751:
    goto v_12761;
v_12757:
    v_12818 = stack[-2];
    v_12818 = qcar(v_12818);
    v_12819 = qcdr(v_12818);
    goto v_12758;
v_12759:
    v_12818 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12760;
v_12761:
    goto v_12757;
v_12758:
    goto v_12759;
v_12760:
    stack[-1] = cons(v_12819, v_12818);
    env = stack[-4];
    goto v_12752;
v_12753:
    goto v_12771;
v_12767:
    v_12819 = stack[0];
    goto v_12768;
v_12769:
    v_12818 = stack[-2];
    v_12818 = qcar(v_12818);
    v_12818 = qcar(v_12818);
    v_12818 = qcdr(v_12818);
    goto v_12770;
v_12771:
    goto v_12767;
v_12768:
    goto v_12769;
v_12770:
    fn = elt(env, 1); // exptsq
    v_12818 = (*qfn2(fn))(fn, v_12819, v_12818);
    env = stack[-4];
    goto v_12754;
v_12755:
    goto v_12751;
v_12752:
    goto v_12753;
v_12754:
    fn = elt(env, 2); // multsq
    v_12819 = (*qfn2(fn))(fn, stack[-1], v_12818);
    env = stack[-4];
    goto v_12746;
v_12747:
    v_12818 = stack[-3];
    goto v_12748;
v_12749:
    goto v_12745;
v_12746:
    goto v_12747;
v_12748:
    {
        fn = elt(env, 3); // addsq
        return (*qfn2(fn))(fn, v_12819, v_12818);
    }
v_12733:
    goto v_12783;
v_12779:
    goto v_12789;
v_12785:
    goto v_12797;
v_12791:
    v_12818 = stack[-2];
    v_12818 = qcar(v_12818);
    v_12820 = qcdr(v_12818);
    goto v_12792;
v_12793:
    v_12819 = stack[-1];
    goto v_12794;
v_12795:
    v_12818 = stack[0];
    goto v_12796;
v_12797:
    goto v_12791;
v_12792:
    goto v_12793;
v_12794:
    goto v_12795;
v_12796:
    stack[0] = CC_ofsf_subf(elt(env, 0), 3, v_12820, v_12819, v_12818);
    env = stack[-4];
    goto v_12786;
v_12787:
    goto v_12808;
v_12804:
    v_12818 = stack[-2];
    v_12818 = qcar(v_12818);
    v_12818 = qcar(v_12818);
    v_12819 = qcar(v_12818);
    goto v_12805;
v_12806:
    v_12818 = stack[-2];
    v_12818 = qcar(v_12818);
    v_12818 = qcar(v_12818);
    v_12818 = qcdr(v_12818);
    goto v_12807;
v_12808:
    goto v_12804;
v_12805:
    goto v_12806;
v_12807:
    fn = elt(env, 4); // ofsf_pow2q
    v_12818 = (*qfn2(fn))(fn, v_12819, v_12818);
    env = stack[-4];
    goto v_12788;
v_12789:
    goto v_12785;
v_12786:
    goto v_12787;
v_12788:
    fn = elt(env, 2); // multsq
    v_12819 = (*qfn2(fn))(fn, stack[0], v_12818);
    env = stack[-4];
    goto v_12780;
v_12781:
    v_12818 = stack[-3];
    goto v_12782;
v_12783:
    goto v_12779;
v_12780:
    goto v_12781;
v_12782:
    {
        fn = elt(env, 3); // addsq
        return (*qfn2(fn))(fn, v_12819, v_12818);
    }
    return onevalue(v_12818);
}



// Code for simpexpt

static LispObject CC_simpexpt(LispObject env,
                         LispObject v_12688)
{
    env = qenv(env);
    LispObject v_12725, v_12726, v_12727;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12688);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12688);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12688;
// end of prologue
    v_12725 = nil;
// Binding kord!*
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 1, -1);
    qvalue(elt(env, 1)) = v_12725; // kord!*
    goto v_12701;
v_12697:
    v_12725 = stack[0];
    v_12726 = qcdr(v_12725);
    goto v_12698;
v_12699:
    v_12725 = elt(env, 2); // expt
    goto v_12700;
v_12701:
    goto v_12697;
v_12698:
    goto v_12699;
v_12700:
    fn = elt(env, 4); // carx
    v_12725 = (*qfn2(fn))(fn, v_12726, v_12725);
    env = stack[-2];
    fn = elt(env, 5); // simpexpon
    v_12725 = (*qfn1(fn))(fn, v_12725);
    env = stack[-2];
    ;}  // end of a binding scope
    goto v_12710;
v_12706:
    v_12726 = v_12725;
    goto v_12707;
v_12708:
    v_12725 = elt(env, 3); // resimp
    goto v_12709;
v_12710:
    goto v_12706;
v_12707:
    goto v_12708;
v_12709:
    fn = elt(env, 6); // simpexpon1
    v_12725 = (*qfn2(fn))(fn, v_12726, v_12725);
    env = stack[-2];
    goto v_12720;
v_12714:
    v_12726 = stack[0];
    v_12727 = qcar(v_12726);
    goto v_12715;
v_12716:
    v_12726 = v_12725;
    goto v_12717;
v_12718:
    v_12725 = nil;
    goto v_12719;
v_12720:
    goto v_12714;
v_12715:
    goto v_12716;
v_12717:
    goto v_12718;
v_12719:
    {
        fn = elt(env, 7); // simpexpt1
        return (*qfnn(fn))(fn, 3, v_12727, v_12726, v_12725);
    }
    return onevalue(v_12725);
}



setup_type const u22_setup[] =
{
    {"exc",                     TOO_FEW_2,      CC_exc,        WRONG_NO_2},
    {"yypeek",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_yypeek},
    {"defineargs",              TOO_FEW_2,      CC_defineargs, WRONG_NO_2},
    {"mk+unit+mat",             CC_mkLunitLmat, TOO_MANY_1,    WRONG_NO_1},
    {"cl_flip",                 CC_cl_flip,     TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_negateat",          CC_ibalp_negateat,TOO_MANY_1,  WRONG_NO_1},
    {"aex_deg",                 TOO_FEW_2,      CC_aex_deg,    WRONG_NO_2},
    {"simprecip",               CC_simprecip,   TOO_MANY_1,    WRONG_NO_1},
    {"coordp",                  CC_coordp,      TOO_MANY_1,    WRONG_NO_1},
    {"begin11",                 CC_begin11,     TOO_MANY_1,    WRONG_NO_1},
    {"lienjactest",             CC_lienjactest, TOO_MANY_1,    WRONG_NO_1},
    {"mv-pow-mv-+",             TOO_FEW_2,      CC_mvKpowKmvKL,WRONG_NO_2},
    {"ilcm",                    TOO_FEW_2,      CC_ilcm,       WRONG_NO_2},
    {"symbvarlst",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_symbvarlst},
    {"ezgcdf1",                 TOO_FEW_2,      CC_ezgcdf1,    WRONG_NO_2},
    {"talp_eqnrhskernels",      CC_talp_eqnrhskernels,TOO_MANY_1,WRONG_NO_1},
    {"qqe_arg-check",           CC_qqe_argKcheck,TOO_MANY_1,   WRONG_NO_1},
    {"delet",                   TOO_FEW_2,      CC_delet,      WRONG_NO_2},
    {"cl_qb",                   CC_cl_qb,       TOO_MANY_1,    WRONG_NO_1},
    {"horner-rule-mod-p",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_hornerKruleKmodKp},
    {"getsetvars",              CC_getsetvars,  TOO_MANY_1,    WRONG_NO_1},
    {"mchkopt1",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mchkopt1},
    {"ps:evaluate",             TOO_FEW_2,      CC_psTevaluate,WRONG_NO_2},
    {"reform-minus",            TOO_FEW_2,      CC_reformKminus,WRONG_NO_2},
    {"setmat",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setmat},
    {"freeoffl",                TOO_FEW_2,      CC_freeoffl,   WRONG_NO_2},
    {"fortexp",                 CC_fortexp,     TOO_MANY_1,    WRONG_NO_1},
    {"indordp",                 TOO_FEW_2,      CC_indordp,    WRONG_NO_2},
    {"lpriw",                   TOO_FEW_2,      CC_lpriw,      WRONG_NO_2},
    {"mv-domainlist-+",         TOO_FEW_2,      CC_mvKdomainlistKL,WRONG_NO_2},
    {"mo_lcm",                  TOO_FEW_2,      CC_mo_lcm,     WRONG_NO_2},
    {"arglist_member",          TOO_FEW_2,      CC_arglist_member,WRONG_NO_2},
    {"drop_rl_with",            TOO_FEW_2,      CC_drop_rl_with,WRONG_NO_2},
    {"remlocs",                 CC_remlocs,     TOO_MANY_1,    WRONG_NO_1},
    {"setqget",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setqget},
    {"ofsf_surep",              TOO_FEW_2,      CC_ofsf_surep, WRONG_NO_2},
    {"ibalp_negatet",           CC_ibalp_negatet,TOO_MANY_1,   WRONG_NO_1},
    {"sfto_dprpartksf",         CC_sfto_dprpartksf,TOO_MANY_1, WRONG_NO_1},
    {"reln",                    TOO_FEW_2,      CC_reln,       WRONG_NO_2},
    {"diffsq",                  TOO_FEW_2,      CC_diffsq,     WRONG_NO_2},
    {"xdegreecheck",            CC_xdegreecheck,TOO_MANY_1,    WRONG_NO_1},
    {"physopsm*",               CC_physopsmH,   TOO_MANY_1,    WRONG_NO_1},
    {"prepd1",                  CC_prepd1,      TOO_MANY_1,    WRONG_NO_1},
    {"ad_numsort",              CC_ad_numsort,  TOO_MANY_1,    WRONG_NO_1},
    {"lambda_ygm6np4pcqv31",    TOO_FEW_2,      CC_lambda_ygm6np4pcqv31,WRONG_NO_2},
    {"rlis",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rlis},
    {"ibalp_isinminclause",     TOO_FEW_2,      CC_ibalp_isinminclause,WRONG_NO_2},
    {"**a2s",                   TOO_FEW_2,      CC_HHa2s,      WRONG_NO_2},
    {"ps:prepfn:",              CC_psTprepfnT,  TOO_MANY_1,    WRONG_NO_1},
    {"dm-minus",                CC_dmKminus,    TOO_MANY_1,    WRONG_NO_1},
    {"groebcplistsortin1",      TOO_FEW_2,      CC_groebcplistsortin1,WRONG_NO_2},
    {"bytelist2id",             CC_bytelist2id, TOO_MANY_1,    WRONG_NO_1},
    {"gfdot",                   TOO_FEW_2,      CC_gfdot,      WRONG_NO_2},
    {"rdcos*",                  CC_rdcosH,      TOO_MANY_1,    WRONG_NO_1},
    {"mkfortterpri",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mkfortterpri},
    {"trwrite",                 CC_trwrite,     TOO_MANY_1,    WRONG_NO_1},
    {"one-entry-listp",         TOO_FEW_2,      CC_oneKentryKlistp,WRONG_NO_2},
    {"fs:times",                TOO_FEW_2,      CC_fsTtimes,   WRONG_NO_2},
    {"moid_member",             TOO_FEW_2,      CC_moid_member,WRONG_NO_2},
    {"splitlist:",              TOO_FEW_2,      CC_splitlistT, WRONG_NO_2},
    {"resimpf",                 CC_resimpf,     TOO_MANY_1,    WRONG_NO_1},
    {"gfk",                     WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gfk},
    {"gcref_mkgraph-tgf",       CC_gcref_mkgraphKtgf,TOO_MANY_1,WRONG_NO_1},
    {"rl_atnum",                CC_rl_atnum,    TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_subf",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_subf},
    {"simpexpt",                CC_simpexpt,    TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u22", (two_args *)"119821 7550241 9798415", 0}
};

// end of generated code
