
// $destdir/u39.c        Machine generated C code

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



// Code for prepsq!*1

static LispObject CC_prepsqH1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22638, v_22639, v_22640;
    LispObject fn;
    LispObject v_21929, v_21928, v_21927;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "prepsq*1");
    va_start(aa, nargs);
    v_21927 = va_arg(aa, LispObject);
    v_21928 = va_arg(aa, LispObject);
    v_21929 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21929,v_21928,v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21927,v_21928,v_21929);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_21929;
    stack[-5] = v_21928;
    stack[-6] = v_21927;
// end of prologue
    v_22638 = stack[-6];
    if (!consp(v_22638)) goto v_21946;
    else goto v_21947;
v_21946:
    v_22638 = lisp_true;
    goto v_21945;
v_21947:
    v_22638 = stack[-6];
    v_22638 = qcar(v_22638);
    v_22638 = (consp(v_22638) ? nil : lisp_true);
    goto v_21945;
    v_22638 = nil;
v_21945:
    if (v_22638 == nil) goto v_21942;
    else goto v_21943;
v_21942:
    goto v_21962;
v_21958:
    v_22638 = stack[-6];
    v_22638 = qcar(v_22638);
    v_22638 = qcar(v_22638);
    v_22639 = qcar(v_22638);
    goto v_21959;
v_21960:
    v_22638 = qvalue(elt(env, 1)); // factors!*
    goto v_21961;
v_21962:
    goto v_21958;
v_21959:
    goto v_21960;
v_21961:
    v_22638 = Lmember(nil, v_22639, v_22638);
    if (v_22638 == nil) goto v_21957;
    else goto v_21956;
v_21957:
    v_22638 = stack[-6];
    v_22638 = qcar(v_22638);
    v_22638 = qcar(v_22638);
    v_22638 = qcar(v_22638);
    if (!consp(v_22638)) goto v_21972;
    goto v_21981;
v_21977:
    v_22638 = stack[-6];
    v_22638 = qcar(v_22638);
    v_22638 = qcar(v_22638);
    v_22638 = qcar(v_22638);
    v_22639 = qcar(v_22638);
    goto v_21978;
v_21979:
    v_22638 = qvalue(elt(env, 1)); // factors!*
    goto v_21980;
v_21981:
    goto v_21977;
v_21978:
    goto v_21979;
v_21980:
    v_22638 = Lmember(nil, v_22639, v_22638);
    goto v_21970;
v_21972:
    v_22638 = nil;
    goto v_21970;
    v_22638 = nil;
v_21970:
v_21956:
    goto v_21941;
v_21943:
    v_22638 = nil;
    goto v_21941;
    v_22638 = nil;
v_21941:
    if (v_22638 == nil) goto v_21939;
    goto v_22000;
v_21996:
    goto v_22009;
v_22005:
    v_22639 = stack[-5];
    goto v_22006;
v_22007:
    v_22638 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22008;
v_22009:
    goto v_22005;
v_22006:
    goto v_22007;
v_22008:
    if (v_22639 == v_22638) goto v_22003;
    else goto v_22004;
v_22003:
    goto v_22017;
v_22013:
    goto v_22023;
v_22019:
    v_22638 = stack[-6];
    v_22638 = qcar(v_22638);
    v_22639 = qcdr(v_22638);
    goto v_22020;
v_22021:
    v_22638 = stack[-5];
    goto v_22022;
v_22023:
    goto v_22019;
v_22020:
    goto v_22021;
v_22022:
    stack[0] = cons(v_22639, v_22638);
    env = stack[-8];
    goto v_22014;
v_22015:
    goto v_22033;
v_22029:
    v_22638 = stack[-6];
    v_22638 = qcar(v_22638);
    v_22639 = qcar(v_22638);
    goto v_22030;
v_22031:
    v_22638 = stack[-4];
    goto v_22032;
v_22033:
    goto v_22029;
v_22030:
    goto v_22031;
v_22032:
    v_22638 = cons(v_22639, v_22638);
    env = stack[-8];
    goto v_22016;
v_22017:
    goto v_22013;
v_22014:
    goto v_22015;
v_22016:
    fn = elt(env, 10); // prepsq!*0
    v_22638 = (*qfn2(fn))(fn, stack[0], v_22638);
    env = stack[-8];
    stack[0] = v_22638;
    goto v_22002;
v_22004:
    v_22638 = stack[-6];
    v_22638 = qcar(v_22638);
    v_22638 = qcar(v_22638);
    v_22638 = qcdr(v_22638);
    stack[-2] = v_22638;
    v_22638 = stack[-5];
    stack[-1] = v_22638;
    goto v_22056;
v_22052:
    goto v_22062;
v_22058:
    v_22638 = stack[-6];
    v_22638 = qcar(v_22638);
    v_22638 = qcar(v_22638);
    v_22639 = qcar(v_22638);
    goto v_22059;
v_22060:
    v_22638 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22061;
v_22062:
    goto v_22058;
v_22059:
    goto v_22060;
v_22061:
    fn = elt(env, 11); // to
    v_22639 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    goto v_22053;
v_22054:
    v_22638 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22055;
v_22056:
    goto v_22052;
v_22053:
    goto v_22054;
v_22055:
    v_22638 = cons(v_22639, v_22638);
    env = stack[-8];
    v_22638 = ncons(v_22638);
    env = stack[-8];
    stack[0] = v_22638;
v_22071:
    goto v_22081;
v_22077:
    v_22639 = stack[-1];
    goto v_22078;
v_22079:
    v_22638 = stack[0];
    goto v_22080;
v_22081:
    goto v_22077;
v_22078:
    goto v_22079;
v_22080:
    fn = elt(env, 12); // quotfm
    v_22638 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    stack[-7] = v_22638;
    if (v_22638 == nil) goto v_22074;
    else goto v_22075;
v_22074:
    goto v_22070;
v_22075:
    v_22638 = stack[-7];
    stack[-1] = v_22638;
    v_22638 = stack[-2];
    v_22638 = sub1(v_22638);
    env = stack[-8];
    stack[-2] = v_22638;
    goto v_22071;
v_22070:
    goto v_22093;
v_22089:
    goto v_22099;
v_22095:
    v_22638 = stack[-6];
    v_22638 = qcar(v_22638);
    v_22639 = qcdr(v_22638);
    goto v_22096;
v_22097:
    v_22638 = stack[-1];
    goto v_22098;
v_22099:
    goto v_22095;
v_22096:
    goto v_22097;
v_22098:
    stack[0] = cons(v_22639, v_22638);
    env = stack[-8];
    goto v_22090;
v_22091:
    goto v_22113;
v_22109:
    v_22639 = stack[-2];
    goto v_22110;
v_22111:
    v_22638 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22112;
v_22113:
    goto v_22109;
v_22110:
    goto v_22111;
v_22112:
    v_22638 = (LispObject)greaterp2(v_22639, v_22638);
    v_22638 = v_22638 ? lisp_true : nil;
    env = stack[-8];
    if (v_22638 == nil) goto v_22107;
    goto v_22121;
v_22117:
    goto v_22127;
v_22123:
    v_22638 = stack[-6];
    v_22638 = qcar(v_22638);
    v_22638 = qcar(v_22638);
    v_22639 = qcar(v_22638);
    goto v_22124;
v_22125:
    v_22638 = stack[-2];
    goto v_22126;
v_22127:
    goto v_22123;
v_22124:
    goto v_22125;
v_22126:
    fn = elt(env, 11); // to
    v_22639 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    goto v_22118;
v_22119:
    v_22638 = stack[-4];
    goto v_22120;
v_22121:
    goto v_22117;
v_22118:
    goto v_22119;
v_22120:
    v_22638 = cons(v_22639, v_22638);
    env = stack[-8];
    goto v_22105;
v_22107:
    goto v_22141;
v_22137:
    v_22639 = stack[-2];
    goto v_22138;
v_22139:
    v_22638 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22140;
v_22141:
    goto v_22137;
v_22138:
    goto v_22139;
v_22140:
    v_22638 = (LispObject)lessp2(v_22639, v_22638);
    v_22638 = v_22638 ? lisp_true : nil;
    env = stack[-8];
    if (v_22638 == nil) goto v_22135;
    goto v_22149;
v_22145:
    goto v_22155;
v_22151:
    goto v_22163;
v_22157:
    v_22640 = elt(env, 2); // expt
    goto v_22158;
v_22159:
    v_22638 = stack[-6];
    v_22638 = qcar(v_22638);
    v_22638 = qcar(v_22638);
    v_22639 = qcar(v_22638);
    goto v_22160;
v_22161:
    v_22638 = stack[-2];
    goto v_22162;
v_22163:
    goto v_22157;
v_22158:
    goto v_22159;
v_22160:
    goto v_22161;
v_22162:
    v_22639 = list3(v_22640, v_22639, v_22638);
    env = stack[-8];
    goto v_22152;
v_22153:
    v_22638 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22154;
v_22155:
    goto v_22151;
v_22152:
    goto v_22153;
v_22154:
    fn = elt(env, 13); // mksp
    v_22639 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    goto v_22146;
v_22147:
    v_22638 = stack[-4];
    goto v_22148;
v_22149:
    goto v_22145;
v_22146:
    goto v_22147;
v_22148:
    v_22638 = cons(v_22639, v_22638);
    env = stack[-8];
    goto v_22105;
v_22135:
    v_22638 = stack[-4];
    goto v_22105;
    v_22638 = nil;
v_22105:
    goto v_22092;
v_22093:
    goto v_22089;
v_22090:
    goto v_22091;
v_22092:
    fn = elt(env, 10); // prepsq!*0
    v_22638 = (*qfn2(fn))(fn, stack[0], v_22638);
    env = stack[-8];
    stack[0] = v_22638;
    goto v_22002;
    stack[0] = nil;
v_22002:
    goto v_21997;
v_21998:
    goto v_22180;
v_22176:
    goto v_22186;
v_22182:
    v_22638 = stack[-6];
    v_22639 = qcdr(v_22638);
    goto v_22183;
v_22184:
    v_22638 = stack[-5];
    goto v_22185;
v_22186:
    goto v_22182;
v_22183:
    goto v_22184;
v_22185:
    v_22639 = cons(v_22639, v_22638);
    env = stack[-8];
    goto v_22177;
v_22178:
    v_22638 = stack[-4];
    goto v_22179;
v_22180:
    goto v_22176;
v_22177:
    goto v_22178;
v_22179:
    fn = elt(env, 10); // prepsq!*0
    v_22638 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    goto v_21999;
v_22000:
    goto v_21996;
v_21997:
    goto v_21998;
v_21999:
    {
        LispObject v_22649 = stack[0];
        fn = elt(env, 14); // nconc!*
        return (*qfn2(fn))(fn, v_22649, v_22638);
    }
v_21939:
    v_22638 = stack[-5];
    if (!consp(v_22638)) goto v_22197;
    else goto v_22198;
v_22197:
    v_22638 = lisp_true;
    goto v_22196;
v_22198:
    v_22638 = stack[-5];
    v_22638 = qcar(v_22638);
    v_22638 = (consp(v_22638) ? nil : lisp_true);
    goto v_22196;
    v_22638 = nil;
v_22196:
    if (v_22638 == nil) goto v_22193;
    else goto v_22194;
v_22193:
    v_22638 = qvalue(elt(env, 3)); // kord!*
    stack[-3] = v_22638;
v_22209:
    v_22638 = stack[-3];
    if (v_22638 == nil) goto v_22213;
    else goto v_22214;
v_22213:
    goto v_22208;
v_22214:
    v_22638 = stack[-3];
    v_22638 = qcar(v_22638);
    stack[-2] = v_22638;
    v_22638 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_22638;
    goto v_22232;
v_22228:
    goto v_22238;
v_22234:
    v_22639 = stack[-2];
    goto v_22235;
v_22236:
    v_22638 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22237;
v_22238:
    goto v_22234;
v_22235:
    goto v_22236;
v_22237:
    fn = elt(env, 11); // to
    v_22639 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    goto v_22229;
v_22230:
    v_22638 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22231;
v_22232:
    goto v_22228;
v_22229:
    goto v_22230;
v_22231:
    v_22638 = cons(v_22639, v_22638);
    env = stack[-8];
    v_22638 = ncons(v_22638);
    env = stack[-8];
    stack[0] = v_22638;
v_22244:
    goto v_22254;
v_22250:
    v_22639 = stack[-5];
    goto v_22251;
v_22252:
    v_22638 = stack[0];
    goto v_22253;
v_22254:
    goto v_22250;
v_22251:
    goto v_22252;
v_22253:
    fn = elt(env, 12); // quotfm
    v_22638 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    stack[-7] = v_22638;
    if (v_22638 == nil) goto v_22247;
    else goto v_22248;
v_22247:
    goto v_22243;
v_22248:
    v_22638 = stack[-1];
    v_22638 = sub1(v_22638);
    env = stack[-8];
    stack[-1] = v_22638;
    v_22638 = stack[-7];
    stack[-5] = v_22638;
    goto v_22244;
v_22243:
    goto v_22270;
v_22266:
    v_22639 = stack[-1];
    goto v_22267;
v_22268:
    v_22638 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22269;
v_22270:
    goto v_22266;
v_22267:
    goto v_22268;
v_22269:
    v_22638 = (LispObject)lessp2(v_22639, v_22638);
    v_22638 = v_22638 ? lisp_true : nil;
    env = stack[-8];
    if (v_22638 == nil) goto v_22264;
    goto v_22278;
v_22274:
    goto v_22284;
v_22280:
    goto v_22292;
v_22286:
    v_22640 = elt(env, 2); // expt
    goto v_22287;
v_22288:
    v_22639 = stack[-2];
    goto v_22289;
v_22290:
    v_22638 = stack[-1];
    goto v_22291;
v_22292:
    goto v_22286;
v_22287:
    goto v_22288;
v_22289:
    goto v_22290;
v_22291:
    v_22639 = list3(v_22640, v_22639, v_22638);
    env = stack[-8];
    goto v_22281;
v_22282:
    v_22638 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22283;
v_22284:
    goto v_22280;
v_22281:
    goto v_22282;
v_22283:
    fn = elt(env, 13); // mksp
    v_22639 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    goto v_22275;
v_22276:
    v_22638 = stack[-4];
    goto v_22277;
v_22278:
    goto v_22274;
v_22275:
    goto v_22276;
v_22277:
    v_22638 = cons(v_22639, v_22638);
    env = stack[-8];
    stack[-4] = v_22638;
    goto v_22262;
v_22264:
v_22262:
    v_22638 = stack[-3];
    v_22638 = qcdr(v_22638);
    stack[-3] = v_22638;
    goto v_22209;
v_22208:
    goto v_22192;
v_22194:
v_22192:
    v_22638 = stack[-6];
    fn = elt(env, 15); // kernlp
    v_22638 = (*qfn1(fn))(fn, v_22638);
    env = stack[-8];
    if (v_22638 == nil) goto v_22303;
    goto v_22311;
v_22307:
    v_22639 = stack[-4];
    goto v_22308;
v_22309:
    v_22638 = stack[-6];
    goto v_22310;
v_22311:
    goto v_22307;
v_22308:
    goto v_22309;
v_22310:
    fn = elt(env, 16); // mkkl
    v_22638 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    stack[-6] = v_22638;
    v_22638 = nil;
    stack[-4] = v_22638;
    goto v_22301;
v_22303:
v_22301:
    v_22638 = qvalue(elt(env, 4)); // dnl!*
    if (v_22638 == nil) goto v_22318;
    v_22638 = qvalue(elt(env, 5)); // !*allfac
    if (v_22638 == nil) goto v_22322;
    else goto v_22323;
v_22322:
    v_22638 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22321;
v_22323:
    v_22638 = stack[-6];
    fn = elt(env, 17); // ckrn
    v_22638 = (*qfn1(fn))(fn, v_22638);
    env = stack[-8];
    goto v_22321;
    v_22638 = nil;
v_22321:
    stack[-1] = v_22638;
    goto v_22335;
v_22331:
    v_22639 = stack[-1];
    goto v_22332;
v_22333:
    v_22638 = qvalue(elt(env, 4)); // dnl!*
    goto v_22334;
v_22335:
    goto v_22331;
v_22332:
    goto v_22333;
v_22334:
    fn = elt(env, 18); // ckrn!*
    v_22638 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    stack[-7] = v_22638;
    goto v_22343;
v_22339:
    v_22639 = stack[-1];
    goto v_22340;
v_22341:
    v_22638 = stack[-7];
    goto v_22342;
v_22343:
    goto v_22339;
v_22340:
    goto v_22341;
v_22342:
    fn = elt(env, 19); // quotof
    v_22638 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    goto v_22351;
v_22347:
    v_22639 = stack[-6];
    goto v_22348;
v_22349:
    v_22638 = stack[-7];
    goto v_22350;
v_22351:
    goto v_22347;
v_22348:
    goto v_22349;
v_22350:
    fn = elt(env, 19); // quotof
    v_22638 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    stack[-6] = v_22638;
    goto v_22359;
v_22355:
    v_22639 = stack[-5];
    goto v_22356;
v_22357:
    v_22638 = stack[-7];
    goto v_22358;
v_22359:
    goto v_22355;
v_22356:
    goto v_22357;
v_22358:
    fn = elt(env, 19); // quotof
    v_22638 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    stack[-5] = v_22638;
    goto v_22316;
v_22318:
v_22316:
    v_22638 = qvalue(elt(env, 6)); // upl!*
    if (v_22638 == nil) goto v_22365;
    v_22638 = stack[-5];
    fn = elt(env, 17); // ckrn
    v_22638 = (*qfn1(fn))(fn, v_22638);
    env = stack[-8];
    stack[0] = v_22638;
    goto v_22374;
v_22370:
    v_22639 = stack[0];
    goto v_22371;
v_22372:
    v_22638 = qvalue(elt(env, 6)); // upl!*
    goto v_22373;
v_22374:
    goto v_22370;
v_22371:
    goto v_22372;
v_22373:
    fn = elt(env, 18); // ckrn!*
    v_22638 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    stack[-7] = v_22638;
    goto v_22382;
v_22378:
    v_22639 = stack[0];
    goto v_22379;
v_22380:
    v_22638 = stack[-7];
    goto v_22381;
v_22382:
    goto v_22378;
v_22379:
    goto v_22380;
v_22381:
    fn = elt(env, 19); // quotof
    v_22638 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    stack[0] = v_22638;
    goto v_22390;
v_22386:
    v_22639 = stack[-6];
    goto v_22387;
v_22388:
    v_22638 = stack[-7];
    goto v_22389;
v_22390:
    goto v_22386;
v_22387:
    goto v_22388;
v_22389:
    fn = elt(env, 19); // quotof
    v_22638 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    stack[-6] = v_22638;
    goto v_22398;
v_22394:
    v_22639 = stack[-5];
    goto v_22395;
v_22396:
    v_22638 = stack[-7];
    goto v_22397;
v_22398:
    goto v_22394;
v_22395:
    goto v_22396;
v_22397:
    fn = elt(env, 19); // quotof
    v_22638 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    stack[-5] = v_22638;
    goto v_22363;
v_22365:
    v_22638 = qvalue(elt(env, 7)); // !*div
    if (v_22638 == nil) goto v_22402;
    v_22638 = stack[-5];
    fn = elt(env, 17); // ckrn
    v_22638 = (*qfn1(fn))(fn, v_22638);
    env = stack[-8];
    stack[0] = v_22638;
    goto v_22363;
v_22402:
    v_22638 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_22638;
    goto v_22363;
v_22363:
    goto v_22415;
v_22411:
    stack[-1] = stack[-6];
    goto v_22412;
v_22413:
    goto v_22422;
v_22418:
    v_22639 = stack[-5];
    goto v_22419;
v_22420:
    v_22638 = stack[0];
    goto v_22421;
v_22422:
    goto v_22418;
v_22419:
    goto v_22420;
v_22421:
    fn = elt(env, 19); // quotof
    v_22638 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    goto v_22414;
v_22415:
    goto v_22411;
v_22412:
    goto v_22413;
v_22414:
    v_22638 = cons(stack[-1], v_22638);
    env = stack[-8];
    fn = elt(env, 20); // canonsq
    v_22638 = (*qfn1(fn))(fn, v_22638);
    env = stack[-8];
    stack[-6] = v_22638;
    goto v_22430;
v_22426:
    goto v_22436;
v_22432:
    v_22638 = stack[-6];
    v_22639 = qcar(v_22638);
    goto v_22433;
v_22434:
    v_22638 = stack[0];
    goto v_22435;
v_22436:
    goto v_22432;
v_22433:
    goto v_22434;
v_22435:
    fn = elt(env, 19); // quotof
    v_22639 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    goto v_22427;
v_22428:
    v_22638 = stack[-6];
    v_22638 = qcdr(v_22638);
    goto v_22429;
v_22430:
    goto v_22426;
v_22427:
    goto v_22428;
v_22429:
    v_22638 = cons(v_22639, v_22638);
    env = stack[-8];
    stack[-6] = v_22638;
    v_22638 = qvalue(elt(env, 5)); // !*allfac
    if (v_22638 == nil) goto v_22445;
    v_22638 = stack[-6];
    v_22638 = qcar(v_22638);
    fn = elt(env, 17); // ckrn
    v_22638 = (*qfn1(fn))(fn, v_22638);
    env = stack[-8];
    stack[-1] = v_22638;
    v_22638 = stack[-6];
    v_22638 = qcdr(v_22638);
    fn = elt(env, 17); // ckrn
    v_22638 = (*qfn1(fn))(fn, v_22638);
    env = stack[-8];
    stack[0] = v_22638;
    goto v_22469;
v_22465:
    v_22639 = stack[-1];
    goto v_22466;
v_22467:
    v_22638 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22468;
v_22469:
    goto v_22465;
v_22466:
    goto v_22467;
v_22468:
    if (v_22639 == v_22638) goto v_22464;
    v_22638 = lisp_true;
    goto v_22462;
v_22464:
    goto v_22480;
v_22476:
    v_22639 = stack[0];
    goto v_22477;
v_22478:
    v_22638 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22479;
v_22480:
    goto v_22476;
v_22477:
    goto v_22478;
v_22479:
    v_22638 = Lneq(nil, v_22639, v_22638);
    env = stack[-8];
    goto v_22462;
    v_22638 = nil;
v_22462:
    if (v_22638 == nil) goto v_22460;
    goto v_22491;
v_22487:
    v_22639 = stack[-1];
    goto v_22488;
v_22489:
    v_22638 = stack[-6];
    v_22638 = qcar(v_22638);
    goto v_22490;
v_22491:
    goto v_22487;
v_22488:
    goto v_22489;
v_22490:
    if (equal(v_22639, v_22638)) goto v_22486;
    v_22638 = lisp_true;
    goto v_22484;
v_22486:
    goto v_22503;
v_22499:
    v_22639 = stack[0];
    goto v_22500;
v_22501:
    v_22638 = stack[-6];
    v_22638 = qcdr(v_22638);
    goto v_22502;
v_22503:
    goto v_22499;
v_22500:
    goto v_22501;
v_22502:
    v_22638 = Lneq(nil, v_22639, v_22638);
    env = stack[-8];
    goto v_22484;
    v_22638 = nil;
v_22484:
    goto v_22458;
