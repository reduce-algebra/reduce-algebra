
// $destdir/u23.c        Machine generated C code

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



// Code for ibalp_var!-set

static LispObject CC_ibalp_varKset(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13374, v_13375;
    LispObject fn;
    LispObject v_13242, v_13241, v_13240, v_13239;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ibalp_var-set");
    va_start(aa, nargs);
    v_13239 = va_arg(aa, LispObject);
    v_13240 = va_arg(aa, LispObject);
    v_13241 = va_arg(aa, LispObject);
    v_13242 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_13242,v_13241,v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_13239,v_13240,v_13241,v_13242);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_13242;
    stack[-1] = v_13241;
    stack[-2] = v_13240;
    stack[-3] = v_13239;
// end of prologue
    goto v_13254;
v_13250:
    v_13374 = stack[-3];
    v_13375 = qcdr(v_13374);
    goto v_13251;
v_13252:
    v_13374 = stack[-2];
    goto v_13253;
v_13254:
    goto v_13250;
v_13251:
    goto v_13252;
v_13253:
    fn = elt(env, 1); // setcar
    v_13374 = (*qfn2(fn))(fn, v_13375, v_13374);
    env = stack[-4];
    goto v_13263;
v_13259:
    v_13374 = stack[-3];
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13375 = qcdr(v_13374);
    goto v_13260;
v_13261:
    v_13374 = stack[-1];
    goto v_13262;
v_13263:
    goto v_13259;
v_13260:
    goto v_13261;
v_13262:
    fn = elt(env, 1); // setcar
    v_13374 = (*qfn2(fn))(fn, v_13375, v_13374);
    env = stack[-4];
    goto v_13277;
v_13273:
    v_13374 = stack[-3];
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13375 = qcdr(v_13374);
    goto v_13274;
v_13275:
    v_13374 = stack[0];
    goto v_13276;
v_13277:
    goto v_13273;
v_13274:
    goto v_13275;
v_13276:
    fn = elt(env, 1); // setcar
    v_13374 = (*qfn2(fn))(fn, v_13375, v_13374);
    env = stack[-4];
    v_13374 = stack[-3];
    v_13374 = qcar(v_13374);
    stack[0] = v_13374;
    goto v_13298;
v_13294:
    v_13375 = stack[-2];
    goto v_13295;
v_13296:
    v_13374 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13297;
v_13298:
    goto v_13294;
v_13295:
    goto v_13296;
v_13297:
    v_13374 = Leqn(nil, v_13375, v_13374);
    env = stack[-4];
    if (v_13374 == nil) goto v_13292;
    v_13374 = stack[-3];
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcar(v_13374);
    goto v_13290;
v_13292:
    v_13374 = stack[-3];
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcar(v_13374);
    goto v_13290;
    v_13374 = nil;
v_13290:
    goto v_13317;
v_13313:
    v_13375 = v_13374;
    goto v_13314;
v_13315:
    v_13374 = stack[0];
    goto v_13316;
v_13317:
    goto v_13313;
v_13314:
    goto v_13315;
v_13316:
    fn = elt(env, 2); // ibalp_var!-satlist
    v_13374 = (*qfn2(fn))(fn, v_13375, v_13374);
    env = stack[-4];
    goto v_13329;
v_13325:
    v_13375 = stack[-2];
    goto v_13326;
v_13327:
    v_13374 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13328;
v_13329:
    goto v_13325;
v_13326:
    goto v_13327;
v_13328:
    v_13374 = Leqn(nil, v_13375, v_13374);
    env = stack[-4];
    if (v_13374 == nil) goto v_13323;
    v_13374 = stack[-3];
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcar(v_13374);
    goto v_13321;
v_13323:
    v_13374 = stack[-3];
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcar(v_13374);
    goto v_13321;
    v_13374 = nil;
v_13321:
    goto v_13348;
v_13344:
    v_13375 = v_13374;
    goto v_13345;
v_13346:
    v_13374 = stack[-2];
    goto v_13347;
v_13348:
    goto v_13344;
v_13345:
    goto v_13346;
v_13347:
    fn = elt(env, 3); // ibalp_var!-unsatlist
    v_13374 = (*qfn2(fn))(fn, v_13375, v_13374);
    env = stack[-4];
    v_13374 = stack[-3];
    fn = elt(env, 4); // ibalp_var!-wclist
    v_13374 = (*qfn1(fn))(fn, v_13374);
    env = stack[-4];
    stack[-1] = v_13374;
    goto v_13358;
v_13354:
    v_13374 = stack[-3];
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    v_13374 = qcdr(v_13374);
    stack[0] = qcdr(v_13374);
    goto v_13355;
v_13356:
    v_13374 = stack[-3];
    fn = elt(env, 5); // ibalp_calcmom
    v_13374 = (*qfn1(fn))(fn, v_13374);
    env = stack[-4];
    goto v_13357;
v_13358:
    goto v_13354;
v_13355:
    goto v_13356;
v_13357:
    fn = elt(env, 1); // setcar
    v_13374 = (*qfn2(fn))(fn, stack[0], v_13374);
    v_13374 = stack[-1];
    return onevalue(v_13374);
}



// Code for inttovec1

static LispObject CC_inttovec1(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13294, v_13295;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13239,v_13240);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13240;
    stack[-1] = v_13239;
// end of prologue
    goto v_13250;
v_13246:
    v_13295 = stack[-1];
    goto v_13247;
v_13248:
    v_13294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13249;
v_13250:
    goto v_13246;
v_13247:
    goto v_13248;
v_13249:
    if (v_13295 == v_13294) goto v_13244;
    else goto v_13245;
v_13244:
    v_13294 = stack[0];
    v_13294 = qcar(v_13294);
    return ncons(v_13294);
v_13245:
    goto v_13263;
v_13259:
    v_13294 = stack[-1];
    v_13295 = sub1(v_13294);
    env = stack[-3];
    goto v_13260;
v_13261:
    v_13294 = stack[0];
    v_13294 = qcdr(v_13294);
    goto v_13262;
v_13263:
    goto v_13259;
v_13260:
    goto v_13261;
v_13262:
    fn = elt(env, 1); // inttovec!-solve
    v_13294 = (*qfn2(fn))(fn, v_13295, v_13294);
    env = stack[-3];
    stack[-2] = v_13294;
    goto v_13274;
v_13270:
    goto v_13280;
v_13276:
    v_13294 = stack[0];
    v_13295 = qcar(v_13294);
    goto v_13277;
v_13278:
    v_13294 = stack[-2];
    v_13294 = qcar(v_13294);
    goto v_13279;
v_13280:
    goto v_13276;
v_13277:
    goto v_13278;
v_13279:
    stack[0] = difference2(v_13295, v_13294);
    env = stack[-3];
    goto v_13271;
v_13272:
    goto v_13290;
v_13286:
    v_13294 = stack[-1];
    v_13295 = sub1(v_13294);
    env = stack[-3];
    goto v_13287;
v_13288:
    v_13294 = stack[-2];
    goto v_13289;
v_13290:
    goto v_13286;
v_13287:
    goto v_13288;
v_13289:
    v_13294 = CC_inttovec1(elt(env, 0), v_13295, v_13294);
    goto v_13273;
v_13274:
    goto v_13270;
v_13271:
    goto v_13272;
v_13273:
    {
        LispObject v_13299 = stack[0];
        return cons(v_13299, v_13294);
    }
    v_13294 = nil;
    return onevalue(v_13294);
}



// Code for collectphystype

static LispObject CC_collectphystype(LispObject env,
                         LispObject v_13239)
{
    env = qenv(env);
    LispObject v_13299;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13239);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_13239;
// end of prologue
    v_13299 = stack[0];
    fn = elt(env, 1); // physopp
    v_13299 = (*qfn1(fn))(fn, v_13299);
    env = stack[-4];
    if (v_13299 == nil) goto v_13244;
    v_13299 = stack[0];
    fn = elt(env, 2); // getphystype
    v_13299 = (*qfn1(fn))(fn, v_13299);
    return ncons(v_13299);
v_13244:
    v_13299 = stack[0];
    if (!consp(v_13299)) goto v_13250;
    else goto v_13251;
v_13250:
    v_13299 = nil;
    goto v_13242;
v_13251:
    v_13299 = stack[0];
    stack[-3] = v_13299;
    v_13299 = stack[-3];
    if (v_13299 == nil) goto v_13266;
    else goto v_13267;
v_13266:
    v_13299 = nil;
    goto v_13261;
v_13267:
    v_13299 = stack[-3];
    v_13299 = qcar(v_13299);
    fn = elt(env, 2); // getphystype
    v_13299 = (*qfn1(fn))(fn, v_13299);
    env = stack[-4];
    v_13299 = ncons(v_13299);
    env = stack[-4];
    stack[-1] = v_13299;
    stack[-2] = v_13299;
v_13262:
    v_13299 = stack[-3];
    v_13299 = qcdr(v_13299);
    stack[-3] = v_13299;
    v_13299 = stack[-3];
    if (v_13299 == nil) goto v_13280;
    else goto v_13281;
v_13280:
    v_13299 = stack[-2];
    goto v_13261;
v_13281:
    goto v_13289;
v_13285:
    stack[0] = stack[-1];
    goto v_13286;
v_13287:
    v_13299 = stack[-3];
    v_13299 = qcar(v_13299);
    fn = elt(env, 2); // getphystype
    v_13299 = (*qfn1(fn))(fn, v_13299);
    env = stack[-4];
    v_13299 = ncons(v_13299);
    env = stack[-4];
    goto v_13288;
v_13289:
    goto v_13285;
v_13286:
    goto v_13287;
v_13288:
    v_13299 = Lrplacd(nil, stack[0], v_13299);
    env = stack[-4];
    v_13299 = stack[-1];
    v_13299 = qcdr(v_13299);
    stack[-1] = v_13299;
    goto v_13262;
v_13261:
    {
        fn = elt(env, 3); // deletemult!*
        return (*qfn1(fn))(fn, v_13299);
    }
    v_13299 = nil;
v_13242:
    return onevalue(v_13299);
}



// Code for replace1_parents

static LispObject CC_replace1_parents(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13258, v_13259, v_13260;
    LispObject fn;
    LispObject v_13241, v_13240, v_13239;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "replace1_parents");
    va_start(aa, nargs);
    v_13239 = va_arg(aa, LispObject);
    v_13240 = va_arg(aa, LispObject);
    v_13241 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13258 = v_13241;
    v_13259 = v_13240;
    v_13260 = v_13239;
// end of prologue
    goto v_13250;
v_13244:
    v_13260 = qcar(v_13260);
    goto v_13245;
v_13246:
    v_13259 = qcar(v_13259);
    goto v_13247;
v_13248:
    v_13258 = qcdr(v_13258);
    v_13258 = qcar(v_13258);
    goto v_13249;
v_13250:
    goto v_13244;
v_13245:
    goto v_13246;
v_13247:
    goto v_13248;
v_13249:
    {
        fn = elt(env, 1); // replace2_parents
        return (*qfnn(fn))(fn, 3, v_13260, v_13259, v_13258);
    }
}



// Code for repartf

static LispObject CC_repartf(LispObject env,
                         LispObject v_13239)
{
    env = qenv(env);
    LispObject v_13361, v_13362;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13239);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_13239;
// end of prologue
    goto v_13246;
v_13242:
    v_13362 = elt(env, 1); // i
    goto v_13243;
v_13244:
    v_13361 = qvalue(elt(env, 2)); // kord!*
    goto v_13245;
v_13246:
    goto v_13242;
v_13243:
    goto v_13244;
v_13245:
    v_13361 = cons(v_13362, v_13361);
    env = stack[-4];
// Binding kord!*
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 2, -3);
    qvalue(elt(env, 2)) = v_13361; // kord!*
    v_13361 = stack[0];
    fn = elt(env, 4); // reorder
    v_13361 = (*qfn1(fn))(fn, v_13361);
    env = stack[-4];
    stack[-2] = v_13361;
    v_13361 = stack[-2];
    if (!consp(v_13361)) goto v_13259;
    else goto v_13260;
v_13259:
    v_13361 = lisp_true;
    goto v_13258;
v_13260:
    v_13361 = stack[-2];
    v_13361 = qcar(v_13361);
    v_13361 = (consp(v_13361) ? nil : lisp_true);
    goto v_13258;
    v_13361 = nil;
v_13258:
    if (v_13361 == nil) goto v_13256;
    v_13361 = stack[-2];
    if (!consp(v_13361)) goto v_13270;
    else goto v_13271;
v_13270:
    v_13361 = stack[-2];
    goto v_13269;
v_13271:
    goto v_13281;
v_13277:
    v_13361 = stack[-2];
    v_13362 = qcar(v_13361);
    goto v_13278;
v_13279:
    v_13361 = elt(env, 3); // cmpxfn
    goto v_13280;
v_13281:
    goto v_13277;
v_13278:
    goto v_13279;
v_13280:
    v_13361 = get(v_13362, v_13361);
    env = stack[-4];
    if (v_13361 == nil) goto v_13275;
    goto v_13293;
v_13287:
    v_13361 = stack[-2];
    stack[-1] = qcar(v_13361);
    goto v_13288;
v_13289:
    v_13361 = stack[-2];
    v_13361 = qcdr(v_13361);
    stack[0] = qcar(v_13361);
    goto v_13290;
v_13291:
    goto v_13304;
v_13300:
    v_13361 = stack[-2];
    v_13361 = qcar(v_13361);
    if (!symbolp(v_13361)) v_13362 = nil;
    else { v_13362 = qfastgets(v_13361);
           if (v_13362 != nil) { v_13362 = elt(v_13362, 34); // i2d
#ifdef RECORD_GET
             if (v_13362 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_13362 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_13362 == SPID_NOPROP) v_13362 = nil; }}
#endif
    goto v_13301;
v_13302:
    v_13361 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13303;
v_13304:
    goto v_13300;
v_13301:
    goto v_13302;
v_13303:
    v_13361 = Lapply1(nil, v_13362, v_13361);
    env = stack[-4];
    v_13361 = qcdr(v_13361);
    v_13361 = qcar(v_13361);
    goto v_13292;
v_13293:
    goto v_13287;
v_13288:
    goto v_13289;
v_13290:
    goto v_13291;
v_13292:
    v_13361 = list2star(stack[-1], stack[0], v_13361);
    env = stack[-4];
    fn = elt(env, 5); // int!-equiv!-chk
    v_13361 = (*qfn1(fn))(fn, v_13361);
    goto v_13269;
v_13275:
    v_13361 = stack[-2];
    goto v_13269;
    v_13361 = nil;
v_13269:
    goto v_13254;
v_13256:
    goto v_13320;
v_13316:
    v_13361 = stack[-2];
    v_13361 = qcar(v_13361);
    v_13361 = qcar(v_13361);
    v_13362 = qcar(v_13361);
    goto v_13317;
v_13318:
    v_13361 = elt(env, 1); // i
    goto v_13319;
v_13320:
    goto v_13316;
v_13317:
    goto v_13318;
v_13319:
    if (v_13362 == v_13361) goto v_13314;
    else goto v_13315;
v_13314:
    v_13361 = stack[-2];
    v_13361 = qcdr(v_13361);
    v_13361 = CC_repartf(elt(env, 0), v_13361);
    goto v_13254;
v_13315:
    goto v_13336;
v_13332:
    goto v_13342;
v_13338:
    goto v_13349;
v_13345:
    v_13361 = stack[-2];
    v_13361 = qcar(v_13361);
    v_13362 = qcar(v_13361);
    goto v_13346;
v_13347:
    v_13361 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13348;
v_13349:
    goto v_13345;
v_13346:
    goto v_13347;
v_13348:
    v_13361 = cons(v_13362, v_13361);
    env = stack[-4];
    stack[0] = ncons(v_13361);
    env = stack[-4];
    goto v_13339;
v_13340:
    v_13361 = stack[-2];
    v_13361 = qcar(v_13361);
    v_13361 = qcdr(v_13361);
    v_13361 = CC_repartf(elt(env, 0), v_13361);
    env = stack[-4];
    goto v_13341;
v_13342:
    goto v_13338;
v_13339:
    goto v_13340;
v_13341:
    fn = elt(env, 6); // multf
    stack[0] = (*qfn2(fn))(fn, stack[0], v_13361);
    env = stack[-4];
    goto v_13333;
v_13334:
    v_13361 = stack[-2];
    v_13361 = qcdr(v_13361);
    v_13361 = CC_repartf(elt(env, 0), v_13361);
    env = stack[-4];
    goto v_13335;
v_13336:
    goto v_13332;
v_13333:
    goto v_13334;
v_13335:
    fn = elt(env, 7); // addf
    v_13361 = (*qfn2(fn))(fn, stack[0], v_13361);
    goto v_13254;
    v_13361 = nil;
v_13254:
    ;}  // end of a binding scope
    return onevalue(v_13361);
}



// Code for setelv

static LispObject CC_setelv(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13300, v_13301;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13239,v_13240);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_13240;
    v_13301 = v_13239;
// end of prologue
    goto v_13247;
v_13243:
    goto v_13253;
v_13249:
    v_13300 = v_13301;
    stack[-5] = qcar(v_13300);
    goto v_13250;
v_13251:
    v_13300 = v_13301;
    v_13300 = qcdr(v_13300);
    stack[-3] = v_13300;
    v_13300 = stack[-3];
    if (v_13300 == nil) goto v_13266;
    else goto v_13267;
v_13266:
    v_13300 = nil;
    goto v_13260;
v_13267:
    v_13300 = stack[-3];
    v_13300 = qcar(v_13300);
    fn = elt(env, 1); // reval_without_mod
    v_13300 = (*qfn1(fn))(fn, v_13300);
    env = stack[-6];
    v_13300 = ncons(v_13300);
    env = stack[-6];
    stack[-1] = v_13300;
    stack[-2] = v_13300;
v_13261:
    v_13300 = stack[-3];
    v_13300 = qcdr(v_13300);
    stack[-3] = v_13300;
    v_13300 = stack[-3];
    if (v_13300 == nil) goto v_13280;
    else goto v_13281;
v_13280:
    v_13300 = stack[-2];
    goto v_13260;
v_13281:
    goto v_13289;
v_13285:
    stack[0] = stack[-1];
    goto v_13286;
v_13287:
    v_13300 = stack[-3];
    v_13300 = qcar(v_13300);
    fn = elt(env, 1); // reval_without_mod
    v_13300 = (*qfn1(fn))(fn, v_13300);
    env = stack[-6];
    v_13300 = ncons(v_13300);
    env = stack[-6];
    goto v_13288;
v_13289:
    goto v_13285;
v_13286:
    goto v_13287;
v_13288:
    v_13300 = Lrplacd(nil, stack[0], v_13300);
    env = stack[-6];
    v_13300 = stack[-1];
    v_13300 = qcdr(v_13300);
    stack[-1] = v_13300;
    goto v_13261;
v_13260:
    goto v_13252;
v_13253:
    goto v_13249;
v_13250:
    goto v_13251;
v_13252:
    v_13301 = cons(stack[-5], v_13300);
    env = stack[-6];
    goto v_13244;
v_13245:
    v_13300 = stack[-4];
    goto v_13246;
v_13247:
    goto v_13243;
v_13244:
    goto v_13245;
v_13246:
    {
        fn = elt(env, 2); // setel
        return (*qfn2(fn))(fn, v_13301, v_13300);
    }
}



// Code for red!=cancelsimp

static LispObject CC_redMcancelsimp(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13269, v_13270;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13239,v_13240);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13240;
    stack[-1] = v_13239;
// end of prologue
    goto v_13251;
v_13247:
    v_13270 = stack[-1];
    goto v_13248;
v_13249:
    v_13269 = stack[0];
    goto v_13250;
v_13251:
    goto v_13247;
v_13248:
    goto v_13249;
v_13250:
    fn = elt(env, 1); // red_better
    v_13269 = (*qfn2(fn))(fn, v_13270, v_13269);
    env = stack[-2];
    if (v_13269 == nil) goto v_13244;
    else goto v_13245;
v_13244:
    v_13269 = nil;
    goto v_13243;
v_13245:
    goto v_13262;
v_13258:
    v_13269 = stack[-1];
    fn = elt(env, 2); // bas_dpoly
    v_13269 = (*qfn1(fn))(fn, v_13269);
    env = stack[-2];
    fn = elt(env, 3); // dp_lmon
    stack[-1] = (*qfn1(fn))(fn, v_13269);
    env = stack[-2];
    goto v_13259;
v_13260:
    v_13269 = stack[0];
    fn = elt(env, 2); // bas_dpoly
    v_13269 = (*qfn1(fn))(fn, v_13269);
    env = stack[-2];
    fn = elt(env, 3); // dp_lmon
    v_13269 = (*qfn1(fn))(fn, v_13269);
    env = stack[-2];
    goto v_13261;
v_13262:
    goto v_13258;
v_13259:
    goto v_13260;
v_13261:
    {
        LispObject v_13273 = stack[-1];
        fn = elt(env, 4); // mo_vdivides!?
        return (*qfn2(fn))(fn, v_13273, v_13269);
    }
    v_13269 = nil;
v_13243:
    return onevalue(v_13269);
}



// Code for pst_termnodep

static LispObject CC_pst_termnodep(LispObject env,
                         LispObject v_13239)
{
    env = qenv(env);
    LispObject v_13252, v_13253;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13252 = v_13239;
// end of prologue
    goto v_13245;
v_13241:
    v_13253 = qcdr(v_13252);
    goto v_13242;
v_13243:
    v_13252 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13244;
v_13245:
    goto v_13241;
v_13242:
    goto v_13243;
v_13244:
    v_13252 = *(LispObject *)((char *)v_13253 + (CELL-TAG_VECTOR) + (((intptr_t)v_13252-TAG_FIXNUM)/(16/CELL)));
    v_13252 = qcdr(v_13252);
    v_13252 = (v_13252 == nil ? lisp_true : nil);
    return onevalue(v_13252);
}



// Code for ratn

static LispObject CC_ratn(LispObject env,
                         LispObject v_13239)
{
    env = qenv(env);
    LispObject v_13290, v_13291, v_13292;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13292 = v_13239;
// end of prologue
    v_13290 = v_13292;
    if (v_13290 == nil) goto v_13243;
    else goto v_13244;
v_13243:
    goto v_13251;
v_13247:
    v_13291 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13248;
v_13249:
    v_13290 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13250;
v_13251:
    goto v_13247;
v_13248:
    goto v_13249;
v_13250:
    return cons(v_13291, v_13290);
v_13244:
    v_13290 = v_13292;
    if (!consp(v_13290)) goto v_13254;
    else goto v_13255;
v_13254:
    goto v_13262;
v_13258:
    v_13291 = v_13292;
    goto v_13259;
v_13260:
    v_13290 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13261;
v_13262:
    goto v_13258;
v_13259:
    goto v_13260;
v_13261:
    return cons(v_13291, v_13290);
v_13255:
    goto v_13271;
v_13267:
    v_13290 = v_13292;
    v_13291 = qcar(v_13290);
    goto v_13268;
v_13269:
    v_13290 = elt(env, 1); // !:rn!:
    goto v_13270;
v_13271:
    goto v_13267;
v_13268:
    goto v_13269;
v_13270:
    if (v_13291 == v_13290) goto v_13265;
    else goto v_13266;
v_13265:
    v_13290 = v_13292;
    v_13290 = qcdr(v_13290);
    goto v_13242;
v_13266:
    goto v_13286;
v_13280:
    v_13292 = elt(env, 2); // arnum
    goto v_13281;
v_13282:
    v_13291 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_13283;
v_13284:
    v_13290 = elt(env, 3); // "Illegal domain in :ar:"
    goto v_13285;
v_13286:
    goto v_13280;
v_13281:
    goto v_13282;
v_13283:
    goto v_13284;
v_13285:
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_13292, v_13291, v_13290);
    }
    v_13290 = nil;
v_13242:
    return onevalue(v_13290);
}



// Code for crprcd2

static LispObject CC_crprcd2(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13247;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13239,v_13240);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13240;
    stack[-1] = v_13239;
