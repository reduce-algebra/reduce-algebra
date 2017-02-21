
// $destdir/u06.c        Machine generated C code

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



// Code for pnthxzz

static LispObject CC_pnthxzz(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1890, v_1891, v_1892, v_1893;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1891 = v_1858;
    v_1892 = v_1857;
// end of prologue
v_1862:
    v_1890 = v_1891;
    if (v_1890 == nil) goto v_1869;
    else goto v_1870;
v_1869:
    v_1890 = lisp_true;
    goto v_1868;
v_1870:
    goto v_1879;
v_1875:
    v_1890 = v_1891;
    v_1890 = qcar(v_1890);
    v_1893 = qcar(v_1890);
    goto v_1876;
v_1877:
    v_1890 = v_1892;
    goto v_1878;
v_1879:
    goto v_1875;
v_1876:
    goto v_1877;
v_1878:
    v_1890 = (equal(v_1893, v_1890) ? lisp_true : nil);
    goto v_1868;
    v_1890 = nil;
v_1868:
    if (v_1890 == nil) goto v_1866;
    v_1890 = v_1891;
    goto v_1861;
v_1866:
    v_1890 = v_1891;
    v_1890 = qcdr(v_1890);
    v_1891 = v_1890;
    goto v_1862;
    v_1890 = nil;
v_1861:
    return onevalue(v_1890);
}



// Code for rd!:onep

static LispObject CC_rdTonep(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1893, v_1894;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_1893 = v_1857;
// end of prologue
    v_1894 = v_1893;
    v_1894 = qcdr(v_1894);
    if (!consp(v_1894)) goto v_1861;
    else goto v_1862;
v_1861:
    goto v_1870;
v_1866:
    goto v_1877;
v_1873:
    v_1894 = elt(env, 1); // 1.0
    goto v_1874;
v_1875:
    v_1893 = qcdr(v_1893);
    goto v_1876;
v_1877:
    goto v_1873;
v_1874:
    goto v_1875;
v_1876:
    v_1893 = difference2(v_1894, v_1893);
    env = stack[-1];
    v_1893 = Labsval(nil, v_1893);
    env = stack[-1];
    goto v_1867;
v_1868:
    v_1894 = qvalue(elt(env, 2)); // !!fleps1
    goto v_1869;
v_1870:
    goto v_1866;
v_1867:
    goto v_1868;
v_1869:
        return Llessp(nil, v_1893, v_1894);
v_1862:
    goto v_1889;
v_1885:
    stack[0] = qvalue(elt(env, 3)); // bfone!*
    goto v_1886;
v_1887:
    fn = elt(env, 4); // bftrim!:
    v_1893 = (*qfn1(fn))(fn, v_1893);
    env = stack[-1];
    goto v_1888;
v_1889:
    goto v_1885;
v_1886:
    goto v_1887;
v_1888:
    {
        LispObject v_1896 = stack[0];
        fn = elt(env, 5); // equal!:
        return (*qfn2(fn))(fn, v_1896, v_1893);
    }
    v_1893 = nil;
    return onevalue(v_1893);
}



// Code for atomf

static LispObject CC_atomf(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1870, v_1871;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1870 = v_1857;
// end of prologue
    v_1871 = v_1870;
    if (!consp(v_1871)) goto v_1861;
    else goto v_1862;
v_1861:
    v_1870 = lisp_true;
    goto v_1860;
v_1862:
    v_1870 = qcar(v_1870);
    if (!symbolp(v_1870)) v_1870 = nil;
    else { v_1870 = qfastgets(v_1870);
           if (v_1870 != nil) { v_1870 = elt(v_1870, 16); // indexvar
#ifdef RECORD_GET
             if (v_1870 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v_1870 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v_1870 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v_1870 == SPID_NOPROP) v_1870 = nil; else v_1870 = lisp_true; }}
#endif
    goto v_1860;
    v_1870 = nil;
v_1860:
    return onevalue(v_1870);
}



// Code for mknwedge

static LispObject CC_mknwedge(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1877, v_1878;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1878 = v_1857;
// end of prologue
    v_1877 = v_1878;
    v_1877 = qcdr(v_1877);
    if (v_1877 == nil) goto v_1862;
    goto v_1870;
v_1866:
    v_1877 = elt(env, 1); // wedge
    goto v_1867;
v_1868:
    goto v_1869;
v_1870:
    goto v_1866;
v_1867:
    goto v_1868;
v_1869:
    return cons(v_1877, v_1878);
v_1862:
    v_1877 = v_1878;
    v_1877 = qcar(v_1877);
    goto v_1860;
    v_1877 = nil;
v_1860:
    return onevalue(v_1877);
}



// Code for putpline

static LispObject CC_putpline(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1963, v_1964, v_1965;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_1857;
// end of prologue
    goto v_1870;
v_1866:
    goto v_1875;
v_1871:
    v_1964 = qvalue(elt(env, 1)); // posn!*
    goto v_1872;
v_1873:
    v_1963 = stack[0];
    v_1963 = qcar(v_1963);
    v_1963 = qcdr(v_1963);
    goto v_1874;
v_1875:
    goto v_1871;
v_1872:
    goto v_1873;
v_1874:
    stack[-1] = (LispObject)(intptr_t)((intptr_t)v_1964 + (intptr_t)v_1963 - TAG_FIXNUM);
    goto v_1867;
v_1868:
    goto v_1885;
v_1881:
    v_1963 = nil;
    v_1964 = Llinelength(nil, v_1963);
    env = stack[-2];
    goto v_1882;
v_1883:
    v_1963 = qvalue(elt(env, 2)); // spare!*
    goto v_1884;
v_1885:
    goto v_1881;
v_1882:
    goto v_1883;
v_1884:
    v_1963 = (LispObject)(intptr_t)((intptr_t)v_1964 - (intptr_t)v_1963 + TAG_FIXNUM);
    goto v_1869;
v_1870:
    goto v_1866;
v_1867:
    goto v_1868;
v_1869:
    v_1963 = (LispObject)greaterp2(stack[-1], v_1963);
    v_1963 = v_1963 ? lisp_true : nil;
    env = stack[-2];
    if (v_1963 == nil) goto v_1864;
    v_1963 = lisp_true;
    fn = elt(env, 8); // terpri!*
    v_1963 = (*qfn1(fn))(fn, v_1963);
    env = stack[-2];
    goto v_1862;
v_1864:
v_1862:
    goto v_1897;
v_1893:
    goto v_1905;
v_1899:
    goto v_1910;
v_1906:
    v_1964 = qvalue(elt(env, 1)); // posn!*
    goto v_1907;
v_1908:
    v_1963 = qvalue(elt(env, 3)); // orig!*
    goto v_1909;
v_1910:
    goto v_1906;
v_1907:
    goto v_1908;
v_1909:
    v_1965 = (LispObject)(intptr_t)((intptr_t)v_1964 - (intptr_t)v_1963 + TAG_FIXNUM);
    goto v_1900;
v_1901:
    v_1964 = qvalue(elt(env, 4)); // ycoord!*
    goto v_1902;
v_1903:
    v_1963 = stack[0];
    v_1963 = qcar(v_1963);
    v_1963 = qcar(v_1963);
    goto v_1904;
v_1905:
    goto v_1899;
v_1900:
    goto v_1901;
v_1902:
    goto v_1903;
v_1904:
    fn = elt(env, 9); // update!-pline
    v_1964 = (*qfnn(fn))(fn, 3, v_1965, v_1964, v_1963);
    env = stack[-2];
    goto v_1894;
v_1895:
    v_1963 = qvalue(elt(env, 5)); // pline!*
    goto v_1896;
v_1897:
    goto v_1893;
v_1894:
    goto v_1895;
v_1896:
    v_1963 = Lappend(nil, v_1964, v_1963);
    env = stack[-2];
    qvalue(elt(env, 5)) = v_1963; // pline!*
    goto v_1923;
v_1919:
    v_1964 = qvalue(elt(env, 1)); // posn!*
    goto v_1920;
v_1921:
    v_1963 = stack[0];
    v_1963 = qcar(v_1963);
    v_1963 = qcdr(v_1963);
    goto v_1922;
v_1923:
    goto v_1919;
v_1920:
    goto v_1921;
v_1922:
    v_1963 = (LispObject)(intptr_t)((intptr_t)v_1964 + (intptr_t)v_1963 - TAG_FIXNUM);
    qvalue(elt(env, 1)) = v_1963; // posn!*
    goto v_1934;
v_1930:
    v_1965 = qvalue(elt(env, 6)); // ymin!*
    goto v_1931;
v_1932:
    goto v_1940;
v_1936:
    v_1963 = stack[0];
    v_1963 = qcdr(v_1963);
    v_1964 = qcar(v_1963);
    goto v_1937;
v_1938:
    v_1963 = qvalue(elt(env, 4)); // ycoord!*
    goto v_1939;
v_1940:
    goto v_1936;
v_1937:
    goto v_1938;
v_1939:
    v_1963 = (LispObject)(intptr_t)((intptr_t)v_1964 + (intptr_t)v_1963 - TAG_FIXNUM);
    goto v_1933;
v_1934:
    goto v_1930;
v_1931:
    goto v_1932;
v_1933:
    fn = elt(env, 10); // min
    v_1963 = (*qfn2(fn))(fn, v_1965, v_1963);
    env = stack[-2];
    qvalue(elt(env, 6)) = v_1963; // ymin!*
    goto v_1951;
v_1947:
    v_1965 = qvalue(elt(env, 7)); // ymax!*
    goto v_1948;
v_1949:
    goto v_1957;
v_1953:
    v_1963 = stack[0];
    v_1963 = qcdr(v_1963);
    v_1964 = qcdr(v_1963);
    goto v_1954;
v_1955:
    v_1963 = qvalue(elt(env, 4)); // ycoord!*
    goto v_1956;
v_1957:
    goto v_1953;
v_1954:
    goto v_1955;
v_1956:
    v_1963 = (LispObject)(intptr_t)((intptr_t)v_1964 + (intptr_t)v_1963 - TAG_FIXNUM);
    goto v_1950;
v_1951:
    goto v_1947;
v_1948:
    goto v_1949;
v_1950:
    fn = elt(env, 11); // max
    v_1963 = (*qfn2(fn))(fn, v_1965, v_1963);
    env = stack[-2];
    qvalue(elt(env, 7)) = v_1963; // ymax!*
    v_1963 = nil;
    return onevalue(v_1963);
}



// Code for int!-equiv!-chk

static LispObject CC_intKequivKchk(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1949, v_1950, v_1951;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_1857;
// end of prologue
    v_1949 = qvalue(elt(env, 1)); // !*noequiv
    if (v_1949 == nil) goto v_1862;
    v_1949 = stack[0];
    goto v_1860;
v_1862:
    v_1949 = stack[0];
    if (!consp(v_1949)) goto v_1872;
    else goto v_1873;
v_1872:
    goto v_1883;
v_1879:
    v_1950 = stack[0];
    goto v_1880;
v_1881:
    v_1949 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1882;
v_1883:
    goto v_1879;
v_1880:
    goto v_1881;
v_1882:
    if (v_1950 == v_1949) goto v_1877;
    else goto v_1878;
v_1877:
    v_1949 = nil;
    goto v_1876;
v_1878:
    v_1949 = stack[0];
    goto v_1876;
    v_1949 = nil;
v_1876:
    goto v_1869;
v_1873:
    goto v_1897;
v_1893:
    v_1949 = stack[0];
    v_1949 = qcar(v_1949);
    if (!symbolp(v_1949)) v_1950 = nil;
    else { v_1950 = qfastgets(v_1949);
           if (v_1950 != nil) { v_1950 = elt(v_1950, 15); // zerop
#ifdef RECORD_GET
             if (v_1950 != SPID_NOPROP)
                record_get(elt(fastget_names, 15), 1);
             else record_get(elt(fastget_names, 15), 0),
                v_1950 = nil; }
           else record_get(elt(fastget_names, 15), 0); }
#else
             if (v_1950 == SPID_NOPROP) v_1950 = nil; }}
#endif
    goto v_1894;
v_1895:
    v_1949 = stack[0];
    goto v_1896;
v_1897:
    goto v_1893;
v_1894:
    goto v_1895;
v_1896:
    v_1949 = Lapply1(nil, v_1950, v_1949);
    env = stack[-1];
    if (v_1949 == nil) goto v_1891;
    v_1949 = nil;
    goto v_1869;
v_1891:
    goto v_1910;
v_1906:
    v_1949 = stack[0];
    v_1949 = qcar(v_1949);
    if (!symbolp(v_1949)) v_1950 = nil;
    else { v_1950 = qfastgets(v_1949);
           if (v_1950 != nil) { v_1950 = elt(v_1950, 26); // onep
#ifdef RECORD_GET
             if (v_1950 != SPID_NOPROP)
                record_get(elt(fastget_names, 26), 1);
             else record_get(elt(fastget_names, 26), 0),
                v_1950 = nil; }
           else record_get(elt(fastget_names, 26), 0); }
#else
             if (v_1950 == SPID_NOPROP) v_1950 = nil; }}
#endif
    goto v_1907;
v_1908:
    v_1949 = stack[0];
    goto v_1909;
v_1910:
    goto v_1906;
v_1907:
    goto v_1908;
v_1909:
    v_1949 = Lapply1(nil, v_1950, v_1949);
    env = stack[-1];
    if (v_1949 == nil) goto v_1904;
    v_1949 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1869;
v_1904:
    v_1949 = stack[0];
    v_1949 = qcar(v_1949);
    if (!symbolp(v_1949)) v_1949 = nil;
    else { v_1949 = qfastgets(v_1949);
           if (v_1949 != nil) { v_1949 = elt(v_1949, 33); // intequivfn
#ifdef RECORD_GET
             if (v_1949 != SPID_NOPROP)
                record_get(elt(fastget_names, 33), 1);
             else record_get(elt(fastget_names, 33), 0),
                v_1949 = nil; }
           else record_get(elt(fastget_names, 33), 0); }
#else
             if (v_1949 == SPID_NOPROP) v_1949 = nil; }}
#endif
    v_1950 = v_1949;
    if (v_1949 == nil) goto v_1917;
    goto v_1928;
v_1924:
    goto v_1925;
v_1926:
    v_1949 = stack[0];
    goto v_1927;
v_1928:
    goto v_1924;
v_1925:
    goto v_1926;
v_1927:
    v_1949 = Lapply1(nil, v_1950, v_1949);
    v_1950 = v_1949;
    if (v_1949 == nil) goto v_1917;
    goto v_1939;
v_1935:
    v_1951 = v_1950;
    goto v_1936;
v_1937:
    v_1949 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1938;
v_1939:
    goto v_1935;
v_1936:
    goto v_1937;
v_1938:
    if (v_1951 == v_1949) goto v_1933;
    else goto v_1934;
v_1933:
    v_1949 = nil;
    goto v_1932;
v_1934:
    v_1949 = v_1950;
    goto v_1932;
    v_1949 = nil;
v_1932:
    goto v_1869;
v_1917:
    v_1949 = stack[0];
    goto v_1869;
    v_1949 = nil;
v_1869:
    goto v_1860;
    v_1949 = nil;
v_1860:
    return onevalue(v_1949);
}



// Code for dp!=ecart

static LispObject CC_dpMecart(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1901, v_1902;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_1857;
// end of prologue
    stack[-1] = nil;
v_1863:
    v_1901 = stack[0];
    if (v_1901 == nil) goto v_1868;
    else goto v_1869;
v_1868:
    goto v_1864;
v_1869:
    goto v_1876;
v_1872:
    v_1901 = stack[0];
    fn = elt(env, 1); // dp_lmon
    v_1901 = (*qfn1(fn))(fn, v_1901);
    env = stack[-2];
    fn = elt(env, 2); // mo_ecart
    v_1902 = (*qfn1(fn))(fn, v_1901);
    env = stack[-2];
    goto v_1873;
v_1874:
    v_1901 = stack[-1];
    goto v_1875;
v_1876:
    goto v_1872;
v_1873:
    goto v_1874;
v_1875:
    v_1901 = cons(v_1902, v_1901);
    env = stack[-2];
    stack[-1] = v_1901;
    v_1901 = stack[0];
    v_1901 = qcdr(v_1901);
    stack[0] = v_1901;
    goto v_1863;
v_1864:
    v_1901 = (LispObject)0+TAG_FIXNUM; // 0
    v_1902 = v_1901;
v_1865:
    v_1901 = stack[-1];
    if (v_1901 == nil) goto v_1886;
    else goto v_1887;
v_1886:
    v_1901 = v_1902;
    goto v_1862;
v_1887:
    goto v_1895;
v_1891:
    v_1901 = stack[-1];
    v_1901 = qcar(v_1901);
    goto v_1892;
v_1893:
    goto v_1894;
v_1895:
    goto v_1891;
v_1892:
    goto v_1893;
v_1894:
    v_1901 = Lmax2(nil, v_1901, v_1902);
    env = stack[-2];
    v_1902 = v_1901;
    v_1901 = stack[-1];
    v_1901 = qcdr(v_1901);
    stack[-1] = v_1901;
    goto v_1865;
v_1862:
    return onevalue(v_1901);
}



// Code for gperm1

static LispObject CC_gperm1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_1920, v_1921, v_1922;
    LispObject fn;
    LispObject v_1860, v_1859, v_1858, v_1857;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "gperm1");
    va_start(aa, nargs);
    v_1857 = va_arg(aa, LispObject);
    v_1858 = va_arg(aa, LispObject);
    v_1859 = va_arg(aa, LispObject);
    v_1860 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_1860,v_1859,v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_1857,v_1858,v_1859,v_1860);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_1860;
    stack[-2] = v_1859;
    stack[-3] = v_1858;
    stack[-4] = v_1857;
// end of prologue
v_1866:
    v_1920 = stack[-4];
    if (v_1920 == nil) goto v_1869;
    else goto v_1870;
v_1869:
    goto v_1879;
v_1873:
    v_1922 = stack[-3];
    goto v_1874;
v_1875:
    v_1921 = stack[-2];
    goto v_1876;
v_1877:
    v_1920 = stack[-1];
    goto v_1878;
v_1879:
    goto v_1873;
v_1874:
    goto v_1875;
v_1876:
    goto v_1877;
v_1878:
    return acons(v_1922, v_1921, v_1920);
v_1870:
    v_1920 = stack[-4];
    v_1920 = qcdr(v_1920);
    stack[-5] = v_1920;
    goto v_1892;
v_1888:
    v_1920 = stack[-4];
    v_1921 = qcar(v_1920);
    goto v_1889;
v_1890:
    v_1920 = stack[-2];
    goto v_1891;
v_1892:
    goto v_1888;
v_1889:
    goto v_1890;
v_1891:
    v_1920 = cons(v_1921, v_1920);
    env = stack[-6];
    stack[0] = v_1920;
    goto v_1901;
v_1897:
    goto v_1907;
v_1903:
    goto v_1904;
v_1905:
    goto v_1914;
v_1910:
    v_1921 = stack[-3];
    goto v_1911;
v_1912:
    v_1920 = stack[-2];
    goto v_1913;
v_1914:
    goto v_1910;
v_1911:
    goto v_1912;
v_1913:
    v_1920 = cons(v_1921, v_1920);
    env = stack[-6];
    goto v_1906;
v_1907:
    goto v_1903;
v_1904:
    goto v_1905;
v_1906:
    fn = elt(env, 1); // rev
    v_1921 = (*qfn2(fn))(fn, stack[-4], v_1920);
    env = stack[-6];
    goto v_1898;
v_1899:
    v_1920 = stack[-1];
    goto v_1900;
v_1901:
    goto v_1897;
v_1898:
    goto v_1899;
v_1900:
    v_1920 = cons(v_1921, v_1920);
    env = stack[-6];
    stack[-1] = v_1920;
    v_1920 = stack[0];
    stack[-2] = v_1920;
    v_1920 = stack[-5];
    stack[-4] = v_1920;
    goto v_1866;
    v_1920 = nil;
    return onevalue(v_1920);
}



// Code for mkrn

static LispObject CC_mkrn(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1915, v_1916;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1857,v_1858);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_1858;
    stack[-2] = v_1857;
// end of prologue
v_1862:
    goto v_1872;
v_1868:
    v_1916 = stack[-1];
    goto v_1869;
v_1870:
    v_1915 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1871;
v_1872:
    goto v_1868;
v_1869:
    goto v_1870;
v_1871:
    v_1915 = (LispObject)lessp2(v_1916, v_1915);
    v_1915 = v_1915 ? lisp_true : nil;
    env = stack[-4];
    if (v_1915 == nil) goto v_1866;
    v_1915 = stack[-2];
    v_1915 = negate(v_1915);
    env = stack[-4];
    stack[-2] = v_1915;
    v_1915 = stack[-1];
    v_1915 = negate(v_1915);
    env = stack[-4];
    stack[-1] = v_1915;
    goto v_1862;
v_1866:
    goto v_1886;
v_1882:
    v_1916 = stack[-2];
    goto v_1883;
v_1884:
    v_1915 = stack[-1];
    goto v_1885;
v_1886:
    goto v_1882;
v_1883:
    goto v_1884;
v_1885:
    v_1915 = Lgcd(nil, v_1916, v_1915);
    env = stack[-4];
    stack[-3] = v_1915;
    goto v_1897;
v_1891:
    stack[0] = elt(env, 1); // !:rn!:
    goto v_1892;
v_1893:
    goto v_1904;
v_1900:
    v_1916 = stack[-2];
    goto v_1901;
v_1902:
    v_1915 = stack[-3];
    goto v_1903;
v_1904:
    goto v_1900;
v_1901:
    goto v_1902;
v_1903:
    stack[-2] = quot2(v_1916, v_1915);
    env = stack[-4];
    goto v_1894;
v_1895:
    goto v_1912;
v_1908:
    v_1916 = stack[-1];
    goto v_1909;
v_1910:
    v_1915 = stack[-3];
    goto v_1911;
v_1912:
    goto v_1908;
v_1909:
    goto v_1910;
v_1911:
    v_1915 = quot2(v_1916, v_1915);
    goto v_1896;
v_1897:
    goto v_1891;
v_1892:
    goto v_1893;
v_1894:
    goto v_1895;
v_1896:
    {
        LispObject v_1921 = stack[0];
        LispObject v_1922 = stack[-2];
        return list2star(v_1921, v_1922, v_1915);
    }
    v_1915 = nil;
    return onevalue(v_1915);
}



// Code for evaluate!-in!-order

static LispObject CC_evaluateKinKorder(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1926, v_1927, v_1928, v_1929;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1857,v_1858);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_1858;
    stack[-1] = v_1857;
// end of prologue
v_1862:
    v_1926 = stack[-1];
    if (!consp(v_1926)) goto v_1869;
    else goto v_1870;
v_1869:
    v_1926 = lisp_true;
    goto v_1868;
v_1870:
    v_1926 = stack[-1];
    v_1926 = qcar(v_1926);
    v_1926 = (consp(v_1926) ? nil : lisp_true);
    goto v_1868;
    v_1926 = nil;
v_1868:
    if (v_1926 == nil) goto v_1866;
    v_1926 = stack[-1];
    {
        fn = elt(env, 1); // !*d2n
        return (*qfn1(fn))(fn, v_1926);
    }
v_1866:
    goto v_1886;
v_1882:
    v_1926 = stack[-1];
    v_1926 = qcar(v_1926);
    v_1926 = qcar(v_1926);
    v_1927 = qcar(v_1926);
    goto v_1883;
v_1884:
    v_1926 = stack[0];
    v_1926 = qcar(v_1926);
    v_1926 = qcar(v_1926);
    goto v_1885;
v_1886:
    goto v_1882;
v_1883:
    goto v_1884;
v_1885:
    if (equal(v_1927, v_1926)) goto v_1880;
    else goto v_1881;
v_1880:
    goto v_1903;
v_1895:
    goto v_1909;
v_1905:
    v_1926 = stack[-1];
    v_1926 = qcar(v_1926);
    v_1927 = qcdr(v_1926);
    goto v_1906;
v_1907:
    v_1926 = stack[0];
    v_1926 = qcdr(v_1926);
    goto v_1908;
v_1909:
    goto v_1905;
v_1906:
    goto v_1907;
v_1908:
    v_1929 = CC_evaluateKinKorder(elt(env, 0), v_1927, v_1926);
    env = stack[-2];
    goto v_1896;
