
// $destdir/u20.c        Machine generated C code

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



// Code for ir2om

static LispObject CC_ir2om(LispObject env,
                         LispObject v_11184)
{
    env = qenv(env);
    LispObject v_11200;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11184);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_11184;
// end of prologue
    v_11200 = (LispObject)32+TAG_FIXNUM; // 2
    qvalue(elt(env, 1)) = v_11200; // ind
    v_11200 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 2)) = v_11200; // indent
    v_11200 = elt(env, 3); // "<OMOBJ>"
    fn = elt(env, 5); // printout
    v_11200 = (*qfn1(fn))(fn, v_11200);
    env = stack[-1];
    v_11200 = lisp_true;
    fn = elt(env, 6); // indent!*
    v_11200 = (*qfn1(fn))(fn, v_11200);
    env = stack[-1];
    v_11200 = stack[0];
    fn = elt(env, 7); // objectom
    v_11200 = (*qfn1(fn))(fn, v_11200);
    env = stack[-1];
    v_11200 = nil;
    fn = elt(env, 6); // indent!*
    v_11200 = (*qfn1(fn))(fn, v_11200);
    env = stack[-1];
    v_11200 = elt(env, 4); // "</OMOBJ>"
    fn = elt(env, 5); // printout
    v_11200 = (*qfn1(fn))(fn, v_11200);
    v_11200 = nil;
    return onevalue(v_11200);
}



// Code for groebcplistsortin

static LispObject CC_groebcplistsortin(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11205, v_11206;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_11185;
    v_11206 = v_11184;
// end of prologue
    v_11205 = stack[0];
    if (v_11205 == nil) goto v_11189;
    else goto v_11190;
v_11189:
    v_11205 = v_11206;
    return ncons(v_11205);
v_11190:
    goto v_11201;
v_11197:
    goto v_11198;
v_11199:
    v_11205 = stack[0];
    goto v_11200;
v_11201:
    goto v_11197;
v_11198:
    goto v_11199;
v_11200:
    fn = elt(env, 1); // groebcplistsortin1
    v_11205 = (*qfn2(fn))(fn, v_11206, v_11205);
    v_11205 = stack[0];
    goto v_11188;
    v_11205 = nil;
v_11188:
    return onevalue(v_11205);
}



// Code for assert_uninstall

static LispObject CC_assert_uninstall(LispObject env,
                         LispObject v_11184)
{
    env = qenv(env);
    LispObject v_11204;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11184);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_11204 = v_11184;
// end of prologue
    stack[0] = v_11204;
v_11189:
    v_11204 = stack[0];
    if (v_11204 == nil) goto v_11193;
    else goto v_11194;
v_11193:
    v_11204 = nil;
    goto v_11188;
v_11194:
    v_11204 = stack[0];
    v_11204 = qcar(v_11204);
    fn = elt(env, 1); // assert_uninstall1
    v_11204 = (*qfn1(fn))(fn, v_11204);
    env = stack[-1];
    v_11204 = stack[0];
    v_11204 = qcdr(v_11204);
    stack[0] = v_11204;
    goto v_11189;
v_11188:
    return onevalue(v_11204);
}



// Code for mo_times_ei

static LispObject CC_mo_times_ei(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11226, v_11227, v_11228;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_11228 = v_11185;
    v_11227 = v_11184;
// end of prologue
    v_11226 = v_11228;
    v_11226 = qcar(v_11226);
    if (v_11226 == nil) goto v_11189;
    else goto v_11190;
v_11189:
    v_11226 = v_11227;
    v_11226 = ncons(v_11226);
    env = stack[-1];
    goto v_11188;
v_11190:
    goto v_11202;
v_11198:
    goto v_11207;
v_11203:
    goto v_11204;
v_11205:
    v_11226 = v_11228;
    v_11226 = qcar(v_11226);
    v_11226 = qcar(v_11226);
    goto v_11206;
v_11207:
    goto v_11203;
v_11204:
    goto v_11205;
v_11206:
    v_11226 = (LispObject)(intptr_t)((intptr_t)v_11227 + (intptr_t)v_11226 - TAG_FIXNUM);
    goto v_11199;
v_11200:
    v_11227 = v_11228;
    v_11227 = qcar(v_11227);
    v_11227 = qcdr(v_11227);
    goto v_11201;
v_11202:
    goto v_11198;
v_11199:
    goto v_11200;
v_11201:
    v_11226 = cons(v_11226, v_11227);
    env = stack[-1];
    goto v_11188;
    v_11226 = nil;
v_11188:
    goto v_11222;
v_11218:
    stack[0] = v_11226;
    goto v_11219;
v_11220:
    fn = elt(env, 1); // mo!=deglist
    v_11226 = (*qfn1(fn))(fn, v_11226);
    goto v_11221;
v_11222:
    goto v_11218;
v_11219:
    goto v_11220;
v_11221:
    {
        LispObject v_11230 = stack[0];
        return cons(v_11230, v_11226);
    }
}



// Code for th_match

static LispObject CC_th_match(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11218, v_11219;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11185;
    stack[-1] = v_11184;
// end of prologue
    goto v_11196;
v_11192:
    v_11219 = stack[-1];
    goto v_11193;
v_11194:
    v_11218 = stack[0];
    goto v_11195;
v_11196:
    goto v_11192;
v_11193:
    goto v_11194;
v_11195:
    fn = elt(env, 1); // th_match0
    v_11218 = (*qfn2(fn))(fn, v_11219, v_11218);
    env = stack[-2];
    if (v_11218 == nil) goto v_11189;
    else goto v_11190;
v_11189:
    v_11218 = nil;
    goto v_11188;
v_11190:
    goto v_11206;
v_11202:
    v_11218 = stack[-1];
    v_11218 = qcdr(v_11218);
    v_11218 = qcar(v_11218);
    fn = elt(env, 2); // dl_get
    v_11218 = (*qfn1(fn))(fn, v_11218);
    env = stack[-2];
    stack[-1] = Llength(nil, v_11218);
    env = stack[-2];
    goto v_11203;
v_11204:
    v_11218 = stack[0];
    v_11218 = qcdr(v_11218);
    v_11218 = qcar(v_11218);
    fn = elt(env, 2); // dl_get
    v_11218 = (*qfn1(fn))(fn, v_11218);
    env = stack[-2];
    v_11218 = Llength(nil, v_11218);
    goto v_11205;
v_11206:
    goto v_11202;
v_11203:
    goto v_11204;
v_11205:
    v_11218 = (equal(stack[-1], v_11218) ? lisp_true : nil);
    goto v_11188;
    v_11218 = nil;
v_11188:
    return onevalue(v_11218);
}



// Code for arplus!:

static LispObject CC_arplusT(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11209, v_11210, v_11211;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_11210 = v_11185;
    v_11211 = v_11184;
// end of prologue
// Binding dmode!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = nil; // dmode!*
// Binding !*exp
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-3, 2, -1);
    qvalue(elt(env, 2)) = nil; // !*exp
    v_11209 = lisp_true;
    qvalue(elt(env, 2)) = v_11209; // !*exp
    goto v_11197;
v_11193:
    stack[0] = elt(env, 3); // !:ar!:
    goto v_11194;
v_11195:
    goto v_11204;
v_11200:
    v_11209 = v_11211;
    v_11209 = qcdr(v_11209);
    goto v_11201;
v_11202:
    v_11210 = qcdr(v_11210);
    goto v_11203;
v_11204:
    goto v_11200;
v_11201:
    goto v_11202;
v_11203:
    fn = elt(env, 4); // addf
    v_11209 = (*qfn2(fn))(fn, v_11209, v_11210);
    env = stack[-3];
    goto v_11196;
v_11197:
    goto v_11193;
v_11194:
    goto v_11195;
v_11196:
    v_11209 = cons(stack[0], v_11209);
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_11209);
}



// Code for subf1

static LispObject CC_subf1(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11932, v_11933, v_11934;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(15);
// copy arguments values to proper place
    stack[-11] = v_11185;
    stack[-12] = v_11184;
// end of prologue
    v_11932 = stack[-12];
    if (v_11932 == nil) goto v_11189;
    else goto v_11190;
v_11189:
    goto v_11197;
v_11193:
    v_11933 = nil;
    goto v_11194;
v_11195:
    v_11932 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11196;
v_11197:
    goto v_11193;
v_11194:
    goto v_11195;
v_11196:
    return cons(v_11933, v_11932);
v_11190:
    v_11932 = stack[-12];
    if (!consp(v_11932)) goto v_11204;
    else goto v_11205;
v_11204:
    v_11932 = lisp_true;
    goto v_11203;
v_11205:
    v_11932 = stack[-12];
    v_11932 = qcar(v_11932);
    v_11932 = (consp(v_11932) ? nil : lisp_true);
    goto v_11203;
    v_11932 = nil;
v_11203:
    if (v_11932 == nil) goto v_11201;
    v_11932 = stack[-12];
    if (!consp(v_11932)) goto v_11215;
    else goto v_11216;
v_11215:
    v_11932 = qvalue(elt(env, 1)); // dmode!*
    if (v_11932 == nil) goto v_11220;
    else goto v_11221;
v_11220:
    goto v_11228;
v_11224:
    v_11933 = stack[-12];
    goto v_11225;
v_11226:
    v_11932 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11227;
v_11228:
    goto v_11224;
v_11225:
    goto v_11226;
v_11227:
    return cons(v_11933, v_11932);
v_11221:
    v_11932 = stack[-12];
    {
        fn = elt(env, 11); // simpatom
        return (*qfn1(fn))(fn, v_11932);
    }
    v_11932 = nil;
    goto v_11214;
v_11216:
    goto v_11245;
v_11241:
    v_11933 = qvalue(elt(env, 1)); // dmode!*
    goto v_11242;
v_11243:
    v_11932 = stack[-12];
    v_11932 = qcar(v_11932);
    goto v_11244;
v_11245:
    goto v_11241;
v_11242:
    goto v_11243;
v_11244:
    if (v_11933 == v_11932) goto v_11239;
    else goto v_11240;
v_11239:
    goto v_11254;
v_11250:
    v_11933 = qvalue(elt(env, 1)); // dmode!*
    goto v_11251;
v_11252:
    v_11932 = elt(env, 2); // resimplify
    goto v_11253;
v_11254:
    goto v_11250;
v_11251:
    goto v_11252;
v_11253:
    v_11932 = Lflagp(nil, v_11933, v_11932);
    env = stack[-14];
    v_11932 = (v_11932 == nil ? lisp_true : nil);
    goto v_11238;
v_11240:
    v_11932 = nil;
    goto v_11238;
    v_11932 = nil;
v_11238:
    if (v_11932 == nil) goto v_11236;
    v_11932 = stack[-12];
    {
        fn = elt(env, 12); // !*d2q
        return (*qfn1(fn))(fn, v_11932);
    }
v_11236:
    v_11932 = stack[-12];
    fn = elt(env, 13); // prepf
    v_11932 = (*qfn1(fn))(fn, v_11932);
    env = stack[-14];
    {
        fn = elt(env, 14); // simp
        return (*qfn1(fn))(fn, v_11932);
    }
    v_11932 = nil;
v_11214:
    goto v_11188;
v_11201:
// Binding varstack!*
// FLUIDBIND: reloadenv=14 litvec-offset=3 saveloc=9
{   bind_fluid_stack bind_fluid_var(-14, 3, -9);
    qvalue(elt(env, 3)) = nil; // varstack!*
    stack[-5] = nil;
    stack[-4] = nil;
    v_11932 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-13] = v_11932;
    goto v_11300;
v_11296:
    v_11933 = nil;
    goto v_11297;
v_11298:
    v_11932 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11299;
v_11300:
    goto v_11296;
v_11297:
    goto v_11298;
v_11299:
    v_11932 = cons(v_11933, v_11932);
    env = stack[-14];
    stack[-3] = v_11932;
v_11285:
    v_11932 = stack[-12];
    v_11932 = qcar(v_11932);
    v_11932 = qcar(v_11932);
    v_11932 = qcar(v_11932);
    stack[-2] = v_11932;
    v_11932 = nil;
    stack[0] = v_11932;
    goto v_11317;
v_11313:
    v_11933 = stack[-2];
    goto v_11314;
v_11315:
    v_11932 = stack[-11];
    goto v_11316;
v_11317:
    goto v_11313;
v_11314:
    goto v_11315;
v_11316:
    v_11932 = Lassoc(nil, v_11933, v_11932);
    if (v_11932 == nil) goto v_11311;
    goto v_11326;
v_11322:
    v_11933 = stack[-2];
    goto v_11323;
v_11324:
    v_11932 = qvalue(elt(env, 4)); // wtl!*
    goto v_11325;
v_11326:
    goto v_11322;
v_11323:
    goto v_11324;
v_11325:
    v_11932 = Lassoc(nil, v_11933, v_11932);
    stack[0] = v_11932;
    if (v_11932 == nil) goto v_11311;
    v_11932 = stack[0];
    v_11932 = qcdr(v_11932);
    stack[0] = v_11932;
    goto v_11309;
v_11311:
v_11309:
    goto v_11340;
v_11336:
    v_11933 = stack[-2];
    goto v_11337;
v_11338:
    v_11932 = qvalue(elt(env, 5)); // asymplis!*
    goto v_11339;
v_11340:
    goto v_11336;
v_11337:
    goto v_11338;
v_11339:
    v_11932 = Lassoc(nil, v_11933, v_11932);
    stack[-10] = v_11932;
    if (v_11932 == nil) goto v_11335;
    v_11932 = stack[-10];
    v_11932 = qcdr(v_11932);
    stack[-10] = v_11932;
    goto v_11333;
v_11335:
v_11333:
v_11286:
    v_11932 = stack[-12];
    if (v_11932 == nil) goto v_11352;
    else goto v_11353;
v_11352:
    v_11932 = lisp_true;
    goto v_11351;
v_11353:
    goto v_11362;
v_11358:
    goto v_11368;
v_11364:
    v_11933 = stack[-12];
    goto v_11365;
v_11366:
    v_11932 = stack[-2];
    goto v_11367;
v_11368:
    goto v_11364;
v_11365:
    goto v_11366;
v_11367:
    fn = elt(env, 15); // degr
    v_11933 = (*qfn2(fn))(fn, v_11933, v_11932);
    env = stack[-14];
    stack[-13] = v_11933;
    goto v_11359;
v_11360:
    v_11932 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11361;
v_11362:
    goto v_11358;
v_11359:
    goto v_11360;
v_11361:
    v_11932 = (v_11933 == v_11932 ? lisp_true : nil);
    goto v_11351;
    v_11932 = nil;
v_11351:
    if (v_11932 == nil) goto v_11349;
    goto v_11287;
v_11349:
    v_11932 = stack[-10];
    if (v_11932 == nil) goto v_11377;
    else goto v_11378;
v_11377:
    v_11932 = lisp_true;
    goto v_11376;
v_11378:
    goto v_11388;
v_11384:
    v_11933 = stack[-13];
    goto v_11385;
v_11386:
    v_11932 = stack[-10];
    goto v_11387;
v_11388:
    goto v_11384;
v_11385:
    goto v_11386;
v_11387:
    v_11932 = (LispObject)lessp2(v_11933, v_11932);
    v_11932 = v_11932 ? lisp_true : nil;
    env = stack[-14];
    goto v_11376;
    v_11932 = nil;
v_11376:
    if (v_11932 == nil) goto v_11374;
    goto v_11396;
v_11392:
    goto v_11402;
v_11398:
    v_11932 = stack[-12];
    v_11933 = qcar(v_11932);
    goto v_11399;
v_11400:
    v_11932 = stack[0];
    goto v_11401;
v_11402:
    goto v_11398;
v_11399:
    goto v_11400;
v_11401:
    fn = elt(env, 16); // wtchk
    v_11933 = (*qfn2(fn))(fn, v_11933, v_11932);
    env = stack[-14];
    goto v_11393;
v_11394:
    v_11932 = stack[-5];
    goto v_11395;
v_11396:
    goto v_11392;
v_11393:
    goto v_11394;
v_11395:
    v_11932 = cons(v_11933, v_11932);
    env = stack[-14];
    stack[-5] = v_11932;
    goto v_11347;
v_11374:
v_11347:
    v_11932 = stack[-12];
    v_11932 = qcdr(v_11932);
    stack[-12] = v_11932;
    goto v_11286;
v_11287:
    v_11932 = nil;
    v_11934 = v_11932;
v_11412:
    v_11932 = stack[-11];
    if (v_11932 == nil) goto v_11415;
    else goto v_11416;
v_11415:
    goto v_11411;
v_11416:
    goto v_11427;
v_11423:
    v_11932 = stack[-11];
    v_11932 = qcar(v_11932);
    v_11933 = qcar(v_11932);
    goto v_11424;
v_11425:
    v_11932 = stack[-11];
    v_11932 = qcar(v_11932);
    v_11932 = qcdr(v_11932);
    goto v_11426;
v_11427:
    goto v_11423;
v_11424:
    goto v_11425;
v_11426:
    if (equal(v_11933, v_11932)) goto v_11422;
    goto v_11439;
v_11435:
    v_11932 = stack[-11];
    v_11932 = qcar(v_11932);
    goto v_11436;
v_11437:
    v_11933 = v_11934;
    goto v_11438;
v_11439:
    goto v_11435;
v_11436:
    goto v_11437;
v_11438:
    v_11932 = cons(v_11932, v_11933);
    env = stack[-14];
    v_11934 = v_11932;
    goto v_11420;
v_11422:
v_11420:
    v_11932 = stack[-11];
    v_11932 = qcdr(v_11932);
    stack[-11] = v_11932;
    goto v_11412;
v_11411:
    v_11932 = v_11934;
    v_11932 = Lnreverse(nil, v_11932);
    env = stack[-14];
    stack[-11] = v_11932;
    v_11932 = stack[-2];
    if (!consp(v_11932)) goto v_11454;
    v_11932 = stack[-2];
    v_11932 = qcar(v_11932);
    v_11932 = (consp(v_11932) ? nil : lisp_true);
    v_11932 = (v_11932 == nil ? lisp_true : nil);
    goto v_11452;
v_11454:
    v_11932 = nil;
    goto v_11452;
    v_11932 = nil;
v_11452:
    if (v_11932 == nil) goto v_11450;
    v_11932 = stack[-2];
    fn = elt(env, 13); // prepf
    v_11932 = (*qfn1(fn))(fn, v_11932);
    env = stack[-14];
    stack[-2] = v_11932;
    goto v_11448;
v_11450:
v_11448:
    v_11932 = stack[-11];
    if (v_11932 == nil) goto v_11467;
    else goto v_11468;
v_11467:
    goto v_11478;
v_11474:
    v_11933 = stack[-2];
    goto v_11475;
v_11476:
    v_11932 = elt(env, 6); // k!*
    goto v_11477;
v_11478:
    goto v_11474;
v_11475:
    goto v_11476;
v_11477:
    if (v_11933 == v_11932) goto v_11472;
    else goto v_11473;
v_11472:
    v_11932 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11471;
v_11473:
    v_11932 = stack[-2];
    goto v_11471;
    v_11932 = nil;
v_11471:
    stack[-1] = v_11932;
    goto v_11466;
v_11468:
    goto v_11495;
v_11491:
    goto v_11501;
v_11497:
    v_11933 = stack[-11];
    goto v_11498;
v_11499:
    v_11932 = stack[-2];
    goto v_11500;
v_11501:
    goto v_11497;
v_11498:
    goto v_11499;
v_11500:
    fn = elt(env, 17); // subsublis
    v_11933 = (*qfn2(fn))(fn, v_11933, v_11932);
    env = stack[-14];
    stack[-1] = v_11933;
    goto v_11492;
v_11493:
    v_11932 = stack[-2];
    goto v_11494;
v_11495:
    goto v_11491;
v_11492:
    goto v_11493;
v_11494:
    if (equal(v_11933, v_11932)) goto v_11489;
    else goto v_11490;
v_11489:
    goto v_11509;
v_11505:
    v_11933 = stack[-2];
    goto v_11506;
v_11507:
    v_11932 = qvalue(elt(env, 5)); // asymplis!*
    goto v_11508;
v_11509:
    goto v_11505;
v_11506:
    goto v_11507;
v_11508:
    v_11932 = Lassoc(nil, v_11933, v_11932);
    v_11932 = (v_11932 == nil ? lisp_true : nil);
    goto v_11488;
v_11490:
    v_11932 = nil;
    goto v_11488;
    v_11932 = nil;
v_11488:
    if (v_11932 == nil) goto v_11486;
    goto v_11290;
v_11486:
v_11466:
v_11288:
    goto v_11522;
v_11518:
    v_11933 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11519;
v_11520:
    v_11932 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11521;
v_11522:
    goto v_11518;
v_11519:
    goto v_11520;
v_11521:
    v_11932 = cons(v_11933, v_11932);
    env = stack[-14];
    stack[-8] = v_11932;
    v_11932 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-13] = v_11932;
    v_11932 = stack[-5];
    if (v_11932 == nil) goto v_11529;
    v_11932 = stack[-5];
    v_11932 = qcar(v_11932);
    v_11932 = qcar(v_11932);
    v_11932 = qcdr(v_11932);
    v_11932 = Lminusp(nil, v_11932);
    env = stack[-14];
    if (v_11932 == nil) goto v_11529;
    goto v_11291;
v_11529:
    goto v_11546;
v_11542:
    v_11932 = stack[-1];
    fn = elt(env, 18); // getrtype
    v_11933 = (*qfn1(fn))(fn, v_11932);
    env = stack[-14];
    stack[-7] = v_11933;
    goto v_11543;
v_11544:
    v_11932 = elt(env, 7); // yetunknowntype
    goto v_11545;
v_11546:
    goto v_11542;
v_11543:
    goto v_11544;
v_11545:
    if (v_11933 == v_11932) goto v_11540;
    else goto v_11541;
v_11540:
    goto v_11556;
v_11552:
    v_11933 = stack[-1];
    goto v_11553;
v_11554:
    v_11932 = nil;
    goto v_11555;
v_11556:
    goto v_11552;
v_11553:
    goto v_11554;
v_11555:
    fn = elt(env, 19); // eval!-yetunknowntypeexpr
    v_11932 = (*qfn2(fn))(fn, v_11933, v_11932);
    env = stack[-14];
    stack[-1] = v_11932;
    fn = elt(env, 18); // getrtype
    v_11932 = (*qfn1(fn))(fn, v_11932);
    env = stack[-14];
    stack[-7] = v_11932;
    goto v_11539;
v_11541:
v_11539:
    v_11932 = stack[-7];
    if (v_11932 == nil) goto v_11562;
    goto v_11570;
v_11566:
    v_11933 = stack[-7];
    goto v_11567;
v_11568:
    v_11932 = elt(env, 8); // list
    goto v_11569;
v_11570:
    goto v_11566;
v_11567:
    goto v_11568;
