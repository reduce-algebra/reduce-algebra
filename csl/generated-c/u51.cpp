
// $destdir/u51.c        Machine generated C code

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



// Code for isimp2

static LispObject CC_isimp2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30416, v_30417, v_30418, v_30419, v_30420;
    LispObject fn;
    LispObject v_30236, v_30235, v_30234, v_30233, v_30232;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "isimp2");
    va_start(aa, nargs);
    v_30232 = va_arg(aa, LispObject);
    v_30233 = va_arg(aa, LispObject);
    v_30234 = va_arg(aa, LispObject);
    v_30235 = va_arg(aa, LispObject);
    v_30236 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_30236,v_30235,v_30234,v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_30232,v_30233,v_30234,v_30235,v_30236);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[0] = v_30236;
    stack[-1] = v_30235;
    stack[-2] = v_30234;
    stack[-3] = v_30233;
    stack[-4] = v_30232;
// end of prologue
    v_30416 = stack[-4];
    v_30416 = qcar(v_30416);
    v_30416 = qcar(v_30416);
    stack[-5] = v_30416;
    if (!consp(v_30416)) goto v_30245;
    else goto v_30246;
v_30245:
    goto v_30241;
v_30246:
    goto v_30260;
v_30256:
    v_30416 = stack[-5];
    v_30417 = qcar(v_30416);
    goto v_30257;
v_30258:
    v_30416 = elt(env, 1); // cons
    goto v_30259;
v_30260:
    goto v_30256;
v_30257:
    goto v_30258;
v_30259:
    if (v_30417 == v_30416) goto v_30254;
    else goto v_30255;
v_30254:
    goto v_30269;
v_30265:
    v_30416 = stack[-5];
    v_30417 = qcdr(v_30416);
    goto v_30266;
v_30267:
    v_30416 = stack[-3];
    goto v_30268;
v_30269:
    goto v_30265;
v_30266:
    goto v_30267;
v_30268:
    fn = elt(env, 4); // xnp
    v_30416 = (*qfn2(fn))(fn, v_30417, v_30416);
    env = stack[-6];
    goto v_30253;
v_30255:
    v_30416 = nil;
    goto v_30253;
    v_30416 = nil;
v_30253:
    if (v_30416 == nil) goto v_30251;
    goto v_30287;
v_30277:
    v_30420 = stack[-4];
    goto v_30278;
v_30279:
    v_30419 = stack[-3];
    goto v_30280;
v_30281:
    v_30418 = stack[-2];
    goto v_30282;
v_30283:
    v_30417 = stack[-1];
    goto v_30284;
v_30285:
    v_30416 = stack[0];
    goto v_30286;
v_30287:
    goto v_30277;
v_30278:
    goto v_30279;
v_30280:
    goto v_30281;
v_30282:
    goto v_30283;
v_30284:
    goto v_30285;
v_30286:
    {
        fn = elt(env, 5); // dotsum
        return (*qfnn(fn))(fn, 5, v_30420, v_30419, v_30418, v_30417, v_30416);
    }
v_30251:
    goto v_30299;
v_30295:
    v_30416 = stack[-5];
    v_30417 = qcar(v_30416);
    goto v_30296;
v_30297:
    v_30416 = elt(env, 2); // g
    goto v_30298;
v_30299:
    goto v_30295;
v_30296:
    goto v_30297;
v_30298:
    if (v_30417 == v_30416) goto v_30293;
    else goto v_30294;
v_30293:
    goto v_30242;
v_30294:
    goto v_30309;
v_30305:
    v_30416 = stack[-5];
    v_30417 = qcar(v_30416);
    goto v_30306;
v_30307:
    v_30416 = elt(env, 3); // eps
    goto v_30308;
v_30309:
    goto v_30305;
v_30306:
    goto v_30307;
v_30308:
    if (v_30417 == v_30416) goto v_30303;
    else goto v_30304;
v_30303:
    goto v_30324;
v_30314:
    v_30420 = stack[-4];
    goto v_30315;
v_30316:
    v_30419 = stack[-3];
    goto v_30317;
v_30318:
    v_30418 = stack[-2];
    goto v_30319;
v_30320:
    v_30417 = stack[-1];
    goto v_30321;
v_30322:
    v_30416 = stack[0];
    goto v_30323;
v_30324:
    goto v_30314;
v_30315:
    goto v_30316;
v_30317:
    goto v_30318;
v_30319:
    goto v_30320;
v_30321:
    goto v_30322;
v_30323:
    {
        fn = elt(env, 6); // esum
        return (*qfnn(fn))(fn, 5, v_30420, v_30419, v_30418, v_30417, v_30416);
    }
v_30304:
v_30241:
    goto v_30335;
v_30331:
    goto v_30342;
v_30338:
    v_30416 = stack[-4];
    v_30417 = qcar(v_30416);
    goto v_30339;
v_30340:
    v_30416 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30341;
v_30342:
    goto v_30338;
v_30339:
    goto v_30340;
v_30341:
    v_30416 = cons(v_30417, v_30416);
    env = stack[-6];
    stack[-5] = ncons(v_30416);
    env = stack[-6];
    goto v_30332;
v_30333:
    goto v_30357;
v_30347:
    v_30416 = stack[-4];
    v_30420 = qcdr(v_30416);
    goto v_30348;
v_30349:
    v_30419 = stack[-3];
    goto v_30350;
v_30351:
    v_30418 = stack[-2];
    goto v_30352;
v_30353:
    v_30417 = stack[-1];
    goto v_30354;
v_30355:
    v_30416 = stack[0];
    goto v_30356;
v_30357:
    goto v_30347;
v_30348:
    goto v_30349;
v_30350:
    goto v_30351;
v_30352:
    goto v_30353;
v_30354:
    goto v_30355;
v_30356:
    fn = elt(env, 7); // isimp1
    v_30416 = (*qfnn(fn))(fn, 5, v_30420, v_30419, v_30418, v_30417, v_30416);
    env = stack[-6];
    goto v_30334;
v_30335:
    goto v_30331;
v_30332:
    goto v_30333;
v_30334:
    {
        LispObject v_30427 = stack[-5];
        fn = elt(env, 8); // multf
        return (*qfn2(fn))(fn, v_30427, v_30416);
    }
v_30242:
    goto v_30371;
v_30365:
    goto v_30377;
v_30373:
    v_30416 = stack[-5];
    v_30416 = qcdr(v_30416);
    v_30417 = qcdr(v_30416);
    goto v_30374;
v_30375:
    v_30416 = stack[-4];
    v_30416 = qcar(v_30416);
    v_30416 = qcdr(v_30416);
    goto v_30376;
v_30377:
    goto v_30373;
v_30374:
    goto v_30375;
v_30376:
    fn = elt(env, 9); // appn
    v_30418 = (*qfn2(fn))(fn, v_30417, v_30416);
    env = stack[-6];
    goto v_30366;
v_30367:
    v_30417 = stack[0];
    goto v_30368;
v_30369:
    v_30416 = stack[-5];
    v_30416 = qcdr(v_30416);
    v_30416 = qcar(v_30416);
    goto v_30370;
v_30371:
    goto v_30365;
v_30366:
    goto v_30367;
v_30368:
    goto v_30369;
v_30370:
    fn = elt(env, 10); // gadd
    v_30416 = (*qfnn(fn))(fn, 3, v_30418, v_30417, v_30416);
    env = stack[-6];
    stack[-5] = v_30416;
    goto v_30399;
v_30389:
    goto v_30405;
v_30401:
    v_30416 = stack[-5];
    v_30416 = qcar(v_30416);
    fn = elt(env, 11); // nb
    v_30417 = (*qfn1(fn))(fn, v_30416);
    env = stack[-6];
    goto v_30402;
v_30403:
    v_30416 = stack[-4];
    v_30416 = qcdr(v_30416);
    goto v_30404;
v_30405:
    goto v_30401;
v_30402:
    goto v_30403;
v_30404:
    fn = elt(env, 12); // multd!*
    v_30420 = (*qfn2(fn))(fn, v_30417, v_30416);
    env = stack[-6];
    goto v_30390;
v_30391:
    v_30419 = stack[-3];
    goto v_30392;
v_30393:
    v_30418 = stack[-2];
    goto v_30394;
v_30395:
    v_30417 = stack[-1];
    goto v_30396;
v_30397:
    v_30416 = stack[-5];
    v_30416 = qcdr(v_30416);
    goto v_30398;
v_30399:
    goto v_30389;
v_30390:
    goto v_30391;
v_30392:
    goto v_30393;
v_30394:
    goto v_30395;
v_30396:
    goto v_30397;
v_30398:
    {
        fn = elt(env, 7); // isimp1
        return (*qfnn(fn))(fn, 5, v_30420, v_30419, v_30418, v_30417, v_30416);
    }
    return onevalue(v_30416);
}



// Code for ofsf_sminsert1

static LispObject CC_ofsf_sminsert1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30421, v_30422, v_30423;
    LispObject fn;
    LispObject v_30236, v_30235, v_30234, v_30233, v_30232;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "ofsf_sminsert1");
    va_start(aa, nargs);
    v_30232 = va_arg(aa, LispObject);
    v_30233 = va_arg(aa, LispObject);
    v_30234 = va_arg(aa, LispObject);
    v_30235 = va_arg(aa, LispObject);
    v_30236 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_30236,v_30235,v_30234,v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_30232,v_30233,v_30234,v_30235,v_30236);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[0] = v_30236;
    stack[-1] = v_30235;
    stack[-2] = v_30234;
    stack[-3] = v_30233;
    stack[-4] = v_30232;
// end of prologue
    goto v_30247;
v_30243:
    stack[-5] = stack[-3];
    goto v_30244;
v_30245:
    v_30421 = stack[-1];
    fn = elt(env, 3); // negsq
    v_30421 = (*qfn1(fn))(fn, v_30421);
    env = stack[-6];
    goto v_30246;
v_30247:
    goto v_30243;
v_30244:
    goto v_30245;
v_30246:
    fn = elt(env, 4); // addsq
    v_30421 = (*qfn2(fn))(fn, stack[-5], v_30421);
    env = stack[-6];
    v_30421 = qcar(v_30421);
    v_30422 = v_30421;
    v_30421 = v_30422;
    if (v_30421 == nil) goto v_30254;
    else goto v_30255;
v_30254:
    goto v_30262;
v_30258:
    v_30422 = stack[-4];
    goto v_30259;
v_30260:
    v_30421 = stack[-2];
    goto v_30261;
v_30262:
    goto v_30258;
v_30259:
    goto v_30260;
v_30261:
    fn = elt(env, 5); // ofsf_smeqtable
    v_30421 = (*qfn2(fn))(fn, v_30422, v_30421);
    env = stack[-6];
    v_30423 = v_30421;
    goto v_30273;
v_30269:
    v_30422 = v_30423;
    goto v_30270;
v_30271:
    v_30421 = elt(env, 1); // false
    goto v_30272;
v_30273:
    goto v_30269;
v_30270:
    goto v_30271;
v_30272:
    if (v_30422 == v_30421) goto v_30267;
    else goto v_30268;
v_30267:
    v_30421 = elt(env, 1); // false
    goto v_30241;
v_30268:
    goto v_30285;
v_30281:
    v_30422 = stack[-4];
    goto v_30282;
v_30283:
    v_30421 = v_30423;
    goto v_30284;
v_30285:
    goto v_30281;
v_30282:
    goto v_30283;
v_30284:
    if (v_30422 == v_30421) goto v_30279;
    else goto v_30280;
v_30279:
    v_30421 = elt(env, 2); // true
    goto v_30241;
v_30280:
    goto v_30296;
v_30290:
    v_30422 = stack[0];
    goto v_30291;
v_30292:
    goto v_30293;
v_30294:
    v_30421 = stack[-3];
    goto v_30295;
v_30296:
    goto v_30290;
v_30291:
    goto v_30292;
v_30293:
    goto v_30294;
v_30295:
    return list2star(v_30422, v_30423, v_30421);
v_30255:
    v_30421 = v_30422;
    fn = elt(env, 6); // minusf
    v_30421 = (*qfn1(fn))(fn, v_30421);
    env = stack[-6];
    if (v_30421 == nil) goto v_30303;
    goto v_30311;
v_30307:
    v_30422 = stack[-4];
    goto v_30308;
v_30309:
    v_30421 = stack[-2];
    goto v_30310;
v_30311:
    goto v_30307;
v_30308:
    goto v_30309;
v_30310:
    fn = elt(env, 7); // ofsf_smordtable
    v_30421 = (*qfn2(fn))(fn, v_30422, v_30421);
    env = stack[-6];
    v_30423 = v_30421;
    v_30421 = v_30423;
    if (!consp(v_30421)) goto v_30316;
    else goto v_30317;
v_30316:
    v_30421 = v_30423;
    goto v_30241;
v_30317:
    goto v_30333;
v_30329:
    v_30422 = v_30423;
    goto v_30330;
v_30331:
    v_30421 = stack[-4];
    goto v_30332;
v_30333:
    goto v_30329;
v_30330:
    goto v_30331;
v_30332:
    if (!consp(v_30422)) goto v_30327;
    v_30422 = qcar(v_30422);
    if (v_30422 == v_30421) goto v_30326;
    else goto v_30327;
v_30326:
    v_30421 = v_30423;
    v_30421 = qcdr(v_30421);
    goto v_30325;
v_30327:
    v_30421 = nil;
    goto v_30325;
    v_30421 = nil;
v_30325:
    if (v_30421 == nil) goto v_30323;
    v_30421 = elt(env, 2); // true
    goto v_30241;
v_30323:
    goto v_30349;
v_30343:
    v_30422 = stack[0];
    goto v_30344;
v_30345:
    v_30421 = v_30423;
    v_30421 = qcar(v_30421);
    goto v_30346;
v_30347:
    v_30423 = qcdr(v_30423);
    if (v_30423 == nil) goto v_30356;
    v_30423 = stack[-3];
    goto v_30354;
v_30356:
    v_30423 = stack[-1];
    goto v_30354;
    v_30423 = nil;
v_30354:
    goto v_30348;
v_30349:
    goto v_30343;
v_30344:
    goto v_30345;
v_30346:
    goto v_30347;
v_30348:
    return list2star(v_30422, v_30421, v_30423);
v_30303:
    goto v_30368;
v_30364:
    v_30422 = stack[-2];
    goto v_30365;
v_30366:
    v_30421 = stack[-4];
    goto v_30367;
v_30368:
    goto v_30364;
v_30365:
    goto v_30366;
v_30367:
    fn = elt(env, 7); // ofsf_smordtable
    v_30421 = (*qfn2(fn))(fn, v_30422, v_30421);
    env = stack[-6];
    v_30423 = v_30421;
    v_30421 = v_30423;
    if (!consp(v_30421)) goto v_30373;
    else goto v_30374;
v_30373:
    v_30421 = v_30423;
    goto v_30241;
v_30374:
    goto v_30390;
v_30386:
    v_30422 = v_30423;
    goto v_30387;
v_30388:
    v_30421 = stack[-4];
    goto v_30389;
v_30390:
    goto v_30386;
v_30387:
    goto v_30388;
v_30389:
    if (!consp(v_30422)) goto v_30384;
    v_30422 = qcar(v_30422);
    if (v_30422 == v_30421) goto v_30383;
    else goto v_30384;
v_30383:
    v_30421 = v_30423;
    v_30421 = qcdr(v_30421);
    v_30421 = (v_30421 == nil ? lisp_true : nil);
    goto v_30382;
v_30384:
    v_30421 = nil;
    goto v_30382;
    v_30421 = nil;
v_30382:
    if (v_30421 == nil) goto v_30380;
    v_30421 = elt(env, 2); // true
    goto v_30241;
v_30380:
    goto v_30407;
v_30401:
    v_30422 = stack[0];
    goto v_30402;
v_30403:
    v_30421 = v_30423;
    v_30421 = qcar(v_30421);
    goto v_30404;
v_30405:
    v_30423 = qcdr(v_30423);
    if (v_30423 == nil) goto v_30414;
    v_30423 = stack[-1];
    goto v_30412;
v_30414:
    v_30423 = stack[-3];
    goto v_30412;
    v_30423 = nil;
v_30412:
    goto v_30406;
v_30407:
    goto v_30401;
v_30402:
    goto v_30403;
v_30404:
    goto v_30405;
v_30406:
    return list2star(v_30422, v_30421, v_30423);
v_30241:
    return onevalue(v_30421);
}



// Code for get!*order

static LispObject CC_getHorder(LispObject env,
                         LispObject v_30232)
{
    env = qenv(env);
    LispObject v_30239;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30232);
    }
// copy arguments values to proper place
    v_30239 = v_30232;
// end of prologue
    fn = elt(env, 1); // get!*elements
    v_30239 = (*qfn1(fn))(fn, v_30239);
        return Llength(nil, v_30239);
    return onevalue(v_30239);
}



// Code for qqe_length!-graph!-marked

static LispObject CC_qqe_lengthKgraphKmarked(LispObject env,
                         LispObject v_30232)
{
    env = qenv(env);
    LispObject v_30242, v_30243;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30242 = v_30232;
// end of prologue
    goto v_30239;
v_30235:
    goto v_30236;
v_30237:
    v_30243 = elt(env, 1); // blockmark
    goto v_30238;
v_30239:
    goto v_30235;
v_30236:
    goto v_30237;
v_30238:
    return get(v_30242, v_30243);
}



// Code for pasf_negateat

static LispObject CC_pasf_negateat(LispObject env,
                         LispObject v_30232)
{
    env = qenv(env);
    LispObject v_30444, v_30445, v_30446;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30232);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_30232;
// end of prologue
    goto v_30246;
v_30242:
    v_30445 = stack[0];
    goto v_30243;
v_30244:
    v_30444 = elt(env, 1); // true
    goto v_30245;
v_30246:
    goto v_30242;
v_30243:
    goto v_30244;
v_30245:
    if (v_30445 == v_30444) goto v_30240;
    else goto v_30241;
v_30240:
    v_30444 = lisp_true;
    goto v_30239;
v_30241:
    goto v_30256;
v_30252:
    v_30445 = stack[0];
    goto v_30253;
v_30254:
    v_30444 = elt(env, 2); // false
    goto v_30255;
v_30256:
    goto v_30252;
v_30253:
    goto v_30254;
v_30255:
    v_30444 = (v_30445 == v_30444 ? lisp_true : nil);
    goto v_30239;
    v_30444 = nil;
v_30239:
    if (v_30444 == nil) goto v_30237;
    goto v_30268;
v_30264:
    v_30445 = stack[0];
    goto v_30265;
v_30266:
    v_30444 = elt(env, 2); // false
    goto v_30267;
v_30268:
    goto v_30264;
v_30265:
    goto v_30266;
v_30267:
    if (v_30445 == v_30444) goto v_30262;
    else goto v_30263;
v_30262:
    v_30444 = elt(env, 1); // true
    goto v_30261;
v_30263:
    v_30444 = elt(env, 2); // false
    goto v_30261;
    v_30444 = nil;
v_30261:
    goto v_30235;
v_30237:
    goto v_30281;
v_30277:
    goto v_30294;
v_30290:
    v_30445 = stack[0];
    goto v_30291;
v_30292:
    v_30444 = elt(env, 1); // true
    goto v_30293;
v_30294:
    goto v_30290;
v_30291:
    goto v_30292;
v_30293:
    if (v_30445 == v_30444) goto v_30288;
    else goto v_30289;
v_30288:
    v_30444 = lisp_true;
    goto v_30287;
v_30289:
    goto v_30304;
v_30300:
    v_30445 = stack[0];
    goto v_30301;
v_30302:
    v_30444 = elt(env, 2); // false
    goto v_30303;
v_30304:
    goto v_30300;
v_30301:
    goto v_30302;
v_30303:
    v_30444 = (v_30445 == v_30444 ? lisp_true : nil);
    goto v_30287;
    v_30444 = nil;
v_30287:
    if (v_30444 == nil) goto v_30285;
    v_30444 = stack[0];
    v_30445 = v_30444;
    goto v_30283;
v_30285:
    v_30444 = stack[0];
    v_30444 = qcar(v_30444);
    v_30444 = Lconsp(nil, v_30444);
    env = stack[-1];
    if (v_30444 == nil) goto v_30310;
    v_30444 = stack[0];
    v_30444 = qcar(v_30444);
    v_30444 = qcar(v_30444);
    v_30445 = v_30444;
    goto v_30283;
v_30310:
    v_30444 = stack[0];
    v_30444 = qcar(v_30444);
    v_30445 = v_30444;
    goto v_30283;
    v_30445 = nil;
v_30283:
    goto v_30278;
v_30279:
    v_30444 = elt(env, 3); // (cong ncong)
    goto v_30280;
v_30281:
    goto v_30277;
v_30278:
    goto v_30279;
v_30280:
    v_30444 = Lmemq(nil, v_30445, v_30444);
    if (v_30444 == nil) goto v_30276;
    goto v_30330;
v_30324:
    goto v_30336;
v_30332:
    goto v_30350;
v_30346:
    v_30445 = stack[0];
    goto v_30347;
v_30348:
    v_30444 = elt(env, 1); // true
    goto v_30349;
v_30350:
    goto v_30346;
v_30347:
    goto v_30348;
v_30349:
    if (v_30445 == v_30444) goto v_30344;
    else goto v_30345;
v_30344:
    v_30444 = lisp_true;
    goto v_30343;
v_30345:
    goto v_30360;
v_30356:
    v_30445 = stack[0];
    goto v_30357;
v_30358:
    v_30444 = elt(env, 2); // false
    goto v_30359;
v_30360:
    goto v_30356;
v_30357:
    goto v_30358;
v_30359:
    v_30444 = (v_30445 == v_30444 ? lisp_true : nil);
    goto v_30343;
    v_30444 = nil;
v_30343:
    if (v_30444 == nil) goto v_30341;
    v_30444 = stack[0];
    goto v_30339;
