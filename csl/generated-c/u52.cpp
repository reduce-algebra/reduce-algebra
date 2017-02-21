
// $destdir/u52.c        Machine generated C code

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



// Code for qqe_simplqequal

static LispObject CC_qqe_simplqequal(LispObject env,
                         LispObject v_30535, LispObject v_30536)
{
    env = qenv(env);
    LispObject v_30929, v_30930, v_30931;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30535,v_30536);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    v_30929 = v_30536;
    stack[0] = v_30535;
// end of prologue
v_30534:
    v_30929 = stack[0];
    fn = elt(env, 5); // qqe_arg2r
    v_30929 = (*qfn1(fn))(fn, v_30929);
    env = stack[-9];
    stack[-7] = v_30929;
    v_30929 = stack[0];
    fn = elt(env, 6); // qqe_arg2l
    v_30929 = (*qfn1(fn))(fn, v_30929);
    env = stack[-9];
    stack[-8] = v_30929;
    goto v_30562;
v_30558:
    v_30930 = stack[-7];
    goto v_30559;
v_30560:
    v_30929 = stack[-8];
    goto v_30561;
v_30562:
    goto v_30558;
v_30559:
    goto v_30560;
v_30561:
    if (equal(v_30930, v_30929)) goto v_30556;
    else goto v_30557;
v_30556:
    v_30929 = elt(env, 1); // true
    goto v_30549;
v_30557:
    v_30929 = stack[-8];
    fn = elt(env, 7); // qqe_qprefix!-var
    v_30929 = (*qfn1(fn))(fn, v_30929);
    env = stack[-9];
    stack[-6] = v_30929;
    v_30929 = stack[-7];
    fn = elt(env, 7); // qqe_qprefix!-var
    v_30929 = (*qfn1(fn))(fn, v_30929);
    env = stack[-9];
    stack[-5] = v_30929;
    goto v_30582;
v_30578:
    v_30930 = stack[-6];
    goto v_30579;
v_30580:
    v_30929 = stack[-5];
    goto v_30581;
v_30582:
    goto v_30578;
v_30579:
    goto v_30580;
v_30581:
    if (v_30930 == v_30929) goto v_30576;
    else goto v_30577;
v_30576:
    v_30929 = lisp_true;
    goto v_30575;
v_30577:
    goto v_30596;
v_30592:
    v_30930 = stack[-6];
    goto v_30593;
v_30594:
    v_30929 = elt(env, 2); // qepsilon
    goto v_30595;
v_30596:
    goto v_30592;
v_30593:
    goto v_30594;
v_30595:
    if (v_30930 == v_30929) goto v_30590;
    else goto v_30591;
v_30590:
    v_30929 = lisp_true;
    goto v_30589;
v_30591:
    goto v_30606;
v_30602:
    v_30930 = stack[-5];
    goto v_30603;
v_30604:
    v_30929 = elt(env, 2); // qepsilon
    goto v_30605;
v_30606:
    goto v_30602;
v_30603:
    goto v_30604;
v_30605:
    v_30929 = (v_30930 == v_30929 ? lisp_true : nil);
    goto v_30589;
    v_30929 = nil;
v_30589:
    goto v_30575;
    v_30929 = nil;
v_30575:
    if (v_30929 == nil) goto v_30573;
    v_30929 = stack[-7];
    fn = elt(env, 8); // qqe_number!-of!-adds!-in!-qterm
    v_30929 = (*qfn1(fn))(fn, v_30929);
    env = stack[-9];
    stack[-3] = v_30929;
    v_30929 = stack[-8];
    fn = elt(env, 8); // qqe_number!-of!-adds!-in!-qterm
    v_30929 = (*qfn1(fn))(fn, v_30929);
    env = stack[-9];
    stack[-4] = v_30929;
    v_30929 = stack[-7];
    fn = elt(env, 9); // qqe_number!-of!-tails!-in!-qterm
    v_30929 = (*qfn1(fn))(fn, v_30929);
    env = stack[-9];
    stack[-1] = v_30929;
    v_30929 = stack[-8];
    fn = elt(env, 9); // qqe_number!-of!-tails!-in!-qterm
    v_30929 = (*qfn1(fn))(fn, v_30929);
    env = stack[-9];
    stack[-2] = v_30929;
    goto v_30630;
v_30626:
    v_30930 = stack[-6];
    goto v_30627;
v_30628:
    v_30929 = stack[-5];
    goto v_30629;
v_30630:
    goto v_30626;
v_30627:
    goto v_30628;
v_30629:
    if (v_30930 == v_30929) goto v_30624;
    else goto v_30625;
v_30624:
    goto v_30643;
v_30639:
    v_30930 = stack[-3];
    goto v_30640;
v_30641:
    v_30929 = stack[-1];
    goto v_30642;
v_30643:
    goto v_30639;
v_30640:
    goto v_30641;
v_30642:
    v_30929 = (LispObject)geq2(v_30930, v_30929);
    v_30929 = v_30929 ? lisp_true : nil;
    env = stack[-9];
    if (v_30929 == nil) goto v_30637;
    else goto v_30636;
v_30637:
    goto v_30652;
v_30648:
    v_30930 = stack[-4];
    goto v_30649;
v_30650:
    v_30929 = stack[-2];
    goto v_30651;
v_30652:
    goto v_30648;
v_30649:
    goto v_30650;
v_30651:
    v_30929 = (LispObject)geq2(v_30930, v_30929);
    v_30929 = v_30929 ? lisp_true : nil;
    env = stack[-9];
    if (v_30929 == nil) goto v_30646;
    else goto v_30636;
v_30646:
    v_30929 = nil;
    goto v_30634;
v_30636:
    goto v_30662;
v_30658:
    goto v_30668;
v_30664:
    v_30930 = stack[-3];
    goto v_30665;
v_30666:
    v_30929 = stack[-1];
    goto v_30667;
v_30668:
    goto v_30664;
v_30665:
    goto v_30666;
v_30667:
    stack[0] = difference2(v_30930, v_30929);
    env = stack[-9];
    goto v_30659;
v_30660:
    goto v_30676;
v_30672:
    v_30930 = stack[-4];
    goto v_30673;
v_30674:
    v_30929 = stack[-2];
    goto v_30675;
v_30676:
    goto v_30672;
v_30673:
    goto v_30674;
v_30675:
    v_30929 = difference2(v_30930, v_30929);
    env = stack[-9];
    goto v_30661;
v_30662:
    goto v_30658;
v_30659:
    goto v_30660;
v_30661:
    v_30929 = (equal(stack[0], v_30929) ? lisp_true : nil);
    v_30929 = (v_30929 == nil ? lisp_true : nil);
    goto v_30634;
    v_30929 = nil;
v_30634:
    goto v_30623;
v_30625:
    v_30929 = nil;
    goto v_30623;
    v_30929 = nil;
v_30623:
    if (v_30929 == nil) goto v_30621;
    v_30929 = elt(env, 3); // false
    goto v_30549;
v_30621:
    goto v_30696;
v_30692:
    v_30930 = stack[-7];
    goto v_30693;
v_30694:
    v_30929 = elt(env, 2); // qepsilon
    goto v_30695;
v_30696:
    goto v_30692;
v_30693:
    goto v_30694;
v_30695:
    if (v_30930 == v_30929) goto v_30690;
    else goto v_30691;
v_30690:
    goto v_30704;
v_30700:
    v_30930 = stack[-4];
    goto v_30701;
v_30702:
    v_30929 = stack[-2];
    goto v_30703;
v_30704:
    goto v_30700;
v_30701:
    goto v_30702;
v_30703:
    v_30929 = (LispObject)greaterp2(v_30930, v_30929);
    v_30929 = v_30929 ? lisp_true : nil;
    env = stack[-9];
    goto v_30689;
v_30691:
    v_30929 = nil;
    goto v_30689;
    v_30929 = nil;
v_30689:
    if (v_30929 == nil) goto v_30687;
    v_30929 = elt(env, 3); // false
    goto v_30549;
v_30687:
    goto v_30721;
v_30717:
    v_30930 = stack[-8];
    goto v_30718;
v_30719:
    v_30929 = elt(env, 2); // qepsilon
    goto v_30720;
v_30721:
    goto v_30717;
v_30718:
    goto v_30719;
v_30720:
    if (v_30930 == v_30929) goto v_30715;
    else goto v_30716;
v_30715:
    goto v_30729;
v_30725:
    v_30930 = stack[-3];
    goto v_30726;
v_30727:
    v_30929 = stack[-1];
    goto v_30728;
v_30729:
    goto v_30725;
v_30726:
    goto v_30727;
v_30728:
    v_30929 = (LispObject)greaterp2(v_30930, v_30929);
    v_30929 = v_30929 ? lisp_true : nil;
    env = stack[-9];
    goto v_30714;
v_30716:
    v_30929 = nil;
    goto v_30714;
    v_30929 = nil;
v_30714:
    if (v_30929 == nil) goto v_30712;
    v_30929 = elt(env, 3); // false
    goto v_30549;
v_30712:
    goto v_30746;
v_30742:
    v_30930 = stack[-7];
    goto v_30743;
v_30744:
    v_30929 = elt(env, 2); // qepsilon
    goto v_30745;
v_30746:
    goto v_30742;
v_30743:
    goto v_30744;
v_30745:
    if (v_30930 == v_30929) goto v_30740;
    else goto v_30741;
v_30740:
    goto v_30757;
v_30753:
    v_30930 = stack[-3];
    goto v_30754;
v_30755:
    v_30929 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30756;
v_30757:
    goto v_30753;
v_30754:
    goto v_30755;
v_30756:
    if (v_30930 == v_30929) goto v_30751;
    else goto v_30752;
v_30751:
    goto v_30764;
v_30760:
    v_30930 = stack[-4];
    goto v_30761;
v_30762:
    v_30929 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30763;
v_30764:
    goto v_30760;
v_30761:
    goto v_30762;
v_30763:
    v_30929 = (v_30930 == v_30929 ? lisp_true : nil);
    goto v_30750;
v_30752:
    v_30929 = nil;
    goto v_30750;
    v_30929 = nil;
v_30750:
    goto v_30739;
v_30741:
    v_30929 = nil;
    goto v_30739;
    v_30929 = nil;
v_30739:
    if (v_30929 == nil) goto v_30737;
    goto v_30782;
v_30778:
    v_30930 = stack[-6];
    goto v_30779;
v_30780:
    v_30929 = elt(env, 2); // qepsilon
    goto v_30781;
v_30782:
    goto v_30778;
v_30779:
    goto v_30780;
v_30781:
    if (v_30930 == v_30929) goto v_30776;
    else goto v_30777;
v_30776:
    v_30929 = elt(env, 1); // true
    goto v_30549;
v_30777:
    v_30929 = stack[-8];
    fn = elt(env, 10); // qqe_simplterm
    v_30929 = (*qfn1(fn))(fn, v_30929);
    env = stack[-9];
    goto v_30775;
v_30775:
    goto v_30797;
v_30791:
    v_30930 = elt(env, 4); // qequal
    goto v_30792;
v_30793:
    v_30931 = v_30929;
    goto v_30794;
v_30795:
    v_30929 = stack[-7];
    goto v_30796;
v_30797:
    goto v_30791;
v_30792:
    goto v_30793;
v_30794:
    goto v_30795;
v_30796:
    {
        fn = elt(env, 11); // qqe_mk2
        return (*qfnn(fn))(fn, 3, v_30930, v_30931, v_30929);
    }
v_30737:
    goto v_30812;
v_30808:
    v_30930 = stack[-8];
    goto v_30809;
v_30810:
    v_30929 = elt(env, 2); // qepsilon
    goto v_30811;
v_30812:
    goto v_30808;
v_30809:
    goto v_30810;
v_30811:
    if (v_30930 == v_30929) goto v_30806;
    else goto v_30807;
v_30806:
    goto v_30823;
v_30819:
    v_30930 = stack[-3];
    goto v_30820;
v_30821:
    v_30929 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30822;
v_30823:
    goto v_30819;
v_30820:
    goto v_30821;
v_30822:
    if (v_30930 == v_30929) goto v_30817;
    else goto v_30818;
v_30817:
    goto v_30830;
v_30826:
    v_30930 = stack[-4];
    goto v_30827;
v_30828:
    v_30929 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30829;
v_30830:
    goto v_30826;
v_30827:
    goto v_30828;
v_30829:
    v_30929 = (v_30930 == v_30929 ? lisp_true : nil);
    goto v_30816;
v_30818:
    v_30929 = nil;
    goto v_30816;
    v_30929 = nil;
v_30816:
    goto v_30805;
v_30807:
    v_30929 = nil;
    goto v_30805;
    v_30929 = nil;
v_30805:
    if (v_30929 == nil) goto v_30803;
    goto v_30848;
v_30844:
    v_30930 = stack[-5];
    goto v_30845;
v_30846:
    v_30929 = elt(env, 2); // qepsilon
    goto v_30847;
v_30848:
    goto v_30844;
v_30845:
    goto v_30846;
v_30847:
    if (v_30930 == v_30929) goto v_30842;
    else goto v_30843;
v_30842:
    v_30929 = elt(env, 1); // true
    goto v_30549;
v_30843:
    v_30929 = stack[-7];
    fn = elt(env, 10); // qqe_simplterm
    v_30929 = (*qfn1(fn))(fn, v_30929);
    env = stack[-9];
    stack[0] = v_30929;
    goto v_30841;
v_30841:
    goto v_30863;
v_30857:
    v_30931 = elt(env, 4); // qequal
    goto v_30858;
v_30859:
    v_30930 = stack[-8];
    goto v_30860;
v_30861:
    v_30929 = stack[0];
    goto v_30862;
v_30863:
    goto v_30857;
v_30858:
    goto v_30859;
v_30860:
    goto v_30861;
v_30862:
    {
        fn = elt(env, 11); // qqe_mk2
        return (*qfnn(fn))(fn, 3, v_30931, v_30930, v_30929);
    }
v_30803:
    goto v_30571;
v_30573:
v_30571:
    v_30929 = stack[-7];
    fn = elt(env, 10); // qqe_simplterm
    v_30929 = (*qfn1(fn))(fn, v_30929);
    env = stack[-9];
    stack[0] = v_30929;
    v_30929 = stack[-8];
    fn = elt(env, 10); // qqe_simplterm
    v_30929 = (*qfn1(fn))(fn, v_30929);
    env = stack[-9];
    goto v_30884;
v_30880:
    v_30931 = stack[-7];
    goto v_30881;
v_30882:
    v_30930 = stack[0];
    goto v_30883;
v_30884:
    goto v_30880;
v_30881:
    goto v_30882;
v_30883:
    if (equal(v_30931, v_30930)) goto v_30878;
    else goto v_30879;
v_30878:
    goto v_30891;
v_30887:
    v_30931 = stack[-8];
    goto v_30888;
v_30889:
    v_30930 = v_30929;
    goto v_30890;
v_30891:
    goto v_30887;
v_30888:
    goto v_30889;
v_30890:
    v_30930 = (equal(v_30931, v_30930) ? lisp_true : nil);
    goto v_30877;
v_30879:
    v_30930 = nil;
    goto v_30877;
    v_30930 = nil;
v_30877:
    if (v_30930 == nil) goto v_30875;
    goto v_30905;
v_30899:
    v_30931 = elt(env, 4); // qequal
    goto v_30900;
v_30901:
    v_30930 = v_30929;
    goto v_30902;
v_30903:
    v_30929 = stack[0];
    goto v_30904;
v_30905:
    goto v_30899;
v_30900:
    goto v_30901;
v_30902:
    goto v_30903;
v_30904:
    {
        fn = elt(env, 11); // qqe_mk2
        return (*qfnn(fn))(fn, 3, v_30931, v_30930, v_30929);
    }
v_30875:
    goto v_30916;
v_30912:
    goto v_30924;
v_30918:
    v_30931 = elt(env, 4); // qequal
    goto v_30919;
v_30920:
    v_30930 = v_30929;
    goto v_30921;
v_30922:
    v_30929 = stack[0];
    goto v_30923;
v_30924:
    goto v_30918;
v_30919:
    goto v_30920;
v_30921:
    goto v_30922;
v_30923:
    fn = elt(env, 11); // qqe_mk2
    v_30929 = (*qfnn(fn))(fn, 3, v_30931, v_30930, v_30929);
    env = stack[-9];
    goto v_30913;
v_30914:
    goto v_30915;
v_30916:
    goto v_30912;
v_30913:
    goto v_30914;
v_30915:
    stack[0] = v_30929;
    goto v_30534;
    v_30929 = nil;
v_30549:
    return onevalue(v_30929);
}



// Code for vdpfmon

static LispObject CC_vdpfmon(LispObject env,
                         LispObject v_30535, LispObject v_30536)
{
    env = qenv(env);
    LispObject v_30582;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30535,v_30536);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_30536;
    v_30582 = v_30535;
// end of prologue
    goto v_30550;
v_30542:
    stack[-5] = elt(env, 1); // vdp
    goto v_30543;
v_30544:
    stack[-3] = stack[-4];
    goto v_30545;
v_30546:
    stack[-2] = v_30582;
    goto v_30547;
v_30548:
    goto v_30561;
v_30555:
    stack[-1] = stack[-4];
    goto v_30556;
v_30557:
    stack[0] = ncons(v_30582);
    env = stack[-6];
    goto v_30558;
v_30559:
    v_30582 = nil;
    v_30582 = ncons(v_30582);
    env = stack[-6];
    goto v_30560;
v_30561:
    goto v_30555;
v_30556:
    goto v_30557;
v_30558:
    goto v_30559;
v_30560:
    v_30582 = acons(stack[-1], stack[0], v_30582);
    env = stack[-6];
    goto v_30549;
v_30550:
    goto v_30542;
v_30543:
    goto v_30544;
v_30545:
    goto v_30546;
v_30547:
    goto v_30548;
v_30549:
    v_30582 = list3star(stack[-5], stack[-3], stack[-2], v_30582);
    env = stack[-6];
    stack[-1] = v_30582;
    v_30582 = qvalue(elt(env, 2)); // !*gsugar
    if (v_30582 == nil) goto v_30570;
    goto v_30577;
v_30573:
    stack[0] = stack[-1];
    goto v_30574;
v_30575:
    v_30582 = stack[-4];
    fn = elt(env, 3); // vevtdeg
    v_30582 = (*qfn1(fn))(fn, v_30582);
    env = stack[-6];
    goto v_30576;
v_30577:
    goto v_30573;
v_30574:
    goto v_30575;
v_30576:
    fn = elt(env, 4); // gsetsugar
    v_30582 = (*qfn2(fn))(fn, stack[0], v_30582);
    goto v_30568;
v_30570:
v_30568:
    v_30582 = stack[-1];
    return onevalue(v_30582);
}



// Code for xexptpf

static LispObject CC_xexptpf(LispObject env,
                         LispObject v_30535, LispObject v_30536)
{
    env = qenv(env);
    LispObject v_30584, v_30585;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30535,v_30536);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30536;
    stack[-1] = v_30535;
// end of prologue
    stack[-2] = nil;
v_30542:
    goto v_30553;
v_30549:
    v_30585 = stack[0];
    goto v_30550;
v_30551:
    v_30584 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30552;
v_30553:
    goto v_30549;
v_30550:
    goto v_30551;
v_30552:
    if (v_30585 == v_30584) goto v_30547;
    else goto v_30548;
v_30547:
    goto v_30543;
v_30548:
    goto v_30561;
v_30557:
    v_30585 = stack[-1];
    goto v_30558;
v_30559:
    v_30584 = stack[-2];
    goto v_30560;
v_30561:
    goto v_30557;
v_30558:
    goto v_30559;
v_30560:
    v_30584 = cons(v_30585, v_30584);
    env = stack[-3];
    stack[-2] = v_30584;
    v_30584 = stack[0];
    v_30584 = sub1(v_30584);
    env = stack[-3];
    stack[0] = v_30584;
    goto v_30542;
v_30543:
    v_30584 = stack[-1];
    v_30585 = v_30584;
v_30544:
    v_30584 = stack[-2];
    if (v_30584 == nil) goto v_30569;
    else goto v_30570;
v_30569:
    v_30584 = v_30585;
    goto v_30541;
v_30570:
    goto v_30578;
v_30574:
    v_30584 = stack[-2];
    v_30584 = qcar(v_30584);
    goto v_30575;
v_30576:
    goto v_30577;
v_30578:
    goto v_30574;
v_30575:
    goto v_30576;
v_30577:
    fn = elt(env, 1); // wedgepf
    v_30584 = (*qfn2(fn))(fn, v_30584, v_30585);
    env = stack[-3];
    v_30585 = v_30584;
    v_30584 = stack[-2];
    v_30584 = qcdr(v_30584);
    stack[-2] = v_30584;
    goto v_30544;
v_30541:
    return onevalue(v_30584);
}



// Code for mk!-contract!-coeff

static LispObject CC_mkKcontractKcoeff(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30596, v_30597;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30535);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_30535;
// end of prologue
    goto v_30545;
v_30541:
    v_30596 = stack[0];
    v_30596 = qcar(v_30596);
    v_30597 = qcar(v_30596);
    goto v_30542;
v_30543:
    v_30596 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30544;
v_30545:
    goto v_30541;
v_30542:
    goto v_30543;
