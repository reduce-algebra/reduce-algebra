
// $destdir/u43.c        Machine generated C code

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



// Code for expand_terminal

static LispObject CC_expand_terminal(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24969, v_24970, v_24971;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_24359;
// end of prologue
    v_24969 = stack[-2];
    if (!consp(v_24969)) goto v_24368;
    else goto v_24369;
v_24368:
    v_24969 = stack[-2];
    goto v_24365;
v_24369:
    goto v_24379;
v_24375:
    v_24970 = stack[-2];
    goto v_24376;
v_24377:
    v_24969 = elt(env, 1); // opt
    goto v_24378;
v_24379:
    goto v_24375;
v_24376:
    goto v_24377;
v_24378:
    if (!consp(v_24970)) goto v_24373;
    v_24970 = qcar(v_24970);
    if (v_24970 == v_24969) goto v_24372;
    else goto v_24373;
v_24372:
    fn = elt(env, 14); // expansion_name
    v_24969 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    stack[-5] = v_24969;
    goto v_24388;
v_24384:
    goto v_24396;
v_24390:
    stack[-1] = stack[-5];
    goto v_24391;
v_24392:
    stack[0] = elt(env, 2); // (nil)
    goto v_24393;
v_24394:
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = ncons(v_24969);
    env = stack[-6];
    goto v_24395;
v_24396:
    goto v_24390;
v_24391:
    goto v_24392;
v_24393:
    goto v_24394;
v_24395:
    v_24970 = list3(stack[-1], stack[0], v_24969);
    env = stack[-6];
    goto v_24385;
v_24386:
    v_24969 = qvalue(elt(env, 3)); // pending_rules!*
    goto v_24387;
v_24388:
    goto v_24384;
v_24385:
    goto v_24386;
v_24387:
    v_24969 = cons(v_24970, v_24969);
    env = stack[-6];
    qvalue(elt(env, 3)) = v_24969; // pending_rules!*
    v_24969 = stack[-5];
    goto v_24365;
v_24373:
    goto v_24411;
v_24407:
    v_24970 = stack[-2];
    goto v_24408;
v_24409:
    v_24969 = elt(env, 4); // seq
    goto v_24410;
v_24411:
    goto v_24407;
v_24408:
    goto v_24409;
v_24410:
    if (!consp(v_24970)) goto v_24405;
    v_24970 = qcar(v_24970);
    if (v_24970 == v_24969) goto v_24404;
    else goto v_24405;
v_24404:
    fn = elt(env, 14); // expansion_name
    v_24969 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    stack[-5] = v_24969;
    goto v_24420;
v_24416:
    goto v_24426;
v_24422:
    stack[0] = stack[-5];
    goto v_24423;
v_24424:
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = ncons(v_24969);
    env = stack[-6];
    goto v_24425;
v_24426:
    goto v_24422;
v_24423:
    goto v_24424;
v_24425:
    v_24970 = list2(stack[0], v_24969);
    env = stack[-6];
    goto v_24417;
v_24418:
    v_24969 = qvalue(elt(env, 3)); // pending_rules!*
    goto v_24419;
v_24420:
    goto v_24416;
v_24417:
    goto v_24418;
v_24419:
    v_24969 = cons(v_24970, v_24969);
    env = stack[-6];
    qvalue(elt(env, 3)) = v_24969; // pending_rules!*
    v_24969 = stack[-5];
    goto v_24365;
v_24405:
    goto v_24440;
v_24436:
    v_24970 = stack[-2];
    goto v_24437;
v_24438:
    v_24969 = elt(env, 5); // star
    goto v_24439;
v_24440:
    goto v_24436;
v_24437:
    goto v_24438;
v_24439:
    if (!consp(v_24970)) goto v_24434;
    v_24970 = qcar(v_24970);
    if (v_24970 == v_24969) goto v_24433;
    else goto v_24434;
v_24433:
    fn = elt(env, 14); // expansion_name
    v_24969 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    stack[-5] = v_24969;
    fn = elt(env, 14); // expansion_name
    v_24969 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    stack[-4] = v_24969;
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    if (v_24969 == nil) goto v_24448;
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = qcdr(v_24969);
    if (v_24969 == nil) goto v_24455;
    else goto v_24456;
v_24455:
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = qcar(v_24969);
    v_24969 = (consp(v_24969) ? nil : lisp_true);
    goto v_24454;
v_24456:
    v_24969 = nil;
    goto v_24454;
    v_24969 = nil;
v_24454:
    if (v_24969 == nil) goto v_24448;
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = qcar(v_24969);
    stack[-4] = v_24969;
    goto v_24446;
v_24448:
    goto v_24477;
v_24473:
    goto v_24483;
v_24479:
    stack[0] = stack[-4];
    goto v_24480;
v_24481:
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = ncons(v_24969);
    env = stack[-6];
    goto v_24482;
v_24483:
    goto v_24479;
v_24480:
    goto v_24481;
v_24482:
    v_24970 = list2(stack[0], v_24969);
    env = stack[-6];
    goto v_24474;
v_24475:
    v_24969 = qvalue(elt(env, 3)); // pending_rules!*
    goto v_24476;
v_24477:
    goto v_24473;
v_24474:
    goto v_24475;
v_24476:
    v_24969 = cons(v_24970, v_24969);
    env = stack[-6];
    qvalue(elt(env, 3)) = v_24969; // pending_rules!*
    goto v_24446;
v_24446:
    goto v_24494;
v_24490:
    goto v_24502;
v_24496:
    stack[-1] = stack[-5];
    goto v_24497;
v_24498:
    stack[0] = elt(env, 2); // (nil)
    goto v_24499;
v_24500:
    goto v_24510;
v_24506:
    goto v_24516;
v_24512:
    v_24970 = stack[-4];
    goto v_24513;
v_24514:
    v_24969 = stack[-5];
    goto v_24515;
v_24516:
    goto v_24512;
v_24513:
    goto v_24514;
v_24515:
    v_24970 = list2(v_24970, v_24969);
    env = stack[-6];
    goto v_24507;
v_24508:
    v_24969 = elt(env, 6); // (cons !$1 !$2)
    goto v_24509;
v_24510:
    goto v_24506;
v_24507:
    goto v_24508;
v_24509:
    v_24969 = list2(v_24970, v_24969);
    env = stack[-6];
    goto v_24501;
v_24502:
    goto v_24496;
v_24497:
    goto v_24498;
v_24499:
    goto v_24500;
v_24501:
    v_24970 = list3(stack[-1], stack[0], v_24969);
    env = stack[-6];
    goto v_24491;
v_24492:
    v_24969 = qvalue(elt(env, 3)); // pending_rules!*
    goto v_24493;
v_24494:
    goto v_24490;
v_24491:
    goto v_24492;
v_24493:
    v_24969 = cons(v_24970, v_24969);
    env = stack[-6];
    qvalue(elt(env, 3)) = v_24969; // pending_rules!*
    v_24969 = stack[-5];
    goto v_24365;
v_24434:
    goto v_24529;
v_24525:
    v_24970 = stack[-2];
    goto v_24526;
v_24527:
    v_24969 = elt(env, 7); // plus
    goto v_24528;
v_24529:
    goto v_24525;
v_24526:
    goto v_24527;
v_24528:
    if (!consp(v_24970)) goto v_24523;
    v_24970 = qcar(v_24970);
    if (v_24970 == v_24969) goto v_24522;
    else goto v_24523;
v_24522:
    fn = elt(env, 14); // expansion_name
    v_24969 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    stack[-5] = v_24969;
    fn = elt(env, 14); // expansion_name
    v_24969 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    stack[-4] = v_24969;
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    if (v_24969 == nil) goto v_24537;
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = qcdr(v_24969);
    if (v_24969 == nil) goto v_24544;
    else goto v_24545;
v_24544:
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = qcar(v_24969);
    v_24969 = (consp(v_24969) ? nil : lisp_true);
    goto v_24543;
v_24545:
    v_24969 = nil;
    goto v_24543;
    v_24969 = nil;
v_24543:
    if (v_24969 == nil) goto v_24537;
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = qcar(v_24969);
    stack[-4] = v_24969;
    goto v_24535;
v_24537:
    goto v_24566;
v_24562:
    goto v_24572;
v_24568:
    stack[0] = stack[-4];
    goto v_24569;
v_24570:
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = ncons(v_24969);
    env = stack[-6];
    goto v_24571;
v_24572:
    goto v_24568;
v_24569:
    goto v_24570;
v_24571:
    v_24970 = list2(stack[0], v_24969);
    env = stack[-6];
    goto v_24563;
v_24564:
    v_24969 = qvalue(elt(env, 3)); // pending_rules!*
    goto v_24565;
v_24566:
    goto v_24562;
v_24563:
    goto v_24564;
v_24565:
    v_24969 = cons(v_24970, v_24969);
    env = stack[-6];
    qvalue(elt(env, 3)) = v_24969; // pending_rules!*
    goto v_24535;
v_24535:
    goto v_24583;
v_24579:
    goto v_24591;
v_24585:
    stack[-1] = stack[-5];
    goto v_24586;
v_24587:
    goto v_24598;
v_24594:
    v_24969 = stack[-4];
    v_24970 = ncons(v_24969);
    env = stack[-6];
    goto v_24595;
v_24596:
    v_24969 = elt(env, 8); // (list !$1)
    goto v_24597;
v_24598:
    goto v_24594;
v_24595:
    goto v_24596;
v_24597:
    stack[0] = list2(v_24970, v_24969);
    env = stack[-6];
    goto v_24588;
v_24589:
    goto v_24607;
v_24603:
    goto v_24613;
v_24609:
    v_24970 = stack[-4];
    goto v_24610;
v_24611:
    v_24969 = stack[-5];
    goto v_24612;
v_24613:
    goto v_24609;
v_24610:
    goto v_24611;
v_24612:
    v_24970 = list2(v_24970, v_24969);
    env = stack[-6];
    goto v_24604;
v_24605:
    v_24969 = elt(env, 6); // (cons !$1 !$2)
    goto v_24606;
v_24607:
    goto v_24603;
v_24604:
    goto v_24605;
v_24606:
    v_24969 = list2(v_24970, v_24969);
    env = stack[-6];
    goto v_24590;
v_24591:
    goto v_24585;
v_24586:
    goto v_24587;
v_24588:
    goto v_24589;
v_24590:
    v_24970 = list3(stack[-1], stack[0], v_24969);
    env = stack[-6];
    goto v_24580;
v_24581:
    v_24969 = qvalue(elt(env, 3)); // pending_rules!*
    goto v_24582;
v_24583:
    goto v_24579;
v_24580:
    goto v_24581;
v_24582:
    v_24969 = cons(v_24970, v_24969);
    env = stack[-6];
    qvalue(elt(env, 3)) = v_24969; // pending_rules!*
    v_24969 = stack[-5];
    goto v_24365;
v_24523:
    goto v_24630;
v_24626:
    v_24970 = stack[-2];
    goto v_24627;
v_24628:
    v_24969 = elt(env, 9); // list
    goto v_24629;
v_24630:
    goto v_24626;
v_24627:
    goto v_24628;
v_24629:
    if (!consp(v_24970)) goto v_24624;
    v_24970 = qcar(v_24970);
    if (v_24970 == v_24969) goto v_24623;
    else goto v_24624;
v_24623:
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    goto v_24622;
v_24624:
    v_24969 = nil;
    goto v_24622;
    v_24969 = nil;
v_24622:
    if (v_24969 == nil) goto v_24620;
    fn = elt(env, 14); // expansion_name
    v_24969 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    stack[-5] = v_24969;
    fn = elt(env, 14); // expansion_name
    v_24969 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    stack[-4] = v_24969;
    fn = elt(env, 14); // expansion_name
    v_24969 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    stack[-3] = v_24969;
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = qcdr(v_24969);
    if (v_24969 == nil) goto v_24644;
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = qcdr(v_24969);
    v_24969 = qcdr(v_24969);
    if (v_24969 == nil) goto v_24652;
    else goto v_24653;
v_24652:
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = qcdr(v_24969);
    v_24969 = qcar(v_24969);
    v_24969 = (consp(v_24969) ? nil : lisp_true);
    goto v_24651;
v_24653:
    v_24969 = nil;
    goto v_24651;
    v_24969 = nil;
v_24651:
    if (v_24969 == nil) goto v_24644;
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = qcdr(v_24969);
    v_24969 = qcar(v_24969);
    stack[-4] = v_24969;
    goto v_24642;
v_24644:
    goto v_24677;
v_24673:
    goto v_24683;
v_24679:
    stack[0] = stack[-4];
    goto v_24680;
v_24681:
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = qcdr(v_24969);
    v_24969 = ncons(v_24969);
    env = stack[-6];
    goto v_24682;
v_24683:
    goto v_24679;
v_24680:
    goto v_24681;
v_24682:
    v_24970 = list2(stack[0], v_24969);
    env = stack[-6];
    goto v_24674;
v_24675:
    v_24969 = qvalue(elt(env, 3)); // pending_rules!*
    goto v_24676;
v_24677:
    goto v_24673;
v_24674:
    goto v_24675;
v_24676:
    v_24969 = cons(v_24970, v_24969);
    env = stack[-6];
    qvalue(elt(env, 3)) = v_24969; // pending_rules!*
    goto v_24642;
v_24642:
    goto v_24695;
v_24691:
    goto v_24703;
v_24697:
    stack[-1] = stack[-3];
    goto v_24698;
v_24699:
    stack[0] = elt(env, 2); // (nil)
    goto v_24700;
v_24701:
    goto v_24711;
v_24707:
    goto v_24719;
v_24713:
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24971 = qcar(v_24969);
    goto v_24714;
v_24715:
    v_24970 = stack[-4];
    goto v_24716;
v_24717:
    v_24969 = stack[-3];
    goto v_24718;
v_24719:
    goto v_24713;
v_24714:
    goto v_24715;
v_24716:
    goto v_24717;
v_24718:
    v_24970 = list3(v_24971, v_24970, v_24969);
    env = stack[-6];
    goto v_24708;
v_24709:
    v_24969 = elt(env, 10); // (cons !$2 !$3)
    goto v_24710;
v_24711:
    goto v_24707;
v_24708:
    goto v_24709;
v_24710:
    v_24969 = list2(v_24970, v_24969);
    env = stack[-6];
    goto v_24702;
v_24703:
    goto v_24697;
v_24698:
    goto v_24699;
v_24700:
    goto v_24701;
v_24702:
    v_24970 = list3(stack[-1], stack[0], v_24969);
    env = stack[-6];
    goto v_24692;
v_24693:
    v_24969 = qvalue(elt(env, 3)); // pending_rules!*
    goto v_24694;
v_24695:
    goto v_24691;
v_24692:
    goto v_24693;
v_24694:
    v_24969 = cons(v_24970, v_24969);
    env = stack[-6];
    qvalue(elt(env, 3)) = v_24969; // pending_rules!*
    goto v_24732;
v_24728:
    goto v_24740;
v_24734:
    stack[-1] = stack[-5];
    goto v_24735;
v_24736:
    stack[0] = elt(env, 2); // (nil)
    goto v_24737;
v_24738:
    goto v_24748;
v_24744:
    goto v_24754;
v_24750:
    v_24970 = stack[-4];
    goto v_24751;
v_24752:
    v_24969 = stack[-3];
    goto v_24753;
v_24754:
    goto v_24750;
v_24751:
    goto v_24752;
v_24753:
    v_24970 = list2(v_24970, v_24969);
    env = stack[-6];
    goto v_24745;
v_24746:
    v_24969 = elt(env, 6); // (cons !$1 !$2)
    goto v_24747;
v_24748:
    goto v_24744;
v_24745:
    goto v_24746;
v_24747:
    v_24969 = list2(v_24970, v_24969);
    env = stack[-6];
    goto v_24739;
v_24740:
    goto v_24734;
v_24735:
    goto v_24736;
v_24737:
    goto v_24738;
v_24739:
    v_24970 = list3(stack[-1], stack[0], v_24969);
    env = stack[-6];
    goto v_24729;
v_24730:
    v_24969 = qvalue(elt(env, 3)); // pending_rules!*
    goto v_24731;
v_24732:
    goto v_24728;
v_24729:
    goto v_24730;
v_24731:
    v_24969 = cons(v_24970, v_24969);
    env = stack[-6];
    qvalue(elt(env, 3)) = v_24969; // pending_rules!*
    v_24969 = stack[-5];
    goto v_24365;
v_24620:
    goto v_24771;
v_24767:
    v_24970 = stack[-2];
    goto v_24768;
v_24769:
    v_24969 = elt(env, 11); // listplus
    goto v_24770;
v_24771:
    goto v_24767;
v_24768:
    goto v_24769;
v_24770:
    if (!consp(v_24970)) goto v_24765;
    v_24970 = qcar(v_24970);
    if (v_24970 == v_24969) goto v_24764;
    else goto v_24765;
v_24764:
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    goto v_24763;
v_24765:
    v_24969 = nil;
    goto v_24763;
    v_24969 = nil;
v_24763:
    if (v_24969 == nil) goto v_24761;
    fn = elt(env, 14); // expansion_name
    v_24969 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    stack[-5] = v_24969;
    fn = elt(env, 14); // expansion_name
    v_24969 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    stack[-4] = v_24969;
    fn = elt(env, 14); // expansion_name
    v_24969 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    stack[-3] = v_24969;
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = qcdr(v_24969);
    if (v_24969 == nil) goto v_24785;
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = qcdr(v_24969);
    v_24969 = qcdr(v_24969);
    if (v_24969 == nil) goto v_24793;
    else goto v_24794;
v_24793:
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = qcdr(v_24969);
    v_24969 = qcar(v_24969);
    v_24969 = (consp(v_24969) ? nil : lisp_true);
    goto v_24792;
v_24794:
    v_24969 = nil;
    goto v_24792;
    v_24969 = nil;
v_24792:
    if (v_24969 == nil) goto v_24785;
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = qcdr(v_24969);
    v_24969 = qcar(v_24969);
    stack[-4] = v_24969;
    goto v_24783;
v_24785:
    goto v_24818;
v_24814:
    goto v_24824;
v_24820:
    stack[0] = stack[-4];
    goto v_24821;
v_24822:
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24969 = qcdr(v_24969);
    v_24969 = ncons(v_24969);
    env = stack[-6];
    goto v_24823;
v_24824:
    goto v_24820;
v_24821:
    goto v_24822;
v_24823:
    v_24970 = list2(stack[0], v_24969);
    env = stack[-6];
    goto v_24815;
v_24816:
    v_24969 = qvalue(elt(env, 3)); // pending_rules!*
    goto v_24817;
v_24818:
    goto v_24814;
v_24815:
    goto v_24816;
v_24817:
    v_24969 = cons(v_24970, v_24969);
    env = stack[-6];
    qvalue(elt(env, 3)) = v_24969; // pending_rules!*
    goto v_24783;
v_24783:
    goto v_24836;
v_24832:
    goto v_24844;
v_24838:
    stack[-1] = stack[-3];
    goto v_24839;
v_24840:
    stack[0] = elt(env, 2); // (nil)
    goto v_24841;
v_24842:
    goto v_24852;
v_24848:
    goto v_24860;
v_24854:
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    v_24971 = qcar(v_24969);
    goto v_24855;
v_24856:
    v_24970 = stack[-4];
    goto v_24857;
v_24858:
    v_24969 = stack[-3];
    goto v_24859;
v_24860:
    goto v_24854;
v_24855:
    goto v_24856;
v_24857:
    goto v_24858;
v_24859:
    v_24970 = list3(v_24971, v_24970, v_24969);
    env = stack[-6];
    goto v_24849;
v_24850:
    v_24969 = elt(env, 10); // (cons !$2 !$3)
    goto v_24851;
v_24852:
    goto v_24848;
v_24849:
    goto v_24850;
v_24851:
    v_24969 = list2(v_24970, v_24969);
    env = stack[-6];
    goto v_24843;
v_24844:
    goto v_24838;
v_24839:
    goto v_24840;
v_24841:
    goto v_24842;
v_24843:
    v_24970 = list3(stack[-1], stack[0], v_24969);
    env = stack[-6];
    goto v_24833;
v_24834:
    v_24969 = qvalue(elt(env, 3)); // pending_rules!*
    goto v_24835;
v_24836:
    goto v_24832;
v_24833:
    goto v_24834;
v_24835:
    v_24969 = cons(v_24970, v_24969);
    env = stack[-6];
    qvalue(elt(env, 3)) = v_24969; // pending_rules!*
    goto v_24873;
v_24869:
    goto v_24879;
v_24875:
    stack[0] = stack[-5];
    goto v_24876;
v_24877:
    goto v_24886;
v_24882:
    goto v_24892;
v_24888:
    v_24970 = stack[-4];
    goto v_24889;
v_24890:
    v_24969 = stack[-3];
    goto v_24891;
v_24892:
    goto v_24888;
v_24889:
    goto v_24890;
v_24891:
    v_24970 = list2(v_24970, v_24969);
    env = stack[-6];
    goto v_24883;
v_24884:
    v_24969 = elt(env, 6); // (cons !$1 !$2)
    goto v_24885;
v_24886:
    goto v_24882;
v_24883:
    goto v_24884;
v_24885:
    v_24969 = list2(v_24970, v_24969);
    env = stack[-6];
    goto v_24878;
v_24879:
    goto v_24875;
v_24876:
    goto v_24877;
v_24878:
    v_24970 = list2(stack[0], v_24969);
    env = stack[-6];
    goto v_24870;
v_24871:
    v_24969 = qvalue(elt(env, 3)); // pending_rules!*
    goto v_24872;
v_24873:
    goto v_24869;
v_24870:
    goto v_24871;
v_24872:
    v_24969 = cons(v_24970, v_24969);
    env = stack[-6];
    qvalue(elt(env, 3)) = v_24969; // pending_rules!*
    v_24969 = stack[-5];
    goto v_24365;
v_24761:
    goto v_24905;
v_24901:
    v_24970 = stack[-2];
    goto v_24902;
v_24903:
    v_24969 = elt(env, 12); // or
    goto v_24904;
v_24905:
    goto v_24901;
v_24902:
    goto v_24903;
v_24904:
    if (!consp(v_24970)) goto v_24899;
    v_24970 = qcar(v_24970);
    if (v_24970 == v_24969) goto v_24898;
    else goto v_24899;
v_24898:
    fn = elt(env, 14); // expansion_name
    v_24969 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    stack[-5] = v_24969;
    goto v_24916;
v_24910:
    stack[-4] = stack[-5];
    goto v_24911;
v_24912:
    v_24969 = stack[-2];
    v_24969 = qcdr(v_24969);
    stack[-3] = v_24969;
    v_24969 = stack[-3];
    if (v_24969 == nil) goto v_24928;
    else goto v_24929;
v_24928:
    v_24969 = nil;
    v_24970 = v_24969;
    goto v_24922;
v_24929:
    v_24969 = stack[-3];
    v_24969 = qcar(v_24969);
    v_24969 = ncons(v_24969);
    env = stack[-6];
    v_24969 = ncons(v_24969);
    env = stack[-6];
    v_24969 = ncons(v_24969);
    env = stack[-6];
    stack[-1] = v_24969;
    stack[-2] = v_24969;
v_24923:
    v_24969 = stack[-3];
    v_24969 = qcdr(v_24969);
    stack[-3] = v_24969;
    v_24969 = stack[-3];
    if (v_24969 == nil) goto v_24943;
    else goto v_24944;
v_24943:
    v_24969 = stack[-2];
    v_24970 = v_24969;
    goto v_24922;
v_24944:
    goto v_24952;
v_24948:
    stack[0] = stack[-1];
    goto v_24949;
v_24950:
    v_24969 = stack[-3];
    v_24969 = qcar(v_24969);
    v_24969 = ncons(v_24969);
    env = stack[-6];
    v_24969 = ncons(v_24969);
    env = stack[-6];
    v_24969 = ncons(v_24969);
    env = stack[-6];
    goto v_24951;
v_24952:
    goto v_24948;
v_24949:
    goto v_24950;
v_24951:
    v_24969 = Lrplacd(nil, stack[0], v_24969);
    env = stack[-6];
    v_24969 = stack[-1];
    v_24969 = qcdr(v_24969);
    stack[-1] = v_24969;
    goto v_24923;
v_24922:
    goto v_24913;
v_24914:
    v_24969 = qvalue(elt(env, 3)); // pending_rules!*
    goto v_24915;
v_24916:
    goto v_24910;
v_24911:
    goto v_24912;
v_24913:
    goto v_24914;
v_24915:
    v_24969 = acons(stack[-4], v_24970, v_24969);
    env = stack[-6];
    qvalue(elt(env, 3)) = v_24969; // pending_rules!*
    v_24969 = stack[-5];
    goto v_24365;
v_24899:
    v_24969 = elt(env, 13); // "Invalid item in a rule"
    fn = elt(env, 15); // rederr
    v_24969 = (*qfn1(fn))(fn, v_24969);
    goto v_24367;
v_24367:
    v_24969 = nil;
v_24365:
    return onevalue(v_24969);
}



