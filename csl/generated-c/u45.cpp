
// $destdir/u45.c        Machine generated C code

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



// Code for diffp

static LispObject CC_diffp(LispObject env,
                         LispObject v_25634, LispObject v_25635)
{
    env = qenv(env);
    LispObject v_27192, v_27193, v_27194, v_27195, v_27196;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25634,v_25635);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-7] = v_25635;
    stack[-8] = v_25634;
// end of prologue
    stack[0] = nil;
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    stack[-9] = v_27192;
    v_27192 = stack[-8];
    v_27192 = qcar(v_27192);
    stack[-8] = v_27192;
    goto v_25666;
v_25662:
    v_27193 = stack[-9];
    goto v_25663;
v_25664:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25665;
v_25666:
    goto v_25662;
v_25663:
    goto v_25664;
v_25665:
    v_27192 = (LispObject)greaterp2(v_27193, v_27192);
    v_27192 = v_27192 ? lisp_true : nil;
    env = stack[-10];
    if (v_27192 == nil) goto v_25659;
    v_27192 = stack[-8];
    fn = elt(env, 22); // noncomp
    v_27192 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    if (v_27192 == nil) goto v_25659;
    goto v_25677;
v_25673:
    goto v_25683;
v_25679:
    goto v_25690;
v_25686:
    v_27193 = stack[-8];
    goto v_25687;
v_25688:
    v_27192 = stack[-7];
    goto v_25689;
v_25690:
    goto v_25686;
v_25687:
    goto v_25688;
v_25689:
    v_27192 = list2(v_27193, v_27192);
    env = stack[-10];
    fn = elt(env, 23); // simpdf
    stack[-1] = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    goto v_25680;
v_25681:
    goto v_25699;
v_25695:
    stack[0] = stack[-8];
    goto v_25696;
v_25697:
    v_27192 = stack[-9];
    v_27192 = sub1(v_27192);
    env = stack[-10];
    goto v_25698;
v_25699:
    goto v_25695;
v_25696:
    goto v_25697;
v_25698:
    v_27192 = list2(stack[0], v_27192);
    env = stack[-10];
    fn = elt(env, 24); // simpexpt
    v_27192 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    goto v_25682;
v_25683:
    goto v_25679;
v_25680:
    goto v_25681;
v_25682:
    fn = elt(env, 25); // multsq
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_27192);
    env = stack[-10];
    goto v_25674;
v_25675:
    goto v_25708;
v_25704:
    goto v_25714;
v_25710:
    goto v_25721;
v_25717:
    goto v_25727;
v_25723:
    v_27193 = stack[-8];
    goto v_25724;
v_25725:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25726;
v_25727:
    goto v_25723;
v_25724:
    goto v_25725;
v_25726:
    fn = elt(env, 26); // to
    v_27193 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    goto v_25718;
v_25719:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25720;
v_25721:
    goto v_25717;
v_25718:
    goto v_25719;
v_25720:
    v_27192 = cons(v_27193, v_27192);
    env = stack[-10];
    v_27193 = ncons(v_27192);
    env = stack[-10];
    goto v_25711;
v_25712:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25713;
v_25714:
    goto v_25710;
v_25711:
    goto v_25712;
v_25713:
    stack[0] = cons(v_27193, v_27192);
    env = stack[-10];
    goto v_25705;
v_25706:
    goto v_25737;
v_25733:
    goto v_25743;
v_25739:
    stack[-2] = stack[-8];
    goto v_25740;
v_25741:
    v_27192 = stack[-9];
    v_27192 = sub1(v_27192);
    env = stack[-10];
    goto v_25742;
v_25743:
    goto v_25739;
v_25740:
    goto v_25741;
v_25742:
    v_27193 = cons(stack[-2], v_27192);
    env = stack[-10];
    goto v_25734;
v_25735:
    v_27192 = stack[-7];
    goto v_25736;
v_25737:
    goto v_25733;
v_25734:
    goto v_25735;
v_25736:
    v_27192 = CC_diffp(elt(env, 0), v_27193, v_27192);
    env = stack[-10];
    goto v_25707;
v_25708:
    goto v_25704;
v_25705:
    goto v_25706;
v_25707:
    fn = elt(env, 25); // multsq
    v_27192 = (*qfn2(fn))(fn, stack[0], v_27192);
    env = stack[-10];
    goto v_25676;
v_25677:
    goto v_25673;
v_25674:
    goto v_25675;
v_25676:
    {
        LispObject v_27207 = stack[-1];
        fn = elt(env, 27); // addsq
        return (*qfn2(fn))(fn, v_27207, v_27192);
    }
v_25659:
    goto v_25758;
v_25754:
    v_27193 = stack[-8];
    goto v_25755;
v_25756:
    v_27192 = stack[-7];
    goto v_25757;
v_25758:
    goto v_25754;
v_25755:
    goto v_25756;
v_25757:
    if (v_27193 == v_27192) goto v_25752;
    else goto v_25753;
v_25752:
    goto v_25766;
v_25762:
    v_27193 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25763;
v_25764:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25765;
v_25766:
    goto v_25762;
v_25763:
    goto v_25764;
