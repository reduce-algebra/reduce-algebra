
// $destdir/u25.c        Machine generated C code

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



// Code for physopsimp

static LispObject CC_physopsimp(LispObject env,
                         LispObject v_14193)
{
    env = qenv(env);
    LispObject v_14640, v_14641, v_14642;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14193);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_14193;
// end of prologue
    stack[-4] = nil;
    v_14640 = stack[-6];
    if (symbolp(v_14640)) goto v_14204;
    else goto v_14205;
v_14204:
    v_14640 = stack[-6];
    goto v_14201;
v_14205:
    v_14640 = stack[-6];
    v_14640 = qcar(v_14640);
    stack[-7] = v_14640;
    v_14640 = stack[-6];
    v_14640 = qcdr(v_14640);
    stack[-5] = v_14640;
    v_14640 = stack[-5];
    if (v_14640 == nil) goto v_14220;
    else goto v_14221;
v_14220:
    v_14640 = nil;
    goto v_14214;
v_14221:
    v_14640 = stack[-5];
    v_14640 = qcar(v_14640);
    stack[0] = v_14640;
    v_14640 = stack[0];
    if (symbolp(v_14640)) goto v_14232;
    else goto v_14231;
v_14232:
    v_14640 = stack[0];
    fn = elt(env, 5); // isanindex
    v_14640 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    if (v_14640 == nil) goto v_14235;
    else goto v_14234;
v_14235:
    v_14640 = stack[0];
    fn = elt(env, 6); // isavarindex
    v_14640 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    if (v_14640 == nil) goto v_14238;
    else goto v_14234;
v_14238:
    goto v_14231;
v_14234:
    v_14640 = stack[0];
    goto v_14229;
v_14231:
    v_14640 = stack[0];
    fn = elt(env, 7); // physopsm!*
    v_14640 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    goto v_14229;
    v_14640 = nil;
v_14229:
    v_14640 = ncons(v_14640);
    env = stack[-8];
    stack[-2] = v_14640;
    stack[-3] = v_14640;
v_14215:
    v_14640 = stack[-5];
    v_14640 = qcdr(v_14640);
    stack[-5] = v_14640;
    v_14640 = stack[-5];
    if (v_14640 == nil) goto v_14250;
    else goto v_14251;
v_14250:
    v_14640 = stack[-3];
    goto v_14214;
v_14251:
    goto v_14259;
v_14255:
    stack[-1] = stack[-2];
    goto v_14256;
v_14257:
    v_14640 = stack[-5];
    v_14640 = qcar(v_14640);
    stack[0] = v_14640;
    v_14640 = stack[0];
    if (symbolp(v_14640)) goto v_14269;
    else goto v_14268;
v_14269:
    v_14640 = stack[0];
    fn = elt(env, 5); // isanindex
    v_14640 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    if (v_14640 == nil) goto v_14272;
    else goto v_14271;
v_14272:
    v_14640 = stack[0];
    fn = elt(env, 6); // isavarindex
    v_14640 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    if (v_14640 == nil) goto v_14275;
    else goto v_14271;
v_14275:
    goto v_14268;
v_14271:
    v_14640 = stack[0];
    goto v_14266;
v_14268:
    v_14640 = stack[0];
    fn = elt(env, 7); // physopsm!*
    v_14640 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    goto v_14266;
    v_14640 = nil;
v_14266:
    v_14640 = ncons(v_14640);
    env = stack[-8];
    goto v_14258;
v_14259:
    goto v_14255;
v_14256:
    goto v_14257;
v_14258:
    v_14640 = Lrplacd(nil, stack[-1], v_14640);
    env = stack[-8];
    v_14640 = stack[-2];
    v_14640 = qcdr(v_14640);
    stack[-2] = v_14640;
    goto v_14215;
v_14214:
    stack[0] = v_14640;
    goto v_14290;
v_14286:
    stack[-5] = stack[-7];
    goto v_14287;
v_14288:
    v_14640 = stack[0];
    stack[-3] = v_14640;
    v_14640 = stack[-3];
    if (v_14640 == nil) goto v_14301;
    else goto v_14302;
v_14301:
    v_14640 = nil;
    goto v_14296;
v_14302:
    v_14640 = stack[-3];
    v_14640 = qcar(v_14640);
    v_14642 = v_14640;
    goto v_14318;
v_14314:
    v_14641 = v_14642;
    goto v_14315;
v_14316:
    v_14640 = elt(env, 1); // !*sq
    goto v_14317;
v_14318:
    goto v_14314;
v_14315:
    goto v_14316;
v_14317:
    if (!consp(v_14641)) goto v_14312;
    v_14641 = qcar(v_14641);
    if (v_14641 == v_14640) goto v_14311;
    else goto v_14312;
v_14311:
    v_14640 = v_14642;
    v_14640 = qcdr(v_14640);
    v_14640 = qcar(v_14640);
    fn = elt(env, 8); // prepsqxx
    v_14640 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    goto v_14310;
v_14312:
    v_14640 = v_14642;
    goto v_14310;
    v_14640 = nil;
v_14310:
    v_14640 = ncons(v_14640);
    env = stack[-8];
    stack[-1] = v_14640;
    stack[-2] = v_14640;
v_14297:
    v_14640 = stack[-3];
    v_14640 = qcdr(v_14640);
    stack[-3] = v_14640;
    v_14640 = stack[-3];
    if (v_14640 == nil) goto v_14332;
    else goto v_14333;
v_14332:
    v_14640 = stack[-2];
    goto v_14296;
v_14333:
    goto v_14341;
v_14337:
    stack[0] = stack[-1];
    goto v_14338;
v_14339:
    v_14640 = stack[-3];
    v_14640 = qcar(v_14640);
    v_14642 = v_14640;
    goto v_14356;
v_14352:
    v_14641 = v_14642;
    goto v_14353;
v_14354:
    v_14640 = elt(env, 1); // !*sq
    goto v_14355;
v_14356:
    goto v_14352;
v_14353:
    goto v_14354;
v_14355:
    if (!consp(v_14641)) goto v_14350;
    v_14641 = qcar(v_14641);
    if (v_14641 == v_14640) goto v_14349;
    else goto v_14350;
v_14349:
    v_14640 = v_14642;
    v_14640 = qcdr(v_14640);
    v_14640 = qcar(v_14640);
    fn = elt(env, 8); // prepsqxx
    v_14640 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    goto v_14348;
v_14350:
    v_14640 = v_14642;
    goto v_14348;
    v_14640 = nil;
v_14348:
    v_14640 = ncons(v_14640);
    env = stack[-8];
    goto v_14340;
v_14341:
    goto v_14337;
v_14338:
    goto v_14339;
v_14340:
    v_14640 = Lrplacd(nil, stack[0], v_14640);
    env = stack[-8];
    v_14640 = stack[-1];
    v_14640 = qcdr(v_14640);
    stack[-1] = v_14640;
    goto v_14297;
v_14296:
    goto v_14289;
v_14290:
    goto v_14286;
v_14287:
    goto v_14288;
v_14289:
    v_14640 = cons(stack[-5], v_14640);
    env = stack[-8];
    stack[-6] = v_14640;
    v_14640 = stack[-6];
    fn = elt(env, 9); // opmtch!*
    v_14640 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    stack[0] = v_14640;
    if (v_14640 == nil) goto v_14371;
    v_14640 = stack[0];
    goto v_14201;
v_14371:
    v_14640 = stack[-6];
    fn = elt(env, 10); // scalopp
    v_14640 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    if (v_14640 == nil) goto v_14378;
    v_14640 = stack[-7];
    fn = elt(env, 11); // tensopp
    v_14640 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    if (v_14640 == nil) goto v_14378;
    goto v_14390;
v_14386:
    v_14641 = stack[-7];
    goto v_14387;
v_14388:
    v_14640 = elt(env, 2); // tensdimen
    goto v_14389;
v_14390:
    goto v_14386;
v_14387:
    goto v_14388;
v_14389:
    v_14640 = get(v_14641, v_14640);
    env = stack[-8];
    stack[-5] = v_14640;
    v_14640 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_14640;
    goto v_14410;
v_14406:
    v_14641 = stack[-5];
    goto v_14407;
v_14408:
    v_14640 = stack[-3];
    goto v_14409;
v_14410:
    goto v_14406;
v_14407:
    goto v_14408;
v_14409:
    v_14640 = difference2(v_14641, v_14640);
    env = stack[-8];
    v_14640 = Lminusp(nil, v_14640);
    env = stack[-8];
    if (v_14640 == nil) goto v_14403;
    v_14640 = nil;
    goto v_14397;
v_14403:
    goto v_14420;
v_14416:
    v_14640 = stack[-6];
    v_14641 = qcdr(v_14640);
    goto v_14417;
v_14418:
    v_14640 = stack[-3];
    goto v_14419;
v_14420:
    goto v_14416;
v_14417:
    goto v_14418;
v_14419:
    fn = elt(env, 12); // nth
    v_14640 = (*qfn2(fn))(fn, v_14641, v_14640);
    env = stack[-8];
    v_14640 = ncons(v_14640);
    env = stack[-8];
    stack[-1] = v_14640;
    stack[-2] = v_14640;
v_14398:
    v_14640 = stack[-3];
    v_14640 = add1(v_14640);
    env = stack[-8];
    stack[-3] = v_14640;
    goto v_14436;
v_14432:
    v_14641 = stack[-5];
    goto v_14433;
v_14434:
    v_14640 = stack[-3];
    goto v_14435;
v_14436:
    goto v_14432;
v_14433:
    goto v_14434;
v_14435:
    v_14640 = difference2(v_14641, v_14640);
    env = stack[-8];
    v_14640 = Lminusp(nil, v_14640);
    env = stack[-8];
    if (v_14640 == nil) goto v_14429;
    v_14640 = stack[-2];
    goto v_14397;
v_14429:
    goto v_14445;
v_14441:
    stack[0] = stack[-1];
    goto v_14442;
v_14443:
    goto v_14453;
v_14449:
    v_14640 = stack[-6];
    v_14641 = qcdr(v_14640);
    goto v_14450;
v_14451:
    v_14640 = stack[-3];
    goto v_14452;
v_14453:
    goto v_14449;
v_14450:
    goto v_14451;
v_14452:
    fn = elt(env, 12); // nth
    v_14640 = (*qfn2(fn))(fn, v_14641, v_14640);
    env = stack[-8];
    v_14640 = ncons(v_14640);
    env = stack[-8];
    goto v_14444;
v_14445:
    goto v_14441;
v_14442:
    goto v_14443;
v_14444:
    v_14640 = Lrplacd(nil, stack[0], v_14640);
    env = stack[-8];
    v_14640 = stack[-1];
    v_14640 = qcdr(v_14640);
    stack[-1] = v_14640;
    goto v_14398;
v_14397:
    stack[0] = v_14640;
    goto v_14468;
v_14464:
    v_14640 = stack[-6];
    v_14640 = qcdr(v_14640);
    v_14641 = Llength(nil, v_14640);
    env = stack[-8];
    goto v_14465;
v_14466:
    v_14640 = stack[-5];
    goto v_14467;
v_14468:
    goto v_14464;
v_14465:
    goto v_14466;
v_14467:
    v_14640 = (LispObject)greaterp2(v_14641, v_14640);
    v_14640 = v_14640 ? lisp_true : nil;
    env = stack[-8];
    if (v_14640 == nil) goto v_14462;
    goto v_14478;
v_14474:
    v_14640 = stack[-6];
    stack[-1] = qcdr(v_14640);
    goto v_14475;
v_14476:
    v_14640 = stack[-5];
    v_14640 = add1(v_14640);
    env = stack[-8];
    goto v_14477;
v_14478:
    goto v_14474;
v_14475:
    goto v_14476;
v_14477:
    fn = elt(env, 13); // pnth
    v_14640 = (*qfn2(fn))(fn, stack[-1], v_14640);
    env = stack[-8];
    stack[-5] = v_14640;
    goto v_14460;
v_14462:
    v_14640 = nil;
    stack[-5] = v_14640;
    goto v_14460;
v_14460:
    v_14640 = stack[-7];
    if (!symbolp(v_14640)) v_14640 = nil;
    else { v_14640 = qfastgets(v_14640);
           if (v_14640 != nil) { v_14640 = elt(v_14640, 43); // symmetric
#ifdef RECORD_GET
             if (v_14640 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v_14640 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v_14640 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v_14640 == SPID_NOPROP) v_14640 = nil; else v_14640 = lisp_true; }}
#endif
    if (v_14640 == nil) goto v_14489;
    goto v_14497;
v_14493:
    stack[-1] = stack[-7];
    goto v_14494;
v_14495:
    v_14640 = stack[0];
    fn = elt(env, 14); // ordn
    v_14640 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    goto v_14496;
v_14497:
    goto v_14493;
v_14494:
    goto v_14495;
v_14496:
    v_14640 = cons(stack[-1], v_14640);
    env = stack[-8];
    stack[-6] = v_14640;
    goto v_14487;
v_14489:
    goto v_14508;
v_14504:
    v_14641 = stack[-7];
    goto v_14505;
v_14506:
    v_14640 = elt(env, 3); // antisymmetric
    goto v_14507;
v_14508:
    goto v_14504;
v_14505:
    goto v_14506;
v_14507:
    v_14640 = Lflagp(nil, v_14641, v_14640);
    env = stack[-8];
    if (v_14640 == nil) goto v_14502;
    v_14640 = stack[0];
    fn = elt(env, 15); // repeats
    v_14640 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    if (v_14640 == nil) goto v_14514;
    v_14640 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14201;
v_14514:
    goto v_14525;
v_14521:
    v_14640 = stack[0];
    fn = elt(env, 14); // ordn
    v_14641 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    stack[-1] = v_14641;
    goto v_14522;
v_14523:
    v_14640 = stack[0];
    goto v_14524;
v_14525:
    goto v_14521;
v_14522:
    goto v_14523;
v_14524:
    fn = elt(env, 16); // permp
    v_14640 = (*qfn2(fn))(fn, v_14641, v_14640);
    env = stack[-8];
    if (v_14640 == nil) goto v_14518;
    else goto v_14519;
v_14518:
    v_14640 = lisp_true;
    stack[-4] = v_14640;
    goto v_14512;
v_14519:
v_14512:
    v_14640 = stack[-1];
    stack[0] = v_14640;
    goto v_14536;
v_14532:
    v_14641 = stack[-7];
    goto v_14533;
v_14534:
    v_14640 = stack[0];
    goto v_14535;
v_14536:
    goto v_14532;
v_14533:
    goto v_14534;
v_14535:
    v_14640 = cons(v_14641, v_14640);
    env = stack[-8];
    stack[-6] = v_14640;
    goto v_14487;
v_14502:
    goto v_14546;
v_14542:
    v_14641 = stack[-7];
    goto v_14543;
v_14544:
    v_14640 = stack[0];
    goto v_14545;
v_14546:
    goto v_14542;
v_14543:
    goto v_14544;
v_14545:
    v_14640 = cons(v_14641, v_14640);
    env = stack[-8];
    stack[-6] = v_14640;
    goto v_14487;
v_14487:
    v_14640 = stack[-5];
    if (v_14640 == nil) goto v_14552;
    goto v_14559;
v_14555:
    v_14641 = stack[-6];
    goto v_14556;
v_14557:
    v_14640 = stack[-5];
    goto v_14558;
v_14559:
    goto v_14555;
v_14556:
    goto v_14557;
v_14558:
    v_14640 = Lappend(nil, v_14641, v_14640);
    env = stack[-8];
    stack[-6] = v_14640;
    goto v_14550;
v_14552:
v_14550:
    v_14640 = stack[-4];
    if (v_14640 == nil) goto v_14565;
    goto v_14572;
v_14568:
    v_14641 = elt(env, 4); // minus
    goto v_14569;
v_14570:
    v_14640 = stack[-6];
    goto v_14571;
v_14572:
    goto v_14568;
v_14569:
    goto v_14570;
v_14571:
    return list2(v_14641, v_14640);
v_14565:
    v_14640 = stack[-6];
    goto v_14563;
    v_14640 = nil;
v_14563:
    goto v_14201;
v_14378:
    v_14640 = stack[-6];
    fn = elt(env, 17); // vecopp
    v_14640 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    if (v_14640 == nil) goto v_14579;
    v_14640 = stack[-6];
    fn = elt(env, 18); // listp
    v_14640 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    if (v_14640 == nil) goto v_14585;
    v_14640 = stack[-6];
    v_14640 = qcdr(v_14640);
    v_14640 = qcar(v_14640);
    fn = elt(env, 19); // putanewindex!*
    v_14640 = (*qfn1(fn))(fn, v_14640);
    goto v_14583;
v_14585:
v_14583:
    v_14640 = stack[-6];
    goto v_14201;
v_14579:
    v_14640 = stack[-6];
    fn = elt(env, 11); // tensopp
    v_14640 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    if (v_14640 == nil) goto v_14594;
    v_14640 = stack[-6];
    fn = elt(env, 18); // listp
    v_14640 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    if (v_14640 == nil) goto v_14600;
    v_14640 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_14640;
v_14606:
    goto v_14618;
v_14614:
    v_14640 = stack[-6];
    v_14640 = qcdr(v_14640);
    v_14641 = Llength(nil, v_14640);
    env = stack[-8];
    goto v_14615;
v_14616:
    v_14640 = stack[0];
    goto v_14617;
v_14618:
    goto v_14614;
v_14615:
    goto v_14616;
v_14617:
    v_14640 = difference2(v_14641, v_14640);
    env = stack[-8];
    v_14640 = Lminusp(nil, v_14640);
    env = stack[-8];
    if (v_14640 == nil) goto v_14611;
    goto v_14605;
v_14611:
    goto v_14630;
v_14626:
    v_14640 = stack[-6];
    v_14641 = qcdr(v_14640);
    goto v_14627;
v_14628:
    v_14640 = stack[0];
    goto v_14629;
v_14630:
    goto v_14626;
v_14627:
    goto v_14628;
v_14629:
    fn = elt(env, 12); // nth
    v_14640 = (*qfn2(fn))(fn, v_14641, v_14640);
    env = stack[-8];
    fn = elt(env, 19); // putanewindex!*
    v_14640 = (*qfn1(fn))(fn, v_14640);
    env = stack[-8];
    v_14640 = stack[0];
    v_14640 = add1(v_14640);
    env = stack[-8];
    stack[0] = v_14640;
    goto v_14606;
v_14605:
    goto v_14598;
v_14600:
v_14598:
    v_14640 = stack[-6];
    goto v_14201;
v_14594:
    v_14640 = stack[-6];
    goto v_14201;
    v_14640 = nil;
v_14201:
    return onevalue(v_14640);
}



// Code for ev!-denom2

static LispObject CC_evKdenom2(LispObject env,
                         LispObject v_14193, LispObject v_14194)
{
    env = qenv(env);
    LispObject v_14205, v_14206;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14205 = v_14194;
    v_14206 = v_14193;
// end of prologue
    goto v_14201;
v_14197:
    v_14206 = qcar(v_14206);
    goto v_14198;
v_14199:
    goto v_14200;
v_14201:
    goto v_14197;
v_14198:
    goto v_14199;
v_14200:
    {
        fn = elt(env, 1); // ev!-edgeloop
        return (*qfn2(fn))(fn, v_14206, v_14205);
    }
}



// Code for impartf

static LispObject CC_impartf(LispObject env,
                         LispObject v_14193)
{
    env = qenv(env);
    LispObject v_14324, v_14325;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14193);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_14193;
// end of prologue
    goto v_14200;
v_14196:
    v_14325 = elt(env, 1); // i
    goto v_14197;
v_14198:
    v_14324 = qvalue(elt(env, 2)); // kord!*
    goto v_14199;
v_14200:
    goto v_14196;
v_14197:
    goto v_14198;
v_14199:
    v_14324 = cons(v_14325, v_14324);
    env = stack[-4];
// Binding kord!*
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 2, -3);
    qvalue(elt(env, 2)) = v_14324; // kord!*
    v_14324 = stack[0];
    fn = elt(env, 4); // reorder
    v_14324 = (*qfn1(fn))(fn, v_14324);
    env = stack[-4];
    stack[-2] = v_14324;
    v_14324 = stack[-2];
    if (!consp(v_14324)) goto v_14213;
    else goto v_14214;
v_14213:
    v_14324 = lisp_true;
    goto v_14212;
v_14214:
    v_14324 = stack[-2];
    v_14324 = qcar(v_14324);
    v_14324 = (consp(v_14324) ? nil : lisp_true);
    goto v_14212;
    v_14324 = nil;
v_14212:
    if (v_14324 == nil) goto v_14210;
    v_14324 = stack[-2];
    if (!consp(v_14324)) goto v_14224;
    else goto v_14225;
v_14224:
    v_14324 = nil;
    goto v_14223;
v_14225:
    goto v_14235;
v_14231:
    v_14324 = stack[-2];
    v_14325 = qcar(v_14324);
    goto v_14232;
v_14233:
    v_14324 = elt(env, 3); // cmpxfn
    goto v_14234;
v_14235:
    goto v_14231;
v_14232:
    goto v_14233;
v_14234:
    v_14324 = get(v_14325, v_14324);
    env = stack[-4];
    if (v_14324 == nil) goto v_14229;
    goto v_14247;
v_14241:
    v_14324 = stack[-2];
    stack[-1] = qcar(v_14324);
    goto v_14242;
v_14243:
    v_14324 = stack[-2];
    v_14324 = qcdr(v_14324);
    stack[0] = qcdr(v_14324);
    goto v_14244;
v_14245:
    goto v_14258;
v_14254:
    v_14324 = stack[-2];
    v_14324 = qcar(v_14324);
    if (!symbolp(v_14324)) v_14325 = nil;
    else { v_14325 = qfastgets(v_14324);
           if (v_14325 != nil) { v_14325 = elt(v_14325, 34); // i2d
#ifdef RECORD_GET
             if (v_14325 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_14325 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_14325 == SPID_NOPROP) v_14325 = nil; }}
