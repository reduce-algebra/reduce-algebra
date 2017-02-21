
// $destdir/u42.c        Machine generated C code

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



// Code for mk_binding

static LispObject CC_mk_binding(LispObject env,
                         LispObject v_23828, LispObject v_23829)
{
    env = qenv(env);
    LispObject v_23856, v_23857;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23829,v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23828,v_23829);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_23829;
    stack[-1] = v_23828;
// end of prologue
    goto v_23840;
v_23836:
    v_23856 = stack[-1];
    v_23857 = qcar(v_23856);
    goto v_23837;
v_23838:
    v_23856 = stack[0];
    goto v_23839;
v_23840:
    goto v_23836;
v_23837:
    goto v_23838;
v_23839:
    fn = elt(env, 1); // can_be_proved
    v_23856 = (*qfn2(fn))(fn, v_23857, v_23856);
    env = stack[-2];
    if (v_23856 == nil) goto v_23833;
    else goto v_23834;
v_23833:
    v_23856 = nil;
    goto v_23832;
v_23834:
    goto v_23852;
v_23848:
    v_23856 = stack[-1];
    v_23857 = qcdr(v_23856);
    goto v_23849;
v_23850:
    v_23856 = stack[0];
    goto v_23851;
v_23852:
    goto v_23848;
v_23849:
    goto v_23850;
v_23851:
    {
        fn = elt(env, 2); // edge_bind
        return (*qfn2(fn))(fn, v_23857, v_23856);
    }
    v_23856 = nil;
v_23832:
    return onevalue(v_23856);
}



// Code for ratnump

static LispObject CC_ratnump(LispObject env,
                         LispObject v_23828)
{
    env = qenv(env);
    LispObject v_23860, v_23861, v_23862;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23828);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_23860 = v_23828;
// end of prologue
    fn = elt(env, 2); // simp!*
    v_23861 = (*qfn1(fn))(fn, v_23860);
    env = stack[0];
    v_23860 = v_23861;
    v_23861 = qcar(v_23861);
    if (!consp(v_23861)) goto v_23836;
    else goto v_23837;
v_23836:
    v_23861 = lisp_true;
    goto v_23835;
v_23837:
    goto v_23848;
v_23844:
    v_23861 = v_23860;
    v_23861 = qcar(v_23861);
    v_23861 = qcar(v_23861);
    goto v_23845;
v_23846:
    v_23862 = elt(env, 1); // !:rn!:
    goto v_23847;
v_23848:
    goto v_23844;
v_23845:
    goto v_23846;
v_23847:
    v_23861 = (v_23861 == v_23862 ? lisp_true : nil);
    goto v_23835;
    v_23861 = nil;
v_23835:
    if (v_23861 == nil) goto v_23833;
    v_23860 = qcdr(v_23860);
    v_23860 = (consp(v_23860) ? nil : lisp_true);
    goto v_23831;
v_23833:
    v_23860 = nil;
    goto v_23831;
    v_23860 = nil;
v_23831:
    return onevalue(v_23860);
}



// Code for miller!-rabin

static LispObject CC_millerKrabin(LispObject env,
                         LispObject v_23828, LispObject v_23829)
{
    env = qenv(env);
    LispObject v_24010, v_24011;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23829,v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23828,v_23829);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_23829;
    stack[0] = v_23828;
// end of prologue
// Binding d
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = nil; // d
    goto v_23845;
v_23841:
    v_24011 = stack[-3];
    goto v_23842;
v_23843:
    v_24010 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23844;
v_23845:
    goto v_23841;
v_23842:
    goto v_23843;
v_23844:
    if (v_24011 == v_24010) goto v_23839;
    else goto v_23840;
v_23839:
    v_24010 = nil;
    goto v_23835;
v_23840:
    goto v_23855;
v_23851:
    goto v_23861;
v_23857:
    v_24011 = stack[-3];
    goto v_23858;
v_23859:
    v_24010 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_23860;
v_23861:
    goto v_23857;
v_23858:
    goto v_23859;
v_23860:
    v_24011 = Cremainder(v_24011, v_24010);
    env = stack[-5];
    goto v_23852;
v_23853:
    v_24010 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23854;
v_23855:
    goto v_23851;
v_23852:
    goto v_23853;
v_23854:
    if (v_24011 == v_24010) goto v_23849;
    else goto v_23850;
v_23849:
    goto v_23869;
v_23865:
    v_24011 = stack[-3];
    goto v_23866;
v_23867:
    v_24010 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_23868;
v_23869:
    goto v_23865;
v_23866:
    goto v_23867;
v_23868:
    v_24010 = (v_24011 == v_24010 ? lisp_true : nil);
    goto v_23835;
v_23850:
    goto v_23880;
v_23876:
    v_24011 = stack[-3];
    goto v_23877;
v_23878:
    v_24010 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_23879;
v_23880:
    goto v_23876;
v_23877:
    goto v_23878;
v_23879:
    v_24010 = (LispObject)lesseq2(v_24011, v_24010);
    v_24010 = v_24010 ? lisp_true : nil;
    env = stack[-5];
    if (v_24010 == nil) goto v_23874;
    v_24010 = lisp_true;
    goto v_23835;
v_23874:
    v_24010 = stack[-3];
    v_24010 = sub1(v_24010);
    env = stack[-5];
    qvalue(elt(env, 1)) = v_24010; // d
    v_24010 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_24010;
v_23889:
    goto v_23898;
v_23894:
    goto v_23904;
v_23900:
    v_24011 = qvalue(elt(env, 1)); // d
    goto v_23901;
v_23902:
    v_24010 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_23903;
v_23904:
    goto v_23900;
v_23901:
    goto v_23902;
v_23903:
    v_24011 = Cremainder(v_24011, v_24010);
    env = stack[-5];
    goto v_23895;
v_23896:
    v_24010 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23897;
v_23898:
    goto v_23894;
v_23895:
    goto v_23896;
v_23897:
    if (v_24011 == v_24010) goto v_23893;
    goto v_23888;
v_23893:
    goto v_23914;
v_23910:
    v_24011 = qvalue(elt(env, 1)); // d
    goto v_23911;
v_23912:
    v_24010 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_23913;
v_23914:
    goto v_23910;
v_23911:
    goto v_23912;
v_23913:
    v_24010 = quot2(v_24011, v_24010);
    env = stack[-5];
    qvalue(elt(env, 1)) = v_24010; // d
    v_24010 = stack[-2];
    v_24010 = add1(v_24010);
    env = stack[-5];
    stack[-2] = v_24010;
    goto v_23889;
v_23888:
    v_24010 = stack[-3];
    fn = elt(env, 2); // set!-modulus
    v_24010 = (*qfn1(fn))(fn, v_24010);
    env = stack[-5];
    goto v_23926;
v_23922:
    v_24011 = stack[0];
    goto v_23923;
v_23924:
    v_24010 = stack[-3];
    goto v_23925;
v_23926:
    goto v_23922;
v_23923:
    goto v_23924;
v_23925:
    v_24010 = Cremainder(v_24011, v_24010);
    env = stack[-5];
    stack[0] = v_24010;
    goto v_23934;
v_23930:
    v_24011 = stack[0];
    goto v_23931;
v_23932:
    v_24010 = qvalue(elt(env, 1)); // d
    goto v_23933;
v_23934:
    goto v_23930;
v_23931:
    goto v_23932;
v_23933:
    v_24010 = Lmodular_expt(nil, v_24011, v_24010);
    env = stack[-5];
    stack[-1] = v_24010;
    goto v_23949;
v_23945:
    v_24011 = stack[-1];
    goto v_23946;
v_23947:
    v_24010 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23948;
v_23949:
    goto v_23945;
v_23946:
    goto v_23947;
v_23948:
    if (v_24011 == v_24010) goto v_23943;
    else goto v_23944;
v_23943:
    v_24010 = lisp_true;
    goto v_23942;
v_23944:
    goto v_23959;
v_23955:
    stack[0] = stack[-1];
    goto v_23956;
v_23957:
    v_24010 = stack[-3];
    v_24010 = sub1(v_24010);
    env = stack[-5];
    goto v_23958;
v_23959:
    goto v_23955;
v_23956:
    goto v_23957;
v_23958:
    v_24010 = (equal(stack[0], v_24010) ? lisp_true : nil);
    goto v_23942;
    v_24010 = nil;
v_23942:
    if (v_24010 == nil) goto v_23940;
    v_24010 = lisp_true;
    goto v_23835;
v_23940:
v_23836:
    goto v_23973;
v_23969:
    v_24011 = stack[-2];
    goto v_23970;
v_23971:
    v_24010 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23972;
v_23973:
    goto v_23969;
v_23970:
    goto v_23971;
v_23972:
    if (v_24011 == v_24010) goto v_23967;
    else goto v_23968;
v_23967:
    v_24010 = nil;
    goto v_23835;
v_23968:
    goto v_23982;
v_23978:
    v_24011 = stack[-1];
    goto v_23979;
v_23980:
    v_24010 = stack[-1];
    goto v_23981;
v_23982:
    goto v_23978;
v_23979:
    goto v_23980;
v_23981:
    v_24010 = Lmodular_times(nil, v_24011, v_24010);
    env = stack[-5];
    stack[-1] = v_24010;
    goto v_23993;
v_23989:
    v_24011 = stack[-1];
    goto v_23990;
v_23991:
    v_24010 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23992;
v_23993:
    goto v_23989;
v_23990:
    goto v_23991;
v_23992:
    if (v_24011 == v_24010) goto v_23987;
    else goto v_23988;
v_23987:
    v_24010 = nil;
    goto v_23835;
v_23988:
    goto v_24003;
v_23999:
    stack[0] = stack[-1];
    goto v_24000;
v_24001:
    v_24010 = stack[-3];
    v_24010 = sub1(v_24010);
    env = stack[-5];
    goto v_24002;
v_24003:
    goto v_23999;
v_24000:
    goto v_24001;
v_24002:
    if (equal(stack[0], v_24010)) goto v_23997;
    else goto v_23998;
v_23997:
    v_24010 = lisp_true;
    goto v_23835;
v_23998:
    v_24010 = stack[-2];
    v_24010 = sub1(v_24010);
    env = stack[-5];
    stack[-2] = v_24010;
    goto v_23836;
v_23835:
    ;}  // end of a binding scope
    return onevalue(v_24010);
}



// Code for equiv!-coeffs

static LispObject CC_equivKcoeffs(LispObject env,
                         LispObject v_23828, LispObject v_23829)
{
    env = qenv(env);
    LispObject v_23910, v_23911;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23829,v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23828,v_23829);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_23829;
    stack[-1] = v_23828;
// end of prologue
    stack[-2] = nil;
v_23834:
    v_23910 = stack[-1];
    if (v_23910 == nil) goto v_23837;
    else goto v_23838;
v_23837:
    goto v_23845;
v_23841:
    stack[-1] = stack[-2];
    goto v_23842;
v_23843:
    v_23910 = stack[0];
    v_23910 = Llength(nil, v_23910);
    env = stack[-3];
    fn = elt(env, 1); // nzeros
    v_23910 = (*qfn1(fn))(fn, v_23910);
    env = stack[-3];
    goto v_23844;
v_23845:
    goto v_23841;
v_23842:
    goto v_23843;
v_23844:
    {
        LispObject v_23915 = stack[-1];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_23915, v_23910);
    }
v_23838:
    v_23910 = stack[0];
    if (v_23910 == nil) goto v_23850;
    else goto v_23851;
v_23850:
    v_23910 = stack[-2];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_23910);
    }
v_23851:
    goto v_23861;
v_23857:
    v_23910 = stack[-1];
    v_23910 = qcar(v_23910);
    v_23911 = qcar(v_23910);
    goto v_23858;
v_23859:
    v_23910 = stack[0];
    v_23910 = qcar(v_23910);
    v_23910 = qcar(v_23910);
    goto v_23860;
v_23861:
    goto v_23857;
v_23858:
    goto v_23859;
v_23860:
    if (equal(v_23911, v_23910)) goto v_23855;
    else goto v_23856;
v_23855:
    goto v_23873;
v_23869:
    v_23910 = stack[-1];
    v_23910 = qcar(v_23910);
    v_23911 = qcdr(v_23910);
    goto v_23870;
v_23871:
    v_23910 = stack[-2];
    goto v_23872;
v_23873:
    goto v_23869;
v_23870:
    goto v_23871;
v_23872:
    v_23910 = cons(v_23911, v_23910);
    env = stack[-3];
    stack[-2] = v_23910;
    v_23910 = stack[-1];
    v_23910 = qcdr(v_23910);
    stack[-1] = v_23910;
    v_23910 = stack[0];
    v_23910 = qcdr(v_23910);
    stack[0] = v_23910;
    goto v_23834;
v_23856:
    goto v_23889;
v_23885:
    v_23910 = stack[-1];
    v_23910 = qcar(v_23910);
    v_23911 = qcar(v_23910);
    goto v_23886;
v_23887:
    v_23910 = stack[0];
    v_23910 = qcar(v_23910);
    v_23910 = qcar(v_23910);
    goto v_23888;
v_23889:
    goto v_23885;
v_23886:
    goto v_23887;
v_23888:
    fn = elt(env, 3); // mv!-pow!-!>
    v_23910 = (*qfn2(fn))(fn, v_23911, v_23910);
    env = stack[-3];
    if (v_23910 == nil) goto v_23883;
    v_23910 = stack[-1];
    v_23910 = qcdr(v_23910);
    stack[-1] = v_23910;
    goto v_23834;
v_23883:
    goto v_23905;
v_23901:
    v_23911 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23902;
v_23903:
    v_23910 = stack[-2];
    goto v_23904;
v_23905:
    goto v_23901;
v_23902:
    goto v_23903;
v_23904:
    v_23910 = cons(v_23911, v_23910);
    env = stack[-3];
    stack[-2] = v_23910;
    v_23910 = stack[0];
    v_23910 = qcdr(v_23910);
    stack[0] = v_23910;
    goto v_23834;
    v_23910 = nil;
    return onevalue(v_23910);
}



// Code for !*g2lex

static LispObject CC_Hg2lex(LispObject env,
                         LispObject v_23828)
{
    env = qenv(env);
    LispObject v_23869, v_23870;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23828);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_23869 = v_23828;
// end of prologue
    v_23870 = nil;
    stack[-1] = v_23869;
v_23836:
    v_23869 = stack[-1];
    if (v_23869 == nil) goto v_23840;
    else goto v_23841;
v_23840:
    goto v_23835;
v_23841:
    v_23869 = stack[-1];
    v_23869 = qcar(v_23869);
    goto v_23852;
v_23848:
    stack[0] = v_23870;
    goto v_23849;
v_23850:
    goto v_23860;
v_23856:
    v_23870 = v_23869;
    v_23870 = qcar(v_23870);
    v_23870 = qcdr(v_23870);
    goto v_23857;
v_23858:
    v_23869 = qcdr(v_23869);
    goto v_23859;
v_23860:
    goto v_23856;
v_23857:
    goto v_23858;
v_23859:
    v_23869 = cons(v_23870, v_23869);
    env = stack[-2];
    v_23869 = ncons(v_23869);
    env = stack[-2];
    goto v_23851;
v_23852:
    goto v_23848;
v_23849:
    goto v_23850;
v_23851:
    fn = elt(env, 1); // psum
    v_23869 = (*qfn2(fn))(fn, stack[0], v_23869);
    env = stack[-2];
    v_23870 = v_23869;
    v_23869 = stack[-1];
    v_23869 = qcdr(v_23869);
    stack[-1] = v_23869;
    goto v_23836;
v_23835:
    v_23869 = v_23870;
    return onevalue(v_23869);
}



// Code for simpquot

static LispObject CC_simpquot(LispObject env,
                         LispObject v_23828)
{
    env = qenv(env);
    LispObject v_24018, v_24019, v_24020;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23828);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_23828;
// end of prologue
    v_24018 = stack[-1];
    fn = elt(env, 7); // simpcar
    stack[0] = (*qfn1(fn))(fn, v_24018);
    env = stack[-3];
    v_24018 = stack[-1];
    v_24018 = qcdr(v_24018);
    v_24018 = qcar(v_24018);
    fn = elt(env, 8); // simp
    v_24018 = (*qfn1(fn))(fn, v_24018);
    env = stack[-3];
    stack[-2] = stack[0];
    stack[0] = v_24018;
    v_24018 = stack[0];
    v_24018 = qcar(v_24018);
    if (v_24018 == nil) goto v_23840;
    else goto v_23841;
v_23840:
    v_24018 = stack[-2];
    v_24018 = qcar(v_24018);
    if (v_24018 == nil) goto v_23846;
    else goto v_23847;
v_23846:
    goto v_23857;
v_23851:
    v_24020 = elt(env, 1); // alg
    goto v_23852;
v_23853:
    v_24019 = (LispObject)304+TAG_FIXNUM; // 19
    goto v_23854;
v_23855:
    v_24018 = elt(env, 2); // "0/0 formed"
    goto v_23856;
v_23857:
    goto v_23851;
v_23852:
    goto v_23853;
v_23854:
    goto v_23855;
v_23856:
    {
        fn = elt(env, 9); // rerror
        return (*qfnn(fn))(fn, 3, v_24020, v_24019, v_24018);
    }
v_23847:
    goto v_23870;
v_23864:
    v_24020 = elt(env, 1); // alg
    goto v_23865;
v_23866:
    v_24019 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_23867;
v_23868:
    v_24018 = elt(env, 3); // "Zero divisor"
    goto v_23869;
v_23870:
    goto v_23864;
v_23865:
    goto v_23866;
v_23867:
    goto v_23868;
v_23869:
    {
        fn = elt(env, 9); // rerror
        return (*qfnn(fn))(fn, 3, v_24020, v_24019, v_24018);
    }
    v_24018 = nil;
    goto v_23839;
v_23841:
    goto v_23881;
v_23877:
    v_24019 = qvalue(elt(env, 4)); // dmode!*
    goto v_23878;
v_23879:
    v_24018 = elt(env, 5); // (!:rd!: !:cr!:)
    goto v_23880;
v_23881:
    goto v_23877;
v_23878:
    goto v_23879;
v_23880:
    v_24018 = Lmemq(nil, v_24019, v_24018);
    if (v_24018 == nil) goto v_23875;
    v_24018 = stack[0];
    v_24018 = qcar(v_24018);
    if (!consp(v_24018)) goto v_23892;
    else goto v_23893;
v_23892:
    v_24018 = lisp_true;
    goto v_23891;
v_23893:
    v_24018 = stack[0];
    v_24018 = qcar(v_24018);
    v_24018 = qcar(v_24018);
    v_24018 = (consp(v_24018) ? nil : lisp_true);
    goto v_23891;
    v_24018 = nil;
v_23891:
    if (v_24018 == nil) goto v_23889;
    v_24018 = stack[0];
    v_24018 = qcdr(v_24018);
    if (!consp(v_24018)) goto v_23909;
    else goto v_23910;
v_23909:
    v_24018 = lisp_true;
    goto v_23908;
v_23910:
    v_24018 = stack[0];
    v_24018 = qcdr(v_24018);
    v_24018 = qcar(v_24018);
    v_24018 = (consp(v_24018) ? nil : lisp_true);
    goto v_23908;
    v_24018 = nil;
v_23908:
    if (v_24018 == nil) goto v_23906;
    v_24018 = stack[-2];
    v_24018 = qcdr(v_24018);
    if (!consp(v_24018)) goto v_23926;
    else goto v_23927;
v_23926:
    v_24018 = lisp_true;
    goto v_23925;
v_23927:
    v_24018 = stack[-2];
    v_24018 = qcdr(v_24018);
    v_24018 = qcar(v_24018);
    v_24018 = (consp(v_24018) ? nil : lisp_true);
    goto v_23925;
    v_24018 = nil;
v_23925:
    if (v_24018 == nil) goto v_23923;
    v_24018 = stack[0];
    v_24018 = qcdr(v_24018);
    fn = elt(env, 10); // !:onep
    v_24018 = (*qfn1(fn))(fn, v_24018);
    env = stack[-3];
    if (v_24018 == nil) goto v_23939;
    else goto v_23940;
v_23939:
    v_24018 = nil;
    goto v_23938;
v_23940:
    v_24018 = stack[-2];
    v_24018 = qcdr(v_24018);
    fn = elt(env, 10); // !:onep
    v_24018 = (*qfn1(fn))(fn, v_24018);
    env = stack[-3];
    goto v_23938;
    v_24018 = nil;
v_23938:
    goto v_23921;
v_23923:
    v_24018 = nil;
    goto v_23921;
    v_24018 = nil;
v_23921:
    goto v_23904;
v_23906:
    v_24018 = nil;
    goto v_23904;
    v_24018 = nil;
v_23904:
    goto v_23887;
v_23889:
    v_24018 = nil;
    goto v_23887;
    v_24018 = nil;
v_23887:
    if (v_24018 == nil) goto v_23875;
    goto v_23964;
v_23960:
    v_24018 = stack[-2];
    v_24018 = qcar(v_24018);
    if (v_24018 == nil) goto v_23967;
    else goto v_23968;
v_23967:
    v_24018 = nil;
    v_24019 = v_24018;
    goto v_23966;
v_23968:
    goto v_23979;
v_23975:
    v_24018 = stack[-2];
    v_24019 = qcar(v_24018);
    goto v_23976;