// end of prologue
    v_13247 = stack[-1];
    fn = elt(env, 2); // crprcd
    v_13247 = (*qfn1(fn))(fn, v_13247);
    env = stack[-2];
    stack[-1] = v_13247;
    v_13247 = stack[0];
    fn = elt(env, 2); // crprcd
    v_13247 = (*qfn1(fn))(fn, v_13247);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_13247; // yy!!
    v_13247 = stack[-1];
    return onevalue(v_13247);
}



// Code for innprodkp

static LispObject CC_innprodkp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13294, v_13295, v_13296;
    LispObject fn;
    LispObject v_13242, v_13241, v_13240, v_13239;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "innprodkp");
    va_start(aa, nargs);
    v_13239 = va_arg(aa, LispObject);
    v_13240 = va_arg(aa, LispObject);
    v_13241 = va_arg(aa, LispObject);
    v_13242 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_13242,v_13241,v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_13239,v_13240,v_13241,v_13242);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13242;
    stack[-1] = v_13241;
    stack[-2] = v_13240;
    v_13295 = v_13239;
// end of prologue
v_13246:
    v_13294 = stack[-1];
    if (v_13294 == nil) goto v_13249;
    else goto v_13250;
v_13249:
    v_13294 = nil;
    goto v_13245;
v_13250:
    goto v_13259;
v_13255:
    v_13296 = stack[-2];
    goto v_13256;
v_13257:
    v_13294 = stack[-1];
    v_13294 = qcar(v_13294);
    goto v_13258;
v_13259:
    goto v_13255;
v_13256:
    goto v_13257;
v_13258:
    if (equal(v_13296, v_13294)) goto v_13253;
    else goto v_13254;
v_13253:
    goto v_13268;
v_13264:
    goto v_13265;
v_13266:
    goto v_13275;
v_13271:
    goto v_13272;
v_13273:
    v_13294 = stack[-1];
    v_13294 = qcdr(v_13294);
    goto v_13274;
v_13275:
    goto v_13271;
v_13272:
    goto v_13273;
v_13274:
    fn = elt(env, 1); // reversip2
    v_13294 = (*qfn2(fn))(fn, v_13295, v_13294);
    goto v_13267;
v_13268:
    goto v_13264;
v_13265:
    goto v_13266;
v_13267:
    {
        LispObject v_13300 = stack[0];
        return cons(v_13300, v_13294);
    }
v_13254:
    goto v_13286;
v_13282:
    v_13294 = stack[-1];
    v_13294 = qcar(v_13294);
    goto v_13283;
v_13284:
    goto v_13285;
v_13286:
    goto v_13282;
v_13283:
    goto v_13284;
v_13285:
    v_13294 = cons(v_13294, v_13295);
    env = stack[-3];
    v_13295 = v_13294;
    v_13294 = stack[-1];
    v_13294 = qcdr(v_13294);
    stack[-1] = v_13294;
    v_13294 = stack[0];
    v_13294 = (v_13294 == nil ? lisp_true : nil);
    stack[0] = v_13294;
    goto v_13246;
    v_13294 = nil;
v_13245:
    return onevalue(v_13294);
}



// Code for ordered!-gcd!-mod!-p

static LispObject CC_orderedKgcdKmodKp(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13319, v_13320;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13239,v_13240);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13240;
    stack[-1] = v_13239;
// end of prologue
    v_13319 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_13319;
v_13245:
    goto v_13252;
v_13248:
    v_13320 = stack[-1];
    goto v_13249;
v_13250:
    v_13319 = stack[0];
    goto v_13251;
v_13252:
    goto v_13248;
v_13249:
    goto v_13250;
v_13251:
    fn = elt(env, 2); // reduce!-degree!-mod!-p
    v_13319 = (*qfn2(fn))(fn, v_13320, v_13319);
    env = stack[-3];
    stack[-1] = v_13319;
    v_13319 = stack[-1];
    if (v_13319 == nil) goto v_13257;
    else goto v_13258;
v_13257:
    v_13319 = stack[0];
    {
        fn = elt(env, 3); // monic!-mod!-p
        return (*qfn1(fn))(fn, v_13319);
    }
v_13258:
    v_13319 = stack[-2];
    v_13319 = add1(v_13319);
    env = stack[-3];
    stack[-2] = v_13319;
    v_13319 = stack[-1];
    if (!consp(v_13319)) goto v_13270;
    else goto v_13271;
v_13270:
    v_13319 = lisp_true;
    goto v_13269;
v_13271:
    v_13319 = stack[-1];
    v_13319 = qcar(v_13319);
    v_13319 = (consp(v_13319) ? nil : lisp_true);
    goto v_13269;
    v_13319 = nil;
v_13269:
    if (v_13319 == nil) goto v_13267;
    goto v_13284;
v_13280:
    v_13320 = qvalue(elt(env, 1)); // reduction!-count
    goto v_13281;
v_13282:
    v_13319 = stack[-2];
    goto v_13283;
v_13284:
    goto v_13280;
v_13281:
    goto v_13282;
v_13283:
    v_13319 = plus2(v_13320, v_13319);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_13319; // reduction!-count
    v_13319 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13244;
v_13267:
    goto v_13295;
v_13291:
    v_13319 = stack[-1];
    v_13319 = qcar(v_13319);
    v_13319 = qcar(v_13319);
    v_13320 = qcdr(v_13319);
    goto v_13292;
v_13293:
    v_13319 = stack[0];
    v_13319 = qcar(v_13319);
    v_13319 = qcar(v_13319);
    v_13319 = qcdr(v_13319);
    goto v_13294;
v_13295:
    goto v_13291;
v_13292:
    goto v_13293;
v_13294:
    v_13319 = (LispObject)lessp2(v_13320, v_13319);
    v_13319 = v_13319 ? lisp_true : nil;
    env = stack[-3];
    if (v_13319 == nil) goto v_13289;
    goto v_13312;
v_13308:
    v_13320 = qvalue(elt(env, 1)); // reduction!-count
    goto v_13309;
v_13310:
    v_13319 = stack[-2];
    goto v_13311;
v_13312:
    goto v_13308;
v_13309:
    goto v_13310;
v_13311:
    v_13319 = plus2(v_13320, v_13319);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_13319; // reduction!-count
    v_13319 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_13319;
    v_13319 = stack[-1];
    v_13320 = v_13319;
    v_13319 = stack[0];
    stack[-1] = v_13319;
    v_13319 = v_13320;
    stack[0] = v_13319;
    goto v_13265;
v_13289:
v_13265:
    goto v_13245;
v_13244:
    return onevalue(v_13319);
}



// Code for pairxvars

static LispObject CC_pairxvars(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13385, v_13386, v_13387;
    LispObject fn;
    LispObject v_13242, v_13241, v_13240, v_13239;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "pairxvars");
    va_start(aa, nargs);
    v_13239 = va_arg(aa, LispObject);
    v_13240 = va_arg(aa, LispObject);
    v_13241 = va_arg(aa, LispObject);
    v_13242 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_13242,v_13241,v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_13239,v_13240,v_13241,v_13242);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_13242;
    stack[-2] = v_13241;
    stack[-3] = v_13240;
    stack[-4] = v_13239;
// end of prologue
    stack[-5] = nil;
v_13250:
    v_13385 = stack[-4];
    if (v_13385 == nil) goto v_13253;
    else goto v_13254;
v_13253:
    goto v_13249;
v_13254:
    goto v_13265;
v_13261:
    v_13385 = stack[-4];
    v_13386 = qcar(v_13385);
    goto v_13262;
v_13263:
    v_13385 = stack[-3];
    goto v_13264;
v_13265:
    goto v_13261;
v_13262:
    goto v_13263;
v_13264:
    v_13385 = Latsoc(nil, v_13386, v_13385);
    stack[0] = v_13385;
    if (v_13385 == nil) goto v_13260;
    goto v_13275;
v_13271:
    v_13386 = stack[0];
    goto v_13272;
v_13273:
    v_13385 = stack[-3];
    goto v_13274;
v_13275:
    goto v_13271;
v_13272:
    goto v_13273;
v_13274:
    v_13385 = Ldelete(nil, v_13386, v_13385);
    env = stack[-6];
    stack[-3] = v_13385;
    goto v_13286;
v_13282:
    v_13385 = stack[0];
    v_13386 = qcdr(v_13385);
    goto v_13283;
v_13284:
    v_13385 = elt(env, 1); // scalar
    goto v_13285;
v_13286:
    goto v_13282;
v_13283:
    goto v_13284;
v_13285:
    if (v_13386 == v_13385) goto v_13281;
    goto v_13297;
v_13291:
    v_13385 = stack[-4];
    v_13387 = qcar(v_13385);
    goto v_13292;
v_13293:
    v_13385 = stack[0];
    v_13386 = qcdr(v_13385);
    goto v_13294;
v_13295:
    v_13385 = stack[-5];
    goto v_13296;
v_13297:
    goto v_13291;
v_13292:
    goto v_13293;
v_13294:
    goto v_13295;
v_13296:
    v_13385 = acons(v_13387, v_13386, v_13385);
    env = stack[-6];
    stack[-5] = v_13385;
    goto v_13279;
v_13281:
    goto v_13312;
v_13306:
    v_13385 = stack[-4];
    v_13387 = qcar(v_13385);
    goto v_13307;
v_13308:
    v_13386 = stack[-1];
    goto v_13309;
v_13310:
    v_13385 = stack[-5];
    goto v_13311;
v_13312:
    goto v_13306;
v_13307:
    goto v_13308;
v_13309:
    goto v_13310;
v_13311:
    v_13385 = acons(v_13387, v_13386, v_13385);
    env = stack[-6];
    stack[-5] = v_13385;
    goto v_13279;
v_13279:
    goto v_13258;
v_13260:
    v_13385 = stack[-4];
    v_13385 = qcar(v_13385);
    if (symbolp(v_13385)) goto v_13322;
    v_13385 = lisp_true;
    goto v_13320;
v_13322:
    v_13385 = stack[-4];
    v_13385 = qcar(v_13385);
    if (!symbolp(v_13385)) v_13385 = nil;
    else { v_13385 = qfastgets(v_13385);
           if (v_13385 != nil) { v_13385 = elt(v_13385, 23); // infix
#ifdef RECORD_GET
             if (v_13385 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_13385 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_13385 == SPID_NOPROP) v_13385 = nil; }}
#endif
    if (v_13385 == nil) goto v_13330;
    else goto v_13329;
v_13330:
    v_13385 = stack[-4];
    v_13385 = qcar(v_13385);
    if (!symbolp(v_13385)) v_13385 = nil;
    else { v_13385 = qfastgets(v_13385);
           if (v_13385 != nil) { v_13385 = elt(v_13385, 36); // stat
#ifdef RECORD_GET
             if (v_13385 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v_13385 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v_13385 == SPID_NOPROP) v_13385 = nil; }}
#endif
v_13329:
    goto v_13320;
    v_13385 = nil;
v_13320:
    if (v_13385 == nil) goto v_13318;
    goto v_13342;
v_13338:
    goto v_13348;
v_13344:
    v_13386 = elt(env, 2); // "Invalid parameter:"
    goto v_13345;
v_13346:
    v_13385 = stack[-4];
    v_13385 = qcar(v_13385);
    goto v_13347;
v_13348:
    goto v_13344;
v_13345:
    goto v_13346;
v_13347:
    v_13386 = list2(v_13386, v_13385);
    env = stack[-6];
    goto v_13339;
v_13340:
    v_13385 = nil;
    goto v_13341;
v_13342:
    goto v_13338;
v_13339:
    goto v_13340;
v_13341:
    fn = elt(env, 3); // symerr
    v_13385 = (*qfn2(fn))(fn, v_13386, v_13385);
    env = stack[-6];
    goto v_13258;
v_13318:
    goto v_13362;
v_13356:
    v_13385 = stack[-4];
    v_13387 = qcar(v_13385);
    goto v_13357;
v_13358:
    v_13386 = stack[-1];
    goto v_13359;
v_13360:
    v_13385 = stack[-5];
    goto v_13361;
v_13362:
    goto v_13356;
v_13357:
    goto v_13358;
v_13359:
    goto v_13360;
v_13361:
    v_13385 = acons(v_13387, v_13386, v_13385);
    env = stack[-6];
    stack[-5] = v_13385;
    goto v_13258;
v_13258:
    v_13385 = stack[-4];
    v_13385 = qcdr(v_13385);
    stack[-4] = v_13385;
    goto v_13250;
v_13249:
    goto v_13374;
v_13370:
    goto v_13380;
v_13376:
    v_13385 = stack[-5];
    fn = elt(env, 4); // reversip!*
    v_13386 = (*qfn1(fn))(fn, v_13385);
    env = stack[-6];
    goto v_13377;
v_13378:
    v_13385 = stack[-2];
    goto v_13379;
v_13380:
    goto v_13376;
v_13377:
    goto v_13378;
v_13379:
    v_13386 = Lappend(nil, v_13386, v_13385);
    goto v_13371;
v_13372:
    v_13385 = stack[-3];
    goto v_13373;
v_13374:
    goto v_13370;
v_13371:
    goto v_13372;
v_13373:
    return cons(v_13386, v_13385);
    return onevalue(v_13385);
}



// Code for monomwrite

static LispObject CC_monomwrite(LispObject env,
                         LispObject v_13239)
{
    env = qenv(env);
    LispObject v_13339, v_13340, v_13341;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13239);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_13340 = v_13239;
// end of prologue
    stack[-5] = nil;
    v_13339 = qvalue(elt(env, 1)); // fluidbibasisnumberofvariables
    stack[-2] = v_13339;
    v_13339 = qvalue(elt(env, 2)); // fluidbibasisreversedvariables
    stack[-4] = v_13339;
    goto v_13254;
v_13250:
    goto v_13251;
v_13252:
    v_13339 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13253;
v_13254:
    goto v_13250;
v_13251:
    goto v_13252;
v_13253:
    v_13339 = *(LispObject *)((char *)v_13340 + (CELL-TAG_VECTOR) + (((intptr_t)v_13339-TAG_FIXNUM)/(16/CELL)));
    stack[-3] = v_13339;
v_13260:
    v_13339 = stack[-3];
    v_13339 = qcar(v_13339);
    if (v_13339 == nil) goto v_13263;
    else goto v_13264;
v_13263:
    goto v_13259;
v_13264:
    v_13339 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_13339;
v_13271:
    goto v_13283;
v_13279:
    goto v_13289;
v_13285:
    v_13340 = stack[-2];
    goto v_13286;
v_13287:
    v_13339 = stack[-3];
    v_13339 = qcar(v_13339);
    goto v_13288;
v_13289:
    goto v_13285;
v_13286:
    goto v_13287;
v_13288:
    v_13340 = difference2(v_13340, v_13339);
    env = stack[-6];
    goto v_13280;
v_13281:
    v_13339 = stack[0];
    goto v_13282;
v_13283:
    goto v_13279;
v_13280:
    goto v_13281;
v_13282:
    v_13339 = difference2(v_13340, v_13339);
    env = stack[-6];
    v_13339 = Lminusp(nil, v_13339);
    env = stack[-6];
    if (v_13339 == nil) goto v_13276;
    goto v_13270;
v_13276:
    v_13339 = stack[-4];
    v_13339 = qcdr(v_13339);
    stack[-4] = v_13339;
    v_13339 = stack[0];
    v_13339 = add1(v_13339);
    env = stack[-6];
    stack[0] = v_13339;
    goto v_13271;
v_13270:
    v_13339 = stack[-3];
    v_13339 = qcar(v_13339);
    stack[-2] = v_13339;
    v_13339 = stack[-5];
    if (v_13339 == nil) goto v_13305;
    goto v_13314;
v_13308:
    v_13339 = stack[-4];
    stack[-1] = qcar(v_13339);
    goto v_13309;
v_13310:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13311;
v_13312:
    v_13339 = stack[-5];
    v_13339 = ncons(v_13339);
    env = stack[-6];
    goto v_13313;
v_13314:
    goto v_13308;
v_13309:
    goto v_13310;
v_13311:
    goto v_13312;
v_13313:
    v_13339 = acons(stack[-1], stack[0], v_13339);
    env = stack[-6];
    stack[-5] = v_13339;
    goto v_13303;
v_13305:
    goto v_13329;
v_13323:
    v_13339 = stack[-4];
    v_13341 = qcar(v_13339);
    goto v_13324;
v_13325:
    v_13340 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13326;
v_13327:
    v_13339 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13328;
v_13329:
    goto v_13323;
v_13324:
    goto v_13325;
v_13326:
    goto v_13327;
v_13328:
    v_13339 = acons(v_13341, v_13340, v_13339);
    env = stack[-6];
    stack[-5] = v_13339;
    goto v_13303;
v_13303:
    v_13339 = stack[-3];
    v_13339 = qcdr(v_13339);
    stack[-3] = v_13339;
    goto v_13260;
v_13259:
    v_13339 = stack[-5];
    return onevalue(v_13339);
}



// Code for super_der_simp

static LispObject CC_super_der_simp(LispObject env,
                         LispObject v_13239)
{
    env = qenv(env);
    LispObject v_13666, v_13667, v_13668;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13239);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_13239;
// end of prologue
    goto v_13249;
v_13245:
    v_13666 = stack[-9];
    v_13667 = Llength(nil, v_13666);
    env = stack[-11];
    goto v_13246;
v_13247:
    v_13666 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13248;
v_13249:
    goto v_13245;
v_13246:
    goto v_13247;
v_13248:
    if (v_13667 == v_13666) goto v_13243;
    else goto v_13244;
v_13243:
    v_13666 = stack[-9];
    v_13666 = qcar(v_13666);
    fn = elt(env, 6); // reval
    v_13666 = (*qfn1(fn))(fn, v_13666);
    env = stack[-11];
    stack[-10] = v_13666;
    goto v_13269;
v_13265:
    v_13667 = stack[-10];
    goto v_13266;
v_13267:
    v_13666 = elt(env, 1); // variables
    goto v_13268;
v_13269:
    goto v_13265;
v_13266:
    goto v_13267;
v_13268:
    v_13666 = get(v_13667, v_13666);
    env = stack[-11];
    stack[-8] = v_13666;
    v_13666 = stack[-9];
    v_13666 = qcdr(v_13666);
    v_13666 = qcar(v_13666);
    fn = elt(env, 7); // simp!*
    v_13666 = (*qfn1(fn))(fn, v_13666);
    env = stack[-11];
    stack[-9] = v_13666;
    goto v_13281;
v_13277:
    v_13666 = stack[-9];
    v_13667 = qcar(v_13666);
    goto v_13278;
v_13279:
    v_13666 = elt(env, 2); // (ext)
    goto v_13280;
v_13281:
    goto v_13277;
v_13278:
    goto v_13279;
v_13280:
    fn = elt(env, 8); // split_form
    v_13666 = (*qfn2(fn))(fn, v_13667, v_13666);
    env = stack[-11];
    stack[-7] = v_13666;
    goto v_13292;
v_13286:
    v_13666 = elt(env, 3); // ext
    v_13668 = ncons(v_13666);
    env = stack[-11];
    goto v_13287;
v_13288:
    v_13666 = stack[-7];
    v_13667 = qcar(v_13666);
    goto v_13289;
v_13290:
    v_13666 = stack[-7];
    v_13666 = qcdr(v_13666);
    goto v_13291;
v_13292:
    goto v_13286;
v_13287:
    goto v_13288;
v_13289:
    goto v_13290;
v_13291:
    v_13666 = acons(v_13668, v_13667, v_13666);
    env = stack[-11];
    stack[-7] = v_13666;
    goto v_13304;
v_13300:
    v_13666 = stack[-9];
    v_13667 = qcdr(v_13666);
    goto v_13301;
v_13302:
    v_13666 = elt(env, 2); // (ext)
    goto v_13303;
v_13304:
    goto v_13300;
v_13301:
    goto v_13302;
v_13303:
    fn = elt(env, 8); // split_form
    v_13666 = (*qfn2(fn))(fn, v_13667, v_13666);
    env = stack[-11];
    stack[-6] = v_13666;
    goto v_13315;
v_13309:
    v_13666 = elt(env, 3); // ext
    v_13668 = ncons(v_13666);
    env = stack[-11];
    goto v_13310;
v_13311:
    v_13666 = stack[-6];
    v_13667 = qcar(v_13666);
    goto v_13312;
v_13313:
    v_13666 = stack[-6];
    v_13666 = qcdr(v_13666);
    goto v_13314;
v_13315:
    goto v_13309;
v_13310:
    goto v_13311;
v_13312:
    goto v_13313;
v_13314:
    v_13666 = acons(v_13668, v_13667, v_13666);
    env = stack[-11];
    stack[-6] = v_13666;
    v_13666 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_13666;
    goto v_13339;
v_13335:
    goto v_13345;
v_13341:
    v_13667 = stack[-10];
    goto v_13342;
v_13343:
    v_13666 = elt(env, 4); // even_dimension
    goto v_13344;
v_13345:
    goto v_13341;
v_13342:
    goto v_13343;
v_13344:
    v_13667 = get(v_13667, v_13666);
    env = stack[-11];
    goto v_13336;
v_13337:
    v_13666 = stack[-5];
    goto v_13338;
v_13339:
    goto v_13335;
v_13336:
    goto v_13337;
v_13338:
    v_13666 = difference2(v_13667, v_13666);
    env = stack[-11];
    v_13666 = Lminusp(nil, v_13666);
    env = stack[-11];
    if (v_13666 == nil) goto v_13332;
    v_13666 = nil;
    goto v_13326;
v_13332:
    goto v_13359;
v_13353:
    v_13668 = stack[-10];
    goto v_13354;
v_13355:
    v_13667 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13356;
v_13357:
    v_13666 = stack[-5];
    goto v_13358;
v_13359:
    goto v_13353;
v_13354:
    goto v_13355;
v_13356:
    goto v_13357;
v_13358:
    v_13666 = list3(v_13668, v_13667, v_13666);
    env = stack[-11];
    fn = elt(env, 7); // simp!*
    v_13666 = (*qfn1(fn))(fn, v_13666);
    env = stack[-11];
    stack[-1] = v_13666;
    goto v_13369;
v_13365:
    goto v_13375;
v_13371:
    v_13667 = stack[-8];
    goto v_13372;
v_13373:
    v_13666 = stack[-5];
    goto v_13374;
v_13375:
    goto v_13371;
v_13372:
    goto v_13373;
v_13374:
    fn = elt(env, 9); // nth
    stack[0] = (*qfn2(fn))(fn, v_13667, v_13666);
    env = stack[-11];
    goto v_13366;
v_13367:
    goto v_13383;
v_13379:
    v_13667 = stack[-1];
    goto v_13380;
v_13381:
    v_13666 = elt(env, 2); // (ext)
    goto v_13382;
v_13383:
    goto v_13379;
v_13380:
    goto v_13381;
v_13382:
    fn = elt(env, 10); // split_ext
    v_13666 = (*qfn2(fn))(fn, v_13667, v_13666);
    env = stack[-11];
    goto v_13368;
v_13369:
    goto v_13365;
v_13366:
    goto v_13367;
v_13368:
    v_13666 = cons(stack[0], v_13666);
    env = stack[-11];
    v_13666 = ncons(v_13666);
    env = stack[-11];
    stack[-3] = v_13666;
    stack[-4] = v_13666;
v_13327:
    v_13666 = stack[-5];
    v_13666 = add1(v_13666);
    env = stack[-11];
    stack[-5] = v_13666;
    goto v_13398;
v_13394:
    goto v_13404;
v_13400:
    v_13667 = stack[-10];
    goto v_13401;
v_13402:
    v_13666 = elt(env, 4); // even_dimension
    goto v_13403;
v_13404:
    goto v_13400;
v_13401:
    goto v_13402;
v_13403:
    v_13667 = get(v_13667, v_13666);
    env = stack[-11];
    goto v_13395;
v_13396:
    v_13666 = stack[-5];
    goto v_13397;
v_13398:
    goto v_13394;
v_13395:
    goto v_13396;
v_13397:
    v_13666 = difference2(v_13667, v_13666);
    env = stack[-11];
    v_13666 = Lminusp(nil, v_13666);
    env = stack[-11];
    if (v_13666 == nil) goto v_13391;
    v_13666 = stack[-4];
    goto v_13326;
v_13391:
    goto v_13414;
v_13410:
    stack[-2] = stack[-3];
    goto v_13411;
v_13412:
    goto v_13425;