v_30341:
    v_30444 = stack[0];
    v_30444 = qcar(v_30444);
    v_30444 = Lconsp(nil, v_30444);
    env = stack[-1];
    if (v_30444 == nil) goto v_30366;
    v_30444 = stack[0];
    v_30444 = qcar(v_30444);
    v_30444 = qcar(v_30444);
    goto v_30339;
v_30366:
    v_30444 = stack[0];
    v_30444 = qcar(v_30444);
    goto v_30339;
    v_30444 = nil;
v_30339:
    fn = elt(env, 4); // pasf_lnegrel
    v_30445 = (*qfn1(fn))(fn, v_30444);
    env = stack[-1];
    goto v_30333;
v_30334:
    v_30444 = stack[0];
    v_30444 = qcar(v_30444);
    v_30444 = qcdr(v_30444);
    goto v_30335;
v_30336:
    goto v_30332;
v_30333:
    goto v_30334;
v_30335:
    fn = elt(env, 5); // pasf_mkop
    v_30446 = (*qfn2(fn))(fn, v_30445, v_30444);
    goto v_30325;
v_30326:
    v_30444 = stack[0];
    v_30444 = qcdr(v_30444);
    v_30445 = qcar(v_30444);
    goto v_30327;
v_30328:
    v_30444 = stack[0];
    v_30444 = qcdr(v_30444);
    v_30444 = qcdr(v_30444);
    v_30444 = qcar(v_30444);
    goto v_30329;
v_30330:
    goto v_30324;
v_30325:
    goto v_30326;
v_30327:
    goto v_30328;
v_30329:
    return list3(v_30446, v_30445, v_30444);
v_30276:
    goto v_30396;
v_30390:
    goto v_30410;
v_30406:
    v_30445 = stack[0];
    goto v_30407;
v_30408:
    v_30444 = elt(env, 1); // true
    goto v_30409;
v_30410:
    goto v_30406;
v_30407:
    goto v_30408;
v_30409:
    if (v_30445 == v_30444) goto v_30404;
    else goto v_30405;
v_30404:
    v_30444 = lisp_true;
    goto v_30403;
v_30405:
    goto v_30420;
v_30416:
    v_30445 = stack[0];
    goto v_30417;
v_30418:
    v_30444 = elt(env, 2); // false
    goto v_30419;
v_30420:
    goto v_30416;
v_30417:
    goto v_30418;
v_30419:
    v_30444 = (v_30445 == v_30444 ? lisp_true : nil);
    goto v_30403;
    v_30444 = nil;
v_30403:
    if (v_30444 == nil) goto v_30401;
    v_30444 = stack[0];
    goto v_30399;
v_30401:
    v_30444 = stack[0];
    v_30444 = qcar(v_30444);
    v_30444 = Lconsp(nil, v_30444);
    env = stack[-1];
    if (v_30444 == nil) goto v_30426;
    v_30444 = stack[0];
    v_30444 = qcar(v_30444);
    v_30444 = qcar(v_30444);
    goto v_30399;
v_30426:
    v_30444 = stack[0];
    v_30444 = qcar(v_30444);
    goto v_30399;
    v_30444 = nil;
v_30399:
    fn = elt(env, 4); // pasf_lnegrel
    v_30446 = (*qfn1(fn))(fn, v_30444);
    goto v_30391;
v_30392:
    v_30444 = stack[0];
    v_30444 = qcdr(v_30444);
    v_30445 = qcar(v_30444);
    goto v_30393;
v_30394:
    v_30444 = stack[0];
    v_30444 = qcdr(v_30444);
    v_30444 = qcdr(v_30444);
    v_30444 = qcar(v_30444);
    goto v_30395;
v_30396:
    goto v_30390;
v_30391:
    goto v_30392;
v_30393:
    goto v_30394;
v_30395:
    return list3(v_30446, v_30445, v_30444);
    v_30444 = nil;
v_30235:
    return onevalue(v_30444);
}



// Code for ofsf_boundchk

static LispObject CC_ofsf_boundchk(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30397, v_30398, v_30399;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30232,v_30233);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_30233;
    stack[-2] = v_30232;
// end of prologue
    v_30397 = stack[-1];
    v_30397 = ncons(v_30397);
    env = stack[-4];
    fn = elt(env, 7); // setkorder
    v_30397 = (*qfn1(fn))(fn, v_30397);
    env = stack[-4];
    stack[0] = v_30397;
    v_30397 = stack[-2];
    v_30397 = qcdr(v_30397);
    v_30397 = qcar(v_30397);
    fn = elt(env, 8); // reorder
    v_30397 = (*qfn1(fn))(fn, v_30397);
    env = stack[-4];
    stack[-3] = v_30397;
    v_30397 = stack[0];
    fn = elt(env, 7); // setkorder
    v_30397 = (*qfn1(fn))(fn, v_30397);
    env = stack[-4];
    v_30397 = stack[-3];
    if (!consp(v_30397)) goto v_30260;
    else goto v_30261;
v_30260:
    v_30397 = lisp_true;
    goto v_30259;
v_30261:
    v_30397 = stack[-3];
    v_30397 = qcar(v_30397);
    v_30397 = (consp(v_30397) ? nil : lisp_true);
    goto v_30259;
    v_30397 = nil;
v_30259:
    if (v_30397 == nil) goto v_30257;
    v_30397 = lisp_true;
    goto v_30255;
v_30257:
    goto v_30277;
v_30273:
    v_30397 = stack[-3];
    v_30397 = qcar(v_30397);
    v_30397 = qcar(v_30397);
    v_30398 = qcar(v_30397);
    goto v_30274;
v_30275:
    v_30397 = stack[-1];
    goto v_30276;
v_30277:
    goto v_30273;
v_30274:
    goto v_30275;
v_30276:
    v_30397 = Lneq(nil, v_30398, v_30397);
    env = stack[-4];
    goto v_30255;
    v_30397 = nil;
v_30255:
    if (v_30397 == nil) goto v_30253;
    v_30397 = nil;
    goto v_30240;
v_30253:
    goto v_30292;
v_30288:
    v_30397 = stack[-3];
    v_30397 = qcar(v_30397);
    v_30397 = qcar(v_30397);
    v_30398 = qcdr(v_30397);
    goto v_30289;
v_30290:
    v_30397 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30291;
v_30292:
    goto v_30288;
v_30289:
    goto v_30290;
v_30291:
    if (v_30398 == v_30397) goto v_30287;
    goto v_30306;
v_30300:
    v_30399 = elt(env, 1); // "ofsf_boundchk:"
    goto v_30301;
v_30302:
    v_30398 = stack[-1];
    goto v_30303;
v_30304:
    v_30397 = elt(env, 2); // "not linear"
    goto v_30305;
v_30306:
    goto v_30300;
v_30301:
    goto v_30302;
v_30303:
    goto v_30304;
v_30305:
    v_30397 = list3(v_30399, v_30398, v_30397);
    env = stack[-4];
    fn = elt(env, 9); // rederr
    v_30397 = (*qfn1(fn))(fn, v_30397);
    env = stack[-4];
    goto v_30285;
v_30287:
v_30285:
    goto v_30315;
v_30311:
    goto v_30321;
v_30317:
    v_30397 = stack[-3];
    v_30397 = qcdr(v_30397);
    fn = elt(env, 8); // reorder
    v_30397 = (*qfn1(fn))(fn, v_30397);
    env = stack[-4];
    fn = elt(env, 10); // negf
    v_30398 = (*qfn1(fn))(fn, v_30397);
    env = stack[-4];
    goto v_30318;
v_30319:
    v_30397 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30320;
v_30321:
    goto v_30317;
v_30318:
    goto v_30319;
v_30320:
    stack[0] = cons(v_30398, v_30397);
    env = stack[-4];
    goto v_30312;
v_30313:
    goto v_30332;
v_30328:
    v_30397 = stack[-3];
    v_30397 = qcar(v_30397);
    v_30397 = qcdr(v_30397);
    fn = elt(env, 8); // reorder
    v_30398 = (*qfn1(fn))(fn, v_30397);
    env = stack[-4];
    goto v_30329;
v_30330:
    v_30397 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30331;
v_30332:
    goto v_30328;
v_30329:
    goto v_30330;
v_30331:
    v_30397 = cons(v_30398, v_30397);
    env = stack[-4];
    goto v_30314;
v_30315:
    goto v_30311;
v_30312:
    goto v_30313;
v_30314:
    fn = elt(env, 11); // quotsq
    v_30397 = (*qfn2(fn))(fn, stack[0], v_30397);
    env = stack[-4];
    stack[0] = v_30397;
    v_30397 = stack[-2];
    v_30397 = qcar(v_30397);
    v_30399 = v_30397;
    goto v_30348;
v_30344:
    v_30398 = v_30399;
    goto v_30345;
v_30346:
    v_30397 = elt(env, 3); // equal
    goto v_30347;
v_30348:
    goto v_30344;
v_30345:
    goto v_30346;
v_30347:
    if (v_30398 == v_30397) goto v_30342;
    else goto v_30343;
v_30342:
    goto v_30356;
v_30352:
    v_30398 = elt(env, 3); // equal
    goto v_30353;
v_30354:
    v_30397 = stack[0];
    goto v_30355;
v_30356:
    goto v_30352;
v_30353:
    goto v_30354;
v_30355:
    return cons(v_30398, v_30397);
v_30343:
    goto v_30368;
v_30364:
    goto v_30373;
v_30369:
    v_30398 = v_30399;
    goto v_30370;
v_30371:
    v_30397 = elt(env, 4); // geq
    goto v_30372;
v_30373:
    goto v_30369;
v_30370:
    goto v_30371;
v_30372:
    stack[-1] = (v_30398 == v_30397 ? lisp_true : nil);
    goto v_30365;
v_30366:
    v_30397 = stack[-3];
    v_30397 = qcar(v_30397);
    v_30397 = qcdr(v_30397);
    fn = elt(env, 12); // minusf
    v_30397 = (*qfn1(fn))(fn, v_30397);
    env = stack[-4];
    goto v_30367;
v_30368:
    goto v_30364;
v_30365:
    goto v_30366;
v_30367:
    fn = elt(env, 13); // ofsf_xor
    v_30397 = (*qfn2(fn))(fn, stack[-1], v_30397);
    env = stack[-4];
    if (v_30397 == nil) goto v_30362;
    goto v_30386;
v_30382:
    v_30398 = elt(env, 5); // lb
    goto v_30383;
v_30384:
    v_30397 = stack[0];
    goto v_30385;
v_30386:
    goto v_30382;
v_30383:
    goto v_30384;
v_30385:
    return cons(v_30398, v_30397);
v_30362:
    goto v_30394;
v_30390:
    v_30398 = elt(env, 6); // ub
    goto v_30391;
v_30392:
    v_30397 = stack[0];
    goto v_30393;
v_30394:
    goto v_30390;
v_30391:
    goto v_30392;
v_30393:
    return cons(v_30398, v_30397);
v_30240:
    return onevalue(v_30397);
}



// Code for ldf!-deg

static LispObject CC_ldfKdeg(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30292, v_30293;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30232,v_30233);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_30233;
    v_30292 = v_30232;
// end of prologue
    stack[-4] = v_30292;
    v_30292 = stack[-4];
    if (v_30292 == nil) goto v_30245;
    else goto v_30246;
v_30245:
    v_30292 = nil;
    goto v_30240;
v_30246:
    v_30292 = stack[-4];
    v_30292 = qcar(v_30292);
    goto v_30258;
v_30254:
    v_30293 = qcdr(v_30292);
    goto v_30255;
v_30256:
    v_30292 = stack[-3];
    goto v_30257;
v_30258:
    goto v_30254;
v_30255:
    goto v_30256;
v_30257:
    fn = elt(env, 1); // degreef
    v_30292 = (*qfn2(fn))(fn, v_30293, v_30292);
    env = stack[-5];
    v_30292 = ncons(v_30292);
    env = stack[-5];
    stack[-1] = v_30292;
    stack[-2] = v_30292;
v_30241:
    v_30292 = stack[-4];
    v_30292 = qcdr(v_30292);
    stack[-4] = v_30292;
    v_30292 = stack[-4];
    if (v_30292 == nil) goto v_30266;
    else goto v_30267;
v_30266:
    v_30292 = stack[-2];
    goto v_30240;
v_30267:
    goto v_30275;
v_30271:
    stack[0] = stack[-1];
    goto v_30272;
v_30273:
    v_30292 = stack[-4];
    v_30292 = qcar(v_30292);
    goto v_30286;
v_30282:
    v_30293 = qcdr(v_30292);
    goto v_30283;
v_30284:
    v_30292 = stack[-3];
    goto v_30285;
v_30286:
    goto v_30282;
v_30283:
    goto v_30284;
v_30285:
    fn = elt(env, 1); // degreef
    v_30292 = (*qfn2(fn))(fn, v_30293, v_30292);
    env = stack[-5];
    v_30292 = ncons(v_30292);
    env = stack[-5];
    goto v_30274;
v_30275:
    goto v_30271;
v_30272:
    goto v_30273;
v_30274:
    v_30292 = Lrplacd(nil, stack[0], v_30292);
    env = stack[-5];
    v_30292 = stack[-1];
    v_30292 = qcdr(v_30292);
    stack[-1] = v_30292;
    goto v_30241;
v_30240:
    {
        fn = elt(env, 2); // maxl
        return (*qfn1(fn))(fn, v_30292);
    }
}



// Code for sprow_dim

static LispObject CC_sprow_dim(LispObject env,
                         LispObject v_30232)
{
    env = qenv(env);
    LispObject v_30259;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30232);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_30232;
// end of prologue
    v_30259 = qvalue(elt(env, 1)); // !*fast_la
    if (v_30259 == nil) goto v_30243;
    else goto v_30244;
v_30243:
    v_30259 = stack[0];
    fn = elt(env, 3); // matrixp
    v_30259 = (*qfn1(fn))(fn, v_30259);
    env = stack[-1];
    v_30259 = (v_30259 == nil ? lisp_true : nil);
    goto v_30242;
v_30244:
    v_30259 = nil;
    goto v_30242;
    v_30259 = nil;
v_30242:
    if (v_30259 == nil) goto v_30240;
    v_30259 = elt(env, 2); // "Error in sprow_dim: input should be a matrix."
    fn = elt(env, 4); // rederr
    v_30259 = (*qfn1(fn))(fn, v_30259);
    env = stack[-1];
    goto v_30238;
v_30240:
v_30238:
    v_30259 = stack[0];
    fn = elt(env, 5); // spmatlength
    v_30259 = (*qfn1(fn))(fn, v_30259);
    v_30259 = qcdr(v_30259);
    v_30259 = qcar(v_30259);
    return onevalue(v_30259);
}



// Code for groebmakepair

static LispObject CC_groebmakepair(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30329, v_30330, v_30331;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30232,v_30233);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_30233;
    stack[-3] = v_30232;
// end of prologue
    goto v_30245;
v_30241:
    v_30329 = stack[-3];
    v_30329 = qcdr(v_30329);
    v_30330 = qcar(v_30329);
    goto v_30242;
v_30243:
    v_30329 = stack[-2];
    v_30329 = qcdr(v_30329);
    v_30329 = qcar(v_30329);
    goto v_30244;
v_30245:
    goto v_30241;
v_30242:
    goto v_30243;
v_30244:
    fn = elt(env, 2); // vevlcm
    v_30329 = (*qfn2(fn))(fn, v_30330, v_30329);
    env = stack[-5];
    stack[-4] = v_30329;
    v_30329 = qvalue(elt(env, 1)); // !*gsugar
    if (v_30329 == nil) goto v_30255;
    goto v_30261;
v_30257:
    v_30329 = stack[-3];
    fn = elt(env, 3); // gsugar
    stack[0] = (*qfn1(fn))(fn, v_30329);
    env = stack[-5];
    goto v_30258;
v_30259:
    goto v_30270;
v_30266:
    v_30330 = stack[-4];
    goto v_30267;
v_30268:
    v_30329 = stack[-3];
    v_30329 = qcdr(v_30329);
    v_30329 = qcar(v_30329);
    goto v_30269;
v_30270:
    goto v_30266;
v_30267:
    goto v_30268;
v_30269:
    fn = elt(env, 4); // vevdif
    v_30329 = (*qfn2(fn))(fn, v_30330, v_30329);
    env = stack[-5];
    fn = elt(env, 5); // vevtdeg
    v_30329 = (*qfn1(fn))(fn, v_30329);
    env = stack[-5];
    goto v_30260;
v_30261:
    goto v_30257;
v_30258:
    goto v_30259;
v_30260:
    v_30329 = (LispObject)(intptr_t)((intptr_t)stack[0] + (intptr_t)v_30329 - TAG_FIXNUM);
    stack[-1] = v_30329;
    goto v_30280;
v_30276:
    v_30329 = stack[-2];
    fn = elt(env, 3); // gsugar
    stack[0] = (*qfn1(fn))(fn, v_30329);
    env = stack[-5];
    goto v_30277;
v_30278:
    goto v_30289;
v_30285:
    v_30330 = stack[-4];
    goto v_30286;
v_30287:
    v_30329 = stack[-2];
    v_30329 = qcdr(v_30329);
    v_30329 = qcar(v_30329);
    goto v_30288;
v_30289:
    goto v_30285;
v_30286:
    goto v_30287;
v_30288:
    fn = elt(env, 4); // vevdif
    v_30329 = (*qfn2(fn))(fn, v_30330, v_30329);
    env = stack[-5];
    fn = elt(env, 5); // vevtdeg
    v_30329 = (*qfn1(fn))(fn, v_30329);
    env = stack[-5];
    goto v_30279;
v_30280:
    goto v_30276;
v_30277:
    goto v_30278;
v_30279:
    v_30329 = (LispObject)(intptr_t)((intptr_t)stack[0] + (intptr_t)v_30329 - TAG_FIXNUM);
    goto v_30304;
v_30296:
    stack[0] = stack[-4];
    goto v_30297;
v_30298:
    goto v_30299;
v_30300:
    goto v_30301;
v_30302:
    goto v_30313;
v_30309:
    v_30330 = stack[-1];
    goto v_30310;
v_30311:
    goto v_30312;
v_30313:
    goto v_30309;
v_30310:
    goto v_30311;
v_30312:
    fn = elt(env, 6); // max
    v_30329 = (*qfn2(fn))(fn, v_30330, v_30329);
    goto v_30303;
v_30304:
    goto v_30296;
v_30297:
    goto v_30298;
v_30299:
    goto v_30300;
v_30301:
    goto v_30302;
v_30303:
    {
        LispObject v_30337 = stack[0];
        LispObject v_30338 = stack[-3];
        LispObject v_30339 = stack[-2];
        return list4(v_30337, v_30338, v_30339, v_30329);
    }
v_30255:
    goto v_30325;
v_30319:
    v_30331 = stack[-4];
    goto v_30320;
v_30321:
    v_30330 = stack[-3];
    goto v_30322;
v_30323:
    v_30329 = stack[-2];
    goto v_30324;
v_30325:
    goto v_30319;
v_30320:
    goto v_30321;
v_30322:
    goto v_30323;
v_30324:
    return list3(v_30331, v_30330, v_30329);
    v_30329 = nil;
    return onevalue(v_30329);
}



// Code for groebreduceonestepint

static LispObject CC_groebreduceonestepint(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30399, v_30400, v_30401;
    LispObject fn;
    LispObject v_30236, v_30235, v_30234, v_30233, v_30232;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "groebreduceonestepint");
    va_start(aa, nargs);
    v_30232 = va_arg(aa, LispObject);
    v_30233 = va_arg(aa, LispObject);
    v_30234 = va_arg(aa, LispObject);
    v_30235 = va_arg(aa, LispObject);
    v_30236 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_30236,v_30235,v_30234,v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_30232,v_30233,v_30234,v_30235,v_30236);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-1] = v_30236;
    stack[-4] = v_30235;
    stack[-3] = v_30234;
    stack[-6] = v_30233;
    stack[-2] = v_30232;
// end of prologue
    v_30399 = stack[-1];
    fn = elt(env, 6); // vdpred
    v_30399 = (*qfn1(fn))(fn, v_30399);
    env = stack[-8];
    stack[0] = v_30399;
    v_30400 = v_30399;
    v_30399 = v_30400;
    if (v_30399 == nil) goto v_30255;
    else goto v_30256;
v_30255:
    v_30399 = lisp_true;
    goto v_30254;
v_30256:
    v_30399 = v_30400;
    v_30399 = qcdr(v_30399);
    v_30399 = qcdr(v_30399);
    v_30399 = qcdr(v_30399);
    v_30399 = qcar(v_30399);
    v_30399 = (v_30399 == nil ? lisp_true : nil);
    goto v_30254;
    v_30399 = nil;
v_30254:
    if (v_30399 == nil) goto v_30249;
    v_30399 = stack[-2];
    fn = elt(env, 6); // vdpred
    v_30399 = (*qfn1(fn))(fn, v_30399);
    env = stack[-8];
    stack[-2] = v_30399;
    v_30399 = stack[-6];
    qvalue(elt(env, 1)) = v_30399; // secondvalue!*
    v_30399 = stack[-2];
    goto v_30245;
v_30249:
    goto v_30276;
v_30272:
    v_30400 = stack[-4];
    goto v_30273;
v_30274:
    v_30399 = stack[-1];
    v_30399 = qcdr(v_30399);
    v_30399 = qcar(v_30399);
    goto v_30275;
v_30276:
    goto v_30272;
v_30273:
    goto v_30274;
v_30275:
    fn = elt(env, 7); // vevdif
    v_30399 = (*qfn2(fn))(fn, v_30400, v_30399);
    env = stack[-8];
    stack[-7] = v_30399;
    v_30399 = stack[-1];
    v_30399 = qcdr(v_30399);
    v_30399 = qcdr(v_30399);
    v_30399 = qcar(v_30399);
    stack[-5] = v_30399;
    v_30399 = qvalue(elt(env, 2)); // !*groebdivide
    if (v_30399 == nil) goto v_30287;
    else goto v_30288;
v_30287:
    v_30399 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 8); // vbcfi
    v_30399 = (*qfn1(fn))(fn, v_30399);
    env = stack[-8];
    goto v_30286;