v_11569:
    if (v_11933 == v_11932) goto v_11562;
    goto v_11578;
v_11574:
    goto v_11584;
v_11580:
    v_11933 = stack[-7];
    goto v_11581;
v_11582:
    v_11932 = stack[-1];
    goto v_11583;
v_11584:
    goto v_11580;
v_11581:
    goto v_11582;
v_11583:
    v_11933 = list2(v_11933, v_11932);
    env = stack[-14];
    goto v_11575;
v_11576:
    v_11932 = elt(env, 9); // "substituted expression"
    goto v_11577;
v_11578:
    goto v_11574;
v_11575:
    goto v_11576;
v_11577:
    fn = elt(env, 20); // typerr
    v_11932 = (*qfn2(fn))(fn, v_11933, v_11932);
    env = stack[-14];
    goto v_11560;
v_11562:
v_11560:
    v_11932 = nil;
    fn = elt(env, 21); // setkorder
    v_11932 = (*qfn1(fn))(fn, v_11932);
    env = stack[-14];
    stack[0] = v_11932;
    v_11932 = stack[-1];
    fn = elt(env, 14); // simp
    v_11932 = (*qfn1(fn))(fn, v_11932);
    env = stack[-14];
    stack[-7] = v_11932;
    v_11932 = stack[0];
    fn = elt(env, 21); // setkorder
    v_11932 = (*qfn1(fn))(fn, v_11932);
    env = stack[-14];
    v_11932 = stack[-7];
    fn = elt(env, 22); // reordsq
    v_11932 = (*qfn1(fn))(fn, v_11932);
    env = stack[-14];
    stack[-7] = v_11932;
    v_11932 = stack[-11];
    if (v_11932 == nil) goto v_11602;
    else goto v_11603;
v_11602:
    v_11932 = stack[-7];
    fn = elt(env, 23); // kernp
    v_11932 = (*qfn1(fn))(fn, v_11932);
    env = stack[-14];
    if (v_11932 == nil) goto v_11607;
    else goto v_11608;
v_11607:
    v_11932 = nil;
    goto v_11606;
v_11608:
    goto v_11618;
v_11614:
    v_11932 = stack[-7];
    v_11932 = qcar(v_11932);
    v_11932 = qcar(v_11932);
    v_11932 = qcar(v_11932);
    v_11933 = qcar(v_11932);
    goto v_11615;
v_11616:
    v_11932 = stack[-2];
    goto v_11617;
v_11618:
    goto v_11614;
v_11615:
    goto v_11616;
v_11617:
    v_11932 = (v_11933 == v_11932 ? lisp_true : nil);
    goto v_11606;
    v_11932 = nil;
v_11606:
    goto v_11601;
v_11603:
    v_11932 = nil;
    goto v_11601;
    v_11932 = nil;
v_11601:
    if (v_11932 == nil) goto v_11599;
    goto v_11290;
v_11599:
    v_11932 = stack[-7];
    v_11932 = qcar(v_11932);
    if (v_11932 == nil) goto v_11629;
    else goto v_11630;
v_11629:
    goto v_11289;
v_11630:
    v_11932 = stack[-7];
    stack[-6] = v_11932;
    v_11932 = stack[-5];
    stack[-2] = v_11932;
v_11637:
    v_11932 = stack[-2];
    if (v_11932 == nil) goto v_11641;
    else goto v_11642;
v_11641:
    goto v_11636;
v_11642:
    v_11932 = stack[-2];
    v_11932 = qcar(v_11932);
    stack[-1] = v_11932;
    v_11932 = stack[-1];
    v_11932 = qcar(v_11932);
    v_11932 = qcdr(v_11932);
    stack[-10] = v_11932;
    goto v_11659;
v_11655:
    v_11933 = stack[-10];
    goto v_11656;
v_11657:
    v_11932 = qvalue(elt(env, 10)); // frlis!*
    goto v_11658;
v_11659:
    goto v_11655;
v_11656:
    goto v_11657;
v_11658:
    v_11932 = Lmemq(nil, v_11933, v_11932);
    if (v_11932 == nil) goto v_11654;
    goto v_11669;
v_11665:
    v_11932 = stack[-6];
    fn = elt(env, 24); // prepsq
    v_11933 = (*qfn1(fn))(fn, v_11932);
    env = stack[-14];
    goto v_11666;
v_11667:
    v_11932 = stack[-10];
    goto v_11668;
v_11669:
    goto v_11665;
v_11666:
    goto v_11667;
v_11668:
    v_11932 = list2(v_11933, v_11932);
    env = stack[-14];
    fn = elt(env, 25); // simpexpt
    v_11932 = (*qfn1(fn))(fn, v_11932);
    env = stack[-14];
    stack[-7] = v_11932;
    v_11932 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-10] = v_11932;
    goto v_11652;
v_11654:
v_11652:
    goto v_11679;
v_11675:
    goto v_11686;
v_11682:
    stack[0] = stack[-7];
    goto v_11683;
v_11684:
    goto v_11693;
v_11689:
    v_11933 = stack[-10];
    goto v_11690;
v_11691:
    v_11932 = stack[-13];
    goto v_11692;
v_11693:
    goto v_11689;
v_11690:
    goto v_11691;
v_11692:
    v_11932 = difference2(v_11933, v_11932);
    env = stack[-14];
    goto v_11685;
v_11686:
    goto v_11682;
v_11683:
    goto v_11684;
v_11685:
    fn = elt(env, 26); // exptsq
    v_11932 = (*qfn2(fn))(fn, stack[0], v_11932);
    env = stack[-14];
    fn = elt(env, 27); // subs2
    v_11933 = (*qfn1(fn))(fn, v_11932);
    env = stack[-14];
    goto v_11676;
v_11677:
    v_11932 = stack[-8];
    goto v_11678;
v_11679:
    goto v_11675;
v_11676:
    goto v_11677;
v_11678:
    fn = elt(env, 28); // multsq
    v_11932 = (*qfn2(fn))(fn, v_11933, v_11932);
    env = stack[-14];
    stack[-8] = v_11932;
    v_11932 = stack[-10];
    stack[-13] = v_11932;
    goto v_11703;
v_11699:
    goto v_11709;
v_11705:
    stack[0] = stack[-8];
    goto v_11706;
v_11707:
    goto v_11716;
v_11712:
    v_11932 = stack[-1];
    v_11933 = qcdr(v_11932);
    goto v_11713;
v_11714:
    v_11932 = stack[-11];
    goto v_11715;
v_11716:
    goto v_11712;
v_11713:
    goto v_11714;
v_11715:
    v_11932 = CC_subf1(elt(env, 0), v_11933, v_11932);
    env = stack[-14];
    goto v_11708;
v_11709:
    goto v_11705;
v_11706:
    goto v_11707;
v_11708:
    fn = elt(env, 28); // multsq
    v_11933 = (*qfn2(fn))(fn, stack[0], v_11932);
    env = stack[-14];
    goto v_11700;
v_11701:
    v_11932 = stack[-3];
    goto v_11702;
v_11703:
    goto v_11699;
v_11700:
    goto v_11701;
v_11702:
    fn = elt(env, 29); // addsq
    v_11932 = (*qfn2(fn))(fn, v_11933, v_11932);
    env = stack[-14];
    stack[-3] = v_11932;
    v_11932 = stack[-2];
    v_11932 = qcdr(v_11932);
    stack[-2] = v_11932;
    goto v_11637;
v_11636:
v_11289:
v_11725:
    v_11932 = stack[-5];
    if (v_11932 == nil) goto v_11728;
    else goto v_11729;
v_11728:
    goto v_11724;
v_11729:
    goto v_11737;
v_11733:
    v_11932 = stack[-5];
    v_11932 = qcar(v_11932);
    v_11933 = qcdr(v_11932);
    goto v_11734;
v_11735:
    v_11932 = stack[-11];
    goto v_11736;
v_11737:
    goto v_11733;
v_11734:
    goto v_11735;
v_11736:
    v_11932 = CC_subf1(elt(env, 0), v_11933, v_11932);
    env = stack[-14];
    v_11932 = stack[-5];
    v_11932 = qcdr(v_11932);
    stack[-5] = v_11932;
    goto v_11725;
v_11724:
    v_11932 = stack[-12];
    if (v_11932 == nil) goto v_11746;
    else goto v_11747;
v_11746:
    v_11932 = stack[-3];
    goto v_11284;
v_11747:
    v_11932 = stack[-12];
    if (!consp(v_11932)) goto v_11754;
    else goto v_11755;
v_11754:
    v_11932 = lisp_true;
    goto v_11753;
v_11755:
    v_11932 = stack[-12];
    v_11932 = qcar(v_11932);
    v_11932 = (consp(v_11932) ? nil : lisp_true);
    goto v_11753;
    v_11932 = nil;
v_11753:
    if (v_11932 == nil) goto v_11751;
    goto v_11768;
v_11764:
    goto v_11774;
v_11770:
    v_11933 = stack[-12];
    goto v_11771;
v_11772:
    v_11932 = stack[-11];
    goto v_11773;
v_11774:
    goto v_11770;
v_11771:
    goto v_11772;
v_11773:
    v_11933 = CC_subf1(elt(env, 0), v_11933, v_11932);
    env = stack[-14];
    goto v_11765;
v_11766:
    v_11932 = stack[-3];
    goto v_11767;
v_11768:
    goto v_11764;
v_11765:
    goto v_11766;
v_11767:
    fn = elt(env, 29); // addsq
    v_11932 = (*qfn2(fn))(fn, v_11933, v_11932);
    goto v_11284;
v_11751:
    goto v_11285;
v_11290:
    v_11932 = stack[-2];
    fn = elt(env, 30); // sub2chk
    v_11932 = (*qfn1(fn))(fn, v_11932);
    env = stack[-14];
    v_11932 = stack[-5];
    stack[-2] = v_11932;
v_11783:
    v_11932 = stack[-2];
    if (v_11932 == nil) goto v_11787;
    else goto v_11788;
v_11787:
    goto v_11782;
v_11788:
    v_11932 = stack[-2];
    v_11932 = qcar(v_11932);
    stack[-1] = v_11932;
    goto v_11799;
v_11795:
    goto v_11805;
v_11801:
    goto v_11811;
v_11807:
    goto v_11818;
v_11814:
    v_11932 = stack[-1];
    v_11933 = qcar(v_11932);
    goto v_11815;
v_11816:
    v_11932 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11817;
v_11818:
    goto v_11814;
v_11815:
    goto v_11816;
v_11817:
    v_11932 = cons(v_11933, v_11932);
    env = stack[-14];
    v_11933 = ncons(v_11932);
    env = stack[-14];
    goto v_11808;
v_11809:
    v_11932 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11810;
v_11811:
    goto v_11807;
v_11808:
    goto v_11809;
v_11810:
    stack[0] = cons(v_11933, v_11932);
    env = stack[-14];
    goto v_11802;
v_11803:
    goto v_11828;
v_11824:
    v_11932 = stack[-1];
    v_11933 = qcdr(v_11932);
    goto v_11825;
v_11826:
    v_11932 = stack[-11];
    goto v_11827;
v_11828:
    goto v_11824;
v_11825:
    goto v_11826;
v_11827:
    v_11932 = CC_subf1(elt(env, 0), v_11933, v_11932);
    env = stack[-14];
    goto v_11804;
v_11805:
    goto v_11801;
v_11802:
    goto v_11803;
v_11804:
    fn = elt(env, 28); // multsq
    v_11933 = (*qfn2(fn))(fn, stack[0], v_11932);
    env = stack[-14];
    goto v_11796;
v_11797:
    v_11932 = stack[-3];
    goto v_11798;
v_11799:
    goto v_11795;
v_11796:
    goto v_11797;
v_11798:
    fn = elt(env, 29); // addsq
    v_11932 = (*qfn2(fn))(fn, v_11933, v_11932);
    env = stack[-14];
    stack[-3] = v_11932;
    v_11932 = stack[-2];
    v_11932 = qcdr(v_11932);
    stack[-2] = v_11932;
    goto v_11783;
v_11782:
    goto v_11289;
v_11291:
    v_11932 = stack[-1];
    v_11932 = ncons(v_11932);
    env = stack[-14];
    fn = elt(env, 31); // simprecip
    v_11932 = (*qfn1(fn))(fn, v_11932);
    env = stack[-14];
    stack[-7] = v_11932;
v_11292:
    goto v_11843;
v_11839:
    v_11932 = stack[-5];
    v_11933 = qcar(v_11932);
    goto v_11840;
v_11841:
    v_11932 = stack[-4];
    goto v_11842;
v_11843:
    goto v_11839;
v_11840:
    goto v_11841;
v_11842:
    v_11932 = cons(v_11933, v_11932);
    env = stack[-14];
    stack[-4] = v_11932;
    v_11932 = stack[-5];
    v_11932 = qcdr(v_11932);
    stack[-5] = v_11932;
    v_11932 = stack[-5];
    if (v_11932 == nil) goto v_11852;
    goto v_11861;
v_11857:
    v_11932 = stack[-5];
    v_11932 = qcar(v_11932);
    v_11932 = qcar(v_11932);
    v_11933 = qcdr(v_11932);
    goto v_11858;
v_11859:
    v_11932 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11860;
v_11861:
    goto v_11857;
v_11858:
    goto v_11859;
v_11860:
    v_11932 = (LispObject)lessp2(v_11933, v_11932);
    v_11932 = v_11932 ? lisp_true : nil;
    env = stack[-14];
    if (v_11932 == nil) goto v_11852;
    goto v_11292;
v_11852:
v_11293:
    v_11932 = stack[-4];
    v_11932 = qcar(v_11932);
    v_11932 = qcar(v_11932);
    v_11932 = qcdr(v_11932);
    v_11932 = negate(v_11932);
    env = stack[-14];
    stack[-10] = v_11932;
    goto v_11877;
v_11873:
    goto v_11884;
v_11880:
    stack[0] = stack[-7];
    goto v_11881;
v_11882:
    goto v_11891;
v_11887:
    v_11933 = stack[-10];
    goto v_11888;
v_11889:
    v_11932 = stack[-13];
    goto v_11890;
v_11891:
    goto v_11887;
v_11888:
    goto v_11889;
v_11890:
    v_11932 = difference2(v_11933, v_11932);
    env = stack[-14];
    goto v_11883;
v_11884:
    goto v_11880;
v_11881:
    goto v_11882;
v_11883:
    fn = elt(env, 26); // exptsq
    v_11932 = (*qfn2(fn))(fn, stack[0], v_11932);
    env = stack[-14];
    fn = elt(env, 27); // subs2
    v_11933 = (*qfn1(fn))(fn, v_11932);
    env = stack[-14];
    goto v_11874;
v_11875:
    v_11932 = stack[-8];
    goto v_11876;
v_11877:
    goto v_11873;
v_11874:
    goto v_11875;
v_11876:
    fn = elt(env, 28); // multsq
    v_11932 = (*qfn2(fn))(fn, v_11933, v_11932);
    env = stack[-14];
    stack[-8] = v_11932;
    v_11932 = stack[-10];
    stack[-13] = v_11932;
    goto v_11901;
v_11897:
    goto v_11907;
v_11903:
    stack[0] = stack[-8];
    goto v_11904;
v_11905:
    goto v_11914;
v_11910:
    v_11932 = stack[-4];
    v_11932 = qcar(v_11932);
    v_11933 = qcdr(v_11932);
    goto v_11911;
v_11912:
    v_11932 = stack[-11];
    goto v_11913;
v_11914:
    goto v_11910;
v_11911:
    goto v_11912;
v_11913:
    v_11932 = CC_subf1(elt(env, 0), v_11933, v_11932);
    env = stack[-14];
    goto v_11906;
v_11907:
    goto v_11903;
v_11904:
    goto v_11905;
v_11906:
    fn = elt(env, 28); // multsq
    v_11933 = (*qfn2(fn))(fn, stack[0], v_11932);
    env = stack[-14];
    goto v_11898;
v_11899:
    v_11932 = stack[-3];
    goto v_11900;
v_11901:
    goto v_11897;
v_11898:
    goto v_11899;
v_11900:
    fn = elt(env, 29); // addsq
    v_11932 = (*qfn2(fn))(fn, v_11933, v_11932);
    env = stack[-14];
    stack[-3] = v_11932;
    v_11932 = stack[-4];
    v_11932 = qcdr(v_11932);
    stack[-4] = v_11932;
    v_11932 = stack[-4];
    if (v_11932 == nil) goto v_11925;
    goto v_11293;
v_11925:
    v_11932 = stack[-5];
    if (v_11932 == nil) goto v_11928;
    goto v_11288;
v_11928:
    goto v_11289;
    v_11932 = nil;
v_11284:
    ;}  // end of a binding scope
    goto v_11188;
    v_11932 = nil;
v_11188:
    return onevalue(v_11932);
}



// Code for decprec2internal

static LispObject CC_decprec2internal(LispObject env,
                         LispObject v_11184)
{
    env = qenv(env);
    LispObject v_11202, v_11203;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11184);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_11202 = v_11184;
// end of prologue
    goto v_11191;
v_11187:
    goto v_11198;
v_11194:
    v_11203 = v_11202;
    goto v_11195;
v_11196:
    v_11202 = qvalue(elt(env, 1)); // !!log2of10
    goto v_11197;
v_11198:
    goto v_11194;
v_11195:
    goto v_11196;
v_11197:
    v_11202 = times2(v_11203, v_11202);
    env = stack[0];
    fn = elt(env, 2); // ceiling
    v_11203 = (*qfn1(fn))(fn, v_11202);
    goto v_11188;
v_11189:
    v_11202 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_11190;
v_11191:
    goto v_11187;
v_11188:
    goto v_11189;
v_11190:
    return plus2(v_11203, v_11202);
}



// Code for triplesetprolongset

static LispObject CC_triplesetprolongset(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11222, v_11223;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11185;
    stack[-1] = v_11184;
// end of prologue
    v_11223 = nil;
v_11192:
    v_11222 = stack[0];
    if (v_11222 == nil) goto v_11195;
    else goto v_11196;
v_11195:
    goto v_11191;
v_11196:
    goto v_11204;
v_11200:
    v_11222 = stack[0];
    v_11222 = qcar(v_11222);
    goto v_11201;
v_11202:
    goto v_11203;
v_11204:
    goto v_11200;
v_11201:
    goto v_11202;
v_11203:
    v_11222 = cons(v_11222, v_11223);
    env = stack[-2];
    v_11223 = v_11222;
    v_11222 = stack[0];
    v_11222 = qcdr(v_11222);
    stack[0] = v_11222;
    goto v_11192;
v_11191:
    goto v_11217;
v_11211:
    goto v_11212;
v_11213:
    stack[0] = (LispObject)48+TAG_FIXNUM; // 3
    goto v_11214;
v_11215:
    v_11222 = v_11223;
    v_11222 = Lreverse(nil, v_11222);
    goto v_11216;
v_11217:
    goto v_11211;
v_11212:
    goto v_11213;
v_11214:
    goto v_11215;
v_11216:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_11222;
    v_11222 = nil;
    return onevalue(v_11222);
}



// Code for rl_csimpl

static LispObject CC_rl_csimpl(LispObject env,
                         LispObject v_11184)
{
    env = qenv(env);
    LispObject v_11209, v_11210, v_11211;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11184);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_11184;
// end of prologue
    v_11209 = qvalue(elt(env, 1)); // !*rlsimpl
    if (v_11209 == nil) goto v_11189;
    v_11209 = elt(env, 2); // rl_simpl
    fn = elt(env, 3); // getd
    v_11209 = (*qfn1(fn))(fn, v_11209);
    env = stack[-1];
    if (v_11209 == nil) goto v_11189;
    goto v_11202;
v_11196:
    v_11211 = stack[0];
    goto v_11197;
v_11198:
    v_11210 = nil;
    goto v_11199;
v_11200:
    v_11209 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_11201;
v_11202:
    goto v_11196;
v_11197:
    goto v_11198;
v_11199:
    goto v_11200;
v_11201:
    {
        fn = elt(env, 2); // rl_simpl
        return (*qfnn(fn))(fn, 3, v_11211, v_11210, v_11209);
    }
v_11189:
    v_11209 = stack[0];
    goto v_11187;
    v_11209 = nil;
v_11187:
    return onevalue(v_11209);
}



// Code for talp_invn

static LispObject CC_talp_invn(LispObject env,
                         LispObject v_11184)
{
    env = qenv(env);
    LispObject v_11197;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11184);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_11197 = v_11184;
// end of prologue
    fn = elt(env, 1); // talp_op
    v_11197 = (*qfn1(fn))(fn, v_11197);
    env = stack[0];
    v_11197 = Lexplodec(nil, v_11197);
    env = stack[0];
    v_11197 = qcdr(v_11197);
    v_11197 = qcdr(v_11197);
    v_11197 = qcdr(v_11197);
    v_11197 = qcdr(v_11197);
    v_11197 = qcdr(v_11197);
    v_11197 = qcar(v_11197);
    v_11197 = ncons(v_11197);
        return Lcompress(nil, v_11197);
}



// Code for lx2xx

static LispObject CC_lx2xx(LispObject env,
                         LispObject v_11184)
{
    env = qenv(env);
    LispObject v_11261, v_11262;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11184);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_11184;
// end of prologue
    v_11261 = stack[-2];
    if (!consp(v_11261)) goto v_11200;
    else goto v_11201;
v_11200:
    v_11261 = lisp_true;
    goto v_11199;
v_11201:
    v_11261 = stack[-2];
    v_11261 = qcar(v_11261);
    v_11261 = (consp(v_11261) ? nil : lisp_true);
    goto v_11199;
    v_11261 = nil;
v_11199:
    if (v_11261 == nil) goto v_11197;
    v_11261 = lisp_true;
    goto v_11195;
v_11197:
    v_11261 = stack[-2];
    v_11261 = qcar(v_11261);
    if (!consp(v_11261)) goto v_11214;
    else goto v_11215;
v_11214:
    v_11261 = lisp_true;
    goto v_11213;
v_11215:
    v_11261 = stack[-2];
    v_11261 = qcar(v_11261);
    v_11261 = qcar(v_11261);
    v_11261 = (consp(v_11261) ? nil : lisp_true);
    goto v_11213;
    v_11261 = nil;
v_11213:
    goto v_11195;
    v_11261 = nil;
v_11195:
    if (v_11261 == nil) goto v_11193;
    v_11261 = stack[-2];
    goto v_11189;
v_11193:
    v_11261 = stack[-2];
    v_11261 = qcdr(v_11261);
    v_11261 = qcar(v_11261);
    stack[-3] = v_11261;
    v_11261 = stack[-3];
    fn = elt(env, 1); // lastnondomain
    v_11261 = (*qfn1(fn))(fn, v_11261);
    env = stack[-4];
    v_11261 = qcdr(v_11261);
    stack[-1] = v_11261;
    goto v_11239;
