
// $destdir/u16.c        Machine generated C code

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



// Code for rread1

static LispObject CC_rread1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8615, v_8616, v_8617;
    LispObject fn;
    argcheck(nargs, 0, "rread1");
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
    fn = elt(env, 13); // ptoken
    v_8615 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_8615;
    goto v_8473;
v_8469:
    v_8616 = qvalue(elt(env, 1)); // ttype!*
    goto v_8470;
v_8471:
    v_8615 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_8472;
v_8473:
    goto v_8469;
v_8470:
    goto v_8471;
v_8472:
    if (v_8616 == v_8615) goto v_8468;
    v_8615 = stack[-1];
    if (symbolp(v_8615)) goto v_8478;
    else goto v_8479;
v_8478:
    v_8615 = qvalue(elt(env, 2)); // !*quotenewnam
    if (v_8615 == nil) goto v_8484;
    goto v_8493;
v_8489:
    v_8616 = stack[-1];
    goto v_8490;
v_8491:
    v_8615 = elt(env, 3); // quotenewnam
    goto v_8492;
v_8493:
    goto v_8489;
v_8490:
    goto v_8491;
v_8492:
    v_8615 = get(v_8616, v_8615);
    stack[0] = v_8615;
    if (v_8615 == nil) goto v_8484;
    v_8615 = stack[0];
    goto v_8482;
v_8484:
    v_8615 = stack[-1];
    goto v_8482;
    v_8615 = nil;
v_8482:
    goto v_8477;
v_8479:
    goto v_8507;
v_8503:
    v_8616 = stack[-1];
    goto v_8504;
v_8505:
    v_8615 = elt(env, 4); // !:dn!:
    goto v_8506;
v_8507:
    goto v_8503;
v_8504:
    goto v_8505;
v_8506:
    if (!consp(v_8616)) goto v_8501;
    v_8616 = qcar(v_8616);
    if (v_8616 == v_8615) goto v_8500;
    else goto v_8501;
v_8500:
    goto v_8517;
v_8511:
    v_8617 = stack[-1];
    goto v_8512;
v_8513:
    v_8616 = nil;
    goto v_8514;
v_8515:
    v_8615 = elt(env, 5); // symbolic
    goto v_8516;
v_8517:
    goto v_8511;
v_8512:
    goto v_8513;
v_8514:
    goto v_8515;
v_8516:
    {
        fn = elt(env, 14); // dnform
        return (*qfnn(fn))(fn, 3, v_8617, v_8616, v_8615);
    }
v_8501:
    v_8615 = stack[-1];
    goto v_8477;
    v_8615 = nil;
v_8477:
    goto v_8463;
v_8468:
    goto v_8530;
v_8526:
    v_8616 = stack[-1];
    goto v_8527;
v_8528:
    v_8615 = elt(env, 6); // !(
    goto v_8529;
v_8530:
    goto v_8526;
v_8527:
    goto v_8528;
v_8529:
    if (v_8616 == v_8615) goto v_8524;
    else goto v_8525;
v_8524:
    {
        fn = elt(env, 15); // rrdls
        return (*qfnn(fn))(fn, 0);
    }
v_8525:
    goto v_8544;
v_8540:
    v_8616 = stack[-1];
    goto v_8541;
v_8542:
    v_8615 = elt(env, 7); // !+
    goto v_8543;
v_8544:
    goto v_8540;
v_8541:
    goto v_8542;
v_8543:
    if (v_8616 == v_8615) goto v_8538;
    else goto v_8539;
v_8538:
    v_8615 = lisp_true;
    goto v_8537;
v_8539:
    goto v_8554;
v_8550:
    v_8616 = stack[-1];
    goto v_8551;
v_8552:
    v_8615 = elt(env, 8); // !-
    goto v_8553;
v_8554:
    goto v_8550;
v_8551:
    goto v_8552;
v_8553:
    v_8615 = (v_8616 == v_8615 ? lisp_true : nil);
    goto v_8537;
    v_8615 = nil;
v_8537:
    if (v_8615 == nil) goto v_8534;
    else goto v_8535;
v_8534:
    v_8615 = stack[-1];
    goto v_8463;
v_8535:
    fn = elt(env, 13); // ptoken
    v_8615 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[0] = v_8615;
    goto v_8569;
v_8565:
    v_8616 = stack[0];
    goto v_8566;
v_8567:
    v_8615 = elt(env, 4); // !:dn!:
    goto v_8568;
v_8569:
    goto v_8565;
v_8566:
    goto v_8567;
v_8568:
    if (!consp(v_8616)) goto v_8563;
    v_8616 = qcar(v_8616);
    if (v_8616 == v_8615) goto v_8562;
    else goto v_8563;
v_8562:
    goto v_8579;
v_8573:
    v_8617 = stack[0];
    goto v_8574;
v_8575:
    v_8616 = nil;
    goto v_8576;
v_8577:
    v_8615 = elt(env, 5); // symbolic
    goto v_8578;
v_8579:
    goto v_8573;
v_8574:
    goto v_8575;
v_8576:
    goto v_8577;
v_8578:
    fn = elt(env, 14); // dnform
    v_8615 = (*qfnn(fn))(fn, 3, v_8617, v_8616, v_8615);
    env = stack[-2];
    stack[0] = v_8615;
    goto v_8561;
v_8563:
v_8561:
    v_8615 = stack[0];
    if (is_number(v_8615)) goto v_8586;
    v_8615 = elt(env, 9); // " "
    qvalue(elt(env, 10)) = v_8615; // nxtsym!*
    goto v_8594;
v_8590:
    v_8616 = elt(env, 11); // "Syntax error: improper number"
    goto v_8591;
v_8592:
    v_8615 = nil;
    goto v_8593;
v_8594:
    goto v_8590;
v_8591:
    goto v_8592;
v_8593:
    fn = elt(env, 16); // symerr
    v_8615 = (*qfn2(fn))(fn, v_8616, v_8615);
    goto v_8584;
v_8586:
    goto v_8603;
v_8599:
    v_8616 = stack[-1];
    goto v_8600;
v_8601:
    v_8615 = elt(env, 8); // !-
    goto v_8602;
v_8603:
    goto v_8599;
v_8600:
    goto v_8601;
v_8602:
    if (v_8616 == v_8615) goto v_8597;
    else goto v_8598;
v_8597:
    goto v_8611;
v_8607:
    v_8616 = elt(env, 12); // minus
    goto v_8608;
v_8609:
    v_8615 = stack[0];
    goto v_8610;
v_8611:
    goto v_8607;
v_8608:
    goto v_8609;
v_8610:
    v_8615 = Lapply1(nil, v_8616, v_8615);
    stack[0] = v_8615;
    goto v_8584;
v_8598:
v_8584:
    v_8615 = stack[0];
v_8463:
    return onevalue(v_8615);
}



// Code for powers3

static LispObject CC_powers3(LispObject env,
                         LispObject v_8459, LispObject v_8460)
{
    env = qenv(env);
    LispObject v_8515, v_8516;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8460,v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8459,v_8460);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_8460;
    v_8515 = v_8459;
// end of prologue
v_8465:
    v_8516 = v_8515;
    if (!consp(v_8516)) goto v_8472;
    else goto v_8473;
v_8472:
    v_8516 = lisp_true;
    goto v_8471;
v_8473:
    v_8516 = v_8515;
    v_8516 = qcar(v_8516);
    v_8516 = (consp(v_8516) ? nil : lisp_true);
    goto v_8471;
    v_8516 = nil;
v_8471:
    if (v_8516 == nil) goto v_8469;
    v_8515 = stack[-1];
    goto v_8464;
v_8469:
    v_8516 = v_8515;
    v_8516 = qcar(v_8516);
    v_8516 = qcdr(v_8516);
    stack[-2] = v_8516;
    goto v_8494;
v_8488:
    v_8516 = v_8515;
    v_8516 = qcar(v_8516);
    v_8516 = qcar(v_8516);
    stack[0] = qcar(v_8516);
    goto v_8489;
v_8490:
    goto v_8504;
v_8500:
    v_8516 = v_8515;
    v_8516 = qcar(v_8516);
    v_8516 = qcar(v_8516);
    v_8516 = qcdr(v_8516);
    goto v_8501;
v_8502:
    v_8515 = qcar(v_8515);
    v_8515 = qcar(v_8515);
    v_8515 = qcdr(v_8515);
    goto v_8503;
v_8504:
    goto v_8500;
v_8501:
    goto v_8502;
v_8503:
    v_8516 = cons(v_8516, v_8515);
    env = stack[-3];
    goto v_8491;
v_8492:
    v_8515 = stack[-1];
    goto v_8493;
v_8494:
    goto v_8488;
v_8489:
    goto v_8490;
v_8491:
    goto v_8492;
v_8493:
    v_8515 = acons(stack[0], v_8516, v_8515);
    env = stack[-3];
    stack[-1] = v_8515;
    v_8515 = stack[-2];
    goto v_8465;
    v_8515 = nil;
v_8464:
    return onevalue(v_8515);
}



// Code for rsubla

static LispObject CC_rsubla(LispObject env,
                         LispObject v_8459, LispObject v_8460)
{
    env = qenv(env);
    LispObject v_8526, v_8527;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8460,v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8459,v_8460);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_8460;
    stack[-1] = v_8459;
// end of prologue
    v_8526 = stack[-1];
    if (v_8526 == nil) goto v_8471;
    else goto v_8472;
v_8471:
    v_8526 = lisp_true;
    goto v_8470;
v_8472:
    v_8526 = stack[0];
    v_8526 = (v_8526 == nil ? lisp_true : nil);
    goto v_8470;
    v_8526 = nil;
v_8470:
    if (v_8526 == nil) goto v_8468;
    v_8526 = stack[0];
    goto v_8464;
v_8468:
    v_8526 = stack[0];
    if (!consp(v_8526)) goto v_8480;
    else goto v_8481;
v_8480:
    goto v_8492;
v_8488:
    v_8527 = stack[0];
    goto v_8489;
v_8490:
    v_8526 = stack[-1];
    goto v_8491;
v_8492:
    goto v_8488;
v_8489:
    goto v_8490;
v_8491:
    fn = elt(env, 1); // rassoc
    v_8526 = (*qfn2(fn))(fn, v_8527, v_8526);
    v_8527 = v_8526;
    if (v_8526 == nil) goto v_8486;
    v_8526 = v_8527;
    v_8526 = qcar(v_8526);
    goto v_8484;
v_8486:
    v_8526 = stack[0];
    goto v_8484;
    v_8526 = nil;
v_8484:
    goto v_8464;
v_8481:
    goto v_8507;
v_8503:
    goto v_8513;
v_8509:
    v_8527 = stack[-1];
    goto v_8510;
v_8511:
    v_8526 = stack[0];
    v_8526 = qcar(v_8526);
    goto v_8512;
v_8513:
    goto v_8509;
v_8510:
    goto v_8511;
v_8512:
    stack[-2] = CC_rsubla(elt(env, 0), v_8527, v_8526);
    env = stack[-3];
    goto v_8504;
v_8505:
    goto v_8522;
v_8518:
    v_8527 = stack[-1];
    goto v_8519;
v_8520:
    v_8526 = stack[0];
    v_8526 = qcdr(v_8526);
    goto v_8521;
v_8522:
    goto v_8518;
v_8519:
    goto v_8520;
v_8521:
    v_8526 = CC_rsubla(elt(env, 0), v_8527, v_8526);
    goto v_8506;
v_8507:
    goto v_8503;
v_8504:
    goto v_8505;
v_8506:
    {
        LispObject v_8531 = stack[-2];
        return cons(v_8531, v_8526);
    }
    v_8526 = nil;
v_8464:
    return onevalue(v_8526);
}



// Code for qqe_id!-nyt!-branchq

static LispObject CC_qqe_idKnytKbranchq(LispObject env,
                         LispObject v_8459)
{
    env = qenv(env);
    LispObject v_8484;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8459);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_8459;
// end of prologue
    v_8484 = stack[0];
    if (!consp(v_8484)) goto v_8463;
    else goto v_8464;
v_8463:
    v_8484 = stack[0];
    fn = elt(env, 1); // qqe_qtidp
    v_8484 = (*qfn1(fn))(fn, v_8484);
    env = stack[-1];
    if (v_8484 == nil) goto v_8468;
    else goto v_8467;
v_8468:
    v_8484 = stack[0];
    {
        fn = elt(env, 2); // qqe_nytidp
        return (*qfn1(fn))(fn, v_8484);
    }
v_8467:
    goto v_8462;
v_8464:
    v_8484 = stack[0];
    v_8484 = qcar(v_8484);
    fn = elt(env, 3); // qqe_qopaddp
    v_8484 = (*qfn1(fn))(fn, v_8484);
    env = stack[-1];
    if (v_8484 == nil) goto v_8477;
    else goto v_8476;
v_8477:
    v_8484 = stack[0];
    v_8484 = qcar(v_8484);
    {
        fn = elt(env, 4); // qqe_qoptailp
        return (*qfn1(fn))(fn, v_8484);
    }
v_8476:
    goto v_8462;
    v_8484 = nil;
v_8462:
    return onevalue(v_8484);
}



// Code for setunion

static LispObject CC_setunion(LispObject env,
                         LispObject v_8459, LispObject v_8460)
{
    env = qenv(env);
    LispObject v_8498, v_8499, v_8500;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8460,v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8459,v_8460);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_8460;
    v_8499 = v_8459;
// end of prologue
v_8464:
    v_8498 = stack[0];
    if (v_8498 == nil) goto v_8467;
    else goto v_8468;
v_8467:
    v_8498 = v_8499;
    goto v_8463;
v_8468:
    goto v_8477;
v_8473:
    v_8498 = stack[0];
    v_8500 = qcar(v_8498);
    goto v_8474;
v_8475:
    v_8498 = v_8499;
    goto v_8476;
v_8477:
    goto v_8473;
v_8474:
    goto v_8475;
v_8476:
    v_8498 = Lmember(nil, v_8500, v_8498);
    if (v_8498 == nil) goto v_8472;
    v_8498 = stack[0];
    v_8498 = qcdr(v_8498);
    stack[0] = v_8498;
    goto v_8464;
v_8472:
    goto v_8491;
v_8487:
    stack[-1] = v_8499;
    goto v_8488;
v_8489:
    v_8498 = stack[0];
    v_8498 = qcar(v_8498);
    v_8498 = ncons(v_8498);
    env = stack[-2];
    goto v_8490;
v_8491:
    goto v_8487;
v_8488:
    goto v_8489;
v_8490:
    v_8498 = Lappend(nil, stack[-1], v_8498);
    env = stack[-2];
    v_8499 = v_8498;
    v_8498 = stack[0];
    v_8498 = qcdr(v_8498);
    stack[0] = v_8498;
    goto v_8464;
    v_8498 = nil;
v_8463:
    return onevalue(v_8498);
}



// Code for ibalp_redclause

static LispObject CC_ibalp_redclause(LispObject env,
                         LispObject v_8459)
{
    env = qenv(env);
    LispObject v_8498, v_8499;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8459);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_8459;
// end of prologue
    stack[0] = nil;
    v_8498 = stack[-1];
    v_8498 = qcar(v_8498);
    stack[-2] = v_8498;
v_8469:
    v_8498 = stack[-2];
    if (v_8498 == nil) goto v_8472;
    v_8498 = stack[0];
    if (v_8498 == nil) goto v_8476;
    else goto v_8472;
v_8476:
    goto v_8473;
v_8472:
    goto v_8468;
v_8473:
    goto v_8488;
v_8484:
    v_8498 = stack[-2];
    v_8499 = qcar(v_8498);
    goto v_8485;
v_8486:
    v_8498 = stack[-1];
    v_8498 = qcdr(v_8498);
    v_8498 = qcar(v_8498);
    goto v_8487;
v_8488:
    goto v_8484;
v_8485:
    goto v_8486;
v_8487:
    fn = elt(env, 1); // ibalp_vmember
    v_8498 = (*qfn2(fn))(fn, v_8499, v_8498);
    env = stack[-3];
    if (v_8498 == nil) goto v_8482;
    v_8498 = lisp_true;
    stack[0] = v_8498;
    goto v_8480;
v_8482:
v_8480:
    v_8498 = stack[-2];
    v_8498 = qcdr(v_8498);
    stack[-2] = v_8498;
    goto v_8469;
v_8468:
    v_8498 = stack[0];
    return onevalue(v_8498);
}



// Code for quotodd

static LispObject CC_quotodd(LispObject env,
                         LispObject v_8459, LispObject v_8460)
{
    env = qenv(env);
    LispObject v_8495, v_8496, v_8497;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8460,v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8459,v_8460);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_8496 = v_8460;
    v_8497 = v_8459;
// end of prologue
    v_8495 = v_8497;
    if (!consp(v_8495)) goto v_8468;
    else goto v_8469;
v_8468:
    v_8495 = v_8496;
    v_8495 = (consp(v_8495) ? nil : lisp_true);
    goto v_8467;
v_8469:
    v_8495 = nil;
    goto v_8467;
    v_8495 = nil;
v_8467:
    if (v_8495 == nil) goto v_8465;
    goto v_8482;
v_8478:
    v_8495 = v_8497;
    goto v_8479;
v_8480:
    goto v_8481;
v_8482:
    goto v_8478;
v_8479:
    goto v_8480;
v_8481:
    fn = elt(env, 1); // mkrn
    v_8495 = (*qfn2(fn))(fn, v_8495, v_8496);
    env = stack[0];
    {
        fn = elt(env, 2); // int!-equiv!-chk
        return (*qfn1(fn))(fn, v_8495);
    }
v_8465:
    goto v_8492;
v_8488:
    v_8495 = v_8497;
    goto v_8489;
v_8490:
    goto v_8491;
v_8492:
    goto v_8488;
v_8489:
    goto v_8490;
v_8491:
    {
        fn = elt(env, 3); // lowest!-terms
        return (*qfn2(fn))(fn, v_8495, v_8496);
    }
    v_8495 = nil;
    return onevalue(v_8495);
}



// Code for bsubs

static LispObject CC_bsubs(LispObject env,
                         LispObject v_8459)
{
    env = qenv(env);
    LispObject v_8525;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8459);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_8459;
// end of prologue
    v_8525 = stack[0];
    if (v_8525 == nil) goto v_8463;
    else goto v_8464;
v_8463:
    v_8525 = stack[0];
    goto v_8462;
v_8464:
    v_8525 = stack[0];
    if (!consp(v_8525)) goto v_8467;
    else goto v_8468;
v_8467:
    v_8525 = stack[0];
    fn = elt(env, 1); // bound
    v_8525 = (*qfn1(fn))(fn, v_8525);
    env = stack[-4];
    if (v_8525 == nil) goto v_8473;
    v_8525 = stack[0];
    {
        fn = elt(env, 2); // binding
        return (*qfn1(fn))(fn, v_8525);
    }
v_8473:
    v_8525 = stack[0];
    goto v_8471;
    v_8525 = nil;
v_8471:
    goto v_8462;
v_8468:
    v_8525 = stack[0];
    stack[-3] = v_8525;
    v_8525 = stack[-3];
    if (v_8525 == nil) goto v_8492;
    else goto v_8493;
v_8492:
    v_8525 = nil;
    goto v_8487;
v_8493:
    v_8525 = stack[-3];
    v_8525 = qcar(v_8525);
    v_8525 = CC_bsubs(elt(env, 0), v_8525);
    env = stack[-4];
    v_8525 = ncons(v_8525);
    env = stack[-4];
    stack[-1] = v_8525;
    stack[-2] = v_8525;
v_8488:
    v_8525 = stack[-3];
    v_8525 = qcdr(v_8525);
    stack[-3] = v_8525;
    v_8525 = stack[-3];
    if (v_8525 == nil) goto v_8506;
    else goto v_8507;
v_8506:
    v_8525 = stack[-2];
    goto v_8487;
v_8507:
    goto v_8515;
v_8511:
    stack[0] = stack[-1];
    goto v_8512;
v_8513:
    v_8525 = stack[-3];
    v_8525 = qcar(v_8525);
    v_8525 = CC_bsubs(elt(env, 0), v_8525);
    env = stack[-4];
    v_8525 = ncons(v_8525);
    env = stack[-4];
    goto v_8514;
v_8515:
    goto v_8511;
v_8512:
    goto v_8513;
v_8514:
    v_8525 = Lrplacd(nil, stack[0], v_8525);
    env = stack[-4];
    v_8525 = stack[-1];
    v_8525 = qcdr(v_8525);
    stack[-1] = v_8525;
    goto v_8488;
v_8487:
    goto v_8462;
    v_8525 = nil;
v_8462:
    return onevalue(v_8525);
}



// Code for dipilcomb1

static LispObject CC_dipilcomb1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8878, v_8879, v_8880;
    LispObject fn;
    LispObject v_8464, v_8463, v_8462, v_8461, v_8460, v_8459;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "dipilcomb1");
    va_start(aa, nargs);
    v_8459 = va_arg(aa, LispObject);
    v_8460 = va_arg(aa, LispObject);
    v_8461 = va_arg(aa, LispObject);
    v_8462 = va_arg(aa, LispObject);
    v_8463 = va_arg(aa, LispObject);
    v_8464 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_8464,v_8463,v_8462,v_8461,v_8460,v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_8459,v_8460,v_8461,v_8462,v_8463,v_8464);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(18);
// copy arguments values to proper place
    stack[-10] = v_8464;
    stack[-11] = v_8463;
    stack[-12] = v_8462;
    stack[-13] = v_8461;
    stack[-14] = v_8460;
    stack[-15] = v_8459;
// end of prologue
    v_8878 = qvalue(elt(env, 1)); // !*gcd
    stack[-1] = v_8878;
    stack[-16] = nil;
    stack[-9] = nil;
// Binding !*gcd
// FLUIDBIND: reloadenv=17 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-17, 1, 0);
    qvalue(elt(env, 1)) = nil; // !*gcd
    goto v_8496;
v_8492:
    v_8879 = stack[-14];
    goto v_8493;
v_8494:
    v_8878 = (LispObject)-1600+TAG_FIXNUM; // -100
    goto v_8495;
v_8496:
    goto v_8492;
v_8493:
    goto v_8494;
v_8495:
    fn = elt(env, 2); // vbcsize
    v_8878 = (*qfn2(fn))(fn, v_8879, v_8878);
    env = stack[-17];
    if (v_8878 == nil) goto v_8489;
    goto v_8505;
v_8501:
    v_8879 = stack[-11];
    goto v_8502;
v_8503:
    v_8878 = (LispObject)-1600+TAG_FIXNUM; // -100
    goto v_8504;
v_8505:
    goto v_8501;
v_8502:
    goto v_8503;
v_8504:
    fn = elt(env, 2); // vbcsize
    v_8878 = (*qfn2(fn))(fn, v_8879, v_8878);
    env = stack[-17];
    if (v_8878 == nil) goto v_8489;
    v_8878 = stack[-1];
    goto v_8487;
v_8489:
    v_8878 = nil;
