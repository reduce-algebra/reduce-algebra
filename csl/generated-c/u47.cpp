
// $destdir/u47.c        Machine generated C code

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



// Code for zfactor1

static LispObject CC_zfactor1(LispObject env,
                         LispObject v_27554, LispObject v_27555)
{
    env = qenv(env);
    LispObject v_27754, v_27755, v_27756;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27554,v_27555);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_27555;
    stack[-4] = v_27554;
// end of prologue
    stack[0] = nil;
v_27560:
    goto v_27570;
v_27566:
    v_27755 = stack[-4];
    goto v_27567;
v_27568:
    v_27754 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27569;
v_27570:
    goto v_27566;
v_27567:
    goto v_27568;
v_27569:
    v_27754 = (LispObject)lessp2(v_27755, v_27754);
    v_27754 = v_27754 ? lisp_true : nil;
    env = stack[-6];
    if (v_27754 == nil) goto v_27564;
    goto v_27580;
v_27574:
    v_27756 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_27575;
v_27576:
    v_27755 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27577;
v_27578:
    v_27754 = stack[0];
    goto v_27579;
v_27580:
    goto v_27574;
v_27575:
    goto v_27576;
v_27577:
    goto v_27578;
v_27579:
    v_27754 = acons(v_27756, v_27755, v_27754);
    env = stack[-6];
    stack[0] = v_27754;
    v_27754 = stack[-4];
    v_27754 = negate(v_27754);
    env = stack[-6];
    stack[-4] = v_27754;
    goto v_27560;
v_27564:
    goto v_27593;
v_27589:
    v_27755 = stack[-4];
    goto v_27590;
v_27591:
    v_27754 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_27592;
v_27593:
    goto v_27589;
v_27590:
    goto v_27591;
v_27592:
    v_27754 = (LispObject)lessp2(v_27755, v_27754);
    v_27754 = v_27754 ? lisp_true : nil;
    env = stack[-6];
    if (v_27754 == nil) goto v_27587;
    goto v_27601;
v_27597:
    goto v_27598;
v_27599:
    goto v_27609;
v_27605:
    v_27755 = stack[-4];
    goto v_27606;
v_27607:
    v_27754 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27608;
v_27609:
    goto v_27605;
v_27606:
    goto v_27607;
v_27608:
    v_27754 = cons(v_27755, v_27754);
    env = stack[-6];
    v_27754 = ncons(v_27754);
    env = stack[-6];
    goto v_27600;
v_27601:
    goto v_27597;
v_27598:
    goto v_27599;
v_27600:
    {
        LispObject v_27763 = stack[0];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_27763, v_27754);
    }
v_27587:
    goto v_27619;
v_27615:
    stack[-5] = stack[0];
    goto v_27616;
v_27617:
    v_27754 = qvalue(elt(env, 1)); // !*primelist!*
    stack[-2] = v_27754;
    v_27754 = nil;
    stack[-1] = v_27754;
v_27631:
    v_27754 = stack[-2];
    if (v_27754 == nil) goto v_27634;
    else goto v_27635;
v_27634:
    goto v_27630;
v_27635:
    v_27754 = stack[-2];
    v_27754 = qcar(v_27754);
    stack[0] = v_27754;
    v_27754 = stack[-2];
    v_27754 = qcdr(v_27754);
    stack[-2] = v_27754;
v_27644:
    goto v_27653;
v_27649:
    goto v_27659;
v_27655:
    v_27755 = stack[-4];
    goto v_27656;
v_27657:
    v_27754 = stack[0];
    goto v_27658;
v_27659:
    goto v_27655;
v_27656:
    goto v_27657;
v_27658:
    v_27754 = Ldivide(nil, v_27755, v_27754);
    env = stack[-6];
    v_27756 = v_27754;
    v_27755 = qcdr(v_27754);
    goto v_27650;
v_27651:
    v_27754 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27652;
v_27653:
    goto v_27649;
v_27650:
    goto v_27651;
v_27652:
    if (v_27755 == v_27754) goto v_27648;
    goto v_27643;
v_27648:
    v_27754 = v_27756;
    v_27754 = qcar(v_27754);
    stack[-4] = v_27754;
    goto v_27672;
v_27668:
    v_27755 = stack[0];
    goto v_27669;
v_27670:
    v_27754 = stack[-1];
    goto v_27671;
v_27672:
    goto v_27668;
v_27669:
    goto v_27670;
v_27671:
    fn = elt(env, 3); // add!-factor
    v_27754 = (*qfn2(fn))(fn, v_27755, v_27754);
    env = stack[-6];
    stack[-1] = v_27754;
    goto v_27644;
v_27643:
    goto v_27687;
v_27683:
    v_27755 = stack[-4];
    goto v_27684;
v_27685:
    v_27754 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27686;
v_27687:
    goto v_27683;
v_27684:
    goto v_27685;
v_27686:
    if (v_27755 == v_27754) goto v_27682;
    goto v_27695;
v_27691:
    goto v_27701;
v_27697:
    v_27755 = stack[0];
    goto v_27698;
v_27699:
    v_27754 = stack[0];
    goto v_27700;
v_27701:
    goto v_27697;
v_27698:
    goto v_27699;
v_27700:
    v_27755 = times2(v_27755, v_27754);
    env = stack[-6];
    goto v_27692;
v_27693:
    v_27754 = stack[-4];
    goto v_27694;
v_27695:
    goto v_27691;
v_27692:
    goto v_27693;
v_27694:
    v_27754 = (LispObject)greaterp2(v_27755, v_27754);
    v_27754 = v_27754 ? lisp_true : nil;
    env = stack[-6];
    goto v_27680;
v_27682:
    v_27754 = nil;
    goto v_27680;
    v_27754 = nil;
v_27680:
    if (v_27754 == nil) goto v_27678;
    v_27754 = nil;
    stack[-2] = v_27754;
    goto v_27714;
v_27710:
    v_27755 = stack[-4];
    goto v_27711;
v_27712:
    v_27754 = stack[-1];
    goto v_27713;
v_27714:
    goto v_27710;
v_27711:
    goto v_27712;
v_27713:
    fn = elt(env, 3); // add!-factor
    v_27754 = (*qfn2(fn))(fn, v_27755, v_27754);
    env = stack[-6];
    stack[-1] = v_27754;
    v_27754 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_27754;
    goto v_27676;
v_27678:
v_27676:
    goto v_27631;
v_27630:
    goto v_27726;
v_27722:
    v_27755 = stack[-4];
    goto v_27723;
v_27724:
    v_27754 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27725;
v_27726:
    goto v_27722;
v_27723:
    goto v_27724;
v_27725:
    if (v_27755 == v_27754) goto v_27720;
    else goto v_27721;
v_27720:
    v_27754 = stack[-1];
    goto v_27719;
v_27721:
    v_27754 = stack[-3];
    if (v_27754 == nil) goto v_27730;
    else goto v_27731;
v_27730:
    goto v_27740;
v_27734:
    v_27756 = stack[-4];
    goto v_27735;
v_27736:
    v_27755 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27737;
v_27738:
    v_27754 = stack[-1];
    goto v_27739;
v_27740:
    goto v_27734;
v_27735:
    goto v_27736;
v_27737:
    goto v_27738;
v_27739:
    v_27754 = acons(v_27756, v_27755, v_27754);
    env = stack[-6];
    goto v_27719;
v_27731:
    goto v_27751;
v_27747:
    v_27755 = stack[-4];
    goto v_27748;
v_27749:
    v_27754 = stack[-1];
    goto v_27750;
v_27751:
    goto v_27747;
v_27748:
    goto v_27749;
v_27750:
    fn = elt(env, 4); // mcfactor!*
    v_27754 = (*qfn2(fn))(fn, v_27755, v_27754);
    env = stack[-6];
    goto v_27719;
    v_27754 = nil;
v_27719:
    goto v_27618;
v_27619:
    goto v_27615;
v_27616:
    goto v_27617;
v_27618:
    {
        LispObject v_27764 = stack[-5];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_27764, v_27754);
    }
    v_27754 = nil;
    return onevalue(v_27754);
}



// Code for noncomfree

static LispObject CC_noncomfree(LispObject env,
                         LispObject v_27554)
{
    env = qenv(env);
    LispObject v_27587;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27554);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27554;
// end of prologue
v_27553:
    v_27587 = stack[0];
    if (symbolp(v_27587)) goto v_27558;
    else goto v_27559;
v_27558:
    v_27587 = stack[0];
    if (!symbolp(v_27587)) v_27587 = nil;
    else { v_27587 = qfastgets(v_27587);
           if (v_27587 != nil) { v_27587 = elt(v_27587, 0); // noncom
#ifdef RECORD_GET
             if (v_27587 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_27587 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_27587 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_27587 == SPID_NOPROP) v_27587 = nil; else v_27587 = lisp_true; }}
#endif
    v_27587 = (v_27587 == nil ? lisp_true : nil);
    goto v_27557;
v_27559:
    v_27587 = stack[0];
    if (!consp(v_27587)) goto v_27568;
    else goto v_27569;
v_27568:
    v_27587 = lisp_true;
    goto v_27567;
v_27569:
    v_27587 = stack[0];
    v_27587 = qcar(v_27587);
    v_27587 = CC_noncomfree(elt(env, 0), v_27587);
    env = stack[-1];
    if (v_27587 == nil) goto v_27576;
    else goto v_27577;
v_27576:
    v_27587 = nil;
    goto v_27575;
v_27577:
    v_27587 = stack[0];
    v_27587 = qcdr(v_27587);
    stack[0] = v_27587;
    goto v_27553;
    v_27587 = nil;
v_27575:
    goto v_27567;
    v_27587 = nil;
v_27567:
    goto v_27557;
    v_27587 = nil;
v_27557:
    return onevalue(v_27587);
}



// Code for tayexp!-max2

static LispObject CC_tayexpKmax2(LispObject env,
                         LispObject v_27554, LispObject v_27555)
{
    env = qenv(env);
    LispObject v_27573, v_27574;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27554,v_27555);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27555;
    stack[-1] = v_27554;
// end of prologue
    goto v_27566;
v_27562:
    v_27574 = stack[-1];
    goto v_27563;
v_27564:
    v_27573 = stack[0];
    goto v_27565;
v_27566:
    goto v_27562;
v_27563:
    goto v_27564;
v_27565:
    fn = elt(env, 1); // tayexp!-lessp
    v_27573 = (*qfn2(fn))(fn, v_27574, v_27573);
    if (v_27573 == nil) goto v_27560;
    v_27573 = stack[0];
    goto v_27558;
v_27560:
    v_27573 = stack[-1];
    goto v_27558;
    v_27573 = nil;
v_27558:
    return onevalue(v_27573);
}



// Code for cl_replace!-varl

static LispObject CC_cl_replaceKvarl(LispObject env,
                         LispObject v_27554)
{
    env = qenv(env);
    LispObject v_27661, v_27662, v_27663;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27554);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_27661 = v_27554;
// end of prologue
    stack[0] = nil;
    fn = elt(env, 1); // cl_varl1
    v_27661 = (*qfn1(fn))(fn, v_27661);
    env = stack[-4];
    v_27662 = v_27661;
    v_27661 = v_27662;
    v_27661 = qcar(v_27661);
    stack[-3] = v_27661;
    v_27661 = v_27662;
    v_27661 = qcdr(v_27661);
    stack[-2] = v_27661;
    goto v_27578;
v_27574:
    v_27662 = stack[-3];
    goto v_27575;
v_27576:
    v_27661 = stack[-2];
    goto v_27577;
v_27578:
    goto v_27574;
v_27575:
    goto v_27576;
v_27577:
    v_27661 = Lappend(nil, v_27662, v_27661);
    env = stack[-4];
    stack[-1] = v_27661;
v_27583:
    v_27661 = stack[-2];
    if (v_27661 == nil) goto v_27586;
    else goto v_27587;
v_27586:
    goto v_27582;
v_27587:
    v_27661 = stack[-2];
    v_27661 = qcar(v_27661);
    v_27662 = v_27661;
    v_27661 = stack[-2];
    v_27661 = qcdr(v_27661);
    stack[-2] = v_27661;
    v_27661 = v_27662;
    v_27663 = v_27661;
    goto v_27607;
v_27603:
    v_27662 = v_27663;
    goto v_27604;
v_27605:
    v_27661 = stack[-3];
    goto v_27606;
v_27607:
    goto v_27603;
v_27604:
    goto v_27605;
v_27606:
    v_27661 = Lmemq(nil, v_27662, v_27661);
    if (v_27661 == nil) goto v_27602;
    goto v_27619;
v_27615:
    v_27662 = v_27663;
    goto v_27616;
v_27617:
    v_27661 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27618;
v_27619:
    goto v_27615;
v_27616:
    goto v_27617;
v_27618:
    v_27661 = cons(v_27662, v_27661);
    env = stack[-4];
    goto v_27627;
v_27623:
    v_27662 = v_27661;
    goto v_27624;
v_27625:
    v_27661 = stack[0];
    goto v_27626;
v_27627:
    goto v_27623;
v_27624:
    goto v_27625;
v_27626:
    v_27661 = cons(v_27662, v_27661);
    env = stack[-4];
    stack[0] = v_27661;
    goto v_27600;
v_27602:
    goto v_27641;
v_27637:
    v_27662 = v_27663;
    goto v_27638;
v_27639:
    v_27661 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27640;
v_27641:
    goto v_27637;
v_27638:
    goto v_27639;
v_27640:
    v_27661 = cons(v_27662, v_27661);
    env = stack[-4];
    goto v_27649;
v_27645:
    v_27662 = v_27661;
    goto v_27646;
v_27647:
    v_27661 = stack[0];
    goto v_27648;
v_27649:
    goto v_27645;
v_27646:
    goto v_27647;
v_27648:
    v_27661 = cons(v_27662, v_27661);
    env = stack[-4];
    stack[0] = v_27661;
    goto v_27600;
v_27600:
    goto v_27583;
v_27582:
    goto v_27658;
v_27654:
    v_27662 = stack[-1];
    goto v_27655;
v_27656:
    v_27661 = stack[0];
    goto v_27657;
v_27658:
    goto v_27654;
v_27655:
    goto v_27656;
v_27657:
    return cons(v_27662, v_27661);
    return onevalue(v_27661);
}



// Code for qqe_simplqneq

static LispObject CC_qqe_simplqneq(LispObject env,
                         LispObject v_27554, LispObject v_27555)
{
    env = qenv(env);
    LispObject v_27628, v_27629, v_27630;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27554,v_27555);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_27629 = v_27555;
    v_27628 = v_27554;
// end of prologue
    v_27629 = v_27628;
    v_27629 = qcdr(v_27629);
    v_27629 = qcar(v_27629);
    v_27628 = qcdr(v_27628);
    v_27628 = qcdr(v_27628);
    v_27628 = qcar(v_27628);
    goto v_27577;
v_27573:
    goto v_27585;
v_27579:
    v_27630 = elt(env, 1); // qequal
    goto v_27580;
v_27581:
    goto v_27582;
v_27583:
    goto v_27584;
v_27585:
    goto v_27579;
v_27580:
    goto v_27581;
v_27582:
    goto v_27583;
v_27584:
    fn = elt(env, 5); // qqe_mk2
    v_27629 = (*qfnn(fn))(fn, 3, v_27630, v_27629, v_27628);
    env = stack[-3];
    goto v_27574;
v_27575:
    v_27628 = nil;
    goto v_27576;
v_27577:
    goto v_27573;
v_27574:
    goto v_27575;
v_27576:
    fn = elt(env, 6); // qqe_simplqequal
    v_27628 = (*qfn2(fn))(fn, v_27629, v_27628);
    env = stack[-3];
    stack[-2] = v_27628;
    goto v_27598;
v_27594:
    v_27629 = stack[-2];
    goto v_27595;
v_27596:
    v_27628 = elt(env, 2); // true
    goto v_27597;
v_27598:
    goto v_27594;
v_27595:
    goto v_27596;
v_27597:
    if (v_27629 == v_27628) goto v_27592;
    else goto v_27593;
v_27592:
    v_27628 = elt(env, 3); // false
    goto v_27591;
v_27593:
    goto v_27608;
v_27604:
    v_27629 = stack[-2];
    goto v_27605;
v_27606:
    v_27628 = elt(env, 3); // false
    goto v_27607;
v_27608:
    goto v_27604;
v_27605:
    goto v_27606;
v_27607:
    if (v_27629 == v_27628) goto v_27602;
    else goto v_27603;
v_27602:
    v_27628 = elt(env, 2); // true
    goto v_27591;
v_27603:
    goto v_27621;
v_27615:
    stack[-1] = elt(env, 4); // qneq
    goto v_27616;
v_27617:
    v_27628 = stack[-2];
    fn = elt(env, 7); // qqe_arg2l
    stack[0] = (*qfn1(fn))(fn, v_27628);
    env = stack[-3];
    goto v_27618;
v_27619:
    v_27628 = stack[-2];
    fn = elt(env, 8); // qqe_arg2r
    v_27628 = (*qfn1(fn))(fn, v_27628);
    env = stack[-3];
    goto v_27620;
v_27621:
    goto v_27615;
v_27616:
    goto v_27617;
v_27618:
    goto v_27619;
v_27620:
    fn = elt(env, 5); // qqe_mk2
    v_27628 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_27628);
    goto v_27591;
v_27591:
    return onevalue(v_27628);
}



// Code for cnml

static LispObject CC_cnml(LispObject env,
                         LispObject v_27554)
{
    env = qenv(env);
    LispObject v_27575, v_27576;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27554);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27554;
// end of prologue
    v_27575 = elt(env, 1); // "<cn"
    fn = elt(env, 4); // printout
    v_27575 = (*qfn1(fn))(fn, v_27575);
    env = stack[-1];
    goto v_27565;
v_27561:
    v_27575 = stack[0];
    v_27576 = qcar(v_27575);
    goto v_27562;
v_27563:
    v_27575 = elt(env, 2); // ""
    goto v_27564;
v_27565:
    goto v_27561;
v_27562:
    goto v_27563;
v_27564:
    fn = elt(env, 5); // attributesml
    v_27575 = (*qfn2(fn))(fn, v_27576, v_27575);
    env = stack[-1];
    v_27575 = stack[0];
    v_27575 = qcdr(v_27575);
    v_27575 = qcar(v_27575);
    v_27575 = Lprinc(nil, v_27575);
    env = stack[-1];
    v_27575 = elt(env, 3); // "</cn>"
    v_27575 = Lprinc(nil, v_27575);
    v_27575 = nil;
    return onevalue(v_27575);
}



// Code for d2int

static LispObject CC_d2int(LispObject env,
                         LispObject v_27554)
{
    env = qenv(env);
    LispObject v_27638, v_27639, v_27640;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27554);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_27639 = v_27554;
// end of prologue
    goto v_27564;
v_27560:
    v_27638 = v_27639;
    v_27640 = qcdr(v_27638);
    goto v_27561;
v_27562:
    v_27638 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27563;
v_27564:
    goto v_27560;
v_27561:
    goto v_27562;
v_27563:
    if (v_27640 == v_27638) goto v_27559;
    v_27638 = nil;
    goto v_27557;
v_27559:
    v_27638 = v_27639;
    v_27638 = qcar(v_27638);
    v_27639 = v_27638;
    if (is_number(v_27638)) goto v_27569;
    else goto v_27570;
v_27569:
    v_27638 = v_27639;
    goto v_27557;
v_27570:
    v_27638 = v_27639;
    if (!consp(v_27638)) goto v_27582;
    else goto v_27583;
v_27582:
    v_27638 = lisp_true;
    goto v_27581;
v_27583:
    v_27638 = v_27639;
    v_27638 = qcar(v_27638);
    v_27638 = (consp(v_27638) ? nil : lisp_true);
    goto v_27581;
    v_27638 = nil;
v_27581:
    if (v_27638 == nil) goto v_27578;
    else goto v_27579;
v_27578:
    v_27638 = lisp_true;
    goto v_27577;
v_27579:
    goto v_27598;
v_27594:
    v_27638 = v_27639;
    v_27640 = qcar(v_27638);
    goto v_27595;
v_27596:
    v_27638 = elt(env, 1); // !:rd!:
    goto v_27597;
v_27598:
    goto v_27594;
v_27595:
    goto v_27596;
v_27597:
    v_27638 = (v_27640 == v_27638 ? lisp_true : nil);
    v_27638 = (v_27638 == nil ? lisp_true : nil);
    goto v_27577;
    v_27638 = nil;
v_27577:
    if (v_27638 == nil) goto v_27575;
    v_27638 = nil;
    goto v_27557;
v_27575:
    v_27638 = v_27639;
    v_27638 = qcdr(v_27638);
    stack[-1] = v_27638;
    v_27638 = stack[-1];
    v_27638 = Ltruncate(nil, v_27638);
    env = stack[-2];
    stack[0] = v_27638;
    goto v_27622;
v_27618:
    goto v_27629;
v_27625:
    v_27638 = stack[0];
    v_27639 = Lfloat(nil, v_27638);
    env = stack[-2];
    goto v_27626;
v_27627:
    v_27638 = stack[-1];
    goto v_27628;
v_27629:
    goto v_27625;
v_27626:
    goto v_27627;
v_27628:
    v_27638 = difference2(v_27639, v_27638);
    env = stack[-2];
    v_27639 = Labsval(nil, v_27638);
    env = stack[-2];
    goto v_27619;
v_27620:
    v_27638 = qvalue(elt(env, 2)); // !!fleps1
    goto v_27621;
v_27622:
    goto v_27618;
v_27619:
    goto v_27620;
v_27621:
    v_27638 = (LispObject)lessp2(v_27639, v_27638);
    v_27638 = v_27638 ? lisp_true : nil;
    if (v_27638 == nil) goto v_27616;
    v_27638 = stack[0];
    goto v_27614;
v_27616:
    v_27638 = nil;
    goto v_27614;
    v_27638 = nil;