v_30544:
    if (v_30597 == v_30596) goto v_30539;
    else goto v_30540;
v_30539:
    v_30596 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30538;
v_30540:
    v_30596 = stack[0];
    v_30596 = qcar(v_30596);
    v_30596 = qcar(v_30596);
    stack[-3] = v_30596;
    v_30596 = stack[0];
    v_30596 = qcdr(v_30596);
    v_30596 = qcar(v_30596);
    v_30596 = Llength(nil, v_30596);
    env = stack[-4];
    v_30597 = v_30596;
    goto v_30572;
v_30568:
    v_30596 = stack[0];
    v_30596 = qcar(v_30596);
    v_30596 = qcdr(v_30596);
    stack[-2] = qcar(v_30596);
    goto v_30569;
v_30570:
    goto v_30584;
v_30578:
    stack[-1] = qvalue(elt(env, 1)); // ndim!*
    goto v_30579;
v_30580:
    stack[0] = v_30597;
    goto v_30581;
v_30582:
    goto v_30592;
v_30588:
    goto v_30589;
v_30590:
    v_30596 = stack[-3];
    goto v_30591;
v_30592:
    goto v_30588;
v_30589:
    goto v_30590;
v_30591:
    v_30596 = plus2(v_30597, v_30596);
    env = stack[-4];
    goto v_30583;
v_30584:
    goto v_30578;
v_30579:
    goto v_30580;
v_30581:
    goto v_30582;
v_30583:
    fn = elt(env, 2); // mk!-numr
    v_30596 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_30596);
    env = stack[-4];
    goto v_30571;
v_30572:
    goto v_30568;
v_30569:
    goto v_30570;
v_30571:
    v_30596 = cons(stack[-2], v_30596);
    env = stack[-4];
    {
        fn = elt(env, 3); // constimes
        return (*qfn1(fn))(fn, v_30596);
    }
    goto v_30538;
    v_30596 = nil;
v_30538:
    return onevalue(v_30596);
}



// Code for rule!-list

static LispObject CC_ruleKlist(LispObject env,
                         LispObject v_30535, LispObject v_30536)
{
    env = qenv(env);
    LispObject v_30735, v_30736, v_30737, v_30738, v_30739;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30535,v_30536);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_30536;
    stack[-2] = v_30535;
// end of prologue
v_30544:
    v_30735 = nil;
    qvalue(elt(env, 1)) = v_30735; // frasc!*
    v_30735 = stack[-2];
    if (v_30735 == nil) goto v_30552;
    else goto v_30553;
v_30552:
    v_30735 = lisp_true;
    goto v_30551;
v_30553:
    goto v_30562;
v_30558:
    stack[0] = stack[-2];
    goto v_30559;
v_30560:
    v_30735 = nil;
    v_30735 = ncons(v_30735);
    env = stack[-4];
    goto v_30561;
v_30562:
    goto v_30558;
v_30559:
    goto v_30560;
v_30561:
    v_30735 = (equal(stack[0], v_30735) ? lisp_true : nil);
    goto v_30551;
    v_30735 = nil;
v_30551:
    if (v_30735 == nil) goto v_30549;
    v_30735 = nil;
    qvalue(elt(env, 2)) = v_30735; // mcond!*
    goto v_30543;
v_30549:
    v_30735 = lisp_true;
    qvalue(elt(env, 2)) = v_30735; // mcond!*
    v_30735 = stack[-2];
    v_30735 = qcar(v_30735);
    stack[-3] = v_30735;
    v_30735 = stack[-3];
    if (symbolp(v_30735)) goto v_30573;
    else goto v_30574;
v_30573:
    v_30735 = stack[-3];
    if (!symbolp(v_30735)) v_30735 = nil;
    else { v_30735 = qfastgets(v_30735);
           if (v_30735 != nil) { v_30735 = elt(v_30735, 4); // avalue
#ifdef RECORD_GET
             if (v_30735 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_30735 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_30735 == SPID_NOPROP) v_30735 = nil; }}
#endif
    v_30737 = v_30735;
    if (v_30735 == nil) goto v_30579;
    goto v_30588;
v_30584:
    v_30735 = v_30737;
    v_30736 = qcar(v_30735);
    goto v_30585;
v_30586:
    v_30735 = elt(env, 3); // list
    goto v_30587;
v_30588:
    goto v_30584;
v_30585:
    goto v_30586;
v_30587:
    if (v_30736 == v_30735) goto v_30583;
    else goto v_30579;
v_30583:
    goto v_30597;
v_30593:
    v_30735 = v_30737;
    v_30735 = qcdr(v_30735);
    v_30735 = qcar(v_30735);
    v_30735 = qcdr(v_30735);
    v_30736 = Lreverse(nil, v_30735);
    env = stack[-4];
    goto v_30594;
v_30595:
    v_30735 = stack[-2];
    v_30735 = qcdr(v_30735);
    goto v_30596;
v_30597:
    goto v_30593;
v_30594:
    goto v_30595;
v_30596:
    v_30735 = Lappend(nil, v_30736, v_30735);
    env = stack[-4];
    stack[-2] = v_30735;
    goto v_30544;
v_30579:
    goto v_30612;
v_30608:
    v_30736 = stack[-3];
    goto v_30609;
v_30610:
    v_30735 = elt(env, 4); // "rule list"
    goto v_30611;
v_30612:
    goto v_30608;
v_30609:
    goto v_30610;
v_30611:
    fn = elt(env, 11); // typerr
    v_30735 = (*qfn2(fn))(fn, v_30736, v_30735);
    env = stack[-4];
    goto v_30577;
v_30577:
    goto v_30572;
v_30574:
    goto v_30621;
v_30617:
    v_30735 = stack[-3];
    v_30736 = qcar(v_30735);
    goto v_30618;
v_30619:
    v_30735 = elt(env, 3); // list
    goto v_30620;
v_30621:
    goto v_30617;
v_30618:
    goto v_30619;
v_30620:
    if (v_30736 == v_30735) goto v_30615;
    else goto v_30616;
v_30615:
    goto v_30630;
v_30626:
    v_30735 = stack[-3];
    v_30736 = qcdr(v_30735);
    goto v_30627;
v_30628:
    v_30735 = stack[-2];
    v_30735 = qcdr(v_30735);
    goto v_30629;
v_30630:
    goto v_30626;
v_30627:
    goto v_30628;
v_30629:
    v_30735 = Lappend(nil, v_30736, v_30735);
    env = stack[-4];
    stack[-2] = v_30735;
    goto v_30544;
v_30616:
    goto v_30641;
v_30637:
    v_30735 = stack[-3];
    v_30736 = qcar(v_30735);
    goto v_30638;
v_30639:
    v_30735 = elt(env, 5); // equal
    goto v_30640;
v_30641:
    goto v_30637;
v_30638:
    goto v_30639;
v_30640:
    if (v_30736 == v_30735) goto v_30635;
    else goto v_30636;
v_30635:
    v_30735 = elt(env, 6); // "Please use => instead of = in rules"
    fn = elt(env, 12); // lprim
    v_30735 = (*qfn1(fn))(fn, v_30735);
    env = stack[-4];
    goto v_30572;
v_30636:
    goto v_30653;
v_30649:
    v_30735 = stack[-3];
    v_30736 = qcar(v_30735);
    goto v_30650;
v_30651:
    v_30735 = elt(env, 7); // replaceby
    goto v_30652;
v_30653:
    goto v_30649;
v_30650:
    goto v_30651;
v_30652:
    if (v_30736 == v_30735) goto v_30648;
    goto v_30662;
v_30658:
    v_30736 = stack[-3];
    goto v_30659;
v_30660:
    v_30735 = elt(env, 8); // "rule"
    goto v_30661;
v_30662:
    goto v_30658;
v_30659:
    goto v_30660;
v_30661:
    fn = elt(env, 11); // typerr
    v_30735 = (*qfn2(fn))(fn, v_30736, v_30735);
    env = stack[-4];
    goto v_30572;
v_30648:
v_30572:
    v_30735 = stack[-3];
    v_30735 = qcdr(v_30735);
    v_30735 = qcar(v_30735);
    fn = elt(env, 13); // remove!-free!-vars
    v_30735 = (*qfn1(fn))(fn, v_30735);
    env = stack[-4];
    stack[0] = v_30735;
    goto v_30678;
v_30674:
    v_30735 = stack[-3];
    v_30735 = qcdr(v_30735);
    v_30735 = qcdr(v_30735);
    v_30736 = qcar(v_30735);
    goto v_30675;
v_30676:
    v_30735 = elt(env, 9); // when
    goto v_30677;
v_30678:
    goto v_30674;
v_30675:
    goto v_30676;
v_30677:
    if (!consp(v_30736)) goto v_30672;
    v_30736 = qcar(v_30736);
    if (v_30736 == v_30735) goto v_30671;
    else goto v_30672;
v_30671:
    goto v_30691;
v_30685:
    v_30735 = stack[-3];
    v_30735 = qcdr(v_30735);
    v_30735 = qcdr(v_30735);
    v_30735 = qcar(v_30735);
    v_30735 = qcdr(v_30735);
    v_30735 = qcdr(v_30735);
    v_30735 = qcar(v_30735);
    fn = elt(env, 14); // remove!-free!-vars!*
    v_30737 = (*qfn1(fn))(fn, v_30735);
    env = stack[-4];
    goto v_30686;
v_30687:
    v_30736 = nil;
    goto v_30688;
v_30689:
    v_30735 = elt(env, 10); // algebraic
    goto v_30690;
v_30691:
    goto v_30685;
v_30686:
    goto v_30687;
v_30688:
    goto v_30689;
v_30690:
    fn = elt(env, 15); // formbool
    v_30735 = (*qfnn(fn))(fn, 3, v_30737, v_30736, v_30735);
    env = stack[-4];
    qvalue(elt(env, 2)) = v_30735; // mcond!*
    v_30735 = stack[-3];
    v_30735 = qcdr(v_30735);
    v_30735 = qcdr(v_30735);
    v_30735 = qcar(v_30735);
    v_30735 = qcdr(v_30735);
    v_30735 = qcar(v_30735);
    fn = elt(env, 14); // remove!-free!-vars!*
    v_30735 = (*qfn1(fn))(fn, v_30735);
    env = stack[-4];
    goto v_30670;
v_30672:
    v_30735 = stack[-3];
    v_30735 = qcdr(v_30735);
    v_30735 = qcdr(v_30735);
    v_30735 = qcar(v_30735);
    fn = elt(env, 14); // remove!-free!-vars!*
    v_30735 = (*qfn1(fn))(fn, v_30735);
    env = stack[-4];
    goto v_30670;
v_30670:
    goto v_30727;
v_30717:
    v_30739 = stack[0];
    goto v_30718;
v_30719:
    v_30738 = v_30735;
    goto v_30720;
v_30721:
    v_30737 = qvalue(elt(env, 1)); // frasc!*
    goto v_30722;
v_30723:
    v_30736 = qvalue(elt(env, 2)); // mcond!*
    goto v_30724;
v_30725:
    v_30735 = stack[-1];
    goto v_30726;
v_30727:
    goto v_30717;
v_30718:
    goto v_30719;
v_30720:
    goto v_30721;
v_30722:
    goto v_30723;
v_30724:
    goto v_30725;
v_30726:
    fn = elt(env, 16); // rule!*
    v_30735 = (*qfnn(fn))(fn, 5, v_30739, v_30738, v_30737, v_30736, v_30735);
    env = stack[-4];
    v_30735 = stack[-2];
    v_30735 = qcdr(v_30735);
    stack[-2] = v_30735;
    goto v_30544;
v_30543:
    return onevalue(v_30735);
}



// Code for hdiff

static LispObject CC_hdiff(LispObject env,
                         LispObject v_30535, LispObject v_30536)
{
    env = qenv(env);
    LispObject v_30575, v_30576;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30535,v_30536);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30536;
    stack[-1] = v_30535;
// end of prologue
    v_30575 = stack[-1];
    if (v_30575 == nil) goto v_30540;
    else goto v_30541;
v_30540:
    v_30575 = nil;
    goto v_30539;
v_30541:
    goto v_30551;
v_30547:
    goto v_30557;
v_30553:
    goto v_30562;
v_30558:
    v_30576 = stack[-1];
    goto v_30559;
v_30560:
    v_30575 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_30561;
v_30562:
    goto v_30558;
v_30559:
    goto v_30560;
v_30561:
    v_30576 = *(LispObject *)((char *)v_30576 + (CELL-TAG_VECTOR) + (((intptr_t)v_30575-TAG_FIXNUM)/(16/CELL)));
    goto v_30554;
v_30555:
    v_30575 = stack[0];
    goto v_30556;
v_30557:
    goto v_30553;
v_30554:
    goto v_30555;
v_30556:
    stack[-2] = CC_hdiff(elt(env, 0), v_30576, v_30575);
    env = stack[-3];
    goto v_30548;
v_30549:
    goto v_30572;
v_30568:
    v_30576 = stack[-1];
    goto v_30569;
v_30570:
    v_30575 = stack[0];
    goto v_30571;
v_30572:
    goto v_30568;
v_30569:
    goto v_30570;
v_30571:
    fn = elt(env, 1); // hdiffterm
    v_30575 = (*qfn2(fn))(fn, v_30576, v_30575);
    env = stack[-3];
    goto v_30550;
v_30551:
    goto v_30547;
v_30548:
    goto v_30549;
v_30550:
    {
        LispObject v_30580 = stack[-2];
        fn = elt(env, 2); // fs!:plus
        return (*qfn2(fn))(fn, v_30580, v_30575);
    }
    v_30575 = nil;
v_30539:
    return onevalue(v_30575);
}



// Code for test!-bool

static LispObject CC_testKbool(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30543;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30535);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30543 = v_30535;
// end of prologue
    v_30543 = qcar(v_30543);
    fn = elt(env, 1); // boolean!-eval1
    v_30543 = (*qfn1(fn))(fn, v_30543);
    env = stack[0];
    v_30543 = ncons(v_30543);
    env = stack[0];
    fn = elt(env, 2); // simp!-prop
    v_30543 = (*qfn1(fn))(fn, v_30543);
    env = stack[0];
    {
        fn = elt(env, 3); // mk!*sq
        return (*qfn1(fn))(fn, v_30543);
    }
}



// Code for combin

static LispObject CC_combin(LispObject env,
                         LispObject v_30535, LispObject v_30536)
{
    env = qenv(env);
    LispObject v_30634, v_30635;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30535,v_30536);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_30536;
    stack[-3] = v_30535;
// end of prologue
    goto v_30547;
v_30543:
    v_30635 = stack[-3];
    goto v_30544;
v_30545:
    v_30634 = stack[-2];
    goto v_30546;
v_30547:
    goto v_30543;
v_30544:
    goto v_30545;
v_30546:
    v_30634 = (LispObject)greaterp2(v_30635, v_30634);
    v_30634 = v_30634 ? lisp_true : nil;
    env = stack[-5];
    if (v_30634 == nil) goto v_30541;
    v_30634 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30539;
v_30541:
    v_30634 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_30634;
    stack[-4] = v_30634;
    goto v_30570;
v_30566:
    v_30635 = stack[-2];
    goto v_30567;
v_30568:
    v_30634 = stack[-3];
    goto v_30569;
v_30570:
    goto v_30566;
v_30567:
    goto v_30568;
v_30569:
    v_30634 = difference2(v_30635, v_30634);
    env = stack[-5];
    v_30634 = add1(v_30634);
    env = stack[-5];
    stack[0] = v_30634;
v_30563:
    goto v_30583;
v_30579:
    v_30635 = stack[-2];
    goto v_30580;
v_30581:
    v_30634 = stack[0];
    goto v_30582;
v_30583:
    goto v_30579;
v_30580:
    goto v_30581;
v_30582:
    v_30634 = difference2(v_30635, v_30634);
    env = stack[-5];
    v_30634 = Lminusp(nil, v_30634);
    env = stack[-5];
    if (v_30634 == nil) goto v_30576;
    goto v_30562;
v_30576:
    goto v_30592;
v_30588:
    v_30635 = stack[-4];
    goto v_30589;
v_30590:
    v_30634 = stack[0];
    goto v_30591;
v_30592:
    goto v_30588;
v_30589:
    goto v_30590;
v_30591:
    v_30634 = times2(v_30635, v_30634);
    env = stack[-5];
    stack[-4] = v_30634;
    v_30634 = stack[0];
    v_30634 = add1(v_30634);
    env = stack[-5];
    stack[0] = v_30634;
    goto v_30563;
v_30562:
    v_30634 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_30634;
v_30600:
    goto v_30612;
v_30608:
    v_30635 = stack[-3];
    goto v_30609;
v_30610:
    v_30634 = stack[0];
    goto v_30611;
v_30612:
    goto v_30608;
v_30609:
    goto v_30610;
v_30611:
    v_30634 = difference2(v_30635, v_30634);
    env = stack[-5];
    v_30634 = Lminusp(nil, v_30634);
    env = stack[-5];
    if (v_30634 == nil) goto v_30605;
    goto v_30599;
v_30605:
    goto v_30621;
v_30617:
    v_30635 = stack[-1];
    goto v_30618;
v_30619:
    v_30634 = stack[0];
    goto v_30620;
v_30621:
    goto v_30617;
v_30618:
    goto v_30619;
v_30620:
    v_30634 = times2(v_30635, v_30634);
    env = stack[-5];
    stack[-1] = v_30634;
    v_30634 = stack[0];
    v_30634 = add1(v_30634);
    env = stack[-5];
    stack[0] = v_30634;
    goto v_30600;
v_30599:
    goto v_30631;
v_30627:
    v_30635 = stack[-4];
    goto v_30628;
v_30629:
    v_30634 = stack[-1];
    goto v_30630;
v_30631:
    goto v_30627;
v_30628:
    goto v_30629;
v_30630:
    return quot2(v_30635, v_30634);
    goto v_30539;
    v_30634 = nil;
v_30539:
    return onevalue(v_30634);
}



// Code for alistp

static LispObject CC_alistp(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30567, v_30568;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30535);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30567 = v_30535;
// end of prologue
v_30534:
    v_30568 = v_30567;
    if (v_30568 == nil) goto v_30539;
    else goto v_30540;
v_30539:
    v_30567 = lisp_true;
    goto v_30538;
v_30540:
    v_30568 = v_30567;
    v_30568 = Lconsp(nil, v_30568);
    env = stack[0];
    if (v_30568 == nil) goto v_30547;
    else goto v_30548;
v_30547:
    v_30567 = nil;
    goto v_30546;
v_30548:
    v_30568 = v_30567;
    v_30568 = qcar(v_30568);
    v_30568 = Lconsp(nil, v_30568);
    env = stack[0];
    if (v_30568 == nil) goto v_30556;
    else goto v_30557;
v_30556:
    v_30567 = nil;
    goto v_30555;
v_30557:
    v_30567 = qcdr(v_30567);
    goto v_30534;
    v_30567 = nil;
v_30555:
    goto v_30546;
    v_30567 = nil;
v_30546:
    goto v_30538;
    v_30567 = nil;
v_30538:
    return onevalue(v_30567);
}



// Code for coeffs!-to!-form1

static LispObject CC_coeffsKtoKform1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30602, v_30603, v_30604;
    LispObject fn;
    LispObject v_30538, v_30537, v_30536;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "coeffs-to-form1");
    va_start(aa, nargs);
    v_30536 = va_arg(aa, LispObject);
    v_30537 = va_arg(aa, LispObject);
    v_30538 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30538,v_30537,v_30536);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30536,v_30537,v_30538);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_30602 = v_30538;
    stack[-2] = v_30537;
    stack[-3] = v_30536;
// end of prologue
// Binding d
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = v_30602; // d
    goto v_30553;
v_30549:
    v_30603 = qvalue(elt(env, 1)); // d
    goto v_30550;
v_30551:
    v_30602 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30552;
v_30553:
    goto v_30549;
v_30550:
    goto v_30551;
v_30552:
    v_30602 = (LispObject)greaterp2(v_30603, v_30602);
    v_30602 = v_30602 ? lisp_true : nil;
    env = stack[-5];
    if (v_30602 == nil) goto v_30547;
    goto v_30563;
v_30557:
    v_30602 = stack[-3];
    stack[-1] = qcdr(v_30602);
    goto v_30558;
v_30559:
    stack[0] = stack[-2];
    goto v_30560;
v_30561:
    v_30602 = qvalue(elt(env, 1)); // d
    v_30602 = sub1(v_30602);
    env = stack[-5];
    goto v_30562;
v_30563:
    goto v_30557;
v_30558:
    goto v_30559;
v_30560:
    goto v_30561;
v_30562:
    v_30602 = CC_coeffsKtoKform1(elt(env, 0), 3, stack[-1], stack[0], v_30602);
    env = stack[-5];
    stack[0] = v_30602;
    v_30602 = stack[-3];
    v_30602 = qcar(v_30602);
    if (v_30602 == nil) goto v_30573;
    goto v_30583;
v_30577:
    goto v_30589;
v_30585:
    v_30603 = stack[-2];
    goto v_30586;
v_30587:
    v_30602 = qvalue(elt(env, 1)); // d
    goto v_30588;
v_30589:
    goto v_30585;
v_30586:
    goto v_30587;
