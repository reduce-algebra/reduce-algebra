
// $destdir/u08.c        Machine generated C code

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



// Code for general!-plus!-mod!-p

static LispObject CC_generalKplusKmodKp(LispObject env,
                         LispObject v_3565, LispObject v_3566)
{
    env = qenv(env);
    LispObject v_3838, v_3839, v_3840;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3565,v_3566);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_3566;
    stack[-2] = v_3565;
// end of prologue
    stack[0] = nil;
v_3571:
    v_3838 = stack[-2];
    if (v_3838 == nil) goto v_3574;
    else goto v_3575;
v_3574:
    goto v_3582;
v_3578:
    v_3839 = stack[0];
    goto v_3579;
v_3580:
    v_3838 = stack[-1];
    goto v_3581;
v_3582:
    goto v_3578;
v_3579:
    goto v_3580;
v_3581:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_3839, v_3838);
    }
v_3575:
    v_3838 = stack[-1];
    if (v_3838 == nil) goto v_3585;
    else goto v_3586;
v_3585:
    goto v_3593;
v_3589:
    v_3839 = stack[0];
    goto v_3590;
v_3591:
    v_3838 = stack[-2];
    goto v_3592;
v_3593:
    goto v_3589;
v_3590:
    goto v_3591;
v_3592:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_3839, v_3838);
    }
v_3586:
    v_3838 = stack[-2];
    if (!consp(v_3838)) goto v_3600;
    else goto v_3601;
v_3600:
    v_3838 = lisp_true;
    goto v_3599;
v_3601:
    v_3838 = stack[-2];
    v_3838 = qcar(v_3838);
    v_3838 = (consp(v_3838) ? nil : lisp_true);
    goto v_3599;
    v_3838 = nil;
v_3599:
    if (v_3838 == nil) goto v_3597;
    v_3838 = stack[-1];
    if (!consp(v_3838)) goto v_3615;
    else goto v_3616;
v_3615:
    v_3838 = lisp_true;
    goto v_3614;
v_3616:
    v_3838 = stack[-1];
    v_3838 = qcar(v_3838);
    v_3838 = (consp(v_3838) ? nil : lisp_true);
    goto v_3614;
    v_3838 = nil;
v_3614:
    if (v_3838 == nil) goto v_3612;
    goto v_3629;
v_3625:
    goto v_3626;
v_3627:
    goto v_3637;
v_3633:
    v_3839 = stack[-2];
    goto v_3634;
v_3635:
    v_3838 = stack[-1];
    goto v_3636;
v_3637:
    goto v_3633;
v_3634:
    goto v_3635;
v_3636:
    fn = elt(env, 2); // general!-modular!-plus
    v_3838 = (*qfn2(fn))(fn, v_3839, v_3838);
    env = stack[-4];
    fn = elt(env, 3); // !*n2f
    v_3838 = (*qfn1(fn))(fn, v_3838);
    env = stack[-4];
    goto v_3628;
v_3629:
    goto v_3625;
v_3626:
    goto v_3627;
v_3628:
    {
        LispObject v_3845 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_3845, v_3838);
    }
v_3612:
    goto v_3647;
v_3643:
    v_3838 = stack[-1];
    v_3839 = qcar(v_3838);
    goto v_3644;
v_3645:
    v_3838 = stack[0];
    goto v_3646;
v_3647:
    goto v_3643;
v_3644:
    goto v_3645;
v_3646:
    v_3838 = cons(v_3839, v_3838);
    env = stack[-4];
    stack[0] = v_3838;
    v_3838 = stack[-1];
    v_3838 = qcdr(v_3838);
    stack[-1] = v_3838;
    goto v_3571;
    goto v_3573;
v_3597:
    v_3838 = stack[-1];
    if (!consp(v_3838)) goto v_3657;
    else goto v_3658;
v_3657:
    v_3838 = lisp_true;
    goto v_3656;
v_3658:
    v_3838 = stack[-1];
    v_3838 = qcar(v_3838);
    v_3838 = (consp(v_3838) ? nil : lisp_true);
    goto v_3656;
    v_3838 = nil;
v_3656:
    if (v_3838 == nil) goto v_3654;
    goto v_3671;
v_3667:
    v_3838 = stack[-2];
    v_3839 = qcar(v_3838);
    goto v_3668;
v_3669:
    v_3838 = stack[0];
    goto v_3670;
v_3671:
    goto v_3667;
v_3668:
    goto v_3669;
v_3670:
    v_3838 = cons(v_3839, v_3838);
    env = stack[-4];
    stack[0] = v_3838;
    v_3838 = stack[-2];
    v_3838 = qcdr(v_3838);
    stack[-2] = v_3838;
    goto v_3571;
v_3654:
    goto v_3683;
v_3679:
    v_3838 = stack[-2];
    v_3838 = qcar(v_3838);
    v_3839 = qcar(v_3838);
    goto v_3680;
v_3681:
    v_3838 = stack[-1];
    v_3838 = qcar(v_3838);
    v_3838 = qcar(v_3838);
    goto v_3682;
v_3683:
    goto v_3679;
v_3680:
    goto v_3681;
v_3682:
    if (equal(v_3839, v_3838)) goto v_3677;
    else goto v_3678;
v_3677:
    goto v_3695;
v_3691:
    stack[-3] = stack[0];
    goto v_3692;
v_3693:
    goto v_3702;
v_3698:
    v_3838 = stack[-2];
    v_3838 = qcar(v_3838);
    v_3839 = qcdr(v_3838);
    goto v_3699;
v_3700:
    v_3838 = stack[-1];
    v_3838 = qcar(v_3838);
    v_3838 = qcdr(v_3838);
    goto v_3701;
v_3702:
    goto v_3698;
v_3699:
    goto v_3700;
v_3701:
    stack[0] = CC_generalKplusKmodKp(elt(env, 0), v_3839, v_3838);
    env = stack[-4];
    goto v_3714;
v_3710:
    v_3838 = stack[-2];
    v_3839 = qcdr(v_3838);
    goto v_3711;
v_3712:
    v_3838 = stack[-1];
    v_3838 = qcdr(v_3838);
    goto v_3713;
v_3714:
    goto v_3710;
v_3711:
    goto v_3712;
v_3713:
    v_3838 = CC_generalKplusKmodKp(elt(env, 0), v_3839, v_3838);
    env = stack[-4];
    v_3839 = stack[0];
    v_3840 = v_3839;
    if (v_3840 == nil) goto v_3723;
    else goto v_3724;
v_3723:
    goto v_3722;
v_3724:
    goto v_3736;
v_3730:
    v_3840 = stack[-2];
    v_3840 = qcar(v_3840);
    v_3840 = qcar(v_3840);
    goto v_3731;
v_3732:
    goto v_3733;
v_3734:
    goto v_3735;
v_3736:
    goto v_3730;
v_3731:
    goto v_3732;
v_3733:
    goto v_3734;
v_3735:
    v_3838 = acons(v_3840, v_3839, v_3838);
    env = stack[-4];
    goto v_3722;
    v_3838 = nil;
v_3722:
    goto v_3694;
v_3695:
    goto v_3691;
v_3692:
    goto v_3693;
v_3694:
    {
        LispObject v_3846 = stack[-3];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_3846, v_3838);
    }
v_3678:
    goto v_3753;
v_3749:
    v_3838 = stack[-2];
    v_3838 = qcar(v_3838);
    v_3838 = qcar(v_3838);
    v_3839 = qcar(v_3838);
    goto v_3750;
v_3751:
    v_3838 = stack[-1];
    v_3838 = qcar(v_3838);
    v_3838 = qcar(v_3838);
    v_3838 = qcar(v_3838);
    goto v_3752;
v_3753:
    goto v_3749;
v_3750:
    goto v_3751;
v_3752:
    if (equal(v_3839, v_3838)) goto v_3747;
    else goto v_3748;
v_3747:
    goto v_3766;
v_3762:
    v_3838 = stack[-2];
    v_3838 = qcar(v_3838);
    v_3838 = qcar(v_3838);
    v_3839 = qcdr(v_3838);
    goto v_3763;
v_3764:
    v_3838 = stack[-1];
    v_3838 = qcar(v_3838);
    v_3838 = qcar(v_3838);
    v_3838 = qcdr(v_3838);
    goto v_3765;
v_3766:
    goto v_3762;
v_3763:
    goto v_3764;
v_3765:
    v_3838 = ((intptr_t)v_3839 > (intptr_t)v_3838) ? lisp_true : nil;
    goto v_3746;
v_3748:
    v_3838 = nil;
    goto v_3746;
    v_3838 = nil;
v_3746:
    if (v_3838 == nil) goto v_3744;
    else goto v_3742;
v_3744:
    goto v_3788;
v_3784:
    v_3838 = stack[-2];
    v_3838 = qcar(v_3838);
    v_3838 = qcar(v_3838);
    v_3839 = qcar(v_3838);
    goto v_3785;
v_3786:
    v_3838 = stack[-1];
    v_3838 = qcar(v_3838);
    v_3838 = qcar(v_3838);
    v_3838 = qcar(v_3838);
    goto v_3787;
v_3788:
    goto v_3784;
v_3785:
    goto v_3786;
v_3787:
    if (equal(v_3839, v_3838)) goto v_3783;
    goto v_3802;
v_3798:
    v_3838 = stack[-2];
    v_3838 = qcar(v_3838);
    v_3838 = qcar(v_3838);
    v_3839 = qcar(v_3838);
    goto v_3799;
v_3800:
    v_3838 = stack[-1];
    v_3838 = qcar(v_3838);
    v_3838 = qcar(v_3838);
    v_3838 = qcar(v_3838);
    goto v_3801;
v_3802:
    goto v_3798;
v_3799:
    goto v_3800;
v_3801:
    fn = elt(env, 4); // ordop
    v_3838 = (*qfn2(fn))(fn, v_3839, v_3838);
    env = stack[-4];
    goto v_3781;
v_3783:
    v_3838 = nil;
    goto v_3781;
    v_3838 = nil;
v_3781:
    if (v_3838 == nil) goto v_3779;
    else goto v_3742;
v_3779:
    goto v_3743;
v_3742:
    goto v_3819;
v_3815:
    v_3838 = stack[-2];
    v_3839 = qcar(v_3838);
    goto v_3816;
v_3817:
    v_3838 = stack[0];
    goto v_3818;
v_3819:
    goto v_3815;
v_3816:
    goto v_3817;
v_3818:
    v_3838 = cons(v_3839, v_3838);
    env = stack[-4];
    stack[0] = v_3838;
    v_3838 = stack[-2];
    v_3838 = qcdr(v_3838);
    stack[-2] = v_3838;
    goto v_3571;
v_3743:
    goto v_3832;
v_3828:
    v_3838 = stack[-1];
    v_3839 = qcar(v_3838);
    goto v_3829;
v_3830:
    v_3838 = stack[0];
    goto v_3831;
v_3832:
    goto v_3828;
v_3829:
    goto v_3830;
v_3831:
    v_3838 = cons(v_3839, v_3838);
    env = stack[-4];
    stack[0] = v_3838;
    v_3838 = stack[-1];
    v_3838 = qcdr(v_3838);
    stack[-1] = v_3838;
    goto v_3571;
v_3573:
    v_3838 = nil;
    return onevalue(v_3838);
}



// Code for divide!:

static LispObject CC_divideT(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3632, v_3633;
    LispObject fn;
    LispObject v_3567, v_3566, v_3565;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "divide:");
    va_start(aa, nargs);
    v_3565 = va_arg(aa, LispObject);
    v_3566 = va_arg(aa, LispObject);
    v_3567 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_3567,v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_3565,v_3566,v_3567);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_3567;
    stack[-2] = v_3566;
    stack[-3] = v_3565;
// end of prologue
    goto v_3576;
v_3572:
    goto v_3573;
v_3574:
    goto v_3583;
v_3579:
    stack[0] = stack[-1];
    goto v_3580;
v_3581:
    v_3632 = stack[-2];
    v_3632 = qcdr(v_3632);
    v_3632 = qcar(v_3632);
    v_3632 = Labsval(nil, v_3632);
    env = stack[-5];
    fn = elt(env, 2); // msd
    v_3632 = (*qfn1(fn))(fn, v_3632);
    env = stack[-5];
    v_3632 = add1(v_3632);
    env = stack[-5];
    goto v_3582;
v_3583:
    goto v_3579;
v_3580:
    goto v_3581;
v_3582:
    v_3632 = plus2(stack[0], v_3632);
    env = stack[-5];
    goto v_3575;
v_3576:
    goto v_3572;
v_3573:
    goto v_3574;
v_3575:
    fn = elt(env, 3); // conv!:mt
    v_3632 = (*qfn2(fn))(fn, stack[-3], v_3632);
    env = stack[-5];
    stack[-3] = v_3632;
    goto v_3598;
v_3592:
    stack[-4] = elt(env, 1); // !:rd!:
    goto v_3593;
v_3594:
    goto v_3605;
v_3601:
    v_3632 = stack[-3];
    v_3632 = qcdr(v_3632);
    v_3633 = qcar(v_3632);
    goto v_3602;
v_3603:
    v_3632 = stack[-2];
    v_3632 = qcdr(v_3632);
    v_3632 = qcar(v_3632);
    goto v_3604;
v_3605:
    goto v_3601;
v_3602:
    goto v_3603;
v_3604:
    stack[0] = quot2(v_3633, v_3632);
    env = stack[-5];
    goto v_3595;
v_3596:
    goto v_3617;
v_3613:
    v_3632 = stack[-3];
    v_3632 = qcdr(v_3632);
    v_3633 = qcdr(v_3632);
    goto v_3614;
v_3615:
    v_3632 = stack[-2];
    v_3632 = qcdr(v_3632);
    v_3632 = qcdr(v_3632);
    goto v_3616;
v_3617:
    goto v_3613;
v_3614:
    goto v_3615;
v_3616:
    v_3632 = difference2(v_3633, v_3632);
    env = stack[-5];
    goto v_3597;
v_3598:
    goto v_3592;
v_3593:
    goto v_3594;
v_3595:
    goto v_3596;
v_3597:
    v_3632 = list2star(stack[-4], stack[0], v_3632);
    env = stack[-5];
    stack[-3] = v_3632;
    goto v_3629;
v_3625:
    v_3633 = stack[-3];
    goto v_3626;
v_3627:
    v_3632 = stack[-1];
    goto v_3628;
v_3629:
    goto v_3625;
v_3626:
    goto v_3627;
v_3628:
    {
        fn = elt(env, 4); // round!:mt
        return (*qfn2(fn))(fn, v_3633, v_3632);
    }
    return onevalue(v_3632);
}



// Code for mcharg2

static LispObject CC_mcharg2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3701, v_3702, v_3703;
    LispObject fn;
    LispObject v_3568, v_3567, v_3566, v_3565;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "mcharg2");
    va_start(aa, nargs);
    v_3565 = va_arg(aa, LispObject);
    v_3566 = va_arg(aa, LispObject);
    v_3567 = va_arg(aa, LispObject);
    v_3568 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_3568,v_3567,v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_3565,v_3566,v_3567,v_3568);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-6] = v_3568;
    stack[-7] = v_3567;
    stack[-8] = v_3566;
    stack[-9] = v_3565;
// end of prologue
    v_3701 = stack[-9];
    if (v_3701 == nil) goto v_3575;
    else goto v_3576;
v_3575:
    v_3701 = stack[-7];
    goto v_3572;
v_3576:
    goto v_3584;
v_3580:
    v_3701 = stack[-9];
    v_3702 = qcar(v_3701);
    goto v_3581;
v_3582:
    v_3701 = stack[-8];
    v_3701 = qcar(v_3701);
    goto v_3583;
v_3584:
    goto v_3580;
v_3581:
    goto v_3582;
v_3583:
    fn = elt(env, 1); // mchk
    v_3701 = (*qfn2(fn))(fn, v_3702, v_3701);
    env = stack[-11];
    v_3702 = v_3701;
    v_3701 = stack[-9];
    v_3701 = qcdr(v_3701);
    stack[-9] = v_3701;
    v_3701 = stack[-8];
    v_3701 = qcdr(v_3701);
    stack[-8] = v_3701;
    v_3701 = v_3702;
    stack[-10] = v_3701;
v_3598:
    v_3701 = stack[-10];
    if (v_3701 == nil) goto v_3603;
    else goto v_3604;
v_3603:
    v_3701 = nil;
    goto v_3597;
v_3604:
    v_3701 = stack[-10];
    v_3701 = qcar(v_3701);
    stack[-2] = v_3701;
    goto v_3619;
v_3611:
    stack[-1] = stack[-9];
    goto v_3612;
v_3613:
    goto v_3628;
v_3622:
    v_3703 = stack[-2];
    goto v_3623;
v_3624:
    v_3702 = stack[-8];
    goto v_3625;
v_3626:
    v_3701 = stack[-6];
    goto v_3627;
v_3628:
    goto v_3622;
v_3623:
    goto v_3624;
v_3625:
    goto v_3626;
v_3627:
    fn = elt(env, 2); // updtemplate
    stack[0] = (*qfnn(fn))(fn, 3, v_3703, v_3702, v_3701);
    env = stack[-11];
    goto v_3614;
v_3615:
    goto v_3637;
v_3633:
    v_3702 = stack[-7];
    goto v_3634;
v_3635:
    v_3701 = stack[-2];
    goto v_3636;
v_3637:
    goto v_3633;
v_3634:
    goto v_3635;
v_3636:
    fn = elt(env, 3); // msappend
    v_3702 = (*qfn2(fn))(fn, v_3702, v_3701);
    env = stack[-11];
    goto v_3616;
v_3617:
    v_3701 = stack[-6];
    goto v_3618;
v_3619:
    goto v_3611;
v_3612:
    goto v_3613;
v_3614:
    goto v_3615;
v_3616:
    goto v_3617;
v_3618:
    v_3701 = CC_mcharg2(elt(env, 0), 4, stack[-1], stack[0], v_3702, v_3701);
    env = stack[-11];
    stack[-5] = v_3701;
    v_3701 = stack[-5];
    fn = elt(env, 4); // lastpair
    v_3701 = (*qfn1(fn))(fn, v_3701);
    env = stack[-11];
    stack[-4] = v_3701;
    v_3701 = stack[-10];
    v_3701 = qcdr(v_3701);
    stack[-10] = v_3701;
    v_3701 = stack[-4];
    if (!consp(v_3701)) goto v_3647;
    else goto v_3648;
v_3647:
    goto v_3598;
v_3648:
v_3599:
    v_3701 = stack[-10];
    if (v_3701 == nil) goto v_3652;
    else goto v_3653;
v_3652:
    v_3701 = stack[-5];
    goto v_3597;
v_3653:
    goto v_3661;
v_3657:
    stack[-3] = stack[-4];
    goto v_3658;
v_3659:
    v_3701 = stack[-10];
    v_3701 = qcar(v_3701);
    stack[-2] = v_3701;
    goto v_3675;
v_3667:
    stack[-1] = stack[-9];
    goto v_3668;
v_3669:
    goto v_3684;
v_3678:
    v_3703 = stack[-2];
    goto v_3679;
v_3680:
    v_3702 = stack[-8];
    goto v_3681;
v_3682:
    v_3701 = stack[-6];
    goto v_3683;
v_3684:
    goto v_3678;
v_3679:
    goto v_3680;
v_3681:
    goto v_3682;
v_3683:
    fn = elt(env, 2); // updtemplate
    stack[0] = (*qfnn(fn))(fn, 3, v_3703, v_3702, v_3701);
    env = stack[-11];
    goto v_3670;
v_3671:
    goto v_3693;
v_3689:
    v_3702 = stack[-7];
    goto v_3690;
v_3691:
    v_3701 = stack[-2];
    goto v_3692;
v_3693:
    goto v_3689;
v_3690:
    goto v_3691;
v_3692:
    fn = elt(env, 3); // msappend
    v_3702 = (*qfn2(fn))(fn, v_3702, v_3701);
    env = stack[-11];
    goto v_3672;
v_3673:
    v_3701 = stack[-6];
    goto v_3674;
v_3675:
    goto v_3667;
v_3668:
    goto v_3669;
v_3670:
    goto v_3671;
v_3672:
    goto v_3673;
v_3674:
    v_3701 = CC_mcharg2(elt(env, 0), 4, stack[-1], stack[0], v_3702, v_3701);
    env = stack[-11];
    goto v_3660;
v_3661:
    goto v_3657;
v_3658:
    goto v_3659;
v_3660:
    v_3701 = Lrplacd(nil, stack[-3], v_3701);
    env = stack[-11];
    v_3701 = stack[-4];
    fn = elt(env, 4); // lastpair
    v_3701 = (*qfn1(fn))(fn, v_3701);
    env = stack[-11];
    stack[-4] = v_3701;
    v_3701 = stack[-10];
    v_3701 = qcdr(v_3701);
    stack[-10] = v_3701;
    goto v_3599;
v_3597:
v_3572:
    return onevalue(v_3701);
}



// Code for times!-term!-mod!-p

static LispObject CC_timesKtermKmodKp(LispObject env,
                         LispObject v_3565, LispObject v_3566)
{
    env = qenv(env);
    LispObject v_3786, v_3787, v_3788;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3565,v_3566);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_3566;
    stack[-2] = v_3565;
// end of prologue
    stack[-3] = nil;
v_3573:
    v_3786 = stack[-1];
    if (v_3786 == nil) goto v_3577;
    else goto v_3578;
v_3577:
    v_3786 = nil;
    v_3787 = v_3786;
    goto v_3574;
v_3578:
    v_3786 = stack[-1];
    if (!consp(v_3786)) goto v_3585;
    else goto v_3586;
v_3585:
    v_3786 = lisp_true;
    goto v_3584;
v_3586:
    v_3786 = stack[-1];
    v_3786 = qcar(v_3786);
    v_3786 = (consp(v_3786) ? nil : lisp_true);
    goto v_3584;
    v_3786 = nil;
v_3584:
    if (v_3786 == nil) goto v_3582;
    goto v_3599;
v_3595:
    v_3786 = stack[-2];
    v_3787 = qcdr(v_3786);
    goto v_3596;
v_3597:
    v_3786 = stack[-1];
    goto v_3598;
v_3599:
    goto v_3595;
v_3596:
    goto v_3597;
v_3598:
    fn = elt(env, 1); // multiply!-by!-constant!-mod!-p
    v_3787 = (*qfn2(fn))(fn, v_3787, v_3786);
    env = stack[-4];
    v_3786 = nil;
    v_3788 = v_3787;
    if (v_3788 == nil) goto v_3608;
    else goto v_3609;
v_3608:
    goto v_3607;
v_3609:
    goto v_3621;
v_3615:
    v_3788 = stack[-2];
    v_3788 = qcar(v_3788);
    goto v_3616;
v_3617:
    goto v_3618;
v_3619:
    goto v_3620;
v_3621:
    goto v_3615;
v_3616:
    goto v_3617;
v_3618:
    goto v_3619;
v_3620:
    v_3786 = acons(v_3788, v_3787, v_3786);
    env = stack[-4];
    goto v_3607;
    v_3786 = nil;
v_3607:
    v_3787 = v_3786;
    goto v_3574;
v_3582:
    goto v_3632;
v_3628:
    v_3786 = stack[-2];
    v_3786 = qcar(v_3786);
    v_3787 = qcar(v_3786);
    goto v_3629;
v_3630:
    v_3786 = stack[-1];
    v_3786 = qcar(v_3786);
    v_3786 = qcar(v_3786);
    v_3786 = qcar(v_3786);
    goto v_3631;
v_3632:
    goto v_3628;
v_3629:
    goto v_3630;
v_3631:
    if (equal(v_3787, v_3786)) goto v_3626;
    else goto v_3627;
v_3626:
    goto v_3647;
v_3641:
    goto v_3653;
v_3649:
    v_3786 = stack[-2];
    v_3786 = qcar(v_3786);
    v_3788 = qcar(v_3786);
    goto v_3650;
v_3651:
    goto v_3661;
v_3657:
    v_3786 = stack[-2];
    v_3786 = qcar(v_3786);
    v_3787 = qcdr(v_3786);
    goto v_3658;
v_3659:
    v_3786 = stack[-1];
    v_3786 = qcar(v_3786);
    v_3786 = qcar(v_3786);
    v_3786 = qcdr(v_3786);
    goto v_3660;
v_3661:
    goto v_3657;
v_3658:
    goto v_3659;
v_3660:
    v_3786 = (LispObject)(intptr_t)((intptr_t)v_3787 + (intptr_t)v_3786 - TAG_FIXNUM);
    goto v_3652;