v_25765:
    v_27192 = cons(v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_25751;
v_25753:
    v_27192 = nil;
    goto v_25751;
    v_27192 = nil;
v_25751:
    if (v_27192 == nil) goto v_25749;
    goto v_25647;
v_25749:
    v_27192 = stack[-8];
    if (!consp(v_27192)) goto v_25772;
    else goto v_25773;
v_25772:
    goto v_25648;
v_25773:
    v_27192 = stack[-8];
    v_27192 = qcar(v_27192);
    if (!consp(v_27192)) goto v_25781;
    goto v_25789;
v_25785:
    v_27193 = stack[-8];
    goto v_25786;
v_25787:
    v_27192 = stack[-7];
    goto v_25788;
v_25789:
    goto v_25785;
v_25786:
    goto v_25787;
v_25788:
    fn = elt(env, 28); // difff
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_25779;
v_25781:
    v_27192 = nil;
    goto v_25779;
    v_27192 = nil;
v_25779:
    if (v_27192 == nil) goto v_25777;
    else goto v_25775;
v_25777:
    goto v_25804;
v_25800:
    v_27192 = stack[-8];
    v_27193 = qcar(v_27192);
    goto v_25801;
v_25802:
    v_27192 = elt(env, 1); // !*sq
    goto v_25803;
v_25804:
    goto v_25800;
v_25801:
    goto v_25802;
v_25803:
    if (v_27193 == v_27192) goto v_25798;
    else goto v_25799;
v_25798:
    goto v_25813;
v_25809:
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    v_27193 = qcar(v_27192);
    goto v_25810;
v_25811:
    v_27192 = stack[-7];
    goto v_25812;
v_25813:
    goto v_25809;
v_25810:
    goto v_25811;
v_25812:
    fn = elt(env, 29); // diffsq
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_25797;
v_25799:
    v_27192 = nil;
    goto v_25797;
    v_27192 = nil;
v_25797:
    if (v_27192 == nil) goto v_25795;
    else goto v_25775;
v_25795:
    goto v_25776;
v_25775:
    goto v_25646;
v_25776:
    goto v_25828;
v_25824:
    v_27192 = stack[-8];
    v_27193 = qcar(v_27192);
    goto v_25825;
v_25826:
    v_27192 = elt(env, 2); // dfform
    goto v_25827;
v_25828:
    goto v_25824;
v_25825:
    goto v_25826;
v_25827:
    v_27192 = get(v_27193, v_27192);
    env = stack[-10];
    stack[-6] = v_27192;
    if (v_27192 == nil) goto v_25822;
    goto v_25841;
v_25833:
    v_27195 = stack[-6];
    goto v_25834;
v_25835:
    v_27194 = stack[-8];
    goto v_25836;
v_25837:
    v_27193 = stack[-7];
    goto v_25838;
v_25839:
    v_27192 = stack[-9];
    goto v_25840;
v_25841:
    goto v_25833;
v_25834:
    goto v_25835;
v_25836:
    goto v_25837;
v_25838:
    goto v_25839;
v_25840:
        return Lapply3(nil, 4, v_27195, v_27194, v_27193, v_27192);
v_25822:
    goto v_25853;
v_25849:
    v_27192 = stack[-8];
    stack[-1] = qcar(v_27192);
    goto v_25850;
v_25851:
    v_27192 = stack[-8];
    fn = elt(env, 30); // dfn_prop
    v_27192 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    goto v_25852;
v_25853:
    goto v_25849;
v_25850:
    goto v_25851;
v_25852:
    v_27192 = get(stack[-1], v_27192);
    env = stack[-10];
    stack[-6] = v_27192;
    if (v_27192 == nil) goto v_25847;
    goto v_25657;
v_25847:
    goto v_25869;
v_25865:
    v_27192 = stack[-8];
    v_27193 = qcar(v_27192);
    goto v_25866;
v_25867:
    v_27192 = elt(env, 3); // plus
    goto v_25868;
v_25869:
    goto v_25865;
v_25866:
    goto v_25867;
v_25868:
    if (v_27193 == v_27192) goto v_25863;
    else goto v_25864;
v_25863:
    goto v_25878;
v_25874:
    v_27192 = stack[-8];
    fn = elt(env, 31); // simp
    v_27193 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    goto v_25875;
v_25876:
    v_27192 = stack[-7];
    goto v_25877;
v_25878:
    goto v_25874;
v_25875:
    goto v_25876;
v_25877:
    fn = elt(env, 29); // diffsq
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_25862;
v_25864:
    v_27192 = nil;
    goto v_25862;
    v_27192 = nil;
v_25862:
    if (v_27192 == nil) goto v_25860;
    goto v_25646;
v_25860:
    goto v_25649;
v_25657:
    v_27192 = stack[-6];
    stack[-5] = v_27192;
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    stack[-4] = v_27192;
v_25645:
    goto v_25895;
v_25891:
    goto v_25901;
v_25897:
    v_27192 = stack[-4];
    v_27192 = qcar(v_27192);
    fn = elt(env, 31); // simp
    v_27193 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    goto v_25898;
v_25899:
    v_27192 = stack[-7];
    goto v_25900;
v_25901:
    goto v_25897;
v_25898:
    goto v_25899;
v_25900:
    fn = elt(env, 29); // diffsq
    v_27193 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    goto v_25892;
v_25893:
    v_27192 = stack[0];
    goto v_25894;
v_25895:
    goto v_25891;
v_25892:
    goto v_25893;
v_25894:
    v_27192 = cons(v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    v_27192 = stack[0];
    v_27192 = qcar(v_27192);
    v_27192 = qcar(v_27192);
    if (v_27192 == nil) goto v_25910;
    v_27192 = stack[-5];
    v_27192 = qcar(v_27192);
    if (v_27192 == nil) goto v_25915;
    else goto v_25910;
v_25915:
    goto v_25649;
v_25910:
    v_27192 = stack[-5];
    v_27192 = qcdr(v_27192);
    stack[-5] = v_27192;
    v_27192 = stack[-4];
    v_27192 = qcdr(v_27192);
    stack[-4] = v_27192;
    v_27192 = stack[-4];
    if (v_27192 == nil) goto v_25925;
    v_27192 = stack[-5];
    if (v_27192 == nil) goto v_25925;
    goto v_25645;
v_25925:
    v_27192 = stack[-4];
    if (v_27192 == nil) goto v_25932;
    else goto v_25930;
v_25932:
    v_27192 = stack[-5];
    if (v_27192 == nil) goto v_25934;
    else goto v_25930;
v_25934:
    goto v_25931;
v_25930:
    goto v_25649;
v_25931:
    v_27192 = stack[0];
    v_27192 = Lreverse(nil, v_27192);
    env = stack[-10];
    stack[-5] = v_27192;
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    stack[-4] = v_27192;
    goto v_25945;
v_25941:
    v_27193 = nil;
    goto v_25942;
v_25943:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25944;
v_25945:
    goto v_25941;
v_25942:
    goto v_25943;
v_25944:
    v_27192 = cons(v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
v_25950:
    v_27192 = stack[-5];
    v_27192 = qcar(v_27192);
    v_27192 = qcar(v_27192);
    if (v_27192 == nil) goto v_25954;
    goto v_25963;
v_25959:
    goto v_25969;
v_25965:
    v_27192 = stack[-5];
    stack[-1] = qcar(v_27192);
    goto v_25966;
v_25967:
    goto v_25978;
v_25974:
    goto v_25984;
v_25980:
    v_27192 = stack[-6];
    v_27192 = qcar(v_27192);
    v_27193 = qcar(v_27192);
    goto v_25981;
v_25982:
    v_27192 = stack[-4];
    goto v_25983;
v_25984:
    goto v_25980;
v_25981:
    goto v_25982;
v_25983:
    fn = elt(env, 32); // pair
    v_27193 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    goto v_25975;
v_25976:
    v_27192 = stack[-6];
    v_27192 = qcar(v_27192);
    v_27192 = qcdr(v_27192);
    goto v_25977;
v_25978:
    goto v_25974;
v_25975:
    goto v_25976;
v_25977:
    v_27192 = Lsubla(nil, v_27193, v_27192);
    env = stack[-10];
    fn = elt(env, 31); // simp
    v_27192 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    goto v_25968;
v_25969:
    goto v_25965;
v_25966:
    goto v_25967;
v_25968:
    fn = elt(env, 25); // multsq
    v_27193 = (*qfn2(fn))(fn, stack[-1], v_27192);
    env = stack[-10];
    goto v_25960;
v_25961:
    v_27192 = stack[0];
    goto v_25962;
v_25963:
    goto v_25959;
v_25960:
    goto v_25961;
v_25962:
    fn = elt(env, 27); // addsq
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_25952;
v_25954:
v_25952:
    v_27192 = stack[-6];
    v_27192 = qcdr(v_27192);
    stack[-6] = v_27192;
    v_27192 = stack[-5];
    v_27192 = qcdr(v_27192);
    stack[-5] = v_27192;
    v_27192 = stack[-5];
    if (v_27192 == nil) goto v_26000;
    goto v_25950;
v_26000:
v_25646:
v_25647:
    goto v_26010;
v_26006:
    v_27193 = stack[-8];
    goto v_26007;
v_26008:
    v_27192 = qvalue(elt(env, 4)); // wtl!*
    goto v_26009;
v_26010:
    goto v_26006;
v_26007:
    goto v_26008;
v_26009:
    v_27192 = Latsoc(nil, v_27193, v_27192);
    stack[-6] = v_27192;
    if (v_27192 == nil) goto v_26005;
    goto v_26019;
v_26015:
    goto v_26025;
v_26021:
    goto v_26032;
v_26028:
    goto v_26038;
v_26034:
    stack[-1] = elt(env, 5); // k!*
    goto v_26035;
v_26036:
    v_27192 = stack[-6];
    v_27192 = qcdr(v_27192);
    v_27192 = negate(v_27192);
    env = stack[-10];
    goto v_26037;
v_26038:
    goto v_26034;
v_26035:
    goto v_26036;
v_26037:
    fn = elt(env, 26); // to
    v_27193 = (*qfn2(fn))(fn, stack[-1], v_27192);
    env = stack[-10];
    goto v_26029;
v_26030:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26031;
v_26032:
    goto v_26028;
v_26029:
    goto v_26030;
v_26031:
    v_27192 = cons(v_27193, v_27192);
    env = stack[-10];
    v_27193 = ncons(v_27192);
    env = stack[-10];
    goto v_26022;
v_26023:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26024;
v_26025:
    goto v_26021;
v_26022:
    goto v_26023;
v_26024:
    v_27193 = cons(v_27193, v_27192);
    env = stack[-10];
    goto v_26016;
v_26017:
    v_27192 = stack[0];
    goto v_26018;
v_26019:
    goto v_26015;
v_26016:
    goto v_26017;
v_26018:
    fn = elt(env, 25); // multsq
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_26003;
v_26005:
v_26003:
    v_27192 = stack[-9];
    v_27192 = sub1(v_27192);
    env = stack[-10];
    stack[-3] = v_27192;
    goto v_26057;
v_26053:
    v_27193 = stack[-9];
    goto v_26054;
v_26055:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26056;
v_26057:
    goto v_26053;
v_26054:
    goto v_26055;
v_26056:
    if (v_27193 == v_27192) goto v_26051;
    else goto v_26052;
v_26051:
    v_27192 = stack[0];
    goto v_26050;
v_26052:
    v_27192 = qvalue(elt(env, 6)); // dmode!*
    if (!symbolp(v_27192)) v_27192 = nil;
    else { v_27192 = qfastgets(v_27192);
           if (v_27192 != nil) { v_27192 = elt(v_27192, 5); // convert
#ifdef RECORD_GET
             if (v_27192 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v_27192 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v_27192 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v_27192 == SPID_NOPROP) v_27192 = nil; else v_27192 = lisp_true; }}
#endif
    if (v_27192 == nil) goto v_26066;
    goto v_26075;
v_26071:
    v_27192 = qvalue(elt(env, 6)); // dmode!*
    if (!symbolp(v_27192)) v_27193 = nil;
    else { v_27193 = qfastgets(v_27192);
           if (v_27193 != nil) { v_27193 = elt(v_27193, 34); // i2d
#ifdef RECORD_GET
             if (v_27193 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_27193 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_27193 == SPID_NOPROP) v_27193 = nil; }}
#endif
    goto v_26072;
v_26073:
    v_27192 = stack[-9];
    goto v_26074;
v_26075:
    goto v_26071;
v_26072:
    goto v_26073;
v_26074:
    v_27192 = Lapply1(nil, v_27193, v_27192);
    env = stack[-10];
    fn = elt(env, 33); // int!-equiv!-chk
    v_27192 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    stack[-9] = v_27192;
    v_27192 = (v_27192 == nil ? lisp_true : nil);
    goto v_26064;
v_26066:
    v_27192 = nil;
    goto v_26064;
    v_27192 = nil;
v_26064:
    if (v_27192 == nil) goto v_26062;
    goto v_26088;
v_26084:
    v_27193 = nil;
    goto v_26085;
v_26086:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26087;
v_26088:
    goto v_26084;
v_26085:
    goto v_26086;
v_26087:
    v_27192 = cons(v_27193, v_27192);
    env = stack[-10];
    goto v_26050;
v_26062:
    goto v_26098;
v_26094:
    goto v_26104;
v_26100:
    goto v_26111;
v_26107:
    goto v_26117;
v_26113:
    v_27193 = stack[-8];
    goto v_26114;
v_26115:
    v_27192 = stack[-3];
    goto v_26116;
v_26117:
    goto v_26113;
v_26114:
    goto v_26115;
v_26116:
    fn = elt(env, 26); // to
    v_27193 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    goto v_26108;
v_26109:
    v_27192 = stack[-9];
    goto v_26110;
v_26111:
    goto v_26107;
v_26108:
    goto v_26109;
v_26110:
    v_27192 = cons(v_27193, v_27192);
    env = stack[-10];
    v_27193 = ncons(v_27192);
    env = stack[-10];
    goto v_26101;
v_26102:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26103;
v_26104:
    goto v_26100;
v_26101:
    goto v_26102;
v_26103:
    v_27193 = cons(v_27193, v_27192);
    env = stack[-10];
    goto v_26095;
v_26096:
    v_27192 = stack[0];
    goto v_26097;
v_26098:
    goto v_26094;
v_26095:
    goto v_26096;
v_26097:
    fn = elt(env, 25); // multsq
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    goto v_26050;
    v_27192 = nil;
v_26050:
    {
        fn = elt(env, 34); // rationalizesq
        return (*qfn1(fn))(fn, v_27192);
    }
v_25648:
    goto v_26136;
v_26132:
    v_27193 = stack[-8];
    goto v_26133;
v_26134:
    v_27192 = stack[-7];
    goto v_26135;
v_26136:
    goto v_26132;
v_26133:
    goto v_26134;
v_26135:
    fn = elt(env, 35); // depends
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    if (v_27192 == nil) goto v_26129;
    else goto v_26130;
v_26129:
    goto v_26151;
v_26147:
    v_27193 = stack[-8];
    goto v_26148;
v_26149:
    v_27192 = qvalue(elt(env, 7)); // powlis!*
    goto v_26150;
v_26151:
    goto v_26147;
v_26148:
    goto v_26149;
v_26150:
    v_27192 = Latsoc(nil, v_27193, v_27192);
    stack[-6] = v_27192;
    if (v_27192 == nil) goto v_26145;
    else goto v_26146;
v_26145:
    v_27192 = lisp_true;
    goto v_26144;
v_26146:
    goto v_26163;
v_26159:
    v_27192 = stack[-6];
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    v_27193 = qcar(v_27192);
    goto v_26160;
v_26161:
    v_27192 = stack[-7];
    goto v_26162;
v_26163:
    goto v_26159;
v_26160:
    goto v_26161;
v_26162:
    fn = elt(env, 35); // depends
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    v_27192 = (v_27192 == nil ? lisp_true : nil);
    goto v_26144;
    v_27192 = nil;
v_26144:
    if (v_27192 == nil) goto v_26142;
    v_27192 = qvalue(elt(env, 8)); // !*depend
    v_27192 = (v_27192 == nil ? lisp_true : nil);
    goto v_26140;
v_26142:
    v_27192 = nil;
    goto v_26140;
    v_27192 = nil;
v_26140:
    goto v_26128;
v_26130:
    v_27192 = nil;
    goto v_26128;
    v_27192 = nil;
v_26128:
    if (v_27192 == nil) goto v_26126;
    goto v_26184;
v_26180:
    v_27193 = nil;
    goto v_26181;
v_26182:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26183;
v_26184:
    goto v_26180;
v_26181:
    goto v_26182;
v_26183:
    return cons(v_27193, v_27192);
v_26126:
    v_27192 = qvalue(elt(env, 9)); // !*expanddf
    if (v_27192 == nil) goto v_26190;
    goto v_26206;
v_26202:
    v_27193 = stack[-8];
    goto v_26203;
v_26204:
    v_27192 = qvalue(elt(env, 7)); // powlis!*
    goto v_26205;
v_26206:
    goto v_26202;
v_26203:
    goto v_26204;
v_26205:
    v_27192 = Latsoc(nil, v_27193, v_27192);
    stack[-6] = v_27192;
    if (v_27192 == nil) goto v_26200;
    else goto v_26201;
v_26200:
    v_27192 = lisp_true;
    goto v_26199;
v_26201:
    goto v_26218;
v_26214:
    v_27192 = stack[-6];
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    v_27193 = qcar(v_27192);
    goto v_26215;
v_26216:
    v_27192 = stack[-7];
    goto v_26217;
v_26218:
    goto v_26214;
v_26215:
    goto v_26216;
v_26217:
    fn = elt(env, 35); // depends
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    v_27192 = (v_27192 == nil ? lisp_true : nil);
    goto v_26199;
    v_27192 = nil;
v_26199:
    if (v_27192 == nil) goto v_26197;
    goto v_26234;
v_26230:
    v_27193 = stack[-8];
    goto v_26231;
v_26232:
    v_27192 = qvalue(elt(env, 10)); // depl!*
    goto v_26233;
v_26234:
    goto v_26230;
v_26231:
    goto v_26232;
v_26233:
    v_27192 = Latsoc(nil, v_27193, v_27192);
    stack[-6] = v_27192;
    if (v_27192 == nil) goto v_26228;
    else goto v_26229;
v_26228:
    v_27192 = nil;
    goto v_26227;
v_26229:
    goto v_26245;
v_26241:
    v_27193 = stack[-7];
    goto v_26242;
v_26243:
    v_27192 = stack[-6];
    v_27192 = qcdr(v_27192);
    stack[-6] = v_27192;
    goto v_26244;
v_26245:
    goto v_26241;
v_26242:
    goto v_26243;
v_26244:
    v_27192 = Lmemq(nil, v_27193, v_27192);
    v_27192 = (v_27192 == nil ? lisp_true : nil);
    goto v_26227;
    v_27192 = nil;
v_26227:
    goto v_26195;
v_26197:
    v_27192 = nil;
    goto v_26195;
    v_27192 = nil;
v_26195:
    if (v_27192 == nil) goto v_26190;
    goto v_26261;
v_26255:
    v_27194 = stack[-8];
    goto v_26256;
v_26257:
    v_27193 = stack[-7];
    goto v_26258;
v_26259:
    v_27192 = stack[-6];
    goto v_26260;
v_26261:
    goto v_26255;
v_26256:
    goto v_26257;
v_26258:
    goto v_26259;
v_26260:
    fn = elt(env, 36); // df!-chain!-rule
    v_27192 = (*qfnn(fn))(fn, 3, v_27194, v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_25647;
v_26190:
    goto v_26272;
v_26266:
    v_27194 = elt(env, 11); // df
    goto v_26267;
v_26268:
    v_27193 = stack[-8];
    goto v_26269;
v_26270:
    v_27192 = stack[-7];
    goto v_26271;
v_26272:
    goto v_26266;
v_26267:
    goto v_26268;
v_26269:
    goto v_26270;
v_26271:
    v_27192 = list3(v_27194, v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    v_27192 = stack[0];
    fn = elt(env, 37); // opmtch
    v_27192 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    stack[-6] = v_27192;
    if (v_27192 == nil) goto v_26279;
    v_27192 = stack[-6];
    fn = elt(env, 31); // simp
    v_27192 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    goto v_26277;
v_26279:
    goto v_26291;
v_26287:
    v_27193 = stack[0];
    goto v_26288;
v_26289:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26290;
v_26291:
    goto v_26287;
v_26288:
    goto v_26289;
v_26290:
    fn = elt(env, 38); // mksq
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    goto v_26277;
    v_27192 = nil;
v_26277:
    stack[0] = v_27192;
    goto v_25647;
v_25649:
    goto v_26302;
v_26298:
    v_27192 = stack[-8];
    v_27193 = qcar(v_27192);
    goto v_26299;
v_26300:
    v_27192 = elt(env, 11); // df
    goto v_26301;
v_26302:
    goto v_26298;
v_26299:
    goto v_26300;
v_26301:
    if (v_27193 == v_27192) goto v_26296;
    else goto v_26297;
v_26296:
    goto v_26314;
v_26310:
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    v_27193 = qcar(v_27192);
    goto v_26311;
v_26312:
    v_27192 = stack[-7];
    goto v_26313;
v_26314:
    goto v_26310;
v_26311:
    goto v_26312;
v_26313:
    if (v_27193 == v_27192) goto v_26308;
    else goto v_26309;
v_26308:
    v_27192 = qvalue(elt(env, 12)); // !*commutedf
    if (v_27192 == nil) goto v_26322;
    v_27192 = qvalue(elt(env, 8)); // !*depend
    if (v_27192 == nil) goto v_26325;
    else goto v_26322;
v_26325:
    goto v_26332;
v_26328:
    v_27193 = nil;
    goto v_26329;
v_26330:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26331;
v_26332:
    goto v_26328;
v_26329:
    goto v_26330;
v_26331:
    return cons(v_27193, v_27192);
v_26322:
    v_27192 = qvalue(elt(env, 13)); // !*simpnoncomdf
    if (v_27192 == nil) goto v_26336;
    goto v_26345;
v_26341:
    v_27193 = stack[-7];
    goto v_26342;
v_26343:
    v_27192 = qvalue(elt(env, 10)); // depl!*
    goto v_26344;
v_26345:
    goto v_26341;
v_26342:
    goto v_26343;
v_26344:
    v_27192 = Latsoc(nil, v_27193, v_27192);
    stack[0] = v_27192;
    if (v_27192 == nil) goto v_26336;
    v_27192 = stack[0];
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    if (v_27192 == nil) goto v_26349;
    else goto v_26336;
v_26349:
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    v_27192 = qcar(v_27192);
    stack[-6] = v_27192;
    goto v_26362;
v_26358:
    goto v_26371;
v_26365:
    v_27194 = elt(env, 11); // df
    goto v_26366;
v_26367:
    v_27193 = stack[-8];
    goto v_26368;
v_26369:
    v_27192 = stack[-6];
    goto v_26370;
v_26371:
    goto v_26365;
v_26366:
    goto v_26367;
v_26368:
    goto v_26369;
v_26370:
    v_27192 = list3(v_27194, v_27193, v_27192);
    env = stack[-10];
    fn = elt(env, 31); // simp
    stack[0] = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    goto v_26359;
v_26360:
    goto v_26383;
v_26377:
    v_27194 = elt(env, 11); // df
    goto v_26378;
v_26379:
    v_27193 = stack[-7];
    goto v_26380;
v_26381:
    v_27192 = stack[-6];
    goto v_26382;
v_26383:
    goto v_26377;
v_26378:
    goto v_26379;
v_26380:
    goto v_26381;
v_26382:
    v_27192 = list3(v_27194, v_27193, v_27192);
    env = stack[-10];
    fn = elt(env, 31); // simp
    v_27192 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    goto v_26361;
v_26362:
    goto v_26358;
v_26359:
    goto v_26360;
v_26361:
    fn = elt(env, 39); // quotsq
    v_27192 = (*qfn2(fn))(fn, stack[0], v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_25647;
v_26336:
    goto v_26307;
v_26309:
    goto v_26394;
v_26390:
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    v_27193 = qcar(v_27192);
    goto v_26391;
v_26392:
    v_27192 = elt(env, 14); // int
    goto v_26393;
v_26394:
    goto v_26390;
v_26391:
    goto v_26392;
v_26393:
    if (!consp(v_27193)) goto v_26388;
    v_27193 = qcar(v_27193);
    if (v_27193 == v_27192) goto v_26387;
    else goto v_26388;
v_26387:
    goto v_26407;
v_26403:
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    v_27192 = qcar(v_27192);
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    v_27193 = qcar(v_27192);
    goto v_26404;
v_26405:
    v_27192 = stack[-7];
    goto v_26406;
v_26407:
    goto v_26403;
v_26404:
    goto v_26405;
v_26406:
    if (v_27193 == v_27192) goto v_26401;
    else goto v_26402;
v_26401:
    goto v_26422;
v_26416:
    v_27194 = elt(env, 11); // df
    goto v_26417;
v_26418:
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    v_27192 = qcar(v_27192);
    v_27192 = qcdr(v_27192);
    v_27193 = qcar(v_27192);
    goto v_26419;
v_26420:
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    goto v_26421;
v_26422:
    goto v_26416;
v_26417:
    goto v_26418;
v_26419:
    goto v_26420;
v_26421:
    v_27192 = list2star(v_27194, v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_25650;
v_26402:
    v_27192 = qvalue(elt(env, 15)); // !*allowdfint
    if (v_27192 == nil) goto v_26433;
    goto v_26443;
v_26439:
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    v_27192 = qcar(v_27192);
    v_27192 = qcdr(v_27192);
    v_27192 = qcar(v_27192);
    fn = elt(env, 40); // simp!*
    v_27193 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    goto v_26440;
v_26441:
    v_27192 = stack[-7];
    goto v_26442;
v_26443:
    goto v_26439;
v_26440:
    goto v_26441;
v_26442:
    fn = elt(env, 29); // diffsq
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    fn = elt(env, 41); // not_df_p
    v_27192 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    if (v_27192 == nil) goto v_26433;
    goto v_26458;
v_26452:
    stack[-2] = elt(env, 11); // df
    goto v_26453;
v_26454:
    goto v_26468;
v_26462:
    stack[-1] = elt(env, 14); // int
    goto v_26463;
v_26464:
    v_27192 = stack[0];
    fn = elt(env, 42); // mk!*sq
    v_27193 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    goto v_26465;
v_26466:
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    v_27192 = qcar(v_27192);
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    v_27192 = qcar(v_27192);
    goto v_26467;
v_26468:
    goto v_26462;
v_26463:
    goto v_26464;
v_26465:
    goto v_26466;
v_26467:
    v_27192 = list3(stack[-1], v_27193, v_27192);
    env = stack[-10];
    fn = elt(env, 43); // reval
    v_27193 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    goto v_26455;
v_26456:
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    goto v_26457;
v_26458:
    goto v_26452;
v_26453:
    goto v_26454;
v_26455:
    goto v_26456;
v_26457:
    v_27192 = list2star(stack[-2], v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_25650;
v_26433:
    goto v_26307;
v_26388:
v_26307:
    v_27192 = qvalue(elt(env, 9)); // !*expanddf
    if (v_27192 == nil) goto v_26484;
    goto v_26494;
v_26490:
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    v_27193 = qcar(v_27192);
    goto v_26491;
v_26492:
    v_27192 = stack[-7];
    goto v_26493;
v_26494:
    goto v_26490;
v_26491:
    goto v_26492;
v_26493:
    fn = elt(env, 35); // depends
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    if (v_27192 == nil) goto v_26484;
    goto v_26508;
v_26504:
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    v_27193 = qcar(v_27192);
    goto v_26505;
v_26506:
    v_27192 = qvalue(elt(env, 7)); // powlis!*
    goto v_26507;
v_26508:
    goto v_26504;
v_26505:
    goto v_26506;
v_26507:
    v_27192 = Latsoc(nil, v_27193, v_27192);
    stack[-6] = v_27192;
    if (v_27192 == nil) goto v_26502;
    else goto v_26503;
v_26502:
    v_27192 = lisp_true;
    goto v_26501;
v_26503:
    goto v_26522;
v_26518:
    v_27192 = stack[-6];
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    v_27193 = qcar(v_27192);
    goto v_26519;
v_26520:
    v_27192 = stack[-7];
    goto v_26521;
v_26522:
    goto v_26518;
v_26519:
    goto v_26520;
v_26521:
    fn = elt(env, 35); // depends
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    v_27192 = (v_27192 == nil ? lisp_true : nil);
    goto v_26501;
    v_27192 = nil;
v_26501:
    if (v_27192 == nil) goto v_26484;
    goto v_26539;
v_26535:
    v_27193 = stack[-7];
    goto v_26536;
v_26537:
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    v_27192 = qcar(v_27192);
    goto v_26538;
v_26539:
    goto v_26535;
v_26536:
    goto v_26537;
v_26538:
    fn = elt(env, 44); // smember
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    if (v_27192 == nil) goto v_26532;
    else goto v_26533;
v_26532:
    goto v_26548;
v_26544:
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    v_27193 = qcar(v_27192);
    goto v_26545;
v_26546:
    v_27192 = qvalue(elt(env, 10)); // depl!*
    goto v_26547;
v_26548:
    goto v_26544;
v_26545:
    goto v_26546;
v_26547:
    v_27192 = Lassoc(nil, v_27193, v_27192);
    stack[-6] = v_27192;
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    v_27192 = qcar(v_27192);
    if (!consp(v_27192)) goto v_26557;
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    v_27192 = qcar(v_27192);
    v_27192 = qcdr(v_27192);
    if (v_27192 == nil) goto v_26563;
    else goto v_26564;
v_26563:
    v_27192 = nil;
    goto v_26562;
v_26564:
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    v_27192 = qcar(v_27192);
    v_27192 = qcdr(v_27192);
    fn = elt(env, 45); // get!-all!-kernels
    v_27192 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    goto v_26562;
    v_27192 = nil;
v_26562:
    goto v_26555;
v_26557:
    v_27192 = nil;
    goto v_26555;
    v_27192 = nil;
v_26555:
    stack[-5] = v_27192;
    v_27192 = stack[-6];
    if (v_27192 == nil) goto v_26583;
    v_27192 = stack[-5];
    if (v_27192 == nil) goto v_26583;
    goto v_26595;
v_26591:
    goto v_26601;
v_26597:
    v_27193 = stack[-7];
    goto v_26598;
v_26599:
    v_27192 = stack[-5];
    goto v_26600;
v_26601:
    goto v_26597;
v_26598:
    goto v_26599;
v_26600:
    v_27193 = Ldelete(nil, v_27193, v_27192);
    env = stack[-10];
    goto v_26592;
v_26593:
    v_27192 = stack[-7];
    goto v_26594;
v_26595:
    goto v_26591;
v_26592:
    goto v_26593;
v_26594:
    fn = elt(env, 46); // ldepends
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    if (v_27192 == nil) goto v_26583;
    goto v_26581;
v_26583:
    v_27192 = stack[-6];
    if (v_27192 == nil) goto v_26607;
    goto v_26615;
v_26611:
    v_27193 = stack[-7];
    goto v_26612;
v_26613:
    v_27192 = stack[-6];
    v_27192 = qcdr(v_27192);
    stack[-6] = v_27192;
    goto v_26614;
v_26615:
    goto v_26611;
v_26612:
    goto v_26613;
v_26614:
    v_27192 = Lmemq(nil, v_27193, v_27192);
    if (v_27192 == nil) goto v_26610;
    else goto v_26607;
v_26610:
    goto v_26627;
v_26621:
    v_27194 = stack[-8];
    goto v_26622;
v_26623:
    v_27193 = stack[-7];
    goto v_26624;
v_26625:
    v_27192 = stack[-6];
    goto v_26626;
v_26627:
    goto v_26621;
v_26622:
    goto v_26623;
v_26624:
    goto v_26625;
v_26626:
    fn = elt(env, 36); // df!-chain!-rule
    v_27192 = (*qfnn(fn))(fn, 3, v_27194, v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_25647;
v_26607:
    v_27192 = stack[-5];
    if (v_27192 == nil) goto v_26632;
    goto v_26641;
v_26637:
    v_27193 = stack[-7];
    goto v_26638;
v_26639:
    v_27192 = stack[-5];
    goto v_26640;
v_26641:
    goto v_26637;
v_26638:
    goto v_26639;
v_26640:
    fn = elt(env, 44); // smember
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    if (v_27192 == nil) goto v_26635;
    else goto v_26632;
v_26635:
    goto v_26651;
v_26645:
    v_27194 = stack[-8];
    goto v_26646;
v_26647:
    v_27193 = stack[-7];
    goto v_26648;
v_26649:
    v_27192 = stack[-5];
    goto v_26650;
v_26651:
    goto v_26645;
v_26646:
    goto v_26647;
v_26648:
    goto v_26649;
v_26650:
    fn = elt(env, 36); // df!-chain!-rule
    v_27192 = (*qfnn(fn))(fn, 3, v_27194, v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_25647;
v_26632:
v_26581:
    goto v_26531;
v_26533:
v_26531:
    goto v_26482;
v_26484:
v_26482:
    goto v_26664;
v_26660:
    goto v_26670;
v_26666:
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    stack[0] = qcar(v_27192);
    goto v_26667;
v_26668:
    goto v_26679;
v_26675:
    v_27193 = stack[-8];
    goto v_26676;
v_26677:
    v_27192 = stack[-7];
    goto v_26678;
v_26679:
    goto v_26675;
v_26676:
    goto v_26677;
v_26678:
    fn = elt(env, 47); // merge!-ind!-vars
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    goto v_26669;
v_26670:
    goto v_26666;
v_26667:
    goto v_26668;
v_26669:
    v_27193 = cons(stack[0], v_27192);
    env = stack[-10];
    stack[0] = v_27193;
    goto v_26661;
v_26662:
    v_27192 = elt(env, 11); // df
    if (!symbolp(v_27192)) v_27192 = nil;
    else { v_27192 = qfastgets(v_27192);
           if (v_27192 != nil) { v_27192 = elt(v_27192, 50); // kvalue
#ifdef RECORD_GET
             if (v_27192 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v_27192 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v_27192 == SPID_NOPROP) v_27192 = nil; }}
#endif
    goto v_26663;
v_26664:
    goto v_26660;
v_26661:
    goto v_26662;
v_26663:
    fn = elt(env, 48); // find_sub_df
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    stack[-6] = v_27192;
    if (v_27192 == nil) goto v_26658;
    v_27192 = stack[-6];
    v_27192 = qcar(v_27192);
    fn = elt(env, 31); // simp
    v_27192 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    v_27192 = stack[-6];
    v_27192 = qcdr(v_27192);
    stack[-3] = v_27192;
v_26690:
    v_27192 = stack[-3];
    if (v_27192 == nil) goto v_26695;
    else goto v_26696;
v_26695:
    goto v_26689;
v_26696:
    v_27192 = stack[-3];
    v_27192 = qcar(v_27192);
    stack[-2] = v_27192;
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_27192;
v_26705:
    goto v_26717;
v_26713:
    v_27192 = stack[-2];
    v_27193 = qcdr(v_27192);
    goto v_26714;
v_26715:
    v_27192 = stack[-1];
    goto v_26716;
v_26717:
    goto v_26713;
v_26714:
    goto v_26715;
v_26716:
    v_27192 = difference2(v_27193, v_27192);
    env = stack[-10];
    v_27192 = Lminusp(nil, v_27192);
    env = stack[-10];
    if (v_27192 == nil) goto v_26710;
    goto v_26704;
v_26710:
    goto v_26727;
v_26723:
    v_27193 = stack[0];
    goto v_26724;
v_26725:
    v_27192 = stack[-2];
    v_27192 = qcar(v_27192);
    goto v_26726;
v_26727:
    goto v_26723;
v_26724:
    goto v_26725;
v_26726:
    fn = elt(env, 29); // diffsq
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    v_27192 = stack[-1];
    v_27192 = add1(v_27192);
    env = stack[-10];
    stack[-1] = v_27192;
    goto v_26705;
v_26704:
    v_27192 = stack[-3];
    v_27192 = qcdr(v_27192);
    stack[-3] = v_27192;
    goto v_26690;
v_26689:
    goto v_25647;
v_26658:
    goto v_26742;
v_26738:
    v_27193 = elt(env, 11); // df
    goto v_26739;
v_26740:
    v_27192 = stack[0];
    goto v_26741;
v_26742:
    goto v_26738;
v_26739:
    goto v_26740;
v_26741:
    v_27192 = cons(v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_26656;
v_26656:
    goto v_26295;
v_26297:
    v_27192 = qvalue(elt(env, 16)); // !*df_partial
    if (v_27192 == nil) goto v_26746;
    v_27192 = qvalue(elt(env, 9)); // !*expanddf
    if (v_27192 == nil) goto v_26746;
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    v_27192 = qcar(v_27192);
    if (!consp(v_27192)) goto v_26746;
    goto v_26763;
v_26759:
    v_27192 = stack[-8];
    v_27192 = qcar(v_27192);
    v_27193 = Lexplode(nil, v_27192);
    env = stack[-10];
    goto v_26760;
v_26761:
    v_27192 = elt(env, 17); // (!! !! !_)
    goto v_26762;
v_26763:
    goto v_26759;
v_26760:
    goto v_26761;
v_26762:
    v_27192 = Lnconc(nil, v_27193, v_27192);
    env = stack[-10];
    v_27192 = Lcompress(nil, v_27192);
    env = stack[-10];
    v_27192 = Lintern(nil, v_27192);
    env = stack[-10];
    stack[-6] = v_27192;
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    stack[-5] = v_27192;
    goto v_26775;
v_26771:
    v_27193 = nil;
    goto v_26772;
v_26773:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26774;
v_26775:
    goto v_26771;
v_26772:
    goto v_26773;
v_26774:
    v_27192 = cons(v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    v_27192 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_27192;
    v_27192 = stack[-5];
    stack[-2] = v_27192;
v_26782:
    v_27192 = stack[-2];
    if (v_27192 == nil) goto v_26786;
    else goto v_26787;
v_26786:
    goto v_26781;
v_26787:
    v_27192 = stack[-2];
    v_27192 = qcar(v_27192);
    stack[-1] = v_27192;
    v_27192 = stack[-3];
    v_27192 = add1(v_27192);
    env = stack[-10];
    stack[-3] = v_27192;
    goto v_26810;
v_26804:
    v_27194 = elt(env, 11); // df
    goto v_26805;
v_26806:
    v_27193 = stack[-1];
    goto v_26807;
v_26808:
    v_27192 = stack[-7];
    goto v_26809;
v_26810:
    goto v_26804;
v_26805:
    goto v_26806;
v_26807:
    goto v_26808;
v_26809:
    v_27192 = list3(v_27194, v_27193, v_27192);
    env = stack[-10];
    fn = elt(env, 31); // simp
    v_27192 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    stack[-1] = v_27192;
    v_27192 = qcar(v_27192);
    if (v_27192 == nil) goto v_26801;
    goto v_26820;
v_26816:
    v_27193 = stack[-6];
    goto v_26817;
v_26818:
    v_27192 = stack[-3];
    goto v_26819;
v_26820:
    goto v_26816;
v_26817:
    goto v_26818;
v_26819:
    fn = elt(env, 49); // mkid
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    stack[-4] = v_27192;
    goto v_26830;
v_26824:
    v_27194 = stack[-4];
    goto v_26825;
v_26826:
    v_27193 = elt(env, 18); // simpfn
    goto v_26827;
v_26828:
    v_27192 = elt(env, 19); // simpiden
    goto v_26829;
v_26830:
    goto v_26824;
v_26825:
    goto v_26826;
v_26827:
    goto v_26828;
v_26829:
    v_27192 = Lputprop(nil, 3, v_27194, v_27193, v_27192);
    env = stack[-10];
    goto v_26839;
v_26835:
    goto v_26836;
v_26837:
    goto v_26846;
v_26842:
    goto v_26853;
v_26849:
    v_27193 = stack[-4];
    goto v_26850;
v_26851:
    v_27192 = stack[-5];
    goto v_26852;
v_26853:
    goto v_26849;
v_26850:
    goto v_26851;
v_26852:
    v_27192 = cons(v_27193, v_27192);
    env = stack[-10];
    fn = elt(env, 31); // simp
    v_27193 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    goto v_26843;
v_26844:
    v_27192 = stack[-1];
    goto v_26845;
v_26846:
    goto v_26842;
v_26843:
    goto v_26844;
v_26845:
    fn = elt(env, 25); // multsq
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    goto v_26838;
v_26839:
    goto v_26835;
v_26836:
    goto v_26837;
v_26838:
    fn = elt(env, 27); // addsq
    v_27192 = (*qfn2(fn))(fn, stack[0], v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_26799;
v_26801:
v_26799:
    v_27192 = stack[-2];
    v_27192 = qcdr(v_27192);
    stack[-2] = v_27192;
    goto v_26782;
v_26781:
    goto v_25647;
v_26746:
    goto v_26868;
v_26862:
    v_27194 = elt(env, 11); // df
    goto v_26863;
v_26864:
    v_27193 = stack[-8];
    goto v_26865;
v_26866:
    v_27192 = stack[-7];
    goto v_26867;
v_26868:
    goto v_26862;
v_26863:
    goto v_26864;
v_26865:
    goto v_26866;
v_26867:
    v_27192 = list3(v_27194, v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_26295;
v_26295:
v_25650:
    v_27192 = stack[0];
    fn = elt(env, 37); // opmtch
    v_27192 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    stack[-6] = v_27192;
    if (v_27192 == nil) goto v_26875;
    v_27192 = stack[-6];
    fn = elt(env, 31); // simp
    v_27192 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_26873;
v_26875:
    goto v_26891;
v_26887:
    v_27193 = stack[-8];
    goto v_26888;
v_26889:
    v_27192 = stack[-7];
    goto v_26890;
v_26891:
    goto v_26887;
v_26888:
    goto v_26889;
v_26890:
    fn = elt(env, 35); // depends
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    if (v_27192 == nil) goto v_26884;
    else goto v_26885;
v_26884:
    goto v_26906;
v_26902:
    v_27192 = stack[0];
    v_27192 = qcdr(v_27192);
    v_27193 = qcar(v_27192);
    stack[-8] = v_27193;
    goto v_26903;
v_26904:
    v_27192 = qvalue(elt(env, 7)); // powlis!*
    goto v_26905;
v_26906:
    goto v_26902;
v_26903:
    goto v_26904;
v_26905:
    v_27192 = Latsoc(nil, v_27193, v_27192);
    stack[-6] = v_27192;
    if (v_27192 == nil) goto v_26900;
    else goto v_26901;
v_26900:
    v_27192 = lisp_true;
    goto v_26899;
v_26901:
    goto v_26920;
v_26916:
    v_27192 = stack[-6];
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    v_27193 = qcar(v_27192);
    goto v_26917;
v_26918:
    v_27192 = stack[0];
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    goto v_26919;
v_26920:
    goto v_26916;
v_26917:
    goto v_26918;
v_26919:
    fn = elt(env, 50); // dependsl
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    v_27192 = (v_27192 == nil ? lisp_true : nil);
    goto v_26899;
    v_27192 = nil;
v_26899:
    if (v_27192 == nil) goto v_26897;
    v_27192 = qvalue(elt(env, 8)); // !*depend
    v_27192 = (v_27192 == nil ? lisp_true : nil);
    goto v_26895;
v_26897:
    v_27192 = nil;
    goto v_26895;
    v_27192 = nil;
v_26895:
    goto v_26883;
v_26885:
    v_27192 = nil;
    goto v_26883;
    v_27192 = nil;
v_26883:
    if (v_27192 == nil) goto v_26881;
    goto v_26943;
v_26939:
    v_27193 = nil;
    goto v_26940;
v_26941:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26942;
v_26943:
    goto v_26939;
v_26940:
    goto v_26941;
v_26942:
    return cons(v_27193, v_27192);
v_26881:
    v_27192 = qvalue(elt(env, 9)); // !*expanddf
    if (v_27192 == nil) goto v_26947;
    v_27192 = stack[-8];
    if (!consp(v_27192)) goto v_26954;
    v_27192 = stack[0];
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    if (v_27192 == nil) goto v_26958;
    else goto v_26959;
v_26958:
    goto v_26972;
v_26968:
    v_27192 = stack[-8];
    v_27193 = qcar(v_27192);
    goto v_26969;
v_26970:
    v_27192 = elt(env, 20); // (df int)
    goto v_26971;
v_26972:
    goto v_26968;
v_26969:
    goto v_26970;
v_26971:
    v_27192 = Lmemq(nil, v_27193, v_27192);
    if (v_27192 == nil) goto v_26966;
    else goto v_26967;
v_26966:
    goto v_26986;
v_26982:
    v_27193 = stack[-7];
    goto v_26983;
v_26984:
    v_27192 = stack[-8];
    goto v_26985;
v_26986:
    goto v_26982;
v_26983:
    goto v_26984;
v_26985:
    fn = elt(env, 44); // smember
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    if (v_27192 == nil) goto v_26979;
    else goto v_26980;
v_26979:
    goto v_26997;
v_26993:
    v_27193 = stack[-8];
    goto v_26994;
v_26995:
    v_27192 = qvalue(elt(env, 7)); // powlis!*
    goto v_26996;
v_26997:
    goto v_26993;
v_26994:
    goto v_26995;
v_26996:
    v_27192 = Latsoc(nil, v_27193, v_27192);
    stack[-6] = v_27192;
    if (v_27192 == nil) goto v_26991;
    else goto v_26992;
v_26991:
    v_27192 = lisp_true;
    goto v_26990;
v_26992:
    goto v_27009;
v_27005:
    v_27192 = stack[-6];
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    v_27192 = qcdr(v_27192);
    v_27193 = qcar(v_27192);
    goto v_27006;
v_27007:
    v_27192 = stack[-7];
    goto v_27008;
v_27009:
    goto v_27005;
v_27006:
    goto v_27007;
v_27008:
    fn = elt(env, 35); // depends
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    v_27192 = (v_27192 == nil ? lisp_true : nil);
    goto v_26990;
    v_27192 = nil;
v_26990:
    goto v_26978;
v_26980:
    v_27192 = nil;
    goto v_26978;
    v_27192 = nil;
v_26978:
    goto v_26965;
v_26967:
    v_27192 = nil;
    goto v_26965;
    v_27192 = nil;
v_26965:
    goto v_26957;
v_26959:
    v_27192 = nil;
    goto v_26957;
    v_27192 = nil;
v_26957:
    goto v_26952;
v_26954:
    v_27192 = nil;
    goto v_26952;
    v_27192 = nil;
v_26952:
    if (v_27192 == nil) goto v_26947;
    goto v_27033;
v_27029:
    v_27193 = stack[-8];
    goto v_27030;
v_27031:
    v_27192 = qvalue(elt(env, 10)); // depl!*
    goto v_27032;
v_27033:
    goto v_27029;
v_27030:
    goto v_27031;
v_27032:
    v_27192 = Lassoc(nil, v_27193, v_27192);
    stack[-6] = v_27192;
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    if (v_27192 == nil) goto v_27039;
    else goto v_27040;
v_27039:
    v_27192 = nil;
    goto v_27038;
v_27040:
    v_27192 = stack[-8];
    v_27192 = qcdr(v_27192);
    fn = elt(env, 45); // get!-all!-kernels
    v_27192 = (*qfn1(fn))(fn, v_27192);
    env = stack[-10];
    goto v_27038;
    v_27192 = nil;
v_27038:
    stack[-5] = v_27192;
    v_27192 = stack[-6];
    if (v_27192 == nil) goto v_27052;
    v_27192 = stack[-5];
    if (v_27192 == nil) goto v_27052;
    goto v_27064;
v_27060:
    goto v_27070;
v_27066:
    v_27193 = stack[-7];
    goto v_27067;
v_27068:
    v_27192 = stack[-5];
    goto v_27069;
v_27070:
    goto v_27066;
v_27067:
    goto v_27068;
v_27069:
    v_27193 = Ldelete(nil, v_27193, v_27192);
    env = stack[-10];
    goto v_27061;
v_27062:
    v_27192 = stack[-7];
    goto v_27063;
v_27064:
    goto v_27060;
v_27061:
    goto v_27062;
v_27063:
    fn = elt(env, 46); // ldepends
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    if (v_27192 == nil) goto v_27052;
    goto v_27085;
v_27075:
    v_27196 = elt(env, 21); // "Possible inconsistent dependencies in"
    goto v_27076;
v_27077:
    v_27195 = stack[-8];
    goto v_27078;
v_27079:
    v_27194 = nil;
    goto v_27080;
v_27081:
    v_27193 = nil;
    goto v_27082;
v_27083:
    v_27192 = nil;
    goto v_27084;
v_27085:
    goto v_27075;
v_27076:
    goto v_27077;
v_27078:
    goto v_27079;
v_27080:
    goto v_27081;
v_27082:
    goto v_27083;
v_27084:
    fn = elt(env, 51); // msgpri
    v_27192 = (*qfnn(fn))(fn, 5, v_27196, v_27195, v_27194, v_27193, v_27192);
    env = stack[-10];
    goto v_27096;
v_27092:
    v_27193 = stack[0];
    goto v_27093;
v_27094:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27095;
v_27096:
    goto v_27092;
v_27093:
    goto v_27094;
v_27095:
    fn = elt(env, 38); // mksq
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_27050;
v_27052:
    v_27192 = stack[-6];
    if (v_27192 == nil) goto v_27100;
    goto v_27110;
v_27106:
    v_27193 = stack[-7];
    goto v_27107;
v_27108:
    v_27192 = stack[-6];
    v_27192 = qcdr(v_27192);
    stack[-6] = v_27192;
    goto v_27109;
v_27110:
    goto v_27106;
v_27107:
    goto v_27108;
v_27109:
    v_27192 = Lmemq(nil, v_27193, v_27192);
    if (v_27192 == nil) goto v_27105;
    goto v_27120;
v_27116:
    v_27193 = stack[0];
    goto v_27117;
v_27118:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27119;
v_27120:
    goto v_27116;
v_27117:
    goto v_27118;
v_27119:
    fn = elt(env, 38); // mksq
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_27103;
v_27105:
    goto v_27132;
v_27126:
    v_27194 = stack[-8];
    goto v_27127;
v_27128:
    v_27193 = stack[-7];
    goto v_27129;
v_27130:
    v_27192 = stack[-6];
    goto v_27131;
v_27132:
    goto v_27126;
v_27127:
    goto v_27128;
v_27129:
    goto v_27130;
v_27131:
    fn = elt(env, 36); // df!-chain!-rule
    v_27192 = (*qfnn(fn))(fn, 3, v_27194, v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_27103;
v_27103:
    goto v_27050;
v_27100:
    v_27192 = stack[-5];
    if (v_27192 == nil) goto v_27137;
    goto v_27148;
v_27144:
    v_27193 = stack[-7];
    goto v_27145;
v_27146:
    v_27192 = stack[-5];
    goto v_27147;
v_27148:
    goto v_27144;
v_27145:
    goto v_27146;
v_27147:
    fn = elt(env, 44); // smember
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    if (v_27192 == nil) goto v_27142;
    goto v_27156;
v_27152:
    v_27193 = stack[0];
    goto v_27153;
v_27154:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27155;
v_27156:
    goto v_27152;
v_27153:
    goto v_27154;
v_27155:
    fn = elt(env, 38); // mksq
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    goto v_27140;
v_27142:
    goto v_27168;
v_27162:
    v_27194 = stack[-8];
    goto v_27163;
v_27164:
    v_27193 = stack[-7];
    goto v_27165;
v_27166:
    v_27192 = stack[-5];
    goto v_27167;
v_27168:
    goto v_27162;
v_27163:
    goto v_27164;
v_27165:
    goto v_27166;
v_27167:
    fn = elt(env, 36); // df!-chain!-rule
    v_27192 = (*qfnn(fn))(fn, 3, v_27194, v_27193, v_27192);
    env = stack[-10];
    goto v_27140;
    v_27192 = nil;
v_27140:
    stack[0] = v_27192;
    goto v_27050;
v_27137:
    goto v_27179;
v_27175:
    v_27193 = stack[0];
    goto v_27176;
v_27177:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27178;
v_27179:
    goto v_27175;
v_27176:
    goto v_27177;
v_27178:
    fn = elt(env, 38); // mksq
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_27050;
v_27050:
    goto v_26873;
v_26947:
    goto v_27189;
v_27185:
    v_27193 = stack[0];
    goto v_27186;
v_27187:
    v_27192 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27188;
v_27189:
    goto v_27185;
v_27186:
    goto v_27187;
v_27188:
    fn = elt(env, 38); // mksq
    v_27192 = (*qfn2(fn))(fn, v_27193, v_27192);
    env = stack[-10];
    stack[0] = v_27192;
    goto v_26873;
v_26873:
    goto v_25647;
    return onevalue(v_27192);
}



// Code for letmtr

static LispObject CC_letmtr(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25731, v_25732, v_25733;
    LispObject fn;
    LispObject v_25636, v_25635, v_25634;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "letmtr");
    va_start(aa, nargs);
    v_25634 = va_arg(aa, LispObject);
    v_25635 = va_arg(aa, LispObject);
    v_25636 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_25636,v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_25634,v_25635,v_25636);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_25636;
    stack[-3] = v_25635;
    stack[-4] = v_25634;
// end of prologue
    stack[-5] = nil;
    goto v_25650;
v_25646:
    v_25732 = stack[-2];
    goto v_25647;
v_25648:
    v_25731 = elt(env, 1); // mat
    goto v_25649;
v_25650:
    goto v_25646;
v_25647:
    goto v_25648;
v_25649:
    if (!consp(v_25732)) goto v_25643;
    v_25732 = qcar(v_25732);
    if (v_25732 == v_25731) goto v_25644;
v_25643:
    goto v_25660;
v_25654:
    stack[-1] = elt(env, 2); // matrix
    goto v_25655;
v_25656:
    stack[0] = (LispObject)160+TAG_FIXNUM; // 10
    goto v_25657;
v_25658:
    goto v_25670;
v_25664:
    v_25733 = elt(env, 3); // "Matrix"
    goto v_25665;
v_25666:
    v_25731 = stack[-4];
    v_25732 = qcar(v_25731);
    goto v_25667;
v_25668:
    v_25731 = elt(env, 4); // "not set"
    goto v_25669;
v_25670:
    goto v_25664;
v_25665:
    goto v_25666;
v_25667:
    goto v_25668;
v_25669:
    v_25731 = list3(v_25733, v_25732, v_25731);
    env = stack[-6];
    goto v_25659;
v_25660:
    goto v_25654;
v_25655:
    goto v_25656;
v_25657:
    goto v_25658;
v_25659:
    fn = elt(env, 6); // rerror
    v_25731 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_25731);
    env = stack[-6];
    goto v_25642;
v_25644:
    v_25731 = stack[-4];
    v_25731 = qcdr(v_25731);
    fn = elt(env, 7); // revlis
    v_25731 = (*qfn1(fn))(fn, v_25731);
    env = stack[-6];
    stack[-5] = v_25731;
    fn = elt(env, 8); // numlis
    v_25731 = (*qfn1(fn))(fn, v_25731);
    env = stack[-6];
    if (v_25731 == nil) goto v_25679;
    else goto v_25680;
v_25679:
    v_25731 = lisp_true;
    goto v_25678;
v_25680:
    goto v_25693;
v_25689:
    v_25731 = stack[-5];
    v_25732 = Llength(nil, v_25731);
    env = stack[-6];
    goto v_25690;
v_25691:
    v_25731 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_25692;
v_25693:
    goto v_25689;
v_25690:
    goto v_25691;
v_25692:
    v_25731 = Lneq(nil, v_25732, v_25731);
    env = stack[-6];
    goto v_25678;
    v_25731 = nil;
v_25678:
    if (v_25731 == nil) goto v_25676;
    goto v_25702;
v_25698:
    v_25732 = stack[-4];
    goto v_25699;
v_25700:
    v_25731 = elt(env, 5); // hold
    goto v_25701;
v_25702:
    goto v_25698;
v_25699:
    goto v_25700;
v_25701:
    {
        fn = elt(env, 9); // errpri2
        return (*qfn2(fn))(fn, v_25732, v_25731);
    }
v_25676:
v_25642:
    goto v_25710;
v_25706:
    goto v_25716;
v_25712:
    goto v_25722;
v_25718:
    v_25731 = stack[-2];
    v_25732 = qcdr(v_25731);
    goto v_25719;
v_25720:
    v_25731 = stack[-5];
    v_25731 = qcar(v_25731);
    goto v_25721;
v_25722:
    goto v_25718;
v_25719:
    goto v_25720;
v_25721:
    fn = elt(env, 10); // nth
    v_25732 = (*qfn2(fn))(fn, v_25732, v_25731);
    env = stack[-6];
    goto v_25713;
v_25714:
    v_25731 = stack[-5];
    v_25731 = qcdr(v_25731);
    v_25731 = qcar(v_25731);
    goto v_25715;
v_25716:
    goto v_25712;
v_25713:
    goto v_25714;
v_25715:
    fn = elt(env, 11); // pnth
    v_25732 = (*qfn2(fn))(fn, v_25732, v_25731);
    env = stack[-6];
    goto v_25707;
v_25708:
    v_25731 = stack[-3];
    goto v_25709;
v_25710:
    goto v_25706;
v_25707:
    goto v_25708;
v_25709:
    v_25731 = Lrplaca(nil, v_25732, v_25731);
    v_25731 = nil;
    return onevalue(v_25731);
}



// Code for xpartitop

static LispObject CC_xpartitop(LispObject env,
                         LispObject v_25634)
{
    env = qenv(env);
    LispObject v_25639;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25634);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_25639 = v_25634;
// end of prologue
    fn = elt(env, 1); // simp!*
    v_25639 = (*qfn1(fn))(fn, v_25639);
    env = stack[0];
    {
        fn = elt(env, 2); // xpartitsq
        return (*qfn1(fn))(fn, v_25639);
    }
}



// Code for r2oaddspecies

static LispObject CC_r2oaddspecies(LispObject env,
                         LispObject v_25634, LispObject v_25635)
{
    env = qenv(env);
    LispObject v_25672, v_25673;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25634,v_25635);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_25635;
    stack[-1] = v_25634;
// end of prologue
    goto v_25645;
v_25641:
    v_25673 = stack[-1];
    goto v_25642;
v_25643:
    v_25672 = stack[0];
    goto v_25644;
v_25645:
    goto v_25641;
v_25642:
    goto v_25643;
v_25644:
    v_25672 = Lassoc(nil, v_25673, v_25672);
    if (v_25672 == nil) goto v_25640;
    v_25672 = stack[0];
    goto v_25638;
v_25640:
    v_25672 = elt(env, 1); // "new species: "
    v_25672 = Lprinc(nil, v_25672);
    env = stack[-2];
    v_25672 = stack[-1];
    fn = elt(env, 2); // prin2t
    v_25672 = (*qfn1(fn))(fn, v_25672);
    env = stack[-2];
    goto v_25661;
v_25657:
    goto v_25658;
v_25659:
    goto v_25669;
v_25665:
    v_25673 = stack[-1];
    goto v_25666;
v_25667:
    v_25672 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25668;
v_25669:
    goto v_25665;
v_25666:
    goto v_25667;
v_25668:
    v_25672 = cons(v_25673, v_25672);
    env = stack[-2];
    v_25672 = ncons(v_25672);
    goto v_25660;
v_25661:
    goto v_25657;
v_25658:
    goto v_25659;
v_25660:
    {
        LispObject v_25676 = stack[0];
        return Lappend(nil, v_25676, v_25672);
    }
    v_25672 = nil;
v_25638:
    return onevalue(v_25672);
}



// Code for ev!-poles

static LispObject CC_evKpoles(LispObject env,
                         LispObject v_25634, LispObject v_25635)
{
    env = qenv(env);
    LispObject v_25669, v_25670, v_25671, v_25672;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_25670 = v_25635;
    v_25671 = v_25634;
// end of prologue
v_25639:
    v_25669 = v_25671;
    if (v_25669 == nil) goto v_25642;
    else goto v_25643;
v_25642:
    v_25669 = nil;
    goto v_25638;
v_25643:
    goto v_25652;
v_25648:
    goto v_25657;
v_25653:
    v_25669 = v_25671;
    v_25672 = qcar(v_25669);
    goto v_25654;
v_25655:
    v_25669 = v_25670;
    goto v_25656;
v_25657:
    goto v_25653;
v_25654:
    goto v_25655;
v_25656:
    v_25669 = Lassoc(nil, v_25672, v_25669);
    v_25672 = qcdr(v_25669);
    goto v_25649;
v_25650:
    v_25669 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25651;
v_25652:
    goto v_25648;
v_25649:
    goto v_25650;
v_25651:
    if (v_25672 == v_25669) goto v_25646;
    else goto v_25647;
v_25646:
    v_25669 = v_25671;
    v_25669 = qcdr(v_25669);
    v_25671 = v_25669;
    goto v_25639;
v_25647:
    v_25669 = v_25671;
    goto v_25638;
    v_25669 = nil;
v_25638:
    return onevalue(v_25669);
}



// Code for dfp!-rule!-found

static LispObject CC_dfpKruleKfound(LispObject env,
                         LispObject v_25634, LispObject v_25635)
{
    env = qenv(env);
    LispObject v_25662, v_25663, v_25664, v_25665;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_25663 = v_25635;
    v_25664 = v_25634;
// end of prologue
    goto v_25646;
v_25642:
    v_25662 = v_25664;
    goto v_25643;
v_25644:
    v_25665 = elt(env, 1); // dfp
    goto v_25645;
v_25646:
    goto v_25642;
v_25643:
    goto v_25644;
v_25645:
    if (!consp(v_25662)) goto v_25639;
    v_25662 = qcar(v_25662);
    if (v_25662 == v_25665) goto v_25640;
v_25639:
    v_25662 = lisp_true;
    goto v_25638;
v_25640:
    goto v_25657;
v_25653:
    v_25662 = v_25664;
    v_25662 = qcdr(v_25662);
    v_25662 = qcar(v_25662);
    goto v_25654;
v_25655:
    goto v_25656;
v_25657:
    goto v_25653;
v_25654:
    goto v_25655;
v_25656:
        return Lneq(nil, v_25662, v_25663);
    v_25662 = nil;
v_25638:
    return onevalue(v_25662);
}



// Code for mv!-compact2

static LispObject CC_mvKcompact2(LispObject env,
                         LispObject v_25634, LispObject v_25635)
{
    env = qenv(env);
    LispObject v_25696, v_25697, v_25698;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25634,v_25635);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_25635;
    stack[-1] = v_25634;
// end of prologue
    goto v_25647;
v_25643:
    v_25697 = stack[-1];
    goto v_25644;
v_25645:
    v_25696 = stack[0];
    goto v_25646;
v_25647:
    goto v_25643;
v_25644:
    goto v_25645;
v_25646:
    fn = elt(env, 1); // equiv!-coeffs
    v_25696 = (*qfn2(fn))(fn, v_25697, v_25696);
    env = stack[-3];
    stack[-2] = v_25696;
    v_25696 = stack[0];
    fn = elt(env, 2); // mv!-domainlist
    v_25696 = (*qfn1(fn))(fn, v_25696);
    env = stack[-3];
    goto v_25657;
v_25653:
    v_25697 = stack[-2];
    goto v_25654;
v_25655:
    goto v_25656;
v_25657:
    goto v_25653;
v_25654:
    goto v_25655;
v_25656:
    fn = elt(env, 3); // reduce
    v_25696 = (*qfn2(fn))(fn, v_25697, v_25696);
    env = stack[-3];
    v_25698 = v_25696;
    goto v_25668;
v_25664:
    v_25697 = v_25698;
    goto v_25665;
v_25666:
    v_25696 = stack[-2];
    goto v_25667;
v_25668:
    goto v_25664;
v_25665:
    goto v_25666;
v_25667:
    if (equal(v_25697, v_25696)) goto v_25662;
    else goto v_25663;
v_25662:
    v_25696 = nil;
    goto v_25661;
v_25663:
    goto v_25679;
v_25675:
    goto v_25685;
v_25681:
    goto v_25682;
v_25683:
    goto v_25692;
v_25688:
    v_25697 = v_25698;
    goto v_25689;
v_25690:
    v_25696 = stack[-2];
    goto v_25691;
v_25692:
    goto v_25688;
v_25689:
    goto v_25690;
v_25691:
    fn = elt(env, 4); // mv!-domainlist!-!-
    v_25696 = (*qfn2(fn))(fn, v_25697, v_25696);
    env = stack[-3];
    goto v_25684;
v_25685:
    goto v_25681;
v_25682:
    goto v_25683;
v_25684:
    fn = elt(env, 5); // mv!-coeff!-replace
    v_25697 = (*qfn2(fn))(fn, stack[0], v_25696);
    env = stack[-3];
    goto v_25676;
v_25677:
    v_25696 = stack[-1];
    goto v_25678;
v_25679:
    goto v_25675;
v_25676:
    goto v_25677;
v_25678:
    {
        fn = elt(env, 6); // mv!-!+
        return (*qfn2(fn))(fn, v_25697, v_25696);
    }
    v_25696 = nil;
v_25661:
    return onevalue(v_25696);
}



// Code for prepcadr

static LispObject CC_prepcadr(LispObject env,
                         LispObject v_25634)
{
    env = qenv(env);
    LispObject v_25640;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_25640 = v_25634;
// end of prologue
    v_25640 = qcdr(v_25640);
    v_25640 = qcar(v_25640);
    {
        fn = elt(env, 1); // prepsq
        return (*qfn1(fn))(fn, v_25640);
    }
}



// Code for listminimize

static LispObject CC_listminimize(LispObject env,
                         LispObject v_25634, LispObject v_25635)
{
    env = qenv(env);
    LispObject v_25657, v_25658, v_25659;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25634,v_25635);
    }
// copy arguments values to proper place
    v_25657 = v_25635;
    v_25658 = v_25634;
// end of prologue
    v_25659 = v_25658;
    if (v_25659 == nil) goto v_25639;
    else goto v_25640;
v_25639:
    v_25657 = nil;
    goto v_25638;
v_25640:
    goto v_25653;
v_25647:
    v_25659 = nil;
    goto v_25648;
v_25649:
    goto v_25650;
v_25651:
    goto v_25652;
v_25653:
    goto v_25647;
v_25648:
    goto v_25649;
v_25650:
    goto v_25651;
v_25652:
    fn = elt(env, 1); // cali!=min
    v_25657 = (*qfnn(fn))(fn, 3, v_25659, v_25658, v_25657);
        return Lreverse(nil, v_25657);
    v_25657 = nil;
v_25638:
    return onevalue(v_25657);
}



// Code for general!-multiply!-by!-constant!-mod!-p

static LispObject CC_generalKmultiplyKbyKconstantKmodKp(LispObject env,
                         LispObject v_25634, LispObject v_25635)
{
    env = qenv(env);
    LispObject v_25719, v_25720, v_25721;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25634,v_25635);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_25635;
    stack[-1] = v_25634;
// end of prologue
    v_25719 = stack[-1];
    if (v_25719 == nil) goto v_25639;
    else goto v_25640;
v_25639:
    v_25719 = nil;
    goto v_25638;
v_25640:
    goto v_25649;
v_25645:
    v_25720 = stack[0];
    goto v_25646;
v_25647:
    v_25719 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25648;
v_25649:
    goto v_25645;
v_25646:
    goto v_25647;
v_25648:
    if (v_25720 == v_25719) goto v_25643;
    else goto v_25644;
v_25643:
    v_25719 = stack[-1];
    goto v_25638;
v_25644:
    v_25719 = stack[-1];
    if (!consp(v_25719)) goto v_25657;
    else goto v_25658;
v_25657:
    v_25719 = lisp_true;
    goto v_25656;
v_25658:
    v_25719 = stack[-1];
    v_25719 = qcar(v_25719);
    v_25719 = (consp(v_25719) ? nil : lisp_true);
    goto v_25656;
    v_25719 = nil;
v_25656:
    if (v_25719 == nil) goto v_25654;
    goto v_25672;
v_25668:
    v_25720 = stack[-1];
    goto v_25669;
v_25670:
    v_25719 = stack[0];
    goto v_25671;
v_25672:
    goto v_25668;
v_25669:
    goto v_25670;
v_25671:
    fn = elt(env, 1); // general!-modular!-times
    v_25719 = (*qfn2(fn))(fn, v_25720, v_25719);
    env = stack[-3];
    {
        fn = elt(env, 2); // !*n2f
        return (*qfn1(fn))(fn, v_25719);
    }
v_25654:
    goto v_25682;
v_25678:
    v_25719 = stack[-1];
    v_25719 = qcar(v_25719);
    v_25720 = qcdr(v_25719);
    goto v_25679;
v_25680:
    v_25719 = stack[0];
    goto v_25681;
v_25682:
    goto v_25678;
v_25679:
    goto v_25680;
v_25681:
    stack[-2] = CC_generalKmultiplyKbyKconstantKmodKp(elt(env, 0), v_25720, v_25719);
    env = stack[-3];
    goto v_25692;
v_25688:
    v_25719 = stack[-1];
    v_25720 = qcdr(v_25719);
    goto v_25689;
v_25690:
    v_25719 = stack[0];
    goto v_25691;
v_25692:
    goto v_25688;
v_25689:
    goto v_25690;
v_25691:
    v_25719 = CC_generalKmultiplyKbyKconstantKmodKp(elt(env, 0), v_25720, v_25719);
    v_25720 = stack[-2];
    v_25721 = v_25720;
    if (v_25721 == nil) goto v_25700;
    else goto v_25701;
v_25700:
    goto v_25699;
v_25701:
    goto v_25713;
v_25707:
    v_25721 = stack[-1];
    v_25721 = qcar(v_25721);
    v_25721 = qcar(v_25721);
    goto v_25708;
v_25709:
    goto v_25710;
v_25711:
    goto v_25712;
v_25713:
    goto v_25707;
v_25708:
    goto v_25709;
v_25710:
    goto v_25711;
v_25712:
    return acons(v_25721, v_25720, v_25719);
    v_25719 = nil;
v_25699:
    goto v_25638;
    v_25719 = nil;
v_25638:
    return onevalue(v_25719);
}



// Code for mchsarg

static LispObject CC_mchsarg(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25797, v_25798;
    LispObject fn;
    LispObject v_25636, v_25635, v_25634;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mchsarg");
    va_start(aa, nargs);
    v_25634 = va_arg(aa, LispObject);
    v_25635 = va_arg(aa, LispObject);
    v_25636 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_25636,v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_25634,v_25635,v_25636);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_25636;
    stack[-6] = v_25635;
    stack[-1] = v_25634;
// end of prologue
    v_25797 = stack[-6];
    fn = elt(env, 2); // mtp
    v_25797 = (*qfn1(fn))(fn, v_25797);
    env = stack[-8];
    if (v_25797 == nil) goto v_25642;
    goto v_25655;
v_25651:
    v_25798 = stack[-5];
    goto v_25652;
v_25653:
    v_25797 = elt(env, 1); // times
    goto v_25654;
v_25655:
    goto v_25651;
v_25652:
    goto v_25653;
v_25654:
    if (v_25798 == v_25797) goto v_25650;
    v_25797 = lisp_true;
    goto v_25648;
v_25650:
    v_25797 = stack[-1];
    fn = elt(env, 3); // noncomfree
    v_25797 = (*qfn1(fn))(fn, v_25797);
    env = stack[-8];
    goto v_25648;
    v_25797 = nil;
v_25648:
    if (v_25797 == nil) goto v_25642;
    v_25797 = stack[-6];
    fn = elt(env, 4); // noncomperm
    v_25797 = (*qfn1(fn))(fn, v_25797);
    env = stack[-8];
    stack[-4] = v_25797;
    v_25797 = stack[-4];
    if (v_25797 == nil) goto v_25673;
    else goto v_25674;
v_25673:
    v_25797 = nil;
    goto v_25667;
v_25674:
    v_25797 = stack[-4];
    v_25797 = qcar(v_25797);
    goto v_25686;
v_25682:
    v_25798 = v_25797;
    goto v_25683;
v_25684:
    v_25797 = stack[-1];
    goto v_25685;
v_25686:
    goto v_25682;
v_25683:
    goto v_25684;
v_25685:
    fn = elt(env, 5); // pair
    v_25797 = (*qfn2(fn))(fn, v_25798, v_25797);
    env = stack[-8];
    v_25797 = ncons(v_25797);
    env = stack[-8];
    stack[-2] = v_25797;
    stack[-3] = v_25797;
v_25668:
    v_25797 = stack[-4];
    v_25797 = qcdr(v_25797);
    stack[-4] = v_25797;
    v_25797 = stack[-4];
    if (v_25797 == nil) goto v_25693;
    else goto v_25694;
v_25693:
    v_25797 = stack[-3];
    goto v_25667;
v_25694:
    goto v_25702;
v_25698:
    stack[0] = stack[-2];
    goto v_25699;
v_25700:
    v_25797 = stack[-4];
    v_25797 = qcar(v_25797);
    goto v_25713;
v_25709:
    v_25798 = v_25797;
    goto v_25710;
v_25711:
    v_25797 = stack[-1];
    goto v_25712;
v_25713:
    goto v_25709;
v_25710:
    goto v_25711;
v_25712:
    fn = elt(env, 5); // pair
    v_25797 = (*qfn2(fn))(fn, v_25798, v_25797);
    env = stack[-8];
    v_25797 = ncons(v_25797);
    env = stack[-8];
    goto v_25701;
v_25702:
    goto v_25698;
v_25699:
    goto v_25700;
v_25701:
    v_25797 = Lrplacd(nil, stack[0], v_25797);
    env = stack[-8];
    v_25797 = stack[-2];
    v_25797 = qcdr(v_25797);
    stack[-2] = v_25797;
    goto v_25668;
v_25667:
    goto v_25640;
v_25642:
    v_25797 = stack[-1];
    fn = elt(env, 4); // noncomperm
    v_25797 = (*qfn1(fn))(fn, v_25797);
    env = stack[-8];
    stack[-7] = v_25797;
v_25725:
    v_25797 = stack[-7];
    if (v_25797 == nil) goto v_25731;
    else goto v_25732;
v_25731:
    v_25797 = nil;
    goto v_25724;
v_25732:
    v_25797 = stack[-7];
    v_25797 = qcar(v_25797);
    goto v_25747;
v_25739:
    stack[-1] = v_25797;
    goto v_25740;
v_25741:
    stack[0] = stack[-6];
    goto v_25742;
v_25743:
    v_25797 = nil;
    v_25798 = ncons(v_25797);
    env = stack[-8];
    goto v_25744;
v_25745:
    v_25797 = stack[-5];
    goto v_25746;
v_25747:
    goto v_25739;
v_25740:
    goto v_25741;
v_25742:
    goto v_25743;
v_25744:
    goto v_25745;
v_25746:
    fn = elt(env, 6); // mcharg2
    v_25797 = (*qfnn(fn))(fn, 4, stack[-1], stack[0], v_25798, v_25797);
    env = stack[-8];
    stack[-4] = v_25797;
    v_25797 = stack[-4];
    fn = elt(env, 7); // lastpair
    v_25797 = (*qfn1(fn))(fn, v_25797);
    env = stack[-8];
    stack[-3] = v_25797;
    v_25797 = stack[-7];
    v_25797 = qcdr(v_25797);
    stack[-7] = v_25797;
    v_25797 = stack[-3];
    if (!consp(v_25797)) goto v_25759;
    else goto v_25760;
v_25759:
    goto v_25725;
v_25760:
v_25726:
    v_25797 = stack[-7];
    if (v_25797 == nil) goto v_25764;
    else goto v_25765;
v_25764:
    v_25797 = stack[-4];
    goto v_25724;
v_25765:
    goto v_25773;
v_25769:
    stack[-2] = stack[-3];
    goto v_25770;
v_25771:
    v_25797 = stack[-7];
    v_25797 = qcar(v_25797);
    goto v_25787;
v_25779:
    stack[-1] = v_25797;
    goto v_25780;
v_25781:
    stack[0] = stack[-6];
    goto v_25782;
v_25783:
    v_25797 = nil;
    v_25798 = ncons(v_25797);
    env = stack[-8];
    goto v_25784;
v_25785:
    v_25797 = stack[-5];
    goto v_25786;
v_25787:
    goto v_25779;
v_25780:
    goto v_25781;
v_25782:
    goto v_25783;
v_25784:
    goto v_25785;
v_25786:
    fn = elt(env, 6); // mcharg2
    v_25797 = (*qfnn(fn))(fn, 4, stack[-1], stack[0], v_25798, v_25797);
    env = stack[-8];
    goto v_25772;
v_25773:
    goto v_25769;
v_25770:
    goto v_25771;
v_25772:
    v_25797 = Lrplacd(nil, stack[-2], v_25797);
    env = stack[-8];
    v_25797 = stack[-3];
    fn = elt(env, 7); // lastpair
    v_25797 = (*qfn1(fn))(fn, v_25797);
    env = stack[-8];
    stack[-3] = v_25797;
    v_25797 = stack[-7];
    v_25797 = qcdr(v_25797);
    stack[-7] = v_25797;
    goto v_25726;
v_25724:
    goto v_25640;
    v_25797 = nil;
v_25640:
    {
        fn = elt(env, 8); // reversip!*
        return (*qfn1(fn))(fn, v_25797);
    }
}



// Code for mkcrn

static LispObject CC_mkcrn(LispObject env,
                         LispObject v_25634, LispObject v_25635)
{
    env = qenv(env);
    LispObject v_25648, v_25649, v_25650;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_25648 = v_25635;
    v_25649 = v_25634;
// end of prologue
    goto v_25644;
v_25638:
    v_25650 = elt(env, 1); // !:crn!:
    goto v_25639;
v_25640:
    goto v_25641;
v_25642:
    goto v_25643;
v_25644:
    goto v_25638;
v_25639:
    goto v_25640;
v_25641:
    goto v_25642;
v_25643:
    return list2star(v_25650, v_25649, v_25648);
}



// Code for ofsf_simplequal

static LispObject CC_ofsf_simplequal(LispObject env,
                         LispObject v_25634, LispObject v_25635)
{
    env = qenv(env);
    LispObject v_25726, v_25727, v_25728;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25634,v_25635);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_25635;
    stack[-2] = v_25634;
// end of prologue
    v_25726 = stack[-2];
    fn = elt(env, 8); // ofsf_posdefp
    v_25726 = (*qfn1(fn))(fn, v_25726);
    env = stack[-4];
    stack[-3] = v_25726;
    goto v_25652;
v_25648:
    v_25727 = stack[-3];
    goto v_25649;
v_25650:
    v_25726 = elt(env, 1); // stsq
    goto v_25651;
v_25652:
    goto v_25648;
v_25649:
    goto v_25650;
v_25651:
    if (v_25727 == v_25726) goto v_25646;
    else goto v_25647;
v_25646:
    v_25726 = elt(env, 2); // false
    goto v_25641;
v_25647:
    v_25726 = stack[-2];
    fn = elt(env, 9); // sfto_sqfpartf
    v_25726 = (*qfn1(fn))(fn, v_25726);
    env = stack[-4];
    stack[0] = v_25726;
    v_25726 = stack[0];
    fn = elt(env, 8); // ofsf_posdefp
    v_25726 = (*qfn1(fn))(fn, v_25726);
    env = stack[-4];
    v_25728 = v_25726;
    goto v_25668;
v_25664:
    v_25727 = v_25728;
    goto v_25665;
v_25666:
    v_25726 = elt(env, 1); // stsq
    goto v_25667;
v_25668:
    goto v_25664;
v_25665:
    goto v_25666;
v_25667:
    if (v_25727 == v_25726) goto v_25662;
    else goto v_25663;
v_25662:
    v_25726 = elt(env, 2); // false
    goto v_25641;
v_25663:
    v_25726 = qvalue(elt(env, 3)); // !*rlsitsqspl
    if (v_25726 == nil) goto v_25675;
    v_25726 = qvalue(elt(env, 4)); // !*rlsiexpla
    if (v_25726 == nil) goto v_25679;
    else goto v_25678;
v_25679:
    v_25726 = qvalue(elt(env, 5)); // !*rlsiexpl
    if (v_25726 == nil) goto v_25681;
    goto v_25689;
v_25685:
    v_25727 = stack[-1];
    goto v_25686;
v_25687:
    v_25726 = elt(env, 6); // and
    goto v_25688;
v_25689:
    goto v_25685;
v_25686:
    goto v_25687;
v_25688:
    if (v_25727 == v_25726) goto v_25684;
    else goto v_25681;
v_25684:
    goto v_25678;
v_25681:
    goto v_25675;
v_25678:
    goto v_25700;
v_25696:
    v_25727 = v_25728;
    goto v_25697;
v_25698:
    v_25726 = elt(env, 7); // tsq
    goto v_25699;
v_25700:
    goto v_25696;
v_25697:
    goto v_25698;
v_25699:
    if (v_25727 == v_25726) goto v_25694;
    else goto v_25695;
v_25694:
    v_25726 = stack[0];
    {
        fn = elt(env, 10); // ofsf_tsqsplequal
        return (*qfn1(fn))(fn, v_25726);
    }
v_25695:
    goto v_25713;
v_25709:
    v_25727 = stack[-3];
    goto v_25710;
v_25711:
    v_25726 = elt(env, 7); // tsq
    goto v_25712;
v_25713:
    goto v_25709;
v_25710:
    goto v_25711;
v_25712:
    if (v_25727 == v_25726) goto v_25707;
    else goto v_25708;
v_25707:
    v_25726 = stack[-2];
    {
        fn = elt(env, 10); // ofsf_tsqsplequal
        return (*qfn1(fn))(fn, v_25726);
    }
v_25708:
    goto v_25673;
v_25675:
v_25673:
    goto v_25723;
v_25719:
    v_25727 = stack[0];
    goto v_25720;
v_25721:
    v_25726 = stack[-1];
    goto v_25722;
v_25723:
    goto v_25719;
v_25720:
    goto v_25721;
v_25722:
    {
        fn = elt(env, 11); // ofsf_facequal!*
        return (*qfn2(fn))(fn, v_25727, v_25726);
    }
v_25641:
    return onevalue(v_25726);
}



// Code for gcdlist

static LispObject CC_gcdlist(LispObject env,
                         LispObject v_25634)
{
    env = qenv(env);
    LispObject v_26281, v_26282, v_26283;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25634);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(15);
// copy arguments values to proper place
    stack[0] = v_25634;
// end of prologue
    v_26281 = stack[0];
    if (v_26281 == nil) goto v_25638;
    else goto v_25639;
v_25638:
    v_26281 = nil;
    goto v_25637;
v_25639:
    v_26281 = stack[0];
    v_26281 = qcdr(v_26281);
    if (v_26281 == nil) goto v_25642;
    else goto v_25643;
v_25642:
    v_26281 = stack[0];
    v_26281 = qcar(v_26281);
    {
        fn = elt(env, 2); // poly!-abs
        return (*qfn1(fn))(fn, v_26281);
    }
v_25643:
    v_26281 = stack[0];
    v_26281 = qcar(v_26281);
    if (!consp(v_26281)) goto v_25653;
    else goto v_25654;
v_25653:
    v_26281 = lisp_true;
    goto v_25652;
v_25654:
    v_26281 = stack[0];
    v_26281 = qcar(v_26281);
    v_26281 = qcar(v_26281);
    v_26281 = (consp(v_26281) ? nil : lisp_true);
    goto v_25652;
    v_26281 = nil;
v_25652:
    if (v_26281 == nil) goto v_25650;
    goto v_25669;
v_25665:
    v_26281 = stack[0];
    v_26282 = qcdr(v_26281);
    goto v_25666;
v_25667:
    v_26281 = stack[0];
    v_26281 = qcar(v_26281);
    goto v_25668;
v_25669:
    goto v_25665;
v_25666:
    goto v_25667;
v_25668:
    {
        fn = elt(env, 3); // gcdld
        return (*qfn2(fn))(fn, v_26282, v_26281);
    }
v_25650:
    stack[-1] = nil;
v_25683:
    v_26281 = stack[0];
    if (v_26281 == nil) goto v_25686;
    else goto v_25687;
v_25686:
    goto v_25682;
v_25687:
    v_26281 = stack[0];
    v_26281 = qcar(v_26281);
    if (v_26281 == nil) goto v_25692;
    else goto v_25693;
v_25692:
    v_26281 = stack[0];
    v_26281 = qcdr(v_26281);
    stack[0] = v_26281;
    goto v_25691;
v_25693:
    v_26281 = stack[0];
    v_26281 = qcar(v_26281);
    if (!consp(v_26281)) goto v_25702;
    else goto v_25703;
v_25702:
    v_26281 = lisp_true;
    goto v_25701;
v_25703:
    v_26281 = stack[0];
    v_26281 = qcar(v_26281);
    v_26281 = qcar(v_26281);
    v_26281 = (consp(v_26281) ? nil : lisp_true);
    goto v_25701;
    v_26281 = nil;
v_25701:
    if (v_26281 == nil) goto v_25699;
    goto v_25720;
v_25716:
    v_26281 = stack[0];
    stack[-2] = qcdr(v_26281);
    goto v_25717;
v_25718:
    goto v_25728;
v_25724:
    v_26281 = stack[-1];
    fn = elt(env, 4); // mapcarcar
    v_26282 = (*qfn1(fn))(fn, v_26281);
    env = stack[-14];
    goto v_25725;
v_25726:
    v_26281 = stack[0];
    v_26281 = qcar(v_26281);
    goto v_25727;
v_25728:
    goto v_25724;
v_25725:
    goto v_25726;
v_25727:
    fn = elt(env, 3); // gcdld
    v_26281 = (*qfn2(fn))(fn, v_26282, v_26281);
    env = stack[-14];
    goto v_25719;
v_25720:
    goto v_25716;
v_25717:
    goto v_25718;
v_25719:
    fn = elt(env, 3); // gcdld
    v_26281 = (*qfn2(fn))(fn, stack[-2], v_26281);
    env = stack[-14];
    v_26281 = ncons(v_26281);
    env = stack[-14];
    v_26281 = ncons(v_26281);
    env = stack[-14];
    stack[-1] = v_26281;
    v_26281 = nil;
    stack[0] = v_26281;
    goto v_25691;
v_25699:
    goto v_25743;
v_25737:
    v_26281 = stack[0];
    stack[-2] = qcar(v_26281);
    goto v_25738;
v_25739:
    v_26281 = stack[0];
    v_26281 = qcar(v_26281);
    fn = elt(env, 5); // powers1
    v_26282 = (*qfn1(fn))(fn, v_26281);
    env = stack[-14];
    goto v_25740;
v_25741:
    v_26281 = stack[-1];
    goto v_25742;
v_25743:
    goto v_25737;
v_25738:
    goto v_25739;
v_25740:
    goto v_25741;
v_25742:
    v_26281 = acons(stack[-2], v_26282, v_26281);
    env = stack[-14];
    stack[-1] = v_26281;
    v_26281 = stack[0];
    v_26281 = qcdr(v_26281);
    stack[0] = v_26281;
    goto v_25691;
v_25691:
    goto v_25683;
v_25682:
    v_26281 = stack[-1];
    if (v_26281 == nil) goto v_25754;
    else goto v_25755;
v_25754:
    v_26281 = nil;
    goto v_25680;
v_25755:
    v_26281 = stack[-1];
    v_26281 = qcdr(v_26281);
    if (v_26281 == nil) goto v_25758;
    else goto v_25759;
v_25758:
    v_26281 = stack[-1];
    v_26281 = qcar(v_26281);
    v_26281 = qcar(v_26281);
    {
        fn = elt(env, 2); // poly!-abs
        return (*qfn1(fn))(fn, v_26281);
    }
v_25759:
    v_26281 = nil;
    stack[-13] = v_26281;
    v_26281 = nil;
    stack[-12] = v_26281;
    v_26281 = stack[-1];
    stack[-11] = v_26281;
    v_26281 = stack[-11];
    if (v_26281 == nil) goto v_25777;
    else goto v_25778;
v_25777:
    v_26281 = nil;
    goto v_25772;
v_25778:
    v_26281 = stack[-11];
    v_26281 = qcar(v_26281);
    stack[-7] = v_26281;
    stack[-6] = nil;
    v_26281 = stack[-7];
    v_26281 = qcdr(v_26281);
    stack[-5] = v_26281;
    v_26281 = stack[-5];
    if (v_26281 == nil) goto v_25800;
    else goto v_25801;
v_25800:
    v_26281 = nil;
    goto v_25794;
v_25801:
    v_26281 = stack[-5];
    v_26281 = qcar(v_26281);
    stack[-1] = v_26281;
    goto v_25815;
v_25809:
    v_26281 = stack[-1];
    v_26283 = qcar(v_26281);
    goto v_25810;
v_25811:
    v_26281 = stack[-1];
    v_26281 = qcdr(v_26281);
    v_26282 = qcdr(v_26281);
    goto v_25812;
v_25813:
    v_26281 = stack[-6];
    goto v_25814;
v_25815:
    goto v_25809;
v_25810:
    goto v_25811;
v_25812:
    goto v_25813;
v_25814:
    v_26281 = acons(v_26283, v_26282, v_26281);
    env = stack[-14];
    stack[-6] = v_26281;
    goto v_25827;
v_25823:
    v_26281 = stack[-1];
    stack[0] = qcar(v_26281);
    goto v_25824;
v_25825:
    goto v_25835;
v_25831:
    v_26281 = stack[-1];
    v_26281 = qcdr(v_26281);
    v_26282 = qcar(v_26281);
    goto v_25832;
v_25833:
    v_26281 = stack[-1];
    v_26281 = qcdr(v_26281);
    v_26281 = qcdr(v_26281);
    goto v_25834;
v_25835:
    goto v_25831;
v_25832:
    goto v_25833;
v_25834:
    v_26281 = difference2(v_26282, v_26281);
    env = stack[-14];
    goto v_25826;
v_25827:
    goto v_25823;
v_25824:
    goto v_25825;
v_25826:
    v_26281 = cons(stack[0], v_26281);
    env = stack[-14];
    v_26281 = ncons(v_26281);
    env = stack[-14];
    stack[-3] = v_26281;
    stack[-4] = v_26281;
v_25795:
    v_26281 = stack[-5];
    v_26281 = qcdr(v_26281);
    stack[-5] = v_26281;
    v_26281 = stack[-5];
    if (v_26281 == nil) goto v_25846;
    else goto v_25847;
v_25846:
    v_26281 = stack[-4];
    goto v_25794;
v_25847:
    goto v_25855;
v_25851:
    stack[-2] = stack[-3];
    goto v_25852;
v_25853:
    v_26281 = stack[-5];
    v_26281 = qcar(v_26281);
    stack[-1] = v_26281;
    goto v_25868;
v_25862:
    v_26281 = stack[-1];
    v_26283 = qcar(v_26281);
    goto v_25863;
v_25864:
    v_26281 = stack[-1];
    v_26281 = qcdr(v_26281);
    v_26282 = qcdr(v_26281);
    goto v_25865;
v_25866:
    v_26281 = stack[-6];
    goto v_25867;
v_25868:
    goto v_25862;
v_25863:
    goto v_25864;
v_25865:
    goto v_25866;
v_25867:
    v_26281 = acons(v_26283, v_26282, v_26281);
    env = stack[-14];
    stack[-6] = v_26281;
    goto v_25880;
v_25876:
    v_26281 = stack[-1];
    stack[0] = qcar(v_26281);
    goto v_25877;
v_25878:
    goto v_25888;
v_25884:
    v_26281 = stack[-1];
    v_26281 = qcdr(v_26281);
    v_26282 = qcar(v_26281);
    goto v_25885;
v_25886:
    v_26281 = stack[-1];
    v_26281 = qcdr(v_26281);
    v_26281 = qcdr(v_26281);
    goto v_25887;
v_25888:
    goto v_25884;
v_25885:
    goto v_25886;
v_25887:
    v_26281 = difference2(v_26282, v_26281);
    env = stack[-14];
    goto v_25879;
v_25880:
    goto v_25876;
v_25877:
    goto v_25878;
v_25879:
    v_26281 = cons(stack[0], v_26281);
    env = stack[-14];
    v_26281 = ncons(v_26281);
    env = stack[-14];
    goto v_25854;
v_25855:
    goto v_25851;
v_25852:
    goto v_25853;
v_25854:
    v_26281 = Lrplacd(nil, stack[-2], v_26281);
    env = stack[-14];
    v_26281 = stack[-3];
    v_26281 = qcdr(v_26281);
    stack[-3] = v_26281;
    goto v_25795;
v_25794:
    stack[0] = v_26281;
    v_26281 = stack[-7];
    v_26281 = qcar(v_26281);
    fn = elt(env, 6); // numeric!-content
    v_26281 = (*qfn1(fn))(fn, v_26281);
    env = stack[-14];
    stack[-1] = v_26281;
    v_26281 = stack[-12];
    if (v_26281 == nil) goto v_25902;
    else goto v_25903;
v_25902:
    v_26281 = stack[-6];
    stack[-13] = v_26281;
    v_26281 = stack[-1];
    stack[-12] = v_26281;
    goto v_25901;
v_25903:
    goto v_25914;
v_25910:
    v_26282 = stack[-13];
    goto v_25911;
v_25912:
    v_26281 = stack[-6];
    goto v_25913;
v_25914:
    goto v_25910;
v_25911:
    goto v_25912;
v_25913:
    fn = elt(env, 7); // vintersection
    v_26281 = (*qfn2(fn))(fn, v_26282, v_26281);
    env = stack[-14];
    stack[-13] = v_26281;
    goto v_25922;
v_25918:
    v_26282 = stack[-12];
    goto v_25919;
v_25920:
    v_26281 = stack[-1];
    goto v_25921;
v_25922:
    goto v_25918;
v_25919:
    goto v_25920;
v_25921:
    fn = elt(env, 8); // gcddd
    v_26281 = (*qfn2(fn))(fn, v_26282, v_26281);
    env = stack[-14];
    stack[-12] = v_26281;
    goto v_25901;
v_25901:
    v_26281 = stack[-6];
    stack[-2] = v_26281;
v_25928:
    v_26281 = stack[-2];
    if (v_26281 == nil) goto v_25932;
    else goto v_25933;
v_25932:
    goto v_25927;
v_25933:
    v_26281 = stack[-2];
    v_26281 = qcar(v_26281);
    v_26283 = v_26281;
    goto v_25947;
v_25943:
    v_26281 = v_26283;
    v_26282 = qcdr(v_26281);
    goto v_25944;
v_25945:
    v_26281 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25946;
v_25947:
    goto v_25943;
v_25944:
    goto v_25945;
v_25946:
    if (v_26282 == v_26281) goto v_25942;
    goto v_25956;
v_25952:
    goto v_25953;
v_25954:
    goto v_25964;
v_25960:
    goto v_25970;
v_25966:
    v_26281 = v_26283;
    v_26281 = qcar(v_26281);
    goto v_25967;
v_25968:
    v_26282 = v_26283;
    v_26282 = qcdr(v_26282);
    goto v_25969;
v_25970:
    goto v_25966;
v_25967:
    goto v_25968;
v_25969:
    fn = elt(env, 9); // mksp
    v_26282 = (*qfn2(fn))(fn, v_26281, v_26282);
    env = stack[-14];
    goto v_25961;
v_25962:
    v_26281 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25963;
v_25964:
    goto v_25960;
v_25961:
    goto v_25962;
v_25963:
    v_26281 = cons(v_26282, v_26281);
    env = stack[-14];
    v_26281 = ncons(v_26281);
    env = stack[-14];
    goto v_25955;
v_25956:
    goto v_25952;
v_25953:
    goto v_25954;
v_25955:
    fn = elt(env, 10); // multf
    v_26281 = (*qfn2(fn))(fn, stack[-1], v_26281);
    env = stack[-14];
    stack[-1] = v_26281;
    goto v_25940;
v_25942:
v_25940:
    v_26281 = stack[-2];
    v_26281 = qcdr(v_26281);
    stack[-2] = v_26281;
    goto v_25928;
v_25927:
    goto v_25983;
v_25979:
    goto v_25991;
v_25985:
    v_26281 = stack[-7];
    v_26283 = qcar(v_26281);
    goto v_25986;
v_25987:
    v_26282 = stack[-1];
    goto v_25988;
v_25989:
    v_26281 = elt(env, 1); // "Term content division failed"
    goto v_25990;
v_25991:
    goto v_25985;
v_25986:
    goto v_25987;
v_25988:
    goto v_25989;
v_25990:
    fn = elt(env, 11); // quotfail1
    v_26282 = (*qfnn(fn))(fn, 3, v_26283, v_26282, v_26281);
    env = stack[-14];
    goto v_25980;
v_25981:
    v_26281 = stack[0];
    goto v_25982;
v_25983:
    goto v_25979;
v_25980:
    goto v_25981;
v_25982:
    v_26281 = cons(v_26282, v_26281);
    env = stack[-14];
    v_26281 = ncons(v_26281);
    env = stack[-14];
    stack[-9] = v_26281;
    stack[-10] = v_26281;
v_25773:
    v_26281 = stack[-11];
    v_26281 = qcdr(v_26281);
    stack[-11] = v_26281;
    v_26281 = stack[-11];
    if (v_26281 == nil) goto v_26001;
    else goto v_26002;
v_26001:
    v_26281 = stack[-10];
    goto v_25772;
v_26002:
    goto v_26010;
v_26006:
    stack[-8] = stack[-9];
    goto v_26007;
v_26008:
    v_26281 = stack[-11];
    v_26281 = qcar(v_26281);
    stack[-7] = v_26281;
    stack[-6] = nil;
    v_26281 = stack[-7];
    v_26281 = qcdr(v_26281);
    stack[-5] = v_26281;
    v_26281 = stack[-5];
    if (v_26281 == nil) goto v_26031;
    else goto v_26032;
v_26031:
    v_26281 = nil;
    goto v_26025;
v_26032:
    v_26281 = stack[-5];
    v_26281 = qcar(v_26281);
    stack[-1] = v_26281;
    goto v_26046;
v_26040:
    v_26281 = stack[-1];
    v_26283 = qcar(v_26281);
    goto v_26041;
v_26042:
    v_26281 = stack[-1];
    v_26281 = qcdr(v_26281);
    v_26282 = qcdr(v_26281);
    goto v_26043;
v_26044:
    v_26281 = stack[-6];
    goto v_26045;
v_26046:
    goto v_26040;
v_26041:
    goto v_26042;
v_26043:
    goto v_26044;
v_26045:
    v_26281 = acons(v_26283, v_26282, v_26281);
    env = stack[-14];
    stack[-6] = v_26281;
    goto v_26058;
v_26054:
    v_26281 = stack[-1];
    stack[0] = qcar(v_26281);
    goto v_26055;
v_26056:
    goto v_26066;
v_26062:
    v_26281 = stack[-1];
    v_26281 = qcdr(v_26281);
    v_26282 = qcar(v_26281);
    goto v_26063;
v_26064:
    v_26281 = stack[-1];
    v_26281 = qcdr(v_26281);
    v_26281 = qcdr(v_26281);
    goto v_26065;
v_26066:
    goto v_26062;
v_26063:
    goto v_26064;
v_26065:
    v_26281 = difference2(v_26282, v_26281);
    env = stack[-14];
    goto v_26057;
v_26058:
    goto v_26054;
v_26055:
    goto v_26056;
v_26057:
    v_26281 = cons(stack[0], v_26281);
    env = stack[-14];
    v_26281 = ncons(v_26281);
    env = stack[-14];
    stack[-3] = v_26281;
    stack[-4] = v_26281;
v_26026:
    v_26281 = stack[-5];
    v_26281 = qcdr(v_26281);
    stack[-5] = v_26281;
    v_26281 = stack[-5];
    if (v_26281 == nil) goto v_26077;
    else goto v_26078;
v_26077:
    v_26281 = stack[-4];
    goto v_26025;
v_26078:
    goto v_26086;
v_26082:
    stack[-2] = stack[-3];
    goto v_26083;
v_26084:
    v_26281 = stack[-5];
    v_26281 = qcar(v_26281);
    stack[-1] = v_26281;
    goto v_26099;
v_26093:
    v_26281 = stack[-1];
    v_26283 = qcar(v_26281);
    goto v_26094;
v_26095:
    v_26281 = stack[-1];
    v_26281 = qcdr(v_26281);
    v_26282 = qcdr(v_26281);
    goto v_26096;
v_26097:
    v_26281 = stack[-6];
    goto v_26098;
v_26099:
    goto v_26093;
v_26094:
    goto v_26095;
v_26096:
    goto v_26097;
v_26098:
    v_26281 = acons(v_26283, v_26282, v_26281);
    env = stack[-14];
    stack[-6] = v_26281;
    goto v_26111;
v_26107:
    v_26281 = stack[-1];
    stack[0] = qcar(v_26281);
    goto v_26108;
v_26109:
    goto v_26119;
v_26115:
    v_26281 = stack[-1];
    v_26281 = qcdr(v_26281);
    v_26282 = qcar(v_26281);
    goto v_26116;
v_26117:
    v_26281 = stack[-1];
    v_26281 = qcdr(v_26281);
    v_26281 = qcdr(v_26281);
    goto v_26118;
v_26119:
    goto v_26115;
v_26116:
    goto v_26117;
v_26118:
    v_26281 = difference2(v_26282, v_26281);
    env = stack[-14];
    goto v_26110;
v_26111:
    goto v_26107;
v_26108:
    goto v_26109;
v_26110:
    v_26281 = cons(stack[0], v_26281);
    env = stack[-14];
    v_26281 = ncons(v_26281);
    env = stack[-14];
    goto v_26085;
v_26086:
    goto v_26082;
v_26083:
    goto v_26084;
v_26085:
    v_26281 = Lrplacd(nil, stack[-2], v_26281);
    env = stack[-14];
    v_26281 = stack[-3];
    v_26281 = qcdr(v_26281);
    stack[-3] = v_26281;
    goto v_26026;
v_26025:
    stack[0] = v_26281;
    v_26281 = stack[-7];
    v_26281 = qcar(v_26281);
    fn = elt(env, 6); // numeric!-content
    v_26281 = (*qfn1(fn))(fn, v_26281);
    env = stack[-14];
    stack[-1] = v_26281;
    v_26281 = stack[-12];
    if (v_26281 == nil) goto v_26133;
    else goto v_26134;
v_26133:
    v_26281 = stack[-6];
    stack[-13] = v_26281;
    v_26281 = stack[-1];
    stack[-12] = v_26281;
    goto v_26132;
v_26134:
    goto v_26145;
v_26141:
    v_26282 = stack[-13];
    goto v_26142;
v_26143:
    v_26281 = stack[-6];
    goto v_26144;
v_26145:
    goto v_26141;
v_26142:
    goto v_26143;
v_26144:
    fn = elt(env, 7); // vintersection
    v_26281 = (*qfn2(fn))(fn, v_26282, v_26281);
    env = stack[-14];
    stack[-13] = v_26281;
    goto v_26153;
v_26149:
    v_26282 = stack[-12];
    goto v_26150;
v_26151:
    v_26281 = stack[-1];
    goto v_26152;
v_26153:
    goto v_26149;
v_26150:
    goto v_26151;
v_26152:
    fn = elt(env, 8); // gcddd
    v_26281 = (*qfn2(fn))(fn, v_26282, v_26281);
    env = stack[-14];
    stack[-12] = v_26281;
    goto v_26132;
v_26132:
    v_26281 = stack[-6];
    stack[-2] = v_26281;
v_26159:
    v_26281 = stack[-2];
    if (v_26281 == nil) goto v_26163;
    else goto v_26164;
v_26163:
    goto v_26158;
v_26164:
    v_26281 = stack[-2];
    v_26281 = qcar(v_26281);
    v_26283 = v_26281;
    goto v_26178;
v_26174:
    v_26281 = v_26283;
    v_26282 = qcdr(v_26281);
    goto v_26175;
v_26176:
    v_26281 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_26177;
v_26178:
    goto v_26174;
v_26175:
    goto v_26176;
v_26177:
    if (v_26282 == v_26281) goto v_26173;
    goto v_26187;
v_26183:
    goto v_26184;
v_26185:
    goto v_26195;
v_26191:
    goto v_26201;
v_26197:
    v_26281 = v_26283;
    v_26281 = qcar(v_26281);
    goto v_26198;
v_26199:
    v_26282 = v_26283;
    v_26282 = qcdr(v_26282);
    goto v_26200;
v_26201:
    goto v_26197;
v_26198:
    goto v_26199;
v_26200:
    fn = elt(env, 9); // mksp
    v_26282 = (*qfn2(fn))(fn, v_26281, v_26282);
    env = stack[-14];
    goto v_26192;
v_26193:
    v_26281 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26194;
v_26195:
    goto v_26191;
v_26192:
    goto v_26193;
v_26194:
    v_26281 = cons(v_26282, v_26281);
    env = stack[-14];
    v_26281 = ncons(v_26281);
    env = stack[-14];
    goto v_26186;
v_26187:
    goto v_26183;
v_26184:
    goto v_26185;
v_26186:
    fn = elt(env, 10); // multf
    v_26281 = (*qfn2(fn))(fn, stack[-1], v_26281);
    env = stack[-14];
    stack[-1] = v_26281;
    goto v_26171;
v_26173:
v_26171:
    v_26281 = stack[-2];
    v_26281 = qcdr(v_26281);
    stack[-2] = v_26281;
    goto v_26159;
v_26158:
    goto v_26214;
v_26210:
    goto v_26222;
v_26216:
    v_26281 = stack[-7];
    v_26283 = qcar(v_26281);
    goto v_26217;
v_26218:
    v_26282 = stack[-1];
    goto v_26219;
v_26220:
    v_26281 = elt(env, 1); // "Term content division failed"
    goto v_26221;
v_26222:
    goto v_26216;
v_26217:
    goto v_26218;
v_26219:
    goto v_26220;
v_26221:
    fn = elt(env, 11); // quotfail1
    v_26282 = (*qfnn(fn))(fn, 3, v_26283, v_26282, v_26281);
    env = stack[-14];
    goto v_26211;
v_26212:
    v_26281 = stack[0];
    goto v_26213;
v_26214:
    goto v_26210;
v_26211:
    goto v_26212;
v_26213:
    v_26281 = cons(v_26282, v_26281);
    env = stack[-14];
    v_26281 = ncons(v_26281);
    env = stack[-14];
    goto v_26009;
v_26010:
    goto v_26006;
v_26007:
    goto v_26008;
v_26009:
    v_26281 = Lrplacd(nil, stack[-8], v_26281);
    env = stack[-14];
    v_26281 = stack[-9];
    v_26281 = qcdr(v_26281);
    stack[-9] = v_26281;
    goto v_25773;
v_25772:
    stack[0] = v_26281;
    v_26281 = stack[-13];
    stack[-1] = v_26281;
v_26233:
    v_26281 = stack[-1];
    if (v_26281 == nil) goto v_26237;
    else goto v_26238;
v_26237:
    goto v_26232;
v_26238:
    v_26281 = stack[-1];
    v_26281 = qcar(v_26281);
    goto v_26249;
v_26245:
    stack[-2] = stack[-12];
    goto v_26246;
v_26247:
    goto v_26257;
v_26253:
    goto v_26263;
v_26259:
    v_26282 = v_26281;
    v_26282 = qcar(v_26282);
    goto v_26260;
v_26261:
    v_26281 = qcdr(v_26281);
    goto v_26262;
v_26263:
    goto v_26259;
v_26260:
    goto v_26261;
v_26262:
    fn = elt(env, 9); // mksp
    v_26282 = (*qfn2(fn))(fn, v_26282, v_26281);
    env = stack[-14];
    goto v_26254;
v_26255:
    v_26281 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26256;
v_26257:
    goto v_26253;
v_26254:
    goto v_26255;
v_26256:
    v_26281 = cons(v_26282, v_26281);
    env = stack[-14];
    v_26281 = ncons(v_26281);
    env = stack[-14];
    goto v_26248;
v_26249:
    goto v_26245;
v_26246:
    goto v_26247;
v_26248:
    fn = elt(env, 10); // multf
    v_26281 = (*qfn2(fn))(fn, stack[-2], v_26281);
    env = stack[-14];
    stack[-12] = v_26281;
    v_26281 = stack[-1];
    v_26281 = qcdr(v_26281);
    stack[-1] = v_26281;
    goto v_26233;
v_26232:
    goto v_26277;
v_26273:
    stack[-1] = stack[-12];
    goto v_26274;
v_26275:
    v_26281 = stack[0];
    fn = elt(env, 12); // gcdlist1
    v_26281 = (*qfn1(fn))(fn, v_26281);
    env = stack[-14];
    goto v_26276;
v_26277:
    goto v_26273;
v_26274:
    goto v_26275;
v_26276:
    fn = elt(env, 10); // multf
    v_26281 = (*qfn2(fn))(fn, stack[-1], v_26281);
    env = stack[-14];
    {
        fn = elt(env, 2); // poly!-abs
        return (*qfn1(fn))(fn, v_26281);
    }
v_25680:
    goto v_25637;
    v_26281 = nil;
v_25637:
    return onevalue(v_26281);
}



// Code for enter!-sorted

static LispObject CC_enterKsorted(LispObject env,
                         LispObject v_25634, LispObject v_25635)
{
    env = qenv(env);
    LispObject v_25696, v_25697;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25634,v_25635);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_25635;
    stack[-1] = v_25634;
// end of prologue
    stack[-2] = nil;
v_25640:
    v_25696 = stack[0];
    if (v_25696 == nil) goto v_25643;
    else goto v_25644;
v_25643:
    goto v_25651;
v_25647:
    stack[0] = stack[-2];
    goto v_25648;
v_25649:
    v_25696 = stack[-1];
    v_25696 = ncons(v_25696);
    env = stack[-3];
    goto v_25650;
v_25651:
    goto v_25647;
v_25648:
    goto v_25649;
v_25650:
    {
        LispObject v_25701 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_25701, v_25696);
    }
v_25644:
    goto v_25662;
v_25658:
    v_25696 = stack[-1];
    v_25697 = qcar(v_25696);
    goto v_25659;
v_25660:
    v_25696 = stack[0];
    v_25696 = qcar(v_25696);
    v_25696 = qcar(v_25696);
    goto v_25661;
v_25662:
    goto v_25658;
v_25659:
    goto v_25660;
v_25661:
    fn = elt(env, 2); // taydegree!<
    v_25696 = (*qfn2(fn))(fn, v_25697, v_25696);
    env = stack[-3];
    if (v_25696 == nil) goto v_25656;
    goto v_25673;
v_25669:
    goto v_25670;
v_25671:
    goto v_25680;
v_25676:
    v_25697 = stack[-1];
    goto v_25677;
v_25678:
    v_25696 = stack[0];
    goto v_25679;
v_25680:
    goto v_25676;
v_25677:
    goto v_25678;
v_25679:
    v_25696 = cons(v_25697, v_25696);
    env = stack[-3];
    goto v_25672;
v_25673:
    goto v_25669;
v_25670:
    goto v_25671;
v_25672:
    {
        LispObject v_25702 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_25702, v_25696);
    }
