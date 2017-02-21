
// $destdir/u35.c        Machine generated C code

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



// Code for matsm1

static LispObject CC_matsm1(LispObject env,
                         LispObject v_19381)
{
    env = qenv(env);
    LispObject v_20238, v_20239, v_20240;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19381);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_19381;
// end of prologue
    stack[-9] = nil;
v_19390:
    v_20238 = stack[-8];
    if (v_20238 == nil) goto v_19401;
    else goto v_19402;
v_19401:
    v_20238 = stack[-9];
    goto v_19389;
v_19402:
    goto v_19412;
v_19408:
    v_20238 = stack[-8];
    v_20239 = qcar(v_20238);
    goto v_19409;
v_19410:
    v_20238 = elt(env, 1); // !*div
    goto v_19411;
v_19412:
    goto v_19408;
v_19409:
    goto v_19410;
v_19411:
    if (!consp(v_20239)) goto v_19406;
    v_20239 = qcar(v_20239);
    if (v_20239 == v_20238) goto v_19405;
    else goto v_19406;
v_19405:
    goto v_19424;
v_19420:
    v_20238 = stack[-8];
    v_20239 = Llength(nil, v_20238);
    env = stack[-10];
    goto v_19421;
v_19422:
    v_20238 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19423;
v_19424:
    goto v_19420;
v_19421:
    goto v_19422;
v_19423:
    if (v_20239 == v_20238) goto v_19418;
    else goto v_19419;
v_19418:
    goto v_19394;
v_19419:
    goto v_19438;
v_19434:
    v_20238 = stack[-8];
    v_20239 = Llength(nil, v_20238);
    env = stack[-10];
    goto v_19435;
v_19436:
    v_20238 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_19437;
v_19438:
    goto v_19434;
v_19435:
    goto v_19436;
v_19437:
    if (v_20239 == v_20238) goto v_19432;
    else goto v_19433;
v_19432:
    goto v_19446;
v_19442:
    v_20238 = stack[-8];
    v_20238 = qcdr(v_20238);
    v_20238 = qcar(v_20238);
    v_20239 = qcar(v_20238);
    goto v_19443;
v_19444:
    v_20238 = elt(env, 2); // sparsemat
    goto v_19445;
v_19446:
    goto v_19442;
v_19443:
    goto v_19444;
v_19445:
    v_20238 = (v_20239 == v_20238 ? lisp_true : nil);
    goto v_19431;
v_19433:
    v_20238 = nil;
    goto v_19431;
    v_20238 = nil;
v_19431:
    if (v_20238 == nil) goto v_19429;
    v_20238 = stack[-8];
    v_20238 = qcdr(v_20238);
    stack[-9] = v_20238;
    goto v_19394;
v_19429:
    goto v_19394;
    goto v_19400;
v_19406:
    v_20238 = stack[-8];
    v_20238 = qcar(v_20238);
    if (!consp(v_20238)) goto v_19461;
    else goto v_19462;
v_19461:
    goto v_19397;
v_19462:
    goto v_19471;
v_19467:
    v_20238 = stack[-8];
    v_20238 = qcar(v_20238);
    v_20239 = qcar(v_20238);
    goto v_19468;
v_19469:
    v_20238 = elt(env, 3); // mat
    goto v_19470;
v_19471:
    goto v_19467;
v_19468:
    goto v_19469;
v_19470:
    if (v_20239 == v_20238) goto v_19465;
    else goto v_19466;
v_19465:
    goto v_19393;
v_19466:
    goto v_19486;
v_19482:
    v_20238 = stack[-8];
    v_20238 = qcar(v_20238);
    v_20239 = qcar(v_20238);
    goto v_19483;
v_19484:
    v_20238 = elt(env, 2); // sparsemat
    goto v_19485;
v_19486:
    goto v_19482;
v_19483:
    goto v_19484;
v_19485:
    if (v_20239 == v_20238) goto v_19480;
    else goto v_19481;
v_19480:
    goto v_19495;
v_19491:
    v_20238 = stack[-8];
    v_20239 = Llength(nil, v_20238);
    env = stack[-10];
    goto v_19492;
v_19493:
    v_20238 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19494;
v_19495:
    goto v_19491;
v_19492:
    goto v_19493;
v_19494:
    v_20238 = (v_20239 == v_20238 ? lisp_true : nil);
    goto v_19479;
v_19481:
    v_20238 = nil;
    goto v_19479;
    v_20238 = nil;
v_19479:
    if (v_20238 == nil) goto v_19477;
    v_20238 = stack[-8];
    stack[-9] = v_20238;
    goto v_19392;
v_19477:
    goto v_19514;
v_19510:
    v_20238 = stack[-8];
    v_20238 = qcar(v_20238);
    v_20239 = qcar(v_20238);
    goto v_19511;
v_19512:
    v_20238 = elt(env, 2); // sparsemat
    goto v_19513;
v_19514:
    goto v_19510;
v_19511:
    goto v_19512;
v_19513:
    if (v_20239 == v_20238) goto v_19508;
    else goto v_19509;
v_19508:
    goto v_19523;
v_19519:
    v_20238 = stack[-8];
    v_20239 = Llength(nil, v_20238);
    env = stack[-10];
    goto v_19520;
v_19521:
    v_20238 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_19522;
v_19523:
    goto v_19519;
v_19520:
    goto v_19521;
v_19522:
    v_20238 = (v_20239 == v_20238 ? lisp_true : nil);
    goto v_19507;
v_19509:
    v_20238 = nil;
    goto v_19507;
    v_20238 = nil;
v_19507:
    if (v_20238 == nil) goto v_19505;
    goto v_19540;
v_19536:
    v_20238 = stack[-8];
    v_20238 = Lreverse(nil, v_20238);
    env = stack[-10];
    v_20239 = qcar(v_20238);
    goto v_19537;
v_19538:
    v_20238 = elt(env, 1); // !*div
    goto v_19539;
v_19540:
    goto v_19536;
v_19537:
    goto v_19538;
v_19539:
    if (!consp(v_20239)) goto v_19534;
    v_20239 = qcar(v_20239);
    if (v_20239 == v_20238) goto v_19533;
    else goto v_19534;
v_19533:
    v_20238 = stack[-8];
    v_20238 = Lreverse(nil, v_20238);
    env = stack[-10];
    stack[-8] = v_20238;
    v_20238 = stack[-8];
    v_20238 = qcdr(v_20238);
    stack[-9] = v_20238;
    goto v_19394;
v_19534:
    goto v_19556;
v_19552:
    v_20238 = stack[-8];
    v_20239 = qcar(v_20238);
    goto v_19553;
v_19554:
    v_20238 = stack[-8];
    v_20238 = qcdr(v_20238);
    goto v_19555;
v_19556:
    goto v_19552;
v_19553:
    goto v_19554;
v_19555:
    fn = elt(env, 15); // spmultm
    v_20238 = (*qfn2(fn))(fn, v_20239, v_20238);
    env = stack[-10];
    stack[-9] = v_20238;
    v_20238 = stack[-8];
    v_20238 = qcdr(v_20238);
    stack[-8] = v_20238;
    goto v_19392;
    goto v_19400;
v_19505:
    goto v_19570;
v_19566:
    v_20238 = stack[-8];
    v_20238 = qcar(v_20238);
    v_20239 = qcar(v_20238);
    goto v_19567;
v_19568:
    v_20238 = elt(env, 2); // sparsemat
    goto v_19569;
v_19570:
    goto v_19566;
v_19567:
    goto v_19568;
v_19569:
    if (v_20239 == v_20238) goto v_19564;
    else goto v_19565;
v_19564:
    goto v_19580;
v_19576:
    v_20238 = stack[-8];
    v_20239 = qcar(v_20238);
    goto v_19577;
v_19578:
    v_20238 = stack[-8];
    v_20238 = qcdr(v_20238);
    goto v_19579;
v_19580:
    goto v_19576;
v_19577:
    goto v_19578;
v_19579:
    fn = elt(env, 15); // spmultm
    v_20238 = (*qfn2(fn))(fn, v_20239, v_20238);
    env = stack[-10];
    stack[-9] = v_20238;
    v_20238 = nil;
    v_20238 = ncons(v_20238);
    env = stack[-10];
    stack[-8] = v_20238;
    goto v_19392;
v_19565:
    goto v_19594;
v_19590:
    v_20238 = stack[-8];
    v_20238 = qcar(v_20238);
    v_20239 = qcar(v_20238);
    goto v_19591;
v_19592:
    v_20238 = stack[-8];
    v_20238 = qcar(v_20238);
    v_20238 = qcdr(v_20238);
    goto v_19593;
v_19594:
    goto v_19590;
v_19591:
    goto v_19592;
v_19593:
    fn = elt(env, 16); // lispapply
    v_20238 = (*qfn2(fn))(fn, v_20239, v_20238);
    env = stack[-10];
    stack[0] = v_20238;
    goto v_19400;
v_19400:
v_19391:
    v_20238 = stack[-9];
    if (v_20238 == nil) goto v_19603;
    else goto v_19604;
v_19603:
    v_20238 = stack[0];
    goto v_19602;
v_19604:
    v_20238 = stack[-9];
    v_20238 = qcdr(v_20238);
    if (v_20238 == nil) goto v_19611;
    else goto v_19612;
v_19611:
    v_20238 = stack[-9];
    v_20238 = qcar(v_20238);
    v_20238 = qcdr(v_20238);
    v_20238 = (v_20238 == nil ? lisp_true : nil);
    goto v_19610;
v_19612:
    v_20238 = nil;
    goto v_19610;
    v_20238 = nil;
v_19610:
    if (v_20238 == nil) goto v_19608;
    goto v_19627;
v_19623:
    v_20238 = stack[-9];
    v_20238 = qcar(v_20238);
    v_20239 = qcar(v_20238);
    goto v_19624;
v_19625:
    v_20238 = stack[0];
    goto v_19626;
v_19627:
    goto v_19623;
v_19624:
    goto v_19625;
v_19626:
    fn = elt(env, 17); // multsm
    v_20238 = (*qfn2(fn))(fn, v_20239, v_20238);
    env = stack[-10];
    goto v_19602;
v_19608:
    goto v_19639;
v_19635:
    v_20239 = stack[0];
    goto v_19636;
v_19637:
    v_20238 = stack[-9];
    goto v_19638;
v_19639:
    goto v_19635;
v_19636:
    goto v_19637;
v_19638:
    fn = elt(env, 18); // multm
    v_20238 = (*qfn2(fn))(fn, v_20239, v_20238);
    env = stack[-10];
    goto v_19602;
    v_20238 = nil;
v_19602:
    stack[-9] = v_20238;
v_19392:
    v_20238 = stack[-8];
    v_20238 = qcdr(v_20238);
    stack[-8] = v_20238;
    goto v_19390;
v_19393:
    v_20238 = stack[-8];
    v_20238 = qcar(v_20238);
    v_20238 = qcdr(v_20238);
    fn = elt(env, 19); // lchk
    v_20238 = (*qfn1(fn))(fn, v_20238);
    env = stack[-10];
    if (v_20238 == nil) goto v_19646;
    else goto v_19647;
v_19646:
    goto v_19659;
v_19653:
    v_20240 = elt(env, 4); // matrix
    goto v_19654;
v_19655:
    v_20239 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_19656;
v_19657:
    v_20238 = elt(env, 5); // "Matrix mismatch"
    goto v_19658;
v_19659:
    goto v_19653;
v_19654:
    goto v_19655;
v_19656:
    goto v_19657;
v_19658:
    fn = elt(env, 20); // rerror
    v_20238 = (*qfnn(fn))(fn, 3, v_20240, v_20239, v_20238);
    env = stack[-10];
    goto v_19645;
v_19647:
v_19645:
    v_20238 = stack[-8];
    v_20238 = qcar(v_20238);
    v_20238 = qcdr(v_20238);
    stack[-7] = v_20238;
    v_20238 = stack[-7];
    if (v_20238 == nil) goto v_19674;
    else goto v_19675;
v_19674:
    v_20238 = nil;
    goto v_19667;
v_19675:
    v_20238 = stack[-7];
    v_20238 = qcar(v_20238);
    stack[-3] = v_20238;
    v_20238 = stack[-3];
    if (v_20238 == nil) goto v_19691;
    else goto v_19692;
v_19691:
    v_20238 = nil;
    goto v_19686;
v_19692:
    v_20238 = stack[-3];
    v_20238 = qcar(v_20238);
    fn = elt(env, 21); // xsimp
    v_20238 = (*qfn1(fn))(fn, v_20238);
    env = stack[-10];
    v_20238 = ncons(v_20238);
    env = stack[-10];
    stack[-1] = v_20238;
    stack[-2] = v_20238;
v_19687:
    v_20238 = stack[-3];
    v_20238 = qcdr(v_20238);
    stack[-3] = v_20238;
    v_20238 = stack[-3];
    if (v_20238 == nil) goto v_19705;
    else goto v_19706;
v_19705:
    v_20238 = stack[-2];
    goto v_19686;
v_19706:
    goto v_19714;
v_19710:
    stack[0] = stack[-1];
    goto v_19711;
v_19712:
    v_20238 = stack[-3];
    v_20238 = qcar(v_20238);
    fn = elt(env, 21); // xsimp
    v_20238 = (*qfn1(fn))(fn, v_20238);
    env = stack[-10];
    v_20238 = ncons(v_20238);
    env = stack[-10];
    goto v_19713;
v_19714:
    goto v_19710;
v_19711:
    goto v_19712;
v_19713:
    v_20238 = Lrplacd(nil, stack[0], v_20238);
    env = stack[-10];
    v_20238 = stack[-1];
    v_20238 = qcdr(v_20238);
    stack[-1] = v_20238;
    goto v_19687;
v_19686:
    v_20238 = ncons(v_20238);
    env = stack[-10];
    stack[-5] = v_20238;
    stack[-6] = v_20238;
v_19668:
    v_20238 = stack[-7];
    v_20238 = qcdr(v_20238);
    stack[-7] = v_20238;
    v_20238 = stack[-7];
    if (v_20238 == nil) goto v_19728;
    else goto v_19729;
v_19728:
    v_20238 = stack[-6];
    goto v_19667;
v_19729:
    goto v_19737;
v_19733:
    stack[-4] = stack[-5];
    goto v_19734;
v_19735:
    v_20238 = stack[-7];
    v_20238 = qcar(v_20238);
    stack[-3] = v_20238;
    v_20238 = stack[-3];
    if (v_20238 == nil) goto v_19752;
    else goto v_19753;
v_19752:
    v_20238 = nil;
    goto v_19747;
v_19753:
    v_20238 = stack[-3];
    v_20238 = qcar(v_20238);
    fn = elt(env, 21); // xsimp
    v_20238 = (*qfn1(fn))(fn, v_20238);
    env = stack[-10];
    v_20238 = ncons(v_20238);
    env = stack[-10];
    stack[-1] = v_20238;
    stack[-2] = v_20238;
v_19748:
    v_20238 = stack[-3];
    v_20238 = qcdr(v_20238);
    stack[-3] = v_20238;
    v_20238 = stack[-3];
    if (v_20238 == nil) goto v_19766;
    else goto v_19767;
v_19766:
    v_20238 = stack[-2];
    goto v_19747;
v_19767:
    goto v_19775;
v_19771:
    stack[0] = stack[-1];
    goto v_19772;
v_19773:
    v_20238 = stack[-3];
    v_20238 = qcar(v_20238);
    fn = elt(env, 21); // xsimp
    v_20238 = (*qfn1(fn))(fn, v_20238);
    env = stack[-10];
    v_20238 = ncons(v_20238);
    env = stack[-10];
    goto v_19774;
v_19775:
    goto v_19771;
v_19772:
    goto v_19773;
v_19774:
    v_20238 = Lrplacd(nil, stack[0], v_20238);
    env = stack[-10];
    v_20238 = stack[-1];
    v_20238 = qcdr(v_20238);
    stack[-1] = v_20238;
    goto v_19748;
v_19747:
    v_20238 = ncons(v_20238);
    env = stack[-10];
    goto v_19736;
v_19737:
    goto v_19733;
v_19734:
    goto v_19735;
v_19736:
    v_20238 = Lrplacd(nil, stack[-4], v_20238);
    env = stack[-10];
    v_20238 = stack[-5];
    v_20238 = qcdr(v_20238);
    stack[-5] = v_20238;
    goto v_19668;
v_19667:
    stack[0] = v_20238;
    goto v_19391;
v_19394:
    goto v_19795;
v_19791:
    v_20238 = stack[-8];
    v_20238 = qcar(v_20238);
    v_20238 = qcdr(v_20238);
    v_20238 = qcar(v_20238);
    fn = elt(env, 22); // checksp
    v_20239 = (*qfn1(fn))(fn, v_20238);
    env = stack[-10];
    goto v_19792;
v_19793:
    v_20238 = elt(env, 6); // sparse
    goto v_19794;
v_19795:
    goto v_19791;
v_19792:
    goto v_19793;
v_19794:
    if (v_20239 == v_20238) goto v_19789;
    else goto v_19790;
v_19789:
    v_20238 = stack[-8];
    v_20238 = qcar(v_20238);
    v_20238 = qcdr(v_20238);
    v_20238 = qcar(v_20238);
    fn = elt(env, 23); // spmatsm
    v_20238 = (*qfn1(fn))(fn, v_20238);
    env = stack[-10];
    stack[-2] = v_20238;
    v_20238 = stack[-2];
    v_20238 = Lreverse(nil, v_20238);
    env = stack[-10];
    v_20238 = qcar(v_20238);
    v_20238 = qcdr(v_20238);
    goto v_19819;
v_19815:
    v_20239 = v_20238;
    v_20239 = qcar(v_20239);
    goto v_19816;
v_19817:
    v_20238 = qcdr(v_20238);
    v_20238 = qcar(v_20238);
    goto v_19818;
v_19819:
    goto v_19815;
v_19816:
    goto v_19817;
v_19818:
    if (equal(v_20239, v_20238)) goto v_19814;
    goto v_19832;
v_19826:
    v_20240 = elt(env, 4); // matrix
    goto v_19827;
v_19828:
    v_20239 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_19829;
v_19830:
    v_20238 = elt(env, 7); // "Non square matrix"
    goto v_19831;
v_19832:
    goto v_19826;
v_19827:
    goto v_19828;
v_19829:
    goto v_19830;
v_19831:
    fn = elt(env, 20); // rerror
    v_20238 = (*qfnn(fn))(fn, 3, v_20240, v_20239, v_20238);
    env = stack[-10];
    goto v_19812;
v_19814:
v_19812:
    goto v_19788;
v_19790:
    v_20238 = stack[-8];
    v_20238 = qcar(v_20238);
    v_20238 = qcdr(v_20238);
    v_20238 = qcar(v_20238);
    fn = elt(env, 24); // matsm
    v_20238 = (*qfn1(fn))(fn, v_20238);
    env = stack[-10];
    stack[-2] = v_20238;
    goto v_19851;
v_19847:
    v_20238 = stack[-2];
    v_20238 = qcar(v_20238);
    stack[0] = Llength(nil, v_20238);
    env = stack[-10];
    stack[-1] = stack[0];
    goto v_19848;
v_19849:
    v_20238 = stack[-2];
    v_20238 = Llength(nil, v_20238);
    env = stack[-10];
    goto v_19850;
v_19851:
    goto v_19847;
v_19848:
    goto v_19849;
v_19850:
    if (equal(stack[0], v_20238)) goto v_19846;
    goto v_19864;
v_19858:
    v_20240 = elt(env, 4); // matrix
    goto v_19859;
v_19860:
    v_20239 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_19861;
v_19862:
    v_20238 = elt(env, 7); // "Non square matrix"
    goto v_19863;
v_19864:
    goto v_19858;
v_19859:
    goto v_19860;
v_19861:
    goto v_19862;
v_19863:
    fn = elt(env, 20); // rerror
    v_20238 = (*qfnn(fn))(fn, 3, v_20240, v_20239, v_20238);
    env = stack[-10];
    goto v_19844;
v_19846:
    v_20238 = stack[-9];
    if (v_20238 == nil) goto v_19869;
    goto v_19877;
v_19873:
    stack[0] = stack[-1];
    goto v_19874;
v_19875:
    v_20238 = stack[-9];
    v_20238 = Llength(nil, v_20238);
    env = stack[-10];
    goto v_19876;
v_19877:
    goto v_19873;
v_19874:
    goto v_19875;
v_19876:
    if (equal(stack[0], v_20238)) goto v_19869;
    goto v_19888;
v_19882:
    v_20240 = elt(env, 4); // matrix
    goto v_19883;
v_19884:
    v_20239 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_19885;
v_19886:
    v_20238 = elt(env, 5); // "Matrix mismatch"
    goto v_19887;
v_19888:
    goto v_19882;
v_19883:
    goto v_19884;
v_19885:
    goto v_19886;
v_19887:
    fn = elt(env, 20); // rerror
    v_20238 = (*qfnn(fn))(fn, 3, v_20240, v_20239, v_20238);
    env = stack[-10];
    goto v_19844;
v_19869:
    v_20238 = stack[-8];
    v_20238 = qcar(v_20238);
    v_20238 = qcdr(v_20238);
    v_20238 = qcdr(v_20238);
    if (v_20238 == nil) goto v_19893;
    goto v_19396;
v_19893:
    v_20238 = stack[-2];
    v_20238 = qcdr(v_20238);
    if (v_20238 == nil) goto v_19902;
    else goto v_19903;
v_19902:
    v_20238 = stack[-2];
    v_20238 = qcar(v_20238);
    v_20238 = qcdr(v_20238);
    v_20238 = (v_20238 == nil ? lisp_true : nil);
    goto v_19901;
v_19903:
    v_20238 = nil;
    goto v_19901;
    v_20238 = nil;
v_19901:
    if (v_20238 == nil) goto v_19899;
    goto v_19395;
v_19899:
v_19844:
    goto v_19788;
