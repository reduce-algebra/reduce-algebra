
// $destdir/u32.c        Machine generated C code

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



// Code for lex_basic_token

static LispObject CC_lex_basic_token(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18433, v_18434, v_18435;
    LispObject fn;
    argcheck(nargs, 0, "lex_basic_token");
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
v_17193:
    stack[-4] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    v_18433 = qvalue(elt(env, 1)); // lex_peeked
    if (v_18433 == nil) goto v_17203;
    v_18433 = qvalue(elt(env, 1)); // lex_peeked
    stack[-4] = v_18433;
    v_18433 = qvalue(elt(env, 2)); // lex_peeked_yylval
    qvalue(elt(env, 3)) = v_18433; // yylval
    v_18433 = qvalue(elt(env, 4)); // lex_peeked_escaped
    qvalue(elt(env, 5)) = v_18433; // lex_escaped
    v_18433 = nil;
    qvalue(elt(env, 4)) = v_18433; // lex_peeked_escaped
    qvalue(elt(env, 2)) = v_18433; // lex_peeked_yylval
    qvalue(elt(env, 1)) = v_18433; // lex_peeked
    v_18433 = stack[-4];
    goto v_17199;
v_17203:
    v_18433 = nil;
    qvalue(elt(env, 5)) = v_18433; // lex_escaped
v_17213:
    goto v_17226;
v_17222:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17223;
v_17224:
    v_18433 = elt(env, 7); // ! 
    goto v_17225;
v_17226:
    goto v_17222;
v_17223:
    goto v_17224;
v_17225:
    if (v_18434 == v_18433) goto v_17220;
    else goto v_17221;
v_17220:
    v_18433 = lisp_true;
    goto v_17219;
v_17221:
    goto v_17240;
v_17236:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17237;
v_17238:
    v_18433 = qvalue(elt(env, 8)); // !$eol!$
    goto v_17239;
v_17240:
    goto v_17236;
v_17237:
    goto v_17238;
v_17239:
    if (equal(v_18434, v_18433)) goto v_17234;
    else goto v_17235;
v_17234:
    v_18433 = lisp_true;
    goto v_17233;
v_17235:
    goto v_17254;
v_17250:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17251;
v_17252:
    v_18433 = elt(env, 9); // !	
    goto v_17253;
v_17254:
    goto v_17250;
v_17251:
    goto v_17252;
v_17253:
    if (v_18434 == v_18433) goto v_17248;
    else goto v_17249;
v_17248:
    v_18433 = lisp_true;
    goto v_17247;
v_17249:
    v_18433 = qvalue(elt(env, 6)); // lex_char
    fn = elt(env, 46); // lex_start_line_comment
    v_18433 = (*qfn1(fn))(fn, v_18433);
    env = stack[-5];
    if (v_18433 == nil) goto v_17265;
    else goto v_17266;
v_17265:
    v_18433 = nil;
    goto v_17264;
v_17266:
    fn = elt(env, 47); // lex_skip_line_comment
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17264;
    v_18433 = nil;
v_17264:
    if (v_18433 == nil) goto v_17262;
    else goto v_17261;
v_17262:
    v_18433 = qvalue(elt(env, 6)); // lex_char
    fn = elt(env, 48); // lex_start_block_comment
    v_18433 = (*qfn1(fn))(fn, v_18433);
    env = stack[-5];
    if (v_18433 == nil) goto v_17275;
    else goto v_17276;
v_17275:
    v_18433 = nil;
    goto v_17274;
v_17276:
    fn = elt(env, 49); // lex_skip_block_comment
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17274;
    v_18433 = nil;
v_17274:
v_17261:
    goto v_17247;
    v_18433 = nil;
v_17247:
    goto v_17233;
    v_18433 = nil;
v_17233:
    goto v_17219;
    v_18433 = nil;
v_17219:
    if (v_18433 == nil) goto v_17216;
    else goto v_17217;
v_17216:
    goto v_17212;
v_17217:
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17213;
v_17212:
    goto v_17293;
v_17289:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17290;
v_17291:
    v_18433 = qvalue(elt(env, 10)); // !$eof!$
    goto v_17292;
v_17293:
    goto v_17289;
v_17290:
    goto v_17291;
v_17292:
    if (equal(v_18434, v_18433)) goto v_17287;
    else goto v_17288;
v_17287:
    v_18433 = qvalue(elt(env, 6)); // lex_char
    qvalue(elt(env, 3)) = v_18433; // yylval
    v_18433 = qvalue(elt(env, 11)); // lex_eof_code
    goto v_17199;
v_17288:
    v_18433 = qvalue(elt(env, 6)); // lex_char
    fn = elt(env, 51); // lexer_word_starter
    v_18433 = (*qfn1(fn))(fn, v_18433);
    env = stack[-5];
    if (v_18433 == nil) goto v_17302;
    else goto v_17300;
v_17302:
    goto v_17314;
v_17310:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17311;
v_17312:
    v_18433 = elt(env, 12); // !!
    goto v_17313;
v_17314:
    goto v_17310;
v_17311:
    goto v_17312;
v_17313:
    if (v_18434 == v_18433) goto v_17308;
    else goto v_17309;
v_17308:
    goto v_17327;
v_17323:
    v_18434 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17324;
v_17325:
    v_18433 = (LispObject)524288+TAG_FIXNUM; // 32768
    goto v_17326;
v_17327:
    goto v_17323;
v_17324:
    goto v_17325;
v_17326:
    fn = elt(env, 52); // land
    v_18433 = (*qfn2(fn))(fn, v_18434, v_18433);
    env = stack[-5];
    v_18433 = (LispObject)zerop(v_18433);
    v_18433 = v_18433 ? lisp_true : nil;
    env = stack[-5];
    if (v_18433 == nil) goto v_17319;
    else goto v_17320;
v_17319:
    v_18434 = nil;
    v_18433 = nil;
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=14 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 14, -1);
    qvalue(elt(env, 14)) = v_18434; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 15, 0);
    qvalue(elt(env, 15)) = v_18433; // !*lower
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    v_18433 = lisp_true;
    qvalue(elt(env, 5)) = v_18433; // lex_escaped
    goto v_17318;
v_17320:
    v_18433 = nil;
    goto v_17318;
    v_18433 = nil;
v_17318:
    goto v_17307;
v_17309:
    v_18433 = nil;
    goto v_17307;
    v_18433 = nil;
v_17307:
    if (v_18433 == nil) goto v_17305;
    else goto v_17300;
v_17305:
    goto v_17301;
v_17300:
    goto v_17347;
v_17343:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17344;
v_17345:
    v_18433 = stack[-4];
    goto v_17346;
v_17347:
    goto v_17343;
v_17344:
    goto v_17345;
v_17346:
    v_18433 = cons(v_18434, v_18433);
    env = stack[-5];
    stack[-4] = v_18433;
v_17352:
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    fn = elt(env, 53); // lexer_word_continues
    v_18433 = (*qfn1(fn))(fn, v_18433);
    env = stack[-5];
    if (v_18433 == nil) goto v_17357;
    else goto v_17356;
v_17357:
    goto v_17369;
v_17365:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17366;
v_17367:
    v_18433 = elt(env, 12); // !!
    goto v_17368;
v_17369:
    goto v_17365;
v_17366:
    goto v_17367;
v_17368:
    if (v_18434 == v_18433) goto v_17363;
    else goto v_17364;
v_17363:
    goto v_17382;
v_17378:
    v_18434 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17379;
v_17380:
    v_18433 = (LispObject)524288+TAG_FIXNUM; // 32768
    goto v_17381;
v_17382:
    goto v_17378;
v_17379:
    goto v_17380;
v_17381:
    fn = elt(env, 52); // land
    v_18433 = (*qfn2(fn))(fn, v_18434, v_18433);
    env = stack[-5];
    v_18433 = (LispObject)zerop(v_18433);
    v_18433 = v_18433 ? lisp_true : nil;
    env = stack[-5];
    if (v_18433 == nil) goto v_17374;
    else goto v_17375;
v_17374:
    v_18434 = nil;
    v_18433 = nil;
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=14 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 14, -1);
    qvalue(elt(env, 14)) = v_18434; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 15, 0);
    qvalue(elt(env, 15)) = v_18433; // !*lower
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    v_18433 = lisp_true;
    qvalue(elt(env, 5)) = v_18433; // lex_escaped
    goto v_17373;
v_17375:
    v_18433 = nil;
    goto v_17373;
    v_18433 = nil;
v_17373:
    goto v_17362;
v_17364:
    v_18433 = nil;
    goto v_17362;
    v_18433 = nil;
v_17362:
    if (v_18433 == nil) goto v_17360;
    else goto v_17356;
v_17360:
    goto v_17351;
v_17356:
    goto v_17403;
v_17399:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17400;
v_17401:
    v_18433 = stack[-4];
    goto v_17402;
v_17403:
    goto v_17399;
v_17400:
    goto v_17401;
v_17402:
    v_18433 = cons(v_18434, v_18433);
    env = stack[-5];
    stack[-4] = v_18433;
    goto v_17352;
v_17351:
    v_18433 = stack[-4];
    v_18433 = Lnreverse(nil, v_18433);
    env = stack[-5];
    stack[-4] = v_18433;
    fn = elt(env, 54); // list2widestring
    v_18433 = (*qfn1(fn))(fn, v_18433);
    env = stack[-5];
    v_18433 = Lintern(nil, v_18433);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18433; // yylval
    goto v_17422;
v_17418:
    v_18434 = qvalue(elt(env, 3)); // yylval
    goto v_17419;
v_17420:
    v_18433 = elt(env, 16); // comment
    goto v_17421;
v_17422:
    goto v_17418;
v_17419:
    goto v_17420;
v_17421:
    if (v_18434 == v_18433) goto v_17416;
    else goto v_17417;
v_17416:
    goto v_17435;
v_17431:
    v_18434 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17432;
v_17433:
    v_18433 = (LispObject)4194304+TAG_FIXNUM; // 262144
    goto v_17434;
v_17435:
    goto v_17431;
v_17432:
    goto v_17433;
v_17434:
    fn = elt(env, 52); // land
    v_18433 = (*qfn2(fn))(fn, v_18434, v_18433);
    env = stack[-5];
    v_18433 = (LispObject)zerop(v_18433);
    v_18433 = v_18433 ? lisp_true : nil;
    env = stack[-5];
    if (v_18433 == nil) goto v_17427;
    else goto v_17428;
v_17427:
    v_18433 = qvalue(elt(env, 5)); // lex_escaped
    v_18433 = (v_18433 == nil ? lisp_true : nil);
    goto v_17426;
v_17428:
    v_18433 = nil;
    goto v_17426;
    v_18433 = nil;
v_17426:
    goto v_17415;
v_17417:
    v_18433 = nil;
    goto v_17415;
    v_18433 = nil;
v_17415:
    if (v_18433 == nil) goto v_17413;
v_17448:
    goto v_17461;
v_17457:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17458;
v_17459:
    v_18433 = elt(env, 17); // !;
    goto v_17460;
v_17461:
    goto v_17457;
v_17458:
    goto v_17459;
v_17460:
    if (v_18434 == v_18433) goto v_17455;
    else goto v_17456;
v_17455:
    v_18433 = lisp_true;
    goto v_17454;
v_17456:
    goto v_17471;
v_17467:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17468;
v_17469:
    v_18433 = elt(env, 18); // !$
    goto v_17470;
v_17471:
    goto v_17467;
v_17468:
    goto v_17469;
v_17470:
    v_18433 = (v_18434 == v_18433 ? lisp_true : nil);
    goto v_17454;
    v_18433 = nil;
v_17454:
    if (v_18433 == nil) goto v_17452;
    goto v_17447;
v_17452:
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17448;
v_17447:
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17193;
v_17413:
    v_18433 = qvalue(elt(env, 5)); // lex_escaped
    if (v_18433 == nil) goto v_17485;
    else goto v_17486;
v_17485:
    goto v_17493;
v_17489:
    v_18434 = qvalue(elt(env, 3)); // yylval
    goto v_17490;
v_17491:
    v_18433 = elt(env, 19); // lex_code
    goto v_17492;
v_17493:
    goto v_17489;
v_17490:
    goto v_17491;
v_17492:
    v_18433 = get(v_18434, v_18433);
    env = stack[-5];
    stack[-3] = v_18433;
    goto v_17484;
v_17486:
    v_18433 = nil;
    goto v_17484;
    v_18433 = nil;
v_17484:
    if (v_18433 == nil) goto v_17482;
    v_18433 = stack[-3];
    goto v_17199;
v_17482:
    goto v_17511;
v_17507:
    v_18434 = stack[-4];
    goto v_17508;
v_17509:
    v_18433 = elt(env, 20); // !'
    goto v_17510;
v_17511:
    goto v_17507;
v_17508:
    goto v_17509;
v_17510:
    if (!consp(v_18434)) goto v_17505;
    v_18434 = qcar(v_18434);
    if (v_18434 == v_18433) goto v_17504;
    else goto v_17505;
v_17504:
    v_18433 = lisp_true;
    goto v_17503;
v_17505:
    goto v_17522;
v_17518:
    v_18434 = stack[-4];
    goto v_17519;
v_17520:
    v_18433 = elt(env, 21); // lex_is_typename
    goto v_17521;
v_17522:
    goto v_17518;
v_17519:
    goto v_17520;
v_17521:
    v_18433 = get(v_18434, v_18433);
    env = stack[-5];
    goto v_17503;
    v_18433 = nil;
v_17503:
    if (v_18433 == nil) goto v_17501;
    v_18433 = qvalue(elt(env, 22)); // lex_typename_code
    goto v_17199;
v_17501:
    v_18433 = qvalue(elt(env, 23)); // lex_symbol_code
    goto v_17199;
    goto v_17299;
v_17301:
    v_18433 = qvalue(elt(env, 6)); // lex_char
    v_18433 = Ldigitp(nil, v_18433);
    env = stack[-5];
    if (v_18433 == nil) goto v_17531;
    else goto v_17529;
v_17531:
    goto v_17543;
v_17539:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17540;
v_17541:
    v_18433 = elt(env, 24); // !~
    goto v_17542;
v_17543:
    goto v_17539;
v_17540:
    goto v_17541;
v_17542:
    if (v_18434 == v_18433) goto v_17537;
    else goto v_17538;
v_17537:
    goto v_17556;
v_17552:
    v_18434 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17553;
v_17554:
    v_18433 = (LispObject)2097152+TAG_FIXNUM; // 131072
    goto v_17555;
v_17556:
    goto v_17552;
v_17553:
    goto v_17554;
v_17555:
    fn = elt(env, 52); // land
    v_18433 = (*qfn2(fn))(fn, v_18434, v_18433);
    env = stack[-5];
    v_18433 = (LispObject)zerop(v_18433);
    v_18433 = v_18433 ? lisp_true : nil;
    env = stack[-5];
    if (v_18433 == nil) goto v_17548;
    else goto v_17549;
v_17548:
    fn = elt(env, 55); // yypeek
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18433 = Ldigitp(nil, v_18433);
    env = stack[-5];
    goto v_17547;
v_17549:
    v_18433 = nil;
    goto v_17547;
    v_18433 = nil;
v_17547:
    goto v_17536;
v_17538:
    v_18433 = nil;
    goto v_17536;
    v_18433 = nil;
v_17536:
    if (v_18433 == nil) goto v_17534;
    else goto v_17529;
v_17534:
    goto v_17530;
v_17529:
    goto v_17575;
v_17571:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17572;
v_17573:
    v_18433 = elt(env, 24); // !~
    goto v_17574;
v_17575:
    goto v_17571;
v_17572:
    goto v_17573;
v_17574:
    if (v_18434 == v_18433) goto v_17569;
    else goto v_17570;
v_17569:
    v_18433 = lisp_true;
    stack[-2] = v_18433;
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17568;
v_17570:
v_17568:
    goto v_17592;
v_17588:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17589;
v_17590:
    v_18433 = elt(env, 25); // !0
    goto v_17591;
v_17592:
    goto v_17588;
v_17589:
    goto v_17590;
v_17591:
    if (v_18434 == v_18433) goto v_17586;
    else goto v_17587;
v_17586:
    goto v_17603;
v_17599:
    fn = elt(env, 55); // yypeek
    v_18434 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17600;
v_17601:
    v_18433 = elt(env, 26); // x
    goto v_17602;
v_17603:
    goto v_17599;
v_17600:
    goto v_17601;
v_17602:
    if (v_18434 == v_18433) goto v_17597;
    else goto v_17598;
v_17597:
    v_18433 = lisp_true;
    goto v_17596;
v_17598:
    goto v_17613;
v_17609:
    fn = elt(env, 55); // yypeek
    v_18434 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17610;
v_17611:
    v_18433 = elt(env, 27); // !X
    goto v_17612;
v_17613:
    goto v_17609;
v_17610:
    goto v_17611;
v_17612:
    v_18433 = (v_18434 == v_18433 ? lisp_true : nil);
    goto v_17596;
    v_18433 = nil;
v_17596:
    goto v_17585;
v_17587:
    v_18433 = nil;
    goto v_17585;
    v_18433 = nil;
v_17585:
    if (v_18433 == nil) goto v_17583;
    v_18433 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 3)) = v_18433; // yylval
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
v_17624:
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    fn = elt(env, 56); // lex_hexval
    v_18433 = (*qfn1(fn))(fn, v_18433);
    env = stack[-5];
    stack[-3] = v_18433;
    if (v_18433 == nil) goto v_17627;
    else goto v_17628;
v_17627:
    goto v_17623;
v_17628:
    goto v_17637;
v_17633:
    goto v_17643;
v_17639:
    v_18434 = (LispObject)256+TAG_FIXNUM; // 16
    goto v_17640;
v_17641:
    v_18433 = qvalue(elt(env, 3)); // yylval
    goto v_17642;
v_17643:
    goto v_17639;
v_17640:
    goto v_17641;
v_17642:
    v_18434 = times2(v_18434, v_18433);
    env = stack[-5];
    goto v_17634;
v_17635:
    v_18433 = stack[-3];
    goto v_17636;
v_17637:
    goto v_17633;
v_17634:
    goto v_17635;
v_17636:
    v_18433 = plus2(v_18434, v_18433);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18433; // yylval
    goto v_17624;
v_17623:
    v_18433 = stack[-2];
    if (v_18433 == nil) goto v_17650;
    v_18433 = qvalue(elt(env, 3)); // yylval
    v_18433 = negate(v_18433);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18433; // yylval
    goto v_17648;
v_17650:
v_17648:
    v_18433 = qvalue(elt(env, 28)); // lex_number_code
    goto v_17199;
v_17583:
    v_18433 = qvalue(elt(env, 6)); // lex_char
    v_18433 = ncons(v_18433);
    env = stack[-5];
    stack[-4] = v_18433;
v_17659:
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18433 = qvalue(elt(env, 6)); // lex_char
    v_18433 = Ldigitp(nil, v_18433);
    env = stack[-5];
    if (v_18433 == nil) goto v_17662;
    else goto v_17663;
v_17662:
    goto v_17658;
v_17663:
    goto v_17673;
v_17669:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17670;
v_17671:
    v_18433 = stack[-4];
    goto v_17672;
v_17673:
    goto v_17669;
v_17670:
    goto v_17671;
v_17672:
    v_18433 = cons(v_18434, v_18433);
    env = stack[-5];
    stack[-4] = v_18433;
    goto v_17659;
v_17658:
    goto v_17684;
v_17680:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17681;
v_17682:
    v_18433 = elt(env, 29); // !.
    goto v_17683;
v_17684:
    goto v_17680;
v_17681:
    goto v_17682;
v_17683:
    if (v_18434 == v_18433) goto v_17678;
    else goto v_17679;
v_17678:
    v_18433 = lisp_true;
    stack[-3] = v_18433;
    goto v_17693;
v_17689:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17690;
v_17691:
    v_18433 = stack[-4];
    goto v_17692;
v_17693:
    goto v_17689;
v_17690:
    goto v_17691;
v_17692:
    v_18433 = cons(v_18434, v_18433);
    env = stack[-5];
    stack[-4] = v_18433;
v_17698:
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18433 = qvalue(elt(env, 6)); // lex_char
    v_18433 = Ldigitp(nil, v_18433);
    env = stack[-5];
    if (v_18433 == nil) goto v_17701;
    else goto v_17702;
v_17701:
    goto v_17697;
v_17702:
    goto v_17712;
v_17708:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17709;
v_17710:
    v_18433 = stack[-4];
    goto v_17711;
v_17712:
    goto v_17708;
v_17709:
    goto v_17710;
v_17711:
    v_18433 = cons(v_18434, v_18433);
    env = stack[-5];
    stack[-4] = v_18433;
    goto v_17698;
v_17697:
    goto v_17677;
v_17679:
v_17677:
    goto v_17727;
v_17723:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17724;
v_17725:
    v_18433 = elt(env, 30); // e
    goto v_17726;
v_17727:
    goto v_17723;
v_17724:
    goto v_17725;
v_17726:
    if (v_18434 == v_18433) goto v_17721;
    else goto v_17722;
v_17721:
    v_18433 = lisp_true;
    goto v_17720;
v_17722:
    goto v_17737;
v_17733:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17734;
v_17735:
    v_18433 = elt(env, 31); // !E
    goto v_17736;
v_17737:
    goto v_17733;
v_17734:
    goto v_17735;
v_17736:
    v_18433 = (v_18434 == v_18433 ? lisp_true : nil);
    goto v_17720;
    v_18433 = nil;
v_17720:
    if (v_18433 == nil) goto v_17718;
    v_18433 = stack[-3];
    if (v_18433 == nil) goto v_17743;
    else goto v_17744;
v_17743:
    goto v_17753;
v_17747:
    v_18435 = elt(env, 25); // !0
    goto v_17748;
v_17749:
    v_18434 = elt(env, 29); // !.
    goto v_17750;
v_17751:
    v_18433 = stack[-4];
    goto v_17752;
v_17753:
    goto v_17747;
v_17748:
    goto v_17749;
v_17750:
    goto v_17751;
v_17752:
    v_18433 = list2star(v_18435, v_18434, v_18433);
    env = stack[-5];
    stack[-4] = v_18433;
    goto v_17742;
v_17744:
v_17742:
    goto v_17763;
v_17759:
    v_18434 = elt(env, 30); // e
    goto v_17760;
v_17761:
    v_18433 = stack[-4];
    goto v_17762;
v_17763:
    goto v_17759;
v_17760:
    goto v_17761;