v_25656:
    goto v_25690;
v_25686:
    v_25696 = stack[0];
    v_25697 = qcar(v_25696);
    goto v_25687;
v_25688:
    v_25696 = stack[-2];
    goto v_25689;
v_25690:
    goto v_25686;
v_25687:
    goto v_25688;
v_25689:
    v_25696 = cons(v_25697, v_25696);
    env = stack[-3];
    stack[-2] = v_25696;
    v_25696 = stack[0];
    v_25696 = qcdr(v_25696);
    stack[0] = v_25696;
    goto v_25640;
    v_25696 = nil;
    return onevalue(v_25696);
}



// Code for iv_cutn

static LispObject CC_iv_cutn(LispObject env,
                         LispObject v_25634)
{
    env = qenv(env);
    LispObject v_25657, v_25658;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25634);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_25658 = v_25634;
// end of prologue
    v_25657 = v_25658;
    v_25657 = qcdr(v_25657);
    if (v_25657 == nil) goto v_25639;
    goto v_25647;
v_25643:
    v_25657 = v_25658;
    stack[0] = qcar(v_25657);
    goto v_25644;
v_25645:
    v_25657 = v_25658;
    v_25657 = qcdr(v_25657);
    v_25657 = CC_iv_cutn(elt(env, 0), v_25657);
    env = stack[-1];
    goto v_25646;