v_19788:
    v_20238 = qvalue(elt(env, 8)); // subfg!*
    stack[0] = v_20238;
    v_20238 = nil;
    qvalue(elt(env, 8)) = v_20238; // subfg!*
    v_20238 = stack[-9];
    if (v_20238 == nil) goto v_19917;
    else goto v_19918;
v_19917:
    goto v_19925;
v_19921:
    goto v_19931;
v_19927:
    v_20239 = elt(env, 3); // mat
    goto v_19928;
v_19929:
    v_20238 = elt(env, 9); // inversefn
    goto v_19930;
v_19931:
    goto v_19927;
v_19928:
    goto v_19929;
v_19930:
    v_20239 = get(v_20239, v_20238);
    env = stack[-10];
    goto v_19922;
v_19923:
    v_20238 = stack[-2];
    goto v_19924;
v_19925:
    goto v_19921;
v_19922:
    goto v_19923;
v_19924:
    v_20238 = Lapply1(nil, v_20239, v_20238);
    env = stack[-10];
    stack[-9] = v_20238;
    goto v_19916;
v_19918:
    goto v_19941;
v_19937:
    v_20238 = stack[-9];
    v_20238 = qcar(v_20238);
    v_20239 = qcar(v_20238);
    goto v_19938;
v_19939:
    v_20238 = elt(env, 2); // sparsemat
    goto v_19940;
v_19941:
    goto v_19937;
v_19938:
    goto v_19939;
v_19940:
    if (v_20239 == v_20238) goto v_19935;
    else goto v_19936;
v_19935:
    goto v_19952;
v_19948:
    goto v_19958;
v_19954:
    goto v_19964;
v_19960:
    v_20239 = elt(env, 3); // mat
    goto v_19961;
v_19962:
    v_20238 = elt(env, 9); // inversefn
    goto v_19963;
v_19964:
    goto v_19960;
v_19961:
    goto v_19962;
v_19963:
    v_20239 = get(v_20239, v_20238);
    env = stack[-10];
    goto v_19955;
v_19956:
    v_20238 = stack[-2];
    goto v_19957;
v_19958:
    goto v_19954;
v_19955:
    goto v_19956;
v_19957:
    v_20238 = Lapply1(nil, v_20239, v_20238);
    env = stack[-10];
    v_20239 = qcar(v_20238);
    goto v_19949;
v_19950:
    v_20238 = stack[-9];
    goto v_19951;
v_19952:
    goto v_19948;
v_19949:
    goto v_19950;
v_19951:
    fn = elt(env, 15); // spmultm
    v_20238 = (*qfn2(fn))(fn, v_20239, v_20238);
    env = stack[-10];
    v_20238 = ncons(v_20238);
    env = stack[-10];
    stack[-9] = v_20238;
    v_20238 = stack[-8];
    v_20238 = qcdr(v_20238);
    stack[-8] = v_20238;
    goto v_19916;
v_19936:
    goto v_19980;
v_19976:
    v_20239 = elt(env, 3); // mat
    goto v_19977;
v_19978:
    v_20238 = elt(env, 10); // lnrsolvefn
    goto v_19979;
v_19980:
    goto v_19976;
v_19977:
    goto v_19978;
v_19979:
    v_20238 = get(v_20239, v_20238);
    env = stack[-10];
    stack[0] = v_20238;
    if (v_20238 == nil) goto v_19973;
    else goto v_19974;
v_19973:
    goto v_19988;
v_19984:
    goto v_19994;
v_19990:
    goto v_20000;
v_19996:
    v_20239 = elt(env, 3); // mat
    goto v_19997;
v_19998:
    v_20238 = elt(env, 9); // inversefn
    goto v_19999;
v_20000:
    goto v_19996;
v_19997:
    goto v_19998;
v_19999:
    v_20239 = get(v_20239, v_20238);
    env = stack[-10];
    goto v_19991;
v_19992:
    v_20238 = stack[-2];
    goto v_19993;
v_19994:
    goto v_19990;
v_19991:
    goto v_19992;
v_19993:
    v_20239 = Lapply1(nil, v_20239, v_20238);
    env = stack[-10];
    goto v_19985;
v_19986:
    v_20238 = stack[-9];
    goto v_19987;
v_19988:
    goto v_19984;
v_19985:
    goto v_19986;
v_19987:
    fn = elt(env, 18); // multm
    v_20238 = (*qfn2(fn))(fn, v_20239, v_20238);
    env = stack[-10];
    stack[-9] = v_20238;
    goto v_19916;
v_19974:
    goto v_20014;
v_20008:
    goto v_20020;
v_20016:
    v_20239 = elt(env, 3); // mat
    goto v_20017;
v_20018:
    v_20238 = elt(env, 10); // lnrsolvefn
    goto v_20019;
v_20020:
    goto v_20016;
v_20017:
    goto v_20018;
v_20019:
    v_20240 = get(v_20239, v_20238);
    env = stack[-10];
    goto v_20009;
v_20010:
    v_20239 = stack[-2];
    goto v_20011;
v_20012:
    v_20238 = stack[-9];
    goto v_20013;
v_20014:
    goto v_20008;
v_20009:
    goto v_20010;
v_20011:
    goto v_20012;
v_20013:
    v_20238 = Lapply2(nil, 3, v_20240, v_20239, v_20238);
    env = stack[-10];
    stack[-9] = v_20238;
    goto v_19916;
v_19916:
    v_20238 = stack[0];
    qvalue(elt(env, 8)) = v_20238; // subfg!*
    goto v_20034;
v_20030:
    v_20238 = stack[-9];
    v_20238 = qcar(v_20238);
    v_20239 = qcar(v_20238);
    goto v_20031;
v_20032:
    v_20238 = elt(env, 2); // sparsemat
    goto v_20033;
v_20034:
    goto v_20030;
v_20031:
    goto v_20032;
v_20033:
    if (v_20239 == v_20238) goto v_20028;
    else goto v_20029;
v_20028:
    v_20238 = stack[-9];
    stack[-9] = v_20238;
    goto v_20027;
v_20029:
    v_20238 = stack[-9];
    stack[-7] = v_20238;
    v_20238 = stack[-7];
    if (v_20238 == nil) goto v_20051;
    else goto v_20052;
v_20051:
    v_20238 = nil;
    goto v_20046;
v_20052:
    v_20238 = stack[-7];
    v_20238 = qcar(v_20238);
    stack[-3] = v_20238;
    v_20238 = stack[-3];
    if (v_20238 == nil) goto v_20068;
    else goto v_20069;
v_20068:
    v_20238 = nil;
    goto v_20063;
v_20069:
    v_20238 = stack[-3];
    v_20238 = qcar(v_20238);
    v_20239 = v_20238;
    v_20238 = lisp_true;
    qvalue(elt(env, 11)) = v_20238; // !*sub2
    v_20238 = v_20239;
    fn = elt(env, 25); // subs2
    v_20238 = (*qfn1(fn))(fn, v_20238);
    env = stack[-10];
    v_20238 = ncons(v_20238);
    env = stack[-10];
    stack[-1] = v_20238;
    stack[-2] = v_20238;
v_20064:
    v_20238 = stack[-3];
    v_20238 = qcdr(v_20238);
    stack[-3] = v_20238;
    v_20238 = stack[-3];
    if (v_20238 == nil) goto v_20083;
    else goto v_20084;
v_20083:
    v_20238 = stack[-2];
    goto v_20063;
v_20084:
    goto v_20092;
v_20088:
    stack[0] = stack[-1];
    goto v_20089;
v_20090:
    v_20238 = stack[-3];
    v_20238 = qcar(v_20238);
    v_20239 = v_20238;
    v_20238 = lisp_true;
    qvalue(elt(env, 11)) = v_20238; // !*sub2
    v_20238 = v_20239;
    fn = elt(env, 25); // subs2
    v_20238 = (*qfn1(fn))(fn, v_20238);
    env = stack[-10];
    v_20238 = ncons(v_20238);
    env = stack[-10];
    goto v_20091;
v_20092:
    goto v_20088;
v_20089:
    goto v_20090;
v_20091:
    v_20238 = Lrplacd(nil, stack[0], v_20238);
    env = stack[-10];
    v_20238 = stack[-1];
    v_20238 = qcdr(v_20238);
    stack[-1] = v_20238;
    goto v_20064;
v_20063:
    v_20238 = ncons(v_20238);
    env = stack[-10];
    stack[-5] = v_20238;
    stack[-6] = v_20238;
v_20047:
    v_20238 = stack[-7];
    v_20238 = qcdr(v_20238);
    stack[-7] = v_20238;
    v_20238 = stack[-7];
    if (v_20238 == nil) goto v_20107;
    else goto v_20108;
v_20107:
    v_20238 = stack[-6];
    goto v_20046;
v_20108:
    goto v_20116;
v_20112:
    stack[-4] = stack[-5];
    goto v_20113;
v_20114:
    v_20238 = stack[-7];
    v_20238 = qcar(v_20238);
    stack[-3] = v_20238;
    v_20238 = stack[-3];
    if (v_20238 == nil) goto v_20131;
    else goto v_20132;
v_20131:
    v_20238 = nil;
    goto v_20126;
v_20132:
    v_20238 = stack[-3];
    v_20238 = qcar(v_20238);
    v_20239 = v_20238;
    v_20238 = lisp_true;
    qvalue(elt(env, 11)) = v_20238; // !*sub2
    v_20238 = v_20239;
    fn = elt(env, 25); // subs2
    v_20238 = (*qfn1(fn))(fn, v_20238);
    env = stack[-10];
    v_20238 = ncons(v_20238);
    env = stack[-10];
    stack[-1] = v_20238;
    stack[-2] = v_20238;
v_20127:
    v_20238 = stack[-3];
    v_20238 = qcdr(v_20238);
    stack[-3] = v_20238;
    v_20238 = stack[-3];
    if (v_20238 == nil) goto v_20146;
    else goto v_20147;
v_20146:
    v_20238 = stack[-2];
    goto v_20126;
v_20147:
    goto v_20155;
v_20151:
    stack[0] = stack[-1];
    goto v_20152;
v_20153:
    v_20238 = stack[-3];
    v_20238 = qcar(v_20238);
    v_20239 = v_20238;
    v_20238 = lisp_true;
    qvalue(elt(env, 11)) = v_20238; // !*sub2
    v_20238 = v_20239;
    fn = elt(env, 25); // subs2
    v_20238 = (*qfn1(fn))(fn, v_20238);
    env = stack[-10];
    v_20238 = ncons(v_20238);
    env = stack[-10];
    goto v_20154;
v_20155:
    goto v_20151;
v_20152:
    goto v_20153;
v_20154:
    v_20238 = Lrplacd(nil, stack[0], v_20238);
    env = stack[-10];
    v_20238 = stack[-1];
    v_20238 = qcdr(v_20238);
    stack[-1] = v_20238;
    goto v_20127;
v_20126:
    v_20238 = ncons(v_20238);
    env = stack[-10];
    goto v_20115;
v_20116:
    goto v_20112;
v_20113:
    goto v_20114;
v_20115:
    v_20238 = Lrplacd(nil, stack[-4], v_20238);
    env = stack[-10];
    v_20238 = stack[-5];
    v_20238 = qcdr(v_20238);
    stack[-5] = v_20238;
    goto v_20047;
v_20046:
    stack[-9] = v_20238;
    goto v_20027;
v_20027:
    goto v_19392;
v_19395:
    v_20238 = stack[-2];
    v_20238 = qcar(v_20238);
    v_20238 = qcar(v_20238);
    v_20238 = qcar(v_20238);
    if (v_20238 == nil) goto v_20170;
    else goto v_20171;
v_20170:
    goto v_20183;
v_20177:
    v_20240 = elt(env, 4); // matrix
    goto v_20178;
v_20179:
    v_20239 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_20180;
v_20181:
    v_20238 = elt(env, 12); // "Zero divisor"
    goto v_20182;
v_20183:
    goto v_20177;
v_20178:
    goto v_20179;
v_20180:
    goto v_20181;
v_20182:
    fn = elt(env, 20); // rerror
    v_20238 = (*qfnn(fn))(fn, 3, v_20240, v_20239, v_20238);
    env = stack[-10];
    goto v_20169;
v_20171:
v_20169:
    v_20238 = stack[-2];
    v_20238 = qcar(v_20238);
    v_20238 = qcar(v_20238);
    fn = elt(env, 26); // revpr
    v_20238 = (*qfn1(fn))(fn, v_20238);
    env = stack[-10];
    stack[-2] = v_20238;
    v_20238 = stack[-9];
    if (v_20238 == nil) goto v_20193;
    else goto v_20194;
v_20193:
    v_20238 = stack[-2];
    v_20238 = ncons(v_20238);
    env = stack[-10];
    v_20238 = ncons(v_20238);
    env = stack[-10];
    goto v_20192;
v_20194:
    goto v_20206;
v_20202:
    v_20239 = stack[-2];
    goto v_20203;
v_20204:
    v_20238 = stack[-9];
    goto v_20205;
v_20206:
    goto v_20202;
v_20203:
    goto v_20204;
v_20205:
    fn = elt(env, 17); // multsm
    v_20238 = (*qfn2(fn))(fn, v_20239, v_20238);
    env = stack[-10];
    goto v_20192;
    v_20238 = nil;
v_20192:
    stack[-9] = v_20238;
    goto v_19392;
v_19396:
    v_20238 = stack[-9];
    if (v_20238 == nil) goto v_20211;
    else goto v_20212;
v_20211:
    v_20238 = stack[-1];
    fn = elt(env, 27); // generateident
    v_20238 = (*qfn1(fn))(fn, v_20238);
    env = stack[-10];
    stack[-9] = v_20238;
    goto v_20210;
v_20212:
v_20210:
    goto v_19392;
v_19397:
    goto v_20223;
v_20217:
    stack[-1] = elt(env, 4); // matrix
    goto v_20218;
v_20219:
    stack[0] = (LispObject)112+TAG_FIXNUM; // 7
    goto v_20220;
v_20221:
    goto v_20233;
v_20227:
    v_20240 = elt(env, 13); // "Matrix"
    goto v_20228;
v_20229:
    v_20238 = stack[-8];
    v_20239 = qcar(v_20238);
    goto v_20230;
v_20231:
    v_20238 = elt(env, 14); // "not set"
    goto v_20232;
v_20233:
    goto v_20227;
v_20228:
    goto v_20229;
v_20230:
    goto v_20231;
v_20232:
    v_20238 = list3(v_20240, v_20239, v_20238);
    env = stack[-10];
    goto v_20222;
v_20223:
    goto v_20217;
v_20218:
    goto v_20219;
v_20220:
    goto v_20221;
v_20222:
    fn = elt(env, 20); // rerror
    v_20238 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_20238);
    v_20238 = nil;
v_19389:
    return onevalue(v_20238);
}



// Code for recaliasbacksubst

static LispObject CC_recaliasbacksubst(LispObject env,
                         LispObject v_19381, LispObject v_19382)
{
    env = qenv(env);
    LispObject v_19478, v_19479;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19382,v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19381,v_19382);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_19382;
    stack[0] = v_19381;
// end of prologue
    v_19478 = stack[0];
    if (!consp(v_19478)) goto v_19390;
    else goto v_19391;
v_19390:
    v_19478 = lisp_true;
    goto v_19389;
v_19391:
    v_19478 = stack[0];
    fn = elt(env, 1); // constp
    v_19478 = (*qfn1(fn))(fn, v_19478);
    env = stack[-5];
    goto v_19389;
    v_19478 = nil;
v_19389:
    if (v_19478 == nil) goto v_19387;
    goto v_19406;
v_19402:
    v_19479 = stack[0];
    goto v_19403;
v_19404:
    v_19478 = stack[-3];
    goto v_19405;
v_19406:
    goto v_19402;
v_19403:
    goto v_19404;
v_19405:
    v_19478 = Lassoc(nil, v_19479, v_19478);
    if (v_19478 == nil) goto v_19401;
    goto v_19414;
v_19410:
    v_19479 = stack[0];
    goto v_19411;
v_19412:
    v_19478 = stack[-3];
    goto v_19413;
v_19414:
    goto v_19410;
v_19411:
    goto v_19412;
v_19413:
    v_19478 = Lassoc(nil, v_19479, v_19478);
    v_19478 = qcdr(v_19478);
    goto v_19399;
v_19401:
    v_19478 = stack[0];
    goto v_19399;
    v_19478 = nil;
v_19399:
    goto v_19385;
v_19387:
    v_19478 = stack[0];
    stack[-4] = v_19478;
    v_19478 = stack[-4];
    if (v_19478 == nil) goto v_19433;
    else goto v_19434;
v_19433:
    v_19478 = nil;
    goto v_19428;
v_19434:
    v_19478 = stack[-4];
    v_19478 = qcar(v_19478);
    goto v_19446;
v_19442:
    v_19479 = v_19478;
    goto v_19443;
v_19444:
    v_19478 = stack[-3];
    goto v_19445;
v_19446:
    goto v_19442;
v_19443:
    goto v_19444;
v_19445:
    v_19478 = CC_recaliasbacksubst(elt(env, 0), v_19479, v_19478);
    env = stack[-5];
    v_19478 = ncons(v_19478);
    env = stack[-5];
    stack[-1] = v_19478;
    stack[-2] = v_19478;
v_19429:
    v_19478 = stack[-4];
    v_19478 = qcdr(v_19478);
    stack[-4] = v_19478;
    v_19478 = stack[-4];
    if (v_19478 == nil) goto v_19453;
    else goto v_19454;
v_19453:
    v_19478 = stack[-2];
    goto v_19428;
v_19454:
    goto v_19462;
v_19458:
    stack[0] = stack[-1];
    goto v_19459;
v_19460:
    v_19478 = stack[-4];
    v_19478 = qcar(v_19478);
    goto v_19473;
v_19469:
    v_19479 = v_19478;
    goto v_19470;
v_19471:
    v_19478 = stack[-3];
    goto v_19472;
v_19473:
    goto v_19469;
v_19470:
    goto v_19471;
v_19472:
    v_19478 = CC_recaliasbacksubst(elt(env, 0), v_19479, v_19478);
    env = stack[-5];
    v_19478 = ncons(v_19478);
    env = stack[-5];
    goto v_19461;
v_19462:
    goto v_19458;
v_19459:
    goto v_19460;
v_19461:
    v_19478 = Lrplacd(nil, stack[0], v_19478);
    env = stack[-5];
    v_19478 = stack[-1];
    v_19478 = qcdr(v_19478);
    stack[-1] = v_19478;
    goto v_19429;
v_19428:
    goto v_19385;
    v_19478 = nil;
v_19385:
    return onevalue(v_19478);
}



// Code for amatch

static LispObject CC_amatch(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_19514, v_19515, v_19516, v_19517;
    LispObject fn;
    LispObject v_19386, v_19385, v_19384, v_19383;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "amatch");
    va_start(aa, nargs);
    v_19383 = va_arg(aa, LispObject);
    v_19384 = va_arg(aa, LispObject);
    v_19385 = va_arg(aa, LispObject);
    v_19386 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_19386,v_19385,v_19384,v_19383);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_19383,v_19384,v_19385,v_19386);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_19386;
    stack[-4] = v_19385;
    v_19515 = v_19384;
    v_19514 = v_19383;