v_8487:
    qvalue(elt(env, 1)) = v_8878; // !*gcd
    v_8878 = stack[-13];
    fn = elt(env, 3); // evzero!?
    v_8878 = (*qfn1(fn))(fn, v_8878);
    env = stack[-17];
    v_8878 = (v_8878 == nil ? lisp_true : nil);
    stack[-7] = v_8878;
    v_8878 = stack[-10];
    fn = elt(env, 3); // evzero!?
    v_8878 = (*qfn1(fn))(fn, v_8878);
    env = stack[-17];
    v_8878 = (v_8878 == nil ? lisp_true : nil);
    stack[-6] = v_8878;
    v_8878 = lisp_true;
    stack[-4] = v_8878;
    stack[-5] = v_8878;
    v_8878 = nil;
    stack[-8] = v_8878;
    stack[-2] = v_8878;
    stack[-3] = v_8878;
v_8485:
    v_8878 = stack[-5];
    if (v_8878 == nil) goto v_8520;
    v_8878 = stack[-15];
    if (v_8878 == nil) goto v_8524;
    else goto v_8525;
v_8524:
    v_8878 = stack[-12];
    if (v_8878 == nil) goto v_8529;
    else goto v_8530;
v_8529:
    v_8878 = stack[-8];
    goto v_8528;
v_8530:
    goto v_8540;
v_8536:
    stack[-1] = stack[-8];
    goto v_8537;
v_8538:
    goto v_8547;
v_8543:
    stack[-2] = stack[-12];
    goto v_8544;
v_8545:
    goto v_8556;
v_8550:
    v_8880 = stack[-10];
    goto v_8551;
v_8552:
    v_8879 = stack[-11];
    goto v_8553;
v_8554:
    v_8878 = nil;
    goto v_8555;
v_8556:
    goto v_8550;
v_8551:
    goto v_8552;
v_8553:
    goto v_8554;
v_8555:
    v_8878 = list2star(v_8880, v_8879, v_8878);
    env = stack[-17];
    goto v_8546;
v_8547:
    goto v_8543;
v_8544:
    goto v_8545;
v_8546:
    fn = elt(env, 4); // dipprod
    v_8878 = (*qfn2(fn))(fn, stack[-2], v_8878);
    env = stack[-17];
    goto v_8539;
v_8540:
    goto v_8536;
v_8537:
    goto v_8538;
v_8539:
    v_8878 = Lnconc(nil, stack[-1], v_8878);
    goto v_8528;
    v_8878 = nil;
v_8528:
    goto v_8484;
v_8525:
    v_8878 = stack[-15];
    v_8878 = qcar(v_8878);
    stack[-16] = v_8878;
    v_8878 = stack[-7];
    if (v_8878 == nil) goto v_8565;
    goto v_8572;
v_8568:
    v_8879 = stack[-16];
    goto v_8569;
v_8570:
    v_8878 = stack[-13];
    goto v_8571;
v_8572:
    goto v_8568;
v_8569:
    goto v_8570;
v_8571:
    fn = elt(env, 5); // evsum
    v_8878 = (*qfn2(fn))(fn, v_8879, v_8878);
    env = stack[-17];
    stack[-16] = v_8878;
    goto v_8563;
v_8565:
v_8563:
    v_8878 = nil;
    stack[-5] = v_8878;
    goto v_8518;
v_8520:
v_8518:
    v_8878 = stack[-4];
    if (v_8878 == nil) goto v_8579;
    v_8878 = stack[-12];
    if (v_8878 == nil) goto v_8583;
    else goto v_8584;
v_8583:
    goto v_8591;
v_8587:
    stack[-1] = stack[-8];
    goto v_8588;
v_8589:
    goto v_8598;
v_8594:
    stack[-2] = stack[-15];
    goto v_8595;
v_8596:
    goto v_8607;
v_8601:
    v_8880 = stack[-13];
    goto v_8602;
v_8603:
    v_8879 = stack[-14];
    goto v_8604;
v_8605:
    v_8878 = nil;
    goto v_8606;
v_8607:
    goto v_8601;
v_8602:
    goto v_8603;
v_8604:
    goto v_8605;
v_8606:
    v_8878 = list2star(v_8880, v_8879, v_8878);
    env = stack[-17];
    goto v_8597;
v_8598:
    goto v_8594;
v_8595:
    goto v_8596;
v_8597:
    fn = elt(env, 4); // dipprod
    v_8878 = (*qfn2(fn))(fn, stack[-2], v_8878);
    env = stack[-17];
    goto v_8590;
v_8591:
    goto v_8587;
v_8588:
    goto v_8589;
v_8590:
    v_8878 = Lnconc(nil, stack[-1], v_8878);
    goto v_8484;
v_8584:
    v_8878 = stack[-12];
    v_8878 = qcar(v_8878);
    stack[-9] = v_8878;
    v_8878 = stack[-6];
    if (v_8878 == nil) goto v_8616;
    goto v_8623;
v_8619:
    v_8879 = stack[-9];
    goto v_8620;
v_8621:
    v_8878 = stack[-10];
    goto v_8622;
v_8623:
    goto v_8619;
v_8620:
    goto v_8621;
v_8622:
    fn = elt(env, 5); // evsum
    v_8878 = (*qfn2(fn))(fn, v_8879, v_8878);
    env = stack[-17];
    stack[-9] = v_8878;
    goto v_8614;
v_8616:
v_8614:
    v_8878 = nil;
    stack[-4] = v_8878;
    goto v_8577;
v_8579:
v_8577:
    goto v_8632;
v_8628:
    v_8879 = stack[-16];
    goto v_8629;
v_8630:
    v_8878 = stack[-9];
    goto v_8631;
v_8632:
    goto v_8628;
v_8629:
    goto v_8630;
v_8631:
    fn = elt(env, 6); // evcomp
    v_8878 = (*qfn2(fn))(fn, v_8879, v_8878);
    env = stack[-17];
    v_8880 = v_8878;
    goto v_8643;
v_8639:
    v_8879 = v_8880;
    goto v_8640;
v_8641:
    v_8878 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8642;
v_8643:
    goto v_8639;
v_8640:
    goto v_8641;
v_8642:
    if (v_8879 == v_8878) goto v_8637;
    else goto v_8638;
v_8637:
    v_8878 = qvalue(elt(env, 1)); // !*gcd
    if (v_8878 == nil) goto v_8649;
    goto v_8658;
v_8654:
    v_8878 = stack[-15];
    v_8878 = qcdr(v_8878);
    v_8879 = qcar(v_8878);
    goto v_8655;
v_8656:
    v_8878 = (LispObject)-1600+TAG_FIXNUM; // -100
    goto v_8657;
v_8658:
    goto v_8654;
v_8655:
    goto v_8656;
v_8657:
    fn = elt(env, 2); // vbcsize
    v_8878 = (*qfn2(fn))(fn, v_8879, v_8878);
    env = stack[-17];
    if (v_8878 == nil) goto v_8652;
    else goto v_8649;
v_8652:
    v_8878 = nil;
    qvalue(elt(env, 1)) = v_8878; // !*gcd
    goto v_8647;
v_8649:
v_8647:
    goto v_8669;
v_8665:
    v_8878 = stack[-15];
    v_8878 = qcdr(v_8878);
    v_8879 = qcar(v_8878);
    goto v_8666;
v_8667:
    v_8878 = stack[-14];
    goto v_8668;
v_8669:
    goto v_8665;
v_8666:
    goto v_8667;
v_8668:
    fn = elt(env, 7); // bcprod
    v_8878 = (*qfn2(fn))(fn, v_8879, v_8878);
    env = stack[-17];
    stack[-1] = v_8878;
    v_8878 = stack[-1];
    fn = elt(env, 8); // bczero!?
    v_8878 = (*qfn1(fn))(fn, v_8878);
    env = stack[-17];
    if (v_8878 == nil) goto v_8676;
    else goto v_8677;
v_8676:
    goto v_8685;
v_8681:
    goto v_8682;
v_8683:
    goto v_8694;
v_8688:
    v_8880 = stack[-16];
    goto v_8689;
v_8690:
    v_8879 = stack[-1];
    goto v_8691;
v_8692:
    v_8878 = nil;
    goto v_8693;
v_8694:
    goto v_8688;
v_8689:
    goto v_8690;
v_8691:
    goto v_8692;
v_8693:
    v_8878 = list2star(v_8880, v_8879, v_8878);
    env = stack[-17];
    goto v_8684;
v_8685:
    goto v_8681;
v_8682:
    goto v_8683;
v_8684:
    v_8878 = Lnconc(nil, stack[-2], v_8878);
    env = stack[-17];
    stack[-3] = v_8878;
    v_8878 = stack[-3];
    v_8878 = qcdr(v_8878);
    v_8878 = qcdr(v_8878);
    stack[-2] = v_8878;
    goto v_8675;
v_8677:
v_8675:
    v_8878 = stack[-15];
    v_8878 = qcdr(v_8878);
    v_8878 = qcdr(v_8878);
    stack[-15] = v_8878;
    v_8878 = lisp_true;
    stack[-5] = v_8878;
    goto v_8636;
v_8638:
    goto v_8712;
v_8708:
    v_8879 = v_8880;
    goto v_8709;
v_8710:
    v_8878 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_8711;
v_8712:
    goto v_8708;
v_8709:
    goto v_8710;
v_8711:
    if (v_8879 == v_8878) goto v_8706;
    else goto v_8707;
v_8706:
    v_8878 = qvalue(elt(env, 1)); // !*gcd
    if (v_8878 == nil) goto v_8718;
    goto v_8727;
v_8723:
    v_8878 = stack[-12];
    v_8878 = qcdr(v_8878);
    v_8879 = qcar(v_8878);
    goto v_8724;
v_8725:
    v_8878 = (LispObject)-1600+TAG_FIXNUM; // -100
    goto v_8726;
v_8727:
    goto v_8723;
v_8724:
    goto v_8725;
v_8726:
    fn = elt(env, 2); // vbcsize
    v_8878 = (*qfn2(fn))(fn, v_8879, v_8878);
    env = stack[-17];
    if (v_8878 == nil) goto v_8721;
    else goto v_8718;
v_8721:
    v_8878 = nil;
    qvalue(elt(env, 1)) = v_8878; // !*gcd
    goto v_8716;
v_8718:
v_8716:
    goto v_8738;
v_8734:
    v_8878 = stack[-12];
    v_8878 = qcdr(v_8878);
    v_8879 = qcar(v_8878);
    goto v_8735;
v_8736:
    v_8878 = stack[-11];
    goto v_8737;
v_8738:
    goto v_8734;
v_8735:
    goto v_8736;
v_8737:
    fn = elt(env, 7); // bcprod
    v_8878 = (*qfn2(fn))(fn, v_8879, v_8878);
    env = stack[-17];
    stack[-1] = v_8878;
    v_8878 = stack[-1];
    fn = elt(env, 8); // bczero!?
    v_8878 = (*qfn1(fn))(fn, v_8878);
    env = stack[-17];
    if (v_8878 == nil) goto v_8745;
    else goto v_8746;
v_8745:
    goto v_8754;
v_8750:
    goto v_8751;
v_8752:
    goto v_8763;
v_8757:
    v_8880 = stack[-9];
    goto v_8758;
v_8759:
    v_8879 = stack[-1];
    goto v_8760;
v_8761:
    v_8878 = nil;
    goto v_8762;
v_8763:
    goto v_8757;
v_8758:
    goto v_8759;
v_8760:
    goto v_8761;
v_8762:
    v_8878 = list2star(v_8880, v_8879, v_8878);
    env = stack[-17];
    goto v_8753;
v_8754:
    goto v_8750;
v_8751:
    goto v_8752;
v_8753:
    v_8878 = Lnconc(nil, stack[-2], v_8878);
    env = stack[-17];
    stack[-3] = v_8878;
    v_8878 = stack[-3];
    v_8878 = qcdr(v_8878);
    v_8878 = qcdr(v_8878);
    stack[-2] = v_8878;
    goto v_8744;
v_8746:
v_8744:
    v_8878 = stack[-12];
    v_8878 = qcdr(v_8878);
    v_8878 = qcdr(v_8878);
    stack[-12] = v_8878;
    v_8878 = lisp_true;
    stack[-4] = v_8878;
    goto v_8636;
v_8707:
    v_8878 = qvalue(elt(env, 1)); // !*gcd
    if (v_8878 == nil) goto v_8779;
    goto v_8792;
v_8788:
    v_8878 = stack[-15];
    v_8878 = qcdr(v_8878);
    v_8879 = qcar(v_8878);
    goto v_8789;
v_8790:
    v_8878 = (LispObject)-1600+TAG_FIXNUM; // -100
    goto v_8791;
v_8792:
    goto v_8788;
v_8789:
    goto v_8790;
v_8791:
    fn = elt(env, 2); // vbcsize
    v_8878 = (*qfn2(fn))(fn, v_8879, v_8878);
    env = stack[-17];
    if (v_8878 == nil) goto v_8785;
    else goto v_8786;
v_8785:
    v_8878 = lisp_true;
    goto v_8784;
v_8786:
    goto v_8805;
v_8801:
    v_8878 = stack[-12];
    v_8878 = qcdr(v_8878);
    v_8879 = qcar(v_8878);
    goto v_8802;
v_8803:
    v_8878 = (LispObject)-1600+TAG_FIXNUM; // -100
    goto v_8804;
v_8805:
    goto v_8801;
v_8802:
    goto v_8803;
v_8804:
    fn = elt(env, 2); // vbcsize
    v_8878 = (*qfn2(fn))(fn, v_8879, v_8878);
    env = stack[-17];
    v_8878 = (v_8878 == nil ? lisp_true : nil);
    goto v_8784;
    v_8878 = nil;
v_8784:
    if (v_8878 == nil) goto v_8779;
    v_8878 = nil;
    qvalue(elt(env, 1)) = v_8878; // !*gcd
    goto v_8777;
v_8779:
v_8777:
    goto v_8817;
v_8813:
    goto v_8823;
v_8819:
    v_8878 = stack[-15];
    v_8878 = qcdr(v_8878);
    v_8879 = qcar(v_8878);
    goto v_8820;
v_8821:
    v_8878 = stack[-14];
    goto v_8822;
v_8823:
    goto v_8819;
v_8820:
    goto v_8821;
v_8822:
    fn = elt(env, 7); // bcprod
    stack[-1] = (*qfn2(fn))(fn, v_8879, v_8878);
    env = stack[-17];
    goto v_8814;
v_8815:
    goto v_8833;
v_8829:
    v_8878 = stack[-12];
    v_8878 = qcdr(v_8878);
    v_8879 = qcar(v_8878);
    goto v_8830;
v_8831:
    v_8878 = stack[-11];
    goto v_8832;
v_8833:
    goto v_8829;
v_8830:
    goto v_8831;
v_8832:
    fn = elt(env, 7); // bcprod
    v_8878 = (*qfn2(fn))(fn, v_8879, v_8878);
    env = stack[-17];
    goto v_8816;
v_8817:
    goto v_8813;
v_8814:
    goto v_8815;
v_8816:
    fn = elt(env, 9); // bcsum
    v_8878 = (*qfn2(fn))(fn, stack[-1], v_8878);
    env = stack[-17];
    stack[-1] = v_8878;
    v_8878 = stack[-1];
    fn = elt(env, 8); // bczero!?
    v_8878 = (*qfn1(fn))(fn, v_8878);
    env = stack[-17];
    if (v_8878 == nil) goto v_8840;
    else goto v_8841;
v_8840:
    goto v_8849;
v_8845:
    goto v_8846;
v_8847:
    goto v_8858;
v_8852:
    v_8880 = stack[-16];
    goto v_8853;
v_8854:
    v_8879 = stack[-1];
    goto v_8855;
v_8856:
    v_8878 = nil;
    goto v_8857;
v_8858:
    goto v_8852;
v_8853:
    goto v_8854;
v_8855:
    goto v_8856;
v_8857:
    v_8878 = list2star(v_8880, v_8879, v_8878);
    env = stack[-17];
    goto v_8848;
v_8849:
    goto v_8845;
v_8846:
    goto v_8847;
v_8848:
    v_8878 = Lnconc(nil, stack[-2], v_8878);
    env = stack[-17];
    stack[-3] = v_8878;
    v_8878 = stack[-3];
    v_8878 = qcdr(v_8878);
    v_8878 = qcdr(v_8878);
    stack[-2] = v_8878;
    goto v_8839;
v_8841:
v_8839:
    v_8878 = stack[-15];
    v_8878 = qcdr(v_8878);
    v_8878 = qcdr(v_8878);
    stack[-15] = v_8878;
    v_8878 = stack[-12];
    v_8878 = qcdr(v_8878);
    v_8878 = qcdr(v_8878);
    stack[-12] = v_8878;
    v_8878 = lisp_true;
    stack[-4] = v_8878;
    stack[-5] = v_8878;
    goto v_8636;
v_8636:
    v_8878 = stack[-8];
    if (v_8878 == nil) goto v_8874;
    else goto v_8875;
v_8874:
    v_8878 = stack[-3];
    stack[-2] = v_8878;
    stack[-8] = v_8878;
    goto v_8873;
v_8875:
v_8873:
    goto v_8485;
v_8484:
    ;}  // end of a binding scope
    return onevalue(v_8878);
}



// Code for greaterp!:

static LispObject CC_greaterpT(LispObject env,
                         LispObject v_8459, LispObject v_8460)
{
    env = qenv(env);
    LispObject v_8672, v_8673, v_8674;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8460,v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8459,v_8460);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_8460;
    v_8674 = v_8459;
// end of prologue
    goto v_8470;
v_8466:
    v_8672 = v_8674;
    v_8672 = qcdr(v_8672);
    v_8673 = qcar(v_8672);
    goto v_8467;
v_8468:
    v_8672 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8469;
v_8470:
    goto v_8466;
v_8467:
    goto v_8468;
v_8469:
    if (v_8673 == v_8672) goto v_8464;
    else goto v_8465;
v_8464:
    goto v_8480;
v_8476:
    v_8672 = stack[0];
    v_8672 = qcdr(v_8672);
    v_8673 = qcar(v_8672);
    goto v_8477;
v_8478:
    v_8672 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8479;
v_8480:
    goto v_8476;
v_8477:
    goto v_8478;
v_8479:
        return Llessp(nil, v_8673, v_8672);
v_8465:
    goto v_8491;
v_8487:
    v_8672 = stack[0];
    v_8672 = qcdr(v_8672);
    v_8673 = qcar(v_8672);
    goto v_8488;
v_8489:
    v_8672 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8490;
v_8491:
    goto v_8487;
v_8488:
    goto v_8489;
v_8490:
    if (v_8673 == v_8672) goto v_8485;
    else goto v_8486;
v_8485:
    goto v_8501;
v_8497:
    v_8672 = v_8674;
    v_8672 = qcdr(v_8672);
    v_8673 = qcar(v_8672);
    goto v_8498;
v_8499:
    v_8672 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8500;
v_8501:
    goto v_8497;
v_8498:
    goto v_8499;
v_8500:
        return Lgreaterp(nil, v_8673, v_8672);
v_8486:
    goto v_8512;
v_8508:
    v_8672 = v_8674;
    v_8672 = qcdr(v_8672);
    v_8673 = qcdr(v_8672);
    goto v_8509;
v_8510:
    v_8672 = stack[0];
    v_8672 = qcdr(v_8672);
    v_8672 = qcdr(v_8672);
    goto v_8511;
v_8512:
    goto v_8508;
v_8509:
    goto v_8510;
v_8511:
    if (equal(v_8673, v_8672)) goto v_8506;
    else goto v_8507;
v_8506:
    goto v_8524;
v_8520:
    v_8672 = v_8674;
    v_8672 = qcdr(v_8672);
    v_8673 = qcar(v_8672);
    goto v_8521;
v_8522:
    v_8672 = stack[0];
    v_8672 = qcdr(v_8672);
    v_8672 = qcar(v_8672);
    goto v_8523;
v_8524:
    goto v_8520;
v_8521:
    goto v_8522;
v_8523:
        return Lgreaterp(nil, v_8673, v_8672);
v_8507:
    v_8672 = v_8674;
    fn = elt(env, 3); // normbf
    stack[-1] = (*qfn1(fn))(fn, v_8672);
    env = stack[-5];
    v_8672 = stack[0];
    fn = elt(env, 3); // normbf
    v_8672 = (*qfn1(fn))(fn, v_8672);
    env = stack[-5];
    stack[0] = v_8672;
    goto v_8544;
v_8540:
    v_8672 = stack[-1];
    v_8672 = qcdr(v_8672);
    v_8673 = qcdr(v_8672);
    goto v_8541;
v_8542:
    v_8672 = stack[0];
    v_8672 = qcdr(v_8672);
    v_8672 = qcdr(v_8672);
    goto v_8543;
v_8544:
    goto v_8540;
v_8541:
    goto v_8542;
v_8543:
    v_8674 = difference2(v_8673, v_8672);
    env = stack[-5];
    v_8672 = stack[-1];
    v_8672 = qcdr(v_8672);
    v_8673 = qcar(v_8672);
    v_8672 = stack[0];
    v_8672 = qcdr(v_8672);
    v_8672 = qcar(v_8672);
// Binding d
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = v_8674; // d
    stack[-3] = v_8673;
    stack[-2] = v_8672;
    goto v_8568;
v_8564:
    v_8673 = qvalue(elt(env, 1)); // d
    goto v_8565;
v_8566:
    v_8672 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8567;
v_8568:
    goto v_8564;
v_8565:
    goto v_8566;
v_8567:
    if (v_8673 == v_8672) goto v_8562;
    else goto v_8563;
v_8562:
    goto v_8576;
v_8572:
    v_8673 = stack[-3];
    goto v_8573;
v_8574:
    v_8672 = stack[-2];
    goto v_8575;
v_8576:
    goto v_8572;
v_8573:
    goto v_8574;
v_8575:
    v_8672 = (LispObject)greaterp2(v_8673, v_8672);
    v_8672 = v_8672 ? lisp_true : nil;
    goto v_8561;
v_8563:
    goto v_8586;
v_8582:
    v_8673 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_8583;
v_8584:
    v_8672 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_8585;
v_8586:
    goto v_8582;
v_8583:
    goto v_8584;
v_8585:
    v_8672 = times2(v_8673, v_8672);
    env = stack[-5];
    stack[-1] = v_8672;
    goto v_8599;
v_8595:
    v_8673 = qvalue(elt(env, 1)); // d
    goto v_8596;
v_8597:
    v_8672 = stack[-1];
    goto v_8598;
v_8599:
    goto v_8595;
v_8596:
    goto v_8597;
v_8598:
    v_8672 = (LispObject)greaterp2(v_8673, v_8672);
    v_8672 = v_8672 ? lisp_true : nil;
    env = stack[-5];
    if (v_8672 == nil) goto v_8593;
    goto v_8607;
v_8603:
    v_8673 = stack[-3];
    goto v_8604;
v_8605:
    v_8672 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8606;