v_1897:
    v_1926 = stack[-1];
    v_1926 = qcar(v_1926);
    v_1926 = qcar(v_1926);
    v_1928 = qcdr(v_1926);
    goto v_1898;
v_1899:
    v_1926 = stack[-1];
    v_1927 = qcdr(v_1926);
    goto v_1900;
v_1901:
    v_1926 = stack[0];
    goto v_1902;
v_1903:
    goto v_1895;
v_1896:
    goto v_1897;
v_1898:
    goto v_1899;
v_1900:
    goto v_1901;
v_1902:
    {
        fn = elt(env, 2); // horner!-rule
        return (*qfnn(fn))(fn, 4, v_1929, v_1928, v_1927, v_1926);
    }
v_1881:
    v_1926 = stack[0];
    v_1926 = qcdr(v_1926);
    stack[0] = v_1926;
    goto v_1862;
    v_1926 = nil;
    return onevalue(v_1926);
}



// Code for set_svf

static LispObject CC_set_svf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_1880, v_1881, v_1882;
    LispObject fn;
    LispObject v_1860, v_1859, v_1858, v_1857;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "set_svf");
    va_start(aa, nargs);
    v_1857 = va_arg(aa, LispObject);
    v_1858 = va_arg(aa, LispObject);
    v_1859 = va_arg(aa, LispObject);
    v_1860 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_1860,v_1859,v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_1857,v_1858,v_1859,v_1860);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_1860;
    v_1880 = v_1859;
    v_1881 = v_1858;
    v_1882 = v_1857;
// end of prologue
    goto v_1867;
v_1863:
    goto v_1875;
v_1869:
    goto v_1870;
v_1871:
    goto v_1872;
v_1873:
    goto v_1874;
v_1875:
    goto v_1869;
v_1870:
    goto v_1871;
v_1872:
    goto v_1873;
v_1874:
    v_1881 = list3(v_1882, v_1881, v_1880);
    env = stack[-1];
    goto v_1864;
v_1865:
    v_1880 = stack[0];
    goto v_1866;
v_1867:
    goto v_1863;
v_1864:
    goto v_1865;
v_1866:
    {
        fn = elt(env, 1); // setk
        return (*qfn2(fn))(fn, v_1881, v_1880);
    }
}



// Code for freeofdepl

static LispObject CC_freeofdepl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_1899, v_1900;
    LispObject fn;
    LispObject v_1859, v_1858, v_1857;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "freeofdepl");
    va_start(aa, nargs);
    v_1857 = va_arg(aa, LispObject);
    v_1858 = va_arg(aa, LispObject);
    v_1859 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_1859,v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_1857,v_1858,v_1859);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_1859;
    stack[-1] = v_1858;
    stack[-2] = v_1857;
// end of prologue
v_1863:
    v_1899 = stack[-2];
    if (v_1899 == nil) goto v_1866;
    else goto v_1867;
v_1866:
    v_1899 = lisp_true;
    goto v_1862;
v_1867:
    goto v_1878;
v_1874:
    v_1900 = stack[0];
    goto v_1875;
v_1876:
    v_1899 = stack[-2];
    v_1899 = qcar(v_1899);
    v_1899 = qcdr(v_1899);
    goto v_1877;
v_1878:
    goto v_1874;
v_1875:
    goto v_1876;
v_1877:
    fn = elt(env, 1); // smember
    v_1899 = (*qfn2(fn))(fn, v_1900, v_1899);
    env = stack[-3];
    if (v_1899 == nil) goto v_1871;
    goto v_1889;
v_1885:
    v_1899 = stack[-2];
    v_1899 = qcar(v_1899);
    v_1900 = qcar(v_1899);
    goto v_1886;
v_1887:
    v_1899 = stack[-1];
    goto v_1888;
v_1889:
    goto v_1885;
v_1886:
    goto v_1887;
v_1888:
    fn = elt(env, 1); // smember
    v_1899 = (*qfn2(fn))(fn, v_1900, v_1899);
    env = stack[-3];
    if (v_1899 == nil) goto v_1871;
    v_1899 = nil;
    goto v_1862;
v_1871:
    v_1899 = stack[-2];
    v_1899 = qcdr(v_1899);
    stack[-2] = v_1899;
    goto v_1863;
    v_1899 = nil;
v_1862:
    return onevalue(v_1899);
}



// Code for rl_smmkatl

static LispObject CC_rl_smmkatl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_1883, v_1884, v_1885, v_1886;
    LispObject fn;
    LispObject v_1860, v_1859, v_1858, v_1857;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "rl_smmkatl");
    va_start(aa, nargs);
    v_1857 = va_arg(aa, LispObject);
    v_1858 = va_arg(aa, LispObject);
    v_1859 = va_arg(aa, LispObject);
    v_1860 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_1860,v_1859,v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_1857,v_1858,v_1859,v_1860);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_1883 = v_1860;
    v_1884 = v_1859;
    v_1885 = v_1858;
    v_1886 = v_1857;
// end of prologue
    goto v_1867;
v_1863:
    stack[0] = qvalue(elt(env, 1)); // rl_smmkatl!*
    goto v_1864;
v_1865:
    goto v_1878;
v_1870:
    goto v_1871;
v_1872:
    goto v_1873;
v_1874:
    goto v_1875;
v_1876:
    goto v_1877;
v_1878:
    goto v_1870;
v_1871:
    goto v_1872;
v_1873:
    goto v_1874;
v_1875:
    goto v_1876;
v_1877:
    v_1883 = list4(v_1886, v_1885, v_1884, v_1883);
    env = stack[-1];
    goto v_1866;
v_1867:
    goto v_1863;
v_1864:
    goto v_1865;
v_1866:
    {
        LispObject v_1888 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_1888, v_1883);
    }
}



// Code for mri_0mk2

static LispObject CC_mri_0mk2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_1875, v_1876, v_1877, v_1878;
    LispObject v_1859, v_1858, v_1857;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mri_0mk2");
    va_start(aa, nargs);
    v_1857 = va_arg(aa, LispObject);
    v_1858 = va_arg(aa, LispObject);
    v_1859 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1877 = v_1859;
    v_1875 = v_1858;
    v_1876 = v_1857;
// end of prologue
    goto v_1870;
v_1862:
    v_1878 = v_1876;
    goto v_1863;
v_1864:
    v_1876 = v_1875;
    goto v_1865;
v_1866:
    v_1875 = nil;
    goto v_1867;
v_1868:
    goto v_1869;
v_1870:
    goto v_1862;
v_1863:
    goto v_1864;
v_1865:
    goto v_1866;
v_1867:
    goto v_1868;
v_1869:
    return list4(v_1878, v_1876, v_1875, v_1877);
}



// Code for cgp_evlmon

static LispObject CC_cgp_evlmon(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1862;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_1862 = v_1857;
// end of prologue
    fn = elt(env, 1); // cgp_rp
    v_1862 = (*qfn1(fn))(fn, v_1862);
    env = stack[0];
    {
        fn = elt(env, 2); // dip_evlmon
        return (*qfn1(fn))(fn, v_1862);
    }
}



// Code for sortcolelem

static LispObject CC_sortcolelem(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_1952, v_1953;
    LispObject v_1859, v_1858, v_1857;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sortcolelem");
    va_start(aa, nargs);
    v_1857 = va_arg(aa, LispObject);
    v_1858 = va_arg(aa, LispObject);
    v_1859 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_1859,v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_1857,v_1858,v_1859);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_1859;
    stack[-2] = v_1858;
    stack[-3] = v_1857;
// end of prologue
    stack[0] = nil;
    v_1952 = stack[-2];
    v_1952 = qcdr(v_1952);
    stack[-4] = v_1952;
v_1869:
    v_1952 = stack[0];
    if (v_1952 == nil) goto v_1873;
    goto v_1868;
v_1873:
    v_1952 = stack[-4];
    if (v_1952 == nil) goto v_1878;
    else goto v_1879;
v_1878:
    goto v_1886;
v_1882:
    stack[0] = stack[-2];
    goto v_1883;
v_1884:
    goto v_1894;
v_1890:
    v_1953 = stack[-3];
    goto v_1891;
v_1892:
    v_1952 = stack[-1];
    goto v_1893;
v_1894:
    goto v_1890;
v_1891:
    goto v_1892;
v_1893:
    v_1952 = cons(v_1953, v_1952);
    env = stack[-5];
    v_1952 = ncons(v_1952);
    env = stack[-5];
    goto v_1885;
v_1886:
    goto v_1882;
v_1883:
    goto v_1884;
v_1885:
    v_1952 = Lrplacd(nil, stack[0], v_1952);
    env = stack[-5];
    v_1952 = lisp_true;
    stack[0] = v_1952;
    goto v_1877;
v_1879:
    goto v_1905;
v_1901:
    v_1953 = stack[-3];
    goto v_1902;
v_1903:
    v_1952 = stack[-4];
    v_1952 = qcar(v_1952);
    v_1952 = qcar(v_1952);
    goto v_1904;
v_1905:
    goto v_1901;
v_1902:
    goto v_1903;
v_1904:
    v_1952 = (LispObject)lessp2(v_1953, v_1952);
    v_1952 = v_1952 ? lisp_true : nil;
    env = stack[-5];
    if (v_1952 == nil) goto v_1899;
    goto v_1915;
v_1911:
    stack[0] = stack[-2];
    goto v_1912;
v_1913:
    goto v_1922;
v_1918:
    goto v_1929;
v_1925:
    v_1953 = stack[-3];
    goto v_1926;
v_1927:
    v_1952 = stack[-1];
    goto v_1928;
v_1929:
    goto v_1925;
v_1926:
    goto v_1927;
v_1928:
    v_1952 = cons(v_1953, v_1952);
    env = stack[-5];
    v_1953 = ncons(v_1952);
    env = stack[-5];
    goto v_1919;
v_1920:
    v_1952 = stack[-4];
    goto v_1921;
v_1922:
    goto v_1918;
v_1919:
    goto v_1920;
v_1921:
    v_1952 = Lrplacd(nil, v_1953, v_1952);
    env = stack[-5];
    goto v_1914;
v_1915:
    goto v_1911;
v_1912:
    goto v_1913;
v_1914:
    v_1952 = Lrplacd(nil, stack[0], v_1952);
    env = stack[-5];
    v_1952 = lisp_true;
    stack[0] = v_1952;
    goto v_1877;
v_1899:
    goto v_1941;
v_1937:
    v_1953 = stack[-3];
    goto v_1938;
v_1939:
    v_1952 = stack[-4];
    v_1952 = qcar(v_1952);
    v_1952 = qcar(v_1952);
    goto v_1940;
v_1941:
    goto v_1937;
v_1938:
    goto v_1939;
v_1940:
    v_1952 = (LispObject)greaterp2(v_1953, v_1952);
    v_1952 = v_1952 ? lisp_true : nil;
    env = stack[-5];
    if (v_1952 == nil) goto v_1935;
    v_1952 = nil;
    stack[0] = v_1952;
    v_1952 = stack[-2];
    v_1952 = qcdr(v_1952);
    stack[-2] = v_1952;
    v_1952 = stack[-2];
    v_1952 = qcdr(v_1952);
    stack[-4] = v_1952;
    goto v_1877;
v_1935:
v_1877:
    goto v_1869;
v_1868:
    v_1952 = nil;
    return onevalue(v_1952);
}



// Code for fast!-column!-dim

static LispObject CC_fastKcolumnKdim(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1869, v_1870;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
// copy arguments values to proper place
    v_1869 = v_1857;
// end of prologue
    goto v_1865;
v_1861:
    v_1870 = v_1869;
    goto v_1862;
v_1863:
    v_1869 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1864;
v_1865:
    goto v_1861;
v_1862:
    goto v_1863;
v_1864:
    v_1869 = *(LispObject *)((char *)v_1870 + (CELL-TAG_VECTOR) + (((intptr_t)v_1869-TAG_FIXNUM)/(16/CELL)));
    v_1869 = Lupbv(nil, v_1869);
    return add1(v_1869);
}



// Code for evtdeg

static LispObject CC_evtdeg(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1882, v_1883, v_1884;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1883 = v_1857;
// end of prologue
    v_1882 = (LispObject)0+TAG_FIXNUM; // 0
v_1863:
    v_1884 = v_1883;
    if (v_1884 == nil) goto v_1866;
    else goto v_1867;
v_1866:
    goto v_1862;
v_1867:
    goto v_1874;
v_1870:
    v_1884 = v_1883;
    v_1884 = qcar(v_1884);
    goto v_1871;
v_1872:
    goto v_1873;
v_1874:
    goto v_1870;
v_1871:
    goto v_1872;
v_1873:
    v_1882 = (LispObject)(intptr_t)((intptr_t)v_1884 + (intptr_t)v_1882 - TAG_FIXNUM);
    v_1883 = qcdr(v_1883);
    goto v_1863;
v_1862:
    return onevalue(v_1882);
}



// Code for algid

static LispObject CC_algid(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1881, v_1882, v_1883;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1881 = v_1858;
    v_1882 = v_1857;
// end of prologue
    goto v_1869;
v_1865:
    v_1883 = v_1882;
    goto v_1866;
v_1867:
    goto v_1868;
v_1869:
    goto v_1865;
v_1866:
    goto v_1867;
v_1868:
    v_1881 = Latsoc(nil, v_1883, v_1881);
    if (v_1881 == nil) goto v_1864;
    else goto v_1862;
v_1864:
    v_1881 = v_1882;
    if (!symbolp(v_1881)) v_1881 = nil;
    else { v_1881 = qfastgets(v_1881);
           if (v_1881 != nil) { v_1881 = elt(v_1881, 17); // share
#ifdef RECORD_GET
             if (v_1881 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v_1881 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v_1881 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v_1881 == SPID_NOPROP) v_1881 = nil; else v_1881 = lisp_true; }}
#endif
    if (v_1881 == nil) goto v_1873;
    else goto v_1862;
v_1873:
    goto v_1863;
v_1862:
    v_1881 = v_1882;
    goto v_1861;
v_1863:
    v_1881 = v_1882;
        return Lmkquote(nil, v_1881);
    v_1881 = nil;
v_1861:
    return onevalue(v_1881);
}



// Code for csl_timbf

static LispObject CC_csl_timbf(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1926, v_1927, v_1928;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1857,v_1858);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_1858;
    stack[-3] = v_1857;
// end of prologue
    goto v_1868;
v_1864:
    v_1926 = stack[-3];
    v_1926 = qcdr(v_1926);
    v_1927 = qcar(v_1926);
    goto v_1865;
v_1866:
    v_1926 = stack[-2];
    v_1926 = qcdr(v_1926);
    v_1926 = qcar(v_1926);
    goto v_1867;
v_1868:
    goto v_1864;
v_1865:
    goto v_1866;
v_1867:
    v_1926 = times2(v_1927, v_1926);
    env = stack[-5];
    v_1928 = v_1926;
    goto v_1883;
v_1879:
    v_1927 = v_1928;
    goto v_1880;
v_1881:
    v_1926 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1882;
v_1883:
    goto v_1879;
v_1880:
    goto v_1881;
v_1882:
    if (v_1927 == v_1926) goto v_1877;
    else goto v_1878;
v_1877:
    v_1926 = elt(env, 1); // (!:rd!: 0 . 0)
    goto v_1862;
v_1878:
    goto v_1892;
v_1888:
    v_1927 = v_1928;
    goto v_1889;
v_1890:
    v_1926 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_1891;
v_1892:
    goto v_1888;
v_1889:
    goto v_1890;
v_1891:
    fn = elt(env, 4); // inorm
    v_1926 = (*qfn2(fn))(fn, v_1927, v_1926);
    env = stack[-5];
    v_1928 = v_1926;
    goto v_1902;
v_1896:
    stack[-4] = elt(env, 3); // !:rd!:
    goto v_1897;
v_1898:
    v_1926 = v_1928;
    stack[-1] = qcar(v_1926);
    goto v_1899;
v_1900:
    goto v_1911;
v_1907:
    v_1926 = v_1928;
    stack[0] = qcdr(v_1926);
    goto v_1908;
v_1909:
    goto v_1919;
v_1915:
    v_1926 = stack[-3];
    v_1926 = qcdr(v_1926);
    v_1927 = qcdr(v_1926);
    goto v_1916;
v_1917:
    v_1926 = stack[-2];
    v_1926 = qcdr(v_1926);
    v_1926 = qcdr(v_1926);
    goto v_1918;
v_1919:
    goto v_1915;
v_1916:
    goto v_1917;
v_1918:
    v_1926 = plus2(v_1927, v_1926);
    env = stack[-5];
    goto v_1910;
v_1911:
    goto v_1907;
v_1908:
    goto v_1909;
v_1910:
    v_1926 = plus2(stack[0], v_1926);
    goto v_1901;
v_1902:
    goto v_1896;
v_1897:
    goto v_1898;
v_1899:
    goto v_1900;
v_1901:
    {
        LispObject v_1934 = stack[-4];
        LispObject v_1935 = stack[-1];
        return list2star(v_1934, v_1935, v_1926);
    }
v_1862:
    return onevalue(v_1926);
}



// Code for safe!-fp!-minus

static LispObject CC_safeKfpKminus(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1878, v_1879, v_1880;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1880 = v_1857;
// end of prologue
    v_1878 = qvalue(elt(env, 1)); // !*nonegzerominus
    if (v_1878 == nil) goto v_1862;
    goto v_1870;
v_1866:
    v_1879 = v_1880;
    goto v_1867;
v_1868:
    v_1878 = elt(env, 2); // 0.0
    goto v_1869;
v_1870:
    goto v_1866;
v_1867:
    goto v_1868;
v_1869:
    if (equal(v_1879, v_1878)) goto v_1865;
    else goto v_1862;
v_1865:
    v_1878 = elt(env, 2); // 0.0
    goto v_1860;
v_1862:
    v_1878 = v_1880;
    return negate(v_1878);
    v_1878 = nil;
v_1860:
    return onevalue(v_1878);
}



// Code for getrmacro

static LispObject CC_getrmacro(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1922, v_1923, v_1924;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_1857;
// end of prologue
    v_1922 = stack[0];
    if (symbolp(v_1922)) goto v_1865;
    v_1922 = nil;
    goto v_1863;
v_1865:
    v_1922 = stack[0];
    fn = elt(env, 4); // getd
    v_1922 = (*qfn1(fn))(fn, v_1922);
    env = stack[-1];
    v_1924 = v_1922;
    if (v_1922 == nil) goto v_1869;
    goto v_1878;
v_1874:
    v_1922 = v_1924;
    v_1923 = qcar(v_1922);
    goto v_1875;
v_1876:
    v_1922 = elt(env, 1); // macro
    goto v_1877;
v_1878:
    goto v_1874;
v_1875:
    goto v_1876;
v_1877:
    if (v_1923 == v_1922) goto v_1873;
    else goto v_1869;
v_1873:
    v_1922 = v_1924;
    goto v_1863;
v_1869:
    goto v_1890;
v_1886:
    v_1923 = stack[0];
    goto v_1887;
v_1888:
    v_1922 = elt(env, 2); // inline
    goto v_1889;
v_1890:
    goto v_1886;
v_1887:
    goto v_1888;
v_1889:
    v_1922 = get(v_1923, v_1922);
    env = stack[-1];
    v_1924 = v_1922;
    if (v_1922 == nil) goto v_1884;
    goto v_1898;
v_1894:
    v_1922 = elt(env, 2); // inline
    goto v_1895;
v_1896:
    v_1923 = v_1924;
    goto v_1897;
v_1898:
    goto v_1894;
v_1895:
    goto v_1896;
v_1897:
    return cons(v_1922, v_1923);
v_1884:
    goto v_1908;
v_1904:
    v_1923 = stack[0];
    goto v_1905;
v_1906:
    v_1922 = elt(env, 3); // smacro
    goto v_1907;
v_1908:
    goto v_1904;
v_1905:
    goto v_1906;
v_1907:
    v_1922 = get(v_1923, v_1922);
    env = stack[-1];
    v_1924 = v_1922;
    if (v_1922 == nil) goto v_1902;
    goto v_1916;
v_1912:
    v_1922 = elt(env, 3); // smacro
    goto v_1913;
v_1914:
    v_1923 = v_1924;
    goto v_1915;
v_1916:
    goto v_1912;
v_1913:
    goto v_1914;
v_1915:
    return cons(v_1922, v_1923);
v_1902:
    v_1922 = nil;
    goto v_1863;
    v_1922 = nil;
v_1863:
    return onevalue(v_1922);
}



// Code for getelv

static LispObject CC_getelv(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1911, v_1912;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_1912 = v_1857;
// end of prologue
    goto v_1865;
v_1861:
    v_1911 = v_1912;
    stack[-4] = qcar(v_1911);
    goto v_1862;
v_1863:
    v_1911 = v_1912;
    v_1911 = qcdr(v_1911);
    stack[-3] = v_1911;
    v_1911 = stack[-3];
    if (v_1911 == nil) goto v_1878;
    else goto v_1879;
v_1878:
    v_1911 = nil;
    goto v_1872;
v_1879:
    v_1911 = stack[-3];
    v_1911 = qcar(v_1911);
    fn = elt(env, 1); // reval_without_mod
    v_1911 = (*qfn1(fn))(fn, v_1911);
    env = stack[-5];
    v_1911 = ncons(v_1911);
    env = stack[-5];
    stack[-1] = v_1911;
    stack[-2] = v_1911;
v_1873:
    v_1911 = stack[-3];
    v_1911 = qcdr(v_1911);
    stack[-3] = v_1911;
    v_1911 = stack[-3];
    if (v_1911 == nil) goto v_1892;
    else goto v_1893;
v_1892:
    v_1911 = stack[-2];
    goto v_1872;
v_1893:
    goto v_1901;
v_1897:
    stack[0] = stack[-1];
    goto v_1898;
v_1899:
    v_1911 = stack[-3];
    v_1911 = qcar(v_1911);
    fn = elt(env, 1); // reval_without_mod
    v_1911 = (*qfn1(fn))(fn, v_1911);
    env = stack[-5];
    v_1911 = ncons(v_1911);
    env = stack[-5];
    goto v_1900;
v_1901:
    goto v_1897;
v_1898:
    goto v_1899;
v_1900:
    v_1911 = Lrplacd(nil, stack[0], v_1911);
    env = stack[-5];
    v_1911 = stack[-1];
    v_1911 = qcdr(v_1911);
    stack[-1] = v_1911;
    goto v_1873;
v_1872:
    goto v_1864;
v_1865:
    goto v_1861;
v_1862:
    goto v_1863;
v_1864:
    v_1911 = cons(stack[-4], v_1911);
    env = stack[-5];
    {
        fn = elt(env, 2); // getel
        return (*qfn1(fn))(fn, v_1911);
    }
}



// Code for dp_diff

static LispObject CC_dp_diff(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1869, v_1870;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1857,v_1858);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_1869 = v_1858;
    v_1870 = v_1857;
// end of prologue
    goto v_1865;
v_1861:
    stack[0] = v_1870;
    goto v_1862;
v_1863:
    fn = elt(env, 1); // dp_neg
    v_1869 = (*qfn1(fn))(fn, v_1869);
    env = stack[-1];
    goto v_1864;
v_1865:
    goto v_1861;
v_1862:
    goto v_1863;
v_1864:
    {
        LispObject v_1872 = stack[0];
        fn = elt(env, 2); // dp_sum
        return (*qfn2(fn))(fn, v_1872, v_1869);
    }
}



// Code for tsym4

static LispObject CC_tsym4(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_1901, v_1902;
    LispObject fn;
    LispObject v_1859, v_1858, v_1857;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "tsym4");
    va_start(aa, nargs);
    v_1857 = va_arg(aa, LispObject);
    v_1858 = va_arg(aa, LispObject);
    v_1859 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_1859,v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_1857,v_1858,v_1859);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_1859;
    stack[-1] = v_1858;
    v_1901 = v_1857;
// end of prologue
v_1864:
    v_1902 = v_1901;
    if (v_1902 == nil) goto v_1867;
    else goto v_1868;
v_1867:
    v_1901 = stack[0];
    goto v_1863;
v_1868:
    v_1902 = v_1901;
    v_1902 = qcdr(v_1902);
    stack[-2] = v_1902;
    goto v_1880;
v_1876:
    goto v_1887;
v_1883:
    goto v_1893;
v_1889:
    v_1902 = stack[-1];
    v_1902 = qcdr(v_1902);
    goto v_1890;