v_23977:
    v_24018 = stack[0];
    v_24018 = qcar(v_24018);
    goto v_23978;
v_23979:
    goto v_23975;
v_23976:
    goto v_23977;
v_23978:
    fn = elt(env, 11); // divd
    v_24018 = (*qfn2(fn))(fn, v_24019, v_24018);
    v_24019 = v_24018;
    goto v_23966;
    v_24019 = nil;
v_23966:
    goto v_23961;
v_23962:
    v_24018 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23963;
v_23964:
    goto v_23960;
v_23961:
    goto v_23962;
v_23963:
    return cons(v_24019, v_24018);
v_23875:
    goto v_23992;
v_23988:
    stack[0] = stack[-2];
    goto v_23989;
v_23990:
    v_24018 = stack[-1];
    v_24018 = qcdr(v_24018);
    fn = elt(env, 12); // simprecip
    v_24018 = (*qfn1(fn))(fn, v_24018);
    env = stack[-3];
    goto v_23991;
v_23992:
    goto v_23988;
v_23989:
    goto v_23990;
v_23991:
    fn = elt(env, 13); // multsq
    v_24018 = (*qfn2(fn))(fn, stack[0], v_24018);
    env = stack[-3];
    stack[-1] = v_24018;
    v_24018 = qvalue(elt(env, 6)); // !*modular
    if (v_24018 == nil) goto v_24000;
    v_24018 = stack[-1];
    v_24018 = qcdr(v_24018);
    if (v_24018 == nil) goto v_24003;
    else goto v_24000;
v_24003:
    goto v_24013;
v_24007:
    v_24020 = elt(env, 1); // alg
    goto v_24008;
v_24009:
    v_24019 = (LispObject)3216+TAG_FIXNUM; // 201
    goto v_24010;
v_24011:
    v_24018 = elt(env, 3); // "Zero divisor"
    goto v_24012;
v_24013:
    goto v_24007;
v_24008:
    goto v_24009;
v_24010:
    goto v_24011;
v_24012:
    fn = elt(env, 9); // rerror
    v_24018 = (*qfnn(fn))(fn, 3, v_24020, v_24019, v_24018);
    goto v_23998;
v_24000:
v_23998:
    v_24018 = stack[-1];
    goto v_23839;
    v_24018 = nil;
v_23839:
    return onevalue(v_24018);
}



// Code for isimp1

static LispObject CC_isimp1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24004, v_24005, v_24006, v_24007, v_24008;
    LispObject fn;
    LispObject v_23832, v_23831, v_23830, v_23829, v_23828;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "isimp1");
    va_start(aa, nargs);
    v_23828 = va_arg(aa, LispObject);
    v_23829 = va_arg(aa, LispObject);
    v_23830 = va_arg(aa, LispObject);
    v_23831 = va_arg(aa, LispObject);
    v_23832 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_23832,v_23831,v_23830,v_23829,v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_23828,v_23829,v_23830,v_23831,v_23832);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[0] = v_23832;
    stack[-1] = v_23831;
    stack[-2] = v_23830;
    stack[-3] = v_23829;
    stack[-4] = v_23828;
// end of prologue
    v_24004 = stack[-4];
    if (v_24004 == nil) goto v_23836;
    else goto v_23837;
v_23836:
    v_24004 = nil;
    goto v_23835;
v_23837:
    v_24004 = stack[-4];
    if (!consp(v_24004)) goto v_23844;
    else goto v_23845;
v_23844:
    v_24004 = lisp_true;
    goto v_23843;
v_23845:
    v_24004 = stack[-4];
    v_24004 = qcar(v_24004);
    v_24004 = (consp(v_24004) ? nil : lisp_true);
    goto v_23843;
    v_24004 = nil;
v_23843:
    if (v_24004 == nil) goto v_23841;
    v_24004 = stack[0];
    if (v_24004 == nil) goto v_23856;
    goto v_23863;
v_23859:
    goto v_23860;
v_23861:
    v_24004 = qvalue(elt(env, 1)); // !*cvit
    if (v_24004 == nil) goto v_23868;
    goto v_23879;
v_23871:
    v_24007 = stack[-3];
    goto v_23872;
v_23873:
    v_24006 = stack[-2];
    goto v_23874;
v_23875:
    v_24005 = stack[-1];
    goto v_23876;
v_23877:
    v_24004 = stack[0];
    goto v_23878;
v_23879:
    goto v_23871;
v_23872:
    goto v_23873;
v_23874:
    goto v_23875;
v_23876:
    goto v_23877;
v_23878:
    fn = elt(env, 2); // calc_spurx
    v_24004 = (*qfnn(fn))(fn, 4, v_24007, v_24006, v_24005, v_24004);
    env = stack[-6];
    goto v_23866;
v_23868:
    goto v_23897;
v_23887:
    v_24004 = stack[0];
    v_24008 = qcar(v_24004);
    goto v_23888;
v_23889:
    v_24007 = stack[-3];
    goto v_23890;
v_23891:
    v_24006 = stack[-2];
    goto v_23892;
v_23893:
    v_24005 = stack[-1];
    goto v_23894;
v_23895:
    v_24004 = stack[0];
    v_24004 = qcdr(v_24004);
    goto v_23896;
v_23897:
    goto v_23887;
v_23888:
    goto v_23889;
v_23890:
    goto v_23891;
v_23892:
    goto v_23893;
v_23894:
    goto v_23895;
v_23896:
    fn = elt(env, 3); // spur0
    v_24004 = (*qfnn(fn))(fn, 5, v_24008, v_24007, v_24006, v_24005, v_24004);
    env = stack[-6];
    goto v_23866;
    v_24004 = nil;
v_23866:
    goto v_23862;
v_23863:
    goto v_23859;
v_23860:
    goto v_23861;
v_23862:
    {
        LispObject v_24015 = stack[-4];
        fn = elt(env, 4); // multd
        return (*qfn2(fn))(fn, v_24015, v_24004);
    }
v_23856:
    v_24004 = stack[-2];
    if (v_24004 == nil) goto v_23906;
    goto v_23913;
v_23909:
    stack[0] = stack[-4];
    goto v_23910;
v_23911:
    goto v_23924;
v_23916:
    v_24007 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23917;
v_23918:
    v_24006 = stack[-3];
    goto v_23919;
v_23920:
    v_24005 = stack[-2];
    goto v_23921;
v_23922:
    v_24004 = stack[-1];
    goto v_23923;
v_23924:
    goto v_23916;
v_23917:
    goto v_23918;
v_23919:
    goto v_23920;
v_23921:
    goto v_23922;
v_23923:
    fn = elt(env, 5); // index_simp
    v_24004 = (*qfnn(fn))(fn, 4, v_24007, v_24006, v_24005, v_24004);
    env = stack[-6];
    goto v_23912;
v_23913:
    goto v_23909;
v_23910:
    goto v_23911;
v_23912:
    {
        LispObject v_24016 = stack[0];
        fn = elt(env, 4); // multd
        return (*qfn2(fn))(fn, v_24016, v_24004);
    }
v_23906:
    v_24004 = stack[-1];
    if (v_24004 == nil) goto v_23930;
    goto v_23937;
v_23933:
    v_24004 = stack[-1];
    fn = elt(env, 6); // emult
    stack[0] = (*qfn1(fn))(fn, v_24004);
    env = stack[-6];
    goto v_23934;
v_23935:
    goto v_23951;
v_23941:
    v_24008 = stack[-4];
    goto v_23942;
v_23943:
    v_24007 = stack[-3];
    goto v_23944;
v_23945:
    v_24006 = stack[-2];
    goto v_23946;
v_23947:
    v_24005 = nil;
    goto v_23948;
v_23949:
    v_24004 = nil;
    goto v_23950;
v_23951:
    goto v_23941;
v_23942:
    goto v_23943;
v_23944:
    goto v_23945;
v_23946:
    goto v_23947;
v_23948:
    goto v_23949;
v_23950:
    v_24004 = CC_isimp1(elt(env, 0), 5, v_24008, v_24007, v_24006, v_24005, v_24004);
    env = stack[-6];
    goto v_23936;
v_23937:
    goto v_23933;
v_23934:
    goto v_23935;
v_23936:
    {
        LispObject v_24017 = stack[0];
        fn = elt(env, 7); // multf
        return (*qfn2(fn))(fn, v_24017, v_24004);
    }
v_23930:
    v_24004 = stack[-4];
    goto v_23854;
    v_24004 = nil;
v_23854:
    goto v_23835;
v_23841:
    goto v_23967;
v_23963:
    goto v_23979;
v_23969:
    v_24004 = stack[-4];
    v_24008 = qcar(v_24004);
    goto v_23970;
v_23971:
    v_24007 = stack[-3];
    goto v_23972;
v_23973:
    v_24006 = stack[-2];
    goto v_23974;
v_23975:
    v_24005 = stack[-1];
    goto v_23976;
v_23977:
    v_24004 = stack[0];
    goto v_23978;
v_23979:
    goto v_23969;
v_23970:
    goto v_23971;
v_23972:
    goto v_23973;
v_23974:
    goto v_23975;
v_23976:
    goto v_23977;
v_23978:
    fn = elt(env, 8); // isimp2
    stack[-5] = (*qfnn(fn))(fn, 5, v_24008, v_24007, v_24006, v_24005, v_24004);
    env = stack[-6];
    goto v_23964;
v_23965:
    goto v_23997;
v_23987:
    v_24004 = stack[-4];
    v_24008 = qcdr(v_24004);
    goto v_23988;
v_23989:
    v_24007 = stack[-3];
    goto v_23990;
v_23991:
    v_24006 = stack[-2];
    goto v_23992;
v_23993:
    v_24005 = stack[-1];
    goto v_23994;
v_23995:
    v_24004 = stack[0];
    goto v_23996;
v_23997:
    goto v_23987;
v_23988:
    goto v_23989;
v_23990:
    goto v_23991;
v_23992:
    goto v_23993;
v_23994:
    goto v_23995;
v_23996:
    v_24004 = CC_isimp1(elt(env, 0), 5, v_24008, v_24007, v_24006, v_24005, v_24004);
    env = stack[-6];
    goto v_23966;
v_23967:
    goto v_23963;
v_23964:
    goto v_23965;
v_23966:
    {
        LispObject v_24018 = stack[-5];
        fn = elt(env, 9); // addf
        return (*qfn2(fn))(fn, v_24018, v_24004);
    }
    v_24004 = nil;
v_23835:
    return onevalue(v_24004);
}



// Code for drop_dec_with

static LispObject CC_drop_dec_with(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23935, v_23936, v_23937;
    LispObject v_23830, v_23829, v_23828;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "drop_dec_with");
    va_start(aa, nargs);
    v_23828 = va_arg(aa, LispObject);
    v_23829 = va_arg(aa, LispObject);
    v_23830 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_23830,v_23829,v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_23828,v_23829,v_23830);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_23830;
    stack[-3] = v_23829;
    stack[-4] = v_23828;
// end of prologue
    stack[-5] = nil;
    v_23935 = stack[-2];
    if (v_23935 == nil) goto v_23840;
    goto v_23847;
v_23843:
    v_23936 = stack[-3];
    goto v_23844;
v_23845:
    v_23935 = elt(env, 1); // dec_with_rl
    goto v_23846;
v_23847:
    goto v_23843;
v_23844:
    goto v_23845;
v_23846:
    v_23935 = get(v_23936, v_23935);
    env = stack[-6];
    goto v_23838;
v_23840:
    goto v_23857;
v_23853:
    v_23936 = stack[-3];
    goto v_23854;
v_23855:
    v_23935 = elt(env, 2); // dec_with
    goto v_23856;
v_23857:
    goto v_23853;
v_23854:
    goto v_23855;
v_23856:
    v_23935 = get(v_23936, v_23935);
    env = stack[-6];
    goto v_23838;
    v_23935 = nil;
v_23838:
    stack[-1] = v_23935;
v_23863:
    v_23935 = stack[-1];
    if (v_23935 == nil) goto v_23867;
    else goto v_23868;
v_23867:
    goto v_23862;
v_23868:
    v_23935 = stack[-1];
    v_23935 = qcar(v_23935);
    stack[0] = v_23935;
    goto v_23879;
v_23875:
    v_23936 = stack[-4];
    goto v_23876;
v_23877:
    v_23935 = stack[0];
    goto v_23878;
v_23879:
    goto v_23875;
v_23876:
    goto v_23877;
v_23878:
    v_23935 = Ldelete(nil, v_23936, v_23935);
    env = stack[-6];
    stack[0] = v_23935;
    goto v_23891;
v_23887:
    v_23935 = stack[0];
    v_23936 = Llength(nil, v_23935);
    env = stack[-6];
    goto v_23888;
v_23889:
    v_23935 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23890;
v_23891:
    goto v_23887;
v_23888:
    goto v_23889;
v_23890:
    v_23935 = (LispObject)greaterp2(v_23936, v_23935);
    v_23935 = v_23935 ? lisp_true : nil;
    env = stack[-6];
    if (v_23935 == nil) goto v_23885;
    goto v_23900;
v_23896:
    v_23936 = stack[0];
    goto v_23897;
v_23898:
    v_23935 = stack[-5];
    goto v_23899;
v_23900:
    goto v_23896;
v_23897:
    goto v_23898;
v_23899:
    v_23935 = cons(v_23936, v_23935);
    env = stack[-6];
    stack[-5] = v_23935;
    goto v_23883;
v_23885:
v_23883:
    v_23935 = stack[-1];
    v_23935 = qcdr(v_23935);
    stack[-1] = v_23935;
    goto v_23863;
v_23862:
    v_23935 = stack[-2];
    if (v_23935 == nil) goto v_23909;
    goto v_23918;
v_23912:
    v_23937 = stack[-3];
    goto v_23913;
v_23914:
    v_23936 = elt(env, 1); // dec_with_rl
    goto v_23915;
v_23916:
    v_23935 = stack[-5];
    goto v_23917;
v_23918:
    goto v_23912;
v_23913:
    goto v_23914;
v_23915:
    goto v_23916;
v_23917:
    v_23935 = Lputprop(nil, 3, v_23937, v_23936, v_23935);
    goto v_23907;
v_23909:
    goto v_23931;
v_23925:
    v_23937 = stack[-3];
    goto v_23926;
v_23927:
    v_23936 = elt(env, 2); // dec_with
    goto v_23928;
v_23929:
    v_23935 = stack[-5];
    goto v_23930;
v_23931:
    goto v_23925;
v_23926:
    goto v_23927;
v_23928:
    goto v_23929;
v_23930:
    v_23935 = Lputprop(nil, 3, v_23937, v_23936, v_23935);
    goto v_23907;
v_23907:
    v_23935 = nil;
    return onevalue(v_23935);
}



// Code for rl_qe

static LispObject CC_rl_qe(LispObject env,
                         LispObject v_23828, LispObject v_23829)
{
    env = qenv(env);
    LispObject v_23846, v_23847;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23829,v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23828,v_23829);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_23846 = v_23829;
    v_23847 = v_23828;
// end of prologue
    goto v_23836;
v_23832:
    stack[0] = qvalue(elt(env, 1)); // rl_qe!*
    goto v_23833;
v_23834:
    goto v_23843;
v_23839:
    goto v_23840;
v_23841:
    goto v_23842;
v_23843:
    goto v_23839;
v_23840:
    goto v_23841;
v_23842:
    v_23846 = list2(v_23847, v_23846);
    env = stack[-1];
    goto v_23835;
v_23836:
    goto v_23832;
v_23833:
    goto v_23834;
v_23835:
    {
        LispObject v_23849 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_23849, v_23846);
    }
}



// Code for cl_nnf1

static LispObject CC_cl_nnf1(LispObject env,
                         LispObject v_23828, LispObject v_23829)
{
    env = qenv(env);
    LispObject v_24337, v_24338, v_24339;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23829,v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23828,v_23829);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_23829;
    stack[-2] = v_23828;
// end of prologue
v_23827:
    v_24337 = stack[-2];
    if (!consp(v_24337)) goto v_23836;
    else goto v_23837;
v_23836:
    v_24337 = stack[-2];
    goto v_23835;
v_23837:
    v_24337 = stack[-2];
    v_24337 = qcar(v_24337);
    goto v_23835;
    v_24337 = nil;
v_23835:
    v_24339 = v_24337;
    goto v_23852;
v_23848:
    v_24338 = v_24339;
    goto v_23849;
v_23850:
    v_24337 = elt(env, 1); // not
    goto v_23851;
v_23852:
    goto v_23848;
v_23849:
    goto v_23850;
v_23851:
    if (v_24338 == v_24337) goto v_23846;
    else goto v_23847;
v_23846:
    goto v_23860;
v_23856:
    v_24337 = stack[-2];
    v_24337 = qcdr(v_24337);
    v_24338 = qcar(v_24337);
    goto v_23857;
v_23858:
    v_24337 = stack[-4];
    v_24337 = (v_24337 == nil ? lisp_true : nil);
    goto v_23859;
v_23860:
    goto v_23856;
v_23857:
    goto v_23858;
v_23859:
    stack[-2] = v_24338;
    stack[-4] = v_24337;
    goto v_23827;
v_23847:
    goto v_23874;
v_23870:
    v_24338 = v_24339;
    goto v_23871;
v_23872:
    v_24337 = elt(env, 2); // impl
    goto v_23873;
v_23874:
    goto v_23870;
v_23871:
    goto v_23872;
v_23873:
    if (v_24338 == v_24337) goto v_23868;
    else goto v_23869;
v_23868:
    goto v_23884;
v_23878:
    goto v_23890;
v_23886:
    v_24338 = elt(env, 3); // or
    goto v_23887;
v_23888:
    v_24337 = stack[-4];
    goto v_23889;
v_23890:
    goto v_23886;
v_23887:
    goto v_23888;
v_23889:
    fn = elt(env, 13); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_24338, v_24337);
    env = stack[-6];
    goto v_23879;
v_23880:
    goto v_23898;
v_23894:
    v_24337 = stack[-2];
    v_24337 = qcdr(v_24337);
    v_24338 = qcar(v_24337);
    goto v_23895;
v_23896:
    v_24337 = stack[-4];
    v_24337 = (v_24337 == nil ? lisp_true : nil);
    goto v_23897;
v_23898:
    goto v_23894;
v_23895:
    goto v_23896;
v_23897:
    stack[0] = CC_cl_nnf1(elt(env, 0), v_24338, v_24337);
    env = stack[-6];
    goto v_23881;
v_23882:
    goto v_23910;
v_23906:
    v_24337 = stack[-2];
    v_24337 = qcdr(v_24337);
    v_24337 = qcdr(v_24337);
    v_24338 = qcar(v_24337);
    goto v_23907;
v_23908:
    v_24337 = stack[-4];
    goto v_23909;
v_23910:
    goto v_23906;
v_23907:
    goto v_23908;
v_23909:
    v_24337 = CC_cl_nnf1(elt(env, 0), v_24338, v_24337);
    env = stack[-6];
    v_24337 = ncons(v_24337);
    goto v_23883;
v_23884:
    goto v_23878;
v_23879:
    goto v_23880;
v_23881:
    goto v_23882;
v_23883:
    {
        LispObject v_24346 = stack[-1];
        LispObject v_24347 = stack[0];
        return list2star(v_24346, v_24347, v_24337);
    }
v_23869:
    goto v_23924;
v_23920:
    v_24338 = v_24339;
    goto v_23921;
v_23922:
    v_24337 = elt(env, 4); // repl
    goto v_23923;
v_23924:
    goto v_23920;
v_23921:
    goto v_23922;
v_23923:
    if (v_24338 == v_24337) goto v_23918;
    else goto v_23919;
v_23918:
    goto v_23934;
v_23928:
    goto v_23940;
v_23936:
    v_24338 = elt(env, 3); // or
    goto v_23937;
v_23938:
    v_24337 = stack[-4];
    goto v_23939;
v_23940:
    goto v_23936;
v_23937:
    goto v_23938;
v_23939:
    fn = elt(env, 13); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_24338, v_24337);
    env = stack[-6];
    goto v_23929;
v_23930:
    goto v_23948;
v_23944:
    v_24337 = stack[-2];
    v_24337 = qcdr(v_24337);
    v_24338 = qcar(v_24337);
    goto v_23945;
v_23946:
    v_24337 = stack[-4];
    goto v_23947;
v_23948:
    goto v_23944;
v_23945:
    goto v_23946;
v_23947:
    stack[0] = CC_cl_nnf1(elt(env, 0), v_24338, v_24337);
    env = stack[-6];
    goto v_23931;
v_23932:
    goto v_23959;
v_23955:
    v_24337 = stack[-2];
    v_24337 = qcdr(v_24337);
    v_24337 = qcdr(v_24337);
    v_24338 = qcar(v_24337);
    goto v_23956;
v_23957:
    v_24337 = stack[-4];
    v_24337 = (v_24337 == nil ? lisp_true : nil);
    goto v_23958;
v_23959:
    goto v_23955;
v_23956:
    goto v_23957;
v_23958:
    v_24337 = CC_cl_nnf1(elt(env, 0), v_24338, v_24337);
    env = stack[-6];
    v_24337 = ncons(v_24337);
    goto v_23933;
v_23934:
    goto v_23928;
v_23929:
    goto v_23930;
v_23931:
    goto v_23932;
v_23933:
    {
        LispObject v_24348 = stack[-1];
        LispObject v_24349 = stack[0];
        return list2star(v_24348, v_24349, v_24337);
    }