// Code for subtractinds

static LispObject CC_subtractinds(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24422, v_24423;
    LispObject v_24361, v_24360, v_24359;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "subtractinds");
    va_start(aa, nargs);
    v_24359 = va_arg(aa, LispObject);
    v_24360 = va_arg(aa, LispObject);
    v_24361 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24361,v_24360,v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24359,v_24360,v_24361);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_24361;
    stack[-2] = v_24360;
    stack[-3] = v_24359;
// end of prologue
v_24367:
    v_24422 = stack[-2];
    if (v_24422 == nil) goto v_24370;
    else goto v_24371;
v_24370:
    v_24422 = stack[-1];
        return Lnreverse(nil, v_24422);
v_24371:
    goto v_24382;
v_24378:
    goto v_24388;
v_24384:
    v_24422 = stack[-3];
    v_24423 = qcar(v_24422);
    goto v_24385;
v_24386:
    v_24422 = stack[-2];
    v_24422 = qcar(v_24422);
    v_24422 = qcar(v_24422);
    goto v_24387;
v_24388:
    goto v_24384;
v_24385:
    goto v_24386;
v_24387:
    v_24423 = difference2(v_24423, v_24422);
    env = stack[-5];
    goto v_24379;
v_24380:
    v_24422 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24381;
v_24382:
    goto v_24378;
v_24379:
    goto v_24380;
v_24381:
    v_24422 = (LispObject)lessp2(v_24423, v_24422);
    v_24422 = v_24422 ? lisp_true : nil;
    env = stack[-5];
    if (v_24422 == nil) goto v_24376;
    v_24422 = nil;
    goto v_24366;
v_24376:
    v_24422 = stack[-3];
    v_24422 = qcdr(v_24422);
    stack[-4] = v_24422;
    v_24422 = stack[-2];
    v_24422 = qcdr(v_24422);
    stack[0] = v_24422;
    goto v_24407;
v_24403:
    goto v_24413;
v_24409:
    v_24422 = stack[-3];
    v_24423 = qcar(v_24422);
    goto v_24410;
v_24411:
    v_24422 = stack[-2];
    v_24422 = qcar(v_24422);
    v_24422 = qcar(v_24422);
    goto v_24412;
v_24413:
    goto v_24409;
v_24410:
    goto v_24411;
v_24412:
    v_24423 = difference2(v_24423, v_24422);
    env = stack[-5];
    goto v_24404;
v_24405:
    v_24422 = stack[-1];
    goto v_24406;
v_24407:
    goto v_24403;
v_24404:
    goto v_24405;
v_24406:
    v_24422 = cons(v_24423, v_24422);
    env = stack[-5];
    stack[-1] = v_24422;
    v_24422 = stack[0];
    stack[-2] = v_24422;
    v_24422 = stack[-4];
    stack[-3] = v_24422;
    goto v_24367;
    v_24422 = nil;
v_24366:
    return onevalue(v_24422);
}



// Code for cl_subfof

static LispObject CC_cl_subfof(LispObject env,
                         LispObject v_24359, LispObject v_24360)
{
    env = qenv(env);
    LispObject v_24451, v_24452, v_24453, v_24454;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24360,v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24359,v_24360);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_24360;
    stack[-5] = v_24359;
// end of prologue
    stack[-6] = nil;
    stack[-2] = nil;
    v_24451 = stack[-5];
    fn = elt(env, 1); // rl_subalchk
    v_24451 = (*qfn1(fn))(fn, v_24451);
    env = stack[-7];
    v_24451 = stack[-5];
    stack[-1] = v_24451;
v_24372:
    v_24451 = stack[-1];
    if (v_24451 == nil) goto v_24376;
    else goto v_24377;
v_24376:
    goto v_24371;
v_24377:
    v_24451 = stack[-1];
    v_24451 = qcar(v_24451);
    stack[0] = v_24451;
    v_24451 = stack[0];
    fn = elt(env, 2); // rl_eqnrhskernels
    v_24451 = (*qfn1(fn))(fn, v_24451);
    env = stack[-7];
    stack[-3] = v_24451;
    goto v_24391;
v_24387:
    goto v_24398;
v_24394:
    v_24451 = stack[0];
    v_24452 = qcar(v_24451);
    goto v_24395;
v_24396:
    v_24451 = stack[-3];
    goto v_24397;
v_24398:
    goto v_24394;
v_24395:
    goto v_24396;
v_24397:
    v_24451 = cons(v_24452, v_24451);
    env = stack[-7];
    v_24452 = ncons(v_24451);
    env = stack[-7];
    goto v_24388;
v_24389:
    v_24451 = stack[-6];
    goto v_24390;
v_24391:
    goto v_24387;
v_24388:
    goto v_24389;
v_24390:
    v_24451 = list2(v_24452, v_24451);
    env = stack[-7];
    fn = elt(env, 3); // lto_alunion
    v_24451 = (*qfn1(fn))(fn, v_24451);
    env = stack[-7];
    stack[-6] = v_24451;
    goto v_24408;
v_24404:
    v_24451 = stack[0];
    stack[0] = qcar(v_24451);
    goto v_24405;
v_24406:
    goto v_24416;
v_24412:
    v_24452 = stack[-3];
    goto v_24413;
v_24414:
    v_24451 = stack[-2];
    goto v_24415;
v_24416:
    goto v_24412;
v_24413:
    goto v_24414;
v_24415:
    v_24451 = Lappend(nil, v_24452, v_24451);
    env = stack[-7];
    goto v_24407;
v_24408:
    goto v_24404;
v_24405:
    goto v_24406;
v_24407:
    v_24451 = cons(stack[0], v_24451);
    env = stack[-7];
    stack[-2] = v_24451;
    v_24451 = stack[-1];
    v_24451 = qcdr(v_24451);
    stack[-1] = v_24451;
    goto v_24372;
v_24371:
    v_24451 = stack[-4];
    fn = elt(env, 4); // cl_varl1
    v_24451 = (*qfn1(fn))(fn, v_24451);
    env = stack[-7];
    stack[-3] = v_24451;
    goto v_24431;
v_24425:
    v_24453 = stack[-2];
    goto v_24426;
v_24427:
    v_24451 = stack[-3];
    v_24452 = qcar(v_24451);
    goto v_24428;
v_24429:
    v_24451 = stack[-3];
    v_24451 = qcdr(v_24451);
    goto v_24430;
v_24431:
    goto v_24425;
v_24426:
    goto v_24427;
v_24428:
    goto v_24429;
v_24430:
    v_24451 = list3(v_24453, v_24452, v_24451);
    env = stack[-7];
    fn = elt(env, 5); // lto_nconcn
    v_24451 = (*qfn1(fn))(fn, v_24451);
    env = stack[-7];
    stack[-2] = v_24451;
    goto v_24446;
v_24438:
    v_24454 = stack[-5];
    goto v_24439;
v_24440:
    v_24453 = stack[-4];
    goto v_24441;
v_24442:
    v_24452 = stack[-6];
    goto v_24443;
v_24444:
    v_24451 = stack[-2];
    goto v_24445;
v_24446:
    goto v_24438;
v_24439:
    goto v_24440;
v_24441:
    goto v_24442;
v_24443:
    goto v_24444;
v_24445:
    {
        fn = elt(env, 6); // cl_subfof1
        return (*qfnn(fn))(fn, 4, v_24454, v_24453, v_24452, v_24451);
    }
    return onevalue(v_24451);
}



// Code for rl_sacatlp

static LispObject CC_rl_sacatlp(LispObject env,
                         LispObject v_24359, LispObject v_24360)
{
    env = qenv(env);
    LispObject v_24377, v_24378;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24360,v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24359,v_24360);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_24377 = v_24360;
    v_24378 = v_24359;
// end of prologue
    goto v_24367;
v_24363:
    stack[0] = qvalue(elt(env, 1)); // rl_sacatlp!*
    goto v_24364;
v_24365:
    goto v_24374;
v_24370:
    goto v_24371;
v_24372:
    goto v_24373;
v_24374:
    goto v_24370;
v_24371:
    goto v_24372;
v_24373:
    v_24377 = list2(v_24378, v_24377);
    env = stack[-1];
    goto v_24366;
v_24367:
    goto v_24363;
v_24364:
    goto v_24365;
v_24366:
    {
        LispObject v_24380 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_24380, v_24377);
    }
}



// Code for cl_sacatlp

static LispObject CC_cl_sacatlp(LispObject env,
                         LispObject v_24359, LispObject v_24360)
{
    env = qenv(env);
    LispObject v_24363, v_24364;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24363 = v_24360;
    v_24364 = v_24359;
// end of prologue
    v_24363 = lisp_true;
    return onevalue(v_24363);
}



// Code for ciom

static LispObject CC_ciom(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24422, v_24423;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24359;
// end of prologue
    v_24422 = elt(env, 1); // "<OMATTR>"
    fn = elt(env, 9); // printout
    v_24422 = (*qfn1(fn))(fn, v_24422);
    env = stack[-1];
    v_24422 = lisp_true;
    fn = elt(env, 10); // indent!*
    v_24422 = (*qfn1(fn))(fn, v_24422);
    env = stack[-1];
    v_24422 = elt(env, 2); // "<OMATP>"
    fn = elt(env, 9); // printout
    v_24422 = (*qfn1(fn))(fn, v_24422);
    env = stack[-1];
    v_24422 = lisp_true;
    fn = elt(env, 10); // indent!*
    v_24422 = (*qfn1(fn))(fn, v_24422);
    env = stack[-1];
    v_24422 = elt(env, 3); // "<OMS cd=""typmml"" name=""type"">"
    fn = elt(env, 9); // printout
    v_24422 = (*qfn1(fn))(fn, v_24422);
    env = stack[-1];
    v_24422 = elt(env, 4); // "<OMS cd=""typmml"" name="""
    fn = elt(env, 9); // printout
    v_24422 = (*qfn1(fn))(fn, v_24422);
    env = stack[-1];
    goto v_24380;
v_24376:
    v_24422 = stack[0];
    v_24422 = qcdr(v_24422);
    v_24422 = qcar(v_24422);
    v_24422 = qcar(v_24422);
    v_24422 = qcdr(v_24422);
    v_24422 = qcar(v_24422);
    v_24423 = Lintern(nil, v_24422);
    env = stack[-1];
    goto v_24377;
v_24378:
    v_24422 = qvalue(elt(env, 5)); // mmltypes!*
    goto v_24379;
v_24380:
    goto v_24376;
v_24377:
    goto v_24378;
v_24379:
    v_24422 = Lassoc(nil, v_24423, v_24422);
    v_24422 = Lprinc(nil, v_24422);
    env = stack[-1];
    goto v_24395;
v_24391:
    v_24422 = stack[0];
    v_24422 = qcdr(v_24422);
    v_24422 = qcar(v_24422);
    v_24422 = qcar(v_24422);
    v_24422 = qcdr(v_24422);
    v_24422 = qcar(v_24422);
    v_24423 = Lintern(nil, v_24422);
    env = stack[-1];
    goto v_24392;
v_24393:
    v_24422 = qvalue(elt(env, 5)); // mmltypes!*
    goto v_24394;
v_24395:
    goto v_24391;
v_24392:
    goto v_24393;
v_24394:
    v_24422 = Lassoc(nil, v_24423, v_24422);
    v_24422 = qcdr(v_24422);
    v_24422 = qcar(v_24422);
    v_24422 = Lprinc(nil, v_24422);
    env = stack[-1];
    v_24422 = elt(env, 6); // """>"
    v_24422 = Lprinc(nil, v_24422);
    env = stack[-1];
    v_24422 = nil;
    fn = elt(env, 10); // indent!*
    v_24422 = (*qfn1(fn))(fn, v_24422);
    env = stack[-1];
    v_24422 = elt(env, 7); // "</OMATP>"
    fn = elt(env, 9); // printout
    v_24422 = (*qfn1(fn))(fn, v_24422);
    env = stack[-1];
    v_24422 = stack[0];
    v_24422 = qcdr(v_24422);
    v_24422 = qcdr(v_24422);
    v_24422 = qcar(v_24422);
    fn = elt(env, 11); // objectom
    v_24422 = (*qfn1(fn))(fn, v_24422);
    env = stack[-1];
    v_24422 = nil;
    fn = elt(env, 10); // indent!*
    v_24422 = (*qfn1(fn))(fn, v_24422);
    env = stack[-1];
    v_24422 = elt(env, 8); // "</OMATTR>"
    fn = elt(env, 9); // printout
    v_24422 = (*qfn1(fn))(fn, v_24422);
    v_24422 = nil;
    return onevalue(v_24422);
}



// Code for simpsqrtsq

static LispObject CC_simpsqrtsq(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24373;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24359;
// end of prologue
    goto v_24366;
v_24362:
    v_24373 = stack[0];
    v_24373 = qcar(v_24373);
    fn = elt(env, 1); // simpsqrt2
    stack[-1] = (*qfn1(fn))(fn, v_24373);
    env = stack[-2];
    goto v_24363;
v_24364:
    v_24373 = stack[0];
    v_24373 = qcdr(v_24373);
    fn = elt(env, 1); // simpsqrt2
    v_24373 = (*qfn1(fn))(fn, v_24373);
    goto v_24365;
v_24366:
    goto v_24362;
v_24363:
    goto v_24364;
v_24365:
    {
        LispObject v_24376 = stack[-1];
        return cons(v_24376, v_24373);
    }
}



// Code for insertocc

static LispObject CC_insertocc(LispObject env,
                         LispObject v_24359, LispObject v_24360)
{
    env = qenv(env);
    LispObject v_24411, v_24412, v_24413;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24360,v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24359,v_24360);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_24413 = v_24360;
    stack[-1] = v_24359;
// end of prologue
    goto v_24373;
v_24369:
    v_24412 = v_24413;
    goto v_24370;
v_24371:
    v_24411 = stack[-1];
    goto v_24372;
v_24373:
    goto v_24369;
v_24370:
    goto v_24371;
v_24372:
    v_24411 = Lassoc(nil, v_24412, v_24411);
    stack[-2] = v_24411;
    if (v_24411 == nil) goto v_24368;
    goto v_24384;
v_24378:
    goto v_24390;
v_24386:
    stack[0] = v_24413;
    goto v_24387;
v_24388:
    v_24411 = stack[-2];
    v_24411 = qcdr(v_24411);
    v_24411 = add1(v_24411);
    env = stack[-3];
    goto v_24389;
v_24390:
    goto v_24386;
v_24387:
    goto v_24388;
v_24389:
    v_24413 = cons(stack[0], v_24411);
    env = stack[-3];
    goto v_24379;
v_24380:
    v_24412 = stack[-2];
    goto v_24381;
v_24382:
    v_24411 = stack[-1];
    goto v_24383;
v_24384:
    goto v_24378;
v_24379:
    goto v_24380;
v_24381:
    goto v_24382;
v_24383:
    v_24411 = Lsubst(nil, 3, v_24413, v_24412, v_24411);
    stack[-1] = v_24411;
    goto v_24366;
v_24368:
    goto v_24406;
v_24400:
    goto v_24401;
v_24402:
    v_24412 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24403;
v_24404:
    v_24411 = stack[-1];
    goto v_24405;
v_24406:
    goto v_24400;
v_24401:
    goto v_24402;
v_24403:
    goto v_24404;
v_24405:
    v_24411 = acons(v_24413, v_24412, v_24411);
    stack[-1] = v_24411;
    goto v_24366;
v_24366:
    v_24411 = stack[-1];
    return onevalue(v_24411);
}



// Code for new_simpexpt