v_3653:
    goto v_3649;
v_3650:
    goto v_3651;
v_3652:
    fn = elt(env, 2); // mksp
    stack[0] = (*qfn2(fn))(fn, v_3788, v_3786);
    env = stack[-4];
    goto v_3642;
v_3643:
    goto v_3675;
v_3671:
    v_3786 = stack[-2];
    v_3787 = qcdr(v_3786);
    goto v_3672;
v_3673:
    v_3786 = stack[-1];
    v_3786 = qcar(v_3786);
    v_3786 = qcdr(v_3786);
    goto v_3674;
v_3675:
    goto v_3671;
v_3672:
    goto v_3673;
v_3674:
    fn = elt(env, 3); // times!-mod!-p
    v_3787 = (*qfn2(fn))(fn, v_3787, v_3786);
    env = stack[-4];
    goto v_3644;
v_3645:
    v_3786 = stack[-3];
    goto v_3646;
v_3647:
    goto v_3641;
v_3642:
    goto v_3643;
v_3644:
    goto v_3645;
v_3646:
    v_3786 = acons(stack[0], v_3787, v_3786);
    env = stack[-4];
    stack[-3] = v_3786;
    v_3786 = stack[-1];
    v_3786 = qcdr(v_3786);
    stack[-1] = v_3786;
    goto v_3573;
v_3627:
    goto v_3691;
v_3687:
    v_3786 = stack[-2];
    v_3786 = qcar(v_3786);
    v_3787 = qcar(v_3786);
    goto v_3688;
v_3689:
    v_3786 = stack[-1];
    v_3786 = qcar(v_3786);
    v_3786 = qcar(v_3786);
    v_3786 = qcar(v_3786);
    goto v_3690;
v_3691:
    goto v_3687;
v_3688:
    goto v_3689;
v_3690:
    fn = elt(env, 4); // ordop
    v_3786 = (*qfn2(fn))(fn, v_3787, v_3786);
    env = stack[-4];
    if (v_3786 == nil) goto v_3685;
    goto v_3704;
v_3700:
    v_3786 = stack[-2];
    v_3787 = qcdr(v_3786);
    goto v_3701;
v_3702:
    v_3786 = stack[-1];
    goto v_3703;
v_3704:
    goto v_3700;
v_3701:
    goto v_3702;
v_3703:
    fn = elt(env, 3); // times!-mod!-p
    v_3787 = (*qfn2(fn))(fn, v_3787, v_3786);
    env = stack[-4];
    v_3786 = nil;
    v_3788 = v_3787;
    if (v_3788 == nil) goto v_3713;
    else goto v_3714;
v_3713:
    goto v_3712;
v_3714:
    goto v_3726;
v_3720:
    v_3788 = stack[-2];
    v_3788 = qcar(v_3788);
    goto v_3721;
v_3722:
    goto v_3723;
v_3724:
    goto v_3725;
v_3726:
    goto v_3720;
v_3721:
    goto v_3722;
v_3723:
    goto v_3724;
v_3725:
    v_3786 = acons(v_3788, v_3787, v_3786);
    env = stack[-4];
    goto v_3712;
    v_3786 = nil;
v_3712:
    v_3787 = v_3786;
    goto v_3574;
v_3685:
    goto v_3740;
v_3734:
    v_3786 = stack[-1];
    v_3786 = qcar(v_3786);
    stack[0] = qcar(v_3786);
    goto v_3735;
v_3736:
    goto v_3749;
v_3745:
    v_3787 = stack[-2];
    goto v_3746;
v_3747:
    v_3786 = stack[-1];
    v_3786 = qcar(v_3786);
    v_3786 = qcdr(v_3786);
    goto v_3748;
v_3749:
    goto v_3745;
v_3746:
    goto v_3747;
v_3748:
    v_3787 = CC_timesKtermKmodKp(elt(env, 0), v_3787, v_3786);
    env = stack[-4];
    goto v_3737;
v_3738:
    v_3786 = stack[-3];
    goto v_3739;
v_3740:
    goto v_3734;
v_3735:
    goto v_3736;
v_3737:
    goto v_3738;
v_3739:
    v_3786 = acons(stack[0], v_3787, v_3786);
    env = stack[-4];
    stack[-3] = v_3786;
    v_3786 = stack[-1];
    v_3786 = qcdr(v_3786);
    stack[-1] = v_3786;
    goto v_3573;
v_3574:
v_3759:
    v_3786 = stack[-3];
    if (v_3786 == nil) goto v_3762;
    else goto v_3763;
v_3762:
    goto v_3758;
v_3763:
    v_3786 = stack[-3];
    v_3786 = qcdr(v_3786);
    stack[0] = v_3786;
    v_3786 = stack[-3];
    v_3786 = qcar(v_3786);
    v_3786 = qcdr(v_3786);
    if (v_3786 == nil) goto v_3771;
    goto v_3780;
v_3776:
    v_3786 = stack[-3];
    goto v_3777;
v_3778:
    goto v_3779;
v_3780:
    goto v_3776;
v_3777:
    goto v_3778;
v_3779:
    v_3786 = Lrplacd(nil, v_3786, v_3787);
    env = stack[-4];
    v_3786 = stack[-3];
    v_3787 = v_3786;
    goto v_3769;
v_3771:
v_3769:
    v_3786 = stack[0];
    stack[-3] = v_3786;
    goto v_3759;
v_3758:
    v_3786 = v_3787;
    return onevalue(v_3786);
}



// Code for get_first_kernel

static LispObject CC_get_first_kernel(LispObject env,
                         LispObject v_3565, LispObject v_3566)
{
    env = qenv(env);
    LispObject v_3579, v_3580, v_3581;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3579 = v_3566;
    v_3580 = v_3565;
// end of prologue
    goto v_3575;
v_3569:
    v_3581 = v_3580;
    goto v_3570;
v_3571:
    v_3580 = v_3579;
    goto v_3572;
v_3573:
    v_3579 = nil;
    goto v_3574;
v_3575:
    goto v_3569;
v_3570:
    goto v_3571;
v_3572:
    goto v_3573;
v_3574:
    {
        fn = elt(env, 1); // gfk
        return (*qfnn(fn))(fn, 3, v_3581, v_3580, v_3579);
    }
}



// Code for lalr_precedence

static LispObject CC_lalr_precedence(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3586, v_3587;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3586 = v_3565;
// end of prologue
    goto v_3571;
v_3567:
    v_3587 = qvalue(elt(env, 1)); // precedence_table
    goto v_3568;
v_3569:
    goto v_3570;
v_3571:
    goto v_3567;
v_3568:
    goto v_3569;
v_3570:
    v_3586 = *(LispObject *)((char *)v_3587 + (CELL-TAG_VECTOR) + (((intptr_t)v_3586-TAG_FIXNUM)/(16/CELL)));
    v_3587 = v_3586;
    v_3586 = v_3587;
    if (v_3586 == nil) goto v_3579;
    v_3586 = v_3587;
    v_3586 = qcar(v_3586);
    goto v_3577;
v_3579:
    v_3586 = nil;
    goto v_3577;
    v_3586 = nil;
v_3577:
    return onevalue(v_3586);
}



// Code for totallessp

static LispObject CC_totallessp(LispObject env,
                         LispObject v_3565, LispObject v_3566)
{
    env = qenv(env);
    LispObject v_3583, v_3584;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3565,v_3566);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_3583 = v_3566;
    v_3584 = v_3565;
// end of prologue
    goto v_3572;
v_3568:
    goto v_3578;
v_3574:
    goto v_3575;
v_3576:
    goto v_3577;
v_3578:
    goto v_3574;
v_3575:
    goto v_3576;
v_3577:
    fn = elt(env, 2); // totalcompare
    v_3583 = (*qfn2(fn))(fn, v_3584, v_3583);
    env = stack[0];
    goto v_3569;
v_3570:
    v_3584 = elt(env, 1); // less
    goto v_3571;
v_3572:
    goto v_3568;
v_3569:
    goto v_3570;
v_3571:
    v_3583 = (v_3583 == v_3584 ? lisp_true : nil);
    return onevalue(v_3583);
}



// Code for talp_varlat

static LispObject CC_talp_varlat(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3579;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3565);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3565;
// end of prologue
    goto v_3572;
v_3568:
    v_3579 = stack[0];
    fn = elt(env, 1); // talp_arg2l
    v_3579 = (*qfn1(fn))(fn, v_3579);
    env = stack[-2];
    fn = elt(env, 2); // talp_varlt
    stack[-1] = (*qfn1(fn))(fn, v_3579);
    env = stack[-2];
    goto v_3569;
v_3570:
    v_3579 = stack[0];
    fn = elt(env, 3); // talp_arg2r
    v_3579 = (*qfn1(fn))(fn, v_3579);
    env = stack[-2];
    fn = elt(env, 2); // talp_varlt
    v_3579 = (*qfn1(fn))(fn, v_3579);
    env = stack[-2];
    goto v_3571;
v_3572:
    goto v_3568;
v_3569:
    goto v_3570;
v_3571:
    {
        LispObject v_3582 = stack[-1];
        fn = elt(env, 4); // union
        return (*qfn2(fn))(fn, v_3582, v_3579);
    }
}



// Code for ibalp_varlat

static LispObject CC_ibalp_varlat(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3579;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3565);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3565;
// end of prologue
    goto v_3572;
v_3568:
    v_3579 = stack[0];
    fn = elt(env, 1); // ibalp_arg2l
    v_3579 = (*qfn1(fn))(fn, v_3579);
    env = stack[-2];
    fn = elt(env, 2); // ibalp_varlt
    stack[-1] = (*qfn1(fn))(fn, v_3579);
    env = stack[-2];
    goto v_3569;
v_3570:
    v_3579 = stack[0];
    fn = elt(env, 3); // ibalp_arg2r
    v_3579 = (*qfn1(fn))(fn, v_3579);
    env = stack[-2];
    fn = elt(env, 2); // ibalp_varlt
    v_3579 = (*qfn1(fn))(fn, v_3579);
    env = stack[-2];
    goto v_3571;
v_3572:
    goto v_3568;
v_3569:
    goto v_3570;
v_3571:
    {
        LispObject v_3582 = stack[-1];
        fn = elt(env, 4); // union
        return (*qfn2(fn))(fn, v_3582, v_3579);
    }
}



// Code for retattributes

static LispObject CC_retattributes(LispObject env,
                         LispObject v_3565, LispObject v_3566)
{
    env = qenv(env);
    LispObject v_3629, v_3630;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3565,v_3566);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3566;
    stack[-1] = v_3565;
// end of prologue
v_3564:
    v_3629 = stack[0];
    if (v_3629 == nil) goto v_3573;
    else goto v_3574;
v_3573:
    goto v_3572;
v_3574:
    goto v_3584;
v_3580:
    v_3630 = stack[-1];
    goto v_3581;
v_3582:
    v_3629 = stack[0];
    v_3629 = qcar(v_3629);
    goto v_3583;
v_3584:
    goto v_3580;
v_3581:
    goto v_3582;
v_3583:
    fn = elt(env, 1); // find
    v_3629 = (*qfn2(fn))(fn, v_3630, v_3629);
    env = stack[-3];
    v_3630 = v_3629;
    if (v_3630 == nil) goto v_3591;
    goto v_3598;
v_3594:
    goto v_3604;
v_3600:
    v_3630 = stack[0];
    v_3630 = qcar(v_3630);
    goto v_3601;
v_3602:
    goto v_3603;
v_3604:
    goto v_3600;
v_3601:
    goto v_3602;
v_3603:
    stack[-2] = list2(v_3630, v_3629);
    env = stack[-3];
    goto v_3595;
v_3596:
    goto v_3613;
v_3609:
    v_3630 = stack[-1];
    goto v_3610;
v_3611:
    v_3629 = stack[0];
    v_3629 = qcdr(v_3629);
    goto v_3612;
v_3613:
    goto v_3609;
v_3610:
    goto v_3611;
v_3612:
    v_3629 = CC_retattributes(elt(env, 0), v_3630, v_3629);
    goto v_3597;
v_3598:
    goto v_3594;
v_3595:
    goto v_3596;
v_3597:
    {
        LispObject v_3634 = stack[-2];
        return cons(v_3634, v_3629);
    }
v_3591:
    goto v_3624;
v_3620:
    v_3630 = stack[-1];
    goto v_3621;
v_3622:
    v_3629 = stack[0];
    v_3629 = qcdr(v_3629);
    goto v_3623;
v_3624:
    goto v_3620;
v_3621:
    goto v_3622;
v_3623:
    stack[-1] = v_3630;
    stack[0] = v_3629;
    goto v_3564;
    goto v_3572;
v_3572:
    v_3629 = nil;
    return onevalue(v_3629);
}



// Code for retimes1

static LispObject CC_retimes1(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3683, v_3684;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3565);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3565;
// end of prologue
    stack[-1] = nil;
v_3570:
    v_3683 = stack[0];
    if (v_3683 == nil) goto v_3573;
    else goto v_3574;
v_3573:
    v_3683 = stack[-1];
    {
        fn = elt(env, 4); // nreverse
        return (*qfn1(fn))(fn, v_3683);
    }
v_3574:
    goto v_3584;
v_3580:
    v_3683 = stack[0];
    v_3684 = qcar(v_3683);
    goto v_3581;
v_3582:
    v_3683 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3583;
v_3584:
    goto v_3580;
v_3581:
    goto v_3582;
v_3583:
    if (v_3684 == v_3683) goto v_3578;
    else goto v_3579;
v_3578:
    v_3683 = stack[0];
    v_3683 = qcdr(v_3683);
    stack[0] = v_3683;
    goto v_3570;
v_3579:
    v_3683 = stack[0];
    v_3683 = qcar(v_3683);
    v_3683 = Lminusp(nil, v_3683);
    env = stack[-2];
    if (v_3683 == nil) goto v_3591;
    v_3683 = qvalue(elt(env, 1)); // !*bool
    v_3683 = (v_3683 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v_3683; // !*bool
    goto v_3602;
v_3598:
    v_3683 = stack[0];
    v_3683 = qcar(v_3683);
    v_3684 = negate(v_3683);
    env = stack[-2];
    goto v_3599;
v_3600:
    v_3683 = stack[0];
    v_3683 = qcdr(v_3683);
    goto v_3601;
v_3602:
    goto v_3598;
v_3599:
    goto v_3600;
v_3601:
    v_3683 = cons(v_3684, v_3683);
    env = stack[-2];
    stack[0] = v_3683;
    goto v_3570;
v_3591:
    v_3683 = stack[0];
    v_3683 = qcar(v_3683);
    if (!consp(v_3683)) goto v_3608;
    else goto v_3609;
v_3608:
    goto v_3617;
v_3613:
    v_3683 = stack[0];
    v_3684 = qcar(v_3683);
    goto v_3614;
v_3615:
    v_3683 = stack[-1];
    goto v_3616;
v_3617:
    goto v_3613;
v_3614:
    goto v_3615;
v_3616:
    v_3683 = cons(v_3684, v_3683);
    env = stack[-2];
    stack[-1] = v_3683;
    v_3683 = stack[0];
    v_3683 = qcdr(v_3683);
    stack[0] = v_3683;
    goto v_3570;
v_3609:
    goto v_3629;
v_3625:
    v_3683 = stack[0];
    v_3683 = qcar(v_3683);
    v_3684 = qcar(v_3683);
    goto v_3626;
v_3627:
    v_3683 = elt(env, 2); // minus
    goto v_3628;
v_3629:
    goto v_3625;
v_3626:
    goto v_3627;
v_3628:
    if (v_3684 == v_3683) goto v_3623;
    else goto v_3624;
v_3623:
    v_3683 = qvalue(elt(env, 1)); // !*bool
    v_3683 = (v_3683 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v_3683; // !*bool
    goto v_3641;
v_3637:
    v_3683 = stack[0];
    v_3683 = qcar(v_3683);
    v_3683 = qcdr(v_3683);
    v_3684 = qcar(v_3683);
    goto v_3638;
v_3639:
    v_3683 = stack[0];
    v_3683 = qcdr(v_3683);
    goto v_3640;
v_3641:
    goto v_3637;
v_3638:
    goto v_3639;
v_3640:
    v_3683 = cons(v_3684, v_3683);
    env = stack[-2];
    stack[0] = v_3683;
    goto v_3570;
v_3624:
    goto v_3654;
v_3650:
    v_3683 = stack[0];
    v_3683 = qcar(v_3683);
    v_3684 = qcar(v_3683);
    goto v_3651;
v_3652:
    v_3683 = elt(env, 3); // times
    goto v_3653;
v_3654:
    goto v_3650;
v_3651:
    goto v_3652;
v_3653:
    if (v_3684 == v_3683) goto v_3648;
    else goto v_3649;
v_3648:
    goto v_3664;
v_3660:
    v_3683 = stack[0];
    v_3683 = qcar(v_3683);
    v_3684 = qcdr(v_3683);
    goto v_3661;
v_3662:
    v_3683 = stack[0];
    v_3683 = qcdr(v_3683);
    goto v_3663;
v_3664:
    goto v_3660;
v_3661:
    goto v_3662;
v_3663:
    v_3683 = Lappend(nil, v_3684, v_3683);
    env = stack[-2];
    stack[0] = v_3683;
    goto v_3570;
v_3649:
    goto v_3677;
v_3673:
    v_3683 = stack[0];
    v_3684 = qcar(v_3683);
    goto v_3674;
v_3675:
    v_3683 = stack[-1];
    goto v_3676;
v_3677:
    goto v_3673;
v_3674:
    goto v_3675;
v_3676:
    v_3683 = cons(v_3684, v_3683);
    env = stack[-2];
    stack[-1] = v_3683;
    v_3683 = stack[0];
    v_3683 = qcdr(v_3683);
    stack[0] = v_3683;
    goto v_3570;
    v_3683 = nil;
    return onevalue(v_3683);
}



// Code for variables

static LispObject CC_variables(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3710, v_3711;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3565);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_3565;
// end of prologue
    v_3710 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_3710;
    v_3710 = stack[-5];
    if (v_3710 == nil) goto v_3582;
    else goto v_3583;
v_3582:
    v_3710 = nil;
    goto v_3574;
v_3583:
    v_3710 = qvalue(elt(env, 1)); // dipvars!*
    v_3710 = Llength(nil, v_3710);
    env = stack[-7];
    stack[-6] = v_3710;
    v_3710 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_3710;
    goto v_3605;
v_3601:
    v_3711 = stack[-6];
    goto v_3602;
v_3603:
    v_3710 = stack[-3];
    goto v_3604;
v_3605:
    goto v_3601;
v_3602:
    goto v_3603;
v_3604:
    v_3710 = difference2(v_3711, v_3710);
    env = stack[-7];
    v_3710 = Lminusp(nil, v_3710);
    env = stack[-7];
    if (v_3710 == nil) goto v_3598;
    v_3710 = nil;
    goto v_3592;
v_3598:
    v_3710 = nil;
    v_3710 = ncons(v_3710);
    env = stack[-7];
    stack[-1] = v_3710;
    stack[-2] = v_3710;
v_3593:
    v_3710 = stack[-3];
    v_3710 = add1(v_3710);
    env = stack[-7];
    stack[-3] = v_3710;
    goto v_3623;
v_3619:
    v_3711 = stack[-6];
    goto v_3620;
v_3621:
    v_3710 = stack[-3];
    goto v_3622;
v_3623:
    goto v_3619;
v_3620:
    goto v_3621;
v_3622:
    v_3710 = difference2(v_3711, v_3710);
    env = stack[-7];
    v_3710 = Lminusp(nil, v_3710);
    env = stack[-7];
    if (v_3710 == nil) goto v_3616;
    v_3710 = stack[-2];
    goto v_3592;
v_3616:
    goto v_3632;
v_3628:
    stack[0] = stack[-1];
    goto v_3629;
v_3630:
    v_3710 = nil;
    v_3710 = ncons(v_3710);
    env = stack[-7];
    goto v_3631;
v_3632:
    goto v_3628;
v_3629:
    goto v_3630;
v_3631:
    v_3710 = Lrplacd(nil, stack[0], v_3710);
    env = stack[-7];
    v_3710 = stack[-1];
    v_3710 = qcdr(v_3710);
    stack[-1] = v_3710;
    goto v_3593;
v_3592:
    stack[0] = v_3710;
v_3575:
    v_3710 = stack[-5];
    v_3710 = qcar(v_3710);
    v_3710 = qcdr(v_3710);
    v_3710 = qcdr(v_3710);
    v_3710 = qcdr(v_3710);
    v_3710 = qcar(v_3710);
    stack[-2] = v_3710;
v_3576:
    v_3710 = stack[-2];
    v_3710 = qcar(v_3710);
    stack[-3] = v_3710;
    v_3710 = stack[0];
    stack[-1] = v_3710;
v_3577:
    goto v_3656;
v_3652:
    v_3710 = stack[-3];
    v_3711 = qcar(v_3710);
    goto v_3653;
v_3654:
    v_3710 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3655;
v_3656:
    goto v_3652;
v_3653:
    goto v_3654;
v_3655:
    if (((intptr_t)(v_3711)) > ((intptr_t)(v_3710))) goto v_3651;
    else goto v_3650;
v_3651:
    v_3710 = stack[-1];
    v_3710 = qcar(v_3710);
    if (v_3710 == nil) goto v_3660;
    else goto v_3650;
v_3660:
    goto v_3668;
v_3664:
    v_3711 = stack[-1];
    goto v_3665;
v_3666:
    v_3710 = lisp_true;
    goto v_3667;
v_3668:
    goto v_3664;
v_3665:
    goto v_3666;
v_3667:
    fn = elt(env, 2); // setcar
    v_3710 = (*qfn2(fn))(fn, v_3711, v_3710);
    env = stack[-7];
    v_3710 = stack[-4];
    v_3710 = (LispObject)((intptr_t)(v_3710) + 0x10);
    stack[-4] = v_3710;
    goto v_3648;
v_3650:
v_3648:
    goto v_3681;
v_3677:
    v_3711 = stack[-4];
    goto v_3678;
v_3679:
    v_3710 = stack[-6];
    goto v_3680;
v_3681:
    goto v_3677;
v_3678:
    goto v_3679;
v_3680:
    if (v_3711 == v_3710) goto v_3675;
    else goto v_3676;
v_3675:
    v_3710 = stack[0];
    goto v_3574;
v_3676:
    v_3710 = stack[-3];
    v_3710 = qcdr(v_3710);
    stack[-3] = v_3710;
    v_3710 = stack[-3];
    if (v_3710 == nil) goto v_3690;
    v_3710 = stack[-1];
    v_3710 = qcdr(v_3710);
    stack[-1] = v_3710;
    goto v_3577;
v_3690:
    v_3710 = stack[-2];
    v_3710 = qcdr(v_3710);
    v_3710 = qcdr(v_3710);
    stack[-2] = v_3710;
    v_3710 = stack[-2];
    if (v_3710 == nil) goto v_3700;
    goto v_3576;
v_3700:
    v_3710 = stack[-5];
    v_3710 = qcdr(v_3710);
    stack[-5] = v_3710;
    v_3710 = stack[-5];
    if (v_3710 == nil) goto v_3707;
    goto v_3575;
v_3707:
    v_3710 = stack[0];
v_3574:
    return onevalue(v_3710);
}



// Code for worderp

static LispObject CC_worderp(LispObject env,
                         LispObject v_3565, LispObject v_3566)
{
    env = qenv(env);
    LispObject v_3734, v_3735, v_3736;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3565,v_3566);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3566;
    stack[-1] = v_3565;
// end of prologue
v_3564:
v_3570:
    v_3734 = stack[-1];
    if (!consp(v_3734)) goto v_3578;
    v_3734 = stack[-1];
    v_3734 = qcar(v_3734);
    if (!symbolp(v_3734)) v_3734 = nil;
    else { v_3734 = qfastgets(v_3734);
           if (v_3734 != nil) { v_3734 = elt(v_3734, 16); // indexvar
#ifdef RECORD_GET
             if (v_3734 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v_3734 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v_3734 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v_3734 == SPID_NOPROP) v_3734 = nil; else v_3734 = lisp_true; }}
#endif
    if (v_3734 == nil) goto v_3583;
    v_3734 = stack[0];
    if (!consp(v_3734)) goto v_3590;
    v_3734 = stack[0];
    v_3734 = qcar(v_3734);
    if (!symbolp(v_3734)) v_3734 = nil;
    else { v_3734 = qfastgets(v_3734);
           if (v_3734 != nil) { v_3734 = elt(v_3734, 16); // indexvar
#ifdef RECORD_GET
             if (v_3734 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v_3734 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v_3734 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v_3734 == SPID_NOPROP) v_3734 = nil; else v_3734 = lisp_true; }}