v_22460:
    v_22638 = nil;
    goto v_22458;
    v_22638 = nil;
v_22458:
    if (v_22638 == nil) goto v_22456;
    goto v_22515;
v_22511:
    v_22638 = stack[-6];
    v_22639 = qcdr(v_22638);
    goto v_22512;
v_22513:
    v_22638 = stack[0];
    goto v_22514;
v_22515:
    goto v_22511;
v_22512:
    goto v_22513;
v_22514:
    fn = elt(env, 19); // quotof
    v_22638 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    stack[-5] = v_22638;
    goto v_22524;
v_22520:
    v_22638 = stack[-6];
    v_22639 = qcar(v_22638);
    goto v_22521;
v_22522:
    v_22638 = stack[-1];
    goto v_22523;
v_22524:
    goto v_22520;
v_22521:
    goto v_22522;
v_22523:
    fn = elt(env, 19); // quotof
    v_22638 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    stack[-6] = v_22638;
    goto v_22534;
v_22530:
    v_22639 = stack[-4];
    goto v_22531;
v_22532:
    v_22638 = stack[-1];
    goto v_22533;
v_22534:
    goto v_22530;
v_22531:
    goto v_22532;
v_22533:
    fn = elt(env, 16); // mkkl
    v_22638 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    fn = elt(env, 21); // prepf
    v_22638 = (*qfn1(fn))(fn, v_22638);
    env = stack[-8];
    stack[-4] = v_22638;
    v_22638 = stack[0];
    fn = elt(env, 21); // prepf
    v_22638 = (*qfn1(fn))(fn, v_22638);
    env = stack[-8];
    stack[-1] = v_22638;
    goto v_22544;
v_22540:
    v_22639 = stack[-4];
    goto v_22541;
v_22542:
    v_22638 = stack[-6];
    goto v_22543;
v_22544:
    goto v_22540;
v_22541:
    goto v_22542;
v_22543:
    fn = elt(env, 22); // addfactors
    v_22638 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    stack[-6] = v_22638;
    goto v_22552;
v_22548:
    v_22639 = stack[-1];
    goto v_22549;
v_22550:
    v_22638 = stack[-5];
    goto v_22551;
v_22552:
    goto v_22548;
v_22549:
    goto v_22550;
v_22551:
    fn = elt(env, 22); // addfactors
    v_22638 = (*qfn2(fn))(fn, v_22639, v_22638);
    env = stack[-8];
    stack[-5] = v_22638;
    goto v_22563;
v_22559:
    v_22639 = stack[-5];
    goto v_22560;
v_22561:
    v_22638 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22562;
v_22563:
    goto v_22559;
v_22560:
    goto v_22561;
v_22562:
    if (v_22639 == v_22638) goto v_22557;
    else goto v_22558;
v_22557:
    v_22638 = stack[-6];
    {
        fn = elt(env, 23); // rmplus
        return (*qfn1(fn))(fn, v_22638);
    }
v_22558:
    goto v_22580;
v_22576:
    v_22639 = stack[-6];
    goto v_22577;
v_22578:
    v_22638 = elt(env, 8); // minus
    goto v_22579;
v_22580:
    goto v_22576;
v_22577:
    goto v_22578;
v_22579:
    if (!consp(v_22639)) goto v_22574;
    v_22639 = qcar(v_22639);
    if (v_22639 == v_22638) goto v_22573;
    else goto v_22574;
v_22573:
    goto v_22588;
v_22584:
    stack[0] = elt(env, 8); // minus
    goto v_22585;
v_22586:
    goto v_22597;
v_22591:
    v_22640 = elt(env, 9); // quotient
    goto v_22592;
v_22593:
    v_22638 = stack[-6];
    v_22638 = qcdr(v_22638);
    v_22639 = qcar(v_22638);
    goto v_22594;
v_22595:
    v_22638 = stack[-5];
    goto v_22596;
v_22597:
    goto v_22591;
v_22592:
    goto v_22593;
v_22594:
    goto v_22595;
v_22596:
    v_22638 = list3(v_22640, v_22639, v_22638);
    env = stack[-8];
    goto v_22587;
v_22588:
    goto v_22584;
v_22585:
    goto v_22586;
v_22587:
    v_22638 = list2(stack[0], v_22638);
    goto v_22572;
v_22574:
    goto v_22612;
v_22606:
    v_22640 = elt(env, 9); // quotient
    goto v_22607;
v_22608:
    v_22639 = stack[-6];
    goto v_22609;
v_22610:
    v_22638 = stack[-5];
    goto v_22611;
v_22612:
    goto v_22606;
v_22607:
    goto v_22608;
v_22609:
    goto v_22610;
v_22611:
    v_22638 = list3(v_22640, v_22639, v_22638);
    goto v_22572;
    v_22638 = nil;
v_22572:
    return ncons(v_22638);
    v_22638 = nil;
    goto v_21935;
v_22456:
    goto v_22443;
v_22445:
v_22443:
    v_22638 = stack[-4];
    if (v_22638 == nil) goto v_22619;
    goto v_22628;
v_22624:
    v_22638 = stack[-4];
    fn = elt(env, 24); // exchk
    stack[0] = (*qfn1(fn))(fn, v_22638);
    env = stack[-8];
    goto v_22625;
v_22626:
    v_22638 = stack[-6];
    fn = elt(env, 25); // prepsq
    v_22638 = (*qfn1(fn))(fn, v_22638);
    env = stack[-8];
    goto v_22627;
v_22628:
    goto v_22624;
v_22625:
    goto v_22626;
v_22627:
    fn = elt(env, 26); // aconc!*
    v_22638 = (*qfn2(fn))(fn, stack[0], v_22638);
    env = stack[-8];
    fn = elt(env, 27); // retimes
    v_22638 = (*qfn1(fn))(fn, v_22638);
    return ncons(v_22638);
v_22619:
    v_22638 = stack[-6];
    fn = elt(env, 25); // prepsq
    v_22638 = (*qfn1(fn))(fn, v_22638);
    env = stack[-8];
    {
        fn = elt(env, 23); // rmplus
        return (*qfn1(fn))(fn, v_22638);
    }
    v_22638 = nil;
v_21935:
    return onevalue(v_22638);
}



// Code for num_signsort

static LispObject CC_num_signsort(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_21937, v_21938;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21937 = v_21927;
// end of prologue
    goto v_21934;
v_21930:
    v_21938 = v_21937;
    goto v_21931;
v_21932:
    v_21937 = elt(env, 1); // lambda_ygm6np4pcqv31
    goto v_21933;
v_21934:
    goto v_21930;
v_21931:
    goto v_21932;
v_21933:
    {
        fn = elt(env, 2); // ad_signsort
        return (*qfn2(fn))(fn, v_21938, v_21937);
    }
}



// Code for lambda_ygm6np4pcqv31

static LispObject CC_lambda_ygm6np4pcqv31(LispObject env,
                         LispObject v_21927, LispObject v_21928)
{
    env = qenv(env);
    LispObject v_21938, v_21939;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21938 = v_21928;
    v_21939 = v_21927;
// end of prologue
    goto v_21935;
v_21931:
    goto v_21932;
v_21933:
    goto v_21934;
v_21935:
    goto v_21931;
v_21932:
    goto v_21933;
v_21934:
        return Lleq(nil, v_21939, v_21938);
}



// Code for makeqn!-maybe

static LispObject CC_makeqnKmaybe(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21950, v_21951, v_21952;
    LispObject v_21929, v_21928, v_21927;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "makeqn-maybe");
    va_start(aa, nargs);
    v_21927 = va_arg(aa, LispObject);
    v_21928 = va_arg(aa, LispObject);
    v_21929 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21950 = v_21929;
    v_21951 = v_21928;
    v_21952 = v_21927;
// end of prologue
    if (v_21950 == nil) goto v_21934;
    v_21950 = v_21951;
    goto v_21932;
v_21934:
    goto v_21946;
v_21940:
    v_21950 = elt(env, 1); // equal
    goto v_21941;
v_21942:
    goto v_21943;
v_21944:
    goto v_21945;
v_21946:
    goto v_21940;
v_21941:
    goto v_21942;
v_21943:
    goto v_21944;
v_21945:
    return list3(v_21950, v_21952, v_21951);
    v_21950 = nil;
v_21932:
    return onevalue(v_21950);
}



// Code for assoc2

static LispObject CC_assoc2(LispObject env,
                         LispObject v_21927, LispObject v_21928)
{
    env = qenv(env);
    LispObject v_21956, v_21957, v_21958, v_21959;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21957 = v_21928;
    v_21958 = v_21927;
// end of prologue
v_21932:
    v_21956 = v_21957;
    if (v_21956 == nil) goto v_21935;
    else goto v_21936;
v_21935:
    v_21956 = nil;
    goto v_21931;
v_21936:
    goto v_21945;
v_21941:
    v_21959 = v_21958;
    goto v_21942;
v_21943:
    v_21956 = v_21957;
    v_21956 = qcar(v_21956);
    v_21956 = qcdr(v_21956);
    goto v_21944;
v_21945:
    goto v_21941;
v_21942:
    goto v_21943;
v_21944:
    if (equal(v_21959, v_21956)) goto v_21939;
    else goto v_21940;
v_21939:
    v_21956 = v_21957;
    v_21956 = qcar(v_21956);
    goto v_21931;
v_21940:
    v_21956 = v_21957;
    v_21956 = qcdr(v_21956);
    v_21957 = v_21956;
    goto v_21932;
    v_21956 = nil;
v_21931:
    return onevalue(v_21956);
}



// Code for vector!-to!-poly

static LispObject CC_vectorKtoKpoly(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22025, v_22026, v_22027;
    LispObject fn;
    LispObject v_21930, v_21929, v_21928;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "vector-to-poly");
    va_start(aa, nargs);
    v_21928 = va_arg(aa, LispObject);
    v_21929 = va_arg(aa, LispObject);
    v_21930 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21930,v_21929,v_21928);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21928,v_21929,v_21930);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_21930;
    v_22025 = v_21929;
    stack[-3] = v_21928;
// end of prologue
// Binding d
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = v_22025; // d
    goto v_21947;
v_21943:
    v_22026 = qvalue(elt(env, 1)); // d
    goto v_21944;
v_21945:
    v_22025 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21946;
v_21947:
    goto v_21943;
v_21944:
    goto v_21945;
v_21946:
    if (((intptr_t)(v_22026)) < ((intptr_t)(v_22025))) goto v_21941;
    else goto v_21942;
v_21941:
    v_22025 = nil;
    goto v_21938;
v_21942:
    goto v_21956;
v_21952:
    v_22026 = stack[-3];
    goto v_21953;
v_21954:
    v_22025 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21955;
v_21956:
    goto v_21952;
v_21953:
    goto v_21954;
v_21955:
    v_22025 = *(LispObject *)((char *)v_22026 + (CELL-TAG_VECTOR) + (((intptr_t)v_22025-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 2); // !*n2f
    v_22025 = (*qfn1(fn))(fn, v_22025);
    env = stack[-5];
    stack[-1] = v_22025;
    v_22025 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_22025;
v_21963:
    goto v_21975;
v_21971:
    v_22026 = qvalue(elt(env, 1)); // d
    goto v_21972;
v_21973:
    v_22025 = stack[0];
    goto v_21974;
v_21975:
    goto v_21971;
v_21972:
    goto v_21973;
v_21974:
    v_22025 = difference2(v_22026, v_22025);
    env = stack[-5];
    v_22025 = Lminusp(nil, v_22025);
    env = stack[-5];
    if (v_22025 == nil) goto v_21968;
    goto v_21962;
v_21968:
    goto v_21987;
v_21983:
    goto v_21992;
v_21988:
    v_22026 = stack[-3];
    goto v_21989;
v_21990:
    v_22025 = stack[0];
    goto v_21991;
v_21992:
    goto v_21988;
v_21989:
    goto v_21990;
v_21991:
    v_22026 = *(LispObject *)((char *)v_22026 + (CELL-TAG_VECTOR) + (((intptr_t)v_22025-TAG_FIXNUM)/(16/CELL)));
    goto v_21984;
v_21985:
    v_22025 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21986;
v_21987:
    goto v_21983;
v_21984:
    goto v_21985;
v_21986:
    if (v_22026 == v_22025) goto v_21982;
    goto v_22004;
v_21998:
    goto v_22010;
v_22006:
    v_22026 = stack[-2];
    goto v_22007;
v_22008:
    v_22025 = stack[0];
    goto v_22009;
v_22010:
    goto v_22006;
v_22007:
    goto v_22008;
v_22009:
    fn = elt(env, 3); // to
    v_22027 = (*qfn2(fn))(fn, v_22026, v_22025);
    env = stack[-5];
    goto v_21999;
v_22000:
    goto v_22017;
v_22013:
    v_22026 = stack[-3];
    goto v_22014;
v_22015:
    v_22025 = stack[0];
    goto v_22016;
v_22017:
    goto v_22013;
v_22014:
    goto v_22015;
v_22016:
    v_22026 = *(LispObject *)((char *)v_22026 + (CELL-TAG_VECTOR) + (((intptr_t)v_22025-TAG_FIXNUM)/(16/CELL)));
    goto v_22001;
v_22002:
    v_22025 = stack[-1];
    goto v_22003;
v_22004:
    goto v_21998;
v_21999:
    goto v_22000;
v_22001:
    goto v_22002;
v_22003:
    v_22025 = acons(v_22027, v_22026, v_22025);
    env = stack[-5];
    stack[-1] = v_22025;
    goto v_21980;
v_21982:
v_21980:
    v_22025 = stack[0];
    v_22025 = add1(v_22025);
    env = stack[-5];
    stack[0] = v_22025;
    goto v_21963;
v_21962:
    v_22025 = stack[-1];
v_21938:
    ;}  // end of a binding scope
    return onevalue(v_22025);
}



// Code for lalr_make_compressed_goto_table

static LispObject CC_lalr_make_compressed_goto_table(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21990, v_21991, v_21992, v_21993;
    LispObject fn;
    argcheck(nargs, 0, "lalr_make_compressed_goto_table");
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
    v_21990 = qvalue(elt(env, 1)); // nonterminals
    v_21990 = Llength(nil, v_21990);
    env = stack[-3];
    v_21990 = sub1(v_21990);
    env = stack[-3];
    v_21990 = Lmkvect(nil, v_21990);
    env = stack[-3];
    stack[-2] = v_21990;
    v_21990 = qvalue(elt(env, 1)); // nonterminals
    stack[-1] = v_21990;
v_21939:
    v_21990 = stack[-1];
    if (v_21990 == nil) goto v_21943;
    else goto v_21944;
v_21943:
    goto v_21938;
v_21944:
    v_21990 = stack[-1];
    v_21990 = qcar(v_21990);
    stack[0] = v_21990;
    goto v_21958;
v_21954:
    v_21991 = stack[0];
    goto v_21955;
v_21956:
    v_21990 = elt(env, 2); // !S!'
    goto v_21957;
v_21958:
    goto v_21954;
v_21955:
    goto v_21956;
v_21957:
    if (v_21991 == v_21990) goto v_21953;
    v_21990 = stack[0];
    fn = elt(env, 5); // lalr_make_compressed_goto_column
    v_21990 = (*qfn1(fn))(fn, v_21990);
    env = stack[-3];
    v_21993 = v_21990;
    goto v_21969;
v_21963:
    v_21992 = stack[-2];
    goto v_21964;
v_21965:
    goto v_21976;
v_21972:
    v_21991 = stack[0];
    goto v_21973;
v_21974:
    v_21990 = elt(env, 3); // lalr_nonterminal_code
    goto v_21975;
v_21976:
    goto v_21972;
v_21973:
    goto v_21974;
v_21975:
    v_21990 = get(v_21991, v_21990);
    env = stack[-3];
    goto v_21966;
v_21967:
    v_21991 = v_21993;
    goto v_21968;
v_21969:
    goto v_21963;
v_21964:
    goto v_21965;
v_21966:
    goto v_21967;
v_21968:
    *(LispObject *)((char *)v_21992 + (CELL-TAG_VECTOR) + (((intptr_t)v_21990-TAG_FIXNUM)/(16/CELL))) = v_21991;
    goto v_21951;
v_21953:
v_21951:
    v_21990 = stack[-1];
    v_21990 = qcdr(v_21990);
    stack[-1] = v_21990;
    goto v_21939;
v_21938:
    v_21990 = qvalue(elt(env, 4)); // !*lalr_verbose
    if (v_21990 == nil) goto v_21985;
    v_21990 = stack[-2];
    fn = elt(env, 6); // lalr_print_compressed_goto_table
    v_21990 = (*qfn1(fn))(fn, v_21990);
    goto v_21983;
v_21985:
v_21983:
    v_21990 = stack[-2];
    return onevalue(v_21990);
}



// Code for my!+nullsq!+p

static LispObject CC_myLnullsqLp(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_21938;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21938 = v_21927;
// end of prologue
    v_21938 = qcar(v_21938);
    if (v_21938 == nil) goto v_21933;
    else goto v_21934;
v_21933:
    v_21938 = lisp_true;
    goto v_21930;
v_21934:
    v_21938 = nil;
v_21930:
    return onevalue(v_21938);
}



// Code for dvfsf_simplat1

static LispObject CC_dvfsf_simplat1(LispObject env,
                         LispObject v_21927, LispObject v_21928)
{
    env = qenv(env);
    LispObject v_21989, v_21990, v_21991;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21928,v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21927,v_21928);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_21928;
    stack[-2] = v_21927;
// end of prologue
    v_21989 = stack[-2];
    fn = elt(env, 3); // dvfsf_op
    v_21989 = (*qfn1(fn))(fn, v_21989);
    env = stack[-4];
    v_21991 = v_21989;
    goto v_21947;
v_21943:
    v_21990 = v_21991;
    goto v_21944;
v_21945:
    v_21989 = elt(env, 1); // equal
    goto v_21946;
v_21947:
    goto v_21943;
v_21944:
    goto v_21945;
v_21946:
    if (v_21990 == v_21989) goto v_21941;
    else goto v_21942;
v_21941:
    v_21989 = lisp_true;
    goto v_21940;
v_21942:
    goto v_21957;
v_21953:
    v_21990 = v_21991;
    goto v_21954;
v_21955:
    v_21989 = elt(env, 2); // neq
    goto v_21956;
v_21957:
    goto v_21953;
v_21954:
    goto v_21955;
v_21956:
    v_21989 = (v_21990 == v_21989 ? lisp_true : nil);
    goto v_21940;
    v_21989 = nil;
v_21940:
    if (v_21989 == nil) goto v_21938;
    goto v_21968;
v_21962:
    stack[0] = v_21991;
    goto v_21963;
v_21964:
    v_21989 = stack[-2];
    fn = elt(env, 4); // dvfsf_arg2l
    v_21990 = (*qfn1(fn))(fn, v_21989);
    env = stack[-4];
    goto v_21965;
v_21966:
    v_21989 = stack[-1];
    goto v_21967;
v_21968:
    goto v_21962;
v_21963:
    goto v_21964;
v_21965:
    goto v_21966;
v_21967:
    {
        LispObject v_21996 = stack[0];
        fn = elt(env, 5); // dvfsf_safield
        return (*qfnn(fn))(fn, 3, v_21996, v_21990, v_21989);
    }
v_21938:
    goto v_21982;
v_21974:
    stack[-3] = v_21991;
    goto v_21975;
v_21976:
    v_21989 = stack[-2];
    fn = elt(env, 4); // dvfsf_arg2l
    stack[0] = (*qfn1(fn))(fn, v_21989);
    env = stack[-4];
    goto v_21977;
v_21978:
    v_21989 = stack[-2];
    fn = elt(env, 6); // dvfsf_arg2r
    v_21990 = (*qfn1(fn))(fn, v_21989);
    env = stack[-4];
    goto v_21979;
v_21980:
    v_21989 = stack[-1];
    goto v_21981;
v_21982:
    goto v_21974;
v_21975:
    goto v_21976;
v_21977:
    goto v_21978;
v_21979:
    goto v_21980;
v_21981:
    {
        LispObject v_21997 = stack[-3];
        LispObject v_21998 = stack[0];
        fn = elt(env, 7); // dvfsf_saval
        return (*qfnn(fn))(fn, 4, v_21997, v_21998, v_21990, v_21989);
    }
    return onevalue(v_21989);
}



// Code for matrixelems

static LispObject CC_matrixelems(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_21955, v_21956;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21927);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21927;
// end of prologue
    v_21956 = nil;
v_21932:
    v_21955 = stack[0];
    if (v_21955 == nil) goto v_21936;
    goto v_21943;
v_21939:
    v_21955 = stack[0];
    v_21955 = qcar(v_21955);
    v_21955 = qcdr(v_21955);
    v_21955 = qcdr(v_21955);
    goto v_21940;
v_21941:
    goto v_21942;
v_21943:
    goto v_21939;
v_21940:
    goto v_21941;
v_21942:
    v_21955 = cons(v_21955, v_21956);
    env = stack[-1];
    v_21956 = v_21955;
    v_21955 = stack[0];
    v_21955 = qcdr(v_21955);
    stack[0] = v_21955;
    goto v_21932;
v_21936:
    v_21955 = v_21956;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_21955);
    }
    v_21955 = nil;
    return onevalue(v_21955);
}



// Code for multerm

static LispObject CC_multerm(LispObject env,
                         LispObject v_21927, LispObject v_21928)
{
    env = qenv(env);
    LispObject v_21960, v_21961;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21928,v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21927,v_21928);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21928;
    stack[-1] = v_21927;
// end of prologue
    goto v_21938;
v_21934:
    v_21960 = stack[-1];
    v_21961 = qcdr(v_21960);
    goto v_21935;
v_21936:
    v_21960 = stack[0];
    v_21960 = qcdr(v_21960);
    goto v_21937;
v_21938:
    goto v_21934;
v_21935:
    goto v_21936;
v_21937:
    fn = elt(env, 1); // !*multsq
    v_21960 = (*qfn2(fn))(fn, v_21961, v_21960);
    env = stack[-3];
    goto v_21948;
v_21944:
    stack[-2] = v_21960;
    goto v_21945;
v_21946:
    goto v_21955;
v_21951:
    v_21960 = stack[-1];
    v_21961 = qcar(v_21960);
    goto v_21952;
v_21953:
    v_21960 = stack[0];
    v_21960 = qcar(v_21960);
    goto v_21954;
v_21955:
    goto v_21951;
v_21952:
    goto v_21953;
v_21954:
    fn = elt(env, 2); // mulpower
    v_21960 = (*qfn2(fn))(fn, v_21961, v_21960);
    env = stack[-3];
    goto v_21947;
v_21948:
    goto v_21944;
v_21945:
    goto v_21946;
v_21947:
    {
        LispObject v_21965 = stack[-2];
        fn = elt(env, 3); // multdfconst
        return (*qfn2(fn))(fn, v_21965, v_21960);
    }
    return onevalue(v_21960);
}



// Code for sptransmat

static LispObject CC_sptransmat(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_22084, v_22085, v_22086, v_22087;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21927);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-1] = v_21927;
// end of prologue
    v_22084 = stack[-1];
    v_22084 = Lconsp(nil, v_22084);
    env = stack[-7];
    if (v_22084 == nil) goto v_21942;
    v_22084 = stack[-1];
    stack[0] = v_22084;
    v_22084 = stack[-1];
    fn = elt(env, 2); // matlength
    v_22084 = (*qfn1(fn))(fn, v_22084);
    env = stack[-7];
    v_22084 = qcdr(v_22084);
    goto v_21940;