v_1891:
    v_1901 = qcar(v_1901);
    goto v_1892;
v_1893:
    goto v_1889;
v_1890:
    goto v_1891;
v_1892:
    fn = elt(env, 1); // pv_applp
    v_1902 = (*qfn2(fn))(fn, v_1902, v_1901);
    env = stack[-3];
    goto v_1884;
v_1885:
    v_1901 = stack[0];
    goto v_1886;
v_1887:
    goto v_1883;
v_1884:
    goto v_1885;
v_1886:
    fn = elt(env, 2); // sieve_pv
    v_1901 = (*qfn2(fn))(fn, v_1902, v_1901);
    env = stack[-3];
    fn = elt(env, 3); // pv_renorm
    v_1902 = (*qfn1(fn))(fn, v_1901);
    env = stack[-3];
    goto v_1877;
v_1878:
    v_1901 = stack[0];
    goto v_1879;
v_1880:
    goto v_1876;
v_1877:
    goto v_1878;
v_1879:
    fn = elt(env, 4); // insert_pv
    v_1901 = (*qfn2(fn))(fn, v_1902, v_1901);
    env = stack[-3];
    stack[0] = v_1901;
    v_1901 = stack[-2];
    goto v_1864;
    v_1901 = nil;
v_1863:
    return onevalue(v_1901);
}



// Code for clear!-column

static LispObject CC_clearKcolumn(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2225, v_2226, v_2227, v_2228, v_2229, v_2230, v_2231, v_2232, v_2233, v_2234;
    LispObject v_1861, v_1860, v_1859, v_1858;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "clear-column");
    va_start(aa, nargs);
    v_1858 = va_arg(aa, LispObject);
    v_1859 = va_arg(aa, LispObject);
    v_1860 = va_arg(aa, LispObject);
    v_1861 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_1861,v_1860,v_1859,v_1858);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_1858,v_1859,v_1860,v_1861);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_1861;
    stack[-1] = v_1860;
    v_2225 = v_1859;
    stack[-2] = v_1858;
// end of prologue
// Binding null!-space!-basis
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = v_2225; // null!-space!-basis
    v_2225 = (LispObject)0+TAG_FIXNUM; // 0
v_1871:
    goto v_1885;
v_1881:
    goto v_1890;
v_1886:
    goto v_1895;
v_1891:
    v_2227 = stack[-1];
    goto v_1892;
v_1893:
    v_2226 = v_2225;
    goto v_1894;
v_1895:
    goto v_1891;
v_1892:
    goto v_1893;
v_1894:
    v_2227 = *(LispObject *)((char *)v_2227 + (CELL-TAG_VECTOR) + (((intptr_t)v_2226-TAG_FIXNUM)/(16/CELL)));
    goto v_1887;
v_1888:
    v_2226 = stack[-2];
    goto v_1889;
v_1890:
    goto v_1886;
v_1887:
    goto v_1888;
v_1889:
    v_2227 = *(LispObject *)((char *)v_2227 + (CELL-TAG_VECTOR) + (((intptr_t)v_2226-TAG_FIXNUM)/(16/CELL)));
    goto v_1882;
v_1883:
    v_2226 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1884;
v_1885:
    goto v_1881;
v_1882:
    goto v_1883;
v_1884:
    if (v_2227 == v_2226) goto v_1879;
    else goto v_1880;
v_1879:
    v_2226 = lisp_true;
    goto v_1878;
v_1880:
    goto v_1913;
v_1909:
    v_2227 = v_2225;
    goto v_1910;
v_1911:
    v_2226 = stack[-2];
    goto v_1912;
v_1913:
    goto v_1909;
v_1910:
    goto v_1911;
v_1912:
    if (((intptr_t)(v_2227)) < ((intptr_t)(v_2226))) goto v_1908;
    v_2226 = nil;
    goto v_1906;
v_1908:
    goto v_1923;
v_1919:
    goto v_1928;
v_1924:
    goto v_1933;
v_1929:
    v_2227 = stack[-1];
    goto v_1930;
v_1931:
    v_2226 = v_2225;
    goto v_1932;
v_1933:
    goto v_1929;
v_1930:
    goto v_1931;
v_1932:
    v_2227 = *(LispObject *)((char *)v_2227 + (CELL-TAG_VECTOR) + (((intptr_t)v_2226-TAG_FIXNUM)/(16/CELL)));
    goto v_1925;
v_1926:
    v_2226 = v_2225;
    goto v_1927;
v_1928:
    goto v_1924;
v_1925:
    goto v_1926;
v_1927:
    v_2227 = *(LispObject *)((char *)v_2227 + (CELL-TAG_VECTOR) + (((intptr_t)v_2226-TAG_FIXNUM)/(16/CELL)));
    goto v_1920;
v_1921:
    v_2226 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1922;
v_1923:
    goto v_1919;
v_1920:
    goto v_1921;
v_1922:
    v_2226 = (v_2227 == v_2226 ? lisp_true : nil);
    v_2226 = (v_2226 == nil ? lisp_true : nil);
    goto v_1906;
    v_2226 = nil;
v_1906:
    goto v_1878;
    v_2226 = nil;
v_1878:
    if (v_2226 == nil) goto v_1876;
    goto v_1950;
v_1946:
    v_2227 = (LispObject)((intptr_t)(v_2225) + 0x10);
    v_2225 = v_2227;
    goto v_1947;
v_1948:
    v_2226 = stack[0];
    goto v_1949;
v_1950:
    goto v_1946;
v_1947:
    goto v_1948;
v_1949:
    if (((intptr_t)(v_2227)) > ((intptr_t)(v_2226))) goto v_1944;
    else goto v_1945;
v_1944:
    goto v_1959;
v_1955:
    v_2226 = stack[-2];
    goto v_1956;
v_1957:
    v_2225 = qvalue(elt(env, 1)); // null!-space!-basis
    goto v_1958;
v_1959:
    goto v_1955;
v_1956:
    goto v_1957;
v_1958:
    v_2225 = cons(v_2226, v_2225);
    goto v_1870;
v_1945:
    goto v_1871;
    goto v_1874;
v_1876:
v_1874:
    goto v_1968;
v_1964:
    v_2227 = stack[-1];
    goto v_1965;
v_1966:
    v_2226 = v_2225;
    goto v_1967;
v_1968:
    goto v_1964;
v_1965:
    goto v_1966;
v_1967:
    v_2226 = *(LispObject *)((char *)v_2227 + (CELL-TAG_VECTOR) + (((intptr_t)v_2226-TAG_FIXNUM)/(16/CELL)));
    v_2234 = v_2226;
    goto v_1978;
v_1972:
    v_2228 = stack[-1];
    goto v_1973;
v_1974:
    v_2227 = v_2225;
    goto v_1975;
v_1976:
    goto v_1985;
v_1981:
    v_2226 = stack[-1];
    goto v_1982;
v_1983:
    v_2225 = stack[-2];
    goto v_1984;
v_1985:
    goto v_1981;
v_1982:
    goto v_1983;
v_1984:
    v_2225 = *(LispObject *)((char *)v_2226 + (CELL-TAG_VECTOR) + (((intptr_t)v_2225-TAG_FIXNUM)/(16/CELL)));
    goto v_1977;
v_1978:
    goto v_1972;
v_1973:
    goto v_1974;
v_1975:
    goto v_1976;
v_1977:
    *(LispObject *)((char *)v_2228 + (CELL-TAG_VECTOR) + (((intptr_t)v_2227-TAG_FIXNUM)/(16/CELL))) = v_2225;
    goto v_1995;
v_1989:
    v_2226 = stack[-1];
    goto v_1990;
v_1991:
    v_2225 = stack[-2];
    goto v_1992;
v_1993:
    v_2227 = v_2234;
    goto v_1994;
v_1995:
    goto v_1989;
v_1990:
    goto v_1991;
v_1992:
    goto v_1993;
v_1994:
    *(LispObject *)((char *)v_2226 + (CELL-TAG_VECTOR) + (((intptr_t)v_2225-TAG_FIXNUM)/(16/CELL))) = v_2227;
    goto v_2004;
v_2000:
    goto v_2009;
v_2005:
    v_2226 = stack[-1];
    goto v_2006;
v_2007:
    v_2225 = stack[-2];
    goto v_2008;
v_2009:
    goto v_2005;
v_2006:
    goto v_2007;
v_2008:
    v_2226 = *(LispObject *)((char *)v_2226 + (CELL-TAG_VECTOR) + (((intptr_t)v_2225-TAG_FIXNUM)/(16/CELL)));
    goto v_2001;
v_2002:
    v_2225 = stack[-2];
    goto v_2003;
v_2004:
    goto v_2000;
v_2001:
    goto v_2002;
v_2003:
    v_2225 = *(LispObject *)((char *)v_2226 + (CELL-TAG_VECTOR) + (((intptr_t)v_2225-TAG_FIXNUM)/(16/CELL)));
    v_2225 = Lmodular_reciprocal(nil, v_2225);
    env = stack[-4];
    {   intptr_t w = int_of_fixnum(v_2225);
        if (w != 0) w = current_modulus - w;
        v_2225 = fixnum_of_int(w);
    }
    v_2234 = v_2225;
    v_2225 = (LispObject)0+TAG_FIXNUM; // 0
    v_2233 = v_2225;
v_2019:
    goto v_2029;
v_2025:
    v_2226 = stack[0];
    goto v_2026;
v_2027:
    v_2225 = v_2233;
    goto v_2028;
v_2029:
    goto v_2025;
v_2026:
    goto v_2027;
v_2028:
    v_2225 = (LispObject)(intptr_t)((intptr_t)v_2226 - (intptr_t)v_2225 + TAG_FIXNUM);
    v_2225 = ((intptr_t)(v_2225) < 0 ? lisp_true : nil);
    if (v_2225 == nil) goto v_2024;
    goto v_2018;
v_2024:
    goto v_2043;
v_2039:
    v_2226 = v_2233;
    goto v_2040;
v_2041:
    v_2225 = stack[-2];
    goto v_2042;
v_2043:
    goto v_2039;
v_2040:
    goto v_2041;
v_2042:
    if (equal(v_2226, v_2225)) goto v_2038;
    goto v_2053;
v_2049:
    goto v_2058;
v_2054:
    v_2226 = stack[-1];
    goto v_2055;
v_2056:
    v_2225 = v_2233;
    goto v_2057;
v_2058:
    goto v_2054;
v_2055:
    goto v_2056;
v_2057:
    v_2226 = *(LispObject *)((char *)v_2226 + (CELL-TAG_VECTOR) + (((intptr_t)v_2225-TAG_FIXNUM)/(16/CELL)));
    goto v_2050;
v_2051:
    v_2225 = stack[-2];
    goto v_2052;
v_2053:
    goto v_2049;
v_2050:
    goto v_2051;
v_2052:
    v_2225 = *(LispObject *)((char *)v_2226 + (CELL-TAG_VECTOR) + (((intptr_t)v_2225-TAG_FIXNUM)/(16/CELL)));
    v_2232 = v_2225;
    goto v_2072;
v_2068:
    v_2226 = v_2232;
    goto v_2069;
v_2070:
    v_2225 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2071;
v_2072:
    goto v_2068;
v_2069:
    goto v_2070;
v_2071:
    if (v_2226 == v_2225) goto v_2067;
    goto v_2080;
v_2076:
    v_2226 = v_2232;
    goto v_2077;
v_2078:
    v_2225 = v_2234;
    goto v_2079;
v_2080:
    goto v_2076;
v_2077:
    goto v_2078;
v_2079:
    v_2225 = Lmodular_times(nil, v_2226, v_2225);
    env = stack[-4];
    v_2232 = v_2225;
    v_2225 = stack[-2];
    v_2231 = v_2225;
v_2086:
    goto v_2096;
v_2092:
    v_2226 = stack[0];
    goto v_2093;
v_2094:
    v_2225 = v_2231;
    goto v_2095;
v_2096:
    goto v_2092;
v_2093:
    goto v_2094;
v_2095:
    v_2225 = (LispObject)(intptr_t)((intptr_t)v_2226 - (intptr_t)v_2225 + TAG_FIXNUM);
    v_2225 = ((intptr_t)(v_2225) < 0 ? lisp_true : nil);
    if (v_2225 == nil) goto v_2091;
    goto v_2085;
v_2091:
    goto v_2108;
v_2102:
    goto v_2113;
v_2109:
    v_2226 = stack[-1];
    goto v_2110;
v_2111:
    v_2225 = v_2233;
    goto v_2112;
v_2113:
    goto v_2109;
v_2110:
    goto v_2111;
v_2112:
    v_2230 = *(LispObject *)((char *)v_2226 + (CELL-TAG_VECTOR) + (((intptr_t)v_2225-TAG_FIXNUM)/(16/CELL)));
    goto v_2103;
v_2104:
    v_2229 = v_2231;
    goto v_2105;
v_2106:
    goto v_2122;
v_2118:
    goto v_2127;
v_2123:
    goto v_2132;
v_2128:
    v_2226 = stack[-1];
    goto v_2129;
v_2130:
    v_2225 = v_2233;
    goto v_2131;
v_2132:
    goto v_2128;
v_2129:
    goto v_2130;
v_2131:
    v_2226 = *(LispObject *)((char *)v_2226 + (CELL-TAG_VECTOR) + (((intptr_t)v_2225-TAG_FIXNUM)/(16/CELL)));
    goto v_2124;
v_2125:
    v_2225 = v_2231;
    goto v_2126;
v_2127:
    goto v_2123;
v_2124:
    goto v_2125;
v_2126:
    v_2228 = *(LispObject *)((char *)v_2226 + (CELL-TAG_VECTOR) + (((intptr_t)v_2225-TAG_FIXNUM)/(16/CELL)));
    goto v_2119;
v_2120:
    goto v_2143;
v_2139:
    v_2227 = v_2232;
    goto v_2140;
v_2141:
    goto v_2149;
v_2145:
    goto v_2154;
v_2150:
    v_2226 = stack[-1];
    goto v_2151;
v_2152:
    v_2225 = stack[-2];
    goto v_2153;
v_2154:
    goto v_2150;
v_2151:
    goto v_2152;
v_2153:
    v_2226 = *(LispObject *)((char *)v_2226 + (CELL-TAG_VECTOR) + (((intptr_t)v_2225-TAG_FIXNUM)/(16/CELL)));
    goto v_2146;
v_2147:
    v_2225 = v_2231;
    goto v_2148;
v_2149:
    goto v_2145;
v_2146:
    goto v_2147;
v_2148:
    v_2225 = *(LispObject *)((char *)v_2226 + (CELL-TAG_VECTOR) + (((intptr_t)v_2225-TAG_FIXNUM)/(16/CELL)));
    goto v_2142;
v_2143:
    goto v_2139;
v_2140:
    goto v_2141;
v_2142:
    v_2225 = Lmodular_times(nil, v_2227, v_2225);
    env = stack[-4];
    goto v_2121;
v_2122:
    goto v_2118;
v_2119:
    goto v_2120;
v_2121:
    {   intptr_t w = int_of_fixnum(v_2228) + int_of_fixnum(v_2225);
        if (w >= current_modulus) w -= current_modulus;
        v_2225 = fixnum_of_int(w);
    }
    goto v_2107;
v_2108:
    goto v_2102;
v_2103:
    goto v_2104;
v_2105:
    goto v_2106;
v_2107:
    *(LispObject *)((char *)v_2230 + (CELL-TAG_VECTOR) + (((intptr_t)v_2229-TAG_FIXNUM)/(16/CELL))) = v_2225;
    v_2225 = v_2231;
    v_2225 = (LispObject)((intptr_t)(v_2225) + 0x10);
    v_2231 = v_2225;
    goto v_2086;
v_2085:
    goto v_2065;
v_2067:
v_2065:
    goto v_2036;
v_2038:
v_2036:
    v_2225 = v_2233;
    v_2225 = (LispObject)((intptr_t)(v_2225) + 0x10);
    v_2233 = v_2225;
    goto v_2019;
v_2018:
    v_2225 = stack[-2];
    v_2229 = v_2225;
v_2168:
    goto v_2178;
v_2174:
    v_2226 = stack[0];
    goto v_2175;
v_2176:
    v_2225 = v_2229;
    goto v_2177;
v_2178:
    goto v_2174;
v_2175:
    goto v_2176;
v_2177:
    v_2225 = (LispObject)(intptr_t)((intptr_t)v_2226 - (intptr_t)v_2225 + TAG_FIXNUM);
    v_2225 = ((intptr_t)(v_2225) < 0 ? lisp_true : nil);
    if (v_2225 == nil) goto v_2173;
    goto v_2167;
v_2173:
    goto v_2190;
v_2184:
    goto v_2195;
v_2191:
    v_2226 = stack[-1];
    goto v_2192;
v_2193:
    v_2225 = stack[-2];
    goto v_2194;
v_2195:
    goto v_2191;
v_2192:
    goto v_2193;
v_2194:
    v_2228 = *(LispObject *)((char *)v_2226 + (CELL-TAG_VECTOR) + (((intptr_t)v_2225-TAG_FIXNUM)/(16/CELL)));
    goto v_2185;
v_2186:
    v_2227 = v_2229;
    goto v_2187;
v_2188:
    goto v_2205;
v_2201:
    goto v_2210;
v_2206:
    goto v_2215;
v_2211:
    v_2226 = stack[-1];
    goto v_2212;
v_2213:
    v_2225 = stack[-2];
    goto v_2214;
v_2215:
    goto v_2211;
v_2212:
    goto v_2213;
v_2214:
    v_2226 = *(LispObject *)((char *)v_2226 + (CELL-TAG_VECTOR) + (((intptr_t)v_2225-TAG_FIXNUM)/(16/CELL)));
    goto v_2207;
v_2208:
    v_2225 = v_2229;
    goto v_2209;
v_2210:
    goto v_2206;
v_2207:
    goto v_2208;
v_2209:
    v_2226 = *(LispObject *)((char *)v_2226 + (CELL-TAG_VECTOR) + (((intptr_t)v_2225-TAG_FIXNUM)/(16/CELL)));
    goto v_2202;
v_2203:
    v_2225 = v_2234;
    goto v_2204;
v_2205:
    goto v_2201;
v_2202:
    goto v_2203;
v_2204:
    v_2225 = Lmodular_times(nil, v_2226, v_2225);
    env = stack[-4];
    goto v_2189;
v_2190:
    goto v_2184;
v_2185:
    goto v_2186;
v_2187:
    goto v_2188;
v_2189:
    *(LispObject *)((char *)v_2228 + (CELL-TAG_VECTOR) + (((intptr_t)v_2227-TAG_FIXNUM)/(16/CELL))) = v_2225;
    v_2225 = v_2229;
    v_2225 = (LispObject)((intptr_t)(v_2225) + 0x10);
    v_2229 = v_2225;
    goto v_2168;
v_2167:
    v_2225 = qvalue(elt(env, 1)); // null!-space!-basis
v_1870:
    ;}  // end of a binding scope
    return onevalue(v_2225);
}



// Code for xread

static LispObject CC_xread(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1889, v_1890;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_1857;
// end of prologue
v_1863:
    fn = elt(env, 4); // scan
    v_1889 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_1889 = qvalue(elt(env, 1)); // !*eoldelimp
    if (v_1889 == nil) goto v_1872;
    else goto v_1873;
v_1872:
    v_1889 = nil;
    goto v_1871;
v_1873:
    goto v_1882;
v_1878:
    v_1890 = qvalue(elt(env, 2)); // cursym!*
    goto v_1879;
v_1880:
    v_1889 = elt(env, 3); // !*semicol!*
    goto v_1881;
v_1882:
    goto v_1878;
v_1879:
    goto v_1880;
v_1881:
    v_1889 = (v_1890 == v_1889 ? lisp_true : nil);
    goto v_1871;
    v_1889 = nil;
v_1871:
    if (v_1889 == nil) goto v_1867;
    else goto v_1868;
v_1867:
    goto v_1862;
v_1868:
    goto v_1863;
v_1862:
    v_1889 = stack[0];
    {
        fn = elt(env, 5); // xread1
        return (*qfn1(fn))(fn, v_1889);
    }
    return onevalue(v_1889);
}



// Code for sfto_gcdf!*

static LispObject CC_sfto_gcdfH(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1870, v_1871, v_1872;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1857,v_1858);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_1871 = v_1858;
    v_1872 = v_1857;
// end of prologue
    v_1870 = lisp_true;
// Binding !*gcd
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_1870; // !*gcd
    goto v_1867;
v_1863:
    v_1870 = v_1872;
    goto v_1864;
v_1865:
    goto v_1866;
v_1867:
    goto v_1863;
v_1864:
    goto v_1865;
v_1866:
    fn = elt(env, 2); // sfto_gcdf
    v_1870 = (*qfn2(fn))(fn, v_1870, v_1871);
    ;}  // end of a binding scope
    return onevalue(v_1870);
}



// Code for removev

static LispObject CC_removev(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1905, v_1906, v_1907, v_1908;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1857,v_1858);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_1908 = v_1858;
    v_1907 = v_1857;
// end of prologue
v_1862:
    v_1905 = v_1907;
    if (v_1905 == nil) goto v_1865;
    else goto v_1866;
v_1865:
    goto v_1876;
v_1870:
    v_1906 = elt(env, 1); // "Vertex"
    goto v_1871;
v_1872:
    v_1907 = v_1908;
    goto v_1873;
v_1874:
    v_1905 = elt(env, 2); // "is absent."
    goto v_1875;
v_1876:
    goto v_1870;
v_1871:
    goto v_1872;
v_1873:
    goto v_1874;
v_1875:
    v_1905 = list3(v_1906, v_1907, v_1905);
    env = stack[0];
    {
        fn = elt(env, 3); // cerror
        return (*qfn1(fn))(fn, v_1905);
    }
v_1866:
    goto v_1886;
v_1882:
    v_1905 = v_1907;
    v_1905 = qcdr(v_1905);
    v_1906 = qcar(v_1905);
    goto v_1883;
v_1884:
    v_1905 = v_1908;
    goto v_1885;
v_1886:
    goto v_1882;
v_1883:
    goto v_1884;
v_1885:
    if (v_1906 == v_1905) goto v_1880;
    else goto v_1881;
v_1880:
    goto v_1896;
v_1892:
    v_1905 = v_1907;
    goto v_1893;
v_1894:
    v_1906 = v_1907;
    v_1906 = qcdr(v_1906);
    v_1906 = qcdr(v_1906);
    goto v_1895;
v_1896:
    goto v_1892;
v_1893:
    goto v_1894;
v_1895:
        return Lrplacd(nil, v_1905, v_1906);
v_1881:
    v_1905 = v_1907;
    v_1905 = qcdr(v_1905);
    v_1907 = v_1905;
    goto v_1862;
    v_1905 = nil;
    return onevalue(v_1905);
}



// Code for qqe_prepat

static LispObject CC_qqe_prepat(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1860;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1860 = v_1857;
// end of prologue
    return onevalue(v_1860);
}



// Code for pasf_susipost

static LispObject CC_pasf_susipost(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1861, v_1862;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1861 = v_1858;
    v_1862 = v_1857;
// end of prologue
    v_1861 = v_1862;
    return onevalue(v_1861);
}



// Code for omobj

static LispObject CC_omobj(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_1885, v_1886;
    LispObject fn;
    argcheck(nargs, 0, "omobj");
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
    goto v_1870;
v_1866:
    v_1885 = qvalue(elt(env, 1)); // char
    fn = elt(env, 3); // compress!*
    v_1886 = (*qfn1(fn))(fn, v_1885);
    env = stack[0];
    goto v_1867;
v_1868:
    v_1885 = qvalue(elt(env, 2)); // omfuncs!*
    goto v_1869;
v_1870:
    goto v_1866;
v_1867:
    goto v_1868;
v_1869:
    v_1885 = Lassoc(nil, v_1886, v_1885);
    v_1886 = v_1885;
    if (v_1885 == nil) goto v_1865;
    goto v_1880;
v_1876:
    v_1885 = v_1886;
    v_1885 = qcdr(v_1885);
    v_1886 = qcar(v_1885);
    goto v_1877;
v_1878:
    v_1885 = nil;
    goto v_1879;
v_1880:
    goto v_1876;
v_1877:
    goto v_1878;
v_1879:
    {
        fn = elt(env, 4); // apply
        return (*qfn2(fn))(fn, v_1886, v_1885);
    }
v_1865:
    v_1885 = nil;
    return onevalue(v_1885);
}