v_11233:
    v_11261 = stack[-2];
    stack[0] = qcar(v_11261);
    goto v_11234;
v_11235:
    goto v_11247;
v_11243:
    goto v_11254;
v_11250:
    v_11262 = stack[-1];
    goto v_11251;
v_11252:
    v_11261 = stack[-3];
    goto v_11253;
v_11254:
    goto v_11250;
v_11251:
    goto v_11252;
v_11253:
    fn = elt(env, 2); // delet
    v_11261 = (*qfn2(fn))(fn, v_11262, v_11261);
    env = stack[-4];
    fn = elt(env, 3); // xxsort
    v_11262 = (*qfn1(fn))(fn, v_11261);
    env = stack[-4];
    goto v_11244;
v_11245:
    v_11261 = stack[-1];
    goto v_11246;
v_11247:
    goto v_11243;
v_11244:
    goto v_11245;
v_11246:
    v_11262 = Lappend(nil, v_11262, v_11261);
    goto v_11236;
v_11237:
    v_11261 = stack[-2];
    v_11261 = qcdr(v_11261);
    v_11261 = qcdr(v_11261);
    goto v_11238;
v_11239:
    goto v_11233;
v_11234:
    goto v_11235;
v_11236:
    goto v_11237;
v_11238:
    {
        LispObject v_11267 = stack[0];
        return list2star(v_11267, v_11262, v_11261);
    }
v_11189:
    return onevalue(v_11261);
}



// Code for ibalp_var!-unsatlist

static LispObject CC_ibalp_varKunsatlist(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11247, v_11248;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_11185;
    v_11247 = v_11184;
// end of prologue
    stack[-3] = v_11247;
v_11190:
    v_11247 = stack[-3];
    if (v_11247 == nil) goto v_11194;
    else goto v_11195;
v_11194:
    v_11247 = nil;
    goto v_11189;
v_11195:
    v_11247 = stack[-3];
    v_11247 = qcar(v_11247);
    stack[-1] = v_11247;
    goto v_11210;
v_11206:
    v_11248 = stack[-2];
    goto v_11207;
v_11208:
    v_11247 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11209;
v_11210:
    goto v_11206;
v_11207:
    goto v_11208;
v_11209:
    v_11247 = Leqn(nil, v_11248, v_11247);
    env = stack[-4];
    if (v_11247 == nil) goto v_11204;
    goto v_11218;
v_11214:
    v_11247 = stack[-1];
    v_11247 = qcdr(v_11247);
    v_11247 = qcdr(v_11247);
    stack[0] = qcdr(v_11247);
    goto v_11215;
v_11216:
    v_11247 = stack[-1];
    v_11247 = qcdr(v_11247);
    v_11247 = qcdr(v_11247);
    v_11247 = qcdr(v_11247);
    v_11247 = qcar(v_11247);
    v_11247 = sub1(v_11247);
    env = stack[-4];
    goto v_11217;
v_11218:
    goto v_11214;
v_11215:
    goto v_11216;
v_11217:
    fn = elt(env, 1); // setcar
    v_11247 = (*qfn2(fn))(fn, stack[0], v_11247);
    env = stack[-4];
    goto v_11202;
v_11204:
    goto v_11236;
v_11232:
    v_11247 = stack[-1];
    v_11247 = qcdr(v_11247);
    stack[0] = qcdr(v_11247);
    goto v_11233;
v_11234:
    v_11247 = stack[-1];
    v_11247 = qcdr(v_11247);
    v_11247 = qcdr(v_11247);
    v_11247 = qcar(v_11247);
    v_11247 = sub1(v_11247);
    env = stack[-4];
    goto v_11235;
v_11236:
    goto v_11232;
v_11233:
    goto v_11234;
v_11235:
    fn = elt(env, 1); // setcar
    v_11247 = (*qfn2(fn))(fn, stack[0], v_11247);
    env = stack[-4];
    goto v_11202;
v_11202:
    v_11247 = stack[-3];
    v_11247 = qcdr(v_11247);
    stack[-3] = v_11247;
    goto v_11190;
v_11189:
    return onevalue(v_11247);
}



// Code for dvfsf_susitf

static LispObject CC_dvfsf_susitf(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11188, v_11189;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11188 = v_11185;
    v_11189 = v_11184;
// end of prologue
    v_11188 = v_11189;
    return onevalue(v_11188);
}



// Code for stats_getargs

static LispObject CC_stats_getargs(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11203, v_11204;
    LispObject fn;
    argcheck(nargs, 0, "stats_getargs");
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
    v_11203 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_11204 = v_11203;
    v_11203 = v_11204;
    if (v_11203 == nil) goto v_11193;
    goto v_11200;
v_11196:
    stack[0] = v_11204;
    goto v_11197;
v_11198:
    v_11203 = CC_stats_getargs(elt(env, 0), 0);
    goto v_11199;
v_11200:
    goto v_11196;
v_11197:
    goto v_11198;
v_11199:
    {
        LispObject v_11206 = stack[0];
        return cons(v_11206, v_11203);
    }
v_11193:
    v_11203 = nil;
    return onevalue(v_11203);
}



// Code for list!-mgen

static LispObject CC_listKmgen(LispObject env,
                         LispObject v_11184)
{
    env = qenv(env);
    LispObject v_11223, v_11224;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11184);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_11224 = v_11184;
// end of prologue
// Binding i
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 1, -1);
    qvalue(elt(env, 1)) = nil; // i
    v_11223 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_11223; // i
    v_11223 = v_11224;
    stack[0] = v_11223;
v_11193:
    v_11223 = stack[0];
    if (v_11223 == nil) goto v_11197;
    else goto v_11198;
v_11197:
    goto v_11192;
v_11198:
    v_11223 = stack[0];
    v_11223 = qcar(v_11223);
    v_11224 = v_11223;
    v_11223 = v_11224;
    if (!consp(v_11223)) goto v_11210;
    else goto v_11211;
v_11210:
    v_11223 = v_11224;
    fn = elt(env, 2); // mgenp
    v_11223 = (*qfn1(fn))(fn, v_11223);
    env = stack[-2];
    goto v_11209;
v_11211:
    v_11223 = nil;
    goto v_11209;
    v_11223 = nil;
v_11209:
    if (v_11223 == nil) goto v_11207;
    v_11223 = qvalue(elt(env, 1)); // i
    v_11223 = add1(v_11223);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_11223; // i
    goto v_11205;
v_11207:
v_11205:
    v_11223 = stack[0];
    v_11223 = qcdr(v_11223);
    stack[0] = v_11223;
    goto v_11193;
v_11192:
    v_11223 = qvalue(elt(env, 1)); // i
    ;}  // end of a binding scope
    return onevalue(v_11223);
}



// Code for prinfit

static LispObject CC_prinfit(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11252, v_11253, v_11254;
    LispObject fn;
    LispObject v_11186, v_11185, v_11184;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "prinfit");
    va_start(aa, nargs);
    v_11184 = va_arg(aa, LispObject);
    v_11185 = va_arg(aa, LispObject);
    v_11186 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_11186,v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_11184,v_11185,v_11186);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11186;
    stack[-1] = v_11185;
    stack[-2] = v_11184;
// end of prologue
    v_11252 = qvalue(elt(env, 1)); // !*nat
    if (v_11252 == nil) goto v_11197;
    else goto v_11198;
v_11197:
    v_11252 = lisp_true;
    goto v_11196;
v_11198:
    v_11252 = qvalue(elt(env, 2)); // testing!-width!*
    goto v_11196;
    v_11252 = nil;
v_11196:
    if (v_11252 == nil) goto v_11194;
    v_11252 = stack[0];
    if (v_11252 == nil) goto v_11207;
    v_11252 = stack[0];
    fn = elt(env, 3); // oprin
    v_11252 = (*qfn1(fn))(fn, v_11252);
    env = stack[-3];
    goto v_11205;
v_11207:
v_11205:
    goto v_11216;
v_11212:
    v_11253 = stack[-2];
    goto v_11213;
v_11214:
    v_11252 = stack[-1];
    goto v_11215;
v_11216:
    goto v_11212;
v_11213:
    goto v_11214;
v_11215:
    {
        fn = elt(env, 4); // maprint
        return (*qfn2(fn))(fn, v_11253, v_11252);
    }
v_11194:
    goto v_11226;
v_11220:
    v_11254 = stack[-2];
    goto v_11221;
v_11222:
    v_11253 = stack[-1];
    goto v_11223;
v_11224:
    v_11252 = stack[0];
    goto v_11225;
v_11226:
    goto v_11220;
v_11221:
    goto v_11222;
v_11223:
    goto v_11224;
v_11225:
    fn = elt(env, 5); // layout!-formula
    v_11252 = (*qfnn(fn))(fn, 3, v_11254, v_11253, v_11252);
    env = stack[-3];
    v_11253 = v_11252;
    v_11252 = v_11253;
    if (v_11252 == nil) goto v_11232;
    else goto v_11233;
v_11232:
    v_11252 = stack[0];
    if (v_11252 == nil) goto v_11238;
    v_11252 = stack[0];
    fn = elt(env, 3); // oprin
    v_11252 = (*qfn1(fn))(fn, v_11252);
    env = stack[-3];
    goto v_11236;
v_11238:
v_11236:
    goto v_11247;
v_11243:
    v_11253 = stack[-2];
    goto v_11244;
v_11245:
    v_11252 = stack[-1];
    goto v_11246;
v_11247:
    goto v_11243;
v_11244:
    goto v_11245;
v_11246:
    {
        fn = elt(env, 4); // maprint
        return (*qfn2(fn))(fn, v_11253, v_11252);
    }
v_11233:
    v_11252 = v_11253;
    fn = elt(env, 6); // putpline
    v_11252 = (*qfn1(fn))(fn, v_11252);
    v_11252 = nil;
    return onevalue(v_11252);
}



// Code for lispassignp

static LispObject CC_lispassignp(LispObject env,
                         LispObject v_11184)
{
    env = qenv(env);
    LispObject v_11194, v_11195;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11194 = v_11184;
// end of prologue
    goto v_11191;
v_11187:
    goto v_11188;
v_11189:
    v_11195 = elt(env, 1); // setq
    goto v_11190;
v_11191:
    goto v_11187;
v_11188:
    goto v_11189;
v_11190:
        return Leqcar(nil, v_11194, v_11195);
}



// Code for assert_uninstall1

static LispObject CC_assert_uninstall1(LispObject env,
                         LispObject v_11184)
{
    env = qenv(env);
    LispObject v_11235, v_11236, v_11237;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11184);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_11184;
// end of prologue
    goto v_11195;
v_11191:
    v_11236 = stack[0];
    goto v_11192;
v_11193:
    v_11235 = elt(env, 1); // assert_installed
    goto v_11194;
v_11195:
    goto v_11191;
v_11192:
    goto v_11193;
v_11194:
    v_11235 = get(v_11236, v_11235);
    env = stack[-1];
    if (v_11235 == nil) goto v_11188;
    else goto v_11189;
v_11188:
    goto v_11204;
v_11200:
    v_11236 = elt(env, 2); // "assert not installed for"
    goto v_11201;
v_11202:
    v_11235 = stack[0];
    goto v_11203;
v_11204:
    goto v_11200;
v_11201:
    goto v_11202;
v_11203:
    v_11235 = list2(v_11236, v_11235);
    env = stack[-1];
    {
        fn = elt(env, 4); // lprim
        return (*qfn1(fn))(fn, v_11235);
    }
v_11189:
    goto v_11214;
v_11210:
    v_11237 = stack[0];
    goto v_11211;
v_11212:
    goto v_11221;
v_11217:
    v_11236 = stack[0];
    goto v_11218;
v_11219:
    v_11235 = elt(env, 3); // assert_noassertfn
    goto v_11220;
v_11221:
    goto v_11217;
v_11218:
    goto v_11219;
v_11220:
    v_11235 = get(v_11236, v_11235);
    env = stack[-1];
    goto v_11213;
v_11214:
    goto v_11210;
v_11211:
    goto v_11212;
v_11213:
    fn = elt(env, 5); // copyd
    v_11235 = (*qfn2(fn))(fn, v_11237, v_11235);
    env = stack[-1];
    goto v_11231;
v_11225:
    v_11236 = stack[0];
    goto v_11226;
v_11227:
    v_11237 = elt(env, 1); // assert_installed
    goto v_11228;
v_11229:
    v_11235 = nil;
    goto v_11230;
v_11231:
    goto v_11225;
v_11226:
    goto v_11227;
v_11228:
    goto v_11229;
v_11230:
        return Lputprop(nil, 3, v_11236, v_11237, v_11235);
    v_11235 = nil;
    return onevalue(v_11235);
}



// Code for evalequal

static LispObject CC_evalequal(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11238, v_11239, v_11240;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11185;
    stack[-2] = v_11184;
// end of prologue
    goto v_11198;
v_11194:
    v_11238 = stack[-2];
    fn = elt(env, 2); // getrtype
    stack[0] = (*qfn1(fn))(fn, v_11238);
    env = stack[-4];
    stack[-3] = stack[0];
    goto v_11195;
v_11196:
    v_11238 = stack[-1];
    fn = elt(env, 2); // getrtype
    v_11238 = (*qfn1(fn))(fn, v_11238);
    env = stack[-4];
    goto v_11197;
v_11198:
    goto v_11194;
v_11195:
    goto v_11196;
v_11197:
    if (equal(stack[0], v_11238)) goto v_11193;
    v_11238 = nil;
    goto v_11191;
v_11193:
    v_11238 = stack[-3];
    if (v_11238 == nil) goto v_11204;
    else goto v_11205;
v_11204:
    goto v_11219;
v_11213:
    v_11240 = elt(env, 1); // difference
    goto v_11214;
v_11215:
    v_11239 = stack[-2];
    goto v_11216;
v_11217:
    v_11238 = stack[-1];
    goto v_11218;
v_11219:
    goto v_11213;
v_11214:
    goto v_11215;
v_11216:
    goto v_11217;
v_11218:
    v_11238 = list3(v_11240, v_11239, v_11238);
    env = stack[-4];
    fn = elt(env, 3); // reval
    v_11238 = (*qfn1(fn))(fn, v_11238);
    stack[-3] = v_11238;
    if (is_number(v_11238)) goto v_11210;
    v_11238 = nil;
    goto v_11208;
v_11210:
    v_11238 = stack[-3];
        return Lzerop(nil, v_11238);
    v_11238 = nil;
v_11208:
    goto v_11191;
v_11205:
    goto v_11234;
v_11230:
    v_11239 = stack[-2];
    goto v_11231;
v_11232:
    v_11238 = stack[-1];
    goto v_11233;
v_11234:
    goto v_11230;
v_11231:
    goto v_11232;
v_11233:
    v_11238 = (equal(v_11239, v_11238) ? lisp_true : nil);
    goto v_11191;
    v_11238 = nil;
v_11191:
    return onevalue(v_11238);
}



// Code for mv2sf1

static LispObject CC_mv2sf1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11243, v_11244, v_11245;
    LispObject fn;
    LispObject v_11186, v_11185, v_11184;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mv2sf1");
    va_start(aa, nargs);
    v_11184 = va_arg(aa, LispObject);
    v_11185 = va_arg(aa, LispObject);
    v_11186 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_11186,v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_11184,v_11185,v_11186);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_11186;
    stack[-1] = v_11185;
    stack[-2] = v_11184;
// end of prologue
v_11190:
    v_11243 = stack[-2];
    if (v_11243 == nil) goto v_11193;
    else goto v_11194;
v_11193:
    v_11243 = stack[-1];
    goto v_11189;
v_11194:
    goto v_11203;
v_11199:
    v_11243 = stack[-2];
    v_11244 = qcar(v_11243);
    goto v_11200;
v_11201:
    v_11243 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11202;
v_11203:
    goto v_11199;
v_11200:
    goto v_11201;
v_11202:
    if (v_11244 == v_11243) goto v_11197;
    else goto v_11198;
v_11197:
    v_11243 = stack[-2];
    v_11243 = qcdr(v_11243);
    stack[-2] = v_11243;
    v_11243 = stack[0];
    v_11243 = qcdr(v_11243);
    stack[0] = v_11243;
    goto v_11190;
v_11198:
    goto v_11219;
v_11215:
    goto v_11225;
v_11221:
    v_11243 = stack[0];
    v_11244 = qcar(v_11243);
    goto v_11222;
v_11223:
    v_11243 = stack[-2];
    v_11243 = qcar(v_11243);
    goto v_11224;
v_11225:
    goto v_11221;
v_11222:
    goto v_11223;
v_11224:
    fn = elt(env, 1); // to
    stack[-3] = (*qfn2(fn))(fn, v_11244, v_11243);
    env = stack[-4];
    goto v_11216;
v_11217:
    goto v_11237;
v_11231:
    v_11243 = stack[-2];
    v_11245 = qcdr(v_11243);
    goto v_11232;
v_11233:
    v_11244 = stack[-1];
    goto v_11234;
v_11235:
    v_11243 = stack[0];
    v_11243 = qcdr(v_11243);
    goto v_11236;
v_11237:
    goto v_11231;
v_11232:
    goto v_11233;
v_11234:
    goto v_11235;
v_11236:
    v_11243 = CC_mv2sf1(elt(env, 0), 3, v_11245, v_11244, v_11243);
    env = stack[-4];
    goto v_11218;
v_11219:
    goto v_11215;
v_11216:
    goto v_11217;
v_11218:
    v_11243 = cons(stack[-3], v_11243);
    return ncons(v_11243);
    v_11243 = nil;
v_11189:
    return onevalue(v_11243);
}



// Code for setk0

static LispObject CC_setk0(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11349, v_11350, v_11351, v_11352;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11185;
    stack[-2] = v_11184;
// end of prologue
// Binding frasc!*
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 1, 0);
    qvalue(elt(env, 1)) = nil; // frasc!*
    v_11349 = stack[-1];
    fn = elt(env, 6); // getrtype
    v_11349 = (*qfn1(fn))(fn, v_11349);
    env = stack[-4];
    stack[-3] = v_11349;
    if (v_11349 == nil) goto v_11194;
    goto v_11204;
v_11200:
    v_11350 = stack[-3];
    goto v_11201;
v_11202:
    v_11349 = elt(env, 2); // setelemfn
    goto v_11203;
v_11204:
    goto v_11200;
v_11201:
    goto v_11202;
v_11203:
    v_11349 = get(v_11350, v_11349);
    env = stack[-4];
    if (v_11349 == nil) goto v_11194;
    v_11349 = nil;
    v_11349 = ncons(v_11349);
    env = stack[-4];
    qvalue(elt(env, 3)) = v_11349; // alglist!*
    goto v_11218;
v_11210:
    v_11352 = stack[-2];
    goto v_11211;
v_11212:
    v_11351 = stack[-1];
    goto v_11213;
v_11214:
    v_11350 = nil;
    goto v_11215;
v_11216:
    v_11349 = lisp_true;
    goto v_11217;
v_11218:
    goto v_11210;
v_11211:
    goto v_11212;
v_11213:
    goto v_11214;
v_11215:
    goto v_11216;
v_11217:
    fn = elt(env, 7); // let2
    v_11349 = (*qfnn(fn))(fn, 4, v_11352, v_11351, v_11350, v_11349);
    goto v_11192;
v_11194:
    v_11349 = stack[-2];
    if (!consp(v_11349)) goto v_11228;
    v_11349 = stack[-2];
    v_11349 = qcar(v_11349);
    if (symbolp(v_11349)) goto v_11233;
    v_11349 = nil;
    goto v_11231;
v_11233:
    v_11349 = stack[-2];
    fn = elt(env, 6); // getrtype
    v_11349 = (*qfn1(fn))(fn, v_11349);
    env = stack[-4];
    if (v_11349 == nil) goto v_11248;
    else goto v_11247;
v_11248:
    v_11349 = stack[-2];
    v_11349 = qcar(v_11349);
    if (!symbolp(v_11349)) v_11349 = nil;
    else { v_11349 = qfastgets(v_11349);
           if (v_11349 != nil) { v_11349 = elt(v_11349, 2); // rtype
#ifdef RECORD_GET
             if (v_11349 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_11349 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_11349 == SPID_NOPROP) v_11349 = nil; }}
#endif
v_11247:
    stack[-3] = v_11349;
    if (v_11349 == nil) goto v_11244;
    else goto v_11245;
v_11244:
    v_11349 = nil;
    goto v_11243;
v_11245:
    goto v_11262;
v_11258:
    v_11350 = stack[-3];
    goto v_11259;
v_11260:
    v_11349 = elt(env, 2); // setelemfn
    goto v_11261;
v_11262:
    goto v_11258;
v_11259:
    goto v_11260;
v_11261:
    v_11349 = get(v_11350, v_11349);
    env = stack[-4];
    stack[-3] = v_11349;
    goto v_11243;
    v_11349 = nil;
v_11243:
    if (v_11349 == nil) goto v_11241;
    else goto v_11240;
v_11241:
    goto v_11270;
v_11266:
    v_11349 = stack[-2];
    v_11350 = qcar(v_11349);
    goto v_11267;
v_11268:
    v_11349 = elt(env, 4); // setkfn
    goto v_11269;
v_11270:
    goto v_11266;
v_11267:
    goto v_11268;
v_11269:
    v_11349 = get(v_11350, v_11349);
    env = stack[-4];
    stack[-3] = v_11349;
v_11240:
    goto v_11231;
    v_11349 = nil;
v_11231:
    goto v_11226;
v_11228:
    v_11349 = nil;
    goto v_11226;
    v_11349 = nil;
v_11226:
    if (v_11349 == nil) goto v_11224;
    v_11349 = nil;
    v_11349 = ncons(v_11349);
    env = stack[-4];
    qvalue(elt(env, 3)) = v_11349; // alglist!*
    goto v_11286;
v_11280:
    v_11351 = stack[-3];
    goto v_11281;
v_11282:
    v_11350 = stack[-2];
    goto v_11283;
v_11284:
    v_11349 = stack[-1];
    goto v_11285;
v_11286:
    goto v_11280;
v_11281:
    goto v_11282;
v_11283:
    goto v_11284;
v_11285:
    v_11349 = Lapply2(nil, 3, v_11351, v_11350, v_11349);
    goto v_11192;
v_11224:
    v_11349 = stack[-2];
    if (!consp(v_11349)) goto v_11295;
    v_11349 = stack[-2];
    v_11349 = qcar(v_11349);
    if (!consp(v_11349)) goto v_11300;
    goto v_11308;
v_11304:
    v_11349 = stack[-2];
    v_11349 = qcar(v_11349);
    v_11350 = qcar(v_11349);
    goto v_11305;
v_11306:
    v_11349 = elt(env, 5); // setstructfn
    goto v_11307;
v_11308:
    goto v_11304;
v_11305:
    goto v_11306;
v_11307:
    v_11349 = get(v_11350, v_11349);
    env = stack[-4];
    stack[-3] = v_11349;
    goto v_11298;
