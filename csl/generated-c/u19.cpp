
// $destdir/u19.c        Machine generated C code

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



// Code for ibalp_process!-var

static LispObject CC_ibalp_processKvar(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11050, v_11051, v_11052;
    LispObject fn;
    LispObject v_10760, v_10759, v_10758, v_10757;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ibalp_process-var");
    va_start(aa, nargs);
    v_10757 = va_arg(aa, LispObject);
    v_10758 = va_arg(aa, LispObject);
    v_10759 = va_arg(aa, LispObject);
    v_10760 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_10760,v_10759,v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_10757,v_10758,v_10759,v_10760);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(17);
// copy arguments values to proper place
    stack[-11] = v_10760;
    stack[-12] = v_10759;
    stack[-13] = v_10758;
    stack[-14] = v_10757;
// end of prologue
    goto v_10773;
v_10769:
    stack[0] = elt(env, 1); // !!
    goto v_10770;
v_10771:
    v_11050 = stack[-12];
    v_11050 = Lexplode(nil, v_11050);
    env = stack[-16];
    goto v_10772;
v_10773:
    goto v_10769;
v_10770:
    goto v_10771;
v_10772:
    v_11050 = cons(stack[0], v_11050);
    env = stack[-16];
    v_11050 = Lcompress(nil, v_11050);
    env = stack[-16];
    v_11050 = Lintern(nil, v_11050);
    env = stack[-16];
    stack[-12] = v_11050;
    goto v_10785;
v_10781:
    v_11051 = stack[-12];
    goto v_10782;
v_10783:
    v_11050 = stack[-13];
    goto v_10784;
v_10785:
    goto v_10781;
v_10782:
    goto v_10783;
v_10784:
    v_11050 = Latsoc(nil, v_11051, v_11050);
    v_11051 = v_11050;
    if (v_11050 == nil) goto v_10780;
    v_11050 = v_11051;
    v_11050 = qcdr(v_11050);
    stack[0] = v_11050;
    goto v_10778;
v_10780:
    goto v_10802;
v_10794:
    stack[-15] = stack[-12];
    goto v_10795;
v_10796:
    stack[-10] = nil;
    goto v_10797;
v_10798:
    stack[-9] = nil;
    goto v_10799;
v_10800:
    goto v_10815;
v_10807:
    stack[-8] = nil;
    goto v_10808;
v_10809:
    stack[-7] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10810;
v_10811:
    stack[-6] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10812;
v_10813:
    goto v_10828;
v_10820:
    stack[-5] = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_10821;
v_10822:
    stack[-4] = nil;
    goto v_10823;
v_10824:
    stack[-3] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10825;
v_10826:
    goto v_10841;
v_10833:
    stack[-2] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10834;
v_10835:
    stack[-1] = nil;
    goto v_10836;
v_10837:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10838;
v_10839:
    goto v_10852;
v_10846:
    v_11052 = nil;
    goto v_10847;
v_10848:
    v_11051 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10849;
v_10850:
    v_11050 = nil;
    goto v_10851;
v_10852:
    goto v_10846;
v_10847:
    goto v_10848;
v_10849:
    goto v_10850;
v_10851:
    v_11050 = list3(v_11052, v_11051, v_11050);
    env = stack[-16];
    goto v_10840;
v_10841:
    goto v_10833;
v_10834:
    goto v_10835;
v_10836:
    goto v_10837;
v_10838:
    goto v_10839;
v_10840:
    v_11050 = list3star(stack[-2], stack[-1], stack[0], v_11050);
    env = stack[-16];
    goto v_10827;
v_10828:
    goto v_10820;
v_10821:
    goto v_10822;
v_10823:
    goto v_10824;
v_10825:
    goto v_10826;
v_10827:
    v_11050 = list3star(stack[-5], stack[-4], stack[-3], v_11050);
    env = stack[-16];
    goto v_10814;
v_10815:
    goto v_10807;
v_10808:
    goto v_10809;
v_10810:
    goto v_10811;
v_10812:
    goto v_10813;
v_10814:
    v_11050 = list3star(stack[-8], stack[-7], stack[-6], v_11050);
    env = stack[-16];
    goto v_10801;
v_10802:
    goto v_10794;
v_10795:
    goto v_10796;
v_10797:
    goto v_10798;
v_10799:
    goto v_10800;
v_10801:
    v_11050 = list3star(stack[-15], stack[-10], stack[-9], v_11050);
    env = stack[-16];
    stack[0] = v_11050;
    goto v_10863;
v_10857:
    v_11052 = stack[-12];
    goto v_10858;
v_10859:
    v_11051 = stack[0];
    goto v_10860;
v_10861:
    v_11050 = stack[-13];
    goto v_10862;
v_10863:
    goto v_10857;
v_10858:
    goto v_10859;
v_10860:
    goto v_10861;
v_10862:
    v_11050 = acons(v_11052, v_11051, v_11050);
    env = stack[-16];
    stack[-13] = v_11050;
    goto v_10778;
v_10778:
    goto v_10876;
v_10872:
    v_11051 = stack[-11];
    goto v_10873;
v_10874:
    v_11050 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10875;
v_10876:
    goto v_10872;
v_10873:
    goto v_10874;
v_10875:
    v_11050 = Leqn(nil, v_11051, v_11050);
    env = stack[-16];
    if (v_11050 == nil) goto v_10870;
    goto v_10884;
v_10880:
    v_11050 = stack[0];
    v_11050 = qcdr(v_11050);
    stack[-1] = qcdr(v_11050);
    goto v_10881;
v_10882:
    goto v_10893;
v_10889:
    v_11051 = stack[-14];
    goto v_10890;
v_10891:
    v_11050 = stack[0];
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcar(v_11050);
    goto v_10892;
v_10893:
    goto v_10889;
v_10890:
    goto v_10891;
v_10892:
    v_11050 = cons(v_11051, v_11050);
    env = stack[-16];
    goto v_10883;
v_10884:
    goto v_10880;
v_10881:
    goto v_10882;
v_10883:
    fn = elt(env, 2); // setcar
    v_11050 = (*qfn2(fn))(fn, stack[-1], v_11050);
    env = stack[-16];
    goto v_10904;
v_10900:
    v_11050 = stack[0];
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    stack[-1] = qcdr(v_11050);
    goto v_10901;
v_10902:
    v_11050 = stack[0];
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcar(v_11050);
    v_11050 = add1(v_11050);
    env = stack[-16];
    goto v_10903;
v_10904:
    goto v_10900;
v_10901:
    goto v_10902;
v_10903:
    fn = elt(env, 2); // setcar
    v_11050 = (*qfn2(fn))(fn, stack[-1], v_11050);
    env = stack[-16];
    goto v_10922;
v_10918:
    v_11050 = stack[0];
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    stack[-1] = qcdr(v_11050);
    goto v_10919;
v_10920:
    v_11050 = stack[0];
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcar(v_11050);
    v_11050 = add1(v_11050);
    env = stack[-16];
    goto v_10921;
v_10922:
    goto v_10918;
v_10919:
    goto v_10920;
v_10921:
    fn = elt(env, 2); // setcar
    v_11050 = (*qfn2(fn))(fn, stack[-1], v_11050);
    env = stack[-16];
    goto v_10948;
v_10944:
    stack[-1] = stack[-14];
    goto v_10945;
v_10946:
    goto v_10955;
v_10951:
    v_11051 = stack[0];
    goto v_10952;
v_10953:
    v_11050 = stack[-14];
    v_11050 = qcar(v_11050);
    goto v_10954;
v_10955:
    goto v_10951;
v_10952:
    goto v_10953;
v_10954:
    v_11050 = cons(v_11051, v_11050);
    env = stack[-16];
    goto v_10947;
v_10948:
    goto v_10944;
v_10945:
    goto v_10946;
v_10947:
    fn = elt(env, 2); // setcar
    v_11050 = (*qfn2(fn))(fn, stack[-1], v_11050);
    goto v_10868;
v_10870:
    goto v_10966;
v_10962:
    v_11050 = stack[0];
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    stack[-1] = qcdr(v_11050);
    goto v_10963;
v_10964:
    goto v_10976;
v_10972:
    v_11051 = stack[-14];
    goto v_10973;
v_10974:
    v_11050 = stack[0];
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcar(v_11050);
    goto v_10975;
v_10976:
    goto v_10972;
v_10973:
    goto v_10974;
v_10975:
    v_11050 = cons(v_11051, v_11050);
    env = stack[-16];
    goto v_10965;
v_10966:
    goto v_10962;
v_10963:
    goto v_10964;
v_10965:
    fn = elt(env, 2); // setcar
    v_11050 = (*qfn2(fn))(fn, stack[-1], v_11050);
    env = stack[-16];
    goto v_10988;
v_10984:
    v_11050 = stack[0];
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    stack[-1] = qcdr(v_11050);
    goto v_10985;
v_10986:
    v_11050 = stack[0];
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcar(v_11050);
    v_11050 = add1(v_11050);
    env = stack[-16];
    goto v_10987;
v_10988:
    goto v_10984;
v_10985:
    goto v_10986;
v_10987:
    fn = elt(env, 2); // setcar
    v_11050 = (*qfn2(fn))(fn, stack[-1], v_11050);
    env = stack[-16];
    goto v_11008;
v_11004:
    v_11050 = stack[0];
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    stack[-1] = qcdr(v_11050);
    goto v_11005;
v_11006:
    v_11050 = stack[0];
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcdr(v_11050);
    v_11050 = qcar(v_11050);
    v_11050 = add1(v_11050);
    env = stack[-16];
    goto v_11007;
v_11008:
    goto v_11004;
v_11005:
    goto v_11006;
v_11007:
    fn = elt(env, 2); // setcar
    v_11050 = (*qfn2(fn))(fn, stack[-1], v_11050);
    env = stack[-16];
    goto v_11036;
v_11032:
    v_11050 = stack[-14];
    stack[-1] = qcdr(v_11050);
    goto v_11033;
v_11034:
    goto v_11044;
v_11040:
    v_11051 = stack[0];
    goto v_11041;
v_11042:
    v_11050 = stack[-14];
    v_11050 = qcdr(v_11050);
    v_11050 = qcar(v_11050);
    goto v_11043;
v_11044:
    goto v_11040;
v_11041:
    goto v_11042;
v_11043:
    v_11050 = cons(v_11051, v_11050);
    env = stack[-16];
    goto v_11035;
v_11036:
    goto v_11032;
v_11033:
    goto v_11034;
v_11035:
    fn = elt(env, 2); // setcar
    v_11050 = (*qfn2(fn))(fn, stack[-1], v_11050);
    goto v_10868;
v_10868:
    v_11050 = stack[-13];
    return onevalue(v_11050);
}



// Code for aex_simpleratp

static LispObject CC_aex_simpleratp(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10787, v_10788;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10787 = v_10757;
// end of prologue
    fn = elt(env, 1); // aex_ex
    v_10787 = (*qfn1(fn))(fn, v_10787);
    env = stack[-1];
    stack[0] = v_10787;
    v_10787 = stack[0];
    v_10787 = qcar(v_10787);
    if (is_number(v_10787)) goto v_10768;
    v_10787 = nil;
    goto v_10766;
v_10768:
    goto v_10779;
v_10775:
    v_10787 = stack[0];
    v_10788 = qcar(v_10787);
    goto v_10776;
v_10777:
    v_10787 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10778;
v_10779:
    goto v_10775;
v_10776:
    goto v_10777;
v_10778:
    v_10787 = Leqn(nil, v_10788, v_10787);
    v_10787 = (v_10787 == nil ? lisp_true : nil);
    goto v_10766;
    v_10787 = nil;
v_10766:
    if (v_10787 == nil) goto v_10764;
    else goto v_10763;
v_10764:
    v_10787 = stack[0];
    v_10787 = qcar(v_10787);
    v_10787 = (v_10787 == nil ? lisp_true : nil);
v_10763:
    return onevalue(v_10787);
}



// Code for exptpri

static LispObject CC_exptpri(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_11173, v_11174, v_11175;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10757,v_10758);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    v_11173 = v_10758;
    stack[-5] = v_10757;
// end of prologue
    v_11174 = qvalue(elt(env, 1)); // !*utf8
    if (v_11174 == nil) goto v_10763;
    goto v_10770;
v_10766:
    v_11174 = stack[-5];
    goto v_10767;
v_10768:
    goto v_10769;
v_10770:
    goto v_10766;
v_10767:
    goto v_10768;
v_10769:
    {
        fn = elt(env, 18); // utf8_exptpri
        return (*qfn2(fn))(fn, v_11174, v_11173);
    }
v_10763:
// Binding !*list
// FLUIDBIND: reloadenv=7 litvec-offset=2 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 2, -6);
    qvalue(elt(env, 2)) = nil; // !*list
    stack[0] = nil;
    v_11174 = qvalue(elt(env, 3)); // !*nat
    if (v_11174 == nil) goto v_10789;
    else goto v_10790;
v_10789:
    v_11174 = lisp_true;
    goto v_10788;
v_10790:
    v_11174 = qvalue(elt(env, 4)); // !*fort
    goto v_10788;
    v_11174 = nil;
v_10788:
    if (v_11174 == nil) goto v_10786;
    v_11173 = elt(env, 5); // failed
    goto v_10782;
v_10786:
    goto v_10802;
v_10798:
    v_11174 = elt(env, 6); // expt
    if (!symbolp(v_11174)) v_11174 = nil;
    else { v_11174 = qfastgets(v_11174);
           if (v_11174 != nil) { v_11174 = elt(v_11174, 23); // infix
#ifdef RECORD_GET
             if (v_11174 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_11174 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_11174 == SPID_NOPROP) v_11174 = nil; }}
#endif
    stack[-2] = v_11174;
    goto v_10799;
v_10800:
    goto v_10801;
v_10802:
    goto v_10798;
v_10799:
    goto v_10800;
v_10801:
    v_11173 = (LispObject)greaterp2(v_11174, v_11173);
    v_11173 = v_11173 ? lisp_true : nil;
    env = stack[-7];
    v_11173 = (v_11173 == nil ? lisp_true : nil);
    stack[-4] = v_11173;
    v_11173 = stack[-5];
    v_11173 = qcdr(v_11173);
    v_11173 = qcar(v_11173);
    stack[-1] = v_11173;
    v_11173 = stack[-5];
    v_11173 = qcdr(v_11173);
    v_11173 = qcdr(v_11173);
    v_11173 = qcar(v_11173);
    stack[-3] = v_11173;
    v_11173 = qvalue(elt(env, 7)); // !*eraise
    if (v_11173 == nil) goto v_10817;
    v_11173 = stack[-1];
    if (!consp(v_11173)) goto v_10824;
    v_11173 = stack[-1];
    v_11173 = qcar(v_11173);
    if (!symbolp(v_11173)) v_11173 = nil;
    else { v_11173 = qfastgets(v_11173);
           if (v_11173 != nil) { v_11173 = elt(v_11173, 57); // prifn
#ifdef RECORD_GET
             if (v_11173 != SPID_NOPROP)
                record_get(elt(fastget_names, 57), 1);
             else record_get(elt(fastget_names, 57), 0),
                v_11173 = nil; }
           else record_get(elt(fastget_names, 57), 0); }
#else
             if (v_11173 == SPID_NOPROP) v_11173 = nil; }}
#endif
    stack[0] = v_11173;
    if (v_11173 == nil) goto v_10828;
    else goto v_10829;
v_10828:
    v_11173 = nil;
    goto v_10827;
v_10829:
    goto v_10840;
v_10836:
    goto v_10846;
v_10842:
    v_11174 = stack[0];
    goto v_10843;
v_10844:
    v_11173 = elt(env, 6); // expt
    goto v_10845;
v_10846:
    goto v_10842;
v_10843:
    goto v_10844;
v_10845:
    v_11174 = get(v_11174, v_11173);
    env = stack[-7];
    goto v_10837;
v_10838:
    v_11173 = elt(env, 8); // inbrackets
    goto v_10839;
v_10840:
    goto v_10836;
v_10837:
    goto v_10838;
v_10839:
    v_11173 = (v_11174 == v_11173 ? lisp_true : nil);
    goto v_10827;
    v_11173 = nil;
v_10827:
    goto v_10822;
v_10824:
    v_11173 = nil;
    goto v_10822;
    v_11173 = nil;
v_10822:
    if (v_11173 == nil) goto v_10817;
    goto v_10861;
v_10855:
    v_11175 = stack[-1];
    goto v_10856;
v_10857:
    v_11174 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10858;
v_10859:
    v_11173 = elt(env, 8); // inbrackets
    goto v_10860;
v_10861:
    goto v_10855;
v_10856:
    goto v_10857;
v_10858:
    goto v_10859;
v_10860:
    fn = elt(env, 19); // layout!-formula
    v_11173 = (*qfnn(fn))(fn, 3, v_11175, v_11174, v_11173);
    env = stack[-7];
    stack[-1] = v_11173;
    goto v_10815;
v_10817:
    goto v_10875;
v_10871:
    v_11174 = stack[0];
    goto v_10872;
v_10873:
    v_11173 = elt(env, 9); // indexprin
    goto v_10874;
v_10875:
    goto v_10871;
v_10872:
    goto v_10873;
v_10874:
    if (v_11174 == v_11173) goto v_10869;
    else goto v_10870;
v_10869:
    goto v_10882;
v_10878:
    goto v_10888;
v_10884:
    v_11174 = stack[-1];
    goto v_10885;
v_10886:
    v_11173 = stack[-3];
    goto v_10887;
v_10888:
    goto v_10884;
v_10885:
    goto v_10886;
v_10887:
    fn = elt(env, 20); // indexpower
    v_11174 = (*qfn2(fn))(fn, v_11174, v_11173);
    env = stack[-7];
    goto v_10879;
v_10880:
    v_11173 = elt(env, 5); // failed
    goto v_10881;
v_10882:
    goto v_10878;
v_10879:
    goto v_10880;
v_10881:
    v_11173 = (v_11174 == v_11173 ? lisp_true : nil);
    v_11173 = (v_11173 == nil ? lisp_true : nil);
    goto v_10868;
v_10870:
    v_11173 = nil;
    goto v_10868;
    v_11173 = nil;
v_10868:
    if (v_11173 == nil) goto v_10866;
    v_11173 = nil;
    goto v_10782;
v_10866:
    goto v_10907;
v_10901:
    v_11175 = stack[-1];
    goto v_10902;
v_10903:
    v_11174 = stack[-2];
    goto v_10904;
v_10905:
    v_11173 = nil;
    goto v_10906;
v_10907:
    goto v_10901;
v_10902:
    goto v_10903;
v_10904:
    goto v_10905;
v_10906:
    fn = elt(env, 19); // layout!-formula
    v_11173 = (*qfnn(fn))(fn, 3, v_11175, v_11174, v_11173);
    env = stack[-7];
    stack[-1] = v_11173;
    goto v_10815;
v_10815:
    v_11173 = stack[-1];
    if (v_11173 == nil) goto v_10913;
    else goto v_10914;
v_10913:
    v_11173 = elt(env, 5); // failed
    goto v_10782;
v_10914:
// Binding !*ratpri
// FLUIDBIND: reloadenv=7 litvec-offset=10 saveloc=5
{   bind_fluid_stack bind_fluid_var(-7, 10, -5);
    qvalue(elt(env, 10)) = nil; // !*ratpri
    goto v_10933;
v_10929:
    v_11174 = stack[-3];
    goto v_10930;
v_10931:
    v_11173 = elt(env, 11); // quotient
    goto v_10932;
v_10933:
    goto v_10929;
v_10930:
    goto v_10931;
v_10932:
    if (!consp(v_11174)) goto v_10927;
    v_11174 = qcar(v_11174);
    if (v_11174 == v_11173) goto v_10926;
    else goto v_10927;
v_10926:
    goto v_10941;
v_10937:
    v_11173 = stack[-3];
    v_11173 = qcdr(v_11173);
    v_11174 = qcar(v_11173);
    goto v_10938;
v_10939:
    v_11173 = elt(env, 12); // minus
    goto v_10940;
v_10941:
    goto v_10937;
v_10938:
    goto v_10939;
v_10940:
    v_11173 = Leqcar(nil, v_11174, v_11173);
    env = stack[-7];
    goto v_10925;
v_10927:
    v_11173 = nil;
    goto v_10925;
    v_11173 = nil;
v_10925:
    if (v_11173 == nil) goto v_10923;
    goto v_10954;
v_10950:
    stack[0] = elt(env, 12); // minus
    goto v_10951;
v_10952:
    goto v_10963;
v_10957:
    v_11173 = stack[-3];
    v_11175 = qcar(v_11173);
    goto v_10958;
v_10959:
    v_11173 = stack[-3];
    v_11173 = qcdr(v_11173);
    v_11173 = qcar(v_11173);
    v_11173 = qcdr(v_11173);
    v_11174 = qcar(v_11173);
    goto v_10960;
v_10961:
    v_11173 = stack[-3];
    v_11173 = qcdr(v_11173);
    v_11173 = qcdr(v_11173);
    v_11173 = qcar(v_11173);
    goto v_10962;
v_10963:
    goto v_10957;
v_10958:
    goto v_10959;
v_10960:
    goto v_10961;
v_10962:
    v_11173 = list3(v_11175, v_11174, v_11173);
    env = stack[-7];
    goto v_10953;
v_10954:
    goto v_10950;
v_10951:
    goto v_10952;
v_10953:
    v_11173 = list2(stack[0], v_11173);
    env = stack[-7];
    stack[-3] = v_11173;
    goto v_10921;
v_10923:
    v_11173 = stack[-3];
    fn = elt(env, 21); // negnumberchk
    v_11173 = (*qfn1(fn))(fn, v_11173);
    env = stack[-7];
    stack[-3] = v_11173;
    goto v_10921;
v_10921:
    goto v_10986;
v_10980:
    v_11175 = stack[-3];
    goto v_10981;
v_10982:
    v_11173 = qvalue(elt(env, 7)); // !*eraise
    if (v_11173 == nil) goto v_10991;
    v_11173 = (LispObject)0+TAG_FIXNUM; // 0
    v_11174 = v_11173;
    goto v_10989;
v_10991:
    v_11173 = stack[-2];
    v_11174 = v_11173;
    goto v_10989;
    v_11174 = nil;
v_10989:
    goto v_10983;
v_10984:
    v_11173 = nil;
    goto v_10985;
v_10986:
    goto v_10980;
v_10981:
    goto v_10982;
v_10983:
    goto v_10984;
v_10985:
    fn = elt(env, 19); // layout!-formula
    v_11173 = (*qfnn(fn))(fn, 3, v_11175, v_11174, v_11173);
    env = stack[-7];
    stack[-3] = v_11173;
    ;}  // end of a binding scope
    v_11173 = stack[-3];
    if (v_11173 == nil) goto v_11000;
    else goto v_11001;
v_11000:
    v_11173 = elt(env, 5); // failed
    goto v_10782;
v_11001:
    goto v_11009;
v_11005:
    v_11173 = stack[-1];
    v_11173 = qcar(v_11173);
    v_11174 = qcdr(v_11173);
    goto v_11006;
v_11007:
    v_11173 = stack[-3];
    v_11173 = qcar(v_11173);
    v_11173 = qcdr(v_11173);
    goto v_11008;
v_11009:
    goto v_11005;
v_11006:
    goto v_11007;
v_11008:
    v_11173 = plus2(v_11174, v_11173);
    env = stack[-7];
    stack[-5] = v_11173;
    v_11173 = stack[-4];
    if (v_11173 == nil) goto v_11019;
    goto v_11026;
v_11022:
    v_11174 = stack[-5];
    goto v_11023;
v_11024:
    v_11173 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_11025;
v_11026:
    goto v_11022;
v_11023:
    goto v_11024;
