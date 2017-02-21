
// $destdir/u21.c        Machine generated C code

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



// Code for begin1a

static LispObject CC_begin1a(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_12313, v_12314, v_12315;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11950;
// end of prologue
    v_12313 = Ltime(nil, 0);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_12313; // otime!*
    v_12313 = elt(env, 2); // gctime
    fn = elt(env, 53); // getd
    v_12313 = (*qfn1(fn))(fn, v_12313);
    env = stack[-2];
    if (v_12313 == nil) goto v_11967;
    v_12313 = Lgctime(nil, 0);
    env = stack[-2];
    qvalue(elt(env, 3)) = v_12313; // ogctime!*
    goto v_11965;
v_11967:
    v_12313 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 3)) = v_12313; // ogctime!*
    goto v_11965;
v_11965:
    v_12313 = qvalue(elt(env, 1)); // otime!*
    qvalue(elt(env, 4)) = v_12313; // otime3!*
    qvalue(elt(env, 5)) = v_12313; // otime2!*
    qvalue(elt(env, 6)) = v_12313; // otime1!*
    v_12313 = qvalue(elt(env, 3)); // ogctime!*
    qvalue(elt(env, 7)) = v_12313; // ogctime3!*
    qvalue(elt(env, 8)) = v_12313; // ogctime2!*
    qvalue(elt(env, 9)) = v_12313; // ogctime1!*
    v_12313 = stack[0];
    qvalue(elt(env, 10)) = v_12313; // peekchar!*
    v_12313 = elt(env, 11); // !*semicol!*
    qvalue(elt(env, 12)) = v_12313; // cursym!*
    v_12313 = nil;
    qvalue(elt(env, 13)) = v_12313; // curescaped!*
v_11957:
    fn = elt(env, 54); // terminalp
    v_12313 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_12313 == nil) goto v_11982;
    v_12313 = qvalue(elt(env, 14)); // !*nosave!*
    if (v_12313 == nil) goto v_11988;
    else goto v_11986;
v_11988:
    goto v_11995;
v_11991:
    v_12314 = qvalue(elt(env, 15)); // statcounter
    goto v_11992;
v_11993:
    v_12313 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11994;
v_11995:
    goto v_11991;
v_11992:
    goto v_11993;
v_11994:
    if (v_12314 == v_12313) goto v_11986;
    goto v_11987;
v_11986:
    goto v_11985;
v_11987:
    fn = elt(env, 55); // add2buflis
    v_12313 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_11985;
v_11985:
    fn = elt(env, 56); // update_prompt
    v_12313 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_11980;
v_11982:
v_11980:
    v_12313 = nil;
    qvalue(elt(env, 14)) = v_12313; // !*nosave!*
    v_12313 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 16)) = v_12313; // !*strind
    v_12313 = nil;
    stack[-1] = v_12313;
    v_12313 = qvalue(elt(env, 17)); // !*time
    if (v_12313 == nil) goto v_12009;
    v_12313 = elt(env, 18); // (showtime nil)
    fn = elt(env, 57); // lispeval
    v_12313 = (*qfn1(fn))(fn, v_12313);
    env = stack[-2];
    goto v_12007;
v_12009:
v_12007:
    v_12313 = qvalue(elt(env, 19)); // !*output
    if (v_12313 == nil) goto v_12016;
    v_12313 = qvalue(elt(env, 20)); // ofl!*
    if (v_12313 == nil) goto v_12022;
    else goto v_12023;
v_12022:
    fn = elt(env, 54); // terminalp
    v_12313 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_12313 == nil) goto v_12027;
    else goto v_12028;
v_12027:
    v_12313 = nil;
    goto v_12026;
v_12028:
    v_12313 = qvalue(elt(env, 21)); // !*defn
    if (v_12313 == nil) goto v_12035;
    else goto v_12036;
v_12035:
    v_12313 = qvalue(elt(env, 22)); // !*lessspace
    v_12313 = (v_12313 == nil ? lisp_true : nil);
    goto v_12034;
v_12036:
    v_12313 = nil;
    goto v_12034;
    v_12313 = nil;
v_12034:
    goto v_12026;
    v_12313 = nil;
v_12026:
    goto v_12021;
v_12023:
    v_12313 = nil;
    goto v_12021;
    v_12313 = nil;
v_12021:
    if (v_12313 == nil) goto v_12016;
    v_12313 = Lterpri(nil, 0);
    env = stack[-2];
    goto v_12014;
v_12016:
v_12014:
    v_12313 = qvalue(elt(env, 23)); // tslin!*
    if (v_12313 == nil) goto v_12050;
    v_12313 = qvalue(elt(env, 23)); // tslin!*
    v_12313 = qcar(v_12313);
    qvalue(elt(env, 24)) = v_12313; // !*slin
    v_12313 = qvalue(elt(env, 23)); // tslin!*
    v_12313 = qcdr(v_12313);
    qvalue(elt(env, 25)) = v_12313; // lreadfn!*
    v_12313 = nil;
    qvalue(elt(env, 23)) = v_12313; // tslin!*
    goto v_12048;
v_12050:
v_12048:
    v_12313 = qvalue(elt(env, 26)); // initl!*
    stack[0] = v_12313;
v_11958:
    v_12313 = stack[0];
    if (v_12313 == nil) goto v_12061;
    v_12313 = stack[0];
    v_12313 = qcar(v_12313);
    fn = elt(env, 58); // sinitl
    v_12313 = (*qfn1(fn))(fn, v_12313);
    env = stack[-2];
    v_12313 = stack[0];
    v_12313 = qcdr(v_12313);
    stack[0] = v_12313;
    goto v_11958;
v_12061:
    goto v_12073;
v_12069:
    v_12314 = qvalue(elt(env, 27)); // forkeywords!*
    goto v_12070;
v_12071:
    v_12313 = elt(env, 28); // delim
    goto v_12072;
v_12073:
    goto v_12069;
v_12070:
    goto v_12071;
v_12072:
    v_12313 = Lremflag(nil, v_12314, v_12313);
    env = stack[-2];
    goto v_12081;
v_12077:
    v_12314 = qvalue(elt(env, 29)); // repeatkeywords!*
    goto v_12078;
v_12079:
    v_12313 = elt(env, 28); // delim
    goto v_12080;
v_12081:
    goto v_12077;
v_12078:
    goto v_12079;
v_12080:
    v_12313 = Lremflag(nil, v_12314, v_12313);
    env = stack[-2];
    goto v_12089;
v_12085:
    v_12314 = qvalue(elt(env, 30)); // whilekeywords!*
    goto v_12086;
v_12087:
    v_12313 = elt(env, 28); // delim
    goto v_12088;
v_12089:
    goto v_12085;
v_12086:
    goto v_12087;
v_12088:
    v_12313 = Lremflag(nil, v_12314, v_12313);
    env = stack[-2];
    v_12313 = qvalue(elt(env, 31)); // !*int
    if (v_12313 == nil) goto v_12095;
    v_12313 = nil;
    qvalue(elt(env, 32)) = v_12313; // erfg!*
    goto v_12093;
v_12095:
v_12093:
    goto v_12106;
v_12102:
    v_12314 = qvalue(elt(env, 12)); // cursym!*
    goto v_12103;
v_12104:
    v_12313 = elt(env, 33); // end
    goto v_12105;
v_12106:
    goto v_12102;
v_12103:
    goto v_12104;
v_12105:
    if (v_12314 == v_12313) goto v_12100;
    else goto v_12101;
v_12100:
    v_12313 = elt(env, 33); // end
    fn = elt(env, 59); // comm1
    v_12313 = (*qfn1(fn))(fn, v_12313);
    v_12313 = nil;
    goto v_11956;
v_12101:
    fn = elt(env, 54); // terminalp
    v_12313 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_12313 == nil) goto v_12113;
    goto v_12121;
v_12117:
    v_12314 = qvalue(elt(env, 34)); // key!*
    goto v_12118;
v_12119:
    v_12313 = elt(env, 35); // ed
    goto v_12120;
v_12121:
    goto v_12117;
v_12118:
    goto v_12119;
v_12120:
    if (v_12314 == v_12313) goto v_12113;
    v_12313 = qvalue(elt(env, 36)); // promptexp!*
    fn = elt(env, 60); // printprompt
    v_12313 = (*qfn1(fn))(fn, v_12313);
    env = stack[-2];
    goto v_12099;
v_12113:
v_12099:
    goto v_12131;
v_12127:
    v_12314 = elt(env, 37); // (command)
    goto v_12128;
v_12129:
    v_12313 = lisp_true;
    goto v_12130;
v_12131:
    goto v_12127;
v_12128:
    goto v_12129;
v_12130:
    fn = elt(env, 61); // errorset!*
    v_12313 = (*qfn2(fn))(fn, v_12314, v_12313);
    env = stack[-2];
    stack[0] = v_12313;
    fn = elt(env, 62); // condterpri
    v_12313 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_12313 = stack[0];
    fn = elt(env, 63); // errorp
    v_12313 = (*qfn1(fn))(fn, v_12313);
    env = stack[-2];
    if (v_12313 == nil) goto v_12138;
    goto v_11960;
v_12138:
    v_12313 = stack[0];
    v_12313 = qcar(v_12313);
    stack[0] = v_12313;
    goto v_12155;
v_12151:
    v_12313 = stack[0];
    v_12314 = qcar(v_12313);
    goto v_12152;
v_12153:
    v_12313 = elt(env, 38); // symbolic
    goto v_12154;
v_12155:
    goto v_12151;
v_12152:
    goto v_12153;
v_12154:
    if (v_12314 == v_12313) goto v_12149;
    else goto v_12150;
v_12149:
    goto v_12164;
v_12160:
    v_12313 = stack[0];
    v_12313 = qcdr(v_12313);
    v_12314 = qcar(v_12313);
    goto v_12161;
v_12162:
    v_12313 = elt(env, 39); // xmodule
    goto v_12163;
v_12164:
    goto v_12160;
v_12161:
    goto v_12162;
v_12163:
    v_12313 = Leqcar(nil, v_12314, v_12313);
    env = stack[-2];
    goto v_12148;
v_12150:
    v_12313 = nil;
    goto v_12148;
    v_12313 = nil;
v_12148:
    if (v_12313 == nil) goto v_12146;
    v_12313 = stack[0];
    v_12313 = qcdr(v_12313);
    v_12313 = qcar(v_12313);
    fn = elt(env, 64); // eval
    v_12313 = (*qfn1(fn))(fn, v_12313);
    env = stack[-2];
    fn = elt(env, 65); // xmodloop
    v_12313 = (*qfn1(fn))(fn, v_12313);
    env = stack[-2];
    v_12315 = v_12313;
    goto v_12144;
v_12146:
    v_12313 = stack[0];
    fn = elt(env, 66); // begin11
    v_12313 = (*qfn1(fn))(fn, v_12313);
    env = stack[-2];
    v_12315 = v_12313;
    goto v_12144;
v_12144:
    v_12313 = v_12315;
    if (v_12313 == nil) goto v_12183;
    else goto v_12184;
v_12183:
    goto v_11957;
v_12184:
    goto v_12192;
v_12188:
    v_12314 = v_12315;
    goto v_12189;
v_12190:
    v_12313 = elt(env, 33); // end
    goto v_12191;
v_12192:
    goto v_12188;
v_12189:
    goto v_12190;
v_12191:
    if (v_12314 == v_12313) goto v_12186;
    else goto v_12187;
v_12186:
    v_12313 = nil;
    goto v_11956;
v_12187:
    goto v_12202;
v_12198:
    v_12314 = v_12315;
    goto v_12199;
v_12200:
    v_12313 = elt(env, 40); // err2
    goto v_12201;
v_12202:
    goto v_12198;
v_12199:
    goto v_12200;
v_12201:
    if (v_12314 == v_12313) goto v_12196;
    else goto v_12197;
v_12196:
    goto v_11961;
v_12197:
    goto v_12211;
v_12207:
    v_12314 = v_12315;
    goto v_12208;
v_12209:
    v_12313 = elt(env, 41); // err3
    goto v_12210;
v_12211:
    goto v_12207;
v_12208:
    goto v_12209;
v_12210:
    if (v_12314 == v_12313) goto v_12205;
    else goto v_12206;
v_12205:
    goto v_11962;
v_12206:
v_11959:
    v_12313 = qvalue(elt(env, 42)); // crbuf1!*
    if (v_12313 == nil) goto v_12217;
    v_12313 = elt(env, 43); // "Closing object improperly removed. Redo edit."
    fn = elt(env, 67); // lprim
    v_12313 = (*qfn1(fn))(fn, v_12313);
    env = stack[-2];
    v_12313 = nil;
    qvalue(elt(env, 42)) = v_12313; // crbuf1!*
    v_12313 = nil;
    goto v_11956;
v_12217:
    goto v_12230;
v_12226:
    v_12314 = qvalue(elt(env, 44)); // eof!*
    goto v_12227;
v_12228:
    v_12313 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_12229;
v_12230:
    goto v_12226;
v_12227:
    goto v_12228;
v_12229:
    v_12313 = (LispObject)greaterp2(v_12314, v_12313);
    v_12313 = v_12313 ? lisp_true : nil;
    env = stack[-2];
    if (v_12313 == nil) goto v_12224;
    v_12313 = elt(env, 45); // "End-of-file read"
    fn = elt(env, 67); // lprim
    v_12313 = (*qfn1(fn))(fn, v_12313);
    env = stack[-2];
    v_12313 = elt(env, 46); // (bye)
    {
        fn = elt(env, 57); // lispeval
        return (*qfn1(fn))(fn, v_12313);
    }
v_12224:
    fn = elt(env, 54); // terminalp
    v_12313 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_12313 == nil) goto v_12238;
    v_12313 = nil;
    qvalue(elt(env, 47)) = v_12313; // crbuf!*
    v_12313 = lisp_true;
    qvalue(elt(env, 14)) = v_12313; // !*nosave!*
    goto v_11957;
v_12238:
    v_12313 = nil;
    goto v_11956;
v_11960:
    fn = elt(env, 68); // eofcheck
    v_12313 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_12313 == nil) goto v_12249;
    else goto v_12247;
v_12249:
    goto v_12257;
v_12253:
    v_12314 = qvalue(elt(env, 44)); // eof!*
    goto v_12254;
v_12255:
    v_12313 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12256;
v_12257:
    goto v_12253;
v_12254:
    goto v_12255;
v_12256:
    v_12313 = (LispObject)greaterp2(v_12314, v_12313);
    v_12313 = v_12313 ? lisp_true : nil;
    env = stack[-2];
    if (v_12313 == nil) goto v_12251;
    else goto v_12247;
v_12251:
    goto v_12248;
v_12247:
    goto v_11959;
v_12248:
    goto v_12266;
v_12262:
    v_12314 = stack[0];
    goto v_12263;
v_12264:
    v_12313 = elt(env, 48); // "BEGIN invalid"
    goto v_12265;
v_12266:
    goto v_12262;
v_12263:
    goto v_12264;
v_12265:
    if (equal(v_12314, v_12313)) goto v_12260;
    else goto v_12261;
v_12260:
    goto v_11957;
v_12261:
    v_12313 = lisp_true;
    stack[-1] = v_12313;
v_11961:
    fn = elt(env, 69); // resetparser
    v_12313 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
v_11962:
    v_12313 = lisp_true;
    qvalue(elt(env, 32)) = v_12313; // erfg!*
    v_12313 = qvalue(elt(env, 31)); // !*int
    if (v_12313 == nil) goto v_12278;
    else goto v_12279;
v_12278:
    v_12313 = qvalue(elt(env, 49)); // !*errcont
    v_12313 = (v_12313 == nil ? lisp_true : nil);
    goto v_12277;
v_12279:
    v_12313 = nil;
    goto v_12277;
    v_12313 = nil;
v_12277:
    if (v_12313 == nil) goto v_12275;
    v_12313 = lisp_true;
    qvalue(elt(env, 21)) = v_12313; // !*defn
    v_12313 = lisp_true;
    qvalue(elt(env, 50)) = v_12313; // !*echo
    v_12313 = qvalue(elt(env, 51)); // cmsg!*
    if (v_12313 == nil) goto v_12290;
    else goto v_12291;
v_12290:
    v_12313 = elt(env, 52); // "Continuing with parsing only ..."
    fn = elt(env, 70); // lprie
    v_12313 = (*qfn1(fn))(fn, v_12313);
    env = stack[-2];
    goto v_12289;
v_12291:
v_12289:
    v_12313 = lisp_true;
    qvalue(elt(env, 51)) = v_12313; // cmsg!*
    goto v_12273;
v_12275:
    v_12313 = qvalue(elt(env, 49)); // !*errcont
    if (v_12313 == nil) goto v_12296;
    else goto v_12297;
v_12296:
    v_12313 = stack[-1];
    fn = elt(env, 71); // pause1
    v_12313 = (*qfn1(fn))(fn, v_12313);
    env = stack[-2];
    v_12315 = v_12313;
    v_12313 = v_12315;
    if (v_12313 == nil) goto v_12304;
    v_12313 = v_12315;
    fn = elt(env, 57); // lispeval
    v_12313 = (*qfn1(fn))(fn, v_12313);
    v_12313 = (v_12313 == nil ? lisp_true : nil);
    goto v_11956;
v_12304:
    v_12313 = nil;
    qvalue(elt(env, 32)) = v_12313; // erfg!*
    goto v_12273;
v_12297:
    v_12313 = nil;
    qvalue(elt(env, 32)) = v_12313; // erfg!*
    goto v_12273;
v_12273:
    goto v_11957;
v_11956:
    return onevalue(v_12313);
}



// Code for bas_newnumber

static LispObject CC_bas_newnumber(LispObject env,
                         LispObject v_11950, LispObject v_11951)
{
    env = qenv(env);
    LispObject v_11962, v_11963;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11962 = v_11951;
    v_11963 = v_11950;
// end of prologue
    goto v_11958;
v_11954:
    goto v_11955;
v_11956:
    v_11962 = qcdr(v_11962);
    goto v_11957;
v_11958:
    goto v_11954;
v_11955:
    goto v_11956;
v_11957:
    return cons(v_11963, v_11962);
}



// Code for derivative!-mod!-p!-1

static LispObject CC_derivativeKmodKpK1(LispObject env,
                         LispObject v_11950, LispObject v_11951)
{
    env = qenv(env);
    LispObject v_12054, v_12055, v_12056;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11950,v_11951);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11951;
    stack[-2] = v_11950;
// end of prologue
    v_12054 = stack[-2];
    if (!consp(v_12054)) goto v_11959;
    else goto v_11960;
v_11959:
    v_12054 = lisp_true;
    goto v_11958;
v_11960:
    v_12054 = stack[-2];
    v_12054 = qcar(v_12054);
    v_12054 = (consp(v_12054) ? nil : lisp_true);
    goto v_11958;
    v_12054 = nil;
v_11958:
    if (v_12054 == nil) goto v_11956;
    v_12054 = nil;
    goto v_11954;
v_11956:
    goto v_11975;
v_11971:
    v_12054 = stack[-2];
    v_12054 = qcar(v_12054);
    v_12054 = qcar(v_12054);
    v_12055 = qcar(v_12054);
    goto v_11972;
v_11973:
    v_12054 = stack[-1];
    goto v_11974;
v_11975:
    goto v_11971;
v_11972:
    goto v_11973;
v_11974:
    if (equal(v_12055, v_12054)) goto v_11970;
    v_12054 = nil;
    goto v_11954;
v_11970:
    goto v_11988;
v_11984:
    v_12054 = stack[-2];
    v_12054 = qcar(v_12054);
    v_12054 = qcar(v_12054);
    v_12055 = qcdr(v_12054);
    goto v_11985;
v_11986:
    v_12054 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11987;
v_11988:
    goto v_11984;
v_11985:
    goto v_11986;
v_11987:
    if (v_12055 == v_12054) goto v_11982;
    else goto v_11983;
v_11982:
    v_12054 = stack[-2];
    v_12054 = qcar(v_12054);
    v_12054 = qcdr(v_12054);
    goto v_11954;
v_11983:
    goto v_12004;
v_12000:
    v_12054 = stack[-2];
    v_12054 = qcar(v_12054);
    v_12055 = qcdr(v_12054);
    goto v_12001;
v_12002:
    v_12054 = stack[-2];
    v_12054 = qcar(v_12054);
    v_12054 = qcar(v_12054);
    v_12054 = qcdr(v_12054);
    v_12054 = Lmodular_number(nil, v_12054);
    env = stack[-4];
    goto v_12003;
v_12004:
    goto v_12000;
v_12001:
    goto v_12002;
v_12003:
    fn = elt(env, 1); // multiply!-by!-constant!-mod!-p
    stack[0] = (*qfn2(fn))(fn, v_12055, v_12054);
    env = stack[-4];
    goto v_12018;
v_12014:
    v_12054 = stack[-2];
    v_12055 = qcdr(v_12054);
    goto v_12015;
v_12016:
    v_12054 = stack[-1];
    goto v_12017;
v_12018:
    goto v_12014;
v_12015:
    goto v_12016;
v_12017:
    v_12054 = CC_derivativeKmodKpK1(elt(env, 0), v_12055, v_12054);
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v_12054;
    v_12054 = stack[-3];
    if (v_12054 == nil) goto v_12026;
    else goto v_12027;
v_12026:
    v_12054 = stack[0];
    goto v_12025;
v_12027:
    goto v_12039;
v_12033:
    goto v_12045;
v_12041:
    v_12055 = stack[-1];
    goto v_12042;
v_12043:
    v_12054 = stack[-2];
    v_12054 = qcar(v_12054);
    v_12054 = qcar(v_12054);
    v_12054 = qcdr(v_12054);
    v_12054 = (LispObject)((intptr_t)(v_12054) - 0x10);
    goto v_12044;
v_12045:
    goto v_12041;
v_12042:
    goto v_12043;
v_12044:
    fn = elt(env, 2); // mksp
    v_12056 = (*qfn2(fn))(fn, v_12055, v_12054);
    goto v_12034;
v_12035:
    v_12055 = stack[-3];
    goto v_12036;
v_12037:
    v_12054 = stack[0];
    goto v_12038;
v_12039:
    goto v_12033;
v_12034:
    goto v_12035;
v_12036:
    goto v_12037;
v_12038:
    return acons(v_12056, v_12055, v_12054);
    v_12054 = nil;
v_12025:
    goto v_11954;
    v_12054 = nil;
v_11954:
    return onevalue(v_12054);
}



// Code for carrassoc

static LispObject CC_carrassoc(LispObject env,
                         LispObject v_11950, LispObject v_11951)
{
    env = qenv(env);
    LispObject v_11981, v_11982;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11950,v_11951);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11951;
    stack[-1] = v_11950;
// end of prologue
    goto v_11965;
v_11961:
    v_11982 = stack[-1];
    goto v_11962;
v_11963:
    v_11981 = stack[0];
    goto v_11964;
v_11965:
    goto v_11961;
v_11962:
    goto v_11963;
v_11964:
    fn = elt(env, 4); // rassoc
    v_11981 = (*qfn2(fn))(fn, v_11982, v_11981);
    env = stack[-2];
    v_11982 = v_11981;
    if (!consp(v_11981)) goto v_11959;
    v_11981 = v_11982;
    v_11981 = qcar(v_11981);
    goto v_11955;