v_21942:
    v_22084 = stack[-1];
    fn = elt(env, 3); // aeval
    v_22084 = (*qfn1(fn))(fn, v_22084);
    env = stack[-7];
    stack[0] = v_22084;
    v_22084 = stack[-1];
    fn = elt(env, 3); // aeval
    v_22084 = (*qfn1(fn))(fn, v_22084);
    env = stack[-7];
    fn = elt(env, 2); // matlength
    v_22084 = (*qfn1(fn))(fn, v_22084);
    env = stack[-7];
    v_22084 = qcdr(v_22084);
    goto v_21940;
v_21940:
    v_22085 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_22085;
    v_22085 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_22085;
    goto v_21964;
v_21960:
    v_22085 = v_22084;
    stack[-1] = qcar(v_22085);
    goto v_21961;
v_21962:
    goto v_21972;
v_21968:
    v_22085 = elt(env, 1); // spm
    goto v_21969;
v_21970:
    goto v_21971;
v_21972:
    goto v_21968;
v_21969:
    goto v_21970;
v_21971:
    v_22084 = cons(v_22085, v_22084);
    env = stack[-7];
    goto v_21963;
v_21964:
    goto v_21960;
v_21961:
    goto v_21962;
v_21963:
    fn = elt(env, 4); // mkempspmat
    v_22084 = (*qfn2(fn))(fn, stack[-1], v_22084);
    env = stack[-7];
    stack[-2] = v_22084;
    v_22084 = nil;
    v_22084 = ncons(v_22084);
    env = stack[-7];
    v_22084 = ncons(v_22084);
    env = stack[-7];
    stack[-3] = v_22084;
    v_22084 = stack[0];
    v_22084 = qcdr(v_22084);
    stack[-1] = v_22084;
v_21981:
    v_22084 = stack[-1];
    if (v_22084 == nil) goto v_21986;
    else goto v_21987;
v_21986:
    goto v_21980;
v_21987:
    v_22084 = stack[-1];
    v_22084 = qcar(v_22084);
    stack[0] = v_22084;
    v_22084 = stack[-6];
    v_22084 = add1(v_22084);
    env = stack[-7];
    stack[-6] = v_22084;
    v_22084 = stack[0];
    stack[0] = v_22084;
v_21999:
    v_22084 = stack[0];
    if (v_22084 == nil) goto v_22003;
    else goto v_22004;
v_22003:
    goto v_21998;
v_22004:
    v_22084 = stack[0];
    v_22084 = qcar(v_22084);
    stack[-4] = v_22084;
    v_22084 = stack[-5];
    v_22084 = add1(v_22084);
    env = stack[-7];
    stack[-5] = v_22084;
    goto v_22021;
v_22017:
    v_22085 = stack[-4];
    goto v_22018;
v_22019:
    v_22084 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22020;
v_22021:
    goto v_22017;
v_22018:
    goto v_22019;
v_22020:
    if (v_22085 == v_22084) goto v_22015;
    else goto v_22016;
v_22015:
    goto v_22014;
v_22016:
    goto v_22034;
v_22028:
    v_22086 = stack[-5];
    goto v_22029;
v_22030:
    v_22085 = stack[-4];
    goto v_22031;
v_22032:
    v_22084 = stack[-3];
    goto v_22033;
v_22034:
    goto v_22028;
v_22029:
    goto v_22030;
v_22031:
    goto v_22032;
v_22033:
    v_22084 = acons(v_22086, v_22085, v_22084);
    env = stack[-7];
    stack[-3] = v_22084;
    goto v_22014;
v_22014:
    v_22084 = stack[0];
    v_22084 = qcdr(v_22084);
    stack[0] = v_22084;
    goto v_21999;
v_21998:
    v_22084 = stack[-3];
    v_22084 = Lreverse(nil, v_22084);
    env = stack[-7];
    stack[-3] = v_22084;
    goto v_22050;
v_22046:
    stack[0] = stack[-3];
    goto v_22047;
v_22048:
    v_22084 = nil;
    v_22084 = ncons(v_22084);
    env = stack[-7];
    v_22084 = ncons(v_22084);
    env = stack[-7];
    goto v_22049;
v_22050:
    goto v_22046;
v_22047:
    goto v_22048;
v_22049:
    if (equal(stack[0], v_22084)) goto v_22045;
    goto v_22064;
v_22056:
    goto v_22070;
v_22066:
    v_22085 = stack[-2];
    goto v_22067;
v_22068:
    v_22084 = stack[-6];
    goto v_22069;
v_22070:
    goto v_22066;
v_22067:
    goto v_22068;
v_22069:
    v_22087 = list2(v_22085, v_22084);
    env = stack[-7];
    goto v_22057;
v_22058:
    v_22086 = stack[-3];
    goto v_22059;
v_22060:
    v_22085 = stack[-2];
    goto v_22061;
v_22062:
    v_22084 = nil;
    goto v_22063;
v_22064:
    goto v_22056;
v_22057:
    goto v_22058;
v_22059:
    goto v_22060;
v_22061:
    goto v_22062;
v_22063:
    fn = elt(env, 5); // letmtr3
    v_22084 = (*qfnn(fn))(fn, 4, v_22087, v_22086, v_22085, v_22084);
    env = stack[-7];
    goto v_22043;
v_22045:
v_22043:
    v_22084 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_22084;
    v_22084 = nil;
    v_22084 = ncons(v_22084);
    env = stack[-7];
    v_22084 = ncons(v_22084);
    env = stack[-7];
    stack[-3] = v_22084;
    v_22084 = stack[-1];
    v_22084 = qcdr(v_22084);
    stack[-1] = v_22084;
    goto v_21981;
v_21980:
    v_22084 = stack[-2];
    return onevalue(v_22084);
}



// Code for weak_xreduce1

static LispObject CC_weak_xreduce1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22103, v_22104, v_22105;
    LispObject fn;
    LispObject v_21929, v_21928, v_21927;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "weak_xreduce1");
    va_start(aa, nargs);
    v_21927 = va_arg(aa, LispObject);
    v_21928 = va_arg(aa, LispObject);
    v_21929 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21929,v_21928,v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21927,v_21928,v_21929);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_21929;
    stack[-4] = v_21928;
    stack[-5] = v_21927;
// end of prologue
    v_22103 = stack[-4];
    stack[0] = v_22103;
v_21941:
    v_22103 = stack[-5];
    if (v_22103 == nil) goto v_21944;
    v_22103 = stack[0];
    if (v_22103 == nil) goto v_21944;
    goto v_21945;
v_21944:
    goto v_21940;
v_21945:
    v_22103 = stack[0];
    v_22103 = qcar(v_22103);
    stack[-6] = v_22103;
    v_22103 = stack[0];
    v_22103 = qcdr(v_22103);
    stack[0] = v_22103;
    goto v_21966;
v_21962:
    v_22103 = stack[-6];
    fn = elt(env, 7); // xval
    stack[-1] = (*qfn1(fn))(fn, v_22103);
    env = stack[-7];
    goto v_21963;
v_21964:
    v_22103 = stack[-5];
    fn = elt(env, 7); // xval
    v_22103 = (*qfn1(fn))(fn, v_22103);
    env = stack[-7];
    goto v_21965;
v_21966:
    goto v_21962;
v_21963:
    goto v_21964;
v_21965:
    fn = elt(env, 8); // xdiv
    v_22103 = (*qfn2(fn))(fn, stack[-1], v_22103);
    env = stack[-7];
    stack[-1] = v_22103;
    if (v_22103 == nil) goto v_21960;
    goto v_21981;
v_21975:
    v_22103 = stack[-1];
    fn = elt(env, 9); // mknwedge
    v_22105 = (*qfn1(fn))(fn, v_22103);
    env = stack[-7];
    goto v_21976;
v_21977:
    v_22104 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21978;
v_21979:
    v_22103 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21980;
v_21981:
    goto v_21975;
v_21976:
    goto v_21977;
v_21978:
    goto v_21979;
v_21980:
    v_22103 = list2star(v_22105, v_22104, v_22103);
    env = stack[-7];
    v_22103 = ncons(v_22103);
    env = stack[-7];
    stack[-1] = v_22103;
    goto v_21991;
v_21987:
    v_22104 = stack[-1];
    goto v_21988;
v_21989:
    v_22103 = stack[-6];
    goto v_21990;
v_21991:
    goto v_21987;
v_21988:
    goto v_21989;
v_21990:
    fn = elt(env, 10); // wedgepf
    v_22103 = (*qfn2(fn))(fn, v_22104, v_22103);
    env = stack[-7];
    stack[0] = v_22103;
    goto v_21999;
v_21995:
    v_22103 = stack[-5];
    v_22103 = qcar(v_22103);
    v_22104 = qcdr(v_22103);
    goto v_21996;
v_21997:
    v_22103 = stack[0];
    v_22103 = qcar(v_22103);
    v_22103 = qcdr(v_22103);
    goto v_21998;
v_21999:
    goto v_21995;
v_21996:
    goto v_21997;
v_21998:
    fn = elt(env, 11); // quotsq
    v_22103 = (*qfn2(fn))(fn, v_22104, v_22103);
    env = stack[-7];
    stack[-2] = v_22103;
    goto v_22012;
v_22008:
    goto v_22009;
v_22010:
    goto v_22019;
v_22015:
    goto v_22016;
v_22017:
    v_22103 = stack[-2];
    fn = elt(env, 12); // negsq
    v_22103 = (*qfn1(fn))(fn, v_22103);
    env = stack[-7];
    goto v_22018;
v_22019:
    goto v_22015;
v_22016:
    goto v_22017;
v_22018:
    fn = elt(env, 13); // multpfsq
    v_22103 = (*qfn2(fn))(fn, stack[0], v_22103);
    env = stack[-7];
    goto v_22011;
v_22012:
    goto v_22008;
v_22009:
    goto v_22010;
v_22011:
    fn = elt(env, 14); // addpf
    v_22103 = (*qfn2(fn))(fn, stack[-5], v_22103);
    env = stack[-7];
    fn = elt(env, 15); // subs2pf
    v_22103 = (*qfn1(fn))(fn, v_22103);
    env = stack[-7];
    stack[-5] = v_22103;
    v_22103 = qvalue(elt(env, 1)); // !*trxmod
    if (v_22103 == nil) goto v_22026;
    goto v_22033;
v_22029:
    stack[0] = stack[-3];
    goto v_22030;
v_22031:
    goto v_22041;
v_22037:
    goto v_22047;
v_22043:
    v_22104 = stack[-1];
    goto v_22044;
v_22045:
    v_22103 = stack[-2];
    goto v_22046;
v_22047:
    goto v_22043;
v_22044:
    goto v_22045;
v_22046:
    fn = elt(env, 13); // multpfsq
    v_22104 = (*qfn2(fn))(fn, v_22104, v_22103);
    env = stack[-7];
    goto v_22038;
v_22039:
    v_22103 = stack[-6];
    goto v_22040;
v_22041:
    goto v_22037;
v_22038:
    goto v_22039;
v_22040:
    v_22103 = list2(v_22104, v_22103);
    env = stack[-7];
    v_22103 = ncons(v_22103);
    env = stack[-7];
    goto v_22032;
v_22033:
    goto v_22029;
v_22030:
    goto v_22031;
v_22032:
    v_22103 = Lnconc(nil, stack[0], v_22103);
    env = stack[-7];
    stack[-3] = v_22103;
    goto v_22024;
v_22026:
v_22024:
    v_22103 = qvalue(elt(env, 1)); // !*trxmod
    if (v_22103 == nil) goto v_22054;
    goto v_22061;
v_22057:
    v_22104 = elt(env, 2); // "   "
    goto v_22058;
v_22059:
    v_22103 = elt(env, 3); // first
    goto v_22060;
v_22061:
    goto v_22057;
v_22058:
    goto v_22059;
v_22060:
    fn = elt(env, 16); // writepri
    v_22103 = (*qfn2(fn))(fn, v_22104, v_22103);
    env = stack[-7];
    goto v_22069;
v_22065:
    goto v_22078;
v_22072:
    stack[0] = elt(env, 4); // wedge
    goto v_22073;
v_22074:
    goto v_22086;
v_22082:
    v_22104 = stack[-1];
    goto v_22083;
v_22084:
    v_22103 = stack[-2];
    goto v_22085;
v_22086:
    goto v_22082;
v_22083:
    goto v_22084;
v_22085:
    fn = elt(env, 13); // multpfsq
    v_22103 = (*qfn2(fn))(fn, v_22104, v_22103);
    env = stack[-7];
    fn = elt(env, 17); // preppf
    stack[-1] = (*qfn1(fn))(fn, v_22103);
    env = stack[-7];
    goto v_22075;
v_22076:
    v_22103 = stack[-6];
    fn = elt(env, 17); // preppf
    v_22103 = (*qfn1(fn))(fn, v_22103);
    env = stack[-7];
    goto v_22077;
v_22078:
    goto v_22072;
v_22073:
    goto v_22074;
v_22075:
    goto v_22076;
v_22077:
    v_22103 = list3(stack[0], stack[-1], v_22103);
    env = stack[-7];
    v_22104 = Lmkquote(nil, v_22103);
    env = stack[-7];
    goto v_22066;
v_22067:
    v_22103 = nil;
    goto v_22068;
v_22069:
    goto v_22065;
v_22066:
    goto v_22067;
v_22068:
    fn = elt(env, 16); // writepri
    v_22103 = (*qfn2(fn))(fn, v_22104, v_22103);
    env = stack[-7];
    goto v_22097;
v_22093:
    v_22104 = elt(env, 5); // " +"
    goto v_22094;
v_22095:
    v_22103 = elt(env, 6); // last
    goto v_22096;
v_22097:
    goto v_22093;
v_22094:
    goto v_22095;
v_22096:
    fn = elt(env, 16); // writepri
    v_22103 = (*qfn2(fn))(fn, v_22104, v_22103);
    env = stack[-7];
    goto v_22052;
v_22054:
v_22052:
    v_22103 = stack[-4];
    stack[0] = v_22103;
    goto v_21958;
v_21960:
v_21958:
    goto v_21941;
v_21940:
    v_22103 = stack[-5];
    return onevalue(v_22103);
}



// Code for toolongassignp

static LispObject CC_toolongassignp(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_21934;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21934 = v_21927;
// end of prologue
    v_21934 = qcdr(v_21934);
    v_21934 = qcdr(v_21934);
    v_21934 = qcar(v_21934);
    {
        fn = elt(env, 1); // toolongexpp
        return (*qfn1(fn))(fn, v_21934);
    }
}



// Code for simppartdf

static LispObject CC_simppartdf(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_21932;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21927);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21932 = v_21927;
// end of prologue
    fn = elt(env, 1); // partitpartdf
    v_21932 = (*qfn1(fn))(fn, v_21932);
    env = stack[0];
    {
        fn = elt(env, 2); // !*pf2sq
        return (*qfn1(fn))(fn, v_21932);
    }
}



// Code for dfp!-sub

static LispObject CC_dfpKsub(LispObject env,
                         LispObject v_21927, LispObject v_21928)
{
    env = qenv(env);
    LispObject v_22105, v_22106, v_22107;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21928,v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21927,v_21928);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_21928;
    stack[-4] = v_21927;
// end of prologue
    v_22105 = stack[-3];
    v_22105 = qcdr(v_22105);
    v_22105 = qcar(v_22105);
    v_22106 = v_22105;
    v_22105 = v_22106;
    v_22105 = qcdr(v_22105);
    stack[-5] = v_22105;
    goto v_21948;
v_21944:
    v_22105 = v_22106;
    v_22106 = qcar(v_22105);
    stack[-2] = v_22106;
    goto v_21945;
v_21946:
    v_22105 = elt(env, 1); // generic_function
    goto v_21947;
v_21948:
    goto v_21944;
v_21945:
    goto v_21946;
v_21947:
    v_22105 = get(v_22106, v_22105);
    env = stack[-6];
    stack[-1] = v_22105;
    v_22105 = stack[-5];
    if (v_22105 == nil) goto v_21954;
    else goto v_21955;
v_21954:
    v_22105 = nil;
    v_22106 = stack[-1];
    v_22107 = v_22106;
v_21961:
    v_22106 = v_22107;
    if (v_22106 == nil) goto v_21965;
    else goto v_21966;
v_21965:
    goto v_21960;
v_21966:
    v_22106 = v_22107;
    v_22106 = qcar(v_22106);
    if (v_22105 == nil) goto v_21974;
    else goto v_21973;
v_21974:
    goto v_21980;
v_21976:
    goto v_21977;
v_21978:
    v_22105 = stack[-4];
    goto v_21979;
v_21980:
    goto v_21976;
v_21977:
    goto v_21978;
v_21979:
    v_22105 = Lassoc(nil, v_22106, v_22105);
v_21973:
    v_22106 = v_22107;
    v_22106 = qcdr(v_22106);
    v_22107 = v_22106;
    goto v_21961;
v_21960:
    if (v_22105 == nil) goto v_21989;
    v_22105 = stack[-1];
    stack[-5] = v_22105;
    goto v_21987;
v_21989:
v_21987:
    goto v_21953;
v_21955:
v_21953:
    goto v_21998;
v_21994:
    stack[0] = stack[-4];
    goto v_21995;
v_21996:
    goto v_22005;
v_22001:
    v_22106 = elt(env, 2); // list
    goto v_22002;
v_22003:
    v_22105 = stack[-5];
    goto v_22004;
v_22005:
    goto v_22001;
v_22002:
    goto v_22003;
v_22004:
    v_22105 = cons(v_22106, v_22105);
    env = stack[-6];
    goto v_21997;
v_21998:
    goto v_21994;
v_21995:
    goto v_21996;
v_21997:
    fn = elt(env, 4); // listsub
    v_22105 = (*qfn2(fn))(fn, stack[0], v_22105);
    env = stack[-6];
    v_22105 = qcdr(v_22105);
    stack[-5] = v_22105;
    goto v_22021;
v_22017:
    v_22106 = stack[-2];
    goto v_22018;
v_22019:
    v_22105 = stack[-4];
    goto v_22020;
v_22021:
    goto v_22017;
v_22018:
    goto v_22019;
v_22020:
    v_22106 = Lassoc(nil, v_22106, v_22105);
    v_22105 = v_22106;
    if (v_22106 == nil) goto v_22015;
    else goto v_22016;
v_22015:
    goto v_22029;
v_22025:
    goto v_22035;
v_22031:
    v_22106 = stack[-2];
    goto v_22032;
v_22033:
    v_22105 = stack[-1];
    goto v_22034;
v_22035:
    goto v_22031;
v_22032:
    goto v_22033;
v_22034:
    v_22106 = cons(v_22106, v_22105);
    env = stack[-6];
    goto v_22026;
v_22027:
    v_22105 = stack[-4];
    goto v_22028;
v_22029:
    goto v_22025;
v_22026:
    goto v_22027;
v_22028:
    v_22106 = Lassoc(nil, v_22106, v_22105);
    v_22105 = v_22106;
    v_22106 = (v_22106 == nil ? lisp_true : nil);
    goto v_22014;
v_22016:
    v_22106 = nil;
    goto v_22014;
    v_22106 = nil;
v_22014:
    if (v_22106 == nil) goto v_22012;
    goto v_22051;
v_22045:
    stack[0] = elt(env, 3); // dfp
    goto v_22046;
v_22047:
    goto v_22058;
v_22054:
    v_22106 = stack[-2];
    goto v_22055;
v_22056:
    v_22105 = stack[-5];
    goto v_22057;
v_22058:
    goto v_22054;
v_22055:
    goto v_22056;
v_22057:
    v_22106 = cons(v_22106, v_22105);
    goto v_22048;
v_22049:
    v_22105 = stack[-3];
    v_22105 = qcdr(v_22105);
    v_22105 = qcdr(v_22105);
    v_22105 = qcar(v_22105);
    goto v_22050;
v_22051:
    goto v_22045;
v_22046:
    goto v_22047;
v_22048:
    goto v_22049;
v_22050:
    {
        LispObject v_22114 = stack[0];
        return list3(v_22114, v_22106, v_22105);
    }
v_22012:
    v_22105 = qcdr(v_22105);
    fn = elt(env, 5); // reval
    v_22105 = (*qfn1(fn))(fn, v_22105);
    env = stack[-6];
    goto v_22075;
v_22069:
    stack[0] = v_22105;
    goto v_22070;
v_22071:
    v_22105 = stack[-5];
    if (v_22105 == nil) goto v_22080;
    goto v_22087;
v_22083:
    v_22106 = stack[-1];
    goto v_22084;
v_22085:
    v_22105 = stack[-5];
    goto v_22086;
v_22087:
    goto v_22083;
v_22084:
    goto v_22085;
v_22086:
    fn = elt(env, 6); // pair
    v_22105 = (*qfn2(fn))(fn, v_22106, v_22105);
    env = stack[-6];
    v_22106 = v_22105;
    goto v_22078;
v_22080:
    v_22106 = nil;
v_22078:
    goto v_22072;
v_22073:
    v_22105 = stack[-4];
    goto v_22074;
v_22075:
    goto v_22069;
v_22070:
    goto v_22071;
v_22072:
    goto v_22073;
v_22074:
    fn = elt(env, 7); // dfp!-sub1
    v_22105 = (*qfnn(fn))(fn, 3, stack[0], v_22106, v_22105);
    env = stack[-6];
    goto v_22098;
v_22092:
    v_22107 = elt(env, 3); // dfp
    goto v_22093;
v_22094:
    v_22106 = v_22105;
    goto v_22095;
v_22096:
    v_22105 = stack[-3];
    v_22105 = qcdr(v_22105);
    v_22105 = qcdr(v_22105);
    v_22105 = qcar(v_22105);
    goto v_22097;
v_22098:
    goto v_22092;
v_22093:
    goto v_22094;
v_22095:
    goto v_22096;
v_22097:
    return list3(v_22107, v_22106, v_22105);
    return onevalue(v_22105);
}



// Code for lf!=zero

static LispObject CC_lfMzero(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_21932;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21932 = v_21927;
// end of prologue
    v_21932 = qcdr(v_21932);
    v_21932 = (v_21932 == nil ? lisp_true : nil);
    return onevalue(v_21932);
}



// Code for setqinsertlist

static LispObject CC_setqinsertlist(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_22074, v_22075, v_22076;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21927);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_22075 = v_21927;
// end of prologue
    v_22074 = qvalue(elt(env, 1)); // fluidbibasissetq
    stack[-2] = v_22074;
    v_22074 = v_22075;
    stack[-1] = v_22074;
v_21939:
    v_22074 = stack[-2];
    v_22074 = qcar(v_22074);
    if (v_22074 == nil) goto v_21942;
    v_22074 = stack[-1];
    v_22074 = qcar(v_22074);
    if (v_22074 == nil) goto v_21942;
    goto v_21943;
v_21942:
    goto v_21938;
v_21943:
    goto v_21956;
v_21952:
    goto v_21961;
v_21957:
    v_22074 = stack[-2];
    v_22075 = qcar(v_22074);
    goto v_21958;
v_21959:
    v_22074 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21960;
v_21961:
    goto v_21957;