#endif
    goto v_3588;
v_3590:
    v_3734 = nil;
    goto v_3588;
    v_3734 = nil;
v_3588:
    goto v_3581;
v_3583:
    v_3734 = nil;
    goto v_3581;
    v_3734 = nil;
v_3581:
    goto v_3576;
v_3578:
    v_3734 = nil;
    goto v_3576;
    v_3734 = nil;
v_3576:
    if (v_3734 == nil) goto v_3574;
    goto v_3609;
v_3605:
    v_3735 = stack[-1];
    goto v_3606;
v_3607:
    v_3734 = stack[0];
    goto v_3608;
v_3609:
    goto v_3605;
v_3606:
    goto v_3607;
v_3608:
    {
        fn = elt(env, 2); // indexvarordp
        return (*qfn2(fn))(fn, v_3735, v_3734);
    }
v_3574:
    v_3734 = stack[-1];
    if (!consp(v_3734)) goto v_3616;
    else goto v_3617;
v_3616:
    v_3734 = lisp_true;
    goto v_3615;
v_3617:
    goto v_3626;
v_3622:
    v_3735 = stack[-1];
    goto v_3623;
v_3624:
    v_3734 = qvalue(elt(env, 1)); // kord!*
    goto v_3625;
v_3626:
    goto v_3622;
v_3623:
    goto v_3624;
v_3625:
    v_3734 = Lmemq(nil, v_3735, v_3734);
    goto v_3615;
    v_3734 = nil;
v_3615:
    if (v_3734 == nil) goto v_3613;
    v_3734 = stack[0];
    if (!consp(v_3734)) goto v_3636;
    else goto v_3637;
v_3636:
    v_3734 = lisp_true;
    goto v_3635;
v_3637:
    goto v_3646;
v_3642:
    v_3735 = stack[0];
    goto v_3643;
v_3644:
    v_3734 = qvalue(elt(env, 1)); // kord!*
    goto v_3645;
v_3646:
    goto v_3642;
v_3643:
    goto v_3644;
v_3645:
    v_3734 = Lmemq(nil, v_3735, v_3734);
    goto v_3635;
    v_3734 = nil;
v_3635:
    if (v_3734 == nil) goto v_3633;
    goto v_3655;
v_3651:
    v_3735 = stack[-1];
    goto v_3652;
v_3653:
    v_3734 = stack[0];
    goto v_3654;
v_3655:
    goto v_3651;
v_3652:
    goto v_3653;
v_3654:
    {
        fn = elt(env, 3); // ordop
        return (*qfn2(fn))(fn, v_3735, v_3734);
    }
v_3633:
    v_3734 = stack[0];
    fn = elt(env, 4); // peel
    v_3734 = (*qfn1(fn))(fn, v_3734);
    env = stack[-2];
    v_3736 = v_3734;
    goto v_3671;
v_3667:
    v_3735 = stack[-1];
    goto v_3668;
v_3669:
    v_3734 = v_3736;
    goto v_3670;
v_3671:
    goto v_3667;
v_3668:
    goto v_3669;
v_3670:
    if (v_3735 == v_3734) goto v_3665;
    else goto v_3666;
v_3665:
    v_3734 = lisp_true;
    goto v_3664;
v_3666:
    goto v_3682;
v_3678:
    v_3734 = stack[-1];
    goto v_3679;
v_3680:
    v_3735 = v_3736;
    goto v_3681;
v_3682:
    goto v_3678;
v_3679:
    goto v_3680;
v_3681:
    stack[-1] = v_3734;
    stack[0] = v_3735;
    goto v_3564;
    v_3734 = nil;
v_3664:
    goto v_3569;
    goto v_3572;
v_3613:
    v_3734 = stack[0];
    if (!consp(v_3734)) goto v_3689;
    else goto v_3690;
v_3689:
    v_3734 = lisp_true;
    goto v_3688;
v_3690:
    goto v_3699;
v_3695:
    v_3735 = stack[0];
    goto v_3696;
v_3697:
    v_3734 = qvalue(elt(env, 1)); // kord!*
    goto v_3698;
v_3699:
    goto v_3695;
v_3696:
    goto v_3697;
v_3698:
    v_3734 = Lmemq(nil, v_3735, v_3734);
    goto v_3688;
    v_3734 = nil;
v_3688:
    if (v_3734 == nil) goto v_3686;
    v_3734 = stack[-1];
    fn = elt(env, 4); // peel
    v_3734 = (*qfn1(fn))(fn, v_3734);
    env = stack[-2];
    v_3736 = v_3734;
    goto v_3714;
v_3710:
    v_3735 = v_3736;
    goto v_3711;
v_3712:
    v_3734 = stack[0];
    goto v_3713;
v_3714:
    goto v_3710;
v_3711:
    goto v_3712;
v_3713:
    if (v_3735 == v_3734) goto v_3708;
    else goto v_3709;
v_3708:
    v_3734 = nil;
    goto v_3707;
v_3709:
    goto v_3725;
v_3721:
    v_3735 = v_3736;
    goto v_3722;
v_3723:
    v_3734 = stack[0];
    goto v_3724;
v_3725:
    goto v_3721;
v_3722:
    goto v_3723;
v_3724:
    stack[-1] = v_3735;
    stack[0] = v_3734;
    goto v_3564;
    v_3734 = nil;
v_3707:
    goto v_3569;
v_3686:
    v_3734 = stack[-1];
    fn = elt(env, 4); // peel
    v_3734 = (*qfn1(fn))(fn, v_3734);
    env = stack[-2];
    stack[-1] = v_3734;
    v_3734 = stack[0];
    fn = elt(env, 4); // peel
    v_3734 = (*qfn1(fn))(fn, v_3734);
    env = stack[-2];
    stack[0] = v_3734;
    goto v_3570;
v_3572:
    v_3734 = nil;
v_3569:
    return onevalue(v_3734);
}



// Code for evaluate0

static LispObject CC_evaluate0(LispObject env,
                         LispObject v_3565, LispObject v_3566)
{
    env = qenv(env);
    LispObject v_3577, v_3578;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3565,v_3566);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_3566;
    v_3577 = v_3565;
// end of prologue
    goto v_3573;
v_3569:
    fn = elt(env, 1); // evaluate!-horner
    v_3578 = (*qfn1(fn))(fn, v_3577);
    env = stack[-1];
    goto v_3570;
v_3571:
    v_3577 = stack[0];
    goto v_3572;
v_3573:
    goto v_3569;
v_3570:
    goto v_3571;
v_3572:
    {
        fn = elt(env, 2); // evaluate1
        return (*qfn2(fn))(fn, v_3578, v_3577);
    }
}



// Code for eofcheck

static LispObject CC_eofcheck(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3596, v_3597;
    argcheck(nargs, 0, "eofcheck");
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
    goto v_3574;
v_3570:
    v_3597 = qvalue(elt(env, 1)); // program!*
    goto v_3571;
v_3572:
    v_3596 = qvalue(elt(env, 2)); // !$eof!$
    goto v_3573;
v_3574:
    goto v_3570;
v_3571:
    goto v_3572;
v_3573:
    if (v_3597 == v_3596) goto v_3568;
    else goto v_3569;
v_3568:
    goto v_3585;
v_3581:
    v_3597 = qvalue(elt(env, 3)); // ttype!*
    goto v_3582;
v_3583:
    v_3596 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_3584;
v_3585:
    goto v_3581;
v_3582:
    goto v_3583;
v_3584:
    if (v_3597 == v_3596) goto v_3579;
    else goto v_3580;
v_3579:
    v_3596 = qvalue(elt(env, 4)); // eof!*
    v_3596 = add1(v_3596);
    env = stack[0];
    qvalue(elt(env, 4)) = v_3596; // eof!*
    goto v_3578;
v_3580:
    v_3596 = nil;
    goto v_3578;
    v_3596 = nil;
v_3578:
    goto v_3567;
v_3569:
    v_3596 = nil;
    goto v_3567;
    v_3596 = nil;
v_3567:
    return onevalue(v_3596);
}



// Code for dp_ecart

static LispObject CC_dp_ecart(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3586;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3565);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3565;
// end of prologue
    v_3586 = stack[0];
    if (v_3586 == nil) goto v_3569;
    else goto v_3570;
v_3569:
    v_3586 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3568;
v_3570:
    goto v_3580;
v_3576:
    v_3586 = stack[0];
    fn = elt(env, 1); // dp!=ecart
    stack[-1] = (*qfn1(fn))(fn, v_3586);
    env = stack[-2];
    goto v_3577;
v_3578:
    v_3586 = stack[0];
    fn = elt(env, 2); // dp_lmon
    v_3586 = (*qfn1(fn))(fn, v_3586);
    env = stack[-2];
    fn = elt(env, 3); // mo_ecart
    v_3586 = (*qfn1(fn))(fn, v_3586);
    goto v_3579;
v_3580:
    goto v_3576;
v_3577:
    goto v_3578;
v_3579:
    {
        LispObject v_3589 = stack[-1];
        return difference2(v_3589, v_3586);
    }
    v_3586 = nil;
v_3568:
    return onevalue(v_3586);
}



// Code for pdmult

static LispObject CC_pdmult(LispObject env,
                         LispObject v_3566, LispObject v_3567)
{
    env = qenv(env);
    LispObject v_3759, v_3760;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3567,v_3566);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3566,v_3567);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    v_3759 = v_3567;
    v_3760 = v_3566;
// end of prologue
// Binding d
// FLUIDBIND: reloadenv=10 litvec-offset=1 saveloc=9
{   bind_fluid_stack bind_fluid_var(-10, 1, -9);
    qvalue(elt(env, 1)) = v_3759; // d
    v_3759 = v_3760;
    stack[-8] = v_3759;
    v_3759 = stack[-8];
    if (v_3759 == nil) goto v_3582;
    else goto v_3583;
v_3582:
    v_3759 = nil;
    goto v_3577;
v_3583:
    v_3759 = stack[-8];
    v_3759 = qcar(v_3759);
    stack[-4] = v_3759;
    goto v_3595;
v_3591:
    goto v_3607;
v_3603:
    v_3759 = stack[-4];
    v_3760 = qcar(v_3759);
    goto v_3604;
v_3605:
    v_3759 = qvalue(elt(env, 1)); // d
    goto v_3606;
v_3607:
    goto v_3603;
v_3604:
    goto v_3605;
v_3606:
    fn = elt(env, 2); // pair
    v_3759 = (*qfn2(fn))(fn, v_3760, v_3759);
    env = stack[-10];
    stack[-3] = v_3759;
    v_3759 = stack[-3];
    if (v_3759 == nil) goto v_3613;
    else goto v_3614;
v_3613:
    v_3759 = nil;
    v_3760 = v_3759;
    goto v_3600;
v_3614:
    v_3759 = stack[-3];
    v_3759 = qcar(v_3759);
    goto v_3625;
v_3621:
    v_3760 = v_3759;
    v_3760 = qcar(v_3760);
    goto v_3622;
v_3623:
    v_3759 = qcdr(v_3759);
    goto v_3624;
v_3625:
    goto v_3621;
v_3622:
    goto v_3623;
v_3624:
    v_3759 = (LispObject)(intptr_t)((intptr_t)v_3760 + (intptr_t)v_3759 - TAG_FIXNUM);
    v_3759 = ncons(v_3759);
    env = stack[-10];
    stack[-1] = v_3759;
    stack[-2] = v_3759;
v_3601:
    v_3759 = stack[-3];
    v_3759 = qcdr(v_3759);
    stack[-3] = v_3759;
    v_3759 = stack[-3];
    if (v_3759 == nil) goto v_3635;
    else goto v_3636;
v_3635:
    v_3759 = stack[-2];
    v_3760 = v_3759;
    goto v_3600;
v_3636:
    goto v_3644;
v_3640:
    stack[0] = stack[-1];
    goto v_3641;
v_3642:
    v_3759 = stack[-3];
    v_3759 = qcar(v_3759);
    goto v_3654;
v_3650:
    v_3760 = v_3759;
    v_3760 = qcar(v_3760);
    goto v_3651;
v_3652:
    v_3759 = qcdr(v_3759);
    goto v_3653;
v_3654:
    goto v_3650;
v_3651:
    goto v_3652;
v_3653:
    v_3759 = (LispObject)(intptr_t)((intptr_t)v_3760 + (intptr_t)v_3759 - TAG_FIXNUM);
    v_3759 = ncons(v_3759);
    env = stack[-10];
    goto v_3643;
v_3644:
    goto v_3640;
v_3641:
    goto v_3642;
v_3643:
    v_3759 = Lrplacd(nil, stack[0], v_3759);
    env = stack[-10];
    v_3759 = stack[-1];
    v_3759 = qcdr(v_3759);
    stack[-1] = v_3759;
    goto v_3601;
v_3600:
    goto v_3592;
v_3593:
    v_3759 = stack[-4];
    v_3759 = qcdr(v_3759);
    goto v_3594;
v_3595:
    goto v_3591;
v_3592:
    goto v_3593;
v_3594:
    v_3759 = cons(v_3760, v_3759);
    env = stack[-10];
    v_3759 = ncons(v_3759);
    env = stack[-10];
    stack[-6] = v_3759;
    stack[-7] = v_3759;
v_3578:
    v_3759 = stack[-8];
    v_3759 = qcdr(v_3759);
    stack[-8] = v_3759;
    v_3759 = stack[-8];
    if (v_3759 == nil) goto v_3668;
    else goto v_3669;
v_3668:
    v_3759 = stack[-7];
    goto v_3577;
v_3669:
    goto v_3677;
v_3673:
    stack[-5] = stack[-6];
    goto v_3674;
v_3675:
    v_3759 = stack[-8];
    v_3759 = qcar(v_3759);
    stack[-4] = v_3759;
    goto v_3688;
v_3684:
    goto v_3700;
v_3696:
    v_3759 = stack[-4];
    v_3760 = qcar(v_3759);
    goto v_3697;
v_3698:
    v_3759 = qvalue(elt(env, 1)); // d
    goto v_3699;
v_3700:
    goto v_3696;
v_3697:
    goto v_3698;
v_3699:
    fn = elt(env, 2); // pair
    v_3759 = (*qfn2(fn))(fn, v_3760, v_3759);
    env = stack[-10];
    stack[-3] = v_3759;
    v_3759 = stack[-3];
    if (v_3759 == nil) goto v_3706;
    else goto v_3707;
v_3706:
    v_3759 = nil;
    v_3760 = v_3759;
    goto v_3693;
v_3707:
    v_3759 = stack[-3];
    v_3759 = qcar(v_3759);
    goto v_3718;
v_3714:
    v_3760 = v_3759;
    v_3760 = qcar(v_3760);
    goto v_3715;
v_3716:
    v_3759 = qcdr(v_3759);
    goto v_3717;
v_3718:
    goto v_3714;
v_3715:
    goto v_3716;
v_3717:
    v_3759 = (LispObject)(intptr_t)((intptr_t)v_3760 + (intptr_t)v_3759 - TAG_FIXNUM);
    v_3759 = ncons(v_3759);
    env = stack[-10];
    stack[-1] = v_3759;
    stack[-2] = v_3759;
v_3694:
    v_3759 = stack[-3];
    v_3759 = qcdr(v_3759);
    stack[-3] = v_3759;
    v_3759 = stack[-3];
    if (v_3759 == nil) goto v_3728;
    else goto v_3729;
v_3728:
    v_3759 = stack[-2];
    v_3760 = v_3759;
    goto v_3693;
v_3729:
    goto v_3737;
v_3733:
    stack[0] = stack[-1];
    goto v_3734;
v_3735:
    v_3759 = stack[-3];
    v_3759 = qcar(v_3759);
    goto v_3747;
v_3743:
    v_3760 = v_3759;
    v_3760 = qcar(v_3760);
    goto v_3744;
v_3745:
    v_3759 = qcdr(v_3759);
    goto v_3746;
v_3747:
    goto v_3743;
v_3744:
    goto v_3745;
v_3746:
    v_3759 = (LispObject)(intptr_t)((intptr_t)v_3760 + (intptr_t)v_3759 - TAG_FIXNUM);
    v_3759 = ncons(v_3759);
    env = stack[-10];
    goto v_3736;
v_3737:
    goto v_3733;
v_3734:
    goto v_3735;
v_3736:
    v_3759 = Lrplacd(nil, stack[0], v_3759);
    env = stack[-10];
    v_3759 = stack[-1];
    v_3759 = qcdr(v_3759);
    stack[-1] = v_3759;
    goto v_3694;
v_3693:
    goto v_3685;
v_3686:
    v_3759 = stack[-4];
    v_3759 = qcdr(v_3759);
    goto v_3687;
v_3688:
    goto v_3684;
v_3685:
    goto v_3686;
v_3687:
    v_3759 = cons(v_3760, v_3759);
    env = stack[-10];
    v_3759 = ncons(v_3759);
    env = stack[-10];
    goto v_3676;
v_3677:
    goto v_3673;
v_3674:
    goto v_3675;
v_3676:
    v_3759 = Lrplacd(nil, stack[-5], v_3759);
    env = stack[-10];
    v_3759 = stack[-6];
    v_3759 = qcdr(v_3759);
    stack[-6] = v_3759;
    goto v_3578;
v_3577:
    ;}  // end of a binding scope
    return onevalue(v_3759);
}



// Code for cancel

static LispObject CC_cancel(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3641, v_3642;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3565);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3565;
// end of prologue
    v_3641 = qvalue(elt(env, 1)); // !*mcd
    if (v_3641 == nil) goto v_3571;
    else goto v_3569;
v_3571:
    goto v_3578;
v_3574:
    v_3641 = stack[0];
    v_3642 = qcdr(v_3641);
    goto v_3575;
v_3576:
    v_3641 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3577;
v_3578:
    goto v_3574;
v_3575:
    goto v_3576;
v_3577:
    if (v_3642 == v_3641) goto v_3569;
    goto v_3570;
v_3569:
    goto v_3587;
v_3583:
    goto v_3593;
v_3589:
    v_3641 = stack[0];
    v_3642 = qcar(v_3641);
    goto v_3590;
v_3591:
    v_3641 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3592;
v_3593:
    goto v_3589;
v_3590:
    goto v_3591;
v_3592:
    stack[-1] = cons(v_3642, v_3641);
    env = stack[-2];
    goto v_3584;
v_3585:
    goto v_3602;
v_3598:
    v_3642 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3599;
v_3600:
    v_3641 = stack[0];
    v_3641 = qcdr(v_3641);
    goto v_3601;
v_3602:
    goto v_3598;
v_3599:
    goto v_3600;
v_3601:
    v_3641 = cons(v_3642, v_3641);
    env = stack[-2];
    goto v_3586;
v_3587:
    goto v_3583;
v_3584:
    goto v_3585;
v_3586:
    {
        LispObject v_3645 = stack[-1];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_3645, v_3641);
    }
v_3570:
    goto v_3613;
v_3609:
    goto v_3619;
v_3615:
    v_3641 = stack[0];
    v_3642 = qcar(v_3641);
    goto v_3616;
v_3617:
    v_3641 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3618;
v_3619:
    goto v_3615;
v_3616:
    goto v_3617;
v_3618:
    stack[-1] = cons(v_3642, v_3641);
    env = stack[-2];
    goto v_3610;
v_3611:
    goto v_3629;
v_3625:
    goto v_3636;
v_3632:
    v_3641 = stack[0];
    v_3642 = qcdr(v_3641);
    goto v_3633;
v_3634:
    v_3641 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3635;
v_3636:
    goto v_3632;
v_3633:
    goto v_3634;
v_3635:
    v_3641 = cons(v_3642, v_3641);
    env = stack[-2];
    fn = elt(env, 3); // mk!*sq
    v_3642 = (*qfn1(fn))(fn, v_3641);
    env = stack[-2];
    goto v_3626;
v_3627:
    v_3641 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_3628;
v_3629:
    goto v_3625;
v_3626:
    goto v_3627;
v_3628:
    v_3641 = list2(v_3642, v_3641);
    env = stack[-2];
    fn = elt(env, 4); // simpexpt
    v_3641 = (*qfn1(fn))(fn, v_3641);
    env = stack[-2];
    goto v_3612;
v_3613:
    goto v_3609;
v_3610:
    goto v_3611;
v_3612:
    {
        LispObject v_3646 = stack[-1];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_3646, v_3641);
    }
    v_3641 = nil;
    return onevalue(v_3641);
}



// Code for canonsq

static LispObject CC_canonsq(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3802, v_3803, v_3804;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3565);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_3565;
// end of prologue
    goto v_3575;
v_3571:
    v_3802 = stack[-2];
    v_3803 = qcdr(v_3802);
    goto v_3572;
v_3573:
    v_3802 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3574;
v_3575:
    goto v_3571;
v_3572:
    goto v_3573;
v_3574:
    if (v_3803 == v_3802) goto v_3569;
    else goto v_3570;
v_3569:
    v_3802 = stack[-2];
    goto v_3568;
v_3570:
    v_3802 = stack[-2];
    v_3802 = qcar(v_3802);
    if (v_3802 == nil) goto v_3580;
    else goto v_3581;
v_3580:
    goto v_3589;
v_3585:
    v_3803 = nil;
    goto v_3586;
v_3587:
    v_3802 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3588;
v_3589:
    goto v_3585;
v_3586:
    goto v_3587;
v_3588:
    return cons(v_3803, v_3802);
v_3581:
    stack[-1] = nil;
    v_3802 = qvalue(elt(env, 1)); // asymplis!*
    if (v_3802 == nil) goto v_3601;
    goto v_3609;
v_3605:
    goto v_3615;
v_3611:
    v_3802 = stack[-2];
    v_3803 = qcar(v_3802);
    goto v_3612;
v_3613:
    v_3802 = stack[-2];
    v_3802 = qcdr(v_3802);
    goto v_3614;
v_3615:
    goto v_3611;
v_3612:
    goto v_3613;
v_3614:
    fn = elt(env, 5); // gcdf
    v_3803 = (*qfn2(fn))(fn, v_3803, v_3802);
    env = stack[-4];
    stack[-3] = v_3803;
    goto v_3606;
v_3607:
    v_3802 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3608;
v_3609:
    goto v_3605;
v_3606:
    goto v_3607;
v_3608:
    if (v_3803 == v_3802) goto v_3601;
    goto v_3626;
v_3622:
    goto v_3632;
v_3628:
    v_3802 = stack[-2];
    v_3803 = qcar(v_3802);
    goto v_3629;
v_3630:
    v_3802 = stack[-3];
    goto v_3631;
v_3632:
    goto v_3628;
v_3629:
    goto v_3630;
v_3631:
    fn = elt(env, 6); // quotf!-fail
    stack[0] = (*qfn2(fn))(fn, v_3803, v_3802);
    env = stack[-4];
    goto v_3623;
v_3624:
    goto v_3641;
v_3637:
    v_3802 = stack[-2];
    v_3803 = qcdr(v_3802);
    goto v_3638;
v_3639:
    v_3802 = stack[-3];
    goto v_3640;
v_3641:
    goto v_3637;
v_3638:
    goto v_3639;
v_3640:
    fn = elt(env, 6); // quotf!-fail
    v_3802 = (*qfn2(fn))(fn, v_3803, v_3802);
    env = stack[-4];
    goto v_3625;
v_3626:
    goto v_3622;
v_3623:
    goto v_3624;
v_3625:
    v_3802 = cons(stack[0], v_3802);
    env = stack[-4];
    stack[-2] = v_3802;
    goto v_3599;
v_3601:
v_3599:
    v_3802 = stack[-2];
    v_3802 = qcdr(v_3802);
    fn = elt(env, 7); // lnc
    v_3802 = (*qfn1(fn))(fn, v_3802);
    env = stack[-4];
    stack[-3] = v_3802;
    goto v_3656;
v_3652:
    v_3803 = stack[-3];
    goto v_3653;
v_3654:
    v_3802 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3655;
v_3656:
    goto v_3652;
v_3653:
    goto v_3654;
v_3655:
    if (v_3803 == v_3802) goto v_3650;
    else goto v_3651;
v_3650:
    v_3802 = stack[-2];
    goto v_3597;
v_3651:
    v_3802 = stack[-3];
    if (!consp(v_3802)) goto v_3660;
    else goto v_3661;