v_11959:
    v_11981 = Lterpri(nil, 0);
    env = stack[-2];
    v_11981 = elt(env, 1); // "RASSOC trouble: "
    v_11981 = Lprinc(nil, v_11981);
    env = stack[-2];
    v_11981 = stack[-1];
    v_11981 = Lprin(nil, v_11981);
    env = stack[-2];
    v_11981 = elt(env, 2); // " "
    v_11981 = Lprinc(nil, v_11981);
    env = stack[-2];
    v_11981 = stack[0];
    v_11981 = Lprint(nil, v_11981);
    env = stack[-2];
    v_11981 = elt(env, 3); // "rassoc trouble"
    fn = elt(env, 5); // rederr
    v_11981 = (*qfn1(fn))(fn, v_11981);
    v_11981 = nil;
v_11955:
    return onevalue(v_11981);
}



// Code for ofsf_varlat

static LispObject CC_ofsf_varlat(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_12015, v_12016;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_12015 = v_11950;
// end of prologue
    v_12015 = qcdr(v_12015);
    v_12015 = qcar(v_12015);
    fn = elt(env, 2); // kernels
    v_12015 = (*qfn1(fn))(fn, v_12015);
    env = stack[-4];
    v_12016 = v_12015;
    v_12015 = qvalue(elt(env, 1)); // !*rlbrkcxk
    if (v_12015 == nil) goto v_11962;
    v_12015 = v_12016;
    stack[-3] = v_12015;
v_11969:
    v_12015 = stack[-3];
    if (v_12015 == nil) goto v_11974;
    else goto v_11975;
v_11974:
    v_12015 = nil;
    goto v_11968;
v_11975:
    v_12015 = stack[-3];
    v_12015 = qcar(v_12015);
    fn = elt(env, 3); // rltools_lpvarl
    v_12015 = (*qfn1(fn))(fn, v_12015);
    env = stack[-4];
    stack[-2] = v_12015;
    v_12015 = stack[-2];
    fn = elt(env, 4); // lastpair
    v_12015 = (*qfn1(fn))(fn, v_12015);
    env = stack[-4];
    stack[-1] = v_12015;
    v_12015 = stack[-3];
    v_12015 = qcdr(v_12015);
    stack[-3] = v_12015;
    v_12015 = stack[-1];
    if (!consp(v_12015)) goto v_11989;
    else goto v_11990;
v_11989:
    goto v_11969;
v_11990:
v_11970:
    v_12015 = stack[-3];
    if (v_12015 == nil) goto v_11994;
    else goto v_11995;
v_11994:
    v_12015 = stack[-2];
    goto v_11968;
v_11995:
    goto v_12003;
v_11999:
    stack[0] = stack[-1];
    goto v_12000;
v_12001:
    v_12015 = stack[-3];
    v_12015 = qcar(v_12015);
    fn = elt(env, 3); // rltools_lpvarl
    v_12015 = (*qfn1(fn))(fn, v_12015);
    env = stack[-4];
    goto v_12002;
v_12003:
    goto v_11999;
v_12000:
    goto v_12001;
v_12002:
    v_12015 = Lrplacd(nil, stack[0], v_12015);
    env = stack[-4];
    v_12015 = stack[-1];
    fn = elt(env, 4); // lastpair
    v_12015 = (*qfn1(fn))(fn, v_12015);
    env = stack[-4];
    stack[-1] = v_12015;
    v_12015 = stack[-3];
    v_12015 = qcdr(v_12015);
    stack[-3] = v_12015;
    goto v_11970;
v_11968:
    v_12016 = v_12015;
    goto v_11960;
v_11962:
v_11960:
    v_12015 = v_12016;
    return onevalue(v_12015);
}



// Code for simpqg

static LispObject CC_simpqg(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_11960, v_11961;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11960 = v_11950;
// end of prologue
    goto v_11957;
v_11953:
    v_11961 = v_11960;
    goto v_11954;
v_11955:
    v_11960 = elt(env, 1); // qg
    goto v_11956;
v_11957:
    goto v_11953;
v_11954:
    goto v_11955;
v_11956:
    {
        fn = elt(env, 2); // simpcv
        return (*qfn2(fn))(fn, v_11961, v_11960);
    }
}



// Code for mkprod

static LispObject CC_mkprod(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_12222, v_12223;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_11950;
// end of prologue
// Binding !*exp
// FLUIDBIND: reloadenv=6 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-6, 1, -2);
    qvalue(elt(env, 1)) = nil; // !*exp
// Binding !*sub2
// FLUIDBIND: reloadenv=6 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-6, 2, -1);
    qvalue(elt(env, 2)) = nil; // !*sub2
    v_12222 = stack[-4];
    if (v_12222 == nil) goto v_11966;
    else goto v_11967;
v_11966:
    v_12222 = lisp_true;
    goto v_11965;
v_11967:
    v_12222 = stack[-4];
    fn = elt(env, 8); // kernlp
    v_12222 = (*qfn1(fn))(fn, v_12222);
    env = stack[-6];
    goto v_11965;
    v_12222 = nil;
v_11965:
    if (v_12222 == nil) goto v_11963;
    v_12222 = stack[-4];
    goto v_11959;
v_11963:
    v_12222 = lisp_true;
    qvalue(elt(env, 2)) = v_12222; // !*sub2
    goto v_11982;
v_11978:
    v_12223 = stack[-4];
    goto v_11979;
v_11980:
    v_12222 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11981;
v_11982:
    goto v_11978;
v_11979:
    goto v_11980;
v_11981:
    v_12222 = cons(v_12223, v_12222);
    env = stack[-6];
    fn = elt(env, 9); // subs2
    v_12222 = (*qfn1(fn))(fn, v_12222);
    env = stack[-6];
    stack[0] = v_12222;
    goto v_11993;
v_11989:
    v_12222 = stack[0];
    v_12223 = qcdr(v_12222);
    goto v_11990;
v_11991:
    v_12222 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11992;
v_11993:
    goto v_11989;
v_11990:
    goto v_11991;
v_11992:
    if (v_12223 == v_12222) goto v_11988;
    v_12222 = stack[-4];
    goto v_11959;
v_11988:
    goto v_12004;
v_12000:
    v_12222 = stack[0];
    v_12223 = qcar(v_12222);
    goto v_12001;
v_12002:
    v_12222 = stack[-4];
    goto v_12003;
v_12004:
    goto v_12000;
v_12001:
    goto v_12002;
v_12003:
    if (equal(v_12223, v_12222)) goto v_11999;
    v_12222 = stack[0];
    v_12222 = qcar(v_12222);
    stack[-4] = v_12222;
    v_12222 = stack[-4];
    if (v_12222 == nil) goto v_12016;
    else goto v_12017;
v_12016:
    v_12222 = lisp_true;
    goto v_12015;
v_12017:
    v_12222 = stack[-4];
    fn = elt(env, 8); // kernlp
    v_12222 = (*qfn1(fn))(fn, v_12222);
    env = stack[-6];
    goto v_12015;
    v_12222 = nil;
v_12015:
    if (v_12222 == nil) goto v_12013;
    v_12222 = stack[-4];
    goto v_11959;
v_12013:
    goto v_11986;
v_11999:
v_11986:
    v_12222 = lisp_true;
    qvalue(elt(env, 1)) = v_12222; // !*exp
    v_12222 = stack[-4];
    fn = elt(env, 10); // ckrn
    v_12222 = (*qfn1(fn))(fn, v_12222);
    env = stack[-6];
    stack[-5] = v_12222;
    goto v_12033;
v_12029:
    v_12223 = stack[-4];
    goto v_12030;
v_12031:
    v_12222 = stack[-5];
    goto v_12032;
v_12033:
    goto v_12029;
v_12030:
    goto v_12031;
v_12032:
    fn = elt(env, 11); // quotf
    v_12222 = (*qfn2(fn))(fn, v_12223, v_12222);
    env = stack[-6];
    stack[-4] = v_12222;
    v_12222 = stack[-4];
    fn = elt(env, 12); // expnd
    v_12222 = (*qfn1(fn))(fn, v_12222);
    env = stack[-6];
    stack[0] = v_12222;
    v_12222 = stack[0];
    if (v_12222 == nil) goto v_12044;
    else goto v_12045;
v_12044:
    v_12222 = lisp_true;
    goto v_12043;
v_12045:
    v_12222 = stack[0];
    fn = elt(env, 8); // kernlp
    v_12222 = (*qfn1(fn))(fn, v_12222);
    env = stack[-6];
    goto v_12043;
    v_12222 = nil;
v_12043:
    if (v_12222 == nil) goto v_12041;
    goto v_12057;
v_12053:
    v_12223 = stack[-5];
    goto v_12054;
v_12055:
    v_12222 = stack[0];
    goto v_12056;
v_12057:
    goto v_12053;
v_12054:
    goto v_12055;
v_12056:
    fn = elt(env, 13); // multf
    v_12222 = (*qfn2(fn))(fn, v_12223, v_12222);
    goto v_11959;
v_12041:
    v_12222 = qvalue(elt(env, 3)); // !*mcd
    if (v_12222 == nil) goto v_12063;
    v_12222 = qvalue(elt(env, 4)); // !*sqfree
    if (v_12222 == nil) goto v_12067;
    else goto v_12066;
v_12067:
    v_12222 = qvalue(elt(env, 5)); // !*factor
    if (v_12222 == nil) goto v_12070;
    else goto v_12066;
v_12070:
    v_12222 = qvalue(elt(env, 6)); // !*gcd
    if (v_12222 == nil) goto v_12072;
    else goto v_12066;
v_12072:
    goto v_12063;
v_12066:
    v_12222 = stack[0];
    fn = elt(env, 14); // fctrf
    v_12222 = (*qfn1(fn))(fn, v_12222);
    env = stack[-6];
    stack[-3] = v_12222;
    goto v_12061;
v_12063:
    v_12222 = stack[0];
    fn = elt(env, 10); // ckrn
    v_12222 = (*qfn1(fn))(fn, v_12222);
    env = stack[-6];
    stack[-3] = v_12222;
    goto v_12085;
v_12081:
    v_12223 = stack[0];
    goto v_12082;
v_12083:
    v_12222 = stack[-3];
    goto v_12084;
v_12085:
    goto v_12081;
v_12082:
    goto v_12083;
v_12084:
    fn = elt(env, 11); // quotf
    v_12222 = (*qfn2(fn))(fn, v_12223, v_12222);
    env = stack[-6];
    stack[0] = v_12222;
    goto v_12093;
v_12089:
    goto v_12090;
v_12091:
    goto v_12100;
v_12096:
    v_12223 = stack[0];
    goto v_12097;
v_12098:
    v_12222 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12099;
v_12100:
    goto v_12096;
v_12097:
    goto v_12098;
v_12099:
    v_12222 = cons(v_12223, v_12222);
    env = stack[-6];
    goto v_12092;
v_12093:
    goto v_12089;
v_12090:
    goto v_12091;
v_12092:
    v_12222 = list2(stack[-3], v_12222);
    env = stack[-6];
    stack[-3] = v_12222;
    goto v_12061;
v_12061:
    goto v_12113;
v_12109:
    v_12222 = stack[-3];
    v_12222 = qcdr(v_12222);
    v_12222 = qcar(v_12222);
    v_12223 = qcdr(v_12222);
    goto v_12110;
v_12111:
    v_12222 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12112;
v_12113:
    goto v_12109;
v_12110:
    goto v_12111;
v_12112:
    v_12222 = (LispObject)greaterp2(v_12223, v_12222);
    v_12222 = v_12222 ? lisp_true : nil;
    env = stack[-6];
    if (v_12222 == nil) goto v_12107;
    else goto v_12105;
v_12107:
    v_12222 = stack[-3];
    v_12222 = qcdr(v_12222);
    v_12222 = qcdr(v_12222);
    if (v_12222 == nil) goto v_12119;
    else goto v_12105;
v_12119:
    goto v_12106;
v_12105:
    v_12222 = stack[-3];
    v_12222 = qcar(v_12222);
    stack[0] = v_12222;
    v_12222 = stack[-3];
    v_12222 = qcdr(v_12222);
    stack[-3] = v_12222;
v_12128:
    v_12222 = stack[-3];
    if (v_12222 == nil) goto v_12133;
    else goto v_12134;
v_12133:
    goto v_12127;
v_12134:
    v_12222 = stack[-3];
    v_12222 = qcar(v_12222);
    goto v_12145;
v_12141:
    goto v_12151;
v_12147:
    v_12223 = v_12222;
    v_12223 = qcar(v_12223);
    goto v_12148;
v_12149:
    v_12222 = qcdr(v_12222);
    goto v_12150;
v_12151:
    goto v_12147;
v_12148:
    goto v_12149;
v_12150:
    fn = elt(env, 15); // mksp!*
    v_12223 = (*qfn2(fn))(fn, v_12223, v_12222);
    env = stack[-6];
    goto v_12142;
v_12143:
    v_12222 = stack[0];
    goto v_12144;
v_12145:
    goto v_12141;
v_12142:
    goto v_12143;
v_12144:
    fn = elt(env, 13); // multf
    v_12222 = (*qfn2(fn))(fn, v_12223, v_12222);
    env = stack[-6];
    stack[0] = v_12222;
    v_12222 = stack[-3];
    v_12222 = qcdr(v_12222);
    stack[-3] = v_12222;
    goto v_12128;
v_12127:
    goto v_12104;
v_12106:
    v_12222 = qvalue(elt(env, 7)); // !*group
    if (v_12222 == nil) goto v_12163;
    else goto v_12164;
v_12163:
    goto v_12171;
v_12167:
    v_12222 = stack[-4];
    fn = elt(env, 16); // tmsf
    stack[0] = (*qfn1(fn))(fn, v_12222);
    env = stack[-6];
    goto v_12168;
v_12169:
    v_12222 = stack[-3];
    v_12222 = qcdr(v_12222);
    v_12222 = qcar(v_12222);
    v_12222 = qcar(v_12222);
    fn = elt(env, 16); // tmsf
    v_12222 = (*qfn1(fn))(fn, v_12222);
    env = stack[-6];
    goto v_12170;
v_12171:
    goto v_12167;
v_12168:
    goto v_12169;
v_12170:
    v_12222 = (LispObject)greaterp2(stack[0], v_12222);
    v_12222 = v_12222 ? lisp_true : nil;
    env = stack[-6];
    goto v_12162;
v_12164:
    v_12222 = nil;
    goto v_12162;
    v_12222 = nil;
v_12162:
    if (v_12222 == nil) goto v_12160;
    goto v_12187;
v_12183:
    goto v_12193;
v_12189:
    v_12222 = stack[-3];
    v_12222 = qcdr(v_12222);
    v_12222 = qcar(v_12222);
    v_12223 = qcar(v_12222);
    goto v_12190;
v_12191:
    v_12222 = stack[-3];
    v_12222 = qcdr(v_12222);
    v_12222 = qcar(v_12222);
    v_12222 = qcdr(v_12222);
    goto v_12192;
v_12193:
    goto v_12189;
v_12190:
    goto v_12191;
v_12192:
    fn = elt(env, 15); // mksp!*
    v_12223 = (*qfn2(fn))(fn, v_12223, v_12222);
    env = stack[-6];
    goto v_12184;
v_12185:
    v_12222 = stack[-3];
    v_12222 = qcar(v_12222);
    goto v_12186;
v_12187:
    goto v_12183;
v_12184:
    goto v_12185;
v_12186:
    fn = elt(env, 13); // multf
    v_12222 = (*qfn2(fn))(fn, v_12223, v_12222);
    env = stack[-6];
    stack[0] = v_12222;
    goto v_12104;
v_12160:
    goto v_12211;
v_12207:
    v_12223 = stack[-4];
    goto v_12208;
v_12209:
    v_12222 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12210;
v_12211:
    goto v_12207;
v_12208:
    goto v_12209;
v_12210:
    fn = elt(env, 15); // mksp!*
    v_12222 = (*qfn2(fn))(fn, v_12223, v_12222);
    env = stack[-6];
    stack[0] = v_12222;
    goto v_12104;
v_12104:
    goto v_12219;
v_12215:
    v_12223 = stack[-5];
    goto v_12216;
v_12217:
    v_12222 = stack[0];
    goto v_12218;
v_12219:
    goto v_12215;
v_12216:
    goto v_12217;
v_12218:
    fn = elt(env, 13); // multf
    v_12222 = (*qfn2(fn))(fn, v_12223, v_12222);
v_11959:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_12222);
}



// Code for cl_simpl1

static LispObject CC_cl_simpl1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12677, v_12678, v_12679, v_12680;
    LispObject fn;
    LispObject v_11953, v_11952, v_11951, v_11950;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_simpl1");
    va_start(aa, nargs);
    v_11950 = va_arg(aa, LispObject);
    v_11951 = va_arg(aa, LispObject);
    v_11952 = va_arg(aa, LispObject);
    v_11953 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_11953,v_11952,v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_11950,v_11951,v_11952,v_11953);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_11953;
    stack[-1] = v_11952;
    stack[-2] = v_11951;
    stack[-3] = v_11950;
// end of prologue
    goto v_11970;
v_11966:
    v_12678 = stack[-1];
    goto v_11967;
v_11968:
    v_12677 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11969;
v_11970:
    goto v_11966;
v_11967:
    goto v_11968;
v_11969:
    v_12677 = Leqn(nil, v_12678, v_12677);
    env = stack[-5];
    if (v_12677 == nil) goto v_11964;
    v_12677 = stack[-3];
    goto v_11960;
v_11964:
    v_12677 = stack[-3];
    if (!consp(v_12677)) goto v_11976;
    else goto v_11977;
v_11976:
    v_12677 = stack[-3];
    goto v_11975;
v_11977:
    v_12677 = stack[-3];
    v_12677 = qcar(v_12677);
    goto v_11975;
    v_12677 = nil;
v_11975:
    stack[-4] = v_12677;
    goto v_11996;
v_11992:
    v_12678 = stack[-4];
    goto v_11993;
v_11994:
    v_12677 = elt(env, 1); // true
    goto v_11995;
v_11996:
    goto v_11992;
v_11993:
    goto v_11994;
v_11995:
    if (v_12678 == v_12677) goto v_11990;
    else goto v_11991;
v_11990:
    v_12677 = lisp_true;
    goto v_11989;
v_11991:
    goto v_12006;
v_12002:
    v_12678 = stack[-4];
    goto v_12003;
v_12004:
    v_12677 = elt(env, 2); // false
    goto v_12005;
v_12006:
    goto v_12002;
v_12003:
    goto v_12004;
v_12005:
    v_12677 = (v_12678 == v_12677 ? lisp_true : nil);
    goto v_11989;
    v_12677 = nil;
v_11989:
    if (v_12677 == nil) goto v_11987;
    v_12677 = stack[-3];
    goto v_11960;
v_11987:
    goto v_12023;
v_12019:
    v_12678 = stack[-4];
    goto v_12020;
v_12021:
    v_12677 = elt(env, 3); // or
    goto v_12022;
v_12023:
    goto v_12019;
v_12020:
    goto v_12021;
v_12022:
    if (v_12678 == v_12677) goto v_12017;
    else goto v_12018;
v_12017:
    v_12677 = lisp_true;
    goto v_12016;
v_12018:
    goto v_12033;
v_12029:
    v_12678 = stack[-4];
    goto v_12030;
v_12031:
    v_12677 = elt(env, 4); // and
    goto v_12032;
v_12033:
    goto v_12029;
v_12030:
    goto v_12031;
v_12032:
    v_12677 = (v_12678 == v_12677 ? lisp_true : nil);
    goto v_12016;
    v_12677 = nil;
v_12016:
    if (v_12677 == nil) goto v_12014;
    goto v_12046;
v_12038:
    v_12680 = stack[-4];
    goto v_12039;
v_12040:
    v_12677 = stack[-3];
    v_12679 = qcdr(v_12677);
    goto v_12041;
v_12042:
    v_12678 = stack[-2];
    goto v_12043;
v_12044:
    v_12677 = stack[-1];
    goto v_12045;
v_12046:
    goto v_12038;
v_12039:
    goto v_12040;
v_12041:
    goto v_12042;
v_12043:
    goto v_12044;
v_12045:
    fn = elt(env, 16); // cl_smsimpl!-junct
    v_12677 = (*qfnn(fn))(fn, 4, v_12680, v_12679, v_12678, v_12677);
    env = stack[-5];
    v_12678 = v_12677;
    v_12677 = v_12678;
    if (v_12677 == nil) goto v_12056;
    v_12677 = v_12678;
    v_12677 = qcdr(v_12677);
    if (v_12677 == nil) goto v_12056;
    goto v_12067;
v_12063:
    v_12677 = stack[-4];
    goto v_12064;
v_12065:
    goto v_12066;
v_12067:
    goto v_12063;
v_12064:
    goto v_12065;
v_12066:
    return cons(v_12677, v_12678);
v_12056:
    v_12677 = v_12678;
    if (v_12677 == nil) goto v_12070;
    else goto v_12071;
v_12070:
    goto v_12081;
v_12077:
    v_12678 = stack[-4];
    goto v_12078;
v_12079:
    v_12677 = elt(env, 4); // and
    goto v_12080;
v_12081:
    goto v_12077;
v_12078:
    goto v_12079;
v_12080:
    if (v_12678 == v_12677) goto v_12075;
    else goto v_12076;
v_12075:
    v_12677 = elt(env, 1); // true
    goto v_12074;
v_12076:
    v_12677 = elt(env, 2); // false
    goto v_12074;
    v_12677 = nil;
v_12074:
    goto v_12054;
v_12071:
    v_12677 = v_12678;
    v_12677 = qcar(v_12677);
    goto v_12054;
    v_12677 = nil;
v_12054:
    goto v_11960;
v_12014:
    goto v_12100;
v_12096:
    v_12678 = stack[-4];
    goto v_12097;
v_12098:
    v_12677 = elt(env, 5); // not
    goto v_12099;
v_12100:
    goto v_12096;
v_12097:
    goto v_12098;
v_12099:
    if (v_12678 == v_12677) goto v_12094;
    else goto v_12095;
v_12094:
    goto v_12112;
v_12104:
    v_12677 = stack[-3];
    v_12677 = qcdr(v_12677);
    stack[0] = qcar(v_12677);
    goto v_12105;
v_12106:
    goto v_12107;
v_12108:
    v_12677 = stack[-1];
    v_12678 = sub1(v_12677);
    env = stack[-5];
    goto v_12109;
v_12110:
    v_12677 = elt(env, 5); // not
    goto v_12111;
v_12112:
    goto v_12104;
v_12105:
    goto v_12106;
v_12107:
    goto v_12108;
v_12109:
    goto v_12110;
v_12111:
    v_12677 = CC_cl_simpl1(elt(env, 0), 4, stack[0], stack[-2], v_12678, v_12677);
    env = stack[-5];
    stack[-1] = v_12677;
    goto v_12132;
v_12128:
    v_12678 = stack[-1];
    goto v_12129;
v_12130:
    v_12677 = elt(env, 1); // true
    goto v_12131;
v_12132:
    goto v_12128;
v_12129:
    goto v_12130;
v_12131:
    if (v_12678 == v_12677) goto v_12126;
    else goto v_12127;
v_12126:
    v_12677 = lisp_true;
    goto v_12125;
v_12127:
    goto v_12142;
v_12138:
    v_12678 = stack[-1];
    goto v_12139;
v_12140:
    v_12677 = elt(env, 2); // false
    goto v_12141;
v_12142:
    goto v_12138;
v_12139:
    goto v_12140;
v_12141:
    v_12677 = (v_12678 == v_12677 ? lisp_true : nil);
    goto v_12125;
    v_12677 = nil;
v_12125:
    if (v_12677 == nil) goto v_12123;
    v_12677 = stack[-1];
    {
        fn = elt(env, 17); // cl_flip
        return (*qfn1(fn))(fn, v_12677);
    }