v_27614:
    goto v_27557;
    v_27638 = nil;
v_27557:
    return onevalue(v_27638);
}



// Code for tchscheme2

static LispObject CC_tchscheme2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27582, v_27583;
    LispObject fn;
    argcheck(nargs, 0, "tchscheme2");
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
    v_27582 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_27582;
v_27560:
    goto v_27572;
v_27568:
    v_27583 = qvalue(elt(env, 1)); // rowmax
    goto v_27569;
v_27570:
    v_27582 = stack[0];
    goto v_27571;
v_27572:
    goto v_27568;
v_27569:
    goto v_27570;
v_27571:
    v_27582 = difference2(v_27583, v_27582);
    env = stack[-1];
    v_27582 = Lminusp(nil, v_27582);
    env = stack[-1];
    if (v_27582 == nil) goto v_27565;
    goto v_27559;
v_27565:
    v_27582 = stack[0];
    fn = elt(env, 2); // removechild
    v_27582 = (*qfn1(fn))(fn, v_27582);
    env = stack[-1];
    v_27582 = stack[0];
    fn = elt(env, 3); // to!*scheme
    v_27582 = (*qfn1(fn))(fn, v_27582);
    env = stack[-1];
    v_27582 = stack[0];
    v_27582 = add1(v_27582);
    env = stack[-1];
    stack[0] = v_27582;
    goto v_27560;
v_27559:
    v_27582 = nil;
    return onevalue(v_27582);
}



// Code for sroot1

static LispObject CC_sroot1(LispObject env,
                         LispObject v_27554, LispObject v_27555)
{
    env = qenv(env);
    LispObject v_27739, v_27740, v_27741, v_27742;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27554,v_27555);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_27555;
    stack[-3] = v_27554;
// end of prologue
// Binding freevars
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-5, 1, -2);
    qvalue(elt(env, 1)) = nil; // freevars
// Binding substitution
// FLUIDBIND: reloadenv=5 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 2, -1);
    qvalue(elt(env, 2)) = nil; // substitution
    goto v_27575;
v_27571:
    v_27740 = qvalue(elt(env, 3)); // rpt
    goto v_27572;
v_27573:
    v_27739 = elt(env, 4); // inf
    goto v_27574;
v_27575:
    goto v_27571;
v_27572:
    goto v_27573;
v_27574:
    if (v_27740 == v_27739) goto v_27570;
    goto v_27583;
v_27579:
    v_27740 = qvalue(elt(env, 3)); // rpt
    goto v_27580;
v_27581:
    v_27739 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27582;
v_27583:
    goto v_27579;
v_27580:
    goto v_27581;
v_27582:
    v_27739 = (LispObject)lesseq2(v_27740, v_27739);
    v_27739 = v_27739 ? lisp_true : nil;
    env = stack[-5];
    goto v_27568;
v_27570:
    v_27739 = nil;
    goto v_27568;
    v_27739 = nil;
v_27568:
    if (v_27739 == nil) goto v_27566;
    else goto v_27564;
v_27566:
    v_27739 = stack[-3];
    if (!consp(v_27739)) goto v_27592;
    else goto v_27593;
v_27592:
    v_27739 = lisp_true;
    goto v_27591;
v_27593:
    goto v_27603;
v_27599:
    v_27739 = stack[-3];
    v_27740 = qcar(v_27739);
    goto v_27600;
v_27601:
    v_27739 = stack[0];
    v_27739 = qcdr(v_27739);
    v_27739 = qcar(v_27739);
    v_27739 = qcar(v_27739);
    goto v_27602;
v_27603:
    goto v_27599;
v_27600:
    goto v_27601;
v_27602:
    v_27739 = Lneq(nil, v_27740, v_27739);
    env = stack[-5];
    goto v_27591;
    v_27739 = nil;
v_27591:
    if (v_27739 == nil) goto v_27589;
    else goto v_27564;
v_27589:
    goto v_27565;
v_27564:
    v_27739 = stack[-3];
    goto v_27561;
v_27565:
    goto v_27616;
v_27612:
    v_27739 = stack[0];
    v_27739 = qcdr(v_27739);
    v_27739 = qcar(v_27739);
    fn = elt(env, 10); // findnewvars
    v_27740 = (*qfn1(fn))(fn, v_27739);
    env = stack[-5];
    goto v_27613;
v_27614:
    v_27739 = nil;
    goto v_27615;
v_27616:
    goto v_27612;
v_27613:
    goto v_27614;
v_27615:
    fn = elt(env, 11); // union
    v_27739 = (*qfn2(fn))(fn, v_27740, v_27739);
    env = stack[-5];
    qvalue(elt(env, 1)) = v_27739; // freevars
    v_27739 = stack[0];
    v_27739 = qcdr(v_27739);
    v_27739 = qcdr(v_27739);
    v_27739 = qcar(v_27739);
    qvalue(elt(env, 2)) = v_27739; // substitution
    v_27739 = qvalue(elt(env, 1)); // freevars
    stack[-4] = v_27739;
v_27629:
    v_27739 = stack[-4];
    if (v_27739 == nil) goto v_27633;
    else goto v_27634;
v_27633:
    goto v_27628;
v_27634:
    v_27739 = stack[-4];
    v_27739 = qcar(v_27739);
    fn = elt(env, 12); // newenv
    v_27739 = (*qfn1(fn))(fn, v_27739);
    env = stack[-5];
    v_27739 = stack[-4];
    v_27739 = qcdr(v_27739);
    stack[-4] = v_27739;
    goto v_27629;
v_27628:
    v_27739 = qvalue(elt(env, 5)); // !*trpm
    if (v_27739 == nil) goto v_27647;
    v_27739 = elt(env, 6); // "Trying rule  "
    v_27739 = Lprinc(nil, v_27739);
    env = stack[-5];
    v_27739 = stack[0];
    fn = elt(env, 13); // rprint
    v_27739 = (*qfn1(fn))(fn, v_27739);
    env = stack[-5];
    v_27739 = elt(env, 7); // "against      "
    v_27739 = Lprinc(nil, v_27739);
    env = stack[-5];
    v_27739 = stack[-3];
    fn = elt(env, 13); // rprint
    v_27739 = (*qfn1(fn))(fn, v_27739);
    env = stack[-5];
    goto v_27645;
v_27647:
v_27645:
    goto v_27668;
v_27660:
    v_27739 = stack[0];
    v_27739 = qcdr(v_27739);
    v_27742 = qcar(v_27739);
    goto v_27661;
v_27662:
    v_27741 = stack[-3];
    goto v_27663;
v_27664:
    v_27740 = lisp_true;
    goto v_27665;
v_27666:
    v_27739 = nil;
    goto v_27667;
v_27668:
    goto v_27660;
v_27661:
    goto v_27662;
v_27663:
    goto v_27664;
v_27665:
    goto v_27666;
v_27667:
    fn = elt(env, 14); // amatch
    v_27739 = (*qfnn(fn))(fn, 4, v_27742, v_27741, v_27740, v_27739);
    env = stack[-5];
    stack[-4] = v_27739;
    v_27739 = qvalue(elt(env, 5)); // !*trpm
    if (v_27739 == nil) goto v_27678;
    v_27739 = stack[-4];
    if (v_27739 == nil) goto v_27683;
    v_27739 = elt(env, 8); // "producing    "
    v_27739 = Lprinc(nil, v_27739);
    env = stack[-5];
    v_27739 = stack[-4];
    fn = elt(env, 15); // embed!-null!-fn
    v_27739 = (*qfn1(fn))(fn, v_27739);
    env = stack[-5];
    stack[-4] = v_27739;
    fn = elt(env, 13); // rprint
    v_27739 = (*qfn1(fn))(fn, v_27739);
    env = stack[-5];
    goto v_27681;
v_27683:
    v_27739 = elt(env, 9); // "failed"
    v_27739 = Lprinc(nil, v_27739);
    env = stack[-5];
    v_27739 = Lterpri(nil, 0);
    env = stack[-5];
    goto v_27681;
v_27681:
    v_27739 = Lterpri(nil, 0);
    env = stack[-5];
    goto v_27676;
v_27678:
v_27676:
    v_27739 = qvalue(elt(env, 1)); // freevars
    stack[0] = v_27739;
v_27701:
    v_27739 = stack[0];
    if (v_27739 == nil) goto v_27705;
    else goto v_27706;
v_27705:
    goto v_27700;
v_27706:
    v_27739 = stack[0];
    v_27739 = qcar(v_27739);
    fn = elt(env, 16); // restorenv
    v_27739 = (*qfn1(fn))(fn, v_27739);
    env = stack[-5];
    v_27739 = stack[0];
    v_27739 = qcdr(v_27739);
    stack[0] = v_27739;
    goto v_27701;
v_27700:
    v_27739 = stack[-4];
    if (v_27739 == nil) goto v_27719;
    goto v_27729;
v_27725:
    v_27740 = qvalue(elt(env, 3)); // rpt
    goto v_27726;
v_27727:
    v_27739 = elt(env, 4); // inf
    goto v_27728;
v_27729:
    goto v_27725;
v_27726:
    goto v_27727;
v_27728:
    if (v_27740 == v_27739) goto v_27724;
    v_27739 = qvalue(elt(env, 3)); // rpt
    v_27739 = sub1(v_27739);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_27739; // rpt
    goto v_27722;
v_27724:
v_27722:
    v_27739 = stack[-4];
    fn = elt(env, 15); // embed!-null!-fn
    v_27739 = (*qfn1(fn))(fn, v_27739);
    goto v_27717;
v_27719:
    v_27739 = stack[-3];
    goto v_27717;
    v_27739 = nil;
v_27717:
v_27561:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_27739);
}



// Code for endmodule

static LispObject CC_endmodule(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27572;
    LispObject fn;
    argcheck(nargs, 0, "endmodule");
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
    v_27572 = qvalue(elt(env, 1)); // mode!-list!*
    if (v_27572 == nil) goto v_27559;
    else goto v_27560;
v_27559:
    v_27572 = elt(env, 2); // "ENDMODULE called outside module"
    fn = elt(env, 7); // rederr
    v_27572 = (*qfn1(fn))(fn, v_27572);
    env = stack[0];
    goto v_27558;
v_27560:
v_27558:
    v_27572 = nil;
    qvalue(elt(env, 3)) = v_27572; // exportslist!*
    v_27572 = nil;
    qvalue(elt(env, 4)) = v_27572; // importslist!*
    v_27572 = nil;
    v_27572 = ncons(v_27572);
    env = stack[0];
    qvalue(elt(env, 5)) = v_27572; // alglist!*
    v_27572 = qvalue(elt(env, 1)); // mode!-list!*
    v_27572 = qcar(v_27572);
    qvalue(elt(env, 6)) = v_27572; // !*mode
    v_27572 = qvalue(elt(env, 1)); // mode!-list!*
    v_27572 = qcdr(v_27572);
    qvalue(elt(env, 1)) = v_27572; // mode!-list!*
    v_27572 = nil;
    return onevalue(v_27572);
}



// Code for mkprec

static LispObject CC_mkprec(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27663, v_27664, v_27665;
    argcheck(nargs, 0, "mkprec");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// end of prologue
    goto v_27566;
v_27562:
    v_27664 = qvalue(elt(env, 1)); // fixedpreclis!*
    goto v_27563;
v_27564:
    v_27663 = qvalue(elt(env, 2)); // preclis!*
    goto v_27565;
v_27566:
    goto v_27562;
v_27563:
    goto v_27564;
v_27565:
    v_27663 = Lappend(nil, v_27664, v_27663);
    env = stack[-4];
    stack[-3] = v_27663;
    v_27663 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_27663;
v_27560:
    v_27663 = stack[-3];
    if (v_27663 == nil) goto v_27572;
    else goto v_27573;
v_27572:
    v_27663 = nil;
    goto v_27559;
v_27573:
    goto v_27583;
v_27577:
    v_27663 = stack[-3];
    v_27665 = qcar(v_27663);
    goto v_27578;
v_27579:
    v_27664 = elt(env, 3); // infix
    goto v_27580;
v_27581:
    v_27663 = stack[-2];
    goto v_27582;
v_27583:
    goto v_27577;
v_27578:
    goto v_27579;
v_27580:
    goto v_27581;
v_27582:
    v_27663 = Lputprop(nil, 3, v_27665, v_27664, v_27663);
    env = stack[-4];
    goto v_27595;
v_27589:
    v_27663 = stack[-3];
    stack[-1] = qcar(v_27663);
    goto v_27590;
v_27591:
    stack[0] = elt(env, 4); // op
    goto v_27592;
v_27593:
    goto v_27605;
v_27601:
    v_27664 = stack[-2];
    goto v_27602;
v_27603:
    v_27663 = stack[-2];
    goto v_27604;
v_27605:
    goto v_27601;
v_27602:
    goto v_27603;
v_27604:
    v_27663 = list2(v_27664, v_27663);
    env = stack[-4];
    v_27663 = ncons(v_27663);
    env = stack[-4];
    goto v_27594;
v_27595:
    goto v_27589;
v_27590:
    goto v_27591;
v_27592:
    goto v_27593;
v_27594:
    v_27663 = Lputprop(nil, 3, stack[-1], stack[0], v_27663);
    env = stack[-4];
    goto v_27617;
v_27613:
    v_27663 = stack[-3];
    v_27664 = qcar(v_27663);
    goto v_27614;
v_27615:
    v_27663 = elt(env, 5); // unary
    goto v_27616;
v_27617:
    goto v_27613;
v_27614:
    goto v_27615;
v_27616:
    v_27663 = get(v_27664, v_27663);
    env = stack[-4];
    stack[0] = v_27663;
    if (v_27663 == nil) goto v_27611;
    goto v_27628;
v_27622:
    v_27665 = stack[0];
    goto v_27623;
v_27624:
    v_27664 = elt(env, 3); // infix
    goto v_27625;
v_27626:
    v_27663 = stack[-2];
    goto v_27627;
v_27628:
    goto v_27622;
v_27623:
    goto v_27624;
v_27625:
    goto v_27626;
v_27627:
    v_27663 = Lputprop(nil, 3, v_27665, v_27664, v_27663);
    env = stack[-4];
    goto v_27609;
v_27611:
v_27609:
    v_27663 = stack[0];
    if (v_27663 == nil) goto v_27635;
    v_27663 = stack[0];
    if (!symbolp(v_27663)) v_27663 = nil;
    else { v_27663 = qfastgets(v_27663);
           if (v_27663 != nil) { v_27663 = elt(v_27663, 35); // nary
#ifdef RECORD_GET
             if (v_27663 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v_27663 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v_27663 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v_27663 == SPID_NOPROP) v_27663 = nil; else v_27663 = lisp_true; }}
#endif
    if (v_27663 == nil) goto v_27638;
    else goto v_27635;
v_27638:
    goto v_27648;
v_27642:
    stack[-1] = stack[0];
    goto v_27643;
v_27644:
    stack[0] = elt(env, 4); // op
    goto v_27645;
v_27646:
    goto v_27656;
v_27652:
    v_27664 = nil;
    goto v_27653;
v_27654:
    v_27663 = stack[-2];
    goto v_27655;
v_27656:
    goto v_27652;
v_27653:
    goto v_27654;
v_27655:
    v_27663 = list2(v_27664, v_27663);
    env = stack[-4];
    goto v_27647;
v_27648:
    goto v_27642;
v_27643:
    goto v_27644;
v_27645:
    goto v_27646;
v_27647:
    v_27663 = Lputprop(nil, 3, stack[-1], stack[0], v_27663);
    env = stack[-4];
    goto v_27633;
v_27635:
v_27633:
    v_27663 = stack[-3];
    v_27663 = qcdr(v_27663);
    stack[-3] = v_27663;
    v_27663 = stack[-2];
    v_27663 = add1(v_27663);
    env = stack[-4];
    stack[-2] = v_27663;
    goto v_27560;
v_27559:
    return onevalue(v_27663);
}



// Code for setmatelem

static LispObject CC_setmatelem(LispObject env,
                         LispObject v_27554, LispObject v_27555)
{
    env = qenv(env);
    LispObject v_27740, v_27741, v_27742;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27554,v_27555);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_27555;
    stack[-3] = v_27554;
// end of prologue
    goto v_27569;
v_27565:
    v_27740 = stack[-3];
    v_27741 = Llength(nil, v_27740);
    env = stack[-5];
    goto v_27566;
v_27567:
    v_27740 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_27568;
v_27569:
    goto v_27565;
v_27566:
    goto v_27567;
v_27568:
    if (v_27741 == v_27740) goto v_27564;
    goto v_27578;
v_27574:
    v_27741 = stack[-3];
    goto v_27575;
v_27576:
    v_27740 = elt(env, 1); // "matrix element"
    goto v_27577;
v_27578:
    goto v_27574;
v_27575:
    goto v_27576;
v_27577:
    fn = elt(env, 8); // typerr
    v_27740 = (*qfn2(fn))(fn, v_27741, v_27740);
    env = stack[-5];
    goto v_27562;
v_27564:
v_27562:
    v_27740 = stack[-3];
    v_27740 = qcar(v_27740);
    if (!symbolp(v_27740)) v_27740 = nil;
    else { v_27740 = qfastgets(v_27740);
           if (v_27740 != nil) { v_27740 = elt(v_27740, 4); // avalue
#ifdef RECORD_GET
             if (v_27740 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_27740 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_27740 == SPID_NOPROP) v_27740 = nil; }}
#endif
    stack[-4] = v_27740;
    v_27740 = stack[-4];
    if (v_27740 == nil) goto v_27590;
    else goto v_27591;
v_27590:
    v_27740 = lisp_true;
    goto v_27589;
v_27591:
    goto v_27600;
v_27596:
    v_27740 = stack[-4];
    v_27741 = qcar(v_27740);
    goto v_27597;
v_27598:
    v_27740 = elt(env, 2); // matrix
    goto v_27599;
v_27600:
    goto v_27596;
v_27597:
    goto v_27598;
v_27599:
    v_27740 = (v_27741 == v_27740 ? lisp_true : nil);
    v_27740 = (v_27740 == nil ? lisp_true : nil);
    goto v_27589;
    v_27740 = nil;
v_27589:
    if (v_27740 == nil) goto v_27587;
    goto v_27611;
v_27607:
    v_27740 = stack[-3];
    v_27741 = qcar(v_27740);
    goto v_27608;
v_27609:
    v_27740 = elt(env, 3); // "matrix"
    goto v_27610;
v_27611:
    goto v_27607;
v_27608:
    goto v_27609;
v_27610:
    fn = elt(env, 8); // typerr
    v_27740 = (*qfn2(fn))(fn, v_27741, v_27740);
    env = stack[-5];
    goto v_27585;
v_27587:
    goto v_27622;
v_27618:
    v_27740 = stack[-4];
    v_27740 = qcdr(v_27740);
    v_27741 = qcar(v_27740);
    stack[-4] = v_27741;
    goto v_27619;
v_27620:
    v_27740 = elt(env, 4); // mat
    goto v_27621;
v_27622:
    goto v_27618;
v_27619:
    goto v_27620;
v_27621:
    if (!consp(v_27741)) goto v_27615;
    v_27741 = qcar(v_27741);
    if (v_27741 == v_27740) goto v_27616;
v_27615:
    goto v_27634;
v_27628:
    stack[-1] = elt(env, 2); // matrix
    goto v_27629;
v_27630:
    stack[0] = (LispObject)160+TAG_FIXNUM; // 10
    goto v_27631;
v_27632:
    goto v_27644;
v_27638:
    v_27742 = elt(env, 5); // "Matrix"
    goto v_27639;
v_27640:
    v_27740 = stack[-3];
    v_27741 = qcar(v_27740);
    goto v_27641;
v_27642:
    v_27740 = elt(env, 6); // "not set"
    goto v_27643;
v_27644:
    goto v_27638;
v_27639:
    goto v_27640;
v_27641:
    goto v_27642;
v_27643:
    v_27740 = list3(v_27742, v_27741, v_27740);
    env = stack[-5];
    goto v_27633;
v_27634:
    goto v_27628;
v_27629:
    goto v_27630;
v_27631:
    goto v_27632;
v_27633:
    fn = elt(env, 9); // rerror
    v_27740 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_27740);
    env = stack[-5];
    goto v_27585;
v_27616:
v_27585:
    v_27740 = stack[-3];
    v_27740 = qcdr(v_27740);
    v_27740 = qcar(v_27740);
    fn = elt(env, 10); // reval_without_mod
    v_27740 = (*qfn1(fn))(fn, v_27740);
    env = stack[-5];
    stack[0] = v_27740;
    v_27740 = stack[0];
    v_27740 = integerp(v_27740);
    if (v_27740 == nil) goto v_27659;
    else goto v_27660;
v_27659:
    v_27740 = lisp_true;
    goto v_27658;
v_27660:
    goto v_27671;
v_27667:
    v_27741 = stack[0];
    goto v_27668;
v_27669:
    v_27740 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27670;
v_27671:
    goto v_27667;
v_27668:
    goto v_27669;
v_27670:
    v_27740 = (LispObject)lesseq2(v_27741, v_27740);
    v_27740 = v_27740 ? lisp_true : nil;
    env = stack[-5];
    goto v_27658;
    v_27740 = nil;
v_27658:
    if (v_27740 == nil) goto v_27656;
    goto v_27679;
v_27675:
    v_27741 = stack[0];
    goto v_27676;
v_27677:
    v_27740 = elt(env, 7); // "positive integer"
    goto v_27678;
v_27679:
    goto v_27675;
v_27676:
    goto v_27677;
v_27678:
    fn = elt(env, 8); // typerr
    v_27740 = (*qfn2(fn))(fn, v_27741, v_27740);
    env = stack[-5];
    goto v_27654;
v_27656:
v_27654:
    goto v_27687;
v_27683:
    v_27740 = stack[-4];
    v_27741 = qcdr(v_27740);
    goto v_27684;