v_11025:
    v_11173 = plus2(v_11174, v_11173);
    env = stack[-7];
    stack[-5] = v_11173;
    goto v_11017;
v_11019:
v_11017:
    goto v_11038;
v_11034:
    stack[0] = stack[-5];
    goto v_11035;
v_11036:
    goto v_11045;
v_11041:
    goto v_11051;
v_11047:
    v_11173 = nil;
    v_11174 = Llinelength(nil, v_11173);
    env = stack[-7];
    goto v_11048;
v_11049:
    v_11173 = qvalue(elt(env, 13)); // spare!*
    goto v_11050;
v_11051:
    goto v_11047;
v_11048:
    goto v_11049;
v_11050:
    v_11174 = difference2(v_11174, v_11173);
    env = stack[-7];
    goto v_11042;
v_11043:
    v_11173 = qvalue(elt(env, 14)); // orig!*
    goto v_11044;
v_11045:
    goto v_11041;
v_11042:
    goto v_11043;
v_11044:
    v_11173 = difference2(v_11174, v_11173);
    env = stack[-7];
    goto v_11037;
v_11038:
    goto v_11034;
v_11035:
    goto v_11036;
v_11037:
    v_11173 = (LispObject)greaterp2(stack[0], v_11173);
    v_11173 = v_11173 ? lisp_true : nil;
    env = stack[-7];
    if (v_11173 == nil) goto v_11032;
    v_11173 = elt(env, 5); // failed
    goto v_10782;
v_11032:
    goto v_11066;
v_11062:
    stack[0] = stack[-5];
    goto v_11063;
v_11064:
    goto v_11073;
v_11069:
    goto v_11079;
v_11075:
    v_11173 = nil;
    v_11174 = Llinelength(nil, v_11173);
    env = stack[-7];
    goto v_11076;
v_11077:
    v_11173 = qvalue(elt(env, 13)); // spare!*
    goto v_11078;
v_11079:
    goto v_11075;
v_11076:
    goto v_11077;
v_11078:
    v_11174 = difference2(v_11174, v_11173);
    env = stack[-7];
    goto v_11070;
v_11071:
    v_11173 = qvalue(elt(env, 15)); // posn!*
    goto v_11072;
v_11073:
    goto v_11069;
v_11070:
    goto v_11071;
v_11072:
    v_11173 = difference2(v_11174, v_11173);
    env = stack[-7];
    goto v_11065;
v_11066:
    goto v_11062;
v_11063:
    goto v_11064;
v_11065:
    v_11173 = (LispObject)greaterp2(stack[0], v_11173);
    v_11173 = v_11173 ? lisp_true : nil;
    env = stack[-7];
    if (v_11173 == nil) goto v_11060;
    v_11173 = lisp_true;
    fn = elt(env, 22); // terpri!*
    v_11173 = (*qfn1(fn))(fn, v_11173);
    env = stack[-7];
    goto v_11058;
v_11060:
v_11058:
    v_11173 = stack[-4];
    if (v_11173 == nil) goto v_11089;
    v_11173 = elt(env, 16); // "("
    fn = elt(env, 23); // prin2!*
    v_11173 = (*qfn1(fn))(fn, v_11173);
    env = stack[-7];
    goto v_11087;
v_11089:
v_11087:
    v_11173 = stack[-1];
    fn = elt(env, 24); // putpline
    v_11173 = (*qfn1(fn))(fn, v_11173);
    env = stack[-7];
    v_11173 = qvalue(elt(env, 7)); // !*eraise
    if (v_11173 == nil) goto v_11098;
    goto v_11105;
v_11101:
    v_11174 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11102;
v_11103:
    v_11173 = stack[-3];
    v_11173 = qcdr(v_11173);
    v_11173 = qcar(v_11173);
    goto v_11104;
v_11105:
    goto v_11101;
v_11102:
    goto v_11103;
v_11104:
    v_11173 = difference2(v_11174, v_11173);
    env = stack[-7];
    stack[-5] = v_11173;
    goto v_11096;
v_11098:
    v_11173 = elt(env, 6); // expt
    fn = elt(env, 25); // oprin
    v_11173 = (*qfn1(fn))(fn, v_11173);
    env = stack[-7];
    v_11173 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_11173;
    goto v_11096;
v_11096:
    goto v_11123;
v_11117:
    goto v_11131;
v_11125:
    v_11175 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11126;
v_11127:
    v_11174 = stack[-5];
    goto v_11128;
v_11129:
    v_11173 = stack[-3];
    v_11173 = qcar(v_11173);
    v_11173 = qcar(v_11173);
    goto v_11130;
v_11131:
    goto v_11125;
v_11126:
    goto v_11127;
v_11128:
    goto v_11129;
v_11130:
    fn = elt(env, 26); // update!-pline
    stack[-2] = (*qfnn(fn))(fn, 3, v_11175, v_11174, v_11173);
    env = stack[-7];
    goto v_11118;
v_11119:
    v_11173 = stack[-3];
    v_11173 = qcar(v_11173);
    stack[-1] = qcdr(v_11173);
    goto v_11120;
v_11121:
    goto v_11145;
v_11141:
    goto v_11151;
v_11147:
    v_11173 = stack[-3];
    v_11173 = qcdr(v_11173);
    v_11174 = qcar(v_11173);
    goto v_11148;
v_11149:
    v_11173 = stack[-5];
    goto v_11150;
v_11151:
    goto v_11147;
v_11148:
    goto v_11149;
v_11150:
    stack[0] = plus2(v_11174, v_11173);
    env = stack[-7];
    goto v_11142;
v_11143:
    goto v_11161;
v_11157:
    v_11173 = stack[-3];
    v_11173 = qcdr(v_11173);
    v_11174 = qcdr(v_11173);
    goto v_11158;
v_11159:
    v_11173 = stack[-5];
    goto v_11160;
v_11161:
    goto v_11157;
v_11158:
    goto v_11159;
v_11160:
    v_11173 = plus2(v_11174, v_11173);
    env = stack[-7];
    goto v_11144;
v_11145:
    goto v_11141;
v_11142:
    goto v_11143;
v_11144:
    v_11173 = cons(stack[0], v_11173);
    env = stack[-7];
    goto v_11122;
v_11123:
    goto v_11117;
v_11118:
    goto v_11119;
v_11120:
    goto v_11121;
v_11122:
    v_11173 = acons(stack[-2], stack[-1], v_11173);
    env = stack[-7];
    fn = elt(env, 24); // putpline
    v_11173 = (*qfn1(fn))(fn, v_11173);
    env = stack[-7];
    v_11173 = stack[-4];
    if (v_11173 == nil) goto v_11169;
    v_11173 = elt(env, 17); // ")"
    fn = elt(env, 23); // prin2!*
    v_11173 = (*qfn1(fn))(fn, v_11173);
    goto v_11167;
v_11169:
v_11167:
    v_11173 = nil;
v_10782:
    ;}  // end of a binding scope
    goto v_10761;
    v_11173 = nil;
v_10761:
    return onevalue(v_11173);
}



// Code for tobvarir

static LispObject CC_tobvarir(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10787, v_10788;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_10757;
// end of prologue
    v_10787 = stack[-1];
    if (v_10787 == nil) goto v_10764;
    goto v_10773;
v_10767:
    stack[-2] = elt(env, 1); // bvar
    goto v_10768;
v_10769:
    goto v_10780;
v_10776:
    v_10787 = stack[-1];
    v_10788 = qcar(v_10787);
    goto v_10777;
v_10778:
    v_10787 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10779;
v_10780:
    goto v_10776;
v_10777:
    goto v_10778;
v_10779:
    stack[0] = list2(v_10788, v_10787);
    env = stack[-3];
    goto v_10770;
v_10771:
    v_10787 = stack[-1];
    v_10787 = qcdr(v_10787);
    v_10787 = CC_tobvarir(elt(env, 0), v_10787);
    goto v_10772;
v_10773:
    goto v_10767;
v_10768:
    goto v_10769;
v_10770:
    goto v_10771;
v_10772:
    {
        LispObject v_10792 = stack[-2];
        LispObject v_10793 = stack[0];
        return acons(v_10792, v_10793, v_10787);
    }
v_10764:
    v_10787 = nil;
    return onevalue(v_10787);
}



// Code for floatprop

static LispObject CC_floatprop(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10772, v_10773;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_10772 = v_10757;
// end of prologue
    v_10773 = v_10772;
    v_10773 = Lfloatp(nil, v_10773);
    env = stack[0];
    if (v_10773 == nil) goto v_10761;
    else goto v_10760;
v_10761:
    goto v_10769;
v_10765:
    goto v_10766;
v_10767:
    v_10773 = elt(env, 1); // !:rd!:
    goto v_10768;
v_10769:
    goto v_10765;
v_10766:
    goto v_10767;
v_10768:
        return Leqcar(nil, v_10772, v_10773);
v_10760:
    return onevalue(v_10773);
}



// Code for inttovec

static LispObject CC_inttovec(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_10775, v_10776;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10757,v_10758);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10776 = v_10758;
    v_10775 = v_10757;
// end of prologue
    goto v_10765;
v_10761:
    stack[0] = v_10776;
    goto v_10762;
v_10763:
    goto v_10772;
v_10768:
    goto v_10769;
v_10770:
    goto v_10771;
v_10772:
    goto v_10768;
v_10769:
    goto v_10770;
v_10771:
    fn = elt(env, 1); // inttovec!-solve
    v_10775 = (*qfn2(fn))(fn, v_10776, v_10775);
    env = stack[-1];
    goto v_10764;
v_10765:
    goto v_10761;
v_10762:
    goto v_10763;
v_10764:
    {
        LispObject v_10778 = stack[0];
        fn = elt(env, 2); // inttovec1
        return (*qfn2(fn))(fn, v_10778, v_10775);
    }
}



// Code for physopaeval

static LispObject CC_physopaeval(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10855, v_10856, v_10857;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10757;
// end of prologue
    v_10855 = stack[0];
    fn = elt(env, 3); // physopp
    v_10855 = (*qfn1(fn))(fn, v_10855);
    env = stack[-1];
    if (v_10855 == nil) goto v_10765;
    v_10855 = stack[0];
    if (!symbolp(v_10855)) v_10855 = nil;
    else { v_10855 = qfastgets(v_10855);
           if (v_10855 != nil) { v_10855 = elt(v_10855, 46); // rvalue
#ifdef RECORD_GET
             if (v_10855 != SPID_NOPROP)
                record_get(elt(fastget_names, 46), 1);
             else record_get(elt(fastget_names, 46), 0),
                v_10855 = nil; }
           else record_get(elt(fastget_names, 46), 0); }
#else
             if (v_10855 == SPID_NOPROP) v_10855 = nil; }}
#endif
    v_10857 = v_10855;
    if (v_10855 == nil) goto v_10771;
    goto v_10782;
v_10778:
    v_10855 = v_10857;
    v_10856 = qcar(v_10855);
    goto v_10779;
v_10780:
    v_10855 = elt(env, 1); // !*sq
    goto v_10781;
v_10782:
    goto v_10778;
v_10779:
    goto v_10780;
v_10781:
    if (v_10856 == v_10855) goto v_10776;
    else goto v_10777;
v_10776:
    v_10855 = v_10857;
    v_10855 = qcdr(v_10855);
    v_10855 = qcar(v_10855);
    {
        fn = elt(env, 4); // !*q2a
        return (*qfn1(fn))(fn, v_10855);
    }
v_10777:
    v_10855 = v_10857;
    goto v_10775;
    v_10855 = nil;
v_10775:
    goto v_10769;
v_10771:
    v_10855 = stack[0];
    if (!consp(v_10855)) goto v_10793;
    else goto v_10794;
v_10793:
    v_10855 = stack[0];
    goto v_10769;
v_10794:
    goto v_10804;
v_10800:
    v_10855 = stack[0];
    v_10856 = qcar(v_10855);
    goto v_10801;
v_10802:
    v_10855 = elt(env, 2); // psimpfn
    goto v_10803;
v_10804:
    goto v_10800;
v_10801:
    goto v_10802;
v_10803:
    v_10855 = get(v_10856, v_10855);
    env = stack[-1];
    v_10857 = v_10855;
    if (v_10855 == nil) goto v_10798;
    goto v_10813;
v_10809:
    v_10856 = v_10857;
    goto v_10810;
v_10811:
    v_10855 = stack[0];
    goto v_10812;
v_10813:
    goto v_10809;
v_10810:
    goto v_10811;
v_10812:
        return Lapply1(nil, v_10856, v_10855);
v_10798:
    v_10855 = stack[0];
    v_10855 = qcar(v_10855);
    if (!symbolp(v_10855)) v_10855 = nil;
    else { v_10855 = qfastgets(v_10855);
           if (v_10855 != nil) { v_10855 = elt(v_10855, 9); // opmtch
#ifdef RECORD_GET
             if (v_10855 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_10855 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_10855 == SPID_NOPROP) v_10855 = nil; }}
#endif
    if (v_10855 == nil) goto v_10817;
    v_10855 = stack[0];
    fn = elt(env, 5); // opmtch!*
    v_10855 = (*qfn1(fn))(fn, v_10855);
    v_10857 = v_10855;
    if (v_10855 == nil) goto v_10817;
    v_10855 = v_10857;
    goto v_10769;
v_10817:
    v_10855 = stack[0];
    goto v_10769;
    v_10855 = nil;
v_10769:
    goto v_10763;
v_10765:
    v_10855 = stack[0];
    if (!consp(v_10855)) goto v_10834;
    goto v_10840;
v_10836:
    v_10855 = stack[0];
    v_10856 = qcar(v_10855);
    goto v_10837;
v_10838:
    v_10855 = elt(env, 1); // !*sq
    goto v_10839;
v_10840:
    goto v_10836;
v_10837:
    goto v_10838;
v_10839:
    v_10855 = (v_10856 == v_10855 ? lisp_true : nil);
    goto v_10832;
v_10834:
    v_10855 = nil;
    goto v_10832;
    v_10855 = nil;
v_10832:
    if (v_10855 == nil) goto v_10830;
    v_10855 = stack[0];
    v_10855 = qcdr(v_10855);
    v_10855 = qcar(v_10855);
    {
        fn = elt(env, 4); // !*q2a
        return (*qfn1(fn))(fn, v_10855);
    }
v_10830:
    v_10855 = stack[0];
    goto v_10763;
    v_10855 = nil;
v_10763:
    return onevalue(v_10855);
}



// Code for mkarray1

static LispObject CC_mkarray1(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_10832, v_10833;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10757,v_10758);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_10758;
    stack[-5] = v_10757;
// end of prologue
    v_10832 = stack[-5];
    if (v_10832 == nil) goto v_10762;
    else goto v_10763;
v_10762:
    goto v_10773;
v_10769:
    v_10832 = stack[-4];
    goto v_10770;
v_10771:
    v_10833 = elt(env, 1); // symbolic
    goto v_10772;
v_10773:
    goto v_10769;
v_10770:
    goto v_10771;
v_10772:
    if (v_10832 == v_10833) goto v_10767;
    else goto v_10768;
v_10767:
    v_10832 = nil;
    goto v_10766;
v_10768:
    v_10832 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10766;
    v_10832 = nil;
v_10766:
    goto v_10761;
v_10763:
    v_10832 = stack[-5];
    v_10832 = qcar(v_10832);
    v_10832 = sub1(v_10832);
    env = stack[-7];
    stack[-6] = v_10832;
    v_10832 = stack[-6];
    v_10832 = Lmkvect(nil, v_10832);
    env = stack[-7];
    stack[-3] = v_10832;
    v_10832 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_10832;
v_10795:
    goto v_10807;
v_10803:
    v_10833 = stack[-6];
    goto v_10804;
v_10805:
    v_10832 = stack[-2];
    goto v_10806;
v_10807:
    goto v_10803;
v_10804:
    goto v_10805;
v_10806:
    v_10832 = difference2(v_10833, v_10832);
    env = stack[-7];
    v_10832 = Lminusp(nil, v_10832);
    env = stack[-7];
    if (v_10832 == nil) goto v_10800;
    goto v_10794;
v_10800:
    goto v_10817;
v_10811:
    stack[-1] = stack[-3];
    goto v_10812;
v_10813:
    stack[0] = stack[-2];
    goto v_10814;
v_10815:
    goto v_10825;
v_10821:
    v_10832 = stack[-5];
    v_10833 = qcdr(v_10832);
    goto v_10822;
v_10823:
    v_10832 = stack[-4];
    goto v_10824;
v_10825:
    goto v_10821;
v_10822:
    goto v_10823;
v_10824:
    v_10832 = CC_mkarray1(elt(env, 0), v_10833, v_10832);
    env = stack[-7];
    goto v_10816;
v_10817:
    goto v_10811;
v_10812:
    goto v_10813;
v_10814:
    goto v_10815;
v_10816:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_10832;
    v_10832 = stack[-2];
    v_10832 = add1(v_10832);
    env = stack[-7];
    stack[-2] = v_10832;
    goto v_10795;
v_10794:
    v_10832 = stack[-3];
    goto v_10761;
    v_10832 = nil;
v_10761:
    return onevalue(v_10832);
}



// Code for mo_from_a

static LispObject CC_mo_from_a(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10865, v_10866;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_10757;
// end of prologue
    goto v_10767;
v_10763:
    stack[0] = stack[-3];
    goto v_10764;
v_10765:
    v_10865 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 3); // ring_all_names
    v_10865 = (*qfn1(fn))(fn, v_10865);
    env = stack[-5];
    goto v_10766;
v_10767:
    goto v_10763;
v_10764:
    goto v_10765;
v_10766:
    v_10865 = Lmember(nil, stack[0], v_10865);
    if (v_10865 == nil) goto v_10761;
    else goto v_10762;
v_10761:
    goto v_10777;
v_10773:
    v_10866 = stack[-3];
    goto v_10774;
v_10775:
    v_10865 = elt(env, 2); // "dpoly variable"
    goto v_10776;
v_10777:
    goto v_10773;
v_10774:
    goto v_10775;
v_10776:
    {
        fn = elt(env, 4); // typerr
        return (*qfn2(fn))(fn, v_10866, v_10865);
    }
v_10762:
    v_10865 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 3); // ring_all_names
    v_10865 = (*qfn1(fn))(fn, v_10865);
    env = stack[-5];
    stack[-4] = v_10865;
    v_10865 = stack[-4];
    if (v_10865 == nil) goto v_10797;
    else goto v_10798;
v_10797:
    v_10865 = nil;
    goto v_10791;
v_10798:
    v_10865 = stack[-4];
    v_10865 = qcar(v_10865);
    goto v_10813;
v_10809:
    v_10866 = v_10865;
    goto v_10810;
v_10811:
    v_10865 = stack[-3];
    goto v_10812;
v_10813:
    goto v_10809;
v_10810:
    goto v_10811;
v_10812:
    if (equal(v_10866, v_10865)) goto v_10807;
    else goto v_10808;
v_10807:
    v_10865 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10806;
v_10808:
    v_10865 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10806;
    v_10865 = nil;
v_10806:
    v_10865 = ncons(v_10865);
    env = stack[-5];
    stack[-1] = v_10865;
    stack[-2] = v_10865;
v_10792:
    v_10865 = stack[-4];
    v_10865 = qcdr(v_10865);
    stack[-4] = v_10865;
    v_10865 = stack[-4];
    if (v_10865 == nil) goto v_10824;
    else goto v_10825;
v_10824:
    v_10865 = stack[-2];
    goto v_10791;
v_10825:
    goto v_10833;
v_10829:
    stack[0] = stack[-1];
    goto v_10830;
v_10831:
    v_10865 = stack[-4];
    v_10865 = qcar(v_10865);
    goto v_10847;
v_10843:
    v_10866 = v_10865;
    goto v_10844;
v_10845:
    v_10865 = stack[-3];
    goto v_10846;
v_10847:
    goto v_10843;
v_10844:
    goto v_10845;
v_10846:
    if (equal(v_10866, v_10865)) goto v_10841;
    else goto v_10842;
v_10841:
    v_10865 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10840;
v_10842:
    v_10865 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10840;
    v_10865 = nil;
v_10840:
    v_10865 = ncons(v_10865);
    env = stack[-5];
    goto v_10832;
v_10833:
    goto v_10829;
v_10830:
    goto v_10831;
v_10832:
    v_10865 = Lrplacd(nil, stack[0], v_10865);
    env = stack[-5];
    v_10865 = stack[-1];
    v_10865 = qcdr(v_10865);
    stack[-1] = v_10865;
    goto v_10792;
v_10791:
    fn = elt(env, 5); // mo!=shorten
    v_10865 = (*qfn1(fn))(fn, v_10865);
    env = stack[-5];
    goto v_10861;
v_10857:
    stack[0] = v_10865;
    goto v_10858;
v_10859:
    fn = elt(env, 6); // mo!=deglist
    v_10865 = (*qfn1(fn))(fn, v_10865);
    goto v_10860;
v_10861:
    goto v_10857;
v_10858:
    goto v_10859;
v_10860:
    {
        LispObject v_10872 = stack[0];
        return cons(v_10872, v_10865);
    }
    goto v_10760;
    v_10865 = nil;
v_10760:
    return onevalue(v_10865);
}



// Code for idcons_ordp

static LispObject CC_idcons_ordp(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_10771, v_10772, v_10773;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10771 = v_10758;
    v_10772 = v_10757;
// end of prologue
    goto v_10767;
v_10761:
    v_10773 = v_10772;
    goto v_10762;
v_10763:
    v_10772 = v_10771;
    goto v_10764;
v_10765:
    v_10771 = elt(env, 1); // atom_compare
    goto v_10766;
v_10767:
    goto v_10761;
v_10762:
    goto v_10763;
v_10764:
    goto v_10765;
v_10766:
    {
        fn = elt(env, 2); // cons_ordp
        return (*qfnn(fn))(fn, 3, v_10773, v_10772, v_10771);
    }
}



// Code for general!-expt!-mod!-p

static LispObject CC_generalKexptKmodKp(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_10834, v_10835, v_10836;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10757,v_10758);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_10836 = v_10758;
    stack[0] = v_10757;
// end of prologue
    goto v_10768;
v_10764:
    v_10835 = v_10836;
    goto v_10765;
v_10766:
    v_10834 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10767;
v_10768:
    goto v_10764;
v_10765:
    goto v_10766;
v_10767:
    if (v_10835 == v_10834) goto v_10762;
    else goto v_10763;
v_10762:
    v_10834 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10761;
v_10763:
    goto v_10778;
v_10774:
    v_10835 = v_10836;
    goto v_10775;
v_10776:
    v_10834 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10777;
v_10778:
    goto v_10774;
v_10775:
    goto v_10776;
v_10777:
    if (v_10835 == v_10834) goto v_10772;
    else goto v_10773;
v_10772:
    v_10834 = stack[0];
    goto v_10761;
v_10773:
    goto v_10793;
v_10789:
    v_10835 = v_10836;
    goto v_10790;
v_10791:
    v_10834 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10792;
v_10793:
    goto v_10789;
v_10790:
    goto v_10791;
v_10792:
    v_10834 = Ldivide(nil, v_10835, v_10834);
    env = stack[-2];
    stack[-1] = v_10834;
    goto v_10801;
v_10797:
    v_10835 = stack[0];
    goto v_10798;
v_10799:
    v_10834 = stack[-1];
    v_10834 = qcar(v_10834);
    goto v_10800;
v_10801:
    goto v_10797;
v_10798:
    goto v_10799;
v_10800:
    v_10834 = CC_generalKexptKmodKp(elt(env, 0), v_10835, v_10834);
    env = stack[-2];
    v_10836 = v_10834;
    goto v_10810;
v_10806:
    v_10834 = v_10836;
    goto v_10807;
v_10808:
    v_10835 = v_10836;
    goto v_10809;