v_21958:
    goto v_21959;
v_21960:
    v_22074 = *(LispObject *)((char *)v_22075 + (CELL-TAG_VECTOR) + (((intptr_t)v_22074-TAG_FIXNUM)/(16/CELL)));
    v_22076 = qcar(v_22074);
    goto v_21953;
v_21954:
    goto v_21971;
v_21967:
    v_22074 = stack[-1];
    v_22075 = qcar(v_22074);
    goto v_21968;
v_21969:
    v_22074 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21970;
v_21971:
    goto v_21967;
v_21968:
    goto v_21969;
v_21970:
    v_22074 = *(LispObject *)((char *)v_22075 + (CELL-TAG_VECTOR) + (((intptr_t)v_22074-TAG_FIXNUM)/(16/CELL)));
    v_22074 = qcar(v_22074);
    goto v_21955;
v_21956:
    goto v_21952;
v_21953:
    goto v_21954;
v_21955:
    fn = elt(env, 2); // monomcompare
    v_22074 = (*qfn2(fn))(fn, v_22076, v_22074);
    env = stack[-3];
    v_22076 = v_22074;
    goto v_21989;
v_21985:
    v_22075 = v_22076;
    goto v_21986;
v_21987:
    v_22074 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_21988;
v_21989:
    goto v_21985;
v_21986:
    goto v_21987;
v_21988:
    if (v_22075 == v_22074) goto v_21983;
    else goto v_21984;
v_21983:
    v_22074 = lisp_true;
    goto v_21982;
v_21984:
    goto v_21999;
v_21995:
    v_22075 = v_22076;
    goto v_21996;
v_21997:
    v_22074 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21998;
v_21999:
    goto v_21995;
v_21996:
    goto v_21997;
v_21998:
    v_22074 = (v_22075 == v_22074 ? lisp_true : nil);
    goto v_21982;
    v_22074 = nil;
v_21982:
    if (v_22074 == nil) goto v_21980;
    v_22074 = stack[-2];
    v_22074 = qcdr(v_22074);
    stack[-2] = v_22074;
    goto v_21978;
v_21980:
    goto v_22013;
v_22009:
    goto v_22019;
v_22015:
    stack[0] = stack[-2];
    goto v_22016;
v_22017:
    goto v_22026;
v_22022:
    v_22074 = stack[-2];
    v_22075 = qcar(v_22074);
    goto v_22023;
v_22024:
    v_22074 = stack[-2];
    v_22074 = qcdr(v_22074);
    goto v_22025;
v_22026:
    goto v_22022;
v_22023:
    goto v_22024;
v_22025:
    v_22074 = cons(v_22075, v_22074);
    env = stack[-3];
    goto v_22018;
v_22019:
    goto v_22015;
v_22016:
    goto v_22017;
v_22018:
    v_22075 = Lrplacd(nil, stack[0], v_22074);
    env = stack[-3];
    goto v_22010;
v_22011:
    v_22074 = stack[-1];
    v_22074 = qcar(v_22074);
    goto v_22012;
v_22013:
    goto v_22009;
v_22010:
    goto v_22011;
v_22012:
    v_22074 = Lrplaca(nil, v_22075, v_22074);
    env = stack[-3];
    v_22074 = stack[-2];
    v_22074 = qcdr(v_22074);
    stack[-2] = v_22074;
    v_22074 = stack[-1];
    v_22074 = qcdr(v_22074);
    stack[-1] = v_22074;
    goto v_21978;
v_21978:
    goto v_21939;
v_21938:
    v_22074 = stack[-1];
    v_22074 = qcar(v_22074);
    if (v_22074 == nil) goto v_22042;
    goto v_22050;
v_22046:
    v_22075 = stack[-2];
    goto v_22047;
v_22048:
    v_22074 = stack[-1];
    goto v_22049;
v_22050:
    goto v_22046;
v_22047:
    goto v_22048;
v_22049:
    v_22074 = Lrplacd(nil, v_22075, v_22074);
    env = stack[-3];
    stack[0] = v_22074;
    goto v_22059;
v_22055:
    goto v_22065;
v_22061:
    v_22075 = stack[0];
    goto v_22062;
v_22063:
    v_22074 = stack[0];
    v_22074 = qcdr(v_22074);
    v_22074 = qcar(v_22074);
    goto v_22064;
v_22065:
    goto v_22061;
v_22062:
    goto v_22063;
v_22064:
    v_22075 = Lrplaca(nil, v_22075, v_22074);
    env = stack[-3];
    goto v_22056;
v_22057:
    v_22074 = stack[0];
    v_22074 = qcdr(v_22074);
    v_22074 = qcdr(v_22074);
    goto v_22058;
v_22059:
    goto v_22055;
v_22056:
    goto v_22057;
v_22058:
    v_22074 = Lrplacd(nil, v_22075, v_22074);
    goto v_22040;
v_22042:
v_22040:
    v_22074 = nil;
    return onevalue(v_22074);
}



// Code for pickbasicset

static LispObject CC_pickbasicset(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_22045, v_22046;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21927);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_21927;
// end of prologue
    stack[-3] = nil;
    v_22045 = qvalue(elt(env, 1)); // wuvarlist!*
    stack[-1] = v_22045;
v_21935:
    v_22045 = stack[-1];
    if (v_22045 == nil) goto v_21939;
    else goto v_21940;
v_21939:
    goto v_21934;
v_21940:
    v_22045 = stack[-1];
    v_22045 = qcar(v_22045);
    stack[0] = v_22045;
v_21948:
    v_22045 = stack[-2];
    if (v_22045 == nil) goto v_21951;
    goto v_21961;
v_21957:
    v_22045 = stack[-2];
    v_22045 = qcar(v_22045);
    v_22045 = qcar(v_22045);
    v_22045 = qcar(v_22045);
    v_22046 = qcar(v_22045);
    goto v_21958;
v_21959:
    v_22045 = stack[0];
    goto v_21960;
v_21961:
    goto v_21957;
v_21958:
    goto v_21959;
v_21960:
    fn = elt(env, 2); // symbollessp
    v_22045 = (*qfn2(fn))(fn, v_22046, v_22045);
    env = stack[-4];
    if (v_22045 == nil) goto v_21951;
    goto v_21952;
v_21951:
    goto v_21947;
v_21952:
    v_22045 = stack[-2];
    v_22045 = qcdr(v_22045);
    stack[-2] = v_22045;
    goto v_21948;
v_21947:
v_21973:
    v_22045 = stack[-2];
    if (v_22045 == nil) goto v_21976;
    goto v_21989;
v_21985:
    v_22046 = stack[0];
    goto v_21986;
v_21987:
    v_22045 = stack[-2];
    v_22045 = qcar(v_22045);
    v_22045 = qcar(v_22045);
    v_22045 = qcar(v_22045);
    v_22045 = qcar(v_22045);
    goto v_21988;
v_21989:
    goto v_21985;
v_21986:
    goto v_21987;
v_21988:
    if (equal(v_22046, v_22045)) goto v_21983;
    else goto v_21984;
v_21983:
    goto v_22001;
v_21997:
    v_22045 = stack[-2];
    v_22046 = qcar(v_22045);
    goto v_21998;
v_21999:
    v_22045 = stack[-3];
    goto v_22000;
v_22001:
    goto v_21997;
v_21998:
    goto v_21999;
v_22000:
    fn = elt(env, 3); // wureducedpolysp
    v_22045 = (*qfn2(fn))(fn, v_22046, v_22045);
    env = stack[-4];
    v_22045 = (v_22045 == nil ? lisp_true : nil);
    goto v_21982;
v_21984:
    v_22045 = nil;
    goto v_21982;
    v_22045 = nil;
v_21982:
    if (v_22045 == nil) goto v_21976;
    goto v_21977;
v_21976:
    goto v_21972;
v_21977:
    v_22045 = stack[-2];
    v_22045 = qcdr(v_22045);
    stack[-2] = v_22045;
    goto v_21973;
v_21972:
    v_22045 = stack[-2];
    if (v_22045 == nil) goto v_22015;
    goto v_22023;
v_22019:
    v_22046 = stack[0];
    goto v_22020;
v_22021:
    v_22045 = stack[-2];
    v_22045 = qcar(v_22045);
    v_22045 = qcar(v_22045);
    v_22045 = qcar(v_22045);
    v_22045 = qcar(v_22045);
    goto v_22022;
v_22023:
    goto v_22019;
v_22020:
    goto v_22021;
v_22022:
    if (equal(v_22046, v_22045)) goto v_22018;
    else goto v_22015;
v_22018:
    goto v_22035;
v_22031:
    v_22045 = stack[-2];
    v_22046 = qcar(v_22045);
    goto v_22032;
v_22033:
    v_22045 = stack[-3];
    goto v_22034;
v_22035:
    goto v_22031;
v_22032:
    goto v_22033;
v_22034:
    v_22045 = cons(v_22046, v_22045);
    env = stack[-4];
    stack[-3] = v_22045;
    v_22045 = stack[-2];
    v_22045 = qcdr(v_22045);
    stack[-2] = v_22045;
    goto v_22013;
v_22015:
v_22013:
    v_22045 = stack[-1];
    v_22045 = qcdr(v_22045);
    stack[-1] = v_22045;
    goto v_21935;
v_21934:
    v_22045 = stack[-3];
        return Lnreverse(nil, v_22045);
    return onevalue(v_22045);
}



// Code for ofsf_optsplitterm

static LispObject CC_ofsf_optsplitterm(LispObject env,
                         LispObject v_21927, LispObject v_21928)
{
    env = qenv(env);
    LispObject v_22010, v_22011, v_22012;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21928,v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21927,v_21928);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_21928;
    stack[-3] = v_21927;
// end of prologue
    goto v_21938;
v_21934:
    v_22011 = stack[-3];
    goto v_21935;
v_21936:
    v_22010 = stack[0];
    goto v_21937;
v_21938:
    goto v_21934;
v_21935:
    goto v_21936;
v_21937:
    fn = elt(env, 4); // sfto_reorder
    v_22010 = (*qfn2(fn))(fn, v_22011, v_22010);
    env = stack[-5];
    stack[-3] = v_22010;
    goto v_21949;
v_21945:
    goto v_21955;
v_21951:
    v_22011 = stack[-3];
    goto v_21952;
v_21953:
    v_22010 = stack[0];
    goto v_21954;
v_21955:
    goto v_21951;
v_21952:
    goto v_21953;
v_21954:
    fn = elt(env, 5); // degr
    v_22011 = (*qfn2(fn))(fn, v_22011, v_22010);
    env = stack[-5];
    stack[-4] = v_22011;
    goto v_21946;
v_21947:
    v_22010 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21948;
v_21949:
    goto v_21945;
v_21946:
    goto v_21947;
v_21948:
    if (v_22011 == v_22010) goto v_21943;
    else goto v_21944;
v_21943:
    v_22010 = nil;
    goto v_21932;
v_21944:
    goto v_21969;
v_21965:
    v_22011 = stack[-4];
    goto v_21966;
v_21967:
    v_22010 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21968;
v_21969:
    goto v_21965;
v_21966:
    goto v_21967;
v_21968:
    v_22010 = (LispObject)greaterp2(v_22011, v_22010);
    v_22010 = v_22010 ? lisp_true : nil;
    env = stack[-5];
    if (v_22010 == nil) goto v_21963;
    goto v_21982;
v_21974:
    stack[-2] = elt(env, 1); // "ofsf_optsplitterm:"
    goto v_21975;
v_21976:
    stack[-1] = stack[0];
    goto v_21977;
v_21978:
    stack[0] = elt(env, 2); // "has degree"
    goto v_21979;
v_21980:
    goto v_21993;
v_21987:
    v_22012 = stack[-4];
    goto v_21988;
v_21989:
    v_22011 = elt(env, 3); // "in"
    goto v_21990;
v_21991:
    v_22010 = stack[-3];
    goto v_21992;
v_21993:
    goto v_21987;
v_21988:
    goto v_21989;
v_21990:
    goto v_21991;
v_21992:
    v_22010 = list3(v_22012, v_22011, v_22010);
    env = stack[-5];
    goto v_21981;
v_21982:
    goto v_21974;
v_21975:
    goto v_21976;
v_21977:
    goto v_21978;
v_21979:
    goto v_21980;
v_21981:
    v_22010 = list3star(stack[-2], stack[-1], stack[0], v_22010);
    env = stack[-5];
    fn = elt(env, 6); // rederr
    v_22010 = (*qfn1(fn))(fn, v_22010);
    env = stack[-5];
    goto v_21961;
v_21963:
v_21961:
    goto v_22002;
v_21998:
    v_22010 = stack[-3];
    v_22010 = qcar(v_22010);
    v_22010 = qcdr(v_22010);
    fn = elt(env, 7); // reorder
    stack[0] = (*qfn1(fn))(fn, v_22010);
    env = stack[-5];
    goto v_21999;
v_22000:
    v_22010 = stack[-3];
    v_22010 = qcdr(v_22010);
    fn = elt(env, 7); // reorder
    v_22010 = (*qfn1(fn))(fn, v_22010);
    goto v_22001;
v_22002:
    goto v_21998;
v_21999:
    goto v_22000;
v_22001:
    {
        LispObject v_22018 = stack[0];
        return cons(v_22018, v_22010);
    }
v_21932:
    return onevalue(v_22010);
}



// Code for determinantrd

static LispObject CC_determinantrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21935;
    LispObject fn;
    argcheck(nargs, 0, "determinantrd");
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
    v_21935 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_21935;
    fn = elt(env, 2); // lex
    v_21935 = (*qfnn(fn))(fn, 0);
    v_21935 = stack[0];
    return ncons(v_21935);
    return onevalue(v_21935);
}



// Code for transmat1

static LispObject CC_transmat1(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_22104, v_22105, v_22106, v_22107;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21927);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_21927;
// end of prologue
    v_22104 = stack[-6];
    v_22104 = qcar(v_22104);
    fn = elt(env, 5); // aeval
    v_22104 = (*qfn1(fn))(fn, v_22104);
    env = stack[-8];
    v_22104 = qcdr(v_22104);
    stack[0] = v_22104;
    v_22104 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_22104;
    v_22104 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_22104;
    v_22104 = stack[-6];
    v_22104 = qcar(v_22104);
    fn = elt(env, 5); // aeval
    v_22104 = (*qfn1(fn))(fn, v_22104);
    env = stack[-8];
    fn = elt(env, 6); // matlength
    v_22104 = (*qfn1(fn))(fn, v_22104);
    env = stack[-8];
    v_22104 = qcdr(v_22104);
    goto v_21955;
v_21951:
    v_22105 = v_22104;
    stack[-1] = qcar(v_22105);
    goto v_21952;
v_21953:
    goto v_21963;
v_21959:
    v_22105 = elt(env, 1); // spm
    goto v_21960;
v_21961:
    goto v_21962;
v_21963:
    goto v_21959;
v_21960:
    goto v_21961;
v_21962:
    v_22104 = cons(v_22105, v_22104);
    env = stack[-8];
    goto v_21954;
v_21955:
    goto v_21951;
v_21952:
    goto v_21953;
v_21954:
    fn = elt(env, 7); // mkempspmat
    v_22104 = (*qfn2(fn))(fn, stack[-1], v_22104);
    env = stack[-8];
    stack[-7] = v_22104;
    v_22104 = nil;
    v_22104 = ncons(v_22104);
    env = stack[-8];
    v_22104 = ncons(v_22104);
    env = stack[-8];
    stack[-2] = v_22104;
    v_22104 = stack[0];
    stack[-1] = v_22104;
v_21972:
    v_22104 = stack[-1];
    if (v_22104 == nil) goto v_21976;
    else goto v_21977;
v_21976:
    goto v_21971;
v_21977:
    v_22104 = stack[-1];
    v_22104 = qcar(v_22104);
    stack[0] = v_22104;
    v_22104 = stack[-5];
    v_22104 = add1(v_22104);
    env = stack[-8];
    stack[-5] = v_22104;
    v_22104 = stack[0];
    stack[0] = v_22104;
v_21989:
    v_22104 = stack[0];
    if (v_22104 == nil) goto v_21993;
    else goto v_21994;
v_21993:
    goto v_21988;
v_21994:
    v_22104 = stack[0];
    v_22104 = qcar(v_22104);
    stack[-3] = v_22104;
    v_22104 = stack[-4];
    v_22104 = add1(v_22104);
    env = stack[-8];
    stack[-4] = v_22104;
    goto v_22011;
v_22007:
    v_22105 = stack[-3];
    goto v_22008;
v_22009:
    v_22104 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22010;
v_22011:
    goto v_22007;
v_22008:
    goto v_22009;
v_22010:
    if (v_22105 == v_22104) goto v_22005;
    else goto v_22006;
v_22005:
    goto v_22004;
v_22006:
    goto v_22024;
v_22018:
    v_22106 = stack[-4];
    goto v_22019;
v_22020:
    v_22105 = stack[-3];
    goto v_22021;
v_22022:
    v_22104 = stack[-2];
    goto v_22023;
v_22024:
    goto v_22018;
v_22019:
    goto v_22020;
v_22021:
    goto v_22022;
v_22023:
    v_22104 = acons(v_22106, v_22105, v_22104);
    env = stack[-8];
    stack[-2] = v_22104;
    goto v_22004;
v_22004:
    v_22104 = stack[0];
    v_22104 = qcdr(v_22104);
    stack[0] = v_22104;
    goto v_21989;
v_21988:
    v_22104 = stack[-2];
    v_22104 = Lreverse(nil, v_22104);
    env = stack[-8];
    stack[-2] = v_22104;
    goto v_22040;
v_22036:
    stack[0] = stack[-2];
    goto v_22037;
v_22038:
    v_22104 = nil;
    v_22104 = ncons(v_22104);
    env = stack[-8];
    v_22104 = ncons(v_22104);
    env = stack[-8];
    goto v_22039;
v_22040:
    goto v_22036;
v_22037:
    goto v_22038;
v_22039:
    if (equal(stack[0], v_22104)) goto v_22035;
    goto v_22054;
v_22046:
    goto v_22060;
v_22056:
    v_22105 = stack[-7];
    goto v_22057;
v_22058:
    v_22104 = stack[-5];
    goto v_22059;
v_22060:
    goto v_22056;
v_22057:
    goto v_22058;
v_22059:
    v_22107 = list2(v_22105, v_22104);
    env = stack[-8];
    goto v_22047;
v_22048:
    v_22106 = stack[-2];
    goto v_22049;
v_22050:
    v_22105 = stack[-7];
    goto v_22051;
v_22052:
    v_22104 = nil;
    goto v_22053;
v_22054:
    goto v_22046;
v_22047:
    goto v_22048;
v_22049:
    goto v_22050;
v_22051:
    goto v_22052;
v_22053:
    fn = elt(env, 8); // letmtr3
    v_22104 = (*qfnn(fn))(fn, 4, v_22107, v_22106, v_22105, v_22104);
    env = stack[-8];
    goto v_22033;
v_22035:
v_22033:
    v_22104 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_22104;
    v_22104 = nil;
    v_22104 = ncons(v_22104);
    env = stack[-8];
    v_22104 = ncons(v_22104);
    env = stack[-8];
    stack[-2] = v_22104;
    v_22104 = stack[-1];
    v_22104 = qcdr(v_22104);
    stack[-1] = v_22104;
    goto v_21972;
v_21971:
    goto v_22080;
v_22074:
    v_22104 = stack[-6];
    stack[-1] = qcar(v_22104);
    goto v_22075;
v_22076:
    stack[0] = elt(env, 2); // avalue
    goto v_22077;
v_22078:
    goto v_22089;
v_22085:
    v_22105 = elt(env, 3); // sparse
    goto v_22086;
v_22087:
    v_22104 = stack[-7];
    goto v_22088;
v_22089:
    goto v_22085;
v_22086:
    goto v_22087;
v_22088:
    v_22104 = list2(v_22105, v_22104);
    env = stack[-8];
    goto v_22079;
v_22080:
    goto v_22074;
v_22075:
    goto v_22076;
v_22077:
    goto v_22078;
v_22079:
    v_22104 = Lputprop(nil, 3, stack[-1], stack[0], v_22104);
    env = stack[-8];
    goto v_22099;
v_22093:
    v_22104 = stack[-6];
    v_22106 = qcar(v_22104);
    goto v_22094;
v_22095:
    v_22105 = elt(env, 4); // rtype
    goto v_22096;
v_22097:
    v_22104 = elt(env, 3); // sparse
    goto v_22098;
v_22099:
    goto v_22093;
v_22094:
    goto v_22095;
v_22096:
    goto v_22097;
v_22098:
    v_22104 = Lputprop(nil, 3, v_22106, v_22105, v_22104);
    v_22104 = nil;
    return onevalue(v_22104);
}



// Code for remzzzz

static LispObject CC_remzzzz(LispObject env,
                         LispObject v_21927, LispObject v_21928)
{
    env = qenv(env);
    LispObject v_21977, v_21978, v_21979;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21928,v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21927,v_21928);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21928;
    stack[-1] = v_21927;
// end of prologue
    v_21979 = nil;
v_21933:
    v_21977 = stack[-1];
    if (v_21977 == nil) goto v_21936;
    else goto v_21937;
v_21936:
    goto v_21944;
v_21940:
    v_21978 = v_21979;
    goto v_21941;
v_21942:
    v_21977 = stack[0];
    goto v_21943;
v_21944:
    goto v_21940;
v_21941:
    goto v_21942;
v_21943:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_21978, v_21977);
    }
v_21937:
    goto v_21953;
v_21949:
    v_21977 = stack[-1];
    v_21977 = qcar(v_21977);
    v_21978 = qcar(v_21977);
    goto v_21950;
v_21951:
    v_21977 = stack[0];
    v_21977 = qcar(v_21977);
    v_21977 = qcar(v_21977);
    goto v_21952;
v_21953:
    goto v_21949;
v_21950:
    goto v_21951;
v_21952:
    if (equal(v_21978, v_21977)) goto v_21947;
    else goto v_21948;
v_21947:
    v_21977 = stack[-1];
    v_21977 = qcdr(v_21977);
    stack[-1] = v_21977;
    v_21977 = stack[0];
    v_21977 = qcdr(v_21977);
    stack[0] = v_21977;
    goto v_21933;
v_21948:
    goto v_21971;
v_21967:
    v_21977 = stack[0];
    v_21977 = qcar(v_21977);
    goto v_21968;
v_21969:
    v_21978 = v_21979;
    goto v_21970;
v_21971:
    goto v_21967;
v_21968:
    goto v_21969;
v_21970:
    v_21977 = cons(v_21977, v_21978);
    env = stack[-2];
    v_21979 = v_21977;
    v_21977 = stack[0];
    v_21977 = qcdr(v_21977);
    stack[0] = v_21977;
    goto v_21933;
    v_21977 = nil;
    return onevalue(v_21977);
}



// Code for diplmon2sq

static LispObject CC_diplmon2sq(LispObject env,
                         LispObject v_21927, LispObject v_21928)
{
    env = qenv(env);
    LispObject v_21952, v_21953;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21928,v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21927,v_21928);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21952 = v_21928;
    v_21953 = v_21927;
// end of prologue
    goto v_21935;
v_21931:
    stack[0] = v_21953;
    goto v_21932;
v_21933:
    goto v_21942;