v_27685:
    v_27740 = stack[0];
    goto v_27686;
v_27687:
    goto v_27683;
v_27684:
    goto v_27685;
v_27686:
    fn = elt(env, 11); // nth
    v_27740 = (*qfn2(fn))(fn, v_27741, v_27740);
    env = stack[-5];
    stack[-4] = v_27740;
    v_27740 = stack[-3];
    v_27740 = qcdr(v_27740);
    v_27740 = qcdr(v_27740);
    v_27740 = qcar(v_27740);
    fn = elt(env, 10); // reval_without_mod
    v_27740 = (*qfn1(fn))(fn, v_27740);
    env = stack[-5];
    stack[0] = v_27740;
    v_27740 = stack[0];
    v_27740 = integerp(v_27740);
    if (v_27740 == nil) goto v_27702;
    else goto v_27703;
v_27702:
    v_27740 = lisp_true;
    goto v_27701;
v_27703:
    goto v_27714;
v_27710:
    v_27741 = stack[0];
    goto v_27711;
v_27712:
    v_27740 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27713;
v_27714:
    goto v_27710;
v_27711:
    goto v_27712;
v_27713:
    v_27740 = (LispObject)lesseq2(v_27741, v_27740);
    v_27740 = v_27740 ? lisp_true : nil;
    env = stack[-5];
    goto v_27701;
    v_27740 = nil;
v_27701:
    if (v_27740 == nil) goto v_27699;
    goto v_27722;
v_27718:
    v_27741 = stack[0];
    goto v_27719;
v_27720:
    v_27740 = elt(env, 7); // "positive integer"
    goto v_27721;
v_27722:
    goto v_27718;
v_27719:
    goto v_27720;
v_27721:
    fn = elt(env, 8); // typerr
    v_27740 = (*qfn2(fn))(fn, v_27741, v_27740);
    env = stack[-5];
    goto v_27697;
v_27699:
v_27697:
    goto v_27730;
v_27726:
    goto v_27736;
v_27732:
    v_27741 = stack[-4];
    goto v_27733;
v_27734:
    v_27740 = stack[0];
    goto v_27735;
v_27736:
    goto v_27732;
v_27733:
    goto v_27734;
v_27735:
    fn = elt(env, 12); // pnth
    v_27741 = (*qfn2(fn))(fn, v_27741, v_27740);
    goto v_27727;
v_27728:
    v_27740 = stack[-2];
    goto v_27729;
v_27730:
    goto v_27726;
v_27727:
    goto v_27728;
v_27729:
        return Lrplaca(nil, v_27741, v_27740);
    return onevalue(v_27740);
}



// Code for mv2sf

static LispObject CC_mv2sf(LispObject env,
                         LispObject v_27554, LispObject v_27555)
{
    env = qenv(env);
    LispObject v_27611, v_27612, v_27613;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27554,v_27555);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27555;
    stack[-1] = v_27554;
// end of prologue
    stack[-2] = nil;
v_27561:
    v_27611 = stack[-1];
    if (v_27611 == nil) goto v_27566;
    else goto v_27567;
v_27566:
    goto v_27562;
v_27567:
    goto v_27574;
v_27570:
    goto v_27582;
v_27576:
    v_27611 = stack[-1];
    v_27611 = qcar(v_27611);
    v_27613 = qcar(v_27611);
    goto v_27577;
v_27578:
    v_27611 = stack[-1];
    v_27611 = qcar(v_27611);
    v_27612 = qcdr(v_27611);
    goto v_27579;
v_27580:
    v_27611 = stack[0];
    goto v_27581;
v_27582:
    goto v_27576;
v_27577:
    goto v_27578;
v_27579:
    goto v_27580;
v_27581:
    fn = elt(env, 1); // mv2sf1
    v_27612 = (*qfnn(fn))(fn, 3, v_27613, v_27612, v_27611);
    env = stack[-3];
    goto v_27571;
v_27572:
    v_27611 = stack[-2];
    goto v_27573;
v_27574:
    goto v_27570;
v_27571:
    goto v_27572;
v_27573:
    v_27611 = cons(v_27612, v_27611);
    env = stack[-3];
    stack[-2] = v_27611;
    v_27611 = stack[-1];
    v_27611 = qcdr(v_27611);
    stack[-1] = v_27611;
    goto v_27561;
v_27562:
    v_27611 = nil;
    v_27612 = v_27611;
v_27563:
    v_27611 = stack[-2];
    if (v_27611 == nil) goto v_27596;
    else goto v_27597;
v_27596:
    v_27611 = v_27612;
    goto v_27560;
v_27597:
    goto v_27605;
v_27601:
    v_27611 = stack[-2];
    v_27611 = qcar(v_27611);
    goto v_27602;
v_27603:
    goto v_27604;
v_27605:
    goto v_27601;
v_27602:
    goto v_27603;
v_27604:
    fn = elt(env, 2); // addf
    v_27611 = (*qfn2(fn))(fn, v_27611, v_27612);
    env = stack[-3];
    v_27612 = v_27611;
    v_27611 = stack[-2];
    v_27611 = qcdr(v_27611);
    stack[-2] = v_27611;
    goto v_27563;
v_27560:
    return onevalue(v_27611);
}



// Code for nodum_varp

static LispObject CC_nodum_varp(LispObject env,
                         LispObject v_27554)
{
    env = qenv(env);
    LispObject v_27609, v_27610;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27554);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27554;
// end of prologue
    v_27609 = stack[0];
    fn = elt(env, 4); // listp
    v_27609 = (*qfn1(fn))(fn, v_27609);
    env = stack[-1];
    if (v_27609 == nil) goto v_27559;
    v_27609 = lisp_true;
    goto v_27557;
v_27559:
    v_27609 = stack[0];
    if (!symbolp(v_27609)) v_27609 = nil;
    else { v_27609 = qfastgets(v_27609);
           if (v_27609 != nil) { v_27609 = elt(v_27609, 32); // dummy
#ifdef RECORD_GET
             if (v_27609 == SPID_NOPROP)
                record_get(elt(fastget_names, 32), 0),
                v_27609 = nil;
             else record_get(elt(fastget_names, 32), 1),
                v_27609 = lisp_true; }
           else record_get(elt(fastget_names, 32), 0); }
#else
             if (v_27609 == SPID_NOPROP) v_27609 = nil; else v_27609 = lisp_true; }}
#endif
    if (v_27609 == nil) goto v_27568;
    v_27609 = lisp_true;
    goto v_27566;
v_27568:
    goto v_27582;
v_27578:
    v_27609 = stack[0];
    fn = elt(env, 5); // ad_splitname
    v_27609 = (*qfn1(fn))(fn, v_27609);
    env = stack[-1];
    v_27610 = qcar(v_27609);
    goto v_27579;
v_27580:
    v_27609 = qvalue(elt(env, 1)); // g_dvbase
    goto v_27581;
v_27582:
    goto v_27578;
v_27579:
    goto v_27580;
v_27581:
    if (equal(v_27610, v_27609)) goto v_27576;
    else goto v_27577;
v_27576:
    v_27609 = lisp_true;
    goto v_27575;
v_27577:
    goto v_27594;
v_27590:
    goto v_27591;
v_27592:
    goto v_27601;
v_27597:
    v_27610 = elt(env, 2); // !~dv
    goto v_27598;
v_27599:
    v_27609 = elt(env, 3); // !~dva
    goto v_27600;
v_27601:
    goto v_27597;
v_27598:
    goto v_27599;
v_27600:
    v_27609 = list2(v_27610, v_27609);
    goto v_27593;
v_27594:
    goto v_27590;
v_27591:
    goto v_27592;
v_27593:
    v_27609 = Lmember(nil, stack[0], v_27609);
    goto v_27575;
    v_27609 = nil;
v_27575:
    goto v_27566;
    v_27609 = nil;
v_27566:
    if (v_27609 == nil) goto v_27564;
    v_27609 = nil;
    goto v_27557;
v_27564:
    v_27609 = lisp_true;
    goto v_27557;
    v_27609 = nil;
v_27557:
    return onevalue(v_27609);
}



// Code for polynomlistautoreduce

static LispObject CC_polynomlistautoreduce(LispObject env,
                         LispObject v_27554, LispObject v_27555)
{
    env = qenv(env);
    LispObject v_27765, v_27766, v_27767;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27554,v_27555);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_27555;
    stack[-4] = v_27554;
// end of prologue
    v_27765 = nil;
    v_27765 = ncons(v_27765);
    env = stack[-6];
    stack[-5] = v_27765;
v_27567:
    v_27765 = stack[-4];
    v_27765 = qcar(v_27765);
    if (v_27765 == nil) goto v_27570;
    else goto v_27571;
v_27570:
    goto v_27566;
v_27571:
    goto v_27582;
v_27576:
    v_27767 = stack[-5];
    goto v_27577;
v_27578:
    v_27765 = stack[-4];
    v_27766 = qcar(v_27765);
    goto v_27579;
v_27580:
    v_27765 = stack[-3];
    goto v_27581;
v_27582:
    goto v_27576;
v_27577:
    goto v_27578;
v_27579:
    goto v_27580;
v_27581:
    fn = elt(env, 1); // polynomlistreduce
    v_27765 = (*qfnn(fn))(fn, 3, v_27767, v_27766, v_27765);
    env = stack[-6];
    stack[-2] = v_27765;
    goto v_27592;
v_27588:
    goto v_27598;
v_27594:
    v_27766 = stack[-4];
    goto v_27595;
v_27596:
    v_27765 = stack[-4];
    v_27765 = qcdr(v_27765);
    v_27765 = qcar(v_27765);
    goto v_27597;
v_27598:
    goto v_27594;
v_27595:
    goto v_27596;
v_27597:
    v_27766 = Lrplaca(nil, v_27766, v_27765);
    env = stack[-6];
    goto v_27589;
v_27590:
    v_27765 = stack[-4];
    v_27765 = qcdr(v_27765);
    v_27765 = qcdr(v_27765);
    goto v_27591;
v_27592:
    goto v_27588;
v_27589:
    goto v_27590;
v_27591:
    v_27765 = Lrplacd(nil, v_27766, v_27765);
    env = stack[-6];
    v_27765 = stack[-2];
    v_27765 = qcar(v_27765);
    if (v_27765 == nil) goto v_27609;
    v_27765 = stack[-2];
    v_27765 = qcar(v_27765);
    stack[-1] = v_27765;
    v_27765 = stack[-5];
    stack[0] = v_27765;
v_27617:
    v_27765 = stack[0];
    v_27765 = qcar(v_27765);
    if (v_27765 == nil) goto v_27620;
    else goto v_27621;
v_27620:
    goto v_27616;
v_27621:
    goto v_27634;
v_27630:
    v_27765 = stack[0];
    v_27765 = qcar(v_27765);
    v_27766 = qcar(v_27765);
    goto v_27631;
v_27632:
    v_27765 = stack[-1];
    goto v_27633;
v_27634:
    goto v_27630;
v_27631:
    goto v_27632;
v_27633:
    fn = elt(env, 2); // monomisdivisibleby
    v_27765 = (*qfn2(fn))(fn, v_27766, v_27765);
    env = stack[-6];
    if (v_27765 == nil) goto v_27628;
    goto v_27644;
v_27640:
    v_27766 = stack[-4];
    goto v_27641;
v_27642:
    v_27765 = stack[0];
    v_27765 = qcar(v_27765);
    goto v_27643;
v_27644:
    goto v_27640;
v_27641:
    goto v_27642;
v_27643:
    fn = elt(env, 3); // pushback
    v_27765 = (*qfn2(fn))(fn, v_27766, v_27765);
    env = stack[-6];
    goto v_27653;
v_27649:
    goto v_27659;
v_27655:
    v_27766 = stack[0];
    goto v_27656;
v_27657:
    v_27765 = stack[0];
    v_27765 = qcdr(v_27765);
    v_27765 = qcar(v_27765);
    goto v_27658;
v_27659:
    goto v_27655;
v_27656:
    goto v_27657;
v_27658:
    v_27766 = Lrplaca(nil, v_27766, v_27765);
    env = stack[-6];
    goto v_27650;
v_27651:
    v_27765 = stack[0];
    v_27765 = qcdr(v_27765);
    v_27765 = qcdr(v_27765);
    goto v_27652;
v_27653:
    goto v_27649;
v_27650:
    goto v_27651;
v_27652:
    v_27765 = Lrplacd(nil, v_27766, v_27765);
    env = stack[-6];
    goto v_27626;
v_27628:
    v_27765 = stack[0];
    v_27765 = qcdr(v_27765);
    stack[0] = v_27765;
    goto v_27626;
v_27626:
    goto v_27617;
v_27616:
    goto v_27679;
v_27675:
    v_27766 = stack[-5];
    goto v_27676;
v_27677:
    v_27765 = stack[-2];
    goto v_27678;
v_27679:
    goto v_27675;
v_27676:
    goto v_27677;
v_27678:
    fn = elt(env, 3); // pushback
    v_27765 = (*qfn2(fn))(fn, v_27766, v_27765);
    env = stack[-6];
    goto v_27607;
v_27609:
v_27607:
    goto v_27567;
v_27566:
    v_27765 = stack[-5];
    stack[0] = v_27765;
v_27687:
    v_27765 = stack[0];
    v_27765 = qcar(v_27765);
    if (v_27765 == nil) goto v_27690;
    else goto v_27691;
v_27690:
    goto v_27686;
v_27691:
    v_27765 = stack[0];
    v_27765 = qcar(v_27765);
    stack[-2] = v_27765;
    goto v_27702;
v_27698:
    goto v_27708;
v_27704:
    v_27766 = stack[0];
    goto v_27705;
v_27706:
    v_27765 = stack[0];
    v_27765 = qcdr(v_27765);
    v_27765 = qcar(v_27765);
    goto v_27707;
v_27708:
    goto v_27704;
v_27705:
    goto v_27706;
v_27707:
    v_27766 = Lrplaca(nil, v_27766, v_27765);
    env = stack[-6];
    goto v_27699;
v_27700:
    v_27765 = stack[0];
    v_27765 = qcdr(v_27765);
    v_27765 = qcdr(v_27765);
    goto v_27701;
v_27702:
    goto v_27698;
v_27699:
    goto v_27700;
v_27701:
    v_27765 = Lrplacd(nil, v_27766, v_27765);
    env = stack[-6];
    goto v_27723;
v_27717:
    v_27767 = stack[-5];
    goto v_27718;
v_27719:
    v_27766 = stack[-2];
    goto v_27720;
v_27721:
    v_27765 = stack[-3];
    goto v_27722;
v_27723:
    goto v_27717;
v_27718:
    goto v_27719;
v_27720:
    goto v_27721;
v_27722:
    fn = elt(env, 1); // polynomlistreduce
    v_27765 = (*qfnn(fn))(fn, 3, v_27767, v_27766, v_27765);
    env = stack[-6];
    stack[-2] = v_27765;
    v_27765 = stack[-2];
    if (v_27765 == nil) goto v_27730;
    v_27765 = stack[-2];
    v_27765 = qcar(v_27765);
    if (v_27765 == nil) goto v_27730;
    goto v_27741;
v_27737:
    goto v_27747;
v_27743:
    stack[-1] = stack[0];
    goto v_27744;
v_27745:
    goto v_27754;
v_27750:
    v_27765 = stack[0];
    v_27766 = qcar(v_27765);
    goto v_27751;
v_27752:
    v_27765 = stack[0];
    v_27765 = qcdr(v_27765);
    goto v_27753;
v_27754:
    goto v_27750;
v_27751:
    goto v_27752;
v_27753:
    v_27765 = cons(v_27766, v_27765);
    env = stack[-6];
    goto v_27746;
v_27747:
    goto v_27743;
v_27744:
    goto v_27745;
v_27746:
    v_27766 = Lrplacd(nil, stack[-1], v_27765);
    env = stack[-6];
    goto v_27738;
v_27739:
    v_27765 = stack[-2];
    goto v_27740;
v_27741:
    goto v_27737;
v_27738:
    goto v_27739;
v_27740:
    v_27765 = Lrplaca(nil, v_27766, v_27765);
    env = stack[-6];
    v_27765 = stack[0];
    v_27765 = qcdr(v_27765);
    stack[0] = v_27765;
    goto v_27728;
v_27730:
v_27728:
    goto v_27687;
v_27686:
    v_27765 = stack[-5];
    return onevalue(v_27765);
}



// Code for talp_simplatlinv

static LispObject CC_talp_simplatlinv(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27591, v_27592, v_27593;
    LispObject fn;
    LispObject v_27556, v_27555, v_27554;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_simplatlinv");
    va_start(aa, nargs);
    v_27554 = va_arg(aa, LispObject);
    v_27555 = va_arg(aa, LispObject);
    v_27556 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27556,v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27554,v_27555,v_27556);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27556;
    stack[-1] = v_27555;
    stack[-2] = v_27554;
// end of prologue
    v_27591 = stack[-1];
    fn = elt(env, 1); // talp_simplt
    v_27591 = (*qfn1(fn))(fn, v_27591);
    env = stack[-3];
    stack[-1] = v_27591;
    v_27591 = stack[-1];
    fn = elt(env, 2); // talp_invp
    v_27591 = (*qfn1(fn))(fn, v_27591);
    env = stack[-3];
    if (v_27591 == nil) goto v_27563;
    goto v_27573;
v_27567:
    v_27593 = stack[-2];
    goto v_27568;
v_27569:
    v_27592 = stack[-1];
    goto v_27570;
v_27571:
    v_27591 = stack[0];
    goto v_27572;
v_27573:
    goto v_27567;
v_27568:
    goto v_27569;
v_27570:
    goto v_27571;
v_27572:
    {
        fn = elt(env, 3); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_27593, v_27592, v_27591);
    }
v_27563:
    goto v_27586;
v_27580:
    goto v_27581;
v_27582:
    goto v_27583;
v_27584:
    v_27591 = stack[0];
    fn = elt(env, 1); // talp_simplt
    v_27591 = (*qfn1(fn))(fn, v_27591);
    env = stack[-3];
    goto v_27585;
v_27586:
    goto v_27580;
v_27581:
    goto v_27582;
v_27583:
    goto v_27584;
v_27585:
    {
        LispObject v_27597 = stack[-2];
        LispObject v_27598 = stack[-1];
        fn = elt(env, 4); // talp_simplat2
        return (*qfnn(fn))(fn, 3, v_27597, v_27598, v_27591);
    }
    v_27591 = nil;
    return onevalue(v_27591);
}



// Code for cl_sacat

static LispObject CC_cl_sacat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27573, v_27574, v_27575;
    LispObject v_27556, v_27555, v_27554;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cl_sacat");
    va_start(aa, nargs);
    v_27554 = va_arg(aa, LispObject);
    v_27555 = va_arg(aa, LispObject);
    v_27556 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27573 = v_27556;
    v_27574 = v_27555;
    v_27575 = v_27554;
// end of prologue
    goto v_27566;
v_27562:
    v_27573 = v_27575;
    goto v_27563;
v_27564:
    goto v_27565;
v_27566:
    goto v_27562;
v_27563:
    goto v_27564;
v_27565:
    if (equal(v_27573, v_27574)) goto v_27560;
    else goto v_27561;
v_27560:
    v_27573 = elt(env, 1); // keep
    goto v_27559;
v_27561:
    v_27573 = nil;
    goto v_27559;
    v_27573 = nil;
v_27559:
    return onevalue(v_27573);
}



// Code for operator_fn

static LispObject CC_operator_fn(LispObject env,
                         LispObject v_27554)
{
    env = qenv(env);
    LispObject v_27584;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27554);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27554;
// end of prologue
    v_27584 = elt(env, 1); // "<apply>"
    fn = elt(env, 7); // printout
    v_27584 = (*qfn1(fn))(fn, v_27584);
    env = stack[-1];
    v_27584 = lisp_true;
    fn = elt(env, 8); // indent!*
    v_27584 = (*qfn1(fn))(fn, v_27584);
    env = stack[-1];
    v_27584 = elt(env, 2); // "<csymbol>"
    fn = elt(env, 7); // printout
    v_27584 = (*qfn1(fn))(fn, v_27584);
    env = stack[-1];
    v_27584 = lisp_true;
    fn = elt(env, 8); // indent!*
    v_27584 = (*qfn1(fn))(fn, v_27584);
    env = stack[-1];
    v_27584 = elt(env, 3); // "<ci>"
    fn = elt(env, 7); // printout
    v_27584 = (*qfn1(fn))(fn, v_27584);
    env = stack[-1];
    v_27584 = stack[0];
    v_27584 = qcar(v_27584);
    v_27584 = Lprinc(nil, v_27584);
    env = stack[-1];
    v_27584 = elt(env, 4); // "</ci>"
    v_27584 = Lprinc(nil, v_27584);
    env = stack[-1];
    v_27584 = nil;
    fn = elt(env, 8); // indent!*
    v_27584 = (*qfn1(fn))(fn, v_27584);
    env = stack[-1];
    v_27584 = elt(env, 5); // "</csymbol>"
    fn = elt(env, 7); // printout
    v_27584 = (*qfn1(fn))(fn, v_27584);
    env = stack[-1];
    v_27584 = stack[0];
    v_27584 = qcdr(v_27584);
    fn = elt(env, 9); // multi_args
    v_27584 = (*qfn1(fn))(fn, v_27584);
    env = stack[-1];
    v_27584 = nil;
    fn = elt(env, 8); // indent!*
    v_27584 = (*qfn1(fn))(fn, v_27584);
    env = stack[-1];
    v_27584 = elt(env, 6); // "</apply>"
    fn = elt(env, 7); // printout
    v_27584 = (*qfn1(fn))(fn, v_27584);
    v_27584 = nil;
    return onevalue(v_27584);
}



// Code for mulpower