static LispObject CC_new_simpexpt(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24460, v_24461;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_24359;
// end of prologue
// Binding !*precise
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
    qvalue(elt(env, 1)) = nil; // !*precise
// Binding !*factor
// FLUIDBIND: reloadenv=7 litvec-offset=2 saveloc=4
{   bind_fluid_stack bind_fluid_var(-7, 2, -4);
    qvalue(elt(env, 2)) = nil; // !*factor
// Binding !*exp
// FLUIDBIND: reloadenv=7 litvec-offset=3 saveloc=3
{   bind_fluid_stack bind_fluid_var(-7, 3, -3);
    qvalue(elt(env, 3)) = nil; // !*exp
// Binding !*mcd
// FLUIDBIND: reloadenv=7 litvec-offset=4 saveloc=2
{   bind_fluid_stack bind_fluid_var(-7, 4, -2);
    qvalue(elt(env, 4)) = nil; // !*mcd
// Binding !*allfac
// FLUIDBIND: reloadenv=7 litvec-offset=5 saveloc=1
{   bind_fluid_stack bind_fluid_var(-7, 5, -1);
    qvalue(elt(env, 5)) = nil; // !*allfac
    goto v_24375;
v_24371:
    v_24461 = elt(env, 6); // exp
    goto v_24372;
v_24373:
    v_24460 = elt(env, 7); // mcd
    goto v_24374;
v_24375:
    goto v_24371;
v_24372:
    goto v_24373;
v_24374:
    v_24460 = list2(v_24461, v_24460);
    env = stack[-7];
    fn = elt(env, 14); // on
    v_24460 = (*qfn1(fn))(fn, v_24460);
    env = stack[-7];
    goto v_24384;
v_24380:
    v_24461 = elt(env, 8); // precise
    goto v_24381;
v_24382:
    v_24460 = elt(env, 9); // allfac
    goto v_24383;
v_24384:
    goto v_24380;
v_24381:
    goto v_24382;
v_24383:
    v_24460 = list2(v_24461, v_24460);
    env = stack[-7];
    fn = elt(env, 15); // off
    v_24460 = (*qfn1(fn))(fn, v_24460);
    env = stack[-7];
    goto v_24396;
v_24392:
    v_24460 = stack[-5];
    v_24461 = qcar(v_24460);
    goto v_24393;
v_24394:
    v_24460 = elt(env, 10); // minus
    goto v_24395;
v_24396:
    goto v_24392;
v_24393:
    goto v_24394;
v_24395:
    if (!consp(v_24461)) goto v_24390;
    v_24461 = qcar(v_24461);
    if (v_24461 == v_24460) goto v_24389;
    else goto v_24390;
v_24389:
    goto v_24405;
v_24401:
    goto v_24412;
v_24408:
    goto v_24418;
v_24414:
    v_24461 = elt(env, 10); // minus
    goto v_24415;
v_24416:
    v_24460 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24417;
v_24418:
    goto v_24414;
v_24415:
    goto v_24416;
v_24417:
    v_24461 = list2(v_24461, v_24460);
    env = stack[-7];
    goto v_24409;
v_24410:
    v_24460 = stack[-5];
    v_24460 = qcdr(v_24460);
    v_24460 = qcar(v_24460);
    goto v_24411;
v_24412:
    goto v_24408;
v_24409:
    goto v_24410;
v_24411:
    v_24460 = list2(v_24461, v_24460);
    env = stack[-7];
    fn = elt(env, 13); // original_simpexpt
    stack[0] = (*qfn1(fn))(fn, v_24460);
    env = stack[-7];
    goto v_24402;
v_24403:
    goto v_24430;
v_24426:
    v_24460 = stack[-5];
    v_24460 = qcar(v_24460);
    v_24460 = qcdr(v_24460);
    v_24461 = qcar(v_24460);
    goto v_24427;
v_24428:
    v_24460 = stack[-5];
    v_24460 = qcdr(v_24460);
    v_24460 = qcar(v_24460);
    goto v_24429;
v_24430:
    goto v_24426;
v_24427:
    goto v_24428;
v_24429:
    v_24460 = list2(v_24461, v_24460);
    env = stack[-7];
    v_24460 = CC_new_simpexpt(elt(env, 0), v_24460);
    env = stack[-7];
    goto v_24404;
v_24405:
    goto v_24401;
v_24402:
    goto v_24403;
v_24404:
    fn = elt(env, 16); // multsq
    v_24460 = (*qfn2(fn))(fn, stack[0], v_24460);
    goto v_24368;
v_24390:
    v_24460 = qvalue(elt(env, 11)); // !*redefmsg
    stack[0] = v_24460;
    v_24460 = nil;
    qvalue(elt(env, 11)) = v_24460; // !*redefmsg
    goto v_24445;
v_24441:
    v_24461 = elt(env, 12); // simpexpt
    goto v_24442;
v_24443:
    v_24460 = elt(env, 13); // original_simpexpt
    goto v_24444;
v_24445:
    goto v_24441;
v_24442:
    goto v_24443;
v_24444:
    fn = elt(env, 17); // copyd
    v_24460 = (*qfn2(fn))(fn, v_24461, v_24460);
    env = stack[-7];
    v_24460 = stack[-5];
    fn = elt(env, 12); // simpexpt
    v_24460 = (*qfn1(fn))(fn, v_24460);
    env = stack[-7];
    stack[-5] = v_24460;
    goto v_24455;
v_24451:
    v_24461 = elt(env, 12); // simpexpt
    goto v_24452;
v_24453:
    v_24460 = elt(env, 0); // new_simpexpt
    goto v_24454;
v_24455:
    goto v_24451;
v_24452:
    goto v_24453;
v_24454:
    fn = elt(env, 17); // copyd
    v_24460 = (*qfn2(fn))(fn, v_24461, v_24460);
    env = stack[-7];
    v_24460 = stack[0];
    qvalue(elt(env, 11)) = v_24460; // !*redefmsg
    v_24460 = stack[-5];
v_24368:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_24460);
}



// Code for a2vdp

static LispObject CC_a2vdp(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24438, v_24439, v_24440;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_24440 = v_24359;
// end of prologue
    goto v_24373;
v_24369:
    v_24439 = v_24440;
    goto v_24370;
v_24371:
    v_24438 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24372;
v_24373:
    goto v_24369;
v_24370:
    goto v_24371;
v_24372:
    if (v_24439 == v_24438) goto v_24367;
    else goto v_24368;
v_24367:
    v_24438 = lisp_true;
    goto v_24366;
v_24368:
    v_24438 = v_24440;
    v_24438 = (v_24438 == nil ? lisp_true : nil);
    goto v_24366;
    v_24438 = nil;
v_24366:
    if (v_24438 == nil) goto v_24364;
    goto v_24390;
v_24382:
    stack[-2] = elt(env, 1); // vdp
    goto v_24383;
v_24384:
    stack[-1] = nil;
    goto v_24385;
v_24386:
    goto v_24398;
v_24394:
    v_24439 = nil;
    goto v_24395;
v_24396:
    v_24438 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24397;
v_24398:
    goto v_24394;
v_24395:
    goto v_24396;
v_24397:
    stack[0] = cons(v_24439, v_24438);
    env = stack[-3];
    goto v_24387;
v_24388:
    goto v_24406;
v_24402:
    v_24439 = nil;
    goto v_24403;
v_24404:
    v_24438 = nil;
    goto v_24405;
v_24406:
    goto v_24402;
v_24403:
    goto v_24404;
v_24405:
    v_24438 = list2(v_24439, v_24438);
    goto v_24389;
v_24390:
    goto v_24382;
v_24383:
    goto v_24384;
v_24385:
    goto v_24386;
v_24387:
    goto v_24388;
v_24389:
    {
        LispObject v_24444 = stack[-2];
        LispObject v_24445 = stack[-1];
        LispObject v_24446 = stack[0];
        return list3star(v_24444, v_24445, v_24446, v_24438);
    }
v_24364:
    v_24438 = v_24440;
    fn = elt(env, 2); // a2dip
    v_24438 = (*qfn1(fn))(fn, v_24438);
    env = stack[-3];
    v_24439 = v_24438;
    goto v_24423;
v_24415:
    stack[-2] = elt(env, 1); // vdp
    goto v_24416;
v_24417:
    v_24438 = v_24439;
    stack[-1] = qcar(v_24438);
    goto v_24418;
v_24419:
    v_24438 = v_24439;
    v_24438 = qcdr(v_24438);
    stack[0] = qcar(v_24438);
    goto v_24420;
v_24421:
    goto v_24435;
v_24431:
    goto v_24432;
v_24433:
    v_24438 = nil;
    goto v_24434;
v_24435:
    goto v_24431;
v_24432:
    goto v_24433;
v_24434:
    v_24438 = list2(v_24439, v_24438);
    goto v_24422;
v_24423:
    goto v_24415;
v_24416:
    goto v_24417;
v_24418:
    goto v_24419;
v_24420:
    goto v_24421;
v_24422:
    {
        LispObject v_24447 = stack[-2];
        LispObject v_24448 = stack[-1];
        LispObject v_24449 = stack[0];
        return list3star(v_24447, v_24448, v_24449, v_24438);
    }
    v_24438 = nil;
    return onevalue(v_24438);
}



// Code for xreadlist

static LispObject CC_xreadlist(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24482, v_24483;
    LispObject fn;
    argcheck(nargs, 0, "xreadlist");
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
    stack[-2] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    goto v_24375;
v_24371:
    fn = elt(env, 9); // scan
    v_24483 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_24372;
v_24373:
    v_24482 = elt(env, 1); // !*rcbkt!*
    goto v_24374;
v_24375:
    goto v_24371;
v_24372:
    goto v_24373;
v_24374:
    if (v_24483 == v_24482) goto v_24369;
    else goto v_24370;
v_24369:
    fn = elt(env, 9); // scan
    v_24482 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    v_24482 = elt(env, 2); // list
    return ncons(v_24482);
v_24370:
v_24366:
    v_24482 = stack[-1];
    if (v_24482 == nil) goto v_24383;
    else goto v_24384;
v_24383:
    goto v_24391;
v_24387:
    stack[0] = stack[-1];
    goto v_24388;
v_24389:
    v_24482 = elt(env, 3); // group
    fn = elt(env, 10); // xread1
    v_24482 = (*qfn1(fn))(fn, v_24482);
    env = stack[-4];
    goto v_24390;
v_24391:
    goto v_24387;
v_24388:
    goto v_24389;
v_24390:
    fn = elt(env, 11); // aconc
    v_24482 = (*qfn2(fn))(fn, stack[0], v_24482);
    env = stack[-4];
    stack[0] = v_24482;
    stack[-1] = v_24482;
    goto v_24382;
v_24384:
    goto v_24402;
v_24398:
    goto v_24399;
v_24400:
    v_24482 = elt(env, 3); // group
    fn = elt(env, 10); // xread1
    v_24482 = (*qfn1(fn))(fn, v_24482);
    env = stack[-4];
    v_24482 = ncons(v_24482);
    env = stack[-4];
    goto v_24401;
v_24402:
    goto v_24398;
v_24399:
    goto v_24400;
v_24401:
    fn = elt(env, 12); // nconc2
    v_24482 = (*qfn2(fn))(fn, stack[0], v_24482);
    env = stack[-4];
    stack[0] = v_24482;
    goto v_24382;
v_24382:
    v_24482 = qvalue(elt(env, 4)); // cursym!*
    stack[-3] = v_24482;
    goto v_24416;
v_24412:
    v_24483 = stack[-3];
    goto v_24413;
v_24414:
    v_24482 = elt(env, 5); // !*semicol!*
    goto v_24415;
v_24416:
    goto v_24412;
v_24413:
    goto v_24414;
v_24415:
    if (v_24483 == v_24482) goto v_24410;
    else goto v_24411;
v_24410:
    goto v_24424;
v_24420:
    v_24483 = elt(env, 6); // "Syntax error: semicolon in list"
    goto v_24421;
v_24422:
    v_24482 = nil;
    goto v_24423;
v_24424:
    goto v_24420;
v_24421:
    goto v_24422;
v_24423:
    fn = elt(env, 13); // symerr
    v_24482 = (*qfn2(fn))(fn, v_24483, v_24482);
    env = stack[-4];
    goto v_24409;
v_24411:
    goto v_24437;
v_24433:
    fn = elt(env, 9); // scan
    v_24483 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_24434;
v_24435:
    v_24482 = elt(env, 1); // !*rcbkt!*
    goto v_24436;
v_24437:
    goto v_24433;
v_24434:
    goto v_24435;
v_24436:
    if (v_24483 == v_24482) goto v_24431;
    else goto v_24432;
v_24431:
    goto v_24444;
v_24440:
    v_24483 = stack[-3];
    goto v_24441;
v_24442:
    v_24482 = elt(env, 7); // !*comma!*
    goto v_24443;
v_24444:
    goto v_24440;
v_24441:
    goto v_24442;
v_24443:
    v_24482 = (v_24483 == v_24482 ? lisp_true : nil);
    goto v_24430;
v_24432:
    v_24482 = nil;
    goto v_24430;
    v_24482 = nil;
v_24430:
    if (v_24482 == nil) goto v_24428;
    goto v_24456;
v_24452:
    v_24483 = elt(env, 8); // "Syntax error: invalid comma in list"
    goto v_24453;
v_24454:
    v_24482 = nil;
    goto v_24455;
v_24456:
    goto v_24452;
v_24453:
    goto v_24454;
v_24455:
    fn = elt(env, 13); // symerr
    v_24482 = (*qfn2(fn))(fn, v_24483, v_24482);
    env = stack[-4];
    goto v_24409;
v_24428:
v_24409:
    goto v_24467;
v_24463:
    v_24483 = stack[-3];
    goto v_24464;
v_24465:
    v_24482 = elt(env, 1); // !*rcbkt!*
    goto v_24466;
v_24467:
    goto v_24463;
v_24464:
    goto v_24465;
v_24466:
    if (v_24483 == v_24482) goto v_24461;
    else goto v_24462;
v_24461:
    goto v_24475;
v_24471:
    v_24483 = elt(env, 2); // list
    goto v_24472;
v_24473:
    v_24482 = stack[-1];
    goto v_24474;
v_24475:
    goto v_24471;
v_24472:
    goto v_24473;
v_24474:
    return cons(v_24483, v_24482);
v_24462:
    v_24482 = stack[-2];
    if (v_24482 == nil) goto v_24478;
    else goto v_24479;
v_24478:
    v_24482 = stack[-3];
    stack[-2] = v_24482;
    goto v_24460;
v_24479:
v_24460:
    goto v_24366;
    return onevalue(v_24482);
}



// Code for physoppri

static LispObject CC_physoppri(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24671, v_24672, v_24673, v_24674;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_24359;
// end of prologue
    stack[-6] = nil;
    v_24671 = stack[-8];
    if (symbolp(v_24671)) goto v_24370;
    else goto v_24371;
v_24370:
    v_24671 = stack[-8];
    goto v_24369;
v_24371:
    v_24671 = stack[-8];
    v_24671 = qcar(v_24671);
    goto v_24369;
    v_24671 = nil;
v_24369:
    stack[-9] = v_24671;
    v_24671 = stack[-8];
    if (symbolp(v_24671)) goto v_24380;
    else goto v_24381;
v_24380:
    v_24671 = nil;
    goto v_24379;
v_24381:
    v_24671 = stack[-8];
    v_24671 = qcdr(v_24671);
    goto v_24379;
    v_24671 = nil;
v_24379:
    stack[-7] = v_24671;
    goto v_24398;
v_24390:
    stack[-5] = elt(env, 0); // physoppri
    goto v_24391;
v_24392:
    stack[-4] = elt(env, 1); // "x= "
    goto v_24393;
v_24394:
    stack[-3] = stack[-9];
    goto v_24395;
v_24396:
    goto v_24411;
v_24403:
    stack[-2] = elt(env, 2); // " y= "
    goto v_24404;
v_24405:
    stack[-1] = stack[-7];
    goto v_24406;
v_24407:
    stack[0] = elt(env, 3); // "nat= "
    goto v_24408;
v_24409:
    goto v_24422;
v_24416:
    v_24673 = elt(env, 4); // !*nat
    goto v_24417;
v_24418:
    v_24672 = elt(env, 5); // " contract= "
    goto v_24419;
v_24420:
    v_24671 = elt(env, 6); // !*contract
    goto v_24421;
v_24422:
    goto v_24416;
v_24417:
    goto v_24418;
v_24419:
    goto v_24420;
v_24421:
    v_24671 = list3(v_24673, v_24672, v_24671);
    env = stack[-10];
    goto v_24410;
v_24411:
    goto v_24403;
v_24404:
    goto v_24405;
v_24406:
    goto v_24407;
v_24408:
    goto v_24409;
v_24410:
    v_24671 = list3star(stack[-2], stack[-1], stack[0], v_24671);
    env = stack[-10];
    goto v_24397;
v_24398:
    goto v_24390;
v_24391:
    goto v_24392;
v_24393:
    goto v_24394;
v_24395:
    goto v_24396;
v_24397:
    v_24671 = list3star(stack[-5], stack[-4], stack[-3], v_24671);
    env = stack[-10];
    fn = elt(env, 18); // trwrite
    v_24671 = (*qfn1(fn))(fn, v_24671);
    env = stack[-10];
    v_24671 = qvalue(elt(env, 4)); // !*nat
    if (v_24671 == nil) goto v_24429;
    v_24671 = qvalue(elt(env, 6)); // !*contract
    if (v_24671 == nil) goto v_24432;
    else goto v_24429;
v_24432:
    goto v_24367;
v_24429:
    goto v_24440;
v_24436:
    goto v_24446;
v_24442:
    stack[0] = elt(env, 7); // !"
    goto v_24443;
v_24444:
    v_24671 = stack[-9];
    v_24671 = Lexplode(nil, v_24671);
    env = stack[-10];
    goto v_24445;
v_24446:
    goto v_24442;
v_24443:
    goto v_24444;
v_24445:
    stack[0] = cons(stack[0], v_24671);
    env = stack[-10];
    goto v_24437;
v_24438:
    v_24671 = elt(env, 7); // !"
    v_24671 = ncons(v_24671);
    env = stack[-10];
    goto v_24439;
v_24440:
    goto v_24436;
v_24437:
    goto v_24438;
v_24439:
    v_24671 = Lappend(nil, stack[0], v_24671);
    env = stack[-10];
    v_24671 = Lcompress(nil, v_24671);
    env = stack[-10];
    stack[-9] = v_24671;
    v_24671 = stack[-9];
    fn = elt(env, 19); // prin2!*
    v_24671 = (*qfn1(fn))(fn, v_24671);
    env = stack[-10];
    v_24671 = stack[-7];
    if (v_24671 == nil) goto v_24457;
    v_24671 = elt(env, 8); // "("
    fn = elt(env, 19); // prin2!*
    v_24671 = (*qfn1(fn))(fn, v_24671);
    env = stack[-10];
    v_24671 = nil;
    qvalue(elt(env, 9)) = v_24671; // obrkp!*
    goto v_24469;
v_24463:
    v_24673 = elt(env, 10); // !*comma!*
    goto v_24464;
v_24465:
    v_24672 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24466;
v_24467:
    v_24671 = stack[-7];
    goto v_24468;
v_24469:
    goto v_24463;
v_24464:
    goto v_24465;
v_24466:
    goto v_24467;
v_24468:
    fn = elt(env, 20); // inprint
    v_24671 = (*qfnn(fn))(fn, 3, v_24673, v_24672, v_24671);
    env = stack[-10];
    v_24671 = lisp_true;
    qvalue(elt(env, 9)) = v_24671; // obrkp!*
    v_24671 = elt(env, 11); // ")"
    fn = elt(env, 19); // prin2!*
    v_24671 = (*qfn1(fn))(fn, v_24671);
    goto v_24455;
v_24457:
v_24455:
    v_24671 = stack[-8];
    goto v_24366;
v_24367:
    v_24671 = stack[-9];
    v_24671 = Lexplode(nil, v_24671);
    env = stack[-10];
    v_24671 = Lreverse(nil, v_24671);
    env = stack[-10];
    stack[-9] = v_24671;
    goto v_24489;
v_24485:
    v_24671 = stack[-9];
    v_24672 = Llength(nil, v_24671);
    env = stack[-10];
    goto v_24486;
v_24487:
    v_24671 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_24488;
v_24489:
    goto v_24485;
v_24486:
    goto v_24487;
v_24488:
    v_24671 = (LispObject)greaterp2(v_24672, v_24671);
    v_24671 = v_24671 ? lisp_true : nil;
    env = stack[-10];
    if (v_24671 == nil) goto v_24483;
    goto v_24501;
v_24497:
    v_24671 = stack[-9];
    v_24671 = qcdr(v_24671);
    v_24672 = qcar(v_24671);
    goto v_24498;
v_24499:
    v_24671 = elt(env, 12); // !-
    goto v_24500;
v_24501:
    goto v_24497;
v_24498:
    goto v_24499;
v_24500:
    if (v_24672 == v_24671) goto v_24495;
    else goto v_24496;
v_24495:
    goto v_24512;
v_24508:
    v_24672 = elt(env, 12); // !-
    goto v_24509;
v_24510:
    v_24671 = elt(env, 13); // !1
    goto v_24511;
v_24512:
    goto v_24508;
v_24509:
    goto v_24510;
v_24511:
    v_24671 = list2(v_24672, v_24671);
    env = stack[-10];
    v_24671 = Lcompress(nil, v_24671);
    env = stack[-10];
    stack[-6] = v_24671;
    goto v_24522;
v_24518:
    v_24672 = stack[-9];
    goto v_24519;
v_24520:
    v_24671 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_24521;
v_24522:
    goto v_24518;
v_24519:
    goto v_24520;
v_24521:
    fn = elt(env, 21); // pnth
    v_24671 = (*qfn2(fn))(fn, v_24672, v_24671);
    env = stack[-10];
    v_24671 = Lreverse(nil, v_24671);
    env = stack[-10];
    v_24671 = Lcompress(nil, v_24671);
    env = stack[-10];
    stack[-9] = v_24671;
    goto v_24494;
v_24496:
    goto v_24532;
v_24528:
    v_24671 = stack[-9];
    v_24672 = qcar(v_24671);
    goto v_24529;
v_24530:
    v_24671 = elt(env, 14); // !+
    goto v_24531;
v_24532:
    goto v_24528;
v_24529:
    goto v_24530;
v_24531:
    if (v_24672 == v_24671) goto v_24526;
    else goto v_24527;
v_24526:
    v_24671 = elt(env, 14); // !+
    stack[-6] = v_24671;
    goto v_24544;
v_24540:
    v_24672 = stack[-9];
    goto v_24541;
v_24542:
    v_24671 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_24543;
v_24544:
    goto v_24540;
v_24541:
    goto v_24542;
v_24543:
    fn = elt(env, 21); // pnth
    v_24671 = (*qfn2(fn))(fn, v_24672, v_24671);
    env = stack[-10];
    v_24671 = Lreverse(nil, v_24671);
    env = stack[-10];
    v_24671 = Lcompress(nil, v_24671);
    env = stack[-10];
    stack[-9] = v_24671;
    goto v_24494;
v_24527:
    v_24671 = stack[-9];
    v_24671 = Lreverse(nil, v_24671);
    env = stack[-10];
    v_24671 = Lcompress(nil, v_24671);
    env = stack[-10];
    stack[-9] = v_24671;
    goto v_24494;
v_24494:
    goto v_24481;
v_24483:
    v_24671 = stack[-9];
    v_24671 = Lreverse(nil, v_24671);
    env = stack[-10];
    v_24671 = Lcompress(nil, v_24671);
    env = stack[-10];
    stack[-9] = v_24671;
    goto v_24481;
v_24481:
    goto v_24564;
v_24560:
    goto v_24570;
v_24566:
    stack[0] = elt(env, 7); // !"
    goto v_24567;
v_24568:
    v_24671 = stack[-9];
    v_24671 = Lexplode(nil, v_24671);
    env = stack[-10];
    goto v_24569;
v_24570:
    goto v_24566;
v_24567:
    goto v_24568;
v_24569:
    stack[0] = cons(stack[0], v_24671);
    env = stack[-10];
    goto v_24561;
v_24562:
    v_24671 = elt(env, 7); // !"
    v_24671 = ncons(v_24671);
    env = stack[-10];
    goto v_24563;
v_24564:
    goto v_24560;
v_24561:
    goto v_24562;
v_24563:
    v_24671 = Lappend(nil, stack[0], v_24671);
    env = stack[-10];
    v_24671 = Lcompress(nil, v_24671);
    env = stack[-10];
    stack[-9] = v_24671;
    v_24671 = stack[-7];
    if (v_24671 == nil) goto v_24579;
    goto v_24586;
v_24582:
    v_24672 = stack[-9];
    goto v_24583;
v_24584:
    v_24671 = stack[-7];
    goto v_24585;
v_24586:
    goto v_24582;
v_24583:
    goto v_24584;
v_24585:
    v_24671 = cons(v_24672, v_24671);
    env = stack[-10];
    goto v_24577;
v_24579:
    v_24671 = stack[-9];
    goto v_24577;
    v_24671 = nil;
v_24577:
    stack[-3] = v_24671;
    goto v_24602;
v_24594:
    stack[-2] = elt(env, 0); // physoppri
    goto v_24595;
v_24596:
    stack[-1] = elt(env, 1); // "x= "
    goto v_24597;
v_24598:
    stack[0] = stack[-9];
    goto v_24599;
v_24600:
    goto v_24615;
v_24607:
    v_24674 = elt(env, 15); // " z= "
    goto v_24608;
v_24609:
    v_24673 = stack[-6];
    goto v_24610;
v_24611:
    v_24672 = elt(env, 16); // " x1= "
    goto v_24612;
v_24613:
    v_24671 = stack[-3];
    goto v_24614;
v_24615:
    goto v_24607;
v_24608:
    goto v_24609;
v_24610:
    goto v_24611;
v_24612:
    goto v_24613;
v_24614:
    v_24671 = list4(v_24674, v_24673, v_24672, v_24671);
    env = stack[-10];
    goto v_24601;
v_24602:
    goto v_24594;
v_24595:
    goto v_24596;
v_24597:
    goto v_24598;
v_24599:
    goto v_24600;
v_24601:
    v_24671 = list3star(stack[-2], stack[-1], stack[0], v_24671);
    env = stack[-10];
    fn = elt(env, 18); // trwrite
    v_24671 = (*qfn1(fn))(fn, v_24671);
    env = stack[-10];
    v_24671 = stack[-6];
    if (v_24671 == nil) goto v_24623;
    goto v_24630;
v_24626:
    goto v_24638;
v_24632:
    v_24673 = elt(env, 17); // expt
    goto v_24633;
v_24634:
    v_24672 = stack[-3];
    goto v_24635;
v_24636:
    v_24671 = stack[-6];
    goto v_24637;
v_24638:
    goto v_24632;
v_24633:
    goto v_24634;
v_24635:
    goto v_24636;
v_24637:
    v_24672 = list3(v_24673, v_24672, v_24671);
    env = stack[-10];
    goto v_24627;
v_24628:
    v_24671 = elt(env, 17); // expt
    if (!symbolp(v_24671)) v_24671 = nil;
    else { v_24671 = qfastgets(v_24671);
           if (v_24671 != nil) { v_24671 = elt(v_24671, 23); // infix
#ifdef RECORD_GET
             if (v_24671 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_24671 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_24671 == SPID_NOPROP) v_24671 = nil; }}
#endif
    goto v_24629;
v_24630:
    goto v_24626;
v_24627:
    goto v_24628;
v_24629:
    fn = elt(env, 22); // exptpri
    v_24671 = (*qfn2(fn))(fn, v_24672, v_24671);
    goto v_24621;
v_24623:
    v_24671 = stack[-9];
    fn = elt(env, 19); // prin2!*
    v_24671 = (*qfn1(fn))(fn, v_24671);
    env = stack[-10];
    v_24671 = stack[-7];
    if (v_24671 == nil) goto v_24651;
    v_24671 = elt(env, 8); // "("
    fn = elt(env, 19); // prin2!*
    v_24671 = (*qfn1(fn))(fn, v_24671);
    env = stack[-10];
    v_24671 = nil;
    qvalue(elt(env, 9)) = v_24671; // obrkp!*
    goto v_24663;
v_24657:
    v_24673 = elt(env, 10); // !*comma!*
    goto v_24658;
v_24659:
    v_24672 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24660;
v_24661:
    v_24671 = stack[-7];
    goto v_24662;
v_24663:
    goto v_24657;
v_24658:
    goto v_24659;
v_24660:
    goto v_24661;
v_24662:
    fn = elt(env, 20); // inprint
    v_24671 = (*qfnn(fn))(fn, 3, v_24673, v_24672, v_24671);
    env = stack[-10];
    v_24671 = lisp_true;
    qvalue(elt(env, 9)) = v_24671; // obrkp!*
    v_24671 = elt(env, 11); // ")"
    fn = elt(env, 19); // prin2!*
    v_24671 = (*qfn1(fn))(fn, v_24671);
    goto v_24649;
v_24651:
v_24649:
    goto v_24621;
v_24621:
    v_24671 = stack[-8];
v_24366:
    return onevalue(v_24671);
}



// Code for nonmult

static LispObject CC_nonmult(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24380, v_24381;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24359;
// end of prologue
    goto v_24366;
v_24362:
    goto v_24372;
v_24368:
    v_24380 = qvalue(elt(env, 1)); // vjets!*
    v_24381 = Lreverse(nil, v_24380);
    env = stack[-1];
    goto v_24369;
v_24370:
    v_24380 = stack[0];
    goto v_24371;
v_24372:
    goto v_24368;
v_24369:
    goto v_24370;
v_24371:
    fn = elt(env, 2); // nth
    stack[0] = (*qfn2(fn))(fn, v_24381, v_24380);
    env = stack[-1];
    goto v_24363;
v_24364:
    v_24380 = qvalue(elt(env, 1)); // vjets!*
    v_24380 = Lreverse(nil, v_24380);
    goto v_24365;
v_24366:
    goto v_24362;
v_24363:
    goto v_24364;
v_24365:
    v_24380 = Lmember(nil, stack[0], v_24380);
    v_24380 = qcdr(v_24380);
        return Lreverse(nil, v_24380);
}



// Code for gadd

static LispObject CC_gadd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24482, v_24483, v_24484;
    LispObject fn;
    LispObject v_24361, v_24360, v_24359;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "gadd");
    va_start(aa, nargs);
    v_24359 = va_arg(aa, LispObject);
    v_24360 = va_arg(aa, LispObject);
    v_24361 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24361,v_24360,v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24359,v_24360,v_24361);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_24361;
    stack[-3] = v_24360;
    stack[-4] = v_24359;
// end of prologue
    stack[-5] = nil;
    v_24482 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_24482;
    goto v_24381;
v_24377:
    v_24483 = stack[-2];
    goto v_24378;
v_24379:
    v_24482 = stack[-3];
    goto v_24380;
v_24381:
    goto v_24377;
v_24378:
    goto v_24379;
v_24380:
    v_24482 = Latsoc(nil, v_24483, v_24482);
    stack[-1] = v_24482;
    if (v_24482 == nil) goto v_24375;
    else goto v_24376;
v_24375:
    goto v_24368;
v_24376:
    goto v_24390;
v_24386:
    v_24483 = stack[-1];
    goto v_24387;
v_24388:
    v_24482 = stack[-3];
    goto v_24389;
v_24390:
    goto v_24386;
v_24387:
    goto v_24388;
v_24389:
    v_24482 = Ldelete(nil, v_24483, v_24482);
    env = stack[-6];
    stack[-3] = v_24482;
    v_24482 = stack[-1];
    v_24482 = qcdr(v_24482);
    v_24482 = qcdr(v_24482);
    stack[-5] = v_24482;
    v_24482 = stack[-1];
    v_24482 = qcdr(v_24482);
    v_24482 = qcar(v_24482);
    stack[-1] = v_24482;
v_24368:
    v_24482 = stack[-4];
    if (v_24482 == nil) goto v_24401;
    else goto v_24402;
v_24401:
    goto v_24411;
v_24405:
    v_24482 = stack[0];
    stack[0] = Levenp(nil, v_24482);
    env = stack[-6];
    goto v_24406;
v_24407:
    goto v_24421;
v_24415:
    v_24484 = stack[-2];
    goto v_24416;
v_24417:
    v_24483 = stack[-1];
    goto v_24418;
v_24419:
    v_24482 = stack[-5];
    goto v_24420;
v_24421:
    goto v_24415;
v_24416:
    goto v_24417;
v_24418:
    goto v_24419;
v_24420:
    v_24483 = list2star(v_24484, v_24483, v_24482);
    goto v_24408;
v_24409:
    v_24482 = stack[-3];
    goto v_24410;
v_24411:
    goto v_24405;
v_24406:
    goto v_24407;
v_24408:
    goto v_24409;
v_24410:
    {
        LispObject v_24491 = stack[0];
        return list2star(v_24491, v_24483, v_24482);
    }
v_24402:
    goto v_24432;
v_24428:
    v_24482 = stack[-4];
    v_24483 = qcar(v_24482);
    goto v_24429;
v_24430:
    v_24482 = elt(env, 1); // a
    goto v_24431;
v_24432:
    goto v_24428;
v_24429:
    goto v_24430;
v_24431:
    if (v_24483 == v_24482) goto v_24426;
    else goto v_24427;
v_24426:
    goto v_24370;
v_24427:
    goto v_24443;
v_24439:
    v_24482 = stack[-4];
    v_24483 = qcar(v_24482);
    goto v_24440;
v_24441:
    v_24482 = stack[-5];
    goto v_24442;
v_24443:
    goto v_24439;
v_24440:
    goto v_24441;
v_24442:
    v_24482 = cons(v_24483, v_24482);
    env = stack[-6];
    stack[-5] = v_24482;
    goto v_24400;
v_24400:
v_24369:
    v_24482 = stack[-4];
    v_24482 = qcdr(v_24482);
    stack[-4] = v_24482;
    goto v_24368;
v_24370:
    goto v_24457;
v_24453:
    v_24483 = qvalue(elt(env, 2)); // ndims!*
    goto v_24454;
v_24455:
    v_24482 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_24456;
v_24457:
    goto v_24453;
v_24454:
    goto v_24455;
v_24456:
    if (v_24483 == v_24482) goto v_24452;
    goto v_24467;
v_24461:
    v_24484 = elt(env, 3); // hephys
    goto v_24462;
v_24463:
    v_24483 = (LispObject)128+TAG_FIXNUM; // 8
    goto v_24464;
v_24465:
    v_24482 = elt(env, 4); // "Gamma5 not allowed unless vecdim is 4"
    goto v_24466;
v_24467:
    goto v_24461;
v_24462:
    goto v_24463;
v_24464:
    goto v_24465;
v_24466:
    fn = elt(env, 5); // rerror
    v_24482 = (*qfnn(fn))(fn, 3, v_24484, v_24483, v_24482);
    env = stack[-6];
    goto v_24450;
v_24452:
v_24450:
    v_24482 = stack[-1];
    v_24482 = (v_24482 == nil ? lisp_true : nil);
    stack[-1] = v_24482;
    goto v_24478;
v_24474:
    v_24482 = stack[-5];
    v_24483 = Llength(nil, v_24482);
    env = stack[-6];
    goto v_24475;
v_24476:
    v_24482 = stack[0];
    goto v_24477;
v_24478:
    goto v_24474;
v_24475:
    goto v_24476;
v_24477:
    v_24482 = plus2(v_24483, v_24482);
    env = stack[-6];
    stack[0] = v_24482;
    goto v_24369;
    return onevalue(v_24482);
}