v_10810:
    goto v_10806;
v_10807:
    goto v_10808;
v_10809:
    fn = elt(env, 1); // general!-times!-mod!-p
    v_10834 = (*qfn2(fn))(fn, v_10834, v_10835);
    env = stack[-2];
    v_10836 = v_10834;
    goto v_10821;
v_10817:
    v_10834 = stack[-1];
    v_10835 = qcdr(v_10834);
    goto v_10818;
v_10819:
    v_10834 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10820;
v_10821:
    goto v_10817;
v_10818:
    goto v_10819;
v_10820:
    if (v_10835 == v_10834) goto v_10816;
    goto v_10830;
v_10826:
    v_10835 = v_10836;
    goto v_10827;
v_10828:
    v_10834 = stack[0];
    goto v_10829;
v_10830:
    goto v_10826;
v_10827:
    goto v_10828;
v_10829:
    fn = elt(env, 1); // general!-times!-mod!-p
    v_10834 = (*qfn2(fn))(fn, v_10835, v_10834);
    v_10836 = v_10834;
    goto v_10814;
v_10816:
v_10814:
    v_10834 = v_10836;
    goto v_10761;
    v_10834 = nil;
v_10761:
    return onevalue(v_10834);
}



// Code for !:expt

static LispObject CC_Texpt(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_10973, v_10974, v_10975;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10757,v_10758);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_10758;
    stack[-4] = v_10757;
// end of prologue
    v_10973 = stack[-4];
    if (v_10973 == nil) goto v_10762;
    else goto v_10763;
v_10762:
    goto v_10773;
v_10769:
    v_10974 = stack[-3];
    goto v_10770;
v_10771:
    v_10973 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10772;
v_10773:
    goto v_10769;
v_10770:
    goto v_10771;
v_10772:
    if (v_10974 == v_10973) goto v_10767;
    else goto v_10768;
v_10767:
    goto v_10783;
v_10777:
    v_10975 = elt(env, 1); // poly
    goto v_10778;
v_10779:
    v_10974 = (LispObject)176+TAG_FIXNUM; // 11
    goto v_10780;
v_10781:
    v_10973 = elt(env, 2); // "0/0 formed"
    goto v_10782;
v_10783:
    goto v_10777;
v_10778:
    goto v_10779;
v_10780:
    goto v_10781;
v_10782:
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_10975, v_10974, v_10973);
    }
v_10768:
    v_10973 = nil;
    goto v_10766;
    v_10973 = nil;
v_10766:
    goto v_10761;
v_10763:
    goto v_10796;
v_10792:
    v_10974 = stack[-3];
    goto v_10793;
v_10794:
    v_10973 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10795;
v_10796:
    goto v_10792;
v_10793:
    goto v_10794;
v_10795:
    if (v_10974 == v_10973) goto v_10790;
    else goto v_10791;
v_10790:
    v_10973 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10761;
v_10791:
    goto v_10806;
v_10802:
    v_10974 = stack[-3];
    goto v_10803;
v_10804:
    v_10973 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10805;
v_10806:
    goto v_10802;
v_10803:
    goto v_10804;
v_10805:
    if (v_10974 == v_10973) goto v_10800;
    else goto v_10801;
v_10800:
    v_10973 = stack[-4];
    goto v_10761;
v_10801:
    goto v_10816;
v_10812:
    v_10974 = stack[-4];
    goto v_10813;
v_10814:
    v_10973 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10815;
v_10816:
    goto v_10812;
v_10813:
    goto v_10814;
v_10815:
    if (v_10974 == v_10973) goto v_10810;
    else goto v_10811;
v_10810:
    v_10973 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10761;
v_10811:
    goto v_10827;
v_10823:
    v_10974 = stack[-3];
    goto v_10824;
v_10825:
    v_10973 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10826;
v_10827:
    goto v_10823;
v_10824:
    goto v_10825;
v_10826:
    v_10973 = (LispObject)lessp2(v_10974, v_10973);
    v_10973 = v_10973 ? lisp_true : nil;
    env = stack[-6];
    if (v_10973 == nil) goto v_10821;
    goto v_10836;
v_10832:
    v_10973 = stack[-4];
    fn = elt(env, 5); // fieldp
    v_10973 = (*qfn1(fn))(fn, v_10973);
    env = stack[-6];
    if (v_10973 == nil) goto v_10839;
    else goto v_10840;
v_10839:
    v_10973 = stack[-4];
    fn = elt(env, 6); // mkratnum
    v_10973 = (*qfn1(fn))(fn, v_10973);
    env = stack[-6];
    stack[0] = v_10973;
    goto v_10838;
v_10840:
    v_10973 = stack[-4];
    stack[0] = v_10973;
    goto v_10838;
    stack[0] = nil;
v_10838:
    goto v_10833;
v_10834:
    v_10973 = stack[-3];
    v_10973 = negate(v_10973);
    env = stack[-6];
    goto v_10835;
v_10836:
    goto v_10832;
v_10833:
    goto v_10834;
v_10835:
    v_10973 = CC_Texpt(elt(env, 0), stack[0], v_10973);
    env = stack[-6];
    {
        fn = elt(env, 7); // !:recip
        return (*qfn1(fn))(fn, v_10973);
    }
v_10821:
    v_10973 = stack[-4];
    if (!consp(v_10973)) goto v_10850;
    else goto v_10851;
v_10850:
    goto v_10858;
v_10854:
    v_10974 = stack[-4];
    goto v_10855;
v_10856:
    v_10973 = stack[-3];
    goto v_10857;
v_10858:
    goto v_10854;
v_10855:
    goto v_10856;
v_10857:
        return Lexpt(nil, v_10974, v_10973);
v_10851:
    goto v_10878;
v_10874:
    v_10973 = stack[-4];
    v_10974 = qcar(v_10973);
    goto v_10875;
v_10876:
    v_10973 = elt(env, 3); // expt
    goto v_10877;
v_10878:
    goto v_10874;
v_10875:
    goto v_10876;
v_10877:
    v_10973 = get(v_10974, v_10973);
    env = stack[-6];
    stack[-2] = v_10973;
    if (v_10973 == nil) goto v_10872;
    goto v_10889;
v_10883:
    v_10975 = stack[-2];
    goto v_10884;
v_10885:
    v_10974 = stack[-4];
    goto v_10886;
v_10887:
    v_10973 = stack[-3];
    goto v_10888;
v_10889:
    goto v_10883;
v_10884:
    goto v_10885;
v_10886:
    goto v_10887;
v_10888:
        return Lapply2(nil, 3, v_10975, v_10974, v_10973);
v_10872:
    goto v_10898;
v_10894:
    v_10973 = stack[-4];
    v_10973 = qcar(v_10973);
    if (!symbolp(v_10973)) v_10974 = nil;
    else { v_10974 = qfastgets(v_10973);
           if (v_10974 != nil) { v_10974 = elt(v_10974, 34); // i2d
#ifdef RECORD_GET
             if (v_10974 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_10974 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_10974 == SPID_NOPROP) v_10974 = nil; }}
#endif
    goto v_10895;
v_10896:
    v_10973 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10897;
v_10898:
    goto v_10894;
v_10895:
    goto v_10896;
v_10897:
    v_10973 = Lapply1(nil, v_10974, v_10973);
    env = stack[-6];
    stack[-5] = v_10973;
    v_10973 = stack[-4];
    v_10973 = qcar(v_10973);
    if (!symbolp(v_10973)) v_10973 = nil;
    else { v_10973 = qfastgets(v_10973);
           if (v_10973 != nil) { v_10973 = elt(v_10973, 54); // times
#ifdef RECORD_GET
             if (v_10973 != SPID_NOPROP)
                record_get(elt(fastget_names, 54), 1);
             else record_get(elt(fastget_names, 54), 0),
                v_10973 = nil; }
           else record_get(elt(fastget_names, 54), 0); }
#else
             if (v_10973 == SPID_NOPROP) v_10973 = nil; }}
#endif
    stack[-2] = v_10973;
v_10868:
    v_10973 = stack[-3];
    goto v_10915;
v_10911:
    goto v_10921;
v_10917:
    stack[-1] = v_10973;
    goto v_10918;
v_10919:
    goto v_10928;
v_10924:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10925;
v_10926:
    goto v_10935;
v_10931:
    v_10974 = stack[-3];
    goto v_10932;
v_10933:
    v_10973 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10934;
v_10935:
    goto v_10931;
v_10932:
    goto v_10933;
v_10934:
    v_10973 = quot2(v_10974, v_10973);
    env = stack[-6];
    stack[-3] = v_10973;
    goto v_10927;
v_10928:
    goto v_10924;
v_10925:
    goto v_10926;
v_10927:
    v_10973 = times2(stack[0], v_10973);
    env = stack[-6];
    goto v_10920;
v_10921:
    goto v_10917;
v_10918:
    goto v_10919;
v_10920:
    v_10974 = difference2(stack[-1], v_10973);
    env = stack[-6];
    goto v_10912;
v_10913:
    v_10973 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10914;
v_10915:
    goto v_10911;
v_10912:
    goto v_10913;
v_10914:
    if (v_10974 == v_10973) goto v_10910;
    goto v_10946;
v_10940:
    v_10975 = stack[-2];
    goto v_10941;
v_10942:
    v_10974 = stack[-4];
    goto v_10943;
v_10944:
    v_10973 = stack[-5];
    goto v_10945;
v_10946:
    goto v_10940;
v_10941:
    goto v_10942;
v_10943:
    goto v_10944;
v_10945:
    v_10973 = Lapply2(nil, 3, v_10975, v_10974, v_10973);
    env = stack[-6];
    stack[-5] = v_10973;
    goto v_10908;
v_10910:
v_10908:
    goto v_10958;
v_10954:
    v_10974 = stack[-3];
    goto v_10955;
v_10956:
    v_10973 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10957;
v_10958:
    goto v_10954;
v_10955:
    goto v_10956;
v_10957:
    if (v_10974 == v_10973) goto v_10952;
    else goto v_10953;
v_10952:
    v_10973 = stack[-5];
    goto v_10867;
v_10953:
    goto v_10969;
v_10963:
    v_10975 = stack[-2];
    goto v_10964;
v_10965:
    v_10974 = stack[-4];
    goto v_10966;
v_10967:
    v_10973 = stack[-4];
    goto v_10968;
v_10969:
    goto v_10963;
v_10964:
    goto v_10965;
v_10966:
    goto v_10967;
v_10968:
    v_10973 = Lapply2(nil, 3, v_10975, v_10974, v_10973);
    env = stack[-6];
    stack[-4] = v_10973;
    goto v_10868;
v_10867:
    goto v_10761;
    v_10973 = nil;
v_10761:
    return onevalue(v_10973);
}



// Code for lex_start_line_comment

static LispObject CC_lex_start_line_comment(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10859, v_10860;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10757;
// end of prologue
    goto v_10771;
v_10767:
    v_10860 = stack[0];
    goto v_10768;
v_10769:
    v_10859 = elt(env, 1); // !%
    goto v_10770;
v_10771:
    goto v_10767;
v_10768:
    goto v_10769;
v_10770:
    if (v_10860 == v_10859) goto v_10765;
    else goto v_10766;
v_10765:
    goto v_10780;
v_10776:
    v_10860 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_10777;
v_10778:
    v_10859 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10779;
v_10780:
    goto v_10776;
v_10777:
    goto v_10778;
v_10779:
    fn = elt(env, 5); // land
    v_10859 = (*qfn2(fn))(fn, v_10860, v_10859);
    env = stack[-1];
    v_10859 = (LispObject)zerop(v_10859);
    v_10859 = v_10859 ? lisp_true : nil;
    env = stack[-1];
    v_10859 = (v_10859 == nil ? lisp_true : nil);
    goto v_10764;
v_10766:
    v_10859 = nil;
    goto v_10764;
    v_10859 = nil;
v_10764:
    if (v_10859 == nil) goto v_10762;
    v_10859 = lisp_true;
    goto v_10760;
v_10762:
    goto v_10802;
v_10798:
    v_10860 = stack[0];
    goto v_10799;
v_10800:
    v_10859 = elt(env, 3); // !#
    goto v_10801;
v_10802:
    goto v_10798;
v_10799:
    goto v_10800;
v_10801:
    if (v_10860 == v_10859) goto v_10796;
    else goto v_10797;
v_10796:
    goto v_10811;
v_10807:
    v_10860 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_10808;
v_10809:
    v_10859 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10810;
v_10811:
    goto v_10807;
v_10808:
    goto v_10809;
v_10810:
    fn = elt(env, 5); // land
    v_10859 = (*qfn2(fn))(fn, v_10860, v_10859);
    env = stack[-1];
    v_10859 = (LispObject)zerop(v_10859);
    v_10859 = v_10859 ? lisp_true : nil;
    env = stack[-1];
    v_10859 = (v_10859 == nil ? lisp_true : nil);
    goto v_10795;
v_10797:
    v_10859 = nil;
    goto v_10795;
    v_10859 = nil;
v_10795:
    if (v_10859 == nil) goto v_10793;
    v_10859 = lisp_true;
    goto v_10791;
v_10793:
    goto v_10829;
v_10825:
    v_10860 = stack[0];
    goto v_10826;
v_10827:
    v_10859 = elt(env, 4); // !/
    goto v_10828;
v_10829:
    goto v_10825;
v_10826:
    goto v_10827;
v_10828:
    if (v_10860 == v_10859) goto v_10823;
    else goto v_10824;
v_10823:
    goto v_10842;
v_10838:
    v_10860 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_10839;
v_10840:
    v_10859 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_10841;
v_10842:
    goto v_10838;
v_10839:
    goto v_10840;
v_10841:
    fn = elt(env, 5); // land
    v_10859 = (*qfn2(fn))(fn, v_10860, v_10859);
    env = stack[-1];
    v_10859 = (LispObject)zerop(v_10859);
    v_10859 = v_10859 ? lisp_true : nil;
    env = stack[-1];
    if (v_10859 == nil) goto v_10834;
    else goto v_10835;
v_10834:
    goto v_10849;
v_10845:
    fn = elt(env, 6); // yypeek
    v_10859 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_10846;
v_10847:
    v_10860 = elt(env, 4); // !/
    goto v_10848;
v_10849:
    goto v_10845;
v_10846:
    goto v_10847;
v_10848:
    v_10859 = (v_10859 == v_10860 ? lisp_true : nil);
    goto v_10833;
v_10835:
    v_10859 = nil;
    goto v_10833;
    v_10859 = nil;
v_10833:
    goto v_10822;
v_10824:
    v_10859 = nil;
    goto v_10822;
    v_10859 = nil;
v_10822:
    goto v_10791;
    v_10859 = nil;
v_10791:
    goto v_10760;
    v_10859 = nil;
v_10760:
    return onevalue(v_10859);
}



// Code for formcond

static LispObject CC_formcond(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10780, v_10781, v_10782;
    LispObject fn;
    LispObject v_10759, v_10758, v_10757;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formcond");
    va_start(aa, nargs);
    v_10757 = va_arg(aa, LispObject);
    v_10758 = va_arg(aa, LispObject);
    v_10759 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_10759,v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_10757,v_10758,v_10759);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_10780 = v_10759;
    v_10781 = v_10758;
    v_10782 = v_10757;
// end of prologue
    goto v_10766;
v_10762:
    stack[0] = elt(env, 1); // cond
    goto v_10763;
v_10764:
    goto v_10775;
v_10769:
    v_10782 = qcdr(v_10782);
    goto v_10770;
v_10771:
    goto v_10772;
v_10773:
    goto v_10774;
v_10775:
    goto v_10769;
v_10770:
    goto v_10771;
v_10772:
    goto v_10773;
v_10774:
    fn = elt(env, 2); // formcond1
    v_10780 = (*qfnn(fn))(fn, 3, v_10782, v_10781, v_10780);
    goto v_10765;
v_10766:
    goto v_10762;
v_10763:
    goto v_10764;
v_10765:
    {
        LispObject v_10784 = stack[0];
        return cons(v_10784, v_10780);
    }
}



// Code for ofsf_entry2at

static LispObject CC_ofsf_entry2at(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10791, v_10792, v_10793, v_10794;
    LispObject fn;
    LispObject v_10759, v_10758, v_10757;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_entry2at");
    va_start(aa, nargs);
    v_10757 = va_arg(aa, LispObject);
    v_10758 = va_arg(aa, LispObject);
    v_10759 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_10759,v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_10757,v_10758,v_10759);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_10792 = v_10759;
    v_10793 = v_10758;
    v_10794 = v_10757;
// end of prologue
    v_10791 = qvalue(elt(env, 1)); // !*rlidentify
    if (v_10791 == nil) goto v_10764;
    goto v_10774;
v_10768:
    v_10791 = v_10794;
    goto v_10769;
v_10770:
    goto v_10771;
v_10772:
    goto v_10773;
v_10774:
    goto v_10768;
v_10769:
    goto v_10770;
v_10771:
    goto v_10772;
v_10773:
    fn = elt(env, 2); // ofsf_entry2at1
    v_10791 = (*qfnn(fn))(fn, 3, v_10791, v_10793, v_10792);
    env = stack[0];
    {
        fn = elt(env, 3); // cl_identifyat
        return (*qfn1(fn))(fn, v_10791);
    }
v_10764:
    goto v_10787;
v_10781:
    v_10791 = v_10794;
    goto v_10782;
v_10783:
    goto v_10784;
v_10785:
    goto v_10786;
v_10787:
    goto v_10781;
v_10782:
    goto v_10783;
v_10784:
    goto v_10785;
v_10786:
    {
        fn = elt(env, 2); // ofsf_entry2at1
        return (*qfnn(fn))(fn, 3, v_10791, v_10793, v_10792);
    }
    v_10791 = nil;
    return onevalue(v_10791);
}



// Code for ofsf_smmkatl1

static LispObject CC_ofsf_smmkatl1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10797, v_10798, v_10799, v_10800, v_10801;
    LispObject fn;
    LispObject v_10760, v_10759, v_10758, v_10757;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ofsf_smmkatl1");
    va_start(aa, nargs);
    v_10757 = va_arg(aa, LispObject);
    v_10758 = va_arg(aa, LispObject);
    v_10759 = va_arg(aa, LispObject);
    v_10760 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10799 = v_10760;
    v_10800 = v_10759;
    v_10801 = v_10758;
    v_10797 = v_10757;
// end of prologue
    goto v_10770;
v_10766:
    v_10798 = v_10797;
    goto v_10767;
v_10768:
    v_10797 = elt(env, 1); // and
    goto v_10769;
v_10770:
    goto v_10766;
v_10767:
    goto v_10768;
v_10769:
    if (v_10798 == v_10797) goto v_10764;
    else goto v_10765;
v_10764:
    goto v_10780;
v_10774:
    v_10797 = v_10801;
    goto v_10775;
v_10776:
    v_10798 = v_10800;
    goto v_10777;
v_10778:
    goto v_10779;
v_10780:
    goto v_10774;
v_10775:
    goto v_10776;
v_10777:
    goto v_10778;
v_10779:
    {
        fn = elt(env, 2); // ofsf_smmkatl!-and
        return (*qfnn(fn))(fn, 3, v_10797, v_10798, v_10799);
    }
v_10765:
    goto v_10793;
v_10787:
    v_10797 = v_10801;
    goto v_10788;
v_10789:
    v_10798 = v_10800;
    goto v_10790;
v_10791:
    goto v_10792;
v_10793:
    goto v_10787;
v_10788:
    goto v_10789;
v_10790:
    goto v_10791;
v_10792:
    {
        fn = elt(env, 3); // ofsf_smmkatl!-or
        return (*qfnn(fn))(fn, 3, v_10797, v_10798, v_10799);
    }
    v_10797 = nil;
    return onevalue(v_10797);
}



// Code for rl_atl

static LispObject CC_rl_atl(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10768;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10768 = v_10757;
// end of prologue
    goto v_10764;
v_10760:
    stack[0] = qvalue(elt(env, 1)); // rl_atl!*
    goto v_10761;
v_10762:
    v_10768 = ncons(v_10768);
    env = stack[-1];
    goto v_10763;
v_10764:
    goto v_10760;
v_10761:
    goto v_10762;
v_10763:
    {
        LispObject v_10770 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_10770, v_10768);
    }
}



// Code for ibalp_readclause

static LispObject CC_ibalp_readclause(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_11015, v_11016, v_11017, v_11018;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10757,v_10758);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_10758;
    v_11015 = v_10757;
// end of prologue
    stack[-3] = nil;
    stack[-2] = nil;
    v_11015 = qcdr(v_11015);
    stack[-4] = v_11015;
    goto v_10781;
v_10773:
    stack[-5] = nil;
    goto v_10774;
v_10775:
    stack[-1] = nil;
    goto v_10776;
v_10777:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10778;
v_10779:
    goto v_10794;
v_10786:
    v_11018 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10787;
v_10788:
    v_11017 = nil;
    goto v_10789;
v_10790:
    v_11016 = nil;
    goto v_10791;
v_10792:
    v_11015 = nil;
    goto v_10793;
v_10794:
    goto v_10786;
v_10787:
    goto v_10788;
v_10789:
    goto v_10790;
v_10791:
    goto v_10792;
v_10793:
    v_11015 = list4(v_11018, v_11017, v_11016, v_11015);
    env = stack[-9];
    goto v_10780;
v_10781:
    goto v_10773;
v_10774:
    goto v_10775;
v_10776:
    goto v_10777;
v_10778:
    goto v_10779;
v_10780:
    v_11015 = list3star(stack[-5], stack[-1], stack[0], v_11015);
    env = stack[-9];
    stack[-5] = v_11015;
    v_11015 = lisp_true;
    stack[-1] = v_11015;
v_10802:
    v_11015 = stack[-1];
    if (v_11015 == nil) goto v_10805;
    v_11015 = stack[-4];
    if (v_11015 == nil) goto v_10805;
    goto v_10806;
v_10805:
    goto v_10801;
v_10806:
    v_11015 = stack[-4];
    v_11015 = qcar(v_11015);
    stack[-8] = v_11015;
    goto v_10822;
v_10818:
    v_11016 = stack[-8];
    goto v_10819;
v_10820:
    v_11015 = elt(env, 1); // true
    goto v_10821;
v_10822:
    goto v_10818;
v_10819:
    goto v_10820;
v_10821:
    if (v_11016 == v_11015) goto v_10816;
    else goto v_10817;
v_10816:
    v_11015 = nil;
    stack[-1] = v_11015;
    goto v_10815;
v_10817:
    v_11015 = stack[-4];
    v_11015 = qcdr(v_11015);
    stack[-4] = v_11015;
    goto v_10838;
v_10834:
    v_11016 = stack[-8];
    goto v_10835;
v_10836:
    v_11015 = elt(env, 2); // false
    goto v_10837;
v_10838:
    goto v_10834;
v_10835:
    goto v_10836;
v_10837:
    if (v_11016 == v_11015) goto v_10833;
    goto v_10849;
v_10845:
    v_11015 = stack[-8];
    if (!consp(v_11015)) goto v_10852;
    else goto v_10853;
v_10852:
    v_11015 = stack[-8];
    v_11016 = v_11015;
    goto v_10851;
v_10853:
    v_11015 = stack[-8];
    v_11015 = qcar(v_11015);
    v_11016 = v_11015;
    goto v_10851;
    v_11016 = nil;
v_10851:
    goto v_10846;
v_10847:
    v_11015 = elt(env, 3); // not
    goto v_10848;
v_10849:
    goto v_10845;
v_10846:
    goto v_10847;
v_10848:
    if (v_11016 == v_11015) goto v_10843;
    else goto v_10844;