v_11300:
    v_11349 = nil;
    goto v_11298;
    v_11349 = nil;
v_11298:
    goto v_11293;
v_11295:
    v_11349 = nil;
    goto v_11293;
    v_11349 = nil;
v_11293:
    if (v_11349 == nil) goto v_11291;
    v_11349 = nil;
    v_11349 = ncons(v_11349);
    env = stack[-4];
    qvalue(elt(env, 3)) = v_11349; // alglist!*
    goto v_11328;
v_11322:
    v_11351 = stack[-3];
    goto v_11323;
v_11324:
    v_11350 = stack[-2];
    goto v_11325;
v_11326:
    v_11349 = stack[-1];
    goto v_11327;
v_11328:
    goto v_11322;
v_11323:
    goto v_11324;
v_11325:
    goto v_11326;
v_11327:
    v_11349 = Lapply2(nil, 3, v_11351, v_11350, v_11349);
    goto v_11192;
v_11291:
    goto v_11343;
v_11335:
    v_11352 = stack[-2];
    goto v_11336;
v_11337:
    v_11351 = stack[-1];
    goto v_11338;
v_11339:
    v_11350 = nil;
    goto v_11340;
v_11341:
    v_11349 = lisp_true;
    goto v_11342;
v_11343:
    goto v_11335;
v_11336:
    goto v_11337;
v_11338:
    goto v_11339;
v_11340:
    goto v_11341;
v_11342:
    fn = elt(env, 7); // let2
    v_11349 = (*qfnn(fn))(fn, 4, v_11352, v_11351, v_11350, v_11349);
    goto v_11192;
v_11192:
    v_11349 = stack[-1];
    ;}  // end of a binding scope
    return onevalue(v_11349);
}



// Code for next!-random!-number

static LispObject CC_nextKrandomKnumber(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11267, v_11268, v_11269, v_11270;
    argcheck(nargs, 0, "next-random-number");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    goto v_11196;
v_11192:
    v_11268 = qvalue(elt(env, 1)); // unidev_next!*
    goto v_11193;
v_11194:
    v_11267 = (LispObject)864+TAG_FIXNUM; // 54
    goto v_11195;
v_11196:
    goto v_11192;
v_11193:
    goto v_11194;
v_11195:
    if (v_11268 == v_11267) goto v_11190;
    else goto v_11191;
v_11190:
    v_11267 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_11267; // unidev_next!*
    goto v_11189;
v_11191:
    v_11267 = qvalue(elt(env, 1)); // unidev_next!*
    v_11267 = (LispObject)((intptr_t)(v_11267) + 0x10);
    qvalue(elt(env, 1)) = v_11267; // unidev_next!*
    goto v_11189;
v_11189:
    goto v_11212;
v_11208:
    v_11268 = qvalue(elt(env, 2)); // unidev_nextp!*
    goto v_11209;
v_11210:
    v_11267 = (LispObject)864+TAG_FIXNUM; // 54
    goto v_11211;
v_11212:
    goto v_11208;
v_11209:
    goto v_11210;
v_11211:
    if (v_11268 == v_11267) goto v_11206;
    else goto v_11207;
v_11206:
    v_11267 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 2)) = v_11267; // unidev_nextp!*
    goto v_11205;
v_11207:
    v_11267 = qvalue(elt(env, 2)); // unidev_nextp!*
    v_11267 = (LispObject)((intptr_t)(v_11267) + 0x10);
    qvalue(elt(env, 2)) = v_11267; // unidev_nextp!*
    goto v_11205;
v_11205:
    goto v_11224;
v_11220:
    goto v_11229;
v_11225:
    v_11268 = qvalue(elt(env, 3)); // unidev_vec!*
    goto v_11226;
v_11227:
    v_11267 = qvalue(elt(env, 1)); // unidev_next!*
    goto v_11228;
v_11229:
    goto v_11225;
v_11226:
    goto v_11227;
v_11228:
    v_11269 = *(LispObject *)((char *)v_11268 + (CELL-TAG_VECTOR) + (((intptr_t)v_11267-TAG_FIXNUM)/(16/CELL)));
    goto v_11221;
v_11222:
    goto v_11237;
v_11233:
    v_11268 = qvalue(elt(env, 3)); // unidev_vec!*
    goto v_11234;
v_11235:
    v_11267 = qvalue(elt(env, 2)); // unidev_nextp!*
    goto v_11236;
v_11237:
    goto v_11233;
v_11234:
    goto v_11235;
v_11236:
    v_11267 = *(LispObject *)((char *)v_11268 + (CELL-TAG_VECTOR) + (((intptr_t)v_11267-TAG_FIXNUM)/(16/CELL)));
    goto v_11223;
v_11224:
    goto v_11220;
v_11221:
    goto v_11222;
v_11223:
    v_11267 = (LispObject)(intptr_t)((intptr_t)v_11269 - (intptr_t)v_11267 + TAG_FIXNUM);
    v_11269 = v_11267;
    v_11267 = v_11269;
    v_11267 = ((intptr_t)(v_11267) < 0 ? lisp_true : nil);
    if (v_11267 == nil) goto v_11245;
    goto v_11252;
v_11248:
    v_11268 = v_11269;
    goto v_11249;
v_11250:
    v_11267 = qvalue(elt(env, 4)); // randommodulus!*
    goto v_11251;
v_11252:
    goto v_11248;
v_11249:
    goto v_11250;
v_11251:
    v_11267 = (LispObject)(intptr_t)((intptr_t)v_11268 + (intptr_t)v_11267 - TAG_FIXNUM);
    v_11269 = v_11267;
    goto v_11243;
v_11245:
v_11243:
    goto v_11262;
v_11256:
    v_11268 = qvalue(elt(env, 3)); // unidev_vec!*
    goto v_11257;
v_11258:
    v_11270 = qvalue(elt(env, 1)); // unidev_next!*
    goto v_11259;
v_11260:
    v_11267 = v_11269;
    goto v_11261;
v_11262:
    goto v_11256;
v_11257:
    goto v_11258;
v_11259:
    goto v_11260;
v_11261:
    *(LispObject *)((char *)v_11268 + (CELL-TAG_VECTOR) + (((intptr_t)v_11270-TAG_FIXNUM)/(16/CELL))) = v_11267;
    v_11267 = v_11269;
    return onevalue(v_11267);
}



// Code for print_with_margin_sub

static LispObject CC_print_with_margin_sub(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11552, v_11553, v_11554, v_11555;
    LispObject fn;
    LispObject v_11187, v_11186, v_11185, v_11184;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "print_with_margin_sub");
    va_start(aa, nargs);
    v_11184 = va_arg(aa, LispObject);
    v_11185 = va_arg(aa, LispObject);
    v_11186 = va_arg(aa, LispObject);
    v_11187 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_11187,v_11186,v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_11184,v_11185,v_11186,v_11187);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_11187;
    stack[-2] = v_11186;
    stack[-3] = v_11185;
    stack[-4] = v_11184;
// end of prologue
    goto v_11202;
v_11198:
    v_11553 = stack[-2];
    goto v_11199;
v_11200:
    v_11552 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_11201;
v_11202:
    goto v_11198;
v_11199:
    goto v_11200;
v_11201:
    v_11552 = (LispObject)lessp2(v_11553, v_11552);
    v_11552 = v_11552 ? lisp_true : nil;
    env = stack[-6];
    if (v_11552 == nil) goto v_11196;
    v_11552 = (LispObject)160+TAG_FIXNUM; // 10
    stack[-2] = v_11552;
    goto v_11194;
v_11196:
v_11194:
    goto v_11215;
v_11211:
    stack[0] = stack[-3];
    goto v_11212;
v_11213:
    goto v_11222;
v_11218:
    v_11553 = stack[-2];
    goto v_11219;
v_11220:
    v_11552 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_11221;
v_11222:
    goto v_11218;
v_11219:
    goto v_11220;
v_11221:
    v_11552 = difference2(v_11553, v_11552);
    env = stack[-6];
    goto v_11214;
v_11215:
    goto v_11211;
v_11212:
    goto v_11213;
v_11214:
    v_11552 = (LispObject)greaterp2(stack[0], v_11552);
    v_11552 = v_11552 ? lisp_true : nil;
    env = stack[-6];
    if (v_11552 == nil) goto v_11209;
    goto v_11230;
v_11226:
    v_11553 = stack[-2];
    goto v_11227;
v_11228:
    v_11552 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_11229;
v_11230:
    goto v_11226;
v_11227:
    goto v_11228;
v_11229:
    v_11552 = difference2(v_11553, v_11552);
    env = stack[-6];
    stack[-3] = v_11552;
    goto v_11207;
v_11209:
v_11207:
    v_11552 = stack[-4];
    stack[-5] = v_11552;
    v_11552 = stack[-5];
    if (!consp(v_11552)) goto v_11237;
    goto v_11248;
v_11244:
    v_11553 = Lposn(nil, 0);
    env = stack[-6];
    goto v_11245;
v_11246:
    v_11552 = stack[-2];
    goto v_11247;
v_11248:
    goto v_11244;
v_11245:
    goto v_11246;
v_11247:
    v_11552 = (LispObject)geq2(v_11553, v_11552);
    v_11552 = v_11552 ? lisp_true : nil;
    env = stack[-6];
    if (v_11552 == nil) goto v_11242;
    v_11552 = Lterpri(nil, 0);
    env = stack[-6];
    v_11552 = stack[-3];
    v_11552 = Lttab(nil, v_11552);
    env = stack[-6];
    goto v_11240;
v_11242:
v_11240:
    v_11552 = elt(env, 1); // "("
    v_11552 = Lprinc(nil, v_11552);
    env = stack[-6];
    goto v_11265;
v_11257:
    v_11552 = stack[-5];
    v_11555 = qcar(v_11552);
    goto v_11258;
v_11259:
    v_11554 = stack[-3];
    goto v_11260;
v_11261:
    v_11553 = stack[-2];
    goto v_11262;
v_11263:
    v_11552 = stack[-1];
    goto v_11264;
v_11265:
    goto v_11257;
v_11258:
    goto v_11259;
v_11260:
    goto v_11261;
v_11262:
    goto v_11263;
v_11264:
    v_11552 = CC_print_with_margin_sub(elt(env, 0), 4, v_11555, v_11554, v_11553, v_11552);
    env = stack[-6];
v_11273:
    v_11552 = stack[-5];
    v_11552 = qcdr(v_11552);
    stack[-5] = v_11552;
    if (!consp(v_11552)) goto v_11276;
    else goto v_11277;
v_11276:
    goto v_11272;
v_11277:
    goto v_11290;
v_11286:
    v_11553 = Lposn(nil, 0);
    env = stack[-6];
    goto v_11287;
v_11288:
    v_11552 = stack[-2];
    goto v_11289;
v_11290:
    goto v_11286;
v_11287:
    goto v_11288;
v_11289:
    v_11552 = (LispObject)geq2(v_11553, v_11552);
    v_11552 = v_11552 ? lisp_true : nil;
    env = stack[-6];
    if (v_11552 == nil) goto v_11284;
    v_11552 = Lterpri(nil, 0);
    env = stack[-6];
    v_11552 = stack[-3];
    v_11552 = Lttab(nil, v_11552);
    env = stack[-6];
    goto v_11282;
v_11284:
    v_11552 = elt(env, 2); // " "
    v_11552 = Lprinc(nil, v_11552);
    env = stack[-6];
    goto v_11282;
v_11282:
    goto v_11309;
v_11301:
    v_11552 = stack[-5];
    v_11555 = qcar(v_11552);
    goto v_11302;
v_11303:
    v_11554 = stack[-3];
    goto v_11304;
v_11305:
    v_11553 = stack[-2];
    goto v_11306;
v_11307:
    v_11552 = stack[-1];
    goto v_11308;
v_11309:
    goto v_11301;
v_11302:
    goto v_11303;
v_11304:
    goto v_11305;
v_11306:
    goto v_11307;
v_11308:
    v_11552 = CC_print_with_margin_sub(elt(env, 0), 4, v_11555, v_11554, v_11553, v_11552);
    env = stack[-6];
    goto v_11273;
v_11272:
    v_11552 = stack[-5];
    if (v_11552 == nil) goto v_11318;
    goto v_11329;
v_11325:
    stack[0] = Lposn(nil, 0);
    env = stack[-6];
    goto v_11326;
v_11327:
    v_11552 = stack[-2];
    v_11552 = sub1(v_11552);
    env = stack[-6];
    goto v_11328;
v_11329:
    goto v_11325;
v_11326:
    goto v_11327;
v_11328:
    v_11552 = (LispObject)geq2(stack[0], v_11552);
    v_11552 = v_11552 ? lisp_true : nil;
    env = stack[-6];
    if (v_11552 == nil) goto v_11323;
    v_11552 = Lterpri(nil, 0);
    env = stack[-6];
    v_11552 = stack[-3];
    v_11552 = Lttab(nil, v_11552);
    env = stack[-6];
    v_11552 = elt(env, 3); // ". "
    v_11552 = Lprinc(nil, v_11552);
    env = stack[-6];
    goto v_11321;
v_11323:
    v_11552 = elt(env, 4); // " ."
    v_11552 = Lprinc(nil, v_11552);
    env = stack[-6];
    goto v_11321;
v_11321:
    goto v_11351;
v_11343:
    v_11555 = stack[-5];
    goto v_11344;
v_11345:
    v_11554 = stack[-3];
    goto v_11346;
v_11347:
    v_11553 = stack[-2];
    goto v_11348;
v_11349:
    v_11552 = stack[-1];
    goto v_11350;
v_11351:
    goto v_11343;
v_11344:
    goto v_11345;
v_11346:
    goto v_11347;
v_11348:
    goto v_11349;
v_11350:
    v_11552 = CC_print_with_margin_sub(elt(env, 0), 4, v_11555, v_11554, v_11553, v_11552);
    env = stack[-6];
    goto v_11316;
v_11318:
v_11316:
    goto v_11365;
v_11361:
    v_11553 = Lposn(nil, 0);
    env = stack[-6];
    goto v_11362;
v_11363:
    v_11552 = stack[-2];
    goto v_11364;
v_11365:
    goto v_11361;
v_11362:
    goto v_11363;
v_11364:
    v_11552 = (LispObject)geq2(v_11553, v_11552);
    v_11552 = v_11552 ? lisp_true : nil;
    env = stack[-6];
    if (v_11552 == nil) goto v_11359;
    v_11552 = Lterpri(nil, 0);
    env = stack[-6];
    v_11552 = stack[-3];
    v_11552 = Lttab(nil, v_11552);
    env = stack[-6];
    goto v_11357;
v_11359:
v_11357:
    v_11552 = elt(env, 5); // ")"
    v_11552 = Lprinc(nil, v_11552);
    v_11552 = stack[-4];
    goto v_11191;
v_11237:
    goto v_11379;
v_11375:
    stack[0] = stack[-1];
    goto v_11376;
v_11377:
    v_11552 = stack[-4];
    v_11552 = ncons(v_11552);
    env = stack[-6];
    goto v_11378;
v_11379:
    goto v_11375;
v_11376:
    goto v_11377;
v_11378:
    fn = elt(env, 7); // apply
    v_11552 = (*qfn2(fn))(fn, stack[0], v_11552);
    env = stack[-6];
    stack[-5] = v_11552;
v_11192:
    goto v_11392;
v_11388:
    goto v_11398;
v_11394:
    stack[0] = Lposn(nil, 0);
    env = stack[-6];
    goto v_11395;
v_11396:
    v_11552 = stack[-5];
    v_11552 = Llength(nil, v_11552);
    env = stack[-6];
    goto v_11397;
v_11398:
    goto v_11394;
v_11395:
    goto v_11396;
v_11397:
    v_11553 = plus2(stack[0], v_11552);
    env = stack[-6];
    goto v_11389;
v_11390:
    v_11552 = stack[-2];
    goto v_11391;
v_11392:
    goto v_11388;
v_11389:
    goto v_11390;
v_11391:
    v_11552 = (LispObject)lessp2(v_11553, v_11552);
    v_11552 = v_11552 ? lisp_true : nil;
    env = stack[-6];
    if (v_11552 == nil) goto v_11386;
    v_11552 = stack[-5];
    stack[0] = v_11552;
v_11406:
    v_11552 = stack[0];
    if (v_11552 == nil) goto v_11410;
    else goto v_11411;
v_11410:
    goto v_11405;
v_11411:
    v_11552 = stack[0];
    v_11552 = qcar(v_11552);
    v_11552 = Lprinc(nil, v_11552);
    env = stack[-6];
    v_11552 = stack[0];
    v_11552 = qcdr(v_11552);
    stack[0] = v_11552;
    goto v_11406;
v_11405:
    v_11552 = stack[-4];
    goto v_11191;
v_11386:
    goto v_11429;
v_11425:
    v_11552 = stack[-5];
    stack[0] = Llength(nil, v_11552);
    env = stack[-6];
    goto v_11426;
v_11427:
    goto v_11437;
v_11433:
    v_11553 = stack[-2];
    goto v_11434;
v_11435:
    v_11552 = stack[-3];
    goto v_11436;
v_11437:
    goto v_11433;
v_11434:
    goto v_11435;
v_11436:
    v_11552 = difference2(v_11553, v_11552);
    env = stack[-6];
    goto v_11428;
v_11429:
    goto v_11425;
v_11426:
    goto v_11427;
v_11428:
    v_11552 = (LispObject)lesseq2(stack[0], v_11552);
    v_11552 = v_11552 ? lisp_true : nil;
    env = stack[-6];
    if (v_11552 == nil) goto v_11423;
    v_11552 = Lterpri(nil, 0);
    env = stack[-6];
    v_11552 = stack[-3];
    v_11552 = Lttab(nil, v_11552);
    env = stack[-6];
    v_11552 = stack[-5];
    stack[0] = v_11552;
v_11446:
    v_11552 = stack[0];
    if (v_11552 == nil) goto v_11450;
    else goto v_11451;
v_11450:
    goto v_11445;
v_11451:
    v_11552 = stack[0];
    v_11552 = qcar(v_11552);
    v_11552 = Lprinc(nil, v_11552);
    env = stack[-6];
    v_11552 = stack[0];
    v_11552 = qcdr(v_11552);
    stack[0] = v_11552;
    goto v_11446;
v_11445:
    v_11552 = stack[-4];
    goto v_11191;
v_11423:
    goto v_11469;
v_11465:
    v_11552 = stack[-5];
    v_11553 = Llength(nil, v_11552);
    env = stack[-6];
    goto v_11466;
v_11467:
    v_11552 = stack[-2];
    goto v_11468;
v_11469:
    goto v_11465;
v_11466:
    goto v_11467;
v_11468:
    v_11552 = (LispObject)lessp2(v_11553, v_11552);
    v_11552 = v_11552 ? lisp_true : nil;
    env = stack[-6];
    if (v_11552 == nil) goto v_11463;
    v_11552 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_11480;
v_11476:
    stack[0] = stack[-2];
    goto v_11477;
v_11478:
    v_11552 = stack[-5];
    v_11552 = Llength(nil, v_11552);
    env = stack[-6];
    goto v_11479;
v_11480:
    goto v_11476;
v_11477:
    goto v_11478;
v_11479:
    v_11552 = difference2(stack[0], v_11552);
    env = stack[-6];
    v_11552 = Lttab(nil, v_11552);
    env = stack[-6];
    v_11552 = stack[-5];
    stack[0] = v_11552;
v_11487:
    v_11552 = stack[0];
    if (v_11552 == nil) goto v_11491;
    else goto v_11492;
v_11491:
    goto v_11486;
v_11492:
    v_11552 = stack[0];
    v_11552 = qcar(v_11552);
    v_11552 = Lprinc(nil, v_11552);
    env = stack[-6];
    v_11552 = stack[0];
    v_11552 = qcdr(v_11552);
    stack[0] = v_11552;
    goto v_11487;
v_11486:
    v_11552 = stack[-4];
    goto v_11191;
v_11463:
    goto v_11514;
v_11510:
    stack[0] = Lposn(nil, 0);
    env = stack[-6];
    goto v_11511;
v_11512:
    goto v_11521;
v_11517:
    v_11553 = stack[-2];
    goto v_11518;
v_11519:
    v_11552 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_11520;
v_11521:
    goto v_11517;
v_11518:
    goto v_11519;
v_11520:
    v_11552 = difference2(v_11553, v_11552);
    env = stack[-6];
    goto v_11513;
v_11514:
    goto v_11510;
v_11511:
    goto v_11512;
v_11513:
    v_11552 = (LispObject)geq2(stack[0], v_11552);
    v_11552 = v_11552 ? lisp_true : nil;
    env = stack[-6];
    if (v_11552 == nil) goto v_11508;
    v_11552 = Lterpri(nil, 0);
    env = stack[-6];
    v_11552 = stack[-3];
    v_11552 = Lttab(nil, v_11552);
    env = stack[-6];
    goto v_11506;
v_11508:
v_11506:
v_11529:
    goto v_11539;
v_11535:
    stack[0] = Lposn(nil, 0);
    env = stack[-6];
    goto v_11536;
v_11537:
    v_11552 = stack[-2];
    v_11552 = sub1(v_11552);
    env = stack[-6];
    goto v_11538;
v_11539:
    goto v_11535;
v_11536:
    goto v_11537;
v_11538:
    v_11552 = (LispObject)lessp2(stack[0], v_11552);
    v_11552 = v_11552 ? lisp_true : nil;
    env = stack[-6];
    if (v_11552 == nil) goto v_11532;
    else goto v_11533;
v_11532:
    goto v_11528;
v_11533:
    v_11552 = stack[-5];
    v_11552 = qcar(v_11552);
    v_11552 = Lprinc(nil, v_11552);
    env = stack[-6];
    v_11552 = stack[-5];
    v_11552 = qcdr(v_11552);
    stack[-5] = v_11552;
    goto v_11529;
v_11528:
    v_11552 = elt(env, 6); // "\"
    v_11552 = Lprinc(nil, v_11552);
    env = stack[-6];
    v_11552 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_11192;
    v_11552 = nil;
v_11191:
    return onevalue(v_11552);
}



// Code for cl_nnf

static LispObject CC_cl_nnf(LispObject env,
                         LispObject v_11184)
{
    env = qenv(env);
    LispObject v_11194, v_11195;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11194 = v_11184;
// end of prologue
    goto v_11191;
v_11187:
    v_11195 = v_11194;
    goto v_11188;
v_11189:
    v_11194 = lisp_true;
    goto v_11190;
v_11191:
    goto v_11187;
v_11188:
    goto v_11189;
v_11190:
    {
        fn = elt(env, 1); // cl_nnf1
        return (*qfn2(fn))(fn, v_11195, v_11194);
    }
}



// Code for subsublis