v_30288:
    goto v_30299;
v_30295:
    v_30400 = stack[-3];
    goto v_30296;
v_30297:
    v_30399 = stack[-5];
    goto v_30298;
v_30299:
    goto v_30295;
v_30296:
    goto v_30297;
v_30298:
    fn = elt(env, 9); // vbcgcd
    v_30399 = (*qfn2(fn))(fn, v_30400, v_30399);
    env = stack[-8];
    goto v_30286;
    v_30399 = nil;
v_30286:
    stack[-4] = v_30399;
    goto v_30307;
v_30303:
    v_30400 = stack[-5];
    goto v_30304;
v_30305:
    v_30399 = stack[-4];
    goto v_30306;
v_30307:
    goto v_30303;
v_30304:
    goto v_30305;
v_30306:
    fn = elt(env, 10); // vbcquot
    v_30399 = (*qfn2(fn))(fn, v_30400, v_30399);
    env = stack[-8];
    stack[-5] = v_30399;
    goto v_30315;
v_30311:
    v_30400 = stack[-3];
    goto v_30312;
v_30313:
    v_30399 = stack[-4];
    goto v_30314;
v_30315:
    goto v_30311;
v_30312:
    goto v_30313;
v_30314:
    fn = elt(env, 10); // vbcquot
    v_30399 = (*qfn2(fn))(fn, v_30400, v_30399);
    env = stack[-8];
    stack[-4] = v_30399;
    v_30399 = stack[-6];
    if (v_30399 == nil) goto v_30321;
    v_30399 = stack[-6];
    if (v_30399 == nil) goto v_30327;
    else goto v_30328;
v_30327:
    v_30399 = lisp_true;
    goto v_30326;
v_30328:
    v_30399 = stack[-6];
    v_30399 = qcdr(v_30399);
    v_30399 = qcdr(v_30399);
    v_30399 = qcdr(v_30399);
    v_30399 = qcar(v_30399);
    v_30399 = (v_30399 == nil ? lisp_true : nil);
    goto v_30326;
    v_30399 = nil;
v_30326:
    if (v_30399 == nil) goto v_30324;
    else goto v_30321;
v_30324:
    goto v_30344;
v_30340:
    v_30400 = stack[-6];
    goto v_30341;
v_30342:
    v_30399 = stack[-5];
    goto v_30343;
v_30344:
    goto v_30340;
v_30341:
    goto v_30342;
v_30343:
    fn = elt(env, 11); // vdpvbcprod
    v_30399 = (*qfn2(fn))(fn, v_30400, v_30399);
    env = stack[-8];
    stack[-6] = v_30399;
    goto v_30319;
v_30321:
v_30319:
    v_30399 = qvalue(elt(env, 3)); // !*groebprot
    if (v_30399 == nil) goto v_30350;
    goto v_30361;
v_30353:
    stack[-3] = stack[-5];
    goto v_30354;
v_30355:
    v_30399 = stack[-4];
    fn = elt(env, 12); // vbcneg
    v_30401 = (*qfn1(fn))(fn, v_30399);
    env = stack[-8];
    goto v_30356;
v_30357:
    v_30400 = stack[-7];
    goto v_30358;
v_30359:
    v_30399 = stack[-1];
    goto v_30360;
v_30361:
    goto v_30353;
v_30354:
    goto v_30355;
v_30356:
    goto v_30357;
v_30358:
    goto v_30359;
v_30360:
    fn = elt(env, 13); // groebreductionprotocol
    v_30399 = (*qfnn(fn))(fn, 4, stack[-3], v_30401, v_30400, v_30399);
    env = stack[-8];
    goto v_30348;
v_30350:
v_30348:
    goto v_30380;
v_30368:
    v_30399 = stack[-2];
    fn = elt(env, 6); // vdpred
    stack[-3] = (*qfn1(fn))(fn, v_30399);
    env = stack[-8];
    goto v_30369;
v_30370:
    stack[-2] = stack[-5];
    goto v_30371;
v_30372:
    goto v_30389;
v_30385:
    v_30400 = qvalue(elt(env, 4)); // vdpvars!*
    goto v_30386;
v_30387:
    v_30399 = nil;
    goto v_30388;
v_30389:
    goto v_30385;
v_30386:
    goto v_30387;
v_30388:
    fn = elt(env, 14); // vevmaptozero1
    stack[-1] = (*qfn2(fn))(fn, v_30400, v_30399);
    env = stack[-8];
    goto v_30373;
v_30374:
    goto v_30375;
v_30376:
    v_30399 = stack[-4];
    fn = elt(env, 12); // vbcneg
    v_30400 = (*qfn1(fn))(fn, v_30399);
    env = stack[-8];
    goto v_30377;
v_30378:
    v_30399 = stack[-7];
    goto v_30379;
v_30380:
    goto v_30368;
v_30369:
    goto v_30370;
v_30371:
    goto v_30372;
v_30373:
    goto v_30374;
v_30375:
    goto v_30376;
v_30377:
    goto v_30378;
v_30379:
    fn = elt(env, 15); // vdpilcomb1
    v_30399 = (*qfnn(fn))(fn, 6, stack[-3], stack[-2], stack[-1], stack[0], v_30400, v_30399);
    env = stack[-8];
    stack[-2] = v_30399;
    v_30399 = stack[-6];
    qvalue(elt(env, 1)) = v_30399; // secondvalue!*
    v_30399 = stack[-5];
    qvalue(elt(env, 5)) = v_30399; // thirdvalue!*
    v_30399 = stack[-2];
v_30245:
    return onevalue(v_30399);
}



// Code for mkunarywedge

static LispObject CC_mkunarywedge(LispObject env,
                         LispObject v_30232)
{
    env = qenv(env);
    LispObject v_30265, v_30266, v_30267;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30232);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30232;
// end of prologue
    stack[-1] = nil;
v_30237:
    v_30265 = stack[0];
    if (v_30265 == nil) goto v_30240;
    else goto v_30241;
v_30240:
    v_30265 = stack[-1];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_30265);
    }
v_30241:
    goto v_30254;
v_30248:
    v_30265 = stack[0];
    v_30265 = qcar(v_30265);
    v_30265 = qcar(v_30265);
    v_30267 = ncons(v_30265);
    env = stack[-2];
    goto v_30249;
v_30250:
    v_30265 = stack[0];
    v_30265 = qcar(v_30265);
    v_30266 = qcdr(v_30265);
    goto v_30251;
v_30252:
    v_30265 = stack[-1];
    goto v_30253;
v_30254:
    goto v_30248;
v_30249:
    goto v_30250;
v_30251:
    goto v_30252;
v_30253:
    v_30265 = acons(v_30267, v_30266, v_30265);
    env = stack[-2];
    stack[-1] = v_30265;
    v_30265 = stack[0];
    v_30265 = qcdr(v_30265);
    stack[0] = v_30265;
    goto v_30237;
    v_30265 = nil;
    return onevalue(v_30265);
}



// Code for chksymmetries!&sub1

static LispObject CC_chksymmetriesGsub1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30273, v_30274, v_30275;
    LispObject fn;
    LispObject v_30235, v_30234, v_30233, v_30232;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "chksymmetries&sub1");
    va_start(aa, nargs);
    v_30232 = va_arg(aa, LispObject);
    v_30233 = va_arg(aa, LispObject);
    v_30234 = va_arg(aa, LispObject);
    v_30235 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_30235,v_30234,v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_30232,v_30233,v_30234,v_30235);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30235;
    v_30273 = v_30234;
    v_30274 = v_30233;
    v_30275 = v_30232;
// end of prologue
    goto v_30244;
v_30238:
    goto v_30239;
v_30240:
    goto v_30241;
v_30242:
    goto v_30243;
v_30244:
    goto v_30238;
v_30239:
    goto v_30240;
v_30241:
    goto v_30242;
v_30243:
    v_30273 = Lsubst(nil, 3, v_30275, v_30274, v_30273);
    env = stack[-2];
    stack[-1] = v_30273;
    v_30273 = stack[0];
    if (v_30273 == nil) goto v_30255;
    else goto v_30256;
v_30255:
    v_30273 = lisp_true;
    goto v_30254;
v_30256:
    goto v_30266;
v_30262:
    v_30274 = stack[-1];
    goto v_30263;
v_30264:
    v_30273 = stack[0];
    goto v_30265;
v_30266:
    goto v_30262;
v_30263:
    goto v_30264;
v_30265:
    fn = elt(env, 1); // indxsymp
    v_30273 = (*qfn2(fn))(fn, v_30274, v_30273);
    goto v_30254;
    v_30273 = nil;
v_30254:
    if (v_30273 == nil) goto v_30252;
    v_30273 = stack[-1];
    goto v_30250;
v_30252:
    v_30273 = nil;
    goto v_30250;
    v_30273 = nil;
v_30250:
    return onevalue(v_30273);
}



// Code for df!-chain!-rule

static LispObject CC_dfKchainKrule(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30301, v_30302, v_30303;
    LispObject fn;
    LispObject v_30234, v_30233, v_30232;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "df-chain-rule");
    va_start(aa, nargs);
    v_30232 = va_arg(aa, LispObject);
    v_30233 = va_arg(aa, LispObject);
    v_30234 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30234,v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30232,v_30233,v_30234);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[0] = v_30234;
    stack[-3] = v_30233;
    stack[-4] = v_30232;
// end of prologue
    goto v_30244;
v_30240:
    v_30302 = nil;
    goto v_30241;
v_30242:
    v_30301 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30243;
v_30244:
    goto v_30240;
v_30241:
    goto v_30242;
v_30243:
    v_30301 = cons(v_30302, v_30301);
    env = stack[-6];
    v_30302 = v_30301;
    v_30301 = stack[0];
    stack[-5] = v_30301;
v_30250:
    v_30301 = stack[-5];
    if (v_30301 == nil) goto v_30254;
    else goto v_30255;
v_30254:
    goto v_30249;
v_30255:
    v_30301 = stack[-5];
    v_30301 = qcar(v_30301);
    stack[-2] = v_30301;
    goto v_30266;
v_30262:
    stack[-1] = v_30302;
    goto v_30263;
v_30264:
    goto v_30273;
v_30269:
    goto v_30282;
v_30276:
    v_30303 = elt(env, 1); // df
    goto v_30277;
v_30278:
    v_30302 = stack[-4];
    goto v_30279;
v_30280:
    v_30301 = stack[-2];
    goto v_30281;
v_30282:
    goto v_30276;
v_30277:
    goto v_30278;
v_30279:
    goto v_30280;
v_30281:
    v_30301 = list3(v_30303, v_30302, v_30301);
    env = stack[-6];
    fn = elt(env, 2); // simp
    stack[0] = (*qfn1(fn))(fn, v_30301);
    env = stack[-6];
    goto v_30270;
v_30271:
    goto v_30294;
v_30288:
    v_30303 = elt(env, 1); // df
    goto v_30289;
v_30290:
    v_30302 = stack[-2];
    goto v_30291;
v_30292:
    v_30301 = stack[-3];
    goto v_30293;
v_30294:
    goto v_30288;
v_30289:
    goto v_30290;
v_30291:
    goto v_30292;
v_30293:
    v_30301 = list3(v_30303, v_30302, v_30301);
    env = stack[-6];
    fn = elt(env, 2); // simp
    v_30301 = (*qfn1(fn))(fn, v_30301);
    env = stack[-6];
    goto v_30272;
v_30273:
    goto v_30269;
v_30270:
    goto v_30271;
v_30272:
    fn = elt(env, 3); // multsq
    v_30301 = (*qfn2(fn))(fn, stack[0], v_30301);
    env = stack[-6];
    goto v_30265;
v_30266:
    goto v_30262;
v_30263:
    goto v_30264;
v_30265:
    fn = elt(env, 4); // addsq
    v_30301 = (*qfn2(fn))(fn, stack[-1], v_30301);
    env = stack[-6];
    v_30302 = v_30301;
    v_30301 = stack[-5];
    v_30301 = qcdr(v_30301);
    stack[-5] = v_30301;
    goto v_30250;
v_30249:
    v_30301 = v_30302;
    return onevalue(v_30301);
}



// Code for pst_d1

static LispObject CC_pst_d1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30424;
    LispObject fn;
    LispObject v_30234, v_30233, v_30232;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pst_d1");
    va_start(aa, nargs);
    v_30232 = va_arg(aa, LispObject);
    v_30233 = va_arg(aa, LispObject);
    v_30234 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30234,v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30232,v_30233,v_30234);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(14);
// copy arguments values to proper place
    stack[-10] = v_30234;
    stack[-11] = v_30233;
    v_30424 = v_30232;
// end of prologue
    goto v_30246;
v_30242:
    stack[0] = stack[-10];
    goto v_30243;
v_30244:
    v_30424 = sub1(v_30424);
    env = stack[-13];
    goto v_30245;
v_30246:
    goto v_30242;
v_30243:
    goto v_30244;
v_30245:
    v_30424 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_30424-TAG_FIXNUM)/(16/CELL)));
    stack[-12] = v_30424;
    v_30424 = stack[-12];
    if (v_30424 == nil) goto v_30253;
    else goto v_30254;
v_30253:
    v_30424 = nil;
    goto v_30240;
v_30254:
    v_30424 = stack[-12];
    v_30424 = qcar(v_30424);
    stack[-6] = v_30424;
    goto v_30272;
v_30268:
    stack[0] = stack[-10];
    goto v_30269;
v_30270:
    v_30424 = stack[-11];
    v_30424 = sub1(v_30424);
    env = stack[-13];
    goto v_30271;
v_30272:
    goto v_30268;
v_30269:
    goto v_30270;
v_30271:
    v_30424 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_30424-TAG_FIXNUM)/(16/CELL)));
    stack[-5] = v_30424;
    v_30424 = stack[-5];
    if (v_30424 == nil) goto v_30279;
    else goto v_30280;
v_30279:
    v_30424 = nil;
    goto v_30266;
v_30280:
    v_30424 = stack[-5];
    v_30424 = qcar(v_30424);
    stack[-1] = v_30424;
    goto v_30293;
v_30289:
    v_30424 = stack[-6];
    fn = elt(env, 1); // sc_kern
    stack[0] = (*qfn1(fn))(fn, v_30424);
    env = stack[-13];
    goto v_30290;
v_30291:
    v_30424 = stack[-1];
    fn = elt(env, 1); // sc_kern
    v_30424 = (*qfn1(fn))(fn, v_30424);
    env = stack[-13];
    goto v_30292;
v_30293:
    goto v_30289;
v_30290:
    goto v_30291;
v_30292:
    fn = elt(env, 2); // pa_coinc_split
    v_30424 = (*qfn2(fn))(fn, stack[0], v_30424);
    env = stack[-13];
    v_30424 = qcar(v_30424);
    fn = elt(env, 3); // ordn
    v_30424 = (*qfn1(fn))(fn, v_30424);
    env = stack[-13];
    v_30424 = ncons(v_30424);
    env = stack[-13];
    stack[-3] = v_30424;
    stack[-4] = v_30424;
v_30267:
    v_30424 = stack[-5];
    v_30424 = qcdr(v_30424);
    stack[-5] = v_30424;
    v_30424 = stack[-5];
    if (v_30424 == nil) goto v_30303;
    else goto v_30304;
v_30303:
    v_30424 = stack[-4];
    goto v_30266;
v_30304:
    goto v_30312;
v_30308:
    stack[-2] = stack[-3];
    goto v_30309;
v_30310:
    v_30424 = stack[-5];
    v_30424 = qcar(v_30424);
    stack[-1] = v_30424;
    goto v_30324;
v_30320:
    v_30424 = stack[-6];
    fn = elt(env, 1); // sc_kern
    stack[0] = (*qfn1(fn))(fn, v_30424);
    env = stack[-13];
    goto v_30321;
v_30322:
    v_30424 = stack[-1];
    fn = elt(env, 1); // sc_kern
    v_30424 = (*qfn1(fn))(fn, v_30424);
    env = stack[-13];
    goto v_30323;
v_30324:
    goto v_30320;
v_30321:
    goto v_30322;
v_30323:
    fn = elt(env, 2); // pa_coinc_split
    v_30424 = (*qfn2(fn))(fn, stack[0], v_30424);
    env = stack[-13];
    v_30424 = qcar(v_30424);
    fn = elt(env, 3); // ordn
    v_30424 = (*qfn1(fn))(fn, v_30424);
    env = stack[-13];
    v_30424 = ncons(v_30424);
    env = stack[-13];
    goto v_30311;
v_30312:
    goto v_30308;
v_30309:
    goto v_30310;
v_30311:
    v_30424 = Lrplacd(nil, stack[-2], v_30424);
    env = stack[-13];
    v_30424 = stack[-3];
    v_30424 = qcdr(v_30424);
    stack[-3] = v_30424;
    goto v_30267;
v_30266:
    fn = elt(env, 3); // ordn
    v_30424 = (*qfn1(fn))(fn, v_30424);
    env = stack[-13];
    v_30424 = ncons(v_30424);
    env = stack[-13];
    stack[-8] = v_30424;
    stack[-9] = v_30424;
v_30241:
    v_30424 = stack[-12];
    v_30424 = qcdr(v_30424);
    stack[-12] = v_30424;
    v_30424 = stack[-12];
    if (v_30424 == nil) goto v_30336;
    else goto v_30337;
v_30336:
    v_30424 = stack[-9];
    goto v_30240;
v_30337:
    goto v_30345;
v_30341:
    stack[-7] = stack[-8];
    goto v_30342;
v_30343:
    v_30424 = stack[-12];
    v_30424 = qcar(v_30424);
    stack[-6] = v_30424;
    goto v_30362;
v_30358:
    stack[0] = stack[-10];
    goto v_30359;
v_30360:
    v_30424 = stack[-11];
    v_30424 = sub1(v_30424);
    env = stack[-13];
    goto v_30361;
v_30362:
    goto v_30358;
v_30359:
    goto v_30360;
v_30361:
    v_30424 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_30424-TAG_FIXNUM)/(16/CELL)));
    stack[-5] = v_30424;
    v_30424 = stack[-5];
    if (v_30424 == nil) goto v_30369;
    else goto v_30370;
v_30369:
    v_30424 = nil;
    goto v_30356;
v_30370:
    v_30424 = stack[-5];
    v_30424 = qcar(v_30424);
    stack[-1] = v_30424;
    goto v_30383;
v_30379:
    v_30424 = stack[-6];
    fn = elt(env, 1); // sc_kern
    stack[0] = (*qfn1(fn))(fn, v_30424);
    env = stack[-13];
    goto v_30380;
v_30381:
    v_30424 = stack[-1];
    fn = elt(env, 1); // sc_kern
    v_30424 = (*qfn1(fn))(fn, v_30424);
    env = stack[-13];
    goto v_30382;
v_30383:
    goto v_30379;
v_30380:
    goto v_30381;
v_30382:
    fn = elt(env, 2); // pa_coinc_split
    v_30424 = (*qfn2(fn))(fn, stack[0], v_30424);
    env = stack[-13];
    v_30424 = qcar(v_30424);
    fn = elt(env, 3); // ordn
    v_30424 = (*qfn1(fn))(fn, v_30424);
    env = stack[-13];
    v_30424 = ncons(v_30424);
    env = stack[-13];
    stack[-3] = v_30424;
    stack[-4] = v_30424;
v_30357:
    v_30424 = stack[-5];
    v_30424 = qcdr(v_30424);
    stack[-5] = v_30424;
    v_30424 = stack[-5];
    if (v_30424 == nil) goto v_30393;
    else goto v_30394;
v_30393:
    v_30424 = stack[-4];
    goto v_30356;
v_30394:
    goto v_30402;
v_30398:
    stack[-2] = stack[-3];
    goto v_30399;
v_30400:
    v_30424 = stack[-5];
    v_30424 = qcar(v_30424);
    stack[-1] = v_30424;
    goto v_30414;
v_30410:
    v_30424 = stack[-6];
    fn = elt(env, 1); // sc_kern
    stack[0] = (*qfn1(fn))(fn, v_30424);
    env = stack[-13];
    goto v_30411;
v_30412:
    v_30424 = stack[-1];
    fn = elt(env, 1); // sc_kern
    v_30424 = (*qfn1(fn))(fn, v_30424);
    env = stack[-13];
    goto v_30413;
v_30414:
    goto v_30410;
v_30411:
    goto v_30412;
v_30413:
    fn = elt(env, 2); // pa_coinc_split
    v_30424 = (*qfn2(fn))(fn, stack[0], v_30424);
    env = stack[-13];
    v_30424 = qcar(v_30424);
    fn = elt(env, 3); // ordn
    v_30424 = (*qfn1(fn))(fn, v_30424);
    env = stack[-13];
    v_30424 = ncons(v_30424);
    env = stack[-13];
    goto v_30401;
v_30402:
    goto v_30398;
v_30399:
    goto v_30400;
v_30401:
    v_30424 = Lrplacd(nil, stack[-2], v_30424);
    env = stack[-13];
    v_30424 = stack[-3];
    v_30424 = qcdr(v_30424);
    stack[-3] = v_30424;
    goto v_30357;
v_30356:
    fn = elt(env, 3); // ordn
    v_30424 = (*qfn1(fn))(fn, v_30424);
    env = stack[-13];
    v_30424 = ncons(v_30424);
    env = stack[-13];
    goto v_30344;
v_30345:
    goto v_30341;
v_30342:
    goto v_30343;
v_30344:
    v_30424 = Lrplacd(nil, stack[-7], v_30424);
    env = stack[-13];
    v_30424 = stack[-8];
    v_30424 = qcdr(v_30424);
    stack[-8] = v_30424;
    goto v_30241;
v_30240:
    return onevalue(v_30424);
}



// Code for general!-difference!-mod!-p

static LispObject CC_generalKdifferenceKmodKp(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30244, v_30245;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30232,v_30233);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_30244 = v_30233;
    v_30245 = v_30232;
// end of prologue
    goto v_30240;
v_30236:
    stack[0] = v_30245;
    goto v_30237;