v_25647:
    goto v_25643;
v_25644:
    goto v_25645;
v_25646:
    {
        LispObject v_25660 = stack[0];
        fn = elt(env, 1); // iv_cut
        return (*qfn2(fn))(fn, v_25660, v_25657);
    }
v_25639:
    v_25657 = v_25658;
    v_25657 = qcar(v_25657);
    goto v_25637;
    v_25657 = nil;
v_25637:
    return onevalue(v_25657);
}



// Code for cols2rows2

static LispObject CC_cols2rows2(LispObject env,
                         LispObject v_25634, LispObject v_25635)
{
    env = qenv(env);
    LispObject v_25673, v_25674;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25634,v_25635);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_25635;
    stack[-1] = v_25634;
// end of prologue
    goto v_25647;
v_25643:
    v_25674 = stack[0];
    goto v_25644;
v_25645:
    v_25673 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25646;
v_25647:
    goto v_25643;
v_25644:
    goto v_25645;
v_25646:
    if (v_25674 == v_25673) goto v_25642;
    goto v_25655;
v_25651:
    goto v_25661;
v_25657:
    v_25674 = stack[-1];
    goto v_25658;
v_25659:
    v_25673 = stack[0];
    goto v_25660;
v_25661:
    goto v_25657;
v_25658:
    goto v_25659;