v_3660:
    v_3802 = stack[-3];
    v_3802 = Lminusp(nil, v_3802);
    env = stack[-4];
    if (v_3802 == nil) goto v_3666;
    goto v_3674;
v_3670:
    v_3802 = stack[-2];
    v_3802 = qcar(v_3802);
    fn = elt(env, 8); // negf
    stack[0] = (*qfn1(fn))(fn, v_3802);
    env = stack[-4];
    goto v_3671;
v_3672:
    v_3802 = stack[-2];
    v_3802 = qcdr(v_3802);
    fn = elt(env, 8); // negf
    v_3802 = (*qfn1(fn))(fn, v_3802);
    env = stack[-4];
    goto v_3673;
v_3674:
    goto v_3670;
v_3671:
    goto v_3672;
v_3673:
    v_3802 = cons(stack[0], v_3802);
    env = stack[-4];
    stack[-2] = v_3802;
    v_3802 = stack[-3];
    v_3802 = negate(v_3802);
    env = stack[-4];
    stack[-3] = v_3802;
    goto v_3664;
v_3666:
    goto v_3664;
v_3664:
    goto v_3649;
v_3661:
    goto v_3693;
v_3689:
    v_3802 = stack[-3];
    v_3802 = qcar(v_3802);
    if (!symbolp(v_3802)) v_3803 = nil;
    else { v_3803 = qfastgets(v_3802);
           if (v_3803 != nil) { v_3803 = elt(v_3803, 30); // minusp
#ifdef RECORD_GET
             if (v_3803 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v_3803 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v_3803 == SPID_NOPROP) v_3803 = nil; }}
#endif
    goto v_3690;
v_3691:
    v_3802 = stack[-3];
    goto v_3692;
v_3693:
    goto v_3689;
v_3690:
    goto v_3691;
v_3692:
    v_3802 = Lapply1(nil, v_3803, v_3802);
    env = stack[-4];
    if (v_3802 == nil) goto v_3687;
    goto v_3703;
v_3699:
    v_3802 = stack[-2];
    v_3802 = qcar(v_3802);
    fn = elt(env, 8); // negf
    stack[0] = (*qfn1(fn))(fn, v_3802);
    env = stack[-4];
    goto v_3700;
v_3701:
    v_3802 = stack[-2];
    v_3802 = qcdr(v_3802);
    fn = elt(env, 8); // negf
    v_3802 = (*qfn1(fn))(fn, v_3802);
    env = stack[-4];
    goto v_3702;
v_3703:
    goto v_3699;
v_3700:
    goto v_3701;
v_3702:
    v_3802 = cons(stack[0], v_3802);
    env = stack[-4];
    stack[-2] = v_3802;
    goto v_3717;
v_3711:
    goto v_3723;
v_3719:
    v_3802 = stack[-3];
    v_3803 = qcar(v_3802);
    goto v_3720;
v_3721:
    v_3802 = elt(env, 2); // difference
    goto v_3722;
v_3723:
    goto v_3719;
v_3720:
    goto v_3721;
v_3722:
    stack[0] = get(v_3803, v_3802);
    env = stack[-4];
    goto v_3712;
v_3713:
    goto v_3732;
v_3728:
    v_3802 = stack[-3];
    v_3802 = qcar(v_3802);
    if (!symbolp(v_3802)) v_3803 = nil;
    else { v_3803 = qfastgets(v_3802);
           if (v_3803 != nil) { v_3803 = elt(v_3803, 34); // i2d
#ifdef RECORD_GET
             if (v_3803 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_3803 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_3803 == SPID_NOPROP) v_3803 = nil; }}
#endif
    goto v_3729;
v_3730:
    v_3802 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3731;
v_3732:
    goto v_3728;
v_3729:
    goto v_3730;
v_3731:
    v_3803 = Lapply1(nil, v_3803, v_3802);
    env = stack[-4];
    goto v_3714;
v_3715:
    v_3802 = stack[-3];
    goto v_3716;
v_3717:
    goto v_3711;
v_3712:
    goto v_3713;
v_3714:
    goto v_3715;
v_3716:
    v_3802 = Lapply2(nil, 3, stack[0], v_3803, v_3802);
    env = stack[-4];
    stack[-3] = v_3802;
    goto v_3649;
v_3687:
v_3649:
    v_3802 = stack[-3];
    if (is_number(v_3802)) goto v_3745;
    goto v_3752;
v_3748:
    v_3803 = qvalue(elt(env, 3)); // dmode!*
    goto v_3749;
v_3750:
    v_3802 = elt(env, 4); // unitsfn
    goto v_3751;
v_3752:
    goto v_3748;
v_3749:
    goto v_3750;
v_3751:
    v_3802 = get(v_3803, v_3802);
    env = stack[-4];
    stack[-1] = v_3802;
    goto v_3743;
v_3745:
    v_3802 = nil;
    goto v_3743;
    v_3802 = nil;
v_3743:
    if (v_3802 == nil) goto v_3741;
    goto v_3765;
v_3759:
    v_3804 = stack[-1];
    goto v_3760;
v_3761:
    v_3803 = stack[-2];
    goto v_3762;
v_3763:
    v_3802 = stack[-3];
    goto v_3764;
v_3765:
    goto v_3759;
v_3760:
    goto v_3761;
v_3762:
    goto v_3763;
v_3764:
        return Lapply2(nil, 3, v_3804, v_3803, v_3802);
v_3741:
    v_3802 = qvalue(elt(env, 3)); // dmode!*
    if (!symbolp(v_3802)) v_3802 = nil;
    else { v_3802 = qfastgets(v_3802);
           if (v_3802 != nil) { v_3802 = elt(v_3802, 3); // field
#ifdef RECORD_GET
             if (v_3802 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_3802 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_3802 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_3802 == SPID_NOPROP) v_3802 = nil; else v_3802 = lisp_true; }}
#endif
    if (v_3802 == nil) goto v_3774;
    v_3802 = lisp_true;
    goto v_3772;
v_3774:
    v_3802 = stack[-3];
    if (!consp(v_3802)) goto v_3783;
    v_3802 = stack[-3];
    v_3802 = qcar(v_3802);
    if (!symbolp(v_3802)) v_3802 = nil;
    else { v_3802 = qfastgets(v_3802);
           if (v_3802 != nil) { v_3802 = elt(v_3802, 3); // field
#ifdef RECORD_GET
             if (v_3802 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_3802 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_3802 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_3802 == SPID_NOPROP) v_3802 = nil; else v_3802 = lisp_true; }}
#endif
    goto v_3781;
v_3783:
    v_3802 = nil;
    goto v_3781;
    v_3802 = nil;
v_3781:
    goto v_3772;
    v_3802 = nil;
v_3772:
    if (v_3802 == nil) goto v_3770;
    goto v_3796;
v_3792:
    v_3803 = stack[-3];
    goto v_3793;
v_3794:
    v_3802 = stack[-2];
    goto v_3795;
v_3796:
    goto v_3792;
v_3793:
    goto v_3794;
v_3795:
    {
        fn = elt(env, 9); // fieldconv
        return (*qfn2(fn))(fn, v_3803, v_3802);
    }
v_3770:
    v_3802 = stack[-2];
    goto v_3739;
    v_3802 = nil;
v_3739:
v_3597:
    goto v_3568;
    v_3802 = nil;
v_3568:
    return onevalue(v_3802);
}



// Code for rassoc

static LispObject CC_rassoc(LispObject env,
                         LispObject v_3565, LispObject v_3566)
{
    env = qenv(env);
    LispObject v_3594, v_3595, v_3596, v_3597;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3595 = v_3566;
    v_3596 = v_3565;
// end of prologue
v_3570:
    v_3594 = v_3595;
    if (!consp(v_3594)) goto v_3573;
    else goto v_3574;
v_3573:
    v_3594 = nil;
    goto v_3569;
v_3574:
    goto v_3583;
v_3579:
    v_3597 = v_3596;
    goto v_3580;
v_3581:
    v_3594 = v_3595;
    v_3594 = qcar(v_3594);
    v_3594 = qcdr(v_3594);
    goto v_3582;
v_3583:
    goto v_3579;
v_3580:
    goto v_3581;
v_3582:
    if (equal(v_3597, v_3594)) goto v_3577;
    else goto v_3578;
v_3577:
    v_3594 = v_3595;
    v_3594 = qcar(v_3594);
    goto v_3569;
v_3578:
    v_3594 = v_3595;
    v_3594 = qcdr(v_3594);
    v_3595 = v_3594;
    goto v_3570;
    v_3594 = nil;
v_3569:
    return onevalue(v_3594);
}



// Code for talp_atfp

static LispObject CC_talp_atfp(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3585, v_3586;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3565);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_3585 = v_3565;
// end of prologue
    v_3586 = v_3585;
    v_3586 = Lconsp(nil, v_3586);
    env = stack[0];
    if (v_3586 == nil) goto v_3569;
    else goto v_3570;
v_3569:
    v_3585 = nil;
    goto v_3568;
v_3570:
    goto v_3580;
v_3576:
    fn = elt(env, 2); // talp_op
    v_3585 = (*qfn1(fn))(fn, v_3585);
    env = stack[0];
    goto v_3577;
v_3578:
    v_3586 = elt(env, 1); // (neq equal)
    goto v_3579;
v_3580:
    goto v_3576;
v_3577:
    goto v_3578;
v_3579:
    v_3585 = Lmemq(nil, v_3585, v_3586);
    goto v_3568;
    v_3585 = nil;
v_3568:
    return onevalue(v_3585);
}



// Code for checktag

static LispObject CC_checktag(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3588, v_3589;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3565);
    }
// copy arguments values to proper place
    v_3588 = v_3565;
// end of prologue
    goto v_3577;
v_3573:
    v_3589 = qvalue(elt(env, 1)); // char
    goto v_3574;
v_3575:
    goto v_3576;
v_3577:
    goto v_3573;
v_3574:
    goto v_3575;
v_3576:
    if (equal(v_3589, v_3588)) goto v_3572;
    goto v_3585;
v_3581:
    v_3589 = elt(env, 2); // "Problem"
    goto v_3582;
v_3583:
    v_3588 = elt(env, 3); // "problem"
    goto v_3584;
v_3585:
    goto v_3581;
v_3582:
    goto v_3583;
v_3584:
    fn = elt(env, 4); // errorml
    v_3588 = (*qfn2(fn))(fn, v_3589, v_3588);
    goto v_3570;
v_3572:
v_3570:
    v_3588 = nil;
    return onevalue(v_3588);
}



// Code for reval1

static LispObject CC_reval1(LispObject env,
                         LispObject v_3565, LispObject v_3566)
{
    env = qenv(env);
    LispObject v_4055, v_4056, v_4057;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3565,v_3566);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_3566;
    stack[-2] = v_3565;
// end of prologue
    v_4055 = qvalue(elt(env, 1)); // !*revalp
    if (v_4055 == nil) goto v_3570;
    else goto v_3571;
v_3570:
    v_4055 = stack[-2];
    goto v_3569;
v_3571:
    v_4055 = qvalue(elt(env, 2)); // varstack!*
// Binding varstack!*
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 2, -3);
    qvalue(elt(env, 2)) = v_4055; // varstack!*
    v_4055 = stack[-2];
    if (v_4055 == nil) goto v_3584;
    else goto v_3585;
v_3584:
    v_4055 = nil;
    goto v_3581;
v_3585:
    v_4055 = stack[-2];
    v_4055 = Lstringp(nil, v_4055);
    env = stack[-4];
    if (v_4055 == nil) goto v_3589;
    v_4055 = stack[-2];
    goto v_3581;
v_3589:
    v_4055 = stack[-2];
    v_4055 = integerp(v_4055);
    if (v_4055 == nil) goto v_3594;
    v_4055 = qvalue(elt(env, 3)); // dmode!*
    if (!symbolp(v_4055)) v_4055 = nil;
    else { v_4055 = qfastgets(v_4055);
           if (v_4055 != nil) { v_4055 = elt(v_4055, 5); // convert
#ifdef RECORD_GET
             if (v_4055 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v_4055 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v_4055 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v_4055 == SPID_NOPROP) v_4055 = nil; else v_4055 = lisp_true; }}
#endif
    if (v_4055 == nil) goto v_3600;
    goto v_3608;
v_3604:
    v_4056 = stack[-2];
    goto v_3605;
v_3606:
    v_4055 = stack[-1];
    goto v_3607;
v_3608:
    goto v_3604;
v_3605:
    goto v_3606;
v_3607:
    fn = elt(env, 19); // reval2
    v_4055 = (*qfn2(fn))(fn, v_4056, v_4055);
    goto v_3598;
v_3600:
    v_4055 = stack[-2];
    goto v_3598;
    v_4055 = nil;
v_3598:
    goto v_3581;
v_3594:
    v_4055 = stack[-2];
    if (!consp(v_4055)) goto v_3614;
    else goto v_3615;
v_3614:
    v_4055 = qvalue(elt(env, 4)); // subfg!*
    if (v_4055 == nil) goto v_3619;
    else goto v_3620;
v_3619:
    v_4055 = stack[-2];
    goto v_3581;
v_3620:
    v_4055 = stack[-2];
    if (symbolp(v_4055)) goto v_3625;
    else goto v_3624;
v_3625:
    v_4055 = stack[-2];
    if (!symbolp(v_4055)) v_4055 = nil;
    else { v_4055 = qfastgets(v_4055);
           if (v_4055 != nil) { v_4055 = elt(v_4055, 4); // avalue
#ifdef RECORD_GET
             if (v_4055 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_4055 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_4055 == SPID_NOPROP) v_4055 = nil; }}
#endif
    stack[0] = v_4055;
    if (v_4055 == nil) goto v_3624;
    goto v_3638;
v_3634:
    v_4056 = stack[-2];
    goto v_3635;
v_3636:
    v_4055 = qvalue(elt(env, 2)); // varstack!*
    goto v_3637;
v_3638:
    goto v_3634;
v_3635:
    goto v_3636;
v_3637:
    v_4055 = Lmemq(nil, v_4056, v_4055);
    if (v_4055 == nil) goto v_3633;
    v_4055 = stack[-2];
    fn = elt(env, 20); // recursiveerror
    v_4055 = (*qfn1(fn))(fn, v_4055);
    env = stack[-4];
    goto v_3631;
v_3633:
    goto v_3651;
v_3647:
    v_4056 = stack[-2];
    goto v_3648;
v_3649:
    v_4055 = qvalue(elt(env, 2)); // varstack!*
    goto v_3650;
v_3651:
    goto v_3647;
v_3648:
    goto v_3649;
v_3650:
    v_4055 = cons(v_4056, v_4055);
    env = stack[-4];
    qvalue(elt(env, 2)) = v_4055; // varstack!*
    goto v_3663;
v_3659:
    v_4055 = stack[0];
    v_4056 = qcar(v_4055);
    goto v_3660;
v_3661:
    v_4055 = elt(env, 5); // evfn
    goto v_3662;
v_3663:
    goto v_3659;
v_3660:
    goto v_3661;
v_3662:
    v_4055 = get(v_4056, v_4055);
    env = stack[-4];
    v_4057 = v_4055;
    if (v_4055 == nil) goto v_3657;
    goto v_3674;
v_3668:
    goto v_3669;
v_3670:
    v_4056 = stack[-2];
    goto v_3671;
v_3672:
    v_4055 = stack[-1];
    goto v_3673;
v_3674:
    goto v_3668;
v_3669:
    goto v_3670;
v_3671:
    goto v_3672;
v_3673:
    v_4055 = Lapply2(nil, 3, v_4057, v_4056, v_4055);
    goto v_3655;
v_3657:
    goto v_3685;
v_3681:
    v_4055 = stack[0];
    v_4055 = qcdr(v_4055);
    v_4056 = qcar(v_4055);
    goto v_3682;
v_3683:
    v_4055 = stack[-1];
    goto v_3684;
v_3685:
    goto v_3681;
v_3682:
    goto v_3683;
v_3684:
    v_4055 = CC_reval1(elt(env, 0), v_4056, v_4055);
    goto v_3655;
    v_4055 = nil;
v_3655:
    goto v_3581;
v_3631:
    goto v_3618;
v_3624:
    goto v_3618;
v_3618:
    goto v_3583;
v_3615:
    v_4055 = stack[-2];
    v_4055 = qcar(v_4055);
    if (symbolp(v_4055)) goto v_3694;
    goto v_3706;
v_3702:
    v_4055 = stack[-2];
    v_4055 = qcar(v_4055);
    v_4056 = qcar(v_4055);
    goto v_3703;
v_3704:
    v_4055 = elt(env, 6); // structfn
    goto v_3705;
v_3706:
    goto v_3702;
v_3703:
    goto v_3704;
v_3705:
    v_4055 = get(v_4056, v_4055);
    env = stack[-4];
    stack[0] = v_4055;
    if (v_4055 == nil) goto v_3700;
    goto v_3716;
v_3712:
    goto v_3713;
v_3714:
    v_4055 = stack[-2];
    v_4055 = ncons(v_4055);
    env = stack[-4];
    goto v_3715;
v_3716:
    goto v_3712;
v_3713:
    goto v_3714;
v_3715:
    fn = elt(env, 21); // apply
    v_4055 = (*qfn2(fn))(fn, stack[0], v_4055);
    goto v_3581;
v_3700:
    goto v_3727;
v_3723:
    v_4056 = stack[-2];
    goto v_3724;
v_3725:
    v_4055 = lisp_true;
    goto v_3726;
v_3727:
    goto v_3723;
v_3724:
    goto v_3725;
v_3726:
    fn = elt(env, 22); // errpri2
    v_4055 = (*qfn2(fn))(fn, v_4056, v_4055);
    env = stack[-4];
    goto v_3698;
v_3698:
    goto v_3583;
v_3694:
    goto v_3736;
v_3732:
    v_4055 = stack[-2];
    v_4056 = qcar(v_4055);
    goto v_3733;
v_3734:
    v_4055 = elt(env, 7); // !*sq
    goto v_3735;
v_3736:
    goto v_3732;
v_3733:
    goto v_3734;
v_3735:
    if (v_4056 == v_4055) goto v_3730;
    else goto v_3731;
v_3730:
    v_4055 = stack[-2];
    v_4055 = qcdr(v_4055);
    v_4055 = qcdr(v_4055);
    v_4055 = qcar(v_4055);
    if (v_4055 == nil) goto v_3743;
    v_4055 = qvalue(elt(env, 8)); // !*resimp
    if (v_4055 == nil) goto v_3749;
    else goto v_3743;
v_3749:
    v_4055 = stack[-1];
    if (v_4055 == nil) goto v_3753;
    else goto v_3754;
v_3753:
    v_4055 = stack[-2];
    goto v_3752;
v_3754:
    v_4055 = stack[-2];
    v_4055 = qcdr(v_4055);
    v_4055 = qcar(v_4055);
    fn = elt(env, 23); // prepsqxx
    v_4055 = (*qfn1(fn))(fn, v_4055);
    goto v_3752;
    v_4055 = nil;
v_3752:
    goto v_3741;
v_3743:
    goto v_3770;
v_3766:
    v_4056 = stack[-2];
    goto v_3767;
v_3768:
    v_4055 = stack[-1];
    goto v_3769;
v_3770:
    goto v_3766;
v_3767:
    goto v_3768;
v_3769:
    fn = elt(env, 19); // reval2
    v_4055 = (*qfn2(fn))(fn, v_4056, v_4055);
    goto v_3741;
    v_4055 = nil;
v_3741:
    goto v_3581;
v_3731:
    v_4055 = stack[-2];
    v_4055 = qcar(v_4055);
    if (!symbolp(v_4055)) v_4055 = nil;
    else { v_4055 = qfastgets(v_4055);
           if (v_4055 != nil) { v_4055 = elt(v_4055, 39); // remember
#ifdef RECORD_GET
             if (v_4055 == SPID_NOPROP)
                record_get(elt(fastget_names, 39), 0),
                v_4055 = nil;
             else record_get(elt(fastget_names, 39), 1),
                v_4055 = lisp_true; }
           else record_get(elt(fastget_names, 39), 0); }
#else
             if (v_4055 == SPID_NOPROP) v_4055 = nil; else v_4055 = lisp_true; }}
#endif
    if (v_4055 == nil) goto v_3774;
    goto v_3783;
v_3779:
    v_4056 = stack[-2];
    goto v_3780;
v_3781:
    v_4055 = stack[-1];
    goto v_3782;
v_3783:
    goto v_3779;
v_3780:
    goto v_3781;
v_3782:
    fn = elt(env, 24); // rmmbreval
    v_4055 = (*qfn2(fn))(fn, v_4056, v_4055);
    goto v_3581;
v_3774:
    v_4055 = stack[-2];
    v_4055 = qcar(v_4055);
    if (!symbolp(v_4055)) v_4055 = nil;
    else { v_4055 = qfastgets(v_4055);
           if (v_4055 != nil) { v_4055 = elt(v_4055, 59); // opfn
#ifdef RECORD_GET
             if (v_4055 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v_4055 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v_4055 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v_4055 == SPID_NOPROP) v_4055 = nil; else v_4055 = lisp_true; }}
#endif
    if (v_4055 == nil) goto v_3787;
    goto v_3796;
v_3792:
    v_4055 = stack[-2];
    fn = elt(env, 25); // opfneval
    v_4056 = (*qfn1(fn))(fn, v_4055);
    env = stack[-4];
    goto v_3793;
v_3794:
    v_4055 = stack[-1];
    goto v_3795;
v_3796:
    goto v_3792;
v_3793:
    goto v_3794;
v_3795:
    v_4055 = CC_reval1(elt(env, 0), v_4056, v_4055);
    goto v_3581;
v_3787:
    v_4055 = stack[-2];
    v_4055 = qcar(v_4055);
    if (!symbolp(v_4055)) v_4055 = nil;
    else { v_4055 = qfastgets(v_4055);
           if (v_4055 != nil) { v_4055 = elt(v_4055, 45); // psopfn
#ifdef RECORD_GET
             if (v_4055 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v_4055 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v_4055 == SPID_NOPROP) v_4055 = nil; }}
#endif
    stack[0] = v_4055;
    if (v_4055 == nil) goto v_3801;
    goto v_3810;
v_3806:
    v_4056 = stack[0];
    goto v_3807;
v_3808:
    v_4055 = stack[-2];
    v_4055 = qcdr(v_4055);
    goto v_3809;
v_3810:
    goto v_3806;
v_3807:
    goto v_3808;
v_3809:
    v_4055 = Lapply1(nil, v_4056, v_4055);
    env = stack[-4];
    stack[-2] = v_4055;
    goto v_3823;
v_3819:
    v_4056 = stack[0];
    goto v_3820;
v_3821:
    v_4055 = elt(env, 9); // cleanupfn
    goto v_3822;
v_3823:
    goto v_3819;
v_3820:
    goto v_3821;
v_3822:
    v_4055 = get(v_4056, v_4055);
    env = stack[-4];
    stack[0] = v_4055;
    if (v_4055 == nil) goto v_3817;
    goto v_3833;
v_3827:
    v_4057 = stack[0];
    goto v_3828;
v_3829:
    v_4056 = stack[-2];
    goto v_3830;
v_3831:
    v_4055 = stack[-1];
    goto v_3832;
v_3833:
    goto v_3827;
v_3828:
    goto v_3829;
v_3830:
    goto v_3831;
v_3832:
    v_4055 = Lapply2(nil, 3, v_4057, v_4056, v_4055);
    stack[-2] = v_4055;
    goto v_3815;
v_3817:
v_3815:
    v_4055 = stack[-2];
    goto v_3581;
v_3801:
    v_4055 = stack[-2];
    v_4055 = qcar(v_4055);
    fn = elt(env, 26); // arrayp
    v_4055 = (*qfn1(fn))(fn, v_4055);
    env = stack[-4];
    if (v_4055 == nil) goto v_3839;
    goto v_3848;
v_3844:
    v_4055 = stack[-2];
    fn = elt(env, 27); // getelv
    v_4056 = (*qfn1(fn))(fn, v_4055);
    env = stack[-4];
    goto v_3845;
v_3846:
    v_4055 = stack[-1];
    goto v_3847;
v_3848:
    goto v_3844;
v_3845:
    goto v_3846;
v_3847:
    v_4055 = CC_reval1(elt(env, 0), v_4056, v_4055);
    goto v_3581;
v_3839:
v_3583:
    v_4055 = stack[-2];
    fn = elt(env, 28); // getrtype
    v_4055 = (*qfn1(fn))(fn, v_4055);
    env = stack[-4];
    stack[0] = v_4055;
    if (v_4055 == nil) goto v_3855;
    goto v_3867;