// Code for fctlength

static LispObject CC_fctlength(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24364;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
// copy arguments values to proper place
    v_24364 = v_24359;
// end of prologue
    fn = elt(env, 1); // fctargs
    v_24364 = (*qfn1(fn))(fn, v_24364);
        return Llength(nil, v_24364);
}



// Code for rl_identity1

static LispObject CC_rl_identity1(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24362;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24362 = v_24359;
// end of prologue
    return onevalue(v_24362);
}



// Code for prsubsetrd

static LispObject CC_prsubsetrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24381, v_24382;
    LispObject fn;
    argcheck(nargs, 0, "prsubsetrd");
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
    v_24381 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_24382 = v_24381;
    v_24381 = v_24382;
    if (v_24381 == nil) goto v_24367;
    else goto v_24368;
v_24367:
    v_24381 = nil;
    goto v_24366;
v_24368:
    goto v_24378;
v_24374:
    stack[0] = v_24382;
    goto v_24375;
v_24376:
    v_24381 = CC_prsubsetrd(elt(env, 0), 0);
    goto v_24377;
v_24378:
    goto v_24374;
v_24375:
    goto v_24376;
v_24377:
    {
        LispObject v_24384 = stack[0];
        return cons(v_24384, v_24381);
    }
    v_24381 = nil;
v_24366:
    return onevalue(v_24381);
}



// Code for f4

static LispObject CC_f4(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24597, v_24598;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24359;
// end of prologue
    goto v_24371;
v_24367:
    v_24598 = stack[0];
    goto v_24368;
v_24369:
    v_24597 = elt(env, 1); // pi
    goto v_24370;
v_24371:
    goto v_24367;
v_24368:
    goto v_24369;
v_24370:
    if (v_24598 == v_24597) goto v_24365;
    else goto v_24366;
v_24365:
    v_24597 = elt(env, 2); // "<pi/>"
    v_24597 = Lprinc(nil, v_24597);
    goto v_24364;
v_24366:
    goto v_24382;
v_24378:
    v_24598 = stack[0];
    goto v_24379;
v_24380:
    v_24597 = elt(env, 3); // euler_gamma
    goto v_24381;
v_24382:
    goto v_24378;
v_24379:
    goto v_24380;
v_24381:
    if (v_24598 == v_24597) goto v_24376;
    else goto v_24377;
v_24376:
    v_24597 = elt(env, 4); // "<eulergamma/>"
    v_24597 = Lprinc(nil, v_24597);
    goto v_24364;
v_24377:
    goto v_24393;
v_24389:
    v_24598 = stack[0];
    goto v_24390;
v_24391:
    v_24597 = elt(env, 5); // true
    goto v_24392;
v_24393:
    goto v_24389;
v_24390:
    goto v_24391;
v_24392:
    if (v_24598 == v_24597) goto v_24387;
    else goto v_24388;
v_24387:
    v_24597 = elt(env, 6); // "<true/>"
    v_24597 = Lprinc(nil, v_24597);
    goto v_24364;
v_24388:
    goto v_24404;
v_24400:
    v_24598 = stack[0];
    goto v_24401;
v_24402:
    v_24597 = elt(env, 7); // false
    goto v_24403;
v_24404:
    goto v_24400;
v_24401:
    goto v_24402;
v_24403:
    if (v_24598 == v_24597) goto v_24398;
    else goto v_24399;
v_24398:
    v_24597 = elt(env, 8); // "<false/>"
    v_24597 = Lprinc(nil, v_24597);
    goto v_24364;
v_24399:
    goto v_24415;
v_24411:
    v_24598 = stack[0];
    goto v_24412;
v_24413:
    v_24597 = elt(env, 9); // !Na!N
    goto v_24414;
v_24415:
    goto v_24411;
v_24412:
    goto v_24413;
v_24414:
    if (v_24598 == v_24597) goto v_24409;
    else goto v_24410;
v_24409:
    v_24597 = elt(env, 10); // "<notanumber/>"
    v_24597 = Lprinc(nil, v_24597);
    goto v_24364;
v_24410:
    goto v_24426;
v_24422:
    v_24598 = stack[0];
    goto v_24423;
v_24424:
    v_24597 = elt(env, 11); // infinity
    goto v_24425;
v_24426:
    goto v_24422;
v_24423:
    goto v_24424;
v_24425:
    if (v_24598 == v_24597) goto v_24420;
    else goto v_24421;
v_24420:
    v_24597 = qvalue(elt(env, 12)); // !*web
    if (v_24597 == nil) goto v_24431;
    else goto v_24432;
v_24431:
    v_24597 = elt(env, 13); // "<cn type=""constant"">"
    fn = elt(env, 33); // printout
    v_24597 = (*qfn1(fn))(fn, v_24597);
    env = stack[-1];
    goto v_24430;
v_24432:
    v_24597 = elt(env, 14); // "<cn type=&quot;constant&quot;>"
    fn = elt(env, 33); // printout
    v_24597 = (*qfn1(fn))(fn, v_24597);
    env = stack[-1];
    goto v_24430;
v_24430:
    v_24597 = elt(env, 15); // "&infin;"
    v_24597 = Lprinc(nil, v_24597);
    env = stack[-1];
    v_24597 = elt(env, 16); // "</cn>"
    v_24597 = Lprinc(nil, v_24597);
    goto v_24364;
v_24421:
    goto v_24454;
v_24450:
    v_24598 = stack[0];
    goto v_24451;
v_24452:
    v_24597 = elt(env, 17); // e
    goto v_24453;
v_24454:
    goto v_24450;
v_24451:
    goto v_24452;
v_24453:
    if (v_24598 == v_24597) goto v_24448;
    else goto v_24449;
v_24448:
    v_24597 = qvalue(elt(env, 12)); // !*web
    if (v_24597 == nil) goto v_24459;
    else goto v_24460;
v_24459:
    v_24597 = elt(env, 13); // "<cn type=""constant"">"
    fn = elt(env, 33); // printout
    v_24597 = (*qfn1(fn))(fn, v_24597);
    env = stack[-1];
    goto v_24458;
v_24460:
    v_24597 = elt(env, 14); // "<cn type=&quot;constant&quot;>"
    fn = elt(env, 33); // printout
    v_24597 = (*qfn1(fn))(fn, v_24597);
    env = stack[-1];
    goto v_24458;
v_24458:
    v_24597 = elt(env, 18); // "&ExponentialE;"
    v_24597 = Lprinc(nil, v_24597);
    env = stack[-1];
    v_24597 = elt(env, 16); // "</cn>"
    v_24597 = Lprinc(nil, v_24597);
    goto v_24447;
v_24449:
    goto v_24482;
v_24478:
    v_24598 = stack[0];
    goto v_24479;
v_24480:
    v_24597 = elt(env, 19); // i
    goto v_24481;
v_24482:
    goto v_24478;
v_24479:
    goto v_24480;
v_24481:
    if (v_24598 == v_24597) goto v_24476;
    else goto v_24477;
v_24476:
    v_24597 = qvalue(elt(env, 12)); // !*web
    if (v_24597 == nil) goto v_24487;
    else goto v_24488;
v_24487:
    v_24597 = elt(env, 13); // "<cn type=""constant"">"
    fn = elt(env, 33); // printout
    v_24597 = (*qfn1(fn))(fn, v_24597);
    env = stack[-1];
    goto v_24486;
v_24488:
    v_24597 = elt(env, 14); // "<cn type=&quot;constant&quot;>"
    fn = elt(env, 33); // printout
    v_24597 = (*qfn1(fn))(fn, v_24597);
    env = stack[-1];
    goto v_24486;
v_24486:
    v_24597 = elt(env, 20); // "&ImaginaryI;"
    v_24597 = Lprinc(nil, v_24597);
    env = stack[-1];
    v_24597 = elt(env, 16); // "</cn>"
    v_24597 = Lprinc(nil, v_24597);
    goto v_24475;
v_24477:
    v_24597 = stack[0];
    if (is_number(v_24597)) goto v_24504;
    else goto v_24505;
v_24504:
    v_24597 = elt(env, 21); // "<cn"
    fn = elt(env, 33); // printout
    v_24597 = (*qfn1(fn))(fn, v_24597);
    env = stack[-1];
    v_24597 = stack[0];
    v_24597 = Lfloatp(nil, v_24597);
    env = stack[-1];
    if (v_24597 == nil) goto v_24512;
    v_24597 = qvalue(elt(env, 12)); // !*web
    if (v_24597 == nil) goto v_24517;
    else goto v_24518;
v_24517:
    v_24597 = elt(env, 22); // " type=""real"">"
    v_24597 = Lprinc(nil, v_24597);
    env = stack[-1];
    goto v_24516;
v_24518:
    v_24597 = elt(env, 23); // " type=&quot;real&quot;>"
    v_24597 = Lprinc(nil, v_24597);
    env = stack[-1];
    goto v_24516;
v_24516:
    goto v_24510;
v_24512:
    v_24597 = stack[0];
    v_24597 = integerp(v_24597);
    if (v_24597 == nil) goto v_24527;
    v_24597 = qvalue(elt(env, 12)); // !*web
    if (v_24597 == nil) goto v_24532;
    else goto v_24533;
v_24532:
    v_24597 = elt(env, 24); // " type=""integer"">"
    v_24597 = Lprinc(nil, v_24597);
    env = stack[-1];
    goto v_24531;
v_24533:
    v_24597 = elt(env, 25); // " type=&quot;integer&quot;>"
    v_24597 = Lprinc(nil, v_24597);
    env = stack[-1];
    goto v_24531;
v_24531:
    goto v_24510;
v_24527:
    v_24597 = elt(env, 26); // ">"
    v_24597 = Lprinc(nil, v_24597);
    env = stack[-1];
    goto v_24510;
v_24510:
    v_24597 = stack[0];
    v_24597 = Lprinc(nil, v_24597);
    env = stack[-1];
    v_24597 = elt(env, 16); // "</cn>"
    v_24597 = Lprinc(nil, v_24597);
    env = stack[-1];
    goto v_24503;
v_24505:
v_24503:
    v_24597 = stack[0];
    if (symbolp(v_24597)) goto v_24551;
    else goto v_24552;
v_24551:
    v_24597 = elt(env, 27); // "<ci"
    fn = elt(env, 33); // printout
    v_24597 = (*qfn1(fn))(fn, v_24597);
    env = stack[-1];
    v_24597 = stack[0];
    fn = elt(env, 34); // listp
    v_24597 = (*qfn1(fn))(fn, v_24597);
    env = stack[-1];
    if (v_24597 == nil) goto v_24559;
    v_24597 = qvalue(elt(env, 12)); // !*web
    if (v_24597 == nil) goto v_24564;
    else goto v_24565;
v_24564:
    v_24597 = elt(env, 28); // " type=""list"">"
    v_24597 = Lprinc(nil, v_24597);
    env = stack[-1];
    goto v_24563;
v_24565:
    v_24597 = elt(env, 29); // " type=&quot;list&quot;>"
    v_24597 = Lprinc(nil, v_24597);
    env = stack[-1];
    goto v_24563;
v_24563:
    goto v_24557;
v_24559:
    v_24597 = stack[0];
    v_24597 = Lsimple_vectorp(nil, v_24597);
    env = stack[-1];
    if (v_24597 == nil) goto v_24574;
    v_24597 = qvalue(elt(env, 12)); // !*web
    if (v_24597 == nil) goto v_24579;
    else goto v_24580;
v_24579:
    v_24597 = elt(env, 30); // " type=""vector"">"
    v_24597 = Lprinc(nil, v_24597);
    env = stack[-1];
    goto v_24578;
v_24580:
    v_24597 = elt(env, 31); // " type=&quot;vector&quot;>"
    v_24597 = Lprinc(nil, v_24597);
    env = stack[-1];
    goto v_24578;
v_24578:
    goto v_24557;
v_24574:
    v_24597 = elt(env, 26); // ">"
    v_24597 = Lprinc(nil, v_24597);
    env = stack[-1];
    goto v_24557;
v_24557:
    v_24597 = stack[0];
    v_24597 = Lprinc(nil, v_24597);
    env = stack[-1];
    v_24597 = elt(env, 32); // "</ci>"
    v_24597 = Lprinc(nil, v_24597);
    goto v_24550;
v_24552:
v_24550:
    goto v_24475;
v_24475:
    goto v_24447;
v_24447:
    goto v_24364;
v_24364:
    v_24597 = nil;
    return onevalue(v_24597);
}



// Code for findoptrow

static LispObject CC_findoptrow(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24546, v_24547, v_24548, v_24549;
    LispObject fn;
    LispObject v_24361, v_24360, v_24359;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "findoptrow");
    va_start(aa, nargs);
    v_24359 = va_arg(aa, LispObject);
    v_24360 = va_arg(aa, LispObject);
    v_24361 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24361,v_24360,v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24359,v_24360,v_24361);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_24361;
    stack[0] = v_24360;
    stack[-6] = v_24359;
// end of prologue
    stack[-7] = nil;
    goto v_24375;
v_24371:
    stack[-2] = stack[0];
    goto v_24372;
v_24373:
    goto v_24381;
v_24377:
    goto v_24386;
v_24382:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_24383;
v_24384:
    goto v_24393;
v_24389:
    v_24547 = qvalue(elt(env, 2)); // maxvar
    goto v_24390;
v_24391:
    v_24546 = stack[-6];
    goto v_24392;
v_24393:
    goto v_24389;
v_24390:
    goto v_24391;
v_24392:
    v_24546 = plus2(v_24547, v_24546);
    env = stack[-8];
    goto v_24385;
v_24386:
    goto v_24382;
v_24383:
    goto v_24384;
v_24385:
    v_24547 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_24546-TAG_FIXNUM)/(16/CELL)));
    goto v_24378;
v_24379:
    v_24546 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_24380;
v_24381:
    goto v_24377;
v_24378:
    goto v_24379;
v_24380:
    v_24546 = *(LispObject *)((char *)v_24547 + (CELL-TAG_VECTOR) + (((intptr_t)v_24546-TAG_FIXNUM)/(16/CELL)));
    goto v_24374;
v_24375:
    goto v_24371;
v_24372:
    goto v_24373;
v_24374:
    fn = elt(env, 7); // pnthxzz
    v_24546 = (*qfn2(fn))(fn, stack[-2], v_24546);
    env = stack[-8];
    v_24546 = qcar(v_24546);
    v_24546 = qcdr(v_24546);
    v_24546 = qcar(v_24546);
    stack[-3] = v_24546;
    goto v_24410;
v_24406:
    goto v_24415;
v_24411:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_24412;
v_24413:
    goto v_24422;
v_24418:
    v_24547 = qvalue(elt(env, 2)); // maxvar
    goto v_24419;
v_24420:
    v_24546 = stack[0];
    goto v_24421;
v_24422:
    goto v_24418;
v_24419:
    goto v_24420;
v_24421:
    v_24546 = plus2(v_24547, v_24546);
    env = stack[-8];
    goto v_24414;
v_24415:
    goto v_24411;
v_24412:
    goto v_24413;
v_24414:
    v_24547 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_24546-TAG_FIXNUM)/(16/CELL)));
    goto v_24407;
v_24408:
    v_24546 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_24409;
v_24410:
    goto v_24406;
v_24407:
    goto v_24408;
v_24409:
    v_24546 = *(LispObject *)((char *)v_24547 + (CELL-TAG_VECTOR) + (((intptr_t)v_24546-TAG_FIXNUM)/(16/CELL)));
    stack[-2] = v_24546;
v_24405:
    v_24546 = stack[-2];
    if (v_24546 == nil) goto v_24430;
    else goto v_24431;
v_24430:
    goto v_24404;
v_24431:
    v_24546 = stack[-2];
    v_24546 = qcar(v_24546);
    stack[-1] = v_24546;
    goto v_24445;
v_24441:
    goto v_24450;
v_24446:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_24447;
v_24448:
    goto v_24457;
v_24453:
    v_24547 = qvalue(elt(env, 2)); // maxvar
    goto v_24454;
v_24455:
    v_24546 = stack[-1];
    v_24546 = qcar(v_24546);
    stack[-4] = v_24546;
    goto v_24456;
v_24457:
    goto v_24453;
v_24454:
    goto v_24455;
v_24456:
    v_24546 = plus2(v_24547, v_24546);
    env = stack[-8];
    goto v_24449;
v_24450:
    goto v_24446;
v_24447:
    goto v_24448;
v_24449:
    v_24547 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_24546-TAG_FIXNUM)/(16/CELL)));
    goto v_24442;
v_24443:
    v_24546 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24444;
v_24445:
    goto v_24441;
v_24442:
    goto v_24443;
v_24444:
    v_24546 = *(LispObject *)((char *)v_24547 + (CELL-TAG_VECTOR) + (((intptr_t)v_24546-TAG_FIXNUM)/(16/CELL)));
    if (v_24546 == nil) goto v_24440;
    goto v_24477;
v_24469:
    v_24549 = stack[-4];
    goto v_24470;
v_24471:
    v_24548 = stack[-6];
    goto v_24472;
v_24473:
    v_24546 = stack[-1];
    v_24546 = qcdr(v_24546);
    v_24547 = qcar(v_24546);
    goto v_24474;
v_24475:
    v_24546 = stack[-3];
    goto v_24476;
v_24477:
    goto v_24469;
v_24470:
    goto v_24471;
v_24472:
    goto v_24473;
v_24474:
    goto v_24475;
v_24476:
    fn = elt(env, 8); // testpr
    v_24546 = (*qfnn(fn))(fn, 4, v_24549, v_24548, v_24547, v_24546);
    env = stack[-8];
    stack[0] = v_24546;
    v_24546 = qcdr(v_24546);
    if (v_24546 == nil) goto v_24466;
    else goto v_24467;
v_24466:
    goto v_24490;
v_24486:
    v_24547 = stack[-4];
    goto v_24487;
v_24488:
    v_24546 = qvalue(elt(env, 3)); // roccup1
    goto v_24489;
v_24490:
    goto v_24486;
v_24487:
    goto v_24488;
v_24489:
    v_24546 = cons(v_24547, v_24546);
    env = stack[-8];
    qvalue(elt(env, 3)) = v_24546; // roccup1
    goto v_24465;
v_24467:
    goto v_24504;
v_24500:
    v_24546 = stack[0];
    v_24547 = Llength(nil, v_24546);
    env = stack[-8];
    stack[-1] = v_24547;
    goto v_24501;
v_24502:
    v_24546 = stack[-5];
    goto v_24503;
v_24504:
    goto v_24500;
v_24501:
    goto v_24502;
v_24503:
    v_24546 = (LispObject)greaterp2(v_24547, v_24546);
    v_24546 = v_24546 ? lisp_true : nil;
    env = stack[-8];
    if (v_24546 == nil) goto v_24498;
    v_24546 = stack[-1];
    stack[-5] = v_24546;
    qvalue(elt(env, 4)) = v_24546; // newnjsi
    v_24546 = stack[-4];
    stack[-7] = v_24546;
    v_24546 = stack[0];
    qvalue(elt(env, 5)) = v_24546; // newjsi
    goto v_24496;
v_24498:
v_24496:
    goto v_24516;
v_24512:
    v_24547 = stack[-4];
    goto v_24513;
v_24514:
    v_24546 = qvalue(elt(env, 6)); // roccup2
    goto v_24515;
v_24516:
    goto v_24512;
v_24513:
    goto v_24514;
v_24515:
    v_24546 = cons(v_24547, v_24546);
    env = stack[-8];
    qvalue(elt(env, 6)) = v_24546; // roccup2
    goto v_24465;
v_24465:
    goto v_24525;
v_24519:
    goto v_24530;
v_24526:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_24527;
v_24528:
    goto v_24537;
v_24533:
    v_24547 = qvalue(elt(env, 2)); // maxvar
    goto v_24534;
v_24535:
    v_24546 = stack[-4];
    goto v_24536;
v_24537:
    goto v_24533;
v_24534:
    goto v_24535;
v_24536:
    v_24546 = plus2(v_24547, v_24546);
    env = stack[-8];
    goto v_24529;
v_24530:
    goto v_24526;
v_24527:
    goto v_24528;
v_24529:
    v_24548 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_24546-TAG_FIXNUM)/(16/CELL)));
    goto v_24520;
v_24521:
    v_24547 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24522;
v_24523:
    v_24546 = nil;
    goto v_24524;
v_24525:
    goto v_24519;
v_24520:
    goto v_24521;
v_24522:
    goto v_24523;
v_24524:
    *(LispObject *)((char *)v_24548 + (CELL-TAG_VECTOR) + (((intptr_t)v_24547-TAG_FIXNUM)/(16/CELL))) = v_24546;
    goto v_24438;
v_24440:
v_24438:
    v_24546 = stack[-2];
    v_24546 = qcdr(v_24546);
    stack[-2] = v_24546;
    goto v_24405;
v_24404:
    v_24546 = stack[-7];
    return onevalue(v_24546);
}



// Code for find_bubles_coeff

static LispObject CC_find_bubles_coeff(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24377, v_24378, v_24379, v_24380;
    LispObject fn;
    LispObject v_24361, v_24360, v_24359;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "find_bubles_coeff");
    va_start(aa, nargs);
    v_24359 = va_arg(aa, LispObject);
    v_24360 = va_arg(aa, LispObject);
    v_24361 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24377 = v_24361;
    v_24378 = v_24360;
    v_24379 = v_24359;
// end of prologue
    goto v_24372;
v_24364:
    v_24380 = v_24379;
    goto v_24365;
v_24366:
    v_24379 = nil;
    goto v_24367;
v_24368:
    goto v_24369;
v_24370:
    goto v_24371;
v_24372:
    goto v_24364;
v_24365:
    goto v_24366;
v_24367:
    goto v_24368;
v_24369:
    goto v_24370;
v_24371:
    {
        fn = elt(env, 1); // find_bubles1_coeff
        return (*qfnn(fn))(fn, 4, v_24380, v_24379, v_24378, v_24377);
    }
}



// Code for primep27