v_30588:
    fn = elt(env, 2); // to
    v_30604 = (*qfn2(fn))(fn, v_30603, v_30602);
    env = stack[-5];
    goto v_30578;
v_30579:
    v_30602 = stack[-3];
    v_30603 = qcar(v_30602);
    goto v_30580;
v_30581:
    v_30602 = stack[0];
    goto v_30582;
v_30583:
    goto v_30577;
v_30578:
    goto v_30579;
v_30580:
    goto v_30581;
v_30582:
    v_30602 = acons(v_30604, v_30603, v_30602);
    goto v_30571;
v_30573:
    v_30602 = stack[0];
    goto v_30571;
    v_30602 = nil;
v_30571:
    goto v_30545;
v_30547:
    v_30602 = stack[-3];
    v_30602 = qcar(v_30602);
    goto v_30545;
    v_30602 = nil;
v_30545:
    ;}  // end of a binding scope
    return onevalue(v_30602);
}



// Code for small!-random!-number

static LispObject CC_smallKrandomKnumber(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30623, v_30624;
    LispObject fn;
    argcheck(nargs, 0, "small-random-number");
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
    goto v_30544;
v_30540:
    fn = elt(env, 4); // next!-random!-number
    v_30624 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_30541;
v_30542:
    v_30623 = (LispObject)16000+TAG_FIXNUM; // 1000
    goto v_30543;
v_30544:
    goto v_30540;
v_30541:
    goto v_30542;
v_30543:
    v_30623 = Cremainder(v_30624, v_30623);
    env = stack[-3];
    stack[-2] = v_30623;
    goto v_30552;
v_30548:
    goto v_30558;
v_30554:
    fn = elt(env, 4); // next!-random!-number
    v_30624 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_30555;
v_30556:
    v_30623 = (LispObject)16000+TAG_FIXNUM; // 1000
    goto v_30557;
v_30558:
    goto v_30554;
v_30555:
    goto v_30556;
v_30557:
    stack[0] = Cremainder(v_30624, v_30623);
    env = stack[-3];
    goto v_30549;
v_30550:
    goto v_30566;
v_30562:
    v_30624 = (LispObject)16000+TAG_FIXNUM; // 1000
    goto v_30563;
v_30564:
    v_30623 = stack[-2];
    goto v_30565;
v_30566:
    goto v_30562;
v_30563:
    goto v_30564;
v_30565:
    v_30623 = times2(v_30624, v_30623);
    env = stack[-3];
    goto v_30551;
v_30552:
    goto v_30548;
v_30549:
    goto v_30550;
v_30551:
    v_30623 = plus2(stack[0], v_30623);
    env = stack[-3];
    stack[-2] = v_30623;
    goto v_30578;
v_30574:
    v_30624 = stack[-2];
    goto v_30575;
v_30576:
    v_30623 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30577;
v_30578:
    goto v_30574;
v_30575:
    goto v_30576;
v_30577:
    v_30623 = (LispObject)lessp2(v_30624, v_30623);
    v_30623 = v_30623 ? lisp_true : nil;
    env = stack[-3];
    if (v_30623 == nil) goto v_30572;
    goto v_30586;
v_30582:
    v_30624 = stack[-2];
    goto v_30583;
v_30584:
    v_30623 = (LispObject)16000000+TAG_FIXNUM; // 1000000
    goto v_30585;
v_30586:
    goto v_30582;
v_30583:
    goto v_30584;
v_30585:
    v_30623 = plus2(v_30624, v_30623);
    env = stack[-3];
    stack[-2] = v_30623;
    goto v_30570;
v_30572:
v_30570:
    goto v_30594;
v_30590:
    stack[-1] = elt(env, 1); // 1.0
    goto v_30591;
v_30592:
    goto v_30601;
v_30597:
    stack[0] = elt(env, 2); // 1.5
    goto v_30598;
v_30599:
    goto v_30608;
v_30604:
    v_30623 = stack[-2];
    v_30624 = Lfloat(nil, v_30623);
    env = stack[-3];
    goto v_30605;
v_30606:
    v_30623 = elt(env, 3); // 1.0e+06
    goto v_30607;
v_30608:
    goto v_30604;
v_30605:
    goto v_30606;
v_30607:
    v_30623 = quot2(v_30624, v_30623);
    env = stack[-3];
    goto v_30600;
v_30601:
    goto v_30597;
v_30598:
    goto v_30599;
v_30600:
    v_30623 = times2(stack[0], v_30623);
    env = stack[-3];
    goto v_30593;
v_30594:
    goto v_30590;
v_30591:
    goto v_30592;
v_30593:
    v_30623 = plus2(stack[-1], v_30623);
    env = stack[-3];
    stack[-2] = v_30623;
    goto v_30617;
v_30613:
    v_30624 = stack[-2];
    goto v_30614;
v_30615:
    v_30623 = stack[-2];
    goto v_30616;
v_30617:
    goto v_30613;
v_30614:
    goto v_30615;
v_30616:
    v_30623 = times2(v_30624, v_30623);
    env = stack[-3];
    stack[-2] = v_30623;
    v_30623 = stack[-2];
    fn = elt(env, 5); // exp
    v_30623 = (*qfn1(fn))(fn, v_30623);
        return Ltruncate(nil, v_30623);
    return onevalue(v_30623);
}



// Code for quotf!*

static LispObject CC_quotfH(LispObject env,
                         LispObject v_30535, LispObject v_30536)
{
    env = qenv(env);
    LispObject v_30601, v_30602, v_30603;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30535,v_30536);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30536;
    stack[-1] = v_30535;
// end of prologue
    v_30601 = stack[-1];
    if (v_30601 == nil) goto v_30540;
    else goto v_30541;
v_30540:
    v_30601 = nil;
    goto v_30539;
v_30541:
    goto v_30551;
v_30547:
    v_30602 = stack[-1];
    goto v_30548;
v_30549:
    v_30601 = stack[0];
    goto v_30550;
v_30551:
    goto v_30547;
v_30548:
    goto v_30549;
v_30550:
    fn = elt(env, 2); // quotf
    v_30601 = (*qfn2(fn))(fn, v_30602, v_30601);
    env = stack[-2];
    v_30602 = v_30601;
    v_30601 = v_30602;
    if (v_30601 == nil) goto v_30558;
    v_30601 = v_30602;
    goto v_30556;
v_30558:
    goto v_30569;
v_30565:
    v_30602 = stack[-1];
    goto v_30566;
v_30567:
    v_30601 = stack[0];
    goto v_30568;
v_30569:
    goto v_30565;
v_30566:
    goto v_30567;
v_30568:
    v_30601 = cons(v_30602, v_30601);
    env = stack[-2];
    fn = elt(env, 3); // rationalizesq
    v_30601 = (*qfn1(fn))(fn, v_30601);
    env = stack[-2];
    v_30603 = v_30601;
    goto v_30581;
v_30577:
    v_30601 = v_30603;
    v_30602 = qcdr(v_30601);
    goto v_30578;
v_30579:
    v_30601 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30580;
v_30581:
    goto v_30577;
v_30578:
    goto v_30579;
v_30580:
    if (v_30602 == v_30601) goto v_30575;
    else goto v_30576;
v_30575:
    v_30601 = v_30603;
    v_30601 = qcar(v_30601);
    goto v_30574;
v_30576:
    goto v_30597;
v_30591:
    v_30603 = elt(env, 1); // "DIVISION FAILED"
    goto v_30592;
v_30593:
    v_30602 = stack[-1];
    goto v_30594;
v_30595:
    v_30601 = stack[0];
    goto v_30596;
v_30597:
    goto v_30591;
v_30592:
    goto v_30593;
v_30594:
    goto v_30595;
v_30596:
    v_30601 = list3(v_30603, v_30602, v_30601);
    env = stack[-2];
    {
        fn = elt(env, 4); // errach
        return (*qfn1(fn))(fn, v_30601);
    }
    v_30601 = nil;
v_30574:
    goto v_30556;
    v_30601 = nil;
v_30556:
    goto v_30539;
    v_30601 = nil;
v_30539:
    return onevalue(v_30601);
}



// Code for vsl_boundtype1

static LispObject CC_vsl_boundtype1(LispObject env,
                         LispObject v_30535, LispObject v_30536)
{
    env = qenv(env);
    LispObject v_30585, v_30586, v_30587, v_30588;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30535,v_30536);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30588 = v_30536;
    v_30587 = v_30535;
// end of prologue
v_30540:
    v_30585 = v_30587;
    if (!consp(v_30585)) goto v_30547;
    else goto v_30548;
v_30547:
    v_30585 = lisp_true;
    goto v_30546;
v_30548:
    v_30585 = v_30587;
    v_30585 = qcar(v_30585);
    v_30585 = (consp(v_30585) ? nil : lisp_true);
    goto v_30546;
    v_30585 = nil;
v_30546:
    if (v_30585 == nil) goto v_30544;
    v_30585 = nil;
    goto v_30539;
v_30544:
    goto v_30563;
v_30559:
    v_30585 = v_30587;
    v_30585 = qcar(v_30585);
    v_30585 = qcar(v_30585);
    v_30586 = qcar(v_30585);
    goto v_30560;
v_30561:
    v_30585 = v_30588;
    goto v_30562;
v_30563:
    goto v_30559;
v_30560:
    goto v_30561;
v_30562:
    if (v_30586 == v_30585) goto v_30557;
    else goto v_30558;
v_30557:
    v_30585 = v_30587;
    v_30585 = qcar(v_30585);
    v_30585 = qcdr(v_30585);
    fn = elt(env, 3); // minusf
    v_30585 = (*qfn1(fn))(fn, v_30585);
    env = stack[0];
    if (v_30585 == nil) goto v_30572;
    v_30585 = elt(env, 1); // ub
    goto v_30539;
v_30572:
    v_30585 = elt(env, 2); // lb
    goto v_30539;
    goto v_30542;
v_30558:
    v_30585 = v_30587;
    v_30585 = qcdr(v_30585);
    v_30587 = v_30585;
    goto v_30540;
v_30542:
    v_30585 = nil;
v_30539:
    return onevalue(v_30585);
}



// Code for ps!:value

static LispObject CC_psTvalue(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30586, v_30587, v_30588;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30588 = v_30535;
// end of prologue
    v_30586 = v_30588;
    if (!consp(v_30586)) goto v_30543;
    else goto v_30544;
v_30543:
    v_30586 = lisp_true;
    goto v_30542;
v_30544:
    goto v_30557;
v_30553:
    v_30586 = v_30588;
    v_30587 = qcar(v_30586);
    goto v_30554;
v_30555:
    v_30586 = elt(env, 1); // !:ps!:
    goto v_30556;
v_30557:
    goto v_30553;
v_30554:
    goto v_30555;
v_30556:
    if (v_30587 == v_30586) goto v_30552;
    v_30586 = v_30588;
    v_30586 = qcar(v_30586);
    if (!symbolp(v_30586)) v_30586 = nil;
    else { v_30586 = qfastgets(v_30586);
           if (v_30586 != nil) { v_30586 = elt(v_30586, 8); // dname
#ifdef RECORD_GET
             if (v_30586 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_30586 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_30586 == SPID_NOPROP) v_30586 = nil; }}
#endif
    goto v_30550;
v_30552:
    v_30586 = nil;
    goto v_30550;
    v_30586 = nil;
v_30550:
    goto v_30542;
    v_30586 = nil;
v_30542:
    if (v_30586 == nil) goto v_30540;
    v_30586 = v_30588;
    if (v_30586 == nil) goto v_30570;
    v_30586 = v_30588;
    goto v_30568;
v_30570:
    v_30586 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30568;
    v_30586 = nil;
v_30568:
    goto v_30538;
v_30540:
    goto v_30583;
v_30579:
    v_30587 = v_30588;
    goto v_30580;
v_30581:
    v_30586 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_30582;
v_30583:
    goto v_30579;
v_30580:
    goto v_30581;
v_30582:
    {
        fn = elt(env, 2); // ps!:getv
        return (*qfn2(fn))(fn, v_30587, v_30586);
    }
    v_30586 = nil;
v_30538:
    return onevalue(v_30586);
}



// Code for ldf!-spf!-var

static LispObject CC_ldfKspfKvar(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30642, v_30643;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30535);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_30642 = v_30535;
// end of prologue
    v_30643 = nil;
    stack[-3] = nil;
    stack[-1] = v_30642;
v_30544:
    v_30642 = stack[-1];
    if (v_30642 == nil) goto v_30548;
    else goto v_30549;
v_30548:
    goto v_30543;
v_30549:
    v_30642 = stack[-1];
    v_30642 = qcar(v_30642);
    goto v_30560;
v_30556:
    stack[0] = v_30643;
    goto v_30557;
v_30558:
    v_30642 = qcdr(v_30642);
    fn = elt(env, 3); // kernels
    v_30642 = (*qfn1(fn))(fn, v_30642);
    env = stack[-4];
    goto v_30559;
v_30560:
    goto v_30556;
v_30557:
    goto v_30558;
v_30559:
    v_30642 = Lappend(nil, stack[0], v_30642);
    env = stack[-4];
    v_30643 = v_30642;
    v_30642 = stack[-1];
    v_30642 = qcdr(v_30642);
    stack[-1] = v_30642;
    goto v_30544;
v_30543:
    v_30642 = v_30643;
    fn = elt(env, 4); // makeset
    v_30642 = (*qfn1(fn))(fn, v_30642);
    env = stack[-4];
    fn = elt(env, 5); // prlist
    v_30642 = (*qfn1(fn))(fn, v_30642);
    env = stack[-4];
    stack[-2] = v_30642;
v_30570:
    v_30642 = stack[-2];
    if (v_30642 == nil) goto v_30576;
    else goto v_30577;
v_30576:
    goto v_30569;
v_30577:
    v_30642 = stack[-2];
    v_30642 = qcar(v_30642);
    stack[-1] = v_30642;
    goto v_30596;
v_30592:
    v_30643 = stack[-1];
    goto v_30593;
v_30594:
    v_30642 = elt(env, 1); // x
    goto v_30595;
v_30596:
    goto v_30592;
v_30593:
    goto v_30594;
v_30595:
    if (!consp(v_30643)) goto v_30589;
    v_30643 = qcar(v_30643);
    if (v_30643 == v_30642) goto v_30590;
v_30589:
    goto v_30604;
v_30600:
    v_30643 = stack[-1];
    goto v_30601;
v_30602:
    v_30642 = elt(env, 2); // u
    goto v_30603;
v_30604:
    goto v_30600;
v_30601:
    goto v_30602;
v_30603:
    v_30642 = Leqcar(nil, v_30643, v_30642);
    env = stack[-4];
    v_30642 = (v_30642 == nil ? lisp_true : nil);
    goto v_30588;
v_30590:
    v_30642 = nil;
    goto v_30588;
    v_30642 = nil;
v_30588:
    if (v_30642 == nil) goto v_30586;
    goto v_30618;
v_30612:
    goto v_30624;
v_30620:
    v_30643 = elt(env, 1); // x
    goto v_30621;
v_30622:
    v_30642 = stack[-1];
    v_30642 = qcdr(v_30642);
    goto v_30623;
v_30624:
    goto v_30620;
v_30621:
    goto v_30622;
v_30623:
    fn = elt(env, 6); // sacar
    stack[0] = (*qfn2(fn))(fn, v_30643, v_30642);
    env = stack[-4];
    goto v_30613;
v_30614:
    goto v_30633;
v_30629:
    v_30643 = elt(env, 2); // u
    goto v_30630;
v_30631:
    v_30642 = stack[-1];
    v_30642 = qcdr(v_30642);
    goto v_30632;
v_30633:
    goto v_30629;
v_30630:
    goto v_30631;
v_30632:
    fn = elt(env, 6); // sacar
    v_30643 = (*qfn2(fn))(fn, v_30643, v_30642);
    env = stack[-4];
    goto v_30615;
v_30616:
    v_30642 = stack[-3];
    goto v_30617;
v_30618:
    goto v_30612;
v_30613:
    goto v_30614;
v_30615:
    goto v_30616;
v_30617:
    fn = elt(env, 7); // appends
    v_30642 = (*qfnn(fn))(fn, 3, stack[0], v_30643, v_30642);
    env = stack[-4];
    stack[-3] = v_30642;
    goto v_30584;
v_30586:
v_30584:
    v_30642 = stack[-2];
    v_30642 = qcdr(v_30642);
    stack[-2] = v_30642;
    goto v_30570;
v_30569:
    v_30642 = stack[-3];
    {
        fn = elt(env, 4); // makeset
        return (*qfn1(fn))(fn, v_30642);
    }
    return onevalue(v_30642);
}



// Code for al1_defined_vertex

static LispObject CC_al1_defined_vertex(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30619, v_30620;
    LispObject fn;
    LispObject v_30538, v_30537, v_30536, v_30535;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "al1_defined_vertex");
    va_start(aa, nargs);
    v_30535 = va_arg(aa, LispObject);
    v_30536 = va_arg(aa, LispObject);
    v_30537 = va_arg(aa, LispObject);
    v_30538 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_30538,v_30537,v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_30535,v_30536,v_30537,v_30538);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_30538;
    stack[-1] = v_30537;
    stack[-2] = v_30536;
    stack[-3] = v_30535;
// end of prologue
v_30543:
    v_30619 = stack[-3];
    if (v_30619 == nil) goto v_30546;
    else goto v_30547;
v_30546:
    v_30619 = stack[-2];
    if (v_30619 == nil) goto v_30551;
    else goto v_30552;
v_30551:
    v_30619 = lisp_true;
    goto v_30542;
v_30552:
    goto v_30562;
v_30558:
    v_30620 = stack[-2];
    goto v_30559;
v_30560:
    v_30619 = stack[-1];
    goto v_30561;
v_30562:
    goto v_30558;
v_30559:
    goto v_30560;
v_30561:
    {
        fn = elt(env, 1); // re_parents
        return (*qfn2(fn))(fn, v_30620, v_30619);
    }
    goto v_30545;
v_30547:
    goto v_30572;
v_30568:
    v_30619 = stack[-3];
    v_30620 = qcar(v_30619);
    goto v_30569;
v_30570:
    v_30619 = stack[0];
    goto v_30571;
v_30572:
    goto v_30568;
v_30569:
    goto v_30570;
v_30571:
    fn = elt(env, 2); // defined_edge
    v_30619 = (*qfn2(fn))(fn, v_30620, v_30619);
    env = stack[-5];
    if (v_30619 == nil) goto v_30566;
    goto v_30581;
v_30577:
    v_30620 = stack[-2];
    goto v_30578;
v_30579:
    v_30619 = stack[-3];
    v_30619 = qcdr(v_30619);
    goto v_30580;
v_30581:
    goto v_30577;
v_30578:
    goto v_30579;
v_30580:
    v_30619 = Lnconc(nil, v_30620, v_30619);
    env = stack[-5];
    stack[-4] = v_30619;
    v_30619 = nil;
    stack[-2] = v_30619;
    goto v_30591;
v_30587:
    v_30619 = stack[-3];
    v_30620 = qcar(v_30619);
    goto v_30588;
v_30589:
    v_30619 = stack[-1];
    goto v_30590;
v_30591:
    goto v_30587;
v_30588:
    goto v_30589;
v_30590:
    v_30619 = cons(v_30620, v_30619);
    env = stack[-5];
    stack[-1] = v_30619;
    goto v_30600;
v_30596:
    v_30619 = stack[-3];
    v_30620 = qcar(v_30619);
    goto v_30597;
v_30598:
    v_30619 = stack[0];
    goto v_30599;
v_30600:
    goto v_30596;
v_30597:
    goto v_30598;
v_30599:
    v_30619 = cons(v_30620, v_30619);
    env = stack[-5];
    stack[0] = v_30619;
    v_30619 = stack[-4];
    stack[-3] = v_30619;
    goto v_30543;
v_30566:
    v_30619 = stack[-3];
    v_30619 = qcdr(v_30619);
    stack[-4] = v_30619;
    goto v_30614;
v_30610:
    v_30619 = stack[-3];
    v_30620 = qcar(v_30619);
    goto v_30611;
v_30612:
    v_30619 = stack[-2];
    goto v_30613;
v_30614:
    goto v_30610;
v_30611:
    goto v_30612;
v_30613:
    v_30619 = cons(v_30620, v_30619);
    env = stack[-5];
    stack[-2] = v_30619;
    v_30619 = stack[-4];
    stack[-3] = v_30619;
    goto v_30543;
v_30545:
    v_30619 = nil;
v_30542:
    return onevalue(v_30619);
}



// Code for dp!=comp

static LispObject CC_dpMcomp(LispObject env,
                         LispObject v_30535, LispObject v_30536)
{
    env = qenv(env);
    LispObject v_30576, v_30577;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30535,v_30536);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30536;
    stack[-1] = v_30535;
// end of prologue
    stack[-2] = nil;
v_30541:
    v_30576 = stack[0];
    if (v_30576 == nil) goto v_30544;
    else goto v_30545;
v_30544:
    v_30576 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_30576);
    }
v_30545:
    goto v_30556;
v_30552:
    v_30576 = stack[0];
    fn = elt(env, 2); // dp_lmon
    v_30576 = (*qfn1(fn))(fn, v_30576);
    env = stack[-3];
    fn = elt(env, 3); // mo_comp
    v_30577 = (*qfn1(fn))(fn, v_30576);
    env = stack[-3];
    goto v_30553;