v_17762:
    v_18433 = cons(v_18434, v_18433);
    env = stack[-5];
    stack[-4] = v_18433;
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17779;
v_17775:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17776;
v_17777:
    v_18433 = elt(env, 32); // !+
    goto v_17778;
v_17779:
    goto v_17775;
v_17776:
    goto v_17777;
v_17778:
    if (v_18434 == v_18433) goto v_17773;
    else goto v_17774;
v_17773:
    v_18433 = lisp_true;
    goto v_17772;
v_17774:
    goto v_17789;
v_17785:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17786;
v_17787:
    v_18433 = elt(env, 33); // !-
    goto v_17788;
v_17789:
    goto v_17785;
v_17786:
    goto v_17787;
v_17788:
    v_18433 = (v_18434 == v_18433 ? lisp_true : nil);
    goto v_17772;
    v_18433 = nil;
v_17772:
    if (v_18433 == nil) goto v_17770;
    goto v_17798;
v_17794:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17795;
v_17796:
    v_18433 = stack[-4];
    goto v_17797;
v_17798:
    goto v_17794;
v_17795:
    goto v_17796;
v_17797:
    v_18433 = cons(v_18434, v_18433);
    env = stack[-5];
    stack[-4] = v_18433;
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17768;
v_17770:
v_17768:
    v_18433 = qvalue(elt(env, 6)); // lex_char
    v_18433 = Ldigitp(nil, v_18433);
    env = stack[-5];
    if (v_18433 == nil) goto v_17804;
    else goto v_17805;
v_17804:
    goto v_17813;
v_17809:
    v_18434 = elt(env, 25); // !0
    goto v_17810;
v_17811:
    v_18433 = stack[-4];
    goto v_17812;
v_17813:
    goto v_17809;
v_17810:
    goto v_17811;
v_17812:
    v_18433 = cons(v_18434, v_18433);
    env = stack[-5];
    stack[-4] = v_18433;
    goto v_17803;
v_17805:
    goto v_17823;
v_17819:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17820;
v_17821:
    v_18433 = stack[-4];
    goto v_17822;
v_17823:
    goto v_17819;
v_17820:
    goto v_17821;
v_17822:
    v_18433 = cons(v_18434, v_18433);
    env = stack[-5];
    stack[-4] = v_18433;
v_17828:
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18433 = qvalue(elt(env, 6)); // lex_char
    v_18433 = Ldigitp(nil, v_18433);
    env = stack[-5];
    if (v_18433 == nil) goto v_17831;
    else goto v_17832;
v_17831:
    goto v_17827;
v_17832:
    goto v_17842;
v_17838:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17839;
v_17840:
    v_18433 = stack[-4];
    goto v_17841;
v_17842:
    goto v_17838;
v_17839:
    goto v_17840;
v_17841:
    v_18433 = cons(v_18434, v_18433);
    env = stack[-5];
    stack[-4] = v_18433;
    goto v_17828;
v_17827:
    goto v_17803;
v_17803:
    goto v_17716;
v_17718:
v_17716:
    v_18433 = stack[-4];
    v_18433 = Lnreverse(nil, v_18433);
    env = stack[-5];
    v_18433 = Lcompress(nil, v_18433);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18433; // yylval
    v_18433 = stack[-2];
    if (v_18433 == nil) goto v_17851;
    v_18433 = qvalue(elt(env, 3)); // yylval
    v_18433 = negate(v_18433);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18433; // yylval
    goto v_17849;
v_17851:
v_17849:
    v_18433 = qvalue(elt(env, 28)); // lex_number_code
    goto v_17199;
v_17530:
    goto v_17866;
v_17862:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17863;
v_17864:
    v_18433 = elt(env, 34); // !"
    goto v_17865;
v_17866:
    goto v_17862;
v_17863:
    goto v_17864;
v_17865:
    if (v_18434 == v_18433) goto v_17860;
    else goto v_17861;
v_17860:
    goto v_17875;
v_17871:
    v_18434 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17872;
v_17873:
    v_18433 = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_17874;
v_17875:
    goto v_17871;
v_17872:
    goto v_17873;
v_17874:
    fn = elt(env, 52); // land
    v_18433 = (*qfn2(fn))(fn, v_18434, v_18433);
    env = stack[-5];
    v_18433 = (LispObject)zerop(v_18433);
    v_18433 = v_18433 ? lisp_true : nil;
    env = stack[-5];
    v_18433 = (v_18433 == nil ? lisp_true : nil);
    goto v_17859;
v_17861:
    v_18433 = nil;
    goto v_17859;
    v_18433 = nil;
v_17859:
    if (v_18433 == nil) goto v_17857;
    goto v_17892;
v_17888:
    v_18434 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17889;
v_17890:
    v_18433 = (LispObject)16384+TAG_FIXNUM; // 1024
    goto v_17891;
v_17892:
    goto v_17888;
v_17889:
    goto v_17890;
v_17891:
    fn = elt(env, 52); // land
    v_18433 = (*qfn2(fn))(fn, v_18434, v_18433);
    env = stack[-5];
    v_18433 = (LispObject)zerop(v_18433);
    v_18433 = v_18433 ? lisp_true : nil;
    env = stack[-5];
    if (v_18433 == nil) goto v_17884;
    else goto v_17885;
v_17884:
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=14 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 14, -1);
    qvalue(elt(env, 14)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 15, 0);
    qvalue(elt(env, 15)) = nil; // !*lower
v_17901:
    goto v_17914;
v_17910:
    fn = elt(env, 50); // yyreadch
    v_18434 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17911;
v_17912:
    v_18433 = elt(env, 34); // !"
    goto v_17913;
v_17914:
    goto v_17910;
v_17911:
    goto v_17912;
v_17913:
    if (v_18434 == v_18433) goto v_17909;
    v_18433 = lisp_true;
    goto v_17907;
v_17909:
    goto v_17928;
v_17924:
    fn = elt(env, 55); // yypeek
    v_18434 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17925;
v_17926:
    v_18433 = elt(env, 34); // !"
    goto v_17927;
v_17928:
    goto v_17924;
v_17925:
    goto v_17926;
v_17927:
    if (v_18434 == v_18433) goto v_17922;
    else goto v_17923;
v_17922:
    goto v_17935;
v_17931:
    fn = elt(env, 50); // yyreadch
    v_18434 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17932;
v_17933:
    v_18433 = elt(env, 34); // !"
    goto v_17934;
v_17935:
    goto v_17931;
v_17932:
    goto v_17933;
v_17934:
    v_18433 = (v_18434 == v_18433 ? lisp_true : nil);
    goto v_17921;
v_17923:
    v_18433 = nil;
    goto v_17921;
    v_18433 = nil;
v_17921:
    goto v_17907;
    v_18433 = nil;
v_17907:
    if (v_18433 == nil) goto v_17904;
    else goto v_17905;
v_17904:
    goto v_17900;
v_17905:
    goto v_17948;
v_17944:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17945;
v_17946:
    v_18433 = stack[-4];
    goto v_17947;
v_17948:
    goto v_17944;
v_17945:
    goto v_17946;
v_17947:
    v_18433 = cons(v_18434, v_18433);
    env = stack[-5];
    stack[-4] = v_18433;
    goto v_17901;
v_17900:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_17883;
v_17885:
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=14 saveloc=2
{   bind_fluid_stack bind_fluid_var(-5, 14, -2);
    qvalue(elt(env, 14)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 15, -1);
    qvalue(elt(env, 15)) = nil; // !*lower
    stack[0] = nil;
v_17960:
    goto v_17973;
v_17969:
    fn = elt(env, 50); // yyreadch
    v_18434 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17970;
v_17971:
    v_18433 = elt(env, 34); // !"
    goto v_17972;
v_17973:
    goto v_17969;
v_17970:
    goto v_17971;
v_17972:
    if (v_18434 == v_18433) goto v_17968;
    v_18433 = lisp_true;
    goto v_17966;
v_17968:
    goto v_17983;
v_17979:
    v_18434 = stack[0];
    goto v_17980;
v_17981:
    v_18433 = elt(env, 35); // !\ (backslash)
    goto v_17982;
v_17983:
    goto v_17979;
v_17980:
    goto v_17981;
v_17982:
    v_18433 = (v_18434 == v_18433 ? lisp_true : nil);
    goto v_17966;
    v_18433 = nil;
v_17966:
    if (v_18433 == nil) goto v_17963;
    else goto v_17964;
v_17963:
    goto v_17959;
v_17964:
    v_18433 = qvalue(elt(env, 6)); // lex_char
    stack[0] = v_18433;
    goto v_17994;
v_17990:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_17991;
v_17992:
    v_18433 = stack[-4];
    goto v_17993;
v_17994:
    goto v_17990;
v_17991:
    goto v_17992;
v_17993:
    v_18433 = cons(v_18434, v_18433);
    env = stack[-5];
    stack[-4] = v_18433;
    goto v_17960;
v_17959:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_17883;
v_17883:
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18433 = stack[-4];
    v_18433 = Lnreverse(nil, v_18433);
    env = stack[-5];
    fn = elt(env, 54); // list2widestring
    v_18433 = (*qfn1(fn))(fn, v_18433);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18433; // yylval
    v_18433 = qvalue(elt(env, 36)); // lex_string_code
    goto v_17199;
v_17857:
    goto v_18012;
v_18008:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_18009;
v_18010:
    v_18433 = elt(env, 20); // !'
    goto v_18011;
v_18012:
    goto v_18008;
v_18009:
    goto v_18010;
v_18011:
    if (v_18434 == v_18433) goto v_18006;
    else goto v_18007;
v_18006:
    goto v_18021;
v_18017:
    v_18434 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_18018;
v_18019:
    v_18433 = (LispObject)4096+TAG_FIXNUM; // 256
    goto v_18020;
v_18021:
    goto v_18017;
v_18018:
    goto v_18019;
v_18020:
    fn = elt(env, 52); // land
    v_18433 = (*qfn2(fn))(fn, v_18434, v_18433);
    env = stack[-5];
    v_18433 = (LispObject)zerop(v_18433);
    v_18433 = v_18433 ? lisp_true : nil;
    env = stack[-5];
    v_18433 = (v_18433 == nil ? lisp_true : nil);
    goto v_18005;
v_18007:
    v_18433 = nil;
    goto v_18005;
    v_18433 = nil;
v_18005:
    if (v_18433 == nil) goto v_18003;
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=14 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 14, -1);
    qvalue(elt(env, 14)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 15, 0);
    qvalue(elt(env, 15)) = nil; // !*lower
v_18034:
v_18037:
    goto v_18046;
v_18042:
    fn = elt(env, 50); // yyreadch
    v_18434 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_18043;
v_18044:
    v_18433 = elt(env, 20); // !'
    goto v_18045;
v_18046:
    goto v_18042;
v_18043:
    goto v_18044;
v_18045:
    if (v_18434 == v_18433) goto v_18040;
    else goto v_18041;
v_18040:
    goto v_18036;
v_18041:
    goto v_18055;
v_18051:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_18052;
v_18053:
    v_18433 = stack[-4];
    goto v_18054;
v_18055:
    goto v_18051;
v_18052:
    goto v_18053;
v_18054:
    v_18433 = cons(v_18434, v_18433);
    env = stack[-5];
    stack[-4] = v_18433;
    goto v_18037;
v_18036:
    goto v_18063;
v_18059:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_18060;
v_18061:
    v_18433 = stack[-4];
    goto v_18062;
v_18063:
    goto v_18059;
v_18060:
    goto v_18061;
v_18062:
    v_18433 = cons(v_18434, v_18433);
    env = stack[-5];
    stack[-4] = v_18433;
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_18075;
v_18071:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_18072;
v_18073:
    v_18433 = elt(env, 20); // !'
    goto v_18074;
v_18075:
    goto v_18071;
v_18072:
    goto v_18073;
v_18074:
    if (v_18434 == v_18433) goto v_18069;
    else goto v_18070;
v_18069:
    goto v_18034;
v_18070:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    v_18433 = stack[-4];
    v_18433 = qcdr(v_18433);
    v_18433 = Lnreverse(nil, v_18433);
    env = stack[-5];
    fn = elt(env, 54); // list2widestring
    v_18433 = (*qfn1(fn))(fn, v_18433);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18433; // yylval
    v_18433 = qvalue(elt(env, 37)); // lex_char_code
    goto v_17199;
v_18003:
    goto v_18093;
v_18089:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_18090;
v_18091:
    v_18433 = elt(env, 20); // !'
    goto v_18092;
v_18093:
    goto v_18089;
v_18090:
    goto v_18091;
v_18092:
    if (v_18434 == v_18433) goto v_18087;
    else goto v_18088;
v_18087:
    goto v_18102;
v_18098:
    v_18434 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_18099;
v_18100:
    v_18433 = (LispObject)4194304+TAG_FIXNUM; // 262144
    goto v_18101;
v_18102:
    goto v_18098;
v_18099:
    goto v_18100;
v_18101:
    fn = elt(env, 52); // land
    v_18433 = (*qfn2(fn))(fn, v_18434, v_18433);
    env = stack[-5];
    v_18433 = (LispObject)zerop(v_18433);
    v_18433 = v_18433 ? lisp_true : nil;
    env = stack[-5];
    v_18433 = (v_18433 == nil ? lisp_true : nil);
    goto v_18086;
v_18088:
    v_18433 = nil;
    goto v_18086;
    v_18433 = nil;
v_18086:
    if (v_18433 == nil) goto v_18084;
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    fn = elt(env, 57); // read_s_expression
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_18116;
v_18112:
    v_18434 = elt(env, 38); // quote
    goto v_18113;
v_18114:
    v_18433 = qvalue(elt(env, 3)); // yylval
    goto v_18115;
v_18116:
    goto v_18112;
v_18113:
    goto v_18114;
v_18115:
    v_18433 = list2(v_18434, v_18433);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18433; // yylval
    v_18433 = qvalue(elt(env, 39)); // lex_list_code
    goto v_17199;
v_18084:
    goto v_18130;
v_18126:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_18127;
v_18128:
    v_18433 = elt(env, 40); // !`
    goto v_18129;
v_18130:
    goto v_18126;
v_18127:
    goto v_18128;
v_18129:
    if (v_18434 == v_18433) goto v_18124;
    else goto v_18125;
v_18124:
    goto v_18139;
v_18135:
    v_18434 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_18136;
v_18137:
    v_18433 = (LispObject)4194304+TAG_FIXNUM; // 262144
    goto v_18138;
v_18139:
    goto v_18135;
v_18136:
    goto v_18137;
v_18138:
    fn = elt(env, 52); // land
    v_18433 = (*qfn2(fn))(fn, v_18434, v_18433);
    env = stack[-5];
    v_18433 = (LispObject)zerop(v_18433);
    v_18433 = v_18433 ? lisp_true : nil;
    env = stack[-5];
    v_18433 = (v_18433 == nil ? lisp_true : nil);
    goto v_18123;
v_18125:
    v_18433 = nil;
    goto v_18123;
    v_18433 = nil;
v_18123:
    if (v_18433 == nil) goto v_18121;
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    fn = elt(env, 57); // read_s_expression
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_18153;
v_18149:
    v_18434 = elt(env, 41); // backquote
    goto v_18150;
v_18151:
    v_18433 = qvalue(elt(env, 3)); // yylval
    goto v_18152;
v_18153:
    goto v_18149;
v_18150:
    goto v_18151;
v_18152:
    v_18433 = list2(v_18434, v_18433);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18433; // yylval
    v_18433 = qvalue(elt(env, 39)); // lex_list_code
    goto v_17199;
v_18121:
    v_18433 = qvalue(elt(env, 6)); // lex_char
    qvalue(elt(env, 3)) = v_18433; // yylval
    goto v_18168;
v_18164:
    v_18434 = qvalue(elt(env, 3)); // yylval
    goto v_18165;
v_18166:
    v_18433 = qvalue(elt(env, 10)); // !$eof!$
    goto v_18167;
v_18168:
    goto v_18164;
v_18165:
    goto v_18166;
v_18167:
    if (equal(v_18434, v_18433)) goto v_18162;
    else goto v_18163;
v_18162:
    v_18433 = qvalue(elt(env, 11)); // lex_eof_code
    goto v_17199;
v_18163:
    goto v_18188;
v_18184:
    v_18434 = qvalue(elt(env, 3)); // yylval
    goto v_18185;
v_18186:
    v_18433 = elt(env, 42); // !#
    goto v_18187;
v_18188:
    goto v_18184;
v_18185:
    goto v_18186;
v_18187:
    if (v_18434 == v_18433) goto v_18182;
    else goto v_18183;
v_18182:
    goto v_18197;
v_18193:
    v_18434 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_18194;
v_18195:
    v_18433 = (LispObject)1024+TAG_FIXNUM; // 64
    goto v_18196;
v_18197:
    goto v_18193;
v_18194:
    goto v_18195;
v_18196:
    fn = elt(env, 52); // land
    v_18433 = (*qfn2(fn))(fn, v_18434, v_18433);
    env = stack[-5];
    v_18433 = (LispObject)zerop(v_18433);
    v_18433 = v_18433 ? lisp_true : nil;
    env = stack[-5];
    v_18433 = (v_18433 == nil ? lisp_true : nil);
    goto v_18181;
v_18183:
    v_18433 = nil;
    goto v_18181;
    v_18433 = nil;
v_18181:
    if (v_18433 == nil) goto v_18179;
    v_18433 = lisp_true;
    goto v_18177;
v_18179:
    goto v_18215;
v_18211:
    v_18434 = qvalue(elt(env, 3)); // yylval
    goto v_18212;
v_18213:
    v_18433 = elt(env, 43); // lex_dipthong
    goto v_18214;
v_18215:
    goto v_18211;
v_18212:
    goto v_18213;
v_18214:
    v_18433 = get(v_18434, v_18433);
    env = stack[-5];
    if (v_18433 == nil) goto v_18209;
    else goto v_18208;
v_18209:
    goto v_18228;
v_18224:
    v_18434 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_18225;
v_18226:
    v_18433 = (LispObject)2097152+TAG_FIXNUM; // 131072
    goto v_18227;
v_18228:
    goto v_18224;
v_18225:
    goto v_18226;
v_18227:
    fn = elt(env, 52); // land
    v_18433 = (*qfn2(fn))(fn, v_18434, v_18433);
    env = stack[-5];
    v_18433 = (LispObject)zerop(v_18433);
    v_18433 = v_18433 ? lisp_true : nil;
    env = stack[-5];
    if (v_18433 == nil) goto v_18220;
    else goto v_18221;
v_18220:
    goto v_18236;
v_18232:
    v_18434 = qvalue(elt(env, 3)); // yylval
    goto v_18233;
v_18234:
    v_18433 = elt(env, 44); // sml_opchar
    goto v_18235;
v_18236:
    goto v_18232;
v_18233:
    goto v_18234;
v_18235:
    v_18433 = Lflagp(nil, v_18434, v_18433);
    env = stack[-5];
    goto v_18219;
v_18221:
    v_18433 = nil;
    goto v_18219;
    v_18433 = nil;
v_18219:
v_18208:
    goto v_18177;
    v_18433 = nil;
v_18177:
    if (v_18433 == nil) goto v_18175;
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_18173;
v_18175:
    v_18433 = elt(env, 7); // ! 
    qvalue(elt(env, 6)) = v_18433; // lex_char
    goto v_18173;
v_18173:
    goto v_18259;
v_18255:
    v_18434 = qvalue(elt(env, 3)); // yylval
    goto v_18256;
v_18257:
    v_18433 = elt(env, 42); // !#
    goto v_18258;
v_18259:
    goto v_18255;
v_18256:
    goto v_18257;
v_18258:
    if (v_18434 == v_18433) goto v_18253;
    else goto v_18254;
v_18253:
    goto v_18272;
v_18268:
    v_18434 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_18269;
v_18270:
    v_18433 = (LispObject)1024+TAG_FIXNUM; // 64
    goto v_18271;
v_18272:
    goto v_18268;
v_18269:
    goto v_18270;
v_18271:
    fn = elt(env, 52); // land
    v_18433 = (*qfn2(fn))(fn, v_18434, v_18433);
    env = stack[-5];
    v_18433 = (LispObject)zerop(v_18433);
    v_18433 = v_18433 ? lisp_true : nil;
    env = stack[-5];
    if (v_18433 == nil) goto v_18264;
    else goto v_18265;
v_18264:
    v_18433 = qvalue(elt(env, 6)); // lex_char
    v_18433 = Lalpha_char_p(nil, v_18433);
    env = stack[-5];
    goto v_18263;
v_18265:
    v_18433 = nil;
    goto v_18263;
    v_18433 = nil;
v_18263:
    goto v_18252;
v_18254:
    v_18433 = nil;
    goto v_18252;
    v_18433 = nil;
v_18252:
    if (v_18433 == nil) goto v_18250;
    else goto v_18248;
v_18250:
    goto v_18288;
v_18284:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_18285;
v_18286:
    v_18433 = elt(env, 12); // !!
    goto v_18287;
v_18288:
    goto v_18284;
v_18285:
    goto v_18286;
v_18287:
    if (v_18434 == v_18433) goto v_18248;
    goto v_18249;
v_18248:
    v_18433 = CC_lex_basic_token(elt(env, 0), 0);
    env = stack[-5];
    stack[-4] = v_18433;
    goto v_18300;
v_18296:
    v_18434 = qvalue(elt(env, 3)); // yylval
    goto v_18297;
v_18298:
    v_18433 = elt(env, 45); // (if else elif endif define eval)
    goto v_18299;
v_18300:
    goto v_18296;
v_18297:
    goto v_18298;
v_18299:
    v_18433 = Lmemq(nil, v_18434, v_18433);
    if (v_18433 == nil) goto v_18295;
    goto v_18311;
v_18307:
    stack[0] = elt(env, 42); // !#
    goto v_18308;
v_18309:
    v_18433 = qvalue(elt(env, 3)); // yylval
    v_18433 = Lsymbol_name(nil, v_18433);
    env = stack[-5];
    fn = elt(env, 58); // widestring2list
    v_18433 = (*qfn1(fn))(fn, v_18433);
    env = stack[-5];
    goto v_18310;
v_18311:
    goto v_18307;
v_18308:
    goto v_18309;
v_18310:
    v_18433 = cons(stack[0], v_18433);
    env = stack[-5];
    fn = elt(env, 54); // list2widestring
    v_18433 = (*qfn1(fn))(fn, v_18433);
    env = stack[-5];
    v_18433 = Lintern(nil, v_18433);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18433; // yylval
    goto v_18293;