v_23919:
    goto v_23974;
v_23970:
    v_24338 = v_24339;
    goto v_23971;
v_23972:
    v_24337 = elt(env, 5); // equiv
    goto v_23973;
v_23974:
    goto v_23970;
v_23971:
    goto v_23972;
v_23973:
    if (v_24338 == v_24337) goto v_23968;
    else goto v_23969;
v_23968:
    goto v_23984;
v_23978:
    goto v_23990;
v_23986:
    v_24338 = elt(env, 3); // or
    goto v_23987;
v_23988:
    v_24337 = stack[-4];
    goto v_23989;
v_23990:
    goto v_23986;
v_23987:
    goto v_23988;
v_23989:
    fn = elt(env, 13); // cl_cflip
    stack[-5] = (*qfn2(fn))(fn, v_24338, v_24337);
    env = stack[-6];
    goto v_23979;
v_23980:
    goto v_24000;
v_23994:
    goto v_24006;
v_24002:
    v_24338 = elt(env, 6); // and
    goto v_24003;
v_24004:
    v_24337 = stack[-4];
    goto v_24005;
v_24006:
    goto v_24002;
v_24003:
    goto v_24004;
v_24005:
    fn = elt(env, 13); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_24338, v_24337);
    env = stack[-6];
    goto v_23995;
v_23996:
    goto v_24014;
v_24010:
    v_24337 = stack[-2];
    v_24337 = qcdr(v_24337);
    v_24338 = qcar(v_24337);
    goto v_24011;
v_24012:
    v_24337 = stack[-4];
    goto v_24013;
v_24014:
    goto v_24010;
v_24011:
    goto v_24012;
v_24013:
    stack[0] = CC_cl_nnf1(elt(env, 0), v_24338, v_24337);
    env = stack[-6];
    goto v_23997;
v_23998:
    goto v_24025;
v_24021:
    v_24337 = stack[-2];
    v_24337 = qcdr(v_24337);
    v_24337 = qcdr(v_24337);
    v_24338 = qcar(v_24337);
    goto v_24022;
v_24023:
    v_24337 = stack[-4];
    goto v_24024;
v_24025:
    goto v_24021;
v_24022:
    goto v_24023;
v_24024:
    v_24337 = CC_cl_nnf1(elt(env, 0), v_24338, v_24337);
    env = stack[-6];
    v_24337 = ncons(v_24337);
    env = stack[-6];
    goto v_23999;
v_24000:
    goto v_23994;
v_23995:
    goto v_23996;
v_23997:
    goto v_23998;
v_23999:
    stack[-3] = list2star(stack[-1], stack[0], v_24337);
    env = stack[-6];
    goto v_23981;
v_23982:
    goto v_24039;
v_24033:
    goto v_24045;
v_24041:
    v_24338 = elt(env, 6); // and
    goto v_24042;
v_24043:
    v_24337 = stack[-4];
    goto v_24044;
v_24045:
    goto v_24041;
v_24042:
    goto v_24043;
v_24044:
    fn = elt(env, 13); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_24338, v_24337);
    env = stack[-6];
    goto v_24034;
v_24035:
    goto v_24053;
v_24049:
    v_24337 = stack[-2];
    v_24337 = qcdr(v_24337);
    v_24338 = qcar(v_24337);
    goto v_24050;
v_24051:
    v_24337 = stack[-4];
    v_24337 = (v_24337 == nil ? lisp_true : nil);
    goto v_24052;
v_24053:
    goto v_24049;
v_24050:
    goto v_24051;
v_24052:
    stack[0] = CC_cl_nnf1(elt(env, 0), v_24338, v_24337);
    env = stack[-6];
    goto v_24036;
v_24037:
    goto v_24065;
v_24061:
    v_24337 = stack[-2];
    v_24337 = qcdr(v_24337);
    v_24337 = qcdr(v_24337);
    v_24338 = qcar(v_24337);
    goto v_24062;
v_24063:
    v_24337 = stack[-4];
    v_24337 = (v_24337 == nil ? lisp_true : nil);
    goto v_24064;
v_24065:
    goto v_24061;
v_24062:
    goto v_24063;
v_24064:
    v_24337 = CC_cl_nnf1(elt(env, 0), v_24338, v_24337);
    env = stack[-6];
    v_24337 = ncons(v_24337);
    env = stack[-6];
    goto v_24038;
v_24039:
    goto v_24033;
v_24034:
    goto v_24035;
v_24036:
    goto v_24037;
v_24038:
    v_24337 = list2star(stack[-1], stack[0], v_24337);
    env = stack[-6];
    v_24337 = ncons(v_24337);
    goto v_23983;
v_23984:
    goto v_23978;
v_23979:
    goto v_23980;
v_23981:
    goto v_23982;
v_23983:
    {
        LispObject v_24350 = stack[-5];
        LispObject v_24351 = stack[-3];
        return list2star(v_24350, v_24351, v_24337);
    }
v_23969:
    goto v_24084;
v_24080:
    v_24338 = v_24339;
    goto v_24081;
v_24082:
    v_24337 = elt(env, 7); // true
    goto v_24083;
v_24084:
    goto v_24080;
v_24081:
    goto v_24082;
v_24083:
    if (v_24338 == v_24337) goto v_24078;
    else goto v_24079;
v_24078:
    v_24337 = lisp_true;
    goto v_24077;
v_24079:
    goto v_24094;
v_24090:
    v_24338 = v_24339;
    goto v_24091;
v_24092:
    v_24337 = elt(env, 8); // false
    goto v_24093;
v_24094:
    goto v_24090;
v_24091:
    goto v_24092;
v_24093:
    v_24337 = (v_24338 == v_24337 ? lisp_true : nil);
    goto v_24077;
    v_24337 = nil;
v_24077:
    if (v_24337 == nil) goto v_24075;
    goto v_24103;
v_24099:
    v_24338 = stack[-2];
    goto v_24100;
v_24101:
    v_24337 = stack[-4];
    goto v_24102;
v_24103:
    goto v_24099;
v_24100:
    goto v_24101;
v_24102:
    {
        fn = elt(env, 13); // cl_cflip
        return (*qfn2(fn))(fn, v_24338, v_24337);
    }
v_24075:
    goto v_24118;
v_24114:
    v_24338 = v_24339;
    goto v_24115;
v_24116:
    v_24337 = elt(env, 9); // ex
    goto v_24117;
v_24118:
    goto v_24114;
v_24115:
    goto v_24116;
v_24117:
    if (v_24338 == v_24337) goto v_24112;
    else goto v_24113;
v_24112:
    v_24337 = lisp_true;
    goto v_24111;
v_24113:
    goto v_24128;
v_24124:
    v_24338 = v_24339;
    goto v_24125;
v_24126:
    v_24337 = elt(env, 10); // all
    goto v_24127;
v_24128:
    goto v_24124;
v_24125:
    goto v_24126;
v_24127:
    v_24337 = (v_24338 == v_24337 ? lisp_true : nil);
    goto v_24111;
    v_24337 = nil;
v_24111:
    if (v_24337 == nil) goto v_24109;
    goto v_24139;
v_24133:
    goto v_24145;
v_24141:
    v_24338 = v_24339;
    goto v_24142;
v_24143:
    v_24337 = stack[-4];
    goto v_24144;
v_24145:
    goto v_24141;
v_24142:
    goto v_24143;
v_24144:
    fn = elt(env, 13); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_24338, v_24337);
    env = stack[-6];
    goto v_24134;
v_24135:
    v_24337 = stack[-2];
    v_24337 = qcdr(v_24337);
    stack[0] = qcar(v_24337);
    goto v_24136;
v_24137:
    goto v_24156;
v_24152:
    v_24337 = stack[-2];
    v_24337 = qcdr(v_24337);
    v_24337 = qcdr(v_24337);
    v_24338 = qcar(v_24337);
    goto v_24153;
v_24154:
    v_24337 = stack[-4];
    goto v_24155;
v_24156:
    goto v_24152;
v_24153:
    goto v_24154;
v_24155:
    v_24337 = CC_cl_nnf1(elt(env, 0), v_24338, v_24337);
    goto v_24138;
v_24139:
    goto v_24133;
v_24134:
    goto v_24135;
v_24136:
    goto v_24137;
v_24138:
    {
        LispObject v_24352 = stack[-1];
        LispObject v_24353 = stack[0];
        return list3(v_24352, v_24353, v_24337);
    }
v_24109:
    goto v_24174;
v_24170:
    v_24338 = v_24339;
    goto v_24171;
v_24172:
    v_24337 = elt(env, 11); // bex
    goto v_24173;
v_24174:
    goto v_24170;
v_24171:
    goto v_24172;
v_24173:
    if (v_24338 == v_24337) goto v_24168;
    else goto v_24169;
v_24168:
    v_24337 = lisp_true;
    goto v_24167;
v_24169:
    goto v_24184;
v_24180:
    v_24338 = v_24339;
    goto v_24181;
v_24182:
    v_24337 = elt(env, 12); // ball
    goto v_24183;
v_24184:
    goto v_24180;
v_24181:
    goto v_24182;
v_24183:
    v_24337 = (v_24338 == v_24337 ? lisp_true : nil);
    goto v_24167;
    v_24337 = nil;
v_24167:
    if (v_24337 == nil) goto v_24165;
    goto v_24197;
v_24189:
    goto v_24203;
v_24199:
    v_24338 = v_24339;
    goto v_24200;
v_24201:
    v_24337 = stack[-4];
    goto v_24202;
v_24203:
    goto v_24199;
v_24200:
    goto v_24201;
v_24202:
    fn = elt(env, 13); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_24338, v_24337);
    env = stack[-6];
    goto v_24190;
v_24191:
    v_24337 = stack[-2];
    v_24337 = qcdr(v_24337);
    stack[0] = qcar(v_24337);
    goto v_24192;
v_24193:
    goto v_24214;
v_24210:
    v_24337 = stack[-2];
    v_24337 = qcdr(v_24337);
    v_24337 = qcdr(v_24337);
    v_24338 = qcar(v_24337);
    goto v_24211;
v_24212:
    v_24337 = stack[-4];
    goto v_24213;
v_24214:
    goto v_24210;
v_24211:
    goto v_24212;
v_24213:
    stack[-3] = CC_cl_nnf1(elt(env, 0), v_24338, v_24337);
    env = stack[-6];
    goto v_24194;
v_24195:
    goto v_24225;
v_24221:
    v_24337 = stack[-2];
    v_24337 = qcdr(v_24337);
    v_24337 = qcdr(v_24337);
    v_24337 = qcdr(v_24337);
    v_24338 = qcar(v_24337);
    goto v_24222;
v_24223:
    v_24337 = lisp_true;
    goto v_24224;
v_24225:
    goto v_24221;
v_24222:
    goto v_24223;
v_24224:
    v_24337 = CC_cl_nnf1(elt(env, 0), v_24338, v_24337);
    goto v_24196;
v_24197:
    goto v_24189;
v_24190:
    goto v_24191;
v_24192:
    goto v_24193;
v_24194:
    goto v_24195;
v_24196:
    {
        LispObject v_24354 = stack[-1];
        LispObject v_24355 = stack[0];
        LispObject v_24356 = stack[-3];
        return list4(v_24354, v_24355, v_24356, v_24337);
    }
v_24165:
    goto v_24244;
v_24240:
    v_24338 = v_24339;
    goto v_24241;
v_24242:
    v_24337 = elt(env, 3); // or
    goto v_24243;
v_24244:
    goto v_24240;
v_24241:
    goto v_24242;
v_24243:
    if (v_24338 == v_24337) goto v_24238;
    else goto v_24239;
v_24238:
    v_24337 = lisp_true;
    goto v_24237;
v_24239:
    goto v_24254;
v_24250:
    v_24338 = v_24339;
    goto v_24251;
v_24252:
    v_24337 = elt(env, 6); // and
    goto v_24253;
v_24254:
    goto v_24250;
v_24251:
    goto v_24252;
v_24253:
    v_24337 = (v_24338 == v_24337 ? lisp_true : nil);
    goto v_24237;
    v_24337 = nil;
v_24237:
    if (v_24337 == nil) goto v_24235;
    goto v_24263;
v_24259:
    goto v_24269;
v_24265:
    v_24338 = v_24339;
    goto v_24266;
v_24267:
    v_24337 = stack[-4];
    goto v_24268;
v_24269:
    goto v_24265;
v_24266:
    goto v_24267;
v_24268:
    fn = elt(env, 13); // cl_cflip
    stack[-5] = (*qfn2(fn))(fn, v_24338, v_24337);
    env = stack[-6];
    goto v_24260;
v_24261:
    v_24337 = stack[-2];
    v_24337 = qcdr(v_24337);
    stack[-3] = v_24337;
    v_24337 = stack[-3];
    if (v_24337 == nil) goto v_24282;
    else goto v_24283;
v_24282:
    v_24337 = nil;
    goto v_24276;
v_24283:
    v_24337 = stack[-3];
    v_24337 = qcar(v_24337);
    goto v_24295;
v_24291:
    v_24338 = v_24337;
    goto v_24292;
v_24293:
    v_24337 = stack[-4];
    goto v_24294;
v_24295:
    goto v_24291;
v_24292:
    goto v_24293;
v_24294:
    v_24337 = CC_cl_nnf1(elt(env, 0), v_24338, v_24337);
    env = stack[-6];
    v_24337 = ncons(v_24337);
    env = stack[-6];
    stack[-1] = v_24337;
    stack[-2] = v_24337;
v_24277:
    v_24337 = stack[-3];
    v_24337 = qcdr(v_24337);
    stack[-3] = v_24337;
    v_24337 = stack[-3];
    if (v_24337 == nil) goto v_24302;
    else goto v_24303;
v_24302:
    v_24337 = stack[-2];
    goto v_24276;
v_24303:
    goto v_24311;
v_24307:
    stack[0] = stack[-1];
    goto v_24308;
v_24309:
    v_24337 = stack[-3];
    v_24337 = qcar(v_24337);
    goto v_24322;
v_24318:
    v_24338 = v_24337;
    goto v_24319;
v_24320:
    v_24337 = stack[-4];
    goto v_24321;
v_24322:
    goto v_24318;
v_24319:
    goto v_24320;
v_24321:
    v_24337 = CC_cl_nnf1(elt(env, 0), v_24338, v_24337);
    env = stack[-6];
    v_24337 = ncons(v_24337);
    env = stack[-6];
    goto v_24310;
v_24311:
    goto v_24307;
v_24308:
    goto v_24309;
v_24310:
    v_24337 = Lrplacd(nil, stack[0], v_24337);
    env = stack[-6];
    v_24337 = stack[-1];
    v_24337 = qcdr(v_24337);
    stack[-1] = v_24337;
    goto v_24277;
v_24276:
    goto v_24262;
v_24263:
    goto v_24259;
v_24260:
    goto v_24261;
v_24262:
    {
        LispObject v_24357 = stack[-5];
        return cons(v_24357, v_24337);
    }
v_24235:
    v_24337 = stack[-4];
    if (v_24337 == nil) goto v_24330;
    v_24337 = stack[-2];
    goto v_24328;
v_24330:
    v_24337 = stack[-2];
    {
        fn = elt(env, 14); // rl_negateat
        return (*qfn1(fn))(fn, v_24337);
    }
    v_24337 = nil;
v_24328:
    return onevalue(v_24337);
}



// Code for repr_ldeg

static LispObject CC_repr_ldeg(LispObject env,
                         LispObject v_23828)
{
    env = qenv(env);
    LispObject v_23836;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23836 = v_23828;
// end of prologue
    v_23836 = qcdr(v_23836);
    v_23836 = qcdr(v_23836);
    v_23836 = qcdr(v_23836);
    v_23836 = qcdr(v_23836);
    v_23836 = qcar(v_23836);
    return onevalue(v_23836);
}



// Code for transposerd

static LispObject CC_transposerd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23836;
    LispObject fn;
    argcheck(nargs, 0, "transposerd");
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
    v_23836 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_23836;
    fn = elt(env, 2); // lex
    v_23836 = (*qfnn(fn))(fn, 0);
    v_23836 = stack[0];
    return ncons(v_23836);
    return onevalue(v_23836);
}



// Code for spcol_dim

static LispObject CC_spcol_dim(LispObject env,
                         LispObject v_23828)
{
    env = qenv(env);
    LispObject v_23856;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23828);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_23828;
// end of prologue
    v_23856 = qvalue(elt(env, 1)); // !*fast_la
    if (v_23856 == nil) goto v_23839;
    else goto v_23840;
v_23839:
    v_23856 = stack[0];
    fn = elt(env, 3); // matrixp
    v_23856 = (*qfn1(fn))(fn, v_23856);
    env = stack[-1];
    v_23856 = (v_23856 == nil ? lisp_true : nil);
    goto v_23838;
v_23840:
    v_23856 = nil;
    goto v_23838;
    v_23856 = nil;
v_23838:
    if (v_23856 == nil) goto v_23836;
    v_23856 = elt(env, 2); // "Error in spcol_dim: input should be a matrix."
    fn = elt(env, 4); // rederr
    v_23856 = (*qfn1(fn))(fn, v_23856);
    env = stack[-1];
    goto v_23834;
v_23836:
v_23834:
    v_23856 = stack[0];
    fn = elt(env, 5); // spmatlength
    v_23856 = (*qfn1(fn))(fn, v_23856);
    v_23856 = qcdr(v_23856);
    v_23856 = qcdr(v_23856);
    v_23856 = qcar(v_23856);
    return onevalue(v_23856);
}



// Code for on!-double1

static LispObject CC_onKdouble1(LispObject env,
                         LispObject v_23828)
{
    env = qenv(env);
    LispObject v_23857;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23828);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_23828;
// end of prologue
v_23832:
    v_23857 = stack[0];
    v_23857 = Lconsp(nil, v_23857);
    env = stack[-1];
    if (v_23857 == nil) goto v_23836;
    v_23857 = stack[0];
    v_23857 = qcar(v_23857);
    fn = elt(env, 2); // doublep
    v_23857 = (*qfn1(fn))(fn, v_23857);
    env = stack[-1];
    if (v_23857 == nil) goto v_23842;
    v_23857 = lisp_true;
    qvalue(elt(env, 1)) = v_23857; // !*double
    goto v_23831;
v_23842:
    v_23857 = stack[0];
    v_23857 = qcar(v_23857);
    v_23857 = CC_onKdouble1(elt(env, 0), v_23857);
    env = stack[-1];
    v_23857 = stack[0];
    v_23857 = qcdr(v_23857);
    stack[0] = v_23857;
    goto v_23832;
    goto v_23834;
v_23836:
    v_23857 = nil;
    goto v_23831;
v_23834:
    v_23857 = nil;
v_23831:
    return onevalue(v_23857);
}



// Code for size_of_matrix

static LispObject CC_size_of_matrix(LispObject env,
                         LispObject v_23828)
{
    env = qenv(env);
    LispObject v_23859, v_23860;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23828);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_23828;
// end of prologue
    v_23859 = stack[0];
    fn = elt(env, 1); // matrix_input_test
    v_23859 = (*qfn1(fn))(fn, v_23859);
    env = stack[-2];
    goto v_23843;
v_23839:
    stack[-1] = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_23840;
v_23841:
    v_23859 = stack[0];
    v_23859 = Llength(nil, v_23859);
    env = stack[-2];
    goto v_23842;
v_23843:
    goto v_23839;
v_23840:
    goto v_23841;
v_23842:
    v_23859 = plus2(stack[-1], v_23859);
    env = stack[-2];
    stack[-1] = v_23859;
    v_23859 = stack[0];
    v_23859 = qcdr(v_23859);
    v_23859 = qcar(v_23859);
    v_23859 = Llength(nil, v_23859);
    goto v_23856;
v_23852:
    v_23860 = stack[-1];
    goto v_23853;
v_23854:
    goto v_23855;
v_23856:
    goto v_23852;
v_23853:
    goto v_23854;
v_23855:
    return list2(v_23860, v_23859);
    return onevalue(v_23859);
}



// Code for get!:const

static LispObject CC_getTconst(LispObject env,
                         LispObject v_23828, LispObject v_23829)
{
    env = qenv(env);
    LispObject v_23920, v_23921;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23829,v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23828,v_23829);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_23829;
    stack[-1] = v_23828;
// end of prologue
    v_23920 = stack[-1];
    if (!consp(v_23920)) goto v_23837;
    else goto v_23838;
v_23837:
    v_23920 = stack[0];
    v_23920 = integerp(v_23920);
    if (v_23920 == nil) goto v_23842;
    else goto v_23843;
v_23842:
    v_23920 = nil;
    goto v_23841;
v_23843:
    goto v_23854;
v_23850:
    v_23921 = stack[0];
    goto v_23851;
v_23852:
    v_23920 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23853;
v_23854:
    goto v_23850;
v_23851:
    goto v_23852;
v_23853:
    v_23920 = (LispObject)greaterp2(v_23921, v_23920);
    v_23920 = v_23920 ? lisp_true : nil;
    env = stack[-2];
    goto v_23841;
    v_23920 = nil;
v_23841:
    goto v_23836;
v_23838:
    v_23920 = nil;
    goto v_23836;
    v_23920 = nil;
v_23836:
    if (v_23920 == nil) goto v_23834;
    goto v_23868;
v_23864:
    v_23921 = stack[-1];
    goto v_23865;
