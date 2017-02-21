
// $destdir/u31.c        Machine generated C code

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



// Code for subsq

static LispObject CC_subsq(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_17017, v_17018, v_17019;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16947,v_16948);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16948;
    stack[-1] = v_16947;
// end of prologue
    goto v_16958;
v_16954:
    v_17017 = stack[-1];
    v_17018 = qcar(v_17017);
    goto v_16955;
v_16956:
    v_17017 = stack[0];
    goto v_16957;
v_16958:
    goto v_16954;
v_16955:
    goto v_16956;
v_16957:
    fn = elt(env, 4); // subf
    v_17017 = (*qfn2(fn))(fn, v_17018, v_17017);
    env = stack[-3];
    stack[-2] = v_17017;
    goto v_16967;
v_16963:
    v_17017 = stack[-1];
    v_17018 = qcdr(v_17017);
    goto v_16964;
v_16965:
    v_17017 = stack[0];
    goto v_16966;
v_16967:
    goto v_16963;
v_16964:
    goto v_16965;
v_16966:
    fn = elt(env, 4); // subf
    v_17017 = (*qfn2(fn))(fn, v_17018, v_17017);
    env = stack[-3];
    stack[-1] = v_17017;
    v_17017 = stack[-1];
    fn = elt(env, 5); // subs2!*
    v_17017 = (*qfn1(fn))(fn, v_17017);
    env = stack[-3];
    v_17017 = qcar(v_17017);
    if (v_17017 == nil) goto v_16973;
    else goto v_16974;
v_16973:
    v_17017 = stack[-2];
    fn = elt(env, 5); // subs2!*
    v_17017 = (*qfn1(fn))(fn, v_17017);
    env = stack[-3];
    v_17017 = qcar(v_17017);
    if (v_17017 == nil) goto v_16980;
    else goto v_16981;
v_16980:
    goto v_16992;
v_16986:
    v_17019 = elt(env, 1); // alg
    goto v_16987;
v_16988:
    v_17018 = (LispObject)3216+TAG_FIXNUM; // 201
    goto v_16989;
v_16990:
    v_17017 = elt(env, 2); // "0/0 formed"
    goto v_16991;
v_16992:
    goto v_16986;
v_16987:
    goto v_16988;
v_16989:
    goto v_16990;
v_16991:
    fn = elt(env, 6); // rerror
    v_17017 = (*qfnn(fn))(fn, 3, v_17019, v_17018, v_17017);
    env = stack[-3];
    goto v_16979;
v_16981:
    goto v_17005;
v_16999:
    v_17019 = elt(env, 1); // alg
    goto v_17000;
v_17001:
    v_17018 = (LispObject)3216+TAG_FIXNUM; // 201
    goto v_17002;
v_17003:
    v_17017 = elt(env, 3); // "Zero divisor"
    goto v_17004;
v_17005:
    goto v_16999;
v_17000:
    goto v_17001;
v_17002:
    goto v_17003;
v_17004:
    fn = elt(env, 6); // rerror
    v_17017 = (*qfnn(fn))(fn, 3, v_17019, v_17018, v_17017);
    env = stack[-3];
    goto v_16979;
v_16979:
    goto v_16972;
v_16974:
v_16972:
    goto v_17014;
v_17010:
    v_17018 = stack[-2];
    goto v_17011;
v_17012:
    v_17017 = stack[-1];
    goto v_17013;
v_17014:
    goto v_17010;
v_17011:
    goto v_17012;
v_17013:
    {
        fn = elt(env, 7); // quotsq
        return (*qfn2(fn))(fn, v_17018, v_17017);
    }
    return onevalue(v_17017);
}



// Code for changearg

static LispObject CC_changearg(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17018, v_17019, v_17020;
    LispObject fn;
    LispObject v_16949, v_16948, v_16947;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "changearg");
    va_start(aa, nargs);
    v_16947 = va_arg(aa, LispObject);
    v_16948 = va_arg(aa, LispObject);
    v_16949 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_16949,v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_16947,v_16948,v_16949);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_16949;
    stack[-1] = v_16948;
    stack[-2] = v_16947;
// end of prologue
    stack[-3] = nil;
v_16954:
    v_17018 = stack[0];
    if (!consp(v_17018)) goto v_16957;
    else goto v_16958;
v_16957:
    goto v_16965;
v_16961:
    v_17019 = stack[-3];
    goto v_16962;
v_16963:
    v_17018 = stack[0];
    goto v_16964;
v_16965:
    goto v_16961;
v_16962:
    goto v_16963;
v_16964:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_17019, v_17018);
    }
v_16958:
    goto v_16974;
v_16970:
    v_17018 = stack[0];
    v_17019 = qcar(v_17018);
    goto v_16971;
v_16972:
    v_17018 = stack[-2];
    goto v_16973;
v_16974:
    goto v_16970;
v_16971:
    goto v_16972;
v_16973:
    v_17018 = Lmemq(nil, v_17019, v_17018);
    if (v_17018 == nil) goto v_16969;
    goto v_16984;
v_16980:
    stack[-2] = stack[-3];
    goto v_16981;
v_16982:
    goto v_16991;
v_16987:
    v_17018 = stack[0];
    v_17019 = qcar(v_17018);
    goto v_16988;
v_16989:
    v_17018 = stack[-1];
    goto v_16990;
v_16991:
    goto v_16987;
v_16988:
    goto v_16989;
v_16990:
    v_17018 = cons(v_17019, v_17018);
    env = stack[-4];
    goto v_16983;
v_16984:
    goto v_16980;
v_16981:
    goto v_16982;
v_16983:
    {
        LispObject v_17025 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_17025, v_17018);
    }
v_16969:
    goto v_17002;
v_16998:
    goto v_17010;
v_17004:
    v_17020 = stack[-2];
    goto v_17005;
v_17006:
    v_17019 = stack[-1];
    goto v_17007;
v_17008:
    v_17018 = stack[0];
    v_17018 = qcar(v_17018);
    goto v_17009;
v_17010:
    goto v_17004;
v_17005:
    goto v_17006;
v_17007:
    goto v_17008;
v_17009:
    v_17019 = CC_changearg(elt(env, 0), 3, v_17020, v_17019, v_17018);
    env = stack[-4];
    goto v_16999;
v_17000:
    v_17018 = stack[-3];
    goto v_17001;
v_17002:
    goto v_16998;
v_16999:
    goto v_17000;
v_17001:
    v_17018 = cons(v_17019, v_17018);
    env = stack[-4];
    stack[-3] = v_17018;
    v_17018 = stack[0];
    v_17018 = qcdr(v_17018);
    stack[0] = v_17018;
    goto v_16954;
    v_17018 = nil;
    return onevalue(v_17018);
}



// Code for simp!-prop2

static LispObject CC_simpKprop2(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_17096, v_17097, v_17098;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16947);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_16947;
// end of prologue
    v_17096 = qvalue(elt(env, 1)); // propvars!*
    stack[-1] = v_17096;
v_16961:
    v_17096 = stack[-1];
    if (v_17096 == nil) goto v_16965;
    else goto v_16966;
v_16965:
    goto v_16960;
v_16966:
    v_17096 = stack[-1];
    v_17096 = qcar(v_17096);
    stack[0] = v_17096;
    v_17096 = nil;
    stack[-2] = v_17096;
v_16975:
    v_17096 = stack[-5];
    if (v_17096 == nil) goto v_16978;
    else goto v_16979;
v_16978:
    goto v_16974;
v_16979:
    v_17096 = stack[-5];
    v_17096 = qcar(v_17096);
    stack[-3] = v_17096;
    v_17096 = stack[-5];
    v_17096 = qcdr(v_17096);
    stack[-5] = v_17096;
    goto v_16991;
v_16987:
    v_17097 = elt(env, 2); // prop!*
    goto v_16988;
v_16989:
    v_17096 = stack[0];
    goto v_16990;
v_16991:
    goto v_16987;
v_16988:
    goto v_16989;
v_16990:
    v_17096 = list2(v_17097, v_17096);
    env = stack[-7];
    stack[-4] = v_17096;
    goto v_16999;
v_16995:
    v_17097 = elt(env, 3); // not_prop!*
    goto v_16996;
v_16997:
    v_17096 = stack[0];
    goto v_16998;
v_16999:
    goto v_16995;
v_16996:
    goto v_16997;
v_16998:
    v_17096 = list2(v_17097, v_17096);
    env = stack[-7];
    v_17098 = v_17096;
    goto v_17010;
v_17006:
    v_17097 = stack[-4];
    goto v_17007;
v_17008:
    v_17096 = stack[-3];
    goto v_17009;
v_17010:
    goto v_17006;
v_17007:
    goto v_17008;
v_17009:
    v_17096 = Lmember(nil, v_17097, v_17096);
    if (v_17096 == nil) goto v_17004;
    else goto v_17005;
v_17004:
    v_17096 = v_17098;
    v_17097 = stack[-4];
    v_17098 = v_17097;
    stack[-4] = v_17096;
    goto v_17003;
v_17005:
v_17003:
    goto v_17024;
v_17018:
    goto v_17019;
v_17020:
    v_17097 = stack[-4];
    goto v_17021;
v_17022:
    v_17096 = stack[-3];
    goto v_17023;
v_17024:
    goto v_17018;
v_17019:
    goto v_17020;
v_17021:
    goto v_17022;
v_17023:
    v_17096 = Lsubst(nil, 3, v_17098, v_17097, v_17096);
    env = stack[-7];
    stack[-6] = v_17096;
    goto v_17033;
v_17029:
    v_17097 = stack[-3];
    goto v_17030;
v_17031:
    v_17096 = stack[-2];
    goto v_17032;
v_17033:
    goto v_17029;
v_17030:
    goto v_17031;
v_17032:
    v_17096 = cons(v_17097, v_17096);
    env = stack[-7];
    stack[-2] = v_17096;
    goto v_17044;
v_17040:
    v_17097 = stack[-6];
    goto v_17041;
v_17042:
    v_17096 = stack[-5];
    goto v_17043;
v_17044:
    goto v_17040;
v_17041:
    goto v_17042;
v_17043:
    v_17096 = Lmember(nil, v_17097, v_17096);
    stack[-6] = v_17096;
    if (v_17096 == nil) goto v_17039;
    v_17096 = stack[-6];
    if (v_17096 == nil) goto v_17051;
    goto v_17058;
v_17054:
    v_17096 = stack[-6];
    v_17097 = qcar(v_17096);
    goto v_17055;
v_17056:
    v_17096 = stack[-5];
    goto v_17057;
v_17058:
    goto v_17054;
v_17055:
    goto v_17056;
v_17057:
    v_17096 = Ldelete(nil, v_17097, v_17096);
    env = stack[-7];
    stack[-5] = v_17096;
    goto v_17067;
v_17063:
    v_17096 = stack[-6];
    v_17097 = qcar(v_17096);
    goto v_17064;
v_17065:
    v_17096 = stack[-2];
    goto v_17066;
v_17067:
    goto v_17063;
v_17064:
    goto v_17065;
v_17066:
    v_17096 = cons(v_17097, v_17096);
    env = stack[-7];
    stack[-2] = v_17096;
    goto v_17049;
v_17051:
v_17049:
    goto v_17076;
v_17072:
    v_17097 = stack[-4];
    goto v_17073;
v_17074:
    v_17096 = stack[-3];
    goto v_17075;
v_17076:
    goto v_17072;
v_17073:
    goto v_17074;
v_17075:
    v_17096 = Ldelete(nil, v_17097, v_17096);
    env = stack[-7];
    stack[-3] = v_17096;
    goto v_17084;
v_17080:
    v_17096 = stack[-3];
    v_17097 = ncons(v_17096);
    env = stack[-7];
    goto v_17081;
v_17082:
    v_17096 = stack[-2];
    goto v_17083;
v_17084:
    goto v_17080;
v_17081:
    goto v_17082;
v_17083:
    fn = elt(env, 4); // union
    v_17096 = (*qfn2(fn))(fn, v_17097, v_17096);
    env = stack[-7];
    stack[-2] = v_17096;
    goto v_17037;
v_17039:
v_17037:
    goto v_16975;
v_16974:
    v_17096 = stack[-2];
    stack[-5] = v_17096;
    v_17096 = stack[-1];
    v_17096 = qcdr(v_17096);
    stack[-1] = v_17096;
    goto v_16961;
v_16960:
    v_17096 = stack[-5];
    {
        fn = elt(env, 5); // simp!-prop!-condense
        return (*qfn1(fn))(fn, v_17096);
    }
    return onevalue(v_17096);
}



// Code for cons_ordp

static LispObject CC_cons_ordp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17018, v_17019, v_17020, v_17021, v_17022;
    LispObject v_16949, v_16948, v_16947;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cons_ordp");
    va_start(aa, nargs);
    v_16947 = va_arg(aa, LispObject);
    v_16948 = va_arg(aa, LispObject);
    v_16949 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_16949,v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_16947,v_16948,v_16949);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_17019 = v_16949;
    v_17020 = v_16948;
    v_17021 = v_16947;
// end of prologue
v_16953:
    v_17018 = v_17021;
    if (v_17018 == nil) goto v_16956;
    else goto v_16957;
v_16956:
    v_17018 = lisp_true;
    goto v_16952;
v_16957:
    v_17018 = v_17020;
    if (v_17018 == nil) goto v_16960;
    else goto v_16961;
v_16960:
    v_17018 = nil;
    goto v_16952;
v_16961:
    v_17018 = v_17021;
    v_17018 = Lconsp(nil, v_17018);
    env = stack[0];
    if (v_17018 == nil) goto v_16965;
    v_17018 = v_17020;
    v_17018 = Lconsp(nil, v_17018);
    env = stack[0];
    if (v_17018 == nil) goto v_16971;
    goto v_16982;
v_16978:
    v_17018 = v_17021;
    v_17022 = qcar(v_17018);
    goto v_16979;
v_16980:
    v_17018 = v_17020;
    v_17018 = qcar(v_17018);
    goto v_16981;
v_16982:
    goto v_16978;
v_16979:
    goto v_16980;
v_16981:
    if (equal(v_17022, v_17018)) goto v_16976;
    else goto v_16977;
v_16976:
    v_17018 = v_17021;
    v_17018 = qcdr(v_17018);
    v_17021 = v_17018;
    v_17018 = v_17020;
    v_17018 = qcdr(v_17018);
    v_17020 = v_17018;
    goto v_16953;
v_16977:
    v_17018 = v_17021;
    v_17018 = qcar(v_17018);
    v_17021 = v_17018;
    v_17018 = v_17020;
    v_17018 = qcar(v_17018);
    v_17020 = v_17018;
    goto v_16953;
    goto v_16969;
v_16971:
    v_17018 = nil;
    goto v_16952;
v_16969:
    goto v_16955;
v_16965:
    v_17018 = v_17020;
    v_17018 = Lconsp(nil, v_17018);
    if (v_17018 == nil) goto v_17001;
    v_17018 = lisp_true;
    goto v_16952;
v_17001:
    goto v_17014;
v_17008:
    v_17018 = v_17019;
    goto v_17009;
v_17010:
    v_17019 = v_17021;
    goto v_17011;
v_17012:
    goto v_17013;
v_17014:
    goto v_17008;
v_17009:
    goto v_17010;
v_17011:
    goto v_17012;
v_17013:
        return Lapply2(nil, 3, v_17018, v_17019, v_17020);
v_16955:
    v_17018 = nil;
v_16952:
    return onevalue(v_17018);
}



// Code for poly!-to!-vector

static LispObject CC_polyKtoKvector(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_16997, v_16998, v_16999, v_17000;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16947);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_16999 = v_16947;
// end of prologue
v_16951:
    v_16997 = v_16999;
    if (!consp(v_16997)) goto v_16958;
    else goto v_16959;
v_16958:
    v_16997 = lisp_true;
    goto v_16957;
v_16959:
    v_16997 = v_16999;
    v_16997 = qcar(v_16997);
    v_16997 = (consp(v_16997) ? nil : lisp_true);
    goto v_16957;
    v_16997 = nil;
v_16957:
    if (v_16997 == nil) goto v_16955;
    goto v_16973;
v_16967:
    stack[-1] = qvalue(elt(env, 1)); // poly!-vector
    goto v_16968;
v_16969:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16970;
v_16971:
    v_16997 = v_16999;
    fn = elt(env, 2); // !*d2n
    v_16997 = (*qfn1(fn))(fn, v_16997);
    goto v_16972;
v_16973:
    goto v_16967;
v_16968:
    goto v_16969;
v_16970:
    goto v_16971;
v_16972:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_16997;
    goto v_16950;
v_16955:
    goto v_16986;
v_16980:
    v_17000 = qvalue(elt(env, 1)); // poly!-vector
    goto v_16981;
v_16982:
    v_16997 = v_16999;
    v_16997 = qcar(v_16997);
    v_16997 = qcar(v_16997);
    v_16998 = qcdr(v_16997);
    goto v_16983;
v_16984:
    v_16997 = v_16999;
    v_16997 = qcar(v_16997);
    v_16997 = qcdr(v_16997);
    goto v_16985;
v_16986:
    goto v_16980;
v_16981:
    goto v_16982;
v_16983:
    goto v_16984;
v_16985:
    *(LispObject *)((char *)v_17000 + (CELL-TAG_VECTOR) + (((intptr_t)v_16998-TAG_FIXNUM)/(16/CELL))) = v_16997;
    v_16997 = v_16999;
    v_16997 = qcdr(v_16997);
    v_16999 = v_16997;
    goto v_16951;
    v_16997 = nil;
v_16950:
    return onevalue(v_16997);
}



// Code for ofsf_smordtable

static LispObject CC_ofsf_smordtable(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_16970, v_16971, v_16972;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16970 = v_16948;
    v_16971 = v_16947;
// end of prologue
    v_16972 = elt(env, 1); // ((equal (equal . false) (neq equal . t) (geq equal . t) (leq . false) (greaterp equal . t) (lessp . false)) (neq (equal equal)
// (neq) (geq) (leq leq) (greaterp) (lessp lessp)) (geq (equal . false) (neq geq . t) (geq geq . t) (leq . false) (greaterp
// geq . t) (lessp . false)) (leq (equal equal) (neq) (geq) (leq leq) (greaterp) (lessp lessp)) (greaterp (equal . false) (neq
// greaterp . t) (geq greaterp . t) (leq . false) (greaterp greaterp . t) (lessp . false)) (lessp (equal equal) (neq) (geq)
// (leq leq) (greaterp) (lessp lessp)))
    goto v_16958;
v_16954:
    goto v_16955;
v_16956:
    goto v_16964;
v_16960:
    goto v_16961;
v_16962:
    goto v_16963;
v_16964:
    goto v_16960;
v_16961:
    goto v_16962;
v_16963:
    v_16971 = Latsoc(nil, v_16971, v_16972);
    goto v_16957;
v_16958:
    goto v_16954;
v_16955:
    goto v_16956;
v_16957:
    v_16970 = Latsoc(nil, v_16970, v_16971);
    v_16970 = qcdr(v_16970);
    return onevalue(v_16970);
}



// Code for checku

static LispObject CC_checku(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_16984, v_16985, v_16986, v_16987;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16985 = v_16948;
    v_16986 = v_16947;
// end of prologue
v_16946:
    v_16984 = v_16986;
    if (v_16984 == nil) goto v_16952;
    else goto v_16953;
v_16952:
    v_16984 = nil;
    goto v_16951;
v_16953:
    goto v_16966;
v_16962:
    v_16984 = v_16985;
    v_16987 = qcar(v_16984);
    goto v_16963;
v_16964:
    v_16984 = v_16986;
    v_16984 = qcar(v_16984);
    v_16984 = qcar(v_16984);
    goto v_16965;
v_16966:
    goto v_16962;
v_16963:
    goto v_16964;
v_16965:
    if (equal(v_16987, v_16984)) goto v_16960;
    else goto v_16961;
v_16960:
    v_16984 = lisp_true;
    goto v_16959;
v_16961:
    goto v_16980;
v_16976:
    v_16984 = v_16986;
    v_16986 = qcdr(v_16984);
    goto v_16977;
v_16978:
    v_16984 = v_16985;
    goto v_16979;
v_16980:
    goto v_16976;
v_16977:
    goto v_16978;
v_16979:
    v_16985 = v_16984;
    goto v_16946;
    v_16984 = nil;
v_16959:
    goto v_16951;
    v_16984 = nil;
v_16951:
    return onevalue(v_16984);
}