v_30554:
    v_30576 = stack[-1];
    goto v_30555;
v_30556:
    goto v_30552;
v_30553:
    goto v_30554;
v_30555:
    v_30576 = Leqn(nil, v_30577, v_30576);
    env = stack[-3];
    if (v_30576 == nil) goto v_30550;
    goto v_30566;
v_30562:
    v_30576 = stack[0];
    v_30577 = qcar(v_30576);
    goto v_30563;
v_30564:
    v_30576 = stack[-2];
    goto v_30565;
v_30566:
    goto v_30562;
v_30563:
    goto v_30564;
v_30565:
    v_30576 = cons(v_30577, v_30576);
    env = stack[-3];
    stack[-2] = v_30576;
    v_30576 = stack[0];
    v_30576 = qcdr(v_30576);
    stack[0] = v_30576;
    goto v_30541;
v_30550:
    v_30576 = stack[0];
    v_30576 = qcdr(v_30576);
    stack[0] = v_30576;
    goto v_30541;
    v_30576 = nil;
    return onevalue(v_30576);
}



// Code for simp!-prop!-form

static LispObject CC_simpKpropKform(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30827, v_30828, v_30829;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30535);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    v_30828 = v_30535;
// end of prologue
    goto v_30545;
v_30541:
    v_30829 = v_30828;
    goto v_30542;
v_30543:
    v_30827 = elt(env, 1); // (nil)
    goto v_30544;
v_30545:
    goto v_30541;
v_30542:
    goto v_30543;
v_30544:
    if (equal(v_30829, v_30827)) goto v_30539;
    else goto v_30540;
v_30539:
    v_30827 = qvalue(elt(env, 2)); // !'true
    goto v_30538;
v_30540:
    v_30827 = v_30828;
    stack[-7] = v_30827;
    v_30827 = stack[-7];
    if (v_30827 == nil) goto v_30560;
    else goto v_30561;
v_30560:
    v_30827 = nil;
    goto v_30555;
v_30561:
    v_30827 = stack[-7];
    v_30827 = qcar(v_30827);
    stack[-3] = v_30827;
    v_30827 = stack[-3];
    if (v_30827 == nil) goto v_30577;
    else goto v_30578;
v_30577:
    v_30827 = nil;
    goto v_30572;
v_30578:
    v_30827 = stack[-3];
    v_30827 = qcar(v_30827);
    v_30829 = v_30827;
    goto v_30594;
v_30590:
    v_30828 = v_30829;
    goto v_30591;
v_30592:
    v_30827 = elt(env, 3); // not_prop!*
    goto v_30593;
v_30594:
    goto v_30590;
v_30591:
    goto v_30592;
v_30593:
    if (!consp(v_30828)) goto v_30588;
    v_30828 = qcar(v_30828);
    if (v_30828 == v_30827) goto v_30587;
    else goto v_30588;
v_30587:
    goto v_30602;
v_30598:
    v_30827 = elt(env, 4); // not
    goto v_30599;
v_30600:
    v_30828 = v_30829;
    v_30828 = qcdr(v_30828);
    v_30828 = qcar(v_30828);
    goto v_30601;
v_30602:
    goto v_30598;
v_30599:
    goto v_30600;
v_30601:
    v_30827 = list2(v_30827, v_30828);
    env = stack[-8];
    goto v_30586;
v_30588:
    v_30827 = v_30829;
    v_30827 = qcdr(v_30827);
    v_30827 = qcar(v_30827);
    goto v_30586;
    v_30827 = nil;
v_30586:
    v_30827 = ncons(v_30827);
    env = stack[-8];
    stack[-1] = v_30827;
    stack[-2] = v_30827;
v_30573:
    v_30827 = stack[-3];
    v_30827 = qcdr(v_30827);
    stack[-3] = v_30827;
    v_30827 = stack[-3];
    if (v_30827 == nil) goto v_30616;
    else goto v_30617;
v_30616:
    v_30827 = stack[-2];
    goto v_30572;
v_30617:
    goto v_30625;
v_30621:
    stack[0] = stack[-1];
    goto v_30622;
v_30623:
    v_30827 = stack[-3];
    v_30827 = qcar(v_30827);
    v_30829 = v_30827;
    goto v_30640;
v_30636:
    v_30828 = v_30829;
    goto v_30637;
v_30638:
    v_30827 = elt(env, 3); // not_prop!*
    goto v_30639;
v_30640:
    goto v_30636;
v_30637:
    goto v_30638;
v_30639:
    if (!consp(v_30828)) goto v_30634;
    v_30828 = qcar(v_30828);
    if (v_30828 == v_30827) goto v_30633;
    else goto v_30634;
v_30633:
    goto v_30648;
v_30644:
    v_30827 = elt(env, 4); // not
    goto v_30645;
v_30646:
    v_30828 = v_30829;
    v_30828 = qcdr(v_30828);
    v_30828 = qcar(v_30828);
    goto v_30647;
v_30648:
    goto v_30644;
v_30645:
    goto v_30646;
v_30647:
    v_30827 = list2(v_30827, v_30828);
    env = stack[-8];
    goto v_30632;
v_30634:
    v_30827 = v_30829;
    v_30827 = qcdr(v_30827);
    v_30827 = qcar(v_30827);
    goto v_30632;
    v_30827 = nil;
v_30632:
    v_30827 = ncons(v_30827);
    env = stack[-8];
    goto v_30624;
v_30625:
    goto v_30621;
v_30622:
    goto v_30623;
v_30624:
    v_30827 = Lrplacd(nil, stack[0], v_30827);
    env = stack[-8];
    v_30827 = stack[-1];
    v_30827 = qcdr(v_30827);
    stack[-1] = v_30827;
    goto v_30573;
v_30572:
    v_30828 = v_30827;
    v_30828 = qcdr(v_30828);
    if (v_30828 == nil) goto v_30663;
    goto v_30671;
v_30667:
    v_30828 = qvalue(elt(env, 5)); // !'and
    goto v_30668;
v_30669:
    goto v_30670;
v_30671:
    goto v_30667;
v_30668:
    goto v_30669;
v_30670:
    v_30827 = cons(v_30828, v_30827);
    env = stack[-8];
    goto v_30661;
v_30663:
    v_30827 = qcar(v_30827);
    goto v_30661;
    v_30827 = nil;
v_30661:
    v_30827 = ncons(v_30827);
    env = stack[-8];
    stack[-5] = v_30827;
    stack[-6] = v_30827;
v_30556:
    v_30827 = stack[-7];
    v_30827 = qcdr(v_30827);
    stack[-7] = v_30827;
    v_30827 = stack[-7];
    if (v_30827 == nil) goto v_30682;
    else goto v_30683;
v_30682:
    v_30827 = stack[-6];
    goto v_30555;
v_30683:
    goto v_30691;
v_30687:
    stack[-4] = stack[-5];
    goto v_30688;
v_30689:
    v_30827 = stack[-7];
    v_30827 = qcar(v_30827);
    stack[-3] = v_30827;
    v_30827 = stack[-3];
    if (v_30827 == nil) goto v_30706;
    else goto v_30707;
v_30706:
    v_30827 = nil;
    goto v_30701;
v_30707:
    v_30827 = stack[-3];
    v_30827 = qcar(v_30827);
    v_30829 = v_30827;
    goto v_30723;
v_30719:
    v_30828 = v_30829;
    goto v_30720;
v_30721:
    v_30827 = elt(env, 3); // not_prop!*
    goto v_30722;
v_30723:
    goto v_30719;
v_30720:
    goto v_30721;
v_30722:
    if (!consp(v_30828)) goto v_30717;
    v_30828 = qcar(v_30828);
    if (v_30828 == v_30827) goto v_30716;
    else goto v_30717;
v_30716:
    goto v_30731;
v_30727:
    v_30827 = elt(env, 4); // not
    goto v_30728;
v_30729:
    v_30828 = v_30829;
    v_30828 = qcdr(v_30828);
    v_30828 = qcar(v_30828);
    goto v_30730;
v_30731:
    goto v_30727;
v_30728:
    goto v_30729;
v_30730:
    v_30827 = list2(v_30827, v_30828);
    env = stack[-8];
    goto v_30715;
v_30717:
    v_30827 = v_30829;
    v_30827 = qcdr(v_30827);
    v_30827 = qcar(v_30827);
    goto v_30715;
    v_30827 = nil;
v_30715:
    v_30827 = ncons(v_30827);
    env = stack[-8];
    stack[-1] = v_30827;
    stack[-2] = v_30827;
v_30702:
    v_30827 = stack[-3];
    v_30827 = qcdr(v_30827);
    stack[-3] = v_30827;
    v_30827 = stack[-3];
    if (v_30827 == nil) goto v_30745;
    else goto v_30746;
v_30745:
    v_30827 = stack[-2];
    goto v_30701;
v_30746:
    goto v_30754;
v_30750:
    stack[0] = stack[-1];
    goto v_30751;
v_30752:
    v_30827 = stack[-3];
    v_30827 = qcar(v_30827);
    v_30829 = v_30827;
    goto v_30769;
v_30765:
    v_30828 = v_30829;
    goto v_30766;
v_30767:
    v_30827 = elt(env, 3); // not_prop!*
    goto v_30768;
v_30769:
    goto v_30765;
v_30766:
    goto v_30767;
v_30768:
    if (!consp(v_30828)) goto v_30763;
    v_30828 = qcar(v_30828);
    if (v_30828 == v_30827) goto v_30762;
    else goto v_30763;
v_30762:
    goto v_30777;
v_30773:
    v_30827 = elt(env, 4); // not
    goto v_30774;
v_30775:
    v_30828 = v_30829;
    v_30828 = qcdr(v_30828);
    v_30828 = qcar(v_30828);
    goto v_30776;
v_30777:
    goto v_30773;
v_30774:
    goto v_30775;
v_30776:
    v_30827 = list2(v_30827, v_30828);
    env = stack[-8];
    goto v_30761;
v_30763:
    v_30827 = v_30829;
    v_30827 = qcdr(v_30827);
    v_30827 = qcar(v_30827);
    goto v_30761;
    v_30827 = nil;
v_30761:
    v_30827 = ncons(v_30827);
    env = stack[-8];
    goto v_30753;
v_30754:
    goto v_30750;
v_30751:
    goto v_30752;
v_30753:
    v_30827 = Lrplacd(nil, stack[0], v_30827);
    env = stack[-8];
    v_30827 = stack[-1];
    v_30827 = qcdr(v_30827);
    stack[-1] = v_30827;
    goto v_30702;
v_30701:
    v_30828 = v_30827;
    v_30828 = qcdr(v_30828);
    if (v_30828 == nil) goto v_30792;
    goto v_30800;
v_30796:
    v_30828 = qvalue(elt(env, 5)); // !'and
    goto v_30797;
v_30798:
    goto v_30799;
v_30800:
    goto v_30796;
v_30797:
    goto v_30798;
v_30799:
    v_30827 = cons(v_30828, v_30827);
    env = stack[-8];
    goto v_30790;
v_30792:
    v_30827 = qcar(v_30827);
    goto v_30790;
    v_30827 = nil;
v_30790:
    v_30827 = ncons(v_30827);
    env = stack[-8];
    goto v_30690;
v_30691:
    goto v_30687;
v_30688:
    goto v_30689;
v_30690:
    v_30827 = Lrplacd(nil, stack[-4], v_30827);
    env = stack[-8];
    v_30827 = stack[-5];
    v_30827 = qcdr(v_30827);
    stack[-5] = v_30827;
    goto v_30556;
v_30555:
    v_30828 = v_30827;
    v_30827 = v_30828;
    v_30827 = qcdr(v_30827);
    if (v_30827 == nil) goto v_30812;
    goto v_30820;
v_30816:
    v_30827 = qvalue(elt(env, 6)); // !'or
    goto v_30817;
v_30818:
    goto v_30819;
v_30820:
    goto v_30816;
v_30817:
    goto v_30818;
v_30819:
    return cons(v_30827, v_30828);
v_30812:
    v_30827 = v_30828;
    v_30827 = qcar(v_30827);
    goto v_30810;
    v_30827 = nil;
v_30810:
    goto v_30538;
    v_30827 = nil;
v_30538:
    return onevalue(v_30827);
}



// Code for can_rep_cell

static LispObject CC_can_rep_cell(LispObject env,
                         LispObject v_30535, LispObject v_30536)
{
    env = qenv(env);
    LispObject v_30556, v_30557, v_30558;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30535,v_30536);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30558 = v_30536;
    v_30556 = v_30535;
// end of prologue
    goto v_30542;
v_30538:
    goto v_30547;
v_30543:
    v_30556 = qcdr(v_30556);
    v_30557 = qcar(v_30556);
    goto v_30544;
v_30545:
    v_30556 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30546;
v_30547:
    goto v_30543;
v_30544:
    goto v_30545;
v_30546:
    stack[0] = *(LispObject *)((char *)v_30557 + (CELL-TAG_VECTOR) + (((intptr_t)v_30556-TAG_FIXNUM)/(16/CELL)));
    goto v_30539;
v_30540:
    v_30556 = v_30558;
    v_30556 = sub1(v_30556);
    goto v_30541;
v_30542:
    goto v_30538;
v_30539:
    goto v_30540;
v_30541:
    v_30556 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_30556-TAG_FIXNUM)/(16/CELL)));
    return onevalue(v_30556);
}



// Code for simpdot

static LispObject CC_simpdot(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30545, v_30546;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30545 = v_30535;
// end of prologue
    goto v_30542;
v_30538:
    v_30546 = v_30545;
    goto v_30539;
v_30540:
    v_30545 = elt(env, 1); // dotord
    goto v_30541;
v_30542:
    goto v_30538;
v_30539:
    goto v_30540;
v_30541:
    {
        fn = elt(env, 2); // mkvarg
        return (*qfn2(fn))(fn, v_30546, v_30545);
    }
}



// Code for ofsf_bestgaussp

static LispObject CC_ofsf_bestgaussp(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30620, v_30621, v_30622;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30622 = v_30535;
// end of prologue
    goto v_30545;
v_30541:
    v_30620 = v_30622;
    v_30621 = qcar(v_30620);
    goto v_30542;
v_30543:
    v_30620 = elt(env, 1); // failed
    goto v_30544;
v_30545:
    goto v_30541;
v_30542:
    goto v_30543;
v_30544:
    if (v_30621 == v_30620) goto v_30540;
    goto v_30557;
v_30553:
    v_30620 = v_30622;
    v_30621 = qcar(v_30620);
    goto v_30554;
v_30555:
    v_30620 = elt(env, 2); // gignore
    goto v_30556;
v_30557:
    goto v_30553;
v_30554:
    goto v_30555;
v_30556:
    if (v_30621 == v_30620) goto v_30552;
    goto v_30569;
v_30565:
    v_30620 = v_30622;
    v_30620 = qcar(v_30620);
    v_30620 = qcdr(v_30620);
    v_30621 = qcar(v_30620);
    goto v_30566;
v_30567:
    v_30620 = elt(env, 3); // lin
    goto v_30568;
v_30569:
    goto v_30565;
v_30566:
    goto v_30567;
v_30568:
    if (v_30621 == v_30620) goto v_30563;
    else goto v_30564;
v_30563:
    goto v_30583;
v_30579:
    v_30620 = v_30622;
    v_30620 = qcar(v_30620);
    v_30620 = qcdr(v_30620);
    v_30620 = qcdr(v_30620);
    v_30620 = qcar(v_30620);
    goto v_30580;
v_30581:
    v_30621 = elt(env, 4); // con
    goto v_30582;
v_30583:
    goto v_30579;
v_30580:
    goto v_30581;
v_30582:
    if (v_30620 == v_30621) goto v_30577;
    else goto v_30578;
v_30577:
    v_30620 = v_30622;
    v_30620 = qcdr(v_30620);
    v_30620 = qcar(v_30620);
    v_30620 = qcdr(v_30620);
    if (v_30620 == nil) goto v_30592;
    else goto v_30593;
v_30592:
    v_30620 = v_30622;
    v_30620 = qcdr(v_30620);
    v_30620 = qcar(v_30620);
    v_30620 = qcar(v_30620);
    v_30620 = qcdr(v_30620);
    v_30620 = qcdr(v_30620);
    v_30620 = (v_30620 == nil ? lisp_true : nil);
    goto v_30591;
v_30593:
    v_30620 = nil;
    goto v_30591;
    v_30620 = nil;
v_30591:
    goto v_30576;
v_30578:
    v_30620 = nil;
    goto v_30576;
    v_30620 = nil;
v_30576:
    goto v_30562;
v_30564:
    v_30620 = nil;
    goto v_30562;
    v_30620 = nil;
v_30562:
    goto v_30550;
v_30552:
    v_30620 = nil;
    goto v_30550;
    v_30620 = nil;
v_30550:
    goto v_30538;
v_30540:
    v_30620 = nil;
    goto v_30538;
    v_30620 = nil;
v_30538:
    return onevalue(v_30620);
}



// Code for texexplode

static LispObject CC_texexplode(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30609, v_30610, v_30611;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30535);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30610 = v_30535;
// end of prologue
    v_30609 = v_30610;
    if (v_30609 == nil) goto v_30543;
    v_30609 = v_30610;
    if (!consp(v_30609)) goto v_30546;
    else goto v_30543;
v_30546:
    goto v_30559;
v_30555:
    v_30611 = v_30610;
    goto v_30556;
v_30557:
    v_30609 = elt(env, 1); // texname
    goto v_30558;
v_30559:
    goto v_30555;
v_30556:
    goto v_30557;
v_30558:
    v_30609 = get(v_30611, v_30609);
    env = stack[0];
    if (v_30609 == nil) goto v_30553;
    else goto v_30552;
v_30553:
    v_30609 = v_30610;
    if (!symbolp(v_30609)) v_30609 = nil;
    else { v_30609 = qfastgets(v_30609);
           if (v_30609 != nil) { v_30609 = elt(v_30609, 7); // class
#ifdef RECORD_GET
             if (v_30609 != SPID_NOPROP)
                record_get(elt(fastget_names, 7), 1);
             else record_get(elt(fastget_names, 7), 0),
                v_30609 = nil; }
           else record_get(elt(fastget_names, 7), 0); }
#else
             if (v_30609 == SPID_NOPROP) v_30609 = nil; }}
#endif
    if (v_30609 == nil) goto v_30564;
    else goto v_30565;
v_30564:
    v_30609 = nil;
    goto v_30563;
v_30565:
    v_30609 = v_30610;
    goto v_30563;
    v_30609 = nil;
v_30563:
v_30552:
    if (v_30609 == nil) goto v_30550;
    else goto v_30549;
v_30550:
    v_30609 = v_30610;
    if (is_number(v_30609)) goto v_30574;
    else goto v_30575;
v_30574:
    v_30609 = v_30610;
    v_30609 = Lexplode(nil, v_30609);
    env = stack[0];
    fn = elt(env, 3); // texcollect
    v_30609 = (*qfn1(fn))(fn, v_30609);
    env = stack[0];
    goto v_30573;
v_30575:
    v_30609 = v_30610;
    v_30609 = Lstringp(nil, v_30609);
    env = stack[0];
    if (v_30609 == nil) goto v_30581;
    v_30609 = v_30610;
    v_30609 = Lexplodec(nil, v_30609);
    env = stack[0];
    fn = elt(env, 4); // strcollect
    v_30609 = (*qfn1(fn))(fn, v_30609);
    env = stack[0];
    goto v_30573;
v_30581:
    v_30609 = v_30610;
    v_30609 = Lexplodec(nil, v_30609);
    env = stack[0];
    fn = elt(env, 3); // texcollect
    v_30609 = (*qfn1(fn))(fn, v_30609);
    env = stack[0];
    fn = elt(env, 5); // texexplist
    v_30609 = (*qfn1(fn))(fn, v_30609);
    env = stack[0];
    goto v_30573;
    v_30609 = nil;
v_30573:
v_30549:
    goto v_30541;
v_30543:
    v_30609 = nil;
v_30541:
    v_30610 = v_30609;
    v_30609 = v_30610;
    if (v_30609 == nil) goto v_30595;
    else goto v_30596;
v_30595:
    v_30609 = elt(env, 2); // ! 
    return ncons(v_30609);
v_30596:
    v_30609 = v_30610;
    if (!consp(v_30609)) goto v_30601;
    v_30609 = v_30610;
    goto v_30594;
v_30601:
    v_30609 = v_30610;
    return ncons(v_30609);
    v_30609 = nil;
v_30594:
    v_30610 = v_30609;
    v_30609 = v_30610;
    return onevalue(v_30609);
}



// Code for gigcd!:

static LispObject CC_gigcdT(LispObject env,
                         LispObject v_30535, LispObject v_30536)
{
    env = qenv(env);
    LispObject v_30562, v_30563;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30535,v_30536);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30536;
    stack[-1] = v_30535;
// end of prologue
v_30541:
    v_30562 = stack[0];
    fn = elt(env, 1); // gizerop!:
    v_30562 = (*qfn1(fn))(fn, v_30562);
    env = stack[-3];
    if (v_30562 == nil) goto v_30545;
    v_30562 = stack[-1];
    {
        fn = elt(env, 2); // fqa
        return (*qfn1(fn))(fn, v_30562);
    }