v_30238:
    fn = elt(env, 1); // general!-minus!-mod!-p
    v_30244 = (*qfn1(fn))(fn, v_30244);
    env = stack[-1];
    goto v_30239;
v_30240:
    goto v_30236;
v_30237:
    goto v_30238;
v_30239:
    {
        LispObject v_30247 = stack[0];
        fn = elt(env, 2); // general!-plus!-mod!-p
        return (*qfn2(fn))(fn, v_30247, v_30244);
    }
}



// Code for smemberl

static LispObject CC_smemberl(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30279, v_30280;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30232,v_30233);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30233;
    stack[-1] = v_30232;
// end of prologue
    stack[-2] = nil;
v_30238:
    v_30279 = stack[-1];
    if (v_30279 == nil) goto v_30242;
    v_30279 = stack[0];
    if (v_30279 == nil) goto v_30242;
    goto v_30256;
v_30252:
    v_30279 = stack[-1];
    v_30280 = qcar(v_30279);
    goto v_30253;
v_30254:
    v_30279 = stack[0];
    goto v_30255;
v_30256:
    goto v_30252;
v_30253:
    goto v_30254;
v_30255:
    fn = elt(env, 1); // smember
    v_30279 = (*qfn2(fn))(fn, v_30280, v_30279);
    env = stack[-3];
    if (v_30279 == nil) goto v_30250;
    goto v_30265;
v_30261:
    v_30279 = stack[-1];
    v_30280 = qcar(v_30279);
    goto v_30262;
v_30263:
    v_30279 = stack[-2];
    goto v_30264;
v_30265:
    goto v_30261;
v_30262:
    goto v_30263;
v_30264:
    v_30279 = cons(v_30280, v_30279);
    env = stack[-3];
    stack[-2] = v_30279;
    v_30279 = stack[-1];
    v_30279 = qcdr(v_30279);
    stack[-1] = v_30279;
    goto v_30238;
v_30250:
    v_30279 = stack[-1];
    v_30279 = qcdr(v_30279);
    stack[-1] = v_30279;
    goto v_30238;
    goto v_30240;
v_30242:
    v_30279 = stack[-2];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_30279);
    }
v_30240:
    v_30279 = nil;
    return onevalue(v_30279);
}



// Code for updkorder

static LispObject CC_updkorder(LispObject env,
                         LispObject v_30232)
{
    env = qenv(env);
    LispObject v_30270, v_30271, v_30272;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30232);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_30271 = v_30232;
// end of prologue
    v_30270 = qvalue(elt(env, 1)); // kord!*
    stack[-1] = v_30270;
    goto v_30244;
v_30240:
    stack[0] = v_30271;
    goto v_30241;
v_30242:
    goto v_30251;
v_30247:
    goto v_30248;
v_30249:
    v_30270 = stack[-1];
    goto v_30250;
v_30251:
    goto v_30247;
v_30248:
    goto v_30249;
v_30250:
    v_30270 = Ldelete(nil, v_30271, v_30270);
    env = stack[-2];
    goto v_30243;
v_30244:
    goto v_30240;
v_30241:
    goto v_30242;
v_30243:
    v_30270 = cons(stack[0], v_30270);
    env = stack[-2];
    v_30272 = v_30270;
    goto v_30262;
v_30258:
    v_30271 = stack[-1];
    goto v_30259;
v_30260:
    v_30270 = v_30272;
    goto v_30261;
v_30262:
    goto v_30258;
v_30259:
    goto v_30260;
v_30261:
    if (equal(v_30271, v_30270)) goto v_30256;
    else goto v_30257;
v_30256:
    v_30270 = stack[-1];
    goto v_30237;
v_30257:
    v_30270 = v_30272;
    qvalue(elt(env, 1)) = v_30270; // kord!*
    v_30270 = nil;
    v_30270 = ncons(v_30270);
    env = stack[-2];
    qvalue(elt(env, 2)) = v_30270; // alglist!*
    v_30270 = stack[-1];
v_30237:
    return onevalue(v_30270);
}



// Code for qroundup

static LispObject CC_qroundup(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30275, v_30276;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30232,v_30233);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30233;
    stack[-1] = v_30232;
// end of prologue
    goto v_30244;
v_30240:
    v_30276 = stack[-1];
    goto v_30241;
v_30242:
    v_30275 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30243;
v_30244:
    goto v_30240;
v_30241:
    goto v_30242;
v_30243:
    v_30275 = (LispObject)lessp2(v_30276, v_30275);
    v_30275 = v_30275 ? lisp_true : nil;
    env = stack[-2];
    if (v_30275 == nil) goto v_30238;
    goto v_30253;
v_30249:
    v_30275 = stack[-1];
    v_30276 = negate(v_30275);
    env = stack[-2];
    goto v_30250;
v_30251:
    v_30275 = stack[0];
    goto v_30252;
v_30253:
    goto v_30249;
v_30250:
    goto v_30251;
v_30252:
    v_30275 = quot2(v_30276, v_30275);
    return negate(v_30275);
v_30238:
    goto v_30264;
v_30260:
    goto v_30270;
v_30266:
    goto v_30267;
v_30268:
    v_30275 = stack[0];
    v_30275 = sub1(v_30275);
    env = stack[-2];
    goto v_30269;
v_30270:
    goto v_30266;
v_30267:
    goto v_30268;
v_30269:
    v_30276 = plus2(stack[-1], v_30275);
    goto v_30261;
v_30262:
    v_30275 = stack[0];
    goto v_30263;
v_30264:
    goto v_30260;
v_30261:
    goto v_30262;
v_30263:
    return quot2(v_30276, v_30275);
    v_30275 = nil;
    return onevalue(v_30275);
}



// Code for constructinvolutivebasis

static LispObject CC_constructinvolutivebasis(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30524, v_30525, v_30526;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30232,v_30233);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_30233;
    stack[0] = v_30232;
// end of prologue
    goto v_30248;
v_30244:
    v_30525 = stack[0];
    goto v_30245;
v_30246:
    v_30524 = lisp_true;
    goto v_30247;
v_30248:
    goto v_30244;
v_30245:
    goto v_30246;
v_30247:
    fn = elt(env, 4); // polynomlistautoreduce
    v_30524 = (*qfn2(fn))(fn, v_30525, v_30524);
    env = stack[-7];
    stack[0] = v_30524;
v_30253:
    v_30524 = stack[0];
    v_30524 = qcar(v_30524);
    if (v_30524 == nil) goto v_30256;
    else goto v_30257;
v_30256:
    goto v_30252;
v_30257:
    goto v_30266;
v_30262:
    stack[-1] = qvalue(elt(env, 1)); // fluidbibasissetq
    goto v_30263;
v_30264:
    v_30524 = stack[0];
    v_30524 = qcar(v_30524);
    fn = elt(env, 5); // createtriple
    v_30524 = (*qfn1(fn))(fn, v_30524);
    env = stack[-7];
    goto v_30265;
v_30266:
    goto v_30262;
v_30263:
    goto v_30264;
v_30265:
    fn = elt(env, 6); // sortedtriplelistinsert
    v_30524 = (*qfn2(fn))(fn, stack[-1], v_30524);
    env = stack[-7];
    v_30524 = stack[0];
    v_30524 = qcdr(v_30524);
    stack[0] = v_30524;
    goto v_30253;
v_30252:
v_30276:
    v_30524 = qvalue(elt(env, 1)); // fluidbibasissetq
    v_30524 = qcar(v_30524);
    if (v_30524 == nil) goto v_30279;
    else goto v_30280;
v_30279:
    goto v_30275;
v_30280:
    fn = elt(env, 7); // setqget
    v_30524 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    stack[-6] = v_30524;
    goto v_30289;
v_30285:
    v_30525 = stack[-6];
    goto v_30286;
v_30287:
    v_30524 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30288;
v_30289:
    goto v_30285;
v_30286:
    goto v_30287;
v_30288:
    v_30524 = *(LispObject *)((char *)v_30525 + (CELL-TAG_VECTOR) + (((intptr_t)v_30524-TAG_FIXNUM)/(16/CELL)));
    v_30524 = qcar(v_30524);
    stack[-4] = v_30524;
    goto v_30299;
v_30295:
    v_30525 = stack[-6];
    goto v_30296;
v_30297:
    v_30524 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30298;
v_30299:
    goto v_30295;
v_30296:
    goto v_30297;
v_30298:
    v_30524 = *(LispObject *)((char *)v_30525 + (CELL-TAG_VECTOR) + (((intptr_t)v_30524-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 8); // normalform
    v_30524 = (*qfn1(fn))(fn, v_30524);
    env = stack[-7];
    stack[-3] = v_30524;
    v_30524 = stack[-3];
    v_30524 = qcar(v_30524);
    stack[-2] = v_30524;
    v_30524 = stack[-2];
    if (v_30524 == nil) goto v_30308;
    v_30524 = qvalue(elt(env, 2)); // fluidbibasisnonzeronormalforms
    v_30524 = (LispObject)((intptr_t)(v_30524) + 0x10);
    qvalue(elt(env, 2)) = v_30524; // fluidbibasisnonzeronormalforms
    v_30524 = nil;
    v_30524 = ncons(v_30524);
    env = stack[-7];
    stack[0] = v_30524;
    v_30524 = qvalue(elt(env, 3)); // fluidbibasissett
    stack[-1] = v_30524;
v_30317:
    v_30524 = stack[-1];
    v_30524 = qcar(v_30524);
    if (v_30524 == nil) goto v_30320;
    else goto v_30321;
v_30320:
    goto v_30316;
v_30321:
    goto v_30334;
v_30330:
    goto v_30339;
v_30335:
    v_30524 = stack[-1];
    v_30525 = qcar(v_30524);
    goto v_30336;
v_30337:
    v_30524 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30338;
v_30339:
    goto v_30335;
v_30336:
    goto v_30337;
v_30338:
    v_30524 = *(LispObject *)((char *)v_30525 + (CELL-TAG_VECTOR) + (((intptr_t)v_30524-TAG_FIXNUM)/(16/CELL)));
    v_30525 = qcar(v_30524);
    goto v_30331;
v_30332:
    v_30524 = stack[-2];
    goto v_30333;
v_30334:
    goto v_30330;
v_30331:
    goto v_30332;
v_30333:
    fn = elt(env, 9); // monomisdivisibleby
    v_30524 = (*qfn2(fn))(fn, v_30525, v_30524);
    env = stack[-7];
    if (v_30524 == nil) goto v_30328;
    goto v_30351;
v_30347:
    v_30524 = stack[-1];
    v_30525 = qcar(v_30524);
    goto v_30348;
v_30349:
    v_30524 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30350;
v_30351:
    goto v_30347;
v_30348:
    goto v_30349;
v_30350:
    v_30524 = *(LispObject *)((char *)v_30525 + (CELL-TAG_VECTOR) + (((intptr_t)v_30524-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 10); // setqdeletedescendants
    v_30524 = (*qfn1(fn))(fn, v_30524);
    env = stack[-7];
    goto v_30361;
v_30357:
    v_30525 = stack[0];
    goto v_30358;
v_30359:
    v_30524 = stack[-1];
    v_30524 = qcar(v_30524);
    goto v_30360;
v_30361:
    goto v_30357;
v_30358:
    goto v_30359;
v_30360:
    fn = elt(env, 6); // sortedtriplelistinsert
    v_30524 = (*qfn2(fn))(fn, v_30525, v_30524);
    env = stack[-7];
    goto v_30370;
v_30366:
    v_30524 = stack[-1];
    v_30525 = qcar(v_30524);
    goto v_30367;
v_30368:
    v_30524 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30369;
v_30370:
    goto v_30366;
v_30367:
    goto v_30368;
v_30369:
    v_30524 = *(LispObject *)((char *)v_30525 + (CELL-TAG_VECTOR) + (((intptr_t)v_30524-TAG_FIXNUM)/(16/CELL)));
    v_30524 = qcar(v_30524);
    fn = elt(env, 11); // janettreedelete
    v_30524 = (*qfn1(fn))(fn, v_30524);
    env = stack[-7];
    goto v_30381;
v_30377:
    goto v_30387;
v_30383:
    v_30525 = stack[-1];
    goto v_30384;
v_30385:
    v_30524 = stack[-1];
    v_30524 = qcdr(v_30524);
    v_30524 = qcar(v_30524);
    goto v_30386;
v_30387:
    goto v_30383;
v_30384:
    goto v_30385;
v_30386:
    v_30525 = Lrplaca(nil, v_30525, v_30524);
    env = stack[-7];
    goto v_30378;
v_30379:
    v_30524 = stack[-1];
    v_30524 = qcdr(v_30524);
    v_30524 = qcdr(v_30524);
    goto v_30380;
v_30381:
    goto v_30377;
v_30378:
    goto v_30379;
v_30380:
    v_30524 = Lrplacd(nil, v_30525, v_30524);
    env = stack[-7];
    goto v_30326;
v_30328:
    v_30524 = stack[-1];
    v_30524 = qcdr(v_30524);
    stack[-1] = v_30524;
    goto v_30326;
v_30326:
    goto v_30317;
v_30316:
    goto v_30410;
v_30406:
    v_30525 = stack[-4];
    goto v_30407;
v_30408:
    v_30524 = stack[-2];
    goto v_30409;
v_30410:
    goto v_30406;
v_30407:
    goto v_30408;
v_30409:
    if (v_30525 == v_30524) goto v_30404;
    else goto v_30405;
v_30404:
    goto v_30419;
v_30415:
    v_30526 = stack[-3];
    goto v_30416;
v_30417:
    goto v_30425;
v_30421:
    v_30525 = stack[-6];
    goto v_30422;
v_30423:
    v_30524 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_30424;
v_30425:
    goto v_30421;
v_30422:
    goto v_30423;
v_30424:
    v_30524 = *(LispObject *)((char *)v_30525 + (CELL-TAG_VECTOR) + (((intptr_t)v_30524-TAG_FIXNUM)/(16/CELL)));
    goto v_30418;
v_30419:
    goto v_30415;
v_30416:
    goto v_30417;
v_30418:
    fn = elt(env, 12); // createtriplewithancestor
    v_30524 = (*qfn2(fn))(fn, v_30526, v_30524);
    env = stack[-7];
    fn = elt(env, 13); // settinsert
    v_30524 = (*qfn1(fn))(fn, v_30524);
    env = stack[-7];
    goto v_30434;
v_30430:
    v_30524 = qvalue(elt(env, 3)); // fluidbibasissett
    v_30526 = qcar(v_30524);
    goto v_30431;
v_30432:
    goto v_30441;
v_30437:
    v_30525 = stack[-6];
    goto v_30438;
v_30439:
    v_30524 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_30440;
v_30441:
    goto v_30437;
v_30438:
    goto v_30439;
v_30440:
    v_30524 = *(LispObject *)((char *)v_30525 + (CELL-TAG_VECTOR) + (((intptr_t)v_30524-TAG_FIXNUM)/(16/CELL)));
    goto v_30433;
v_30434:
    goto v_30430;
v_30431:
    goto v_30432;
v_30433:
    fn = elt(env, 14); // triplesetprolongset
    v_30524 = (*qfn2(fn))(fn, v_30526, v_30524);
    env = stack[-7];
    goto v_30403;
v_30405:
    v_30524 = stack[-3];
    fn = elt(env, 5); // createtriple
    v_30524 = (*qfn1(fn))(fn, v_30524);
    env = stack[-7];
    fn = elt(env, 13); // settinsert
    v_30524 = (*qfn1(fn))(fn, v_30524);
    env = stack[-7];
    goto v_30403;
v_30403:
    v_30524 = stack[0];
    fn = elt(env, 15); // settcollectnonmultiprolongations
    v_30524 = (*qfn1(fn))(fn, v_30524);
    env = stack[-7];
    goto v_30463;
v_30459:
    goto v_30468;
v_30464:
    v_30525 = stack[-2];
    goto v_30465;
v_30466:
    v_30524 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30467;
v_30468:
    goto v_30464;
v_30465:
    goto v_30466;
v_30467:
    v_30525 = *(LispObject *)((char *)v_30525 + (CELL-TAG_VECTOR) + (((intptr_t)v_30524-TAG_FIXNUM)/(16/CELL)));
    goto v_30460;
v_30461:
    v_30524 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30462;
v_30463:
    goto v_30459;
v_30460:
    goto v_30461;
v_30462:
    v_30524 = Leqn(nil, v_30525, v_30524);
    env = stack[-7];
    if (v_30524 == nil) goto v_30457;
    v_30524 = nil;
    v_30524 = ncons(v_30524);
    env = stack[-7];
    qvalue(elt(env, 1)) = v_30524; // fluidbibasissetq
    goto v_30455;
v_30457:
    v_30524 = stack[0];
    fn = elt(env, 16); // setqinsertlist
    v_30524 = (*qfn1(fn))(fn, v_30524);
    env = stack[-7];
    goto v_30455;
v_30455:
    goto v_30306;
v_30308:
v_30306:
    goto v_30276;
v_30275:
    v_30524 = nil;
    v_30524 = ncons(v_30524);
    env = stack[-7];
    stack[0] = v_30524;
    v_30524 = qvalue(elt(env, 3)); // fluidbibasissett
    stack[-1] = v_30524;
v_30488:
    v_30524 = stack[-1];
    v_30524 = qcar(v_30524);
    if (v_30524 == nil) goto v_30491;
    else goto v_30492;
v_30491:
    goto v_30487;
v_30492:
    goto v_30501;
v_30497:
    v_30526 = stack[0];
    goto v_30498;
v_30499:
    goto v_30507;
v_30503:
    v_30524 = stack[-1];
    v_30525 = qcar(v_30524);
    goto v_30504;
v_30505:
    v_30524 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30506;
v_30507:
    goto v_30503;
v_30504:
    goto v_30505;
v_30506:
    v_30524 = *(LispObject *)((char *)v_30525 + (CELL-TAG_VECTOR) + (((intptr_t)v_30524-TAG_FIXNUM)/(16/CELL)));
    goto v_30500;
v_30501:
    goto v_30497;
v_30498:
    goto v_30499;
v_30500:
    fn = elt(env, 17); // sortedpolynomlistinsert
    v_30524 = (*qfn2(fn))(fn, v_30526, v_30524);
    env = stack[-7];
    v_30524 = stack[-1];
    v_30524 = qcdr(v_30524);
    stack[-1] = v_30524;
    goto v_30488;
v_30487:
    goto v_30520;
v_30516:
    v_30525 = stack[0];
    goto v_30517;
v_30518:
    v_30524 = stack[-5];
    goto v_30519;
v_30520:
    goto v_30516;
v_30517:
    goto v_30518;
v_30519:
    {
        fn = elt(env, 4); // polynomlistautoreduce
        return (*qfn2(fn))(fn, v_30525, v_30524);
    }
    return onevalue(v_30524);
}



// Code for ofsf_canegrel

static LispObject CC_ofsf_canegrel(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30245, v_30246;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30245 = v_30233;
    v_30246 = v_30232;
// end of prologue
    if (v_30245 == nil) goto v_30238;
    v_30245 = v_30246;
    goto v_30236;
v_30238:
    v_30245 = v_30246;
    {
        fn = elt(env, 1); // ofsf_anegrel
        return (*qfn1(fn))(fn, v_30245);
    }
    v_30245 = nil;
v_30236:
    return onevalue(v_30245);
}



// Code for talp_cocc

static LispObject CC_talp_cocc(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30309, v_30310, v_30311;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30232,v_30233);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_30233;
    v_30309 = v_30232;
// end of prologue
    v_30310 = (LispObject)0+TAG_FIXNUM; // 0
    v_30311 = v_30310;
    v_30310 = v_30309;
    v_30310 = Lconsp(nil, v_30310);
    env = stack[-3];
    if (v_30310 == nil) goto v_30243;
    stack[-2] = v_30309;
v_30249:
    v_30309 = stack[-2];
    if (v_30309 == nil) goto v_30253;
    else goto v_30254;
v_30253:
    goto v_30248;
v_30254:
    v_30309 = stack[-2];
    v_30309 = qcar(v_30309);
    v_30310 = v_30309;
    v_30309 = v_30310;
    v_30309 = Lconsp(nil, v_30309);
    env = stack[-3];
    if (v_30309 == nil) goto v_30263;
    goto v_30271;
v_30267:
    stack[0] = v_30311;
    goto v_30268;
v_30269:
    goto v_30278;
v_30274:
    goto v_30275;
v_30276:
    v_30309 = stack[-1];
    goto v_30277;
v_30278:
    goto v_30274;
v_30275:
    goto v_30276;
v_30277:
    v_30309 = CC_talp_cocc(elt(env, 0), v_30310, v_30309);
    env = stack[-3];
    goto v_30270;
v_30271:
    goto v_30267;
v_30268:
    goto v_30269;
v_30270:
    v_30309 = plus2(stack[0], v_30309);
    env = stack[-3];
    v_30311 = v_30309;
    goto v_30261;
v_30263:
    goto v_30291;
v_30287:
    goto v_30288;
v_30289:
    v_30309 = stack[-1];
    goto v_30290;
v_30291:
    goto v_30287;
v_30288:
    goto v_30289;
v_30290:
    if (v_30310 == v_30309) goto v_30285;
    else goto v_30286;
v_30285:
    v_30309 = v_30311;
    v_30309 = add1(v_30309);
    env = stack[-3];
    v_30311 = v_30309;
    goto v_30284;
v_30286:
v_30284:
    goto v_30261;
v_30261:
    v_30309 = stack[-2];
    v_30309 = qcdr(v_30309);
    stack[-2] = v_30309;
    goto v_30249;
v_30248:
    goto v_30241;
v_30243:
    goto v_30304;
v_30300:
    v_30310 = stack[-1];
    goto v_30301;
v_30302:
    goto v_30303;
v_30304:
    goto v_30300;
v_30301:
    goto v_30302;
v_30303:
    if (v_30310 == v_30309) goto v_30298;
    else goto v_30299;
v_30298:
    v_30309 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30237;
v_30299:
v_30241:
    v_30309 = v_30311;
v_30237:
    return onevalue(v_30309);
}



// Code for pasf_smordtable2

static LispObject CC_pasf_smordtable2(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30255, v_30256, v_30257;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30255 = v_30233;
    v_30256 = v_30232;
// end of prologue
    v_30257 = elt(env, 1); // ((lessp (lessp 2) (leq 2) (equal 2) (neq nil) (geq nil) (greaterp nil) (cong nil) (ncong nil)) (leq (lessp 2) (leq 2) (equal
// 2) (neq nil) (geq nil) (greaterp nil) (cong nil) (ncong nil)) (equal (lessp false) (leq false) (equal false) (neq 1) (geq
// 1) (greaterp 1) (cong nil) (ncong nil)) (neq (lessp 2) (leq 2) (equal 2) (neq nil) (geq nil) (greaterp nil) (cong nil) (ncong
// nil)) (geq (lessp false) (leq false) (equal false) (neq 1) (geq 1) (greaterp 1) (cong nil) (ncong nil)) (greaterp (lessp
// false) (leq false) (equal false) (neq 1) (geq 1) (greaterp 1) (cong nil) (ncong nil)))
    goto v_30243;
v_30239:
    goto v_30240;
v_30241:
    goto v_30249;
v_30245:
    goto v_30246;
v_30247:
    goto v_30248;
v_30249:
    goto v_30245;
v_30246:
    goto v_30247;
v_30248:
    v_30256 = Latsoc(nil, v_30256, v_30257);
    goto v_30242;
v_30243:
    goto v_30239;
v_30240:
    goto v_30241;
v_30242:
    v_30255 = Latsoc(nil, v_30255, v_30256);
    v_30255 = qcdr(v_30255);
    return onevalue(v_30255);
}



// Code for ldf!-sep!-var

static LispObject CC_ldfKsepKvar(LispObject env,
                         LispObject v_30232)
{
    env = qenv(env);
    LispObject v_30252;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30232);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30232;
// end of prologue
    goto v_30239;
v_30235:
    goto v_30245;
v_30241:
    v_30252 = stack[0];
    fn = elt(env, 1); // ldf!-pow!-var
    stack[-1] = (*qfn1(fn))(fn, v_30252);
    env = stack[-2];
    goto v_30242;
v_30243:
    v_30252 = stack[0];
    fn = elt(env, 2); // ldf!-dep!-var
    v_30252 = (*qfn1(fn))(fn, v_30252);
    env = stack[-2];
    goto v_30244;
v_30245:
    goto v_30241;
v_30242:
    goto v_30243;
v_30244:
    fn = elt(env, 3); // compl
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_30252);
    env = stack[-2];
    goto v_30236;
v_30237:
    v_30252 = stack[0];
    fn = elt(env, 4); // ldf!-spf!-var
    v_30252 = (*qfn1(fn))(fn, v_30252);
    env = stack[-2];
    goto v_30238;
v_30239:
    goto v_30235;
v_30236:
    goto v_30237;
v_30238:
    {
        LispObject v_30255 = stack[-1];
        fn = elt(env, 3); // compl
        return (*qfn2(fn))(fn, v_30255, v_30252);
    }
}