v_21938:
    goto v_21948;
v_21944:
    v_21953 = v_21952;
    goto v_21945;
v_21946:
    v_21952 = qvalue(elt(env, 1)); // dipvars!*
    goto v_21947;
v_21948:
    goto v_21944;
v_21945:
    goto v_21946;
v_21947:
    fn = elt(env, 2); // dipev2f
    v_21953 = (*qfn2(fn))(fn, v_21953, v_21952);
    env = stack[-1];
    goto v_21939;
v_21940:
    v_21952 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21941;
v_21942:
    goto v_21938;
v_21939:
    goto v_21940;
v_21941:
    v_21952 = cons(v_21953, v_21952);
    env = stack[-1];
    goto v_21934;
v_21935:
    goto v_21931;
v_21932:
    goto v_21933;
v_21934:
    {
        LispObject v_21955 = stack[0];
        fn = elt(env, 3); // multsq
        return (*qfn2(fn))(fn, v_21955, v_21952);
    }
}



// Code for sc_rowscalarproduct

static LispObject CC_sc_rowscalarproduct(LispObject env,
                         LispObject v_21927, LispObject v_21928)
{
    env = qenv(env);
    LispObject v_21993, v_21994, v_21995;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21928,v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21927,v_21928);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_21928;
    stack[-3] = v_21927;
// end of prologue
    v_21993 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 1); // sc_simp
    v_21993 = (*qfn1(fn))(fn, v_21993);
    env = stack[-5];
    stack[0] = v_21993;
    v_21993 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_21993;
v_21938:
    goto v_21950;
v_21946:
    v_21993 = stack[-3];
    fn = elt(env, 2); // fast!-column!-dim
    v_21994 = (*qfn1(fn))(fn, v_21993);
    env = stack[-5];
    goto v_21947;
v_21948:
    v_21993 = stack[-4];
    goto v_21949;
v_21950:
    goto v_21946;
v_21947:
    goto v_21948;
v_21949:
    v_21993 = difference2(v_21994, v_21993);
    env = stack[-5];
    v_21993 = Lminusp(nil, v_21993);
    env = stack[-5];
    if (v_21993 == nil) goto v_21943;
    goto v_21937;
v_21943:
    goto v_21960;
v_21956:
    stack[-1] = stack[0];
    goto v_21957;
v_21958:
    goto v_21967;
v_21963:
    goto v_21975;
v_21969:
    v_21995 = stack[-3];
    goto v_21970;
v_21971:
    v_21994 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21972;
v_21973:
    v_21993 = stack[-4];
    goto v_21974;
v_21975:
    goto v_21969;
v_21970:
    goto v_21971;
v_21972:
    goto v_21973;
v_21974:
    fn = elt(env, 3); // sc_getmat
    stack[0] = (*qfnn(fn))(fn, 3, v_21995, v_21994, v_21993);
    env = stack[-5];
    goto v_21964;
v_21965:
    goto v_21986;
v_21980:
    v_21995 = stack[-2];
    goto v_21981;
v_21982:
    v_21994 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21983;
v_21984:
    v_21993 = stack[-4];
    goto v_21985;
v_21986:
    goto v_21980;
v_21981:
    goto v_21982;
v_21983:
    goto v_21984;
v_21985:
    fn = elt(env, 3); // sc_getmat
    v_21993 = (*qfnn(fn))(fn, 3, v_21995, v_21994, v_21993);
    env = stack[-5];
    goto v_21966;
v_21967:
    goto v_21963;
v_21964:
    goto v_21965;
v_21966:
    fn = elt(env, 4); // sc_multsq
    v_21993 = (*qfn2(fn))(fn, stack[0], v_21993);
    env = stack[-5];
    goto v_21959;
v_21960:
    goto v_21956;
v_21957:
    goto v_21958;
v_21959:
    fn = elt(env, 5); // sc_addsq
    v_21993 = (*qfn2(fn))(fn, stack[-1], v_21993);
    env = stack[-5];
    stack[0] = v_21993;
    v_21993 = stack[-4];
    v_21993 = add1(v_21993);
    env = stack[-5];
    stack[-4] = v_21993;
    goto v_21938;
v_21937:
    v_21993 = stack[0];
    return onevalue(v_21993);
}



// Code for xnsiz

static LispObject CC_xnsiz(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_21939, v_21940;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21927);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21939 = v_21927;
// end of prologue
    goto v_21935;
v_21931:
    fn = elt(env, 2); // xnsiz1
    v_21940 = (*qfn1(fn))(fn, v_21939);
    env = stack[0];
    goto v_21932;
v_21933:
    v_21939 = qvalue(elt(env, 1)); // !!log2of10
    goto v_21934;
v_21935:
    goto v_21931;
v_21932:
    goto v_21933;
v_21934:
    v_21939 = quot2(v_21940, v_21939);
    env = stack[0];
    {
        fn = elt(env, 3); // ceiling
        return (*qfn1(fn))(fn, v_21939);
    }
}



// Code for rd!:difference

static LispObject CC_rdTdifference(LispObject env,
                         LispObject v_21927, LispObject v_21928)
{
    env = qenv(env);
    LispObject v_22129, v_22130, v_22131;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21928,v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21927,v_21928);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_21928;
    stack[-2] = v_21927;
// end of prologue
    v_22129 = nil;
    stack[-3] = v_22129;
    v_22129 = qvalue(elt(env, 1)); // !*!*roundbf
    if (v_22129 == nil) goto v_21938;
    else goto v_21939;
v_21938:
    v_22129 = stack[-2];
    v_22129 = qcdr(v_22129);
    if (!consp(v_22129)) goto v_21943;
    else goto v_21944;
v_21943:
    v_22129 = stack[0];
    v_22129 = qcdr(v_22129);
    if (!consp(v_22129)) goto v_21949;
    else goto v_21950;
v_21949:
    goto v_21958;
v_21954:
    v_22129 = stack[-2];
    stack[-1] = qcdr(v_22129);
    goto v_21955;
v_21956:
    v_22129 = stack[0];
    v_22129 = qcdr(v_22129);
    fn = elt(env, 4); // safe!-fp!-minus
    v_22129 = (*qfn1(fn))(fn, v_22129);
    env = stack[-4];
    goto v_21957;
v_21958:
    goto v_21954;
v_21955:
    goto v_21956;
v_21957:
    fn = elt(env, 5); // safe!-fp!-plus
    v_22129 = (*qfn2(fn))(fn, stack[-1], v_22129);
    env = stack[-4];
    stack[-3] = v_22129;
    goto v_21948;
v_21950:
    v_22129 = nil;
    goto v_21948;
    v_22129 = nil;
v_21948:
    goto v_21942;
v_21944:
    v_22129 = nil;
    goto v_21942;
    v_22129 = nil;
v_21942:
    goto v_21937;
v_21939:
    v_22129 = nil;
    goto v_21937;
    v_22129 = nil;
v_21937:
    if (v_22129 == nil) goto v_21935;
    goto v_21978;
v_21974:
    v_22130 = elt(env, 2); // !:rd!:
    goto v_21975;
v_21976:
    v_22129 = stack[-3];
    goto v_21977;
v_21978:
    goto v_21974;
v_21975:
    goto v_21976;
v_21977:
    return cons(v_22130, v_22129);
v_21935:
    goto v_21992;
v_21988:
    v_22130 = stack[-2];
    goto v_21989;
v_21990:
    v_22129 = stack[0];
    goto v_21991;
v_21992:
    goto v_21988;
v_21989:
    goto v_21990;
v_21991:
    fn = elt(env, 6); // convprc2
    v_22129 = (*qfn2(fn))(fn, v_22130, v_22129);
    env = stack[-4];
    stack[-1] = v_22129;
    v_22129 = qvalue(elt(env, 3)); // yy!!
    stack[0] = v_22129;
    v_22129 = stack[-1];
    if (!consp(v_22129)) goto v_21999;
    goto v_22006;
v_22002:
    v_22130 = stack[-1];
    goto v_22003;
v_22004:
    v_22129 = stack[0];
    goto v_22005;
v_22006:
    goto v_22002;
v_22003:
    goto v_22004;
v_22005:
    fn = elt(env, 7); // difbf
    v_22129 = (*qfn2(fn))(fn, v_22130, v_22129);
    env = stack[-4];
    goto v_21997;
v_21999:
    goto v_22016;
v_22012:
    v_22130 = stack[-1];
    goto v_22013;
v_22014:
    v_22129 = stack[0];
    goto v_22015;
v_22016:
    goto v_22012;
v_22013:
    goto v_22014;
v_22015:
    v_22129 = difference2(v_22130, v_22129);
    env = stack[-4];
    stack[-3] = v_22129;
    v_22129 = stack[-3];
    fn = elt(env, 8); // fp!-infinite
    v_22129 = (*qfn1(fn))(fn, v_22129);
    env = stack[-4];
    if (v_22129 == nil) goto v_22022;
    fn = elt(env, 9); // rndbfon
    v_22129 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_22031;
v_22027:
    v_22129 = stack[-1];
    v_22129 = Lfloatp(nil, v_22129);
    env = stack[-4];
    if (v_22129 == nil) goto v_22035;
    v_22129 = stack[-1];
    fn = elt(env, 10); // fl2bf
    v_22129 = (*qfn1(fn))(fn, v_22129);
    env = stack[-4];
    stack[-2] = v_22129;
    goto v_22033;
v_22035:
    v_22129 = stack[-1];
    if (!consp(v_22129)) goto v_22046;
    v_22129 = stack[-1];
    goto v_22044;
v_22046:
    v_22129 = stack[-1];
    v_22129 = integerp(v_22129);
    if (v_22129 == nil) goto v_22050;
    goto v_22060;
v_22054:
    v_22131 = elt(env, 2); // !:rd!:
    goto v_22055;
v_22056:
    v_22130 = stack[-1];
    goto v_22057;
v_22058:
    v_22129 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22059;
v_22060:
    goto v_22054;
v_22055:
    goto v_22056;
v_22057:
    goto v_22058;
v_22059:
    v_22129 = list2star(v_22131, v_22130, v_22129);
    env = stack[-4];
    goto v_22044;
v_22050:
    v_22129 = stack[-1];
    fn = elt(env, 11); // read!:num
    v_22129 = (*qfn1(fn))(fn, v_22129);
    env = stack[-4];
    goto v_22044;
    v_22129 = nil;
v_22044:
    fn = elt(env, 12); // normbf
    v_22129 = (*qfn1(fn))(fn, v_22129);
    env = stack[-4];
    stack[-2] = v_22129;
    goto v_22033;
    stack[-2] = nil;
v_22033:
    stack[-1] = stack[-2];
    goto v_22028;
v_22029:
    v_22129 = stack[0];
    v_22129 = Lfloatp(nil, v_22129);
    env = stack[-4];
    if (v_22129 == nil) goto v_22071;
    v_22129 = stack[0];
    fn = elt(env, 10); // fl2bf
    v_22129 = (*qfn1(fn))(fn, v_22129);
    env = stack[-4];
    goto v_22069;
v_22071:
    v_22129 = stack[0];
    if (!consp(v_22129)) goto v_22082;
    v_22129 = stack[0];
    goto v_22080;
v_22082:
    v_22129 = stack[0];
    v_22129 = integerp(v_22129);
    if (v_22129 == nil) goto v_22086;
    goto v_22096;
v_22090:
    v_22131 = elt(env, 2); // !:rd!:
    goto v_22091;
v_22092:
    v_22130 = stack[0];
    goto v_22093;
v_22094:
    v_22129 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22095;
v_22096:
    goto v_22090;
v_22091:
    goto v_22092;
v_22093:
    goto v_22094;
v_22095:
    v_22129 = list2star(v_22131, v_22130, v_22129);
    env = stack[-4];
    goto v_22080;
v_22086:
    v_22129 = stack[0];
    fn = elt(env, 11); // read!:num
    v_22129 = (*qfn1(fn))(fn, v_22129);
    env = stack[-4];
    goto v_22080;
    v_22129 = nil;
v_22080:
    fn = elt(env, 12); // normbf
    v_22129 = (*qfn1(fn))(fn, v_22129);
    env = stack[-4];
    goto v_22069;
    v_22129 = nil;
v_22069:
    stack[0] = v_22129;
    goto v_22030;
v_22031:
    goto v_22027;
v_22028:
    goto v_22029;
v_22030:
    fn = elt(env, 7); // difbf
    v_22129 = (*qfn2(fn))(fn, stack[-2], v_22129);
    env = stack[-4];
    goto v_22020;
v_22022:
    v_22129 = stack[-3];
    goto v_22020;
    v_22129 = nil;
v_22020:
    goto v_21997;
    v_22129 = nil;
v_21997:
    stack[-2] = v_22129;
    goto v_22115;
v_22109:
    goto v_22110;
v_22111:
    goto v_22112;
v_22113:
    v_22129 = stack[0];
    if (!consp(v_22129)) goto v_22120;
    else goto v_22121;
v_22120:
    v_22129 = stack[0];
    v_22129 = negate(v_22129);
    env = stack[-4];
    goto v_22119;
v_22121:
    v_22129 = stack[0];
    fn = elt(env, 13); // minus!:
    v_22129 = (*qfn1(fn))(fn, v_22129);
    env = stack[-4];
    goto v_22119;
    v_22129 = nil;
v_22119:
    goto v_22114;
v_22115:
    goto v_22109;
v_22110:
    goto v_22111;
v_22112:
    goto v_22113;
v_22114:
    fn = elt(env, 14); // rdzchk
    v_22129 = (*qfnn(fn))(fn, 3, stack[-2], stack[-1], v_22129);
    env = stack[-4];
    {
        fn = elt(env, 15); // mkround
        return (*qfn1(fn))(fn, v_22129);
    }
    goto v_21933;
    v_22129 = nil;
v_21933:
    return onevalue(v_22129);
}



// Code for indxsymp

static LispObject CC_indxsymp(LispObject env,
                         LispObject v_21927, LispObject v_21928)
{
    env = qenv(env);
    LispObject v_21963, v_21964;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21928,v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21927,v_21928);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21928;
    stack[-1] = v_21927;
// end of prologue
v_21926:
    v_21963 = stack[0];
    if (v_21963 == nil) goto v_21932;
    else goto v_21933;
v_21932:
    v_21963 = lisp_true;
    goto v_21931;
v_21933:
    goto v_21947;
v_21943:
    v_21963 = stack[0];
    v_21964 = qcar(v_21963);
    goto v_21944;
v_21945:
    v_21963 = stack[-1];
    goto v_21946;
v_21947:
    goto v_21943;
v_21944:
    goto v_21945;
v_21946:
    v_21963 = Lapply1(nil, v_21964, v_21963);
    env = stack[-2];
    if (v_21963 == nil) goto v_21940;
    else goto v_21941;
v_21940:
    v_21963 = nil;
    goto v_21939;
v_21941:
    goto v_21959;
v_21955:
    v_21964 = stack[-1];
    goto v_21956;
v_21957:
    v_21963 = stack[0];
    v_21963 = qcdr(v_21963);
    goto v_21958;
v_21959:
    goto v_21955;
v_21956:
    goto v_21957;
v_21958:
    stack[-1] = v_21964;
    stack[0] = v_21963;
    goto v_21926;
    v_21963 = nil;
v_21939:
    goto v_21931;
    v_21963 = nil;
v_21931:
    return onevalue(v_21963);
}



// Code for calc_coeffmap_

static LispObject CC_calc_coeffmap_(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21972, v_21973, v_21974;
    LispObject fn;
    LispObject v_21929, v_21928, v_21927;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "calc_coeffmap_");
    va_start(aa, nargs);
    v_21927 = va_arg(aa, LispObject);
    v_21928 = va_arg(aa, LispObject);
    v_21929 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21929,v_21928,v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21927,v_21928,v_21929);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_21929;
    stack[-2] = v_21928;
    v_21972 = v_21927;
// end of prologue
    goto v_21936;
v_21932:
    v_21973 = v_21972;
    goto v_21933;
v_21934:
    v_21972 = stack[-1];
    goto v_21935;
v_21936:
    goto v_21932;
v_21933:
    goto v_21934;
v_21935:
    fn = elt(env, 2); // calc_map_
    v_21972 = (*qfn2(fn))(fn, v_21973, v_21972);
    env = stack[-4];
    v_21974 = v_21972;
    goto v_21948;
v_21944:
    v_21973 = v_21974;
    goto v_21945;
v_21946:
    v_21972 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21947;
v_21948:
    goto v_21944;
v_21945:
    goto v_21946;
v_21947:
    if (v_21973 == v_21972) goto v_21942;
    else goto v_21943;
v_21942:
    v_21972 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21941;
v_21943:
    goto v_21961;
v_21955:
    stack[-3] = elt(env, 1); // times
    goto v_21956;
v_21957:
    stack[0] = v_21974;
    goto v_21958;
v_21959:
    goto v_21969;
v_21965:
    v_21973 = stack[-2];
    goto v_21966;
v_21967:
    v_21972 = stack[-1];
    goto v_21968;
v_21969:
    goto v_21965;
v_21966:
    goto v_21967;
v_21968:
    fn = elt(env, 3); // calc_coeff
    v_21972 = (*qfn2(fn))(fn, v_21973, v_21972);
    goto v_21960;
v_21961:
    goto v_21955;
v_21956:
    goto v_21957;
v_21958:
    goto v_21959;
v_21960:
    {
        LispObject v_21979 = stack[-3];
        LispObject v_21980 = stack[0];
        return list2star(v_21979, v_21980, v_21972);
    }
    v_21972 = nil;
v_21941:
    return onevalue(v_21972);
}



// Code for lengthreval

static LispObject CC_lengthreval(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_22090, v_22091, v_22092;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21927);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_21927;
// end of prologue
    stack[0] = nil;
    goto v_21942;
v_21938:
    v_22090 = stack[-1];
    v_22091 = Llength(nil, v_22090);
    env = stack[-3];
    goto v_21939;
v_21940:
    v_22090 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21941;
v_21942:
    goto v_21938;
v_21939:
    goto v_21940;
v_21941:
    if (v_22091 == v_22090) goto v_21937;
    goto v_21953;
v_21947:
    v_22092 = elt(env, 1); // alg
    goto v_21948;
v_21949:
    v_22091 = (LispObject)176+TAG_FIXNUM; // 11
    goto v_21950;
v_21951:
    v_22090 = elt(env, 2); // "LENGTH called with wrong number of arguments"
    goto v_21952;
v_21953:
    goto v_21947;
v_21948:
    goto v_21949;
v_21950:
    goto v_21951;
v_21952:
    fn = elt(env, 9); // rerror
    v_22090 = (*qfnn(fn))(fn, 3, v_22092, v_22091, v_22090);
    env = stack[-3];
    goto v_21935;
v_21937:
v_21935:
    v_22090 = stack[-1];
    v_22090 = qcar(v_22090);
    stack[-1] = v_22090;
    v_22090 = stack[-1];
    if (symbolp(v_22090)) goto v_21963;
    else goto v_21962;
v_21963:
    v_22090 = stack[-1];
    fn = elt(env, 10); // arrayp
    v_22090 = (*qfn1(fn))(fn, v_22090);
    env = stack[-3];
    if (v_22090 == nil) goto v_21962;
    goto v_21973;
v_21969:
    v_22092 = elt(env, 3); // list
    goto v_21970;
v_21971:
    goto v_21980;
v_21976:
    v_22091 = stack[-1];
    goto v_21977;
v_21978:
    v_22090 = elt(env, 4); // dimension
    goto v_21979;
v_21980:
    goto v_21976;
v_21977:
    goto v_21978;
v_21979:
    v_22090 = get(v_22091, v_22090);
    goto v_21972;
v_21973:
    goto v_21969;
v_21970:
    goto v_21971;
v_21972:
    return cons(v_22092, v_22090);
v_21962:
    v_22090 = stack[-1];
    fn = elt(env, 11); // aeval
    v_22090 = (*qfn1(fn))(fn, v_22090);
    env = stack[-3];
    stack[-2] = v_22090;
    v_22090 = stack[-2];
    fn = elt(env, 12); // getrtype
    v_22090 = (*qfn1(fn))(fn, v_22090);
    env = stack[-3];
    v_22092 = v_22090;
    if (v_22090 == nil) goto v_21988;
    goto v_21998;
v_21994:
    v_22091 = v_22092;
    goto v_21995;
v_21996:
    v_22090 = elt(env, 5); // lengthfn
    goto v_21997;
v_21998:
    goto v_21994;
v_21995:
    goto v_21996;
v_21997:
    v_22090 = get(v_22091, v_22090);
    env = stack[-3];
    stack[0] = v_22090;
    if (v_22090 == nil) goto v_21988;
    goto v_22009;
v_22005:
    v_22090 = v_22092;
    goto v_22006;
v_22007:
    v_22091 = elt(env, 6); // sparse
    goto v_22008;
v_22009:
    goto v_22005;
v_22006:
    goto v_22007;
v_22008:
    if (v_22090 == v_22091) goto v_22003;
    else goto v_22004;
v_22003:
    goto v_22017;
v_22013:
    v_22091 = stack[0];
    goto v_22014;
v_22015:
    v_22090 = stack[-1];
    goto v_22016;
v_22017:
    goto v_22013;
v_22014:
    goto v_22015;
v_22016:
        return Lapply1(nil, v_22091, v_22090);
v_22004:
    goto v_22027;
v_22023:
    v_22091 = stack[0];
    goto v_22024;
v_22025:
    v_22090 = stack[-2];
    goto v_22026;
v_22027:
    goto v_22023;
v_22024:
    goto v_22025;
v_22026:
        return Lapply1(nil, v_22091, v_22090);
    goto v_21986;
v_21988:
    v_22090 = stack[-2];
    if (!consp(v_22090)) goto v_22030;
    else goto v_22031;
v_22030:
    v_22090 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21933;
v_22031:
    v_22090 = stack[-2];
    v_22090 = qcar(v_22090);
    if (symbolp(v_22090)) goto v_22039;
    v_22090 = lisp_true;
    goto v_22037;
v_22039:
    goto v_22050;
v_22046:
    v_22090 = stack[-2];
    v_22091 = qcar(v_22090);
    goto v_22047;
v_22048:
    v_22090 = elt(env, 5); // lengthfn
    goto v_22049;
v_22050:
    goto v_22046;
v_22047:
    goto v_22048;
v_22049:
    v_22090 = get(v_22091, v_22090);
    env = stack[-3];
    stack[0] = v_22090;
    v_22090 = (v_22090 == nil ? lisp_true : nil);
    goto v_22037;
    v_22090 = nil;
v_22037:
    if (v_22090 == nil) goto v_22035;
    v_22090 = v_22092;
    if (v_22090 == nil) goto v_22058;
    goto v_22066;
v_22062:
    v_22090 = elt(env, 7); // "LENGTH not defined for argument of type"
    goto v_22063;
v_22064:
    v_22091 = v_22092;
    goto v_22065;
v_22066:
    goto v_22062;
v_22063:
    goto v_22064;
v_22065:
    v_22090 = list2(v_22090, v_22091);
    env = stack[-3];
    fn = elt(env, 13); // lprie
    v_22090 = (*qfn1(fn))(fn, v_22090);
    goto v_22056;
v_22058:
    goto v_22076;
v_22072:
    v_22091 = stack[-1];
    goto v_22073;