#endif
    goto v_14255;
v_14256:
    v_14324 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14257;
v_14258:
    goto v_14254;
v_14255:
    goto v_14256;
v_14257:
    v_14324 = Lapply1(nil, v_14325, v_14324);
    env = stack[-4];
    v_14324 = qcdr(v_14324);
    v_14324 = qcar(v_14324);
    goto v_14246;
v_14247:
    goto v_14241;
v_14242:
    goto v_14243;
v_14244:
    goto v_14245;
v_14246:
    v_14324 = list2star(stack[-1], stack[0], v_14324);
    env = stack[-4];
    fn = elt(env, 5); // int!-equiv!-chk
    v_14324 = (*qfn1(fn))(fn, v_14324);
    goto v_14223;
v_14229:
    v_14324 = nil;
    goto v_14223;
    v_14324 = nil;
v_14223:
    goto v_14208;
v_14210:
    goto v_14274;
v_14270:
    v_14324 = stack[-2];
    v_14324 = qcar(v_14324);
    v_14324 = qcar(v_14324);
    v_14325 = qcar(v_14324);
    goto v_14271;
v_14272:
    v_14324 = elt(env, 1); // i
    goto v_14273;
v_14274:
    goto v_14270;
v_14271:
    goto v_14272;
v_14273:
    if (v_14325 == v_14324) goto v_14268;
    else goto v_14269;
v_14268:
    goto v_14285;
v_14281:
    v_14324 = stack[-2];
    v_14324 = qcar(v_14324);
    stack[0] = qcdr(v_14324);
    goto v_14282;
v_14283:
    v_14324 = stack[-2];
    v_14324 = qcdr(v_14324);
    v_14324 = CC_impartf(elt(env, 0), v_14324);
    env = stack[-4];
    goto v_14284;
v_14285:
    goto v_14281;
v_14282:
    goto v_14283;
v_14284:
    fn = elt(env, 6); // addf
    v_14324 = (*qfn2(fn))(fn, stack[0], v_14324);
    goto v_14208;
v_14269:
    goto v_14299;
v_14295:
    goto v_14305;
v_14301:
    goto v_14312;
v_14308:
    v_14324 = stack[-2];
    v_14324 = qcar(v_14324);
    v_14325 = qcar(v_14324);
    goto v_14309;
v_14310:
    v_14324 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14311;
v_14312:
    goto v_14308;
v_14309:
    goto v_14310;
v_14311:
    v_14324 = cons(v_14325, v_14324);
    env = stack[-4];
    stack[0] = ncons(v_14324);
    env = stack[-4];
    goto v_14302;
v_14303:
    v_14324 = stack[-2];
    v_14324 = qcar(v_14324);
    v_14324 = qcdr(v_14324);
    v_14324 = CC_impartf(elt(env, 0), v_14324);
    env = stack[-4];
    goto v_14304;
v_14305:
    goto v_14301;
v_14302:
    goto v_14303;
v_14304:
    fn = elt(env, 7); // multf
    stack[0] = (*qfn2(fn))(fn, stack[0], v_14324);
    env = stack[-4];
    goto v_14296;
v_14297:
    v_14324 = stack[-2];
    v_14324 = qcdr(v_14324);
    v_14324 = CC_impartf(elt(env, 0), v_14324);
    env = stack[-4];
    goto v_14298;
v_14299:
    goto v_14295;
v_14296:
    goto v_14297;
v_14298:
    fn = elt(env, 6); // addf
    v_14324 = (*qfn2(fn))(fn, stack[0], v_14324);
    goto v_14208;
    v_14324 = nil;
v_14208:
    ;}  // end of a binding scope
    return onevalue(v_14324);
}



// Code for endstat

static LispObject CC_endstat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_14202;
    LispObject fn;
    argcheck(nargs, 0, "endstat");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// end of prologue
    v_14202 = qvalue(elt(env, 1)); // cursym!*
    stack[0] = v_14202;
    v_14202 = elt(env, 2); // end
    fn = elt(env, 3); // comm1
    v_14202 = (*qfn1(fn))(fn, v_14202);
    v_14202 = stack[0];
    return ncons(v_14202);
    return onevalue(v_14202);
}



// Code for red_topredbe

static LispObject CC_red_topredbe(LispObject env,
                         LispObject v_14193, LispObject v_14194)
{
    env = qenv(env);
    LispObject v_14270, v_14271;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14194,v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14193,v_14194);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_14194;
    stack[-2] = v_14193;
// end of prologue
    v_14270 = stack[-1];
    fn = elt(env, 2); // bas_dpoly
    v_14270 = (*qfn1(fn))(fn, v_14270);
    env = stack[-4];
    if (v_14270 == nil) goto v_14202;
    else goto v_14203;
v_14202:
    v_14270 = lisp_true;
    goto v_14201;
v_14203:
    v_14270 = stack[-2];
    v_14270 = (v_14270 == nil ? lisp_true : nil);
    goto v_14201;
    v_14270 = nil;
v_14201:
    if (v_14270 == nil) goto v_14199;
    v_14270 = stack[-1];
    goto v_14197;
v_14199:
    goto v_14227;
v_14223:
    fn = elt(env, 3); // cali_trace
    v_14271 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_14224;
v_14225:
    v_14270 = (LispObject)1264+TAG_FIXNUM; // 79
    goto v_14226;
v_14227:
    goto v_14223;
v_14224:
    goto v_14225;
v_14226:
    v_14270 = (LispObject)greaterp2(v_14271, v_14270);
    v_14270 = v_14270 ? lisp_true : nil;
    env = stack[-4];
    if (v_14270 == nil) goto v_14221;
    v_14270 = elt(env, 1); // " reduce "
    v_14270 = Lprinc(nil, v_14270);
    env = stack[-4];
    v_14270 = stack[-1];
    fn = elt(env, 2); // bas_dpoly
    v_14270 = (*qfn1(fn))(fn, v_14270);
    env = stack[-4];
    fn = elt(env, 4); // dp_print
    v_14270 = (*qfn1(fn))(fn, v_14270);
    env = stack[-4];
    goto v_14219;
v_14221:
v_14219:
v_14238:
    v_14270 = stack[-1];
    fn = elt(env, 2); // bas_dpoly
    v_14270 = (*qfn1(fn))(fn, v_14270);
    env = stack[-4];
    v_14271 = v_14270;
    if (v_14270 == nil) goto v_14241;
    goto v_14254;
v_14248:
    stack[-3] = stack[-2];
    goto v_14249;
v_14250:
    v_14270 = v_14271;
    fn = elt(env, 5); // dp_lmon
    stack[0] = (*qfn1(fn))(fn, v_14270);
    env = stack[-4];
    goto v_14251;
v_14252:
    v_14270 = stack[-1];
    fn = elt(env, 6); // bas_dpecart
    v_14270 = (*qfn1(fn))(fn, v_14270);
    env = stack[-4];
    goto v_14253;
v_14254:
    goto v_14248;
v_14249:
    goto v_14250;
v_14251:
    goto v_14252;
v_14253:
    fn = elt(env, 7); // red_divtestbe
    v_14271 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_14270);
    env = stack[-4];
    v_14270 = v_14271;
    if (v_14271 == nil) goto v_14241;
    goto v_14242;
v_14241:
    goto v_14237;
v_14242:
    goto v_14266;
v_14262:
    v_14271 = stack[-1];
    goto v_14263;
v_14264:
    goto v_14265;
v_14266:
    goto v_14262;
v_14263:
    goto v_14264;
v_14265:
    fn = elt(env, 8); // red_subst
    v_14270 = (*qfn2(fn))(fn, v_14271, v_14270);
    env = stack[-4];
    stack[-1] = v_14270;
    goto v_14238;
v_14237:
    v_14270 = stack[-1];
    goto v_14197;
    v_14270 = nil;
v_14197:
    return onevalue(v_14270);
}



// Code for pa_coinc_split

static LispObject CC_pa_coinc_split(LispObject env,
                         LispObject v_14193, LispObject v_14194)
{
    env = qenv(env);
    LispObject v_14542, v_14543, v_14544;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14194,v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14193,v_14194);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-8] = v_14194;
    stack[-9] = v_14193;
// end of prologue
    stack[-6] = nil;
    v_14542 = stack[-9];
    v_14542 = qcdr(v_14542);
    fn = elt(env, 2); // upbve
    v_14542 = (*qfn1(fn))(fn, v_14542);
    env = stack[-11];
    stack[-4] = v_14542;
    v_14542 = stack[-4];
    v_14542 = sub1(v_14542);
    env = stack[-11];
    v_14542 = Lmkvect(nil, v_14542);
    env = stack[-11];
    stack[-10] = v_14542;
    v_14542 = stack[-4];
    v_14542 = sub1(v_14542);
    env = stack[-11];
    v_14542 = Lmkvect(nil, v_14542);
    env = stack[-11];
    stack[-7] = v_14542;
    v_14542 = stack[-4];
    v_14542 = sub1(v_14542);
    env = stack[-11];
    v_14542 = Lmkvect(nil, v_14542);
    env = stack[-11];
    stack[-5] = v_14542;
    v_14542 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_14542;
    v_14542 = stack[-9];
    v_14542 = qcar(v_14542);
    stack[-2] = v_14542;
v_14225:
    v_14542 = stack[-2];
    if (v_14542 == nil) goto v_14230;
    else goto v_14231;
v_14230:
    goto v_14224;
v_14231:
    v_14542 = stack[-2];
    v_14542 = qcar(v_14542);
    stack[-1] = v_14542;
    v_14542 = stack[-3];
    v_14542 = add1(v_14542);
    env = stack[-11];
    stack[-3] = v_14542;
    goto v_14245;
v_14239:
    stack[0] = stack[-10];
    goto v_14240;
v_14241:
    v_14542 = stack[-1];
    v_14543 = sub1(v_14542);
    env = stack[-11];
    goto v_14242;
v_14243:
    v_14542 = stack[-3];
    goto v_14244;
v_14245:
    goto v_14239;
v_14240:
    goto v_14241;
v_14242:
    goto v_14243;
v_14244:
    *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_14543-TAG_FIXNUM)/(16/CELL))) = v_14542;
    v_14542 = stack[-2];
    v_14542 = qcdr(v_14542);
    stack[-2] = v_14542;
    goto v_14225;
v_14224:
    v_14542 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_14542;
    v_14542 = stack[-8];
    v_14542 = qcar(v_14542);
    stack[-2] = v_14542;
v_14256:
    v_14542 = stack[-2];
    if (v_14542 == nil) goto v_14261;
    else goto v_14262;
v_14261:
    goto v_14255;
v_14262:
    v_14542 = stack[-2];
    v_14542 = qcar(v_14542);
    stack[-1] = v_14542;
    v_14542 = stack[-3];
    v_14542 = add1(v_14542);
    env = stack[-11];
    stack[-3] = v_14542;
    goto v_14276;
v_14270:
    stack[0] = stack[-7];
    goto v_14271;
v_14272:
    v_14542 = stack[-1];
    v_14543 = sub1(v_14542);
    env = stack[-11];
    goto v_14273;
v_14274:
    v_14542 = stack[-3];
    goto v_14275;
v_14276:
    goto v_14270;
v_14271:
    goto v_14272;
v_14273:
    goto v_14274;
v_14275:
    *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_14543-TAG_FIXNUM)/(16/CELL))) = v_14542;
    v_14542 = stack[-2];
    v_14542 = qcdr(v_14542);
    stack[-2] = v_14542;
    goto v_14256;
v_14255:
    v_14542 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_14542;
v_14286:
    goto v_14298;
v_14294:
    v_14543 = stack[-4];
    goto v_14295;
v_14296:
    v_14542 = stack[-3];
    goto v_14297;
v_14298:
    goto v_14294;
v_14295:
    goto v_14296;
v_14297:
    v_14542 = difference2(v_14543, v_14542);
    env = stack[-11];
    v_14542 = Lminusp(nil, v_14542);
    env = stack[-11];
    if (v_14542 == nil) goto v_14291;
    goto v_14285;
v_14291:
    goto v_14307;
v_14303:
    goto v_14312;
v_14308:
    stack[-1] = stack[-10];
    goto v_14309;
v_14310:
    goto v_14319;
v_14315:
    v_14542 = stack[-9];
    stack[0] = qcdr(v_14542);
    goto v_14316;
v_14317:
    v_14542 = stack[-3];
    v_14542 = sub1(v_14542);
    env = stack[-11];
    goto v_14318;
v_14319:
    goto v_14315;
v_14316:
    goto v_14317;
v_14318:
    v_14542 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_14542-TAG_FIXNUM)/(16/CELL)));
    v_14542 = sub1(v_14542);
    env = stack[-11];
    goto v_14311;
v_14312:
    goto v_14308;
v_14309:
    goto v_14310;
v_14311:
    stack[-2] = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_14542-TAG_FIXNUM)/(16/CELL)));
    goto v_14304;
v_14305:
    goto v_14330;
v_14326:
    stack[-1] = stack[-7];
    goto v_14327;
v_14328:
    goto v_14337;
v_14333:
    v_14542 = stack[-8];
    stack[0] = qcdr(v_14542);
    goto v_14334;
v_14335:
    v_14542 = stack[-3];
    v_14542 = sub1(v_14542);
    env = stack[-11];
    goto v_14336;
v_14337:
    goto v_14333;
v_14334:
    goto v_14335;
v_14336:
    v_14542 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_14542-TAG_FIXNUM)/(16/CELL)));
    v_14542 = sub1(v_14542);
    env = stack[-11];
    goto v_14329;
v_14330:
    goto v_14326;
v_14327:
    goto v_14328;
v_14329:
    v_14542 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_14542-TAG_FIXNUM)/(16/CELL)));
    goto v_14306;
v_14307:
    goto v_14303;
v_14304:
    goto v_14305;
v_14306:
    v_14542 = cons(stack[-2], v_14542);
    env = stack[-11];
    v_14544 = v_14542;
    goto v_14352;
v_14348:
    v_14543 = v_14544;
    goto v_14349;
v_14350:
    v_14542 = stack[-6];
    goto v_14351;
v_14352:
    goto v_14348;
v_14349:
    goto v_14350;
v_14351:
    v_14542 = Lassoc(nil, v_14543, v_14542);
    stack[-1] = v_14542;
    if (v_14542 == nil) goto v_14347;
    goto v_14361;
v_14357:
    v_14542 = stack[-1];
    stack[0] = qcdr(v_14542);
    goto v_14358;
v_14359:
    v_14542 = stack[-1];
    v_14542 = qcdr(v_14542);
    v_14542 = qcdr(v_14542);
    v_14542 = add1(v_14542);
    env = stack[-11];
    goto v_14360;
v_14361:
    goto v_14357;
v_14358:
    goto v_14359;
v_14360:
    v_14542 = Lrplacd(nil, stack[0], v_14542);
    env = stack[-11];
    goto v_14374;
v_14368:
    stack[0] = stack[-5];
    goto v_14369;
v_14370:
    v_14542 = stack[-3];
    v_14543 = sub1(v_14542);
    env = stack[-11];
    goto v_14371;
v_14372:
    v_14542 = stack[-1];
    v_14542 = qcdr(v_14542);
    v_14542 = qcar(v_14542);
    goto v_14373;
v_14374:
    goto v_14368;
v_14369:
    goto v_14370;
v_14371:
    goto v_14372;
v_14373:
    *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_14543-TAG_FIXNUM)/(16/CELL))) = v_14542;
    goto v_14345;
v_14347:
    goto v_14390;
v_14384:
    goto v_14385;
v_14386:
    v_14543 = stack[-3];
    goto v_14387;
v_14388:
    v_14542 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14389;
v_14390:
    goto v_14384;
v_14385:
    goto v_14386;
v_14387:
    goto v_14388;
v_14389:
    v_14542 = list2star(v_14544, v_14543, v_14542);
    env = stack[-11];
    stack[-1] = v_14542;
    goto v_14399;
v_14395:
    v_14543 = stack[-1];
    goto v_14396;
v_14397:
    v_14542 = stack[-6];
    goto v_14398;
v_14399:
    goto v_14395;
v_14396:
    goto v_14397;
v_14398:
    v_14542 = cons(v_14543, v_14542);
    env = stack[-11];
    stack[-6] = v_14542;
    goto v_14408;
v_14402:
    stack[0] = stack[-5];
    goto v_14403;
v_14404:
    v_14542 = stack[-3];
    v_14543 = sub1(v_14542);
    env = stack[-11];
    goto v_14405;
v_14406:
    v_14542 = stack[-3];
    goto v_14407;
v_14408:
    goto v_14402;
v_14403:
    goto v_14404;
v_14405:
    goto v_14406;
v_14407:
    *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_14543-TAG_FIXNUM)/(16/CELL))) = v_14542;
    goto v_14345;
v_14345:
    v_14542 = stack[-3];
    v_14542 = add1(v_14542);
    env = stack[-11];
    stack[-3] = v_14542;
    goto v_14286;
v_14285:
    goto v_14420;
v_14416:
    v_14543 = stack[-6];
    goto v_14417;
v_14418:
    v_14542 = elt(env, 1); // lambda_er1ez819f9yx2
    goto v_14419;
v_14420:
    goto v_14416;
v_14417:
    goto v_14418;
v_14419:
    fn = elt(env, 3); // sort
    v_14542 = (*qfn2(fn))(fn, v_14543, v_14542);
    env = stack[-11];
    stack[-6] = v_14542;
    goto v_14428;
v_14424:
    v_14542 = stack[-6];
    stack[-3] = v_14542;
    v_14542 = stack[-3];
    if (v_14542 == nil) goto v_14438;
    else goto v_14439;
v_14438:
    v_14542 = nil;
    v_14543 = v_14542;
    goto v_14433;
v_14439:
    v_14542 = stack[-3];
    v_14542 = qcar(v_14542);
    v_14542 = qcdr(v_14542);
    v_14542 = qcar(v_14542);
    v_14542 = ncons(v_14542);
    env = stack[-11];
    stack[-1] = v_14542;
    stack[-2] = v_14542;
v_14434:
    v_14542 = stack[-3];
    v_14542 = qcdr(v_14542);
    stack[-3] = v_14542;
    v_14542 = stack[-3];
    if (v_14542 == nil) goto v_14453;
    else goto v_14454;
v_14453:
    v_14542 = stack[-2];
    v_14543 = v_14542;
    goto v_14433;
v_14454:
    goto v_14462;
v_14458:
    stack[0] = stack[-1];
    goto v_14459;
v_14460:
    v_14542 = stack[-3];
    v_14542 = qcar(v_14542);
    v_14542 = qcdr(v_14542);
    v_14542 = qcar(v_14542);
    v_14542 = ncons(v_14542);
    env = stack[-11];
    goto v_14461;
v_14462:
    goto v_14458;
v_14459:
    goto v_14460;
v_14461:
    v_14542 = Lrplacd(nil, stack[0], v_14542);
    env = stack[-11];
    v_14542 = stack[-1];
    v_14542 = qcdr(v_14542);
    stack[-1] = v_14542;
    goto v_14434;
v_14433:
    goto v_14425;
v_14426:
    v_14542 = stack[-5];
    goto v_14427;
v_14428:
    goto v_14424;
v_14425:
    goto v_14426;
v_14427:
    v_14542 = cons(v_14543, v_14542);
    env = stack[-11];
    stack[-5] = v_14542;
    v_14542 = stack[-6];
    stack[-3] = v_14542;
    v_14542 = stack[-3];
    if (v_14542 == nil) goto v_14483;
    else goto v_14484;
v_14483:
    v_14542 = nil;
    goto v_14478;
v_14484:
    v_14542 = stack[-3];
    v_14542 = qcar(v_14542);
    goto v_14496;
v_14492:
    v_14543 = v_14542;
    v_14543 = qcar(v_14543);
    goto v_14493;
v_14494:
    v_14542 = qcdr(v_14542);
    v_14542 = qcdr(v_14542);
    goto v_14495;
v_14496:
    goto v_14492;
v_14493:
    goto v_14494;
v_14495:
    v_14542 = cons(v_14543, v_14542);
    env = stack[-11];
    v_14542 = ncons(v_14542);
    env = stack[-11];
    stack[-1] = v_14542;
    stack[-2] = v_14542;
v_14479:
    v_14542 = stack[-3];
    v_14542 = qcdr(v_14542);
    stack[-3] = v_14542;
    v_14542 = stack[-3];
    if (v_14542 == nil) goto v_14506;
    else goto v_14507;
v_14506:
    v_14542 = stack[-2];
    goto v_14478;
v_14507:
    goto v_14515;
v_14511:
    stack[0] = stack[-1];
    goto v_14512;
v_14513:
    v_14542 = stack[-3];
    v_14542 = qcar(v_14542);
    goto v_14526;
v_14522:
    v_14543 = v_14542;
    v_14543 = qcar(v_14543);
    goto v_14523;
v_14524:
    v_14542 = qcdr(v_14542);
    v_14542 = qcdr(v_14542);
    goto v_14525;
v_14526:
    goto v_14522;
v_14523:
    goto v_14524;
v_14525:
    v_14542 = cons(v_14543, v_14542);
    env = stack[-11];
    v_14542 = ncons(v_14542);
    env = stack[-11];
    goto v_14514;
v_14515:
    goto v_14511;
v_14512:
    goto v_14513;
v_14514:
    v_14542 = Lrplacd(nil, stack[0], v_14542);
    env = stack[-11];
    v_14542 = stack[-1];
    v_14542 = qcdr(v_14542);
    stack[-1] = v_14542;
    goto v_14479;
v_14478:
    goto v_14539;