v_25660:
    fn = elt(env, 1); // ithlistelem
    stack[-2] = (*qfn2(fn))(fn, v_25674, v_25673);
    env = stack[-3];
    goto v_25652;
v_25653:
    goto v_25669;
v_25665:
    goto v_25666;
v_25667:
    v_25673 = stack[0];
    v_25673 = sub1(v_25673);
    env = stack[-3];
    goto v_25668;
v_25669:
    goto v_25665;
v_25666:
    goto v_25667;
v_25668:
    v_25673 = CC_cols2rows2(elt(env, 0), stack[-1], v_25673);
    goto v_25654;
v_25655:
    goto v_25651;
v_25652:
    goto v_25653;
v_25654:
    {
        LispObject v_25678 = stack[-2];
        return cons(v_25678, v_25673);
    }
v_25642:
    v_25673 = nil;
    return onevalue(v_25673);
}



// Code for ldf!-dep!-var

static LispObject CC_ldfKdepKvar(LispObject env,
                         LispObject v_25634)
{
    env = qenv(env);
    LispObject v_25687, v_25688;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25634);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_25687 = v_25634;
// end of prologue
    stack[-2] = nil;
    stack[-1] = v_25687;
v_25642:
    v_25687 = stack[-1];
    if (v_25687 == nil) goto v_25646;
    else goto v_25647;