v_8607:
    goto v_8603;
v_8604:
    goto v_8605;
v_8606:
    v_8672 = (LispObject)greaterp2(v_8673, v_8672);
    v_8672 = v_8672 ? lisp_true : nil;
    goto v_8591;
v_8593:
    goto v_8617;
v_8613:
    stack[0] = qvalue(elt(env, 1)); // d
    goto v_8614;
v_8615:
    v_8672 = stack[-1];
    v_8672 = negate(v_8672);
    env = stack[-5];
    goto v_8616;
v_8617:
    goto v_8613;
v_8614:
    goto v_8615;
v_8616:
    v_8672 = (LispObject)lessp2(stack[0], v_8672);
    v_8672 = v_8672 ? lisp_true : nil;
    env = stack[-5];
    if (v_8672 == nil) goto v_8611;
    goto v_8626;
v_8622:
    v_8673 = stack[-2];
    goto v_8623;
v_8624:
    v_8672 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8625;
v_8626:
    goto v_8622;
v_8623:
    goto v_8624;
v_8625:
    v_8672 = (LispObject)lessp2(v_8673, v_8672);
    v_8672 = v_8672 ? lisp_true : nil;
    goto v_8591;
v_8611:
    goto v_8636;
v_8632:
    v_8673 = qvalue(elt(env, 1)); // d
    goto v_8633;
v_8634:
    v_8672 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8635;
v_8636:
    goto v_8632;
v_8633:
    goto v_8634;
v_8635:
    v_8672 = (LispObject)greaterp2(v_8673, v_8672);
    v_8672 = v_8672 ? lisp_true : nil;
    env = stack[-5];
    if (v_8672 == nil) goto v_8630;
    goto v_8644;
v_8640:
    goto v_8650;
v_8646:
    v_8673 = stack[-3];
    goto v_8647;
v_8648:
    v_8672 = qvalue(elt(env, 1)); // d
    goto v_8649;
v_8650:
    goto v_8646;
v_8647:
    goto v_8648;
v_8649:
    fn = elt(env, 4); // ashift
    v_8673 = (*qfn2(fn))(fn, v_8673, v_8672);
    env = stack[-5];
    goto v_8641;
v_8642:
    v_8672 = stack[-2];
    goto v_8643;
v_8644:
    goto v_8640;
v_8641:
    goto v_8642;
v_8643:
    v_8672 = (LispObject)greaterp2(v_8673, v_8672);
    v_8672 = v_8672 ? lisp_true : nil;
    goto v_8591;
v_8630:
    goto v_8661;
v_8657:
    stack[0] = stack[-3];
    goto v_8658;
v_8659:
    goto v_8668;
v_8664:
    stack[-1] = stack[-2];
    goto v_8665;
v_8666:
    v_8672 = qvalue(elt(env, 1)); // d
    v_8672 = negate(v_8672);
    env = stack[-5];
    goto v_8667;
v_8668:
    goto v_8664;
v_8665:
    goto v_8666;
v_8667:
    fn = elt(env, 4); // ashift
    v_8672 = (*qfn2(fn))(fn, stack[-1], v_8672);
    env = stack[-5];
    goto v_8660;
v_8661:
    goto v_8657;
v_8658:
    goto v_8659;
v_8660:
    v_8672 = (LispObject)greaterp2(stack[0], v_8672);
    v_8672 = v_8672 ? lisp_true : nil;
    goto v_8591;
    v_8672 = nil;
v_8591:
    goto v_8561;
    v_8672 = nil;
v_8561:
    ;}  // end of a binding scope
    goto v_8463;
    v_8672 = nil;
v_8463:
    return onevalue(v_8672);
}



// Code for mkinds

static LispObject CC_mkinds(LispObject env,
                         LispObject v_8459, LispObject v_8460)
{
    env = qenv(env);
    LispObject v_8503, v_8504;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8460,v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8459,v_8460);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_8460;
    stack[-1] = v_8459;
// end of prologue
    goto v_8470;
v_8466:
    v_8504 = stack[0];
    goto v_8467;
v_8468:
    v_8503 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8469;
v_8470:
    goto v_8466;
v_8467:
    goto v_8468;
v_8469:
    if (v_8504 == v_8503) goto v_8464;
    else goto v_8465;
v_8464:
    v_8503 = nil;
    goto v_8463;
v_8465:
    goto v_8484;
v_8480:
    v_8504 = stack[-1];
    goto v_8481;
v_8482:
    v_8503 = stack[0];
    goto v_8483;
v_8484:
    goto v_8480;
v_8481:
    goto v_8482;
v_8483:
    v_8503 = cons(v_8504, v_8503);
    env = stack[-3];
    goto v_8492;
v_8488:
    stack[-2] = v_8503;
    goto v_8489;
v_8490:
    goto v_8499;
v_8495:
    goto v_8496;
v_8497:
    v_8503 = stack[0];
    v_8503 = sub1(v_8503);
    env = stack[-3];
    goto v_8498;
v_8499:
    goto v_8495;
v_8496:
    goto v_8497;
v_8498:
    v_8503 = CC_mkinds(elt(env, 0), stack[-1], v_8503);
    goto v_8491;
v_8492:
    goto v_8488;
v_8489:
    goto v_8490;
v_8491:
    {
        LispObject v_8508 = stack[-2];
        return cons(v_8508, v_8503);
    }
    goto v_8463;
    v_8503 = nil;
v_8463:
    return onevalue(v_8503);
}



// Code for pappend

static LispObject CC_pappend(LispObject env,
                         LispObject v_8459, LispObject v_8460)
{
    env = qenv(env);
    LispObject v_8534, v_8535;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8460,v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8459,v_8460);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[0] = v_8460;
    stack[-4] = v_8459;
// end of prologue
    v_8534 = stack[-4];
    fn = elt(env, 1); // unpkp
    v_8534 = (*qfn1(fn))(fn, v_8534);
    env = stack[-6];
    stack[-4] = v_8534;
    v_8534 = stack[-4];
    v_8534 = Llength(nil, v_8534);
    env = stack[-6];
    stack[-5] = v_8534;
    v_8534 = stack[0];
    fn = elt(env, 1); // unpkp
    v_8534 = (*qfn1(fn))(fn, v_8534);
    env = stack[-6];
    stack[0] = v_8534;
    v_8534 = stack[0];
    stack[-3] = v_8534;
    v_8534 = stack[-3];
    if (v_8534 == nil) goto v_8480;
    else goto v_8481;
v_8480:
    v_8534 = nil;
    goto v_8475;
v_8481:
    v_8534 = stack[-3];
    v_8534 = qcar(v_8534);
    goto v_8493;
v_8489:
    v_8535 = v_8534;
    goto v_8490;
v_8491:
    v_8534 = stack[-5];
    goto v_8492;
v_8493:
    goto v_8489;
v_8490:
    goto v_8491;
v_8492:
    v_8534 = plus2(v_8535, v_8534);
    env = stack[-6];
    v_8534 = ncons(v_8534);
    env = stack[-6];
    stack[-1] = v_8534;
    stack[-2] = v_8534;
v_8476:
    v_8534 = stack[-3];
    v_8534 = qcdr(v_8534);
    stack[-3] = v_8534;
    v_8534 = stack[-3];
    if (v_8534 == nil) goto v_8500;
    else goto v_8501;
v_8500:
    v_8534 = stack[-2];
    goto v_8475;
v_8501:
    goto v_8509;
v_8505:
    stack[0] = stack[-1];
    goto v_8506;
v_8507:
    v_8534 = stack[-3];
    v_8534 = qcar(v_8534);
    goto v_8520;
v_8516:
    v_8535 = v_8534;
    goto v_8517;
v_8518:
    v_8534 = stack[-5];
    goto v_8519;
v_8520:
    goto v_8516;
v_8517:
    goto v_8518;
v_8519:
    v_8534 = plus2(v_8535, v_8534);
    env = stack[-6];
    v_8534 = ncons(v_8534);
    env = stack[-6];
    goto v_8508;
v_8509:
    goto v_8505;
v_8506:
    goto v_8507;
v_8508:
    v_8534 = Lrplacd(nil, stack[0], v_8534);
    env = stack[-6];
    v_8534 = stack[-1];
    v_8534 = qcdr(v_8534);
    stack[-1] = v_8534;
    goto v_8476;
v_8475:
    stack[0] = v_8534;
    goto v_8531;
v_8527:
    v_8535 = stack[-4];
    goto v_8528;
v_8529:
    v_8534 = stack[0];
    goto v_8530;
v_8531:
    goto v_8527;
v_8528:
    goto v_8529;
v_8530:
    v_8534 = Lappend(nil, v_8535, v_8534);
    env = stack[-6];
    {
        fn = elt(env, 2); // pkp
        return (*qfn1(fn))(fn, v_8534);
    }
    return onevalue(v_8534);
}



// Code for flatsizec

static LispObject CC_flatsizec(LispObject env,
                         LispObject v_8459)
{
    env = qenv(env);
    LispObject v_8487;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8459);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_8459;
// end of prologue
    v_8487 = stack[0];
    if (v_8487 == nil) goto v_8463;
    else goto v_8464;
v_8463:
    v_8487 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8462;
v_8464:
    v_8487 = stack[0];
    if (!consp(v_8487)) goto v_8467;
    else goto v_8468;
v_8467:
    v_8487 = stack[0];
    {
        fn = elt(env, 1); // widelengthc
        return (*qfn1(fn))(fn, v_8487);
    }
v_8468:
    goto v_8479;
v_8475:
    v_8487 = stack[0];
    v_8487 = qcar(v_8487);
    stack[-1] = CC_flatsizec(elt(env, 0), v_8487);
    env = stack[-2];
    goto v_8476;
v_8477:
    v_8487 = stack[0];
    v_8487 = qcdr(v_8487);
    v_8487 = CC_flatsizec(elt(env, 0), v_8487);
    env = stack[-2];
    v_8487 = add1(v_8487);
    goto v_8478;
v_8479:
    goto v_8475;
v_8476:
    goto v_8477;
v_8478:
    {
        LispObject v_8490 = stack[-1];
        return plus2(v_8490, v_8487);
    }
    v_8487 = nil;
v_8462:
    return onevalue(v_8487);
}



// Code for modquotient!:

static LispObject CC_modquotientT(LispObject env,
                         LispObject v_8459, LispObject v_8460)
{
    env = qenv(env);
    LispObject v_8474, v_8475;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8460,v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8459,v_8460);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_8475 = v_8460;
    v_8474 = v_8459;
// end of prologue
    goto v_8468;
v_8464:
    stack[0] = qcdr(v_8474);
    goto v_8465;
v_8466:
    v_8474 = v_8475;
    v_8474 = qcdr(v_8474);
    fn = elt(env, 1); // general!-modular!-reciprocal
    v_8474 = (*qfn1(fn))(fn, v_8474);
    env = stack[-1];
    goto v_8467;
v_8468:
    goto v_8464;
v_8465:
    goto v_8466;
v_8467:
    fn = elt(env, 2); // general!-modular!-times
    v_8474 = (*qfn2(fn))(fn, stack[0], v_8474);
    env = stack[-1];
    {
        fn = elt(env, 3); // !*modular2f
        return (*qfn1(fn))(fn, v_8474);
    }
}



// Code for difference!-mod!-p

static LispObject CC_differenceKmodKp(LispObject env,
                         LispObject v_8459, LispObject v_8460)
{
    env = qenv(env);
    LispObject v_8471, v_8472;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8460,v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8459,v_8460);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_8471 = v_8460;
    v_8472 = v_8459;
// end of prologue
    goto v_8467;
v_8463:
    stack[0] = v_8472;
    goto v_8464;
v_8465:
    fn = elt(env, 1); // minus!-mod!-p
    v_8471 = (*qfn1(fn))(fn, v_8471);
    env = stack[-1];
    goto v_8466;
v_8467:
    goto v_8463;
v_8464:
    goto v_8465;
v_8466:
    {
        LispObject v_8474 = stack[0];
        fn = elt(env, 2); // plus!-mod!-p
        return (*qfn2(fn))(fn, v_8474, v_8471);
    }
}



// Code for nb

static LispObject CC_nb(LispObject env,
                         LispObject v_8459)
{
    env = qenv(env);
    LispObject v_8470;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8470 = v_8459;
// end of prologue
    if (v_8470 == nil) goto v_8464;
    v_8470 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8462;
v_8464:
    v_8470 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_8462;
    v_8470 = nil;
v_8462:
    return onevalue(v_8470);
}



// Code for simp0

static LispObject CC_simp0(LispObject env,
                         LispObject v_8459)
{
    env = qenv(env);
    LispObject v_8573, v_8574;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8459);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_8459;
// end of prologue
// Binding !*factor
// FLUIDBIND: reloadenv=6 litvec-offset=1 saveloc=5
{   bind_fluid_stack bind_fluid_var(-6, 1, -5);
    qvalue(elt(env, 1)) = nil; // !*factor
    goto v_8476;
v_8472:
    v_8574 = stack[-4];
    goto v_8473;
v_8474:
    v_8573 = elt(env, 2); // !*sq
    goto v_8475;
v_8476:
    goto v_8472;
v_8473:
    goto v_8474;
v_8475:
    if (!consp(v_8574)) goto v_8470;
    v_8574 = qcar(v_8574);
    if (v_8574 == v_8573) goto v_8469;
    else goto v_8470;
v_8469:
    v_8573 = stack[-4];
    v_8573 = qcdr(v_8573);
    v_8573 = qcar(v_8573);
    fn = elt(env, 7); // prepsq!*
    v_8573 = (*qfn1(fn))(fn, v_8573);
    env = stack[-6];
    v_8573 = CC_simp0(elt(env, 0), v_8573);
    goto v_8466;
v_8470:
    goto v_8490;
v_8486:
    v_8574 = stack[-4];
    goto v_8487;
v_8488:
    v_8573 = nil;
    goto v_8489;
v_8490:
    goto v_8486;
v_8487:
    goto v_8488;
v_8489:
    fn = elt(env, 8); // frvarsof
    v_8573 = (*qfn2(fn))(fn, v_8574, v_8573);
    env = stack[-6];
    fn = elt(env, 9); // setkorder
    v_8573 = (*qfn1(fn))(fn, v_8573);
    env = stack[-6];
    stack[-2] = v_8573;
    goto v_8498;
v_8494:
    v_8574 = qvalue(elt(env, 3)); // subfg!*
    goto v_8495;
v_8496:
    v_8573 = qvalue(elt(env, 4)); // !*sub2
    goto v_8497;
v_8498:
    goto v_8494;
v_8495:
    goto v_8496;
v_8497:
    v_8573 = cons(v_8574, v_8573);
    env = stack[-6];
    stack[-3] = v_8573;
    v_8573 = nil;
    v_8573 = ncons(v_8573);
    env = stack[-6];
    qvalue(elt(env, 5)) = v_8573; // alglist!*
    v_8573 = nil;
    qvalue(elt(env, 3)) = v_8573; // subfg!*
    v_8573 = stack[-4];
    if (!consp(v_8573)) goto v_8510;
    else goto v_8511;
v_8510:
    v_8573 = lisp_true;
    goto v_8509;
v_8511:
    v_8573 = stack[-4];
    v_8573 = qcar(v_8573);
    if (symbolp(v_8573)) goto v_8519;
    v_8573 = nil;
    goto v_8517;
v_8519:
    goto v_8534;
v_8530:
    v_8573 = stack[-4];
    v_8574 = qcar(v_8573);
    goto v_8531;
v_8532:
    v_8573 = elt(env, 6); // simp0fn
    goto v_8533;
v_8534:
    goto v_8530;
v_8531:
    goto v_8532;
v_8533:
    v_8573 = Lflagp(nil, v_8574, v_8573);
    env = stack[-6];
    if (v_8573 == nil) goto v_8528;
    v_8573 = lisp_true;
    goto v_8526;
v_8528:
    v_8573 = stack[-4];
    v_8573 = qcar(v_8573);
    if (!symbolp(v_8573)) v_8573 = nil;
    else { v_8573 = qfastgets(v_8573);
           if (v_8573 != nil) { v_8573 = elt(v_8573, 2); // rtype
#ifdef RECORD_GET
             if (v_8573 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_8573 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_8573 == SPID_NOPROP) v_8573 = nil; }}
#endif
    goto v_8526;
    v_8573 = nil;
v_8526:
    goto v_8517;
    v_8573 = nil;
v_8517:
    goto v_8509;
    v_8573 = nil;
v_8509:
    if (v_8573 == nil) goto v_8507;
    v_8573 = stack[-4];
    fn = elt(env, 10); // simp
    v_8573 = (*qfn1(fn))(fn, v_8573);
    env = stack[-6];
    stack[-1] = v_8573;
    goto v_8505;
v_8507:
    v_8573 = stack[-4];
    fn = elt(env, 11); // simpiden
    v_8573 = (*qfn1(fn))(fn, v_8573);
    env = stack[-6];
    stack[-1] = v_8573;
    goto v_8505;
v_8505:
    goto v_8555;
v_8551:
    stack[0] = qvalue(elt(env, 5)); // alglist!*
    goto v_8552;
v_8553:
    goto v_8562;
v_8558:
    v_8574 = stack[-4];
    goto v_8559;
v_8560:
    v_8573 = qvalue(elt(env, 5)); // alglist!*
    v_8573 = qcar(v_8573);
    goto v_8561;
v_8562:
    goto v_8558;
v_8559:
    goto v_8560;
v_8561:
    fn = elt(env, 12); // delete_from_alglist
    v_8573 = (*qfn2(fn))(fn, v_8574, v_8573);
    env = stack[-6];
    goto v_8554;
v_8555:
    goto v_8551;
v_8552:
    goto v_8553;
v_8554:
    v_8573 = Lrplaca(nil, stack[0], v_8573);
    env = stack[-6];
    v_8573 = stack[-3];
    v_8573 = qcar(v_8573);
    qvalue(elt(env, 3)) = v_8573; // subfg!*
    v_8573 = stack[-3];
    v_8573 = qcdr(v_8573);
    qvalue(elt(env, 4)) = v_8573; // !*sub2
    v_8573 = stack[-2];
    fn = elt(env, 9); // setkorder
    v_8573 = (*qfn1(fn))(fn, v_8573);
    v_8573 = stack[-1];
v_8466:
    ;}  // end of a binding scope
    return onevalue(v_8573);
}



// Code for get_goto

static LispObject CC_get_goto(LispObject env,
                         LispObject v_8459, LispObject v_8460)
{
    env = qenv(env);
    LispObject v_8510, v_8511, v_8512, v_8513, v_8514;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8510 = v_8460;
    v_8513 = v_8459;
// end of prologue
    goto v_8471;
v_8467:
    v_8511 = qvalue(elt(env, 1)); // parser_goto_table
    goto v_8468;
v_8469:
    goto v_8470;
v_8471:
    goto v_8467;
v_8468:
    goto v_8469;
v_8470:
    v_8510 = *(LispObject *)((char *)v_8511 + (CELL-TAG_VECTOR) + (((intptr_t)v_8510-TAG_FIXNUM)/(16/CELL)));
    v_8511 = v_8510;
    v_8511 = qcar(v_8511);
    v_8514 = v_8511;
    v_8510 = qcdr(v_8510);
    v_8512 = v_8510;
v_8481:
    v_8510 = v_8514;
    if (v_8510 == nil) goto v_8484;
    else goto v_8485;
v_8484:
    goto v_8480;
v_8485:
    goto v_8496;
v_8492:
    v_8510 = v_8514;
    v_8510 = qcar(v_8510);
    v_8511 = qcar(v_8510);
    goto v_8493;
v_8494:
    v_8510 = v_8513;
    goto v_8495;
v_8496:
    goto v_8492;
v_8493:
    goto v_8494;
v_8495:
    if (equal(v_8511, v_8510)) goto v_8490;
    else goto v_8491;
v_8490:
    v_8510 = v_8514;
    v_8510 = qcar(v_8510);
    v_8510 = qcdr(v_8510);
    v_8512 = v_8510;
    v_8510 = nil;
    v_8514 = v_8510;
    goto v_8489;
v_8491:
    v_8510 = v_8514;
    v_8510 = qcdr(v_8510);
    v_8514 = v_8510;
    goto v_8489;
v_8489:
    goto v_8481;
v_8480:
    v_8510 = v_8512;
    return onevalue(v_8510);
}



// Code for in_list1

static LispObject CC_in_list1(LispObject env,
                         LispObject v_8459, LispObject v_8460)
{
    env = qenv(env);
    LispObject v_8473, v_8474, v_8475;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8473 = v_8460;
    v_8474 = v_8459;
// end of prologue
    goto v_8469;
v_8463:
    v_8475 = v_8474;
    goto v_8464;
v_8465:
    v_8474 = v_8473;
    goto v_8466;
v_8467:
    v_8473 = nil;
    goto v_8468;
v_8469:
    goto v_8463;
v_8464:
    goto v_8465;
v_8466:
    goto v_8467;
v_8468:
    {
        fn = elt(env, 1); // in_list1a
        return (*qfnn(fn))(fn, 3, v_8475, v_8474, v_8473);
    }
}



// Code for poly!-minusp

static LispObject CC_polyKminusp(LispObject env,
                         LispObject v_8459)
{
    env = qenv(env);
    LispObject v_8490, v_8491;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8490 = v_8459;
// end of prologue
v_8463:
    v_8491 = v_8490;
    if (v_8491 == nil) goto v_8466;
    else goto v_8467;
v_8466:
    v_8490 = nil;
    goto v_8462;
v_8467:
    v_8491 = v_8490;
    if (!consp(v_8491)) goto v_8474;
    else goto v_8475;
v_8474:
    v_8491 = lisp_true;
    goto v_8473;
v_8475:
    v_8491 = v_8490;
    v_8491 = qcar(v_8491);
    v_8491 = (consp(v_8491) ? nil : lisp_true);
    goto v_8473;
    v_8491 = nil;
v_8473:
    if (v_8491 == nil) goto v_8471;
        return Lminusp(nil, v_8490);
v_8471:
    v_8490 = qcar(v_8490);
    v_8490 = qcdr(v_8490);
    goto v_8463;
    v_8490 = nil;
v_8462:
    return onevalue(v_8490);
}



// Code for exchk1

static LispObject CC_exchk1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8702, v_8703, v_8704, v_8705;
    LispObject fn;
    LispObject v_8462, v_8461, v_8460, v_8459;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "exchk1");
    va_start(aa, nargs);
    v_8459 = va_arg(aa, LispObject);
    v_8460 = va_arg(aa, LispObject);
    v_8461 = va_arg(aa, LispObject);
    v_8462 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_8462,v_8461,v_8460,v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_8459,v_8460,v_8461,v_8462);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_8462;
    stack[-2] = v_8461;
    stack[-3] = v_8460;
    stack[-4] = v_8459;
// end of prologue
v_8458:
v_8467:
    v_8702 = stack[-4];
    if (v_8702 == nil) goto v_8470;
    else goto v_8471;
v_8470:
    goto v_8478;