// Code for mk!*sq

static LispObject CC_mkHsq(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1936, v_1937;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_1936 = v_1857;
// end of prologue
    fn = elt(env, 5); // expchk
    v_1936 = (*qfn1(fn))(fn, v_1936);
    env = stack[-2];
    stack[0] = v_1936;
    v_1936 = stack[0];
    v_1936 = qcar(v_1936);
    if (v_1936 == nil) goto v_1864;
    else goto v_1865;
v_1864:
    v_1936 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1863;
v_1865:
    v_1936 = stack[0];
    v_1936 = qcar(v_1936);
    if (!consp(v_1936)) goto v_1873;
    else goto v_1874;
v_1873:
    goto v_1881;
v_1877:
    v_1936 = stack[0];
    v_1937 = qcdr(v_1936);
    goto v_1878;
v_1879:
    v_1936 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1880;
v_1881:
    goto v_1877;
v_1878:
    goto v_1879;
v_1880:
    v_1936 = (v_1937 == v_1936 ? lisp_true : nil);
    goto v_1872;
v_1874:
    v_1936 = nil;
    goto v_1872;
    v_1936 = nil;
v_1872:
    if (v_1936 == nil) goto v_1870;
    v_1936 = stack[0];
    v_1936 = qcar(v_1936);
    goto v_1863;
v_1870:
    v_1936 = stack[0];
    fn = elt(env, 6); // kernp
    v_1936 = (*qfn1(fn))(fn, v_1936);
    env = stack[-2];
    if (v_1936 == nil) goto v_1892;
    goto v_1902;
v_1898:
    v_1936 = stack[0];
    v_1936 = qcar(v_1936);
    v_1936 = qcar(v_1936);
    v_1936 = qcar(v_1936);
    v_1937 = qcar(v_1936);
    goto v_1899;
v_1900:
    v_1936 = elt(env, 1); // list
    goto v_1901;
v_1902:
    goto v_1898;
v_1899:
    goto v_1900;
v_1901:
    if (!consp(v_1937)) goto v_1892;
    v_1937 = qcar(v_1937);
    if (v_1937 == v_1936) goto v_1896;
    else goto v_1892;
v_1896:
    v_1936 = stack[0];
    v_1936 = qcar(v_1936);
    v_1936 = qcar(v_1936);
    v_1936 = qcar(v_1936);
    v_1936 = qcar(v_1936);
    goto v_1863;
v_1892:
    goto v_1923;
v_1917:
    stack[-1] = elt(env, 2); // !*sq
    goto v_1918;
v_1919:
    goto v_1920;
v_1921:
    v_1936 = qvalue(elt(env, 3)); // !*resubs
    if (v_1936 == nil) goto v_1929;
    v_1936 = qvalue(elt(env, 4)); // !*sqvar!*
    goto v_1927;
v_1929:
    v_1936 = nil;
    v_1936 = ncons(v_1936);
    goto v_1927;
    v_1936 = nil;
v_1927:
    goto v_1922;
v_1923:
    goto v_1917;
v_1918:
    goto v_1919;
v_1920:
    goto v_1921;
v_1922:
    {
        LispObject v_1940 = stack[-1];
        LispObject v_1941 = stack[0];
        return list2star(v_1940, v_1941, v_1936);
    }
    v_1936 = nil;
v_1863:
    return onevalue(v_1936);
}



// Code for comm_kernels

static LispObject CC_comm_kernels(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1867, v_1868;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1867 = v_1857;
// end of prologue
    goto v_1864;
v_1860:
    v_1868 = v_1867;
    goto v_1861;
v_1862:
    v_1867 = nil;
    goto v_1863;
v_1864:
    goto v_1860;
v_1861:
    goto v_1862;
v_1863:
    {
        fn = elt(env, 1); // comm_kernels1
        return (*qfn2(fn))(fn, v_1868, v_1867);
    }
}



// Code for !:times

static LispObject CC_Ttimes(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1908, v_1909, v_1910;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1909 = v_1858;
    v_1910 = v_1857;
// end of prologue
    v_1908 = v_1910;
    if (v_1908 == nil) goto v_1866;
    else goto v_1867;
v_1866:
    v_1908 = lisp_true;
    goto v_1865;
v_1867:
    v_1908 = v_1909;
    v_1908 = (v_1908 == nil ? lisp_true : nil);
    goto v_1865;
    v_1908 = nil;
v_1865:
    if (v_1908 == nil) goto v_1863;
    v_1908 = nil;
    goto v_1861;
v_1863:
    v_1908 = v_1910;
    if (!consp(v_1908)) goto v_1879;
    else goto v_1880;
v_1879:
    v_1908 = v_1909;
    v_1908 = (consp(v_1908) ? nil : lisp_true);
    goto v_1878;
v_1880:
    v_1908 = nil;
    goto v_1878;
    v_1908 = nil;
v_1878:
    if (v_1908 == nil) goto v_1876;
    goto v_1892;
v_1888:
    v_1908 = v_1910;
    goto v_1889;
v_1890:
    goto v_1891;
v_1892:
    goto v_1888;
v_1889:
    goto v_1890;
v_1891:
    return times2(v_1908, v_1909);
v_1876:
    goto v_1904;
v_1898:
    goto v_1899;
v_1900:
    goto v_1901;
v_1902:
    v_1908 = elt(env, 1); // times
    goto v_1903;
v_1904:
    goto v_1898;
v_1899:
    goto v_1900;
v_1901:
    goto v_1902;
v_1903:
    {
        fn = elt(env, 2); // dcombine
        return (*qfnn(fn))(fn, 3, v_1910, v_1909, v_1908);
    }
    v_1908 = nil;
v_1861:
    return onevalue(v_1908);
}



// Code for areallindices

static LispObject CC_areallindices(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1881;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_1857;
// end of prologue
v_1856:
    v_1881 = stack[0];
    v_1881 = qcar(v_1881);
    fn = elt(env, 1); // isanindex
    v_1881 = (*qfn1(fn))(fn, v_1881);
    env = stack[-1];
    if (v_1881 == nil) goto v_1861;
    else goto v_1862;
v_1861:
    v_1881 = nil;
    goto v_1860;
v_1862:
    v_1881 = stack[0];
    v_1881 = qcdr(v_1881);
    if (v_1881 == nil) goto v_1871;
    else goto v_1872;
v_1871:
    v_1881 = lisp_true;
    goto v_1870;
v_1872:
    v_1881 = stack[0];
    v_1881 = qcdr(v_1881);
    stack[0] = v_1881;
    goto v_1856;
    v_1881 = nil;
v_1870:
    goto v_1860;
    v_1881 = nil;
v_1860:
    return onevalue(v_1881);
}



// Code for !*ssave

static LispObject CC_Hssave(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1952, v_1953, v_1954;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1857,v_1858);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_1858;
    stack[-3] = v_1857;
// end of prologue
    v_1952 = qvalue(elt(env, 1)); // !*uncached
    if (v_1952 == nil) goto v_1864;
    else goto v_1865;
v_1864:
    goto v_1872;
v_1868:
    stack[-4] = qvalue(elt(env, 2)); // alglist!*
    goto v_1869;
v_1870:
    goto v_1879;
v_1875:
    v_1953 = qvalue(elt(env, 3)); // !*sub2
    goto v_1876;
v_1877:
    v_1952 = stack[-3];
    goto v_1878;
v_1879:
    goto v_1875;
v_1876:
    goto v_1877;
v_1878:
    v_1953 = cons(v_1953, v_1952);
    env = stack[-5];
    v_1952 = qvalue(elt(env, 2)); // alglist!*
    v_1952 = qcar(v_1952);
    stack[-1] = v_1953;
    stack[0] = v_1952;
    v_1952 = stack[0];
    if (v_1952 == nil) goto v_1892;
    else goto v_1893;
v_1892:
    v_1952 = lisp_true;
    goto v_1891;
v_1893:
    goto v_1903;
v_1899:
    v_1953 = qvalue(elt(env, 4)); // alglist_count!*
    goto v_1900;
v_1901:
    v_1952 = qvalue(elt(env, 5)); // alglist_limit!*
    goto v_1902;
v_1903:
    goto v_1899;
v_1900:
    goto v_1901;
v_1902:
    v_1952 = (LispObject)greaterp2(v_1953, v_1952);
    v_1952 = v_1952 ? lisp_true : nil;
    env = stack[-5];
    goto v_1891;
    v_1952 = nil;
v_1891:
    if (v_1952 == nil) goto v_1889;
    v_1952 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 4)) = v_1952; // alglist_count!*
    goto v_1917;
v_1911:
    v_1954 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_1912;
v_1913:
    v_1953 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_1914;
v_1915:
    v_1952 = elt(env, 6); // 2.0
    goto v_1916;
v_1917:
    goto v_1911;
v_1912:
    goto v_1913;
v_1914:
    goto v_1915;
v_1916:
    fn = elt(env, 8); // mkhash
    v_1952 = (*qfnn(fn))(fn, 3, v_1954, v_1953, v_1952);
    env = stack[-5];
    stack[0] = v_1952;
    goto v_1928;
v_1922:
    v_1954 = stack[-2];
    goto v_1923;
v_1924:
    v_1953 = stack[0];
    goto v_1925;
v_1926:
    v_1952 = stack[-1];
    goto v_1927;
v_1928:
    goto v_1922;
v_1923:
    goto v_1924;
v_1925:
    goto v_1926;
v_1927:
    fn = elt(env, 9); // puthash
    v_1952 = (*qfnn(fn))(fn, 3, v_1954, v_1953, v_1952);
    env = stack[-5];
    v_1952 = stack[0];
    goto v_1887;
v_1889:
    goto v_1942;
v_1936:
    v_1954 = stack[-2];
    goto v_1937;
v_1938:
    v_1953 = stack[0];
    goto v_1939;
v_1940:
    v_1952 = stack[-1];
    goto v_1941;
v_1942:
    goto v_1936;
v_1937:
    goto v_1938;
v_1939:
    goto v_1940;
v_1941:
    fn = elt(env, 9); // puthash
    v_1952 = (*qfnn(fn))(fn, 3, v_1954, v_1953, v_1952);
    env = stack[-5];
    v_1952 = qvalue(elt(env, 4)); // alglist_count!*
    v_1952 = add1(v_1952);
    env = stack[-5];
    qvalue(elt(env, 4)) = v_1952; // alglist_count!*
    v_1952 = stack[0];
    goto v_1887;
    v_1952 = nil;
v_1887:
    goto v_1871;
v_1872:
    goto v_1868;
v_1869:
    goto v_1870;
v_1871:
    v_1952 = Lrplaca(nil, stack[-4], v_1952);
    env = stack[-5];
    goto v_1863;
v_1865:
v_1863:
    v_1952 = qvalue(elt(env, 7)); // simpcount!*
    v_1952 = sub1(v_1952);
    env = stack[-5];
    qvalue(elt(env, 7)) = v_1952; // simpcount!*
    v_1952 = stack[-3];
    return onevalue(v_1952);
}



// Code for red!-weight

static LispObject CC_redKweight(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1876, v_1877;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1857,v_1858);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_1858;
    stack[-1] = v_1857;
// end of prologue
    goto v_1865;
v_1861:
    v_1876 = stack[-1];
    fn = elt(env, 1); // nonzero!-length
    stack[-2] = (*qfn1(fn))(fn, v_1876);
    env = stack[-3];
    goto v_1862;
v_1863:
    goto v_1873;
v_1869:
    v_1877 = stack[-1];
    goto v_1870;
v_1871:
    v_1876 = stack[0];
    goto v_1872;
v_1873:
    goto v_1869;
v_1870:
    goto v_1871;
v_1872:
    fn = elt(env, 2); // red!-weight1
    v_1876 = (*qfn2(fn))(fn, v_1877, v_1876);
    goto v_1864;
v_1865:
    goto v_1861;
v_1862:
    goto v_1863;
v_1864:
    {
        LispObject v_1881 = stack[-2];
        return cons(v_1881, v_1876);
    }
}



// Code for bc!=simp

static LispObject CC_bcMsimp(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1958, v_1959;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_1857;
// end of prologue
    v_1958 = elt(env, 1); // cali
    if (!symbolp(v_1958)) v_1958 = nil;
    else { v_1958 = qfastgets(v_1958);
           if (v_1958 != nil) { v_1958 = elt(v_1958, 20); // rules
#ifdef RECORD_GET
             if (v_1958 != SPID_NOPROP)
                record_get(elt(fastget_names, 20), 1);
             else record_get(elt(fastget_names, 20), 0),
                v_1958 = nil; }
           else record_get(elt(fastget_names, 20), 0); }
#else
             if (v_1958 == SPID_NOPROP) v_1958 = nil; }}
#endif
    stack[-4] = v_1958;
    v_1958 = stack[-4];
    if (v_1958 == nil) goto v_1865;
    v_1958 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_1958;
    v_1958 = stack[-4];
    stack[-2] = v_1958;
v_1877:
    v_1958 = stack[-2];
    if (v_1958 == nil) goto v_1880;
    goto v_1890;
v_1886:
    v_1959 = stack[0];
    goto v_1887;
v_1888:
    v_1958 = (LispObject)16000+TAG_FIXNUM; // 1000
    goto v_1889;
v_1890:
    goto v_1886;
v_1887:
    goto v_1888;
v_1889:
    v_1958 = (LispObject)lessp2(v_1959, v_1958);
    v_1958 = v_1958 ? lisp_true : nil;
    env = stack[-5];
    if (v_1958 == nil) goto v_1880;
    goto v_1881;
v_1880:
    goto v_1876;
v_1881:
    goto v_1899;
v_1895:
    v_1959 = stack[-3];
    goto v_1896;
v_1897:
    v_1958 = stack[-2];
    v_1958 = qcar(v_1958);
    v_1958 = qcar(v_1958);
    goto v_1898;
v_1899:
    goto v_1895;
v_1896:
    goto v_1897;
v_1898:
    fn = elt(env, 3); // qremf
    v_1958 = (*qfn2(fn))(fn, v_1959, v_1958);
    env = stack[-5];
    stack[-1] = v_1958;
    v_1958 = stack[-1];
    v_1958 = qcar(v_1958);
    if (v_1958 == nil) goto v_1906;
    else goto v_1907;
v_1906:
    v_1958 = stack[-2];
    v_1958 = qcdr(v_1958);
    stack[-2] = v_1958;
    goto v_1905;
v_1907:
    goto v_1919;
v_1915:
    goto v_1925;
v_1921:
    v_1958 = stack[-1];
    v_1959 = qcar(v_1958);
    goto v_1922;
v_1923:
    v_1958 = stack[-2];
    v_1958 = qcar(v_1958);
    v_1958 = qcdr(v_1958);
    goto v_1924;
v_1925:
    goto v_1921;
v_1922:
    goto v_1923;
v_1924:
    fn = elt(env, 4); // multf
    v_1959 = (*qfn2(fn))(fn, v_1959, v_1958);
    env = stack[-5];
    goto v_1916;
v_1917:
    v_1958 = stack[-1];
    v_1958 = qcdr(v_1958);
    goto v_1918;
v_1919:
    goto v_1915;
v_1916:
    goto v_1917;
v_1918:
    fn = elt(env, 5); // addf
    v_1958 = (*qfn2(fn))(fn, v_1959, v_1958);
    env = stack[-5];
    stack[-3] = v_1958;
    v_1958 = stack[0];
    v_1958 = add1(v_1958);
    env = stack[-5];
    stack[0] = v_1958;
    v_1958 = stack[-4];
    stack[-2] = v_1958;
    goto v_1905;
v_1905:
    goto v_1877;
v_1876:
    goto v_1947;
v_1943:
    v_1959 = stack[0];
    goto v_1944;
v_1945:
    v_1958 = (LispObject)16000+TAG_FIXNUM; // 1000
    goto v_1946;
v_1947:
    goto v_1943;
v_1944:
    goto v_1945;
v_1946:
    v_1958 = (LispObject)lessp2(v_1959, v_1958);
    v_1958 = v_1958 ? lisp_true : nil;
    env = stack[-5];
    if (v_1958 == nil) goto v_1941;
    v_1958 = stack[-3];
    goto v_1871;
v_1941:
    v_1958 = elt(env, 2); // "recursion depth of bc!=simp too high"
    fn = elt(env, 6); // rederr
    v_1958 = (*qfn1(fn))(fn, v_1958);
    goto v_1939;
v_1939:
    v_1958 = nil;
v_1871:
    goto v_1863;
v_1865:
    v_1958 = stack[-3];
    goto v_1863;
    v_1958 = nil;
v_1863:
    return onevalue(v_1958);
}



// Code for vecp

static LispObject CC_vecp(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1968, v_1969, v_1970, v_1971;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_1970 = v_1857;
// end of prologue
    v_1968 = v_1970;
    if (v_1968 == nil) goto v_1868;
    else goto v_1869;
v_1868:
    v_1968 = lisp_true;
    goto v_1867;
v_1869:
    v_1968 = v_1970;
    v_1968 = (is_number(v_1968) ? lisp_true : nil);
    goto v_1867;
    v_1968 = nil;
v_1867:
    if (v_1968 == nil) goto v_1865;
    v_1968 = nil;
    goto v_1863;
v_1865:
    v_1968 = v_1970;
    if (!consp(v_1968)) goto v_1877;
    else goto v_1878;
v_1877:
    goto v_1888;
v_1884:
    v_1968 = v_1970;
    if (!symbolp(v_1968)) v_1968 = nil;
    else { v_1968 = qfastgets(v_1968);
           if (v_1968 != nil) { v_1968 = elt(v_1968, 2); // rtype
#ifdef RECORD_GET
             if (v_1968 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_1968 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_1968 == SPID_NOPROP) v_1968 = nil; }}
#endif
    goto v_1885;
v_1886:
    v_1969 = elt(env, 1); // !3vector
    goto v_1887;
v_1888:
    goto v_1884;
v_1885:
    goto v_1886;
v_1887:
    if (v_1968 == v_1969) goto v_1882;
    else goto v_1883;
v_1882:
    v_1968 = lisp_true;
    goto v_1881;
v_1883:
    v_1968 = v_1970;
        return Lthreevectorp(nil, v_1968);
    v_1968 = nil;
v_1881:
    goto v_1863;
v_1878:
    v_1968 = v_1970;
    v_1968 = Lthreevectorp(nil, v_1968);
    env = stack[0];
    if (v_1968 == nil) goto v_1898;
    v_1968 = lisp_true;
    goto v_1863;
v_1898:
    v_1968 = v_1970;
    v_1968 = qcar(v_1968);
    v_1971 = v_1968;
    if (!consp(v_1968)) goto v_1906;
    else goto v_1907;
v_1906:
    goto v_1914;
v_1910:
    v_1968 = v_1971;
    if (!symbolp(v_1968)) v_1969 = nil;
    else { v_1969 = qfastgets(v_1968);
           if (v_1969 != nil) { v_1969 = elt(v_1969, 2); // rtype
#ifdef RECORD_GET
             if (v_1969 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_1969 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_1969 == SPID_NOPROP) v_1969 = nil; }}
#endif
    goto v_1911;
v_1912:
    v_1968 = elt(env, 1); // !3vector
    goto v_1913;
v_1914:
    goto v_1910;
v_1911:
    goto v_1912;
v_1913:
    v_1968 = (v_1969 == v_1968 ? lisp_true : nil);
    goto v_1905;
v_1907:
    v_1968 = nil;
    goto v_1905;
    v_1968 = nil;
v_1905:
    if (v_1968 == nil) goto v_1903;
    v_1968 = v_1970;
    v_1968 = qcdr(v_1968);
    v_1968 = qcar(v_1968);
    {
        fn = elt(env, 5); // isvectorindex
        return (*qfn1(fn))(fn, v_1968);
    }
v_1903:
    goto v_1933;
v_1929:
    v_1969 = v_1971;
    goto v_1930;
v_1931:
    v_1968 = elt(env, 2); // vectorfn
    goto v_1932;
v_1933:
    goto v_1929;
v_1930:
    goto v_1931;
v_1932:
    v_1968 = Lflagp(nil, v_1969, v_1968);
    env = stack[0];
    if (v_1968 == nil) goto v_1927;
    v_1968 = lisp_true;
    goto v_1863;
v_1927:
    goto v_1948;
v_1944:
    v_1969 = v_1971;
    goto v_1945;
v_1946:
    v_1968 = elt(env, 3); // varithop
    goto v_1947;
v_1948:
    goto v_1944;
v_1945:
    goto v_1946;
v_1947:
    v_1968 = Lflagp(nil, v_1969, v_1968);
    env = stack[0];
    if (v_1968 == nil) goto v_1942;
    v_1968 = lisp_true;
    goto v_1940;
v_1942:
    goto v_1959;
v_1955:
    v_1969 = v_1971;
    goto v_1956;
v_1957:
    v_1968 = elt(env, 4); // vectormapping
    goto v_1958;
v_1959:
    goto v_1955;
v_1956:
    goto v_1957;
v_1958:
    v_1968 = Lflagp(nil, v_1969, v_1968);
    env = stack[0];
    goto v_1940;
    v_1968 = nil;
v_1940:
    if (v_1968 == nil) goto v_1938;
    v_1968 = v_1970;
    v_1968 = qcdr(v_1968);
    {
        fn = elt(env, 6); // hasonevector
        return (*qfn1(fn))(fn, v_1968);
    }
v_1938:
    v_1968 = nil;
    goto v_1863;
    v_1968 = nil;
v_1863:
    return onevalue(v_1968);
}



// Code for pv_sort2a

static LispObject CC_pv_sort2a(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1964, v_1965;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1857,v_1858);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_1858;
    stack[-1] = v_1857;
// end of prologue
v_1862:
    v_1964 = stack[0];
    v_1964 = qcdr(v_1964);
    if (v_1964 == nil) goto v_1865;
    else goto v_1866;
v_1865:
    goto v_1878;
v_1874:
    v_1964 = stack[-1];
    v_1965 = qcdr(v_1964);
    goto v_1875;
v_1876:
    v_1964 = stack[0];
    v_1964 = qcar(v_1964);
    v_1964 = qcdr(v_1964);
    goto v_1877;
v_1878:
    goto v_1874;
v_1875:
    goto v_1876;
v_1877:
    v_1964 = (LispObject)greaterp2(v_1965, v_1964);
    v_1964 = v_1964 ? lisp_true : nil;
    env = stack[-3];
    if (v_1964 == nil) goto v_1872;
    goto v_1889;
v_1885:
    goto v_1886;
v_1887:
    v_1964 = stack[-1];
    v_1964 = ncons(v_1964);
    goto v_1888;
v_1889:
    goto v_1885;
v_1886:
    goto v_1887;
v_1888:
    {
        LispObject v_1969 = stack[0];
        return Lrplacd(nil, v_1969, v_1964);
    }
v_1872:
    goto v_1900;
v_1896:
    v_1964 = stack[0];
    v_1965 = qcar(v_1964);
    goto v_1897;
v_1898:
    v_1964 = stack[0];
    v_1964 = qcdr(v_1964);
    goto v_1899;
v_1900:
    goto v_1896;
v_1897:
    goto v_1898;
v_1899:
    v_1964 = cons(v_1965, v_1964);
    env = stack[-3];
    stack[-2] = v_1964;
    goto v_1911;
v_1907:
    goto v_1917;
v_1913:
    v_1965 = stack[0];
    goto v_1914;
v_1915:
    v_1964 = stack[-1];
    goto v_1916;
v_1917:
    goto v_1913;
v_1914:
    goto v_1915;
v_1916:
    v_1965 = Lrplaca(nil, v_1965, v_1964);
    goto v_1908;
v_1909:
    v_1964 = stack[-2];
    goto v_1910;
v_1911:
    goto v_1907;
v_1908:
    goto v_1909;
v_1910:
        return Lrplacd(nil, v_1965, v_1964);
    goto v_1864;
v_1866:
    goto v_1928;
v_1924:
    v_1964 = stack[-1];
    v_1965 = qcdr(v_1964);
    goto v_1925;
v_1926:
    v_1964 = stack[0];
    v_1964 = qcar(v_1964);
    v_1964 = qcdr(v_1964);
    goto v_1927;
v_1928:
    goto v_1924;
v_1925:
    goto v_1926;