static LispObject CC_primep27(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24435, v_24436;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24359;
// end of prologue
    goto v_24373;
v_24369:
    v_24436 = stack[0];
    goto v_24370;
v_24371:
    v_24435 = (LispObject)23888+TAG_FIXNUM; // 1493
    goto v_24372;
v_24373:
    goto v_24369;
v_24370:
    goto v_24371;
v_24372:
    if (v_24436 == v_24435) goto v_24367;
    else goto v_24368;
v_24367:
    v_24435 = lisp_true;
    goto v_24364;
v_24368:
    v_24435 = nil;
    fn = elt(env, 1); // set!-modulus
    v_24435 = (*qfn1(fn))(fn, v_24435);
    env = stack[-2];
    stack[-1] = v_24435;
    goto v_24388;
v_24384:
    v_24436 = (LispObject)143328+TAG_FIXNUM; // 8958
    goto v_24385;
v_24386:
    v_24435 = stack[0];
    goto v_24387;
v_24388:
    goto v_24384;
v_24385:
    goto v_24386;
v_24387:
    fn = elt(env, 2); // miller!-rabin
    v_24435 = (*qfn2(fn))(fn, v_24436, v_24435);
    env = stack[-2];
    if (v_24435 == nil) goto v_24381;
    else goto v_24382;
v_24381:
    v_24435 = nil;
    goto v_24380;
v_24382:
    goto v_24403;
v_24399:
    v_24436 = (LispObject)75264+TAG_FIXNUM; // 4704
    goto v_24400;
v_24401:
    v_24435 = stack[0];
    goto v_24402;
v_24403:
    goto v_24399;
v_24400:
    goto v_24401;
v_24402:
    fn = elt(env, 2); // miller!-rabin
    v_24435 = (*qfn2(fn))(fn, v_24436, v_24435);
    env = stack[-2];
    if (v_24435 == nil) goto v_24396;
    else goto v_24397;
v_24396:
    v_24435 = nil;
    goto v_24395;
v_24397:
    goto v_24417;
v_24413:
    v_24436 = stack[0];
    goto v_24414;
v_24415:
    v_24435 = (LispObject)146102416+TAG_FIXNUM; // 9131401
    goto v_24416;
v_24417:
    goto v_24413;
v_24414:
    goto v_24415;
v_24416:
    if (v_24436 == v_24435) goto v_24411;
    else goto v_24412;
v_24411:
    v_24435 = lisp_true;
    goto v_24410;
v_24412:
    goto v_24427;
v_24423:
    v_24436 = stack[0];
    goto v_24424;
v_24425:
    v_24435 = (LispObject)97425136+TAG_FIXNUM; // 6089071
    goto v_24426;
v_24427:
    goto v_24423;
v_24424:
    goto v_24425;
v_24426:
    v_24435 = (v_24436 == v_24435 ? lisp_true : nil);
    goto v_24410;
    v_24435 = nil;
v_24410:
    v_24435 = (v_24435 == nil ? lisp_true : nil);
    goto v_24395;
    v_24435 = nil;
v_24395:
    goto v_24380;
    v_24435 = nil;
v_24380:
    stack[0] = v_24435;
    v_24435 = stack[-1];
    fn = elt(env, 1); // set!-modulus
    v_24435 = (*qfn1(fn))(fn, v_24435);
    v_24435 = stack[0];
v_24364:
    return onevalue(v_24435);
}



// Code for reduce!-columns

static LispObject CC_reduceKcolumns(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24507, v_24508;
    LispObject fn;
    LispObject v_24361, v_24360, v_24359;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "reduce-columns");
    va_start(aa, nargs);
    v_24359 = va_arg(aa, LispObject);
    v_24360 = va_arg(aa, LispObject);
    v_24361 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24361,v_24360,v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24359,v_24360,v_24361);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_24361;
    stack[-5] = v_24360;
    stack[-6] = v_24359;
// end of prologue
    v_24507 = stack[-6];
    stack[-3] = v_24507;
    v_24507 = stack[-5];
    stack[-2] = v_24507;
    goto v_24378;
v_24374:
    stack[0] = stack[-6];
    goto v_24375;
v_24376:
    goto v_24385;
v_24381:
    v_24508 = stack[-6];
    goto v_24382;
v_24383:
    v_24507 = stack[-4];
    goto v_24384;
v_24385:
    goto v_24381;
v_24382:
    goto v_24383;
v_24384:
    fn = elt(env, 1); // red!-weight
    v_24507 = (*qfn2(fn))(fn, v_24508, v_24507);
    env = stack[-8];
    goto v_24377;
v_24378:
    goto v_24374;
v_24375:
    goto v_24376;
v_24377:
    v_24507 = cons(stack[0], v_24507);
    env = stack[-8];
    stack[-7] = v_24507;
v_24370:
    v_24507 = stack[-3];
    if (v_24507 == nil) goto v_24390;
    else goto v_24391;
v_24390:
    v_24507 = stack[-7];
    v_24507 = qcar(v_24507);
    goto v_24369;
v_24391:
    goto v_24405;
v_24401:
    v_24507 = stack[-3];
    v_24508 = qcar(v_24507);
    goto v_24402;
v_24403:
    v_24507 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24404;
v_24405:
    goto v_24401;
v_24402:
    goto v_24403;
v_24404:
    if (v_24508 == v_24507) goto v_24399;
    else goto v_24400;
v_24399:
    v_24507 = lisp_true;
    goto v_24398;
v_24400:
    goto v_24416;
v_24412:
    v_24507 = stack[-2];
    v_24508 = qcar(v_24507);
    goto v_24413;
v_24414:
    v_24507 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24415;
v_24416:
    goto v_24412;
v_24413:
    goto v_24414;
v_24415:
    v_24507 = (v_24508 == v_24507 ? lisp_true : nil);
    goto v_24398;
    v_24507 = nil;
v_24398:
    if (v_24507 == nil) goto v_24396;
    goto v_24389;
v_24396:
    goto v_24428;
v_24424:
    goto v_24434;
v_24430:
    v_24507 = stack[-3];
    v_24508 = qcar(v_24507);
    goto v_24431;
v_24432:
    v_24507 = stack[-2];
    v_24507 = qcar(v_24507);
    goto v_24433;
v_24434:
    goto v_24430;
v_24431:
    goto v_24432;
v_24433:
    v_24507 = Ldivide(nil, v_24508, v_24507);
    env = stack[-8];
    stack[-1] = v_24507;
    v_24508 = qcdr(v_24507);
    goto v_24425;
v_24426:
    v_24507 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24427;
v_24428:
    goto v_24424;
v_24425:
    goto v_24426;
v_24427:
    if (v_24508 == v_24507) goto v_24422;
    else goto v_24423;
v_24422:
    goto v_24446;
v_24442:
    stack[0] = stack[-6];
    goto v_24443;
v_24444:
    goto v_24453;
v_24449:
    v_24507 = stack[-1];
    v_24508 = qcar(v_24507);
    goto v_24450;
v_24451:
    v_24507 = stack[-5];
    goto v_24452;
v_24453:
    goto v_24449;
v_24450:
    goto v_24451;
v_24452:
    fn = elt(env, 2); // mv!-domainlist!-!*
    v_24507 = (*qfn2(fn))(fn, v_24508, v_24507);
    env = stack[-8];
    goto v_24445;
v_24446:
    goto v_24442;
v_24443:
    goto v_24444;
v_24445:
    fn = elt(env, 3); // mv!-domainlist!-!-
    v_24507 = (*qfn2(fn))(fn, stack[0], v_24507);
    env = stack[-8];
    stack[-1] = v_24507;
    goto v_24462;
v_24458:
    v_24508 = stack[-1];
    goto v_24459;
v_24460:
    v_24507 = stack[-4];
    goto v_24461;
v_24462:
    goto v_24458;
v_24459:
    goto v_24460;
v_24461:
    fn = elt(env, 1); // red!-weight
    v_24507 = (*qfn2(fn))(fn, v_24508, v_24507);
    env = stack[-8];
    stack[0] = v_24507;
    goto v_24475;
v_24471:
    v_24508 = stack[0];
    goto v_24472;
v_24473:
    v_24507 = stack[-7];
    v_24507 = qcdr(v_24507);
    goto v_24474;
v_24475:
    goto v_24471;
v_24472:
    goto v_24473;
v_24474:
    fn = elt(env, 4); // red!-weight!-less!-p
    v_24507 = (*qfn2(fn))(fn, v_24508, v_24507);
    env = stack[-8];
    if (v_24507 == nil) goto v_24468;
    goto v_24485;
v_24481:
    goto v_24491;
v_24487:
    v_24508 = stack[-1];
    goto v_24488;
v_24489:
    v_24507 = stack[0];
    goto v_24490;
v_24491:
    goto v_24487;
v_24488:
    goto v_24489;
v_24490:
    v_24508 = cons(v_24508, v_24507);
    env = stack[-8];
    goto v_24482;
v_24483:
    v_24507 = stack[-7];
    goto v_24484;
v_24485:
    goto v_24481;
v_24482:
    goto v_24483;
v_24484:
    fn = elt(env, 5); // more!-apartp
    v_24507 = (*qfn2(fn))(fn, v_24508, v_24507);
    env = stack[-8];
    if (v_24507 == nil) goto v_24479;
    else goto v_24468;
v_24479:
    goto v_24500;
v_24496:
    v_24508 = stack[-1];
    goto v_24497;
v_24498:
    v_24507 = stack[0];
    goto v_24499;
v_24500:
    goto v_24496;
v_24497:
    goto v_24498;
v_24499:
    v_24507 = cons(v_24508, v_24507);
    env = stack[-8];
    stack[-7] = v_24507;
    goto v_24466;
v_24468:
v_24466:
    goto v_24389;
v_24423:
v_24389:
    v_24507 = stack[-3];
    v_24507 = qcdr(v_24507);
    stack[-3] = v_24507;
    v_24507 = stack[-2];
    v_24507 = qcdr(v_24507);
    stack[-2] = v_24507;
    goto v_24370;
v_24369:
    return onevalue(v_24507);
}



// Code for extadd

static LispObject CC_extadd(LispObject env,
                         LispObject v_24359, LispObject v_24360)
{
    env = qenv(env);
    LispObject v_24510, v_24511;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24360,v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24359,v_24360);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_24360;
    stack[-3] = v_24359;
// end of prologue
    v_24510 = stack[-3];
    if (v_24510 == nil) goto v_24364;
    else goto v_24365;
v_24364:
    v_24510 = stack[-2];
    goto v_24363;
v_24365:
    v_24510 = stack[-2];
    if (v_24510 == nil) goto v_24368;
    else goto v_24369;
v_24368:
    v_24510 = stack[-3];
    goto v_24363;
v_24369:
    v_24510 = nil;
    v_24510 = ncons(v_24510);
    env = stack[-5];
    stack[-1] = v_24510;
    stack[-4] = v_24510;
v_24383:
    v_24510 = stack[-3];
    if (v_24510 == nil) goto v_24386;
    v_24510 = stack[-2];
    if (v_24510 == nil) goto v_24386;
    goto v_24387;
v_24386:
    goto v_24382;
v_24387:
    goto v_24401;
v_24397:
    v_24510 = stack[-2];
    v_24510 = qcar(v_24510);
    v_24511 = qcar(v_24510);
    goto v_24398;
v_24399:
    v_24510 = stack[-3];
    v_24510 = qcar(v_24510);
    v_24510 = qcar(v_24510);
    goto v_24400;
v_24401:
    goto v_24397;
v_24398:
    goto v_24399;
v_24400:
    if (equal(v_24511, v_24510)) goto v_24395;
    else goto v_24396;
v_24395:
    goto v_24417;
v_24413:
    v_24510 = stack[-3];
    v_24510 = qcar(v_24510);
    v_24511 = qcdr(v_24510);
    goto v_24414;
v_24415:
    v_24510 = stack[-2];
    v_24510 = qcar(v_24510);
    v_24510 = qcdr(v_24510);
    goto v_24416;
v_24417:
    goto v_24413;
v_24414:
    goto v_24415;
v_24416:
    fn = elt(env, 1); // addf
    v_24511 = (*qfn2(fn))(fn, v_24511, v_24510);
    env = stack[-5];
    v_24510 = v_24511;
    if (v_24511 == nil) goto v_24411;
    goto v_24429;
v_24425:
    stack[0] = stack[-1];
    goto v_24426;
v_24427:
    goto v_24437;
v_24433:
    v_24511 = stack[-3];
    v_24511 = qcar(v_24511);
    v_24511 = qcar(v_24511);
    goto v_24434;
v_24435:
    goto v_24436;
v_24437:
    goto v_24433;
v_24434:
    goto v_24435;
v_24436:
    v_24510 = cons(v_24511, v_24510);
    env = stack[-5];
    v_24510 = ncons(v_24510);
    env = stack[-5];
    goto v_24428;
v_24429:
    goto v_24425;
v_24426:
    goto v_24427;
v_24428:
    fn = elt(env, 2); // setcdr
    v_24510 = (*qfn2(fn))(fn, stack[0], v_24510);
    env = stack[-5];
    v_24510 = stack[-1];
    v_24510 = qcdr(v_24510);
    stack[-1] = v_24510;
    goto v_24409;
v_24411:
v_24409:
    v_24510 = stack[-3];
    v_24510 = qcdr(v_24510);
    stack[-3] = v_24510;
    v_24510 = stack[-2];
    v_24510 = qcdr(v_24510);
    stack[-2] = v_24510;
    goto v_24394;
v_24396:
    goto v_24455;
v_24451:
    v_24510 = stack[-2];
    v_24510 = qcar(v_24510);
    v_24511 = qcar(v_24510);
    goto v_24452;
v_24453:
    v_24510 = stack[-3];
    v_24510 = qcar(v_24510);
    v_24510 = qcar(v_24510);
    goto v_24454;
v_24455:
    goto v_24451;
v_24452:
    goto v_24453;
v_24454:
    fn = elt(env, 3); // ordexp
    v_24510 = (*qfn2(fn))(fn, v_24511, v_24510);
    env = stack[-5];
    if (v_24510 == nil) goto v_24449;
    goto v_24467;
v_24463:
    stack[0] = stack[-1];
    goto v_24464;
v_24465:
    v_24510 = stack[-2];
    v_24510 = qcar(v_24510);
    v_24510 = ncons(v_24510);
    env = stack[-5];
    goto v_24466;
v_24467:
    goto v_24463;
v_24464:
    goto v_24465;
v_24466:
    fn = elt(env, 2); // setcdr
    v_24510 = (*qfn2(fn))(fn, stack[0], v_24510);
    env = stack[-5];
    v_24510 = stack[-2];
    v_24510 = qcdr(v_24510);
    stack[-2] = v_24510;
    v_24510 = stack[-1];
    v_24510 = qcdr(v_24510);
    stack[-1] = v_24510;
    goto v_24394;
v_24449:
    goto v_24483;
v_24479:
    stack[0] = stack[-1];
    goto v_24480;
v_24481:
    v_24510 = stack[-3];
    v_24510 = qcar(v_24510);
    v_24510 = ncons(v_24510);
    env = stack[-5];
    goto v_24482;
v_24483:
    goto v_24479;
v_24480:
    goto v_24481;
v_24482:
    fn = elt(env, 2); // setcdr
    v_24510 = (*qfn2(fn))(fn, stack[0], v_24510);
    env = stack[-5];
    v_24510 = stack[-3];
    v_24510 = qcdr(v_24510);
    stack[-3] = v_24510;
    v_24510 = stack[-1];
    v_24510 = qcdr(v_24510);
    stack[-1] = v_24510;
    goto v_24394;
v_24394:
    goto v_24383;
v_24382:
    goto v_24497;
v_24493:
    v_24511 = stack[-1];
    goto v_24494;
v_24495:
    v_24510 = stack[-3];
    if (v_24510 == nil) goto v_24502;
    v_24510 = stack[-3];
    goto v_24500;
v_24502:
    v_24510 = stack[-2];
    goto v_24500;
    v_24510 = nil;
v_24500:
    goto v_24496;
v_24497:
    goto v_24493;
v_24494:
    goto v_24495;
v_24496:
    fn = elt(env, 2); // setcdr
    v_24510 = (*qfn2(fn))(fn, v_24511, v_24510);
    v_24510 = stack[-4];
    v_24510 = qcdr(v_24510);
    goto v_24363;
    v_24510 = nil;
v_24363:
    return onevalue(v_24510);
}



// Code for co_hfn

static LispObject CC_co_hfn(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24373;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24359;
// end of prologue
    goto v_24366;
v_24362:
    v_24373 = stack[0];
    v_24373 = qcdr(v_24373);
    fn = elt(env, 1); // cl_fvarl1
    stack[-1] = (*qfn1(fn))(fn, v_24373);
    env = stack[-2];
    goto v_24363;
v_24364:
    v_24373 = stack[0];
    v_24373 = qcdr(v_24373);
    fn = elt(env, 2); // rl_atnum
    v_24373 = (*qfn1(fn))(fn, v_24373);
    goto v_24365;
v_24366:
    goto v_24362;
v_24363:
    goto v_24364;
v_24365:
    {
        LispObject v_24376 = stack[-1];
        return list2(v_24376, v_24373);
    }
}



// Code for rtypepart

static LispObject CC_rtypepart(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24371;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_24371 = v_24359;
// end of prologue
    fn = elt(env, 2); // getrtypecar
    v_24371 = (*qfn1(fn))(fn, v_24371);
    env = stack[0];
    if (v_24371 == nil) goto v_24364;
    v_24371 = elt(env, 1); // yetunknowntype
    goto v_24362;
v_24364:
    v_24371 = nil;
    goto v_24362;
    v_24371 = nil;
v_24362:
    return onevalue(v_24371);
}



// Code for mk!+equation

static LispObject CC_mkLequation(LispObject env,
                         LispObject v_24359, LispObject v_24360)
{
    env = qenv(env);
    LispObject v_24375, v_24376, v_24377;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24375 = v_24360;
    v_24376 = v_24359;
// end of prologue
    goto v_24371;
v_24365:
    v_24377 = elt(env, 1); // equal
    goto v_24366;
v_24367:
    goto v_24368;
v_24369:
    goto v_24370;
v_24371:
    goto v_24365;
v_24366:
    goto v_24367;
v_24368:
    goto v_24369;
v_24370:
    return list3(v_24377, v_24376, v_24375);
    return onevalue(v_24375);
}



// Code for freeof!-dfl

static LispObject CC_freeofKdfl(LispObject env,
                         LispObject v_24359, LispObject v_24360)
{
    env = qenv(env);
    LispObject v_24395, v_24396;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24360,v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24359,v_24360);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24360;
    stack[-1] = v_24359;
// end of prologue
v_24358:
    v_24395 = stack[-1];
    if (!consp(v_24395)) goto v_24364;
    else goto v_24365;
v_24364:
    v_24395 = lisp_true;
    goto v_24363;
v_24365:
    goto v_24379;
v_24375:
    v_24395 = stack[-1];
    v_24396 = qcar(v_24395);
    goto v_24376;
v_24377:
    v_24395 = stack[0];
    goto v_24378;
v_24379:
    goto v_24375;
v_24376:
    goto v_24377;
v_24378:
    fn = elt(env, 1); // freeof!-df
    v_24395 = (*qfn2(fn))(fn, v_24396, v_24395);
    env = stack[-2];
    if (v_24395 == nil) goto v_24372;
    else goto v_24373;
v_24372:
    v_24395 = nil;
    goto v_24371;
v_24373:
    goto v_24391;
v_24387:
    v_24395 = stack[-1];
    v_24396 = qcdr(v_24395);
    goto v_24388;
v_24389:
    v_24395 = stack[0];
    goto v_24390;
v_24391:
    goto v_24387;
v_24388:
    goto v_24389;
v_24390:
    stack[-1] = v_24396;
    stack[0] = v_24395;
    goto v_24358;
    v_24395 = nil;
v_24371:
    goto v_24363;
    v_24395 = nil;
v_24363:
    return onevalue(v_24395);
}



// Code for talp_invtscc

static LispObject CC_talp_invtscc(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24466, v_24467;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_24359;
// end of prologue
    v_24466 = stack[0];
    fn = elt(env, 1); // talp_arg2l
    v_24466 = (*qfn1(fn))(fn, v_24466);
    env = stack[-4];
    if (!consp(v_24466)) goto v_24369;
    else goto v_24370;
v_24369:
    v_24466 = stack[0];
    fn = elt(env, 1); // talp_arg2l
    v_24466 = (*qfn1(fn))(fn, v_24466);
    env = stack[-4];
    stack[-3] = v_24466;
    goto v_24368;
v_24370:
    v_24466 = stack[0];
    fn = elt(env, 2); // talp_arg2r
    v_24466 = (*qfn1(fn))(fn, v_24466);
    env = stack[-4];
    if (!consp(v_24466)) goto v_24375;
    else goto v_24376;
v_24375:
    v_24466 = stack[0];
    fn = elt(env, 2); // talp_arg2r
    v_24466 = (*qfn1(fn))(fn, v_24466);
    env = stack[-4];
    stack[-3] = v_24466;
    goto v_24368;
v_24376:
    v_24466 = nil;
    goto v_24366;
v_24368:
    v_24466 = stack[0];
    fn = elt(env, 1); // talp_arg2l
    v_24466 = (*qfn1(fn))(fn, v_24466);
    env = stack[-4];
    if (!consp(v_24466)) goto v_24386;
    else goto v_24387;
v_24386:
    v_24466 = stack[0];
    fn = elt(env, 2); // talp_arg2r
    v_24466 = (*qfn1(fn))(fn, v_24466);
    env = stack[-4];
    goto v_24385;
v_24387:
    v_24466 = stack[0];
    fn = elt(env, 1); // talp_arg2l
    v_24466 = (*qfn1(fn))(fn, v_24466);
    env = stack[-4];
    goto v_24385;
    v_24466 = nil;
v_24385:
    stack[-2] = v_24466;
    fn = elt(env, 3); // talp_noffcts
    v_24466 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[0] = v_24466;
    v_24466 = stack[-2];
    fn = elt(env, 4); // talp_invp
    v_24466 = (*qfn1(fn))(fn, v_24466);
    env = stack[-4];
    if (v_24466 == nil) goto v_24403;
    else goto v_24404;
v_24403:
    v_24466 = lisp_true;
    goto v_24402;
v_24404:
    goto v_24418;
v_24414:
    v_24466 = stack[-2];
    fn = elt(env, 5); // talp_td
    v_24467 = (*qfn1(fn))(fn, v_24466);
    env = stack[-4];
    goto v_24415;
v_24416:
    v_24466 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24417;
v_24418:
    goto v_24414;
v_24415:
    goto v_24416;
v_24417:
    v_24466 = (LispObject)greaterp2(v_24467, v_24466);
    v_24466 = v_24466 ? lisp_true : nil;
    env = stack[-4];
    if (v_24466 == nil) goto v_24412;
    else goto v_24411;
v_24412:
    goto v_24426;
v_24422:
    v_24467 = stack[0];
    goto v_24423;
v_24424:
    v_24466 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24425;
v_24426:
    goto v_24422;
v_24423:
    goto v_24424;
v_24425:
    v_24466 = (v_24467 == v_24466 ? lisp_true : nil);
v_24411:
    v_24466 = (v_24466 == nil ? lisp_true : nil);
    goto v_24402;
    v_24466 = nil;
v_24402:
    if (v_24466 == nil) goto v_24400;
    v_24466 = nil;
    goto v_24366;
v_24400:
    v_24466 = stack[-2];
    stack[-1] = v_24466;
v_24435:
    v_24466 = stack[-1];
    fn = elt(env, 6); // talp_invarg
    v_24466 = (*qfn1(fn))(fn, v_24466);
    env = stack[-4];
    if (!consp(v_24466)) goto v_24438;
    else goto v_24439;
v_24438:
    goto v_24434;
v_24439:
    v_24466 = stack[-1];
    fn = elt(env, 6); // talp_invarg
    v_24466 = (*qfn1(fn))(fn, v_24466);
    env = stack[-4];
    stack[-1] = v_24466;
    goto v_24435;
v_24434:
    goto v_24453;
v_24449:
    stack[0] = stack[-3];
    goto v_24450;
v_24451:
    v_24466 = stack[-1];
    fn = elt(env, 6); // talp_invarg
    v_24466 = (*qfn1(fn))(fn, v_24466);
    goto v_24452;
v_24453:
    goto v_24449;
v_24450:
    goto v_24451;
v_24452:
    if (equal(stack[0], v_24466)) goto v_24448;
    v_24466 = nil;
    goto v_24366;
v_24448:
    goto v_24463;
v_24459:
    v_24467 = stack[-3];
    goto v_24460;
v_24461:
    v_24466 = stack[-2];
    goto v_24462;
v_24463:
    goto v_24459;
v_24460:
    goto v_24461;
v_24462:
    return cons(v_24467, v_24466);
v_24366:
    return onevalue(v_24466);
}



// Code for pasf_or