v_30545:
    v_30562 = stack[0];
    stack[-2] = v_30562;
    goto v_30558;
v_30554:
    v_30563 = stack[-1];
    goto v_30555;
v_30556:
    v_30562 = stack[0];
    goto v_30557;
v_30558:
    goto v_30554;
v_30555:
    goto v_30556;
v_30557:
    fn = elt(env, 3); // giremainder
    v_30562 = (*qfn2(fn))(fn, v_30563, v_30562);
    env = stack[-3];
    stack[0] = v_30562;
    v_30562 = stack[-2];
    stack[-1] = v_30562;
    goto v_30541;
    v_30562 = nil;
    return onevalue(v_30562);
}



// Code for simp!-sign2

static LispObject CC_simpKsign2(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30564, v_30565;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30535);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_30535;
// end of prologue
    v_30564 = stack[0];
    fn = elt(env, 2); // rd!-sign
    v_30564 = (*qfn1(fn))(fn, v_30564);
    env = stack[-1];
    v_30565 = v_30564;
    v_30564 = v_30565;
    if (v_30564 == nil) goto v_30543;
    goto v_30550;
v_30546:
    goto v_30547;
v_30548:
    v_30564 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30549;
v_30550:
    goto v_30546;
v_30547:
    goto v_30548;
v_30549:
    return cons(v_30565, v_30564);
v_30543:
    goto v_30561;
v_30557:
    v_30565 = elt(env, 1); // sign
    goto v_30558;
v_30559:
    v_30564 = stack[0];
    goto v_30560;
v_30561:
    goto v_30557;
v_30558:
    goto v_30559;
v_30560:
    v_30564 = list2(v_30565, v_30564);
    env = stack[-1];
    {
        fn = elt(env, 3); // simpiden
        return (*qfn1(fn))(fn, v_30564);
    }
    v_30564 = nil;
    return onevalue(v_30564);
}



// Code for qqe_prefix!-length

static LispObject CC_qqe_prefixKlength(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30584, v_30585, v_30586;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30535);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_30585 = v_30535;
// end of prologue
    v_30584 = (LispObject)0+TAG_FIXNUM; // 0
    v_30586 = v_30584;
    v_30584 = v_30585;
    if (v_30584 == nil) goto v_30544;
    else goto v_30545;
v_30544:
    v_30584 = nil;
    stack[0] = v_30584;
    goto v_30543;
v_30545:
    v_30584 = v_30585;
    stack[0] = v_30584;
    goto v_30543;
v_30543:
v_30554:
    v_30584 = stack[0];
    if (v_30584 == nil) goto v_30557;
    v_30584 = stack[0];
    if (!consp(v_30584)) goto v_30557;
    goto v_30558;
v_30557:
    goto v_30553;
v_30558:
    goto v_30572;
v_30568:
    v_30584 = stack[0];
    v_30585 = qcar(v_30584);
    goto v_30569;
v_30570:
    v_30584 = elt(env, 1); // (rtail ltail rhead lhead)
    goto v_30571;
v_30572:
    goto v_30568;
v_30569:
    goto v_30570;
v_30571:
    v_30584 = Lmemq(nil, v_30585, v_30584);
    if (v_30584 == nil) goto v_30567;
    v_30584 = v_30586;
    v_30584 = add1(v_30584);
    env = stack[-1];
    v_30586 = v_30584;
    goto v_30565;
v_30567:
v_30565:
    v_30584 = stack[0];
    v_30584 = qcdr(v_30584);
    v_30584 = qcar(v_30584);
    stack[0] = v_30584;
    goto v_30554;
v_30553:
    v_30584 = v_30586;
    return onevalue(v_30584);
}



// Code for transferrow1

static LispObject CC_transferrow1(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30589, v_30590;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30535);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30535;
// end of prologue
    goto v_30545;
v_30541:
    goto v_30550;
v_30546:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_30547;
v_30548:
    goto v_30557;
v_30553:
    v_30590 = qvalue(elt(env, 2)); // maxvar
    goto v_30554;
v_30555:
    v_30589 = stack[0];
    goto v_30556;
v_30557:
    goto v_30553;
v_30554:
    goto v_30555;
v_30556:
    v_30589 = plus2(v_30590, v_30589);
    env = stack[-2];
    goto v_30549;
v_30550:
    goto v_30546;
v_30547:
    goto v_30548;
v_30549:
    v_30590 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_30589-TAG_FIXNUM)/(16/CELL)));
    goto v_30542;
v_30543:
    v_30589 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_30544;
v_30545:
    goto v_30541;
v_30542:
    goto v_30543;
v_30544:
    v_30589 = *(LispObject *)((char *)v_30590 + (CELL-TAG_VECTOR) + (((intptr_t)v_30589-TAG_FIXNUM)/(16/CELL)));
    if (v_30589 == nil) goto v_30539;
    else goto v_30540;
v_30539:
    goto v_30567;
v_30563:
    goto v_30572;
v_30568:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_30569;
v_30570:
    goto v_30579;
v_30575:
    v_30590 = qvalue(elt(env, 2)); // maxvar
    goto v_30576;
v_30577:
    v_30589 = stack[0];
    goto v_30578;
v_30579:
    goto v_30575;
v_30576:
    goto v_30577;
v_30578:
    v_30589 = plus2(v_30590, v_30589);
    goto v_30571;
v_30572:
    goto v_30568;
v_30569:
    goto v_30570;
v_30571:
    v_30590 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_30589-TAG_FIXNUM)/(16/CELL)));
    goto v_30564;
v_30565:
    v_30589 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_30566;
v_30567:
    goto v_30563;
v_30564:
    goto v_30565;
v_30566:
    v_30589 = *(LispObject *)((char *)v_30590 + (CELL-TAG_VECTOR) + (((intptr_t)v_30589-TAG_FIXNUM)/(16/CELL)));
    v_30589 = (is_number(v_30589) ? lisp_true : nil);
    goto v_30538;
v_30540:
    v_30589 = nil;
    goto v_30538;
    v_30589 = nil;
v_30538:
    return onevalue(v_30589);
}



// Code for f2dip2

static LispObject CC_f2dip2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30622, v_30623, v_30624, v_30625;
    LispObject fn;
    LispObject v_30539, v_30538, v_30537, v_30536, v_30535;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "f2dip2");
    va_start(aa, nargs);
    v_30535 = va_arg(aa, LispObject);
    v_30536 = va_arg(aa, LispObject);
    v_30537 = va_arg(aa, LispObject);
    v_30538 = va_arg(aa, LispObject);
    v_30539 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_30539,v_30538,v_30537,v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_30535,v_30536,v_30537,v_30538,v_30539);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_30539;
    stack[-1] = v_30538;
    stack[-2] = v_30537;
    stack[-3] = v_30536;
    stack[-4] = v_30535;
// end of prologue
    goto v_30549;
v_30545:
    v_30623 = stack[-4];
    goto v_30546;
v_30547:
    v_30622 = qvalue(elt(env, 1)); // dipvars!*
    goto v_30548;
v_30549:
    goto v_30545;
v_30546:
    goto v_30547;
v_30548:
    v_30622 = Lmemq(nil, v_30623, v_30622);
    if (v_30622 == nil) goto v_30544;
    goto v_30562;
v_30554:
    v_30625 = stack[-1];
    goto v_30555;
v_30556:
    v_30624 = stack[-4];
    goto v_30557;
v_30558:
    v_30623 = stack[-3];
    goto v_30559;
v_30560:
    v_30622 = qvalue(elt(env, 1)); // dipvars!*
    goto v_30561;
v_30562:
    goto v_30554;
v_30555:
    goto v_30556;
v_30557:
    goto v_30558;
v_30559:
    goto v_30560;
v_30561:
    fn = elt(env, 2); // evinsert
    v_30622 = (*qfnn(fn))(fn, 4, v_30625, v_30624, v_30623, v_30622);
    env = stack[-5];
    goto v_30542;
v_30544:
    v_30622 = nil;
    goto v_30542;
    v_30622 = nil;
v_30542:
    v_30623 = v_30622;
    v_30622 = v_30623;
    if (v_30622 == nil) goto v_30574;
    v_30622 = v_30623;
    stack[-1] = v_30622;
    goto v_30572;
v_30574:
    goto v_30584;
v_30580:
    goto v_30581;
v_30582:
    goto v_30593;
v_30587:
    goto v_30599;
v_30595:
    goto v_30605;
v_30601:
    v_30623 = stack[-4];
    goto v_30602;
v_30603:
    v_30622 = stack[-3];
    goto v_30604;
v_30605:
    goto v_30601;
v_30602:
    goto v_30603;
v_30604:
    fn = elt(env, 3); // to
    v_30623 = (*qfn2(fn))(fn, v_30623, v_30622);
    env = stack[-5];
    goto v_30596;
v_30597:
    v_30622 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30598;
v_30599:
    goto v_30595;
v_30596:
    goto v_30597;
v_30598:
    v_30624 = cons(v_30623, v_30622);
    env = stack[-5];
    goto v_30588;
v_30589:
    v_30623 = nil;
    goto v_30590;
v_30591:
    v_30622 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30592;
v_30593:
    goto v_30587;
v_30588:
    goto v_30589;
v_30590:
    goto v_30591;
v_30592:
    v_30622 = acons(v_30624, v_30623, v_30622);
    env = stack[-5];
    goto v_30583;
v_30584:
    goto v_30580;
v_30581:
    goto v_30582;
v_30583:
    fn = elt(env, 4); // multsq
    v_30622 = (*qfn2(fn))(fn, stack[0], v_30622);
    env = stack[-5];
    stack[0] = v_30622;
    goto v_30572;
v_30572:
    goto v_30618;
v_30612:
    v_30624 = stack[-2];
    goto v_30613;
v_30614:
    v_30623 = stack[-1];
    goto v_30615;
v_30616:
    v_30622 = stack[0];
    goto v_30617;
v_30618:
    goto v_30612;
v_30613:
    goto v_30614;
v_30615:
    goto v_30616;
v_30617:
    {
        fn = elt(env, 5); // f2dip1
        return (*qfnn(fn))(fn, 3, v_30624, v_30623, v_30622);
    }
}



// Code for symmetrize!-inds

static LispObject CC_symmetrizeKinds(LispObject env,
                         LispObject v_30535, LispObject v_30536)
{
    env = qenv(env);
    LispObject v_30847, v_30848;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30535,v_30536);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-8] = v_30536;
    stack[-9] = v_30535;
// end of prologue
    v_30847 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-10] = v_30847;
    v_30847 = stack[-9];
    stack[-7] = v_30847;
    v_30847 = stack[-7];
    if (v_30847 == nil) goto v_30554;
    else goto v_30555;
v_30554:
    v_30847 = nil;
    goto v_30549;
v_30555:
    v_30847 = stack[-7];
    v_30847 = qcar(v_30847);
    v_30848 = v_30847;
    if (!consp(v_30848)) goto v_30564;
    else goto v_30565;
v_30564:
    goto v_30572;
v_30568:
    v_30848 = stack[-8];
    goto v_30569;
v_30570:
    goto v_30571;
v_30572:
    goto v_30568;
v_30569:
    goto v_30570;
v_30571:
    fn = elt(env, 1); // nth
    v_30847 = (*qfn2(fn))(fn, v_30848, v_30847);
    env = stack[-11];
    goto v_30563;
v_30565:
    stack[-3] = v_30847;
    v_30847 = stack[-3];
    if (v_30847 == nil) goto v_30586;
    else goto v_30587;
v_30586:
    v_30847 = nil;
    goto v_30581;
v_30587:
    v_30847 = stack[-3];
    v_30847 = qcar(v_30847);
    goto v_30599;
v_30595:
    v_30848 = stack[-8];
    goto v_30596;
v_30597:
    goto v_30598;
v_30599:
    goto v_30595;
v_30596:
    goto v_30597;
v_30598:
    fn = elt(env, 1); // nth
    v_30847 = (*qfn2(fn))(fn, v_30848, v_30847);
    env = stack[-11];
    v_30847 = ncons(v_30847);
    env = stack[-11];
    stack[-1] = v_30847;
    stack[-2] = v_30847;
v_30582:
    v_30847 = stack[-3];
    v_30847 = qcdr(v_30847);
    stack[-3] = v_30847;
    v_30847 = stack[-3];
    if (v_30847 == nil) goto v_30606;
    else goto v_30607;
v_30606:
    v_30847 = stack[-2];
    goto v_30581;
v_30607:
    goto v_30615;
v_30611:
    stack[0] = stack[-1];
    goto v_30612;
v_30613:
    v_30847 = stack[-3];
    v_30847 = qcar(v_30847);
    goto v_30626;
v_30622:
    v_30848 = stack[-8];
    goto v_30623;
v_30624:
    goto v_30625;
v_30626:
    goto v_30622;
v_30623:
    goto v_30624;
v_30625:
    fn = elt(env, 1); // nth
    v_30847 = (*qfn2(fn))(fn, v_30848, v_30847);
    env = stack[-11];
    v_30847 = ncons(v_30847);
    env = stack[-11];
    goto v_30614;
v_30615:
    goto v_30611;
v_30612:
    goto v_30613;
v_30614:
    v_30847 = Lrplacd(nil, stack[0], v_30847);
    env = stack[-11];
    v_30847 = stack[-1];
    v_30847 = qcdr(v_30847);
    stack[-1] = v_30847;
    goto v_30582;
v_30581:
    goto v_30563;
    v_30847 = nil;
v_30563:
    v_30847 = ncons(v_30847);
    env = stack[-11];
    stack[-5] = v_30847;
    stack[-6] = v_30847;
v_30550:
    v_30847 = stack[-7];
    v_30847 = qcdr(v_30847);
    stack[-7] = v_30847;
    v_30847 = stack[-7];
    if (v_30847 == nil) goto v_30635;
    else goto v_30636;
v_30635:
    v_30847 = stack[-6];
    goto v_30549;
v_30636:
    goto v_30644;
v_30640:
    stack[-4] = stack[-5];
    goto v_30641;
v_30642:
    v_30847 = stack[-7];
    v_30847 = qcar(v_30847);
    v_30848 = v_30847;
    if (!consp(v_30848)) goto v_30652;
    else goto v_30653;
v_30652:
    goto v_30660;
v_30656:
    v_30848 = stack[-8];
    goto v_30657;
v_30658:
    goto v_30659;
v_30660:
    goto v_30656;
v_30657:
    goto v_30658;
v_30659:
    fn = elt(env, 1); // nth
    v_30847 = (*qfn2(fn))(fn, v_30848, v_30847);
    env = stack[-11];
    goto v_30651;
v_30653:
    stack[-3] = v_30847;
    v_30847 = stack[-3];
    if (v_30847 == nil) goto v_30674;
    else goto v_30675;
v_30674:
    v_30847 = nil;
    goto v_30669;
v_30675:
    v_30847 = stack[-3];
    v_30847 = qcar(v_30847);
    goto v_30687;
v_30683:
    v_30848 = stack[-8];
    goto v_30684;
v_30685:
    goto v_30686;
v_30687:
    goto v_30683;
v_30684:
    goto v_30685;
v_30686:
    fn = elt(env, 1); // nth
    v_30847 = (*qfn2(fn))(fn, v_30848, v_30847);
    env = stack[-11];
    v_30847 = ncons(v_30847);
    env = stack[-11];
    stack[-1] = v_30847;
    stack[-2] = v_30847;
v_30670:
    v_30847 = stack[-3];
    v_30847 = qcdr(v_30847);
    stack[-3] = v_30847;
    v_30847 = stack[-3];
    if (v_30847 == nil) goto v_30694;
    else goto v_30695;
v_30694:
    v_30847 = stack[-2];
    goto v_30669;
v_30695:
    goto v_30703;
v_30699:
    stack[0] = stack[-1];
    goto v_30700;
v_30701:
    v_30847 = stack[-3];
    v_30847 = qcar(v_30847);
    goto v_30714;
v_30710:
    v_30848 = stack[-8];
    goto v_30711;
v_30712:
    goto v_30713;
v_30714:
    goto v_30710;
v_30711:
    goto v_30712;
v_30713:
    fn = elt(env, 1); // nth
    v_30847 = (*qfn2(fn))(fn, v_30848, v_30847);
    env = stack[-11];
    v_30847 = ncons(v_30847);
    env = stack[-11];
    goto v_30702;
v_30703:
    goto v_30699;
v_30700:
    goto v_30701;
v_30702:
    v_30847 = Lrplacd(nil, stack[0], v_30847);
    env = stack[-11];
    v_30847 = stack[-1];
    v_30847 = qcdr(v_30847);
    stack[-1] = v_30847;
    goto v_30670;
v_30669:
    goto v_30651;
    v_30847 = nil;
v_30651:
    v_30847 = ncons(v_30847);
    env = stack[-11];
    goto v_30643;
v_30644:
    goto v_30640;
v_30641:
    goto v_30642;
v_30643:
    v_30847 = Lrplacd(nil, stack[-4], v_30847);
    env = stack[-11];
    v_30847 = stack[-5];
    v_30847 = qcdr(v_30847);
    stack[-5] = v_30847;
    goto v_30550;
v_30549:
    stack[-5] = v_30847;
    v_30847 = stack[-5];
    v_30847 = qcar(v_30847);
    if (!consp(v_30847)) goto v_30723;
    else goto v_30724;
v_30723:
    v_30847 = stack[-5];
    fn = elt(env, 2); // indordn
    v_30847 = (*qfn1(fn))(fn, v_30847);
    env = stack[-11];
    goto v_30722;
v_30724:
    v_30847 = stack[-5];
    fn = elt(env, 3); // indordln
    v_30847 = (*qfn1(fn))(fn, v_30847);
    env = stack[-11];
    fn = elt(env, 4); // flatindl
    v_30847 = (*qfn1(fn))(fn, v_30847);
    env = stack[-11];
    goto v_30722;
    v_30847 = nil;
v_30722:
    stack[0] = v_30847;
    v_30847 = stack[-9];
    v_30847 = qcar(v_30847);
    if (!consp(v_30847)) goto v_30737;
    v_30847 = stack[-9];
    fn = elt(env, 4); // flatindl
    v_30847 = (*qfn1(fn))(fn, v_30847);
    env = stack[-11];
    stack[-9] = v_30847;
    goto v_30735;
v_30737:
v_30735:
    goto v_30747;
v_30743:
    v_30848 = stack[-9];
    goto v_30744;
v_30745:
    v_30847 = stack[0];
    goto v_30746;
v_30747:
    goto v_30743;
v_30744:
    goto v_30745;
v_30746:
    fn = elt(env, 5); // pair
    v_30847 = (*qfn2(fn))(fn, v_30848, v_30847);
    env = stack[-11];
    stack[-5] = v_30847;
    goto v_30755;
v_30751:
    stack[-6] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30752;
v_30753:
    v_30847 = stack[-8];
    stack[-7] = v_30847;
    v_30847 = stack[-7];
    if (v_30847 == nil) goto v_30766;
    else goto v_30767;
v_30766:
    v_30847 = nil;
    goto v_30761;
v_30767:
    v_30847 = stack[-7];
    v_30847 = qcar(v_30847);
    stack[-1] = v_30847;
    v_30847 = stack[-5];
    if (v_30847 == nil) goto v_30777;
    goto v_30785;
v_30781:
    v_30847 = stack[-5];
    v_30847 = qcar(v_30847);
    stack[0] = qcar(v_30847);
    goto v_30782;
v_30783:
    v_30847 = stack[-10];
    v_30847 = add1(v_30847);
    env = stack[-11];
    stack[-10] = v_30847;
    goto v_30784;
v_30785:
    goto v_30781;
v_30782:
    goto v_30783;
v_30784:
    if (equal(stack[0], v_30847)) goto v_30780;
    else goto v_30777;
v_30780:
    v_30847 = stack[-5];
    v_30847 = qcar(v_30847);
    v_30847 = qcdr(v_30847);
    v_30848 = v_30847;
    v_30847 = stack[-5];
    v_30847 = qcdr(v_30847);
    stack[-5] = v_30847;
    v_30847 = v_30848;
    goto v_30775;
v_30777:
    v_30847 = stack[-1];
    goto v_30775;
    v_30847 = nil;
v_30775:
    v_30847 = ncons(v_30847);
    env = stack[-11];
    stack[-3] = v_30847;
    stack[-4] = v_30847;
v_30762:
    v_30847 = stack[-7];
    v_30847 = qcdr(v_30847);
    stack[-7] = v_30847;
    v_30847 = stack[-7];
    if (v_30847 == nil) goto v_30804;
    else goto v_30805;
v_30804:
    v_30847 = stack[-4];
    goto v_30761;
v_30805:
    goto v_30813;
v_30809:
    stack[-2] = stack[-3];
    goto v_30810;
v_30811:
    v_30847 = stack[-7];
    v_30847 = qcar(v_30847);
    stack[-1] = v_30847;
    v_30847 = stack[-5];
    if (v_30847 == nil) goto v_30822;
    goto v_30830;
v_30826:
    v_30847 = stack[-5];
    v_30847 = qcar(v_30847);
    stack[0] = qcar(v_30847);
    goto v_30827;
v_30828:
    v_30847 = stack[-10];
    v_30847 = add1(v_30847);
    env = stack[-11];
    stack[-10] = v_30847;
    goto v_30829;
v_30830:
    goto v_30826;
v_30827:
    goto v_30828;