// Code for mk!+squared!+norm

static LispObject CC_mkLsquaredLnorm(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_16959, v_16960;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16959 = v_16947;
// end of prologue
    goto v_16956;
v_16952:
    v_16960 = v_16959;
    goto v_16953;
v_16954:
    goto v_16955;
v_16956:
    goto v_16952;
v_16953:
    goto v_16954;
v_16955:
    {
        fn = elt(env, 1); // mk!+inner!+product
        return (*qfn2(fn))(fn, v_16960, v_16959);
    }
    return onevalue(v_16959);
}



// Code for cl_nnfnot

static LispObject CC_cl_nnfnot(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_16957, v_16958;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16957 = v_16947;
// end of prologue
    goto v_16954;
v_16950:
    v_16958 = v_16957;
    goto v_16951;
v_16952:
    v_16957 = nil;
    goto v_16953;
v_16954:
    goto v_16950;
v_16951:
    goto v_16952;
v_16953:
    {
        fn = elt(env, 1); // cl_nnf1
        return (*qfn2(fn))(fn, v_16958, v_16957);
    }
}



// Code for repr_a

static LispObject CC_repr_a(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_16967, v_16968;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16947);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_16947;
// end of prologue
    goto v_16954;
v_16950:
    v_16967 = stack[0];
    v_16967 = qcdr(v_16967);
    v_16967 = qcdr(v_16967);
    v_16967 = qcar(v_16967);
    v_16967 = Lreverse(nil, v_16967);
    env = stack[-1];
    v_16967 = qcar(v_16967);
    v_16968 = qcar(v_16967);
    goto v_16951;
v_16952:
    v_16967 = stack[0];
    v_16967 = qcdr(v_16967);
    v_16967 = qcdr(v_16967);
    v_16967 = qcdr(v_16967);
    v_16967 = qcar(v_16967);
    goto v_16953;
v_16954:
    goto v_16950;
v_16951:
    goto v_16952;
v_16953:
    {
        fn = elt(env, 1); // addf
        return (*qfn2(fn))(fn, v_16968, v_16967);
    }
}



// Code for sfto_lcx

static LispObject CC_sfto_lcx(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_16970, v_16971;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16970 = v_16947;
// end of prologue
    v_16971 = v_16970;
    if (!consp(v_16971)) goto v_16955;
    else goto v_16956;
v_16955:
    v_16971 = lisp_true;
    goto v_16954;
v_16956:
    v_16971 = v_16970;
    v_16971 = qcar(v_16971);
    v_16971 = (consp(v_16971) ? nil : lisp_true);
    goto v_16954;
    v_16971 = nil;
v_16954:
    if (v_16971 == nil) goto v_16952;
    goto v_16950;
v_16952:
    v_16970 = qcar(v_16970);
    v_16970 = qcdr(v_16970);
    goto v_16950;
    v_16970 = nil;
v_16950:
    return onevalue(v_16970);
}



// Code for sfto_b!:extmult

static LispObject CC_sfto_bTextmult(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_17093, v_17094;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16947,v_16948);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_16948;
    stack[-3] = v_16947;
// end of prologue
    v_17093 = stack[-3];
    if (v_17093 == nil) goto v_16956;
    else goto v_16957;
v_16956:
    v_17093 = lisp_true;
    goto v_16955;
v_16957:
    v_17093 = stack[-2];
    v_17093 = (v_17093 == nil ? lisp_true : nil);
    goto v_16955;
    v_17093 = nil;
v_16955:
    if (v_17093 == nil) goto v_16953;
    v_17093 = nil;
    goto v_16951;
v_16953:
    goto v_16971;
v_16967:
    v_17094 = stack[-2];
    goto v_16968;
v_16969:
    v_17093 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16970;
v_16971:
    goto v_16967;
v_16968:
    goto v_16969;
v_16970:
    if (v_17094 == v_17093) goto v_16965;
    else goto v_16966;
v_16965:
    v_17093 = stack[-3];
    goto v_16951;
v_16966:
    goto v_16982;
v_16978:
    v_17093 = stack[-3];
    v_17093 = qcar(v_17093);
    v_17093 = qcar(v_17093);
    v_17094 = qcar(v_17093);
    goto v_16979;
v_16980:
    v_17093 = stack[-2];
    v_17093 = qcar(v_17093);
    v_17093 = qcar(v_17093);
    goto v_16981;
v_16982:
    goto v_16978;
v_16979:
    goto v_16980;
v_16981:
    fn = elt(env, 1); // sfto_b!:ordexn
    v_17093 = (*qfn2(fn))(fn, v_17094, v_17093);
    env = stack[-5];
    v_17094 = v_17093;
    v_17093 = v_17094;
    if (v_17093 == nil) goto v_16994;
    goto v_17003;
v_16997:
    v_17093 = v_17094;
    stack[-4] = qcdr(v_17093);
    goto v_16998;
v_16999:
    v_17093 = v_17094;
    v_17093 = qcar(v_17093);
    if (v_17093 == nil) goto v_17009;
    goto v_17018;
v_17014:
    v_17093 = stack[-3];
    v_17093 = qcar(v_17093);
    v_17094 = qcdr(v_17093);
    goto v_17015;
v_17016:
    v_17093 = stack[-2];
    v_17093 = qcar(v_17093);
    v_17093 = qcdr(v_17093);
    goto v_17017;
v_17018:
    goto v_17014;
v_17015:
    goto v_17016;
v_17017:
    fn = elt(env, 2); // multf
    v_17093 = (*qfn2(fn))(fn, v_17094, v_17093);
    env = stack[-5];
    fn = elt(env, 3); // negf
    v_17093 = (*qfn1(fn))(fn, v_17093);
    env = stack[-5];
    stack[-1] = v_17093;
    goto v_17007;
v_17009:
    goto v_17032;
v_17028:
    v_17093 = stack[-3];
    v_17093 = qcar(v_17093);
    v_17094 = qcdr(v_17093);
    goto v_17029;
v_17030:
    v_17093 = stack[-2];
    v_17093 = qcar(v_17093);
    v_17093 = qcdr(v_17093);
    goto v_17031;
v_17032:
    goto v_17028;
v_17029:
    goto v_17030;
v_17031:
    fn = elt(env, 2); // multf
    v_17093 = (*qfn2(fn))(fn, v_17094, v_17093);
    env = stack[-5];
    stack[-1] = v_17093;
    goto v_17007;
    stack[-1] = nil;
v_17007:
    goto v_17000;
v_17001:
    goto v_17044;
v_17040:
    goto v_17050;
v_17046:
    v_17093 = stack[-3];
    v_17093 = qcar(v_17093);
    v_17094 = ncons(v_17093);
    env = stack[-5];
    goto v_17047;
v_17048:
    v_17093 = stack[-2];
    v_17093 = qcdr(v_17093);
    goto v_17049;
v_17050:
    goto v_17046;
v_17047:
    goto v_17048;
v_17049:
    stack[0] = CC_sfto_bTextmult(elt(env, 0), v_17094, v_17093);
    env = stack[-5];
    goto v_17041;
v_17042:
    goto v_17061;
v_17057:
    v_17093 = stack[-3];
    v_17094 = qcdr(v_17093);
    goto v_17058;
v_17059:
    v_17093 = stack[-2];
    goto v_17060;
v_17061:
    goto v_17057;
v_17058:
    goto v_17059;
v_17060:
    v_17093 = CC_sfto_bTextmult(elt(env, 0), v_17094, v_17093);
    env = stack[-5];
    goto v_17043;
v_17044:
    goto v_17040;
v_17041:
    goto v_17042;
v_17043:
    fn = elt(env, 4); // sfto_b!:extadd
    v_17093 = (*qfn2(fn))(fn, stack[0], v_17093);
    goto v_17002;
v_17003:
    goto v_16997;
v_16998:
    goto v_16999;
v_17000:
    goto v_17001;
v_17002:
    {
        LispObject v_17100 = stack[-4];
        LispObject v_17101 = stack[-1];
        return acons(v_17100, v_17101, v_17093);
    }
v_16994:
    goto v_17072;
v_17068:
    goto v_17078;
v_17074:
    v_17093 = stack[-3];
    v_17094 = qcdr(v_17093);
    goto v_17075;
v_17076:
    v_17093 = stack[-2];
    goto v_17077;
v_17078:
    goto v_17074;
v_17075:
    goto v_17076;
v_17077:
    stack[0] = CC_sfto_bTextmult(elt(env, 0), v_17094, v_17093);
    env = stack[-5];
    goto v_17069;
v_17070:
    goto v_17087;
v_17083:
    v_17093 = stack[-3];
    v_17093 = qcar(v_17093);
    v_17094 = ncons(v_17093);
    env = stack[-5];
    goto v_17084;
v_17085:
    v_17093 = stack[-2];
    v_17093 = qcdr(v_17093);
    goto v_17086;
v_17087:
    goto v_17083;
v_17084:
    goto v_17085;
v_17086:
    v_17093 = CC_sfto_bTextmult(elt(env, 0), v_17094, v_17093);
    env = stack[-5];
    goto v_17071;
v_17072:
    goto v_17068;
v_17069:
    goto v_17070;
v_17071:
    {
        LispObject v_17102 = stack[0];
        fn = elt(env, 4); // sfto_b!:extadd
        return (*qfn2(fn))(fn, v_17102, v_17093);
    }
    v_17093 = nil;
    goto v_16951;
    v_17093 = nil;
v_16951:
    return onevalue(v_17093);
}



// Code for relnrd

static LispObject CC_relnrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16997, v_16998;
    LispObject fn;
    argcheck(nargs, 0, "relnrd");
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
    fn = elt(env, 5); // lex
    v_16997 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_16958;
v_16954:
    v_16998 = qvalue(elt(env, 1)); // atts
    goto v_16955;
v_16956:
    v_16997 = elt(env, 2); // (type definitionurl)
    goto v_16957;
v_16958:
    goto v_16954;
v_16955:
    goto v_16956;
v_16957:
    fn = elt(env, 6); // retattributes
    v_16997 = (*qfn2(fn))(fn, v_16998, v_16997);
    env = stack[-2];
    stack[0] = v_16997;
    goto v_16969;
v_16965:
    v_16997 = qvalue(elt(env, 3)); // char
    fn = elt(env, 7); // compress!*
    v_16998 = (*qfn1(fn))(fn, v_16997);
    env = stack[-2];
    goto v_16966;
v_16967:
    v_16997 = qvalue(elt(env, 4)); // relations!*
    goto v_16968;
v_16969:
    goto v_16965;
v_16966:
    goto v_16967;
v_16968:
    v_16997 = Lassoc(nil, v_16998, v_16997);
    v_16998 = v_16997;
    if (v_16997 == nil) goto v_16964;
    goto v_16981;
v_16975:
    v_16997 = v_16998;
    v_16997 = qcdr(v_16997);
    v_16997 = qcdr(v_16997);
    stack[-1] = qcar(v_16997);
    goto v_16976;
v_16977:
    goto v_16978;
v_16979:
    goto v_16992;
v_16988:
    v_16997 = v_16998;
    v_16997 = qcdr(v_16997);
    v_16998 = qcar(v_16997);
    goto v_16989;
v_16990:
    v_16997 = nil;
    goto v_16991;
v_16992:
    goto v_16988;
v_16989:
    goto v_16990;
v_16991:
    fn = elt(env, 8); // apply
    v_16997 = (*qfn2(fn))(fn, v_16998, v_16997);
    goto v_16980;
v_16981:
    goto v_16975;
v_16976:
    goto v_16977;
v_16978:
    goto v_16979;
v_16980:
    {
        LispObject v_17001 = stack[-1];
        LispObject v_17002 = stack[0];
        return list2star(v_17001, v_17002, v_16997);
    }
v_16964:
    v_16997 = nil;
    return onevalue(v_16997);
}



// Code for bcminus!?

static LispObject CC_bcminusW(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_16960, v_16961;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16961 = v_16947;
// end of prologue
    v_16960 = qvalue(elt(env, 1)); // !*grmod!*
    if (v_16960 == nil) goto v_16951;
    else goto v_16952;
v_16951:
    v_16960 = v_16961;
    v_16960 = qcar(v_16960);
    {
        fn = elt(env, 2); // minusf
        return (*qfn1(fn))(fn, v_16960);
    }
v_16952:
    v_16960 = nil;
    goto v_16950;
    v_16960 = nil;
v_16950:
    return onevalue(v_16960);
}



// Code for dipprod

static LispObject CC_dipprod(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_16982, v_16983;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16947,v_16948);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16948;
    stack[-1] = v_16947;
// end of prologue
    goto v_16959;
v_16955:
    v_16982 = stack[-1];
    fn = elt(env, 1); // diplength
    stack[-2] = (*qfn1(fn))(fn, v_16982);
    env = stack[-3];
    goto v_16956;
v_16957:
    v_16982 = stack[0];
    fn = elt(env, 1); // diplength
    v_16982 = (*qfn1(fn))(fn, v_16982);
    env = stack[-3];
    goto v_16958;
v_16959:
    goto v_16955;
v_16956:
    goto v_16957;
v_16958:
    v_16982 = (LispObject)lesseq2(stack[-2], v_16982);
    v_16982 = v_16982 ? lisp_true : nil;
    env = stack[-3];
    if (v_16982 == nil) goto v_16953;
    goto v_16969;
v_16965:
    v_16983 = stack[-1];
    goto v_16966;
v_16967:
    v_16982 = stack[0];
    goto v_16968;
v_16969:
    goto v_16965;
v_16966:
    goto v_16967;
v_16968:
    {
        fn = elt(env, 2); // dipprodin
        return (*qfn2(fn))(fn, v_16983, v_16982);
    }
v_16953:
    goto v_16979;
v_16975:
    v_16983 = stack[0];
    goto v_16976;
v_16977:
    v_16982 = stack[-1];
    goto v_16978;
v_16979:
    goto v_16975;
v_16976:
    goto v_16977;
v_16978:
    {
        fn = elt(env, 2); // dipprodin
        return (*qfn2(fn))(fn, v_16983, v_16982);
    }
    v_16982 = nil;
    return onevalue(v_16982);
}



// Code for basisformp

static LispObject CC_basisformp(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_16965, v_16966;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16966 = v_16947;
// end of prologue
    v_16965 = v_16966;
    if (!consp(v_16965)) goto v_16952;
    goto v_16958;
v_16954:
    v_16965 = v_16966;
    goto v_16955;
v_16956:
    v_16966 = qvalue(elt(env, 1)); // basisforml!*
    goto v_16957;
v_16958:
    goto v_16954;
v_16955:
    goto v_16956;
v_16957:
    v_16965 = Lmemq(nil, v_16965, v_16966);
    goto v_16950;
v_16952:
    v_16965 = nil;
    goto v_16950;
    v_16965 = nil;
v_16950:
    return onevalue(v_16965);
}



// Code for nconc2

static LispObject CC_nconc2(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_16982, v_16983, v_16984;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16947,v_16948);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_16983 = v_16948;
    v_16984 = v_16947;
// end of prologue
    v_16982 = v_16984;
    if (!consp(v_16982)) goto v_16955;
    else goto v_16956;
v_16955:
    v_16982 = v_16983;
    goto v_16952;
v_16956:
    v_16982 = v_16984;
    stack[0] = v_16982;
v_16962:
    v_16982 = stack[0];
    v_16982 = qcdr(v_16982);
    v_16982 = Lconsp(nil, v_16982);
    env = stack[-1];
    if (v_16982 == nil) goto v_16965;
    else goto v_16966;
v_16965:
    goto v_16961;
v_16966:
    v_16982 = stack[0];
    v_16982 = qcdr(v_16982);
    stack[0] = v_16982;
    goto v_16962;
v_16961:
    goto v_16978;
v_16974:
    v_16982 = stack[0];
    goto v_16975;
v_16976:
    goto v_16977;
v_16978:
    goto v_16974;
v_16975:
    goto v_16976;
v_16977:
    v_16982 = Lrplacd(nil, v_16982, v_16983);
    v_16982 = stack[0];
v_16952:
    return onevalue(v_16982);
}



// Code for formatfort

static LispObject CC_formatfort(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_17142, v_17143, v_17144;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16947);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_16947;
// end of prologue
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-5, 1, -2);
    qvalue(elt(env, 1)) = nil; // !*lower
    v_17142 = (LispObject)4800+TAG_FIXNUM; // 300
    v_17142 = Llinelength(nil, v_17142);
    env = stack[-5];
    stack[-4] = v_17142;
    v_17142 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 2)) = v_17142; // !*posn!*
    v_17142 = stack[0];
    stack[-1] = v_17142;
v_16960:
    v_17142 = stack[-1];
    if (v_17142 == nil) goto v_16964;
    else goto v_16965;
v_16964:
    goto v_16959;
v_16965:
    v_17142 = stack[-1];
    v_17142 = qcar(v_17142);
    stack[0] = v_17142;
    v_17142 = stack[0];
    v_17142 = Lconsp(nil, v_17142);
    env = stack[-5];
    if (v_17142 == nil) goto v_16974;
    v_17142 = stack[0];
    fn = elt(env, 10); // lispeval
    v_17142 = (*qfn1(fn))(fn, v_17142);
    env = stack[-5];
    goto v_16972;
v_16974:
    v_17142 = stack[0];
    v_17142 = integerp(v_17142);
    if (v_17142 == nil) goto v_16984;
    goto v_16995;
v_16991:
    v_17143 = stack[0];
    goto v_16992;
v_16993:
    v_17142 = qvalue(elt(env, 3)); // maxint
    goto v_16994;
v_16995:
    goto v_16991;
v_16992:
    goto v_16993;
v_16994:
    v_17142 = (LispObject)greaterp2(v_17143, v_17142);
    v_17142 = v_17142 ? lisp_true : nil;
    env = stack[-5];
    if (v_17142 == nil) goto v_16989;
    else goto v_16988;
v_16989:
    goto v_17004;
v_17000:
    stack[-3] = stack[0];
    goto v_17001;
v_17002:
    v_17142 = qvalue(elt(env, 3)); // maxint
    v_17142 = negate(v_17142);
    env = stack[-5];
    goto v_17003;
v_17004:
    goto v_17000;
v_17001:
    goto v_17002;
v_17003:
    v_17142 = (LispObject)lessp2(stack[-3], v_17142);
    v_17142 = v_17142 ? lisp_true : nil;
    env = stack[-5];
    if (v_17142 == nil) goto v_16998;
    else goto v_16988;
v_16998:
    goto v_16984;
v_16988:
    v_17142 = stack[0];
    fn = elt(env, 11); // i2rd!*
    v_17142 = (*qfn1(fn))(fn, v_17142);
    env = stack[-5];
    v_17142 = qcdr(v_17142);
    stack[0] = v_17142;
    goto v_16982;
v_16984:
v_16982:
    v_17142 = stack[0];
    v_17142 = Lexplodec(nil, v_17142);
    env = stack[-5];
    stack[-3] = v_17142;
    v_17142 = stack[0];
    v_17142 = Lfloatp(nil, v_17142);
    env = stack[-5];
    if (v_17142 == nil) goto v_17016;
    v_17142 = qvalue(elt(env, 4)); // !*double
    if (v_17142 == nil) goto v_17022;
    goto v_17032;
v_17028:
    v_17143 = elt(env, 5); // e
    goto v_17029;
v_17030:
    v_17142 = stack[-3];
    goto v_17031;
v_17032:
    goto v_17028;
v_17029:
    goto v_17030;
v_17031:
    v_17142 = Lmemq(nil, v_17143, v_17142);
    if (v_17142 == nil) goto v_17027;
    goto v_17043;
v_17037:
    v_17144 = elt(env, 6); // !D
    goto v_17038;
v_17039:
    v_17143 = elt(env, 5); // e
    goto v_17040;
v_17041:
    v_17142 = stack[-3];
    goto v_17042;
v_17043:
    goto v_17037;