v_8474:
    goto v_8484;
v_8480:
    v_8703 = stack[-1];
    goto v_8481;
v_8482:
    v_8702 = stack[-2];
    goto v_8483;
v_8484:
    goto v_8480;
v_8481:
    goto v_8482;
v_8483:
    v_8703 = Lappend(nil, v_8703, v_8702);
    env = stack[-6];
    goto v_8475;
v_8476:
    v_8702 = stack[-3];
    goto v_8477;
v_8478:
    goto v_8474;
v_8475:
    goto v_8476;
v_8477:
    {
        fn = elt(env, 3); // exchk2
        return (*qfn2(fn))(fn, v_8703, v_8702);
    }
v_8471:
    goto v_8495;
v_8491:
    v_8702 = stack[-4];
    v_8702 = qcar(v_8702);
    v_8703 = qcar(v_8702);
    goto v_8492;
v_8493:
    v_8702 = elt(env, 1); // expt
    goto v_8494;
v_8495:
    goto v_8491;
v_8492:
    goto v_8493;
v_8494:
    if (!consp(v_8703)) goto v_8489;
    v_8703 = qcar(v_8703);
    if (v_8703 == v_8702) goto v_8488;
    else goto v_8489;
v_8488:
    goto v_8512;
v_8506:
    v_8704 = elt(env, 2); // times
    goto v_8507;
v_8508:
    v_8702 = stack[-4];
    v_8702 = qcar(v_8702);
    v_8703 = qcdr(v_8702);
    goto v_8509;
v_8510:
    v_8702 = stack[-4];
    v_8702 = qcar(v_8702);
    v_8702 = qcar(v_8702);
    v_8702 = qcdr(v_8702);
    v_8702 = qcdr(v_8702);
    v_8702 = qcar(v_8702);
    goto v_8511;
v_8512:
    goto v_8506;
v_8507:
    goto v_8508;
v_8509:
    goto v_8510;
v_8511:
    v_8702 = list3(v_8704, v_8703, v_8702);
    env = stack[-6];
    fn = elt(env, 4); // simpexpon
    v_8702 = (*qfn1(fn))(fn, v_8702);
    env = stack[-6];
    stack[-5] = v_8702;
    v_8702 = stack[-4];
    v_8702 = qcar(v_8702);
    v_8702 = qcar(v_8702);
    v_8702 = qcdr(v_8702);
    v_8702 = qcar(v_8702);
    if (is_number(v_8702)) goto v_8525;
    else goto v_8526;
v_8525:
    goto v_8537;
v_8533:
    v_8703 = stack[-5];
    goto v_8534;
v_8535:
    v_8702 = stack[-1];
    goto v_8536;
v_8537:
    goto v_8533;
v_8534:
    goto v_8535;
v_8536:
    fn = elt(env, 5); // assoc2
    v_8702 = (*qfn2(fn))(fn, v_8703, v_8702);
    env = stack[-6];
    v_8703 = v_8702;
    if (v_8703 == nil) goto v_8543;
    goto v_8550;
v_8546:
    stack[0] = v_8702;
    goto v_8547;
v_8548:
    goto v_8557;
v_8553:
    v_8703 = qcar(v_8702);
    goto v_8554;
v_8555:
    v_8702 = stack[-4];
    v_8702 = qcar(v_8702);
    v_8702 = qcar(v_8702);
    v_8702 = qcdr(v_8702);
    v_8702 = qcar(v_8702);
    goto v_8556;
v_8557:
    goto v_8553;
v_8554:
    goto v_8555;
v_8556:
    v_8702 = times2(v_8703, v_8702);
    env = stack[-6];
    goto v_8549;
v_8550:
    goto v_8546;
v_8547:
    goto v_8548;
v_8549:
    v_8702 = Lrplaca(nil, stack[0], v_8702);
    env = stack[-6];
    goto v_8541;
v_8543:
    goto v_8574;
v_8568:
    v_8702 = stack[-4];
    v_8702 = qcar(v_8702);
    v_8702 = qcar(v_8702);
    v_8702 = qcdr(v_8702);
    v_8704 = qcar(v_8702);
    goto v_8569;
v_8570:
    v_8703 = stack[-5];
    goto v_8571;
v_8572:
    v_8702 = stack[-1];
    goto v_8573;
v_8574:
    goto v_8568;
v_8569:
    goto v_8570;
v_8571:
    goto v_8572;
v_8573:
    v_8702 = acons(v_8704, v_8703, v_8702);
    env = stack[-6];
    stack[-1] = v_8702;
    goto v_8541;
v_8541:
    goto v_8524;
v_8526:
    goto v_8588;
v_8584:
    v_8702 = stack[-4];
    v_8702 = qcar(v_8702);
    v_8702 = qcar(v_8702);
    v_8702 = qcdr(v_8702);
    v_8703 = qcar(v_8702);
    goto v_8585;
v_8586:
    v_8702 = stack[-2];
    goto v_8587;
v_8588:
    goto v_8584;
v_8585:
    goto v_8586;
v_8587:
    v_8702 = Lassoc(nil, v_8703, v_8702);
    v_8703 = v_8702;
    if (v_8703 == nil) goto v_8599;
    goto v_8606;
v_8602:
    stack[0] = v_8702;
    goto v_8603;
v_8604:
    goto v_8613;
v_8609:
    v_8703 = stack[-5];
    goto v_8610;
v_8611:
    v_8702 = qcdr(v_8702);
    goto v_8612;
v_8613:
    goto v_8609;
v_8610:
    goto v_8611;
v_8612:
    fn = elt(env, 6); // addsq
    v_8702 = (*qfn2(fn))(fn, v_8703, v_8702);
    env = stack[-6];
    goto v_8605;
v_8606:
    goto v_8602;
v_8603:
    goto v_8604;
v_8605:
    v_8702 = Lrplacd(nil, stack[0], v_8702);
    env = stack[-6];
    goto v_8597;
v_8599:
    goto v_8626;
v_8620:
    v_8702 = stack[-4];
    v_8702 = qcar(v_8702);
    v_8702 = qcar(v_8702);
    v_8702 = qcdr(v_8702);
    v_8704 = qcar(v_8702);
    goto v_8621;
v_8622:
    v_8703 = stack[-5];
    goto v_8623;
v_8624:
    v_8702 = stack[-2];
    goto v_8625;
v_8626:
    goto v_8620;
v_8621:
    goto v_8622;
v_8623:
    goto v_8624;
v_8625:
    v_8702 = acons(v_8704, v_8703, v_8702);
    env = stack[-6];
    stack[-2] = v_8702;
    goto v_8597;
v_8597:
    goto v_8524;
v_8524:
    goto v_8643;
v_8635:
    v_8702 = stack[-4];
    v_8705 = qcdr(v_8702);
    goto v_8636;
v_8637:
    v_8704 = stack[-3];
    goto v_8638;
v_8639:
    v_8703 = stack[-2];
    goto v_8640;
v_8641:
    v_8702 = stack[-1];
    goto v_8642;
v_8643:
    goto v_8635;
v_8636:
    goto v_8637;
v_8638:
    goto v_8639;
v_8640:
    goto v_8641;
v_8642:
    stack[-4] = v_8705;
    stack[-3] = v_8704;
    stack[-2] = v_8703;
    stack[-1] = v_8702;
    goto v_8458;
    goto v_8466;
v_8489:
    goto v_8655;
v_8651:
    v_8702 = stack[-4];
    v_8702 = qcar(v_8702);
    v_8703 = qcdr(v_8702);
    goto v_8652;
v_8653:
    v_8702 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8654;
v_8655:
    goto v_8651;
v_8652:
    goto v_8653;
v_8654:
    if (v_8703 == v_8702) goto v_8649;
    else goto v_8650;
v_8649:
    v_8702 = stack[-4];
    v_8702 = qcdr(v_8702);
    stack[-5] = v_8702;
    goto v_8667;
v_8663:
    v_8702 = stack[-4];
    v_8702 = qcar(v_8702);
    v_8702 = qcar(v_8702);
    fn = elt(env, 7); // sqchk
    v_8703 = (*qfn1(fn))(fn, v_8702);
    env = stack[-6];
    goto v_8664;
v_8665:
    v_8702 = stack[-3];
    goto v_8666;
v_8667:
    goto v_8663;
v_8664:
    goto v_8665;
v_8666:
    v_8702 = cons(v_8703, v_8702);
    env = stack[-6];
    stack[-3] = v_8702;
    v_8702 = stack[-5];
    stack[-4] = v_8702;
    goto v_8467;
v_8650:
    v_8702 = stack[-4];
    v_8702 = qcdr(v_8702);
    stack[-5] = v_8702;
    goto v_8683;
v_8679:
    goto v_8691;
v_8685:
    stack[0] = elt(env, 1); // expt
    goto v_8686;
v_8687:
    v_8702 = stack[-4];
    v_8702 = qcar(v_8702);
    v_8702 = qcar(v_8702);
    fn = elt(env, 7); // sqchk
    v_8703 = (*qfn1(fn))(fn, v_8702);
    env = stack[-6];
    goto v_8688;
v_8689:
    v_8702 = stack[-4];
    v_8702 = qcar(v_8702);
    v_8702 = qcdr(v_8702);
    goto v_8690;
v_8691:
    goto v_8685;
v_8686:
    goto v_8687;
v_8688:
    goto v_8689;
v_8690:
    v_8703 = list3(stack[0], v_8703, v_8702);
    env = stack[-6];
    goto v_8680;
v_8681:
    v_8702 = stack[-3];
    goto v_8682;
v_8683:
    goto v_8679;
v_8680:
    goto v_8681;
v_8682:
    v_8702 = cons(v_8703, v_8702);
    env = stack[-6];
    stack[-3] = v_8702;
    v_8702 = stack[-5];
    stack[-4] = v_8702;
    goto v_8467;
    v_8702 = nil;
v_8466:
    return onevalue(v_8702);
}



// Code for opmtch

static LispObject CC_opmtch(LispObject env,
                         LispObject v_8459)
{
    env = qenv(env);
    LispObject v_8552, v_8553, v_8554;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8459);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_8553 = v_8459;
// end of prologue
// Binding rpt
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-3, 1, 0);
    qvalue(elt(env, 1)) = nil; // rpt
    v_8552 = elt(env, 2); // inf
    qvalue(elt(env, 1)) = v_8552; // rpt
    v_8552 = v_8553;
    v_8552 = qcar(v_8552);
    if (!symbolp(v_8552)) v_8552 = nil;
    else { v_8552 = qfastgets(v_8552);
           if (v_8552 != nil) { v_8552 = elt(v_8552, 9); // opmtch
#ifdef RECORD_GET
             if (v_8552 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_8552 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_8552 == SPID_NOPROP) v_8552 = nil; }}
#endif
    stack[-1] = v_8552;
    v_8552 = stack[-1];
    if (v_8552 == nil) goto v_8476;
    else goto v_8477;
v_8476:
    v_8552 = lisp_true;
    goto v_8475;
v_8477:
    v_8552 = qvalue(elt(env, 3)); // subfg!*
    v_8552 = (v_8552 == nil ? lisp_true : nil);
    goto v_8475;
    v_8552 = nil;
v_8475:
    if (v_8552 == nil) goto v_8473;
    v_8552 = nil;
    goto v_8465;
v_8473:
    v_8552 = v_8553;
    stack[-2] = v_8552;
v_8488:
    v_8552 = stack[-1];
    v_8552 = qcar(v_8552);
    v_8552 = qcar(v_8552);
    if (!consp(v_8552)) goto v_8491;
    else goto v_8492;
v_8491:
    goto v_8501;
v_8497:
    goto v_8498;
v_8499:
    v_8552 = stack[-1];
    v_8552 = qcar(v_8552);
    goto v_8500;
v_8501:
    goto v_8497;
v_8498:
    goto v_8499;
v_8500:
    fn = elt(env, 4); // sroot1
    v_8552 = (*qfn2(fn))(fn, v_8553, v_8552);
    env = stack[-3];
    goto v_8490;
v_8492:
    goto v_8512;
v_8508:
    goto v_8509;
v_8510:
    v_8552 = stack[-1];
    v_8552 = qcar(v_8552);
    goto v_8511;
v_8512:
    goto v_8508;
v_8509:
    goto v_8510;
v_8511:
    fn = elt(env, 5); // oldmtch
    v_8552 = (*qfn2(fn))(fn, v_8553, v_8552);
    env = stack[-3];
    goto v_8490;
    v_8552 = nil;
v_8490:
    v_8553 = v_8552;
    goto v_8528;
v_8524:
    v_8554 = v_8553;
    goto v_8525;
v_8526:
    v_8552 = stack[-2];
    goto v_8527;
v_8528:
    goto v_8524;
v_8525:
    goto v_8526;
v_8527:
    if (equal(v_8554, v_8552)) goto v_8523;
    v_8552 = lisp_true;
    goto v_8521;
v_8523:
    v_8552 = stack[-1];
    v_8552 = qcdr(v_8552);
    stack[-1] = v_8552;
    v_8552 = (v_8552 == nil ? lisp_true : nil);
    goto v_8521;
    v_8552 = nil;
v_8521:
    if (v_8552 == nil) goto v_8518;
    else goto v_8519;
v_8518:
    goto v_8488;
v_8519:
    goto v_8545;
v_8541:
    v_8554 = v_8553;
    goto v_8542;
v_8543:
    v_8552 = stack[-2];
    goto v_8544;
v_8545:
    goto v_8541;
v_8542:
    goto v_8543;
v_8544:
    if (v_8554 == v_8552) goto v_8539;
    else goto v_8540;
v_8539:
    v_8552 = nil;
    goto v_8538;
v_8540:
    v_8552 = v_8553;
    goto v_8538;
    v_8552 = nil;
v_8538:
v_8465:
    ;}  // end of a binding scope
    return onevalue(v_8552);
}



// Code for c!:extmult

static LispObject CC_cTextmult(LispObject env,
                         LispObject v_8459, LispObject v_8460)
{
    env = qenv(env);
    LispObject v_8746, v_8747, v_8748;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8460,v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8459,v_8460);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_8460;
    stack[-4] = v_8459;
// end of prologue
    v_8746 = nil;
    stack[-5] = v_8746;
v_8469:
    v_8746 = stack[-4];
    if (v_8746 == nil) goto v_8478;
    else goto v_8479;
v_8478:
    v_8746 = lisp_true;
    goto v_8477;
v_8479:
    v_8746 = stack[-3];
    v_8746 = (v_8746 == nil ? lisp_true : nil);
    goto v_8477;
    v_8746 = nil;
v_8477:
    if (v_8746 == nil) goto v_8475;
    v_8746 = nil;
    stack[-1] = v_8746;
    goto v_8470;
v_8475:
    goto v_8493;
v_8489:
    v_8747 = stack[-3];
    goto v_8490;
v_8491:
    v_8746 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8492;
v_8493:
    goto v_8489;
v_8490:
    goto v_8491;
v_8492:
    if (v_8747 == v_8746) goto v_8487;
    else goto v_8488;
v_8487:
    v_8746 = stack[-4];
    stack[-1] = v_8746;
    goto v_8470;
v_8488:
    goto v_8502;
v_8498:
    v_8746 = stack[-4];
    v_8746 = qcar(v_8746);
    v_8746 = qcar(v_8746);
    v_8747 = qcar(v_8746);
    goto v_8499;
v_8500:
    v_8746 = stack[-3];
    v_8746 = qcar(v_8746);
    v_8746 = qcar(v_8746);
    goto v_8501;
v_8502:
    goto v_8498;
v_8499:
    goto v_8500;
v_8501:
    fn = elt(env, 2); // c!:ordexn
    v_8746 = (*qfn2(fn))(fn, v_8747, v_8746);
    env = stack[-6];
    stack[0] = v_8746;
    v_8746 = stack[0];
    if (v_8746 == nil) goto v_8513;
    goto v_8522;
v_8516:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8517;
v_8518:
    goto v_8531;
v_8525:
    v_8748 = stack[0];
    goto v_8526;
v_8527:
    v_8747 = stack[-4];
    goto v_8528;
v_8529:
    v_8746 = stack[-3];
    goto v_8530;
v_8531:
    goto v_8525;
v_8526:
    goto v_8527;
v_8528:
    goto v_8529;
v_8530:
    v_8747 = list2star(v_8748, v_8747, v_8746);
    env = stack[-6];
    goto v_8519;
v_8520:
    v_8746 = stack[-5];
    goto v_8521;
v_8522:
    goto v_8516;
v_8517:
    goto v_8518;
v_8519:
    goto v_8520;
v_8521:
    v_8746 = acons(stack[-1], v_8747, v_8746);
    env = stack[-6];
    stack[-5] = v_8746;
    v_8746 = stack[-4];
    v_8746 = qcdr(v_8746);
    stack[-4] = v_8746;
    goto v_8469;
v_8513:
    goto v_8547;
v_8541:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_8542;
v_8543:
    goto v_8554;
v_8550:
    v_8747 = stack[-4];
    goto v_8551;
v_8552:
    v_8746 = stack[-3];
    goto v_8553;
v_8554:
    goto v_8550;
v_8551:
    goto v_8552;
v_8553:
    v_8747 = cons(v_8747, v_8746);
    env = stack[-6];
    goto v_8544;
v_8545:
    v_8746 = stack[-5];
    goto v_8546;
v_8547:
    goto v_8541;
v_8542:
    goto v_8543;
v_8544:
    goto v_8545;
v_8546:
    v_8746 = acons(stack[0], v_8747, v_8746);
    env = stack[-6];
    stack[-5] = v_8746;
    v_8746 = stack[-4];
    v_8746 = qcdr(v_8746);
    stack[-4] = v_8746;
    goto v_8469;
v_8470:
    v_8746 = stack[-5];
    if (v_8746 == nil) goto v_8562;
    else goto v_8563;
v_8562:
    v_8746 = stack[-1];
    goto v_8468;
v_8563:
    v_8746 = stack[-5];
    v_8746 = qcar(v_8746);
    v_8748 = v_8746;
    v_8746 = stack[-5];
    v_8746 = qcdr(v_8746);
    stack[-5] = v_8746;
    goto v_8578;
v_8574:
    v_8746 = v_8748;
    v_8747 = qcar(v_8746);
    goto v_8575;
v_8576:
    v_8746 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8577;
v_8578:
    goto v_8574;
v_8575:
    goto v_8576;
v_8577:
    if (v_8747 == v_8746) goto v_8572;
    else goto v_8573;
v_8572:
    v_8746 = v_8748;
    v_8746 = qcdr(v_8746);
    v_8748 = v_8746;
    v_8746 = v_8748;
    v_8746 = qcar(v_8746);
    stack[0] = v_8746;
    v_8746 = v_8748;
    v_8746 = qcdr(v_8746);
    v_8748 = v_8746;
    v_8746 = v_8748;
    v_8746 = qcar(v_8746);
    stack[-4] = v_8746;
    v_8746 = v_8748;
    v_8746 = qcdr(v_8746);
    stack[-3] = v_8746;
    goto v_8599;
v_8593:
    stack[-2] = (LispObject)48+TAG_FIXNUM; // 3
    goto v_8594;
v_8595:
    goto v_8608;
v_8602:
    goto v_8603;
v_8604:
    goto v_8605;
v_8606:
    goto v_8616;
v_8612:
    v_8747 = stack[-4];
    goto v_8613;
v_8614:
    v_8746 = stack[-3];
    goto v_8615;
v_8616:
    goto v_8612;
v_8613:
    goto v_8614;
v_8615:
    v_8746 = cons(v_8747, v_8746);
    env = stack[-6];
    goto v_8607;
v_8608:
    goto v_8602;
v_8603:
    goto v_8604;
v_8605:
    goto v_8606;
v_8607:
    v_8747 = list2star(stack[-1], stack[0], v_8746);
    env = stack[-6];
    goto v_8596;
v_8597:
    v_8746 = stack[-5];
    goto v_8598;
v_8599:
    goto v_8593;
v_8594:
    goto v_8595;
v_8596:
    goto v_8597;
v_8598:
    v_8746 = acons(stack[-2], v_8747, v_8746);
    env = stack[-6];
    stack[-5] = v_8746;
    v_8746 = stack[-4];
    v_8746 = qcar(v_8746);
    v_8746 = ncons(v_8746);
    env = stack[-6];
    stack[-4] = v_8746;
    v_8746 = stack[-3];
    v_8746 = qcdr(v_8746);
    stack[-3] = v_8746;
    goto v_8469;
v_8573:
    goto v_8631;
v_8627:
    v_8746 = v_8748;
    v_8747 = qcar(v_8746);
    goto v_8628;
v_8629:
    v_8746 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_8630;
v_8631:
    goto v_8627;
v_8628:
    goto v_8629;
v_8630:
    if (v_8747 == v_8746) goto v_8625;
    else goto v_8626;
v_8625:
    v_8746 = v_8748;
    v_8746 = qcdr(v_8746);
    v_8748 = v_8746;
    v_8746 = v_8748;
    v_8746 = qcar(v_8746);
    stack[-4] = v_8746;
    v_8746 = v_8748;
    v_8746 = qcdr(v_8746);
    stack[-3] = v_8746;
    goto v_8648;
v_8642:
    v_8748 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_8643;
v_8644:
    v_8747 = stack[-1];
    goto v_8645;
v_8646:
    v_8746 = stack[-5];
    goto v_8647;
v_8648:
    goto v_8642;
v_8643:
    goto v_8644;
v_8645:
    goto v_8646;
v_8647:
    v_8746 = acons(v_8748, v_8747, v_8746);
    env = stack[-6];
    stack[-5] = v_8746;
    v_8746 = stack[-4];
    v_8746 = qcar(v_8746);
    v_8746 = ncons(v_8746);
    env = stack[-6];
    stack[-4] = v_8746;
    v_8746 = stack[-3];
    v_8746 = qcdr(v_8746);
    stack[-3] = v_8746;
    goto v_8469;
v_8626:
    goto v_8663;
v_8659:
    v_8746 = v_8748;
    v_8747 = qcar(v_8746);
    goto v_8660;
v_8661:
    v_8746 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_8662;
v_8663:
    goto v_8659;
v_8660:
    goto v_8661;
v_8662:
    if (v_8747 == v_8746) goto v_8657;
    else goto v_8658;
v_8657:
    v_8746 = v_8748;
    v_8746 = qcdr(v_8746);
    v_8748 = v_8746;
    v_8746 = v_8748;
    v_8746 = qcar(v_8746);
    stack[-2] = v_8746;
    v_8746 = v_8748;
    v_8746 = qcdr(v_8746);
    v_8748 = v_8746;
    v_8746 = v_8748;
    v_8746 = qcar(v_8746);
    stack[0] = v_8746;
    v_8746 = v_8748;
    v_8746 = qcdr(v_8746);
    v_8748 = v_8746;
    v_8746 = v_8748;
    v_8746 = qcar(v_8746);
    stack[-4] = v_8746;
    v_8746 = v_8748;
    v_8746 = qcdr(v_8746);
    stack[-3] = v_8746;
    goto v_8686;