v_18295:
    v_18433 = stack[-4];
    qvalue(elt(env, 1)) = v_18433; // lex_peeked
    v_18433 = qvalue(elt(env, 3)); // yylval
    qvalue(elt(env, 2)) = v_18433; // lex_peeked_yylval
    v_18433 = qvalue(elt(env, 5)); // lex_escaped
    qvalue(elt(env, 4)) = v_18433; // lex_peeked_escaped
    v_18433 = elt(env, 42); // !#
    qvalue(elt(env, 3)) = v_18433; // yylval
    v_18433 = nil;
    qvalue(elt(env, 5)) = v_18433; // lex_escaped
    goto v_18293;
v_18293:
    goto v_18247;
v_18249:
v_18247:
v_18325:
    goto v_18334;
v_18330:
    v_18435 = qvalue(elt(env, 6)); // lex_char
    goto v_18331;
v_18332:
    goto v_18341;
v_18337:
    v_18434 = qvalue(elt(env, 3)); // yylval
    goto v_18338;
v_18339:
    v_18433 = elt(env, 43); // lex_dipthong
    goto v_18340;
v_18341:
    goto v_18337;
v_18338:
    goto v_18339;
v_18340:
    v_18433 = get(v_18434, v_18433);
    env = stack[-5];
    goto v_18333;
v_18334:
    goto v_18330;
v_18331:
    goto v_18332;
v_18333:
    v_18433 = Latsoc(nil, v_18435, v_18433);
    stack[-3] = v_18433;
    if (v_18433 == nil) goto v_18328;
    else goto v_18329;
v_18328:
    goto v_18324;
v_18329:
    v_18433 = stack[-3];
    v_18433 = qcdr(v_18433);
    qvalue(elt(env, 3)) = v_18433; // yylval
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_18325;
v_18324:
    goto v_18363;
v_18359:
    v_18434 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_18360;
v_18361:
    v_18433 = (LispObject)2097152+TAG_FIXNUM; // 131072
    goto v_18362;
v_18363:
    goto v_18359;
v_18360:
    goto v_18361;
v_18362:
    fn = elt(env, 52); // land
    v_18433 = (*qfn2(fn))(fn, v_18434, v_18433);
    env = stack[-5];
    v_18433 = (LispObject)zerop(v_18433);
    v_18433 = v_18433 ? lisp_true : nil;
    env = stack[-5];
    if (v_18433 == nil) goto v_18355;
    else goto v_18356;
v_18355:
    v_18433 = qvalue(elt(env, 3)); // yylval
    v_18433 = Lexplodec(nil, v_18433);
    env = stack[-5];
    stack[-3] = v_18433;
    fn = elt(env, 59); // all_sml_opchar
    v_18433 = (*qfn1(fn))(fn, v_18433);
    env = stack[-5];
    goto v_18354;
v_18356:
    v_18433 = nil;
    goto v_18354;
    v_18433 = nil;
v_18354:
    if (v_18433 == nil) goto v_18352;
v_18374:
    goto v_18389;
v_18385:
    v_18434 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_18386;
v_18387:
    v_18433 = (LispObject)2097152+TAG_FIXNUM; // 131072
    goto v_18388;
v_18389:
    goto v_18385;
v_18386:
    goto v_18387;
v_18388:
    fn = elt(env, 52); // land
    v_18433 = (*qfn2(fn))(fn, v_18434, v_18433);
    env = stack[-5];
    v_18433 = (LispObject)zerop(v_18433);
    v_18433 = v_18433 ? lisp_true : nil;
    env = stack[-5];
    if (v_18433 == nil) goto v_18381;
    else goto v_18382;
v_18381:
    goto v_18397;
v_18393:
    v_18434 = qvalue(elt(env, 6)); // lex_char
    goto v_18394;
v_18395:
    v_18433 = elt(env, 44); // sml_opchar
    goto v_18396;
v_18397:
    goto v_18393;
v_18394:
    goto v_18395;
v_18396:
    v_18433 = Lflagp(nil, v_18434, v_18433);
    env = stack[-5];
    goto v_18380;
v_18382:
    v_18433 = nil;
    goto v_18380;
    v_18433 = nil;
v_18380:
    if (v_18433 == nil) goto v_18377;
    else goto v_18378;
v_18377:
    goto v_18373;
v_18378:
    goto v_18409;
v_18405:
    stack[0] = stack[-3];
    goto v_18406;
v_18407:
    v_18433 = qvalue(elt(env, 6)); // lex_char
    v_18433 = ncons(v_18433);
    env = stack[-5];
    goto v_18408;
v_18409:
    goto v_18405;
v_18406:
    goto v_18407;
v_18408:
    v_18433 = Lappend(nil, stack[0], v_18433);
    env = stack[-5];
    stack[-3] = v_18433;
    fn = elt(env, 50); // yyreadch
    v_18433 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_18374;
v_18373:
    v_18433 = stack[-3];
    fn = elt(env, 60); // list2string
    v_18433 = (*qfn1(fn))(fn, v_18433);
    env = stack[-5];
    v_18433 = Lintern(nil, v_18433);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18433; // yylval
    goto v_18350;
v_18352:
v_18350:
    goto v_18426;
v_18422:
    v_18434 = qvalue(elt(env, 3)); // yylval
    goto v_18423;
v_18424:
    v_18433 = elt(env, 19); // lex_code
    goto v_18425;
v_18426:
    goto v_18422;
v_18423:
    goto v_18424;
v_18425:
    v_18433 = get(v_18434, v_18433);
    env = stack[-5];
    stack[-3] = v_18433;
    if (v_18433 == nil) goto v_18420;
    v_18433 = stack[-3];
    goto v_17199;
v_18420:
    v_18433 = qvalue(elt(env, 23)); // lex_symbol_code
    goto v_17199;
    goto v_17299;
v_17299:
    v_18433 = nil;
v_17199:
    return onevalue(v_18433);
}



// Code for formbool

static LispObject CC_formbool(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17485, v_17486, v_17487, v_17488, v_17489;
    LispObject fn;
    LispObject v_17196, v_17195, v_17194;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formbool");
    va_start(aa, nargs);
    v_17194 = va_arg(aa, LispObject);
    v_17195 = va_arg(aa, LispObject);
    v_17196 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_17196,v_17195,v_17194);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_17194,v_17195,v_17196);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_17196;
    stack[-3] = v_17195;
    stack[-4] = v_17194;
// end of prologue
    goto v_17206;
v_17202:
    v_17486 = stack[-2];
    goto v_17203;
v_17204:
    v_17485 = elt(env, 1); // symbolic
    goto v_17205;
v_17206:
    goto v_17202;
v_17203:
    goto v_17204;
v_17205:
    if (v_17486 == v_17485) goto v_17200;
    else goto v_17201;
v_17200:
    goto v_17216;
v_17210:
    v_17487 = stack[-4];
    goto v_17211;
v_17212:
    v_17486 = stack[-3];
    goto v_17213;
v_17214:
    v_17485 = stack[-2];
    goto v_17215;
v_17216:
    goto v_17210;
v_17211:
    goto v_17212;
v_17213:
    goto v_17214;
v_17215:
    {
        fn = elt(env, 9); // formc
        return (*qfnn(fn))(fn, 3, v_17487, v_17486, v_17485);
    }
v_17201:
    v_17485 = stack[-4];
    if (!consp(v_17485)) goto v_17220;
    else goto v_17221;
v_17220:
    goto v_17231;
v_17227:
    v_17486 = stack[-4];
    goto v_17228;
v_17229:
    v_17485 = lisp_true;
    goto v_17230;
v_17231:
    goto v_17227;
v_17228:
    goto v_17229;
v_17230:
    if (v_17486 == v_17485) goto v_17225;
    else goto v_17226;
v_17225:
    v_17485 = stack[-4];
    goto v_17224;
v_17226:
    v_17485 = stack[-4];
    if (symbolp(v_17485)) goto v_17240;
    v_17485 = lisp_true;
    goto v_17238;
v_17240:
    goto v_17249;
v_17245:
    v_17486 = stack[-4];
    goto v_17246;
v_17247:
    v_17485 = stack[-3];
    goto v_17248;
v_17249:
    goto v_17245;
v_17246:
    goto v_17247;
v_17248:
    v_17485 = Latsoc(nil, v_17486, v_17485);
    goto v_17238;
    v_17485 = nil;
v_17238:
    if (v_17485 == nil) goto v_17236;
    goto v_17258;
v_17254:
    v_17486 = elt(env, 2); // boolvalue!*
    goto v_17255;
v_17256:
    v_17485 = stack[-4];
    goto v_17257;
v_17258:
    goto v_17254;
v_17255:
    goto v_17256;
v_17257:
    return list2(v_17486, v_17485);
v_17236:
    goto v_17268;
v_17264:
    stack[0] = elt(env, 2); // boolvalue!*
    goto v_17265;
v_17266:
    goto v_17277;
v_17271:
    v_17487 = stack[-4];
    goto v_17272;
v_17273:
    v_17486 = stack[-3];
    goto v_17274;
v_17275:
    v_17485 = stack[-2];
    goto v_17276;
v_17277:
    goto v_17271;
v_17272:
    goto v_17273;
v_17274:
    goto v_17275;
v_17276:
    fn = elt(env, 10); // formc!*
    v_17485 = (*qfnn(fn))(fn, 3, v_17487, v_17486, v_17485);
    goto v_17267;
v_17268:
    goto v_17264;
v_17265:
    goto v_17266;
v_17267:
    {
        LispObject v_17496 = stack[0];
        return list2(v_17496, v_17485);
    }
    v_17485 = nil;
v_17224:
    goto v_17199;
v_17221:
    goto v_17289;
v_17285:
    v_17485 = stack[-4];
    v_17486 = qcdr(v_17485);
    goto v_17286;
v_17287:
    v_17485 = stack[-3];
    goto v_17288;
v_17289:
    goto v_17285;
v_17286:
    goto v_17287;
v_17288:
    fn = elt(env, 11); // intexprlisp
    v_17485 = (*qfn2(fn))(fn, v_17486, v_17485);
    env = stack[-6];
    if (v_17485 == nil) goto v_17282;
    goto v_17299;
v_17295:
    v_17485 = stack[-4];
    v_17486 = qcar(v_17485);
    goto v_17296;
v_17297:
    v_17485 = elt(env, 3); // boolfn
    goto v_17298;
v_17299:
    goto v_17295;
v_17296:
    goto v_17297;
v_17298:
    v_17485 = get(v_17486, v_17485);
    env = stack[-6];
    if (v_17485 == nil) goto v_17282;
    v_17485 = stack[-4];
    goto v_17199;
v_17282:
    v_17485 = stack[-4];
    v_17485 = qcar(v_17485);
    if (symbolp(v_17485)) goto v_17306;
    else goto v_17305;
v_17306:
    goto v_17315;
v_17311:
    v_17485 = stack[-4];
    v_17486 = qcar(v_17485);
    goto v_17312;
v_17313:
    v_17485 = elt(env, 3); // boolfn
    goto v_17314;
v_17315:
    goto v_17311;
v_17312:
    goto v_17313;
v_17314:
    v_17485 = get(v_17486, v_17485);
    env = stack[-6];
    if (v_17485 == nil) goto v_17305;
    goto v_17324;
v_17320:
    goto v_17330;
v_17326:
    v_17485 = stack[-4];
    v_17486 = qcar(v_17485);
    goto v_17327;
v_17328:
    v_17485 = elt(env, 3); // boolfn
    goto v_17329;
v_17330:
    goto v_17326;
v_17327:
    goto v_17328;
v_17329:
    stack[0] = get(v_17486, v_17485);
    env = stack[-6];
    goto v_17321;
v_17322:
    goto v_17341;
v_17335:
    v_17485 = stack[-4];
    v_17487 = qcdr(v_17485);
    goto v_17336;
v_17337:
    v_17486 = stack[-3];
    goto v_17338;
v_17339:
    v_17485 = stack[-2];
    goto v_17340;
v_17341:
    goto v_17335;
v_17336:
    goto v_17337;
v_17338:
    goto v_17339;
v_17340:
    fn = elt(env, 12); // formclis
    v_17485 = (*qfnn(fn))(fn, 3, v_17487, v_17486, v_17485);
    goto v_17323;
v_17324:
    goto v_17320;
v_17321:
    goto v_17322;
v_17323:
    {
        LispObject v_17497 = stack[0];
        return cons(v_17497, v_17485);
    }
v_17305:
    v_17485 = stack[-4];
    v_17485 = qcar(v_17485);
    if (symbolp(v_17485)) goto v_17348;
    else goto v_17347;
v_17348:
    goto v_17357;
v_17353:
    v_17485 = stack[-4];
    v_17486 = qcar(v_17485);
    goto v_17354;
v_17355:
    v_17485 = elt(env, 4); // boolean
    goto v_17356;
v_17357:
    goto v_17353;
v_17354:
    goto v_17355;
v_17356:
    v_17485 = Lflagp(nil, v_17486, v_17485);
    env = stack[-6];
    if (v_17485 == nil) goto v_17347;
    goto v_17366;
v_17362:
    v_17485 = stack[-4];
    stack[0] = qcar(v_17485);
    goto v_17363;
v_17364:
    goto v_17378;
v_17370:
    v_17485 = stack[-4];
    v_17489 = qcdr(v_17485);
    goto v_17371;
v_17372:
    v_17488 = stack[-3];
    goto v_17373;
v_17374:
    v_17487 = stack[-2];
    goto v_17375;
v_17376:
    goto v_17388;
v_17384:
    v_17485 = stack[-4];
    v_17486 = qcar(v_17485);
    goto v_17385;
v_17386:
    v_17485 = elt(env, 5); // boolargs
    goto v_17387;
v_17388:
    goto v_17384;
v_17385:
    goto v_17386;
v_17387:
    v_17485 = Lflagp(nil, v_17486, v_17485);
    env = stack[-6];
    goto v_17377;
v_17378:
    goto v_17370;
v_17371:
    goto v_17372;
v_17373:
    goto v_17374;
v_17375:
    goto v_17376;
v_17377:
    fn = elt(env, 13); // formboollis
    v_17485 = (*qfnn(fn))(fn, 4, v_17489, v_17488, v_17487, v_17485);
    goto v_17365;
v_17366:
    goto v_17362;
v_17363:
    goto v_17364;
v_17365:
    {
        LispObject v_17498 = stack[0];
        return cons(v_17498, v_17485);
    }
v_17347:
    goto v_17398;
v_17394:
    v_17485 = stack[-4];
    v_17486 = qcar(v_17485);
    goto v_17395;
v_17396:
    v_17485 = elt(env, 2); // boolvalue!*
    goto v_17397;
v_17398:
    goto v_17394;
v_17395:
    goto v_17396;
v_17397:
    if (v_17486 == v_17485) goto v_17392;
    else goto v_17393;
v_17392:
    v_17485 = elt(env, 6); // "Too many formbools"
    {
        fn = elt(env, 14); // rederr
        return (*qfn1(fn))(fn, v_17485);
    }
v_17393:
    goto v_17410;
v_17406:
    v_17485 = stack[-4];
    v_17486 = qcar(v_17485);
    goto v_17407;
v_17408:
    v_17485 = elt(env, 7); // where
    goto v_17409;
v_17410:
    goto v_17406;
v_17407:
    goto v_17408;
v_17409:
    if (v_17486 == v_17485) goto v_17404;
    else goto v_17405;
v_17404:
    goto v_17419;
v_17415:
    stack[-5] = elt(env, 2); // boolvalue!*
    goto v_17416;
v_17417:
    goto v_17428;
v_17422:
    goto v_17436;
v_17430:
    stack[-1] = elt(env, 7); // where
    goto v_17431;
v_17432:
    goto v_17444;
v_17440:
    stack[0] = elt(env, 8); // bool!-eval
    goto v_17441;
v_17442:
    goto v_17453;
v_17447:
    v_17485 = stack[-4];
    v_17485 = qcdr(v_17485);
    v_17487 = qcar(v_17485);
    goto v_17448;
v_17449:
    v_17486 = stack[-3];
    goto v_17450;
v_17451:
    v_17485 = stack[-2];
    goto v_17452;
v_17453:
    goto v_17447;
v_17448:
    goto v_17449;
v_17450:
    goto v_17451;
v_17452:
    v_17485 = CC_formbool(elt(env, 0), 3, v_17487, v_17486, v_17485);
    env = stack[-6];
    goto v_17443;
v_17444:
    goto v_17440;
v_17441:
    goto v_17442;
v_17443:
    v_17485 = list2(stack[0], v_17485);
    env = stack[-6];
    v_17486 = Lmkquote(nil, v_17485);
    env = stack[-6];
    goto v_17433;
v_17434:
    v_17485 = stack[-4];
    v_17485 = qcdr(v_17485);
    v_17485 = qcdr(v_17485);
    v_17485 = qcar(v_17485);
    goto v_17435;
v_17436:
    goto v_17430;
v_17431:
    goto v_17432;
v_17433:
    goto v_17434;
v_17435:
    v_17487 = list3(stack[-1], v_17486, v_17485);
    env = stack[-6];
    goto v_17423;
v_17424:
    v_17486 = stack[-3];
    goto v_17425;
v_17426:
    v_17485 = stack[-2];
    goto v_17427;
v_17428:
    goto v_17422;
v_17423:
    goto v_17424;
v_17425:
    goto v_17426;
v_17427:
    fn = elt(env, 10); // formc!*
    v_17485 = (*qfnn(fn))(fn, 3, v_17487, v_17486, v_17485);
    goto v_17418;
v_17419:
    goto v_17415;
v_17416:
    goto v_17417;
v_17418:
    {
        LispObject v_17499 = stack[-5];
        return list2(v_17499, v_17485);
    }
v_17405:
    goto v_17472;
v_17468:
    stack[0] = elt(env, 2); // boolvalue!*
    goto v_17469;
v_17470:
    goto v_17481;
v_17475:
    v_17487 = stack[-4];
    goto v_17476;
v_17477:
    v_17486 = stack[-3];
    goto v_17478;
v_17479:
    v_17485 = stack[-2];
    goto v_17480;
v_17481:
    goto v_17475;
v_17476:
    goto v_17477;
v_17478:
    goto v_17479;
v_17480:
    fn = elt(env, 10); // formc!*
    v_17485 = (*qfnn(fn))(fn, 3, v_17487, v_17486, v_17485);
    goto v_17471;
v_17472:
    goto v_17468;
v_17469:
    goto v_17470;
v_17471:
    {
        LispObject v_17500 = stack[0];
        return list2(v_17500, v_17485);
    }
    v_17485 = nil;
v_17199:
    return onevalue(v_17485);
}



// Code for even_action_sf

static LispObject CC_even_action_sf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17254, v_17255, v_17256, v_17257;
    LispObject fn;
    LispObject v_17197, v_17196, v_17195, v_17194;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "even_action_sf");
    va_start(aa, nargs);
    v_17194 = va_arg(aa, LispObject);
    v_17195 = va_arg(aa, LispObject);
    v_17196 = va_arg(aa, LispObject);
    v_17197 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_17197,v_17196,v_17195,v_17194);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_17194,v_17195,v_17196,v_17197);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_17197;
    stack[-1] = v_17196;
    stack[-2] = v_17195;
    stack[-3] = v_17194;
// end of prologue
    goto v_17207;
v_17203:
    v_17255 = nil;
    goto v_17204;
v_17205:
    v_17254 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17206;
v_17207:
    goto v_17203;
v_17204:
    goto v_17205;
v_17206:
    v_17254 = cons(v_17255, v_17254);
    env = stack[-5];
    v_17255 = v_17254;
v_17212:
    v_17254 = stack[-2];
    if (!consp(v_17254)) goto v_17219;
    else goto v_17220;
v_17219:
    v_17254 = lisp_true;
    goto v_17218;
v_17220:
    v_17254 = stack[-2];
    v_17254 = qcar(v_17254);
    v_17254 = (consp(v_17254) ? nil : lisp_true);
    goto v_17218;
    v_17254 = nil;
v_17218:
    if (v_17254 == nil) goto v_17216;
    goto v_17211;
v_17216:
    goto v_17234;
v_17230:
    stack[-4] = v_17255;
    goto v_17231;
v_17232:
    goto v_17245;
v_17237:
    v_17257 = stack[-3];
    goto v_17238;
v_17239:
    v_17254 = stack[-2];
    v_17256 = qcar(v_17254);
    goto v_17240;
v_17241:
    v_17255 = stack[-1];
    goto v_17242;
v_17243:
    v_17254 = stack[0];
    goto v_17244;
v_17245:
    goto v_17237;
v_17238:
    goto v_17239;
v_17240:
    goto v_17241;
v_17242:
    goto v_17243;
v_17244:
    fn = elt(env, 1); // even_action_term
    v_17254 = (*qfnn(fn))(fn, 4, v_17257, v_17256, v_17255, v_17254);
    env = stack[-5];
    goto v_17233;
v_17234:
    goto v_17230;
v_17231:
    goto v_17232;
v_17233:
    fn = elt(env, 2); // addsq
    v_17254 = (*qfn2(fn))(fn, stack[-4], v_17254);
    env = stack[-5];
    v_17255 = v_17254;
    v_17254 = stack[-2];
    v_17254 = qcdr(v_17254);
    stack[-2] = v_17254;
    goto v_17212;
v_17211:
    v_17254 = v_17255;
    return onevalue(v_17254);
}



// Code for matrix_rows

static LispObject CC_matrix_rows(LispObject env,
                         LispObject v_17194)
{
    env = qenv(env);
    LispObject v_17218;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_17194);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_17194);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_17194;
// end of prologue
    v_17218 = stack[0];
    if (v_17218 == nil) goto v_17201;
    v_17218 = elt(env, 1); // "<matrixrow>"
    fn = elt(env, 3); // printout
    v_17218 = (*qfn1(fn))(fn, v_17218);
    env = stack[-1];
    v_17218 = lisp_true;
    fn = elt(env, 4); // indent!*
    v_17218 = (*qfn1(fn))(fn, v_17218);
    env = stack[-1];
    v_17218 = stack[0];
    v_17218 = qcar(v_17218);
    fn = elt(env, 5); // row
    v_17218 = (*qfn1(fn))(fn, v_17218);
    env = stack[-1];
    v_17218 = nil;
    fn = elt(env, 4); // indent!*
    v_17218 = (*qfn1(fn))(fn, v_17218);
    env = stack[-1];
    v_17218 = elt(env, 2); // "</matrixrow>"
    fn = elt(env, 3); // printout
    v_17218 = (*qfn1(fn))(fn, v_17218);
    env = stack[-1];
    v_17218 = stack[0];
    v_17218 = qcdr(v_17218);
    v_17218 = CC_matrix_rows(elt(env, 0), v_17218);
    goto v_17199;