// Code for dipreplus

static LispObject CC_dipreplus(LispObject env,
                         LispObject v_30232)
{
    env = qenv(env);
    LispObject v_30256, v_30257;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30257 = v_30232;
// end of prologue
    v_30256 = v_30257;
    if (!consp(v_30256)) goto v_30236;
    else goto v_30237;
v_30236:
    v_30256 = v_30257;
    goto v_30235;
v_30237:
    v_30256 = v_30257;
    v_30256 = qcdr(v_30256);
    if (v_30256 == nil) goto v_30240;
    else goto v_30241;
v_30240:
    v_30256 = v_30257;
    v_30256 = qcar(v_30256);
    goto v_30235;
v_30241:
    goto v_30253;
v_30249:
    v_30256 = elt(env, 1); // plus
    goto v_30250;
v_30251:
    goto v_30252;
v_30253:
    goto v_30249;
v_30250:
    goto v_30251;
v_30252:
    return cons(v_30256, v_30257);
    v_30256 = nil;
v_30235:
    return onevalue(v_30256);
}



// Code for make_wedge_pair

static LispObject CC_make_wedge_pair(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30324, v_30325, v_30326;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30232,v_30233);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_30233;
    stack[-2] = v_30232;
// end of prologue
    goto v_30240;
v_30236:
    goto v_30246;
v_30242:
    v_30325 = stack[-2];
    goto v_30243;
v_30244:
    v_30324 = stack[-2];
    goto v_30245;
v_30246:
    goto v_30242;
v_30243:
    goto v_30244;
v_30245:
    stack[0] = list2(v_30325, v_30324);
    env = stack[-4];
    goto v_30237;
v_30238:
    v_30324 = stack[-1];
    fn = elt(env, 4); // xval
    v_30324 = (*qfn1(fn))(fn, v_30324);
    env = stack[-4];
    goto v_30239;
v_30240:
    goto v_30236;
v_30237:
    goto v_30238;
v_30239:
    fn = elt(env, 5); // xlcm
    v_30324 = (*qfn2(fn))(fn, stack[0], v_30324);
    env = stack[-4];
    stack[-3] = v_30324;
    v_30324 = qvalue(elt(env, 1)); // !*twosided
    if (v_30324 == nil) goto v_30256;
    v_30324 = qvalue(elt(env, 2)); // xtruncate!*
    if (v_30324 == nil) goto v_30259;
    else goto v_30256;
v_30259:
    goto v_30255;
v_30256:
    goto v_30266;
v_30262:
    stack[0] = stack[-2];
    goto v_30263;
v_30264:
    v_30324 = stack[-1];
    fn = elt(env, 4); // xval
    v_30324 = (*qfn1(fn))(fn, v_30324);
    env = stack[-4];
    goto v_30265;
v_30266:
    goto v_30262;
v_30263:
    goto v_30264;
v_30265:
    v_30324 = Lmemq(nil, stack[0], v_30324);
    if (v_30324 == nil) goto v_30261;
    else goto v_30255;
v_30261:
    v_30324 = nil;
    goto v_30253;
v_30255:
    goto v_30283;
v_30279:
    v_30325 = stack[-2];
    goto v_30280;
v_30281:
    v_30324 = stack[-1];
    goto v_30282;
v_30283:
    goto v_30279;
v_30280:
    goto v_30281;
v_30282:
    fn = elt(env, 6); // overall_factor
    v_30324 = (*qfn2(fn))(fn, v_30325, v_30324);
    env = stack[-4];
    if (v_30324 == nil) goto v_30276;
    else goto v_30277;
v_30276:
    v_30324 = stack[-3];
    fn = elt(env, 7); // mknwedge
    v_30324 = (*qfn1(fn))(fn, v_30324);
    env = stack[-4];
    fn = elt(env, 8); // xdegreecheck
    v_30324 = (*qfn1(fn))(fn, v_30324);
    env = stack[-4];
    if (v_30324 == nil) goto v_30288;
    else goto v_30289;
v_30288:
    goto v_30302;
v_30294:
    goto v_30295;
v_30296:
    stack[0] = elt(env, 3); // wedge_pair
    goto v_30297;
v_30298:
    goto v_30313;
v_30307:
    v_30326 = stack[-2];
    goto v_30308;
v_30309:
    v_30325 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30310;
v_30311:
    v_30324 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30312;
v_30313:
    goto v_30307;
v_30308:
    goto v_30309;
v_30310:
    goto v_30311;
v_30312:
    v_30324 = list2star(v_30326, v_30325, v_30324);
    env = stack[-4];
    v_30325 = ncons(v_30324);
    goto v_30299;
v_30300:
    v_30324 = stack[-1];
    goto v_30301;
v_30302:
    goto v_30294;
v_30295:
    goto v_30296;
v_30297:
    goto v_30298;
v_30299:
    goto v_30300;
v_30301:
    {
        LispObject v_30331 = stack[-3];
        LispObject v_30332 = stack[0];
        return list4(v_30331, v_30332, v_30325, v_30324);
    }
v_30289:
    v_30324 = nil;
    goto v_30287;
    v_30324 = nil;
v_30287:
    goto v_30275;
v_30277:
    v_30324 = nil;
    goto v_30275;
    v_30324 = nil;
v_30275:
    goto v_30253;
    v_30324 = nil;
v_30253:
    return onevalue(v_30324);
}



// Code for gbftimes

static LispObject CC_gbftimes(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30299, v_30300, v_30301;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30232,v_30233);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_30300 = v_30233;
    v_30301 = v_30232;
// end of prologue
    v_30299 = v_30301;
    v_30299 = qcar(v_30299);
    stack[-4] = v_30299;
    v_30299 = v_30301;
    v_30299 = qcdr(v_30299);
    stack[-3] = v_30299;
    v_30299 = v_30300;
    v_30299 = qcar(v_30299);
    stack[-2] = v_30299;
    v_30299 = v_30300;
    v_30299 = qcdr(v_30299);
    stack[-1] = v_30299;
    goto v_30254;
v_30250:
    goto v_30260;
v_30256:
    goto v_30266;
v_30262:
    v_30300 = stack[-4];
    goto v_30263;
v_30264:
    v_30299 = stack[-2];
    goto v_30265;
v_30266:
    goto v_30262;
v_30263:
    goto v_30264;
v_30265:
    fn = elt(env, 1); // csl_timbf
    stack[0] = (*qfn2(fn))(fn, v_30300, v_30299);
    env = stack[-5];
    goto v_30257;
v_30258:
    goto v_30274;
v_30270:
    v_30300 = stack[-3];
    goto v_30271;
v_30272:
    v_30299 = stack[-1];
    goto v_30273;
v_30274:
    goto v_30270;
v_30271:
    goto v_30272;
v_30273:
    fn = elt(env, 1); // csl_timbf
    v_30299 = (*qfn2(fn))(fn, v_30300, v_30299);
    env = stack[-5];
    goto v_30259;
v_30260:
    goto v_30256;
v_30257:
    goto v_30258;
v_30259:
    fn = elt(env, 2); // difbf
    stack[0] = (*qfn2(fn))(fn, stack[0], v_30299);
    env = stack[-5];
    goto v_30251;
v_30252:
    goto v_30282;
v_30278:
    goto v_30288;
v_30284:
    v_30300 = stack[-4];
    goto v_30285;
v_30286:
    v_30299 = stack[-1];
    goto v_30287;
v_30288:
    goto v_30284;
v_30285:
    goto v_30286;
v_30287:
    fn = elt(env, 1); // csl_timbf
    stack[-1] = (*qfn2(fn))(fn, v_30300, v_30299);
    env = stack[-5];
    goto v_30279;
v_30280:
    goto v_30296;
v_30292:
    v_30300 = stack[-3];
    goto v_30293;
v_30294:
    v_30299 = stack[-2];
    goto v_30295;
v_30296:
    goto v_30292;
v_30293:
    goto v_30294;
v_30295:
    fn = elt(env, 1); // csl_timbf
    v_30299 = (*qfn2(fn))(fn, v_30300, v_30299);
    env = stack[-5];
    goto v_30281;
v_30282:
    goto v_30278;
v_30279:
    goto v_30280;
v_30281:
    fn = elt(env, 3); // plubf
    v_30299 = (*qfn2(fn))(fn, stack[-1], v_30299);
    goto v_30253;
v_30254:
    goto v_30250;
v_30251:
    goto v_30252;
v_30253:
    {
        LispObject v_30307 = stack[0];
        return cons(v_30307, v_30299);
    }
    return onevalue(v_30299);
}



// Code for gpexpp

static LispObject CC_gpexpp(LispObject env,
                         LispObject v_30232)
{
    env = qenv(env);
    LispObject v_30469, v_30470;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30232);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_30232;
// end of prologue
v_30237:
    v_30469 = stack[0];
    if (!consp(v_30469)) goto v_30240;
    else goto v_30241;
v_30240:
    v_30469 = stack[0];
    v_30469 = Lsymbolp(nil, v_30469);
    v_30470 = v_30469;
    if (v_30469 == nil) goto v_30246;
    v_30469 = v_30470;
    goto v_30236;
v_30246:
    v_30469 = stack[0];
    v_30469 = (is_number(v_30469) ? lisp_true : nil);
    v_30470 = v_30469;
    if (v_30469 == nil) goto v_30251;
    v_30469 = v_30470;
    goto v_30236;
v_30251:
    v_30469 = nil;
    goto v_30236;
    goto v_30239;
v_30241:
    goto v_30264;
v_30260:
    v_30469 = stack[0];
    v_30470 = qcar(v_30469);
    goto v_30261;
v_30262:
    v_30469 = elt(env, 1); // (!:rd!: !:cr!: !:crn!: !:gi!:)
    goto v_30263;
v_30264:
    goto v_30260;
v_30261:
    goto v_30262;
v_30263:
    v_30469 = Lmemq(nil, v_30470, v_30469);
    if (v_30469 == nil) goto v_30259;
    v_30469 = lisp_true;
    goto v_30236;
v_30259:
    goto v_30276;
v_30272:
    v_30469 = stack[0];
    v_30470 = qcar(v_30469);
    goto v_30273;
v_30274:
    v_30469 = elt(env, 2); // plus
    goto v_30275;
v_30276:
    goto v_30272;
v_30273:
    goto v_30274;
v_30275:
    if (v_30470 == v_30469) goto v_30270;
    else goto v_30271;
v_30270:
    goto v_30289;
v_30285:
    v_30469 = stack[0];
    v_30470 = Llength(nil, v_30469);
    env = stack[-1];
    goto v_30286;
v_30287:
    v_30469 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_30288;
v_30289:
    goto v_30285;
v_30286:
    goto v_30287;
v_30288:
    v_30469 = (LispObject)geq2(v_30470, v_30469);
    v_30469 = v_30469 ? lisp_true : nil;
    env = stack[-1];
    if (v_30469 == nil) goto v_30283;
    v_30469 = stack[0];
    v_30469 = qcdr(v_30469);
    v_30469 = qcar(v_30469);
    v_30469 = CC_gpexpp(elt(env, 0), v_30469);
    env = stack[-1];
    if (v_30469 == nil) goto v_30296;
    v_30469 = stack[0];
    v_30469 = qcdr(v_30469);
    v_30469 = qcdr(v_30469);
    {
        fn = elt(env, 8); // gpexp1p
        return (*qfn1(fn))(fn, v_30469);
    }
v_30296:
    v_30469 = nil;
    goto v_30236;
    goto v_30281;
v_30283:
    v_30469 = nil;
    goto v_30236;
v_30281:
    goto v_30239;
v_30271:
    goto v_30317;
v_30313:
    v_30469 = stack[0];
    v_30470 = qcar(v_30469);
    goto v_30314;
v_30315:
    v_30469 = elt(env, 3); // (minus recip)
    goto v_30316;
v_30317:
    goto v_30313;
v_30314:
    goto v_30315;
v_30316:
    v_30469 = Lmemq(nil, v_30470, v_30469);
    if (v_30469 == nil) goto v_30312;
    goto v_30330;
v_30326:
    v_30469 = stack[0];
    v_30470 = Llength(nil, v_30469);
    env = stack[-1];
    goto v_30327;
v_30328:
    v_30469 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_30329;
v_30330:
    goto v_30326;
v_30327:
    goto v_30328;
v_30329:
    if (v_30470 == v_30469) goto v_30324;
    else goto v_30325;
v_30324:
    v_30469 = stack[0];
    v_30469 = qcdr(v_30469);
    v_30469 = qcar(v_30469);
    stack[0] = v_30469;
    goto v_30237;
v_30325:
    v_30469 = nil;
    goto v_30236;
    goto v_30239;
v_30312:
    goto v_30346;
v_30342:
    v_30469 = stack[0];
    v_30470 = qcar(v_30469);
    goto v_30343;
v_30344:
    v_30469 = elt(env, 4); // (difference quotient expt)
    goto v_30345;
v_30346:
    goto v_30342;
v_30343:
    goto v_30344;
v_30345:
    v_30469 = Lmemq(nil, v_30470, v_30469);
    if (v_30469 == nil) goto v_30341;
    goto v_30359;
v_30355:
    v_30469 = stack[0];
    v_30470 = Llength(nil, v_30469);
    env = stack[-1];
    goto v_30356;
v_30357:
    v_30469 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_30358;
v_30359:
    goto v_30355;
v_30356:
    goto v_30357;
v_30358:
    if (v_30470 == v_30469) goto v_30353;
    else goto v_30354;
v_30353:
    v_30469 = stack[0];
    v_30469 = qcdr(v_30469);
    v_30469 = qcar(v_30469);
    v_30469 = CC_gpexpp(elt(env, 0), v_30469);
    env = stack[-1];
    if (v_30469 == nil) goto v_30366;
    v_30469 = stack[0];
    v_30469 = qcdr(v_30469);
    v_30469 = qcdr(v_30469);
    v_30469 = qcar(v_30469);
    stack[0] = v_30469;
    goto v_30237;
v_30366:
    v_30469 = nil;
    goto v_30236;
    goto v_30352;
v_30354:
    v_30469 = nil;
    goto v_30236;
v_30352:
    goto v_30239;
v_30341:
    goto v_30387;
v_30383:
    v_30469 = stack[0];
    v_30470 = qcar(v_30469);
    goto v_30384;
v_30385:
    v_30469 = elt(env, 5); // times
    goto v_30386;
v_30387:
    goto v_30383;
v_30384:
    goto v_30385;
v_30386:
    if (v_30470 == v_30469) goto v_30381;
    else goto v_30382;
v_30381:
    goto v_30400;
v_30396:
    v_30469 = stack[0];
    v_30470 = Llength(nil, v_30469);
    env = stack[-1];
    goto v_30397;
v_30398:
    v_30469 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_30399;
v_30400:
    goto v_30396;
v_30397:
    goto v_30398;
v_30399:
    v_30469 = (LispObject)geq2(v_30470, v_30469);
    v_30469 = v_30469 ? lisp_true : nil;
    env = stack[-1];
    if (v_30469 == nil) goto v_30394;
    v_30469 = stack[0];
    v_30469 = qcdr(v_30469);
    v_30469 = qcar(v_30469);
    v_30469 = CC_gpexpp(elt(env, 0), v_30469);
    env = stack[-1];
    if (v_30469 == nil) goto v_30407;
    v_30469 = stack[0];
    v_30469 = qcdr(v_30469);
    v_30469 = qcdr(v_30469);
    v_30469 = qcar(v_30469);
    v_30469 = CC_gpexpp(elt(env, 0), v_30469);
    env = stack[-1];
    if (v_30469 == nil) goto v_30415;
    v_30469 = stack[0];
    v_30469 = qcdr(v_30469);
    v_30469 = qcdr(v_30469);
    v_30469 = qcdr(v_30469);
    {
        fn = elt(env, 8); // gpexp1p
        return (*qfn1(fn))(fn, v_30469);
    }
v_30415:
    v_30469 = nil;
    goto v_30236;
    goto v_30405;
v_30407:
    v_30469 = nil;
    goto v_30236;
v_30405:
    goto v_30392;
v_30394:
    v_30469 = nil;
    goto v_30236;
v_30392:
    goto v_30239;
v_30382:
    goto v_30441;
v_30437:
    v_30469 = stack[0];
    v_30470 = qcar(v_30469);
    goto v_30438;
v_30439:
    v_30469 = elt(env, 6); // !:rd!:
    goto v_30440;
v_30441:
    goto v_30437;
v_30438:
    goto v_30439;
v_30440:
    if (v_30470 == v_30469) goto v_30435;
    else goto v_30436;
v_30435:
    v_30469 = lisp_true;
    goto v_30236;
v_30436:
    goto v_30452;
v_30448:
    v_30469 = stack[0];
    v_30470 = qcar(v_30469);
    goto v_30449;
v_30450:
    v_30469 = elt(env, 7); // (!:cr!: !:crn!: !:gi!:)
    goto v_30451;
v_30452:
    goto v_30448;
v_30449:
    goto v_30450;
v_30451:
    v_30469 = Lmemq(nil, v_30470, v_30469);
    if (v_30469 == nil) goto v_30447;
    v_30469 = lisp_true;
    goto v_30236;
v_30447:
    v_30469 = stack[0];
    v_30469 = qcar(v_30469);
    fn = elt(env, 9); // unresidp
    v_30469 = (*qfn1(fn))(fn, v_30469);
    env = stack[-1];
    if (v_30469 == nil) goto v_30459;
    v_30469 = stack[0];
    v_30469 = qcdr(v_30469);
    {
        fn = elt(env, 10); // gparg1p
        return (*qfn1(fn))(fn, v_30469);
    }
v_30459:
    v_30469 = nil;
    goto v_30236;
v_30239:
    v_30469 = nil;
v_30236:
    return onevalue(v_30469);
}



// Code for positive!-powp

static LispObject CC_positiveKpowp(LispObject env,
                         LispObject v_30232)
{
    env = qenv(env);
    LispObject v_30253, v_30254;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30254 = v_30232;
// end of prologue
    v_30253 = v_30254;
    v_30253 = qcar(v_30253);
    if (!consp(v_30253)) goto v_30237;
    goto v_30244;
v_30240:
    v_30253 = v_30254;
    v_30253 = qcar(v_30253);
    v_30253 = qcar(v_30253);
    goto v_30241;
v_30242:
    v_30254 = elt(env, 1); // (abs norm)
    goto v_30243;
v_30244:
    goto v_30240;
v_30241:
    goto v_30242;
v_30243:
    v_30253 = Lmemq(nil, v_30253, v_30254);
    goto v_30235;
v_30237:
    v_30253 = nil;
    goto v_30235;
    v_30253 = nil;
v_30235:
    return onevalue(v_30253);
}



// Code for ofsf_smmkatl!-and

static LispObject CC_ofsf_smmkatlKand(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30385, v_30386, v_30387;
    LispObject fn;
    LispObject v_30234, v_30233, v_30232;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_smmkatl-and");
    va_start(aa, nargs);
    v_30232 = va_arg(aa, LispObject);
    v_30233 = va_arg(aa, LispObject);
    v_30234 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30234,v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30232,v_30233,v_30234);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_30234;
    v_30385 = v_30233;
    stack[-4] = v_30232;