static LispObject CC_mulpower(LispObject env,
                         LispObject v_27554, LispObject v_27555)
{
    env = qenv(env);
    LispObject v_27608, v_27609, v_27610;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27554,v_27555);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_27608 = v_27555;
    v_27609 = v_27554;
// end of prologue
    stack[0] = nil;
    goto v_27566;
v_27562:
    goto v_27563;
v_27564:
    goto v_27565;
v_27566:
    goto v_27562;
v_27563:
    goto v_27564;
v_27565:
    fn = elt(env, 3); // addexptsdf
    v_27608 = (*qfn2(fn))(fn, v_27609, v_27608);
    env = stack[-2];
    stack[-1] = v_27608;
    v_27608 = qvalue(elt(env, 1)); // sqrtlist
    if (v_27608 == nil) goto v_27572;
    goto v_27579;
v_27575:
    v_27609 = stack[-1];
    goto v_27576;
v_27577:
    v_27608 = qvalue(elt(env, 2)); // zlist
    goto v_27578;
v_27579:
    goto v_27575;
v_27576:
    goto v_27577;
v_27578:
    fn = elt(env, 4); // reduceroots
    v_27608 = (*qfn2(fn))(fn, v_27609, v_27608);
    env = stack[-2];
    stack[0] = v_27608;
    goto v_27570;
v_27572:
v_27570:
    goto v_27590;
v_27584:
    v_27610 = stack[-1];
    goto v_27585;
v_27586:
    v_27609 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27587;
v_27588:
    v_27608 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27589;
v_27590:
    goto v_27584;
v_27585:
    goto v_27586;
v_27587:
    goto v_27588;
v_27589:
    v_27608 = list2star(v_27610, v_27609, v_27608);
    env = stack[-2];
    v_27608 = ncons(v_27608);
    env = stack[-2];
    stack[-1] = v_27608;
    v_27608 = stack[0];
    if (v_27608 == nil) goto v_27597;
    goto v_27604;
v_27600:
    v_27609 = stack[-1];
    goto v_27601;
v_27602:
    v_27608 = stack[0];
    goto v_27603;
v_27604:
    goto v_27600;
v_27601:
    goto v_27602;
v_27603:
    fn = elt(env, 5); // multdf
    v_27608 = (*qfn2(fn))(fn, v_27609, v_27608);
    stack[-1] = v_27608;
    goto v_27595;
v_27597:
v_27595:
    v_27608 = stack[-1];
    return onevalue(v_27608);
}



// Code for newsym1

static LispObject CC_newsym1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27571, v_27572;
    argcheck(nargs, 0, "newsym1");
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
    v_27571 = qvalue(elt(env, 1)); // cindex!*
    v_27571 = Lexplode(nil, v_27571);
    env = stack[-1];
    stack[0] = v_27571;
    v_27571 = qvalue(elt(env, 1)); // cindex!*
    v_27571 = add1(v_27571);
    env = stack[-1];
    qvalue(elt(env, 1)) = v_27571; // cindex!*
    goto v_27568;
v_27564:
    v_27572 = qvalue(elt(env, 2)); // cname!*
    goto v_27565;
v_27566:
    v_27571 = stack[0];
    goto v_27567;
v_27568:
    goto v_27564;
v_27565:
    goto v_27566;
v_27567:
    v_27571 = Lappend(nil, v_27572, v_27571);
        return Lcompress(nil, v_27571);
    return onevalue(v_27571);
}



// Code for xregister_spoly_pair

static LispObject CC_xregister_spoly_pair(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27556;
    argcheck(nargs, 0, "xregister_spoly_pair");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_27556 = nil;
    return onevalue(v_27556);
}



// Code for evaluate2

static LispObject CC_evaluate2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27752, v_27753, v_27754;
    LispObject fn;
    LispObject v_27556, v_27555, v_27554;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "evaluate2");
    va_start(aa, nargs);
    v_27554 = va_arg(aa, LispObject);
    v_27555 = va_arg(aa, LispObject);
    v_27556 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27556,v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27554,v_27555,v_27556);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_27556;
    v_27753 = v_27555;
    stack[-4] = v_27554;
// end of prologue
    goto v_27566;
v_27562:
    v_27754 = stack[-4];
    goto v_27563;
v_27564:
    v_27752 = elt(env, 1); // !:dn!:
    goto v_27565;
v_27566:
    goto v_27562;
v_27563:
    goto v_27564;
v_27565:
    if (v_27754 == v_27752) goto v_27560;
    else goto v_27561;
v_27560:
    v_27752 = v_27753;
    fn = elt(env, 5); // dn!:simp
    v_27752 = (*qfn1(fn))(fn, v_27752);
    v_27752 = qcar(v_27752);
    goto v_27559;
v_27561:
    v_27752 = v_27753;
    stack[-5] = v_27752;
    v_27752 = stack[-5];
    if (v_27752 == nil) goto v_27585;
    else goto v_27586;
v_27585:
    v_27752 = nil;
    goto v_27580;
v_27586:
    v_27752 = stack[-5];
    v_27752 = qcar(v_27752);
    goto v_27598;
v_27594:
    v_27753 = v_27752;
    goto v_27595;
v_27596:
    v_27752 = stack[-3];
    goto v_27597;
v_27598:
    goto v_27594;
v_27595:
    goto v_27596;
v_27597:
    fn = elt(env, 6); // evaluate1
    v_27752 = (*qfn2(fn))(fn, v_27753, v_27752);
    env = stack[-6];
    v_27752 = ncons(v_27752);
    env = stack[-6];
    stack[-1] = v_27752;
    stack[-2] = v_27752;
v_27581:
    v_27752 = stack[-5];
    v_27752 = qcdr(v_27752);
    stack[-5] = v_27752;
    v_27752 = stack[-5];
    if (v_27752 == nil) goto v_27605;
    else goto v_27606;
v_27605:
    v_27752 = stack[-2];
    goto v_27580;
v_27606:
    goto v_27614;
v_27610:
    stack[0] = stack[-1];
    goto v_27611;
v_27612:
    v_27752 = stack[-5];
    v_27752 = qcar(v_27752);
    goto v_27625;
v_27621:
    v_27753 = v_27752;
    goto v_27622;
v_27623:
    v_27752 = stack[-3];
    goto v_27624;
v_27625:
    goto v_27621;
v_27622:
    goto v_27623;
v_27624:
    fn = elt(env, 6); // evaluate1
    v_27752 = (*qfn2(fn))(fn, v_27753, v_27752);
    env = stack[-6];
    v_27752 = ncons(v_27752);
    env = stack[-6];
    goto v_27613;
v_27614:
    goto v_27610;
v_27611:
    goto v_27612;
v_27613:
    v_27752 = Lrplacd(nil, stack[0], v_27752);
    env = stack[-6];
    v_27752 = stack[-1];
    v_27752 = qcdr(v_27752);
    stack[-1] = v_27752;
    goto v_27581;
v_27580:
    v_27753 = v_27752;
    goto v_27638;
v_27634:
    v_27754 = stack[-4];
    goto v_27635;
v_27636:
    v_27752 = elt(env, 2); // plus
    goto v_27637;
v_27638:
    goto v_27634;
v_27635:
    goto v_27636;
v_27637:
    if (v_27754 == v_27752) goto v_27632;
    else goto v_27633;
v_27632:
    v_27752 = v_27753;
    {
        fn = elt(env, 7); // !:dmpluslst
        return (*qfn1(fn))(fn, v_27752);
    }
v_27633:
    goto v_27649;
v_27645:
    v_27754 = stack[-4];
    goto v_27646;
v_27647:
    v_27752 = elt(env, 3); // times
    goto v_27648;
v_27649:
    goto v_27645;
v_27646:
    goto v_27647;
v_27648:
    if (v_27754 == v_27752) goto v_27643;
    else goto v_27644;
v_27643:
    v_27752 = v_27753;
    {
        fn = elt(env, 8); // !:dmtimeslst
        return (*qfn1(fn))(fn, v_27752);
    }
v_27644:
    goto v_27660;
v_27656:
    v_27754 = stack[-4];
    goto v_27657;
v_27658:
    v_27752 = qvalue(elt(env, 4)); // dmarith!*
    goto v_27659;
v_27660:
    goto v_27656;
v_27657:
    goto v_27658;
v_27659:
    v_27752 = Lassoc(nil, v_27754, v_27752);
    v_27754 = v_27752;
    if (v_27752 == nil) goto v_27655;
    goto v_27669;
v_27665:
    v_27752 = v_27754;
    v_27752 = qcdr(v_27752);
    goto v_27666;
v_27667:
    goto v_27668;
v_27669:
    goto v_27665;
v_27666:
    goto v_27667;
v_27668:
    {
        fn = elt(env, 9); // apply
        return (*qfn2(fn))(fn, v_27752, v_27753);
    }
v_27655:
    v_27752 = v_27753;
    v_27752 = qcar(v_27752);
    v_27752 = Lconsp(nil, v_27752);
    env = stack[-6];
    if (v_27752 == nil) goto v_27674;
    goto v_27685;
v_27681:
    v_27754 = stack[-4];
    goto v_27682;
v_27683:
    v_27752 = v_27753;
    v_27752 = qcar(v_27752);
    v_27752 = qcar(v_27752);
    goto v_27684;
v_27685:
    goto v_27681;
v_27682:
    goto v_27683;
v_27684:
    v_27752 = get(v_27754, v_27752);
    env = stack[-6];
    v_27754 = v_27752;
    if (v_27752 == nil) goto v_27674;
    goto v_27695;
v_27691:
    v_27752 = v_27754;
    goto v_27692;
v_27693:
    goto v_27694;
v_27695:
    goto v_27691;
v_27692:
    goto v_27693;
v_27694:
    {
        fn = elt(env, 9); // apply
        return (*qfn2(fn))(fn, v_27752, v_27753);
    }
v_27674:
    goto v_27707;
v_27703:
    goto v_27704;
v_27705:
    v_27752 = v_27753;
    stack[-3] = v_27752;
    v_27752 = stack[-3];
    if (v_27752 == nil) goto v_27718;
    else goto v_27719;
v_27718:
    v_27752 = nil;
    goto v_27713;
v_27719:
    v_27752 = stack[-3];
    v_27752 = qcar(v_27752);
    fn = elt(env, 10); // prepf
    v_27752 = (*qfn1(fn))(fn, v_27752);
    env = stack[-6];
    v_27752 = ncons(v_27752);
    env = stack[-6];
    stack[-1] = v_27752;
    stack[-2] = v_27752;
v_27714:
    v_27752 = stack[-3];
    v_27752 = qcdr(v_27752);
    stack[-3] = v_27752;
    v_27752 = stack[-3];
    if (v_27752 == nil) goto v_27732;
    else goto v_27733;
v_27732:
    v_27752 = stack[-2];
    goto v_27713;
v_27733:
    goto v_27741;
v_27737:
    stack[0] = stack[-1];
    goto v_27738;
v_27739:
    v_27752 = stack[-3];
    v_27752 = qcar(v_27752);
    fn = elt(env, 10); // prepf
    v_27752 = (*qfn1(fn))(fn, v_27752);
    env = stack[-6];
    v_27752 = ncons(v_27752);
    env = stack[-6];
    goto v_27740;
v_27741:
    goto v_27737;
v_27738:
    goto v_27739;
v_27740:
    v_27752 = Lrplacd(nil, stack[0], v_27752);
    env = stack[-6];
    v_27752 = stack[-1];
    v_27752 = qcdr(v_27752);
    stack[-1] = v_27752;
    goto v_27714;
v_27713:
    goto v_27706;
v_27707:
    goto v_27703;
v_27704:
    goto v_27705;
v_27706:
    v_27752 = cons(stack[-4], v_27752);
    env = stack[-6];
    fn = elt(env, 11); // simp
    v_27752 = (*qfn1(fn))(fn, v_27752);
    env = stack[-6];
    v_27752 = qcar(v_27752);
    {
        fn = elt(env, 12); // force!-to!-dm
        return (*qfn1(fn))(fn, v_27752);
    }
    v_27752 = nil;
    goto v_27559;
    v_27752 = nil;
v_27559:
    return onevalue(v_27752);
}



// Code for mkforttab

static LispObject CC_mkforttab(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27570, v_27571;
    argcheck(nargs, 0, "mkforttab");
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
    goto v_27560;
v_27556:
    stack[0] = elt(env, 1); // forttab
    goto v_27557;
v_27558:
    goto v_27567;
v_27563:
    v_27571 = qvalue(elt(env, 2)); // fortcurrind!*
    goto v_27564;
v_27565:
    v_27570 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_27566;
v_27567:
    goto v_27563;
v_27564:
    goto v_27565;
v_27566:
    v_27570 = plus2(v_27571, v_27570);
    goto v_27559;
v_27560:
    goto v_27556;
v_27557:
    goto v_27558;
v_27559:
    {
        LispObject v_27573 = stack[0];
        return list2(v_27573, v_27570);
    }
}



// Code for sign!-abs

static LispObject CC_signKabs(LispObject env,
                         LispObject v_27554)
{
    env = qenv(env);
    LispObject v_27601, v_27602;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27554);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27554;
// end of prologue
    v_27601 = stack[0];
    fn = elt(env, 2); // sign!-of
    v_27601 = (*qfn1(fn))(fn, v_27601);
    env = stack[-2];
    stack[-1] = v_27601;
    v_27601 = stack[-1];
    if (is_number(v_27601)) goto v_27562;
    v_27601 = nil;
    goto v_27560;
v_27562:
    goto v_27577;
v_27573:
    v_27602 = stack[-1];
    goto v_27574;
v_27575:
    v_27601 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27576;
v_27577:
    goto v_27573;
v_27574:
    goto v_27575;
v_27576:
    v_27601 = (LispObject)lessp2(v_27602, v_27601);
    v_27601 = v_27601 ? lisp_true : nil;
    env = stack[-2];
    if (v_27601 == nil) goto v_27571;
    goto v_27585;
v_27581:
    v_27602 = elt(env, 1); // minus
    goto v_27582;
v_27583:
    v_27601 = stack[0];
    goto v_27584;
v_27585:
    goto v_27581;
v_27582:
    goto v_27583;
v_27584:
    v_27601 = list2(v_27602, v_27601);
    env = stack[-2];
    goto v_27569;
v_27571:
    goto v_27594;
v_27590:
    v_27602 = stack[-1];
    goto v_27591;
v_27592:
    v_27601 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27593;
v_27594:
    goto v_27590;
v_27591:
    goto v_27592;
v_27593:
    if (v_27602 == v_27601) goto v_27588;
    else goto v_27589;
v_27588:
    v_27601 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27569;
v_27589:
    v_27601 = stack[0];
    goto v_27569;
    v_27601 = nil;
v_27569:
    {
        fn = elt(env, 3); // simp
        return (*qfn1(fn))(fn, v_27601);
    }
    v_27601 = nil;
v_27560:
    return onevalue(v_27601);
}



// Code for mv!-compact

static LispObject CC_mvKcompact(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27704, v_27705, v_27706;
    LispObject fn;
    LispObject v_27556, v_27555, v_27554;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mv-compact");
    va_start(aa, nargs);
    v_27554 = va_arg(aa, LispObject);
    v_27555 = va_arg(aa, LispObject);
    v_27556 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27556,v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27554,v_27555,v_27556);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_27556;
    stack[-2] = v_27555;
    stack[-3] = v_27554;
// end of prologue
v_27553:
    v_27704 = stack[-3];
    if (v_27704 == nil) goto v_27564;
    else goto v_27565;
v_27564:
    v_27704 = stack[-1];
    {
        fn = elt(env, 1); // mv!-reverse
        return (*qfn1(fn))(fn, v_27704);
    }
v_27565:
    goto v_27579;
v_27575:
    v_27705 = stack[-3];
    goto v_27576;
v_27577:
    v_27704 = stack[-2];
    goto v_27578;
v_27579:
    goto v_27575;
v_27576:
    goto v_27577;
v_27578:
    fn = elt(env, 2); // mv!-pow!-chk
    v_27704 = (*qfn2(fn))(fn, v_27705, v_27704);
    env = stack[-5];
    stack[-4] = v_27704;
    if (v_27704 == nil) goto v_27572;
    goto v_27588;
v_27584:
    stack[0] = stack[-3];
    goto v_27585;
v_27586:
    goto v_27595;
v_27591:
    v_27705 = stack[-4];
    goto v_27592;
v_27593:
    v_27704 = stack[-2];
    goto v_27594;
v_27595:
    goto v_27591;
v_27592:
    goto v_27593;
v_27594:
    fn = elt(env, 3); // mv!-pow!-mv!-!+
    v_27704 = (*qfn2(fn))(fn, v_27705, v_27704);
    env = stack[-5];
    goto v_27587;
v_27588:
    goto v_27584;
v_27585:
    goto v_27586;
v_27587:
    fn = elt(env, 4); // mv!-compact2
    v_27704 = (*qfn2(fn))(fn, stack[0], v_27704);
    env = stack[-5];
    stack[0] = v_27704;
    if (v_27704 == nil) goto v_27572;
    goto v_27605;
v_27599:
    v_27706 = stack[0];
    goto v_27600;
v_27601:
    v_27705 = stack[-2];
    goto v_27602;
v_27603:
    v_27704 = stack[-1];
    goto v_27604;
v_27605:
    goto v_27599;
v_27600:
    goto v_27601;
v_27602:
    goto v_27603;
v_27604:
    stack[-3] = v_27706;
    stack[-2] = v_27705;
    stack[-1] = v_27704;
    goto v_27553;
v_27572:
    goto v_27617;
v_27613:
    v_27705 = stack[-3];
    goto v_27614;
v_27615:
    v_27704 = stack[-2];
    v_27704 = qcdr(v_27704);
    goto v_27616;
v_27617:
    goto v_27613;
v_27614:
    goto v_27615;
v_27616:
    fn = elt(env, 2); // mv!-pow!-chk
    v_27704 = (*qfn2(fn))(fn, v_27705, v_27704);
    env = stack[-5];
    stack[-4] = v_27704;
    if (v_27704 == nil) goto v_27610;
    goto v_27631;
v_27627:
    goto v_27637;
v_27633:
    v_27705 = stack[-4];
    goto v_27634;
v_27635:
    v_27704 = stack[-2];
    v_27704 = qcar(v_27704);
    v_27704 = qcar(v_27704);
    goto v_27636;
v_27637:
    goto v_27633;
v_27634:
    goto v_27635;
v_27636:
    fn = elt(env, 5); // mv!-pow!-!+
    v_27705 = (*qfn2(fn))(fn, v_27705, v_27704);
    env = stack[-5];
    stack[0] = v_27705;
    goto v_27628;
v_27629:
    v_27704 = stack[-1];
    goto v_27630;
v_27631:
    goto v_27627;
v_27628:
    goto v_27629;
v_27630:
    fn = elt(env, 6); // mv!-pow!-assoc
    v_27704 = (*qfn2(fn))(fn, v_27705, v_27704);
    env = stack[-5];
    if (v_27704 == nil) goto v_27624;
    else goto v_27625;
v_27624:
    goto v_27648;
v_27644:
    goto v_27656;
v_27650:
    v_27706 = stack[0];
    goto v_27651;
v_27652:
    v_27705 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27653;
v_27654:
    v_27704 = stack[-3];
    goto v_27655;
v_27656:
    goto v_27650;
v_27651:
    goto v_27652;
v_27653:
    goto v_27654;
v_27655:
    stack[0] = acons(v_27706, v_27705, v_27704);
    env = stack[-5];
    goto v_27645;
v_27646:
    goto v_27665;
v_27661:
    v_27705 = stack[-4];
    goto v_27662;
v_27663:
    v_27704 = stack[-2];
    goto v_27664;
v_27665:
    goto v_27661;
v_27662:
    goto v_27663;
v_27664:
    fn = elt(env, 3); // mv!-pow!-mv!-!+
    v_27704 = (*qfn2(fn))(fn, v_27705, v_27704);
    env = stack[-5];
    goto v_27647;
v_27648:
    goto v_27644;
v_27645:
    goto v_27646;
v_27647:
    fn = elt(env, 4); // mv!-compact2
    v_27704 = (*qfn2(fn))(fn, stack[0], v_27704);
    env = stack[-5];
    stack[0] = v_27704;
    goto v_27623;
v_27625:
    v_27704 = nil;
    goto v_27623;
    v_27704 = nil;
v_27623:
    if (v_27704 == nil) goto v_27610;
    goto v_27678;
v_27672:
    v_27706 = stack[0];
    goto v_27673;
v_27674:
    v_27705 = stack[-2];
    goto v_27675;
v_27676:
    v_27704 = stack[-1];
    goto v_27677;
v_27678:
    goto v_27672;
v_27673:
    goto v_27674;
v_27675:
    goto v_27676;
v_27677:
    stack[-3] = v_27706;
    stack[-2] = v_27705;
    stack[-1] = v_27704;
    goto v_27553;
v_27610:
    goto v_27691;
v_27685:
    v_27704 = stack[-3];
    stack[0] = qcdr(v_27704);
    goto v_27686;
v_27687:
    goto v_27688;
v_27689:
    goto v_27700;
v_27696:
    v_27704 = stack[-3];
    v_27705 = qcar(v_27704);
    goto v_27697;
v_27698:
    v_27704 = stack[-1];
    goto v_27699;
v_27700:
    goto v_27696;
v_27697:
    goto v_27698;
v_27699:
    v_27704 = cons(v_27705, v_27704);
    env = stack[-5];
    goto v_27690;
v_27691:
    goto v_27685;
v_27686:
    goto v_27687;
v_27688:
    goto v_27689;
v_27690:
    stack[-3] = stack[0];
    stack[-1] = v_27704;
    goto v_27553;
    v_27704 = nil;
    return onevalue(v_27704);
}



// Code for simp!-prop

static LispObject CC_simpKprop(LispObject env,
                         LispObject v_27554)
{
    env = qenv(env);
    LispObject v_27774, v_27775, v_27776;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27554);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-2] = v_27554;