v_14535:
    v_14543 = v_14542;
    goto v_14536;
v_14537:
    v_14542 = stack[-5];
    goto v_14538;
v_14539:
    goto v_14535;
v_14536:
    goto v_14537;
v_14538:
    return cons(v_14543, v_14542);
    return onevalue(v_14542);
}



// Code for lambda_er1ez819f9yx2

static LispObject CC_lambda_er1ez819f9yx2(LispObject env,
                         LispObject v_14193, LispObject v_14194)
{
    env = qenv(env);
    LispObject v_14242, v_14243;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14194,v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14193,v_14194);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_14194;
    stack[-1] = v_14193;
// end of prologue
    goto v_14205;
v_14201:
    v_14242 = stack[-1];
    v_14242 = qcar(v_14242);
    v_14243 = qcar(v_14242);
    goto v_14202;
v_14203:
    v_14242 = stack[0];
    v_14242 = qcar(v_14242);
    v_14242 = qcar(v_14242);
    goto v_14204;
v_14205:
    goto v_14201;
v_14202:
    goto v_14203;
v_14204:
    v_14242 = (LispObject)lessp2(v_14243, v_14242);
    v_14242 = v_14242 ? lisp_true : nil;
    env = stack[-2];
    if (v_14242 == nil) goto v_14199;
    v_14242 = lisp_true;
    goto v_14197;
v_14199:
    goto v_14220;
v_14216:
    v_14242 = stack[0];
    v_14242 = qcar(v_14242);
    v_14243 = qcar(v_14242);
    goto v_14217;
v_14218:
    v_14242 = stack[-1];
    v_14242 = qcar(v_14242);
    v_14242 = qcar(v_14242);
    goto v_14219;
v_14220:
    goto v_14216;
v_14217:
    goto v_14218;
v_14219:
    v_14242 = (LispObject)lessp2(v_14243, v_14242);
    v_14242 = v_14242 ? lisp_true : nil;
    if (v_14242 == nil) goto v_14214;
    v_14242 = nil;
    goto v_14197;
v_14214:
    goto v_14235;
v_14231:
    v_14242 = stack[-1];
    v_14242 = qcar(v_14242);
    v_14243 = qcdr(v_14242);
    goto v_14232;
v_14233:
    v_14242 = stack[0];
    v_14242 = qcar(v_14242);
    v_14242 = qcdr(v_14242);
    goto v_14234;
v_14235:
    goto v_14231;
v_14232:
    goto v_14233;
v_14234:
        return Lleq(nil, v_14243, v_14242);
    v_14242 = nil;
v_14197:
    return onevalue(v_14242);
}



// Code for safe!-modrecip

static LispObject CC_safeKmodrecip(LispObject env,
                         LispObject v_14193)
{
    env = qenv(env);
    LispObject v_14246, v_14247, v_14248;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14193);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_14247 = v_14193;
// end of prologue
// Binding !*msg
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-3, 1, -1);
    qvalue(elt(env, 1)) = nil; // !*msg
// Binding !*protfg
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-3, 2, 0);
    qvalue(elt(env, 2)) = nil; // !*protfg
    v_14246 = nil;
    qvalue(elt(env, 1)) = v_14246; // !*msg
    v_14246 = lisp_true;
    qvalue(elt(env, 2)) = v_14246; // !*protfg
    goto v_14211;
v_14207:
    v_14248 = v_14247;
    goto v_14208;
v_14209:
    v_14246 = elt(env, 3); // !:mod!:
    goto v_14210;
v_14211:
    goto v_14207;
v_14208:
    goto v_14209;
v_14210:
    if (!consp(v_14248)) goto v_14205;
    v_14248 = qcar(v_14248);
    if (v_14248 == v_14246) goto v_14204;
    else goto v_14205;
v_14204:
    v_14246 = v_14247;
    v_14246 = qcdr(v_14246);
    v_14247 = v_14246;
    goto v_14203;
v_14205:
v_14203:
    goto v_14223;
v_14217:
    goto v_14229;
v_14225:
    v_14246 = elt(env, 4); // general!-modular!-reciprocal
    goto v_14226;
v_14227:
    goto v_14228;
v_14229:
    goto v_14225;
v_14226:
    goto v_14227;
v_14228:
    v_14248 = list2(v_14246, v_14247);
    env = stack[-3];
    goto v_14218;
v_14219:
    v_14247 = nil;
    goto v_14220;
v_14221:
    v_14246 = nil;
    goto v_14222;
v_14223:
    goto v_14217;
v_14218:
    goto v_14219;
v_14220:
    goto v_14221;
v_14222:
    fn = elt(env, 6); // errorset
    v_14246 = (*qfnn(fn))(fn, 3, v_14248, v_14247, v_14246);
    env = stack[-3];
    stack[-2] = v_14246;
    v_14246 = nil;
    qvalue(elt(env, 5)) = v_14246; // erfg!*
    v_14246 = stack[-2];
    fn = elt(env, 7); // errorp
    v_14246 = (*qfn1(fn))(fn, v_14246);
    if (v_14246 == nil) goto v_14238;
    v_14246 = nil;
    goto v_14236;
v_14238:
    v_14246 = stack[-2];
    v_14246 = qcar(v_14246);
    goto v_14236;
    v_14246 = nil;
v_14236:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_14246);
}



// Code for cde_position

static LispObject CC_cde_position(LispObject env,
                         LispObject v_14193, LispObject v_14194)
{
    env = qenv(env);
    LispObject v_14219, v_14220, v_14221, v_14222;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14221 = v_14194;
    v_14222 = v_14193;
// end of prologue
    goto v_14204;
v_14200:
    v_14220 = v_14222;
    goto v_14201;
v_14202:
    v_14219 = v_14221;
    goto v_14203;
v_14204:
    goto v_14200;
v_14201:
    goto v_14202;
v_14203:
    v_14219 = Lmember(nil, v_14220, v_14219);
    if (v_14219 == nil) goto v_14199;
    goto v_14213;
v_14209:
    v_14219 = v_14222;
    goto v_14210;
v_14211:
    v_14220 = v_14221;
    goto v_14212;
v_14213:
    goto v_14209;
v_14210:
    goto v_14211;
v_14212:
    {
        fn = elt(env, 1); // cde_position2
        return (*qfn2(fn))(fn, v_14219, v_14220);
    }
v_14199:
    v_14219 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14197;
    v_14219 = nil;
v_14197:
    return onevalue(v_14219);
}



// Code for sfto_int2sf

static LispObject CC_sfto_int2sf(LispObject env,
                         LispObject v_14193)
{
    env = qenv(env);
    LispObject v_14207, v_14208, v_14209;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14208 = v_14193;
// end of prologue
    goto v_14203;
v_14199:
    v_14209 = v_14208;
    goto v_14200;
v_14201:
    v_14207 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14202;
v_14203:
    goto v_14199;
v_14200:
    goto v_14201;
v_14202:
    if (v_14209 == v_14207) goto v_14198;
    v_14207 = v_14208;
    goto v_14196;
v_14198:
    v_14207 = nil;
v_14196:
    return onevalue(v_14207);
}



// Code for gettype

static LispObject CC_gettype(LispObject env,
                         LispObject v_14193)
{
    env = qenv(env);
    LispObject v_14265, v_14266;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14193);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_14193;
// end of prologue
    v_14265 = stack[0];
    if (is_number(v_14265)) goto v_14197;
    else goto v_14198;
v_14197:
    v_14265 = elt(env, 1); // number
    goto v_14196;
v_14198:
    v_14265 = stack[0];
    if (!consp(v_14265)) goto v_14206;
    v_14265 = lisp_true;
    goto v_14204;
v_14206:
    v_14265 = stack[0];
    if (v_14265 == nil) goto v_14213;
    else goto v_14214;
v_14213:
    v_14265 = lisp_true;
    goto v_14212;
v_14214:
    v_14265 = stack[0];
    v_14265 = Lsymbolp(nil, v_14265);
    env = stack[-1];
    v_14265 = (v_14265 == nil ? lisp_true : nil);
    goto v_14212;
    v_14265 = nil;
v_14212:
    goto v_14204;
    v_14265 = nil;
v_14204:
    if (v_14265 == nil) goto v_14202;
    v_14265 = elt(env, 2); // form
    goto v_14196;
v_14202:
    v_14265 = stack[0];
    if (!symbolp(v_14265)) v_14265 = nil;
    else { v_14265 = qfastgets(v_14265);
           if (v_14265 != nil) { v_14265 = elt(v_14265, 22); // simpfn
#ifdef RECORD_GET
             if (v_14265 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v_14265 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v_14265 == SPID_NOPROP) v_14265 = nil; }}
#endif
    if (v_14265 == nil) goto v_14224;
    v_14265 = elt(env, 3); // operator
    goto v_14196;
v_14224:
    v_14265 = stack[0];
    if (!symbolp(v_14265)) v_14265 = nil;
    else { v_14265 = qfastgets(v_14265);
           if (v_14265 != nil) { v_14265 = elt(v_14265, 4); // avalue
#ifdef RECORD_GET
             if (v_14265 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_14265 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_14265 == SPID_NOPROP) v_14265 = nil; }}
#endif
    if (v_14265 == nil) goto v_14229;
    v_14265 = stack[0];
    if (!symbolp(v_14265)) v_14265 = nil;
    else { v_14265 = qfastgets(v_14265);
           if (v_14265 != nil) { v_14265 = elt(v_14265, 4); // avalue
#ifdef RECORD_GET
             if (v_14265 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_14265 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_14265 == SPID_NOPROP) v_14265 = nil; }}
#endif
    v_14265 = qcar(v_14265);
    goto v_14196;
v_14229:
    v_14265 = stack[0];
    fn = elt(env, 9); // getd
    v_14265 = (*qfn1(fn))(fn, v_14265);
    env = stack[-1];
    if (v_14265 == nil) goto v_14236;
    v_14265 = elt(env, 4); // procedure
    goto v_14196;
v_14236:
    v_14265 = stack[0];
    v_14265 = Lsymbol_globalp(nil, v_14265);
    env = stack[-1];
    if (v_14265 == nil) goto v_14241;
    v_14265 = elt(env, 5); // global
    goto v_14196;
v_14241:
    v_14265 = stack[0];
    v_14265 = Lsymbol_specialp(nil, v_14265);
    env = stack[-1];
    if (v_14265 == nil) goto v_14246;
    v_14265 = elt(env, 6); // fluid
    goto v_14196;
v_14246:
    goto v_14257;
v_14253:
    v_14266 = stack[0];
    goto v_14254;
v_14255:
    v_14265 = elt(env, 7); // parm
    goto v_14256;
v_14257:
    goto v_14253;
v_14254:
    goto v_14255;
v_14256:
    v_14265 = Lflagp(nil, v_14266, v_14265);
    env = stack[-1];
    if (v_14265 == nil) goto v_14251;
    v_14265 = elt(env, 8); // parameter
    goto v_14196;
v_14251:
    v_14265 = stack[0];
    if (!symbolp(v_14265)) v_14265 = nil;
    else { v_14265 = qfastgets(v_14265);
           if (v_14265 != nil) { v_14265 = elt(v_14265, 2); // rtype
#ifdef RECORD_GET
             if (v_14265 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_14265 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_14265 == SPID_NOPROP) v_14265 = nil; }}
#endif
    goto v_14196;
    v_14265 = nil;
v_14196:
    return onevalue(v_14265);
}



// Code for evaluatecoeffts

static LispObject CC_evaluatecoeffts(LispObject env,
                         LispObject v_14193, LispObject v_14194)
{
    env = qenv(env);
    LispObject v_14314, v_14315, v_14316;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14194,v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14193,v_14194);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_14194;
    stack[-1] = v_14193;
// end of prologue
    v_14314 = stack[-1];
    if (v_14314 == nil) goto v_14202;
    else goto v_14203;
v_14202:
    v_14314 = lisp_true;
    goto v_14201;
v_14203:
    v_14314 = stack[-1];
    if (!consp(v_14314)) goto v_14210;
    else goto v_14211;
v_14210:
    v_14314 = lisp_true;
    goto v_14209;
v_14211:
    v_14314 = stack[-1];
    v_14314 = qcar(v_14314);
    v_14314 = (consp(v_14314) ? nil : lisp_true);
    goto v_14209;
    v_14314 = nil;
v_14209:
    goto v_14201;
    v_14314 = nil;
v_14201:
    if (v_14314 == nil) goto v_14199;
    goto v_14227;
v_14223:
    v_14315 = stack[-1];
    goto v_14224;
v_14225:
    v_14314 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14226;
v_14227:
    goto v_14223;
v_14224:
    goto v_14225;
v_14226:
    if (v_14315 == v_14314) goto v_14221;
    else goto v_14222;
v_14221:
    v_14314 = nil;
    goto v_14220;
v_14222:
    v_14314 = stack[-1];
    goto v_14220;
    v_14314 = nil;
v_14220:
    goto v_14197;
v_14199:
    goto v_14247;
v_14243:
    v_14314 = stack[-1];
    v_14314 = qcar(v_14314);
    v_14314 = qcar(v_14314);
    v_14315 = qcar(v_14314);
    goto v_14244;
v_14245:
    v_14314 = qvalue(elt(env, 1)); // indexlist
    goto v_14246;
v_14247:
    goto v_14243;
v_14244:
    goto v_14245;
v_14246:
    v_14314 = Lmember(nil, v_14315, v_14314);
    if (v_14314 == nil) goto v_14242;
    goto v_14261;
v_14255:
    v_14314 = stack[-1];
    v_14314 = qcar(v_14314);
    v_14314 = qcar(v_14314);
    v_14316 = qcar(v_14314);
    goto v_14256;
v_14257:
    v_14315 = stack[0];
    goto v_14258;
v_14259:
    v_14314 = qvalue(elt(env, 1)); // indexlist
    goto v_14260;
v_14261:
    goto v_14255;
v_14256:
    goto v_14257;
v_14258:
    goto v_14259;
v_14260:
    fn = elt(env, 2); // valuecoefft
    v_14314 = (*qfnn(fn))(fn, 3, v_14316, v_14315, v_14314);
    env = stack[-3];
    goto v_14240;
v_14242:
    goto v_14276;
v_14272:
    v_14314 = stack[-1];
    v_14314 = qcar(v_14314);
    v_14315 = qcar(v_14314);
    goto v_14273;
v_14274:
    v_14314 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14275;
v_14276:
    goto v_14272;
v_14273:
    goto v_14274;
v_14275:
    v_14314 = cons(v_14315, v_14314);
    env = stack[-3];
    v_14314 = ncons(v_14314);
    env = stack[-3];
    goto v_14240;
v_14240:
    goto v_14286;
v_14282:
    stack[-2] = v_14314;
    goto v_14283;
v_14284:
    goto v_14293;
v_14289:
    v_14314 = stack[-1];
    v_14314 = qcar(v_14314);
    v_14315 = qcdr(v_14314);
    goto v_14290;
v_14291:
    v_14314 = stack[0];
    goto v_14292;
v_14293:
    goto v_14289;
v_14290:
    goto v_14291;
v_14292:
    v_14314 = CC_evaluatecoeffts(elt(env, 0), v_14315, v_14314);
    env = stack[-3];
    goto v_14285;
v_14286:
    goto v_14282;
v_14283:
    goto v_14284;
v_14285:
    fn = elt(env, 3); // !*multf
    v_14314 = (*qfn2(fn))(fn, stack[-2], v_14314);
    env = stack[-3];
    goto v_14303;
v_14299:
    stack[-2] = v_14314;
    goto v_14300;
v_14301:
    goto v_14310;
v_14306:
    v_14314 = stack[-1];
    v_14315 = qcdr(v_14314);
    goto v_14307;
v_14308:
    v_14314 = stack[0];
    goto v_14309;
v_14310:
    goto v_14306;
v_14307:
    goto v_14308;
v_14309:
    v_14314 = CC_evaluatecoeffts(elt(env, 0), v_14315, v_14314);
    env = stack[-3];
    goto v_14302;
v_14303:
    goto v_14299;
v_14300:
    goto v_14301;
v_14302:
    {
        LispObject v_14320 = stack[-2];
        fn = elt(env, 4); // addf
        return (*qfn2(fn))(fn, v_14320, v_14314);
    }
    goto v_14197;
    v_14314 = nil;
v_14197:
    return onevalue(v_14314);
}



// Code for expnd

static LispObject CC_expnd(LispObject env,
                         LispObject v_14193)
{
    env = qenv(env);
    LispObject v_14230, v_14231, v_14232;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14193);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_14193;
// end of prologue
    v_14230 = qvalue(elt(env, 1)); // !*really_off_exp
    if (v_14230 == nil) goto v_14198;
    v_14230 = stack[0];
    goto v_14196;
v_14198:
// Binding !*sub2
// FLUIDBIND: reloadenv=2 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 2, -1);
    qvalue(elt(env, 2)) = nil; // !*sub2
    v_14230 = stack[0];
    fn = elt(env, 3); // expnd1
    v_14230 = (*qfn1(fn))(fn, v_14230);
    env = stack[-2];
    stack[0] = v_14230;
    v_14230 = qvalue(elt(env, 2)); // !*sub2
    if (v_14230 == nil) goto v_14212;
    goto v_14220;
v_14216:
    v_14230 = stack[0];
    fn = elt(env, 4); // subs2f
    v_14230 = (*qfn1(fn))(fn, v_14230);
    v_14232 = v_14230;
    v_14231 = qcdr(v_14230);
    goto v_14217;
v_14218:
    v_14230 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14219;
v_14220:
    goto v_14216;
v_14217:
    goto v_14218;
v_14219:
    if (v_14231 == v_14230) goto v_14215;
    else goto v_14212;
v_14215:
    v_14230 = v_14232;
    v_14230 = qcar(v_14230);
    goto v_14210;
v_14212:
    v_14230 = stack[0];
    goto v_14210;
    v_14230 = nil;
v_14210:
    ;}  // end of a binding scope
    goto v_14196;
    v_14230 = nil;
v_14196:
    return onevalue(v_14230);
}



// Code for lto_alunion

static LispObject CC_lto_alunion(LispObject env,
                         LispObject v_14193)
{
    env = qenv(env);
    LispObject v_14203, v_14204;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14203 = v_14193;
// end of prologue
    goto v_14200;
v_14196:
    v_14204 = v_14203;
    goto v_14197;
v_14198:
    v_14203 = elt(env, 1); // union
    goto v_14199;
v_14200:
    goto v_14196;
v_14197:
    goto v_14198;
v_14199:
    {
        fn = elt(env, 2); // lto_almerge
        return (*qfn2(fn))(fn, v_14204, v_14203);
    }
}



// Code for mri_prepat

static LispObject CC_mri_prepat(LispObject env,
                         LispObject v_14193)
{
    env = qenv(env);
    LispObject v_14198;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14193);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_14198 = v_14193;
// end of prologue
    fn = elt(env, 1); // mri_2pasfat
    v_14198 = (*qfn1(fn))(fn, v_14198);
    env = stack[0];
    {
        fn = elt(env, 2); // pasf_prepat
        return (*qfn1(fn))(fn, v_14198);
    }
}



// Code for pasf_vf

static LispObject CC_pasf_vf(LispObject env,
                         LispObject v_14193)
{
    env = qenv(env);
    LispObject v_14316, v_14317, v_14318;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14193);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_14317 = v_14193;
// end of prologue
    goto v_14213;
v_14209:
    v_14318 = v_14317;
    goto v_14210;
v_14211:
    v_14316 = elt(env, 1); // true
    goto v_14212;
v_14213:
    goto v_14209;
v_14210:
    goto v_14211;
v_14212:
    if (v_14318 == v_14316) goto v_14207;
    else goto v_14208;
v_14207:
    v_14316 = lisp_true;
    goto v_14206;
v_14208:
    goto v_14223;
v_14219:
    v_14318 = v_14317;
    goto v_14220;
v_14221:
    v_14316 = elt(env, 2); // false
    goto v_14222;
v_14223:
    goto v_14219;
v_14220:
    goto v_14221;
v_14222:
    v_14316 = (v_14318 == v_14316 ? lisp_true : nil);
    goto v_14206;
    v_14316 = nil;
v_14206:
    if (v_14316 == nil) goto v_14203;
    else goto v_14204;
v_14203:
    v_14316 = v_14317;
    v_14316 = qcdr(v_14316);
    v_14316 = qcar(v_14316);
    if (!consp(v_14316)) goto v_14229;
    else goto v_14230;
v_14229:
    v_14316 = lisp_true;
    goto v_14228;
v_14230:
    v_14316 = v_14317;
    v_14316 = qcdr(v_14316);
    v_14316 = qcar(v_14316);
    v_14316 = qcar(v_14316);
    v_14316 = (consp(v_14316) ? nil : lisp_true);
    goto v_14228;
    v_14316 = nil;
v_14228:
    goto v_14202;
v_14204:
    v_14316 = nil;
    goto v_14202;
    v_14316 = nil;
v_14202:
    if (v_14316 == nil) goto v_14200;
    v_14316 = v_14317;
    v_14316 = Lconsp(nil, v_14316);
    env = stack[0];
    if (v_14316 == nil) goto v_14248;
    v_14316 = v_14317;
    v_14316 = qcar(v_14316);
    v_14316 = Lconsp(nil, v_14316);
    env = stack[0];
    if (v_14316 == nil) goto v_14248;
    goto v_14263;
v_14259:
    v_14316 = v_14317;
    v_14316 = qcar(v_14316);
    v_14318 = qcar(v_14316);
    goto v_14260;
v_14261:
    v_14316 = elt(env, 3); // (cong ncong)
    goto v_14262;
v_14263:
    goto v_14259;
v_14260:
    goto v_14261;