v_22074:
    v_22090 = elt(env, 8); // "LENGTH argument"
    goto v_22075;
v_22076:
    goto v_22072;
v_22073:
    goto v_22074;
v_22075:
    fn = elt(env, 14); // typerr
    v_22090 = (*qfn2(fn))(fn, v_22091, v_22090);
    goto v_22056;
v_22056:
    goto v_21986;
v_22035:
    goto v_22086;
v_22082:
    v_22091 = stack[0];
    goto v_22083;
v_22084:
    v_22090 = stack[-2];
    v_22090 = qcdr(v_22090);
    goto v_22085;
v_22086:
    goto v_22082;
v_22083:
    goto v_22084;
v_22085:
        return Lapply1(nil, v_22091, v_22090);
v_21986:
    v_22090 = nil;
v_21933:
    return onevalue(v_22090);
}



// Code for gcdld

static LispObject CC_gcdld(LispObject env,
                         LispObject v_21927, LispObject v_21928)
{
    env = qenv(env);
    LispObject v_21986, v_21987, v_21988, v_21989;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21928,v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21927,v_21928);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21987 = v_21928;
    v_21988 = v_21927;
// end of prologue
v_21933:
    goto v_21946;
v_21942:
    v_21989 = v_21987;
    goto v_21943;
v_21944:
    v_21986 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21945;
v_21946:
    goto v_21942;
v_21943:
    goto v_21944;
v_21945:
    if (v_21989 == v_21986) goto v_21940;
    else goto v_21941;
v_21940:
    v_21986 = lisp_true;
    goto v_21939;
v_21941:
    goto v_21956;
v_21952:
    v_21989 = v_21987;
    goto v_21953;
v_21954:
    v_21986 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_21955;
v_21956:
    goto v_21952;
v_21953:
    goto v_21954;
v_21955:
    v_21986 = (v_21989 == v_21986 ? lisp_true : nil);
    goto v_21939;
    v_21986 = nil;
v_21939:
    if (v_21986 == nil) goto v_21937;
    v_21986 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21932;
v_21937:
    v_21986 = v_21988;
    if (v_21986 == nil) goto v_21961;
    else goto v_21962;
v_21961:
    v_21986 = v_21987;
        return Labsval(nil, v_21986);
v_21962:
    v_21986 = v_21988;
    v_21986 = qcar(v_21986);
    if (v_21986 == nil) goto v_21966;
    else goto v_21967;
v_21966:
    v_21986 = v_21988;
    v_21986 = qcdr(v_21986);
    v_21988 = v_21986;
    goto v_21933;
v_21967:
    v_21986 = v_21988;
    v_21986 = qcdr(v_21986);
    stack[0] = v_21986;
    goto v_21981;
v_21977:
    v_21986 = v_21987;
    goto v_21978;
v_21979:
    v_21987 = v_21988;
    v_21987 = qcar(v_21987);
    goto v_21980;
v_21981:
    goto v_21977;
v_21978:
    goto v_21979;
v_21980:
    fn = elt(env, 1); // gcd!-with!-number
    v_21986 = (*qfn2(fn))(fn, v_21986, v_21987);
    env = stack[-1];
    v_21987 = v_21986;
    v_21986 = stack[0];
    v_21988 = v_21986;
    goto v_21933;
    v_21986 = nil;
v_21932:
    return onevalue(v_21986);
}



// Code for lalr_lr0_initial_itemset

static LispObject CC_lalr_lr0_initial_itemset(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21951, v_21952, v_21953;
    LispObject fn;
    argcheck(nargs, 0, "lalr_lr0_initial_itemset");
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
    v_21951 = elt(env, 1); // !S!'
    fn = elt(env, 3); // lalr_productions
    v_21951 = (*qfn1(fn))(fn, v_21951);
    env = stack[0];
    v_21951 = qcar(v_21951);
    v_21951 = qcar(v_21951);
    v_21951 = qcar(v_21951);
    goto v_21944;
v_21938:
    v_21953 = elt(env, 1); // !S!'
    goto v_21939;
v_21940:
    v_21952 = elt(env, 2); // !.
    goto v_21941;
v_21942:
    goto v_21943;
v_21944:
    goto v_21938;
v_21939:
    goto v_21940;
v_21941:
    goto v_21942;
v_21943:
    v_21951 = list3(v_21953, v_21952, v_21951);
    env = stack[0];
    v_21951 = ncons(v_21951);
    env = stack[0];
    {
        fn = elt(env, 4); // lalr_lr0_closure
        return (*qfn1(fn))(fn, v_21951);
    }
    return onevalue(v_21951);
}



// Code for createmonomunit

static LispObject CC_createmonomunit(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21955, v_21956, v_21957;
    argcheck(nargs, 0, "createmonomunit");
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
    v_21955 = (LispObject)16+TAG_FIXNUM; // 1
    v_21955 = Lmkvect(nil, v_21955);
    env = stack[-3];
    stack[-2] = v_21955;
    goto v_21939;
v_21933:
    v_21957 = stack[-2];
    goto v_21934;
v_21935:
    v_21956 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21936;
v_21937:
    v_21955 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21938;
v_21939:
    goto v_21933;
v_21934:
    goto v_21935;
v_21936:
    goto v_21937;
v_21938:
    *(LispObject *)((char *)v_21957 + (CELL-TAG_VECTOR) + (((intptr_t)v_21956-TAG_FIXNUM)/(16/CELL))) = v_21955;
    goto v_21949;
v_21943:
    stack[-1] = stack[-2];
    goto v_21944;
v_21945:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21946;
v_21947:
    v_21955 = nil;
    v_21955 = ncons(v_21955);
    goto v_21948;
v_21949:
    goto v_21943;
v_21944:
    goto v_21945;
v_21946:
    goto v_21947;
v_21948:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_21955;
    v_21955 = stack[-2];
    return onevalue(v_21955);
}



// Code for sfto_yun!-updecf

static LispObject CC_sfto_yunKupdecf(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_22097, v_22098;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21927);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_21927;
// end of prologue
// Binding !*gcd
// FLUIDBIND: reloadenv=9 litvec-offset=1 saveloc=8
{   bind_fluid_stack bind_fluid_var(-9, 1, -8);
    qvalue(elt(env, 1)) = nil; // !*gcd
// Binding d
// FLUIDBIND: reloadenv=9 litvec-offset=2 saveloc=3
{   bind_fluid_stack bind_fluid_var(-9, 2, -3);
    qvalue(elt(env, 2)) = nil; // d
    stack[0] = nil;
    v_22097 = lisp_true;
    qvalue(elt(env, 1)) = v_22097; // !*gcd
    goto v_21945;
v_21941:
    v_22098 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21942;
v_21943:
    v_22097 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21944;
v_21945:
    goto v_21941;
v_21942:
    goto v_21943;
v_21944:
    v_22097 = cons(v_22098, v_22097);
    env = stack[-9];
    stack[-1] = v_22097;
    v_22097 = stack[-7];
    v_22097 = qcar(v_22097);
    v_22097 = qcar(v_22097);
    v_22097 = qcar(v_22097);
    stack[-6] = v_22097;
    goto v_21957;
v_21953:
    stack[-4] = stack[-7];
    goto v_21954;
v_21955:
    goto v_21964;
v_21960:
    v_22098 = stack[-7];
    goto v_21961;
v_21962:
    v_22097 = stack[-6];
    goto v_21963;
v_21964:
    goto v_21960;
v_21961:
    goto v_21962;
v_21963:
    fn = elt(env, 3); // diff
    v_22097 = (*qfn2(fn))(fn, v_22098, v_22097);
    env = stack[-9];
    stack[-2] = v_22097;
    goto v_21956;
v_21957:
    goto v_21953;
v_21954:
    goto v_21955;
v_21956:
    fn = elt(env, 4); // sfto_gcdf
    v_22097 = (*qfn2(fn))(fn, stack[-4], v_22097);
    env = stack[-9];
    stack[-5] = v_22097;
    goto v_21972;
v_21968:
    v_22098 = stack[-7];
    goto v_21969;
v_21970:
    v_22097 = stack[-5];
    goto v_21971;
v_21972:
    goto v_21968;
v_21969:
    goto v_21970;
v_21971:
    fn = elt(env, 5); // quotf
    v_22097 = (*qfn2(fn))(fn, v_22098, v_22097);
    env = stack[-9];
    stack[-4] = v_22097;
    goto v_21980;
v_21976:
    goto v_21986;
v_21982:
    v_22098 = stack[-2];
    goto v_21983;
v_21984:
    v_22097 = stack[-5];
    goto v_21985;
v_21986:
    goto v_21982;
v_21983:
    goto v_21984;
v_21985:
    fn = elt(env, 5); // quotf
    stack[-2] = (*qfn2(fn))(fn, v_22098, v_22097);
    env = stack[-9];
    goto v_21977;
v_21978:
    goto v_21995;
v_21991:
    v_22098 = stack[-4];
    goto v_21992;
v_21993:
    v_22097 = stack[-6];
    goto v_21994;
v_21995:
    goto v_21991;
v_21992:
    goto v_21993;
v_21994:
    fn = elt(env, 3); // diff
    v_22097 = (*qfn2(fn))(fn, v_22098, v_22097);
    env = stack[-9];
    fn = elt(env, 6); // negf
    v_22097 = (*qfn1(fn))(fn, v_22097);
    env = stack[-9];
    goto v_21979;
v_21980:
    goto v_21976;
v_21977:
    goto v_21978;
v_21979:
    fn = elt(env, 7); // addf
    v_22097 = (*qfn2(fn))(fn, stack[-2], v_22097);
    env = stack[-9];
    qvalue(elt(env, 2)) = v_22097; // d
v_22000:
    v_22097 = stack[0];
    v_22097 = (v_22097 == nil ? lisp_true : nil);
    stack[0] = v_22097;
    goto v_22008;
v_22004:
    v_22098 = stack[-4];
    goto v_22005;
v_22006:
    v_22097 = qvalue(elt(env, 2)); // d
    goto v_22007;
v_22008:
    goto v_22004;
v_22005:
    goto v_22006;
v_22007:
    fn = elt(env, 4); // sfto_gcdf
    v_22097 = (*qfn2(fn))(fn, v_22098, v_22097);
    env = stack[-9];
    stack[-7] = v_22097;
    v_22097 = stack[0];
    if (v_22097 == nil) goto v_22014;
    goto v_22021;
v_22017:
    stack[-2] = stack[-1];
    goto v_22018;
v_22019:
    goto v_22028;
v_22024:
    v_22097 = stack[-1];
    v_22098 = qcar(v_22097);
    goto v_22025;
v_22026:
    v_22097 = stack[-7];
    goto v_22027;
v_22028:
    goto v_22024;
v_22025:
    goto v_22026;
v_22027:
    fn = elt(env, 8); // multf
    v_22097 = (*qfn2(fn))(fn, v_22098, v_22097);
    env = stack[-9];
    goto v_22020;
v_22021:
    goto v_22017;
v_22018:
    goto v_22019;
v_22020:
    fn = elt(env, 9); // setcar
    v_22097 = (*qfn2(fn))(fn, stack[-2], v_22097);
    env = stack[-9];
    goto v_22012;
v_22014:
    goto v_22039;
v_22035:
    stack[-2] = stack[-1];
    goto v_22036;
v_22037:
    goto v_22046;
v_22042:
    v_22097 = stack[-1];
    v_22098 = qcdr(v_22097);
    goto v_22043;
v_22044:
    v_22097 = stack[-7];
    goto v_22045;
v_22046:
    goto v_22042;
v_22043:
    goto v_22044;
v_22045:
    fn = elt(env, 8); // multf
    v_22097 = (*qfn2(fn))(fn, v_22098, v_22097);
    env = stack[-9];
    goto v_22038;
v_22039:
    goto v_22035;
v_22036:
    goto v_22037;
v_22038:
    fn = elt(env, 10); // setcdr
    v_22097 = (*qfn2(fn))(fn, stack[-2], v_22097);
    env = stack[-9];
    goto v_22012;
v_22012:
    goto v_22055;
v_22051:
    v_22098 = stack[-4];
    goto v_22052;
v_22053:
    v_22097 = stack[-7];
    goto v_22054;
v_22055:
    goto v_22051;
v_22052:
    goto v_22053;
v_22054:
    fn = elt(env, 5); // quotf
    v_22097 = (*qfn2(fn))(fn, v_22098, v_22097);
    env = stack[-9];
    stack[-4] = v_22097;
    goto v_22063;
v_22059:
    goto v_22069;
v_22065:
    v_22098 = qvalue(elt(env, 2)); // d
    goto v_22066;
v_22067:
    v_22097 = stack[-7];
    goto v_22068;
v_22069:
    goto v_22065;
v_22066:
    goto v_22067;
v_22068:
    fn = elt(env, 5); // quotf
    stack[-2] = (*qfn2(fn))(fn, v_22098, v_22097);
    env = stack[-9];
    goto v_22060;
v_22061:
    goto v_22078;
v_22074:
    v_22098 = stack[-4];
    goto v_22075;
v_22076:
    v_22097 = stack[-6];
    goto v_22077;
v_22078:
    goto v_22074;
v_22075:
    goto v_22076;
v_22077:
    fn = elt(env, 3); // diff
    v_22097 = (*qfn2(fn))(fn, v_22098, v_22097);
    env = stack[-9];
    fn = elt(env, 6); // negf
    v_22097 = (*qfn1(fn))(fn, v_22097);
    env = stack[-9];
    goto v_22062;
v_22063:
    goto v_22059;
v_22060:
    goto v_22061;
v_22062:
    fn = elt(env, 7); // addf
    v_22097 = (*qfn2(fn))(fn, stack[-2], v_22097);
    env = stack[-9];
    qvalue(elt(env, 2)) = v_22097; // d
    v_22097 = stack[-4];
    if (!consp(v_22097)) goto v_22087;
    else goto v_22088;
v_22087:
    v_22097 = lisp_true;
    goto v_22086;
v_22088:
    v_22097 = stack[-4];
    v_22097 = qcar(v_22097);
    v_22097 = (consp(v_22097) ? nil : lisp_true);
    goto v_22086;
    v_22097 = nil;
v_22086:
    if (v_22097 == nil) goto v_22083;
    else goto v_22084;
v_22083:
    goto v_22000;
v_22084:
    v_22097 = stack[-1];
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_22097);
}



// Code for squashsqrt

static LispObject CC_squashsqrt(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_22129, v_22130, v_22131;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21927);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_21927;
// end of prologue
v_21926:
    v_22129 = qvalue(elt(env, 1)); // sqrtflag
    if (v_22129 == nil) goto v_21935;
    else goto v_21936;
v_21935:
    v_22129 = lisp_true;
    goto v_21934;
v_21936:
    v_22129 = stack[-1];
    if (!consp(v_22129)) goto v_21943;
    else goto v_21944;
v_21943:
    v_22129 = lisp_true;
    goto v_21942;
v_21944:
    v_22129 = stack[-1];
    v_22129 = qcar(v_22129);
    v_22129 = qcar(v_22129);
    v_22129 = qcar(v_22129);
    v_22129 = (consp(v_22129) ? nil : lisp_true);
    goto v_21942;
    v_22129 = nil;
v_21942:
    goto v_21934;
    v_22129 = nil;
v_21934:
    if (v_22129 == nil) goto v_21932;
    v_22129 = stack[-1];
    goto v_21930;
v_21932:
    goto v_21965;
v_21961:
    v_22129 = stack[-1];
    v_22129 = qcar(v_22129);
    v_22129 = qcar(v_22129);
    v_22129 = qcar(v_22129);
    v_22130 = qcar(v_22129);
    goto v_21962;
v_21963:
    v_22129 = elt(env, 2); // sqrt
    goto v_21964;
v_21965:
    goto v_21961;
v_21962:
    goto v_21963;
v_21964:
    if (v_22130 == v_22129) goto v_21959;
    else goto v_21960;
v_21959:
    goto v_21977;
v_21973:
    v_22129 = stack[-1];
    v_22129 = qcar(v_22129);
    v_22129 = qcar(v_22129);
    v_22130 = qcdr(v_22129);
    goto v_21974;
v_21975:
    v_22129 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21976;
v_21977:
    goto v_21973;
v_21974:
    goto v_21975;
v_21976:
    v_22129 = (LispObject)greaterp2(v_22130, v_22129);
    v_22129 = v_22129 ? lisp_true : nil;
    env = stack[-3];
    goto v_21958;
v_21960:
    v_22129 = nil;
    goto v_21958;
    v_22129 = nil;
v_21958:
    if (v_22129 == nil) goto v_21956;
    goto v_21991;
v_21987:
    v_22129 = stack[-1];
    v_22129 = qcdr(v_22129);
    stack[0] = CC_squashsqrt(elt(env, 0), v_22129);
    env = stack[-3];
    goto v_21988;
v_21989:
    goto v_22002;
v_21996:
    v_22129 = stack[-1];
    v_22129 = qcar(v_22129);
    v_22129 = qcar(v_22129);
    v_22131 = qcar(v_22129);
    goto v_21997;
v_21998:
    v_22129 = stack[-1];
    v_22129 = qcar(v_22129);
    v_22130 = qcdr(v_22129);
    goto v_21999;
v_22000:
    v_22129 = stack[-1];
    v_22129 = qcar(v_22129);
    v_22129 = qcar(v_22129);
    v_22129 = qcdr(v_22129);
    goto v_22001;
v_22002:
    goto v_21996;
v_21997:
    goto v_21998;
v_21999:
    goto v_22000;
v_22001:
    fn = elt(env, 4); // !*multfsqrt
    v_22129 = (*qfnn(fn))(fn, 3, v_22131, v_22130, v_22129);
    env = stack[-3];
    goto v_21990;
v_21991:
    goto v_21987;
v_21988:
    goto v_21989;
v_21990:
    {
        LispObject v_22135 = stack[0];
        fn = elt(env, 5); // addf
        return (*qfn2(fn))(fn, v_22135, v_22129);
    }
v_21956:
    goto v_22024;
v_22020:
    v_22129 = stack[-1];
    v_22129 = qcar(v_22129);
    v_22129 = qcar(v_22129);
    v_22129 = qcar(v_22129);
    v_22130 = qcar(v_22129);
    goto v_22021;
v_22022:
    v_22129 = elt(env, 3); // expt
    goto v_22023;
v_22024:
    goto v_22020;
v_22021:
    goto v_22022;
v_22023:
    if (v_22130 == v_22129) goto v_22018;
    else goto v_22019;
v_22018:
    v_22129 = stack[-1];
    v_22129 = qcar(v_22129);
    v_22129 = qcar(v_22129);
    v_22129 = qcar(v_22129);
    v_22129 = qcdr(v_22129);
    v_22129 = qcdr(v_22129);
    v_22129 = qcar(v_22129);
    fn = elt(env, 6); // prefix!-rational!-numberp
    v_22129 = (*qfn1(fn))(fn, v_22129);
    env = stack[-3];
    if (v_22129 == nil) goto v_22033;
    else goto v_22034;
v_22033:
    v_22129 = nil;
    goto v_22032;
v_22034:
    goto v_22051;
v_22047:
    v_22129 = stack[-1];
    v_22129 = qcar(v_22129);
    v_22129 = qcar(v_22129);
    v_22130 = qcdr(v_22129);
    goto v_22048;
v_22049:
    v_22129 = stack[-1];
    v_22129 = qcar(v_22129);
    v_22129 = qcar(v_22129);
    v_22129 = qcar(v_22129);
    v_22129 = qcdr(v_22129);
    v_22129 = qcdr(v_22129);
    v_22129 = qcar(v_22129);
    v_22129 = qcdr(v_22129);
    v_22129 = qcdr(v_22129);
    v_22129 = qcar(v_22129);
    goto v_22050;
v_22051:
    goto v_22047;
v_22048:
    goto v_22049;
v_22050:
    v_22129 = (LispObject)geq2(v_22130, v_22129);
    v_22129 = v_22129 ? lisp_true : nil;
    env = stack[-3];
    goto v_22032;
    v_22129 = nil;
v_22032:
    goto v_22017;
v_22019:
    v_22129 = nil;
    goto v_22017;
    v_22129 = nil;
v_22017:
    if (v_22129 == nil) goto v_22015;
    goto v_22074;
v_22070:
    v_22129 = stack[-1];
    v_22129 = qcdr(v_22129);
    stack[0] = CC_squashsqrt(elt(env, 0), v_22129);
    env = stack[-3];
    goto v_22071;
v_22072:
    goto v_22085;
v_22079:
    v_22129 = stack[-1];
    v_22129 = qcar(v_22129);
    v_22129 = qcar(v_22129);
    v_22131 = qcar(v_22129);
    goto v_22080;
v_22081:
    v_22129 = stack[-1];
    v_22129 = qcar(v_22129);
    v_22130 = qcdr(v_22129);
    goto v_22082;
v_22083:
    v_22129 = stack[-1];
    v_22129 = qcar(v_22129);
    v_22129 = qcar(v_22129);
    v_22129 = qcdr(v_22129);
    goto v_22084;
v_22085:
    goto v_22079;
v_22080:
    goto v_22081;
v_22082:
    goto v_22083;
v_22084:
    fn = elt(env, 7); // !*multfexpt
    v_22129 = (*qfnn(fn))(fn, 3, v_22131, v_22130, v_22129);
    env = stack[-3];
    goto v_22073;
v_22074:
    goto v_22070;
v_22071:
    goto v_22072;
v_22073:
    {
        LispObject v_22136 = stack[0];
        fn = elt(env, 5); // addf
        return (*qfn2(fn))(fn, v_22136, v_22129);
    }
v_22015:
    v_22129 = stack[-1];
    v_22129 = qcar(v_22129);
    v_22129 = qcdr(v_22129);
    v_22129 = CC_squashsqrt(elt(env, 0), v_22129);
    env = stack[-3];
    v_22130 = v_22129;
    v_22129 = v_22130;
    if (v_22129 == nil) goto v_22106;
    else goto v_22107;
v_22106:
    v_22129 = stack[-1];
    v_22129 = qcdr(v_22129);
    stack[-1] = v_22129;
    goto v_21926;
v_22107:
    goto v_22121;
v_22115:
    v_22129 = stack[-1];
    v_22129 = qcar(v_22129);
    stack[-2] = qcar(v_22129);
    goto v_22116;
v_22117:
    stack[0] = v_22130;
    goto v_22118;
v_22119:
    v_22129 = stack[-1];
    v_22129 = qcdr(v_22129);
    v_22129 = CC_squashsqrt(elt(env, 0), v_22129);
    goto v_22120;
v_22121:
    goto v_22115;
v_22116:
    goto v_22117;
v_22118:
    goto v_22119;
v_22120:
    {
        LispObject v_22137 = stack[-2];
        LispObject v_22138 = stack[0];
        return acons(v_22137, v_22138, v_22129);
    }
    v_22129 = nil;
    goto v_21930;
    v_22129 = nil;
v_21930:
    return onevalue(v_22129);
}



// Code for cl_bvarl

static LispObject CC_cl_bvarl(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_21938, v_21939;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21927);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21938 = v_21927;
// end of prologue
    goto v_21934;
v_21930:
    fn = elt(env, 2); // cl_bvarl1
    v_21939 = (*qfn1(fn))(fn, v_21938);
    env = stack[0];
    goto v_21931;