v_23866:
    v_23920 = elt(env, 1); // save!:c
    goto v_23867;
v_23868:
    goto v_23864;
v_23865:
    goto v_23866;
v_23867:
    v_23920 = get(v_23921, v_23920);
    env = stack[-2];
    stack[-1] = v_23920;
    v_23920 = stack[-1];
    if (v_23920 == nil) goto v_23877;
    else goto v_23878;
v_23877:
    v_23920 = lisp_true;
    goto v_23876;
v_23878:
    goto v_23888;
v_23884:
    v_23920 = stack[-1];
    v_23921 = qcar(v_23920);
    goto v_23885;
v_23886:
    v_23920 = stack[0];
    goto v_23887;
v_23888:
    goto v_23884;
v_23885:
    goto v_23886;
v_23887:
    v_23920 = (LispObject)lessp2(v_23921, v_23920);
    v_23920 = v_23920 ? lisp_true : nil;
    env = stack[-2];
    goto v_23876;
    v_23920 = nil;
v_23876:
    if (v_23920 == nil) goto v_23874;
    v_23920 = elt(env, 2); // not_found
    goto v_23862;
v_23874:
    goto v_23899;
v_23895:
    v_23920 = stack[-1];
    v_23921 = qcar(v_23920);
    goto v_23896;
v_23897:
    v_23920 = stack[0];
    goto v_23898;
v_23899:
    goto v_23895;
v_23896:
    goto v_23897;
v_23898:
    if (equal(v_23921, v_23920)) goto v_23893;
    else goto v_23894;
v_23893:
    v_23920 = stack[-1];
    v_23920 = qcdr(v_23920);
    goto v_23862;
v_23894:
    goto v_23912;
v_23908:
    v_23920 = stack[-1];
    v_23921 = qcdr(v_23920);
    goto v_23909;
v_23910:
    v_23920 = stack[0];
    goto v_23911;
v_23912:
    goto v_23908;
v_23909:
    goto v_23910;
v_23911:
    {
        fn = elt(env, 3); // round!:mt
        return (*qfn2(fn))(fn, v_23921, v_23920);
    }
    v_23920 = nil;
v_23862:
    goto v_23832;
v_23834:
    v_23920 = elt(env, 0); // get!:const
    {
        fn = elt(env, 4); // bflerrmsg
        return (*qfn1(fn))(fn, v_23920);
    }
    v_23920 = nil;
v_23832:
    return onevalue(v_23920);
}



// Code for r2speclist1

static LispObject CC_r2speclist1(LispObject env,
                         LispObject v_23828)
{
    env = qenv(env);
    LispObject v_23871, v_23872, v_23873;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23871 = v_23828;
// end of prologue
    goto v_23839;
v_23835:
    v_23873 = v_23871;
    goto v_23836;
v_23837:
    v_23872 = elt(env, 1); // times
    goto v_23838;
v_23839:
    goto v_23835;
v_23836:
    goto v_23837;
v_23838:
    if (!consp(v_23873)) goto v_23833;
    v_23873 = qcar(v_23873);
    if (v_23873 == v_23872) goto v_23832;
    else goto v_23833;
v_23832:
    goto v_23849;
v_23843:
    v_23872 = v_23871;
    v_23872 = qcdr(v_23872);
    v_23873 = qcar(v_23872);
    goto v_23844;
v_23845:
    v_23872 = v_23871;
    v_23872 = qcdr(v_23872);
    v_23872 = qcdr(v_23872);
    v_23872 = qcar(v_23872);
    goto v_23846;
v_23847:
    v_23871 = qcdr(v_23871);
    v_23871 = qcdr(v_23871);
    v_23871 = qcdr(v_23871);
    goto v_23848;
v_23849:
    goto v_23843;
v_23844:
    goto v_23845;
v_23846:
    goto v_23847;
v_23848:
    {
        fn = elt(env, 2); // r2speclist2
        return (*qfnn(fn))(fn, 3, v_23873, v_23872, v_23871);
    }
v_23833:
    goto v_23868;
v_23864:
    v_23872 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23865;
v_23866:
    goto v_23867;
v_23868:
    goto v_23864;
v_23865:
    goto v_23866;
v_23867:
    return cons(v_23872, v_23871);
    v_23871 = nil;
    return onevalue(v_23871);
}



// Code for list!-evaluate

static LispObject CC_listKevaluate(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23892, v_23893, v_23894;
    LispObject fn;
    LispObject v_23830, v_23829, v_23828;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "list-evaluate");
    va_start(aa, nargs);
    v_23828 = va_arg(aa, LispObject);
    v_23829 = va_arg(aa, LispObject);
    v_23830 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_23830,v_23829,v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_23828,v_23829,v_23830);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_23830;
    stack[-4] = v_23829;
    v_23892 = v_23828;
// end of prologue
    stack[-5] = v_23892;
    v_23892 = stack[-5];
    if (v_23892 == nil) goto v_23841;
    else goto v_23842;
v_23841:
    v_23892 = nil;
    goto v_23836;
v_23842:
    v_23892 = stack[-5];
    v_23892 = qcar(v_23892);
    goto v_23856;
v_23850:
    v_23894 = v_23892;
    goto v_23851;
v_23852:
    v_23893 = stack[-4];
    goto v_23853;
v_23854:
    v_23892 = stack[-3];
    goto v_23855;
v_23856:
    goto v_23850;
v_23851:
    goto v_23852;
v_23853:
    goto v_23854;
v_23855:
    fn = elt(env, 1); // evaluate
    v_23892 = (*qfnn(fn))(fn, 3, v_23894, v_23893, v_23892);
    env = stack[-6];
    v_23892 = ncons(v_23892);
    env = stack[-6];
    stack[-1] = v_23892;
    stack[-2] = v_23892;
v_23837:
    v_23892 = stack[-5];
    v_23892 = qcdr(v_23892);
    stack[-5] = v_23892;
    v_23892 = stack[-5];
    if (v_23892 == nil) goto v_23864;
    else goto v_23865;
v_23864:
    v_23892 = stack[-2];
    goto v_23836;
v_23865:
    goto v_23873;
v_23869:
    stack[0] = stack[-1];
    goto v_23870;
v_23871:
    v_23892 = stack[-5];
    v_23892 = qcar(v_23892);
    goto v_23886;
v_23880:
    v_23894 = v_23892;
    goto v_23881;
v_23882:
    v_23893 = stack[-4];
    goto v_23883;
v_23884:
    v_23892 = stack[-3];
    goto v_23885;
v_23886:
    goto v_23880;
v_23881:
    goto v_23882;
v_23883:
    goto v_23884;
v_23885:
    fn = elt(env, 1); // evaluate
    v_23892 = (*qfnn(fn))(fn, 3, v_23894, v_23893, v_23892);
    env = stack[-6];
    v_23892 = ncons(v_23892);
    env = stack[-6];
    goto v_23872;
v_23873:
    goto v_23869;
v_23870:
    goto v_23871;
v_23872:
    v_23892 = Lrplacd(nil, stack[0], v_23892);
    env = stack[-6];
    v_23892 = stack[-1];
    v_23892 = qcdr(v_23892);
    stack[-1] = v_23892;
    goto v_23837;
v_23836:
    return onevalue(v_23892);
}



// Code for mkassign

static LispObject CC_mkassign(LispObject env,
                         LispObject v_23828, LispObject v_23829)
{
    env = qenv(env);
    LispObject v_23842, v_23843, v_23844;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23842 = v_23829;
    v_23843 = v_23828;
// end of prologue
    goto v_23838;
v_23832:
    v_23844 = elt(env, 1); // setq
    goto v_23833;
v_23834:
    goto v_23835;
v_23836:
    goto v_23837;
v_23838:
    goto v_23832;
v_23833:
    goto v_23834;
v_23835:
    goto v_23836;
v_23837:
    return list3(v_23844, v_23843, v_23842);
}



// Code for revalpart

static LispObject CC_revalpart(LispObject env,
                         LispObject v_23828)
{
    env = qenv(env);
    LispObject v_24226, v_24227, v_24228, v_24229, v_24230;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23828);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[0] = v_23828;
// end of prologue
    v_24226 = stack[0];
    if (v_24226 == nil) goto v_23832;
    else goto v_23833;
v_23832:
    goto v_23842;
v_23836:
    v_24228 = elt(env, 1); // alg
    goto v_23837;
v_23838:
    v_24227 = (LispObject)3216+TAG_FIXNUM; // 201
    goto v_23839;
v_23840:
    v_24226 = elt(env, 2); // "part called without arguments"
    goto v_23841;
v_23842:
    goto v_23836;
v_23837:
    goto v_23838;
v_23839:
    goto v_23840;
v_23841:
    {
        fn = elt(env, 10); // rerror
        return (*qfnn(fn))(fn, 3, v_24228, v_24227, v_24226);
    }
v_23833:
// Binding !*intstr
// FLUIDBIND: reloadenv=8 litvec-offset=3 saveloc=7
{   bind_fluid_stack bind_fluid_var(-8, 3, -7);
    qvalue(elt(env, 3)) = nil; // !*intstr
    stack[-6] = nil;
    v_24226 = lisp_true;
    qvalue(elt(env, 3)) = v_24226; // !*intstr
    goto v_23864;
v_23860:
    v_24226 = stack[0];
    v_24226 = qcar(v_24226);
    fn = elt(env, 11); // getrtype
    v_24227 = (*qfn1(fn))(fn, v_24226);
    env = stack[-8];
    stack[-3] = v_24227;
    goto v_23861;
v_23862:
    v_24226 = elt(env, 4); // list
    goto v_23863;
v_23864:
    goto v_23860;
v_23861:
    goto v_23862;
v_23863:
    if (v_24227 == v_24226) goto v_23858;
    else goto v_23859;
v_23858:
    v_24226 = stack[0];
    v_24226 = qcar(v_24226);
    if (!consp(v_24226)) goto v_23876;
    goto v_23884;
v_23880:
    v_24226 = stack[0];
    v_24226 = qcar(v_24226);
    v_24227 = qcar(v_24226);
    goto v_23881;
v_23882:
    v_24226 = elt(env, 5); // listfn
    goto v_23883;
v_23884:
    goto v_23880;
v_23881:
    goto v_23882;
v_23883:
    v_24226 = get(v_24227, v_24226);
    env = stack[-8];
    goto v_23874;
v_23876:
    v_24226 = nil;
    goto v_23874;
    v_24226 = nil;
v_23874:
    if (v_24226 == nil) goto v_23872;
    v_24226 = stack[0];
    v_24226 = qcar(v_24226);
    fn = elt(env, 12); // reval
    v_24226 = (*qfn1(fn))(fn, v_24226);
    env = stack[-8];
    goto v_23870;
v_23872:
    v_24226 = stack[0];
    v_24226 = qcar(v_24226);
    fn = elt(env, 13); // listeval0
    v_24226 = (*qfn1(fn))(fn, v_24226);
    env = stack[-8];
    goto v_23870;
    v_24226 = nil;
v_23870:
    goto v_23857;
v_23859:
    v_24226 = stack[0];
    v_24226 = qcar(v_24226);
    fn = elt(env, 12); // reval
    v_24226 = (*qfn1(fn))(fn, v_24226);
    env = stack[-8];
    goto v_23857;
    v_24226 = nil;
v_23857:
    stack[-5] = v_24226;
    v_24226 = nil;
    qvalue(elt(env, 3)) = v_24226; // !*intstr
    v_24226 = stack[0];
    v_24226 = qcdr(v_24226);
    stack[-4] = v_24226;
v_23910:
    v_24226 = stack[-4];
    if (v_24226 == nil) goto v_23913;
    else goto v_23914;
v_23913:
    goto v_23909;
v_23914:
    stack[-2] = nil;
    stack[-1] = nil;
    goto v_23927;
v_23923:
    v_24227 = stack[-5];
    goto v_23924;
v_23925:
    v_24226 = elt(env, 6); // !*hold
    goto v_23926;
v_23927:
    goto v_23923;
v_23924:
    goto v_23925;
v_23926:
    v_24226 = Leqcar(nil, v_24227, v_24226);
    env = stack[-8];
    stack[0] = v_24226;
    v_24226 = stack[-5];
    if (!consp(v_24226)) goto v_23932;
    else goto v_23933;
v_23932:
    goto v_23940;
v_23936:
    v_24227 = stack[-5];
    goto v_23937;
v_23938:
    v_24226 = stack[-4];
    v_24226 = qcar(v_24226);
    goto v_23939;
v_23940:
    goto v_23936;
v_23937:
    goto v_23938;
v_23939:
    fn = elt(env, 14); // parterr2
    v_24226 = (*qfn2(fn))(fn, v_24227, v_24226);
    env = stack[-8];
    v_24226 = lisp_true;
    stack[-6] = v_24226;
    goto v_23931;
v_23933:
    v_24226 = stack[-4];
    v_24226 = qcar(v_24226);
    fn = elt(env, 12); // reval
    v_24226 = (*qfn1(fn))(fn, v_24226);
    env = stack[-8];
    stack[-2] = v_24226;
    if (is_number(v_24226)) goto v_23946;
    goto v_23961;
v_23951:
    v_24230 = elt(env, 7); // "Invalid argument"
    goto v_23952;
v_23953:
    v_24226 = stack[-4];
    v_24229 = qcar(v_24226);
    goto v_23954;
v_23955:
    v_24228 = elt(env, 8); // "to part"
    goto v_23956;
v_23957:
    v_24227 = nil;
    goto v_23958;
v_23959:
    v_24226 = lisp_true;
    goto v_23960;
v_23961:
    goto v_23951;
v_23952:
    goto v_23953;
v_23954:
    goto v_23955;
v_23956:
    goto v_23957;
v_23958:
    goto v_23959;
v_23960:
    fn = elt(env, 15); // msgpri
    v_24226 = (*qfnn(fn))(fn, 5, v_24230, v_24229, v_24228, v_24227, v_24226);
    env = stack[-8];
    goto v_23931;
v_23946:
    goto v_23975;
v_23971:
    v_24226 = stack[-5];
    v_24227 = qcar(v_24226);
    goto v_23972;
v_23973:
    v_24226 = elt(env, 9); // partop
    goto v_23974;
v_23975:
    goto v_23971;
v_23972:
    goto v_23973;
v_23974:
    v_24226 = get(v_24227, v_24226);
    env = stack[-8];
    stack[-1] = v_24226;
    if (v_24226 == nil) goto v_23969;
    goto v_23986;
v_23980:
    v_24228 = stack[-1];
    goto v_23981;
v_23982:
    v_24227 = stack[-5];
    goto v_23983;
v_23984:
    v_24226 = stack[-2];
    goto v_23985;
v_23986:
    goto v_23980;
v_23981:
    goto v_23982;
v_23983:
    goto v_23984;
v_23985:
    v_24226 = Lapply2(nil, 3, v_24228, v_24227, v_24226);
    env = stack[-8];
    stack[-5] = v_24226;
    v_24226 = stack[-4];
    v_24226 = qcdr(v_24226);
    stack[-4] = v_24226;
    goto v_23921;
v_23969:
    goto v_23998;
v_23994:
    v_24227 = stack[-2];
    goto v_23995;
v_23996:
    v_24226 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23997;
v_23998:
    goto v_23994;
v_23995:
    goto v_23996;
v_23997:
    if (v_24227 == v_24226) goto v_23992;
    else goto v_23993;
v_23992:
    v_24226 = stack[-5];
    v_24226 = qcar(v_24226);
    stack[0] = v_24226;
    goto v_24016;
v_24012:
    v_24226 = stack[0];
    fn = elt(env, 11); // getrtype
    v_24227 = (*qfn1(fn))(fn, v_24226);
    env = stack[-8];
    goto v_24013;
v_24014:
    v_24226 = elt(env, 4); // list
    goto v_24015;
v_24016:
    goto v_24012;
v_24013:
    goto v_24014;
v_24015:
    if (v_24227 == v_24226) goto v_24010;
    else goto v_24011;
v_24010:
    v_24226 = elt(env, 4); // list
    stack[-3] = v_24226;
    goto v_24009;
v_24011:
    v_24226 = nil;
    goto v_24009;
    v_24226 = nil;
v_24009:
    if (v_24226 == nil) goto v_24007;
    v_24226 = stack[0];
    fn = elt(env, 13); // listeval0
    v_24226 = (*qfn1(fn))(fn, v_24226);
    env = stack[-8];
    goto v_24005;
v_24007:
    goto v_24032;
v_24028:
    v_24227 = stack[-3];
    goto v_24029;
v_24030:
    v_24226 = elt(env, 4); // list
    goto v_24031;
v_24032:
    goto v_24028;
v_24029:
    goto v_24030;
v_24031:
    if (v_24227 == v_24226) goto v_24026;
    else goto v_24027;
v_24026:
    v_24226 = lisp_true;
    qvalue(elt(env, 3)) = v_24226; // !*intstr
    v_24226 = stack[0];
    fn = elt(env, 12); // reval
    v_24226 = (*qfn1(fn))(fn, v_24226);
    env = stack[-8];
    stack[0] = v_24226;
    v_24226 = nil;
    stack[-3] = v_24226;
    qvalue(elt(env, 3)) = v_24226; // !*intstr
    v_24226 = stack[0];
    goto v_24005;
v_24027:
    v_24226 = stack[0];
    goto v_24005;
    v_24226 = nil;
v_24005:
    stack[-5] = v_24226;
    v_24226 = nil;
    stack[-4] = v_24226;
    goto v_23921;
v_23993:
    goto v_24051;
v_24047:
    v_24227 = stack[-2];
    goto v_24048;
v_24049:
    v_24226 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24050;
v_24051:
    goto v_24047;
v_24048:
    goto v_24049;
v_24050:
    v_24226 = (LispObject)lessp2(v_24227, v_24226);
    v_24226 = v_24226 ? lisp_true : nil;
    env = stack[-8];
    if (v_24226 == nil) goto v_24045;
    v_24226 = stack[-2];
    v_24226 = negate(v_24226);
    env = stack[-8];
    stack[-2] = v_24226;
    v_24226 = stack[-5];
    v_24226 = qcdr(v_24226);
    v_24226 = Lreverse(nil, v_24226);
    env = stack[-8];
    stack[-1] = v_24226;
    goto v_23931;
v_24045:
    v_24226 = stack[-5];
    v_24226 = qcdr(v_24226);
    stack[-1] = v_24226;
    goto v_23931;
v_23931:
    v_24226 = stack[0];
    if (v_24226 == nil) goto v_24066;
    v_24226 = stack[-1];
    v_24226 = qcar(v_24226);
    stack[-1] = v_24226;
    v_24226 = stack[-1];
    if (!consp(v_24226)) goto v_24072;
    else goto v_24073;
v_24072:
    goto v_24080;
v_24076:
    v_24227 = stack[-5];
    goto v_24077;
v_24078:
    v_24226 = stack[-4];
    v_24226 = qcar(v_24226);
    goto v_24079;
v_24080:
    goto v_24076;
v_24077:
    goto v_24078;
v_24079:
    fn = elt(env, 14); // parterr2
    v_24226 = (*qfn2(fn))(fn, v_24227, v_24226);
    env = stack[-8];
    v_24226 = lisp_true;
    stack[-6] = v_24226;
    goto v_24071;
v_24073:
    v_24226 = stack[-1];
    v_24226 = qcdr(v_24226);
    stack[-1] = v_24226;
    goto v_24071;
v_24071:
    goto v_24064;
v_24066:
v_24064:
    v_24226 = stack[-6];
    if (v_24226 == nil) goto v_24092;
    goto v_24090;
v_24092:
    goto v_24102;
v_24098:
    v_24226 = stack[-1];
    v_24227 = Llength(nil, v_24226);
    env = stack[-8];
    goto v_24099;
v_24100:
    v_24226 = stack[-2];
    goto v_24101;
v_24102:
    goto v_24098;
v_24099:
    goto v_24100;
v_24101:
    v_24226 = (LispObject)lessp2(v_24227, v_24226);
    v_24226 = v_24226 ? lisp_true : nil;
    env = stack[-8];
    if (v_24226 == nil) goto v_24096;
    goto v_24111;
v_24107:
    v_24227 = stack[-5];
    goto v_24108;
v_24109:
    v_24226 = stack[-4];
    v_24226 = qcar(v_24226);
    goto v_24110;
v_24111:
    goto v_24107;
v_24108:
    goto v_24109;
v_24110:
    fn = elt(env, 14); // parterr2
    v_24226 = (*qfn2(fn))(fn, v_24227, v_24226);
    env = stack[-8];
    v_24226 = lisp_true;
    stack[-6] = v_24226;
    goto v_24090;
v_24096:
    v_24226 = stack[0];
    if (v_24226 == nil) goto v_24117;
    goto v_24124;
v_24120:
    v_24227 = stack[-1];
    goto v_24121;
v_24122:
    v_24226 = stack[-2];
    goto v_24123;
v_24124:
    goto v_24120;
v_24121:
    goto v_24122;
v_24123:
    fn = elt(env, 16); // nth
    v_24226 = (*qfn2(fn))(fn, v_24227, v_24226);
    env = stack[-8];
    stack[-5] = v_24226;
    v_24226 = stack[-5];
    if (!consp(v_24226)) goto v_24134;
    goto v_24141;
v_24137:
    v_24227 = stack[-5];
    goto v_24138;
v_24139:
    v_24226 = elt(env, 6); // !*hold
    goto v_24140;
v_24141:
    goto v_24137;
v_24138:
    goto v_24139;
v_24140:
    v_24226 = Leqcar(nil, v_24227, v_24226);
    env = stack[-8];
    v_24226 = (v_24226 == nil ? lisp_true : nil);
    goto v_24132;
v_24134:
    v_24226 = nil;
    goto v_24132;
    v_24226 = nil;
v_24132:
    if (v_24226 == nil) goto v_24130;
    goto v_24153;
v_24149:
    v_24227 = elt(env, 6); // !*hold
    goto v_24150;
v_24151:
    v_24226 = stack[-5];
    goto v_24152;
v_24153:
    goto v_24149;
v_24150:
    goto v_24151;
v_24152:
    v_24226 = list2(v_24227, v_24226);
    env = stack[-8];
    stack[-5] = v_24226;
    goto v_24128;
v_24130:
v_24128:
    goto v_24090;
v_24117:
    goto v_24163;
v_24159:
    v_24227 = stack[-1];
    goto v_24160;
v_24161:
    v_24226 = stack[-2];
    goto v_24162;
v_24163:
    goto v_24159;
v_24160:
    goto v_24161;
v_24162:
    fn = elt(env, 16); // nth
    v_24226 = (*qfn2(fn))(fn, v_24227, v_24226);
    env = stack[-8];
    stack[0] = v_24226;
    goto v_24179;
v_24175:
    v_24226 = stack[0];
    fn = elt(env, 11); // getrtype
    v_24227 = (*qfn1(fn))(fn, v_24226);
    env = stack[-8];
    goto v_24176;
v_24177:
    v_24226 = elt(env, 4); // list
    goto v_24178;
v_24179:
    goto v_24175;
v_24176:
    goto v_24177;
v_24178:
    if (v_24227 == v_24226) goto v_24173;
    else goto v_24174;
v_24173:
    v_24226 = elt(env, 4); // list
    stack[-3] = v_24226;
    goto v_24172;
v_24174:
    v_24226 = nil;
    goto v_24172;
    v_24226 = nil;
v_24172:
    if (v_24226 == nil) goto v_24170;
    v_24226 = stack[0];
    fn = elt(env, 13); // listeval0
    v_24226 = (*qfn1(fn))(fn, v_24226);
    env = stack[-8];
    goto v_24168;
v_24170:
    goto v_24195;
v_24191:
    v_24227 = stack[-3];
    goto v_24192;
v_24193:
    v_24226 = elt(env, 4); // list
    goto v_24194;
v_24195:
    goto v_24191;
v_24192:
    goto v_24193;
v_24194:
    if (v_24227 == v_24226) goto v_24189;
    else goto v_24190;
v_24189:
    v_24226 = lisp_true;
    qvalue(elt(env, 3)) = v_24226; // !*intstr
    v_24226 = stack[0];
    fn = elt(env, 12); // reval
    v_24226 = (*qfn1(fn))(fn, v_24226);
    env = stack[-8];
    stack[0] = v_24226;
    v_24226 = nil;
    stack[-3] = v_24226;
    qvalue(elt(env, 3)) = v_24226; // !*intstr
    v_24226 = stack[0];
    goto v_24168;
v_24190:
    v_24226 = stack[0];
    goto v_24168;
    v_24226 = nil;
v_24168:
    stack[-5] = v_24226;
    goto v_24090;
v_24090:
    v_24226 = stack[-6];
    if (v_24226 == nil) goto v_24209;
    v_24226 = nil;
    goto v_24207;
v_24209:
    v_24226 = stack[-4];
    v_24226 = qcdr(v_24226);
    goto v_24207;
    v_24226 = nil;
v_24207:
    stack[-4] = v_24226;
v_23921:
    goto v_23910;
v_23909:
    v_24226 = stack[-6];
    if (v_24226 == nil) goto v_24219;
    v_24226 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24217;
v_24219:
    v_24226 = stack[-5];
    fn = elt(env, 12); // reval
    v_24226 = (*qfn1(fn))(fn, v_24226);
    goto v_24217;
    v_24226 = nil;
v_24217:
    ;}  // end of a binding scope
    goto v_23831;
    v_24226 = nil;