v_25646:
    goto v_25641;
v_25647:
    v_25687 = stack[-1];
    v_25687 = qcar(v_25687);
    stack[0] = v_25687;
    goto v_25661;
v_25657:
    v_25687 = stack[0];
    fn = elt(env, 2); // ldt!-tvar
    v_25688 = (*qfn1(fn))(fn, v_25687);
    env = stack[-3];
    goto v_25658;
v_25659:
    v_25687 = qvalue(elt(env, 1)); // depl!*
    goto v_25660;
v_25661:
    goto v_25657;
v_25658:
    goto v_25659;
v_25660:
    v_25687 = Lassoc(nil, v_25688, v_25687);
    if (v_25687 == nil) goto v_25656;
    goto v_25671;
v_25667:
    goto v_25676;
v_25672:
    v_25687 = stack[0];
    fn = elt(env, 2); // ldt!-tvar
    v_25688 = (*qfn1(fn))(fn, v_25687);
    env = stack[-3];
    goto v_25673;
v_25674:
    v_25687 = qvalue(elt(env, 1)); // depl!*
    goto v_25675;
v_25676:
    goto v_25672;
v_25673:
    goto v_25674;
v_25675:
    v_25687 = Lassoc(nil, v_25688, v_25687);
    v_25688 = qcdr(v_25687);
    goto v_25668;
v_25669:
    v_25687 = stack[-2];
    goto v_25670;
v_25671:
    goto v_25667;
v_25668:
    goto v_25669;
v_25670:
    v_25687 = Lappend(nil, v_25688, v_25687);
    env = stack[-3];
    stack[-2] = v_25687;
    goto v_25654;
v_25656:
v_25654:
    v_25687 = stack[-1];
    v_25687 = qcdr(v_25687);
    stack[-1] = v_25687;
    goto v_25642;
v_25641:
    v_25687 = stack[-2];
    {
        fn = elt(env, 3); // makeset
        return (*qfn1(fn))(fn, v_25687);
    }
    return onevalue(v_25687);
}



// Code for ndepends

static LispObject CC_ndepends(LispObject env,
                         LispObject v_25634, LispObject v_25635)
{
    env = qenv(env);
    LispObject v_25816, v_25817, v_25818;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25634,v_25635);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_25635;
    stack[-1] = v_25634;
// end of prologue
    v_25816 = stack[-1];
    if (v_25816 == nil) goto v_25643;
    else goto v_25644;
v_25643:
    v_25816 = lisp_true;
    goto v_25642;
v_25644:
    v_25816 = stack[-1];
    v_25816 = (is_number(v_25816) ? lisp_true : nil);
    if (v_25816 == nil) goto v_25651;
    else goto v_25650;
v_25651:
    v_25816 = stack[0];
    v_25816 = (is_number(v_25816) ? lisp_true : nil);
v_25650:
    goto v_25642;
    v_25816 = nil;
v_25642:
    if (v_25816 == nil) goto v_25640;
    v_25816 = nil;
    goto v_25638;
v_25640:
    goto v_25663;
v_25659:
    v_25817 = stack[-1];
    goto v_25660;
v_25661:
    v_25816 = stack[0];
    goto v_25662;
v_25663:
    goto v_25659;
v_25660:
    goto v_25661;
v_25662:
    if (equal(v_25817, v_25816)) goto v_25657;
    else goto v_25658;
v_25657:
    v_25816 = stack[-1];
    goto v_25638;
v_25658:
    v_25816 = stack[-1];
    if (!consp(v_25816)) goto v_25671;
    else goto v_25672;
v_25671:
    goto v_25678;
v_25674:
    v_25817 = stack[-1];
    goto v_25675;
v_25676:
    v_25816 = qvalue(elt(env, 1)); // frlis!*
    goto v_25677;
v_25678:
    goto v_25674;
v_25675:
    goto v_25676;
v_25677:
    v_25816 = Lmemq(nil, v_25817, v_25816);
    goto v_25670;
v_25672:
    v_25816 = nil;
    goto v_25670;
    v_25816 = nil;
v_25670:
    if (v_25816 == nil) goto v_25668;
    v_25816 = lisp_true;
    goto v_25638;
v_25668:
    goto v_25692;
v_25688:
    v_25817 = stack[-1];
    goto v_25689;
v_25690:
    v_25816 = qvalue(elt(env, 2)); // depl!*
    goto v_25691;
v_25692:
    goto v_25688;
v_25689:
    goto v_25690;
v_25691:
    v_25816 = Lassoc(nil, v_25817, v_25816);
    v_25817 = v_25816;
    v_25816 = v_25817;
    if (v_25816 == nil) goto v_25699;
    else goto v_25700;
v_25699:
    v_25816 = nil;
    goto v_25698;
v_25700:
    goto v_25710;
v_25706:
    v_25816 = v_25817;
    v_25817 = qcdr(v_25816);
    goto v_25707;
v_25708:
    v_25816 = stack[0];
    goto v_25709;
v_25710:
    goto v_25706;
v_25707:
    goto v_25708;
v_25709:
    fn = elt(env, 4); // lndepends
    v_25816 = (*qfn2(fn))(fn, v_25817, v_25816);
    env = stack[-2];
    goto v_25698;
    v_25816 = nil;
v_25698:
    if (v_25816 == nil) goto v_25687;
    v_25816 = lisp_true;
    goto v_25638;
v_25687:
    v_25816 = stack[-1];
    if (!consp(v_25816)) goto v_25720;
    v_25816 = stack[-1];
    v_25816 = qcar(v_25816);
    if (symbolp(v_25816)) goto v_25725;
    v_25816 = nil;
    goto v_25723;
v_25725:
    v_25816 = stack[-1];
    v_25816 = qcar(v_25816);
    if (!symbolp(v_25816)) v_25816 = nil;
    else { v_25816 = qfastgets(v_25816);
           if (v_25816 != nil) { v_25816 = elt(v_25816, 8); // dname
#ifdef RECORD_GET
             if (v_25816 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_25816 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_25816 == SPID_NOPROP) v_25816 = nil; }}
#endif
    goto v_25723;
    v_25816 = nil;
v_25723:
    goto v_25718;
v_25720:
    v_25816 = nil;
    goto v_25718;
    v_25816 = nil;
v_25718:
    if (v_25816 == nil) goto v_25716;
    goto v_25742;
v_25738:
    v_25816 = stack[-1];
    v_25817 = qcar(v_25816);
    goto v_25739;
v_25740:
    v_25816 = elt(env, 3); // domain!-depends!-fn
    goto v_25741;
v_25742:
    goto v_25738;
v_25739:
    goto v_25740;
v_25741:
    v_25816 = get(v_25817, v_25816);
    v_25817 = v_25816;
    v_25816 = v_25817;
    if (v_25816 == nil) goto v_25750;
    goto v_25759;
v_25753:
    v_25818 = v_25817;
    goto v_25754;
v_25755:
    v_25817 = stack[-1];
    goto v_25756;
v_25757:
    v_25816 = stack[0];
    goto v_25758;
v_25759:
    goto v_25753;
v_25754:
    goto v_25755;
v_25756:
    goto v_25757;
v_25758:
        return Lapply2(nil, 3, v_25818, v_25817, v_25816);
v_25750:
    v_25816 = nil;
    goto v_25748;
    v_25816 = nil;
v_25748:
    goto v_25638;
v_25716:
    v_25816 = stack[-1];
    fn = elt(env, 5); // atomf
    v_25816 = (*qfn1(fn))(fn, v_25816);
    env = stack[-2];
    if (v_25816 == nil) goto v_25770;
    else goto v_25771;
v_25770:
    goto v_25782;
v_25778:
    v_25816 = stack[-1];
    v_25817 = qcdr(v_25816);
    goto v_25779;
v_25780:
    v_25816 = stack[0];
    goto v_25781;
v_25782:
    goto v_25778;
v_25779:
    goto v_25780;
v_25781:
    fn = elt(env, 4); // lndepends
    v_25816 = (*qfn2(fn))(fn, v_25817, v_25816);
    env = stack[-2];
    if (v_25816 == nil) goto v_25776;
    else goto v_25775;
v_25776:
    goto v_25791;
v_25787:
    v_25816 = stack[-1];
    v_25817 = qcar(v_25816);
    goto v_25788;
v_25789:
    v_25816 = stack[0];
    goto v_25790;
v_25791:
    goto v_25787;
v_25788:
    goto v_25789;
v_25790:
    v_25816 = CC_ndepends(elt(env, 0), v_25817, v_25816);
    env = stack[-2];
v_25775:
    goto v_25769;
v_25771:
    v_25816 = nil;
    goto v_25769;
    v_25816 = nil;
v_25769:
    if (v_25816 == nil) goto v_25767;
    v_25816 = lisp_true;
    goto v_25638;
v_25767:
    v_25816 = stack[0];
    fn = elt(env, 5); // atomf
    v_25816 = (*qfn1(fn))(fn, v_25816);
    if (v_25816 == nil) goto v_25801;
    else goto v_25799;
v_25801:
    v_25816 = stack[0];
    v_25816 = qcar(v_25816);
    if (symbolp(v_25816)) goto v_25805;
    else goto v_25804;
v_25805:
    v_25816 = stack[0];
    v_25816 = qcar(v_25816);
    if (!symbolp(v_25816)) v_25816 = nil;
    else { v_25816 = qfastgets(v_25816);
           if (v_25816 != nil) { v_25816 = elt(v_25816, 8); // dname
#ifdef RECORD_GET
             if (v_25816 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_25816 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_25816 == SPID_NOPROP) v_25816 = nil; }}
#endif
    if (v_25816 == nil) goto v_25804;
    goto v_25799;
v_25804:
    goto v_25800;
v_25799:
    v_25816 = nil;
    goto v_25638;
v_25800:
    v_25816 = nil;
    goto v_25638;
    v_25816 = nil;
v_25638:
    return onevalue(v_25816);
}



// Code for make_spoly_pair

static LispObject CC_make_spoly_pair(LispObject env,
                         LispObject v_25634, LispObject v_25635)
{
    env = qenv(env);
    LispObject v_25733, v_25734, v_25735, v_25736;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25634,v_25635);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_25635;
    stack[-3] = v_25634;
// end of prologue
v_25640:
    goto v_25650;
v_25646:
    v_25734 = stack[-2];
    goto v_25647;
v_25648:
    v_25733 = stack[-3];
    goto v_25649;
v_25650:
    goto v_25646;
v_25647:
    goto v_25648;
v_25649:
    fn = elt(env, 2); // pfordp
    v_25733 = (*qfn2(fn))(fn, v_25734, v_25733);
    env = stack[-5];
    if (v_25733 == nil) goto v_25644;
    v_25733 = stack[-2];
    v_25734 = v_25733;
    v_25733 = stack[-3];
    stack[-2] = v_25733;
    v_25733 = v_25734;
    stack[-3] = v_25733;
    goto v_25640;
v_25644:
    goto v_25663;
v_25659:
    v_25733 = stack[-3];
    fn = elt(env, 3); // xval
    stack[0] = (*qfn1(fn))(fn, v_25733);
    env = stack[-5];
    goto v_25660;
v_25661:
    v_25733 = stack[-2];
    fn = elt(env, 3); // xval
    v_25733 = (*qfn1(fn))(fn, v_25733);
    env = stack[-5];
    goto v_25662;
v_25663:
    goto v_25659;
v_25660:
    goto v_25661;
v_25662:
    fn = elt(env, 4); // xlcm
    v_25733 = (*qfn2(fn))(fn, stack[0], v_25733);
    env = stack[-5];
    stack[-4] = v_25733;
    v_25733 = stack[-3];
    v_25733 = qcdr(v_25733);
    if (v_25733 == nil) goto v_25677;
    else goto v_25676;
v_25677:
    v_25733 = stack[-2];
    v_25733 = qcdr(v_25733);
    if (v_25733 == nil) goto v_25680;
    else goto v_25676;
v_25680:
    v_25733 = nil;
    goto v_25674;
v_25676:
    goto v_25697;
v_25691:
    stack[-1] = stack[-4];
    goto v_25692;
v_25693:
    v_25733 = stack[-3];
    fn = elt(env, 3); // xval
    stack[0] = (*qfn1(fn))(fn, v_25733);
    env = stack[-5];
    goto v_25694;
v_25695:
    v_25733 = stack[-2];
    fn = elt(env, 3); // xval
    v_25733 = (*qfn1(fn))(fn, v_25733);
    env = stack[-5];
    goto v_25696;
v_25697:
    goto v_25691;
v_25692:
    goto v_25693;
v_25694:
    goto v_25695;
v_25696:
    fn = elt(env, 5); // triviallcm
    v_25733 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_25733);
    env = stack[-5];
    if (v_25733 == nil) goto v_25688;
    else goto v_25689;
v_25688:
    v_25733 = stack[-4];
    fn = elt(env, 6); // mknwedge
    v_25733 = (*qfn1(fn))(fn, v_25733);
    env = stack[-5];
    fn = elt(env, 7); // xdegreecheck
    v_25733 = (*qfn1(fn))(fn, v_25733);
    env = stack[-5];
    if (v_25733 == nil) goto v_25705;
    else goto v_25706;
v_25705:
    goto v_25719;
v_25711:
    v_25735 = stack[-4];
    goto v_25712;
v_25713:
    v_25736 = elt(env, 1); // spoly_pair
    goto v_25714;
v_25715:
    v_25734 = stack[-3];
    goto v_25716;
v_25717:
    v_25733 = stack[-2];
    goto v_25718;
v_25719:
    goto v_25711;
v_25712:
    goto v_25713;
v_25714:
    goto v_25715;
v_25716:
    goto v_25717;
v_25718:
    return list4(v_25735, v_25736, v_25734, v_25733);
v_25706:
    v_25733 = nil;
    goto v_25704;
    v_25733 = nil;
v_25704:
    goto v_25687;
v_25689:
    v_25733 = nil;
    goto v_25687;
    v_25733 = nil;
v_25687:
    goto v_25674;
    v_25733 = nil;
v_25674:
    goto v_25670;
    v_25733 = nil;
    goto v_25670;
    v_25733 = nil;
v_25670:
    goto v_25639;
    v_25733 = nil;
v_25639:
    return onevalue(v_25733);
}



// Code for all_defined_map_

static LispObject CC_all_defined_map_(LispObject env,
                         LispObject v_25634, LispObject v_25635)
{
    env = qenv(env);
    LispObject v_25648, v_25649, v_25650;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_25648 = v_25635;
    v_25649 = v_25634;
// end of prologue
    goto v_25644;
v_25638:
    v_25650 = v_25649;
    goto v_25639;
v_25640:
    v_25649 = nil;
    goto v_25641;
v_25642:
    goto v_25643;
v_25644:
    goto v_25638;
v_25639:
    goto v_25640;
v_25641:
    goto v_25642;
v_25643:
    {
        fn = elt(env, 1); // al1_defined_map_
        return (*qfnn(fn))(fn, 3, v_25650, v_25649, v_25648);
    }
}



// Code for rl_nnfnot

static LispObject CC_rl_nnfnot(LispObject env,
                         LispObject v_25634)
{
    env = qenv(env);
    LispObject v_25645;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25634);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_25645 = v_25634;
// end of prologue
    goto v_25641;
v_25637:
    stack[0] = qvalue(elt(env, 1)); // rl_nnfnot!*
    goto v_25638;
v_25639:
    v_25645 = ncons(v_25645);
    env = stack[-1];
    goto v_25640;
v_25641:
    goto v_25637;
v_25638:
    goto v_25639;
v_25640:
    {
        LispObject v_25647 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_25647, v_25645);
    }
}



// Code for nlist