v_21932:
    v_21938 = elt(env, 1); // ordp
    goto v_21933;
v_21934:
    goto v_21930;
v_21931:
    goto v_21932;
v_21933:
    {
        fn = elt(env, 3); // sort
        return (*qfn2(fn))(fn, v_21939, v_21938);
    }
}



// Code for rl_onp

static LispObject CC_rl_onp(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_21942;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21927);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21927;
// end of prologue
    goto v_21937;
v_21933:
    v_21942 = elt(env, 1); // !*
    stack[-1] = Lexplode(nil, v_21942);
    env = stack[-2];
    goto v_21934;
v_21935:
    v_21942 = stack[0];
    v_21942 = Lexplode(nil, v_21942);
    env = stack[-2];
    goto v_21936;
v_21937:
    goto v_21933;
v_21934:
    goto v_21935;
v_21936:
    v_21942 = Lappend(nil, stack[-1], v_21942);
    env = stack[-2];
    v_21942 = Lcompress(nil, v_21942);
    env = stack[-2];
    v_21942 = Lintern(nil, v_21942);
    env = stack[-2];
    {
        fn = elt(env, 2); // eval
        return (*qfn1(fn))(fn, v_21942);
    }
}



// Code for termorder1

static LispObject CC_termorder1(LispObject env,
                         LispObject v_21927, LispObject v_21928)
{
    env = qenv(env);
    LispObject v_21990, v_21991;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21928,v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21927,v_21928);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21928;
    stack[-1] = v_21927;
// end of prologue
v_21932:
    v_21990 = stack[-1];
    if (v_21990 == nil) goto v_21935;
    else goto v_21936;
v_21935:
    v_21990 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21931;
v_21936:
    v_21990 = stack[-1];
    v_21990 = (LispObject)zerop(v_21990);
    v_21990 = v_21990 ? lisp_true : nil;
    env = stack[-2];
    if (v_21990 == nil) goto v_21940;
    v_21990 = stack[0];
    v_21990 = (LispObject)zerop(v_21990);
    v_21990 = v_21990 ? lisp_true : nil;
    env = stack[-2];
    if (v_21990 == nil) goto v_21940;
    v_21990 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21931;
v_21940:
    v_21990 = stack[-1];
    v_21990 = (LispObject)zerop(v_21990);
    v_21990 = v_21990 ? lisp_true : nil;
    env = stack[-2];
    if (v_21990 == nil) goto v_21949;
    v_21990 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_21931;
v_21949:
    v_21990 = stack[0];
    v_21990 = (LispObject)zerop(v_21990);
    v_21990 = v_21990 ? lisp_true : nil;
    env = stack[-2];
    if (v_21990 == nil) goto v_21954;
    v_21990 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21931;
v_21954:
    goto v_21965;
v_21961:
    v_21990 = stack[-1];
    v_21991 = qcar(v_21990);
    goto v_21962;
v_21963:
    v_21990 = stack[0];
    v_21990 = qcar(v_21990);
    goto v_21964;
v_21965:
    goto v_21961;
v_21962:
    goto v_21963;
v_21964:
    v_21990 = (LispObject)lessp2(v_21991, v_21990);
    v_21990 = v_21990 ? lisp_true : nil;
    env = stack[-2];
    if (v_21990 == nil) goto v_21959;
    v_21990 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_21931;
v_21959:
    goto v_21978;
v_21974:
    v_21990 = stack[-1];
    v_21991 = qcar(v_21990);
    goto v_21975;
v_21976:
    v_21990 = stack[0];
    v_21990 = qcar(v_21990);
    goto v_21977;
v_21978:
    goto v_21974;
v_21975:
    goto v_21976;
v_21977:
    v_21990 = (LispObject)greaterp2(v_21991, v_21990);
    v_21990 = v_21990 ? lisp_true : nil;
    env = stack[-2];
    if (v_21990 == nil) goto v_21972;
    v_21990 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21931;
v_21972:
    v_21990 = stack[-1];
    v_21990 = qcdr(v_21990);
    stack[-1] = v_21990;
    v_21990 = stack[0];
    v_21990 = qcdr(v_21990);
    stack[0] = v_21990;
    goto v_21932;
    v_21990 = nil;
v_21931:
    return onevalue(v_21990);
}



// Code for vdp_make

static LispObject CC_vdp_make(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21952, v_21953, v_21954;
    LispObject v_21929, v_21928, v_21927;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "vdp_make");
    va_start(aa, nargs);
    v_21927 = va_arg(aa, LispObject);
    v_21928 = va_arg(aa, LispObject);
    v_21929 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21929,v_21928,v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21927,v_21928,v_21929);
    }
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_21952 = v_21929;
    v_21953 = v_21928;
    v_21954 = v_21927;
// end of prologue
    goto v_21940;
v_21932:
    stack[-2] = elt(env, 1); // vdp
    goto v_21933;
v_21934:
    stack[-1] = v_21953;
    goto v_21935;
v_21936:
    stack[0] = v_21954;
    goto v_21937;
v_21938:
    goto v_21949;
v_21945:
    v_21953 = v_21952;
    goto v_21946;
v_21947:
    v_21952 = nil;
    goto v_21948;
v_21949:
    goto v_21945;
v_21946:
    goto v_21947;
v_21948:
    v_21952 = list2(v_21953, v_21952);
    goto v_21939;
v_21940:
    goto v_21932;
v_21933:
    goto v_21934;
v_21935:
    goto v_21936;
v_21937:
    goto v_21938;
v_21939:
    {
        LispObject v_21958 = stack[-2];
        LispObject v_21959 = stack[-1];
        LispObject v_21960 = stack[0];
        return list3star(v_21958, v_21959, v_21960, v_21952);
    }
}



// Code for omattrir

static LispObject CC_omattrir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21997, v_21998, v_21999;
    LispObject fn;
    argcheck(nargs, 0, "omattrir");
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
    fn = elt(env, 5); // lex
    v_21997 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    fn = elt(env, 6); // omatpir
    v_21997 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_21997;
    fn = elt(env, 5); // lex
    v_21997 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    fn = elt(env, 7); // omobj
    v_21997 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[0] = v_21997;
    fn = elt(env, 5); // lex
    v_21997 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_21997 = elt(env, 1); // (!/ o m a t t r)
    fn = elt(env, 8); // checktag
    v_21997 = (*qfn1(fn))(fn, v_21997);
    env = stack[-2];
    v_21997 = stack[-1];
    v_21997 = Lconsp(nil, v_21997);
    env = stack[-2];
    if (v_21997 == nil) goto v_21942;
    goto v_21953;
v_21949:
    v_21997 = stack[-1];
    v_21997 = qcar(v_21997);
    v_21997 = qcdr(v_21997);
    v_21998 = qcar(v_21997);
    goto v_21950;
v_21951:
    v_21997 = elt(env, 2); // csymbol
    goto v_21952;
v_21953:
    goto v_21949;
v_21950:
    goto v_21951;
v_21952:
    if (v_21998 == v_21997) goto v_21947;
    else goto v_21948;
v_21947:
    goto v_21966;
v_21960:
    v_21999 = stack[0];
    goto v_21961;
v_21962:
    v_21998 = nil;
    goto v_21963;
v_21964:
    v_21997 = nil;
    goto v_21965;
v_21966:
    goto v_21960;
v_21961:
    goto v_21962;
v_21963:
    goto v_21964;
v_21965:
    return list2star(v_21999, v_21998, v_21997);
v_21948:
    goto v_21940;
v_21942:
v_21940:
    v_21997 = stack[0];
    if (is_number(v_21997)) goto v_21972;
    else goto v_21973;
v_21972:
    goto v_21982;
v_21976:
    v_21999 = elt(env, 3); // cn
    goto v_21977;
v_21978:
    v_21998 = stack[-1];
    goto v_21979;
v_21980:
    v_21997 = stack[0];
    goto v_21981;
v_21982:
    goto v_21976;
v_21977:
    goto v_21978;
v_21979:
    goto v_21980;
v_21981:
    return list3(v_21999, v_21998, v_21997);
v_21973:
    goto v_21993;
v_21987:
    v_21999 = elt(env, 4); // ci
    goto v_21988;
v_21989:
    v_21998 = stack[-1];
    goto v_21990;
v_21991:
    v_21997 = stack[0];
    goto v_21992;
v_21993:
    goto v_21987;
v_21988:
    goto v_21989;
v_21990:
    goto v_21991;
v_21992:
    return list3(v_21999, v_21998, v_21997);
    return onevalue(v_21997);
}



// Code for dipcontevmin

static LispObject CC_dipcontevmin(LispObject env,
                         LispObject v_21927, LispObject v_21928)
{
    env = qenv(env);
    LispObject v_21998, v_21999, v_22000;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21928,v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21927,v_21928);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21928;
    stack[-1] = v_21927;
// end of prologue
    v_22000 = nil;
v_21935:
    v_21998 = stack[-1];
    if (v_21998 == nil) goto v_21938;
    v_21998 = stack[0];
    if (v_21998 == nil) goto v_21938;
    goto v_21939;
v_21938:
    goto v_21934;
v_21939:
    goto v_21950;
v_21946:
    goto v_21959;
v_21955:
    v_21998 = stack[-1];
    v_21999 = qcar(v_21998);
    goto v_21956;
v_21957:
    v_21998 = stack[0];
    v_21998 = qcar(v_21998);
    goto v_21958;
v_21959:
    goto v_21955;
v_21956:
    goto v_21957;
v_21958:
    if (((intptr_t)(v_21999)) < ((intptr_t)(v_21998))) goto v_21953;
    else goto v_21954;
v_21953:
    v_21998 = stack[-1];
    v_21998 = qcar(v_21998);
    goto v_21952;
v_21954:
    v_21998 = stack[0];
    v_21998 = qcar(v_21998);
    goto v_21952;
    v_21998 = nil;
v_21952:
    goto v_21947;
v_21948:
    v_21999 = v_22000;
    goto v_21949;
v_21950:
    goto v_21946;
v_21947:
    goto v_21948;
v_21949:
    v_21998 = cons(v_21998, v_21999);
    env = stack[-2];
    v_22000 = v_21998;
    v_21998 = stack[-1];
    v_21998 = qcdr(v_21998);
    stack[-1] = v_21998;
    v_21998 = stack[0];
    v_21998 = qcdr(v_21998);
    stack[0] = v_21998;
    goto v_21935;
v_21934:
v_21977:
    v_21998 = v_22000;
    if (v_21998 == nil) goto v_21980;
    goto v_21989;
v_21985:
    v_21999 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21986;
v_21987:
    v_21998 = v_22000;
    v_21998 = qcar(v_21998);
    goto v_21988;
v_21989:
    goto v_21985;
v_21986:
    goto v_21987;
v_21988:
    if (v_21999 == v_21998) goto v_21984;
    else goto v_21980;
v_21984:
    goto v_21981;
v_21980:
    goto v_21976;
v_21981:
    v_21998 = v_22000;
    v_21998 = qcdr(v_21998);
    v_22000 = v_21998;
    goto v_21977;
v_21976:
    v_21998 = v_22000;
        return Lnreverse(nil, v_21998);
    return onevalue(v_21998);
}



// Code for f2dip1

static LispObject CC_f2dip1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22021, v_22022, v_22023, v_22024, v_22025;
    LispObject fn;
    LispObject v_21929, v_21928, v_21927;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "f2dip1");
    va_start(aa, nargs);
    v_21927 = va_arg(aa, LispObject);
    v_21928 = va_arg(aa, LispObject);
    v_21929 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21929,v_21928,v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21927,v_21928,v_21929);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_21929;
    stack[-1] = v_21928;
    stack[-2] = v_21927;
// end of prologue
    v_22021 = stack[-2];
    if (v_22021 == nil) goto v_21933;
    else goto v_21934;
v_21933:
    v_22021 = nil;
    goto v_21932;
v_21934:
    v_22021 = stack[-2];
    if (!consp(v_22021)) goto v_21941;
    else goto v_21942;
v_21941:
    v_22021 = lisp_true;
    goto v_21940;
v_21942:
    v_22021 = stack[-2];
    v_22021 = qcar(v_22021);
    v_22021 = (consp(v_22021) ? nil : lisp_true);
    goto v_21940;
    v_22021 = nil;
v_21940:
    if (v_22021 == nil) goto v_21938;
    v_22021 = stack[0];
    v_22021 = (is_number(v_22021) ? lisp_true : nil);
    if (v_22021 == nil) goto v_21952;
    else goto v_21951;
v_21952:
    v_22021 = stack[0];
    fn = elt(env, 1); // f2dip11
    v_22021 = (*qfn1(fn))(fn, v_22021);
    env = stack[-4];
v_21951:
    goto v_21964;
v_21958:
    goto v_21959;
v_21960:
    goto v_21971;
v_21967:
    goto v_21968;
v_21969:
    v_22021 = stack[-2];
    fn = elt(env, 2); // bcfd
    v_22021 = (*qfn1(fn))(fn, v_22021);
    env = stack[-4];
    goto v_21970;
v_21971:
    goto v_21967;
v_21968:
    goto v_21969;
v_21970:
    fn = elt(env, 3); // bcprod
    v_22022 = (*qfn2(fn))(fn, stack[0], v_22021);
    goto v_21961;
v_21962:
    v_22021 = nil;
    goto v_21963;
v_21964:
    goto v_21958;
v_21959:
    goto v_21960;
v_21961:
    goto v_21962;
v_21963:
    {
        LispObject v_22030 = stack[-1];
        return list2star(v_22030, v_22022, v_22021);
    }
v_21938:
    goto v_21983;
v_21979:
    goto v_21995;
v_21985:
    v_22021 = stack[-2];
    v_22021 = qcar(v_22021);
    v_22021 = qcar(v_22021);
    v_22025 = qcar(v_22021);
    goto v_21986;
v_21987:
    v_22021 = stack[-2];
    v_22021 = qcar(v_22021);
    v_22021 = qcar(v_22021);
    v_22024 = qcdr(v_22021);
    goto v_21988;
v_21989:
    v_22021 = stack[-2];
    v_22021 = qcar(v_22021);
    v_22023 = qcdr(v_22021);
    goto v_21990;
v_21991:
    v_22022 = stack[-1];
    goto v_21992;
v_21993:
    v_22021 = stack[0];
    goto v_21994;
v_21995:
    goto v_21985;
v_21986:
    goto v_21987;
v_21988:
    goto v_21989;
v_21990:
    goto v_21991;
v_21992:
    goto v_21993;
v_21994:
    fn = elt(env, 4); // f2dip2
    stack[-3] = (*qfnn(fn))(fn, 5, v_22025, v_22024, v_22023, v_22022, v_22021);
    env = stack[-4];
    goto v_21980;
v_21981:
    goto v_22016;
v_22010:
    v_22021 = stack[-2];
    v_22023 = qcdr(v_22021);
    goto v_22011;
v_22012:
    v_22022 = stack[-1];
    goto v_22013;
v_22014:
    v_22021 = stack[0];
    goto v_22015;
v_22016:
    goto v_22010;
v_22011:
    goto v_22012;
v_22013:
    goto v_22014;
v_22015:
    v_22021 = CC_f2dip1(elt(env, 0), 3, v_22023, v_22022, v_22021);
    env = stack[-4];
    goto v_21982;
v_21983:
    goto v_21979;
v_21980:
    goto v_21981;
v_21982:
    {
        LispObject v_22031 = stack[-3];
        fn = elt(env, 5); // dipsum
        return (*qfn2(fn))(fn, v_22031, v_22021);
    }
    v_22021 = nil;
v_21932:
    return onevalue(v_22021);
}



// Code for add_item

static LispObject CC_add_item(LispObject env,
                         LispObject v_21927, LispObject v_21928)
{
    env = qenv(env);
    LispObject v_21988, v_21989;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21928,v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21927,v_21928);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21928;
    stack[-1] = v_21927;
// end of prologue
v_21932:
    v_21988 = stack[0];
    v_21988 = qcdr(v_21988);
    if (v_21988 == nil) goto v_21935;
    else goto v_21936;
v_21935:
    goto v_21944;
v_21940:
    v_21989 = stack[0];
    goto v_21941;
v_21942:
    v_21988 = stack[-1];
    goto v_21943;
v_21944:
    goto v_21940;
v_21941:
    goto v_21942;
v_21943:
    fn = elt(env, 2); // setcar
    v_21988 = (*qfn2(fn))(fn, v_21989, v_21988);
    env = stack[-3];
    goto v_21952;
v_21948:
    stack[-2] = stack[0];
    goto v_21949;
v_21950:
    goto v_21961;
v_21955:
    stack[-1] = elt(env, 1); // !*xset!*
    goto v_21956;
v_21957:
    stack[0] = nil;
    goto v_21958;
v_21959:
    v_21988 = elt(env, 1); // !*xset!*
    v_21988 = ncons(v_21988);
    env = stack[-3];
    goto v_21960;
v_21961:
    goto v_21955;
v_21956:
    goto v_21957;
v_21958:
    goto v_21959;
v_21960:
    v_21988 = acons(stack[-1], stack[0], v_21988);
    env = stack[-3];
    goto v_21951;
v_21952:
    goto v_21948;
v_21949:
    goto v_21950;
v_21951:
    fn = elt(env, 3); // setcdr
    v_21988 = (*qfn2(fn))(fn, stack[-2], v_21988);
    v_21988 = nil;
    goto v_21931;
v_21936:
    goto v_21974;
v_21970:
    v_21988 = stack[0];
    v_21988 = qcar(v_21988);
    v_21989 = qcar(v_21988);
    goto v_21971;
v_21972:
    v_21988 = stack[-1];
    v_21988 = qcar(v_21988);
    goto v_21973;
v_21974:
    goto v_21970;
v_21971:
    goto v_21972;
v_21973:
    fn = elt(env, 4); // monordp
    v_21988 = (*qfn2(fn))(fn, v_21989, v_21988);
    env = stack[-3];
    if (v_21988 == nil) goto v_21968;
    v_21988 = stack[0];
    v_21988 = qcdr(v_21988);
    v_21988 = qcar(v_21988);
    stack[0] = v_21988;
    goto v_21932;
v_21968:
    v_21988 = stack[0];
    v_21988 = qcdr(v_21988);
    v_21988 = qcdr(v_21988);
    stack[0] = v_21988;
    goto v_21932;
    v_21988 = nil;
v_21931:
    return onevalue(v_21988);
}



// Code for fl2bf

static LispObject CC_fl2bf(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_21983, v_21984;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21927);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_21927;
// end of prologue
    v_21983 = stack[-1];
    fn = elt(env, 4); // fp!-finite
    v_21983 = (*qfn1(fn))(fn, v_21983);
    env = stack[-3];
    if (v_21983 == nil) goto v_21931;
    else goto v_21932;
v_21931:
    v_21983 = elt(env, 1); // "Floating point infinity or NaN"
    {
        fn = elt(env, 5); // rederr
        return (*qfn1(fn))(fn, v_21983);
    }
v_21932:
    v_21983 = stack[-1];
    fn = elt(env, 6); // frexp
    v_21983 = (*qfn1(fn))(fn, v_21983);
    env = stack[-3];
    stack[-2] = v_21983;
    v_21983 = stack[-2];
    v_21983 = qcdr(v_21983);
    stack[-1] = v_21983;
    v_21983 = stack[-2];
    v_21983 = qcar(v_21983);
    stack[-2] = v_21983;
    goto v_21954;
v_21950:
    stack[0] = stack[-1];
    goto v_21951;
v_21952:
    goto v_21961;
v_21957:
    v_21984 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_21958;
v_21959:
    v_21983 = qvalue(elt(env, 2)); // !!nbfpd
    goto v_21960;
v_21961:
    goto v_21957;
v_21958:
    goto v_21959;
v_21960:
    v_21983 = Lexpt(nil, v_21984, v_21983);
    env = stack[-3];
    goto v_21953;
v_21954:
    goto v_21950;
v_21951:
    goto v_21952;
v_21953:
    v_21983 = times2(stack[0], v_21983);
    env = stack[-3];
    v_21983 = Ltruncate(nil, v_21983);
    env = stack[-3];
    stack[-1] = v_21983;
    goto v_21972;
v_21966:
    stack[0] = elt(env, 3); // !:rd!:
    goto v_21967;
v_21968:
    goto v_21969;
v_21970:
    goto v_21980;
v_21976:
    v_21984 = stack[-2];
    goto v_21977;
v_21978:
    v_21983 = qvalue(elt(env, 2)); // !!nbfpd
    goto v_21979;
v_21980:
    goto v_21976;
v_21977:
    goto v_21978;
v_21979:
    v_21983 = difference2(v_21984, v_21983);
    env = stack[-3];
    goto v_21971;
v_21972:
    goto v_21966;
v_21967:
    goto v_21968;
v_21969:
    goto v_21970;
v_21971:
    v_21983 = list2star(stack[0], stack[-1], v_21983);
    env = stack[-3];
    {
        fn = elt(env, 7); // normbf
        return (*qfn1(fn))(fn, v_21983);
    }
    goto v_21930;
    v_21983 = nil;
v_21930:
    return onevalue(v_21983);
}



// Code for spp

static LispObject CC_spp(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_21941, v_21942;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21927);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21941 = v_21927;
// end of prologue
    v_21942 = v_21941;
    v_21942 = Lconsp(nil, v_21942);
    env = stack[0];
    if (v_21942 == nil) goto v_21931;
    else goto v_21932;
v_21931:
    v_21941 = nil;
    goto v_21930;
v_21932:
    v_21941 = qcar(v_21941);
    {
        fn = elt(env, 1); // kernelp
        return (*qfn1(fn))(fn, v_21941);
    }
    v_21941 = nil;
v_21930:
    return onevalue(v_21941);
}



// Code for fs!:minusp

static LispObject CC_fsTminusp(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_21968, v_21969, v_21970;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21969 = v_21927;
// end of prologue
v_21931:
    v_21968 = v_21969;
    if (v_21968 == nil) goto v_21934;
    else goto v_21935;
v_21934:
    v_21968 = nil;
    goto v_21930;
v_21935:
    goto v_21944;
v_21940:
    v_21970 = v_21969;
    goto v_21941;
v_21942:
    v_21968 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_21943;
v_21944:
    goto v_21940;
v_21941:
    goto v_21942;
v_21943:
    v_21968 = *(LispObject *)((char *)v_21970 + (CELL-TAG_VECTOR) + (((intptr_t)v_21968-TAG_FIXNUM)/(16/CELL)));
    if (v_21968 == nil) goto v_21938;
    else goto v_21939;
v_21938:
    goto v_21953;
v_21949:
    goto v_21950;
v_21951:
    v_21968 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21952;
v_21953:
    goto v_21949;
v_21950:
    goto v_21951;
v_21952:
    v_21968 = *(LispObject *)((char *)v_21969 + (CELL-TAG_VECTOR) + (((intptr_t)v_21968-TAG_FIXNUM)/(16/CELL)));
    v_21968 = qcar(v_21968);
    {
        fn = elt(env, 1); // minusf
        return (*qfn1(fn))(fn, v_21968);
    }
v_21939:
    goto v_21964;
v_21960:
    goto v_21961;
v_21962:
    v_21968 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_21963;
v_21964:
    goto v_21960;
v_21961:
    goto v_21962;
v_21963:
    v_21968 = *(LispObject *)((char *)v_21969 + (CELL-TAG_VECTOR) + (((intptr_t)v_21968-TAG_FIXNUM)/(16/CELL)));
    v_21969 = v_21968;
    goto v_21931;
    v_21968 = nil;
v_21930:
    return onevalue(v_21968);
}