static LispObject CC_subsublis(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11411, v_11412, v_11413;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_11185;
    stack[-3] = v_11184;
// end of prologue
v_11183:
    goto v_11198;
v_11194:
    v_11412 = stack[0];
    goto v_11195;
v_11196:
    v_11411 = stack[-3];
    goto v_11197;
v_11198:
    goto v_11194;
v_11195:
    goto v_11196;
v_11197:
    v_11411 = Lassoc(nil, v_11412, v_11411);
    v_11413 = v_11411;
    if (v_11411 == nil) goto v_11193;
    v_11411 = v_11413;
    v_11411 = qcdr(v_11411);
    goto v_11191;
v_11193:
    goto v_11215;
v_11211:
    v_11412 = stack[0];
    goto v_11212;
v_11213:
    v_11411 = elt(env, 1); // sqrt
    goto v_11214;
v_11215:
    goto v_11211;
v_11212:
    goto v_11213;
v_11214:
    if (!consp(v_11412)) goto v_11209;
    v_11412 = qcar(v_11412);
    if (v_11412 == v_11411) goto v_11208;
    else goto v_11209;
v_11208:
    goto v_11222;
v_11218:
    goto v_11230;
v_11224:
    v_11413 = elt(env, 2); // expt
    goto v_11225;
v_11226:
    v_11411 = stack[0];
    v_11411 = qcdr(v_11411);
    v_11412 = qcar(v_11411);
    goto v_11227;
v_11228:
    v_11411 = elt(env, 3); // (quotient 1 2)
    goto v_11229;
v_11230:
    goto v_11224;
v_11225:
    goto v_11226;
v_11227:
    goto v_11228;
v_11229:
    v_11412 = list3(v_11413, v_11412, v_11411);
    env = stack[-5];
    goto v_11219;
v_11220:
    v_11411 = stack[-3];
    goto v_11221;
v_11222:
    goto v_11218;
v_11219:
    goto v_11220;
v_11221:
    v_11411 = Lassoc(nil, v_11412, v_11411);
    v_11413 = v_11411;
    goto v_11207;
v_11209:
    v_11411 = nil;
    goto v_11207;
    v_11411 = nil;
v_11207:
    if (v_11411 == nil) goto v_11205;
    v_11411 = v_11413;
    v_11411 = qcdr(v_11411);
    goto v_11191;
v_11205:
    v_11411 = stack[0];
    if (!consp(v_11411)) goto v_11243;
    else goto v_11244;
v_11243:
    v_11411 = stack[0];
    goto v_11191;
v_11244:
    v_11411 = stack[0];
    v_11411 = qcar(v_11411);
    if (symbolp(v_11411)) goto v_11248;
    v_11411 = stack[0];
    stack[-4] = v_11411;
    v_11411 = stack[-4];
    if (v_11411 == nil) goto v_11260;
    else goto v_11261;
v_11260:
    v_11411 = nil;
    goto v_11255;
v_11261:
    v_11411 = stack[-4];
    v_11411 = qcar(v_11411);
    goto v_11273;
v_11269:
    v_11412 = stack[-3];
    goto v_11270;
v_11271:
    goto v_11272;
v_11273:
    goto v_11269;
v_11270:
    goto v_11271;
v_11272:
    v_11411 = CC_subsublis(elt(env, 0), v_11412, v_11411);
    env = stack[-5];
    v_11411 = ncons(v_11411);
    env = stack[-5];
    stack[-1] = v_11411;
    stack[-2] = v_11411;
v_11256:
    v_11411 = stack[-4];
    v_11411 = qcdr(v_11411);
    stack[-4] = v_11411;
    v_11411 = stack[-4];
    if (v_11411 == nil) goto v_11280;
    else goto v_11281;
v_11280:
    v_11411 = stack[-2];
    goto v_11255;
v_11281:
    goto v_11289;
v_11285:
    stack[0] = stack[-1];
    goto v_11286;
v_11287:
    v_11411 = stack[-4];
    v_11411 = qcar(v_11411);
    goto v_11300;
v_11296:
    v_11412 = stack[-3];
    goto v_11297;
v_11298:
    goto v_11299;
v_11300:
    goto v_11296;
v_11297:
    goto v_11298;
v_11299:
    v_11411 = CC_subsublis(elt(env, 0), v_11412, v_11411);
    env = stack[-5];
    v_11411 = ncons(v_11411);
    env = stack[-5];
    goto v_11288;
v_11289:
    goto v_11285;
v_11286:
    goto v_11287;
v_11288:
    v_11411 = Lrplacd(nil, stack[0], v_11411);
    env = stack[-5];
    v_11411 = stack[-1];
    v_11411 = qcdr(v_11411);
    stack[-1] = v_11411;
    goto v_11256;
v_11255:
    goto v_11191;
v_11248:
    goto v_11312;
v_11308:
    v_11411 = stack[0];
    v_11412 = qcar(v_11411);
    goto v_11309;
v_11310:
    v_11411 = elt(env, 4); // subfunc
    goto v_11311;
v_11312:
    goto v_11308;
v_11309:
    goto v_11310;
v_11311:
    v_11411 = get(v_11412, v_11411);
    env = stack[-5];
    v_11413 = v_11411;
    if (v_11411 == nil) goto v_11306;
    goto v_11323;
v_11317:
    goto v_11318;
v_11319:
    v_11412 = stack[-3];
    goto v_11320;
v_11321:
    v_11411 = stack[0];
    goto v_11322;
v_11323:
    goto v_11317;
v_11318:
    goto v_11319;
v_11320:
    goto v_11321;
v_11322:
        return Lapply2(nil, 3, v_11413, v_11412, v_11411);
v_11306:
    v_11411 = stack[0];
    v_11411 = qcar(v_11411);
    if (!symbolp(v_11411)) v_11411 = nil;
    else { v_11411 = qfastgets(v_11411);
           if (v_11411 != nil) { v_11411 = elt(v_11411, 8); // dname
#ifdef RECORD_GET
             if (v_11411 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_11411 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_11411 == SPID_NOPROP) v_11411 = nil; }}
#endif
    if (v_11411 == nil) goto v_11328;
    v_11411 = stack[0];
    goto v_11191;
v_11328:
    goto v_11339;
v_11335:
    v_11411 = stack[0];
    v_11412 = qcar(v_11411);
    goto v_11336;
v_11337:
    v_11411 = elt(env, 5); // !*sq
    goto v_11338;
v_11339:
    goto v_11335;
v_11336:
    goto v_11337;
v_11338:
    if (v_11412 == v_11411) goto v_11333;
    else goto v_11334;
v_11333:
    goto v_11348;
v_11344:
    stack[-1] = stack[-3];
    goto v_11345;
v_11346:
    v_11411 = stack[0];
    v_11411 = qcdr(v_11411);
    v_11411 = qcar(v_11411);
    fn = elt(env, 6); // prepsq
    v_11411 = (*qfn1(fn))(fn, v_11411);
    env = stack[-5];
    goto v_11347;
v_11348:
    goto v_11344;
v_11345:
    goto v_11346;
v_11347:
    stack[-3] = stack[-1];
    stack[0] = v_11411;
    goto v_11183;
v_11334:
    v_11411 = stack[0];
    stack[-4] = v_11411;
    v_11411 = stack[-4];
    if (v_11411 == nil) goto v_11365;
    else goto v_11366;
v_11365:
    v_11411 = nil;
    goto v_11360;
v_11366:
    v_11411 = stack[-4];
    v_11411 = qcar(v_11411);
    goto v_11378;
v_11374:
    v_11412 = stack[-3];
    goto v_11375;
v_11376:
    goto v_11377;
v_11378:
    goto v_11374;
v_11375:
    goto v_11376;
v_11377:
    v_11411 = CC_subsublis(elt(env, 0), v_11412, v_11411);
    env = stack[-5];
    v_11411 = ncons(v_11411);
    env = stack[-5];
    stack[-1] = v_11411;
    stack[-2] = v_11411;
v_11361:
    v_11411 = stack[-4];
    v_11411 = qcdr(v_11411);
    stack[-4] = v_11411;
    v_11411 = stack[-4];
    if (v_11411 == nil) goto v_11385;
    else goto v_11386;
v_11385:
    v_11411 = stack[-2];
    goto v_11360;
v_11386:
    goto v_11394;
v_11390:
    stack[0] = stack[-1];
    goto v_11391;
v_11392:
    v_11411 = stack[-4];
    v_11411 = qcar(v_11411);
    goto v_11405;
v_11401:
    v_11412 = stack[-3];
    goto v_11402;
v_11403:
    goto v_11404;
v_11405:
    goto v_11401;
v_11402:
    goto v_11403;
v_11404:
    v_11411 = CC_subsublis(elt(env, 0), v_11412, v_11411);
    env = stack[-5];
    v_11411 = ncons(v_11411);
    env = stack[-5];
    goto v_11393;
v_11394:
    goto v_11390;
v_11391:
    goto v_11392;
v_11393:
    v_11411 = Lrplacd(nil, stack[0], v_11411);
    env = stack[-5];
    v_11411 = stack[-1];
    v_11411 = qcdr(v_11411);
    stack[-1] = v_11411;
    goto v_11361;
v_11360:
    goto v_11191;
    v_11411 = nil;
v_11191:
    v_11413 = v_11411;
    v_11411 = v_11413;
    return onevalue(v_11411);
}



// Code for token!-number

static LispObject CC_tokenKnumber(LispObject env,
                         LispObject v_11184)
{
    env = qenv(env);
    LispObject v_11578, v_11579, v_11580;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11184);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_11184;
// end of prologue
    stack[-10] = nil;
    stack[-7] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    v_11578 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-8] = v_11578;
    v_11578 = (LispObject)32+TAG_FIXNUM; // 2
    qvalue(elt(env, 1)) = v_11578; // ttype!*
v_11193:
    v_11578 = stack[-6];
    if (v_11578 == nil) goto v_11207;
    else goto v_11205;
v_11207:
    goto v_11214;
v_11210:
    v_11579 = stack[-9];
    goto v_11211;
v_11212:
    v_11578 = elt(env, 2); // !)
    goto v_11213;
v_11214:
    goto v_11210;
v_11211:
    goto v_11212;
v_11213:
    if (v_11579 == v_11578) goto v_11209;
    else goto v_11205;
v_11209:
    goto v_11206;
v_11205:
    goto v_11222;
v_11218:
    v_11579 = stack[-9];
    goto v_11219;
v_11220:
    v_11578 = stack[-6];
    goto v_11221;
v_11222:
    goto v_11218;
v_11219:
    goto v_11220;
v_11221:
    v_11578 = cons(v_11579, v_11578);
    env = stack[-11];
    stack[-6] = v_11578;
    goto v_11204;
v_11206:
v_11204:
    v_11578 = stack[-10];
    if (v_11578 == nil) goto v_11228;
    v_11578 = stack[-8];
    v_11578 = sub1(v_11578);
    env = stack[-11];
    stack[-8] = v_11578;
    goto v_11226;
v_11228:
v_11226:
v_11194:
    fn = elt(env, 21); // readch1
    v_11578 = (*qfnn(fn))(fn, 0);
    env = stack[-11];
    stack[-9] = v_11578;
    goto v_11245;
v_11241:
    v_11579 = stack[-9];
    goto v_11242;
v_11243:
    v_11578 = qvalue(elt(env, 3)); // !$eof!$
    goto v_11244;
v_11245:
    goto v_11241;
v_11242:
    goto v_11243;
v_11244:
    if (v_11579 == v_11578) goto v_11239;
    else goto v_11240;
v_11239:
    v_11578 = lisp_true;
    goto v_11238;
v_11240:
    goto v_11255;
v_11251:
    v_11578 = stack[-9];
    fn = elt(env, 22); // id2string
    v_11578 = (*qfn1(fn))(fn, v_11578);
    env = stack[-11];
    fn = elt(env, 23); // string!-length
    v_11579 = (*qfn1(fn))(fn, v_11578);
    env = stack[-11];
    goto v_11252;
v_11253:
    v_11578 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11254;
v_11255:
    goto v_11251;
v_11252:
    goto v_11253;
v_11254:
    v_11578 = (v_11579 == v_11578 ? lisp_true : nil);
    v_11578 = (v_11578 == nil ? lisp_true : nil);
    goto v_11238;
    v_11578 = nil;
v_11238:
    if (v_11578 == nil) goto v_11236;
    goto v_11199;
v_11236:
    goto v_11272;
v_11268:
    v_11579 = stack[-9];
    goto v_11269;
v_11270:
    v_11578 = elt(env, 4); // !.
    goto v_11271;
v_11272:
    goto v_11268;
v_11269:
    goto v_11270;
v_11271:
    if (v_11579 == v_11578) goto v_11266;
    else goto v_11267;
v_11266:
    v_11578 = stack[-10];
    v_11578 = (v_11578 == nil ? lisp_true : nil);
    goto v_11265;
v_11267:
    v_11578 = nil;
    goto v_11265;
    v_11578 = nil;
v_11265:
    if (v_11578 == nil) goto v_11263;
    v_11578 = lisp_true;
    stack[-10] = v_11578;
    goto v_11194;
v_11263:
    v_11578 = stack[-9];
    v_11578 = Ldigitp(nil, v_11578);
    env = stack[-11];
    if (v_11578 == nil) goto v_11282;
    goto v_11193;
v_11282:
    goto v_11295;
v_11291:
    v_11579 = stack[-6];
    goto v_11292;
v_11293:
    v_11578 = elt(env, 5); // (!0)
    goto v_11294;
v_11295:
    goto v_11291;
v_11292:
    goto v_11293;
v_11294:
    if (equal(v_11579, v_11578)) goto v_11289;
    else goto v_11290;
v_11289:
    goto v_11306;
v_11302:
    v_11579 = stack[-9];
    goto v_11303;
v_11304:
    v_11578 = elt(env, 6); // x
    goto v_11305;
v_11306:
    goto v_11302;
v_11303:
    goto v_11304;
v_11305:
    if (v_11579 == v_11578) goto v_11300;
    else goto v_11301;
v_11300:
    v_11578 = lisp_true;
    goto v_11299;
v_11301:
    goto v_11316;
v_11312:
    v_11579 = stack[-9];
    goto v_11313;
v_11314:
    v_11578 = elt(env, 7); // !X
    goto v_11315;
v_11316:
    goto v_11312;
v_11313:
    goto v_11314;
v_11315:
    v_11578 = (v_11579 == v_11578 ? lisp_true : nil);
    goto v_11299;
    v_11578 = nil;
v_11299:
    goto v_11288;
v_11290:
    v_11578 = nil;
    goto v_11288;
    v_11578 = nil;
v_11288:
    if (v_11578 == nil) goto v_11286;
    goto v_11196;
v_11286:
    goto v_11329;
v_11325:
    v_11579 = stack[-9];
    goto v_11326;
v_11327:
    v_11578 = elt(env, 8); // !\ (backslash)
    goto v_11328;
v_11329:
    goto v_11325;
v_11326:
    goto v_11327;
v_11328:
    if (v_11579 == v_11578) goto v_11323;
    else goto v_11324;
v_11323:
    fn = elt(env, 21); // readch1
    v_11578 = (*qfnn(fn))(fn, 0);
    env = stack[-11];
    goto v_11194;
v_11324:
    goto v_11343;
v_11339:
    v_11579 = stack[-9];
    goto v_11340;
v_11341:
    v_11578 = elt(env, 9); // e
    goto v_11342;
v_11343:
    goto v_11339;
v_11340:
    goto v_11341;
v_11342:
    if (v_11579 == v_11578) goto v_11337;
    else goto v_11338;
v_11337:
    v_11578 = lisp_true;
    goto v_11336;
v_11338:
    goto v_11353;
v_11349:
    v_11579 = stack[-9];
    goto v_11350;
v_11351:
    v_11578 = elt(env, 10); // !E
    goto v_11352;
v_11353:
    goto v_11349;
v_11350:
    goto v_11351;
v_11352:
    v_11578 = (v_11579 == v_11578 ? lisp_true : nil);
    goto v_11336;
    v_11578 = nil;
v_11336:
    if (v_11578 == nil) goto v_11333;
    else goto v_11334;
v_11333:
    goto v_11199;
v_11334:
    v_11578 = lisp_true;
    stack[-10] = v_11578;
    goto v_11366;
v_11362:
    fn = elt(env, 21); // readch1
    v_11579 = (*qfnn(fn))(fn, 0);
    env = stack[-11];
    stack[-9] = v_11579;
    goto v_11363;
v_11364:
    v_11578 = elt(env, 11); // !-
    goto v_11365;
v_11366:
    goto v_11362;
v_11363:
    goto v_11364;
v_11365:
    if (v_11579 == v_11578) goto v_11360;
    else goto v_11361;
v_11360:
    v_11578 = lisp_true;
    stack[-7] = v_11578;
    goto v_11359;
v_11361:
    goto v_11376;
v_11372:
    v_11579 = stack[-9];
    goto v_11373;
v_11374:
    v_11578 = elt(env, 12); // !+
    goto v_11375;
v_11376:
    goto v_11372;
v_11373:
    goto v_11374;
v_11375:
    if (v_11579 == v_11578) goto v_11370;
    else goto v_11371;
v_11370:
    goto v_11359;
v_11371:
    goto v_11390;
v_11386:
    v_11579 = stack[-9];
    goto v_11387;
v_11388:
    v_11578 = qvalue(elt(env, 3)); // !$eof!$
    goto v_11389;
v_11390:
    goto v_11386;
v_11387:
    goto v_11388;
v_11389:
    if (v_11579 == v_11578) goto v_11384;
    else goto v_11385;
v_11384:
    v_11578 = lisp_true;
    goto v_11383;
v_11385:
    goto v_11400;
v_11396:
    v_11578 = stack[-9];
    fn = elt(env, 22); // id2string
    v_11578 = (*qfn1(fn))(fn, v_11578);
    env = stack[-11];
    fn = elt(env, 23); // string!-length
    v_11579 = (*qfn1(fn))(fn, v_11578);
    env = stack[-11];
    goto v_11397;
v_11398:
    v_11578 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11399;
v_11400:
    goto v_11396;
v_11397:
    goto v_11398;
v_11399:
    v_11578 = (v_11579 == v_11578 ? lisp_true : nil);
    v_11578 = (v_11578 == nil ? lisp_true : nil);
    goto v_11383;
    v_11578 = nil;
v_11383:
    if (v_11578 == nil) goto v_11381;
    goto v_11199;
v_11381:
    v_11578 = stack[-9];
    v_11578 = Ldigitp(nil, v_11578);
    env = stack[-11];
    if (v_11578 == nil) goto v_11407;
    else goto v_11408;
v_11407:
    goto v_11199;
v_11408:
    v_11578 = stack[-9];
    v_11578 = ncons(v_11578);
    env = stack[-11];
    stack[-5] = v_11578;
    goto v_11359;
v_11359:
v_11195:
    fn = elt(env, 21); // readch1
    v_11578 = (*qfnn(fn))(fn, 0);
    env = stack[-11];
    stack[-9] = v_11578;
    goto v_11424;
v_11420:
    v_11578 = stack[-9];
    fn = elt(env, 22); // id2string
    v_11578 = (*qfn1(fn))(fn, v_11578);
    env = stack[-11];
    fn = elt(env, 23); // string!-length
    v_11579 = (*qfn1(fn))(fn, v_11578);
    env = stack[-11];
    goto v_11421;
v_11422:
    v_11578 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11423;
v_11424:
    goto v_11420;
v_11421:
    goto v_11422;
v_11423:
    if (v_11579 == v_11578) goto v_11419;
    goto v_11198;
v_11419:
    v_11578 = stack[-9];
    v_11578 = Ldigitp(nil, v_11578);
    env = stack[-11];
    if (v_11578 == nil) goto v_11429;
    else goto v_11430;
v_11429:
    goto v_11198;
v_11430:
    goto v_11438;
v_11434:
    v_11579 = stack[-9];
    goto v_11435;
v_11436:
    v_11578 = stack[-5];
    goto v_11437;
v_11438:
    goto v_11434;
v_11435:
    goto v_11436;
v_11437:
    v_11578 = cons(v_11579, v_11578);
    env = stack[-11];
    stack[-5] = v_11578;
    goto v_11195;
v_11196:
    v_11578 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_11578;
v_11197:
    goto v_11451;
v_11447:
    fn = elt(env, 21); // readch1
    v_11579 = (*qfnn(fn))(fn, 0);
    env = stack[-11];
    stack[-9] = v_11579;
    goto v_11448;
v_11449:
    v_11578 = elt(env, 13); // hexdigit
    goto v_11450;
v_11451:
    goto v_11447;
v_11448:
    goto v_11449;
v_11450:
    v_11578 = get(v_11579, v_11578);
    env = stack[-11];
    stack[-5] = v_11578;
    if (v_11578 == nil) goto v_11444;
    else goto v_11445;
v_11444:
    goto v_11200;
v_11445:
    goto v_11459;
v_11455:
    goto v_11465;
v_11461:
    v_11579 = (LispObject)256+TAG_FIXNUM; // 16
    goto v_11462;
v_11463:
    v_11578 = stack[-6];
    goto v_11464;
v_11465:
    goto v_11461;
v_11462:
    goto v_11463;
v_11464:
    v_11579 = times2(v_11579, v_11578);
    env = stack[-11];
    goto v_11456;
v_11457:
    v_11578 = stack[-5];
    goto v_11458;
v_11459:
    goto v_11455;
v_11456:
    goto v_11457;
v_11458:
    v_11578 = plus2(v_11579, v_11578);
    env = stack[-11];
    stack[-6] = v_11578;
    goto v_11197;
v_11198:
    v_11578 = stack[-5];
    if (v_11578 == nil) goto v_11471;
    else goto v_11472;
v_11471:
    goto v_11481;
v_11475:
    stack[-4] = elt(env, 14); // rlisp
    goto v_11476;
v_11477:
    stack[-3] = (LispObject)64+TAG_FIXNUM; // 4
    goto v_11478;
v_11479:
    goto v_11489;
v_11485:
    stack[-2] = elt(env, 15); // "Syntax error: improper number "
    goto v_11486;
v_11487:
    goto v_11497;
v_11493:
    stack[-1] = stack[-9];
    goto v_11494;
v_11495:
    goto v_11504;
v_11500:
    stack[0] = stack[-5];
    goto v_11501;
v_11502:
    goto v_11511;
v_11507:
    v_11579 = elt(env, 9); // e
    goto v_11508;
v_11509:
    v_11578 = stack[-6];
    goto v_11510;
v_11511:
    goto v_11507;
v_11508:
    goto v_11509;
v_11510:
    v_11578 = cons(v_11579, v_11578);
    env = stack[-11];
    goto v_11503;
v_11504:
    goto v_11500;
v_11501:
    goto v_11502;
v_11503:
    v_11578 = Lappend(nil, stack[0], v_11578);
    env = stack[-11];
    goto v_11496;
v_11497:
    goto v_11493;
v_11494:
    goto v_11495;