// end of prologue
// Binding r
// FLUIDBIND: reloadenv=6 litvec-offset=1 saveloc=5
{   bind_fluid_stack bind_fluid_var(-6, 1, -5);
// Binding p
// FLUIDBIND: reloadenv=6 litvec-offset=2 saveloc=2
{   bind_fluid_stack bind_fluid_var(-6, 2, -2);
    qvalue(elt(env, 1)) = v_19514; // r
    v_19514 = v_19515;
    qvalue(elt(env, 2)) = v_19514; // p
v_19397:
    v_19514 = qvalue(elt(env, 1)); // r
    if (!consp(v_19514)) goto v_19400;
    else goto v_19401;
v_19400:
    goto v_19414;
v_19404:
    stack[-1] = nil;
    goto v_19405;
v_19406:
    v_19514 = qvalue(elt(env, 1)); // r
    v_19514 = ncons(v_19514);
    env = stack[-6];
    fn = elt(env, 5); // mval
    stack[0] = (*qfn1(fn))(fn, v_19514);
    env = stack[-6];
    goto v_19407;
v_19408:
    v_19514 = qvalue(elt(env, 2)); // p
    v_19516 = ncons(v_19514);
    env = stack[-6];
    goto v_19409;
v_19410:
    v_19515 = stack[-4];
    goto v_19411;
v_19412:
    v_19514 = stack[-3];
    goto v_19413;
v_19414:
    goto v_19404;
v_19405:
    goto v_19406;
v_19407:
    goto v_19408;
v_19409:
    goto v_19410;
v_19411:
    goto v_19412;
v_19413:
    fn = elt(env, 6); // unify
    v_19514 = (*qfnn(fn))(fn, 5, stack[-1], stack[0], v_19516, v_19515, v_19514);
    goto v_19396;
v_19401:
    v_19514 = qvalue(elt(env, 2)); // p
    if (!consp(v_19514)) goto v_19427;
    else goto v_19428;
v_19427:
    v_19514 = lisp_true;
    goto v_19426;
v_19428:
    goto v_19438;
v_19434:
    v_19514 = qvalue(elt(env, 1)); // r
    v_19515 = qcar(v_19514);
    goto v_19435;
v_19436:
    v_19514 = qvalue(elt(env, 2)); // p
    v_19514 = qcar(v_19514);
    goto v_19437;
v_19438:
    goto v_19434;
v_19435:
    goto v_19436;
v_19437:
    v_19514 = Lneq(nil, v_19515, v_19514);
    env = stack[-6];
    goto v_19426;
    v_19514 = nil;
v_19426:
    if (v_19514 == nil) goto v_19423;
    else goto v_19424;
v_19423:
    goto v_19454;
v_19444:
    v_19514 = qvalue(elt(env, 1)); // r
    stack[0] = qcar(v_19514);
    goto v_19445;
v_19446:
    v_19514 = qvalue(elt(env, 1)); // r
    v_19514 = qcdr(v_19514);
    fn = elt(env, 5); // mval
    v_19517 = (*qfn1(fn))(fn, v_19514);
    env = stack[-6];
    goto v_19447;
v_19448:
    v_19514 = qvalue(elt(env, 2)); // p
    v_19516 = qcdr(v_19514);
    goto v_19449;
v_19450:
    v_19515 = stack[-4];
    goto v_19451;
v_19452:
    v_19514 = stack[-3];
    goto v_19453;
v_19454:
    goto v_19444;
v_19445:
    goto v_19446;
v_19447:
    goto v_19448;
v_19449:
    goto v_19450;
v_19451:
    goto v_19452;
v_19453:
    fn = elt(env, 6); // unify
    v_19514 = (*qfnn(fn))(fn, 5, stack[0], v_19517, v_19516, v_19515, v_19514);
    goto v_19396;
v_19424:
    v_19514 = qvalue(elt(env, 1)); // r
    fn = elt(env, 7); // suchp
    v_19514 = (*qfn1(fn))(fn, v_19514);
    env = stack[-6];
    if (v_19514 == nil) goto v_19465;
    v_19514 = qvalue(elt(env, 1)); // r
    v_19514 = qcdr(v_19514);
    v_19514 = qcar(v_19514);
    stack[0] = v_19514;
    goto v_19476;
v_19472:
    v_19514 = qvalue(elt(env, 1)); // r
    v_19514 = qcdr(v_19514);
    v_19514 = qcdr(v_19514);
    v_19515 = qcar(v_19514);
    goto v_19473;
v_19474:
    v_19514 = stack[-4];
    goto v_19475;
v_19476:
    goto v_19472;
v_19473:
    goto v_19474;
v_19475:
    v_19514 = cons(v_19515, v_19514);
    env = stack[-6];
    stack[-4] = v_19514;
    v_19514 = stack[0];
    qvalue(elt(env, 1)) = v_19514; // r
    goto v_19397;
v_19465:
    v_19514 = qvalue(elt(env, 3)); // !*semantic
    if (v_19514 == nil) goto v_19484;
    goto v_19491;
v_19487:
    goto v_19497;
v_19493:
    goto v_19505;
v_19499:
    v_19516 = elt(env, 4); // equal
    goto v_19500;
v_19501:
    v_19515 = qvalue(elt(env, 1)); // r
    goto v_19502;
v_19503:
    v_19514 = qvalue(elt(env, 2)); // p
    goto v_19504;
v_19505:
    goto v_19499;
v_19500:
    goto v_19501;
v_19502:
    goto v_19503;
v_19504:
    v_19515 = list3(v_19516, v_19515, v_19514);
    env = stack[-6];
    goto v_19494;
v_19495:
    v_19514 = stack[-4];
    goto v_19496;
v_19497:
    goto v_19493;
v_19494:
    goto v_19495;
v_19496:
    v_19515 = cons(v_19515, v_19514);
    env = stack[-6];
    goto v_19488;
v_19489:
    v_19514 = stack[-3];
    goto v_19490;
v_19491:
    goto v_19487;
v_19488:
    goto v_19489;
v_19490:
    fn = elt(env, 8); // resume
    v_19514 = (*qfn2(fn))(fn, v_19515, v_19514);
    goto v_19396;
v_19484:
    v_19514 = nil;
    goto v_19396;
    v_19514 = nil;
v_19396:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_19514);
}



// Code for fieldp

static LispObject CC_fieldp(LispObject env,
                         LispObject v_19381)
{
    env = qenv(env);
    LispObject v_19394, v_19395;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_19394 = v_19381;
// end of prologue
    v_19395 = v_19394;
    if (!consp(v_19395)) goto v_19386;
    v_19394 = qcar(v_19394);
    if (!symbolp(v_19394)) v_19394 = nil;
    else { v_19394 = qfastgets(v_19394);
           if (v_19394 != nil) { v_19394 = elt(v_19394, 3); // field
#ifdef RECORD_GET
             if (v_19394 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_19394 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_19394 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_19394 == SPID_NOPROP) v_19394 = nil; else v_19394 = lisp_true; }}
#endif
    goto v_19384;
v_19386:
    v_19394 = nil;
    goto v_19384;
    v_19394 = nil;
v_19384:
    return onevalue(v_19394);
}



// Code for evinvlexcomp

static LispObject CC_evinvlexcomp(LispObject env,
                         LispObject v_19381, LispObject v_19382)
{
    env = qenv(env);
    LispObject v_19469, v_19470;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19382,v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19381,v_19382);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_19382;
    stack[-1] = v_19381;
// end of prologue
v_19386:
    v_19469 = stack[-1];
    if (v_19469 == nil) goto v_19389;
    else goto v_19390;
v_19389:
    v_19469 = stack[0];
    if (v_19469 == nil) goto v_19394;
    else goto v_19395;
v_19394:
    v_19469 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19385;
v_19395:
    v_19469 = elt(env, 1); // (0)
    stack[-1] = v_19469;
    goto v_19386;
    goto v_19388;
v_19390:
    v_19469 = stack[0];
    if (v_19469 == nil) goto v_19401;
    else goto v_19402;
v_19401:
    goto v_19409;
v_19405:
    v_19470 = stack[-1];
    goto v_19406;
v_19407:
    v_19469 = elt(env, 1); // (0)
    goto v_19408;
v_19409:
    goto v_19405;
v_19406:
    goto v_19407;
v_19408:
    {
        fn = elt(env, 2); // evlexcomp
        return (*qfn2(fn))(fn, v_19470, v_19469);
    }
v_19402:
    goto v_19419;
v_19415:
    v_19469 = stack[-1];
    v_19470 = qcar(v_19469);
    goto v_19416;
v_19417:
    v_19469 = stack[0];
    v_19469 = qcar(v_19469);
    goto v_19418;
v_19419:
    goto v_19415;
v_19416:
    goto v_19417;
v_19418:
    fn = elt(env, 3); // iequal
    v_19469 = (*qfn2(fn))(fn, v_19470, v_19469);
    env = stack[-3];
    if (v_19469 == nil) goto v_19413;
    v_19469 = stack[-1];
    v_19469 = qcdr(v_19469);
    stack[-1] = v_19469;
    v_19469 = stack[0];
    v_19469 = qcdr(v_19469);
    stack[0] = v_19469;
    goto v_19386;
v_19413:
    goto v_19435;
v_19431:
    v_19469 = stack[-1];
    v_19470 = qcdr(v_19469);
    goto v_19432;
v_19433:
    v_19469 = stack[0];
    v_19469 = qcdr(v_19469);
    goto v_19434;
v_19435:
    goto v_19431;
v_19432:
    goto v_19433;
v_19434:
    v_19469 = CC_evinvlexcomp(elt(env, 0), v_19470, v_19469);
    env = stack[-3];
    stack[-2] = v_19469;
    goto v_19450;
v_19446:
    v_19470 = stack[-2];
    goto v_19447;
v_19448:
    v_19469 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19449;
v_19450:
    goto v_19446;
v_19447:
    goto v_19448;
v_19449:
    fn = elt(env, 3); // iequal
    v_19469 = (*qfn2(fn))(fn, v_19470, v_19469);
    if (v_19469 == nil) goto v_19443;
    else goto v_19444;
v_19443:
    v_19469 = stack[-2];
    goto v_19442;
v_19444:
    goto v_19460;
v_19456:
    v_19469 = stack[0];
    v_19470 = qcar(v_19469);
    goto v_19457;
v_19458:
    v_19469 = stack[-1];
    v_19469 = qcar(v_19469);
    goto v_19459;
v_19460:
    goto v_19456;
v_19457:
    goto v_19458;
v_19459:
    if (((intptr_t)(v_19470)) > ((intptr_t)(v_19469))) goto v_19454;
    else goto v_19455;
v_19454:
    v_19469 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19442;
v_19455:
    v_19469 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_19442;
    v_19469 = nil;
v_19442:
    goto v_19385;
v_19388:
    v_19469 = nil;
v_19385:
    return onevalue(v_19469);
}



// Code for color!-roads

static LispObject CC_colorKroads(LispObject env,
                         LispObject v_19381, LispObject v_19382)
{
    env = qenv(env);
    LispObject v_19510, v_19511, v_19512;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19382,v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19381,v_19382);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_19382;
    v_19512 = v_19381;
// end of prologue
    goto v_19394;
v_19390:
    v_19510 = stack[-4];
    v_19510 = qcar(v_19510);
    v_19511 = qcar(v_19510);
    goto v_19391;
v_19392:
    v_19510 = v_19512;
    goto v_19393;
v_19394:
    goto v_19390;
v_19391:
    goto v_19392;
v_19393:
    v_19510 = Lassoc(nil, v_19511, v_19510);
    v_19510 = qcdr(v_19510);
    stack[-1] = v_19510;
    goto v_19405;
v_19401:
    v_19510 = stack[-4];
    v_19510 = qcdr(v_19510);
    v_19510 = qcar(v_19510);
    v_19511 = qcar(v_19510);
    goto v_19402;
v_19403:
    v_19510 = v_19512;
    goto v_19404;
v_19405:
    goto v_19401;
v_19402:
    goto v_19403;
v_19404:
    v_19510 = Lassoc(nil, v_19511, v_19510);
    v_19510 = qcdr(v_19510);
    stack[0] = v_19510;
    goto v_19417;
v_19413:
    v_19510 = stack[-4];
    v_19510 = qcdr(v_19510);
    v_19510 = qcdr(v_19510);
    v_19510 = qcar(v_19510);
    v_19510 = qcar(v_19510);
    goto v_19414;
v_19415:
    v_19511 = v_19512;
    goto v_19416;
v_19417:
    goto v_19413;
v_19414:
    goto v_19415;
v_19416:
    v_19510 = Lassoc(nil, v_19510, v_19511);
    v_19510 = qcdr(v_19510);
    stack[-5] = v_19510;
    goto v_19431;
v_19427:
    goto v_19437;
v_19433:
    stack[-2] = stack[-1];
    goto v_19434;
v_19435:
    goto v_19444;
v_19440:
    v_19511 = stack[0];
    goto v_19441;
v_19442:
    v_19510 = stack[-5];
    goto v_19443;
v_19444:
    goto v_19440;
v_19441:
    goto v_19442;
v_19443:
    v_19510 = plus2(v_19511, v_19510);
    env = stack[-6];
    goto v_19436;
v_19437:
    goto v_19433;
v_19434:
    goto v_19435;
v_19436:
    v_19511 = plus2(stack[-2], v_19510);
    env = stack[-6];
    goto v_19428;
v_19429:
    v_19510 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_19430;
v_19431:
    goto v_19427;
v_19428:
    goto v_19429;
v_19430:
    v_19510 = quot2(v_19511, v_19510);
    env = stack[-6];
    stack[-2] = v_19510;
    goto v_19453;
v_19449:
    v_19511 = stack[-2];
    goto v_19450;
v_19451:
    v_19510 = stack[-1];
    goto v_19452;
v_19453:
    goto v_19449;
v_19450:
    goto v_19451;
v_19452:
    v_19510 = difference2(v_19511, v_19510);
    env = stack[-6];
    stack[-1] = v_19510;
    goto v_19461;
v_19457:
    v_19511 = stack[-2];
    goto v_19458;
v_19459:
    v_19510 = stack[0];
    goto v_19460;
v_19461:
    goto v_19457;
v_19458:
    goto v_19459;
v_19460:
    v_19510 = difference2(v_19511, v_19510);
    env = stack[-6];
    stack[0] = v_19510;
    goto v_19469;
v_19465:
    v_19511 = stack[-2];
    goto v_19466;
v_19467:
    v_19510 = stack[-5];
    goto v_19468;
v_19469:
    goto v_19465;
v_19466:
    goto v_19467;
v_19468:
    v_19510 = difference2(v_19511, v_19510);
    env = stack[-6];
    stack[-5] = v_19510;
    goto v_19479;
v_19473:
    v_19510 = stack[-4];
    v_19510 = qcar(v_19510);
    stack[-3] = qcar(v_19510);
    goto v_19474;
v_19475:
    stack[-2] = stack[-1];
    goto v_19476;
v_19477:
    goto v_19491;
v_19485:
    v_19510 = stack[-4];
    v_19510 = qcdr(v_19510);
    v_19510 = qcar(v_19510);
    stack[-1] = qcar(v_19510);
    goto v_19486;
v_19487:
    goto v_19488;
v_19489:
    goto v_19503;
v_19499:
    v_19510 = stack[-4];
    v_19510 = qcdr(v_19510);
    v_19510 = qcdr(v_19510);
    v_19510 = qcar(v_19510);
    v_19511 = qcar(v_19510);
    goto v_19500;
v_19501:
    v_19510 = stack[-5];
    goto v_19502;
v_19503:
    goto v_19499;
v_19500:
    goto v_19501;
v_19502:
    v_19510 = cons(v_19511, v_19510);
    env = stack[-6];
    v_19510 = ncons(v_19510);
    env = stack[-6];
    goto v_19490;
v_19491:
    goto v_19485;
v_19486:
    goto v_19487;
v_19488:
    goto v_19489;
v_19490:
    v_19510 = acons(stack[-1], stack[0], v_19510);
    goto v_19478;
v_19479:
    goto v_19473;
v_19474:
    goto v_19475;
v_19476:
    goto v_19477;
v_19478:
    {
        LispObject v_19519 = stack[-3];
        LispObject v_19520 = stack[-2];
        return acons(v_19519, v_19520, v_19510);
    }
    return onevalue(v_19510);
}



// Code for greaterpcdr

static LispObject CC_greaterpcdr(LispObject env,
                         LispObject v_19381, LispObject v_19382)
{
    env = qenv(env);
    LispObject v_19394, v_19395;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_19394 = v_19382;
    v_19395 = v_19381;
// end of prologue
    goto v_19389;
v_19385:
    v_19395 = qcdr(v_19395);
    goto v_19386;
v_19387:
    v_19394 = qcdr(v_19394);
    goto v_19388;
v_19389:
    goto v_19385;
v_19386:
    goto v_19387;
v_19388:
        return Lgreaterp(nil, v_19395, v_19394);
}



// Code for assert_structstat

static LispObject CC_assert_structstat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_19525, v_19526, v_19527;
    LispObject fn;
    argcheck(nargs, 0, "assert_structstat");
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
    fn = elt(env, 16); // scan
    v_19525 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[0] = v_19525;
    goto v_19396;
v_19390:
    stack[-1] = elt(env, 1); // flag
    goto v_19391;
v_19392:
    v_19525 = stack[0];
    v_19525 = ncons(v_19525);
    env = stack[-5];
    v_19526 = Lmkquote(nil, v_19525);
    env = stack[-5];
    goto v_19393;
v_19394:
    v_19525 = elt(env, 2); // (quote assert_dyntype)
    goto v_19395;
v_19396:
    goto v_19390;
v_19391:
    goto v_19392;
v_19393:
    goto v_19394;
v_19395:
    v_19525 = list3(stack[-1], v_19526, v_19525);
    env = stack[-5];
    stack[-3] = v_19525;
    fn = elt(env, 16); // scan
    v_19525 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_19525 = qvalue(elt(env, 3)); // cursym!*
    if (!symbolp(v_19525)) v_19525 = nil;
    else { v_19525 = qfastgets(v_19525);
           if (v_19525 != nil) { v_19525 = elt(v_19525, 55); // delim
#ifdef RECORD_GET
             if (v_19525 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v_19525 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v_19525 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v_19525 == SPID_NOPROP) v_19525 = nil; else v_19525 = lisp_true; }}
#endif
    if (v_19525 == nil) goto v_19406;
    v_19525 = qvalue(elt(env, 4)); // !*msg
    if (v_19525 == nil) goto v_19412;
    goto v_19422;
v_19416:
    v_19527 = elt(env, 5); // "struct"
    goto v_19417;
v_19418:
    v_19526 = stack[0];
    goto v_19419;
v_19420:
    v_19525 = elt(env, 6); // "is not checked"
    goto v_19421;
v_19422:
    goto v_19416;
v_19417:
    goto v_19418;
v_19419:
    goto v_19420;
v_19421:
    v_19525 = list3(v_19527, v_19526, v_19525);
    env = stack[-5];
    fn = elt(env, 17); // lprim
    v_19525 = (*qfn1(fn))(fn, v_19525);
    goto v_19410;
v_19412:
v_19410:
    v_19525 = stack[-3];
    goto v_19387;
v_19406:
    goto v_19439;
v_19435:
    v_19526 = qvalue(elt(env, 3)); // cursym!*
    goto v_19436;
v_19437:
    v_19525 = elt(env, 7); // checked
    goto v_19438;
v_19439:
    goto v_19435;
v_19436:
    goto v_19437;
v_19438:
    if (v_19526 == v_19525) goto v_19434;
    goto v_19447;
v_19443:
    v_19526 = qvalue(elt(env, 3)); // cursym!*
    goto v_19444;
v_19445:
    v_19525 = elt(env, 8); // asserted
    goto v_19446;
v_19447:
    goto v_19443;
v_19444:
    goto v_19445;
v_19446:
    v_19525 = Lneq(nil, v_19526, v_19525);
    env = stack[-5];
    goto v_19432;
v_19434:
    v_19525 = nil;
    goto v_19432;
    v_19525 = nil;
v_19432:
    if (v_19525 == nil) goto v_19430;
    goto v_19459;
v_19455:
    v_19526 = elt(env, 9); // "expecting 'asserted by' in struct but found"
    goto v_19456;
v_19457:
    v_19525 = qvalue(elt(env, 3)); // cursym!*
    goto v_19458;
v_19459:
    goto v_19455;
v_19456:
    goto v_19457;
v_19458:
    v_19525 = list2(v_19526, v_19525);
    env = stack[-5];
    fn = elt(env, 18); // rederr
    v_19525 = (*qfn1(fn))(fn, v_19525);
    env = stack[-5];
    goto v_19428;
v_19430:
v_19428:
    goto v_19470;
v_19466:
    fn = elt(env, 16); // scan
    v_19526 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_19467;
v_19468:
    v_19525 = elt(env, 10); // by
    goto v_19469;
v_19470:
    goto v_19466;
v_19467:
    goto v_19468;
v_19469:
    if (v_19526 == v_19525) goto v_19465;
    goto v_19479;
v_19475:
    v_19526 = elt(env, 11); // "expecting 'by' in struct but found"
    goto v_19476;
v_19477:
    v_19525 = qvalue(elt(env, 3)); // cursym!*
    goto v_19478;
v_19479:
    goto v_19475;
v_19476:
    goto v_19477;
v_19478:
    v_19525 = list2(v_19526, v_19525);
    env = stack[-5];
    fn = elt(env, 18); // rederr
    v_19525 = (*qfn1(fn))(fn, v_19525);
    env = stack[-5];
    goto v_19463;
v_19465:
v_19463:
    fn = elt(env, 16); // scan
    v_19525 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[-4] = v_19525;
    fn = elt(env, 16); // scan
    v_19525 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    if (!symbolp(v_19525)) v_19525 = nil;
    else { v_19525 = qfastgets(v_19525);
           if (v_19525 != nil) { v_19525 = elt(v_19525, 55); // delim
#ifdef RECORD_GET
             if (v_19525 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v_19525 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v_19525 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v_19525 == SPID_NOPROP) v_19525 = nil; else v_19525 = lisp_true; }}
#endif
    if (v_19525 == nil) goto v_19485;
    else goto v_19486;
v_19485:
    goto v_19495;
v_19491:
    v_19526 = elt(env, 12); // "expecting end of struct but found"
    goto v_19492;
v_19493:
    v_19525 = qvalue(elt(env, 3)); // cursym!*
    goto v_19494;
v_19495:
    goto v_19491;
v_19492:
    goto v_19493;
v_19494:
    v_19525 = list2(v_19526, v_19525);
    env = stack[-5];
    fn = elt(env, 18); // rederr
    v_19525 = (*qfn1(fn))(fn, v_19525);
    env = stack[-5];
    goto v_19484;
v_19486:
v_19484:
    goto v_19507;
v_19499:
    stack[-2] = elt(env, 13); // put
    goto v_19500;
v_19501:
    v_19525 = stack[0];
    stack[-1] = Lmkquote(nil, v_19525);
    env = stack[-5];
    goto v_19502;
v_19503:
    stack[0] = elt(env, 14); // (quote assert_dyntypechk)
    goto v_19504;
v_19505:
    v_19525 = stack[-4];
    v_19525 = Lmkquote(nil, v_19525);
    env = stack[-5];
    goto v_19506;
v_19507:
    goto v_19499;
v_19500:
    goto v_19501;
v_19502:
    goto v_19503;
v_19504:
    goto v_19505;
v_19506:
    v_19525 = list4(stack[-2], stack[-1], stack[0], v_19525);
    env = stack[-5];
    goto v_19521;
v_19515:
    v_19527 = elt(env, 15); // progn
    goto v_19516;
v_19517:
    v_19526 = v_19525;
    goto v_19518;
v_19519:
    v_19525 = stack[-3];
    goto v_19520;
v_19521:
    goto v_19515;
v_19516:
    goto v_19517;
v_19518:
    goto v_19519;
v_19520:
    return list3(v_19527, v_19526, v_19525);
v_19387:
    return onevalue(v_19525);
}



// Code for subs2chk

static LispObject CC_subs2chk(LispObject env,
                         LispObject v_19381)
{
    env = qenv(env);
    LispObject v_19405, v_19406, v_19407;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19381);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_19381;
// end of prologue
    v_19405 = qvalue(elt(env, 1)); // subfg!*
    if (v_19405 == nil) goto v_19389;
    goto v_19397;
v_19393:
    v_19405 = stack[0];
    fn = elt(env, 2); // subs2f
    v_19405 = (*qfn1(fn))(fn, v_19405);
    v_19407 = v_19405;
    v_19406 = qcdr(v_19405);
    goto v_19394;
v_19395:
    v_19405 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19396;
v_19397:
    goto v_19393;
v_19394:
    goto v_19395;