// end of prologue
// Binding propvars!*
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
    qvalue(elt(env, 1)) = nil; // propvars!*
    v_27774 = stack[-2];
    v_27774 = qcdr(v_27774);
    stack[-4] = v_27774;
    v_27774 = stack[-4];
    if (v_27774 == nil) goto v_27571;
    else goto v_27572;
v_27571:
    v_27774 = nil;
    goto v_27565;
v_27572:
    v_27774 = stack[-4];
    v_27774 = qcar(v_27774);
    fn = elt(env, 12); // reval
    v_27774 = (*qfn1(fn))(fn, v_27774);
    env = stack[-7];
    v_27774 = ncons(v_27774);
    env = stack[-7];
    stack[-1] = v_27774;
    stack[-3] = v_27774;
v_27566:
    v_27774 = stack[-4];
    v_27774 = qcdr(v_27774);
    stack[-4] = v_27774;
    v_27774 = stack[-4];
    if (v_27774 == nil) goto v_27585;
    else goto v_27586;
v_27585:
    v_27774 = stack[-3];
    goto v_27565;
v_27586:
    goto v_27594;
v_27590:
    stack[0] = stack[-1];
    goto v_27591;
v_27592:
    v_27774 = stack[-4];
    v_27774 = qcar(v_27774);
    fn = elt(env, 12); // reval
    v_27774 = (*qfn1(fn))(fn, v_27774);
    env = stack[-7];
    v_27774 = ncons(v_27774);
    env = stack[-7];
    goto v_27593;
v_27594:
    goto v_27590;
v_27591:
    goto v_27592;
v_27593:
    v_27774 = Lrplacd(nil, stack[0], v_27774);
    env = stack[-7];
    v_27774 = stack[-1];
    v_27774 = qcdr(v_27774);
    stack[-1] = v_27774;
    goto v_27566;
v_27565:
    stack[-5] = v_27774;
    goto v_27612;
v_27608:
    v_27775 = elt(env, 2); // and
    goto v_27609;
v_27610:
    v_27774 = stack[-5];
    goto v_27611;
v_27612:
    goto v_27608;
v_27609:
    goto v_27610;
v_27611:
    v_27774 = Lmember(nil, v_27775, v_27774);
    if (v_27774 == nil) goto v_27607;
    v_27774 = elt(env, 3); // or
    qvalue(elt(env, 4)) = v_27774; // !'and
    v_27774 = elt(env, 2); // and
    qvalue(elt(env, 5)) = v_27774; // !'or
    v_27774 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 6)) = v_27774; // !'true
    v_27774 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 7)) = v_27774; // !'false
    goto v_27605;
v_27607:
    v_27774 = elt(env, 2); // and
    qvalue(elt(env, 4)) = v_27774; // !'and
    v_27774 = elt(env, 3); // or
    qvalue(elt(env, 5)) = v_27774; // !'or
    v_27774 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 6)) = v_27774; // !'true
    v_27774 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 7)) = v_27774; // !'false
    goto v_27605;
v_27605:
    goto v_27635;
v_27631:
    v_27774 = stack[-2];
    v_27775 = qcar(v_27774);
    goto v_27632;
v_27633:
    v_27774 = lisp_true;
    goto v_27634;
v_27635:
    goto v_27631;
v_27632:
    goto v_27633;
v_27634:
    fn = elt(env, 13); // simp!-prop1
    v_27774 = (*qfn2(fn))(fn, v_27775, v_27774);
    env = stack[-7];
    fn = elt(env, 14); // prepf
    v_27774 = (*qfn1(fn))(fn, v_27774);
    env = stack[-7];
    fn = elt(env, 12); // reval
    v_27774 = (*qfn1(fn))(fn, v_27774);
    env = stack[-7];
    v_27776 = v_27774;
    goto v_27647;
v_27643:
    v_27775 = v_27776;
    goto v_27644;
v_27645:
    v_27774 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27646;
v_27647:
    goto v_27643;
v_27644:
    goto v_27645;
v_27646:
    if (v_27775 == v_27774) goto v_27641;
    else goto v_27642;
v_27641:
    v_27774 = qvalue(elt(env, 7)); // !'false
    fn = elt(env, 15); // simp
    v_27774 = (*qfn1(fn))(fn, v_27774);
    goto v_27560;
v_27642:
    v_27774 = qvalue(elt(env, 1)); // propvars!*
    stack[-4] = v_27774;
v_27655:
    v_27774 = stack[-4];
    if (v_27774 == nil) goto v_27659;
    else goto v_27660;
v_27659:
    goto v_27654;
v_27660:
    v_27774 = stack[-4];
    v_27774 = qcar(v_27774);
    goto v_27674;
v_27668:
    stack[-3] = elt(env, 8); // times
    goto v_27669;
v_27670:
    stack[-2] = v_27776;
    goto v_27671;
v_27672:
    goto v_27683;
v_27679:
    goto v_27691;
v_27685:
    stack[-1] = qvalue(elt(env, 5)); // !'or
    goto v_27686;
v_27687:
    stack[0] = v_27774;
    goto v_27688;
v_27689:
    goto v_27699;
v_27695:
    v_27775 = elt(env, 9); // not
    goto v_27696;
v_27697:
    goto v_27698;
v_27699:
    goto v_27695;
v_27696:
    goto v_27697;
v_27698:
    v_27774 = list2(v_27775, v_27774);
    env = stack[-7];
    goto v_27690;
v_27691:
    goto v_27685;
v_27686:
    goto v_27687;
v_27688:
    goto v_27689;
v_27690:
    v_27775 = list3(stack[-1], stack[0], v_27774);
    env = stack[-7];
    goto v_27680;
v_27681:
    v_27774 = lisp_true;
    goto v_27682;
v_27683:
    goto v_27679;
v_27680:
    goto v_27681;
v_27682:
    fn = elt(env, 13); // simp!-prop1
    v_27774 = (*qfn2(fn))(fn, v_27775, v_27774);
    env = stack[-7];
    fn = elt(env, 14); // prepf
    v_27774 = (*qfn1(fn))(fn, v_27774);
    env = stack[-7];
    goto v_27673;
v_27674:
    goto v_27668;
v_27669:
    goto v_27670;
v_27671:
    goto v_27672;
v_27673:
    v_27774 = list3(stack[-3], stack[-2], v_27774);
    env = stack[-7];
    fn = elt(env, 12); // reval
    v_27774 = (*qfn1(fn))(fn, v_27774);
    env = stack[-7];
    v_27776 = v_27774;
    v_27774 = stack[-4];
    v_27774 = qcdr(v_27774);
    stack[-4] = v_27774;
    goto v_27655;
v_27654:
    v_27774 = v_27776;
    fn = elt(env, 16); // simp!-prop!-dist
    v_27774 = (*qfn1(fn))(fn, v_27774);
    env = stack[-7];
    v_27776 = v_27774;
    goto v_27715;
v_27711:
    v_27775 = elt(env, 10); // full
    goto v_27712;
v_27713:
    v_27774 = stack[-5];
    goto v_27714;
v_27715:
    goto v_27711;
v_27712:
    goto v_27713;
v_27714:
    v_27774 = Lmember(nil, v_27775, v_27774);
    if (v_27774 == nil) goto v_27709;
    else goto v_27710;
v_27709:
    v_27774 = v_27776;
    fn = elt(env, 17); // simp!-prop2
    v_27774 = (*qfn1(fn))(fn, v_27774);
    env = stack[-7];
    v_27776 = v_27774;
    goto v_27708;
v_27710:
v_27708:
    v_27774 = v_27776;
    fn = elt(env, 18); // simp!-prop!-form
    v_27774 = (*qfn1(fn))(fn, v_27774);
    env = stack[-7];
    v_27776 = v_27774;
    v_27774 = v_27776;
    if (is_number(v_27774)) goto v_27725;
    else goto v_27726;
v_27725:
    goto v_27733;
v_27729:
    v_27775 = v_27776;
    goto v_27730;
v_27731:
    v_27774 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27732;
v_27733:
    goto v_27729;
v_27730:
    goto v_27731;
v_27732:
    v_27774 = cons(v_27775, v_27774);
    goto v_27560;
v_27726:
    v_27774 = v_27776;
    if (!consp(v_27774)) goto v_27739;
    goto v_27746;
v_27742:
    v_27774 = elt(env, 11); // boolean
    goto v_27743;
v_27744:
    v_27775 = v_27776;
    goto v_27745;
v_27746:
    goto v_27742;
v_27743:
    goto v_27744;
v_27745:
    v_27774 = list2(v_27774, v_27775);
    env = stack[-7];
    v_27776 = v_27774;
    goto v_27737;
v_27739:
v_27737:
    goto v_27756;
v_27750:
    goto v_27762;
v_27758:
    goto v_27768;
v_27764:
    v_27775 = v_27776;
    goto v_27765;
v_27766:
    v_27774 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27767;
v_27768:
    goto v_27764;
v_27765:
    goto v_27766;
v_27767:
    fn = elt(env, 19); // to
    v_27775 = (*qfn2(fn))(fn, v_27775, v_27774);
    env = stack[-7];
    goto v_27759;
v_27760:
    v_27774 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27761;
v_27762:
    goto v_27758;
v_27759:
    goto v_27760;
v_27761:
    v_27776 = cons(v_27775, v_27774);
    env = stack[-7];
    goto v_27751;
v_27752:
    v_27775 = nil;
    goto v_27753;
v_27754:
    v_27774 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27755;
v_27756:
    goto v_27750;
v_27751:
    goto v_27752;
v_27753:
    goto v_27754;
v_27755:
    v_27774 = acons(v_27776, v_27775, v_27774);
v_27560:
    ;}  // end of a binding scope
    return onevalue(v_27774);
}



// Code for check_letop

static LispObject CC_check_letop(LispObject env,
                         LispObject v_27554)
{
    env = qenv(env);
    LispObject v_27570, v_27571;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27554);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_27570 = v_27554;
// end of prologue
    goto v_27565;
v_27561:
    v_27571 = v_27570;
    goto v_27562;
v_27563:
    v_27570 = elt(env, 1); // letop
    goto v_27564;
v_27565:
    goto v_27561;
v_27562:
    goto v_27563;
v_27564:
    fn = elt(env, 3); // freeof
    v_27570 = (*qfn2(fn))(fn, v_27571, v_27570);
    env = stack[0];
    if (v_27570 == nil) goto v_27558;
    else goto v_27559;
v_27558:
    v_27570 = elt(env, 2); // "Presence of letop, jetspace too small!"
    {
        fn = elt(env, 4); // rederr
        return (*qfn1(fn))(fn, v_27570);
    }
v_27559:
    v_27570 = nil;
    return onevalue(v_27570);
}



// Code for even_action_pow

static LispObject CC_even_action_pow(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27719, v_27720, v_27721, v_27722;
    LispObject fn;
    LispObject v_27557, v_27556, v_27555, v_27554;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "even_action_pow");
    va_start(aa, nargs);
    v_27554 = va_arg(aa, LispObject);
    v_27555 = va_arg(aa, LispObject);
    v_27556 = va_arg(aa, LispObject);
    v_27557 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_27557,v_27556,v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_27554,v_27555,v_27556,v_27557);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_27557;
    stack[-3] = v_27556;
    stack[-4] = v_27555;
    v_27722 = v_27554;
// end of prologue
    v_27719 = stack[-4];
    v_27719 = qcar(v_27719);
    v_27721 = v_27719;
    v_27719 = stack[-4];
    v_27719 = qcdr(v_27719);
    stack[-1] = v_27719;
    goto v_27579;
v_27575:
    v_27720 = v_27721;
    goto v_27576;
v_27577:
    v_27719 = v_27722;
    goto v_27578;
v_27579:
    goto v_27575;
v_27576:
    goto v_27577;
v_27578:
    v_27719 = Lassoc(nil, v_27720, v_27719);
    stack[0] = v_27719;
    if (v_27719 == nil) goto v_27574;
    goto v_27591;
v_27587:
    v_27720 = stack[-1];
    goto v_27588;
v_27589:
    v_27719 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27590;
v_27591:
    goto v_27587;
v_27588:
    goto v_27589;
v_27590:
    if (v_27720 == v_27719) goto v_27585;
    else goto v_27586;
v_27585:
    goto v_27599;
v_27595:
    v_27720 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27596;
v_27597:
    v_27719 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27598;
v_27599:
    goto v_27595;
v_27596:
    goto v_27597;
v_27598:
    v_27719 = cons(v_27720, v_27719);
    env = stack[-6];
    goto v_27584;
v_27586:
    goto v_27611;
v_27605:
    goto v_27617;
v_27613:
    goto v_27623;
v_27619:
    stack[-4] = v_27721;
    goto v_27620;
v_27621:
    v_27719 = stack[-1];
    v_27719 = sub1(v_27719);
    env = stack[-6];
    goto v_27622;
v_27623:
    goto v_27619;
v_27620:
    goto v_27621;
v_27622:
    fn = elt(env, 1); // to
    v_27720 = (*qfn2(fn))(fn, stack[-4], v_27719);
    env = stack[-6];
    goto v_27614;
v_27615:
    v_27719 = stack[-1];
    goto v_27616;
v_27617:
    goto v_27613;
v_27614:
    goto v_27615;
v_27616:
    v_27721 = cons(v_27720, v_27719);
    env = stack[-6];
    goto v_27606;
v_27607:
    v_27720 = nil;
    goto v_27608;
v_27609:
    v_27719 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27610;
v_27611:
    goto v_27605;
v_27606:
    goto v_27607;
v_27608:
    goto v_27609;
v_27610:
    v_27719 = acons(v_27721, v_27720, v_27719);
    env = stack[-6];
    goto v_27584;
    v_27719 = nil;
v_27584:
    goto v_27637;
v_27631:
    v_27721 = stack[0];
    goto v_27632;
v_27633:
    v_27720 = stack[-3];
    goto v_27634;
v_27635:
    goto v_27636;
v_27637:
    goto v_27631;
v_27632:
    goto v_27633;
v_27634:
    goto v_27635;
v_27636:
    fn = elt(env, 2); // component_action
    v_27719 = (*qfnn(fn))(fn, 3, v_27721, v_27720, v_27719);
    env = stack[-6];
    stack[0] = v_27719;
    goto v_27646;
v_27642:
    v_27720 = stack[0];
    goto v_27643;
v_27644:
    v_27719 = stack[-2];
    goto v_27645;
v_27646:
    goto v_27642;
v_27643:
    goto v_27644;
v_27645:
    {
        fn = elt(env, 3); // multsq
        return (*qfn2(fn))(fn, v_27720, v_27719);
    }
v_27574:
    goto v_27656;
v_27650:
    v_27720 = v_27721;
    goto v_27651;
v_27652:
    v_27721 = v_27722;
    goto v_27653;
v_27654:
    v_27719 = nil;
    goto v_27655;
v_27656:
    goto v_27650;
v_27651:
    goto v_27652;
v_27653:
    goto v_27654;
v_27655:
    fn = elt(env, 4); // find_active_components
    v_27719 = (*qfnn(fn))(fn, 3, v_27720, v_27721, v_27719);
    env = stack[-6];
    stack[-1] = v_27719;
    goto v_27665;
v_27661:
    v_27720 = nil;
    goto v_27662;
v_27663:
    v_27719 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27664;
v_27665:
    goto v_27661;
v_27662:
    goto v_27663;
v_27664:
    v_27719 = cons(v_27720, v_27719);
    env = stack[-6];
    stack[0] = v_27719;
    v_27719 = stack[-1];
    stack[-5] = v_27719;
v_27671:
    v_27719 = stack[-5];
    if (v_27719 == nil) goto v_27675;
    else goto v_27676;
v_27675:
    goto v_27670;
v_27676:
    v_27719 = stack[-5];
    v_27719 = qcar(v_27719);
    stack[-1] = v_27719;
    goto v_27687;
v_27683:
    v_27720 = stack[-4];
    goto v_27684;
v_27685:
    v_27719 = stack[-1];
    v_27719 = qcar(v_27719);
    goto v_27686;
v_27687:
    goto v_27683;
v_27684:
    goto v_27685;
v_27686:
    fn = elt(env, 5); // diffp
    v_27719 = (*qfn2(fn))(fn, v_27720, v_27719);
    env = stack[-6];
    goto v_27696;
v_27692:
    goto v_27693;
v_27694:
    goto v_27705;
v_27699:
    v_27721 = stack[-1];
    goto v_27700;
v_27701:
    v_27720 = stack[-3];
    goto v_27702;
v_27703:
    goto v_27704;
v_27705:
    goto v_27699;
v_27700:
    goto v_27701;
v_27702:
    goto v_27703;
v_27704:
    fn = elt(env, 2); // component_action
    v_27719 = (*qfnn(fn))(fn, 3, v_27721, v_27720, v_27719);
    env = stack[-6];
    goto v_27695;
v_27696:
    goto v_27692;
v_27693:
    goto v_27694;
v_27695:
    fn = elt(env, 6); // addsq
    v_27719 = (*qfn2(fn))(fn, stack[0], v_27719);
    env = stack[-6];
    stack[0] = v_27719;
    v_27719 = stack[-5];
    v_27719 = qcdr(v_27719);
    stack[-5] = v_27719;
    goto v_27671;
v_27670:
    goto v_27716;
v_27712:
    v_27720 = stack[0];
    goto v_27713;
v_27714:
    v_27719 = stack[-2];
    goto v_27715;
v_27716:
    goto v_27712;
v_27713:
    goto v_27714;
v_27715:
    {
        fn = elt(env, 3); // multsq
        return (*qfn2(fn))(fn, v_27720, v_27719);
    }
    return onevalue(v_27719);
}



// Code for cl_identifyonoff

static LispObject CC_cl_identifyonoff(LispObject env,
                         LispObject v_27554)
{
    env = qenv(env);
    LispObject v_27557;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27557 = v_27554;
// end of prologue
    v_27557 = nil;
    qvalue(elt(env, 1)) = v_27557; // cl_identify!-atl!*
    return onevalue(v_27557);
}



// Code for pasf_ordatp

static LispObject CC_pasf_ordatp(LispObject env,
                         LispObject v_27554, LispObject v_27555)
{
    env = qenv(env);
    LispObject v_27670, v_27671, v_27672, v_27673, v_27674, v_27675;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27554,v_27555);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_27673 = v_27555;
    v_27674 = v_27554;
// end of prologue
    v_27670 = v_27674;
    v_27670 = qcdr(v_27670);
    v_27670 = qcar(v_27670);
    v_27675 = v_27670;
    v_27670 = v_27673;
    v_27670 = qcdr(v_27670);
    v_27670 = qcar(v_27670);
    v_27672 = v_27670;
    goto v_27575;
v_27571:
    v_27671 = v_27675;
    goto v_27572;
v_27573:
    v_27670 = v_27672;
    goto v_27574;
v_27575:
    goto v_27571;
v_27572:
    goto v_27573;
v_27574:
    if (equal(v_27671, v_27670)) goto v_27570;
    goto v_27583;
v_27579:
    v_27670 = v_27675;
    goto v_27580;
v_27581:
    v_27671 = v_27672;
    goto v_27582;
v_27583:
    goto v_27579;
v_27580:
    goto v_27581;
v_27582:
    {
        fn = elt(env, 3); // ordp
        return (*qfn2(fn))(fn, v_27670, v_27671);
    }
v_27570:
    goto v_27591;
v_27587:
    goto v_27604;
v_27600:
    v_27671 = v_27674;
    goto v_27601;
v_27602:
    v_27670 = elt(env, 1); // true
    goto v_27603;
v_27604:
    goto v_27600;
v_27601:
    goto v_27602;
v_27603:
    if (v_27671 == v_27670) goto v_27598;
    else goto v_27599;
v_27598:
    v_27670 = lisp_true;
    goto v_27597;
v_27599:
    goto v_27614;
v_27610:
    v_27671 = v_27674;
    goto v_27611;
v_27612:
    v_27670 = elt(env, 2); // false
    goto v_27613;
v_27614:
    goto v_27610;
v_27611:
    goto v_27612;
v_27613:
    v_27670 = (v_27671 == v_27670 ? lisp_true : nil);
    goto v_27597;
    v_27670 = nil;
v_27597:
    if (v_27670 == nil) goto v_27595;
    v_27670 = v_27674;
    v_27672 = v_27670;
    goto v_27593;
v_27595:
    v_27670 = v_27674;
    v_27670 = qcar(v_27670);
    v_27670 = Lconsp(nil, v_27670);
    env = stack[0];
    if (v_27670 == nil) goto v_27620;
    v_27670 = v_27674;
    v_27670 = qcar(v_27670);
    v_27670 = qcar(v_27670);
    v_27672 = v_27670;
    goto v_27593;
v_27620:
    v_27670 = v_27674;
    v_27670 = qcar(v_27670);
    v_27672 = v_27670;
    goto v_27593;
    v_27672 = nil;
v_27593:
    goto v_27588;
v_27589:
    goto v_27643;
v_27639:
    v_27671 = v_27673;
    goto v_27640;
v_27641:
    v_27670 = elt(env, 1); // true
    goto v_27642;
v_27643:
    goto v_27639;
v_27640:
    goto v_27641;
v_27642:
    if (v_27671 == v_27670) goto v_27637;
    else goto v_27638;
v_27637:
    v_27670 = lisp_true;
    goto v_27636;
v_27638:
    goto v_27653;
v_27649:
    v_27671 = v_27673;
    goto v_27650;
v_27651:
    v_27670 = elt(env, 2); // false
    goto v_27652;
v_27653:
    goto v_27649;
v_27650:
    goto v_27651;
v_27652:
    v_27670 = (v_27671 == v_27670 ? lisp_true : nil);
    goto v_27636;
    v_27670 = nil;
v_27636:
    if (v_27670 == nil) goto v_27634;
    v_27670 = v_27673;
    goto v_27632;