v_8682:
    v_8746 = stack[-4];
    v_8746 = qcar(v_8746);
    v_8747 = qcdr(v_8746);
    goto v_8683;
v_8684:
    v_8746 = stack[-3];
    v_8746 = qcar(v_8746);
    v_8746 = qcdr(v_8746);
    goto v_8685;
v_8686:
    goto v_8682;
v_8683:
    goto v_8684;
v_8685:
    fn = elt(env, 3); // c!:subs2multf
    v_8746 = (*qfn2(fn))(fn, v_8747, v_8746);
    env = stack[-6];
    v_8748 = v_8746;
    v_8746 = stack[0];
    v_8746 = qcar(v_8746);
    if (v_8746 == nil) goto v_8696;
    v_8746 = v_8748;
    fn = elt(env, 4); // negf
    v_8746 = (*qfn1(fn))(fn, v_8746);
    env = stack[-6];
    v_8748 = v_8746;
    goto v_8694;
v_8696:
v_8694:
    goto v_8706;
v_8702:
    goto v_8713;
v_8709:
    v_8746 = stack[0];
    v_8746 = qcdr(v_8746);
    goto v_8710;
v_8711:
    v_8747 = v_8748;
    goto v_8712;
v_8713:
    goto v_8709;
v_8710:
    goto v_8711;
v_8712:
    v_8746 = cons(v_8746, v_8747);
    env = stack[-6];
    stack[0] = ncons(v_8746);
    env = stack[-6];
    goto v_8703;
v_8704:
    goto v_8722;
v_8718:
    v_8747 = stack[-1];
    goto v_8719;
v_8720:
    v_8746 = stack[-2];
    goto v_8721;
v_8722:
    goto v_8718;
v_8719:
    goto v_8720;
v_8721:
    fn = elt(env, 5); // c!:extadd
    v_8746 = (*qfn2(fn))(fn, v_8747, v_8746);
    env = stack[-6];
    goto v_8705;
v_8706:
    goto v_8702;
v_8703:
    goto v_8704;
v_8705:
    fn = elt(env, 5); // c!:extadd
    v_8746 = (*qfn2(fn))(fn, stack[0], v_8746);
    env = stack[-6];
    stack[-1] = v_8746;
    goto v_8470;
v_8658:
    goto v_8731;
v_8727:
    v_8746 = v_8748;
    v_8747 = qcar(v_8746);
    goto v_8728;
v_8729:
    v_8746 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_8730;
v_8731:
    goto v_8727;
v_8728:
    goto v_8729;
v_8730:
    if (v_8747 == v_8746) goto v_8725;
    else goto v_8726;
v_8725:
    goto v_8740;
v_8736:
    v_8746 = stack[-1];
    goto v_8737;
v_8738:
    v_8747 = v_8748;
    v_8747 = qcdr(v_8747);
    goto v_8739;
v_8740:
    goto v_8736;
v_8737:
    goto v_8738;
v_8739:
    fn = elt(env, 5); // c!:extadd
    v_8746 = (*qfn2(fn))(fn, v_8746, v_8747);
    env = stack[-6];
    stack[-1] = v_8746;
    goto v_8470;
v_8726:
    v_8746 = elt(env, 1); // "should never get here"
    fn = elt(env, 6); // rederr
    v_8746 = (*qfn1(fn))(fn, v_8746);
    v_8746 = nil;
v_8468:
    return onevalue(v_8746);
}



// Code for assert_uninstall_all

static LispObject CC_assert_uninstall_all(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8462;
    LispObject fn;
    argcheck(nargs, 0, "assert_uninstall_all");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_8462 = qvalue(elt(env, 1)); // assert_functionl!*
    {
        fn = elt(env, 2); // assert_uninstall
        return (*qfn1(fn))(fn, v_8462);
    }
}



// Code for cali_bc_inv

static LispObject CC_cali_bc_inv(LispObject env,
                         LispObject v_8459)
{
    env = qenv(env);
    LispObject v_8512, v_8513, v_8514;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8459);
    }
// copy arguments values to proper place
    v_8514 = v_8459;
// end of prologue
    goto v_8473;
v_8469:
    v_8513 = v_8514;
    goto v_8470;
v_8471:
    v_8512 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8472;
v_8473:
    goto v_8469;
v_8470:
    goto v_8471;
v_8472:
    if (v_8513 == v_8512) goto v_8467;
    else goto v_8468;
v_8467:
    v_8512 = lisp_true;
    goto v_8466;
v_8468:
    goto v_8483;
v_8479:
    v_8513 = v_8514;
    goto v_8480;
v_8481:
    v_8512 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_8482;
v_8483:
    goto v_8479;
v_8480:
    goto v_8481;
v_8482:
    v_8512 = (v_8513 == v_8512 ? lisp_true : nil);
    goto v_8466;
    v_8512 = nil;
v_8466:
    if (v_8512 == nil) goto v_8464;
    v_8512 = v_8514;
    goto v_8462;
v_8464:
    goto v_8498;
v_8494:
    v_8512 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8495;
v_8496:
    v_8513 = v_8514;
    goto v_8497;
v_8498:
    goto v_8494;
v_8495:
    goto v_8496;
v_8497:
    fn = elt(env, 1); // qremf
    v_8512 = (*qfn2(fn))(fn, v_8512, v_8513);
    v_8513 = v_8512;
    v_8512 = v_8513;
    v_8512 = qcdr(v_8512);
    if (v_8512 == nil) goto v_8504;
    v_8512 = nil;
    goto v_8492;
v_8504:
    v_8512 = v_8513;
    v_8512 = qcar(v_8512);
    goto v_8492;
    v_8512 = nil;
v_8492:
    goto v_8462;
    v_8512 = nil;
v_8462:
    return onevalue(v_8512);
}



// Code for subsetp

static LispObject CC_subsetp(LispObject env,
                         LispObject v_8459, LispObject v_8460)
{
    env = qenv(env);
    LispObject v_8495, v_8496, v_8497, v_8498;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8496 = v_8460;
    v_8497 = v_8459;
// end of prologue
v_8458:
    v_8495 = v_8497;
    if (v_8495 == nil) goto v_8464;
    else goto v_8465;
v_8464:
    v_8495 = lisp_true;
    goto v_8463;
v_8465:
    goto v_8478;
v_8474:
    v_8495 = v_8497;
    v_8498 = qcar(v_8495);
    goto v_8475;
v_8476:
    v_8495 = v_8496;
    goto v_8477;
v_8478:
    goto v_8474;
v_8475:
    goto v_8476;
v_8477:
    v_8495 = Lmember(nil, v_8498, v_8495);
    if (v_8495 == nil) goto v_8472;
    else goto v_8473;
v_8472:
    v_8495 = nil;
    goto v_8471;
v_8473:
    goto v_8491;
v_8487:
    v_8495 = v_8497;
    v_8497 = qcdr(v_8495);
    goto v_8488;
v_8489:
    v_8495 = v_8496;
    goto v_8490;
v_8491:
    goto v_8487;
v_8488:
    goto v_8489;
v_8490:
    v_8496 = v_8495;
    goto v_8458;
    v_8495 = nil;
v_8471:
    goto v_8463;
    v_8495 = nil;
v_8463:
    return onevalue(v_8495);
}



// Code for ra_transform

static LispObject CC_ra_transform(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8524, v_8525;
    LispObject fn;
    LispObject v_8461, v_8460, v_8459;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ra_transform");
    va_start(aa, nargs);
    v_8459 = va_arg(aa, LispObject);
    v_8460 = va_arg(aa, LispObject);
    v_8461 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_8461,v_8460,v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_8459,v_8460,v_8461);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_8524 = v_8461;
    stack[-2] = v_8460;
    v_8525 = v_8459;
// end of prologue
    goto v_8468;
v_8464:
    stack[-3] = v_8525;
    goto v_8465;
v_8466:
    goto v_8476;
v_8472:
    stack[-1] = elt(env, 1); // x
    goto v_8473;
v_8474:
    goto v_8483;
v_8479:
    goto v_8489;
v_8485:
    goto v_8495;
v_8491:
    stack[0] = v_8524;
    goto v_8492;
v_8493:
    v_8524 = stack[-2];
    fn = elt(env, 2); // negsq
    v_8524 = (*qfn1(fn))(fn, v_8524);
    env = stack[-4];
    goto v_8494;
v_8495:
    goto v_8491;
v_8492:
    goto v_8493;
v_8494:
    fn = elt(env, 3); // addsq
    stack[0] = (*qfn2(fn))(fn, stack[0], v_8524);
    env = stack[-4];
    goto v_8486;
v_8487:
    goto v_8504;
v_8500:
    goto v_8511;
v_8507:
    goto v_8517;
v_8513:
    v_8525 = elt(env, 1); // x
    goto v_8514;
v_8515:
    v_8524 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8516;
v_8517:
    goto v_8513;
v_8514:
    goto v_8515;
v_8516:
    fn = elt(env, 4); // to
    v_8525 = (*qfn2(fn))(fn, v_8525, v_8524);
    env = stack[-4];
    goto v_8508;
v_8509:
    v_8524 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8510;
v_8511:
    goto v_8507;
v_8508:
    goto v_8509;
v_8510:
    v_8524 = cons(v_8525, v_8524);
    env = stack[-4];
    v_8525 = ncons(v_8524);
    env = stack[-4];
    goto v_8501;
v_8502:
    v_8524 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8503;
v_8504:
    goto v_8500;
v_8501:
    goto v_8502;
v_8503:
    v_8524 = cons(v_8525, v_8524);
    env = stack[-4];
    goto v_8488;
v_8489:
    goto v_8485;
v_8486:
    goto v_8487;
v_8488:
    fn = elt(env, 5); // multsq
    v_8525 = (*qfn2(fn))(fn, stack[0], v_8524);
    env = stack[-4];
    goto v_8480;
v_8481:
    v_8524 = stack[-2];
    goto v_8482;
v_8483:
    goto v_8479;
v_8480:
    goto v_8481;
v_8482:
    fn = elt(env, 3); // addsq
    v_8524 = (*qfn2(fn))(fn, v_8525, v_8524);
    env = stack[-4];
    goto v_8475;
v_8476:
    goto v_8472;
v_8473:
    goto v_8474;
v_8475:
    v_8524 = cons(stack[-1], v_8524);
    env = stack[-4];
    v_8524 = ncons(v_8524);
    env = stack[-4];
    goto v_8467;
v_8468:
    goto v_8464;
v_8465:
    goto v_8466;
v_8467:
    fn = elt(env, 6); // sfto_qsub1
    v_8524 = (*qfn2(fn))(fn, stack[-3], v_8524);
    v_8524 = qcar(v_8524);
    return onevalue(v_8524);
}



// Code for lex_start_block_comment

static LispObject CC_lex_start_block_comment(LispObject env,
                         LispObject v_8459)
{
    env = qenv(env);
    LispObject v_8544, v_8545;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8459);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_8459;
// end of prologue
    goto v_8473;
v_8469:
    v_8545 = stack[0];
    goto v_8470;
v_8471:
    v_8544 = elt(env, 1); // !/
    goto v_8472;
v_8473:
    goto v_8469;
v_8470:
    goto v_8471;
v_8472:
    if (v_8545 == v_8544) goto v_8467;
    else goto v_8468;
v_8467:
    goto v_8484;
v_8480:
    fn = elt(env, 5); // yypeek
    v_8545 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_8481;
v_8482:
    v_8544 = elt(env, 2); // !*
    goto v_8483;
v_8484:
    goto v_8480;
v_8481:
    goto v_8482;
v_8483:
    if (v_8545 == v_8544) goto v_8478;
    else goto v_8479;
v_8478:
    goto v_8493;
v_8489:
    v_8545 = qvalue(elt(env, 3)); // lexer_style!*
    goto v_8490;
v_8491:
    v_8544 = (LispObject)128+TAG_FIXNUM; // 8
    goto v_8492;
v_8493:
    goto v_8489;
v_8490:
    goto v_8491;
v_8492:
    fn = elt(env, 6); // land
    v_8544 = (*qfn2(fn))(fn, v_8545, v_8544);
    env = stack[-1];
    v_8544 = (LispObject)zerop(v_8544);
    v_8544 = v_8544 ? lisp_true : nil;
    env = stack[-1];
    v_8544 = (v_8544 == nil ? lisp_true : nil);
    goto v_8477;
v_8479:
    v_8544 = nil;
    goto v_8477;
    v_8544 = nil;
v_8477:
    goto v_8466;
v_8468:
    v_8544 = nil;
    goto v_8466;
    v_8544 = nil;
v_8466:
    if (v_8544 == nil) goto v_8464;
    v_8544 = lisp_true;
    goto v_8462;
v_8464:
    goto v_8514;
v_8510:
    v_8545 = stack[0];
    goto v_8511;
v_8512:
    v_8544 = elt(env, 4); // !(
    goto v_8513;
v_8514:
    goto v_8510;
v_8511:
    goto v_8512;
v_8513:
    if (v_8545 == v_8544) goto v_8508;
    else goto v_8509;
v_8508:
    goto v_8525;
v_8521:
    fn = elt(env, 5); // yypeek
    v_8545 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_8522;
v_8523:
    v_8544 = elt(env, 2); // !*
    goto v_8524;
v_8525:
    goto v_8521;
v_8522:
    goto v_8523;
v_8524:
    if (v_8545 == v_8544) goto v_8519;
    else goto v_8520;
v_8519:
    goto v_8534;
v_8530:
    v_8545 = qvalue(elt(env, 3)); // lexer_style!*
    goto v_8531;
v_8532:
    v_8544 = (LispObject)256+TAG_FIXNUM; // 16
    goto v_8533;
v_8534:
    goto v_8530;
v_8531:
    goto v_8532;
v_8533:
    fn = elt(env, 6); // land
    v_8544 = (*qfn2(fn))(fn, v_8545, v_8544);
    env = stack[-1];
    v_8544 = (LispObject)zerop(v_8544);
    v_8544 = v_8544 ? lisp_true : nil;
    v_8544 = (v_8544 == nil ? lisp_true : nil);
    goto v_8518;
v_8520:
    v_8544 = nil;
    goto v_8518;
    v_8544 = nil;
v_8518:
    goto v_8507;
v_8509:
    v_8544 = nil;
    goto v_8507;
    v_8544 = nil;
v_8507:
    goto v_8462;
    v_8544 = nil;
v_8462:
    return onevalue(v_8544);
}



// Code for gcref_mkedges!-tgf

static LispObject CC_gcref_mkedgesKtgf(LispObject env,
                         LispObject v_8459, LispObject v_8460)
{
    env = qenv(env);
    LispObject v_8484;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8460,v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8459,v_8460);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_8484 = v_8460;
    stack[-1] = v_8459;
// end of prologue
    stack[-2] = v_8484;
v_8465:
    v_8484 = stack[-2];
    if (v_8484 == nil) goto v_8469;
    else goto v_8470;
v_8469:
    v_8484 = nil;
    goto v_8464;
v_8470:
    v_8484 = stack[-2];
    v_8484 = qcar(v_8484);
    stack[0] = v_8484;
    v_8484 = stack[-1];
    v_8484 = Lprinc(nil, v_8484);
    env = stack[-3];
    v_8484 = elt(env, 1); // " "
    v_8484 = Lprinc(nil, v_8484);
    env = stack[-3];
    v_8484 = stack[0];
    fn = elt(env, 2); // prin2t
    v_8484 = (*qfn1(fn))(fn, v_8484);
    env = stack[-3];
    v_8484 = stack[-2];
    v_8484 = qcdr(v_8484);
    stack[-2] = v_8484;
    goto v_8465;
v_8464:
    return onevalue(v_8484);
}



// Code for mri_pasf2mriat

static LispObject CC_mri_pasf2mriat(LispObject env,
                         LispObject v_8459, LispObject v_8460)
{
    env = qenv(env);
    LispObject v_8476, v_8477, v_8478;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8476 = v_8460;
    v_8477 = v_8459;
// end of prologue
    goto v_8469;
v_8463:
    v_8478 = v_8477;
    v_8478 = qcar(v_8478);
    goto v_8464;
v_8465:
    v_8477 = qcdr(v_8477);
    v_8477 = qcar(v_8477);
    goto v_8466;
v_8467:
    goto v_8468;
v_8469:
    goto v_8463;
v_8464:
    goto v_8465;
v_8466:
    goto v_8467;
v_8468:
    {
        fn = elt(env, 1); // mri_0mk2
        return (*qfnn(fn))(fn, 3, v_8478, v_8477, v_8476);
    }
}



// Code for ibalp_simpterm

static LispObject CC_ibalp_simpterm(LispObject env,
                         LispObject v_8459)
{
    env = qenv(env);
    LispObject v_8553, v_8554;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8459);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_8459;
// end of prologue
v_8458:
    v_8553 = stack[0];
    if (!consp(v_8553)) goto v_8466;
    else goto v_8467;
v_8466:
    v_8553 = stack[0];
    {
        fn = elt(env, 2); // ibalp_simpatom
        return (*qfn1(fn))(fn, v_8553);
    }
v_8467:
    v_8553 = stack[0];
    v_8553 = qcar(v_8553);
    stack[-1] = v_8553;
    v_8553 = stack[-1];
    fn = elt(env, 3); // ibalp_boolfp
    v_8553 = (*qfn1(fn))(fn, v_8553);
    env = stack[-5];
    if (v_8553 == nil) goto v_8476;
    goto v_8484;
v_8480:
    stack[-4] = stack[-1];
    goto v_8481;
v_8482:
    v_8553 = stack[0];
    v_8553 = qcdr(v_8553);
    stack[-3] = v_8553;
    v_8553 = stack[-3];
    if (v_8553 == nil) goto v_8496;
    else goto v_8497;
v_8496:
    v_8553 = nil;
    goto v_8490;
v_8497:
    v_8553 = stack[-3];
    v_8553 = qcar(v_8553);
    v_8553 = CC_ibalp_simpterm(elt(env, 0), v_8553);
    env = stack[-5];
    v_8553 = ncons(v_8553);
    env = stack[-5];
    stack[-1] = v_8553;
    stack[-2] = v_8553;
v_8491:
    v_8553 = stack[-3];
    v_8553 = qcdr(v_8553);
    stack[-3] = v_8553;
    v_8553 = stack[-3];
    if (v_8553 == nil) goto v_8510;
    else goto v_8511;
v_8510:
    v_8553 = stack[-2];
    goto v_8490;
v_8511:
    goto v_8519;
v_8515:
    stack[0] = stack[-1];
    goto v_8516;
v_8517:
    v_8553 = stack[-3];
    v_8553 = qcar(v_8553);
    v_8553 = CC_ibalp_simpterm(elt(env, 0), v_8553);
    env = stack[-5];
    v_8553 = ncons(v_8553);
    env = stack[-5];
    goto v_8518;
v_8519:
    goto v_8515;
v_8516:
    goto v_8517;
v_8518:
    v_8553 = Lrplacd(nil, stack[0], v_8553);
    env = stack[-5];
    v_8553 = stack[-1];
    v_8553 = qcdr(v_8553);
    stack[-1] = v_8553;
    goto v_8491;
v_8490:
    goto v_8483;
v_8484:
    goto v_8480;
v_8481:
    goto v_8482;
v_8483:
    {
        LispObject v_8560 = stack[-4];
        return cons(v_8560, v_8553);
    }
v_8476:
    v_8553 = stack[0];
    fn = elt(env, 4); // reval
    v_8553 = (*qfn1(fn))(fn, v_8553);
    env = stack[-5];
    stack[0] = v_8553;
    goto v_8540;
v_8536:
    v_8554 = stack[0];
    goto v_8537;
v_8538:
    v_8553 = stack[-1];
    goto v_8539;
v_8540:
    goto v_8536;
v_8537:
    goto v_8538;
v_8539:
    if (!consp(v_8554)) goto v_8534;
    v_8554 = qcar(v_8554);
    if (v_8554 == v_8553) goto v_8533;
    else goto v_8534;
v_8533:
    goto v_8548;
v_8544:
    v_8554 = stack[-1];
    goto v_8545;
v_8546:
    v_8553 = elt(env, 1); // "Boolean function"
    goto v_8547;
v_8548:
    goto v_8544;
v_8545:
    goto v_8546;
v_8547:
    fn = elt(env, 5); // typerr
    v_8553 = (*qfn2(fn))(fn, v_8554, v_8553);
    env = stack[-5];
    goto v_8532;
v_8534:
v_8532:
    v_8553 = stack[0];
    stack[0] = v_8553;
    goto v_8458;
    return onevalue(v_8553);
}



// Code for matrixrowrd

static LispObject CC_matrixrowrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8481, v_8482;
    LispObject fn;
    argcheck(nargs, 0, "matrixrowrd");
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
    fn = elt(env, 1); // mathml
    v_8481 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_8482 = v_8481;
    v_8481 = v_8482;
    if (v_8481 == nil) goto v_8467;
    else goto v_8468;
v_8467:
    v_8481 = nil;
    goto v_8466;
v_8468:
    goto v_8478;
v_8474:
    stack[0] = v_8482;
    goto v_8475;
v_8476:
    v_8481 = CC_matrixrowrd(elt(env, 0), 0);
    goto v_8477;
v_8478:
    goto v_8474;
v_8475:
    goto v_8476;
v_8477:
    {
        LispObject v_8484 = stack[0];
        return cons(v_8484, v_8481);
    }
    v_8481 = nil;
v_8466:
    return onevalue(v_8481);
}



// Code for find_sub_df

static LispObject CC_find_sub_df(LispObject env,
                         LispObject v_8459, LispObject v_8460)
{
    env = qenv(env);
    LispObject v_8491, v_8492;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8460,v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8459,v_8460);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_8460;
    stack[-1] = v_8459;
// end of prologue
v_8458:
    v_8491 = stack[0];
    if (v_8491 == nil) goto v_8464;
    else goto v_8465;
v_8464:
    v_8491 = nil;
    goto v_8463;
v_8465:
    goto v_8478;
v_8474:
    v_8492 = stack[-1];
    goto v_8475;
v_8476:
    v_8491 = stack[0];
    v_8491 = qcar(v_8491);
    goto v_8477;
v_8478:
    goto v_8474;
v_8475:
    goto v_8476;
v_8477:
    fn = elt(env, 1); // is_sub_df
    v_8491 = (*qfn2(fn))(fn, v_8492, v_8491);
    env = stack[-2];
    if (v_8491 == nil) goto v_8472;
    else goto v_8471;
v_8472:
    goto v_8487;
v_8483:
    v_8492 = stack[-1];
    goto v_8484;
v_8485:
    v_8491 = stack[0];
    v_8491 = qcdr(v_8491);
    goto v_8486;
v_8487:
    goto v_8483;
v_8484:
    goto v_8485;
v_8486:
    stack[-1] = v_8492;
    stack[0] = v_8491;
    goto v_8458;
v_8471:
    goto v_8463;
    v_8491 = nil;
v_8463:
    return onevalue(v_8491);
}