v_12123:
    v_12677 = stack[-1];
    fn = elt(env, 18); // cl_atfp
    v_12677 = (*qfn1(fn))(fn, v_12677);
    env = stack[-5];
    if (v_12677 == nil) goto v_12151;
    v_12677 = stack[-1];
    {
        fn = elt(env, 19); // rl_negateat
        return (*qfn1(fn))(fn, v_12677);
    }
v_12151:
    v_12677 = stack[-1];
    {
        fn = elt(env, 20); // cl_negate!-invol
        return (*qfn1(fn))(fn, v_12677);
    }
v_12095:
    goto v_12170;
v_12166:
    v_12678 = stack[-4];
    goto v_12167;
v_12168:
    v_12677 = elt(env, 6); // ex
    goto v_12169;
v_12170:
    goto v_12166;
v_12167:
    goto v_12168;
v_12169:
    if (v_12678 == v_12677) goto v_12164;
    else goto v_12165;
v_12164:
    v_12677 = lisp_true;
    goto v_12163;
v_12165:
    goto v_12180;
v_12176:
    v_12678 = stack[-4];
    goto v_12177;
v_12178:
    v_12677 = elt(env, 7); // all
    goto v_12179;
v_12180:
    goto v_12176;
v_12177:
    goto v_12178;
v_12179:
    v_12677 = (v_12678 == v_12677 ? lisp_true : nil);
    goto v_12163;
    v_12677 = nil;
v_12163:
    if (v_12677 == nil) goto v_12161;
    v_12677 = qvalue(elt(env, 8)); // !*rlsism
    if (v_12677 == nil) goto v_12187;
    goto v_12194;
v_12190:
    v_12678 = stack[-2];
    goto v_12191;
v_12192:
    v_12677 = stack[-3];
    v_12677 = qcdr(v_12677);
    v_12677 = qcar(v_12677);
    goto v_12193;
v_12194:
    goto v_12190;
v_12191:
    goto v_12192;
v_12193:
    fn = elt(env, 21); // rl_smrmknowl
    v_12677 = (*qfn2(fn))(fn, v_12678, v_12677);
    env = stack[-5];
    stack[-2] = v_12677;
    goto v_12185;
v_12187:
v_12185:
    goto v_12208;
v_12200:
    v_12677 = stack[-3];
    v_12677 = qcdr(v_12677);
    v_12677 = qcdr(v_12677);
    stack[0] = qcar(v_12677);
    goto v_12201;
v_12202:
    goto v_12203;
v_12204:
    v_12677 = stack[-1];
    v_12678 = sub1(v_12677);
    env = stack[-5];
    goto v_12205;
v_12206:
    v_12677 = stack[-4];
    goto v_12207;
v_12208:
    goto v_12200;
v_12201:
    goto v_12202;
v_12203:
    goto v_12204;
v_12205:
    goto v_12206;
v_12207:
    v_12677 = CC_cl_simpl1(elt(env, 0), 4, stack[0], stack[-2], v_12678, v_12677);
    env = stack[-5];
    stack[-1] = v_12677;
    goto v_12229;
v_12225:
    v_12678 = stack[-1];
    goto v_12226;
v_12227:
    v_12677 = elt(env, 1); // true
    goto v_12228;
v_12229:
    goto v_12225;
v_12226:
    goto v_12227;
v_12228:
    if (v_12678 == v_12677) goto v_12223;
    else goto v_12224;
v_12223:
    v_12677 = lisp_true;
    goto v_12222;
v_12224:
    goto v_12239;
v_12235:
    v_12678 = stack[-1];
    goto v_12236;
v_12237:
    v_12677 = elt(env, 2); // false
    goto v_12238;
v_12239:
    goto v_12235;
v_12236:
    goto v_12237;
v_12238:
    v_12677 = (v_12678 == v_12677 ? lisp_true : nil);
    goto v_12222;
    v_12677 = nil;
v_12222:
    if (v_12677 == nil) goto v_12220;
    v_12677 = stack[-1];
    goto v_11960;
v_12220:
    goto v_12252;
v_12248:
    v_12677 = stack[-3];
    v_12677 = qcdr(v_12677);
    stack[0] = qcar(v_12677);
    goto v_12249;
v_12250:
    v_12677 = stack[-1];
    fn = elt(env, 22); // cl_fvarl
    v_12677 = (*qfn1(fn))(fn, v_12677);
    goto v_12251;
v_12252:
    goto v_12248;
v_12249:
    goto v_12250;
v_12251:
    v_12677 = Lmemq(nil, stack[0], v_12677);
    if (v_12677 == nil) goto v_12246;
    else goto v_12247;
v_12246:
    v_12677 = stack[-1];
    goto v_11960;
v_12247:
    goto v_12267;
v_12261:
    v_12679 = stack[-4];
    goto v_12262;
v_12263:
    v_12677 = stack[-3];
    v_12677 = qcdr(v_12677);
    v_12678 = qcar(v_12677);
    goto v_12264;
v_12265:
    v_12677 = stack[-1];
    goto v_12266;
v_12267:
    goto v_12261;
v_12262:
    goto v_12263;
v_12264:
    goto v_12265;
v_12266:
    return list3(v_12679, v_12678, v_12677);
v_12161:
    goto v_12285;
v_12281:
    v_12678 = stack[-4];
    goto v_12282;
v_12283:
    v_12677 = elt(env, 9); // bex
    goto v_12284;
v_12285:
    goto v_12281;
v_12282:
    goto v_12283;
v_12284:
    if (v_12678 == v_12677) goto v_12279;
    else goto v_12280;
v_12279:
    v_12677 = lisp_true;
    goto v_12278;
v_12280:
    goto v_12295;
v_12291:
    v_12678 = stack[-4];
    goto v_12292;
v_12293:
    v_12677 = elt(env, 10); // ball
    goto v_12294;
v_12295:
    goto v_12291;
v_12292:
    goto v_12293;
v_12294:
    v_12677 = (v_12678 == v_12677 ? lisp_true : nil);
    goto v_12278;
    v_12677 = nil;
v_12278:
    if (v_12677 == nil) goto v_12276;
    v_12677 = qvalue(elt(env, 8)); // !*rlsism
    if (v_12677 == nil) goto v_12302;
    goto v_12309;
v_12305:
    v_12678 = stack[-2];
    goto v_12306;
v_12307:
    v_12677 = stack[-3];
    v_12677 = qcdr(v_12677);
    v_12677 = qcar(v_12677);
    goto v_12308;
v_12309:
    goto v_12305;
v_12306:
    goto v_12307;
v_12308:
    fn = elt(env, 21); // rl_smrmknowl
    v_12677 = (*qfn2(fn))(fn, v_12678, v_12677);
    env = stack[-5];
    stack[-2] = v_12677;
    goto v_12300;
v_12302:
v_12300:
    goto v_12321;
v_12315:
    v_12679 = stack[-3];
    goto v_12316;
v_12317:
    v_12678 = stack[-2];
    goto v_12318;
v_12319:
    v_12677 = stack[-1];
    goto v_12320;
v_12321:
    goto v_12315;
v_12316:
    goto v_12317;
v_12318:
    goto v_12319;
v_12320:
    {
        fn = elt(env, 23); // cl_simplbq
        return (*qfnn(fn))(fn, 3, v_12679, v_12678, v_12677);
    }
v_12276:
    goto v_12333;
v_12329:
    v_12678 = stack[-4];
    goto v_12330;
v_12331:
    v_12677 = elt(env, 11); // impl
    goto v_12332;
v_12333:
    goto v_12329;
v_12330:
    goto v_12331;
v_12332:
    if (v_12678 == v_12677) goto v_12327;
    else goto v_12328;
v_12327:
    goto v_12345;
v_12337:
    v_12677 = stack[-3];
    v_12677 = qcdr(v_12677);
    v_12680 = qcar(v_12677);
    goto v_12338;
v_12339:
    v_12677 = stack[-3];
    v_12677 = qcdr(v_12677);
    v_12677 = qcdr(v_12677);
    v_12679 = qcar(v_12677);
    goto v_12340;
v_12341:
    v_12678 = stack[-2];
    goto v_12342;
v_12343:
    v_12677 = stack[-1];
    goto v_12344;
v_12345:
    goto v_12337;
v_12338:
    goto v_12339;
v_12340:
    goto v_12341;
v_12342:
    goto v_12343;
v_12344:
    {
        fn = elt(env, 24); // cl_smsimpl!-imprep
        return (*qfnn(fn))(fn, 4, v_12680, v_12679, v_12678, v_12677);
    }
v_12328:
    goto v_12363;
v_12359:
    v_12678 = stack[-4];
    goto v_12360;
v_12361:
    v_12677 = elt(env, 12); // repl
    goto v_12362;
v_12363:
    goto v_12359;
v_12360:
    goto v_12361;
v_12362:
    if (v_12678 == v_12677) goto v_12357;
    else goto v_12358;
v_12357:
    goto v_12375;
v_12367:
    v_12677 = stack[-3];
    v_12677 = qcdr(v_12677);
    v_12677 = qcdr(v_12677);
    v_12680 = qcar(v_12677);
    goto v_12368;
v_12369:
    v_12677 = stack[-3];
    v_12677 = qcdr(v_12677);
    v_12679 = qcar(v_12677);
    goto v_12370;
v_12371:
    v_12678 = stack[-2];
    goto v_12372;
v_12373:
    v_12677 = stack[-1];
    goto v_12374;
v_12375:
    goto v_12367;
v_12368:
    goto v_12369;
v_12370:
    goto v_12371;
v_12372:
    goto v_12373;
v_12374:
    {
        fn = elt(env, 24); // cl_smsimpl!-imprep
        return (*qfnn(fn))(fn, 4, v_12680, v_12679, v_12678, v_12677);
    }
v_12358:
    goto v_12393;
v_12389:
    v_12678 = stack[-4];
    goto v_12390;
v_12391:
    v_12677 = elt(env, 13); // equiv
    goto v_12392;
v_12393:
    goto v_12389;
v_12390:
    goto v_12391;
v_12392:
    if (v_12678 == v_12677) goto v_12387;
    else goto v_12388;
v_12387:
    goto v_12405;
v_12397:
    v_12677 = stack[-3];
    v_12677 = qcdr(v_12677);
    v_12680 = qcar(v_12677);
    goto v_12398;
v_12399:
    v_12677 = stack[-3];
    v_12677 = qcdr(v_12677);
    v_12677 = qcdr(v_12677);
    v_12679 = qcar(v_12677);
    goto v_12400;
v_12401:
    v_12678 = stack[-2];
    goto v_12402;
v_12403:
    v_12677 = stack[-1];
    goto v_12404;
v_12405:
    goto v_12397;
v_12398:
    goto v_12399;
v_12400:
    goto v_12401;
v_12402:
    goto v_12403;
v_12404:
    {
        fn = elt(env, 25); // cl_smsimpl!-equiv
        return (*qfnn(fn))(fn, 4, v_12680, v_12679, v_12678, v_12677);
    }
v_12388:
    goto v_12424;
v_12420:
    v_12678 = stack[-4];
    goto v_12421;
v_12422:
    v_12677 = elt(env, 14); // cl_simpl
    goto v_12423;
v_12424:
    goto v_12420;
v_12421:
    goto v_12422;
v_12423:
    fn = elt(env, 26); // rl_external
    v_12677 = (*qfn2(fn))(fn, v_12678, v_12677);
    env = stack[-5];
    v_12678 = v_12677;
    if (v_12677 == nil) goto v_12418;
    goto v_12432;
v_12428:
    stack[0] = v_12678;
    goto v_12429;
v_12430:
    v_12677 = stack[-3];
    v_12677 = ncons(v_12677);
    env = stack[-5];
    goto v_12431;
v_12432:
    goto v_12428;
v_12429:
    goto v_12430;
v_12431:
    {
        LispObject v_12686 = stack[0];
        fn = elt(env, 27); // apply
        return (*qfn2(fn))(fn, v_12686, v_12677);
    }
v_12418:
    goto v_12441;
v_12437:
    v_12678 = stack[-3];
    goto v_12438;
v_12439:
    v_12677 = stack[0];
    goto v_12440;
v_12441:
    goto v_12437;
v_12438:
    goto v_12439;
v_12440:
    fn = elt(env, 28); // cl_simplat
    v_12677 = (*qfn2(fn))(fn, v_12678, v_12677);
    env = stack[-5];
    v_12678 = v_12677;
    v_12677 = qvalue(elt(env, 8)); // !*rlsism
    if (v_12677 == nil) goto v_12447;
    v_12677 = v_12678;
    if (!consp(v_12677)) goto v_12451;
    else goto v_12452;
v_12451:
    v_12677 = v_12678;
    goto v_12450;
v_12452:
    v_12677 = v_12678;
    v_12677 = qcar(v_12677);
    goto v_12450;
    v_12677 = nil;
v_12450:
    stack[-4] = v_12677;
    goto v_12471;
v_12467:
    v_12679 = stack[-4];
    goto v_12468;
v_12469:
    v_12677 = elt(env, 3); // or
    goto v_12470;
v_12471:
    goto v_12467;
v_12468:
    goto v_12469;
v_12470:
    if (v_12679 == v_12677) goto v_12465;
    else goto v_12466;
v_12465:
    v_12677 = lisp_true;
    goto v_12464;
v_12466:
    goto v_12481;
v_12477:
    v_12679 = stack[-4];
    goto v_12478;
v_12479:
    v_12677 = elt(env, 4); // and
    goto v_12480;
v_12481:
    goto v_12477;
v_12478:
    goto v_12479;
v_12480:
    v_12677 = (v_12679 == v_12677 ? lisp_true : nil);
    goto v_12464;
    v_12677 = nil;
v_12464:
    if (v_12677 == nil) goto v_12462;
    goto v_12494;
v_12486:
    v_12680 = stack[-4];
    goto v_12487;
v_12488:
    v_12677 = v_12678;
    v_12679 = qcdr(v_12677);
    goto v_12489;
v_12490:
    v_12678 = stack[-2];
    goto v_12491;
v_12492:
    v_12677 = stack[-1];
    goto v_12493;
v_12494:
    goto v_12486;
v_12487:
    goto v_12488;
v_12489:
    goto v_12490;
v_12491:
    goto v_12492;
v_12493:
    fn = elt(env, 16); // cl_smsimpl!-junct
    v_12677 = (*qfnn(fn))(fn, 4, v_12680, v_12679, v_12678, v_12677);
    env = stack[-5];
    v_12678 = v_12677;
    v_12677 = v_12678;
    if (v_12677 == nil) goto v_12504;
    v_12677 = v_12678;
    v_12677 = qcdr(v_12677);
    if (v_12677 == nil) goto v_12504;
    goto v_12515;
v_12511:
    v_12677 = stack[-4];
    goto v_12512;
v_12513:
    goto v_12514;
v_12515:
    goto v_12511;
v_12512:
    goto v_12513;
v_12514:
    return cons(v_12677, v_12678);
v_12504:
    v_12677 = v_12678;
    if (v_12677 == nil) goto v_12518;
    else goto v_12519;
v_12518:
    goto v_12529;
v_12525:
    v_12678 = stack[-4];
    goto v_12526;
v_12527:
    v_12677 = elt(env, 4); // and
    goto v_12528;
v_12529:
    goto v_12525;
v_12526:
    goto v_12527;
v_12528:
    if (v_12678 == v_12677) goto v_12523;
    else goto v_12524;
v_12523:
    v_12677 = elt(env, 1); // true
    goto v_12522;
v_12524:
    v_12677 = elt(env, 2); // false
    goto v_12522;
    v_12677 = nil;
v_12522:
    goto v_12502;
v_12519:
    v_12677 = v_12678;
    v_12677 = qcar(v_12677);
    goto v_12502;
    v_12677 = nil;
v_12502:
    goto v_11960;
v_12462:
    goto v_12552;
v_12548:
    v_12679 = stack[-4];
    goto v_12549;
v_12550:
    v_12677 = elt(env, 1); // true
    goto v_12551;
v_12552:
    goto v_12548;
v_12549:
    goto v_12550;
v_12551:
    if (v_12679 == v_12677) goto v_12546;
    else goto v_12547;
v_12546:
    v_12677 = lisp_true;
    goto v_12545;
v_12547:
    goto v_12562;
v_12558:
    v_12679 = stack[-4];
    goto v_12559;
v_12560:
    v_12677 = elt(env, 2); // false
    goto v_12561;
v_12562:
    goto v_12558;
v_12559:
    goto v_12560;
v_12561:
    v_12677 = (v_12679 == v_12677 ? lisp_true : nil);
    goto v_12545;
    v_12677 = nil;
v_12545:
    if (v_12677 == nil) goto v_12543;
    v_12677 = v_12678;
    goto v_11960;
v_12543:
    goto v_12576;
v_12568:
    stack[-3] = elt(env, 4); // and
    goto v_12569;
v_12570:
    v_12677 = v_12678;
    stack[0] = ncons(v_12677);
    env = stack[-5];
    goto v_12571;
v_12572:
    v_12677 = stack[-2];
    fn = elt(env, 29); // rl_smcpknowl
    v_12678 = (*qfn1(fn))(fn, v_12677);
    env = stack[-5];
    goto v_12573;
v_12574:
    v_12677 = stack[-1];
    goto v_12575;
v_12576:
    goto v_12568;
v_12569:
    goto v_12570;
v_12571:
    goto v_12572;
v_12573:
    goto v_12574;
v_12575:
    fn = elt(env, 30); // rl_smupdknowl
    v_12677 = (*qfnn(fn))(fn, 4, stack[-3], stack[0], v_12678, v_12677);
    env = stack[-5];
    goto v_12591;
v_12587:
    v_12679 = v_12677;
    goto v_12588;
v_12589:
    v_12678 = elt(env, 2); // false
    goto v_12590;
v_12591:
    goto v_12587;
v_12588:
    goto v_12589;
v_12590:
    if (v_12679 == v_12678) goto v_12585;
    else goto v_12586;
v_12585:
    v_12677 = elt(env, 2); // false
    goto v_11960;
v_12586:
    goto v_12604;
v_12596:
    v_12680 = elt(env, 4); // and
    goto v_12597;
v_12598:
    v_12679 = stack[-2];
    goto v_12599;
v_12600:
    v_12678 = v_12677;
    goto v_12601;
v_12602:
    v_12677 = stack[-1];
    goto v_12603;
v_12604:
    goto v_12596;
v_12597:
    goto v_12598;
v_12599:
    goto v_12600;
v_12601:
    goto v_12602;
v_12603:
    fn = elt(env, 31); // rl_smmkatl
    v_12677 = (*qfnn(fn))(fn, 4, v_12680, v_12679, v_12678, v_12677);
    env = stack[-5];
    v_12678 = v_12677;
    goto v_12617;
v_12613:
    v_12679 = v_12678;
    goto v_12614;
v_12615:
    v_12677 = elt(env, 2); // false
    goto v_12616;
v_12617:
    goto v_12613;
v_12614:
    goto v_12615;
v_12616:
    if (v_12679 == v_12677) goto v_12611;
    else goto v_12612;
v_12611:
    v_12677 = elt(env, 2); // false
    goto v_12610;
v_12612:
    v_12677 = v_12678;
    if (v_12677 == nil) goto v_12626;
    v_12677 = v_12678;
    v_12677 = qcdr(v_12677);
    if (v_12677 == nil) goto v_12626;
    goto v_12637;
v_12633:
    v_12677 = elt(env, 4); // and
    goto v_12634;
v_12635:
    goto v_12636;
v_12637:
    goto v_12633;
v_12634:
    goto v_12635;
v_12636:
    return cons(v_12677, v_12678);
v_12626:
    v_12677 = v_12678;
    if (v_12677 == nil) goto v_12640;
    else goto v_12641;
v_12640:
    goto v_12651;
v_12647:
    v_12678 = elt(env, 4); // and
    goto v_12648;
v_12649:
    v_12677 = elt(env, 4); // and
    goto v_12650;
v_12651:
    goto v_12647;
v_12648:
    goto v_12649;
v_12650:
    if (v_12678 == v_12677) goto v_12645;
    else goto v_12646;
v_12645:
    v_12677 = elt(env, 1); // true
    goto v_12644;
v_12646:
    v_12677 = elt(env, 2); // false
    goto v_12644;
    v_12677 = nil;
v_12644:
    goto v_12624;
v_12641:
    v_12677 = v_12678;
    v_12677 = qcar(v_12677);
    goto v_12624;
    v_12677 = nil;
v_12624:
    goto v_12610;
    v_12677 = nil;
v_12610:
    goto v_11960;
v_12447:
    v_12677 = v_12678;
    if (v_12677 == nil) goto v_12665;
    v_12677 = v_12678;
    goto v_11960;
v_12665:
    goto v_12674;
v_12670:
    v_12678 = elt(env, 15); // "cl_simpl1(): unknown operator"
    goto v_12671;
v_12672:
    v_12677 = stack[-4];
    goto v_12673;
v_12674:
    goto v_12670;
v_12671:
    goto v_12672;
v_12673:
    v_12677 = list2(v_12678, v_12677);
    env = stack[-5];
    fn = elt(env, 32); // rederr
    v_12677 = (*qfn1(fn))(fn, v_12677);
    v_12677 = nil;
v_11960:
    return onevalue(v_12677);
}



// Code for gb_buch!-ev_divides!?

static LispObject CC_gb_buchKev_dividesW(LispObject env,
                         LispObject v_11950, LispObject v_11951)
{
    env = qenv(env);
    LispObject v_11961, v_11962;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11962 = v_11951;
    v_11961 = v_11950;
// end of prologue
    goto v_11958;
v_11954:
    goto v_11955;
v_11956:
    goto v_11957;
v_11958:
    goto v_11954;
v_11955:
    goto v_11956;
v_11957:
    {
        fn = elt(env, 1); // ev_mtest!?
        return (*qfn2(fn))(fn, v_11962, v_11961);
    }
}



// Code for ev_invlexcomp

static LispObject CC_ev_invlexcomp(LispObject env,
                         LispObject v_11950, LispObject v_11951)
{
    env = qenv(env);
    LispObject v_12039, v_12040;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11950,v_11951);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11951;
    stack[-1] = v_11950;
// end of prologue
v_11949:
    v_12039 = stack[-1];
    if (v_12039 == nil) goto v_11958;
    else goto v_11959;
v_11958:
    v_12039 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11955;
v_11959:
    goto v_11971;
v_11967:
    v_12039 = stack[-1];
    v_12040 = qcar(v_12039);
    goto v_11968;
v_11969:
    v_12039 = stack[0];
    v_12039 = qcar(v_12039);
    goto v_11970;
v_11971:
    goto v_11967;
v_11968:
    goto v_11969;
v_11970:
    fn = elt(env, 1); // iequal
    v_12039 = (*qfn2(fn))(fn, v_12040, v_12039);
    env = stack[-3];
    if (v_12039 == nil) goto v_11965;
    goto v_11981;
v_11977:
    v_12039 = stack[-1];
    v_12040 = qcdr(v_12039);
    goto v_11978;
v_11979:
    v_12039 = stack[0];
    v_12039 = qcdr(v_12039);
    goto v_11980;
v_11981:
    goto v_11977;
v_11978:
    goto v_11979;
v_11980:
    stack[-1] = v_12040;
    stack[0] = v_12039;
    goto v_11949;
v_11965:
    goto v_11991;
v_11987:
    v_12039 = stack[-1];
    v_12040 = qcdr(v_12039);
    goto v_11988;
v_11989:
    v_12039 = stack[0];
    v_12039 = qcdr(v_12039);
    goto v_11990;
v_11991:
    goto v_11987;
v_11988:
    goto v_11989;