v_13419:
    v_13668 = stack[-10];
    goto v_13420;
v_13421:
    v_13667 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13422;
v_13423:
    v_13666 = stack[-5];
    goto v_13424;
v_13425:
    goto v_13419;
v_13420:
    goto v_13421;
v_13422:
    goto v_13423;
v_13424:
    v_13666 = list3(v_13668, v_13667, v_13666);
    env = stack[-11];
    fn = elt(env, 7); // simp!*
    v_13666 = (*qfn1(fn))(fn, v_13666);
    env = stack[-11];
    stack[-1] = v_13666;
    goto v_13435;
v_13431:
    goto v_13441;
v_13437:
    v_13667 = stack[-8];
    goto v_13438;
v_13439:
    v_13666 = stack[-5];
    goto v_13440;
v_13441:
    goto v_13437;
v_13438:
    goto v_13439;
v_13440:
    fn = elt(env, 9); // nth
    stack[0] = (*qfn2(fn))(fn, v_13667, v_13666);
    env = stack[-11];
    goto v_13432;
v_13433:
    goto v_13449;
v_13445:
    v_13667 = stack[-1];
    goto v_13446;
v_13447:
    v_13666 = elt(env, 2); // (ext)
    goto v_13448;
v_13449:
    goto v_13445;
v_13446:
    goto v_13447;
v_13448:
    fn = elt(env, 10); // split_ext
    v_13666 = (*qfn2(fn))(fn, v_13667, v_13666);
    env = stack[-11];
    goto v_13434;
v_13435:
    goto v_13431;
v_13432:
    goto v_13433;
v_13434:
    v_13666 = cons(stack[0], v_13666);
    env = stack[-11];
    v_13666 = ncons(v_13666);
    env = stack[-11];
    goto v_13413;
v_13414:
    goto v_13410;
v_13411:
    goto v_13412;
v_13413:
    v_13666 = Lrplacd(nil, stack[-2], v_13666);
    env = stack[-11];
    v_13666 = stack[-3];
    v_13666 = qcdr(v_13666);
    stack[-3] = v_13666;
    goto v_13327;
v_13326:
    stack[-5] = v_13666;
    v_13666 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_13666;
    goto v_13471;
v_13467:
    goto v_13477;
v_13473:
    v_13667 = stack[-10];
    goto v_13474;
v_13475:
    v_13666 = elt(env, 5); // odd_dimension
    goto v_13476;
v_13477:
    goto v_13473;
v_13474:
    goto v_13475;
v_13476:
    v_13667 = get(v_13667, v_13666);
    env = stack[-11];
    goto v_13468;
v_13469:
    v_13666 = stack[-4];
    goto v_13470;
v_13471:
    goto v_13467;
v_13468:
    goto v_13469;
v_13470:
    v_13666 = difference2(v_13667, v_13666);
    env = stack[-11];
    v_13666 = Lminusp(nil, v_13666);
    env = stack[-11];
    if (v_13666 == nil) goto v_13464;
    v_13666 = nil;
    goto v_13458;
v_13464:
    goto v_13491;
v_13485:
    v_13668 = stack[-10];
    goto v_13486;
v_13487:
    v_13667 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13488;
v_13489:
    v_13666 = stack[-4];
    goto v_13490;
v_13491:
    goto v_13485;
v_13486:
    goto v_13487;
v_13488:
    goto v_13489;
v_13490:
    v_13666 = list3(v_13668, v_13667, v_13666);
    env = stack[-11];
    fn = elt(env, 7); // simp!*
    v_13666 = (*qfn1(fn))(fn, v_13666);
    env = stack[-11];
    goto v_13501;
v_13497:
    stack[0] = stack[-4];
    goto v_13498;
v_13499:
    goto v_13508;
v_13504:
    v_13667 = v_13666;
    goto v_13505;
v_13506:
    v_13666 = elt(env, 2); // (ext)
    goto v_13507;
v_13508:
    goto v_13504;
v_13505:
    goto v_13506;
v_13507:
    fn = elt(env, 10); // split_ext
    v_13666 = (*qfn2(fn))(fn, v_13667, v_13666);
    env = stack[-11];
    goto v_13500;
v_13501:
    goto v_13497;
v_13498:
    goto v_13499;
v_13500:
    v_13666 = cons(stack[0], v_13666);
    env = stack[-11];
    v_13666 = ncons(v_13666);
    env = stack[-11];
    stack[-2] = v_13666;
    stack[-3] = v_13666;
v_13459:
    v_13666 = stack[-4];
    v_13666 = add1(v_13666);
    env = stack[-11];
    stack[-4] = v_13666;
    goto v_13523;
v_13519:
    goto v_13529;
v_13525:
    v_13667 = stack[-10];
    goto v_13526;
v_13527:
    v_13666 = elt(env, 5); // odd_dimension
    goto v_13528;
v_13529:
    goto v_13525;
v_13526:
    goto v_13527;
v_13528:
    v_13667 = get(v_13667, v_13666);
    env = stack[-11];
    goto v_13520;
v_13521:
    v_13666 = stack[-4];
    goto v_13522;
v_13523:
    goto v_13519;
v_13520:
    goto v_13521;
v_13522:
    v_13666 = difference2(v_13667, v_13666);
    env = stack[-11];
    v_13666 = Lminusp(nil, v_13666);
    env = stack[-11];
    if (v_13666 == nil) goto v_13516;
    v_13666 = stack[-3];
    goto v_13458;
v_13516:
    goto v_13539;
v_13535:
    stack[-1] = stack[-2];
    goto v_13536;
v_13537:
    goto v_13550;
v_13544:
    v_13668 = stack[-10];
    goto v_13545;
v_13546:
    v_13667 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13547;
v_13548:
    v_13666 = stack[-4];
    goto v_13549;
v_13550:
    goto v_13544;
v_13545:
    goto v_13546;
v_13547:
    goto v_13548;
v_13549:
    v_13666 = list3(v_13668, v_13667, v_13666);
    env = stack[-11];
    fn = elt(env, 7); // simp!*
    v_13666 = (*qfn1(fn))(fn, v_13666);
    env = stack[-11];
    goto v_13560;
v_13556:
    stack[0] = stack[-4];
    goto v_13557;
v_13558:
    goto v_13567;
v_13563:
    v_13667 = v_13666;
    goto v_13564;
v_13565:
    v_13666 = elt(env, 2); // (ext)
    goto v_13566;
v_13567:
    goto v_13563;
v_13564:
    goto v_13565;
v_13566:
    fn = elt(env, 10); // split_ext
    v_13666 = (*qfn2(fn))(fn, v_13667, v_13666);
    env = stack[-11];
    goto v_13559;
v_13560:
    goto v_13556;
v_13557:
    goto v_13558;
v_13559:
    v_13666 = cons(stack[0], v_13666);
    env = stack[-11];
    v_13666 = ncons(v_13666);
    env = stack[-11];
    goto v_13538;
v_13539:
    goto v_13535;
v_13536:
    goto v_13537;
v_13538:
    v_13666 = Lrplacd(nil, stack[-1], v_13666);
    env = stack[-11];
    v_13666 = stack[-2];
    v_13666 = qcdr(v_13666);
    stack[-2] = v_13666;
    goto v_13459;
v_13458:
    stack[-1] = v_13666;
    goto v_13577;
v_13573:
    goto v_13583;
v_13579:
    goto v_13589;
v_13585:
    goto v_13595;
v_13591:
    v_13667 = stack[-5];
    goto v_13592;
v_13593:
    v_13666 = stack[-7];
    goto v_13594;
v_13595:
    goto v_13591;
v_13592:
    goto v_13593;
v_13594:
    fn = elt(env, 11); // even_action
    stack[0] = (*qfn2(fn))(fn, v_13667, v_13666);
    env = stack[-11];
    goto v_13586;
v_13587:
    goto v_13603;
v_13599:
    v_13667 = stack[-1];
    goto v_13600;
v_13601:
    v_13666 = stack[-7];
    goto v_13602;
v_13603:
    goto v_13599;
v_13600:
    goto v_13601;
v_13602:
    fn = elt(env, 12); // odd_action
    v_13666 = (*qfn2(fn))(fn, v_13667, v_13666);
    env = stack[-11];
    goto v_13588;
v_13589:
    goto v_13585;
v_13586:
    goto v_13587;
v_13588:
    fn = elt(env, 13); // addsq
    stack[0] = (*qfn2(fn))(fn, stack[0], v_13666);
    env = stack[-11];
    goto v_13580;
v_13581:
    goto v_13611;
v_13607:
    v_13666 = stack[-9];
    v_13667 = qcdr(v_13666);
    goto v_13608;
v_13609:
    v_13666 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13610;
v_13611:
    goto v_13607;
v_13608:
    goto v_13609;
v_13610:
    v_13666 = cons(v_13667, v_13666);
    env = stack[-11];
    goto v_13582;
v_13583:
    goto v_13579;
v_13580:
    goto v_13581;
v_13582:
    fn = elt(env, 14); // quotsq
    stack[0] = (*qfn2(fn))(fn, stack[0], v_13666);
    env = stack[-11];
    goto v_13574;
v_13575:
    goto v_13621;
v_13617:
    goto v_13627;
v_13623:
    goto v_13633;
v_13629:
    v_13667 = stack[-5];
    goto v_13630;
v_13631:
    v_13666 = stack[-6];
    goto v_13632;
v_13633:
    goto v_13629;
v_13630:
    goto v_13631;
v_13632:
    fn = elt(env, 11); // even_action
    stack[-1] = (*qfn2(fn))(fn, v_13667, v_13666);
    env = stack[-11];
    goto v_13624;
v_13625:
    goto v_13641;
v_13637:
    v_13666 = stack[-9];
    v_13667 = qcar(v_13666);
    goto v_13638;
v_13639:
    v_13666 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13640;
v_13641:
    goto v_13637;
v_13638:
    goto v_13639;
v_13640:
    v_13666 = cons(v_13667, v_13666);
    env = stack[-11];
    goto v_13626;
v_13627:
    goto v_13623;
v_13624:
    goto v_13625;
v_13626:
    fn = elt(env, 15); // super_product_sq
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_13666);
    env = stack[-11];
    goto v_13618;
v_13619:
    goto v_13650;
v_13646:
    goto v_13656;
v_13652:
    v_13666 = stack[-9];
    v_13667 = qcdr(v_13666);
    goto v_13653;
v_13654:
    v_13666 = stack[-9];
    v_13666 = qcdr(v_13666);
    goto v_13655;
v_13656:
    goto v_13652;
v_13653:
    goto v_13654;
v_13655:
    fn = elt(env, 16); // multf
    v_13667 = (*qfn2(fn))(fn, v_13667, v_13666);
    env = stack[-11];
    goto v_13647;
v_13648:
    v_13666 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13649;
v_13650:
    goto v_13646;
v_13647:
    goto v_13648;
v_13649:
    v_13666 = cons(v_13667, v_13666);
    env = stack[-11];
    goto v_13620;
v_13621:
    goto v_13617;
v_13618:
    goto v_13619;
v_13620:
    fn = elt(env, 14); // quotsq
    v_13666 = (*qfn2(fn))(fn, stack[-1], v_13666);
    env = stack[-11];
    fn = elt(env, 17); // negsq
    v_13666 = (*qfn1(fn))(fn, v_13666);
    env = stack[-11];
    goto v_13576;
v_13577:
    goto v_13573;
v_13574:
    goto v_13575;
v_13576:
    {
        LispObject v_13680 = stack[0];
        fn = elt(env, 13); // addsq
        return (*qfn2(fn))(fn, v_13680, v_13666);
    }
    goto v_13242;
v_13244:
    v_13666 = stack[-9];
    {
        fn = elt(env, 18); // simpiden
        return (*qfn1(fn))(fn, v_13666);
    }
    v_13666 = nil;
v_13242:
    return onevalue(v_13666);
}



// Code for tayexp!-times2

static LispObject CC_tayexpKtimes2(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13322, v_13323, v_13324;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13239,v_13240);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13240;
    v_13323 = v_13239;
// end of prologue
    v_13322 = v_13323;
    if (!consp(v_13322)) goto v_13248;
    else goto v_13249;
v_13248:
    v_13322 = stack[0];
    v_13322 = (consp(v_13322) ? nil : lisp_true);
    goto v_13247;
v_13249:
    v_13322 = nil;
    goto v_13247;
    v_13322 = nil;
v_13247:
    if (v_13322 == nil) goto v_13245;
    goto v_13261;
v_13257:
    goto v_13258;
v_13259:
    v_13322 = stack[0];
    goto v_13260;
v_13261:
    goto v_13257;
v_13258:
    goto v_13259;
v_13260:
    return times2(v_13323, v_13322);
v_13245:
    v_13322 = v_13323;
    if (!consp(v_13322)) goto v_13268;
    else goto v_13269;
v_13268:
    goto v_13276;
v_13272:
    v_13322 = v_13323;
    fn = elt(env, 1); // !*i2rn
    v_13323 = (*qfn1(fn))(fn, v_13322);
    env = stack[-2];
    goto v_13273;
v_13274:
    v_13322 = stack[0];
    goto v_13275;
v_13276:
    goto v_13272;
v_13273:
    goto v_13274;
v_13275:
    fn = elt(env, 2); // rntimes!:
    v_13322 = (*qfn2(fn))(fn, v_13323, v_13322);
    goto v_13267;
v_13269:
    v_13322 = stack[0];
    if (!consp(v_13322)) goto v_13280;
    else goto v_13281;
v_13280:
    goto v_13288;
v_13284:
    stack[-1] = v_13323;
    goto v_13285;
v_13286:
    v_13322 = stack[0];
    fn = elt(env, 1); // !*i2rn
    v_13322 = (*qfn1(fn))(fn, v_13322);
    env = stack[-2];
    goto v_13287;
v_13288:
    goto v_13284;
v_13285:
    goto v_13286;
v_13287:
    fn = elt(env, 2); // rntimes!:
    v_13322 = (*qfn2(fn))(fn, stack[-1], v_13322);
    goto v_13267;
v_13281:
    goto v_13299;
v_13295:
    goto v_13296;
v_13297:
    v_13322 = stack[0];
    goto v_13298;
v_13299:
    goto v_13295;
v_13296:
    goto v_13297;
v_13298:
    fn = elt(env, 2); // rntimes!:
    v_13322 = (*qfn2(fn))(fn, v_13323, v_13322);
    goto v_13267;
    v_13322 = nil;
v_13267:
    v_13324 = v_13322;
    goto v_13311;
v_13307:
    v_13322 = v_13324;
    v_13322 = qcdr(v_13322);
    v_13323 = qcdr(v_13322);
    goto v_13308;
v_13309:
    v_13322 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13310;
v_13311:
    goto v_13307;
v_13308:
    goto v_13309;
v_13310:
    if (v_13323 == v_13322) goto v_13305;
    else goto v_13306;
v_13305:
    v_13322 = v_13324;
    v_13322 = qcdr(v_13322);
    v_13322 = qcar(v_13322);
    goto v_13304;
v_13306:
    v_13322 = v_13324;
    goto v_13304;
    v_13322 = nil;
v_13304:
    goto v_13243;
    v_13322 = nil;
v_13243:
    return onevalue(v_13322);
}



// Code for get!*elements

static LispObject CC_getHelements(LispObject env,
                         LispObject v_13239)
{
    env = qenv(env);
    LispObject v_13252, v_13253;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13252 = v_13239;
// end of prologue
    goto v_13249;
v_13245:
    goto v_13246;
v_13247:
    v_13253 = elt(env, 1); // elems
    goto v_13248;
v_13249:
    goto v_13245;
v_13246:
    goto v_13247;
v_13248:
    return get(v_13252, v_13253);
    return onevalue(v_13252);
}



// Code for talp_subt

static LispObject CC_talp_subt(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13331, v_13332, v_13333;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13239,v_13240);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_13332 = v_13240;
    stack[-4] = v_13239;
// end of prologue
    v_13331 = v_13332;
    if (symbolp(v_13331)) goto v_13249;
    else goto v_13248;
v_13249:
    goto v_13256;
v_13252:
    v_13333 = v_13332;
    goto v_13253;
v_13254:
    v_13331 = stack[-4];
    goto v_13255;
v_13256:
    goto v_13252;
v_13253:
    goto v_13254;
v_13255:
    v_13331 = Latsoc(nil, v_13333, v_13331);
    v_13333 = v_13331;
    if (v_13331 == nil) goto v_13248;
    v_13331 = v_13333;
    v_13331 = qcdr(v_13331);
    goto v_13244;
v_13248:
    v_13331 = v_13332;
    if (!consp(v_13331)) goto v_13264;
    else goto v_13265;
v_13264:
    v_13331 = v_13332;
    goto v_13244;
v_13265:
    goto v_13273;
v_13269:
    v_13331 = v_13332;
    stack[-5] = qcar(v_13331);
    goto v_13270;
v_13271:
    v_13331 = v_13332;
    v_13331 = qcdr(v_13331);
    stack[-3] = v_13331;
    v_13331 = stack[-3];
    if (v_13331 == nil) goto v_13286;
    else goto v_13287;
v_13286:
    v_13331 = nil;
    goto v_13280;
v_13287:
    v_13331 = stack[-3];
    v_13331 = qcar(v_13331);
    goto v_13299;
v_13295:
    v_13332 = stack[-4];
    goto v_13296;
v_13297:
    goto v_13298;
v_13299:
    goto v_13295;
v_13296:
    goto v_13297;
v_13298:
    v_13331 = CC_talp_subt(elt(env, 0), v_13332, v_13331);
    env = stack[-6];
    v_13331 = ncons(v_13331);
    env = stack[-6];
    stack[-1] = v_13331;
    stack[-2] = v_13331;
v_13281:
    v_13331 = stack[-3];
    v_13331 = qcdr(v_13331);
    stack[-3] = v_13331;
    v_13331 = stack[-3];
    if (v_13331 == nil) goto v_13306;
    else goto v_13307;
v_13306:
    v_13331 = stack[-2];
    goto v_13280;
v_13307:
    goto v_13315;
v_13311:
    stack[0] = stack[-1];
    goto v_13312;
v_13313:
    v_13331 = stack[-3];
    v_13331 = qcar(v_13331);
    goto v_13326;
v_13322:
    v_13332 = stack[-4];
    goto v_13323;
v_13324:
    goto v_13325;
v_13326:
    goto v_13322;
v_13323:
    goto v_13324;
v_13325:
    v_13331 = CC_talp_subt(elt(env, 0), v_13332, v_13331);
    env = stack[-6];
    v_13331 = ncons(v_13331);
    env = stack[-6];
    goto v_13314;
v_13315:
    goto v_13311;
v_13312:
    goto v_13313;
v_13314:
    v_13331 = Lrplacd(nil, stack[0], v_13331);
    env = stack[-6];
    v_13331 = stack[-1];
    v_13331 = qcdr(v_13331);
    stack[-1] = v_13331;
    goto v_13281;
v_13280:
    goto v_13272;
v_13273:
    goto v_13269;
v_13270:
    goto v_13271;
v_13272:
    {
        LispObject v_13340 = stack[-5];
        return cons(v_13340, v_13331);
    }
v_13244:
    return onevalue(v_13331);
}



// Code for ibalp_readform

static LispObject CC_ibalp_readform(LispObject env,
                         LispObject v_13239)
{
    env = qenv(env);
    LispObject v_13395, v_13396;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13239);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    v_13395 = v_13239;
// end of prologue
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-3] = nil;
    v_13396 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_13396;
    goto v_13257;
v_13253:
    v_13396 = v_13395;
    goto v_13254;
v_13255:
    v_13395 = elt(env, 1); // and
    goto v_13256;
v_13257:
    goto v_13253;
v_13254:
    goto v_13255;
v_13256:
    fn = elt(env, 7); // cl_mkstrict
    v_13395 = (*qfn2(fn))(fn, v_13396, v_13395);
    env = stack[-7];
    v_13395 = qcdr(v_13395);
    stack[-2] = v_13395;
    v_13395 = lisp_true;
    stack[-1] = v_13395;
v_13265:
    v_13395 = stack[-1];
    if (v_13395 == nil) goto v_13268;
    v_13395 = stack[-2];
    if (v_13395 == nil) goto v_13268;
    goto v_13269;
v_13268:
    goto v_13264;
v_13269:
    v_13395 = stack[-2];
    v_13395 = qcar(v_13395);
    v_13396 = v_13395;
    v_13395 = stack[-2];
    v_13395 = qcdr(v_13395);
    stack[-2] = v_13395;
    goto v_13284;
v_13280:
    goto v_13281;
v_13282:
    v_13395 = stack[-4];
    goto v_13283;
v_13284:
    goto v_13280;
v_13281:
    goto v_13282;
v_13283:
    fn = elt(env, 8); // ibalp_readclause
    v_13395 = (*qfn2(fn))(fn, v_13396, v_13395);
    env = stack[-7];
    stack[-6] = v_13395;
    v_13395 = stack[-6];
    v_13395 = qcar(v_13395);
    stack[-3] = v_13395;
    v_13395 = stack[-6];
    v_13395 = qcdr(v_13395);
    stack[-4] = v_13395;
    goto v_13299;
v_13295:
    v_13396 = stack[-3];
    goto v_13296;
v_13297:
    v_13395 = elt(env, 2); // true
    goto v_13298;
v_13299:
    goto v_13295;
v_13296:
    goto v_13297;
v_13298:
    if (v_13396 == v_13395) goto v_13294;
    v_13395 = stack[-3];
    fn = elt(env, 9); // ibalp_emptyclausep
    v_13395 = (*qfn1(fn))(fn, v_13395);
    env = stack[-7];
    if (v_13395 == nil) goto v_13305;
    v_13395 = nil;
    stack[-1] = v_13395;
    goto v_13303;
v_13305:
    goto v_13321;
v_13317:
    v_13396 = stack[-3];
    goto v_13318;
v_13319:
    v_13395 = stack[-5];
    goto v_13320;
v_13321:
    goto v_13317;
v_13318:
    goto v_13319;
v_13320:
    fn = elt(env, 10); // ibalp_clmember
    v_13395 = (*qfn2(fn))(fn, v_13396, v_13395);
    env = stack[-7];
    if (v_13395 == nil) goto v_13315;
    else goto v_13313;
v_13315:
    v_13395 = stack[-3];
    fn = elt(env, 11); // ibalp_redclause
    v_13395 = (*qfn1(fn))(fn, v_13395);
    env = stack[-7];
    if (v_13395 == nil) goto v_13324;
    else goto v_13313;
v_13324:
    goto v_13314;
v_13313:
    v_13395 = stack[-3];
    fn = elt(env, 12); // ibalp_undoclause
    v_13395 = (*qfn1(fn))(fn, v_13395);
    env = stack[-7];
    v_13395 = stack[0];
    v_13395 = add1(v_13395);
    env = stack[-7];
    stack[0] = v_13395;
    goto v_13312;
v_13314:
    goto v_13338;
v_13334:
    v_13395 = stack[-6];
    v_13396 = qcar(v_13395);
    goto v_13335;
v_13336:
    v_13395 = stack[-5];
    goto v_13337;
v_13338:
    goto v_13334;
v_13335:
    goto v_13336;
v_13337:
    v_13395 = cons(v_13396, v_13395);
    env = stack[-7];
    stack[-5] = v_13395;
    goto v_13312;
v_13312:
    goto v_13303;
v_13303:
    goto v_13292;
v_13294:
v_13292:
    goto v_13265;
v_13264:
    v_13395 = stack[-1];
    if (v_13395 == nil) goto v_13344;
    else goto v_13345;
v_13344:
    v_13395 = qvalue(elt(env, 3)); // !*rlverbose
    if (v_13395 == nil) goto v_13350;
    v_13395 = elt(env, 4); // "Detected empty clause"
    v_13395 = ncons(v_13395);
    env = stack[-7];
    fn = elt(env, 13); // ioto_tprin2t
    v_13395 = (*qfn1(fn))(fn, v_13395);
    env = stack[-7];
    goto v_13348;
v_13350:
v_13348:
    v_13395 = stack[-3];
    v_13395 = ncons(v_13395);
    return ncons(v_13395);
v_13345:
    v_13395 = stack[-5];
    if (v_13395 == nil) goto v_13360;
    else goto v_13361;