v_19396:
    if (v_19406 == v_19405) goto v_19392;
    else goto v_19389;
v_19392:
    v_19405 = v_19407;
    v_19405 = qcar(v_19405);
    stack[0] = v_19405;
    goto v_19387;
v_19389:
v_19387:
    v_19405 = stack[0];
    return onevalue(v_19405);
}



// Code for fs!:prin

static LispObject CC_fsTprin(LispObject env,
                         LispObject v_19381)
{
    env = qenv(env);
    LispObject v_19418, v_19419;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19381);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_19381;
// end of prologue
    v_19418 = stack[0];
    if (v_19418 == nil) goto v_19385;
    else goto v_19386;
v_19385:
    v_19418 = elt(env, 1); // " 0 "
    {
        fn = elt(env, 3); // prin2!*
        return (*qfn1(fn))(fn, v_19418);
    }
v_19386:
v_19394:
    v_19418 = stack[0];
    if (v_19418 == nil) goto v_19397;
    else goto v_19398;
v_19397:
    v_19418 = nil;
    goto v_19393;
v_19398:
    v_19418 = stack[0];
    fn = elt(env, 4); // fs!:prin1
    v_19418 = (*qfn1(fn))(fn, v_19418);
    env = stack[-1];
    goto v_19407;
v_19403:
    v_19419 = stack[0];
    goto v_19404;
v_19405:
    v_19418 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_19406;
v_19407:
    goto v_19403;
v_19404:
    goto v_19405;
v_19406:
    v_19418 = *(LispObject *)((char *)v_19419 + (CELL-TAG_VECTOR) + (((intptr_t)v_19418-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_19418;
    v_19418 = stack[0];
    if (v_19418 == nil) goto v_19414;
    v_19418 = elt(env, 2); // " + "
    fn = elt(env, 3); // prin2!*
    v_19418 = (*qfn1(fn))(fn, v_19418);
    env = stack[-1];
    goto v_19412;
v_19414:
v_19412:
    goto v_19394;
v_19393:
    goto v_19384;
    v_19418 = nil;
v_19384:
    return onevalue(v_19418);
}



// Code for mo_zero!?

static LispObject CC_mo_zeroW(LispObject env,
                         LispObject v_19381)
{
    env = qenv(env);
    LispObject v_19386;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_19386 = v_19381;
// end of prologue
    v_19386 = qcar(v_19386);
    {
        fn = elt(env, 1); // mo!=zero
        return (*qfn1(fn))(fn, v_19386);
    }
}



// Code for dv_ind2var

static LispObject CC_dv_ind2var(LispObject env,
                         LispObject v_19381)
{
    env = qenv(env);
    LispObject v_19415, v_19416;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19381);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_19381;
// end of prologue
    goto v_19392;
v_19388:
    stack[-1] = stack[0];
    goto v_19389;
v_19390:
    v_19415 = qvalue(elt(env, 1)); // g_dvnames
    fn = elt(env, 3); // upbve
    v_19415 = (*qfn1(fn))(fn, v_19415);
    env = stack[-2];
    goto v_19391;
v_19392:
    goto v_19388;
v_19389:
    goto v_19390;
v_19391:
    v_19415 = (LispObject)lesseq2(stack[-1], v_19415);
    v_19415 = v_19415 ? lisp_true : nil;
    env = stack[-2];
    if (v_19415 == nil) goto v_19386;
    goto v_19400;
v_19396:
    stack[-1] = qvalue(elt(env, 1)); // g_dvnames
    goto v_19397;
v_19398:
    v_19415 = stack[0];
    v_19415 = sub1(v_19415);
    goto v_19399;
v_19400:
    goto v_19396;
v_19397:
    goto v_19398;
v_19399:
    v_19415 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_19415-TAG_FIXNUM)/(16/CELL)));
    goto v_19384;
v_19386:
    goto v_19412;
v_19408:
    v_19416 = qvalue(elt(env, 2)); // g_dvbase
    goto v_19409;
v_19410:
    v_19415 = stack[0];
    goto v_19411;
v_19412:
    goto v_19408;
v_19409:
    goto v_19410;
v_19411:
    {
        fn = elt(env, 4); // mkid
        return (*qfn2(fn))(fn, v_19416, v_19415);
    }
    v_19415 = nil;
v_19384:
    return onevalue(v_19415);
}



// Code for outer!-simpsqrt

static LispObject CC_outerKsimpsqrt(LispObject env,
                         LispObject v_19381)
{
    env = qenv(env);
    LispObject v_19394, v_19395;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_19395 = v_19381;
// end of prologue
    v_19394 = qvalue(elt(env, 1)); // !*inside!-int!*
    if (v_19394 == nil) goto v_19386;
    v_19394 = v_19395;
    {
        fn = elt(env, 2); // proper!-simpsqrt
        return (*qfn1(fn))(fn, v_19394);
    }
v_19386:
    v_19394 = v_19395;
    {
        fn = elt(env, 3); // simpsqrt
        return (*qfn1(fn))(fn, v_19394);
    }
    v_19394 = nil;
    return onevalue(v_19394);
}



// Code for msolve!-polyn

static LispObject CC_msolveKpolyn(LispObject env,
                         LispObject v_19381, LispObject v_19382)
{
    env = qenv(env);
    LispObject v_19630, v_19631, v_19632;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19382,v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19381,v_19382);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-8] = v_19382;
    stack[-9] = v_19381;
// end of prologue
    v_19630 = stack[-8];
    v_19630 = qcar(v_19630);
    stack[-10] = v_19630;
    v_19630 = stack[-8];
    v_19630 = qcdr(v_19630);
    if (v_19630 == nil) goto v_19389;
    else goto v_19390;
v_19389:
    goto v_19398;
v_19394:
    v_19631 = stack[-9];
    goto v_19395;
v_19396:
    v_19630 = stack[-8];
    v_19630 = qcar(v_19630);
    goto v_19397;
v_19398:
    goto v_19394;
v_19395:
    goto v_19396;
v_19397:
    {
        fn = elt(env, 2); // msolve!-poly1
        return (*qfn2(fn))(fn, v_19631, v_19630);
    }
v_19390:
    v_19630 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_19630;
v_19409:
    goto v_19422;
v_19418:
    v_19630 = qvalue(elt(env, 1)); // current!-modulus
    v_19631 = sub1(v_19630);
    env = stack[-11];
    goto v_19419;
v_19420:
    v_19630 = stack[-7];
    goto v_19421;
v_19422:
    goto v_19418;
v_19419:
    goto v_19420;
v_19421:
    v_19630 = difference2(v_19631, v_19630);
    env = stack[-11];
    v_19630 = Lminusp(nil, v_19630);
    env = stack[-11];
    if (v_19630 == nil) goto v_19415;
    v_19630 = nil;
    goto v_19408;
v_19415:
    goto v_19438;
v_19434:
    goto v_19444;
v_19440:
    stack[0] = stack[-9];
    goto v_19441;
v_19442:
    goto v_19452;
v_19448:
    v_19631 = stack[-10];
    goto v_19449;
v_19450:
    v_19630 = stack[-7];
    goto v_19451;
v_19452:
    goto v_19448;
v_19449:
    goto v_19450;
v_19451:
    v_19630 = cons(v_19631, v_19630);
    env = stack[-11];
    v_19630 = ncons(v_19630);
    env = stack[-11];
    goto v_19443;
v_19444:
    goto v_19440;
v_19441:
    goto v_19442;
v_19443:
    fn = elt(env, 3); // subf
    v_19630 = (*qfn2(fn))(fn, stack[0], v_19630);
    env = stack[-11];
    v_19631 = qcar(v_19630);
    goto v_19435;
v_19436:
    v_19630 = stack[-8];
    v_19630 = qcdr(v_19630);
    goto v_19437;
v_19438:
    goto v_19434;
v_19435:
    goto v_19436;
v_19437:
    v_19630 = CC_msolveKpolyn(elt(env, 0), v_19631, v_19630);
    env = stack[-11];
    stack[-3] = v_19630;
    v_19630 = stack[-3];
    if (v_19630 == nil) goto v_19460;
    else goto v_19461;
v_19460:
    v_19630 = nil;
    goto v_19431;
v_19461:
    v_19630 = stack[-3];
    v_19630 = qcar(v_19630);
    goto v_19475;
v_19469:
    v_19632 = stack[-10];
    goto v_19470;
v_19471:
    v_19631 = stack[-7];
    goto v_19472;
v_19473:
    goto v_19474;
v_19475:
    goto v_19469;
v_19470:
    goto v_19471;
v_19472:
    goto v_19473;
v_19474:
    v_19630 = acons(v_19632, v_19631, v_19630);
    env = stack[-11];
    v_19630 = ncons(v_19630);
    env = stack[-11];
    stack[-1] = v_19630;
    stack[-2] = v_19630;
v_19432:
    v_19630 = stack[-3];
    v_19630 = qcdr(v_19630);
    stack[-3] = v_19630;
    v_19630 = stack[-3];
    if (v_19630 == nil) goto v_19483;
    else goto v_19484;
v_19483:
    v_19630 = stack[-2];
    goto v_19431;
v_19484:
    goto v_19492;
v_19488:
    stack[0] = stack[-1];
    goto v_19489;
v_19490:
    v_19630 = stack[-3];
    v_19630 = qcar(v_19630);
    goto v_19505;
v_19499:
    v_19632 = stack[-10];
    goto v_19500;
v_19501:
    v_19631 = stack[-7];
    goto v_19502;
v_19503:
    goto v_19504;
v_19505:
    goto v_19499;
v_19500:
    goto v_19501;
v_19502:
    goto v_19503;
v_19504:
    v_19630 = acons(v_19632, v_19631, v_19630);
    env = stack[-11];
    v_19630 = ncons(v_19630);
    env = stack[-11];
    goto v_19491;
v_19492:
    goto v_19488;
v_19489:
    goto v_19490;
v_19491:
    v_19630 = Lrplacd(nil, stack[0], v_19630);
    env = stack[-11];
    v_19630 = stack[-1];
    v_19630 = qcdr(v_19630);
    stack[-1] = v_19630;
    goto v_19432;
v_19431:
    stack[-6] = v_19630;
    v_19630 = stack[-6];
    fn = elt(env, 4); // lastpair
    v_19630 = (*qfn1(fn))(fn, v_19630);
    env = stack[-11];
    stack[-5] = v_19630;
    v_19630 = stack[-7];
    v_19630 = add1(v_19630);
    env = stack[-11];
    stack[-7] = v_19630;
    v_19630 = stack[-5];
    if (!consp(v_19630)) goto v_19517;
    else goto v_19518;
v_19517:
    goto v_19409;
v_19518:
v_19410:
    goto v_19530;
v_19526:
    v_19630 = qvalue(elt(env, 1)); // current!-modulus
    v_19631 = sub1(v_19630);
    env = stack[-11];
    goto v_19527;
v_19528:
    v_19630 = stack[-7];
    goto v_19529;
v_19530:
    goto v_19526;
v_19527:
    goto v_19528;
v_19529:
    v_19630 = difference2(v_19631, v_19630);
    env = stack[-11];
    v_19630 = Lminusp(nil, v_19630);
    env = stack[-11];
    if (v_19630 == nil) goto v_19523;
    v_19630 = stack[-6];
    goto v_19408;
v_19523:
    goto v_19540;
v_19536:
    stack[-4] = stack[-5];
    goto v_19537;
v_19538:
    goto v_19553;
v_19549:
    goto v_19559;
v_19555:
    stack[0] = stack[-9];
    goto v_19556;
v_19557:
    goto v_19567;
v_19563:
    v_19631 = stack[-10];
    goto v_19564;
v_19565:
    v_19630 = stack[-7];
    goto v_19566;
v_19567:
    goto v_19563;
v_19564:
    goto v_19565;
v_19566:
    v_19630 = cons(v_19631, v_19630);
    env = stack[-11];
    v_19630 = ncons(v_19630);
    env = stack[-11];
    goto v_19558;
v_19559:
    goto v_19555;
v_19556:
    goto v_19557;
v_19558:
    fn = elt(env, 3); // subf
    v_19630 = (*qfn2(fn))(fn, stack[0], v_19630);
    env = stack[-11];
    v_19631 = qcar(v_19630);
    goto v_19550;
v_19551:
    v_19630 = stack[-8];
    v_19630 = qcdr(v_19630);
    goto v_19552;
v_19553:
    goto v_19549;
v_19550:
    goto v_19551;
v_19552:
    v_19630 = CC_msolveKpolyn(elt(env, 0), v_19631, v_19630);
    env = stack[-11];
    stack[-3] = v_19630;
    v_19630 = stack[-3];
    if (v_19630 == nil) goto v_19575;
    else goto v_19576;
v_19575:
    v_19630 = nil;
    goto v_19546;
v_19576:
    v_19630 = stack[-3];
    v_19630 = qcar(v_19630);
    goto v_19590;
v_19584:
    v_19632 = stack[-10];
    goto v_19585;
v_19586:
    v_19631 = stack[-7];
    goto v_19587;
v_19588:
    goto v_19589;
v_19590:
    goto v_19584;
v_19585:
    goto v_19586;
v_19587:
    goto v_19588;
v_19589:
    v_19630 = acons(v_19632, v_19631, v_19630);
    env = stack[-11];
    v_19630 = ncons(v_19630);
    env = stack[-11];
    stack[-1] = v_19630;
    stack[-2] = v_19630;
v_19547:
    v_19630 = stack[-3];
    v_19630 = qcdr(v_19630);
    stack[-3] = v_19630;
    v_19630 = stack[-3];
    if (v_19630 == nil) goto v_19598;
    else goto v_19599;
v_19598:
    v_19630 = stack[-2];
    goto v_19546;
v_19599:
    goto v_19607;
v_19603:
    stack[0] = stack[-1];
    goto v_19604;
v_19605:
    v_19630 = stack[-3];
    v_19630 = qcar(v_19630);
    goto v_19620;
v_19614:
    v_19632 = stack[-10];
    goto v_19615;
v_19616:
    v_19631 = stack[-7];
    goto v_19617;
v_19618:
    goto v_19619;
v_19620:
    goto v_19614;
v_19615:
    goto v_19616;
v_19617:
    goto v_19618;
v_19619:
    v_19630 = acons(v_19632, v_19631, v_19630);
    env = stack[-11];
    v_19630 = ncons(v_19630);
    env = stack[-11];
    goto v_19606;
v_19607:
    goto v_19603;
v_19604:
    goto v_19605;
v_19606:
    v_19630 = Lrplacd(nil, stack[0], v_19630);
    env = stack[-11];
    v_19630 = stack[-1];
    v_19630 = qcdr(v_19630);
    stack[-1] = v_19630;
    goto v_19547;
v_19546:
    goto v_19539;
v_19540:
    goto v_19536;
v_19537:
    goto v_19538;
v_19539:
    v_19630 = Lrplacd(nil, stack[-4], v_19630);
    env = stack[-11];
    v_19630 = stack[-5];
    fn = elt(env, 4); // lastpair
    v_19630 = (*qfn1(fn))(fn, v_19630);
    env = stack[-11];
    stack[-5] = v_19630;
    v_19630 = stack[-7];
    v_19630 = add1(v_19630);
    env = stack[-11];
    stack[-7] = v_19630;
    goto v_19410;
v_19408:
    goto v_19388;
    v_19630 = nil;
v_19388:
    return onevalue(v_19630);
}



// Code for !*a2k

static LispObject CC_Ha2k(LispObject env,
                         LispObject v_19381)
{
    env = qenv(env);
    LispObject v_19416, v_19417;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19381);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_19381;
// end of prologue
    v_19416 = stack[0];
    fn = elt(env, 2); // simp!*
    v_19416 = (*qfn1(fn))(fn, v_19416);
    env = stack[-2];
    stack[-1] = v_19416;
    fn = elt(env, 3); // kernp
    v_19416 = (*qfn1(fn))(fn, v_19416);
    env = stack[-2];
    if (v_19416 == nil) goto v_19389;
    v_19416 = stack[-1];
    v_19416 = qcar(v_19416);
    v_19416 = qcar(v_19416);
    v_19416 = qcar(v_19416);
    v_19416 = qcar(v_19416);
    goto v_19385;
v_19389:
    goto v_19405;
v_19401:
    v_19416 = stack[0];
    if (v_19416 == nil) goto v_19408;
    else goto v_19409;
v_19408:
    v_19416 = (LispObject)0+TAG_FIXNUM; // 0
    v_19417 = v_19416;
    goto v_19407;
v_19409:
    v_19416 = stack[0];
    v_19417 = v_19416;
    goto v_19407;
    v_19417 = nil;
v_19407:
    goto v_19402;
v_19403:
    v_19416 = elt(env, 1); // kernel
    goto v_19404;
v_19405:
    goto v_19401;
v_19402:
    goto v_19403;
v_19404:
    fn = elt(env, 4); // typerr
    v_19416 = (*qfn2(fn))(fn, v_19417, v_19416);
    goto v_19387;
v_19387:
    v_19416 = nil;
v_19385:
    return onevalue(v_19416);
}



// Code for lalr_warn_shift_reduce_conflict

static LispObject CC_lalr_warn_shift_reduce_conflict(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_19423;
    LispObject fn;
    LispObject v_19383, v_19382, v_19381;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "lalr_warn_shift_reduce_conflict");
    va_start(aa, nargs);
    v_19381 = va_arg(aa, LispObject);
    v_19382 = va_arg(aa, LispObject);
    v_19383 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_19383,v_19382,v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_19381,v_19382,v_19383);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_19383;
    stack[-1] = v_19382;
    stack[-2] = v_19381;
// end of prologue
    v_19423 = Lposn(nil, 0);
    env = stack[-3];
    v_19423 = (LispObject)zerop(v_19423);
    v_19423 = v_19423 ? lisp_true : nil;
    env = stack[-3];
    if (v_19423 == nil) goto v_19387;
    else goto v_19388;
v_19387:
    v_19423 = Lterpri(nil, 0);
    env = stack[-3];
    goto v_19386;
v_19388:
v_19386:
    v_19423 = elt(env, 1); // "+++ Shift/reduce conflict in itemset #"
    v_19423 = Lprinc(nil, v_19423);
    env = stack[-3];
    v_19423 = stack[0];
    v_19423 = Lprin(nil, v_19423);
    env = stack[-3];
    v_19423 = elt(env, 2); // " on lookahead "
    v_19423 = Lprinc(nil, v_19423);
    env = stack[-3];
    v_19423 = stack[-2];
    v_19423 = qcar(v_19423);
    fn = elt(env, 6); // lalr_prin_symbol
    v_19423 = (*qfn1(fn))(fn, v_19423);
    env = stack[-3];
    v_19423 = Lterpri(nil, 0);
    env = stack[-3];
    v_19423 = elt(env, 3); // "Reduce: "
    v_19423 = Lprinc(nil, v_19423);
    env = stack[-3];
    v_19423 = stack[-1];
    v_19423 = qcdr(v_19423);
    v_19423 = qcar(v_19423);
    v_19423 = qcdr(v_19423);
    v_19423 = qcar(v_19423);
    fn = elt(env, 7); // lalr_prin_production
    v_19423 = (*qfn1(fn))(fn, v_19423);
    env = stack[-3];
    v_19423 = Lterpri(nil, 0);
    env = stack[-3];
    v_19423 = elt(env, 4); // "Shift: to state #"
    v_19423 = Lprinc(nil, v_19423);
    env = stack[-3];
    v_19423 = stack[-2];
    v_19423 = qcdr(v_19423);
    v_19423 = qcar(v_19423);
    v_19423 = qcdr(v_19423);
    v_19423 = qcar(v_19423);
    v_19423 = Lprin(nil, v_19423);
    env = stack[-3];
    v_19423 = Lterpri(nil, 0);
    env = stack[-3];
    v_19423 = elt(env, 5); // "Resolved in favour of the shift operation"
    v_19423 = Lprintc(nil, v_19423);
        return Lterpri(nil, 0);
}



// Code for component_action

static LispObject CC_component_action(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_19455, v_19456, v_19457;
    LispObject fn;
    LispObject v_19383, v_19382, v_19381;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "component_action");
    va_start(aa, nargs);
    v_19381 = va_arg(aa, LispObject);
    v_19382 = va_arg(aa, LispObject);
    v_19383 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_19383,v_19382,v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_19381,v_19382,v_19383);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_19383;
    stack[-3] = v_19382;
    stack[0] = v_19381;
// end of prologue
    goto v_19393;
v_19389:
    v_19456 = nil;
    goto v_19390;
v_19391:
    v_19455 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19392;
v_19393:
    goto v_19389;
v_19390:
    goto v_19391;
v_19392:
    v_19455 = cons(v_19456, v_19455);
    env = stack[-5];
    stack[-4] = v_19455;
    v_19455 = stack[0];
    v_19455 = qcdr(v_19455);
    stack[-1] = v_19455;
v_19399:
    v_19455 = stack[-1];
    if (v_19455 == nil) goto v_19404;
    else goto v_19405;
v_19404:
    goto v_19398;
v_19405:
    v_19455 = stack[-1];
    v_19455 = qcar(v_19455);
    stack[0] = v_19455;
    goto v_19416;
v_19412:
    v_19455 = stack[0];
    v_19456 = qcar(v_19455);
    goto v_19413;
v_19414:
    v_19455 = stack[-3];
    goto v_19415;
v_19416:
    goto v_19412;
v_19413:
    goto v_19414;
v_19415:
    fn = elt(env, 1); // ext_mult
    v_19456 = (*qfn2(fn))(fn, v_19456, v_19455);
    env = stack[-5];
    v_19455 = stack[0];
    v_19455 = qcdr(v_19455);
    v_19457 = v_19456;
    v_19456 = v_19455;
    v_19455 = v_19457;
    v_19455 = qcar(v_19455);
    if (v_19455 == nil) goto v_19427;
    goto v_19435;
v_19431:
    stack[0] = stack[-4];
    goto v_19432;
v_19433:
    goto v_19442;
v_19438:
    goto v_19448;