static LispObject CC_pasf_or(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24800, v_24801;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24359;
// end of prologue
    goto v_24380;
v_24376:
    v_24801 = stack[0];
    goto v_24377;
v_24378:
    v_24800 = elt(env, 1); // true
    goto v_24379;
v_24380:
    goto v_24376;
v_24377:
    goto v_24378;
v_24379:
    if (v_24801 == v_24800) goto v_24374;
    else goto v_24375;
v_24374:
    v_24800 = lisp_true;
    goto v_24373;
v_24375:
    goto v_24390;
v_24386:
    v_24801 = stack[0];
    goto v_24387;
v_24388:
    v_24800 = elt(env, 2); // false
    goto v_24389;
v_24390:
    goto v_24386;
v_24387:
    goto v_24388;
v_24389:
    v_24800 = (v_24801 == v_24800 ? lisp_true : nil);
    goto v_24373;
    v_24800 = nil;
v_24373:
    if (v_24800 == nil) goto v_24371;
    v_24800 = lisp_true;
    goto v_24369;
v_24371:
    goto v_24401;
v_24397:
    goto v_24414;
v_24410:
    v_24801 = stack[0];
    goto v_24411;
v_24412:
    v_24800 = elt(env, 1); // true
    goto v_24413;
v_24414:
    goto v_24410;
v_24411:
    goto v_24412;
v_24413:
    if (v_24801 == v_24800) goto v_24408;
    else goto v_24409;
v_24408:
    v_24800 = lisp_true;
    goto v_24407;
v_24409:
    goto v_24424;
v_24420:
    v_24801 = stack[0];
    goto v_24421;
v_24422:
    v_24800 = elt(env, 2); // false
    goto v_24423;
v_24424:
    goto v_24420;
v_24421:
    goto v_24422;
v_24423:
    v_24800 = (v_24801 == v_24800 ? lisp_true : nil);
    goto v_24407;
    v_24800 = nil;
v_24407:
    if (v_24800 == nil) goto v_24405;
    v_24800 = stack[0];
    v_24801 = v_24800;
    goto v_24403;
v_24405:
    v_24800 = stack[0];
    v_24800 = qcar(v_24800);
    v_24800 = Lconsp(nil, v_24800);
    env = stack[-2];
    if (v_24800 == nil) goto v_24430;
    v_24800 = stack[0];
    v_24800 = qcar(v_24800);
    v_24800 = qcar(v_24800);
    v_24801 = v_24800;
    goto v_24403;
v_24430:
    v_24800 = stack[0];
    v_24800 = qcar(v_24800);
    v_24801 = v_24800;
    goto v_24403;
    v_24801 = nil;
v_24403:
    goto v_24398;
v_24399:
    v_24800 = elt(env, 3); // (lessp greaterp leq geq)
    goto v_24400;
v_24401:
    goto v_24397;
v_24398:
    goto v_24399;
v_24400:
    v_24800 = Lmemq(nil, v_24801, v_24800);
    v_24800 = (v_24800 == nil ? lisp_true : nil);
    goto v_24369;
    v_24800 = nil;
v_24369:
    if (v_24800 == nil) goto v_24367;
    v_24800 = stack[0];
    goto v_24363;
v_24367:
    v_24800 = stack[0];
    v_24800 = qcdr(v_24800);
    v_24800 = qcar(v_24800);
    fn = elt(env, 8); // pasf_deci
    v_24800 = (*qfn1(fn))(fn, v_24800);
    env = stack[-2];
    stack[-1] = v_24800;
    goto v_24461;
v_24457:
    goto v_24474;
v_24470:
    v_24801 = stack[0];
    goto v_24471;
v_24472:
    v_24800 = elt(env, 1); // true
    goto v_24473;
v_24474:
    goto v_24470;
v_24471:
    goto v_24472;
v_24473:
    if (v_24801 == v_24800) goto v_24468;
    else goto v_24469;
v_24468:
    v_24800 = lisp_true;
    goto v_24467;
v_24469:
    goto v_24484;
v_24480:
    v_24801 = stack[0];
    goto v_24481;
v_24482:
    v_24800 = elt(env, 2); // false
    goto v_24483;
v_24484:
    goto v_24480;
v_24481:
    goto v_24482;
v_24483:
    v_24800 = (v_24801 == v_24800 ? lisp_true : nil);
    goto v_24467;
    v_24800 = nil;
v_24467:
    if (v_24800 == nil) goto v_24465;
    v_24800 = stack[0];
    v_24801 = v_24800;
    goto v_24463;
v_24465:
    v_24800 = stack[0];
    v_24800 = qcar(v_24800);
    v_24800 = Lconsp(nil, v_24800);
    env = stack[-2];
    if (v_24800 == nil) goto v_24490;
    v_24800 = stack[0];
    v_24800 = qcar(v_24800);
    v_24800 = qcar(v_24800);
    v_24801 = v_24800;
    goto v_24463;
v_24490:
    v_24800 = stack[0];
    v_24800 = qcar(v_24800);
    v_24801 = v_24800;
    goto v_24463;
    v_24801 = nil;
v_24463:
    goto v_24458;
v_24459:
    v_24800 = elt(env, 4); // lessp
    goto v_24460;
v_24461:
    goto v_24457;
v_24458:
    goto v_24459;
v_24460:
    if (v_24801 == v_24800) goto v_24455;
    else goto v_24456;
v_24455:
    goto v_24507;
v_24503:
    v_24800 = stack[-1];
    v_24801 = qcdr(v_24800);
    goto v_24504;
v_24505:
    v_24800 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24506;
v_24507:
    goto v_24503;
v_24504:
    goto v_24505;
v_24506:
    v_24800 = (LispObject)lessp2(v_24801, v_24800);
    v_24800 = v_24800 ? lisp_true : nil;
    env = stack[-2];
    goto v_24454;
v_24456:
    v_24800 = nil;
    goto v_24454;
    v_24800 = nil;
v_24454:
    if (v_24800 == nil) goto v_24452;
    goto v_24521;
v_24515:
    stack[-1] = elt(env, 5); // leq
    goto v_24516;
v_24517:
    goto v_24528;
v_24524:
    v_24800 = stack[0];
    v_24800 = qcdr(v_24800);
    stack[0] = qcar(v_24800);
    goto v_24525;
v_24526:
    v_24800 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 9); // simp
    v_24800 = (*qfn1(fn))(fn, v_24800);
    env = stack[-2];
    v_24800 = qcar(v_24800);
    goto v_24527;
v_24528:
    goto v_24524;
v_24525:
    goto v_24526;
v_24527:
    fn = elt(env, 10); // addf
    v_24801 = (*qfn2(fn))(fn, stack[0], v_24800);
    goto v_24518;
v_24519:
    v_24800 = nil;
    goto v_24520;
v_24521:
    goto v_24515;
v_24516:
    goto v_24517;
v_24518:
    goto v_24519;
v_24520:
    {
        LispObject v_24804 = stack[-1];
        return list3(v_24804, v_24801, v_24800);
    }
v_24452:
    goto v_24548;
v_24544:
    goto v_24561;
v_24557:
    v_24801 = stack[0];
    goto v_24558;
v_24559:
    v_24800 = elt(env, 1); // true
    goto v_24560;
v_24561:
    goto v_24557;
v_24558:
    goto v_24559;
v_24560:
    if (v_24801 == v_24800) goto v_24555;
    else goto v_24556;
v_24555:
    v_24800 = lisp_true;
    goto v_24554;
v_24556:
    goto v_24571;
v_24567:
    v_24801 = stack[0];
    goto v_24568;
v_24569:
    v_24800 = elt(env, 2); // false
    goto v_24570;
v_24571:
    goto v_24567;
v_24568:
    goto v_24569;
v_24570:
    v_24800 = (v_24801 == v_24800 ? lisp_true : nil);
    goto v_24554;
    v_24800 = nil;
v_24554:
    if (v_24800 == nil) goto v_24552;
    v_24800 = stack[0];
    v_24801 = v_24800;
    goto v_24550;
v_24552:
    v_24800 = stack[0];
    v_24800 = qcar(v_24800);
    v_24800 = Lconsp(nil, v_24800);
    env = stack[-2];
    if (v_24800 == nil) goto v_24577;
    v_24800 = stack[0];
    v_24800 = qcar(v_24800);
    v_24800 = qcar(v_24800);
    v_24801 = v_24800;
    goto v_24550;
v_24577:
    v_24800 = stack[0];
    v_24800 = qcar(v_24800);
    v_24801 = v_24800;
    goto v_24550;
    v_24801 = nil;
v_24550:
    goto v_24545;
v_24546:
    v_24800 = elt(env, 5); // leq
    goto v_24547;
v_24548:
    goto v_24544;
v_24545:
    goto v_24546;
v_24547:
    if (v_24801 == v_24800) goto v_24542;
    else goto v_24543;
v_24542:
    goto v_24594;
v_24590:
    v_24800 = stack[-1];
    v_24801 = qcdr(v_24800);
    goto v_24591;
v_24592:
    v_24800 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24593;
v_24594:
    goto v_24590;
v_24591:
    goto v_24592;
v_24593:
    v_24800 = (LispObject)greaterp2(v_24801, v_24800);
    v_24800 = v_24800 ? lisp_true : nil;
    env = stack[-2];
    goto v_24541;
v_24543:
    v_24800 = nil;
    goto v_24541;
    v_24800 = nil;
v_24541:
    if (v_24800 == nil) goto v_24539;
    goto v_24608;
v_24602:
    stack[-1] = elt(env, 4); // lessp
    goto v_24603;
v_24604:
    goto v_24615;
v_24611:
    v_24800 = stack[0];
    v_24800 = qcdr(v_24800);
    stack[0] = qcar(v_24800);
    goto v_24612;
v_24613:
    v_24800 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 9); // simp
    v_24800 = (*qfn1(fn))(fn, v_24800);
    env = stack[-2];
    v_24800 = qcar(v_24800);
    fn = elt(env, 11); // negf
    v_24800 = (*qfn1(fn))(fn, v_24800);
    env = stack[-2];
    goto v_24614;
v_24615:
    goto v_24611;
v_24612:
    goto v_24613;
v_24614:
    fn = elt(env, 10); // addf
    v_24801 = (*qfn2(fn))(fn, stack[0], v_24800);
    goto v_24605;
v_24606:
    v_24800 = nil;
    goto v_24607;
v_24608:
    goto v_24602;
v_24603:
    goto v_24604;
v_24605:
    goto v_24606;
v_24607:
    {
        LispObject v_24805 = stack[-1];
        return list3(v_24805, v_24801, v_24800);
    }
v_24539:
    goto v_24636;
v_24632:
    goto v_24649;
v_24645:
    v_24801 = stack[0];
    goto v_24646;
v_24647:
    v_24800 = elt(env, 1); // true
    goto v_24648;
v_24649:
    goto v_24645;
v_24646:
    goto v_24647;
v_24648:
    if (v_24801 == v_24800) goto v_24643;
    else goto v_24644;
v_24643:
    v_24800 = lisp_true;
    goto v_24642;
v_24644:
    goto v_24659;
v_24655:
    v_24801 = stack[0];
    goto v_24656;
v_24657:
    v_24800 = elt(env, 2); // false
    goto v_24658;
v_24659:
    goto v_24655;
v_24656:
    goto v_24657;
v_24658:
    v_24800 = (v_24801 == v_24800 ? lisp_true : nil);
    goto v_24642;
    v_24800 = nil;
v_24642:
    if (v_24800 == nil) goto v_24640;
    v_24800 = stack[0];
    v_24801 = v_24800;
    goto v_24638;
v_24640:
    v_24800 = stack[0];
    v_24800 = qcar(v_24800);
    v_24800 = Lconsp(nil, v_24800);
    env = stack[-2];
    if (v_24800 == nil) goto v_24665;
    v_24800 = stack[0];
    v_24800 = qcar(v_24800);
    v_24800 = qcar(v_24800);
    v_24801 = v_24800;
    goto v_24638;
v_24665:
    v_24800 = stack[0];
    v_24800 = qcar(v_24800);
    v_24801 = v_24800;
    goto v_24638;
    v_24801 = nil;
v_24638:
    goto v_24633;
v_24634:
    v_24800 = elt(env, 6); // greaterp
    goto v_24635;
v_24636:
    goto v_24632;
v_24633:
    goto v_24634;
v_24635:
    if (v_24801 == v_24800) goto v_24630;
    else goto v_24631;
v_24630:
    goto v_24682;
v_24678:
    v_24800 = stack[-1];
    v_24801 = qcdr(v_24800);
    goto v_24679;
v_24680:
    v_24800 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24681;
v_24682:
    goto v_24678;
v_24679:
    goto v_24680;
v_24681:
    v_24800 = (LispObject)greaterp2(v_24801, v_24800);
    v_24800 = v_24800 ? lisp_true : nil;
    env = stack[-2];
    goto v_24629;
v_24631:
    v_24800 = nil;
    goto v_24629;
    v_24800 = nil;
v_24629:
    if (v_24800 == nil) goto v_24627;
    goto v_24696;
v_24690:
    stack[-1] = elt(env, 7); // geq
    goto v_24691;
v_24692:
    goto v_24703;
v_24699:
    v_24800 = stack[0];
    v_24800 = qcdr(v_24800);
    stack[0] = qcar(v_24800);
    goto v_24700;
v_24701:
    v_24800 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 9); // simp
    v_24800 = (*qfn1(fn))(fn, v_24800);
    env = stack[-2];
    v_24800 = qcar(v_24800);
    fn = elt(env, 11); // negf
    v_24800 = (*qfn1(fn))(fn, v_24800);
    env = stack[-2];
    goto v_24702;
v_24703:
    goto v_24699;
v_24700:
    goto v_24701;
v_24702:
    fn = elt(env, 10); // addf
    v_24801 = (*qfn2(fn))(fn, stack[0], v_24800);
    goto v_24693;
v_24694:
    v_24800 = nil;
    goto v_24695;
v_24696:
    goto v_24690;
v_24691:
    goto v_24692;
v_24693:
    goto v_24694;
v_24695:
    {
        LispObject v_24806 = stack[-1];
        return list3(v_24806, v_24801, v_24800);
    }
v_24627:
    goto v_24724;
v_24720:
    goto v_24737;
v_24733:
    v_24801 = stack[0];
    goto v_24734;
v_24735:
    v_24800 = elt(env, 1); // true
    goto v_24736;
v_24737:
    goto v_24733;
v_24734:
    goto v_24735;
v_24736:
    if (v_24801 == v_24800) goto v_24731;
    else goto v_24732;
v_24731:
    v_24800 = lisp_true;
    goto v_24730;
v_24732:
    goto v_24747;
v_24743:
    v_24801 = stack[0];
    goto v_24744;
v_24745:
    v_24800 = elt(env, 2); // false
    goto v_24746;
v_24747:
    goto v_24743;
v_24744:
    goto v_24745;
v_24746:
    v_24800 = (v_24801 == v_24800 ? lisp_true : nil);
    goto v_24730;
    v_24800 = nil;
v_24730:
    if (v_24800 == nil) goto v_24728;
    v_24800 = stack[0];
    v_24801 = v_24800;
    goto v_24726;
v_24728:
    v_24800 = stack[0];
    v_24800 = qcar(v_24800);
    v_24800 = Lconsp(nil, v_24800);
    env = stack[-2];
    if (v_24800 == nil) goto v_24753;
    v_24800 = stack[0];
    v_24800 = qcar(v_24800);
    v_24800 = qcar(v_24800);
    v_24801 = v_24800;
    goto v_24726;
v_24753:
    v_24800 = stack[0];
    v_24800 = qcar(v_24800);
    v_24801 = v_24800;
    goto v_24726;
    v_24801 = nil;
v_24726:
    goto v_24721;
v_24722:
    v_24800 = elt(env, 7); // geq
    goto v_24723;
v_24724:
    goto v_24720;
v_24721:
    goto v_24722;
v_24723:
    if (v_24801 == v_24800) goto v_24718;
    else goto v_24719;
v_24718:
    goto v_24770;
v_24766:
    v_24800 = stack[-1];
    v_24801 = qcdr(v_24800);
    goto v_24767;
v_24768:
    v_24800 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24769;
v_24770:
    goto v_24766;
v_24767:
    goto v_24768;
v_24769:
    v_24800 = (LispObject)lessp2(v_24801, v_24800);
    v_24800 = v_24800 ? lisp_true : nil;
    env = stack[-2];
    goto v_24717;
v_24719:
    v_24800 = nil;
    goto v_24717;
    v_24800 = nil;
v_24717:
    if (v_24800 == nil) goto v_24715;
    goto v_24784;
v_24778:
    stack[-1] = elt(env, 6); // greaterp
    goto v_24779;
v_24780:
    goto v_24791;
v_24787:
    v_24800 = stack[0];
    v_24800 = qcdr(v_24800);
    stack[0] = qcar(v_24800);
    goto v_24788;
v_24789:
    v_24800 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 9); // simp
    v_24800 = (*qfn1(fn))(fn, v_24800);
    env = stack[-2];
    v_24800 = qcar(v_24800);
    goto v_24790;
v_24791:
    goto v_24787;
v_24788:
    goto v_24789;
v_24790:
    fn = elt(env, 10); // addf
    v_24801 = (*qfn2(fn))(fn, stack[0], v_24800);
    goto v_24781;
v_24782:
    v_24800 = nil;
    goto v_24783;
v_24784:
    goto v_24778;
v_24779:
    goto v_24780;
v_24781:
    goto v_24782;
v_24783:
    {
        LispObject v_24807 = stack[-1];
        return list3(v_24807, v_24801, v_24800);
    }
v_24715:
    v_24800 = stack[0];
v_24363:
    return onevalue(v_24800);
}



// Code for sfto_dprpartf

static LispObject CC_sfto_dprpartf(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24370;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_24370 = v_24359;
// end of prologue
    goto v_24366;
v_24362:
    stack[0] = v_24370;
    goto v_24363;
v_24364:
    fn = elt(env, 1); // sfto_dcontentf
    v_24370 = (*qfn1(fn))(fn, v_24370);
    env = stack[-1];
    goto v_24365;
v_24366:
    goto v_24362;
v_24363:
    goto v_24364;
v_24365:
    {
        LispObject v_24372 = stack[0];
        fn = elt(env, 2); // sfto_dprpartf1
        return (*qfn2(fn))(fn, v_24372, v_24370);
    }
}



// Code for integralir

static LispObject CC_integralir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24440, v_24441;
    LispObject fn;
    argcheck(nargs, 0, "integralir");
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
    goto v_24372;
v_24368:
    v_24441 = qvalue(elt(env, 1)); // atts
    goto v_24369;
v_24370:
    v_24440 = elt(env, 2); // name
    goto v_24371;
v_24372:
    goto v_24368;
v_24369:
    goto v_24370;
v_24371:
    fn = elt(env, 6); // find
    v_24440 = (*qfn2(fn))(fn, v_24441, v_24440);
    env = stack[-3];
    v_24440 = Lintern(nil, v_24440);
    env = stack[-3];
    stack[-1] = v_24440;
    v_24440 = elt(env, 3); // (bvar x 1)
    v_24440 = ncons(v_24440);
    env = stack[-3];
    stack[0] = v_24440;
    goto v_24386;
v_24382:
    v_24441 = stack[-1];
    goto v_24383;
v_24384:
    v_24440 = elt(env, 4); // defint
    goto v_24385;
v_24386:
    goto v_24382;
v_24383:
    goto v_24384;
v_24385:
    if (v_24441 == v_24440) goto v_24380;
    else goto v_24381;
v_24380:
    fn = elt(env, 7); // lex
    v_24440 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    fn = elt(env, 8); // omobj
    v_24440 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_24379;
v_24381:
v_24379:
    fn = elt(env, 7); // lex
    v_24440 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    fn = elt(env, 8); // omobj
    v_24440 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-2] = v_24440;
    v_24440 = stack[-2];
    v_24440 = Lconsp(nil, v_24440);
    env = stack[-3];
    if (v_24440 == nil) goto v_24397;
    goto v_24408;
v_24404:
    v_24440 = stack[-2];
    v_24441 = qcar(v_24440);
    goto v_24405;
v_24406:
    v_24440 = elt(env, 5); // lambda
    goto v_24407;
v_24408:
    goto v_24404;
v_24405:
    goto v_24406;
v_24407:
    if (v_24441 == v_24440) goto v_24402;
    else goto v_24403;
v_24402:
    v_24440 = stack[-2];
    fn = elt(env, 9); // lambdavar
    v_24440 = (*qfn1(fn))(fn, v_24440);
    env = stack[-3];
    stack[0] = v_24440;
    v_24440 = stack[-2];
    fn = elt(env, 10); // lambdafun
    v_24440 = (*qfn1(fn))(fn, v_24440);
    env = stack[-3];
    stack[-2] = v_24440;
    goto v_24401;
v_24403:
v_24401:
    goto v_24395;
v_24397:
v_24395:
    goto v_24422;
v_24418:
    goto v_24428;
v_24424:
    v_24441 = stack[-1];
    goto v_24425;
v_24426:
    v_24440 = nil;
    goto v_24427;
v_24428:
    goto v_24424;
v_24425:
    goto v_24426;
v_24427:
    stack[-1] = list2(v_24441, v_24440);
    env = stack[-3];
    goto v_24419;
v_24420:
    goto v_24436;
v_24432:
    goto v_24433;
v_24434:
    v_24440 = stack[-2];
    v_24440 = ncons(v_24440);
    env = stack[-3];
    goto v_24435;
v_24436:
    goto v_24432;
v_24433:
    goto v_24434;
v_24435:
    v_24440 = Lappend(nil, stack[0], v_24440);
    goto v_24421;
v_24422:
    goto v_24418;
v_24419:
    goto v_24420;
v_24421:
    {
        LispObject v_24445 = stack[-1];
        return Lappend(nil, v_24445, v_24440);
    }
    return onevalue(v_24440);
}



// Code for plusrd

static LispObject CC_plusrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24381, v_24382;
    LispObject fn;
    argcheck(nargs, 0, "plusrd");
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
    v_24381 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_24382 = v_24381;
    v_24381 = v_24382;
    if (v_24381 == nil) goto v_24367;
    else goto v_24368;
v_24367:
    v_24381 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24366;
v_24368:
    goto v_24378;
v_24374:
    stack[0] = v_24382;
    goto v_24375;
v_24376:
    v_24381 = CC_plusrd(elt(env, 0), 0);
    env = stack[-1];
    goto v_24377;
v_24378:
    goto v_24374;
v_24375:
    goto v_24376;
v_24377:
    {
        LispObject v_24384 = stack[0];
        fn = elt(env, 2); // alg_plus
        return (*qfn2(fn))(fn, v_24384, v_24381);
    }
    v_24381 = nil;
v_24366:
    return onevalue(v_24381);
}



// Code for simpu

static LispObject CC_simpu(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24398, v_24399;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_24399 = v_24359;
// end of prologue
    goto v_24366;
v_24362:
    goto v_24373;
v_24369:
    goto v_24379;
v_24375:
    goto v_24387;
v_24381:
    stack[-1] = elt(env, 1); // u
    goto v_24382;
v_24383:
    v_24398 = v_24399;
    stack[0] = qcar(v_24398);
    goto v_24384;
v_24385:
    v_24398 = v_24399;
    v_24398 = qcdr(v_24398);
    fn = elt(env, 2); // ordn
    v_24398 = (*qfn1(fn))(fn, v_24398);
    env = stack[-2];
    v_24398 = Lreverse(nil, v_24398);
    env = stack[-2];
    goto v_24386;
v_24387:
    goto v_24381;
v_24382:
    goto v_24383;
v_24384:
    goto v_24385;
v_24386:
    v_24399 = list2star(stack[-1], stack[0], v_24398);
    env = stack[-2];
    goto v_24376;
v_24377:
    v_24398 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24378;
v_24379:
    goto v_24375;
v_24376:
    goto v_24377;
v_24378:
    fn = elt(env, 3); // mksp
    v_24399 = (*qfn2(fn))(fn, v_24399, v_24398);
    env = stack[-2];
    goto v_24370;
v_24371:
    v_24398 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24372;
v_24373:
    goto v_24369;
v_24370:
    goto v_24371;
v_24372:
    v_24398 = cons(v_24399, v_24398);
    env = stack[-2];
    v_24399 = ncons(v_24398);
    goto v_24363;
v_24364:
    v_24398 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24365;
v_24366:
    goto v_24362;
v_24363:
    goto v_24364;
v_24365:
    return cons(v_24399, v_24398);
}



// Code for o!-nextarg