v_17038:
    goto v_17039;
v_17040:
    goto v_17041;
v_17042:
    v_17142 = Lsubst(nil, 3, v_17144, v_17143, v_17142);
    env = stack[-5];
    stack[-3] = v_17142;
    goto v_17025;
v_17027:
    goto v_17053;
v_17049:
    v_17143 = elt(env, 7); // !E
    goto v_17050;
v_17051:
    v_17142 = stack[-3];
    goto v_17052;
v_17053:
    goto v_17049;
v_17050:
    goto v_17051;
v_17052:
    v_17142 = Lmemq(nil, v_17143, v_17142);
    if (v_17142 == nil) goto v_17048;
    goto v_17064;
v_17058:
    v_17144 = elt(env, 6); // !D
    goto v_17059;
v_17060:
    v_17143 = elt(env, 7); // !E
    goto v_17061;
v_17062:
    v_17142 = stack[-3];
    goto v_17063;
v_17064:
    goto v_17058;
v_17059:
    goto v_17060;
v_17061:
    goto v_17062;
v_17063:
    v_17142 = Lsubst(nil, 3, v_17144, v_17143, v_17142);
    env = stack[-5];
    stack[-3] = v_17142;
    goto v_17025;
v_17048:
    goto v_17075;
v_17071:
    v_17143 = stack[-3];
    goto v_17072;
v_17073:
    v_17142 = elt(env, 8); // (d !0)
    goto v_17074;
v_17075:
    goto v_17071;
v_17072:
    goto v_17073;
v_17074:
    v_17142 = Lappend(nil, v_17143, v_17142);
    env = stack[-5];
    stack[-3] = v_17142;
    goto v_17025;
v_17025:
    goto v_17020;
v_17022:
    goto v_17084;
v_17080:
    v_17143 = elt(env, 5); // e
    goto v_17081;
v_17082:
    v_17142 = stack[-3];
    goto v_17083;
v_17084:
    goto v_17080;
v_17081:
    goto v_17082;
v_17083:
    v_17142 = Lmemq(nil, v_17143, v_17142);
    if (v_17142 == nil) goto v_17079;
    goto v_17095;
v_17089:
    v_17144 = elt(env, 7); // !E
    goto v_17090;
v_17091:
    v_17143 = elt(env, 5); // e
    goto v_17092;
v_17093:
    v_17142 = stack[-3];
    goto v_17094;
v_17095:
    goto v_17089;
v_17090:
    goto v_17091;
v_17092:
    goto v_17093;
v_17094:
    v_17142 = Lsubst(nil, 3, v_17144, v_17143, v_17142);
    env = stack[-5];
    stack[-3] = v_17142;
    goto v_17020;
v_17079:
v_17020:
    goto v_17014;
v_17016:
v_17014:
    goto v_17108;
v_17104:
    goto v_17114;
v_17110:
    stack[0] = qvalue(elt(env, 2)); // !*posn!*
    goto v_17111;
v_17112:
    v_17142 = stack[-3];
    v_17142 = Llength(nil, v_17142);
    env = stack[-5];
    goto v_17113;
v_17114:
    goto v_17110;
v_17111:
    goto v_17112;
v_17113:
    v_17143 = plus2(stack[0], v_17142);
    env = stack[-5];
    goto v_17105;
v_17106:
    v_17142 = qvalue(elt(env, 9)); // fortlinelen!*
    goto v_17107;
v_17108:
    goto v_17104;
v_17105:
    goto v_17106;
v_17107:
    v_17142 = (LispObject)greaterp2(v_17143, v_17142);
    v_17142 = v_17142 ? lisp_true : nil;
    env = stack[-5];
    if (v_17142 == nil) goto v_17102;
    fn = elt(env, 12); // fortcontline
    v_17142 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17100;
v_17102:
v_17100:
    v_17142 = stack[-3];
    stack[0] = v_17142;
v_17123:
    v_17142 = stack[0];
    if (v_17142 == nil) goto v_17127;
    else goto v_17128;
v_17127:
    goto v_17122;
v_17128:
    v_17142 = stack[0];
    v_17142 = qcar(v_17142);
    fn = elt(env, 13); // pprin2
    v_17142 = (*qfn1(fn))(fn, v_17142);
    env = stack[-5];
    v_17142 = stack[0];
    v_17142 = qcdr(v_17142);
    stack[0] = v_17142;
    goto v_17123;
v_17122:
    goto v_16972;
v_16972:
    v_17142 = stack[-1];
    v_17142 = qcdr(v_17142);
    stack[-1] = v_17142;
    goto v_16960;
v_16959:
    v_17142 = stack[-4];
    v_17142 = Llinelength(nil, v_17142);
    v_17142 = nil;
    ;}  // end of a binding scope
    return onevalue(v_17142);
}



// Code for locate_member

static LispObject CC_locate_member(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_16986, v_16987, v_16988, v_16989;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16947,v_16948);
    }
// copy arguments values to proper place
    v_16988 = v_16948;
    v_16989 = v_16947;
// end of prologue
    goto v_16958;
v_16954:
    v_16987 = v_16989;
    goto v_16955;
v_16956:
    v_16986 = v_16988;
    goto v_16957;
v_16958:
    goto v_16954;
v_16955:
    goto v_16956;
v_16957:
    v_16986 = Lmember(nil, v_16987, v_16986);
    if (v_16986 == nil) goto v_16952;
    else goto v_16953;
v_16952:
    v_16986 = nil;
    goto v_16951;
v_16953:
    goto v_16969;
v_16965:
    v_16987 = v_16989;
    goto v_16966;
v_16967:
    v_16986 = v_16988;
    v_16986 = qcar(v_16986);
    goto v_16968;
v_16969:
    goto v_16965;
v_16966:
    goto v_16967;
v_16968:
    if (equal(v_16987, v_16986)) goto v_16963;
    else goto v_16964;
v_16963:
    v_16986 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16951;
v_16964:
    goto v_16982;
v_16978:
    v_16986 = v_16989;
    goto v_16979;
v_16980:
    v_16987 = v_16988;
    v_16987 = qcdr(v_16987);
    goto v_16981;
v_16982:
    goto v_16978;
v_16979:
    goto v_16980;
v_16981:
    v_16986 = CC_locate_member(elt(env, 0), v_16986, v_16987);
    return add1(v_16986);
    v_16986 = nil;
v_16951:
    return onevalue(v_16986);
}



// Code for ra_wrapper1

static LispObject CC_ra_wrapper1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16977, v_16978;
    LispObject fn;
    LispObject v_16949, v_16948, v_16947;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ra_wrapper1");
    va_start(aa, nargs);
    v_16947 = va_arg(aa, LispObject);
    v_16948 = va_arg(aa, LispObject);
    v_16949 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_16949,v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_16947,v_16948,v_16949);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16949;
    stack[-1] = v_16948;
    stack[-2] = v_16947;
// end of prologue
    v_16977 = stack[0];
    if (v_16977 == nil) goto v_16957;
    v_16977 = stack[0];
    fn = elt(env, 1); // off1
    v_16977 = (*qfn1(fn))(fn, v_16977);
    env = stack[-3];
    goto v_16955;
v_16957:
v_16955:
    goto v_16966;
v_16962:
    v_16978 = stack[-2];
    goto v_16963;
v_16964:
    v_16977 = stack[-1];
    goto v_16965;
v_16966:
    goto v_16962;
v_16963:
    goto v_16964;
v_16965:
    fn = elt(env, 2); // apply
    v_16977 = (*qfn2(fn))(fn, v_16978, v_16977);
    env = stack[-3];
    stack[-1] = v_16977;
    v_16977 = stack[0];
    if (v_16977 == nil) goto v_16972;
    v_16977 = stack[0];
    fn = elt(env, 3); // on1
    v_16977 = (*qfn1(fn))(fn, v_16977);
    goto v_16970;
v_16972:
v_16970:
    v_16977 = stack[-1];
    return onevalue(v_16977);
}



// Code for deginvar

static LispObject CC_deginvar(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_17003, v_17004;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16947,v_16948);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16948;
    stack[-1] = v_16947;
// end of prologue
    v_17003 = stack[-1];
    fn = elt(env, 2); // wuconstantp
    v_17003 = (*qfn1(fn))(fn, v_17003);
    env = stack[-3];
    if (v_17003 == nil) goto v_16953;
    v_17003 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16951;
v_16953:
    goto v_16963;
v_16959:
    v_17003 = stack[-1];
    v_17003 = qcar(v_17003);
    v_17003 = qcar(v_17003);
    v_17004 = qcar(v_17003);
    goto v_16960;
v_16961:
    v_17003 = stack[0];
    goto v_16962;
v_16963:
    goto v_16959;
v_16960:
    goto v_16961;
v_16962:
    if (equal(v_17004, v_17003)) goto v_16957;
    else goto v_16958;
v_16957:
    v_17003 = stack[-1];
    v_17003 = qcar(v_17003);
    v_17003 = qcar(v_17003);
    v_17003 = qcdr(v_17003);
    goto v_16951;
v_16958:
// Binding kord!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = nil; // kord!*
    v_17003 = stack[0];
    v_17003 = ncons(v_17003);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_17003; // kord!*
    v_17003 = stack[-1];
    fn = elt(env, 3); // reorder
    v_17003 = (*qfn1(fn))(fn, v_17003);
    stack[-1] = v_17003;
    goto v_16990;
v_16986:
    v_17003 = stack[-1];
    v_17003 = qcar(v_17003);
    v_17003 = qcar(v_17003);
    v_17004 = qcar(v_17003);
    goto v_16987;
v_16988:
    v_17003 = stack[0];
    goto v_16989;
v_16990:
    goto v_16986;
v_16987:
    goto v_16988;
v_16989:
    if (equal(v_17004, v_17003)) goto v_16984;
    else goto v_16985;
v_16984:
    v_17003 = stack[-1];
    v_17003 = qcar(v_17003);
    v_17003 = qcar(v_17003);
    v_17003 = qcdr(v_17003);
    goto v_16983;
v_16985:
    v_17003 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16983;
    v_17003 = nil;
v_16983:
    ;}  // end of a binding scope
    goto v_16951;
    v_17003 = nil;
v_16951:
    return onevalue(v_17003);
}



// Code for vunion

static LispObject CC_vunion(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_17050, v_17051;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16947,v_16948);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_16948;
    stack[-2] = v_16947;
// end of prologue
    v_17050 = stack[-2];
    if (v_17050 == nil) goto v_16955;
    else goto v_16956;
v_16955:
    v_17050 = stack[-1];
    goto v_16954;
v_16956:
    goto v_16965;
v_16961:
    v_17050 = stack[-2];
    v_17050 = qcar(v_17050);
    v_17051 = qcar(v_17050);
    goto v_16962;
v_16963:
    v_17050 = stack[-1];
    goto v_16964;
v_16965:
    goto v_16961;
v_16962:
    goto v_16963;
v_16964:
    v_17050 = Lassoc(nil, v_17051, v_17050);
    stack[-3] = v_17050;
    if (v_17050 == nil) goto v_16959;
    else goto v_16960;
v_16959:
    goto v_16976;
v_16972:
    v_17050 = stack[-2];
    stack[0] = qcar(v_17050);
    goto v_16973;
v_16974:
    goto v_16984;
v_16980:
    v_17050 = stack[-2];
    v_17051 = qcdr(v_17050);
    goto v_16981;
v_16982:
    v_17050 = stack[-1];
    goto v_16983;
v_16984:
    goto v_16980;
v_16981:
    goto v_16982;
v_16983:
    v_17050 = CC_vunion(elt(env, 0), v_17051, v_17050);
    goto v_16975;
v_16976:
    goto v_16972;
v_16973:
    goto v_16974;
v_16975:
    {
        LispObject v_17056 = stack[0];
        return cons(v_17056, v_17050);
    }
v_16960:
    goto v_16995;
v_16991:
    v_17050 = stack[-2];
    v_17050 = qcar(v_17050);
    v_17051 = qcdr(v_17050);
    goto v_16992;
v_16993:
    v_17050 = stack[-3];
    v_17050 = qcdr(v_17050);
    goto v_16994;
v_16995:
    goto v_16991;
v_16992:
    goto v_16993;
v_16994:
    v_17050 = (LispObject)greaterp2(v_17051, v_17050);
    v_17050 = v_17050 ? lisp_true : nil;
    env = stack[-4];
    if (v_17050 == nil) goto v_16989;
    goto v_17006;
v_17002:
    v_17050 = stack[-2];
    stack[0] = qcar(v_17050);
    goto v_17003;
v_17004:
    goto v_17014;
v_17010:
    v_17050 = stack[-2];
    stack[-2] = qcdr(v_17050);
    goto v_17011;
v_17012:
    goto v_17022;
v_17018:
    v_17051 = stack[-3];
    goto v_17019;
v_17020:
    v_17050 = stack[-1];
    goto v_17021;
v_17022:
    goto v_17018;
v_17019:
    goto v_17020;
v_17021:
    v_17050 = Ldelete(nil, v_17051, v_17050);
    env = stack[-4];
    goto v_17013;
v_17014:
    goto v_17010;
v_17011:
    goto v_17012;
v_17013:
    v_17050 = CC_vunion(elt(env, 0), stack[-2], v_17050);
    goto v_17005;
v_17006:
    goto v_17002;
v_17003:
    goto v_17004;
v_17005:
    {
        LispObject v_17057 = stack[0];
        return cons(v_17057, v_17050);
    }
v_16989:
    goto v_17032;
v_17028:
    stack[0] = stack[-3];
    goto v_17029;
v_17030:
    goto v_17039;
v_17035:
    v_17050 = stack[-2];
    stack[-2] = qcdr(v_17050);
    goto v_17036;
v_17037:
    goto v_17047;
v_17043:
    v_17051 = stack[-3];
    goto v_17044;
v_17045:
    v_17050 = stack[-1];
    goto v_17046;
v_17047:
    goto v_17043;
v_17044:
    goto v_17045;
v_17046:
    v_17050 = Ldelete(nil, v_17051, v_17050);
    env = stack[-4];
    goto v_17038;
v_17039:
    goto v_17035;
v_17036:
    goto v_17037;
v_17038:
    v_17050 = CC_vunion(elt(env, 0), stack[-2], v_17050);
    goto v_17031;
v_17032:
    goto v_17028;
v_17029:
    goto v_17030;
v_17031:
    {
        LispObject v_17058 = stack[0];
        return cons(v_17058, v_17050);
    }
    v_17050 = nil;
v_16954:
    return onevalue(v_17050);
}



// Code for dfconst

static LispObject CC_dfconst(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_16968, v_16969;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16947);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_16947;
// end of prologue
    v_16968 = stack[0];
    v_16968 = qcar(v_16968);
    if (v_16968 == nil) goto v_16951;
    else goto v_16952;
v_16951:
    v_16968 = nil;
    goto v_16950;
v_16952:
    goto v_16964;
v_16960:
    v_16968 = qvalue(elt(env, 1)); // zlist
    fn = elt(env, 2); // vp2
    v_16969 = (*qfn1(fn))(fn, v_16968);
    env = stack[-1];
    goto v_16961;
v_16962:
    v_16968 = stack[0];
    goto v_16963;
v_16964:
    goto v_16960;
v_16961:
    goto v_16962;
v_16963:
    v_16968 = cons(v_16969, v_16968);
    return ncons(v_16968);
    v_16968 = nil;
v_16950:
    return onevalue(v_16968);
}



// Code for ofsf_xor

static LispObject CC_ofsf_xor(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_16971, v_16972, v_16973;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16971 = v_16948;
    v_16972 = v_16947;
// end of prologue
    v_16973 = v_16972;
    if (v_16973 == nil) goto v_16954;
    else goto v_16953;
v_16954:
    v_16973 = v_16971;
    if (v_16973 == nil) goto v_16956;
    else goto v_16953;
v_16956:
    v_16971 = nil;
    goto v_16951;
v_16953:
    if (v_16972 == nil) goto v_16963;
    else goto v_16964;
v_16963:
    v_16971 = nil;
    goto v_16962;
v_16964:
    goto v_16962;
    v_16971 = nil;
v_16962:
    v_16971 = (v_16971 == nil ? lisp_true : nil);
    goto v_16951;
    v_16971 = nil;
v_16951:
    return onevalue(v_16971);
}



// Code for exptplus

static LispObject CC_exptplus(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_16997, v_16998, v_16999;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16947,v_16948);
    }
// copy arguments values to proper place
    v_16998 = v_16948;
    v_16999 = v_16947;
// end of prologue
    v_16997 = v_16999;
    if (!consp(v_16997)) goto v_16952;
    else goto v_16953;
v_16952:
    v_16997 = v_16998;
    if (!consp(v_16997)) goto v_16957;
    else goto v_16958;
v_16957:
    goto v_16965;
v_16961:
    v_16997 = v_16999;
    goto v_16962;
v_16963:
    goto v_16964;
v_16965:
    goto v_16961;
v_16962:
    goto v_16963;
v_16964:
    return plus2(v_16997, v_16998);
v_16958:
    goto v_16976;
v_16972:
    v_16997 = v_16999;
    goto v_16973;
v_16974:
    v_16998 = qcar(v_16998);
    goto v_16975;
v_16976:
    goto v_16972;
v_16973:
    goto v_16974;
v_16975:
    v_16997 = plus2(v_16997, v_16998);
    return ncons(v_16997);
    v_16997 = nil;
    goto v_16951;
v_16953:
    v_16997 = v_16998;
    if (!consp(v_16997)) goto v_16980;
    else goto v_16981;
v_16980:
    goto v_16989;
v_16985:
    v_16997 = v_16999;
    v_16997 = qcar(v_16997);
    goto v_16986;
v_16987:
    goto v_16988;
v_16989:
    goto v_16985;
v_16986:
    goto v_16987;
v_16988:
    v_16997 = plus2(v_16997, v_16998);
    return ncons(v_16997);
v_16981:
    v_16997 = elt(env, 1); // "Bad exponent sum"
    {
        fn = elt(env, 2); // interr
        return (*qfn1(fn))(fn, v_16997);
    }
    v_16997 = nil;
v_16951:
    return onevalue(v_16997);
}



// Code for unify

static LispObject CC_unify(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17172, v_17173, v_17174, v_17175, v_17176;
    LispObject fn;
    LispObject v_16954, v_16953, v_16952, v_16951, v_16950;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "unify");
    va_start(aa, nargs);
    v_16950 = va_arg(aa, LispObject);
    v_16951 = va_arg(aa, LispObject);
    v_16952 = va_arg(aa, LispObject);
    v_16953 = va_arg(aa, LispObject);
    v_16954 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_16954,v_16953,v_16952,v_16951,v_16950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_16950,v_16951,v_16952,v_16953,v_16954);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(17);
// copy arguments values to proper place
    stack[-13] = v_16954;
    stack[-14] = v_16953;
    v_17173 = v_16952;
    v_17174 = v_16951;
    v_17172 = v_16950;