// end of prologue
    v_30386 = qvalue(elt(env, 1)); // !*rlsipw
    if (v_30386 == nil) goto v_30245;
    else goto v_30246;
v_30245:
    v_30386 = qvalue(elt(env, 2)); // !*rlsipo
    goto v_30244;
v_30246:
    v_30386 = nil;
    goto v_30244;
    v_30386 = nil;
v_30244:
    if (v_30386 == nil) goto v_30242;
    goto v_30259;
v_30253:
    v_30387 = elt(env, 3); // and
    goto v_30254;
v_30255:
    v_30386 = v_30385;
    goto v_30256;
v_30257:
    v_30385 = stack[-3];
    goto v_30258;
v_30259:
    goto v_30253;
v_30254:
    goto v_30255;
v_30256:
    goto v_30257;
v_30258:
    {
        fn = elt(env, 4); // ofsf_irl2atl
        return (*qfnn(fn))(fn, 3, v_30387, v_30386, v_30385);
    }
v_30242:
    stack[-5] = v_30385;
v_30268:
    v_30385 = stack[-5];
    if (v_30385 == nil) goto v_30273;
    else goto v_30274;
v_30273:
    v_30385 = nil;
    goto v_30267;
v_30274:
    v_30385 = stack[-5];
    v_30385 = qcar(v_30385);
    goto v_30284;
v_30280:
    v_30386 = v_30385;
    v_30387 = qcar(v_30386);
    goto v_30281;
v_30282:
    v_30386 = stack[-4];
    goto v_30283;
v_30284:
    goto v_30280;
v_30281:
    goto v_30282;
v_30283:
    v_30386 = Latsoc(nil, v_30387, v_30386);
    v_30387 = v_30386;
    v_30386 = v_30387;
    if (v_30386 == nil) goto v_30291;
    else goto v_30292;
v_30291:
    goto v_30301;
v_30295:
    v_30386 = elt(env, 3); // and
    goto v_30296;
v_30297:
    v_30387 = v_30385;
    goto v_30298;
v_30299:
    v_30385 = stack[-3];
    goto v_30300;
v_30301:
    goto v_30295;
v_30296:
    goto v_30297;
v_30298:
    goto v_30299;
v_30300:
    fn = elt(env, 5); // ofsf_ir2atl
    v_30385 = (*qfnn(fn))(fn, 3, v_30386, v_30387, v_30385);
    env = stack[-6];
    goto v_30290;
v_30292:
    goto v_30314;
v_30308:
    goto v_30309;
v_30310:
    v_30386 = v_30385;
    goto v_30311;
v_30312:
    v_30385 = stack[-3];
    goto v_30313;
v_30314:
    goto v_30308;
v_30309:
    goto v_30310;
v_30311:
    goto v_30312;
v_30313:
    fn = elt(env, 6); // ofsf_smmkatl!-and1
    v_30385 = (*qfnn(fn))(fn, 3, v_30387, v_30386, v_30385);
    env = stack[-6];
    goto v_30290;
    v_30385 = nil;
v_30290:
    stack[-2] = v_30385;
    v_30385 = stack[-2];
    fn = elt(env, 7); // lastpair
    v_30385 = (*qfn1(fn))(fn, v_30385);
    env = stack[-6];
    stack[-1] = v_30385;
    v_30385 = stack[-5];
    v_30385 = qcdr(v_30385);
    stack[-5] = v_30385;
    v_30385 = stack[-1];
    if (!consp(v_30385)) goto v_30324;
    else goto v_30325;
v_30324:
    goto v_30268;
v_30325:
v_30269:
    v_30385 = stack[-5];
    if (v_30385 == nil) goto v_30329;
    else goto v_30330;
v_30329:
    v_30385 = stack[-2];
    goto v_30267;
v_30330:
    goto v_30338;
v_30334:
    stack[0] = stack[-1];
    goto v_30335;
v_30336:
    v_30385 = stack[-5];
    v_30385 = qcar(v_30385);
    goto v_30347;
v_30343:
    v_30386 = v_30385;
    v_30387 = qcar(v_30386);
    goto v_30344;
v_30345:
    v_30386 = stack[-4];
    goto v_30346;
v_30347:
    goto v_30343;
v_30344:
    goto v_30345;
v_30346:
    v_30386 = Latsoc(nil, v_30387, v_30386);
    v_30387 = v_30386;
    v_30386 = v_30387;
    if (v_30386 == nil) goto v_30354;
    else goto v_30355;
v_30354:
    goto v_30364;
v_30358:
    v_30387 = elt(env, 3); // and
    goto v_30359;
v_30360:
    v_30386 = v_30385;
    goto v_30361;
v_30362:
    v_30385 = stack[-3];
    goto v_30363;
v_30364:
    goto v_30358;
v_30359:
    goto v_30360;
v_30361:
    goto v_30362;
v_30363:
    fn = elt(env, 5); // ofsf_ir2atl
    v_30385 = (*qfnn(fn))(fn, 3, v_30387, v_30386, v_30385);
    env = stack[-6];
    goto v_30353;
v_30355:
    goto v_30377;
v_30371:
    goto v_30372;
v_30373:
    v_30386 = v_30385;
    goto v_30374;
v_30375:
    v_30385 = stack[-3];
    goto v_30376;
v_30377:
    goto v_30371;
v_30372:
    goto v_30373;
v_30374:
    goto v_30375;
v_30376:
    fn = elt(env, 6); // ofsf_smmkatl!-and1
    v_30385 = (*qfnn(fn))(fn, 3, v_30387, v_30386, v_30385);
    env = stack[-6];
    goto v_30353;
    v_30385 = nil;
v_30353:
    goto v_30337;
v_30338:
    goto v_30334;
v_30335:
    goto v_30336;
v_30337:
    v_30385 = Lrplacd(nil, stack[0], v_30385);
    env = stack[-6];
    v_30385 = stack[-1];
    fn = elt(env, 7); // lastpair
    v_30385 = (*qfn1(fn))(fn, v_30385);
    env = stack[-6];
    stack[-1] = v_30385;
    v_30385 = stack[-5];
    v_30385 = qcdr(v_30385);
    stack[-5] = v_30385;
    goto v_30269;
v_30267:
    return onevalue(v_30385);
}



// Code for xadd!*

static LispObject CC_xaddH(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30468, v_30469, v_30470;
    LispObject fn;
    LispObject v_30234, v_30233, v_30232;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xadd*");
    va_start(aa, nargs);
    v_30232 = va_arg(aa, LispObject);
    v_30233 = va_arg(aa, LispObject);
    v_30234 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30234,v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30232,v_30233,v_30234);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(14);
// copy arguments values to proper place
    stack[-9] = v_30234;
    stack[-10] = v_30233;
    stack[-11] = v_30232;
// end of prologue
    v_30468 = stack[-10];
    stack[-12] = v_30468;
v_30243:
    v_30468 = stack[-12];
    if (v_30468 == nil) goto v_30246;
    goto v_30259;
v_30255:
    v_30468 = stack[-11];
    v_30469 = qcar(v_30468);
    goto v_30256;
v_30257:
    v_30468 = stack[-12];
    v_30468 = qcar(v_30468);
    v_30468 = qcar(v_30468);
    goto v_30258;
v_30259:
    goto v_30255;
v_30256:
    goto v_30257;
v_30258:
    if (equal(v_30469, v_30468)) goto v_30253;
    else goto v_30254;
v_30253:
    goto v_30269;
v_30265:
    v_30468 = stack[-11];
    v_30468 = qcdr(v_30468);
    v_30469 = qcar(v_30468);
    goto v_30266;
v_30267:
    v_30468 = stack[-12];
    v_30468 = qcar(v_30468);
    v_30468 = qcdr(v_30468);
    v_30468 = qcar(v_30468);
    goto v_30268;
v_30269:
    goto v_30265;
v_30266:
    goto v_30267;
v_30268:
    v_30468 = (equal(v_30469, v_30468) ? lisp_true : nil);
    goto v_30252;
v_30254:
    v_30468 = nil;
    goto v_30252;
    v_30468 = nil;
v_30252:
    if (v_30468 == nil) goto v_30250;
    else goto v_30246;
v_30250:
    goto v_30247;
v_30246:
    goto v_30242;
v_30247:
    v_30468 = stack[-12];
    v_30468 = qcdr(v_30468);
    stack[-12] = v_30468;
    goto v_30243;
v_30242:
    v_30468 = stack[-12];
    if (v_30468 == nil) goto v_30287;
    goto v_30294;
v_30290:
    v_30468 = stack[-12];
    v_30469 = qcar(v_30468);
    goto v_30291;
v_30292:
    v_30468 = stack[-10];
    goto v_30293;
v_30294:
    goto v_30290;
v_30291:
    goto v_30292;
v_30293:
    v_30468 = Ldelete(nil, v_30469, v_30468);
    env = stack[-13];
    stack[-10] = v_30468;
    v_30468 = stack[-12];
    v_30468 = qcar(v_30468);
    stack[-12] = v_30468;
    v_30468 = stack[-9];
    if (v_30468 == nil) goto v_30303;
    v_30468 = qvalue(elt(env, 1)); // newrule!*
    if (v_30468 == nil) goto v_30303;
    goto v_30320;
v_30316:
    v_30468 = stack[-12];
    v_30469 = qcar(v_30468);
    goto v_30317;
v_30318:
    v_30468 = qvalue(elt(env, 1)); // newrule!*
    v_30468 = qcar(v_30468);
    stack[0] = v_30468;
    goto v_30319;
v_30320:
    goto v_30316;
v_30317:
    goto v_30318;
v_30319:
    if (equal(v_30469, v_30468)) goto v_30315;
    v_30468 = stack[-12];
    v_30468 = qcar(v_30468);
    fn = elt(env, 6); // powlisp
    v_30468 = (*qfn1(fn))(fn, v_30468);
    env = stack[-13];
    goto v_30313;
v_30315:
    v_30468 = nil;
    goto v_30313;
    v_30468 = nil;
v_30313:
    if (v_30468 == nil) goto v_30311;
    goto v_30336;
v_30332:
    goto v_30346;
v_30340:
    stack[-8] = elt(env, 2); // plus
    goto v_30341;
v_30342:
    stack[-7] = stack[0];
    goto v_30343;
v_30344:
    goto v_30356;
v_30350:
    stack[-6] = elt(env, 3); // difference
    goto v_30351;
v_30352:
    v_30468 = stack[-12];
    v_30468 = qcdr(v_30468);
    v_30468 = qcdr(v_30468);
    stack[-5] = qcar(v_30468);
    goto v_30353;
v_30354:
    goto v_30367;
v_30363:
    stack[-4] = elt(env, 4); // times
    goto v_30364;
v_30365:
    v_30468 = stack[-12];
    v_30468 = qcar(v_30468);
    stack[-3] = v_30468;
    v_30468 = stack[-3];
    if (v_30468 == nil) goto v_30379;
    else goto v_30380;
v_30379:
    v_30468 = nil;
    goto v_30373;
v_30380:
    v_30468 = stack[-3];
    v_30468 = qcar(v_30468);
    goto v_30394;
v_30388:
    v_30470 = elt(env, 5); // expt
    goto v_30389;
v_30390:
    v_30469 = v_30468;
    v_30469 = qcar(v_30469);
    goto v_30391;
v_30392:
    v_30468 = qcdr(v_30468);
    goto v_30393;
v_30394:
    goto v_30388;
v_30389:
    goto v_30390;
v_30391:
    goto v_30392;
v_30393:
    v_30468 = list3(v_30470, v_30469, v_30468);
    env = stack[-13];
    v_30468 = ncons(v_30468);
    env = stack[-13];
    stack[-1] = v_30468;
    stack[-2] = v_30468;
v_30374:
    v_30468 = stack[-3];
    v_30468 = qcdr(v_30468);
    stack[-3] = v_30468;
    v_30468 = stack[-3];
    if (v_30468 == nil) goto v_30404;
    else goto v_30405;
v_30404:
    v_30468 = stack[-2];
    goto v_30373;
v_30405:
    goto v_30413;
v_30409:
    stack[0] = stack[-1];
    goto v_30410;
v_30411:
    v_30468 = stack[-3];
    v_30468 = qcar(v_30468);
    goto v_30426;
v_30420:
    v_30470 = elt(env, 5); // expt
    goto v_30421;
v_30422:
    v_30469 = v_30468;
    v_30469 = qcar(v_30469);
    goto v_30423;
v_30424:
    v_30468 = qcdr(v_30468);
    goto v_30425;
v_30426:
    goto v_30420;
v_30421:
    goto v_30422;
v_30423:
    goto v_30424;
v_30425:
    v_30468 = list3(v_30470, v_30469, v_30468);
    env = stack[-13];
    v_30468 = ncons(v_30468);
    env = stack[-13];
    goto v_30412;
v_30413:
    goto v_30409;
v_30410:
    goto v_30411;
v_30412:
    v_30468 = Lrplacd(nil, stack[0], v_30468);
    env = stack[-13];
    v_30468 = stack[-1];
    v_30468 = qcdr(v_30468);
    stack[-1] = v_30468;
    goto v_30374;
v_30373:
    goto v_30366;
v_30367:
    goto v_30363;
v_30364:
    goto v_30365;
v_30366:
    v_30468 = cons(stack[-4], v_30468);
    env = stack[-13];
    goto v_30355;
v_30356:
    goto v_30350;
v_30351:
    goto v_30352;
v_30353:
    goto v_30354;
v_30355:
    v_30468 = list3(stack[-6], stack[-5], v_30468);
    env = stack[-13];
    goto v_30345;
v_30346:
    goto v_30340;
v_30341:
    goto v_30342;
v_30343:
    goto v_30344;
v_30345:
    v_30468 = list3(stack[-8], stack[-7], v_30468);
    env = stack[-13];
    fn = elt(env, 7); // simp
    v_30468 = (*qfn1(fn))(fn, v_30468);
    env = stack[-13];
    fn = elt(env, 8); // prepsq
    v_30469 = (*qfn1(fn))(fn, v_30468);
    env = stack[-13];
    goto v_30333;
v_30334:
    v_30468 = stack[-12];
    v_30468 = qcdr(v_30468);
    v_30468 = qcar(v_30468);
    v_30468 = qcdr(v_30468);
    goto v_30335;
v_30336:
    goto v_30332;
v_30333:
    goto v_30334;
v_30335:
    fn = elt(env, 9); // updoldrules
    v_30468 = (*qfn2(fn))(fn, v_30469, v_30468);
    env = stack[-13];
    goto v_30309;
v_30311:
    goto v_30445;
v_30441:
    v_30468 = stack[-12];
    v_30468 = qcdr(v_30468);
    v_30468 = qcdr(v_30468);
    v_30469 = qcar(v_30468);
    goto v_30442;
v_30443:
    v_30468 = stack[-12];
    v_30468 = qcdr(v_30468);
    v_30468 = qcar(v_30468);
    v_30468 = qcdr(v_30468);
    goto v_30444;
v_30445:
    goto v_30441;
v_30442:
    goto v_30443;
v_30444:
    fn = elt(env, 9); // updoldrules
    v_30468 = (*qfn2(fn))(fn, v_30469, v_30468);
    env = stack[-13];
    goto v_30309;
v_30309:
    goto v_30301;
v_30303:
v_30301:
    goto v_30285;
v_30287:
v_30285:
    v_30468 = stack[-9];
    if (v_30468 == nil) goto v_30457;
    goto v_30464;
v_30460:
    v_30469 = stack[-11];
    goto v_30461;
v_30462:
    v_30468 = stack[-10];
    goto v_30463;
v_30464:
    goto v_30460;
v_30461:
    goto v_30462;
v_30463:
    v_30468 = cons(v_30469, v_30468);
    stack[-10] = v_30468;
    goto v_30455;
v_30457:
v_30455:
    v_30468 = stack[-10];
    return onevalue(v_30468);
}



// Code for !*multsq

static LispObject CC_Hmultsq(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30438, v_30439;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30232,v_30233);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_30233;
    stack[-3] = v_30232;
// end of prologue
    v_30438 = stack[-3];
    v_30438 = qcar(v_30438);
    if (v_30438 == nil) goto v_30241;
    else goto v_30242;
v_30241:
    v_30438 = lisp_true;
    goto v_30240;
v_30242:
    v_30438 = stack[-2];
    v_30438 = qcar(v_30438);
    v_30438 = (v_30438 == nil ? lisp_true : nil);
    goto v_30240;
    v_30438 = nil;
v_30240:
    if (v_30438 == nil) goto v_30238;
    goto v_30256;
v_30252:
    v_30439 = nil;
    goto v_30253;
v_30254:
    v_30438 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30255;
v_30256:
    goto v_30252;
v_30253:
    goto v_30254;
v_30255:
    return cons(v_30439, v_30438);
v_30238:
    goto v_30269;
v_30265:
    v_30438 = stack[-3];
    v_30439 = qcdr(v_30438);
    goto v_30266;
v_30267:
    v_30438 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30268;
v_30269:
    goto v_30265;
v_30266:
    goto v_30267;
v_30268:
    if (v_30439 == v_30438) goto v_30263;
    else goto v_30264;
v_30263:
    goto v_30277;
v_30273:
    v_30438 = stack[-2];
    v_30439 = qcdr(v_30438);
    goto v_30274;
v_30275:
    v_30438 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30276;
v_30277:
    goto v_30273;
v_30274:
    goto v_30275;
v_30276:
    v_30438 = (v_30439 == v_30438 ? lisp_true : nil);
    goto v_30262;
v_30264:
    v_30438 = nil;
    goto v_30262;
    v_30438 = nil;
v_30262:
    if (v_30438 == nil) goto v_30260;
    goto v_30290;
v_30286:
    goto v_30296;
v_30292:
    v_30438 = stack[-3];
    v_30439 = qcar(v_30438);
    goto v_30293;
v_30294:
    v_30438 = stack[-2];
    v_30438 = qcar(v_30438);
    goto v_30295;
v_30296:
    goto v_30292;
v_30293:
    goto v_30294;
v_30295:
    fn = elt(env, 1); // !*multf
    v_30439 = (*qfn2(fn))(fn, v_30439, v_30438);
    goto v_30287;
v_30288:
    v_30438 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30289;
v_30290:
    goto v_30286;
v_30287:
    goto v_30288;
v_30289:
    return cons(v_30439, v_30438);
v_30260:
    goto v_30314;
v_30310:
    v_30438 = stack[-3];
    v_30439 = qcar(v_30438);
    goto v_30311;
v_30312:
    v_30438 = stack[-2];
    v_30438 = qcdr(v_30438);
    goto v_30313;
v_30314:
    goto v_30310;
v_30311:
    goto v_30312;
v_30313:
    fn = elt(env, 2); // gcdf
    v_30438 = (*qfn2(fn))(fn, v_30439, v_30438);
    env = stack[-5];
    stack[-4] = v_30438;
    goto v_30324;
v_30320:
    v_30438 = stack[-2];
    v_30439 = qcar(v_30438);
    goto v_30321;
v_30322:
    v_30438 = stack[-3];
    v_30438 = qcdr(v_30438);
    goto v_30323;
v_30324:
    goto v_30320;
v_30321:
    goto v_30322;
v_30323:
    fn = elt(env, 2); // gcdf
    v_30438 = (*qfn2(fn))(fn, v_30439, v_30438);
    env = stack[-5];
    stack[-1] = v_30438;
    goto v_30334;
v_30330:
    goto v_30340;
v_30336:
    v_30438 = stack[-3];
    v_30439 = qcar(v_30438);
    goto v_30337;
v_30338:
    v_30438 = stack[-4];
    goto v_30339;
v_30340:
    goto v_30336;
v_30337:
    goto v_30338;
v_30339:
    fn = elt(env, 3); // quotf!-fail
    stack[0] = (*qfn2(fn))(fn, v_30439, v_30438);
    env = stack[-5];
    goto v_30331;
v_30332:
    goto v_30349;
v_30345:
    v_30438 = stack[-2];
    v_30439 = qcar(v_30438);
    goto v_30346;
v_30347:
    v_30438 = stack[-1];
    goto v_30348;
v_30349:
    goto v_30345;
v_30346:
    goto v_30347;
v_30348:
    fn = elt(env, 3); // quotf!-fail
    v_30438 = (*qfn2(fn))(fn, v_30439, v_30438);
    env = stack[-5];
    goto v_30333;
v_30334:
    goto v_30330;
v_30331:
    goto v_30332;
v_30333:
    fn = elt(env, 1); // !*multf
    v_30438 = (*qfn2(fn))(fn, stack[0], v_30438);
    env = stack[-5];
    stack[0] = v_30438;
    goto v_30358;
v_30354:
    goto v_30364;
v_30360:
    v_30438 = stack[-3];
    v_30439 = qcdr(v_30438);
    goto v_30361;
v_30362:
    v_30438 = stack[-1];
    goto v_30363;
v_30364:
    goto v_30360;
v_30361:
    goto v_30362;
v_30363:
    fn = elt(env, 3); // quotf!-fail
    stack[-1] = (*qfn2(fn))(fn, v_30439, v_30438);
    env = stack[-5];
    goto v_30355;
v_30356:
    goto v_30373;
v_30369:
    v_30438 = stack[-2];
    v_30439 = qcdr(v_30438);
    goto v_30370;
v_30371:
    v_30438 = stack[-4];
    goto v_30372;
v_30373:
    goto v_30369;
v_30370:
    goto v_30371;
v_30372:
    fn = elt(env, 3); // quotf!-fail
    v_30438 = (*qfn2(fn))(fn, v_30439, v_30438);
    env = stack[-5];
    goto v_30357;
v_30358:
    goto v_30354;
v_30355:
    goto v_30356;