v_3863:
    v_4056 = stack[0];
    goto v_3864;
v_3865:
    v_4055 = elt(env, 5); // evfn
    goto v_3866;
v_3867:
    goto v_3863;
v_3864:
    goto v_3865;
v_3866:
    v_4055 = get(v_4056, v_4055);
    env = stack[-4];
    v_4057 = v_4055;
    if (v_4055 == nil) goto v_3861;
    goto v_3877;
v_3871:
    goto v_3872;
v_3873:
    v_4056 = stack[-2];
    goto v_3874;
v_3875:
    v_4055 = stack[-1];
    goto v_3876;
v_3877:
    goto v_3871;
v_3872:
    goto v_3873;
v_3874:
    goto v_3875;
v_3876:
    v_4055 = Lapply2(nil, 3, v_4057, v_4056, v_4055);
    goto v_3859;
v_3861:
    goto v_3890;
v_3884:
    stack[-2] = elt(env, 10); // alg
    goto v_3885;
v_3886:
    stack[-1] = (LispObject)1616+TAG_FIXNUM; // 101
    goto v_3887;
v_3888:
    goto v_3898;
v_3894:
    v_4056 = elt(env, 11); // "Missing evaluation for type"
    goto v_3895;
v_3896:
    v_4055 = stack[0];
    goto v_3897;
v_3898:
    goto v_3894;
v_3895:
    goto v_3896;
v_3897:
    v_4055 = list2(v_4056, v_4055);
    env = stack[-4];
    goto v_3889;
v_3890:
    goto v_3884;
v_3885:
    goto v_3886;
v_3887:
    goto v_3888;
v_3889:
    fn = elt(env, 29); // rerror
    v_4055 = (*qfnn(fn))(fn, 3, stack[-2], stack[-1], v_4055);
    goto v_3859;
    v_4055 = nil;
v_3859:
    goto v_3853;
v_3855:
    v_4055 = stack[-2];
    if (!consp(v_4055)) goto v_3906;
    v_4055 = stack[-2];
    v_4055 = qcdr(v_4055);
    if (!consp(v_4055)) goto v_3911;
    v_4055 = stack[-2];
    v_4055 = qcdr(v_4055);
    v_4055 = qcar(v_4055);
    fn = elt(env, 28); // getrtype
    v_4055 = (*qfn1(fn))(fn, v_4055);
    env = stack[-4];
    v_4057 = v_4055;
    if (v_4055 == nil) goto v_3916;
    else goto v_3917;
v_3916:
    v_4055 = nil;
    goto v_3915;
v_3917:
    goto v_3937;
v_3933:
    v_4056 = v_4057;
    goto v_3934;
v_3935:
    v_4055 = elt(env, 12); // list
    goto v_3936;
v_3937:
    goto v_3933;
v_3934:
    goto v_3935;
v_3936:
    if (v_4056 == v_4055) goto v_3931;
    else goto v_3932;
v_3931:
    v_4055 = stack[-2];
    v_4055 = qcdr(v_4055);
    v_4055 = qcdr(v_4055);
    goto v_3930;
v_3932:
    v_4055 = nil;
    goto v_3930;
    v_4055 = nil;
v_3930:
    if (v_4055 == nil) goto v_3927;
    else goto v_3928;
v_3927:
    goto v_3955;
v_3951:
    v_4056 = v_4057;
    goto v_3952;
v_3953:
    v_4055 = elt(env, 13); // aggregatefn
    goto v_3954;
v_3955:
    goto v_3951;
v_3952:
    goto v_3953;
v_3954:
    v_4055 = get(v_4056, v_4055);
    env = stack[-4];
    stack[0] = v_4055;
    if (v_4055 == nil) goto v_3948;
    else goto v_3949;
v_3948:
    v_4055 = nil;
    goto v_3947;
v_3949:
    goto v_3973;
v_3969:
    v_4056 = stack[0];
    goto v_3970;
v_3971:
    v_4055 = elt(env, 14); // matrixmap
    goto v_3972;
v_3973:
    goto v_3969;
v_3970:
    goto v_3971;
v_3972:
    if (v_4056 == v_4055) goto v_3968;
    v_4055 = lisp_true;
    goto v_3966;
v_3968:
    goto v_3984;
v_3980:
    v_4055 = stack[-2];
    v_4056 = qcar(v_4055);
    goto v_3981;
v_3982:
    v_4055 = elt(env, 15); // matmapfn
    goto v_3983;
v_3984:
    goto v_3980;
v_3981:
    goto v_3982;
v_3983:
    v_4055 = Lflagp(nil, v_4056, v_4055);
    env = stack[-4];
    goto v_3966;
    v_4055 = nil;
v_3966:
    if (v_4055 == nil) goto v_3964;
    goto v_3997;
v_3993:
    v_4055 = stack[-2];
    v_4056 = qcar(v_4055);
    goto v_3994;
v_3995:
    v_4055 = elt(env, 16); // boolean
    goto v_3996;
v_3997:
    goto v_3993;
v_3994:
    goto v_3995;
v_3996:
    v_4055 = Lflagp(nil, v_4056, v_4055);
    env = stack[-4];
    if (v_4055 == nil) goto v_3990;
    else goto v_3991;
v_3990:
    v_4055 = qvalue(elt(env, 17)); // !*listargs
    if (v_4055 == nil) goto v_4003;
    else goto v_4004;
v_4003:
    goto v_4011;
v_4007:
    v_4055 = stack[-2];
    v_4056 = qcar(v_4055);
    goto v_4008;
v_4009:
    v_4055 = elt(env, 18); // listargp
    goto v_4010;
v_4011:
    goto v_4007;
v_4008:
    goto v_4009;
v_4010:
    v_4055 = Lflagp(nil, v_4056, v_4055);
    env = stack[-4];
    v_4055 = (v_4055 == nil ? lisp_true : nil);
    goto v_4002;
v_4004:
    v_4055 = nil;
    goto v_4002;
    v_4055 = nil;
v_4002:
    goto v_3989;
v_3991:
    v_4055 = nil;
    goto v_3989;
    v_4055 = nil;
v_3989:
    goto v_3962;
v_3964:
    v_4055 = nil;
    goto v_3962;
    v_4055 = nil;
v_3962:
    goto v_3947;
    v_4055 = nil;
v_3947:
    goto v_3926;
v_3928:
    v_4055 = nil;
    goto v_3926;
    v_4055 = nil;
v_3926:
    goto v_3915;
    v_4055 = nil;
v_3915:
    goto v_3909;
v_3911:
    v_4055 = nil;
    goto v_3909;
    v_4055 = nil;
v_3909:
    goto v_3904;
v_3906:
    v_4055 = nil;
    goto v_3904;
    v_4055 = nil;
v_3904:
    if (v_4055 == nil) goto v_3902;
    goto v_4041;
v_4035:
    v_4057 = stack[0];
    goto v_4036;
v_4037:
    v_4056 = stack[-2];
    goto v_4038;
v_4039:
    v_4055 = stack[-1];
    goto v_4040;
v_4041:
    goto v_4035;
v_4036:
    goto v_4037;
v_4038:
    goto v_4039;
v_4040:
    v_4055 = Lapply2(nil, 3, v_4057, v_4056, v_4055);
    goto v_3853;
v_3902:
    goto v_4052;
v_4048:
    v_4056 = stack[-2];
    goto v_4049;
v_4050:
    v_4055 = stack[-1];
    goto v_4051;
v_4052:
    goto v_4048;
v_4049:
    goto v_4050;
v_4051:
    fn = elt(env, 19); // reval2
    v_4055 = (*qfn2(fn))(fn, v_4056, v_4055);
    goto v_3853;
    v_4055 = nil;
v_3853:
v_3581:
    ;}  // end of a binding scope
    goto v_3569;
    v_4055 = nil;
v_3569:
    return onevalue(v_4055);
}



// Code for vevmaptozero1

static LispObject CC_vevmaptozero1(LispObject env,
                         LispObject v_3565, LispObject v_3566)
{
    env = qenv(env);
    LispObject v_3589, v_3590;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3565,v_3566);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_3589 = v_3566;
    stack[0] = v_3565;
// end of prologue
v_3570:
    v_3590 = stack[0];
    if (v_3590 == nil) goto v_3573;
    else goto v_3574;
v_3573:
    goto v_3569;
v_3574:
    v_3590 = stack[0];
    v_3590 = qcdr(v_3590);
    stack[0] = v_3590;
    goto v_3586;
v_3582:
    v_3590 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3583;
v_3584:
    goto v_3585;
v_3586:
    goto v_3582;
v_3583:
    goto v_3584;
v_3585:
    v_3589 = cons(v_3590, v_3589);
    env = stack[-1];
    goto v_3570;
    v_3589 = nil;
v_3569:
    return onevalue(v_3589);
}



// Code for physopsim!*

static LispObject CC_physopsimH(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3591, v_3592;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3565);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_3565;
// end of prologue
    goto v_3576;
v_3572:
    v_3592 = stack[0];
    goto v_3573;
v_3574:
    v_3591 = elt(env, 1); // !:dn!:
    goto v_3575;
v_3576:
    goto v_3572;
v_3573:
    goto v_3574;
v_3575:
    if (!consp(v_3592)) goto v_3570;
    v_3592 = qcar(v_3592);
    if (v_3592 == v_3591) goto v_3569;
    else goto v_3570;
v_3569:
    v_3591 = stack[0];
    fn = elt(env, 2); // simp
    v_3591 = (*qfn1(fn))(fn, v_3591);
    env = stack[-1];
    {
        fn = elt(env, 3); // prepsq
        return (*qfn1(fn))(fn, v_3591);
    }
v_3570:
    v_3591 = stack[0];
    fn = elt(env, 4); // !*physopp!*
    v_3591 = (*qfn1(fn))(fn, v_3591);
    env = stack[-1];
    if (v_3591 == nil) goto v_3583;
    v_3591 = stack[0];
    {
        fn = elt(env, 5); // physopsm!*
        return (*qfn1(fn))(fn, v_3591);
    }
v_3583:
    v_3591 = stack[0];
    goto v_3568;
    v_3591 = nil;
v_3568:
    return onevalue(v_3591);
}



// Code for rread

static LispObject CC_rread(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3569;
    LispObject fn;
    argcheck(nargs, 0, "rread");
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
    v_3569 = elt(env, 1); // " '"
    fn = elt(env, 2); // prin2x
    v_3569 = (*qfn1(fn))(fn, v_3569);
    env = stack[0];
    {
        fn = elt(env, 3); // rread1
        return (*qfnn(fn))(fn, 0);
    }
}



// Code for reval2

static LispObject CC_reval2(LispObject env,
                         LispObject v_3565, LispObject v_3566)
{
    env = qenv(env);
    LispObject v_3606, v_3607;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3565,v_3566);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3566;
    v_3607 = v_3565;
// end of prologue
    v_3606 = stack[0];
    if (v_3606 == nil) goto v_3572;
    else goto v_3570;
v_3572:
    v_3606 = qvalue(elt(env, 1)); // !*combineexpt
    if (v_3606 == nil) goto v_3577;
    else goto v_3578;
v_3577:
    v_3606 = lisp_true;
    goto v_3576;
v_3578:
    v_3606 = qvalue(elt(env, 2)); // dmode!*
    goto v_3576;
    v_3606 = nil;
v_3576:
    if (v_3606 == nil) goto v_3574;
    else goto v_3570;
v_3574:
    goto v_3571;
v_3570:
    goto v_3589;
v_3585:
    v_3606 = v_3607;
    fn = elt(env, 4); // simp!*
    v_3607 = (*qfn1(fn))(fn, v_3606);
    env = stack[-2];
    goto v_3586;
v_3587:
    v_3606 = stack[0];
    goto v_3588;
v_3589:
    goto v_3585;
v_3586:
    goto v_3587;
v_3588:
    {
        fn = elt(env, 5); // !*q2a1
        return (*qfn2(fn))(fn, v_3607, v_3606);
    }
v_3571:
    goto v_3600;
v_3596:
    v_3606 = nil;
// Binding !*mcd
// FLUIDBIND: reloadenv=2 litvec-offset=3 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 3, -1);
    qvalue(elt(env, 3)) = v_3606; // !*mcd
    v_3606 = v_3607;
    fn = elt(env, 4); // simp!*
    v_3607 = (*qfn1(fn))(fn, v_3606);
    env = stack[-2];
    ;}  // end of a binding scope
    goto v_3597;
v_3598:
    v_3606 = stack[0];
    goto v_3599;
v_3600:
    goto v_3596;
v_3597:
    goto v_3598;
v_3599:
    {
        fn = elt(env, 5); // !*q2a1
        return (*qfn2(fn))(fn, v_3607, v_3606);
    }
    v_3606 = nil;
    return onevalue(v_3606);
}



// Code for divd

static LispObject CC_divd(LispObject env,
                         LispObject v_3565, LispObject v_3566)
{
    env = qenv(env);
    LispObject v_3679, v_3680, v_3681;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3565,v_3566);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_3566;
    stack[-2] = v_3565;
// end of prologue
    stack[-3] = nil;
v_3571:
    v_3679 = stack[-1];
    if (v_3679 == nil) goto v_3574;
    else goto v_3575;
v_3574:
    v_3679 = stack[-2];
    if (v_3679 == nil) goto v_3579;
    else goto v_3580;
v_3579:
    goto v_3587;
v_3583:
    stack[0] = stack[-3];
    goto v_3584;
v_3585:
    goto v_3596;
v_3590:
    v_3681 = elt(env, 1); // poly
    goto v_3591;
v_3592:
    v_3680 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3593;
v_3594:
    v_3679 = elt(env, 2); // "0/0 formed"
    goto v_3595;
v_3596:
    goto v_3590;
v_3591:
    goto v_3592;
v_3593:
    goto v_3594;
v_3595:
    fn = elt(env, 4); // rerror
    v_3679 = (*qfnn(fn))(fn, 3, v_3681, v_3680, v_3679);
    env = stack[-4];
    goto v_3586;
v_3587:
    goto v_3583;
v_3584:
    goto v_3585;
v_3586:
    {
        LispObject v_3686 = stack[0];
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(fn, v_3686, v_3679);
    }
v_3580:
    goto v_3607;
v_3603:
    stack[0] = stack[-3];
    goto v_3604;
v_3605:
    goto v_3616;
v_3610:
    v_3681 = elt(env, 1); // poly
    goto v_3611;
v_3612:
    v_3680 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_3613;
v_3614:
    v_3679 = elt(env, 3); // "Zero divisor"
    goto v_3615;
v_3616:
    goto v_3610;
v_3611:
    goto v_3612;
v_3613:
    goto v_3614;
v_3615:
    fn = elt(env, 4); // rerror
    v_3679 = (*qfnn(fn))(fn, 3, v_3681, v_3680, v_3679);
    env = stack[-4];
    goto v_3606;
v_3607:
    goto v_3603;
v_3604:
    goto v_3605;
v_3606:
    {
        LispObject v_3687 = stack[0];
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(fn, v_3687, v_3679);
    }
    goto v_3573;
v_3575:
    v_3679 = stack[-2];
    if (v_3679 == nil) goto v_3620;
    else goto v_3621;
v_3620:
    v_3679 = stack[-3];
    {
        fn = elt(env, 5); // nreverse
        return (*qfn1(fn))(fn, v_3679);
    }
v_3621:
    v_3679 = stack[-2];
    if (!consp(v_3679)) goto v_3629;
    else goto v_3630;
v_3629:
    v_3679 = lisp_true;
    goto v_3628;
v_3630:
    v_3679 = stack[-2];
    v_3679 = qcar(v_3679);
    v_3679 = (consp(v_3679) ? nil : lisp_true);
    goto v_3628;
    v_3679 = nil;
v_3628:
    if (v_3679 == nil) goto v_3626;
    goto v_3643;
v_3639:
    stack[0] = stack[-3];
    goto v_3640;
v_3641:
    goto v_3650;
v_3646:
    v_3680 = stack[-2];
    goto v_3647;
v_3648:
    v_3679 = stack[-1];
    goto v_3649;
v_3650:
    goto v_3646;
v_3647:
    goto v_3648;
v_3649:
    fn = elt(env, 6); // divdm
    v_3679 = (*qfn2(fn))(fn, v_3680, v_3679);
    env = stack[-4];
    goto v_3642;
v_3643:
    goto v_3639;
v_3640:
    goto v_3641;
v_3642:
    {
        LispObject v_3688 = stack[0];
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(fn, v_3688, v_3679);
    }
v_3626:
    goto v_3662;
v_3656:
    v_3679 = stack[-2];
    v_3679 = qcar(v_3679);
    stack[0] = qcar(v_3679);
    goto v_3657;
v_3658:
    goto v_3671;
v_3667:
    v_3679 = stack[-2];
    v_3679 = qcar(v_3679);
    v_3680 = qcdr(v_3679);
    goto v_3668;
v_3669:
    v_3679 = stack[-1];
    goto v_3670;
v_3671:
    goto v_3667;
v_3668:
    goto v_3669;
v_3670:
    v_3680 = CC_divd(elt(env, 0), v_3680, v_3679);
    env = stack[-4];
    goto v_3659;
v_3660:
    v_3679 = stack[-3];
    goto v_3661;
v_3662:
    goto v_3656;
v_3657:
    goto v_3658;
v_3659:
    goto v_3660;
v_3661:
    v_3679 = acons(stack[0], v_3680, v_3679);
    env = stack[-4];
    stack[-3] = v_3679;
    v_3679 = stack[-2];
    v_3679 = qcdr(v_3679);
    stack[-2] = v_3679;
    goto v_3571;
v_3573:
    v_3679 = nil;
    return onevalue(v_3679);
}



// Code for bas_make1

static LispObject CC_bas_make1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3592, v_3593;
    LispObject fn;
    LispObject v_3567, v_3566, v_3565;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "bas_make1");
    va_start(aa, nargs);
    v_3565 = va_arg(aa, LispObject);
    v_3566 = va_arg(aa, LispObject);
    v_3567 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_3567,v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_3565,v_3566,v_3567);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_3567;
    stack[-3] = v_3566;
    v_3592 = v_3565;
// end of prologue
    goto v_3578;
v_3570:
    stack[-4] = v_3592;
    goto v_3571;
v_3572:
    stack[-1] = stack[-3];
    goto v_3573;
v_3574:
    v_3592 = stack[-3];
    stack[0] = Llength(nil, v_3592);
    env = stack[-5];
    goto v_3575;
v_3576:
    goto v_3588;
v_3584:
    v_3592 = stack[-3];
    fn = elt(env, 1); // dp_ecart
    v_3593 = (*qfn1(fn))(fn, v_3592);
    env = stack[-5];
    goto v_3585;
v_3586:
    v_3592 = stack[-2];
    goto v_3587;
v_3588:
    goto v_3584;
v_3585:
    goto v_3586;
v_3587:
    v_3592 = list2(v_3593, v_3592);
    goto v_3577;
v_3578:
    goto v_3570;
v_3571:
    goto v_3572;
v_3573:
    goto v_3574;
v_3575:
    goto v_3576;
v_3577:
    {
        LispObject v_3599 = stack[-4];
        LispObject v_3600 = stack[-1];
        LispObject v_3601 = stack[0];
        return list3star(v_3599, v_3600, v_3601, v_3592);
    }
}



// Code for adddummy1a

static LispObject CC_adddummy1a(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3627, v_3628;
    LispObject fn;
    LispObject v_3567, v_3566, v_3565;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "adddummy1a");
    va_start(aa, nargs);
    v_3565 = va_arg(aa, LispObject);
    v_3566 = va_arg(aa, LispObject);
    v_3567 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_3567,v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_3565,v_3566,v_3567);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_3567;
    v_3627 = v_3566;
    stack[-2] = v_3565;
// end of prologue
v_3572:
    v_3628 = v_3627;
    if (v_3628 == nil) goto v_3575;
    else goto v_3576;
v_3575:
    v_3627 = stack[-1];
    goto v_3571;
v_3576:
    v_3628 = v_3627;
    v_3628 = qcdr(v_3628);
    stack[-3] = v_3628;
    goto v_3588;
v_3584:
    v_3628 = stack[-1];
    if (v_3628 == nil) goto v_3591;
    else goto v_3592;
v_3591:
    v_3628 = stack[-2];
    v_3628 = qcar(v_3628);
    stack[0] = v_3628;
    goto v_3590;
v_3592:
    v_3628 = stack[-1];
    v_3628 = qcar(v_3628);
    stack[0] = v_3628;
    goto v_3590;
    stack[0] = nil;
v_3590:
    goto v_3585;
v_3586:
    goto v_3605;
v_3601:
    goto v_3611;
v_3607:
    v_3628 = qcar(v_3627);
    goto v_3608;
v_3609:
    v_3627 = stack[-2];
    v_3627 = qcdr(v_3627);
    goto v_3610;
v_3611:
    goto v_3607;
v_3608:
    goto v_3609;
v_3610:
    fn = elt(env, 1); // pappl_pv
    v_3628 = (*qfn2(fn))(fn, v_3628, v_3627);
    env = stack[-4];
    goto v_3602;
v_3603:
    v_3627 = stack[-1];
    if (v_3627 == nil) goto v_3618;
    else goto v_3619;
v_3618:
    v_3627 = stack[-1];
    goto v_3617;
v_3619:
    v_3627 = stack[-1];
    v_3627 = qcdr(v_3627);
    goto v_3617;
    v_3627 = nil;
v_3617:
    goto v_3604;
v_3605:
    goto v_3601;
v_3602:
    goto v_3603;
v_3604:
    fn = elt(env, 2); // insert_pv
    v_3627 = (*qfn2(fn))(fn, v_3628, v_3627);
    env = stack[-4];
    goto v_3587;
v_3588:
    goto v_3584;
v_3585:
    goto v_3586;
v_3587:
    v_3627 = cons(stack[0], v_3627);
    env = stack[-4];
    stack[-1] = v_3627;
    v_3627 = stack[-3];
    goto v_3572;
    v_3627 = nil;
v_3571:
    return onevalue(v_3627);
}



// Code for yyreadch

static LispObject CC_yyreadch(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3626, v_3627, v_3628;
    argcheck(nargs, 0, "yyreadch");
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
    v_3626 = qvalue(elt(env, 1)); // lex_peek_char
    if (v_3626 == nil) goto v_3569;
    v_3626 = qvalue(elt(env, 1)); // lex_peek_char
    qvalue(elt(env, 2)) = v_3626; // lex_char
    v_3626 = nil;
    qvalue(elt(env, 1)) = v_3626; // lex_peek_char
    v_3626 = qvalue(elt(env, 2)); // lex_char
    goto v_3567;
v_3569:
    v_3626 = Lreadch(nil, 0);
    env = stack[0];
    qvalue(elt(env, 2)) = v_3626; // lex_char
    goto v_3585;
v_3581:
    v_3627 = qvalue(elt(env, 2)); // lex_char
    goto v_3582;
v_3583:
    v_3626 = qvalue(elt(env, 3)); // !$eol!$
    goto v_3584;
v_3585:
    goto v_3581;
v_3582:
    goto v_3583;
v_3584:
    if (equal(v_3627, v_3626)) goto v_3579;
    else goto v_3580;
v_3579:
    v_3626 = qvalue(elt(env, 4)); // which_line
    v_3626 = add1(v_3626);
    env = stack[0];
    qvalue(elt(env, 4)) = v_3626; // which_line
    goto v_3578;
v_3580:
v_3578:
    goto v_3598;
v_3594:
    v_3627 = qvalue(elt(env, 2)); // lex_char
    goto v_3595;
v_3596:
    v_3626 = qvalue(elt(env, 5)); // !$eof!$
    goto v_3597;
v_3598:
    goto v_3594;
v_3595:
    goto v_3596;
v_3597:
    if (equal(v_3627, v_3626)) goto v_3593;
    v_3626 = qvalue(elt(env, 6)); // last64p
    v_3626 = add1(v_3626);
    env = stack[0];
    qvalue(elt(env, 6)) = v_3626; // last64p
    goto v_3611;
v_3607:
    v_3627 = qvalue(elt(env, 6)); // last64p
    goto v_3608;
v_3609:
    v_3626 = (LispObject)1024+TAG_FIXNUM; // 64
    goto v_3610;
v_3611:
    goto v_3607;
v_3608:
    goto v_3609;
v_3610:
    if (v_3627 == v_3626) goto v_3605;
    else goto v_3606;
v_3605:
    v_3626 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 6)) = v_3626; // last64p
    goto v_3604;