// end of prologue
// Binding op
// FLUIDBIND: reloadenv=16 litvec-offset=1 saveloc=15
{   bind_fluid_stack bind_fluid_var(-16, 1, -15);
// Binding r
// FLUIDBIND: reloadenv=16 litvec-offset=2 saveloc=12
{   bind_fluid_stack bind_fluid_var(-16, 2, -12);
// Binding p
// FLUIDBIND: reloadenv=16 litvec-offset=3 saveloc=11
{   bind_fluid_stack bind_fluid_var(-16, 3, -11);
    qvalue(elt(env, 1)) = v_17172; // op
    v_17172 = v_17174;
    qvalue(elt(env, 2)) = v_17172; // r
    v_17172 = v_17173;
    qvalue(elt(env, 3)) = v_17172; // p
    v_17172 = qvalue(elt(env, 2)); // r
    if (v_17172 == nil) goto v_16970;
    else goto v_16971;
v_16970:
    v_17172 = qvalue(elt(env, 3)); // p
    v_17172 = (v_17172 == nil ? lisp_true : nil);
    goto v_16969;
v_16971:
    v_17172 = nil;
    goto v_16969;
    v_17172 = nil;
v_16969:
    if (v_17172 == nil) goto v_16967;
    goto v_16983;
v_16979:
    v_17173 = stack[-14];
    goto v_16980;
v_16981:
    v_17172 = stack[-13];
    goto v_16982;
v_16983:
    goto v_16979;
v_16980:
    goto v_16981;
v_16982:
    fn = elt(env, 13); // resume
    v_17172 = (*qfn2(fn))(fn, v_17173, v_17172);
    goto v_16965;
v_16967:
    v_17172 = qvalue(elt(env, 2)); // r
    if (v_17172 == nil) goto v_16986;
    else goto v_16987;
v_16986:
    v_17172 = elt(env, 4); // "UNIFY:pattern over-run for function "
    v_17172 = Lprinc(nil, v_17172);
    env = stack[-16];
    v_17172 = qvalue(elt(env, 1)); // op
    v_17172 = Lprint(nil, v_17172);
    v_17172 = nil;
    goto v_16965;
v_16987:
    v_17172 = qvalue(elt(env, 3)); // p
    if (v_17172 == nil) goto v_16998;
    else goto v_16999;
v_16998:
    v_17172 = qvalue(elt(env, 1)); // op
    fn = elt(env, 14); // ident
    v_17172 = (*qfn1(fn))(fn, v_17172);
    env = stack[-16];
    if (v_17172 == nil) goto v_17003;
    else goto v_17002;
v_17003:
    v_17172 = qvalue(elt(env, 2)); // r
    v_17172 = qcar(v_17172);
    fn = elt(env, 15); // mgenp
    v_17172 = (*qfn1(fn))(fn, v_17172);
    env = stack[-16];
v_17002:
    v_17172 = (v_17172 == nil ? lisp_true : nil);
    goto v_16997;
v_16999:
    v_17172 = nil;
    goto v_16997;
    v_17172 = nil;
v_16997:
    if (v_17172 == nil) goto v_16995;
    v_17172 = nil;
    goto v_16965;
v_16995:
    stack[0] = nil;
    stack[-9] = nil;
// Binding symm
// FLUIDBIND: reloadenv=16 litvec-offset=5 saveloc=8
{   bind_fluid_stack bind_fluid_var(-16, 5, -8);
    qvalue(elt(env, 5)) = nil; // symm
// Binding comb
// FLUIDBIND: reloadenv=16 litvec-offset=6 saveloc=7
{   bind_fluid_stack bind_fluid_var(-16, 6, -7);
    qvalue(elt(env, 6)) = nil; // comb
// Binding identity
// FLUIDBIND: reloadenv=16 litvec-offset=7 saveloc=6
{   bind_fluid_stack bind_fluid_var(-16, 7, -6);
    qvalue(elt(env, 7)) = nil; // identity
// Binding mcontract
// FLUIDBIND: reloadenv=16 litvec-offset=8 saveloc=5
{   bind_fluid_stack bind_fluid_var(-16, 8, -5);
    qvalue(elt(env, 8)) = nil; // mcontract
// Binding acontract
// FLUIDBIND: reloadenv=16 litvec-offset=9 saveloc=4
{   bind_fluid_stack bind_fluid_var(-16, 9, -4);
    qvalue(elt(env, 9)) = nil; // acontract
// Binding expand
// FLUIDBIND: reloadenv=16 litvec-offset=10 saveloc=3
{   bind_fluid_stack bind_fluid_var(-16, 10, -3);
    qvalue(elt(env, 10)) = nil; // expand
// Binding i
// FLUIDBIND: reloadenv=16 litvec-offset=11 saveloc=2
{   bind_fluid_stack bind_fluid_var(-16, 11, -2);
    qvalue(elt(env, 11)) = nil; // i
// Binding upb
// FLUIDBIND: reloadenv=16 litvec-offset=12 saveloc=1
{   bind_fluid_stack bind_fluid_var(-16, 12, -1);
    qvalue(elt(env, 12)) = nil; // upb
    v_17172 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 11)) = v_17172; // i
    v_17172 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 12)) = v_17172; // upb
    v_17172 = qvalue(elt(env, 2)); // r
    v_17172 = qcar(v_17172);
    fn = elt(env, 16); // pm!:free
    v_17172 = (*qfn1(fn))(fn, v_17172);
    env = stack[-16];
    if (v_17172 == nil) goto v_17034;
    goto v_17043;
v_17039:
    v_17172 = qvalue(elt(env, 2)); // r
    v_17172 = qcar(v_17172);
    fn = elt(env, 17); // genp
    v_17173 = (*qfn1(fn))(fn, v_17172);
    env = stack[-16];
    goto v_17040;
v_17041:
    v_17172 = stack[-14];
    goto v_17042;
v_17043:
    goto v_17039;
v_17040:
    goto v_17041;
v_17042:
    v_17172 = cons(v_17173, v_17172);
    env = stack[-16];
    stack[-14] = v_17172;
    goto v_17032;
v_17034:
v_17032:
    v_17172 = qvalue(elt(env, 3)); // p
    fn = elt(env, 18); // initarg
    v_17172 = (*qfn1(fn))(fn, v_17172);
    env = stack[-16];
v_17052:
    v_17172 = stack[0];
    if (v_17172 == nil) goto v_17059;
    else goto v_17060;
v_17059:
    v_17172 = qvalue(elt(env, 3)); // p
    fn = elt(env, 19); // nextarg
    v_17172 = (*qfn1(fn))(fn, v_17172);
    env = stack[-16];
    stack[-9] = v_17172;
    goto v_17058;
v_17060:
    v_17172 = nil;
    goto v_17058;
    v_17172 = nil;
v_17058:
    if (v_17172 == nil) goto v_17055;
    else goto v_17056;
v_17055:
    goto v_17051;
v_17056:
    v_17172 = qvalue(elt(env, 2)); // r
    v_17172 = qcar(v_17172);
    if (!consp(v_17172)) goto v_17073;
    goto v_17087;
v_17077:
    v_17176 = qvalue(elt(env, 1)); // op
    goto v_17078;
v_17079:
    v_17175 = qvalue(elt(env, 2)); // r
    goto v_17080;
v_17081:
    v_17174 = stack[-9];
    goto v_17082;
v_17083:
    v_17173 = stack[-14];
    goto v_17084;
v_17085:
    v_17172 = stack[-13];
    goto v_17086;
v_17087:
    goto v_17077;
v_17078:
    goto v_17079;
v_17080:
    goto v_17081;
v_17082:
    goto v_17083;
v_17084:
    goto v_17085;
v_17086:
    fn = elt(env, 20); // suspend
    v_17172 = (*qfnn(fn))(fn, 5, v_17176, v_17175, v_17174, v_17173, v_17172);
    env = stack[-16];
    stack[0] = v_17172;
    goto v_17071;
v_17073:
    v_17172 = qvalue(elt(env, 2)); // r
    v_17172 = qcar(v_17172);
    fn = elt(env, 16); // pm!:free
    v_17172 = (*qfn1(fn))(fn, v_17172);
    env = stack[-16];
    if (v_17172 == nil) goto v_17094;
    goto v_17105;
v_17101:
    v_17172 = qvalue(elt(env, 2)); // r
    v_17173 = qcar(v_17172);
    goto v_17102;
v_17103:
    v_17172 = stack[-9];
    v_17172 = qcar(v_17172);
    goto v_17104;
v_17105:
    goto v_17101;
v_17102:
    goto v_17103;
v_17104:
    fn = elt(env, 21); // bind
    v_17172 = (*qfn2(fn))(fn, v_17173, v_17172);
    env = stack[-16];
    v_17172 = stack[-14];
    fn = elt(env, 22); // chk
    v_17172 = (*qfn1(fn))(fn, v_17172);
    env = stack[-16];
    stack[-10] = v_17172;
    if (v_17172 == nil) goto v_17113;
    goto v_17127;
v_17117:
    stack[0] = qvalue(elt(env, 1)); // op
    goto v_17118;
v_17119:
    v_17172 = qvalue(elt(env, 2)); // r
    v_17172 = qcdr(v_17172);
    fn = elt(env, 23); // mval
    v_17175 = (*qfn1(fn))(fn, v_17172);
    env = stack[-16];
    goto v_17120;
v_17121:
    v_17172 = stack[-9];
    v_17174 = qcdr(v_17172);
    goto v_17122;
v_17123:
    v_17173 = stack[-10];
    goto v_17124;
v_17125:
    v_17172 = stack[-13];
    goto v_17126;
v_17127:
    goto v_17117;
v_17118:
    goto v_17119;
v_17120:
    goto v_17121;
v_17122:
    goto v_17123;
v_17124:
    goto v_17125;
v_17126:
    v_17172 = CC_unify(elt(env, 0), 5, stack[0], v_17175, v_17174, v_17173, v_17172);
    env = stack[-16];
    stack[0] = v_17172;
    goto v_17111;
v_17113:
v_17111:
    v_17172 = qvalue(elt(env, 2)); // r
    v_17172 = qcar(v_17172);
    fn = elt(env, 24); // unbind
    v_17172 = (*qfn1(fn))(fn, v_17172);
    env = stack[-16];
    goto v_17071;
v_17094:
    goto v_17146;
v_17142:
    v_17172 = qvalue(elt(env, 2)); // r
    v_17173 = qcar(v_17172);
    goto v_17143;
v_17144:
    v_17172 = stack[-9];
    v_17172 = qcar(v_17172);
    goto v_17145;
v_17146:
    goto v_17142;
v_17143:
    goto v_17144;
v_17145:
    fn = elt(env, 25); // meq
    v_17172 = (*qfn2(fn))(fn, v_17173, v_17172);
    env = stack[-16];
    if (v_17172 == nil) goto v_17140;
    goto v_17162;
v_17152:
    stack[0] = qvalue(elt(env, 1)); // op
    goto v_17153;
v_17154:
    v_17172 = qvalue(elt(env, 2)); // r
    v_17172 = qcdr(v_17172);
    fn = elt(env, 23); // mval
    v_17175 = (*qfn1(fn))(fn, v_17172);
    env = stack[-16];
    goto v_17155;
v_17156:
    v_17172 = stack[-9];
    v_17174 = qcdr(v_17172);
    goto v_17157;
v_17158:
    v_17173 = stack[-14];
    goto v_17159;
v_17160:
    v_17172 = stack[-13];
    goto v_17161;
v_17162:
    goto v_17152;
v_17153:
    goto v_17154;
v_17155:
    goto v_17156;
v_17157:
    goto v_17158;
v_17159:
    goto v_17160;
v_17161:
    v_17172 = CC_unify(elt(env, 0), 5, stack[0], v_17175, v_17174, v_17173, v_17172);
    env = stack[-16];
    stack[0] = v_17172;
    goto v_17071;
v_17140:
v_17071:
    goto v_17052;
v_17051:
    v_17172 = stack[0];
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_16965;
    v_17172 = nil;
v_16965:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_17172);
}



// Code for evload

static LispObject CC_evload(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_16965;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16947);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_16947;
// end of prologue
v_16953:
    v_16965 = stack[0];
    if (v_16965 == nil) goto v_16956;
    else goto v_16957;
v_16956:
    goto v_16952;
v_16957:
    v_16965 = stack[0];
    v_16965 = qcar(v_16965);
    v_16965 = Lload_module(nil, v_16965);
    env = stack[-1];
    v_16965 = stack[0];
    v_16965 = qcdr(v_16965);
    stack[0] = v_16965;
    goto v_16953;
v_16952:
    v_16965 = nil;
    return onevalue(v_16965);
}



// Code for repartsq

static LispObject CC_repartsq(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_17020, v_17021, v_17022, v_17023;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16947);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_16947;
// end of prologue
    v_17020 = stack[0];
    v_17020 = qcar(v_17020);
    fn = elt(env, 1); // splitcomplex
    stack[-1] = (*qfn1(fn))(fn, v_17020);
    env = stack[-4];
    v_17020 = stack[0];
    v_17020 = qcdr(v_17020);
    fn = elt(env, 1); // splitcomplex
    v_17020 = (*qfn1(fn))(fn, v_17020);
    env = stack[-4];
    v_17022 = stack[-1];
    v_17021 = v_17020;
    v_17020 = v_17022;
    v_17020 = qcar(v_17020);
    v_17023 = qcdr(v_17022);
    v_17022 = v_17021;
    v_17022 = qcar(v_17022);
    v_17021 = qcdr(v_17021);
    stack[-3] = v_17023;
    stack[-2] = v_17022;
    stack[-1] = v_17021;
    goto v_16974;
v_16970:
    goto v_16980;
v_16976:
    goto v_16986;
v_16982:
    v_17021 = v_17020;
    goto v_16983;
v_16984:
    v_17020 = stack[-2];
    goto v_16985;
v_16986:
    goto v_16982;
v_16983:
    goto v_16984;
v_16985:
    fn = elt(env, 2); // multsq
    stack[0] = (*qfn2(fn))(fn, v_17021, v_17020);
    env = stack[-4];
    goto v_16977;
v_16978:
    goto v_16994;
v_16990:
    v_17021 = stack[-3];
    goto v_16991;
v_16992:
    v_17020 = stack[-1];
    goto v_16993;
v_16994:
    goto v_16990;
v_16991:
    goto v_16992;
v_16993:
    fn = elt(env, 2); // multsq
    v_17020 = (*qfn2(fn))(fn, v_17021, v_17020);
    env = stack[-4];
    goto v_16979;
v_16980:
    goto v_16976;
v_16977:
    goto v_16978;
v_16979:
    fn = elt(env, 3); // addsq
    stack[0] = (*qfn2(fn))(fn, stack[0], v_17020);
    env = stack[-4];
    goto v_16971;
v_16972:
    goto v_17003;
v_16999:
    goto v_17009;
v_17005:
    v_17021 = stack[-2];
    goto v_17006;
v_17007:
    v_17020 = stack[-2];
    goto v_17008;
v_17009:
    goto v_17005;
v_17006:
    goto v_17007;
v_17008:
    fn = elt(env, 2); // multsq
    stack[-2] = (*qfn2(fn))(fn, v_17021, v_17020);
    env = stack[-4];
    goto v_17000;
v_17001:
    goto v_17017;
v_17013:
    v_17021 = stack[-1];
    goto v_17014;
v_17015:
    v_17020 = stack[-1];
    goto v_17016;
v_17017:
    goto v_17013;
v_17014:
    goto v_17015;
v_17016:
    fn = elt(env, 2); // multsq
    v_17020 = (*qfn2(fn))(fn, v_17021, v_17020);
    env = stack[-4];
    goto v_17002;
v_17003:
    goto v_16999;
v_17000:
    goto v_17001;
v_17002:
    fn = elt(env, 3); // addsq
    v_17020 = (*qfn2(fn))(fn, stack[-2], v_17020);
    env = stack[-4];
    fn = elt(env, 4); // invsq
    v_17020 = (*qfn1(fn))(fn, v_17020);
    env = stack[-4];
    goto v_16973;
v_16974:
    goto v_16970;
v_16971:
    goto v_16972;
v_16973:
    {
        LispObject v_17028 = stack[0];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_17028, v_17020);
    }
}



// Code for formsetq

static LispObject CC_formsetq(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17032, v_17033, v_17034, v_17035, v_17036;
    LispObject fn;
    LispObject v_16949, v_16948, v_16947;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formsetq");
    va_start(aa, nargs);
    v_16947 = va_arg(aa, LispObject);
    v_16948 = va_arg(aa, LispObject);
    v_16949 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_17034 = v_16949;
    v_17035 = v_16948;
    v_17036 = v_16947;
// end of prologue
    goto v_16959;
v_16955:
    v_17033 = v_17034;
    goto v_16956;
v_16957:
    v_17032 = elt(env, 1); // symbolic
    goto v_16958;
v_16959:
    goto v_16955;
v_16956:
    goto v_16957;
v_16958:
    if (v_17033 == v_17032) goto v_16954;
    goto v_16969;
v_16963:
    v_17032 = v_17036;
    goto v_16964;
v_16965:
    v_17033 = v_17035;
    goto v_16966;
v_16967:
    goto v_16968;
v_16969:
    goto v_16963;
v_16964:
    goto v_16965;
v_16966:
    goto v_16967;
v_16968:
    {
        fn = elt(env, 4); // formsetq0
        return (*qfnn(fn))(fn, 3, v_17032, v_17033, v_17034);
    }
v_16954:
    goto v_16980;
v_16976:
    v_17032 = v_17036;
    v_17032 = qcdr(v_17032);
    v_17033 = qcar(v_17032);
    goto v_16977;
v_16978:
    v_17032 = elt(env, 2); // list
    goto v_16979;
v_16980:
    goto v_16976;
v_16977:
    goto v_16978;
v_16979:
    if (!consp(v_17033)) goto v_16974;
    v_17033 = qcar(v_17033);
    if (v_17033 == v_17032) goto v_16973;
    else goto v_16974;
v_16973:
    goto v_16992;
v_16986:
    v_17032 = v_17036;
    goto v_16987;
v_16988:
    v_17033 = v_17035;
    goto v_16989;
v_16990:
    goto v_16991;
v_16992:
    goto v_16986;
v_16987:
    goto v_16988;
v_16989:
    goto v_16990;
v_16991:
    {
        fn = elt(env, 5); // formsetq1
        return (*qfnn(fn))(fn, 3, v_17032, v_17033, v_17034);
    }
v_16974:
    goto v_17003;
v_16999:
    v_17032 = v_17036;
    v_17032 = qcdr(v_17032);
    v_17033 = qcar(v_17032);
    goto v_17000;
v_17001:
    v_17032 = elt(env, 3); // cons
    goto v_17002;
v_17003:
    goto v_16999;
v_17000:
    goto v_17001;
v_17002:
    if (!consp(v_17033)) goto v_16997;
    v_17033 = qcar(v_17033);
    if (v_17033 == v_17032) goto v_16996;
    else goto v_16997;
v_16996:
    goto v_17015;
v_17009:
    v_17032 = v_17036;
    goto v_17010;
v_17011:
    v_17033 = v_17035;
    goto v_17012;
v_17013:
    goto v_17014;
v_17015:
    goto v_17009;
v_17010:
    goto v_17011;
v_17012:
    goto v_17013;
v_17014:
    {
        fn = elt(env, 6); // formsetq2
        return (*qfnn(fn))(fn, 3, v_17032, v_17033, v_17034);
    }
v_16997:
    goto v_17028;
v_17022:
    v_17032 = v_17036;
    goto v_17023;
v_17024:
    v_17033 = v_17035;
    goto v_17025;
v_17026:
    goto v_17027;
v_17028:
    goto v_17022;
v_17023:
    goto v_17024;
v_17025:
    goto v_17026;
v_17027:
    {
        fn = elt(env, 4); // formsetq0
        return (*qfnn(fn))(fn, 3, v_17032, v_17033, v_17034);
    }
    v_17032 = nil;
    return onevalue(v_17032);
}



// Code for harmonicp

static LispObject CC_harmonicp(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_16957, v_16958;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16957 = v_16947;
// end of prologue
    goto v_16954;
v_16950:
    goto v_16951;
v_16952:
    v_16958 = elt(env, 1); // fourier!-angle
    goto v_16953;
v_16954:
    goto v_16950;
v_16951:
    goto v_16952;
v_16953:
    return get(v_16957, v_16958);
}



// Code for red_topred

static LispObject CC_red_topred(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_17032, v_17033;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16947,v_16948);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16948;
    stack[-1] = v_16947;
// end of prologue
    v_17032 = stack[0];
    fn = elt(env, 2); // bas_dpoly
    v_17032 = (*qfn1(fn))(fn, v_17032);
    env = stack[-3];
    if (v_17032 == nil) goto v_16956;
    else goto v_16957;
v_16956:
    v_17032 = lisp_true;
    goto v_16955;
v_16957:
    v_17032 = stack[-1];
    v_17032 = (v_17032 == nil ? lisp_true : nil);
    goto v_16955;
    v_17032 = nil;
v_16955:
    if (v_17032 == nil) goto v_16953;
    v_17032 = stack[0];
    goto v_16951;
v_16953:
    goto v_16977;
v_16973:
    v_17033 = stack[-1];
    goto v_16974;
v_16975:
    v_17032 = stack[0];
    goto v_16976;
v_16977:
    goto v_16973;
v_16974:
    goto v_16975;
v_16976:
    fn = elt(env, 3); // red_topredbe
    v_17032 = (*qfn2(fn))(fn, v_17033, v_17032);
    env = stack[-3];
    stack[0] = v_17032;
v_16982:
    v_17032 = stack[0];
    fn = elt(env, 2); // bas_dpoly
    v_17032 = (*qfn1(fn))(fn, v_17032);
    env = stack[-3];
    v_17033 = v_17032;
    if (v_17032 == nil) goto v_16985;
    goto v_16996;
v_16992:
    stack[-2] = stack[-1];
    goto v_16993;
v_16994:
    v_17032 = v_17033;
    fn = elt(env, 4); // dp_lmon
    v_17032 = (*qfn1(fn))(fn, v_17032);
    env = stack[-3];
    goto v_16995;
v_16996:
    goto v_16992;
v_16993:
    goto v_16994;
v_16995:
    fn = elt(env, 5); // red_divtest
    v_17032 = (*qfn2(fn))(fn, stack[-2], v_17032);
    env = stack[-3];
    stack[-2] = v_17032;
    if (v_17032 == nil) goto v_16985;
    goto v_16986;
v_16985:
    goto v_16981;
v_16986:
    goto v_17006;
v_17002:
    v_17033 = stack[0];
    goto v_17003;
v_17004:
    v_17032 = stack[-2];
    goto v_17005;
v_17006:
    goto v_17002;
v_17003:
    goto v_17004;
v_17005:
    fn = elt(env, 6); // red_subst
    v_17032 = (*qfn2(fn))(fn, v_17033, v_17032);
    env = stack[-3];
    stack[-2] = v_17032;
    v_17032 = qvalue(elt(env, 1)); // !*noetherian
    if (v_17032 == nil) goto v_17011;
    else goto v_17012;
v_17011:
    goto v_17019;
v_17015:
    v_17033 = stack[-1];
    goto v_17016;
v_17017:
    v_17032 = stack[0];
    goto v_17018;
v_17019:
    goto v_17015;
v_17016:
    goto v_17017;
v_17018:
    fn = elt(env, 7); // red_update
    v_17032 = (*qfn2(fn))(fn, v_17033, v_17032);
    env = stack[-3];
    stack[-1] = v_17032;
    goto v_17010;
v_17012:
v_17010:
    goto v_17027;
v_17023:
    v_17033 = stack[-1];
    goto v_17024;
v_17025:
    v_17032 = stack[-2];
    goto v_17026;
v_17027:
    goto v_17023;
v_17024:
    goto v_17025;
v_17026:
    fn = elt(env, 3); // red_topredbe
    v_17032 = (*qfn2(fn))(fn, v_17033, v_17032);
    env = stack[-3];
    stack[0] = v_17032;
    goto v_16982;
v_16981:
    v_17032 = stack[0];
    goto v_16951;
    v_17032 = nil;
v_16951:
    return onevalue(v_17032);
}



// Code for reverse!-num1

static LispObject CC_reverseKnum1(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_17126, v_17127;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16947,v_16948);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_16948;
    stack[0] = v_16947;
// end of prologue
    goto v_16958;
v_16954:
    v_17127 = stack[0];
    goto v_16955;
v_16956:
    v_17126 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16957;
v_16958:
    goto v_16954;
v_16955:
    goto v_16956;
v_16957:
    if (v_17127 == v_17126) goto v_16952;
    else goto v_16953;
v_16952:
    v_17126 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16951;
v_16953:
    goto v_16968;
v_16964:
    v_17127 = stack[-2];
    goto v_16965;
v_16966:
    v_17126 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16967;
v_16968:
    goto v_16964;
v_16965:
    goto v_16966;
v_16967:
    if (v_17127 == v_17126) goto v_16962;
    else goto v_16963;
v_16962:
    v_17126 = stack[0];
    goto v_16951;
v_16963:
    goto v_16978;
v_16974:
    v_17127 = stack[-2];
    goto v_16975;
v_16976:
    v_17126 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_16977;
v_16978:
    goto v_16974;
v_16975:
    goto v_16976;
v_16977:
    if (v_17127 == v_17126) goto v_16972;
    else goto v_16973;
v_16972:
    goto v_16985;
v_16981:
    stack[-1] = qvalue(elt(env, 1)); // reverse!-num!-table!*
    goto v_16982;
v_16983:
    goto v_16992;
v_16988:
    v_17127 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_16989;
v_16990:
    v_17126 = stack[0];
    goto v_16991;
v_16992:
    goto v_16988;
v_16989:
    goto v_16990;
v_16991:
    v_17126 = times2(v_17127, v_17126);
    goto v_16984;
v_16985:
    goto v_16981;
v_16982:
    goto v_16983;
v_16984:
    v_17126 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_17126-TAG_FIXNUM)/(16/CELL)));
    goto v_16951;