v_11990:
    v_12039 = CC_ev_invlexcomp(elt(env, 0), v_12040, v_12039);
    env = stack[-3];
    stack[-2] = v_12039;
    goto v_12005;
v_12001:
    v_12040 = stack[-2];
    goto v_12002;
v_12003:
    v_12039 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12004;
v_12005:
    goto v_12001;
v_12002:
    goto v_12003;
v_12004:
    fn = elt(env, 1); // iequal
    v_12039 = (*qfn2(fn))(fn, v_12040, v_12039);
    env = stack[-3];
    if (v_12039 == nil) goto v_11998;
    else goto v_11999;
v_11998:
    v_12039 = stack[-2];
    goto v_11955;
v_11999:
    goto v_12018;
v_12014:
    v_12039 = stack[0];
    v_12040 = qcar(v_12039);
    goto v_12015;
v_12016:
    v_12039 = stack[-1];
    v_12039 = qcar(v_12039);
    goto v_12017;
v_12018:
    goto v_12014;
v_12015:
    goto v_12016;
v_12017:
    fn = elt(env, 1); // iequal
    v_12039 = (*qfn2(fn))(fn, v_12040, v_12039);
    if (v_12039 == nil) goto v_12012;
    v_12039 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11955;
v_12012:
    goto v_12032;
v_12028:
    v_12039 = stack[0];
    v_12040 = qcar(v_12039);
    goto v_12029;
v_12030:
    v_12039 = stack[-1];
    v_12039 = qcar(v_12039);
    goto v_12031;
v_12032:
    goto v_12028;
v_12029:
    goto v_12030;
v_12031:
    if (((intptr_t)(v_12040)) > ((intptr_t)(v_12039))) goto v_12026;
    else goto v_12027;
v_12026:
    v_12039 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11955;
v_12027:
    v_12039 = (LispObject)-16+TAG_FIXNUM; // -1
v_11955:
    return onevalue(v_12039);
}



// Code for ir2mml

static LispObject CC_ir2mml(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_11968;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_11950;
// end of prologue
    v_11968 = elt(env, 1); // (indent)
    fn = elt(env, 6); // fluid
    v_11968 = (*qfn1(fn))(fn, v_11968);
    env = stack[-1];
    v_11968 = (LispObject)48+TAG_FIXNUM; // 3
    qvalue(elt(env, 2)) = v_11968; // ind
    v_11968 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 3)) = v_11968; // indent
    v_11968 = elt(env, 4); // "<math>"
    fn = elt(env, 7); // printout
    v_11968 = (*qfn1(fn))(fn, v_11968);
    env = stack[-1];
    v_11968 = lisp_true;
    fn = elt(env, 8); // indent!*
    v_11968 = (*qfn1(fn))(fn, v_11968);
    env = stack[-1];
    v_11968 = stack[0];
    fn = elt(env, 9); // expression
    v_11968 = (*qfn1(fn))(fn, v_11968);
    env = stack[-1];
    v_11968 = nil;
    fn = elt(env, 8); // indent!*
    v_11968 = (*qfn1(fn))(fn, v_11968);
    env = stack[-1];
    v_11968 = elt(env, 5); // "</math>"
    fn = elt(env, 7); // printout
    v_11968 = (*qfn1(fn))(fn, v_11968);
    v_11968 = nil;
    return onevalue(v_11968);
}



// Code for rd!:prep

static LispObject CC_rdTprep(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_11974;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_11950;
// end of prologue
    v_11974 = qvalue(elt(env, 1)); // !*noconvert
    if (v_11974 == nil) goto v_11955;
    v_11974 = stack[0];
    {
        fn = elt(env, 2); // rdprep1
        return (*qfn1(fn))(fn, v_11974);
    }
v_11955:
    v_11974 = stack[0];
    fn = elt(env, 3); // rd!:onep
    v_11974 = (*qfn1(fn))(fn, v_11974);
    env = stack[-1];
    if (v_11974 == nil) goto v_11960;
    v_11974 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11953;
v_11960:
    v_11974 = stack[0];
    fn = elt(env, 4); // rd!:minus
    v_11974 = (*qfn1(fn))(fn, v_11974);
    env = stack[-1];
    fn = elt(env, 3); // rd!:onep
    v_11974 = (*qfn1(fn))(fn, v_11974);
    env = stack[-1];
    if (v_11974 == nil) goto v_11965;
    v_11974 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_11953;
v_11965:
    v_11974 = stack[0];
    {
        fn = elt(env, 2); // rdprep1
        return (*qfn1(fn))(fn, v_11974);
    }
    v_11974 = nil;
v_11953:
    return onevalue(v_11974);
}



// Code for chk

static LispObject CC_chk(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_12031, v_12032, v_12033;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11950;
// end of prologue
v_11949:
    v_12031 = stack[0];
    if (v_12031 == nil) goto v_11954;
    else goto v_11955;
v_11954:
    v_12031 = lisp_true;
    goto v_11953;
v_11955:
    goto v_11968;
v_11964:
    v_12032 = stack[0];
    goto v_11965;
v_11966:
    v_12031 = lisp_true;
    goto v_11967;
v_11968:
    goto v_11964;
v_11965:
    goto v_11966;
v_11967:
    if (v_12032 == v_12031) goto v_11962;
    else goto v_11963;
v_11962:
    v_12031 = lisp_true;
    goto v_11961;
v_11963:
    v_12031 = stack[0];
    v_12031 = qcar(v_12031);
    fn = elt(env, 1); // bsubs
    v_12031 = (*qfn1(fn))(fn, v_12031);
    env = stack[-2];
    stack[-1] = v_12031;
    v_12031 = stack[-1];
    fn = elt(env, 2); // freexp
    v_12031 = (*qfn1(fn))(fn, v_12031);
    env = stack[-2];
    if (v_12031 == nil) goto v_11981;
    v_12031 = stack[0];
    v_12031 = qcdr(v_12031);
    v_12031 = CC_chk(elt(env, 0), v_12031);
    v_12033 = v_12031;
    v_12031 = v_12033;
    if (v_12031 == nil) goto v_11990;
    else goto v_11991;
v_11990:
    v_12031 = nil;
    goto v_11989;
v_11991:
    goto v_12000;
v_11996:
    v_12032 = v_12033;
    goto v_11997;
v_11998:
    v_12031 = lisp_true;
    goto v_11999;
v_12000:
    goto v_11996;
v_11997:
    goto v_11998;
v_11999:
    if (v_12032 == v_12031) goto v_11994;
    else goto v_11995;
v_11994:
    v_12031 = stack[-1];
    return ncons(v_12031);
v_11995:
    goto v_12012;
v_12008:
    v_12031 = stack[-1];
    goto v_12009;
v_12010:
    v_12032 = v_12033;
    goto v_12011;
v_12012:
    goto v_12008;
v_12009:
    goto v_12010;
v_12011:
    return cons(v_12031, v_12032);
    v_12031 = nil;
v_11989:
    goto v_11979;
v_11981:
    goto v_12021;
v_12017:
    v_12031 = stack[-1];
    fn = elt(env, 3); // reval
    v_12032 = (*qfn1(fn))(fn, v_12031);
    env = stack[-2];
    goto v_12018;
v_12019:
    v_12031 = lisp_true;
    goto v_12020;
v_12021:
    goto v_12017;
v_12018:
    goto v_12019;
v_12020:
    if (v_12032 == v_12031) goto v_12015;
    else goto v_12016;
v_12015:
    v_12031 = stack[0];
    v_12031 = qcdr(v_12031);
    stack[0] = v_12031;
    goto v_11949;
v_12016:
    v_12031 = nil;
    goto v_11979;
    v_12031 = nil;
v_11979:
    goto v_11961;
    v_12031 = nil;
v_11961:
    goto v_11953;
    v_12031 = nil;
v_11953:
    return onevalue(v_12031);
}



// Code for expvec2a

static LispObject CC_expvec2a(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_11960, v_11961;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11960 = v_11950;
// end of prologue
    goto v_11957;
v_11953:
    v_11961 = v_11960;
    goto v_11954;
v_11955:
    v_11960 = qvalue(elt(env, 1)); // dipvars!*
    goto v_11956;
v_11957:
    goto v_11953;
v_11954:
    goto v_11955;
v_11956:
    {
        fn = elt(env, 2); // expvec2a1
        return (*qfn2(fn))(fn, v_11961, v_11960);
    }
}



// Code for treesizep

static LispObject CC_treesizep(LispObject env,
                         LispObject v_11950, LispObject v_11951)
{
    env = qenv(env);
    LispObject v_11968, v_11969;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11950,v_11951);
    }
// copy arguments values to proper place
    v_11968 = v_11951;
    v_11969 = v_11950;
// end of prologue
    goto v_11957;
v_11953:
    goto v_11963;
v_11959:
    goto v_11960;
v_11961:
    goto v_11962;
v_11963:
    goto v_11959;
v_11960:
    goto v_11961;
v_11962:
    fn = elt(env, 1); // treesizep1
    v_11969 = (*qfn2(fn))(fn, v_11969, v_11968);
    goto v_11954;
v_11955:
    v_11968 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11956;
v_11957:
    goto v_11953;
v_11954:
    goto v_11955;
v_11956:
    v_11968 = (v_11969 == v_11968 ? lisp_true : nil);
    return onevalue(v_11968);
}



// Code for ncoeffs

static LispObject CC_ncoeffs(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_12021, v_12022;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_12022 = v_11950;
// end of prologue
    stack[-4] = nil;
    stack[-3] = nil;
// Binding d
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-5, 1, -2);
    qvalue(elt(env, 1)) = nil; // d
    v_12021 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_12021; // d
    v_12021 = v_12022;
    stack[-1] = v_12021;
v_11961:
    v_12021 = stack[-1];
    if (v_12021 == nil) goto v_11965;
    else goto v_11966;
v_11965:
    goto v_11960;
v_11966:
    v_12021 = stack[-1];
    v_12021 = qcar(v_12021);
    stack[0] = v_12021;
    v_12021 = stack[0];
    v_12021 = qcar(v_12021);
    stack[-4] = v_12021;
v_11976:
    goto v_11986;
v_11982:
    v_12022 = qvalue(elt(env, 1)); // d
    goto v_11983;
v_11984:
    v_12021 = stack[-4];
    goto v_11985;
v_11986:
    goto v_11982;
v_11983:
    goto v_11984;
v_11985:
    v_12021 = (LispObject)lessp2(v_12022, v_12021);
    v_12021 = v_12021 ? lisp_true : nil;
    env = stack[-5];
    if (v_12021 == nil) goto v_11979;
    else goto v_11980;
v_11979:
    goto v_11975;
v_11980:
    goto v_11995;
v_11991:
    v_12022 = nil;
    goto v_11992;
v_11993:
    v_12021 = stack[-3];
    goto v_11994;
v_11995:
    goto v_11991;
v_11992:
    goto v_11993;
v_11994:
    v_12021 = cons(v_12022, v_12021);
    env = stack[-5];
    stack[-3] = v_12021;
    v_12021 = qvalue(elt(env, 1)); // d
    v_12021 = add1(v_12021);
    env = stack[-5];
    qvalue(elt(env, 1)) = v_12021; // d
    goto v_11976;
v_11975:
    v_12021 = qvalue(elt(env, 1)); // d
    v_12021 = add1(v_12021);
    env = stack[-5];
    qvalue(elt(env, 1)) = v_12021; // d
    goto v_12007;
v_12003:
    v_12021 = stack[0];
    v_12022 = qcdr(v_12021);
    goto v_12004;
v_12005:
    v_12021 = stack[-3];
    goto v_12006;
v_12007:
    goto v_12003;
v_12004:
    goto v_12005;
v_12006:
    v_12021 = cons(v_12022, v_12021);
    env = stack[-5];
    stack[-3] = v_12021;
    v_12021 = stack[-1];
    v_12021 = qcdr(v_12021);
    stack[-1] = v_12021;
    goto v_11961;
v_11960:
    goto v_12018;
v_12014:
    v_12022 = stack[-4];
    goto v_12015;
v_12016:
    v_12021 = stack[-3];
    goto v_12017;
v_12018:
    goto v_12014;
v_12015:
    goto v_12016;
v_12017:
    v_12021 = cons(v_12022, v_12021);
    ;}  // end of a binding scope
    return onevalue(v_12021);
}



// Code for nfactorial

static LispObject CC_nfactorial(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_12008, v_12009;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_11950;
// end of prologue
    goto v_11961;
v_11957:
    v_12009 = stack[-1];
    goto v_11958;
v_11959:
    v_12008 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_11960;
v_11961:
    goto v_11957;
v_11958:
    goto v_11959;
v_11960:
    v_12008 = (LispObject)greaterp2(v_12009, v_12008);
    v_12008 = v_12008 ? lisp_true : nil;
    env = stack[-3];
    if (v_12008 == nil) goto v_11955;
    goto v_11969;
v_11965:
    v_12009 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11966;
v_11967:
    v_12008 = stack[-1];
    goto v_11968;
v_11969:
    goto v_11965;
v_11966:
    goto v_11967;
v_11968:
    {
        fn = elt(env, 1); // fac!-part
        return (*qfn2(fn))(fn, v_12009, v_12008);
    }
v_11955:
    v_12008 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_12008;
    v_12008 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_12008;
v_11981:
    goto v_11993;
v_11989:
    v_12009 = stack[-1];
    goto v_11990;
v_11991:
    v_12008 = stack[0];
    goto v_11992;
v_11993:
    goto v_11989;
v_11990:
    goto v_11991;
v_11992:
    v_12008 = difference2(v_12009, v_12008);
    env = stack[-3];
    v_12008 = Lminusp(nil, v_12008);
    env = stack[-3];
    if (v_12008 == nil) goto v_11986;
    goto v_11980;
v_11986:
    goto v_12002;
v_11998:
    v_12009 = stack[-2];
    goto v_11999;
v_12000:
    v_12008 = stack[0];
    goto v_12001;
v_12002:
    goto v_11998;
v_11999:
    goto v_12000;
v_12001:
    v_12008 = times2(v_12009, v_12008);
    env = stack[-3];
    stack[-2] = v_12008;
    v_12008 = stack[0];
    v_12008 = add1(v_12008);
    env = stack[-3];
    stack[0] = v_12008;
    goto v_11981;
v_11980:
    v_12008 = stack[-2];
    goto v_11953;
    v_12008 = nil;
v_11953:
    return onevalue(v_12008);
}



// Code for expand!-imrepart

static LispObject CC_expandKimrepart(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_12022, v_12023;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_11950;
// end of prologue
    stack[-2] = nil;
v_11956:
    v_12022 = stack[-1];
    if (!consp(v_12022)) goto v_11965;
    else goto v_11966;
v_11965:
    v_12022 = lisp_true;
    goto v_11964;
v_11966:
    v_12022 = stack[-1];
    v_12022 = qcar(v_12022);
    v_12022 = (consp(v_12022) ? nil : lisp_true);
    goto v_11964;
    v_12022 = nil;
v_11964:
    if (v_12022 == nil) goto v_11962;
    goto v_11957;
v_11962:
    goto v_11979;
v_11975:
    goto v_11985;
v_11981:
    v_12022 = stack[-1];
    v_12022 = qcar(v_12022);
    v_12022 = qcar(v_12022);
    fn = elt(env, 1); // expand!-imrepartpow
    stack[0] = (*qfn1(fn))(fn, v_12022);
    env = stack[-3];
    goto v_11982;
v_11983:
    v_12022 = stack[-1];
    v_12022 = qcar(v_12022);
    v_12022 = qcdr(v_12022);
    v_12022 = CC_expandKimrepart(elt(env, 0), v_12022);
    env = stack[-3];
    goto v_11984;
v_11985:
    goto v_11981;
v_11982:
    goto v_11983;
v_11984:
    fn = elt(env, 2); // multsq
    v_12023 = (*qfn2(fn))(fn, stack[0], v_12022);
    env = stack[-3];
    goto v_11976;
v_11977:
    v_12022 = stack[-2];
    goto v_11978;
v_11979:
    goto v_11975;
v_11976:
    goto v_11977;
v_11978:
    v_12022 = cons(v_12023, v_12022);
    env = stack[-3];
    stack[-2] = v_12022;
    v_12022 = stack[-1];
    v_12022 = qcdr(v_12022);
    stack[-1] = v_12022;
    goto v_11956;
v_11957:
    goto v_12002;
v_11998:
    v_12023 = stack[-1];
    goto v_11999;
v_12000:
    v_12022 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12001;
v_12002:
    goto v_11998;
v_11999:
    goto v_12000;
v_12001:
    v_12022 = cons(v_12023, v_12022);
    env = stack[-3];
    v_12023 = v_12022;
v_11958:
    v_12022 = stack[-2];
    if (v_12022 == nil) goto v_12007;
    else goto v_12008;
v_12007:
    v_12022 = v_12023;
    goto v_11955;
v_12008:
    goto v_12016;
v_12012:
    v_12022 = stack[-2];
    v_12022 = qcar(v_12022);
    goto v_12013;
v_12014:
    goto v_12015;
v_12016:
    goto v_12012;
v_12013:
    goto v_12014;
v_12015:
    fn = elt(env, 3); // addsq
    v_12022 = (*qfn2(fn))(fn, v_12022, v_12023);
    env = stack[-3];
    v_12023 = v_12022;
    v_12022 = stack[-2];
    v_12022 = qcdr(v_12022);
    stack[-2] = v_12022;
    goto v_11958;
v_11955:
    return onevalue(v_12022);
}



// Code for rootrnd

static LispObject CC_rootrnd(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_11960, v_11961;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11960 = v_11950;
// end of prologue
    goto v_11957;
v_11953:
    v_11961 = v_11960;
    goto v_11954;
v_11955:
    v_11960 = qvalue(elt(env, 1)); // acc!#
    goto v_11956;
v_11957:
    goto v_11953;
v_11954:
    goto v_11955;
v_11956:
    {
        fn = elt(env, 2); // rtrnda
        return (*qfn2(fn))(fn, v_11961, v_11960);
    }
}



// Code for mkcr

static LispObject CC_mkcr(LispObject env,
                         LispObject v_11950, LispObject v_11951)
{
    env = qenv(env);
    LispObject v_11966;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11950,v_11951);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_11951;
    v_11966 = v_11950;
// end of prologue
    goto v_11960;
v_11954:
    stack[-2] = elt(env, 1); // !:cr!:
    goto v_11955;
v_11956:
    fn = elt(env, 2); // striptag
    stack[0] = (*qfn1(fn))(fn, v_11966);
    env = stack[-3];
    goto v_11957;
v_11958:
    v_11966 = stack[-1];
    fn = elt(env, 2); // striptag
    v_11966 = (*qfn1(fn))(fn, v_11966);
    goto v_11959;
v_11960:
    goto v_11954;
v_11955:
    goto v_11956;
v_11957:
    goto v_11958;
v_11959:
    {
        LispObject v_11970 = stack[-2];
        LispObject v_11971 = stack[0];
        return list2star(v_11970, v_11971, v_11966);
    }
}



// Code for cde_delete

static LispObject CC_cde_delete(LispObject env,
                         LispObject v_11950, LispObject v_11951)
{
    env = qenv(env);
    LispObject v_11993, v_11994, v_11995, v_11996;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11950,v_11951);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_11993 = v_11951;
    stack[0] = v_11950;
// end of prologue
    v_11996 = nil;
    stack[-1] = v_11993;
v_11959:
    v_11993 = stack[-1];
    if (v_11993 == nil) goto v_11963;
    else goto v_11964;
v_11963:
    goto v_11958;
v_11964:
    v_11993 = stack[-1];
    v_11993 = qcar(v_11993);
    v_11995 = v_11993;
    goto v_11978;
v_11974:
    v_11994 = v_11995;
    goto v_11975;
v_11976:
    v_11993 = stack[0];
    goto v_11977;
v_11978:
    goto v_11974;
v_11975:
    goto v_11976;
v_11977:
    if (equal(v_11994, v_11993)) goto v_11973;
    goto v_11986;
v_11982:
    v_11993 = v_11995;
    goto v_11983;
v_11984:
    v_11994 = v_11996;
    goto v_11985;
v_11986:
    goto v_11982;
v_11983:
    goto v_11984;
v_11985:
    v_11993 = cons(v_11993, v_11994);
    env = stack[-2];
    v_11996 = v_11993;
    goto v_11971;
v_11973:
v_11971:
    v_11993 = stack[-1];
    v_11993 = qcdr(v_11993);
    stack[-1] = v_11993;
    goto v_11959;
v_11958:
    v_11993 = v_11996;
        return Lnreverse(nil, v_11993);
    return onevalue(v_11993);
}



// Code for lalr_prin_rhs

static LispObject CC_lalr_prin_rhs(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_11981, v_11982;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_11982 = v_11950;
// end of prologue
    v_11981 = v_11982;
    if (v_11981 == nil) goto v_11954;
    else goto v_11955;
v_11954:
    v_11981 = elt(env, 1); // "<empty>"
        return Lprinc(nil, v_11981);
v_11955:
    v_11981 = v_11982;
    stack[0] = v_11981;
v_11964:
    v_11981 = stack[0];
    if (v_11981 == nil) goto v_11968;
    else goto v_11969;
v_11968:
    v_11981 = nil;
    goto v_11963;
v_11969:
    v_11981 = stack[0];
    v_11981 = qcar(v_11981);
    fn = elt(env, 3); // lalr_prin_symbol
    v_11981 = (*qfn1(fn))(fn, v_11981);
    env = stack[-1];
    v_11981 = elt(env, 2); // " "
    v_11981 = Lprinc(nil, v_11981);
    env = stack[-1];
    v_11981 = stack[0];
    v_11981 = qcdr(v_11981);
    stack[0] = v_11981;
    goto v_11964;
v_11963:
    goto v_11953;
    v_11981 = nil;
v_11953:
    return onevalue(v_11981);
}



// Code for dfprint

static LispObject CC_dfprint(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_11997, v_11998;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11950;
// end of prologue
    v_11997 = qvalue(elt(env, 1)); // dfprint!*
    if (v_11997 == nil) goto v_11955;
    goto v_11962;
v_11958:
    stack[-1] = qvalue(elt(env, 1)); // dfprint!*
    goto v_11959;
v_11960:
    v_11997 = stack[0];
    v_11997 = ncons(v_11997);
    env = stack[-2];
    goto v_11961;
v_11962:
    goto v_11958;
v_11959:
    goto v_11960;
v_11961:
    {
        LispObject v_12001 = stack[-1];
        fn = elt(env, 4); // lispapply
        return (*qfn2(fn))(fn, v_12001, v_11997);
    }
v_11955:
    v_11997 = qvalue(elt(env, 2)); // cmsg!*
    if (v_11997 == nil) goto v_11967;
    v_11997 = nil;
    goto v_11953;
v_11967:
    goto v_11977;
v_11973:
    v_11998 = stack[0];
    goto v_11974;
v_11975:
    v_11997 = elt(env, 3); // progn
    goto v_11976;
v_11977:
    goto v_11973;
v_11974:
    goto v_11975;
v_11976:
    if (!consp(v_11998)) goto v_11970;
    v_11998 = qcar(v_11998);
    if (v_11998 == v_11997) goto v_11971;
v_11970:
    v_11997 = stack[0];
    {
        fn = elt(env, 5); // prettyprint
        return (*qfn1(fn))(fn, v_11997);
    }
v_11971:
v_11986:
    v_11997 = stack[0];
    v_11997 = qcdr(v_11997);
    stack[0] = v_11997;
    if (v_11997 == nil) goto v_11989;
    else goto v_11990;
v_11989:
    v_11997 = nil;
    goto v_11985;
v_11990:
    v_11997 = stack[0];
    v_11997 = qcar(v_11997);
    v_11997 = CC_dfprint(elt(env, 0), v_11997);
    env = stack[-2];
    goto v_11986;
v_11985:
    goto v_11953;
    v_11997 = nil;
v_11953:
    return onevalue(v_11997);
}