v_1927:
    v_1964 = (LispObject)greaterp2(v_1965, v_1964);
    v_1964 = v_1964 ? lisp_true : nil;
    env = stack[-3];
    if (v_1964 == nil) goto v_1922;
    v_1964 = stack[0];
    v_1964 = qcdr(v_1964);
    stack[0] = v_1964;
    goto v_1862;
v_1922:
    goto v_1943;
v_1939:
    v_1964 = stack[0];
    v_1965 = qcar(v_1964);
    goto v_1940;
v_1941:
    v_1964 = stack[0];
    v_1964 = qcdr(v_1964);
    goto v_1942;
v_1943:
    goto v_1939;
v_1940:
    goto v_1941;
v_1942:
    v_1964 = cons(v_1965, v_1964);
    env = stack[-3];
    stack[-2] = v_1964;
    goto v_1954;
v_1950:
    goto v_1960;
v_1956:
    v_1965 = stack[0];
    goto v_1957;
v_1958:
    v_1964 = stack[-1];
    goto v_1959;
v_1960:
    goto v_1956;
v_1957:
    goto v_1958;
v_1959:
    v_1965 = Lrplaca(nil, v_1965, v_1964);
    goto v_1951;
v_1952:
    v_1964 = stack[-2];
    goto v_1953;
v_1954:
    goto v_1950;
v_1951:
    goto v_1952;
v_1953:
        return Lrplacd(nil, v_1965, v_1964);
v_1864:
    v_1964 = nil;
    return onevalue(v_1964);
}



// Code for times!-mod!-p

static LispObject CC_timesKmodKp(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_2075, v_2076, v_2077;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1857,v_1858);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_1858;
    stack[-1] = v_1857;
// end of prologue
    v_2075 = stack[-1];
    if (v_2075 == nil) goto v_1866;
    else goto v_1867;
v_1866:
    v_2075 = lisp_true;
    goto v_1865;
v_1867:
    v_2075 = stack[0];
    v_2075 = (v_2075 == nil ? lisp_true : nil);
    goto v_1865;
    v_2075 = nil;
v_1865:
    if (v_2075 == nil) goto v_1863;
    v_2075 = nil;
    goto v_1861;
v_1863:
    v_2075 = stack[-1];
    if (!consp(v_2075)) goto v_1879;
    else goto v_1880;
v_1879:
    v_2075 = lisp_true;
    goto v_1878;
v_1880:
    v_2075 = stack[-1];
    v_2075 = qcar(v_2075);
    v_2075 = (consp(v_2075) ? nil : lisp_true);
    goto v_1878;
    v_2075 = nil;
v_1878:
    if (v_2075 == nil) goto v_1876;
    goto v_1893;
v_1889:
    v_2076 = stack[0];
    goto v_1890;
v_1891:
    v_2075 = stack[-1];
    goto v_1892;
v_1893:
    goto v_1889;
v_1890:
    goto v_1891;
v_1892:
    {
        fn = elt(env, 1); // multiply!-by!-constant!-mod!-p
        return (*qfn2(fn))(fn, v_2076, v_2075);
    }
v_1876:
    v_2075 = stack[0];
    if (!consp(v_2075)) goto v_1900;
    else goto v_1901;
v_1900:
    v_2075 = lisp_true;
    goto v_1899;
v_1901:
    v_2075 = stack[0];
    v_2075 = qcar(v_2075);
    v_2075 = (consp(v_2075) ? nil : lisp_true);
    goto v_1899;
    v_2075 = nil;
v_1899:
    if (v_2075 == nil) goto v_1897;
    goto v_1914;
v_1910:
    v_2076 = stack[-1];
    goto v_1911;
v_1912:
    v_2075 = stack[0];
    goto v_1913;
v_1914:
    goto v_1910;
v_1911:
    goto v_1912;
v_1913:
    {
        fn = elt(env, 1); // multiply!-by!-constant!-mod!-p
        return (*qfn2(fn))(fn, v_2076, v_2075);
    }
v_1897:
    goto v_1923;
v_1919:
    v_2075 = stack[-1];
    v_2075 = qcar(v_2075);
    v_2075 = qcar(v_2075);
    v_2076 = qcar(v_2075);
    goto v_1920;
v_1921:
    v_2075 = stack[0];
    v_2075 = qcar(v_2075);
    v_2075 = qcar(v_2075);
    v_2075 = qcar(v_2075);
    goto v_1922;
v_1923:
    goto v_1919;
v_1920:
    goto v_1921;
v_1922:
    if (equal(v_2076, v_2075)) goto v_1917;
    else goto v_1918;
v_1917:
    goto v_1937;
v_1933:
    goto v_1943;
v_1939:
    goto v_1949;
v_1945:
    v_2075 = stack[-1];
    v_2076 = qcar(v_2075);
    goto v_1946;
v_1947:
    v_2075 = stack[0];
    goto v_1948;
v_1949:
    goto v_1945;
v_1946:
    goto v_1947;
v_1948:
    fn = elt(env, 2); // times!-term!-mod!-p
    stack[-2] = (*qfn2(fn))(fn, v_2076, v_2075);
    env = stack[-3];
    goto v_1940;
v_1941:
    goto v_1958;
v_1954:
    v_2075 = stack[0];
    v_2076 = qcar(v_2075);
    goto v_1955;
v_1956:
    v_2075 = stack[-1];
    v_2075 = qcdr(v_2075);
    goto v_1957;
v_1958:
    goto v_1954;
v_1955:
    goto v_1956;
v_1957:
    fn = elt(env, 2); // times!-term!-mod!-p
    v_2075 = (*qfn2(fn))(fn, v_2076, v_2075);
    env = stack[-3];
    goto v_1942;
v_1943:
    goto v_1939;
v_1940:
    goto v_1941;
v_1942:
    fn = elt(env, 3); // plus!-mod!-p
    stack[-2] = (*qfn2(fn))(fn, stack[-2], v_2075);
    env = stack[-3];
    goto v_1934;
v_1935:
    goto v_1968;
v_1964:
    v_2075 = stack[-1];
    v_2076 = qcdr(v_2075);
    goto v_1965;
v_1966:
    v_2075 = stack[0];
    v_2075 = qcdr(v_2075);
    goto v_1967;
v_1968:
    goto v_1964;
v_1965:
    goto v_1966;
v_1967:
    v_2075 = CC_timesKmodKp(elt(env, 0), v_2076, v_2075);
    env = stack[-3];
    goto v_1936;
v_1937:
    goto v_1933;
v_1934:
    goto v_1935;
v_1936:
    {
        LispObject v_2081 = stack[-2];
        fn = elt(env, 3); // plus!-mod!-p
        return (*qfn2(fn))(fn, v_2081, v_2075);
    }
v_1918:
    goto v_1980;
v_1976:
    v_2075 = stack[-1];
    v_2075 = qcar(v_2075);
    v_2075 = qcar(v_2075);
    v_2076 = qcar(v_2075);
    goto v_1977;
v_1978:
    v_2075 = stack[0];
    v_2075 = qcar(v_2075);
    v_2075 = qcar(v_2075);
    v_2075 = qcar(v_2075);
    goto v_1979;
v_1980:
    goto v_1976;
v_1977:
    goto v_1978;
v_1979:
    fn = elt(env, 4); // ordop
    v_2075 = (*qfn2(fn))(fn, v_2076, v_2075);
    env = stack[-3];
    if (v_2075 == nil) goto v_1974;
    goto v_1994;
v_1990:
    v_2075 = stack[-1];
    v_2075 = qcar(v_2075);
    v_2076 = qcdr(v_2075);
    goto v_1991;
v_1992:
    v_2075 = stack[0];
    goto v_1993;
v_1994:
    goto v_1990;
v_1991:
    goto v_1992;
v_1993:
    stack[-2] = CC_timesKmodKp(elt(env, 0), v_2076, v_2075);
    env = stack[-3];
    goto v_2004;
v_2000:
    v_2075 = stack[-1];
    v_2076 = qcdr(v_2075);
    goto v_2001;
v_2002:
    v_2075 = stack[0];
    goto v_2003;
v_2004:
    goto v_2000;
v_2001:
    goto v_2002;
v_2003:
    v_2075 = CC_timesKmodKp(elt(env, 0), v_2076, v_2075);
    v_2076 = stack[-2];
    v_2077 = v_2076;
    if (v_2077 == nil) goto v_2012;
    else goto v_2013;
v_2012:
    goto v_2011;
v_2013:
    goto v_2025;
v_2019:
    v_2077 = stack[-1];
    v_2077 = qcar(v_2077);
    v_2077 = qcar(v_2077);
    goto v_2020;
v_2021:
    goto v_2022;
v_2023:
    goto v_2024;
v_2025:
    goto v_2019;
v_2020:
    goto v_2021;
v_2022:
    goto v_2023;
v_2024:
    return acons(v_2077, v_2076, v_2075);
    v_2075 = nil;
v_2011:
    goto v_1861;
v_1974:
    goto v_2038;
v_2034:
    v_2076 = stack[-1];
    goto v_2035;
v_2036:
    v_2075 = stack[0];
    v_2075 = qcar(v_2075);
    v_2075 = qcdr(v_2075);
    goto v_2037;
v_2038:
    goto v_2034;
v_2035:
    goto v_2036;
v_2037:
    stack[-2] = CC_timesKmodKp(elt(env, 0), v_2076, v_2075);
    env = stack[-3];
    goto v_2048;
v_2044:
    v_2076 = stack[-1];
    goto v_2045;
v_2046:
    v_2075 = stack[0];
    v_2075 = qcdr(v_2075);
    goto v_2047;
v_2048:
    goto v_2044;
v_2045:
    goto v_2046;
v_2047:
    v_2075 = CC_timesKmodKp(elt(env, 0), v_2076, v_2075);
    v_2076 = stack[-2];
    v_2077 = v_2076;
    if (v_2077 == nil) goto v_2056;
    else goto v_2057;
v_2056:
    goto v_2055;
v_2057:
    goto v_2069;
v_2063:
    v_2077 = stack[0];
    v_2077 = qcar(v_2077);
    v_2077 = qcar(v_2077);
    goto v_2064;
v_2065:
    goto v_2066;
v_2067:
    goto v_2068;
v_2069:
    goto v_2063;
v_2064:
    goto v_2065;
v_2066:
    goto v_2067;
v_2068:
    return acons(v_2077, v_2076, v_2075);
    v_2075 = nil;
v_2055:
    goto v_1861;
    v_2075 = nil;
v_1861:
    return onevalue(v_2075);
}



// Code for gcddd

static LispObject CC_gcddd(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1974, v_1975, v_1976;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1857,v_1858);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_1858;
    stack[-1] = v_1857;
// end of prologue
    goto v_1872;
v_1868:
    v_1975 = stack[-1];
    goto v_1869;
v_1870:
    v_1974 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1871;
v_1872:
    goto v_1868;
v_1869:
    goto v_1870;
v_1871:
    if (v_1975 == v_1974) goto v_1866;
    else goto v_1867;
v_1866:
    v_1974 = lisp_true;
    goto v_1865;
v_1867:
    goto v_1882;
v_1878:
    v_1975 = stack[0];
    goto v_1879;
v_1880:
    v_1974 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1881;
v_1882:
    goto v_1878;
v_1879:
    goto v_1880;
v_1881:
    v_1974 = (v_1975 == v_1974 ? lisp_true : nil);
    goto v_1865;
    v_1974 = nil;
v_1865:
    if (v_1974 == nil) goto v_1863;
    v_1974 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1861;
v_1863:
    v_1974 = stack[-1];
    if (!consp(v_1974)) goto v_1887;
    else goto v_1888;
v_1887:
    v_1974 = stack[0];
    if (!consp(v_1974)) goto v_1892;
    else goto v_1893;
v_1892:
    goto v_1900;
v_1896:
    v_1975 = stack[-1];
    goto v_1897;
v_1898:
    v_1974 = stack[0];
    goto v_1899;
v_1900:
    goto v_1896;
v_1897:
    goto v_1898;
v_1899:
        return Lgcd(nil, v_1975, v_1974);
v_1893:
    v_1974 = stack[0];
    fn = elt(env, 2); // fieldp
    v_1974 = (*qfn1(fn))(fn, v_1974);
    env = stack[-2];
    if (v_1974 == nil) goto v_1904;
    v_1974 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1891;
v_1904:
    goto v_1917;
v_1911:
    v_1976 = stack[-1];
    goto v_1912;
v_1913:
    v_1975 = stack[0];
    goto v_1914;
v_1915:
    v_1974 = elt(env, 1); // gcd
    goto v_1916;
v_1917:
    goto v_1911;
v_1912:
    goto v_1913;
v_1914:
    goto v_1915;
v_1916:
    {
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(fn, 3, v_1976, v_1975, v_1974);
    }
    v_1974 = nil;
v_1891:
    goto v_1861;
v_1888:
    v_1974 = stack[0];
    if (!consp(v_1974)) goto v_1921;
    else goto v_1922;
v_1921:
    v_1974 = stack[-1];
    v_1974 = qcar(v_1974);
    if (!symbolp(v_1974)) v_1974 = nil;
    else { v_1974 = qfastgets(v_1974);
           if (v_1974 != nil) { v_1974 = elt(v_1974, 3); // field
#ifdef RECORD_GET
             if (v_1974 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_1974 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_1974 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_1974 == SPID_NOPROP) v_1974 = nil; else v_1974 = lisp_true; }}
#endif
    if (v_1974 == nil) goto v_1927;
    v_1974 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1925;
v_1927:
    goto v_1941;
v_1935:
    v_1976 = stack[-1];
    goto v_1936;
v_1937:
    v_1975 = stack[0];
    goto v_1938;
v_1939:
    v_1974 = elt(env, 1); // gcd
    goto v_1940;
v_1941:
    goto v_1935;
v_1936:
    goto v_1937;
v_1938:
    goto v_1939;
v_1940:
    {
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(fn, 3, v_1976, v_1975, v_1974);
    }
    v_1974 = nil;
v_1925:
    goto v_1861;
v_1922:
    v_1974 = stack[-1];
    v_1974 = qcar(v_1974);
    if (!symbolp(v_1974)) v_1974 = nil;
    else { v_1974 = qfastgets(v_1974);
           if (v_1974 != nil) { v_1974 = elt(v_1974, 3); // field
#ifdef RECORD_GET
             if (v_1974 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_1974 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_1974 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_1974 == SPID_NOPROP) v_1974 = nil; else v_1974 = lisp_true; }}
#endif
    if (v_1974 == nil) goto v_1950;
    v_1974 = lisp_true;
    goto v_1948;
v_1950:
    v_1974 = stack[0];
    v_1974 = qcar(v_1974);
    if (!symbolp(v_1974)) v_1974 = nil;
    else { v_1974 = qfastgets(v_1974);
           if (v_1974 != nil) { v_1974 = elt(v_1974, 3); // field
#ifdef RECORD_GET
             if (v_1974 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_1974 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_1974 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_1974 == SPID_NOPROP) v_1974 = nil; else v_1974 = lisp_true; }}
#endif
    goto v_1948;
    v_1974 = nil;
v_1948:
    if (v_1974 == nil) goto v_1946;
    v_1974 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1861;
v_1946:
    goto v_1970;
v_1964:
    v_1976 = stack[-1];
    goto v_1965;
v_1966:
    v_1975 = stack[0];
    goto v_1967;
v_1968:
    v_1974 = elt(env, 1); // gcd
    goto v_1969;
v_1970:
    goto v_1964;
v_1965:
    goto v_1966;
v_1967:
    goto v_1968;
v_1969:
    {
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(fn, 3, v_1976, v_1975, v_1974);
    }
    v_1974 = nil;
v_1861:
    return onevalue(v_1974);
}



// Code for checkargcount

static LispObject CC_checkargcount(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1917, v_1918, v_1919, v_1920, v_1921;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1857,v_1858);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_1919 = v_1858;
    v_1920 = v_1857;
// end of prologue
    goto v_1872;
v_1868:
    v_1918 = v_1920;
    goto v_1869;
v_1870:
    v_1917 = elt(env, 1); // naryargs
    goto v_1871;
v_1872:
    goto v_1868;
v_1869:
    goto v_1870;
v_1871:
    v_1917 = Lflagp(nil, v_1918, v_1917);
    env = stack[-3];
    if (v_1917 == nil) goto v_1866;
    v_1917 = nil;
    goto v_1862;
v_1866:
    v_1917 = v_1920;
    if (!symbolp(v_1917)) v_1917 = nil;
    else { v_1917 = qfastgets(v_1917);
           if (v_1917 != nil) { v_1917 = elt(v_1917, 42); // number!-of!-args
#ifdef RECORD_GET
             if (v_1917 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v_1917 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v_1917 == SPID_NOPROP) v_1917 = nil; }}
#endif
    v_1921 = v_1917;
    v_1917 = v_1921;
    if (v_1917 == nil) goto v_1880;
    else goto v_1881;
v_1880:
    goto v_1888;
v_1884:
    v_1917 = v_1920;
    goto v_1885;
v_1886:
    v_1918 = v_1919;
    goto v_1887;
v_1888:
    goto v_1884;
v_1885:
    goto v_1886;
v_1887:
    {
        fn = elt(env, 3); // hasarg
        return (*qfn2(fn))(fn, v_1917, v_1918);
    }
v_1881:
    goto v_1899;
v_1895:
    v_1918 = v_1921;
    goto v_1896;
v_1897:
    v_1917 = v_1919;
    goto v_1898;
v_1899:
    goto v_1895;
v_1896:
    goto v_1897;
v_1898:
    if (equal(v_1918, v_1917)) goto v_1894;
    goto v_1911;
v_1903:
    stack[-2] = v_1920;
    goto v_1904;
v_1905:
    stack[-1] = v_1921;
    goto v_1906;
v_1907:
    stack[0] = v_1919;
    goto v_1908;
v_1909:
    v_1917 = qvalue(elt(env, 2)); // curfun!*
    v_1917 = ncons(v_1917);
    env = stack[-3];
    goto v_1910;
v_1911:
    goto v_1903;
v_1904:
    goto v_1905;
v_1906:
    goto v_1907;
v_1908:
    goto v_1909;
v_1910:
    fn = elt(env, 4); // instdof
    v_1917 = (*qfnn(fn))(fn, 4, stack[-2], stack[-1], stack[0], v_1917);
    goto v_1892;
v_1894:
v_1892:
    v_1917 = nil;
v_1862:
    return onevalue(v_1917);
}



// Code for wulessp

static LispObject CC_wulessp(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1965;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1857,v_1858);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_1858;
    stack[-1] = v_1857;
// end of prologue
    goto v_1868;
v_1864:
    v_1965 = stack[-1];
    fn = elt(env, 1); // wuconstantp
    v_1965 = (*qfn1(fn))(fn, v_1965);
    env = stack[-3];
    if (v_1965 == nil) goto v_1872;
    v_1965 = nil;
    stack[-2] = v_1965;
    goto v_1870;
v_1872:
    v_1965 = stack[-1];
    v_1965 = qcar(v_1965);
    v_1965 = qcar(v_1965);
    v_1965 = qcar(v_1965);
    stack[-2] = v_1965;
    goto v_1870;
    stack[-2] = nil;
v_1870:
    goto v_1865;
v_1866:
    v_1965 = stack[0];
    fn = elt(env, 1); // wuconstantp
    v_1965 = (*qfn1(fn))(fn, v_1965);
    env = stack[-3];
    if (v_1965 == nil) goto v_1885;
    v_1965 = nil;
    goto v_1883;
v_1885:
    v_1965 = stack[0];
    v_1965 = qcar(v_1965);
    v_1965 = qcar(v_1965);
    v_1965 = qcar(v_1965);
    goto v_1883;
    v_1965 = nil;
v_1883:
    goto v_1867;
v_1868:
    goto v_1864;
v_1865:
    goto v_1866;
v_1867:
    fn = elt(env, 2); // symbollessp
    v_1965 = (*qfn2(fn))(fn, stack[-2], v_1965);
    env = stack[-3];
    if (v_1965 == nil) goto v_1862;
    else goto v_1861;
v_1862:
    goto v_1903;
v_1899:
    v_1965 = stack[-1];
    fn = elt(env, 1); // wuconstantp
    v_1965 = (*qfn1(fn))(fn, v_1965);
    env = stack[-3];
    if (v_1965 == nil) goto v_1907;
    v_1965 = nil;
    stack[-2] = v_1965;
    goto v_1905;
v_1907:
    v_1965 = stack[-1];
    v_1965 = qcar(v_1965);
    v_1965 = qcar(v_1965);
    v_1965 = qcar(v_1965);
    stack[-2] = v_1965;
    goto v_1905;
    stack[-2] = nil;
v_1905:
    goto v_1900;
v_1901:
    v_1965 = stack[0];
    fn = elt(env, 1); // wuconstantp
    v_1965 = (*qfn1(fn))(fn, v_1965);
    env = stack[-3];
    if (v_1965 == nil) goto v_1920;
    v_1965 = nil;
    goto v_1918;
v_1920:
    v_1965 = stack[0];
    v_1965 = qcar(v_1965);
    v_1965 = qcar(v_1965);
    v_1965 = qcar(v_1965);
    goto v_1918;
    v_1965 = nil;
v_1918:
    goto v_1902;
v_1903:
    goto v_1899;
v_1900:
    goto v_1901;
v_1902:
    if (equal(stack[-2], v_1965)) goto v_1897;
    else goto v_1898;
v_1897:
    goto v_1935;
v_1931:
    v_1965 = stack[-1];
    fn = elt(env, 1); // wuconstantp
    v_1965 = (*qfn1(fn))(fn, v_1965);
    env = stack[-3];
    if (v_1965 == nil) goto v_1939;
    v_1965 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_1965;
    goto v_1937;
v_1939:
    v_1965 = stack[-1];
    v_1965 = qcar(v_1965);
    v_1965 = qcar(v_1965);
    v_1965 = qcdr(v_1965);
    stack[-1] = v_1965;
    goto v_1937;
    stack[-1] = nil;
v_1937:
    goto v_1932;
v_1933:
    v_1965 = stack[0];
    fn = elt(env, 1); // wuconstantp
    v_1965 = (*qfn1(fn))(fn, v_1965);
    if (v_1965 == nil) goto v_1952;
    v_1965 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1950;
v_1952:
    v_1965 = stack[0];
    v_1965 = qcar(v_1965);
    v_1965 = qcar(v_1965);
    v_1965 = qcdr(v_1965);
    goto v_1950;
    v_1965 = nil;
v_1950:
    goto v_1934;
v_1935:
    goto v_1931;
v_1932:
    goto v_1933;
v_1934:
    {
        LispObject v_1969 = stack[-1];
        return Llessp(nil, v_1969, v_1965);
    }
v_1898:
    v_1965 = nil;
    goto v_1896;
    v_1965 = nil;
v_1896:
v_1861:
    return onevalue(v_1965);
}



// Code for mcharg1

static LispObject CC_mcharg1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2016, v_2017, v_2018;
    LispObject fn;
    LispObject v_1859, v_1858, v_1857;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mcharg1");
    va_start(aa, nargs);
    v_1857 = va_arg(aa, LispObject);
    v_1858 = va_arg(aa, LispObject);
    v_1859 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_1859,v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_1857,v_1858,v_1859);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_1859;
    stack[-2] = v_1858;
    stack[-3] = v_1857;
// end of prologue
    v_2016 = stack[-3];
    if (v_2016 == nil) goto v_1867;
    else goto v_1868;
v_1867:
    v_2016 = stack[-2];
    v_2016 = (v_2016 == nil ? lisp_true : nil);
    goto v_1866;
v_1868:
    v_2016 = nil;
    goto v_1866;
    v_2016 = nil;
v_1866:
    if (v_2016 == nil) goto v_1864;
    v_2016 = nil;
    return ncons(v_2016);
v_1864:
    v_2016 = stack[-3];
    v_2016 = Llength(nil, v_2016);
    env = stack[-5];
    stack[-4] = v_2016;
    v_2016 = stack[-2];
    v_2016 = Llength(nil, v_2016);
    env = stack[-5];
    stack[0] = v_2016;
    v_2016 = stack[-1];
    if (!symbolp(v_2016)) v_2016 = nil;
    else { v_2016 = qfastgets(v_2016);
           if (v_2016 != nil) { v_2016 = elt(v_2016, 35); // nary
#ifdef RECORD_GET
             if (v_2016 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v_2016 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v_2016 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v_2016 == SPID_NOPROP) v_2016 = nil; else v_2016 = lisp_true; }}