v_16973:
    goto v_17002;
v_16998:
    v_17127 = stack[-2];
    goto v_16999;
v_17000:
    v_17126 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_17001;
v_17002:
    goto v_16998;
v_16999:
    goto v_17000;
v_17001:
    if (v_17127 == v_17126) goto v_16996;
    else goto v_16997;
v_16996:
    goto v_17009;
v_17005:
    stack[-1] = qvalue(elt(env, 1)); // reverse!-num!-table!*
    goto v_17006;
v_17007:
    goto v_17016;
v_17012:
    v_17127 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_17013;
v_17014:
    v_17126 = stack[0];
    goto v_17015;
v_17016:
    goto v_17012;
v_17013:
    goto v_17014;
v_17015:
    v_17126 = times2(v_17127, v_17126);
    goto v_17008;
v_17009:
    goto v_17005;
v_17006:
    goto v_17007;
v_17008:
    v_17126 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_17126-TAG_FIXNUM)/(16/CELL)));
    goto v_16951;
v_16997:
    goto v_17026;
v_17022:
    v_17127 = stack[-2];
    goto v_17023;
v_17024:
    v_17126 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_17025;
v_17026:
    goto v_17022;
v_17023:
    goto v_17024;
v_17025:
    if (v_17127 == v_17126) goto v_17020;
    else goto v_17021;
v_17020:
    goto v_17033;
v_17029:
    v_17127 = qvalue(elt(env, 1)); // reverse!-num!-table!*
    goto v_17030;
v_17031:
    v_17126 = stack[0];
    goto v_17032;
v_17033:
    goto v_17029;
v_17030:
    goto v_17031;
v_17032:
    v_17126 = *(LispObject *)((char *)v_17127 + (CELL-TAG_VECTOR) + (((intptr_t)v_17126-TAG_FIXNUM)/(16/CELL)));
    goto v_16951;
v_17021:
    goto v_17048;
v_17044:
    stack[-1] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_17045;
v_17046:
    goto v_17055;
v_17051:
    v_17127 = stack[-2];
    goto v_17052;
v_17053:
    v_17126 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_17054;
v_17055:
    goto v_17051;
v_17052:
    goto v_17053;
v_17054:
    v_17126 = quot2(v_17127, v_17126);
    env = stack[-4];
    goto v_17047;
v_17048:
    goto v_17044;
v_17045:
    goto v_17046;
v_17047:
    v_17126 = Lexpt(nil, stack[-1], v_17126);
    env = stack[-4];
    stack[-3] = v_17126;
    goto v_17063;
v_17059:
    v_17127 = stack[0];
    goto v_17060;
v_17061:
    v_17126 = stack[-3];
    goto v_17062;
v_17063:
    goto v_17059;
v_17060:
    goto v_17061;
v_17062:
    v_17126 = Ldivide(nil, v_17127, v_17126);
    env = stack[-4];
    stack[-1] = v_17126;
    v_17126 = stack[-2];
    v_17126 = Levenp(nil, v_17126);
    env = stack[-4];
    if (v_17126 == nil) goto v_17068;
    else goto v_17069;
v_17068:
    goto v_17077;
v_17073:
    v_17127 = stack[-3];
    goto v_17074;
v_17075:
    v_17126 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_17076;
v_17077:
    goto v_17073;
v_17074:
    goto v_17075;
v_17076:
    v_17126 = times2(v_17127, v_17126);
    env = stack[-4];
    stack[-3] = v_17126;
    goto v_17067;
v_17069:
v_17067:
    goto v_17085;
v_17081:
    goto v_17091;
v_17087:
    goto v_17097;
v_17093:
    v_17126 = stack[-1];
    stack[0] = qcdr(v_17126);
    goto v_17094;
v_17095:
    goto v_17105;
v_17101:
    v_17127 = stack[-2];
    goto v_17102;
v_17103:
    v_17126 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_17104;
v_17105:
    goto v_17101;
v_17102:
    goto v_17103;
v_17104:
    v_17126 = quot2(v_17127, v_17126);
    env = stack[-4];
    goto v_17096;
v_17097:
    goto v_17093;
v_17094:
    goto v_17095;
v_17096:
    v_17127 = CC_reverseKnum1(elt(env, 0), stack[0], v_17126);
    env = stack[-4];
    goto v_17088;
v_17089:
    v_17126 = stack[-3];
    goto v_17090;
v_17091:
    goto v_17087;
v_17088:
    goto v_17089;
v_17090:
    stack[0] = times2(v_17127, v_17126);
    env = stack[-4];
    goto v_17082;
v_17083:
    goto v_17114;
v_17110:
    v_17126 = stack[-1];
    stack[-1] = qcar(v_17126);
    goto v_17111;
v_17112:
    goto v_17122;
v_17118:
    v_17126 = stack[-2];
    v_17127 = add1(v_17126);
    env = stack[-4];
    goto v_17119;
v_17120:
    v_17126 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_17121;
v_17122:
    goto v_17118;
v_17119:
    goto v_17120;
v_17121:
    v_17126 = quot2(v_17127, v_17126);
    env = stack[-4];
    goto v_17113;
v_17114:
    goto v_17110;
v_17111:
    goto v_17112;
v_17113:
    v_17126 = CC_reverseKnum1(elt(env, 0), stack[-1], v_17126);
    goto v_17084;
v_17085:
    goto v_17081;
v_17082:
    goto v_17083;
v_17084:
    {
        LispObject v_17132 = stack[0];
        return plus2(v_17132, v_17126);
    }
    goto v_16951;
    v_17126 = nil;
v_16951:
    return onevalue(v_17126);
}



// Code for mksf

static LispObject CC_mksf(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_16991, v_16992, v_16993;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16947);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_16947;
// end of prologue
    goto v_16957;
v_16953:
    v_16992 = stack[0];
    goto v_16954;
v_16955:
    v_16991 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16956;
v_16957:
    goto v_16953;
v_16954:
    goto v_16955;
v_16956:
    fn = elt(env, 2); // mksq
    v_16991 = (*qfn2(fn))(fn, v_16992, v_16991);
    env = stack[-1];
    v_16993 = v_16991;
    goto v_16968;
v_16964:
    v_16991 = v_16993;
    v_16992 = qcdr(v_16991);
    goto v_16965;
v_16966:
    v_16991 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16967;
v_16968:
    goto v_16964;
v_16965:
    goto v_16966;
v_16967:
    if (v_16992 == v_16991) goto v_16962;
    else goto v_16963;
v_16962:
    v_16991 = v_16993;
    v_16991 = qcar(v_16991);
    goto v_16951;
v_16963:
    v_16991 = lisp_true;
    qvalue(elt(env, 1)) = v_16991; // !*sub2
    goto v_16981;
v_16977:
    goto v_16987;
v_16983:
    v_16992 = stack[0];
    goto v_16984;
v_16985:
    v_16991 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16986;
v_16987:
    goto v_16983;
v_16984:
    goto v_16985;
v_16986:
    fn = elt(env, 3); // mksp
    v_16992 = (*qfn2(fn))(fn, v_16992, v_16991);
    env = stack[-1];
    goto v_16978;
v_16979:
    v_16991 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16980;
v_16981:
    goto v_16977;
v_16978:
    goto v_16979;
v_16980:
    v_16991 = cons(v_16992, v_16991);
    return ncons(v_16991);
v_16951:
    return onevalue(v_16991);
}



// Code for make!-x!-to!-p

static LispObject CC_makeKxKtoKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17172, v_17173, v_17174, v_17175, v_17176;
    LispObject fn;
    LispObject v_16949, v_16948, v_16947;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "make-x-to-p");
    va_start(aa, nargs);
    v_16947 = va_arg(aa, LispObject);
    v_16948 = va_arg(aa, LispObject);
    v_16949 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_16949,v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_16947,v_16948,v_16949);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_16949;
    stack[-1] = v_16948;
    stack[-2] = v_16947;
// end of prologue
    goto v_16963;
v_16959:
    v_17173 = stack[-2];
    goto v_16960;
v_16961:
    v_17172 = qvalue(elt(env, 1)); // dpoly
    goto v_16962;
v_16963:
    goto v_16959;
v_16960:
    goto v_16961;
v_16962:
    if (((intptr_t)(v_17173)) < ((intptr_t)(v_17172))) goto v_16957;
    else goto v_16958;
v_16957:
    v_17172 = (LispObject)0+TAG_FIXNUM; // 0
    v_17175 = v_17172;
v_16969:
    goto v_16979;
v_16975:
    v_17172 = stack[-2];
    v_17173 = (LispObject)((intptr_t)(v_17172) - 0x10);
    goto v_16976;
v_16977:
    v_17172 = v_17175;
    goto v_16978;
v_16979:
    goto v_16975;
v_16976:
    goto v_16977;
v_16978:
    v_17172 = (LispObject)(intptr_t)((intptr_t)v_17173 - (intptr_t)v_17172 + TAG_FIXNUM);
    v_17172 = ((intptr_t)(v_17172) < 0 ? lisp_true : nil);
    if (v_17172 == nil) goto v_16974;
    goto v_16968;
v_16974:
    goto v_16992;
v_16986:
    v_17174 = stack[0];
    goto v_16987;
v_16988:
    v_17173 = v_17175;
    goto v_16989;
v_16990:
    v_17172 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16991;
v_16992:
    goto v_16986;
v_16987:
    goto v_16988;
v_16989:
    goto v_16990;
v_16991:
    *(LispObject *)((char *)v_17174 + (CELL-TAG_VECTOR) + (((intptr_t)v_17173-TAG_FIXNUM)/(16/CELL))) = v_17172;
    v_17172 = v_17175;
    v_17172 = (LispObject)((intptr_t)(v_17172) + 0x10);
    v_17175 = v_17172;
    goto v_16969;
v_16968:
    goto v_17004;
v_16998:
    v_17174 = stack[0];
    goto v_16999;
v_17000:
    v_17173 = stack[-2];
    goto v_17001;
v_17002:
    v_17172 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17003;
v_17004:
    goto v_16998;
v_16999:
    goto v_17000;
v_17001:
    goto v_17002;
v_17003:
    *(LispObject *)((char *)v_17174 + (CELL-TAG_VECTOR) + (((intptr_t)v_17173-TAG_FIXNUM)/(16/CELL))) = v_17172;
    v_17172 = stack[-2];
    goto v_16954;
v_16958:
    goto v_17016;
v_17010:
    goto v_17022;
v_17018:
    v_17173 = stack[-2];
    goto v_17019;
v_17020:
    v_17172 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_17021;
v_17022:
    goto v_17018;
v_17019:
    goto v_17020;
v_17021:
    v_17174 = quot2(v_17173, v_17172);
    env = stack[-4];
    goto v_17011;
v_17012:
    v_17173 = stack[-1];
    goto v_17013;
v_17014:
    v_17172 = stack[0];
    goto v_17015;
v_17016:
    goto v_17010;
v_17011:
    goto v_17012;
v_17013:
    goto v_17014;
v_17015:
    v_17172 = CC_makeKxKtoKp(elt(env, 0), 3, v_17174, v_17173, v_17172);
    env = stack[-4];
    goto v_17038;
v_17028:
    v_17176 = stack[0];
    goto v_17029;
v_17030:
    v_17175 = v_17172;
    goto v_17031;
v_17032:
    v_17174 = stack[0];
    goto v_17033;
v_17034:
    v_17173 = v_17172;
    goto v_17035;
v_17036:
    v_17172 = stack[-1];
    goto v_17037;
v_17038:
    goto v_17028;
v_17029:
    goto v_17030;
v_17031:
    goto v_17032;
v_17033:
    goto v_17034;
v_17035:
    goto v_17036;
v_17037:
    fn = elt(env, 3); // times!-in!-vector
    v_17172 = (*qfnn(fn))(fn, 5, v_17176, v_17175, v_17174, v_17173, v_17172);
    env = stack[-4];
    stack[-3] = v_17172;
    goto v_17053;
v_17045:
    v_17175 = stack[-1];
    goto v_17046;
v_17047:
    v_17174 = stack[-3];
    goto v_17048;
v_17049:
    v_17173 = qvalue(elt(env, 2)); // poly!-vector
    goto v_17050;
v_17051:
    v_17172 = qvalue(elt(env, 1)); // dpoly
    goto v_17052;
v_17053:
    goto v_17045;
v_17046:
    goto v_17047;
v_17048:
    goto v_17049;
v_17050:
    goto v_17051;
v_17052:
    fn = elt(env, 4); // remainder!-in!-vector
    v_17172 = (*qfnn(fn))(fn, 4, v_17175, v_17174, v_17173, v_17172);
    env = stack[-4];
    stack[-3] = v_17172;
    goto v_17066;
v_17062:
    goto v_17072;
v_17068:
    v_17173 = stack[-2];
    goto v_17069;
v_17070:
    v_17172 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_17071;
v_17072:
    goto v_17068;
v_17069:
    goto v_17070;
v_17071:
    v_17173 = Liremainder(nil, v_17173, v_17172);
    env = stack[-4];
    goto v_17063;
v_17064:
    v_17172 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17065;
v_17066:
    goto v_17062;
v_17063:
    goto v_17064;
v_17065:
    if (v_17173 == v_17172) goto v_17061;
    v_17172 = stack[-3];
    v_17176 = v_17172;
v_17079:
    v_17172 = v_17176;
    v_17172 = ((intptr_t)(v_17172) < 0 ? lisp_true : nil);
    if (v_17172 == nil) goto v_17084;
    goto v_17078;
v_17084:
    goto v_17094;
v_17088:
    v_17175 = stack[-1];
    goto v_17089;
v_17090:
    v_17172 = v_17176;
    v_17174 = (LispObject)((intptr_t)(v_17172) + 0x10);
    goto v_17091;
v_17092:
    goto v_17102;
v_17098:
    v_17173 = stack[-1];
    goto v_17099;
v_17100:
    v_17172 = v_17176;
    goto v_17101;
v_17102:
    goto v_17098;
v_17099:
    goto v_17100;
v_17101:
    v_17172 = *(LispObject *)((char *)v_17173 + (CELL-TAG_VECTOR) + (((intptr_t)v_17172-TAG_FIXNUM)/(16/CELL)));
    goto v_17093;
v_17094:
    goto v_17088;
v_17089:
    goto v_17090;
v_17091:
    goto v_17092;
v_17093:
    *(LispObject *)((char *)v_17175 + (CELL-TAG_VECTOR) + (((intptr_t)v_17174-TAG_FIXNUM)/(16/CELL))) = v_17172;
    v_17172 = v_17176;
    v_17172 = (LispObject)((intptr_t)(v_17172) - 0x10);
    v_17176 = v_17172;
    goto v_17079;
v_17078:
    goto v_17114;
v_17108:
    v_17174 = stack[-1];
    goto v_17109;
v_17110:
    v_17173 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17111;
v_17112:
    v_17172 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17113;
v_17114:
    goto v_17108;
v_17109:
    goto v_17110;
v_17111:
    goto v_17112;
v_17113:
    *(LispObject *)((char *)v_17174 + (CELL-TAG_VECTOR) + (((intptr_t)v_17173-TAG_FIXNUM)/(16/CELL))) = v_17172;
    goto v_17127;
v_17119:
    v_17175 = stack[-1];
    goto v_17120;
v_17121:
    v_17172 = stack[-3];
    v_17174 = (LispObject)((intptr_t)(v_17172) + 0x10);
    goto v_17122;