v_30829:
    if (equal(stack[0], v_30847)) goto v_30825;
    else goto v_30822;
v_30825:
    v_30847 = stack[-5];
    v_30847 = qcar(v_30847);
    v_30847 = qcdr(v_30847);
    v_30848 = v_30847;
    v_30847 = stack[-5];
    v_30847 = qcdr(v_30847);
    stack[-5] = v_30847;
    v_30847 = v_30848;
    goto v_30820;
v_30822:
    v_30847 = stack[-1];
    goto v_30820;
    v_30847 = nil;
v_30820:
    v_30847 = ncons(v_30847);
    env = stack[-11];
    goto v_30812;
v_30813:
    goto v_30809;
v_30810:
    goto v_30811;
v_30812:
    v_30847 = Lrplacd(nil, stack[-2], v_30847);
    env = stack[-11];
    v_30847 = stack[-3];
    v_30847 = qcdr(v_30847);
    stack[-3] = v_30847;
    goto v_30762;
v_30761:
    goto v_30754;
v_30755:
    goto v_30751;
v_30752:
    goto v_30753;
v_30754:
    {
        LispObject v_30860 = stack[-6];
        return cons(v_30860, v_30847);
    }
    return onevalue(v_30847);
}



// Code for coeff_sortl

static LispObject CC_coeff_sortl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30557, v_30558, v_30559;
    LispObject fn;
    LispObject v_30537, v_30536, v_30535;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "coeff_sortl");
    va_start(aa, nargs);
    v_30535 = va_arg(aa, LispObject);
    v_30536 = va_arg(aa, LispObject);
    v_30537 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30537,v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30535,v_30536,v_30537);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30537;
    stack[-1] = v_30536;
    v_30557 = v_30535;
// end of prologue
    goto v_30546;
v_30540:
    goto v_30552;
v_30548:
    v_30558 = v_30557;
    goto v_30549;
v_30550:
    v_30557 = stack[0];
    goto v_30551;
v_30552:
    goto v_30548;
v_30549:
    goto v_30550;
v_30551:
    fn = elt(env, 1); // coeff_ordn
    v_30559 = (*qfn2(fn))(fn, v_30558, v_30557);
    env = stack[-2];
    goto v_30541;
v_30542:
    v_30558 = stack[-1];
    goto v_30543;
v_30544:
    v_30557 = stack[0];
    goto v_30545;
v_30546:
    goto v_30540;
v_30541:
    goto v_30542;
v_30543:
    goto v_30544;
v_30545:
    {
        fn = elt(env, 2); // coeff_sortl1
        return (*qfnn(fn))(fn, 3, v_30559, v_30558, v_30557);
    }
}



// Code for subs2chkex

static LispObject CC_subs2chkex(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30574, v_30575, v_30576;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30535);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_30535;
// end of prologue
v_30534:
    v_30574 = stack[0];
    if (v_30574 == nil) goto v_30539;
    else goto v_30540;
v_30539:
    v_30574 = nil;
    goto v_30538;
v_30540:
    v_30574 = stack[0];
    v_30574 = qcar(v_30574);
    v_30574 = qcdr(v_30574);
    fn = elt(env, 1); // subs2chk
    v_30574 = (*qfn1(fn))(fn, v_30574);
    env = stack[-1];
    v_30575 = v_30574;
    if (v_30575 == nil) goto v_30553;
    goto v_30562;
v_30556:
    v_30575 = stack[0];
    v_30575 = qcar(v_30575);
    v_30576 = qcar(v_30575);
    goto v_30557;
v_30558:
    v_30575 = v_30574;
    goto v_30559;
v_30560:
    v_30574 = stack[0];
    v_30574 = qcdr(v_30574);
    goto v_30561;
v_30562:
    goto v_30556;
v_30557:
    goto v_30558;
v_30559:
    goto v_30560;
v_30561:
    return acons(v_30576, v_30575, v_30574);
v_30553:
    v_30574 = stack[0];
    v_30574 = qcdr(v_30574);
    stack[0] = v_30574;
    goto v_30534;
    v_30574 = nil;
    goto v_30538;
    v_30574 = nil;
v_30538:
    return onevalue(v_30574);
}



// Code for simpsqrt3

static LispObject CC_simpsqrt3(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30607, v_30608, v_30609;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30535);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30535;
// end of prologue
    goto v_30545;
v_30541:
    v_30608 = stack[0];
    goto v_30542;
v_30543:
    v_30607 = qvalue(elt(env, 1)); // listofallsqrts
    goto v_30544;
v_30545:
    goto v_30541;
v_30542:
    goto v_30543;
v_30544:
    v_30607 = Lassoc(nil, v_30608, v_30607);
    stack[-1] = v_30607;
    v_30607 = stack[-1];
    if (v_30607 == nil) goto v_30552;
    v_30607 = stack[-1];
    v_30607 = qcdr(v_30607);
    goto v_30539;
v_30552:
    goto v_30560;
v_30556:
    v_30608 = qvalue(elt(env, 2)); // listofnewsqrts
    goto v_30557;
v_30558:
    v_30607 = qvalue(elt(env, 3)); // knowntobeindep
    goto v_30559;
v_30560:
    goto v_30556;
v_30557:
    goto v_30558;
v_30559:
    v_30607 = Latsoc(nil, v_30608, v_30607);
    stack[-1] = v_30607;
    v_30607 = stack[-1];
    if (v_30607 == nil) goto v_30566;
    else goto v_30567;
v_30566:
    goto v_30540;
v_30567:
    goto v_30573;
v_30569:
    v_30608 = stack[0];
    goto v_30570;
v_30571:
    v_30607 = stack[-1];
    v_30607 = qcdr(v_30607);
    goto v_30572;
v_30573:
    goto v_30569;
v_30570:
    goto v_30571;
v_30572:
    v_30607 = Lassoc(nil, v_30608, v_30607);
    stack[-1] = v_30607;
    v_30607 = stack[-1];
    if (v_30607 == nil) goto v_30581;
    goto v_30588;
v_30584:
    v_30608 = stack[-1];
    goto v_30585;
v_30586:
    v_30607 = qvalue(elt(env, 1)); // listofallsqrts
    goto v_30587;
v_30588:
    goto v_30584;
v_30585:
    goto v_30586;
v_30587:
    v_30607 = cons(v_30608, v_30607);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_30607; // listofallsqrts
    v_30607 = stack[-1];
    v_30607 = qcdr(v_30607);
    goto v_30539;
v_30581:
v_30540:
    v_30607 = stack[0];
    fn = elt(env, 4); // actualsimpsqrt
    v_30607 = (*qfn1(fn))(fn, v_30607);
    env = stack[-2];
    stack[-1] = v_30607;
    goto v_30602;
v_30596:
    v_30609 = stack[0];
    goto v_30597;
v_30598:
    v_30608 = stack[-1];
    goto v_30599;
v_30600:
    v_30607 = qvalue(elt(env, 1)); // listofallsqrts
    goto v_30601;
v_30602:
    goto v_30596;
v_30597:
    goto v_30598;
v_30599:
    goto v_30600;
v_30601:
    v_30607 = acons(v_30609, v_30608, v_30607);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_30607; // listofallsqrts
    v_30607 = stack[-1];
v_30539:
    return onevalue(v_30607);
}



// Code for ofsf_smmkatl!-or

static LispObject CC_ofsf_smmkatlKor(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30664, v_30665, v_30666;
    LispObject fn;
    LispObject v_30537, v_30536, v_30535;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_smmkatl-or");
    va_start(aa, nargs);
    v_30535 = va_arg(aa, LispObject);
    v_30536 = va_arg(aa, LispObject);
    v_30537 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30537,v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30535,v_30536,v_30537);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_30537;
    v_30664 = v_30536;
    stack[-4] = v_30535;
// end of prologue
    stack[-5] = v_30664;
v_30547:
    v_30664 = stack[-5];
    if (v_30664 == nil) goto v_30552;
    else goto v_30553;
v_30552:
    v_30664 = nil;
    goto v_30546;
v_30553:
    v_30664 = stack[-5];
    v_30664 = qcar(v_30664);
    goto v_30563;
v_30559:
    v_30665 = v_30664;
    v_30666 = qcar(v_30665);
    goto v_30560;
v_30561:
    v_30665 = stack[-4];
    goto v_30562;
v_30563:
    goto v_30559;
v_30560:
    goto v_30561;
v_30562:
    v_30665 = Latsoc(nil, v_30666, v_30665);
    v_30666 = v_30665;
    v_30665 = v_30666;
    if (v_30665 == nil) goto v_30570;
    else goto v_30571;
v_30570:
    goto v_30580;
v_30574:
    v_30665 = elt(env, 1); // or
    goto v_30575;
v_30576:
    v_30666 = v_30664;
    goto v_30577;
v_30578:
    v_30664 = stack[-3];
    goto v_30579;
v_30580:
    goto v_30574;
v_30575:
    goto v_30576;
v_30577:
    goto v_30578;
v_30579:
    fn = elt(env, 2); // ofsf_ir2atl
    v_30664 = (*qfnn(fn))(fn, 3, v_30665, v_30666, v_30664);
    env = stack[-6];
    goto v_30569;
v_30571:
    goto v_30593;
v_30587:
    goto v_30588;
v_30589:
    v_30665 = v_30664;
    goto v_30590;
v_30591:
    v_30664 = stack[-3];
    goto v_30592;
v_30593:
    goto v_30587;
v_30588:
    goto v_30589;
v_30590:
    goto v_30591;
v_30592:
    fn = elt(env, 3); // ofsf_smmkatl!-or1
    v_30664 = (*qfnn(fn))(fn, 3, v_30666, v_30665, v_30664);
    env = stack[-6];
    goto v_30569;
    v_30664 = nil;
v_30569:
    stack[-2] = v_30664;
    v_30664 = stack[-2];
    fn = elt(env, 4); // lastpair
    v_30664 = (*qfn1(fn))(fn, v_30664);
    env = stack[-6];
    stack[-1] = v_30664;
    v_30664 = stack[-5];
    v_30664 = qcdr(v_30664);
    stack[-5] = v_30664;
    v_30664 = stack[-1];
    if (!consp(v_30664)) goto v_30603;
    else goto v_30604;
v_30603:
    goto v_30547;
v_30604:
v_30548:
    v_30664 = stack[-5];
    if (v_30664 == nil) goto v_30608;
    else goto v_30609;
v_30608:
    v_30664 = stack[-2];
    goto v_30546;
v_30609:
    goto v_30617;
v_30613:
    stack[0] = stack[-1];
    goto v_30614;
v_30615:
    v_30664 = stack[-5];
    v_30664 = qcar(v_30664);
    goto v_30626;
v_30622:
    v_30665 = v_30664;
    v_30666 = qcar(v_30665);
    goto v_30623;
v_30624:
    v_30665 = stack[-4];
    goto v_30625;
v_30626:
    goto v_30622;
v_30623:
    goto v_30624;
v_30625:
    v_30665 = Latsoc(nil, v_30666, v_30665);
    v_30666 = v_30665;
    v_30665 = v_30666;
    if (v_30665 == nil) goto v_30633;
    else goto v_30634;
v_30633:
    goto v_30643;
v_30637:
    v_30666 = elt(env, 1); // or
    goto v_30638;
v_30639:
    v_30665 = v_30664;
    goto v_30640;
v_30641:
    v_30664 = stack[-3];
    goto v_30642;
v_30643:
    goto v_30637;
v_30638:
    goto v_30639;
v_30640:
    goto v_30641;
v_30642:
    fn = elt(env, 2); // ofsf_ir2atl
    v_30664 = (*qfnn(fn))(fn, 3, v_30666, v_30665, v_30664);
    env = stack[-6];
    goto v_30632;
v_30634:
    goto v_30656;
v_30650:
    goto v_30651;
v_30652:
    v_30665 = v_30664;
    goto v_30653;
v_30654:
    v_30664 = stack[-3];
    goto v_30655;
v_30656:
    goto v_30650;
v_30651:
    goto v_30652;
v_30653:
    goto v_30654;
v_30655:
    fn = elt(env, 3); // ofsf_smmkatl!-or1
    v_30664 = (*qfnn(fn))(fn, 3, v_30666, v_30665, v_30664);
    env = stack[-6];
    goto v_30632;
    v_30664 = nil;
v_30632:
    goto v_30616;
v_30617:
    goto v_30613;
v_30614:
    goto v_30615;
v_30616:
    v_30664 = Lrplacd(nil, stack[0], v_30664);
    env = stack[-6];
    v_30664 = stack[-1];
    fn = elt(env, 4); // lastpair
    v_30664 = (*qfn1(fn))(fn, v_30664);
    env = stack[-6];
    stack[-1] = v_30664;
    v_30664 = stack[-5];
    v_30664 = qcdr(v_30664);
    stack[-5] = v_30664;
    goto v_30548;
v_30546:
    return onevalue(v_30664);
}



// Code for giprim

static LispObject CC_giprim(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30562, v_30563, v_30564;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30564 = v_30535;
// end of prologue
    goto v_30545;
v_30541:
    v_30563 = v_30564;
    goto v_30542;
v_30543:
    v_30562 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30544;
v_30545:
    goto v_30541;
v_30542:
    goto v_30543;
v_30544:
    if (v_30563 == v_30562) goto v_30539;
    else goto v_30540;
v_30539:
    v_30562 = elt(env, 1); // i
    goto v_30538;
v_30540:
    goto v_30558;
v_30552:
    v_30562 = elt(env, 2); // times
    goto v_30553;
v_30554:
    v_30563 = v_30564;
    goto v_30555;
v_30556:
    v_30564 = elt(env, 1); // i
    goto v_30557;
v_30558:
    goto v_30552;
v_30553:
    goto v_30554;
v_30555:
    goto v_30556;
v_30557:
    return list3(v_30562, v_30563, v_30564);
    v_30562 = nil;
v_30538:
    return onevalue(v_30562);
}



// Code for talp_simplatfn

static LispObject CC_talp_simplatfn(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30761, v_30762, v_30763;
    LispObject fn;
    LispObject v_30537, v_30536, v_30535;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_simplatfn");
    va_start(aa, nargs);
    v_30535 = va_arg(aa, LispObject);
    v_30536 = va_arg(aa, LispObject);
    v_30537 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30537,v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30535,v_30536,v_30537);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_30537;
    stack[-2] = v_30536;
    stack[-3] = v_30535;
// end of prologue
    stack[-4] = nil;
    v_30761 = stack[-1];
    if (!consp(v_30761)) goto v_30545;
    else goto v_30546;
v_30545:
    goto v_30556;
v_30552:
    stack[0] = stack[-1];
    goto v_30553;
v_30554:
    fn = elt(env, 5); // talp_getl
    v_30761 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_30555;
v_30556:
    goto v_30552;
v_30553:
    goto v_30554;
v_30555:
    v_30761 = Latsoc(nil, stack[0], v_30761);
    if (v_30761 == nil) goto v_30550;
    else goto v_30551;
v_30550:
    goto v_30569;
v_30565:
    v_30762 = stack[-1];
    goto v_30566;
v_30567:
    v_30761 = stack[-2];
    goto v_30568;
v_30569:
    goto v_30565;
v_30566:
    goto v_30567;
v_30568:
    fn = elt(env, 6); // talp_telp
    v_30761 = (*qfn2(fn))(fn, v_30762, v_30761);
    env = stack[-5];
    if (v_30761 == nil) goto v_30563;
    goto v_30577;
v_30573:
    v_30761 = stack[-3];
    goto v_30574;
v_30575:
    v_30762 = elt(env, 1); // equal
    goto v_30576;
v_30577:
    goto v_30573;
v_30574:
    goto v_30575;
v_30576:
        return Lneq(nil, v_30761, v_30762);
v_30563:
    goto v_30589;
v_30583:
    stack[0] = stack[-3];
    goto v_30584;
v_30585:
    v_30761 = stack[-2];
    fn = elt(env, 7); // talp_simplt
    v_30762 = (*qfn1(fn))(fn, v_30761);
    env = stack[-5];
    goto v_30586;
v_30587:
    v_30761 = stack[-1];
    goto v_30588;
v_30589:
    goto v_30583;
v_30584:
    goto v_30585;
v_30586:
    goto v_30587;
v_30588:
    {
        LispObject v_30769 = stack[0];
        fn = elt(env, 8); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_30769, v_30762, v_30761);
    }
    goto v_30549;
v_30551:
    goto v_30601;
v_30597:
    v_30761 = stack[-3];
    goto v_30598;
v_30599:
    v_30762 = elt(env, 1); // equal
    goto v_30600;
v_30601:
    goto v_30597;
v_30598:
    goto v_30599;
v_30600:
        return Lneq(nil, v_30761, v_30762);
v_30549:
    goto v_30544;
v_30546:
    goto v_30610;
v_30606:
    v_30761 = stack[-2];
    fn = elt(env, 9); // talp_fop
    stack[0] = (*qfn1(fn))(fn, v_30761);
    env = stack[-5];
    goto v_30607;
v_30608:
    v_30761 = stack[-1];
    fn = elt(env, 9); // talp_fop
    v_30761 = (*qfn1(fn))(fn, v_30761);
    env = stack[-5];
    goto v_30609;
v_30610:
    goto v_30606;
v_30607:
    goto v_30608;
v_30609:
    v_30761 = (stack[0] == v_30761 ? lisp_true : nil);
    stack[0] = v_30761;
    v_30761 = stack[-2];
    fn = elt(env, 10); // talp_fargl
    v_30761 = (*qfn1(fn))(fn, v_30761);
    env = stack[-5];
    stack[-2] = v_30761;
    v_30761 = stack[-1];
    fn = elt(env, 10); // talp_fargl
    v_30761 = (*qfn1(fn))(fn, v_30761);
    env = stack[-5];
    stack[-1] = v_30761;
v_30622:
    v_30761 = stack[-2];
    if (v_30761 == nil) goto v_30625;
    v_30761 = stack[-1];
    if (v_30761 == nil) goto v_30625;
    v_30761 = stack[0];
    if (v_30761 == nil) goto v_30625;
    goto v_30626;
v_30625:
    goto v_30621;
v_30626:
    goto v_30642;
v_30636:
    v_30763 = elt(env, 1); // equal
    goto v_30637;
v_30638:
    v_30761 = stack[-2];
    v_30762 = qcar(v_30761);
    goto v_30639;
v_30640:
    v_30761 = stack[-1];
    v_30761 = qcar(v_30761);
    goto v_30641;
v_30642:
    goto v_30636;
v_30637:
    goto v_30638;
v_30639:
    goto v_30640;
v_30641:
    fn = elt(env, 11); // talp_simplat2
    v_30761 = (*qfnn(fn))(fn, 3, v_30763, v_30762, v_30761);
    env = stack[-5];
    stack[0] = v_30761;
    v_30761 = stack[0];
    if (v_30761 == nil) goto v_30651;
    goto v_30659;
v_30655:
    v_30762 = stack[0];
    goto v_30656;
v_30657:
    v_30761 = lisp_true;
    goto v_30658;
v_30659:
    goto v_30655;
v_30656:
    goto v_30657;
v_30658:
    if (equal(v_30762, v_30761)) goto v_30651;
    goto v_30670;
v_30666:
    v_30762 = stack[-3];
    goto v_30667;
v_30668:
    v_30761 = elt(env, 1); // equal
    goto v_30669;
v_30670:
    goto v_30666;
v_30667:
    goto v_30668;
v_30669:
    if (v_30762 == v_30761) goto v_30664;
    else goto v_30665;
v_30664:
    goto v_30678;
v_30674:
    v_30762 = stack[0];
    goto v_30675;
v_30676:
    v_30761 = stack[-4];
    goto v_30677;
v_30678:
    goto v_30674;
v_30675:
    goto v_30676;
v_30677:
    v_30761 = cons(v_30762, v_30761);
    env = stack[-5];
    stack[-4] = v_30761;
    goto v_30663;
v_30665:
    goto v_30690;
v_30684:
    v_30763 = elt(env, 2); // neq
    goto v_30685;
v_30686:
    v_30761 = stack[0];
    v_30762 = qcdr(v_30761);
    goto v_30687;
v_30688:
    v_30761 = stack[-4];
    goto v_30689;
v_30690:
    goto v_30684;
v_30685:
    goto v_30686;
v_30687:
    goto v_30688;
v_30689:
    v_30761 = acons(v_30763, v_30762, v_30761);
    env = stack[-5];
    stack[-4] = v_30761;
    goto v_30663;
v_30663:
    goto v_30649;
v_30651:
v_30649:
    v_30761 = stack[-2];
    v_30761 = qcdr(v_30761);
    stack[-2] = v_30761;
    v_30761 = stack[-1];
    v_30761 = qcdr(v_30761);
    stack[-1] = v_30761;
    goto v_30622;
v_30621:
    v_30761 = stack[0];
    if (v_30761 == nil) goto v_30703;
    v_30761 = stack[-4];
    if (v_30761 == nil) goto v_30703;
    v_30761 = stack[-4];
    v_30761 = qcdr(v_30761);
    if (v_30761 == nil) goto v_30711;
    goto v_30722;
v_30718:
    v_30762 = stack[-3];
    goto v_30719;
v_30720:
    v_30761 = elt(env, 1); // equal
    goto v_30721;
v_30722:
    goto v_30718;