v_14262:
    v_14316 = Lmemq(nil, v_14318, v_14316);
    if (v_14316 == nil) goto v_14248;
    v_14316 = v_14317;
    v_14316 = qcar(v_14316);
    v_14316 = qcdr(v_14316);
    if (!consp(v_14316)) goto v_14272;
    else goto v_14273;
v_14272:
    v_14316 = lisp_true;
    goto v_14271;
v_14273:
    v_14316 = v_14317;
    v_14316 = qcar(v_14316);
    v_14316 = qcdr(v_14316);
    v_14316 = qcar(v_14316);
    v_14316 = (consp(v_14316) ? nil : lisp_true);
    goto v_14271;
    v_14316 = nil;
v_14271:
    if (v_14316 == nil) goto v_14269;
    else goto v_14248;
v_14269:
    v_14316 = v_14317;
    v_14316 = qcdr(v_14316);
    v_14316 = qcar(v_14316);
    if (v_14316 == nil) goto v_14287;
    else goto v_14288;
v_14287:
    v_14316 = elt(env, 2); // false
    goto v_14196;
v_14288:
    v_14316 = v_14317;
    goto v_14196;
    goto v_14246;
v_14248:
v_14246:
    goto v_14305;
v_14301:
    v_14316 = v_14317;
    v_14316 = qcar(v_14316);
    goto v_14302;
v_14303:
    v_14317 = qcdr(v_14317);
    v_14317 = qcar(v_14317);
    goto v_14304;
v_14305:
    goto v_14301;
v_14302:
    goto v_14303;
v_14304:
    fn = elt(env, 4); // pasf_evalatp
    v_14316 = (*qfn2(fn))(fn, v_14316, v_14317);
    env = stack[0];
    if (v_14316 == nil) goto v_14299;
    v_14316 = elt(env, 1); // true
    goto v_14297;
v_14299:
    v_14316 = elt(env, 2); // false
    goto v_14297;
    v_14316 = nil;
v_14297:
    goto v_14196;
v_14200:
    v_14316 = v_14317;
v_14196:
    return onevalue(v_14316);
}



// Code for dip_fmon

static LispObject CC_dip_fmon(LispObject env,
                         LispObject v_14193, LispObject v_14194)
{
    env = qenv(env);
    LispObject v_14207, v_14208, v_14209;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14208 = v_14194;
    v_14207 = v_14193;
// end of prologue
    goto v_14203;
v_14197:
    v_14209 = v_14208;
    goto v_14198;
v_14199:
    v_14208 = v_14207;
    goto v_14200;
v_14201:
    v_14207 = nil;
    goto v_14202;
v_14203:
    goto v_14197;
v_14198:
    goto v_14199;
v_14200:
    goto v_14201;
v_14202:
    return list2star(v_14209, v_14208, v_14207);
}



// Code for mml2ir

static LispObject CC_mml2ir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_14253, v_14254;
    LispObject fn;
    argcheck(nargs, 0, "mml2ir");
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
    v_14253 = nil;
    stack[0] = v_14253;
    v_14253 = nil;
    qvalue(elt(env, 1)) = v_14253; // mmlatts
    v_14253 = (LispObject)512+TAG_FIXNUM; // 32
    v_14253 = ncons(v_14253);
    env = stack[-1];
    fn = elt(env, 11); // list2string
    v_14253 = (*qfn1(fn))(fn, v_14253);
    env = stack[-1];
    v_14253 = Lintern(nil, v_14253);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_14253; // space
    v_14253 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 3)) = v_14253; // count
    v_14253 = Lreadch(nil, 0);
    env = stack[-1];
    qvalue(elt(env, 4)) = v_14253; // ch
    v_14253 = nil;
    qvalue(elt(env, 5)) = v_14253; // temp2
    fn = elt(env, 12); // lex
    v_14253 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_14215;
v_14211:
    v_14254 = qvalue(elt(env, 6)); // char
    goto v_14212;
v_14213:
    v_14253 = elt(env, 7); // (m a t h)
    goto v_14214;
v_14215:
    goto v_14211;
v_14212:
    goto v_14213;
v_14214:
    if (equal(v_14254, v_14253)) goto v_14209;
    else goto v_14210;
v_14209:
    fn = elt(env, 13); // mathml
    v_14253 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_14253;
    goto v_14208;
v_14210:
    goto v_14226;
v_14222:
    v_14254 = elt(env, 8); // "<math>"
    goto v_14223;
v_14224:
    v_14253 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_14225;
v_14226:
    goto v_14222;
v_14223:
    goto v_14224;
v_14225:
    fn = elt(env, 14); // errorml
    v_14253 = (*qfn2(fn))(fn, v_14254, v_14253);
    env = stack[-1];
    goto v_14208;
v_14208:
    fn = elt(env, 12); // lex
    v_14253 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_14238;
v_14234:
    v_14254 = qvalue(elt(env, 6)); // char
    goto v_14235;
v_14236:
    v_14253 = elt(env, 9); // (!/ m a t h)
    goto v_14237;
v_14238:
    goto v_14234;
v_14235:
    goto v_14236;
v_14237:
    if (equal(v_14254, v_14253)) goto v_14232;
    else goto v_14233;
v_14232:
    v_14253 = Lterpri(nil, 0);
    goto v_14231;
v_14233:
    goto v_14249;
v_14245:
    v_14254 = elt(env, 10); // "</math>"
    goto v_14246;
v_14247:
    v_14253 = (LispObject)304+TAG_FIXNUM; // 19
    goto v_14248;
v_14249:
    goto v_14245;
v_14246:
    goto v_14247;
v_14248:
    fn = elt(env, 14); // errorml
    v_14253 = (*qfn2(fn))(fn, v_14254, v_14253);
    goto v_14231;
v_14231:
    v_14253 = stack[0];
    return onevalue(v_14253);
}



// Code for mkmatrix

static LispObject CC_mkmatrix(LispObject env,
                         LispObject v_14193, LispObject v_14194)
{
    env = qenv(env);
    LispObject v_14351, v_14352;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14194,v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14193,v_14194);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-8] = v_14194;
    stack[-9] = v_14193;
// end of prologue
    goto v_14201;
v_14197:
    stack[-10] = elt(env, 1); // mat
    goto v_14198;
v_14199:
    v_14351 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-7] = v_14351;
    goto v_14220;
v_14216:
    v_14352 = stack[-9];
    goto v_14217;
v_14218:
    v_14351 = stack[-7];
    goto v_14219;
v_14220:
    goto v_14216;
v_14217:
    goto v_14218;
v_14219:
    v_14351 = difference2(v_14352, v_14351);
    env = stack[-11];
    v_14351 = Lminusp(nil, v_14351);
    env = stack[-11];
    if (v_14351 == nil) goto v_14213;
    v_14351 = nil;
    goto v_14207;
v_14213:
    v_14351 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_14351;
    goto v_14242;
v_14238:
    v_14352 = stack[-8];
    goto v_14239;
v_14240:
    v_14351 = stack[-3];
    goto v_14241;
v_14242:
    goto v_14238;
v_14239:
    goto v_14240;
v_14241:
    v_14351 = difference2(v_14352, v_14351);
    env = stack[-11];
    v_14351 = Lminusp(nil, v_14351);
    env = stack[-11];
    if (v_14351 == nil) goto v_14235;
    v_14351 = nil;
    goto v_14229;
v_14235:
    v_14351 = (LispObject)0+TAG_FIXNUM; // 0
    v_14351 = ncons(v_14351);
    env = stack[-11];
    stack[-1] = v_14351;
    stack[-2] = v_14351;
v_14230:
    v_14351 = stack[-3];
    v_14351 = add1(v_14351);
    env = stack[-11];
    stack[-3] = v_14351;
    goto v_14260;
v_14256:
    v_14352 = stack[-8];
    goto v_14257;
v_14258:
    v_14351 = stack[-3];
    goto v_14259;
v_14260:
    goto v_14256;
v_14257:
    goto v_14258;
v_14259:
    v_14351 = difference2(v_14352, v_14351);
    env = stack[-11];
    v_14351 = Lminusp(nil, v_14351);
    env = stack[-11];
    if (v_14351 == nil) goto v_14253;
    v_14351 = stack[-2];
    goto v_14229;
v_14253:
    goto v_14269;
v_14265:
    stack[0] = stack[-1];
    goto v_14266;
v_14267:
    v_14351 = (LispObject)0+TAG_FIXNUM; // 0
    v_14351 = ncons(v_14351);
    env = stack[-11];
    goto v_14268;
v_14269:
    goto v_14265;
v_14266:
    goto v_14267;
v_14268:
    v_14351 = Lrplacd(nil, stack[0], v_14351);
    env = stack[-11];
    v_14351 = stack[-1];
    v_14351 = qcdr(v_14351);
    stack[-1] = v_14351;
    goto v_14230;
v_14229:
    v_14351 = ncons(v_14351);
    env = stack[-11];
    stack[-5] = v_14351;
    stack[-6] = v_14351;
v_14208:
    v_14351 = stack[-7];
    v_14351 = add1(v_14351);
    env = stack[-11];
    stack[-7] = v_14351;
    goto v_14287;
v_14283:
    v_14352 = stack[-9];
    goto v_14284;
v_14285:
    v_14351 = stack[-7];
    goto v_14286;
v_14287:
    goto v_14283;
v_14284:
    goto v_14285;
v_14286:
    v_14351 = difference2(v_14352, v_14351);
    env = stack[-11];
    v_14351 = Lminusp(nil, v_14351);
    env = stack[-11];
    if (v_14351 == nil) goto v_14280;
    v_14351 = stack[-6];
    goto v_14207;
v_14280:
    goto v_14296;
v_14292:
    stack[-4] = stack[-5];
    goto v_14293;
v_14294:
    v_14351 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_14351;
    goto v_14316;
v_14312:
    v_14352 = stack[-8];
    goto v_14313;
v_14314:
    v_14351 = stack[-3];
    goto v_14315;
v_14316:
    goto v_14312;
v_14313:
    goto v_14314;
v_14315:
    v_14351 = difference2(v_14352, v_14351);
    env = stack[-11];
    v_14351 = Lminusp(nil, v_14351);
    env = stack[-11];
    if (v_14351 == nil) goto v_14309;
    v_14351 = nil;
    goto v_14303;
v_14309:
    v_14351 = (LispObject)0+TAG_FIXNUM; // 0
    v_14351 = ncons(v_14351);
    env = stack[-11];
    stack[-1] = v_14351;
    stack[-2] = v_14351;
v_14304:
    v_14351 = stack[-3];
    v_14351 = add1(v_14351);
    env = stack[-11];
    stack[-3] = v_14351;
    goto v_14334;
v_14330:
    v_14352 = stack[-8];
    goto v_14331;
v_14332:
    v_14351 = stack[-3];
    goto v_14333;
v_14334:
    goto v_14330;
v_14331:
    goto v_14332;
v_14333:
    v_14351 = difference2(v_14352, v_14351);
    env = stack[-11];
    v_14351 = Lminusp(nil, v_14351);
    env = stack[-11];
    if (v_14351 == nil) goto v_14327;
    v_14351 = stack[-2];
    goto v_14303;
v_14327:
    goto v_14343;
v_14339:
    stack[0] = stack[-1];
    goto v_14340;
v_14341:
    v_14351 = (LispObject)0+TAG_FIXNUM; // 0
    v_14351 = ncons(v_14351);
    env = stack[-11];
    goto v_14342;
v_14343:
    goto v_14339;
v_14340:
    goto v_14341;
v_14342:
    v_14351 = Lrplacd(nil, stack[0], v_14351);
    env = stack[-11];
    v_14351 = stack[-1];
    v_14351 = qcdr(v_14351);
    stack[-1] = v_14351;
    goto v_14304;
v_14303:
    v_14351 = ncons(v_14351);
    env = stack[-11];
    goto v_14295;
v_14296:
    goto v_14292;
v_14293:
    goto v_14294;
v_14295:
    v_14351 = Lrplacd(nil, stack[-4], v_14351);
    env = stack[-11];
    v_14351 = stack[-5];
    v_14351 = qcdr(v_14351);
    stack[-5] = v_14351;
    goto v_14208;
v_14207:
    goto v_14200;
v_14201:
    goto v_14197;
v_14198:
    goto v_14199;
v_14200:
    {
        LispObject v_14364 = stack[-10];
        return cons(v_14364, v_14351);
    }
}



// Code for dipev2f

static LispObject CC_dipev2f(LispObject env,
                         LispObject v_14193, LispObject v_14194)
{
    env = qenv(env);
    LispObject v_14255, v_14256;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14194,v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14193,v_14194);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_14194;
    stack[-1] = v_14193;
// end of prologue
v_14198:
    v_14255 = stack[-1];
    if (v_14255 == nil) goto v_14201;
    else goto v_14202;
v_14201:
    v_14255 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14197;
v_14202:
    goto v_14211;
v_14207:
    v_14255 = stack[-1];
    v_14256 = qcar(v_14255);
    goto v_14208;
v_14209:
    v_14255 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14210;
v_14211:
    goto v_14207;
v_14208:
    goto v_14209;
v_14210:
    if (v_14256 == v_14255) goto v_14205;
    else goto v_14206;
v_14205:
    v_14255 = stack[-1];
    v_14255 = qcdr(v_14255);
    stack[-1] = v_14255;
    v_14255 = stack[0];
    v_14255 = qcdr(v_14255);
    stack[0] = v_14255;
    goto v_14198;
v_14206:
    goto v_14226;
v_14222:
    goto v_14233;
v_14229:
    goto v_14239;
v_14235:
    v_14255 = stack[0];
    v_14256 = qcar(v_14255);
    goto v_14236;
v_14237:
    v_14255 = stack[-1];
    v_14255 = qcar(v_14255);
    goto v_14238;
v_14239:
    goto v_14235;
v_14236:
    goto v_14237;
v_14238:
    fn = elt(env, 1); // to
    v_14256 = (*qfn2(fn))(fn, v_14256, v_14255);
    env = stack[-3];
    goto v_14230;
v_14231:
    v_14255 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14232;
v_14233:
    goto v_14229;
v_14230:
    goto v_14231;
v_14232:
    v_14255 = cons(v_14256, v_14255);
    env = stack[-3];
    stack[-2] = ncons(v_14255);
    env = stack[-3];
    goto v_14223;
v_14224:
    goto v_14250;
v_14246:
    v_14255 = stack[-1];
    v_14256 = qcdr(v_14255);
    goto v_14247;
v_14248:
    v_14255 = stack[0];
    v_14255 = qcdr(v_14255);
    goto v_14249;
v_14250:
    goto v_14246;
v_14247:
    goto v_14248;
v_14249:
    v_14255 = CC_dipev2f(elt(env, 0), v_14256, v_14255);
    env = stack[-3];
    goto v_14225;
v_14226:
    goto v_14222;
v_14223:
    goto v_14224;
v_14225:
    {
        LispObject v_14260 = stack[-2];
        fn = elt(env, 2); // multf
        return (*qfn2(fn))(fn, v_14260, v_14255);
    }
    v_14255 = nil;
v_14197:
    return onevalue(v_14255);
}



// Code for bcneg

static LispObject CC_bcneg(LispObject env,
                         LispObject v_14193)
{
    env = qenv(env);
    LispObject v_14227, v_14228;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14193);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_14193;
// end of prologue
    v_14227 = qvalue(elt(env, 1)); // !*grmod!*
    if (v_14227 == nil) goto v_14198;
    goto v_14209;
v_14205:
    v_14228 = stack[0];
    goto v_14206;
v_14207:
    v_14227 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14208;
v_14209:
    goto v_14205;
v_14206:
    goto v_14207;
v_14208:
    v_14227 = Leqn(nil, v_14228, v_14227);
    env = stack[-1];
    if (v_14227 == nil) goto v_14203;
    v_14227 = stack[0];
    goto v_14201;
v_14203:
    goto v_14219;
v_14215:
    v_14228 = qvalue(elt(env, 2)); // current!-modulus
    goto v_14216;
v_14217:
    v_14227 = stack[0];
    goto v_14218;
v_14219:
    goto v_14215;
v_14216:
    goto v_14217;
v_14218:
    v_14227 = (LispObject)(intptr_t)((intptr_t)v_14228 - (intptr_t)v_14227 + TAG_FIXNUM);
    goto v_14201;
    v_14227 = nil;
v_14201:
    goto v_14196;
v_14198:
    v_14227 = stack[0];
    {
        fn = elt(env, 3); // negsq
        return (*qfn1(fn))(fn, v_14227);
    }
    v_14227 = nil;
v_14196:
    return onevalue(v_14227);
}



// Code for formc!*

static LispObject CC_formcH(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_14212, v_14213, v_14214, v_14215;
    LispObject fn;
    LispObject v_14195, v_14194, v_14193;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formc*");
    va_start(aa, nargs);
    v_14193 = va_arg(aa, LispObject);
    v_14194 = va_arg(aa, LispObject);
    v_14195 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_14195,v_14194,v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_14193,v_14194,v_14195);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_14213 = v_14195;
    v_14214 = v_14194;
    v_14215 = v_14193;
// end of prologue
// Binding !*!*a2sfn
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = nil; // !*!*a2sfn
    v_14212 = elt(env, 2); // revalx
    qvalue(elt(env, 1)) = v_14212; // !*!*a2sfn
    goto v_14208;
v_14202:
    v_14212 = v_14215;
    goto v_14203;
v_14204:
    goto v_14205;
v_14206:
    goto v_14207;
v_14208:
    goto v_14202;
v_14203:
    goto v_14204;
v_14205:
    goto v_14206;
v_14207:
    fn = elt(env, 3); // formc
    v_14212 = (*qfnn(fn))(fn, 3, v_14212, v_14214, v_14213);
    ;}  // end of a binding scope
    return onevalue(v_14212);
}



// Code for r2findindex

static LispObject CC_r2findindex(LispObject env,
                         LispObject v_14193, LispObject v_14194)
{
    env = qenv(env);
    LispObject v_14207, v_14208, v_14209;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14207 = v_14194;
    v_14208 = v_14193;
// end of prologue
    goto v_14203;
v_14197:
    v_14209 = v_14208;
    goto v_14198;
v_14199:
    v_14208 = v_14207;
    goto v_14200;
v_14201:
    v_14207 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14202;
v_14203:
    goto v_14197;
v_14198:
    goto v_14199;
v_14200:
    goto v_14201;
v_14202:
    {
        fn = elt(env, 1); // r2findindex1
        return (*qfnn(fn))(fn, 3, v_14209, v_14208, v_14207);
    }
}



// Code for !:dmpluslst

static LispObject CC_Tdmpluslst(LispObject env,
                         LispObject v_14193)
{
    env = qenv(env);
    LispObject v_14220, v_14221;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14193);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_14221 = v_14193;
// end of prologue
    v_14220 = v_14221;
    if (v_14220 == nil) goto v_14197;
    else goto v_14198;
v_14197:
    v_14220 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14196;
v_14198:
    v_14220 = v_14221;
    v_14220 = qcdr(v_14220);
    if (v_14220 == nil) goto v_14201;
    else goto v_14202;
v_14201:
    v_14220 = v_14221;
    v_14220 = qcar(v_14220);
    goto v_14196;
v_14202:
    goto v_14214;
v_14210:
    v_14220 = v_14221;
    stack[0] = qcar(v_14220);
    goto v_14211;
v_14212:
    v_14220 = v_14221;
    v_14220 = qcdr(v_14220);
    v_14220 = CC_Tdmpluslst(elt(env, 0), v_14220);
    env = stack[-1];
    goto v_14213;
v_14214:
    goto v_14210;
v_14211:
    goto v_14212;
v_14213:
    {
        LispObject v_14223 = stack[0];
        fn = elt(env, 1); // !:plus
        return (*qfn2(fn))(fn, v_14223, v_14220);
    }
    v_14220 = nil;
v_14196:
    return onevalue(v_14220);
}



// Code for physopordchk

static LispObject CC_physopordchk(LispObject env,
                         LispObject v_14193, LispObject v_14194)
{
    env = qenv(env);
    LispObject v_14250, v_14251, v_14252;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14194,v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14193,v_14194);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_14194;
    v_14250 = v_14193;
// end of prologue
    fn = elt(env, 2); // !*collectphysops
    v_14250 = (*qfn1(fn))(fn, v_14250);
    env = stack[-2];
    fn = elt(env, 3); // deletemult!*
    v_14250 = (*qfn1(fn))(fn, v_14250);
    env = stack[-2];
    stack[-1] = v_14250;
    v_14250 = stack[0];
    fn = elt(env, 2); // !*collectphysops
    v_14250 = (*qfn1(fn))(fn, v_14250);
    env = stack[-2];
    fn = elt(env, 3); // deletemult!*
    v_14250 = (*qfn1(fn))(fn, v_14250);
    env = stack[-2];
    v_14252 = v_14250;
    v_14250 = stack[-1];
    if (v_14250 == nil) goto v_14211;
    else goto v_14212;
v_14211:
    v_14250 = lisp_true;
    goto v_14210;
v_14212:
    v_14250 = v_14252;
    if (v_14250 == nil) goto v_14215;
    else goto v_14216;
v_14215:
    v_14250 = nil;
    goto v_14210;
v_14216:
    goto v_14226;
v_14222:
    v_14251 = elt(env, 1); // unit
    goto v_14223;
v_14224:
    v_14250 = stack[-1];
    goto v_14225;
v_14226:
    goto v_14222;
v_14223:
    goto v_14224;
v_14225:
    v_14250 = Lmember(nil, v_14251, v_14250);
    if (v_14250 == nil) goto v_14221;
    else goto v_14219;
v_14221:
    goto v_14235;
v_14231:
    v_14251 = elt(env, 1); // unit
    goto v_14232;
v_14233:
    v_14250 = v_14252;
    goto v_14234;
v_14235:
    goto v_14231;
v_14232:
    goto v_14233;