v_13360:
    v_13395 = qvalue(elt(env, 3)); // !*rlverbose
    if (v_13395 == nil) goto v_13366;
    v_13395 = elt(env, 5); // "Tautology detected"
    v_13395 = ncons(v_13395);
    env = stack[-7];
    fn = elt(env, 13); // ioto_tprin2t
    v_13395 = (*qfn1(fn))(fn, v_13395);
    goto v_13364;
v_13366:
v_13364:
    v_13395 = nil;
    return ncons(v_13395);
v_13361:
    v_13395 = qvalue(elt(env, 3)); // !*rlverbose
    if (v_13395 == nil) goto v_13376;
    goto v_13384;
v_13380:
    v_13396 = elt(env, 6); // "Deleted redundant clauses: "
    goto v_13381;
v_13382:
    v_13395 = stack[0];
    goto v_13383;
v_13384:
    goto v_13380;
v_13381:
    goto v_13382;
v_13383:
    v_13395 = list2(v_13396, v_13395);
    env = stack[-7];
    fn = elt(env, 13); // ioto_tprin2t
    v_13395 = (*qfn1(fn))(fn, v_13395);
    goto v_13374;
v_13376:
v_13374:
    goto v_13392;
v_13388:
    v_13396 = stack[-5];
    goto v_13389;
v_13390:
    v_13395 = stack[-4];
    goto v_13391;
v_13392:
    goto v_13388;
v_13389:
    goto v_13390;
v_13391:
    return cons(v_13396, v_13395);
    return onevalue(v_13395);
}



// Code for vsl_boundtype

static LispObject CC_vsl_boundtype(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13252, v_13253;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13252 = v_13240;
    v_13253 = v_13239;
// end of prologue
    goto v_13247;
v_13243:
    v_13253 = qcdr(v_13253);
    v_13253 = qcar(v_13253);
    goto v_13244;
v_13245:
    goto v_13246;
v_13247:
    goto v_13243;
v_13244:
    goto v_13245;
v_13246:
    {
        fn = elt(env, 1); // vsl_boundtype1
        return (*qfn2(fn))(fn, v_13253, v_13252);
    }
}



// Code for naryom

static LispObject CC_naryom(LispObject env,
                         LispObject v_13239)
{
    env = qenv(env);
    LispObject v_13333, v_13334;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13239);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_13239;
// end of prologue
    v_13333 = stack[-1];
    v_13333 = qcar(v_13333);
    stack[0] = v_13333;
    goto v_13255;
v_13251:
    v_13334 = stack[0];
    goto v_13252;
v_13253:
    v_13333 = elt(env, 1); // var
    goto v_13254;
v_13255:
    goto v_13251;
v_13252:
    goto v_13253;
v_13254:
    if (v_13334 == v_13333) goto v_13249;
    else goto v_13250;
v_13249:
    v_13333 = elt(env, 2); // variance
    stack[0] = v_13333;
    goto v_13248;
v_13250:
v_13248:
    goto v_13263;
v_13259:
    v_13334 = stack[0];
    goto v_13260;
v_13261:
    v_13333 = qvalue(elt(env, 3)); // valid_om!*
    goto v_13262;
v_13263:
    goto v_13259;
v_13260:
    goto v_13261;
v_13262:
    v_13333 = Lassoc(nil, v_13334, v_13333);
    stack[-2] = v_13333;
    v_13333 = stack[-2];
    if (v_13333 == nil) goto v_13270;
    v_13333 = stack[-2];
    v_13333 = qcdr(v_13333);
    v_13333 = qcar(v_13333);
    stack[-2] = v_13333;
    goto v_13268;
v_13270:
v_13268:
    v_13333 = stack[-1];
    v_13333 = qcdr(v_13333);
    v_13333 = qcar(v_13333);
    if (v_13333 == nil) goto v_13278;
    goto v_13290;
v_13286:
    v_13333 = stack[-1];
    v_13333 = qcdr(v_13333);
    v_13334 = qcar(v_13333);
    goto v_13287;
v_13288:
    v_13333 = elt(env, 4); // multiset
    goto v_13289;
v_13290:
    goto v_13286;
v_13287:
    goto v_13288;
v_13289:
    if (v_13334 == v_13333) goto v_13284;
    else goto v_13285;
v_13284:
    v_13333 = stack[-1];
    v_13333 = qcdr(v_13333);
    v_13333 = qcar(v_13333);
    stack[-2] = v_13333;
    goto v_13283;
v_13285:
v_13283:
    goto v_13276;
v_13278:
v_13276:
    v_13333 = elt(env, 5); // "<OMA>"
    fn = elt(env, 11); // printout
    v_13333 = (*qfn1(fn))(fn, v_13333);
    env = stack[-3];
    goto v_13306;
v_13302:
    v_13334 = qvalue(elt(env, 6)); // indent
    goto v_13303;
v_13304:
    v_13333 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13305;
v_13306:
    goto v_13302;
v_13303:
    goto v_13304;
v_13305:
    v_13333 = plus2(v_13334, v_13333);
    env = stack[-3];
    qvalue(elt(env, 6)) = v_13333; // indent
    v_13333 = elt(env, 7); // "<OMS cd="""
    fn = elt(env, 11); // printout
    v_13333 = (*qfn1(fn))(fn, v_13333);
    env = stack[-3];
    v_13333 = stack[-2];
    v_13333 = Lprinc(nil, v_13333);
    env = stack[-3];
    v_13333 = elt(env, 8); // """ name="""
    v_13333 = Lprinc(nil, v_13333);
    env = stack[-3];
    v_13333 = stack[0];
    v_13333 = Lprinc(nil, v_13333);
    env = stack[-3];
    v_13333 = elt(env, 9); // """>"
    v_13333 = Lprinc(nil, v_13333);
    env = stack[-3];
    v_13333 = stack[-1];
    v_13333 = qcdr(v_13333);
    v_13333 = qcdr(v_13333);
    fn = elt(env, 12); // multiom
    v_13333 = (*qfn1(fn))(fn, v_13333);
    env = stack[-3];
    goto v_13328;
v_13324:
    v_13334 = qvalue(elt(env, 6)); // indent
    goto v_13325;
v_13326:
    v_13333 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13327;
v_13328:
    goto v_13324;
v_13325:
    goto v_13326;
v_13327:
    v_13333 = difference2(v_13334, v_13333);
    env = stack[-3];
    qvalue(elt(env, 6)) = v_13333; // indent
    v_13333 = elt(env, 10); // "</OMA>"
    fn = elt(env, 11); // printout
    v_13333 = (*qfn1(fn))(fn, v_13333);
    v_13333 = nil;
    return onevalue(v_13333);
}



// Code for evdif

static LispObject CC_evdif(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13290, v_13291, v_13292;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13239,v_13240);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13240;
    stack[-1] = v_13239;
// end of prologue
    v_13292 = nil;
v_13247:
    v_13290 = stack[0];
    if (v_13290 == nil) goto v_13250;
    else goto v_13251;
v_13250:
    goto v_13246;
v_13251:
    v_13290 = stack[-1];
    if (v_13290 == nil) goto v_13256;
    else goto v_13257;
v_13256:
    v_13290 = elt(env, 1); // (0)
    stack[-1] = v_13290;
    goto v_13255;
v_13257:
v_13255:
    goto v_13265;
v_13261:
    goto v_13270;
v_13266:
    v_13290 = stack[-1];
    v_13291 = qcar(v_13290);
    goto v_13267;
v_13268:
    v_13290 = stack[0];
    v_13290 = qcar(v_13290);
    goto v_13269;
v_13270:
    goto v_13266;
v_13267:
    goto v_13268;
v_13269:
    v_13290 = (LispObject)(intptr_t)((intptr_t)v_13291 - (intptr_t)v_13290 + TAG_FIXNUM);
    goto v_13262;
v_13263:
    v_13291 = v_13292;
    goto v_13264;
v_13265:
    goto v_13261;
v_13262:
    goto v_13263;
v_13264:
    v_13290 = cons(v_13290, v_13291);
    env = stack[-2];
    v_13292 = v_13290;
    v_13290 = stack[-1];
    v_13290 = qcdr(v_13290);
    stack[-1] = v_13290;
    v_13290 = stack[0];
    v_13290 = qcdr(v_13290);
    stack[0] = v_13290;
    goto v_13247;
v_13246:
    goto v_13286;
v_13282:
    v_13290 = v_13292;
    v_13291 = Lnreverse(nil, v_13290);
    goto v_13283;
v_13284:
    v_13290 = stack[-1];
    goto v_13285;
v_13286:
    goto v_13282;
v_13283:
    goto v_13284;
v_13285:
        return Lnconc(nil, v_13291, v_13290);
    return onevalue(v_13290);
}



// Code for evgradlexcomp

static LispObject CC_evgradlexcomp(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13321, v_13322;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13239,v_13240);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_13240;
    stack[-2] = v_13239;
// end of prologue
v_13244:
    v_13321 = stack[-2];
    if (v_13321 == nil) goto v_13247;
    else goto v_13248;
v_13247:
    v_13321 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13243;
v_13248:
    v_13321 = stack[-1];
    if (v_13321 == nil) goto v_13251;
    else goto v_13252;
v_13251:
    v_13321 = elt(env, 1); // (0)
    stack[-1] = v_13321;
    goto v_13244;
v_13252:
    goto v_13262;
v_13258:
    v_13321 = stack[-2];
    v_13322 = qcar(v_13321);
    goto v_13259;
v_13260:
    v_13321 = stack[-1];
    v_13321 = qcar(v_13321);
    goto v_13261;
v_13262:
    goto v_13258;
v_13259:
    goto v_13260;
v_13261:
    fn = elt(env, 2); // iequal
    v_13321 = (*qfn2(fn))(fn, v_13322, v_13321);
    env = stack[-4];
    if (v_13321 == nil) goto v_13256;
    v_13321 = stack[-2];
    v_13321 = qcdr(v_13321);
    stack[-2] = v_13321;
    v_13321 = stack[-1];
    v_13321 = qcdr(v_13321);
    stack[-1] = v_13321;
    goto v_13244;
v_13256:
    v_13321 = stack[-2];
    fn = elt(env, 3); // evtdeg
    stack[0] = (*qfn1(fn))(fn, v_13321);
    env = stack[-4];
    v_13321 = stack[-1];
    fn = elt(env, 3); // evtdeg
    v_13321 = (*qfn1(fn))(fn, v_13321);
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v_13321;
    goto v_13288;
v_13284:
    v_13322 = stack[-3];
    goto v_13285;
v_13286:
    v_13321 = stack[0];
    goto v_13287;
v_13288:
    goto v_13284;
v_13285:
    goto v_13286;
v_13287:
    fn = elt(env, 2); // iequal
    v_13321 = (*qfn2(fn))(fn, v_13322, v_13321);
    if (v_13321 == nil) goto v_13282;
    goto v_13299;
v_13295:
    v_13321 = stack[-2];
    v_13322 = qcar(v_13321);
    goto v_13296;
v_13297:
    v_13321 = stack[-1];
    v_13321 = qcar(v_13321);
    goto v_13298;
v_13299:
    goto v_13295;
v_13296:
    goto v_13297;
v_13298:
    if (((intptr_t)(v_13322)) > ((intptr_t)(v_13321))) goto v_13293;
    else goto v_13294;
v_13293:
    v_13321 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13292;
v_13294:
    v_13321 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_13292;
    v_13321 = nil;
v_13292:
    goto v_13280;
v_13282:
    goto v_13314;
v_13310:
    v_13322 = stack[-3];
    goto v_13311;
v_13312:
    v_13321 = stack[0];
    goto v_13313;
v_13314:
    goto v_13310;
v_13311:
    goto v_13312;
v_13313:
    if (((intptr_t)(v_13322)) > ((intptr_t)(v_13321))) goto v_13308;
    else goto v_13309;
v_13308:
    v_13321 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13280;
v_13309:
    v_13321 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_13280;
    v_13321 = nil;
v_13280:
    goto v_13243;
    v_13321 = nil;
v_13243:
    return onevalue(v_13321);
}



// Code for wedgek2

static LispObject CC_wedgek2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13470, v_13471, v_13472;
    LispObject fn;
    LispObject v_13241, v_13240, v_13239;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "wedgek2");
    va_start(aa, nargs);
    v_13239 = va_arg(aa, LispObject);
    v_13240 = va_arg(aa, LispObject);
    v_13241 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13241,v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13239,v_13240,v_13241);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_13241;
    stack[-3] = v_13240;
    stack[-4] = v_13239;
// end of prologue
v_13245:
    goto v_13258;
v_13254:
    v_13471 = stack[-4];
    goto v_13255;
v_13256:
    v_13470 = stack[-3];
    v_13470 = qcar(v_13470);
    goto v_13257;
v_13258:
    goto v_13254;
v_13255:
    goto v_13256;
v_13257:
    if (v_13471 == v_13470) goto v_13252;
    else goto v_13253;
v_13252:
    goto v_13267;
v_13263:
    v_13471 = stack[-4];
    goto v_13264;
v_13265:
    v_13470 = elt(env, 1); // wedge
    goto v_13266;
v_13267:
    goto v_13263;
v_13264:
    goto v_13265;
v_13266:
    v_13470 = Leqcar(nil, v_13471, v_13470);
    env = stack[-6];
    v_13470 = (v_13470 == nil ? lisp_true : nil);
    goto v_13251;
v_13253:
    v_13470 = nil;
    goto v_13251;
    v_13470 = nil;
v_13251:
    if (v_13470 == nil) goto v_13249;
    v_13470 = stack[-4];
    fn = elt(env, 2); // deg!*form
    v_13470 = (*qfn1(fn))(fn, v_13470);
    env = stack[-6];
    v_13471 = v_13470;
    v_13470 = v_13471;
    v_13470 = integerp(v_13470);
    if (v_13470 == nil) goto v_13283;
    else goto v_13284;
v_13283:
    v_13470 = nil;
    goto v_13282;
v_13284:
    v_13470 = v_13471;
    v_13470 = Loddp(nil, v_13470);
    env = stack[-6];
    goto v_13282;
    v_13470 = nil;
v_13282:
    if (v_13470 == nil) goto v_13277;
    v_13470 = nil;
    goto v_13244;
v_13277:
    goto v_13300;
v_13296:
    goto v_13307;
v_13303:
    v_13471 = stack[-4];
    goto v_13304;
v_13305:
    v_13470 = stack[-3];
    goto v_13306;
v_13307:
    goto v_13303;
v_13304:
    goto v_13305;
v_13306:
    v_13470 = cons(v_13471, v_13470);
    env = stack[-6];
    fn = elt(env, 3); // wedgef
    stack[0] = (*qfn1(fn))(fn, v_13470);
    env = stack[-6];
    goto v_13297;
v_13298:
    v_13470 = stack[-2];
    fn = elt(env, 4); // mksgnsq
    v_13470 = (*qfn1(fn))(fn, v_13470);
    env = stack[-6];
    goto v_13299;
v_13300:
    goto v_13296;
v_13297:
    goto v_13298;
v_13299:
    {
        LispObject v_13479 = stack[0];
        fn = elt(env, 5); // multpfsq
        return (*qfn2(fn))(fn, v_13479, v_13470);
    }
    goto v_13247;
v_13249:
    goto v_13319;
v_13315:
    v_13470 = stack[-3];
    v_13471 = qcar(v_13470);
    goto v_13316;
v_13317:
    v_13470 = elt(env, 1); // wedge
    goto v_13318;
v_13319:
    goto v_13315;
v_13316:
    goto v_13317;
v_13318:
    if (!consp(v_13471)) goto v_13313;
    v_13471 = qcar(v_13471);
    if (v_13471 == v_13470) goto v_13312;
    else goto v_13313;
v_13312:
    v_13470 = stack[-3];
    v_13470 = qcar(v_13470);
    v_13470 = qcdr(v_13470);
    stack[-3] = v_13470;
    goto v_13245;
v_13313:
    goto v_13333;
v_13329:
    v_13471 = stack[-4];
    goto v_13330;
v_13331:
    v_13470 = elt(env, 1); // wedge
    goto v_13332;
v_13333:
    goto v_13329;
v_13330:
    goto v_13331;
v_13332:
    if (!consp(v_13471)) goto v_13327;
    v_13471 = qcar(v_13471);
    if (v_13471 == v_13470) goto v_13326;
    else goto v_13327;
v_13326:
    goto v_13341;
v_13337:
    goto v_13347;
v_13343:
    v_13470 = stack[-4];
    v_13471 = qcdr(v_13470);
    goto v_13344;
v_13345:
    v_13470 = stack[-3];
    goto v_13346;
v_13347:
    goto v_13343;
v_13344:
    goto v_13345;
v_13346:
    fn = elt(env, 6); // wedgewedge
    stack[0] = (*qfn2(fn))(fn, v_13471, v_13470);
    env = stack[-6];
    goto v_13338;
v_13339:
    v_13470 = stack[-2];
    fn = elt(env, 4); // mksgnsq
    v_13470 = (*qfn1(fn))(fn, v_13470);
    env = stack[-6];
    goto v_13340;
v_13341:
    goto v_13337;
v_13338:
    goto v_13339;
v_13340:
    {
        LispObject v_13480 = stack[0];
        fn = elt(env, 5); // multpfsq
        return (*qfn2(fn))(fn, v_13480, v_13470);
    }
v_13327:
    goto v_13360;
v_13356:
    v_13471 = stack[-4];
    goto v_13357;
v_13358:
    v_13470 = stack[-3];
    v_13470 = qcar(v_13470);
    goto v_13359;
v_13360:
    goto v_13356;
v_13357:
    goto v_13358;
v_13359:
    fn = elt(env, 7); // worderp
    v_13470 = (*qfn2(fn))(fn, v_13471, v_13470);
    env = stack[-6];
    if (v_13470 == nil) goto v_13354;
    goto v_13369;
v_13365:
    goto v_13376;
v_13372:
    v_13471 = stack[-4];
    goto v_13373;
v_13374:
    v_13470 = stack[-3];
    goto v_13375;
v_13376:
    goto v_13372;
v_13373:
    goto v_13374;
v_13375:
    v_13470 = cons(v_13471, v_13470);
    env = stack[-6];
    fn = elt(env, 3); // wedgef
    stack[0] = (*qfn1(fn))(fn, v_13470);
    env = stack[-6];
    goto v_13366;
v_13367:
    v_13470 = stack[-2];
    fn = elt(env, 4); // mksgnsq
    v_13470 = (*qfn1(fn))(fn, v_13470);
    env = stack[-6];
    goto v_13368;
v_13369:
    goto v_13365;
v_13366:
    goto v_13367;
v_13368:
    {
        LispObject v_13481 = stack[0];
        fn = elt(env, 5); // multpfsq
        return (*qfn2(fn))(fn, v_13481, v_13470);
    }
v_13354:
    v_13470 = stack[-3];
    v_13470 = qcdr(v_13470);
    if (v_13470 == nil) goto v_13382;
    goto v_13390;
v_13386:
    goto v_13399;
v_13393:
    v_13470 = stack[-3];
    v_13472 = qcar(v_13470);
    goto v_13394;
v_13395:
    v_13471 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13396;
v_13397:
    v_13470 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13398;
v_13399:
    goto v_13393;
v_13394:
    goto v_13395;
v_13396:
    goto v_13397;
v_13398:
    v_13470 = list2star(v_13472, v_13471, v_13470);
    env = stack[-6];
    stack[-5] = ncons(v_13470);
    env = stack[-6];
    goto v_13387;
v_13388:
    goto v_13411;
v_13405:
    stack[-1] = stack[-4];
    goto v_13406;
v_13407:
    v_13470 = stack[-3];
    stack[0] = qcdr(v_13470);
    goto v_13408;
v_13409:
    goto v_13420;
v_13416:
    goto v_13417;
v_13418:
    goto v_13427;
v_13423:
    v_13470 = stack[-4];
    fn = elt(env, 2); // deg!*form
    stack[-4] = (*qfn1(fn))(fn, v_13470);
    env = stack[-6];
    goto v_13424;
v_13425:
    v_13470 = stack[-3];
    v_13470 = qcar(v_13470);
    fn = elt(env, 2); // deg!*form
    v_13470 = (*qfn1(fn))(fn, v_13470);
    env = stack[-6];
    goto v_13426;
v_13427:
    goto v_13423;
v_13424:
    goto v_13425;
v_13426:
    fn = elt(env, 8); // multf
    v_13470 = (*qfn2(fn))(fn, stack[-4], v_13470);
    env = stack[-6];
    goto v_13419;
v_13420:
    goto v_13416;
v_13417:
    goto v_13418;
v_13419:
    fn = elt(env, 9); // addf
    v_13470 = (*qfn2(fn))(fn, stack[-2], v_13470);
    env = stack[-6];
    goto v_13410;
v_13411:
    goto v_13405;
v_13406:
    goto v_13407;
v_13408:
    goto v_13409;
v_13410:
    v_13470 = CC_wedgek2(elt(env, 0), 3, stack[-1], stack[0], v_13470);
    env = stack[-6];
    goto v_13389;
v_13390:
    goto v_13386;
v_13387:
    goto v_13388;
v_13389:
    {
        LispObject v_13482 = stack[-5];
        fn = elt(env, 10); // wedgepf2
        return (*qfn2(fn))(fn, v_13482, v_13470);
    }
v_13382:
    goto v_13440;
v_13436:
    goto v_13447;
v_13443:
    v_13470 = stack[-3];
    v_13471 = qcar(v_13470);
    goto v_13444;
v_13445:
    v_13470 = stack[-4];
    goto v_13446;
v_13447:
    goto v_13443;
v_13444:
    goto v_13445;
v_13446:
    v_13470 = list2(v_13471, v_13470);
    env = stack[-6];
    fn = elt(env, 3); // wedgef
    stack[0] = (*qfn1(fn))(fn, v_13470);
    env = stack[-6];
    goto v_13437;
v_13438:
    goto v_13457;
v_13453:
    stack[-1] = stack[-2];
    goto v_13454;
v_13455:
    goto v_13464;
v_13460:
    v_13470 = stack[-4];
    fn = elt(env, 2); // deg!*form
    stack[-2] = (*qfn1(fn))(fn, v_13470);
    env = stack[-6];
    goto v_13461;
v_13462:
    v_13470 = stack[-3];
    v_13470 = qcar(v_13470);
    fn = elt(env, 2); // deg!*form
    v_13470 = (*qfn1(fn))(fn, v_13470);
    env = stack[-6];
    goto v_13463;
v_13464:
    goto v_13460;
v_13461:
    goto v_13462;
v_13463:
    fn = elt(env, 8); // multf
    v_13470 = (*qfn2(fn))(fn, stack[-2], v_13470);
    env = stack[-6];
    goto v_13456;
v_13457:
    goto v_13453;
v_13454:
    goto v_13455;
v_13456:
    fn = elt(env, 9); // addf
    v_13470 = (*qfn2(fn))(fn, stack[-1], v_13470);
    env = stack[-6];
    fn = elt(env, 4); // mksgnsq
    v_13470 = (*qfn1(fn))(fn, v_13470);
    env = stack[-6];
    goto v_13439;
v_13440:
    goto v_13436;
v_13437:
    goto v_13438;
v_13439:
    {
        LispObject v_13483 = stack[0];
        fn = elt(env, 5); // multpfsq
        return (*qfn2(fn))(fn, v_13483, v_13470);
    }
v_13247:
    v_13470 = nil;
v_13244:
    return onevalue(v_13470);
}



// Code for physop2sq

static LispObject CC_physop2sq(LispObject env,
                         LispObject v_13239)
{
    env = qenv(env);
    LispObject v_13402, v_13403;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13239);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13239;
// end of prologue
v_13238:
    v_13402 = stack[0];
    fn = elt(env, 3); // physopp
    v_13402 = (*qfn1(fn))(fn, v_13402);
    env = stack[-2];
    if (v_13402 == nil) goto v_13247;
    v_13402 = stack[0];
    if (!symbolp(v_13402)) v_13402 = nil;
    else { v_13402 = qfastgets(v_13402);
           if (v_13402 != nil) { v_13402 = elt(v_13402, 46); // rvalue
#ifdef RECORD_GET
             if (v_13402 != SPID_NOPROP)
                record_get(elt(fastget_names, 46), 1);
             else record_get(elt(fastget_names, 46), 0),
                v_13402 = nil; }
           else record_get(elt(fastget_names, 46), 0); }