v_17201:
v_17199:
    v_17218 = nil;
    return onevalue(v_17218);
}



// Code for sc_getrow

static LispObject CC_sc_getrow(LispObject env,
                         LispObject v_17194, LispObject v_17195)
{
    env = qenv(env);
    LispObject v_17206, v_17207;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_17195,v_17194);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_17194,v_17195);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_17206 = v_17195;
    v_17207 = v_17194;
// end of prologue
    goto v_17202;
v_17198:
    stack[0] = v_17207;
    goto v_17199;
v_17200:
    v_17206 = sub1(v_17206);
    env = stack[-1];
    goto v_17201;
v_17202:
    goto v_17198;
v_17199:
    goto v_17200;
v_17201:
    {
        LispObject v_17209 = stack[0];
        fn = elt(env, 1); // sc_igetv
        return (*qfn2(fn))(fn, v_17209, v_17206);
    }
}



// Code for gparg1p

static LispObject CC_gparg1p(LispObject env,
                         LispObject v_17194)
{
    env = qenv(env);
    LispObject v_17217;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_17194);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_17194);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_17194;
// end of prologue
v_17193:
    v_17217 = stack[0];
    if (v_17217 == nil) goto v_17198;
    else goto v_17199;
v_17198:
    v_17217 = lisp_true;
    goto v_17197;
v_17199:
    v_17217 = stack[0];
    v_17217 = qcar(v_17217);
    fn = elt(env, 1); // gpargp
    v_17217 = (*qfn1(fn))(fn, v_17217);
    env = stack[-1];
    if (v_17217 == nil) goto v_17206;
    else goto v_17207;
v_17206:
    v_17217 = nil;
    goto v_17205;
v_17207:
    v_17217 = stack[0];
    v_17217 = qcdr(v_17217);
    stack[0] = v_17217;
    goto v_17193;
    v_17217 = nil;
v_17205:
    goto v_17197;
    v_17217 = nil;
v_17197:
    return onevalue(v_17217);
}



// Code for indordn

static LispObject CC_indordn(LispObject env,
                         LispObject v_17194)
{
    env = qenv(env);
    LispObject v_17236, v_17237;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_17194);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_17194);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_17237 = v_17194;
// end of prologue
    v_17236 = v_17237;
    if (v_17236 == nil) goto v_17198;
    else goto v_17199;
v_17198:
    v_17236 = nil;
    goto v_17197;
v_17199:
    v_17236 = v_17237;
    v_17236 = qcdr(v_17236);
    if (v_17236 == nil) goto v_17202;
    else goto v_17203;
v_17202:
    v_17236 = v_17237;
    goto v_17197;
v_17203:
    v_17236 = v_17237;
    v_17236 = qcdr(v_17236);
    v_17236 = qcdr(v_17236);
    if (v_17236 == nil) goto v_17207;
    else goto v_17208;
v_17207:
    goto v_17217;
v_17213:
    v_17236 = v_17237;
    v_17236 = qcar(v_17236);
    goto v_17214;
v_17215:
    v_17237 = qcdr(v_17237);
    v_17237 = qcar(v_17237);
    goto v_17216;
v_17217:
    goto v_17213;
v_17214:
    goto v_17215;
v_17216:
    {
        fn = elt(env, 1); // indord2
        return (*qfn2(fn))(fn, v_17236, v_17237);
    }
v_17208:
    goto v_17230;
v_17226:
    v_17236 = v_17237;
    stack[0] = qcar(v_17236);
    goto v_17227;
v_17228:
    v_17236 = v_17237;
    v_17236 = qcdr(v_17236);
    v_17236 = CC_indordn(elt(env, 0), v_17236);
    env = stack[-1];
    goto v_17229;
v_17230:
    goto v_17226;
v_17227:
    goto v_17228;
v_17229:
    {
        LispObject v_17239 = stack[0];
        fn = elt(env, 2); // indordad
        return (*qfn2(fn))(fn, v_17239, v_17236);
    }
    v_17236 = nil;
v_17197:
    return onevalue(v_17236);
}



// Code for one!-entryp

static LispObject CC_oneKentryp(LispObject env,
                         LispObject v_17194, LispObject v_17195)
{
    env = qenv(env);
    LispObject v_17239, v_17240;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_17195,v_17194);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_17194,v_17195);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_17195;
    stack[-1] = v_17194;
// end of prologue
v_17199:
    v_17239 = stack[0];
    if (!consp(v_17239)) goto v_17202;
    else goto v_17203;
v_17202:
    v_17239 = lisp_true;
    goto v_17198;
v_17203:
    goto v_17213;
v_17209:
    v_17240 = stack[-1];
    goto v_17210;
v_17211:
    v_17239 = stack[0];
    v_17239 = qcar(v_17239);
    goto v_17212;
v_17213:
    goto v_17209;
v_17210:
    goto v_17211;
v_17212:
    v_17239 = Lsmemq(nil, v_17240, v_17239);
    env = stack[-2];
    if (v_17239 == nil) goto v_17207;
    goto v_17226;
v_17222:
    v_17240 = stack[-1];
    goto v_17223;
v_17224:
    v_17239 = stack[0];
    v_17239 = qcdr(v_17239);
    goto v_17225;
v_17226:
    goto v_17222;
v_17223:
    goto v_17224;
v_17225:
    v_17239 = Lsmemq(nil, v_17240, v_17239);
    env = stack[-2];
    if (v_17239 == nil) goto v_17220;
    v_17239 = nil;
    goto v_17198;
v_17220:
    v_17239 = stack[0];
    v_17239 = qcar(v_17239);
    stack[0] = v_17239;
    goto v_17199;
    goto v_17201;
v_17207:
    v_17239 = stack[0];
    v_17239 = qcdr(v_17239);
    stack[0] = v_17239;
    goto v_17199;
v_17201:
    v_17239 = nil;
v_17198:
    return onevalue(v_17239);
}



// Code for modp

static LispObject CC_modp(LispObject env,
                         LispObject v_17194, LispObject v_17195)
{
    env = qenv(env);
    LispObject v_17228, v_17229;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_17195,v_17194);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_17194,v_17195);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_17195;
    stack[-1] = v_17194;
// end of prologue
    goto v_17202;
v_17198:
    v_17229 = stack[-1];
    goto v_17199;
v_17200:
    v_17228 = stack[0];
    goto v_17201;
v_17202:
    goto v_17198;
v_17199:
    goto v_17200;
v_17201:
    v_17228 = Cremainder(v_17229, v_17228);
    env = stack[-2];
    stack[-1] = v_17228;
    goto v_17214;
v_17210:
    v_17229 = stack[-1];
    goto v_17211;
v_17212:
    v_17228 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17213;
v_17214:
    goto v_17210;
v_17211:
    goto v_17212;
v_17213:
    v_17228 = (LispObject)lessp2(v_17229, v_17228);
    v_17228 = v_17228 ? lisp_true : nil;
    if (v_17228 == nil) goto v_17208;
    goto v_17222;
v_17218:
    v_17229 = stack[-1];
    goto v_17219;
v_17220:
    v_17228 = stack[0];
    goto v_17221;
v_17222:
    goto v_17218;
v_17219:
    goto v_17220;
v_17221:
    return plus2(v_17229, v_17228);
v_17208:
    v_17228 = stack[-1];
    goto v_17206;
    v_17228 = nil;
v_17206:
    return onevalue(v_17228);
}



// Code for horner!-rule!-for!-one!-var

static LispObject CC_hornerKruleKforKoneKvar(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17335, v_17336, v_17337, v_17338, v_17339, v_17340, v_17341;
    LispObject fn;
    LispObject v_17198, v_17197, v_17196, v_17195, v_17194;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "horner-rule-for-one-var");
    va_start(aa, nargs);
    v_17194 = va_arg(aa, LispObject);
    v_17195 = va_arg(aa, LispObject);
    v_17196 = va_arg(aa, LispObject);
    v_17197 = va_arg(aa, LispObject);
    v_17198 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_17198,v_17197,v_17196,v_17195,v_17194);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_17194,v_17195,v_17196,v_17197,v_17198);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_17336 = v_17198;
    v_17337 = v_17197;
    v_17338 = v_17196;
    v_17339 = v_17195;
    v_17340 = v_17194;
// end of prologue
v_17193:
    v_17335 = v_17340;
    if (!consp(v_17335)) goto v_17210;
    else goto v_17211;
v_17210:
    v_17335 = lisp_true;
    goto v_17209;
v_17211:
    v_17335 = v_17340;
    v_17335 = qcar(v_17335);
    v_17335 = (consp(v_17335) ? nil : lisp_true);
    goto v_17209;
    v_17335 = nil;
v_17209:
    if (v_17335 == nil) goto v_17207;
    v_17335 = lisp_true;
    goto v_17205;
v_17207:
    goto v_17226;
v_17222:
    v_17335 = v_17340;
    v_17335 = qcar(v_17335);
    v_17335 = qcar(v_17335);
    v_17341 = qcar(v_17335);
    goto v_17223;
v_17224:
    v_17335 = v_17339;
    goto v_17225;
v_17226:
    goto v_17222;
v_17223:
    goto v_17224;
v_17225:
    v_17335 = (equal(v_17341, v_17335) ? lisp_true : nil);
    v_17335 = (v_17335 == nil ? lisp_true : nil);
    goto v_17205;
    v_17335 = nil;
v_17205:
    if (v_17335 == nil) goto v_17203;
    v_17335 = v_17338;
    v_17335 = (LispObject)zerop(v_17335);
    v_17335 = v_17335 ? lisp_true : nil;
    env = stack[-6];
    if (v_17335 == nil) goto v_17237;
    v_17335 = v_17340;
    goto v_17235;
v_17237:
    goto v_17248;
v_17244:
    stack[-1] = v_17340;
    goto v_17245;
v_17246:
    goto v_17255;
v_17251:
    stack[0] = v_17337;
    goto v_17252;
v_17253:
    goto v_17263;
v_17259:
    v_17335 = v_17338;
    goto v_17260;
v_17261:
    goto v_17262;
v_17263:
    goto v_17259;
v_17260:
    goto v_17261;
v_17262:
    v_17335 = Lexpt(nil, v_17335, v_17336);
    env = stack[-6];
    fn = elt(env, 1); // !*n2f
    v_17335 = (*qfn1(fn))(fn, v_17335);
    env = stack[-6];
    goto v_17254;
v_17255:
    goto v_17251;
v_17252:
    goto v_17253;
v_17254:
    fn = elt(env, 2); // multf
    v_17335 = (*qfn2(fn))(fn, stack[0], v_17335);
    env = stack[-6];
    goto v_17247;
v_17248:
    goto v_17244;
v_17245:
    goto v_17246;
v_17247:
    {
        LispObject v_17348 = stack[-1];
        fn = elt(env, 3); // addf
        return (*qfn2(fn))(fn, v_17348, v_17335);
    }
    v_17335 = nil;
v_17235:
    goto v_17201;
v_17203:
    v_17335 = v_17340;
    v_17335 = qcar(v_17335);
    v_17335 = qcar(v_17335);
    v_17335 = qcdr(v_17335);
    stack[-5] = v_17335;
    goto v_17286;
v_17276:
    v_17335 = v_17340;
    stack[-4] = qcdr(v_17335);
    goto v_17277;
v_17278:
    stack[-3] = v_17339;
    goto v_17279;
v_17280:
    stack[-2] = v_17338;
    goto v_17281;
v_17282:
    v_17335 = v_17338;
    v_17335 = (LispObject)zerop(v_17335);
    v_17335 = v_17335 ? lisp_true : nil;
    env = stack[-6];
    if (v_17335 == nil) goto v_17294;
    v_17335 = v_17340;
    v_17335 = qcar(v_17335);
    v_17335 = qcdr(v_17335);
    v_17336 = v_17335;
    goto v_17292;
v_17294:
    goto v_17307;
v_17303:
    v_17335 = v_17340;
    v_17335 = qcar(v_17335);
    stack[-1] = qcdr(v_17335);
    goto v_17304;
v_17305:
    goto v_17316;
v_17312:
    stack[0] = v_17337;
    goto v_17313;
v_17314:
    goto v_17324;
v_17320:
    v_17337 = v_17338;
    goto v_17321;
v_17322:
    goto v_17330;
v_17326:
    goto v_17327;
v_17328:
    v_17335 = stack[-5];
    goto v_17329;
v_17330:
    goto v_17326;
v_17327:
    goto v_17328;
v_17329:
    v_17335 = (LispObject)(intptr_t)((intptr_t)v_17336 - (intptr_t)v_17335 + TAG_FIXNUM);
    goto v_17323;
v_17324:
    goto v_17320;
v_17321:
    goto v_17322;
v_17323:
    v_17335 = Lexpt(nil, v_17337, v_17335);
    env = stack[-6];
    fn = elt(env, 1); // !*n2f
    v_17335 = (*qfn1(fn))(fn, v_17335);
    env = stack[-6];
    goto v_17315;
v_17316:
    goto v_17312;
v_17313:
    goto v_17314;
v_17315:
    fn = elt(env, 2); // multf
    v_17335 = (*qfn2(fn))(fn, stack[0], v_17335);
    env = stack[-6];
    goto v_17306;
v_17307:
    goto v_17303;
v_17304:
    goto v_17305;
v_17306:
    fn = elt(env, 3); // addf
    v_17335 = (*qfn2(fn))(fn, stack[-1], v_17335);
    env = stack[-6];
    v_17336 = v_17335;
    goto v_17292;
    v_17336 = nil;
v_17292:
    goto v_17283;
v_17284:
    v_17335 = stack[-5];
    goto v_17285;
v_17286:
    goto v_17276;
v_17277:
    goto v_17278;
v_17279:
    goto v_17280;
v_17281:
    goto v_17282;
v_17283:
    goto v_17284;
v_17285:
    v_17340 = stack[-4];
    v_17339 = stack[-3];
    v_17338 = stack[-2];
    v_17337 = v_17336;
    v_17336 = v_17335;
    goto v_17193;
    goto v_17201;
    v_17335 = nil;
v_17201:
    return onevalue(v_17335);
}



// Code for lalr_process_reductions

static LispObject CC_lalr_process_reductions(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17403, v_17404, v_17405;
    LispObject fn;
    argcheck(nargs, 0, "lalr_process_reductions");
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
    stack[-6] = nil;
    v_17403 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[-4] = v_17403;
    v_17403 = qvalue(elt(env, 1)); // nonterminals
    stack[-5] = v_17403;
v_17212:
    v_17403 = stack[-5];
    if (v_17403 == nil) goto v_17216;
    else goto v_17217;
v_17216:
    goto v_17211;
v_17217:
    v_17403 = stack[-5];
    v_17403 = qcar(v_17403);
    stack[-3] = v_17403;
    v_17403 = stack[-3];
    fn = elt(env, 3); // lalr_productions
    v_17403 = (*qfn1(fn))(fn, v_17403);
    env = stack[-7];
    stack[-2] = v_17403;
v_17226:
    v_17403 = stack[-2];
    if (v_17403 == nil) goto v_17231;
    else goto v_17232;
v_17231:
    goto v_17225;
v_17232:
    v_17403 = stack[-2];
    v_17403 = qcar(v_17403);
    stack[-1] = v_17403;
    goto v_17245;
v_17239:
    stack[0] = stack[-3];
    goto v_17240;
v_17241:
    v_17403 = stack[-1];
    v_17403 = qcar(v_17403);
    v_17404 = Llength(nil, v_17403);
    env = stack[-7];
    goto v_17242;
v_17243:
    v_17403 = stack[-1];
    v_17403 = qcdr(v_17403);
    goto v_17244;
v_17245:
    goto v_17239;
v_17240:
    goto v_17241;
v_17242:
    goto v_17243;
v_17244:
    v_17403 = acons(stack[0], v_17404, v_17403);
    env = stack[-7];
    v_17405 = v_17403;
    goto v_17256;
v_17252:
    v_17404 = v_17405;
    goto v_17253;
v_17254:
    v_17403 = stack[-6];
    goto v_17255;
v_17256:
    goto v_17252;
v_17253:
    goto v_17254;
v_17255:
    v_17403 = Lassoc(nil, v_17404, v_17403);
    stack[0] = v_17403;
    v_17403 = stack[0];
    if (v_17403 == nil) goto v_17262;
    else goto v_17263;
v_17262:
    goto v_17270;
v_17266:
    stack[0] = v_17405;
    goto v_17267;
v_17268:
    v_17403 = stack[-4];
    v_17403 = add1(v_17403);
    env = stack[-7];
    stack[-4] = v_17403;
    goto v_17269;
v_17270:
    goto v_17266;
v_17267:
    goto v_17268;
v_17269:
    v_17403 = cons(stack[0], v_17403);
    env = stack[-7];
    stack[0] = v_17403;
    goto v_17279;
v_17275:
    v_17404 = stack[0];
    goto v_17276;
v_17277:
    v_17403 = stack[-6];
    goto v_17278;
v_17279:
    goto v_17275;
v_17276:
    goto v_17277;
v_17278:
    v_17403 = cons(v_17404, v_17403);
    env = stack[-7];
    stack[-6] = v_17403;
    goto v_17261;
v_17263:
v_17261:
    goto v_17287;
v_17283:
    v_17404 = stack[-1];
    goto v_17284;
v_17285:
    v_17403 = stack[0];
    v_17403 = qcdr(v_17403);
    goto v_17286;
v_17287:
    goto v_17283;
v_17284:
    goto v_17285;
v_17286:
    v_17403 = Lrplacd(nil, v_17404, v_17403);
    env = stack[-7];
    v_17403 = stack[-2];
    v_17403 = qcdr(v_17403);
    stack[-2] = v_17403;
    goto v_17226;
v_17225:
    v_17403 = stack[-5];
    v_17403 = qcdr(v_17403);
    stack[-5] = v_17403;
    goto v_17212;
v_17211:
    v_17403 = stack[-4];
    v_17403 = add1(v_17403);
    env = stack[-7];
    stack[0] = v_17403;
    v_17403 = stack[0];
    v_17403 = sub1(v_17403);
    env = stack[-7];
    v_17403 = Lmkvect(nil, v_17403);
    env = stack[-7];
    stack[-5] = v_17403;
    v_17403 = stack[0];
    v_17403 = sub1(v_17403);
    env = stack[-7];
    fn = elt(env, 4); // mkvect16
    v_17403 = (*qfn1(fn))(fn, v_17403);
    env = stack[-7];
    stack[-3] = v_17403;
    v_17403 = stack[0];
    v_17403 = sub1(v_17403);
    env = stack[-7];
    fn = elt(env, 5); // mkvect8
    v_17403 = (*qfn1(fn))(fn, v_17403);
    env = stack[-7];
    stack[-2] = v_17403;
    v_17403 = stack[-6];
    stack[-1] = v_17403;
v_17309:
    v_17403 = stack[-1];
    if (v_17403 == nil) goto v_17313;
    else goto v_17314;
v_17313:
    goto v_17308;
v_17314:
    v_17403 = stack[-1];
    v_17403 = qcar(v_17403);
    stack[0] = v_17403;
    v_17403 = stack[0];
    v_17403 = qcdr(v_17403);
    stack[-4] = v_17403;
    v_17403 = stack[0];
    v_17403 = qcar(v_17403);
    v_17403 = qcar(v_17403);
    v_17403 = qcdr(v_17403);
    stack[-6] = v_17403;
    goto v_17331;
v_17327:
    v_17403 = stack[0];
    v_17403 = qcar(v_17403);
    v_17403 = qcar(v_17403);
    v_17404 = qcar(v_17403);
    goto v_17328;
v_17329:
    v_17403 = elt(env, 2); // lalr_nonterminal_code
    goto v_17330;
v_17331:
    goto v_17327;
v_17328:
    goto v_17329;
v_17330:
    v_17403 = get(v_17404, v_17403);
    env = stack[-7];
    goto v_17344;
v_17338:
    v_17405 = stack[-3];
    goto v_17339;
v_17340:
    v_17404 = stack[-4];
    goto v_17341;
v_17342:
    goto v_17343;
v_17344:
    goto v_17338;
v_17339:
    goto v_17340;
v_17341:
    goto v_17342;
v_17343:
    fn = elt(env, 6); // putv16
    v_17403 = (*qfnn(fn))(fn, 3, v_17405, v_17404, v_17403);
    env = stack[-7];
    goto v_17355;
v_17349:
    v_17405 = stack[-2];
    goto v_17350;
v_17351:
    v_17404 = stack[-4];
    goto v_17352;
v_17353:
    v_17403 = stack[-6];
    goto v_17354;
v_17355:
    goto v_17349;
v_17350:
    goto v_17351;
v_17352:
    goto v_17353;
v_17354:
    fn = elt(env, 7); // putv8
    v_17403 = (*qfnn(fn))(fn, 3, v_17405, v_17404, v_17403);
    env = stack[-7];
    v_17403 = stack[0];
    v_17403 = qcar(v_17403);
    v_17403 = qcdr(v_17403);
    if (v_17403 == nil) goto v_17362;
    v_17403 = stack[0];
    v_17403 = qcar(v_17403);
    v_17403 = qcdr(v_17403);
    goto v_17374;
v_17370:
    v_17404 = v_17403;
    goto v_17371;
v_17372:
    v_17403 = stack[-6];
    goto v_17373;
v_17374:
    goto v_17370;
v_17371:
    goto v_17372;
v_17373:
    fn = elt(env, 8); // lalr_construct_fn
    v_17403 = (*qfn2(fn))(fn, v_17404, v_17403);
    env = stack[-7];
    goto v_17360;
v_17362:
    v_17403 = nil;
    goto v_17360;
v_17360:
    goto v_17386;
v_17380:
    v_17405 = stack[-5];
    goto v_17381;
v_17382:
    v_17404 = stack[-4];
    goto v_17383;
v_17384:
    goto v_17385;
v_17386:
    goto v_17380;
v_17381:
    goto v_17382;
v_17383:
    goto v_17384;
v_17385:
    *(LispObject *)((char *)v_17405 + (CELL-TAG_VECTOR) + (((intptr_t)v_17404-TAG_FIXNUM)/(16/CELL))) = v_17403;
    v_17403 = stack[-1];
    v_17403 = qcdr(v_17403);
    stack[-1] = v_17403;
    goto v_17309;
v_17308:
    goto v_17399;
v_17393:
    v_17405 = stack[-5];
    goto v_17394;
v_17395:
    v_17404 = stack[-2];
    goto v_17396;
v_17397:
    v_17403 = stack[-3];
    goto v_17398;
v_17399:
    goto v_17393;
v_17394:
    goto v_17395;
v_17396:
    goto v_17397;
v_17398:
    return list3(v_17405, v_17404, v_17403);
    return onevalue(v_17403);
}