v_14234:
    v_14250 = Lmember(nil, v_14251, v_14250);
    if (v_14250 == nil) goto v_14230;
    else goto v_14219;
v_14230:
    goto v_14220;
v_14219:
    v_14250 = nil;
    goto v_14210;
v_14220:
    goto v_14247;
v_14243:
    v_14250 = stack[-1];
    goto v_14244;
v_14245:
    v_14251 = v_14252;
    goto v_14246;
v_14247:
    goto v_14243;
v_14244:
    goto v_14245;
v_14246:
    {
        fn = elt(env, 4); // physopordchk!*
        return (*qfn2(fn))(fn, v_14250, v_14251);
    }
    v_14250 = nil;
v_14210:
    return onevalue(v_14250);
}



// Code for copy!-tree

static LispObject CC_copyKtree(LispObject env,
                         LispObject v_14193)
{
    env = qenv(env);
    LispObject v_14278, v_14279, v_14280, v_14281;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14193);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_14193;
// end of prologue
    v_14278 = stack[-2];
    if (v_14278 == nil) goto v_14197;
    else goto v_14198;
v_14197:
    v_14278 = nil;
    goto v_14196;
v_14198:
    v_14278 = (LispObject)48+TAG_FIXNUM; // 3
    v_14278 = Lmkvect(nil, v_14278);
    env = stack[-4];
    stack[-3] = v_14278;
    goto v_14214;
v_14208:
    v_14281 = stack[-3];
    goto v_14209;
v_14210:
    v_14280 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14211;
v_14212:
    goto v_14221;
v_14217:
    v_14279 = stack[-2];
    goto v_14218;
v_14219:
    v_14278 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14220;
v_14221:
    goto v_14217;
v_14218:
    goto v_14219;
v_14220:
    v_14278 = *(LispObject *)((char *)v_14279 + (CELL-TAG_VECTOR) + (((intptr_t)v_14278-TAG_FIXNUM)/(16/CELL)));
    goto v_14213;
v_14214:
    goto v_14208;
v_14209:
    goto v_14210;
v_14211:
    goto v_14212;
v_14213:
    *(LispObject *)((char *)v_14281 + (CELL-TAG_VECTOR) + (((intptr_t)v_14280-TAG_FIXNUM)/(16/CELL))) = v_14278;
    goto v_14231;
v_14225:
    v_14281 = stack[-3];
    goto v_14226;
v_14227:
    v_14280 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14228;
v_14229:
    goto v_14238;
v_14234:
    v_14279 = stack[-2];
    goto v_14235;
v_14236:
    v_14278 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14237;
v_14238:
    goto v_14234;
v_14235:
    goto v_14236;
v_14237:
    v_14278 = *(LispObject *)((char *)v_14279 + (CELL-TAG_VECTOR) + (((intptr_t)v_14278-TAG_FIXNUM)/(16/CELL)));
    goto v_14230;
v_14231:
    goto v_14225;
v_14226:
    goto v_14227;
v_14228:
    goto v_14229;
v_14230:
    *(LispObject *)((char *)v_14281 + (CELL-TAG_VECTOR) + (((intptr_t)v_14280-TAG_FIXNUM)/(16/CELL))) = v_14278;
    goto v_14248;
v_14242:
    v_14281 = stack[-3];
    goto v_14243;
v_14244:
    v_14280 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_14245;
v_14246:
    goto v_14255;
v_14251:
    v_14279 = stack[-2];
    goto v_14252;
v_14253:
    v_14278 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_14254;
v_14255:
    goto v_14251;
v_14252:
    goto v_14253;
v_14254:
    v_14278 = *(LispObject *)((char *)v_14279 + (CELL-TAG_VECTOR) + (((intptr_t)v_14278-TAG_FIXNUM)/(16/CELL)));
    goto v_14247;
v_14248:
    goto v_14242;
v_14243:
    goto v_14244;
v_14245:
    goto v_14246;
v_14247:
    *(LispObject *)((char *)v_14281 + (CELL-TAG_VECTOR) + (((intptr_t)v_14280-TAG_FIXNUM)/(16/CELL))) = v_14278;
    goto v_14265;
v_14259:
    stack[-1] = stack[-3];
    goto v_14260;
v_14261:
    stack[0] = (LispObject)48+TAG_FIXNUM; // 3
    goto v_14262;
v_14263:
    goto v_14273;
v_14269:
    v_14279 = stack[-2];
    goto v_14270;
v_14271:
    v_14278 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_14272;
v_14273:
    goto v_14269;
v_14270:
    goto v_14271;
v_14272:
    v_14278 = *(LispObject *)((char *)v_14279 + (CELL-TAG_VECTOR) + (((intptr_t)v_14278-TAG_FIXNUM)/(16/CELL)));
    v_14278 = CC_copyKtree(elt(env, 0), v_14278);
    goto v_14264;
v_14265:
    goto v_14259;
v_14260:
    goto v_14261;
v_14262:
    goto v_14263;
v_14264:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_14278;
    v_14278 = stack[-3];
    goto v_14196;
    v_14278 = nil;
v_14196:
    return onevalue(v_14278);
}



// Code for setdiff_according_to

static LispObject CC_setdiff_according_to(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_14387, v_14388, v_14389;
    LispObject v_14195, v_14194, v_14193;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "setdiff_according_to");
    va_start(aa, nargs);
    v_14193 = va_arg(aa, LispObject);
    v_14194 = va_arg(aa, LispObject);
    v_14195 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_14195,v_14194,v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_14193,v_14194,v_14195);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_14195;
    stack[-2] = v_14194;
    stack[-3] = v_14193;
// end of prologue
    stack[-4] = nil;
    stack[0] = nil;
v_14204:
    v_14387 = stack[-3];
    if (v_14387 == nil) goto v_14207;
    v_14387 = stack[-2];
    if (v_14387 == nil) goto v_14207;
    goto v_14208;
v_14207:
    goto v_14203;
v_14208:
    goto v_14222;
v_14218:
    v_14387 = stack[-3];
    v_14388 = qcar(v_14387);
    goto v_14219;
v_14220:
    v_14387 = stack[-2];
    v_14387 = qcar(v_14387);
    goto v_14221;
v_14222:
    goto v_14218;
v_14219:
    goto v_14220;
v_14221:
    if (v_14388 == v_14387) goto v_14216;
    else goto v_14217;
v_14216:
    v_14387 = stack[-3];
    v_14387 = qcdr(v_14387);
    stack[-3] = v_14387;
    v_14387 = stack[-2];
    v_14387 = qcdr(v_14387);
    stack[-2] = v_14387;
    v_14387 = stack[-1];
    v_14387 = qcdr(v_14387);
    stack[-1] = v_14387;
    goto v_14215;
v_14217:
    v_14387 = stack[0];
    if (v_14387 == nil) goto v_14241;
    else goto v_14242;
v_14241:
    v_14387 = stack[-3];
    v_14387 = qcar(v_14387);
    v_14387 = Lconsp(nil, v_14387);
    env = stack[-5];
    if (v_14387 == nil) goto v_14246;
    else goto v_14245;
v_14246:
    v_14387 = stack[-2];
    v_14387 = qcar(v_14387);
    v_14387 = Lconsp(nil, v_14387);
    env = stack[-5];
v_14245:
    goto v_14240;
v_14242:
    v_14387 = nil;
    goto v_14240;
    v_14387 = nil;
v_14240:
    if (v_14387 == nil) goto v_14238;
    v_14387 = lisp_true;
    stack[0] = v_14387;
    goto v_14236;
v_14238:
v_14236:
    v_14387 = stack[0];
    if (v_14387 == nil) goto v_14260;
    v_14387 = stack[-2];
    v_14389 = v_14387;
v_14265:
    v_14387 = v_14389;
    if (v_14387 == nil) goto v_14268;
    goto v_14277;
v_14273:
    v_14387 = stack[-3];
    v_14388 = qcar(v_14387);
    goto v_14274;
v_14275:
    v_14387 = v_14389;
    v_14387 = qcar(v_14387);
    goto v_14276;
v_14277:
    goto v_14273;
v_14274:
    goto v_14275;
v_14276:
    if (equal(v_14388, v_14387)) goto v_14268;
    goto v_14269;
v_14268:
    goto v_14264;
v_14269:
    v_14387 = v_14389;
    v_14387 = qcdr(v_14387);
    v_14389 = v_14387;
    goto v_14265;
v_14264:
    v_14387 = v_14389;
    if (v_14387 == nil) goto v_14287;
    else goto v_14288;
v_14287:
    goto v_14295;
v_14291:
    v_14387 = stack[-3];
    v_14388 = qcar(v_14387);
    goto v_14292;
v_14293:
    v_14387 = stack[-4];
    goto v_14294;
v_14295:
    goto v_14291;
v_14292:
    goto v_14293;
v_14294:
    v_14387 = cons(v_14388, v_14387);
    env = stack[-5];
    stack[-4] = v_14387;
    goto v_14286;
v_14288:
v_14286:
    v_14387 = stack[-3];
    v_14387 = qcdr(v_14387);
    stack[-3] = v_14387;
    goto v_14258;
v_14260:
v_14305:
    goto v_14318;
v_14314:
    v_14387 = stack[-1];
    v_14388 = qcar(v_14387);
    goto v_14315;
v_14316:
    v_14387 = stack[-3];
    v_14387 = qcar(v_14387);
    goto v_14317;
v_14318:
    goto v_14314;
v_14315:
    goto v_14316;
v_14317:
    if (equal(v_14388, v_14387)) goto v_14313;
    goto v_14328;
v_14324:
    v_14387 = stack[-1];
    v_14388 = qcar(v_14387);
    goto v_14325;
v_14326:
    v_14387 = stack[-2];
    v_14387 = qcar(v_14387);
    goto v_14327;
v_14328:
    goto v_14324;
v_14325:
    goto v_14326;
v_14327:
    v_14387 = Lneq(nil, v_14388, v_14387);
    env = stack[-5];
    goto v_14311;
v_14313:
    v_14387 = nil;
    goto v_14311;
    v_14387 = nil;
v_14311:
    if (v_14387 == nil) goto v_14308;
    else goto v_14309;
v_14308:
    goto v_14304;
v_14309:
    v_14387 = stack[-1];
    v_14387 = qcdr(v_14387);
    stack[-1] = v_14387;
    goto v_14305;
v_14304:
    goto v_14347;
v_14343:
    v_14387 = stack[-1];
    v_14388 = qcar(v_14387);
    goto v_14344;
v_14345:
    v_14387 = stack[-3];
    v_14387 = qcar(v_14387);
    goto v_14346;
v_14347:
    goto v_14343;
v_14344:
    goto v_14345;
v_14346:
    if (v_14388 == v_14387) goto v_14341;
    else goto v_14342;
v_14341:
    goto v_14357;
v_14353:
    v_14387 = stack[-3];
    v_14388 = qcar(v_14387);
    goto v_14354;
v_14355:
    v_14387 = stack[-4];
    goto v_14356;
v_14357:
    goto v_14353;
v_14354:
    goto v_14355;
v_14356:
    v_14387 = cons(v_14388, v_14387);
    env = stack[-5];
    stack[-4] = v_14387;
    v_14387 = stack[-3];
    v_14387 = qcdr(v_14387);
    stack[-3] = v_14387;
    goto v_14340;
v_14342:
    v_14387 = stack[-2];
    v_14387 = qcdr(v_14387);
    stack[-2] = v_14387;
    goto v_14340;
v_14340:
    v_14387 = stack[-1];
    v_14387 = qcdr(v_14387);
    stack[-1] = v_14387;
    goto v_14258;
v_14258:
    goto v_14215;
v_14215:
    goto v_14204;
v_14203:
    v_14387 = stack[-3];
    if (v_14387 == nil) goto v_14372;
    goto v_14379;
v_14375:
    v_14387 = stack[-4];
    v_14388 = Lnreverse(nil, v_14387);
    goto v_14376;
v_14377:
    v_14387 = stack[-3];
    goto v_14378;
v_14379:
    goto v_14375;
v_14376:
    goto v_14377;
v_14378:
        return Lnconc(nil, v_14388, v_14387);
v_14372:
    v_14387 = stack[-4];
        return Lnreverse(nil, v_14387);
    v_14387 = nil;
    return onevalue(v_14387);
}



// Code for setk_super_vectorfield

static LispObject CC_setk_super_vectorfield(LispObject env,
                         LispObject v_14193, LispObject v_14194)
{
    env = qenv(env);
    LispObject v_14367, v_14368, v_14369, v_14370, v_14371;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14194,v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14193,v_14194);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_14194;
    stack[0] = v_14193;
// end of prologue
    goto v_14211;
v_14207:
    v_14367 = stack[0];
    v_14368 = Llength(nil, v_14367);
    env = stack[-4];
    goto v_14208;
v_14209:
    v_14367 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_14210;
v_14211:
    goto v_14207;
v_14208:
    goto v_14209;
v_14210:
    if (v_14368 == v_14367) goto v_14206;
    goto v_14224;
v_14216:
    v_14370 = stack[0];
    goto v_14217;
v_14218:
    v_14369 = stack[-2];
    goto v_14219;
v_14220:
    v_14368 = nil;
    goto v_14221;
v_14222:
    v_14367 = lisp_true;
    goto v_14223;
v_14224:
    goto v_14216;
v_14217:
    goto v_14218;
v_14219:
    goto v_14220;
v_14221:
    goto v_14222;
v_14223:
    {
        fn = elt(env, 5); // let2
        return (*qfnn(fn))(fn, 4, v_14370, v_14369, v_14368, v_14367);
    }
v_14206:
    v_14367 = stack[0];
    v_14367 = qcar(v_14367);
    stack[-3] = v_14367;
    v_14367 = stack[0];
    v_14367 = qcdr(v_14367);
    v_14367 = qcar(v_14367);
    stack[-1] = v_14367;
    v_14367 = stack[-1];
    if (!consp(v_14367)) goto v_14241;
    goto v_14251;
v_14247:
    v_14367 = stack[-1];
    v_14368 = qcar(v_14367);
    goto v_14248;
v_14249:
    v_14367 = elt(env, 1); // ext
    goto v_14250;
v_14251:
    goto v_14247;
v_14248:
    goto v_14249;
v_14250:
    if (v_14368 == v_14367) goto v_14245;
    else goto v_14246;
v_14245:
    goto v_14259;
v_14255:
    v_14367 = stack[-1];
    v_14368 = Llength(nil, v_14367);
    env = stack[-4];
    goto v_14256;
v_14257:
    v_14367 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_14258;
v_14259:
    goto v_14255;
v_14256:
    goto v_14257;
v_14258:
    v_14367 = (v_14368 == v_14367 ? lisp_true : nil);
    goto v_14244;
v_14246:
    v_14367 = nil;
    goto v_14244;
    v_14367 = nil;
v_14244:
    goto v_14239;
v_14241:
    v_14367 = nil;
    goto v_14239;
    v_14367 = nil;
v_14239:
    if (v_14367 == nil) goto v_14237;
    goto v_14275;
v_14271:
    v_14368 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14272;
v_14273:
    v_14367 = stack[-1];
    v_14367 = qcdr(v_14367);
    v_14367 = qcar(v_14367);
    goto v_14274;
v_14275:
    goto v_14271;
v_14272:
    goto v_14273;
v_14274:
    v_14367 = list2(v_14368, v_14367);
    env = stack[-4];
    goto v_14235;
v_14237:
    goto v_14287;
v_14283:
    v_14368 = stack[-3];
    goto v_14284;
v_14285:
    v_14367 = elt(env, 2); // variables
    goto v_14286;
v_14287:
    goto v_14283;
v_14284:
    goto v_14285;
v_14286:
    v_14367 = get(v_14368, v_14367);
    env = stack[-4];
    stack[0] = v_14367;
    v_14367 = (LispObject)16+TAG_FIXNUM; // 1
    v_14369 = v_14367;
v_14293:
    v_14367 = stack[0];
    if (v_14367 == nil) goto v_14296;
    goto v_14305;
v_14301:
    v_14368 = stack[-1];
    goto v_14302;
v_14303:
    v_14367 = stack[0];
    v_14367 = qcar(v_14367);
    goto v_14304;
v_14305:
    goto v_14301;
v_14302:
    goto v_14303;
v_14304:
    if (equal(v_14368, v_14367)) goto v_14296;
    goto v_14297;
v_14296:
    goto v_14292;
v_14297:
    v_14367 = stack[0];
    v_14367 = qcdr(v_14367);
    stack[0] = v_14367;
    v_14367 = v_14369;
    v_14367 = add1(v_14367);
    env = stack[-4];
    v_14369 = v_14367;
    goto v_14293;
v_14292:
    v_14367 = stack[0];
    if (v_14367 == nil) goto v_14316;
    else goto v_14317;
v_14316:
    goto v_14330;
v_14320:
    v_14371 = elt(env, 3); // "SETK_SUPER_VECTORFIELD:"
    goto v_14321;
v_14322:
    v_14370 = stack[-1];
    goto v_14323;
v_14324:
    v_14369 = elt(env, 4); // "not a valid variable for"
    goto v_14325;
v_14326:
    v_14368 = stack[-3];
    goto v_14327;
v_14328:
    v_14367 = lisp_true;
    goto v_14329;
v_14330:
    goto v_14320;
v_14321:
    goto v_14322;
v_14323:
    goto v_14324;
v_14325:
    goto v_14326;
v_14327:
    goto v_14328;
v_14329:
    fn = elt(env, 6); // msgpri
    v_14367 = (*qfnn(fn))(fn, 5, v_14371, v_14370, v_14369, v_14368, v_14367);
    env = stack[-4];
    goto v_14315;
v_14317:
    goto v_14343;
v_14339:
    v_14367 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14340;
v_14341:
    v_14368 = v_14369;
    goto v_14342;
v_14343:
    goto v_14339;
v_14340:
    goto v_14341;
v_14342:
    v_14367 = list2(v_14367, v_14368);
    env = stack[-4];
    goto v_14315;
    v_14367 = nil;
v_14315:
    goto v_14235;
    v_14367 = nil;
v_14235:
    goto v_14355;
v_14347:
    goto v_14361;
v_14357:
    v_14368 = stack[-3];
    goto v_14358;
v_14359:
    goto v_14360;
v_14361:
    goto v_14357;
v_14358:
    goto v_14359;
v_14360:
    v_14370 = cons(v_14368, v_14367);
    env = stack[-4];
    goto v_14348;
v_14349:
    v_14369 = stack[-2];
    goto v_14350;
v_14351:
    v_14368 = nil;
    goto v_14352;
v_14353:
    v_14367 = lisp_true;
    goto v_14354;
v_14355:
    goto v_14347;
v_14348:
    goto v_14349;
v_14350:
    goto v_14351;
v_14352:
    goto v_14353;
v_14354:
    {
        fn = elt(env, 5); // let2
        return (*qfnn(fn))(fn, 4, v_14370, v_14369, v_14368, v_14367);
    }
    return onevalue(v_14367);
}



// Code for lalr_construct_fn

static LispObject CC_lalr_construct_fn(LispObject env,
                         LispObject v_14193, LispObject v_14194)
{
    env = qenv(env);
    LispObject v_14227, v_14228, v_14229;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14194,v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14193,v_14194);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_14194;
    stack[-2] = v_14193;
// end of prologue
    v_14227 = elt(env, 1); // g
    v_14227 = Lgensym1(nil, v_14227);
    env = stack[-4];
    stack[-3] = v_14227;
    goto v_14208;
v_14202:
    stack[0] = elt(env, 2); // lambda
    goto v_14203;
v_14204:
    v_14227 = stack[-1];
    fn = elt(env, 5); // lalr_make_arglist
    v_14228 = (*qfn1(fn))(fn, v_14227);
    env = stack[-4];
    goto v_14205;
v_14206:
    v_14227 = stack[-2];
    goto v_14207;
v_14208:
    goto v_14202;
v_14203:
    goto v_14204;
v_14205:
    goto v_14206;
v_14207:
    v_14227 = list2star(stack[0], v_14228, v_14227);
    env = stack[-4];
    stack[-2] = v_14227;
    v_14227 = nil;
// Binding !*pwrds
// FLUIDBIND: reloadenv=4 litvec-offset=3 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 3, 0);
    qvalue(elt(env, 3)) = v_14227; // !*pwrds
    goto v_14222;
v_14216:
    v_14229 = stack[-3];
    goto v_14217;
v_14218:
    v_14228 = elt(env, 4); // expr
    goto v_14219;
v_14220:
    v_14227 = stack[-2];
    goto v_14221;
v_14222:
    goto v_14216;
v_14217:
    goto v_14218;
v_14219:
    goto v_14220;
v_14221:
    fn = elt(env, 6); // putd
    v_14227 = (*qfnn(fn))(fn, 3, v_14229, v_14228, v_14227);
    ;}  // end of a binding scope
    v_14227 = stack[-3];
    return onevalue(v_14227);
}



// Code for add2locs

static LispObject CC_add2locs(LispObject env,
                         LispObject v_14193)
{
    env = qenv(env);
    LispObject v_14336, v_14337;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14193);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_14337 = v_14193;
// end of prologue
    v_14336 = qvalue(elt(env, 1)); // !*globals
    if (v_14336 == nil) goto v_14201;
    v_14336 = v_14337;
    stack[-2] = v_14336;
v_14206:
    v_14336 = stack[-2];
    if (v_14336 == nil) goto v_14210;
    else goto v_14211;
v_14210:
    goto v_14205;
v_14211:
    v_14336 = stack[-2];
    v_14336 = qcar(v_14336);
    stack[-1] = v_14336;
    goto v_14221;
v_14217:
    v_14337 = stack[-1];
    goto v_14218;
v_14219:
    v_14336 = qvalue(elt(env, 2)); // locls!*
    goto v_14220;
v_14221:
    goto v_14217;
v_14218:
    goto v_14219;