// Code for sfto_sqfpartf

static LispObject CC_sfto_sqfpartf(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_12015, v_12016;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_11950;
// end of prologue
    v_12015 = stack[-3];
    if (!consp(v_12015)) goto v_11962;
    else goto v_11963;
v_11962:
    v_12015 = lisp_true;
    goto v_11961;
v_11963:
    v_12015 = stack[-3];
    v_12015 = qcar(v_12015);
    v_12015 = (consp(v_12015) ? nil : lisp_true);
    goto v_11961;
    v_12015 = nil;
v_11961:
    if (v_12015 == nil) goto v_11959;
    v_12015 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11955;
v_11959:
    v_12015 = stack[-3];
    fn = elt(env, 1); // sfto_ucontentf
    v_12015 = (*qfn1(fn))(fn, v_12015);
    env = stack[-5];
    stack[0] = v_12015;
    goto v_11979;
v_11975:
    v_12016 = stack[-3];
    goto v_11976;
v_11977:
    v_12015 = stack[0];
    goto v_11978;
v_11979:
    goto v_11975;
v_11976:
    goto v_11977;
v_11978:
    fn = elt(env, 2); // quotf
    v_12015 = (*qfn2(fn))(fn, v_12016, v_12015);
    env = stack[-5];
    stack[-4] = v_12015;
    goto v_11987;
v_11983:
    v_12015 = stack[0];
    stack[-2] = CC_sfto_sqfpartf(elt(env, 0), v_12015);
    env = stack[-5];
    goto v_11984;
v_11985:
    goto v_11995;
v_11991:
    stack[-1] = stack[-4];
    goto v_11992;
v_11993:
    goto v_12002;
v_11998:
    stack[0] = stack[-4];
    goto v_11999;
v_12000:
    goto v_12009;
v_12005:
    v_12016 = stack[-4];
    goto v_12006;
v_12007:
    v_12015 = stack[-3];
    v_12015 = qcar(v_12015);
    v_12015 = qcar(v_12015);
    v_12015 = qcar(v_12015);
    goto v_12008;
v_12009:
    goto v_12005;
v_12006:
    goto v_12007;
v_12008:
    fn = elt(env, 3); // diff
    v_12015 = (*qfn2(fn))(fn, v_12016, v_12015);
    env = stack[-5];
    goto v_12001;
v_12002:
    goto v_11998;
v_11999:
    goto v_12000;
v_12001:
    fn = elt(env, 4); // sfto_gcdf!*
    v_12015 = (*qfn2(fn))(fn, stack[0], v_12015);
    env = stack[-5];
    goto v_11994;
v_11995:
    goto v_11991;
v_11992:
    goto v_11993;
v_11994:
    fn = elt(env, 2); // quotf
    v_12015 = (*qfn2(fn))(fn, stack[-1], v_12015);
    env = stack[-5];
    goto v_11986;
v_11987:
    goto v_11983;
v_11984:
    goto v_11985;
v_11986:
    {
        LispObject v_12022 = stack[-2];
        fn = elt(env, 5); // multf
        return (*qfn2(fn))(fn, v_12022, v_12015);
    }
v_11955:
    return onevalue(v_12015);
}



// Code for cl_atl

static LispObject CC_cl_atl(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_11961, v_11962;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_11961 = v_11950;
// end of prologue
    goto v_11957;
v_11953:
    fn = elt(env, 2); // cl_atl1
    v_11962 = (*qfn1(fn))(fn, v_11961);
    env = stack[0];
    goto v_11954;
v_11955:
    v_11961 = elt(env, 1); // rl_ordatp
    goto v_11956;
v_11957:
    goto v_11953;
v_11954:
    goto v_11955;
v_11956:
    {
        fn = elt(env, 3); // sort
        return (*qfn2(fn))(fn, v_11962, v_11961);
    }
}



// Code for sq2sstm

static LispObject CC_sq2sstm(LispObject env,
                         LispObject v_11950, LispObject v_11951)
{
    env = qenv(env);
    LispObject v_12059, v_12060, v_12061;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11950,v_11951);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_11951;
    v_12061 = v_11950;
// end of prologue
    goto v_11966;
v_11962:
    v_12059 = v_12061;
    v_12059 = qcar(v_12059);
    v_12060 = qcar(v_12059);
    goto v_11963;
v_11964:
    v_12059 = stack[-2];
    v_12059 = qcar(v_12059);
    v_12059 = qcar(v_12059);
    goto v_11965;
v_11966:
    goto v_11962;
v_11963:
    goto v_11964;
v_11965:
    if (equal(v_12060, v_12059)) goto v_11960;
    else goto v_11961;
v_11960:
    v_12059 = v_12061;
    v_12059 = qcdr(v_12059);
    stack[0] = v_12059;
    v_12059 = v_12061;
    v_12059 = qcar(v_12059);
    v_12059 = qcdr(v_12059);
    stack[-3] = v_12059;
    v_12059 = stack[0];
    if (!consp(v_12059)) goto v_11984;
    else goto v_11985;
v_11984:
    v_12059 = lisp_true;
    goto v_11983;
v_11985:
    v_12059 = stack[0];
    v_12059 = qcar(v_12059);
    v_12059 = (consp(v_12059) ? nil : lisp_true);
    goto v_11983;
    v_12059 = nil;
v_11983:
    if (v_12059 == nil) goto v_11981;
    goto v_12001;
v_11995:
    stack[-1] = stack[-3];
    goto v_11996;
v_11997:
    v_12059 = stack[-2];
    v_12059 = qcdr(v_12059);
    fn = elt(env, 1); // mkzl
    v_12060 = (*qfn1(fn))(fn, v_12059);
    env = stack[-4];
    goto v_11998;
v_11999:
    v_12059 = stack[0];
    goto v_12000;
v_12001:
    goto v_11995;
v_11996:
    goto v_11997;
v_11998:
    goto v_11999;
v_12000:
    v_12059 = acons(stack[-1], v_12060, v_12059);
    return ncons(v_12059);
v_11981:
    goto v_12014;
v_12010:
    stack[-1] = stack[0];
    goto v_12011;
v_12012:
    goto v_12021;
v_12017:
    v_12059 = stack[-2];
    v_12059 = qcar(v_12059);
    stack[0] = qcdr(v_12059);
    goto v_12018;
v_12019:
    v_12059 = stack[-2];
    v_12059 = qcdr(v_12059);
    v_12059 = sub1(v_12059);
    env = stack[-4];
    goto v_12020;
v_12021:
    goto v_12017;
v_12018:
    goto v_12019;
v_12020:
    v_12059 = cons(stack[0], v_12059);
    env = stack[-4];
    goto v_12013;
v_12014:
    goto v_12010;
v_12011:
    goto v_12012;
v_12013:
    fn = elt(env, 2); // sq2sscfpl
    v_12059 = (*qfn2(fn))(fn, stack[-1], v_12059);
    env = stack[-4];
    goto v_11979;
v_11979:
    goto v_11959;
v_11961:
    goto v_12035;
v_12031:
    v_12059 = v_12061;
    stack[-1] = ncons(v_12059);
    env = stack[-4];
    goto v_12032;
v_12033:
    goto v_12043;
v_12039:
    v_12059 = stack[-2];
    v_12059 = qcar(v_12059);
    stack[0] = qcdr(v_12059);
    goto v_12040;
v_12041:
    v_12059 = stack[-2];
    v_12059 = qcdr(v_12059);
    v_12059 = sub1(v_12059);
    env = stack[-4];
    goto v_12042;
v_12043:
    goto v_12039;
v_12040:
    goto v_12041;
v_12042:
    v_12059 = cons(stack[0], v_12059);
    env = stack[-4];
    goto v_12034;
v_12035:
    goto v_12031;
v_12032:
    goto v_12033;
v_12034:
    fn = elt(env, 2); // sq2sscfpl
    v_12059 = (*qfn2(fn))(fn, stack[-1], v_12059);
    env = stack[-4];
    v_12060 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_12060;
    goto v_11959;
v_11959:
    goto v_12056;
v_12052:
    v_12060 = stack[-3];
    goto v_12053;
v_12054:
    goto v_12055;
v_12056:
    goto v_12052;
v_12053:
    goto v_12054;
v_12055:
    {
        fn = elt(env, 3); // mapins
        return (*qfn2(fn))(fn, v_12060, v_12059);
    }
    return onevalue(v_12059);
}



// Code for diff!-over!-k!-mod!-p

static LispObject CC_diffKoverKkKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12125, v_12126, v_12127;
    LispObject fn;
    LispObject v_11952, v_11951, v_11950;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "diff-over-k-mod-p");
    va_start(aa, nargs);
    v_11950 = va_arg(aa, LispObject);
    v_11951 = va_arg(aa, LispObject);
    v_11952 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_11952,v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_11950,v_11951,v_11952);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_11952;
    stack[-1] = v_11951;
    stack[-2] = v_11950;
// end of prologue
    v_12125 = stack[-2];
    if (!consp(v_12125)) goto v_11960;
    else goto v_11961;
v_11960:
    v_12125 = lisp_true;
    goto v_11959;
v_11961:
    v_12125 = stack[-2];
    v_12125 = qcar(v_12125);
    v_12125 = (consp(v_12125) ? nil : lisp_true);
    goto v_11959;
    v_12125 = nil;
v_11959:
    if (v_12125 == nil) goto v_11957;
    v_12125 = nil;
    goto v_11955;
v_11957:
    goto v_11976;
v_11972:
    v_12125 = stack[-2];
    v_12125 = qcar(v_12125);
    v_12125 = qcar(v_12125);
    v_12126 = qcar(v_12125);
    goto v_11973;
v_11974:
    v_12125 = stack[0];
    goto v_11975;
v_11976:
    goto v_11972;
v_11973:
    goto v_11974;
v_11975:
    if (equal(v_12126, v_12125)) goto v_11970;
    else goto v_11971;
v_11970:
    goto v_11990;
v_11986:
    v_12125 = stack[-2];
    v_12125 = qcar(v_12125);
    v_12125 = qcar(v_12125);
    v_12126 = qcdr(v_12125);
    goto v_11987;
v_11988:
    v_12125 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11989;
v_11990:
    goto v_11986;
v_11987:
    goto v_11988;
v_11989:
    if (v_12126 == v_12125) goto v_11984;
    else goto v_11985;
v_11984:
    goto v_12001;
v_11997:
    v_12125 = stack[-2];
    v_12125 = qcar(v_12125);
    v_12126 = qcdr(v_12125);
    goto v_11998;
v_11999:
    v_12125 = stack[-1];
    v_12125 = Lmodular_number(nil, v_12125);
    env = stack[-4];
    goto v_12000;
v_12001:
    goto v_11997;
v_11998:
    goto v_11999;
v_12000:
    {
        fn = elt(env, 1); // quotfail!-mod!-p
        return (*qfn2(fn))(fn, v_12126, v_12125);
    }
v_11985:
    goto v_12014;
v_12010:
    goto v_12020;
v_12016:
    v_12125 = stack[-2];
    v_12125 = qcar(v_12125);
    v_12125 = qcar(v_12125);
    v_12125 = qcdr(v_12125);
    v_12126 = Lmodular_number(nil, v_12125);
    env = stack[-4];
    goto v_12017;
v_12018:
    v_12125 = stack[-2];
    v_12125 = qcar(v_12125);
    v_12125 = qcdr(v_12125);
    goto v_12019;
v_12020:
    goto v_12016;
v_12017:
    goto v_12018;
v_12019:
    fn = elt(env, 2); // times!-mod!-p
    v_12126 = (*qfn2(fn))(fn, v_12126, v_12125);
    env = stack[-4];
    goto v_12011;
v_12012:
    v_12125 = stack[-1];
    v_12125 = Lmodular_number(nil, v_12125);
    env = stack[-4];
    goto v_12013;
v_12014:
    goto v_12010;
v_12011:
    goto v_12012;
v_12013:
    fn = elt(env, 1); // quotfail!-mod!-p
    stack[-3] = (*qfn2(fn))(fn, v_12126, v_12125);
    env = stack[-4];
    goto v_12038;
v_12032:
    v_12125 = stack[-2];
    v_12127 = qcdr(v_12125);
    goto v_12033;
v_12034:
    v_12126 = stack[-1];
    goto v_12035;
v_12036:
    v_12125 = stack[0];
    goto v_12037;
v_12038:
    goto v_12032;
v_12033:
    goto v_12034;
v_12035:
    goto v_12036;
v_12037:
    v_12125 = CC_diffKoverKkKmodKp(elt(env, 0), 3, v_12127, v_12126, v_12125);
    env = stack[-4];
    stack[-1] = v_12125;
    v_12125 = stack[-3];
    if (v_12125 == nil) goto v_12047;
    else goto v_12048;
v_12047:
    v_12125 = stack[-1];
    goto v_12046;
v_12048:
    goto v_12060;
v_12054:
    goto v_12066;
v_12062:
    v_12126 = stack[0];
    goto v_12063;
v_12064:
    v_12125 = stack[-2];
    v_12125 = qcar(v_12125);
    v_12125 = qcar(v_12125);
    v_12125 = qcdr(v_12125);
    v_12125 = (LispObject)((intptr_t)(v_12125) - 0x10);
    goto v_12065;
v_12066:
    goto v_12062;
v_12063:
    goto v_12064;
v_12065:
    fn = elt(env, 3); // mksp
    v_12127 = (*qfn2(fn))(fn, v_12126, v_12125);
    goto v_12055;
v_12056:
    v_12126 = stack[-3];
    goto v_12057;
v_12058:
    v_12125 = stack[-1];
    goto v_12059;
v_12060:
    goto v_12054;
v_12055:
    goto v_12056;
v_12057:
    goto v_12058;
v_12059:
    return acons(v_12127, v_12126, v_12125);
    v_12125 = nil;
v_12046:
    goto v_11983;
    v_12125 = nil;
v_11983:
    goto v_11955;
v_11971:
    goto v_12084;
v_12078:
    v_12125 = stack[-2];
    v_12125 = qcar(v_12125);
    v_12127 = qcdr(v_12125);
    goto v_12079;
v_12080:
    v_12126 = stack[-1];
    goto v_12081;
v_12082:
    v_12125 = stack[0];
    goto v_12083;
v_12084:
    goto v_12078;
v_12079:
    goto v_12080;
v_12081:
    goto v_12082;
v_12083:
    stack[-3] = CC_diffKoverKkKmodKp(elt(env, 0), 3, v_12127, v_12126, v_12125);
    env = stack[-4];
    goto v_12097;
v_12091:
    v_12125 = stack[-2];
    v_12127 = qcdr(v_12125);
    goto v_12092;
v_12093:
    v_12126 = stack[-1];
    goto v_12094;
v_12095:
    v_12125 = stack[0];
    goto v_12096;
v_12097:
    goto v_12091;
v_12092:
    goto v_12093;
v_12094:
    goto v_12095;
v_12096:
    v_12125 = CC_diffKoverKkKmodKp(elt(env, 0), 3, v_12127, v_12126, v_12125);
    v_12126 = stack[-3];
    v_12127 = v_12126;
    if (v_12127 == nil) goto v_12106;
    else goto v_12107;
v_12106:
    goto v_12105;
v_12107:
    goto v_12119;
v_12113:
    v_12127 = stack[-2];
    v_12127 = qcar(v_12127);
    v_12127 = qcar(v_12127);
    goto v_12114;
v_12115:
    goto v_12116;
v_12117:
    goto v_12118;
v_12119:
    goto v_12113;
v_12114:
    goto v_12115;
v_12116:
    goto v_12117;
v_12118:
    return acons(v_12127, v_12126, v_12125);
    v_12125 = nil;
v_12105:
    goto v_11955;
    v_12125 = nil;
v_11955:
    return onevalue(v_12125);
}



// Code for dipevlcomp

static LispObject CC_dipevlcomp(LispObject env,
                         LispObject v_11950, LispObject v_11951)
{
    env = qenv(env);
    LispObject v_11964, v_11965;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11950,v_11951);
    }
// copy arguments values to proper place
    v_11964 = v_11951;
    v_11965 = v_11950;
// end of prologue
    goto v_11958;
v_11954:
    v_11965 = qcar(v_11965);
    goto v_11955;
v_11956:
    v_11964 = qcar(v_11964);
    goto v_11957;
v_11958:
    goto v_11954;
v_11955:
    goto v_11956;
v_11957:
    fn = elt(env, 1); // evcompless!?
    v_11964 = (*qfn2(fn))(fn, v_11965, v_11964);
    v_11964 = (v_11964 == nil ? lisp_true : nil);
    return onevalue(v_11964);
}



// Code for coposp

static LispObject CC_coposp(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_11975, v_11976;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11976 = v_11950;
// end of prologue
    v_11975 = v_11976;
    v_11975 = qcdr(v_11975);
    if (v_11975 == nil) goto v_11954;
    else goto v_11955;
v_11954:
    v_11975 = lisp_true;
    goto v_11953;
v_11955:
    v_11975 = v_11976;
    v_11975 = qcar(v_11975);
    if (!consp(v_11975)) goto v_11963;
    else goto v_11964;
v_11963:
    v_11975 = v_11976;
    v_11975 = qcdr(v_11975);
    {
        fn = elt(env, 1); // contposp
        return (*qfn1(fn))(fn, v_11975);
    }
v_11964:
    v_11975 = v_11976;
    v_11975 = qcdr(v_11975);
    {
        fn = elt(env, 2); // covposp
        return (*qfn1(fn))(fn, v_11975);
    }
    v_11975 = nil;
    goto v_11953;
    v_11975 = nil;
v_11953:
    return onevalue(v_11975);
}



// Code for assert_format

static LispObject CC_assert_format(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12103, v_12104, v_12105;
    LispObject v_11952, v_11951, v_11950;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "assert_format");
    va_start(aa, nargs);
    v_11950 = va_arg(aa, LispObject);
    v_11951 = va_arg(aa, LispObject);
    v_11952 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_11952,v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_11950,v_11951,v_11952);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    v_12103 = v_11952;
    stack[-8] = v_11951;
    stack[-9] = v_11950;
// end of prologue
    v_12103 = Lexplode(nil, v_12103);
    env = stack[-11];
    stack[-10] = v_12103;
    goto v_11966;
v_11960:
    stack[-7] = elt(env, 1); // !!
    goto v_11961;
v_11962:
    stack[-6] = elt(env, 2); // !)
    goto v_11963;
v_11964:
    goto v_11976;
v_11970:
    stack[-5] = elt(env, 1); // !!
    goto v_11971;
v_11972:
    stack[-4] = elt(env, 3); // ! 
    goto v_11973;
v_11974:
    goto v_11986;
v_11980:
    stack[-3] = elt(env, 1); // !!
    goto v_11981;
v_11982:
    stack[-2] = elt(env, 4); // !-
    goto v_11983;
v_11984:
    goto v_11996;
v_11990:
    stack[-1] = elt(env, 1); // !!
    goto v_11991;
v_11992:
    stack[0] = elt(env, 5); // !>
    goto v_11993;
v_11994:
    goto v_12006;
v_12000:
    v_12105 = elt(env, 1); // !!
    goto v_12001;
v_12002:
    v_12104 = elt(env, 3); // ! 
    goto v_12003;
v_12004:
    v_12103 = stack[-10];
    goto v_12005;
v_12006:
    goto v_12000;
v_12001:
    goto v_12002;
v_12003:
    goto v_12004;
v_12005:
    v_12103 = list2star(v_12105, v_12104, v_12103);
    env = stack[-11];
    goto v_11995;
v_11996:
    goto v_11990;
v_11991:
    goto v_11992;
v_11993:
    goto v_11994;
v_11995:
    v_12103 = list2star(stack[-1], stack[0], v_12103);
    env = stack[-11];
    goto v_11985;
v_11986:
    goto v_11980;
v_11981:
    goto v_11982;
v_11983:
    goto v_11984;
v_11985:
    v_12103 = list2star(stack[-3], stack[-2], v_12103);
    env = stack[-11];
    goto v_11975;
v_11976:
    goto v_11970;
v_11971:
    goto v_11972;
v_11973:
    goto v_11974;
v_11975:
    v_12103 = list2star(stack[-5], stack[-4], v_12103);
    env = stack[-11];
    goto v_11965;
v_11966:
    goto v_11960;
v_11961:
    goto v_11962;
v_11963:
    goto v_11964;
v_11965:
    v_12103 = list2star(stack[-7], stack[-6], v_12103);
    env = stack[-11];
    stack[-10] = v_12103;
    v_12103 = stack[-8];
    v_12103 = Lreverse(nil, v_12103);
    env = stack[-11];
    stack[-4] = v_12103;
v_12013:
    v_12103 = stack[-4];
    if (v_12103 == nil) goto v_12018;
    else goto v_12019;
v_12018:
    goto v_12012;
v_12019:
    v_12103 = stack[-4];
    v_12103 = qcar(v_12103);
    goto v_12032;
v_12026:
    stack[-3] = elt(env, 1); // !!
    goto v_12027;
v_12028:
    stack[-2] = elt(env, 6); // !,
    goto v_12029;
v_12030:
    goto v_12042;
v_12036:
    stack[-1] = elt(env, 1); // !!
    goto v_12037;
v_12038:
    stack[0] = elt(env, 3); // ! 
    goto v_12039;
v_12040:
    goto v_12050;
v_12046:
    v_12104 = Lexplode(nil, v_12103);
    env = stack[-11];
    goto v_12047;
v_12048:
    v_12103 = stack[-10];
    goto v_12049;
v_12050:
    goto v_12046;
v_12047:
    goto v_12048;
v_12049:
    v_12103 = Lnconc(nil, v_12104, v_12103);
    env = stack[-11];
    goto v_12041;
v_12042:
    goto v_12036;
v_12037:
    goto v_12038;
v_12039:
    goto v_12040;
v_12041:
    v_12103 = list2star(stack[-1], stack[0], v_12103);
    env = stack[-11];
    goto v_12031;
v_12032:
    goto v_12026;
v_12027:
    goto v_12028;
v_12029:
    goto v_12030;
v_12031:
    v_12103 = list2star(stack[-3], stack[-2], v_12103);
    env = stack[-11];
    stack[-10] = v_12103;
    v_12103 = stack[-4];
    v_12103 = qcdr(v_12103);
    stack[-4] = v_12103;
    goto v_12013;
v_12012:
    v_12103 = stack[-10];
    v_12103 = qcdr(v_12103);
    v_12103 = qcdr(v_12103);
    v_12103 = qcdr(v_12103);
    v_12103 = qcdr(v_12103);
    stack[-10] = v_12103;
    goto v_12068;
v_12062:
    stack[-3] = elt(env, 1); // !!
    goto v_12063;
v_12064:
    stack[-2] = elt(env, 7); // !:
    goto v_12065;
v_12066:
    goto v_12078;
v_12072:
    stack[-1] = elt(env, 1); // !!
    goto v_12073;
v_12074:
    stack[0] = elt(env, 3); // ! 
    goto v_12075;
v_12076:
    goto v_12088;
v_12082:
    v_12105 = elt(env, 1); // !!
    goto v_12083;
v_12084:
    v_12104 = elt(env, 8); // !(
    goto v_12085;
v_12086:
    v_12103 = stack[-10];
    goto v_12087;
v_12088:
    goto v_12082;
v_12083:
    goto v_12084;
v_12085:
    goto v_12086;