#else
             if (v_13402 == SPID_NOPROP) v_13402 = nil; }}
#endif
    stack[-1] = v_13402;
    if (v_13402 == nil) goto v_13253;
    v_13402 = stack[-1];
    stack[0] = v_13402;
    goto v_13238;
v_13253:
    v_13402 = stack[0];
    if (symbolp(v_13402)) goto v_13258;
    else goto v_13259;
v_13258:
    goto v_13266;
v_13262:
    goto v_13273;
v_13269:
    goto v_13279;
v_13275:
    v_13403 = stack[0];
    goto v_13276;
v_13277:
    v_13402 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13278;
v_13279:
    goto v_13275;
v_13276:
    goto v_13277;
v_13278:
    fn = elt(env, 4); // to
    v_13403 = (*qfn2(fn))(fn, v_13403, v_13402);
    env = stack[-2];
    goto v_13270;
v_13271:
    v_13402 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13272;
v_13273:
    goto v_13269;
v_13270:
    goto v_13271;
v_13272:
    v_13402 = cons(v_13403, v_13402);
    env = stack[-2];
    v_13403 = ncons(v_13402);
    goto v_13263;
v_13264:
    v_13402 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13265;
v_13266:
    goto v_13262;
v_13263:
    goto v_13264;
v_13265:
    return cons(v_13403, v_13402);
v_13259:
    goto v_13291;
v_13287:
    v_13402 = stack[0];
    v_13403 = qcar(v_13402);
    goto v_13288;
v_13289:
    v_13402 = elt(env, 1); // psimpfn
    goto v_13290;
v_13291:
    goto v_13287;
v_13288:
    goto v_13289;
v_13290:
    v_13402 = get(v_13403, v_13402);
    env = stack[-2];
    stack[-1] = v_13402;
    if (v_13402 == nil) goto v_13285;
    goto v_13305;
v_13301:
    v_13403 = stack[-1];
    goto v_13302;
v_13303:
    v_13402 = stack[0];
    goto v_13304;
v_13305:
    goto v_13301;
v_13302:
    goto v_13303;
v_13304:
    v_13402 = Lapply1(nil, v_13403, v_13402);
    env = stack[-2];
    stack[-1] = v_13402;
    fn = elt(env, 3); // physopp
    v_13402 = (*qfn1(fn))(fn, v_13402);
    env = stack[-2];
    if (v_13402 == nil) goto v_13298;
    goto v_13313;
v_13309:
    goto v_13320;
v_13316:
    goto v_13326;
v_13322:
    v_13403 = stack[-1];
    goto v_13323;
v_13324:
    v_13402 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13325;
v_13326:
    goto v_13322;
v_13323:
    goto v_13324;
v_13325:
    fn = elt(env, 4); // to
    v_13403 = (*qfn2(fn))(fn, v_13403, v_13402);
    env = stack[-2];
    goto v_13317;
v_13318:
    v_13402 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13319;
v_13320:
    goto v_13316;
v_13317:
    goto v_13318;
v_13319:
    v_13402 = cons(v_13403, v_13402);
    env = stack[-2];
    v_13403 = ncons(v_13402);
    goto v_13310;
v_13311:
    v_13402 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13312;
v_13313:
    goto v_13309;
v_13310:
    goto v_13311;
v_13312:
    return cons(v_13403, v_13402);
v_13298:
    v_13402 = stack[-1];
    fn = elt(env, 5); // physopsm!*
    v_13402 = (*qfn1(fn))(fn, v_13402);
    v_13402 = qcdr(v_13402);
    v_13402 = qcar(v_13402);
    goto v_13296;
    v_13402 = nil;
v_13296:
    goto v_13251;
v_13285:
    v_13402 = stack[0];
    v_13402 = qcar(v_13402);
    if (!symbolp(v_13402)) v_13402 = nil;
    else { v_13402 = qfastgets(v_13402);
           if (v_13402 != nil) { v_13402 = elt(v_13402, 9); // opmtch
#ifdef RECORD_GET
             if (v_13402 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_13402 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_13402 == SPID_NOPROP) v_13402 = nil; }}
#endif
    if (v_13402 == nil) goto v_13338;
    v_13402 = stack[0];
    fn = elt(env, 6); // opmtch!*
    v_13402 = (*qfn1(fn))(fn, v_13402);
    env = stack[-2];
    stack[-1] = v_13402;
    if (v_13402 == nil) goto v_13338;
    v_13402 = stack[-1];
    stack[0] = v_13402;
    goto v_13238;
v_13338:
    goto v_13355;
v_13351:
    goto v_13362;
v_13358:
    goto v_13368;
v_13364:
    v_13403 = stack[0];
    goto v_13365;
v_13366:
    v_13402 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13367;
v_13368:
    goto v_13364;
v_13365:
    goto v_13366;
v_13367:
    fn = elt(env, 4); // to
    v_13403 = (*qfn2(fn))(fn, v_13403, v_13402);
    env = stack[-2];
    goto v_13359;
v_13360:
    v_13402 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13361;
v_13362:
    goto v_13358;
v_13359:
    goto v_13360;
v_13361:
    v_13402 = cons(v_13403, v_13402);
    env = stack[-2];
    v_13403 = ncons(v_13402);
    goto v_13352;
v_13353:
    v_13402 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13354;
v_13355:
    goto v_13351;
v_13352:
    goto v_13353;
v_13354:
    return cons(v_13403, v_13402);
    v_13402 = nil;
v_13251:
    goto v_13245;
v_13247:
    v_13402 = stack[0];
    if (!consp(v_13402)) goto v_13373;
    else goto v_13374;
v_13373:
    v_13402 = stack[0];
    {
        fn = elt(env, 7); // simp
        return (*qfn1(fn))(fn, v_13402);
    }
v_13374:
    goto v_13384;
v_13380:
    v_13402 = stack[0];
    v_13403 = qcar(v_13402);
    goto v_13381;
v_13382:
    v_13402 = elt(env, 2); // !*sq
    goto v_13383;
v_13384:
    goto v_13380;
v_13381:
    goto v_13382;
v_13383:
    if (v_13403 == v_13402) goto v_13378;
    else goto v_13379;
v_13378:
    v_13402 = stack[0];
    v_13402 = qcdr(v_13402);
    v_13402 = qcar(v_13402);
    goto v_13245;
v_13379:
    v_13402 = stack[0];
    fn = elt(env, 8); // getphystype
    v_13402 = (*qfn1(fn))(fn, v_13402);
    env = stack[-2];
    if (v_13402 == nil) goto v_13391;
    else goto v_13392;
v_13391:
    v_13402 = stack[0];
    {
        fn = elt(env, 7); // simp
        return (*qfn1(fn))(fn, v_13402);
    }
v_13392:
    v_13402 = stack[0];
    fn = elt(env, 5); // physopsm!*
    v_13402 = (*qfn1(fn))(fn, v_13402);
    env = stack[-2];
    stack[0] = v_13402;
    goto v_13238;
    v_13402 = nil;
v_13245:
    return onevalue(v_13402);
}



// Code for def_edge

static LispObject CC_def_edge(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13271, v_13272, v_13273, v_13274;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13273 = v_13240;
    v_13271 = v_13239;
// end of prologue
    v_13271 = qcdr(v_13271);
    v_13271 = qcar(v_13271);
    v_13274 = v_13271;
    goto v_13254;
v_13250:
    v_13271 = v_13274;
    v_13272 = qcar(v_13271);
    goto v_13251;
v_13252:
    v_13271 = v_13273;
    goto v_13253;
v_13254:
    goto v_13250;
v_13251:
    goto v_13252;
v_13253:
    v_13271 = Lassoc(nil, v_13272, v_13271);
    if (v_13271 == nil) goto v_13248;
    else goto v_13249;
v_13248:
    v_13271 = nil;
    goto v_13247;
v_13249:
    goto v_13266;
v_13262:
    v_13271 = v_13274;
    v_13271 = qcdr(v_13271);
    goto v_13263;
v_13264:
    v_13272 = v_13273;
    goto v_13265;
v_13266:
    goto v_13262;
v_13263:
    goto v_13264;
v_13265:
    v_13271 = Lassoc(nil, v_13271, v_13272);
    goto v_13247;
    v_13271 = nil;
v_13247:
    return onevalue(v_13271);
}



// Code for setel1

static LispObject CC_setel1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13327, v_13328, v_13329;
    LispObject fn;
    LispObject v_13242, v_13241, v_13240, v_13239;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "setel1");
    va_start(aa, nargs);
    v_13239 = va_arg(aa, LispObject);
    v_13240 = va_arg(aa, LispObject);
    v_13241 = va_arg(aa, LispObject);
    v_13242 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_13242,v_13241,v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_13239,v_13240,v_13241,v_13242);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_13242;
    stack[-1] = v_13241;
    stack[-2] = v_13240;
    stack[-3] = v_13239;
// end of prologue
v_13246:
    v_13327 = stack[-2];
    v_13327 = qcar(v_13327);
    v_13327 = integerp(v_13327);
    if (v_13327 == nil) goto v_13249;
    else goto v_13250;
v_13249:
    goto v_13259;
v_13255:
    v_13327 = stack[-2];
    v_13328 = qcar(v_13327);
    goto v_13256;
v_13257:
    v_13327 = elt(env, 1); // "array index"
    goto v_13258;
v_13259:
    goto v_13255;
v_13256:
    goto v_13257;
v_13258:
    {
        fn = elt(env, 4); // typerr
        return (*qfn2(fn))(fn, v_13328, v_13327);
    }
v_13250:
    goto v_13271;
v_13267:
    v_13327 = stack[-2];
    v_13328 = qcar(v_13327);
    goto v_13268;
v_13269:
    v_13327 = stack[0];
    v_13327 = qcar(v_13327);
    goto v_13270;
v_13271:
    goto v_13267;
v_13268:
    goto v_13269;
v_13270:
    v_13327 = (LispObject)geq2(v_13328, v_13327);
    v_13327 = v_13327 ? lisp_true : nil;
    env = stack[-4];
    if (v_13327 == nil) goto v_13265;
    else goto v_13263;
v_13265:
    goto v_13282;
v_13278:
    v_13327 = stack[-2];
    v_13328 = qcar(v_13327);
    goto v_13279;
v_13280:
    v_13327 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13281;
v_13282:
    goto v_13278;
v_13279:
    goto v_13280;
v_13281:
    v_13327 = (LispObject)lessp2(v_13328, v_13327);
    v_13327 = v_13327 ? lisp_true : nil;
    env = stack[-4];
    if (v_13327 == nil) goto v_13276;
    else goto v_13263;
v_13276:
    goto v_13264;
v_13263:
    goto v_13293;
v_13287:
    v_13329 = elt(env, 2); // rlisp
    goto v_13288;
v_13289:
    v_13328 = (LispObject)368+TAG_FIXNUM; // 23
    goto v_13290;
v_13291:
    v_13327 = elt(env, 3); // "Array out of bounds"
    goto v_13292;
v_13293:
    goto v_13287;
v_13288:
    goto v_13289;
v_13290:
    goto v_13291;
v_13292:
    {
        fn = elt(env, 5); // rerror
        return (*qfnn(fn))(fn, 3, v_13329, v_13328, v_13327);
    }
v_13264:
    v_13327 = stack[-2];
    v_13327 = qcdr(v_13327);
    if (v_13327 == nil) goto v_13297;
    else goto v_13298;
v_13297:
    goto v_13307;
v_13301:
    v_13329 = stack[-3];
    goto v_13302;
v_13303:
    v_13327 = stack[-2];
    v_13328 = qcar(v_13327);
    goto v_13304;
v_13305:
    v_13327 = stack[-1];
    goto v_13306;
v_13307:
    goto v_13301;
v_13302:
    goto v_13303;
v_13304:
    goto v_13305;
v_13306:
    *(LispObject *)((char *)v_13329 + (CELL-TAG_VECTOR) + (((intptr_t)v_13328-TAG_FIXNUM)/(16/CELL))) = v_13327;
    goto v_13245;
v_13298:
    goto v_13318;
v_13314:
    v_13328 = stack[-3];
    goto v_13315;
v_13316:
    v_13327 = stack[-2];
    v_13327 = qcar(v_13327);
    goto v_13317;
v_13318:
    goto v_13314;
v_13315:
    goto v_13316;
v_13317:
    v_13327 = *(LispObject *)((char *)v_13328 + (CELL-TAG_VECTOR) + (((intptr_t)v_13327-TAG_FIXNUM)/(16/CELL)));
    stack[-3] = v_13327;
    v_13327 = stack[-2];
    v_13327 = qcdr(v_13327);
    stack[-2] = v_13327;
    v_13327 = stack[0];
    v_13327 = qcdr(v_13327);
    stack[0] = v_13327;
    goto v_13246;
    v_13327 = nil;
v_13245:
    return onevalue(v_13327);
}



// Code for simp!-prop!-order

static LispObject CC_simpKpropKorder(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13283, v_13284, v_13285, v_13286;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13284 = v_13240;
    v_13285 = v_13239;
// end of prologue
v_13244:
    v_13283 = v_13285;
    if (v_13283 == nil) goto v_13247;
    else goto v_13248;
v_13247:
    v_13283 = nil;
    goto v_13243;
v_13248:
    goto v_13257;
v_13253:
    v_13283 = v_13285;
    v_13283 = qcar(v_13283);
    v_13286 = qcar(v_13283);
    goto v_13254;
v_13255:
    v_13283 = v_13284;
    v_13283 = qcar(v_13283);
    v_13283 = qcar(v_13283);
    goto v_13256;
v_13257:
    goto v_13253;
v_13254:
    goto v_13255;
v_13256:
    if (equal(v_13286, v_13283)) goto v_13251;
    else goto v_13252;
v_13251:
    v_13283 = v_13285;
    v_13283 = qcdr(v_13283);
    v_13285 = v_13283;
    v_13283 = v_13284;
    v_13283 = qcdr(v_13283);
    v_13284 = v_13283;
    goto v_13244;
v_13252:
    goto v_13274;
v_13270:
    v_13283 = v_13285;
    v_13283 = qcar(v_13283);
    v_13283 = qcar(v_13283);
    goto v_13271;
v_13272:
    v_13284 = elt(env, 1); // prop!*
    goto v_13273;
v_13274:
    goto v_13270;
v_13271:
    goto v_13272;
v_13273:
    if (v_13283 == v_13284) goto v_13268;
    else goto v_13269;
v_13268:
    v_13283 = lisp_true;
    goto v_13243;
v_13269:
    v_13283 = nil;
    goto v_13243;
    v_13283 = nil;
v_13243:
    return onevalue(v_13283);
}



// Code for p_prinl2

static LispObject CC_p_prinl2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13730, v_13731, v_13732, v_13733;
    LispObject fn;
    LispObject v_13242, v_13241, v_13240, v_13239;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "p_prinl2");
    va_start(aa, nargs);
    v_13239 = va_arg(aa, LispObject);
    v_13240 = va_arg(aa, LispObject);
    v_13241 = va_arg(aa, LispObject);
    v_13242 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_13242,v_13241,v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_13239,v_13240,v_13241,v_13242);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-2] = v_13242;
    stack[-4] = v_13241;
    stack[-5] = v_13240;
    stack[-6] = v_13239;
// end of prologue
    v_13730 = qvalue(elt(env, 1)); // !*print!-level!*
    v_13730 = integerp(v_13730);
    if (v_13730 == nil) goto v_13247;
    goto v_13257;
v_13253:
    v_13731 = stack[-5];
    goto v_13254;
v_13255:
    v_13730 = qvalue(elt(env, 1)); // !*print!-level!*
    goto v_13256;
v_13257:
    goto v_13253;
v_13254:
    goto v_13255;
v_13256:
    v_13730 = (LispObject)greaterp2(v_13731, v_13730);
    v_13730 = v_13730 ? lisp_true : nil;
    env = stack[-8];
    if (v_13730 == nil) goto v_13247;
    goto v_13265;
v_13261:
    v_13731 = elt(env, 2); // "#"
    goto v_13262;
v_13263:
    v_13730 = stack[-2];
    goto v_13264;
v_13265:
    goto v_13261;
v_13262:
    goto v_13263;
v_13264:
    {
        fn = elt(env, 12); // p_princ
        return (*qfn2(fn))(fn, v_13731, v_13730);
    }
v_13247:
    v_13730 = stack[-6];
    if (!consp(v_13730)) goto v_13272;
    else goto v_13273;
v_13272:
    v_13730 = stack[-6];
    v_13730 = Lsimple_vectorp(nil, v_13730);
    env = stack[-8];
    if (v_13730 == nil) goto v_13277;
    else goto v_13278;
v_13277:
    v_13730 = stack[-6];
    fn = elt(env, 13); // gensymp
    v_13730 = (*qfn1(fn))(fn, v_13730);
    env = stack[-8];
    v_13730 = (v_13730 == nil ? lisp_true : nil);
    goto v_13276;
v_13278:
    v_13730 = nil;
    goto v_13276;
    v_13730 = nil;
v_13276:
    goto v_13271;
v_13273:
    v_13730 = nil;
    goto v_13271;
    v_13730 = nil;
v_13271:
    if (v_13730 == nil) goto v_13269;
    v_13730 = stack[-4];
    if (v_13730 == nil) goto v_13293;
    goto v_13300;
v_13296:
    v_13731 = stack[-6];
    goto v_13297;
v_13298:
    v_13730 = stack[-2];
    goto v_13299;
v_13300:
    goto v_13296;
v_13297:
    goto v_13298;
v_13299:
    {
        fn = elt(env, 14); // p_prin
        return (*qfn2(fn))(fn, v_13731, v_13730);
    }
v_13293:
    goto v_13310;
v_13306:
    v_13731 = stack[-6];
    goto v_13307;
v_13308:
    v_13730 = stack[-2];
    goto v_13309;
v_13310:
    goto v_13306;
v_13307:
    goto v_13308;
v_13309:
    {
        fn = elt(env, 12); // p_princ
        return (*qfn2(fn))(fn, v_13731, v_13730);
    }
    v_13730 = nil;
    goto v_13245;
v_13269:
    goto v_13325;
v_13321:
    v_13731 = stack[-6];
    goto v_13322;
v_13323:
    v_13730 = qvalue(elt(env, 3)); // !*prinl_visited_nodes!*
    goto v_13324;
v_13325:
    goto v_13321;
v_13322:
    goto v_13323;
v_13324:
    fn = elt(env, 15); // gethash
    v_13730 = (*qfn2(fn))(fn, v_13731, v_13730);
    env = stack[-8];
    stack[-1] = v_13730;
    v_13730 = stack[-1];
    if (v_13730 == nil) goto v_13331;
    v_13730 = stack[-1];
    v_13730 = (LispObject)zerop(v_13730);
    v_13730 = v_13730 ? lisp_true : nil;
    env = stack[-8];
    if (v_13730 == nil) goto v_13334;
    else goto v_13331;
v_13334:
    goto v_13346;
v_13342:
    v_13731 = stack[-1];
    goto v_13343;
v_13344:
    v_13730 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13345;
v_13346:
    goto v_13342;
v_13343:
    goto v_13344;
v_13345:
    v_13730 = (LispObject)lessp2(v_13731, v_13730);
    v_13730 = v_13730 ? lisp_true : nil;
    env = stack[-8];
    if (v_13730 == nil) goto v_13340;
    goto v_13356;
v_13350:
    v_13730 = stack[-1];
    v_13732 = negate(v_13730);
    env = stack[-8];
    goto v_13351;
v_13352:
    v_13731 = stack[-2];
    goto v_13353;
v_13354:
    v_13730 = elt(env, 2); // "#"
    goto v_13355;
v_13356:
    goto v_13350;
v_13351:
    goto v_13352;
v_13353:
    goto v_13354;
v_13355:
    fn = elt(env, 16); // p_printref
    v_13730 = (*qfnn(fn))(fn, 3, v_13732, v_13731, v_13730);
    v_13730 = nil;
    goto v_13318;
v_13340:
    goto v_13371;
v_13365:
    stack[-3] = stack[-6];
    goto v_13366;
v_13367:
    stack[0] = qvalue(elt(env, 3)); // !*prinl_visited_nodes!*
    goto v_13368;
v_13369:
    v_13730 = stack[-1];
    v_13730 = negate(v_13730);
    env = stack[-8];
    goto v_13370;
v_13371:
    goto v_13365;
v_13366:
    goto v_13367;
v_13368:
    goto v_13369;
v_13370:
    fn = elt(env, 17); // puthash
    v_13730 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_13730);
    env = stack[-8];
    goto v_13383;
v_13377:
    v_13732 = stack[-1];
    goto v_13378;
v_13379:
    v_13731 = stack[-2];
    goto v_13380;
v_13381:
    v_13730 = elt(env, 4); // "="
    goto v_13382;
v_13383:
    goto v_13377;
v_13378:
    goto v_13379;
v_13380:
    goto v_13381;
v_13382:
    fn = elt(env, 16); // p_printref
    v_13730 = (*qfnn(fn))(fn, 3, v_13732, v_13731, v_13730);
    env = stack[-8];
    v_13730 = nil;
    stack[-2] = v_13730;
    goto v_13338;
v_13338:
    goto v_13329;
v_13331:
v_13329:
    v_13730 = stack[-6];
    v_13730 = Lsimple_vectorp(nil, v_13730);
    env = stack[-8];
    if (v_13730 == nil) goto v_13391;
    goto v_13399;
v_13395:
    v_13731 = elt(env, 5); // "%("
    goto v_13396;
v_13397:
    v_13730 = stack[-2];
    goto v_13398;
v_13399:
    goto v_13395;
v_13396:
    goto v_13397;
v_13398:
    fn = elt(env, 12); // p_princ
    v_13730 = (*qfn2(fn))(fn, v_13731, v_13730);
    env = stack[-8];
    v_13730 = qvalue(elt(env, 6)); // !*print!-array!*
    if (v_13730 == nil) goto v_13405;
    v_13730 = stack[-6];
    v_13730 = Lupbv(nil, v_13730);
    env = stack[-8];
    stack[-7] = v_13730;
    v_13730 = qvalue(elt(env, 7)); // !*print!-length!*
    v_13730 = integerp(v_13730);
    if (v_13730 == nil) goto v_13412;
    goto v_13422;
v_13418:
    v_13731 = qvalue(elt(env, 7)); // !*print!-length!*
    goto v_13419;
v_13420:
    v_13730 = stack[-7];
    goto v_13421;
v_13422:
    goto v_13418;
v_13419:
    goto v_13420;
v_13421:
    v_13730 = (LispObject)lessp2(v_13731, v_13730);
    v_13730 = v_13730 ? lisp_true : nil;
    env = stack[-8];
    if (v_13730 == nil) goto v_13412;
    v_13730 = qvalue(elt(env, 7)); // !*print!-length!*
    stack[-7] = v_13730;
    goto v_13410;
v_13412:
v_13410:
    v_13730 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_13730;
v_13429:
    goto v_13441;
v_13437:
    v_13731 = stack[-7];
    goto v_13438;
v_13439:
    v_13730 = stack[-3];
    goto v_13440;
v_13441:
    goto v_13437;
v_13438:
    goto v_13439;
v_13440:
    v_13730 = difference2(v_13731, v_13730);
    env = stack[-8];
    v_13730 = Lminusp(nil, v_13730);
    env = stack[-8];
    if (v_13730 == nil) goto v_13434;
    goto v_13428;
v_13434:
    goto v_13454;
v_13446:
    goto v_13459;
v_13455:
    v_13731 = stack[-6];
    goto v_13456;
v_13457:
    v_13730 = stack[-3];
    goto v_13458;
v_13459:
    goto v_13455;
v_13456:
    goto v_13457;
v_13458:
    stack[-2] = *(LispObject *)((char *)v_13731 + (CELL-TAG_VECTOR) + (((intptr_t)v_13730-TAG_FIXNUM)/(16/CELL)));
    goto v_13447;
v_13448:
    v_13730 = stack[-5];
    stack[-1] = add1(v_13730);
    env = stack[-8];
    goto v_13449;