v_23831:
    return onevalue(v_24226);
}



// Code for set!-weights

static LispObject CC_setKweights(LispObject env,
                         LispObject v_23828)
{
    env = qenv(env);
    LispObject v_23883;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23828);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_23883 = v_23828;
// end of prologue
    goto v_23840;
v_23836:
    stack[-4] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23837;
v_23838:
    v_23883 = qcdr(v_23883);
    stack[-3] = v_23883;
    v_23883 = stack[-3];
    if (v_23883 == nil) goto v_23852;
    else goto v_23853;
v_23852:
    v_23883 = nil;
    goto v_23846;
v_23853:
    v_23883 = (LispObject)16+TAG_FIXNUM; // 1
    v_23883 = ncons(v_23883);
    env = stack[-5];
    stack[-1] = v_23883;
    stack[-2] = v_23883;
v_23847:
    v_23883 = stack[-3];
    v_23883 = qcdr(v_23883);
    stack[-3] = v_23883;
    v_23883 = stack[-3];
    if (v_23883 == nil) goto v_23865;
    else goto v_23866;
v_23865:
    v_23883 = stack[-2];
    goto v_23846;
v_23866:
    goto v_23874;
v_23870:
    stack[0] = stack[-1];
    goto v_23871;
v_23872:
    v_23883 = (LispObject)16+TAG_FIXNUM; // 1
    v_23883 = ncons(v_23883);
    env = stack[-5];
    goto v_23873;
v_23874:
    goto v_23870;
v_23871:
    goto v_23872;
v_23873:
    v_23883 = Lrplacd(nil, stack[0], v_23883);
    env = stack[-5];
    v_23883 = stack[-1];
    v_23883 = qcdr(v_23883);
    stack[-1] = v_23883;
    goto v_23847;
v_23846:
    goto v_23839;
v_23840:
    goto v_23836;
v_23837:
    goto v_23838;
v_23839:
    v_23883 = cons(stack[-4], v_23883);
        return Lnreverse(nil, v_23883);
    return onevalue(v_23883);
}



// Code for simp!-prop!-dist

static LispObject CC_simpKpropKdist(LispObject env,
                         LispObject v_23828)
{
    env = qenv(env);
    LispObject v_23962, v_23963, v_23964;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23828);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_23963 = v_23828;
// end of prologue
    goto v_23839;
v_23835:
    v_23964 = v_23963;
    goto v_23836;
v_23837:
    v_23962 = elt(env, 1); // plus
    goto v_23838;
v_23839:
    goto v_23835;
v_23836:
    goto v_23837;
v_23838:
    if (!consp(v_23964)) goto v_23833;
    v_23964 = qcar(v_23964);
    if (v_23964 == v_23962) goto v_23832;
    else goto v_23833;
v_23832:
    v_23962 = v_23963;
    v_23962 = qcdr(v_23962);
    v_23963 = v_23962;
    goto v_23831;
v_23833:
    v_23962 = v_23963;
    v_23962 = ncons(v_23962);
    env = stack[-4];
    v_23963 = v_23962;
    goto v_23831;
v_23831:
    v_23962 = v_23963;
    stack[-3] = v_23962;
    v_23962 = stack[-3];
    if (v_23962 == nil) goto v_23857;
    else goto v_23858;
v_23857:
    v_23962 = nil;
    goto v_23852;
v_23858:
    v_23962 = stack[-3];
    v_23962 = qcar(v_23962);
    v_23964 = v_23962;
    goto v_23874;
v_23870:
    v_23963 = v_23964;
    goto v_23871;
v_23872:
    v_23962 = elt(env, 2); // times
    goto v_23873;
v_23874:
    goto v_23870;
v_23871:
    goto v_23872;
v_23873:
    if (!consp(v_23963)) goto v_23868;
    v_23963 = qcar(v_23963);
    if (v_23963 == v_23962) goto v_23867;
    else goto v_23868;
v_23867:
    v_23962 = v_23964;
    v_23962 = qcdr(v_23962);
    goto v_23866;
v_23868:
    v_23962 = v_23964;
    v_23962 = ncons(v_23962);
    env = stack[-4];
    goto v_23866;
    v_23962 = nil;
v_23866:
    v_23964 = v_23962;
    v_23962 = v_23964;
    v_23962 = qcar(v_23962);
    if (is_number(v_23962)) goto v_23885;
    else goto v_23886;
v_23885:
    v_23962 = v_23964;
    v_23962 = qcdr(v_23962);
    v_23964 = v_23962;
    goto v_23884;
v_23886:
v_23884:
    goto v_23896;
v_23892:
    v_23963 = v_23964;
    goto v_23893;
v_23894:
    v_23962 = elt(env, 3); // lambda_iff2c8okfzyq1
    goto v_23895;
v_23896:
    goto v_23892;
v_23893:
    goto v_23894;
v_23895:
    fn = elt(env, 5); // sort
    v_23962 = (*qfn2(fn))(fn, v_23963, v_23962);
    env = stack[-4];
    v_23962 = ncons(v_23962);
    env = stack[-4];
    stack[-1] = v_23962;
    stack[-2] = v_23962;
v_23853:
    v_23962 = stack[-3];
    v_23962 = qcdr(v_23962);
    stack[-3] = v_23962;
    v_23962 = stack[-3];
    if (v_23962 == nil) goto v_23903;
    else goto v_23904;
v_23903:
    v_23962 = stack[-2];
    goto v_23852;
v_23904:
    goto v_23912;
v_23908:
    stack[0] = stack[-1];
    goto v_23909;
v_23910:
    v_23962 = stack[-3];
    v_23962 = qcar(v_23962);
    v_23964 = v_23962;
    goto v_23927;
v_23923:
    v_23963 = v_23964;
    goto v_23924;
v_23925:
    v_23962 = elt(env, 2); // times
    goto v_23926;
v_23927:
    goto v_23923;
v_23924:
    goto v_23925;
v_23926:
    if (!consp(v_23963)) goto v_23921;
    v_23963 = qcar(v_23963);
    if (v_23963 == v_23962) goto v_23920;
    else goto v_23921;
v_23920:
    v_23962 = v_23964;
    v_23962 = qcdr(v_23962);
    goto v_23919;
v_23921:
    v_23962 = v_23964;
    v_23962 = ncons(v_23962);
    env = stack[-4];
    goto v_23919;
    v_23962 = nil;
v_23919:
    v_23964 = v_23962;
    v_23962 = v_23964;
    v_23962 = qcar(v_23962);
    if (is_number(v_23962)) goto v_23938;
    else goto v_23939;
v_23938:
    v_23962 = v_23964;
    v_23962 = qcdr(v_23962);
    v_23964 = v_23962;
    goto v_23937;
v_23939:
v_23937:
    goto v_23949;
v_23945:
    v_23963 = v_23964;
    goto v_23946;
v_23947:
    v_23962 = elt(env, 3); // lambda_iff2c8okfzyq1
    goto v_23948;
v_23949:
    goto v_23945;
v_23946:
    goto v_23947;
v_23948:
    fn = elt(env, 5); // sort
    v_23962 = (*qfn2(fn))(fn, v_23963, v_23962);
    env = stack[-4];
    v_23962 = ncons(v_23962);
    env = stack[-4];
    goto v_23911;
v_23912:
    goto v_23908;
v_23909:
    goto v_23910;
v_23911:
    v_23962 = Lrplacd(nil, stack[0], v_23962);
    env = stack[-4];
    v_23962 = stack[-1];
    v_23962 = qcdr(v_23962);
    stack[-1] = v_23962;
    goto v_23853;
v_23852:
    v_23963 = v_23962;
    goto v_23959;
v_23955:
    goto v_23956;
v_23957:
    v_23962 = elt(env, 4); // simp!-prop!-order
    goto v_23958;
v_23959:
    goto v_23955;
v_23956:
    goto v_23957;
v_23958:
    {
        fn = elt(env, 5); // sort
        return (*qfn2(fn))(fn, v_23963, v_23962);
    }
}



// Code for lambda_iff2c8okfzyq1

static LispObject CC_lambda_iff2c8okfzyq1(LispObject env,
                         LispObject v_23828, LispObject v_23829)
{
    env = qenv(env);
    LispObject v_23843, v_23844;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23843 = v_23829;
    v_23844 = v_23828;
// end of prologue
    goto v_23836;
v_23832:
    v_23844 = qcdr(v_23844);
    v_23844 = qcar(v_23844);
    goto v_23833;
v_23834:
    v_23843 = qcdr(v_23843);
    v_23843 = qcar(v_23843);
    goto v_23835;
v_23836:
    goto v_23832;
v_23833:
    goto v_23834;
v_23835:
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_23844, v_23843);
    }
}



// Code for lambda_iff2c8okfzyq1

static LispObject CC1_lambda_iff2c8okfzyq1(LispObject env,
                         LispObject v_23828, LispObject v_23829)
{
    env = qenv(env);
    LispObject v_23843, v_23844;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23843 = v_23829;
    v_23844 = v_23828;
// end of prologue
    goto v_23836;
v_23832:
    v_23844 = qcdr(v_23844);
    v_23844 = qcar(v_23844);
    goto v_23833;
v_23834:
    v_23843 = qcdr(v_23843);
    v_23843 = qcar(v_23843);
    goto v_23835;
v_23836:
    goto v_23832;
v_23833:
    goto v_23834;
v_23835:
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_23844, v_23843);
    }
}



// Code for lesspcar

static LispObject CC_lesspcar(LispObject env,
                         LispObject v_23828, LispObject v_23829)
{
    env = qenv(env);
    LispObject v_23841, v_23842;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23841 = v_23829;
    v_23842 = v_23828;
// end of prologue
    goto v_23836;
v_23832:
    v_23842 = qcar(v_23842);
    goto v_23833;
v_23834:
    v_23841 = qcar(v_23841);
    goto v_23835;
v_23836:
    goto v_23832;
v_23833:
    goto v_23834;
v_23835:
        return Llessp(nil, v_23842, v_23841);
}



// Code for algmodep

static LispObject CC_algmodep(LispObject env,
                         LispObject v_23828)
{
    env = qenv(env);
    LispObject v_23847, v_23848;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23848 = v_23828;
// end of prologue
    v_23847 = v_23848;
    if (!consp(v_23847)) goto v_23833;
    goto v_23839;
v_23835:
    v_23847 = v_23848;
    v_23847 = qcar(v_23847);
    goto v_23836;
v_23837:
    v_23848 = elt(env, 1); // (aeval aeval!*)
    goto v_23838;
v_23839:
    goto v_23835;
v_23836:
    goto v_23837;
v_23838:
    v_23847 = Lmemq(nil, v_23847, v_23848);
    goto v_23831;
v_23833:
    v_23847 = nil;
    goto v_23831;
    v_23847 = nil;
v_23831:
    return onevalue(v_23847);
}



// Code for talp_trygaussvar

static LispObject CC_talp_trygaussvar(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23909, v_23910, v_23911;
    LispObject fn;
    LispObject v_23830, v_23829, v_23828;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_trygaussvar");
    va_start(aa, nargs);
    v_23828 = va_arg(aa, LispObject);
    v_23829 = va_arg(aa, LispObject);
    v_23830 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_23830,v_23829,v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_23828,v_23829,v_23830);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_23830;
    stack[-1] = v_23829;
    stack[-2] = v_23828;
// end of prologue
    v_23909 = stack[-1];
    fn = elt(env, 4); // talp_atfp
    v_23909 = (*qfn1(fn))(fn, v_23909);
    env = stack[-3];
    if (v_23909 == nil) goto v_23835;
    goto v_23843;
v_23839:
    v_23910 = stack[-2];
    goto v_23840;
v_23841:
    v_23909 = stack[-1];
    goto v_23842;
v_23843:
    goto v_23839;
v_23840:
    goto v_23841;
v_23842:
    {
        fn = elt(env, 5); // talp_qesolset
        return (*qfn2(fn))(fn, v_23910, v_23909);
    }
v_23835:
    goto v_23852;
v_23848:
    v_23909 = stack[-1];
    if (!consp(v_23909)) goto v_23855;
    else goto v_23856;
v_23855:
    v_23909 = stack[-1];
    v_23910 = v_23909;
    goto v_23854;
v_23856:
    v_23909 = stack[-1];
    v_23909 = qcar(v_23909);
    v_23910 = v_23909;
    goto v_23854;
    v_23910 = nil;
v_23854:
    goto v_23849;
v_23850:
    v_23909 = elt(env, 1); // and
    goto v_23851;
v_23852:
    goto v_23848;
v_23849:
    goto v_23850;
v_23851:
    if (v_23910 == v_23909) goto v_23846;
    else goto v_23847;
v_23846:
    goto v_23871;
v_23865:
    v_23911 = stack[-2];
    goto v_23866;
v_23867:
    v_23909 = stack[-1];
    v_23910 = qcdr(v_23909);
    goto v_23868;
v_23869:
    v_23909 = stack[0];
    goto v_23870;
v_23871:
    goto v_23865;
v_23866:
    goto v_23867;
v_23868:
    goto v_23869;
v_23870:
    {
        fn = elt(env, 6); // talp_gaussand
        return (*qfnn(fn))(fn, 3, v_23911, v_23910, v_23909);
    }
v_23847:
    goto v_23882;
v_23878:
    v_23909 = stack[-1];
    if (!consp(v_23909)) goto v_23885;
    else goto v_23886;
v_23885:
    v_23909 = stack[-1];
    v_23910 = v_23909;
    goto v_23884;
v_23886:
    v_23909 = stack[-1];
    v_23909 = qcar(v_23909);
    v_23910 = v_23909;
    goto v_23884;
    v_23910 = nil;
v_23884:
    goto v_23879;
v_23880:
    v_23909 = elt(env, 2); // or
    goto v_23881;
v_23882:
    goto v_23878;
v_23879:
    goto v_23880;
v_23881:
    if (v_23910 == v_23909) goto v_23876;
    else goto v_23877;
v_23876:
    goto v_23901;
v_23895:
    v_23911 = stack[-2];
    goto v_23896;
v_23897:
    v_23909 = stack[-1];
    v_23910 = qcdr(v_23909);
    goto v_23898;
v_23899:
    v_23909 = stack[0];
    goto v_23900;
v_23901:
    goto v_23895;
v_23896:
    goto v_23897;
v_23898:
    goto v_23899;
v_23900:
    {
        fn = elt(env, 7); // talp_gaussor
        return (*qfnn(fn))(fn, 3, v_23911, v_23910, v_23909);
    }
v_23877:
    v_23909 = elt(env, 3); // failed
    goto v_23833;
    v_23909 = nil;
v_23833:
    return onevalue(v_23909);
}



// Code for fctrf

static LispObject CC_fctrf(LispObject env,
                         LispObject v_23828)
{
    env = qenv(env);
    LispObject v_24052, v_24053, v_24054;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23828);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_23828;
// end of prologue
    v_24053 = qvalue(elt(env, 1)); // !*exp
    v_24052 = qvalue(elt(env, 2)); // ncmp!*
// Binding !*exp
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
    qvalue(elt(env, 1)) = v_24053; // !*exp