v_11496:
    v_11578 = cons(stack[-1], v_11578);
    env = stack[-11];
    fn = elt(env, 24); // list2string
    v_11578 = (*qfn1(fn))(fn, v_11578);
    env = stack[-11];
    goto v_11488;
v_11489:
    goto v_11485;
v_11486:
    goto v_11487;
v_11488:
    fn = elt(env, 25); // concat
    v_11578 = (*qfn2(fn))(fn, stack[-2], v_11578);
    env = stack[-11];
    goto v_11480;
v_11481:
    goto v_11475;
v_11476:
    goto v_11477;
v_11478:
    goto v_11479;
v_11480:
    fn = elt(env, 26); // rerror
    v_11578 = (*qfnn(fn))(fn, 3, stack[-4], stack[-3], v_11578);
    env = stack[-11];
    goto v_11470;
v_11472:
v_11470:
    v_11578 = stack[-5];
    fn = elt(env, 27); // reversip!*
    v_11578 = (*qfn1(fn))(fn, v_11578);
    env = stack[-11];
    v_11578 = Lcompress(nil, v_11578);
    env = stack[-11];
    stack[-5] = v_11578;
    v_11578 = stack[-7];
    if (v_11578 == nil) goto v_11520;
    goto v_11527;
v_11523:
    v_11579 = stack[-8];
    goto v_11524;
v_11525:
    v_11578 = stack[-5];
    goto v_11526;
v_11527:
    goto v_11523;
v_11524:
    goto v_11525;
v_11526:
    v_11578 = difference2(v_11579, v_11578);
    env = stack[-11];
    stack[-8] = v_11578;
    goto v_11518;
v_11520:
    goto v_11537;
v_11533:
    v_11579 = stack[-8];
    goto v_11534;
v_11535:
    v_11578 = stack[-5];
    goto v_11536;
v_11537:
    goto v_11533;
v_11534:
    goto v_11535;
v_11536:
    v_11578 = plus2(v_11579, v_11578);
    env = stack[-11];
    stack[-8] = v_11578;
    goto v_11518;
v_11518:
v_11199:
    v_11578 = stack[-6];
    fn = elt(env, 27); // reversip!*
    v_11578 = (*qfn1(fn))(fn, v_11578);
    env = stack[-11];
    v_11578 = Lcompress(nil, v_11578);
    env = stack[-11];
    stack[-6] = v_11578;
v_11200:
    v_11578 = stack[-10];
    if (v_11578 == nil) goto v_11546;
    goto v_11555;
v_11549:
    v_11580 = elt(env, 16); // !:dn!:
    goto v_11550;
v_11551:
    v_11579 = stack[-6];
    goto v_11552;
v_11553:
    v_11578 = stack[-8];
    goto v_11554;
v_11555:
    goto v_11549;
v_11550:
    goto v_11551;
v_11552:
    goto v_11553;
v_11554:
    v_11578 = list2star(v_11580, v_11579, v_11578);
    env = stack[-11];
    goto v_11544;
v_11546:
    v_11578 = qvalue(elt(env, 17)); // !*adjprec
    if (v_11578 == nil) goto v_11560;
    goto v_11569;
v_11563:
    v_11580 = elt(env, 18); // !:int!:
    goto v_11564;
v_11565:
    v_11579 = stack[-6];
    goto v_11566;
v_11567:
    v_11578 = nil;
    goto v_11568;
v_11569:
    goto v_11563;
v_11564:
    goto v_11565;
v_11566:
    goto v_11567;
v_11568:
    v_11578 = list2star(v_11580, v_11579, v_11578);
    env = stack[-11];
    goto v_11544;
v_11560:
    v_11578 = stack[-6];
    goto v_11544;
    v_11578 = nil;
v_11544:
    qvalue(elt(env, 19)) = v_11578; // nxtsym!*
    v_11578 = stack[-9];
    qvalue(elt(env, 20)) = v_11578; // crchar!*
    v_11578 = qvalue(elt(env, 19)); // nxtsym!*
    return onevalue(v_11578);
}



// Code for applyrd

static LispObject CC_applyrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11251, v_11252;
    LispObject fn;
    argcheck(nargs, 0, "applyrd");
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
    fn = elt(env, 6); // lex
    v_11251 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_11195;
v_11191:
    v_11252 = qvalue(elt(env, 1)); // atts
    goto v_11192;
v_11193:
    v_11251 = elt(env, 2); // (type definitionurl encoding)
    goto v_11194;
v_11195:
    goto v_11191;
v_11192:
    goto v_11193;
v_11194:
    fn = elt(env, 7); // retattributes
    v_11251 = (*qfn2(fn))(fn, v_11252, v_11251);
    env = stack[-1];
    qvalue(elt(env, 3)) = v_11251; // mmlatts
    goto v_11206;
v_11202:
    v_11251 = qvalue(elt(env, 4)); // char
    fn = elt(env, 8); // compress!*
    v_11252 = (*qfn1(fn))(fn, v_11251);
    env = stack[-1];
    goto v_11203;
v_11204:
    v_11251 = qvalue(elt(env, 5)); // functions!*
    goto v_11205;
v_11206:
    goto v_11202;
v_11203:
    goto v_11204;
v_11205:
    v_11251 = Lassoc(nil, v_11252, v_11251);
    stack[0] = v_11251;
    if (v_11251 == nil) goto v_11201;
    goto v_11216;
v_11212:
    v_11251 = stack[0];
    v_11251 = qcdr(v_11251);
    v_11252 = qcar(v_11251);
    goto v_11213;
v_11214:
    v_11251 = nil;
    goto v_11215;
v_11216:
    goto v_11212;
v_11213:
    goto v_11214;
v_11215:
    fn = elt(env, 9); // apply
    v_11251 = (*qfn2(fn))(fn, v_11252, v_11251);
    env = stack[-1];
    v_11252 = v_11251;
    goto v_11226;
v_11222:
    v_11251 = qvalue(elt(env, 3)); // mmlatts
    goto v_11223;
v_11224:
    goto v_11225;
v_11226:
    goto v_11222;
v_11223:
    goto v_11224;
v_11225:
    v_11251 = cons(v_11251, v_11252);
    env = stack[-1];
    v_11252 = v_11251;
    v_11251 = nil;
    qvalue(elt(env, 3)) = v_11251; // mmlatts
    goto v_11235;
v_11231:
    v_11251 = stack[0];
    v_11251 = qcdr(v_11251);
    v_11251 = qcdr(v_11251);
    v_11251 = qcar(v_11251);
    goto v_11232;
v_11233:
    goto v_11234;
v_11235:
    goto v_11231;
v_11232:
    goto v_11233;
v_11234:
    return cons(v_11251, v_11252);
v_11201:
    goto v_11247;
v_11243:
    v_11251 = qvalue(elt(env, 4)); // char
    v_11252 = Lcompress(nil, v_11251);
    env = stack[-1];
    goto v_11244;
v_11245:
    v_11251 = (LispObject)272+TAG_FIXNUM; // 17
    goto v_11246;
v_11247:
    goto v_11243;
v_11244:
    goto v_11245;
v_11246:
    fn = elt(env, 10); // errorml
    v_11251 = (*qfn2(fn))(fn, v_11252, v_11251);
    v_11251 = nil;
    return onevalue(v_11251);
}



// Code for ps!:minusp!:

static LispObject CC_psTminuspT(LispObject env,
                         LispObject v_11184)
{
    env = qenv(env);
    LispObject v_11187;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11187 = v_11184;
// end of prologue
    v_11187 = nil;
    return onevalue(v_11187);
}



// Code for arg2of2

static LispObject CC_arg2of2(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11188, v_11189;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11188 = v_11185;
    v_11189 = v_11184;
// end of prologue
    return onevalue(v_11188);
}



// Code for cut!:mt

static LispObject CC_cutTmt(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11294, v_11295;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11185;
    stack[-2] = v_11184;
// end of prologue
    goto v_11204;
v_11200:
    v_11295 = stack[-2];
    goto v_11201;
v_11202:
    v_11294 = elt(env, 1); // !:rd!:
    goto v_11203;
v_11204:
    goto v_11200;
v_11201:
    goto v_11202;
v_11203:
    if (!consp(v_11295)) goto v_11198;
    v_11295 = qcar(v_11295);
    if (v_11295 == v_11294) goto v_11197;
    else goto v_11198;
v_11197:
    v_11294 = stack[-2];
    v_11294 = qcdr(v_11294);
    v_11294 = (consp(v_11294) ? nil : lisp_true);
    v_11294 = (v_11294 == nil ? lisp_true : nil);
    goto v_11196;
v_11198:
    v_11294 = nil;
    goto v_11196;
    v_11294 = nil;
v_11196:
    if (v_11294 == nil) goto v_11194;
    v_11294 = stack[-1];
    v_11294 = integerp(v_11294);
    if (v_11294 == nil) goto v_11216;
    else goto v_11217;
v_11216:
    v_11294 = nil;
    goto v_11215;
v_11217:
    goto v_11228;
v_11224:
    v_11295 = stack[-1];
    goto v_11225;
v_11226:
    v_11294 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11227;
v_11228:
    goto v_11224;
v_11225:
    goto v_11226;
v_11227:
    v_11294 = (LispObject)greaterp2(v_11295, v_11294);
    v_11294 = v_11294 ? lisp_true : nil;
    env = stack[-4];
    goto v_11215;
    v_11294 = nil;
v_11215:
    goto v_11192;
v_11194:
    v_11294 = nil;
    goto v_11192;
    v_11294 = nil;
v_11192:
    if (v_11294 == nil) goto v_11190;
    goto v_11243;
v_11239:
    goto v_11249;
v_11245:
    v_11294 = stack[-2];
    v_11294 = qcdr(v_11294);
    v_11294 = qcar(v_11294);
    v_11294 = Labsval(nil, v_11294);
    env = stack[-4];
    fn = elt(env, 2); // msd
    v_11295 = (*qfn1(fn))(fn, v_11294);
    env = stack[-4];
    goto v_11246;
v_11247:
    v_11294 = stack[-1];
    goto v_11248;
v_11249:
    goto v_11245;
v_11246:
    goto v_11247;
v_11248:
    v_11295 = difference2(v_11295, v_11294);
    env = stack[-4];
    stack[-1] = v_11295;
    goto v_11240;
v_11241:
    v_11294 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11242;
v_11243:
    goto v_11239;
v_11240:
    goto v_11241;
v_11242:
    v_11294 = (LispObject)lesseq2(v_11295, v_11294);
    v_11294 = v_11294 ? lisp_true : nil;
    env = stack[-4];
    if (v_11294 == nil) goto v_11237;
    v_11294 = stack[-2];
    goto v_11235;
v_11237:
    goto v_11267;
v_11261:
    stack[-3] = elt(env, 1); // !:rd!:
    goto v_11262;
v_11263:
    goto v_11274;
v_11270:
    v_11294 = stack[-2];
    v_11294 = qcdr(v_11294);
    stack[0] = qcar(v_11294);
    goto v_11271;
v_11272:
    v_11294 = stack[-1];
    v_11294 = negate(v_11294);
    env = stack[-4];
    goto v_11273;
v_11274:
    goto v_11270;
v_11271:
    goto v_11272;
v_11273:
    fn = elt(env, 3); // ashift
    stack[0] = (*qfn2(fn))(fn, stack[0], v_11294);
    env = stack[-4];
    goto v_11264;
v_11265:
    goto v_11285;
v_11281:
    v_11294 = stack[-2];
    v_11294 = qcdr(v_11294);
    v_11295 = qcdr(v_11294);
    goto v_11282;
v_11283:
    v_11294 = stack[-1];
    goto v_11284;
v_11285:
    goto v_11281;
v_11282:
    goto v_11283;
v_11284:
    v_11294 = plus2(v_11295, v_11294);
    goto v_11266;
v_11267:
    goto v_11261;
v_11262:
    goto v_11263;
v_11264:
    goto v_11265;
v_11266:
    {
        LispObject v_11300 = stack[-3];
        LispObject v_11301 = stack[0];
        return list2star(v_11300, v_11301, v_11294);
    }
    v_11294 = nil;
v_11235:
    goto v_11188;
v_11190:
    v_11294 = elt(env, 0); // cut!:mt
    {
        fn = elt(env, 4); // bflerrmsg
        return (*qfn1(fn))(fn, v_11294);
    }
    v_11294 = nil;
v_11188:
    return onevalue(v_11294);
}



// Code for contr2!-strand

static LispObject CC_contr2Kstrand(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11301, v_11302, v_11303, v_11304;
    LispObject fn;
    LispObject v_11187, v_11186, v_11185, v_11184;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "contr2-strand");
    va_start(aa, nargs);
    v_11184 = va_arg(aa, LispObject);
    v_11185 = va_arg(aa, LispObject);
    v_11186 = va_arg(aa, LispObject);
    v_11187 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_11187,v_11186,v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_11184,v_11185,v_11186,v_11187);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_11187;
    stack[-1] = v_11186;
    stack[-2] = v_11185;
    stack[-3] = v_11184;
// end of prologue
v_11183:
    v_11301 = stack[-3];
    if (v_11301 == nil) goto v_11191;
    else goto v_11192;
v_11191:
    v_11301 = stack[-1];
    goto v_11190;
v_11192:
    goto v_11202;
v_11198:
    v_11301 = stack[-3];
    v_11302 = qcar(v_11301);
    goto v_11199;
v_11200:
    v_11301 = stack[-2];
    goto v_11201;
v_11202:
    goto v_11198;
v_11199:
    goto v_11200;
v_11201:
    fn = elt(env, 1); // contrsp
    v_11301 = (*qfn2(fn))(fn, v_11302, v_11301);
    env = stack[-4];
    v_11303 = v_11301;
    v_11301 = v_11303;
    if (v_11301 == nil) goto v_11210;
    goto v_11220;
v_11216:
    v_11301 = v_11303;
    v_11302 = qcar(v_11301);
    goto v_11217;
v_11218:
    v_11301 = v_11303;
    v_11301 = qcdr(v_11301);
    goto v_11219;
v_11220:
    goto v_11216;
v_11217:
    goto v_11218;
v_11219:
    v_11301 = Lmember(nil, v_11302, v_11301);
    if (v_11301 == nil) goto v_11215;
    goto v_11231;
v_11227:
    v_11302 = stack[-3];
    goto v_11228;
v_11229:
    v_11301 = stack[-1];
    goto v_11230;
v_11231:
    goto v_11227;
v_11228:
    goto v_11229;
v_11230:
        return Lappend(nil, v_11302, v_11301);
v_11215:
    v_11301 = stack[0];
    if (v_11301 == nil) goto v_11234;
    else goto v_11235;
v_11234:
    goto v_11246;
v_11238:
    goto v_11254;
v_11248:
    goto v_11249;
v_11250:
    v_11301 = stack[-3];
    v_11302 = qcdr(v_11301);
    goto v_11251;
v_11252:
    v_11301 = stack[-1];
    goto v_11253;
v_11254:
    goto v_11248;
v_11249:
    goto v_11250;
v_11251:
    goto v_11252;
v_11253:
    fn = elt(env, 2); // contr2
    v_11304 = (*qfnn(fn))(fn, 3, v_11303, v_11302, v_11301);
    env = stack[-4];
    goto v_11239;
v_11240:
    v_11303 = stack[-2];
    goto v_11241;
v_11242:
    v_11302 = nil;
    goto v_11243;
v_11244:
    v_11301 = lisp_true;
    goto v_11245;
v_11246:
    goto v_11238;
v_11239:
    goto v_11240;
v_11241:
    goto v_11242;
v_11243:
    goto v_11244;
v_11245:
    stack[-3] = v_11304;
    stack[-2] = v_11303;
    stack[-1] = v_11302;
    stack[0] = v_11301;
    goto v_11183;
v_11235:
    goto v_11271;
v_11265:
    goto v_11266;
v_11267:
    v_11301 = stack[-3];
    v_11302 = qcdr(v_11301);
    goto v_11268;
v_11269:
    v_11301 = stack[-1];
    goto v_11270;
v_11271:
    goto v_11265;
v_11266:
    goto v_11267;
v_11268:
    goto v_11269;
v_11270:
    {
        fn = elt(env, 2); // contr2
        return (*qfnn(fn))(fn, 3, v_11303, v_11302, v_11301);
    }
    v_11301 = nil;
    goto v_11208;
v_11210:
    goto v_11287;
v_11279:
    v_11301 = stack[-3];
    stack[0] = qcdr(v_11301);
    goto v_11280;
v_11281:
    goto v_11282;
v_11283:
    goto v_11296;
v_11292:
    v_11301 = stack[-3];
    v_11302 = qcar(v_11301);
    goto v_11293;
v_11294:
    v_11301 = stack[-1];
    goto v_11295;
v_11296:
    goto v_11292;
v_11293:
    goto v_11294;
v_11295:
    v_11302 = cons(v_11302, v_11301);
    env = stack[-4];
    goto v_11284;
v_11285:
    v_11301 = nil;
    goto v_11286;
v_11287:
    goto v_11279;
v_11280:
    goto v_11281;
v_11282:
    goto v_11283;
v_11284:
    goto v_11285;
v_11286:
    stack[-3] = stack[0];
    stack[-1] = v_11302;
    stack[0] = v_11301;
    goto v_11183;
    v_11301 = nil;
v_11208:
    goto v_11190;
    v_11301 = nil;
v_11190:
    return onevalue(v_11301);
}



// Code for assert_install

static LispObject CC_assert_install(LispObject env,
                         LispObject v_11184)
{
    env = qenv(env);
    LispObject v_11204;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11184);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_11204 = v_11184;
// end of prologue
    stack[0] = v_11204;
v_11189:
    v_11204 = stack[0];
    if (v_11204 == nil) goto v_11193;
    else goto v_11194;
v_11193:
    v_11204 = nil;
    goto v_11188;
v_11194:
    v_11204 = stack[0];
    v_11204 = qcar(v_11204);
    fn = elt(env, 1); // assert_install1
    v_11204 = (*qfn1(fn))(fn, v_11204);
    env = stack[-1];
    v_11204 = stack[0];
    v_11204 = qcdr(v_11204);
    stack[0] = v_11204;
    goto v_11189;
v_11188:
    return onevalue(v_11204);
}



// Code for rnminusp!:

static LispObject CC_rnminuspT(LispObject env,
                         LispObject v_11184)
{
    env = qenv(env);
    LispObject v_11213, v_11214;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11213 = v_11184;
// end of prologue
    v_11213 = qcdr(v_11213);
    v_11214 = qcar(v_11213);
    v_11213 = v_11214;
    if (!consp(v_11214)) goto v_11188;
    else goto v_11189;
v_11188:
    goto v_11198;
v_11194:
    v_11214 = v_11213;
    goto v_11195;
v_11196:
    v_11213 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11197;
v_11198:
    goto v_11194;
v_11195:
    goto v_11196;
v_11197:
        return Llessp(nil, v_11214, v_11213);
v_11189:
    goto v_11208;
v_11204:
    v_11214 = v_11213;
    v_11214 = qcar(v_11214);
    if (!symbolp(v_11214)) v_11214 = nil;
    else { v_11214 = qfastgets(v_11214);
           if (v_11214 != nil) { v_11214 = elt(v_11214, 30); // minusp
#ifdef RECORD_GET
             if (v_11214 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v_11214 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v_11214 == SPID_NOPROP) v_11214 = nil; }}
#endif
    goto v_11205;
v_11206:
    goto v_11207;
v_11208:
    goto v_11204;
v_11205:
    goto v_11206;
v_11207:
        return Lapply1(nil, v_11214, v_11213);
    v_11213 = nil;
    return onevalue(v_11213);
}



// Code for qremd

static LispObject CC_qremd(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11320, v_11321;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11185;
    stack[-2] = v_11184;
// end of prologue
    v_11320 = stack[-2];
    if (v_11320 == nil) goto v_11189;
    else goto v_11190;
v_11189:
    goto v_11197;
v_11193:
    v_11321 = stack[-2];
    goto v_11194;
v_11195:
    v_11320 = stack[-2];
    goto v_11196;
v_11197:
    goto v_11193;
v_11194:
    goto v_11195;
v_11196:
    return cons(v_11321, v_11320);
v_11190:
    goto v_11206;
v_11202:
    v_11321 = stack[-1];
    goto v_11203;
v_11204:
    v_11320 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11205;
v_11206:
    goto v_11202;
v_11203:
    goto v_11204;
v_11205:
    if (v_11321 == v_11320) goto v_11200;
    else goto v_11201;
v_11200:
    v_11320 = stack[-2];
    return ncons(v_11320);
v_11201:
    v_11320 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_11320)) v_11320 = nil;
    else { v_11320 = qfastgets(v_11320);
           if (v_11320 != nil) { v_11320 = elt(v_11320, 3); // field
#ifdef RECORD_GET
             if (v_11320 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_11320 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_11320 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_11320 == SPID_NOPROP) v_11320 = nil; else v_11320 = lisp_true; }}
#endif
    if (v_11320 == nil) goto v_11212;
    goto v_11221;
v_11217:
    v_11320 = stack[-1];
    fn = elt(env, 2); // !:recip
    v_11321 = (*qfn1(fn))(fn, v_11320);
    env = stack[-4];
    goto v_11218;
v_11219:
    v_11320 = stack[-2];
    goto v_11220;
v_11221:
    goto v_11217;
v_11218:
    goto v_11219;
v_11220:
    fn = elt(env, 3); // multd
    v_11320 = (*qfn2(fn))(fn, v_11321, v_11320);
    return ncons(v_11320);
v_11212:
    v_11320 = stack[-2];
    if (!consp(v_11320)) goto v_11229;
    else goto v_11230;
v_11229:
    v_11320 = lisp_true;
    goto v_11228;
v_11230:
    v_11320 = stack[-2];
    v_11320 = qcar(v_11320);
    v_11320 = (consp(v_11320) ? nil : lisp_true);
    goto v_11228;
    v_11320 = nil;
v_11228:
    if (v_11320 == nil) goto v_11226;
    goto v_11243;
v_11239:
    v_11321 = stack[-2];
    goto v_11240;
v_11241:
    v_11320 = stack[-1];
    goto v_11242;
v_11243:
    goto v_11239;
v_11240:
    goto v_11241;
v_11242:
    {
        fn = elt(env, 4); // !:divide
        return (*qfn2(fn))(fn, v_11321, v_11320);
    }
v_11226:
    goto v_11256;
v_11252:
    v_11320 = stack[-2];
    v_11320 = qcar(v_11320);
    v_11321 = qcdr(v_11320);
    goto v_11253;
v_11254:
    v_11320 = stack[-1];
    goto v_11255;
v_11256:
    goto v_11252;
v_11253:
    goto v_11254;
v_11255:
    fn = elt(env, 5); // qremf
    v_11320 = (*qfn2(fn))(fn, v_11321, v_11320);
    env = stack[-4];
    stack[-3] = v_11320;
    goto v_11266;
v_11262:
    goto v_11272;