v_10843:
    v_11015 = stack[-8];
    v_11015 = qcdr(v_11015);
    v_11015 = qcar(v_11015);
    fn = elt(env, 4); // ibalp_arg2l
    v_11015 = (*qfn1(fn))(fn, v_11015);
    env = stack[-9];
    stack[-6] = v_11015;
    goto v_10869;
v_10865:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10866;
v_10867:
    v_11015 = stack[-8];
    v_11015 = qcdr(v_11015);
    v_11015 = qcar(v_11015);
    fn = elt(env, 5); // ibalp_arg2r
    v_11015 = (*qfn1(fn))(fn, v_11015);
    env = stack[-9];
    goto v_10868;
v_10869:
    goto v_10865;
v_10866:
    goto v_10867;
v_10868:
    v_11015 = (LispObject)(intptr_t)((intptr_t)stack[0] - (intptr_t)v_11015 + TAG_FIXNUM);
    goto v_10842;
v_10844:
    v_11015 = stack[-8];
    fn = elt(env, 4); // ibalp_arg2l
    v_11015 = (*qfn1(fn))(fn, v_11015);
    env = stack[-9];
    stack[-6] = v_11015;
    v_11015 = stack[-8];
    fn = elt(env, 5); // ibalp_arg2r
    v_11015 = (*qfn1(fn))(fn, v_11015);
    env = stack[-9];
    goto v_10842;
v_10842:
    goto v_10891;
v_10887:
    v_11016 = v_11015;
    goto v_10888;
v_10889:
    v_11015 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10890;
v_10891:
    goto v_10887;
v_10888:
    goto v_10889;
v_10890:
    fn = elt(env, 6); // iequal
    v_11015 = (*qfn2(fn))(fn, v_11016, v_11015);
    env = stack[-9];
    if (v_11015 == nil) goto v_10885;
    goto v_10902;
v_10898:
    v_11016 = stack[-6];
    goto v_10899;
v_10900:
    v_11015 = stack[-3];
    goto v_10901;
v_10902:
    goto v_10898;
v_10899:
    goto v_10900;
v_10901:
    v_11015 = Lmemq(nil, v_11016, v_11015);
    if (v_11015 == nil) goto v_10896;
    else goto v_10897;
v_10896:
    goto v_10911;
v_10907:
    v_11015 = stack[-5];
    v_11015 = qcdr(v_11015);
    stack[0] = qcdr(v_11015);
    goto v_10908;
v_10909:
    v_11015 = stack[-5];
    v_11015 = qcdr(v_11015);
    v_11015 = qcdr(v_11015);
    v_11015 = qcar(v_11015);
    v_11015 = add1(v_11015);
    env = stack[-9];
    goto v_10910;
v_10911:
    goto v_10907;
v_10908:
    goto v_10909;
v_10910:
    fn = elt(env, 7); // setcar
    v_11015 = (*qfn2(fn))(fn, stack[0], v_11015);
    env = stack[-9];
    goto v_10925;
v_10921:
    v_11016 = stack[-6];
    goto v_10922;
v_10923:
    v_11015 = stack[-3];
    goto v_10924;
v_10925:
    goto v_10921;
v_10922:
    goto v_10923;
v_10924:
    v_11015 = cons(v_11016, v_11015);
    env = stack[-9];
    stack[-3] = v_11015;
    goto v_10937;
v_10929:
    v_11018 = stack[-5];
    goto v_10930;
v_10931:
    v_11017 = stack[-7];
    goto v_10932;
v_10933:
    v_11016 = stack[-6];
    goto v_10934;
v_10935:
    v_11015 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10936;
v_10937:
    goto v_10929;
v_10930:
    goto v_10931;
v_10932:
    goto v_10933;
v_10934:
    goto v_10935;
v_10936:
    fn = elt(env, 8); // ibalp_process!-var
    v_11015 = (*qfnn(fn))(fn, 4, v_11018, v_11017, v_11016, v_11015);
    env = stack[-9];
    stack[-7] = v_11015;
    goto v_10895;
v_10897:
v_10895:
    goto v_10883;
v_10885:
    goto v_10952;
v_10948:
    v_11016 = stack[-6];
    goto v_10949;
v_10950:
    v_11015 = stack[-2];
    goto v_10951;
v_10952:
    goto v_10948;
v_10949:
    goto v_10950;
v_10951:
    v_11015 = Lmemq(nil, v_11016, v_11015);
    if (v_11015 == nil) goto v_10946;
    else goto v_10947;
v_10946:
    goto v_10961;
v_10957:
    v_11015 = stack[-5];
    v_11015 = qcdr(v_11015);
    v_11015 = qcdr(v_11015);
    stack[0] = qcdr(v_11015);
    goto v_10958;
v_10959:
    v_11015 = stack[-5];
    v_11015 = qcdr(v_11015);
    v_11015 = qcdr(v_11015);
    v_11015 = qcdr(v_11015);
    v_11015 = qcar(v_11015);
    v_11015 = add1(v_11015);
    env = stack[-9];
    goto v_10960;
v_10961:
    goto v_10957;
v_10958:
    goto v_10959;
v_10960:
    fn = elt(env, 7); // setcar
    v_11015 = (*qfn2(fn))(fn, stack[0], v_11015);
    env = stack[-9];
    goto v_10977;
v_10973:
    v_11016 = stack[-6];
    goto v_10974;
v_10975:
    v_11015 = stack[-2];
    goto v_10976;
v_10977:
    goto v_10973;
v_10974:
    goto v_10975;
v_10976:
    v_11015 = cons(v_11016, v_11015);
    env = stack[-9];
    stack[-2] = v_11015;
    goto v_10989;
v_10981:
    v_11018 = stack[-5];
    goto v_10982;
v_10983:
    v_11017 = stack[-7];
    goto v_10984;
v_10985:
    v_11016 = stack[-6];
    goto v_10986;
v_10987:
    v_11015 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10988;
v_10989:
    goto v_10981;
v_10982:
    goto v_10983;
v_10984:
    goto v_10985;
v_10986:
    goto v_10987;
v_10988:
    fn = elt(env, 8); // ibalp_process!-var
    v_11015 = (*qfnn(fn))(fn, 4, v_11018, v_11017, v_11016, v_11015);
    env = stack[-9];
    stack[-7] = v_11015;
    goto v_10945;
v_10947:
v_10945:
    goto v_10883;
v_10883:
    goto v_10831;
v_10833:
v_10831:
    goto v_10815;
v_10815:
    goto v_10802;
v_10801:
    v_11015 = stack[-1];
    if (v_11015 == nil) goto v_10996;
    else goto v_10997;
v_10996:
    goto v_11004;
v_11000:
    v_11016 = elt(env, 1); // true
    goto v_11001;
v_11002:
    v_11015 = stack[-7];
    goto v_11003;
v_11004:
    goto v_11000;
v_11001:
    goto v_11002;
v_11003:
    return cons(v_11016, v_11015);
v_10997:
    goto v_11012;
v_11008:
    v_11016 = stack[-5];
    goto v_11009;
v_11010:
    v_11015 = stack[-7];
    goto v_11011;
v_11012:
    goto v_11008;
v_11009:
    goto v_11010;
v_11011:
    return cons(v_11016, v_11015);
    return onevalue(v_11015);
}



// Code for powers4

static LispObject CC_powers4(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_11084, v_11085, v_11086;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10757,v_10758);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_10758;
    stack[-1] = v_10757;
// end of prologue
    stack[-3] = nil;
v_10763:
    v_11084 = stack[-1];
    if (v_11084 == nil) goto v_10766;
    else goto v_10767;
v_10766:
    goto v_10774;
v_10770:
    stack[-4] = stack[-3];
    goto v_10771;
v_10772:
    v_11084 = stack[0];
    stack[-3] = v_11084;
    v_11084 = stack[-3];
    if (v_11084 == nil) goto v_10785;
    else goto v_10786;
v_10785:
    v_11084 = nil;
    goto v_10780;
v_10786:
    v_11084 = stack[-3];
    v_11084 = qcar(v_11084);
    goto v_10800;
v_10794:
    v_11085 = v_11084;
    v_11086 = qcar(v_11085);
    goto v_10795;
v_10796:
    v_11084 = qcdr(v_11084);
    v_11085 = qcar(v_11084);
    goto v_10797;
v_10798:
    v_11084 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10799;
v_10800:
    goto v_10794;
v_10795:
    goto v_10796;
v_10797:
    goto v_10798;
v_10799:
    v_11084 = list2star(v_11086, v_11085, v_11084);
    env = stack[-5];
    v_11084 = ncons(v_11084);
    env = stack[-5];
    stack[-1] = v_11084;
    stack[-2] = v_11084;
v_10781:
    v_11084 = stack[-3];
    v_11084 = qcdr(v_11084);
    stack[-3] = v_11084;
    v_11084 = stack[-3];
    if (v_11084 == nil) goto v_10811;
    else goto v_10812;
v_10811:
    v_11084 = stack[-2];
    goto v_10780;
v_10812:
    goto v_10820;
v_10816:
    stack[0] = stack[-1];
    goto v_10817;
v_10818:
    v_11084 = stack[-3];
    v_11084 = qcar(v_11084);
    goto v_10833;
v_10827:
    v_11085 = v_11084;
    v_11086 = qcar(v_11085);
    goto v_10828;
v_10829:
    v_11084 = qcdr(v_11084);
    v_11085 = qcar(v_11084);
    goto v_10830;
v_10831:
    v_11084 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10832;
v_10833:
    goto v_10827;
v_10828:
    goto v_10829;
v_10830:
    goto v_10831;
v_10832:
    v_11084 = list2star(v_11086, v_11085, v_11084);
    env = stack[-5];
    v_11084 = ncons(v_11084);
    env = stack[-5];
    goto v_10819;
v_10820:
    goto v_10816;
v_10817:
    goto v_10818;
v_10819:
    v_11084 = Lrplacd(nil, stack[0], v_11084);
    env = stack[-5];
    v_11084 = stack[-1];
    v_11084 = qcdr(v_11084);
    stack[-1] = v_11084;
    goto v_10781;
v_10780:
    goto v_10773;
v_10774:
    goto v_10770;
v_10771:
    goto v_10772;
v_10773:
    {
        LispObject v_11092 = stack[-4];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_11092, v_11084);
    }
v_10767:
    v_11084 = stack[0];
    if (v_11084 == nil) goto v_10842;
    else goto v_10843;
v_10842:
    goto v_10850;
v_10846:
    stack[-4] = stack[-3];
    goto v_10847;
v_10848:
    v_11084 = stack[-1];
    stack[-3] = v_11084;
    v_11084 = stack[-3];
    if (v_11084 == nil) goto v_10861;
    else goto v_10862;
v_10861:
    v_11084 = nil;
    goto v_10856;
v_10862:
    v_11084 = stack[-3];
    v_11084 = qcar(v_11084);
    goto v_10876;
v_10870:
    v_11085 = v_11084;
    v_11086 = qcar(v_11085);
    goto v_10871;
v_10872:
    v_11085 = qcdr(v_11084);
    goto v_10873;
v_10874:
    v_11084 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10875;
v_10876:
    goto v_10870;
v_10871:
    goto v_10872;
v_10873:
    goto v_10874;
v_10875:
    v_11084 = list2star(v_11086, v_11085, v_11084);
    env = stack[-5];
    v_11084 = ncons(v_11084);
    env = stack[-5];
    stack[-1] = v_11084;
    stack[-2] = v_11084;
v_10857:
    v_11084 = stack[-3];
    v_11084 = qcdr(v_11084);
    stack[-3] = v_11084;
    v_11084 = stack[-3];
    if (v_11084 == nil) goto v_10886;
    else goto v_10887;
v_10886:
    v_11084 = stack[-2];
    goto v_10856;
v_10887:
    goto v_10895;
v_10891:
    stack[0] = stack[-1];
    goto v_10892;
v_10893:
    v_11084 = stack[-3];
    v_11084 = qcar(v_11084);
    goto v_10908;
v_10902:
    v_11085 = v_11084;
    v_11086 = qcar(v_11085);
    goto v_10903;
v_10904:
    v_11085 = qcdr(v_11084);
    goto v_10905;
v_10906:
    v_11084 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10907;
v_10908:
    goto v_10902;
v_10903:
    goto v_10904;
v_10905:
    goto v_10906;
v_10907:
    v_11084 = list2star(v_11086, v_11085, v_11084);
    env = stack[-5];
    v_11084 = ncons(v_11084);
    env = stack[-5];
    goto v_10894;
v_10895:
    goto v_10891;
v_10892:
    goto v_10893;
v_10894:
    v_11084 = Lrplacd(nil, stack[0], v_11084);
    env = stack[-5];
    v_11084 = stack[-1];
    v_11084 = qcdr(v_11084);
    stack[-1] = v_11084;
    goto v_10857;
v_10856:
    goto v_10849;
v_10850:
    goto v_10846;
v_10847:
    goto v_10848;
v_10849:
    {
        LispObject v_11093 = stack[-4];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_11093, v_11084);
    }
v_10843:
    goto v_10922;
v_10918:
    v_11084 = stack[-1];
    v_11084 = qcar(v_11084);
    v_11085 = qcar(v_11084);
    goto v_10919;
v_10920:
    v_11084 = stack[0];
    v_11084 = qcar(v_11084);
    v_11084 = qcar(v_11084);
    goto v_10921;
v_10922:
    goto v_10918;
v_10919:
    goto v_10920;
v_10921:
    if (equal(v_11085, v_11084)) goto v_10916;
    else goto v_10917;
v_10916:
    goto v_10938;
v_10934:
    v_11084 = stack[-1];
    v_11084 = qcar(v_11084);
    v_11085 = qcdr(v_11084);
    goto v_10935;
v_10936:
    v_11084 = stack[0];
    v_11084 = qcar(v_11084);
    v_11084 = qcdr(v_11084);
    v_11084 = qcar(v_11084);
    goto v_10937;
v_10938:
    goto v_10934;
v_10935:
    goto v_10936;
v_10937:
    v_11084 = (LispObject)greaterp2(v_11085, v_11084);
    v_11084 = v_11084 ? lisp_true : nil;
    env = stack[-5];
    if (v_11084 == nil) goto v_10932;
    goto v_10951;
v_10947:
    v_11084 = stack[0];
    v_11084 = qcar(v_11084);
    v_11085 = qcdr(v_11084);
    goto v_10948;
v_10949:
    v_11084 = stack[-1];
    v_11084 = qcar(v_11084);
    v_11084 = qcdr(v_11084);
    goto v_10950;
v_10951:
    goto v_10947;
v_10948:
    goto v_10949;
v_10950:
    v_11084 = Lrplaca(nil, v_11085, v_11084);
    env = stack[-5];
    goto v_10930;
v_10932:
v_10930:
    goto v_10967;
v_10963:
    v_11084 = stack[-1];
    v_11084 = qcar(v_11084);
    v_11085 = qcdr(v_11084);
    goto v_10964;
v_10965:
    v_11084 = stack[0];
    v_11084 = qcar(v_11084);
    v_11084 = qcdr(v_11084);
    v_11084 = qcdr(v_11084);
    goto v_10966;
v_10967:
    goto v_10963;
v_10964:
    goto v_10965;
v_10966:
    v_11084 = (LispObject)lessp2(v_11085, v_11084);
    v_11084 = v_11084 ? lisp_true : nil;
    env = stack[-5];
    if (v_11084 == nil) goto v_10961;
    goto v_10980;
v_10976:
    v_11084 = stack[0];
    v_11084 = qcar(v_11084);
    v_11085 = qcdr(v_11084);
    goto v_10977;
v_10978:
    v_11084 = stack[-1];
    v_11084 = qcar(v_11084);
    v_11084 = qcdr(v_11084);
    goto v_10979;
v_10980:
    goto v_10976;
v_10977:
    goto v_10978;
v_10979:
    v_11084 = Lrplacd(nil, v_11085, v_11084);
    env = stack[-5];
    goto v_10959;
v_10961:
v_10959:
    goto v_10992;
v_10988:
    goto v_10989;
v_10990:
    goto v_10999;
v_10995:
    stack[-2] = stack[0];
    goto v_10996;
v_10997:
    goto v_11006;
v_11002:
    v_11084 = stack[-1];
    v_11085 = qcdr(v_11084);
    goto v_11003;
v_11004:
    v_11084 = stack[0];
    v_11084 = qcdr(v_11084);
    goto v_11005;
v_11006:
    goto v_11002;
v_11003:
    goto v_11004;
v_11005:
    v_11084 = CC_powers4(elt(env, 0), v_11085, v_11084);
    env = stack[-5];
    goto v_10998;
v_10999:
    goto v_10995;
v_10996:
    goto v_10997;
v_10998:
    v_11084 = Lrplacd(nil, stack[-2], v_11084);
    env = stack[-5];
    goto v_10991;
v_10992:
    goto v_10988;
v_10989:
    goto v_10990;
v_10991:
    {
        LispObject v_11094 = stack[-3];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_11094, v_11084);
    }
v_10917:
    goto v_11018;
v_11014:
    v_11084 = stack[-1];
    v_11084 = qcar(v_11084);
    v_11085 = qcar(v_11084);
    goto v_11015;
v_11016:
    v_11084 = stack[0];
    v_11084 = qcar(v_11084);
    v_11084 = qcar(v_11084);
    goto v_11017;
v_11018:
    goto v_11014;
v_11015:
    goto v_11016;
v_11017:
    fn = elt(env, 2); // ordop
    v_11084 = (*qfn2(fn))(fn, v_11085, v_11084);
    env = stack[-5];
    if (v_11084 == nil) goto v_11012;
    goto v_11030;
v_11026:
    v_11084 = stack[0];
    v_11084 = qcar(v_11084);
    v_11085 = qcdr(v_11084);
    goto v_11027;
v_11028:
    v_11084 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11029;
v_11030:
    goto v_11026;
v_11027:
    goto v_11028;
v_11029:
    v_11084 = Lrplacd(nil, v_11085, v_11084);
    env = stack[-5];
    goto v_11040;
v_11036:
    goto v_11037;
v_11038:
    goto v_11047;
v_11043:
    stack[-2] = stack[0];
    goto v_11044;
v_11045:
    goto v_11054;
v_11050:
    v_11085 = stack[-1];
    goto v_11051;
v_11052:
    v_11084 = stack[0];
    v_11084 = qcdr(v_11084);
    goto v_11053;
v_11054:
    goto v_11050;
v_11051:
    goto v_11052;
v_11053:
    v_11084 = CC_powers4(elt(env, 0), v_11085, v_11084);
    env = stack[-5];
    goto v_11046;
v_11047:
    goto v_11043;
v_11044:
    goto v_11045;
v_11046:
    v_11084 = Lrplacd(nil, stack[-2], v_11084);
    env = stack[-5];
    goto v_11039;
v_11040:
    goto v_11036;
v_11037:
    goto v_11038;
v_11039:
    {
        LispObject v_11095 = stack[-3];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_11095, v_11084);
    }
v_11012:
    goto v_11067;
v_11061:
    v_11084 = stack[-1];
    v_11084 = qcar(v_11084);
    stack[-2] = qcar(v_11084);
    goto v_11062;
v_11063:
    goto v_11076;
v_11072:
    v_11084 = stack[-1];
    v_11084 = qcar(v_11084);
    v_11085 = qcdr(v_11084);
    goto v_11073;
v_11074:
    v_11084 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11075;
v_11076:
    goto v_11072;
v_11073:
    goto v_11074;
v_11075:
    v_11085 = cons(v_11085, v_11084);
    env = stack[-5];
    goto v_11064;
v_11065:
    v_11084 = stack[-3];
    goto v_11066;
v_11067:
    goto v_11061;
v_11062:
    goto v_11063;
v_11064:
    goto v_11065;
v_11066:
    v_11084 = acons(stack[-2], v_11085, v_11084);
    env = stack[-5];
    stack[-3] = v_11084;
    v_11084 = stack[-1];
    v_11084 = qcdr(v_11084);
    stack[-1] = v_11084;
    goto v_10763;
    v_11084 = nil;
    return onevalue(v_11084);
}



// Code for om2mml

static LispObject CC_om2mml(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10774;
    LispObject fn;
    argcheck(nargs, 0, "om2mml");
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
    fn = elt(env, 2); // om2ir
    v_10774 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_10774;
    v_10774 = lisp_true;
    fn = elt(env, 3); // terpri!*
    v_10774 = (*qfn1(fn))(fn, v_10774);
    env = stack[-1];
    v_10774 = elt(env, 1); // "Intermediate representation:"
    v_10774 = Lprinc(nil, v_10774);
    env = stack[-1];
    v_10774 = lisp_true;
    fn = elt(env, 3); // terpri!*
    v_10774 = (*qfn1(fn))(fn, v_10774);
    env = stack[-1];
    v_10774 = stack[0];
    v_10774 = Lprinc(nil, v_10774);
    env = stack[-1];
    v_10774 = lisp_true;
    fn = elt(env, 3); // terpri!*
    v_10774 = (*qfn1(fn))(fn, v_10774);
    env = stack[-1];
    v_10774 = stack[0];
    fn = elt(env, 4); // ir2mml
    v_10774 = (*qfn1(fn))(fn, v_10774);
    v_10774 = nil;
    return onevalue(v_10774);
}



// Code for !*wedgepf2pf

static LispObject CC_Hwedgepf2pf(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10790, v_10791, v_10792;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10757;
// end of prologue
    stack[-1] = nil;
v_10762:
    v_10790 = stack[0];
    if (v_10790 == nil) goto v_10765;
    else goto v_10766;
v_10765:
    v_10790 = stack[-1];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_10790);
    }
v_10766:
    goto v_10779;
v_10773:
    v_10790 = stack[0];
    v_10790 = qcar(v_10790);
    v_10790 = qcar(v_10790);
    fn = elt(env, 2); // mkuwedge
    v_10792 = (*qfn1(fn))(fn, v_10790);
    env = stack[-2];
    goto v_10774;
v_10775:
    v_10790 = stack[0];
    v_10790 = qcar(v_10790);
    v_10791 = qcdr(v_10790);
    goto v_10776;
v_10777:
    v_10790 = stack[-1];
    goto v_10778;
v_10779:
    goto v_10773;
v_10774:
    goto v_10775;
v_10776:
    goto v_10777;
v_10778:
    v_10790 = acons(v_10792, v_10791, v_10790);
    env = stack[-2];
    stack[-1] = v_10790;
    v_10790 = stack[0];
    v_10790 = qcdr(v_10790);
    stack[0] = v_10790;
    goto v_10762;
    v_10790 = nil;
    return onevalue(v_10790);
}



// Code for delete!-dups

static LispObject CC_deleteKdups(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10801, v_10802, v_10803;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10757;
// end of prologue
    v_10803 = nil;
v_10762:
    v_10801 = stack[0];
    if (v_10801 == nil) goto v_10766;
    goto v_10776;
v_10772:
    v_10801 = stack[0];
    v_10802 = qcar(v_10801);
    goto v_10773;
v_10774:
    v_10801 = stack[0];
    v_10801 = qcdr(v_10801);
    goto v_10775;
v_10776:
    goto v_10772;
v_10773:
    goto v_10774;
v_10775:
    v_10801 = Lmember(nil, v_10802, v_10801);
    if (v_10801 == nil) goto v_10771;
    v_10801 = stack[0];
    v_10801 = qcdr(v_10801);
    stack[0] = v_10801;
    goto v_10762;
v_10771:
    goto v_10791;
v_10787:
    v_10801 = stack[0];
    v_10801 = qcar(v_10801);
    goto v_10788;
v_10789:
    v_10802 = v_10803;
    goto v_10790;
v_10791:
    goto v_10787;
v_10788:
    goto v_10789;
v_10790:
    v_10801 = cons(v_10801, v_10802);
    env = stack[-1];
    v_10803 = v_10801;
    v_10801 = stack[0];
    v_10801 = qcdr(v_10801);
    stack[0] = v_10801;
    goto v_10762;
    goto v_10764;
v_10766:
    v_10801 = v_10803;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_10801);
    }