// Code for profile_a_package

static LispObject CC_profile_a_package(LispObject env,
                         LispObject v_17194)
{
    env = qenv(env);
    LispObject v_17934, v_17935, v_17936, v_17937, v_17938;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_17194);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_17194);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_17194;
// end of prologue
// Binding !*errcont
// FLUIDBIND: reloadenv=9 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-9, 1, -2);
    qvalue(elt(env, 1)) = nil; // !*errcont
    v_17934 = elt(env, 2); // cpulimit
    v_17934 = Lboundp(nil, v_17934);
    env = stack[-9];
    if (v_17934 == nil) goto v_17212;
    else goto v_17213;
v_17212:
    v_17934 = lisp_true;
    goto v_17211;
v_17213:
    v_17934 = qvalue(elt(env, 2)); // cpulimit
    v_17934 = Lexplodec(nil, v_17934);
    env = stack[-9];
    v_17934 = Lcompress(nil, v_17934);
    env = stack[-9];
    qvalue(elt(env, 2)) = v_17934; // cpulimit
    v_17934 = integerp(v_17934);
    if (v_17934 == nil) goto v_17221;
    else goto v_17222;
v_17221:
    v_17934 = lisp_true;
    goto v_17220;
v_17222:
    goto v_17235;
v_17231:
    v_17935 = qvalue(elt(env, 2)); // cpulimit
    goto v_17232;
v_17233:
    v_17934 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17234;
v_17235:
    goto v_17231;
v_17232:
    goto v_17233;
v_17234:
    v_17934 = (LispObject)lessp2(v_17935, v_17934);
    v_17934 = v_17934 ? lisp_true : nil;
    env = stack[-9];
    goto v_17220;
    v_17934 = nil;
v_17220:
    goto v_17211;
    v_17934 = nil;
v_17211:
    if (v_17934 == nil) goto v_17209;
    goto v_17246;
v_17242:
    v_17935 = elt(env, 3); // jlisp
    goto v_17243;
v_17244:
    v_17934 = qvalue(elt(env, 4)); // lispsystem!*
    goto v_17245;
v_17246:
    goto v_17242;
v_17243:
    goto v_17244;
v_17245:
    v_17934 = Lmemq(nil, v_17935, v_17934);
    if (v_17934 == nil) goto v_17241;
    v_17934 = (LispObject)80000+TAG_FIXNUM; // 5000
    goto v_17239;
v_17241:
    v_17934 = (LispObject)2880+TAG_FIXNUM; // 180
    goto v_17239;
    v_17934 = nil;
v_17239:
    qvalue(elt(env, 2)) = v_17934; // cpulimit
    goto v_17207;
v_17209:
v_17207:
    v_17934 = elt(env, 5); // conslimit
    v_17934 = Lboundp(nil, v_17934);
    env = stack[-9];
    if (v_17934 == nil) goto v_17260;
    else goto v_17261;
v_17260:
    v_17934 = lisp_true;
    goto v_17259;
v_17261:
    v_17934 = qvalue(elt(env, 5)); // conslimit
    v_17934 = Lexplodec(nil, v_17934);
    env = stack[-9];
    v_17934 = Lcompress(nil, v_17934);
    env = stack[-9];
    qvalue(elt(env, 5)) = v_17934; // conslimit
    v_17934 = integerp(v_17934);
    if (v_17934 == nil) goto v_17269;
    else goto v_17270;
v_17269:
    v_17934 = lisp_true;
    goto v_17268;
v_17270:
    goto v_17283;
v_17279:
    v_17935 = qvalue(elt(env, 5)); // conslimit
    goto v_17280;
v_17281:
    v_17934 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17282;
v_17283:
    goto v_17279;
v_17280:
    goto v_17281;
v_17282:
    v_17934 = (LispObject)lessp2(v_17935, v_17934);
    v_17934 = v_17934 ? lisp_true : nil;
    env = stack[-9];
    goto v_17268;
    v_17934 = nil;
v_17268:
    goto v_17259;
    v_17934 = nil;
v_17259:
    if (v_17934 == nil) goto v_17257;
    v_17934 = (LispObject)32000+TAG_FIXNUM; // 2000
    qvalue(elt(env, 5)) = v_17934; // conslimit
    goto v_17255;
v_17257:
v_17255:
    v_17934 = elt(env, 6); // "PROFILING: "
    v_17934 = Lprinc(nil, v_17934);
    env = stack[-9];
    v_17934 = stack[-7];
    v_17934 = qcar(v_17934);
    v_17934 = Lprint(nil, v_17934);
    env = stack[-9];
    v_17934 = nil;
    qvalue(elt(env, 7)) = v_17934; // !*backtrace
    v_17934 = lisp_true;
    qvalue(elt(env, 1)) = v_17934; // !*errcont
    v_17934 = nil;
    qvalue(elt(env, 8)) = v_17934; // !*int
    v_17934 = stack[-7];
    v_17934 = qcar(v_17934);
    stack[-8] = v_17934;
    v_17934 = nil;
    v_17934 = Lverbos(nil, v_17934);
    env = stack[-9];
    fn = elt(env, 53); // get_configuration_data
    v_17934 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    goto v_17308;
v_17304:
    v_17935 = stack[-8];
    goto v_17305;
v_17306:
    v_17934 = qvalue(elt(env, 9)); // reduce_regression_tests
    goto v_17307;
v_17308:
    goto v_17304;
v_17305:
    goto v_17306;
v_17307:
    v_17934 = Lmemq(nil, v_17935, v_17934);
    if (v_17934 == nil) goto v_17302;
    else goto v_17303;
v_17302:
    v_17934 = stack[-8];
    fn = elt(env, 54); // load!-package
    v_17934 = (*qfn1(fn))(fn, v_17934);
    env = stack[-9];
    goto v_17323;
v_17319:
    v_17935 = stack[-8];
    goto v_17320;
v_17321:
    v_17934 = elt(env, 10); // folder
    goto v_17322;
v_17323:
    goto v_17319;
v_17320:
    goto v_17321;
v_17322:
    v_17934 = get(v_17935, v_17934);
    env = stack[-9];
    if (v_17934 == nil) goto v_17317;
    goto v_17331;
v_17327:
    v_17935 = stack[-8];
    goto v_17328;
v_17329:
    v_17934 = elt(env, 10); // folder
    goto v_17330;
v_17331:
    goto v_17327;
v_17328:
    goto v_17329;
v_17330:
    v_17934 = get(v_17935, v_17934);
    env = stack[-9];
    stack[-8] = v_17934;
    goto v_17315;
v_17317:
v_17315:
    goto v_17339;
v_17335:
    v_17935 = elt(env, 11); // "$reduce/packages/"
    goto v_17336;
v_17337:
    v_17934 = stack[-8];
    goto v_17338;
v_17339:
    goto v_17335;
v_17336:
    goto v_17337;
v_17338:
    fn = elt(env, 55); // concat
    v_17934 = (*qfn2(fn))(fn, v_17935, v_17934);
    env = stack[-9];
    qvalue(elt(env, 12)) = v_17934; // testdirectory
    goto v_17347;
v_17343:
    stack[-1] = elt(env, 11); // "$reduce/packages/"
    goto v_17344;
v_17345:
    goto v_17354;
v_17350:
    stack[-3] = stack[-8];
    goto v_17351;
v_17352:
    goto v_17361;
v_17357:
    stack[0] = elt(env, 13); // "/"
    goto v_17358;
v_17359:
    goto v_17368;
v_17364:
    v_17934 = stack[-7];
    v_17935 = qcar(v_17934);
    goto v_17365;
v_17366:
    v_17934 = elt(env, 14); // ".tst"
    goto v_17367;
v_17368:
    goto v_17364;
v_17365:
    goto v_17366;
v_17367:
    fn = elt(env, 55); // concat
    v_17934 = (*qfn2(fn))(fn, v_17935, v_17934);
    env = stack[-9];
    goto v_17360;
v_17361:
    goto v_17357;
v_17358:
    goto v_17359;
v_17360:
    fn = elt(env, 55); // concat
    v_17934 = (*qfn2(fn))(fn, stack[0], v_17934);
    env = stack[-9];
    goto v_17353;
v_17354:
    goto v_17350;
v_17351:
    goto v_17352;
v_17353:
    fn = elt(env, 55); // concat
    v_17934 = (*qfn2(fn))(fn, stack[-3], v_17934);
    env = stack[-9];
    goto v_17346;
v_17347:
    goto v_17343;
v_17344:
    goto v_17345;
v_17346:
    fn = elt(env, 55); // concat
    v_17934 = (*qfn2(fn))(fn, stack[-1], v_17934);
    env = stack[-9];
    stack[-8] = v_17934;
    v_17934 = (LispObject)1280+TAG_FIXNUM; // 80
    v_17934 = Llinelength(nil, v_17934);
    env = stack[-9];
    stack[-6] = v_17934;
    v_17934 = nil;
    v_17934 = ncons(v_17934);
    env = stack[-9];
    qvalue(elt(env, 15)) = v_17934; // alglist!*
    v_17934 = elt(env, 16); // algebraic
    qvalue(elt(env, 17)) = v_17934; // !*mode
    goto v_17384;
v_17380:
    v_17934 = elt(env, 18); // "[Profile] "
    stack[0] = Lexplodec(nil, v_17934);
    env = stack[-9];
    goto v_17381;
v_17382:
    v_17934 = stack[-7];
    v_17934 = qcar(v_17934);
    v_17934 = Lexplodec(nil, v_17934);
    env = stack[-9];
    goto v_17383;
v_17384:
    goto v_17380;
v_17381:
    goto v_17382;
v_17383:
    v_17934 = Lappend(nil, stack[0], v_17934);
    env = stack[-9];
    fn = elt(env, 56); // list!-to!-string
    v_17934 = (*qfn1(fn))(fn, v_17934);
    env = stack[-9];
    fn = elt(env, 57); // window!-heading
    v_17934 = (*qfn1(fn))(fn, v_17934);
    env = stack[-9];
    v_17934 = elt(env, 19); // quit
    fn = elt(env, 58); // getd
    v_17934 = (*qfn1(fn))(fn, v_17934);
    env = stack[-9];
    stack[-3] = v_17934;
    v_17934 = elt(env, 19); // quit
    v_17934 = Lremd(nil, v_17934);
    env = stack[-9];
    goto v_17401;
v_17395:
    v_17936 = elt(env, 19); // quit
    goto v_17396;
v_17397:
    v_17935 = elt(env, 20); // expr
    goto v_17398;
v_17399:
    v_17934 = elt(env, 21); // posn
    goto v_17400;
v_17401:
    goto v_17395;
v_17396:
    goto v_17397;
v_17398:
    goto v_17399;
v_17400:
    fn = elt(env, 59); // putd
    v_17934 = (*qfnn(fn))(fn, 3, v_17936, v_17935, v_17934);
    env = stack[-9];
    v_17934 = (LispObject)64+TAG_FIXNUM; // 4
    v_17934 = Lmapstore(nil, v_17934);
    env = stack[-9];
    v_17934 = lisp_true;
    qvalue(elt(env, 1)) = v_17934; // !*errcont
    v_17934 = nil;
    v_17934 = Lwrs(nil, v_17934);
    env = stack[-9];
    stack[-5] = v_17934;
    v_17934 = nil;
    v_17934 = Lrds(nil, v_17934);
    env = stack[-9];
    stack[-4] = v_17934;
    v_17934 = stack[-5];
    v_17934 = Lwrs(nil, v_17934);
    env = stack[-9];
    v_17934 = stack[-4];
    v_17934 = Lrds(nil, v_17934);
    env = stack[-9];
    goto v_17427;
v_17417:
    goto v_17437;
v_17429:
    stack[-1] = elt(env, 22); // errorset
    goto v_17430;
v_17431:
    goto v_17447;
v_17441:
    stack[0] = elt(env, 23); // in_list1
    goto v_17442;
v_17443:
    v_17934 = stack[-8];
    v_17935 = Lmkquote(nil, v_17934);
    env = stack[-9];
    goto v_17444;
v_17445:
    v_17934 = lisp_true;
    goto v_17446;
v_17447:
    goto v_17441;
v_17442:
    goto v_17443;
v_17444:
    goto v_17445;
v_17446:
    v_17934 = list3(stack[0], v_17935, v_17934);
    env = stack[-9];
    v_17936 = Lmkquote(nil, v_17934);
    env = stack[-9];
    goto v_17432;
v_17433:
    v_17935 = nil;
    goto v_17434;
v_17435:
    v_17934 = nil;
    goto v_17436;
v_17437:
    goto v_17429;
v_17430:
    goto v_17431;
v_17432:
    goto v_17433;
v_17434:
    goto v_17435;
v_17436:
    v_17938 = list4(stack[-1], v_17936, v_17935, v_17934);
    env = stack[-9];
    goto v_17418;
v_17419:
    v_17937 = qvalue(elt(env, 2)); // cpulimit
    goto v_17420;
v_17421:
    v_17936 = qvalue(elt(env, 5)); // conslimit
    goto v_17422;
v_17423:
    v_17935 = (LispObject)160000+TAG_FIXNUM; // 10000
    goto v_17424;
v_17425:
    v_17934 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_17426;
v_17427:
    goto v_17417;
v_17418:
    goto v_17419;
v_17420:
    goto v_17421;
v_17422:
    goto v_17423;
v_17424:
    goto v_17425;
v_17426:
    fn = elt(env, 60); // resource!-limit
    v_17934 = (*qfnn(fn))(fn, 5, v_17938, v_17937, v_17936, v_17935, v_17934);
    env = stack[-9];
    stack[0] = v_17934;
    v_17934 = stack[-5];
    v_17934 = Lwrs(nil, v_17934);
    env = stack[-9];
    v_17934 = stack[-4];
    v_17934 = Lrds(nil, v_17934);
    env = stack[-9];
    v_17934 = nil;
    qvalue(elt(env, 24)) = v_17934; // erfg!*
    v_17934 = Lterpri(nil, 0);
    env = stack[-9];
    goto v_17471;
v_17465:
    v_17936 = elt(env, 19); // quit
    goto v_17466;
v_17467:
    v_17934 = stack[-3];
    v_17935 = qcar(v_17934);
    goto v_17468;
v_17469:
    v_17934 = stack[-3];
    v_17934 = qcdr(v_17934);
    goto v_17470;
v_17471:
    goto v_17465;
v_17466:
    goto v_17467;
v_17468:
    goto v_17469;
v_17470:
    fn = elt(env, 59); // putd
    v_17934 = (*qfnn(fn))(fn, 3, v_17936, v_17935, v_17934);
    env = stack[-9];
    goto v_17482;
v_17478:
    v_17934 = (LispObject)32+TAG_FIXNUM; // 2
    v_17935 = Lmapstore(nil, v_17934);
    env = stack[-9];
    goto v_17479;
v_17480:
    v_17934 = elt(env, 25); // profile_compare_fn
    goto v_17481;
v_17482:
    goto v_17478;
v_17479:
    goto v_17480;
v_17481:
    fn = elt(env, 61); // sort
    v_17934 = (*qfn2(fn))(fn, v_17935, v_17934);
    env = stack[-9];
    stack[-5] = v_17934;
    goto v_17495;
v_17491:
    v_17935 = elt(env, 26); // "buildlogs/flaguse.log"
    goto v_17492;
v_17493:
    v_17934 = elt(env, 27); // append
    goto v_17494;
v_17495:
    goto v_17491;
v_17492:
    goto v_17493;
v_17494:
    fn = elt(env, 62); // open
    v_17934 = (*qfn2(fn))(fn, v_17935, v_17934);
    env = stack[-9];
    v_17934 = Lwrs(nil, v_17934);
    env = stack[-9];
    stack[-1] = v_17934;
    v_17934 = lisp_true;
    fn = elt(env, 63); // bytecounts
    v_17934 = (*qfn1(fn))(fn, v_17934);
    env = stack[-9];
    v_17934 = stack[-1];
    v_17934 = Lwrs(nil, v_17934);
    env = stack[-9];
    v_17934 = Lclose(nil, v_17934);
    env = stack[-9];
    fn = elt(env, 64); // load!-source
    v_17934 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    v_17934 = nil;
    stack[-4] = v_17934;
v_17507:
    v_17934 = stack[-5];
    if (v_17934 == nil) goto v_17510;
    else goto v_17511;
v_17510:
    goto v_17506;
v_17511:
    goto v_17519;
v_17515:
    v_17934 = stack[-5];
    v_17934 = qcar(v_17934);
    v_17935 = qcar(v_17934);
    goto v_17516;
v_17517:
    v_17934 = elt(env, 28); // !*savedef
    goto v_17518;
v_17519:
    goto v_17515;
v_17516:
    goto v_17517;
v_17518:
    v_17934 = get(v_17935, v_17934);
    env = stack[-9];
    v_17936 = v_17934;
    goto v_17533;
v_17529:
    v_17935 = v_17936;
    goto v_17530;
v_17531:
    v_17934 = elt(env, 29); // lambda
    goto v_17532;
v_17533:
    goto v_17529;
v_17530:
    goto v_17531;
v_17532:
    if (!consp(v_17935)) goto v_17527;
    v_17935 = qcar(v_17935);
    if (v_17935 == v_17934) goto v_17526;
    else goto v_17527;
v_17526:
    goto v_17543;
v_17537:
    v_17934 = stack[-5];
    v_17934 = qcar(v_17934);
    stack[-1] = qcar(v_17934);
    goto v_17538;
v_17539:
    goto v_17554;
v_17548:
    goto v_17561;
v_17557:
    v_17934 = stack[-5];
    v_17934 = qcar(v_17934);
    v_17934 = qcar(v_17934);
    goto v_17558;
v_17559:
    v_17935 = v_17936;
    v_17935 = qcdr(v_17935);
    goto v_17560;
v_17561:
    goto v_17557;
v_17558:
    goto v_17559;
v_17560:
    v_17934 = cons(v_17934, v_17935);
    env = stack[-9];
    fn = elt(env, 65); // md60
    v_17936 = (*qfn1(fn))(fn, v_17934);
    env = stack[-9];
    goto v_17549;
v_17550:
    v_17934 = stack[-5];
    v_17934 = qcar(v_17934);
    v_17934 = qcdr(v_17934);
    v_17935 = qcar(v_17934);
    goto v_17551;
v_17552:
    v_17934 = stack[-5];
    v_17934 = qcar(v_17934);
    v_17934 = qcdr(v_17934);
    v_17934 = qcdr(v_17934);
    v_17934 = qcar(v_17934);
    goto v_17553;
v_17554:
    goto v_17548;
v_17549:
    goto v_17550;
v_17551:
    goto v_17552;
v_17553:
    v_17935 = list2star(v_17936, v_17935, v_17934);
    env = stack[-9];
    goto v_17540;
v_17541:
    v_17934 = stack[-4];
    goto v_17542;
v_17543:
    goto v_17537;
v_17538:
    goto v_17539;
v_17540:
    goto v_17541;
v_17542:
    v_17934 = acons(stack[-1], v_17935, v_17934);
    env = stack[-9];
    stack[-4] = v_17934;
    goto v_17525;
v_17527:
v_17525:
    v_17934 = stack[-5];
    v_17934 = qcdr(v_17934);
    stack[-5] = v_17934;
    goto v_17507;
v_17506:
    v_17934 = stack[-4];
    stack[-5] = v_17934;
    v_17934 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_17934;
v_17583:
    goto v_17595;
v_17591:
    v_17935 = (LispObject)5584+TAG_FIXNUM; // 349
    goto v_17592;
v_17593:
    v_17934 = stack[-1];
    goto v_17594;
v_17595:
    goto v_17591;
v_17592:
    goto v_17593;
v_17594:
    v_17934 = difference2(v_17935, v_17934);
    env = stack[-9];
    v_17934 = Lminusp(nil, v_17934);
    env = stack[-9];
    if (v_17934 == nil) goto v_17588;
    goto v_17582;
v_17588:
    v_17934 = stack[-4];
    if (v_17934 == nil) goto v_17602;
    v_17934 = stack[-4];
    v_17934 = qcdr(v_17934);
    stack[-4] = v_17934;
    goto v_17600;
v_17602:
v_17600:
    v_17934 = stack[-1];
    v_17934 = add1(v_17934);
    env = stack[-9];
    stack[-1] = v_17934;
    goto v_17583;
v_17582:
    v_17934 = stack[-4];
    if (v_17934 == nil) goto v_17611;
    goto v_17618;
v_17614:
    v_17935 = stack[-4];
    goto v_17615;
v_17616:
    v_17934 = nil;
    goto v_17617;
v_17618:
    goto v_17614;
v_17615:
    goto v_17616;
v_17617:
    v_17934 = Lrplacd(nil, v_17935, v_17934);
    env = stack[-9];
    goto v_17609;
v_17611:
v_17609:
    goto v_17626;
v_17622:
    v_17935 = elt(env, 30); // "profile.dat"
    goto v_17623;
v_17624:
    v_17934 = elt(env, 27); // append
    goto v_17625;
v_17626:
    goto v_17622;
v_17623:
    goto v_17624;
v_17625:
    fn = elt(env, 62); // open
    v_17934 = (*qfn2(fn))(fn, v_17935, v_17934);
    env = stack[-9];
    stack[-4] = v_17934;
    v_17934 = stack[-4];
    v_17934 = Lwrs(nil, v_17934);
    env = stack[-9];
    stack[-4] = v_17934;
    v_17934 = (LispObject)1280+TAG_FIXNUM; // 80
    v_17934 = Llinelength(nil, v_17934);
    env = stack[-9];
    v_17934 = stack[0];
    if (!consp(v_17934)) goto v_17635;
    else goto v_17636;
v_17635:
    v_17934 = elt(env, 31); // "% +++++ Error: Resource limit exceeded"
    v_17934 = Lprintc(nil, v_17934);
    env = stack[-9];
    goto v_17634;