#endif
    if (v_2016 == nil) goto v_1896;
    goto v_1904;
v_1900:
    v_2017 = stack[-4];
    goto v_1901;
v_1902:
    v_2016 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_1903;
v_1904:
    goto v_1900;
v_1901:
    goto v_1902;
v_1903:
    v_2016 = (LispObject)greaterp2(v_2017, v_2016);
    v_2016 = v_2016 ? lisp_true : nil;
    env = stack[-5];
    goto v_1894;
v_1896:
    v_2016 = nil;
    goto v_1894;
    v_2016 = nil;
v_1894:
    if (v_2016 == nil) goto v_1892;
    goto v_1920;
v_1916:
    v_2017 = stack[-4];
    goto v_1917;
v_1918:
    v_2016 = qvalue(elt(env, 1)); // matchlength!*
    goto v_1919;
v_1920:
    goto v_1916;
v_1917:
    goto v_1918;
v_1919:
    v_2016 = (LispObject)lesseq2(v_2017, v_2016);
    v_2016 = v_2016 ? lisp_true : nil;
    env = stack[-5];
    if (v_2016 == nil) goto v_1913;
    v_2016 = stack[-1];
    if (!symbolp(v_2016)) v_2016 = nil;
    else { v_2016 = qfastgets(v_2016);
           if (v_2016 != nil) { v_2016 = elt(v_2016, 43); // symmetric
#ifdef RECORD_GET
             if (v_2016 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v_2016 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v_2016 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v_2016 == SPID_NOPROP) v_2016 = nil; else v_2016 = lisp_true; }}
#endif
    if (v_2016 == nil) goto v_1913;
    goto v_1933;
v_1927:
    v_2018 = stack[-3];
    goto v_1928;
v_1929:
    v_2017 = stack[-2];
    goto v_1930;
v_1931:
    v_2016 = stack[-1];
    goto v_1932;
v_1933:
    goto v_1927;
v_1928:
    goto v_1929;
v_1930:
    goto v_1931;
v_1932:
    {
        fn = elt(env, 2); // mchcomb
        return (*qfnn(fn))(fn, 3, v_2018, v_2017, v_2016);
    }
v_1913:
    goto v_1943;
v_1939:
    v_2017 = stack[0];
    goto v_1940;
v_1941:
    v_2016 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_1942;
v_1943:
    goto v_1939;
v_1940:
    goto v_1941;
v_1942:
    if (v_2017 == v_2016) goto v_1937;
    else goto v_1938;
v_1937:
    goto v_1951;
v_1947:
    v_2017 = stack[-1];
    goto v_1948;
v_1949:
    v_2016 = stack[-3];
    goto v_1950;
v_1951:
    goto v_1947;
v_1948:
    goto v_1949;
v_1950:
    fn = elt(env, 3); // mkbin
    v_2016 = (*qfn2(fn))(fn, v_2017, v_2016);
    env = stack[-5];
    v_2016 = qcdr(v_2016);
    stack[-3] = v_2016;
    v_2016 = (LispObject)32+TAG_FIXNUM; // 2
    stack[-4] = v_2016;
    goto v_1911;
v_1938:
    v_2016 = nil;
    goto v_1882;
v_1911:
    goto v_1890;
v_1892:
v_1890:
    goto v_1967;
v_1963:
    v_2017 = stack[-4];
    goto v_1964;
v_1965:
    v_2016 = stack[0];
    goto v_1966;
v_1967:
    goto v_1963;
v_1964:
    goto v_1965;
v_1966:
    if (equal(v_2017, v_2016)) goto v_1962;
    v_2016 = nil;
    goto v_1960;
v_1962:
    v_2016 = stack[-1];
    if (!symbolp(v_2016)) v_2016 = nil;
    else { v_2016 = qfastgets(v_2016);
           if (v_2016 != nil) { v_2016 = elt(v_2016, 43); // symmetric
#ifdef RECORD_GET
             if (v_2016 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v_2016 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v_2016 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v_2016 == SPID_NOPROP) v_2016 = nil; else v_2016 = lisp_true; }}
#endif
    if (v_2016 == nil) goto v_1972;
    goto v_1982;
v_1976:
    v_2018 = stack[-3];
    goto v_1977;
v_1978:
    v_2017 = stack[-2];
    goto v_1979;
v_1980:
    v_2016 = stack[-1];
    goto v_1981;
v_1982:
    goto v_1976;
v_1977:
    goto v_1978;
v_1979:
    goto v_1980;
v_1981:
    {
        fn = elt(env, 4); // mchsarg
        return (*qfnn(fn))(fn, 3, v_2018, v_2017, v_2016);
    }
v_1972:
    v_2016 = stack[-2];
    fn = elt(env, 5); // mtp
    v_2016 = (*qfn1(fn))(fn, v_2016);
    env = stack[-5];
    if (v_2016 == nil) goto v_1987;
    goto v_1996;
v_1992:
    v_2017 = stack[-2];
    goto v_1993;
v_1994:
    v_2016 = stack[-3];
    goto v_1995;
v_1996:
    goto v_1992;
v_1993:
    goto v_1994;
v_1995:
    fn = elt(env, 6); // pair
    v_2016 = (*qfn2(fn))(fn, v_2017, v_2016);
    return ncons(v_2016);
v_1987:
    goto v_2010;
v_2002:
    stack[0] = stack[-3];
    goto v_2003;
v_2004:
    goto v_2005;
v_2006:
    v_2016 = nil;
    v_2017 = ncons(v_2016);
    env = stack[-5];
    goto v_2007;
v_2008:
    v_2016 = stack[-1];
    goto v_2009;
v_2010:
    goto v_2002;
v_2003:
    goto v_2004;
v_2005:
    goto v_2006;
v_2007:
    goto v_2008;
v_2009:
    {
        LispObject v_2024 = stack[0];
        LispObject v_2025 = stack[-2];
        fn = elt(env, 7); // mcharg2
        return (*qfnn(fn))(fn, 4, v_2024, v_2025, v_2017, v_2016);
    }
    v_2016 = nil;
v_1960:
v_1882:
    goto v_1862;
    v_2016 = nil;
v_1862:
    return onevalue(v_2016);
}



// Code for talp_simplat1

static LispObject CC_talp_simplat1(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1902, v_1903, v_1904;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1857,v_1858);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_1902 = v_1858;
    stack[-1] = v_1857;
// end of prologue
    v_1902 = stack[-1];
    fn = elt(env, 3); // talp_simpat
    v_1902 = (*qfn1(fn))(fn, v_1902);
    env = stack[-3];
    stack[-1] = v_1902;
    goto v_1872;
v_1866:
    v_1902 = stack[-1];
    fn = elt(env, 4); // talp_op
    stack[-2] = (*qfn1(fn))(fn, v_1902);
    env = stack[-3];
    goto v_1867;
v_1868:
    v_1902 = stack[-1];
    fn = elt(env, 5); // talp_arg2l
    stack[0] = (*qfn1(fn))(fn, v_1902);
    env = stack[-3];
    goto v_1869;
v_1870:
    v_1902 = stack[-1];
    fn = elt(env, 6); // talp_arg2r
    v_1902 = (*qfn1(fn))(fn, v_1902);
    env = stack[-3];
    goto v_1871;
v_1872:
    goto v_1866;
v_1867:
    goto v_1868;
v_1869:
    goto v_1870;
v_1871:
    fn = elt(env, 7); // talp_simplat2
    v_1902 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_1902);
    env = stack[-3];
    v_1904 = v_1902;
    v_1902 = v_1904;
    if (v_1902 == nil) goto v_1882;
    goto v_1892;
v_1888:
    v_1903 = v_1904;
    goto v_1889;
v_1890:
    v_1902 = lisp_true;
    goto v_1891;
v_1892:
    goto v_1888;
v_1889:
    goto v_1890;
v_1891:
    if (v_1903 == v_1902) goto v_1886;
    else goto v_1887;
v_1886:
    v_1902 = elt(env, 1); // true
    goto v_1862;
v_1887:
    v_1902 = v_1904;
    goto v_1862;
    goto v_1880;
v_1882:
    v_1902 = elt(env, 2); // false
    goto v_1862;
v_1880:
    v_1902 = nil;
v_1862:
    return onevalue(v_1902);
}



// Code for mri_type

static LispObject CC_mri_type(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1875, v_1876;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1875 = v_1857;
// end of prologue
    v_1876 = v_1875;
    v_1876 = qcdr(v_1876);
    v_1876 = qcdr(v_1876);
    v_1876 = qcdr(v_1876);
    if (v_1876 == nil) goto v_1861;
    else goto v_1862;
v_1861:
    v_1875 = nil;
    goto v_1860;
v_1862:
    v_1875 = qcdr(v_1875);
    v_1875 = qcdr(v_1875);
    v_1875 = qcdr(v_1875);
    v_1875 = qcar(v_1875);
    goto v_1860;
    v_1875 = nil;
v_1860:
    return onevalue(v_1875);
}



// Code for rl_simpat

static LispObject CC_rl_simpat(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1868;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_1868 = v_1857;
// end of prologue
    goto v_1864;
v_1860:
    stack[0] = qvalue(elt(env, 1)); // rl_simpat!*
    goto v_1861;
v_1862:
    v_1868 = ncons(v_1868);
    env = stack[-1];
    goto v_1863;
v_1864:
    goto v_1860;
v_1861:
    goto v_1862;
v_1863:
    {
        LispObject v_1870 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_1870, v_1868);
    }
}



// Code for find