// Binding ncmp!*
// FLUIDBIND: reloadenv=7 litvec-offset=2 saveloc=4
{   bind_fluid_stack bind_fluid_var(-7, 2, -4);
    qvalue(elt(env, 2)) = v_24052; // ncmp!*
// Binding !*ezgcd
// FLUIDBIND: reloadenv=7 litvec-offset=3 saveloc=3
{   bind_fluid_stack bind_fluid_var(-7, 3, -3);
    qvalue(elt(env, 3)) = nil; // !*ezgcd
// Binding !*gcd
// FLUIDBIND: reloadenv=7 litvec-offset=4 saveloc=2
{   bind_fluid_stack bind_fluid_var(-7, 4, -2);
    qvalue(elt(env, 4)) = nil; // !*gcd
    stack[-1] = nil;
    v_24052 = stack[-5];
    if (!consp(v_24052)) goto v_23847;
    else goto v_23848;
v_23847:
    v_24052 = lisp_true;
    goto v_23846;
v_23848:
    v_24052 = stack[-5];
    v_24052 = qcar(v_24052);
    v_24052 = (consp(v_24052) ? nil : lisp_true);
    goto v_23846;
    v_24052 = nil;
v_23846:
    if (v_24052 == nil) goto v_23844;
    v_24052 = stack[-5];
    v_24052 = ncons(v_24052);
    goto v_23840;
v_23844:
    v_24052 = qvalue(elt(env, 2)); // ncmp!*
    if (v_24052 == nil) goto v_23859;
    v_24052 = stack[-5];
    fn = elt(env, 14); // noncomfp
    v_24052 = (*qfn1(fn))(fn, v_24052);
    env = stack[-7];
    if (v_24052 == nil) goto v_23862;
    else goto v_23859;
v_23862:
    v_24052 = nil;
    qvalue(elt(env, 2)) = v_24052; // ncmp!*
    goto v_23842;
v_23859:
v_23842:
    v_24052 = lisp_true;
    qvalue(elt(env, 4)) = v_24052; // !*gcd
    v_24052 = qvalue(elt(env, 5)); // !*limitedfactors
    if (v_24052 == nil) goto v_23873;
    else goto v_23874;
v_23873:
    v_24052 = qvalue(elt(env, 6)); // dmode!*
    v_24052 = (v_24052 == nil ? lisp_true : nil);
    goto v_23872;
v_23874:
    v_24052 = nil;
    goto v_23872;
    v_24052 = nil;
v_23872:
    if (v_24052 == nil) goto v_23870;
    v_24052 = lisp_true;
    qvalue(elt(env, 3)) = v_24052; // !*ezgcd
    goto v_23868;
v_23870:
v_23868:
    v_24052 = qvalue(elt(env, 7)); // !*mcd
    if (v_24052 == nil) goto v_23884;
    else goto v_23885;
v_23884:
    goto v_23894;
v_23888:
    v_24054 = elt(env, 8); // poly
    goto v_23889;
v_23890:
    v_24053 = (LispObject)240+TAG_FIXNUM; // 15
    goto v_23891;
v_23892:
    v_24052 = elt(env, 9); // "Factorization invalid with MCD off"
    goto v_23893;
v_23894:
    goto v_23888;
v_23889:
    goto v_23890;
v_23891:
    goto v_23892;
v_23893:
    fn = elt(env, 15); // rerror
    v_24052 = (*qfnn(fn))(fn, 3, v_24054, v_24053, v_24052);
    env = stack[-7];
    goto v_23883;
v_23885:
    v_24052 = qvalue(elt(env, 1)); // !*exp
    if (v_24052 == nil) goto v_23898;
    else goto v_23899;
v_23898:
    v_24052 = lisp_true;
    qvalue(elt(env, 1)) = v_24052; // !*exp
    goto v_23909;
v_23905:
    v_24053 = stack[-5];
    goto v_23906;
v_23907:
    v_24052 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23908;
v_23909:
    goto v_23905;
v_23906:
    goto v_23907;
v_23908:
    v_24052 = cons(v_24053, v_24052);
    env = stack[-7];
    fn = elt(env, 16); // resimp
    v_24052 = (*qfn1(fn))(fn, v_24052);
    env = stack[-7];
    fn = elt(env, 17); // !*q2f
    v_24052 = (*qfn1(fn))(fn, v_24052);
    env = stack[-7];
    stack[-5] = v_24052;
    goto v_23883;
v_23899:
v_23883:
    goto v_23920;
v_23916:
    v_24053 = qvalue(elt(env, 6)); // dmode!*
    goto v_23917;
v_23918:
    v_24052 = elt(env, 10); // !:rn!:
    goto v_23919;
v_23920:
    goto v_23916;
v_23917:
    goto v_23918;
v_23919:
    if (v_24053 == v_24052) goto v_23914;
    else goto v_23915;
v_23914:
    v_24052 = nil;
    qvalue(elt(env, 6)) = v_24052; // dmode!*
    v_24052 = nil;
    v_24052 = ncons(v_24052);
    env = stack[-7];
    qvalue(elt(env, 11)) = v_24052; // alglist!*
    v_24052 = stack[-5];
    fn = elt(env, 18); // prepf
    v_24052 = (*qfn1(fn))(fn, v_24052);
    env = stack[-7];
    fn = elt(env, 19); // simp
    v_24052 = (*qfn1(fn))(fn, v_24052);
    env = stack[-7];
    stack[0] = v_24052;
    v_24052 = stack[0];
    v_24052 = qcdr(v_24052);
    if (!consp(v_24052)) goto v_23931;
    else goto v_23932;
v_23931:
    v_24052 = stack[0];
    v_24052 = qcdr(v_24052);
    stack[-1] = v_24052;
    v_24052 = stack[0];
    v_24052 = qcar(v_24052);
    stack[-5] = v_24052;
    goto v_23930;
v_23932:
    v_24052 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_24052;
    goto v_23930;
v_23930:
    goto v_23913;
v_23915:
v_23913:
    v_24052 = qvalue(elt(env, 2)); // ncmp!*
    if (v_24052 == nil) goto v_23944;
    else goto v_23945;
v_23944:
    v_24052 = stack[-5];
    fn = elt(env, 20); // sf2ss
    v_24052 = (*qfn1(fn))(fn, v_24052);
    env = stack[-7];
    stack[0] = v_24052;
    v_24052 = stack[0];
    fn = elt(env, 21); // homogp
    v_24052 = (*qfn1(fn))(fn, v_24052);
    env = stack[-7];
    if (v_24052 == nil) goto v_23952;
    v_24052 = qvalue(elt(env, 12)); // !*trfac
    if (v_24052 == nil) goto v_23958;
    v_24052 = elt(env, 13); // "This polynomial is homogeneous - variables scaled"
    fn = elt(env, 22); // prin2t
    v_24052 = (*qfn1(fn))(fn, v_24052);
    env = stack[-7];
    goto v_23956;
v_23958:
v_23956:
    goto v_23967;
v_23963:
    v_24052 = stack[0];
    v_24052 = qcar(v_24052);
    v_24052 = qcar(v_24052);
    stack[-1] = qcar(v_24052);
    goto v_23964;
v_23965:
    v_24052 = stack[0];
    v_24052 = qcdr(v_24052);
    v_24052 = qcar(v_24052);
    v_24052 = qcar(v_24052);
    v_24052 = qcar(v_24052);
    fn = elt(env, 23); // listsum
    v_24052 = (*qfn1(fn))(fn, v_24052);
    env = stack[-7];
    goto v_23966;
v_23967:
    goto v_23963;
v_23964:
    goto v_23965;
v_23966:
    v_24052 = cons(stack[-1], v_24052);
    env = stack[-7];
    stack[-5] = v_24052;
    goto v_23987;
v_23981:
    v_24052 = stack[0];
    stack[-1] = qcar(v_24052);
    goto v_23982;
v_23983:
    v_24052 = stack[0];
    v_24052 = qcdr(v_24052);
    v_24052 = qcar(v_24052);
    fn = elt(env, 24); // subs0
    v_24052 = (*qfn1(fn))(fn, v_24052);
    env = stack[-7];
    v_24053 = Lreverse(nil, v_24052);
    env = stack[-7];
    goto v_23984;
v_23985:
    v_24052 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23986;
v_23987:
    goto v_23981;
v_23982:
    goto v_23983;
v_23984:
    goto v_23985;
v_23986:
    v_24052 = list2star(stack[-1], v_24053, v_24052);
    env = stack[-7];
    fn = elt(env, 25); // ss2sf
    v_24052 = (*qfn1(fn))(fn, v_24052);
    env = stack[-7];
    fn = elt(env, 26); // fctrf1
    v_24052 = (*qfn1(fn))(fn, v_24052);
    env = stack[-7];
    stack[0] = v_24052;
    goto v_24001;
v_23997:
    v_24053 = stack[-5];
    goto v_23998;
v_23999:
    v_24052 = stack[0];
    goto v_24000;
v_24001:
    goto v_23997;
v_23998:
    goto v_23999;
v_24000:
    fn = elt(env, 27); // rconst
    v_24052 = (*qfn2(fn))(fn, v_24053, v_24052);
    env = stack[-7];
    stack[0] = v_24052;
    goto v_24009;
v_24005:
    v_24052 = stack[0];
    stack[-1] = qcar(v_24052);
    goto v_24006;
v_24007:
    v_24052 = stack[0];
    v_24052 = qcdr(v_24052);
    fn = elt(env, 28); // sort!-factors
    v_24052 = (*qfn1(fn))(fn, v_24052);
    env = stack[-7];
    goto v_24008;
v_24009:
    goto v_24005;
v_24006:
    goto v_24007;
v_24008:
    v_24052 = cons(stack[-1], v_24052);
    goto v_23840;
v_23952:
    goto v_23943;
v_23945:
v_23943:
    v_24052 = stack[-5];
    fn = elt(env, 26); // fctrf1
    v_24052 = (*qfn1(fn))(fn, v_24052);
    env = stack[-7];
    stack[-5] = v_24052;
    v_24052 = stack[-1];
    if (v_24052 == nil) goto v_24020;
    v_24052 = nil;
    v_24052 = ncons(v_24052);
    env = stack[-7];
    qvalue(elt(env, 11)) = v_24052; // alglist!*
    v_24052 = elt(env, 10); // !:rn!:
    qvalue(elt(env, 6)) = v_24052; // dmode!*
    goto v_24030;
v_24026:
    stack[0] = stack[-5];
    goto v_24027;
v_24028:
    goto v_24037;
v_24033:
    v_24052 = stack[-5];
    v_24053 = qcar(v_24052);
    goto v_24034;
v_24035:
    v_24052 = stack[-1];
    goto v_24036;
v_24037:
    goto v_24033;
v_24034:
    goto v_24035;
v_24036:
    fn = elt(env, 29); // quotf!*
    v_24052 = (*qfn2(fn))(fn, v_24053, v_24052);
    env = stack[-7];
    goto v_24029;
v_24030:
    goto v_24026;
v_24027:
    goto v_24028;
v_24029:
    fn = elt(env, 30); // setcar
    v_24052 = (*qfn2(fn))(fn, stack[0], v_24052);
    env = stack[-7];
    goto v_24018;
v_24020:
v_24018:
    goto v_24046;
v_24042:
    v_24052 = stack[-5];
    stack[0] = qcar(v_24052);
    goto v_24043;
v_24044:
    v_24052 = stack[-5];
    v_24052 = qcdr(v_24052);
    fn = elt(env, 28); // sort!-factors
    v_24052 = (*qfn1(fn))(fn, v_24052);
    env = stack[-7];
    goto v_24045;
v_24046:
    goto v_24042;
v_24043:
    goto v_24044;
v_24045:
    v_24052 = cons(stack[0], v_24052);
v_23840:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_24052);
}



// Code for ofsf_anegrel

static LispObject CC_ofsf_anegrel(LispObject env,
                         LispObject v_23828)
{
    env = qenv(env);
    LispObject v_23851, v_23852, v_23853;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23828);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_23853 = v_23828;
// end of prologue
    goto v_23837;
v_23833:
    v_23852 = v_23853;
    goto v_23834;
v_23835:
    v_23851 = elt(env, 1); // ((equal . equal) (neq . neq) (leq . geq) (geq . leq) (lessp . greaterp) (greaterp . lessp))
    goto v_23836;
v_23837:
    goto v_23833;
v_23834:
    goto v_23835;
v_23836:
    v_23851 = Latsoc(nil, v_23852, v_23851);
    v_23851 = qcdr(v_23851);
    if (v_23851 == nil) goto v_23832;
    else goto v_23831;
v_23832:
    goto v_23848;
v_23844:
    v_23851 = elt(env, 2); // "ofsf_anegrel: unknown operator "
    goto v_23845;
v_23846:
    v_23852 = v_23853;
    goto v_23847;
v_23848:
    goto v_23844;
v_23845:
    goto v_23846;
v_23847:
    v_23851 = list2(v_23851, v_23852);
    env = stack[0];
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_23851);
    }
v_23831:
    return onevalue(v_23851);
}



// Code for diffrd

static LispObject CC_diffrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23861, v_23862;
    LispObject fn;
    argcheck(nargs, 0, "diffrd");
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
    fn = elt(env, 3); // lex
    v_23861 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_23842;
v_23838:
    v_23862 = qvalue(elt(env, 1)); // char
    goto v_23839;
v_23840:
    v_23861 = elt(env, 2); // (b v a r)
    goto v_23841;
v_23842:
    goto v_23838;
v_23839:
    goto v_23840;
v_23841:
    if (equal(v_23862, v_23861)) goto v_23836;
    else goto v_23837;
v_23836:
    fn = elt(env, 4); // bvarrd
    v_23861 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_23861;
    fn = elt(env, 3); // lex
    v_23861 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_23835;
v_23837:
    v_23861 = nil;
    stack[-1] = v_23861;
    goto v_23835;
v_23835:
    fn = elt(env, 5); // mathml2
    v_23861 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[0] = v_23861;
    fn = elt(env, 3); // lex
    v_23861 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_23858;
v_23854:
    v_23862 = stack[-1];
    goto v_23855;
v_23856:
    v_23861 = stack[0];
    goto v_23857;
v_23858:
    goto v_23854;
v_23855:
    goto v_23856;
v_23857:
    v_23861 = list2(v_23862, v_23861);
    env = stack[-2];
    {
        fn = elt(env, 6); // diff2
        return (*qfn1(fn))(fn, v_23861);
    }
    return onevalue(v_23861);
}



// Code for findelem2

static LispObject CC_findelem2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23887, v_23888, v_23889, v_23890, v_23891;
    LispObject v_23830, v_23829, v_23828;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "findelem2");
    va_start(aa, nargs);
    v_23828 = va_arg(aa, LispObject);
    v_23829 = va_arg(aa, LispObject);
    v_23830 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_23830,v_23829,v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_23828,v_23829,v_23830);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_23887 = v_23830;
    v_23888 = v_23829;
    v_23889 = v_23828;
// end of prologue
    v_23890 = v_23889;
    v_23890 = Lconsp(nil, v_23890);
    env = stack[0];
    if (v_23890 == nil) goto v_23841;
    goto v_23850;
v_23846:
    v_23890 = v_23889;
    v_23890 = qcar(v_23890);
    goto v_23847;
v_23848:
    v_23891 = elt(env, 1); // sparsemat
    goto v_23849;
v_23850:
    goto v_23846;
v_23847:
    goto v_23848;
v_23849:
    if (v_23890 == v_23891) goto v_23845;
    else goto v_23841;
v_23845:
    v_23889 = qcdr(v_23889);
    v_23889 = qcar(v_23889);
    goto v_23839;
v_23841:
    goto v_23839;
v_23839:
    goto v_23864;
v_23860:
    goto v_23861;
v_23862:
    goto v_23863;
v_23864:
    goto v_23860;
v_23861:
    goto v_23862;
v_23863:
    v_23888 = *(LispObject *)((char *)v_23889 + (CELL-TAG_VECTOR) + (((intptr_t)v_23888-TAG_FIXNUM)/(16/CELL)));
    goto v_23872;
v_23868:
    goto v_23869;
v_23870:
    goto v_23871;
v_23872:
    goto v_23868;
v_23869:
    goto v_23870;
v_23871:
    v_23887 = Latsoc(nil, v_23887, v_23888);
    v_23888 = v_23887;
    v_23887 = v_23888;
    if (v_23887 == nil) goto v_23878;
    else goto v_23879;
v_23878:
    v_23887 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23877;
v_23879:
    v_23887 = v_23888;
    v_23887 = qcdr(v_23887);
    goto v_23877;
v_23877:
    return onevalue(v_23887);
}



// Code for inszzz

static LispObject CC_inszzz(LispObject env,
                         LispObject v_23828, LispObject v_23829)
{
    env = qenv(env);
    LispObject v_23948, v_23949;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23829,v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23828,v_23829);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_23829;
    stack[-2] = v_23828;
// end of prologue
    stack[-3] = nil;
v_23834:
    v_23948 = stack[-1];
    if (v_23948 == nil) goto v_23841;
    else goto v_23842;
v_23841:
    v_23948 = lisp_true;
    goto v_23840;
v_23842:
    goto v_23852;
v_23848:
    v_23948 = stack[-1];
    v_23948 = qcar(v_23948);
    v_23949 = qcar(v_23948);
    goto v_23849;
v_23850:
    v_23948 = stack[-2];
    v_23948 = qcar(v_23948);
    goto v_23851;
v_23852:
    goto v_23848;
v_23849:
    goto v_23850;
v_23851:
    v_23948 = (LispObject)lessp2(v_23949, v_23948);
    v_23948 = v_23948 ? lisp_true : nil;
    env = stack[-4];
    goto v_23840;
    v_23948 = nil;
v_23840:
    if (v_23948 == nil) goto v_23838;
    goto v_23863;
v_23859:
    stack[0] = stack[-3];
    goto v_23860;
v_23861:
    goto v_23870;
v_23866:
    v_23949 = stack[-2];
    goto v_23867;
v_23868:
    v_23948 = stack[-1];
    goto v_23869;
v_23870:
    goto v_23866;
v_23867:
    goto v_23868;
v_23869:
    v_23948 = cons(v_23949, v_23948);
    env = stack[-4];
    goto v_23862;
v_23863:
    goto v_23859;
v_23860:
    goto v_23861;
v_23862:
    {
        LispObject v_23954 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_23954, v_23948);
    }
v_23838:
    goto v_23879;
v_23875:
    v_23948 = stack[-1];
    v_23948 = qcar(v_23948);
    v_23949 = qcar(v_23948);
    goto v_23876;
v_23877:
    v_23948 = stack[-2];
    v_23948 = qcar(v_23948);
    goto v_23878;
v_23879:
    goto v_23875;
v_23876:
    goto v_23877;
v_23878:
    if (equal(v_23949, v_23948)) goto v_23873;
    else goto v_23874;
v_23873:
    goto v_23890;
v_23886:
    v_23948 = stack[-1];
    v_23948 = qcar(v_23948);
    stack[0] = qcdr(v_23948);
    goto v_23887;
v_23888:
    goto v_23899;
v_23895:
    v_23948 = stack[-1];
    v_23948 = qcar(v_23948);
    v_23948 = qcdr(v_23948);
    v_23949 = qcar(v_23948);
    goto v_23896;
v_23897:
    v_23948 = stack[-2];
    v_23948 = qcdr(v_23948);
    v_23948 = qcar(v_23948);
    goto v_23898;
v_23899:
    goto v_23895;
v_23896:
    goto v_23897;
v_23898:
    fn = elt(env, 2); // dm!-plus
    v_23948 = (*qfn2(fn))(fn, v_23949, v_23948);
    env = stack[-4];
    goto v_23889;
v_23890:
    goto v_23886;
v_23887:
    goto v_23888;
v_23889:
    v_23948 = Lrplaca(nil, stack[0], v_23948);
    env = stack[-4];
    v_23948 = stack[-1];
    v_23948 = qcar(v_23948);
    v_23948 = qcdr(v_23948);
    v_23948 = qcar(v_23948);
    fn = elt(env, 3); // zeropp
    v_23948 = (*qfn1(fn))(fn, v_23948);
    env = stack[-4];
    if (v_23948 == nil) goto v_23910;
    goto v_23921;
v_23917:
    v_23949 = stack[-3];
    goto v_23918;
v_23919:
    v_23948 = stack[-1];
    v_23948 = qcdr(v_23948);
    goto v_23920;
v_23921:
    goto v_23917;
v_23918:
    goto v_23919;
v_23920:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_23949, v_23948);
    }
v_23910:
    goto v_23932;
v_23928:
    v_23949 = stack[-3];
    goto v_23929;
v_23930:
    v_23948 = stack[-1];
    goto v_23931;
v_23932:
    goto v_23928;
v_23929:
    goto v_23930;
v_23931:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_23949, v_23948);
    }
    goto v_23836;
v_23874:
    goto v_23942;
v_23938:
    v_23948 = stack[-1];
    v_23949 = qcar(v_23948);
    goto v_23939;
v_23940:
    v_23948 = stack[-3];
    goto v_23941;
v_23942:
    goto v_23938;
v_23939:
    goto v_23940;
v_23941:
    v_23948 = cons(v_23949, v_23948);
    env = stack[-4];
    stack[-3] = v_23948;
    v_23948 = stack[-1];
    v_23948 = qcdr(v_23948);
    stack[-1] = v_23948;
    goto v_23834;
v_23836:
    v_23948 = nil;
    return onevalue(v_23948);
}



// Code for listpri

static LispObject CC_listpri(LispObject env,
                         LispObject v_23828)
{
    env = qenv(env);
    LispObject v_23911, v_23912;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23828);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_23828;
// end of prologue
    v_23911 = stack[-2];
    stack[0] = v_23911;
    v_23911 = stack[-2];
    v_23911 = qcdr(v_23911);
    stack[-2] = v_23911;
    v_23911 = elt(env, 1); // !*lcbkt!*
    if (!symbolp(v_23911)) v_23911 = nil;
    else { v_23911 = qfastgets(v_23911);
           if (v_23911 != nil) { v_23911 = elt(v_23911, 37); // prtch
#ifdef RECORD_GET
             if (v_23911 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v_23911 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v_23911 == SPID_NOPROP) v_23911 = nil; }}
#endif
    fn = elt(env, 7); // prin2!*
    v_23911 = (*qfn1(fn))(fn, v_23911);
    env = stack[-4];
    v_23911 = qvalue(elt(env, 2)); // orig!*
    stack[-3] = v_23911;
    goto v_23853;
v_23849:
    v_23912 = qvalue(elt(env, 3)); // posn!*
    goto v_23850;
v_23851:
    v_23911 = (LispObject)288+TAG_FIXNUM; // 18
    goto v_23852;
v_23853:
    goto v_23849;
v_23850:
    goto v_23851;
v_23852:
    v_23911 = (LispObject)lessp2(v_23912, v_23911);
    v_23911 = v_23911 ? lisp_true : nil;
    env = stack[-4];
    if (v_23911 == nil) goto v_23847;
    v_23911 = qvalue(elt(env, 3)); // posn!*
    goto v_23845;
v_23847:
    goto v_23864;
v_23860:
    v_23912 = qvalue(elt(env, 2)); // orig!*
    goto v_23861;
v_23862:
    v_23911 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_23863;
v_23864:
    goto v_23860;
v_23861:
    goto v_23862;
v_23863:
    v_23911 = plus2(v_23912, v_23911);
    env = stack[-4];
    goto v_23845;
    v_23911 = nil;
v_23845:
    qvalue(elt(env, 2)) = v_23911; // orig!*
    v_23911 = stack[-2];
    if (v_23911 == nil) goto v_23869;
    else goto v_23870;