v_3606:
v_3604:
    goto v_3621;
v_3615:
    v_3628 = qvalue(elt(env, 7)); // last64
    goto v_3616;
v_3617:
    v_3627 = qvalue(elt(env, 6)); // last64p
    goto v_3618;
v_3619:
    v_3626 = qvalue(elt(env, 2)); // lex_char
    goto v_3620;
v_3621:
    goto v_3615;
v_3616:
    goto v_3617;
v_3618:
    goto v_3619;
v_3620:
    *(LispObject *)((char *)v_3628 + (CELL-TAG_VECTOR) + (((intptr_t)v_3627-TAG_FIXNUM)/(16/CELL))) = v_3626;
    goto v_3591;
v_3593:
v_3591:
    v_3626 = qvalue(elt(env, 2)); // lex_char
    goto v_3567;
    v_3626 = nil;
v_3567:
    return onevalue(v_3626);
}



// Code for lispapply

static LispObject CC_lispapply(LispObject env,
                         LispObject v_3565, LispObject v_3566)
{
    env = qenv(env);
    LispObject v_3601, v_3602, v_3603;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3565,v_3566);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_3602 = v_3566;
    v_3603 = v_3565;
// end of prologue
    v_3601 = v_3603;
    if (!consp(v_3601)) goto v_3571;
    goto v_3580;
v_3574:
    stack[-1] = elt(env, 1); // rlisp
    goto v_3575;
v_3576:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_3577;
v_3578:
    goto v_3588;
v_3584:
    v_3601 = elt(env, 2); // "Apply called with non-id arg"
    goto v_3585;
v_3586:
    v_3602 = v_3603;
    goto v_3587;
v_3588:
    goto v_3584;
v_3585:
    goto v_3586;
v_3587:
    v_3601 = list2(v_3601, v_3602);
    env = stack[-2];
    goto v_3579;
v_3580:
    goto v_3574;
v_3575:
    goto v_3576;
v_3577:
    goto v_3578;
v_3579:
    {
        LispObject v_3606 = stack[-1];
        LispObject v_3607 = stack[0];
        fn = elt(env, 3); // rerror
        return (*qfnn(fn))(fn, 3, v_3606, v_3607, v_3601);
    }
v_3571:
    goto v_3598;
v_3594:
    v_3601 = v_3603;
    goto v_3595;
v_3596:
    goto v_3597;
v_3598:
    goto v_3594;
v_3595:
    goto v_3596;
v_3597:
    {
        fn = elt(env, 4); // apply
        return (*qfn2(fn))(fn, v_3601, v_3602);
    }
    v_3601 = nil;
    return onevalue(v_3601);
}



// Code for cdarx

static LispObject CC_cdarx(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3576, v_3577;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3565);
    }
// copy arguments values to proper place
    v_3576 = v_3565;
// end of prologue
    goto v_3572;
v_3568:
    v_3577 = v_3576;
    goto v_3569;
v_3570:
    v_3576 = elt(env, 1); // cdar
    goto v_3571;
v_3572:
    goto v_3568;
v_3569:
    goto v_3570;
v_3571:
    fn = elt(env, 2); // carx
    v_3576 = (*qfn2(fn))(fn, v_3577, v_3576);
    v_3576 = qcdr(v_3576);
    return onevalue(v_3576);
}



// Code for diff

static LispObject CC_diff(LispObject env,
                         LispObject v_3565, LispObject v_3566)
{
    env = qenv(env);
    LispObject v_3669, v_3670;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3565,v_3566);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_3566;
    stack[-3] = v_3565;
// end of prologue
    stack[-4] = nil;
v_3572:
    v_3669 = stack[-3];
    if (!consp(v_3669)) goto v_3581;
    else goto v_3582;
v_3581:
    v_3669 = lisp_true;
    goto v_3580;
v_3582:
    v_3669 = stack[-3];
    v_3669 = qcar(v_3669);
    v_3669 = (consp(v_3669) ? nil : lisp_true);
    goto v_3580;
    v_3669 = nil;
v_3580:
    if (v_3669 == nil) goto v_3578;
    goto v_3573;
v_3578:
    goto v_3595;
v_3591:
    goto v_3601;
v_3597:
    goto v_3607;
v_3603:
    goto v_3614;
v_3610:
    v_3669 = stack[-3];
    v_3669 = qcar(v_3669);
    v_3670 = qcar(v_3669);
    goto v_3611;
v_3612:
    v_3669 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3613;
v_3614:
    goto v_3610;
v_3611:
    goto v_3612;
v_3613:
    v_3669 = cons(v_3670, v_3669);
    env = stack[-5];
    stack[0] = ncons(v_3669);
    env = stack[-5];
    goto v_3604;
v_3605:
    goto v_3624;
v_3620:
    v_3669 = stack[-3];
    v_3669 = qcar(v_3669);
    v_3670 = qcdr(v_3669);
    goto v_3621;
v_3622:
    v_3669 = stack[-2];
    goto v_3623;
v_3624:
    goto v_3620;
v_3621:
    goto v_3622;
v_3623:
    v_3669 = CC_diff(elt(env, 0), v_3670, v_3669);
    env = stack[-5];
    goto v_3606;
v_3607:
    goto v_3603;
v_3604:
    goto v_3605;
v_3606:
    fn = elt(env, 1); // multf
    stack[-1] = (*qfn2(fn))(fn, stack[0], v_3669);
    env = stack[-5];
    goto v_3598;
v_3599:
    goto v_3634;
v_3630:
    v_3669 = stack[-3];
    v_3669 = qcar(v_3669);
    stack[0] = qcdr(v_3669);
    goto v_3631;
v_3632:
    goto v_3643;
v_3639:
    v_3669 = stack[-3];
    v_3669 = qcar(v_3669);
    v_3670 = qcar(v_3669);
    goto v_3640;
v_3641:
    v_3669 = stack[-2];
    goto v_3642;
v_3643:
    goto v_3639;
v_3640:
    goto v_3641;
v_3642:
    fn = elt(env, 2); // diffp1
    v_3669 = (*qfn2(fn))(fn, v_3670, v_3669);
    env = stack[-5];
    goto v_3633;
v_3634:
    goto v_3630;
v_3631:
    goto v_3632;
v_3633:
    fn = elt(env, 1); // multf
    v_3669 = (*qfn2(fn))(fn, stack[0], v_3669);
    env = stack[-5];
    goto v_3600;
v_3601:
    goto v_3597;
v_3598:
    goto v_3599;
v_3600:
    fn = elt(env, 3); // addf
    v_3670 = (*qfn2(fn))(fn, stack[-1], v_3669);
    env = stack[-5];
    goto v_3592;
v_3593:
    v_3669 = stack[-4];
    goto v_3594;
v_3595:
    goto v_3591;
v_3592:
    goto v_3593;
v_3594:
    v_3669 = cons(v_3670, v_3669);
    env = stack[-5];
    stack[-4] = v_3669;
    v_3669 = stack[-3];
    v_3669 = qcdr(v_3669);
    stack[-3] = v_3669;
    goto v_3572;
v_3573:
    v_3669 = nil;
    v_3670 = v_3669;
v_3574:
    v_3669 = stack[-4];
    if (v_3669 == nil) goto v_3654;
    else goto v_3655;
v_3654:
    v_3669 = v_3670;
    goto v_3571;
v_3655:
    goto v_3663;
v_3659:
    v_3669 = stack[-4];
    v_3669 = qcar(v_3669);
    goto v_3660;
v_3661:
    goto v_3662;
v_3663:
    goto v_3659;
v_3660:
    goto v_3661;
v_3662:
    fn = elt(env, 3); // addf
    v_3669 = (*qfn2(fn))(fn, v_3669, v_3670);
    env = stack[-5];
    v_3670 = v_3669;
    v_3669 = stack[-4];
    v_3669 = qcdr(v_3669);
    stack[-4] = v_3669;
    goto v_3574;
v_3571:
    return onevalue(v_3669);
}



// Code for talp_smupdknowl1

static LispObject CC_talp_smupdknowl1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3645, v_3646, v_3647;
    LispObject fn;
    LispObject v_3568, v_3567, v_3566, v_3565;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "talp_smupdknowl1");
    va_start(aa, nargs);
    v_3565 = va_arg(aa, LispObject);
    v_3566 = va_arg(aa, LispObject);
    v_3567 = va_arg(aa, LispObject);
    v_3568 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_3568,v_3567,v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_3565,v_3566,v_3567,v_3568);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_3568;
    stack[-1] = v_3567;
    stack[-2] = v_3566;
    v_3645 = v_3565;
// end of prologue
    goto v_3582;
v_3578:
    v_3646 = v_3645;
    goto v_3579;
v_3580:
    v_3645 = elt(env, 1); // or
    goto v_3581;
v_3582:
    goto v_3578;
v_3579:
    goto v_3580;
v_3581:
    if (v_3646 == v_3645) goto v_3576;
    else goto v_3577;
v_3576:
    v_3645 = stack[-2];
    fn = elt(env, 3); // rl_negateat
    v_3645 = (*qfn1(fn))(fn, v_3645);
    env = stack[-4];
    stack[-3] = v_3645;
    v_3645 = stack[-2];
    goto v_3575;
v_3577:
    v_3645 = stack[-2];
    stack[-3] = v_3645;
    v_3645 = stack[-2];
    fn = elt(env, 3); // rl_negateat
    v_3645 = (*qfn1(fn))(fn, v_3645);
    env = stack[-4];
    goto v_3575;
v_3575:
    goto v_3603;
v_3599:
    v_3646 = v_3645;
    goto v_3600;
v_3601:
    v_3645 = stack[-1];
    goto v_3602;
v_3603:
    goto v_3599;
v_3600:
    goto v_3601;
v_3602:
    v_3645 = Lassoc(nil, v_3646, v_3645);
    if (v_3645 == nil) goto v_3598;
    v_3645 = elt(env, 2); // false
    goto v_3573;
v_3598:
    goto v_3617;
v_3613:
    v_3646 = stack[-3];
    goto v_3614;
v_3615:
    v_3645 = stack[-1];
    goto v_3616;
v_3617:
    goto v_3613;
v_3614:
    goto v_3615;
v_3616:
    fn = elt(env, 4); // talp_chkknowl
    v_3645 = (*qfn2(fn))(fn, v_3646, v_3645);
    env = stack[-4];
    if (v_3645 == nil) goto v_3611;
    v_3645 = elt(env, 2); // false
    goto v_3573;
v_3611:
    goto v_3629;
v_3625:
    v_3646 = stack[-3];
    goto v_3626;
v_3627:
    v_3645 = stack[-1];
    goto v_3628;
v_3629:
    goto v_3625;
v_3626:
    goto v_3627;
v_3628:
    v_3645 = Lassoc(nil, v_3646, v_3645);
    if (v_3645 == nil) goto v_3624;
    v_3645 = stack[-1];
    goto v_3573;
v_3624:
    goto v_3641;
v_3635:
    v_3647 = stack[-3];
    goto v_3636;
v_3637:
    v_3646 = stack[0];
    goto v_3638;
v_3639:
    v_3645 = stack[-1];
    goto v_3640;
v_3641:
    goto v_3635;
v_3636:
    goto v_3637;
v_3638:
    goto v_3639;
v_3640:
    v_3645 = acons(v_3647, v_3646, v_3645);
v_3573:
    return onevalue(v_3645);
}



// Code for subs2f1

static LispObject CC_subs2f1(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_4190, v_4191, v_4192, v_4193, v_4194;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3565);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_3565;
// end of prologue
    v_4190 = stack[-8];
    if (!consp(v_4190)) goto v_3573;
    else goto v_3574;
v_3573:
    v_4190 = lisp_true;
    goto v_3572;
v_3574:
    v_4190 = stack[-8];
    v_4190 = qcar(v_4190);
    v_4190 = (consp(v_4190) ? nil : lisp_true);
    goto v_3572;
    v_4190 = nil;
v_3572:
    if (v_4190 == nil) goto v_3570;
    v_4190 = stack[-8];
    {
        fn = elt(env, 10); // !*d2q
        return (*qfn1(fn))(fn, v_4190);
    }
v_3570:
    stack[-2] = nil;
v_3595:
    v_4190 = nil;
    stack[-4] = v_4190;
    v_4190 = stack[-8];
    v_4190 = qcar(v_4190);
    v_4190 = qcar(v_4190);
    v_4190 = qcar(v_4190);
    stack[-9] = v_4190;
    goto v_3617;
v_3613:
    v_4191 = nil;
    goto v_3614;
v_3615:
    v_4190 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3616;
v_3617:
    goto v_3613;
v_3614:
    goto v_3615;
v_3616:
    v_4190 = cons(v_4191, v_4190);
    env = stack[-10];
    stack[-3] = v_4190;
v_3596:
    v_4190 = stack[-8];
    if (v_4190 == nil) goto v_3626;
    else goto v_3627;
v_3626:
    v_4190 = lisp_true;
    goto v_3625;
v_3627:
    goto v_3636;
v_3632:
    goto v_3642;
v_3638:
    v_4191 = stack[-8];
    goto v_3639;
v_3640:
    v_4190 = stack[-9];
    goto v_3641;
v_3642:
    goto v_3638;
v_3639:
    goto v_3640;
v_3641:
    fn = elt(env, 11); // degr
    v_4191 = (*qfn2(fn))(fn, v_4191, v_4190);
    env = stack[-10];
    goto v_3633;
v_3634:
    v_4190 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3635;
v_3636:
    goto v_3632;
v_3633:
    goto v_3634;
v_3635:
    v_4190 = (v_4191 == v_4190 ? lisp_true : nil);
    goto v_3625;
    v_4190 = nil;
v_3625:
    if (v_4190 == nil) goto v_3623;
    goto v_3597;
v_3623:
    goto v_3652;
v_3648:
    v_4190 = stack[-8];
    v_4191 = qcar(v_4190);
    goto v_3649;
v_3650:
    v_4190 = stack[-4];
    goto v_3651;
v_3652:
    goto v_3648;
v_3649:
    goto v_3650;
v_3651:
    v_4190 = cons(v_4191, v_4190);
    env = stack[-10];
    stack[-4] = v_4190;
    v_4190 = stack[-8];
    v_4190 = qcdr(v_4190);
    stack[-8] = v_4190;
    goto v_3596;
v_3597:
    v_4190 = qvalue(elt(env, 1)); // powlis!*
    stack[-5] = v_4190;
v_3598:
    v_4190 = stack[-5];
    if (v_4190 == nil) goto v_3661;
    else goto v_3662;
v_3661:
    goto v_3599;
v_3662:
    goto v_3670;
v_3666:
    v_4190 = stack[-4];
    v_4190 = qcar(v_4190);
    v_4190 = qcar(v_4190);
    v_4191 = qcar(v_4190);
    goto v_3667;
v_3668:
    v_4190 = stack[-5];
    v_4190 = qcar(v_4190);
    v_4190 = qcar(v_4190);
    goto v_3669;
v_3670:
    goto v_3666;
v_3667:
    goto v_3668;
v_3669:
    if (equal(v_4191, v_4190)) goto v_3664;
    else goto v_3665;
v_3664:
    goto v_3685;
v_3679:
    v_4190 = stack[-4];
    v_4190 = qcar(v_4190);
    v_4192 = qcar(v_4190);
    goto v_3680;
v_3681:
    v_4190 = stack[-5];
    v_4190 = qcar(v_4190);
    v_4190 = qcdr(v_4190);
    v_4191 = qcar(v_4190);
    goto v_3682;