v_11268:
    goto v_11278;
v_11274:
    goto v_11285;
v_11281:
    v_11320 = stack[-2];
    v_11320 = qcar(v_11320);
    v_11321 = qcar(v_11320);
    goto v_11282;
v_11283:
    v_11320 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11284;
v_11285:
    goto v_11281;
v_11282:
    goto v_11283;
v_11284:
    v_11320 = cons(v_11321, v_11320);
    env = stack[-4];
    v_11321 = ncons(v_11320);
    env = stack[-4];
    goto v_11275;
v_11276:
    v_11320 = stack[-3];
    v_11320 = qcar(v_11320);
    goto v_11277;
v_11278:
    goto v_11274;
v_11275:
    goto v_11276;
v_11277:
    fn = elt(env, 6); // multf
    stack[0] = (*qfn2(fn))(fn, v_11321, v_11320);
    env = stack[-4];
    goto v_11269;
v_11270:
    goto v_11297;
v_11293:
    goto v_11304;
v_11300:
    v_11320 = stack[-2];
    v_11320 = qcar(v_11320);
    v_11321 = qcar(v_11320);
    goto v_11301;
v_11302:
    v_11320 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11303;
v_11304:
    goto v_11300;
v_11301:
    goto v_11302;
v_11303:
    v_11320 = cons(v_11321, v_11320);
    env = stack[-4];
    v_11321 = ncons(v_11320);
    env = stack[-4];
    goto v_11294;
v_11295:
    v_11320 = stack[-3];
    v_11320 = qcdr(v_11320);
    goto v_11296;
v_11297:
    goto v_11293;
v_11294:
    goto v_11295;
v_11296:
    fn = elt(env, 6); // multf
    v_11320 = (*qfn2(fn))(fn, v_11321, v_11320);
    env = stack[-4];
    goto v_11271;
v_11272:
    goto v_11268;
v_11269:
    goto v_11270;
v_11271:
    stack[0] = cons(stack[0], v_11320);
    env = stack[-4];
    goto v_11263;
v_11264:
    goto v_11316;
v_11312:
    v_11320 = stack[-2];
    v_11321 = qcdr(v_11320);
    goto v_11313;
v_11314:
    v_11320 = stack[-1];
    goto v_11315;
v_11316:
    goto v_11312;
v_11313:
    goto v_11314;
v_11315:
    v_11320 = CC_qremd(elt(env, 0), v_11321, v_11320);
    env = stack[-4];
    goto v_11265;
v_11266:
    goto v_11262;
v_11263:
    goto v_11264;
v_11265:
    {
        LispObject v_11326 = stack[0];
        fn = elt(env, 7); // praddf
        return (*qfn2(fn))(fn, v_11326, v_11320);
    }
    goto v_11188;
    v_11320 = nil;
v_11188:
    return onevalue(v_11320);
}



// Code for reverse!-num

static LispObject CC_reverseKnum(LispObject env,
                         LispObject v_11184)
{
    env = qenv(env);
    LispObject v_11233, v_11234;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11184);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11184;
// end of prologue
    goto v_11194;
v_11190:
    v_11234 = stack[0];
    goto v_11191;
v_11192:
    v_11233 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11193;
v_11194:
    goto v_11190;
v_11191:
    goto v_11192;
v_11193:
    if (v_11234 == v_11233) goto v_11188;
    else goto v_11189;
v_11188:
    v_11233 = stack[0];
    goto v_11187;
v_11189:
    goto v_11205;
v_11201:
    v_11234 = stack[0];
    goto v_11202;
v_11203:
    v_11233 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11204;
v_11205:
    goto v_11201;
v_11202:
    goto v_11203;
v_11204:
    v_11233 = (LispObject)lessp2(v_11234, v_11233);
    v_11233 = v_11233 ? lisp_true : nil;
    env = stack[-2];
    if (v_11233 == nil) goto v_11199;
    goto v_11214;
v_11210:
    v_11233 = stack[0];
    stack[-1] = negate(v_11233);
    env = stack[-2];
    goto v_11211;
v_11212:
    v_11233 = stack[0];
    v_11233 = negate(v_11233);
    env = stack[-2];
    fn = elt(env, 1); // ilog2
    v_11233 = (*qfn1(fn))(fn, v_11233);
    env = stack[-2];
    v_11233 = add1(v_11233);
    env = stack[-2];
    goto v_11213;
v_11214:
    goto v_11210;
v_11211:
    goto v_11212;
v_11213:
    fn = elt(env, 2); // reverse!-num1
    v_11233 = (*qfn2(fn))(fn, stack[-1], v_11233);
    return negate(v_11233);
v_11199:
    goto v_11228;
v_11224:
    stack[-1] = stack[0];
    goto v_11225;
v_11226:
    v_11233 = stack[0];
    fn = elt(env, 1); // ilog2
    v_11233 = (*qfn1(fn))(fn, v_11233);
    env = stack[-2];
    v_11233 = add1(v_11233);
    env = stack[-2];
    goto v_11227;
v_11228:
    goto v_11224;
v_11225:
    goto v_11226;
v_11227:
    {
        LispObject v_11237 = stack[-1];
        fn = elt(env, 2); // reverse!-num1
        return (*qfn2(fn))(fn, v_11237, v_11233);
    }
    v_11233 = nil;
v_11187:
    return onevalue(v_11233);
}



// Code for quotient!-mod!-p

static LispObject CC_quotientKmodKp(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11336, v_11337, v_11338;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11185;
    stack[-1] = v_11184;
// end of prologue
    v_11336 = stack[0];
    if (v_11336 == nil) goto v_11189;
    else goto v_11190;
v_11189:
    v_11336 = elt(env, 1); // "b=0 in quotient-mod-p"
    {
        fn = elt(env, 3); // errorf
        return (*qfn1(fn))(fn, v_11336);
    }
v_11190:
    v_11336 = stack[0];
    if (!consp(v_11336)) goto v_11198;
    else goto v_11199;
v_11198:
    v_11336 = lisp_true;
    goto v_11197;
v_11199:
    v_11336 = stack[0];
    v_11336 = qcar(v_11336);
    v_11336 = (consp(v_11336) ? nil : lisp_true);
    goto v_11197;
    v_11336 = nil;
v_11197:
    if (v_11336 == nil) goto v_11195;
    v_11336 = stack[0];
    fn = elt(env, 4); // safe!-modular!-reciprocal
    v_11336 = (*qfn1(fn))(fn, v_11336);
    env = stack[-3];
    v_11337 = v_11336;
    if (v_11337 == nil) goto v_11214;
    else goto v_11215;
v_11214:
    v_11336 = nil;
    qvalue(elt(env, 2)) = v_11336; // exact!-quotient!-flag
    goto v_11209;
v_11215:
    goto v_11225;
v_11221:
    v_11337 = stack[-1];
    goto v_11222;
v_11223:
    goto v_11224;
v_11225:
    goto v_11221;
v_11222:
    goto v_11223;
v_11224:
    {
        fn = elt(env, 5); // multiply!-by!-constant!-mod!-p
        return (*qfn2(fn))(fn, v_11337, v_11336);
    }
    v_11336 = nil;
v_11209:
    goto v_11188;
v_11195:
    v_11336 = stack[-1];
    if (v_11336 == nil) goto v_11228;
    else goto v_11229;
v_11228:
    v_11336 = nil;
    goto v_11188;
v_11229:
    v_11336 = stack[-1];
    if (!consp(v_11336)) goto v_11236;
    else goto v_11237;
v_11236:
    v_11336 = lisp_true;
    goto v_11235;
v_11237:
    v_11336 = stack[-1];
    v_11336 = qcar(v_11336);
    v_11336 = (consp(v_11336) ? nil : lisp_true);
    goto v_11235;
    v_11336 = nil;
v_11235:
    if (v_11336 == nil) goto v_11233;
    v_11336 = nil;
    qvalue(elt(env, 2)) = v_11336; // exact!-quotient!-flag
    goto v_11188;
v_11233:
    goto v_11252;
v_11248:
    v_11336 = stack[-1];
    v_11336 = qcar(v_11336);
    v_11336 = qcar(v_11336);
    v_11337 = qcar(v_11336);
    goto v_11249;
v_11250:
    v_11336 = stack[0];
    v_11336 = qcar(v_11336);
    v_11336 = qcar(v_11336);
    v_11336 = qcar(v_11336);
    goto v_11251;
v_11252:
    goto v_11248;
v_11249:
    goto v_11250;
v_11251:
    if (equal(v_11337, v_11336)) goto v_11246;
    else goto v_11247;
v_11246:
    goto v_11268;
v_11262:
    v_11338 = stack[-1];
    goto v_11263;
v_11264:
    v_11337 = stack[0];
    goto v_11265;
v_11266:
    v_11336 = stack[0];
    v_11336 = qcar(v_11336);
    v_11336 = qcar(v_11336);
    v_11336 = qcar(v_11336);
    goto v_11267;
v_11268:
    goto v_11262;
v_11263:
    goto v_11264;
v_11265:
    goto v_11266;
v_11267:
    {
        fn = elt(env, 6); // xquotient!-mod!-p
        return (*qfnn(fn))(fn, 3, v_11338, v_11337, v_11336);
    }
v_11247:
    goto v_11282;
v_11278:
    v_11336 = stack[-1];
    v_11336 = qcar(v_11336);
    v_11336 = qcar(v_11336);
    v_11337 = qcar(v_11336);
    goto v_11279;
v_11280:
    v_11336 = stack[0];
    v_11336 = qcar(v_11336);
    v_11336 = qcar(v_11336);
    v_11336 = qcar(v_11336);
    goto v_11281;
v_11282:
    goto v_11278;
v_11279:
    goto v_11280;
v_11281:
    fn = elt(env, 7); // ordop
    v_11336 = (*qfn2(fn))(fn, v_11337, v_11336);
    env = stack[-3];
    if (v_11336 == nil) goto v_11276;
    goto v_11296;
v_11292:
    v_11336 = stack[-1];
    v_11336 = qcar(v_11336);
    v_11337 = qcdr(v_11336);
    goto v_11293;
v_11294:
    v_11336 = stack[0];
    goto v_11295;
v_11296:
    goto v_11292;
v_11293:
    goto v_11294;
v_11295:
    stack[-2] = CC_quotientKmodKp(elt(env, 0), v_11337, v_11336);
    env = stack[-3];
    goto v_11306;
v_11302:
    v_11336 = stack[-1];
    v_11337 = qcdr(v_11336);
    goto v_11303;
v_11304:
    v_11336 = stack[0];
    goto v_11305;
v_11306:
    goto v_11302;
v_11303:
    goto v_11304;
v_11305:
    v_11336 = CC_quotientKmodKp(elt(env, 0), v_11337, v_11336);
    v_11337 = stack[-2];
    v_11338 = v_11337;
    if (v_11338 == nil) goto v_11314;
    else goto v_11315;
v_11314:
    goto v_11313;
v_11315:
    goto v_11327;
v_11321:
    v_11338 = stack[-1];
    v_11338 = qcar(v_11338);
    v_11338 = qcar(v_11338);
    goto v_11322;
v_11323:
    goto v_11324;
v_11325:
    goto v_11326;
v_11327:
    goto v_11321;
v_11322:
    goto v_11323;
v_11324:
    goto v_11325;
v_11326:
    return acons(v_11338, v_11337, v_11336);
    v_11336 = nil;
v_11313:
    goto v_11188;
v_11276:
    v_11336 = nil;
    qvalue(elt(env, 2)) = v_11336; // exact!-quotient!-flag
    goto v_11188;
    v_11336 = nil;
v_11188:
    return onevalue(v_11336);
}



// Code for lto_max1

static LispObject CC_lto_max1(LispObject env,
                         LispObject v_11184)
{
    env = qenv(env);
    LispObject v_11229, v_11230;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11184);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11184;
// end of prologue
    stack[-1] = nil;
v_11190:
    v_11229 = stack[0];
    v_11229 = qcdr(v_11229);
    if (v_11229 == nil) goto v_11195;
    else goto v_11196;
v_11195:
    goto v_11191;
v_11196:
    goto v_11204;
v_11200:
    v_11229 = stack[0];
    v_11230 = qcar(v_11229);
    goto v_11201;
v_11202:
    v_11229 = stack[-1];
    goto v_11203;
v_11204:
    goto v_11200;
v_11201:
    goto v_11202;
v_11203:
    v_11229 = cons(v_11230, v_11229);
    env = stack[-2];
    stack[-1] = v_11229;
    v_11229 = stack[0];
    v_11229 = qcdr(v_11229);
    stack[0] = v_11229;
    goto v_11190;
v_11191:
    v_11229 = stack[0];
    v_11229 = qcar(v_11229);
    v_11230 = v_11229;
v_11192:
    v_11229 = stack[-1];
    if (v_11229 == nil) goto v_11214;
    else goto v_11215;
v_11214:
    v_11229 = v_11230;
    goto v_11189;
v_11215:
    goto v_11223;
v_11219:
    v_11229 = stack[-1];
    v_11229 = qcar(v_11229);
    goto v_11220;
v_11221:
    goto v_11222;
v_11223:
    goto v_11219;
v_11220:
    goto v_11221;
v_11222:
    fn = elt(env, 1); // max
    v_11229 = (*qfn2(fn))(fn, v_11229, v_11230);
    env = stack[-2];
    v_11230 = v_11229;
    v_11229 = stack[-1];
    v_11229 = qcdr(v_11229);
    stack[-1] = v_11229;
    goto v_11192;
v_11189:
    return onevalue(v_11229);
}



// Code for mapins

static LispObject CC_mapins(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11224, v_11225, v_11226;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11185;
    stack[-1] = v_11184;
// end of prologue
    stack[-2] = nil;
v_11190:
    v_11224 = stack[0];
    if (v_11224 == nil) goto v_11193;
    else goto v_11194;
v_11193:
    v_11224 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_11224);
    }
v_11194:
    goto v_11207;
v_11201:
    goto v_11213;
v_11209:
    v_11225 = stack[-1];
    goto v_11210;
v_11211:
    v_11224 = stack[0];
    v_11224 = qcar(v_11224);
    v_11224 = qcar(v_11224);
    goto v_11212;
v_11213:
    goto v_11209;
v_11210:
    goto v_11211;
v_11212:
    v_11226 = cons(v_11225, v_11224);
    env = stack[-3];
    goto v_11202;
v_11203:
    v_11224 = stack[0];
    v_11224 = qcar(v_11224);
    v_11225 = qcdr(v_11224);
    goto v_11204;
v_11205:
    v_11224 = stack[-2];
    goto v_11206;
v_11207:
    goto v_11201;
v_11202:
    goto v_11203;
v_11204:
    goto v_11205;
v_11206:
    v_11224 = acons(v_11226, v_11225, v_11224);
    env = stack[-3];
    stack[-2] = v_11224;
    v_11224 = stack[0];
    v_11224 = qcdr(v_11224);
    stack[0] = v_11224;
    goto v_11190;
    v_11224 = nil;
    return onevalue(v_11224);
}



// Code for ibalp_tvb

static LispObject CC_ibalp_tvb(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11235, v_11236;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_11185;
    v_11235 = v_11184;
// end of prologue
    stack[-2] = v_11235;
v_11190:
    v_11235 = stack[-2];
    if (v_11235 == nil) goto v_11194;
    else goto v_11195;
v_11194:
    v_11235 = nil;
    goto v_11189;
v_11195:
    v_11235 = stack[-2];
    v_11235 = qcar(v_11235);
    stack[0] = v_11235;
    goto v_11210;
v_11206:
    v_11235 = stack[0];
    v_11235 = qcdr(v_11235);
    v_11235 = qcdr(v_11235);
    v_11235 = qcdr(v_11235);
    v_11235 = qcdr(v_11235);
    v_11235 = qcdr(v_11235);
    v_11235 = qcdr(v_11235);
    v_11235 = qcdr(v_11235);
    v_11236 = qcar(v_11235);
    goto v_11207;
v_11208:
    v_11235 = stack[-1];
    goto v_11209;
v_11210:
    goto v_11206;
v_11207:
    goto v_11208;
v_11209:
    v_11235 = (LispObject)geq2(v_11236, v_11235);
    v_11235 = v_11235 ? lisp_true : nil;
    env = stack[-3];
    if (v_11235 == nil) goto v_11204;
    goto v_11226;
v_11222:
    v_11235 = stack[0];
    v_11236 = qcdr(v_11235);
    goto v_11223;
v_11224:
    v_11235 = stack[0];
    v_11235 = qcdr(v_11235);
    v_11235 = qcdr(v_11235);
    v_11235 = qcar(v_11235);
    goto v_11225;
v_11226:
    goto v_11222;
v_11223:
    goto v_11224;
v_11225:
    fn = elt(env, 1); // ibalp_var!-unset
    v_11235 = (*qfn2(fn))(fn, v_11236, v_11235);
    env = stack[-3];
    goto v_11202;
v_11204:
v_11202:
    v_11235 = stack[-2];
    v_11235 = qcdr(v_11235);
    stack[-2] = v_11235;
    goto v_11190;
v_11189:
    return onevalue(v_11235);
}



// Code for aex_fvarl

static LispObject CC_aex_fvarl(LispObject env,
                         LispObject v_11184)
{
    env = qenv(env);
    LispObject v_11197;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11184);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11184;
// end of prologue
    goto v_11191;
v_11187:
    v_11197 = stack[0];
    fn = elt(env, 1); // aex_varl
    stack[-1] = (*qfn1(fn))(fn, v_11197);
    env = stack[-2];
    goto v_11188;
v_11189:
    v_11197 = stack[0];
    fn = elt(env, 2); // aex_ctx
    v_11197 = (*qfn1(fn))(fn, v_11197);
    env = stack[-2];
    fn = elt(env, 3); // ctx_idl
    v_11197 = (*qfn1(fn))(fn, v_11197);
    env = stack[-2];
    goto v_11190;
v_11191:
    goto v_11187;
v_11188:
    goto v_11189;
v_11190:
    {
        LispObject v_11200 = stack[-1];
        fn = elt(env, 4); // lto_setminus
        return (*qfn2(fn))(fn, v_11200, v_11197);
    }
}



// Code for make!-univariate!-image!-mod!-p