v_17636:
v_17634:
    v_17934 = elt(env, 32); // "% @@@@@ Resources used: "
    v_17934 = Lprinc(nil, v_17934);
    env = stack[-9];
    v_17934 = qvalue(elt(env, 33)); // !*resources!*
    v_17934 = Lprint(nil, v_17934);
    env = stack[-9];
    v_17934 = elt(env, 34); // "("
    v_17934 = Lprinc(nil, v_17934);
    env = stack[-9];
    v_17934 = stack[-7];
    v_17934 = qcar(v_17934);
    v_17934 = Lprin(nil, v_17934);
    env = stack[-9];
    v_17934 = Lterpri(nil, 0);
    env = stack[-9];
    v_17934 = stack[-5];
    stack[-1] = v_17934;
v_17653:
    v_17934 = stack[-1];
    if (v_17934 == nil) goto v_17657;
    else goto v_17658;
v_17657:
    goto v_17652;
v_17658:
    v_17934 = stack[-1];
    v_17934 = qcar(v_17934);
    stack[0] = v_17934;
    v_17934 = elt(env, 35); // "  ("
    v_17934 = Lprinc(nil, v_17934);
    env = stack[-9];
    v_17934 = stack[0];
    v_17934 = qcar(v_17934);
    v_17934 = Lprin(nil, v_17934);
    env = stack[-9];
    v_17934 = elt(env, 36); // " "
    v_17934 = Lprinc(nil, v_17934);
    env = stack[-9];
    goto v_17680;
v_17676:
    v_17935 = Lposn(nil, 0);
    env = stack[-9];
    goto v_17677;
v_17678:
    v_17934 = (LispObject)480+TAG_FIXNUM; // 30
    goto v_17679;
v_17680:
    goto v_17676;
v_17677:
    goto v_17678;
v_17679:
    v_17934 = (LispObject)greaterp2(v_17935, v_17934);
    v_17934 = v_17934 ? lisp_true : nil;
    env = stack[-9];
    if (v_17934 == nil) goto v_17674;
    v_17934 = Lterpri(nil, 0);
    env = stack[-9];
    v_17934 = (LispObject)480+TAG_FIXNUM; // 30
    v_17934 = Lttab(nil, v_17934);
    env = stack[-9];
    goto v_17672;
v_17674:
v_17672:
    v_17934 = stack[0];
    v_17934 = qcdr(v_17934);
    v_17934 = qcar(v_17934);
    v_17934 = Lprin(nil, v_17934);
    env = stack[-9];
    v_17934 = elt(env, 36); // " "
    v_17934 = Lprinc(nil, v_17934);
    env = stack[-9];
    v_17934 = stack[0];
    v_17934 = qcdr(v_17934);
    v_17934 = qcdr(v_17934);
    v_17934 = qcar(v_17934);
    v_17934 = Lprin(nil, v_17934);
    env = stack[-9];
    v_17934 = elt(env, 36); // " "
    v_17934 = Lprinc(nil, v_17934);
    env = stack[-9];
    v_17934 = stack[0];
    v_17934 = qcdr(v_17934);
    v_17934 = qcdr(v_17934);
    v_17934 = qcdr(v_17934);
    v_17934 = Lprinc(nil, v_17934);
    env = stack[-9];
    v_17934 = elt(env, 37); // ")"
    v_17934 = Lprintc(nil, v_17934);
    env = stack[-9];
    v_17934 = stack[-1];
    v_17934 = qcdr(v_17934);
    stack[-1] = v_17934;
    goto v_17653;
v_17652:
    v_17934 = elt(env, 38); // "  )"
    v_17934 = Lprintc(nil, v_17934);
    env = stack[-9];
    v_17934 = Lterpri(nil, 0);
    env = stack[-9];
    v_17934 = stack[-4];
    v_17934 = Lwrs(nil, v_17934);
    env = stack[-9];
    v_17934 = Lclose(nil, v_17934);
    env = stack[-9];
    v_17934 = stack[-6];
    v_17934 = Llinelength(nil, v_17934);
    env = stack[-9];
    goto v_17301;
v_17303:
v_17301:
    v_17934 = stack[-7];
    v_17934 = qcdr(v_17934);
    stack[-7] = v_17934;
    v_17934 = stack[-7];
    if (v_17934 == nil) goto v_17720;
    else goto v_17721;
v_17720:
    goto v_17728;
v_17724:
    v_17935 = elt(env, 26); // "buildlogs/flaguse.log"
    goto v_17725;
v_17726:
    v_17934 = elt(env, 39); // input
    goto v_17727;
v_17728:
    goto v_17724;
v_17725:
    goto v_17726;
v_17727:
    fn = elt(env, 62); // open
    v_17934 = (*qfn2(fn))(fn, v_17935, v_17934);
    env = stack[-9];
    stack[-4] = v_17934;
    v_17934 = stack[-4];
    v_17934 = Lrds(nil, v_17934);
    env = stack[-9];
    stack[-4] = v_17934;
    v_17934 = nil;
    stack[-5] = v_17934;
v_17736:
    goto v_17745;
v_17741:
    v_17935 = Lread(nil, 0);
    env = stack[-9];
    v_17936 = v_17935;
    goto v_17742;
v_17743:
    v_17934 = qvalue(elt(env, 40)); // !$eof!$
    goto v_17744;
v_17745:
    goto v_17741;
v_17742:
    goto v_17743;
v_17744:
    if (equal(v_17935, v_17934)) goto v_17739;
    else goto v_17740;
v_17739:
    goto v_17735;
v_17740:
    goto v_17754;
v_17750:
    goto v_17760;
v_17756:
    v_17935 = v_17936;
    goto v_17757;
v_17758:
    v_17934 = elt(env, 41); // orderp
    goto v_17759;
v_17760:
    goto v_17756;
v_17757:
    goto v_17758;
v_17759:
    fn = elt(env, 61); // sort
    v_17935 = (*qfn2(fn))(fn, v_17935, v_17934);
    env = stack[-9];
    goto v_17751;
v_17752:
    v_17934 = stack[-5];
    goto v_17753;
v_17754:
    goto v_17750;
v_17751:
    goto v_17752;
v_17753:
    v_17934 = cons(v_17935, v_17934);
    env = stack[-9];
    stack[-5] = v_17934;
    goto v_17736;
v_17735:
    v_17934 = stack[-4];
    v_17934 = Lrds(nil, v_17934);
    env = stack[-9];
    v_17934 = Lclose(nil, v_17934);
    env = stack[-9];
    v_17934 = elt(env, 42); // ((symbol!-make!-fastget (quote lose) 1) (symbol!-make!-fastget (quote noncom) 0))
    stack[0] = v_17934;
    goto v_17773;
v_17769:
    v_17935 = elt(env, 43); // (lose noncom)
    goto v_17770;
v_17771:
    v_17934 = elt(env, 44); // processed
    goto v_17772;
v_17773:
    goto v_17769;
v_17770:
    goto v_17771;
v_17772:
    v_17934 = Lflag(nil, v_17935, v_17934);
    env = stack[-9];
    v_17934 = (LispObject)32+TAG_FIXNUM; // 2
    stack[-6] = v_17934;
v_17779:
    v_17934 = stack[-5];
    if (v_17934 == nil) goto v_17782;
    else goto v_17783;
v_17782:
    goto v_17778;
v_17783:
    v_17934 = nil;
    stack[-4] = v_17934;
    v_17934 = stack[-5];
    stack[-5] = v_17934;
v_17790:
    v_17934 = stack[-5];
    if (v_17934 == nil) goto v_17794;
    else goto v_17795;
v_17794:
    goto v_17789;
v_17795:
    v_17934 = stack[-5];
    v_17934 = qcar(v_17934);
    stack[-3] = v_17934;
    v_17934 = stack[-3];
    if (v_17934 == nil) goto v_17804;
    goto v_17817;
v_17813:
    v_17934 = stack[-3];
    v_17934 = qcar(v_17934);
    v_17934 = qcdr(v_17934);
    v_17935 = qcar(v_17934);
    goto v_17814;
v_17815:
    v_17934 = elt(env, 44); // processed
    goto v_17816;
v_17817:
    goto v_17813;
v_17814:
    goto v_17815;
v_17816:
    v_17934 = Lflagp(nil, v_17935, v_17934);
    env = stack[-9];
    if (v_17934 == nil) goto v_17810;
    else goto v_17811;
v_17810:
    goto v_17828;
v_17824:
    v_17935 = stack[-6];
    goto v_17825;
v_17826:
    v_17934 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_17827;
v_17828:
    goto v_17824;
v_17825:
    goto v_17826;
v_17827:
    v_17934 = (LispObject)lessp2(v_17935, v_17934);
    v_17934 = v_17934 ? lisp_true : nil;
    env = stack[-9];
    goto v_17809;
v_17811:
    v_17934 = nil;
    goto v_17809;
    v_17934 = nil;
v_17809:
    if (v_17934 == nil) goto v_17804;
    goto v_17839;
v_17835:
    goto v_17847;
v_17841:
    stack[-1] = elt(env, 45); // symbol!-make!-fastget
    goto v_17842;
v_17843:
    v_17934 = stack[-3];
    v_17934 = qcar(v_17934);
    v_17934 = qcdr(v_17934);
    v_17934 = qcar(v_17934);
    v_17935 = Lmkquote(nil, v_17934);
    env = stack[-9];
    goto v_17844;
v_17845:
    v_17934 = stack[-6];
    goto v_17846;
v_17847:
    goto v_17841;
v_17842:
    goto v_17843;
v_17844:
    goto v_17845;
v_17846:
    v_17935 = list3(stack[-1], v_17935, v_17934);
    env = stack[-9];
    goto v_17836;
v_17837:
    v_17934 = stack[0];
    goto v_17838;
v_17839:
    goto v_17835;
v_17836:
    goto v_17837;
v_17838:
    v_17934 = cons(v_17935, v_17934);
    env = stack[-9];
    stack[0] = v_17934;
    goto v_17861;
v_17857:
    v_17934 = stack[-3];
    v_17934 = qcar(v_17934);
    v_17934 = qcdr(v_17934);
    v_17934 = qcar(v_17934);
    v_17935 = ncons(v_17934);
    env = stack[-9];
    goto v_17858;
v_17859:
    v_17934 = elt(env, 44); // processed
    goto v_17860;
v_17861:
    goto v_17857;
v_17858:
    goto v_17859;
v_17860:
    v_17934 = Lflag(nil, v_17935, v_17934);
    env = stack[-9];
    v_17934 = stack[-6];
    v_17934 = add1(v_17934);
    env = stack[-9];
    stack[-6] = v_17934;
    goto v_17802;
v_17804:
v_17802:
    v_17934 = stack[-3];
    v_17934 = qcdr(v_17934);
    if (v_17934 == nil) goto v_17873;
    goto v_17881;
v_17877:
    v_17934 = stack[-3];
    v_17935 = qcdr(v_17934);
    goto v_17878;
v_17879:
    v_17934 = stack[-4];
    goto v_17880;
v_17881:
    goto v_17877;
v_17878:
    goto v_17879;
v_17880:
    v_17934 = cons(v_17935, v_17934);
    env = stack[-9];
    stack[-4] = v_17934;
    goto v_17871;
v_17873:
v_17871:
    v_17934 = stack[-5];
    v_17934 = qcdr(v_17934);
    stack[-5] = v_17934;
    goto v_17790;
v_17789:
    v_17934 = stack[-4];
    v_17934 = Lreverse(nil, v_17934);
    env = stack[-9];
    stack[-5] = v_17934;
    goto v_17779;
v_17778:
    goto v_17894;
v_17890:
    v_17935 = elt(env, 46); // "buildlogs/fastgets.lsp"
    goto v_17891;
v_17892:
    v_17934 = elt(env, 47); // output
    goto v_17893;
v_17894:
    goto v_17890;
v_17891:
    goto v_17892;
v_17893:
    fn = elt(env, 62); // open
    v_17934 = (*qfn2(fn))(fn, v_17935, v_17934);
    env = stack[-9];
    stack[-5] = v_17934;
    v_17934 = stack[-5];
    v_17934 = Lwrs(nil, v_17934);
    env = stack[-9];
    stack[-5] = v_17934;
    v_17934 = elt(env, 48); // "% fastgets.lsp generated by profiling"
    v_17934 = Lprintc(nil, v_17934);
    env = stack[-9];
    v_17934 = Lterpri(nil, 0);
    env = stack[-9];
    goto v_17908;
v_17904:
    stack[-1] = elt(env, 49); // progn
    goto v_17905;
v_17906:
    v_17934 = stack[0];
    v_17934 = Lreverse(nil, v_17934);
    env = stack[-9];
    goto v_17907;
v_17908:
    goto v_17904;
v_17905:
    goto v_17906;
v_17907:
    v_17934 = cons(stack[-1], v_17934);
    env = stack[-9];
    fn = elt(env, 66); // prettyprint
    v_17934 = (*qfn1(fn))(fn, v_17934);
    env = stack[-9];
    v_17934 = Lterpri(nil, 0);
    env = stack[-9];
    v_17934 = elt(env, 50); // "% end of fastgets.lsp"
    v_17934 = Lprintc(nil, v_17934);
    env = stack[-9];
    v_17934 = stack[-5];
    v_17934 = Lwrs(nil, v_17934);
    env = stack[-9];
    v_17934 = Lclose(nil, v_17934);
    env = stack[-9];
    v_17934 = elt(env, 51); // "Profiling complete"
    v_17934 = Lprintc(nil, v_17934);
    env = stack[-9];
    v_17934 = elt(env, 51); // "Profiling complete"
    fn = elt(env, 57); // window!-heading
    v_17934 = (*qfn1(fn))(fn, v_17934);
    env = stack[-9];
    v_17934 = lisp_true;
    fn = elt(env, 67); // restart!-csl
    v_17934 = (*qfn1(fn))(fn, v_17934);
    goto v_17719;
v_17721:
    goto v_17931;
v_17927:
    v_17935 = elt(env, 52); // (remake profile_a_package)
    goto v_17928;
v_17929:
    v_17934 = stack[-7];
    goto v_17930;
v_17931:
    goto v_17927;
v_17928:
    goto v_17929;
v_17930:
    fn = elt(env, 67); // restart!-csl
    v_17934 = (*qfn2(fn))(fn, v_17935, v_17934);
    goto v_17719;
v_17719:
    v_17934 = nil;
    ;}  // end of a binding scope
    return onevalue(v_17934);
}



// Code for ofsf_siatsubf

static LispObject CC_ofsf_siatsubf(LispObject env,
                         LispObject v_17194, LispObject v_17195)
{
    env = qenv(env);
    LispObject v_17313, v_17314, v_17315;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_17195,v_17194);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_17194,v_17195);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_17195;
    stack[-1] = v_17194;
// end of prologue
    v_17313 = stack[-1];
    if (!consp(v_17313)) goto v_17208;
    else goto v_17209;
v_17208:
    v_17313 = lisp_true;
    goto v_17207;
v_17209:
    v_17313 = stack[-1];
    v_17313 = qcar(v_17313);
    v_17313 = (consp(v_17313) ? nil : lisp_true);
    goto v_17207;
    v_17313 = nil;
v_17207:
    if (v_17313 == nil) goto v_17205;
    goto v_17222;
v_17218:
    v_17314 = stack[-1];
    goto v_17219;
v_17220:
    v_17313 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17221;
v_17222:
    goto v_17218;
v_17219:
    goto v_17220;
v_17221:
    return cons(v_17314, v_17313);
v_17205:
    goto v_17230;
v_17226:
    v_17313 = stack[-1];
    v_17314 = qcdr(v_17313);
    goto v_17227;
v_17228:
    v_17313 = stack[0];
    goto v_17229;
v_17230:
    goto v_17226;
v_17227:
    goto v_17228;
v_17229:
    v_17313 = CC_ofsf_siatsubf(elt(env, 0), v_17314, v_17313);
    env = stack[-3];
    stack[-2] = v_17313;
    goto v_17239;
v_17235:
    v_17313 = stack[-1];
    v_17313 = qcar(v_17313);
    v_17314 = qcdr(v_17313);
    goto v_17236;
v_17237:
    v_17313 = stack[0];
    goto v_17238;
v_17239:
    goto v_17235;
v_17236:
    goto v_17237;
v_17238:
    v_17313 = CC_ofsf_siatsubf(elt(env, 0), v_17314, v_17313);
    env = stack[-3];
    v_17314 = v_17313;
    goto v_17252;
v_17248:
    v_17313 = stack[-1];
    v_17313 = qcar(v_17313);
    v_17313 = qcar(v_17313);
    v_17315 = qcar(v_17313);
    goto v_17249;
v_17250:
    v_17313 = stack[0];
    goto v_17251;
v_17252:
    goto v_17248;
v_17249:
    goto v_17250;
v_17251:
    v_17313 = Latsoc(nil, v_17315, v_17313);
    v_17315 = v_17313;
    if (v_17313 == nil) goto v_17247;
    goto v_17264;
v_17260:
    goto v_17270;
v_17266:
    stack[0] = v_17314;
    goto v_17267;
v_17268:
    goto v_17277;
v_17273:
    v_17313 = v_17315;
    v_17314 = qcdr(v_17313);
    goto v_17274;
v_17275:
    v_17313 = stack[-1];
    v_17313 = qcar(v_17313);
    v_17313 = qcar(v_17313);
    v_17313 = qcdr(v_17313);
    goto v_17276;
v_17277:
    goto v_17273;
v_17274:
    goto v_17275;
v_17276:
    fn = elt(env, 1); // exptsq
    v_17313 = (*qfn2(fn))(fn, v_17314, v_17313);
    env = stack[-3];
    goto v_17269;
v_17270:
    goto v_17266;
v_17267:
    goto v_17268;
v_17269:
    fn = elt(env, 2); // multsq
    v_17314 = (*qfn2(fn))(fn, stack[0], v_17313);
    env = stack[-3];
    goto v_17261;
v_17262:
    v_17313 = stack[-2];
    goto v_17263;
v_17264:
    goto v_17260;
v_17261:
    goto v_17262;
v_17263:
    {
        fn = elt(env, 3); // addsq
        return (*qfn2(fn))(fn, v_17314, v_17313);
    }
v_17247:
    goto v_17290;
v_17286:
    goto v_17296;
v_17292:
    stack[0] = v_17314;
    goto v_17293;
v_17294:
    goto v_17303;
v_17299:
    v_17313 = stack[-1];
    v_17313 = qcar(v_17313);
    v_17313 = qcar(v_17313);
    v_17314 = qcar(v_17313);
    goto v_17300;
v_17301:
    v_17313 = stack[-1];
    v_17313 = qcar(v_17313);
    v_17313 = qcar(v_17313);
    v_17313 = qcdr(v_17313);
    goto v_17302;
v_17303:
    goto v_17299;
v_17300:
    goto v_17301;
v_17302:
    fn = elt(env, 4); // ofsf_pow2q
    v_17313 = (*qfn2(fn))(fn, v_17314, v_17313);
    env = stack[-3];
    goto v_17295;
v_17296:
    goto v_17292;
v_17293:
    goto v_17294;
v_17295:
    fn = elt(env, 2); // multsq
    v_17314 = (*qfn2(fn))(fn, stack[0], v_17313);
    env = stack[-3];
    goto v_17287;
v_17288:
    v_17313 = stack[-2];
    goto v_17289;
v_17290:
    goto v_17286;
v_17287:
    goto v_17288;
v_17289:
    {
        fn = elt(env, 3); // addsq
        return (*qfn2(fn))(fn, v_17314, v_17313);
    }
    return onevalue(v_17313);
}



// Code for monomgetfirstmultivar

static LispObject CC_monomgetfirstmultivar(LispObject env,
                         LispObject v_17194)
{
    env = qenv(env);
    LispObject v_17223, v_17224, v_17225;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_17224 = v_17194;
// end of prologue
    goto v_17206;
v_17202:
    v_17225 = v_17224;
    goto v_17203;
v_17204:
    v_17223 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17205;
v_17206:
    goto v_17202;
v_17203:
    goto v_17204;
v_17205:
    v_17223 = *(LispObject *)((char *)v_17225 + (CELL-TAG_VECTOR) + (((intptr_t)v_17223-TAG_FIXNUM)/(16/CELL)));
    v_17223 = qcar(v_17223);
    if (v_17223 == nil) goto v_17201;
    goto v_17215;
v_17211:
    goto v_17212;
v_17213:
    v_17223 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17214;
v_17215:
    goto v_17211;
v_17212:
    goto v_17213;
v_17214:
    v_17223 = *(LispObject *)((char *)v_17224 + (CELL-TAG_VECTOR) + (((intptr_t)v_17223-TAG_FIXNUM)/(16/CELL)));
    v_17223 = qcar(v_17223);
    goto v_17199;
v_17201:
    v_17223 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17199;
    v_17223 = nil;
v_17199:
    return onevalue(v_17223);
}



// Code for ofsf_simplat1

static LispObject CC_ofsf_simplat1(LispObject env,
                         LispObject v_17194, LispObject v_17195)
{
    env = qenv(env);
    LispObject v_17399, v_17400, v_17401;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_17195,v_17194);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_17194,v_17195);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_17195;
    v_17401 = v_17194;
// end of prologue
    v_17399 = v_17401;
    v_17399 = qcar(v_17399);
    stack[-3] = v_17399;
    goto v_17211;
v_17207:
    v_17400 = stack[-3];
    goto v_17208;
v_17209:
    v_17399 = elt(env, 1); // (equal neq leq geq lessp greaterp)
    goto v_17210;
v_17211:
    goto v_17207;
v_17208:
    goto v_17209;
v_17210:
    v_17399 = Lmemq(nil, v_17400, v_17399);
    if (v_17399 == nil) goto v_17205;
    else goto v_17206;
v_17205:
    v_17399 = nil;
    goto v_17200;
v_17206:
    v_17399 = v_17401;
    v_17399 = qcdr(v_17399);
    v_17399 = qcar(v_17399);
    stack[-1] = v_17399;
    v_17399 = stack[-1];
    if (!consp(v_17399)) goto v_17225;
    else goto v_17226;
v_17225:
    v_17399 = lisp_true;
    goto v_17224;
v_17226:
    v_17399 = stack[-1];
    v_17399 = qcar(v_17399);
    v_17399 = (consp(v_17399) ? nil : lisp_true);
    goto v_17224;
    v_17399 = nil;
v_17224:
    if (v_17399 == nil) goto v_17222;
    goto v_17243;
v_17239:
    v_17400 = stack[-3];
    goto v_17240;
v_17241:
    v_17399 = stack[-1];
    goto v_17242;
v_17243:
    goto v_17239;
v_17240:
    goto v_17241;