v_10764:
    v_10801 = nil;
    return onevalue(v_10801);
}



// Code for scal!*list

static LispObject CC_scalHlist(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_10791, v_10792;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10757,v_10758);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10758;
    stack[-1] = v_10757;
// end of prologue
    stack[-2] = nil;
v_10763:
    v_10791 = stack[0];
    if (v_10791 == nil) goto v_10766;
    else goto v_10767;
v_10766:
    v_10791 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_10791);
    }
v_10767:
    goto v_10778;
v_10774:
    goto v_10784;
v_10780:
    v_10792 = stack[-1];
    goto v_10781;
v_10782:
    v_10791 = stack[0];
    v_10791 = qcar(v_10791);
    goto v_10783;
v_10784:
    goto v_10780;
v_10781:
    goto v_10782;
v_10783:
    fn = elt(env, 2); // !:times
    v_10792 = (*qfn2(fn))(fn, v_10792, v_10791);
    env = stack[-3];
    goto v_10775;
v_10776:
    v_10791 = stack[-2];
    goto v_10777;
v_10778:
    goto v_10774;
v_10775:
    goto v_10776;
v_10777:
    v_10791 = cons(v_10792, v_10791);
    env = stack[-3];
    stack[-2] = v_10791;
    v_10791 = stack[0];
    v_10791 = qcdr(v_10791);
    stack[0] = v_10791;
    goto v_10763;
    v_10791 = nil;
    return onevalue(v_10791);
}



// Code for physop!-ordop

static LispObject CC_physopKordop(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_10945, v_10946;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10757,v_10758);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_10758;
    stack[-1] = v_10757;
// end of prologue
v_10756:
    v_10945 = stack[-1];
    fn = elt(env, 3); // !*physopp
    v_10945 = (*qfn1(fn))(fn, v_10945);
    env = stack[-4];
    if (v_10945 == nil) goto v_10769;
    v_10945 = stack[0];
    fn = elt(env, 3); // !*physopp
    v_10945 = (*qfn1(fn))(fn, v_10945);
    env = stack[-4];
    if (v_10945 == nil) goto v_10769;
    goto v_10770;
v_10769:
    v_10945 = stack[-1];
    fn = elt(env, 3); // !*physopp
    v_10945 = (*qfn1(fn))(fn, v_10945);
    env = stack[-4];
    if (v_10945 == nil) goto v_10780;
    v_10945 = nil;
    goto v_10778;
v_10780:
    v_10945 = stack[0];
    fn = elt(env, 3); // !*physopp
    v_10945 = (*qfn1(fn))(fn, v_10945);
    env = stack[-4];
    if (v_10945 == nil) goto v_10785;
    v_10945 = lisp_true;
    goto v_10778;
v_10785:
    goto v_10796;
v_10792:
    v_10946 = stack[-1];
    goto v_10793;
v_10794:
    v_10945 = stack[0];
    goto v_10795;
v_10796:
    goto v_10792;
v_10793:
    goto v_10794;
v_10795:
    {
        fn = elt(env, 4); // ordop2
        return (*qfn2(fn))(fn, v_10946, v_10945);
    }
    v_10945 = nil;
v_10778:
    goto v_10766;
v_10770:
    v_10945 = stack[-1];
    if (symbolp(v_10945)) goto v_10801;
    else goto v_10802;
v_10801:
    goto v_10809;
v_10805:
    v_10946 = stack[-1];
    goto v_10806;
v_10807:
    v_10945 = elt(env, 1); // physopname
    goto v_10808;
v_10809:
    goto v_10805;
v_10806:
    goto v_10807;
v_10808:
    v_10945 = get(v_10946, v_10945);
    env = stack[-4];
    stack[-3] = v_10945;
    goto v_10800;
v_10802:
    goto v_10819;
v_10815:
    v_10945 = stack[-1];
    v_10946 = qcar(v_10945);
    goto v_10816;
v_10817:
    v_10945 = elt(env, 1); // physopname
    goto v_10818;
v_10819:
    goto v_10815;
v_10816:
    goto v_10817;
v_10818:
    v_10945 = get(v_10946, v_10945);
    env = stack[-4];
    stack[-3] = v_10945;
    goto v_10828;
v_10824:
    v_10946 = stack[-3];
    goto v_10825;
v_10826:
    v_10945 = stack[-1];
    v_10945 = qcdr(v_10945);
    goto v_10827;
v_10828:
    goto v_10824;
v_10825:
    goto v_10826;
v_10827:
    v_10945 = cons(v_10946, v_10945);
    env = stack[-4];
    stack[-3] = v_10945;
    v_10945 = stack[-1];
    v_10945 = qcar(v_10945);
    stack[-1] = v_10945;
    goto v_10800;
v_10800:
    goto v_10843;
v_10839:
    v_10946 = stack[-1];
    goto v_10840;
v_10841:
    v_10945 = qvalue(elt(env, 2)); // specoplist!*
    goto v_10842;
v_10843:
    goto v_10839;
v_10840:
    goto v_10841;
v_10842:
    v_10945 = Lmember(nil, v_10946, v_10945);
    if (v_10945 == nil) goto v_10838;
    v_10945 = lisp_true;
    goto v_10766;
v_10838:
    v_10945 = stack[0];
    if (symbolp(v_10945)) goto v_10850;
    else goto v_10851;
v_10850:
    goto v_10858;
v_10854:
    v_10946 = stack[0];
    goto v_10855;
v_10856:
    v_10945 = elt(env, 1); // physopname
    goto v_10857;
v_10858:
    goto v_10854;
v_10855:
    goto v_10856;
v_10857:
    v_10945 = get(v_10946, v_10945);
    env = stack[-4];
    stack[-2] = v_10945;
    goto v_10849;
v_10851:
    goto v_10868;
v_10864:
    v_10945 = stack[0];
    v_10946 = qcar(v_10945);
    goto v_10865;
v_10866:
    v_10945 = elt(env, 1); // physopname
    goto v_10867;
v_10868:
    goto v_10864;
v_10865:
    goto v_10866;
v_10867:
    v_10945 = get(v_10946, v_10945);
    env = stack[-4];
    stack[-2] = v_10945;
    goto v_10877;
v_10873:
    v_10946 = stack[-2];
    goto v_10874;
v_10875:
    v_10945 = stack[0];
    v_10945 = qcdr(v_10945);
    goto v_10876;
v_10877:
    goto v_10873;
v_10874:
    goto v_10875;
v_10876:
    v_10945 = cons(v_10946, v_10945);
    env = stack[-4];
    stack[-2] = v_10945;
    v_10945 = stack[0];
    v_10945 = qcar(v_10945);
    stack[0] = v_10945;
    goto v_10849;
v_10849:
    goto v_10892;
v_10888:
    v_10946 = stack[0];
    goto v_10889;
v_10890:
    v_10945 = qvalue(elt(env, 2)); // specoplist!*
    goto v_10891;
v_10892:
    goto v_10888;
v_10889:
    goto v_10890;
v_10891:
    v_10945 = Lmember(nil, v_10946, v_10945);
    if (v_10945 == nil) goto v_10887;
    v_10945 = lisp_true;
    goto v_10766;
v_10887:
    v_10945 = stack[-3];
    fn = elt(env, 5); // opnum!*
    v_10945 = (*qfn1(fn))(fn, v_10945);
    env = stack[-4];
    stack[-1] = v_10945;
    v_10945 = stack[-2];
    fn = elt(env, 5); // opnum!*
    v_10945 = (*qfn1(fn))(fn, v_10945);
    env = stack[-4];
    stack[0] = v_10945;
    goto v_10910;
v_10906:
    v_10946 = stack[-1];
    goto v_10907;
v_10908:
    v_10945 = stack[0];
    goto v_10909;
v_10910:
    goto v_10906;
v_10907:
    goto v_10908;
v_10909:
    v_10945 = (LispObject)lessp2(v_10946, v_10945);
    v_10945 = v_10945 ? lisp_true : nil;
    env = stack[-4];
    if (v_10945 == nil) goto v_10904;
    v_10945 = lisp_true;
    goto v_10902;
v_10904:
    goto v_10921;
v_10917:
    v_10946 = stack[-1];
    goto v_10918;
v_10919:
    v_10945 = stack[0];
    goto v_10920;
v_10921:
    goto v_10917;
v_10918:
    goto v_10919;
v_10920:
    v_10945 = (LispObject)greaterp2(v_10946, v_10945);
    v_10945 = v_10945 ? lisp_true : nil;
    env = stack[-4];
    if (v_10945 == nil) goto v_10915;
    v_10945 = nil;
    goto v_10902;
v_10915:
    v_10945 = stack[-3];
    if (symbolp(v_10945)) goto v_10925;
    else goto v_10926;
v_10925:
    v_10945 = lisp_true;
    goto v_10902;
v_10926:
    v_10945 = stack[-2];
    if (symbolp(v_10945)) goto v_10929;
    else goto v_10930;
v_10929:
    v_10945 = nil;
    goto v_10902;
v_10930:
    goto v_10940;
v_10936:
    v_10945 = stack[-3];
    v_10946 = qcdr(v_10945);
    goto v_10937;
v_10938:
    v_10945 = stack[-2];
    v_10945 = qcdr(v_10945);
    goto v_10939;
v_10940:
    goto v_10936;
v_10937:
    goto v_10938;
v_10939:
    stack[-1] = v_10946;
    stack[0] = v_10945;
    goto v_10756;
    v_10945 = nil;
v_10902:
v_10766:
    return onevalue(v_10945);
}



// Code for zero!-roads

static LispObject CC_zeroKroads(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10791, v_10792;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10757;
// end of prologue
v_10756:
    v_10791 = stack[0];
    if (v_10791 == nil) goto v_10761;
    else goto v_10762;
v_10761:
    v_10791 = nil;
    goto v_10760;
v_10762:
    v_10791 = stack[0];
    v_10791 = qcar(v_10791);
    fn = elt(env, 1); // z!-roads
    v_10791 = (*qfn1(fn))(fn, v_10791);
    env = stack[-2];
    v_10792 = v_10791;
    v_10791 = v_10792;
    if (v_10791 == nil) goto v_10774;
    goto v_10781;
v_10777:
    stack[-1] = v_10792;
    goto v_10778;
v_10779:
    v_10791 = stack[0];
    v_10791 = qcdr(v_10791);
    v_10791 = CC_zeroKroads(elt(env, 0), v_10791);
    goto v_10780;
v_10781:
    goto v_10777;
v_10778:
    goto v_10779;
v_10780:
    {
        LispObject v_10795 = stack[-1];
        return cons(v_10795, v_10791);
    }
v_10774:
    v_10791 = stack[0];
    v_10791 = qcdr(v_10791);
    stack[0] = v_10791;
    goto v_10756;
    v_10791 = nil;
    goto v_10760;
    v_10791 = nil;
v_10760:
    return onevalue(v_10791);
}



// Code for revalx

static LispObject CC_revalx(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10781, v_10782;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_10782 = v_10757;
// end of prologue
    v_10781 = v_10782;
    if (!consp(v_10781)) goto v_10767;
    v_10781 = v_10782;
    v_10781 = qcar(v_10781);
    v_10781 = (consp(v_10781) ? nil : lisp_true);
    v_10781 = (v_10781 == nil ? lisp_true : nil);
    goto v_10765;
v_10767:
    v_10781 = nil;
    goto v_10765;
    v_10781 = nil;
v_10765:
    if (v_10781 == nil) goto v_10763;
    v_10781 = v_10782;
    fn = elt(env, 1); // prepf
    v_10781 = (*qfn1(fn))(fn, v_10781);
    env = stack[0];
    goto v_10761;
v_10763:
    v_10781 = v_10782;
    goto v_10761;
    v_10781 = nil;
v_10761:
    {
        fn = elt(env, 2); // reval
        return (*qfn1(fn))(fn, v_10781);
    }
}



// Code for di_restore

static LispObject CC_di_restore(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10767, v_10768;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10767 = v_10757;
// end of prologue
    goto v_10764;
v_10760:
    v_10768 = v_10767;
    goto v_10761;
v_10762:
    v_10767 = nil;
    goto v_10763;
v_10764:
    goto v_10760;
v_10761:
    goto v_10762;
v_10763:
    {
        fn = elt(env, 1); // di_restore1
        return (*qfn2(fn))(fn, v_10768, v_10767);
    }
}



// Code for general!-reduce!-mod!-p

static LispObject CC_generalKreduceKmodKp(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10813, v_10814, v_10815;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10757;
// end of prologue
    v_10813 = stack[0];
    if (v_10813 == nil) goto v_10761;
    else goto v_10762;
v_10761:
    v_10813 = nil;
    goto v_10760;
v_10762:
    v_10813 = stack[0];
    if (!consp(v_10813)) goto v_10769;
    else goto v_10770;
v_10769:
    v_10813 = lisp_true;
    goto v_10768;
v_10770:
    v_10813 = stack[0];
    v_10813 = qcar(v_10813);
    v_10813 = (consp(v_10813) ? nil : lisp_true);
    goto v_10768;
    v_10813 = nil;
v_10768:
    if (v_10813 == nil) goto v_10766;
    v_10813 = stack[0];
    fn = elt(env, 1); // general!-modular!-number
    v_10813 = (*qfn1(fn))(fn, v_10813);
    env = stack[-2];
    {
        fn = elt(env, 2); // !*n2f
        return (*qfn1(fn))(fn, v_10813);
    }
v_10766:
    v_10813 = stack[0];
    v_10813 = qcar(v_10813);
    v_10813 = qcdr(v_10813);
    stack[-1] = CC_generalKreduceKmodKp(elt(env, 0), v_10813);
    env = stack[-2];
    v_10813 = stack[0];
    v_10813 = qcdr(v_10813);
    v_10813 = CC_generalKreduceKmodKp(elt(env, 0), v_10813);
    v_10814 = stack[-1];
    v_10815 = v_10814;
    if (v_10815 == nil) goto v_10794;
    else goto v_10795;
v_10794:
    goto v_10793;
v_10795:
    goto v_10807;
v_10801:
    v_10815 = stack[0];
    v_10815 = qcar(v_10815);
    v_10815 = qcar(v_10815);
    goto v_10802;
v_10803:
    goto v_10804;
v_10805:
    goto v_10806;
v_10807:
    goto v_10801;
v_10802:
    goto v_10803;
v_10804:
    goto v_10805;
v_10806:
    return acons(v_10815, v_10814, v_10813);
    v_10813 = nil;
v_10793:
    goto v_10760;
    v_10813 = nil;
v_10760:
    return onevalue(v_10813);
}



// Code for lex_save_context

static LispObject CC_lex_save_context(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10830, v_10831;
    argcheck(nargs, 0, "lex_save_context");
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
    stack_popper stack_popper_var(6);
// end of prologue
    v_10830 = qvalue(elt(env, 1)); // lex_codename
    stack[-4] = v_10830;
    v_10830 = stack[-4];
    if (v_10830 == nil) goto v_10767;
    else goto v_10768;
v_10767:
    v_10830 = nil;
    goto v_10762;
v_10768:
    v_10830 = stack[-4];
    v_10830 = qcar(v_10830);
    stack[0] = v_10830;
    goto v_10780;
v_10776:
    goto v_10786;
v_10782:
    v_10830 = stack[0];
    v_10830 = qcdr(v_10830);
    v_10831 = Lintern(nil, v_10830);
    env = stack[-5];
    goto v_10783;
v_10784:
    v_10830 = elt(env, 2); // lex_dipthong
    goto v_10785;
v_10786:
    goto v_10782;
v_10783:
    goto v_10784;
v_10785:
    v_10831 = get(v_10831, v_10830);
    env = stack[-5];
    goto v_10777;
v_10778:
    v_10830 = stack[0];
    goto v_10779;
v_10780:
    goto v_10776;
v_10777:
    goto v_10778;
v_10779:
    v_10830 = cons(v_10831, v_10830);
    env = stack[-5];
    v_10830 = ncons(v_10830);
    env = stack[-5];
    stack[-2] = v_10830;
    stack[-3] = v_10830;
v_10763:
    v_10830 = stack[-4];
    v_10830 = qcdr(v_10830);
    stack[-4] = v_10830;
    v_10830 = stack[-4];
    if (v_10830 == nil) goto v_10796;
    else goto v_10797;
v_10796:
    v_10830 = stack[-3];
    goto v_10762;
v_10797:
    goto v_10805;
v_10801:
    stack[-1] = stack[-2];
    goto v_10802;
v_10803:
    v_10830 = stack[-4];
    v_10830 = qcar(v_10830);
    stack[0] = v_10830;
    goto v_10816;
v_10812:
    goto v_10822;
v_10818:
    v_10830 = stack[0];
    v_10830 = qcdr(v_10830);
    v_10831 = Lintern(nil, v_10830);
    env = stack[-5];
    goto v_10819;
v_10820:
    v_10830 = elt(env, 2); // lex_dipthong
    goto v_10821;
v_10822:
    goto v_10818;
v_10819:
    goto v_10820;
v_10821:
    v_10831 = get(v_10831, v_10830);
    env = stack[-5];
    goto v_10813;
v_10814:
    v_10830 = stack[0];
    goto v_10815;
v_10816:
    goto v_10812;
v_10813:
    goto v_10814;
v_10815:
    v_10830 = cons(v_10831, v_10830);
    env = stack[-5];
    v_10830 = ncons(v_10830);
    env = stack[-5];
    goto v_10804;
v_10805:
    goto v_10801;
v_10802:
    goto v_10803;
v_10804:
    v_10830 = Lrplacd(nil, stack[-1], v_10830);
    env = stack[-5];
    v_10830 = stack[-2];
    v_10830 = qcdr(v_10830);
    stack[-2] = v_10830;
    goto v_10763;
v_10762:
    return onevalue(v_10830);
}



// Code for monomdivide

static LispObject CC_monomdivide(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_10878, v_10879, v_10880;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10757,v_10758);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_10758;
    stack[-4] = v_10757;
// end of prologue
    stack[-2] = nil;
    v_10878 = (LispObject)16+TAG_FIXNUM; // 1
    v_10878 = Lmkvect(nil, v_10878);
    env = stack[-6];
    stack[-5] = v_10878;
    goto v_10774;
v_10768:
    stack[-1] = stack[-5];
    goto v_10769;
v_10770:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10771;
v_10772:
    goto v_10782;
v_10778:
    goto v_10787;
v_10783:
    v_10879 = stack[-4];
    goto v_10784;
v_10785:
    v_10878 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10786;
v_10787:
    goto v_10783;
v_10784:
    goto v_10785;
v_10786:
    v_10880 = *(LispObject *)((char *)v_10879 + (CELL-TAG_VECTOR) + (((intptr_t)v_10878-TAG_FIXNUM)/(16/CELL)));
    goto v_10779;
v_10780:
    goto v_10795;
v_10791:
    v_10879 = stack[-3];
    goto v_10792;
v_10793:
    v_10878 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10794;
v_10795:
    goto v_10791;
v_10792:
    goto v_10793;
v_10794:
    v_10878 = *(LispObject *)((char *)v_10879 + (CELL-TAG_VECTOR) + (((intptr_t)v_10878-TAG_FIXNUM)/(16/CELL)));
    goto v_10781;
v_10782:
    goto v_10778;
v_10779:
    goto v_10780;
v_10781:
    v_10878 = difference2(v_10880, v_10878);
    env = stack[-6];
    goto v_10773;
v_10774:
    goto v_10768;
v_10769:
    goto v_10770;
v_10771:
    goto v_10772;
v_10773:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_10878;
    goto v_10803;
v_10799:
    v_10879 = stack[-4];
    goto v_10800;
v_10801:
    v_10878 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10802;
v_10803:
    goto v_10799;
v_10800:
    goto v_10801;