// Code for redcodmat

static LispObject CC_redcodmat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8483, v_8484;
    LispObject fn;
    argcheck(nargs, 0, "redcodmat");
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
    v_8483 = qvalue(elt(env, 1)); // rowmin
    stack[0] = v_8483;
v_8463:
    goto v_8475;
v_8471:
    v_8484 = qvalue(elt(env, 2)); // rowmax
    goto v_8472;
v_8473:
    v_8483 = stack[0];
    goto v_8474;
v_8475:
    goto v_8471;
v_8472:
    goto v_8473;
v_8474:
    v_8483 = difference2(v_8484, v_8483);
    env = stack[-1];
    v_8483 = Lminusp(nil, v_8483);
    env = stack[-1];
    if (v_8483 == nil) goto v_8468;
    v_8483 = nil;
    goto v_8462;
v_8468:
    v_8483 = stack[0];
    fn = elt(env, 3); // testred
    v_8483 = (*qfn1(fn))(fn, v_8483);
    env = stack[-1];
    v_8483 = stack[0];
    v_8483 = add1(v_8483);
    env = stack[-1];
    stack[0] = v_8483;
    goto v_8463;
v_8462:
    return onevalue(v_8483);
}



// Code for termordp!!

static LispObject CC_termordpB(LispObject env,
                         LispObject v_8459, LispObject v_8460)
{
    env = qenv(env);
    LispObject v_8486, v_8487, v_8488;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8460,v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8459,v_8460);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_8460;
    v_8488 = v_8459;
// end of prologue
    goto v_8470;
v_8466:
    v_8487 = v_8488;
    goto v_8467;
v_8468:
    v_8486 = stack[0];
    goto v_8469;
v_8470:
    goto v_8466;
v_8467:
    goto v_8468;
v_8469:
    if (equal(v_8487, v_8486)) goto v_8465;
    goto v_8478;
v_8474:
    v_8486 = v_8488;
    fn = elt(env, 1); // guesspftype
    stack[-1] = (*qfn1(fn))(fn, v_8486);
    env = stack[-2];
    goto v_8475;
v_8476:
    v_8486 = stack[0];
    fn = elt(env, 1); // guesspftype
    v_8486 = (*qfn1(fn))(fn, v_8486);
    env = stack[-2];
    goto v_8477;
v_8478:
    goto v_8474;
v_8475:
    goto v_8476;
v_8477:
    {
        LispObject v_8491 = stack[-1];
        fn = elt(env, 2); // termordp
        return (*qfn2(fn))(fn, v_8491, v_8486);
    }
v_8465:
    v_8486 = nil;
    goto v_8463;
    v_8486 = nil;
v_8463:
    return onevalue(v_8486);
}



// Code for nzeros

static LispObject CC_nzeros(LispObject env,
                         LispObject v_8459)
{
    env = qenv(env);
    LispObject v_8490, v_8491;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8459);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_8459;
// end of prologue
    stack[-1] = nil;
v_8464:
    goto v_8473;
v_8469:
    v_8491 = stack[0];
    goto v_8470;
v_8471:
    v_8490 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8472;
v_8473:
    goto v_8469;
v_8470:
    goto v_8471;
v_8472:
    if (v_8491 == v_8490) goto v_8467;
    else goto v_8468;
v_8467:
    v_8490 = stack[-1];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_8490);
    }
v_8468:
    goto v_8485;
v_8481:
    v_8491 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8482;
v_8483:
    v_8490 = stack[-1];
    goto v_8484;
v_8485:
    goto v_8481;
v_8482:
    goto v_8483;
v_8484:
    v_8490 = cons(v_8491, v_8490);
    env = stack[-2];
    stack[-1] = v_8490;
    v_8490 = stack[0];
    v_8490 = sub1(v_8490);
    env = stack[-2];
    stack[0] = v_8490;
    goto v_8464;
    v_8490 = nil;
    return onevalue(v_8490);
}



// Code for wi_new

static LispObject CC_wi_new(LispObject env,
                         LispObject v_8459)
{
    env = qenv(env);
    LispObject v_8488, v_8489;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8459);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_8459;
// end of prologue
    v_8488 = qvalue(elt(env, 1)); // wi_number
    v_8488 = add1(v_8488);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_8488; // wi_number
    goto v_8472;
v_8468:
    v_8489 = elt(env, 2); // !:
    goto v_8469;
v_8470:
    v_8488 = qvalue(elt(env, 1)); // wi_number
    goto v_8471;
v_8472:
    goto v_8468;
v_8469:
    goto v_8470;
v_8471:
    fn = elt(env, 4); // mkid
    v_8488 = (*qfn2(fn))(fn, v_8489, v_8488);
    env = stack[-4];
    v_8488 = Lintern(nil, v_8488);
    env = stack[-4];
    stack[-3] = v_8488;
    goto v_8482;
v_8476:
    stack[-1] = stack[-3];
    goto v_8477;
v_8478:
    stack[0] = elt(env, 3); // windex
    goto v_8479;
v_8480:
    v_8488 = stack[-2];
    v_8488 = ncons(v_8488);
    env = stack[-4];
    goto v_8481;
v_8482:
    goto v_8476;
v_8477:
    goto v_8478;
v_8479:
    goto v_8480;
v_8481:
    v_8488 = Lputprop(nil, 3, stack[-1], stack[0], v_8488);
    v_8488 = stack[-3];
    return onevalue(v_8488);
}



// Code for lalr_associativity

static LispObject CC_lalr_associativity(LispObject env,
                         LispObject v_8459)
{
    env = qenv(env);
    LispObject v_8480, v_8481;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8480 = v_8459;
// end of prologue
    goto v_8465;
v_8461:
    v_8481 = qvalue(elt(env, 1)); // precedence_table
    goto v_8462;
v_8463:
    goto v_8464;
v_8465:
    goto v_8461;
v_8462:
    goto v_8463;
v_8464:
    v_8480 = *(LispObject *)((char *)v_8481 + (CELL-TAG_VECTOR) + (((intptr_t)v_8480-TAG_FIXNUM)/(16/CELL)));
    v_8481 = v_8480;
    v_8480 = v_8481;
    if (v_8480 == nil) goto v_8473;
    v_8480 = v_8481;
    v_8480 = qcdr(v_8480);
    goto v_8471;
v_8473:
    v_8480 = nil;
    goto v_8471;
    v_8480 = nil;
v_8471:
    return onevalue(v_8480);
}



// Code for xread1

static LispObject CC_xread1(LispObject env,
                         LispObject v_8459)
{
    env = qenv(env);
    LispObject v_9834, v_9835, v_9836;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8459);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8459);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_8459;
// end of prologue
    stack[-8] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v_9834 = qvalue(elt(env, 1)); // commentlist!*
    if (v_9834 == nil) goto v_8496;
    v_9834 = qvalue(elt(env, 1)); // commentlist!*
    stack[-1] = v_9834;
    v_9834 = nil;
    qvalue(elt(env, 1)) = v_9834; // commentlist!*
    goto v_8494;
v_8496:
v_8494:
v_8471:
    v_9834 = qvalue(elt(env, 2)); // cursym!*
    stack[-3] = v_9834;
v_8472:
    v_9834 = stack[-3];
    if (symbolp(v_9834)) goto v_8504;
    goto v_8502;
v_8504:
    goto v_8513;
v_8509:
    v_9835 = stack[-3];
    goto v_8510;
v_8511:
    v_9834 = elt(env, 3); // !*lpar!*
    goto v_8512;
v_8513:
    goto v_8509;
v_8510:
    goto v_8511;
v_8512:
    if (v_9835 == v_9834) goto v_8507;
    else goto v_8508;
v_8507:
    goto v_8476;
v_8508:
    goto v_8522;
v_8518:
    v_9835 = stack[-3];
    goto v_8519;
v_8520:
    v_9834 = elt(env, 4); // !*rpar!*
    goto v_8521;
v_8522:
    goto v_8518;
v_8519:
    goto v_8520;
v_8521:
    if (v_9835 == v_9834) goto v_8516;
    else goto v_8517;
v_8516:
    goto v_8478;
v_8517:
    v_9834 = stack[-3];
    if (!symbolp(v_9834)) v_9834 = nil;
    else { v_9834 = qfastgets(v_9834);
           if (v_9834 != nil) { v_9834 = elt(v_9834, 23); // infix
#ifdef RECORD_GET
             if (v_9834 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_9834 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_9834 == SPID_NOPROP) v_9834 = nil; }}
#endif
    stack[-4] = v_9834;
    if (v_9834 == nil) goto v_8526;
    goto v_8479;
v_8526:
    v_9834 = stack[-3];
    if (!symbolp(v_9834)) v_9834 = nil;
    else { v_9834 = qfastgets(v_9834);
           if (v_9834 != nil) { v_9834 = elt(v_9834, 55); // delim
#ifdef RECORD_GET
             if (v_9834 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v_9834 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v_9834 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v_9834 == SPID_NOPROP) v_9834 = nil; else v_9834 = lisp_true; }}
#endif
    if (v_9834 == nil) goto v_8530;
    goto v_8490;
v_8530:
    v_9834 = stack[-3];
    if (!symbolp(v_9834)) v_9834 = nil;
    else { v_9834 = qfastgets(v_9834);
           if (v_9834 != nil) { v_9834 = elt(v_9834, 36); // stat
#ifdef RECORD_GET
             if (v_9834 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v_9834 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v_9834 == SPID_NOPROP) v_9834 = nil; }}
#endif
    stack[-4] = v_9834;
    if (v_9834 == nil) goto v_8534;
    goto v_8489;
v_8534:
    v_9834 = qvalue(elt(env, 5)); // !*reduce4
    if (v_9834 == nil) goto v_8541;
    else goto v_8542;
v_8541:
    goto v_8549;
v_8545:
    v_9835 = stack[-3];
    goto v_8546;
v_8547:
    v_9834 = elt(env, 6); // type
    goto v_8548;
v_8549:
    goto v_8545;
v_8546:
    goto v_8547;
v_8548:
    v_9834 = Lflagp(nil, v_9835, v_9834);
    env = stack[-9];
    goto v_8540;
v_8542:
    v_9834 = nil;
    goto v_8540;
    v_9834 = nil;
v_8540:
    if (v_9834 == nil) goto v_8538;
    goto v_8560;
v_8556:
    goto v_8566;
v_8562:
    v_9835 = elt(env, 7); // decstat
    goto v_8563;
v_8564:
    v_9834 = nil;
    goto v_8565;
v_8566:
    goto v_8562;
v_8563:
    goto v_8564;
v_8565:
    fn = elt(env, 48); // lispapply
    v_9835 = (*qfn2(fn))(fn, v_9835, v_9834);
    env = stack[-9];
    goto v_8557;
v_8558:
    v_9834 = stack[-6];
    goto v_8559;
v_8560:
    goto v_8556;
v_8557:
    goto v_8558;
v_8559:
    v_9834 = cons(v_9835, v_9834);
    env = stack[-9];
    stack[-6] = v_9834;
    goto v_8471;
v_8538:
v_8502:
v_8473:
    v_9834 = nil;
    stack[-4] = v_9834;
v_8474:
    goto v_8576;
v_8572:
    v_9835 = stack[-3];
    goto v_8573;
v_8574:
    v_9834 = stack[-6];
    goto v_8575;
v_8576:
    goto v_8572;
v_8573:
    goto v_8574;
v_8575:
    v_9834 = cons(v_9835, v_9834);
    env = stack[-9];
    stack[-6] = v_9834;
    v_9834 = stack[-3];
    fn = elt(env, 49); // toknump
    v_9834 = (*qfn1(fn))(fn, v_9834);
    env = stack[-9];
    if (v_9834 == nil) goto v_8582;
    goto v_8595;
v_8591:
    v_9835 = stack[-2];
    goto v_8592;
v_8593:
    v_9834 = qvalue(elt(env, 8)); // !$eol!$
    goto v_8594;
v_8595:
    goto v_8591;
v_8592:
    goto v_8593;
v_8594:
    if (v_9835 == v_9834) goto v_8590;
    v_9834 = qvalue(elt(env, 9)); // nxtsym!*
    fn = elt(env, 50); // chknewnam
    v_9834 = (*qfn1(fn))(fn, v_9834);
    env = stack[-9];
    stack[-2] = v_9834;
    if (symbolp(v_9834)) goto v_8601;
    v_9834 = nil;
    goto v_8599;
v_8601:
    v_9834 = stack[-2];
    if (!symbolp(v_9834)) v_9834 = nil;
    else { v_9834 = qfastgets(v_9834);
           if (v_9834 != nil) { v_9834 = elt(v_9834, 55); // delim
#ifdef RECORD_GET
             if (v_9834 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v_9834 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v_9834 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v_9834 == SPID_NOPROP) v_9834 = nil; else v_9834 = lisp_true; }}
#endif
    if (v_9834 == nil) goto v_8609;
    else goto v_8610;
v_8609:
    v_9834 = stack[-2];
    if (!symbolp(v_9834)) v_9834 = nil;
    else { v_9834 = qfastgets(v_9834);
           if (v_9834 != nil) { v_9834 = elt(v_9834, 11); // switch!*
#ifdef RECORD_GET
             if (v_9834 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v_9834 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v_9834 == SPID_NOPROP) v_9834 = nil; }}
#endif
    if (v_9834 == nil) goto v_8615;
    goto v_8625;
v_8621:
    v_9835 = stack[-2];
    goto v_8622;
v_8623:
    v_9834 = elt(env, 10); // !(
    goto v_8624;
v_8625:
    goto v_8621;
v_8622:
    goto v_8623;
v_8624:
    if (v_9835 == v_9834) goto v_8615;
    goto v_8616;
v_8615:
    v_9834 = stack[-2];
    if (!symbolp(v_9834)) v_9834 = nil;
    else { v_9834 = qfastgets(v_9834);
           if (v_9834 != nil) { v_9834 = elt(v_9834, 23); // infix
#ifdef RECORD_GET
             if (v_9834 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_9834 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_9834 == SPID_NOPROP) v_9834 = nil; }}
#endif
    if (v_9834 == nil) goto v_8630;
    else goto v_8631;
v_8630:
    v_9834 = qvalue(elt(env, 11)); // !*eoldelimp
    if (v_9834 == nil) goto v_8636;
    else goto v_8637;
v_8636:
    v_9834 = nil;
    goto v_8635;
v_8637:
    goto v_8646;
v_8642:
    v_9835 = stack[-2];
    goto v_8643;
v_8644:
    v_9834 = qvalue(elt(env, 8)); // !$eol!$
    goto v_8645;
v_8646:
    goto v_8642;
v_8643:
    goto v_8644;
v_8645:
    v_9834 = (v_9835 == v_9834 ? lisp_true : nil);
    goto v_8635;
    v_9834 = nil;
v_8635:
    v_9834 = (v_9834 == nil ? lisp_true : nil);
    goto v_8629;
v_8631:
    v_9834 = nil;
    goto v_8629;
    v_9834 = nil;
v_8629:
    goto v_8614;
v_8616:
    v_9834 = nil;
    goto v_8614;
    v_9834 = nil;
v_8614:
    goto v_8608;
v_8610:
    v_9834 = nil;
    goto v_8608;
    v_9834 = nil;
v_8608:
    goto v_8599;
    v_9834 = nil;
v_8599:
    goto v_8588;
v_8590:
    v_9834 = nil;
    goto v_8588;
    v_9834 = nil;
v_8588:
    if (v_9834 == nil) goto v_8582;
    v_9834 = elt(env, 12); // times
    qvalue(elt(env, 2)) = v_9834; // cursym!*
    v_9834 = nil;
    qvalue(elt(env, 13)) = v_9834; // curescaped!*
    goto v_8471;
v_8582:
    goto v_8675;
v_8671:
    v_9835 = stack[-7];
    goto v_8672;
v_8673:
    v_9834 = elt(env, 14); // proc
    goto v_8674;
v_8675:
    goto v_8671;
v_8672:
    goto v_8673;
v_8674:
    if (v_9835 == v_9834) goto v_8669;
    else goto v_8670;
v_8669:
    goto v_8683;
v_8679:
    v_9834 = stack[-6];
    v_9835 = Llength(nil, v_9834);
    env = stack[-9];
    goto v_8680;
v_8681:
    v_9834 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_8682;
v_8683:
    goto v_8679;
v_8680:
    goto v_8681;
v_8682:
    v_9834 = (LispObject)greaterp2(v_9835, v_9834);
    v_9834 = v_9834 ? lisp_true : nil;
    env = stack[-9];
    goto v_8668;
v_8670:
    v_9834 = nil;
    goto v_8668;
    v_9834 = nil;
v_8668:
    if (v_9834 == nil) goto v_8666;
    goto v_8695;
v_8691:
    v_9835 = elt(env, 15); // "Syntax error in procedure header"
    goto v_8692;
v_8693:
    v_9834 = nil;
    goto v_8694;
v_8695:
    goto v_8691;
v_8692:
    goto v_8693;
v_8694:
    fn = elt(env, 51); // symerr
    v_9834 = (*qfn2(fn))(fn, v_9835, v_9834);
    env = stack[-9];
    goto v_8580;
v_8666:
v_8580:
v_8475:
    fn = elt(env, 52); // scan
    v_9834 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    stack[-3] = v_9834;
    goto v_8472;
v_8476:
    fn = elt(env, 53); // eolcheck
    v_9834 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    v_9834 = nil;
    stack[-4] = v_9834;
    goto v_8709;
v_8705:
    fn = elt(env, 52); // scan
    v_9835 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    goto v_8706;
v_8707:
    v_9834 = elt(env, 4); // !*rpar!*
    goto v_8708;
v_8709:
    goto v_8705;
v_8706:
    goto v_8707;
v_8708:
    if (v_9835 == v_9834) goto v_8703;
    else goto v_8704;
v_8703:
    goto v_8477;
v_8704:
    goto v_8719;
v_8715:
    v_9835 = stack[-6];
    goto v_8716;
v_8717:
    v_9834 = elt(env, 16); // struct
    goto v_8718;
v_8719:
    goto v_8715;
v_8716:
    goto v_8717;
v_8718:
    v_9834 = Lflagpcar(nil, v_9835, v_9834);
    env = stack[-9];
    if (v_9834 == nil) goto v_8713;
    v_9834 = stack[-6];
    v_9834 = qcar(v_9834);
    v_9834 = CC_xread1(elt(env, 0), v_9834);
    env = stack[-9];
    stack[-3] = v_9834;
    goto v_8702;
v_8713:
    v_9834 = elt(env, 17); // paren
    v_9834 = CC_xread1(elt(env, 0), v_9834);
    env = stack[-9];
    stack[-3] = v_9834;
    goto v_8702;
v_8702:
    goto v_8738;
v_8734:
    v_9835 = stack[-7];
    goto v_8735;
v_8736:
    v_9834 = elt(env, 16); // struct
    goto v_8737;
v_8738:
    goto v_8734;
v_8735:
    goto v_8736;
v_8737:
    v_9834 = Lflagp(nil, v_9835, v_9834);
    env = stack[-9];
    if (v_9834 == nil) goto v_8732;
    v_9834 = stack[-3];
    fn = elt(env, 54); // remcomma
    v_9834 = (*qfn1(fn))(fn, v_9834);
    env = stack[-9];
    stack[-3] = v_9834;
    goto v_8474;
v_8732:
    goto v_8750;
v_8746:
    v_9835 = stack[-3];
    goto v_8747;
v_8748:
    v_9834 = elt(env, 18); // !*comma!*
    goto v_8749;
v_8750:
    goto v_8746;
v_8747:
    goto v_8748;
v_8749:
    if (!consp(v_9835)) goto v_8743;
    v_9835 = qcar(v_9835);
    if (v_9835 == v_9834) goto v_8744;
v_8743:
    goto v_8474;
v_8744:
    v_9834 = stack[-6];
    if (v_9834 == nil) goto v_8753;
    else goto v_8754;
v_8753:
    goto v_8764;
v_8760:
    v_9835 = stack[-7];
    goto v_8761;
v_8762:
    v_9834 = elt(env, 19); // lambda
    goto v_8763;
v_8764:
    goto v_8760;
v_8761:
    goto v_8762;
v_8763:
    if (v_9835 == v_9834) goto v_8758;
    else goto v_8759;
v_8758:
    goto v_8474;
v_8759:
    goto v_8774;
v_8770:
    v_9835 = elt(env, 20); // "Improper delimiter"
    goto v_8771;
v_8772:
    v_9834 = nil;
    goto v_8773;
v_8774:
    goto v_8770;
v_8771:
    goto v_8772;
v_8773:
    fn = elt(env, 51); // symerr
    v_9834 = (*qfn2(fn))(fn, v_9835, v_9834);
    env = stack[-9];
    goto v_8757;
v_8757:
    goto v_8730;
v_8754:
    goto v_8786;
v_8780:
    v_9834 = stack[-6];
    v_9836 = qcar(v_9834);
    goto v_8781;
v_8782:
    v_9834 = stack[-3];
    v_9835 = qcdr(v_9834);
    goto v_8783;
v_8784:
    v_9834 = stack[-6];
    v_9834 = qcdr(v_9834);
    goto v_8785;
v_8786:
    goto v_8780;
v_8781:
    goto v_8782;
v_8783:
    goto v_8784;
v_8785:
    v_9834 = acons(v_9836, v_9835, v_9834);
    env = stack[-9];
    stack[-6] = v_9834;
    goto v_8730;
v_8730:
    goto v_8475;
v_8477:
    v_9834 = stack[-6];
    if (v_9834 == nil) goto v_8796;
    goto v_8803;
v_8799:
    v_9834 = stack[-6];
    v_9834 = qcar(v_9834);
    v_9835 = ncons(v_9834);
    env = stack[-9];
    goto v_8800;
v_8801:
    v_9834 = stack[-6];
    v_9834 = qcdr(v_9834);
    goto v_8802;
v_8803:
    goto v_8799;
v_8800:
    goto v_8801;
v_8802:
    v_9834 = cons(v_9835, v_9834);
    env = stack[-9];
    stack[-6] = v_9834;
    goto v_8794;
v_8796:
v_8794:
    goto v_8475;
v_8478:
    v_9834 = stack[-7];
    if (v_9834 == nil) goto v_8815;
    else goto v_8816;
v_8815:
    v_9834 = lisp_true;
    goto v_8814;
v_8816:
    goto v_8829;
v_8825:
    v_9835 = stack[-7];
    goto v_8826;
v_8827:
    v_9834 = elt(env, 21); // group
    goto v_8828;
v_8829:
    goto v_8825;
v_8826:
    goto v_8827;
v_8828:
    if (v_9835 == v_9834) goto v_8823;
    else goto v_8824;
v_8823:
    v_9834 = lisp_true;
    goto v_8822;
v_8824:
    goto v_8839;
v_8835:
    v_9835 = stack[-7];
    goto v_8836;
v_8837:
    v_9834 = elt(env, 14); // proc
    goto v_8838;
v_8839:
    goto v_8835;
v_8836:
    goto v_8837;