v_17242:
    fn = elt(env, 11); // ofsf_evalatp
    v_17399 = (*qfn2(fn))(fn, v_17400, v_17399);
    env = stack[-4];
    if (v_17399 == nil) goto v_17237;
    v_17399 = elt(env, 2); // true
    goto v_17235;
v_17237:
    v_17399 = elt(env, 3); // false
    goto v_17235;
    v_17399 = nil;
v_17235:
    goto v_17200;
v_17222:
    goto v_17255;
v_17251:
    stack[0] = stack[-1];
    goto v_17252;
v_17253:
    v_17399 = stack[-1];
    fn = elt(env, 12); // sfto_dcontentf
    v_17399 = (*qfn1(fn))(fn, v_17399);
    env = stack[-4];
    goto v_17254;
v_17255:
    goto v_17251;
v_17252:
    goto v_17253;
v_17254:
    fn = elt(env, 13); // quotf
    v_17399 = (*qfn2(fn))(fn, stack[0], v_17399);
    env = stack[-4];
    stack[-1] = v_17399;
    v_17399 = stack[-1];
    fn = elt(env, 14); // minusf
    v_17399 = (*qfn1(fn))(fn, v_17399);
    env = stack[-4];
    if (v_17399 == nil) goto v_17262;
    v_17399 = stack[-1];
    fn = elt(env, 15); // negf
    v_17399 = (*qfn1(fn))(fn, v_17399);
    env = stack[-4];
    stack[-1] = v_17399;
    v_17399 = stack[-3];
    fn = elt(env, 16); // ofsf_anegrel
    v_17399 = (*qfn1(fn))(fn, v_17399);
    env = stack[-4];
    stack[-3] = v_17399;
    goto v_17260;
v_17262:
v_17260:
    v_17399 = qvalue(elt(env, 4)); // !*rlsiatadv
    if (v_17399 == nil) goto v_17271;
    else goto v_17272;
v_17271:
    goto v_17281;
v_17275:
    v_17401 = stack[-3];
    goto v_17276;
v_17277:
    v_17400 = stack[-1];
    goto v_17278;
v_17279:
    v_17399 = nil;
    goto v_17280;
v_17281:
    goto v_17275;
v_17276:
    goto v_17277;
v_17278:
    goto v_17279;
v_17280:
    return list3(v_17401, v_17400, v_17399);
v_17272:
    goto v_17293;
v_17289:
    v_17400 = stack[-3];
    goto v_17290;
v_17291:
    v_17399 = elt(env, 5); // equal
    goto v_17292;
v_17293:
    goto v_17289;
v_17290:
    goto v_17291;
v_17292:
    if (v_17400 == v_17399) goto v_17287;
    else goto v_17288;
v_17287:
    goto v_17301;
v_17297:
    v_17400 = stack[-1];
    goto v_17298;
v_17299:
    v_17399 = stack[-2];
    goto v_17300;
v_17301:
    goto v_17297;
v_17298:
    goto v_17299;
v_17300:
    {
        fn = elt(env, 17); // ofsf_simplequal
        return (*qfn2(fn))(fn, v_17400, v_17399);
    }
v_17288:
    goto v_17312;
v_17308:
    v_17400 = stack[-3];
    goto v_17309;
v_17310:
    v_17399 = elt(env, 6); // neq
    goto v_17311;
v_17312:
    goto v_17308;
v_17309:
    goto v_17310;
v_17311:
    if (v_17400 == v_17399) goto v_17306;
    else goto v_17307;
v_17306:
    goto v_17320;
v_17316:
    v_17400 = stack[-1];
    goto v_17317;
v_17318:
    v_17399 = stack[-2];
    goto v_17319;
v_17320:
    goto v_17316;
v_17317:
    goto v_17318;
v_17319:
    {
        fn = elt(env, 18); // ofsf_simplneq
        return (*qfn2(fn))(fn, v_17400, v_17399);
    }
v_17307:
    goto v_17331;
v_17327:
    v_17400 = stack[-3];
    goto v_17328;
v_17329:
    v_17399 = elt(env, 7); // leq
    goto v_17330;
v_17331:
    goto v_17327;
v_17328:
    goto v_17329;
v_17330:
    if (v_17400 == v_17399) goto v_17325;
    else goto v_17326;
v_17325:
    goto v_17339;
v_17335:
    v_17400 = stack[-1];
    goto v_17336;
v_17337:
    v_17399 = stack[-2];
    goto v_17338;
v_17339:
    goto v_17335;
v_17336:
    goto v_17337;
v_17338:
    {
        fn = elt(env, 19); // ofsf_simplleq
        return (*qfn2(fn))(fn, v_17400, v_17399);
    }
v_17326:
    goto v_17350;
v_17346:
    v_17400 = stack[-3];
    goto v_17347;
v_17348:
    v_17399 = elt(env, 8); // geq
    goto v_17349;
v_17350:
    goto v_17346;
v_17347:
    goto v_17348;
v_17349:
    if (v_17400 == v_17399) goto v_17344;
    else goto v_17345;
v_17344:
    goto v_17358;
v_17354:
    v_17400 = stack[-1];
    goto v_17355;
v_17356:
    v_17399 = stack[-2];
    goto v_17357;
v_17358:
    goto v_17354;
v_17355:
    goto v_17356;
v_17357:
    {
        fn = elt(env, 20); // ofsf_simplgeq
        return (*qfn2(fn))(fn, v_17400, v_17399);
    }
v_17345:
    goto v_17369;
v_17365:
    v_17400 = stack[-3];
    goto v_17366;
v_17367:
    v_17399 = elt(env, 9); // lessp
    goto v_17368;
v_17369:
    goto v_17365;
v_17366:
    goto v_17367;
v_17368:
    if (v_17400 == v_17399) goto v_17363;
    else goto v_17364;
v_17363:
    goto v_17377;
v_17373:
    v_17400 = stack[-1];
    goto v_17374;
v_17375:
    v_17399 = stack[-2];
    goto v_17376;
v_17377:
    goto v_17373;
v_17374:
    goto v_17375;
v_17376:
    {
        fn = elt(env, 21); // ofsf_simpllessp
        return (*qfn2(fn))(fn, v_17400, v_17399);
    }
v_17364:
    goto v_17388;
v_17384:
    v_17400 = stack[-3];
    goto v_17385;
v_17386:
    v_17399 = elt(env, 10); // greaterp
    goto v_17387;
v_17388:
    goto v_17384;
v_17385:
    goto v_17386;
v_17387:
    if (v_17400 == v_17399) goto v_17382;
    else goto v_17383;
v_17382:
    goto v_17396;
v_17392:
    v_17400 = stack[-1];
    goto v_17393;
v_17394:
    v_17399 = stack[-2];
    goto v_17395;
v_17396:
    goto v_17392;
v_17393:
    goto v_17394;
v_17395:
    {
        fn = elt(env, 22); // ofsf_simplgreaterp
        return (*qfn2(fn))(fn, v_17400, v_17399);
    }
v_17383:
    v_17399 = nil;
v_17200:
    return onevalue(v_17399);
}



// Code for containerml

static LispObject CC_containerml(LispObject env,
                         LispObject v_17194, LispObject v_17195)
{
    env = qenv(env);
    LispObject v_17237, v_17238;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_17195,v_17194);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_17194,v_17195);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_17195;
    stack[-1] = v_17194;
// end of prologue
    goto v_17207;
v_17203:
    v_17238 = stack[0];
    goto v_17204;
v_17205:
    v_17237 = elt(env, 1); // integer_interval
    goto v_17206;
v_17207:
    goto v_17203;
v_17204:
    goto v_17205;
v_17206:
    if (v_17238 == v_17237) goto v_17201;
    else goto v_17202;
v_17201:
    v_17237 = elt(env, 2); // interval
    stack[0] = v_17237;
    goto v_17200;
v_17202:
v_17200:
    v_17237 = elt(env, 3); // "<"
    fn = elt(env, 7); // printout
    v_17237 = (*qfn1(fn))(fn, v_17237);
    env = stack[-2];
    v_17237 = stack[0];
    v_17237 = Lprinc(nil, v_17237);
    env = stack[-2];
    goto v_17220;
v_17216:
    v_17237 = stack[-1];
    v_17238 = qcar(v_17237);
    goto v_17217;
v_17218:
    v_17237 = elt(env, 4); // ""
    goto v_17219;
v_17220:
    goto v_17216;
v_17217:
    goto v_17218;
v_17219:
    fn = elt(env, 8); // attributesml
    v_17237 = (*qfn2(fn))(fn, v_17238, v_17237);
    env = stack[-2];
    v_17237 = lisp_true;
    fn = elt(env, 9); // indent!*
    v_17237 = (*qfn1(fn))(fn, v_17237);
    env = stack[-2];
    v_17237 = stack[-1];
    v_17237 = qcdr(v_17237);
    fn = elt(env, 10); // multi_elem
    v_17237 = (*qfn1(fn))(fn, v_17237);
    env = stack[-2];
    v_17237 = nil;
    fn = elt(env, 9); // indent!*
    v_17237 = (*qfn1(fn))(fn, v_17237);
    env = stack[-2];
    v_17237 = elt(env, 5); // "</"
    fn = elt(env, 7); // printout
    v_17237 = (*qfn1(fn))(fn, v_17237);
    env = stack[-2];
    v_17237 = stack[0];
    v_17237 = Lprinc(nil, v_17237);
    env = stack[-2];
    v_17237 = elt(env, 6); // ">"
    v_17237 = Lprinc(nil, v_17237);
    v_17237 = nil;
    return onevalue(v_17237);
}



// Code for add_minus

static LispObject CC_add_minus(LispObject env,
                         LispObject v_17194)
{
    env = qenv(env);
    LispObject v_17378, v_17379;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_17194);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_17194);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_17194;
// end of prologue
    v_17378 = stack[-1];
    if (!consp(v_17378)) goto v_17200;
    else goto v_17201;
v_17200:
    v_17378 = stack[-1];
    goto v_17197;
v_17201:
    goto v_17214;
v_17210:
    v_17378 = stack[-1];
    v_17379 = qcar(v_17378);
    goto v_17211;
v_17212:
    v_17378 = elt(env, 1); // !:rd!:
    goto v_17213;
v_17214:
    goto v_17210;
v_17211:
    goto v_17212;
v_17213:
    if (v_17379 == v_17378) goto v_17208;
    else goto v_17209;
v_17208:
    goto v_17223;
v_17219:
    v_17378 = stack[-1];
    v_17379 = qcdr(v_17378);
    goto v_17220;
v_17221:
    v_17378 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17222;
v_17223:
    goto v_17219;
v_17220:
    goto v_17221;
v_17222:
    v_17378 = (LispObject)geq2(v_17379, v_17378);
    v_17378 = v_17378 ? lisp_true : nil;
    env = stack[-3];
    goto v_17207;
v_17209:
    v_17378 = nil;
    goto v_17207;
    v_17378 = nil;
v_17207:
    if (v_17378 == nil) goto v_17205;
    v_17378 = stack[-1];
    goto v_17197;
v_17205:
    goto v_17241;
v_17237:
    v_17378 = stack[-1];
    v_17379 = qcar(v_17378);
    goto v_17238;
v_17239:
    v_17378 = elt(env, 1); // !:rd!:
    goto v_17240;
v_17241:
    goto v_17237;
v_17238:
    goto v_17239;
v_17240:
    if (v_17379 == v_17378) goto v_17235;
    else goto v_17236;
v_17235:
    goto v_17250;
v_17246:
    v_17378 = stack[-1];
    v_17379 = qcdr(v_17378);
    goto v_17247;
v_17248:
    v_17378 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17249;
v_17250:
    goto v_17246;
v_17247:
    goto v_17248;
v_17249:
    v_17378 = (LispObject)lessp2(v_17379, v_17378);
    v_17378 = v_17378 ? lisp_true : nil;
    env = stack[-3];
    goto v_17234;
v_17236:
    v_17378 = nil;
    goto v_17234;
    v_17378 = nil;
v_17234:
    if (v_17378 == nil) goto v_17232;
    goto v_17262;
v_17258:
    stack[-2] = elt(env, 2); // minus
    goto v_17259;
v_17260:
    goto v_17269;
v_17265:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_17266;
v_17267:
    v_17378 = stack[-1];
    v_17378 = qcdr(v_17378);
    v_17378 = Labsval(nil, v_17378);
    env = stack[-3];
    goto v_17268;
v_17269:
    goto v_17265;
v_17266:
    goto v_17267;
v_17268:
    v_17378 = cons(stack[0], v_17378);
    goto v_17261;
v_17262:
    goto v_17258;
v_17259:
    goto v_17260;
v_17261:
    {
        LispObject v_17383 = stack[-2];
        return list2(v_17383, v_17378);
    }
v_17232:
    goto v_17284;
v_17280:
    v_17378 = stack[-1];
    v_17379 = qcar(v_17378);
    goto v_17281;
v_17282:
    v_17378 = elt(env, 2); // minus
    goto v_17283;
v_17284:
    goto v_17280;
v_17281:
    goto v_17282;
v_17283:
    if (v_17379 == v_17378) goto v_17278;
    else goto v_17279;
v_17278:
    v_17378 = stack[-1];
    v_17378 = qcdr(v_17378);
    v_17378 = qcar(v_17378);
    v_17378 = (is_number(v_17378) ? lisp_true : nil);
    goto v_17277;
v_17279:
    v_17378 = nil;
    goto v_17277;
    v_17378 = nil;
v_17277:
    if (v_17378 == nil) goto v_17275;
    v_17378 = stack[-1];
    goto v_17197;
v_17275:
    goto v_17306;
v_17302:
    v_17378 = stack[-1];
    v_17379 = qcar(v_17378);
    goto v_17303;
v_17304:
    v_17378 = elt(env, 2); // minus
    goto v_17305;
v_17306:
    goto v_17302;
v_17303:
    goto v_17304;
v_17305:
    if (v_17379 == v_17378) goto v_17300;
    else goto v_17301;
v_17300:
    goto v_17315;
v_17311:
    v_17378 = stack[-1];
    v_17378 = qcdr(v_17378);
    v_17378 = qcar(v_17378);
    v_17379 = qcdr(v_17378);
    goto v_17312;
v_17313:
    v_17378 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17314;
v_17315:
    goto v_17311;
v_17312:
    goto v_17313;
v_17314:
    v_17378 = (LispObject)lessp2(v_17379, v_17378);
    v_17378 = v_17378 ? lisp_true : nil;
    env = stack[-3];
    goto v_17299;
v_17301:
    v_17378 = nil;
    goto v_17299;
    v_17378 = nil;
v_17299:
    if (v_17378 == nil) goto v_17297;
    goto v_17329;
v_17325:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_17326;
v_17327:
    v_17378 = stack[-1];
    v_17378 = qcdr(v_17378);
    v_17378 = qcar(v_17378);
    v_17378 = qcdr(v_17378);
    v_17378 = Labsval(nil, v_17378);
    goto v_17328;
v_17329:
    goto v_17325;
v_17326:
    goto v_17327;
v_17328:
    {
        LispObject v_17384 = stack[0];
        return cons(v_17384, v_17378);
    }
v_17297:
    goto v_17342;
v_17338:
    v_17378 = stack[-1];
    v_17379 = qcar(v_17378);
    goto v_17339;
v_17340:
    v_17378 = elt(env, 2); // minus
    goto v_17341;
v_17342:
    goto v_17338;
v_17339:
    goto v_17340;
v_17341:
    if (v_17379 == v_17378) goto v_17336;
    else goto v_17337;
v_17336:
    v_17378 = stack[-1];
    goto v_17197;
v_17337:
    goto v_17354;
v_17350:
    v_17378 = stack[-1];
    v_17379 = qcdr(v_17378);
    goto v_17351;
v_17352:
    v_17378 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_17353;
v_17354:
    goto v_17350;
v_17351:
    goto v_17352;
v_17353:
    v_17378 = (LispObject)lessp2(v_17379, v_17378);
    v_17378 = v_17378 ? lisp_true : nil;
    env = stack[-3];
    if (v_17378 == nil) goto v_17348;
    goto v_17363;
v_17359:
    stack[-2] = elt(env, 2); // minus
    goto v_17360;
v_17361:
    goto v_17370;
v_17366:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_17367;
v_17368:
    v_17378 = stack[-1];
    v_17378 = qcdr(v_17378);
    v_17378 = Labsval(nil, v_17378);
    env = stack[-3];
    goto v_17369;
v_17370:
    goto v_17366;
v_17367:
    goto v_17368;
v_17369:
    v_17378 = cons(stack[0], v_17378);
    goto v_17362;
v_17363:
    goto v_17359;
v_17360:
    goto v_17361;
v_17362:
    {
        LispObject v_17385 = stack[-2];
        return list2(v_17385, v_17378);
    }
v_17348:
    v_17378 = stack[-1];
    goto v_17197;
    v_17378 = nil;
v_17197:
    return onevalue(v_17378);
}



// Code for insoccs

static LispObject CC_insoccs(LispObject env,
                         LispObject v_17194, LispObject v_17195)
{
    env = qenv(env);
    LispObject v_17266, v_17267;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_17195,v_17194);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_17194,v_17195);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_17195;
    stack[-1] = v_17194;
// end of prologue
    v_17266 = stack[-1];
    if (symbolp(v_17266)) goto v_17201;
    v_17266 = stack[-1];
    fn = elt(env, 1); // subscriptedvarp
    v_17266 = (*qfn1(fn))(fn, v_17266);
    env = stack[-2];
    if (v_17266 == nil) goto v_17206;
    else goto v_17201;
v_17206:
    v_17266 = stack[-1];
    v_17266 = Lconsp(nil, v_17266);
    env = stack[-2];
    if (v_17266 == nil) goto v_17209;
    v_17266 = stack[-1];
    v_17266 = qcar(v_17266);
    fn = elt(env, 1); // subscriptedvarp
    v_17266 = (*qfn1(fn))(fn, v_17266);
    env = stack[-2];
    if (v_17266 == nil) goto v_17209;
    goto v_17201;
v_17209:
    goto v_17202;
v_17201:
    goto v_17222;
v_17218:
    v_17267 = stack[0];
    goto v_17219;
v_17220:
    v_17266 = stack[-1];
    goto v_17221;
v_17222:
    goto v_17218;
v_17219:
    goto v_17220;
v_17221:
    fn = elt(env, 2); // insertocc
    v_17266 = (*qfn2(fn))(fn, v_17267, v_17266);
    env = stack[-2];
    stack[0] = v_17266;
    goto v_17200;
v_17202:
v_17200:
    v_17266 = stack[-1];
    if (symbolp(v_17266)) goto v_17232;
    v_17266 = stack[-1];
    fn = elt(env, 3); // constp
    v_17266 = (*qfn1(fn))(fn, v_17266);
    env = stack[-2];
    v_17266 = (v_17266 == nil ? lisp_true : nil);
    goto v_17230;
v_17232:
    v_17266 = nil;
    goto v_17230;
    v_17266 = nil;
v_17230:
    if (v_17266 == nil) goto v_17228;
    v_17266 = stack[-1];
    v_17266 = qcdr(v_17266);
    stack[-1] = v_17266;
v_17243:
    v_17266 = stack[-1];
    if (v_17266 == nil) goto v_17248;
    else goto v_17249;
v_17248:
    goto v_17242;
v_17249:
    v_17266 = stack[-1];
    v_17266 = qcar(v_17266);
    goto v_17260;
v_17256:
    v_17267 = v_17266;
    goto v_17257;
v_17258:
    v_17266 = stack[0];
    goto v_17259;
v_17260:
    goto v_17256;
v_17257:
    goto v_17258;
v_17259:
    v_17266 = CC_insoccs(elt(env, 0), v_17267, v_17266);
    env = stack[-2];
    stack[0] = v_17266;
    v_17266 = stack[-1];
    v_17266 = qcdr(v_17266);
    stack[-1] = v_17266;
    goto v_17243;
v_17242:
    goto v_17226;
v_17228:
v_17226:
    v_17266 = stack[0];
    return onevalue(v_17266);
}



// Code for overall_factor

static LispObject CC_overall_factor(LispObject env,
                         LispObject v_17194, LispObject v_17195)
{
    env = qenv(env);
    LispObject v_17230, v_17231;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_17195,v_17194);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_17194,v_17195);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_17195;
    stack[-1] = v_17194;
// end of prologue
v_17193:
    v_17230 = stack[0];
    if (v_17230 == nil) goto v_17199;
    else goto v_17200;
v_17199:
    v_17230 = lisp_true;
    goto v_17198;
v_17200:
    goto v_17213;
v_17209:
    stack[-2] = stack[-1];
    goto v_17210;
v_17211:
    v_17230 = stack[0];
    fn = elt(env, 1); // xval
    v_17230 = (*qfn1(fn))(fn, v_17230);
    env = stack[-3];
    goto v_17212;
v_17213:
    goto v_17209;
v_17210:
    goto v_17211;
v_17212:
    v_17230 = Lmemq(nil, stack[-2], v_17230);
    if (v_17230 == nil) goto v_17207;
    else goto v_17208;
v_17207:
    v_17230 = nil;
    goto v_17206;
v_17208:
    goto v_17226;
v_17222:
    v_17231 = stack[-1];
    goto v_17223;
v_17224:
    v_17230 = stack[0];
    v_17230 = qcdr(v_17230);
    goto v_17225;
v_17226:
    goto v_17222;
v_17223:
    goto v_17224;
v_17225:
    stack[-1] = v_17231;
    stack[0] = v_17230;
    goto v_17193;
    v_17230 = nil;
v_17206:
    goto v_17198;
    v_17230 = nil;
v_17198:
    return onevalue(v_17230);
}



// Code for testchar1

static LispObject CC_testchar1(LispObject env,
                         LispObject v_17194)
{
    env = qenv(env);
    LispObject v_17242, v_17243;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_17194);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_17194);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_17194;
// end of prologue
    v_17242 = stack[0];
    v_17242 = integerp(v_17242);
    if (v_17242 == nil) goto v_17199;
    v_17242 = stack[0];
    goto v_17197;
v_17199:
    v_17242 = stack[0];
    v_17242 = Lexplodec(nil, v_17242);
    env = stack[-1];
    v_17242 = qcdr(v_17242);
    if (v_17242 == nil) goto v_17203;
    else goto v_17204;
v_17203:
    v_17242 = stack[0];
    goto v_17197;
v_17204:
    goto v_17215;
v_17211:
    v_17243 = stack[0];
    goto v_17212;
v_17213:
    v_17242 = qvalue(elt(env, 1)); // nochar!*
    goto v_17214;