v_19444:
    v_19455 = v_19457;
    goto v_19445;
v_19446:
    goto v_19447;
v_19448:
    goto v_19444;
v_19445:
    goto v_19446;
v_19447:
    fn = elt(env, 2); // multsq
    v_19456 = (*qfn2(fn))(fn, v_19455, v_19456);
    env = stack[-5];
    goto v_19439;
v_19440:
    v_19455 = stack[-2];
    goto v_19441;
v_19442:
    goto v_19438;
v_19439:
    goto v_19440;
v_19441:
    fn = elt(env, 2); // multsq
    v_19455 = (*qfn2(fn))(fn, v_19456, v_19455);
    env = stack[-5];
    goto v_19434;
v_19435:
    goto v_19431;
v_19432:
    goto v_19433;
v_19434:
    fn = elt(env, 3); // addsq
    v_19455 = (*qfn2(fn))(fn, stack[0], v_19455);
    env = stack[-5];
    stack[-4] = v_19455;
    goto v_19425;
v_19427:
v_19425:
    v_19455 = stack[-1];
    v_19455 = qcdr(v_19455);
    stack[-1] = v_19455;
    goto v_19399;
v_19398:
    v_19455 = stack[-4];
    return onevalue(v_19455);
}



// Code for plusdf

static LispObject CC_plusdf(LispObject env,
                         LispObject v_19381, LispObject v_19382)
{
    env = qenv(env);
    LispObject v_19516, v_19517, v_19518;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19382,v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19381,v_19382);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_19382;
    stack[-2] = v_19381;
// end of prologue
    stack[0] = nil;
v_19387:
    v_19516 = stack[-2];
    if (v_19516 == nil) goto v_19390;
    else goto v_19391;
v_19390:
    goto v_19398;
v_19394:
    v_19517 = stack[0];
    goto v_19395;
v_19396:
    v_19516 = stack[-1];
    goto v_19397;
v_19398:
    goto v_19394;
v_19395:
    goto v_19396;
v_19397:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_19517, v_19516);
    }
v_19391:
    v_19516 = stack[-1];
    if (v_19516 == nil) goto v_19401;
    else goto v_19402;
v_19401:
    goto v_19409;
v_19405:
    v_19517 = stack[0];
    goto v_19406;
v_19407:
    v_19516 = stack[-2];
    goto v_19408;
v_19409:
    goto v_19405;
v_19406:
    goto v_19407;
v_19408:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_19517, v_19516);
    }
v_19402:
    goto v_19418;
v_19414:
    v_19516 = stack[-2];
    v_19516 = qcar(v_19516);
    v_19517 = qcar(v_19516);
    goto v_19415;
v_19416:
    v_19516 = stack[-1];
    v_19516 = qcar(v_19516);
    v_19516 = qcar(v_19516);
    goto v_19417;
v_19418:
    goto v_19414;
v_19415:
    goto v_19416;
v_19417:
    if (equal(v_19517, v_19516)) goto v_19412;
    else goto v_19413;
v_19412:
    goto v_19430;
v_19426:
    stack[-3] = stack[0];
    goto v_19427;
v_19428:
    goto v_19437;
v_19433:
    v_19516 = stack[-2];
    v_19516 = qcar(v_19516);
    v_19517 = qcdr(v_19516);
    goto v_19434;
v_19435:
    v_19516 = stack[-1];
    v_19516 = qcar(v_19516);
    v_19516 = qcdr(v_19516);
    goto v_19436;
v_19437:
    goto v_19433;
v_19434:
    goto v_19435;
v_19436:
    fn = elt(env, 2); // !*addsq
    stack[0] = (*qfn2(fn))(fn, v_19517, v_19516);
    env = stack[-4];
    goto v_19449;
v_19445:
    v_19516 = stack[-2];
    v_19517 = qcdr(v_19516);
    goto v_19446;
v_19447:
    v_19516 = stack[-1];
    v_19516 = qcdr(v_19516);
    goto v_19448;
v_19449:
    goto v_19445;
v_19446:
    goto v_19447;
v_19448:
    v_19516 = CC_plusdf(elt(env, 0), v_19517, v_19516);
    env = stack[-4];
    v_19517 = stack[0];
    v_19518 = v_19517;
    v_19518 = qcar(v_19518);
    if (v_19518 == nil) goto v_19458;
    else goto v_19459;
v_19458:
    goto v_19457;
v_19459:
    goto v_19472;
v_19466:
    v_19518 = stack[-2];
    v_19518 = qcar(v_19518);
    v_19518 = qcar(v_19518);
    goto v_19467;
v_19468:
    goto v_19469;
v_19470:
    goto v_19471;
v_19472:
    goto v_19466;
v_19467:
    goto v_19468;
v_19469:
    goto v_19470;
v_19471:
    v_19516 = acons(v_19518, v_19517, v_19516);
    env = stack[-4];
    goto v_19457;
    v_19516 = nil;
v_19457:
    goto v_19429;
v_19430:
    goto v_19426;
v_19427:
    goto v_19428;
v_19429:
    {
        LispObject v_19523 = stack[-3];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_19523, v_19516);
    }
v_19413:
    goto v_19485;
v_19481:
    v_19516 = stack[-2];
    v_19516 = qcar(v_19516);
    v_19517 = qcar(v_19516);
    goto v_19482;
v_19483:
    v_19516 = stack[-1];
    v_19516 = qcar(v_19516);
    v_19516 = qcar(v_19516);
    goto v_19484;
v_19485:
    goto v_19481;
v_19482:
    goto v_19483;
v_19484:
    fn = elt(env, 3); // orddf
    v_19516 = (*qfn2(fn))(fn, v_19517, v_19516);
    env = stack[-4];
    if (v_19516 == nil) goto v_19479;
    goto v_19497;
v_19493:
    v_19516 = stack[-2];
    v_19517 = qcar(v_19516);
    goto v_19494;
v_19495:
    v_19516 = stack[0];
    goto v_19496;
v_19497:
    goto v_19493;
v_19494:
    goto v_19495;
v_19496:
    v_19516 = cons(v_19517, v_19516);
    env = stack[-4];
    stack[0] = v_19516;
    v_19516 = stack[-2];
    v_19516 = qcdr(v_19516);
    stack[-2] = v_19516;
    goto v_19387;
v_19479:
    goto v_19510;
v_19506:
    v_19516 = stack[-1];
    v_19517 = qcar(v_19516);
    goto v_19507;
v_19508:
    v_19516 = stack[0];
    goto v_19509;
v_19510:
    goto v_19506;
v_19507:
    goto v_19508;
v_19509:
    v_19516 = cons(v_19517, v_19516);
    env = stack[-4];
    stack[0] = v_19516;
    v_19516 = stack[-1];
    v_19516 = qcdr(v_19516);
    stack[-1] = v_19516;
    goto v_19387;
    v_19516 = nil;
    return onevalue(v_19516);
}



// Code for get!*inverse

static LispObject CC_getHinverse(LispObject env,
                         LispObject v_19381, LispObject v_19382)
{
    env = qenv(env);
    LispObject v_19413, v_19414, v_19415;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19382,v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19381,v_19382);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_19414 = v_19382;
    v_19413 = v_19381;
// end of prologue
    goto v_19392;
v_19388:
    v_19415 = v_19413;
    goto v_19389;
v_19390:
    v_19413 = elt(env, 1); // inverse
    goto v_19391;
v_19392:
    goto v_19388;
v_19389:
    goto v_19390;
v_19391:
    v_19413 = get(v_19415, v_19413);
    env = stack[-1];
    v_19415 = v_19413;
    goto v_19400;
v_19396:
    v_19413 = v_19415;
    v_19413 = qcdr(v_19413);
    stack[0] = qcar(v_19413);
    goto v_19397;
v_19398:
    goto v_19409;
v_19405:
    v_19413 = v_19414;
    goto v_19406;
v_19407:
    v_19414 = v_19415;
    v_19414 = qcar(v_19414);
    goto v_19408;
v_19409:
    goto v_19405;
v_19406:
    goto v_19407;
v_19408:
    fn = elt(env, 2); // give!*position
    v_19413 = (*qfn2(fn))(fn, v_19413, v_19414);
    env = stack[-1];
    goto v_19399;
v_19400:
    goto v_19396;
v_19397:
    goto v_19398;
v_19399:
    {
        LispObject v_19417 = stack[0];
        fn = elt(env, 3); // nth
        return (*qfn2(fn))(fn, v_19417, v_19413);
    }
    return onevalue(v_19413);
}



// Code for talp_sumd

static LispObject CC_talp_sumd(LispObject env,
                         LispObject v_19381)
{
    env = qenv(env);
    LispObject v_19430, v_19431;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19381);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_19431 = v_19381;
// end of prologue
    v_19430 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_19430;
    v_19430 = v_19431;
    if (!consp(v_19430)) goto v_19390;
    else goto v_19391;
v_19390:
    v_19430 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19386;
v_19391:
    v_19430 = v_19431;
    fn = elt(env, 1); // rl_atl
    v_19430 = (*qfn1(fn))(fn, v_19430);
    env = stack[-3];
    stack[-2] = v_19430;
v_19398:
    v_19430 = stack[-2];
    if (v_19430 == nil) goto v_19401;
    else goto v_19402;
v_19401:
    goto v_19397;
v_19402:
    goto v_19410;
v_19406:
    stack[-1] = stack[0];
    goto v_19407;
v_19408:
    goto v_19417;
v_19413:
    v_19430 = stack[-2];
    v_19430 = qcar(v_19430);
    fn = elt(env, 2); // talp_arg2l
    v_19430 = (*qfn1(fn))(fn, v_19430);
    env = stack[-3];
    fn = elt(env, 3); // talp_td
    stack[0] = (*qfn1(fn))(fn, v_19430);
    env = stack[-3];
    goto v_19414;
v_19415:
    v_19430 = stack[-2];
    v_19430 = qcar(v_19430);
    fn = elt(env, 4); // talp_arg2r
    v_19430 = (*qfn1(fn))(fn, v_19430);
    env = stack[-3];
    fn = elt(env, 3); // talp_td
    v_19430 = (*qfn1(fn))(fn, v_19430);
    env = stack[-3];
    goto v_19416;
v_19417:
    goto v_19413;
v_19414:
    goto v_19415;
v_19416:
    v_19430 = plus2(stack[0], v_19430);
    env = stack[-3];
    goto v_19409;
v_19410:
    goto v_19406;
v_19407:
    goto v_19408;
v_19409:
    v_19430 = plus2(stack[-1], v_19430);
    env = stack[-3];
    stack[0] = v_19430;
    v_19430 = stack[-2];
    v_19430 = qcdr(v_19430);
    stack[-2] = v_19430;
    goto v_19398;
v_19397:
    v_19430 = stack[0];
v_19386:
    return onevalue(v_19430);
}



// Code for cl_susicpknowl

static LispObject CC_cl_susicpknowl(LispObject env,
                         LispObject v_19381)
{
    env = qenv(env);
    LispObject v_19441, v_19442;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19381);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_19441 = v_19381;
// end of prologue
    stack[-3] = v_19441;
    v_19441 = stack[-3];
    if (v_19441 == nil) goto v_19392;
    else goto v_19393;
v_19392:
    v_19441 = nil;
    goto v_19387;
v_19393:
    v_19441 = stack[-3];
    v_19441 = qcar(v_19441);
    goto v_19405;
v_19401:
    v_19442 = v_19441;
    v_19442 = qcar(v_19442);
    goto v_19402;
v_19403:
    v_19441 = qcdr(v_19441);
    goto v_19404;
v_19405:
    goto v_19401;
v_19402:
    goto v_19403;
v_19404:
    v_19441 = cons(v_19442, v_19441);
    env = stack[-4];
    v_19441 = ncons(v_19441);
    env = stack[-4];
    stack[-1] = v_19441;
    stack[-2] = v_19441;
v_19388:
    v_19441 = stack[-3];
    v_19441 = qcdr(v_19441);
    stack[-3] = v_19441;
    v_19441 = stack[-3];
    if (v_19441 == nil) goto v_19414;
    else goto v_19415;
v_19414:
    v_19441 = stack[-2];
    goto v_19387;
v_19415:
    goto v_19423;
v_19419:
    stack[0] = stack[-1];
    goto v_19420;
v_19421:
    v_19441 = stack[-3];
    v_19441 = qcar(v_19441);
    goto v_19434;
v_19430:
    v_19442 = v_19441;
    v_19442 = qcar(v_19442);
    goto v_19431;
v_19432:
    v_19441 = qcdr(v_19441);
    goto v_19433;
v_19434:
    goto v_19430;
v_19431:
    goto v_19432;
v_19433:
    v_19441 = cons(v_19442, v_19441);
    env = stack[-4];
    v_19441 = ncons(v_19441);
    env = stack[-4];
    goto v_19422;
v_19423:
    goto v_19419;
v_19420:
    goto v_19421;
v_19422:
    v_19441 = Lrplacd(nil, stack[0], v_19441);
    env = stack[-4];
    v_19441 = stack[-1];
    v_19441 = qcdr(v_19441);
    stack[-1] = v_19441;
    goto v_19388;
v_19387:
    return onevalue(v_19441);
}



// Code for listrd

static LispObject CC_listrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_19404, v_19405;
    LispObject fn;
    argcheck(nargs, 0, "listrd");
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
    goto v_19390;
v_19386:
    v_19405 = qvalue(elt(env, 1)); // atts
    goto v_19387;
v_19388:
    v_19404 = elt(env, 2); // (order)
    goto v_19389;
v_19390:
    goto v_19386;
v_19387:
    goto v_19388;
v_19389:
    fn = elt(env, 4); // retattributes
    v_19404 = (*qfn2(fn))(fn, v_19405, v_19404);
    env = stack[-2];
    goto v_19400;
v_19394:
    stack[-1] = elt(env, 3); // list
    goto v_19395;
v_19396:
    stack[0] = v_19404;
    goto v_19397;
v_19398:
    fn = elt(env, 5); // stats_getargs
    v_19404 = (*qfnn(fn))(fn, 0);
    goto v_19399;
v_19400:
    goto v_19394;
v_19395:
    goto v_19396;
v_19397:
    goto v_19398;
v_19399:
    {
        LispObject v_19408 = stack[-1];
        LispObject v_19409 = stack[0];
        return list2star(v_19408, v_19409, v_19404);
    }
    return onevalue(v_19404);
}



// Code for delyzz

static LispObject CC_delyzz(LispObject env,
                         LispObject v_19381, LispObject v_19382)
{
    env = qenv(env);
    LispObject v_19423, v_19424, v_19425;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19382,v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19381,v_19382);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_19382;
    stack[-1] = v_19381;
// end of prologue
    v_19425 = nil;
v_19387:
    goto v_19396;
v_19392:
    v_19424 = stack[-1];
    goto v_19393;
v_19394:
    v_19423 = stack[0];
    v_19423 = qcar(v_19423);
    v_19423 = qcar(v_19423);
    goto v_19395;
v_19396:
    goto v_19392;
v_19393:
    goto v_19394;
v_19395:
    if (equal(v_19424, v_19423)) goto v_19390;
    else goto v_19391;
v_19390:
    goto v_19406;
v_19402:
    v_19424 = v_19425;
    goto v_19403;
v_19404:
    v_19423 = stack[0];
    v_19423 = qcdr(v_19423);
    goto v_19405;
v_19406:
    goto v_19402;
v_19403:
    goto v_19404;
v_19405:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_19424, v_19423);
    }
v_19391:
    goto v_19417;
v_19413:
    v_19423 = stack[0];
    v_19423 = qcar(v_19423);
    goto v_19414;
v_19415:
    v_19424 = v_19425;
    goto v_19416;
v_19417:
    goto v_19413;
v_19414:
    goto v_19415;
v_19416:
    v_19423 = cons(v_19423, v_19424);
    env = stack[-2];
    v_19425 = v_19423;
    v_19423 = stack[0];
    v_19423 = qcdr(v_19423);
    stack[0] = v_19423;
    goto v_19387;
    v_19423 = nil;
    return onevalue(v_19423);
}



// Code for unplus

static LispObject CC_unplus(LispObject env,
                         LispObject v_19381)
{
    env = qenv(env);
    LispObject v_19465, v_19466, v_19467;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19381);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_19381;
// end of prologue
    v_19467 = nil;
v_19386:
    v_19465 = stack[-1];
    if (!consp(v_19465)) goto v_19389;
    else goto v_19390;
v_19389:
    goto v_19397;
v_19393:
    v_19466 = v_19467;
    goto v_19394;
v_19395:
    v_19465 = stack[-1];
    goto v_19396;
v_19397:
    goto v_19393;
v_19394:
    goto v_19395;
v_19396:
    {
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_19466, v_19465);
    }
v_19390:
    goto v_19406;
v_19402:
    v_19465 = stack[-1];
    v_19466 = qcar(v_19465);
    goto v_19403;
v_19404:
    v_19465 = elt(env, 1); // plus
    goto v_19405;
v_19406:
    goto v_19402;
v_19403:
    goto v_19404;
v_19405:
    if (v_19466 == v_19465) goto v_19400;
    else goto v_19401;
v_19400:
    v_19465 = stack[-1];
    v_19465 = qcdr(v_19465);
    stack[-1] = v_19465;
    goto v_19386;
v_19401:
    v_19465 = stack[-1];
    v_19465 = qcar(v_19465);
    if (!consp(v_19465)) goto v_19416;
    else goto v_19417;
v_19416:
    v_19465 = lisp_true;
    goto v_19415;
v_19417:
    goto v_19428;
v_19424:
    v_19465 = stack[-1];
    v_19466 = qcar(v_19465);
    goto v_19425;
v_19426:
    v_19465 = elt(env, 1); // plus
    goto v_19427;
v_19428:
    goto v_19424;
v_19425:
    goto v_19426;
v_19427:
    v_19465 = Leqcar(nil, v_19466, v_19465);
    env = stack[-3];
    v_19465 = (v_19465 == nil ? lisp_true : nil);
    goto v_19415;
    v_19465 = nil;
v_19415:
    if (v_19465 == nil) goto v_19413;
    goto v_19438;
v_19434:
    v_19465 = stack[-1];
    v_19465 = qcar(v_19465);
    goto v_19435;
v_19436:
    v_19466 = v_19467;
    goto v_19437;
v_19438:
    goto v_19434;
v_19435:
    goto v_19436;
v_19437:
    v_19465 = cons(v_19465, v_19466);
    env = stack[-3];
    v_19467 = v_19465;
    v_19465 = stack[-1];
    v_19465 = qcdr(v_19465);
    stack[-1] = v_19465;
    goto v_19386;
v_19413:
    goto v_19451;
v_19447:
    stack[-2] = v_19467;
    goto v_19448;
v_19449:
    goto v_19458;
v_19454:
    v_19465 = stack[-1];
    v_19465 = qcar(v_19465);
    stack[0] = qcdr(v_19465);
    goto v_19455;
v_19456:
    v_19465 = stack[-1];
    v_19465 = qcdr(v_19465);
    v_19465 = CC_unplus(elt(env, 0), v_19465);
    env = stack[-3];
    goto v_19457;
v_19458:
    goto v_19454;
v_19455:
    goto v_19456;
v_19457:
    v_19465 = Lappend(nil, stack[0], v_19465);
    env = stack[-3];
    goto v_19450;
v_19451:
    goto v_19447;
v_19448:
    goto v_19449;
v_19450:
    {
        LispObject v_19471 = stack[-2];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_19471, v_19465);
    }
    v_19465 = nil;
    return onevalue(v_19465);
}



// Code for convprc2

static LispObject CC_convprc2(LispObject env,
                         LispObject v_19381, LispObject v_19382)
{
    env = qenv(env);
    LispObject v_19470, v_19471, v_19472;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19382,v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19381,v_19382);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_19382;
    stack[-1] = v_19381;
// end of prologue
    v_19470 = stack[-1];
    fn = elt(env, 4); // convprec
    v_19470 = (*qfn1(fn))(fn, v_19470);
    env = stack[-2];
    stack[-1] = v_19470;
    v_19470 = stack[0];
    fn = elt(env, 4); // convprec
    v_19470 = (*qfn1(fn))(fn, v_19470);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_19470; // yy!!
    v_19470 = qvalue(elt(env, 2)); // !*roundbf
    if (v_19470 == nil) goto v_19391;
    v_19470 = qvalue(elt(env, 1)); // yy!!
    v_19471 = v_19470;
    v_19471 = Lfloatp(nil, v_19471);
    env = stack[-2];
    if (v_19471 == nil) goto v_19398;
    fn = elt(env, 5); // fl2bf
    v_19470 = (*qfn1(fn))(fn, v_19470);
    env = stack[-2];
    goto v_19396;
v_19398:
    v_19471 = v_19470;
    if (!consp(v_19471)) goto v_19409;
    goto v_19407;
v_19409:
    v_19471 = v_19470;
    v_19471 = integerp(v_19471);
    if (v_19471 == nil) goto v_19413;
    goto v_19423;
v_19417:
    v_19472 = elt(env, 3); // !:rd!:
    goto v_19418;
v_19419:
    v_19471 = v_19470;
    goto v_19420;
v_19421:
    v_19470 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19422;
v_19423:
    goto v_19417;
v_19418:
    goto v_19419;
v_19420:
    goto v_19421;
v_19422:
    v_19470 = list2star(v_19472, v_19471, v_19470);
    env = stack[-2];
    goto v_19407;
v_19413:
    fn = elt(env, 6); // read!:num
    v_19470 = (*qfn1(fn))(fn, v_19470);
    env = stack[-2];
    goto v_19407;
    v_19470 = nil;
v_19407:
    fn = elt(env, 7); // normbf
    v_19470 = (*qfn1(fn))(fn, v_19470);
    env = stack[-2];
    goto v_19396;
    v_19470 = nil;