v_10802:
    v_10878 = *(LispObject *)((char *)v_10879 + (CELL-TAG_VECTOR) + (((intptr_t)v_10878-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_10878;
    goto v_10811;
v_10807:
    v_10879 = stack[-3];
    goto v_10808;
v_10809:
    v_10878 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10810;
v_10811:
    goto v_10807;
v_10808:
    goto v_10809;
v_10810:
    v_10878 = *(LispObject *)((char *)v_10879 + (CELL-TAG_VECTOR) + (((intptr_t)v_10878-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_10878;
v_10817:
    v_10878 = stack[0];
    v_10878 = qcar(v_10878);
    if (v_10878 == nil) goto v_10820;
    else goto v_10821;
v_10820:
    goto v_10816;
v_10821:
    goto v_10833;
v_10829:
    v_10878 = stack[0];
    v_10879 = qcar(v_10878);
    goto v_10830;
v_10831:
    v_10878 = stack[-1];
    v_10878 = qcar(v_10878);
    goto v_10832;
v_10833:
    goto v_10829;
v_10830:
    goto v_10831;
v_10832:
    if (equal(v_10879, v_10878)) goto v_10827;
    else goto v_10828;
v_10827:
    v_10878 = stack[0];
    v_10878 = qcdr(v_10878);
    stack[0] = v_10878;
    v_10878 = stack[-1];
    v_10878 = qcdr(v_10878);
    stack[-1] = v_10878;
    goto v_10826;
v_10828:
    goto v_10850;
v_10846:
    v_10878 = stack[0];
    v_10879 = qcar(v_10878);
    goto v_10847;
v_10848:
    v_10878 = stack[-2];
    goto v_10849;
v_10850:
    goto v_10846;
v_10847:
    goto v_10848;
v_10849:
    v_10878 = cons(v_10879, v_10878);
    env = stack[-6];
    stack[-2] = v_10878;
    v_10878 = stack[0];
    v_10878 = qcdr(v_10878);
    stack[0] = v_10878;
    goto v_10826;
v_10826:
    goto v_10817;
v_10816:
    goto v_10863;
v_10859:
    v_10879 = nil;
    goto v_10860;
v_10861:
    v_10878 = stack[-2];
    goto v_10862;
v_10863:
    goto v_10859;
v_10860:
    goto v_10861;
v_10862:
    v_10878 = cons(v_10879, v_10878);
    env = stack[-6];
    stack[-2] = v_10878;
    goto v_10872;
v_10866:
    stack[-1] = stack[-5];
    goto v_10867;
v_10868:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10869;
v_10870:
    v_10878 = stack[-2];
    v_10878 = Lreverse(nil, v_10878);
    goto v_10871;
v_10872:
    goto v_10866;
v_10867:
    goto v_10868;
v_10869:
    goto v_10870;
v_10871:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_10878;
    v_10878 = stack[-5];
    return onevalue(v_10878);
}



// Code for sfto_ucontentf1

static LispObject CC_sfto_ucontentf1(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_10830, v_10831;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10757,v_10758);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10758;
    stack[-1] = v_10757;
// end of prologue
    stack[-2] = nil;
v_10764:
    v_10830 = stack[-1];
    if (!consp(v_10830)) goto v_10777;
    else goto v_10778;
v_10777:
    v_10830 = lisp_true;
    goto v_10776;
v_10778:
    v_10830 = stack[-1];
    v_10830 = qcar(v_10830);
    v_10830 = (consp(v_10830) ? nil : lisp_true);
    goto v_10776;
    v_10830 = nil;
v_10776:
    if (v_10830 == nil) goto v_10774;
    v_10830 = lisp_true;
    goto v_10772;
v_10774:
    goto v_10794;
v_10790:
    v_10830 = stack[-1];
    v_10830 = qcar(v_10830);
    v_10830 = qcar(v_10830);
    v_10831 = qcar(v_10830);
    goto v_10791;
v_10792:
    v_10830 = stack[0];
    goto v_10793;
v_10794:
    goto v_10790;
v_10791:
    goto v_10792;
v_10793:
    v_10830 = Lneq(nil, v_10831, v_10830);
    env = stack[-3];
    goto v_10772;
    v_10830 = nil;
v_10772:
    if (v_10830 == nil) goto v_10770;
    goto v_10765;
v_10770:
    goto v_10805;
v_10801:
    v_10830 = stack[-1];
    v_10830 = qcar(v_10830);
    v_10831 = qcdr(v_10830);
    goto v_10802;
v_10803:
    v_10830 = stack[-2];
    goto v_10804;
v_10805:
    goto v_10801;
v_10802:
    goto v_10803;
v_10804:
    v_10830 = cons(v_10831, v_10830);
    env = stack[-3];
    stack[-2] = v_10830;
    v_10830 = stack[-1];
    v_10830 = qcdr(v_10830);
    stack[-1] = v_10830;
    goto v_10764;
v_10765:
    v_10830 = stack[-1];
    v_10831 = v_10830;
v_10766:
    v_10830 = stack[-2];
    if (v_10830 == nil) goto v_10815;
    else goto v_10816;
v_10815:
    v_10830 = v_10831;
    goto v_10763;
v_10816:
    goto v_10824;
v_10820:
    v_10830 = stack[-2];
    v_10830 = qcar(v_10830);
    goto v_10821;
v_10822:
    goto v_10823;
v_10824:
    goto v_10820;
v_10821:
    goto v_10822;
v_10823:
    fn = elt(env, 1); // sfto_gcdf!*
    v_10830 = (*qfn2(fn))(fn, v_10830, v_10831);
    env = stack[-3];
    v_10831 = v_10830;
    v_10830 = stack[-2];
    v_10830 = qcdr(v_10830);
    stack[-2] = v_10830;
    goto v_10766;
v_10763:
    return onevalue(v_10830);
}



// Code for simpg3

static LispObject CC_simpg3(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10767, v_10768;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10767 = v_10757;
// end of prologue
    goto v_10764;
v_10760:
    v_10768 = v_10767;
    goto v_10761;
v_10762:
    v_10767 = elt(env, 1); // g3
    goto v_10763;
v_10764:
    goto v_10760;
v_10761:
    goto v_10762;
v_10763:
    {
        fn = elt(env, 2); // simpcv
        return (*qfn2(fn))(fn, v_10768, v_10767);
    }
}



// Code for findnthroot

static LispObject CC_findnthroot(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10760;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10760 = v_10757;
// end of prologue
    v_10760 = nil;
    return onevalue(v_10760);
}



// Code for prepsq!*

static LispObject CC_prepsqH(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_11064, v_11065, v_11066;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_10757;
// end of prologue
// Binding !*combinelogs
// FLUIDBIND: reloadenv=11 litvec-offset=1 saveloc=8
{   bind_fluid_stack bind_fluid_var(-11, 1, -8);
    qvalue(elt(env, 1)) = nil; // !*combinelogs
    v_11064 = stack[-9];
    v_11064 = qcar(v_11064);
    if (v_11064 == nil) goto v_10766;
    else goto v_10767;
v_10766:
    v_11064 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10763;
v_10767:
    v_11064 = qvalue(elt(env, 2)); // ordl!*
    fn = elt(env, 13); // setkorder
    v_11064 = (*qfn1(fn))(fn, v_11064);
    env = stack[-11];
    stack[-10] = v_11064;
    goto v_10779;
v_10775:
    goto v_10785;
v_10781:
    v_11064 = qvalue(elt(env, 3)); // factors!*
    stack[-7] = v_11064;
v_10791:
    v_11064 = stack[-7];
    if (v_11064 == nil) goto v_10796;
    else goto v_10797;
v_10796:
    v_11064 = nil;
    v_11065 = v_11064;
    goto v_10790;
v_10797:
    v_11064 = stack[-7];
    v_11064 = qcar(v_11064);
    v_11065 = v_11064;
    v_11064 = v_11065;
    if (symbolp(v_11064)) goto v_10806;
    v_11064 = nil;
    goto v_10804;
v_10806:
    goto v_10816;
v_10812:
    v_11066 = v_11065;
    goto v_10813;
v_10814:
    v_11064 = elt(env, 4); // prepsq!*fn
    goto v_10815;
v_10816:
    goto v_10812;
v_10813:
    goto v_10814;
v_10815:
    v_11064 = get(v_11066, v_11064);
    env = stack[-11];
    v_11066 = v_11064;
    if (v_11064 == nil) goto v_10810;
    goto v_10826;
v_10820:
    goto v_10821;
v_10822:
    v_11064 = stack[-9];
    goto v_10823;
v_10824:
    goto v_10825;
v_10826:
    goto v_10820;
v_10821:
    goto v_10822;
v_10823:
    goto v_10824;
v_10825:
    v_11064 = Lapply2(nil, 3, v_11066, v_11064, v_11065);
    env = stack[-11];
    goto v_10804;
v_10810:
    v_11064 = v_11065;
    if (!symbolp(v_11064)) v_11064 = nil;
    else { v_11064 = qfastgets(v_11064);
           if (v_11064 != nil) { v_11064 = elt(v_11064, 24); // klist
#ifdef RECORD_GET
             if (v_11064 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v_11064 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v_11064 == SPID_NOPROP) v_11064 = nil; }}
#endif
    stack[-3] = v_11064;
    v_11064 = stack[-3];
    if (v_11064 == nil) goto v_10842;
    else goto v_10843;
v_10842:
    v_11064 = nil;
    goto v_10836;
v_10843:
    v_11064 = stack[-3];
    v_11064 = qcar(v_11064);
    v_11064 = qcar(v_11064);
    v_11064 = ncons(v_11064);
    env = stack[-11];
    stack[-1] = v_11064;
    stack[-2] = v_11064;
v_10837:
    v_11064 = stack[-3];
    v_11064 = qcdr(v_11064);
    stack[-3] = v_11064;
    v_11064 = stack[-3];
    if (v_11064 == nil) goto v_10856;
    else goto v_10857;
v_10856:
    v_11064 = stack[-2];
    goto v_10836;
v_10857:
    goto v_10865;
v_10861:
    stack[0] = stack[-1];
    goto v_10862;
v_10863:
    v_11064 = stack[-3];
    v_11064 = qcar(v_11064);
    v_11064 = qcar(v_11064);
    v_11064 = ncons(v_11064);
    env = stack[-11];
    goto v_10864;
v_10865:
    goto v_10861;
v_10862:
    goto v_10863;
v_10864:
    v_11064 = Lrplacd(nil, stack[0], v_11064);
    env = stack[-11];
    v_11064 = stack[-1];
    v_11064 = qcdr(v_11064);
    stack[-1] = v_11064;
    goto v_10837;
v_10836:
    goto v_10804;
    v_11064 = nil;
v_10804:
    stack[-6] = v_11064;
    v_11064 = stack[-6];
    fn = elt(env, 14); // lastpair
    v_11064 = (*qfn1(fn))(fn, v_11064);
    env = stack[-11];
    stack[-5] = v_11064;
    v_11064 = stack[-7];
    v_11064 = qcdr(v_11064);
    stack[-7] = v_11064;
    v_11064 = stack[-5];
    if (!consp(v_11064)) goto v_10881;
    else goto v_10882;
v_10881:
    goto v_10791;
v_10882:
v_10792:
    v_11064 = stack[-7];
    if (v_11064 == nil) goto v_10886;
    else goto v_10887;
v_10886:
    v_11064 = stack[-6];
    v_11065 = v_11064;
    goto v_10790;
v_10887:
    goto v_10895;
v_10891:
    stack[-4] = stack[-5];
    goto v_10892;
v_10893:
    v_11064 = stack[-7];
    v_11064 = qcar(v_11064);
    v_11065 = v_11064;
    if (symbolp(v_11065)) goto v_10903;
    v_11064 = nil;
    goto v_10901;
v_10903:
    goto v_10913;
v_10909:
    v_11066 = v_11064;
    goto v_10910;
v_10911:
    v_11065 = elt(env, 4); // prepsq!*fn
    goto v_10912;
v_10913:
    goto v_10909;
v_10910:
    goto v_10911;
v_10912:
    v_11065 = get(v_11066, v_11065);
    env = stack[-11];
    v_11066 = v_11065;
    if (v_11065 == nil) goto v_10907;
    goto v_10923;
v_10917:
    goto v_10918;
v_10919:
    v_11065 = stack[-9];
    goto v_10920;
v_10921:
    goto v_10922;
v_10923:
    goto v_10917;
v_10918:
    goto v_10919;
v_10920:
    goto v_10921;
v_10922:
    v_11064 = Lapply2(nil, 3, v_11066, v_11065, v_11064);
    env = stack[-11];
    goto v_10901;
v_10907:
    if (!symbolp(v_11064)) v_11064 = nil;
    else { v_11064 = qfastgets(v_11064);
           if (v_11064 != nil) { v_11064 = elt(v_11064, 24); // klist
#ifdef RECORD_GET
             if (v_11064 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v_11064 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v_11064 == SPID_NOPROP) v_11064 = nil; }}
#endif
    stack[-3] = v_11064;
    v_11064 = stack[-3];
    if (v_11064 == nil) goto v_10939;
    else goto v_10940;
v_10939:
    v_11064 = nil;
    goto v_10933;
v_10940:
    v_11064 = stack[-3];
    v_11064 = qcar(v_11064);
    v_11064 = qcar(v_11064);
    v_11064 = ncons(v_11064);
    env = stack[-11];
    stack[-1] = v_11064;
    stack[-2] = v_11064;
v_10934:
    v_11064 = stack[-3];
    v_11064 = qcdr(v_11064);
    stack[-3] = v_11064;
    v_11064 = stack[-3];
    if (v_11064 == nil) goto v_10953;
    else goto v_10954;
v_10953:
    v_11064 = stack[-2];
    goto v_10933;
v_10954:
    goto v_10962;
v_10958:
    stack[0] = stack[-1];
    goto v_10959;
v_10960:
    v_11064 = stack[-3];
    v_11064 = qcar(v_11064);
    v_11064 = qcar(v_11064);
    v_11064 = ncons(v_11064);
    env = stack[-11];
    goto v_10961;
v_10962:
    goto v_10958;
v_10959:
    goto v_10960;
v_10961:
    v_11064 = Lrplacd(nil, stack[0], v_11064);
    env = stack[-11];
    v_11064 = stack[-1];
    v_11064 = qcdr(v_11064);
    stack[-1] = v_11064;
    goto v_10934;
v_10933:
    goto v_10901;
    v_11064 = nil;
v_10901:
    goto v_10894;
v_10895:
    goto v_10891;
v_10892:
    goto v_10893;
v_10894:
    v_11064 = Lrplacd(nil, stack[-4], v_11064);
    env = stack[-11];
    v_11064 = stack[-5];
    fn = elt(env, 14); // lastpair
    v_11064 = (*qfn1(fn))(fn, v_11064);
    env = stack[-11];
    stack[-5] = v_11064;
    v_11064 = stack[-7];
    v_11064 = qcdr(v_11064);
    stack[-7] = v_11064;
    goto v_10792;
v_10790:
    goto v_10782;
v_10783:
    v_11064 = elt(env, 5); // ordop
    goto v_10784;
v_10785:
    goto v_10781;
v_10782:
    goto v_10783;
v_10784:
    fn = elt(env, 15); // sort
    stack[0] = (*qfn2(fn))(fn, v_11065, v_11064);
    env = stack[-11];
    goto v_10776;
v_10777:
    goto v_10982;
v_10978:
    goto v_10988;
v_10984:
    v_11065 = qvalue(elt(env, 3)); // factors!*
    goto v_10985;
v_10986:
    v_11064 = elt(env, 5); // ordop
    goto v_10987;
v_10988:
    goto v_10984;
v_10985:
    goto v_10986;
v_10987:
    fn = elt(env, 15); // sort
    v_11065 = (*qfn2(fn))(fn, v_11065, v_11064);
    env = stack[-11];
    goto v_10979;
v_10980:
    v_11064 = qvalue(elt(env, 2)); // ordl!*
    goto v_10981;
v_10982:
    goto v_10978;
v_10979:
    goto v_10980;
v_10981:
    v_11064 = Lappend(nil, v_11065, v_11064);
    env = stack[-11];
    goto v_10778;
v_10779:
    goto v_10775;
v_10776:
    goto v_10777;
v_10778:
    v_11064 = Lappend(nil, stack[0], v_11064);
    env = stack[-11];
    fn = elt(env, 13); // setkorder
    v_11064 = (*qfn1(fn))(fn, v_11064);
    env = stack[-11];
    goto v_11004;
v_11000:
    v_11065 = qvalue(elt(env, 6)); // kord!*
    goto v_11001;
v_11002:
    v_11064 = stack[-10];
    goto v_11003;
v_11004:
    goto v_11000;
v_11001:
    goto v_11002;
v_11003:
    if (equal(v_11065, v_11064)) goto v_10999;
    v_11064 = lisp_true;
    goto v_10997;
v_10999:
    v_11064 = qvalue(elt(env, 7)); // wtl!*
    goto v_10997;
    v_11064 = nil;
v_10997:
    if (v_11064 == nil) goto v_10995;
    goto v_11016;
v_11012:
    v_11064 = stack[-9];
    v_11064 = qcar(v_11064);
    fn = elt(env, 16); // formop
    stack[0] = (*qfn1(fn))(fn, v_11064);
    env = stack[-11];
    goto v_11013;
v_11014:
    v_11064 = stack[-9];
    v_11064 = qcdr(v_11064);
    fn = elt(env, 16); // formop
    v_11064 = (*qfn1(fn))(fn, v_11064);
    env = stack[-11];
    goto v_11015;
v_11016:
    goto v_11012;
v_11013:
    goto v_11014;
v_11015:
    v_11064 = cons(stack[0], v_11064);
    env = stack[-11];
    stack[-9] = v_11064;
    goto v_10993;
v_10995:
v_10993:
    v_11064 = qvalue(elt(env, 8)); // !*rat
    if (v_11064 == nil) goto v_11027;
    else goto v_11025;
v_11027:
    v_11064 = qvalue(elt(env, 9)); // !*div
    if (v_11064 == nil) goto v_11030;
    else goto v_11025;
v_11030:
    v_11064 = qvalue(elt(env, 10)); // upl!*
    if (v_11064 == nil) goto v_11033;
    else goto v_11025;
v_11033:
    v_11064 = qvalue(elt(env, 11)); // dnl!*
    if (v_11064 == nil) goto v_11035;
    else goto v_11025;
v_11035:
    goto v_11026;
v_11025:
    goto v_11045;
v_11039:
    v_11064 = stack[-9];
    v_11066 = qcar(v_11064);
    goto v_11040;
v_11041:
    v_11064 = stack[-9];
    v_11065 = qcdr(v_11064);
    goto v_11042;
v_11043:
    v_11064 = nil;
    goto v_11044;
v_11045:
    goto v_11039;
v_11040:
    goto v_11041;
v_11042:
    goto v_11043;
v_11044:
    fn = elt(env, 17); // prepsq!*1
    v_11064 = (*qfnn(fn))(fn, 3, v_11066, v_11065, v_11064);
    env = stack[-11];
    fn = elt(env, 18); // replus
    v_11064 = (*qfn1(fn))(fn, v_11064);
    env = stack[-11];
    goto v_11024;
v_11026:
    goto v_11058;
v_11054:
    v_11065 = stack[-9];
    goto v_11055;
v_11056:
    v_11064 = elt(env, 12); // prepsq!*2
    goto v_11057;
v_11058:
    goto v_11054;
v_11055:
    goto v_11056;
v_11057:
    fn = elt(env, 19); // sqform
    v_11064 = (*qfn2(fn))(fn, v_11065, v_11064);
    env = stack[-11];
    goto v_11024;
    v_11064 = nil;
v_11024:
    stack[-9] = v_11064;
    v_11064 = stack[-10];
    fn = elt(env, 13); // setkorder
    v_11064 = (*qfn1(fn))(fn, v_11064);
    v_11064 = stack[-9];
v_10763:
    ;}  // end of a binding scope
    return onevalue(v_11064);
}



// Code for ibalp_recalcv

static LispObject CC_ibalp_recalcv(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10845, v_10846;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_10845 = v_10757;
// end of prologue
    stack[-2] = v_10845;
v_10762:
    v_10845 = stack[-2];
    if (v_10845 == nil) goto v_10766;
    else goto v_10767;
v_10766:
    v_10845 = nil;
    goto v_10761;
v_10767:
    v_10845 = stack[-2];
    v_10845 = qcar(v_10845);
    stack[-1] = v_10845;
    goto v_10778;
v_10774:
    v_10845 = stack[-1];
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    stack[0] = qcdr(v_10845);
    goto v_10775;
v_10776:
    goto v_10794;
v_10790:
    v_10845 = stack[-1];
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10846 = qcar(v_10845);
    goto v_10791;
v_10792:
    v_10845 = elt(env, 1); // 0.05
    goto v_10793;
v_10794:
    goto v_10790;
v_10791:
    goto v_10792;
v_10793:
    v_10845 = difference2(v_10846, v_10845);
    env = stack[-3];
    goto v_10777;
v_10778:
    goto v_10774;
v_10775:
    goto v_10776;
v_10777:
    fn = elt(env, 2); // setcar
    v_10845 = (*qfn2(fn))(fn, stack[0], v_10845);
    env = stack[-3];
    goto v_10812;
v_10808:
    v_10845 = stack[-1];
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    stack[0] = qcdr(v_10845);
    goto v_10809;
v_10810:
    goto v_10829;
v_10825:
    v_10845 = stack[-1];
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10845 = qcdr(v_10845);
    v_10846 = qcar(v_10845);
    goto v_10826;
v_10827:
    v_10845 = elt(env, 1); // 0.05
    goto v_10828;
v_10829:
    goto v_10825;
v_10826:
    goto v_10827;
v_10828:
    v_10845 = difference2(v_10846, v_10845);
    env = stack[-3];
    goto v_10811;
v_10812:
    goto v_10808;
v_10809:
    goto v_10810;
v_10811:
    fn = elt(env, 2); // setcar
    v_10845 = (*qfn2(fn))(fn, stack[0], v_10845);
    env = stack[-3];
    v_10845 = stack[-2];
    v_10845 = qcdr(v_10845);
    stack[-2] = v_10845;
    goto v_10762;
v_10761:
    return onevalue(v_10845);
}



// Code for mvar_member

static LispObject CC_mvar_member(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_10791, v_10792, v_10793, v_10794;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10793 = v_10758;
    v_10794 = v_10757;
// end of prologue
    goto v_10768;
v_10764:
    v_10792 = v_10794;
    goto v_10765;
v_10766:
    v_10791 = v_10793;
    goto v_10767;
v_10768:
    goto v_10764;
v_10765:
    goto v_10766;
v_10767:
    if (equal(v_10792, v_10791)) goto v_10762;
    else goto v_10763;
v_10762:
    v_10791 = lisp_true;
    goto v_10761;
v_10763:
    v_10791 = v_10793;
    if (!consp(v_10791)) goto v_10777;
    goto v_10784;
v_10780:
    v_10791 = v_10794;
    goto v_10781;
v_10782:
    v_10792 = v_10793;
    v_10792 = qcdr(v_10792);
    goto v_10783;
v_10784:
    goto v_10780;
v_10781:
    goto v_10782;
v_10783:
    {
        fn = elt(env, 1); // arglist_member
        return (*qfn2(fn))(fn, v_10791, v_10792);
    }
v_10777:
    v_10791 = nil;
    goto v_10775;
    v_10791 = nil;
v_10775:
    goto v_10761;
    v_10791 = nil;
v_10761:
    return onevalue(v_10791);
}



// Code for variablesir

static LispObject CC_variablesir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10800, v_10801;
    LispObject fn;
    argcheck(nargs, 0, "variablesir");
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
    goto v_10770;
v_10766:
    v_10801 = qvalue(elt(env, 1)); // char
    goto v_10767;
v_10768:
    v_10800 = elt(env, 2); // (!/ o m b v a r)
    goto v_10769;
v_10770:
    goto v_10766;
v_10767:
    goto v_10768;
v_10769:
    if (equal(v_10801, v_10800)) goto v_10765;
    fn = elt(env, 3); // omvir
    v_10800 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_10800;
    fn = elt(env, 4); // lex
    v_10800 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_10800 = CC_variablesir(elt(env, 0), 0);
    v_10801 = stack[0];
    if (v_10801 == nil) goto v_10778;
    else goto v_10779;
v_10778:
    goto v_10786;
v_10782:
    v_10801 = stack[0];
    goto v_10783;
v_10784:
    goto v_10785;
v_10786:
    goto v_10782;
v_10783:
    goto v_10784;
v_10785:
        return Lappend(nil, v_10801, v_10800);
v_10779:
    goto v_10796;
v_10792:
    v_10801 = stack[0];
    goto v_10793;
v_10794:
    goto v_10795;
v_10796:
    goto v_10792;
v_10793:
    goto v_10794;
v_10795:
    return cons(v_10801, v_10800);
    goto v_10763;
v_10765:
v_10763:
    v_10800 = nil;
    return onevalue(v_10800);
}



// Code for evmtest!?

static LispObject CC_evmtestW(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_10795, v_10796, v_10797, v_10798;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10796 = v_10758;
    v_10797 = v_10757;
// end of prologue
v_10762:
    v_10795 = v_10797;
    if (v_10795 == nil) goto v_10766;
    v_10795 = v_10796;
    if (v_10795 == nil) goto v_10766;
    goto v_10779;
v_10775:
    v_10795 = v_10797;
    v_10798 = qcar(v_10795);
    goto v_10776;
v_10777:
    v_10795 = v_10796;
    v_10795 = qcar(v_10795);
    goto v_10778;
v_10779:
    goto v_10775;
v_10776:
    goto v_10777;
v_10778:
    if (((intptr_t)(v_10798)) < ((intptr_t)(v_10795))) goto v_10774;
    v_10795 = v_10797;
    v_10795 = qcdr(v_10795);
    v_10797 = v_10795;
    v_10795 = v_10796;
    v_10795 = qcdr(v_10795);
    v_10796 = v_10795;
    goto v_10762;
v_10774:
    v_10795 = nil;
    goto v_10761;
    goto v_10764;
v_10766:
    v_10795 = v_10796;
    {
        fn = elt(env, 1); // evzero!?
        return (*qfn1(fn))(fn, v_10795);
    }
v_10764:
    v_10795 = nil;
v_10761:
    return onevalue(v_10795);
}



// Code for xord_deglex

static LispObject CC_xord_deglex(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_10821, v_10822, v_10823, v_10824;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10757,v_10758);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10758;
    stack[-1] = v_10757;
// end of prologue
    goto v_10768;
v_10764:
    v_10821 = stack[-1];
    v_10822 = qcar(v_10821);
    goto v_10765;
v_10766:
    v_10821 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10767;
v_10768:
    goto v_10764;
v_10765:
    goto v_10766;
v_10767:
    if (v_10822 == v_10821) goto v_10762;
    else goto v_10763;
v_10762:
    v_10821 = nil;
    goto v_10761;
v_10763:
    goto v_10779;
v_10775:
    v_10821 = stack[0];
    v_10822 = qcar(v_10821);
    goto v_10776;
v_10777:
    v_10821 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10778;
v_10779:
    goto v_10775;
v_10776:
    goto v_10777;
v_10778:
    if (v_10822 == v_10821) goto v_10773;
    else goto v_10774;
v_10773:
    v_10821 = lisp_true;
    goto v_10761;
v_10774:
    v_10821 = stack[-1];
    fn = elt(env, 1); // xdegreemon
    stack[-2] = (*qfn1(fn))(fn, v_10821);
    env = stack[-3];
    v_10821 = stack[0];
    fn = elt(env, 1); // xdegreemon
    v_10821 = (*qfn1(fn))(fn, v_10821);
    env = stack[-3];
    v_10824 = stack[-2];
    v_10823 = v_10821;
    goto v_10800;
v_10796:
    v_10822 = v_10824;
    goto v_10797;
v_10798:
    v_10821 = v_10823;
    goto v_10799;
v_10800:
    goto v_10796;
v_10797:
    goto v_10798;
v_10799:
    if (equal(v_10822, v_10821)) goto v_10794;
    else goto v_10795;
v_10794:
    goto v_10808;
v_10804:
    v_10822 = stack[-1];
    goto v_10805;
v_10806:
    v_10821 = stack[0];
    goto v_10807;
v_10808:
    goto v_10804;
v_10805:
    goto v_10806;
v_10807:
    {
        fn = elt(env, 2); // xord_lex
        return (*qfn2(fn))(fn, v_10822, v_10821);
    }
v_10795:
    goto v_10818;
v_10814:
    v_10821 = v_10824;
    goto v_10815;
v_10816:
    v_10822 = v_10823;
    goto v_10817;
v_10818:
    goto v_10814;
v_10815:
    goto v_10816;
v_10817:
        return Lgreaterp(nil, v_10821, v_10822);
    v_10821 = nil;
    goto v_10761;
    v_10821 = nil;
v_10761:
    return onevalue(v_10821);
}



// Code for invp

static LispObject CC_invp(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10823, v_10824, v_10825;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
// copy arguments values to proper place
    v_10825 = v_10757;
// end of prologue
    goto v_10767;
v_10763:
    v_10824 = v_10825;
    goto v_10764;
v_10765:
    v_10823 = elt(env, 1); // unit
    goto v_10766;
v_10767:
    goto v_10763;
v_10764:
    goto v_10765;
v_10766:
    if (v_10824 == v_10823) goto v_10761;
    else goto v_10762;
v_10761:
    v_10823 = v_10825;
    goto v_10760;
v_10762:
    v_10823 = v_10825;
    if (!consp(v_10823)) goto v_10771;
    else goto v_10772;
v_10771:
    goto v_10779;
v_10775:
    v_10823 = v_10825;
    goto v_10776;
v_10777:
    v_10824 = elt(env, 2); // inverse
    goto v_10778;
v_10779:
    goto v_10775;
v_10776:
    goto v_10777;
v_10778:
    return get(v_10823, v_10824);
v_10772:
    goto v_10788;
v_10784:
    v_10823 = v_10825;
    v_10824 = qcar(v_10823);
    goto v_10785;
v_10786:
    v_10823 = elt(env, 3); // (comm anticomm)
    goto v_10787;
v_10788:
    goto v_10784;
v_10785:
    goto v_10786;
v_10787:
    v_10823 = Lmember(nil, v_10824, v_10823);
    if (v_10823 == nil) goto v_10783;
    goto v_10800;
v_10794:
    v_10824 = elt(env, 4); // quotient
    goto v_10795;
v_10796:
    v_10823 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10797;
v_10798:
    goto v_10799;
v_10800:
    goto v_10794;
v_10795:
    goto v_10796;
v_10797:
    goto v_10798;
v_10799:
    return list3(v_10824, v_10823, v_10825);
v_10783:
    goto v_10811;
v_10807:
    goto v_10817;
v_10813:
    v_10823 = v_10825;
    v_10824 = qcar(v_10823);
    goto v_10814;
v_10815:
    v_10823 = elt(env, 2); // inverse
    goto v_10816;
v_10817:
    goto v_10813;
v_10814:
    goto v_10815;
v_10816:
    v_10823 = get(v_10824, v_10823);
    goto v_10808;
v_10809:
    v_10824 = v_10825;
    v_10824 = qcdr(v_10824);
    goto v_10810;
v_10811:
    goto v_10807;
v_10808:
    goto v_10809;
v_10810:
    return cons(v_10823, v_10824);
    v_10823 = nil;
v_10760:
    return onevalue(v_10823);
}



// Code for contr

static LispObject CC_contr(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_10791, v_10792;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10757,v_10758);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10758;
    stack[-1] = v_10757;
// end of prologue
    stack[-2] = nil;
v_10763:
    v_10791 = stack[0];
    if (v_10791 == nil) goto v_10766;
    else goto v_10767;
v_10766:
    v_10791 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_10791);
    }