v_30719:
    goto v_30720;
v_30721:
    if (v_30762 == v_30761) goto v_30716;
    else goto v_30717;
v_30716:
    goto v_30730;
v_30726:
    v_30762 = elt(env, 3); // and
    goto v_30727;
v_30728:
    v_30761 = stack[-4];
    goto v_30729;
v_30730:
    goto v_30726;
v_30727:
    goto v_30728;
v_30729:
    return cons(v_30762, v_30761);
v_30717:
    goto v_30740;
v_30736:
    v_30762 = elt(env, 4); // or
    goto v_30737;
v_30738:
    v_30761 = stack[-4];
    goto v_30739;
v_30740:
    goto v_30736;
v_30737:
    goto v_30738;
v_30739:
    return cons(v_30762, v_30761);
    goto v_30709;
v_30711:
    v_30761 = stack[-4];
    v_30761 = qcar(v_30761);
    goto v_30542;
v_30709:
    goto v_30701;
v_30703:
    goto v_30753;
v_30749:
    v_30761 = stack[-3];
    goto v_30750;
v_30751:
    v_30762 = elt(env, 1); // equal
    goto v_30752;
v_30753:
    goto v_30749;
v_30750:
    goto v_30751;
v_30752:
    if (v_30761 == v_30762) goto v_30747;
    else goto v_30748;
v_30747:
    v_30761 = stack[0];
    goto v_30542;
v_30748:
    v_30761 = stack[0];
    v_30761 = (v_30761 == nil ? lisp_true : nil);
    goto v_30542;
v_30701:
    goto v_30544;
v_30544:
    v_30761 = nil;
v_30542:
    return onevalue(v_30761);
}



// Code for spmatsm!*

static LispObject CC_spmatsmH(LispObject env,
                         LispObject v_30535, LispObject v_30536)
{
    env = qenv(env);
    LispObject v_30561, v_30562, v_30563;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30535,v_30536);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30561 = v_30536;
    v_30562 = v_30535;
// end of prologue
    v_30561 = v_30562;
    fn = elt(env, 2); // spmatsm
    v_30561 = (*qfn1(fn))(fn, v_30561);
    env = stack[0];
    v_30563 = v_30561;
    goto v_30552;
v_30548:
    v_30562 = v_30563;
    goto v_30549;
v_30550:
    v_30561 = elt(env, 1); // sparsemat
    goto v_30551;
v_30552:
    goto v_30548;
v_30549:
    goto v_30550;
v_30551:
    if (!consp(v_30562)) goto v_30546;
    v_30562 = qcar(v_30562);
    if (v_30562 == v_30561) goto v_30545;
    else goto v_30546;
v_30545:
    v_30561 = v_30563;
    goto v_30540;
v_30546:
    v_30561 = v_30563;
    {
        fn = elt(env, 3); // matsm!*1
        return (*qfn1(fn))(fn, v_30561);
    }
    v_30561 = nil;
v_30540:
    return onevalue(v_30561);
}



// Code for tchscheme

static LispObject CC_tchscheme(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30660, v_30661;
    LispObject fn;
    argcheck(nargs, 0, "tchscheme");
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
    stack[-3] = nil;
    stack[-2] = nil;
    v_30660 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_30660;
v_30543:
    goto v_30555;
v_30551:
    v_30661 = qvalue(elt(env, 1)); // rowmax
    goto v_30552;
v_30553:
    v_30660 = stack[-1];
    goto v_30554;
v_30555:
    goto v_30551;
v_30552:
    goto v_30553;
v_30554:
    v_30660 = difference2(v_30661, v_30660);
    env = stack[-4];
    v_30660 = Lminusp(nil, v_30660);
    env = stack[-4];
    if (v_30660 == nil) goto v_30548;
    goto v_30542;
v_30548:
    goto v_30571;
v_30567:
    goto v_30576;
v_30572:
    goto v_30581;
v_30577:
    stack[0] = qvalue(elt(env, 2)); // codmat
    goto v_30578;
v_30579:
    goto v_30588;
v_30584:
    v_30661 = qvalue(elt(env, 3)); // maxvar
    goto v_30585;
v_30586:
    v_30660 = stack[-1];
    goto v_30587;
v_30588:
    goto v_30584;
v_30585:
    goto v_30586;
v_30587:
    v_30660 = plus2(v_30661, v_30660);
    env = stack[-4];
    goto v_30580;
v_30581:
    goto v_30577;
v_30578:
    goto v_30579;
v_30580:
    v_30661 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_30660-TAG_FIXNUM)/(16/CELL)));
    goto v_30573;
v_30574:
    v_30660 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_30575;
v_30576:
    goto v_30572;
v_30573:
    goto v_30574;
v_30575:
    v_30661 = *(LispObject *)((char *)v_30661 + (CELL-TAG_VECTOR) + (((intptr_t)v_30660-TAG_FIXNUM)/(16/CELL)));
    goto v_30568;
v_30569:
    v_30660 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_30570;
v_30571:
    goto v_30567;
v_30568:
    goto v_30569;
v_30570:
    if (v_30661 == v_30660) goto v_30566;
    goto v_30603;
v_30599:
    goto v_30608;
v_30604:
    stack[0] = qvalue(elt(env, 2)); // codmat
    goto v_30605;
v_30606:
    goto v_30615;
v_30611:
    v_30661 = qvalue(elt(env, 3)); // maxvar
    goto v_30612;
v_30613:
    v_30660 = stack[-1];
    goto v_30614;
v_30615:
    goto v_30611;
v_30612:
    goto v_30613;
v_30614:
    v_30660 = plus2(v_30661, v_30660);
    env = stack[-4];
    goto v_30607;
v_30608:
    goto v_30604;
v_30605:
    goto v_30606;
v_30607:
    v_30661 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_30660-TAG_FIXNUM)/(16/CELL)));
    goto v_30600;
v_30601:
    v_30660 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_30602;
v_30603:
    goto v_30599;
v_30600:
    goto v_30601;
v_30602:
    v_30660 = *(LispObject *)((char *)v_30661 + (CELL-TAG_VECTOR) + (((intptr_t)v_30660-TAG_FIXNUM)/(16/CELL)));
    stack[-3] = v_30660;
    if (v_30660 == nil) goto v_30597;
    else goto v_30598;
v_30597:
    v_30660 = nil;
    goto v_30596;
v_30598:
    v_30660 = stack[-3];
    v_30660 = qcdr(v_30660);
    if (v_30660 == nil) goto v_30626;
    else goto v_30627;
v_30626:
    goto v_30635;
v_30631:
    v_30661 = stack[-1];
    goto v_30632;
v_30633:
    v_30660 = stack[-3];
    v_30660 = qcar(v_30660);
    v_30660 = qcdr(v_30660);
    v_30660 = qcar(v_30660);
    goto v_30634;
v_30635:
    goto v_30631;
v_30632:
    goto v_30633;
v_30634:
    fn = elt(env, 4); // transferrow
    v_30660 = (*qfn2(fn))(fn, v_30661, v_30660);
    env = stack[-4];
    goto v_30625;
v_30627:
    v_30660 = nil;
    goto v_30625;
    v_30660 = nil;
v_30625:
    goto v_30596;
    v_30660 = nil;
v_30596:
    goto v_30564;
v_30566:
    v_30660 = nil;
    goto v_30564;
    v_30660 = nil;
v_30564:
    if (v_30660 == nil) goto v_30562;
    goto v_30652;
v_30648:
    v_30661 = stack[-1];
    goto v_30649;
v_30650:
    v_30660 = stack[-3];
    v_30660 = qcar(v_30660);
    goto v_30651;
v_30652:
    goto v_30648;
v_30649:
    goto v_30650;
v_30651:
    fn = elt(env, 5); // chscheme
    v_30660 = (*qfn2(fn))(fn, v_30661, v_30660);
    env = stack[-4];
    v_30660 = lisp_true;
    stack[-2] = v_30660;
    goto v_30560;
v_30562:
v_30560:
    v_30660 = stack[-1];
    v_30660 = add1(v_30660);
    env = stack[-4];
    stack[-1] = v_30660;
    goto v_30543;
v_30542:
    v_30660 = stack[-2];
    return onevalue(v_30660);
}



// Code for solvealgtrig01

static LispObject CC_solvealgtrig01(LispObject env,
                         LispObject v_30535, LispObject v_30536)
{
    env = qenv(env);
    LispObject v_30595, v_30596;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30536,v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30535,v_30536);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30536;
    stack[-1] = v_30535;
// end of prologue
v_30541:
    v_30595 = stack[-1];
    if (!consp(v_30595)) goto v_30544;
    else goto v_30545;
v_30544:
    v_30595 = stack[0];
    goto v_30540;
v_30545:
    goto v_30554;
v_30550:
    v_30595 = stack[-1];
    v_30596 = qcar(v_30595);
    goto v_30551;
v_30552:
    v_30595 = elt(env, 1); // (sin cos tan cot sinh cosh tanh coth)
    goto v_30553;
v_30554:
    goto v_30550;
v_30551:
    goto v_30552;
v_30553:
    v_30595 = Lmemq(nil, v_30596, v_30595);
    if (v_30595 == nil) goto v_30549;
    v_30595 = stack[-1];
    v_30595 = qcdr(v_30595);
    v_30595 = qcar(v_30595);
    fn = elt(env, 2); // constant_exprp
    v_30595 = (*qfn1(fn))(fn, v_30595);
    env = stack[-3];
    if (v_30595 == nil) goto v_30562;
    v_30595 = stack[0];
    goto v_30540;
v_30562:
    goto v_30575;
v_30571:
    v_30595 = stack[-1];
    v_30595 = qcdr(v_30595);
    v_30595 = qcar(v_30595);
    v_30596 = ncons(v_30595);
    env = stack[-3];
    goto v_30572;
v_30573:
    v_30595 = stack[0];
    goto v_30574;
v_30575:
    goto v_30571;
v_30572:
    goto v_30573;
v_30574:
    {
        fn = elt(env, 3); // union
        return (*qfn2(fn))(fn, v_30596, v_30595);
    }
    goto v_30543;
v_30549:
    v_30595 = stack[-1];
    v_30595 = qcdr(v_30595);
    stack[-2] = v_30595;
    goto v_30590;
v_30586:
    v_30595 = stack[-1];
    v_30596 = qcar(v_30595);
    goto v_30587;
v_30588:
    v_30595 = stack[0];
    goto v_30589;
v_30590:
    goto v_30586;
v_30587:
    goto v_30588;
v_30589:
    v_30595 = CC_solvealgtrig01(elt(env, 0), v_30596, v_30595);
    env = stack[-3];
    stack[0] = v_30595;
    v_30595 = stack[-2];
    stack[-1] = v_30595;
    goto v_30541;
v_30543:
    v_30595 = nil;
v_30540:
    return onevalue(v_30595);
}



// Code for normmat

static LispObject CC_normmat(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30681, v_30682;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30535);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    v_30682 = v_30535;
// end of prologue
    stack[-6] = nil;
    v_30681 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_30681;
    v_30681 = v_30682;
    stack[-5] = v_30681;
v_30546:
    v_30681 = stack[-5];
    if (v_30681 == nil) goto v_30550;
    else goto v_30551;
v_30550:
    goto v_30545;
v_30551:
    v_30681 = stack[-5];
    v_30681 = qcar(v_30681);
    stack[-1] = v_30681;
    v_30681 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-7] = v_30681;
    v_30681 = stack[-1];
    stack[0] = v_30681;
v_30561:
    v_30681 = stack[0];
    if (v_30681 == nil) goto v_30565;
    else goto v_30566;
v_30565:
    goto v_30560;
v_30566:
    v_30681 = stack[0];
    v_30681 = qcar(v_30681);
    goto v_30577;
v_30573:
    v_30682 = stack[-7];
    goto v_30574;
v_30575:
    v_30681 = qcdr(v_30681);
    goto v_30576;
v_30577:
    goto v_30573;
v_30574:
    goto v_30575;
v_30576:
    fn = elt(env, 1); // lcm
    v_30681 = (*qfn2(fn))(fn, v_30682, v_30681);
    env = stack[-9];
    stack[-7] = v_30681;
    v_30681 = stack[0];
    v_30681 = qcdr(v_30681);
    stack[0] = v_30681;
    goto v_30561;
v_30560:
    goto v_30588;
v_30584:
    v_30681 = stack[-1];
    stack[-4] = v_30681;
    v_30681 = stack[-4];
    if (v_30681 == nil) goto v_30598;
    else goto v_30599;
v_30598:
    v_30681 = nil;
    v_30682 = v_30681;
    goto v_30593;
v_30599:
    v_30681 = stack[-4];
    v_30681 = qcar(v_30681);
    goto v_30611;
v_30607:
    v_30682 = v_30681;
    stack[0] = qcar(v_30682);
    goto v_30608;
v_30609:
    goto v_30619;
v_30615:
    v_30682 = stack[-7];
    goto v_30616;
v_30617:
    v_30681 = qcdr(v_30681);
    goto v_30618;
v_30619:
    goto v_30615;
v_30616:
    goto v_30617;
v_30618:
    fn = elt(env, 2); // quotf
    v_30681 = (*qfn2(fn))(fn, v_30682, v_30681);
    env = stack[-9];
    goto v_30610;
v_30611:
    goto v_30607;
v_30608:
    goto v_30609;
v_30610:
    fn = elt(env, 3); // multf
    v_30681 = (*qfn2(fn))(fn, stack[0], v_30681);
    env = stack[-9];
    v_30681 = ncons(v_30681);
    env = stack[-9];
    stack[-2] = v_30681;
    stack[-3] = v_30681;
v_30594:
    v_30681 = stack[-4];
    v_30681 = qcdr(v_30681);
    stack[-4] = v_30681;
    v_30681 = stack[-4];
    if (v_30681 == nil) goto v_30627;
    else goto v_30628;
v_30627:
    v_30681 = stack[-3];
    v_30682 = v_30681;
    goto v_30593;
v_30628:
    goto v_30636;
v_30632:
    stack[-1] = stack[-2];
    goto v_30633;
v_30634:
    v_30681 = stack[-4];
    v_30681 = qcar(v_30681);
    goto v_30647;
v_30643:
    v_30682 = v_30681;
    stack[0] = qcar(v_30682);
    goto v_30644;
v_30645:
    goto v_30655;
v_30651:
    v_30682 = stack[-7];
    goto v_30652;
v_30653:
    v_30681 = qcdr(v_30681);
    goto v_30654;
v_30655:
    goto v_30651;
v_30652:
    goto v_30653;
v_30654:
    fn = elt(env, 2); // quotf
    v_30681 = (*qfn2(fn))(fn, v_30682, v_30681);
    env = stack[-9];
    goto v_30646;
v_30647:
    goto v_30643;
v_30644:
    goto v_30645;
v_30646:
    fn = elt(env, 3); // multf
    v_30681 = (*qfn2(fn))(fn, stack[0], v_30681);
    env = stack[-9];
    v_30681 = ncons(v_30681);
    env = stack[-9];
    goto v_30635;
v_30636:
    goto v_30632;
v_30633:
    goto v_30634;
v_30635:
    v_30681 = Lrplacd(nil, stack[-1], v_30681);
    env = stack[-9];
    v_30681 = stack[-2];
    v_30681 = qcdr(v_30681);
    stack[-2] = v_30681;
    goto v_30594;
v_30593:
    goto v_30585;
v_30586:
    v_30681 = stack[-6];
    goto v_30587;
v_30588:
    goto v_30584;
v_30585:
    goto v_30586;
v_30587:
    v_30681 = cons(v_30682, v_30681);
    env = stack[-9];
    stack[-6] = v_30681;
    goto v_30667;
v_30663:
    v_30682 = stack[-7];
    goto v_30664;
v_30665:
    v_30681 = stack[-8];
    goto v_30666;
v_30667:
    goto v_30663;
v_30664:
    goto v_30665;
v_30666:
    fn = elt(env, 3); // multf
    v_30681 = (*qfn2(fn))(fn, v_30682, v_30681);
    env = stack[-9];
    stack[-8] = v_30681;
    v_30681 = stack[-5];
    v_30681 = qcdr(v_30681);
    stack[-5] = v_30681;
    goto v_30546;
v_30545:
    goto v_30677;
v_30673:
    v_30681 = stack[-6];
    v_30682 = Lreverse(nil, v_30681);
    goto v_30674;
v_30675:
    v_30681 = stack[-8];
    goto v_30676;
v_30677:
    goto v_30673;
v_30674:
    goto v_30675;
v_30676:
    return cons(v_30682, v_30681);
    return onevalue(v_30681);
}



// Code for actual_arguments

static LispObject CC_actual_arguments(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30558, v_30559, v_30560;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30535);
    }
// copy arguments values to proper place
    v_30559 = v_30535;
// end of prologue
    goto v_30542;
v_30538:
    v_30560 = elt(env, 1); // list
    goto v_30539;
v_30540:
    v_30558 = v_30559;
    v_30558 = qcdr(v_30558);
    if (v_30558 == nil) goto v_30546;
    else goto v_30545;
v_30546:
    goto v_30554;
v_30550:
    v_30558 = v_30559;
    v_30559 = qcar(v_30558);
    goto v_30551;
v_30552:
    v_30558 = elt(env, 2); // generic_function
    goto v_30553;
v_30554:
    goto v_30550;
v_30551:
    goto v_30552;
v_30553:
    v_30558 = get(v_30559, v_30558);
v_30545:
    goto v_30541;
v_30542:
    goto v_30538;
v_30539:
    goto v_30540;
v_30541:
    return cons(v_30560, v_30558);
}



// Code for extract_numid

static LispObject CC_extract_numid(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30569, v_30570;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30535);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30535;
// end of prologue
v_30534:
    v_30569 = stack[0];
    if (v_30569 == nil) goto v_30539;
    else goto v_30540;
v_30539:
    v_30569 = nil;
    goto v_30538;
v_30540:
    v_30569 = stack[0];
    v_30569 = qcar(v_30569);
    fn = elt(env, 1); // !*id2num
    v_30569 = (*qfn1(fn))(fn, v_30569);
    env = stack[-2];
    v_30570 = v_30569;
    v_30569 = v_30570;
    if (v_30569 == nil) goto v_30552;
    goto v_30559;
v_30555:
    stack[-1] = v_30570;
    goto v_30556;
v_30557:
    v_30569 = stack[0];
    v_30569 = qcdr(v_30569);
    v_30569 = CC_extract_numid(elt(env, 0), v_30569);
    goto v_30558;
v_30559:
    goto v_30555;
v_30556:
    goto v_30557;
v_30558:
    {
        LispObject v_30573 = stack[-1];
        return cons(v_30573, v_30569);
    }
v_30552:
    v_30569 = stack[0];
    v_30569 = qcdr(v_30569);
    stack[0] = v_30569;
    goto v_30534;
    v_30569 = nil;
    goto v_30538;
    v_30569 = nil;
v_30538:
    return onevalue(v_30569);
}



// Code for dv_skelsplit

static LispObject CC_dv_skelsplit(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30990, v_30991, v_30992;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30535);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(13);
// copy arguments values to proper place
    stack[-10] = v_30535;
// end of prologue
    v_30990 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_30990;
    v_30990 = stack[-10];
    fn = elt(env, 10); // listp
    v_30990 = (*qfn1(fn))(fn, v_30990);
    env = stack[-12];
    if (v_30990 == nil) goto v_30555;
    v_30990 = stack[-10];
    v_30990 = qcdr(v_30990);
    v_30990 = qcar(v_30990);
    fn = elt(env, 10); // listp
    v_30990 = (*qfn1(fn))(fn, v_30990);
    env = stack[-12];
    if (v_30990 == nil) goto v_30561;
    goto v_30572;
v_30568:
    v_30990 = stack[-10];
    v_30990 = qcdr(v_30990);
    v_30990 = qcar(v_30990);
    v_30991 = qcar(v_30990);
    goto v_30569;
v_30570:
    v_30990 = elt(env, 1); // list
    goto v_30571;
v_30572:
    goto v_30568;
v_30569:
    goto v_30570;
v_30571:
    if (v_30991 == v_30990) goto v_30567;
    else goto v_30561;
v_30567:
    v_30990 = stack[-10];
    v_30990 = qcdr(v_30990);
    v_30990 = qcar(v_30990);
    goto v_30559;
v_30561:
    v_30990 = nil;
v_30559:
    goto v_30553;
v_30555:
    v_30990 = nil;
v_30553:
    stack[-11] = v_30990;
    v_30990 = stack[-10];
    fn = elt(env, 11); // dummyp
    v_30990 = (*qfn1(fn))(fn, v_30990);
    env = stack[-12];
    stack[-6] = v_30990;
    if (v_30990 == nil) goto v_30584;
    goto v_30594;
v_30588:
    stack[-3] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30589;
v_30590:
    stack[-2] = stack[-6];
    goto v_30591;
v_30592:
    goto v_30604;
v_30598:
    stack[-1] = elt(env, 2); // !~dv
    goto v_30599;
v_30600:
    stack[0] = elt(env, 3); // !*
    goto v_30601;
v_30602:
    v_30990 = stack[-6];
    v_30990 = ncons(v_30990);
    env = stack[-12];
    goto v_30603;
v_30604:
    goto v_30598;
v_30599:
    goto v_30600;
v_30601:
    goto v_30602;