// Code for lex_keywords

static LispObject CC_lex_keywords(LispObject env,
                         LispObject v_21927)
{
    env = qenv(env);
    LispObject v_22313, v_22314, v_22315, v_22316;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21927);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21927);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_22313 = v_21927;
// end of prologue
    stack[-4] = v_22313;
v_21932:
    v_22313 = stack[-4];
    if (v_22313 == nil) goto v_21936;
    else goto v_21937;
v_21936:
    v_22313 = nil;
    goto v_21931;
v_21937:
    v_22313 = stack[-4];
    v_22313 = qcar(v_22313);
    stack[-3] = v_22313;
    v_22313 = stack[-3];
    fn = elt(env, 14); // widestring2list
    v_22313 = (*qfn1(fn))(fn, v_22313);
    env = stack[-6];
    stack[-2] = v_22313;
    v_22313 = stack[-2];
    if (v_22313 == nil) goto v_21952;
    else goto v_21953;
v_21952:
    v_22313 = elt(env, 1); // "Empty string passed to lex_keywords"
    fn = elt(env, 15); // rederr
    v_22313 = (*qfn1(fn))(fn, v_22313);
    env = stack[-6];
    goto v_21951;
v_21953:
v_21951:
    goto v_21969;
v_21965:
    v_22313 = stack[-2];
    v_22314 = qcar(v_22313);
    goto v_21966;
v_21967:
    v_22313 = (LispObject)1040+TAG_FIXNUM; // 65
    goto v_21968;
v_21969:
    goto v_21965;
v_21966:
    goto v_21967;
v_21968:
    v_22313 = (LispObject)geq2(v_22314, v_22313);
    v_22313 = v_22313 ? lisp_true : nil;
    env = stack[-6];
    if (v_22313 == nil) goto v_21962;
    else goto v_21963;
v_21962:
    v_22313 = nil;
    goto v_21961;
v_21963:
    goto v_21981;
v_21977:
    v_22313 = stack[-2];
    v_22314 = qcar(v_22313);
    goto v_21978;
v_21979:
    v_22313 = (LispObject)1440+TAG_FIXNUM; // 90
    goto v_21980;
v_21981:
    goto v_21977;
v_21978:
    goto v_21979;
v_21980:
    v_22313 = (LispObject)lesseq2(v_22314, v_22313);
    v_22313 = v_22313 ? lisp_true : nil;
    env = stack[-6];
    goto v_21961;
    v_22313 = nil;
v_21961:
    if (v_22313 == nil) goto v_21959;
    else goto v_21958;
v_21959:
    goto v_21994;
v_21990:
    v_22313 = stack[-2];
    v_22314 = qcar(v_22313);
    goto v_21991;
v_21992:
    v_22313 = (LispObject)1552+TAG_FIXNUM; // 97
    goto v_21993;
v_21994:
    goto v_21990;
v_21991:
    goto v_21992;
v_21993:
    v_22313 = (LispObject)geq2(v_22314, v_22313);
    v_22313 = v_22313 ? lisp_true : nil;
    env = stack[-6];
    if (v_22313 == nil) goto v_21987;
    else goto v_21988;
v_21987:
    v_22313 = nil;
    goto v_21986;
v_21988:
    goto v_22006;
v_22002:
    v_22313 = stack[-2];
    v_22314 = qcar(v_22313);
    goto v_22003;
v_22004:
    v_22313 = (LispObject)1952+TAG_FIXNUM; // 122
    goto v_22005;
v_22006:
    goto v_22002;
v_22003:
    goto v_22004;
v_22005:
    v_22313 = (LispObject)lesseq2(v_22314, v_22313);
    v_22313 = v_22313 ? lisp_true : nil;
    env = stack[-6];
    goto v_21986;
    v_22313 = nil;
v_21986:
v_21958:
    stack[-5] = v_22313;
    v_22313 = stack[-2];
    v_22313 = qcdr(v_22313);
    stack[-1] = v_22313;
v_22013:
    v_22313 = stack[-1];
    if (v_22313 == nil) goto v_22018;
    else goto v_22019;
v_22018:
    goto v_22012;
v_22019:
    v_22313 = stack[-1];
    v_22313 = qcar(v_22313);
    stack[0] = v_22313;
    goto v_22040;
v_22036:
    v_22314 = stack[0];
    goto v_22037;
v_22038:
    v_22313 = (LispObject)1040+TAG_FIXNUM; // 65
    goto v_22039;
v_22040:
    goto v_22036;
v_22037:
    goto v_22038;
v_22039:
    v_22313 = (LispObject)geq2(v_22314, v_22313);
    v_22313 = v_22313 ? lisp_true : nil;
    env = stack[-6];
    if (v_22313 == nil) goto v_22033;
    goto v_22049;
v_22045:
    v_22314 = stack[0];
    goto v_22046;
v_22047:
    v_22313 = (LispObject)1440+TAG_FIXNUM; // 90
    goto v_22048;
v_22049:
    goto v_22045;
v_22046:
    goto v_22047;
v_22048:
    v_22313 = (LispObject)lesseq2(v_22314, v_22313);
    v_22313 = v_22313 ? lisp_true : nil;
    env = stack[-6];
    if (v_22313 == nil) goto v_22033;
    goto v_22032;
v_22033:
    goto v_22059;
v_22055:
    v_22314 = stack[0];
    goto v_22056;
v_22057:
    v_22313 = (LispObject)1552+TAG_FIXNUM; // 97
    goto v_22058;
v_22059:
    goto v_22055;
v_22056:
    goto v_22057;
v_22058:
    v_22313 = (LispObject)geq2(v_22314, v_22313);
    v_22313 = v_22313 ? lisp_true : nil;
    env = stack[-6];
    if (v_22313 == nil) goto v_22052;
    goto v_22068;
v_22064:
    v_22314 = stack[0];
    goto v_22065;
v_22066:
    v_22313 = (LispObject)1952+TAG_FIXNUM; // 122
    goto v_22067;
v_22068:
    goto v_22064;
v_22065:
    goto v_22066;
v_22067:
    v_22313 = (LispObject)lesseq2(v_22314, v_22313);
    v_22313 = v_22313 ? lisp_true : nil;
    env = stack[-6];
    if (v_22313 == nil) goto v_22052;
    goto v_22032;
v_22052:
    goto v_22081;
v_22077:
    v_22314 = stack[0];
    goto v_22078;
v_22079:
    v_22313 = (LispObject)768+TAG_FIXNUM; // 48
    goto v_22080;
v_22081:
    goto v_22077;
v_22078:
    goto v_22079;
v_22080:
    v_22313 = (LispObject)geq2(v_22314, v_22313);
    v_22313 = v_22313 ? lisp_true : nil;
    env = stack[-6];
    if (v_22313 == nil) goto v_22073;
    goto v_22090;
v_22086:
    v_22314 = stack[0];
    goto v_22087;
v_22088:
    v_22313 = (LispObject)912+TAG_FIXNUM; // 57
    goto v_22089;
v_22090:
    goto v_22086;
v_22087:
    goto v_22088;
v_22089:
    v_22313 = (LispObject)lesseq2(v_22314, v_22313);
    v_22313 = v_22313 ? lisp_true : nil;
    env = stack[-6];
    if (v_22313 == nil) goto v_22073;
    goto v_22074;
v_22073:
    goto v_22098;
v_22094:
    v_22314 = stack[0];
    goto v_22095;
v_22096:
    v_22313 = (LispObject)1520+TAG_FIXNUM; // 95
    goto v_22097;
v_22098:
    goto v_22094;
v_22095:
    goto v_22096;
v_22097:
    v_22313 = Lneq(nil, v_22314, v_22313);
    env = stack[-6];
    goto v_22072;
v_22074:
    v_22313 = nil;
    goto v_22072;
    v_22313 = nil;
v_22072:
    goto v_22030;
v_22032:
    v_22313 = nil;
    goto v_22030;
    v_22313 = nil;
v_22030:
    if (v_22313 == nil) goto v_22028;
    v_22313 = nil;
    stack[-5] = v_22313;
    goto v_22026;
v_22028:
v_22026:
    v_22313 = stack[-1];
    v_22313 = qcdr(v_22313);
    stack[-1] = v_22313;
    goto v_22013;
v_22012:
    v_22313 = stack[-2];
    v_22313 = qcdr(v_22313);
    if (v_22313 == nil) goto v_22116;
    else goto v_22117;
v_22116:
    v_22313 = lisp_true;
    goto v_22115;
v_22117:
    v_22313 = stack[-5];
    goto v_22115;
    v_22313 = nil;
v_22115:
    if (v_22313 == nil) goto v_22113;
    v_22313 = stack[-3];
    v_22313 = Lintern(nil, v_22313);
    env = stack[-6];
    stack[-2] = v_22313;
    goto v_22135;
v_22131:
    v_22314 = stack[-2];
    goto v_22132;
v_22133:
    v_22313 = elt(env, 2); // lex_code
    goto v_22134;
v_22135:
    goto v_22131;
v_22132:
    goto v_22133;
v_22134:
    v_22313 = get(v_22314, v_22313);
    env = stack[-6];
    if (v_22313 == nil) goto v_22128;
    else goto v_22129;
v_22128:
    goto v_22143;
v_22139:
    v_22314 = stack[-2];
    goto v_22140;
v_22141:
    v_22313 = qvalue(elt(env, 3)); // lex_keyword_names
    goto v_22142;
v_22143:
    goto v_22139;
v_22140:
    goto v_22141;
v_22142:
    v_22313 = cons(v_22314, v_22313);
    env = stack[-6];
    qvalue(elt(env, 3)) = v_22313; // lex_keyword_names
    goto v_22155;
v_22151:
    v_22314 = stack[-2];
    goto v_22152;
v_22153:
    v_22313 = elt(env, 4); // lex_next_code
    goto v_22154;
v_22155:
    goto v_22151;
v_22152:
    goto v_22153;
v_22154:
    v_22313 = get(v_22314, v_22313);
    env = stack[-6];
    if (v_22313 == nil) goto v_22148;
    else goto v_22149;
v_22148:
    goto v_22165;
v_22159:
    v_22315 = stack[-2];
    goto v_22160;
v_22161:
    v_22314 = elt(env, 2); // lex_code
    goto v_22162;
v_22163:
    v_22313 = qvalue(elt(env, 4)); // lex_next_code
    goto v_22164;
v_22165:
    goto v_22159;
v_22160:
    goto v_22161;
v_22162:
    goto v_22163;
v_22164:
    v_22313 = Lputprop(nil, 3, v_22315, v_22314, v_22313);
    env = stack[-6];
    goto v_22176;
v_22170:
    v_22315 = qvalue(elt(env, 4)); // lex_next_code
    goto v_22171;
v_22172:
    v_22314 = stack[-2];
    goto v_22173;
v_22174:
    v_22313 = qvalue(elt(env, 5)); // lex_codename
    goto v_22175;
v_22176:
    goto v_22170;
v_22171:
    goto v_22172;
v_22173:
    goto v_22174;
v_22175:
    v_22313 = acons(v_22315, v_22314, v_22313);
    env = stack[-6];
    qvalue(elt(env, 5)) = v_22313; // lex_codename
    v_22313 = qvalue(elt(env, 6)); // !*tracelex
    if (v_22313 == nil) goto v_22183;
    v_22313 = elt(env, 7); // "Token '"
    v_22313 = Lprinc(nil, v_22313);
    env = stack[-6];
    v_22313 = stack[-2];
    v_22313 = Lprin(nil, v_22313);
    env = stack[-6];
    v_22313 = elt(env, 8); // "' allocated code "
    v_22313 = Lprinc(nil, v_22313);
    env = stack[-6];
    v_22313 = qvalue(elt(env, 4)); // lex_next_code
    v_22313 = Lprint(nil, v_22313);
    env = stack[-6];
    goto v_22181;
v_22183:
v_22181:
    v_22313 = qvalue(elt(env, 4)); // lex_next_code
    v_22313 = add1(v_22313);
    env = stack[-6];
    qvalue(elt(env, 4)) = v_22313; // lex_next_code
    goto v_22147;
v_22149:
v_22147:
    goto v_22127;
v_22129:
v_22127:
    goto v_21947;
v_22113:
    v_22313 = stack[-3];
    v_22313 = Lintern(nil, v_22313);
    env = stack[-6];
    stack[-3] = v_22313;
    goto v_22207;
v_22203:
    v_22314 = stack[-3];
    goto v_22204;
v_22205:
    v_22313 = elt(env, 2); // lex_code
    goto v_22206;
v_22207:
    goto v_22203;
v_22204:
    goto v_22205;
v_22206:
    v_22313 = get(v_22314, v_22313);
    env = stack[-6];
    if (v_22313 == nil) goto v_22200;
    else goto v_22201;
v_22200:
    goto v_22215;
v_22211:
    v_22314 = stack[-3];
    goto v_22212;
v_22213:
    v_22313 = qvalue(elt(env, 3)); // lex_keyword_names
    goto v_22214;
v_22215:
    goto v_22211;
v_22212:
    goto v_22213;
v_22214:
    v_22313 = cons(v_22314, v_22313);
    env = stack[-6];
    qvalue(elt(env, 3)) = v_22313; // lex_keyword_names
    goto v_22225;
v_22219:
    v_22315 = stack[-3];
    goto v_22220;
v_22221:
    v_22314 = elt(env, 2); // lex_code
    goto v_22222;
v_22223:
    v_22313 = qvalue(elt(env, 4)); // lex_next_code
    goto v_22224;
v_22225:
    goto v_22219;
v_22220:
    goto v_22221;
v_22222:
    goto v_22223;
v_22224:
    v_22313 = Lputprop(nil, 3, v_22315, v_22314, v_22313);
    env = stack[-6];
    goto v_22236;
v_22230:
    v_22315 = qvalue(elt(env, 4)); // lex_next_code
    goto v_22231;
v_22232:
    v_22314 = stack[-3];
    goto v_22233;
v_22234:
    v_22313 = qvalue(elt(env, 5)); // lex_codename
    goto v_22235;
v_22236:
    goto v_22230;
v_22231:
    goto v_22232;
v_22233:
    goto v_22234;
v_22235:
    v_22313 = acons(v_22315, v_22314, v_22313);
    env = stack[-6];
    qvalue(elt(env, 5)) = v_22313; // lex_codename
    v_22313 = qvalue(elt(env, 4)); // lex_next_code
    v_22313 = add1(v_22313);
    env = stack[-6];
    qvalue(elt(env, 4)) = v_22313; // lex_next_code
    v_22313 = stack[-2];
    v_22313 = Lreverse(nil, v_22313);
    env = stack[-6];
    v_22313 = qcdr(v_22313);
    v_22313 = Lreverse(nil, v_22313);
    env = stack[-6];
    fn = elt(env, 16); // list2widestring
    v_22313 = (*qfn1(fn))(fn, v_22313);
    env = stack[-6];
    stack[-5] = v_22313;
    v_22313 = stack[-5];
    v_22313 = ncons(v_22313);
    env = stack[-6];
    v_22313 = CC_lex_keywords(elt(env, 0), v_22313);
    env = stack[-6];
    v_22313 = stack[-5];
    v_22313 = Lintern(nil, v_22313);
    env = stack[-6];
    stack[-5] = v_22313;
    v_22313 = stack[-2];
    fn = elt(env, 17); // lastcar
    v_22313 = (*qfn1(fn))(fn, v_22313);
    env = stack[-6];
    v_22313 = ncons(v_22313);
    env = stack[-6];
    fn = elt(env, 16); // list2widestring
    v_22313 = (*qfn1(fn))(fn, v_22313);
    env = stack[-6];
    v_22313 = Lintern(nil, v_22313);
    env = stack[-6];
    stack[-2] = v_22313;
    v_22313 = qvalue(elt(env, 6)); // !*tracelex
    if (v_22313 == nil) goto v_22260;
    v_22313 = Lposn(nil, 0);
    env = stack[-6];
    v_22313 = (LispObject)zerop(v_22313);
    v_22313 = v_22313 ? lisp_true : nil;
    env = stack[-6];
    if (v_22313 == nil) goto v_22264;
    else goto v_22265;
v_22264:
    v_22313 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_22263;
v_22265:
v_22263:
    v_22313 = elt(env, 9); // "dipthong data '"
    v_22313 = Lprinc(nil, v_22313);
    env = stack[-6];
    v_22313 = stack[-5];
    v_22313 = Lprin(nil, v_22313);
    env = stack[-6];
    v_22313 = elt(env, 10); // "' plus '"
    v_22313 = Lprinc(nil, v_22313);
    env = stack[-6];
    v_22313 = stack[-2];
    v_22313 = Lprin(nil, v_22313);
    env = stack[-6];
    v_22313 = elt(env, 11); // "' => '"
    v_22313 = Lprinc(nil, v_22313);
    env = stack[-6];
    v_22313 = stack[-3];
    v_22313 = Lprin(nil, v_22313);
    env = stack[-6];
    v_22313 = elt(env, 12); // "'"
    v_22313 = Lprintc(nil, v_22313);
    env = stack[-6];
    goto v_22258;
v_22260:
v_22258:
    goto v_22290;
v_22284:
    stack[-1] = stack[-5];
    goto v_22285;
v_22286:
    stack[0] = elt(env, 13); // lex_dipthong
    goto v_22287;
v_22288:
    goto v_22300;
v_22294:
    v_22316 = stack[-2];
    goto v_22295;
v_22296:
    v_22315 = stack[-3];
    goto v_22297;
v_22298:
    goto v_22308;
v_22304:
    v_22314 = stack[-5];
    goto v_22305;
v_22306:
    v_22313 = elt(env, 13); // lex_dipthong
    goto v_22307;
v_22308:
    goto v_22304;
v_22305:
    goto v_22306;
v_22307:
    v_22313 = get(v_22314, v_22313);
    env = stack[-6];
    goto v_22299;
v_22300:
    goto v_22294;
v_22295:
    goto v_22296;
v_22297:
    goto v_22298;
v_22299:
    v_22313 = acons(v_22316, v_22315, v_22313);
    env = stack[-6];
    goto v_22289;
v_22290:
    goto v_22284;
v_22285:
    goto v_22286;
v_22287:
    goto v_22288;
v_22289:
    v_22313 = Lputprop(nil, 3, stack[-1], stack[0], v_22313);
    env = stack[-6];
    goto v_22199;
v_22201:
v_22199:
v_21947:
    v_22313 = stack[-4];
    v_22313 = qcdr(v_22313);
    stack[-4] = v_22313;
    goto v_21932;
v_21931:
    return onevalue(v_22313);
}



setup_type const u39_setup[] =
{
    {"prepsq*1",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_prepsqH1},
    {"num_signsort",            CC_num_signsort,TOO_MANY_1,    WRONG_NO_1},
    {"lambda_ygm6np4pcqv31",    TOO_FEW_2,      CC_lambda_ygm6np4pcqv31,WRONG_NO_2},
    {"makeqn-maybe",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_makeqnKmaybe},
    {"assoc2",                  TOO_FEW_2,      CC_assoc2,     WRONG_NO_2},
    {"vector-to-poly",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vectorKtoKpoly},
    {"lalr_make_compressed_goto_table",WRONG_NO_NA,WRONG_NO_NB,(n_args *)CC_lalr_make_compressed_goto_table},
    {"my+nullsq+p",             CC_myLnullsqLp, TOO_MANY_1,    WRONG_NO_1},
    {"dvfsf_simplat1",          TOO_FEW_2,      CC_dvfsf_simplat1,WRONG_NO_2},
    {"matrixelems",             CC_matrixelems, TOO_MANY_1,    WRONG_NO_1},
    {"multerm",                 TOO_FEW_2,      CC_multerm,    WRONG_NO_2},
    {"sptransmat",              CC_sptransmat,  TOO_MANY_1,    WRONG_NO_1},
    {"weak_xreduce1",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_weak_xreduce1},
    {"toolongassignp",          CC_toolongassignp,TOO_MANY_1,  WRONG_NO_1},
    {"simppartdf",              CC_simppartdf,  TOO_MANY_1,    WRONG_NO_1},
    {"dfp-sub",                 TOO_FEW_2,      CC_dfpKsub,    WRONG_NO_2},
    {"lf=zero",                 CC_lfMzero,     TOO_MANY_1,    WRONG_NO_1},
    {"setqinsertlist",          CC_setqinsertlist,TOO_MANY_1,  WRONG_NO_1},
    {"pickbasicset",            CC_pickbasicset,TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_optsplitterm",       TOO_FEW_2,      CC_ofsf_optsplitterm,WRONG_NO_2},
    {"determinantrd",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_determinantrd},
    {"transmat1",               CC_transmat1,   TOO_MANY_1,    WRONG_NO_1},
    {"remzzzz",                 TOO_FEW_2,      CC_remzzzz,    WRONG_NO_2},
    {"diplmon2sq",              TOO_FEW_2,      CC_diplmon2sq, WRONG_NO_2},
    {"sc_rowscalarproduct",     TOO_FEW_2,      CC_sc_rowscalarproduct,WRONG_NO_2},
    {"xnsiz",                   CC_xnsiz,       TOO_MANY_1,    WRONG_NO_1},
    {"rd:difference",           TOO_FEW_2,      CC_rdTdifference,WRONG_NO_2},
    {"indxsymp",                TOO_FEW_2,      CC_indxsymp,   WRONG_NO_2},
    {"calc_coeffmap_",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_calc_coeffmap_},
    {"lengthreval",             CC_lengthreval, TOO_MANY_1,    WRONG_NO_1},
    {"gcdld",                   TOO_FEW_2,      CC_gcdld,      WRONG_NO_2},
    {"lalr_lr0_initial_itemset",WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lalr_lr0_initial_itemset},
    {"createmonomunit",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_createmonomunit},
    {"sfto_yun-updecf",         CC_sfto_yunKupdecf,TOO_MANY_1, WRONG_NO_1},
    {"squashsqrt",              CC_squashsqrt,  TOO_MANY_1,    WRONG_NO_1},
    {"cl_bvarl",                CC_cl_bvarl,    TOO_MANY_1,    WRONG_NO_1},
    {"rl_onp",                  CC_rl_onp,      TOO_MANY_1,    WRONG_NO_1},
    {"termorder1",              TOO_FEW_2,      CC_termorder1, WRONG_NO_2},
    {"vdp_make",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vdp_make},
    {"omattrir",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_omattrir},
    {"dipcontevmin",            TOO_FEW_2,      CC_dipcontevmin,WRONG_NO_2},
    {"f2dip1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_f2dip1},
    {"add_item",                TOO_FEW_2,      CC_add_item,   WRONG_NO_2},
    {"fl2bf",                   CC_fl2bf,       TOO_MANY_1,    WRONG_NO_1},
    {"spp",                     CC_spp,         TOO_MANY_1,    WRONG_NO_1},
    {"fs:minusp",               CC_fsTminusp,   TOO_MANY_1,    WRONG_NO_1},
    {"lex_keywords",            CC_lex_keywords,TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u39", (two_args *)"6285 3984890 838613", 0}
};

// end of generated code