v_27634:
    v_27670 = v_27673;
    v_27670 = qcar(v_27670);
    v_27670 = Lconsp(nil, v_27670);
    env = stack[0];
    if (v_27670 == nil) goto v_27659;
    v_27670 = v_27673;
    v_27670 = qcar(v_27670);
    v_27670 = qcar(v_27670);
    goto v_27632;
v_27659:
    v_27670 = v_27673;
    v_27670 = qcar(v_27670);
    goto v_27632;
    v_27670 = nil;
v_27632:
    goto v_27590;
v_27591:
    goto v_27587;
v_27588:
    goto v_27589;
v_27590:
    {
        fn = elt(env, 4); // pasf_ordrelp
        return (*qfn2(fn))(fn, v_27672, v_27670);
    }
    return onevalue(v_27670);
}



// Code for quotfdx

static LispObject CC_quotfdx(LispObject env,
                         LispObject v_27554, LispObject v_27555)
{
    env = qenv(env);
    LispObject v_27612, v_27613, v_27614, v_27615;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27614 = v_27555;
    v_27615 = v_27554;
// end of prologue
    goto v_27565;
v_27561:
    v_27613 = v_27615;
    goto v_27562;
v_27563:
    v_27612 = v_27614;
    goto v_27564;
v_27565:
    goto v_27561;
v_27562:
    goto v_27563;
v_27564:
    if (equal(v_27613, v_27612)) goto v_27559;
    else goto v_27560;
v_27559:
    v_27612 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27558;
v_27560:
    v_27612 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_27612)) v_27612 = nil;
    else { v_27612 = qfastgets(v_27612);
           if (v_27612 != nil) { v_27612 = elt(v_27612, 3); // field
#ifdef RECORD_GET
             if (v_27612 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_27612 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_27612 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_27612 == SPID_NOPROP) v_27612 = nil; else v_27612 = lisp_true; }}
#endif
    if (v_27612 == nil) goto v_27570;
    goto v_27578;
v_27574:
    v_27612 = v_27615;
    goto v_27575;
v_27576:
    v_27613 = v_27614;
    goto v_27577;
v_27578:
    goto v_27574;
v_27575:
    goto v_27576;
v_27577:
    {
        fn = elt(env, 2); // divd
        return (*qfn2(fn))(fn, v_27612, v_27613);
    }
v_27570:
    v_27612 = v_27615;
    if (!consp(v_27612)) goto v_27585;
    else goto v_27586;
v_27585:
    v_27612 = lisp_true;
    goto v_27584;
v_27586:
    v_27612 = v_27615;
    v_27612 = qcar(v_27612);
    v_27612 = (consp(v_27612) ? nil : lisp_true);
    goto v_27584;
    v_27612 = nil;
v_27584:
    if (v_27612 == nil) goto v_27582;
    goto v_27599;
v_27595:
    v_27612 = v_27615;
    goto v_27596;
v_27597:
    v_27613 = v_27614;
    goto v_27598;
v_27599:
    goto v_27595;
v_27596:
    goto v_27597;
v_27598:
    {
        fn = elt(env, 3); // quotdd
        return (*qfn2(fn))(fn, v_27612, v_27613);
    }
v_27582:
    goto v_27609;
v_27605:
    v_27612 = v_27615;
    goto v_27606;
v_27607:
    v_27613 = v_27614;
    goto v_27608;
v_27609:
    goto v_27605;
v_27606:
    goto v_27607;
v_27608:
    {
        fn = elt(env, 4); // quotkx
        return (*qfn2(fn))(fn, v_27612, v_27613);
    }
    v_27612 = nil;
v_27558:
    return onevalue(v_27612);
}



// Code for limitom

static LispObject CC_limitom(LispObject env,
                         LispObject v_27554)
{
    env = qenv(env);
    LispObject v_27656, v_27657, v_27658;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27554);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_27657 = v_27554;
// end of prologue
    v_27656 = v_27657;
    v_27656 = qcdr(v_27656);
    v_27656 = qcdr(v_27656);
    v_27656 = qcar(v_27656);
    stack[-2] = v_27656;
    v_27656 = v_27657;
    v_27656 = qcdr(v_27656);
    v_27656 = qcdr(v_27656);
    v_27656 = qcdr(v_27656);
    v_27656 = qcar(v_27656);
    stack[0] = v_27656;
    v_27656 = v_27657;
    v_27656 = Lreverse(nil, v_27656);
    env = stack[-4];
    v_27656 = qcar(v_27656);
    stack[-3] = v_27656;
    v_27656 = elt(env, 1); // "<OMA>"
    fn = elt(env, 10); // printout
    v_27656 = (*qfn1(fn))(fn, v_27656);
    env = stack[-4];
    v_27656 = lisp_true;
    fn = elt(env, 11); // indent!*
    v_27656 = (*qfn1(fn))(fn, v_27656);
    env = stack[-4];
    v_27656 = elt(env, 2); // "<OMS cd=""limit1"" name=""limit""/>"
    fn = elt(env, 10); // printout
    v_27656 = (*qfn1(fn))(fn, v_27656);
    env = stack[-4];
    goto v_27588;
v_27584:
    v_27656 = stack[0];
    v_27657 = qcar(v_27656);
    goto v_27585;
v_27586:
    v_27656 = elt(env, 3); // lowlimit
    goto v_27587;
v_27588:
    goto v_27584;
v_27585:
    goto v_27586;
v_27587:
    if (v_27657 == v_27656) goto v_27582;
    else goto v_27583;
v_27582:
    v_27656 = stack[0];
    v_27656 = qcdr(v_27656);
    v_27656 = qcar(v_27656);
    fn = elt(env, 12); // objectom
    v_27656 = (*qfn1(fn))(fn, v_27656);
    env = stack[-4];
    v_27656 = elt(env, 4); // "<OMS cd=""limit1"" name=""null""/>"
    fn = elt(env, 10); // printout
    v_27656 = (*qfn1(fn))(fn, v_27656);
    env = stack[-4];
    goto v_27581;
v_27583:
v_27581:
    goto v_27606;
v_27602:
    v_27656 = stack[0];
    v_27657 = qcar(v_27656);
    goto v_27603;
v_27604:
    v_27656 = elt(env, 5); // condition
    goto v_27605;
v_27606:
    goto v_27602;
v_27603:
    goto v_27604;
v_27605:
    if (v_27657 == v_27656) goto v_27600;
    else goto v_27601;
v_27600:
    v_27656 = stack[0];
    v_27656 = qcdr(v_27656);
    v_27656 = qcar(v_27656);
    v_27656 = Lreverse(nil, v_27656);
    env = stack[-4];
    v_27656 = qcar(v_27656);
    fn = elt(env, 12); // objectom
    v_27656 = (*qfn1(fn))(fn, v_27656);
    env = stack[-4];
    v_27656 = stack[0];
    v_27656 = qcdr(v_27656);
    v_27656 = qcar(v_27656);
    v_27656 = qcdr(v_27656);
    v_27656 = qcar(v_27656);
    v_27656 = qcar(v_27656);
    v_27656 = qcdr(v_27656);
    v_27656 = qcar(v_27656);
    stack[0] = v_27656;
    v_27656 = elt(env, 6); // "<OMS cd=""limit1"" name="""
    fn = elt(env, 10); // printout
    v_27656 = (*qfn1(fn))(fn, v_27656);
    env = stack[-4];
    v_27656 = stack[0];
    v_27656 = Lprinc(nil, v_27656);
    env = stack[-4];
    v_27656 = elt(env, 7); // """/>"
    v_27656 = Lprinc(nil, v_27656);
    env = stack[-4];
    goto v_27599;
v_27601:
v_27599:
    goto v_27638;
v_27632:
    stack[-1] = elt(env, 8); // limit
    goto v_27633;
v_27634:
    stack[0] = nil;
    goto v_27635;
v_27636:
    goto v_27648;
v_27642:
    v_27658 = stack[-2];
    goto v_27643;
v_27644:
    v_27657 = stack[-3];
    goto v_27645;
v_27646:
    v_27656 = nil;
    goto v_27647;
v_27648:
    goto v_27642;
v_27643:
    goto v_27644;
v_27645:
    goto v_27646;
v_27647:
    v_27656 = list2star(v_27658, v_27657, v_27656);
    env = stack[-4];
    goto v_27637;
v_27638:
    goto v_27632;
v_27633:
    goto v_27634;
v_27635:
    goto v_27636;
v_27637:
    v_27656 = list2star(stack[-1], stack[0], v_27656);
    env = stack[-4];
    fn = elt(env, 13); // lambdaom
    v_27656 = (*qfn1(fn))(fn, v_27656);
    env = stack[-4];
    v_27656 = nil;
    fn = elt(env, 11); // indent!*
    v_27656 = (*qfn1(fn))(fn, v_27656);
    env = stack[-4];
    v_27656 = elt(env, 9); // "</OMA>"
    fn = elt(env, 10); // printout
    v_27656 = (*qfn1(fn))(fn, v_27656);
    v_27656 = nil;
    return onevalue(v_27656);
}



// Code for i2ps

static LispObject CC_i2ps(LispObject env,
                         LispObject v_27554)
{
    env = qenv(env);
    LispObject v_27557;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27557 = v_27554;
// end of prologue
    return onevalue(v_27557);
}



// Code for lndepends

static LispObject CC_lndepends(LispObject env,
                         LispObject v_27554, LispObject v_27555)
{
    env = qenv(env);
    LispObject v_27597, v_27598;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27554,v_27555);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27555;
    stack[-1] = v_27554;
// end of prologue
v_27553:
    v_27597 = stack[-1];
    if (v_27597 == nil) goto v_27559;
    else goto v_27560;
v_27559:
    v_27597 = nil;
    goto v_27558;
v_27560:
    v_27597 = stack[-1];
    if (!consp(v_27597)) goto v_27563;
    else goto v_27564;
v_27563:
    goto v_27571;
v_27567:
    v_27598 = stack[-1];
    goto v_27568;
v_27569:
    v_27597 = stack[0];
    goto v_27570;
v_27571:
    goto v_27567;
v_27568:
    goto v_27569;
v_27570:
    {
        fn = elt(env, 1); // ndepends
        return (*qfn2(fn))(fn, v_27598, v_27597);
    }
v_27564:
    goto v_27584;
v_27580:
    v_27597 = stack[-1];
    v_27598 = qcar(v_27597);
    goto v_27581;
v_27582:
    v_27597 = stack[0];
    goto v_27583;
v_27584:
    goto v_27580;
v_27581:
    goto v_27582;
v_27583:
    fn = elt(env, 1); // ndepends
    v_27597 = (*qfn2(fn))(fn, v_27598, v_27597);
    env = stack[-2];
    if (v_27597 == nil) goto v_27578;
    else goto v_27577;
v_27578:
    goto v_27593;
v_27589:
    v_27597 = stack[-1];
    v_27598 = qcdr(v_27597);
    goto v_27590;
v_27591:
    v_27597 = stack[0];
    goto v_27592;
v_27593:
    goto v_27589;
v_27590:
    goto v_27591;
v_27592:
    stack[-1] = v_27598;
    stack[0] = v_27597;
    goto v_27553;
v_27577:
    goto v_27558;
    v_27597 = nil;
v_27558:
    return onevalue(v_27597);
}



// Code for split!-comfac!-part

static LispObject CC_splitKcomfacKpart(LispObject env,
                         LispObject v_27554)
{
    env = qenv(env);
    LispObject v_27567, v_27568, v_27569;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27567 = v_27554;
// end of prologue
    goto v_27563;
v_27557:
    v_27569 = v_27567;
    goto v_27558;
v_27559:
    v_27568 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27560;
v_27561:
    v_27567 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27562;
v_27563:
    goto v_27557;
v_27558:
    goto v_27559;
v_27560:
    goto v_27561;
v_27562:
    {
        fn = elt(env, 1); // split!-comfac
        return (*qfnn(fn))(fn, 3, v_27569, v_27568, v_27567);
    }
}



// Code for reduce!-weights

static LispObject CC_reduceKweights(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27642, v_27643;
    LispObject fn;
    LispObject v_27556, v_27555, v_27554;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "reduce-weights");
    va_start(aa, nargs);
    v_27554 = va_arg(aa, LispObject);
    v_27555 = va_arg(aa, LispObject);
    v_27556 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27556,v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27554,v_27555,v_27556);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_27556;
    stack[-4] = v_27555;
    stack[-5] = v_27554;
// end of prologue
    stack[-6] = nil;
    goto v_27571;
v_27567:
    v_27643 = stack[-5];
    goto v_27568;
v_27569:
    v_27642 = stack[-3];
    goto v_27570;
v_27571:
    goto v_27567;
v_27568:
    goto v_27569;
v_27570:
    fn = elt(env, 1); // red!-weight
    v_27642 = (*qfn2(fn))(fn, v_27643, v_27642);
    env = stack[-7];
    stack[-2] = v_27642;
v_27564:
    goto v_27579;
v_27575:
    v_27643 = stack[-5];
    goto v_27576;
v_27577:
    v_27642 = stack[-4];
    goto v_27578;
v_27579:
    goto v_27575;
v_27576:
    goto v_27577;
v_27578:
    fn = elt(env, 2); // mv!-domainlist!-!+
    v_27642 = (*qfn2(fn))(fn, v_27643, v_27642);
    env = stack[-7];
    stack[-1] = v_27642;
    goto v_27587;
v_27583:
    v_27643 = stack[-1];
    goto v_27584;
v_27585:
    v_27642 = stack[-3];
    goto v_27586;
v_27587:
    goto v_27583;
v_27584:
    goto v_27585;
v_27586:
    fn = elt(env, 1); // red!-weight
    v_27642 = (*qfn2(fn))(fn, v_27643, v_27642);
    env = stack[-7];
    stack[0] = v_27642;
    goto v_27599;
v_27595:
    v_27643 = stack[0];
    goto v_27596;
v_27597:
    v_27642 = stack[-2];
    goto v_27598;
v_27599:
    goto v_27595;
v_27596:
    goto v_27597;
v_27598:
    fn = elt(env, 3); // red!-weight!-less!-p
    v_27642 = (*qfn2(fn))(fn, v_27643, v_27642);
    env = stack[-7];
    if (v_27642 == nil) goto v_27593;
    v_27642 = lisp_true;
    stack[-6] = v_27642;
    v_27642 = stack[-1];
    stack[-5] = v_27642;
    v_27642 = stack[0];
    stack[-2] = v_27642;
    goto v_27564;
v_27593:
    v_27642 = stack[-6];
    if (v_27642 == nil) goto v_27608;
    v_27642 = stack[-5];
    goto v_27563;
v_27608:
v_27565:
    goto v_27616;
v_27612:
    v_27643 = stack[-5];
    goto v_27613;
v_27614:
    v_27642 = stack[-4];
    goto v_27615;
v_27616:
    goto v_27612;
v_27613:
    goto v_27614;
v_27615:
    fn = elt(env, 4); // mv!-domainlist!-!-
    v_27642 = (*qfn2(fn))(fn, v_27643, v_27642);
    env = stack[-7];
    stack[-1] = v_27642;
    goto v_27624;
v_27620:
    v_27643 = stack[-1];
    goto v_27621;
v_27622:
    v_27642 = stack[-3];
    goto v_27623;
v_27624:
    goto v_27620;
v_27621:
    goto v_27622;
v_27623:
    fn = elt(env, 1); // red!-weight
    v_27642 = (*qfn2(fn))(fn, v_27643, v_27642);
    env = stack[-7];
    stack[0] = v_27642;
    goto v_27636;
v_27632:
    v_27643 = stack[0];
    goto v_27633;
v_27634:
    v_27642 = stack[-2];
    goto v_27635;
v_27636:
    goto v_27632;
v_27633:
    goto v_27634;
v_27635:
    fn = elt(env, 3); // red!-weight!-less!-p
    v_27642 = (*qfn2(fn))(fn, v_27643, v_27642);
    env = stack[-7];
    if (v_27642 == nil) goto v_27630;
    v_27642 = stack[-1];
    stack[-5] = v_27642;
    v_27642 = stack[0];
    stack[-2] = v_27642;
    goto v_27565;
v_27630:
    v_27642 = stack[-5];
v_27563:
    return onevalue(v_27642);
}



// Code for cali_bc_from_a

static LispObject CC_cali_bc_from_a(LispObject env,
                         LispObject v_27554)
{
    env = qenv(env);
    LispObject v_27560;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27554);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_27560 = v_27554;
// end of prologue
    fn = elt(env, 1); // simp!*
    v_27560 = (*qfn1(fn))(fn, v_27560);
    env = stack[0];
    v_27560 = qcar(v_27560);
    {
        fn = elt(env, 2); // bc!=simp
        return (*qfn1(fn))(fn, v_27560);
    }
}



// Code for vecsimp!*

static LispObject CC_vecsimpH(LispObject env,
                         LispObject v_27554)
{
    env = qenv(env);
    LispObject v_27567;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27554);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27554;
// end of prologue
    v_27567 = stack[0];
    fn = elt(env, 1); // vecp
    v_27567 = (*qfn1(fn))(fn, v_27567);
    env = stack[-1];
    if (v_27567 == nil) goto v_27559;
    v_27567 = stack[0];
    {
        fn = elt(env, 2); // vecsm!*
        return (*qfn1(fn))(fn, v_27567);
    }
v_27559:
    v_27567 = stack[0];
    goto v_27557;
    v_27567 = nil;
v_27557:
    return onevalue(v_27567);
}



// Code for mkrootsq

static LispObject CC_mkrootsq(LispObject env,
                         LispObject v_27554, LispObject v_27555)
{
    env = qenv(env);
    LispObject v_27786, v_27787, v_27788;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27554,v_27555);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27555;
    stack[-1] = v_27554;
// end of prologue
    goto v_27565;
v_27561:
    v_27787 = stack[-1];
    goto v_27562;
v_27563:
    v_27786 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27564;
v_27565:
    goto v_27561;
v_27562:
    goto v_27563;
v_27564:
    if (v_27787 == v_27786) goto v_27559;
    else goto v_27560;
v_27559:
    v_27786 = (LispObject)16+TAG_FIXNUM; // 1
    {
        fn = elt(env, 8); // !*d2q
        return (*qfn1(fn))(fn, v_27786);
    }
v_27560:
    goto v_27580;
v_27576:
    v_27787 = stack[0];
    goto v_27577;
v_27578:
    v_27786 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_27579;
v_27580:
    goto v_27576;
v_27577:
    goto v_27578;
v_27579:
    if (v_27787 == v_27786) goto v_27574;
    else goto v_27575;
v_27574:
    goto v_27591;
v_27587:
    v_27787 = stack[-1];
    goto v_27588;
v_27589:
    v_27786 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_27590;
v_27591:
    goto v_27587;
v_27588:
    goto v_27589;
v_27590:
    if (v_27787 == v_27786) goto v_27585;
    else goto v_27586;
v_27585:
    v_27786 = lisp_true;
    goto v_27584;
v_27586:
    goto v_27601;
v_27597:
    v_27787 = stack[-1];
    goto v_27598;
v_27599:
    v_27786 = elt(env, 1); // (minus 1)
    goto v_27600;
v_27601:
    goto v_27597;
v_27598:
    goto v_27599;
v_27600:
    v_27786 = (equal(v_27787, v_27786) ? lisp_true : nil);
    goto v_27584;
    v_27786 = nil;
v_27584:
    goto v_27573;
v_27575:
    v_27786 = nil;
    goto v_27573;
    v_27786 = nil;
v_27573:
    if (v_27786 == nil) goto v_27571;
    v_27786 = elt(env, 2); // i
    {
        fn = elt(env, 9); // simp
        return (*qfn1(fn))(fn, v_27786);
    }
v_27571:
    goto v_27621;
v_27617:
    v_27787 = stack[-1];
    goto v_27618;
v_27619:
    v_27786 = elt(env, 3); // expt
    goto v_27620;
v_27621:
    goto v_27617;
v_27618:
    goto v_27619;
v_27620:
    if (!consp(v_27787)) goto v_27615;
    v_27787 = qcar(v_27787);
    if (v_27787 == v_27786) goto v_27614;
    else goto v_27615;
v_27614:
    v_27786 = stack[-1];
    v_27786 = qcdr(v_27786);
    v_27786 = qcdr(v_27786);
    v_27786 = qcar(v_27786);
    v_27786 = integerp(v_27786);
    if (v_27786 == nil) goto v_27626;
    else goto v_27627;
v_27626:
    v_27786 = nil;
    goto v_27625;
v_27627:
    v_27786 = qvalue(elt(env, 4)); // !*precise_complex
    v_27786 = (v_27786 == nil ? lisp_true : nil);
    goto v_27625;
    v_27786 = nil;
v_27625:
    goto v_27613;
v_27615:
    v_27786 = nil;
    goto v_27613;
    v_27786 = nil;
v_27613:
    if (v_27786 == nil) goto v_27611;
    goto v_27646;
v_27642:
    goto v_27652;
v_27648:
    v_27786 = stack[-1];
    v_27786 = qcdr(v_27786);
    v_27787 = qcar(v_27786);
    goto v_27649;
v_27650:
    v_27786 = stack[0];
    goto v_27651;
v_27652:
    goto v_27648;
v_27649:
    goto v_27650;
v_27651:
    v_27787 = CC_mkrootsq(elt(env, 0), v_27787, v_27786);
    env = stack[-3];
    goto v_27643;
v_27644:
    v_27786 = stack[-1];
    v_27786 = qcdr(v_27786);
    v_27786 = qcdr(v_27786);
    v_27786 = qcar(v_27786);
    goto v_27645;
v_27646:
    goto v_27642;
v_27643:
    goto v_27644;
v_27645:
    {
        fn = elt(env, 10); // exptsq
        return (*qfn2(fn))(fn, v_27787, v_27786);
    }