v_23869:
    goto v_23836;
v_23870:
    goto v_23877;
v_23873:
    v_23912 = stack[-2];
    goto v_23874;
v_23875:
    v_23911 = qvalue(elt(env, 4)); // listpri_depth!*
    goto v_23876;
v_23877:
    goto v_23873;
v_23874:
    goto v_23875;
v_23876:
    fn = elt(env, 8); // treesizep
    v_23911 = (*qfn2(fn))(fn, v_23912, v_23911);
    env = stack[-4];
    stack[-1] = v_23911;
v_23835:
    goto v_23885;
v_23881:
    v_23911 = stack[-2];
    v_23911 = qcar(v_23911);
    fn = elt(env, 9); // negnumberchk
    v_23912 = (*qfn1(fn))(fn, v_23911);
    env = stack[-4];
    goto v_23882;
v_23883:
    v_23911 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23884;
v_23885:
    goto v_23881;
v_23882:
    goto v_23883;
v_23884:
    fn = elt(env, 10); // maprint
    v_23911 = (*qfn2(fn))(fn, v_23912, v_23911);
    env = stack[-4];
    v_23911 = stack[-2];
    v_23911 = qcdr(v_23911);
    stack[-2] = v_23911;
    v_23911 = stack[-2];
    if (v_23911 == nil) goto v_23894;
    else goto v_23895;
v_23894:
    goto v_23836;
v_23895:
    v_23911 = elt(env, 5); // !*comma!*
    fn = elt(env, 11); // oprin
    v_23911 = (*qfn1(fn))(fn, v_23911);
    env = stack[-4];
    v_23911 = stack[-1];
    if (v_23911 == nil) goto v_23902;
    v_23911 = lisp_true;
    fn = elt(env, 12); // terpri!*
    v_23911 = (*qfn1(fn))(fn, v_23911);
    env = stack[-4];
    goto v_23900;
v_23902:
v_23900:
    goto v_23835;
v_23836:
    v_23911 = elt(env, 6); // !*rcbkt!*
    if (!symbolp(v_23911)) v_23911 = nil;
    else { v_23911 = qfastgets(v_23911);
           if (v_23911 != nil) { v_23911 = elt(v_23911, 37); // prtch
#ifdef RECORD_GET
             if (v_23911 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v_23911 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v_23911 == SPID_NOPROP) v_23911 = nil; }}
#endif
    fn = elt(env, 7); // prin2!*
    v_23911 = (*qfn1(fn))(fn, v_23911);
    env = stack[-4];
    v_23911 = stack[-3];
    qvalue(elt(env, 2)) = v_23911; // orig!*
    v_23911 = stack[0];
    return onevalue(v_23911);
}



// Code for gfdiffer

static LispObject CC_gfdiffer(LispObject env,
                         LispObject v_23828, LispObject v_23829)
{
    env = qenv(env);
    LispObject v_23855, v_23856, v_23857;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23856 = v_23829;
    v_23857 = v_23828;
// end of prologue
    v_23855 = v_23857;
    v_23855 = qcar(v_23855);
    if (!consp(v_23855)) goto v_23833;
    else goto v_23834;
v_23833:
    goto v_23842;
v_23838:
    v_23855 = v_23857;
    goto v_23839;
v_23840:
    goto v_23841;
v_23842:
    goto v_23838;
v_23839:
    goto v_23840;
v_23841:
    {
        fn = elt(env, 1); // gffdiff
        return (*qfn2(fn))(fn, v_23855, v_23856);
    }
v_23834:
    goto v_23852;
v_23848:
    v_23855 = v_23857;
    goto v_23849;
v_23850:
    goto v_23851;
v_23852:
    goto v_23848;
v_23849:
    goto v_23850;
v_23851:
    {
        fn = elt(env, 2); // gbfdiff
        return (*qfn2(fn))(fn, v_23855, v_23856);
    }
    v_23855 = nil;
    return onevalue(v_23855);
}



// Code for consrecip

static LispObject CC_consrecip(LispObject env,
                         LispObject v_23828)
{
    env = qenv(env);
    LispObject v_23870, v_23871, v_23872;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23872 = v_23828;
// end of prologue
    goto v_23842;
v_23838:
    v_23870 = v_23872;
    v_23871 = qcar(v_23870);
    goto v_23839;
v_23840:
    v_23870 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23841;
v_23842:
    goto v_23838;
v_23839:
    goto v_23840;
v_23841:
    if (v_23871 == v_23870) goto v_23836;
    else goto v_23837;
v_23836:
    v_23870 = lisp_true;
    goto v_23835;
v_23837:
    goto v_23853;
v_23849:
    v_23870 = v_23872;
    v_23871 = qcar(v_23870);
    goto v_23850;
v_23851:
    v_23870 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_23852;
v_23853:
    goto v_23849;
v_23850:
    goto v_23851;
v_23852:
    v_23870 = (v_23871 == v_23870 ? lisp_true : nil);
    goto v_23835;
    v_23870 = nil;
v_23835:
    if (v_23870 == nil) goto v_23833;
    v_23870 = v_23872;
    v_23870 = qcar(v_23870);
    goto v_23831;
v_23833:
    goto v_23867;
v_23863:
    v_23870 = elt(env, 1); // recip
    goto v_23864;
v_23865:
    v_23871 = v_23872;
    goto v_23866;
v_23867:
    goto v_23863;
v_23864:
    goto v_23865;
v_23866:
    return cons(v_23870, v_23871);
    v_23870 = nil;
v_23831:
    return onevalue(v_23870);
}



// Code for splitup

static LispObject CC_splitup(LispObject env,
                         LispObject v_23828, LispObject v_23829)
{
    env = qenv(env);
    LispObject v_23903, v_23904, v_23905;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23829,v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23828,v_23829);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_23905 = v_23829;
    stack[0] = v_23828;
// end of prologue
    v_23903 = stack[0];
    if (v_23903 == nil) goto v_23833;
    else goto v_23834;
v_23833:
    goto v_23841;
v_23837:
    v_23904 = nil;
    goto v_23838;
v_23839:
    v_23903 = nil;
    goto v_23840;
v_23841:
    goto v_23837;
v_23838:
    goto v_23839;
v_23840:
    return list2(v_23904, v_23903);
v_23834:
    v_23903 = stack[0];
    v_23903 = qcar(v_23903);
    v_23903 = qcar(v_23903);
    v_23903 = qcar(v_23903);
    v_23904 = v_23903;
    v_23903 = v_23904;
    if (v_23903 == nil) goto v_23853;
    else goto v_23854;
v_23853:
    v_23903 = lisp_true;
    goto v_23852;
v_23854:
    goto v_23863;
v_23859:
    goto v_23860;
v_23861:
    v_23903 = v_23905;
    goto v_23862;
v_23863:
    goto v_23859;
v_23860:
    goto v_23861;
v_23862:
    v_23903 = Lmemq(nil, v_23904, v_23903);
    goto v_23852;
    v_23903 = nil;
v_23852:
    if (v_23903 == nil) goto v_23845;
    goto v_23872;
v_23868:
    v_23904 = nil;
    goto v_23869;
v_23870:
    v_23903 = stack[0];
    goto v_23871;
v_23872:
    goto v_23868;
v_23869:
    goto v_23870;
v_23871:
    return list2(v_23904, v_23903);
v_23845:
    goto v_23882;
v_23878:
    v_23903 = stack[0];
    v_23903 = qcdr(v_23903);
    goto v_23879;
v_23880:
    v_23904 = v_23905;
    goto v_23881;
v_23882:
    goto v_23878;
v_23879:
    goto v_23880;
v_23881:
    v_23903 = CC_splitup(elt(env, 0), v_23903, v_23904);
    env = stack[-2];
    v_23904 = v_23903;
    goto v_23894;
v_23888:
    v_23903 = stack[0];
    stack[-1] = qcar(v_23903);
    goto v_23889;
v_23890:
    v_23903 = v_23904;
    stack[0] = qcar(v_23903);
    goto v_23891;
v_23892:
    v_23903 = v_23904;
    v_23903 = qcdr(v_23903);
    v_23903 = qcar(v_23903);
    v_23903 = ncons(v_23903);
    goto v_23893;
v_23894:
    goto v_23888;
v_23889:
    goto v_23890;
v_23891:
    goto v_23892;
v_23893:
    {
        LispObject v_23908 = stack[-1];
        LispObject v_23909 = stack[0];
        return acons(v_23908, v_23909, v_23903);
    }
    v_23903 = nil;
    return onevalue(v_23903);
}



// Code for simpdfp

static LispObject CC_simpdfp(LispObject env,
                         LispObject v_23828)
{
    env = qenv(env);
    LispObject v_24175, v_24176, v_24177, v_24178, v_24179;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23828);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[0] = v_23828;
// end of prologue
    goto v_23848;
v_23844:
    v_24175 = stack[0];
    v_24176 = Llength(nil, v_24175);
    env = stack[-6];
    goto v_23845;
v_23846:
    v_24175 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_23847;
v_23848:
    goto v_23844;
v_23845:
    goto v_23846;
v_23847:
    v_24175 = (LispObject)lessp2(v_24176, v_24175);
    v_24175 = v_24175 ? lisp_true : nil;
    env = stack[-6];
    if (v_24175 == nil) goto v_23842;
    goto v_23838;
v_23842:
    v_24175 = stack[0];
    v_24175 = qcar(v_24175);
    fn = elt(env, 10); // reval
    v_24175 = (*qfn1(fn))(fn, v_24175);
    env = stack[-6];
    stack[-5] = v_24175;
    v_24175 = stack[-5];
    v_24175 = Lconsp(nil, v_24175);
    env = stack[-6];
    if (v_24175 == nil) goto v_23857;
    else goto v_23858;
v_23857:
    goto v_23869;
v_23865:
    v_24175 = stack[0];
    v_24175 = qcdr(v_24175);
    v_24176 = qcar(v_24175);
    goto v_23866;
v_23867:
    v_24175 = qvalue(elt(env, 1)); // frlis!*
    goto v_23868;
v_23869:
    goto v_23865;
v_23866:
    goto v_23867;
v_23868:
    v_24175 = Lmember(nil, v_24176, v_24175);
    if (v_24175 == nil) goto v_23864;
    goto v_23880;
v_23876:
    goto v_23886;
v_23882:
    v_24176 = elt(env, 2); // dfp
    goto v_23883;
v_23884:
    v_24175 = stack[0];
    goto v_23885;
v_23886:
    goto v_23882;
v_23883:
    goto v_23884;
v_23885:
    v_24176 = cons(v_24176, v_24175);
    env = stack[-6];
    goto v_23877;
v_23878:
    v_24175 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23879;
v_23880:
    goto v_23876;
v_23877:
    goto v_23878;
v_23879:
    {
        fn = elt(env, 11); // mksq
        return (*qfn2(fn))(fn, v_24176, v_24175);
    }
v_23864:
    goto v_23898;
v_23894:
    v_24176 = stack[-5];
    goto v_23895;
v_23896:
    v_24175 = stack[0];
    v_24175 = qcdr(v_24175);
    v_24175 = qcar(v_24175);
    v_24175 = qcdr(v_24175);
    goto v_23897;
v_23898:
    goto v_23894;
v_23895:
    goto v_23896;
v_23897:
    v_24175 = cons(v_24176, v_24175);
    env = stack[-6];
    {
        fn = elt(env, 12); // simpdf
        return (*qfn1(fn))(fn, v_24175);
    }
    v_24175 = nil;
    goto v_23837;
v_23858:
    v_24175 = stack[-5];
    v_24175 = qcar(v_24175);
    stack[-1] = v_24175;
    v_24175 = stack[0];
    v_24175 = qcdr(v_24175);
    v_24175 = qcar(v_24175);
    fn = elt(env, 10); // reval
    v_24175 = (*qfn1(fn))(fn, v_24175);
    env = stack[-6];
    v_24179 = v_24175;
    goto v_23924;
v_23920:
    v_24176 = v_24179;
    goto v_23921;
v_23922:
    v_24175 = qvalue(elt(env, 1)); // frlis!*
    goto v_23923;
v_23924:
    goto v_23920;
v_23921:
    goto v_23922;
v_23923:
    v_24175 = Lmember(nil, v_24176, v_24175);
    if (v_24175 == nil) goto v_23918;
    else goto v_23919;
v_23918:
    goto v_23933;
v_23929:
    v_24176 = v_24179;
    goto v_23930;
v_23931:
    v_24175 = elt(env, 3); // list
    goto v_23932;
v_23933:
    goto v_23929;
v_23930:
    goto v_23931;
v_23932:
    v_24175 = Leqcar(nil, v_24176, v_24175);
    env = stack[-6];
    v_24175 = (v_24175 == nil ? lisp_true : nil);
    goto v_23917;
v_23919:
    v_24175 = nil;
    goto v_23917;
    v_24175 = nil;
v_23917:
    if (v_24175 == nil) goto v_23915;
    goto v_23945;
v_23941:
    stack[-4] = v_24179;
    goto v_23942;
v_23943:
    v_24175 = stack[0];
    v_24175 = qcdr(v_24175);
    v_24175 = qcdr(v_24175);
    stack[-3] = v_24175;
    v_24175 = stack[-3];
    if (v_24175 == nil) goto v_23958;
    else goto v_23959;
v_23958:
    v_24175 = nil;
    goto v_23951;
v_23959:
    v_24175 = stack[-3];
    v_24175 = qcar(v_24175);
    fn = elt(env, 10); // reval
    v_24175 = (*qfn1(fn))(fn, v_24175);
    env = stack[-6];
    v_24175 = ncons(v_24175);
    env = stack[-6];
    stack[-1] = v_24175;
    stack[-2] = v_24175;
v_23952:
    v_24175 = stack[-3];
    v_24175 = qcdr(v_24175);
    stack[-3] = v_24175;
    v_24175 = stack[-3];
    if (v_24175 == nil) goto v_23972;
    else goto v_23973;
v_23972:
    v_24175 = stack[-2];
    goto v_23951;
v_23973:
    goto v_23981;
v_23977:
    stack[0] = stack[-1];
    goto v_23978;
v_23979:
    v_24175 = stack[-3];
    v_24175 = qcar(v_24175);
    fn = elt(env, 10); // reval
    v_24175 = (*qfn1(fn))(fn, v_24175);
    env = stack[-6];
    v_24175 = ncons(v_24175);
    env = stack[-6];
    goto v_23980;
v_23981:
    goto v_23977;
v_23978:
    goto v_23979;
v_23980:
    v_24175 = Lrplacd(nil, stack[0], v_24175);
    env = stack[-6];
    v_24175 = stack[-1];
    v_24175 = qcdr(v_24175);
    stack[-1] = v_24175;
    goto v_23952;
v_23951:
    goto v_23944;
v_23945:
    goto v_23941;
v_23942:
    goto v_23943;
v_23944:
    v_24175 = cons(stack[-4], v_24175);
    env = stack[-6];
    v_24179 = v_24175;
    goto v_23996;
v_23992:
    stack[0] = elt(env, 3); // list
    goto v_23993;
v_23994:
    goto v_24003;
v_23999:
    v_24176 = v_24179;
    goto v_24000;
v_24001:
    v_24175 = nil;
    goto v_24002;
v_24003:
    goto v_23999;
v_24000:
    goto v_24001;
v_24002:
    fn = elt(env, 13); // dfp!-normalize
    v_24175 = (*qfn2(fn))(fn, v_24176, v_24175);
    env = stack[-6];
    goto v_23995;
v_23996:
    goto v_23992;
v_23993:
    goto v_23994;
v_23995:
    v_24175 = cons(stack[0], v_24175);
    env = stack[-6];
    v_24179 = v_24175;
    goto v_24014;
v_24008:
    v_24176 = elt(env, 2); // dfp
    goto v_24009;
v_24010:
    v_24175 = stack[-5];
    goto v_24011;
v_24012:
    v_24177 = v_24179;
    goto v_24013;
v_24014:
    goto v_24008;
v_24009:
    goto v_24010;
v_24011:
    goto v_24012;
v_24013:
    v_24175 = list3(v_24176, v_24175, v_24177);
    env = stack[-6];
    {
        fn = elt(env, 14); // simp
        return (*qfn1(fn))(fn, v_24175);
    }
v_23915:
    goto v_24024;
v_24020:
    v_24176 = stack[-1];
    goto v_24021;
v_24022:
    v_24175 = elt(env, 4); // generic_function
    goto v_24023;
v_24024:
    goto v_24020;
v_24021:
    goto v_24022;
v_24023:
    v_24175 = get(v_24176, v_24175);
    env = stack[-6];
    v_24178 = v_24175;
    v_24175 = lisp_true;
    v_24176 = v_24178;
    if (v_24176 == nil) goto v_24031;
    goto v_24040;
v_24036:
    v_24177 = v_24179;
    goto v_24037;
v_24038:
    v_24176 = elt(env, 3); // list
    goto v_24039;
v_24040:
    goto v_24036;
v_24037:
    goto v_24038;
v_24039:
    if (!consp(v_24177)) goto v_24031;
    v_24177 = qcar(v_24177);
    if (v_24177 == v_24176) goto v_24034;
    else goto v_24031;
v_24034:
    v_24176 = v_24179;
    v_24176 = qcdr(v_24176);
    v_24177 = v_24176;
v_24046:
    v_24176 = v_24177;
    if (v_24176 == nil) goto v_24051;
    else goto v_24052;
v_24051:
    goto v_24045;
v_24052:
    v_24176 = v_24177;
    v_24176 = qcar(v_24176);
    if (v_24175 == nil) goto v_24060;
    else goto v_24061;
v_24060:
    v_24175 = nil;
    goto v_24059;
v_24061:
    goto v_24070;
v_24066:
    goto v_24067;
v_24068:
    v_24175 = v_24178;
    goto v_24069;
v_24070:
    goto v_24066;
v_24067:
    goto v_24068;
v_24069:
    v_24175 = Lmember(nil, v_24176, v_24175);
    goto v_24059;
    v_24175 = nil;
v_24059:
    v_24176 = v_24177;
    v_24176 = qcdr(v_24176);
    v_24177 = v_24176;
    goto v_24046;
v_24045:
    goto v_24029;
v_24031:
v_24029:
    if (v_24175 == nil) goto v_24078;
    else goto v_24079;
v_24078:
    goto v_24086;
v_24082:
    v_24176 = nil;
    goto v_24083;
v_24084:
    v_24175 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24085;
v_24086:
    goto v_24082;
v_24083:
    goto v_24084;
v_24085:
    return cons(v_24176, v_24175);
v_24079:
    goto v_24097;
v_24093:
    v_24176 = v_24179;
    goto v_24094;
v_24095:
    v_24175 = elt(env, 5); // (list)
    goto v_24096;
v_24097:
    goto v_24093;
v_24094:
    goto v_24095;
v_24096:
    if (equal(v_24176, v_24175)) goto v_24091;
    else goto v_24092;
v_24091:
    goto v_24105;
v_24101:
    v_24176 = stack[-5];
    goto v_24102;
v_24103:
    v_24175 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24104;
v_24105:
    goto v_24101;
v_24102:
    goto v_24103;
v_24104:
    {
        fn = elt(env, 11); // mksq
        return (*qfn2(fn))(fn, v_24176, v_24175);
    }
v_24092:
    v_24175 = v_24178;
    if (v_24175 == nil) goto v_24111;
    goto v_24120;
v_24116:
    v_24176 = stack[-1];
    goto v_24117;
v_24118:
    v_24175 = elt(env, 6); // dfp_commute
    goto v_24119;
v_24120:
    goto v_24116;
v_24117:
    goto v_24118;
v_24119:
    v_24175 = Lflagp(nil, v_24176, v_24175);
    env = stack[-6];
    if (v_24175 == nil) goto v_24111;
    v_24175 = v_24178;
// Binding kord!*
// FLUIDBIND: reloadenv=6 litvec-offset=7 saveloc=1
{   bind_fluid_stack bind_fluid_var(-6, 7, -1);
    qvalue(elt(env, 7)) = v_24175; // kord!*
    goto v_24130;
v_24126:
    stack[0] = elt(env, 3); // list
    goto v_24127;
v_24128:
    goto v_24137;
v_24133:
    v_24175 = v_24179;
    v_24176 = qcdr(v_24175);
    goto v_24134;
v_24135:
    v_24175 = elt(env, 8); // ordp
    goto v_24136;
v_24137:
    goto v_24133;
v_24134:
    goto v_24135;
v_24136:
    fn = elt(env, 15); // sort
    v_24175 = (*qfn2(fn))(fn, v_24176, v_24175);
    env = stack[-6];
    goto v_24129;
v_24130:
    goto v_24126;
v_24127:
    goto v_24128;
v_24129:
    v_24175 = cons(stack[0], v_24175);
    env = stack[-6];
    v_24179 = v_24175;
    ;}  // end of a binding scope
    goto v_24109;
v_24111:
v_24109:
    goto v_24148;
v_24142:
    v_24176 = elt(env, 2); // dfp
    goto v_24143;
v_24144:
    v_24175 = stack[-5];
    goto v_24145;
v_24146:
    v_24177 = v_24179;
    goto v_24147;
v_24148:
    goto v_24142;
v_24143:
    goto v_24144;
v_24145:
    goto v_24146;
v_24147:
    v_24175 = list3(v_24176, v_24175, v_24177);
    env = stack[-6];
    stack[0] = v_24175;
    goto v_24157;