v_30357:
    fn = elt(env, 1); // !*multf
    v_30438 = (*qfn2(fn))(fn, stack[-1], v_30438);
    env = stack[-5];
    stack[-4] = v_30438;
    v_30438 = stack[-4];
    fn = elt(env, 4); // minusf
    v_30438 = (*qfn1(fn))(fn, v_30438);
    env = stack[-5];
    if (v_30438 == nil) goto v_30380;
    v_30438 = stack[0];
    fn = elt(env, 5); // negf
    v_30438 = (*qfn1(fn))(fn, v_30438);
    env = stack[-5];
    stack[0] = v_30438;
    v_30438 = stack[-4];
    fn = elt(env, 5); // negf
    v_30438 = (*qfn1(fn))(fn, v_30438);
    env = stack[-5];
    stack[-4] = v_30438;
    goto v_30378;
v_30380:
v_30378:
    goto v_30392;
v_30388:
    v_30439 = stack[0];
    goto v_30389;
v_30390:
    v_30438 = stack[-4];
    goto v_30391;
v_30392:
    goto v_30388;
v_30389:
    goto v_30390;
v_30391:
    fn = elt(env, 2); // gcdf
    v_30438 = (*qfn2(fn))(fn, v_30439, v_30438);
    env = stack[-5];
    stack[-1] = v_30438;
    goto v_30403;
v_30399:
    v_30439 = stack[-1];
    goto v_30400;
v_30401:
    v_30438 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30402;
v_30403:
    goto v_30399;
v_30400:
    goto v_30401;
v_30402:
    if (v_30439 == v_30438) goto v_30397;
    else goto v_30398;
v_30397:
    goto v_30411;
v_30407:
    v_30439 = stack[0];
    goto v_30408;
v_30409:
    v_30438 = stack[-4];
    goto v_30410;
v_30411:
    goto v_30407;
v_30408:
    goto v_30409;
v_30410:
    return cons(v_30439, v_30438);
v_30398:
    goto v_30421;
v_30417:
    goto v_30427;
v_30423:
    v_30439 = stack[0];
    goto v_30424;
v_30425:
    v_30438 = stack[-1];
    goto v_30426;
v_30427:
    goto v_30423;
v_30424:
    goto v_30425;
v_30426:
    fn = elt(env, 3); // quotf!-fail
    stack[0] = (*qfn2(fn))(fn, v_30439, v_30438);
    env = stack[-5];
    goto v_30418;
v_30419:
    goto v_30435;
v_30431:
    v_30439 = stack[-4];
    goto v_30432;
v_30433:
    v_30438 = stack[-1];
    goto v_30434;
v_30435:
    goto v_30431;
v_30432:
    goto v_30433;
v_30434:
    fn = elt(env, 3); // quotf!-fail
    v_30438 = (*qfn2(fn))(fn, v_30439, v_30438);
    goto v_30420;
v_30421:
    goto v_30417;
v_30418:
    goto v_30419;
v_30420:
    {
        LispObject v_30445 = stack[0];
        return cons(v_30445, v_30438);
    }
    v_30438 = nil;
    goto v_30236;
    v_30438 = nil;
v_30236:
    return onevalue(v_30438);
}



// Code for taymindegreel

static LispObject CC_taymindegreel(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30294, v_30295;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30232,v_30233);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_30233;
    stack[-2] = v_30232;
// end of prologue
    stack[-3] = nil;
v_30238:
    v_30294 = stack[-2];
    if (v_30294 == nil) goto v_30241;
    else goto v_30242;
v_30241:
    v_30294 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_30294);
    }
v_30242:
    goto v_30253;
v_30249:
    goto v_30259;
v_30255:
    v_30294 = stack[-2];
    v_30294 = qcar(v_30294);
    stack[0] = v_30294;
    v_30294 = (LispObject)0+TAG_FIXNUM; // 0
    v_30295 = v_30294;
v_30264:
    v_30294 = stack[0];
    if (v_30294 == nil) goto v_30270;
    else goto v_30271;
v_30270:
    v_30294 = v_30295;
    v_30295 = v_30294;
    goto v_30263;
v_30271:
    goto v_30279;
v_30275:
    v_30294 = stack[0];
    v_30294 = qcar(v_30294);
    goto v_30276;
v_30277:
    goto v_30278;
v_30279:
    goto v_30275;
v_30276:
    goto v_30277;
v_30278:
    fn = elt(env, 2); // tayexp!-plus2
    v_30294 = (*qfn2(fn))(fn, v_30294, v_30295);
    env = stack[-4];
    v_30295 = v_30294;
    v_30294 = stack[0];
    v_30294 = qcdr(v_30294);
    stack[0] = v_30294;
    goto v_30264;
v_30263:
    goto v_30256;
v_30257:
    v_30294 = stack[-1];
    v_30294 = qcar(v_30294);
    goto v_30258;
v_30259:
    goto v_30255;
v_30256:
    goto v_30257;
v_30258:
    fn = elt(env, 3); // tayexp!-min2
    v_30295 = (*qfn2(fn))(fn, v_30295, v_30294);
    env = stack[-4];
    goto v_30250;
v_30251:
    v_30294 = stack[-3];
    goto v_30252;
v_30253:
    goto v_30249;
v_30250:
    goto v_30251;
v_30252:
    v_30294 = cons(v_30295, v_30294);
    env = stack[-4];
    stack[-3] = v_30294;
    v_30294 = stack[-2];
    v_30294 = qcdr(v_30294);
    stack[-2] = v_30294;
    v_30294 = stack[-1];
    v_30294 = qcdr(v_30294);
    stack[-1] = v_30294;
    goto v_30238;
    v_30294 = nil;
    return onevalue(v_30294);
}



// Code for cl_susimkatl

static LispObject CC_cl_susimkatl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30506, v_30507, v_30508;
    LispObject fn;
    LispObject v_30235, v_30234, v_30233, v_30232;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_susimkatl");
    va_start(aa, nargs);
    v_30232 = va_arg(aa, LispObject);
    v_30233 = va_arg(aa, LispObject);
    v_30234 = va_arg(aa, LispObject);
    v_30235 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_30235,v_30234,v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_30232,v_30233,v_30234,v_30235);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_30235;
    v_30506 = v_30234;
    stack[-4] = v_30233;
    stack[-5] = v_30232;
// end of prologue
    stack[-6] = v_30506;
v_30245:
    v_30506 = stack[-6];
    if (v_30506 == nil) goto v_30250;
    else goto v_30251;
v_30250:
    v_30506 = nil;
    goto v_30244;
v_30251:
    v_30506 = stack[-6];
    v_30506 = qcar(v_30506);
    v_30508 = v_30506;
    goto v_30265;
v_30261:
    v_30506 = v_30508;
    v_30507 = qcdr(v_30506);
    goto v_30262;
v_30263:
    v_30506 = stack[-3];
    goto v_30264;
v_30265:
    goto v_30261;
v_30262:
    goto v_30263;
v_30264:
    if (equal(v_30507, v_30506)) goto v_30259;
    else goto v_30260;
v_30259:
    v_30506 = v_30508;
    v_30506 = qcar(v_30506);
    v_30506 = ncons(v_30506);
    env = stack[-7];
    goto v_30258;
v_30260:
    v_30506 = nil;
v_30258:
    stack[-2] = v_30506;
    v_30506 = stack[-2];
    fn = elt(env, 6); // lastpair
    v_30506 = (*qfn1(fn))(fn, v_30506);
    env = stack[-7];
    stack[-1] = v_30506;
    v_30506 = stack[-6];
    v_30506 = qcdr(v_30506);
    stack[-6] = v_30506;
    v_30506 = stack[-1];
    if (!consp(v_30506)) goto v_30278;
    else goto v_30279;
v_30278:
    goto v_30245;
v_30279:
v_30246:
    v_30506 = stack[-6];
    if (v_30506 == nil) goto v_30283;
    else goto v_30284;
v_30283:
    v_30506 = stack[-2];
    goto v_30244;
v_30284:
    goto v_30292;
v_30288:
    stack[0] = stack[-1];
    goto v_30289;
v_30290:
    v_30506 = stack[-6];
    v_30506 = qcar(v_30506);
    v_30508 = v_30506;
    goto v_30305;
v_30301:
    v_30506 = v_30508;
    v_30507 = qcdr(v_30506);
    goto v_30302;
v_30303:
    v_30506 = stack[-3];
    goto v_30304;
v_30305:
    goto v_30301;
v_30302:
    goto v_30303;
v_30304:
    if (equal(v_30507, v_30506)) goto v_30299;
    else goto v_30300;
v_30299:
    v_30506 = v_30508;
    v_30506 = qcar(v_30506);
    v_30506 = ncons(v_30506);
    env = stack[-7];
    goto v_30298;
v_30300:
    v_30506 = nil;
v_30298:
    goto v_30291;
v_30292:
    goto v_30288;
v_30289:
    goto v_30290;
v_30291:
    v_30506 = Lrplacd(nil, stack[0], v_30506);
    env = stack[-7];
    v_30506 = stack[-1];
    fn = elt(env, 6); // lastpair
    v_30506 = (*qfn1(fn))(fn, v_30506);
    env = stack[-7];
    stack[-1] = v_30506;
    v_30506 = stack[-6];
    v_30506 = qcdr(v_30506);
    stack[-6] = v_30506;
    goto v_30246;
v_30244:
    v_30508 = v_30506;
    v_30506 = v_30508;
    if (v_30506 == nil) goto v_30318;
    else goto v_30319;
v_30318:
    v_30506 = nil;
    goto v_30239;
v_30319:
    goto v_30327;
v_30323:
    v_30507 = v_30508;
    goto v_30324;
v_30325:
    v_30506 = stack[-4];
    goto v_30326;
v_30327:
    goto v_30323;
v_30324:
    goto v_30325;
v_30326:
    fn = elt(env, 7); // rl_susipost
    v_30506 = (*qfn2(fn))(fn, v_30507, v_30506);
    env = stack[-7];
    v_30508 = v_30506;
    goto v_30342;
v_30338:
    v_30507 = v_30508;
    goto v_30339;
v_30340:
    v_30506 = elt(env, 1); // true
    goto v_30341;
v_30342:
    goto v_30338;
v_30339:
    goto v_30340;
v_30341:
    if (v_30507 == v_30506) goto v_30336;
    else goto v_30337;
v_30336:
    v_30506 = lisp_true;
    goto v_30335;
v_30337:
    goto v_30352;
v_30348:
    v_30507 = v_30508;
    goto v_30349;
v_30350:
    v_30506 = elt(env, 2); // false
    goto v_30351;
v_30352:
    goto v_30348;
v_30349:
    goto v_30350;
v_30351:
    v_30506 = (v_30507 == v_30506 ? lisp_true : nil);
    goto v_30335;
    v_30506 = nil;
v_30335:
    if (v_30506 == nil) goto v_30333;
    goto v_30362;
v_30358:
    goto v_30359;
v_30360:
    goto v_30368;
v_30364:
    v_30507 = stack[-5];
    goto v_30365;
v_30366:
    v_30506 = elt(env, 3); // and
    goto v_30367;
v_30368:
    goto v_30364;
v_30365:
    goto v_30366;
v_30367:
    v_30506 = (v_30507 == v_30506 ? lisp_true : nil);
    goto v_30361;
v_30362:
    goto v_30358;
v_30359:
    goto v_30360;
v_30361:
    fn = elt(env, 8); // cl_cflip
    v_30506 = (*qfn2(fn))(fn, v_30508, v_30506);
    return ncons(v_30506);
v_30333:
    goto v_30380;
v_30376:
    v_30507 = v_30508;
    goto v_30377;
v_30378:
    v_30506 = elt(env, 4); // inctheo
    goto v_30379;
v_30380:
    goto v_30376;
v_30377:
    goto v_30378;
v_30379:
    if (v_30507 == v_30506) goto v_30374;
    else goto v_30375;
v_30374:
    goto v_30388;
v_30384:
    v_30508 = elt(env, 2); // false
    goto v_30385;
v_30386:
    goto v_30394;
v_30390:
    v_30507 = stack[-5];
    goto v_30391;
v_30392:
    v_30506 = elt(env, 3); // and
    goto v_30393;
v_30394:
    goto v_30390;
v_30391:
    goto v_30392;
v_30393:
    v_30506 = (v_30507 == v_30506 ? lisp_true : nil);
    goto v_30387;
v_30388:
    goto v_30384;
v_30385:
    goto v_30386;
v_30387:
    {
        fn = elt(env, 8); // cl_cflip
        return (*qfn2(fn))(fn, v_30508, v_30506);
    }
v_30375:
    goto v_30406;
v_30402:
    v_30507 = stack[-5];
    goto v_30403;
v_30404:
    v_30506 = elt(env, 5); // or
    goto v_30405;
v_30406:
    goto v_30402;
v_30403:
    goto v_30404;
v_30405:
    if (v_30507 == v_30506) goto v_30400;
    else goto v_30401;
v_30400:
    v_30506 = v_30508;
    stack[-3] = v_30506;
    v_30506 = stack[-3];
    if (v_30506 == nil) goto v_30418;
    else goto v_30419;
v_30418:
    v_30506 = nil;
    goto v_30413;
v_30419:
    v_30506 = stack[-3];
    v_30506 = qcar(v_30506);
    fn = elt(env, 9); // rl_negateat
    v_30506 = (*qfn1(fn))(fn, v_30506);
    env = stack[-7];
    v_30506 = ncons(v_30506);
    env = stack[-7];
    stack[-1] = v_30506;
    stack[-2] = v_30506;
v_30414:
    v_30506 = stack[-3];
    v_30506 = qcdr(v_30506);
    stack[-3] = v_30506;
    v_30506 = stack[-3];
    if (v_30506 == nil) goto v_30432;
    else goto v_30433;
v_30432:
    v_30506 = stack[-2];
    goto v_30413;
v_30433:
    goto v_30441;
v_30437:
    stack[0] = stack[-1];
    goto v_30438;
v_30439:
    v_30506 = stack[-3];
    v_30506 = qcar(v_30506);
    fn = elt(env, 9); // rl_negateat
    v_30506 = (*qfn1(fn))(fn, v_30506);
    env = stack[-7];
    v_30506 = ncons(v_30506);
    env = stack[-7];
    goto v_30440;
v_30441:
    goto v_30437;
v_30438:
    goto v_30439;
v_30440:
    v_30506 = Lrplacd(nil, stack[0], v_30506);
    env = stack[-7];
    v_30506 = stack[-1];
    v_30506 = qcdr(v_30506);
    stack[-1] = v_30506;
    goto v_30414;
v_30413:
    v_30508 = v_30506;
    goto v_30399;
v_30401:
v_30399:
    v_30506 = v_30508;
    stack[-3] = v_30506;
    v_30506 = stack[-3];
    if (v_30506 == nil) goto v_30460;
    else goto v_30461;
v_30460:
    v_30506 = nil;
    goto v_30455;
v_30461:
    v_30506 = stack[-3];
    v_30506 = qcar(v_30506);
    goto v_30473;
v_30469:
    v_30507 = v_30506;
    goto v_30470;
v_30471:
    v_30506 = stack[-4];
    goto v_30472;
v_30473:
    goto v_30469;
v_30470:
    goto v_30471;
v_30472:
    fn = elt(env, 10); // rl_susitf
    v_30506 = (*qfn2(fn))(fn, v_30507, v_30506);
    env = stack[-7];
    v_30506 = ncons(v_30506);
    env = stack[-7];
    stack[-1] = v_30506;
    stack[-2] = v_30506;
v_30456:
    v_30506 = stack[-3];
    v_30506 = qcdr(v_30506);
    stack[-3] = v_30506;
    v_30506 = stack[-3];
    if (v_30506 == nil) goto v_30480;
    else goto v_30481;
v_30480:
    v_30506 = stack[-2];
    goto v_30455;
v_30481:
    goto v_30489;
v_30485:
    stack[0] = stack[-1];
    goto v_30486;
v_30487:
    v_30506 = stack[-3];
    v_30506 = qcar(v_30506);
    goto v_30500;
v_30496:
    v_30507 = v_30506;
    goto v_30497;
v_30498:
    v_30506 = stack[-4];
    goto v_30499;
v_30500:
    goto v_30496;
v_30497:
    goto v_30498;
v_30499:
    fn = elt(env, 10); // rl_susitf
    v_30506 = (*qfn2(fn))(fn, v_30507, v_30506);
    env = stack[-7];
    v_30506 = ncons(v_30506);
    env = stack[-7];
    goto v_30488;
v_30489:
    goto v_30485;
v_30486:
    goto v_30487;
v_30488:
    v_30506 = Lrplacd(nil, stack[0], v_30506);
    env = stack[-7];
    v_30506 = stack[-1];
    v_30506 = qcdr(v_30506);
    stack[-1] = v_30506;
    goto v_30456;
v_30455:
    v_30508 = v_30506;
    v_30506 = v_30508;
v_30239:
    return onevalue(v_30506);
}



// Code for sfto_kexp

static LispObject CC_sfto_kexp(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30271, v_30272;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30232,v_30233);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30233;
    stack[-1] = v_30232;
// end of prologue
    goto v_30238;
    goto v_30236;
v_30238:
v_30236:
    goto v_30249;
v_30245:
    v_30272 = stack[0];
    goto v_30246;
v_30247:
    v_30271 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30248;
v_30249:
    goto v_30245;
v_30246:
    goto v_30247;
v_30248:
    v_30271 = Leqn(nil, v_30272, v_30271);
    env = stack[-2];
    if (v_30271 == nil) goto v_30243;
    v_30271 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30241;
v_30243:
    goto v_30261;
v_30257:
    goto v_30267;
v_30263:
    v_30272 = stack[-1];
    goto v_30264;
v_30265:
    v_30271 = stack[0];
    goto v_30266;
v_30267:
    goto v_30263;
v_30264:
    goto v_30265;
v_30266:
    fn = elt(env, 1); // to
    v_30272 = (*qfn2(fn))(fn, v_30272, v_30271);
    env = stack[-2];
    goto v_30258;
v_30259:
    v_30271 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30260;
v_30261:
    goto v_30257;
v_30258:
    goto v_30259;
v_30260:
    v_30271 = cons(v_30272, v_30271);
    return ncons(v_30271);
    v_30271 = nil;
v_30241:
    return onevalue(v_30271);
}



// Code for acfsf_0mk2

static LispObject CC_acfsf_0mk2(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30246, v_30247, v_30248;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30246 = v_30233;
    v_30247 = v_30232;
// end of prologue
    goto v_30242;
v_30236:
    v_30248 = v_30247;
    goto v_30237;
v_30238:
    v_30247 = v_30246;
    goto v_30239;
v_30240:
    v_30246 = nil;
    goto v_30241;
v_30242:
    goto v_30236;
v_30237:
    goto v_30238;
v_30239:
    goto v_30240;
v_30241:
    return list3(v_30248, v_30247, v_30246);
}



// Code for latexprint

static LispObject CC_latexprint(LispObject env,
                         LispObject v_30232)
{
    env = qenv(env);
    LispObject v_30238;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30232);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_30232;
// end of prologue
    fn = elt(env, 1); // prinlabegin
    v_30238 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_30238 = stack[0];
    fn = elt(env, 2); // latexprin
    v_30238 = (*qfn1(fn))(fn, v_30238);
    env = stack[-1];
    {
        fn = elt(env, 3); // prinlaend
        return (*qfnn(fn))(fn, 0);
    }
}



// Code for decimal2internal

static LispObject CC_decimal2internal(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30293, v_30294, v_30295;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30232,v_30233);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30233;
    stack[-1] = v_30232;
// end of prologue
    goto v_30244;
v_30240:
    v_30294 = stack[0];
    goto v_30241;
v_30242:
    v_30293 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30243;
v_30244:
    goto v_30240;
v_30241:
    goto v_30242;
v_30243:
    v_30293 = (LispObject)geq2(v_30294, v_30293);
    v_30293 = v_30293 ? lisp_true : nil;
    env = stack[-3];
    if (v_30293 == nil) goto v_30238;
    goto v_30254;
v_30248:
    stack[-2] = elt(env, 1); // !:rd!:
    goto v_30249;
v_30250:
    goto v_30261;
v_30257:
    goto v_30258;
v_30259:
    goto v_30268;
v_30264:
    v_30294 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_30265;
v_30266:
    v_30293 = stack[0];
    goto v_30267;
v_30268:
    goto v_30264;
v_30265:
    goto v_30266;
v_30267:
    v_30293 = Lexpt(nil, v_30294, v_30293);
    env = stack[-3];
    goto v_30260;
v_30261:
    goto v_30257;
v_30258:
    goto v_30259;
v_30260:
    v_30294 = times2(stack[-1], v_30293);
    goto v_30251;
v_30252:
    v_30293 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30253;
v_30254:
    goto v_30248;
v_30249:
    goto v_30250;
v_30251:
    goto v_30252;
v_30253:
    {
        LispObject v_30299 = stack[-2];
        return list2star(v_30299, v_30294, v_30293);
    }
v_30238:
    goto v_30279;
v_30275:
    goto v_30287;
v_30281:
    v_30295 = elt(env, 1); // !:rd!:
    goto v_30282;
v_30283:
    v_30294 = stack[-1];
    goto v_30284;
v_30285:
    v_30293 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30286;
v_30287:
    goto v_30281;
v_30282:
    goto v_30283;
v_30284:
    goto v_30285;
v_30286:
    stack[-1] = list2star(v_30295, v_30294, v_30293);
    env = stack[-3];
    goto v_30276;
v_30277:
    v_30293 = stack[0];
    v_30293 = negate(v_30293);
    env = stack[-3];
    goto v_30278;
v_30279:
    goto v_30275;
v_30276:
    goto v_30277;
v_30278:
    {
        LispObject v_30300 = stack[-1];
        fn = elt(env, 2); // divide!-by!-power!-of!-ten
        return (*qfn2(fn))(fn, v_30300, v_30293);
    }
    v_30293 = nil;
    return onevalue(v_30293);
}



// Code for is_buble

static LispObject CC_is_buble(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30279, v_30280;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30232,v_30233);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30233;
    stack[-1] = v_30232;
// end of prologue
    goto v_30241;
v_30237:
    v_30280 = stack[-1];
    goto v_30238;
v_30239:
    v_30279 = stack[0];
    goto v_30240;
v_30241:
    goto v_30237;
v_30238:
    goto v_30239;