v_10767:
    goto v_10778;
v_10774:
    goto v_10784;
v_10780:
    v_10792 = stack[-1];
    goto v_10781;
v_10782:
    v_10791 = stack[0];
    v_10791 = qcar(v_10791);
    goto v_10783;
v_10784:
    goto v_10780;
v_10781:
    goto v_10782;
v_10783:
    fn = elt(env, 2); // split!-road
    v_10792 = (*qfn2(fn))(fn, v_10792, v_10791);
    env = stack[-3];
    goto v_10775;
v_10776:
    v_10791 = stack[-2];
    goto v_10777;
v_10778:
    goto v_10774;
v_10775:
    goto v_10776;
v_10777:
    v_10791 = cons(v_10792, v_10791);
    env = stack[-3];
    stack[-2] = v_10791;
    v_10791 = stack[0];
    v_10791 = qcdr(v_10791);
    stack[0] = v_10791;
    goto v_10763;
    v_10791 = nil;
    return onevalue(v_10791);
}



// Code for repasc

static LispObject CC_repasc(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10841, v_10842, v_10843;
    LispObject fn;
    LispObject v_10759, v_10758, v_10757;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "repasc");
    va_start(aa, nargs);
    v_10757 = va_arg(aa, LispObject);
    v_10758 = va_arg(aa, LispObject);
    v_10759 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_10759,v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_10757,v_10758,v_10759);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_10759;
    stack[-1] = v_10758;
    stack[-2] = v_10757;
// end of prologue
    v_10843 = nil;
v_10764:
    v_10841 = stack[0];
    if (v_10841 == nil) goto v_10767;
    else goto v_10768;
v_10767:
    goto v_10775;
v_10771:
    stack[-3] = v_10843;
    goto v_10772;
v_10773:
    goto v_10784;
v_10778:
    stack[-1] = elt(env, 1); // alg
    goto v_10779;
v_10780:
    stack[0] = (LispObject)112+TAG_FIXNUM; // 7
    goto v_10781;
v_10782:
    goto v_10794;
v_10788:
    v_10843 = elt(env, 2); // "key"
    goto v_10789;
v_10790:
    v_10842 = stack[-2];
    goto v_10791;
v_10792:
    v_10841 = elt(env, 3); // "not found"
    goto v_10793;
v_10794:
    goto v_10788;
v_10789:
    goto v_10790;
v_10791:
    goto v_10792;
v_10793:
    v_10841 = list3(v_10843, v_10842, v_10841);
    env = stack[-4];
    goto v_10783;
v_10784:
    goto v_10778;
v_10779:
    goto v_10780;
v_10781:
    goto v_10782;
v_10783:
    fn = elt(env, 4); // rerror
    v_10841 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_10841);
    env = stack[-4];
    goto v_10774;
v_10775:
    goto v_10771;
v_10772:
    goto v_10773;
v_10774:
    {
        LispObject v_10848 = stack[-3];
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(fn, v_10848, v_10841);
    }
v_10768:
    goto v_10804;
v_10800:
    v_10842 = stack[-2];
    goto v_10801;
v_10802:
    v_10841 = stack[0];
    v_10841 = qcar(v_10841);
    v_10841 = qcar(v_10841);
    goto v_10803;
v_10804:
    goto v_10800;
v_10801:
    goto v_10802;
v_10803:
    if (equal(v_10842, v_10841)) goto v_10798;
    else goto v_10799;
v_10798:
    goto v_10814;
v_10810:
    stack[-3] = v_10843;
    goto v_10811;
v_10812:
    goto v_10823;
v_10817:
    v_10843 = stack[-2];
    goto v_10818;
v_10819:
    v_10842 = stack[-1];
    goto v_10820;
v_10821:
    v_10841 = stack[0];
    v_10841 = qcdr(v_10841);
    goto v_10822;
v_10823:
    goto v_10817;
v_10818:
    goto v_10819;
v_10820:
    goto v_10821;
v_10822:
    v_10841 = acons(v_10843, v_10842, v_10841);
    env = stack[-4];
    goto v_10813;
v_10814:
    goto v_10810;
v_10811:
    goto v_10812;
v_10813:
    {
        LispObject v_10849 = stack[-3];
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(fn, v_10849, v_10841);
    }
v_10799:
    goto v_10835;
v_10831:
    v_10841 = stack[0];
    v_10841 = qcar(v_10841);
    goto v_10832;
v_10833:
    v_10842 = v_10843;
    goto v_10834;
v_10835:
    goto v_10831;
v_10832:
    goto v_10833;
v_10834:
    v_10841 = cons(v_10841, v_10842);
    env = stack[-4];
    v_10843 = v_10841;
    v_10841 = stack[0];
    v_10841 = qcdr(v_10841);
    stack[0] = v_10841;
    goto v_10764;
    v_10841 = nil;
    return onevalue(v_10841);
}



// Code for addgt

static LispObject CC_addgt(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10789, v_10790;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10757;
// end of prologue
    goto v_10767;
v_10763:
    v_10790 = qvalue(elt(env, 1)); // ordering
    goto v_10764;
v_10765:
    v_10789 = elt(env, 2); // lex
    goto v_10766;
v_10767:
    goto v_10763;
v_10764:
    goto v_10765;
v_10766:
    if (v_10790 == v_10789) goto v_10761;
    else goto v_10762;
v_10761:
    v_10789 = stack[0];
    goto v_10760;
v_10762:
    goto v_10778;
v_10774:
    goto v_10785;
v_10781:
    v_10790 = elt(env, 3); // plus
    goto v_10782;
v_10783:
    v_10789 = stack[0];
    goto v_10784;
v_10785:
    goto v_10781;
v_10782:
    goto v_10783;
v_10784:
    v_10789 = cons(v_10790, v_10789);
    env = stack[-1];
    fn = elt(env, 4); // eval
    v_10790 = (*qfn1(fn))(fn, v_10789);
    goto v_10775;
v_10776:
    v_10789 = stack[0];
    goto v_10777;
v_10778:
    goto v_10774;
v_10775:
    goto v_10776;
v_10777:
    return cons(v_10790, v_10789);
    v_10789 = nil;
v_10760:
    return onevalue(v_10789);
}



// Code for il_simp

static LispObject CC_il_simp(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10767, v_10768;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10767 = v_10757;
// end of prologue
    goto v_10764;
v_10760:
    v_10768 = v_10767;
    goto v_10761;
v_10762:
    v_10767 = nil;
    goto v_10763;
v_10764:
    goto v_10760;
v_10761:
    goto v_10762;
v_10763:
    {
        fn = elt(env, 1); // il_simp1
        return (*qfn2(fn))(fn, v_10768, v_10767);
    }
}



// Code for ordexn

static LispObject CC_ordexn(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_10849, v_10850;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10757,v_10758);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_10758;
    stack[-2] = v_10757;
// end of prologue
    stack[0] = nil;
    stack[-3] = nil;
v_10764:
    v_10849 = stack[-1];
    if (v_10849 == nil) goto v_10767;
    else goto v_10768;
v_10767:
    goto v_10775;
v_10771:
    goto v_10772;
v_10773:
    goto v_10783;
v_10779:
    v_10850 = stack[-2];
    goto v_10780;
v_10781:
    v_10849 = stack[-3];
    goto v_10782;
v_10783:
    goto v_10779;
v_10780:
    goto v_10781;
v_10782:
    v_10849 = cons(v_10850, v_10849);
    env = stack[-4];
    v_10849 = Lreverse(nil, v_10849);
    goto v_10774;
v_10775:
    goto v_10771;
v_10772:
    goto v_10773;
v_10774:
    {
        LispObject v_10855 = stack[0];
        return cons(v_10855, v_10849);
    }
v_10768:
    goto v_10792;
v_10788:
    v_10850 = stack[-2];
    goto v_10789;
v_10790:
    v_10849 = stack[-1];
    v_10849 = qcar(v_10849);
    goto v_10791;
v_10792:
    goto v_10788;
v_10789:
    goto v_10790;
v_10791:
    if (v_10850 == v_10849) goto v_10786;
    else goto v_10787;
v_10786:
    v_10849 = nil;
    goto v_10763;
v_10787:
    v_10849 = stack[-2];
    if (v_10849 == nil) goto v_10798;
    goto v_10807;
v_10803:
    v_10850 = stack[-2];
    goto v_10804;
v_10805:
    v_10849 = stack[-1];
    v_10849 = qcar(v_10849);
    goto v_10806;
v_10807:
    goto v_10803;
v_10804:
    goto v_10805;
v_10806:
    fn = elt(env, 1); // ordop
    v_10849 = (*qfn2(fn))(fn, v_10850, v_10849);
    env = stack[-4];
    if (v_10849 == nil) goto v_10798;
    goto v_10816;
v_10812:
    goto v_10813;
v_10814:
    goto v_10823;
v_10819:
    goto v_10830;
v_10826:
    v_10850 = stack[-2];
    goto v_10827;
v_10828:
    v_10849 = stack[-3];
    goto v_10829;
v_10830:
    goto v_10826;
v_10827:
    goto v_10828;
v_10829:
    v_10849 = cons(v_10850, v_10849);
    env = stack[-4];
    v_10850 = Lreverse(nil, v_10849);
    env = stack[-4];
    goto v_10820;
v_10821:
    v_10849 = stack[-1];
    goto v_10822;
v_10823:
    goto v_10819;
v_10820:
    goto v_10821;
v_10822:
    v_10849 = Lappend(nil, v_10850, v_10849);
    goto v_10815;
v_10816:
    goto v_10812;
v_10813:
    goto v_10814;
v_10815:
    {
        LispObject v_10856 = stack[0];
        return cons(v_10856, v_10849);
    }
v_10798:
    goto v_10841;
v_10837:
    v_10849 = stack[-1];
    v_10850 = qcar(v_10849);
    goto v_10838;
v_10839:
    v_10849 = stack[-3];
    goto v_10840;
v_10841:
    goto v_10837;
v_10838:
    goto v_10839;
v_10840:
    v_10849 = cons(v_10850, v_10849);
    env = stack[-4];
    stack[-3] = v_10849;
    v_10849 = stack[-1];
    v_10849 = qcdr(v_10849);
    stack[-1] = v_10849;
    v_10849 = stack[0];
    v_10849 = (v_10849 == nil ? lisp_true : nil);
    stack[0] = v_10849;
    goto v_10766;
v_10766:
    goto v_10764;
v_10763:
    return onevalue(v_10849);
}



// Code for expt!-mod!-p

static LispObject CC_exptKmodKp(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_10834, v_10835, v_10836;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10757,v_10758);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_10836 = v_10758;
    stack[0] = v_10757;
// end of prologue
    goto v_10768;
v_10764:
    v_10835 = v_10836;
    goto v_10765;
v_10766:
    v_10834 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10767;
v_10768:
    goto v_10764;
v_10765:
    goto v_10766;
v_10767:
    if (v_10835 == v_10834) goto v_10762;
    else goto v_10763;
v_10762:
    v_10834 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10761;
v_10763:
    goto v_10778;
v_10774:
    v_10835 = v_10836;
    goto v_10775;
v_10776:
    v_10834 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10777;
v_10778:
    goto v_10774;
v_10775:
    goto v_10776;
v_10777:
    if (v_10835 == v_10834) goto v_10772;
    else goto v_10773;
v_10772:
    v_10834 = stack[0];
    goto v_10761;
v_10773:
    goto v_10793;
v_10789:
    v_10835 = v_10836;
    goto v_10790;
v_10791:
    v_10834 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10792;
v_10793:
    goto v_10789;
v_10790:
    goto v_10791;
v_10792:
    v_10834 = Ldivide(nil, v_10835, v_10834);
    env = stack[-2];
    stack[-1] = v_10834;
    goto v_10801;
v_10797:
    v_10835 = stack[0];
    goto v_10798;
v_10799:
    v_10834 = stack[-1];
    v_10834 = qcar(v_10834);
    goto v_10800;
v_10801:
    goto v_10797;
v_10798:
    goto v_10799;
v_10800:
    v_10834 = CC_exptKmodKp(elt(env, 0), v_10835, v_10834);
    env = stack[-2];
    v_10836 = v_10834;
    goto v_10810;
v_10806:
    v_10834 = v_10836;
    goto v_10807;
v_10808:
    v_10835 = v_10836;
    goto v_10809;
v_10810:
    goto v_10806;
v_10807:
    goto v_10808;
v_10809:
    fn = elt(env, 1); // times!-mod!-p
    v_10834 = (*qfn2(fn))(fn, v_10834, v_10835);
    env = stack[-2];
    v_10836 = v_10834;
    goto v_10821;
v_10817:
    v_10834 = stack[-1];
    v_10835 = qcdr(v_10834);
    goto v_10818;
v_10819:
    v_10834 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10820;
v_10821:
    goto v_10817;
v_10818:
    goto v_10819;
v_10820:
    if (v_10835 == v_10834) goto v_10816;
    goto v_10830;
v_10826:
    v_10835 = v_10836;
    goto v_10827;
v_10828:
    v_10834 = stack[0];
    goto v_10829;
v_10830:
    goto v_10826;
v_10827:
    goto v_10828;
v_10829:
    fn = elt(env, 1); // times!-mod!-p
    v_10834 = (*qfn2(fn))(fn, v_10835, v_10834);
    v_10836 = v_10834;
    goto v_10814;
v_10816:
v_10814:
    v_10834 = v_10836;
    goto v_10761;
    v_10834 = nil;
v_10761:
    return onevalue(v_10834);
}



// Code for prin_with_margin

static LispObject CC_prin_with_margin(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10781, v_10782;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_10781 = v_10757;
// end of prologue
    goto v_10768;
v_10760:
    stack[-1] = v_10781;
    goto v_10761;
v_10762:
    stack[0] = Lposn(nil, 0);
    env = stack[-2];
    goto v_10763;
v_10764:
    goto v_10776;
v_10772:
    v_10781 = nil;
    v_10782 = Llinelength(nil, v_10781);
    env = stack[-2];
    goto v_10773;
v_10774:
    v_10781 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10775;
v_10776:
    goto v_10772;
v_10773:
    goto v_10774;
v_10775:
    v_10782 = difference2(v_10782, v_10781);
    env = stack[-2];
    goto v_10765;
v_10766:
    v_10781 = elt(env, 1); // explode
    goto v_10767;
v_10768:
    goto v_10760;
v_10761:
    goto v_10762;
v_10763:
    goto v_10764;
v_10765:
    goto v_10766;
v_10767:
    {
        LispObject v_10785 = stack[-1];
        LispObject v_10786 = stack[0];
        fn = elt(env, 2); // print_with_margin_sub
        return (*qfnn(fn))(fn, 4, v_10785, v_10786, v_10782, v_10781);
    }
}



// Code for gcref_mkgraph

static LispObject CC_gcref_mkgraph(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10770, v_10771;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10771 = v_10757;
// end of prologue
    v_10770 = qvalue(elt(env, 1)); // !*gcrefudg
    if (v_10770 == nil) goto v_10762;
    v_10770 = v_10771;
    {
        fn = elt(env, 2); // gcref_mkgraph!-udg
        return (*qfn1(fn))(fn, v_10770);
    }
v_10762:
    v_10770 = v_10771;
    {
        fn = elt(env, 3); // gcref_mkgraph!-tgf
        return (*qfn1(fn))(fn, v_10770);
    }
    v_10770 = nil;
    return onevalue(v_10770);
}



// Code for sfto_varp

static LispObject CC_sfto_varp(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10822, v_10823;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10757;
// end of prologue
    v_10822 = stack[0];
    if (!consp(v_10822)) goto v_10769;
    else goto v_10770;
v_10769:
    v_10822 = lisp_true;
    goto v_10768;
v_10770:
    v_10822 = stack[0];
    v_10822 = qcar(v_10822);
    v_10822 = (consp(v_10822) ? nil : lisp_true);
    goto v_10768;
    v_10822 = nil;
v_10768:
    if (v_10822 == nil) goto v_10765;
    else goto v_10766;
v_10765:
    v_10822 = stack[0];
    v_10822 = qcdr(v_10822);
    if (v_10822 == nil) goto v_10780;
    else goto v_10781;
v_10780:
    goto v_10793;
v_10789:
    v_10822 = stack[0];
    v_10822 = qcar(v_10822);
    v_10823 = qcdr(v_10822);
    goto v_10790;
v_10791:
    v_10822 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10792;
v_10793:
    goto v_10789;
v_10790:
    goto v_10791;
v_10792:
    v_10822 = Leqn(nil, v_10823, v_10822);
    env = stack[-1];
    if (v_10822 == nil) goto v_10786;
    else goto v_10787;
v_10786:
    v_10822 = nil;
    goto v_10785;
v_10787:
    goto v_10806;
v_10802:
    v_10822 = stack[0];
    v_10822 = qcar(v_10822);
    v_10822 = qcar(v_10822);
    v_10823 = qcdr(v_10822);
    goto v_10803;
v_10804:
    v_10822 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10805;
v_10806:
    goto v_10802;
v_10803:
    goto v_10804;
v_10805:
    v_10822 = Leqn(nil, v_10823, v_10822);
    goto v_10785;
    v_10822 = nil;
v_10785:
    goto v_10779;
v_10781:
    v_10822 = nil;
    goto v_10779;
    v_10822 = nil;
v_10779:
    goto v_10764;
v_10766:
    v_10822 = nil;
    goto v_10764;
    v_10822 = nil;
v_10764:
    if (v_10822 == nil) goto v_10762;
    v_10822 = stack[0];
    v_10822 = qcar(v_10822);
    v_10822 = qcar(v_10822);
    v_10822 = qcar(v_10822);
    goto v_10760;
v_10762:
    v_10822 = nil;
v_10760:
    return onevalue(v_10822);
}



// Code for talp_rnf1