v_12087:
    v_12103 = list2star(v_12105, v_12104, v_12103);
    env = stack[-11];
    goto v_12077;
v_12078:
    goto v_12072;
v_12073:
    goto v_12074;
v_12075:
    goto v_12076;
v_12077:
    v_12103 = list2star(stack[-1], stack[0], v_12103);
    env = stack[-11];
    goto v_12067;
v_12068:
    goto v_12062;
v_12063:
    goto v_12064;
v_12065:
    goto v_12066;
v_12067:
    v_12103 = list2star(stack[-3], stack[-2], v_12103);
    env = stack[-11];
    stack[-10] = v_12103;
    goto v_12097;
v_12093:
    v_12103 = stack[-9];
    v_12104 = Lexplode(nil, v_12103);
    env = stack[-11];
    goto v_12094;
v_12095:
    v_12103 = stack[-10];
    goto v_12096;
v_12097:
    goto v_12093;
v_12094:
    goto v_12095;
v_12096:
    v_12103 = Lnconc(nil, v_12104, v_12103);
    stack[-10] = v_12103;
    v_12103 = stack[-10];
        return Lcompress(nil, v_12103);
    return onevalue(v_12103);
}



// Code for mv!-domainlist

static LispObject CC_mvKdomainlist(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_11977, v_11978;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_11950;
// end of prologue
    v_11978 = nil;
v_11955:
    v_11977 = stack[0];
    if (v_11977 == nil) goto v_11958;
    else goto v_11959;
v_11958:
    v_11977 = v_11978;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_11977);
    }
v_11959:
    goto v_11970;
v_11966:
    v_11977 = stack[0];
    v_11977 = qcar(v_11977);
    v_11977 = qcdr(v_11977);
    goto v_11967;
v_11968:
    goto v_11969;
v_11970:
    goto v_11966;
v_11967:
    goto v_11968;
v_11969:
    v_11977 = cons(v_11977, v_11978);
    env = stack[-1];
    v_11978 = v_11977;
    v_11977 = stack[0];
    v_11977 = qcdr(v_11977);
    stack[0] = v_11977;
    goto v_11955;
    v_11977 = nil;
    return onevalue(v_11977);
}



// Code for rnprep!:

static LispObject CC_rnprepT(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_11987, v_11988, v_11989;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_11950;
// end of prologue
    v_11987 = stack[-1];
    v_11987 = qcdr(v_11987);
    v_11987 = qcar(v_11987);
    fn = elt(env, 2); // prepf
    v_11987 = (*qfn1(fn))(fn, v_11987);
    env = stack[-3];
    v_11989 = v_11987;
    goto v_11965;
v_11961:
    v_11987 = stack[-1];
    v_11987 = qcdr(v_11987);
    v_11988 = qcdr(v_11987);
    goto v_11962;
v_11963:
    v_11987 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11964;
v_11965:
    goto v_11961;
v_11962:
    goto v_11963;
v_11964:
    if (v_11988 == v_11987) goto v_11959;
    else goto v_11960;
v_11959:
    v_11987 = v_11989;
    goto v_11958;
v_11960:
    goto v_11980;
v_11974:
    stack[-2] = elt(env, 1); // quotient
    goto v_11975;
v_11976:
    stack[0] = v_11989;
    goto v_11977;
v_11978:
    v_11987 = stack[-1];
    v_11987 = qcdr(v_11987);
    v_11987 = qcdr(v_11987);
    fn = elt(env, 2); // prepf
    v_11987 = (*qfn1(fn))(fn, v_11987);
    goto v_11979;
v_11980:
    goto v_11974;
v_11975:
    goto v_11976;
v_11977:
    goto v_11978;
v_11979:
    {
        LispObject v_11993 = stack[-2];
        LispObject v_11994 = stack[0];
        return list3(v_11993, v_11994, v_11987);
    }
    v_11987 = nil;
v_11958:
    return onevalue(v_11987);
}



// Code for quotfail!-in!-vector

static LispObject CC_quotfailKinKvector(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12227, v_12228, v_12229, v_12230, v_12231, v_12232, v_12233, v_12234;
    LispObject fn;
    LispObject v_11953, v_11952, v_11951, v_11950;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "quotfail-in-vector");
    va_start(aa, nargs);
    v_11950 = va_arg(aa, LispObject);
    v_11951 = va_arg(aa, LispObject);
    v_11952 = va_arg(aa, LispObject);
    v_11953 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_11953,v_11952,v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_11950,v_11951,v_11952,v_11953);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_11953;
    stack[-2] = v_11952;
    v_12229 = v_11951;
    stack[-3] = v_11950;
// end of prologue
    goto v_11963;
v_11959:
    v_12228 = v_12229;
    goto v_11960;
v_11961:
    v_12227 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11962;
v_11963:
    goto v_11959;
v_11960:
    goto v_11961;
v_11962:
    if (((intptr_t)(v_12228)) < ((intptr_t)(v_12227))) goto v_11957;
    else goto v_11958;
v_11957:
    v_12227 = v_12229;
    goto v_11956;
v_11958:
    goto v_11973;
v_11969:
    v_12228 = stack[-1];
    goto v_11970;
v_11971:
    v_12227 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11972;
v_11973:
    goto v_11969;
v_11970:
    goto v_11971;
v_11972:
    if (((intptr_t)(v_12228)) < ((intptr_t)(v_12227))) goto v_11967;
    else goto v_11968;
v_11967:
    v_12227 = elt(env, 1); // "Attempt to divide by zero"
    {
        fn = elt(env, 4); // errorf
        return (*qfn1(fn))(fn, v_12227);
    }
v_11968:
    goto v_11984;
v_11980:
    v_12228 = v_12229;
    goto v_11981;
v_11982:
    v_12227 = stack[-1];
    goto v_11983;
v_11984:
    goto v_11980;
v_11981:
    goto v_11982;
v_11983:
    if (((intptr_t)(v_12228)) < ((intptr_t)(v_12227))) goto v_11978;
    else goto v_11979;
v_11978:
    v_12227 = elt(env, 2); // "Bad degrees in quotfail-in-vector"
    {
        fn = elt(env, 4); // errorf
        return (*qfn1(fn))(fn, v_12227);
    }
v_11979:
    goto v_11998;
v_11994:
    v_12228 = v_12229;
    goto v_11995;
v_11996:
    v_12227 = stack[-1];
    goto v_11997;
v_11998:
    goto v_11994;
v_11995:
    goto v_11996;
v_11997:
    v_12227 = (LispObject)(intptr_t)((intptr_t)v_12228 - (intptr_t)v_12227 + TAG_FIXNUM);
    stack[-4] = v_12227;
    v_12227 = stack[-4];
    stack[0] = v_12227;
v_12005:
    v_12227 = stack[0];
    v_12227 = ((intptr_t)(v_12227) < 0 ? lisp_true : nil);
    if (v_12227 == nil) goto v_12010;
    goto v_12004;
v_12010:
    goto v_12022;
v_12018:
    goto v_12027;
v_12023:
    v_12229 = stack[-3];
    goto v_12024;
v_12025:
    goto v_12033;
v_12029:
    v_12228 = stack[-1];
    goto v_12030;
v_12031:
    v_12227 = stack[0];
    goto v_12032;
v_12033:
    goto v_12029;
v_12030:
    goto v_12031;
v_12032:
    v_12227 = (LispObject)(intptr_t)((intptr_t)v_12228 + (intptr_t)v_12227 - TAG_FIXNUM);
    goto v_12026;
v_12027:
    goto v_12023;
v_12024:
    goto v_12025;
v_12026:
    v_12229 = *(LispObject *)((char *)v_12229 + (CELL-TAG_VECTOR) + (((intptr_t)v_12227-TAG_FIXNUM)/(16/CELL)));
    goto v_12019;
v_12020:
    goto v_12042;
v_12038:
    v_12228 = stack[-2];
    goto v_12039;
v_12040:
    v_12227 = stack[-1];
    goto v_12041;
v_12042:
    goto v_12038;
v_12039:
    goto v_12040;
v_12041:
    v_12227 = *(LispObject *)((char *)v_12228 + (CELL-TAG_VECTOR) + (((intptr_t)v_12227-TAG_FIXNUM)/(16/CELL)));
    goto v_12021;
v_12022:
    goto v_12018;
v_12019:
    goto v_12020;
v_12021:
    v_12227 = Lmodular_quotient(nil, v_12229, v_12227);
    env = stack[-5];
    v_12234 = v_12227;
    v_12227 = (LispObject)0+TAG_FIXNUM; // 0
    v_12233 = v_12227;
v_12049:
    goto v_12059;
v_12055:
    v_12227 = stack[-1];
    v_12228 = (LispObject)((intptr_t)(v_12227) - 0x10);
    goto v_12056;
v_12057:
    v_12227 = v_12233;
    goto v_12058;
v_12059:
    goto v_12055;
v_12056:
    goto v_12057;
v_12058:
    v_12227 = (LispObject)(intptr_t)((intptr_t)v_12228 - (intptr_t)v_12227 + TAG_FIXNUM);
    v_12227 = ((intptr_t)(v_12227) < 0 ? lisp_true : nil);
    if (v_12227 == nil) goto v_12054;
    goto v_12048;
v_12054:
    goto v_12072;
v_12066:
    v_12232 = stack[-3];
    goto v_12067;
v_12068:
    goto v_12078;
v_12074:
    v_12228 = stack[0];
    goto v_12075;
v_12076:
    v_12227 = v_12233;
    goto v_12077;
v_12078:
    goto v_12074;
v_12075:
    goto v_12076;
v_12077:
    v_12231 = (LispObject)(intptr_t)((intptr_t)v_12228 + (intptr_t)v_12227 - TAG_FIXNUM);
    goto v_12069;
v_12070:
    goto v_12086;
v_12082:
    goto v_12091;
v_12087:
    v_12229 = stack[-3];
    goto v_12088;
v_12089:
    goto v_12097;
v_12093:
    v_12228 = stack[0];
    goto v_12094;
v_12095:
    v_12227 = v_12233;
    goto v_12096;
v_12097:
    goto v_12093;
v_12094:
    goto v_12095;
v_12096:
    v_12227 = (LispObject)(intptr_t)((intptr_t)v_12228 + (intptr_t)v_12227 - TAG_FIXNUM);
    goto v_12090;
v_12091:
    goto v_12087;
v_12088:
    goto v_12089;
v_12090:
    v_12230 = *(LispObject *)((char *)v_12229 + (CELL-TAG_VECTOR) + (((intptr_t)v_12227-TAG_FIXNUM)/(16/CELL)));
    goto v_12083;
v_12084:
    goto v_12107;
v_12103:
    v_12229 = v_12234;
    goto v_12104;
v_12105:
    goto v_12113;
v_12109:
    v_12228 = stack[-2];
    goto v_12110;
v_12111:
    v_12227 = v_12233;
    goto v_12112;
v_12113:
    goto v_12109;
v_12110:
    goto v_12111;
v_12112:
    v_12227 = *(LispObject *)((char *)v_12228 + (CELL-TAG_VECTOR) + (((intptr_t)v_12227-TAG_FIXNUM)/(16/CELL)));
    goto v_12106;
v_12107:
    goto v_12103;
v_12104:
    goto v_12105;
v_12106:
    v_12227 = Lmodular_times(nil, v_12229, v_12227);
    env = stack[-5];
    goto v_12085;
v_12086:
    goto v_12082;
v_12083:
    goto v_12084;
v_12085:
    {   intptr_t w = int_of_fixnum(v_12230) - int_of_fixnum(v_12227);
        if (w < 0) w += current_modulus;
        v_12227 = fixnum_of_int(w);
    }
    goto v_12071;
v_12072:
    goto v_12066;
v_12067:
    goto v_12068;
v_12069:
    goto v_12070;
v_12071:
    *(LispObject *)((char *)v_12232 + (CELL-TAG_VECTOR) + (((intptr_t)v_12231-TAG_FIXNUM)/(16/CELL))) = v_12227;
    v_12227 = v_12233;
    v_12227 = (LispObject)((intptr_t)(v_12227) + 0x10);
    v_12233 = v_12227;
    goto v_12049;
v_12048:
    goto v_12126;
v_12120:
    v_12229 = stack[-3];
    goto v_12121;
v_12122:
    goto v_12132;
v_12128:
    v_12228 = stack[-1];
    goto v_12129;
v_12130:
    v_12227 = stack[0];
    goto v_12131;
v_12132:
    goto v_12128;
v_12129:
    goto v_12130;
v_12131:
    v_12227 = (LispObject)(intptr_t)((intptr_t)v_12228 + (intptr_t)v_12227 - TAG_FIXNUM);
    goto v_12123;
v_12124:
    v_12228 = v_12234;
    goto v_12125;
v_12126:
    goto v_12120;
v_12121:
    goto v_12122;
v_12123:
    goto v_12124;
v_12125:
    *(LispObject *)((char *)v_12229 + (CELL-TAG_VECTOR) + (((intptr_t)v_12227-TAG_FIXNUM)/(16/CELL))) = v_12228;
    v_12227 = stack[0];
    v_12227 = (LispObject)((intptr_t)(v_12227) - 0x10);
    stack[0] = v_12227;
    goto v_12005;
v_12004:
    v_12227 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_12227;
v_12142:
    goto v_12152;
v_12148:
    v_12227 = stack[-1];
    v_12228 = (LispObject)((intptr_t)(v_12227) - 0x10);
    goto v_12149;
v_12150:
    v_12227 = stack[0];
    goto v_12151;
v_12152:
    goto v_12148;
v_12149:
    goto v_12150;
v_12151:
    v_12227 = (LispObject)(intptr_t)((intptr_t)v_12228 - (intptr_t)v_12227 + TAG_FIXNUM);
    v_12227 = ((intptr_t)(v_12227) < 0 ? lisp_true : nil);
    if (v_12227 == nil) goto v_12147;
    goto v_12141;
v_12147:
    goto v_12167;
v_12163:
    goto v_12172;
v_12168:
    v_12228 = stack[-3];
    goto v_12169;
v_12170:
    v_12227 = stack[0];
    goto v_12171;
v_12172:
    goto v_12168;
v_12169:
    goto v_12170;
v_12171:
    v_12228 = *(LispObject *)((char *)v_12228 + (CELL-TAG_VECTOR) + (((intptr_t)v_12227-TAG_FIXNUM)/(16/CELL)));
    goto v_12164;
v_12165:
    v_12227 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12166;
v_12167:
    goto v_12163;
v_12164:
    goto v_12165;
v_12166:
    if (v_12228 == v_12227) goto v_12162;
    v_12227 = elt(env, 3); // "Quotient not exact in quotfail!-in!-vector"
    fn = elt(env, 4); // errorf
    v_12227 = (*qfn1(fn))(fn, v_12227);
    env = stack[-5];
    goto v_12160;
v_12162:
v_12160:
    v_12227 = stack[0];
    v_12227 = (LispObject)((intptr_t)(v_12227) + 0x10);
    stack[0] = v_12227;
    goto v_12142;
v_12141:
    v_12227 = (LispObject)0+TAG_FIXNUM; // 0
    v_12232 = v_12227;
v_12184:
    goto v_12194;
v_12190:
    v_12228 = stack[-4];
    goto v_12191;
v_12192:
    v_12227 = v_12232;
    goto v_12193;
v_12194:
    goto v_12190;
v_12191:
    goto v_12192;
v_12193:
    v_12227 = (LispObject)(intptr_t)((intptr_t)v_12228 - (intptr_t)v_12227 + TAG_FIXNUM);
    v_12227 = ((intptr_t)(v_12227) < 0 ? lisp_true : nil);
    if (v_12227 == nil) goto v_12189;
    goto v_12183;
v_12189:
    goto v_12206;
v_12200:
    v_12231 = stack[-3];
    goto v_12201;
v_12202:
    v_12230 = v_12232;
    goto v_12203;
v_12204:
    goto v_12213;
v_12209:
    v_12229 = stack[-3];
    goto v_12210;
v_12211:
    goto v_12219;
v_12215:
    v_12228 = stack[-1];
    goto v_12216;
v_12217:
    v_12227 = v_12232;
    goto v_12218;
v_12219:
    goto v_12215;
v_12216:
    goto v_12217;
v_12218:
    v_12227 = (LispObject)(intptr_t)((intptr_t)v_12228 + (intptr_t)v_12227 - TAG_FIXNUM);
    goto v_12212;
v_12213:
    goto v_12209;
v_12210:
    goto v_12211;
v_12212:
    v_12227 = *(LispObject *)((char *)v_12229 + (CELL-TAG_VECTOR) + (((intptr_t)v_12227-TAG_FIXNUM)/(16/CELL)));
    goto v_12205;
v_12206:
    goto v_12200;
v_12201:
    goto v_12202;
v_12203:
    goto v_12204;
v_12205:
    *(LispObject *)((char *)v_12231 + (CELL-TAG_VECTOR) + (((intptr_t)v_12230-TAG_FIXNUM)/(16/CELL))) = v_12227;
    v_12227 = v_12232;
    v_12227 = (LispObject)((intptr_t)(v_12227) + 0x10);
    v_12232 = v_12227;
    goto v_12184;
v_12183:
    v_12227 = stack[-4];
    goto v_11956;
    v_12227 = nil;
v_11956:
    return onevalue(v_12227);
}



// Code for lalr_precalculate_first_sets

static LispObject CC_lalr_precalculate_first_sets(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12137, v_12138, v_12139;
    LispObject fn;
    argcheck(nargs, 0, "lalr_precalculate_first_sets");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// end of prologue
    stack[-3] = nil;
v_11959:
    v_12137 = nil;
    stack[-6] = v_12137;
    v_12137 = qvalue(elt(env, 1)); // nonterminals
    stack[-2] = v_12137;
v_11964:
    v_12137 = stack[-2];
    if (v_12137 == nil) goto v_11968;
    else goto v_11969;
v_11968:
    goto v_11963;
v_11969:
    v_12137 = stack[-2];
    v_12137 = qcar(v_12137);
    stack[-1] = v_12137;
    goto v_11980;
v_11976:
    v_12138 = stack[-1];
    goto v_11977;
v_11978:
    v_12137 = elt(env, 2); // lalr_first
    goto v_11979;
v_11980:
    goto v_11976;
v_11977:
    goto v_11978;
v_11979:
    v_12137 = get(v_12138, v_12137);
    env = stack[-7];
    stack[-5] = v_12137;
    v_12137 = stack[-1];
    fn = elt(env, 4); // lalr_productions
    v_12137 = (*qfn1(fn))(fn, v_12137);
    env = stack[-7];
    stack[0] = v_12137;
v_11986:
    v_12137 = stack[0];
    if (v_12137 == nil) goto v_11991;
    else goto v_11992;
v_11991:
    goto v_11985;
v_11992:
    v_12137 = stack[0];
    v_12137 = qcar(v_12137);
    v_12137 = qcar(v_12137);
    stack[-4] = v_12137;
v_12002:
    v_12137 = stack[-4];
    if (v_12137 == nil) goto v_12005;
    v_12137 = stack[-4];
    v_12137 = qcar(v_12137);
    if (is_number(v_12137)) goto v_12013;
    goto v_12020;
v_12016:
    v_12139 = nil;
    goto v_12017;
v_12018:
    goto v_12027;
v_12023:
    v_12137 = stack[-4];
    v_12138 = qcar(v_12137);
    goto v_12024;
v_12025:
    v_12137 = elt(env, 2); // lalr_first
    goto v_12026;
v_12027:
    goto v_12023;
v_12024:
    goto v_12025;
v_12026:
    v_12137 = get(v_12138, v_12137);
    env = stack[-7];
    stack[-3] = v_12137;
    goto v_12019;
v_12020:
    goto v_12016;
v_12017:
    goto v_12018;
v_12019:
    v_12137 = Lmember(nil, v_12139, v_12137);
    goto v_12011;
v_12013:
    v_12137 = nil;
    goto v_12011;
    v_12137 = nil;
v_12011:
    if (v_12137 == nil) goto v_12005;
    goto v_12006;
v_12005:
    goto v_12001;
v_12006:
    goto v_12041;
v_12037:
    goto v_12047;
v_12043:
    v_12138 = nil;
    goto v_12044;
v_12045:
    v_12137 = stack[-3];
    goto v_12046;
v_12047:
    goto v_12043;
v_12044:
    goto v_12045;
v_12046:
    v_12138 = Ldeleq(nil, v_12138, v_12137);
    env = stack[-7];
    goto v_12038;
v_12039:
    v_12137 = stack[-5];
    goto v_12040;
v_12041:
    goto v_12037;
v_12038:
    goto v_12039;
v_12040:
    fn = elt(env, 5); // union
    v_12137 = (*qfn2(fn))(fn, v_12138, v_12137);
    env = stack[-7];
    stack[-5] = v_12137;
    v_12137 = stack[-4];
    v_12137 = qcdr(v_12137);
    stack[-4] = v_12137;
    goto v_12002;
v_12001:
    v_12137 = stack[-4];
    if (v_12137 == nil) goto v_12055;
    else goto v_12056;
v_12055:
    goto v_12063;
v_12059:
    v_12138 = elt(env, 3); // (nil)
    goto v_12060;
v_12061:
    v_12137 = stack[-5];
    goto v_12062;
v_12063:
    goto v_12059;
v_12060:
    goto v_12061;
v_12062:
    fn = elt(env, 5); // union
    v_12137 = (*qfn2(fn))(fn, v_12138, v_12137);
    env = stack[-7];
    stack[-5] = v_12137;
    goto v_12054;
v_12056:
    v_12137 = stack[-4];
    v_12137 = qcar(v_12137);
    if (is_number(v_12137)) goto v_12066;
    else goto v_12067;
v_12066:
    goto v_12075;
v_12071:
    v_12137 = stack[-4];
    v_12137 = qcar(v_12137);
    v_12138 = ncons(v_12137);
    env = stack[-7];
    goto v_12072;
v_12073:
    v_12137 = stack[-5];
    goto v_12074;
v_12075:
    goto v_12071;
v_12072:
    goto v_12073;
v_12074:
    fn = elt(env, 5); // union
    v_12137 = (*qfn2(fn))(fn, v_12138, v_12137);
    env = stack[-7];
    stack[-5] = v_12137;
    goto v_12054;
v_12067:
    goto v_12087;
v_12083:
    goto v_12093;
v_12089:
    v_12137 = stack[-4];
    v_12138 = qcar(v_12137);
    goto v_12090;
v_12091:
    v_12137 = elt(env, 2); // lalr_first
    goto v_12092;
v_12093:
    goto v_12089;
v_12090:
    goto v_12091;
v_12092:
    v_12138 = get(v_12138, v_12137);
    env = stack[-7];
    goto v_12084;
v_12085:
    v_12137 = stack[-5];
    goto v_12086;
v_12087:
    goto v_12083;
v_12084:
    goto v_12085;
v_12086:
    fn = elt(env, 5); // union
    v_12137 = (*qfn2(fn))(fn, v_12138, v_12137);
    env = stack[-7];
    stack[-5] = v_12137;
    goto v_12054;
v_12054:
    v_12137 = stack[0];
    v_12137 = qcdr(v_12137);
    stack[0] = v_12137;
    goto v_11986;
v_11985:
    goto v_12108;
v_12104:
    v_12139 = stack[-5];
    goto v_12105;
v_12106:
    goto v_12115;
v_12111:
    v_12138 = stack[-1];
    goto v_12112;
v_12113:
    v_12137 = elt(env, 2); // lalr_first
    goto v_12114;
v_12115:
    goto v_12111;
v_12112:
    goto v_12113;
v_12114:
    v_12137 = get(v_12138, v_12137);
    env = stack[-7];
    goto v_12107;
v_12108:
    goto v_12104;
v_12105:
    goto v_12106;
v_12107:
    if (equal(v_12139, v_12137)) goto v_12103;
    v_12137 = lisp_true;
    stack[-6] = v_12137;
    goto v_12126;
v_12120:
    v_12139 = stack[-1];
    goto v_12121;
v_12122:
    v_12138 = elt(env, 2); // lalr_first
    goto v_12123;
v_12124:
    v_12137 = stack[-5];
    goto v_12125;
v_12126:
    goto v_12120;
v_12121:
    goto v_12122;
v_12123:
    goto v_12124;
v_12125:
    v_12137 = Lputprop(nil, 3, v_12139, v_12138, v_12137);
    env = stack[-7];
    goto v_12101;
v_12103:
v_12101:
    v_12137 = stack[-2];
    v_12137 = qcdr(v_12137);
    stack[-2] = v_12137;
    goto v_11964;
v_11963:
    v_12137 = stack[-6];
    if (v_12137 == nil) goto v_12135;
    goto v_11959;
v_12135:
    v_12137 = nil;
    return onevalue(v_12137);
}