v_19396:
    qvalue(elt(env, 1)) = v_19470; // yy!!
    v_19470 = stack[-1];
    v_19470 = Lfloatp(nil, v_19470);
    env = stack[-2];
    if (v_19470 == nil) goto v_19434;
    v_19470 = stack[-1];
    {
        fn = elt(env, 5); // fl2bf
        return (*qfn1(fn))(fn, v_19470);
    }
v_19434:
    v_19470 = stack[-1];
    if (!consp(v_19470)) goto v_19445;
    v_19470 = stack[-1];
    goto v_19443;
v_19445:
    v_19470 = stack[-1];
    v_19470 = integerp(v_19470);
    if (v_19470 == nil) goto v_19449;
    goto v_19459;
v_19453:
    v_19472 = elt(env, 3); // !:rd!:
    goto v_19454;
v_19455:
    v_19471 = stack[-1];
    goto v_19456;
v_19457:
    v_19470 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19458;
v_19459:
    goto v_19453;
v_19454:
    goto v_19455;
v_19456:
    goto v_19457;
v_19458:
    v_19470 = list2star(v_19472, v_19471, v_19470);
    env = stack[-2];
    goto v_19443;
v_19449:
    v_19470 = stack[-1];
    fn = elt(env, 6); // read!:num
    v_19470 = (*qfn1(fn))(fn, v_19470);
    env = stack[-2];
    goto v_19443;
    v_19470 = nil;
v_19443:
    {
        fn = elt(env, 7); // normbf
        return (*qfn1(fn))(fn, v_19470);
    }
    v_19470 = nil;
    goto v_19389;
v_19391:
    v_19470 = stack[-1];
    goto v_19389;
    v_19470 = nil;
v_19389:
    return onevalue(v_19470);
}



// Code for po!:statep

static LispObject CC_poTstatep(LispObject env,
                         LispObject v_19381)
{
    env = qenv(env);
    LispObject v_19430, v_19431, v_19432;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_19432 = v_19381;
// end of prologue
    v_19430 = v_19432;
    if (symbolp(v_19430)) goto v_19389;
    v_19430 = nil;
    goto v_19387;
v_19389:
    goto v_19398;
v_19394:
    v_19430 = v_19432;
    if (!symbolp(v_19430)) v_19431 = nil;
    else { v_19431 = qfastgets(v_19430);
           if (v_19431 != nil) { v_19431 = elt(v_19431, 18); // phystype
#ifdef RECORD_GET
             if (v_19431 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v_19431 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v_19431 == SPID_NOPROP) v_19431 = nil; }}
#endif
    goto v_19395;
v_19396:
    v_19430 = elt(env, 1); // state
    goto v_19397;
v_19398:
    goto v_19394;
v_19395:
    goto v_19396;
v_19397:
    v_19430 = (v_19431 == v_19430 ? lisp_true : nil);
    goto v_19387;
    v_19430 = nil;
v_19387:
    if (v_19430 == nil) goto v_19385;
    else goto v_19384;
v_19385:
    v_19430 = v_19432;
    if (!consp(v_19430)) goto v_19406;
    v_19430 = v_19432;
    v_19430 = qcar(v_19430);
    if (symbolp(v_19430)) goto v_19411;
    v_19430 = nil;
    goto v_19409;
v_19411:
    goto v_19421;
v_19417:
    v_19430 = v_19432;
    v_19430 = qcar(v_19430);
    if (!symbolp(v_19430)) v_19430 = nil;
    else { v_19430 = qfastgets(v_19430);
           if (v_19430 != nil) { v_19430 = elt(v_19430, 18); // phystype
#ifdef RECORD_GET
             if (v_19430 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v_19430 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v_19430 == SPID_NOPROP) v_19430 = nil; }}
#endif
    goto v_19418;
v_19419:
    v_19431 = elt(env, 1); // state
    goto v_19420;
v_19421:
    goto v_19417;
v_19418:
    goto v_19419;
v_19420:
    v_19430 = (v_19430 == v_19431 ? lisp_true : nil);
    goto v_19409;
    v_19430 = nil;
v_19409:
    goto v_19404;
v_19406:
    v_19430 = nil;
    goto v_19404;
    v_19430 = nil;
v_19404:
v_19384:
    return onevalue(v_19430);
}



// Code for color!-strand

static LispObject CC_colorKstrand(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_19421, v_19422, v_19423;
    LispObject fn;
    LispObject v_19383, v_19382, v_19381;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "color-strand");
    va_start(aa, nargs);
    v_19381 = va_arg(aa, LispObject);
    v_19382 = va_arg(aa, LispObject);
    v_19383 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_19383,v_19382,v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_19381,v_19382,v_19383);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_19383;
    stack[-1] = v_19382;
    stack[-2] = v_19381;
// end of prologue
    stack[-3] = nil;
v_19388:
    v_19421 = stack[-1];
    if (v_19421 == nil) goto v_19391;
    else goto v_19392;
v_19391:
    v_19421 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_19421);
    }
v_19392:
    goto v_19405;
v_19399:
    goto v_19411;
v_19407:
    v_19422 = stack[-2];
    goto v_19408;
v_19409:
    v_19421 = stack[-1];
    v_19421 = qcar(v_19421);
    goto v_19410;
v_19411:
    goto v_19407;
v_19408:
    goto v_19409;
v_19410:
    fn = elt(env, 2); // color!-roads
    v_19423 = (*qfn2(fn))(fn, v_19422, v_19421);
    env = stack[-4];
    goto v_19400;
v_19401:
    v_19422 = stack[0];
    goto v_19402;
v_19403:
    v_19421 = stack[-3];
    goto v_19404;
v_19405:
    goto v_19399;
v_19400:
    goto v_19401;
v_19402:
    goto v_19403;
v_19404:
    v_19421 = acons(v_19423, v_19422, v_19421);
    env = stack[-4];
    stack[-3] = v_19421;
    v_19421 = stack[-1];
    v_19421 = qcdr(v_19421);
    stack[-1] = v_19421;
    v_19421 = stack[0];
    v_19421 = add1(v_19421);
    env = stack[-4];
    stack[0] = v_19421;
    goto v_19388;
    v_19421 = nil;
    return onevalue(v_19421);
}



// Code for realvaluedp

static LispObject CC_realvaluedp(LispObject env,
                         LispObject v_19381)
{
    env = qenv(env);
    LispObject v_19451, v_19452, v_19453;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19381);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_19452 = v_19381;
// end of prologue
    v_19451 = v_19452;
    if (!consp(v_19451)) goto v_19385;
    else goto v_19386;
v_19385:
    v_19451 = v_19452;
    v_19451 = (is_number(v_19451) ? lisp_true : nil);
    if (v_19451 == nil) goto v_19390;
    else goto v_19389;
v_19390:
    goto v_19398;
v_19394:
    v_19451 = v_19452;
    goto v_19395;
v_19396:
    v_19452 = elt(env, 1); // realvalued
    goto v_19397;
v_19398:
    goto v_19394;
v_19395:
    goto v_19396;
v_19397:
        return Lflagp(nil, v_19451, v_19452);
v_19389:
    goto v_19384;
v_19386:
    goto v_19415;
v_19411:
    v_19451 = v_19452;
    v_19453 = qcar(v_19451);
    stack[0] = v_19453;
    goto v_19412;
v_19413:
    v_19451 = elt(env, 2); // alwaysrealvalued
    goto v_19414;
v_19415:
    goto v_19411;
v_19412:
    goto v_19413;
v_19414:
    v_19451 = Lflagp(nil, v_19453, v_19451);
    env = stack[-1];
    if (v_19451 == nil) goto v_19409;
    v_19451 = lisp_true;
    goto v_19407;
v_19409:
    goto v_19434;
v_19430:
    v_19453 = stack[0];
    goto v_19431;
v_19432:
    v_19451 = elt(env, 1); // realvalued
    goto v_19433;
v_19434:
    goto v_19430;
v_19431:
    goto v_19432;
v_19433:
    v_19451 = Lflagp(nil, v_19453, v_19451);
    env = stack[-1];
    if (v_19451 == nil) goto v_19428;
    v_19451 = v_19452;
    v_19451 = qcdr(v_19451);
    fn = elt(env, 4); // realvaluedlist
    v_19451 = (*qfn1(fn))(fn, v_19451);
    env = stack[-1];
    goto v_19426;
v_19428:
    v_19451 = nil;
    goto v_19426;
    v_19451 = nil;
v_19426:
    if (v_19451 == nil) goto v_19424;
    else goto v_19423;
v_19424:
    goto v_19447;
v_19443:
    v_19451 = stack[0];
    goto v_19444;
v_19445:
    v_19452 = elt(env, 3); // !:rd!:
    goto v_19446;
v_19447:
    goto v_19443;
v_19444:
    goto v_19445;
v_19446:
    v_19451 = (v_19451 == v_19452 ? lisp_true : nil);
v_19423:
    goto v_19407;
    v_19451 = nil;
v_19407:
    goto v_19384;
    v_19451 = nil;
v_19384:
    return onevalue(v_19451);
}



// Code for subeval1

static LispObject CC_subeval1(LispObject env,
                         LispObject v_19381, LispObject v_19382)
{
    env = qenv(env);
    LispObject v_19480, v_19481, v_19482;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19382,v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19381,v_19382);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_19382;
    stack[-2] = v_19381;
// end of prologue
v_19390:
    v_19480 = stack[-2];
    if (v_19480 == nil) goto v_19393;
    goto v_19402;
v_19398:
    v_19480 = stack[-2];
    v_19480 = qcar(v_19480);
    v_19481 = qcar(v_19480);
    goto v_19399;
v_19400:
    v_19480 = stack[-2];
    v_19480 = qcar(v_19480);
    v_19480 = qcdr(v_19480);
    goto v_19401;
v_19402:
    goto v_19398;
v_19399:
    goto v_19400;
v_19401:
    if (equal(v_19481, v_19480)) goto v_19397;
    else goto v_19393;
v_19397:
    goto v_19394;
v_19393:
    goto v_19389;
v_19394:
    v_19480 = stack[-2];
    v_19480 = qcdr(v_19480);
    stack[-2] = v_19480;
    goto v_19390;
v_19389:
    v_19480 = stack[-2];
    if (v_19480 == nil) goto v_19414;
    else goto v_19415;
v_19414:
    v_19480 = stack[-1];
    goto v_19387;
v_19415:
    v_19480 = stack[-1];
    fn = elt(env, 5); // getrtype
    v_19480 = (*qfn1(fn))(fn, v_19480);
    env = stack[-4];
    v_19482 = v_19480;
    if (v_19480 == nil) goto v_19419;
    goto v_19431;
v_19427:
    v_19481 = v_19482;
    goto v_19428;
v_19429:
    v_19480 = elt(env, 1); // subfn
    goto v_19430;
v_19431:
    goto v_19427;
v_19428:
    goto v_19429;
v_19430:
    v_19480 = get(v_19481, v_19480);
    env = stack[-4];
    v_19481 = v_19480;
    if (v_19480 == nil) goto v_19425;
    goto v_19441;
v_19435:
    v_19482 = v_19481;
    goto v_19436;
v_19437:
    v_19481 = stack[-2];
    goto v_19438;
v_19439:
    v_19480 = stack[-1];
    goto v_19440;
v_19441:
    goto v_19435;
v_19436:
    goto v_19437;
v_19438:
    goto v_19439;
v_19440:
        return Lapply2(nil, 3, v_19482, v_19481, v_19480);
v_19425:
    goto v_19454;
v_19448:
    stack[-3] = elt(env, 2); // alg
    goto v_19449;
v_19450:
    stack[0] = (LispObject)368+TAG_FIXNUM; // 23
    goto v_19451;
v_19452:
    goto v_19462;
v_19458:
    v_19480 = elt(env, 3); // "No substitution defined for type"
    goto v_19459;
v_19460:
    v_19481 = v_19482;
    goto v_19461;
v_19462:
    goto v_19458;
v_19459:
    goto v_19460;
v_19461:
    v_19480 = list2(v_19480, v_19481);
    env = stack[-4];
    goto v_19453;
v_19454:
    goto v_19448;
v_19449:
    goto v_19450;
v_19451:
    goto v_19452;
v_19453:
    fn = elt(env, 6); // rerror
    v_19480 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_19480);
    env = stack[-4];
    goto v_19423;
v_19423:
    goto v_19413;
v_19419:
v_19413:
    goto v_19470;
v_19466:
    v_19480 = stack[-1];
    fn = elt(env, 7); // simp
    v_19481 = (*qfn1(fn))(fn, v_19480);
    env = stack[-4];
    goto v_19467;
v_19468:
    v_19480 = stack[-2];
    goto v_19469;
v_19470:
    goto v_19466;
v_19467:
    goto v_19468;
v_19469:
    fn = elt(env, 8); // subsq
    v_19480 = (*qfn2(fn))(fn, v_19481, v_19480);
    env = stack[-4];
    stack[-2] = v_19480;
    v_19480 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=4 litvec-offset=4 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 4, 0);
    qvalue(elt(env, 4)) = v_19480; // !*sub2
    v_19480 = stack[-2];
    fn = elt(env, 9); // subs2
    v_19480 = (*qfn1(fn))(fn, v_19480);
    env = stack[-4];
    stack[-2] = v_19480;
    ;}  // end of a binding scope
    v_19480 = stack[-2];
    {
        fn = elt(env, 10); // mk!*sq
        return (*qfn1(fn))(fn, v_19480);
    }
v_19387:
    return onevalue(v_19480);
}



// Code for ratfunpri1

static LispObject CC_ratfunpri1(LispObject env,
                         LispObject v_19381)
{
    env = qenv(env);
    LispObject v_19798, v_19799, v_19800;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19381);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[0] = v_19381;
// end of prologue
    goto v_19407;
v_19403:
    v_19799 = qvalue(elt(env, 1)); // spare!*
    goto v_19404;
v_19405:
    v_19798 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_19406;
v_19407:
    goto v_19403;
v_19404:
    goto v_19405;
v_19406:
    v_19798 = plus2(v_19799, v_19798);
    env = stack[-8];
    qvalue(elt(env, 1)) = v_19798; // spare!*
    goto v_19422;
v_19416:
    v_19798 = stack[0];
    v_19798 = qcdr(v_19798);
    v_19800 = qcar(v_19798);
    goto v_19417;
v_19418:
    v_19799 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19419;
v_19420:
    v_19798 = nil;
    goto v_19421;
v_19422:
    goto v_19416;
v_19417:
    goto v_19418;
v_19419:
    goto v_19420;
v_19421:
    fn = elt(env, 13); // layout!-formula
    v_19798 = (*qfnn(fn))(fn, 3, v_19800, v_19799, v_19798);
    env = stack[-8];
    stack[-7] = v_19798;
    if (v_19798 == nil) goto v_19413;
    goto v_19436;
v_19430:
    v_19798 = stack[0];
    v_19798 = qcdr(v_19798);
    v_19798 = qcdr(v_19798);
    v_19800 = qcar(v_19798);
    goto v_19431;
v_19432:
    v_19799 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19433;
v_19434:
    v_19798 = nil;
    goto v_19435;
v_19436:
    goto v_19430;
v_19431:
    goto v_19432;
v_19433:
    goto v_19434;
v_19435:
    fn = elt(env, 13); // layout!-formula
    v_19798 = (*qfnn(fn))(fn, 3, v_19800, v_19799, v_19798);
    env = stack[-8];
    stack[-6] = v_19798;
    if (v_19798 == nil) goto v_19413;
    goto v_19448;
v_19444:
    v_19799 = qvalue(elt(env, 1)); // spare!*
    goto v_19445;
v_19446:
    v_19798 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_19447;
v_19448:
    goto v_19444;
v_19445:
    goto v_19446;
v_19447:
    v_19798 = difference2(v_19799, v_19798);
    env = stack[-8];
    qvalue(elt(env, 1)) = v_19798; // spare!*
    goto v_19456;
v_19452:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_19453;
v_19454:
    goto v_19463;
v_19459:
    v_19798 = stack[-7];
    v_19798 = qcar(v_19798);
    v_19799 = qcdr(v_19798);
    goto v_19460;
v_19461:
    v_19798 = stack[-6];
    v_19798 = qcar(v_19798);
    v_19798 = qcdr(v_19798);
    goto v_19462;
v_19463:
    goto v_19459;
v_19460:
    goto v_19461;
v_19462:
    fn = elt(env, 14); // max
    v_19798 = (*qfn2(fn))(fn, v_19799, v_19798);
    env = stack[-8];
    goto v_19455;
v_19456:
    goto v_19452;
v_19453:
    goto v_19454;
v_19455:
    v_19798 = plus2(stack[0], v_19798);
    env = stack[-8];
    stack[-2] = v_19798;
    goto v_19479;
v_19475:
    stack[0] = stack[-2];
    goto v_19476;
v_19477:
    goto v_19486;
v_19482:
    goto v_19492;
v_19488:
    v_19798 = nil;
    v_19799 = Llinelength(nil, v_19798);
    env = stack[-8];
    goto v_19489;
v_19490:
    v_19798 = qvalue(elt(env, 1)); // spare!*
    goto v_19491;
v_19492:
    goto v_19488;
v_19489:
    goto v_19490;
v_19491:
    v_19799 = difference2(v_19799, v_19798);
    env = stack[-8];
    goto v_19483;
v_19484:
    v_19798 = qvalue(elt(env, 2)); // posn!*
    goto v_19485;
v_19486:
    goto v_19482;
v_19483:
    goto v_19484;
v_19485:
    v_19798 = difference2(v_19799, v_19798);
    env = stack[-8];
    goto v_19478;
v_19479:
    goto v_19475;
v_19476:
    goto v_19477;
v_19478:
    v_19798 = (LispObject)greaterp2(stack[0], v_19798);
    v_19798 = v_19798 ? lisp_true : nil;
    env = stack[-8];
    if (v_19798 == nil) goto v_19473;
    v_19798 = lisp_true;
    fn = elt(env, 15); // terpri!*
    v_19798 = (*qfn1(fn))(fn, v_19798);
    env = stack[-8];
    goto v_19471;
v_19473:
v_19471:
    goto v_19504;
v_19500:
    v_19798 = stack[-7];
    v_19798 = qcar(v_19798);
    v_19799 = qcdr(v_19798);
    goto v_19501;
v_19502:
    v_19798 = stack[-6];
    v_19798 = qcar(v_19798);
    v_19798 = qcdr(v_19798);
    goto v_19503;
v_19504:
    goto v_19500;
v_19501:
    goto v_19502;
v_19503:
    v_19798 = difference2(v_19799, v_19798);
    env = stack[-8];
    stack[-1] = v_19798;
    goto v_19520;
v_19516:
    v_19799 = stack[-1];
    goto v_19517;
v_19518:
    v_19798 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19519;
v_19520:
    goto v_19516;
v_19517:
    goto v_19518;
v_19519:
    v_19798 = (LispObject)greaterp2(v_19799, v_19798);
    v_19798 = v_19798 ? lisp_true : nil;
    env = stack[-8];
    if (v_19798 == nil) goto v_19514;
    v_19798 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_19798;
    goto v_19529;
v_19525:
    v_19799 = stack[-1];
    goto v_19526;
v_19527:
    v_19798 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_19528;
v_19529:
    goto v_19525;
v_19526:
    goto v_19527;
v_19528:
    v_19798 = quot2(v_19799, v_19798);
    env = stack[-8];
    stack[-3] = v_19798;
    goto v_19512;
v_19514:
    goto v_19539;
v_19535:
    v_19798 = stack[-1];
    v_19799 = negate(v_19798);
    env = stack[-8];
    goto v_19536;
v_19537:
    v_19798 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_19538;
v_19539:
    goto v_19535;
v_19536:
    goto v_19537;
v_19538:
    v_19798 = quot2(v_19799, v_19798);
    env = stack[-8];
    stack[0] = v_19798;
    v_19798 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_19798;
    goto v_19512;
v_19512:
    goto v_19550;
v_19546:
    v_19798 = stack[-7];
    v_19798 = qcdr(v_19798);
    v_19799 = qcdr(v_19798);
    goto v_19547;
v_19548:
    v_19798 = stack[-7];
    v_19798 = qcdr(v_19798);
    v_19798 = qcar(v_19798);
    goto v_19549;
v_19550:
    goto v_19546;
v_19547:
    goto v_19548;
v_19549:
    v_19798 = difference2(v_19799, v_19798);
    env = stack[-8];
    v_19798 = add1(v_19798);
    env = stack[-8];
    stack[-5] = v_19798;
    goto v_19563;
v_19559:
    v_19798 = stack[-6];
    v_19798 = qcdr(v_19798);
    v_19799 = qcdr(v_19798);
    goto v_19560;
v_19561:
    v_19798 = stack[-6];
    v_19798 = qcdr(v_19798);
    v_19798 = qcar(v_19798);
    goto v_19562;
v_19563:
    goto v_19559;
v_19560:
    goto v_19561;
v_19562:
    v_19798 = difference2(v_19799, v_19798);
    env = stack[-8];
    v_19798 = add1(v_19798);
    env = stack[-8];
    stack[-4] = v_19798;
    goto v_19575;
v_19571:
    goto v_19583;
v_19577:
    goto v_19589;
v_19585:
    stack[-1] = stack[0];
    goto v_19586;
v_19587:
    goto v_19596;
v_19592:
    stack[0] = qvalue(elt(env, 2)); // posn!*
    goto v_19593;
v_19594:
    goto v_19603;
v_19599:
    v_19799 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19600;
v_19601:
    v_19798 = qvalue(elt(env, 3)); // orig!*
    goto v_19602;
v_19603:
    goto v_19599;
v_19600:
    goto v_19601;
v_19602:
    v_19798 = difference2(v_19799, v_19798);
    env = stack[-8];
    goto v_19595;
v_19596:
    goto v_19592;
v_19593:
    goto v_19594;
v_19595:
    v_19798 = plus2(stack[0], v_19798);
    env = stack[-8];
    goto v_19588;
v_19589:
    goto v_19585;
v_19586:
    goto v_19587;
v_19588:
    stack[0] = plus2(stack[-1], v_19798);
    env = stack[-8];
    goto v_19578;
v_19579:
    goto v_19611;