static LispObject CC_oKnextarg(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24522, v_24523;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_24359;
// end of prologue
    v_24522 = qvalue(elt(env, 1)); // !*udebug
    if (v_24522 == nil) goto v_24367;
    v_24522 = nil;
    fn = elt(env, 11); // uprint
    v_24522 = (*qfn1(fn))(fn, v_24522);
    env = stack[-3];
    goto v_24365;
v_24367:
v_24365:
    goto v_24383;
v_24379:
    v_24523 = qvalue(elt(env, 2)); // i
    goto v_24380;
v_24381:
    v_24522 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24382;
v_24383:
    goto v_24379;
v_24380:
    goto v_24381;
v_24382:
    if (v_24523 == v_24522) goto v_24377;
    else goto v_24378;
v_24377:
    goto v_24391;
v_24387:
    v_24523 = qvalue(elt(env, 2)); // i
    goto v_24388;
v_24389:
    v_24522 = qvalue(elt(env, 3)); // upb
    goto v_24390;
v_24391:
    goto v_24387;
v_24388:
    goto v_24389;
v_24390:
    v_24522 = (LispObject)lesseq2(v_24523, v_24522);
    v_24522 = v_24522 ? lisp_true : nil;
    env = stack[-3];
    goto v_24376;
v_24378:
    v_24522 = nil;
    goto v_24376;
    v_24522 = nil;
v_24376:
    if (v_24522 == nil) goto v_24374;
    v_24522 = stack[-1];
    goto v_24372;
v_24374:
    goto v_24408;
v_24404:
    v_24523 = qvalue(elt(env, 2)); // i
    goto v_24405;
v_24406:
    v_24522 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24407;
v_24408:
    goto v_24404;
v_24405:
    goto v_24406;
v_24407:
    if (v_24523 == v_24522) goto v_24402;
    else goto v_24403;
v_24402:
    goto v_24416;
v_24412:
    v_24523 = qvalue(elt(env, 2)); // i
    goto v_24413;
v_24414:
    v_24522 = qvalue(elt(env, 3)); // upb
    goto v_24415;
v_24416:
    goto v_24412;
v_24413:
    goto v_24414;
v_24415:
    v_24522 = (LispObject)lesseq2(v_24523, v_24522);
    v_24522 = v_24522 ? lisp_true : nil;
    env = stack[-3];
    goto v_24401;
v_24403:
    v_24522 = nil;
    goto v_24401;
    v_24522 = nil;
v_24401:
    if (v_24522 == nil) goto v_24399;
    goto v_24427;
v_24423:
    v_24523 = elt(env, 4); // (null!-fn)
    goto v_24424;
v_24425:
    v_24522 = stack[-1];
    goto v_24426;
v_24427:
    goto v_24423;
v_24424:
    goto v_24425;
v_24426:
    v_24522 = cons(v_24523, v_24522);
    env = stack[-3];
    goto v_24372;
v_24399:
    v_24522 = qvalue(elt(env, 5)); // acontract
    if (v_24522 == nil) goto v_24431;
    goto v_24440;
v_24436:
    v_24523 = qvalue(elt(env, 2)); // i
    goto v_24437;
v_24438:
    v_24522 = qvalue(elt(env, 3)); // upb
    goto v_24439;
v_24440:
    goto v_24436;
v_24437:
    goto v_24438;
v_24439:
    v_24522 = (LispObject)lesseq2(v_24523, v_24522);
    v_24522 = v_24522 ? lisp_true : nil;
    env = stack[-3];
    if (v_24522 == nil) goto v_24431;
    goto v_24451;
v_24445:
    stack[-2] = qvalue(elt(env, 6)); // op
    goto v_24446;
v_24447:
    goto v_24458;
v_24454:
    v_24523 = stack[-1];
    goto v_24455;
v_24456:
    v_24522 = qvalue(elt(env, 2)); // i
    goto v_24457;
v_24458:
    goto v_24454;
v_24455:
    goto v_24456;
v_24457:
    fn = elt(env, 12); // first0
    stack[0] = (*qfn2(fn))(fn, v_24523, v_24522);
    env = stack[-3];
    goto v_24448;
v_24449:
    goto v_24466;
v_24462:
    v_24523 = stack[-1];
    goto v_24463;
v_24464:
    v_24522 = qvalue(elt(env, 2)); // i
    goto v_24465;
v_24466:
    goto v_24462;
v_24463:
    goto v_24464;
v_24465:
    fn = elt(env, 13); // last0
    v_24522 = (*qfn2(fn))(fn, v_24523, v_24522);
    env = stack[-3];
    goto v_24450;
v_24451:
    goto v_24445;
v_24446:
    goto v_24447;
v_24448:
    goto v_24449;
v_24450:
    v_24522 = acons(stack[-2], stack[0], v_24522);
    env = stack[-3];
    fn = elt(env, 14); // mval
    v_24522 = (*qfn1(fn))(fn, v_24522);
    env = stack[-3];
    goto v_24372;
v_24431:
    v_24522 = qvalue(elt(env, 7)); // mcontract
    if (v_24522 == nil) goto v_24470;
    goto v_24479;
v_24475:
    v_24523 = qvalue(elt(env, 2)); // i
    goto v_24476;
v_24477:
    v_24522 = qvalue(elt(env, 3)); // upb
    goto v_24478;
v_24479:
    goto v_24475;
v_24476:
    goto v_24477;
v_24478:
    v_24522 = (LispObject)lesseq2(v_24523, v_24522);
    v_24522 = v_24522 ? lisp_true : nil;
    env = stack[-3];
    if (v_24522 == nil) goto v_24470;
    goto v_24489;
v_24483:
    stack[-2] = elt(env, 8); // null!-fn
    goto v_24484;
v_24485:
    goto v_24496;
v_24492:
    v_24523 = stack[-1];
    goto v_24493;
v_24494:
    v_24522 = qvalue(elt(env, 2)); // i
    goto v_24495;
v_24496:
    goto v_24492;
v_24493:
    goto v_24494;
v_24495:
    fn = elt(env, 12); // first0
    stack[0] = (*qfn2(fn))(fn, v_24523, v_24522);
    env = stack[-3];
    goto v_24486;
v_24487:
    goto v_24504;
v_24500:
    v_24523 = stack[-1];
    goto v_24501;
v_24502:
    v_24522 = qvalue(elt(env, 2)); // i
    goto v_24503;
v_24504:
    goto v_24500;
v_24501:
    goto v_24502;
v_24503:
    fn = elt(env, 13); // last0
    v_24522 = (*qfn2(fn))(fn, v_24523, v_24522);
    env = stack[-3];
    goto v_24488;
v_24489:
    goto v_24483;
v_24484:
    goto v_24485;
v_24486:
    goto v_24487;
v_24488:
    v_24522 = acons(stack[-2], stack[0], v_24522);
    env = stack[-3];
    goto v_24372;
v_24470:
    v_24522 = qvalue(elt(env, 9)); // expand
    if (v_24522 == nil) goto v_24508;
    v_24522 = nil;
    qvalue(elt(env, 9)) = v_24522; // expand
    goto v_24516;
v_24512:
    v_24523 = qvalue(elt(env, 10)); // identity
    goto v_24513;
v_24514:
    v_24522 = stack[-1];
    goto v_24515;
v_24516:
    goto v_24512;
v_24513:
    goto v_24514;
v_24515:
    v_24522 = cons(v_24523, v_24522);
    env = stack[-3];
    goto v_24372;
v_24508:
    v_24522 = nil;
v_24372:
    stack[0] = v_24522;
    v_24522 = qvalue(elt(env, 2)); // i
    v_24522 = add1(v_24522);
    env = stack[-3];
    qvalue(elt(env, 2)) = v_24522; // i
    v_24522 = stack[0];
    return onevalue(v_24522);
}



// Code for incident1

static LispObject CC_incident1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24479, v_24480, v_24481, v_24482, v_24483;
    LispObject v_24361, v_24360, v_24359;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "incident1");
    va_start(aa, nargs);
    v_24359 = va_arg(aa, LispObject);
    v_24360 = va_arg(aa, LispObject);
    v_24361 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24361,v_24360,v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24359,v_24360,v_24361);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_24481 = v_24361;
    v_24482 = v_24360;
    v_24483 = v_24359;
// end of prologue
    goto v_24371;
v_24367:
    v_24480 = v_24483;
    goto v_24368;
v_24369:
    v_24479 = v_24482;
    v_24479 = qcar(v_24479);
    v_24479 = qcar(v_24479);
    goto v_24370;
v_24371:
    goto v_24367;
v_24368:
    goto v_24369;
v_24370:
    if (v_24480 == v_24479) goto v_24365;
    else goto v_24366;
v_24365:
    goto v_24383;
v_24377:
    v_24479 = v_24482;
    v_24479 = qcdr(v_24479);
    v_24479 = qcar(v_24479);
    stack[-1] = qcar(v_24479);
    goto v_24378;
v_24379:
    stack[0] = v_24481;
    goto v_24380;
v_24381:
    goto v_24395;
v_24391:
    v_24479 = v_24482;
    v_24479 = qcdr(v_24479);
    v_24479 = qcdr(v_24479);
    v_24479 = qcar(v_24479);
    v_24479 = qcar(v_24479);
    goto v_24392;
v_24393:
    v_24480 = v_24481;
    goto v_24394;
v_24395:
    goto v_24391;
v_24392:
    goto v_24393;
v_24394:
    v_24479 = cons(v_24479, v_24480);
    env = stack[-2];
    v_24479 = ncons(v_24479);
    goto v_24382;
v_24383:
    goto v_24377;
v_24378:
    goto v_24379;
v_24380:
    goto v_24381;
v_24382:
    {
        LispObject v_24486 = stack[-1];
        LispObject v_24487 = stack[0];
        return acons(v_24486, v_24487, v_24479);
    }
v_24366:
    goto v_24408;
v_24404:
    v_24480 = v_24483;
    goto v_24405;
v_24406:
    v_24479 = v_24482;
    v_24479 = qcdr(v_24479);
    v_24479 = qcar(v_24479);
    v_24479 = qcar(v_24479);
    goto v_24407;
v_24408:
    goto v_24404;
v_24405:
    goto v_24406;
v_24407:
    if (v_24480 == v_24479) goto v_24402;
    else goto v_24403;
v_24402:
    goto v_24421;
v_24415:
    v_24479 = v_24482;
    v_24479 = qcdr(v_24479);
    v_24479 = qcdr(v_24479);
    v_24479 = qcar(v_24479);
    stack[-1] = qcar(v_24479);
    goto v_24416;
v_24417:
    stack[0] = v_24481;
    goto v_24418;
v_24419:
    goto v_24434;
v_24430:
    v_24479 = v_24482;
    v_24479 = qcar(v_24479);
    v_24479 = qcar(v_24479);
    goto v_24431;
v_24432:
    v_24480 = v_24481;
    goto v_24433;
v_24434:
    goto v_24430;
v_24431:
    goto v_24432;
v_24433:
    v_24479 = cons(v_24479, v_24480);
    env = stack[-2];
    v_24479 = ncons(v_24479);
    goto v_24420;
v_24421:
    goto v_24415;
v_24416:
    goto v_24417;
v_24418:
    goto v_24419;
v_24420:
    {
        LispObject v_24488 = stack[-1];
        LispObject v_24489 = stack[0];
        return acons(v_24488, v_24489, v_24479);
    }
v_24403:
    goto v_24445;
v_24441:
    v_24480 = v_24483;
    goto v_24442;
v_24443:
    v_24479 = v_24482;
    v_24479 = qcdr(v_24479);
    v_24479 = qcdr(v_24479);
    v_24479 = qcar(v_24479);
    v_24479 = qcar(v_24479);
    goto v_24444;
v_24445:
    goto v_24441;
v_24442:
    goto v_24443;
v_24444:
    if (v_24480 == v_24479) goto v_24439;
    else goto v_24440;
v_24439:
    goto v_24459;
v_24453:
    v_24479 = v_24482;
    v_24479 = qcar(v_24479);
    stack[-1] = qcar(v_24479);
    goto v_24454;
v_24455:
    stack[0] = v_24481;
    goto v_24456;
v_24457:
    goto v_24470;
v_24466:
    v_24479 = v_24482;
    v_24479 = qcdr(v_24479);
    v_24479 = qcar(v_24479);
    v_24479 = qcar(v_24479);
    goto v_24467;
v_24468:
    v_24480 = v_24481;
    goto v_24469;
v_24470:
    goto v_24466;
v_24467:
    goto v_24468;
v_24469:
    v_24479 = cons(v_24479, v_24480);
    env = stack[-2];
    v_24479 = ncons(v_24479);
    goto v_24458;
v_24459:
    goto v_24453;
v_24454:
    goto v_24455;
v_24456:
    goto v_24457;
v_24458:
    {
        LispObject v_24490 = stack[-1];
        LispObject v_24491 = stack[0];
        return acons(v_24490, v_24491, v_24479);
    }
v_24440:
    v_24479 = nil;
    goto v_24364;
    v_24479 = nil;
v_24364:
    return onevalue(v_24479);
}



// Code for evalwhereexp

static LispObject CC_evalwhereexp(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24401, v_24402;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_24402 = v_24359;
// end of prologue
    goto v_24366;
v_24362:
    goto v_24372;
v_24368:
    v_24401 = v_24402;
    v_24401 = qcar(v_24401);
    stack[-2] = qcdr(v_24401);
    goto v_24369;
v_24370:
    goto v_24381;
v_24377:
    stack[-1] = elt(env, 1); // aeval
    goto v_24378;
v_24379:
    goto v_24389;
v_24385:
    stack[0] = elt(env, 1); // aeval
    goto v_24386;
v_24387:
    goto v_24396;
v_24392:
    v_24401 = v_24402;
    v_24402 = qcdr(v_24401);
    goto v_24393;
v_24394:
    v_24401 = elt(env, 2); // where
    goto v_24395;
v_24396:
    goto v_24392;
v_24393:
    goto v_24394;
v_24395:
    fn = elt(env, 3); // carx
    v_24401 = (*qfn2(fn))(fn, v_24402, v_24401);
    env = stack[-3];
    goto v_24388;
v_24389:
    goto v_24385;
v_24386:
    goto v_24387;
v_24388:
    v_24401 = list2(stack[0], v_24401);
    env = stack[-3];
    v_24401 = Lmkquote(nil, v_24401);
    env = stack[-3];
    goto v_24380;
v_24381:
    goto v_24377;
v_24378:
    goto v_24379;
v_24380:
    v_24401 = list2(stack[-1], v_24401);
    env = stack[-3];
    goto v_24371;
v_24372:
    goto v_24368;
v_24369:
    goto v_24370;
v_24371:
    v_24402 = list2(stack[-2], v_24401);
    env = stack[-3];
    goto v_24363;
v_24364:
    v_24401 = nil;
    goto v_24365;
v_24366:
    goto v_24362;
v_24363:
    goto v_24364;
v_24365:
    {
        fn = elt(env, 4); // evalletsub
        return (*qfn2(fn))(fn, v_24402, v_24401);
    }
}



// Code for lieninstruc

static LispObject CC_lieninstruc(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24562, v_24563, v_24564, v_24565;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24359);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_24359;
// end of prologue
    v_24562 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_24562;
v_24366:
    goto v_24380;
v_24374:
    stack[0] = elt(env, 1); // difference
    goto v_24375;
v_24376:
    goto v_24390;
v_24384:
    v_24564 = elt(env, 1); // difference
    goto v_24385;
v_24386:
    v_24563 = stack[-4];
    goto v_24387;
v_24388:
    v_24562 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24389;
v_24390:
    goto v_24384;
v_24385:
    goto v_24386;
v_24387:
    goto v_24388;
v_24389:
    v_24562 = list3(v_24564, v_24563, v_24562);
    env = stack[-6];
    fn = elt(env, 6); // aeval!*
    v_24563 = (*qfn1(fn))(fn, v_24562);
    env = stack[-6];
    goto v_24377;
v_24378:
    v_24562 = stack[-5];
    goto v_24379;
v_24380:
    goto v_24374;
v_24375:
    goto v_24376;
v_24377:
    goto v_24378;
v_24379:
    v_24562 = list3(stack[0], v_24563, v_24562);
    env = stack[-6];
    fn = elt(env, 7); // aminusp!:
    v_24562 = (*qfn1(fn))(fn, v_24562);
    env = stack[-6];
    if (v_24562 == nil) goto v_24371;
    goto v_24365;
v_24371:
    v_24562 = stack[-5];
    v_24562 = add1(v_24562);
    env = stack[-6];
    stack[-3] = v_24562;
v_24399:
    goto v_24414;
v_24408:
    stack[0] = elt(env, 1); // difference
    goto v_24409;
v_24410:
    v_24562 = stack[-4];
    fn = elt(env, 6); // aeval!*
    v_24563 = (*qfn1(fn))(fn, v_24562);
    env = stack[-6];
    goto v_24411;
v_24412:
    v_24562 = stack[-3];
    goto v_24413;
v_24414:
    goto v_24408;
v_24409:
    goto v_24410;
v_24411:
    goto v_24412;
v_24413:
    v_24562 = list3(stack[0], v_24563, v_24562);
    env = stack[-6];
    fn = elt(env, 7); // aminusp!:
    v_24562 = (*qfn1(fn))(fn, v_24562);
    env = stack[-6];
    if (v_24562 == nil) goto v_24405;
    goto v_24398;
v_24405:
    v_24562 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_24562;
v_24423:
    goto v_24437;
v_24431:
    stack[0] = elt(env, 1); // difference
    goto v_24432;
v_24433:
    v_24562 = stack[-4];
    fn = elt(env, 6); // aeval!*
    v_24563 = (*qfn1(fn))(fn, v_24562);
    env = stack[-6];
    goto v_24434;
v_24435:
    v_24562 = stack[-2];
    goto v_24436;
v_24437:
    goto v_24431;
v_24432:
    goto v_24433;
v_24434:
    goto v_24435;
v_24436:
    v_24562 = list3(stack[0], v_24563, v_24562);
    env = stack[-6];
    fn = elt(env, 7); // aminusp!:
    v_24562 = (*qfn1(fn))(fn, v_24562);
    env = stack[-6];
    if (v_24562 == nil) goto v_24428;
    goto v_24422;
v_24428:
    goto v_24448;
v_24444:
    goto v_24458;
v_24450:
    v_24565 = elt(env, 2); // lie_cc
    goto v_24451;
v_24452:
    v_24564 = stack[-5];
    goto v_24453;
v_24454:
    v_24563 = stack[-3];
    goto v_24455;
v_24456:
    v_24562 = stack[-2];
    goto v_24457;
v_24458:
    goto v_24450;
v_24451:
    goto v_24452;
v_24453:
    goto v_24454;
v_24455:
    goto v_24456;
v_24457:
    stack[0] = list4(v_24565, v_24564, v_24563, v_24562);
    env = stack[-6];
    goto v_24445;
v_24446:
    goto v_24473;
v_24465:
    v_24565 = elt(env, 3); // lienstrucin
    goto v_24466;
v_24467:
    v_24564 = stack[-5];
    goto v_24468;
v_24469:
    v_24563 = stack[-3];
    goto v_24470;
v_24471:
    v_24562 = stack[-2];
    goto v_24472;
v_24473:
    goto v_24465;
v_24466:
    goto v_24467;
v_24468:
    goto v_24469;
v_24470:
    goto v_24471;
v_24472:
    v_24562 = list4(v_24565, v_24564, v_24563, v_24562);
    env = stack[-6];
    fn = elt(env, 6); // aeval!*
    v_24562 = (*qfn1(fn))(fn, v_24562);
    env = stack[-6];
    goto v_24447;
v_24448:
    goto v_24444;
v_24445:
    goto v_24446;
v_24447:
    fn = elt(env, 8); // setk
    v_24562 = (*qfn2(fn))(fn, stack[0], v_24562);
    env = stack[-6];
    goto v_24483;
v_24479:
    goto v_24493;
v_24485:
    v_24565 = elt(env, 2); // lie_cc
    goto v_24486;
v_24487:
    v_24564 = stack[-3];
    goto v_24488;
v_24489:
    v_24563 = stack[-5];
    goto v_24490;
v_24491:
    v_24562 = stack[-2];
    goto v_24492;
v_24493:
    goto v_24485;
v_24486:
    goto v_24487;
v_24488:
    goto v_24489;
v_24490:
    goto v_24491;
v_24492:
    stack[-1] = list4(v_24565, v_24564, v_24563, v_24562);
    env = stack[-6];
    goto v_24480;
v_24481:
    goto v_24504;
v_24500:
    stack[0] = elt(env, 4); // minus
    goto v_24501;
v_24502:
    goto v_24515;
v_24507:
    v_24565 = elt(env, 3); // lienstrucin
    goto v_24508;
v_24509:
    v_24564 = stack[-5];
    goto v_24510;
v_24511:
    v_24563 = stack[-3];
    goto v_24512;
v_24513:
    v_24562 = stack[-2];
    goto v_24514;
v_24515:
    goto v_24507;
v_24508:
    goto v_24509;
v_24510:
    goto v_24511;
v_24512:
    goto v_24513;
v_24514:
    v_24562 = list4(v_24565, v_24564, v_24563, v_24562);
    env = stack[-6];
    goto v_24503;
v_24504:
    goto v_24500;
v_24501:
    goto v_24502;
v_24503:
    v_24562 = list2(stack[0], v_24562);
    env = stack[-6];
    fn = elt(env, 6); // aeval!*
    v_24562 = (*qfn1(fn))(fn, v_24562);
    env = stack[-6];
    goto v_24482;
v_24483:
    goto v_24479;
v_24480:
    goto v_24481;
v_24482:
    fn = elt(env, 8); // setk
    v_24562 = (*qfn2(fn))(fn, stack[-1], v_24562);
    env = stack[-6];
    v_24562 = stack[-2];
    goto v_24530;
v_24524:
    v_24564 = elt(env, 5); // plus
    goto v_24525;
v_24526:
    v_24563 = v_24562;
    goto v_24527;
v_24528:
    v_24562 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24529;
v_24530:
    goto v_24524;
v_24525:
    goto v_24526;
v_24527:
    goto v_24528;
v_24529:
    v_24562 = list3(v_24564, v_24563, v_24562);
    env = stack[-6];
    fn = elt(env, 6); // aeval!*
    v_24562 = (*qfn1(fn))(fn, v_24562);
    env = stack[-6];
    stack[-2] = v_24562;
    goto v_24423;
v_24422:
    v_24562 = stack[-3];
    goto v_24544;
v_24538:
    v_24564 = elt(env, 5); // plus
    goto v_24539;
v_24540:
    v_24563 = v_24562;
    goto v_24541;
v_24542:
    v_24562 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24543;
v_24544:
    goto v_24538;
v_24539:
    goto v_24540;
v_24541:
    goto v_24542;
v_24543:
    v_24562 = list3(v_24564, v_24563, v_24562);
    env = stack[-6];
    fn = elt(env, 6); // aeval!*
    v_24562 = (*qfn1(fn))(fn, v_24562);
    env = stack[-6];
    stack[-3] = v_24562;
    goto v_24399;
v_24398:
    v_24562 = stack[-5];
    goto v_24558;
v_24552:
    v_24564 = elt(env, 5); // plus
    goto v_24553;
v_24554:
    v_24563 = v_24562;
    goto v_24555;
v_24556:
    v_24562 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24557;
v_24558:
    goto v_24552;
v_24553:
    goto v_24554;
v_24555:
    goto v_24556;
v_24557:
    v_24562 = list3(v_24564, v_24563, v_24562);
    env = stack[-6];
    fn = elt(env, 6); // aeval!*
    v_24562 = (*qfn1(fn))(fn, v_24562);
    env = stack[-6];
    stack[-5] = v_24562;
    goto v_24366;
v_24365:
    v_24562 = nil;
    return onevalue(v_24562);
}



// Code for balance_mod

static LispObject CC_balance_mod(LispObject env,
                         LispObject v_24359, LispObject v_24360)
{
    env = qenv(env);
    LispObject v_24392, v_24393;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24360,v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24359,v_24360);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24360;
    stack[-1] = v_24359;
// end of prologue
    goto v_24371;
v_24367:
    goto v_24377;
v_24373:
    v_24393 = stack[-1];
    goto v_24374;
v_24375:
    v_24392 = stack[-1];
    goto v_24376;
v_24377:
    goto v_24373;
v_24374:
    goto v_24375;
v_24376:
    v_24393 = plus2(v_24393, v_24392);
    env = stack[-2];
    goto v_24368;
v_24369:
    v_24392 = stack[0];
    goto v_24370;
v_24371:
    goto v_24367;
v_24368:
    goto v_24369;
v_24370:
    v_24392 = (LispObject)greaterp2(v_24393, v_24392);
    v_24392 = v_24392 ? lisp_true : nil;
    if (v_24392 == nil) goto v_24365;
    goto v_24386;
v_24382:
    v_24393 = stack[-1];
    goto v_24383;
v_24384:
    v_24392 = stack[0];
    goto v_24385;
v_24386:
    goto v_24382;
v_24383:
    goto v_24384;
v_24385:
    return difference2(v_24393, v_24392);
v_24365:
    v_24392 = stack[-1];
    goto v_24363;
    v_24392 = nil;
v_24363:
    return onevalue(v_24392);
}



// Code for appr

static LispObject CC_appr(LispObject env,
                         LispObject v_24359, LispObject v_24360)
{
    env = qenv(env);
    LispObject v_24386, v_24387, v_24388;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24360,v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24359,v_24360);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_24386 = v_24360;
    v_24387 = v_24359;
// end of prologue
v_24365:
    v_24388 = v_24387;
    if (v_24388 == nil) goto v_24368;
    else goto v_24369;
v_24368:
    goto v_24364;
v_24369:
    v_24388 = v_24387;
    v_24388 = qcdr(v_24388);
    stack[0] = v_24388;
    goto v_24381;
v_24377:
    v_24387 = qcar(v_24387);
    goto v_24378;
v_24379:
    goto v_24380;
v_24381:
    goto v_24377;
v_24378:
    goto v_24379;
v_24380:
    v_24386 = cons(v_24387, v_24386);
    env = stack[-1];
    v_24387 = stack[0];
    goto v_24365;
    v_24386 = nil;
v_24364:
    return onevalue(v_24386);
}



// Code for super_vectorfield

static LispObject CC_super_vectorfield(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24602, v_24603, v_24604, v_24605, v_24606;
    LispObject fn;
    LispObject v_24361, v_24360, v_24359;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "super_vectorfield");
    va_start(aa, nargs);
    v_24359 = va_arg(aa, LispObject);
    v_24360 = va_arg(aa, LispObject);
    v_24361 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24361,v_24360,v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24359,v_24360,v_24361);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_24361;
    stack[-2] = v_24360;
    stack[-3] = v_24359;
// end of prologue
    v_24602 = stack[-3];
    if (symbolp(v_24602)) goto v_24369;
    goto v_24382;