v_14220:
    v_14336 = Lassoc(nil, v_14337, v_14336);
    stack[-3] = v_14336;
    v_14336 = stack[-3];
    if (v_14336 == nil) goto v_14228;
    goto v_14237;
v_14233:
    v_14337 = stack[-1];
    goto v_14234;
v_14235:
    v_14336 = elt(env, 3); // dclglb
    goto v_14236;
v_14237:
    goto v_14233;
v_14234:
    goto v_14235;
v_14236:
    v_14336 = Lflagp(nil, v_14337, v_14336);
    env = stack[-4];
    if (v_14336 == nil) goto v_14228;
    v_14336 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 11); // qerline
    v_14336 = (*qfn1(fn))(fn, v_14336);
    env = stack[-4];
    v_14336 = elt(env, 4); // "*** Variable "
    v_14336 = Lprinc(nil, v_14336);
    env = stack[-4];
    v_14336 = stack[-1];
    v_14336 = Lprin(nil, v_14336);
    env = stack[-4];
    v_14336 = elt(env, 5); // " nested declaration in "
    v_14336 = Lprinc(nil, v_14336);
    env = stack[-4];
    v_14336 = qvalue(elt(env, 6)); // curfun!*
    fn = elt(env, 12); // princng
    v_14336 = (*qfn1(fn))(fn, v_14336);
    env = stack[-4];
    v_14336 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 13); // newline
    v_14336 = (*qfn1(fn))(fn, v_14336);
    env = stack[-4];
    goto v_14257;
v_14253:
    stack[0] = stack[-3];
    goto v_14254;
v_14255:
    goto v_14264;
v_14260:
    v_14337 = nil;
    goto v_14261;
v_14262:
    v_14336 = stack[-3];
    goto v_14263;
v_14264:
    goto v_14260;
v_14261:
    goto v_14262;
v_14263:
    v_14336 = cons(v_14337, v_14336);
    env = stack[-4];
    goto v_14256;
v_14257:
    goto v_14253;
v_14254:
    goto v_14255;
v_14256:
    v_14336 = Lrplacd(nil, stack[0], v_14336);
    env = stack[-4];
    goto v_14226;
v_14228:
    goto v_14276;
v_14270:
    stack[0] = stack[-1];
    goto v_14271;
v_14272:
    v_14336 = nil;
    v_14337 = ncons(v_14336);
    env = stack[-4];
    goto v_14273;
v_14274:
    v_14336 = qvalue(elt(env, 2)); // locls!*
    goto v_14275;
v_14276:
    goto v_14270;
v_14271:
    goto v_14272;
v_14273:
    goto v_14274;
v_14275:
    v_14336 = acons(stack[0], v_14337, v_14336);
    env = stack[-4];
    qvalue(elt(env, 2)) = v_14336; // locls!*
    goto v_14226;
v_14226:
    goto v_14294;
v_14290:
    v_14337 = stack[-1];
    goto v_14291;
v_14292:
    v_14336 = elt(env, 3); // dclglb
    goto v_14293;
v_14294:
    goto v_14290;
v_14291:
    goto v_14292;
v_14293:
    v_14336 = Lflagp(nil, v_14337, v_14336);
    env = stack[-4];
    if (v_14336 == nil) goto v_14288;
    v_14336 = lisp_true;
    goto v_14286;
v_14288:
    goto v_14305;
v_14301:
    v_14337 = stack[-1];
    goto v_14302;
v_14303:
    v_14336 = elt(env, 7); // glb2rf
    goto v_14304;
v_14305:
    goto v_14301;
v_14302:
    goto v_14303;
v_14304:
    v_14336 = Lflagp(nil, v_14337, v_14336);
    env = stack[-4];
    goto v_14286;
    v_14336 = nil;
v_14286:
    if (v_14336 == nil) goto v_14284;
    v_14336 = stack[-1];
    fn = elt(env, 14); // globind
    v_14336 = (*qfn1(fn))(fn, v_14336);
    env = stack[-4];
    goto v_14282;
v_14284:
v_14282:
    goto v_14319;
v_14315:
    v_14337 = stack[-1];
    goto v_14316;
v_14317:
    v_14336 = elt(env, 8); // seen
    goto v_14318;
v_14319:
    goto v_14315;
v_14316:
    goto v_14317;
v_14318:
    v_14336 = Lflagp(nil, v_14337, v_14336);
    env = stack[-4];
    if (v_14336 == nil) goto v_14313;
    v_14336 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 11); // qerline
    v_14336 = (*qfn1(fn))(fn, v_14336);
    env = stack[-4];
    v_14336 = elt(env, 9); // "*** Function "
    v_14336 = Lprinc(nil, v_14336);
    env = stack[-4];
    v_14336 = stack[-1];
    fn = elt(env, 12); // princng
    v_14336 = (*qfn1(fn))(fn, v_14336);
    env = stack[-4];
    v_14336 = elt(env, 10); // " used as variable in "
    v_14336 = Lprinc(nil, v_14336);
    env = stack[-4];
    v_14336 = qvalue(elt(env, 6)); // curfun!*
    fn = elt(env, 12); // princng
    v_14336 = (*qfn1(fn))(fn, v_14336);
    env = stack[-4];
    v_14336 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 13); // newline
    v_14336 = (*qfn1(fn))(fn, v_14336);
    env = stack[-4];
    goto v_14311;
v_14313:
v_14311:
    v_14336 = stack[-2];
    v_14336 = qcdr(v_14336);
    stack[-2] = v_14336;
    goto v_14206;
v_14205:
    goto v_14199;
v_14201:
v_14199:
    v_14336 = nil;
    return onevalue(v_14336);
}



// Code for cl_f2ml

static LispObject CC_cl_f2ml(LispObject env,
                         LispObject v_14193, LispObject v_14194)
{
    env = qenv(env);
    LispObject v_14490, v_14491, v_14492;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14194,v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14193,v_14194);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_14194;
    stack[0] = v_14193;
// end of prologue
v_14192:
    v_14490 = stack[0];
    if (!consp(v_14490)) goto v_14201;
    else goto v_14202;
v_14201:
    v_14490 = stack[0];
    goto v_14200;
v_14202:
    v_14490 = stack[0];
    v_14490 = qcar(v_14490);
    goto v_14200;
    v_14490 = nil;
v_14200:
    v_14492 = v_14490;
    goto v_14221;
v_14217:
    v_14491 = stack[0];
    goto v_14218;
v_14219:
    v_14490 = elt(env, 1); // true
    goto v_14220;
v_14221:
    goto v_14217;
v_14218:
    goto v_14219;
v_14220:
    if (v_14491 == v_14490) goto v_14215;
    else goto v_14216;
v_14215:
    v_14490 = lisp_true;
    goto v_14214;
v_14216:
    goto v_14231;
v_14227:
    v_14491 = stack[0];
    goto v_14228;
v_14229:
    v_14490 = elt(env, 2); // false
    goto v_14230;
v_14231:
    goto v_14227;
v_14228:
    goto v_14229;
v_14230:
    v_14490 = (v_14491 == v_14490 ? lisp_true : nil);
    goto v_14214;
    v_14490 = nil;
v_14214:
    if (v_14490 == nil) goto v_14212;
    v_14490 = nil;
    goto v_14198;
v_14212:
    goto v_14256;
v_14252:
    v_14491 = v_14492;
    goto v_14253;
v_14254:
    v_14490 = elt(env, 3); // or
    goto v_14255;
v_14256:
    goto v_14252;
v_14253:
    goto v_14254;
v_14255:
    if (v_14491 == v_14490) goto v_14250;
    else goto v_14251;
v_14250:
    v_14490 = lisp_true;
    goto v_14249;
v_14251:
    goto v_14266;
v_14262:
    v_14491 = v_14492;
    goto v_14263;
v_14264:
    v_14490 = elt(env, 4); // and
    goto v_14265;
v_14266:
    goto v_14262;
v_14263:
    goto v_14264;
v_14265:
    v_14490 = (v_14491 == v_14490 ? lisp_true : nil);
    goto v_14249;
    v_14490 = nil;
v_14249:
    if (v_14490 == nil) goto v_14247;
    v_14490 = lisp_true;
    goto v_14245;
v_14247:
    goto v_14277;
v_14273:
    v_14491 = v_14492;
    goto v_14274;
v_14275:
    v_14490 = elt(env, 5); // not
    goto v_14276;
v_14277:
    goto v_14273;
v_14274:
    goto v_14275;
v_14276:
    v_14490 = (v_14491 == v_14490 ? lisp_true : nil);
    goto v_14245;
    v_14490 = nil;
v_14245:
    if (v_14490 == nil) goto v_14243;
    v_14490 = lisp_true;
    goto v_14241;
v_14243:
    goto v_14292;
v_14288:
    v_14491 = v_14492;
    goto v_14289;
v_14290:
    v_14490 = elt(env, 6); // impl
    goto v_14291;
v_14292:
    goto v_14288;
v_14289:
    goto v_14290;
v_14291:
    if (v_14491 == v_14490) goto v_14286;
    else goto v_14287;
v_14286:
    v_14490 = lisp_true;
    goto v_14285;
v_14287:
    goto v_14306;
v_14302:
    v_14491 = v_14492;
    goto v_14303;
v_14304:
    v_14490 = elt(env, 7); // repl
    goto v_14305;
v_14306:
    goto v_14302;
v_14303:
    goto v_14304;
v_14305:
    if (v_14491 == v_14490) goto v_14300;
    else goto v_14301;
v_14300:
    v_14490 = lisp_true;
    goto v_14299;
v_14301:
    goto v_14316;
v_14312:
    v_14491 = v_14492;
    goto v_14313;
v_14314:
    v_14490 = elt(env, 8); // equiv
    goto v_14315;
v_14316:
    goto v_14312;
v_14313:
    goto v_14314;
v_14315:
    v_14490 = (v_14491 == v_14490 ? lisp_true : nil);
    goto v_14299;
    v_14490 = nil;
v_14299:
    goto v_14285;
    v_14490 = nil;
v_14285:
    goto v_14241;
    v_14490 = nil;
v_14241:
    if (v_14490 == nil) goto v_14239;
    goto v_14325;
v_14321:
    v_14490 = stack[0];
    v_14490 = qcdr(v_14490);
    stack[-4] = v_14490;
    v_14490 = stack[-4];
    if (v_14490 == nil) goto v_14336;
    else goto v_14337;
v_14336:
    v_14490 = nil;
    v_14491 = v_14490;
    goto v_14330;
v_14337:
    v_14490 = stack[-4];
    v_14490 = qcar(v_14490);
    goto v_14349;
v_14345:
    v_14491 = v_14490;
    goto v_14346;
v_14347:
    v_14490 = stack[-3];
    goto v_14348;
v_14349:
    goto v_14345;
v_14346:
    goto v_14347;
v_14348:
    v_14490 = CC_cl_f2ml(elt(env, 0), v_14491, v_14490);
    env = stack[-5];
    v_14490 = ncons(v_14490);
    env = stack[-5];
    stack[-1] = v_14490;
    stack[-2] = v_14490;
v_14331:
    v_14490 = stack[-4];
    v_14490 = qcdr(v_14490);
    stack[-4] = v_14490;
    v_14490 = stack[-4];
    if (v_14490 == nil) goto v_14356;
    else goto v_14357;
v_14356:
    v_14490 = stack[-2];
    v_14491 = v_14490;
    goto v_14330;
v_14357:
    goto v_14365;
v_14361:
    stack[0] = stack[-1];
    goto v_14362;
v_14363:
    v_14490 = stack[-4];
    v_14490 = qcar(v_14490);
    goto v_14376;
v_14372:
    v_14491 = v_14490;
    goto v_14373;
v_14374:
    v_14490 = stack[-3];
    goto v_14375;
v_14376:
    goto v_14372;
v_14373:
    goto v_14374;
v_14375:
    v_14490 = CC_cl_f2ml(elt(env, 0), v_14491, v_14490);
    env = stack[-5];
    v_14490 = ncons(v_14490);
    env = stack[-5];
    goto v_14364;
v_14365:
    goto v_14361;
v_14362:
    goto v_14363;
v_14364:
    v_14490 = Lrplacd(nil, stack[0], v_14490);
    env = stack[-5];
    v_14490 = stack[-1];
    v_14490 = qcdr(v_14490);
    stack[-1] = v_14490;
    goto v_14331;
v_14330:
    goto v_14322;
v_14323:
    v_14490 = elt(env, 9); // plus2
    goto v_14324;
v_14325:
    goto v_14321;
v_14322:
    goto v_14323;
v_14324:
    {
        fn = elt(env, 14); // lto_almerge
        return (*qfn2(fn))(fn, v_14491, v_14490);
    }
v_14239:
    goto v_14394;
v_14390:
    v_14491 = v_14492;
    goto v_14391;
v_14392:
    v_14490 = elt(env, 10); // ex
    goto v_14393;
v_14394:
    goto v_14390;
v_14391:
    goto v_14392;
v_14393:
    if (v_14491 == v_14490) goto v_14388;
    else goto v_14389;
v_14388:
    v_14490 = lisp_true;
    goto v_14387;
v_14389:
    goto v_14404;
v_14400:
    v_14491 = v_14492;
    goto v_14401;
v_14402:
    v_14490 = elt(env, 11); // all
    goto v_14403;
v_14404:
    goto v_14400;
v_14401:
    goto v_14402;
v_14403:
    v_14490 = (v_14491 == v_14490 ? lisp_true : nil);
    goto v_14387;
    v_14490 = nil;
v_14387:
    if (v_14490 == nil) goto v_14385;
    goto v_14413;
v_14409:
    v_14490 = stack[0];
    v_14490 = qcdr(v_14490);
    v_14490 = qcdr(v_14490);
    v_14491 = qcar(v_14490);
    goto v_14410;
v_14411:
    v_14490 = stack[-3];
    goto v_14412;
v_14413:
    goto v_14409;
v_14410:
    goto v_14411;
v_14412:
    stack[0] = v_14491;
    stack[-3] = v_14490;
    goto v_14192;
v_14385:
    goto v_14431;
v_14427:
    v_14491 = v_14492;
    goto v_14428;
v_14429:
    v_14490 = elt(env, 12); // bex
    goto v_14430;
v_14431:
    goto v_14427;
v_14428:
    goto v_14429;
v_14430:
    if (v_14491 == v_14490) goto v_14425;
    else goto v_14426;
v_14425:
    v_14490 = lisp_true;
    goto v_14424;
v_14426:
    goto v_14441;
v_14437:
    v_14491 = v_14492;
    goto v_14438;
v_14439:
    v_14490 = elt(env, 13); // ball
    goto v_14440;
v_14441:
    goto v_14437;
v_14438:
    goto v_14439;
v_14440:
    v_14490 = (v_14491 == v_14490 ? lisp_true : nil);
    goto v_14424;
    v_14490 = nil;
v_14424:
    if (v_14490 == nil) goto v_14422;
    goto v_14450;
v_14446:
    goto v_14456;
v_14452:
    goto v_14462;
v_14458:
    v_14490 = stack[0];
    v_14490 = qcdr(v_14490);
    v_14490 = qcdr(v_14490);
    v_14491 = qcar(v_14490);
    goto v_14459;
v_14460:
    v_14490 = stack[-3];
    goto v_14461;
v_14462:
    goto v_14458;
v_14459:
    goto v_14460;
v_14461:
    stack[-1] = CC_cl_f2ml(elt(env, 0), v_14491, v_14490);
    env = stack[-5];
    goto v_14453;
v_14454:
    goto v_14473;
v_14469:
    v_14490 = stack[0];
    v_14490 = qcdr(v_14490);
    v_14490 = qcdr(v_14490);
    v_14490 = qcdr(v_14490);
    v_14491 = qcar(v_14490);
    goto v_14470;
v_14471:
    v_14490 = stack[-3];
    goto v_14472;
v_14473:
    goto v_14469;
v_14470:
    goto v_14471;
v_14472:
    v_14490 = CC_cl_f2ml(elt(env, 0), v_14491, v_14490);
    env = stack[-5];
    goto v_14455;
v_14456:
    goto v_14452;
v_14453:
    goto v_14454;
v_14455:
    v_14491 = list2(stack[-1], v_14490);
    env = stack[-5];
    goto v_14447;
v_14448:
    v_14490 = elt(env, 9); // plus2
    goto v_14449;
v_14450:
    goto v_14446;
v_14447:
    goto v_14448;
v_14449:
    {
        fn = elt(env, 14); // lto_almerge
        return (*qfn2(fn))(fn, v_14491, v_14490);
    }
v_14422:
    goto v_14486;
v_14482:
    stack[-1] = stack[-3];
    goto v_14483;
v_14484:
    v_14490 = stack[0];
    v_14490 = ncons(v_14490);
    env = stack[-5];
    goto v_14485;
v_14486:
    goto v_14482;
v_14483:
    goto v_14484;
v_14485:
    {
        LispObject v_14498 = stack[-1];
        fn = elt(env, 15); // apply
        return (*qfn2(fn))(fn, v_14498, v_14490);
    }
v_14198:
    return onevalue(v_14490);
}



// Code for texstrlen

static LispObject CC_texstrlen(LispObject env,
                         LispObject v_14193)
{
    env = qenv(env);
    LispObject v_14245, v_14246, v_14247;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14193);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_14245 = v_14193;
// end of prologue
    v_14246 = (LispObject)0+TAG_FIXNUM; // 0
    v_14247 = v_14246;
    v_14246 = nil;
    stack[0] = v_14245;
v_14205:
    v_14245 = stack[0];
    if (v_14245 == nil) goto v_14209;
    else goto v_14210;
v_14209:
    goto v_14204;
v_14210:
    v_14245 = stack[0];
    v_14245 = qcar(v_14245);
    if (v_14246 == nil) goto v_14222;
    else goto v_14223;
v_14222:
    goto v_14229;
v_14225:
    v_14246 = v_14245;
    goto v_14226;
v_14227:
    v_14245 = elt(env, 1); // !!
    goto v_14228;
v_14229:
    goto v_14225;
v_14226:
    goto v_14227;
v_14228:
    v_14245 = (v_14246 == v_14245 ? lisp_true : nil);
    goto v_14221;
v_14223:
    v_14245 = nil;
    goto v_14221;
    v_14245 = nil;
v_14221:
    if (v_14245 == nil) goto v_14219;
    v_14245 = lisp_true;
    v_14246 = v_14245;
    goto v_14217;
v_14219:
    v_14245 = v_14247;
    v_14245 = add1(v_14245);
    env = stack[-1];
    v_14247 = v_14245;
    v_14245 = nil;
    v_14246 = v_14245;
    goto v_14217;
v_14217:
    v_14245 = stack[0];
    v_14245 = qcdr(v_14245);
    stack[0] = v_14245;
    goto v_14205;
v_14204:
    v_14245 = v_14247;
    return onevalue(v_14245);
}



// Code for cl_smsimpl!-junct1

static LispObject CC_cl_smsimplKjunct1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_14611, v_14612, v_14613, v_14614, v_14615, v_14616;
    LispObject fn;
    LispObject v_14199, v_14198, v_14197, v_14196, v_14195, v_14194, v_14193;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 7, "cl_smsimpl-junct1");
    va_start(aa, nargs);
    v_14193 = va_arg(aa, LispObject);
    v_14194 = va_arg(aa, LispObject);
    v_14195 = va_arg(aa, LispObject);
    v_14196 = va_arg(aa, LispObject);
    v_14197 = va_arg(aa, LispObject);
    v_14198 = va_arg(aa, LispObject);
    v_14199 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_14199,v_14198,v_14197,v_14196,v_14195,v_14194);
        push(v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_14193,v_14194,v_14195,v_14196,v_14197,v_14198);
        pop(v_14199);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-3] = v_14199;
    stack[-4] = v_14198;
    stack[-5] = v_14197;
    stack[-6] = v_14196;
    stack[-7] = v_14195;
    v_14611 = v_14194;
    stack[-8] = v_14193;
// end of prologue
    stack[-9] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
v_14211:
    v_14611 = stack[-7];
    if (v_14611 == nil) goto v_14214;
    else goto v_14215;
v_14214:
    goto v_14210;
v_14215:
    v_14611 = stack[-7];
    v_14611 = qcar(v_14611);
    v_14612 = v_14611;
    v_14611 = stack[-7];
    v_14611 = qcdr(v_14611);
    stack[-7] = v_14611;
    v_14611 = v_14612;
    stack[-9] = v_14611;
    goto v_14236;
v_14228:
    stack[-10] = stack[-9];
    goto v_14229;
v_14230:
    stack[0] = stack[-5];
    goto v_14231;
v_14232:
    v_14611 = stack[-4];
    v_14612 = sub1(v_14611);
    env = stack[-11];
    goto v_14233;
v_14234:
    v_14611 = stack[-8];
    goto v_14235;
v_14236:
    goto v_14228;
v_14229:
    goto v_14230;
v_14231:
    goto v_14232;
v_14233:
    goto v_14234;
v_14235:
    fn = elt(env, 14); // cl_simpl1
    v_14611 = (*qfnn(fn))(fn, 4, stack[-10], stack[0], v_14612, v_14611);
    env = stack[-11];
    stack[-10] = v_14611;
    v_14611 = stack[-10];
    if (!consp(v_14611)) goto v_14244;
    else goto v_14245;
v_14244:
    v_14611 = stack[-10];
    goto v_14243;
v_14245:
    v_14611 = stack[-10];
    v_14611 = qcar(v_14611);
    goto v_14243;
    v_14611 = nil;
v_14243:
    v_14613 = v_14611;
    goto v_14260;
v_14256:
    v_14612 = v_14613;
    goto v_14257;
v_14258:
    v_14611 = stack[-3];
    goto v_14259;
v_14260:
    goto v_14256;
v_14257:
    goto v_14258;