v_27611:
    stack[-2] = nil;
    v_27786 = stack[-1];
    v_27786 = integerp(v_27786);
    if (v_27786 == nil) goto v_27670;
    v_27786 = stack[-1];
    v_27786 = Lminusp(nil, v_27786);
    env = stack[-3];
    if (v_27786 == nil) goto v_27677;
    else goto v_27678;
v_27677:
    goto v_27689;
v_27685:
    goto v_27696;
v_27692:
    stack[-2] = stack[-1];
    goto v_27693;
v_27694:
    goto v_27706;
v_27702:
    v_27787 = stack[-1];
    goto v_27703;
v_27704:
    v_27786 = qvalue(elt(env, 5)); // factorbound!*
    goto v_27705;
v_27706:
    goto v_27702;
v_27703:
    goto v_27704;
v_27705:
    v_27786 = (LispObject)lessp2(v_27787, v_27786);
    v_27786 = v_27786 ? lisp_true : nil;
    env = stack[-3];
    if (v_27786 == nil) goto v_27700;
    else goto v_27699;
v_27700:
    v_27786 = qvalue(elt(env, 6)); // !*ifactor
v_27699:
    goto v_27695;
v_27696:
    goto v_27692;
v_27693:
    goto v_27694;
v_27695:
    fn = elt(env, 11); // zfactor1
    v_27786 = (*qfn2(fn))(fn, stack[-2], v_27786);
    env = stack[-3];
    stack[-2] = v_27786;
    v_27787 = Llength(nil, v_27786);
    env = stack[-3];
    goto v_27686;
v_27687:
    v_27786 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27688;
v_27689:
    goto v_27685;
v_27686:
    goto v_27687;
v_27688:
    v_27786 = (LispObject)greaterp2(v_27787, v_27786);
    v_27786 = v_27786 ? lisp_true : nil;
    env = stack[-3];
    if (v_27786 == nil) goto v_27683;
    else goto v_27682;
v_27683:
    goto v_27716;
v_27712:
    v_27786 = stack[-2];
    v_27786 = qcar(v_27786);
    v_27787 = qcdr(v_27786);
    goto v_27713;
v_27714:
    v_27786 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27715;
v_27716:
    goto v_27712;
v_27713:
    goto v_27714;
v_27715:
    v_27786 = (LispObject)greaterp2(v_27787, v_27786);
    v_27786 = v_27786 ? lisp_true : nil;
    env = stack[-3];
v_27682:
    goto v_27676;
v_27678:
    v_27786 = nil;
    goto v_27676;
    v_27786 = nil;
v_27676:
    if (v_27786 == nil) goto v_27670;
    goto v_27729;
v_27725:
    v_27787 = stack[-2];
    goto v_27726;
v_27727:
    v_27786 = stack[0];
    goto v_27728;
v_27729:
    goto v_27725;
v_27726:
    goto v_27727;
v_27728:
    {
        fn = elt(env, 12); // mkrootsql
        return (*qfn2(fn))(fn, v_27787, v_27786);
    }
v_27670:
    goto v_27740;
v_27736:
    v_27787 = stack[0];
    goto v_27737;
v_27738:
    v_27786 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_27739;
v_27740:
    goto v_27736;
v_27737:
    goto v_27738;
v_27739:
    if (v_27787 == v_27786) goto v_27734;
    else goto v_27735;
v_27734:
    v_27786 = stack[-1];
    fn = elt(env, 13); // mksqrt
    v_27786 = (*qfn1(fn))(fn, v_27786);
    env = stack[-3];
    goto v_27733;
v_27735:
    goto v_27754;
v_27748:
    stack[-2] = elt(env, 3); // expt
    goto v_27749;
v_27750:
    goto v_27751;
v_27752:
    goto v_27764;
v_27758:
    v_27788 = elt(env, 7); // quotient
    goto v_27759;
v_27760:
    v_27787 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27761;
v_27762:
    v_27786 = stack[0];
    goto v_27763;
v_27764:
    goto v_27758;
v_27759:
    goto v_27760;
v_27761:
    goto v_27762;
v_27763:
    v_27786 = list3(v_27788, v_27787, v_27786);
    env = stack[-3];
    goto v_27753;
v_27754:
    goto v_27748;
v_27749:
    goto v_27750;
v_27751:
    goto v_27752;
v_27753:
    v_27786 = list3(stack[-2], stack[-1], v_27786);
    env = stack[-3];
    goto v_27733;
    v_27786 = nil;
v_27733:
    stack[-2] = v_27786;
    v_27786 = stack[-2];
    fn = elt(env, 14); // opmtch
    v_27786 = (*qfn1(fn))(fn, v_27786);
    env = stack[-3];
    v_27787 = v_27786;
    if (v_27786 == nil) goto v_27771;
    v_27786 = v_27787;
    {
        fn = elt(env, 9); // simp
        return (*qfn1(fn))(fn, v_27786);
    }
v_27771:
    goto v_27783;
v_27779:
    v_27787 = stack[-2];
    goto v_27780;
v_27781:
    v_27786 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27782;
v_27783:
    goto v_27779;
v_27780:
    goto v_27781;
v_27782:
    {
        fn = elt(env, 15); // mksq
        return (*qfn2(fn))(fn, v_27787, v_27786);
    }
    v_27786 = nil;
    goto v_27558;
    v_27786 = nil;
v_27558:
    return onevalue(v_27786);
}



// Code for count!-linear!-factors!-mod!-p

static LispObject CC_countKlinearKfactorsKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27878, v_27879, v_27880, v_27881, v_27882;
    LispObject fn;
    LispObject v_27556, v_27555, v_27554;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "count-linear-factors-mod-p");
    va_start(aa, nargs);
    v_27554 = va_arg(aa, LispObject);
    v_27555 = va_arg(aa, LispObject);
    v_27556 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27556,v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27554,v_27555,v_27556);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_27556;
    stack[-2] = v_27555;
    stack[-3] = v_27554;
// end of prologue
// Binding linear!-factors
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 1, 0);
    qvalue(elt(env, 1)) = nil; // linear!-factors
    v_27878 = (LispObject)0+TAG_FIXNUM; // 0
    v_27882 = v_27878;
v_27566:
    goto v_27576;
v_27572:
    v_27879 = qvalue(elt(env, 2)); // dpoly
    goto v_27573;
v_27574:
    v_27878 = v_27882;
    goto v_27575;
v_27576:
    goto v_27572;
v_27573:
    goto v_27574;
v_27575:
    v_27878 = (LispObject)(intptr_t)((intptr_t)v_27879 - (intptr_t)v_27878 + TAG_FIXNUM);
    v_27878 = ((intptr_t)(v_27878) < 0 ? lisp_true : nil);
    if (v_27878 == nil) goto v_27571;
    goto v_27565;
v_27571:
    goto v_27588;
v_27582:
    v_27881 = stack[-2];
    goto v_27583;
v_27584:
    v_27880 = v_27882;
    goto v_27585;
v_27586:
    goto v_27595;
v_27591:
    v_27879 = qvalue(elt(env, 3)); // poly!-vector
    goto v_27592;
v_27593:
    v_27878 = v_27882;
    goto v_27594;
v_27595:
    goto v_27591;
v_27592:
    goto v_27593;
v_27594:
    v_27878 = *(LispObject *)((char *)v_27879 + (CELL-TAG_VECTOR) + (((intptr_t)v_27878-TAG_FIXNUM)/(16/CELL)));
    goto v_27587;
v_27588:
    goto v_27582;
v_27583:
    goto v_27584;
v_27585:
    goto v_27586;
v_27587:
    *(LispObject *)((char *)v_27881 + (CELL-TAG_VECTOR) + (((intptr_t)v_27880-TAG_FIXNUM)/(16/CELL))) = v_27878;
    v_27878 = v_27882;
    v_27878 = (LispObject)((intptr_t)(v_27878) + 0x10);
    v_27882 = v_27878;
    goto v_27566;
v_27565:
    goto v_27608;
v_27602:
    v_27880 = qvalue(elt(env, 4)); // current!-modulus
    goto v_27603;
v_27604:
    v_27879 = stack[-3];
    goto v_27605;
v_27606:
    v_27878 = stack[-1];
    goto v_27607;
v_27608:
    goto v_27602;
v_27603:
    goto v_27604;
v_27605:
    goto v_27606;
v_27607:
    fn = elt(env, 5); // make!-x!-to!-p
    v_27878 = (*qfnn(fn))(fn, 3, v_27880, v_27879, v_27878);
    env = stack[-5];
    stack[-4] = v_27878;
    v_27878 = (LispObject)0+TAG_FIXNUM; // 0
    v_27882 = v_27878;
v_27615:
    goto v_27625;
v_27621:
    v_27879 = stack[-4];
    goto v_27622;
v_27623:
    v_27878 = v_27882;
    goto v_27624;
v_27625:
    goto v_27621;
v_27622:
    goto v_27623;
v_27624:
    v_27878 = (LispObject)(intptr_t)((intptr_t)v_27879 - (intptr_t)v_27878 + TAG_FIXNUM);
    v_27878 = ((intptr_t)(v_27878) < 0 ? lisp_true : nil);
    if (v_27878 == nil) goto v_27620;
    goto v_27614;
v_27620:
    goto v_27637;
v_27631:
    v_27881 = stack[-3];
    goto v_27632;
v_27633:
    v_27880 = v_27882;
    goto v_27634;
v_27635:
    goto v_27644;
v_27640:
    v_27879 = stack[-1];
    goto v_27641;
v_27642:
    v_27878 = v_27882;
    goto v_27643;
v_27644:
    goto v_27640;
v_27641:
    goto v_27642;
v_27643:
    v_27878 = *(LispObject *)((char *)v_27879 + (CELL-TAG_VECTOR) + (((intptr_t)v_27878-TAG_FIXNUM)/(16/CELL)));
    goto v_27636;
v_27637:
    goto v_27631;
v_27632:
    goto v_27633;
v_27634:
    goto v_27635;
v_27636:
    *(LispObject *)((char *)v_27881 + (CELL-TAG_VECTOR) + (((intptr_t)v_27880-TAG_FIXNUM)/(16/CELL))) = v_27878;
    v_27878 = v_27882;
    v_27878 = (LispObject)((intptr_t)(v_27878) + 0x10);
    v_27882 = v_27878;
    goto v_27615;
v_27614:
    goto v_27658;
v_27654:
    v_27879 = stack[-4];
    goto v_27655;
v_27656:
    v_27878 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27657;
v_27658:
    goto v_27654;
v_27655:
    goto v_27656;
v_27657:
    if (((intptr_t)(v_27879)) < ((intptr_t)(v_27878))) goto v_27652;
    else goto v_27653;
v_27652:
    goto v_27669;
v_27665:
    v_27879 = stack[-4];
    goto v_27666;
v_27667:
    v_27878 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27668;
v_27669:
    goto v_27665;
v_27666:
    goto v_27667;
v_27668:
    if (((intptr_t)(v_27879)) < ((intptr_t)(v_27878))) goto v_27663;
    else goto v_27664;
v_27663:
    goto v_27678;
v_27672:
    v_27880 = stack[-3];
    goto v_27673;
v_27674:
    v_27879 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27675;
v_27676:
    v_27878 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27677;
v_27678:
    goto v_27672;
v_27673:
    goto v_27674;
v_27675:
    goto v_27676;
v_27677:
    *(LispObject *)((char *)v_27880 + (CELL-TAG_VECTOR) + (((intptr_t)v_27879-TAG_FIXNUM)/(16/CELL))) = v_27878;
    goto v_27662;
v_27664:
v_27662:
    goto v_27688;
v_27682:
    v_27880 = stack[-3];
    goto v_27683;
v_27684:
    v_27879 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27685;
v_27686:
    v_27878 = (LispObject)16+TAG_FIXNUM; // 1
    {   intptr_t w = int_of_fixnum(v_27878);
        if (w != 0) w = current_modulus - w;
        v_27878 = fixnum_of_int(w);
    }
    goto v_27687;
v_27688:
    goto v_27682;
v_27683:
    goto v_27684;
v_27685:
    goto v_27686;
v_27687:
    *(LispObject *)((char *)v_27880 + (CELL-TAG_VECTOR) + (((intptr_t)v_27879-TAG_FIXNUM)/(16/CELL))) = v_27878;
    v_27878 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_27878;
    goto v_27651;
v_27653:
    goto v_27702;
v_27696:
    v_27881 = stack[-3];
    goto v_27697;
v_27698:
    v_27880 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27699;
v_27700:
    goto v_27709;
v_27705:
    goto v_27714;
v_27710:
    v_27879 = stack[-3];
    goto v_27711;
v_27712:
    v_27878 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27713;
v_27714:
    goto v_27710;
v_27711:
    goto v_27712;
v_27713:
    v_27879 = *(LispObject *)((char *)v_27879 + (CELL-TAG_VECTOR) + (((intptr_t)v_27878-TAG_FIXNUM)/(16/CELL)));
    goto v_27706;
v_27707:
    v_27878 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27708;
v_27709:
    goto v_27705;
v_27706:
    goto v_27707;
v_27708:
    {   intptr_t w = int_of_fixnum(v_27879) - int_of_fixnum(v_27878);
        if (w < 0) w += current_modulus;
        v_27878 = fixnum_of_int(w);
    }
    goto v_27701;
v_27702:
    goto v_27696;
v_27697:
    goto v_27698;
v_27699:
    goto v_27700;
v_27701:
    *(LispObject *)((char *)v_27881 + (CELL-TAG_VECTOR) + (((intptr_t)v_27880-TAG_FIXNUM)/(16/CELL))) = v_27878;
    goto v_27732;
v_27728:
    v_27879 = stack[-4];
    goto v_27729;
v_27730:
    v_27878 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27731;
v_27732:
    goto v_27728;
v_27729:
    goto v_27730;
v_27731:
    if (v_27879 == v_27878) goto v_27726;
    else goto v_27727;
v_27726:
    goto v_27739;
v_27735:
    goto v_27744;
v_27740:
    v_27879 = stack[-3];
    goto v_27741;
v_27742:
    v_27878 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27743;
v_27744:
    goto v_27740;
v_27741:
    goto v_27742;
v_27743:
    v_27879 = *(LispObject *)((char *)v_27879 + (CELL-TAG_VECTOR) + (((intptr_t)v_27878-TAG_FIXNUM)/(16/CELL)));
    goto v_27736;
v_27737:
    v_27878 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27738;
v_27739:
    goto v_27735;
v_27736:
    goto v_27737;
v_27738:
    v_27878 = (v_27879 == v_27878 ? lisp_true : nil);
    goto v_27725;
v_27727:
    v_27878 = nil;
    goto v_27725;
    v_27878 = nil;
v_27725:
    if (v_27878 == nil) goto v_27723;
    goto v_27761;
v_27757:
    goto v_27766;
v_27762:
    v_27879 = stack[-3];
    goto v_27763;
v_27764:
    v_27878 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27765;
v_27766:
    goto v_27762;
v_27763:
    goto v_27764;
v_27765:
    v_27879 = *(LispObject *)((char *)v_27879 + (CELL-TAG_VECTOR) + (((intptr_t)v_27878-TAG_FIXNUM)/(16/CELL)));
    goto v_27758;
v_27759:
    v_27878 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27760;
v_27761:
    goto v_27757;
v_27758:
    goto v_27759;
v_27760:
    if (v_27879 == v_27878) goto v_27755;
    else goto v_27756;
v_27755:
    v_27878 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[-4] = v_27878;
    goto v_27754;
v_27756:
    v_27878 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_27878;
    goto v_27754;
v_27754:
    goto v_27721;
v_27723:
v_27721:
    goto v_27651;
v_27651:
    goto v_27783;
v_27779:
    v_27879 = stack[-4];
    goto v_27780;
v_27781:
    v_27878 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27782;
v_27783:
    goto v_27779;
v_27780:
    goto v_27781;
v_27782:
    if (((intptr_t)(v_27879)) < ((intptr_t)(v_27878))) goto v_27777;
    else goto v_27778;
v_27777:
    goto v_27793;
v_27787:
    v_27880 = stack[-2];
    goto v_27788;
v_27789:
    v_27879 = qvalue(elt(env, 2)); // dpoly
    goto v_27790;
v_27791:
    v_27878 = stack[-3];
    goto v_27792;
v_27793:
    goto v_27787;
v_27788:
    goto v_27789;
v_27790:
    goto v_27791;
v_27792:
    fn = elt(env, 6); // copy!-vector
    v_27878 = (*qfnn(fn))(fn, 3, v_27880, v_27879, v_27878);
    env = stack[-5];
    stack[-1] = v_27878;
    goto v_27776;
v_27778:
    goto v_27808;
v_27800:
    v_27881 = stack[-3];
    goto v_27801;
v_27802:
    v_27880 = stack[-4];
    goto v_27803;
v_27804:
    v_27879 = stack[-2];
    goto v_27805;
v_27806:
    v_27878 = qvalue(elt(env, 2)); // dpoly
    goto v_27807;
v_27808:
    goto v_27800;
v_27801:
    goto v_27802;
v_27803:
    goto v_27804;
v_27805:
    goto v_27806;
v_27807:
    fn = elt(env, 7); // gcd!-in!-vector
    v_27878 = (*qfnn(fn))(fn, 4, v_27881, v_27880, v_27879, v_27878);
    env = stack[-5];
    stack[-1] = v_27878;
    goto v_27776;
v_27776:
    v_27878 = stack[-1];
    v_27878 = Lmkvect(nil, v_27878);
    env = stack[-5];
    qvalue(elt(env, 1)) = v_27878; // linear!-factors
    v_27878 = (LispObject)0+TAG_FIXNUM; // 0
    v_27882 = v_27878;
v_27818:
    goto v_27828;
v_27824:
    v_27879 = stack[-1];
    goto v_27825;
v_27826:
    v_27878 = v_27882;
    goto v_27827;
v_27828:
    goto v_27824;
v_27825:
    goto v_27826;
v_27827:
    v_27878 = (LispObject)(intptr_t)((intptr_t)v_27879 - (intptr_t)v_27878 + TAG_FIXNUM);
    v_27878 = ((intptr_t)(v_27878) < 0 ? lisp_true : nil);
    if (v_27878 == nil) goto v_27823;
    goto v_27817;
v_27823:
    goto v_27840;
v_27834:
    v_27881 = qvalue(elt(env, 1)); // linear!-factors
    goto v_27835;
v_27836:
    v_27880 = v_27882;
    goto v_27837;
v_27838:
    goto v_27847;
v_27843:
    v_27879 = stack[-3];
    goto v_27844;
v_27845:
    v_27878 = v_27882;
    goto v_27846;
v_27847:
    goto v_27843;
v_27844:
    goto v_27845;
v_27846:
    v_27878 = *(LispObject *)((char *)v_27879 + (CELL-TAG_VECTOR) + (((intptr_t)v_27878-TAG_FIXNUM)/(16/CELL)));
    goto v_27839;
v_27840:
    goto v_27834;
v_27835:
    goto v_27836;
v_27837:
    goto v_27838;
v_27839:
    *(LispObject *)((char *)v_27881 + (CELL-TAG_VECTOR) + (((intptr_t)v_27880-TAG_FIXNUM)/(16/CELL))) = v_27878;
    v_27878 = v_27882;
    v_27878 = (LispObject)((intptr_t)(v_27878) + 0x10);
    v_27882 = v_27878;
    goto v_27818;
v_27817:
    goto v_27862;
v_27854:
    v_27881 = qvalue(elt(env, 3)); // poly!-vector
    goto v_27855;
v_27856:
    v_27880 = qvalue(elt(env, 2)); // dpoly
    goto v_27857;
v_27858:
    v_27879 = qvalue(elt(env, 1)); // linear!-factors
    goto v_27859;
v_27860:
    v_27878 = stack[-1];
    goto v_27861;
v_27862:
    goto v_27854;
v_27855:
    goto v_27856;
v_27857:
    goto v_27858;
v_27859:
    goto v_27860;
v_27861:
    fn = elt(env, 8); // quotfail!-in!-vector
    v_27878 = (*qfnn(fn))(fn, 4, v_27881, v_27880, v_27879, v_27878);
    env = stack[-5];
    qvalue(elt(env, 2)) = v_27878; // dpoly
    goto v_27874;
v_27868:
    v_27880 = stack[-1];
    goto v_27869;
v_27870:
    v_27879 = qvalue(elt(env, 1)); // linear!-factors
    goto v_27871;
v_27872:
    v_27878 = stack[-4];
    goto v_27873;
v_27874:
    goto v_27868;
v_27869:
    goto v_27870;
v_27871:
    goto v_27872;
v_27873:
    v_27878 = list3(v_27880, v_27879, v_27878);
    ;}  // end of a binding scope
    return onevalue(v_27878);
}



// Code for ofsf_facequal

static LispObject CC_ofsf_facequal(LispObject env,
                         LispObject v_27554)
{
    env = qenv(env);
    LispObject v_27660, v_27661, v_27662;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27554);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_27660 = v_27554;
// end of prologue
    fn = elt(env, 6); // fctrf
    v_27660 = (*qfn1(fn))(fn, v_27660);
    env = stack[-4];
    v_27660 = qcdr(v_27660);
    stack[-3] = v_27660;
    v_27660 = stack[-3];
    if (v_27660 == nil) goto v_27567;
    else goto v_27568;
v_27567:
    v_27660 = nil;
    goto v_27560;
v_27568:
    v_27660 = stack[-3];
    v_27660 = qcar(v_27660);
    goto v_27582;
v_27576:
    v_27662 = elt(env, 1); // equal
    goto v_27577;
v_27578:
    v_27661 = qcar(v_27660);
    goto v_27579;
v_27580:
    v_27660 = nil;
    goto v_27581;
v_27582:
    goto v_27576;
v_27577:
    goto v_27578;
v_27579:
    goto v_27580;