v_30603:
    v_30990 = list2star(stack[-1], stack[0], v_30990);
    goto v_30593;
v_30594:
    goto v_30588;
v_30589:
    goto v_30590;
v_30591:
    goto v_30592;
v_30593:
    {
        LispObject v_31005 = stack[-3];
        LispObject v_31006 = stack[-2];
        return list3(v_31005, v_31006, v_30990);
    }
v_30584:
    v_30990 = stack[-10];
    fn = elt(env, 10); // listp
    v_30990 = (*qfn1(fn))(fn, v_30990);
    env = stack[-12];
    if (v_30990 == nil) goto v_30613;
    else goto v_30614;
v_30613:
    v_30990 = lisp_true;
    goto v_30612;
v_30614:
    v_30990 = stack[-11];
    if (v_30990 == nil) goto v_30622;
    else goto v_30623;
v_30622:
    v_30990 = nil;
    goto v_30621;
v_30623:
    v_30990 = stack[-10];
    v_30990 = qcdr(v_30990);
    v_30990 = qcdr(v_30990);
    v_30990 = (v_30990 == nil ? lisp_true : nil);
    goto v_30621;
    v_30990 = nil;
v_30621:
    goto v_30612;
    v_30990 = nil;
v_30612:
    if (v_30990 == nil) goto v_30610;
    goto v_30639;
v_30633:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30634;
v_30635:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30636;
v_30637:
    v_30990 = stack[-10];
    v_30990 = ncons(v_30990);
    goto v_30638;
v_30639:
    goto v_30633;
v_30634:
    goto v_30635;
v_30636:
    goto v_30637;
v_30638:
    {
        LispObject v_31007 = stack[-1];
        LispObject v_31008 = stack[0];
        return list3(v_31007, v_31008, v_30990);
    }
v_30610:
    goto v_30649;
v_30645:
    v_30990 = stack[-10];
    v_30991 = qcar(v_30990);
    goto v_30646;
v_30647:
    v_30990 = elt(env, 4); // symtree
    goto v_30648;
v_30649:
    goto v_30645;
v_30646:
    goto v_30647;
v_30648:
    v_30990 = get(v_30991, v_30990);
    env = stack[-12];
    stack[-9] = v_30990;
    v_30990 = stack[-9];
    if (v_30990 == nil) goto v_30655;
    else goto v_30656;
v_30655:
    v_30990 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_30990;
    goto v_30675;
v_30671:
    v_30990 = stack[-11];
    if (v_30990 == nil) goto v_30680;
    v_30990 = stack[-10];
    v_30990 = qcdr(v_30990);
    v_30990 = qcdr(v_30990);
    goto v_30678;
v_30680:
    v_30990 = stack[-10];
    v_30990 = qcdr(v_30990);
    goto v_30678;
    v_30990 = nil;
v_30678:
    v_30991 = Llength(nil, v_30990);
    env = stack[-12];
    goto v_30672;
v_30673:
    v_30990 = stack[-3];
    goto v_30674;
v_30675:
    goto v_30671;
v_30672:
    goto v_30673;
v_30674:
    v_30990 = difference2(v_30991, v_30990);
    env = stack[-12];
    v_30990 = Lminusp(nil, v_30990);
    env = stack[-12];
    if (v_30990 == nil) goto v_30668;
    v_30990 = nil;
    goto v_30662;
v_30668:
    v_30990 = stack[-3];
    v_30990 = ncons(v_30990);
    env = stack[-12];
    stack[-1] = v_30990;
    stack[-2] = v_30990;
v_30663:
    v_30990 = stack[-3];
    v_30990 = add1(v_30990);
    env = stack[-12];
    stack[-3] = v_30990;
    goto v_30705;
v_30701:
    v_30990 = stack[-11];
    if (v_30990 == nil) goto v_30710;
    v_30990 = stack[-10];
    v_30990 = qcdr(v_30990);
    v_30990 = qcdr(v_30990);
    goto v_30708;
v_30710:
    v_30990 = stack[-10];
    v_30990 = qcdr(v_30990);
    goto v_30708;
    v_30990 = nil;
v_30708:
    v_30991 = Llength(nil, v_30990);
    env = stack[-12];
    goto v_30702;
v_30703:
    v_30990 = stack[-3];
    goto v_30704;
v_30705:
    goto v_30701;
v_30702:
    goto v_30703;
v_30704:
    v_30990 = difference2(v_30991, v_30990);
    env = stack[-12];
    v_30990 = Lminusp(nil, v_30990);
    env = stack[-12];
    if (v_30990 == nil) goto v_30698;
    v_30990 = stack[-2];
    goto v_30662;
v_30698:
    goto v_30726;
v_30722:
    stack[0] = stack[-1];
    goto v_30723;
v_30724:
    v_30990 = stack[-3];
    v_30990 = ncons(v_30990);
    env = stack[-12];
    goto v_30725;
v_30726:
    goto v_30722;
v_30723:
    goto v_30724;
v_30725:
    v_30990 = Lrplacd(nil, stack[0], v_30990);
    env = stack[-12];
    v_30990 = stack[-1];
    v_30990 = qcdr(v_30990);
    stack[-1] = v_30990;
    goto v_30663;
v_30662:
    stack[-9] = v_30990;
    v_30990 = stack[-10];
    v_30990 = qcar(v_30990);
    if (!symbolp(v_30990)) v_30990 = nil;
    else { v_30990 = qfastgets(v_30990);
           if (v_30990 != nil) { v_30990 = elt(v_30990, 43); // symmetric
#ifdef RECORD_GET
             if (v_30990 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v_30990 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v_30990 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v_30990 == SPID_NOPROP) v_30990 = nil; else v_30990 = lisp_true; }}
#endif
    if (v_30990 == nil) goto v_30735;
    goto v_30744;
v_30740:
    v_30991 = elt(env, 5); // !+
    goto v_30741;
v_30742:
    v_30990 = stack[-9];
    goto v_30743;
v_30744:
    goto v_30740;
v_30741:
    goto v_30742;
v_30743:
    v_30990 = cons(v_30991, v_30990);
    env = stack[-12];
    stack[-9] = v_30990;
    goto v_30733;
v_30735:
    goto v_30754;
v_30750:
    v_30990 = stack[-10];
    v_30991 = qcar(v_30990);
    goto v_30751;
v_30752:
    v_30990 = elt(env, 6); // antisymmetric
    goto v_30753;
v_30754:
    goto v_30750;
v_30751:
    goto v_30752;
v_30753:
    v_30990 = Lflagp(nil, v_30991, v_30990);
    env = stack[-12];
    if (v_30990 == nil) goto v_30748;
    goto v_30763;
v_30759:
    v_30991 = elt(env, 7); // !-
    goto v_30760;
v_30761:
    v_30990 = stack[-9];
    goto v_30762;
v_30763:
    goto v_30759;
v_30760:
    goto v_30761;
v_30762:
    v_30990 = cons(v_30991, v_30990);
    env = stack[-12];
    stack[-9] = v_30990;
    goto v_30733;
v_30748:
    goto v_30773;
v_30769:
    v_30991 = elt(env, 3); // !*
    goto v_30770;
v_30771:
    v_30990 = stack[-9];
    goto v_30772;
v_30773:
    goto v_30769;
v_30770:
    goto v_30771;
v_30772:
    v_30990 = cons(v_30991, v_30990);
    env = stack[-12];
    stack[-9] = v_30990;
    goto v_30733;
v_30733:
    goto v_30654;
v_30656:
v_30654:
    v_30990 = stack[-11];
    if (v_30990 == nil) goto v_30782;
    v_30990 = stack[-10];
    v_30990 = qcdr(v_30990);
    v_30990 = qcdr(v_30990);
    goto v_30780;
v_30782:
    v_30990 = stack[-10];
    v_30990 = qcdr(v_30990);
    goto v_30780;
    v_30990 = nil;
v_30780:
    v_30990 = Llength(nil, v_30990);
    env = stack[-12];
    v_30990 = sub1(v_30990);
    env = stack[-12];
    v_30990 = Lmkvect(nil, v_30990);
    env = stack[-12];
    stack[-8] = v_30990;
    v_30990 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_30990;
    v_30990 = stack[-11];
    if (v_30990 == nil) goto v_30799;
    v_30990 = stack[-10];
    v_30990 = qcdr(v_30990);
    v_30990 = qcdr(v_30990);
    goto v_30797;
v_30799:
    v_30990 = stack[-10];
    v_30990 = qcdr(v_30990);
    goto v_30797;
    v_30990 = nil;
v_30797:
    stack[-4] = v_30990;
v_30795:
    v_30990 = stack[-4];
    if (v_30990 == nil) goto v_30810;
    else goto v_30811;
v_30810:
    goto v_30794;
v_30811:
    v_30990 = stack[-4];
    v_30990 = qcar(v_30990);
    stack[-1] = v_30990;
    v_30990 = stack[-7];
    v_30990 = add1(v_30990);
    env = stack[-12];
    stack[-7] = v_30990;
    v_30990 = stack[-1];
    fn = elt(env, 11); // dummyp
    v_30990 = (*qfn1(fn))(fn, v_30990);
    env = stack[-12];
    stack[-6] = v_30990;
    if (v_30990 == nil) goto v_30822;
    goto v_30830;
v_30826:
    v_30991 = stack[-5];
    goto v_30827;
v_30828:
    v_30990 = stack[-6];
    goto v_30829;
v_30830:
    goto v_30826;
v_30827:
    goto v_30828;
v_30829:
    fn = elt(env, 12); // max
    v_30990 = (*qfn2(fn))(fn, v_30991, v_30990);
    env = stack[-12];
    stack[-5] = v_30990;
    v_30990 = stack[-1];
    if (symbolp(v_30990)) goto v_30835;
    else goto v_30836;
v_30835:
    goto v_30844;
v_30838:
    stack[-3] = stack[-8];
    goto v_30839;
v_30840:
    v_30990 = stack[-7];
    stack[-2] = sub1(v_30990);
    env = stack[-12];
    goto v_30841;
v_30842:
    goto v_30855;
v_30849:
    stack[-1] = elt(env, 2); // !~dv
    goto v_30850;
v_30851:
    stack[0] = elt(env, 3); // !*
    goto v_30852;
v_30853:
    v_30990 = stack[-6];
    v_30990 = ncons(v_30990);
    env = stack[-12];
    goto v_30854;
v_30855:
    goto v_30849;
v_30850:
    goto v_30851;
v_30852:
    goto v_30853;
v_30854:
    v_30990 = list2star(stack[-1], stack[0], v_30990);
    env = stack[-12];
    goto v_30843;
v_30844:
    goto v_30838;
v_30839:
    goto v_30840;
v_30841:
    goto v_30842;
v_30843:
    *(LispObject *)((char *)stack[-3] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-2]-TAG_FIXNUM)/(16/CELL))) = v_30990;
    goto v_30834;
v_30836:
    goto v_30868;
v_30862:
    stack[-3] = stack[-8];
    goto v_30863;
v_30864:
    v_30990 = stack[-7];
    stack[-2] = sub1(v_30990);
    env = stack[-12];
    goto v_30865;
v_30866:
    goto v_30879;
v_30873:
    stack[-1] = elt(env, 8); // !~dva
    goto v_30874;
v_30875:
    stack[0] = elt(env, 3); // !*
    goto v_30876;
v_30877:
    v_30990 = stack[-6];
    v_30990 = ncons(v_30990);
    env = stack[-12];
    goto v_30878;
v_30879:
    goto v_30873;
v_30874:
    goto v_30875;
v_30876:
    goto v_30877;
v_30878:
    v_30990 = list2star(stack[-1], stack[0], v_30990);
    env = stack[-12];
    goto v_30867;
v_30868:
    goto v_30862;
v_30863:
    goto v_30864;
v_30865:
    goto v_30866;
v_30867:
    *(LispObject *)((char *)stack[-3] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-2]-TAG_FIXNUM)/(16/CELL))) = v_30990;
    goto v_30834;
v_30834:
    goto v_30820;
v_30822:
    goto v_30892;
v_30886:
    stack[-2] = stack[-8];
    goto v_30887;
v_30888:
    v_30990 = stack[-7];
    stack[0] = sub1(v_30990);
    env = stack[-12];
    goto v_30889;
v_30890:
    v_30990 = stack[-1];
    v_30990 = ncons(v_30990);
    env = stack[-12];
    goto v_30891;
v_30892:
    goto v_30886;
v_30887:
    goto v_30888;
v_30889:
    goto v_30890;
v_30891:
    *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_30990;
    goto v_30820;
v_30820:
    v_30990 = stack[-4];
    v_30990 = qcdr(v_30990);
    stack[-4] = v_30990;
    goto v_30795;
v_30794:
    goto v_30908;
v_30902:
    v_30992 = stack[-9];
    goto v_30903;
v_30904:
    v_30991 = stack[-8];
    goto v_30905;
v_30906:
    v_30990 = elt(env, 9); // idcons_ordp
    goto v_30907;
v_30908:
    goto v_30902;
v_30903:
    goto v_30904;
v_30905:
    goto v_30906;
v_30907:
    fn = elt(env, 13); // st_sorttree
    v_30990 = (*qfnn(fn))(fn, 3, v_30992, v_30991, v_30990);
    env = stack[-12];
    stack[-9] = v_30990;
    v_30990 = stack[-9];
    if (v_30990 == nil) goto v_30915;
    goto v_30923;
v_30919:
    v_30990 = stack[-9];
    v_30991 = qcar(v_30990);
    goto v_30920;
v_30921:
    v_30990 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30922;
v_30923:
    goto v_30919;
v_30920:
    goto v_30921;
v_30922:
    if (v_30991 == v_30990) goto v_30918;
    else goto v_30915;
v_30918:
    v_30990 = nil;
    goto v_30546;
v_30915:
    v_30990 = stack[-9];
    v_30990 = qcar(v_30990);
    stack[0] = v_30990;
    goto v_30935;
v_30931:
    v_30990 = stack[-9];
    v_30991 = qcdr(v_30990);
    goto v_30932;
v_30933:
    v_30990 = stack[-8];
    goto v_30934;
v_30935:
    goto v_30931;
v_30932:
    goto v_30933;
v_30934:
    fn = elt(env, 14); // dv_skelsplit1
    v_30990 = (*qfn2(fn))(fn, v_30991, v_30990);
    env = stack[-12];
    stack[-1] = v_30990;
    v_30990 = stack[-1];
    v_30990 = qcdr(v_30990);
    fn = elt(env, 15); // st_consolidate
    v_30990 = (*qfn1(fn))(fn, v_30990);
    env = stack[-12];
    stack[-9] = v_30990;
    v_30990 = stack[-11];
    if (v_30990 == nil) goto v_30945;
    goto v_30954;
v_30948:
    v_30990 = stack[-10];
    v_30992 = qcar(v_30990);
    goto v_30949;
v_30950:
    v_30991 = stack[-11];
    goto v_30951;
v_30952:
    v_30990 = stack[-1];
    v_30990 = qcar(v_30990);
    goto v_30953;
v_30954:
    goto v_30948;
v_30949:
    goto v_30950;
v_30951:
    goto v_30952;
v_30953:
    v_30990 = list2star(v_30992, v_30991, v_30990);
    env = stack[-12];
    goto v_30943;
v_30945:
    goto v_30967;
v_30963:
    v_30990 = stack[-10];
    v_30991 = qcar(v_30990);
    goto v_30964;
v_30965:
    v_30990 = stack[-1];
    v_30990 = qcar(v_30990);
    goto v_30966;
v_30967:
    goto v_30963;
v_30964:
    goto v_30965;
v_30966:
    v_30990 = cons(v_30991, v_30990);
    env = stack[-12];
    goto v_30943;
    v_30990 = nil;
v_30943:
    stack[-1] = v_30990;
    goto v_30979;
v_30973:
    goto v_30974;
v_30975:
    stack[-2] = stack[-5];
    goto v_30976;
v_30977:
    goto v_30987;
v_30983:
    v_30991 = stack[-1];
    goto v_30984;
v_30985:
    v_30990 = stack[-9];
    goto v_30986;
v_30987:
    goto v_30983;
v_30984:
    goto v_30985;
v_30986:
    v_30990 = cons(v_30991, v_30990);
    goto v_30978;
v_30979:
    goto v_30973;
v_30974:
    goto v_30975;
v_30976:
    goto v_30977;
v_30978:
    {
        LispObject v_31009 = stack[0];
        LispObject v_31010 = stack[-2];
        return list3(v_31009, v_31010, v_30990);
    }
v_30546:
    return onevalue(v_30990);
}



// Code for rl_identifyonoff

static LispObject CC_rl_identifyonoff(LispObject env,
                         LispObject v_30535)
{
    env = qenv(env);
    LispObject v_30546;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30535);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30535);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_30546 = v_30535;
// end of prologue
    goto v_30542;
v_30538:
    stack[0] = qvalue(elt(env, 1)); // rl_identifyonoff!*
    goto v_30539;
v_30540:
    v_30546 = ncons(v_30546);
    env = stack[-1];
    goto v_30541;
v_30542:
    goto v_30538;
v_30539:
    goto v_30540;
v_30541:
    {
        LispObject v_30548 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_30548, v_30546);
    }
}



setup_type const u52_setup[] =
{
    {"qqe_simplqequal",         TOO_FEW_2,      CC_qqe_simplqequal,WRONG_NO_2},
    {"vdpfmon",                 TOO_FEW_2,      CC_vdpfmon,    WRONG_NO_2},
    {"xexptpf",                 TOO_FEW_2,      CC_xexptpf,    WRONG_NO_2},
    {"mk-contract-coeff",       CC_mkKcontractKcoeff,TOO_MANY_1,WRONG_NO_1},
    {"rule-list",               TOO_FEW_2,      CC_ruleKlist,  WRONG_NO_2},
    {"hdiff",                   TOO_FEW_2,      CC_hdiff,      WRONG_NO_2},
    {"test-bool",               CC_testKbool,   TOO_MANY_1,    WRONG_NO_1},
    {"combin",                  TOO_FEW_2,      CC_combin,     WRONG_NO_2},
    {"alistp",                  CC_alistp,      TOO_MANY_1,    WRONG_NO_1},
    {"coeffs-to-form1",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_coeffsKtoKform1},
    {"small-random-number",     WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_smallKrandomKnumber},
    {"quotf*",                  TOO_FEW_2,      CC_quotfH,     WRONG_NO_2},
    {"vsl_boundtype1",          TOO_FEW_2,      CC_vsl_boundtype1,WRONG_NO_2},
    {"ps:value",                CC_psTvalue,    TOO_MANY_1,    WRONG_NO_1},
    {"ldf-spf-var",             CC_ldfKspfKvar, TOO_MANY_1,    WRONG_NO_1},
    {"al1_defined_vertex",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_al1_defined_vertex},
    {"dp=comp",                 TOO_FEW_2,      CC_dpMcomp,    WRONG_NO_2},
    {"simp-prop-form",          CC_simpKpropKform,TOO_MANY_1,  WRONG_NO_1},
    {"can_rep_cell",            TOO_FEW_2,      CC_can_rep_cell,WRONG_NO_2},
    {"simpdot",                 CC_simpdot,     TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_bestgaussp",         CC_ofsf_bestgaussp,TOO_MANY_1, WRONG_NO_1},
    {"texexplode",              CC_texexplode,  TOO_MANY_1,    WRONG_NO_1},
    {"gigcd:",                  TOO_FEW_2,      CC_gigcdT,     WRONG_NO_2},
    {"simp-sign2",              CC_simpKsign2,  TOO_MANY_1,    WRONG_NO_1},
    {"qqe_prefix-length",       CC_qqe_prefixKlength,TOO_MANY_1,WRONG_NO_1},
    {"transferrow1",            CC_transferrow1,TOO_MANY_1,    WRONG_NO_1},
    {"f2dip2",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_f2dip2},
    {"symmetrize-inds",         TOO_FEW_2,      CC_symmetrizeKinds,WRONG_NO_2},
    {"coeff_sortl",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_coeff_sortl},
    {"subs2chkex",              CC_subs2chkex,  TOO_MANY_1,    WRONG_NO_1},
    {"simpsqrt3",               CC_simpsqrt3,   TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_smmkatl-or",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smmkatlKor},
    {"giprim",                  CC_giprim,      TOO_MANY_1,    WRONG_NO_1},
    {"talp_simplatfn",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_simplatfn},
    {"spmatsm*",                TOO_FEW_2,      CC_spmatsmH,   WRONG_NO_2},
    {"tchscheme",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_tchscheme},
    {"solvealgtrig01",          TOO_FEW_2,      CC_solvealgtrig01,WRONG_NO_2},
    {"normmat",                 CC_normmat,     TOO_MANY_1,    WRONG_NO_1},
    {"actual_arguments",        CC_actual_arguments,TOO_MANY_1,WRONG_NO_1},
    {"extract_numid",           CC_extract_numid,TOO_MANY_1,   WRONG_NO_1},
    {"dv_skelsplit",            CC_dv_skelsplit,TOO_MANY_1,    WRONG_NO_1},
    {"rl_identifyonoff",        CC_rl_identifyonoff,TOO_MANY_1,WRONG_NO_1},
    {NULL, (one_args *)"u52", (two_args *)"171577 3944440 9966890", 0}
};

// end of generated code