v_13450:
    stack[0] = stack[-4];
    goto v_13451;
v_13452:
    goto v_13471;
v_13467:
    v_13731 = stack[-3];
    goto v_13468;
v_13469:
    v_13730 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13470;
v_13471:
    goto v_13467;
v_13468:
    goto v_13469;
v_13470:
    v_13730 = Lneq(nil, v_13731, v_13730);
    env = stack[-8];
    goto v_13453;
v_13454:
    goto v_13446;
v_13447:
    goto v_13448;
v_13449:
    goto v_13450;
v_13451:
    goto v_13452;
v_13453:
    v_13730 = CC_p_prinl2(elt(env, 0), 4, stack[-2], stack[-1], stack[0], v_13730);
    env = stack[-8];
    v_13730 = stack[-3];
    v_13730 = add1(v_13730);
    env = stack[-8];
    stack[-3] = v_13730;
    goto v_13429;
v_13428:
    goto v_13403;
v_13405:
    goto v_13483;
v_13479:
    v_13731 = elt(env, 8); // "..."
    goto v_13480;
v_13481:
    v_13730 = nil;
    goto v_13482;
v_13483:
    goto v_13479;
v_13480:
    goto v_13481;
v_13482:
    fn = elt(env, 12); // p_princ
    v_13730 = (*qfn2(fn))(fn, v_13731, v_13730);
    env = stack[-8];
    goto v_13403;
v_13403:
    goto v_13491;
v_13487:
    v_13731 = elt(env, 9); // ")"
    goto v_13488;
v_13489:
    v_13730 = nil;
    goto v_13490;
v_13491:
    goto v_13487;
v_13488:
    goto v_13489;
v_13490:
    fn = elt(env, 12); // p_princ
    v_13730 = (*qfn2(fn))(fn, v_13731, v_13730);
    v_13730 = nil;
    goto v_13318;
v_13391:
    v_13730 = stack[-6];
    if (!consp(v_13730)) goto v_13495;
    else goto v_13496;
v_13495:
    v_13730 = stack[-4];
    if (v_13730 == nil) goto v_13501;
    goto v_13508;
v_13504:
    v_13731 = stack[-6];
    goto v_13505;
v_13506:
    v_13730 = stack[-2];
    goto v_13507;
v_13508:
    goto v_13504;
v_13505:
    goto v_13506;
v_13507:
    fn = elt(env, 14); // p_prin
    v_13730 = (*qfn2(fn))(fn, v_13731, v_13730);
    goto v_13499;
v_13501:
    goto v_13518;
v_13514:
    v_13731 = stack[-6];
    goto v_13515;
v_13516:
    v_13730 = stack[-2];
    goto v_13517;
v_13518:
    goto v_13514;
v_13515:
    goto v_13516;
v_13517:
    fn = elt(env, 12); // p_princ
    v_13730 = (*qfn2(fn))(fn, v_13731, v_13730);
    goto v_13499;
v_13499:
    v_13730 = nil;
    goto v_13318;
v_13496:
    goto v_13527;
v_13523:
    v_13731 = elt(env, 10); // "("
    goto v_13524;
v_13525:
    v_13730 = stack[-2];
    goto v_13526;
v_13527:
    goto v_13523;
v_13524:
    goto v_13525;
v_13526:
    fn = elt(env, 12); // p_princ
    v_13730 = (*qfn2(fn))(fn, v_13731, v_13730);
    env = stack[-8];
    goto v_13539;
v_13531:
    v_13730 = stack[-6];
    stack[0] = qcar(v_13730);
    goto v_13532;
v_13533:
    v_13730 = stack[-5];
    v_13732 = add1(v_13730);
    env = stack[-8];
    goto v_13534;
v_13535:
    v_13731 = stack[-4];
    goto v_13536;
v_13537:
    v_13730 = nil;
    goto v_13538;
v_13539:
    goto v_13531;
v_13532:
    goto v_13533;
v_13534:
    goto v_13535;
v_13536:
    goto v_13537;
v_13538:
    v_13730 = CC_p_prinl2(elt(env, 0), 4, stack[0], v_13732, v_13731, v_13730);
    env = stack[-8];
    v_13730 = stack[-6];
    v_13730 = qcdr(v_13730);
    stack[-6] = v_13730;
    v_13730 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_13730;
v_13319:
    v_13730 = stack[-6];
    if (!consp(v_13730)) goto v_13551;
    else goto v_13552;
v_13551:
    v_13730 = stack[-6];
    if (v_13730 == nil) goto v_13557;
    goto v_13564;
v_13560:
    v_13731 = elt(env, 11); // "."
    goto v_13561;
v_13562:
    v_13730 = lisp_true;
    goto v_13563;
v_13564:
    goto v_13560;
v_13561:
    goto v_13562;
v_13563:
    fn = elt(env, 12); // p_princ
    v_13730 = (*qfn2(fn))(fn, v_13731, v_13730);
    env = stack[-8];
    goto v_13576;
v_13568:
    v_13733 = stack[-6];
    goto v_13569;
v_13570:
    v_13732 = stack[-5];
    goto v_13571;
v_13572:
    v_13731 = stack[-4];
    goto v_13573;
v_13574:
    v_13730 = lisp_true;
    goto v_13575;
v_13576:
    goto v_13568;
v_13569:
    goto v_13570;
v_13571:
    goto v_13572;
v_13573:
    goto v_13574;
v_13575:
    v_13730 = CC_p_prinl2(elt(env, 0), 4, v_13733, v_13732, v_13731, v_13730);
    env = stack[-8];
    goto v_13555;
v_13557:
v_13555:
    goto v_13586;
v_13582:
    v_13731 = elt(env, 9); // ")"
    goto v_13583;
v_13584:
    v_13730 = nil;
    goto v_13585;
v_13586:
    goto v_13582;
v_13583:
    goto v_13584;
v_13585:
    {
        fn = elt(env, 12); // p_princ
        return (*qfn2(fn))(fn, v_13731, v_13730);
    }
v_13552:
    v_13730 = qvalue(elt(env, 7)); // !*print!-length!*
    v_13730 = integerp(v_13730);
    if (v_13730 == nil) goto v_13592;
    goto v_13602;
v_13598:
    v_13730 = stack[-7];
    v_13731 = add1(v_13730);
    env = stack[-8];
    stack[-7] = v_13731;
    goto v_13599;
v_13600:
    v_13730 = qvalue(elt(env, 7)); // !*print!-length!*
    goto v_13601;
v_13602:
    goto v_13598;
v_13599:
    goto v_13600;
v_13601:
    v_13730 = (LispObject)greaterp2(v_13731, v_13730);
    v_13730 = v_13730 ? lisp_true : nil;
    env = stack[-8];
    if (v_13730 == nil) goto v_13592;
    goto v_13611;
v_13607:
    v_13731 = elt(env, 8); // "..."
    goto v_13608;
v_13609:
    v_13730 = lisp_true;
    goto v_13610;
v_13611:
    goto v_13607;
v_13608:
    goto v_13609;
v_13610:
    fn = elt(env, 12); // p_princ
    v_13730 = (*qfn2(fn))(fn, v_13731, v_13730);
    env = stack[-8];
    goto v_13619;
v_13615:
    v_13731 = elt(env, 9); // ")"
    goto v_13616;
v_13617:
    v_13730 = nil;
    goto v_13618;
v_13619:
    goto v_13615;
v_13616:
    goto v_13617;
v_13618:
    {
        fn = elt(env, 12); // p_princ
        return (*qfn2(fn))(fn, v_13731, v_13730);
    }
v_13592:
    goto v_13627;
v_13623:
    v_13731 = stack[-6];
    goto v_13624;
v_13625:
    v_13730 = qvalue(elt(env, 3)); // !*prinl_visited_nodes!*
    goto v_13626;
v_13627:
    goto v_13623;
v_13624:
    goto v_13625;
v_13626:
    fn = elt(env, 15); // gethash
    v_13730 = (*qfn2(fn))(fn, v_13731, v_13730);
    env = stack[-8];
    stack[-1] = v_13730;
    v_13730 = stack[-1];
    if (v_13730 == nil) goto v_13633;
    v_13730 = stack[-1];
    v_13730 = (LispObject)zerop(v_13730);
    v_13730 = v_13730 ? lisp_true : nil;
    env = stack[-8];
    if (v_13730 == nil) goto v_13636;
    else goto v_13633;
v_13636:
    goto v_13648;
v_13644:
    v_13731 = stack[-1];
    goto v_13645;
v_13646:
    v_13730 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13647;
v_13648:
    goto v_13644;
v_13645:
    goto v_13646;
v_13647:
    v_13730 = (LispObject)lessp2(v_13731, v_13730);
    v_13730 = v_13730 ? lisp_true : nil;
    env = stack[-8];
    if (v_13730 == nil) goto v_13642;
    goto v_13656;
v_13652:
    v_13731 = elt(env, 11); // "."
    goto v_13653;
v_13654:
    v_13730 = lisp_true;
    goto v_13655;
v_13656:
    goto v_13652;
v_13653:
    goto v_13654;
v_13655:
    fn = elt(env, 12); // p_princ
    v_13730 = (*qfn2(fn))(fn, v_13731, v_13730);
    env = stack[-8];
    goto v_13666;
v_13660:
    v_13730 = stack[-1];
    v_13732 = negate(v_13730);
    env = stack[-8];
    goto v_13661;
v_13662:
    v_13731 = lisp_true;
    goto v_13663;
v_13664:
    v_13730 = elt(env, 2); // "#"
    goto v_13665;
v_13666:
    goto v_13660;
v_13661:
    goto v_13662;
v_13663:
    goto v_13664;
v_13665:
    fn = elt(env, 16); // p_printref
    v_13730 = (*qfnn(fn))(fn, 3, v_13732, v_13731, v_13730);
    env = stack[-8];
    goto v_13676;
v_13672:
    v_13731 = elt(env, 9); // ")"
    goto v_13673;
v_13674:
    v_13730 = nil;
    goto v_13675;
v_13676:
    goto v_13672;
v_13673:
    goto v_13674;
v_13675:
    {
        fn = elt(env, 12); // p_princ
        return (*qfn2(fn))(fn, v_13731, v_13730);
    }
v_13642:
    goto v_13686;
v_13682:
    v_13731 = elt(env, 11); // "."
    goto v_13683;
v_13684:
    v_13730 = lisp_true;
    goto v_13685;
v_13686:
    goto v_13682;
v_13683:
    goto v_13684;
v_13685:
    fn = elt(env, 12); // p_princ
    v_13730 = (*qfn2(fn))(fn, v_13731, v_13730);
    env = stack[-8];
    goto v_13698;
v_13690:
    stack[0] = stack[-6];
    goto v_13691;
v_13692:
    v_13730 = stack[-5];
    v_13732 = add1(v_13730);
    env = stack[-8];
    goto v_13693;
v_13694:
    v_13731 = stack[-4];
    goto v_13695;
v_13696:
    v_13730 = lisp_true;
    goto v_13697;
v_13698:
    goto v_13690;
v_13691:
    goto v_13692;
v_13693:
    goto v_13694;
v_13695:
    goto v_13696;
v_13697:
    v_13730 = CC_p_prinl2(elt(env, 0), 4, stack[0], v_13732, v_13731, v_13730);
    env = stack[-8];
    goto v_13709;
v_13705:
    v_13731 = elt(env, 9); // ")"
    goto v_13706;
v_13707:
    v_13730 = nil;
    goto v_13708;
v_13709:
    goto v_13705;
v_13706:
    goto v_13707;
v_13708:
    {
        fn = elt(env, 12); // p_princ
        return (*qfn2(fn))(fn, v_13731, v_13730);
    }
    goto v_13631;
v_13633:
v_13631:
    goto v_13721;
v_13713:
    v_13730 = stack[-6];
    stack[0] = qcar(v_13730);
    goto v_13714;
v_13715:
    v_13730 = stack[-5];
    v_13732 = add1(v_13730);
    env = stack[-8];
    goto v_13716;
v_13717:
    v_13731 = stack[-4];
    goto v_13718;
v_13719:
    v_13730 = lisp_true;
    goto v_13720;
v_13721:
    goto v_13713;
v_13714:
    goto v_13715;
v_13716:
    goto v_13717;
v_13718:
    goto v_13719;
v_13720:
    v_13730 = CC_p_prinl2(elt(env, 0), 4, stack[0], v_13732, v_13731, v_13730);
    env = stack[-8];
    v_13730 = stack[-6];
    v_13730 = qcdr(v_13730);
    stack[-6] = v_13730;
    goto v_13319;
v_13318:
    goto v_13245;
    v_13730 = nil;
v_13245:
    return onevalue(v_13730);
}



// Code for squared!+matrix!+p

static LispObject CC_squaredLmatrixLp(LispObject env,
                         LispObject v_13239)
{
    env = qenv(env);
    LispObject v_13261;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13239);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13239;
// end of prologue
    v_13261 = stack[0];
    fn = elt(env, 1); // matrix!+p
    v_13261 = (*qfn1(fn))(fn, v_13261);
    env = stack[-2];
    if (v_13261 == nil) goto v_13246;
    goto v_13255;
v_13251:
    v_13261 = stack[0];
    fn = elt(env, 2); // get!+row!+nr
    stack[-1] = (*qfn1(fn))(fn, v_13261);
    env = stack[-2];
    goto v_13252;
v_13253:
    v_13261 = stack[0];
    fn = elt(env, 3); // get!+col!+nr
    v_13261 = (*qfn1(fn))(fn, v_13261);
    goto v_13254;
v_13255:
    goto v_13251;
v_13252:
    goto v_13253;
v_13254:
    if (equal(stack[-1], v_13261)) goto v_13250;
    else goto v_13246;
v_13250:
    v_13261 = lisp_true;
    goto v_13242;
v_13246:
    v_13261 = nil;
v_13242:
    return onevalue(v_13261);
}



// Code for rl_pnf

static LispObject CC_rl_pnf(LispObject env,
                         LispObject v_13239)
{
    env = qenv(env);
    LispObject v_13250;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13239);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_13250 = v_13239;
// end of prologue
    goto v_13246;
v_13242:
    stack[0] = qvalue(elt(env, 1)); // rl_pnf!*
    goto v_13243;
v_13244:
    v_13250 = ncons(v_13250);
    env = stack[-1];
    goto v_13245;
v_13246:
    goto v_13242;
v_13243:
    goto v_13244;
v_13245:
    {
        LispObject v_13252 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_13252, v_13250);
    }
}



// Code for qqe_eta!-in!-term

static LispObject CC_qqe_etaKinKterm(LispObject env,
                         LispObject v_13239)
{
    env = qenv(env);
    LispObject v_13315, v_13316;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13239);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13239;
// end of prologue
    v_13315 = nil;
    stack[-1] = v_13315;
    v_13315 = stack[0];
    if (!consp(v_13315)) goto v_13248;
    else goto v_13249;
v_13248:
    v_13315 = nil;
    goto v_13244;
v_13249:
    goto v_13258;
v_13254:
    v_13315 = stack[0];
    fn = elt(env, 2); // qqe_op
    v_13316 = (*qfn1(fn))(fn, v_13315);
    env = stack[-2];
    goto v_13255;
v_13256:
    v_13315 = elt(env, 1); // (lhead rhead)
    goto v_13257;
v_13258:
    goto v_13254;
v_13255:
    goto v_13256;
v_13257:
    v_13315 = Lmemq(nil, v_13316, v_13315);
    if (v_13315 == nil) goto v_13253;
    v_13315 = stack[0];
    {
        fn = elt(env, 3); // qqe_eta!-in!-term1
        return (*qfn1(fn))(fn, v_13315);
    }
v_13253:
    v_13315 = stack[0];
    v_13315 = qcdr(v_13315);
    stack[0] = v_13315;
v_13271:
    v_13315 = stack[0];
    if (v_13315 == nil) goto v_13274;
    v_13315 = stack[-1];
    if (v_13315 == nil) goto v_13278;
    else goto v_13274;
v_13278:
    goto v_13275;
v_13274:
    goto v_13270;
v_13275:
    v_13315 = stack[0];
    v_13315 = qcar(v_13315);
    if (!consp(v_13315)) goto v_13284;
    goto v_13295;
v_13291:
    v_13315 = stack[0];
    v_13315 = qcar(v_13315);
    fn = elt(env, 2); // qqe_op
    v_13316 = (*qfn1(fn))(fn, v_13315);
    env = stack[-2];
    goto v_13292;
v_13293:
    v_13315 = elt(env, 1); // (lhead rhead)
    goto v_13294;
v_13295:
    goto v_13291;
v_13292:
    goto v_13293;
v_13294:
    v_13315 = Lmemq(nil, v_13316, v_13315);
    if (v_13315 == nil) goto v_13290;
    v_13315 = stack[0];
    v_13315 = qcar(v_13315);
    fn = elt(env, 3); // qqe_eta!-in!-term1
    v_13315 = (*qfn1(fn))(fn, v_13315);
    env = stack[-2];
    stack[-1] = v_13315;
    goto v_13288;
v_13290:
    v_13315 = stack[0];
    v_13315 = qcar(v_13315);
    v_13315 = CC_qqe_etaKinKterm(elt(env, 0), v_13315);
    env = stack[-2];
    stack[-1] = v_13315;
    goto v_13288;
v_13288:
    goto v_13282;
v_13284:
v_13282:
    v_13315 = stack[0];
    v_13315 = qcdr(v_13315);
    stack[0] = v_13315;
    goto v_13271;
v_13270:
    v_13315 = stack[-1];
    goto v_13244;
    v_13315 = nil;
v_13244:
    return onevalue(v_13315);
}



// Code for ibalp_var!-unset

static LispObject CC_ibalp_varKunset(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13421, v_13422;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13239,v_13240);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_13240;
    stack[-4] = v_13239;
// end of prologue
    goto v_13252;
v_13248:
    v_13421 = stack[-4];
    v_13422 = qcdr(v_13421);
    goto v_13249;
v_13250:
    v_13421 = nil;
    goto v_13251;
v_13252:
    goto v_13248;
v_13249:
    goto v_13250;
v_13251:
    fn = elt(env, 1); // setcar
    v_13421 = (*qfn2(fn))(fn, v_13422, v_13421);
    env = stack[-6];
    goto v_13261;
v_13257:
    v_13421 = stack[-4];
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13422 = qcdr(v_13421);
    goto v_13258;
v_13259:
    v_13421 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_13260;
v_13261:
    goto v_13257;
v_13258:
    goto v_13259;
v_13260:
    fn = elt(env, 1); // setcar
    v_13421 = (*qfn2(fn))(fn, v_13422, v_13421);
    env = stack[-6];
    goto v_13275;
v_13271:
    v_13421 = stack[-4];
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13422 = qcdr(v_13421);
    goto v_13272;
v_13273:
    v_13421 = nil;
    goto v_13274;
v_13275:
    goto v_13271;
v_13272:
    goto v_13273;
v_13274:
    fn = elt(env, 1); // setcar
    v_13421 = (*qfn2(fn))(fn, v_13422, v_13421);
    env = stack[-6];
    v_13421 = stack[-4];
    v_13421 = qcar(v_13421);
    stack[-5] = v_13421;
    goto v_13296;
v_13292:
    v_13422 = stack[-3];
    goto v_13293;
v_13294:
    v_13421 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13295;
v_13296:
    goto v_13292;
v_13293:
    goto v_13294;
v_13295:
    v_13421 = Leqn(nil, v_13422, v_13421);
    env = stack[-6];
    if (v_13421 == nil) goto v_13290;
    v_13421 = stack[-4];
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcar(v_13421);
    goto v_13288;
v_13290:
    v_13421 = stack[-4];
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcar(v_13421);
    goto v_13288;
    v_13421 = nil;
v_13288:
    stack[-2] = v_13421;
v_13313:
    v_13421 = stack[-2];
    if (v_13421 == nil) goto v_13317;
    else goto v_13318;
v_13317:
    goto v_13312;
v_13318:
    v_13421 = stack[-2];
    v_13421 = qcar(v_13421);
    stack[-1] = v_13421;
    goto v_13333;
v_13329:
    v_13422 = stack[-3];
    goto v_13330;
v_13331:
    v_13421 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13332;
v_13333:
    goto v_13329;
v_13330:
    goto v_13331;
v_13332:
    v_13421 = Leqn(nil, v_13422, v_13421);
    env = stack[-6];
    if (v_13421 == nil) goto v_13327;
    goto v_13341;
v_13337:
    v_13421 = stack[-1];
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    stack[0] = qcdr(v_13421);
    goto v_13338;
v_13339:
    v_13421 = stack[-1];
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcar(v_13421);
    v_13421 = add1(v_13421);
    env = stack[-6];
    goto v_13340;
v_13341:
    goto v_13337;
v_13338:
    goto v_13339;
v_13340:
    fn = elt(env, 1); // setcar
    v_13421 = (*qfn2(fn))(fn, stack[0], v_13421);
    env = stack[-6];
    goto v_13325;
v_13327:
    goto v_13359;
v_13355:
    v_13421 = stack[-1];
    v_13421 = qcdr(v_13421);
    stack[0] = qcdr(v_13421);
    goto v_13356;
v_13357:
    v_13421 = stack[-1];
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcar(v_13421);
    v_13421 = add1(v_13421);
    env = stack[-6];
    goto v_13358;
v_13359:
    goto v_13355;
v_13356:
    goto v_13357;
v_13358:
    fn = elt(env, 1); // setcar
    v_13421 = (*qfn2(fn))(fn, stack[0], v_13421);
    env = stack[-6];
    goto v_13325;
v_13325:
    v_13421 = stack[-2];
    v_13421 = qcdr(v_13421);
    stack[-2] = v_13421;
    goto v_13313;
v_13312:
    goto v_13379;
v_13375:
    v_13422 = stack[-3];
    goto v_13376;
v_13377:
    v_13421 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13378;
v_13379:
    goto v_13375;
v_13376:
    goto v_13377;
v_13378:
    v_13421 = Leqn(nil, v_13422, v_13421);
    env = stack[-6];
    if (v_13421 == nil) goto v_13373;
    v_13421 = stack[-4];
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcar(v_13421);
    goto v_13371;
v_13373:
    v_13421 = stack[-4];
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcar(v_13421);
    goto v_13371;
    v_13421 = nil;
v_13371:
    goto v_13398;
v_13394:
    v_13422 = v_13421;
    goto v_13395;
v_13396:
    v_13421 = stack[-5];
    goto v_13397;
v_13398:
    goto v_13394;
v_13395:
    goto v_13396;
v_13397:
    fn = elt(env, 2); // ibalp_unvar!-unsatlist
    v_13421 = (*qfn2(fn))(fn, v_13422, v_13421);
    env = stack[-6];
    goto v_13406;
v_13402:
    v_13421 = stack[-4];
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    v_13421 = qcdr(v_13421);
    stack[0] = qcdr(v_13421);
    goto v_13403;
v_13404:
    v_13421 = stack[-4];
    fn = elt(env, 3); // ibalp_calcmom
    v_13421 = (*qfn1(fn))(fn, v_13421);
    env = stack[-6];
    goto v_13405;
v_13406:
    goto v_13402;
v_13403:
    goto v_13404;
v_13405:
    fn = elt(env, 1); // setcar
    v_13421 = (*qfn2(fn))(fn, stack[0], v_13421);
    v_13421 = nil;
    return onevalue(v_13421);
}



// Code for ev_lexcomp

static LispObject CC_ev_lexcomp(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13282, v_13283;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13239,v_13240);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13240;
    stack[-1] = v_13239;
// end of prologue
v_13244:
    v_13282 = stack[-1];
    if (v_13282 == nil) goto v_13247;
    else goto v_13248;
v_13247:
    v_13282 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13243;
v_13248:
    goto v_13258;
v_13254:
    v_13282 = stack[-1];
    v_13283 = qcar(v_13282);
    goto v_13255;
v_13256:
    v_13282 = stack[0];
    v_13282 = qcar(v_13282);
    goto v_13257;
v_13258:
    goto v_13254;
v_13255:
    goto v_13256;
v_13257:
    fn = elt(env, 1); // iequal
    v_13282 = (*qfn2(fn))(fn, v_13283, v_13282);
    env = stack[-2];
    if (v_13282 == nil) goto v_13252;
    v_13282 = stack[-1];
    v_13282 = qcdr(v_13282);
    stack[-1] = v_13282;
    v_13282 = stack[0];
    v_13282 = qcdr(v_13282);
    stack[0] = v_13282;
    goto v_13244;