v_3683:
    v_4190 = stack[-5];
    v_4190 = qcar(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcar(v_4190);
    goto v_3684;
v_3685:
    goto v_3679;
v_3680:
    goto v_3681;
v_3682:
    goto v_3683;
v_3684:
    fn = elt(env, 12); // subs2p
    v_4190 = (*qfnn(fn))(fn, 3, v_4192, v_4191, v_4190);
    env = stack[-10];
    stack[-6] = v_4190;
    goto v_3605;
v_3665:
    goto v_3710;
v_3706:
    v_4191 = stack[-9];
    goto v_3707;
v_3708:
    v_4190 = elt(env, 2); // expt
    goto v_3709;
v_3710:
    goto v_3706;
v_3707:
    goto v_3708;
v_3709:
    if (!consp(v_4191)) goto v_3704;
    v_4191 = qcar(v_4191);
    if (v_4191 == v_4190) goto v_3703;
    else goto v_3704;
v_3703:
    goto v_3721;
v_3717:
    v_4190 = stack[-9];
    v_4190 = qcdr(v_4190);
    v_4191 = qcar(v_4190);
    goto v_3718;
v_3719:
    v_4190 = stack[-5];
    v_4190 = qcar(v_4190);
    v_4190 = qcar(v_4190);
    goto v_3720;
v_3721:
    goto v_3717;
v_3718:
    goto v_3719;
v_3720:
    if (equal(v_4191, v_4190)) goto v_3715;
    else goto v_3716;
v_3715:
    goto v_3737;
v_3733:
    v_4190 = stack[-9];
    v_4190 = qcdr(v_4190);
    v_4190 = qcdr(v_4190);
    v_4191 = qcar(v_4190);
    goto v_3734;
v_3735:
    v_4190 = elt(env, 3); // quotient
    goto v_3736;
v_3737:
    goto v_3733;
v_3734:
    goto v_3735;
v_3736:
    if (!consp(v_4191)) goto v_3731;
    v_4191 = qcar(v_4191);
    if (v_4191 == v_4190) goto v_3730;
    else goto v_3731;
v_3730:
    goto v_3751;
v_3747:
    v_4190 = stack[-9];
    v_4190 = qcdr(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcar(v_4190);
    v_4190 = qcdr(v_4190);
    v_4191 = qcar(v_4190);
    goto v_3748;
v_3749:
    v_4190 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3750;
v_3751:
    goto v_3747;
v_3748:
    goto v_3749;
v_3750:
    if (v_4191 == v_4190) goto v_3745;
    else goto v_3746;
v_3745:
    v_4190 = stack[-9];
    v_4190 = qcdr(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcar(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcar(v_4190);
    v_4190 = (is_number(v_4190) ? lisp_true : nil);
    goto v_3744;
v_3746:
    v_4190 = nil;
    goto v_3744;
    v_4190 = nil;
v_3744:
    goto v_3729;
v_3731:
    v_4190 = nil;
    goto v_3729;
    v_4190 = nil;
v_3729:
    goto v_3714;
v_3716:
    v_4190 = nil;
    goto v_3714;
    v_4190 = nil;
v_3714:
    goto v_3702;
v_3704:
    v_4190 = nil;
    goto v_3702;
    v_4190 = nil;
v_3702:
    if (v_4190 == nil) goto v_3700;
    goto v_3784;
v_3780:
    v_4190 = stack[-4];
    v_4190 = qcar(v_4190);
    v_4190 = qcar(v_4190);
    v_4191 = qcdr(v_4190);
    goto v_3781;
v_3782:
    v_4190 = stack[-9];
    v_4190 = qcdr(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcar(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcar(v_4190);
    goto v_3783;
v_3784:
    goto v_3780;
v_3781:
    goto v_3782;
v_3783:
    v_4190 = Ldivide(nil, v_4191, v_4190);
    env = stack[-10];
    stack[-7] = v_4190;
    goto v_3804;
v_3800:
    v_4190 = stack[-7];
    v_4191 = qcar(v_4190);
    goto v_3801;
v_3802:
    v_4190 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3803;
v_3804:
    goto v_3800;
v_3801:
    goto v_3802;
v_3803:
    if (v_4191 == v_4190) goto v_3799;
    goto v_3813;
v_3809:
    v_4190 = stack[-9];
    v_4190 = qcdr(v_4190);
    v_4190 = qcar(v_4190);
    fn = elt(env, 13); // simp
    v_4191 = (*qfn1(fn))(fn, v_4190);
    env = stack[-10];
    goto v_3810;
v_3811:
    v_4190 = stack[-7];
    v_4190 = qcar(v_4190);
    goto v_3812;
v_3813:
    goto v_3809;
v_3810:
    goto v_3811;
v_3812:
    fn = elt(env, 14); // exptsq
    v_4190 = (*qfn2(fn))(fn, v_4191, v_4190);
    env = stack[-10];
    stack[-6] = v_4190;
    goto v_3797;
v_3799:
    goto v_3827;
v_3823:
    v_4191 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3824;
v_3825:
    v_4190 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3826;
v_3827:
    goto v_3823;
v_3824:
    goto v_3825;
v_3826:
    v_4190 = cons(v_4191, v_4190);
    env = stack[-10];
    stack[-6] = v_4190;
    goto v_3797;
v_3797:
    goto v_3838;
v_3834:
    v_4190 = stack[-7];
    v_4191 = qcdr(v_4190);
    goto v_3835;
v_3836:
    v_4190 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3837;
v_3838:
    goto v_3834;
v_3835:
    goto v_3836;
v_3837:
    if (v_4191 == v_4190) goto v_3833;
// Binding alglist!*
// FLUIDBIND: reloadenv=10 litvec-offset=4 saveloc=1
{   bind_fluid_stack bind_fluid_var(-10, 4, -1);
    qvalue(elt(env, 4)) = nil; // alglist!*
// Binding dmode!*
// FLUIDBIND: reloadenv=10 litvec-offset=5 saveloc=0
{   bind_fluid_stack bind_fluid_var(-10, 5, 0);
    qvalue(elt(env, 5)) = nil; // dmode!*
    v_4190 = nil;
    v_4190 = ncons(v_4190);
    env = stack[-10];
    qvalue(elt(env, 4)) = v_4190; // alglist!*
    goto v_3854;
v_3850:
    v_4190 = stack[-7];
    v_4191 = qcdr(v_4190);
    goto v_3851;
v_3852:
    v_4190 = stack[-9];
    v_4190 = qcdr(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcar(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcar(v_4190);
    goto v_3853;
v_3854:
    goto v_3850;
v_3851:
    goto v_3852;
v_3853:
    v_4190 = cons(v_4191, v_4190);
    env = stack[-10];
    fn = elt(env, 15); // cancel
    v_4190 = (*qfn1(fn))(fn, v_4190);
    env = stack[-10];
    stack[-7] = v_4190;
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_3869;
v_3865:
    goto v_3875;
v_3871:
    goto v_3883;
v_3877:
    goto v_3889;
v_3885:
    v_4190 = stack[-9];
    v_4190 = qcdr(v_4190);
    v_4191 = qcar(v_4190);
    goto v_3886;
v_3887:
    v_4190 = stack[-7];
    v_4190 = qcar(v_4190);
    goto v_3888;
v_3889:
    goto v_3885;
v_3886:
    goto v_3887;
v_3888:
    v_4192 = cons(v_4191, v_4190);
    env = stack[-10];
    goto v_3878;
v_3879:
    v_4190 = stack[-5];
    v_4190 = qcar(v_4190);
    v_4190 = qcdr(v_4190);
    v_4191 = qcar(v_4190);
    goto v_3880;
v_3881:
    v_4190 = stack[-5];
    v_4190 = qcar(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcar(v_4190);
    goto v_3882;
v_3883:
    goto v_3877;
v_3878:
    goto v_3879;
v_3880:
    goto v_3881;
v_3882:
    fn = elt(env, 12); // subs2p
    v_4191 = (*qfnn(fn))(fn, 3, v_4192, v_4191, v_4190);
    env = stack[-10];
    goto v_3872;
v_3873:
    v_4190 = stack[-7];
    v_4190 = qcdr(v_4190);
    goto v_3874;
v_3875:
    goto v_3871;
v_3872:
    goto v_3873;
v_3874:
    fn = elt(env, 16); // raddsq
    v_4191 = (*qfn2(fn))(fn, v_4191, v_4190);
    env = stack[-10];
    goto v_3866;
v_3867:
    v_4190 = stack[-6];
    goto v_3868;
v_3869:
    goto v_3865;
v_3866:
    goto v_3867;
v_3868:
    fn = elt(env, 17); // multsq
    v_4190 = (*qfn2(fn))(fn, v_4191, v_4190);
    env = stack[-10];
    stack[-6] = v_4190;
    goto v_3831;
v_3833:
v_3831:
    goto v_3605;
v_3700:
    v_4190 = stack[-5];
    v_4190 = qcdr(v_4190);
    stack[-5] = v_4190;
    goto v_3598;
v_3599:
    v_4190 = qvalue(elt(env, 6)); // powlis1!*
    stack[-5] = v_4190;
v_3600:
    v_4190 = stack[-5];
    if (v_4190 == nil) goto v_3913;
    else goto v_3914;
v_3913:
    goto v_3601;
v_3914:
    goto v_3929;
v_3919:
    v_4190 = stack[-4];
    v_4190 = qcar(v_4190);
    v_4194 = qcar(v_4190);
    goto v_3920;
v_3921:
    v_4190 = stack[-5];
    v_4190 = qcar(v_4190);
    v_4193 = qcar(v_4190);
    goto v_3922;
v_3923:
    v_4190 = stack[-5];
    v_4190 = qcar(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcdr(v_4190);
    v_4192 = qcar(v_4190);
    goto v_3924;
v_3925:
    v_4190 = stack[-5];
    v_4190 = qcar(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcar(v_4190);
    v_4191 = qcar(v_4190);
    goto v_3926;
v_3927:
    v_4190 = stack[-5];
    v_4190 = qcar(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = qcar(v_4190);
    v_4190 = qcdr(v_4190);
    goto v_3928;
v_3929:
    goto v_3919;
v_3920:
    goto v_3921;
v_3922:
    goto v_3923;
v_3924:
    goto v_3925;
v_3926:
    goto v_3927;
v_3928:
    fn = elt(env, 18); // mtchp
    v_4190 = (*qfnn(fn))(fn, 5, v_4194, v_4193, v_4192, v_4191, v_4190);
    env = stack[-10];
    stack[-6] = v_4190;
    if (v_4190 == nil) goto v_3917;
    goto v_3605;
v_3917:
    v_4190 = stack[-5];
    v_4190 = qcdr(v_4190);
    stack[-5] = v_4190;
    goto v_3600;
v_3601:
    goto v_3966;
v_3962:
    v_4191 = stack[-9];
    goto v_3963;
v_3964:
    v_4190 = elt(env, 2); // expt
    goto v_3965;
v_3966:
    goto v_3962;
v_3963:
    goto v_3964;
v_3965:
    if (!consp(v_4191)) goto v_3960;
    v_4191 = qcar(v_4191);
    if (v_4191 == v_4190) goto v_3959;
    else goto v_3960;
v_3959:
    v_4190 = qvalue(elt(env, 7)); // !*structure
    v_4190 = (v_4190 == nil ? lisp_true : nil);
    goto v_3958;
v_3960:
    v_4190 = nil;
    goto v_3958;
    v_4190 = nil;
v_3958:
    if (v_4190 == nil) goto v_3956;
    goto v_3606;
v_3956:
    goto v_3979;
v_3975:
    goto v_3985;
v_3981:
    goto v_3991;
v_3987:
    goto v_3998;
v_3994:
    v_4190 = stack[-4];
    v_4190 = qcar(v_4190);
    v_4191 = qcar(v_4190);
    goto v_3995;
v_3996:
    v_4190 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3997;
v_3998:
    goto v_3994;
v_3995:
    goto v_3996;
v_3997:
    v_4190 = cons(v_4191, v_4190);
    env = stack[-10];
    v_4191 = ncons(v_4190);
    env = stack[-10];
    goto v_3988;
v_3989:
    v_4190 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3990;
v_3991:
    goto v_3987;
v_3988:
    goto v_3989;
v_3990:
    stack[0] = cons(v_4191, v_4190);
    env = stack[-10];
    goto v_3982;
v_3983:
    v_4190 = stack[-4];
    v_4190 = qcar(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = CC_subs2f1(elt(env, 0), v_4190);
    env = stack[-10];
    goto v_3984;
v_3985:
    goto v_3981;
v_3982:
    goto v_3983;
v_3984:
    fn = elt(env, 17); // multsq
    v_4191 = (*qfn2(fn))(fn, stack[0], v_4190);
    env = stack[-10];
    goto v_3976;
v_3977:
    v_4190 = stack[-3];
    goto v_3978;
v_3979:
    goto v_3975;
v_3976:
    goto v_3977;
v_3978:
    fn = elt(env, 19); // addsq
    v_4190 = (*qfn2(fn))(fn, v_4191, v_4190);
    env = stack[-10];
    stack[-3] = v_4190;
v_3602:
    v_4190 = stack[-4];
    v_4190 = qcdr(v_4190);
    stack[-4] = v_4190;
    v_4190 = stack[-4];
    if (v_4190 == nil) goto v_4014;
    goto v_3597;
v_4014:
v_3603:
    v_4190 = stack[-8];
    if (!consp(v_4190)) goto v_4022;
    else goto v_4023;
v_4022:
    v_4190 = lisp_true;
    goto v_4021;
v_4023:
    v_4190 = stack[-8];
    v_4190 = qcar(v_4190);
    v_4190 = (consp(v_4190) ? nil : lisp_true);
    goto v_4021;
    v_4190 = nil;
v_4021:
    if (v_4190 == nil) goto v_4019;
    v_4190 = stack[-8];
    fn = elt(env, 10); // !*d2q
    v_4190 = (*qfn1(fn))(fn, v_4190);
    env = stack[-10];
    stack[-4] = v_4190;
    goto v_3604;
v_4019:
    goto v_4038;
v_4034:
    v_4191 = stack[-3];
    goto v_4035;
v_4036:
    v_4190 = stack[-2];
    goto v_4037;
v_4038:
    goto v_4034;
v_4035:
    goto v_4036;
v_4037:
    v_4190 = cons(v_4191, v_4190);
    env = stack[-10];
    stack[-2] = v_4190;
    goto v_3595;
v_3604:
    v_4190 = qvalue(elt(env, 8)); // !*exp
    if (v_4190 == nil) goto v_4043;
    else goto v_4044;
v_4043:
    goto v_4051;
v_4047:
    v_4190 = stack[-4];
    v_4190 = qcar(v_4190);
    fn = elt(env, 20); // mkprod
    stack[0] = (*qfn1(fn))(fn, v_4190);
    env = stack[-10];
    goto v_4048;
v_4049:
    v_4190 = stack[-4];
    v_4190 = qcdr(v_4190);
    fn = elt(env, 20); // mkprod
    v_4190 = (*qfn1(fn))(fn, v_4190);
    env = stack[-10];
    goto v_4050;
v_4051:
    goto v_4047;
v_4048:
    goto v_4049;
v_4050:
    v_4190 = cons(stack[0], v_4190);
    env = stack[-10];
    stack[-4] = v_4190;
    goto v_4042;
v_4044:
v_4042:
    goto v_4063;
v_4059:
    v_4191 = stack[-3];
    goto v_4060;
v_4061:
    v_4190 = stack[-4];
    goto v_4062;
v_4063:
    goto v_4059;
v_4060:
    goto v_4061;
v_4062:
    fn = elt(env, 19); // addsq
    v_4190 = (*qfn2(fn))(fn, v_4191, v_4190);
    env = stack[-10];
    stack[-4] = v_4190;
    v_4190 = stack[-2];
    if (v_4190 == nil) goto v_4069;
    v_4190 = stack[-2];
    v_4190 = qcar(v_4190);
    stack[-3] = v_4190;
    v_4190 = stack[-2];
    v_4190 = qcdr(v_4190);
    stack[-2] = v_4190;
    goto v_3604;
v_4069:
    v_4190 = stack[-4];
    goto v_3594;
v_3605:
    goto v_4081;
v_4077:
    goto v_4087;
v_4083:
    stack[0] = stack[-6];
    goto v_4084;
v_4085:
    v_4190 = stack[-4];
    v_4190 = qcar(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = CC_subs2f1(elt(env, 0), v_4190);
    env = stack[-10];
    goto v_4086;
v_4087:
    goto v_4083;
v_4084:
    goto v_4085;
v_4086:
    fn = elt(env, 17); // multsq
    v_4191 = (*qfn2(fn))(fn, stack[0], v_4190);
    env = stack[-10];
    goto v_4078;
v_4079:
    v_4190 = stack[-3];
    goto v_4080;
v_4081:
    goto v_4077;
v_4078:
    goto v_4079;
v_4080:
    fn = elt(env, 19); // addsq
    v_4190 = (*qfn2(fn))(fn, v_4191, v_4190);
    env = stack[-10];
    stack[-3] = v_4190;
    goto v_3602;
v_3606:
    goto v_4106;
v_4102:
    v_4190 = stack[-4];
    v_4190 = qcar(v_4190);
    v_4190 = qcar(v_4190);
    v_4191 = qcdr(v_4190);
    goto v_4103;
v_4104:
    v_4190 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4105;
v_4106:
    goto v_4102;
v_4103:
    goto v_4104;
v_4105:
    if (v_4191 == v_4190) goto v_4100;
    else goto v_4101;
v_4100:
    goto v_4117;
v_4113:
    v_4190 = stack[-9];
    v_4190 = qcdr(v_4190);
    v_4191 = qcar(v_4190);
    goto v_4114;
v_4115:
    v_4190 = elt(env, 2); // expt
    goto v_4116;
v_4117:
    goto v_4113;
v_4114:
    goto v_4115;
v_4116:
    v_4190 = Leqcar(nil, v_4191, v_4190);
    env = stack[-10];
    v_4190 = (v_4190 == nil ? lisp_true : nil);
    goto v_4099;
v_4101:
    v_4190 = nil;
    goto v_4099;
    v_4190 = nil;
v_4099:
    if (v_4190 == nil) goto v_4097;
    goto v_4131;
v_4127:
    v_4191 = stack[-9];
    goto v_4128;
v_4129:
    v_4190 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_4130;
v_4131:
    goto v_4127;
v_4128:
    goto v_4129;
v_4130:
    fn = elt(env, 21); // mksq
    v_4190 = (*qfn2(fn))(fn, v_4191, v_4190);
    env = stack[-10];
    stack[-6] = v_4190;
    goto v_4095;
v_4097:
    goto v_4142;
v_4138:
    v_4190 = stack[-9];
    v_4190 = qcdr(v_4190);
    stack[0] = qcar(v_4190);
    goto v_4139;
v_4140:
    goto v_4153;
v_4147:
    v_4192 = elt(env, 9); // times
    goto v_4148;
v_4149:
    v_4190 = stack[-9];
    v_4190 = qcdr(v_4190);
    v_4190 = qcdr(v_4190);
    v_4191 = qcar(v_4190);
    goto v_4150;
v_4151:
    v_4190 = stack[-4];
    v_4190 = qcar(v_4190);
    v_4190 = qcar(v_4190);
    v_4190 = qcdr(v_4190);
    goto v_4152;
v_4153:
    goto v_4147;
v_4148:
    goto v_4149;
v_4150:
    goto v_4151;
v_4152:
    v_4190 = list3(v_4192, v_4191, v_4190);
    env = stack[-10];
    goto v_4141;
v_4142:
    goto v_4138;
v_4139:
    goto v_4140;
v_4141:
    v_4190 = list2(stack[0], v_4190);
    env = stack[-10];
    fn = elt(env, 22); // simpexpt
    v_4190 = (*qfn1(fn))(fn, v_4190);
    env = stack[-10];
    stack[-6] = v_4190;
    goto v_4095;
v_4095:
    goto v_4168;
v_4164:
    goto v_4174;
v_4170:
    stack[0] = stack[-6];
    goto v_4171;
v_4172:
    v_4190 = stack[-4];
    v_4190 = qcar(v_4190);
    v_4190 = qcdr(v_4190);
    v_4190 = CC_subs2f1(elt(env, 0), v_4190);
    env = stack[-10];
    goto v_4173;
v_4174:
    goto v_4170;
v_4171:
    goto v_4172;
v_4173:
    fn = elt(env, 17); // multsq
    v_4191 = (*qfn2(fn))(fn, stack[0], v_4190);
    env = stack[-10];
    goto v_4165;
v_4166:
    v_4190 = stack[-3];
    goto v_4167;
v_4168:
    goto v_4164;
v_4165:
    goto v_4166;
v_4167:
    fn = elt(env, 19); // addsq
    v_4190 = (*qfn2(fn))(fn, v_4191, v_4190);
    env = stack[-10];
    stack[-3] = v_4190;
    v_4190 = stack[-4];
    v_4190 = qcdr(v_4190);
    stack[-4] = v_4190;
    v_4190 = stack[-4];
    if (v_4190 == nil) goto v_4186;
    goto v_3606;
v_4186:
    goto v_3603;
    v_4190 = nil;
v_3594:
    goto v_3568;
    v_4190 = nil;
v_3568:
    return onevalue(v_4190);
}



// Code for genp

static LispObject CC_genp(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3588, v_3589, v_3590;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3565);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_3589 = v_3565;
// end of prologue
    v_3588 = v_3589;
    if (!consp(v_3588)) goto v_3569;
    else goto v_3570;
v_3569:
    goto v_3580;
v_3576:
    v_3590 = v_3589;
    goto v_3577;
v_3578:
    v_3588 = elt(env, 1); // gen
    goto v_3579;
v_3580:
    goto v_3576;
v_3577:
    goto v_3578;
v_3579:
    v_3588 = get(v_3590, v_3588);
    env = stack[0];
    if (v_3588 == nil) goto v_3574;
    else goto v_3573;
v_3574:
    v_3588 = v_3589;
    {
        fn = elt(env, 2); // mgenp
        return (*qfn1(fn))(fn, v_3588);
    }
v_3573:
    goto v_3568;
v_3570:
    v_3588 = nil;
    goto v_3568;
    v_3588 = nil;
v_3568:
    return onevalue(v_3588);
}



// Code for deg!*form

static LispObject CC_degHform(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3769, v_3770, v_3771;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3565);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3565;
// end of prologue
v_3564:
    v_3769 = stack[0];
    if (!consp(v_3769)) goto v_3569;
    else goto v_3570;
v_3569:
    v_3769 = stack[0];
    if (!symbolp(v_3769)) v_3769 = nil;
    else { v_3769 = qfastgets(v_3769);
           if (v_3769 != nil) { v_3769 = elt(v_3769, 29); // fdegree
#ifdef RECORD_GET
             if (v_3769 != SPID_NOPROP)
                record_get(elt(fastget_names, 29), 1);
             else record_get(elt(fastget_names, 29), 0),
                v_3769 = nil; }
           else record_get(elt(fastget_names, 29), 0); }
#else
             if (v_3769 == SPID_NOPROP) v_3769 = nil; }}
#endif
    v_3770 = v_3769;
    v_3769 = v_3770;
    if (v_3769 == nil) goto v_3578;
    v_3769 = v_3770;
    v_3769 = qcar(v_3769);
    goto v_3576;
v_3578:
    v_3769 = nil;
    goto v_3576;
    v_3769 = nil;
v_3576:
    goto v_3568;
v_3570:
    v_3769 = stack[0];
    v_3769 = qcar(v_3769);
    v_3771 = v_3769;
    v_3769 = v_3771;
    if (!symbolp(v_3769)) v_3769 = nil;
    else { v_3769 = qfastgets(v_3769);
           if (v_3769 != nil) { v_3769 = elt(v_3769, 16); // indexvar
#ifdef RECORD_GET
             if (v_3769 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v_3769 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v_3769 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v_3769 == SPID_NOPROP) v_3769 = nil; else v_3769 = lisp_true; }}
#endif
    if (v_3769 == nil) goto v_3593;
    goto v_3600;
v_3596:
    v_3769 = stack[0];
    v_3769 = qcdr(v_3769);
    v_3770 = Llength(nil, v_3769);
    goto v_3597;
v_3598:
    v_3769 = stack[0];
    v_3769 = qcar(v_3769);
    if (!symbolp(v_3769)) v_3769 = nil;
    else { v_3769 = qfastgets(v_3769);
           if (v_3769 != nil) { v_3769 = elt(v_3769, 25); // ifdegree
#ifdef RECORD_GET
             if (v_3769 != SPID_NOPROP)
                record_get(elt(fastget_names, 25), 1);
             else record_get(elt(fastget_names, 25), 0),
                v_3769 = nil; }
           else record_get(elt(fastget_names, 25), 0); }
#else
             if (v_3769 == SPID_NOPROP) v_3769 = nil; }}
#endif
    goto v_3599;
v_3600:
    goto v_3596;
v_3597:
    goto v_3598;
v_3599:
    v_3769 = Lassoc(nil, v_3770, v_3769);
    v_3770 = v_3769;
    v_3769 = v_3770;
    if (v_3769 == nil) goto v_3612;
    v_3769 = v_3770;
    v_3769 = qcdr(v_3769);
    goto v_3610;
v_3612:
    v_3769 = nil;
    goto v_3610;
    v_3769 = nil;
v_3610:
    goto v_3591;
v_3593:
    goto v_3625;
v_3621:
    v_3770 = v_3771;
    goto v_3622;
v_3623:
    v_3769 = elt(env, 1); // wedge
    goto v_3624;
v_3625:
    goto v_3621;
v_3622:
    goto v_3623;
v_3624:
    if (v_3770 == v_3769) goto v_3619;
    else goto v_3620;
v_3619:
    v_3769 = stack[0];
    v_3769 = qcdr(v_3769);
    {
        fn = elt(env, 11); // deg!*farg
        return (*qfn1(fn))(fn, v_3769);
    }
v_3620:
    goto v_3637;
v_3633:
    v_3770 = v_3771;
    goto v_3634;
v_3635:
    v_3769 = elt(env, 2); // d
    goto v_3636;
v_3637:
    goto v_3633;
v_3634:
    goto v_3635;
v_3636:
    if (v_3770 == v_3769) goto v_3631;
    else goto v_3632;
v_3631:
    goto v_3645;
v_3641:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3642;
v_3643:
    v_3769 = stack[0];
    v_3769 = qcdr(v_3769);
    v_3769 = qcar(v_3769);
    v_3769 = CC_degHform(elt(env, 0), v_3769);
    env = stack[-2];
    goto v_3644;
v_3645:
    goto v_3641;
v_3642:
    goto v_3643;
v_3644:
    {
        LispObject v_3774 = stack[-1];
        fn = elt(env, 12); // addd
        return (*qfn2(fn))(fn, v_3774, v_3769);
    }
v_3632:
    goto v_3657;
v_3653:
    v_3770 = v_3771;
    goto v_3654;
v_3655:
    v_3769 = elt(env, 3); // hodge
    goto v_3656;
v_3657:
    goto v_3653;
v_3654:
    goto v_3655;
v_3656:
    if (v_3770 == v_3769) goto v_3651;
    else goto v_3652;
v_3651:
    goto v_3665;
v_3661:
    stack[-1] = qvalue(elt(env, 4)); // dimex!*
    goto v_3662;
v_3663:
    v_3769 = stack[0];
    v_3769 = qcdr(v_3769);
    v_3769 = qcar(v_3769);
    v_3769 = CC_degHform(elt(env, 0), v_3769);
    env = stack[-2];
    fn = elt(env, 13); // negf
    v_3769 = (*qfn1(fn))(fn, v_3769);
    env = stack[-2];
    goto v_3664;
v_3665:
    goto v_3661;
v_3662:
    goto v_3663;
v_3664:
    {
        LispObject v_3775 = stack[-1];
        fn = elt(env, 14); // addf
        return (*qfn2(fn))(fn, v_3775, v_3769);
    }
v_3652:
    goto v_3678;
v_3674:
    v_3770 = v_3771;
    goto v_3675;
v_3676:
    v_3769 = elt(env, 5); // partdf
    goto v_3677;
v_3678:
    goto v_3674;
v_3675:
    goto v_3676;
v_3677:
    if (v_3770 == v_3769) goto v_3672;
    else goto v_3673;
v_3672:
    v_3769 = stack[0];
    v_3769 = qcdr(v_3769);
    v_3769 = qcdr(v_3769);
    if (v_3769 == nil) goto v_3684;
    v_3769 = nil;
    goto v_3682;
v_3684:
    v_3769 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_3682;
    v_3769 = nil;
v_3682:
    goto v_3591;
v_3673:
    goto v_3698;
v_3694:
    v_3770 = v_3771;
    goto v_3695;
v_3696:
    v_3769 = elt(env, 6); // liedf
    goto v_3697;
v_3698:
    goto v_3694;
v_3695:
    goto v_3696;
v_3697:
    if (v_3770 == v_3769) goto v_3692;
    else goto v_3693;
v_3692:
    v_3769 = stack[0];
    v_3769 = qcdr(v_3769);
    v_3769 = qcdr(v_3769);
    v_3769 = qcar(v_3769);
    stack[0] = v_3769;
    goto v_3564;
v_3693:
    goto v_3712;
v_3708:
    v_3770 = v_3771;
    goto v_3709;
v_3710:
    v_3769 = elt(env, 7); // innerprod
    goto v_3711;
v_3712:
    goto v_3708;
v_3709:
    goto v_3710;
v_3711:
    if (v_3770 == v_3769) goto v_3706;
    else goto v_3707;
v_3706:
    goto v_3720;
v_3716:
    stack[-1] = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_3717;
v_3718:
    v_3769 = stack[0];
    v_3769 = qcdr(v_3769);
    v_3769 = qcdr(v_3769);
    v_3769 = qcar(v_3769);
    v_3769 = CC_degHform(elt(env, 0), v_3769);
    env = stack[-2];
    goto v_3719;
v_3720:
    goto v_3716;
v_3717:
    goto v_3718;
v_3719:
    {
        LispObject v_3776 = stack[-1];
        fn = elt(env, 12); // addd
        return (*qfn2(fn))(fn, v_3776, v_3769);
    }
v_3707:
    goto v_3733;
v_3729:
    v_3770 = v_3771;
    goto v_3730;
v_3731:
    v_3769 = elt(env, 8); // (plus minus difference quotient)
    goto v_3732;
v_3733:
    goto v_3729;
v_3730:
    goto v_3731;
v_3732:
    v_3769 = Lmemq(nil, v_3770, v_3769);
    if (v_3769 == nil) goto v_3728;
    v_3769 = stack[0];
    v_3769 = qcdr(v_3769);
    v_3769 = qcar(v_3769);
    stack[0] = v_3769;
    goto v_3564;
v_3728:
    goto v_3747;
v_3743:
    v_3770 = v_3771;
    goto v_3744;
v_3745:
    v_3769 = elt(env, 9); // times
    goto v_3746;
v_3747:
    goto v_3743;
v_3744:
    goto v_3745;
v_3746:
    if (v_3770 == v_3769) goto v_3741;
    else goto v_3742;
v_3741:
    v_3769 = stack[0];
    v_3769 = qcdr(v_3769);
    {
        fn = elt(env, 11); // deg!*farg
        return (*qfn1(fn))(fn, v_3769);
    }
v_3742:
    goto v_3759;
v_3755:
    v_3770 = v_3771;
    goto v_3756;
v_3757:
    v_3769 = elt(env, 10); // !*sq
    goto v_3758;
v_3759:
    goto v_3755;
v_3756:
    goto v_3757;
v_3758:
    if (v_3770 == v_3769) goto v_3753;
    else goto v_3754;
v_3753:
    v_3769 = stack[0];
    fn = elt(env, 15); // simp!*
    v_3769 = (*qfn1(fn))(fn, v_3769);
    env = stack[-2];
    fn = elt(env, 16); // prepsq
    v_3769 = (*qfn1(fn))(fn, v_3769);
    env = stack[-2];
    stack[0] = v_3769;
    goto v_3564;
v_3754:
    v_3769 = nil;
    goto v_3591;
    v_3769 = nil;
v_3591:
    goto v_3568;
    v_3769 = nil;
v_3568:
    return onevalue(v_3769);
}



// Code for domain!*p

static LispObject CC_domainHp(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3597, v_3598;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3598 = v_3565;
// end of prologue
    v_3597 = v_3598;
    if (v_3597 == nil) goto v_3569;
    else goto v_3570;
v_3569:
    v_3597 = lisp_true;
    goto v_3568;
v_3570:
    v_3597 = v_3598;
    v_3597 = (is_number(v_3597) ? lisp_true : nil);
    if (v_3597 == nil) goto v_3577;
    else goto v_3576;
v_3577:
    v_3597 = v_3598;
    if (!consp(v_3597)) goto v_3583;
    goto v_3589;
v_3585:
    v_3597 = v_3598;
    v_3597 = qcar(v_3597);
    goto v_3586;
v_3587:
    v_3598 = qvalue(elt(env, 1)); // domainlist!*
    goto v_3588;
v_3589:
    goto v_3585;
v_3586:
    goto v_3587;
v_3588:
    v_3597 = Lmemq(nil, v_3597, v_3598);
    goto v_3581;
v_3583:
    v_3597 = nil;
    goto v_3581;
    v_3597 = nil;
v_3581:
v_3576:
    goto v_3568;
    v_3597 = nil;
v_3568:
    return onevalue(v_3597);
}



// Code for sfpx

static LispObject CC_sfpx(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3584, v_3585, v_3586, v_3587, v_3588;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3584 = v_3565;
// end of prologue
    goto v_3578;
v_3568:
    v_3588 = v_3584;
    goto v_3569;
v_3570:
    v_3587 = nil;
    goto v_3571;
v_3572:
    v_3586 = nil;
    goto v_3573;
v_3574:
    v_3585 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3575;
v_3576:
    v_3584 = lisp_true;
    goto v_3577;
v_3578:
    goto v_3568;
v_3569:
    goto v_3570;
v_3571:
    goto v_3572;
v_3573:
    goto v_3574;
v_3575:
    goto v_3576;
v_3577:
    {
        fn = elt(env, 1); // sfpx1
        return (*qfnn(fn))(fn, 5, v_3588, v_3587, v_3586, v_3585, v_3584);
    }
}



// Code for psum

static LispObject CC_psum(LispObject env,
                         LispObject v_3565, LispObject v_3566)
{
    env = qenv(env);
    LispObject v_3737, v_3738, v_3739;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3565,v_3566);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_3566;
    stack[-6] = v_3565;
// end of prologue
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v_3737 = stack[-6];
    if (v_3737 == nil) goto v_3579;
    else goto v_3580;
v_3579:
    v_3737 = stack[-5];
    stack[-2] = v_3737;
    goto v_3578;
v_3580:
    v_3737 = stack[-5];
    if (v_3737 == nil) goto v_3583;
    else goto v_3584;
v_3583:
    v_3737 = stack[-6];
    stack[-2] = v_3737;
    goto v_3578;
v_3584:
v_3591:
    v_3737 = stack[-5];
    if (v_3737 == nil) goto v_3594;
    v_3737 = stack[-1];
    if (v_3737 == nil) goto v_3598;
    else goto v_3594;
v_3598:
    goto v_3595;
v_3594:
    goto v_3590;
v_3595:
    v_3737 = stack[-5];
    v_3737 = qcar(v_3737);
    stack[0] = v_3737;
    v_3737 = stack[0];
    v_3737 = qcar(v_3737);
    stack[-7] = v_3737;
v_3607:
    v_3737 = stack[-6];
    if (v_3737 == nil) goto v_3610;
    goto v_3620;
v_3616:
    v_3738 = stack[-7];
    goto v_3617;
v_3618:
    v_3737 = stack[-6];
    v_3737 = qcar(v_3737);
    v_3737 = qcar(v_3737);
    goto v_3619;
v_3620:
    goto v_3616;
v_3617:
    goto v_3618;
v_3619:
    fn = elt(env, 1); // dless
    v_3737 = (*qfn2(fn))(fn, v_3738, v_3737);
    env = stack[-8];
    if (v_3737 == nil) goto v_3610;
    goto v_3611;
v_3610:
    goto v_3606;
v_3611:
    goto v_3631;
v_3627:
    v_3737 = stack[-6];
    v_3738 = qcar(v_3737);
    goto v_3628;
v_3629:
    v_3737 = stack[-3];
    goto v_3630;
v_3631:
    goto v_3627;
v_3628:
    goto v_3629;
v_3630:
    v_3737 = cons(v_3738, v_3737);
    env = stack[-8];
    stack[-3] = v_3737;
    v_3737 = stack[-6];
    v_3737 = qcdr(v_3737);
    stack[-6] = v_3737;
    goto v_3607;
v_3606:
    v_3737 = stack[-6];
    if (v_3737 == nil) goto v_3639;
    else goto v_3640;
v_3639:
    goto v_3647;
v_3643:
    v_3737 = stack[-3];
    v_3738 = Lreverse(nil, v_3737);
    env = stack[-8];
    goto v_3644;
v_3645:
    v_3737 = stack[-5];
    goto v_3646;
v_3647:
    goto v_3643;
v_3644:
    goto v_3645;
v_3646:
    v_3737 = Lappend(nil, v_3738, v_3737);
    env = stack[-8];
    stack[-2] = v_3737;
    v_3737 = lisp_true;
    stack[-1] = v_3737;
    goto v_3638;
v_3640:
    v_3737 = stack[-6];
    v_3737 = qcar(v_3737);
    v_3739 = v_3737;
    goto v_3664;
v_3660:
    v_3738 = stack[-7];
    goto v_3661;
v_3662:
    v_3737 = v_3739;
    v_3737 = qcar(v_3737);
    goto v_3663;
v_3664:
    goto v_3660;
v_3661:
    goto v_3662;
v_3663:
    if (equal(v_3738, v_3737)) goto v_3658;
    else goto v_3659;
v_3658:
    goto v_3673;
v_3669:
    v_3737 = v_3739;
    v_3738 = qcdr(v_3737);
    goto v_3670;
v_3671:
    v_3737 = stack[0];
    v_3737 = qcdr(v_3737);
    goto v_3672;
v_3673:
    goto v_3669;
v_3670:
    goto v_3671;
v_3672:
    fn = elt(env, 2); // csum
    v_3737 = (*qfn2(fn))(fn, v_3738, v_3737);
    env = stack[-8];
    stack[-4] = v_3737;
    goto v_3686;
v_3682:
    stack[0] = stack[-4];
    goto v_3683;
v_3684:
    fn = elt(env, 3); // c_zero
    v_3737 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_3685;
v_3686:
    goto v_3682;
v_3683:
    goto v_3684;
v_3685:
    if (equal(stack[0], v_3737)) goto v_3681;
    goto v_3696;
v_3690:
    v_3739 = stack[-7];
    goto v_3691;
v_3692:
    v_3738 = stack[-4];
    goto v_3693;
v_3694:
    v_3737 = stack[-3];
    goto v_3695;
v_3696:
    goto v_3690;
v_3691:
    goto v_3692;
v_3693:
    goto v_3694;
v_3695:
    v_3737 = acons(v_3739, v_3738, v_3737);
    env = stack[-8];
    stack[-3] = v_3737;
    goto v_3679;
v_3681:
v_3679:
    v_3737 = stack[-6];
    v_3737 = qcdr(v_3737);
    stack[-6] = v_3737;
    v_3737 = stack[-6];
    if (v_3737 == nil) goto v_3705;
    goto v_3703;
v_3705:
v_3703:
    goto v_3657;
v_3659:
    goto v_3717;
v_3713:
    v_3738 = stack[0];
    goto v_3714;
v_3715:
    v_3737 = stack[-3];
    goto v_3716;
v_3717:
    goto v_3713;
v_3714:
    goto v_3715;
v_3716:
    v_3737 = cons(v_3738, v_3737);
    env = stack[-8];
    stack[-3] = v_3737;
    goto v_3657;
v_3657:
    v_3737 = stack[-5];
    v_3737 = qcdr(v_3737);
    stack[-5] = v_3737;
    v_3737 = stack[-5];
    if (v_3737 == nil) goto v_3724;
    else goto v_3725;
v_3724:
    goto v_3732;
v_3728:
    v_3737 = stack[-3];
    v_3738 = Lreverse(nil, v_3737);
    env = stack[-8];
    goto v_3729;
v_3730:
    v_3737 = stack[-6];
    goto v_3731;
v_3732:
    goto v_3728;
v_3729:
    goto v_3730;
v_3731:
    v_3737 = Lappend(nil, v_3738, v_3737);
    env = stack[-8];
    stack[-2] = v_3737;
    goto v_3723;
v_3725:
v_3723:
    goto v_3638;
v_3638:
    goto v_3591;
v_3590:
    goto v_3578;
v_3578:
    v_3737 = stack[-2];
    return onevalue(v_3737);
}



// Code for gintequiv!:

static LispObject CC_gintequivT(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3586, v_3587, v_3588;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3587 = v_3565;
// end of prologue
    goto v_3575;
v_3571:
    v_3586 = v_3587;
    v_3586 = qcdr(v_3586);
    v_3588 = qcdr(v_3586);
    goto v_3572;
v_3573:
    v_3586 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3574;
v_3575:
    goto v_3571;
v_3572:
    goto v_3573;
v_3574:
    if (v_3588 == v_3586) goto v_3569;
    else goto v_3570;
v_3569:
    v_3586 = v_3587;
    v_3586 = qcdr(v_3586);
    v_3586 = qcar(v_3586);
    goto v_3568;
v_3570:
    v_3586 = nil;
    goto v_3568;
    v_3586 = nil;
v_3568:
    return onevalue(v_3586);
}



// Code for hevenp

static LispObject CC_hevenp(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3579, v_3580;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3565);
    }
// copy arguments values to proper place
    v_3580 = v_3565;
// end of prologue
    v_3579 = v_3580;
    if (v_3579 == nil) goto v_3569;
    else goto v_3570;
v_3569:
    v_3579 = lisp_true;
    goto v_3568;
v_3570:
    v_3579 = v_3580;
    v_3579 = qcdr(v_3579);
    v_3579 = CC_hevenp(elt(env, 0), v_3579);
    v_3579 = (v_3579 == nil ? lisp_true : nil);
    goto v_3568;
    v_3579 = nil;
v_3568:
    return onevalue(v_3579);
}



// Code for klistt

static LispObject CC_klistt(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3599, v_3600;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3565);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3565;
// end of prologue
    stack[-1] = nil;
v_3570:
    v_3599 = stack[0];
    if (!consp(v_3599)) goto v_3573;
    else goto v_3574;
v_3573:
    v_3599 = stack[-1];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_3599);
    }
v_3574:
    goto v_3585;
v_3581:
    v_3599 = stack[0];
    v_3599 = qcar(v_3599);
    v_3600 = qcar(v_3599);
    goto v_3582;
v_3583:
    v_3599 = stack[-1];
    goto v_3584;
v_3585:
    goto v_3581;
v_3582:
    goto v_3583;
v_3584:
    v_3599 = cons(v_3600, v_3599);
    env = stack[-2];
    stack[-1] = v_3599;
    goto v_3595;
v_3591:
    v_3600 = stack[0];
    goto v_3592;
v_3593:
    v_3599 = elt(env, 1); // list
    goto v_3594;
v_3595:
    goto v_3591;
v_3592:
    goto v_3593;
v_3594:
    fn = elt(env, 3); // carx
    v_3599 = (*qfn2(fn))(fn, v_3600, v_3599);
    env = stack[-2];
    v_3599 = qcdr(v_3599);
    stack[0] = v_3599;
    goto v_3570;
    v_3599 = nil;
    return onevalue(v_3599);
}



// Code for anform1

static LispObject CC_anform1(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3689, v_3690;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3565);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_3565;
// end of prologue
    v_3689 = stack[-1];
    v_3689 = qcar(v_3689);
    stack[-2] = v_3689;
    v_3689 = stack[-1];
    v_3689 = qcdr(v_3689);
    stack[-1] = v_3689;
    v_3689 = stack[-2];
    if (!consp(v_3689)) goto v_3578;
    v_3689 = stack[-2];
    v_3689 = CC_anform1(elt(env, 0), v_3689);
    env = stack[-3];
    v_3689 = stack[-1];
    {
        fn = elt(env, 7); // anforml
        return (*qfn1(fn))(fn, v_3689);
    }
v_3578:
    v_3689 = stack[-2];
    if (symbolp(v_3689)) goto v_3587;
    v_3689 = nil;
    goto v_3570;
v_3587:
    goto v_3597;
v_3593:
    v_3690 = stack[-2];
    goto v_3594;
v_3595:
    v_3689 = elt(env, 1); // dclglb
    goto v_3596;
v_3597:
    goto v_3593;
v_3594:
    goto v_3595;
v_3596:
    v_3689 = Lflagp(nil, v_3690, v_3689);
    env = stack[-3];
    if (v_3689 == nil) goto v_3591;
    goto v_3609;
v_3605:
    v_3690 = stack[-2];
    goto v_3606;
v_3607:
    v_3689 = elt(env, 2); // glb2rf
    goto v_3608;
v_3609:
    goto v_3605;
v_3606:
    goto v_3607;
v_3608:
    v_3689 = Lflagp(nil, v_3690, v_3689);
    env = stack[-3];
    if (v_3689 == nil) goto v_3602;
    else goto v_3603;
v_3602:
    goto v_3617;
v_3613:
    v_3689 = stack[-2];
    v_3690 = ncons(v_3689);
    env = stack[-3];
    goto v_3614;
v_3615:
    v_3689 = elt(env, 2); // glb2rf
    goto v_3616;
v_3617:
    goto v_3613;
v_3614:
    goto v_3615;
v_3616:
    v_3689 = Lflag(nil, v_3690, v_3689);
    env = stack[-3];
    goto v_3626;
v_3622:
    v_3690 = stack[-2];
    goto v_3623;
v_3624:
    v_3689 = qvalue(elt(env, 3)); // globs!*
    goto v_3625;
v_3626:
    goto v_3622;
v_3623:
    goto v_3624;
v_3625:
    v_3689 = cons(v_3690, v_3689);
    env = stack[-3];
    qvalue(elt(env, 3)) = v_3689; // globs!*
    goto v_3601;
v_3603:
v_3601:
    v_3689 = stack[-1];
    {
        fn = elt(env, 7); // anforml
        return (*qfn1(fn))(fn, v_3689);
    }
v_3591:
    goto v_3637;
v_3633:
    v_3690 = stack[-2];
    goto v_3634;
v_3635:
    v_3689 = qvalue(elt(env, 4)); // locls!*
    goto v_3636;
v_3637:
    goto v_3633;
v_3634:
    goto v_3635;
v_3636:
    v_3689 = Lassoc(nil, v_3690, v_3689);
    if (v_3689 == nil) goto v_3632;
    v_3689 = stack[-1];
    {
        fn = elt(env, 7); // anforml
        return (*qfn1(fn))(fn, v_3689);
    }
v_3632:
    v_3689 = stack[-2];
    fn = elt(env, 8); // add2calls
    v_3689 = (*qfn1(fn))(fn, v_3689);
    env = stack[-3];
    goto v_3650;
v_3646:
    stack[0] = stack[-2];
    goto v_3647;
v_3648:
    v_3689 = stack[-1];
    v_3689 = Llength(nil, v_3689);
    env = stack[-3];
    goto v_3649;
v_3650:
    goto v_3646;
v_3647:
    goto v_3648;
v_3649:
    fn = elt(env, 9); // checkargcount
    v_3689 = (*qfn2(fn))(fn, stack[0], v_3689);
    env = stack[-3];
    goto v_3663;
v_3659:
    v_3690 = stack[-2];
    goto v_3660;
v_3661:
    v_3689 = elt(env, 5); // noanl
    goto v_3662;
v_3663:
    goto v_3659;
v_3660:
    goto v_3661;
v_3662:
    v_3689 = Lflagp(nil, v_3690, v_3689);
    env = stack[-3];
    if (v_3689 == nil) goto v_3657;
    goto v_3655;
v_3657:
    goto v_3674;
v_3670:
    v_3690 = stack[-2];
    goto v_3671;
v_3672:
    v_3689 = elt(env, 6); // anlfn
    goto v_3673;
v_3674:
    goto v_3670;
v_3671:
    goto v_3672;
v_3673:
    v_3689 = get(v_3690, v_3689);
    env = stack[-3];
    v_3690 = v_3689;
    if (v_3689 == nil) goto v_3668;
    goto v_3682;
v_3678:
    goto v_3679;
v_3680:
    v_3689 = stack[-1];
    goto v_3681;
v_3682:
    goto v_3678;
v_3679:
    goto v_3680;
v_3681:
    v_3689 = Lapply1(nil, v_3690, v_3689);
    goto v_3655;
v_3668:
    v_3689 = stack[-1];
    fn = elt(env, 7); // anforml
    v_3689 = (*qfn1(fn))(fn, v_3689);
    goto v_3655;
v_3655:
    v_3689 = nil;
v_3570:
    return onevalue(v_3689);
}



// Code for tayexp!-min2

static LispObject CC_tayexpKmin2(LispObject env,
                         LispObject v_3565, LispObject v_3566)
{
    env = qenv(env);
    LispObject v_3584, v_3585;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3565,v_3566);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_3566;
    stack[-1] = v_3565;
// end of prologue
    goto v_3577;
v_3573:
    v_3585 = stack[-1];
    goto v_3574;
v_3575:
    v_3584 = stack[0];
    goto v_3576;
v_3577:
    goto v_3573;
v_3574:
    goto v_3575;
v_3576:
    fn = elt(env, 1); // tayexp!-lessp
    v_3584 = (*qfn2(fn))(fn, v_3585, v_3584);
    if (v_3584 == nil) goto v_3571;
    v_3584 = stack[-1];
    goto v_3569;
v_3571:
    v_3584 = stack[0];
    goto v_3569;
    v_3584 = nil;
v_3569:
    return onevalue(v_3584);
}



// Code for talp_invf

static LispObject CC_talp_invf(LispObject env,
                         LispObject v_3565)
{
    env = qenv(env);
    LispObject v_3575;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3565);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_3575 = v_3565;
// end of prologue
    fn = elt(env, 1); // talp_op
    v_3575 = (*qfn1(fn))(fn, v_3575);
    env = stack[0];
    v_3575 = Lexplodec(nil, v_3575);
    v_3575 = qcdr(v_3575);
    v_3575 = qcdr(v_3575);
    v_3575 = qcdr(v_3575);
    v_3575 = qcdr(v_3575);
    v_3575 = qcar(v_3575);
    return onevalue(v_3575);
}