v_30240:
    fn = elt(env, 1); // diff_vertex
    v_30279 = (*qfn2(fn))(fn, v_30280, v_30279);
    env = stack[-3];
    v_30279 = Llength(nil, v_30279);
    env = stack[-3];
    stack[-2] = v_30279;
    goto v_30254;
v_30250:
    v_30280 = stack[-2];
    goto v_30251;
v_30252:
    v_30279 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_30253;
v_30254:
    goto v_30250;
v_30251:
    goto v_30252;
v_30253:
    v_30279 = (LispObject)geq2(v_30280, v_30279);
    v_30279 = v_30279 ? lisp_true : nil;
    env = stack[-3];
    if (v_30279 == nil) goto v_30248;
    v_30279 = nil;
    goto v_30246;
v_30248:
    goto v_30267;
v_30261:
    goto v_30273;
v_30269:
    v_30280 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_30270;
v_30271:
    v_30279 = stack[-2];
    goto v_30272;
v_30273:
    goto v_30269;
v_30270:
    goto v_30271;
v_30272:
    stack[-2] = times2(v_30280, v_30279);
    env = stack[-3];
    goto v_30262;
v_30263:
    goto v_30264;
v_30265:
    v_30279 = stack[0];
    v_30279 = ncons(v_30279);
    goto v_30266;
v_30267:
    goto v_30261;
v_30262:
    goto v_30263;
v_30264:
    goto v_30265;
v_30266:
    {
        LispObject v_30284 = stack[-2];
        LispObject v_30285 = stack[-1];
        return list2star(v_30284, v_30285, v_30279);
    }
    v_30279 = nil;
v_30246:
    return onevalue(v_30279);
}



// Code for tidysqrtf

static LispObject CC_tidysqrtf(LispObject env,
                         LispObject v_30232)
{
    env = qenv(env);
    LispObject v_30424, v_30425, v_30426;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30232);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_30232;
// end of prologue
    v_30424 = stack[-1];
    if (!consp(v_30424)) goto v_30240;
    else goto v_30241;
v_30240:
    v_30424 = lisp_true;
    goto v_30239;
v_30241:
    v_30424 = stack[-1];
    v_30424 = qcar(v_30424);
    v_30424 = (consp(v_30424) ? nil : lisp_true);
    goto v_30239;
    v_30424 = nil;
v_30239:
    if (v_30424 == nil) goto v_30237;
    goto v_30254;
v_30250:
    v_30425 = stack[-1];
    goto v_30251;
v_30252:
    v_30424 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30253;
v_30254:
    goto v_30250;
v_30251:
    goto v_30252;
v_30253:
    return cons(v_30425, v_30424);
v_30237:
    v_30424 = stack[-1];
    v_30424 = qcar(v_30424);
    v_30424 = qcar(v_30424);
    stack[-2] = v_30424;
    goto v_30274;
v_30270:
    v_30424 = stack[-2];
    v_30425 = qcar(v_30424);
    goto v_30271;
v_30272:
    v_30424 = elt(env, 1); // i
    goto v_30273;
v_30274:
    goto v_30270;
v_30271:
    goto v_30272;
v_30273:
    if (v_30425 == v_30424) goto v_30268;
    else goto v_30269;
v_30268:
    goto v_30283;
v_30279:
    v_30425 = elt(env, 2); // (sqrt -1)
    goto v_30280;
v_30281:
    v_30424 = stack[-2];
    v_30424 = qcdr(v_30424);
    goto v_30282;
v_30283:
    goto v_30279;
v_30280:
    goto v_30281;
v_30282:
    fn = elt(env, 4); // mksp
    v_30424 = (*qfn2(fn))(fn, v_30425, v_30424);
    env = stack[-3];
    stack[-2] = v_30424;
    goto v_30267;
v_30269:
v_30267:
    goto v_30300;
v_30296:
    v_30424 = stack[-2];
    v_30425 = qcar(v_30424);
    goto v_30297;
v_30298:
    v_30424 = elt(env, 3); // sqrt
    goto v_30299;
v_30300:
    goto v_30296;
v_30297:
    goto v_30298;
v_30299:
    if (!consp(v_30425)) goto v_30294;
    v_30425 = qcar(v_30425);
    if (v_30425 == v_30424) goto v_30293;
    else goto v_30294;
v_30293:
    v_30424 = stack[-2];
    v_30424 = qcdr(v_30424);
    v_30424 = Lonep(nil, v_30424);
    env = stack[-3];
    v_30424 = (v_30424 == nil ? lisp_true : nil);
    goto v_30292;
v_30294:
    v_30424 = nil;
    goto v_30292;
    v_30424 = nil;
v_30292:
    if (v_30424 == nil) goto v_30290;
    goto v_30319;
v_30315:
    v_30424 = stack[-2];
    v_30425 = qcdr(v_30424);
    goto v_30316;
v_30317:
    v_30424 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_30318;
v_30319:
    goto v_30315;
v_30316:
    goto v_30317;
v_30318:
    v_30424 = Ldivide(nil, v_30425, v_30424);
    env = stack[-3];
    stack[0] = v_30424;
    goto v_30328;
v_30324:
    v_30424 = stack[-2];
    v_30424 = qcar(v_30424);
    v_30424 = qcdr(v_30424);
    v_30424 = qcar(v_30424);
    fn = elt(env, 5); // simp
    v_30425 = (*qfn1(fn))(fn, v_30424);
    env = stack[-3];
    goto v_30325;
v_30326:
    v_30424 = stack[0];
    v_30424 = qcar(v_30424);
    goto v_30327;
v_30328:
    goto v_30324;
v_30325:
    goto v_30326;
v_30327:
    fn = elt(env, 6); // exptsq
    v_30424 = (*qfn2(fn))(fn, v_30425, v_30424);
    env = stack[-3];
    v_30426 = v_30424;
    goto v_30344;
v_30340:
    v_30424 = stack[0];
    v_30425 = qcdr(v_30424);
    goto v_30341;
v_30342:
    v_30424 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30343;
v_30344:
    goto v_30340;
v_30341:
    goto v_30342;
v_30343:
    if (v_30425 == v_30424) goto v_30339;
    goto v_30353;
v_30349:
    stack[0] = v_30426;
    goto v_30350;
v_30351:
    goto v_30362;
v_30356:
    goto v_30368;
v_30364:
    goto v_30374;
v_30370:
    v_30424 = stack[-2];
    v_30425 = qcar(v_30424);
    goto v_30371;
v_30372:
    v_30424 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30373;
v_30374:
    goto v_30370;
v_30371:
    goto v_30372;
v_30373:
    fn = elt(env, 4); // mksp
    v_30425 = (*qfn2(fn))(fn, v_30425, v_30424);
    env = stack[-3];
    goto v_30365;
v_30366:
    v_30424 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30367;
v_30368:
    goto v_30364;
v_30365:
    goto v_30366;
v_30367:
    v_30426 = cons(v_30425, v_30424);
    env = stack[-3];
    goto v_30357;
v_30358:
    v_30425 = nil;
    goto v_30359;
v_30360:
    v_30424 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30361;
v_30362:
    goto v_30356;
v_30357:
    goto v_30358;
v_30359:
    goto v_30360;
v_30361:
    v_30424 = acons(v_30426, v_30425, v_30424);
    env = stack[-3];
    goto v_30352;
v_30353:
    goto v_30349;
v_30350:
    goto v_30351;
v_30352:
    fn = elt(env, 7); // multsq
    v_30424 = (*qfn2(fn))(fn, stack[0], v_30424);
    env = stack[-3];
    v_30426 = v_30424;
    goto v_30337;
v_30339:
v_30337:
    v_30424 = v_30426;
    fn = elt(env, 8); // tidysqrt
    v_30424 = (*qfn1(fn))(fn, v_30424);
    env = stack[-3];
    v_30426 = v_30424;
    goto v_30288;
v_30290:
    goto v_30392;
v_30386:
    goto v_30398;
v_30394:
    v_30425 = stack[-2];
    goto v_30395;
v_30396:
    v_30424 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30397;
v_30398:
    goto v_30394;
v_30395:
    goto v_30396;
v_30397:
    v_30426 = cons(v_30425, v_30424);
    env = stack[-3];
    goto v_30387;
v_30388:
    v_30425 = nil;
    goto v_30389;
v_30390:
    v_30424 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30391;
v_30392:
    goto v_30386;
v_30387:
    goto v_30388;
v_30389:
    goto v_30390;
v_30391:
    v_30424 = acons(v_30426, v_30425, v_30424);
    env = stack[-3];
    v_30426 = v_30424;
    goto v_30288;
v_30288:
    goto v_30408;
v_30404:
    stack[0] = v_30426;
    goto v_30405;
v_30406:
    v_30424 = stack[-1];
    v_30424 = qcar(v_30424);
    v_30424 = qcdr(v_30424);
    v_30424 = CC_tidysqrtf(elt(env, 0), v_30424);
    env = stack[-3];
    goto v_30407;
v_30408:
    goto v_30404;
v_30405:
    goto v_30406;
v_30407:
    fn = elt(env, 7); // multsq
    v_30424 = (*qfn2(fn))(fn, stack[0], v_30424);
    env = stack[-3];
    stack[-2] = v_30424;
    goto v_30419;
v_30415:
    stack[0] = stack[-2];
    goto v_30416;
v_30417:
    v_30424 = stack[-1];
    v_30424 = qcdr(v_30424);
    v_30424 = CC_tidysqrtf(elt(env, 0), v_30424);
    env = stack[-3];
    goto v_30418;
v_30419:
    goto v_30415;
v_30416:
    goto v_30417;
v_30418:
    {
        LispObject v_30430 = stack[0];
        fn = elt(env, 9); // addsq
        return (*qfn2(fn))(fn, v_30430, v_30424);
    }
    goto v_30235;
    v_30424 = nil;
v_30235:
    return onevalue(v_30424);
}



// Code for ofsf_smwrmknowl

static LispObject CC_ofsf_smwrmknowl(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30258, v_30259, v_30260;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30259 = v_30233;
    v_30260 = v_30232;
// end of prologue
    v_30258 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_30258 == nil) goto v_30238;
    goto v_30245;
v_30241:
    v_30258 = v_30260;
    goto v_30242;
v_30243:
    goto v_30244;
v_30245:
    goto v_30241;
v_30242:
    goto v_30243;
v_30244:
    {
        fn = elt(env, 2); // ofsf_susirmknowl
        return (*qfn2(fn))(fn, v_30258, v_30259);
    }
v_30238:
    goto v_30255;
v_30251:
    v_30258 = v_30260;
    goto v_30252;
v_30253:
    goto v_30254;
v_30255:
    goto v_30251;
v_30252:
    goto v_30253;
v_30254:
    {
        fn = elt(env, 3); // ofsf_smrmknowl
        return (*qfn2(fn))(fn, v_30258, v_30259);
    }
    v_30258 = nil;
    return onevalue(v_30258);
}



// Code for eval!-yetunknowntypeexpr

static LispObject CC_evalKyetunknowntypeexpr(LispObject env,
                         LispObject v_30232, LispObject v_30233)
{
    env = qenv(env);
    LispObject v_30389, v_30390;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30233,v_30232);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30232,v_30233);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_30233;
    stack[0] = v_30232;
// end of prologue
v_30231:
    v_30389 = stack[0];
    if (!consp(v_30389)) goto v_30237;
    else goto v_30238;
v_30237:
    v_30389 = stack[0];
    if (!symbolp(v_30389)) v_30389 = nil;
    else { v_30389 = qfastgets(v_30389);
           if (v_30389 != nil) { v_30389 = elt(v_30389, 4); // avalue
#ifdef RECORD_GET
             if (v_30389 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_30389 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_30389 == SPID_NOPROP) v_30389 = nil; }}
#endif
    v_30390 = v_30389;
    v_30389 = v_30390;
    if (v_30389 == nil) goto v_30246;
    goto v_30253;
v_30249:
    v_30389 = v_30390;
    v_30389 = qcdr(v_30389);
    v_30390 = qcar(v_30389);
    goto v_30250;
v_30251:
    v_30389 = stack[-4];
    goto v_30252;
v_30253:
    goto v_30249;
v_30250:
    goto v_30251;
v_30252:
    stack[0] = v_30390;
    stack[-4] = v_30389;
    goto v_30231;
v_30246:
    v_30389 = stack[0];
    goto v_30244;
    v_30389 = nil;
v_30244:
    goto v_30236;
v_30238:
    goto v_30271;
v_30267:
    v_30389 = stack[0];
    v_30390 = qcar(v_30389);
    goto v_30268;
v_30269:
    v_30389 = elt(env, 1); // !*sq
    goto v_30270;
v_30271:
    goto v_30267;
v_30268:
    goto v_30269;
v_30270:
    if (v_30390 == v_30389) goto v_30265;
    else goto v_30266;
v_30265:
    v_30389 = lisp_true;
    goto v_30264;
v_30266:
    v_30389 = stack[0];
    v_30389 = qcar(v_30389);
    if (!symbolp(v_30389)) v_30389 = nil;
    else { v_30389 = qfastgets(v_30389);
           if (v_30389 != nil) { v_30389 = elt(v_30389, 8); // dname
#ifdef RECORD_GET
             if (v_30389 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_30389 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_30389 == SPID_NOPROP) v_30389 = nil; }}
#endif
    if (v_30389 == nil) goto v_30280;
    else goto v_30279;
v_30280:
    goto v_30288;
v_30284:
    v_30389 = stack[0];
    v_30390 = qcar(v_30389);
    goto v_30285;
v_30286:
    v_30389 = elt(env, 2); // !:dn!:
    goto v_30287;
v_30288:
    goto v_30284;
v_30285:
    goto v_30286;
v_30287:
    v_30389 = (v_30390 == v_30389 ? lisp_true : nil);
v_30279:
    goto v_30264;
    v_30389 = nil;
v_30264:
    if (v_30389 == nil) goto v_30262;
    v_30389 = stack[0];
    goto v_30236;
v_30262:
    v_30389 = stack[0];
    v_30389 = qcar(v_30389);
    if (!symbolp(v_30389)) v_30389 = nil;
    else { v_30389 = qfastgets(v_30389);
           if (v_30389 != nil) { v_30389 = elt(v_30389, 45); // psopfn
#ifdef RECORD_GET
             if (v_30389 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v_30389 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v_30389 == SPID_NOPROP) v_30389 = nil; }}
#endif
    stack[-1] = v_30389;
    v_30389 = stack[-1];
    if (v_30389 == nil) goto v_30303;
    goto v_30311;
v_30307:
    v_30389 = stack[0];
    fn = elt(env, 4); // getrtype
    v_30390 = (*qfn1(fn))(fn, v_30389);
    env = stack[-6];
    goto v_30308;
v_30309:
    v_30389 = elt(env, 3); // yetunknowntype
    goto v_30310;
v_30311:
    goto v_30307;
v_30308:
    goto v_30309;
v_30310:
    if (v_30390 == v_30389) goto v_30306;
    else goto v_30303;
v_30306:
    goto v_30320;
v_30316:
    v_30390 = stack[-1];
    goto v_30317;
v_30318:
    v_30389 = stack[0];
    v_30389 = qcdr(v_30389);
    goto v_30319;
v_30320:
    goto v_30316;
v_30317:
    goto v_30318;
v_30319:
        return Lapply1(nil, v_30390, v_30389);
v_30303:
    goto v_30331;
v_30327:
    v_30389 = stack[0];
    stack[-5] = qcar(v_30389);
    goto v_30328;
v_30329:
    v_30389 = stack[0];
    v_30389 = qcdr(v_30389);
    stack[-3] = v_30389;
    v_30389 = stack[-3];
    if (v_30389 == nil) goto v_30344;
    else goto v_30345;
v_30344:
    v_30389 = nil;
    goto v_30338;
v_30345:
    v_30389 = stack[-3];
    v_30389 = qcar(v_30389);
    goto v_30357;
v_30353:
    v_30390 = v_30389;
    goto v_30354;
v_30355:
    v_30389 = stack[-4];
    goto v_30356;
v_30357:
    goto v_30353;
v_30354:
    goto v_30355;
v_30356:
    v_30389 = CC_evalKyetunknowntypeexpr(elt(env, 0), v_30390, v_30389);
    env = stack[-6];
    v_30389 = ncons(v_30389);
    env = stack[-6];
    stack[-1] = v_30389;
    stack[-2] = v_30389;
v_30339:
    v_30389 = stack[-3];
    v_30389 = qcdr(v_30389);
    stack[-3] = v_30389;
    v_30389 = stack[-3];
    if (v_30389 == nil) goto v_30364;
    else goto v_30365;
v_30364:
    v_30389 = stack[-2];
    goto v_30338;
v_30365:
    goto v_30373;
v_30369:
    stack[0] = stack[-1];
    goto v_30370;
v_30371:
    v_30389 = stack[-3];
    v_30389 = qcar(v_30389);
    goto v_30384;
v_30380:
    v_30390 = v_30389;
    goto v_30381;
v_30382:
    v_30389 = stack[-4];
    goto v_30383;
v_30384:
    goto v_30380;
v_30381:
    goto v_30382;
v_30383:
    v_30389 = CC_evalKyetunknowntypeexpr(elt(env, 0), v_30390, v_30389);
    env = stack[-6];
    v_30389 = ncons(v_30389);
    env = stack[-6];
    goto v_30372;
v_30373:
    goto v_30369;
v_30370:
    goto v_30371;
v_30372:
    v_30389 = Lrplacd(nil, stack[0], v_30389);
    env = stack[-6];
    v_30389 = stack[-1];
    v_30389 = qcdr(v_30389);
    stack[-1] = v_30389;
    goto v_30339;
v_30338:
    goto v_30330;
v_30331:
    goto v_30327;
v_30328:
    goto v_30329;
v_30330:
    {
        LispObject v_30397 = stack[-5];
        return cons(v_30397, v_30389);
    }
    v_30389 = nil;
    goto v_30236;
    v_30389 = nil;
v_30236:
    return onevalue(v_30389);
}



setup_type const u51_setup[] =
{
    {"isimp2",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_isimp2},
    {"ofsf_sminsert1",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_sminsert1},
    {"get*order",               CC_getHorder,   TOO_MANY_1,    WRONG_NO_1},
    {"qqe_length-graph-marked", CC_qqe_lengthKgraphKmarked,TOO_MANY_1,WRONG_NO_1},
    {"pasf_negateat",           CC_pasf_negateat,TOO_MANY_1,   WRONG_NO_1},
    {"ofsf_boundchk",           TOO_FEW_2,      CC_ofsf_boundchk,WRONG_NO_2},
    {"ldf-deg",                 TOO_FEW_2,      CC_ldfKdeg,    WRONG_NO_2},
    {"sprow_dim",               CC_sprow_dim,   TOO_MANY_1,    WRONG_NO_1},
    {"groebmakepair",           TOO_FEW_2,      CC_groebmakepair,WRONG_NO_2},
    {"groebreduceonestepint",   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_groebreduceonestepint},
    {"mkunarywedge",            CC_mkunarywedge,TOO_MANY_1,    WRONG_NO_1},
    {"chksymmetries&sub1",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_chksymmetriesGsub1},
    {"df-chain-rule",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dfKchainKrule},
    {"pst_d1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pst_d1},
    {"general-difference-mod-p",TOO_FEW_2,      CC_generalKdifferenceKmodKp,WRONG_NO_2},
    {"smemberl",                TOO_FEW_2,      CC_smemberl,   WRONG_NO_2},
    {"updkorder",               CC_updkorder,   TOO_MANY_1,    WRONG_NO_1},
    {"qroundup",                TOO_FEW_2,      CC_qroundup,   WRONG_NO_2},
    {"constructinvolutivebasis",TOO_FEW_2,      CC_constructinvolutivebasis,WRONG_NO_2},
    {"ofsf_canegrel",           TOO_FEW_2,      CC_ofsf_canegrel,WRONG_NO_2},
    {"talp_cocc",               TOO_FEW_2,      CC_talp_cocc,  WRONG_NO_2},
    {"pasf_smordtable2",        TOO_FEW_2,      CC_pasf_smordtable2,WRONG_NO_2},
    {"ldf-sep-var",             CC_ldfKsepKvar, TOO_MANY_1,    WRONG_NO_1},
    {"dipreplus",               CC_dipreplus,   TOO_MANY_1,    WRONG_NO_1},
    {"make_wedge_pair",         TOO_FEW_2,      CC_make_wedge_pair,WRONG_NO_2},
    {"gbftimes",                TOO_FEW_2,      CC_gbftimes,   WRONG_NO_2},
    {"gpexpp",                  CC_gpexpp,      TOO_MANY_1,    WRONG_NO_1},
    {"positive-powp",           CC_positiveKpowp,TOO_MANY_1,   WRONG_NO_1},
    {"ofsf_smmkatl-and",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smmkatlKand},
    {"xadd*",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xaddH},
    {"*multsq",                 TOO_FEW_2,      CC_Hmultsq,    WRONG_NO_2},
    {"taymindegreel",           TOO_FEW_2,      CC_taymindegreel,WRONG_NO_2},
    {"cl_susimkatl",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_susimkatl},
    {"sfto_kexp",               TOO_FEW_2,      CC_sfto_kexp,  WRONG_NO_2},
    {"acfsf_0mk2",              TOO_FEW_2,      CC_acfsf_0mk2, WRONG_NO_2},
    {"latexprint",              CC_latexprint,  TOO_MANY_1,    WRONG_NO_1},
    {"decimal2internal",        TOO_FEW_2,      CC_decimal2internal,WRONG_NO_2},
    {"is_buble",                TOO_FEW_2,      CC_is_buble,   WRONG_NO_2},
    {"tidysqrtf",               CC_tidysqrtf,   TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_smwrmknowl",         TOO_FEW_2,      CC_ofsf_smwrmknowl,WRONG_NO_2},
    {"eval-yetunknowntypeexpr", TOO_FEW_2,      CC_evalKyetunknowntypeexpr,WRONG_NO_2},
    {NULL, (one_args *)"u51", (two_args *)"10810 2608372 2526461", 0}
};

// end of generated code