static LispObject CC_nlist(LispObject env,
                         LispObject v_25634, LispObject v_25635)
{
    env = qenv(env);
    LispObject v_25666, v_25667;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25634,v_25635);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_25635;
    stack[-1] = v_25634;
// end of prologue
    stack[-2] = nil;
v_25640:
    goto v_25649;
v_25645:
    v_25667 = stack[0];
    goto v_25646;
v_25647:
    v_25666 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25648;
v_25649:
    goto v_25645;
v_25646:
    goto v_25647;
v_25648:
    if (v_25667 == v_25666) goto v_25643;
    else goto v_25644;
v_25643:
    v_25666 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_25666);
    }
v_25644:
    goto v_25661;
v_25657:
    v_25667 = stack[-1];
    goto v_25658;
v_25659:
    v_25666 = stack[-2];
    goto v_25660;
v_25661:
    goto v_25657;
v_25658:
    goto v_25659;
v_25660:
    v_25666 = cons(v_25667, v_25666);
    env = stack[-3];
    stack[-2] = v_25666;
    v_25666 = stack[0];
    v_25666 = sub1(v_25666);
    env = stack[-3];
    stack[0] = v_25666;
    goto v_25640;
    v_25666 = nil;
    return onevalue(v_25666);
}



// Code for makecoeffpairshom

static LispObject CC_makecoeffpairshom(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25984, v_25985, v_25986, v_25987;
    LispObject fn;
    LispObject v_25637, v_25636, v_25635, v_25634;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "makecoeffpairshom");
    va_start(aa, nargs);
    v_25634 = va_arg(aa, LispObject);
    v_25635 = va_arg(aa, LispObject);
    v_25636 = va_arg(aa, LispObject);
    v_25637 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_25637,v_25636,v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_25634,v_25635,v_25636,v_25637);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(17);
// copy arguments values to proper place
    stack[-11] = v_25637;
    stack[-12] = v_25636;
    stack[-13] = v_25635;
    stack[-14] = v_25634;
// end of prologue
    v_25984 = stack[-12];
    if (v_25984 == nil) goto v_25641;
    else goto v_25642;
v_25641:
    v_25984 = elt(env, 1); // ((nil))
    goto v_25640;
v_25642:
    v_25984 = stack[-13];
    v_25984 = qcar(v_25984);
    stack[-15] = v_25984;
v_25652:
    goto v_25666;
v_25662:
    stack[0] = stack[-11];
    goto v_25663;
v_25664:
    goto v_25673;
v_25669:
    v_25984 = stack[-14];
    v_25985 = qcar(v_25984);
    goto v_25670;
v_25671:
    v_25984 = stack[-15];
    goto v_25672;
v_25673:
    goto v_25669;
v_25670:
    goto v_25671;
v_25672:
    fn = elt(env, 2); // tayexp!-difference
    v_25984 = (*qfn2(fn))(fn, v_25985, v_25984);
    env = stack[-16];
    goto v_25665;
v_25666:
    goto v_25662;
v_25663:
    goto v_25664;
v_25665:
    fn = elt(env, 3); // tayexp!-times2
    v_25984 = (*qfn2(fn))(fn, stack[0], v_25984);
    env = stack[-16];
    fn = elt(env, 4); // tayexp!-minusp
    v_25984 = (*qfn1(fn))(fn, v_25984);
    env = stack[-16];
    if (v_25984 == nil) goto v_25659;
    v_25984 = nil;
    goto v_25651;
v_25659:
    goto v_25693;
v_25685:
    v_25984 = stack[-14];
    v_25987 = qcdr(v_25984);
    goto v_25686;
v_25687:
    v_25984 = stack[-13];
    v_25986 = qcdr(v_25984);
    goto v_25688;
v_25689:
    v_25984 = stack[-12];
    v_25985 = qcdr(v_25984);
    goto v_25690;
v_25691:
    v_25984 = stack[-11];
    goto v_25692;
v_25693:
    goto v_25685;
v_25686:
    goto v_25687;
v_25688:
    goto v_25689;
v_25690:
    goto v_25691;
v_25692:
    v_25984 = CC_makecoeffpairshom(elt(env, 0), 4, v_25987, v_25986, v_25985, v_25984);
    env = stack[-16];
    stack[-7] = v_25984;
    v_25984 = stack[-7];
    if (v_25984 == nil) goto v_25703;
    else goto v_25704;
v_25703:
    v_25984 = nil;
    goto v_25682;
v_25704:
    v_25984 = stack[-7];
    v_25984 = qcar(v_25984);
    stack[-3] = v_25984;
    goto v_25718;
v_25712:
    stack[-2] = stack[-15];
    goto v_25713;
v_25714:
    v_25984 = stack[-3];
    stack[-1] = qcar(v_25984);
    goto v_25715;
v_25716:
    goto v_25727;
v_25723:
    goto v_25733;
v_25729:
    v_25984 = stack[-13];
    stack[0] = qcar(v_25984);
    goto v_25730;
v_25731:
    goto v_25741;
v_25737:
    v_25984 = stack[-12];
    v_25985 = qcar(v_25984);
    goto v_25738;
v_25739:
    v_25984 = stack[-15];
    goto v_25740;
v_25741:
    goto v_25737;
v_25738:
    goto v_25739;
v_25740:
    fn = elt(env, 2); // tayexp!-difference
    v_25984 = (*qfn2(fn))(fn, v_25985, v_25984);
    env = stack[-16];
    goto v_25732;
v_25733:
    goto v_25729;
v_25730:
    goto v_25731;
v_25732:
    fn = elt(env, 5); // tayexp!-plus2
    v_25985 = (*qfn2(fn))(fn, stack[0], v_25984);
    env = stack[-16];
    goto v_25724;
v_25725:
    v_25984 = stack[-3];
    v_25984 = qcdr(v_25984);
    goto v_25726;
v_25727:
    goto v_25723;
v_25724:
    goto v_25725;
v_25726:
    v_25984 = cons(v_25985, v_25984);
    env = stack[-16];
    goto v_25717;
v_25718:
    goto v_25712;
v_25713:
    goto v_25714;
v_25715:
    goto v_25716;
v_25717:
    v_25984 = acons(stack[-2], stack[-1], v_25984);
    env = stack[-16];
    v_25984 = ncons(v_25984);
    env = stack[-16];
    stack[-5] = v_25984;
    stack[-6] = v_25984;
v_25683:
    v_25984 = stack[-7];
    v_25984 = qcdr(v_25984);
    stack[-7] = v_25984;
    v_25984 = stack[-7];
    if (v_25984 == nil) goto v_25751;
    else goto v_25752;
v_25751:
    v_25984 = stack[-6];
    goto v_25682;
v_25752:
    goto v_25760;
v_25756:
    stack[-4] = stack[-5];
    goto v_25757;
v_25758:
    v_25984 = stack[-7];
    v_25984 = qcar(v_25984);
    stack[-3] = v_25984;
    goto v_25773;
v_25767:
    stack[-2] = stack[-15];
    goto v_25768;
v_25769:
    v_25984 = stack[-3];
    stack[-1] = qcar(v_25984);
    goto v_25770;
v_25771:
    goto v_25782;
v_25778:
    goto v_25788;
v_25784:
    v_25984 = stack[-13];
    stack[0] = qcar(v_25984);
    goto v_25785;
v_25786:
    goto v_25796;
v_25792:
    v_25984 = stack[-12];
    v_25985 = qcar(v_25984);
    goto v_25793;
v_25794:
    v_25984 = stack[-15];
    goto v_25795;
v_25796:
    goto v_25792;
v_25793:
    goto v_25794;
v_25795:
    fn = elt(env, 2); // tayexp!-difference
    v_25984 = (*qfn2(fn))(fn, v_25985, v_25984);
    env = stack[-16];
    goto v_25787;
v_25788:
    goto v_25784;
v_25785:
    goto v_25786;
v_25787:
    fn = elt(env, 5); // tayexp!-plus2
    v_25985 = (*qfn2(fn))(fn, stack[0], v_25984);
    env = stack[-16];
    goto v_25779;
v_25780:
    v_25984 = stack[-3];
    v_25984 = qcdr(v_25984);
    goto v_25781;
v_25782:
    goto v_25778;
v_25779:
    goto v_25780;
v_25781:
    v_25984 = cons(v_25985, v_25984);
    env = stack[-16];
    goto v_25772;
v_25773:
    goto v_25767;
v_25768:
    goto v_25769;
v_25770:
    goto v_25771;
v_25772:
    v_25984 = acons(stack[-2], stack[-1], v_25984);
    env = stack[-16];
    v_25984 = ncons(v_25984);
    env = stack[-16];
    goto v_25759;
v_25760:
    goto v_25756;
v_25757:
    goto v_25758;
v_25759:
    v_25984 = Lrplacd(nil, stack[-4], v_25984);
    env = stack[-16];
    v_25984 = stack[-5];
    v_25984 = qcdr(v_25984);
    stack[-5] = v_25984;
    goto v_25683;
v_25682:
    stack[-10] = v_25984;
    v_25984 = stack[-10];
    fn = elt(env, 6); // lastpair
    v_25984 = (*qfn1(fn))(fn, v_25984);
    env = stack[-16];
    stack[-9] = v_25984;
    goto v_25811;
v_25807:
    v_25985 = stack[-15];
    goto v_25808;
v_25809:
    v_25984 = stack[-11];
    goto v_25810;
v_25811:
    goto v_25807;
v_25808:
    goto v_25809;
v_25810:
    fn = elt(env, 5); // tayexp!-plus2
    v_25984 = (*qfn2(fn))(fn, v_25985, v_25984);
    env = stack[-16];
    stack[-15] = v_25984;
    v_25984 = stack[-9];
    if (!consp(v_25984)) goto v_25816;
    else goto v_25817;
v_25816:
    goto v_25652;
v_25817:
v_25653:
    goto v_25829;
v_25825:
    stack[0] = stack[-11];
    goto v_25826;
v_25827:
    goto v_25836;
v_25832:
    v_25984 = stack[-14];
    v_25985 = qcar(v_25984);
    goto v_25833;
v_25834:
    v_25984 = stack[-15];
    goto v_25835;
v_25836:
    goto v_25832;
v_25833:
    goto v_25834;
v_25835:
    fn = elt(env, 2); // tayexp!-difference
    v_25984 = (*qfn2(fn))(fn, v_25985, v_25984);
    env = stack[-16];
    goto v_25828;
v_25829:
    goto v_25825;
v_25826:
    goto v_25827;
v_25828:
    fn = elt(env, 3); // tayexp!-times2
    v_25984 = (*qfn2(fn))(fn, stack[0], v_25984);
    env = stack[-16];
    fn = elt(env, 4); // tayexp!-minusp
    v_25984 = (*qfn1(fn))(fn, v_25984);
    env = stack[-16];
    if (v_25984 == nil) goto v_25822;
    v_25984 = stack[-10];
    goto v_25651;
v_25822:
    goto v_25846;
v_25842:
    stack[-8] = stack[-9];
    goto v_25843;
v_25844:
    goto v_25863;
v_25855:
    v_25984 = stack[-14];
    v_25987 = qcdr(v_25984);
    goto v_25856;
v_25857:
    v_25984 = stack[-13];
    v_25986 = qcdr(v_25984);
    goto v_25858;
v_25859:
    v_25984 = stack[-12];
    v_25985 = qcdr(v_25984);
    goto v_25860;
v_25861:
    v_25984 = stack[-11];
    goto v_25862;
v_25863:
    goto v_25855;
v_25856:
    goto v_25857;
v_25858:
    goto v_25859;
v_25860:
    goto v_25861;
v_25862:
    v_25984 = CC_makecoeffpairshom(elt(env, 0), 4, v_25987, v_25986, v_25985, v_25984);
    env = stack[-16];
    stack[-7] = v_25984;
    v_25984 = stack[-7];
    if (v_25984 == nil) goto v_25873;
    else goto v_25874;
v_25873:
    v_25984 = nil;
    goto v_25852;
v_25874:
    v_25984 = stack[-7];
    v_25984 = qcar(v_25984);
    stack[-3] = v_25984;
    goto v_25888;
v_25882:
    stack[-2] = stack[-15];
    goto v_25883;
v_25884:
    v_25984 = stack[-3];
    stack[-1] = qcar(v_25984);
    goto v_25885;
v_25886:
    goto v_25897;
v_25893:
    goto v_25903;
v_25899:
    v_25984 = stack[-13];
    stack[0] = qcar(v_25984);
    goto v_25900;
v_25901:
    goto v_25911;
v_25907:
    v_25984 = stack[-12];
    v_25985 = qcar(v_25984);
    goto v_25908;
v_25909:
    v_25984 = stack[-15];
    goto v_25910;
v_25911:
    goto v_25907;
v_25908:
    goto v_25909;
v_25910:
    fn = elt(env, 2); // tayexp!-difference
    v_25984 = (*qfn2(fn))(fn, v_25985, v_25984);
    env = stack[-16];
    goto v_25902;
v_25903:
    goto v_25899;
v_25900:
    goto v_25901;
v_25902:
    fn = elt(env, 5); // tayexp!-plus2
    v_25985 = (*qfn2(fn))(fn, stack[0], v_25984);
    env = stack[-16];
    goto v_25894;
v_25895:
    v_25984 = stack[-3];
    v_25984 = qcdr(v_25984);
    goto v_25896;
v_25897:
    goto v_25893;
v_25894:
    goto v_25895;
v_25896:
    v_25984 = cons(v_25985, v_25984);
    env = stack[-16];
    goto v_25887;
v_25888:
    goto v_25882;
v_25883:
    goto v_25884;
v_25885:
    goto v_25886;
v_25887:
    v_25984 = acons(stack[-2], stack[-1], v_25984);
    env = stack[-16];
    v_25984 = ncons(v_25984);
    env = stack[-16];
    stack[-5] = v_25984;
    stack[-6] = v_25984;
v_25853:
    v_25984 = stack[-7];
    v_25984 = qcdr(v_25984);
    stack[-7] = v_25984;
    v_25984 = stack[-7];
    if (v_25984 == nil) goto v_25921;
    else goto v_25922;
v_25921:
    v_25984 = stack[-6];
    goto v_25852;
v_25922:
    goto v_25930;
v_25926:
    stack[-4] = stack[-5];
    goto v_25927;
v_25928:
    v_25984 = stack[-7];
    v_25984 = qcar(v_25984);
    stack[-3] = v_25984;
    goto v_25943;
v_25937:
    stack[-2] = stack[-15];
    goto v_25938;
v_25939:
    v_25984 = stack[-3];
    stack[-1] = qcar(v_25984);
    goto v_25940;
v_25941:
    goto v_25952;
v_25948:
    goto v_25958;
v_25954:
    v_25984 = stack[-13];
    stack[0] = qcar(v_25984);
    goto v_25955;
v_25956:
    goto v_25966;
v_25962:
    v_25984 = stack[-12];
    v_25985 = qcar(v_25984);
    goto v_25963;
v_25964:
    v_25984 = stack[-15];
    goto v_25965;
v_25966:
    goto v_25962;
v_25963:
    goto v_25964;
v_25965:
    fn = elt(env, 2); // tayexp!-difference
    v_25984 = (*qfn2(fn))(fn, v_25985, v_25984);
    env = stack[-16];
    goto v_25957;
v_25958:
    goto v_25954;
v_25955:
    goto v_25956;
v_25957:
    fn = elt(env, 5); // tayexp!-plus2
    v_25985 = (*qfn2(fn))(fn, stack[0], v_25984);
    env = stack[-16];
    goto v_25949;
v_25950:
    v_25984 = stack[-3];
    v_25984 = qcdr(v_25984);
    goto v_25951;
v_25952:
    goto v_25948;
v_25949:
    goto v_25950;
v_25951:
    v_25984 = cons(v_25985, v_25984);
    env = stack[-16];
    goto v_25942;
v_25943:
    goto v_25937;
v_25938:
    goto v_25939;
v_25940:
    goto v_25941;
v_25942:
    v_25984 = acons(stack[-2], stack[-1], v_25984);
    env = stack[-16];
    v_25984 = ncons(v_25984);
    env = stack[-16];
    goto v_25929;
v_25930:
    goto v_25926;
v_25927:
    goto v_25928;
v_25929:
    v_25984 = Lrplacd(nil, stack[-4], v_25984);
    env = stack[-16];
    v_25984 = stack[-5];
    v_25984 = qcdr(v_25984);
    stack[-5] = v_25984;
    goto v_25853;
v_25852:
    goto v_25845;
v_25846:
    goto v_25842;
v_25843:
    goto v_25844;
v_25845:
    v_25984 = Lrplacd(nil, stack[-8], v_25984);
    env = stack[-16];
    v_25984 = stack[-9];
    fn = elt(env, 6); // lastpair
    v_25984 = (*qfn1(fn))(fn, v_25984);
    env = stack[-16];
    stack[-9] = v_25984;
    goto v_25981;
v_25977:
    v_25985 = stack[-15];
    goto v_25978;
v_25979:
    v_25984 = stack[-11];
    goto v_25980;
v_25981:
    goto v_25977;
v_25978:
    goto v_25979;
v_25980:
    fn = elt(env, 5); // tayexp!-plus2
    v_25984 = (*qfn2(fn))(fn, v_25985, v_25984);
    env = stack[-16];
    stack[-15] = v_25984;
    goto v_25653;
v_25651:
    goto v_25640;
    v_25984 = nil;
v_25640:
    return onevalue(v_25984);
}



// Code for depend!-f

static LispObject CC_dependKf(LispObject env,
                         LispObject v_25634, LispObject v_25635)
{
    env = qenv(env);
    LispObject v_25691, v_25692;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25634,v_25635);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_25635;
    stack[-1] = v_25634;
// end of prologue
v_25633:
    v_25691 = stack[-1];
    if (!consp(v_25691)) goto v_25643;
    else goto v_25644;
v_25643:
    v_25691 = lisp_true;
    goto v_25642;
v_25644:
    v_25691 = stack[-1];
    v_25691 = qcar(v_25691);
    v_25691 = (consp(v_25691) ? nil : lisp_true);
    goto v_25642;
    v_25691 = nil;
v_25642:
    if (v_25691 == nil) goto v_25640;
    v_25691 = nil;
    goto v_25638;
v_25640:
    goto v_25663;
v_25659:
    v_25691 = stack[-1];
    v_25691 = qcar(v_25691);
    v_25691 = qcar(v_25691);
    v_25692 = qcar(v_25691);
    goto v_25660;
v_25661:
    v_25691 = stack[0];
    goto v_25662;
v_25663:
    goto v_25659;
v_25660:
    goto v_25661;
v_25662:
    fn = elt(env, 1); // depend!-p
    v_25691 = (*qfn2(fn))(fn, v_25692, v_25691);
    env = stack[-2];
    if (v_25691 == nil) goto v_25657;
    else goto v_25656;
v_25657:
    goto v_25677;
v_25673:
    v_25691 = stack[-1];
    v_25691 = qcar(v_25691);
    v_25692 = qcdr(v_25691);
    goto v_25674;
v_25675:
    v_25691 = stack[0];
    goto v_25676;
v_25677:
    goto v_25673;
v_25674:
    goto v_25675;
v_25676:
    v_25691 = CC_dependKf(elt(env, 0), v_25692, v_25691);
    env = stack[-2];
    if (v_25691 == nil) goto v_25671;
    else goto v_25670;
v_25671:
    goto v_25687;
v_25683:
    v_25691 = stack[-1];
    v_25692 = qcdr(v_25691);
    goto v_25684;
v_25685:
    v_25691 = stack[0];
    goto v_25686;
v_25687:
    goto v_25683;
v_25684:
    goto v_25685;
v_25686:
    stack[-1] = v_25692;
    stack[0] = v_25691;
    goto v_25633;
v_25670:
v_25656:
    goto v_25638;
    v_25691 = nil;
v_25638:
    return onevalue(v_25691);
}



// Code for quotexf!*

static LispObject CC_quotexfH(LispObject env,
                         LispObject v_25634, LispObject v_25635)
{
    env = qenv(env);
    LispObject v_25674, v_25675;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25634,v_25635);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_25635;
    stack[-2] = v_25634;
// end of prologue
    stack[-3] = nil;
v_25640:
    v_25674 = stack[-2];
    if (v_25674 == nil) goto v_25643;
    else goto v_25644;
v_25643:
    v_25674 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_25674);
    }
v_25644:
    goto v_25657;
v_25651:
    v_25674 = stack[-2];
    v_25674 = qcar(v_25674);
    stack[0] = qcar(v_25674);
    goto v_25652;
v_25653:
    goto v_25666;
v_25662:
    v_25674 = stack[-2];
    v_25674 = qcar(v_25674);
    v_25675 = qcdr(v_25674);
    goto v_25663;
v_25664:
    v_25674 = stack[-1];
    goto v_25665;
v_25666:
    goto v_25662;
v_25663:
    goto v_25664;
v_25665:
    fn = elt(env, 2); // quotfexf!*1
    v_25675 = (*qfn2(fn))(fn, v_25675, v_25674);
    env = stack[-4];
    goto v_25654;
v_25655:
    v_25674 = stack[-3];
    goto v_25656;
v_25657:
    goto v_25651;
v_25652:
    goto v_25653;
v_25654:
    goto v_25655;
v_25656:
    v_25674 = acons(stack[0], v_25675, v_25674);
    env = stack[-4];
    stack[-3] = v_25674;
    v_25674 = stack[-2];
    v_25674 = qcdr(v_25674);
    stack[-2] = v_25674;
    goto v_25640;
    v_25674 = nil;
    return onevalue(v_25674);
}



// Code for lowupperlimitml

static LispObject CC_lowupperlimitml(LispObject env,
                         LispObject v_25634)
{
    env = qenv(env);
    LispObject v_25663;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25634);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_25634;
// end of prologue
    v_25663 = elt(env, 1); // "<lowlimit>"
    fn = elt(env, 5); // printout
    v_25663 = (*qfn1(fn))(fn, v_25663);
    env = stack[-1];
    v_25663 = lisp_true;
    fn = elt(env, 6); // indent!*
    v_25663 = (*qfn1(fn))(fn, v_25663);
    env = stack[-1];
    v_25663 = stack[0];
    v_25663 = qcdr(v_25663);
    v_25663 = qcar(v_25663);
    fn = elt(env, 7); // expression
    v_25663 = (*qfn1(fn))(fn, v_25663);
    env = stack[-1];
    v_25663 = nil;
    fn = elt(env, 6); // indent!*
    v_25663 = (*qfn1(fn))(fn, v_25663);
    env = stack[-1];
    v_25663 = elt(env, 2); // "</lowlimit>"
    fn = elt(env, 5); // printout
    v_25663 = (*qfn1(fn))(fn, v_25663);
    env = stack[-1];
    v_25663 = elt(env, 3); // "<uplimit>"
    fn = elt(env, 5); // printout
    v_25663 = (*qfn1(fn))(fn, v_25663);
    env = stack[-1];
    v_25663 = lisp_true;
    fn = elt(env, 6); // indent!*
    v_25663 = (*qfn1(fn))(fn, v_25663);
    env = stack[-1];
    v_25663 = stack[0];
    v_25663 = qcdr(v_25663);
    v_25663 = qcdr(v_25663);
    v_25663 = qcar(v_25663);
    fn = elt(env, 7); // expression
    v_25663 = (*qfn1(fn))(fn, v_25663);
    env = stack[-1];
    v_25663 = nil;
    fn = elt(env, 6); // indent!*
    v_25663 = (*qfn1(fn))(fn, v_25663);
    env = stack[-1];
    v_25663 = elt(env, 4); // "</uplimit>"
    fn = elt(env, 5); // printout
    v_25663 = (*qfn1(fn))(fn, v_25663);
    v_25663 = nil;
    return onevalue(v_25663);
}