v_19607:
    goto v_19617;
v_19613:
    v_19799 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19614;
v_19615:
    v_19798 = stack[-7];
    v_19798 = qcdr(v_19798);
    v_19798 = qcar(v_19798);
    goto v_19616;
v_19617:
    goto v_19613;
v_19614:
    goto v_19615;
v_19616:
    v_19799 = difference2(v_19799, v_19798);
    env = stack[-8];
    goto v_19608;
v_19609:
    v_19798 = qvalue(elt(env, 4)); // ycoord!*
    goto v_19610;
v_19611:
    goto v_19607;
v_19608:
    goto v_19609;
v_19610:
    v_19799 = plus2(v_19799, v_19798);
    env = stack[-8];
    goto v_19580;
v_19581:
    v_19798 = stack[-7];
    v_19798 = qcar(v_19798);
    v_19798 = qcar(v_19798);
    goto v_19582;
v_19583:
    goto v_19577;
v_19578:
    goto v_19579;
v_19580:
    goto v_19581;
v_19582:
    fn = elt(env, 16); // update!-pline
    stack[-1] = (*qfnn(fn))(fn, 3, stack[0], v_19799, v_19798);
    env = stack[-8];
    goto v_19572;
v_19573:
    goto v_19631;
v_19627:
    goto v_19639;
v_19633:
    goto v_19645;
v_19641:
    goto v_19642;
v_19643:
    goto v_19652;
v_19648:
    stack[0] = qvalue(elt(env, 2)); // posn!*
    goto v_19649;
v_19650:
    goto v_19659;
v_19655:
    v_19799 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19656;
v_19657:
    v_19798 = qvalue(elt(env, 3)); // orig!*
    goto v_19658;
v_19659:
    goto v_19655;
v_19656:
    goto v_19657;
v_19658:
    v_19798 = difference2(v_19799, v_19798);
    env = stack[-8];
    goto v_19651;
v_19652:
    goto v_19648;
v_19649:
    goto v_19650;
v_19651:
    v_19798 = plus2(stack[0], v_19798);
    env = stack[-8];
    goto v_19644;
v_19645:
    goto v_19641;
v_19642:
    goto v_19643;
v_19644:
    stack[0] = plus2(stack[-3], v_19798);
    env = stack[-8];
    goto v_19634;
v_19635:
    goto v_19668;
v_19664:
    v_19799 = qvalue(elt(env, 4)); // ycoord!*
    goto v_19665;
v_19666:
    v_19798 = stack[-6];
    v_19798 = qcdr(v_19798);
    v_19798 = qcdr(v_19798);
    goto v_19667;
v_19668:
    goto v_19664;
v_19665:
    goto v_19666;
v_19667:
    v_19798 = difference2(v_19799, v_19798);
    env = stack[-8];
    v_19799 = sub1(v_19798);
    env = stack[-8];
    goto v_19636;
v_19637:
    v_19798 = stack[-6];
    v_19798 = qcar(v_19798);
    v_19798 = qcar(v_19798);
    goto v_19638;
v_19639:
    goto v_19633;
v_19634:
    goto v_19635;
v_19636:
    goto v_19637;
v_19638:
    fn = elt(env, 16); // update!-pline
    v_19799 = (*qfnn(fn))(fn, 3, stack[0], v_19799, v_19798);
    env = stack[-8];
    goto v_19628;
v_19629:
    v_19798 = qvalue(elt(env, 5)); // pline!*
    goto v_19630;
v_19631:
    goto v_19627;
v_19628:
    goto v_19629;
v_19630:
    v_19798 = Lappend(nil, v_19799, v_19798);
    env = stack[-8];
    goto v_19574;
v_19575:
    goto v_19571;
v_19572:
    goto v_19573;
v_19574:
    v_19798 = Lappend(nil, stack[-1], v_19798);
    env = stack[-8];
    qvalue(elt(env, 5)) = v_19798; // pline!*
    goto v_19682;
v_19678:
    stack[0] = qvalue(elt(env, 6)); // ymin!*
    goto v_19679;
v_19680:
    goto v_19689;
v_19685:
    v_19799 = qvalue(elt(env, 4)); // ycoord!*
    goto v_19686;
v_19687:
    v_19798 = stack[-4];
    goto v_19688;
v_19689:
    goto v_19685;
v_19686:
    goto v_19687;
v_19688:
    v_19798 = difference2(v_19799, v_19798);
    env = stack[-8];
    goto v_19681;
v_19682:
    goto v_19678;
v_19679:
    goto v_19680;
v_19681:
    fn = elt(env, 17); // min
    v_19798 = (*qfn2(fn))(fn, stack[0], v_19798);
    env = stack[-8];
    qvalue(elt(env, 6)) = v_19798; // ymin!*
    goto v_19697;
v_19693:
    stack[0] = qvalue(elt(env, 7)); // ymax!*
    goto v_19694;
v_19695:
    goto v_19704;
v_19700:
    v_19799 = qvalue(elt(env, 4)); // ycoord!*
    goto v_19701;
v_19702:
    v_19798 = stack[-5];
    goto v_19703;
v_19704:
    goto v_19700;
v_19701:
    goto v_19702;
v_19703:
    v_19798 = plus2(v_19799, v_19798);
    env = stack[-8];
    goto v_19696;
v_19697:
    goto v_19693;
v_19694:
    goto v_19695;
v_19696:
    fn = elt(env, 14); // max
    v_19798 = (*qfn2(fn))(fn, stack[0], v_19798);
    env = stack[-8];
    qvalue(elt(env, 7)) = v_19798; // ymax!*
    v_19798 = elt(env, 8); // bar
    fn = elt(env, 18); // symbol
    v_19798 = (*qfn1(fn))(fn, v_19798);
    env = stack[-8];
    stack[-1] = v_19798;
    v_19798 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_19798;
v_19712:
    goto v_19724;
v_19720:
    v_19799 = stack[-2];
    goto v_19721;
v_19722:
    v_19798 = stack[0];
    goto v_19723;
v_19724:
    goto v_19720;
v_19721:
    goto v_19722;
v_19723:
    v_19798 = difference2(v_19799, v_19798);
    env = stack[-8];
    v_19798 = Lminusp(nil, v_19798);
    env = stack[-8];
    if (v_19798 == nil) goto v_19717;
    goto v_19711;
v_19717:
    v_19798 = stack[-1];
    fn = elt(env, 19); // prin2!*
    v_19798 = (*qfn1(fn))(fn, v_19798);
    env = stack[-8];
    v_19798 = stack[0];
    v_19798 = add1(v_19798);
    env = stack[-8];
    stack[0] = v_19798;
    goto v_19712;
v_19711:
    goto v_19411;
v_19413:
    goto v_19739;
v_19735:
    v_19799 = qvalue(elt(env, 1)); // spare!*
    goto v_19736;
v_19737:
    v_19798 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_19738;
v_19739:
    goto v_19735;
v_19736:
    goto v_19737;
v_19738:
    v_19798 = difference2(v_19799, v_19798);
    env = stack[-8];
    qvalue(elt(env, 1)) = v_19798; // spare!*
    v_19798 = stack[0];
    v_19798 = qcdr(v_19798);
    stack[0] = v_19798;
    v_19798 = elt(env, 9); // quotient
    if (!symbolp(v_19798)) v_19798 = nil;
    else { v_19798 = qfastgets(v_19798);
           if (v_19798 != nil) { v_19798 = elt(v_19798, 23); // infix
#ifdef RECORD_GET
             if (v_19798 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_19798 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_19798 == SPID_NOPROP) v_19798 = nil; }}
#endif
    stack[-2] = v_19798;
    v_19798 = qvalue(elt(env, 10)); // p!*!*
    if (v_19798 == nil) goto v_19749;
    goto v_19756;
v_19752:
    v_19799 = qvalue(elt(env, 10)); // p!*!*
    goto v_19753;
v_19754:
    v_19798 = stack[-2];
    goto v_19755;
v_19756:
    goto v_19752;
v_19753:
    goto v_19754;
v_19755:
    v_19798 = (LispObject)greaterp2(v_19799, v_19798);
    v_19798 = v_19798 ? lisp_true : nil;
    env = stack[-8];
    stack[-1] = v_19798;
    goto v_19747;
v_19749:
    v_19798 = nil;
    stack[-1] = v_19798;
    goto v_19747;
v_19747:
    v_19798 = stack[-1];
    if (v_19798 == nil) goto v_19765;
    v_19798 = elt(env, 11); // "("
    fn = elt(env, 19); // prin2!*
    v_19798 = (*qfn1(fn))(fn, v_19798);
    env = stack[-8];
    goto v_19763;
v_19765:
v_19763:
    goto v_19774;
v_19770:
    v_19798 = stack[0];
    v_19799 = qcar(v_19798);
    goto v_19771;
v_19772:
    v_19798 = stack[-2];
    goto v_19773;
v_19774:
    goto v_19770;
v_19771:
    goto v_19772;
v_19773:
    fn = elt(env, 20); // maprint
    v_19798 = (*qfn2(fn))(fn, v_19799, v_19798);
    env = stack[-8];
    v_19798 = elt(env, 9); // quotient
    fn = elt(env, 21); // oprin
    v_19798 = (*qfn1(fn))(fn, v_19798);
    env = stack[-8];
    goto v_19785;
v_19781:
    v_19798 = stack[0];
    v_19798 = qcdr(v_19798);
    v_19798 = qcar(v_19798);
    fn = elt(env, 22); // negnumberchk
    v_19799 = (*qfn1(fn))(fn, v_19798);
    env = stack[-8];
    goto v_19782;
v_19783:
    v_19798 = stack[-2];
    goto v_19784;
v_19785:
    goto v_19781;
v_19782:
    goto v_19783;
v_19784:
    fn = elt(env, 20); // maprint
    v_19798 = (*qfn2(fn))(fn, v_19799, v_19798);
    env = stack[-8];
    v_19798 = stack[-1];
    if (v_19798 == nil) goto v_19794;
    v_19798 = elt(env, 12); // ")"
    fn = elt(env, 19); // prin2!*
    v_19798 = (*qfn1(fn))(fn, v_19798);
    goto v_19792;
v_19794:
v_19792:
    goto v_19411;
v_19411:
    v_19798 = nil;
    return onevalue(v_19798);
}



// Code for !*f2di

static LispObject CC_Hf2di(LispObject env,
                         LispObject v_19382, LispObject v_19383)
{
    env = qenv(env);
    LispObject v_19615, v_19616;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19383,v_19382);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19382,v_19383);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    v_19615 = v_19383;
    stack[-5] = v_19382;
// end of prologue
// Binding varlist!*
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
    qvalue(elt(env, 1)) = v_19615; // varlist!*
    v_19615 = stack[-5];
    if (v_19615 == nil) goto v_19391;
    else goto v_19392;
v_19391:
    v_19615 = nil;
    goto v_19390;
v_19392:
    v_19615 = stack[-5];
    if (!consp(v_19615)) goto v_19399;
    else goto v_19400;
v_19399:
    v_19615 = lisp_true;
    goto v_19398;
v_19400:
    v_19615 = stack[-5];
    v_19615 = qcar(v_19615);
    v_19615 = (consp(v_19615) ? nil : lisp_true);
    goto v_19398;
    v_19615 = nil;
v_19398:
    if (v_19615 == nil) goto v_19396;
    goto v_19414;
v_19410:
    v_19615 = qvalue(elt(env, 1)); // varlist!*
    stack[-3] = v_19615;
    v_19615 = stack[-3];
    if (v_19615 == nil) goto v_19425;
    else goto v_19426;
v_19425:
    v_19615 = nil;
    goto v_19420;
v_19426:
    v_19615 = (LispObject)0+TAG_FIXNUM; // 0
    v_19615 = ncons(v_19615);
    env = stack[-7];
    stack[-1] = v_19615;
    stack[-2] = v_19615;
v_19421:
    v_19615 = stack[-3];
    v_19615 = qcdr(v_19615);
    stack[-3] = v_19615;
    v_19615 = stack[-3];
    if (v_19615 == nil) goto v_19438;
    else goto v_19439;
v_19438:
    v_19615 = stack[-2];
    goto v_19420;
v_19439:
    goto v_19447;
v_19443:
    stack[0] = stack[-1];
    goto v_19444;
v_19445:
    v_19615 = (LispObject)0+TAG_FIXNUM; // 0
    v_19615 = ncons(v_19615);
    env = stack[-7];
    goto v_19446;
v_19447:
    goto v_19443;
v_19444:
    goto v_19445;
v_19446:
    v_19615 = Lrplacd(nil, stack[0], v_19615);
    env = stack[-7];
    v_19615 = stack[-1];
    v_19615 = qcdr(v_19615);
    stack[-1] = v_19615;
    goto v_19421;
v_19420:
    fn = elt(env, 2); // addgt
    v_19616 = (*qfn1(fn))(fn, v_19615);
    env = stack[-7];
    goto v_19411;
v_19412:
    v_19615 = stack[-5];
    goto v_19413;
v_19414:
    goto v_19410;
v_19411:
    goto v_19412;
v_19413:
    v_19615 = cons(v_19616, v_19615);
    env = stack[-7];
    v_19615 = ncons(v_19615);
    goto v_19390;
v_19396:
    goto v_19464;
v_19460:
    goto v_19473;
v_19469:
    v_19615 = stack[-5];
    v_19615 = qcar(v_19615);
    v_19615 = qcar(v_19615);
    v_19616 = qcar(v_19615);
    goto v_19470;
v_19471:
    v_19615 = qvalue(elt(env, 1)); // varlist!*
    goto v_19472;
v_19473:
    goto v_19469;
v_19470:
    goto v_19471;
v_19472:
    v_19615 = Lmember(nil, v_19616, v_19615);
    if (v_19615 == nil) goto v_19468;
    goto v_19485;
v_19481:
    goto v_19491;
v_19487:
    v_19615 = stack[-5];
    v_19615 = qcar(v_19615);
    v_19616 = qcdr(v_19615);
    goto v_19488;
v_19489:
    v_19615 = qvalue(elt(env, 1)); // varlist!*
    goto v_19490;
v_19491:
    goto v_19487;
v_19488:
    goto v_19489;
v_19490:
    stack[-4] = CC_Hf2di(elt(env, 0), v_19616, v_19615);
    env = stack[-7];
    goto v_19482;
v_19483:
    v_19615 = qvalue(elt(env, 1)); // varlist!*
    stack[-3] = v_19615;
    v_19615 = stack[-3];
    if (v_19615 == nil) goto v_19506;
    else goto v_19507;
v_19506:
    v_19615 = nil;
    goto v_19501;
v_19507:
    v_19615 = stack[-3];
    v_19615 = qcar(v_19615);
    goto v_19522;
v_19518:
    v_19616 = v_19615;
    goto v_19519;
v_19520:
    v_19615 = stack[-5];
    v_19615 = qcar(v_19615);
    v_19615 = qcar(v_19615);
    v_19615 = qcar(v_19615);
    goto v_19521;
v_19522:
    goto v_19518;
v_19519:
    goto v_19520;
v_19521:
    if (equal(v_19616, v_19615)) goto v_19516;
    else goto v_19517;
v_19516:
    v_19615 = stack[-5];
    v_19615 = qcar(v_19615);
    v_19615 = qcar(v_19615);
    v_19615 = qcdr(v_19615);
    goto v_19515;
v_19517:
    v_19615 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19515;
    v_19615 = nil;
v_19515:
    v_19615 = ncons(v_19615);
    env = stack[-7];
    stack[-1] = v_19615;
    stack[-2] = v_19615;
v_19502:
    v_19615 = stack[-3];
    v_19615 = qcdr(v_19615);
    stack[-3] = v_19615;
    v_19615 = stack[-3];
    if (v_19615 == nil) goto v_19539;
    else goto v_19540;
v_19539:
    v_19615 = stack[-2];
    goto v_19501;
v_19540:
    goto v_19548;
v_19544:
    stack[0] = stack[-1];
    goto v_19545;
v_19546:
    v_19615 = stack[-3];
    v_19615 = qcar(v_19615);
    goto v_19562;
v_19558:
    v_19616 = v_19615;
    goto v_19559;
v_19560:
    v_19615 = stack[-5];
    v_19615 = qcar(v_19615);
    v_19615 = qcar(v_19615);
    v_19615 = qcar(v_19615);
    goto v_19561;
v_19562:
    goto v_19558;
v_19559:
    goto v_19560;
v_19561:
    if (equal(v_19616, v_19615)) goto v_19556;
    else goto v_19557;
v_19556:
    v_19615 = stack[-5];
    v_19615 = qcar(v_19615);
    v_19615 = qcar(v_19615);
    v_19615 = qcdr(v_19615);
    goto v_19555;
v_19557:
    v_19615 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19555;
    v_19615 = nil;
v_19555:
    v_19615 = ncons(v_19615);
    env = stack[-7];
    goto v_19547;
v_19548:
    goto v_19544;
v_19545:
    goto v_19546;
v_19547:
    v_19615 = Lrplacd(nil, stack[0], v_19615);
    env = stack[-7];
    v_19615 = stack[-1];
    v_19615 = qcdr(v_19615);
    stack[-1] = v_19615;
    goto v_19502;
v_19501:
    fn = elt(env, 2); // addgt
    v_19615 = (*qfn1(fn))(fn, v_19615);
    env = stack[-7];
    goto v_19484;
v_19485:
    goto v_19481;
v_19482:
    goto v_19483;
v_19484:
    fn = elt(env, 3); // pdmult
    v_19615 = (*qfn2(fn))(fn, stack[-4], v_19615);
    env = stack[-7];
    stack[0] = v_19615;
    goto v_19466;
v_19468:
    goto v_19584;
v_19580:
    goto v_19590;
v_19586:
    v_19615 = stack[-5];
    v_19615 = qcar(v_19615);
    v_19616 = qcdr(v_19615);
    goto v_19587;
v_19588:
    v_19615 = qvalue(elt(env, 1)); // varlist!*
    goto v_19589;
v_19590:
    goto v_19586;
v_19587:
    goto v_19588;
v_19589:
    stack[0] = CC_Hf2di(elt(env, 0), v_19616, v_19615);
    env = stack[-7];
    goto v_19581;
v_19582:
    goto v_19601;
v_19597:
    v_19615 = stack[-5];
    v_19615 = qcar(v_19615);
    v_19616 = qcar(v_19615);
    goto v_19598;
v_19599:
    v_19615 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19600;
v_19601:
    goto v_19597;
v_19598:
    goto v_19599;
v_19600:
    v_19615 = cons(v_19616, v_19615);
    env = stack[-7];
    v_19615 = ncons(v_19615);
    env = stack[-7];
    goto v_19583;
v_19584:
    goto v_19580;
v_19581:
    goto v_19582;
v_19583:
    fn = elt(env, 4); // pcmult
    v_19615 = (*qfn2(fn))(fn, stack[0], v_19615);
    env = stack[-7];
    stack[0] = v_19615;
    goto v_19466;
    stack[0] = nil;
v_19466:
    goto v_19461;
v_19462:
    goto v_19611;
v_19607:
    v_19615 = stack[-5];
    v_19616 = qcdr(v_19615);
    goto v_19608;
v_19609:
    v_19615 = qvalue(elt(env, 1)); // varlist!*
    goto v_19610;
v_19611:
    goto v_19607;
v_19608:
    goto v_19609;
v_19610:
    v_19615 = CC_Hf2di(elt(env, 0), v_19616, v_19615);
    env = stack[-7];
    goto v_19463;
v_19464:
    goto v_19460;
v_19461:
    goto v_19462;
v_19463:
    fn = elt(env, 5); // psum
    v_19615 = (*qfn2(fn))(fn, stack[0], v_19615);
    goto v_19390;
    v_19615 = nil;
v_19390:
    ;}  // end of a binding scope
    return onevalue(v_19615);
}



// Code for list_is_all_free

static LispObject CC_list_is_all_free(LispObject env,
                         LispObject v_19381)
{
    env = qenv(env);
    LispObject v_19402;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19381);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_19381;
// end of prologue
v_19385:
    v_19402 = stack[0];
    if (v_19402 == nil) goto v_19388;
    else goto v_19389;
v_19388:
    v_19402 = lisp_true;
    goto v_19384;
v_19389:
    v_19402 = stack[0];
    v_19402 = qcar(v_19402);
    fn = elt(env, 1); // nodum_varp
    v_19402 = (*qfn1(fn))(fn, v_19402);
    env = stack[-1];
    if (v_19402 == nil) goto v_19393;
    v_19402 = stack[0];
    v_19402 = qcdr(v_19402);
    stack[0] = v_19402;
    goto v_19385;
v_19393:
    v_19402 = nil;
    goto v_19384;
    v_19402 = nil;
v_19384:
    return onevalue(v_19402);
}



// Code for msolve!-poly1

static LispObject CC_msolveKpoly1(LispObject env,
                         LispObject v_19381, LispObject v_19382)
{
    env = qenv(env);
    LispObject v_19685, v_19686, v_19687;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19382,v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19381,v_19382);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_19382;
    stack[-5] = v_19381;
// end of prologue
    v_19685 = stack[-5];
    if (!consp(v_19685)) goto v_19396;
    else goto v_19397;
v_19396:
    v_19685 = lisp_true;
    goto v_19395;
v_19397:
    v_19685 = stack[-5];
    v_19685 = qcar(v_19685);
    v_19685 = (consp(v_19685) ? nil : lisp_true);
    goto v_19395;
    v_19685 = nil;
v_19395:
    if (v_19685 == nil) goto v_19393;
    goto v_19391;
v_19393:
    goto v_19412;
v_19408:
    v_19685 = stack[-5];
    v_19685 = qcar(v_19685);
    v_19685 = qcar(v_19685);
    v_19686 = qcdr(v_19685);
    goto v_19409;
v_19410:
    v_19685 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19411;
v_19412:
    goto v_19408;
v_19409:
    goto v_19410;
v_19411:
    if (v_19686 == v_19685) goto v_19406;
    else goto v_19407;