static LispObject CC_find(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_3060, v_3061, v_3062;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_1857;
// end of prologue
v_1856:
    v_3060 = elt(env, 1); // mcd
    v_3060 = ncons(v_3060);
    env = stack[-3];
    fn = elt(env, 14); // off
    v_3060 = (*qfn1(fn))(fn, v_3060);
    env = stack[-3];
    v_3060 = elt(env, 2); // factor
    v_3060 = ncons(v_3060);
    env = stack[-3];
    fn = elt(env, 14); // off
    v_3060 = (*qfn1(fn))(fn, v_3060);
    env = stack[-3];
    v_3060 = elt(env, 3); // exp
    v_3060 = ncons(v_3060);
    env = stack[-3];
    fn = elt(env, 14); // off
    v_3060 = (*qfn1(fn))(fn, v_3060);
    env = stack[-3];
    v_3060 = stack[-1];
    if (!consp(v_3060)) goto v_1872;
    else goto v_1873;
v_1872:
    goto v_1884;
v_1880:
    v_3061 = stack[-1];
    goto v_1881;
v_1882:
    v_3060 = elt(env, 4); // ww
    goto v_1883;
v_1884:
    goto v_1880;
v_1881:
    goto v_1882;
v_1883:
    fn = elt(env, 15); // freeof
    v_3060 = (*qfn2(fn))(fn, v_3061, v_3060);
    env = stack[-3];
    if (v_3060 == nil) goto v_1878;
    v_3060 = stack[-1];
    if (is_number(v_3060)) goto v_1889;
    else goto v_1890;
v_1889:
    goto v_1897;
v_1893:
    v_3061 = elt(env, 5); // number
    goto v_1894;
v_1895:
    v_3060 = stack[-1];
    goto v_1896;
v_1897:
    goto v_1893;
v_1894:
    goto v_1895;
v_1896:
    return list2(v_3061, v_3060);
v_1890:
    goto v_1910;
v_1906:
    v_3061 = stack[-1];
    goto v_1907;
v_1908:
    v_3060 = elt(env, 6); // e
    goto v_1909;
v_1910:
    goto v_1906;
v_1907:
    goto v_1908;
v_1909:
    if (v_3061 == v_3060) goto v_1904;
    else goto v_1905;
v_1904:
    goto v_1918;
v_1914:
    v_3060 = elt(env, 5); // number
    goto v_1915;
v_1916:
    v_3061 = elt(env, 6); // e
    goto v_1917;
v_1918:
    goto v_1914;
v_1915:
    goto v_1916;
v_1917:
    return list2(v_3060, v_3061);
v_1905:
    goto v_1928;
v_1924:
    v_3061 = elt(env, 7); // x_exp
    goto v_1925;
v_1926:
    v_3060 = stack[-1];
    goto v_1927;
v_1928:
    goto v_1924;
v_1925:
    goto v_1926;
v_1927:
    return list2(v_3061, v_3060);
    goto v_1888;
v_1888:
    goto v_1876;
v_1878:
    goto v_1941;
v_1935:
    v_3061 = elt(env, 8); // expt
    goto v_1936;
v_1937:
    v_3062 = elt(env, 4); // ww
    goto v_1938;
v_1939:
    v_3060 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1940;
v_1941:
    goto v_1935;
v_1936:
    goto v_1937;
v_1938:
    goto v_1939;
v_1940:
    return list3(v_3061, v_3062, v_3060);
v_1876:
    goto v_1871;
v_1873:
    goto v_1955;
v_1951:
    v_3060 = stack[-1];
    v_3061 = qcar(v_3060);
    goto v_1952;
v_1953:
    v_3060 = elt(env, 8); // expt
    goto v_1954;
v_1955:
    goto v_1951;
v_1952:
    goto v_1953;
v_1954:
    if (v_3061 == v_3060) goto v_1949;
    else goto v_1950;
v_1949:
    goto v_1966;
v_1960:
    v_3062 = elt(env, 8); // expt
    goto v_1961;
v_1962:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_1963;
v_1964:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    goto v_1965;
v_1966:
    goto v_1960;
v_1961:
    goto v_1962;
v_1963:
    goto v_1964;
v_1965:
    return list3(v_3062, v_3061, v_3060);
v_1950:
    goto v_1985;
v_1981:
    v_3060 = stack[-1];
    v_3061 = qcar(v_3060);
    goto v_1982;
v_1983:
    v_3060 = elt(env, 9); // plus
    goto v_1984;
v_1985:
    goto v_1981;
v_1982:
    goto v_1983;
v_1984:
    if (v_3061 == v_3060) goto v_1979;
    else goto v_1980;
v_1979:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    if (!consp(v_3060)) goto v_1995;
    else goto v_1996;
v_1995:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = (consp(v_3060) ? nil : lisp_true);
    goto v_1994;
v_1996:
    v_3060 = nil;
    goto v_1994;
    v_3060 = nil;
v_1994:
    if (v_3060 == nil) goto v_1992;
    goto v_2017;
v_2013:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = Llength(nil, v_3060);
    env = stack[-3];
    goto v_2014;
v_2015:
    v_3060 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_2016;
v_2017:
    goto v_2013;
v_2014:
    goto v_2015;
v_2016:
    v_3060 = (LispObject)greaterp2(v_3061, v_3060);
    v_3060 = v_3060 ? lisp_true : nil;
    env = stack[-3];
    if (v_3060 == nil) goto v_2011;
    goto v_2034;
v_2030:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_2031;
v_2032:
    v_3060 = elt(env, 4); // ww
    goto v_2033;
v_2034:
    goto v_2030;
v_2031:
    goto v_2032;
v_2033:
    if (v_3061 == v_3060) goto v_2028;
    else goto v_2029;
v_2028:
    goto v_2044;
v_2040:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_2041;
v_2042:
    v_3060 = elt(env, 4); // ww
    goto v_2043;
v_2044:
    goto v_2040;
v_2041:
    goto v_2042;
v_2043:
    fn = elt(env, 15); // freeof
    v_3060 = (*qfn2(fn))(fn, v_3061, v_3060);
    env = stack[-3];
    goto v_2027;
v_2029:
    v_3060 = nil;
    goto v_2027;
    v_3060 = nil;
v_2027:
    if (v_3060 == nil) goto v_2025;
    goto v_2058;
v_2054:
    goto v_2066;
v_2060:
    v_3062 = elt(env, 8); // expt
    goto v_2061;
v_2062:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_2063;
v_2064:
    v_3060 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2065;
v_2066:
    goto v_2060;
v_2061:
    goto v_2062;
v_2063:
    goto v_2064;
v_2065:
    stack[0] = list3(v_3062, v_3061, v_3060);
    env = stack[-3];
    goto v_2055;
v_2056:
    goto v_2078;
v_2074:
    v_3060 = elt(env, 9); // plus
    v_3061 = ncons(v_3060);
    env = stack[-3];
    goto v_2075;
v_2076:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    goto v_2077;
v_2078:
    goto v_2074;
v_2075:
    goto v_2076;
v_2077:
    v_3060 = Lappend(nil, v_3061, v_3060);
    env = stack[-3];
    v_3060 = CC_find(elt(env, 0), v_3060);
    goto v_2057;
v_2058:
    goto v_2054;
v_2055:
    goto v_2056;
v_2057:
    {
        LispObject v_3066 = stack[0];
        return Lappend(nil, v_3066, v_3060);
    }
v_2025:
    goto v_2091;
v_2087:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    stack[0] = CC_find(elt(env, 0), v_3060);
    env = stack[-3];
    goto v_2088;
v_2089:
    goto v_2101;
v_2097:
    v_3060 = elt(env, 9); // plus
    v_3061 = ncons(v_3060);
    env = stack[-3];
    goto v_2098;
v_2099:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    goto v_2100;
v_2101:
    goto v_2097;
v_2098:
    goto v_2099;
v_2100:
    v_3060 = Lappend(nil, v_3061, v_3060);
    goto v_2090;
v_2091:
    goto v_2087;
v_2088:
    goto v_2089;
v_2090:
    {
        LispObject v_3067 = stack[0];
        return Lappend(nil, v_3067, v_3060);
    }
    goto v_2009;
v_2011:
    goto v_2121;
v_2117:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_2118;
v_2119:
    v_3060 = elt(env, 4); // ww
    goto v_2120;
v_2121:
    goto v_2117;
v_2118:
    goto v_2119;
v_2120:
    if (v_3061 == v_3060) goto v_2115;
    else goto v_2116;
v_2115:
    goto v_2132;
v_2128:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_2129;
v_2130:
    v_3060 = elt(env, 4); // ww
    goto v_2131;
v_2132:
    goto v_2128;
v_2129:
    goto v_2130;
v_2131:
    fn = elt(env, 15); // freeof
    v_3060 = (*qfn2(fn))(fn, v_3061, v_3060);
    env = stack[-3];
    goto v_2114;
v_2116:
    v_3060 = nil;
    goto v_2114;
    v_3060 = nil;
v_2114:
    if (v_3060 == nil) goto v_2112;
    goto v_2149;
v_2141:
    stack[-2] = elt(env, 7); // x_exp
    goto v_2142;
v_2143:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    stack[-1] = qcar(v_3060);
    goto v_2144;
v_2145:
    stack[0] = elt(env, 8); // expt
    goto v_2146;
v_2147:
    goto v_2160;
v_2156:
    v_3061 = elt(env, 4); // ww
    goto v_2157;
v_2158:
    v_3060 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2159;
v_2160:
    goto v_2156;
v_2157:
    goto v_2158;
v_2159:
    v_3060 = list2(v_3061, v_3060);
    goto v_2148;
v_2149:
    goto v_2141;
v_2142:
    goto v_2143;
v_2144:
    goto v_2145;
v_2146:
    goto v_2147;
v_2148:
    {
        LispObject v_3068 = stack[-2];
        LispObject v_3069 = stack[-1];
        LispObject v_3070 = stack[0];
        return list3star(v_3068, v_3069, v_3070, v_3060);
    }
v_2112:
    goto v_2177;
v_2173:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_2174;
v_2175:
    v_3060 = elt(env, 4); // ww
    goto v_2176;
v_2177:
    goto v_2173;
v_2174:
    goto v_2175;
v_2176:
    if (v_3061 == v_3060) goto v_2171;
    else goto v_2172;
v_2171:
    goto v_2187;
v_2183:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_2184;
v_2185:
    v_3060 = elt(env, 4); // ww
    goto v_2186;
v_2187:
    goto v_2183;
v_2184:
    goto v_2185;
v_2186:
    fn = elt(env, 15); // freeof
    v_3060 = (*qfn2(fn))(fn, v_3061, v_3060);
    env = stack[-3];
    goto v_2170;
v_2172:
    v_3060 = nil;
    goto v_2170;
    v_3060 = nil;
v_2170:
    if (v_3060 == nil) goto v_2168;
    goto v_2201;
v_2197:
    goto v_2209;
v_2203:
    v_3062 = elt(env, 8); // expt
    goto v_2204;
v_2205:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_2206;
v_2207:
    v_3060 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2208;
v_2209:
    goto v_2203;
v_2204:
    goto v_2205;
v_2206:
    goto v_2207;
v_2208:
    stack[0] = list3(v_3062, v_3061, v_3060);
    env = stack[-3];
    goto v_2198;
v_2199:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = CC_find(elt(env, 0), v_3060);
    goto v_2200;
v_2201:
    goto v_2197;
v_2198:
    goto v_2199;
v_2200:
    {
        LispObject v_3071 = stack[0];
        return Lappend(nil, v_3071, v_3060);
    }
v_2168:
    goto v_2227;
v_2223:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    stack[0] = CC_find(elt(env, 0), v_3060);
    env = stack[-3];
    goto v_2224;
v_2225:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = CC_find(elt(env, 0), v_3060);
    goto v_2226;
v_2227:
    goto v_2223;
v_2224:
    goto v_2225;
v_2226:
    {
        LispObject v_3072 = stack[0];
        return Lappend(nil, v_3072, v_3060);
    }
    goto v_2110;
v_2110:
    goto v_2009;
v_2009:
    goto v_1990;
v_1992:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    if (!consp(v_3060)) goto v_2245;
    else goto v_2246;
v_2245:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = Lconsp(nil, v_3060);
    env = stack[-3];
    goto v_2244;
v_2246:
    v_3060 = nil;
    goto v_2244;
    v_3060 = nil;
v_2244:
    if (v_3060 == nil) goto v_2242;
    goto v_2267;
v_2263:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = Llength(nil, v_3060);
    env = stack[-3];
    goto v_2264;
v_2265:
    v_3060 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_2266;
v_2267:
    goto v_2263;
v_2264:
    goto v_2265;
v_2266:
    v_3060 = (LispObject)greaterp2(v_3061, v_3060);
    v_3060 = v_3060 ? lisp_true : nil;
    env = stack[-3];
    if (v_3060 == nil) goto v_2261;
    goto v_2280;
v_2276:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_2277;
v_2278:
    v_3060 = elt(env, 4); // ww
    goto v_2279;
v_2280:
    goto v_2276;
v_2277:
    goto v_2278;
v_2279:
    if (v_3061 == v_3060) goto v_2274;
    else goto v_2275;
v_2274:
    goto v_2290;
v_2286:
    goto v_2298;
v_2292:
    v_3062 = elt(env, 8); // expt
    goto v_2293;
v_2294:
    v_3061 = elt(env, 4); // ww
    goto v_2295;
v_2296:
    v_3060 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2297;
v_2298:
    goto v_2292;
v_2293:
    goto v_2294;
v_2295:
    goto v_2296;
v_2297:
    stack[0] = list3(v_3062, v_3061, v_3060);
    env = stack[-3];
    goto v_2287;
v_2288:
    goto v_2308;
v_2304:
    v_3060 = elt(env, 9); // plus
    v_3061 = ncons(v_3060);
    env = stack[-3];
    goto v_2305;
v_2306:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    goto v_2307;
v_2308:
    goto v_2304;
v_2305:
    goto v_2306;
v_2307:
    v_3060 = Lappend(nil, v_3061, v_3060);
    env = stack[-3];
    v_3060 = CC_find(elt(env, 0), v_3060);
    goto v_2289;
v_2290:
    goto v_2286;
v_2287:
    goto v_2288;
v_2289:
    {
        LispObject v_3073 = stack[0];
        return Lappend(nil, v_3073, v_3060);
    }
v_2275:
    goto v_2321;
v_2317:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    stack[0] = CC_find(elt(env, 0), v_3060);
    env = stack[-3];
    goto v_2318;
v_2319:
    goto v_2332;
v_2328:
    v_3060 = elt(env, 9); // plus
    v_3061 = ncons(v_3060);
    env = stack[-3];
    goto v_2329;
v_2330:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    goto v_2331;
v_2332:
    goto v_2328;
v_2329:
    goto v_2330;
v_2331:
    v_3060 = Lappend(nil, v_3061, v_3060);
    env = stack[-3];
    v_3060 = CC_find(elt(env, 0), v_3060);
    goto v_2320;
v_2321:
    goto v_2317;
v_2318:
    goto v_2319;
v_2320:
    {
        LispObject v_3074 = stack[0];
        return Lappend(nil, v_3074, v_3060);
    }
    goto v_2259;
v_2261:
    goto v_2345;
v_2341:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    stack[0] = CC_find(elt(env, 0), v_3060);
    env = stack[-3];
    goto v_2342;
v_2343:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = CC_find(elt(env, 0), v_3060);
    goto v_2344;
v_2345:
    goto v_2341;
v_2342:
    goto v_2343;
v_2344:
    {
        LispObject v_3075 = stack[0];
        return Lappend(nil, v_3075, v_3060);
    }
v_2259:
    goto v_2240;
v_2242:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = Lconsp(nil, v_3060);
    env = stack[-3];
    if (v_3060 == nil) goto v_2360;
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = Lconsp(nil, v_3060);
    env = stack[-3];
    if (v_3060 == nil) goto v_2360;
    goto v_2381;
v_2377:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = Llength(nil, v_3060);
    env = stack[-3];
    goto v_2378;
v_2379:
    v_3060 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_2380;
v_2381:
    goto v_2377;
v_2378:
    goto v_2379;
v_2380:
    v_3060 = (LispObject)greaterp2(v_3061, v_3060);
    v_3060 = v_3060 ? lisp_true : nil;
    env = stack[-3];
    if (v_3060 == nil) goto v_2375;
    goto v_2391;
v_2387:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    stack[0] = CC_find(elt(env, 0), v_3060);
    env = stack[-3];
    goto v_2388;
v_2389:
    goto v_2402;
v_2398:
    v_3060 = elt(env, 9); // plus
    v_3061 = ncons(v_3060);
    env = stack[-3];
    goto v_2399;
v_2400:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    goto v_2401;
v_2402:
    goto v_2398;
v_2399:
    goto v_2400;
v_2401:
    v_3060 = Lappend(nil, v_3061, v_3060);
    env = stack[-3];
    v_3060 = CC_find(elt(env, 0), v_3060);
    goto v_2390;
v_2391:
    goto v_2387;
v_2388:
    goto v_2389;
v_2390:
    {
        LispObject v_3076 = stack[0];
        return Lappend(nil, v_3076, v_3060);
    }
v_2375:
    goto v_2415;
v_2411:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    stack[0] = CC_find(elt(env, 0), v_3060);
    env = stack[-3];
    goto v_2412;
v_2413:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = CC_find(elt(env, 0), v_3060);
    goto v_2414;
v_2415:
    goto v_2411;
v_2412:
    goto v_2413;
v_2414:
    {
        LispObject v_3077 = stack[0];
        return Lappend(nil, v_3077, v_3060);
    }
    goto v_2358;
v_2360:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = Lconsp(nil, v_3060);
    env = stack[-3];
    if (v_3060 == nil) goto v_2430;
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    if (!consp(v_3060)) goto v_2436;
    else goto v_2430;
v_2436:
    goto v_2450;
v_2446:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = Llength(nil, v_3060);
    env = stack[-3];
    goto v_2447;
v_2448:
    v_3060 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_2449;
v_2450:
    goto v_2446;
v_2447:
    goto v_2448;
v_2449:
    v_3060 = (LispObject)greaterp2(v_3061, v_3060);
    v_3060 = v_3060 ? lisp_true : nil;
    env = stack[-3];
    if (v_3060 == nil) goto v_2444;
    goto v_2463;
v_2459:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_2460;
v_2461:
    v_3060 = elt(env, 4); // ww
    goto v_2462;
v_2463:
    goto v_2459;
v_2460:
    goto v_2461;
v_2462:
    if (v_3061 == v_3060) goto v_2457;
    else goto v_2458;
v_2457:
    goto v_2476;
v_2470:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    stack[-2] = CC_find(elt(env, 0), v_3060);
    env = stack[-3];
    goto v_2471;
v_2472:
    goto v_2488;
v_2482:
    v_3062 = elt(env, 8); // expt
    goto v_2483;
v_2484:
    v_3061 = elt(env, 4); // ww
    goto v_2485;
v_2486:
    v_3060 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2487;
v_2488:
    goto v_2482;
v_2483:
    goto v_2484;
v_2485:
    goto v_2486;
v_2487:
    stack[0] = list3(v_3062, v_3061, v_3060);
    env = stack[-3];
    goto v_2473;
v_2474:
    goto v_2498;
v_2494:
    v_3060 = elt(env, 9); // plus
    v_3061 = ncons(v_3060);
    env = stack[-3];
    goto v_2495;
v_2496:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    goto v_2497;
v_2498:
    goto v_2494;
v_2495:
    goto v_2496;
v_2497:
    v_3060 = Lappend(nil, v_3061, v_3060);
    env = stack[-3];
    v_3060 = CC_find(elt(env, 0), v_3060);
    goto v_2475;
v_2476:
    goto v_2470;
v_2471:
    goto v_2472;
v_2473:
    goto v_2474;
v_2475:
    {
        LispObject v_3078 = stack[-2];
        LispObject v_3079 = stack[0];
        return list2star(v_3078, v_3079, v_3060);
    }
v_2458:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    if (is_number(v_3060)) goto v_2508;
    else goto v_2509;
v_2508:
    goto v_2521;
v_2515:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    stack[-2] = CC_find(elt(env, 0), v_3060);
    env = stack[-3];
    goto v_2516;
v_2517:
    goto v_2531;
v_2527:
    v_3061 = elt(env, 5); // number
    goto v_2528;
v_2529:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    goto v_2530;
v_2531:
    goto v_2527;
v_2528:
    goto v_2529;
v_2530:
    stack[0] = list2(v_3061, v_3060);
    env = stack[-3];
    goto v_2518;
v_2519:
    goto v_2543;
v_2539:
    v_3060 = elt(env, 9); // plus
    v_3061 = ncons(v_3060);
    env = stack[-3];
    goto v_2540;
v_2541:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    goto v_2542;
v_2543:
    goto v_2539;
v_2540:
    goto v_2541;
v_2542:
    v_3060 = Lappend(nil, v_3061, v_3060);
    env = stack[-3];
    v_3060 = CC_find(elt(env, 0), v_3060);
    goto v_2520;
v_2521:
    goto v_2515;
v_2516:
    goto v_2517;
v_2518:
    goto v_2519;
v_2520:
    {
        LispObject v_3080 = stack[-2];
        LispObject v_3081 = stack[0];
        return list2star(v_3080, v_3081, v_3060);
    }
v_2509:
    goto v_2507;
v_2507:
    goto v_2456;
v_2456:
    goto v_2442;
v_2444:
    goto v_2558;
v_2554:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    stack[0] = CC_find(elt(env, 0), v_3060);
    env = stack[-3];
    goto v_2555;
v_2556:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = CC_find(elt(env, 0), v_3060);
    goto v_2557;
v_2558:
    goto v_2554;
v_2555:
    goto v_2556;
v_2557:
    {
        LispObject v_3082 = stack[0];
        return Lappend(nil, v_3082, v_3060);
    }
v_2442:
    goto v_2428;
v_2430:
    goto v_2575;
v_2571:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    stack[0] = CC_find(elt(env, 0), v_3060);
    env = stack[-3];
    goto v_2572;
v_2573:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = ncons(v_3060);
    goto v_2574;
v_2575:
    goto v_2571;
v_2572:
    goto v_2573;
v_2574:
    {
        LispObject v_3083 = stack[0];
        return Lappend(nil, v_3083, v_3060);
    }
v_2428:
    goto v_2358;
v_2358:
    goto v_2240;
v_2240:
    goto v_1990;
v_1990:
    goto v_1978;
v_1980:
    goto v_2595;
v_2591:
    v_3060 = stack[-1];
    v_3061 = qcar(v_3060);
    goto v_2592;
v_2593:
    v_3060 = elt(env, 10); // lminus
    goto v_2594;
v_2595:
    goto v_2591;
v_2592:
    goto v_2593;
v_2594:
    if (v_3061 == v_3060) goto v_2589;
    else goto v_2590;
v_2589:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    if (is_number(v_3060)) goto v_2601;
    else goto v_2602;
v_2601:
    goto v_2611;
v_2607:
    v_3061 = elt(env, 5); // number
    goto v_2608;
v_2609:
    v_3060 = stack[-1];
    goto v_2610;
v_2611:
    goto v_2607;
v_2608:
    goto v_2609;
v_2610:
    return list2(v_3061, v_3060);
v_2602:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    stack[-1] = v_3060;
    goto v_1856;
    goto v_2588;
v_2590:
    goto v_2630;
v_2626:
    v_3060 = stack[-1];
    v_3061 = qcar(v_3060);
    goto v_2627;
v_2628:
    v_3060 = elt(env, 11); // quotient
    goto v_2629;
v_2630:
    goto v_2626;
v_2627:
    goto v_2628;
v_2629:
    if (v_3061 == v_3060) goto v_2624;
    else goto v_2625;
v_2624:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    if (is_number(v_3060)) goto v_2638;
    else goto v_2637;
v_2638:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    if (is_number(v_3060)) goto v_2642;
    else goto v_2637;
v_2642:
    goto v_2654;
v_2648:
    v_3062 = elt(env, 5); // number
    goto v_2649;
v_2650:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_2651;
v_2652:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    goto v_2653;
v_2654:
    goto v_2648;
v_2649:
    goto v_2650;
v_2651:
    goto v_2652;
v_2653:
    return list3(v_3062, v_3061, v_3060);
v_2637:
    goto v_2670;
v_2666:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    stack[0] = CC_find(elt(env, 0), v_3060);
    env = stack[-3];
    goto v_2667;
v_2668:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = CC_find(elt(env, 0), v_3060);
    goto v_2669;
v_2670:
    goto v_2666;
v_2667:
    goto v_2668;
v_2669:
    {
        LispObject v_3084 = stack[0];
        return Lappend(nil, v_3084, v_3060);
    }
    goto v_2623;
v_2625:
    goto v_2690;
v_2686:
    v_3060 = stack[-1];
    v_3061 = qcar(v_3060);
    goto v_2687;
v_2688:
    v_3060 = elt(env, 12); // minus
    goto v_2689;
v_2690:
    goto v_2686;
v_2687:
    goto v_2688;
v_2689:
    if (v_3061 == v_3060) goto v_2684;
    else goto v_2685;
v_2684:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    if (!consp(v_3060)) goto v_2696;
    else goto v_2697;
v_2696:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    stack[-1] = v_3060;
    goto v_1856;
v_2697:
    goto v_2718;
v_2714:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_2715;
v_2716:
    v_3060 = elt(env, 8); // expt
    goto v_2717;
v_2718:
    goto v_2714;
v_2715:
    goto v_2716;
v_2717:
    if (v_3061 == v_3060) goto v_2712;
    else goto v_2713;
v_2712:
    goto v_2727;
v_2723:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_2724;
v_2725:
    v_3060 = elt(env, 4); // ww
    goto v_2726;
v_2727:
    goto v_2723;
v_2724:
    goto v_2725;
v_2726:
    v_3060 = (v_3061 == v_3060 ? lisp_true : nil);
    goto v_2711;
v_2713:
    v_3060 = nil;
    goto v_2711;
    v_3060 = nil;
v_2711:
    if (v_3060 == nil) goto v_2709;
    goto v_2742;
v_2738:
    goto v_2748;
v_2744:
    v_3060 = elt(env, 12); // minus
    stack[0] = ncons(v_3060);
    env = stack[-3];
    goto v_2745;
v_2746:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = CC_find(elt(env, 0), v_3060);
    env = stack[-3];
    goto v_2747;
v_2748:
    goto v_2744;
v_2745:
    goto v_2746;
v_2747:
    stack[0] = Lappend(nil, stack[0], v_3060);
    env = stack[-3];
    goto v_2739;
v_2740:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = CC_find(elt(env, 0), v_3060);
    goto v_2741;
v_2742:
    goto v_2738;
v_2739:
    goto v_2740;
v_2741:
    {
        LispObject v_3085 = stack[0];
        return Lappend(nil, v_3085, v_3060);
    }
v_2709:
    goto v_2767;
v_2763:
    v_3060 = elt(env, 12); // minus
    stack[0] = ncons(v_3060);
    env = stack[-3];
    goto v_2764;
v_2765:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = CC_find(elt(env, 0), v_3060);
    goto v_2766;
v_2767:
    goto v_2763;
v_2764:
    goto v_2765;
v_2766:
    {
        LispObject v_3086 = stack[0];
        return Lappend(nil, v_3086, v_3060);
    }
    goto v_2695;
v_2695:
    goto v_2683;
v_2685:
    goto v_2784;
v_2780:
    v_3060 = stack[-1];
    v_3061 = qcar(v_3060);
    goto v_2781;
v_2782:
    v_3060 = elt(env, 13); // times
    goto v_2783;
v_2784:
    goto v_2780;
v_2781:
    goto v_2782;
v_2783:
    if (v_3061 == v_3060) goto v_2778;
    else goto v_2779;
v_2778:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    if (!consp(v_3060)) goto v_2794;
    else goto v_2795;
v_2794:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = (consp(v_3060) ? nil : lisp_true);
    goto v_2793;
v_2795:
    v_3060 = nil;
    goto v_2793;
    v_3060 = nil;
v_2793:
    if (v_3060 == nil) goto v_2791;
    goto v_2816;
v_2812:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_2813;
v_2814:
    v_3060 = elt(env, 4); // ww
    goto v_2815;
v_2816:
    goto v_2812;
v_2813:
    goto v_2814;
v_2815:
    fn = elt(env, 15); // freeof
    v_3060 = (*qfn2(fn))(fn, v_3061, v_3060);
    env = stack[-3];
    if (v_3060 == nil) goto v_2809;
    else goto v_2810;
v_2809:
    goto v_2828;
v_2822:
    v_3062 = elt(env, 8); // expt
    goto v_2823;
v_2824:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_2825;
v_2826:
    v_3060 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2827;
v_2828:
    goto v_2822;
v_2823:
    goto v_2824;
v_2825:
    goto v_2826;
v_2827:
    return list3(v_3062, v_3061, v_3060);
v_2810:
    goto v_2845;
v_2841:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_2842;
v_2843:
    v_3060 = elt(env, 4); // ww
    goto v_2844;
v_2845:
    goto v_2841;
v_2842:
    goto v_2843;
v_2844:
    fn = elt(env, 15); // freeof
    v_3060 = (*qfn2(fn))(fn, v_3061, v_3060);
    if (v_3060 == nil) goto v_2838;
    else goto v_2839;
v_2838:
    goto v_2856;
v_2852:
    v_3061 = nil;
    goto v_2853;
v_2854:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    goto v_2855;
v_2856:
    goto v_2852;
v_2853:
    goto v_2854;
v_2855:
    return list2(v_3061, v_3060);
v_2839:
    goto v_2837;
v_2837:
    goto v_2808;
v_2808:
    goto v_2789;
v_2791:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    if (!consp(v_3060)) goto v_2873;
    else goto v_2874;
v_2873:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = Lconsp(nil, v_3060);
    env = stack[-3];
    goto v_2872;
v_2874:
    v_3060 = nil;
    goto v_2872;
    v_3060 = nil;
v_2872:
    if (v_3060 == nil) goto v_2870;
    goto v_2895;
v_2891:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_2892;
v_2893:
    v_3060 = elt(env, 4); // ww
    goto v_2894;
v_2895:
    goto v_2891;
v_2892:
    goto v_2893;
v_2894:
    fn = elt(env, 15); // freeof
    v_3060 = (*qfn2(fn))(fn, v_3061, v_3060);
    env = stack[-3];
    if (v_3060 == nil) goto v_2888;
    else goto v_2889;
v_2888:
    goto v_2907;
v_2901:
    v_3062 = elt(env, 8); // expt
    goto v_2902;
v_2903:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_2904;
v_2905:
    v_3060 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2906;
v_2907:
    goto v_2901;
v_2902:
    goto v_2903;
v_2904:
    goto v_2905;
v_2906:
    return list3(v_3062, v_3061, v_3060);
v_2889:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    stack[-1] = v_3060;
    goto v_1856;
    goto v_2868;
v_2870:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = Lconsp(nil, v_3060);
    env = stack[-3];
    if (v_3060 == nil) goto v_2925;
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = Lconsp(nil, v_3060);
    env = stack[-3];
    if (v_3060 == nil) goto v_2925;
    goto v_2946;
v_2942:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = Llength(nil, v_3060);
    env = stack[-3];
    goto v_2943;
v_2944:
    v_3060 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_2945;
v_2946:
    goto v_2942;
v_2943:
    goto v_2944;
v_2945:
    v_3060 = (LispObject)greaterp2(v_3061, v_3060);
    v_3060 = v_3060 ? lisp_true : nil;
    env = stack[-3];
    if (v_3060 == nil) goto v_2940;
    goto v_2956;
v_2952:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    stack[0] = CC_find(elt(env, 0), v_3060);
    env = stack[-3];
    goto v_2953;
v_2954:
    goto v_2967;
v_2963:
    v_3060 = elt(env, 13); // times
    v_3061 = ncons(v_3060);
    env = stack[-3];
    goto v_2964;
v_2965:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    goto v_2966;
v_2967:
    goto v_2963;
v_2964:
    goto v_2965;
v_2966:
    v_3060 = Lappend(nil, v_3061, v_3060);
    env = stack[-3];
    v_3060 = CC_find(elt(env, 0), v_3060);
    goto v_2955;
v_2956:
    goto v_2952;
v_2953:
    goto v_2954;
v_2955:
    {
        LispObject v_3087 = stack[0];
        return Lappend(nil, v_3087, v_3060);
    }
v_2940:
    goto v_2980;
v_2976:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    stack[0] = CC_find(elt(env, 0), v_3060);
    env = stack[-3];
    goto v_2977;
v_2978:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = CC_find(elt(env, 0), v_3060);
    goto v_2979;
v_2980:
    goto v_2976;
v_2977:
    goto v_2978;
v_2979:
    {
        LispObject v_3088 = stack[0];
        return Lappend(nil, v_3088, v_3060);
    }
    goto v_2923;
v_2925:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = Lconsp(nil, v_3060);
    env = stack[-3];
    if (v_3060 == nil) goto v_2995;
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    if (!consp(v_3060)) goto v_3001;
    else goto v_2995;
v_3001:
    goto v_3016;
v_3012:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_3013;
v_3014:
    v_3060 = elt(env, 4); // ww
    goto v_3015;
v_3016:
    goto v_3012;
v_3013:
    goto v_3014;
v_3015:
    fn = elt(env, 15); // freeof
    v_3060 = (*qfn2(fn))(fn, v_3061, v_3060);
    env = stack[-3];
    if (v_3060 == nil) goto v_3009;
    goto v_3026;
v_3022:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3061 = qcar(v_3060);
    goto v_3023;
v_3024:
    v_3060 = elt(env, 4); // ww
    goto v_3025;
v_3026:
    goto v_3022;
v_3023:
    goto v_3024;
v_3025:
    if (v_3061 == v_3060) goto v_3021;
    else goto v_3009;
v_3021:
    goto v_3039;
v_3033:
    v_3061 = elt(env, 8); // expt
    goto v_3034;
v_3035:
    v_3062 = elt(env, 4); // ww
    goto v_3036;
v_3037:
    v_3060 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3038;
v_3039:
    goto v_3033;
v_3034:
    goto v_3035;
v_3036:
    goto v_3037;
v_3038:
    return list3(v_3061, v_3062, v_3060);
v_3009:
    goto v_3050;
v_3046:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    stack[0] = CC_find(elt(env, 0), v_3060);
    env = stack[-3];
    goto v_3047;
v_3048:
    v_3060 = stack[-1];
    v_3060 = qcdr(v_3060);
    v_3060 = qcdr(v_3060);
    v_3060 = qcar(v_3060);
    v_3060 = CC_find(elt(env, 0), v_3060);
    goto v_3049;
v_3050:
    goto v_3046;
v_3047:
    goto v_3048;
v_3049:
    {
        LispObject v_3089 = stack[0];
        return Lappend(nil, v_3089, v_3060);
    }
    goto v_2993;
v_2995:
v_2993:
    goto v_2923;
v_2923:
    goto v_2868;
v_2868:
    goto v_2789;
v_2789:
    goto v_2777;
v_2779:
v_2777:
    goto v_2683;
v_2683:
    goto v_2623;
v_2623:
    goto v_2588;
v_2588:
    goto v_1978;
v_1978:
    goto v_1948;
v_1948:
    goto v_1871;
v_1871:
    v_3060 = nil;
    return onevalue(v_3060);
}



// Code for subscriptedvarp

static LispObject CC_subscriptedvarp(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1886, v_1887;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_1857;
// end of prologue
    goto v_1867;
v_1863:
    goto v_1874;
v_1870:
    v_1887 = nil;
    goto v_1871;
v_1872:
    v_1886 = stack[0];
    goto v_1873;
v_1874:
    goto v_1870;
v_1871:
    goto v_1872;
v_1873:
    fn = elt(env, 2); // symtabget
    v_1886 = (*qfn2(fn))(fn, v_1887, v_1886);
    env = stack[-1];
    v_1887 = Llength(nil, v_1886);
    env = stack[-1];
    goto v_1864;
v_1865:
    v_1886 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_1866;
v_1867:
    goto v_1863;
v_1864:
    goto v_1865;
v_1866:
    v_1886 = (LispObject)greaterp2(v_1887, v_1886);
    v_1886 = v_1886 ? lisp_true : nil;
    env = stack[-1];
    if (v_1886 == nil) goto v_1861;
    else goto v_1860;
v_1861:
    goto v_1883;
v_1879:
    v_1886 = stack[0];
    goto v_1880;
v_1881:
    v_1887 = elt(env, 1); // subscripted
    goto v_1882;
v_1883:
    goto v_1879;
v_1880:
    goto v_1881;
v_1882:
        return Lflagp(nil, v_1886, v_1887);
v_1860:
    return onevalue(v_1886);
}



// Code for exptchk

static LispObject CC_exptchk(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1921, v_1922, v_1923;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_1857;
// end of prologue
    v_1921 = stack[0];
    if (!consp(v_1921)) goto v_1865;
    else goto v_1866;
v_1865:
    v_1921 = lisp_true;
    goto v_1864;
v_1866:
    v_1921 = stack[0];
    v_1921 = qcar(v_1921);
    v_1921 = (consp(v_1921) ? nil : lisp_true);
    goto v_1864;
    v_1921 = nil;
v_1864:
    if (v_1921 == nil) goto v_1862;
    goto v_1879;
v_1875:
    v_1922 = stack[0];
    goto v_1876;
v_1877:
    v_1921 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1878;
v_1879:
    goto v_1875;
v_1876:
    goto v_1877;
v_1878:
    return cons(v_1922, v_1921);
v_1862:
    v_1921 = stack[0];
    fn = elt(env, 1); // comm_kernels
    v_1921 = (*qfn1(fn))(fn, v_1921);
    env = stack[-2];
    stack[-1] = v_1921;
    goto v_1896;
v_1892:
    v_1921 = stack[-1];
    v_1922 = Llength(nil, v_1921);
    env = stack[-2];
    goto v_1893;
v_1894:
    v_1921 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_1895;
v_1896:
    goto v_1892;
v_1893:
    goto v_1894;
v_1895:
    v_1921 = (LispObject)lessp2(v_1922, v_1921);
    v_1921 = v_1921 ? lisp_true : nil;
    env = stack[-2];
    if (v_1921 == nil) goto v_1890;
    goto v_1905;
v_1901:
    v_1922 = stack[0];
    goto v_1902;
v_1903:
    v_1921 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1904;
v_1905:
    goto v_1901;
v_1902:
    goto v_1903;
v_1904:
    return cons(v_1922, v_1921);
v_1890:
    goto v_1917;
v_1911:
    v_1923 = stack[0];
    goto v_1912;
v_1913:
    v_1922 = nil;
    goto v_1914;
v_1915:
    v_1921 = stack[-1];
    goto v_1916;
v_1917:
    goto v_1911;
v_1912:
    goto v_1913;
v_1914:
    goto v_1915;
v_1916:
    {
        fn = elt(env, 2); // exptchk0
        return (*qfnn(fn))(fn, 3, v_1923, v_1922, v_1921);
    }
    v_1921 = nil;
    goto v_1860;
    v_1921 = nil;
v_1860:
    return onevalue(v_1921);
}



// Code for freeindexchk