// Code for readprogn

static LispObject CC_readprogn(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11990, v_11991;
    LispObject fn;
    argcheck(nargs, 0, "readprogn");
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
    v_11990 = elt(env, 1); // group
    fn = elt(env, 5); // xread
    v_11990 = (*qfn1(fn))(fn, v_11990);
    env = stack[-1];
    v_11990 = ncons(v_11990);
    env = stack[-1];
    stack[0] = v_11990;
v_11959:
    goto v_11968;
v_11964:
    v_11991 = qvalue(elt(env, 2)); // cursym!*
    goto v_11965;
v_11966:
    v_11990 = elt(env, 3); // !*rsqbkt!*
    goto v_11967;
v_11968:
    goto v_11964;
v_11965:
    goto v_11966;
v_11967:
    if (v_11991 == v_11990) goto v_11962;
    else goto v_11963;
v_11962:
    goto v_11958;
v_11963:
    goto v_11977;
v_11973:
    goto v_11974;
v_11975:
    v_11990 = elt(env, 1); // group
    fn = elt(env, 5); // xread
    v_11990 = (*qfn1(fn))(fn, v_11990);
    env = stack[-1];
    goto v_11976;
v_11977:
    goto v_11973;
v_11974:
    goto v_11975;
v_11976:
    fn = elt(env, 6); // aconc!*
    v_11990 = (*qfn2(fn))(fn, stack[0], v_11990);
    env = stack[-1];
    stack[0] = v_11990;
    goto v_11959;
v_11958:
    fn = elt(env, 7); // scan
    v_11990 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_11987;
v_11983:
    v_11991 = elt(env, 4); // progn
    goto v_11984;
v_11985:
    v_11990 = stack[0];
    goto v_11986;
v_11987:
    goto v_11983;
v_11984:
    goto v_11985;
v_11986:
    return cons(v_11991, v_11990);
    return onevalue(v_11990);
}



// Code for ofsf_smwmkatl

static LispObject CC_ofsf_smwmkatl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11990, v_11991, v_11992, v_11993, v_11994;
    LispObject fn;
    LispObject v_11953, v_11952, v_11951, v_11950;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ofsf_smwmkatl");
    va_start(aa, nargs);
    v_11950 = va_arg(aa, LispObject);
    v_11951 = va_arg(aa, LispObject);
    v_11952 = va_arg(aa, LispObject);
    v_11953 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11991 = v_11953;
    v_11992 = v_11952;
    v_11993 = v_11951;
    v_11994 = v_11950;
// end of prologue
    v_11990 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_11990 == nil) goto v_11958;
    goto v_11969;
v_11961:
    v_11990 = v_11994;
    goto v_11962;
v_11963:
    goto v_11964;
v_11965:
    goto v_11966;
v_11967:
    goto v_11968;
v_11969:
    goto v_11961;
v_11962:
    goto v_11963;
v_11964:
    goto v_11965;
v_11966:
    goto v_11967;
v_11968:
    {
        fn = elt(env, 2); // cl_susimkatl
        return (*qfnn(fn))(fn, 4, v_11990, v_11993, v_11992, v_11991);
    }
v_11958:
    goto v_11985;
v_11977:
    v_11990 = v_11994;
    goto v_11978;
v_11979:
    goto v_11980;
v_11981:
    goto v_11982;
v_11983:
    goto v_11984;
v_11985:
    goto v_11977;
v_11978:
    goto v_11979;
v_11980:
    goto v_11981;
v_11982:
    goto v_11983;
v_11984:
    {
        fn = elt(env, 3); // ofsf_smmkatl
        return (*qfnn(fn))(fn, 4, v_11990, v_11993, v_11992, v_11991);
    }
    v_11990 = nil;
    return onevalue(v_11990);
}



// Code for vintersection

static LispObject CC_vintersection(LispObject env,
                         LispObject v_11950, LispObject v_11951)
{
    env = qenv(env);
    LispObject v_12074, v_12075;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11950,v_11951);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11951;
    stack[-1] = v_11950;
// end of prologue
v_11949:
    v_12074 = stack[-1];
    if (v_12074 == nil) goto v_11958;
    else goto v_11959;
v_11958:
    v_12074 = nil;
    goto v_11957;
v_11959:
    goto v_11968;
v_11964:
    v_12074 = stack[-1];
    v_12074 = qcar(v_12074);
    v_12075 = qcar(v_12074);
    goto v_11965;
v_11966:
    v_12074 = stack[0];
    goto v_11967;
v_11968:
    goto v_11964;
v_11965:
    goto v_11966;
v_11967:
    v_12074 = Lassoc(nil, v_12075, v_12074);
    stack[-2] = v_12074;
    if (v_12074 == nil) goto v_11962;
    else goto v_11963;
v_11962:
    goto v_11979;
v_11975:
    v_12074 = stack[-1];
    v_12075 = qcdr(v_12074);
    goto v_11976;
v_11977:
    v_12074 = stack[0];
    goto v_11978;
v_11979:
    goto v_11975;
v_11976:
    goto v_11977;
v_11978:
    stack[-1] = v_12075;
    stack[0] = v_12074;
    goto v_11949;
v_11963:
    goto v_11990;
v_11986:
    v_12074 = stack[-1];
    v_12074 = qcar(v_12074);
    v_12075 = qcdr(v_12074);
    goto v_11987;
v_11988:
    v_12074 = stack[-2];
    v_12074 = qcdr(v_12074);
    goto v_11989;
v_11990:
    goto v_11986;
v_11987:
    goto v_11988;
v_11989:
    v_12074 = (LispObject)greaterp2(v_12075, v_12074);
    v_12074 = v_12074 ? lisp_true : nil;
    env = stack[-3];
    if (v_12074 == nil) goto v_11984;
    goto v_12004;
v_12000:
    v_12074 = stack[-2];
    v_12075 = qcdr(v_12074);
    goto v_12001;
v_12002:
    v_12074 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12003;
v_12004:
    goto v_12000;
v_12001:
    goto v_12002;
v_12003:
    if (v_12075 == v_12074) goto v_11998;
    else goto v_11999;
v_11998:
    goto v_12013;
v_12009:
    v_12074 = stack[-1];
    v_12075 = qcdr(v_12074);
    goto v_12010;
v_12011:
    v_12074 = stack[0];
    goto v_12012;
v_12013:
    goto v_12009;
v_12010:
    goto v_12011;
v_12012:
    stack[-1] = v_12075;
    stack[0] = v_12074;
    goto v_11949;
v_11999:
    goto v_12024;
v_12020:
    goto v_12021;
v_12022:
    goto v_12031;
v_12027:
    v_12074 = stack[-1];
    v_12075 = qcdr(v_12074);
    goto v_12028;
v_12029:
    v_12074 = stack[0];
    goto v_12030;
v_12031:
    goto v_12027;
v_12028:
    goto v_12029;
v_12030:
    v_12074 = CC_vintersection(elt(env, 0), v_12075, v_12074);
    goto v_12023;
v_12024:
    goto v_12020;
v_12021:
    goto v_12022;
v_12023:
    {
        LispObject v_12079 = stack[-2];
        return cons(v_12079, v_12074);
    }
    v_12074 = nil;
    goto v_11957;
v_11984:
    goto v_12041;
v_12037:
    v_12074 = stack[-1];
    v_12074 = qcar(v_12074);
    v_12075 = qcdr(v_12074);
    goto v_12038;
v_12039:
    v_12074 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12040;
v_12041:
    goto v_12037;
v_12038:
    goto v_12039;
v_12040:
    if (v_12075 == v_12074) goto v_12035;
    else goto v_12036;
v_12035:
    goto v_12051;
v_12047:
    v_12074 = stack[-1];
    v_12075 = qcdr(v_12074);
    goto v_12048;
v_12049:
    v_12074 = stack[0];
    goto v_12050;
v_12051:
    goto v_12047;
v_12048:
    goto v_12049;
v_12050:
    stack[-1] = v_12075;
    stack[0] = v_12074;
    goto v_11949;
v_12036:
    goto v_12062;
v_12058:
    v_12074 = stack[-1];
    stack[-2] = qcar(v_12074);
    goto v_12059;
v_12060:
    goto v_12070;
v_12066:
    v_12074 = stack[-1];
    v_12075 = qcdr(v_12074);
    goto v_12067;
v_12068:
    v_12074 = stack[0];
    goto v_12069;
v_12070:
    goto v_12066;
v_12067:
    goto v_12068;
v_12069:
    v_12074 = CC_vintersection(elt(env, 0), v_12075, v_12074);
    goto v_12061;
v_12062:
    goto v_12058;
v_12059:
    goto v_12060;
v_12061:
    {
        LispObject v_12080 = stack[-2];
        return cons(v_12080, v_12074);
    }
    v_12074 = nil;
v_11957:
    return onevalue(v_12074);
}



// Code for ibalp_var!-wclist

static LispObject CC_ibalp_varKwclist(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_12139, v_12140;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_11950;
// end of prologue
    stack[-3] = nil;
    v_12139 = stack[-4];
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcar(v_12139);
    stack[-2] = v_12139;
v_11959:
    v_12139 = stack[-2];
    if (v_12139 == nil) goto v_11974;
    else goto v_11975;
v_11974:
    goto v_11958;
v_11975:
    v_12139 = stack[-2];
    v_12139 = qcar(v_12139);
    stack[-1] = v_12139;
    v_12139 = stack[-1];
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcar(v_12139);
    if (v_12139 == nil) goto v_11983;
    else goto v_11984;
v_11983:
    goto v_11996;
v_11992:
    v_12139 = stack[-1];
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    stack[0] = qcdr(v_12139);
    goto v_11993;
v_11994:
    goto v_12009;
v_12005:
    v_12140 = stack[-4];
    goto v_12006;
v_12007:
    v_12139 = stack[-1];
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcar(v_12139);
    goto v_12008;
v_12009:
    goto v_12005;
v_12006:
    goto v_12007;
v_12008:
    fn = elt(env, 1); // delq
    v_12139 = (*qfn2(fn))(fn, v_12140, v_12139);
    env = stack[-6];
    goto v_11995;
v_11996:
    goto v_11992;
v_11993:
    goto v_11994;
v_11995:
    fn = elt(env, 2); // setcar
    v_12139 = (*qfn2(fn))(fn, stack[0], v_12139);
    env = stack[-6];
    goto v_12024;
v_12020:
    v_12139 = stack[-4];
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    stack[0] = qcdr(v_12139);
    goto v_12021;
v_12022:
    goto v_12041;
v_12037:
    v_12140 = stack[-1];
    goto v_12038;
v_12039:
    v_12139 = stack[-4];
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcar(v_12139);
    goto v_12040;
v_12041:
    goto v_12037;
v_12038:
    goto v_12039;
v_12040:
    fn = elt(env, 1); // delq
    v_12139 = (*qfn2(fn))(fn, v_12140, v_12139);
    env = stack[-6];
    goto v_12023;
v_12024:
    goto v_12020;
v_12021:
    goto v_12022;
v_12023:
    fn = elt(env, 2); // setcar
    v_12139 = (*qfn2(fn))(fn, stack[0], v_12139);
    env = stack[-6];
    v_12139 = stack[-1];
    fn = elt(env, 3); // ibalp_getnewwl
    v_12139 = (*qfn1(fn))(fn, v_12139);
    env = stack[-6];
    stack[-5] = v_12139;
    v_12139 = stack[-5];
    if (v_12139 == nil) goto v_12059;
    else goto v_12060;
v_12059:
    goto v_12067;
v_12063:
    v_12140 = stack[-1];
    goto v_12064;
v_12065:
    v_12139 = stack[-3];
    goto v_12066;
v_12067:
    goto v_12063;
v_12064:
    goto v_12065;
v_12066:
    v_12139 = cons(v_12140, v_12139);
    env = stack[-6];
    stack[-3] = v_12139;
    goto v_12058;
v_12060:
    goto v_12077;
v_12073:
    v_12139 = stack[-1];
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    stack[0] = qcdr(v_12139);
    goto v_12074;
v_12075:
    goto v_12090;
v_12086:
    v_12140 = stack[-5];
    goto v_12087;
v_12088:
    v_12139 = stack[-1];
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcar(v_12139);
    goto v_12089;
v_12090:
    goto v_12086;
v_12087:
    goto v_12088;
v_12089:
    v_12139 = cons(v_12140, v_12139);
    env = stack[-6];
    goto v_12076;
v_12077:
    goto v_12073;
v_12074:
    goto v_12075;
v_12076:
    fn = elt(env, 2); // setcar
    v_12139 = (*qfn2(fn))(fn, stack[0], v_12139);
    env = stack[-6];
    goto v_12105;
v_12101:
    v_12139 = stack[-5];
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    stack[0] = qcdr(v_12139);
    goto v_12102;
v_12103:
    goto v_12122;
v_12118:
    v_12140 = stack[-1];
    goto v_12119;
v_12120:
    v_12139 = stack[-5];
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcdr(v_12139);
    v_12139 = qcar(v_12139);
    goto v_12121;
v_12122:
    goto v_12118;
v_12119:
    goto v_12120;
v_12121:
    v_12139 = cons(v_12140, v_12139);
    env = stack[-6];
    goto v_12104;
v_12105:
    goto v_12101;
v_12102:
    goto v_12103;
v_12104:
    fn = elt(env, 2); // setcar
    v_12139 = (*qfn2(fn))(fn, stack[0], v_12139);
    env = stack[-6];
    goto v_12058;
v_12058:
    goto v_11982;
v_11984:
v_11982:
    v_12139 = stack[-2];
    v_12139 = qcdr(v_12139);
    stack[-2] = v_12139;
    goto v_11959;
v_11958:
    v_12139 = stack[-3];
    return onevalue(v_12139);
}



// Code for quotofd

static LispObject CC_quotofd(LispObject env,
                         LispObject v_11950, LispObject v_11951)
{
    env = qenv(env);
    LispObject v_12018, v_12019;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11950,v_11951);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11951;
    stack[-2] = v_11950;
// end of prologue
    stack[-3] = nil;
v_11956:
    v_12018 = stack[-2];
    if (v_12018 == nil) goto v_11959;
    else goto v_11960;
v_11959:
    v_12018 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12018);
    }
v_11960:
    v_12018 = stack[-2];
    if (!consp(v_12018)) goto v_11968;
    else goto v_11969;
v_11968:
    v_12018 = lisp_true;
    goto v_11967;
v_11969:
    v_12018 = stack[-2];
    v_12018 = qcar(v_12018);
    v_12018 = (consp(v_12018) ? nil : lisp_true);
    goto v_11967;
    v_12018 = nil;
v_11967:
    if (v_12018 == nil) goto v_11965;
    goto v_11982;
v_11978:
    stack[0] = stack[-3];
    goto v_11979;
v_11980:
    goto v_11989;
v_11985:
    v_12019 = stack[-2];
    goto v_11986;
v_11987:
    v_12018 = stack[-1];
    goto v_11988;
v_11989:
    goto v_11985;
v_11986:
    goto v_11987;
v_11988:
    fn = elt(env, 2); // quotodd
    v_12018 = (*qfn2(fn))(fn, v_12019, v_12018);
    env = stack[-4];
    goto v_11981;
v_11982:
    goto v_11978;
v_11979:
    goto v_11980;
v_11981:
    {
        LispObject v_12024 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_12024, v_12018);
    }
v_11965:
    goto v_12001;
v_11995:
    v_12018 = stack[-2];
    v_12018 = qcar(v_12018);
    stack[0] = qcar(v_12018);
    goto v_11996;
v_11997:
    goto v_12010;
v_12006:
    v_12018 = stack[-2];
    v_12018 = qcar(v_12018);
    v_12019 = qcdr(v_12018);
    goto v_12007;
v_12008:
    v_12018 = stack[-1];
    goto v_12009;
v_12010:
    goto v_12006;
v_12007:
    goto v_12008;
v_12009:
    v_12019 = CC_quotofd(elt(env, 0), v_12019, v_12018);
    env = stack[-4];
    goto v_11998;
v_11999:
    v_12018 = stack[-3];
    goto v_12000;
v_12001:
    goto v_11995;
v_11996:
    goto v_11997;
v_11998:
    goto v_11999;
v_12000:
    v_12018 = acons(stack[0], v_12019, v_12018);
    env = stack[-4];
    stack[-3] = v_12018;
    v_12018 = stack[-2];
    v_12018 = qcdr(v_12018);
    stack[-2] = v_12018;
    goto v_11956;
    v_12018 = nil;
    return onevalue(v_12018);
}



// Code for dm!-gt

static LispObject CC_dmKgt(LispObject env,
                         LispObject v_11950, LispObject v_11951)
{
    env = qenv(env);
    LispObject v_11962, v_11963;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11950,v_11951);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_11963 = v_11951;
    v_11962 = v_11950;
// end of prologue
    goto v_11959;
v_11955:
    goto v_11956;
v_11957:
    goto v_11958;
v_11959:
    goto v_11955;
v_11956:
    goto v_11957;
v_11958:
    fn = elt(env, 1); // dm!-difference
    v_11962 = (*qfn2(fn))(fn, v_11963, v_11962);
    env = stack[0];
    {
        fn = elt(env, 2); // !:minusp
        return (*qfn1(fn))(fn, v_11962);
    }
}



// Code for dipcondense

static LispObject CC_dipcondense(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_12041, v_12042;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_11950;
// end of prologue
    v_12041 = qvalue(elt(env, 1)); // dipevlist!*
    stack[-3] = v_12041;
v_11959:
    v_12041 = stack[-2];
    if (v_12041 == nil) goto v_11962;
    else goto v_11963;
v_11962:
    goto v_11958;
v_11963:
    v_12041 = stack[-2];
    v_12041 = qcar(v_12041);
    stack[-1] = v_12041;
v_11970:
    v_12041 = stack[-3];
    v_12041 = qcdr(v_12041);
    if (v_12041 == nil) goto v_11973;
    goto v_11984;
v_11980:
    v_12041 = stack[-2];
    v_12042 = qcar(v_12041);
    goto v_11981;
v_11982:
    v_12041 = stack[-3];
    v_12041 = qcdr(v_12041);
    v_12041 = qcar(v_12041);
    goto v_11983;
v_11984:
    goto v_11980;
v_11981:
    goto v_11982;
v_11983:
    fn = elt(env, 2); // evcompless!?
    v_12041 = (*qfn2(fn))(fn, v_12042, v_12041);
    env = stack[-4];
    if (v_12041 == nil) goto v_11973;
    goto v_11974;
v_11973:
    goto v_11969;
v_11974:
    v_12041 = stack[-3];
    v_12041 = qcdr(v_12041);
    stack[-3] = v_12041;
    goto v_11970;
v_11969:
    v_12041 = stack[-3];
    v_12041 = qcdr(v_12041);
    if (v_12041 == nil) goto v_11996;
    goto v_12005;
v_12001:
    v_12042 = stack[-1];
    goto v_12002;
v_12003:
    v_12041 = stack[-3];
    v_12041 = qcdr(v_12041);
    v_12041 = qcar(v_12041);
    goto v_12004;
v_12005:
    goto v_12001;
v_12002:
    goto v_12003;
v_12004:
    if (equal(v_12042, v_12041)) goto v_12000;
    else goto v_11996;
v_12000:
    goto v_12015;
v_12011:
    v_12042 = stack[-2];
    goto v_12012;
v_12013:
    v_12041 = stack[-3];
    v_12041 = qcdr(v_12041);
    v_12041 = qcar(v_12041);
    goto v_12014;
v_12015:
    goto v_12011;
v_12012:
    goto v_12013;
v_12014:
    fn = elt(env, 3); // setcar
    v_12041 = (*qfn2(fn))(fn, v_12042, v_12041);
    env = stack[-4];
    goto v_11994;
v_11996:
    goto v_12027;
v_12023:
    stack[0] = stack[-3];
    goto v_12024;
v_12025:
    goto v_12034;
v_12030:
    v_12042 = stack[-1];
    goto v_12031;
v_12032:
    v_12041 = stack[-3];
    v_12041 = qcdr(v_12041);
    goto v_12033;
v_12034:
    goto v_12030;
v_12031:
    goto v_12032;
v_12033:
    v_12041 = cons(v_12042, v_12041);
    env = stack[-4];
    goto v_12026;
v_12027:
    goto v_12023;
v_12024:
    goto v_12025;
v_12026:
    fn = elt(env, 4); // setcdr
    v_12041 = (*qfn2(fn))(fn, stack[0], v_12041);
    env = stack[-4];
    goto v_11994;
v_11994:
    v_12041 = stack[-2];
    v_12041 = qcdr(v_12041);
    v_12041 = qcdr(v_12041);
    stack[-2] = v_12041;
    goto v_11959;
v_11958:
    v_12041 = nil;
    return onevalue(v_12041);
}



// Code for partitexdf

static LispObject CC_partitexdf(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_11956;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_11956 = v_11950;
// end of prologue
    v_11956 = qcar(v_11956);
    fn = elt(env, 1); // partitop
    v_11956 = (*qfn1(fn))(fn, v_11956);
    env = stack[0];
    {
        fn = elt(env, 2); // exdfpf
        return (*qfn1(fn))(fn, v_11956);
    }
}



// Code for indord2

static LispObject CC_indord2(LispObject env,
                         LispObject v_11950, LispObject v_11951)
{
    env = qenv(env);
    LispObject v_11983, v_11984;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11950,v_11951);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_11951;
    stack[-1] = v_11950;
// end of prologue
    goto v_11962;
v_11958:
    v_11984 = stack[-1];
    goto v_11959;
v_11960:
    v_11983 = stack[0];
    goto v_11961;
v_11962:
    goto v_11958;
v_11959:
    goto v_11960;
v_11961:
    fn = elt(env, 1); // indordp
    v_11983 = (*qfn2(fn))(fn, v_11984, v_11983);
    if (v_11983 == nil) goto v_11956;
    goto v_11970;
v_11966:
    v_11984 = stack[-1];
    goto v_11967;
v_11968:
    v_11983 = stack[0];
    goto v_11969;
v_11970:
    goto v_11966;
v_11967:
    goto v_11968;
v_11969:
    return list2(v_11984, v_11983);
v_11956:
    goto v_11980;
v_11976:
    v_11984 = stack[0];
    goto v_11977;
v_11978:
    v_11983 = stack[-1];
    goto v_11979;
v_11980:
    goto v_11976;
v_11977:
    goto v_11978;
v_11979:
    return list2(v_11984, v_11983);
    v_11983 = nil;
    return onevalue(v_11983);
}



// Code for sf2mv1