v_17123:
    v_17173 = qvalue(elt(env, 2)); // poly!-vector
    goto v_17124;
v_17125:
    v_17172 = qvalue(elt(env, 1)); // dpoly
    goto v_17126;
v_17127:
    goto v_17119;
v_17120:
    goto v_17121;
v_17122:
    goto v_17123;
v_17124:
    goto v_17125;
v_17126:
    fn = elt(env, 4); // remainder!-in!-vector
    v_17172 = (*qfnn(fn))(fn, 4, v_17175, v_17174, v_17173, v_17172);
    stack[-3] = v_17172;
    goto v_17059;
v_17061:
v_17059:
    v_17172 = (LispObject)0+TAG_FIXNUM; // 0
    v_17176 = v_17172;
v_17136:
    goto v_17146;
v_17142:
    v_17173 = stack[-3];
    goto v_17143;
v_17144:
    v_17172 = v_17176;
    goto v_17145;
v_17146:
    goto v_17142;
v_17143:
    goto v_17144;
v_17145:
    v_17172 = (LispObject)(intptr_t)((intptr_t)v_17173 - (intptr_t)v_17172 + TAG_FIXNUM);
    v_17172 = ((intptr_t)(v_17172) < 0 ? lisp_true : nil);
    if (v_17172 == nil) goto v_17141;
    goto v_17135;
v_17141:
    goto v_17158;
v_17152:
    v_17175 = stack[0];
    goto v_17153;
v_17154:
    v_17174 = v_17176;
    goto v_17155;
v_17156:
    goto v_17165;
v_17161:
    v_17173 = stack[-1];
    goto v_17162;
v_17163:
    v_17172 = v_17176;
    goto v_17164;
v_17165:
    goto v_17161;
v_17162:
    goto v_17163;
v_17164:
    v_17172 = *(LispObject *)((char *)v_17173 + (CELL-TAG_VECTOR) + (((intptr_t)v_17172-TAG_FIXNUM)/(16/CELL)));
    goto v_17157;
v_17158:
    goto v_17152;
v_17153:
    goto v_17154;
v_17155:
    goto v_17156;
v_17157:
    *(LispObject *)((char *)v_17175 + (CELL-TAG_VECTOR) + (((intptr_t)v_17174-TAG_FIXNUM)/(16/CELL))) = v_17172;
    v_17172 = v_17176;
    v_17172 = (LispObject)((intptr_t)(v_17172) + 0x10);
    v_17176 = v_17172;
    goto v_17136;
v_17135:
    v_17172 = stack[-3];
v_16954:
    return onevalue(v_17172);
}



// Code for lalr_process_productions

static LispObject CC_lalr_process_productions(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_17137, v_17138, v_17139;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16947,v_16948);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_16948;
    v_17137 = v_16947;
// end of prologue
    stack[-6] = v_17137;
v_16961:
    v_17137 = stack[-6];
    if (v_17137 == nil) goto v_16965;
    else goto v_16966;
v_16965:
    goto v_16960;
v_16966:
    v_17137 = stack[-6];
    v_17137 = qcar(v_17137);
    v_17138 = v_17137;
    v_17137 = v_17138;
    v_17137 = qcar(v_17137);
    stack[-10] = v_17137;
    v_17137 = nil;
    stack[-8] = v_17137;
    v_17137 = v_17138;
    v_17137 = qcdr(v_17137);
    stack[-5] = v_17137;
v_16978:
    v_17137 = stack[-5];
    if (v_17137 == nil) goto v_16983;
    else goto v_16984;
v_16983:
    goto v_16977;
v_16984:
    v_17137 = stack[-5];
    v_17137 = qcar(v_17137);
    v_17138 = v_17137;
    v_17138 = qcar(v_17138);
    v_17137 = qcdr(v_17137);
    stack[-7] = v_17137;
    v_17137 = v_17138;
    stack[-4] = v_17137;
    v_17137 = stack[-4];
    if (v_17137 == nil) goto v_17003;
    else goto v_17004;
v_17003:
    v_17137 = nil;
    goto v_16998;
v_17004:
    v_17137 = stack[-4];
    v_17137 = qcar(v_17137);
    stack[0] = v_17137;
    goto v_17019;
v_17015:
    v_17137 = stack[0];
    v_17138 = Lintern(nil, v_17137);
    env = stack[-11];
    goto v_17016;
v_17017:
    v_17137 = qvalue(elt(env, 1)); // nonterminals
    goto v_17018;
v_17019:
    goto v_17015;
v_17016:
    goto v_17017;
v_17018:
    v_17137 = Lmember(nil, v_17138, v_17137);
    if (v_17137 == nil) goto v_17014;
    v_17137 = stack[0];
    v_17137 = Lintern(nil, v_17137);
    env = stack[-11];
    goto v_17012;
v_17014:
    goto v_17033;
v_17029:
    v_17137 = stack[0];
    v_17138 = Lintern(nil, v_17137);
    env = stack[-11];
    goto v_17030;
v_17031:
    v_17137 = stack[-9];
    goto v_17032;
v_17033:
    goto v_17029;
v_17030:
    goto v_17031;
v_17032:
    fn = elt(env, 3); // carrassoc
    v_17137 = (*qfn2(fn))(fn, v_17138, v_17137);
    env = stack[-11];
    goto v_17012;
    v_17137 = nil;
v_17012:
    v_17137 = ncons(v_17137);
    env = stack[-11];
    stack[-2] = v_17137;
    stack[-3] = v_17137;
v_16999:
    v_17137 = stack[-4];
    v_17137 = qcdr(v_17137);
    stack[-4] = v_17137;
    v_17137 = stack[-4];
    if (v_17137 == nil) goto v_17041;
    else goto v_17042;
v_17041:
    v_17137 = stack[-3];
    goto v_16998;
v_17042:
    goto v_17050;
v_17046:
    stack[-1] = stack[-2];
    goto v_17047;
v_17048:
    v_17137 = stack[-4];
    v_17137 = qcar(v_17137);
    stack[0] = v_17137;
    goto v_17064;
v_17060:
    v_17137 = stack[0];
    v_17138 = Lintern(nil, v_17137);
    env = stack[-11];
    goto v_17061;
v_17062:
    v_17137 = qvalue(elt(env, 1)); // nonterminals
    goto v_17063;
v_17064:
    goto v_17060;
v_17061:
    goto v_17062;
v_17063:
    v_17137 = Lmember(nil, v_17138, v_17137);
    if (v_17137 == nil) goto v_17059;
    v_17137 = stack[0];
    v_17137 = Lintern(nil, v_17137);
    env = stack[-11];
    goto v_17057;
v_17059:
    goto v_17078;
v_17074:
    v_17137 = stack[0];
    v_17138 = Lintern(nil, v_17137);
    env = stack[-11];
    goto v_17075;
v_17076:
    v_17137 = stack[-9];
    goto v_17077;
v_17078:
    goto v_17074;
v_17075:
    goto v_17076;
v_17077:
    fn = elt(env, 3); // carrassoc
    v_17137 = (*qfn2(fn))(fn, v_17138, v_17137);
    env = stack[-11];
    goto v_17057;
    v_17137 = nil;
v_17057:
    v_17137 = ncons(v_17137);
    env = stack[-11];
    goto v_17049;
v_17050:
    goto v_17046;
v_17047:
    goto v_17048;
v_17049:
    v_17137 = Lrplacd(nil, stack[-1], v_17137);
    env = stack[-11];
    v_17137 = stack[-2];
    v_17137 = qcdr(v_17137);
    stack[-2] = v_17137;
    goto v_16999;
v_16998:
    v_17138 = v_17137;
    goto v_17089;
v_17085:
    goto v_17086;
v_17087:
    v_17137 = stack[-7];
    goto v_17088;
v_17089:
    goto v_17085;
v_17086:
    goto v_17087;
v_17088:
    v_17137 = cons(v_17138, v_17137);
    env = stack[-11];
    goto v_17097;
v_17093:
    v_17138 = v_17137;
    goto v_17094;
v_17095:
    v_17137 = stack[-8];
    goto v_17096;
v_17097:
    goto v_17093;
v_17094:
    goto v_17095;
v_17096:
    v_17137 = cons(v_17138, v_17137);
    env = stack[-11];
    stack[-8] = v_17137;
    v_17137 = stack[-5];
    v_17137 = qcdr(v_17137);
    stack[-5] = v_17137;
    goto v_16978;
v_16977:
    goto v_17111;
v_17107:
    v_17137 = stack[-10];
    v_17138 = Lintern(nil, v_17137);
    env = stack[-11];
    goto v_17108;
v_17109:
    v_17137 = elt(env, 2); // lalr_produces
    goto v_17110;
v_17111:
    goto v_17107;
v_17108:
    goto v_17109;
v_17110:
    v_17137 = get(v_17138, v_17137);
    env = stack[-11];
    v_17138 = v_17137;
    if (v_17137 == nil) goto v_17105;
    goto v_17120;
v_17116:
    goto v_17117;
v_17118:
    v_17137 = stack[-8];
    goto v_17119;
v_17120:
    goto v_17116;
v_17117:
    goto v_17118;
v_17119:
    v_17137 = Lappend(nil, v_17138, v_17137);
    env = stack[-11];
    stack[-8] = v_17137;
    goto v_17103;
v_17105:
v_17103:
    goto v_17130;
v_17124:
    v_17137 = stack[-10];
    v_17139 = Lintern(nil, v_17137);
    env = stack[-11];
    goto v_17125;
v_17126:
    v_17138 = elt(env, 2); // lalr_produces
    goto v_17127;
v_17128:
    v_17137 = stack[-8];
    goto v_17129;
v_17130:
    goto v_17124;
v_17125:
    goto v_17126;
v_17127:
    goto v_17128;
v_17129:
    v_17137 = Lputprop(nil, 3, v_17139, v_17138, v_17137);
    env = stack[-11];
    v_17137 = stack[-6];
    v_17137 = qcdr(v_17137);
    stack[-6] = v_17137;
    goto v_16961;
v_16960:
    v_17137 = nil;
    return onevalue(v_17137);
}



// Code for sfto_updecf

static LispObject CC_sfto_updecf(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_16966, v_16967;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16947);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_16967 = v_16947;
// end of prologue
    v_16966 = qvalue(elt(env, 1)); // !*sfto_yun
    if (v_16966 == nil) goto v_16952;
    v_16966 = v_16967;
    {
        fn = elt(env, 4); // sfto_yun!-updecf
        return (*qfn1(fn))(fn, v_16966);
    }
v_16952:
    v_16966 = qvalue(elt(env, 2)); // !*sfto_musser
    if (v_16966 == nil) goto v_16957;
    v_16966 = v_16967;
    {
        fn = elt(env, 5); // sfto_musser!-updecf
        return (*qfn1(fn))(fn, v_16966);
    }
v_16957:
    v_16966 = elt(env, 3); // "sfto_updecf: select a decomposition method"
    v_16966 = ncons(v_16966);
    env = stack[0];
    {
        fn = elt(env, 6); // rederr
        return (*qfn1(fn))(fn, v_16966);
    }
    v_16966 = nil;
    return onevalue(v_16966);
}



// Code for width

static LispObject CC_width(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_17011, v_17012, v_17013;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16947,v_16948);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_16948;
    v_17012 = v_16947;
// end of prologue
    goto v_16958;
v_16954:
    v_17013 = v_17012;
    goto v_16955;
v_16956:
    v_17011 = elt(env, 1); // textag
    goto v_16957;
v_16958:
    goto v_16954;
v_16955:
    goto v_16956;
v_16957:
    v_17011 = get(v_17013, v_17011);
    env = stack[-2];
    stack[-1] = v_17011;
    v_17011 = stack[-1];
    if (v_17011 == nil) goto v_16963;
    else goto v_16964;
v_16963:
    goto v_16971;
v_16967:
    goto v_16977;
v_16973:
    v_17011 = elt(env, 2); // "cannot find item "
    goto v_16974;
v_16975:
    goto v_16976;
v_16977:
    goto v_16973;
v_16974:
    goto v_16975;
v_16976:
    v_17012 = list2(v_17011, v_17012);
    env = stack[-2];
    goto v_16968;
v_16969:
    v_17011 = elt(env, 3); // fatal
    goto v_16970;
v_16971:
    goto v_16967;
v_16968:
    goto v_16969;
v_16970:
    fn = elt(env, 4); // tri!-error
    v_17011 = (*qfn2(fn))(fn, v_17012, v_17011);
    env = stack[-2];
    goto v_16962;
v_16964:
v_16962:
v_16983:
    goto v_16994;
v_16990:
    v_17012 = stack[0];
    goto v_16991;
v_16992:
    v_17011 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16993;
v_16994:
    goto v_16990;
v_16991:
    goto v_16992;
v_16993:
    v_17011 = (LispObject)greaterp2(v_17012, v_17011);
    v_17011 = v_17011 ? lisp_true : nil;
    env = stack[-2];
    if (v_17011 == nil) goto v_16986;
    v_17011 = stack[-1];
    v_17011 = qcdr(v_17011);
    if (v_17011 == nil) goto v_16986;
    goto v_16987;
v_16986:
    goto v_16982;
v_16987:
    v_17011 = stack[-1];
    v_17011 = qcdr(v_17011);
    stack[-1] = v_17011;
    v_17011 = stack[0];
    v_17011 = sub1(v_17011);
    env = stack[-2];
    stack[0] = v_17011;
    goto v_16983;
v_16982:
    v_17011 = stack[-1];
    v_17011 = qcar(v_17011);
    if (v_17011 == nil) goto v_17007;
    else goto v_17006;
v_17007:
    v_17011 = (LispObject)0+TAG_FIXNUM; // 0
v_17006:
    return onevalue(v_17011);
}



// Code for get_char_group

static LispObject CC_get_char_group(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_16953;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16953 = v_16947;
// end of prologue
    v_16953 = qcar(v_16953);
    return onevalue(v_16953);
}



// Code for cl_susiupdknowl2

static LispObject CC_cl_susiupdknowl2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17102, v_17103, v_17104;
    LispObject fn;
    LispObject v_16949, v_16948, v_16947;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cl_susiupdknowl2");
    va_start(aa, nargs);
    v_16947 = va_arg(aa, LispObject);
    v_16948 = va_arg(aa, LispObject);
    v_16949 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_16949,v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_16947,v_16948,v_16949);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_16949;
    stack[-5] = v_16948;
    stack[-6] = v_16947;
// end of prologue
    stack[-3] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    v_17102 = stack[-5];
    stack[-2] = v_17102;
v_16963:
    v_17102 = stack[-2];
    if (v_17102 == nil) goto v_16966;
    else goto v_16967;
v_16966:
    goto v_16962;
v_16967:
    v_17102 = stack[-2];
    v_17102 = qcar(v_17102);
    stack[-7] = v_17102;
    v_17102 = stack[-2];
    v_17102 = qcdr(v_17102);
    stack[-2] = v_17102;
    goto v_16979;
v_16975:
    v_17103 = stack[-7];
    goto v_16976;
v_16977:
    v_17102 = stack[-6];
    goto v_16978;
v_16979:
    goto v_16975;
v_16976:
    goto v_16977;
v_16978:
    fn = elt(env, 2); // rl_susibin
    v_17102 = (*qfn2(fn))(fn, v_17103, v_17102);
    env = stack[-8];
    stack[-3] = v_17102;
    goto v_16990;
v_16986:
    v_17103 = stack[-3];
    goto v_16987;
v_16988:
    v_17102 = elt(env, 1); // false
    goto v_16989;
v_16990:
    goto v_16986;
v_16987:
    goto v_16988;
v_16989:
    if (v_17103 == v_17102) goto v_16984;
    else goto v_16985;
v_16984:
    v_17102 = nil;
    stack[-2] = v_17102;
    goto v_16983;
v_16985:
    goto v_17003;
v_16997:
    v_17104 = stack[-3];
    goto v_16998;
v_16999:
    v_17103 = stack[-5];
    goto v_17000;
v_17001:
    v_17102 = stack[-7];
    goto v_17002;
v_17003:
    goto v_16997;
v_16998:
    goto v_16999;
v_17000:
    goto v_17001;
v_17002:
    fn = elt(env, 3); // cl_susiinter
    v_17102 = (*qfnn(fn))(fn, 3, v_17104, v_17103, v_17102);
    env = stack[-8];
    stack[-3] = v_17102;
    goto v_17012;
v_17008:
    v_17103 = stack[0];
    goto v_17009;
v_17010:
    v_17102 = stack[-3];
    v_17102 = qcdr(v_17102);
    v_17102 = qcar(v_17102);
    goto v_17011;
v_17012:
    goto v_17008;
v_17009:
    goto v_17010;
v_17011:
    v_17102 = Lnconc(nil, v_17103, v_17102);
    env = stack[-8];
    stack[0] = v_17102;
    v_17102 = stack[-3];
    v_17102 = qcar(v_17102);
    stack[-5] = v_17102;
    v_17102 = stack[-3];
    v_17102 = qcdr(v_17102);
    v_17102 = qcdr(v_17102);
    v_17102 = qcar(v_17102);
    if (v_17102 == nil) goto v_17022;
    goto v_17020;
v_17022:
v_17020:
    v_17102 = stack[-3];
    v_17102 = qcdr(v_17102);
    v_17102 = qcdr(v_17102);
    v_17102 = qcdr(v_17102);
    v_17102 = qcar(v_17102);
    if (v_17102 == nil) goto v_17031;
    v_17102 = lisp_true;
    stack[-1] = v_17102;
    v_17102 = nil;
    stack[-2] = v_17102;
    goto v_17029;
v_17031:
v_17029:
    goto v_16983;
v_16983:
    goto v_16963;
v_16962:
    goto v_17047;
v_17043:
    v_17103 = stack[-3];
    goto v_17044;
v_17045:
    v_17102 = elt(env, 1); // false
    goto v_17046;
v_17047:
    goto v_17043;
v_17044:
    goto v_17045;
v_17046:
    if (v_17103 == v_17102) goto v_17041;
    else goto v_17042;
v_17041:
    v_17102 = elt(env, 1); // false
    goto v_16959;
v_17042:
    v_17102 = stack[-1];
    if (v_17102 == nil) goto v_17053;
    else goto v_17054;
v_17053:
    goto v_17061;
v_17057:
    v_17103 = stack[-6];
    goto v_17058;
v_17059:
    v_17102 = stack[-5];
    goto v_17060;
v_17061:
    goto v_17057;
v_17058:
    goto v_17059;
v_17060:
    v_17102 = cons(v_17103, v_17102);
    env = stack[-8];
    stack[-5] = v_17102;
    goto v_17052;
v_17054:
v_17052:
v_17066:
    v_17102 = stack[0];
    if (v_17102 == nil) goto v_17069;
    else goto v_17070;
v_17069:
    goto v_17065;
v_17070:
    goto v_17080;
v_17074:
    v_17102 = stack[0];
    v_17104 = qcar(v_17102);
    goto v_17075;
v_17076:
    v_17103 = stack[-5];
    goto v_17077;
v_17078:
    v_17102 = stack[-4];
    goto v_17079;
v_17080:
    goto v_17074;
v_17075:
    goto v_17076;
v_17077:
    goto v_17078;
v_17079:
    v_17102 = CC_cl_susiupdknowl2(elt(env, 0), 3, v_17104, v_17103, v_17102);
    env = stack[-8];
    stack[-5] = v_17102;
    goto v_17093;
v_17089:
    v_17103 = stack[-5];
    goto v_17090;
v_17091:
    v_17102 = elt(env, 1); // false
    goto v_17092;
v_17093:
    goto v_17089;
v_17090:
    goto v_17091;
v_17092:
    if (v_17103 == v_17102) goto v_17087;
    else goto v_17088;
v_17087:
    v_17102 = nil;
    stack[0] = v_17102;
    goto v_17086;
v_17088:
    v_17102 = stack[0];
    v_17102 = qcdr(v_17102);
    stack[0] = v_17102;
    goto v_17086;
v_17086:
    goto v_17066;
v_17065:
    v_17102 = stack[-5];
v_16959:
    return onevalue(v_17102);
}



// Code for semanticml