v_24372:
    v_24606 = elt(env, 1); // "SUPER_VECTORFIELD:"
    goto v_24373;
v_24374:
    v_24605 = stack[-3];
    goto v_24375;
v_24376:
    v_24604 = elt(env, 2); // "is not an identifier"
    goto v_24377;
v_24378:
    v_24603 = nil;
    goto v_24379;
v_24380:
    v_24602 = lisp_true;
    goto v_24381;
v_24382:
    goto v_24372;
v_24373:
    goto v_24374;
v_24375:
    goto v_24376;
v_24377:
    goto v_24378;
v_24379:
    goto v_24380;
v_24381:
    fn = elt(env, 14); // msgpri
    v_24602 = (*qfnn(fn))(fn, 5, v_24606, v_24605, v_24604, v_24603, v_24602);
    env = stack[-5];
    goto v_24367;
v_24369:
v_24367:
    goto v_24395;
v_24389:
    v_24604 = stack[-3];
    goto v_24390;
v_24391:
    v_24603 = elt(env, 3); // simpfn
    goto v_24392;
v_24393:
    v_24602 = elt(env, 4); // super_der_simp
    goto v_24394;
v_24395:
    goto v_24389;
v_24390:
    goto v_24391;
v_24392:
    goto v_24393;
v_24394:
    v_24602 = Lputprop(nil, 3, v_24604, v_24603, v_24602);
    env = stack[-5];
    goto v_24404;
v_24400:
    v_24602 = stack[-3];
    v_24603 = ncons(v_24602);
    env = stack[-5];
    goto v_24401;
v_24402:
    v_24602 = elt(env, 5); // full
    goto v_24403;
v_24404:
    goto v_24400;
v_24401:
    goto v_24402;
v_24403:
    v_24602 = Lflag(nil, v_24603, v_24602);
    env = stack[-5];
    v_24602 = stack[-2];
    if (v_24602 == nil) goto v_24410;
    else goto v_24411;
v_24410:
    v_24602 = stack[-2];
    goto v_24409;
v_24411:
    v_24602 = stack[-2];
    if (!consp(v_24602)) goto v_24414;
    else goto v_24415;
v_24414:
    v_24602 = stack[-2];
    v_24602 = ncons(v_24602);
    env = stack[-5];
    goto v_24409;
v_24415:
    goto v_24425;
v_24421:
    v_24602 = stack[-2];
    v_24603 = qcar(v_24602);
    goto v_24422;
v_24423:
    v_24602 = elt(env, 6); // list
    goto v_24424;
v_24425:
    goto v_24421;
v_24422:
    goto v_24423;
v_24424:
    if (v_24603 == v_24602) goto v_24419;
    else goto v_24420;
v_24419:
    v_24602 = stack[-2];
    v_24602 = qcdr(v_24602);
    goto v_24409;
v_24420:
    v_24602 = stack[-2];
    goto v_24409;
    v_24602 = nil;
v_24409:
    stack[-2] = v_24602;
    v_24602 = stack[0];
    if (v_24602 == nil) goto v_24436;
    else goto v_24437;
v_24436:
    v_24602 = stack[0];
    goto v_24435;
v_24437:
    v_24602 = stack[0];
    if (!consp(v_24602)) goto v_24440;
    else goto v_24441;
v_24440:
    v_24602 = stack[0];
    v_24602 = ncons(v_24602);
    env = stack[-5];
    goto v_24435;
v_24441:
    goto v_24451;
v_24447:
    v_24602 = stack[0];
    v_24603 = qcar(v_24602);
    goto v_24448;
v_24449:
    v_24602 = elt(env, 6); // list
    goto v_24450;
v_24451:
    goto v_24447;
v_24448:
    goto v_24449;
v_24450:
    if (v_24603 == v_24602) goto v_24445;
    else goto v_24446;
v_24445:
    v_24602 = stack[0];
    v_24602 = qcdr(v_24602);
    goto v_24435;
v_24446:
    v_24602 = stack[0];
    goto v_24435;
    v_24602 = nil;
v_24435:
    stack[0] = v_24602;
    v_24602 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_24602;
    v_24602 = stack[0];
    stack[-1] = v_24602;
v_24464:
    v_24602 = stack[-1];
    if (v_24602 == nil) goto v_24468;
    else goto v_24469;
v_24468:
    goto v_24463;
v_24469:
    v_24602 = stack[-1];
    v_24602 = qcar(v_24602);
    stack[0] = v_24602;
    goto v_24487;
v_24483:
    v_24602 = stack[0];
    v_24603 = Llength(nil, v_24602);
    env = stack[-5];
    goto v_24484;
v_24485:
    v_24602 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_24486;
v_24487:
    goto v_24483;
v_24484:
    goto v_24485;
v_24486:
    if (v_24603 == v_24602) goto v_24482;
    v_24602 = lisp_true;
    goto v_24480;
v_24482:
    goto v_24502;
v_24498:
    v_24602 = stack[0];
    v_24603 = qcar(v_24602);
    goto v_24499;
v_24500:
    v_24602 = elt(env, 7); // ext
    goto v_24501;
v_24502:
    goto v_24498;
v_24499:
    goto v_24500;
v_24501:
    if (v_24603 == v_24602) goto v_24497;
    v_24602 = lisp_true;
    goto v_24495;
v_24497:
    v_24602 = stack[0];
    v_24602 = qcdr(v_24602);
    v_24602 = qcar(v_24602);
    v_24602 = integerp(v_24602);
    v_24602 = (v_24602 == nil ? lisp_true : nil);
    goto v_24495;
    v_24602 = nil;
v_24495:
    goto v_24480;
    v_24602 = nil;
v_24480:
    if (v_24602 == nil) goto v_24478;
    goto v_24525;
v_24515:
    v_24606 = elt(env, 1); // "SUPER_VECTORFIELD:"
    goto v_24516;
v_24517:
    v_24605 = stack[0];
    goto v_24518;
v_24519:
    v_24604 = elt(env, 8); // "not a valid odd variable"
    goto v_24520;
v_24521:
    v_24603 = nil;
    goto v_24522;
v_24523:
    v_24602 = lisp_true;
    goto v_24524;
v_24525:
    goto v_24515;
v_24516:
    goto v_24517;
v_24518:
    goto v_24519;
v_24520:
    goto v_24521;
v_24522:
    goto v_24523;
v_24524:
    fn = elt(env, 14); // msgpri
    v_24602 = (*qfnn(fn))(fn, 5, v_24606, v_24605, v_24604, v_24603, v_24602);
    env = stack[-5];
    goto v_24476;
v_24478:
    goto v_24538;
v_24534:
    v_24603 = stack[-4];
    goto v_24535;
v_24536:
    v_24602 = stack[0];
    v_24602 = qcdr(v_24602);
    v_24602 = qcar(v_24602);
    goto v_24537;
v_24538:
    goto v_24534;
v_24535:
    goto v_24536;
v_24537:
    fn = elt(env, 15); // max
    v_24602 = (*qfn2(fn))(fn, v_24603, v_24602);
    env = stack[-5];
    stack[-4] = v_24602;
    goto v_24476;
v_24476:
    v_24602 = stack[-1];
    v_24602 = qcdr(v_24602);
    stack[-1] = v_24602;
    goto v_24464;
v_24463:
    goto v_24552;
v_24546:
    v_24604 = stack[-3];
    goto v_24547;
v_24548:
    v_24603 = elt(env, 9); // variables
    goto v_24549;
v_24550:
    v_24602 = stack[-2];
    goto v_24551;
v_24552:
    goto v_24546;
v_24547:
    goto v_24548;
v_24549:
    goto v_24550;
v_24551:
    v_24602 = Lputprop(nil, 3, v_24604, v_24603, v_24602);
    env = stack[-5];
    goto v_24563;
v_24557:
    stack[-1] = stack[-3];
    goto v_24558;
v_24559:
    stack[0] = elt(env, 10); // even_dimension
    goto v_24560;
v_24561:
    v_24602 = stack[-2];
    v_24602 = Llength(nil, v_24602);
    env = stack[-5];
    goto v_24562;
v_24563:
    goto v_24557;
v_24558:
    goto v_24559;
v_24560:
    goto v_24561;
v_24562:
    v_24602 = Lputprop(nil, 3, stack[-1], stack[0], v_24602);
    env = stack[-5];
    goto v_24575;
v_24569:
    v_24604 = stack[-3];
    goto v_24570;
v_24571:
    v_24603 = elt(env, 11); // odd_dimension
    goto v_24572;
v_24573:
    v_24602 = stack[-4];
    goto v_24574;
v_24575:
    goto v_24569;
v_24570:
    goto v_24571;
v_24572:
    goto v_24573;
v_24574:
    v_24602 = Lputprop(nil, 3, v_24604, v_24603, v_24602);
    env = stack[-5];
    goto v_24586;
v_24580:
    v_24604 = stack[-3];
    goto v_24581;
v_24582:
    v_24603 = elt(env, 12); // setkfn
    goto v_24583;
v_24584:
    v_24602 = elt(env, 13); // setk_super_vectorfield
    goto v_24585;
v_24586:
    goto v_24580;
v_24581:
    goto v_24582;
v_24583:
    goto v_24584;
v_24585:
    v_24602 = Lputprop(nil, 3, v_24604, v_24603, v_24602);
    env = stack[-5];
    goto v_24597;
v_24591:
    stack[0] = elt(env, 6); // list
    goto v_24592;
v_24593:
    v_24602 = stack[-2];
    v_24603 = Llength(nil, v_24602);
    goto v_24594;
v_24595:
    v_24602 = stack[-4];
    goto v_24596;
v_24597:
    goto v_24591;
v_24592:
    goto v_24593;
v_24594:
    goto v_24595;
v_24596:
    {
        LispObject v_24612 = stack[0];
        return list3(v_24612, v_24603, v_24602);
    }
    return onevalue(v_24602);
}



// Code for fctargs

static LispObject CC_fctargs(LispObject env,
                         LispObject v_24359)
{
    env = qenv(env);
    LispObject v_24375, v_24376;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24375 = v_24359;
// end of prologue
    goto v_24369;
v_24365:
    goto v_24366;
v_24367:
    v_24376 = qvalue(elt(env, 1)); // depl!*
    goto v_24368;
v_24369:
    goto v_24365;
v_24366:
    goto v_24367;
v_24368:
    v_24376 = Lassoc(nil, v_24375, v_24376);
    v_24375 = v_24376;
    if (v_24376 == nil) goto v_24364;
    v_24375 = qcdr(v_24375);
    goto v_24362;
v_24364:
    v_24375 = nil;
v_24362:
    return onevalue(v_24375);
}



// Code for expf

static LispObject CC_expf(LispObject env,
                         LispObject v_24359, LispObject v_24360)
{
    env = qenv(env);
    LispObject v_24576, v_24577, v_24578;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24360,v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24359,v_24360);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_24360;
    stack[-1] = v_24359;
// end of prologue
    v_24576 = stack[-1];
    if (v_24576 == nil) goto v_24364;
    else goto v_24365;
v_24364:
    v_24576 = nil;
    goto v_24363;
v_24365:
    goto v_24374;
v_24370:
    v_24577 = stack[-1];
    goto v_24371;
v_24372:
    v_24576 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24373;
v_24374:
    goto v_24370;
v_24371:
    goto v_24372;
v_24373:
    if (v_24577 == v_24576) goto v_24368;
    else goto v_24369;
v_24368:
    v_24576 = stack[-1];
    goto v_24363;
v_24369:
    v_24576 = stack[-1];
    if (!consp(v_24576)) goto v_24378;
    else goto v_24379;
v_24378:
    goto v_24386;
v_24382:
    stack[-2] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24383;
v_24384:
    goto v_24393;
v_24389:
    goto v_24390;
v_24391:
    v_24576 = stack[0];
    v_24576 = negate(v_24576);
    env = stack[-3];
    goto v_24392;
v_24393:
    goto v_24389;
v_24390:
    goto v_24391;
v_24392:
    v_24576 = Lexpt(nil, stack[-1], v_24576);
    env = stack[-3];
    goto v_24385;
v_24386:
    goto v_24382;
v_24383:
    goto v_24384;
v_24385:
    {
        LispObject v_24582 = stack[-2];
        fn = elt(env, 3); // mkrn
        return (*qfn2(fn))(fn, v_24582, v_24576);
    }
v_24379:
    v_24576 = stack[-1];
    if (!consp(v_24576)) goto v_24401;
    else goto v_24402;
v_24401:
    v_24576 = lisp_true;
    goto v_24400;
v_24402:
    v_24576 = stack[-1];
    v_24576 = qcar(v_24576);
    v_24576 = (consp(v_24576) ? nil : lisp_true);
    goto v_24400;
    v_24576 = nil;
v_24400:
    if (v_24576 == nil) goto v_24398;
    goto v_24415;
v_24411:
    v_24577 = stack[-1];
    goto v_24412;
v_24413:
    v_24576 = stack[0];
    goto v_24414;
v_24415:
    goto v_24411;
v_24412:
    goto v_24413;
v_24414:
    {
        fn = elt(env, 4); // !:expt
        return (*qfn2(fn))(fn, v_24577, v_24576);
    }
v_24398:
    v_24576 = stack[-1];
    v_24576 = qcdr(v_24576);
    if (v_24576 == nil) goto v_24419;
    goto v_24427;
v_24423:
    v_24577 = stack[-1];
    goto v_24424;
v_24425:
    v_24576 = stack[0];
    goto v_24426;
v_24427:
    goto v_24423;
v_24424:
    goto v_24425;
v_24426:
    {
        fn = elt(env, 5); // mksp!*
        return (*qfn2(fn))(fn, v_24577, v_24576);
    }
v_24419:
    goto v_24436;
v_24432:
    v_24576 = stack[-1];
    v_24576 = qcar(v_24576);
    v_24576 = qcar(v_24576);
    v_24577 = qcdr(v_24576);
    goto v_24433;
v_24434:
    v_24576 = qvalue(elt(env, 1)); // frlis!*
    goto v_24435;
v_24436:
    goto v_24432;
v_24433:
    goto v_24434;
v_24435:
    v_24576 = Lmemq(nil, v_24577, v_24576);
    if (v_24576 == nil) goto v_24431;
    goto v_24449;
v_24445:
    goto v_24455;
v_24451:
    goto v_24464;
v_24458:
    v_24578 = elt(env, 2); // expt
    goto v_24459;
v_24460:
    v_24576 = stack[-1];
    v_24576 = qcar(v_24576);
    v_24576 = qcar(v_24576);
    v_24577 = qcar(v_24576);
    goto v_24461;
v_24462:
    v_24576 = stack[-1];
    v_24576 = qcar(v_24576);
    v_24576 = qcar(v_24576);
    v_24576 = qcdr(v_24576);
    goto v_24463;
v_24464:
    goto v_24458;
v_24459:
    goto v_24460;
v_24461:
    goto v_24462;
v_24463:
    v_24576 = list3(v_24578, v_24577, v_24576);
    env = stack[-3];
    fn = elt(env, 6); // fkern
    v_24576 = (*qfn1(fn))(fn, v_24576);
    env = stack[-3];
    v_24577 = qcar(v_24576);
    goto v_24452;
v_24453:
    v_24576 = stack[0];
    goto v_24454;
v_24455:
    goto v_24451;
v_24452:
    goto v_24453;
v_24454:
    fn = elt(env, 7); // to
    stack[-2] = (*qfn2(fn))(fn, v_24577, v_24576);
    env = stack[-3];
    goto v_24446;
v_24447:
    goto v_24481;
v_24477:
    v_24576 = stack[-1];
    v_24576 = qcar(v_24576);
    v_24577 = qcdr(v_24576);
    goto v_24478;
v_24479:
    v_24576 = stack[0];
    goto v_24480;
v_24481:
    goto v_24477;
v_24478:
    goto v_24479;
v_24480:
    v_24576 = CC_expf(elt(env, 0), v_24577, v_24576);
    env = stack[-3];
    goto v_24448;
v_24449:
    goto v_24445;
v_24446:
    goto v_24447;
v_24448:
    v_24576 = cons(stack[-2], v_24576);
    return ncons(v_24576);
v_24431:
    goto v_24493;
v_24489:
    v_24576 = stack[-1];
    v_24576 = qcar(v_24576);
    v_24576 = qcar(v_24576);
    v_24577 = qcdr(v_24576);
    goto v_24490;
v_24491:
    v_24576 = stack[0];
    goto v_24492;
v_24493:
    goto v_24489;
v_24490:
    goto v_24491;
v_24492:
    v_24576 = times2(v_24577, v_24576);
    env = stack[-3];
    stack[-2] = v_24576;
    goto v_24510;
v_24506:
    v_24577 = stack[-2];
    goto v_24507;
v_24508:
    v_24576 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24509;
v_24510:
    goto v_24506;
v_24507:
    goto v_24508;
v_24509:
    v_24576 = (LispObject)greaterp2(v_24577, v_24576);
    v_24576 = v_24576 ? lisp_true : nil;
    env = stack[-3];
    if (v_24576 == nil) goto v_24503;
    v_24576 = stack[-1];
    v_24576 = qcar(v_24576);
    v_24576 = qcar(v_24576);
    v_24576 = qcar(v_24576);
    fn = elt(env, 8); // sfp
    v_24576 = (*qfn1(fn))(fn, v_24576);
    env = stack[-3];
    if (v_24576 == nil) goto v_24503;
    goto v_24524;
v_24520:
    goto v_24530;
v_24526:
    v_24576 = stack[-1];
    v_24576 = qcar(v_24576);
    v_24576 = qcar(v_24576);
    v_24577 = qcar(v_24576);
    goto v_24527;
v_24528:
    v_24576 = stack[-2];
    goto v_24529;
v_24530:
    goto v_24526;
v_24527:
    goto v_24528;
v_24529:
    fn = elt(env, 9); // exptf
    stack[-2] = (*qfn2(fn))(fn, v_24577, v_24576);
    env = stack[-3];
    goto v_24521;
v_24522:
    goto v_24541;
v_24537:
    v_24576 = stack[-1];
    v_24576 = qcar(v_24576);
    v_24577 = qcdr(v_24576);
    goto v_24538;
v_24539:
    v_24576 = stack[0];
    goto v_24540;
v_24541:
    goto v_24537;
v_24538:
    goto v_24539;
v_24540:
    v_24576 = CC_expf(elt(env, 0), v_24577, v_24576);
    env = stack[-3];
    goto v_24523;
v_24524:
    goto v_24520;
v_24521:
    goto v_24522;
v_24523:
    {
        LispObject v_24583 = stack[-2];
        fn = elt(env, 10); // multf
        return (*qfn2(fn))(fn, v_24583, v_24576);
    }
v_24503:
    goto v_24554;
v_24550:
    goto v_24560;
v_24556:
    v_24576 = stack[-1];
    v_24576 = qcar(v_24576);
    v_24576 = qcar(v_24576);
    v_24577 = qcar(v_24576);
    goto v_24557;
v_24558:
    v_24576 = stack[-2];
    goto v_24559;
v_24560:
    goto v_24556;
v_24557:
    goto v_24558;
v_24559:
    fn = elt(env, 7); // to
    stack[-2] = (*qfn2(fn))(fn, v_24577, v_24576);
    env = stack[-3];
    goto v_24551;
v_24552:
    goto v_24571;
v_24567:
    v_24576 = stack[-1];
    v_24576 = qcar(v_24576);
    v_24577 = qcdr(v_24576);
    goto v_24568;
v_24569:
    v_24576 = stack[0];
    goto v_24570;
v_24571:
    goto v_24567;
v_24568:
    goto v_24569;
v_24570:
    v_24576 = CC_expf(elt(env, 0), v_24577, v_24576);
    env = stack[-3];
    goto v_24553;
v_24554:
    goto v_24550;
v_24551:
    goto v_24552;
v_24553:
    v_24576 = cons(stack[-2], v_24576);
    return ncons(v_24576);
    v_24576 = nil;
    goto v_24363;
    v_24576 = nil;
v_24363:
    return onevalue(v_24576);
}



// Code for pasf_premf

static LispObject CC_pasf_premf(LispObject env,
                         LispObject v_24359, LispObject v_24360)
{
    env = qenv(env);
    LispObject v_24377, v_24378;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24360,v_24359);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24359,v_24360);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24360;
    v_24377 = v_24359;
// end of prologue
    goto v_24367;
v_24363:
    goto v_24373;
v_24369:
    v_24378 = v_24377;
    goto v_24370;
v_24371:
    v_24377 = stack[0];
    goto v_24372;
v_24373:
    goto v_24369;
v_24370:
    goto v_24371;
v_24372:
    fn = elt(env, 1); // remf
    v_24378 = (*qfn2(fn))(fn, v_24378, v_24377);
    env = stack[-1];
    goto v_24364;
v_24365:
    v_24377 = stack[0];
    goto v_24366;
v_24367:
    goto v_24363;
v_24364:
    goto v_24365;
v_24366:
    {
        fn = elt(env, 2); // pasf_premf1
        return (*qfn2(fn))(fn, v_24378, v_24377);
    }
}



setup_type const u43_setup[] =
{
    {"expand_terminal",         CC_expand_terminal,TOO_MANY_1, WRONG_NO_1},
    {"subtractinds",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_subtractinds},
    {"cl_subfof",               TOO_FEW_2,      CC_cl_subfof,  WRONG_NO_2},
    {"rl_sacatlp",              TOO_FEW_2,      CC_rl_sacatlp, WRONG_NO_2},
    {"cl_sacatlp",              TOO_FEW_2,      CC_cl_sacatlp, WRONG_NO_2},
    {"ciom",                    CC_ciom,        TOO_MANY_1,    WRONG_NO_1},
    {"simpsqrtsq",              CC_simpsqrtsq,  TOO_MANY_1,    WRONG_NO_1},
    {"insertocc",               TOO_FEW_2,      CC_insertocc,  WRONG_NO_2},
    {"new_simpexpt",            CC_new_simpexpt,TOO_MANY_1,    WRONG_NO_1},
    {"a2vdp",                   CC_a2vdp,       TOO_MANY_1,    WRONG_NO_1},
    {"xreadlist",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xreadlist},
    {"physoppri",               CC_physoppri,   TOO_MANY_1,    WRONG_NO_1},
    {"nonmult",                 CC_nonmult,     TOO_MANY_1,    WRONG_NO_1},
    {"gadd",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gadd},
    {"fctlength",               CC_fctlength,   TOO_MANY_1,    WRONG_NO_1},
    {"rl_identity1",            CC_rl_identity1,TOO_MANY_1,    WRONG_NO_1},
    {"prsubsetrd",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_prsubsetrd},
    {"f4",                      CC_f4,          TOO_MANY_1,    WRONG_NO_1},
    {"findoptrow",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_findoptrow},
    {"find_bubles_coeff",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_find_bubles_coeff},
    {"primep27",                CC_primep27,    TOO_MANY_1,    WRONG_NO_1},
    {"reduce-columns",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_reduceKcolumns},
    {"extadd",                  TOO_FEW_2,      CC_extadd,     WRONG_NO_2},
    {"co_hfn",                  CC_co_hfn,      TOO_MANY_1,    WRONG_NO_1},
    {"rtypepart",               CC_rtypepart,   TOO_MANY_1,    WRONG_NO_1},
    {"mk+equation",             TOO_FEW_2,      CC_mkLequation,WRONG_NO_2},
    {"freeof-dfl",              TOO_FEW_2,      CC_freeofKdfl, WRONG_NO_2},
    {"talp_invtscc",            CC_talp_invtscc,TOO_MANY_1,    WRONG_NO_1},
    {"pasf_or",                 CC_pasf_or,     TOO_MANY_1,    WRONG_NO_1},
    {"sfto_dprpartf",           CC_sfto_dprpartf,TOO_MANY_1,   WRONG_NO_1},
    {"integralir",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_integralir},
    {"plusrd",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_plusrd},
    {"simpu",                   CC_simpu,       TOO_MANY_1,    WRONG_NO_1},
    {"o-nextarg",               CC_oKnextarg,   TOO_MANY_1,    WRONG_NO_1},
    {"incident1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_incident1},
    {"evalwhereexp",            CC_evalwhereexp,TOO_MANY_1,    WRONG_NO_1},
    {"lieninstruc",             CC_lieninstruc, TOO_MANY_1,    WRONG_NO_1},
    {"balance_mod",             TOO_FEW_2,      CC_balance_mod,WRONG_NO_2},
    {"appr",                    TOO_FEW_2,      CC_appr,       WRONG_NO_2},
    {"super_vectorfield",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_super_vectorfield},
    {"fctargs",                 CC_fctargs,     TOO_MANY_1,    WRONG_NO_1},
    {"expf",                    TOO_FEW_2,      CC_expf,       WRONG_NO_2},
    {"pasf_premf",              TOO_FEW_2,      CC_pasf_premf, WRONG_NO_2},
    {NULL, (one_args *)"u43", (two_args *)"168463 2100903 6321835", 0}
};

// end of generated code