// Code for ibalp_varlt1

static LispObject CC_ibalp_varlt1(LispObject env,
                         LispObject v_3565, LispObject v_3566)
{
    env = qenv(env);
    LispObject v_3636, v_3637, v_3638;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3566,v_3565);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3565,v_3566);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3566;
    v_3638 = v_3565;
// end of prologue
    goto v_3582;
v_3578:
    v_3637 = v_3638;
    goto v_3579;
v_3580:
    v_3636 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3581;
v_3582:
    goto v_3578;
v_3579:
    goto v_3580;
v_3581:
    if (v_3637 == v_3636) goto v_3576;
    else goto v_3577;
v_3576:
    v_3636 = lisp_true;
    goto v_3575;
v_3577:
    goto v_3592;
v_3588:
    v_3637 = v_3638;
    goto v_3589;
v_3590:
    v_3636 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3591;
v_3592:
    goto v_3588;
v_3589:
    goto v_3590;
v_3591:
    v_3636 = (v_3637 == v_3636 ? lisp_true : nil);
    goto v_3575;
    v_3636 = nil;
v_3575:
    if (v_3636 == nil) goto v_3573;
    v_3636 = nil;
    goto v_3569;
v_3573:
    v_3636 = v_3638;
    if (symbolp(v_3636)) goto v_3599;
    else goto v_3600;
v_3599:
    goto v_3607;
v_3603:
    v_3637 = v_3638;
    goto v_3604;
v_3605:
    v_3636 = stack[0];
    goto v_3606;
v_3607:
    goto v_3603;
v_3604:
    goto v_3605;
v_3606:
    {
        fn = elt(env, 1); // lto_insertq
        return (*qfn2(fn))(fn, v_3637, v_3636);
    }
v_3600:
    v_3636 = v_3638;
    fn = elt(env, 2); // ibalp_argn
    v_3636 = (*qfn1(fn))(fn, v_3636);
    env = stack[-2];
    stack[-1] = v_3636;
v_3613:
    v_3636 = stack[-1];
    if (v_3636 == nil) goto v_3618;
    else goto v_3619;
v_3618:
    goto v_3612;
v_3619:
    v_3636 = stack[-1];
    v_3636 = qcar(v_3636);
    goto v_3630;
v_3626:
    v_3637 = v_3636;
    goto v_3627;
v_3628:
    v_3636 = stack[0];
    goto v_3629;
v_3630:
    goto v_3626;
v_3627:
    goto v_3628;
v_3629:
    v_3636 = CC_ibalp_varlt1(elt(env, 0), v_3637, v_3636);
    env = stack[-2];
    stack[0] = v_3636;
    v_3636 = stack[-1];
    v_3636 = qcdr(v_3636);
    stack[-1] = v_3636;
    goto v_3613;
v_3612:
    v_3636 = stack[0];
v_3569:
    return onevalue(v_3636);
}



setup_type const u08_setup[] =
{
    {"general-plus-mod-p",      TOO_FEW_2,      CC_generalKplusKmodKp,WRONG_NO_2},
    {"divide:",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_divideT},
    {"mcharg2",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mcharg2},
    {"times-term-mod-p",        TOO_FEW_2,      CC_timesKtermKmodKp,WRONG_NO_2},
    {"get_first_kernel",        TOO_FEW_2,      CC_get_first_kernel,WRONG_NO_2},
    {"lalr_precedence",         CC_lalr_precedence,TOO_MANY_1, WRONG_NO_1},
    {"totallessp",              TOO_FEW_2,      CC_totallessp, WRONG_NO_2},
    {"talp_varlat",             CC_talp_varlat, TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_varlat",            CC_ibalp_varlat,TOO_MANY_1,    WRONG_NO_1},
    {"retattributes",           TOO_FEW_2,      CC_retattributes,WRONG_NO_2},
    {"retimes1",                CC_retimes1,    TOO_MANY_1,    WRONG_NO_1},
    {"variables",               CC_variables,   TOO_MANY_1,    WRONG_NO_1},
    {"worderp",                 TOO_FEW_2,      CC_worderp,    WRONG_NO_2},
    {"evaluate0",               TOO_FEW_2,      CC_evaluate0,  WRONG_NO_2},
    {"eofcheck",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_eofcheck},
    {"dp_ecart",                CC_dp_ecart,    TOO_MANY_1,    WRONG_NO_1},
    {"pdmult",                  TOO_FEW_2,      CC_pdmult,     WRONG_NO_2},
    {"cancel",                  CC_cancel,      TOO_MANY_1,    WRONG_NO_1},
    {"canonsq",                 CC_canonsq,     TOO_MANY_1,    WRONG_NO_1},
    {"rassoc",                  TOO_FEW_2,      CC_rassoc,     WRONG_NO_2},
    {"talp_atfp",               CC_talp_atfp,   TOO_MANY_1,    WRONG_NO_1},
    {"checktag",                CC_checktag,    TOO_MANY_1,    WRONG_NO_1},
    {"reval1",                  TOO_FEW_2,      CC_reval1,     WRONG_NO_2},
    {"vevmaptozero1",           TOO_FEW_2,      CC_vevmaptozero1,WRONG_NO_2},
    {"physopsim*",              CC_physopsimH,  TOO_MANY_1,    WRONG_NO_1},
    {"rread",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rread},
    {"reval2",                  TOO_FEW_2,      CC_reval2,     WRONG_NO_2},
    {"divd",                    TOO_FEW_2,      CC_divd,       WRONG_NO_2},
    {"bas_make1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_bas_make1},
    {"adddummy1a",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_adddummy1a},
    {"yyreadch",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_yyreadch},
    {"lispapply",               TOO_FEW_2,      CC_lispapply,  WRONG_NO_2},
    {"cdarx",                   CC_cdarx,       TOO_MANY_1,    WRONG_NO_1},
    {"diff",                    TOO_FEW_2,      CC_diff,       WRONG_NO_2},
    {"talp_smupdknowl1",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_smupdknowl1},
    {"subs2f1",                 CC_subs2f1,     TOO_MANY_1,    WRONG_NO_1},
    {"genp",                    CC_genp,        TOO_MANY_1,    WRONG_NO_1},
    {"deg*form",                CC_degHform,    TOO_MANY_1,    WRONG_NO_1},
    {"domain*p",                CC_domainHp,    TOO_MANY_1,    WRONG_NO_1},
    {"sfpx",                    CC_sfpx,        TOO_MANY_1,    WRONG_NO_1},
    {"psum",                    TOO_FEW_2,      CC_psum,       WRONG_NO_2},
    {"gintequiv:",              CC_gintequivT,  TOO_MANY_1,    WRONG_NO_1},
    {"hevenp",                  CC_hevenp,      TOO_MANY_1,    WRONG_NO_1},
    {"klistt",                  CC_klistt,      TOO_MANY_1,    WRONG_NO_1},
    {"anform1",                 CC_anform1,     TOO_MANY_1,    WRONG_NO_1},
    {"tayexp-min2",             TOO_FEW_2,      CC_tayexpKmin2,WRONG_NO_2},
    {"talp_invf",               CC_talp_invf,   TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_varlt1",            TOO_FEW_2,      CC_ibalp_varlt1,WRONG_NO_2},
    {NULL, (one_args *)"u08", (two_args *)"141994 4238039 7275483", 0}
};

// end of generated code