static LispObject CC_freeindexchk(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1875, v_1876;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_1876 = v_1857;
// end of prologue
    v_1875 = v_1876;
    if (v_1875 == nil) goto v_1862;
    v_1875 = qvalue(elt(env, 1)); // indxl!*
    if (v_1875 == nil) goto v_1862;
    v_1875 = v_1876;
    fn = elt(env, 3); // indxchk
    v_1875 = (*qfn1(fn))(fn, v_1875);
    env = stack[0];
    if (v_1875 == nil) goto v_1862;
    v_1875 = elt(env, 2); // form!-with!-free!-indices
    goto v_1860;
v_1862:
    v_1875 = nil;
    goto v_1860;
    v_1875 = nil;
v_1860:
    return onevalue(v_1875);
}



// Code for boundindp

static LispObject CC_boundindp(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1889, v_1890, v_1891, v_1892;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1890 = v_1858;
    v_1891 = v_1857;
// end of prologue
v_1862:
    v_1889 = v_1891;
    if (v_1889 == nil) goto v_1865;
    else goto v_1866;
v_1865:
    v_1889 = lisp_true;
    goto v_1861;
v_1866:
    goto v_1879;
v_1875:
    v_1889 = v_1891;
    v_1892 = qcar(v_1889);
    goto v_1876;
v_1877:
    v_1889 = v_1890;
    goto v_1878;
v_1879:
    goto v_1875;
v_1876:
    goto v_1877;
v_1878:
    v_1889 = Lmember(nil, v_1892, v_1889);
    if (v_1889 == nil) goto v_1874;
    v_1889 = v_1891;
    v_1889 = qcdr(v_1889);
    v_1891 = v_1889;
    goto v_1862;
v_1874:
    v_1889 = nil;
    goto v_1861;
    goto v_1864;
v_1864:
    v_1889 = nil;
v_1861:
    return onevalue(v_1889);
}



// Code for make!-set

static LispObject CC_makeKset(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1868, v_1869;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_1868 = v_1857;
// end of prologue
    goto v_1865;
v_1861:
    v_1869 = v_1868;
    goto v_1862;
v_1863:
    v_1868 = elt(env, 1); // set!-ordp
    goto v_1864;
v_1865:
    goto v_1861;
v_1862:
    goto v_1863;
v_1864:
    fn = elt(env, 2); // sort
    v_1868 = (*qfn2(fn))(fn, v_1869, v_1868);
    env = stack[0];
    {
        fn = elt(env, 3); // makelist
        return (*qfn1(fn))(fn, v_1868);
    }
}



// Code for chundexp

static LispObject CC_chundexp(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1936, v_1937;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_1857;
// end of prologue
    v_1936 = stack[-1];
    v_1936 = Lexplodec(nil, v_1936);
    env = stack[-3];
    stack[-1] = v_1936;
    v_1936 = stack[-1];
    stack[-2] = v_1936;
    goto v_1880;
v_1876:
    v_1937 = stack[-1];
    goto v_1877;
v_1878:
    v_1936 = elt(env, 1); // !_
    goto v_1879;
v_1880:
    goto v_1876;
v_1877:
    goto v_1878;
v_1879:
    if (!consp(v_1937)) goto v_1874;
    v_1937 = qcar(v_1937);
    if (v_1937 == v_1936) goto v_1873;
    else goto v_1874;
v_1873:
    v_1936 = stack[-1];
    v_1936 = qcdr(v_1936);
    goto v_1872;
v_1874:
    v_1936 = nil;
    goto v_1872;
    v_1936 = nil;
v_1872:
    if (v_1936 == nil) goto v_1870;
    goto v_1893;
v_1889:
    v_1937 = elt(env, 2); // !\ (backslash)
    goto v_1890;
v_1891:
    v_1936 = stack[-1];
    goto v_1892;
v_1893:
    goto v_1889;
v_1890:
    goto v_1891;
v_1892:
    v_1936 = cons(v_1937, v_1936);
    env = stack[-3];
    stack[-1] = v_1936;
    goto v_1868;
v_1870:
v_1868:
v_1862:
    v_1936 = stack[-2];
    v_1936 = qcdr(v_1936);
    if (v_1936 == nil) goto v_1898;
    else goto v_1899;
v_1898:
    goto v_1863;
v_1899:
    goto v_1910;
v_1906:
    v_1936 = stack[-2];
    v_1936 = qcdr(v_1936);
    v_1937 = qcar(v_1936);
    goto v_1907;
v_1908:
    v_1936 = elt(env, 1); // !_
    goto v_1909;
v_1910:
    goto v_1906;
v_1907:
    goto v_1908;
v_1909:
    if (v_1937 == v_1936) goto v_1904;
    else goto v_1905;
v_1904:
    goto v_1920;
v_1916:
    stack[0] = stack[-2];
    goto v_1917;
v_1918:
    goto v_1927;
v_1923:
    v_1937 = elt(env, 2); // !\ (backslash)
    goto v_1924;
v_1925:
    v_1936 = stack[-2];
    v_1936 = qcdr(v_1936);
    goto v_1926;
v_1927:
    goto v_1923;
v_1924:
    goto v_1925;
v_1926:
    v_1936 = cons(v_1937, v_1936);
    env = stack[-3];
    goto v_1919;
v_1920:
    goto v_1916;
v_1917:
    goto v_1918;
v_1919:
    v_1936 = Lrplacd(nil, stack[0], v_1936);
    env = stack[-3];
    v_1936 = stack[-2];
    v_1936 = qcdr(v_1936);
    stack[-2] = v_1936;
    goto v_1903;
v_1905:
v_1903:
    v_1936 = stack[-2];
    v_1936 = qcdr(v_1936);
    stack[-2] = v_1936;
    goto v_1862;
v_1863:
    v_1936 = stack[-1];
    return onevalue(v_1936);
}



// Code for physopp!*

static LispObject CC_physoppH(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1929, v_1930;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_1857;
// end of prologue
    v_1929 = stack[0];
    fn = elt(env, 4); // physopp
    v_1929 = (*qfn1(fn))(fn, v_1929);
    env = stack[-1];
    if (v_1929 == nil) goto v_1861;
    else goto v_1860;
v_1861:
    v_1929 = stack[0];
    if (!consp(v_1929)) goto v_1867;
    goto v_1878;
v_1874:
    v_1929 = stack[0];
    v_1930 = qcar(v_1929);
    goto v_1875;
v_1876:
    v_1929 = elt(env, 1); // physopfn
    goto v_1877;
v_1878:
    goto v_1874;
v_1875:
    goto v_1876;
v_1877:
    v_1929 = Lflagp(nil, v_1930, v_1929);
    env = stack[-1];
    if (v_1929 == nil) goto v_1872;
    v_1929 = lisp_true;
    goto v_1870;
v_1872:
    goto v_1897;
v_1893:
    v_1929 = stack[0];
    v_1930 = qcar(v_1929);
    goto v_1894;
v_1895:
    v_1929 = elt(env, 2); // physoparith
    goto v_1896;
v_1897:
    goto v_1893;
v_1894:
    goto v_1895;
v_1896:
    v_1929 = Lflagp(nil, v_1930, v_1929);
    env = stack[-1];
    if (v_1929 == nil) goto v_1891;
    v_1929 = stack[0];
    v_1929 = qcdr(v_1929);
    fn = elt(env, 5); // hasonephysop
    v_1929 = (*qfn1(fn))(fn, v_1929);
    env = stack[-1];
    goto v_1889;
v_1891:
    v_1929 = nil;
    goto v_1889;
    v_1929 = nil;
v_1889:
    if (v_1929 == nil) goto v_1887;
    else goto v_1886;
v_1887:
    goto v_1916;
v_1912:
    v_1929 = stack[0];
    v_1930 = qcar(v_1929);
    goto v_1913;
v_1914:
    v_1929 = elt(env, 3); // physopmapping
    goto v_1915;
v_1916:
    goto v_1912;
v_1913:
    goto v_1914;
v_1915:
    v_1929 = Lflagp(nil, v_1930, v_1929);
    env = stack[-1];
    if (v_1929 == nil) goto v_1910;
    v_1929 = stack[0];
    v_1929 = qcdr(v_1929);
    {
        fn = elt(env, 5); // hasonephysop
        return (*qfn1(fn))(fn, v_1929);
    }
v_1910:
    v_1929 = nil;
    goto v_1908;
    v_1929 = nil;
v_1908:
v_1886:
    goto v_1870;
    v_1929 = nil;
v_1870:
    goto v_1865;
v_1867:
    v_1929 = nil;
    goto v_1865;
    v_1929 = nil;
v_1865:
v_1860:
    return onevalue(v_1929);
}



// Code for getel

static LispObject CC_getel(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1912, v_1913, v_1914;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_1857;
// end of prologue
    goto v_1864;
v_1860:
    v_1912 = stack[-1];
    v_1913 = qcar(v_1912);
    goto v_1861;
v_1862:
    v_1912 = elt(env, 1); // dimension
    goto v_1863;
v_1864:
    goto v_1860;
v_1861:
    goto v_1862;
v_1863:
    v_1912 = get(v_1913, v_1912);
    env = stack[-3];
    stack[-2] = v_1912;
    goto v_1877;
v_1873:
    v_1912 = stack[-2];
    stack[0] = Llength(nil, v_1912);
    env = stack[-3];
    goto v_1874;
v_1875:
    v_1912 = stack[-1];
    v_1912 = qcdr(v_1912);
    v_1912 = Llength(nil, v_1912);
    env = stack[-3];
    goto v_1876;
v_1877:
    goto v_1873;
v_1874:
    goto v_1875;
v_1876:
    if (equal(stack[0], v_1912)) goto v_1872;
    goto v_1890;
v_1884:
    v_1914 = elt(env, 2); // rlisp
    goto v_1885;
v_1886:
    v_1913 = (LispObject)336+TAG_FIXNUM; // 21
    goto v_1887;
v_1888:
    v_1912 = elt(env, 3); // "Incorrect array reference"
    goto v_1889;
v_1890:
    goto v_1884;
v_1885:
    goto v_1886;
v_1887:
    goto v_1888;
v_1889:
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_1914, v_1913, v_1912);
    }
v_1872:
    goto v_1903;
v_1897:
    v_1912 = stack[-1];
    v_1912 = qcar(v_1912);
    if (!symbolp(v_1912)) v_1912 = nil;
    else { v_1912 = qfastgets(v_1912);
           if (v_1912 != nil) { v_1912 = elt(v_1912, 4); // avalue
#ifdef RECORD_GET
             if (v_1912 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_1912 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_1912 == SPID_NOPROP) v_1912 = nil; }}
#endif
    v_1912 = qcdr(v_1912);
    v_1914 = qcar(v_1912);
    goto v_1898;
v_1899:
    v_1912 = stack[-1];
    v_1913 = qcdr(v_1912);
    goto v_1900;
v_1901:
    v_1912 = stack[-2];
    goto v_1902;
v_1903:
    goto v_1897;
v_1898:
    goto v_1899;
v_1900:
    goto v_1901;
v_1902:
    {
        fn = elt(env, 5); // getel1
        return (*qfnn(fn))(fn, 3, v_1914, v_1913, v_1912);
    }
    v_1912 = nil;
    return onevalue(v_1912);
}



// Code for mo!=lexcomp

static LispObject CC_moMlexcomp(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1911, v_1912, v_1913, v_1914;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_1912 = v_1858;
    v_1913 = v_1857;
// end of prologue
v_1862:
    v_1911 = v_1913;
    if (v_1911 == nil) goto v_1865;
    else goto v_1866;
v_1865:
    v_1911 = v_1912;
    if (v_1911 == nil) goto v_1870;
    else goto v_1871;
v_1870:
    v_1911 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1861;
v_1871:
    v_1911 = elt(env, 1); // (0)
    v_1913 = v_1911;
    goto v_1862;
    goto v_1864;
v_1866:
    v_1911 = v_1912;
    if (v_1911 == nil) goto v_1877;
    else goto v_1878;
v_1877:
    v_1911 = elt(env, 1); // (0)
    v_1912 = v_1911;
    goto v_1862;
v_1878:
    goto v_1887;
v_1883:
    v_1911 = v_1913;
    v_1914 = qcar(v_1911);
    goto v_1884;
v_1885:
    v_1911 = v_1912;
    v_1911 = qcar(v_1911);
    goto v_1886;
v_1887:
    goto v_1883;
v_1884:
    goto v_1885;
v_1886:
    if (equal(v_1914, v_1911)) goto v_1881;
    else goto v_1882;
v_1881:
    v_1911 = v_1913;
    v_1911 = qcdr(v_1911);
    v_1913 = v_1911;
    v_1911 = v_1912;
    v_1911 = qcdr(v_1911);
    v_1912 = v_1911;
    goto v_1862;
v_1882:
    goto v_1902;
v_1898:
    v_1911 = v_1913;
    v_1911 = qcar(v_1911);
    goto v_1899;
v_1900:
    v_1912 = qcar(v_1912);
    goto v_1901;
v_1902:
    goto v_1898;
v_1899:
    goto v_1900;
v_1901:
    if (((intptr_t)(v_1911)) > ((intptr_t)(v_1912))) goto v_1896;
    else goto v_1897;
v_1896:
    v_1911 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_1861;
v_1897:
    v_1911 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_1861;
v_1864:
    v_1911 = nil;
v_1861:
    return onevalue(v_1911);
}



// Code for gperm

static LispObject CC_gperm(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1931, v_1932;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_1857;
// end of prologue
    stack[-1] = nil;
v_1864:
    goto v_1874;
v_1870:
    v_1932 = stack[0];
    goto v_1871;
v_1872:
    v_1931 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_1873;
v_1874:
    goto v_1870;
v_1871:
    goto v_1872;
v_1873:
    v_1931 = (LispObject)greaterp2(v_1932, v_1931);
    v_1931 = v_1931 ? lisp_true : nil;
    env = stack[-4];
    if (v_1931 == nil) goto v_1867;
    else goto v_1868;
v_1867:
    goto v_1863;
v_1868:
    goto v_1883;
v_1879:
    v_1932 = stack[0];
    goto v_1880;
v_1881:
    v_1931 = stack[-1];
    goto v_1882;
v_1883:
    goto v_1879;
v_1880:
    goto v_1881;
v_1882:
    v_1931 = cons(v_1932, v_1931);
    env = stack[-4];
    stack[-1] = v_1931;
    v_1931 = stack[0];
    v_1931 = sub1(v_1931);
    env = stack[-4];
    stack[0] = v_1931;
    goto v_1864;
v_1863:
    v_1931 = stack[-1];
    fn = elt(env, 1); // gperm0
    v_1931 = (*qfn1(fn))(fn, v_1931);
    env = stack[-4];
    stack[-3] = v_1931;
    v_1931 = stack[-3];
    if (v_1931 == nil) goto v_1898;
    else goto v_1899;
v_1898:
    v_1931 = nil;
    goto v_1892;
v_1899:
    v_1931 = stack[-3];
    v_1931 = qcar(v_1931);
    fn = elt(env, 2); // pkp
    v_1931 = (*qfn1(fn))(fn, v_1931);
    env = stack[-4];
    v_1931 = ncons(v_1931);
    env = stack[-4];
    stack[-1] = v_1931;
    stack[-2] = v_1931;
v_1893:
    v_1931 = stack[-3];
    v_1931 = qcdr(v_1931);
    stack[-3] = v_1931;
    v_1931 = stack[-3];
    if (v_1931 == nil) goto v_1912;
    else goto v_1913;
v_1912:
    v_1931 = stack[-2];
    goto v_1892;
v_1913:
    goto v_1921;
v_1917:
    stack[0] = stack[-1];
    goto v_1918;
v_1919:
    v_1931 = stack[-3];
    v_1931 = qcar(v_1931);
    fn = elt(env, 2); // pkp
    v_1931 = (*qfn1(fn))(fn, v_1931);
    env = stack[-4];
    v_1931 = ncons(v_1931);
    env = stack[-4];
    goto v_1920;
v_1921:
    goto v_1917;
v_1918:
    goto v_1919;
v_1920:
    v_1931 = Lrplacd(nil, stack[0], v_1931);
    env = stack[-4];
    v_1931 = stack[-1];
    v_1931 = qcdr(v_1931);
    stack[-1] = v_1931;
    goto v_1893;
v_1892:
    return onevalue(v_1931);
}



// Code for copy

static LispObject CC_copy(LispObject env,
                         LispObject v_1857)
{
    env = qenv(env);
    LispObject v_1890, v_1891;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_1857);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_1857;
// end of prologue
    stack[-1] = nil;
v_1862:
    v_1890 = stack[0];
    if (!consp(v_1890)) goto v_1865;
    else goto v_1866;
v_1865:
    goto v_1873;
v_1869:
    v_1891 = stack[-1];
    goto v_1870;
v_1871:
    v_1890 = stack[0];
    goto v_1872;
v_1873:
    goto v_1869;
v_1870:
    goto v_1871;
v_1872:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_1891, v_1890);
    }
v_1866:
    goto v_1883;
v_1879:
    v_1890 = stack[0];
    v_1890 = qcar(v_1890);
    v_1891 = CC_copy(elt(env, 0), v_1890);
    env = stack[-2];
    goto v_1880;
v_1881:
    v_1890 = stack[-1];
    goto v_1882;
v_1883:
    goto v_1879;
v_1880:
    goto v_1881;
v_1882:
    v_1890 = cons(v_1891, v_1890);
    env = stack[-2];
    stack[-1] = v_1890;
    v_1890 = stack[0];
    v_1890 = qcdr(v_1890);
    stack[0] = v_1890;
    goto v_1862;
    v_1890 = nil;
    return onevalue(v_1890);
}



// Code for general!-modular!-quotient

static LispObject CC_generalKmodularKquotient(LispObject env,
                         LispObject v_1857, LispObject v_1858)
{
    env = qenv(env);
    LispObject v_1869, v_1870;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_1858,v_1857);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_1857,v_1858);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_1869 = v_1858;
    v_1870 = v_1857;
// end of prologue
    goto v_1865;
v_1861:
    stack[0] = v_1870;
    goto v_1862;
v_1863:
    fn = elt(env, 1); // general!-modular!-reciprocal
    v_1869 = (*qfn1(fn))(fn, v_1869);
    env = stack[-1];
    goto v_1864;
v_1865:
    goto v_1861;
v_1862:
    goto v_1863;
v_1864:
    {
        LispObject v_1872 = stack[0];
        fn = elt(env, 2); // general!-modular!-times
        return (*qfn2(fn))(fn, v_1872, v_1869);
    }
}



setup_type const u06_setup[] =
{
    {"pnthxzz",                 TOO_FEW_2,      CC_pnthxzz,    WRONG_NO_2},
    {"rd:onep",                 CC_rdTonep,     TOO_MANY_1,    WRONG_NO_1},
    {"atomf",                   CC_atomf,       TOO_MANY_1,    WRONG_NO_1},
    {"mknwedge",                CC_mknwedge,    TOO_MANY_1,    WRONG_NO_1},
    {"putpline",                CC_putpline,    TOO_MANY_1,    WRONG_NO_1},
    {"int-equiv-chk",           CC_intKequivKchk,TOO_MANY_1,   WRONG_NO_1},
    {"dp=ecart",                CC_dpMecart,    TOO_MANY_1,    WRONG_NO_1},
    {"gperm1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gperm1},
    {"mkrn",                    TOO_FEW_2,      CC_mkrn,       WRONG_NO_2},
    {"evaluate-in-order",       TOO_FEW_2,      CC_evaluateKinKorder,WRONG_NO_2},
    {"set_svf",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_set_svf},
    {"freeofdepl",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_freeofdepl},
    {"rl_smmkatl",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rl_smmkatl},
    {"mri_0mk2",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mri_0mk2},
    {"cgp_evlmon",              CC_cgp_evlmon,  TOO_MANY_1,    WRONG_NO_1},
    {"sortcolelem",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_sortcolelem},
    {"fast-column-dim",         CC_fastKcolumnKdim,TOO_MANY_1, WRONG_NO_1},
    {"evtdeg",                  CC_evtdeg,      TOO_MANY_1,    WRONG_NO_1},
    {"algid",                   TOO_FEW_2,      CC_algid,      WRONG_NO_2},
    {"csl_timbf",               TOO_FEW_2,      CC_csl_timbf,  WRONG_NO_2},
    {"safe-fp-minus",           CC_safeKfpKminus,TOO_MANY_1,   WRONG_NO_1},
    {"getrmacro",               CC_getrmacro,   TOO_MANY_1,    WRONG_NO_1},
    {"getelv",                  CC_getelv,      TOO_MANY_1,    WRONG_NO_1},
    {"dp_diff",                 TOO_FEW_2,      CC_dp_diff,    WRONG_NO_2},
    {"tsym4",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_tsym4},
    {"clear-column",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_clearKcolumn},
    {"xread",                   CC_xread,       TOO_MANY_1,    WRONG_NO_1},
    {"sfto_gcdf*",              TOO_FEW_2,      CC_sfto_gcdfH, WRONG_NO_2},
    {"removev",                 TOO_FEW_2,      CC_removev,    WRONG_NO_2},
    {"qqe_prepat",              CC_qqe_prepat,  TOO_MANY_1,    WRONG_NO_1},
    {"pasf_susipost",           TOO_FEW_2,      CC_pasf_susipost,WRONG_NO_2},
    {"omobj",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_omobj},
    {"mk*sq",                   CC_mkHsq,       TOO_MANY_1,    WRONG_NO_1},
    {"comm_kernels",            CC_comm_kernels,TOO_MANY_1,    WRONG_NO_1},
    {":times",                  TOO_FEW_2,      CC_Ttimes,     WRONG_NO_2},
    {"areallindices",           CC_areallindices,TOO_MANY_1,   WRONG_NO_1},
    {"*ssave",                  TOO_FEW_2,      CC_Hssave,     WRONG_NO_2},
    {"red-weight",              TOO_FEW_2,      CC_redKweight, WRONG_NO_2},
    {"bc=simp",                 CC_bcMsimp,     TOO_MANY_1,    WRONG_NO_1},
    {"vecp",                    CC_vecp,        TOO_MANY_1,    WRONG_NO_1},
    {"pv_sort2a",               TOO_FEW_2,      CC_pv_sort2a,  WRONG_NO_2},
    {"times-mod-p",             TOO_FEW_2,      CC_timesKmodKp,WRONG_NO_2},
    {"gcddd",                   TOO_FEW_2,      CC_gcddd,      WRONG_NO_2},
    {"checkargcount",           TOO_FEW_2,      CC_checkargcount,WRONG_NO_2},
    {"wulessp",                 TOO_FEW_2,      CC_wulessp,    WRONG_NO_2},
    {"mcharg1",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mcharg1},
    {"talp_simplat1",           TOO_FEW_2,      CC_talp_simplat1,WRONG_NO_2},
    {"mri_type",                CC_mri_type,    TOO_MANY_1,    WRONG_NO_1},
    {"rl_simpat",               CC_rl_simpat,   TOO_MANY_1,    WRONG_NO_1},
    {"find",                    CC_find,        TOO_MANY_1,    WRONG_NO_1},
    {"subscriptedvarp",         CC_subscriptedvarp,TOO_MANY_1, WRONG_NO_1},
    {"exptchk",                 CC_exptchk,     TOO_MANY_1,    WRONG_NO_1},
    {"freeindexchk",            CC_freeindexchk,TOO_MANY_1,    WRONG_NO_1},
    {"boundindp",               TOO_FEW_2,      CC_boundindp,  WRONG_NO_2},
    {"make-set",                CC_makeKset,    TOO_MANY_1,    WRONG_NO_1},
    {"chundexp",                CC_chundexp,    TOO_MANY_1,    WRONG_NO_1},
    {"physopp*",                CC_physoppH,    TOO_MANY_1,    WRONG_NO_1},
    {"getel",                   CC_getel,       TOO_MANY_1,    WRONG_NO_1},
    {"mo=lexcomp",              TOO_FEW_2,      CC_moMlexcomp, WRONG_NO_2},
    {"gperm",                   CC_gperm,       TOO_MANY_1,    WRONG_NO_1},
    {"copy",                    CC_copy,        TOO_MANY_1,    WRONG_NO_1},
    {"general-modular-quotient",TOO_FEW_2,      CC_generalKmodularKquotient,WRONG_NO_2},
    {NULL, (one_args *)"u06", (two_args *)"101834 6864909 1361666", 0}
};

// end of generated code