v_8838:
    v_9834 = (v_9835 == v_9834 ? lisp_true : nil);
    goto v_8822;
    v_9834 = nil;
v_8822:
    goto v_8814;
    v_9834 = nil;
v_8814:
    if (v_9834 == nil) goto v_8812;
    goto v_8848;
v_8844:
    v_9835 = elt(env, 22); // "Too many right parentheses"
    goto v_8845;
v_8846:
    v_9834 = nil;
    goto v_8847;
v_8848:
    goto v_8844;
v_8845:
    goto v_8846;
v_8847:
    fn = elt(env, 51); // symerr
    v_9834 = (*qfn2(fn))(fn, v_9835, v_9834);
    env = stack[-9];
    goto v_8810;
v_8812:
    goto v_8491;
v_8810:
v_8479:
    fn = elt(env, 53); // eolcheck
    v_9834 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    goto v_8866;
v_8862:
    v_9835 = stack[-3];
    goto v_8863;
v_8864:
    v_9834 = elt(env, 18); // !*comma!*
    goto v_8865;
v_8866:
    goto v_8862;
v_8863:
    goto v_8864;
v_8865:
    if (v_9835 == v_9834) goto v_8860;
    else goto v_8861;
v_8860:
    v_9834 = lisp_true;
    goto v_8859;
v_8861:
    fn = elt(env, 52); // scan
    v_9834 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    stack[-2] = v_9834;
    if (!consp(v_9834)) goto v_8875;
    v_9834 = lisp_true;
    goto v_8873;
v_8875:
    v_9834 = stack[-2];
    fn = elt(env, 49); // toknump
    v_9834 = (*qfn1(fn))(fn, v_9834);
    env = stack[-9];
    goto v_8873;
    v_9834 = nil;
v_8873:
    goto v_8859;
    v_9834 = nil;
v_8859:
    if (v_9834 == nil) goto v_8857;
    goto v_8480;
v_8857:
    goto v_8892;
v_8888:
    v_9835 = stack[-2];
    goto v_8889;
v_8890:
    v_9834 = elt(env, 4); // !*rpar!*
    goto v_8891;
v_8892:
    goto v_8888;
v_8889:
    goto v_8890;
v_8891:
    if (v_9835 == v_9834) goto v_8886;
    else goto v_8887;
v_8886:
    v_9834 = lisp_true;
    goto v_8885;
v_8887:
    goto v_8906;
v_8902:
    v_9835 = stack[-2];
    goto v_8903;
v_8904:
    v_9834 = elt(env, 18); // !*comma!*
    goto v_8905;
v_8906:
    goto v_8902;
v_8903:
    goto v_8904;
v_8905:
    if (v_9835 == v_9834) goto v_8900;
    else goto v_8901;
v_8900:
    v_9834 = lisp_true;
    goto v_8899;
v_8901:
    v_9834 = stack[-2];
    if (!symbolp(v_9834)) v_9834 = nil;
    else { v_9834 = qfastgets(v_9834);
           if (v_9834 != nil) { v_9834 = elt(v_9834, 55); // delim
#ifdef RECORD_GET
             if (v_9834 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v_9834 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v_9834 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v_9834 == SPID_NOPROP) v_9834 = nil; else v_9834 = lisp_true; }}
#endif
    goto v_8899;
    v_9834 = nil;
v_8899:
    goto v_8885;
    v_9834 = nil;
v_8885:
    if (v_9834 == nil) goto v_8883;
    goto v_8481;
v_8883:
    goto v_8924;
v_8920:
    v_9835 = stack[-2];
    goto v_8921;
v_8922:
    v_9834 = elt(env, 3); // !*lpar!*
    goto v_8923;
v_8924:
    goto v_8920;
v_8921:
    goto v_8922;
v_8923:
    if (v_9835 == v_9834) goto v_8918;
    else goto v_8919;
v_8918:
    fn = elt(env, 53); // eolcheck
    v_9834 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    if (v_9834 == nil) goto v_8929;
    else goto v_8930;
v_8929:
    v_9834 = elt(env, 17); // paren
    fn = elt(env, 55); // xread
    v_9834 = (*qfn1(fn))(fn, v_9834);
    env = stack[-9];
    stack[-2] = v_9834;
    if (!consp(v_9834)) goto v_8935;
    goto v_8946;
v_8942:
    v_9834 = stack[-2];
    v_9835 = qcar(v_9834);
    goto v_8943;
v_8944:
    v_9834 = elt(env, 18); // !*comma!*
    goto v_8945;
v_8946:
    goto v_8942;
v_8943:
    goto v_8944;
v_8945:
    if (v_9835 == v_9834) goto v_8940;
    else goto v_8941;
v_8940:
    goto v_8955;
v_8951:
    v_9835 = stack[-3];
    goto v_8952;
v_8953:
    v_9834 = stack[-2];
    v_9834 = qcdr(v_9834);
    goto v_8954;
v_8955:
    goto v_8951;
v_8952:
    goto v_8953;
v_8954:
    v_9834 = cons(v_9835, v_9834);
    env = stack[-9];
    stack[-3] = v_9834;
    goto v_8939;
v_8941:
    v_9834 = nil;
    goto v_8939;
    v_9834 = nil;
v_8939:
    goto v_8933;
v_8935:
    v_9834 = nil;
    goto v_8933;
    v_9834 = nil;
v_8933:
    goto v_8928;
v_8930:
    v_9834 = nil;
    goto v_8928;
    v_9834 = nil;
v_8928:
    goto v_8917;
v_8919:
    v_9834 = nil;
    goto v_8917;
    v_9834 = nil;
v_8917:
    if (v_9834 == nil) goto v_8915;
    goto v_8472;
v_8915:
v_8480:
    v_9834 = stack[-6];
    if (v_9834 == nil) goto v_8974;
    goto v_8483;
v_8974:
    goto v_8983;
v_8979:
    v_9835 = stack[-3];
    goto v_8980;
v_8981:
    v_9834 = elt(env, 23); // unary
    goto v_8982;
v_8983:
    goto v_8979;
v_8980:
    goto v_8981;
v_8982:
    v_9834 = get(v_9835, v_9834);
    env = stack[-9];
    stack[-3] = v_9834;
    if (v_9834 == nil) goto v_8976;
    else goto v_8977;
v_8976:
    goto v_8991;
v_8987:
    v_9835 = elt(env, 24); // "Redundant operator"
    goto v_8988;
v_8989:
    v_9834 = nil;
    goto v_8990;
v_8991:
    goto v_8987;
v_8988:
    goto v_8989;
v_8990:
    fn = elt(env, 51); // symerr
    v_9834 = (*qfn2(fn))(fn, v_9835, v_9834);
    env = stack[-9];
    goto v_8972;
v_8977:
v_8972:
    goto v_8999;
v_8995:
    v_9835 = elt(env, 25); // !*!*un!*!*
    goto v_8996;
v_8997:
    v_9834 = stack[-8];
    goto v_8998;
v_8999:
    goto v_8995;
v_8996:
    goto v_8997;
v_8998:
    v_9834 = cons(v_9835, v_9834);
    env = stack[-9];
    stack[-8] = v_9834;
    goto v_8487;
v_8481:
    v_9834 = stack[-4];
    if (v_9834 == nil) goto v_9005;
    v_9834 = nil;
    stack[-4] = v_9834;
    goto v_9003;
v_9005:
v_9003:
    goto v_9013;
v_9009:
    v_9835 = stack[-3];
    goto v_9010;
v_9011:
    v_9834 = stack[-6];
    goto v_9012;
v_9013:
    goto v_9009;
v_9010:
    goto v_9011;
v_9012:
    v_9834 = cons(v_9835, v_9834);
    env = stack[-9];
    stack[-6] = v_9834;
v_8482:
    v_9834 = stack[-2];
    stack[-3] = v_9834;
    goto v_8472;
v_8483:
    v_9834 = stack[-6];
    if (v_9834 == nil) goto v_9019;
    else goto v_9020;
v_9019:
    goto v_9027;
v_9023:
    v_9835 = elt(env, 20); // "Improper delimiter"
    goto v_9024;
v_9025:
    v_9834 = nil;
    goto v_9026;
v_9027:
    goto v_9023;
v_9024:
    goto v_9025;
v_9026:
    fn = elt(env, 51); // symerr
    v_9834 = (*qfn2(fn))(fn, v_9835, v_9834);
    env = stack[-9];
    goto v_9018;
v_9020:
v_9018:
    goto v_9035;
v_9031:
    v_9834 = stack[-6];
    v_9835 = qcar(v_9834);
    goto v_9032;
v_9033:
    v_9834 = stack[-3];
    goto v_9034;
v_9035:
    goto v_9031;
v_9032:
    goto v_9033;
v_9034:
    fn = elt(env, 56); // mkvar
    v_9834 = (*qfn2(fn))(fn, v_9835, v_9834);
    env = stack[-9];
    stack[0] = v_9834;
v_8484:
    v_9834 = stack[-6];
    v_9834 = qcdr(v_9834);
    stack[-6] = v_9834;
    v_9834 = stack[-6];
    if (v_9834 == nil) goto v_9043;
    else goto v_9044;
v_9043:
    goto v_8485;
v_9044:
    v_9834 = stack[-6];
    v_9834 = qcar(v_9834);
    if (!consp(v_9834)) goto v_9050;
    else goto v_9051;
v_9050:
    v_9834 = stack[-6];
    v_9834 = qcar(v_9834);
    v_9834 = Lsymbolp(nil, v_9834);
    env = stack[-9];
    v_9834 = (v_9834 == nil ? lisp_true : nil);
    goto v_9049;
v_9051:
    v_9834 = nil;
    goto v_9049;
    v_9834 = nil;
v_9049:
    if (v_9834 == nil) goto v_9047;
    goto v_9066;
v_9062:
    v_9835 = elt(env, 26); // "Missing operator"
    goto v_9063;
v_9064:
    v_9834 = nil;
    goto v_9065;
v_9066:
    goto v_9062;
v_9063:
    goto v_9064;
v_9065:
    fn = elt(env, 51); // symerr
    v_9834 = (*qfn2(fn))(fn, v_9835, v_9834);
    env = stack[-9];
    goto v_9042;
v_9047:
v_9042:
    goto v_9074;
v_9070:
    v_9834 = stack[-6];
    v_9835 = qcar(v_9834);
    goto v_9071;
v_9072:
    v_9834 = stack[0];
    goto v_9073;
v_9074:
    goto v_9070;
v_9071:
    goto v_9072;
v_9073:
    v_9834 = list2(v_9835, v_9834);
    env = stack[-9];
    stack[0] = v_9834;
    goto v_8484;
v_8485:
    goto v_9083;
v_9079:
    v_9835 = stack[0];
    goto v_9080;
v_9081:
    v_9834 = stack[-8];
    goto v_9082;
v_9083:
    goto v_9079;
v_9080:
    goto v_9081;
v_9082:
    v_9834 = cons(v_9835, v_9834);
    env = stack[-9];
    stack[-8] = v_9834;
v_8486:
    v_9834 = stack[-5];
    if (v_9834 == nil) goto v_9088;
    else goto v_9089;
v_9088:
    goto v_9099;
v_9095:
    v_9835 = stack[-4];
    goto v_9096;
v_9097:
    v_9834 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9098;
v_9099:
    goto v_9095;
v_9096:
    goto v_9097;
v_9098:
    if (v_9835 == v_9834) goto v_9093;
    else goto v_9094;
v_9093:
    goto v_8492;
v_9094:
    goto v_9092;
v_9092:
    goto v_9087;
v_9089:
    v_9834 = stack[-8];
    if (v_9834 == nil) goto v_9106;
    goto v_9119;
v_9115:
    v_9834 = stack[-8];
    v_9835 = qcdr(v_9834);
    goto v_9116;
v_9117:
    v_9834 = elt(env, 25); // !*!*un!*!*
    goto v_9118;
v_9119:
    goto v_9115;
v_9116:
    goto v_9117;
v_9118:
    if (!consp(v_9835)) goto v_9113;
    v_9835 = qcar(v_9835);
    if (v_9835 == v_9834) goto v_9112;
    else goto v_9113;
v_9112:
    v_9834 = stack[-5];
    v_9834 = qcdr(v_9834);
    if (v_9834 == nil) goto v_9125;
    else goto v_9126;
v_9125:
    v_9834 = nil;
    goto v_9124;
v_9126:
    goto v_9141;
v_9137:
    v_9835 = stack[-4];
    goto v_9138;
v_9139:
    v_9834 = stack[-5];
    v_9834 = qcar(v_9834);
    v_9834 = qcar(v_9834);
    goto v_9140;
v_9141:
    goto v_9137;
v_9138:
    goto v_9139;
v_9140:
    v_9834 = (LispObject)geq2(v_9835, v_9834);
    v_9834 = v_9834 ? lisp_true : nil;
    env = stack[-9];
    if (v_9834 == nil) goto v_9134;
    else goto v_9135;
v_9134:
    v_9834 = nil;
    goto v_9133;
v_9135:
    goto v_9154;
v_9150:
    v_9835 = stack[-4];
    goto v_9151;
v_9152:
    v_9834 = stack[-5];
    v_9834 = qcdr(v_9834);
    v_9834 = qcar(v_9834);
    v_9834 = qcar(v_9834);
    goto v_9153;
v_9154:
    goto v_9150;
v_9151:
    goto v_9152;
v_9153:
    v_9834 = (LispObject)lesseq2(v_9835, v_9834);
    v_9834 = v_9834 ? lisp_true : nil;
    env = stack[-9];
    goto v_9133;
    v_9834 = nil;
v_9133:
    goto v_9124;
    v_9834 = nil;
v_9124:
    goto v_9111;
v_9113:
    v_9834 = nil;
    goto v_9111;
    v_9834 = nil;
v_9111:
    if (v_9834 == nil) goto v_9106;
    goto v_9168;
v_9164:
    v_9835 = elt(env, 27); // "Please use parentheses around use of the unary operator"
    goto v_9165;
v_9166:
    v_9834 = nil;
    goto v_9167;
v_9168:
    goto v_9164;
v_9165:
    goto v_9166;
v_9167:
    fn = elt(env, 51); // symerr
    v_9834 = (*qfn2(fn))(fn, v_9835, v_9834);
    env = stack[-9];
    goto v_9087;
v_9106:
    goto v_9179;
v_9175:
    v_9835 = stack[-4];
    goto v_9176;
v_9177:
    v_9834 = stack[-5];
    v_9834 = qcar(v_9834);
    v_9834 = qcar(v_9834);
    goto v_9178;
v_9179:
    goto v_9175;
v_9176:
    goto v_9177;
v_9178:
    v_9834 = (LispObject)lessp2(v_9835, v_9834);
    v_9834 = v_9834 ? lisp_true : nil;
    env = stack[-9];
    if (v_9834 == nil) goto v_9173;
    else goto v_9171;
v_9173:
    goto v_9193;
v_9189:
    v_9835 = stack[-4];
    goto v_9190;
v_9191:
    v_9834 = stack[-5];
    v_9834 = qcar(v_9834);
    v_9834 = qcar(v_9834);
    goto v_9192;
v_9193:
    goto v_9189;
v_9190:
    goto v_9191;
v_9192:
    if (equal(v_9835, v_9834)) goto v_9187;
    else goto v_9188;
v_9187:
    goto v_9210;
v_9206:
    v_9835 = stack[-3];
    goto v_9207;
v_9208:
    v_9834 = stack[-5];
    v_9834 = qcar(v_9834);
    v_9834 = qcdr(v_9834);
    goto v_9209;
v_9210:
    goto v_9206;
v_9207:
    goto v_9208;
v_9209:
    if (v_9835 == v_9834) goto v_9204;
    else goto v_9205;
v_9204:
    v_9834 = stack[-3];
    if (!symbolp(v_9834)) v_9834 = nil;
    else { v_9834 = qfastgets(v_9834);
           if (v_9834 != nil) { v_9834 = elt(v_9834, 35); // nary
#ifdef RECORD_GET
             if (v_9834 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v_9834 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v_9834 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v_9834 == SPID_NOPROP) v_9834 = nil; else v_9834 = lisp_true; }}
#endif
    if (v_9834 == nil) goto v_9217;
    else goto v_9218;
v_9217:
    goto v_9226;
v_9222:
    v_9835 = stack[-3];
    goto v_9223;
v_9224:
    v_9834 = elt(env, 28); // right
    goto v_9225;
v_9226:
    goto v_9222;
v_9223:
    goto v_9224;
v_9225:
    v_9834 = Lflagp(nil, v_9835, v_9834);
    env = stack[-9];
    v_9834 = (v_9834 == nil ? lisp_true : nil);
    goto v_9216;
v_9218:
    v_9834 = nil;
    goto v_9216;
    v_9834 = nil;
v_9216:
    goto v_9203;
v_9205:
    v_9834 = nil;
    goto v_9203;
    v_9834 = nil;
v_9203:
    if (v_9834 == nil) goto v_9201;
    v_9834 = lisp_true;
    goto v_9199;
v_9201:
    v_9834 = stack[-5];
    v_9834 = qcar(v_9834);
    v_9834 = qcdr(v_9834);
    if (!symbolp(v_9834)) v_9834 = nil;
    else { v_9834 = qfastgets(v_9834);
           if (v_9834 != nil) { v_9834 = elt(v_9834, 49); // alt
#ifdef RECORD_GET
             if (v_9834 != SPID_NOPROP)
                record_get(elt(fastget_names, 49), 1);
             else record_get(elt(fastget_names, 49), 0),
                v_9834 = nil; }
           else record_get(elt(fastget_names, 49), 0); }
#else
             if (v_9834 == SPID_NOPROP) v_9834 = nil; }}
#endif
    goto v_9199;
    v_9834 = nil;
v_9199:
    goto v_9186;
v_9188:
    v_9834 = nil;
    goto v_9186;
    v_9834 = nil;
v_9186:
    if (v_9834 == nil) goto v_9184;
    else goto v_9171;
v_9184:
    goto v_9172;
v_9171:
    goto v_8488;
v_9172:
v_9087:
v_8487:
    goto v_9253;
v_9247:
    v_9836 = stack[-4];
    goto v_9248;
v_9249:
    v_9835 = stack[-3];
    goto v_9250;
v_9251:
    v_9834 = stack[-5];
    goto v_9252;
v_9253:
    goto v_9247;
v_9248:
    goto v_9249;
v_9250:
    goto v_9251;
v_9252:
    v_9834 = acons(v_9836, v_9835, v_9834);
    env = stack[-9];
    stack[-5] = v_9834;
    goto v_9265;
v_9261:
    v_9835 = stack[-3];
    goto v_9262;
v_9263:
    v_9834 = elt(env, 18); // !*comma!*
    goto v_9264;
v_9265:
    goto v_9261;
v_9262:
    goto v_9263;
v_9264:
    if (v_9835 == v_9834) goto v_9260;
    goto v_8482;
v_9260:
    v_9834 = stack[-5];
    v_9834 = qcdr(v_9834);
    if (v_9834 == nil) goto v_9270;
    else goto v_9268;
v_9270:
    v_9834 = stack[-7];
    if (v_9834 == nil) goto v_9276;
    else goto v_9277;
v_9276:
    v_9834 = lisp_true;
    goto v_9275;
v_9277:
    goto v_9289;
v_9285:
    v_9835 = stack[-7];
    goto v_9286;
v_9287:
    v_9834 = elt(env, 29); // (lambda paren)
    goto v_9288;
v_9289:
    goto v_9285;
v_9286:
    goto v_9287;
v_9288:
    v_9834 = Lmemq(nil, v_9835, v_9834);
    if (v_9834 == nil) goto v_9284;
    else goto v_9283;
v_9284:
    goto v_9298;
v_9294:
    v_9835 = stack[-7];
    goto v_9295;
v_9296:
    v_9834 = elt(env, 16); // struct
    goto v_9297;
v_9298:
    goto v_9294;
v_9295:
    goto v_9296;
v_9297:
    v_9834 = Lflagp(nil, v_9835, v_9834);
    env = stack[-9];
v_9283:
    goto v_9275;
    v_9834 = nil;
v_9275:
    if (v_9834 == nil) goto v_9273;
    else goto v_9268;
v_9273:
    goto v_9269;
v_9268:
    goto v_8475;
v_9269:
    goto v_8492;
v_8488:
    goto v_9316;
v_9312:
    v_9834 = stack[-8];
    v_9834 = qcdr(v_9834);
    v_9835 = qcar(v_9834);
    goto v_9313;
v_9314:
    v_9834 = elt(env, 30); // not
    goto v_9315;
v_9316:
    goto v_9312;
v_9313:
    goto v_9314;
v_9315:
    if (!consp(v_9835)) goto v_9310;
    v_9835 = qcar(v_9835);
    if (v_9835 == v_9834) goto v_9309;
    else goto v_9310;
v_9309:
    goto v_9326;
v_9322:
    v_9834 = stack[-5];
    v_9834 = qcar(v_9834);
    v_9835 = qcar(v_9834);
    goto v_9323;
v_9324:
    v_9834 = elt(env, 31); // member
    if (!symbolp(v_9834)) v_9834 = nil;
    else { v_9834 = qfastgets(v_9834);
           if (v_9834 != nil) { v_9834 = elt(v_9834, 23); // infix
#ifdef RECORD_GET
             if (v_9834 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_9834 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_9834 == SPID_NOPROP) v_9834 = nil; }}
#endif
    goto v_9325;
v_9326:
    goto v_9322;
v_9323:
    goto v_9324;
v_9325:
    v_9834 = (LispObject)geq2(v_9835, v_9834);
    v_9834 = v_9834 ? lisp_true : nil;
    env = stack[-9];
    goto v_9308;
v_9310:
    v_9834 = nil;
    goto v_9308;
    v_9834 = nil;
v_9308:
    if (v_9834 == nil) goto v_9306;
    goto v_9340;
v_9336:
    v_9835 = elt(env, 32); // "NOT"
    goto v_9337;
v_9338:
    v_9834 = elt(env, 33); // "infix operator"
    goto v_9339;
v_9340:
    goto v_9336;
v_9337:
    goto v_9338;
v_9339:
    fn = elt(env, 57); // typerr
    v_9834 = (*qfn2(fn))(fn, v_9835, v_9834);
    env = stack[-9];
    goto v_9304;
v_9306:
v_9304:
    goto v_9351;
v_9347:
    v_9834 = stack[-8];
    v_9834 = qcdr(v_9834);
    v_9835 = qcar(v_9834);
    goto v_9348;
v_9349:
    v_9834 = elt(env, 25); // !*!*un!*!*
    goto v_9350;
v_9351:
    goto v_9347;
v_9348:
    goto v_9349;
v_9350:
    if (v_9835 == v_9834) goto v_9345;
    else goto v_9346;
v_9345:
    goto v_9364;
v_9360:
    v_9834 = stack[-8];
    v_9835 = qcar(v_9834);
    goto v_9361;
v_9362:
    v_9834 = elt(env, 25); // !*!*un!*!*
    goto v_9363;