static LispObject CC_semanticml(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_17031, v_17032;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16947);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_16947;
// end of prologue
    goto v_16960;
v_16956:
    v_17031 = stack[0];
    v_17032 = Llength(nil, v_17031);
    env = stack[-1];
    goto v_16957;
v_16958:
    v_17031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16959;
v_16960:
    goto v_16956;
v_16957:
    goto v_16958;
v_16959:
    v_17031 = (LispObject)greaterp2(v_17032, v_17031);
    v_17031 = v_17031 ? lisp_true : nil;
    env = stack[-1];
    if (v_17031 == nil) goto v_16954;
    v_17031 = elt(env, 1); // "<apply>"
    fn = elt(env, 13); // printout
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    v_17031 = lisp_true;
    fn = elt(env, 14); // indent!*
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    v_17031 = elt(env, 2); // "<fn>"
    fn = elt(env, 13); // printout
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    v_17031 = lisp_true;
    fn = elt(env, 14); // indent!*
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    goto v_16952;
v_16954:
v_16952:
    v_17031 = elt(env, 3); // "<semantic>"
    fn = elt(env, 13); // printout
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    v_17031 = lisp_true;
    fn = elt(env, 14); // indent!*
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    v_17031 = elt(env, 4); // "<ci><mo>"
    fn = elt(env, 13); // printout
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    v_17031 = stack[0];
    v_17031 = qcar(v_17031);
    v_17031 = qcar(v_17031);
    v_17031 = Lprinc(nil, v_17031);
    env = stack[-1];
    v_17031 = elt(env, 5); // "</mo></ci>"
    v_17031 = Lprinc(nil, v_17031);
    env = stack[-1];
    v_17031 = elt(env, 6); // "<annotation-xml encoding=""OpenMath"">"
    fn = elt(env, 13); // printout
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    v_17031 = lisp_true;
    fn = elt(env, 14); // indent!*
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    v_17031 = elt(env, 7); // "<"
    fn = elt(env, 13); // printout
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    v_17031 = stack[0];
    v_17031 = qcar(v_17031);
    v_17031 = qcdr(v_17031);
    v_17031 = qcar(v_17031);
    fn = elt(env, 15); // mathml_list2string
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    v_17031 = elt(env, 8); // ">"
    v_17031 = Lprinc(nil, v_17031);
    env = stack[-1];
    v_17031 = nil;
    fn = elt(env, 14); // indent!*
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    v_17031 = elt(env, 9); // "</annotation-xml>"
    fn = elt(env, 13); // printout
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    v_17031 = nil;
    fn = elt(env, 14); // indent!*
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    v_17031 = elt(env, 10); // "</semantic>"
    fn = elt(env, 13); // printout
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    goto v_17015;
v_17011:
    v_17031 = stack[0];
    v_17032 = Llength(nil, v_17031);
    env = stack[-1];
    goto v_17012;
v_17013:
    v_17031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17014;
v_17015:
    goto v_17011;
v_17012:
    goto v_17013;
v_17014:
    v_17031 = (LispObject)greaterp2(v_17032, v_17031);
    v_17031 = v_17031 ? lisp_true : nil;
    env = stack[-1];
    if (v_17031 == nil) goto v_17009;
    v_17031 = nil;
    fn = elt(env, 14); // indent!*
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    v_17031 = elt(env, 11); // "</fn>"
    fn = elt(env, 13); // printout
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    v_17031 = stack[0];
    v_17031 = qcdr(v_17031);
    fn = elt(env, 16); // multi_elem
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    v_17031 = nil;
    fn = elt(env, 14); // indent!*
    v_17031 = (*qfn1(fn))(fn, v_17031);
    env = stack[-1];
    v_17031 = elt(env, 12); // "</apply>"
    fn = elt(env, 13); // printout
    v_17031 = (*qfn1(fn))(fn, v_17031);
    goto v_17007;
v_17009:
v_17007:
    v_17031 = nil;
    return onevalue(v_17031);
}



// Code for derad

static LispObject CC_derad(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_17087, v_17088, v_17089;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16947,v_16948);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16948;
    stack[-1] = v_16947;
// end of prologue
    stack[-2] = nil;
v_16953:
    v_17087 = stack[0];
    if (v_17087 == nil) goto v_16956;
    else goto v_16957;
v_16956:
    goto v_16964;
v_16960:
    stack[0] = stack[-2];
    goto v_16961;
v_16962:
    v_17087 = stack[-1];
    v_17087 = ncons(v_17087);
    env = stack[-3];
    goto v_16963;
v_16964:
    goto v_16960;
v_16961:
    goto v_16962;
v_16963:
    {
        LispObject v_17093 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_17093, v_17087);
    }
v_16957:
    v_17087 = stack[0];
    v_17087 = qcar(v_17087);
    if (is_number(v_17087)) goto v_16968;
    else goto v_16969;
v_16968:
    goto v_16977;
v_16973:
    v_17087 = stack[0];
    v_17088 = qcar(v_17087);
    goto v_16974;
v_16975:
    v_17087 = stack[-2];
    goto v_16976;
v_16977:
    goto v_16973;
v_16974:
    goto v_16975;
v_16976:
    v_17087 = cons(v_17088, v_17087);
    env = stack[-3];
    stack[-2] = v_17087;
    v_17087 = stack[0];
    v_17087 = qcdr(v_17087);
    stack[0] = v_17087;
    goto v_16953;
v_16969:
    goto v_16989;
v_16985:
    v_17088 = stack[-1];
    goto v_16986;
v_16987:
    v_17087 = stack[0];
    v_17087 = qcar(v_17087);
    goto v_16988;
v_16989:
    goto v_16985;
v_16986:
    goto v_16987;
v_16988:
    if (equal(v_17088, v_17087)) goto v_16983;
    else goto v_16984;
v_16983:
    v_17087 = stack[0];
    v_17087 = qcdr(v_17087);
    if (v_17087 == nil) goto v_16996;
    v_17087 = stack[0];
    v_17087 = qcdr(v_17087);
    v_17087 = qcar(v_17087);
    if (is_number(v_17087)) goto v_17000;
    else goto v_16996;
v_17000:
    goto v_17009;
v_17005:
    goto v_17006;
v_17007:
    goto v_17018;
v_17012:
    goto v_17013;
v_17014:
    v_17087 = stack[0];
    v_17087 = qcdr(v_17087);
    v_17087 = qcar(v_17087);
    v_17088 = add1(v_17087);
    env = stack[-3];
    goto v_17015;
v_17016:
    v_17087 = stack[0];
    v_17087 = qcdr(v_17087);
    v_17087 = qcdr(v_17087);
    goto v_17017;
v_17018:
    goto v_17012;
v_17013:
    goto v_17014;
v_17015:
    goto v_17016;
v_17017:
    v_17087 = list2star(stack[-1], v_17088, v_17087);
    env = stack[-3];
    goto v_17008;
v_17009:
    goto v_17005;
v_17006:
    goto v_17007;
v_17008:
    {
        LispObject v_17094 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_17094, v_17087);
    }
v_16996:
    goto v_17034;
v_17030:
    goto v_17031;
v_17032:
    goto v_17043;
v_17037:
    v_17089 = stack[-1];
    goto v_17038;
v_17039:
    v_17088 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_17040;
v_17041:
    v_17087 = stack[0];
    v_17087 = qcdr(v_17087);
    goto v_17042;
v_17043:
    goto v_17037;
v_17038:
    goto v_17039;
v_17040:
    goto v_17041;
v_17042:
    v_17087 = list2star(v_17089, v_17088, v_17087);
    env = stack[-3];
    goto v_17033;
v_17034:
    goto v_17030;
v_17031:
    goto v_17032;
v_17033:
    {
        LispObject v_17095 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_17095, v_17087);
    }
    goto v_16955;
v_16984:
    goto v_17055;
v_17051:
    v_17088 = stack[-1];
    goto v_17052;
v_17053:
    v_17087 = stack[0];
    v_17087 = qcar(v_17087);
    goto v_17054;
v_17055:
    goto v_17051;
v_17052:
    goto v_17053;
v_17054:
    fn = elt(env, 2); // ordp
    v_17087 = (*qfn2(fn))(fn, v_17088, v_17087);
    env = stack[-3];
    if (v_17087 == nil) goto v_17049;
    goto v_17064;
v_17060:
    goto v_17061;
v_17062:
    goto v_17071;
v_17067:
    v_17088 = stack[-1];
    goto v_17068;
v_17069:
    v_17087 = stack[0];
    goto v_17070;
v_17071:
    goto v_17067;
v_17068:
    goto v_17069;
v_17070:
    v_17087 = cons(v_17088, v_17087);
    env = stack[-3];
    goto v_17063;
v_17064:
    goto v_17060;
v_17061:
    goto v_17062;
v_17063:
    {
        LispObject v_17096 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_17096, v_17087);
    }
v_17049:
    goto v_17081;
v_17077:
    v_17087 = stack[0];
    v_17088 = qcar(v_17087);
    goto v_17078;
v_17079:
    v_17087 = stack[-2];
    goto v_17080;
v_17081:
    goto v_17077;
v_17078:
    goto v_17079;
v_17080:
    v_17087 = cons(v_17088, v_17087);
    env = stack[-3];
    stack[-2] = v_17087;
    v_17087 = stack[0];
    v_17087 = qcdr(v_17087);
    stack[0] = v_17087;
    goto v_16953;
v_16955:
    v_17087 = nil;
    return onevalue(v_17087);
}



// Code for evalvars

static LispObject CC_evalvars(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_17043, v_17044;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16947);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_16947;
// end of prologue
    stack[-2] = nil;
v_16952:
    v_17043 = stack[-1];
    if (v_17043 == nil) goto v_16955;
    else goto v_16956;
v_16955:
    v_17043 = stack[-2];
    {
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(fn, v_17043);
    }
v_16956:
    v_17043 = stack[-1];
    v_17043 = qcar(v_17043);
    if (!consp(v_17043)) goto v_16964;
    else goto v_16965;
v_16964:
    v_17043 = lisp_true;
    goto v_16963;
v_16965:
    goto v_16976;
v_16972:
    v_17043 = stack[-1];
    v_17043 = qcar(v_17043);
    v_17044 = qcar(v_17043);
    goto v_16973;
v_16974:
    v_17043 = elt(env, 1); // intfn
    goto v_16975;
v_16976:
    goto v_16972;
v_16973:
    goto v_16974;
v_16975:
    v_17043 = Lflagp(nil, v_17044, v_17043);
    env = stack[-3];
    goto v_16963;
    v_17043 = nil;
v_16963:
    if (v_17043 == nil) goto v_16961;
    goto v_16986;
v_16982:
    v_17043 = stack[-1];
    v_17044 = qcar(v_17043);
    goto v_16983;
v_16984:
    v_17043 = stack[-2];
    goto v_16985;
v_16986:
    goto v_16982;
v_16983:
    goto v_16984;
v_16985:
    v_17043 = cons(v_17044, v_17043);
    env = stack[-3];
    stack[-2] = v_17043;
    v_17043 = stack[-1];
    v_17043 = qcdr(v_17043);
    stack[-1] = v_17043;
    goto v_16952;
v_16961:
    goto v_16999;
v_16995:
    v_17043 = stack[-1];
    v_17043 = qcar(v_17043);
    v_17043 = qcar(v_17043);
    if (!symbolp(v_17043)) v_17044 = nil;
    else { v_17044 = qfastgets(v_17043);
           if (v_17044 != nil) { v_17044 = elt(v_17044, 2); // rtype
#ifdef RECORD_GET
             if (v_17044 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_17044 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_17044 == SPID_NOPROP) v_17044 = nil; }}
#endif
    goto v_16996;
v_16997:
    v_17043 = elt(env, 2); // setelemfn
    goto v_16998;
v_16999:
    goto v_16995;
v_16996:
    goto v_16997;
v_16998:
    v_17043 = get(v_17044, v_17043);
    env = stack[-3];
    if (v_17043 == nil) goto v_16993;
    goto v_17012;
v_17006:
    v_17043 = stack[-1];
    v_17043 = qcar(v_17043);
    stack[0] = qcar(v_17043);
    goto v_17007;
v_17008:
    v_17043 = stack[-1];
    v_17043 = qcar(v_17043);
    v_17043 = qcdr(v_17043);
    fn = elt(env, 4); // revlis_without_mode
    v_17044 = (*qfn1(fn))(fn, v_17043);
    env = stack[-3];
    goto v_17009;
v_17010:
    v_17043 = stack[-2];
    goto v_17011;
v_17012:
    goto v_17006;
v_17007:
    goto v_17008;
v_17009:
    goto v_17010;
v_17011:
    v_17043 = acons(stack[0], v_17044, v_17043);
    env = stack[-3];
    stack[-2] = v_17043;
    v_17043 = stack[-1];
    v_17043 = qcdr(v_17043);
    stack[-1] = v_17043;
    goto v_16952;
v_16993:
    goto v_17032;
v_17026:
    v_17043 = stack[-1];
    v_17043 = qcar(v_17043);
    stack[0] = qcar(v_17043);
    goto v_17027;
v_17028:
    v_17043 = stack[-1];
    v_17043 = qcar(v_17043);
    v_17043 = qcdr(v_17043);
    fn = elt(env, 5); // revlis
    v_17044 = (*qfn1(fn))(fn, v_17043);
    env = stack[-3];
    goto v_17029;
v_17030:
    v_17043 = stack[-2];
    goto v_17031;
v_17032:
    goto v_17026;
v_17027:
    goto v_17028;
v_17029:
    goto v_17030;
v_17031:
    v_17043 = acons(stack[0], v_17044, v_17043);
    env = stack[-3];
    stack[-2] = v_17043;
    v_17043 = stack[-1];
    v_17043 = qcdr(v_17043);
    stack[-1] = v_17043;
    goto v_16952;
    v_17043 = nil;
    return onevalue(v_17043);
}



// Code for vdp2a

static LispObject CC_vdp2a(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_16955;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16955 = v_16947;
// end of prologue
    v_16955 = qcdr(v_16955);
    v_16955 = qcdr(v_16955);
    v_16955 = qcdr(v_16955);
    v_16955 = qcar(v_16955);
    {
        fn = elt(env, 1); // dip2a
        return (*qfn1(fn))(fn, v_16955);
    }
}



// Code for gfplusn

static LispObject CC_gfplusn(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_16992, v_16993;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16947,v_16948);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16948;
    stack[-1] = v_16947;
// end of prologue
    v_16992 = stack[-1];
    v_16992 = qcar(v_16992);
    if (!consp(v_16992)) goto v_16952;
    else goto v_16953;
v_16952:
    goto v_16961;
v_16957:
    v_16993 = stack[-1];
    goto v_16958;
v_16959:
    v_16992 = stack[0];
    goto v_16960;
v_16961:
    goto v_16957;
v_16958:
    goto v_16959;
v_16960:
    {
        fn = elt(env, 1); // gffplus
        return (*qfn2(fn))(fn, v_16993, v_16992);
    }
v_16953:
    goto v_16971;
v_16967:
    goto v_16977;
v_16973:
    v_16992 = stack[-1];
    v_16993 = qcar(v_16992);
    goto v_16974;
v_16975:
    v_16992 = stack[0];
    v_16992 = qcar(v_16992);
    goto v_16976;
v_16977:
    goto v_16973;
v_16974:
    goto v_16975;
v_16976:
    fn = elt(env, 2); // plus!:
    stack[-2] = (*qfn2(fn))(fn, v_16993, v_16992);
    env = stack[-3];
    goto v_16968;
v_16969:
    goto v_16987;
v_16983:
    v_16992 = stack[-1];
    v_16993 = qcdr(v_16992);
    goto v_16984;
v_16985:
    v_16992 = stack[0];
    v_16992 = qcdr(v_16992);
    goto v_16986;
v_16987:
    goto v_16983;
v_16984:
    goto v_16985;
v_16986:
    fn = elt(env, 2); // plus!:
    v_16992 = (*qfn2(fn))(fn, v_16993, v_16992);
    goto v_16970;
v_16971:
    goto v_16967;
v_16968:
    goto v_16969;
v_16970:
    {
        LispObject v_16997 = stack[-2];
        return cons(v_16997, v_16992);
    }
    v_16992 = nil;
    return onevalue(v_16992);
}



// Code for clogsq!*

static LispObject CC_clogsqH(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_16965, v_16966;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16947);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_16965 = v_16947;
// end of prologue
// Binding !*div
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = nil; // !*div
// Binding !*combinelogs
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=2
{   bind_fluid_stack bind_fluid_var(-4, 2, -2);
    qvalue(elt(env, 2)) = nil; // !*combinelogs
// Binding !*expandlogs
// FLUIDBIND: reloadenv=4 litvec-offset=3 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 3, -1);
    qvalue(elt(env, 3)) = nil; // !*expandlogs
    v_16966 = lisp_true;
    qvalue(elt(env, 3)) = v_16966; // !*expandlogs
    qvalue(elt(env, 1)) = v_16966; // !*div
    v_16966 = lisp_true;
// Binding !*uncached
// FLUIDBIND: reloadenv=4 litvec-offset=4 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 4, 0);
    qvalue(elt(env, 4)) = v_16966; // !*uncached
    fn = elt(env, 5); // prepsq
    v_16965 = (*qfn1(fn))(fn, v_16965);
    env = stack[-4];
    fn = elt(env, 6); // simp
    v_16965 = (*qfn1(fn))(fn, v_16965);
    env = stack[-4];
    ;}  // end of a binding scope
    v_16966 = nil;
    qvalue(elt(env, 3)) = v_16966; // !*expandlogs
    fn = elt(env, 7); // prepsq!*
    v_16965 = (*qfn1(fn))(fn, v_16965);
    env = stack[-4];
    fn = elt(env, 8); // comblog
    v_16965 = (*qfn1(fn))(fn, v_16965);
    env = stack[-4];
    fn = elt(env, 9); // simp!*
    v_16965 = (*qfn1(fn))(fn, v_16965);
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_16965);
}



// Code for assert_stat!-parse

static LispObject CC_assert_statKparse(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17037, v_17038, v_17039;
    LispObject fn;
    argcheck(nargs, 0, "assert_stat-parse");
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
    fn = elt(env, 8); // scan
    v_17037 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-2] = v_17037;
    goto v_16962;
v_16958:
    fn = elt(env, 8); // scan
    v_17038 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_16959;
v_16960:
    v_17037 = elt(env, 1); // !*colon!*
    goto v_16961;
v_16962:
    goto v_16958;
v_16959:
    goto v_16960;
v_16961:
    if (v_17038 == v_17037) goto v_16957;
    goto v_16971;
v_16967:
    v_17038 = elt(env, 2); // "expecting ':' in assert but found"
    goto v_16968;
v_16969:
    v_17037 = qvalue(elt(env, 3)); // cursym!*
    goto v_16970;
v_16971:
    goto v_16967;
v_16968:
    goto v_16969;
v_16970:
    v_17037 = list2(v_17038, v_17037);
    env = stack[-3];
    fn = elt(env, 9); // rederr
    v_17037 = (*qfn1(fn))(fn, v_17037);
    env = stack[-3];
    goto v_16955;
v_16957:
v_16955:
    fn = elt(env, 10); // assert_stat1
    v_17037 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-1] = v_17037;
    goto v_16987;
v_16983:
    fn = elt(env, 8); // scan
    v_17038 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_16984;
v_16985:
    v_17037 = elt(env, 4); // difference
    goto v_16986;
v_16987:
    goto v_16983;
v_16984:
    goto v_16985;
v_16986:
    if (v_17038 == v_17037) goto v_16982;
    v_17037 = lisp_true;
    goto v_16980;
v_16982:
    goto v_16998;
v_16994:
    fn = elt(env, 8); // scan
    v_17038 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_16995;
v_16996:
    v_17037 = elt(env, 5); // greaterp
    goto v_16997;
v_16998:
    goto v_16994;
v_16995:
    goto v_16996;
v_16997:
    v_17037 = Lneq(nil, v_17038, v_17037);
    env = stack[-3];
    goto v_16980;
    v_17037 = nil;
v_16980:
    if (v_17037 == nil) goto v_16978;
    goto v_17007;