v_19406:
    v_19685 = stack[-5];
    v_19685 = qcar(v_19685);
    v_19685 = qcdr(v_19685);
    fn = elt(env, 4); // safe!-modrecip
    v_19685 = (*qfn1(fn))(fn, v_19685);
    env = stack[-7];
    stack[0] = v_19685;
    v_19685 = nil;
    qvalue(elt(env, 1)) = v_19685; // erfg!*
    v_19685 = stack[0];
    if (v_19685 == nil) goto v_19425;
    else goto v_19426;
v_19425:
    goto v_19388;
v_19426:
    goto v_19434;
v_19430:
    goto v_19431;
v_19432:
    v_19685 = stack[-5];
    v_19685 = qcdr(v_19685);
    fn = elt(env, 5); // negf
    v_19685 = (*qfn1(fn))(fn, v_19685);
    env = stack[-7];
    goto v_19433;
v_19434:
    goto v_19430;
v_19431:
    goto v_19432;
v_19433:
    fn = elt(env, 6); // multf
    v_19685 = (*qfn2(fn))(fn, stack[0], v_19685);
    env = stack[-7];
    fn = elt(env, 7); // moduntag
    v_19685 = (*qfn1(fn))(fn, v_19685);
    env = stack[-7];
    stack[0] = v_19685;
    v_19685 = stack[0];
    if (v_19685 == nil) goto v_19442;
    goto v_19452;
v_19448:
    v_19686 = stack[0];
    goto v_19449;
v_19450:
    v_19685 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19451;
v_19452:
    goto v_19448;
v_19449:
    goto v_19450;
v_19451:
    v_19685 = (LispObject)lessp2(v_19686, v_19685);
    v_19685 = v_19685 ? lisp_true : nil;
    env = stack[-7];
    if (v_19685 == nil) goto v_19446;
    else goto v_19445;
v_19446:
    goto v_19461;
v_19457:
    v_19686 = stack[0];
    goto v_19458;
v_19459:
    v_19685 = qvalue(elt(env, 2)); // current!-modulus
    goto v_19460;
v_19461:
    goto v_19457;
v_19458:
    goto v_19459;
v_19460:
    v_19685 = (LispObject)greaterp2(v_19686, v_19685);
    v_19685 = v_19685 ? lisp_true : nil;
    env = stack[-7];
    if (v_19685 == nil) goto v_19455;
    else goto v_19445;
v_19455:
    goto v_19442;
v_19445:
    v_19685 = stack[0];
    fn = elt(env, 8); // general!-modular!-number
    v_19685 = (*qfn1(fn))(fn, v_19685);
    env = stack[-7];
    stack[0] = v_19685;
    goto v_19440;
v_19442:
v_19440:
    v_19685 = stack[0];
    v_19685 = ncons(v_19685);
    env = stack[-7];
    stack[0] = v_19685;
    goto v_19389;
v_19407:
v_19391:
v_19388:
    goto v_19475;
v_19469:
    v_19687 = stack[-5];
    goto v_19470;
v_19471:
    v_19686 = stack[-4];
    goto v_19472;
v_19473:
    v_19685 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19474;
v_19475:
    goto v_19469;
v_19470:
    goto v_19471;
v_19472:
    goto v_19473;
v_19474:
    fn = elt(env, 9); // lowestdeg
    v_19685 = (*qfnn(fn))(fn, 3, v_19687, v_19686, v_19685);
    env = stack[-7];
    stack[-6] = v_19685;
    goto v_19488;
v_19484:
    v_19686 = stack[-6];
    goto v_19485;
v_19486:
    v_19685 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19487;
v_19488:
    goto v_19484;
v_19485:
    goto v_19486;
v_19487:
    v_19685 = (LispObject)greaterp2(v_19686, v_19685);
    v_19685 = v_19685 ? lisp_true : nil;
    env = stack[-7];
    if (v_19685 == nil) goto v_19482;
    goto v_19496;
v_19492:
    stack[0] = stack[-5];
    goto v_19493;
v_19494:
    goto v_19506;
v_19500:
    v_19687 = elt(env, 3); // expt
    goto v_19501;
v_19502:
    v_19686 = stack[-4];
    goto v_19503;
v_19504:
    v_19685 = stack[-6];
    goto v_19505;
v_19506:
    goto v_19500;
v_19501:
    goto v_19502;
v_19503:
    goto v_19504;
v_19505:
    v_19685 = list3(v_19687, v_19686, v_19685);
    env = stack[-7];
    fn = elt(env, 10); // simp
    v_19685 = (*qfn1(fn))(fn, v_19685);
    env = stack[-7];
    v_19685 = qcar(v_19685);
    goto v_19495;
v_19496:
    goto v_19492;
v_19493:
    goto v_19494;
v_19495:
    fn = elt(env, 11); // quotf
    v_19685 = (*qfn2(fn))(fn, stack[0], v_19685);
    env = stack[-7];
    stack[-5] = v_19685;
    goto v_19480;
v_19482:
v_19480:
    v_19685 = stack[-5];
    fn = elt(env, 7); // moduntag
    v_19685 = (*qfn1(fn))(fn, v_19685);
    env = stack[-7];
    fn = elt(env, 12); // general!-reduce!-mod!-p
    v_19685 = (*qfn1(fn))(fn, v_19685);
    env = stack[-7];
    stack[-5] = v_19685;
    v_19685 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_19685;
v_19519:
    goto v_19532;
v_19528:
    v_19685 = qvalue(elt(env, 2)); // current!-modulus
    v_19686 = sub1(v_19685);
    env = stack[-7];
    goto v_19529;
v_19530:
    v_19685 = stack[-3];
    goto v_19531;
v_19532:
    goto v_19528;
v_19529:
    goto v_19530;
v_19531:
    v_19685 = difference2(v_19686, v_19685);
    env = stack[-7];
    v_19685 = Lminusp(nil, v_19685);
    env = stack[-7];
    if (v_19685 == nil) goto v_19525;
    v_19685 = nil;
    goto v_19518;
v_19525:
    goto v_19548;
v_19542:
    v_19687 = stack[-5];
    goto v_19543;
v_19544:
    v_19686 = stack[-4];
    goto v_19545;
v_19546:
    v_19685 = stack[-3];
    goto v_19547;
v_19548:
    goto v_19542;
v_19543:
    goto v_19544;
v_19545:
    goto v_19546;
v_19547:
    fn = elt(env, 13); // general!-evaluate!-mod!-p
    v_19685 = (*qfnn(fn))(fn, 3, v_19687, v_19686, v_19685);
    env = stack[-7];
    if (v_19685 == nil) goto v_19539;
    else goto v_19540;
v_19539:
    v_19685 = stack[-3];
    v_19685 = ncons(v_19685);
    env = stack[-7];
    goto v_19538;
v_19540:
    v_19685 = nil;
v_19538:
    stack[-2] = v_19685;
    v_19685 = stack[-2];
    fn = elt(env, 14); // lastpair
    v_19685 = (*qfn1(fn))(fn, v_19685);
    env = stack[-7];
    stack[-1] = v_19685;
    v_19685 = stack[-3];
    v_19685 = add1(v_19685);
    env = stack[-7];
    stack[-3] = v_19685;
    v_19685 = stack[-1];
    if (!consp(v_19685)) goto v_19560;
    else goto v_19561;
v_19560:
    goto v_19519;
v_19561:
v_19520:
    goto v_19573;
v_19569:
    v_19685 = qvalue(elt(env, 2)); // current!-modulus
    v_19686 = sub1(v_19685);
    env = stack[-7];
    goto v_19570;
v_19571:
    v_19685 = stack[-3];
    goto v_19572;
v_19573:
    goto v_19569;
v_19570:
    goto v_19571;
v_19572:
    v_19685 = difference2(v_19686, v_19685);
    env = stack[-7];
    v_19685 = Lminusp(nil, v_19685);
    env = stack[-7];
    if (v_19685 == nil) goto v_19566;
    v_19685 = stack[-2];
    goto v_19518;
v_19566:
    goto v_19583;
v_19579:
    stack[0] = stack[-1];
    goto v_19580;
v_19581:
    goto v_19596;
v_19590:
    v_19687 = stack[-5];
    goto v_19591;
v_19592:
    v_19686 = stack[-4];
    goto v_19593;
v_19594:
    v_19685 = stack[-3];
    goto v_19595;
v_19596:
    goto v_19590;
v_19591:
    goto v_19592;
v_19593:
    goto v_19594;
v_19595:
    fn = elt(env, 13); // general!-evaluate!-mod!-p
    v_19685 = (*qfnn(fn))(fn, 3, v_19687, v_19686, v_19685);
    env = stack[-7];
    if (v_19685 == nil) goto v_19587;
    else goto v_19588;
v_19587:
    v_19685 = stack[-3];
    v_19685 = ncons(v_19685);
    env = stack[-7];
    goto v_19586;
v_19588:
    v_19685 = nil;
v_19586:
    goto v_19582;
v_19583:
    goto v_19579;
v_19580:
    goto v_19581;
v_19582:
    v_19685 = Lrplacd(nil, stack[0], v_19685);
    env = stack[-7];
    v_19685 = stack[-1];
    fn = elt(env, 14); // lastpair
    v_19685 = (*qfn1(fn))(fn, v_19685);
    env = stack[-7];
    stack[-1] = v_19685;
    v_19685 = stack[-3];
    v_19685 = add1(v_19685);
    env = stack[-7];
    stack[-3] = v_19685;
    goto v_19520;
v_19518:
    stack[0] = v_19685;
    goto v_19615;
v_19611:
    v_19686 = stack[-6];
    goto v_19612;
v_19613:
    v_19685 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19614;
v_19615:
    goto v_19611;
v_19612:
    goto v_19613;
v_19614:
    v_19685 = (LispObject)greaterp2(v_19686, v_19685);
    v_19685 = v_19685 ? lisp_true : nil;
    env = stack[-7];
    if (v_19685 == nil) goto v_19609;
    goto v_19623;
v_19619:
    goto v_19620;
v_19621:
    v_19685 = nil;
    v_19685 = ncons(v_19685);
    env = stack[-7];
    goto v_19622;
v_19623:
    goto v_19619;
v_19620:
    goto v_19621;
v_19622:
    v_19685 = Lappend(nil, stack[0], v_19685);
    env = stack[-7];
    stack[0] = v_19685;
    goto v_19607;
v_19609:
v_19607:
v_19389:
    v_19685 = stack[0];
    stack[-5] = v_19685;
    v_19685 = stack[-5];
    if (v_19685 == nil) goto v_19636;
    else goto v_19637;
v_19636:
    v_19685 = nil;
    goto v_19631;
v_19637:
    v_19685 = stack[-5];
    v_19685 = qcar(v_19685);
    goto v_19650;
v_19646:
    stack[0] = stack[-4];
    goto v_19647;
v_19648:
    fn = elt(env, 15); // prepf
    v_19685 = (*qfn1(fn))(fn, v_19685);
    env = stack[-7];
    goto v_19649;
v_19650:
    goto v_19646;
v_19647:
    goto v_19648;
v_19649:
    v_19685 = cons(stack[0], v_19685);
    env = stack[-7];
    v_19685 = ncons(v_19685);
    env = stack[-7];
    v_19685 = ncons(v_19685);
    env = stack[-7];
    stack[-2] = v_19685;
    stack[-3] = v_19685;
v_19632:
    v_19685 = stack[-5];
    v_19685 = qcdr(v_19685);
    stack[-5] = v_19685;
    v_19685 = stack[-5];
    if (v_19685 == nil) goto v_19658;
    else goto v_19659;
v_19658:
    v_19685 = stack[-3];
    goto v_19631;
v_19659:
    goto v_19667;
v_19663:
    stack[-1] = stack[-2];
    goto v_19664;
v_19665:
    v_19685 = stack[-5];
    v_19685 = qcar(v_19685);
    goto v_19679;
v_19675:
    stack[0] = stack[-4];
    goto v_19676;
v_19677:
    fn = elt(env, 15); // prepf
    v_19685 = (*qfn1(fn))(fn, v_19685);
    env = stack[-7];
    goto v_19678;
v_19679:
    goto v_19675;
v_19676:
    goto v_19677;
v_19678:
    v_19685 = cons(stack[0], v_19685);
    env = stack[-7];
    v_19685 = ncons(v_19685);
    env = stack[-7];
    v_19685 = ncons(v_19685);
    env = stack[-7];
    goto v_19666;
v_19667:
    goto v_19663;
v_19664:
    goto v_19665;
v_19666:
    v_19685 = Lrplacd(nil, stack[-1], v_19685);
    env = stack[-7];
    v_19685 = stack[-2];
    v_19685 = qcdr(v_19685);
    stack[-2] = v_19685;
    goto v_19632;
v_19631:
    return onevalue(v_19685);
}



// Code for reduce!-mod!-eigf

static LispObject CC_reduceKmodKeigf(LispObject env,
                         LispObject v_19381, LispObject v_19382)
{
    env = qenv(env);
    LispObject v_19416, v_19417;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19382,v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19381,v_19382);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_19382;
    v_19416 = v_19381;
// end of prologue
    v_19417 = qvalue(elt(env, 1)); // !*sub2
// Binding !*sub2
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = v_19417; // !*sub2
    goto v_19392;
v_19388:
    goto v_19398;
v_19394:
    v_19417 = v_19416;
    v_19417 = qcar(v_19417);
    stack[0] = qcar(v_19417);
    goto v_19395;
v_19396:
    goto v_19409;
v_19405:
    v_19417 = v_19416;
    v_19417 = qcdr(v_19417);
    goto v_19406;
v_19407:
    v_19416 = qcar(v_19416);
    v_19416 = qcdr(v_19416);
    goto v_19408;
v_19409:
    goto v_19405;
v_19406:
    goto v_19407;
v_19408:
    v_19416 = cons(v_19417, v_19416);
    env = stack[-3];
    fn = elt(env, 2); // cancel
    v_19416 = (*qfn1(fn))(fn, v_19416);
    env = stack[-3];
    fn = elt(env, 3); // negsq
    v_19416 = (*qfn1(fn))(fn, v_19416);
    env = stack[-3];
    goto v_19397;
v_19398:
    goto v_19394;
v_19395:
    goto v_19396;
v_19397:
    v_19417 = cons(stack[0], v_19416);
    env = stack[-3];
    goto v_19389;
v_19390:
    v_19416 = stack[-1];
    goto v_19391;
v_19392:
    goto v_19388;
v_19389:
    goto v_19390;
v_19391:
    fn = elt(env, 4); // reduce!-eival!-powers
    v_19416 = (*qfn2(fn))(fn, v_19417, v_19416);
    env = stack[-3];
    fn = elt(env, 5); // subs2
    v_19416 = (*qfn1(fn))(fn, v_19416);
    ;}  // end of a binding scope
    return onevalue(v_19416);
}



// Code for even_action_term

static LispObject CC_even_action_term(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_19453, v_19454;
    LispObject fn;
    LispObject v_19384, v_19383, v_19382, v_19381;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "even_action_term");
    va_start(aa, nargs);
    v_19381 = va_arg(aa, LispObject);
    v_19382 = va_arg(aa, LispObject);
    v_19383 = va_arg(aa, LispObject);
    v_19384 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_19384,v_19383,v_19382,v_19381);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_19381,v_19382,v_19383,v_19384);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-2] = v_19384;
    stack[-3] = v_19383;
    stack[-4] = v_19382;
    stack[-5] = v_19381;
// end of prologue
    goto v_19391;
v_19387:
    goto v_19401;
v_19393:
    stack[-6] = stack[-5];
    goto v_19394;
v_19395:
    v_19453 = stack[-4];
    stack[-1] = qcar(v_19453);
    goto v_19396;
v_19397:
    stack[0] = stack[-3];
    goto v_19398;
v_19399:
    goto v_19411;
v_19407:
    goto v_19417;
v_19413:
    v_19454 = stack[-2];
    goto v_19414;
v_19415:
    v_19453 = stack[-4];
    v_19453 = qcdr(v_19453);
    goto v_19416;
v_19417:
    goto v_19413;
v_19414:
    goto v_19415;
v_19416:
    fn = elt(env, 1); // multf
    v_19454 = (*qfn2(fn))(fn, v_19454, v_19453);
    env = stack[-7];
    goto v_19408;
v_19409:
    v_19453 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19410;
v_19411:
    goto v_19407;
v_19408:
    goto v_19409;
v_19410:
    v_19453 = cons(v_19454, v_19453);
    env = stack[-7];
    goto v_19400;
v_19401:
    goto v_19393;
v_19394:
    goto v_19395;
v_19396:
    goto v_19397;
v_19398:
    goto v_19399;
v_19400:
    fn = elt(env, 2); // even_action_pow
    stack[-1] = (*qfnn(fn))(fn, 4, stack[-6], stack[-1], stack[0], v_19453);
    env = stack[-7];
    goto v_19388;
v_19389:
    goto v_19431;
v_19423:
    goto v_19424;
v_19425:
    v_19453 = stack[-4];
    stack[0] = qcdr(v_19453);
    goto v_19426;
v_19427:
    goto v_19428;
v_19429:
    goto v_19441;
v_19437:
    goto v_19438;
v_19439:
    goto v_19449;
v_19445:
    v_19453 = stack[-4];
    v_19454 = qcar(v_19453);
    goto v_19446;
v_19447:
    v_19453 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19448;
v_19449:
    goto v_19445;
v_19446:
    goto v_19447;
v_19448:
    v_19453 = cons(v_19454, v_19453);
    env = stack[-7];
    v_19453 = ncons(v_19453);
    env = stack[-7];
    goto v_19440;
v_19441:
    goto v_19437;
v_19438:
    goto v_19439;
v_19440:
    fn = elt(env, 1); // multf
    v_19453 = (*qfn2(fn))(fn, stack[-2], v_19453);
    env = stack[-7];
    goto v_19430;
v_19431:
    goto v_19423;
v_19424:
    goto v_19425;
v_19426:
    goto v_19427;
v_19428:
    goto v_19429;
v_19430:
    fn = elt(env, 3); // even_action_sf
    v_19453 = (*qfnn(fn))(fn, 4, stack[-5], stack[0], stack[-3], v_19453);
    env = stack[-7];
    goto v_19390;
v_19391:
    goto v_19387;
v_19388:
    goto v_19389;
v_19390:
    {
        LispObject v_19462 = stack[-1];
        fn = elt(env, 4); // addsq
        return (*qfn2(fn))(fn, v_19462, v_19453);
    }
}



setup_type const u35_setup[] =
{
    {"matsm1",                  CC_matsm1,      TOO_MANY_1,    WRONG_NO_1},
    {"recaliasbacksubst",       TOO_FEW_2,      CC_recaliasbacksubst,WRONG_NO_2},
    {"amatch",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_amatch},
    {"fieldp",                  CC_fieldp,      TOO_MANY_1,    WRONG_NO_1},
    {"evinvlexcomp",            TOO_FEW_2,      CC_evinvlexcomp,WRONG_NO_2},
    {"color-roads",             TOO_FEW_2,      CC_colorKroads,WRONG_NO_2},
    {"greaterpcdr",             TOO_FEW_2,      CC_greaterpcdr,WRONG_NO_2},
    {"assert_structstat",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_assert_structstat},
    {"subs2chk",                CC_subs2chk,    TOO_MANY_1,    WRONG_NO_1},
    {"fs:prin",                 CC_fsTprin,     TOO_MANY_1,    WRONG_NO_1},
    {"mo_zero?",                CC_mo_zeroW,    TOO_MANY_1,    WRONG_NO_1},
    {"dv_ind2var",              CC_dv_ind2var,  TOO_MANY_1,    WRONG_NO_1},
    {"outer-simpsqrt",          CC_outerKsimpsqrt,TOO_MANY_1,  WRONG_NO_1},
    {"msolve-polyn",            TOO_FEW_2,      CC_msolveKpolyn,WRONG_NO_2},
    {"*a2k",                    CC_Ha2k,        TOO_MANY_1,    WRONG_NO_1},
    {"lalr_warn_shift_reduce_conflict",WRONG_NO_NA,WRONG_NO_NB,(n_args *)CC_lalr_warn_shift_reduce_conflict},
    {"component_action",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_component_action},
    {"plusdf",                  TOO_FEW_2,      CC_plusdf,     WRONG_NO_2},
    {"get*inverse",             TOO_FEW_2,      CC_getHinverse,WRONG_NO_2},
    {"talp_sumd",               CC_talp_sumd,   TOO_MANY_1,    WRONG_NO_1},
    {"cl_susicpknowl",          CC_cl_susicpknowl,TOO_MANY_1,  WRONG_NO_1},
    {"listrd",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_listrd},
    {"delyzz",                  TOO_FEW_2,      CC_delyzz,     WRONG_NO_2},
    {"unplus",                  CC_unplus,      TOO_MANY_1,    WRONG_NO_1},
    {"convprc2",                TOO_FEW_2,      CC_convprc2,   WRONG_NO_2},
    {"po:statep",               CC_poTstatep,   TOO_MANY_1,    WRONG_NO_1},
    {"color-strand",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_colorKstrand},
    {"realvaluedp",             CC_realvaluedp, TOO_MANY_1,    WRONG_NO_1},
    {"subeval1",                TOO_FEW_2,      CC_subeval1,   WRONG_NO_2},
    {"ratfunpri1",              CC_ratfunpri1,  TOO_MANY_1,    WRONG_NO_1},
    {"*f2di",                   TOO_FEW_2,      CC_Hf2di,      WRONG_NO_2},
    {"list_is_all_free",        CC_list_is_all_free,TOO_MANY_1,WRONG_NO_1},
    {"msolve-poly1",            TOO_FEW_2,      CC_msolveKpoly1,WRONG_NO_2},
    {"reduce-mod-eigf",         TOO_FEW_2,      CC_reduceKmodKeigf,WRONG_NO_2},
    {"even_action_term",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_even_action_term},
    {NULL, (one_args *)"u35", (two_args *)"126341 9016441 9363636", 0}
};

// end of generated code