v_14259:
    if (v_14612 == v_14611) goto v_14254;
    else goto v_14255;
v_14254:
    v_14611 = stack[-3];
    stack[-9] = v_14611;
    v_14611 = nil;
    stack[-7] = v_14611;
    goto v_14253;
v_14255:
    goto v_14271;
v_14267:
    v_14612 = v_14613;
    goto v_14268;
v_14269:
    v_14611 = stack[-8];
    goto v_14270;
v_14271:
    goto v_14267;
v_14268:
    goto v_14269;
v_14270:
    if (v_14612 == v_14611) goto v_14265;
    else goto v_14266;
v_14265:
    v_14611 = stack[-10];
    v_14611 = qcdr(v_14611);
    stack[0] = v_14611;
v_14278:
    v_14611 = stack[0];
    if (v_14611 == nil) goto v_14281;
    v_14611 = stack[0];
    v_14611 = qcar(v_14611);
    fn = elt(env, 15); // cl_atfp
    v_14611 = (*qfn1(fn))(fn, v_14611);
    env = stack[-11];
    if (v_14611 == nil) goto v_14281;
    goto v_14282;
v_14281:
    goto v_14277;
v_14282:
    goto v_14295;
v_14291:
    v_14611 = stack[0];
    v_14612 = qcar(v_14611);
    goto v_14292;
v_14293:
    v_14611 = stack[-1];
    goto v_14294;
v_14295:
    goto v_14291;
v_14292:
    goto v_14293;
v_14294:
    v_14611 = cons(v_14612, v_14611);
    env = stack[-11];
    stack[-1] = v_14611;
    v_14611 = stack[0];
    v_14611 = qcdr(v_14611);
    stack[0] = v_14611;
    goto v_14278;
v_14277:
    v_14611 = qvalue(elt(env, 1)); // !*rlsiidem
    if (v_14611 == nil) goto v_14304;
    v_14611 = stack[-1];
    if (v_14611 == nil) goto v_14304;
    goto v_14314;
v_14310:
    v_14611 = stack[-2];
    v_14612 = Lnreverse(nil, v_14611);
    env = stack[-11];
    goto v_14311;
v_14312:
    v_14611 = stack[-7];
    goto v_14313;
v_14314:
    goto v_14310;
v_14311:
    goto v_14312;
v_14313:
    v_14611 = Lnconc(nil, v_14612, v_14611);
    env = stack[-11];
    stack[-7] = v_14611;
    v_14611 = nil;
    stack[-2] = v_14611;
    goto v_14302;
v_14304:
v_14302:
    goto v_14324;
v_14320:
    goto v_14321;
v_14322:
    v_14611 = stack[0];
    v_14611 = Lreverse(nil, v_14611);
    env = stack[-11];
    goto v_14323;
v_14324:
    goto v_14320;
v_14321:
    goto v_14322;
v_14323:
    v_14611 = Lnconc(nil, stack[-2], v_14611);
    env = stack[-11];
    stack[-2] = v_14611;
    goto v_14253;
v_14266:
    goto v_14342;
v_14338:
    v_14612 = v_14613;
    goto v_14339;
v_14340:
    v_14611 = elt(env, 2); // true
    goto v_14341;
v_14342:
    goto v_14338;
v_14339:
    goto v_14340;
v_14341:
    if (v_14612 == v_14611) goto v_14336;
    else goto v_14337;
v_14336:
    v_14611 = lisp_true;
    goto v_14335;
v_14337:
    goto v_14352;
v_14348:
    v_14612 = v_14613;
    goto v_14349;
v_14350:
    v_14611 = elt(env, 3); // false
    goto v_14351;
v_14352:
    goto v_14348;
v_14349:
    goto v_14350;
v_14351:
    v_14611 = (v_14612 == v_14611 ? lisp_true : nil);
    goto v_14335;
    v_14611 = nil;
v_14335:
    if (v_14611 == nil) goto v_14333;
    v_14611 = lisp_true;
    goto v_14331;
v_14333:
    goto v_14379;
v_14375:
    v_14612 = v_14613;
    goto v_14376;
v_14377:
    v_14611 = elt(env, 4); // or
    goto v_14378;
v_14379:
    goto v_14375;
v_14376:
    goto v_14377;
v_14378:
    if (v_14612 == v_14611) goto v_14373;
    else goto v_14374;
v_14373:
    v_14611 = lisp_true;
    goto v_14372;
v_14374:
    goto v_14389;
v_14385:
    v_14612 = v_14613;
    goto v_14386;
v_14387:
    v_14611 = elt(env, 5); // and
    goto v_14388;
v_14389:
    goto v_14385;
v_14386:
    goto v_14387;
v_14388:
    v_14611 = (v_14612 == v_14611 ? lisp_true : nil);
    goto v_14372;
    v_14611 = nil;
v_14372:
    if (v_14611 == nil) goto v_14370;
    v_14611 = lisp_true;
    goto v_14368;
v_14370:
    goto v_14400;
v_14396:
    v_14612 = v_14613;
    goto v_14397;
v_14398:
    v_14611 = elt(env, 6); // not
    goto v_14399;
v_14400:
    goto v_14396;
v_14397:
    goto v_14398;
v_14399:
    v_14611 = (v_14612 == v_14611 ? lisp_true : nil);
    goto v_14368;
    v_14611 = nil;
v_14368:
    if (v_14611 == nil) goto v_14366;
    v_14611 = lisp_true;
    goto v_14364;
v_14366:
    goto v_14415;
v_14411:
    v_14612 = v_14613;
    goto v_14412;
v_14413:
    v_14611 = elt(env, 7); // impl
    goto v_14414;
v_14415:
    goto v_14411;
v_14412:
    goto v_14413;
v_14414:
    if (v_14612 == v_14611) goto v_14409;
    else goto v_14410;
v_14409:
    v_14611 = lisp_true;
    goto v_14408;
v_14410:
    goto v_14429;
v_14425:
    v_14612 = v_14613;
    goto v_14426;
v_14427:
    v_14611 = elt(env, 8); // repl
    goto v_14428;
v_14429:
    goto v_14425;
v_14426:
    goto v_14427;
v_14428:
    if (v_14612 == v_14611) goto v_14423;
    else goto v_14424;
v_14423:
    v_14611 = lisp_true;
    goto v_14422;
v_14424:
    goto v_14439;
v_14435:
    v_14612 = v_14613;
    goto v_14436;
v_14437:
    v_14611 = elt(env, 9); // equiv
    goto v_14438;
v_14439:
    goto v_14435;
v_14436:
    goto v_14437;
v_14438:
    v_14611 = (v_14612 == v_14611 ? lisp_true : nil);
    goto v_14422;
    v_14611 = nil;
v_14422:
    goto v_14408;
    v_14611 = nil;
v_14408:
    goto v_14364;
    v_14611 = nil;
v_14364:
    if (v_14611 == nil) goto v_14362;
    v_14611 = lisp_true;
    goto v_14360;
v_14362:
    goto v_14458;
v_14454:
    v_14612 = v_14613;
    goto v_14455;
v_14456:
    v_14611 = elt(env, 10); // ex
    goto v_14457;
v_14458:
    goto v_14454;
v_14455:
    goto v_14456;
v_14457:
    if (v_14612 == v_14611) goto v_14452;
    else goto v_14453;
v_14452:
    v_14611 = lisp_true;
    goto v_14451;
v_14453:
    goto v_14468;
v_14464:
    v_14612 = v_14613;
    goto v_14465;
v_14466:
    v_14611 = elt(env, 11); // all
    goto v_14467;
v_14468:
    goto v_14464;
v_14465:
    goto v_14466;
v_14467:
    v_14611 = (v_14612 == v_14611 ? lisp_true : nil);
    goto v_14451;
    v_14611 = nil;
v_14451:
    if (v_14611 == nil) goto v_14449;
    v_14611 = lisp_true;
    goto v_14447;
v_14449:
    goto v_14487;
v_14483:
    v_14612 = v_14613;
    goto v_14484;
v_14485:
    v_14611 = elt(env, 12); // bex
    goto v_14486;
v_14487:
    goto v_14483;
v_14484:
    goto v_14485;
v_14486:
    if (v_14612 == v_14611) goto v_14481;
    else goto v_14482;
v_14481:
    v_14611 = lisp_true;
    goto v_14480;
v_14482:
    goto v_14497;
v_14493:
    v_14612 = v_14613;
    goto v_14494;
v_14495:
    v_14611 = elt(env, 13); // ball
    goto v_14496;
v_14497:
    goto v_14493;
v_14494:
    goto v_14495;
v_14496:
    v_14611 = (v_14612 == v_14611 ? lisp_true : nil);
    goto v_14480;
    v_14611 = nil;
v_14480:
    if (v_14611 == nil) goto v_14478;
    v_14611 = lisp_true;
    goto v_14476;
v_14478:
    v_14611 = v_14613;
    if (!symbolp(v_14611)) v_14611 = nil;
    else { v_14611 = qfastgets(v_14611);
           if (v_14611 != nil) { v_14611 = elt(v_14611, 21); // rl_external
#ifdef RECORD_GET
             if (v_14611 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_14611 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_14611 == SPID_NOPROP) v_14611 = nil; }}
#endif
    goto v_14476;
    v_14611 = nil;
v_14476:
    goto v_14447;
    v_14611 = nil;
v_14447:
    goto v_14360;
    v_14611 = nil;
v_14360:
    goto v_14331;
    v_14611 = nil;
v_14331:
    if (v_14611 == nil) goto v_14329;
    goto v_14514;
v_14510:
    stack[0] = v_14613;
    goto v_14511;
v_14512:
    v_14611 = stack[-3];
    fn = elt(env, 16); // cl_flip
    v_14611 = (*qfn1(fn))(fn, v_14611);
    env = stack[-11];
    goto v_14513;
v_14514:
    goto v_14510;
v_14511:
    goto v_14512;
v_14513:
    if (equal(stack[0], v_14611)) goto v_14509;
    goto v_14523;
v_14519:
    v_14612 = stack[-10];
    goto v_14520;
v_14521:
    v_14611 = stack[-2];
    goto v_14522;
v_14523:
    goto v_14519;
v_14520:
    goto v_14521;
v_14522:
    v_14611 = cons(v_14612, v_14611);
    env = stack[-11];
    stack[-2] = v_14611;
    goto v_14507;
v_14509:
v_14507:
    goto v_14253;
v_14329:
    v_14611 = qvalue(elt(env, 1)); // !*rlsiidem
    if (v_14611 == nil) goto v_14531;
    goto v_14538;
v_14534:
    v_14611 = stack[-2];
    v_14612 = Lnreverse(nil, v_14611);
    env = stack[-11];
    goto v_14535;
v_14536:
    v_14611 = stack[-7];
    goto v_14537;
v_14538:
    goto v_14534;
v_14535:
    goto v_14536;
v_14537:
    v_14611 = Lnconc(nil, v_14612, v_14611);
    env = stack[-11];
    stack[-7] = v_14611;
    v_14611 = nil;
    stack[-2] = v_14611;
    goto v_14529;
v_14531:
v_14529:
    v_14611 = stack[-10];
    v_14611 = ncons(v_14611);
    env = stack[-11];
    stack[-1] = v_14611;
    goto v_14253;
v_14253:
    v_14611 = stack[-1];
    if (v_14611 == nil) goto v_14548;
    goto v_14559;
v_14551:
    v_14614 = stack[-8];
    goto v_14552;
v_14553:
    v_14613 = stack[-1];
    goto v_14554;
v_14555:
    v_14612 = stack[-5];
    goto v_14556;
v_14557:
    v_14611 = stack[-4];
    goto v_14558;
v_14559:
    goto v_14551;
v_14552:
    goto v_14553;
v_14554:
    goto v_14555;
v_14556:
    goto v_14557;
v_14558:
    fn = elt(env, 17); // rl_smupdknowl
    v_14611 = (*qfnn(fn))(fn, 4, v_14614, v_14613, v_14612, v_14611);
    env = stack[-11];
    stack[-5] = v_14611;
    goto v_14572;
v_14568:
    v_14612 = stack[-5];
    goto v_14569;
v_14570:
    v_14611 = elt(env, 3); // false
    goto v_14571;
v_14572:
    goto v_14568;
v_14569:
    goto v_14570;
v_14571:
    if (v_14612 == v_14611) goto v_14566;
    else goto v_14567;
v_14566:
    v_14611 = stack[-3];
    stack[-9] = v_14611;
    v_14611 = nil;
    stack[-7] = v_14611;
    goto v_14565;
v_14567:
v_14565:
    v_14611 = nil;
    stack[-1] = v_14611;
    goto v_14546;
v_14548:
v_14546:
    goto v_14211;
v_14210:
    goto v_14586;
v_14582:
    v_14612 = stack[-9];
    goto v_14583;
v_14584:
    v_14611 = stack[-3];
    goto v_14585;
v_14586:
    goto v_14582;
v_14583:
    goto v_14584;
v_14585:
    if (v_14612 == v_14611) goto v_14580;
    else goto v_14581;
v_14580:
    v_14611 = stack[-3];
    return ncons(v_14611);
v_14581:
    goto v_14604;
v_14592:
    v_14616 = stack[-8];
    goto v_14593;
v_14594:
    v_14615 = stack[-2];
    goto v_14595;
v_14596:
    v_14614 = stack[-6];
    goto v_14597;
v_14598:
    v_14613 = stack[-5];
    goto v_14599;
v_14600:
    v_14612 = stack[-4];
    goto v_14601;
v_14602:
    v_14611 = stack[-3];
    goto v_14603;
v_14604:
    goto v_14592;
v_14593:
    goto v_14594;
v_14595:
    goto v_14596;
v_14597:
    goto v_14598;
v_14599:
    goto v_14600;
v_14601:
    goto v_14602;
v_14603:
    {
        fn = elt(env, 18); // cl_smsimpl!-junct2
        return (*qfnn(fn))(fn, 6, v_14616, v_14615, v_14614, v_14613, v_14612, v_14611);
    }
    return onevalue(v_14611);
}



// Code for pasf_mkpos

static LispObject CC_pasf_mkpos(LispObject env,
                         LispObject v_14193)
{
    env = qenv(env);
    LispObject v_14331, v_14332;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14193);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_14193;
// end of prologue
    goto v_14214;
v_14210:
    v_14332 = stack[0];
    goto v_14211;
v_14212:
    v_14331 = elt(env, 1); // true
    goto v_14213;
v_14214:
    goto v_14210;
v_14211:
    goto v_14212;
v_14213:
    if (v_14332 == v_14331) goto v_14208;
    else goto v_14209;
v_14208:
    v_14331 = lisp_true;
    goto v_14207;
v_14209:
    goto v_14224;
v_14220:
    v_14332 = stack[0];
    goto v_14221;
v_14222:
    v_14331 = elt(env, 2); // false
    goto v_14223;
v_14224:
    goto v_14220;
v_14221:
    goto v_14222;
v_14223:
    v_14331 = (v_14332 == v_14331 ? lisp_true : nil);
    goto v_14207;
    v_14331 = nil;
v_14207:
    if (v_14331 == nil) goto v_14204;
    else goto v_14205;
v_14204:
    v_14331 = stack[0];
    v_14331 = qcdr(v_14331);
    v_14331 = qcar(v_14331);
    fn = elt(env, 4); // minusf
    v_14331 = (*qfn1(fn))(fn, v_14331);
    env = stack[-3];
    goto v_14203;
v_14205:
    v_14331 = nil;
    goto v_14203;
    v_14331 = nil;
v_14203:
    if (v_14331 == nil) goto v_14201;
    v_14331 = stack[0];
    fn = elt(env, 5); // pasf_anegateat
    v_14331 = (*qfn1(fn))(fn, v_14331);
    env = stack[-3];
    goto v_14199;
v_14201:
    v_14331 = stack[0];
    goto v_14199;
    v_14331 = nil;
v_14199:
    stack[-2] = v_14331;
    v_14331 = stack[-2];
    v_14331 = Lconsp(nil, v_14331);
    env = stack[-3];
    if (v_14331 == nil) goto v_14243;
    v_14331 = stack[-2];
    v_14331 = qcar(v_14331);
    v_14331 = Lconsp(nil, v_14331);
    env = stack[-3];
    if (v_14331 == nil) goto v_14243;
    goto v_14258;
v_14254:
    v_14331 = stack[-2];
    v_14331 = qcar(v_14331);
    v_14332 = qcar(v_14331);
    goto v_14255;
v_14256:
    v_14331 = elt(env, 3); // (cong ncong)
    goto v_14257;
v_14258:
    goto v_14254;
v_14255:
    goto v_14256;
v_14257:
    v_14331 = Lmemq(nil, v_14332, v_14331);
    if (v_14331 == nil) goto v_14243;
    v_14331 = stack[-2];
    v_14331 = qcar(v_14331);
    v_14331 = qcdr(v_14331);
    fn = elt(env, 4); // minusf
    v_14331 = (*qfn1(fn))(fn, v_14331);
    env = stack[-3];
    if (v_14331 == nil) goto v_14243;
    goto v_14276;
v_14270:
    goto v_14289;
v_14285:
    v_14332 = stack[-2];
    goto v_14286;
v_14287:
    v_14331 = elt(env, 1); // true
    goto v_14288;
v_14289:
    goto v_14285;
v_14286:
    goto v_14287;
v_14288:
    if (v_14332 == v_14331) goto v_14283;
    else goto v_14284;
v_14283:
    v_14331 = lisp_true;
    goto v_14282;
v_14284:
    goto v_14299;
v_14295:
    v_14332 = stack[-2];
    goto v_14296;
v_14297:
    v_14331 = elt(env, 2); // false
    goto v_14298;
v_14299:
    goto v_14295;
v_14296:
    goto v_14297;
v_14298:
    v_14331 = (v_14332 == v_14331 ? lisp_true : nil);
    goto v_14282;
    v_14331 = nil;
v_14282:
    if (v_14331 == nil) goto v_14280;
    v_14331 = stack[-2];
    stack[-1] = v_14331;
    goto v_14278;
v_14280:
    v_14331 = stack[-2];
    v_14331 = qcar(v_14331);
    v_14331 = Lconsp(nil, v_14331);
    env = stack[-3];
    if (v_14331 == nil) goto v_14305;
    v_14331 = stack[-2];
    v_14331 = qcar(v_14331);
    v_14331 = qcar(v_14331);
    stack[-1] = v_14331;
    goto v_14278;
v_14305:
    v_14331 = stack[-2];
    v_14331 = qcar(v_14331);
    stack[-1] = v_14331;
    goto v_14278;
    stack[-1] = nil;
v_14278:
    goto v_14271;
v_14272:
    v_14331 = stack[-2];
    v_14331 = qcar(v_14331);
    v_14331 = qcdr(v_14331);
    fn = elt(env, 6); // negf
    stack[0] = (*qfn1(fn))(fn, v_14331);
    env = stack[-3];
    goto v_14273;
v_14274:
    goto v_14325;
v_14321:
    v_14331 = stack[-2];
    v_14331 = qcdr(v_14331);
    v_14332 = qcar(v_14331);
    goto v_14322;
v_14323:
    v_14331 = nil;
    goto v_14324;
v_14325:
    goto v_14321;
v_14322:
    goto v_14323;
v_14324:
    v_14331 = list2(v_14332, v_14331);
    env = stack[-3];
    goto v_14275;
v_14276:
    goto v_14270;
v_14271:
    goto v_14272;
v_14273:
    goto v_14274;
v_14275:
    v_14331 = acons(stack[-1], stack[0], v_14331);
    stack[-2] = v_14331;
    goto v_14241;
v_14243:
v_14241:
    v_14331 = stack[-2];
    return onevalue(v_14331);
}



// Code for ctx_new

static LispObject CC_ctx_new(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_14202, v_14203;
    argcheck(nargs, 0, "ctx_new");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    goto v_14199;
v_14195:
    v_14203 = elt(env, 1); // ctx
    goto v_14196;
v_14197:
    v_14202 = nil;
    goto v_14198;
v_14199:
    goto v_14195;
v_14196:
    goto v_14197;
v_14198:
    return list2(v_14203, v_14202);
}



// Code for bc_zero!?

static LispObject CC_bc_zeroW(LispObject env,
                         LispObject v_14193)
{
    env = qenv(env);
    LispObject v_14198;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14198 = v_14193;
// end of prologue
    v_14198 = qcar(v_14198);
    v_14198 = (v_14198 == nil ? lisp_true : nil);
    return onevalue(v_14198);
}



// Code for binaryrd

static LispObject CC_binaryrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_14212, v_14213, v_14214;
    LispObject fn;
    argcheck(nargs, 0, "binaryrd");
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
    fn = elt(env, 1); // mathml
    v_14212 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_14212;
    fn = elt(env, 1); // mathml
    v_14212 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[0] = v_14212;
    fn = elt(env, 2); // lex
    v_14212 = (*qfnn(fn))(fn, 0);
    goto v_14208;
v_14202:
    v_14214 = stack[-1];
    goto v_14203;
v_14204:
    v_14213 = stack[0];
    goto v_14205;
v_14206:
    v_14212 = nil;
    goto v_14207;
v_14208:
    goto v_14202;
v_14203:
    goto v_14204;
v_14205:
    goto v_14206;
v_14207:
    return list2star(v_14214, v_14213, v_14212);
    return onevalue(v_14212);
}



// Code for gvarlis1

static LispObject CC_gvarlis1(LispObject env,
                         LispObject v_14193, LispObject v_14194)
{
    env = qenv(env);
    LispObject v_14244, v_14245;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_14194,v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_14193,v_14194);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_14194;
    stack[-1] = v_14193;
// end of prologue
    stack[-2] = nil;
v_14200:
    v_14244 = stack[-1];
    if (v_14244 == nil) goto v_14205;
    else goto v_14206;