v_17003:
    v_17038 = elt(env, 6); // "expecting '->' in assert but found"
    goto v_17004;
v_17005:
    v_17037 = qvalue(elt(env, 3)); // cursym!*
    goto v_17006;
v_17007:
    goto v_17003;
v_17004:
    goto v_17005;
v_17006:
    v_17037 = list2(v_17038, v_17037);
    env = stack[-3];
    fn = elt(env, 9); // rederr
    v_17037 = (*qfn1(fn))(fn, v_17037);
    env = stack[-3];
    goto v_16976;
v_16978:
v_16976:
    fn = elt(env, 8); // scan
    v_17037 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[0] = v_17037;
    fn = elt(env, 8); // scan
    v_17037 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    if (!symbolp(v_17037)) v_17037 = nil;
    else { v_17037 = qfastgets(v_17037);
           if (v_17037 != nil) { v_17037 = elt(v_17037, 55); // delim
#ifdef RECORD_GET
             if (v_17037 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v_17037 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v_17037 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v_17037 == SPID_NOPROP) v_17037 = nil; else v_17037 = lisp_true; }}
#endif
    if (v_17037 == nil) goto v_17013;
    else goto v_17014;
v_17013:
    goto v_17023;
v_17019:
    v_17038 = elt(env, 7); // "expecting end of assert but found"
    goto v_17020;
v_17021:
    v_17037 = qvalue(elt(env, 3)); // cursym!*
    goto v_17022;
v_17023:
    goto v_17019;
v_17020:
    goto v_17021;
v_17022:
    v_17037 = list2(v_17038, v_17037);
    env = stack[-3];
    fn = elt(env, 9); // rederr
    v_17037 = (*qfn1(fn))(fn, v_17037);
    goto v_17012;
v_17014:
v_17012:
    goto v_17033;
v_17027:
    v_17039 = stack[-2];
    goto v_17028;
v_17029:
    v_17038 = stack[-1];
    goto v_17030;
v_17031:
    v_17037 = stack[0];
    goto v_17032;
v_17033:
    goto v_17027;
v_17028:
    goto v_17029;
v_17030:
    goto v_17031;
v_17032:
    return list3(v_17039, v_17038, v_17037);
    return onevalue(v_17037);
}



// Code for mv!-pow!-!>

static LispObject CC_mvKpowKS(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_16986, v_16987, v_16988, v_16989;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16987 = v_16948;
    v_16988 = v_16947;
// end of prologue
v_16952:
    v_16986 = v_16988;
    if (v_16986 == nil) goto v_16955;
    else goto v_16956;
v_16955:
    v_16986 = nil;
    goto v_16951;
v_16956:
    goto v_16965;
v_16961:
    v_16986 = v_16988;
    v_16989 = qcar(v_16986);
    goto v_16962;
v_16963:
    v_16986 = v_16987;
    v_16986 = qcar(v_16986);
    goto v_16964;
v_16965:
    goto v_16961;
v_16962:
    goto v_16963;
v_16964:
    if (equal(v_16989, v_16986)) goto v_16959;
    else goto v_16960;
v_16959:
    v_16986 = v_16988;
    v_16986 = qcdr(v_16986);
    v_16988 = v_16986;
    v_16986 = v_16987;
    v_16986 = qcdr(v_16986);
    v_16987 = v_16986;
    goto v_16952;
v_16960:
    goto v_16981;
v_16977:
    v_16986 = v_16988;
    v_16986 = qcar(v_16986);
    goto v_16978;
v_16979:
    v_16987 = qcar(v_16987);
    goto v_16980;
v_16981:
    goto v_16977;
v_16978:
    goto v_16979;
v_16980:
        return Lgreaterp(nil, v_16986, v_16987);
    v_16986 = nil;
v_16951:
    return onevalue(v_16986);
}



// Code for symbol

static LispObject CC_symbol(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_17020, v_17021, v_17022;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16947);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_17021 = v_16947;
// end of prologue
    v_17020 = qvalue(elt(env, 1)); // !*utf8
    if (v_17020 == nil) goto v_16952;
    v_17020 = qvalue(elt(env, 2)); // !*utf82d
    if (v_17020 == nil) goto v_16957;
    goto v_16967;
v_16963:
    v_17022 = v_17021;
    goto v_16964;
v_16965:
    v_17020 = elt(env, 3); // utf8_2d!-symbol!-character
    goto v_16966;
v_16967:
    goto v_16963;
v_16964:
    goto v_16965;
v_16966:
    v_17020 = get(v_17022, v_17020);
    env = stack[0];
    if (v_17020 == nil) goto v_16961;
    else goto v_16960;
v_16961:
    goto v_16978;
v_16974:
    v_17022 = v_17021;
    goto v_16975;
v_16976:
    v_17020 = elt(env, 4); // utf8_symbol!-character
    goto v_16977;
v_16978:
    goto v_16974;
v_16975:
    goto v_16976;
v_16977:
    v_17020 = get(v_17022, v_17020);
    env = stack[0];
    if (v_17020 == nil) goto v_16972;
    else goto v_16971;
v_16972:
    goto v_16986;
v_16982:
    v_17020 = v_17021;
    goto v_16983;
v_16984:
    v_17021 = elt(env, 5); // symbol!-character
    goto v_16985;
v_16986:
    goto v_16982;
v_16983:
    goto v_16984;
v_16985:
    return get(v_17020, v_17021);
v_16971:
v_16960:
    goto v_16955;
v_16957:
    goto v_16999;
v_16995:
    v_17022 = v_17021;
    goto v_16996;
v_16997:
    v_17020 = elt(env, 4); // utf8_symbol!-character
    goto v_16998;
v_16999:
    goto v_16995;
v_16996:
    goto v_16997;
v_16998:
    v_17020 = get(v_17022, v_17020);
    env = stack[0];
    if (v_17020 == nil) goto v_16993;
    else goto v_16992;
v_16993:
    goto v_17007;
v_17003:
    v_17020 = v_17021;
    goto v_17004;
v_17005:
    v_17021 = elt(env, 5); // symbol!-character
    goto v_17006;
v_17007:
    goto v_17003;
v_17004:
    goto v_17005;
v_17006:
    return get(v_17020, v_17021);
v_16992:
    goto v_16955;
    v_17020 = nil;
v_16955:
    goto v_16950;
v_16952:
    goto v_17017;
v_17013:
    v_17020 = v_17021;
    goto v_17014;
v_17015:
    v_17021 = elt(env, 5); // symbol!-character
    goto v_17016;
v_17017:
    goto v_17013;
v_17014:
    goto v_17015;
v_17016:
    return get(v_17020, v_17021);
    v_17020 = nil;
v_16950:
    return onevalue(v_17020);
}



// Code for red!=hide

static LispObject CC_redMhide(LispObject env,
                         LispObject v_16947)
{
    env = qenv(env);
    LispObject v_17023, v_17024;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16947);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_17023 = v_16947;
// end of prologue
    stack[-5] = v_17023;
    v_17023 = stack[-5];
    if (v_17023 == nil) goto v_16958;
    else goto v_16959;
v_16958:
    v_17023 = nil;
    goto v_16953;
v_16959:
    v_17023 = stack[-5];
    v_17023 = qcar(v_17023);
    stack[-1] = v_17023;
    goto v_16971;
v_16967:
    goto v_16977;
v_16973:
    stack[0] = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_16974;
v_16975:
    v_17023 = stack[-1];
    v_17023 = qcar(v_17023);
    fn = elt(env, 1); // mo_neg
    v_17023 = (*qfn1(fn))(fn, v_17023);
    env = stack[-6];
    goto v_16976;
v_16977:
    goto v_16973;
v_16974:
    goto v_16975;
v_16976:
    fn = elt(env, 2); // mo_times_ei
    v_17024 = (*qfn2(fn))(fn, stack[0], v_17023);
    env = stack[-6];
    goto v_16968;
v_16969:
    v_17023 = stack[-1];
    v_17023 = qcdr(v_17023);
    goto v_16970;
v_16971:
    goto v_16967;
v_16968:
    goto v_16969;
v_16970:
    v_17023 = cons(v_17024, v_17023);
    env = stack[-6];
    v_17023 = ncons(v_17023);
    env = stack[-6];
    stack[-3] = v_17023;
    stack[-4] = v_17023;
v_16954:
    v_17023 = stack[-5];
    v_17023 = qcdr(v_17023);
    stack[-5] = v_17023;
    v_17023 = stack[-5];
    if (v_17023 == nil) goto v_16988;
    else goto v_16989;
v_16988:
    v_17023 = stack[-4];
    goto v_16953;
v_16989:
    goto v_16997;
v_16993:
    stack[-2] = stack[-3];
    goto v_16994;
v_16995:
    v_17023 = stack[-5];
    v_17023 = qcar(v_17023);
    stack[-1] = v_17023;
    goto v_17008;
v_17004:
    goto v_17014;
v_17010:
    stack[0] = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_17011;
v_17012:
    v_17023 = stack[-1];
    v_17023 = qcar(v_17023);
    fn = elt(env, 1); // mo_neg
    v_17023 = (*qfn1(fn))(fn, v_17023);
    env = stack[-6];
    goto v_17013;
v_17014:
    goto v_17010;
v_17011:
    goto v_17012;
v_17013:
    fn = elt(env, 2); // mo_times_ei
    v_17024 = (*qfn2(fn))(fn, stack[0], v_17023);
    env = stack[-6];
    goto v_17005;
v_17006:
    v_17023 = stack[-1];
    v_17023 = qcdr(v_17023);
    goto v_17007;
v_17008:
    goto v_17004;
v_17005:
    goto v_17006;
v_17007:
    v_17023 = cons(v_17024, v_17023);
    env = stack[-6];
    v_17023 = ncons(v_17023);
    env = stack[-6];
    goto v_16996;
v_16997:
    goto v_16993;
v_16994:
    goto v_16995;
v_16996:
    v_17023 = Lrplacd(nil, stack[-2], v_17023);
    env = stack[-6];
    v_17023 = stack[-3];
    v_17023 = qcdr(v_17023);
    stack[-3] = v_17023;
    goto v_16954;
v_16953:
    return onevalue(v_17023);
}



// Code for general!-ordered!-gcd!-mod!-p

static LispObject CC_generalKorderedKgcdKmodKp(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_17027, v_17028;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16948,v_16947);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16947,v_16948);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16948;
    stack[-1] = v_16947;
// end of prologue
    v_17027 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_17027;
v_16953:
    goto v_16960;
v_16956:
    v_17028 = stack[-1];
    goto v_16957;
v_16958:
    v_17027 = stack[0];
    goto v_16959;
v_16960:
    goto v_16956;
v_16957:
    goto v_16958;
v_16959:
    fn = elt(env, 2); // general!-reduce!-degree!-mod!-p
    v_17027 = (*qfn2(fn))(fn, v_17028, v_17027);
    env = stack[-3];
    stack[-1] = v_17027;
    v_17027 = stack[-1];
    if (v_17027 == nil) goto v_16965;
    else goto v_16966;
v_16965:
    v_17027 = stack[0];
    {
        fn = elt(env, 3); // general!-monic!-mod!-p
        return (*qfn1(fn))(fn, v_17027);
    }
v_16966:
    v_17027 = stack[-2];
    v_17027 = add1(v_17027);
    env = stack[-3];
    stack[-2] = v_17027;
    v_17027 = stack[-1];
    if (!consp(v_17027)) goto v_16978;
    else goto v_16979;
v_16978:
    v_17027 = lisp_true;
    goto v_16977;
v_16979:
    v_17027 = stack[-1];
    v_17027 = qcar(v_17027);
    v_17027 = (consp(v_17027) ? nil : lisp_true);
    goto v_16977;
    v_17027 = nil;
v_16977:
    if (v_17027 == nil) goto v_16975;
    goto v_16992;
v_16988:
    v_17028 = qvalue(elt(env, 1)); // reduction!-count
    goto v_16989;
v_16990:
    v_17027 = stack[-2];
    goto v_16991;
v_16992:
    goto v_16988;
v_16989:
    goto v_16990;
v_16991:
    v_17027 = plus2(v_17028, v_17027);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_17027; // reduction!-count
    v_17027 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16952;
v_16975:
    goto v_17003;
v_16999:
    v_17027 = stack[-1];
    v_17027 = qcar(v_17027);
    v_17027 = qcar(v_17027);
    v_17028 = qcdr(v_17027);
    goto v_17000;
v_17001:
    v_17027 = stack[0];
    v_17027 = qcar(v_17027);
    v_17027 = qcar(v_17027);
    v_17027 = qcdr(v_17027);
    goto v_17002;
v_17003:
    goto v_16999;
v_17000:
    goto v_17001;
v_17002:
    v_17027 = (LispObject)lessp2(v_17028, v_17027);
    v_17027 = v_17027 ? lisp_true : nil;
    env = stack[-3];
    if (v_17027 == nil) goto v_16997;
    goto v_17020;
v_17016:
    v_17028 = qvalue(elt(env, 1)); // reduction!-count
    goto v_17017;
v_17018:
    v_17027 = stack[-2];
    goto v_17019;
v_17020:
    goto v_17016;
v_17017:
    goto v_17018;
v_17019:
    v_17027 = plus2(v_17028, v_17027);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_17027; // reduction!-count
    v_17027 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_17027;
    v_17027 = stack[-1];
    v_17028 = v_17027;
    v_17027 = stack[0];
    stack[-1] = v_17027;
    v_17027 = v_17028;
    stack[0] = v_17027;
    goto v_16973;
v_16997:
v_16973:
    goto v_16953;
v_16952:
    return onevalue(v_17027);
}



// Code for not_included

static LispObject CC_not_included(LispObject env,
                         LispObject v_16947, LispObject v_16948)
{
    env = qenv(env);
    LispObject v_17001, v_17002, v_17003, v_17004, v_17005;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_17003 = v_16948;
    v_17004 = v_16947;
// end of prologue
    v_17001 = lisp_true;
    v_17005 = v_17001;
v_16956:
    v_17001 = v_17004;
    if (v_17001 == nil) goto v_16959;
    v_17001 = v_17005;
    if (v_17001 == nil) goto v_16959;
    goto v_16960;
v_16959:
    goto v_16955;
v_16960:
    v_17001 = v_17003;
    v_17005 = v_17001;
v_16969:
    v_17001 = v_17005;
    if (v_17001 == nil) goto v_16972;
    goto v_16981;
v_16977:
    v_17001 = v_17004;
    v_17002 = qcar(v_17001);
    goto v_16978;
v_16979:
    v_17001 = v_17005;
    v_17001 = qcar(v_17001);
    goto v_16980;
v_16981:
    goto v_16977;
v_16978:
    goto v_16979;
v_16980:
    if (equal(v_17002, v_17001)) goto v_16972;
    goto v_16973;
v_16972:
    goto v_16968;
v_16973:
    v_17001 = v_17005;
    v_17001 = qcdr(v_17001);
    v_17005 = v_17001;
    goto v_16969;
v_16968:
    v_17001 = v_17004;
    v_17001 = qcdr(v_17001);
    v_17004 = v_17001;
    goto v_16956;
v_16955:
    v_17001 = v_17005;
    if (v_17001 == nil) goto v_16995;
    v_17001 = nil;
    goto v_16993;
v_16995:
    v_17001 = lisp_true;
    goto v_16993;
    v_17001 = nil;
v_16993:
    return onevalue(v_17001);
}



setup_type const u31_setup[] =
{
    {"subsq",                   TOO_FEW_2,      CC_subsq,      WRONG_NO_2},
    {"changearg",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_changearg},
    {"simp-prop2",              CC_simpKprop2,  TOO_MANY_1,    WRONG_NO_1},
    {"cons_ordp",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cons_ordp},
    {"poly-to-vector",          CC_polyKtoKvector,TOO_MANY_1,  WRONG_NO_1},
    {"ofsf_smordtable",         TOO_FEW_2,      CC_ofsf_smordtable,WRONG_NO_2},
    {"checku",                  TOO_FEW_2,      CC_checku,     WRONG_NO_2},
    {"mk+squared+norm",         CC_mkLsquaredLnorm,TOO_MANY_1, WRONG_NO_1},
    {"cl_nnfnot",               CC_cl_nnfnot,   TOO_MANY_1,    WRONG_NO_1},
    {"repr_a",                  CC_repr_a,      TOO_MANY_1,    WRONG_NO_1},
    {"sfto_lcx",                CC_sfto_lcx,    TOO_MANY_1,    WRONG_NO_1},
    {"sfto_b:extmult",          TOO_FEW_2,      CC_sfto_bTextmult,WRONG_NO_2},
    {"relnrd",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_relnrd},
    {"bcminus?",                CC_bcminusW,    TOO_MANY_1,    WRONG_NO_1},
    {"dipprod",                 TOO_FEW_2,      CC_dipprod,    WRONG_NO_2},
    {"basisformp",              CC_basisformp,  TOO_MANY_1,    WRONG_NO_1},
    {"nconc2",                  TOO_FEW_2,      CC_nconc2,     WRONG_NO_2},
    {"formatfort",              CC_formatfort,  TOO_MANY_1,    WRONG_NO_1},
    {"locate_member",           TOO_FEW_2,      CC_locate_member,WRONG_NO_2},
    {"ra_wrapper1",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ra_wrapper1},
    {"deginvar",                TOO_FEW_2,      CC_deginvar,   WRONG_NO_2},
    {"vunion",                  TOO_FEW_2,      CC_vunion,     WRONG_NO_2},
    {"dfconst",                 CC_dfconst,     TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_xor",                TOO_FEW_2,      CC_ofsf_xor,   WRONG_NO_2},
    {"exptplus",                TOO_FEW_2,      CC_exptplus,   WRONG_NO_2},
    {"unify",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_unify},
    {"evload",                  CC_evload,      TOO_MANY_1,    WRONG_NO_1},
    {"repartsq",                CC_repartsq,    TOO_MANY_1,    WRONG_NO_1},
    {"formsetq",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formsetq},
    {"harmonicp",               CC_harmonicp,   TOO_MANY_1,    WRONG_NO_1},
    {"red_topred",              TOO_FEW_2,      CC_red_topred, WRONG_NO_2},
    {"reverse-num1",            TOO_FEW_2,      CC_reverseKnum1,WRONG_NO_2},
    {"mksf",                    CC_mksf,        TOO_MANY_1,    WRONG_NO_1},
    {"make-x-to-p",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_makeKxKtoKp},
    {"lalr_process_productions",TOO_FEW_2,      CC_lalr_process_productions,WRONG_NO_2},
    {"sfto_updecf",             CC_sfto_updecf, TOO_MANY_1,    WRONG_NO_1},
    {"width",                   TOO_FEW_2,      CC_width,      WRONG_NO_2},
    {"get_char_group",          CC_get_char_group,TOO_MANY_1,  WRONG_NO_1},
    {"cl_susiupdknowl2",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_susiupdknowl2},
    {"semanticml",              CC_semanticml,  TOO_MANY_1,    WRONG_NO_1},
    {"derad",                   TOO_FEW_2,      CC_derad,      WRONG_NO_2},
    {"evalvars",                CC_evalvars,    TOO_MANY_1,    WRONG_NO_1},
    {"vdp2a",                   CC_vdp2a,       TOO_MANY_1,    WRONG_NO_1},
    {"gfplusn",                 TOO_FEW_2,      CC_gfplusn,    WRONG_NO_2},
    {"clogsq*",                 CC_clogsqH,     TOO_MANY_1,    WRONG_NO_1},
    {"assert_stat-parse",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_assert_statKparse},
    {"mv-pow->",                TOO_FEW_2,      CC_mvKpowKS,   WRONG_NO_2},
    {"symbol",                  CC_symbol,      TOO_MANY_1,    WRONG_NO_1},
    {"red=hide",                CC_redMhide,    TOO_MANY_1,    WRONG_NO_1},
    {"general-ordered-gcd-mod-p",TOO_FEW_2,     CC_generalKorderedKgcdKmodKp,WRONG_NO_2},
    {"not_included",            TOO_FEW_2,      CC_not_included,WRONG_NO_2},
    {NULL, (one_args *)"u31", (two_args *)"175645 7176666 422310", 0}
};

// end of generated code