v_24153:
    v_24176 = stack[0];
    goto v_24154;
v_24155:
    v_24175 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24156;
v_24157:
    goto v_24153;
v_24154:
    goto v_24155;
v_24156:
    {
        fn = elt(env, 11); // mksq
        return (*qfn2(fn))(fn, v_24176, v_24175);
    }
v_23838:
    goto v_24165;
v_24161:
    goto v_24171;
v_24167:
    v_24176 = elt(env, 2); // dfp
    goto v_24168;
v_24169:
    v_24175 = stack[0];
    goto v_24170;
v_24171:
    goto v_24167;
v_24168:
    goto v_24169;
v_24170:
    v_24176 = cons(v_24176, v_24175);
    env = stack[-6];
    goto v_24162;
v_24163:
    v_24175 = elt(env, 9); // "generic differential"
    goto v_24164;
v_24165:
    goto v_24161;
v_24162:
    goto v_24163;
v_24164:
    fn = elt(env, 16); // typerr
    v_24175 = (*qfn2(fn))(fn, v_24176, v_24175);
    v_24175 = nil;
v_23837:
    return onevalue(v_24175);
}



// Code for groeb!=testc1

static LispObject CC_groebMtestc1(LispObject env,
                         LispObject v_23828)
{
    env = qenv(env);
    LispObject v_23870, v_23871;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23828);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_23828;
// end of prologue
    goto v_23835;
v_23831:
    goto v_23841;
v_23837:
    goto v_23849;
v_23845:
    v_23871 = stack[0];
    goto v_23846;
v_23847:
    v_23870 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_23848;
v_23849:
    goto v_23845;
v_23846:
    goto v_23847;
v_23848:
    fn = elt(env, 1); // nth
    v_23870 = (*qfn2(fn))(fn, v_23871, v_23870);
    env = stack[-2];
    fn = elt(env, 2); // bas_dpoly
    v_23870 = (*qfn1(fn))(fn, v_23870);
    env = stack[-2];
    fn = elt(env, 3); // dp_lmon
    stack[-1] = (*qfn1(fn))(fn, v_23870);
    env = stack[-2];
    goto v_23838;
v_23839:
    goto v_23859;
v_23855:
    v_23871 = stack[0];
    goto v_23856;
v_23857:
    v_23870 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_23858;
v_23859:
    goto v_23855;
v_23856:
    goto v_23857;
v_23858:
    fn = elt(env, 1); // nth
    v_23870 = (*qfn2(fn))(fn, v_23871, v_23870);
    env = stack[-2];
    fn = elt(env, 2); // bas_dpoly
    v_23870 = (*qfn1(fn))(fn, v_23870);
    env = stack[-2];
    fn = elt(env, 3); // dp_lmon
    v_23870 = (*qfn1(fn))(fn, v_23870);
    env = stack[-2];
    goto v_23840;
v_23841:
    goto v_23837;
v_23838:
    goto v_23839;
v_23840:
    fn = elt(env, 4); // mo_sum
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_23870);
    env = stack[-2];
    goto v_23832;
v_23833:
    goto v_23867;
v_23863:
    v_23871 = stack[0];
    goto v_23864;
v_23865:
    v_23870 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_23866;
v_23867:
    goto v_23863;
v_23864:
    goto v_23865;
v_23866:
    fn = elt(env, 1); // nth
    v_23870 = (*qfn2(fn))(fn, v_23871, v_23870);
    env = stack[-2];
    goto v_23834;
v_23835:
    goto v_23831;
v_23832:
    goto v_23833;
v_23834:
    {
        LispObject v_23874 = stack[-1];
        fn = elt(env, 5); // mo_equal!?
        return (*qfn2(fn))(fn, v_23874, v_23870);
    }
}



// Code for list2vect!*

static LispObject CC_list2vectH(LispObject env,
                         LispObject v_23828, LispObject v_23829)
{
    env = qenv(env);
    LispObject v_23902, v_23903;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23829,v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23828,v_23829);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_23829;
    stack[-4] = v_23828;
// end of prologue
    v_23902 = stack[-4];
    v_23902 = Llength(nil, v_23902);
    env = stack[-6];
    v_23902 = sub1(v_23902);
    env = stack[-6];
    v_23902 = Lmkvect(nil, v_23902);
    env = stack[-6];
    stack[-5] = v_23902;
    v_23902 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_23902;
v_23841:
    goto v_23853;
v_23849:
    v_23902 = stack[-5];
    v_23902 = Lupbv(nil, v_23902);
    env = stack[-6];
    v_23903 = add1(v_23902);
    env = stack[-6];
    goto v_23850;
v_23851:
    v_23902 = stack[-2];
    goto v_23852;
v_23853:
    goto v_23849;
v_23850:
    goto v_23851;
v_23852:
    v_23902 = difference2(v_23903, v_23902);
    env = stack[-6];
    v_23902 = Lminusp(nil, v_23902);
    env = stack[-6];
    if (v_23902 == nil) goto v_23846;
    goto v_23840;
v_23846:
    goto v_23865;
v_23859:
    stack[-1] = stack[-5];
    goto v_23860;
v_23861:
    v_23902 = stack[-2];
    stack[0] = sub1(v_23902);
    env = stack[-6];
    goto v_23862;
v_23863:
    goto v_23877;
v_23873:
    v_23903 = stack[-3];
    goto v_23874;
v_23875:
    v_23902 = elt(env, 1); // algebraic
    goto v_23876;
v_23877:
    goto v_23873;
v_23874:
    goto v_23875;
v_23876:
    if (v_23903 == v_23902) goto v_23871;
    else goto v_23872;
v_23871:
    goto v_23886;
v_23882:
    v_23903 = stack[-4];
    goto v_23883;
v_23884:
    v_23902 = stack[-2];
    goto v_23885;
v_23886:
    goto v_23882;
v_23883:
    goto v_23884;
v_23885:
    fn = elt(env, 2); // nth
    v_23902 = (*qfn2(fn))(fn, v_23903, v_23902);
    env = stack[-6];
    fn = elt(env, 3); // symb_to_alg
    v_23902 = (*qfn1(fn))(fn, v_23902);
    env = stack[-6];
    goto v_23870;
v_23872:
    goto v_23896;
v_23892:
    v_23903 = stack[-4];
    goto v_23893;
v_23894:
    v_23902 = stack[-2];
    goto v_23895;
v_23896:
    goto v_23892;
v_23893:
    goto v_23894;
v_23895:
    fn = elt(env, 2); // nth
    v_23902 = (*qfn2(fn))(fn, v_23903, v_23902);
    env = stack[-6];
    goto v_23870;
    v_23902 = nil;
v_23870:
    goto v_23864;
v_23865:
    goto v_23859;
v_23860:
    goto v_23861;
v_23862:
    goto v_23863;
v_23864:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_23902;
    v_23902 = stack[-2];
    v_23902 = add1(v_23902);
    env = stack[-6];
    stack[-2] = v_23902;
    goto v_23841;
v_23840:
    v_23902 = stack[-5];
    return onevalue(v_23902);
}



// Code for xquotient!-mod!-p

static LispObject CC_xquotientKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24032, v_24033, v_24034;
    LispObject fn;
    LispObject v_23830, v_23829, v_23828;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xquotient-mod-p");
    va_start(aa, nargs);
    v_23828 = va_arg(aa, LispObject);
    v_23829 = va_arg(aa, LispObject);
    v_23830 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_23830,v_23829,v_23828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_23828,v_23829,v_23830);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_23830;
    stack[-1] = v_23829;
    stack[-2] = v_23828;
// end of prologue
    v_24032 = stack[-2];
    if (v_24032 == nil) goto v_23834;
    else goto v_23835;
v_23834:
    v_24032 = nil;
    goto v_23833;
v_23835:
    v_24032 = stack[-2];
    if (!consp(v_24032)) goto v_23846;
    else goto v_23847;
v_23846:
    v_24032 = lisp_true;
    goto v_23845;
v_23847:
    v_24032 = stack[-2];
    v_24032 = qcar(v_24032);
    v_24032 = (consp(v_24032) ? nil : lisp_true);
    goto v_23845;
    v_24032 = nil;
v_23845:
    if (v_24032 == nil) goto v_23843;
    v_24032 = lisp_true;
    goto v_23841;
v_23843:
    goto v_23866;
v_23862:
    v_24032 = stack[-2];
    v_24032 = qcar(v_24032);
    v_24032 = qcar(v_24032);
    v_24033 = qcar(v_24032);
    goto v_23863;
v_23864:
    v_24032 = stack[0];
    goto v_23865;
v_23866:
    goto v_23862;
v_23863:
    goto v_23864;
v_23865:
    if (equal(v_24033, v_24032)) goto v_23861;
    v_24032 = lisp_true;
    goto v_23859;
v_23861:
    goto v_23879;
v_23875:
    v_24032 = stack[-2];
    v_24032 = qcar(v_24032);
    v_24032 = qcar(v_24032);
    v_24033 = qcdr(v_24032);
    goto v_23876;
v_23877:
    v_24032 = stack[-1];
    v_24032 = qcar(v_24032);
    v_24032 = qcar(v_24032);
    v_24032 = qcdr(v_24032);
    goto v_23878;
v_23879:
    goto v_23875;
v_23876:
    goto v_23877;
v_23878:
    v_24032 = ((intptr_t)v_24033 < (intptr_t)v_24032) ? lisp_true : nil;
    goto v_23859;
    v_24032 = nil;
v_23859:
    goto v_23841;
    v_24032 = nil;
v_23841:
    if (v_24032 == nil) goto v_23839;
    v_24032 = nil;
    qvalue(elt(env, 1)) = v_24032; // exact!-quotient!-flag
    goto v_23833;
v_23839:
    goto v_23896;
v_23892:
    v_24032 = stack[-2];
    v_24032 = qcar(v_24032);
    v_24032 = qcar(v_24032);
    v_24033 = qcdr(v_24032);
    goto v_23893;
v_23894:
    v_24032 = stack[-1];
    v_24032 = qcar(v_24032);
    v_24032 = qcar(v_24032);
    v_24032 = qcdr(v_24032);
    goto v_23895;
v_23896:
    goto v_23892;
v_23893:
    goto v_23894;
v_23895:
    if (equal(v_24033, v_24032)) goto v_23890;
    else goto v_23891;
v_23890:
    goto v_23913;
v_23909:
    v_24032 = stack[-2];
    v_24032 = qcar(v_24032);
    v_24033 = qcdr(v_24032);
    goto v_23910;
v_23911:
    v_24032 = stack[-1];
    v_24032 = qcar(v_24032);
    v_24032 = qcdr(v_24032);
    goto v_23912;
v_23913:
    goto v_23909;
v_23910:
    goto v_23911;
v_23912:
    fn = elt(env, 2); // quotient!-mod!-p
    v_24032 = (*qfn2(fn))(fn, v_24033, v_24032);
    env = stack[-4];
    stack[0] = v_24032;
    v_24032 = stack[0];
    if (v_24032 == nil) goto v_23926;
    else goto v_23927;
v_23926:
    v_24032 = lisp_true;
    goto v_23925;
v_23927:
    goto v_23937;
v_23933:
    goto v_23934;
v_23935:
    goto v_23944;
v_23940:
    v_24033 = stack[0];
    goto v_23941;
v_23942:
    v_24032 = stack[-1];
    goto v_23943;
v_23944:
    goto v_23940;
v_23941:
    goto v_23942;
v_23943:
    fn = elt(env, 3); // times!-mod!-p
    v_24032 = (*qfn2(fn))(fn, v_24033, v_24032);
    env = stack[-4];
    goto v_23936;
v_23937:
    goto v_23933;
v_23934:
    goto v_23935;
v_23936:
    fn = elt(env, 4); // difference!-mod!-p
    v_24032 = (*qfn2(fn))(fn, stack[-2], v_24032);
    env = stack[-4];
    goto v_23925;
    v_24032 = nil;
v_23925:
    if (v_24032 == nil) goto v_23923;
    v_24032 = nil;
    qvalue(elt(env, 1)) = v_24032; // exact!-quotient!-flag
    goto v_23921;
v_23923:
v_23921:
    v_24032 = stack[0];
    goto v_23833;
v_23891:
    goto v_23959;
v_23955:
    goto v_23965;
v_23961:
    v_24032 = stack[-2];
    v_24032 = qcar(v_24032);
    v_24032 = qcar(v_24032);
    v_24034 = qcar(v_24032);
    goto v_23962;
v_23963:
    goto v_23974;
v_23970:
    v_24032 = stack[-2];
    v_24032 = qcar(v_24032);
    v_24032 = qcar(v_24032);
    v_24033 = qcdr(v_24032);
    goto v_23971;
v_23972:
    v_24032 = stack[-1];
    v_24032 = qcar(v_24032);
    v_24032 = qcar(v_24032);
    v_24032 = qcdr(v_24032);
    goto v_23973;
v_23974:
    goto v_23970;
v_23971:
    goto v_23972;
v_23973:
    v_24032 = (LispObject)(intptr_t)((intptr_t)v_24033 - (intptr_t)v_24032 + TAG_FIXNUM);
    goto v_23964;
v_23965:
    goto v_23961;
v_23962:
    goto v_23963;
v_23964:
    fn = elt(env, 5); // mksp
    stack[-3] = (*qfn2(fn))(fn, v_24034, v_24032);
    env = stack[-4];
    goto v_23956;
v_23957:
    goto v_23989;
v_23985:
    v_24032 = stack[-2];
    v_24032 = qcar(v_24032);
    v_24033 = qcdr(v_24032);
    goto v_23986;
v_23987:
    v_24032 = stack[-1];
    v_24032 = qcar(v_24032);
    v_24032 = qcdr(v_24032);
    goto v_23988;
v_23989:
    goto v_23985;
v_23986:
    goto v_23987;
v_23988:
    fn = elt(env, 2); // quotient!-mod!-p
    v_24032 = (*qfn2(fn))(fn, v_24033, v_24032);
    env = stack[-4];
    goto v_23958;
v_23959:
    goto v_23955;
v_23956:
    goto v_23957;
v_23958:
    v_24032 = cons(stack[-3], v_24032);
    env = stack[-4];
    stack[-3] = v_24032;
    goto v_24001;
v_23997:
    v_24032 = stack[-2];
    stack[-2] = qcdr(v_24032);
    goto v_23998;
v_23999:
    goto v_24009;
v_24005:
    v_24032 = stack[-3];
    fn = elt(env, 6); // negate!-term
    v_24033 = (*qfn1(fn))(fn, v_24032);
    env = stack[-4];
    goto v_24006;
v_24007:
    v_24032 = stack[-1];
    v_24032 = qcdr(v_24032);
    goto v_24008;
v_24009:
    goto v_24005;
v_24006:
    goto v_24007;
v_24008:
    fn = elt(env, 7); // times!-term!-mod!-p
    v_24032 = (*qfn2(fn))(fn, v_24033, v_24032);
    env = stack[-4];
    goto v_24000;
v_24001:
    goto v_23997;
v_23998:
    goto v_23999;
v_24000:
    fn = elt(env, 8); // plus!-mod!-p
    v_24032 = (*qfn2(fn))(fn, stack[-2], v_24032);
    env = stack[-4];
    stack[-2] = v_24032;
    goto v_24019;
v_24015:
    goto v_24016;
v_24017:
    goto v_24028;
v_24022:
    v_24034 = stack[-2];
    goto v_24023;
v_24024:
    v_24033 = stack[-1];
    goto v_24025;
v_24026:
    v_24032 = stack[0];
    goto v_24027;
v_24028:
    goto v_24022;
v_24023:
    goto v_24024;
v_24025:
    goto v_24026;
v_24027:
    v_24032 = CC_xquotientKmodKp(elt(env, 0), 3, v_24034, v_24033, v_24032);
    goto v_24018;
v_24019:
    goto v_24015;
v_24016:
    goto v_24017;
v_24018:
    {
        LispObject v_24039 = stack[-3];
        return cons(v_24039, v_24032);
    }
    goto v_23833;
    v_24032 = nil;
v_23833:
    return onevalue(v_24032);
}



// Code for xnp

static LispObject CC_xnp(LispObject env,
                         LispObject v_23828, LispObject v_23829)
{
    env = qenv(env);
    LispObject v_23860, v_23861, v_23862, v_23863;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23861 = v_23829;
    v_23862 = v_23828;
// end of prologue
v_23827:
    v_23860 = v_23862;
    if (v_23860 == nil) goto v_23833;
    else goto v_23834;
v_23833:
    v_23860 = nil;
    goto v_23832;
v_23834:
    goto v_23846;
v_23842:
    v_23860 = v_23862;
    v_23863 = qcar(v_23860);
    goto v_23843;
v_23844:
    v_23860 = v_23861;
    goto v_23845;
v_23846:
    goto v_23842;
v_23843:
    goto v_23844;
v_23845:
    v_23860 = Lmemq(nil, v_23863, v_23860);
    if (v_23860 == nil) goto v_23841;
    else goto v_23840;
v_23841:
    goto v_23856;
v_23852:
    v_23860 = v_23862;
    v_23862 = qcdr(v_23860);
    goto v_23853;
v_23854:
    v_23860 = v_23861;
    goto v_23855;
v_23856:
    goto v_23852;
v_23853:
    goto v_23854;
v_23855:
    v_23861 = v_23860;
    goto v_23827;
v_23840:
    goto v_23832;
    v_23860 = nil;
v_23832:
    return onevalue(v_23860);
}



setup_type const u42_setup[] =
{
    {"mk_binding",              TOO_FEW_2,      CC_mk_binding, WRONG_NO_2},
    {"ratnump",                 CC_ratnump,     TOO_MANY_1,    WRONG_NO_1},
    {"miller-rabin",            TOO_FEW_2,      CC_millerKrabin,WRONG_NO_2},
    {"equiv-coeffs",            TOO_FEW_2,      CC_equivKcoeffs,WRONG_NO_2},
    {"*g2lex",                  CC_Hg2lex,      TOO_MANY_1,    WRONG_NO_1},
    {"simpquot",                CC_simpquot,    TOO_MANY_1,    WRONG_NO_1},
    {"isimp1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_isimp1},
    {"drop_dec_with",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_drop_dec_with},
    {"rl_qe",                   TOO_FEW_2,      CC_rl_qe,      WRONG_NO_2},
    {"cl_nnf1",                 TOO_FEW_2,      CC_cl_nnf1,    WRONG_NO_2},
    {"repr_ldeg",               CC_repr_ldeg,   TOO_MANY_1,    WRONG_NO_1},
    {"transposerd",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_transposerd},
    {"spcol_dim",               CC_spcol_dim,   TOO_MANY_1,    WRONG_NO_1},
    {"on-double1",              CC_onKdouble1,  TOO_MANY_1,    WRONG_NO_1},
    {"size_of_matrix",          CC_size_of_matrix,TOO_MANY_1,  WRONG_NO_1},
    {"get:const",               TOO_FEW_2,      CC_getTconst,  WRONG_NO_2},
    {"r2speclist1",             CC_r2speclist1, TOO_MANY_1,    WRONG_NO_1},
    {"list-evaluate",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_listKevaluate},
    {"mkassign",                TOO_FEW_2,      CC_mkassign,   WRONG_NO_2},
    {"revalpart",               CC_revalpart,   TOO_MANY_1,    WRONG_NO_1},
    {"set-weights",             CC_setKweights, TOO_MANY_1,    WRONG_NO_1},
    {"simp-prop-dist",          CC_simpKpropKdist,TOO_MANY_1,  WRONG_NO_1},
    {"lambda_iff2c8okfzyq1",    TOO_FEW_2,      CC_lambda_iff2c8okfzyq1,WRONG_NO_2},
    {"lambda_iff2c8okfzyq1",    TOO_FEW_2,      CC1_lambda_iff2c8okfzyq1,WRONG_NO_2},
    {"lesspcar",                TOO_FEW_2,      CC_lesspcar,   WRONG_NO_2},
    {"algmodep",                CC_algmodep,    TOO_MANY_1,    WRONG_NO_1},
    {"talp_trygaussvar",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_trygaussvar},
    {"fctrf",                   CC_fctrf,       TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_anegrel",            CC_ofsf_anegrel,TOO_MANY_1,    WRONG_NO_1},
    {"diffrd",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_diffrd},
    {"findelem2",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_findelem2},
    {"inszzz",                  TOO_FEW_2,      CC_inszzz,     WRONG_NO_2},
    {"listpri",                 CC_listpri,     TOO_MANY_1,    WRONG_NO_1},
    {"gfdiffer",                TOO_FEW_2,      CC_gfdiffer,   WRONG_NO_2},
    {"consrecip",               CC_consrecip,   TOO_MANY_1,    WRONG_NO_1},
    {"splitup",                 TOO_FEW_2,      CC_splitup,    WRONG_NO_2},
    {"simpdfp",                 CC_simpdfp,     TOO_MANY_1,    WRONG_NO_1},
    {"groeb=testc1",            CC_groebMtestc1,TOO_MANY_1,    WRONG_NO_1},
    {"list2vect*",              TOO_FEW_2,      CC_list2vectH, WRONG_NO_2},
    {"xquotient-mod-p",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xquotientKmodKp},
    {"xnp",                     TOO_FEW_2,      CC_xnp,        WRONG_NO_2},
    {NULL, (one_args *)"u42", (two_args *)"48444 2762935 1692903", 0}
};

// end of generated code