v_9364:
    goto v_9360;
v_9361:
    goto v_9362;
v_9363:
    if (v_9835 == v_9834) goto v_9358;
    else goto v_9359;
v_9358:
    goto v_8487;
v_9359:
    goto v_9375;
v_9371:
    v_9834 = stack[-5];
    v_9834 = qcar(v_9834);
    v_9835 = qcdr(v_9834);
    goto v_9372;
v_9373:
    v_9834 = stack[-8];
    v_9834 = qcar(v_9834);
    goto v_9374;
v_9375:
    goto v_9371;
v_9372:
    goto v_9373;
v_9374:
    v_9834 = list2(v_9835, v_9834);
    env = stack[-9];
    stack[0] = v_9834;
    goto v_9357;
v_9357:
    goto v_9344;
v_9346:
    goto v_9388;
v_9384:
    v_9834 = stack[-5];
    v_9834 = qcar(v_9834);
    stack[0] = qcdr(v_9834);
    goto v_9385;
v_9386:
    goto v_9405;
v_9401:
    v_9834 = stack[-8];
    v_9835 = qcar(v_9834);
    goto v_9402;
v_9403:
    v_9834 = stack[-5];
    v_9834 = qcar(v_9834);
    v_9834 = qcdr(v_9834);
    goto v_9404;
v_9405:
    goto v_9401;
v_9402:
    goto v_9403;
v_9404:
    if (!consp(v_9835)) goto v_9399;
    v_9835 = qcar(v_9835);
    if (v_9835 == v_9834) goto v_9398;
    else goto v_9399;
v_9398:
    v_9834 = stack[-5];
    v_9834 = qcar(v_9834);
    v_9834 = qcdr(v_9834);
    if (!symbolp(v_9834)) v_9834 = nil;
    else { v_9834 = qfastgets(v_9834);
           if (v_9834 != nil) { v_9834 = elt(v_9834, 35); // nary
#ifdef RECORD_GET
             if (v_9834 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v_9834 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v_9834 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v_9834 == SPID_NOPROP) v_9834 = nil; else v_9834 = lisp_true; }}
#endif
    goto v_9397;
v_9399:
    v_9834 = nil;
    goto v_9397;
    v_9834 = nil;
v_9397:
    if (v_9834 == nil) goto v_9395;
    goto v_9423;
v_9419:
    v_9834 = stack[-8];
    v_9834 = qcdr(v_9834);
    v_9835 = qcar(v_9834);
    goto v_9420;
v_9421:
    v_9834 = stack[-8];
    v_9834 = qcar(v_9834);
    v_9834 = qcdr(v_9834);
    goto v_9422;
v_9423:
    goto v_9419;
v_9420:
    goto v_9421;
v_9422:
    v_9834 = cons(v_9835, v_9834);
    env = stack[-9];
    goto v_9393;
v_9395:
    goto v_9437;
v_9433:
    v_9834 = stack[-8];
    v_9834 = qcdr(v_9834);
    v_9835 = qcar(v_9834);
    goto v_9434;
v_9435:
    v_9834 = stack[-8];
    v_9834 = qcar(v_9834);
    goto v_9436;
v_9437:
    goto v_9433;
v_9434:
    goto v_9435;
v_9436:
    v_9834 = list2(v_9835, v_9834);
    env = stack[-9];
    goto v_9393;
    v_9834 = nil;
v_9393:
    goto v_9387;
v_9388:
    goto v_9384;
v_9385:
    goto v_9386;
v_9387:
    v_9834 = cons(stack[0], v_9834);
    env = stack[-9];
    stack[0] = v_9834;
    goto v_9344;
v_9344:
    v_9834 = stack[-5];
    v_9834 = qcdr(v_9834);
    stack[-5] = v_9834;
    goto v_9450;
v_9446:
    v_9835 = stack[0];
    goto v_9447;
v_9448:
    v_9834 = stack[-8];
    v_9834 = qcdr(v_9834);
    v_9834 = qcdr(v_9834);
    goto v_9449;
v_9450:
    goto v_9446;
v_9447:
    goto v_9448;
v_9449:
    v_9834 = cons(v_9835, v_9834);
    env = stack[-9];
    stack[-8] = v_9834;
    goto v_8486;
v_8489:
    goto v_9463;
v_9459:
    v_9835 = stack[-4];
    goto v_9460;
v_9461:
    v_9834 = elt(env, 34); // endstat
    goto v_9462;
v_9463:
    goto v_9459;
v_9460:
    goto v_9461;
v_9462:
    if (v_9835 == v_9834) goto v_9458;
    fn = elt(env, 53); // eolcheck
    v_9834 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    goto v_9456;
v_9458:
v_9456:
    goto v_9480;
v_9476:
    v_9835 = stack[-3];
    goto v_9477;
v_9478:
    v_9834 = elt(env, 35); // go
    goto v_9479;
v_9480:
    goto v_9476;
v_9477:
    goto v_9478;
v_9479:
    v_9834 = Lflagp(nil, v_9835, v_9834);
    env = stack[-9];
    if (v_9834 == nil) goto v_9474;
    v_9834 = lisp_true;
    goto v_9472;
v_9474:
    goto v_9494;
v_9490:
    v_9835 = stack[-7];
    goto v_9491;
v_9492:
    v_9834 = elt(env, 14); // proc
    goto v_9493;
v_9494:
    goto v_9490;
v_9491:
    goto v_9492;
v_9493:
    if (v_9835 == v_9834) goto v_9489;
    goto v_9506;
v_9502:
    v_9835 = stack[-4];
    goto v_9503;
v_9504:
    v_9834 = elt(env, 36); // endstatfn
    goto v_9505;
v_9506:
    goto v_9502;
v_9503:
    goto v_9504;
v_9505:
    v_9834 = Lflagp(nil, v_9835, v_9834);
    env = stack[-9];
    if (v_9834 == nil) goto v_9500;
    v_9834 = lisp_true;
    goto v_9498;
v_9500:
    v_9834 = qvalue(elt(env, 9)); // nxtsym!*
    fn = elt(env, 58); // delcp
    v_9834 = (*qfn1(fn))(fn, v_9834);
    env = stack[-9];
    if (v_9834 == nil) goto v_9514;
    else goto v_9515;
v_9514:
    goto v_9522;
v_9518:
    v_9835 = qvalue(elt(env, 9)); // nxtsym!*
    goto v_9519;
v_9520:
    v_9834 = elt(env, 37); // !,
    goto v_9521;
v_9522:
    goto v_9518;
v_9519:
    goto v_9520;
v_9521:
    v_9834 = (v_9835 == v_9834 ? lisp_true : nil);
    v_9834 = (v_9834 == nil ? lisp_true : nil);
    goto v_9513;
v_9515:
    v_9834 = nil;
    goto v_9513;
    v_9834 = nil;
v_9513:
    goto v_9498;
    v_9834 = nil;
v_9498:
    goto v_9487;
v_9489:
    v_9834 = nil;
    goto v_9487;
    v_9834 = nil;
v_9487:
    goto v_9472;
    v_9834 = nil;
v_9472:
    if (v_9834 == nil) goto v_9469;
    else goto v_9470;
v_9469:
    goto v_8473;
v_9470:
    goto v_9545;
v_9541:
    v_9835 = stack[-3];
    goto v_9542;
v_9543:
    v_9834 = elt(env, 38); // procedure
    goto v_9544;
v_9545:
    goto v_9541;
v_9542:
    goto v_9543;
v_9544:
    if (v_9835 == v_9834) goto v_9539;
    else goto v_9540;
v_9539:
    v_9834 = qvalue(elt(env, 5)); // !*reduce4
    goto v_9538;
v_9540:
    v_9834 = nil;
    goto v_9538;
    v_9834 = nil;
v_9538:
    if (v_9834 == nil) goto v_9536;
    v_9834 = stack[-6];
    if (v_9834 == nil) goto v_9555;
    v_9834 = stack[-6];
    v_9834 = qcdr(v_9834);
    if (v_9834 == nil) goto v_9561;
    else goto v_9559;
v_9561:
    v_9834 = qvalue(elt(env, 5)); // !*reduce4
    if (v_9834 == nil) goto v_9564;
    else goto v_9559;
v_9564:
    goto v_9560;
v_9559:
    goto v_9571;
v_9567:
    v_9835 = elt(env, 39); // "proc form"
    goto v_9568;
v_9569:
    v_9834 = nil;
    goto v_9570;
v_9571:
    goto v_9567;
v_9568:
    goto v_9569;
v_9570:
    fn = elt(env, 51); // symerr
    v_9834 = (*qfn2(fn))(fn, v_9835, v_9834);
    env = stack[-9];
    goto v_9558;
v_9560:
    v_9834 = stack[-6];
    v_9834 = qcar(v_9834);
    fn = elt(env, 59); // procstat1
    v_9834 = (*qfn1(fn))(fn, v_9834);
    env = stack[-9];
    v_9834 = ncons(v_9834);
    env = stack[-9];
    stack[-6] = v_9834;
    goto v_9558;
v_9558:
    goto v_9553;
v_9555:
    v_9834 = nil;
    fn = elt(env, 59); // procstat1
    v_9834 = (*qfn1(fn))(fn, v_9834);
    env = stack[-9];
    v_9834 = ncons(v_9834);
    env = stack[-9];
    stack[-6] = v_9834;
    goto v_9553;
v_9553:
    goto v_9534;
v_9536:
    goto v_9592;
v_9588:
    goto v_9598;
v_9594:
    v_9835 = stack[-4];
    goto v_9595;
v_9596:
    v_9834 = nil;
    goto v_9597;
v_9598:
    goto v_9594;
v_9595:
    goto v_9596;
v_9597:
    fn = elt(env, 48); // lispapply
    v_9835 = (*qfn2(fn))(fn, v_9835, v_9834);
    env = stack[-9];
    goto v_9589;
v_9590:
    v_9834 = stack[-6];
    goto v_9591;
v_9592:
    goto v_9588;
v_9589:
    goto v_9590;
v_9591:
    v_9834 = cons(v_9835, v_9834);
    env = stack[-9];
    stack[-6] = v_9834;
    goto v_9534;
v_9534:
    v_9834 = nil;
    stack[-4] = v_9834;
    goto v_8471;
v_8490:
    goto v_9611;
v_9607:
    v_9835 = qvalue(elt(env, 2)); // cursym!*
    goto v_9608;
v_9609:
    v_9834 = elt(env, 40); // !*semicol!*
    goto v_9610;
v_9611:
    goto v_9607;
v_9608:
    goto v_9609;
v_9610:
    if (v_9835 == v_9834) goto v_9606;
    fn = elt(env, 53); // eolcheck
    v_9834 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    goto v_9604;
v_9606:
v_9604:
    goto v_9628;
v_9624:
    v_9835 = stack[-3];
    goto v_9625;
v_9626:
    v_9834 = elt(env, 41); // !*colon!*
    goto v_9627;
v_9628:
    goto v_9624;
v_9625:
    goto v_9626;
v_9627:
    if (v_9835 == v_9834) goto v_9622;
    else goto v_9623;
v_9622:
    goto v_9639;
v_9635:
    v_9835 = stack[-7];
    goto v_9636;
v_9637:
    v_9834 = elt(env, 42); // for
    goto v_9638;
v_9639:
    goto v_9635;
v_9636:
    goto v_9637;
v_9638:
    if (v_9835 == v_9834) goto v_9634;
    v_9834 = qvalue(elt(env, 43)); // !*blockp
    if (v_9834 == nil) goto v_9644;
    else goto v_9645;
v_9644:
    v_9834 = lisp_true;
    goto v_9643;
v_9645:
    v_9834 = stack[-6];
    if (v_9834 == nil) goto v_9652;
    else goto v_9653;
v_9652:
    v_9834 = lisp_true;
    goto v_9651;
v_9653:
    v_9834 = stack[-6];
    v_9834 = qcar(v_9834);
    if (!consp(v_9834)) goto v_9661;
    v_9834 = lisp_true;
    goto v_9659;
v_9661:
    v_9834 = stack[-6];
    v_9834 = qcdr(v_9834);
    goto v_9659;
    v_9834 = nil;
v_9659:
    goto v_9651;
    v_9834 = nil;
v_9651:
    goto v_9643;
    v_9834 = nil;
v_9643:
    goto v_9632;
v_9634:
    v_9834 = nil;
    goto v_9632;
    v_9834 = nil;
v_9632:
    goto v_9621;
v_9623:
    v_9834 = nil;
    goto v_9621;
    v_9834 = nil;
v_9621:
    if (v_9834 == nil) goto v_9619;
    else goto v_9617;
v_9619:
    goto v_9685;
v_9681:
    v_9835 = stack[-3];
    goto v_9682;
v_9683:
    v_9834 = elt(env, 44); // nodel
    goto v_9684;
v_9685:
    goto v_9681;
v_9682:
    goto v_9683;
v_9684:
    v_9834 = Lflagp(nil, v_9835, v_9834);
    env = stack[-9];
    if (v_9834 == nil) goto v_9679;
    v_9834 = stack[-7];
    if (v_9834 == nil) goto v_9690;
    else goto v_9691;
v_9690:
    v_9834 = lisp_true;
    goto v_9689;
v_9691:
    goto v_9704;
v_9700:
    v_9835 = stack[-7];
    goto v_9701;
v_9702:
    v_9834 = elt(env, 21); // group
    goto v_9703;
v_9704:
    goto v_9700;
v_9701:
    goto v_9702;
v_9703:
    if (v_9835 == v_9834) goto v_9698;
    else goto v_9699;
v_9698:
    goto v_9711;
v_9707:
    v_9835 = stack[-3];
    goto v_9708;
v_9709:
    v_9834 = elt(env, 45); // (!*rsqbkt!* !*rcbkt!* !*rsqb!*)
    goto v_9710;
v_9711:
    goto v_9707;
v_9708:
    goto v_9709;
v_9710:
    v_9834 = Lmemq(nil, v_9835, v_9834);
    v_9834 = (v_9834 == nil ? lisp_true : nil);
    goto v_9697;
v_9699:
    v_9834 = nil;
    goto v_9697;
    v_9834 = nil;
v_9697:
    goto v_9689;
    v_9834 = nil;
v_9689:
    goto v_9677;
v_9679:
    v_9834 = nil;
    goto v_9677;
    v_9834 = nil;
v_9677:
    if (v_9834 == nil) goto v_9675;
    else goto v_9617;
v_9675:
    goto v_9618;
v_9617:
    goto v_9727;
v_9723:
    v_9835 = elt(env, 20); // "Improper delimiter"
    goto v_9724;
v_9725:
    v_9834 = nil;
    goto v_9726;
v_9727:
    goto v_9723;
v_9724:
    goto v_9725;
v_9726:
    fn = elt(env, 51); // symerr
    v_9834 = (*qfn2(fn))(fn, v_9835, v_9834);
    env = stack[-9];
    goto v_9616;
v_9618:
    v_9834 = stack[-7];
    if (symbolp(v_9834)) goto v_9732;
    else goto v_9731;
v_9732:
    goto v_9743;
v_9739:
    v_9835 = stack[-7];
    goto v_9740;
v_9741:
    v_9834 = elt(env, 17); // paren
    goto v_9742;
v_9743:
    goto v_9739;
v_9740:
    goto v_9741;
v_9742:
    if (v_9835 == v_9834) goto v_9737;
    else goto v_9738;
v_9737:
    v_9834 = lisp_true;
    goto v_9736;
v_9738:
    goto v_9754;
v_9750:
    v_9835 = stack[-7];
    goto v_9751;
v_9752:
    v_9834 = elt(env, 16); // struct
    goto v_9753;
v_9754:
    goto v_9750;
v_9751:
    goto v_9752;
v_9753:
    v_9834 = Lflagp(nil, v_9835, v_9834);
    env = stack[-9];
    goto v_9736;
    v_9834 = nil;
v_9736:
    if (v_9834 == nil) goto v_9731;
    goto v_9762;
v_9758:
    v_9835 = elt(env, 46); // "Too few right parentheses"
    goto v_9759;
v_9760:
    v_9834 = nil;
    goto v_9761;
v_9762:
    goto v_9758;
v_9759:
    goto v_9760;
v_9761:
    fn = elt(env, 51); // symerr
    v_9834 = (*qfn2(fn))(fn, v_9835, v_9834);
    env = stack[-9];
    goto v_9616;
v_9731:
v_9616:
v_8491:
    v_9834 = stack[-4];
    if (v_9834 == nil) goto v_9768;
    goto v_9775;
v_9771:
    v_9835 = elt(env, 20); // "Improper delimiter"
    goto v_9772;
v_9773:
    v_9834 = nil;
    goto v_9774;
v_9775:
    goto v_9771;
v_9772:
    goto v_9773;
v_9774:
    fn = elt(env, 51); // symerr
    v_9834 = (*qfn2(fn))(fn, v_9835, v_9834);
    env = stack[-9];
    goto v_9766;
v_9768:
    v_9834 = stack[-8];
    if (v_9834 == nil) goto v_9782;
    else goto v_9783;
v_9782:
    v_9834 = stack[-6];
    if (v_9834 == nil) goto v_9787;
    else goto v_9788;
v_9787:
    v_9834 = stack[-5];
    v_9834 = (v_9834 == nil ? lisp_true : nil);
    goto v_9786;
v_9788:
    v_9834 = nil;
    goto v_9786;
    v_9834 = nil;
v_9786:
    goto v_9781;
v_9783:
    v_9834 = nil;
    goto v_9781;
    v_9834 = nil;
v_9781:
    if (v_9834 == nil) goto v_9779;
    goto v_9803;
v_9799:
    v_9835 = nil;
    goto v_9800;
v_9801:
    v_9834 = stack[-1];
    goto v_9802;
v_9803:
    goto v_9799;
v_9800:
    goto v_9801;
v_9802:
    {
        fn = elt(env, 60); // xcomment
        return (*qfn2(fn))(fn, v_9835, v_9834);
    }
v_9779:
v_9766:
    v_9834 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_9834;
    goto v_8483;
v_8492:
    v_9834 = stack[-8];
    v_9834 = qcdr(v_9834);
    if (v_9834 == nil) goto v_9809;
    else goto v_9810;
v_9809:
    goto v_9818;
v_9814:
    v_9834 = stack[-8];
    v_9835 = qcar(v_9834);
    goto v_9815;
v_9816:
    v_9834 = stack[-1];
    goto v_9817;
v_9818:
    goto v_9814;
v_9815:
    goto v_9816;
v_9817:
    {
        fn = elt(env, 60); // xcomment
        return (*qfn2(fn))(fn, v_9835, v_9834);
    }
v_9810:
    v_9834 = elt(env, 47); // "Please send hearn@rand.org your program!!"
    v_9834 = Lprint(nil, v_9834);
    env = stack[-9];
    goto v_9808;
v_9808:
    goto v_9831;
v_9827:
    v_9835 = elt(env, 20); // "Improper delimiter"
    goto v_9828;
v_9829:
    v_9834 = nil;
    goto v_9830;
v_9831:
    goto v_9827;
v_9828:
    goto v_9829;
v_9830:
    fn = elt(env, 51); // symerr
    v_9834 = (*qfn2(fn))(fn, v_9835, v_9834);
    v_9834 = nil;
    return onevalue(v_9834);
}



setup_type const u16_setup[] =
{
    {"rread1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rread1},
    {"powers3",                 TOO_FEW_2,      CC_powers3,    WRONG_NO_2},
    {"rsubla",                  TOO_FEW_2,      CC_rsubla,     WRONG_NO_2},
    {"qqe_id-nyt-branchq",      CC_qqe_idKnytKbranchq,TOO_MANY_1,WRONG_NO_1},
    {"setunion",                TOO_FEW_2,      CC_setunion,   WRONG_NO_2},
    {"ibalp_redclause",         CC_ibalp_redclause,TOO_MANY_1, WRONG_NO_1},
    {"quotodd",                 TOO_FEW_2,      CC_quotodd,    WRONG_NO_2},
    {"bsubs",                   CC_bsubs,       TOO_MANY_1,    WRONG_NO_1},
    {"dipilcomb1",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dipilcomb1},
    {"greaterp:",               TOO_FEW_2,      CC_greaterpT,  WRONG_NO_2},
    {"mkinds",                  TOO_FEW_2,      CC_mkinds,     WRONG_NO_2},
    {"pappend",                 TOO_FEW_2,      CC_pappend,    WRONG_NO_2},
    {"flatsizec",               CC_flatsizec,   TOO_MANY_1,    WRONG_NO_1},
    {"modquotient:",            TOO_FEW_2,      CC_modquotientT,WRONG_NO_2},
    {"difference-mod-p",        TOO_FEW_2,      CC_differenceKmodKp,WRONG_NO_2},
    {"nb",                      CC_nb,          TOO_MANY_1,    WRONG_NO_1},
    {"simp0",                   CC_simp0,       TOO_MANY_1,    WRONG_NO_1},
    {"get_goto",                TOO_FEW_2,      CC_get_goto,   WRONG_NO_2},
    {"in_list1",                TOO_FEW_2,      CC_in_list1,   WRONG_NO_2},
    {"poly-minusp",             CC_polyKminusp, TOO_MANY_1,    WRONG_NO_1},
    {"exchk1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_exchk1},
    {"opmtch",                  CC_opmtch,      TOO_MANY_1,    WRONG_NO_1},
    {"c:extmult",               TOO_FEW_2,      CC_cTextmult,  WRONG_NO_2},
    {"assert_uninstall_all",    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_assert_uninstall_all},
    {"cali_bc_inv",             CC_cali_bc_inv, TOO_MANY_1,    WRONG_NO_1},
    {"subsetp",                 TOO_FEW_2,      CC_subsetp,    WRONG_NO_2},
    {"ra_transform",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ra_transform},
    {"lex_start_block_comment", CC_lex_start_block_comment,TOO_MANY_1,WRONG_NO_1},
    {"gcref_mkedges-tgf",       TOO_FEW_2,      CC_gcref_mkedgesKtgf,WRONG_NO_2},
    {"mri_pasf2mriat",          TOO_FEW_2,      CC_mri_pasf2mriat,WRONG_NO_2},
    {"ibalp_simpterm",          CC_ibalp_simpterm,TOO_MANY_1,  WRONG_NO_1},
    {"matrixrowrd",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_matrixrowrd},
    {"find_sub_df",             TOO_FEW_2,      CC_find_sub_df,WRONG_NO_2},
    {"redcodmat",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_redcodmat},
    {"termordp!",               TOO_FEW_2,      CC_termordpB,  WRONG_NO_2},
    {"nzeros",                  CC_nzeros,      TOO_MANY_1,    WRONG_NO_1},
    {"wi_new",                  CC_wi_new,      TOO_MANY_1,    WRONG_NO_1},
    {"lalr_associativity",      CC_lalr_associativity,TOO_MANY_1,WRONG_NO_1},
    {"xread1",                  CC_xread1,      TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u16", (two_args *)"146007 4468478 5957590", 0}
};

// end of generated code