v_13252:
    goto v_13273;
v_13269:
    v_13282 = stack[-1];
    v_13283 = qcar(v_13282);
    goto v_13270;
v_13271:
    v_13282 = stack[0];
    v_13282 = qcar(v_13282);
    goto v_13272;
v_13273:
    goto v_13269;
v_13270:
    goto v_13271;
v_13272:
    if (((intptr_t)(v_13283)) > ((intptr_t)(v_13282))) goto v_13267;
    else goto v_13268;
v_13267:
    v_13282 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13243;
v_13268:
    v_13282 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_13243;
    v_13282 = nil;
v_13243:
    return onevalue(v_13282);
}



// Code for subs4q

static LispObject CC_subs4q(LispObject env,
                         LispObject v_13239)
{
    env = qenv(env);
    LispObject v_13385, v_13386, v_13387;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13239);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_13239;
// end of prologue
    stack[-3] = nil;
// Binding d
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-7, 1, -2);
    qvalue(elt(env, 1)) = nil; // d
    v_13385 = elt(env, 2); // slash
    if (!symbolp(v_13385)) v_13385 = nil;
    else { v_13385 = qfastgets(v_13385);
           if (v_13385 != nil) { v_13385 = elt(v_13385, 9); // opmtch
#ifdef RECORD_GET
             if (v_13385 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_13385 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_13385 == SPID_NOPROP) v_13385 = nil; }}
#endif
    stack[-6] = v_13385;
    if (v_13385 == nil) goto v_13249;
    else goto v_13250;
v_13249:
    v_13385 = stack[-5];
    goto v_13246;
v_13250:
    v_13385 = stack[-5];
    fn = elt(env, 7); // prepsq
    v_13385 = (*qfn1(fn))(fn, v_13385);
    env = stack[-7];
    stack[-4] = v_13385;
    goto v_13261;
v_13257:
    v_13386 = elt(env, 2); // slash
    goto v_13258;
v_13259:
    v_13385 = elt(env, 3); // opmtch
    goto v_13260;
v_13261:
    goto v_13257;
v_13258:
    goto v_13259;
v_13260:
    v_13385 = Lremprop(nil, v_13386, v_13385);
    env = stack[-7];
    goto v_13271;
v_13265:
    v_13387 = elt(env, 4); // slash!*
    goto v_13266;
v_13267:
    v_13386 = elt(env, 3); // opmtch
    goto v_13268;
v_13269:
    v_13385 = stack[-6];
    goto v_13270;
v_13271:
    goto v_13265;
v_13266:
    goto v_13267;
v_13268:
    goto v_13269;
v_13270:
    v_13385 = Lputprop(nil, 3, v_13387, v_13386, v_13385);
    env = stack[-7];
v_13277:
    v_13385 = stack[-4];
    if (v_13385 == nil) goto v_13280;
    goto v_13290;
v_13286:
    v_13386 = stack[-4];
    stack[-3] = v_13386;
    goto v_13287;
v_13288:
    v_13385 = elt(env, 5); // quotient
    goto v_13289;
v_13290:
    goto v_13286;
v_13287:
    goto v_13288;
v_13289:
    if (!consp(v_13386)) goto v_13280;
    v_13386 = qcar(v_13386);
    if (v_13386 == v_13385) goto v_13284;
    else goto v_13280;
v_13284:
    goto v_13281;
v_13280:
    goto v_13276;
v_13281:
    goto v_13303;
v_13299:
    v_13386 = elt(env, 4); // slash!*
    goto v_13300;
v_13301:
    v_13385 = stack[-4];
    v_13385 = qcdr(v_13385);
    goto v_13302;
v_13303:
    goto v_13299;
v_13300:
    goto v_13301;
v_13302:
    v_13385 = cons(v_13386, v_13385);
    env = stack[-7];
    fn = elt(env, 3); // opmtch
    v_13385 = (*qfn1(fn))(fn, v_13385);
    env = stack[-7];
    if (v_13385 == nil) goto v_13296;
    else goto v_13295;
v_13296:
    goto v_13316;
v_13312:
    v_13386 = elt(env, 6); // minus
    goto v_13313;
v_13314:
    v_13385 = stack[-4];
    v_13385 = qcdr(v_13385);
    v_13385 = qcdr(v_13385);
    v_13385 = qcar(v_13385);
    goto v_13315;
v_13316:
    goto v_13312;
v_13313:
    goto v_13314;
v_13315:
    v_13385 = Lsmemq(nil, v_13386, v_13385);
    env = stack[-7];
    if (v_13385 == nil) goto v_13309;
    else goto v_13310;
v_13309:
    v_13385 = nil;
    goto v_13308;
v_13310:
    goto v_13333;
v_13327:
    stack[-1] = elt(env, 4); // slash!*
    goto v_13328;
v_13329:
    goto v_13341;
v_13337:
    v_13386 = elt(env, 6); // minus
    goto v_13338;
v_13339:
    v_13385 = stack[-4];
    v_13385 = qcdr(v_13385);
    v_13385 = qcar(v_13385);
    goto v_13340;
v_13341:
    goto v_13337;
v_13338:
    goto v_13339;
v_13340:
    v_13385 = list2(v_13386, v_13385);
    env = stack[-7];
    fn = elt(env, 8); // reval
    stack[0] = (*qfn1(fn))(fn, v_13385);
    env = stack[-7];
    goto v_13330;
v_13331:
    goto v_13352;
v_13348:
    v_13386 = elt(env, 6); // minus
    goto v_13349;
v_13350:
    v_13385 = stack[-4];
    v_13385 = qcdr(v_13385);
    v_13385 = qcdr(v_13385);
    v_13385 = qcar(v_13385);
    goto v_13351;
v_13352:
    goto v_13348;
v_13349:
    goto v_13350;
v_13351:
    v_13385 = list2(v_13386, v_13385);
    env = stack[-7];
    fn = elt(env, 8); // reval
    v_13385 = (*qfn1(fn))(fn, v_13385);
    env = stack[-7];
    goto v_13332;
v_13333:
    goto v_13327;
v_13328:
    goto v_13329;
v_13330:
    goto v_13331;
v_13332:
    v_13385 = list3(stack[-1], stack[0], v_13385);
    env = stack[-7];
    fn = elt(env, 3); // opmtch
    v_13385 = (*qfn1(fn))(fn, v_13385);
    env = stack[-7];
    goto v_13308;
    v_13385 = nil;
v_13308:
v_13295:
    stack[-4] = v_13385;
    v_13385 = qvalue(elt(env, 1)); // d
    if (v_13385 == nil) goto v_13360;
    else goto v_13359;
v_13360:
    v_13385 = stack[-4];
v_13359:
    qvalue(elt(env, 1)) = v_13385; // d
    goto v_13277;
v_13276:
    v_13385 = qvalue(elt(env, 1)); // d
    if (v_13385 == nil) goto v_13366;
    v_13385 = stack[-3];
    fn = elt(env, 9); // simp!*
    v_13385 = (*qfn1(fn))(fn, v_13385);
    env = stack[-7];
    goto v_13364;
v_13366:
    v_13385 = stack[-5];
    goto v_13364;
    v_13385 = nil;
v_13364:
    stack[-5] = v_13385;
    goto v_13380;
v_13374:
    v_13387 = elt(env, 2); // slash
    goto v_13375;
v_13376:
    v_13386 = elt(env, 3); // opmtch
    goto v_13377;
v_13378:
    v_13385 = stack[-6];
    goto v_13379;
v_13380:
    goto v_13374;
v_13375:
    goto v_13376;
v_13377:
    goto v_13378;
v_13379:
    v_13385 = Lputprop(nil, 3, v_13387, v_13386, v_13385);
    v_13385 = stack[-5];
v_13246:
    ;}  // end of a binding scope
    return onevalue(v_13385);
}



// Code for makeset

static LispObject CC_makeset(LispObject env,
                         LispObject v_13239)
{
    env = qenv(env);
    LispObject v_13279, v_13280, v_13281;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13239);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_13239;
// end of prologue
    v_13281 = nil;
v_13244:
    v_13279 = stack[0];
    if (v_13279 == nil) goto v_13247;
    else goto v_13248;
v_13247:
    v_13279 = v_13281;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_13279);
    }
v_13248:
    goto v_13258;
v_13254:
    v_13279 = stack[0];
    v_13280 = qcar(v_13279);
    goto v_13255;
v_13256:
    v_13279 = stack[0];
    v_13279 = qcdr(v_13279);
    goto v_13257;
v_13258:
    goto v_13254;
v_13255:
    goto v_13256;
v_13257:
    v_13279 = Lmember(nil, v_13280, v_13279);
    if (v_13279 == nil) goto v_13253;
    v_13279 = stack[0];
    v_13279 = qcdr(v_13279);
    stack[0] = v_13279;
    goto v_13244;
v_13253:
    goto v_13273;
v_13269:
    v_13279 = stack[0];
    v_13279 = qcar(v_13279);
    goto v_13270;
v_13271:
    v_13280 = v_13281;
    goto v_13272;
v_13273:
    goto v_13269;
v_13270:
    goto v_13271;
v_13272:
    v_13279 = cons(v_13279, v_13280);
    env = stack[-1];
    v_13281 = v_13279;
    v_13279 = stack[0];
    v_13279 = qcdr(v_13279);
    stack[0] = v_13279;
    goto v_13244;
    v_13279 = nil;
    return onevalue(v_13279);
}



// Code for xlcm

static LispObject CC_xlcm(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13362, v_13363;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13239,v_13240);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13240;
    stack[-1] = v_13239;
// end of prologue
    stack[-2] = nil;
v_13245:
    v_13362 = stack[-1];
    if (v_13362 == nil) goto v_13252;
    else goto v_13253;
v_13252:
    v_13362 = lisp_true;
    goto v_13251;
v_13253:
    goto v_13262;
v_13258:
    v_13362 = stack[-1];
    v_13363 = qcar(v_13362);
    goto v_13259;
v_13260:
    v_13362 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13261;
v_13262:
    goto v_13258;
v_13259:
    goto v_13260;
v_13261:
    v_13362 = (v_13363 == v_13362 ? lisp_true : nil);
    goto v_13251;
    v_13362 = nil;
v_13251:
    if (v_13362 == nil) goto v_13249;
    goto v_13272;
v_13268:
    v_13363 = stack[-2];
    goto v_13269;
v_13270:
    v_13362 = stack[0];
    goto v_13271;
v_13272:
    goto v_13268;
v_13269:
    goto v_13270;
v_13271:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_13363, v_13362);
    }
v_13249:
    v_13362 = stack[0];
    if (v_13362 == nil) goto v_13279;
    else goto v_13280;
v_13279:
    v_13362 = lisp_true;
    goto v_13278;
v_13280:
    goto v_13289;
v_13285:
    v_13362 = stack[0];
    v_13363 = qcar(v_13362);
    goto v_13286;
v_13287:
    v_13362 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13288;
v_13289:
    goto v_13285;
v_13286:
    goto v_13287;
v_13288:
    v_13362 = (v_13363 == v_13362 ? lisp_true : nil);
    goto v_13278;
    v_13362 = nil;
v_13278:
    if (v_13362 == nil) goto v_13276;
    goto v_13299;
v_13295:
    v_13363 = stack[-2];
    goto v_13296;
v_13297:
    v_13362 = stack[-1];
    goto v_13298;
v_13299:
    goto v_13295;
v_13296:
    goto v_13297;
v_13298:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_13363, v_13362);
    }
v_13276:
    goto v_13308;
v_13304:
    v_13362 = stack[-1];
    v_13363 = qcar(v_13362);
    goto v_13305;
v_13306:
    v_13362 = stack[0];
    v_13362 = qcar(v_13362);
    goto v_13307;
v_13308:
    goto v_13304;
v_13305:
    goto v_13306;
v_13307:
    if (v_13363 == v_13362) goto v_13302;
    else goto v_13303;
v_13302:
    goto v_13318;
v_13314:
    v_13362 = stack[-1];
    v_13363 = qcar(v_13362);
    goto v_13315;
v_13316:
    v_13362 = stack[-2];
    goto v_13317;
v_13318:
    goto v_13314;
v_13315:
    goto v_13316;
v_13317:
    v_13362 = cons(v_13363, v_13362);
    env = stack[-3];
    stack[-2] = v_13362;
    v_13362 = stack[-1];
    v_13362 = qcdr(v_13362);
    stack[-1] = v_13362;
    v_13362 = stack[0];
    v_13362 = qcdr(v_13362);
    stack[0] = v_13362;
    goto v_13245;
v_13303:
    goto v_13333;
v_13329:
    v_13362 = stack[-1];
    v_13363 = qcar(v_13362);
    goto v_13330;
v_13331:
    v_13362 = stack[0];
    v_13362 = qcar(v_13362);
    goto v_13332;
v_13333:
    goto v_13329;
v_13330:
    goto v_13331;
v_13332:
    fn = elt(env, 2); // factorordp
    v_13362 = (*qfn2(fn))(fn, v_13363, v_13362);
    env = stack[-3];
    if (v_13362 == nil) goto v_13327;
    goto v_13343;
v_13339:
    v_13362 = stack[-1];
    v_13363 = qcar(v_13362);
    goto v_13340;
v_13341:
    v_13362 = stack[-2];
    goto v_13342;
v_13343:
    goto v_13339;
v_13340:
    goto v_13341;
v_13342:
    v_13362 = cons(v_13363, v_13362);
    env = stack[-3];
    stack[-2] = v_13362;
    v_13362 = stack[-1];
    v_13362 = qcdr(v_13362);
    stack[-1] = v_13362;
    goto v_13245;
v_13327:
    goto v_13356;
v_13352:
    v_13362 = stack[0];
    v_13363 = qcar(v_13362);
    goto v_13353;
v_13354:
    v_13362 = stack[-2];
    goto v_13355;
v_13356:
    goto v_13352;
v_13353:
    goto v_13354;
v_13355:
    v_13362 = cons(v_13363, v_13362);
    env = stack[-3];
    stack[-2] = v_13362;
    v_13362 = stack[0];
    v_13362 = qcdr(v_13362);
    stack[0] = v_13362;
    goto v_13245;
    v_13362 = nil;
    return onevalue(v_13362);
}



// Code for set!-global!-mode

static LispObject CC_setKglobalKmode(LispObject env,
                         LispObject v_13239)
{
    env = qenv(env);
    LispObject v_13265;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13239);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_13239;
// end of prologue
    v_13265 = nil;
    v_13265 = ncons(v_13265);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_13265; // alglist!*
    v_13265 = stack[-2];
    qvalue(elt(env, 2)) = v_13265; // !*mode
    goto v_13251;
v_13247:
    stack[-3] = elt(env, 3); // null
    goto v_13248;
v_13249:
    goto v_13260;
v_13254:
    stack[-1] = elt(env, 4); // setq
    goto v_13255;
v_13256:
    stack[0] = elt(env, 2); // !*mode
    goto v_13257;
v_13258:
    v_13265 = stack[-2];
    v_13265 = Lmkquote(nil, v_13265);
    env = stack[-4];
    goto v_13259;
v_13260:
    goto v_13254;
v_13255:
    goto v_13256;
v_13257:
    goto v_13258;
v_13259:
    v_13265 = list3(stack[-1], stack[0], v_13265);
    goto v_13250;
v_13251:
    goto v_13247;
v_13248:
    goto v_13249;
v_13250:
    {
        LispObject v_13270 = stack[-3];
        return list2(v_13270, v_13265);
    }
    return onevalue(v_13265);
}



// Code for scalprod

static LispObject CC_scalprod(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13315, v_13316, v_13317;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13239,v_13240);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13240;
    stack[-1] = v_13239;
// end of prologue
    v_13315 = stack[-1];
    if (v_13315 == nil) goto v_13248;
    else goto v_13249;
v_13248:
    v_13315 = stack[0];
    v_13315 = (v_13315 == nil ? lisp_true : nil);
    goto v_13247;
v_13249:
    v_13315 = nil;
    goto v_13247;
    v_13315 = nil;
v_13247:
    if (v_13315 == nil) goto v_13245;
    goto v_13261;
v_13257:
    v_13316 = nil;
    goto v_13258;
v_13259:
    v_13315 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13260;
v_13261:
    goto v_13257;
v_13258:
    goto v_13259;
v_13260:
    return cons(v_13316, v_13315);
v_13245:
    v_13315 = stack[-1];
    if (v_13315 == nil) goto v_13268;
    else goto v_13269;
v_13268:
    v_13315 = lisp_true;
    goto v_13267;
v_13269:
    v_13315 = stack[0];
    v_13315 = (v_13315 == nil ? lisp_true : nil);
    goto v_13267;
    v_13315 = nil;
v_13267:
    if (v_13315 == nil) goto v_13265;
    goto v_13283;
v_13277:
    v_13317 = elt(env, 1); // matrix
    goto v_13278;
v_13279:
    v_13316 = (LispObject)144+TAG_FIXNUM; // 9
    goto v_13280;
v_13281:
    v_13315 = elt(env, 2); // "Matrix mismatch"
    goto v_13282;
v_13283:
    goto v_13277;
v_13278:
    goto v_13279;
v_13280:
    goto v_13281;
v_13282:
    {
        fn = elt(env, 3); // rerror
        return (*qfnn(fn))(fn, 3, v_13317, v_13316, v_13315);
    }
v_13265:
    goto v_13294;
v_13290:
    goto v_13300;
v_13296:
    v_13315 = stack[-1];
    v_13316 = qcar(v_13315);
    goto v_13297;
v_13298:
    v_13315 = stack[0];
    v_13315 = qcar(v_13315);
    goto v_13299;
v_13300:
    goto v_13296;
v_13297:
    goto v_13298;
v_13299:
    fn = elt(env, 4); // multsq
    stack[-2] = (*qfn2(fn))(fn, v_13316, v_13315);
    env = stack[-3];
    goto v_13291;
v_13292:
    goto v_13310;
v_13306:
    v_13315 = stack[-1];
    v_13316 = qcdr(v_13315);
    goto v_13307;
v_13308:
    v_13315 = stack[0];
    v_13315 = qcdr(v_13315);
    goto v_13309;
v_13310:
    goto v_13306;
v_13307:
    goto v_13308;
v_13309:
    v_13315 = CC_scalprod(elt(env, 0), v_13316, v_13315);
    env = stack[-3];
    goto v_13293;
v_13294:
    goto v_13290;
v_13291:
    goto v_13292;
v_13293:
    {
        LispObject v_13321 = stack[-2];
        fn = elt(env, 5); // addsq
        return (*qfn2(fn))(fn, v_13321, v_13315);
    }
    v_13315 = nil;
    return onevalue(v_13315);
}



// Code for fs!:null!-angle

static LispObject CC_fsTnullKangle(LispObject env,
                         LispObject v_13239)
{
    env = qenv(env);
    LispObject v_13291, v_13292;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13239);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_13291 = v_13239;
// end of prologue
    goto v_13251;
v_13247:
    v_13292 = v_13291;
    goto v_13248;
v_13249:
    v_13291 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13250;
v_13251:
    goto v_13247;
v_13248:
    goto v_13249;
v_13250:
    v_13291 = *(LispObject *)((char *)v_13292 + (CELL-TAG_VECTOR) + (((intptr_t)v_13291-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_13291;
    v_13291 = lisp_true;
    stack[-2] = v_13291;
    v_13291 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_13291;
v_13246:
    goto v_13265;
v_13261:
    goto v_13270;
v_13266:
    v_13292 = stack[0];
    goto v_13267;
v_13268:
    v_13291 = stack[-1];
    goto v_13269;
v_13270:
    goto v_13266;
v_13267:
    goto v_13268;
v_13269:
    v_13292 = *(LispObject *)((char *)v_13292 + (CELL-TAG_VECTOR) + (((intptr_t)v_13291-TAG_FIXNUM)/(16/CELL)));
    goto v_13262;
v_13263:
    v_13291 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13264;
v_13265:
    goto v_13261;
v_13262:
    goto v_13263;
v_13264:
    if (v_13292 == v_13291) goto v_13260;
    v_13291 = nil;
    goto v_13245;
v_13260:
    v_13291 = stack[-1];
    v_13291 = add1(v_13291);
    env = stack[-3];
    stack[-1] = v_13291;
    goto v_13287;
v_13283:
    v_13292 = stack[-1];
    goto v_13284;
v_13285:
    v_13291 = (LispObject)128+TAG_FIXNUM; // 8
    goto v_13286;
v_13287:
    goto v_13283;
v_13284:
    goto v_13285;
v_13286:
    v_13291 = (LispObject)lessp2(v_13292, v_13291);
    v_13291 = v_13291 ? lisp_true : nil;
    env = stack[-3];
    if (v_13291 == nil) goto v_13281;
    goto v_13246;
v_13281:
    v_13291 = stack[-2];
v_13245:
    return onevalue(v_13291);
}



// Code for mo_equal!?

static LispObject CC_mo_equalW(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13254;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13239,v_13240);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13240;
    v_13254 = v_13239;
// end of prologue
    goto v_13246;
v_13242:
    v_13254 = qcar(v_13254);
    fn = elt(env, 1); // mo!=shorten
    stack[-1] = (*qfn1(fn))(fn, v_13254);
    env = stack[-2];
    goto v_13243;
v_13244:
    v_13254 = stack[0];
    v_13254 = qcar(v_13254);
    fn = elt(env, 1); // mo!=shorten
    v_13254 = (*qfn1(fn))(fn, v_13254);
    goto v_13245;
v_13246:
    goto v_13242;
v_13243:
    goto v_13244;
v_13245:
    v_13254 = (equal(stack[-1], v_13254) ? lisp_true : nil);
    return onevalue(v_13254);
}



// Code for formcond1

static LispObject CC_formcond1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13298, v_13299, v_13300;
    LispObject fn;
    LispObject v_13241, v_13240, v_13239;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formcond1");
    va_start(aa, nargs);
    v_13239 = va_arg(aa, LispObject);
    v_13240 = va_arg(aa, LispObject);
    v_13241 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13241,v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13239,v_13240,v_13241);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_13241;
    stack[-2] = v_13240;
    stack[-3] = v_13239;
// end of prologue
    stack[-4] = nil;
v_13246:
    v_13298 = stack[-3];
    if (v_13298 == nil) goto v_13249;
    else goto v_13250;
v_13249:
    v_13298 = stack[-4];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_13298);
    }
v_13250:
    goto v_13261;
v_13257:
    goto v_13267;
v_13263:
    goto v_13275;
v_13269:
    v_13298 = stack[-3];
    v_13298 = qcar(v_13298);
    v_13300 = qcar(v_13298);
    goto v_13270;
v_13271:
    v_13299 = stack[-2];
    goto v_13272;
v_13273:
    v_13298 = stack[-1];
    goto v_13274;
v_13275:
    goto v_13269;
v_13270:
    goto v_13271;
v_13272:
    goto v_13273;
v_13274:
    fn = elt(env, 2); // formbool
    stack[0] = (*qfnn(fn))(fn, 3, v_13300, v_13299, v_13298);
    env = stack[-5];
    goto v_13264;
v_13265:
    goto v_13288;
v_13282:
    v_13298 = stack[-3];
    v_13298 = qcar(v_13298);
    v_13298 = qcdr(v_13298);
    v_13300 = qcar(v_13298);
    goto v_13283;
v_13284:
    v_13299 = stack[-2];
    goto v_13285;
v_13286:
    v_13298 = stack[-1];
    goto v_13287;
v_13288:
    goto v_13282;
v_13283:
    goto v_13284;
v_13285:
    goto v_13286;
v_13287:
    fn = elt(env, 3); // formc
    v_13298 = (*qfnn(fn))(fn, 3, v_13300, v_13299, v_13298);
    env = stack[-5];
    goto v_13266;
v_13267:
    goto v_13263;
v_13264:
    goto v_13265;
v_13266:
    v_13299 = list2(stack[0], v_13298);
    env = stack[-5];
    goto v_13258;
v_13259:
    v_13298 = stack[-4];
    goto v_13260;
v_13261:
    goto v_13257;