v_17215:
    goto v_17211;
v_17212:
    goto v_17213;
v_17214:
    v_17242 = Lmember(nil, v_17243, v_17242);
    if (v_17242 == nil) goto v_17210;
    v_17242 = stack[0];
    goto v_17197;
v_17210:
    goto v_17226;
v_17222:
    v_17243 = stack[0];
    goto v_17223;
v_17224:
    v_17242 = qvalue(elt(env, 2)); // nochar1!*
    goto v_17225;
v_17226:
    goto v_17222;
v_17223:
    goto v_17224;
v_17225:
    v_17242 = Lmember(nil, v_17243, v_17242);
    if (v_17242 == nil) goto v_17221;
    v_17242 = stack[0];
    goto v_17197;
v_17221:
    goto v_17238;
v_17234:
    v_17243 = stack[0];
    goto v_17235;
v_17236:
    v_17242 = qvalue(elt(env, 2)); // nochar1!*
    goto v_17237;
v_17238:
    goto v_17234;
v_17235:
    goto v_17236;
v_17237:
    v_17242 = cons(v_17243, v_17242);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_17242; // nochar1!*
    v_17242 = stack[0];
    goto v_17197;
    v_17242 = nil;
v_17197:
    return onevalue(v_17242);
}



// Code for letscalar

static LispObject CC_letscalar(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17599, v_17600, v_17601, v_17602, v_17603, v_17604;
    LispObject fn;
    LispObject v_17199, v_17198, v_17197, v_17196, v_17195, v_17194;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "letscalar");
    va_start(aa, nargs);
    v_17194 = va_arg(aa, LispObject);
    v_17195 = va_arg(aa, LispObject);
    v_17196 = va_arg(aa, LispObject);
    v_17197 = va_arg(aa, LispObject);
    v_17198 = va_arg(aa, LispObject);
    v_17199 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_17199,v_17198,v_17197,v_17196,v_17195,v_17194);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_17194,v_17195,v_17196,v_17197,v_17198,v_17199);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-2] = v_17199;
    stack[-3] = v_17198;
    stack[-4] = v_17197;
    stack[-5] = v_17196;
    stack[-6] = v_17195;
    stack[-7] = v_17194;
// end of prologue
    v_17599 = stack[-4];
    if (!consp(v_17599)) goto v_17206;
    v_17599 = stack[-4];
    v_17599 = qcar(v_17599);
    if (symbolp(v_17599)) goto v_17211;
    goto v_17219;
v_17215:
    v_17600 = stack[-7];
    goto v_17216;
v_17217:
    v_17599 = elt(env, 1); // hold
    goto v_17218;
v_17219:
    goto v_17215;
v_17216:
    goto v_17217;
v_17218:
    {
        fn = elt(env, 23); // errpri2
        return (*qfn2(fn))(fn, v_17600, v_17599);
    }
v_17211:
    goto v_17228;
v_17224:
    v_17599 = stack[-4];
    v_17600 = qcar(v_17599);
    goto v_17225;
v_17226:
    v_17599 = elt(env, 2); // df
    goto v_17227;
v_17228:
    goto v_17224;
v_17225:
    goto v_17226;
v_17227:
    if (v_17600 == v_17599) goto v_17222;
    else goto v_17223;
v_17222:
    goto v_17247;
v_17237:
    v_17603 = stack[-7];
    goto v_17238;
v_17239:
    v_17602 = stack[-6];
    goto v_17240;
v_17241:
    v_17601 = stack[-5];
    goto v_17242;
v_17243:
    v_17600 = stack[-4];
    goto v_17244;
v_17245:
    v_17599 = stack[-3];
    goto v_17246;
v_17247:
    goto v_17237;
v_17238:
    goto v_17239;
v_17240:
    goto v_17241;
v_17242:
    goto v_17243;
v_17244:
    goto v_17245;
v_17246:
    fn = elt(env, 24); // letdf
    v_17599 = (*qfnn(fn))(fn, 5, v_17603, v_17602, v_17601, v_17600, v_17599);
    env = stack[-9];
    if (v_17599 == nil) goto v_17234;
    else goto v_17235;
v_17234:
    goto v_17233;
v_17235:
    v_17599 = nil;
    goto v_17202;
v_17233:
    goto v_17209;
v_17223:
    v_17599 = stack[-4];
    v_17599 = qcar(v_17599);
    fn = elt(env, 25); // getrtype
    v_17599 = (*qfn1(fn))(fn, v_17599);
    env = stack[-9];
    if (v_17599 == nil) goto v_17258;
    goto v_17271;
v_17263:
    v_17599 = stack[-4];
    fn = elt(env, 26); // reval
    v_17602 = (*qfn1(fn))(fn, v_17599);
    env = stack[-9];
    goto v_17264;
v_17265:
    v_17601 = stack[-6];
    goto v_17266;
v_17267:
    v_17600 = stack[-5];
    goto v_17268;
v_17269:
    v_17599 = stack[-3];
    goto v_17270;
v_17271:
    goto v_17263;
v_17264:
    goto v_17265;
v_17266:
    goto v_17267;
v_17268:
    goto v_17269;
v_17270:
    {
        fn = elt(env, 27); // let2
        return (*qfnn(fn))(fn, 4, v_17602, v_17601, v_17600, v_17599);
    }
v_17258:
    v_17599 = stack[-4];
    v_17599 = qcar(v_17599);
    if (!symbolp(v_17599)) v_17599 = nil;
    else { v_17599 = qfastgets(v_17599);
           if (v_17599 != nil) { v_17599 = elt(v_17599, 22); // simpfn
#ifdef RECORD_GET
             if (v_17599 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v_17599 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v_17599 == SPID_NOPROP) v_17599 = nil; }}
#endif
    if (v_17599 == nil) goto v_17277;
    else goto v_17278;
v_17277:
    goto v_17287;
v_17283:
    v_17599 = stack[-4];
    v_17600 = qcar(v_17599);
    goto v_17284;
v_17285:
    v_17599 = elt(env, 3); // "operator"
    goto v_17286;
v_17287:
    goto v_17283;
v_17284:
    goto v_17285;
v_17286:
    fn = elt(env, 28); // redmsg
    v_17599 = (*qfn2(fn))(fn, v_17600, v_17599);
    env = stack[-9];
    v_17599 = stack[-4];
    v_17599 = qcar(v_17599);
    fn = elt(env, 29); // mkop
    v_17599 = (*qfn1(fn))(fn, v_17599);
    env = stack[-9];
    goto v_17305;
v_17295:
    v_17603 = stack[-7];
    goto v_17296;
v_17297:
    v_17602 = stack[-6];
    goto v_17298;
v_17299:
    v_17601 = stack[-5];
    goto v_17300;
v_17301:
    v_17600 = stack[-3];
    goto v_17302;
v_17303:
    v_17599 = stack[-2];
    goto v_17304;
v_17305:
    goto v_17295;
v_17296:
    goto v_17297;
v_17298:
    goto v_17299;
v_17300:
    goto v_17301;
v_17302:
    goto v_17303;
v_17304:
    {
        fn = elt(env, 30); // let3
        return (*qfnn(fn))(fn, 5, v_17603, v_17602, v_17601, v_17600, v_17599);
    }
v_17278:
    goto v_17209;
v_17209:
    goto v_17204;
v_17206:
    v_17599 = stack[-3];
    if (v_17599 == nil) goto v_17318;
    else goto v_17319;
v_17318:
    v_17599 = stack[-5];
    v_17599 = (v_17599 == nil ? lisp_true : nil);
    goto v_17317;
v_17319:
    v_17599 = nil;
    goto v_17317;
    v_17599 = nil;
v_17317:
    if (v_17599 == nil) goto v_17315;
    goto v_17331;
v_17327:
    v_17600 = stack[-4];
    goto v_17328;
v_17329:
    v_17599 = elt(env, 4); // avalue
    goto v_17330;
v_17331:
    goto v_17327;
v_17328:
    goto v_17329;
v_17330:
    v_17599 = Lremprop(nil, v_17600, v_17599);
    env = stack[-9];
    goto v_17339;
v_17335:
    v_17600 = stack[-4];
    goto v_17336;
v_17337:
    v_17599 = elt(env, 5); // rtype
    goto v_17338;
v_17339:
    goto v_17335;
v_17336:
    goto v_17337;
v_17338:
    v_17599 = Lremprop(nil, v_17600, v_17599);
    env = stack[-9];
    goto v_17347;
v_17343:
    v_17599 = stack[-4];
    v_17600 = ncons(v_17599);
    env = stack[-9];
    goto v_17344;
v_17345:
    v_17599 = elt(env, 6); // antisymmetric
    goto v_17346;
v_17347:
    goto v_17343;
v_17344:
    goto v_17345;
v_17346:
    v_17599 = Lremflag(nil, v_17600, v_17599);
    env = stack[-9];
    goto v_17356;
v_17352:
    v_17600 = stack[-4];
    goto v_17353;
v_17354:
    v_17599 = elt(env, 7); // infix
    goto v_17355;
v_17356:
    goto v_17352;
v_17353:
    goto v_17354;
v_17355:
    v_17599 = Lremprop(nil, v_17600, v_17599);
    env = stack[-9];
    goto v_17364;
v_17360:
    v_17600 = stack[-4];
    goto v_17361;
v_17362:
    v_17599 = elt(env, 8); // kvalue
    goto v_17363;
v_17364:
    goto v_17360;
v_17361:
    goto v_17362;
v_17363:
    v_17599 = Lremprop(nil, v_17600, v_17599);
    env = stack[-9];
    goto v_17372;
v_17368:
    v_17599 = stack[-4];
    v_17600 = ncons(v_17599);
    env = stack[-9];
    goto v_17369;
v_17370:
    v_17599 = elt(env, 9); // linear
    goto v_17371;
v_17372:
    goto v_17368;
v_17369:
    goto v_17370;
v_17371:
    v_17599 = Lremflag(nil, v_17600, v_17599);
    env = stack[-9];
    goto v_17381;
v_17377:
    v_17599 = stack[-4];
    v_17600 = ncons(v_17599);
    env = stack[-9];
    goto v_17378;
v_17379:
    v_17599 = elt(env, 10); // noncom
    goto v_17380;
v_17381:
    goto v_17377;
v_17378:
    goto v_17379;
v_17380:
    v_17599 = Lremflag(nil, v_17600, v_17599);
    env = stack[-9];
    goto v_17390;
v_17386:
    v_17600 = stack[-4];
    goto v_17387;
v_17388:
    v_17599 = elt(env, 11); // op
    goto v_17389;
v_17390:
    goto v_17386;
v_17387:
    goto v_17388;
v_17389:
    v_17599 = Lremprop(nil, v_17600, v_17599);
    env = stack[-9];
    goto v_17398;
v_17394:
    v_17600 = stack[-4];
    goto v_17395;
v_17396:
    v_17599 = elt(env, 12); // opmtch
    goto v_17397;
v_17398:
    goto v_17394;
v_17395:
    goto v_17396;
v_17397:
    v_17599 = Lremprop(nil, v_17600, v_17599);
    env = stack[-9];
    goto v_17406;
v_17402:
    v_17600 = stack[-4];
    goto v_17403;
v_17404:
    v_17599 = elt(env, 13); // simpfn
    goto v_17405;
v_17406:
    goto v_17402;
v_17403:
    goto v_17404;
v_17405:
    v_17599 = Lremprop(nil, v_17600, v_17599);
    env = stack[-9];
    goto v_17414;
v_17410:
    v_17599 = stack[-4];
    v_17600 = ncons(v_17599);
    env = stack[-9];
    goto v_17411;
v_17412:
    v_17599 = elt(env, 14); // symmetric
    goto v_17413;
v_17414:
    goto v_17410;
v_17411:
    goto v_17412;
v_17413:
    v_17599 = Lremflag(nil, v_17600, v_17599);
    env = stack[-9];
    goto v_17423;
v_17419:
    v_17600 = stack[-4];
    goto v_17420;
v_17421:
    v_17599 = qvalue(elt(env, 15)); // wtl!*
    goto v_17422;
v_17423:
    goto v_17419;
v_17420:
    goto v_17421;
v_17422:
    fn = elt(env, 31); // delasc
    v_17599 = (*qfn2(fn))(fn, v_17600, v_17599);
    env = stack[-9];
    qvalue(elt(env, 15)) = v_17599; // wtl!*
    v_17599 = stack[-4];
    if (!symbolp(v_17599)) v_17599 = nil;
    else { v_17599 = qfastgets(v_17599);
           if (v_17599 != nil) { v_17599 = elt(v_17599, 59); // opfn
#ifdef RECORD_GET
             if (v_17599 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v_17599 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v_17599 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v_17599 == SPID_NOPROP) v_17599 = nil; else v_17599 = lisp_true; }}
#endif
    if (v_17599 == nil) goto v_17429;
    goto v_17437;
v_17433:
    v_17599 = stack[-4];
    v_17600 = ncons(v_17599);
    env = stack[-9];
    goto v_17434;
v_17435:
    v_17599 = elt(env, 16); // opfn
    goto v_17436;
v_17437:
    goto v_17433;
v_17434:
    goto v_17435;
v_17436:
    v_17599 = Lremflag(nil, v_17600, v_17599);
    env = stack[-9];
    v_17599 = stack[-4];
    v_17599 = Lremd(nil, v_17599);
    env = stack[-9];
    goto v_17427;
v_17429:
v_17427:
    fn = elt(env, 32); // rmsubs
    v_17599 = (*qfnn(fn))(fn, 0);
    v_17599 = nil;
    goto v_17202;
v_17315:
v_17204:
    goto v_17458;
v_17454:
    v_17600 = stack[-4];
    goto v_17455;
v_17456:
    v_17599 = elt(env, 17); // expt
    goto v_17457;
v_17458:
    goto v_17454;
v_17455:
    goto v_17456;
v_17457:
    if (!consp(v_17600)) goto v_17452;
    v_17600 = qcar(v_17600);
    if (v_17600 == v_17599) goto v_17451;
    else goto v_17452;
v_17451:
    goto v_17465;
v_17461:
    v_17599 = stack[-4];
    v_17599 = qcdr(v_17599);
    v_17599 = qcdr(v_17599);
    v_17600 = qcar(v_17599);
    goto v_17462;
v_17463:
    v_17599 = qvalue(elt(env, 18)); // frlis!*
    goto v_17464;
v_17465:
    goto v_17461;
v_17462:
    goto v_17463;
v_17464:
    v_17599 = Lmemq(nil, v_17600, v_17599);
    goto v_17450;
v_17452:
    v_17599 = nil;
    goto v_17450;
    v_17599 = nil;
v_17450:
    if (v_17599 == nil) goto v_17448;
    goto v_17488;
v_17476:
    stack[-8] = stack[-7];
    goto v_17477;
v_17478:
    stack[-1] = stack[-6];
    goto v_17479;
v_17480:
    stack[0] = stack[-5];
    goto v_17481;
v_17482:
    goto v_17497;
v_17493:
    goto v_17504;
v_17500:
    goto v_17510;
v_17506:
    v_17600 = stack[-4];
    goto v_17507;
v_17508:
    v_17599 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17509;
v_17510:
    goto v_17506;
v_17507:
    goto v_17508;
v_17509:
    fn = elt(env, 33); // to
    v_17600 = (*qfn2(fn))(fn, v_17600, v_17599);
    env = stack[-9];
    goto v_17501;
v_17502:
    v_17599 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17503;
v_17504:
    goto v_17500;
v_17501:
    goto v_17502;
v_17503:
    v_17599 = cons(v_17600, v_17599);
    env = stack[-9];
    v_17600 = ncons(v_17599);
    env = stack[-9];
    goto v_17494;
v_17495:
    v_17599 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_17496;
v_17497:
    goto v_17493;
v_17494:
    goto v_17495;
v_17496:
    v_17601 = cons(v_17600, v_17599);
    env = stack[-9];
    goto v_17483;
v_17484:
    v_17600 = stack[-3];
    goto v_17485;
v_17486:
    v_17599 = stack[-2];
    goto v_17487;
v_17488:
    goto v_17476;
v_17477:
    goto v_17478;
v_17479:
    goto v_17480;
v_17481:
    goto v_17482;
v_17483:
    goto v_17484;
v_17485:
    goto v_17486;
v_17487:
    fn = elt(env, 34); // letexprn
    v_17599 = (*qfnn(fn))(fn, 6, stack[-8], stack[-1], stack[0], v_17601, v_17600, v_17599);
    env = stack[-9];
    goto v_17446;
v_17448:
    goto v_17524;
v_17520:
    v_17600 = stack[-4];
    goto v_17521;
v_17522:
    v_17599 = elt(env, 19); // sqrt
    goto v_17523;
v_17524:
    goto v_17520;
v_17521:
    goto v_17522;
v_17523:
    if (!consp(v_17600)) goto v_17518;
    v_17600 = qcar(v_17600);
    if (v_17600 == v_17599) goto v_17517;
    else goto v_17518;
v_17517:
    v_17599 = lisp_true;
    qvalue(elt(env, 20)) = v_17599; // !*sqrtrulep
    goto v_17537;
v_17529:
    goto v_17545;
v_17539:
    v_17601 = elt(env, 17); // expt
    goto v_17540;
v_17541:
    v_17599 = stack[-4];
    v_17599 = qcdr(v_17599);
    v_17600 = qcar(v_17599);
    goto v_17542;
v_17543:
    v_17599 = elt(env, 21); // (quotient 1 2)
    goto v_17544;
v_17545:
    goto v_17539;
v_17540:
    goto v_17541;
v_17542:
    goto v_17543;
v_17544:
    v_17602 = list3(v_17601, v_17600, v_17599);
    env = stack[-9];
    goto v_17530;
v_17531:
    v_17601 = stack[-6];
    goto v_17532;
v_17533:
    v_17600 = stack[-5];
    goto v_17534;
v_17535:
    v_17599 = stack[-3];
    goto v_17536;
v_17537:
    goto v_17529;
v_17530:
    goto v_17531;
v_17532:
    goto v_17533;
v_17534:
    goto v_17535;
v_17536:
    fn = elt(env, 27); // let2
    v_17599 = (*qfnn(fn))(fn, 4, v_17602, v_17601, v_17600, v_17599);
    env = stack[-9];
    goto v_17446;
v_17518:
v_17446:
    v_17599 = lisp_true;
// Binding !*precise
// FLUIDBIND: reloadenv=9 litvec-offset=22 saveloc=0
{   bind_fluid_stack bind_fluid_var(-9, 22, 0);
    qvalue(elt(env, 22)) = v_17599; // !*precise
    v_17599 = stack[-4];
    fn = elt(env, 35); // simp0
    v_17599 = (*qfn1(fn))(fn, v_17599);
    env = stack[-9];
    stack[-4] = v_17599;
    ;}  // end of a binding scope
    v_17599 = stack[-4];
    v_17599 = qcar(v_17599);
    if (!consp(v_17599)) goto v_17564;
    else goto v_17565;
v_17564:
    v_17599 = lisp_true;
    goto v_17563;
v_17565:
    v_17599 = stack[-4];
    v_17599 = qcar(v_17599);
    v_17599 = qcar(v_17599);
    v_17599 = (consp(v_17599) ? nil : lisp_true);
    goto v_17563;
    v_17599 = nil;
v_17563:
    if (v_17599 == nil) goto v_17560;
    else goto v_17561;
v_17560:
    goto v_17588;
v_17576:
    v_17604 = stack[-7];
    goto v_17577;
v_17578:
    v_17603 = stack[-6];
    goto v_17579;
v_17580:
    v_17602 = stack[-5];
    goto v_17581;
v_17582:
    v_17601 = stack[-4];
    goto v_17583;
v_17584:
    v_17600 = stack[-3];
    goto v_17585;
v_17586:
    v_17599 = stack[-2];
    goto v_17587;
v_17588:
    goto v_17576;
v_17577:
    goto v_17578;
v_17579:
    goto v_17580;
v_17581:
    goto v_17582;
v_17583:
    goto v_17584;
v_17585:
    goto v_17586;
v_17587:
    {
        fn = elt(env, 34); // letexprn
        return (*qfnn(fn))(fn, 6, v_17604, v_17603, v_17602, v_17601, v_17600, v_17599);
    }
v_17561:
    v_17599 = stack[-7];
    {
        fn = elt(env, 36); // errpri1
        return (*qfn1(fn))(fn, v_17599);
    }
    v_17599 = nil;
v_17202:
    return onevalue(v_17599);
}



setup_type const u32_setup[] =
{
    {"lex_basic_token",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex_basic_token},
    {"formbool",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formbool},
    {"even_action_sf",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_even_action_sf},
    {"matrix_rows",             CC_matrix_rows, TOO_MANY_1,    WRONG_NO_1},
    {"sc_getrow",               TOO_FEW_2,      CC_sc_getrow,  WRONG_NO_2},
    {"gparg1p",                 CC_gparg1p,     TOO_MANY_1,    WRONG_NO_1},
    {"indordn",                 CC_indordn,     TOO_MANY_1,    WRONG_NO_1},
    {"one-entryp",              TOO_FEW_2,      CC_oneKentryp, WRONG_NO_2},
    {"modp",                    TOO_FEW_2,      CC_modp,       WRONG_NO_2},
    {"horner-rule-for-one-var", WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_hornerKruleKforKoneKvar},
    {"lalr_process_reductions", WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lalr_process_reductions},
    {"profile_a_package",       CC_profile_a_package,TOO_MANY_1,WRONG_NO_1},
    {"ofsf_siatsubf",           TOO_FEW_2,      CC_ofsf_siatsubf,WRONG_NO_2},
    {"monomgetfirstmultivar",   CC_monomgetfirstmultivar,TOO_MANY_1,WRONG_NO_1},
    {"ofsf_simplat1",           TOO_FEW_2,      CC_ofsf_simplat1,WRONG_NO_2},
    {"containerml",             TOO_FEW_2,      CC_containerml,WRONG_NO_2},
    {"add_minus",               CC_add_minus,   TOO_MANY_1,    WRONG_NO_1},
    {"insoccs",                 TOO_FEW_2,      CC_insoccs,    WRONG_NO_2},
    {"overall_factor",          TOO_FEW_2,      CC_overall_factor,WRONG_NO_2},
    {"testchar1",               CC_testchar1,   TOO_MANY_1,    WRONG_NO_1},
    {"letscalar",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_letscalar},
    {NULL, (one_args *)"u32", (two_args *)"163316 5598466 2718246", 0}
};

// end of generated code