v_14205:
    goto v_14201;
v_14206:
    goto v_14213;
v_14209:
    goto v_14219;
v_14215:
    v_14244 = stack[-1];
    v_14245 = qcar(v_14244);
    goto v_14216;
v_14217:
    v_14244 = stack[0];
    goto v_14218;
v_14219:
    goto v_14215;
v_14216:
    goto v_14217;
v_14218:
    fn = elt(env, 1); // gvar1
    v_14245 = (*qfn2(fn))(fn, v_14245, v_14244);
    env = stack[-3];
    goto v_14210;
v_14211:
    v_14244 = stack[-2];
    goto v_14212;
v_14213:
    goto v_14209;
v_14210:
    goto v_14211;
v_14212:
    v_14244 = cons(v_14245, v_14244);
    env = stack[-3];
    stack[-2] = v_14244;
    v_14244 = stack[-1];
    v_14244 = qcdr(v_14244);
    stack[-1] = v_14244;
    goto v_14200;
v_14201:
    v_14244 = stack[0];
    v_14245 = v_14244;
v_14202:
    v_14244 = stack[-2];
    if (v_14244 == nil) goto v_14229;
    else goto v_14230;
v_14229:
    v_14244 = v_14245;
    goto v_14199;
v_14230:
    goto v_14238;
v_14234:
    v_14244 = stack[-2];
    v_14244 = qcar(v_14244);
    goto v_14235;
v_14236:
    goto v_14237;
v_14238:
    goto v_14234;
v_14235:
    goto v_14236;
v_14237:
    fn = elt(env, 2); // union
    v_14244 = (*qfn2(fn))(fn, v_14244, v_14245);
    env = stack[-3];
    v_14245 = v_14244;
    v_14244 = stack[-2];
    v_14244 = qcdr(v_14244);
    stack[-2] = v_14244;
    goto v_14202;
v_14199:
    return onevalue(v_14244);
}



// Code for prinlatom

static LispObject CC_prinlatom(LispObject env,
                         LispObject v_14193)
{
    env = qenv(env);
    LispObject v_14262, v_14263;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14193);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_14193;
// end of prologue
    goto v_14209;
v_14205:
    v_14263 = stack[-1];
    goto v_14206;
v_14207:
    v_14262 = elt(env, 1); // font
    goto v_14208;
v_14209:
    goto v_14205;
v_14206:
    goto v_14207;
v_14208:
    v_14262 = get(v_14263, v_14262);
    env = stack[-3];
    stack[-2] = v_14262;
    if (v_14262 == nil) goto v_14203;
    v_14262 = stack[-2];
    fn = elt(env, 5); // prin2la
    v_14262 = (*qfn1(fn))(fn, v_14262);
    env = stack[-3];
    goto v_14201;
v_14203:
v_14201:
    goto v_14223;
v_14219:
    v_14263 = stack[-1];
    goto v_14220;
v_14221:
    v_14262 = elt(env, 2); // accent
    goto v_14222;
v_14223:
    goto v_14219;
v_14220:
    goto v_14221;
v_14222:
    v_14262 = get(v_14263, v_14262);
    env = stack[-3];
    stack[0] = v_14262;
    if (v_14262 == nil) goto v_14217;
    v_14262 = stack[0];
    fn = elt(env, 5); // prin2la
    v_14262 = (*qfn1(fn))(fn, v_14262);
    env = stack[-3];
    goto v_14215;
v_14217:
v_14215:
    goto v_14237;
v_14233:
    v_14263 = stack[-1];
    goto v_14234;
v_14235:
    v_14262 = elt(env, 3); // name
    goto v_14236;
v_14237:
    goto v_14233;
v_14234:
    goto v_14235;
v_14236:
    v_14262 = get(v_14263, v_14262);
    env = stack[-3];
    v_14263 = v_14262;
    if (v_14262 == nil) goto v_14231;
    v_14262 = v_14263;
    fn = elt(env, 5); // prin2la
    v_14262 = (*qfn1(fn))(fn, v_14262);
    env = stack[-3];
    goto v_14229;
v_14231:
    v_14262 = stack[-1];
    fn = elt(env, 6); // testchar1
    v_14262 = (*qfn1(fn))(fn, v_14262);
    env = stack[-3];
    fn = elt(env, 5); // prin2la
    v_14262 = (*qfn1(fn))(fn, v_14262);
    env = stack[-3];
    goto v_14229;
v_14229:
    v_14262 = stack[0];
    if (v_14262 == nil) goto v_14250;
    v_14262 = elt(env, 4); // "}"
    fn = elt(env, 5); // prin2la
    v_14262 = (*qfn1(fn))(fn, v_14262);
    env = stack[-3];
    goto v_14248;
v_14250:
v_14248:
    v_14262 = stack[-2];
    if (v_14262 == nil) goto v_14257;
    v_14262 = elt(env, 4); // "}"
    fn = elt(env, 5); // prin2la
    v_14262 = (*qfn1(fn))(fn, v_14262);
    goto v_14255;
v_14257:
v_14255:
    v_14262 = stack[-1];
    return onevalue(v_14262);
}



// Code for edges_parents

static LispObject CC_edges_parents(LispObject env,
                         LispObject v_14193)
{
    env = qenv(env);
    LispObject v_14217;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_14193);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_14193;
// end of prologue
    v_14217 = stack[0];
    if (v_14217 == nil) goto v_14197;
    else goto v_14198;
v_14197:
    v_14217 = nil;
    goto v_14196;
v_14198:
    v_14217 = stack[0];
    v_14217 = qcar(v_14217);
    fn = elt(env, 1); // edge_new_parents
    v_14217 = (*qfn1(fn))(fn, v_14217);
    env = stack[-2];
    goto v_14212;
v_14208:
    stack[-1] = v_14217;
    goto v_14209;
v_14210:
    v_14217 = stack[0];
    v_14217 = qcdr(v_14217);
    v_14217 = CC_edges_parents(elt(env, 0), v_14217);
    goto v_14211;
v_14212:
    goto v_14208;
v_14209:
    goto v_14210;
v_14211:
    {
        LispObject v_14220 = stack[-1];
        return Lappend(nil, v_14220, v_14217);
    }
    v_14217 = nil;
v_14196:
    return onevalue(v_14217);
}



// Code for assert_check1

static LispObject CC_assert_check1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_14462, v_14463, v_14464, v_14465, v_14466, v_14467;
    LispObject fn;
    LispObject v_14197, v_14196, v_14195, v_14194, v_14193;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "assert_check1");
    va_start(aa, nargs);
    v_14193 = va_arg(aa, LispObject);
    v_14194 = va_arg(aa, LispObject);
    v_14195 = va_arg(aa, LispObject);
    v_14196 = va_arg(aa, LispObject);
    v_14197 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_14197,v_14196,v_14195,v_14194,v_14193);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_14193,v_14194,v_14195,v_14196,v_14197);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-5] = v_14197;
    stack[-6] = v_14196;
    stack[-7] = v_14195;
    stack[-8] = v_14194;
    stack[-9] = v_14193;
// end of prologue
    stack[-4] = nil;
    v_14462 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_14462;
    v_14462 = qvalue(elt(env, 1)); // !*assertstatistics
    if (v_14462 == nil) goto v_14211;
    goto v_14217;
v_14213:
    v_14463 = stack[-9];
    goto v_14214;
v_14215:
    v_14462 = qvalue(elt(env, 2)); // assertstatistics!*
    goto v_14216;
v_14217:
    goto v_14213;
v_14214:
    goto v_14215;
v_14216:
    v_14462 = Latsoc(nil, v_14463, v_14462);
    v_14463 = v_14462;
    v_14462 = v_14463;
    if (v_14462 == nil) goto v_14224;
    goto v_14231;
v_14227:
    v_14462 = v_14463;
    stack[0] = qcdr(v_14462);
    goto v_14228;
v_14229:
    v_14462 = v_14463;
    v_14462 = qcdr(v_14462);
    v_14462 = qcar(v_14462);
    v_14462 = add1(v_14462);
    env = stack[-11];
    goto v_14230;
v_14231:
    goto v_14227;
v_14228:
    goto v_14229;
v_14230:
    fn = elt(env, 5); // setcar
    v_14462 = (*qfn2(fn))(fn, stack[0], v_14462);
    env = stack[-11];
    goto v_14222;
v_14224:
    goto v_14247;
v_14241:
    stack[0] = stack[-9];
    goto v_14242;
v_14243:
    goto v_14256;
v_14250:
    v_14464 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_14251;
v_14252:
    v_14463 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14253;
v_14254:
    v_14462 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14255;
v_14256:
    goto v_14250;
v_14251:
    goto v_14252;
v_14253:
    goto v_14254;
v_14255:
    v_14463 = list3(v_14464, v_14463, v_14462);
    env = stack[-11];
    goto v_14244;
v_14245:
    v_14462 = qvalue(elt(env, 2)); // assertstatistics!*
    goto v_14246;
v_14247:
    goto v_14241;
v_14242:
    goto v_14243;
v_14244:
    goto v_14245;
v_14246:
    v_14462 = acons(stack[0], v_14463, v_14462);
    env = stack[-11];
    qvalue(elt(env, 2)) = v_14462; // assertstatistics!*
    goto v_14222;
v_14222:
    goto v_14209;
v_14211:
v_14209:
    v_14462 = stack[-6];
    stack[-10] = v_14462;
    v_14462 = stack[-7];
    stack[-2] = v_14462;
v_14265:
    v_14462 = stack[-2];
    if (v_14462 == nil) goto v_14269;
    else goto v_14270;
v_14269:
    goto v_14264;
v_14270:
    v_14462 = stack[-2];
    v_14462 = qcar(v_14462);
    stack[-1] = v_14462;
    v_14462 = stack[-3];
    v_14462 = add1(v_14462);
    env = stack[-11];
    stack[-3] = v_14462;
    goto v_14288;
v_14284:
    v_14462 = stack[-10];
    v_14463 = qcar(v_14462);
    goto v_14285;
v_14286:
    v_14462 = elt(env, 3); // assert_dyntypechk
    goto v_14287;
v_14288:
    goto v_14284;
v_14285:
    goto v_14286;
v_14287:
    v_14462 = get(v_14463, v_14462);
    env = stack[-11];
    v_14463 = v_14462;
    if (v_14462 == nil) goto v_14281;
    goto v_14302;
v_14298:
    stack[0] = v_14463;
    goto v_14299;
v_14300:
    v_14462 = stack[-1];
    v_14462 = ncons(v_14462);
    env = stack[-11];
    goto v_14301;
v_14302:
    goto v_14298;
v_14299:
    goto v_14300;
v_14301:
    fn = elt(env, 6); // apply
    v_14462 = (*qfn2(fn))(fn, stack[0], v_14462);
    env = stack[-11];
    if (v_14462 == nil) goto v_14295;
    else goto v_14296;
v_14295:
    v_14462 = stack[-1];
    v_14462 = Lconsp(nil, v_14462);
    env = stack[-11];
    if (v_14462 == nil) goto v_14308;
    else goto v_14309;
v_14308:
    v_14462 = nil;
    goto v_14307;
v_14309:
    goto v_14320;
v_14316:
    v_14462 = stack[-1];
    v_14463 = qcar(v_14462);
    goto v_14317;
v_14318:
    v_14462 = elt(env, 4); // assert_ignore
    goto v_14319;
v_14320:
    goto v_14316;
v_14317:
    goto v_14318;
v_14319:
    v_14462 = Lflagp(nil, v_14463, v_14462);
    env = stack[-11];
    goto v_14307;
    v_14462 = nil;
v_14307:
    v_14462 = (v_14462 == nil ? lisp_true : nil);
    goto v_14294;
v_14296:
    v_14462 = nil;
    goto v_14294;
    v_14462 = nil;
v_14294:
    if (v_14462 == nil) goto v_14281;
    v_14462 = lisp_true;
    stack[-4] = v_14462;
    goto v_14342;
v_14330:
    v_14467 = stack[-9];
    goto v_14331;
v_14332:
    v_14466 = stack[-6];
    goto v_14333;
v_14334:
    v_14465 = stack[-5];
    goto v_14335;
v_14336:
    v_14464 = stack[-3];
    goto v_14337;
v_14338:
    v_14462 = stack[-10];
    v_14463 = qcar(v_14462);
    goto v_14339;
v_14340:
    v_14462 = stack[-1];
    goto v_14341;
v_14342:
    goto v_14330;
v_14331:
    goto v_14332;
v_14333:
    goto v_14334;
v_14335:
    goto v_14336;
v_14337:
    goto v_14338;
v_14339:
    goto v_14340;
v_14341:
    fn = elt(env, 7); // assert_error
    v_14462 = (*qfnn(fn))(fn, 6, v_14467, v_14466, v_14465, v_14464, v_14463, v_14462);
    env = stack[-11];
    goto v_14279;
v_14281:
v_14279:
    v_14462 = stack[-10];
    v_14462 = qcdr(v_14462);
    stack[-10] = v_14462;
    v_14462 = stack[-2];
    v_14462 = qcdr(v_14462);
    stack[-2] = v_14462;
    goto v_14265;
v_14264:
    goto v_14359;
v_14355:
    v_14463 = stack[-8];
    goto v_14356;
v_14357:
    v_14462 = stack[-7];
    goto v_14358;
v_14359:
    goto v_14355;
v_14356:
    goto v_14357;
v_14358:
    fn = elt(env, 6); // apply
    v_14462 = (*qfn2(fn))(fn, v_14463, v_14462);
    env = stack[-11];
    stack[-1] = v_14462;
    goto v_14372;
v_14368:
    v_14463 = stack[-5];
    goto v_14369;
v_14370:
    v_14462 = elt(env, 3); // assert_dyntypechk
    goto v_14371;
v_14372:
    goto v_14368;
v_14369:
    goto v_14370;
v_14371:
    v_14462 = get(v_14463, v_14462);
    env = stack[-11];
    v_14463 = v_14462;
    if (v_14462 == nil) goto v_14365;
    goto v_14385;
v_14381:
    stack[0] = v_14463;
    goto v_14382;
v_14383:
    v_14462 = stack[-1];
    v_14462 = ncons(v_14462);
    env = stack[-11];
    goto v_14384;
v_14385:
    goto v_14381;
v_14382:
    goto v_14383;
v_14384:
    fn = elt(env, 6); // apply
    v_14462 = (*qfn2(fn))(fn, stack[0], v_14462);
    env = stack[-11];
    if (v_14462 == nil) goto v_14378;
    else goto v_14379;
v_14378:
    v_14462 = stack[-1];
    v_14462 = Lconsp(nil, v_14462);
    env = stack[-11];
    if (v_14462 == nil) goto v_14391;
    else goto v_14392;
v_14391:
    v_14462 = nil;
    goto v_14390;
v_14392:
    goto v_14403;
v_14399:
    v_14462 = stack[-1];
    v_14463 = qcar(v_14462);
    goto v_14400;
v_14401:
    v_14462 = elt(env, 4); // assert_ignore
    goto v_14402;
v_14403:
    goto v_14399;
v_14400:
    goto v_14401;
v_14402:
    v_14462 = Lflagp(nil, v_14463, v_14462);
    env = stack[-11];
    goto v_14390;
    v_14462 = nil;
v_14390:
    v_14462 = (v_14462 == nil ? lisp_true : nil);
    goto v_14377;
v_14379:
    v_14462 = nil;
    goto v_14377;
    v_14462 = nil;
v_14377:
    if (v_14462 == nil) goto v_14365;
    v_14462 = lisp_true;
    stack[-4] = v_14462;
    goto v_14425;
v_14413:
    v_14467 = stack[-9];
    goto v_14414;
v_14415:
    v_14466 = stack[-6];
    goto v_14416;
v_14417:
    v_14465 = stack[-5];
    goto v_14418;
v_14419:
    v_14464 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_14420;
v_14421:
    v_14463 = stack[-5];
    goto v_14422;
v_14423:
    v_14462 = stack[-1];
    goto v_14424;
v_14425:
    goto v_14413;
v_14414:
    goto v_14415;
v_14416:
    goto v_14417;
v_14418:
    goto v_14419;
v_14420:
    goto v_14421;
v_14422:
    goto v_14423;
v_14424:
    fn = elt(env, 7); // assert_error
    v_14462 = (*qfnn(fn))(fn, 6, v_14467, v_14466, v_14465, v_14464, v_14463, v_14462);
    env = stack[-11];
    goto v_14363;
v_14365:
v_14363:
    v_14462 = qvalue(elt(env, 1)); // !*assertstatistics
    if (v_14462 == nil) goto v_14435;
    v_14462 = stack[-4];
    if (v_14462 == nil) goto v_14435;
    goto v_14444;
v_14440:
    v_14463 = stack[-9];
    goto v_14441;
v_14442:
    v_14462 = qvalue(elt(env, 2)); // assertstatistics!*
    goto v_14443;
v_14444:
    goto v_14440;
v_14441:
    goto v_14442;
v_14443:
    v_14462 = Latsoc(nil, v_14463, v_14462);
    v_14462 = qcdr(v_14462);
    v_14463 = v_14462;
    goto v_14454;
v_14450:
    v_14462 = v_14463;
    stack[0] = qcdr(v_14462);
    goto v_14451;
v_14452:
    v_14462 = v_14463;
    v_14462 = qcdr(v_14462);
    v_14462 = qcar(v_14462);
    v_14462 = add1(v_14462);
    env = stack[-11];
    goto v_14453;
v_14454:
    goto v_14450;
v_14451:
    goto v_14452;
v_14453:
    fn = elt(env, 5); // setcar
    v_14462 = (*qfn2(fn))(fn, stack[0], v_14462);
    goto v_14433;
v_14435:
v_14433:
    v_14462 = stack[-1];
    return onevalue(v_14462);
}



setup_type const u25_setup[] =
{
    {"physopsimp",              CC_physopsimp,  TOO_MANY_1,    WRONG_NO_1},
    {"ev-denom2",               TOO_FEW_2,      CC_evKdenom2,  WRONG_NO_2},
    {"impartf",                 CC_impartf,     TOO_MANY_1,    WRONG_NO_1},
    {"endstat",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_endstat},
    {"red_topredbe",            TOO_FEW_2,      CC_red_topredbe,WRONG_NO_2},
    {"pa_coinc_split",          TOO_FEW_2,      CC_pa_coinc_split,WRONG_NO_2},
    {"lambda_er1ez819f9yx2",    TOO_FEW_2,      CC_lambda_er1ez819f9yx2,WRONG_NO_2},
    {"safe-modrecip",           CC_safeKmodrecip,TOO_MANY_1,   WRONG_NO_1},
    {"cde_position",            TOO_FEW_2,      CC_cde_position,WRONG_NO_2},
    {"sfto_int2sf",             CC_sfto_int2sf, TOO_MANY_1,    WRONG_NO_1},
    {"gettype",                 CC_gettype,     TOO_MANY_1,    WRONG_NO_1},
    {"evaluatecoeffts",         TOO_FEW_2,      CC_evaluatecoeffts,WRONG_NO_2},
    {"expnd",                   CC_expnd,       TOO_MANY_1,    WRONG_NO_1},
    {"lto_alunion",             CC_lto_alunion, TOO_MANY_1,    WRONG_NO_1},
    {"mri_prepat",              CC_mri_prepat,  TOO_MANY_1,    WRONG_NO_1},
    {"pasf_vf",                 CC_pasf_vf,     TOO_MANY_1,    WRONG_NO_1},
    {"dip_fmon",                TOO_FEW_2,      CC_dip_fmon,   WRONG_NO_2},
    {"mml2ir",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mml2ir},
    {"mkmatrix",                TOO_FEW_2,      CC_mkmatrix,   WRONG_NO_2},
    {"dipev2f",                 TOO_FEW_2,      CC_dipev2f,    WRONG_NO_2},
    {"bcneg",                   CC_bcneg,       TOO_MANY_1,    WRONG_NO_1},
    {"formc*",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formcH},
    {"r2findindex",             TOO_FEW_2,      CC_r2findindex,WRONG_NO_2},
    {":dmpluslst",              CC_Tdmpluslst,  TOO_MANY_1,    WRONG_NO_1},
    {"physopordchk",            TOO_FEW_2,      CC_physopordchk,WRONG_NO_2},
    {"copy-tree",               CC_copyKtree,   TOO_MANY_1,    WRONG_NO_1},
    {"setdiff_according_to",    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setdiff_according_to},
    {"setk_super_vectorfield",  TOO_FEW_2,      CC_setk_super_vectorfield,WRONG_NO_2},
    {"lalr_construct_fn",       TOO_FEW_2,      CC_lalr_construct_fn,WRONG_NO_2},
    {"add2locs",                CC_add2locs,    TOO_MANY_1,    WRONG_NO_1},
    {"cl_f2ml",                 TOO_FEW_2,      CC_cl_f2ml,    WRONG_NO_2},
    {"texstrlen",               CC_texstrlen,   TOO_MANY_1,    WRONG_NO_1},
    {"cl_smsimpl-junct1",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_smsimplKjunct1},
    {"pasf_mkpos",              CC_pasf_mkpos,  TOO_MANY_1,    WRONG_NO_1},
    {"ctx_new",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ctx_new},
    {"bc_zero?",                CC_bc_zeroW,    TOO_MANY_1,    WRONG_NO_1},
    {"binaryrd",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_binaryrd},
    {"gvarlis1",                TOO_FEW_2,      CC_gvarlis1,   WRONG_NO_2},
    {"prinlatom",               CC_prinlatom,   TOO_MANY_1,    WRONG_NO_1},
    {"edges_parents",           CC_edges_parents,TOO_MANY_1,   WRONG_NO_1},
    {"assert_check1",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_assert_check1},
    {NULL, (one_args *)"u25", (two_args *)"168832 6325959 9456831", 0}
};

// end of generated code