static LispObject CC_makeKunivariateKimageKmodKp(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11426, v_11427, v_11428;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11185;
    stack[-2] = v_11184;
// end of prologue
    v_11426 = stack[-2];
    if (!consp(v_11426)) goto v_11197;
    else goto v_11198;
v_11197:
    v_11426 = lisp_true;
    goto v_11196;
v_11198:
    v_11426 = stack[-2];
    v_11426 = qcar(v_11426);
    v_11426 = (consp(v_11426) ? nil : lisp_true);
    goto v_11196;
    v_11426 = nil;
v_11196:
    if (v_11426 == nil) goto v_11194;
    v_11426 = stack[-2];
    if (v_11426 == nil) goto v_11208;
    else goto v_11209;
v_11208:
    v_11426 = nil;
    goto v_11190;
v_11209:
    v_11426 = stack[-2];
    v_11426 = Lmodular_number(nil, v_11426);
    env = stack[-4];
    {
        fn = elt(env, 1); // !*n2f
        return (*qfn1(fn))(fn, v_11426);
    }
    goto v_11192;
v_11194:
v_11192:
    goto v_11225;
v_11221:
    v_11426 = stack[-2];
    v_11426 = qcar(v_11426);
    v_11426 = qcar(v_11426);
    v_11427 = qcar(v_11426);
    goto v_11222;
v_11223:
    v_11426 = stack[-1];
    goto v_11224;
v_11225:
    goto v_11221;
v_11222:
    goto v_11223;
v_11224:
    if (equal(v_11427, v_11426)) goto v_11219;
    else goto v_11220;
v_11219:
    v_11426 = nil;
    stack[0] = v_11426;
v_11234:
    v_11426 = stack[-2];
    if (!consp(v_11426)) goto v_11245;
    else goto v_11246;
v_11245:
    v_11426 = lisp_true;
    goto v_11244;
v_11246:
    v_11426 = stack[-2];
    v_11426 = qcar(v_11426);
    v_11426 = (consp(v_11426) ? nil : lisp_true);
    goto v_11244;
    v_11426 = nil;
v_11244:
    if (v_11426 == nil) goto v_11241;
    else goto v_11242;
v_11241:
    goto v_11258;
v_11254:
    v_11426 = stack[-2];
    v_11426 = qcar(v_11426);
    v_11426 = qcar(v_11426);
    v_11427 = qcar(v_11426);
    goto v_11255;
v_11256:
    v_11426 = stack[-1];
    goto v_11257;
v_11258:
    goto v_11254;
v_11255:
    goto v_11256;
v_11257:
    v_11426 = (equal(v_11427, v_11426) ? lisp_true : nil);
    goto v_11240;
v_11242:
    v_11426 = nil;
    goto v_11240;
    v_11426 = nil;
v_11240:
    if (v_11426 == nil) goto v_11237;
    else goto v_11238;
v_11237:
    goto v_11233;
v_11238:
    goto v_11274;
v_11270:
    v_11426 = stack[-2];
    v_11426 = qcar(v_11426);
    v_11427 = qcdr(v_11426);
    goto v_11271;
v_11272:
    v_11426 = stack[-1];
    goto v_11273;
v_11274:
    goto v_11270;
v_11271:
    goto v_11272;
v_11273:
    v_11426 = CC_makeKunivariateKimageKmodKp(elt(env, 0), v_11427, v_11426);
    env = stack[-4];
    stack[-3] = v_11426;
    v_11426 = stack[-3];
    if (v_11426 == nil) goto v_11282;
    goto v_11291;
v_11285:
    v_11426 = stack[-2];
    v_11426 = qcar(v_11426);
    v_11428 = qcar(v_11426);
    goto v_11286;
v_11287:
    v_11427 = stack[-3];
    goto v_11288;
v_11289:
    v_11426 = stack[0];
    goto v_11290;
v_11291:
    goto v_11285;
v_11286:
    goto v_11287;
v_11288:
    goto v_11289;
v_11290:
    v_11426 = acons(v_11428, v_11427, v_11426);
    env = stack[-4];
    stack[0] = v_11426;
    goto v_11280;
v_11282:
v_11280:
    v_11426 = stack[-2];
    v_11426 = qcdr(v_11426);
    stack[-2] = v_11426;
    goto v_11234;
v_11233:
    goto v_11304;
v_11300:
    v_11427 = stack[-2];
    goto v_11301;
v_11302:
    v_11426 = stack[-1];
    goto v_11303;
v_11304:
    goto v_11300;
v_11301:
    goto v_11302;
v_11303:
    v_11426 = CC_makeKunivariateKimageKmodKp(elt(env, 0), v_11427, v_11426);
    env = stack[-4];
    stack[-2] = v_11426;
v_11310:
    v_11426 = stack[0];
    if (v_11426 == nil) goto v_11313;
    else goto v_11314;
v_11313:
    goto v_11309;
v_11314:
    v_11426 = stack[0];
    v_11426 = qcdr(v_11426);
    stack[-3] = v_11426;
    goto v_11324;
v_11320:
    v_11427 = stack[0];
    goto v_11321;
v_11322:
    v_11426 = stack[-2];
    goto v_11323;
v_11324:
    goto v_11320;
v_11321:
    goto v_11322;
v_11323:
    v_11426 = Lrplacd(nil, v_11427, v_11426);
    env = stack[-4];
    v_11426 = stack[0];
    stack[-2] = v_11426;
    v_11426 = stack[-3];
    stack[0] = v_11426;
    goto v_11310;
v_11309:
    v_11426 = stack[-2];
    goto v_11190;
v_11220:
    v_11426 = nil;
    stack[0] = v_11426;
v_11335:
    v_11426 = stack[-2];
    if (!consp(v_11426)) goto v_11346;
    else goto v_11347;
v_11346:
    v_11426 = lisp_true;
    goto v_11345;
v_11347:
    v_11426 = stack[-2];
    v_11426 = qcar(v_11426);
    v_11426 = (consp(v_11426) ? nil : lisp_true);
    goto v_11345;
    v_11426 = nil;
v_11345:
    if (v_11426 == nil) goto v_11342;
    else goto v_11343;
v_11342:
    goto v_11359;
v_11355:
    v_11426 = stack[-2];
    v_11426 = qcar(v_11426);
    v_11426 = qcar(v_11426);
    v_11427 = qcar(v_11426);
    goto v_11356;
v_11357:
    v_11426 = stack[-1];
    goto v_11358;
v_11359:
    goto v_11355;
v_11356:
    goto v_11357;
v_11358:
    v_11426 = (equal(v_11427, v_11426) ? lisp_true : nil);
    v_11426 = (v_11426 == nil ? lisp_true : nil);
    goto v_11341;
v_11343:
    v_11426 = nil;
    goto v_11341;
    v_11426 = nil;
v_11341:
    if (v_11426 == nil) goto v_11338;
    else goto v_11339;
v_11338:
    goto v_11334;
v_11339:
    goto v_11376;
v_11372:
    stack[-3] = stack[0];
    goto v_11373;
v_11374:
    goto v_11383;
v_11379:
    goto v_11389;
v_11385:
    v_11426 = stack[-2];
    v_11426 = qcar(v_11426);
    v_11426 = qcar(v_11426);
    v_11427 = qcar(v_11426);
    goto v_11386;
v_11387:
    v_11426 = stack[-2];
    v_11426 = qcar(v_11426);
    v_11426 = qcar(v_11426);
    v_11426 = qcdr(v_11426);
    goto v_11388;
v_11389:
    goto v_11385;
v_11386:
    goto v_11387;
v_11388:
    fn = elt(env, 2); // image!-of!-power
    stack[0] = (*qfn2(fn))(fn, v_11427, v_11426);
    env = stack[-4];
    goto v_11380;
v_11381:
    goto v_11403;
v_11399:
    v_11426 = stack[-2];
    v_11426 = qcar(v_11426);
    v_11427 = qcdr(v_11426);
    goto v_11400;
v_11401:
    v_11426 = stack[-1];
    goto v_11402;
v_11403:
    goto v_11399;
v_11400:
    goto v_11401;
v_11402:
    v_11426 = CC_makeKunivariateKimageKmodKp(elt(env, 0), v_11427, v_11426);
    env = stack[-4];
    goto v_11382;
v_11383:
    goto v_11379;
v_11380:
    goto v_11381;
v_11382:
    fn = elt(env, 3); // times!-mod!-p
    v_11426 = (*qfn2(fn))(fn, stack[0], v_11426);
    env = stack[-4];
    goto v_11375;
v_11376:
    goto v_11372;
v_11373:
    goto v_11374;
v_11375:
    fn = elt(env, 4); // plus!-mod!-p
    v_11426 = (*qfn2(fn))(fn, stack[-3], v_11426);
    env = stack[-4];
    stack[0] = v_11426;
    v_11426 = stack[-2];
    v_11426 = qcdr(v_11426);
    stack[-2] = v_11426;
    goto v_11335;
v_11334:
    goto v_11415;
v_11411:
    v_11427 = stack[-2];
    goto v_11412;
v_11413:
    v_11426 = stack[-1];
    goto v_11414;
v_11415:
    goto v_11411;
v_11412:
    goto v_11413;
v_11414:
    v_11426 = CC_makeKunivariateKimageKmodKp(elt(env, 0), v_11427, v_11426);
    env = stack[-4];
    stack[-2] = v_11426;
    goto v_11423;
v_11419:
    v_11427 = stack[0];
    goto v_11420;
v_11421:
    v_11426 = stack[-2];
    goto v_11422;
v_11423:
    goto v_11419;
v_11420:
    goto v_11421;
v_11422:
    {
        fn = elt(env, 4); // plus!-mod!-p
        return (*qfn2(fn))(fn, v_11427, v_11426);
    }
    v_11426 = nil;
v_11190:
    return onevalue(v_11426);
}



// Code for merge!-ind!-vars

static LispObject CC_mergeKindKvars(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11243, v_11244;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11185;
    stack[-1] = v_11184;
// end of prologue
    v_11243 = qvalue(elt(env, 1)); // !*nocommutedf
    if (v_11243 == nil) goto v_11191;
    else goto v_11189;
v_11191:
    v_11243 = qvalue(elt(env, 2)); // !*commutedf
    if (v_11243 == nil) goto v_11196;
    else goto v_11197;
v_11196:
    goto v_11203;
v_11199:
    v_11243 = stack[-1];
    v_11243 = qcdr(v_11243);
    stack[-2] = qcar(v_11243);
    goto v_11200;
v_11201:
    goto v_11212;
v_11208:
    v_11244 = stack[0];
    goto v_11209;
v_11210:
    v_11243 = stack[-1];
    v_11243 = qcdr(v_11243);
    v_11243 = qcdr(v_11243);
    goto v_11211;
v_11212:
    goto v_11208;
v_11209:
    goto v_11210;
v_11211:
    v_11243 = cons(v_11244, v_11243);
    env = stack[-3];
    goto v_11202;
v_11203:
    goto v_11199;
v_11200:
    goto v_11201;
v_11202:
    v_11243 = Lmemq(nil, stack[-2], v_11243);
    goto v_11195;
v_11197:
    v_11243 = nil;
    goto v_11195;
    v_11243 = nil;
v_11195:
    if (v_11243 == nil) goto v_11193;
    else goto v_11189;
v_11193:
    goto v_11190;
v_11189:
    goto v_11226;
v_11222:
    v_11244 = stack[0];
    goto v_11223;
v_11224:
    v_11243 = stack[-1];
    v_11243 = qcdr(v_11243);
    v_11243 = qcdr(v_11243);
    goto v_11225;
v_11226:
    goto v_11222;
v_11223:
    goto v_11224;
v_11225:
    {
        fn = elt(env, 3); // derad!*
        return (*qfn2(fn))(fn, v_11244, v_11243);
    }
v_11190:
    goto v_11238;
v_11234:
    v_11244 = stack[0];
    goto v_11235;
v_11236:
    v_11243 = stack[-1];
    v_11243 = qcdr(v_11243);
    v_11243 = qcdr(v_11243);
    goto v_11237;
v_11238:
    goto v_11234;
v_11235:
    goto v_11236;
v_11237:
    {
        fn = elt(env, 4); // derad
        return (*qfn2(fn))(fn, v_11244, v_11243);
    }
    v_11243 = nil;
    return onevalue(v_11243);
}



// Code for testredzz

static LispObject CC_testredzz(LispObject env,
                         LispObject v_11184)
{
    env = qenv(env);
    LispObject v_11226, v_11227;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11184);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_11226 = v_11184;
// end of prologue
    goto v_11194;
v_11190:
    goto v_11199;
v_11195:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_11196;
v_11197:
    goto v_11206;
v_11202:
    v_11227 = qvalue(elt(env, 2)); // maxvar
    goto v_11203;
v_11204:
    goto v_11205;
v_11206:
    goto v_11202;
v_11203:
    goto v_11204;
v_11205:
    v_11226 = plus2(v_11227, v_11226);
    env = stack[-1];
    goto v_11198;
v_11199:
    goto v_11195;
v_11196:
    goto v_11197;
v_11198:
    v_11227 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_11226-TAG_FIXNUM)/(16/CELL)));
    goto v_11191;
v_11192:
    v_11226 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_11193;
v_11194:
    goto v_11190;
v_11191:
    goto v_11192;
v_11193:
    v_11226 = *(LispObject *)((char *)v_11227 + (CELL-TAG_VECTOR) + (((intptr_t)v_11226-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_11226;
v_11189:
    v_11226 = stack[0];
    if (v_11226 == nil) goto v_11214;
    else goto v_11215;
v_11214:
    v_11226 = nil;
    goto v_11188;
v_11215:
    v_11226 = stack[0];
    v_11226 = qcar(v_11226);
    v_11226 = qcar(v_11226);
    fn = elt(env, 3); // testredh
    v_11226 = (*qfn1(fn))(fn, v_11226);
    env = stack[-1];
    v_11226 = stack[0];
    v_11226 = qcdr(v_11226);
    stack[0] = v_11226;
    goto v_11189;
v_11188:
    return onevalue(v_11226);
}



// Code for indexvarordp

static LispObject CC_indexvarordp(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11302, v_11303;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11185;
    stack[-1] = v_11184;
// end of prologue
    goto v_11199;
v_11195:
    v_11302 = stack[-1];
    v_11303 = qcar(v_11302);
    goto v_11196;
v_11197:
    v_11302 = stack[0];
    v_11302 = qcar(v_11302);
    goto v_11198;
v_11199:
    goto v_11195;
v_11196:
    goto v_11197;
v_11198:
    if (v_11303 == v_11302) goto v_11194;
    v_11302 = lisp_true;
    goto v_11192;
v_11194:
    goto v_11214;
v_11210:
    v_11303 = stack[-1];
    goto v_11211;
v_11212:
    v_11302 = qvalue(elt(env, 1)); // kord!*
    goto v_11213;
v_11214:
    goto v_11210;
v_11211:
    goto v_11212;
v_11213:
    v_11302 = Lmemq(nil, v_11303, v_11302);
    if (v_11302 == nil) goto v_11209;
    else goto v_11208;
v_11209:
    goto v_11222;
v_11218:
    v_11303 = stack[0];
    goto v_11219;
v_11220:
    v_11302 = qvalue(elt(env, 1)); // kord!*
    goto v_11221;
v_11222:
    goto v_11218;
v_11219:
    goto v_11220;
v_11221:
    v_11302 = Lmemq(nil, v_11303, v_11302);
v_11208:
    goto v_11192;
    v_11302 = nil;
v_11192:
    if (v_11302 == nil) goto v_11190;
    goto v_11231;
v_11227:
    v_11303 = stack[-1];
    goto v_11228;
v_11229:
    v_11302 = stack[0];
    goto v_11230;
v_11231:
    goto v_11227;
v_11228:
    goto v_11229;
v_11230:
    {
        fn = elt(env, 3); // ordop
        return (*qfn2(fn))(fn, v_11303, v_11302);
    }
v_11190:
    v_11302 = stack[-1];
    v_11302 = qcdr(v_11302);
    fn = elt(env, 4); // flatindxl
    stack[-2] = (*qfn1(fn))(fn, v_11302);
    env = stack[-3];
    v_11302 = stack[0];
    v_11302 = qcdr(v_11302);
    fn = elt(env, 4); // flatindxl
    v_11303 = (*qfn1(fn))(fn, v_11302);
    env = stack[-3];
    v_11302 = stack[-2];
    stack[-2] = v_11303;
    goto v_11253;
v_11249:
    v_11303 = v_11302;
    goto v_11250;
v_11251:
    v_11302 = qvalue(elt(env, 2)); // indxl!*
    goto v_11252;
v_11253:
    goto v_11249;
v_11250:
    goto v_11251;
v_11252:
    fn = elt(env, 5); // boundindp
    v_11302 = (*qfn2(fn))(fn, v_11303, v_11302);
    env = stack[-3];
    if (v_11302 == nil) goto v_11247;
    goto v_11265;
v_11261:
    v_11303 = stack[-2];
    goto v_11262;
v_11263:
    v_11302 = qvalue(elt(env, 2)); // indxl!*
    goto v_11264;
v_11265:
    goto v_11261;
v_11262:
    goto v_11263;
v_11264:
    fn = elt(env, 5); // boundindp
    v_11302 = (*qfn2(fn))(fn, v_11303, v_11302);
    env = stack[-3];
    if (v_11302 == nil) goto v_11259;
    goto v_11273;
v_11269:
    v_11302 = stack[-1];
    v_11303 = qcdr(v_11302);
    goto v_11270;
v_11271:
    v_11302 = stack[0];
    v_11302 = qcdr(v_11302);
    goto v_11272;
v_11273:
    goto v_11269;
v_11270:
    goto v_11271;
v_11272:
    {
        fn = elt(env, 6); // indordlp
        return (*qfn2(fn))(fn, v_11303, v_11302);
    }
v_11259:
    v_11302 = lisp_true;
    goto v_11257;
    v_11302 = nil;
v_11257:
    goto v_11245;
v_11247:
    goto v_11288;
v_11284:
    v_11303 = stack[-2];
    goto v_11285;
v_11286:
    v_11302 = qvalue(elt(env, 2)); // indxl!*
    goto v_11287;
v_11288:
    goto v_11284;
v_11285:
    goto v_11286;
v_11287:
    fn = elt(env, 5); // boundindp
    v_11302 = (*qfn2(fn))(fn, v_11303, v_11302);
    env = stack[-3];
    if (v_11302 == nil) goto v_11282;
    v_11302 = nil;
    goto v_11245;
v_11282:
    goto v_11299;
v_11295:
    v_11303 = stack[-1];
    goto v_11296;
v_11297:
    v_11302 = stack[0];
    goto v_11298;
v_11299:
    goto v_11295;
v_11296:
    goto v_11297;
v_11298:
    {
        fn = elt(env, 3); // ordop
        return (*qfn2(fn))(fn, v_11303, v_11302);
    }
    v_11302 = nil;
v_11245:
    goto v_11188;
    v_11302 = nil;
v_11188:
    return onevalue(v_11302);
}



// Code for inttovec!-solve

static LispObject CC_inttovecKsolve(LispObject env,
                         LispObject v_11184, LispObject v_11185)
{
    env = qenv(env);
    LispObject v_11286, v_11287;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11185,v_11184);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11184,v_11185);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_11185;
    stack[-3] = v_11184;
// end of prologue
    goto v_11199;
v_11195:
    v_11287 = stack[-2];
    goto v_11196;
v_11197:
    v_11286 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11198;
v_11199:
    goto v_11195;
v_11196:
    goto v_11197;
v_11198:
    if (v_11287 == v_11286) goto v_11193;
    else goto v_11194;
v_11193:
    v_11286 = lisp_true;
    goto v_11192;
v_11194:
    goto v_11209;
v_11205:
    v_11287 = stack[-3];
    goto v_11206;
v_11207:
    v_11286 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11208;
v_11209:
    goto v_11205;
v_11206:
    goto v_11207;
v_11208:
    v_11286 = (v_11287 == v_11286 ? lisp_true : nil);
    goto v_11192;
    v_11286 = nil;
v_11192:
    if (v_11286 == nil) goto v_11190;
    goto v_11218;
v_11214:
    v_11287 = stack[-2];
    goto v_11215;
v_11216:
    v_11286 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11217;
v_11218:
    goto v_11214;
v_11215:
    goto v_11216;
v_11217:
    return cons(v_11287, v_11286);
v_11190:
// Binding d
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = nil; // d
    v_11286 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_11286; // d
    v_11286 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_11286;
v_11232:
    v_11286 = stack[0];
    stack[-1] = v_11286;
    v_11286 = qvalue(elt(env, 1)); // d
    v_11286 = add1(v_11286);
    env = stack[-5];
    qvalue(elt(env, 1)) = v_11286; // d
    goto v_11241;
v_11237:
    goto v_11247;
v_11243:
    goto v_11253;
v_11249:
    v_11287 = stack[-3];
    goto v_11250;
v_11251:
    v_11286 = qvalue(elt(env, 1)); // d
    goto v_11252;
v_11253:
    goto v_11249;
v_11250:
    goto v_11251;
v_11252:
    v_11287 = plus2(v_11287, v_11286);
    env = stack[-5];
    goto v_11244;
v_11245:
    v_11286 = stack[-1];
    goto v_11246;
v_11247:
    goto v_11243;
v_11244:
    goto v_11245;
v_11246:
    v_11287 = times2(v_11287, v_11286);
    env = stack[-5];
    goto v_11238;
v_11239:
    v_11286 = qvalue(elt(env, 1)); // d
    goto v_11240;
v_11241:
    goto v_11237;
v_11238:
    goto v_11239;
v_11240:
    v_11286 = quot2(v_11287, v_11286);
    env = stack[-5];
    stack[0] = v_11286;
    goto v_11268;
v_11264:
    v_11287 = stack[0];
    goto v_11265;
v_11266:
    v_11286 = stack[-2];
    goto v_11267;
v_11268:
    goto v_11264;
v_11265:
    goto v_11266;
v_11267:
    v_11286 = (LispObject)greaterp2(v_11287, v_11286);
    v_11286 = v_11286 ? lisp_true : nil;
    env = stack[-5];
    if (v_11286 == nil) goto v_11261;
    else goto v_11262;
v_11261:
    goto v_11232;
v_11262:
    goto v_11276;
v_11272:
    stack[0] = qvalue(elt(env, 1)); // d
    goto v_11273;
v_11274:
    goto v_11283;
v_11279:
    v_11287 = stack[-2];
    goto v_11280;
v_11281:
    v_11286 = stack[-1];
    goto v_11282;
v_11283:
    goto v_11279;
v_11280:
    goto v_11281;
v_11282:
    v_11286 = difference2(v_11287, v_11286);
    env = stack[-5];
    goto v_11275;
v_11276:
    goto v_11272;
v_11273:
    goto v_11274;
v_11275:
    v_11286 = cons(stack[0], v_11286);
    ;}  // end of a binding scope
    goto v_11188;
    v_11286 = nil;
v_11188:
    return onevalue(v_11286);
}



setup_type const u20_setup[] =
{
    {"ir2om",                   CC_ir2om,       TOO_MANY_1,    WRONG_NO_1},
    {"groebcplistsortin",       TOO_FEW_2,      CC_groebcplistsortin,WRONG_NO_2},
    {"assert_uninstall",        CC_assert_uninstall,TOO_MANY_1,WRONG_NO_1},
    {"mo_times_ei",             TOO_FEW_2,      CC_mo_times_ei,WRONG_NO_2},
    {"th_match",                TOO_FEW_2,      CC_th_match,   WRONG_NO_2},
    {"arplus:",                 TOO_FEW_2,      CC_arplusT,    WRONG_NO_2},
    {"subf1",                   TOO_FEW_2,      CC_subf1,      WRONG_NO_2},
    {"decprec2internal",        CC_decprec2internal,TOO_MANY_1,WRONG_NO_1},
    {"triplesetprolongset",     TOO_FEW_2,      CC_triplesetprolongset,WRONG_NO_2},
    {"rl_csimpl",               CC_rl_csimpl,   TOO_MANY_1,    WRONG_NO_1},
    {"talp_invn",               CC_talp_invn,   TOO_MANY_1,    WRONG_NO_1},
    {"lx2xx",                   CC_lx2xx,       TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_var-unsatlist",     TOO_FEW_2,      CC_ibalp_varKunsatlist,WRONG_NO_2},
    {"dvfsf_susitf",            TOO_FEW_2,      CC_dvfsf_susitf,WRONG_NO_2},
    {"stats_getargs",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_stats_getargs},
    {"list-mgen",               CC_listKmgen,   TOO_MANY_1,    WRONG_NO_1},
    {"prinfit",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_prinfit},
    {"lispassignp",             CC_lispassignp, TOO_MANY_1,    WRONG_NO_1},
    {"assert_uninstall1",       CC_assert_uninstall1,TOO_MANY_1,WRONG_NO_1},
    {"evalequal",               TOO_FEW_2,      CC_evalequal,  WRONG_NO_2},
    {"mv2sf1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mv2sf1},
    {"setk0",                   TOO_FEW_2,      CC_setk0,      WRONG_NO_2},
    {"next-random-number",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_nextKrandomKnumber},
    {"print_with_margin_sub",   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_print_with_margin_sub},
    {"cl_nnf",                  CC_cl_nnf,      TOO_MANY_1,    WRONG_NO_1},
    {"subsublis",               TOO_FEW_2,      CC_subsublis,  WRONG_NO_2},
    {"token-number",            CC_tokenKnumber,TOO_MANY_1,    WRONG_NO_1},
    {"applyrd",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_applyrd},
    {"ps:minusp:",              CC_psTminuspT,  TOO_MANY_1,    WRONG_NO_1},
    {"arg2of2",                 TOO_FEW_2,      CC_arg2of2,    WRONG_NO_2},
    {"cut:mt",                  TOO_FEW_2,      CC_cutTmt,     WRONG_NO_2},
    {"contr2-strand",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_contr2Kstrand},
    {"assert_install",          CC_assert_install,TOO_MANY_1,  WRONG_NO_1},
    {"rnminusp:",               CC_rnminuspT,   TOO_MANY_1,    WRONG_NO_1},
    {"qremd",                   TOO_FEW_2,      CC_qremd,      WRONG_NO_2},
    {"reverse-num",             CC_reverseKnum, TOO_MANY_1,    WRONG_NO_1},
    {"quotient-mod-p",          TOO_FEW_2,      CC_quotientKmodKp,WRONG_NO_2},
    {"lto_max1",                CC_lto_max1,    TOO_MANY_1,    WRONG_NO_1},
    {"mapins",                  TOO_FEW_2,      CC_mapins,     WRONG_NO_2},
    {"ibalp_tvb",               TOO_FEW_2,      CC_ibalp_tvb,  WRONG_NO_2},
    {"aex_fvarl",               CC_aex_fvarl,   TOO_MANY_1,    WRONG_NO_1},
    {"make-univariate-image-mod-p",TOO_FEW_2,   CC_makeKunivariateKimageKmodKp,WRONG_NO_2},
    {"merge-ind-vars",          TOO_FEW_2,      CC_mergeKindKvars,WRONG_NO_2},
    {"testredzz",               CC_testredzz,   TOO_MANY_1,    WRONG_NO_1},
    {"indexvarordp",            TOO_FEW_2,      CC_indexvarordp,WRONG_NO_2},
    {"inttovec-solve",          TOO_FEW_2,      CC_inttovecKsolve,WRONG_NO_2},
    {NULL, (one_args *)"u20", (two_args *)"73091 5186985 4893354", 0}
};

// end of generated code