static LispObject CC_sf2mv1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12063, v_12064, v_12065;
    LispObject fn;
    LispObject v_11952, v_11951, v_11950;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sf2mv1");
    va_start(aa, nargs);
    v_11950 = va_arg(aa, LispObject);
    v_11951 = va_arg(aa, LispObject);
    v_11952 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_11952,v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_11950,v_11951,v_11952);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_11952;
    stack[-2] = v_11951;
    stack[-3] = v_11950;
// end of prologue
v_11956:
    v_12063 = stack[-3];
    if (v_12063 == nil) goto v_11959;
    else goto v_11960;
v_11959:
    v_12063 = nil;
    goto v_11955;
v_11960:
    v_12063 = stack[-3];
    if (!consp(v_12063)) goto v_11967;
    else goto v_11968;
v_11967:
    v_12063 = lisp_true;
    goto v_11966;
v_11968:
    v_12063 = stack[-3];
    v_12063 = qcar(v_12063);
    v_12063 = (consp(v_12063) ? nil : lisp_true);
    goto v_11966;
    v_12063 = nil;
v_11966:
    if (v_12063 == nil) goto v_11964;
    goto v_11982;
v_11978:
    goto v_11988;
v_11984:
    stack[0] = stack[-2];
    goto v_11985;
v_11986:
    v_12063 = stack[-1];
    v_12063 = Llength(nil, v_12063);
    env = stack[-5];
    fn = elt(env, 1); // nzeros
    v_12063 = (*qfn1(fn))(fn, v_12063);
    env = stack[-5];
    goto v_11987;
v_11988:
    goto v_11984;
v_11985:
    goto v_11986;
v_11987:
    v_12064 = Lappend(nil, stack[0], v_12063);
    env = stack[-5];
    goto v_11979;
v_11980:
    v_12063 = stack[-3];
    goto v_11981;
v_11982:
    goto v_11978;
v_11979:
    goto v_11980;
v_11981:
    v_12063 = cons(v_12064, v_12063);
    return ncons(v_12063);
v_11964:
    goto v_12000;
v_11996:
    v_12063 = stack[-3];
    v_12063 = qcar(v_12063);
    v_12063 = qcar(v_12063);
    v_12064 = qcar(v_12063);
    goto v_11997;
v_11998:
    v_12063 = stack[-1];
    v_12063 = qcar(v_12063);
    goto v_11999;
v_12000:
    goto v_11996;
v_11997:
    goto v_11998;
v_11999:
    if (equal(v_12064, v_12063)) goto v_11994;
    else goto v_11995;
v_11994:
    goto v_12012;
v_12008:
    goto v_12020;
v_12014:
    v_12063 = stack[-3];
    v_12063 = qcar(v_12063);
    stack[-4] = qcdr(v_12063);
    goto v_12015;
v_12016:
    goto v_12029;
v_12025:
    stack[0] = stack[-2];
    goto v_12026;
v_12027:
    v_12063 = stack[-3];
    v_12063 = qcar(v_12063);
    v_12063 = qcar(v_12063);
    v_12063 = qcdr(v_12063);
    v_12063 = ncons(v_12063);
    env = stack[-5];
    goto v_12028;
v_12029:
    goto v_12025;
v_12026:
    goto v_12027;
v_12028:
    v_12064 = Lappend(nil, stack[0], v_12063);
    env = stack[-5];
    goto v_12017;
v_12018:
    v_12063 = stack[-1];
    v_12063 = qcdr(v_12063);
    goto v_12019;
v_12020:
    goto v_12014;
v_12015:
    goto v_12016;
v_12017:
    goto v_12018;
v_12019:
    stack[0] = CC_sf2mv1(elt(env, 0), 3, stack[-4], v_12064, v_12063);
    env = stack[-5];
    goto v_12009;
v_12010:
    goto v_12045;
v_12039:
    v_12063 = stack[-3];
    v_12065 = qcdr(v_12063);
    goto v_12040;
v_12041:
    v_12064 = stack[-2];
    goto v_12042;
v_12043:
    v_12063 = stack[-1];
    goto v_12044;
v_12045:
    goto v_12039;
v_12040:
    goto v_12041;
v_12042:
    goto v_12043;
v_12044:
    v_12063 = CC_sf2mv1(elt(env, 0), 3, v_12065, v_12064, v_12063);
    goto v_12011;
v_12012:
    goto v_12008;
v_12009:
    goto v_12010;
v_12011:
    {
        LispObject v_12071 = stack[0];
        return Lappend(nil, v_12071, v_12063);
    }
v_11995:
    goto v_12057;
v_12053:
    stack[0] = stack[-2];
    goto v_12054;
v_12055:
    v_12063 = (LispObject)0+TAG_FIXNUM; // 0
    v_12063 = ncons(v_12063);
    env = stack[-5];
    goto v_12056;
v_12057:
    goto v_12053;
v_12054:
    goto v_12055;
v_12056:
    v_12063 = Lappend(nil, stack[0], v_12063);
    env = stack[-5];
    stack[-2] = v_12063;
    v_12063 = stack[-1];
    v_12063 = qcdr(v_12063);
    stack[-1] = v_12063;
    goto v_11956;
    v_12063 = nil;
v_11955:
    return onevalue(v_12063);
}



// Code for !:rn2rd

static LispObject CC_Trn2rd(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_11965, v_11966;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11966 = v_11950;
// end of prologue
    v_11965 = qvalue(elt(env, 1)); // !*roundall
    if (v_11965 == nil) goto v_11955;
    v_11965 = qvalue(elt(env, 2)); // !*rounded
    if (v_11965 == nil) goto v_11955;
    v_11965 = v_11966;
    {
        fn = elt(env, 3); // !*rn2rd
        return (*qfn1(fn))(fn, v_11965);
    }
v_11955:
    v_11965 = v_11966;
    goto v_11953;
    v_11965 = nil;
v_11953:
    return onevalue(v_11965);
}



// Code for groeb!=weight

static LispObject CC_groebMweight(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11972;
    LispObject fn;
    LispObject v_11952, v_11951, v_11950;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "groeb=weight");
    va_start(aa, nargs);
    v_11950 = va_arg(aa, LispObject);
    v_11951 = va_arg(aa, LispObject);
    v_11952 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_11952,v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_11950,v_11951,v_11952);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11952;
    stack[-1] = v_11951;
    v_11972 = v_11950;
// end of prologue
    goto v_11959;
v_11955:
    fn = elt(env, 1); // mo_ecart
    stack[-2] = (*qfn1(fn))(fn, v_11972);
    env = stack[-3];
    goto v_11956;
v_11957:
    goto v_11967;
v_11963:
    v_11972 = stack[-1];
    fn = elt(env, 2); // bas_dpecart
    stack[-1] = (*qfn1(fn))(fn, v_11972);
    env = stack[-3];
    goto v_11964;
v_11965:
    v_11972 = stack[0];
    fn = elt(env, 2); // bas_dpecart
    v_11972 = (*qfn1(fn))(fn, v_11972);
    env = stack[-3];
    goto v_11966;
v_11967:
    goto v_11963;
v_11964:
    goto v_11965;
v_11966:
    v_11972 = Lmin2(nil, stack[-1], v_11972);
    goto v_11958;
v_11959:
    goto v_11955;
v_11956:
    goto v_11957;
v_11958:
    {
        LispObject v_11976 = stack[-2];
        return plus2(v_11976, v_11972);
    }
}



// Code for tensorp

static LispObject CC_tensorp(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_11969, v_11970;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11970 = v_11950;
// end of prologue
    v_11969 = v_11970;
    if (!consp(v_11969)) goto v_11955;
    goto v_11962;
v_11958:
    v_11969 = v_11970;
    v_11969 = qcar(v_11969);
    goto v_11959;
v_11960:
    v_11970 = elt(env, 1); // tensor
    goto v_11961;
v_11962:
    goto v_11958;
v_11959:
    goto v_11960;
v_11961:
        return Lflagp(nil, v_11969, v_11970);
v_11955:
    v_11969 = nil;
    goto v_11953;
    v_11969 = nil;
v_11953:
    return onevalue(v_11969);
}



// Code for reducepowers

static LispObject CC_reducepowers(LispObject env,
                         LispObject v_11950)
{
    env = qenv(env);
    LispObject v_12082, v_12083;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11950);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11950;
// end of prologue
v_11954:
    v_12082 = stack[0];
    if (!consp(v_12082)) goto v_11965;
    else goto v_11966;
v_11965:
    v_12082 = lisp_true;
    goto v_11964;
v_11966:
    v_12082 = stack[0];
    v_12082 = qcar(v_12082);
    v_12082 = (consp(v_12082) ? nil : lisp_true);
    goto v_11964;
    v_12082 = nil;
v_11964:
    if (v_12082 == nil) goto v_11962;
    v_12082 = lisp_true;
    goto v_11960;
v_11962:
    goto v_11982;
v_11978:
    v_12082 = stack[0];
    v_12082 = qcar(v_12082);
    v_12082 = qcar(v_12082);
    v_12083 = qcdr(v_12082);
    goto v_11979;
v_11980:
    v_12082 = qvalue(elt(env, 1)); // repowl!*
    v_12082 = qcar(v_12082);
    v_12082 = qcdr(v_12082);
    goto v_11981;
v_11982:
    goto v_11978;
v_11979:
    goto v_11980;
v_11981:
    v_12082 = (LispObject)lessp2(v_12083, v_12082);
    v_12082 = v_12082 ? lisp_true : nil;
    env = stack[-2];
    goto v_11960;
    v_12082 = nil;
v_11960:
    if (v_12082 == nil) goto v_11958;
    v_12082 = stack[0];
    goto v_11953;
v_11958:
    goto v_11997;
v_11993:
    v_12082 = stack[0];
    v_12082 = qcar(v_12082);
    v_12082 = qcar(v_12082);
    v_12083 = qcdr(v_12082);
    goto v_11994;
v_11995:
    v_12082 = qvalue(elt(env, 1)); // repowl!*
    v_12082 = qcar(v_12082);
    v_12082 = qcdr(v_12082);
    goto v_11996;
v_11997:
    goto v_11993;
v_11994:
    goto v_11995;
v_11996:
    if (equal(v_12083, v_12082)) goto v_11991;
    else goto v_11992;
v_11991:
    goto v_12010;
v_12006:
    goto v_12016;
v_12012:
    v_12082 = qvalue(elt(env, 1)); // repowl!*
    v_12083 = qcdr(v_12082);
    goto v_12013;
v_12014:
    v_12082 = stack[0];
    v_12082 = qcar(v_12082);
    v_12082 = qcdr(v_12082);
    goto v_12015;
v_12016:
    goto v_12012;
v_12013:
    goto v_12014;
v_12015:
    fn = elt(env, 2); // multf
    v_12083 = (*qfn2(fn))(fn, v_12083, v_12082);
    env = stack[-2];
    goto v_12007;
v_12008:
    v_12082 = stack[0];
    v_12082 = qcdr(v_12082);
    goto v_12009;
v_12010:
    goto v_12006;
v_12007:
    goto v_12008;
v_12009:
    {
        fn = elt(env, 3); // addf
        return (*qfn2(fn))(fn, v_12083, v_12082);
    }
v_11992:
    goto v_12031;
v_12027:
    goto v_12037;
v_12033:
    goto v_12043;
v_12039:
    goto v_12050;
v_12046:
    goto v_12056;
v_12052:
    v_12082 = stack[0];
    v_12082 = qcar(v_12082);
    v_12082 = qcar(v_12082);
    stack[-1] = qcar(v_12082);
    goto v_12053;
v_12054:
    goto v_12066;
v_12062:
    v_12082 = stack[0];
    v_12082 = qcar(v_12082);
    v_12082 = qcar(v_12082);
    v_12083 = qcdr(v_12082);
    goto v_12063;
v_12064:
    v_12082 = qvalue(elt(env, 1)); // repowl!*
    v_12082 = qcar(v_12082);
    v_12082 = qcdr(v_12082);
    goto v_12065;
v_12066:
    goto v_12062;
v_12063:
    goto v_12064;
v_12065:
    v_12082 = difference2(v_12083, v_12082);
    env = stack[-2];
    goto v_12055;
v_12056:
    goto v_12052;
v_12053:
    goto v_12054;
v_12055:
    fn = elt(env, 4); // to
    v_12083 = (*qfn2(fn))(fn, stack[-1], v_12082);
    env = stack[-2];
    goto v_12047;
v_12048:
    v_12082 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12049;
v_12050:
    goto v_12046;
v_12047:
    goto v_12048;
v_12049:
    v_12082 = cons(v_12083, v_12082);
    env = stack[-2];
    v_12083 = ncons(v_12082);
    env = stack[-2];
    goto v_12040;
v_12041:
    v_12082 = stack[0];
    v_12082 = qcar(v_12082);
    v_12082 = qcdr(v_12082);
    goto v_12042;
v_12043:
    goto v_12039;
v_12040:
    goto v_12041;
v_12042:
    fn = elt(env, 2); // multf
    v_12083 = (*qfn2(fn))(fn, v_12083, v_12082);
    env = stack[-2];
    goto v_12034;
v_12035:
    v_12082 = qvalue(elt(env, 1)); // repowl!*
    v_12082 = qcdr(v_12082);
    goto v_12036;
v_12037:
    goto v_12033;
v_12034:
    goto v_12035;
v_12036:
    fn = elt(env, 2); // multf
    v_12083 = (*qfn2(fn))(fn, v_12083, v_12082);
    env = stack[-2];
    goto v_12028;
v_12029:
    v_12082 = stack[0];
    v_12082 = qcdr(v_12082);
    goto v_12030;
v_12031:
    goto v_12027;
v_12028:
    goto v_12029;
v_12030:
    fn = elt(env, 3); // addf
    v_12082 = (*qfn2(fn))(fn, v_12083, v_12082);
    env = stack[-2];
    stack[0] = v_12082;
    goto v_11954;
    v_12082 = nil;
v_11953:
    return onevalue(v_12082);
}



// Code for general!-reciprocal!-by!-gcd

static LispObject CC_generalKreciprocalKbyKgcd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12056, v_12057, v_12058;
    LispObject fn;
    LispObject v_11953, v_11952, v_11951, v_11950;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "general-reciprocal-by-gcd");
    va_start(aa, nargs);
    v_11950 = va_arg(aa, LispObject);
    v_11951 = va_arg(aa, LispObject);
    v_11952 = va_arg(aa, LispObject);
    v_11953 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_11953,v_11952,v_11951,v_11950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_11950,v_11951,v_11952,v_11953);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_11953;
    stack[-2] = v_11952;
    stack[-3] = v_11951;
    stack[-4] = v_11950;
// end of prologue
v_11959:
    goto v_11968;
v_11964:
    v_12057 = stack[-3];
    goto v_11965;
v_11966:
    v_12056 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11967;
v_11968:
    goto v_11964;
v_11965:
    goto v_11966;
v_11967:
    if (v_12057 == v_12056) goto v_11962;
    else goto v_11963;
v_11962:
    goto v_11978;
v_11972:
    v_12058 = elt(env, 1); // alg
    goto v_11973;
v_11974:
    v_12057 = (LispObject)128+TAG_FIXNUM; // 8
    goto v_11975;
v_11976:
    v_12056 = elt(env, 2); // "Invalid modular division"
    goto v_11977;
v_11978:
    goto v_11972;
v_11973:
    goto v_11974;
v_11975:
    goto v_11976;
v_11977:
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_12058, v_12057, v_12056);
    }
v_11963:
    goto v_11988;
v_11984:
    v_12057 = stack[-3];
    goto v_11985;
v_11986:
    v_12056 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11987;
v_11988:
    goto v_11984;
v_11985:
    goto v_11986;
v_11987:
    if (v_12057 == v_12056) goto v_11982;
    else goto v_11983;
v_11982:
    goto v_12000;
v_11996:
    v_12057 = stack[-1];
    goto v_11997;
v_11998:
    v_12056 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11999;
v_12000:
    goto v_11996;
v_11997:
    goto v_11998;
v_11999:
    v_12056 = (LispObject)lessp2(v_12057, v_12056);
    v_12056 = v_12056 ? lisp_true : nil;
    env = stack[-6];
    if (v_12056 == nil) goto v_11994;
    goto v_12008;
v_12004:
    v_12056 = stack[-1];
    goto v_12005;
v_12006:
    v_12057 = qvalue(elt(env, 3)); // current!-modulus
    goto v_12007;
v_12008:
    goto v_12004;
v_12005:
    goto v_12006;
v_12007:
    return plus2(v_12056, v_12057);
v_11994:
    v_12056 = stack[-1];
    goto v_11992;
    v_12056 = nil;
v_11992:
    goto v_11958;
v_11983:
    goto v_12019;
v_12015:
    v_12057 = stack[-4];
    goto v_12016;
v_12017:
    v_12056 = stack[-3];
    goto v_12018;
v_12019:
    goto v_12015;
v_12016:
    goto v_12017;
v_12018:
    v_12056 = quot2(v_12057, v_12056);
    env = stack[-6];
    stack[-5] = v_12056;
    v_12056 = stack[-4];
    v_12057 = v_12056;
    v_12056 = stack[-3];
    stack[-4] = v_12056;
    goto v_12029;
v_12025:
    stack[0] = v_12057;
    goto v_12026;
v_12027:
    goto v_12036;
v_12032:
    v_12057 = stack[-3];
    goto v_12033;
v_12034:
    v_12056 = stack[-5];
    goto v_12035;
v_12036:
    goto v_12032;
v_12033:
    goto v_12034;
v_12035:
    v_12056 = times2(v_12057, v_12056);
    env = stack[-6];
    goto v_12028;
v_12029:
    goto v_12025;
v_12026:
    goto v_12027;
v_12028:
    v_12056 = difference2(stack[0], v_12056);
    env = stack[-6];
    stack[-3] = v_12056;
    v_12056 = stack[-2];
    v_12057 = v_12056;
    v_12056 = stack[-1];
    stack[-2] = v_12056;
    goto v_12046;
v_12042:
    stack[0] = v_12057;
    goto v_12043;
v_12044:
    goto v_12053;
v_12049:
    v_12057 = stack[-1];
    goto v_12050;
v_12051:
    v_12056 = stack[-5];
    goto v_12052;
v_12053:
    goto v_12049;
v_12050:
    goto v_12051;
v_12052:
    v_12056 = times2(v_12057, v_12056);
    env = stack[-6];
    goto v_12045;
v_12046:
    goto v_12042;
v_12043:
    goto v_12044;
v_12045:
    v_12056 = difference2(stack[0], v_12056);
    env = stack[-6];
    stack[-1] = v_12056;
    goto v_11959;
v_11958:
    return onevalue(v_12056);
}



setup_type const u21_setup[] =
{
    {"begin1a",                 CC_begin1a,     TOO_MANY_1,    WRONG_NO_1},
    {"bas_newnumber",           TOO_FEW_2,      CC_bas_newnumber,WRONG_NO_2},
    {"derivative-mod-p-1",      TOO_FEW_2,      CC_derivativeKmodKpK1,WRONG_NO_2},
    {"carrassoc",               TOO_FEW_2,      CC_carrassoc,  WRONG_NO_2},
    {"ofsf_varlat",             CC_ofsf_varlat, TOO_MANY_1,    WRONG_NO_1},
    {"simpqg",                  CC_simpqg,      TOO_MANY_1,    WRONG_NO_1},
    {"mkprod",                  CC_mkprod,      TOO_MANY_1,    WRONG_NO_1},
    {"cl_simpl1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_simpl1},
    {"gb_buch-ev_divides?",     TOO_FEW_2,      CC_gb_buchKev_dividesW,WRONG_NO_2},
    {"ev_invlexcomp",           TOO_FEW_2,      CC_ev_invlexcomp,WRONG_NO_2},
    {"ir2mml",                  CC_ir2mml,      TOO_MANY_1,    WRONG_NO_1},
    {"rd:prep",                 CC_rdTprep,     TOO_MANY_1,    WRONG_NO_1},
    {"chk",                     CC_chk,         TOO_MANY_1,    WRONG_NO_1},
    {"expvec2a",                CC_expvec2a,    TOO_MANY_1,    WRONG_NO_1},
    {"treesizep",               TOO_FEW_2,      CC_treesizep,  WRONG_NO_2},
    {"ncoeffs",                 CC_ncoeffs,     TOO_MANY_1,    WRONG_NO_1},
    {"nfactorial",              CC_nfactorial,  TOO_MANY_1,    WRONG_NO_1},
    {"expand-imrepart",         CC_expandKimrepart,TOO_MANY_1, WRONG_NO_1},
    {"rootrnd",                 CC_rootrnd,     TOO_MANY_1,    WRONG_NO_1},
    {"mkcr",                    TOO_FEW_2,      CC_mkcr,       WRONG_NO_2},
    {"cde_delete",              TOO_FEW_2,      CC_cde_delete, WRONG_NO_2},
    {"lalr_prin_rhs",           CC_lalr_prin_rhs,TOO_MANY_1,   WRONG_NO_1},
    {"dfprint",                 CC_dfprint,     TOO_MANY_1,    WRONG_NO_1},
    {"sfto_sqfpartf",           CC_sfto_sqfpartf,TOO_MANY_1,   WRONG_NO_1},
    {"cl_atl",                  CC_cl_atl,      TOO_MANY_1,    WRONG_NO_1},
    {"sq2sstm",                 TOO_FEW_2,      CC_sq2sstm,    WRONG_NO_2},
    {"diff-over-k-mod-p",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_diffKoverKkKmodKp},
    {"dipevlcomp",              TOO_FEW_2,      CC_dipevlcomp, WRONG_NO_2},
    {"coposp",                  CC_coposp,      TOO_MANY_1,    WRONG_NO_1},
    {"assert_format",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_assert_format},
    {"mv-domainlist",           CC_mvKdomainlist,TOO_MANY_1,   WRONG_NO_1},
    {"rnprep:",                 CC_rnprepT,     TOO_MANY_1,    WRONG_NO_1},
    {"quotfail-in-vector",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_quotfailKinKvector},
    {"lalr_precalculate_first_sets",WRONG_NO_NA,WRONG_NO_NB,   (n_args *)CC_lalr_precalculate_first_sets},
    {"readprogn",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_readprogn},
    {"ofsf_smwmkatl",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smwmkatl},
    {"vintersection",           TOO_FEW_2,      CC_vintersection,WRONG_NO_2},
    {"ibalp_var-wclist",        CC_ibalp_varKwclist,TOO_MANY_1,WRONG_NO_1},
    {"quotofd",                 TOO_FEW_2,      CC_quotofd,    WRONG_NO_2},
    {"dm-gt",                   TOO_FEW_2,      CC_dmKgt,      WRONG_NO_2},
    {"dipcondense",             CC_dipcondense, TOO_MANY_1,    WRONG_NO_1},
    {"partitexdf",              CC_partitexdf,  TOO_MANY_1,    WRONG_NO_1},
    {"indord2",                 TOO_FEW_2,      CC_indord2,    WRONG_NO_2},
    {"sf2mv1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_sf2mv1},
    {":rn2rd",                  CC_Trn2rd,      TOO_MANY_1,    WRONG_NO_1},
    {"groeb=weight",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_groebMweight},
    {"tensorp",                 CC_tensorp,     TOO_MANY_1,    WRONG_NO_1},
    {"reducepowers",            CC_reducepowers,TOO_MANY_1,    WRONG_NO_1},
    {"general-reciprocal-by-gcd",WRONG_NO_NA,   WRONG_NO_NB,   (n_args *)CC_generalKreciprocalKbyKgcd},
    {NULL, (one_args *)"u21", (two_args *)"35054 6097351 5502530", 0}
};

// end of generated code