// Code for findhr

static LispObject CC_findhr(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25707, v_25708, v_25709;
    argcheck(nargs, 0, "findhr");
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
    stack[-1] = nil;
v_25640:
    goto v_25651;
v_25647:
    v_25708 = qvalue(elt(env, 1)); // headhisto
    goto v_25648;
v_25649:
    v_25707 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25650;
v_25651:
    goto v_25647;
v_25648:
    goto v_25649;
v_25650:
    v_25707 = (LispObject)greaterp2(v_25708, v_25707);
    v_25707 = v_25707 ? lisp_true : nil;
    env = stack[-2];
    if (v_25707 == nil) goto v_25643;
    goto v_25659;
v_25655:
    v_25708 = qvalue(elt(env, 2)); // codhisto
    goto v_25656;
v_25657:
    v_25707 = qvalue(elt(env, 1)); // headhisto
    goto v_25658;
v_25659:
    goto v_25655;
v_25656:
    goto v_25657;
v_25658:
    v_25707 = *(LispObject *)((char *)v_25708 + (CELL-TAG_VECTOR) + (((intptr_t)v_25707-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_25707;
    if (v_25707 == nil) goto v_25654;
    else goto v_25643;
v_25654:
    goto v_25644;
v_25643:
    goto v_25639;
v_25644:
    v_25707 = qvalue(elt(env, 1)); // headhisto
    v_25707 = sub1(v_25707);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_25707; // headhisto
    goto v_25640;
v_25639:
    v_25707 = stack[-1];
    if (v_25707 == nil) goto v_25669;
    v_25707 = stack[-1];
    v_25707 = ncons(v_25707);
    env = stack[-2];
    qvalue(elt(env, 3)) = v_25707; // psi
    v_25707 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 4)) = v_25707; // npsi
    goto v_25680;
v_25674:
    goto v_25685;
v_25681:
    stack[0] = qvalue(elt(env, 5)); // codmat
    goto v_25682;
v_25683:
    goto v_25692;
v_25688:
    v_25708 = qvalue(elt(env, 6)); // maxvar
    goto v_25689;
v_25690:
    v_25707 = stack[-1];
    goto v_25691;
v_25692:
    goto v_25688;
v_25689:
    goto v_25690;
v_25691:
    v_25707 = plus2(v_25708, v_25707);
    env = stack[-2];
    goto v_25684;
v_25685:
    goto v_25681;
v_25682:
    goto v_25683;
v_25684:
    v_25709 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_25707-TAG_FIXNUM)/(16/CELL)));
    goto v_25675;
v_25676:
    v_25708 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25677;
v_25678:
    v_25707 = nil;
    goto v_25679;
v_25680:
    goto v_25674;
v_25675:
    goto v_25676;
v_25677:
    goto v_25678;
v_25679:
    *(LispObject *)((char *)v_25709 + (CELL-TAG_VECTOR) + (((intptr_t)v_25708-TAG_FIXNUM)/(16/CELL))) = v_25707;
    goto v_25703;
v_25699:
    v_25708 = stack[-1];
    goto v_25700;
v_25701:
    v_25707 = qvalue(elt(env, 7)); // rcoccup
    goto v_25702;
v_25703:
    goto v_25699;
v_25700:
    goto v_25701;
v_25702:
    v_25707 = cons(v_25708, v_25707);
    env = stack[-2];
    qvalue(elt(env, 7)) = v_25707; // rcoccup
    goto v_25667;
v_25669:
v_25667:
    v_25707 = stack[-1];
    return onevalue(v_25707);
}



// Code for gfstorval

static LispObject CC_gfstorval(LispObject env,
                         LispObject v_25634, LispObject v_25635)
{
    env = qenv(env);
    LispObject v_25648, v_25649, v_25650;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25634,v_25635);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_25648 = v_25635;
    v_25649 = v_25634;
// end of prologue
    goto v_25644;
v_25638:
    v_25650 = v_25649;
    goto v_25639;
v_25640:
    v_25649 = v_25648;
    goto v_25641;
v_25642:
    v_25648 = qvalue(elt(env, 1)); // !*xnlist
    goto v_25643;
v_25644:
    goto v_25638;
v_25639:
    goto v_25640;
v_25641:
    goto v_25642;
v_25643:
    v_25648 = acons(v_25650, v_25649, v_25648);
    env = stack[0];
    qvalue(elt(env, 1)) = v_25648; // !*xnlist
    return onevalue(v_25648);
}



// Code for try!-all!-constants

static LispObject CC_tryKallKconstants(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25727, v_25728, v_25729;
    LispObject fn;
    LispObject v_25636, v_25635, v_25634;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "try-all-constants");
    va_start(aa, nargs);
    v_25634 = va_arg(aa, LispObject);
    v_25635 = va_arg(aa, LispObject);
    v_25636 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_25636,v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_25634,v_25635,v_25636);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_25636;
    stack[-3] = v_25635;
    v_25728 = v_25634;
// end of prologue
    v_25727 = nil;
    stack[-1] = v_25727;
    v_25727 = v_25728;
    stack[-4] = v_25727;
    v_25727 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_25727;
v_25644:
    goto v_25654;
v_25648:
    v_25729 = stack[-3];
    goto v_25649;
v_25650:
    v_25728 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25651;
v_25652:
    v_25727 = stack[0];
    goto v_25653;
v_25654:
    goto v_25648;
v_25649:
    goto v_25650;
v_25651:
    goto v_25652;
v_25653:
    *(LispObject *)((char *)v_25729 + (CELL-TAG_VECTOR) + (((intptr_t)v_25728-TAG_FIXNUM)/(16/CELL))) = v_25727;
    goto v_25665;
v_25659:
    v_25729 = stack[-4];
    goto v_25660;
v_25661:
    v_25728 = stack[-3];
    goto v_25662;
v_25663:
    v_25727 = stack[-2];
    goto v_25664;
v_25665:
    goto v_25659;
v_25660:
    goto v_25661;
v_25662:
    goto v_25663;
v_25664:
    fn = elt(env, 3); // split!-further
    v_25727 = (*qfnn(fn))(fn, 3, v_25729, v_25728, v_25727);
    env = stack[-5];
    v_25728 = v_25727;
    v_25727 = v_25728;
    v_25727 = qcdr(v_25727);
    stack[-4] = v_25727;
    v_25727 = v_25728;
    v_25727 = qcar(v_25727);
    v_25728 = v_25727;
    goto v_25678;
v_25674:
    goto v_25675;
v_25676:
    v_25727 = stack[-1];
    goto v_25677;
v_25678:
    goto v_25674;
v_25675:
    goto v_25676;
v_25677:
    v_25727 = Lnconc(nil, v_25728, v_25727);
    env = stack[-5];
    stack[-1] = v_25727;
    v_25727 = stack[-4];
    if (v_25727 == nil) goto v_25683;
    else goto v_25684;
v_25683:
    v_25727 = stack[-1];
    goto v_25643;
v_25684:
    goto v_25695;
v_25691:
    v_25728 = qvalue(elt(env, 1)); // number!-needed
    goto v_25692;
v_25693:
    v_25727 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25694;
v_25695:
    goto v_25691;
v_25692:
    goto v_25693;
v_25694:
    if (v_25728 == v_25727) goto v_25689;
    else goto v_25690;
v_25689:
    goto v_25703;
v_25699:
    v_25728 = stack[-4];
    goto v_25700;
v_25701:
    v_25727 = stack[-1];
    goto v_25702;
v_25703:
    goto v_25699;
v_25700:
    goto v_25701;
v_25702:
        return Lnconc(nil, v_25728, v_25727);
v_25690:
    v_25727 = stack[0];
    v_25727 = (LispObject)((intptr_t)(v_25727) + 0x10);
    stack[0] = v_25727;
    goto v_25716;
v_25712:
    v_25728 = stack[0];
    goto v_25713;
v_25714:
    v_25727 = qvalue(elt(env, 2)); // current!-modulus
    goto v_25715;
v_25716:
    goto v_25712;
v_25713:
    goto v_25714;
v_25715:
    if (((intptr_t)(v_25728)) < ((intptr_t)(v_25727))) goto v_25710;
    else goto v_25711;
v_25710:
    goto v_25644;
v_25711:
    goto v_25724;
v_25720:
    v_25728 = stack[-4];
    goto v_25721;
v_25722:
    v_25727 = stack[-1];
    goto v_25723;
v_25724:
    goto v_25720;
v_25721:
    goto v_25722;
v_25723:
        return Lnconc(nil, v_25728, v_25727);
v_25643:
    return onevalue(v_25727);
}



// Code for rule

static LispObject CC_rule(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25855, v_25856, v_25857, v_25858, v_25859;
    LispObject fn;
    LispObject v_25637, v_25636, v_25635, v_25634;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "rule");
    va_start(aa, nargs);
    v_25634 = va_arg(aa, LispObject);
    v_25635 = va_arg(aa, LispObject);
    v_25636 = va_arg(aa, LispObject);
    v_25637 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_25637,v_25636,v_25635,v_25634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_25634,v_25635,v_25636,v_25637);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_25637;
    stack[0] = v_25636;
    stack[-5] = v_25635;
    stack[-6] = v_25634;
// end of prologue
    stack[-7] = nil;
    goto v_25651;
v_25647:
    v_25856 = stack[0];
    goto v_25648;
v_25649:
    v_25855 = stack[-6];
    goto v_25650;
v_25651:
    goto v_25647;
v_25648:
    goto v_25649;
v_25650:
    v_25855 = Lsubla(nil, v_25856, v_25855);
    env = stack[-8];
    stack[-2] = v_25855;
    goto v_25662;
v_25658:
    v_25856 = stack[-2];
    goto v_25659;
v_25660:
    v_25855 = stack[-6];
    goto v_25661;
v_25662:
    goto v_25658;
v_25659:
    goto v_25660;
v_25661:
    if (equal(v_25856, v_25855)) goto v_25657;
    v_25855 = stack[-2];
    if (!consp(v_25855)) goto v_25667;
    else goto v_25668;
v_25667:
    v_25855 = stack[-6];
    {
        fn = elt(env, 7); // errpri1
        return (*qfn1(fn))(fn, v_25855);
    }
v_25668:
    v_25855 = lisp_true;
    stack[-7] = v_25855;
    v_25855 = stack[-2];
    stack[-6] = v_25855;
    goto v_25666;
v_25666:
    goto v_25655;
v_25657:
v_25655:
    goto v_25681;
v_25677:
    v_25856 = stack[0];
    goto v_25678;
v_25679:
    v_25855 = stack[-5];
    goto v_25680;
v_25681:
    goto v_25677;
v_25678:
    goto v_25679;
v_25680:
    v_25855 = Lsubla(nil, v_25856, v_25855);
    env = stack[-8];
    stack[-2] = v_25855;
    goto v_25692;
v_25688:
    v_25856 = stack[-2];
    goto v_25689;
v_25690:
    v_25855 = stack[-5];
    goto v_25691;
v_25692:
    goto v_25688;
v_25689:
    goto v_25690;
v_25691:
    if (equal(v_25856, v_25855)) goto v_25687;
    v_25855 = stack[-2];
    stack[-5] = v_25855;
    goto v_25705;
v_25701:
    v_25856 = stack[-5];
    goto v_25702;
v_25703:
    v_25855 = elt(env, 1); // !*sq!*
    goto v_25704;
v_25705:
    goto v_25701;
v_25702:
    goto v_25703;
v_25704:
    if (!consp(v_25856)) goto v_25699;
    v_25856 = qcar(v_25856);
    if (v_25856 == v_25855) goto v_25698;
    else goto v_25699;
v_25698:
    v_25855 = stack[-5];
    v_25855 = qcdr(v_25855);
    v_25855 = qcar(v_25855);
    fn = elt(env, 8); // prepsq!*
    v_25855 = (*qfn1(fn))(fn, v_25855);
    env = stack[-8];
    stack[-5] = v_25855;
    goto v_25697;
v_25699:
v_25697:
    goto v_25685;
v_25687:
v_25685:
    v_25855 = stack[0];
    stack[-3] = v_25855;
    v_25855 = stack[-3];
    if (v_25855 == nil) goto v_25721;
    else goto v_25722;
v_25721:
    v_25855 = nil;
    goto v_25716;
v_25722:
    v_25855 = stack[-3];
    v_25855 = qcar(v_25855);
    v_25855 = qcdr(v_25855);
    v_25855 = ncons(v_25855);
    env = stack[-8];
    stack[-1] = v_25855;
    stack[-2] = v_25855;
v_25717:
    v_25855 = stack[-3];
    v_25855 = qcdr(v_25855);
    stack[-3] = v_25855;
    v_25855 = stack[-3];
    if (v_25855 == nil) goto v_25735;
    else goto v_25736;
v_25735:
    v_25855 = stack[-2];
    goto v_25716;
v_25736:
    goto v_25744;
v_25740:
    stack[0] = stack[-1];
    goto v_25741;
v_25742:
    v_25855 = stack[-3];
    v_25855 = qcar(v_25855);
    v_25855 = qcdr(v_25855);
    v_25855 = ncons(v_25855);
    env = stack[-8];
    goto v_25743;
v_25744:
    goto v_25740;
v_25741:
    goto v_25742;
v_25743:
    v_25855 = Lrplacd(nil, stack[0], v_25855);
    env = stack[-8];
    v_25855 = stack[-1];
    v_25855 = qcdr(v_25855);
    stack[-1] = v_25855;
    goto v_25717;
v_25716:
    stack[0] = v_25855;
    goto v_25759;
v_25755:
    v_25856 = stack[0];
    goto v_25756;
v_25757:
    v_25855 = qvalue(elt(env, 2)); // mcond!*
    goto v_25758;
v_25759:
    goto v_25755;
v_25756:
    goto v_25757;
v_25758:
    fn = elt(env, 9); // smemql
    v_25855 = (*qfn2(fn))(fn, v_25856, v_25855);
    env = stack[-8];
    stack[-2] = v_25855;
    goto v_25767;
v_25763:
    v_25856 = stack[0];
    goto v_25764;
v_25765:
    v_25855 = stack[-6];
    goto v_25766;
v_25767:
    goto v_25763;
v_25764:
    goto v_25765;
v_25766:
    fn = elt(env, 9); // smemql
    v_25855 = (*qfn2(fn))(fn, v_25856, v_25855);
    env = stack[-8];
    stack[-1] = v_25855;
    goto v_25780;
v_25776:
    v_25856 = stack[-2];
    goto v_25777;
v_25778:
    v_25855 = stack[-1];
    goto v_25779;
v_25780:
    goto v_25776;
v_25777:
    goto v_25778;
v_25779:
    fn = elt(env, 10); // setdiff
    v_25856 = (*qfn2(fn))(fn, v_25856, v_25855);
    env = stack[-8];
    v_25855 = v_25856;
    if (v_25856 == nil) goto v_25774;
    else goto v_25772;
v_25774:
    goto v_25789;
v_25785:
    goto v_25795;
v_25791:
    goto v_25801;
v_25797:
    v_25856 = stack[0];
    goto v_25798;
v_25799:
    v_25855 = stack[-5];
    goto v_25800;
v_25801:
    goto v_25797;
v_25798:
    goto v_25799;
v_25800:
    fn = elt(env, 9); // smemql
    v_25856 = (*qfn2(fn))(fn, v_25856, v_25855);
    env = stack[-8];
    goto v_25792;
v_25793:
    v_25855 = stack[-2];
    goto v_25794;
v_25795:
    goto v_25791;
v_25792:
    goto v_25793;
v_25794:
    fn = elt(env, 10); // setdiff
    stack[0] = (*qfn2(fn))(fn, v_25856, v_25855);
    env = stack[-8];
    goto v_25786;
v_25787:
    goto v_25810;
v_25806:
    v_25856 = stack[-1];
    goto v_25807;
v_25808:
    v_25855 = stack[-2];
    goto v_25809;
v_25810:
    goto v_25806;
v_25807:
    goto v_25808;
v_25809:
    fn = elt(env, 10); // setdiff
    v_25855 = (*qfn2(fn))(fn, v_25856, v_25855);
    env = stack[-8];
    goto v_25788;
v_25789:
    goto v_25785;
v_25786:
    goto v_25787;
v_25788:
    fn = elt(env, 10); // setdiff
    v_25856 = (*qfn2(fn))(fn, stack[0], v_25855);
    env = stack[-8];
    v_25855 = v_25856;
    if (v_25856 == nil) goto v_25783;
    else goto v_25772;
v_25783:
    goto v_25773;
v_25772:
    goto v_25819;
v_25815:
    v_25856 = elt(env, 3); // "Unmatched free variable(s)"
    goto v_25816;
v_25817:
    goto v_25818;
v_25819:
    goto v_25815;
v_25816:
    goto v_25817;
v_25818:
    v_25855 = cons(v_25856, v_25855);
    env = stack[-8];
    fn = elt(env, 11); // lprie
    v_25855 = (*qfn1(fn))(fn, v_25855);
    env = stack[-8];
    v_25855 = elt(env, 4); // hold
    qvalue(elt(env, 5)) = v_25855; // erfg!*
    v_25855 = nil;
    goto v_25645;
v_25773:
    goto v_25831;
v_25827:
    v_25856 = stack[-6];
    goto v_25828;
v_25829:
    v_25855 = elt(env, 6); // getel
    goto v_25830;
v_25831:
    goto v_25827;
v_25828:
    goto v_25829;
v_25830:
    if (!consp(v_25856)) goto v_25825;
    v_25856 = qcar(v_25856);
    if (v_25856 == v_25855) goto v_25824;
    else goto v_25825;
v_25824:
    v_25855 = stack[-6];
    v_25855 = qcdr(v_25855);
    v_25855 = qcar(v_25855);
    fn = elt(env, 12); // lispeval
    v_25855 = (*qfn1(fn))(fn, v_25855);
    env = stack[-8];
    stack[-6] = v_25855;
    goto v_25771;
v_25825:
v_25771:
    goto v_25849;
v_25839:
    v_25859 = stack[-6];
    goto v_25840;
v_25841:
    v_25858 = stack[-5];
    goto v_25842;
v_25843:
    v_25857 = nil;
    goto v_25844;
v_25845:
    v_25856 = stack[-4];
    goto v_25846;
v_25847:
    v_25855 = stack[-7];
    goto v_25848;
v_25849:
    goto v_25839;
v_25840:
    goto v_25841;
v_25842:
    goto v_25843;
v_25844:
    goto v_25845;
v_25846:
    goto v_25847;
v_25848:
    {
        fn = elt(env, 13); // let3
        return (*qfnn(fn))(fn, 5, v_25859, v_25858, v_25857, v_25856, v_25855);
    }
v_25645:
    return onevalue(v_25855);
}



setup_type const u45_setup[] =
{
    {"diffp",                   TOO_FEW_2,      CC_diffp,      WRONG_NO_2},
    {"letmtr",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_letmtr},
    {"xpartitop",               CC_xpartitop,   TOO_MANY_1,    WRONG_NO_1},
    {"r2oaddspecies",           TOO_FEW_2,      CC_r2oaddspecies,WRONG_NO_2},
    {"ev-poles",                TOO_FEW_2,      CC_evKpoles,   WRONG_NO_2},
    {"dfp-rule-found",          TOO_FEW_2,      CC_dfpKruleKfound,WRONG_NO_2},
    {"mv-compact2",             TOO_FEW_2,      CC_mvKcompact2,WRONG_NO_2},
    {"prepcadr",                CC_prepcadr,    TOO_MANY_1,    WRONG_NO_1},
    {"listminimize",            TOO_FEW_2,      CC_listminimize,WRONG_NO_2},
    {"general-multiply-by-constant-mod-p",TOO_FEW_2,CC_generalKmultiplyKbyKconstantKmodKp,WRONG_NO_2},
    {"mchsarg",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mchsarg},
    {"mkcrn",                   TOO_FEW_2,      CC_mkcrn,      WRONG_NO_2},
    {"ofsf_simplequal",         TOO_FEW_2,      CC_ofsf_simplequal,WRONG_NO_2},
    {"gcdlist",                 CC_gcdlist,     TOO_MANY_1,    WRONG_NO_1},
    {"enter-sorted",            TOO_FEW_2,      CC_enterKsorted,WRONG_NO_2},
    {"iv_cutn",                 CC_iv_cutn,     TOO_MANY_1,    WRONG_NO_1},
    {"cols2rows2",              TOO_FEW_2,      CC_cols2rows2, WRONG_NO_2},
    {"ldf-dep-var",             CC_ldfKdepKvar, TOO_MANY_1,    WRONG_NO_1},
    {"ndepends",                TOO_FEW_2,      CC_ndepends,   WRONG_NO_2},
    {"make_spoly_pair",         TOO_FEW_2,      CC_make_spoly_pair,WRONG_NO_2},
    {"all_defined_map_",        TOO_FEW_2,      CC_all_defined_map_,WRONG_NO_2},
    {"rl_nnfnot",               CC_rl_nnfnot,   TOO_MANY_1,    WRONG_NO_1},
    {"nlist",                   TOO_FEW_2,      CC_nlist,      WRONG_NO_2},
    {"makecoeffpairshom",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_makecoeffpairshom},
    {"depend-f",                TOO_FEW_2,      CC_dependKf,   WRONG_NO_2},
    {"quotexf*",                TOO_FEW_2,      CC_quotexfH,   WRONG_NO_2},
    {"lowupperlimitml",         CC_lowupperlimitml,TOO_MANY_1, WRONG_NO_1},
    {"findhr",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_findhr},
    {"gfstorval",               TOO_FEW_2,      CC_gfstorval,  WRONG_NO_2},
    {"try-all-constants",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_tryKallKconstants},
    {"rule",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rule},
    {NULL, (one_args *)"u45", (two_args *)"23323 9429360 1977519", 0}
};

// end of generated code