v_13258:
    goto v_13259;
v_13260:
    v_13298 = cons(v_13299, v_13298);
    env = stack[-5];
    stack[-4] = v_13298;
    v_13298 = stack[-3];
    v_13298 = qcdr(v_13298);
    stack[-3] = v_13298;
    goto v_13246;
    v_13298 = nil;
    return onevalue(v_13298);
}



// Code for talp_contains

static LispObject CC_talp_contains(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13309, v_13310, v_13311;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13239,v_13240);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13240;
    v_13309 = v_13239;
// end of prologue
    v_13311 = nil;
    v_13310 = v_13309;
    v_13310 = Lconsp(nil, v_13310);
    env = stack[-2];
    if (v_13310 == nil) goto v_13248;
    stack[-1] = v_13309;
v_13254:
    v_13309 = stack[-1];
    if (v_13309 == nil) goto v_13258;
    else goto v_13259;
v_13258:
    goto v_13253;
v_13259:
    v_13309 = stack[-1];
    v_13309 = qcar(v_13309);
    v_13310 = v_13309;
    v_13309 = v_13310;
    v_13309 = Lconsp(nil, v_13309);
    env = stack[-2];
    if (v_13309 == nil) goto v_13268;
    v_13309 = v_13311;
    if (v_13309 == nil) goto v_13272;
    else goto v_13268;
v_13272:
    goto v_13279;
v_13275:
    goto v_13276;
v_13277:
    v_13309 = stack[0];
    goto v_13278;
v_13279:
    goto v_13275;
v_13276:
    goto v_13277;
v_13278:
    v_13309 = CC_talp_contains(elt(env, 0), v_13310, v_13309);
    env = stack[-2];
    v_13311 = v_13309;
    goto v_13266;
v_13268:
    goto v_13292;
v_13288:
    goto v_13289;
v_13290:
    v_13309 = stack[0];
    goto v_13291;
v_13292:
    goto v_13288;
v_13289:
    goto v_13290;
v_13291:
    if (v_13310 == v_13309) goto v_13286;
    else goto v_13287;
v_13286:
    v_13309 = lisp_true;
    v_13311 = v_13309;
    goto v_13285;
v_13287:
v_13285:
    goto v_13266;
v_13266:
    v_13309 = stack[-1];
    v_13309 = qcdr(v_13309);
    stack[-1] = v_13309;
    goto v_13254;
v_13253:
    goto v_13246;
v_13248:
    goto v_13304;
v_13300:
    v_13310 = stack[0];
    goto v_13301;
v_13302:
    goto v_13303;
v_13304:
    goto v_13300;
v_13301:
    goto v_13302;
v_13303:
    if (v_13310 == v_13309) goto v_13298;
    else goto v_13299;
v_13298:
    v_13309 = lisp_true;
    goto v_13244;
v_13299:
v_13246:
    v_13309 = v_13311;
v_13244:
    return onevalue(v_13309);
}



// Code for mri_pasf2mri

static LispObject CC_mri_pasf2mri(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13254, v_13255;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13239,v_13240);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_13254 = v_13240;
    v_13255 = v_13239;
// end of prologue
    goto v_13249;
v_13243:
    stack[-1] = v_13255;
    goto v_13244;
v_13245:
    stack[0] = elt(env, 1); // mri_pasf2mriat
    goto v_13246;
v_13247:
    v_13254 = ncons(v_13254);
    env = stack[-2];
    goto v_13248;
v_13249:
    goto v_13243;
v_13244:
    goto v_13245;
v_13246:
    goto v_13247;
v_13248:
    {
        LispObject v_13258 = stack[-1];
        LispObject v_13259 = stack[0];
        fn = elt(env, 2); // cl_apply2ats1
        return (*qfnn(fn))(fn, 3, v_13258, v_13259, v_13254);
    }
}



// Code for xregister_wedge_pair

static LispObject CC_xregister_wedge_pair(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13241;
    argcheck(nargs, 0, "xregister_wedge_pair");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_13241 = nil;
    return onevalue(v_13241);
}



// Code for total!-degree!-in!-powers

static LispObject CC_totalKdegreeKinKpowers(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13353, v_13354, v_13355;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13239,v_13240);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13240;
    stack[-1] = v_13239;
// end of prologue
v_13238:
    v_13353 = stack[-1];
    if (v_13353 == nil) goto v_13248;
    else goto v_13249;
v_13248:
    v_13353 = lisp_true;
    goto v_13247;
v_13249:
    v_13353 = stack[-1];
    if (!consp(v_13353)) goto v_13256;
    else goto v_13257;
v_13256:
    v_13353 = lisp_true;
    goto v_13255;
v_13257:
    v_13353 = stack[-1];
    v_13353 = qcar(v_13353);
    v_13353 = (consp(v_13353) ? nil : lisp_true);
    goto v_13255;
    v_13353 = nil;
v_13255:
    goto v_13247;
    v_13353 = nil;
v_13247:
    if (v_13353 == nil) goto v_13245;
    v_13353 = stack[0];
    goto v_13243;
v_13245:
    goto v_13279;
v_13275:
    v_13353 = stack[-1];
    v_13353 = qcar(v_13353);
    v_13353 = qcar(v_13353);
    v_13354 = qcar(v_13353);
    goto v_13276;
v_13277:
    v_13353 = stack[0];
    goto v_13278;
v_13279:
    goto v_13275;
v_13276:
    goto v_13277;
v_13278:
    v_13353 = Latsoc(nil, v_13354, v_13353);
    stack[-2] = v_13353;
    if (v_13353 == nil) goto v_13274;
    goto v_13295;
v_13291:
    v_13353 = stack[-1];
    v_13353 = qcar(v_13353);
    v_13353 = qcar(v_13353);
    v_13354 = qcdr(v_13353);
    goto v_13292;
v_13293:
    v_13353 = stack[-2];
    v_13353 = qcdr(v_13353);
    goto v_13294;
v_13295:
    goto v_13291;
v_13292:
    goto v_13293;
v_13294:
    v_13353 = (LispObject)greaterp2(v_13354, v_13353);
    v_13353 = v_13353 ? lisp_true : nil;
    env = stack[-3];
    if (v_13353 == nil) goto v_13288;
    else goto v_13289;
v_13288:
    goto v_13287;
v_13289:
    goto v_13310;
v_13306:
    v_13354 = stack[-2];
    goto v_13307;
v_13308:
    v_13353 = stack[-1];
    v_13353 = qcar(v_13353);
    v_13353 = qcar(v_13353);
    v_13353 = qcdr(v_13353);
    goto v_13309;
v_13310:
    goto v_13306;
v_13307:
    goto v_13308;
v_13309:
    v_13353 = Lrplacd(nil, v_13354, v_13353);
    env = stack[-3];
    goto v_13287;
v_13287:
    goto v_13272;
v_13274:
    goto v_13325;
v_13319:
    v_13353 = stack[-1];
    v_13353 = qcar(v_13353);
    v_13353 = qcar(v_13353);
    v_13355 = qcar(v_13353);
    goto v_13320;
v_13321:
    v_13353 = stack[-1];
    v_13353 = qcar(v_13353);
    v_13353 = qcar(v_13353);
    v_13354 = qcdr(v_13353);
    goto v_13322;
v_13323:
    v_13353 = stack[0];
    goto v_13324;
v_13325:
    goto v_13319;
v_13320:
    goto v_13321;
v_13322:
    goto v_13323;
v_13324:
    v_13353 = acons(v_13355, v_13354, v_13353);
    env = stack[-3];
    stack[0] = v_13353;
    goto v_13272;
v_13272:
    goto v_13340;
v_13336:
    v_13353 = stack[-1];
    stack[-2] = qcdr(v_13353);
    goto v_13337;
v_13338:
    goto v_13348;
v_13344:
    v_13353 = stack[-1];
    v_13353 = qcar(v_13353);
    v_13354 = qcdr(v_13353);
    goto v_13345;
v_13346:
    v_13353 = stack[0];
    goto v_13347;
v_13348:
    goto v_13344;
v_13345:
    goto v_13346;
v_13347:
    v_13353 = CC_totalKdegreeKinKpowers(elt(env, 0), v_13354, v_13353);
    env = stack[-3];
    goto v_13339;
v_13340:
    goto v_13336;
v_13337:
    goto v_13338;
v_13339:
    stack[-1] = stack[-2];
    stack[0] = v_13353;
    goto v_13238;
    goto v_13243;
    v_13353 = nil;
v_13243:
    return onevalue(v_13353);
}



// Code for putd

static LispObject CC_putd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13418, v_13419, v_13420;
    LispObject fn;
    LispObject v_13241, v_13240, v_13239;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "putd");
    va_start(aa, nargs);
    v_13239 = va_arg(aa, LispObject);
    v_13240 = va_arg(aa, LispObject);
    v_13241 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13241,v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13239,v_13240,v_13241);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13241;
    stack[-1] = v_13240;
    stack[-2] = v_13239;
// end of prologue
    goto v_13252;
v_13248:
    v_13419 = stack[0];
    goto v_13249;
v_13250:
    v_13418 = elt(env, 1); // funarg
    goto v_13251;
v_13252:
    goto v_13248;
v_13249:
    goto v_13250;
v_13251:
    if (!consp(v_13419)) goto v_13246;
    v_13419 = qcar(v_13419);
    if (v_13419 == v_13418) goto v_13245;
    else goto v_13246;
v_13245:
    goto v_13260;
v_13256:
    v_13419 = elt(env, 2); // lambda
    goto v_13257;
v_13258:
    v_13418 = stack[0];
    v_13418 = qcdr(v_13418);
    v_13418 = qcdr(v_13418);
    goto v_13259;
v_13260:
    goto v_13256;
v_13257:
    goto v_13258;
v_13259:
    v_13418 = cons(v_13419, v_13418);
    env = stack[-3];
    stack[0] = v_13418;
    goto v_13244;
v_13246:
v_13244:
    v_13418 = stack[-2];
    if (!symbolp(v_13418)) v_13418 = nil;
    else { v_13418 = qfastgets(v_13418);
           if (v_13418 != nil) { v_13418 = elt(v_13418, 1); // lose
#ifdef RECORD_GET
             if (v_13418 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v_13418 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v_13418 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v_13418 == SPID_NOPROP) v_13418 = nil; else v_13418 = lisp_true; }}
#endif
    if (v_13418 == nil) goto v_13268;
    v_13418 = Lterpri(nil, 0);
    env = stack[-3];
    v_13418 = elt(env, 3); // "+++ "
    v_13418 = Lprinc(nil, v_13418);
    env = stack[-3];
    v_13418 = stack[-2];
    v_13418 = Lprin(nil, v_13418);
    env = stack[-3];
    v_13418 = elt(env, 4); // " not defined (LOSE flag)"
    v_13418 = Lprintc(nil, v_13418);
    v_13418 = nil;
    goto v_13266;
v_13268:
    v_13418 = qvalue(elt(env, 5)); // !*redefmsg
    if (v_13418 == nil) goto v_13284;
    v_13418 = stack[-2];
    fn = elt(env, 14); // getd
    v_13418 = (*qfn1(fn))(fn, v_13418);
    env = stack[-3];
    if (v_13418 == nil) goto v_13284;
    v_13418 = Lterpri(nil, 0);
    env = stack[-3];
    v_13418 = elt(env, 3); // "+++ "
    v_13418 = Lprinc(nil, v_13418);
    env = stack[-3];
    v_13418 = stack[-2];
    v_13418 = Lprin(nil, v_13418);
    env = stack[-3];
    v_13418 = elt(env, 6); // " redefined"
    v_13418 = Lprintc(nil, v_13418);
    env = stack[-3];
    goto v_13282;
v_13284:
v_13282:
    goto v_13305;
v_13301:
    v_13419 = stack[-1];
    goto v_13302;
v_13303:
    v_13418 = elt(env, 7); // expr
    goto v_13304;
v_13305:
    goto v_13301;
v_13302:
    goto v_13303;
v_13304:
    if (v_13419 == v_13418) goto v_13299;
    else goto v_13300;
v_13299:
    goto v_13313;
v_13309:
    v_13419 = stack[-2];
    goto v_13310;
v_13311:
    v_13418 = stack[0];
    goto v_13312;
v_13313:
    goto v_13309;
v_13310:
    goto v_13311;
v_13312:
    v_13418 = Lsymbol_set_definition(nil, v_13419, v_13418);
    goto v_13298;
v_13300:
    goto v_13322;
v_13318:
    v_13419 = stack[-1];
    goto v_13319;
v_13320:
    v_13418 = elt(env, 8); // subr
    goto v_13321;
v_13322:
    goto v_13318;
v_13319:
    goto v_13320;
v_13321:
    if (v_13419 == v_13418) goto v_13316;
    else goto v_13317;
v_13316:
    goto v_13330;
v_13326:
    v_13419 = stack[-2];
    goto v_13327;
v_13328:
    v_13418 = stack[0];
    goto v_13329;
v_13330:
    goto v_13326;
v_13327:
    goto v_13328;
v_13329:
    v_13418 = Lsymbol_set_definition(nil, v_13419, v_13418);
    goto v_13298;
v_13317:
    goto v_13343;
v_13339:
    v_13419 = stack[-1];
    goto v_13340;
v_13341:
    v_13418 = elt(env, 9); // macro
    goto v_13342;
v_13343:
    goto v_13339;
v_13340:
    goto v_13341;
v_13342:
    if (v_13419 == v_13418) goto v_13337;
    else goto v_13338;
v_13337:
    goto v_13351;
v_13347:
    v_13419 = stack[0];
    goto v_13348;
v_13349:
    v_13418 = elt(env, 2); // lambda
    goto v_13350;
v_13351:
    goto v_13347;
v_13348:
    goto v_13349;
v_13350:
    v_13418 = Leqcar(nil, v_13419, v_13418);
    env = stack[-3];
    goto v_13336;
v_13338:
    v_13418 = nil;
    goto v_13336;
    v_13418 = nil;
v_13336:
    if (v_13418 == nil) goto v_13334;
    goto v_13365;
v_13359:
    v_13420 = elt(env, 10); // dm
    goto v_13360;
v_13361:
    v_13419 = stack[-2];
    goto v_13362;
v_13363:
    v_13418 = stack[0];
    v_13418 = qcdr(v_13418);
    goto v_13364;
v_13365:
    goto v_13359;
v_13360:
    goto v_13361;
v_13362:
    goto v_13363;
v_13364:
    v_13418 = list2star(v_13420, v_13419, v_13418);
    env = stack[-3];
    fn = elt(env, 15); // eval
    v_13418 = (*qfn1(fn))(fn, v_13418);
    goto v_13298;
v_13334:
    goto v_13380;
v_13376:
    v_13419 = stack[-1];
    goto v_13377;
v_13378:
    v_13418 = elt(env, 11); // fexpr
    goto v_13379;
v_13380:
    goto v_13376;
v_13377:
    goto v_13378;
v_13379:
    if (v_13419 == v_13418) goto v_13374;
    else goto v_13375;
v_13374:
    goto v_13388;
v_13384:
    v_13419 = stack[0];
    goto v_13385;
v_13386:
    v_13418 = elt(env, 2); // lambda
    goto v_13387;
v_13388:
    goto v_13384;
v_13385:
    goto v_13386;
v_13387:
    v_13418 = Leqcar(nil, v_13419, v_13418);
    env = stack[-3];
    goto v_13373;
v_13375:
    v_13418 = nil;
    goto v_13373;
    v_13418 = nil;
v_13373:
    if (v_13418 == nil) goto v_13371;
    goto v_13402;
v_13396:
    v_13420 = elt(env, 12); // df
    goto v_13397;
v_13398:
    v_13419 = stack[-2];
    goto v_13399;
v_13400:
    v_13418 = stack[0];
    v_13418 = qcdr(v_13418);
    goto v_13401;
v_13402:
    goto v_13396;
v_13397:
    goto v_13398;
v_13399:
    goto v_13400;
v_13401:
    v_13418 = list2star(v_13420, v_13419, v_13418);
    env = stack[-3];
    fn = elt(env, 15); // eval
    v_13418 = (*qfn1(fn))(fn, v_13418);
    goto v_13298;
v_13371:
    goto v_13414;
v_13410:
    v_13419 = elt(env, 13); // "Bad type ~S in putd"
    goto v_13411;
v_13412:
    v_13418 = stack[-1];
    goto v_13413;
v_13414:
    goto v_13410;
v_13411:
    goto v_13412;
v_13413:
    fn = elt(env, 16); // error
    v_13418 = (*qfn2(fn))(fn, v_13419, v_13418);
    goto v_13298;
v_13298:
    v_13418 = stack[-2];
    goto v_13266;
    v_13418 = nil;
v_13266:
    return onevalue(v_13418);
}



// Code for setel

static LispObject CC_setel(LispObject env,
                         LispObject v_13239, LispObject v_13240)
{
    env = qenv(env);
    LispObject v_13298, v_13299, v_13300, v_13301;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13240,v_13239);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13239,v_13240);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_13240;
    stack[-2] = v_13239;
// end of prologue
    goto v_13247;
v_13243:
    v_13298 = stack[-2];
    v_13299 = qcar(v_13298);
    goto v_13244;
v_13245:
    v_13298 = elt(env, 1); // dimension
    goto v_13246;
v_13247:
    goto v_13243;
v_13244:
    goto v_13245;
v_13246:
    v_13298 = get(v_13299, v_13298);
    env = stack[-4];
    stack[-3] = v_13298;
    goto v_13260;
v_13256:
    v_13298 = stack[-3];
    stack[0] = Llength(nil, v_13298);
    env = stack[-4];
    goto v_13257;
v_13258:
    v_13298 = stack[-2];
    v_13298 = qcdr(v_13298);
    v_13298 = Llength(nil, v_13298);
    env = stack[-4];
    goto v_13259;
v_13260:
    goto v_13256;
v_13257:
    goto v_13258;
v_13259:
    if (equal(stack[0], v_13298)) goto v_13255;
    goto v_13273;
v_13267:
    v_13300 = elt(env, 2); // rlisp
    goto v_13268;
v_13269:
    v_13299 = (LispObject)352+TAG_FIXNUM; // 22
    goto v_13270;
v_13271:
    v_13298 = elt(env, 3); // "Incorrect array reference"
    goto v_13272;
v_13273:
    goto v_13267;
v_13268:
    goto v_13269;
v_13270:
    goto v_13271;
v_13272:
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_13300, v_13299, v_13298);
    }
v_13255:
    goto v_13288;
v_13280:
    v_13298 = stack[-2];
    v_13298 = qcar(v_13298);
    if (!symbolp(v_13298)) v_13298 = nil;
    else { v_13298 = qfastgets(v_13298);
           if (v_13298 != nil) { v_13298 = elt(v_13298, 4); // avalue
#ifdef RECORD_GET
             if (v_13298 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_13298 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_13298 == SPID_NOPROP) v_13298 = nil; }}
#endif
    v_13298 = qcdr(v_13298);
    v_13301 = qcar(v_13298);
    goto v_13281;
v_13282:
    v_13298 = stack[-2];
    v_13300 = qcdr(v_13298);
    goto v_13283;
v_13284:
    v_13299 = stack[-1];
    goto v_13285;
v_13286:
    v_13298 = stack[-3];
    goto v_13287;
v_13288:
    goto v_13280;
v_13281:
    goto v_13282;
v_13283:
    goto v_13284;
v_13285:
    goto v_13286;
v_13287:
    {
        fn = elt(env, 5); // setel1
        return (*qfnn(fn))(fn, 4, v_13301, v_13300, v_13299, v_13298);
    }
    v_13298 = nil;
    return onevalue(v_13298);
}



setup_type const u23_setup[] =
{
    {"ibalp_var-set",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ibalp_varKset},
    {"inttovec1",               TOO_FEW_2,      CC_inttovec1,  WRONG_NO_2},
    {"collectphystype",         CC_collectphystype,TOO_MANY_1, WRONG_NO_1},
    {"replace1_parents",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_replace1_parents},
    {"repartf",                 CC_repartf,     TOO_MANY_1,    WRONG_NO_1},
    {"setelv",                  TOO_FEW_2,      CC_setelv,     WRONG_NO_2},
    {"red=cancelsimp",          TOO_FEW_2,      CC_redMcancelsimp,WRONG_NO_2},
    {"pst_termnodep",           CC_pst_termnodep,TOO_MANY_1,   WRONG_NO_1},
    {"ratn",                    CC_ratn,        TOO_MANY_1,    WRONG_NO_1},
    {"crprcd2",                 TOO_FEW_2,      CC_crprcd2,    WRONG_NO_2},
    {"innprodkp",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_innprodkp},
    {"ordered-gcd-mod-p",       TOO_FEW_2,      CC_orderedKgcdKmodKp,WRONG_NO_2},
    {"pairxvars",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pairxvars},
    {"monomwrite",              CC_monomwrite,  TOO_MANY_1,    WRONG_NO_1},
    {"super_der_simp",          CC_super_der_simp,TOO_MANY_1,  WRONG_NO_1},
    {"tayexp-times2",           TOO_FEW_2,      CC_tayexpKtimes2,WRONG_NO_2},
    {"get*elements",            CC_getHelements,TOO_MANY_1,    WRONG_NO_1},
    {"talp_subt",               TOO_FEW_2,      CC_talp_subt,  WRONG_NO_2},
    {"ibalp_readform",          CC_ibalp_readform,TOO_MANY_1,  WRONG_NO_1},
    {"vsl_boundtype",           TOO_FEW_2,      CC_vsl_boundtype,WRONG_NO_2},
    {"naryom",                  CC_naryom,      TOO_MANY_1,    WRONG_NO_1},
    {"evdif",                   TOO_FEW_2,      CC_evdif,      WRONG_NO_2},
    {"evgradlexcomp",           TOO_FEW_2,      CC_evgradlexcomp,WRONG_NO_2},
    {"wedgek2",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_wedgek2},
    {"physop2sq",               CC_physop2sq,   TOO_MANY_1,    WRONG_NO_1},
    {"def_edge",                TOO_FEW_2,      CC_def_edge,   WRONG_NO_2},
    {"setel1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setel1},
    {"simp-prop-order",         TOO_FEW_2,      CC_simpKpropKorder,WRONG_NO_2},
    {"p_prinl2",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_p_prinl2},
    {"squared+matrix+p",        CC_squaredLmatrixLp,TOO_MANY_1,WRONG_NO_1},
    {"rl_pnf",                  CC_rl_pnf,      TOO_MANY_1,    WRONG_NO_1},
    {"qqe_eta-in-term",         CC_qqe_etaKinKterm,TOO_MANY_1, WRONG_NO_1},
    {"ibalp_var-unset",         TOO_FEW_2,      CC_ibalp_varKunset,WRONG_NO_2},
    {"ev_lexcomp",              TOO_FEW_2,      CC_ev_lexcomp, WRONG_NO_2},
    {"subs4q",                  CC_subs4q,      TOO_MANY_1,    WRONG_NO_1},
    {"makeset",                 CC_makeset,     TOO_MANY_1,    WRONG_NO_1},
    {"xlcm",                    TOO_FEW_2,      CC_xlcm,       WRONG_NO_2},
    {"set-global-mode",         CC_setKglobalKmode,TOO_MANY_1, WRONG_NO_1},
    {"scalprod",                TOO_FEW_2,      CC_scalprod,   WRONG_NO_2},
    {"fs:null-angle",           CC_fsTnullKangle,TOO_MANY_1,   WRONG_NO_1},
    {"mo_equal?",               TOO_FEW_2,      CC_mo_equalW,  WRONG_NO_2},
    {"formcond1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formcond1},
    {"talp_contains",           TOO_FEW_2,      CC_talp_contains,WRONG_NO_2},
    {"mri_pasf2mri",            TOO_FEW_2,      CC_mri_pasf2mri,WRONG_NO_2},
    {"xregister_wedge_pair",    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xregister_wedge_pair},
    {"total-degree-in-powers",  TOO_FEW_2,      CC_totalKdegreeKinKpowers,WRONG_NO_2},
    {"putd",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_putd},
    {"setel",                   TOO_FEW_2,      CC_setel,      WRONG_NO_2},
    {NULL, (one_args *)"u23", (two_args *)"14514 6341145 5071715", 0}
};

// end of generated code