v_27581:
    v_27660 = list3(v_27662, v_27661, v_27660);
    env = stack[-4];
    v_27660 = ncons(v_27660);
    env = stack[-4];
    stack[-1] = v_27660;
    stack[-2] = v_27660;
v_27561:
    v_27660 = stack[-3];
    v_27660 = qcdr(v_27660);
    stack[-3] = v_27660;
    v_27660 = stack[-3];
    if (v_27660 == nil) goto v_27591;
    else goto v_27592;
v_27591:
    v_27660 = stack[-2];
    goto v_27560;
v_27592:
    goto v_27600;
v_27596:
    stack[0] = stack[-1];
    goto v_27597;
v_27598:
    v_27660 = stack[-3];
    v_27660 = qcar(v_27660);
    goto v_27613;
v_27607:
    v_27662 = elt(env, 1); // equal
    goto v_27608;
v_27609:
    v_27661 = qcar(v_27660);
    goto v_27610;
v_27611:
    v_27660 = nil;
    goto v_27612;
v_27613:
    goto v_27607;
v_27608:
    goto v_27609;
v_27610:
    goto v_27611;
v_27612:
    v_27660 = list3(v_27662, v_27661, v_27660);
    env = stack[-4];
    v_27660 = ncons(v_27660);
    env = stack[-4];
    goto v_27599;
v_27600:
    goto v_27596;
v_27597:
    goto v_27598;
v_27599:
    v_27660 = Lrplacd(nil, stack[0], v_27660);
    env = stack[-4];
    v_27660 = stack[-1];
    v_27660 = qcdr(v_27660);
    stack[-1] = v_27660;
    goto v_27561;
v_27560:
    v_27661 = v_27660;
    v_27660 = v_27661;
    if (v_27660 == nil) goto v_27624;
    v_27660 = v_27661;
    v_27660 = qcdr(v_27660);
    if (v_27660 == nil) goto v_27624;
    goto v_27635;
v_27631:
    v_27660 = elt(env, 2); // or
    goto v_27632;
v_27633:
    goto v_27634;
v_27635:
    goto v_27631;
v_27632:
    goto v_27633;
v_27634:
    return cons(v_27660, v_27661);
v_27624:
    v_27660 = v_27661;
    if (v_27660 == nil) goto v_27638;
    else goto v_27639;
v_27638:
    goto v_27649;
v_27645:
    v_27661 = elt(env, 2); // or
    goto v_27646;
v_27647:
    v_27660 = elt(env, 3); // and
    goto v_27648;
v_27649:
    goto v_27645;
v_27646:
    goto v_27647;
v_27648:
    if (v_27661 == v_27660) goto v_27643;
    else goto v_27644;
v_27643:
    v_27660 = elt(env, 4); // true
    goto v_27642;
v_27644:
    v_27660 = elt(env, 5); // false
    goto v_27642;
    v_27660 = nil;
v_27642:
    goto v_27622;
v_27639:
    v_27660 = v_27661;
    v_27660 = qcar(v_27660);
    goto v_27622;
    v_27660 = nil;
v_27622:
    return onevalue(v_27660);
}



// Code for even_action

static LispObject CC_even_action(LispObject env,
                         LispObject v_27554, LispObject v_27555)
{
    env = qenv(env);
    LispObject v_27608, v_27609, v_27610, v_27611;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27554,v_27555);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27555;
    stack[-1] = v_27554;
// end of prologue
    goto v_27565;
v_27561:
    v_27609 = nil;
    goto v_27562;
v_27563:
    v_27608 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27564;
v_27565:
    goto v_27561;
v_27562:
    goto v_27563;
v_27564:
    v_27608 = cons(v_27609, v_27608);
    env = stack[-3];
    v_27609 = v_27608;
    v_27608 = stack[0];
    stack[-2] = v_27608;
v_27571:
    v_27608 = stack[-2];
    if (v_27608 == nil) goto v_27575;
    else goto v_27576;
v_27575:
    goto v_27570;
v_27576:
    v_27608 = stack[-2];
    v_27608 = qcar(v_27608);
    goto v_27587;
v_27583:
    stack[0] = v_27609;
    goto v_27584;
v_27585:
    goto v_27598;
v_27590:
    v_27611 = stack[-1];
    goto v_27591;
v_27592:
    v_27609 = v_27608;
    v_27610 = qcdr(v_27609);
    goto v_27593;
v_27594:
    v_27609 = qcar(v_27608);
    goto v_27595;
v_27596:
    v_27608 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27597;
v_27598:
    goto v_27590;
v_27591:
    goto v_27592;
v_27593:
    goto v_27594;
v_27595:
    goto v_27596;
v_27597:
    fn = elt(env, 1); // even_action_sf
    v_27608 = (*qfnn(fn))(fn, 4, v_27611, v_27610, v_27609, v_27608);
    env = stack[-3];
    goto v_27586;
v_27587:
    goto v_27583;
v_27584:
    goto v_27585;
v_27586:
    fn = elt(env, 2); // addsq
    v_27608 = (*qfn2(fn))(fn, stack[0], v_27608);
    env = stack[-3];
    v_27609 = v_27608;
    v_27608 = stack[-2];
    v_27608 = qcdr(v_27608);
    stack[-2] = v_27608;
    goto v_27571;
v_27570:
    v_27608 = v_27609;
    return onevalue(v_27608);
}



// Code for checkexp

static LispObject CC_checkexp(LispObject env,
                         LispObject v_27554, LispObject v_27555)
{
    env = qenv(env);
    LispObject v_27593, v_27594, v_27595, v_27596;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27554,v_27555);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_27595 = v_27555;
    v_27596 = v_27554;
// end of prologue
    goto v_27565;
v_27561:
    v_27594 = v_27595;
    goto v_27562;
v_27563:
    v_27593 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27564;
v_27565:
    goto v_27561;
v_27562:
    goto v_27563;
v_27564:
    if (v_27594 == v_27593) goto v_27559;
    else goto v_27560;
v_27559:
    v_27593 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27558;
v_27560:
    goto v_27575;
v_27571:
    v_27594 = v_27595;
    goto v_27572;
v_27573:
    v_27593 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27574;
v_27575:
    goto v_27571;
v_27572:
    goto v_27573;
v_27574:
    if (v_27594 == v_27593) goto v_27569;
    else goto v_27570;
v_27569:
    v_27593 = v_27596;
    goto v_27558;
v_27570:
    goto v_27588;
v_27582:
    stack[-1] = elt(env, 1); // expt
    goto v_27583;
v_27584:
    stack[0] = v_27596;
    goto v_27585;
v_27586:
    v_27593 = v_27595;
    fn = elt(env, 2); // preptayexp
    v_27593 = (*qfn1(fn))(fn, v_27593);
    goto v_27587;
v_27588:
    goto v_27582;
v_27583:
    goto v_27584;
v_27585:
    goto v_27586;
v_27587:
    {
        LispObject v_27599 = stack[-1];
        LispObject v_27600 = stack[0];
        return list3(v_27599, v_27600, v_27593);
    }
    v_27593 = nil;
v_27558:
    return onevalue(v_27593);
}



// Code for f2df

static LispObject CC_f2df(LispObject env,
                         LispObject v_27554)
{
    env = qenv(env);
    LispObject v_27670, v_27671, v_27672;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27554);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27554;
// end of prologue
    v_27670 = stack[0];
    if (!consp(v_27670)) goto v_27562;
    else goto v_27563;
v_27562:
    v_27670 = lisp_true;
    goto v_27561;
v_27563:
    v_27670 = stack[0];
    v_27670 = qcar(v_27670);
    v_27670 = (consp(v_27670) ? nil : lisp_true);
    goto v_27561;
    v_27670 = nil;
v_27561:
    if (v_27670 == nil) goto v_27559;
    goto v_27577;
v_27573:
    v_27671 = stack[0];
    goto v_27574;
v_27575:
    v_27670 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27576;
v_27577:
    goto v_27573;
v_27574:
    goto v_27575;
v_27576:
    v_27670 = cons(v_27671, v_27670);
    env = stack[-2];
    {
        fn = elt(env, 2); // dfconst
        return (*qfn1(fn))(fn, v_27670);
    }
v_27559:
    goto v_27586;
v_27582:
    v_27670 = stack[0];
    v_27670 = qcar(v_27670);
    v_27670 = qcar(v_27670);
    v_27671 = qcar(v_27670);
    goto v_27583;
v_27584:
    v_27670 = qvalue(elt(env, 1)); // zlist
    goto v_27585;
v_27586:
    goto v_27582;
v_27583:
    goto v_27584;
v_27585:
    v_27670 = Lmember(nil, v_27671, v_27670);
    if (v_27670 == nil) goto v_27581;
    goto v_27598;
v_27594:
    goto v_27604;
v_27600:
    goto v_27612;
v_27606:
    v_27670 = stack[0];
    v_27670 = qcar(v_27670);
    v_27670 = qcar(v_27670);
    v_27672 = qcar(v_27670);
    goto v_27607;
v_27608:
    v_27670 = stack[0];
    v_27670 = qcar(v_27670);
    v_27670 = qcar(v_27670);
    v_27671 = qcdr(v_27670);
    goto v_27609;
v_27610:
    v_27670 = qvalue(elt(env, 1)); // zlist
    goto v_27611;
v_27612:
    goto v_27606;
v_27607:
    goto v_27608;
v_27609:
    goto v_27610;
v_27611:
    fn = elt(env, 3); // vp2df
    stack[-1] = (*qfnn(fn))(fn, 3, v_27672, v_27671, v_27670);
    env = stack[-2];
    goto v_27601;
v_27602:
    v_27670 = stack[0];
    v_27670 = qcar(v_27670);
    v_27670 = qcdr(v_27670);
    v_27670 = CC_f2df(elt(env, 0), v_27670);
    env = stack[-2];
    goto v_27603;
v_27604:
    goto v_27600;
v_27601:
    goto v_27602;
v_27603:
    fn = elt(env, 4); // multdf
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_27670);
    env = stack[-2];
    goto v_27595;
v_27596:
    v_27670 = stack[0];
    v_27670 = qcdr(v_27670);
    v_27670 = CC_f2df(elt(env, 0), v_27670);
    env = stack[-2];
    goto v_27597;
v_27598:
    goto v_27594;
v_27595:
    goto v_27596;
v_27597:
    {
        LispObject v_27675 = stack[-1];
        fn = elt(env, 5); // plusdf
        return (*qfn2(fn))(fn, v_27675, v_27670);
    }
v_27581:
    goto v_27636;
v_27632:
    goto v_27642;
v_27638:
    goto v_27650;
v_27644:
    goto v_27656;
v_27652:
    v_27670 = stack[0];
    v_27670 = qcar(v_27670);
    v_27671 = qcar(v_27670);
    goto v_27653;
v_27654:
    v_27670 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27655;
v_27656:
    goto v_27652;
v_27653:
    goto v_27654;
v_27655:
    v_27672 = cons(v_27671, v_27670);
    env = stack[-2];
    goto v_27645;
v_27646:
    v_27671 = nil;
    goto v_27647;
v_27648:
    v_27670 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27649;
v_27650:
    goto v_27644;
v_27645:
    goto v_27646;
v_27647:
    goto v_27648;
v_27649:
    stack[-1] = acons(v_27672, v_27671, v_27670);
    env = stack[-2];
    goto v_27639;
v_27640:
    v_27670 = stack[0];
    v_27670 = qcar(v_27670);
    v_27670 = qcdr(v_27670);
    v_27670 = CC_f2df(elt(env, 0), v_27670);
    env = stack[-2];
    goto v_27641;
v_27642:
    goto v_27638;
v_27639:
    goto v_27640;
v_27641:
    fn = elt(env, 6); // multdfconst
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_27670);
    env = stack[-2];
    goto v_27633;
v_27634:
    v_27670 = stack[0];
    v_27670 = qcdr(v_27670);
    v_27670 = CC_f2df(elt(env, 0), v_27670);
    env = stack[-2];
    goto v_27635;
v_27636:
    goto v_27632;
v_27633:
    goto v_27634;
v_27635:
    {
        LispObject v_27676 = stack[-1];
        fn = elt(env, 5); // plusdf
        return (*qfn2(fn))(fn, v_27676, v_27670);
    }
    v_27670 = nil;
    return onevalue(v_27670);
}



// Code for mksfpf

static LispObject CC_mksfpf(LispObject env,
                         LispObject v_27554, LispObject v_27555)
{
    env = qenv(env);
    LispObject v_27687, v_27688;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27555,v_27554);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27554,v_27555);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27555;
    v_27687 = v_27554;
// end of prologue
    fn = elt(env, 3); // mkprod
    v_27687 = (*qfn1(fn))(fn, v_27687);
    env = stack[-2];
    stack[-1] = v_27687;
    goto v_27568;
v_27564:
    v_27688 = stack[0];
    goto v_27565;
v_27566:
    v_27687 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27567;
v_27568:
    goto v_27564;
v_27565:
    goto v_27566;
v_27567:
    if (v_27688 == v_27687) goto v_27562;
    else goto v_27563;
v_27562:
    v_27687 = stack[-1];
    goto v_27561;
v_27563:
    v_27687 = stack[-1];
    if (!consp(v_27687)) goto v_27576;
    else goto v_27577;
v_27576:
    v_27687 = lisp_true;
    goto v_27575;
v_27577:
    v_27687 = stack[-1];
    v_27687 = qcar(v_27687);
    v_27687 = (consp(v_27687) ? nil : lisp_true);
    goto v_27575;
    v_27687 = nil;
v_27575:
    if (v_27687 == nil) goto v_27573;
    goto v_27590;
v_27586:
    v_27688 = stack[-1];
    goto v_27587;
v_27588:
    v_27687 = stack[0];
    goto v_27589;
v_27590:
    goto v_27586;
v_27587:
    goto v_27588;
v_27589:
    {
        fn = elt(env, 4); // !:expt
        return (*qfn2(fn))(fn, v_27688, v_27687);
    }
v_27573:
    goto v_27601;
v_27597:
    v_27688 = stack[0];
    goto v_27598;
v_27599:
    v_27687 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27600;
v_27601:
    goto v_27597;
v_27598:
    goto v_27599;
v_27600:
    v_27687 = (LispObject)geq2(v_27688, v_27687);
    v_27687 = v_27687 ? lisp_true : nil;
    env = stack[-2];
    if (v_27687 == nil) goto v_27594;
    v_27687 = stack[-1];
    v_27687 = qcar(v_27687);
    v_27687 = qcdr(v_27687);
    v_27687 = Lonep(nil, v_27687);
    env = stack[-2];
    if (v_27687 == nil) goto v_27594;
    v_27687 = stack[-1];
    v_27687 = qcdr(v_27687);
    if (v_27687 == nil) goto v_27610;
    else goto v_27594;
v_27610:
    goto v_27618;
v_27614:
    v_27687 = stack[-1];
    v_27687 = qcar(v_27687);
    v_27687 = qcar(v_27687);
    v_27688 = qcdr(v_27687);
    goto v_27615;
v_27616:
    v_27687 = stack[0];
    goto v_27617;
v_27618:
    goto v_27614;
v_27615:
    goto v_27616;
v_27617:
    v_27688 = times2(v_27688, v_27687);
    env = stack[-2];
    v_27687 = stack[-1];
    v_27687 = qcar(v_27687);
    v_27687 = qcar(v_27687);
    v_27687 = qcar(v_27687);
    stack[-1] = v_27688;
    stack[0] = v_27687;
    goto v_27634;
v_27630:
    v_27688 = stack[0];
    goto v_27631;
v_27632:
    v_27687 = qvalue(elt(env, 1)); // asymplis!*
    goto v_27633;
v_27634:
    goto v_27630;
v_27631:
    goto v_27632;
v_27633:
    v_27687 = Lassoc(nil, v_27688, v_27687);
    v_27688 = v_27687;
    v_27687 = qvalue(elt(env, 2)); // subfg!*
    if (v_27687 == nil) goto v_27642;
    v_27687 = v_27688;
    if (v_27687 == nil) goto v_27642;
    goto v_27654;
v_27650:
    v_27687 = v_27688;
    v_27688 = qcdr(v_27687);
    goto v_27651;
v_27652:
    v_27687 = stack[-1];
    goto v_27653;
v_27654:
    goto v_27650;
v_27651:
    goto v_27652;
v_27653:
    v_27687 = (LispObject)lesseq2(v_27688, v_27687);
    v_27687 = v_27687 ? lisp_true : nil;
    env = stack[-2];
    if (v_27687 == nil) goto v_27642;
    v_27687 = nil;
    goto v_27640;
v_27642:
    goto v_27667;
v_27663:
    goto v_27673;
v_27669:
    v_27688 = stack[0];
    goto v_27670;
v_27671:
    v_27687 = stack[-1];
    goto v_27672;
v_27673:
    goto v_27669;
v_27670:
    goto v_27671;
v_27672:
    fn = elt(env, 5); // mksp
    v_27688 = (*qfn2(fn))(fn, v_27688, v_27687);
    env = stack[-2];
    goto v_27664;
v_27665:
    v_27687 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27666;
v_27667:
    goto v_27663;
v_27664:
    goto v_27665;
v_27666:
    v_27687 = cons(v_27688, v_27687);
    return ncons(v_27687);
    v_27687 = nil;
v_27640:
    goto v_27561;
v_27594:
    goto v_27684;
v_27680:
    v_27688 = stack[-1];
    goto v_27681;
v_27682:
    v_27687 = stack[0];
    goto v_27683;
v_27684:
    goto v_27680;
v_27681:
    goto v_27682;
v_27683:
    {
        fn = elt(env, 6); // exptf2
        return (*qfn2(fn))(fn, v_27688, v_27687);
    }
    v_27687 = nil;
v_27561:
    return onevalue(v_27687);
}



setup_type const u47_setup[] =
{
    {"zfactor1",                TOO_FEW_2,      CC_zfactor1,   WRONG_NO_2},
    {"noncomfree",              CC_noncomfree,  TOO_MANY_1,    WRONG_NO_1},
    {"tayexp-max2",             TOO_FEW_2,      CC_tayexpKmax2,WRONG_NO_2},
    {"cl_replace-varl",         CC_cl_replaceKvarl,TOO_MANY_1, WRONG_NO_1},
    {"qqe_simplqneq",           TOO_FEW_2,      CC_qqe_simplqneq,WRONG_NO_2},
    {"cnml",                    CC_cnml,        TOO_MANY_1,    WRONG_NO_1},
    {"d2int",                   CC_d2int,       TOO_MANY_1,    WRONG_NO_1},
    {"tchscheme2",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_tchscheme2},
    {"sroot1",                  TOO_FEW_2,      CC_sroot1,     WRONG_NO_2},
    {"endmodule",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_endmodule},
    {"mkprec",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mkprec},
    {"setmatelem",              TOO_FEW_2,      CC_setmatelem, WRONG_NO_2},
    {"mv2sf",                   TOO_FEW_2,      CC_mv2sf,      WRONG_NO_2},
    {"nodum_varp",              CC_nodum_varp,  TOO_MANY_1,    WRONG_NO_1},
    {"polynomlistautoreduce",   TOO_FEW_2,      CC_polynomlistautoreduce,WRONG_NO_2},
    {"talp_simplatlinv",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_simplatlinv},
    {"cl_sacat",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_sacat},
    {"operator_fn",             CC_operator_fn, TOO_MANY_1,    WRONG_NO_1},
    {"mulpower",                TOO_FEW_2,      CC_mulpower,   WRONG_NO_2},
    {"newsym1",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_newsym1},
    {"xregister_spoly_pair",    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xregister_spoly_pair},
    {"evaluate2",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_evaluate2},
    {"mkforttab",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mkforttab},
    {"sign-abs",                CC_signKabs,    TOO_MANY_1,    WRONG_NO_1},
    {"mv-compact",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mvKcompact},
    {"simp-prop",               CC_simpKprop,   TOO_MANY_1,    WRONG_NO_1},
    {"check_letop",             CC_check_letop, TOO_MANY_1,    WRONG_NO_1},
    {"even_action_pow",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_even_action_pow},
    {"cl_identifyonoff",        CC_cl_identifyonoff,TOO_MANY_1,WRONG_NO_1},
    {"pasf_ordatp",             TOO_FEW_2,      CC_pasf_ordatp,WRONG_NO_2},
    {"quotfdx",                 TOO_FEW_2,      CC_quotfdx,    WRONG_NO_2},
    {"limitom",                 CC_limitom,     TOO_MANY_1,    WRONG_NO_1},
    {"i2ps",                    CC_i2ps,        TOO_MANY_1,    WRONG_NO_1},
    {"lndepends",               TOO_FEW_2,      CC_lndepends,  WRONG_NO_2},
    {"split-comfac-part",       CC_splitKcomfacKpart,TOO_MANY_1,WRONG_NO_1},
    {"reduce-weights",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_reduceKweights},
    {"cali_bc_from_a",          CC_cali_bc_from_a,TOO_MANY_1,  WRONG_NO_1},
    {"vecsimp*",                CC_vecsimpH,    TOO_MANY_1,    WRONG_NO_1},
    {"mkrootsq",                TOO_FEW_2,      CC_mkrootsq,   WRONG_NO_2},
    {"count-linear-factors-mod-p",WRONG_NO_NA,  WRONG_NO_NB,   (n_args *)CC_countKlinearKfactorsKmodKp},
    {"ofsf_facequal",           CC_ofsf_facequal,TOO_MANY_1,   WRONG_NO_1},
    {"even_action",             TOO_FEW_2,      CC_even_action,WRONG_NO_2},
    {"checkexp",                TOO_FEW_2,      CC_checkexp,   WRONG_NO_2},
    {"f2df",                    CC_f2df,        TOO_MANY_1,    WRONG_NO_1},
    {"mksfpf",                  TOO_FEW_2,      CC_mksfpf,     WRONG_NO_2},
    {NULL, (one_args *)"u47", (two_args *)"13207 811766 8048168", 0}
};

// end of generated code