static LispObject CC_talp_rnf1(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_10894, v_10895, v_10896;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_10895 = v_10757;
// end of prologue
    v_10894 = v_10895;
    if (!consp(v_10894)) goto v_10764;
    else goto v_10765;
v_10764:
    v_10894 = v_10895;
    goto v_10761;
v_10765:
    goto v_10775;
v_10769:
    v_10896 = v_10895;
    goto v_10770;
v_10771:
    v_10895 = nil;
    goto v_10772;
v_10773:
    v_10894 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_10774;
v_10775:
    goto v_10769;
v_10770:
    goto v_10771;
v_10772:
    goto v_10773;
v_10774:
    fn = elt(env, 3); // cl_simpl
    v_10894 = (*qfnn(fn))(fn, 3, v_10896, v_10895, v_10894);
    env = stack[-5];
    stack[0] = v_10894;
    goto v_10791;
v_10787:
    v_10895 = stack[0];
    goto v_10788;
v_10789:
    v_10894 = elt(env, 1); // true
    goto v_10790;
v_10791:
    goto v_10787;
v_10788:
    goto v_10789;
v_10790:
    if (v_10895 == v_10894) goto v_10785;
    else goto v_10786;
v_10785:
    v_10894 = lisp_true;
    goto v_10784;
v_10786:
    goto v_10801;
v_10797:
    v_10895 = stack[0];
    goto v_10798;
v_10799:
    v_10894 = elt(env, 2); // false
    goto v_10800;
v_10801:
    goto v_10797;
v_10798:
    goto v_10799;
v_10800:
    v_10894 = (v_10895 == v_10894 ? lisp_true : nil);
    goto v_10784;
    v_10894 = nil;
v_10784:
    if (v_10894 == nil) goto v_10782;
    v_10894 = stack[0];
    goto v_10761;
v_10782:
    v_10894 = stack[0];
    fn = elt(env, 4); // talp_atfp
    v_10894 = (*qfn1(fn))(fn, v_10894);
    env = stack[-5];
    if (v_10894 == nil) goto v_10809;
    v_10894 = stack[0];
    fn = elt(env, 5); // talp_acfrp
    v_10894 = (*qfn1(fn))(fn, v_10894);
    env = stack[-5];
    if (v_10894 == nil) goto v_10815;
    goto v_10825;
v_10819:
    v_10894 = stack[0];
    fn = elt(env, 6); // talp_raf
    v_10896 = (*qfn1(fn))(fn, v_10894);
    env = stack[-5];
    goto v_10820;
v_10821:
    v_10895 = nil;
    goto v_10822;
v_10823:
    v_10894 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_10824;
v_10825:
    goto v_10819;
v_10820:
    goto v_10821;
v_10822:
    goto v_10823;
v_10824:
    {
        fn = elt(env, 3); // cl_simpl
        return (*qfnn(fn))(fn, 3, v_10896, v_10895, v_10894);
    }
v_10815:
    v_10894 = stack[0];
    goto v_10813;
    v_10894 = nil;
v_10813:
    goto v_10761;
v_10809:
    goto v_10840;
v_10834:
    goto v_10846;
v_10842:
    v_10894 = stack[0];
    fn = elt(env, 7); // talp_op
    stack[-4] = (*qfn1(fn))(fn, v_10894);
    env = stack[-5];
    goto v_10843;
v_10844:
    v_10894 = stack[0];
    fn = elt(env, 8); // talp_argl
    v_10894 = (*qfn1(fn))(fn, v_10894);
    env = stack[-5];
    stack[-3] = v_10894;
    v_10894 = stack[-3];
    if (v_10894 == nil) goto v_10859;
    else goto v_10860;
v_10859:
    v_10894 = nil;
    goto v_10853;
v_10860:
    v_10894 = stack[-3];
    v_10894 = qcar(v_10894);
    v_10894 = CC_talp_rnf1(elt(env, 0), v_10894);
    env = stack[-5];
    v_10894 = ncons(v_10894);
    env = stack[-5];
    stack[-1] = v_10894;
    stack[-2] = v_10894;
v_10854:
    v_10894 = stack[-3];
    v_10894 = qcdr(v_10894);
    stack[-3] = v_10894;
    v_10894 = stack[-3];
    if (v_10894 == nil) goto v_10873;
    else goto v_10874;
v_10873:
    v_10894 = stack[-2];
    goto v_10853;
v_10874:
    goto v_10882;
v_10878:
    stack[0] = stack[-1];
    goto v_10879;
v_10880:
    v_10894 = stack[-3];
    v_10894 = qcar(v_10894);
    v_10894 = CC_talp_rnf1(elt(env, 0), v_10894);
    env = stack[-5];
    v_10894 = ncons(v_10894);
    env = stack[-5];
    goto v_10881;
v_10882:
    goto v_10878;
v_10879:
    goto v_10880;
v_10881:
    v_10894 = Lrplacd(nil, stack[0], v_10894);
    env = stack[-5];
    v_10894 = stack[-1];
    v_10894 = qcdr(v_10894);
    stack[-1] = v_10894;
    goto v_10854;
v_10853:
    goto v_10845;
v_10846:
    goto v_10842;
v_10843:
    goto v_10844;
v_10845:
    v_10896 = cons(stack[-4], v_10894);
    env = stack[-5];
    goto v_10835;
v_10836:
    v_10895 = nil;
    goto v_10837;
v_10838:
    v_10894 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_10839;
v_10840:
    goto v_10834;
v_10835:
    goto v_10836;
v_10837:
    goto v_10838;
v_10839:
    {
        fn = elt(env, 3); // cl_simpl
        return (*qfnn(fn))(fn, 3, v_10896, v_10895, v_10894);
    }
v_10761:
    return onevalue(v_10894);
}



// Code for ibalp_renewwl

static LispObject CC_ibalp_renewwl(LispObject env,
                         LispObject v_10757)
{
    env = qenv(env);
    LispObject v_11081, v_11082;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10757);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_11081 = v_10757;
// end of prologue
    stack[-2] = v_11081;
v_10765:
    v_11081 = stack[-2];
    if (v_11081 == nil) goto v_10769;
    else goto v_10770;
v_10769:
    goto v_10764;
v_10770:
    v_11081 = stack[-2];
    v_11081 = qcar(v_11081);
    stack[-1] = v_11081;
    v_11081 = stack[-1];
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcar(v_11081);
    if (v_11081 == nil) goto v_10778;
    else goto v_10779;
v_10778:
    goto v_10796;
v_10792:
    v_11081 = stack[-1];
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcar(v_11081);
    v_11082 = Llength(nil, v_11081);
    env = stack[-4];
    goto v_10793;
v_10794:
    v_11081 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10795;
v_10796:
    goto v_10792;
v_10793:
    goto v_10794;
v_10795:
    v_11081 = Leqn(nil, v_11082, v_11081);
    env = stack[-4];
    if (v_11081 == nil) goto v_10789;
    goto v_10813;
v_10809:
    goto v_10819;
v_10815:
    v_11081 = stack[-1];
    v_11081 = qcar(v_11081);
    stack[0] = Llength(nil, v_11081);
    env = stack[-4];
    goto v_10816;
v_10817:
    v_11081 = stack[-1];
    v_11081 = qcdr(v_11081);
    v_11081 = qcar(v_11081);
    v_11081 = Llength(nil, v_11081);
    env = stack[-4];
    goto v_10818;
v_10819:
    goto v_10815;
v_10816:
    goto v_10817;
v_10818:
    v_11082 = plus2(stack[0], v_11081);
    env = stack[-4];
    goto v_10810;
v_10811:
    v_11081 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10812;
v_10813:
    goto v_10809;
v_10810:
    goto v_10811;
v_10812:
    v_11081 = (LispObject)greaterp2(v_11082, v_11081);
    v_11081 = v_11081 ? lisp_true : nil;
    env = stack[-4];
    if (v_11081 == nil) goto v_10789;
    v_11081 = stack[-1];
    fn = elt(env, 1); // ibalp_getnewwl
    v_11081 = (*qfn1(fn))(fn, v_11081);
    env = stack[-4];
    stack[-3] = v_11081;
    v_11081 = stack[-3];
    if (v_11081 == nil) goto v_10833;
    goto v_10840;
v_10836:
    v_11081 = stack[-1];
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    stack[0] = qcdr(v_11081);
    goto v_10837;
v_10838:
    goto v_10853;
v_10849:
    v_11082 = stack[-3];
    goto v_10850;
v_10851:
    v_11081 = stack[-1];
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcar(v_11081);
    goto v_10852;
v_10853:
    goto v_10849;
v_10850:
    goto v_10851;
v_10852:
    v_11081 = cons(v_11082, v_11081);
    env = stack[-4];
    goto v_10839;
v_10840:
    goto v_10836;
v_10837:
    goto v_10838;
v_10839:
    fn = elt(env, 2); // setcar
    v_11081 = (*qfn2(fn))(fn, stack[0], v_11081);
    env = stack[-4];
    goto v_10868;
v_10864:
    v_11081 = stack[-3];
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    stack[0] = qcdr(v_11081);
    goto v_10865;
v_10866:
    goto v_10885;
v_10881:
    v_11082 = stack[-1];
    goto v_10882;
v_10883:
    v_11081 = stack[-3];
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcar(v_11081);
    goto v_10884;
v_10885:
    goto v_10881;
v_10882:
    goto v_10883;
v_10884:
    v_11081 = cons(v_11082, v_11081);
    env = stack[-4];
    goto v_10867;
v_10868:
    goto v_10864;
v_10865:
    goto v_10866;
v_10867:
    fn = elt(env, 2); // setcar
    v_11081 = (*qfn2(fn))(fn, stack[0], v_11081);
    env = stack[-4];
    goto v_10831;
v_10833:
v_10831:
    goto v_10787;
v_10789:
    v_11081 = stack[-1];
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcar(v_11081);
    if (v_11081 == nil) goto v_10904;
    else goto v_10905;
v_10904:
    goto v_10919;
v_10915:
    goto v_10925;
v_10921:
    v_11081 = stack[-1];
    v_11081 = qcar(v_11081);
    stack[0] = Llength(nil, v_11081);
    env = stack[-4];
    goto v_10922;
v_10923:
    v_11081 = stack[-1];
    v_11081 = qcdr(v_11081);
    v_11081 = qcar(v_11081);
    v_11081 = Llength(nil, v_11081);
    env = stack[-4];
    goto v_10924;
v_10925:
    goto v_10921;
v_10922:
    goto v_10923;
v_10924:
    v_11082 = plus2(stack[0], v_11081);
    env = stack[-4];
    goto v_10916;
v_10917:
    v_11081 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10918;
v_10919:
    goto v_10915;
v_10916:
    goto v_10917;
v_10918:
    v_11081 = (LispObject)greaterp2(v_11082, v_11081);
    v_11081 = v_11081 ? lisp_true : nil;
    env = stack[-4];
    goto v_10903;
v_10905:
    v_11081 = nil;
    goto v_10903;
    v_11081 = nil;
v_10903:
    if (v_11081 == nil) goto v_10901;
    v_11081 = stack[-1];
    fn = elt(env, 1); // ibalp_getnewwl
    v_11081 = (*qfn1(fn))(fn, v_11081);
    env = stack[-4];
    stack[-3] = v_11081;
    v_11081 = stack[-3];
    if (v_11081 == nil) goto v_10942;
    goto v_10949;
v_10945:
    v_11081 = stack[-1];
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    stack[0] = qcdr(v_11081);
    goto v_10946;
v_10947:
    goto v_10962;
v_10958:
    v_11082 = stack[-3];
    goto v_10959;
v_10960:
    v_11081 = stack[-1];
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcar(v_11081);
    goto v_10961;
v_10962:
    goto v_10958;
v_10959:
    goto v_10960;
v_10961:
    v_11081 = cons(v_11082, v_11081);
    env = stack[-4];
    goto v_10948;
v_10949:
    goto v_10945;
v_10946:
    goto v_10947;
v_10948:
    fn = elt(env, 2); // setcar
    v_11081 = (*qfn2(fn))(fn, stack[0], v_11081);
    env = stack[-4];
    goto v_10977;
v_10973:
    v_11081 = stack[-3];
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    stack[0] = qcdr(v_11081);
    goto v_10974;
v_10975:
    goto v_10994;
v_10990:
    v_11082 = stack[-1];
    goto v_10991;
v_10992:
    v_11081 = stack[-3];
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcar(v_11081);
    goto v_10993;
v_10994:
    goto v_10990;
v_10991:
    goto v_10992;
v_10993:
    v_11081 = cons(v_11082, v_11081);
    env = stack[-4];
    goto v_10976;
v_10977:
    goto v_10973;
v_10974:
    goto v_10975;
v_10976:
    fn = elt(env, 2); // setcar
    v_11081 = (*qfn2(fn))(fn, stack[0], v_11081);
    env = stack[-4];
    goto v_10940;
v_10942:
v_10940:
    v_11081 = stack[-1];
    fn = elt(env, 1); // ibalp_getnewwl
    v_11081 = (*qfn1(fn))(fn, v_11081);
    env = stack[-4];
    stack[-3] = v_11081;
    v_11081 = stack[-3];
    if (v_11081 == nil) goto v_11013;
    goto v_11020;
v_11016:
    v_11081 = stack[-1];
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    stack[0] = qcdr(v_11081);
    goto v_11017;
v_11018:
    goto v_11033;
v_11029:
    v_11082 = stack[-3];
    goto v_11030;
v_11031:
    v_11081 = stack[-1];
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcar(v_11081);
    goto v_11032;
v_11033:
    goto v_11029;
v_11030:
    goto v_11031;
v_11032:
    v_11081 = cons(v_11082, v_11081);
    env = stack[-4];
    goto v_11019;
v_11020:
    goto v_11016;
v_11017:
    goto v_11018;
v_11019:
    fn = elt(env, 2); // setcar
    v_11081 = (*qfn2(fn))(fn, stack[0], v_11081);
    env = stack[-4];
    goto v_11048;
v_11044:
    v_11081 = stack[-3];
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    stack[0] = qcdr(v_11081);
    goto v_11045;
v_11046:
    goto v_11065;
v_11061:
    v_11082 = stack[-1];
    goto v_11062;
v_11063:
    v_11081 = stack[-3];
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcdr(v_11081);
    v_11081 = qcar(v_11081);
    goto v_11064;
v_11065:
    goto v_11061;
v_11062:
    goto v_11063;
v_11064:
    v_11081 = cons(v_11082, v_11081);
    env = stack[-4];
    goto v_11047;
v_11048:
    goto v_11044;
v_11045:
    goto v_11046;
v_11047:
    fn = elt(env, 2); // setcar
    v_11081 = (*qfn2(fn))(fn, stack[0], v_11081);
    env = stack[-4];
    goto v_11011;
v_11013:
v_11011:
    goto v_10787;
v_10901:
v_10787:
    goto v_10777;
v_10779:
v_10777:
    v_11081 = stack[-2];
    v_11081 = qcdr(v_11081);
    stack[-2] = v_11081;
    goto v_10765;
v_10764:
    v_11081 = nil;
    return onevalue(v_11081);
}



// Code for binomial!-coefft!-mod!-p

static LispObject CC_binomialKcoefftKmodKp(LispObject env,
                         LispObject v_10757, LispObject v_10758)
{
    env = qenv(env);
    LispObject v_10876, v_10877, v_10878, v_10879, v_10880;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10758,v_10757);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10757,v_10758);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_10758;
    stack[-2] = v_10757;
// end of prologue
    goto v_10769;
v_10765:
    v_10877 = stack[-2];
    goto v_10766;
v_10767:
    v_10876 = stack[-1];
    goto v_10768;
v_10769:
    goto v_10765;
v_10766:
    goto v_10767;
v_10768:
    v_10876 = (LispObject)lessp2(v_10877, v_10876);
    v_10876 = v_10876 ? lisp_true : nil;
    env = stack[-4];
    if (v_10876 == nil) goto v_10763;
    v_10876 = nil;
    goto v_10761;
v_10763:
    goto v_10779;
v_10775:
    v_10877 = stack[-2];
    goto v_10776;
v_10777:
    v_10876 = stack[-1];
    goto v_10778;
v_10779:
    goto v_10775;
v_10776:
    goto v_10777;
v_10778:
    if (equal(v_10877, v_10876)) goto v_10773;
    else goto v_10774;
v_10773:
    v_10876 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10761;
v_10774:
    goto v_10789;
v_10785:
    v_10877 = stack[-1];
    goto v_10786;
v_10787:
    v_10876 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10788;
v_10789:
    goto v_10785;
v_10786:
    goto v_10787;
v_10788:
    if (v_10877 == v_10876) goto v_10783;
    else goto v_10784;
v_10783:
    v_10876 = stack[-2];
    v_10876 = Lmodular_number(nil, v_10876);
    env = stack[-4];
    {
        fn = elt(env, 1); // !*n2f
        return (*qfn1(fn))(fn, v_10876);
    }
v_10784:
    v_10876 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_10876;
    goto v_10808;
v_10804:
    stack[0] = stack[-1];
    goto v_10805;
v_10806:
    goto v_10815;
v_10811:
    v_10877 = stack[-2];
    goto v_10812;
v_10813:
    v_10876 = stack[-1];
    goto v_10814;
v_10815:
    goto v_10811;
v_10812:
    goto v_10813;
v_10814:
    v_10876 = difference2(v_10877, v_10876);
    env = stack[-4];
    goto v_10807;
v_10808:
    goto v_10804;
v_10805:
    goto v_10806;
v_10807:
    fn = elt(env, 2); // min
    v_10876 = (*qfn2(fn))(fn, stack[0], v_10876);
    env = stack[-4];
    stack[0] = v_10876;
    v_10876 = stack[-2];
    v_10876 = Lmodular_number(nil, v_10876);
    env = stack[-4];
    stack[-2] = v_10876;
    v_10876 = stack[-1];
    v_10876 = Lmodular_number(nil, v_10876);
    env = stack[-4];
    v_10876 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_10876;
v_10825:
    goto v_10837;
v_10833:
    v_10877 = stack[0];
    goto v_10834;
v_10835:
    v_10876 = stack[-1];
    goto v_10836;
v_10837:
    goto v_10833;
v_10834:
    goto v_10835;
v_10836:
    v_10876 = difference2(v_10877, v_10876);
    env = stack[-4];
    v_10876 = Lminusp(nil, v_10876);
    env = stack[-4];
    if (v_10876 == nil) goto v_10830;
    goto v_10824;
v_10830:
    v_10876 = stack[-1];
    v_10876 = Lmodular_number(nil, v_10876);
    env = stack[-4];
    v_10880 = v_10876;
    goto v_10848;
v_10844:
    goto v_10854;
v_10850:
    v_10879 = stack[-3];
    goto v_10851;
v_10852:
    goto v_10860;
v_10856:
    v_10878 = stack[-2];
    goto v_10857;
v_10858:
    goto v_10866;
v_10862:
    v_10877 = v_10880;
    goto v_10863;
v_10864:
    v_10876 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10865;
v_10866:
    goto v_10862;
v_10863:
    goto v_10864;
v_10865:
    {   intptr_t w = int_of_fixnum(v_10877) - int_of_fixnum(v_10876);
        if (w < 0) w += current_modulus;
        v_10876 = fixnum_of_int(w);
    }
    goto v_10859;
v_10860:
    goto v_10856;
v_10857:
    goto v_10858;
v_10859:
    {   intptr_t w = int_of_fixnum(v_10878) - int_of_fixnum(v_10876);
        if (w < 0) w += current_modulus;
        v_10876 = fixnum_of_int(w);
    }
    goto v_10853;
v_10854:
    goto v_10850;
v_10851:
    goto v_10852;
v_10853:
    v_10876 = Lmodular_times(nil, v_10879, v_10876);
    env = stack[-4];
    goto v_10845;
v_10846:
    v_10877 = v_10880;
    goto v_10847;
v_10848:
    goto v_10844;
v_10845:
    goto v_10846;
v_10847:
    v_10876 = Lmodular_quotient(nil, v_10876, v_10877);
    env = stack[-4];
    stack[-3] = v_10876;
    v_10876 = stack[-1];
    v_10876 = add1(v_10876);
    env = stack[-4];
    stack[-1] = v_10876;
    goto v_10825;
v_10824:
    v_10876 = stack[-3];
    {
        fn = elt(env, 1); // !*n2f
        return (*qfn1(fn))(fn, v_10876);
    }
    goto v_10761;
    v_10876 = nil;
v_10761:
    return onevalue(v_10876);
}



setup_type const u19_setup[] =
{
    {"ibalp_process-var",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ibalp_processKvar},
    {"aex_simpleratp",          CC_aex_simpleratp,TOO_MANY_1,  WRONG_NO_1},
    {"exptpri",                 TOO_FEW_2,      CC_exptpri,    WRONG_NO_2},
    {"tobvarir",                CC_tobvarir,    TOO_MANY_1,    WRONG_NO_1},
    {"floatprop",               CC_floatprop,   TOO_MANY_1,    WRONG_NO_1},
    {"inttovec",                TOO_FEW_2,      CC_inttovec,   WRONG_NO_2},
    {"physopaeval",             CC_physopaeval, TOO_MANY_1,    WRONG_NO_1},
    {"mkarray1",                TOO_FEW_2,      CC_mkarray1,   WRONG_NO_2},
    {"mo_from_a",               CC_mo_from_a,   TOO_MANY_1,    WRONG_NO_1},
    {"idcons_ordp",             TOO_FEW_2,      CC_idcons_ordp,WRONG_NO_2},
    {"general-expt-mod-p",      TOO_FEW_2,      CC_generalKexptKmodKp,WRONG_NO_2},
    {":expt",                   TOO_FEW_2,      CC_Texpt,      WRONG_NO_2},
    {"lex_start_line_comment",  CC_lex_start_line_comment,TOO_MANY_1,WRONG_NO_1},
    {"formcond",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formcond},
    {"ofsf_entry2at",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_entry2at},
    {"ofsf_smmkatl1",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smmkatl1},
    {"rl_atl",                  CC_rl_atl,      TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_readclause",        TOO_FEW_2,      CC_ibalp_readclause,WRONG_NO_2},
    {"powers4",                 TOO_FEW_2,      CC_powers4,    WRONG_NO_2},
    {"om2mml",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_om2mml},
    {"*wedgepf2pf",             CC_Hwedgepf2pf, TOO_MANY_1,    WRONG_NO_1},
    {"delete-dups",             CC_deleteKdups, TOO_MANY_1,    WRONG_NO_1},
    {"scal*list",               TOO_FEW_2,      CC_scalHlist,  WRONG_NO_2},
    {"physop-ordop",            TOO_FEW_2,      CC_physopKordop,WRONG_NO_2},
    {"zero-roads",              CC_zeroKroads,  TOO_MANY_1,    WRONG_NO_1},
    {"revalx",                  CC_revalx,      TOO_MANY_1,    WRONG_NO_1},
    {"di_restore",              CC_di_restore,  TOO_MANY_1,    WRONG_NO_1},
    {"general-reduce-mod-p",    CC_generalKreduceKmodKp,TOO_MANY_1,WRONG_NO_1},
    {"lex_save_context",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex_save_context},
    {"monomdivide",             TOO_FEW_2,      CC_monomdivide,WRONG_NO_2},
    {"sfto_ucontentf1",         TOO_FEW_2,      CC_sfto_ucontentf1,WRONG_NO_2},
    {"simpg3",                  CC_simpg3,      TOO_MANY_1,    WRONG_NO_1},
    {"findnthroot",             CC_findnthroot, TOO_MANY_1,    WRONG_NO_1},
    {"prepsq*",                 CC_prepsqH,     TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_recalcv",           CC_ibalp_recalcv,TOO_MANY_1,   WRONG_NO_1},
    {"mvar_member",             TOO_FEW_2,      CC_mvar_member,WRONG_NO_2},
    {"variablesir",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_variablesir},
    {"evmtest?",                TOO_FEW_2,      CC_evmtestW,   WRONG_NO_2},
    {"xord_deglex",             TOO_FEW_2,      CC_xord_deglex,WRONG_NO_2},
    {"invp",                    CC_invp,        TOO_MANY_1,    WRONG_NO_1},
    {"contr",                   TOO_FEW_2,      CC_contr,      WRONG_NO_2},
    {"repasc",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_repasc},
    {"addgt",                   CC_addgt,       TOO_MANY_1,    WRONG_NO_1},
    {"il_simp",                 CC_il_simp,     TOO_MANY_1,    WRONG_NO_1},
    {"ordexn",                  TOO_FEW_2,      CC_ordexn,     WRONG_NO_2},
    {"expt-mod-p",              TOO_FEW_2,      CC_exptKmodKp, WRONG_NO_2},
    {"prin_with_margin",        CC_prin_with_margin,TOO_MANY_1,WRONG_NO_1},
    {"gcref_mkgraph",           CC_gcref_mkgraph,TOO_MANY_1,   WRONG_NO_1},
    {"sfto_varp",               CC_sfto_varp,   TOO_MANY_1,    WRONG_NO_1},
    {"talp_rnf1",               CC_talp_rnf1,   TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_renewwl",           CC_ibalp_renewwl,TOO_MANY_1,   WRONG_NO_1},
    {"binomial-coefft-mod-p",   TOO_FEW_2,      CC_binomialKcoefftKmodKp,WRONG_NO_2},
    {NULL, (one_args *)"u19", (two_args *)"28001 9869325 29998", 0}
};

// end of generated code
