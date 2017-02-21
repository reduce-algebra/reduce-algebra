
// $destdir/u07.c        Machine generated C code

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



// Code for minus!-mod!-p

static LispObject CC_minusKmodKp(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3146, v_3147;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_3091;
// end of prologue
    stack[-2] = nil;
v_3096:
    v_3146 = stack[-1];
    if (v_3146 == nil) goto v_3099;
    else goto v_3100;
v_3099:
    v_3146 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_3146);
    }
v_3100:
    v_3146 = stack[-1];
    if (!consp(v_3146)) goto v_3108;
    else goto v_3109;
v_3108:
    v_3146 = lisp_true;
    goto v_3107;
v_3109:
    v_3146 = stack[-1];
    v_3146 = qcar(v_3146);
    v_3146 = (consp(v_3146) ? nil : lisp_true);
    goto v_3107;
    v_3146 = nil;
v_3107:
    if (v_3146 == nil) goto v_3105;
    goto v_3122;
v_3118:
    v_3147 = stack[-2];
    goto v_3119;
v_3120:
    v_3146 = stack[-1];
    {   intptr_t w = int_of_fixnum(v_3146);
        if (w != 0) w = current_modulus - w;
        v_3146 = fixnum_of_int(w);
    }
    goto v_3121;
v_3122:
    goto v_3118;
v_3119:
    goto v_3120;
v_3121:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_3147, v_3146);
    }
v_3105:
    goto v_3135;
v_3129:
    v_3146 = stack[-1];
    v_3146 = qcar(v_3146);
    stack[0] = qcar(v_3146);
    goto v_3130;
v_3131:
    v_3146 = stack[-1];
    v_3146 = qcar(v_3146);
    v_3146 = qcdr(v_3146);
    v_3147 = CC_minusKmodKp(elt(env, 0), v_3146);
    env = stack[-3];
    goto v_3132;
v_3133:
    v_3146 = stack[-2];
    goto v_3134;
v_3135:
    goto v_3129;
v_3130:
    goto v_3131;
v_3132:
    goto v_3133;
v_3134:
    v_3146 = acons(stack[0], v_3147, v_3146);
    env = stack[-3];
    stack[-2] = v_3146;
    v_3146 = stack[-1];
    v_3146 = qcdr(v_3146);
    stack[-1] = v_3146;
    goto v_3096;
    v_3146 = nil;
    return onevalue(v_3146);
}



// Code for raddf

static LispObject CC_raddf(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3257, v_3258;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_3092;
    stack[-2] = v_3091;
// end of prologue
    stack[-3] = nil;
v_3097:
    v_3257 = stack[-2];
    if (v_3257 == nil) goto v_3100;
    else goto v_3101;
v_3100:
    goto v_3108;
v_3104:
    v_3258 = stack[-3];
    goto v_3105;
v_3106:
    v_3257 = stack[-1];
    goto v_3107;
v_3108:
    goto v_3104;
v_3105:
    goto v_3106;
v_3107:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_3258, v_3257);
    }
v_3101:
    v_3257 = stack[-1];
    if (v_3257 == nil) goto v_3111;
    else goto v_3112;
v_3111:
    goto v_3119;
v_3115:
    v_3258 = stack[-3];
    goto v_3116;
v_3117:
    v_3257 = stack[-2];
    goto v_3118;
v_3119:
    goto v_3115;
v_3116:
    goto v_3117;
v_3118:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_3258, v_3257);
    }
v_3112:
    v_3257 = stack[-2];
    if (!consp(v_3257)) goto v_3126;
    else goto v_3127;
v_3126:
    v_3257 = lisp_true;
    goto v_3125;
v_3127:
    v_3257 = stack[-2];
    v_3257 = qcar(v_3257);
    v_3257 = (consp(v_3257) ? nil : lisp_true);
    goto v_3125;
    v_3257 = nil;
v_3125:
    if (v_3257 == nil) goto v_3123;
    goto v_3140;
v_3136:
    stack[0] = stack[-3];
    goto v_3137;
v_3138:
    goto v_3147;
v_3143:
    v_3258 = stack[-2];
    goto v_3144;
v_3145:
    v_3257 = stack[-1];
    goto v_3146;
v_3147:
    goto v_3143;
v_3144:
    goto v_3145;
v_3146:
    fn = elt(env, 2); // addd
    v_3257 = (*qfn2(fn))(fn, v_3258, v_3257);
    env = stack[-4];
    goto v_3139;
v_3140:
    goto v_3136;
v_3137:
    goto v_3138;
v_3139:
    {
        LispObject v_3263 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_3263, v_3257);
    }
v_3123:
    v_3257 = stack[-1];
    if (!consp(v_3257)) goto v_3154;
    else goto v_3155;
v_3154:
    v_3257 = lisp_true;
    goto v_3153;
v_3155:
    v_3257 = stack[-1];
    v_3257 = qcar(v_3257);
    v_3257 = (consp(v_3257) ? nil : lisp_true);
    goto v_3153;
    v_3257 = nil;
v_3153:
    if (v_3257 == nil) goto v_3151;
    goto v_3168;
v_3164:
    stack[0] = stack[-3];
    goto v_3165;
v_3166:
    goto v_3175;
v_3171:
    v_3258 = stack[-1];
    goto v_3172;
v_3173:
    v_3257 = stack[-2];
    goto v_3174;
v_3175:
    goto v_3171;
v_3172:
    goto v_3173;
v_3174:
    fn = elt(env, 2); // addd
    v_3257 = (*qfn2(fn))(fn, v_3258, v_3257);
    env = stack[-4];
    goto v_3167;
v_3168:
    goto v_3164;
v_3165:
    goto v_3166;
v_3167:
    {
        LispObject v_3264 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_3264, v_3257);
    }
v_3151:
    goto v_3184;
v_3180:
    v_3257 = stack[-2];
    v_3257 = qcar(v_3257);
    v_3258 = qcar(v_3257);
    goto v_3181;
v_3182:
    v_3257 = stack[-1];
    v_3257 = qcar(v_3257);
    v_3257 = qcar(v_3257);
    goto v_3183;
v_3184:
    goto v_3180;
v_3181:
    goto v_3182;
v_3183:
    if (equal(v_3258, v_3257)) goto v_3178;
    else goto v_3179;
v_3178:
    goto v_3198;
v_3192:
    v_3257 = stack[-2];
    v_3257 = qcar(v_3257);
    stack[0] = qcar(v_3257);
    goto v_3193;
v_3194:
    goto v_3207;
v_3203:
    v_3257 = stack[-2];
    v_3257 = qcar(v_3257);
    v_3258 = qcdr(v_3257);
    goto v_3204;
v_3205:
    v_3257 = stack[-1];
    v_3257 = qcar(v_3257);
    v_3257 = qcdr(v_3257);
    goto v_3206;
v_3207:
    goto v_3203;
v_3204:
    goto v_3205;
v_3206:
    v_3258 = CC_raddf(elt(env, 0), v_3258, v_3257);
    env = stack[-4];
    goto v_3195;
v_3196:
    v_3257 = stack[-3];
    goto v_3197;
v_3198:
    goto v_3192;
v_3193:
    goto v_3194;
v_3195:
    goto v_3196;
v_3197:
    v_3257 = acons(stack[0], v_3258, v_3257);
    env = stack[-4];
    stack[-3] = v_3257;
    v_3257 = stack[-2];
    v_3257 = qcdr(v_3257);
    stack[-2] = v_3257;
    v_3257 = stack[-1];
    v_3257 = qcdr(v_3257);
    stack[-1] = v_3257;
    goto v_3097;
v_3179:
    goto v_3226;
v_3222:
    v_3257 = stack[-2];
    v_3257 = qcar(v_3257);
    v_3258 = qcar(v_3257);
    goto v_3223;
v_3224:
    v_3257 = stack[-1];
    v_3257 = qcar(v_3257);
    v_3257 = qcar(v_3257);
    goto v_3225;
v_3226:
    goto v_3222;
v_3223:
    goto v_3224;
v_3225:
    fn = elt(env, 3); // ordpp
    v_3257 = (*qfn2(fn))(fn, v_3258, v_3257);
    env = stack[-4];
    if (v_3257 == nil) goto v_3220;
    goto v_3238;
v_3234:
    v_3257 = stack[-2];
    v_3258 = qcar(v_3257);
    goto v_3235;
v_3236:
    v_3257 = stack[-3];
    goto v_3237;
v_3238:
    goto v_3234;
v_3235:
    goto v_3236;
v_3237:
    v_3257 = cons(v_3258, v_3257);
    env = stack[-4];
    stack[-3] = v_3257;
    v_3257 = stack[-2];
    v_3257 = qcdr(v_3257);
    stack[-2] = v_3257;
    goto v_3097;
v_3220:
    goto v_3251;
v_3247:
    v_3257 = stack[-1];
    v_3258 = qcar(v_3257);
    goto v_3248;
v_3249:
    v_3257 = stack[-3];
    goto v_3250;
v_3251:
    goto v_3247;
v_3248:
    goto v_3249;
v_3250:
    v_3257 = cons(v_3258, v_3257);
    env = stack[-4];
    stack[-3] = v_3257;
    v_3257 = stack[-1];
    v_3257 = qcdr(v_3257);
    stack[-1] = v_3257;
    goto v_3097;
    v_3257 = nil;
    return onevalue(v_3257);
}



// Code for talp_varlt1

static LispObject CC_talp_varlt1(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3157, v_3158;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3092;
    stack[-1] = v_3091;
// end of prologue
    v_3157 = stack[-1];
    if (!consp(v_3157)) goto v_3098;
    else goto v_3099;
v_3098:
    goto v_3109;
v_3105:
    stack[-2] = stack[-1];
    goto v_3106;
v_3107:
    fn = elt(env, 1); // talp_getl
    v_3157 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_3108;
v_3109:
    goto v_3105;
v_3106:
    goto v_3107;
v_3108:
    v_3157 = Latsoc(nil, stack[-2], v_3157);
    if (v_3157 == nil) goto v_3103;
    else goto v_3104;
v_3103:
    goto v_3118;
v_3114:
    v_3158 = stack[-1];
    goto v_3115;
v_3116:
    v_3157 = stack[0];
    goto v_3117;
v_3118:
    goto v_3114;
v_3115:
    goto v_3116;
v_3117:
    {
        fn = elt(env, 2); // lto_insert
        return (*qfn2(fn))(fn, v_3158, v_3157);
    }
v_3104:
    v_3157 = nil;
    goto v_3095;
    goto v_3097;
v_3099:
v_3097:
    v_3157 = stack[-1];
    fn = elt(env, 3); // talp_argl
    v_3157 = (*qfn1(fn))(fn, v_3157);
    env = stack[-3];
    stack[-1] = v_3157;
v_3127:
    v_3157 = stack[-1];
    if (v_3157 == nil) goto v_3132;
    else goto v_3133;
v_3132:
    goto v_3126;
v_3133:
    v_3157 = stack[-1];
    v_3157 = qcar(v_3157);
    goto v_3144;
v_3140:
    goto v_3150;
v_3146:
    v_3158 = v_3157;
    goto v_3147;
v_3148:
    v_3157 = stack[0];
    goto v_3149;
v_3150:
    goto v_3146;
v_3147:
    goto v_3148;
v_3149:
    v_3158 = CC_talp_varlt1(elt(env, 0), v_3158, v_3157);
    env = stack[-3];
    goto v_3141;
v_3142:
    v_3157 = stack[0];
    goto v_3143;
v_3144:
    goto v_3140;
v_3141:
    goto v_3142;
v_3143:
    fn = elt(env, 4); // union
    v_3157 = (*qfn2(fn))(fn, v_3158, v_3157);
    env = stack[-3];
    stack[0] = v_3157;
    v_3157 = stack[-1];
    v_3157 = qcdr(v_3157);
    stack[-1] = v_3157;
    goto v_3127;
v_3126:
    v_3157 = stack[0];
v_3095:
    return onevalue(v_3157);
}



// Code for mri_simplfloor

static LispObject CC_mri_simplfloor(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3104;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_3091;
// end of prologue
    v_3104 = stack[0];
    fn = elt(env, 1); // mri_floorkernelp
    v_3104 = (*qfn1(fn))(fn, v_3104);
    env = stack[-1];
    if (v_3104 == nil) goto v_3095;
    else goto v_3096;
v_3095:
    v_3104 = stack[0];
    goto v_3094;
v_3096:
    v_3104 = stack[0];
    {
        fn = elt(env, 2); // mri_simplfloor1
        return (*qfn1(fn))(fn, v_3104);
    }
    v_3104 = nil;
v_3094:
    return onevalue(v_3104);
}



// Code for quotfd

static LispObject CC_quotfd(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3149, v_3150, v_3151, v_3152;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3151 = v_3092;
    v_3152 = v_3091;
// end of prologue
    goto v_3102;
v_3098:
    v_3150 = v_3152;
    goto v_3099;
v_3100:
    v_3149 = v_3151;
    goto v_3101;
v_3102:
    goto v_3098;
v_3099:
    goto v_3100;
v_3101:
    if (equal(v_3150, v_3149)) goto v_3096;
    else goto v_3097;
v_3096:
    v_3149 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3095;
v_3097:
    v_3149 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_3149)) v_3149 = nil;
    else { v_3149 = qfastgets(v_3149);
           if (v_3149 != nil) { v_3149 = elt(v_3149, 3); // field
#ifdef RECORD_GET
             if (v_3149 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_3149 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_3149 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_3149 == SPID_NOPROP) v_3149 = nil; else v_3149 = lisp_true; }}
#endif
    if (v_3149 == nil) goto v_3107;
    goto v_3115;
v_3111:
    v_3149 = v_3152;
    goto v_3112;
v_3113:
    v_3150 = v_3151;
    goto v_3114;
v_3115:
    goto v_3111;
v_3112:
    goto v_3113;
v_3114:
    {
        fn = elt(env, 2); // divd
        return (*qfn2(fn))(fn, v_3149, v_3150);
    }
v_3107:
    v_3149 = v_3152;
    if (!consp(v_3149)) goto v_3122;
    else goto v_3123;
v_3122:
    v_3149 = lisp_true;
    goto v_3121;
v_3123:
    v_3149 = v_3152;
    v_3149 = qcar(v_3149);
    v_3149 = (consp(v_3149) ? nil : lisp_true);
    goto v_3121;
    v_3149 = nil;
v_3121:
    if (v_3149 == nil) goto v_3119;
    goto v_3136;
v_3132:
    v_3149 = v_3152;
    goto v_3133;
v_3134:
    v_3150 = v_3151;
    goto v_3135;
v_3136:
    goto v_3132;
v_3133:
    goto v_3134;
v_3135:
    {
        fn = elt(env, 3); // quotdd
        return (*qfn2(fn))(fn, v_3149, v_3150);
    }
v_3119:
    goto v_3146;
v_3142:
    v_3149 = v_3152;
    goto v_3143;
v_3144:
    v_3150 = v_3151;
    goto v_3145;
v_3146:
    goto v_3142;
v_3143:
    goto v_3144;
v_3145:
    {
        fn = elt(env, 4); // quotk
        return (*qfn2(fn))(fn, v_3149, v_3150);
    }
    v_3149 = nil;
v_3095:
    return onevalue(v_3149);
}



// Code for downwght

static LispObject CC_downwght(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3106, v_3107;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3092;
    stack[-1] = v_3091;
// end of prologue
    v_3106 = stack[-1];
    fn = elt(env, 1); // delhisto
    v_3106 = (*qfn1(fn))(fn, v_3106);
    env = stack[-2];
    goto v_3101;
v_3097:
    v_3107 = stack[-1];
    goto v_3098;
v_3099:
    v_3106 = stack[0];
    goto v_3100;
v_3101:
    goto v_3097;
v_3098:
    goto v_3099;
v_3100:
    fn = elt(env, 2); // downwght1
    v_3106 = (*qfn2(fn))(fn, v_3107, v_3106);
    env = stack[-2];
    v_3106 = stack[-1];
    {
        fn = elt(env, 3); // inshisto
        return (*qfn1(fn))(fn, v_3106);
    }
}



// Code for freexp

static LispObject CC_freexp(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3111;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_3091;
// end of prologue
v_3090:
    v_3111 = stack[0];
    if (!consp(v_3111)) goto v_3095;
    else goto v_3096;
v_3095:
    v_3111 = stack[0];
    {
        fn = elt(env, 1); // pm!:free
        return (*qfn1(fn))(fn, v_3111);
    }
v_3096:
    v_3111 = stack[0];
    v_3111 = qcar(v_3111);
    v_3111 = CC_freexp(elt(env, 0), v_3111);
    env = stack[-1];
    if (v_3111 == nil) goto v_3104;
    else goto v_3103;
v_3104:
    v_3111 = stack[0];
    v_3111 = qcdr(v_3111);
    stack[0] = v_3111;
    goto v_3090;
v_3103:
    goto v_3094;
    v_3111 = nil;
v_3094:
    return onevalue(v_3111);
}



// Code for prepd

static LispObject CC_prepd(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3172, v_3173;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3091;
// end of prologue
    v_3172 = stack[0];
    if (!consp(v_3172)) goto v_3095;
    else goto v_3096;
v_3095:
    goto v_3107;
v_3103:
    v_3173 = stack[0];
    goto v_3104;
v_3105:
    v_3172 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3106;
v_3107:
    goto v_3103;
v_3104:
    goto v_3105;
v_3106:
    v_3172 = (LispObject)lessp2(v_3173, v_3172);
    v_3172 = v_3172 ? lisp_true : nil;
    env = stack[-2];
    if (v_3172 == nil) goto v_3101;
    goto v_3115;
v_3111:
    stack[-1] = elt(env, 1); // minus
    goto v_3112;
v_3113:
    v_3172 = stack[0];
    v_3172 = negate(v_3172);
    goto v_3114;
v_3115:
    goto v_3111;
v_3112:
    goto v_3113;
v_3114:
    {
        LispObject v_3176 = stack[-1];
        return list2(v_3176, v_3172);
    }
v_3101:
    v_3172 = stack[0];
    goto v_3099;
    v_3172 = nil;
v_3099:
    goto v_3094;
v_3096:
    goto v_3129;
v_3125:
    v_3172 = stack[0];
    v_3172 = qcar(v_3172);
    if (!symbolp(v_3172)) v_3173 = nil;
    else { v_3173 = qfastgets(v_3172);
           if (v_3173 != nil) { v_3173 = elt(v_3173, 30); // minusp
#ifdef RECORD_GET
             if (v_3173 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v_3173 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v_3173 == SPID_NOPROP) v_3173 = nil; }}
#endif
    goto v_3126;
v_3127:
    v_3172 = stack[0];
    goto v_3128;
v_3129:
    goto v_3125;
v_3126:
    goto v_3127;
v_3128:
    v_3172 = Lapply1(nil, v_3173, v_3172);
    env = stack[-2];
    if (v_3172 == nil) goto v_3123;
    v_3172 = stack[0];
    fn = elt(env, 3); // !:minus
    v_3172 = (*qfn1(fn))(fn, v_3172);
    env = stack[-2];
    fn = elt(env, 4); // prepd1
    v_3172 = (*qfn1(fn))(fn, v_3172);
    env = stack[-2];
    v_3173 = v_3172;
    v_3172 = v_3173;
    if (v_3172 == nil) goto v_3140;
    else goto v_3141;
v_3140:
    v_3172 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3139;
v_3141:
    goto v_3151;
v_3147:
    v_3172 = elt(env, 1); // minus
    goto v_3148;
v_3149:
    goto v_3150;
v_3151:
    goto v_3147;
v_3148:
    goto v_3149;
v_3150:
    return list2(v_3172, v_3173);
    v_3172 = nil;
v_3139:
    goto v_3094;
v_3123:
    goto v_3161;
v_3157:
    goto v_3167;
v_3163:
    v_3172 = stack[0];
    v_3173 = qcar(v_3172);
    goto v_3164;
v_3165:
    v_3172 = elt(env, 2); // prepfn
    goto v_3166;
v_3167:
    goto v_3163;
v_3164:
    goto v_3165;
v_3166:
    v_3173 = get(v_3173, v_3172);
    goto v_3158;
v_3159:
    v_3172 = stack[0];
    goto v_3160;
v_3161:
    goto v_3157;
v_3158:
    goto v_3159;
v_3160:
        return Lapply1(nil, v_3173, v_3172);
    v_3172 = nil;
v_3094:
    return onevalue(v_3172);
}



// Code for diplength

static LispObject CC_diplength(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3134, v_3135;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3091;
// end of prologue
    stack[-1] = nil;
v_3097:
    v_3134 = stack[0];
    if (v_3134 == nil) goto v_3102;
    else goto v_3103;
v_3102:
    goto v_3098;
v_3103:
    goto v_3110;
v_3106:
    v_3135 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3107;
v_3108:
    v_3134 = stack[-1];
    goto v_3109;
v_3110:
    goto v_3106;
v_3107:
    goto v_3108;
v_3109:
    v_3134 = cons(v_3135, v_3134);
    env = stack[-2];
    stack[-1] = v_3134;
    v_3134 = stack[0];
    v_3134 = qcdr(v_3134);
    v_3134 = qcdr(v_3134);
    stack[0] = v_3134;
    goto v_3097;
v_3098:
    v_3134 = (LispObject)0+TAG_FIXNUM; // 0
    v_3135 = v_3134;
v_3099:
    v_3134 = stack[-1];
    if (v_3134 == nil) goto v_3119;
    else goto v_3120;
v_3119:
    v_3134 = v_3135;
    goto v_3096;
v_3120:
    goto v_3128;
v_3124:
    v_3134 = stack[-1];
    v_3134 = qcar(v_3134);
    goto v_3125;
v_3126:
    goto v_3127;
v_3128:
    goto v_3124;
v_3125:
    goto v_3126;
v_3127:
    v_3134 = plus2(v_3134, v_3135);
    env = stack[-2];
    v_3135 = v_3134;
    v_3134 = stack[-1];
    v_3134 = qcdr(v_3134);
    stack[-1] = v_3134;
    goto v_3099;
v_3096:
    return onevalue(v_3134);
}



// Code for quotematrix

static LispObject CC_quotematrix(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3094;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3094 = v_3091;
// end of prologue
    v_3094 = elt(env, 1); // matrix
    return onevalue(v_3094);
}



// Code for deg!*farg

static LispObject CC_degHfarg(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3133, v_3134;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_3134 = v_3091;
// end of prologue
    v_3133 = v_3134;
    v_3133 = qcdr(v_3133);
    if (v_3133 == nil) goto v_3095;
    else goto v_3096;
v_3095:
    v_3133 = v_3134;
    v_3133 = qcar(v_3133);
    {
        fn = elt(env, 1); // deg!*form
        return (*qfn1(fn))(fn, v_3133);
    }
v_3096:
    stack[-1] = nil;
    v_3133 = v_3134;
    stack[0] = v_3133;
v_3110:
    v_3133 = stack[0];
    if (v_3133 == nil) goto v_3114;
    else goto v_3115;
v_3114:
    goto v_3109;
v_3115:
    v_3133 = stack[0];
    v_3133 = qcar(v_3133);
    goto v_3126;
v_3122:
    fn = elt(env, 1); // deg!*form
    v_3134 = (*qfn1(fn))(fn, v_3133);
    env = stack[-2];
    goto v_3123;
v_3124:
    v_3133 = stack[-1];
    goto v_3125;
v_3126:
    goto v_3122;
v_3123:
    goto v_3124;
v_3125:
    fn = elt(env, 2); // addf
    v_3133 = (*qfn2(fn))(fn, v_3134, v_3133);
    env = stack[-2];
    stack[-1] = v_3133;
    v_3133 = stack[0];
    v_3133 = qcdr(v_3133);
    stack[0] = v_3133;
    goto v_3110;
v_3109:
    v_3133 = stack[-1];
    goto v_3094;
    v_3133 = nil;
v_3094:
    return onevalue(v_3133);
}



// Code for round!:mt

static LispObject CC_roundTmt(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3214, v_3215;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_3092;
    stack[-2] = v_3091;
// end of prologue
    goto v_3111;
v_3107:
    v_3215 = stack[-2];
    goto v_3108;
v_3109:
    v_3214 = elt(env, 1); // !:rd!:
    goto v_3110;
v_3111:
    goto v_3107;
v_3108:
    goto v_3109;
v_3110:
    if (!consp(v_3215)) goto v_3105;
    v_3215 = qcar(v_3215);
    if (v_3215 == v_3214) goto v_3104;
    else goto v_3105;
v_3104:
    v_3214 = stack[-2];
    v_3214 = qcdr(v_3214);
    v_3214 = (consp(v_3214) ? nil : lisp_true);
    v_3214 = (v_3214 == nil ? lisp_true : nil);
    goto v_3103;
v_3105:
    v_3214 = nil;
    goto v_3103;
    v_3214 = nil;
v_3103:
    if (v_3214 == nil) goto v_3101;
    v_3214 = stack[-1];
    v_3214 = integerp(v_3214);
    if (v_3214 == nil) goto v_3123;
    else goto v_3124;
v_3123:
    v_3214 = nil;
    goto v_3122;
v_3124:
    goto v_3135;
v_3131:
    v_3215 = stack[-1];
    goto v_3132;
v_3133:
    v_3214 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3134;
v_3135:
    goto v_3131;
v_3132:
    goto v_3133;
v_3134:
    v_3214 = (LispObject)greaterp2(v_3215, v_3214);
    v_3214 = v_3214 ? lisp_true : nil;
    env = stack[-4];
    goto v_3122;
    v_3214 = nil;
v_3122:
    goto v_3099;
v_3101:
    v_3214 = nil;
    goto v_3099;
    v_3214 = nil;
v_3099:
    if (v_3214 == nil) goto v_3097;
    goto v_3150;
v_3146:
    goto v_3157;
v_3153:
    v_3214 = stack[-2];
    v_3214 = qcdr(v_3214);
    v_3214 = qcar(v_3214);
    v_3214 = Labsval(nil, v_3214);
    env = stack[-4];
    fn = elt(env, 2); // msd
    v_3215 = (*qfn1(fn))(fn, v_3214);
    env = stack[-4];
    goto v_3154;
v_3155:
    v_3214 = stack[-1];
    goto v_3156;
v_3157:
    goto v_3153;
v_3154:
    goto v_3155;
v_3156:
    v_3214 = difference2(v_3215, v_3214);
    env = stack[-4];
    v_3215 = sub1(v_3214);
    env = stack[-4];
    stack[-1] = v_3215;
    goto v_3147;
v_3148:
    v_3214 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3149;
v_3150:
    goto v_3146;
v_3147:
    goto v_3148;
v_3149:
    v_3214 = (LispObject)lessp2(v_3215, v_3214);
    v_3214 = v_3214 ? lisp_true : nil;
    env = stack[-4];
    if (v_3214 == nil) goto v_3144;
    v_3214 = stack[-2];
    goto v_3142;
v_3144:
    goto v_3172;
v_3168:
    v_3215 = stack[-1];
    goto v_3169;
v_3170:
    v_3214 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3171;
v_3172:
    goto v_3168;
v_3169:
    goto v_3170;
v_3171:
    if (v_3215 == v_3214) goto v_3166;
    else goto v_3167;
v_3166:
    v_3214 = stack[-2];
    {
        fn = elt(env, 3); // round!:last
        return (*qfn1(fn))(fn, v_3214);
    }
v_3167:
    goto v_3187;
v_3181:
    stack[-3] = elt(env, 1); // !:rd!:
    goto v_3182;
v_3183:
    goto v_3194;
v_3190:
    v_3214 = stack[-2];
    v_3214 = qcdr(v_3214);
    stack[0] = qcar(v_3214);
    goto v_3191;
v_3192:
    v_3214 = stack[-1];
    v_3214 = negate(v_3214);
    env = stack[-4];
    goto v_3193;
v_3194:
    goto v_3190;
v_3191:
    goto v_3192;
v_3193:
    fn = elt(env, 4); // ashift
    stack[0] = (*qfn2(fn))(fn, stack[0], v_3214);
    env = stack[-4];
    goto v_3184;
v_3185:
    goto v_3205;
v_3201:
    v_3214 = stack[-2];
    v_3214 = qcdr(v_3214);
    v_3215 = qcdr(v_3214);
    goto v_3202;
v_3203:
    v_3214 = stack[-1];
    goto v_3204;
v_3205:
    goto v_3201;
v_3202:
    goto v_3203;
v_3204:
    v_3214 = plus2(v_3215, v_3214);
    env = stack[-4];
    goto v_3186;
v_3187:
    goto v_3181;
v_3182:
    goto v_3183;
v_3184:
    goto v_3185;
v_3186:
    v_3214 = list2star(stack[-3], stack[0], v_3214);
    env = stack[-4];
    {
        fn = elt(env, 3); // round!:last
        return (*qfn1(fn))(fn, v_3214);
    }
    v_3214 = nil;
v_3142:
    goto v_3095;
v_3097:
    v_3214 = elt(env, 0); // round!:mt
    {
        fn = elt(env, 5); // bflerrmsg
        return (*qfn1(fn))(fn, v_3214);
    }
    v_3214 = nil;
v_3095:
    return onevalue(v_3214);
}



// Code for gizerop!:

static LispObject CC_gizeropT(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3119, v_3120, v_3121;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3120 = v_3091;
// end of prologue
    goto v_3101;
v_3097:
    v_3119 = v_3120;
    v_3119 = qcdr(v_3119);
    v_3121 = qcar(v_3119);
    goto v_3098;
v_3099:
    v_3119 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3100;
v_3101:
    goto v_3097;
v_3098:
    goto v_3099;
v_3100:
    if (v_3121 == v_3119) goto v_3095;
    else goto v_3096;
v_3095:
    goto v_3110;
v_3106:
    v_3119 = v_3120;
    v_3119 = qcdr(v_3119);
    v_3120 = qcdr(v_3119);
    goto v_3107;
v_3108:
    v_3119 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3109;
v_3110:
    goto v_3106;
v_3107:
    goto v_3108;
v_3109:
    v_3119 = (v_3120 == v_3119 ? lisp_true : nil);
    goto v_3094;
v_3096:
    v_3119 = nil;
    goto v_3094;
    v_3119 = nil;
v_3094:
    return onevalue(v_3119);
}



// Code for red!-char!-downcase

static LispObject CC_redKcharKdowncase(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3112, v_3113, v_3114;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3113 = v_3091;
// end of prologue
    goto v_3097;
v_3093:
    v_3112 = v_3113;
    goto v_3094;
v_3095:
    v_3114 = qvalue(elt(env, 1)); // charassoc!*
    goto v_3096;
v_3097:
    goto v_3093;
v_3094:
    goto v_3095;
v_3096:
    v_3112 = Latsoc(nil, v_3112, v_3114);
    v_3114 = v_3112;
    v_3112 = v_3114;
    if (v_3112 == nil) goto v_3105;
    v_3112 = v_3114;
    v_3112 = qcdr(v_3112);
    goto v_3103;
v_3105:
    v_3112 = v_3113;
    goto v_3103;
    v_3112 = nil;
v_3103:
    return onevalue(v_3112);
}



// Code for repeatsp

static LispObject CC_repeatsp(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3117, v_3118, v_3119;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3118 = v_3091;
// end of prologue
v_3090:
    v_3117 = v_3118;
    if (v_3117 == nil) goto v_3095;
    else goto v_3096;
v_3095:
    v_3117 = nil;
    goto v_3094;
v_3096:
    goto v_3108;
v_3104:
    v_3117 = v_3118;
    v_3119 = qcar(v_3117);
    goto v_3105;
v_3106:
    v_3117 = v_3118;
    v_3117 = qcdr(v_3117);
    goto v_3107;
v_3108:
    goto v_3104;
v_3105:
    goto v_3106;
v_3107:
    v_3117 = Lmember(nil, v_3119, v_3117);
    if (v_3117 == nil) goto v_3103;
    else goto v_3102;
v_3103:
    v_3117 = v_3118;
    v_3117 = qcdr(v_3117);
    v_3118 = v_3117;
    goto v_3090;
v_3102:
    goto v_3094;
    v_3117 = nil;
v_3094:
    return onevalue(v_3117);
}



// Code for macrochk

static LispObject CC_macrochk(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3164, v_3165, v_3166, v_3167;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3092;
    stack[-1] = v_3091;
// end of prologue
    v_3164 = stack[-1];
    if (!consp(v_3164)) goto v_3099;
    else goto v_3100;
v_3099:
    v_3164 = stack[-1];
    goto v_3096;
v_3100:
    v_3164 = stack[-1];
    v_3164 = qcar(v_3164);
    fn = elt(env, 3); // expdrmacro
    v_3164 = (*qfn1(fn))(fn, v_3164);
    env = stack[-2];
    v_3165 = v_3164;
    if (v_3164 == nil) goto v_3104;
    goto v_3118;
v_3114:
    v_3166 = stack[0];
    goto v_3115;
v_3116:
    v_3164 = elt(env, 1); // symbolic
    goto v_3117;
v_3118:
    goto v_3114;
v_3115:
    goto v_3116;
v_3117:
    if (v_3166 == v_3164) goto v_3112;
    else goto v_3113;
v_3112:
    v_3164 = lisp_true;
    goto v_3111;
v_3113:
    v_3164 = stack[-1];
    v_3164 = qcar(v_3164);
    if (symbolp(v_3164)) goto v_3127;
    v_3164 = nil;
    goto v_3125;
v_3127:
    v_3164 = stack[-1];
    v_3164 = qcar(v_3164);
    if (!symbolp(v_3164)) v_3164 = nil;
    else { v_3164 = qfastgets(v_3164);
           if (v_3164 != nil) { v_3164 = elt(v_3164, 59); // opfn
#ifdef RECORD_GET
             if (v_3164 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v_3164 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v_3164 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v_3164 == SPID_NOPROP) v_3164 = nil; else v_3164 = lisp_true; }}
#endif
    goto v_3125;
    v_3164 = nil;
v_3125:
    goto v_3111;
    v_3164 = nil;
v_3111:
    if (v_3164 == nil) goto v_3104;
    goto v_3145;
v_3137:
    goto v_3151;
v_3147:
    v_3164 = v_3165;
    v_3166 = qcar(v_3164);
    goto v_3148;
v_3149:
    v_3164 = elt(env, 2); // macrofn
    goto v_3150;
v_3151:
    goto v_3147;
v_3148:
    goto v_3149;
v_3150:
    v_3167 = get(v_3166, v_3164);
    goto v_3138;
v_3139:
    v_3164 = v_3165;
    v_3166 = qcdr(v_3164);
    goto v_3140;
v_3141:
    v_3164 = stack[-1];
    v_3165 = qcdr(v_3164);
    goto v_3142;
v_3143:
    v_3164 = stack[-1];
    v_3164 = qcar(v_3164);
    goto v_3144;
v_3145:
    goto v_3137;
v_3138:
    goto v_3139;
v_3140:
    goto v_3141;
v_3142:
    goto v_3143;
v_3144:
        return Lapply3(nil, 4, v_3167, v_3166, v_3165, v_3164);
v_3104:
    v_3164 = stack[-1];
    goto v_3096;
    v_3164 = nil;
v_3096:
    return onevalue(v_3164);
}



// Code for red_divtestbe

static LispObject CC_red_divtestbe(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3135, v_3136;
    LispObject fn;
    LispObject v_3093, v_3092, v_3091;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "red_divtestbe");
    va_start(aa, nargs);
    v_3091 = va_arg(aa, LispObject);
    v_3092 = va_arg(aa, LispObject);
    v_3093 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_3093,v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_3091,v_3092,v_3093);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3093;
    stack[-1] = v_3092;
    stack[-2] = v_3091;
// end of prologue
v_3097:
    v_3135 = stack[-2];
    if (v_3135 == nil) goto v_3100;
    else goto v_3101;
v_3100:
    v_3135 = nil;
    goto v_3096;
v_3101:
    goto v_3112;
v_3108:
    v_3135 = stack[-2];
    v_3135 = qcar(v_3135);
    fn = elt(env, 1); // bas_dpecart
    v_3136 = (*qfn1(fn))(fn, v_3135);
    env = stack[-3];
    goto v_3109;
v_3110:
    v_3135 = stack[0];
    goto v_3111;
v_3112:
    goto v_3108;
v_3109:
    goto v_3110;
v_3111:
    v_3135 = (LispObject)lesseq2(v_3136, v_3135);
    v_3135 = v_3135 ? lisp_true : nil;
    env = stack[-3];
    if (v_3135 == nil) goto v_3105;
    goto v_3123;
v_3119:
    v_3135 = stack[-2];
    v_3135 = qcar(v_3135);
    fn = elt(env, 2); // bas_dpoly
    v_3135 = (*qfn1(fn))(fn, v_3135);
    env = stack[-3];
    fn = elt(env, 3); // dp_lmon
    v_3136 = (*qfn1(fn))(fn, v_3135);
    env = stack[-3];
    goto v_3120;
v_3121:
    v_3135 = stack[-1];
    goto v_3122;
v_3123:
    goto v_3119;
v_3120:
    goto v_3121;
v_3122:
    fn = elt(env, 4); // mo_vdivides!?
    v_3135 = (*qfn2(fn))(fn, v_3136, v_3135);
    env = stack[-3];
    if (v_3135 == nil) goto v_3105;
    v_3135 = stack[-2];
    v_3135 = qcar(v_3135);
    goto v_3096;
v_3105:
    v_3135 = stack[-2];
    v_3135 = qcdr(v_3135);
    stack[-2] = v_3135;
    goto v_3097;
    v_3135 = nil;
v_3096:
    return onevalue(v_3135);
}



// Code for resimp1

static LispObject CC_resimp1(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3121, v_3122;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3091;
// end of prologue
    goto v_3100;
v_3096:
    goto v_3106;
v_3102:
    v_3121 = stack[0];
    v_3122 = qcar(v_3121);
    goto v_3103;
v_3104:
    v_3121 = nil;
    goto v_3105;
v_3106:
    goto v_3102;
v_3103:
    goto v_3104;
v_3105:
    fn = elt(env, 2); // subf1
    stack[-1] = (*qfn2(fn))(fn, v_3122, v_3121);
    env = stack[-2];
    goto v_3097;
v_3098:
    goto v_3115;
v_3111:
    v_3121 = stack[0];
    v_3122 = qcdr(v_3121);
    goto v_3112;
v_3113:
    v_3121 = nil;
    goto v_3114;
v_3115:
    goto v_3111;
v_3112:
    goto v_3113;
v_3114:
    fn = elt(env, 2); // subf1
    v_3121 = (*qfn2(fn))(fn, v_3122, v_3121);
    env = stack[-2];
    goto v_3099;
v_3100:
    goto v_3096;
v_3097:
    goto v_3098;
v_3099:
    fn = elt(env, 3); // quotsq
    v_3121 = (*qfn2(fn))(fn, stack[-1], v_3121);
    env = stack[-2];
    stack[0] = v_3121;
    v_3121 = lisp_true;
    qvalue(elt(env, 1)) = v_3121; // !*sub2
    v_3121 = stack[0];
    return onevalue(v_3121);
}



// Code for pappl_pv

static LispObject CC_pappl_pv(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3167, v_3168;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_3167 = v_3092;
    stack[-4] = v_3091;
// end of prologue
    stack[-5] = v_3167;
    v_3167 = stack[-5];
    if (v_3167 == nil) goto v_3104;
    else goto v_3105;
v_3104:
    v_3167 = nil;
    goto v_3099;
v_3105:
    v_3167 = stack[-5];
    v_3167 = qcar(v_3167);
    goto v_3117;
v_3113:
    v_3168 = v_3167;
    stack[0] = qcar(v_3168);
    goto v_3114;
v_3115:
    goto v_3125;
v_3121:
    v_3168 = stack[-4];
    goto v_3122;
v_3123:
    v_3167 = qcdr(v_3167);
    goto v_3124;
v_3125:
    goto v_3121;
v_3122:
    goto v_3123;
v_3124:
    fn = elt(env, 1); // pappl0
    v_3167 = (*qfn2(fn))(fn, v_3168, v_3167);
    env = stack[-6];
    goto v_3116;
v_3117:
    goto v_3113;
v_3114:
    goto v_3115;
v_3116:
    v_3167 = cons(stack[0], v_3167);
    env = stack[-6];
    v_3167 = ncons(v_3167);
    env = stack[-6];
    stack[-2] = v_3167;
    stack[-3] = v_3167;
v_3100:
    v_3167 = stack[-5];
    v_3167 = qcdr(v_3167);
    stack[-5] = v_3167;
    v_3167 = stack[-5];
    if (v_3167 == nil) goto v_3133;
    else goto v_3134;
v_3133:
    v_3167 = stack[-3];
    goto v_3099;
v_3134:
    goto v_3142;
v_3138:
    stack[-1] = stack[-2];
    goto v_3139;
v_3140:
    v_3167 = stack[-5];
    v_3167 = qcar(v_3167);
    goto v_3153;
v_3149:
    v_3168 = v_3167;
    stack[0] = qcar(v_3168);
    goto v_3150;
v_3151:
    goto v_3161;
v_3157:
    v_3168 = stack[-4];
    goto v_3158;
v_3159:
    v_3167 = qcdr(v_3167);
    goto v_3160;
v_3161:
    goto v_3157;
v_3158:
    goto v_3159;
v_3160:
    fn = elt(env, 1); // pappl0
    v_3167 = (*qfn2(fn))(fn, v_3168, v_3167);
    env = stack[-6];
    goto v_3152;
v_3153:
    goto v_3149;
v_3150:
    goto v_3151;
v_3152:
    v_3167 = cons(stack[0], v_3167);
    env = stack[-6];
    v_3167 = ncons(v_3167);
    env = stack[-6];
    goto v_3141;
v_3142:
    goto v_3138;
v_3139:
    goto v_3140;
v_3141:
    v_3167 = Lrplacd(nil, stack[-1], v_3167);
    env = stack[-6];
    v_3167 = stack[-2];
    v_3167 = qcdr(v_3167);
    stack[-2] = v_3167;
    goto v_3100;
v_3099:
    {
        fn = elt(env, 2); // pv_sort
        return (*qfn1(fn))(fn, v_3167);
    }
}



// Code for !*modular2f

static LispObject CC_Hmodular2f(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3191, v_3192;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3091;
// end of prologue
v_3095:
    goto v_3104;
v_3100:
    v_3192 = stack[0];
    goto v_3101;
v_3102:
    v_3191 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3103;
v_3104:
    goto v_3100;
v_3101:
    goto v_3102;
v_3103:
    if (v_3192 == v_3191) goto v_3098;
    else goto v_3099;
v_3098:
    v_3191 = nil;
    goto v_3094;
v_3099:
    v_3191 = qvalue(elt(env, 1)); // !*balanced_mod
    if (v_3191 == nil) goto v_3109;
    goto v_3120;
v_3116:
    goto v_3126;
v_3122:
    v_3192 = stack[0];
    goto v_3123;
v_3124:
    v_3191 = stack[0];
    goto v_3125;
v_3126:
    goto v_3122;
v_3123:
    goto v_3124;
v_3125:
    v_3192 = plus2(v_3192, v_3191);
    env = stack[-2];
    goto v_3117;
v_3118:
    v_3191 = qvalue(elt(env, 2)); // current!-modulus
    goto v_3119;
v_3120:
    goto v_3116;
v_3117:
    goto v_3118;
v_3119:
    v_3191 = (LispObject)greaterp2(v_3192, v_3191);
    v_3191 = v_3191 ? lisp_true : nil;
    env = stack[-2];
    if (v_3191 == nil) goto v_3114;
    goto v_3135;
v_3131:
    stack[-1] = elt(env, 3); // !:mod!:
    goto v_3132;
v_3133:
    goto v_3142;
v_3138:
    v_3192 = stack[0];
    goto v_3139;
v_3140:
    v_3191 = qvalue(elt(env, 2)); // current!-modulus
    goto v_3141;
v_3142:
    goto v_3138;
v_3139:
    goto v_3140;
v_3141:
    v_3191 = difference2(v_3192, v_3191);
    goto v_3134;
v_3135:
    goto v_3131;
v_3132:
    goto v_3133;
v_3134:
    {
        LispObject v_3195 = stack[-1];
        return cons(v_3195, v_3191);
    }
v_3114:
    goto v_3152;
v_3148:
    goto v_3158;
v_3154:
    v_3192 = stack[0];
    goto v_3155;
v_3156:
    v_3191 = stack[0];
    goto v_3157;
v_3158:
    goto v_3154;
v_3155:
    goto v_3156;
v_3157:
    stack[-1] = plus2(v_3192, v_3191);
    env = stack[-2];
    goto v_3149;
v_3150:
    v_3191 = qvalue(elt(env, 2)); // current!-modulus
    v_3191 = negate(v_3191);
    env = stack[-2];
    goto v_3151;
v_3152:
    goto v_3148;
v_3149:
    goto v_3150;
v_3151:
    v_3191 = (LispObject)lesseq2(stack[-1], v_3191);
    v_3191 = v_3191 ? lisp_true : nil;
    env = stack[-2];
    if (v_3191 == nil) goto v_3146;
    goto v_3168;
v_3164:
    v_3192 = stack[0];
    goto v_3165;
v_3166:
    v_3191 = qvalue(elt(env, 2)); // current!-modulus
    goto v_3167;
v_3168:
    goto v_3164;
v_3165:
    goto v_3166;
v_3167:
    v_3191 = plus2(v_3192, v_3191);
    env = stack[-2];
    stack[0] = v_3191;
    goto v_3095;
v_3146:
    goto v_3178;
v_3174:
    v_3192 = elt(env, 3); // !:mod!:
    goto v_3175;
v_3176:
    v_3191 = stack[0];
    goto v_3177;
v_3178:
    goto v_3174;
v_3175:
    goto v_3176;
v_3177:
    return cons(v_3192, v_3191);
    goto v_3097;
v_3109:
    goto v_3188;
v_3184:
    v_3192 = elt(env, 3); // !:mod!:
    goto v_3185;
v_3186:
    v_3191 = stack[0];
    goto v_3187;
v_3188:
    goto v_3184;
v_3185:
    goto v_3186;
v_3187:
    return cons(v_3192, v_3191);
v_3097:
    v_3191 = nil;
v_3094:
    return onevalue(v_3191);
}



// Code for exptmod!:

static LispObject CC_exptmodT(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3104, v_3105;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_3104 = v_3092;
    v_3105 = v_3091;
// end of prologue
    goto v_3100;
v_3096:
    v_3105 = qcdr(v_3105);
    goto v_3097;
v_3098:
    goto v_3099;
v_3100:
    goto v_3096;
v_3097:
    goto v_3098;
v_3099:
    fn = elt(env, 1); // general!-modular!-expt
    v_3104 = (*qfn2(fn))(fn, v_3105, v_3104);
    env = stack[0];
    {
        fn = elt(env, 2); // !*modular2f
        return (*qfn1(fn))(fn, v_3104);
    }
}



// Code for lalr_add_goto

static LispObject CC_lalr_add_goto(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3123, v_3124, v_3125;
    LispObject fn;
    LispObject v_3093, v_3092, v_3091;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "lalr_add_goto");
    va_start(aa, nargs);
    v_3091 = va_arg(aa, LispObject);
    v_3092 = va_arg(aa, LispObject);
    v_3093 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_3093,v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_3091,v_3092,v_3093);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_3123 = v_3093;
    v_3124 = v_3092;
    v_3125 = v_3091;
// end of prologue
    goto v_3102;
v_3096:
    stack[-3] = v_3124;
    goto v_3097;
v_3098:
    stack[-2] = qvalue(elt(env, 1)); // goto_table
    goto v_3099;
v_3100:
    goto v_3112;
v_3106:
    stack[-1] = v_3125;
    goto v_3107;
v_3108:
    stack[0] = v_3123;
    goto v_3109;
v_3110:
    goto v_3120;
v_3116:
    goto v_3117;
v_3118:
    v_3123 = qvalue(elt(env, 1)); // goto_table
    goto v_3119;
v_3120:
    goto v_3116;
v_3117:
    goto v_3118;
v_3119:
    fn = elt(env, 2); // gethash
    v_3123 = (*qfn2(fn))(fn, v_3124, v_3123);
    env = stack[-4];
    goto v_3111;
v_3112:
    goto v_3106;
v_3107:
    goto v_3108;
v_3109:
    goto v_3110;
v_3111:
    v_3123 = acons(stack[-1], stack[0], v_3123);
    env = stack[-4];
    goto v_3101;
v_3102:
    goto v_3096;
v_3097:
    goto v_3098;
v_3099:
    goto v_3100;
v_3101:
    {
        LispObject v_3130 = stack[-3];
        LispObject v_3131 = stack[-2];
        fn = elt(env, 3); // puthash
        return (*qfnn(fn))(fn, 3, v_3130, v_3131, v_3123);
    }
}



// Code for procstat

static LispObject CC_procstat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3094;
    LispObject fn;
    argcheck(nargs, 0, "procstat");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_3094 = nil;
    {
        fn = elt(env, 1); // procstat1
        return (*qfn1(fn))(fn, v_3094);
    }
}



// Code for sfto_gcdf

static LispObject CC_sfto_gcdf(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3147, v_3148;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3092;
    stack[-1] = v_3091;
// end of prologue
    v_3147 = qvalue(elt(env, 1)); // !*rldavgcd
    if (v_3147 == nil) goto v_3096;
    else goto v_3097;
v_3096:
    goto v_3104;
v_3100:
    v_3148 = stack[-1];
    goto v_3101;
v_3102:
    v_3147 = stack[0];
    goto v_3103;
v_3104:
    goto v_3100;
v_3101:
    goto v_3102;
v_3103:
    {
        fn = elt(env, 3); // gcdf
        return (*qfn2(fn))(fn, v_3148, v_3147);
    }
v_3097:
    goto v_3115;
v_3111:
    v_3148 = stack[-1];
    goto v_3112;
v_3113:
    v_3147 = nil;
    goto v_3114;
v_3115:
    goto v_3111;
v_3112:
    goto v_3113;
v_3114:
    fn = elt(env, 4); // sfto_davp
    v_3147 = (*qfn2(fn))(fn, v_3148, v_3147);
    env = stack[-3];
    if (v_3147 == nil) goto v_3109;
    else goto v_3107;
v_3109:
    goto v_3124;
v_3120:
    v_3148 = stack[0];
    goto v_3121;
v_3122:
    v_3147 = nil;
    goto v_3123;
v_3124:
    goto v_3120;
v_3121:
    goto v_3122;
v_3123:
    fn = elt(env, 4); // sfto_davp
    v_3147 = (*qfn2(fn))(fn, v_3148, v_3147);
    env = stack[-3];
    if (v_3147 == nil) goto v_3118;
    else goto v_3107;
v_3118:
    goto v_3108;
v_3107:
    v_3147 = nil;
// Binding !*ezgcd
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 2, -2);
    qvalue(elt(env, 2)) = v_3147; // !*ezgcd
    goto v_3134;
v_3130:
    v_3148 = stack[-1];
    goto v_3131;
v_3132:
    v_3147 = stack[0];
    goto v_3133;
v_3134:
    goto v_3130;
v_3131:
    goto v_3132;
v_3133:
    fn = elt(env, 3); // gcdf
    v_3147 = (*qfn2(fn))(fn, v_3148, v_3147);
    ;}  // end of a binding scope
    goto v_3095;
v_3108:
    goto v_3144;
v_3140:
    v_3148 = stack[-1];
    goto v_3141;
v_3142:
    v_3147 = stack[0];
    goto v_3143;
v_3144:
    goto v_3140;
v_3141:
    goto v_3142;
v_3143:
    {
        fn = elt(env, 5); // ezgcdf
        return (*qfn2(fn))(fn, v_3148, v_3147);
    }
    v_3147 = nil;
v_3095:
    return onevalue(v_3147);
}



// Code for gcdf1

static LispObject CC_gcdf1(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3301, v_3302;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_3092;
    stack[-2] = v_3091;
// end of prologue
    v_3301 = stack[-2];
    if (v_3301 == nil) goto v_3099;
    else goto v_3100;
v_3099:
    v_3301 = stack[-1];
    goto v_3096;
v_3100:
    v_3301 = stack[-1];
    if (v_3301 == nil) goto v_3103;
    else goto v_3104;
v_3103:
    v_3301 = stack[-2];
    goto v_3096;
v_3104:
    goto v_3117;
v_3113:
    v_3302 = stack[-2];
    goto v_3114;
v_3115:
    v_3301 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3116;
v_3117:
    goto v_3113;
v_3114:
    goto v_3115;
v_3116:
    if (v_3302 == v_3301) goto v_3111;
    else goto v_3112;
v_3111:
    v_3301 = lisp_true;
    goto v_3110;
v_3112:
    goto v_3127;
v_3123:
    v_3302 = stack[-1];
    goto v_3124;
v_3125:
    v_3301 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3126;
v_3127:
    goto v_3123;
v_3124:
    goto v_3125;
v_3126:
    v_3301 = (v_3302 == v_3301 ? lisp_true : nil);
    goto v_3110;
    v_3301 = nil;
v_3110:
    if (v_3301 == nil) goto v_3108;
    v_3301 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3096;
v_3108:
    v_3301 = stack[-2];
    if (!consp(v_3301)) goto v_3136;
    else goto v_3137;
v_3136:
    v_3301 = lisp_true;
    goto v_3135;
v_3137:
    v_3301 = stack[-2];
    v_3301 = qcar(v_3301);
    v_3301 = (consp(v_3301) ? nil : lisp_true);
    goto v_3135;
    v_3301 = nil;
v_3135:
    if (v_3301 == nil) goto v_3133;
    goto v_3150;
v_3146:
    v_3302 = stack[-2];
    goto v_3147;
v_3148:
    v_3301 = stack[-1];
    goto v_3149;
v_3150:
    goto v_3146;
v_3147:
    goto v_3148;
v_3149:
    {
        fn = elt(env, 6); // gcdfd
        return (*qfn2(fn))(fn, v_3302, v_3301);
    }
v_3133:
    v_3301 = stack[-1];
    if (!consp(v_3301)) goto v_3157;
    else goto v_3158;
v_3157:
    v_3301 = lisp_true;
    goto v_3156;
v_3158:
    v_3301 = stack[-1];
    v_3301 = qcar(v_3301);
    v_3301 = (consp(v_3301) ? nil : lisp_true);
    goto v_3156;
    v_3301 = nil;
v_3156:
    if (v_3301 == nil) goto v_3154;
    goto v_3171;
v_3167:
    v_3302 = stack[-1];
    goto v_3168;
v_3169:
    v_3301 = stack[-2];
    goto v_3170;
v_3171:
    goto v_3167;
v_3168:
    goto v_3169;
v_3170:
    {
        fn = elt(env, 6); // gcdfd
        return (*qfn2(fn))(fn, v_3302, v_3301);
    }
v_3154:
    v_3301 = qvalue(elt(env, 1)); // !*anygcd
    if (v_3301 == nil) goto v_3178;
    else goto v_3179;
v_3178:
    v_3301 = lisp_true;
    goto v_3177;
v_3179:
    v_3301 = stack[-2];
    fn = elt(env, 7); // num!-exponents
    v_3301 = (*qfn1(fn))(fn, v_3301);
    env = stack[-4];
    if (v_3301 == nil) goto v_3186;
    else goto v_3187;
v_3186:
    v_3301 = lisp_true;
    goto v_3185;
v_3187:
    v_3301 = stack[-1];
    fn = elt(env, 7); // num!-exponents
    v_3301 = (*qfn1(fn))(fn, v_3301);
    env = stack[-4];
    v_3301 = (v_3301 == nil ? lisp_true : nil);
    goto v_3185;
    v_3301 = nil;
v_3185:
    goto v_3177;
    v_3301 = nil;
v_3177:
    if (v_3301 == nil) goto v_3175;
    v_3301 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3096;
v_3175:
    goto v_3204;
v_3200:
    v_3302 = stack[-2];
    goto v_3201;
v_3202:
    v_3301 = stack[-1];
    goto v_3203;
v_3204:
    goto v_3200;
v_3201:
    goto v_3202;
v_3203:
    fn = elt(env, 8); // quotf1
    v_3301 = (*qfn2(fn))(fn, v_3302, v_3301);
    env = stack[-4];
    if (v_3301 == nil) goto v_3198;
    v_3301 = stack[-1];
    goto v_3096;
v_3198:
    goto v_3215;
v_3211:
    v_3302 = stack[-1];
    goto v_3212;
v_3213:
    v_3301 = stack[-2];
    goto v_3214;
v_3215:
    goto v_3211;
v_3212:
    goto v_3213;
v_3214:
    fn = elt(env, 8); // quotf1
    v_3301 = (*qfn2(fn))(fn, v_3302, v_3301);
    env = stack[-4];
    if (v_3301 == nil) goto v_3209;
    v_3301 = stack[-2];
    goto v_3096;
v_3209:
    goto v_3224;
v_3220:
    v_3302 = stack[-2];
    goto v_3221;
v_3222:
    v_3301 = stack[-1];
    goto v_3223;
v_3224:
    goto v_3220;
v_3221:
    goto v_3222;
v_3223:
    fn = elt(env, 9); // gcdf2
    v_3301 = (*qfn2(fn))(fn, v_3302, v_3301);
    env = stack[-4];
    stack[-3] = v_3301;
    v_3301 = qvalue(elt(env, 2)); // !*gcd
    if (v_3301 == nil) goto v_3230;
    goto v_3242;
v_3238:
    v_3302 = qvalue(elt(env, 3)); // dmode!*
    goto v_3239;
v_3240:
    v_3301 = elt(env, 4); // (!:rd!: !:cr!:)
    goto v_3241;
v_3242:
    goto v_3238;
v_3239:
    goto v_3240;
v_3241:
    v_3301 = Lmemq(nil, v_3302, v_3301);
    if (v_3301 == nil) goto v_3236;
    else goto v_3237;
v_3236:
    goto v_3255;
v_3251:
    v_3302 = stack[-2];
    goto v_3252;
v_3253:
    v_3301 = stack[-3];
    goto v_3254;
v_3255:
    goto v_3251;
v_3252:
    goto v_3253;
v_3254:
    fn = elt(env, 8); // quotf1
    v_3301 = (*qfn2(fn))(fn, v_3302, v_3301);
    env = stack[-4];
    if (v_3301 == nil) goto v_3248;
    else goto v_3249;
v_3248:
    v_3301 = lisp_true;
    goto v_3247;
v_3249:
    goto v_3266;
v_3262:
    v_3302 = stack[-1];
    goto v_3263;
v_3264:
    v_3301 = stack[-3];
    goto v_3265;
v_3266:
    goto v_3262;
v_3263:
    goto v_3264;
v_3265:
    fn = elt(env, 8); // quotf1
    v_3301 = (*qfn2(fn))(fn, v_3302, v_3301);
    env = stack[-4];
    v_3301 = (v_3301 == nil ? lisp_true : nil);
    goto v_3247;
    v_3301 = nil;
v_3247:
    goto v_3235;
v_3237:
    v_3301 = nil;
    goto v_3235;
    v_3301 = nil;
v_3235:
    if (v_3301 == nil) goto v_3230;
    v_3301 = stack[-2];
    fn = elt(env, 10); // noncomfp
    v_3301 = (*qfn1(fn))(fn, v_3301);
    env = stack[-4];
    if (v_3301 == nil) goto v_3277;
    else goto v_3275;
v_3277:
    v_3301 = stack[-1];
    fn = elt(env, 10); // noncomfp
    v_3301 = (*qfn1(fn))(fn, v_3301);
    env = stack[-4];
    if (v_3301 == nil) goto v_3280;
    else goto v_3275;
v_3280:
    goto v_3276;
v_3275:
    v_3301 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3096;
v_3276:
    goto v_3294;
v_3288:
    stack[0] = elt(env, 5); // "gcdf failed"
    goto v_3289;
v_3290:
    v_3301 = stack[-2];
    fn = elt(env, 11); // prepf
    stack[-2] = (*qfn1(fn))(fn, v_3301);
    env = stack[-4];
    goto v_3291;
v_3292:
    v_3301 = stack[-1];
    fn = elt(env, 11); // prepf
    v_3301 = (*qfn1(fn))(fn, v_3301);
    env = stack[-4];
    goto v_3293;
v_3294:
    goto v_3288;
v_3289:
    goto v_3290;
v_3291:
    goto v_3292;
v_3293:
    v_3301 = list3(stack[0], stack[-2], v_3301);
    env = stack[-4];
    fn = elt(env, 12); // errach
    v_3301 = (*qfn1(fn))(fn, v_3301);
    goto v_3274;
v_3274:
    goto v_3228;
v_3230:
v_3228:
    v_3301 = stack[-3];
v_3096:
    return onevalue(v_3301);
}



// Code for talp_smupdknowl

static LispObject CC_talp_smupdknowl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3154, v_3155, v_3156, v_3157;
    LispObject fn;
    LispObject v_3094, v_3093, v_3092, v_3091;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "talp_smupdknowl");
    va_start(aa, nargs);
    v_3091 = va_arg(aa, LispObject);
    v_3092 = va_arg(aa, LispObject);
    v_3093 = va_arg(aa, LispObject);
    v_3094 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_3094,v_3093,v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_3091,v_3092,v_3093,v_3094);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_3094;
    v_3154 = v_3093;
    stack[-1] = v_3092;
    stack[-2] = v_3091;
// end of prologue
    stack[-3] = nil;
v_3101:
    v_3155 = stack[-1];
    if (v_3155 == nil) goto v_3104;
    else goto v_3105;
v_3104:
    goto v_3100;
v_3105:
    v_3155 = stack[-1];
    v_3155 = qcar(v_3155);
    stack[-3] = v_3155;
    v_3155 = stack[-1];
    v_3155 = qcdr(v_3155);
    stack[-1] = v_3155;
    goto v_3121;
v_3113:
    v_3157 = stack[-2];
    goto v_3114;
v_3115:
    v_3156 = stack[-3];
    goto v_3116;
v_3117:
    v_3155 = v_3154;
    goto v_3118;
v_3119:
    v_3154 = stack[0];
    goto v_3120;
v_3121:
    goto v_3113;
v_3114:
    goto v_3115;
v_3116:
    goto v_3117;
v_3118:
    goto v_3119;
v_3120:
    fn = elt(env, 3); // talp_smupdknowl1
    v_3154 = (*qfnn(fn))(fn, 4, v_3157, v_3156, v_3155, v_3154);
    env = stack[-4];
    goto v_3134;
v_3130:
    v_3156 = v_3154;
    goto v_3131;
v_3132:
    v_3155 = elt(env, 1); // false
    goto v_3133;
v_3134:
    goto v_3130;
v_3131:
    goto v_3132;
v_3133:
    if (v_3156 == v_3155) goto v_3128;
    else goto v_3129;
v_3128:
    v_3155 = nil;
    stack[-1] = v_3155;
    v_3155 = elt(env, 2); // break
    stack[-3] = v_3155;
    goto v_3127;
v_3129:
v_3127:
    goto v_3101;
v_3100:
    goto v_3147;
v_3143:
    v_3156 = stack[-3];
    goto v_3144;
v_3145:
    v_3155 = elt(env, 2); // break
    goto v_3146;
v_3147:
    goto v_3143;
v_3144:
    goto v_3145;
v_3146:
    if (v_3156 == v_3155) goto v_3141;
    else goto v_3142;
v_3141:
    v_3154 = elt(env, 1); // false
    goto v_3098;
v_3142:
    goto v_3098;
    v_3154 = nil;
v_3098:
    return onevalue(v_3154);
}



// Code for qqe_id!-nyt!-branchb

static LispObject CC_qqe_idKnytKbranchb(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3117;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_3091;
// end of prologue
    v_3117 = stack[0];
    if (!consp(v_3117)) goto v_3095;
    else goto v_3096;
v_3095:
    v_3117 = stack[0];
    fn = elt(env, 1); // qqe_btidp
    v_3117 = (*qfn1(fn))(fn, v_3117);
    env = stack[-1];
    if (v_3117 == nil) goto v_3100;
    else goto v_3099;
v_3100:
    v_3117 = stack[0];
    {
        fn = elt(env, 2); // qqe_nytidp
        return (*qfn1(fn))(fn, v_3117);
    }
v_3099:
    goto v_3094;
v_3096:
    v_3117 = stack[0];
    v_3117 = qcar(v_3117);
    fn = elt(env, 3); // qqe_qopaddp
    v_3117 = (*qfn1(fn))(fn, v_3117);
    env = stack[-1];
    if (v_3117 == nil) goto v_3109;
    else goto v_3108;
v_3109:
    v_3117 = stack[0];
    v_3117 = qcar(v_3117);
    fn = elt(env, 4); // qqe_qoptailp
    v_3117 = (*qfn1(fn))(fn, v_3117);
v_3108:
    v_3117 = (v_3117 == nil ? lisp_true : nil);
    goto v_3094;
    v_3117 = nil;
v_3094:
    return onevalue(v_3117);
}



// Code for kernord

static LispObject CC_kernord(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3114, v_3115;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_3114 = v_3092;
    stack[0] = v_3091;
// end of prologue
    goto v_3099;
v_3095:
    v_3115 = stack[0];
    goto v_3096;
v_3097:
    goto v_3098;
v_3099:
    goto v_3095;
v_3096:
    goto v_3097;
v_3098:
    fn = elt(env, 1); // kernord!-split
    v_3114 = (*qfn2(fn))(fn, v_3115, v_3114);
    env = stack[-2];
    stack[0] = v_3114;
    goto v_3107;
v_3103:
    v_3114 = stack[0];
    v_3114 = qcar(v_3114);
    fn = elt(env, 2); // kernord!-sort
    stack[-1] = (*qfn1(fn))(fn, v_3114);
    env = stack[-2];
    goto v_3104;
v_3105:
    v_3114 = stack[0];
    v_3114 = qcdr(v_3114);
    fn = elt(env, 2); // kernord!-sort
    v_3114 = (*qfn1(fn))(fn, v_3114);
    goto v_3106;
v_3107:
    goto v_3103;
v_3104:
    goto v_3105;
v_3106:
    {
        LispObject v_3118 = stack[-1];
        return Lappend(nil, v_3118, v_3114);
    }
}



// Code for ibalp_calcmom

static LispObject CC_ibalp_calcmom(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3144, v_3145;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3091;
// end of prologue
    goto v_3098;
v_3094:
    goto v_3104;
v_3100:
    goto v_3110;
v_3106:
    v_3144 = stack[0];
    v_3144 = qcdr(v_3144);
    v_3144 = qcdr(v_3144);
    v_3144 = qcdr(v_3144);
    v_3144 = qcdr(v_3144);
    v_3145 = qcar(v_3144);
    goto v_3107;
v_3108:
    v_3144 = stack[0];
    v_3144 = qcdr(v_3144);
    v_3144 = qcdr(v_3144);
    v_3144 = qcdr(v_3144);
    v_3144 = qcdr(v_3144);
    v_3144 = qcdr(v_3144);
    v_3144 = qcar(v_3144);
    goto v_3109;
v_3110:
    goto v_3106;
v_3107:
    goto v_3108;
v_3109:
    v_3145 = plus2(v_3145, v_3144);
    env = stack[-2];
    goto v_3101;
v_3102:
    v_3144 = (LispObject)512+TAG_FIXNUM; // 32
    goto v_3103;
v_3104:
    goto v_3100;
v_3101:
    goto v_3102;
v_3103:
    stack[-1] = times2(v_3145, v_3144);
    env = stack[-2];
    goto v_3095;
v_3096:
    goto v_3130;
v_3126:
    v_3144 = stack[0];
    v_3144 = qcdr(v_3144);
    v_3144 = qcdr(v_3144);
    v_3144 = qcdr(v_3144);
    v_3144 = qcdr(v_3144);
    v_3145 = qcar(v_3144);
    goto v_3127;
v_3128:
    v_3144 = stack[0];
    v_3144 = qcdr(v_3144);
    v_3144 = qcdr(v_3144);
    v_3144 = qcdr(v_3144);
    v_3144 = qcdr(v_3144);
    v_3144 = qcdr(v_3144);
    v_3144 = qcar(v_3144);
    goto v_3129;
v_3130:
    goto v_3126;
v_3127:
    goto v_3128;
v_3129:
    v_3144 = times2(v_3145, v_3144);
    goto v_3097;
v_3098:
    goto v_3094;
v_3095:
    goto v_3096;
v_3097:
    {
        LispObject v_3148 = stack[-1];
        return plus2(v_3148, v_3144);
    }
}



// Code for multi_elem

static LispObject CC_multi_elem(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3119, v_3120;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_3091;
// end of prologue
    goto v_3103;
v_3099:
    v_3119 = stack[0];
    v_3120 = Llength(nil, v_3119);
    env = stack[-1];
    goto v_3100;
v_3101:
    v_3119 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3102;
v_3103:
    goto v_3099;
v_3100:
    goto v_3101;
v_3102:
    if (v_3120 == v_3119) goto v_3097;
    else goto v_3098;
v_3097:
    v_3119 = stack[0];
    v_3119 = qcar(v_3119);
    fn = elt(env, 1); // expression
    v_3119 = (*qfn1(fn))(fn, v_3119);
    goto v_3096;
v_3098:
    v_3119 = stack[0];
    v_3119 = qcar(v_3119);
    fn = elt(env, 1); // expression
    v_3119 = (*qfn1(fn))(fn, v_3119);
    env = stack[-1];
    v_3119 = stack[0];
    v_3119 = qcdr(v_3119);
    v_3119 = CC_multi_elem(elt(env, 0), v_3119);
    goto v_3096;
v_3096:
    v_3119 = nil;
    return onevalue(v_3119);
}



// Code for simp!*

static LispObject CC_simpH(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3235, v_3236;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_3091;
// end of prologue
// Binding !*asymp!*
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = nil; // !*asymp!*
    goto v_3110;
v_3106:
    v_3236 = stack[-2];
    goto v_3107;
v_3108:
    v_3235 = elt(env, 2); // !*sq
    goto v_3109;
v_3110:
    goto v_3106;
v_3107:
    goto v_3108;
v_3109:
    if (!consp(v_3236)) goto v_3104;
    v_3236 = qcar(v_3236);
    if (v_3236 == v_3235) goto v_3103;
    else goto v_3104;
v_3103:
    v_3235 = stack[-2];
    v_3235 = qcdr(v_3235);
    v_3235 = qcdr(v_3235);
    v_3235 = qcar(v_3235);
    if (v_3235 == nil) goto v_3115;
    else goto v_3116;
v_3115:
    v_3235 = nil;
    goto v_3114;
v_3116:
    v_3235 = qvalue(elt(env, 3)); // !*resimp
    v_3235 = (v_3235 == nil ? lisp_true : nil);
    goto v_3114;
    v_3235 = nil;
v_3114:
    goto v_3102;
v_3104:
    v_3235 = nil;
    goto v_3102;
    v_3235 = nil;
v_3102:
    if (v_3235 == nil) goto v_3100;
    v_3235 = stack[-2];
    v_3235 = qcdr(v_3235);
    v_3235 = qcar(v_3235);
    goto v_3096;
v_3100:
    goto v_3137;
v_3133:
    v_3236 = qvalue(elt(env, 4)); // mul!*
    goto v_3134;
v_3135:
    v_3235 = qvalue(elt(env, 5)); // !*sub2
    goto v_3136;
v_3137:
    goto v_3133;
v_3134:
    goto v_3135;
v_3136:
    v_3235 = cons(v_3236, v_3235);
    env = stack[-4];
    stack[-1] = v_3235;
    v_3235 = nil;
    qvalue(elt(env, 4)) = v_3235; // mul!*
    v_3235 = stack[-2];
    fn = elt(env, 13); // simp
    v_3235 = (*qfn1(fn))(fn, v_3235);
    env = stack[-4];
    stack[-2] = v_3235;
    v_3235 = qvalue(elt(env, 6)); // !*nospurp
    if (v_3235 == nil) goto v_3146;
    goto v_3153;
v_3149:
    v_3236 = qvalue(elt(env, 4)); // mul!*
    goto v_3150;
v_3151:
    v_3235 = elt(env, 7); // (isimpq)
    goto v_3152;
v_3153:
    goto v_3149;
v_3150:
    goto v_3151;
v_3152:
    fn = elt(env, 14); // union
    v_3235 = (*qfn2(fn))(fn, v_3236, v_3235);
    env = stack[-4];
    qvalue(elt(env, 4)) = v_3235; // mul!*
    goto v_3144;
v_3146:
v_3144:
    v_3235 = qvalue(elt(env, 4)); // mul!*
    stack[0] = v_3235;
v_3159:
    v_3235 = stack[0];
    if (v_3235 == nil) goto v_3163;
    else goto v_3164;
v_3163:
    goto v_3158;
v_3164:
    v_3235 = stack[0];
    v_3235 = qcar(v_3235);
    goto v_3175;
v_3171:
    v_3236 = v_3235;
    goto v_3172;
v_3173:
    v_3235 = stack[-2];
    goto v_3174;
v_3175:
    goto v_3171;
v_3172:
    goto v_3173;
v_3174:
    v_3235 = Lapply1(nil, v_3236, v_3235);
    env = stack[-4];
    stack[-2] = v_3235;
    v_3235 = stack[0];
    v_3235 = qcdr(v_3235);
    stack[0] = v_3235;
    goto v_3159;
v_3158:
    v_3235 = stack[-1];
    v_3235 = qcar(v_3235);
    qvalue(elt(env, 4)) = v_3235; // mul!*
    v_3235 = stack[-2];
    fn = elt(env, 15); // subs2
    v_3235 = (*qfn1(fn))(fn, v_3235);
    env = stack[-4];
    stack[-2] = v_3235;
    v_3235 = qvalue(elt(env, 8)); // !*combinelogs
    if (v_3235 == nil) goto v_3187;
    v_3235 = stack[-2];
    fn = elt(env, 16); // clogsq!*
    v_3235 = (*qfn1(fn))(fn, v_3235);
    env = stack[-4];
    stack[-2] = v_3235;
    goto v_3185;
v_3187:
v_3185:
    goto v_3203;
v_3199:
    v_3236 = qvalue(elt(env, 9)); // dmode!*
    goto v_3200;
v_3201:
    v_3235 = elt(env, 10); // !:gi!:
    goto v_3202;
v_3203:
    goto v_3199;
v_3200:
    goto v_3201;
v_3202:
    if (v_3236 == v_3235) goto v_3197;
    else goto v_3198;
v_3197:
    v_3235 = qvalue(elt(env, 11)); // !*norationalgi
    v_3235 = (v_3235 == nil ? lisp_true : nil);
    goto v_3196;
v_3198:
    v_3235 = nil;
    goto v_3196;
    v_3235 = nil;
v_3196:
    if (v_3235 == nil) goto v_3194;
    v_3235 = stack[-2];
    fn = elt(env, 17); // girationalize!:
    v_3235 = (*qfn1(fn))(fn, v_3235);
    env = stack[-4];
    stack[-2] = v_3235;
    goto v_3192;
v_3194:
    v_3235 = qvalue(elt(env, 12)); // !*rationalize
    if (v_3235 == nil) goto v_3214;
    v_3235 = stack[-2];
    fn = elt(env, 18); // rationalizesq
    v_3235 = (*qfn1(fn))(fn, v_3235);
    env = stack[-4];
    stack[-2] = v_3235;
    goto v_3192;
v_3214:
    v_3235 = stack[-2];
    fn = elt(env, 19); // rationalizei
    v_3235 = (*qfn1(fn))(fn, v_3235);
    env = stack[-4];
    stack[-2] = v_3235;
    goto v_3192;
v_3192:
    v_3235 = stack[-1];
    v_3235 = qcdr(v_3235);
    qvalue(elt(env, 5)) = v_3235; // !*sub2
    v_3235 = qvalue(elt(env, 1)); // !*asymp!*
    if (v_3235 == nil) goto v_3227;
    v_3235 = qvalue(elt(env, 12)); // !*rationalize
    if (v_3235 == nil) goto v_3227;
    v_3235 = stack[-2];
    fn = elt(env, 20); // gcdchk
    v_3235 = (*qfn1(fn))(fn, v_3235);
    stack[-2] = v_3235;
    goto v_3225;
v_3227:
v_3225:
    v_3235 = stack[-2];
v_3096:
    ;}  // end of a binding scope
    return onevalue(v_3235);
}



// Code for termordp

static LispObject CC_termordp(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3104;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3092;
    v_3104 = v_3091;
// end of prologue
    goto v_3099;
v_3095:
    fn = elt(env, 1); // wedgefax
    stack[-1] = (*qfn1(fn))(fn, v_3104);
    env = stack[-2];
    goto v_3096;
v_3097:
    v_3104 = stack[0];
    fn = elt(env, 1); // wedgefax
    v_3104 = (*qfn1(fn))(fn, v_3104);
    env = stack[-2];
    goto v_3098;
v_3099:
    goto v_3095;
v_3096:
    goto v_3097;
v_3098:
    {
        LispObject v_3107 = stack[-1];
        fn = elt(env, 2); // monordp
        return (*qfn2(fn))(fn, v_3107, v_3104);
    }
}



// Code for !:plus

static LispObject CC_Tplus(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3153, v_3154, v_3155;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
// copy arguments values to proper place
    v_3154 = v_3092;
    v_3155 = v_3091;
// end of prologue
    v_3153 = v_3155;
    if (v_3153 == nil) goto v_3096;
    else goto v_3097;
v_3096:
    v_3153 = v_3154;
    goto v_3095;
v_3097:
    v_3153 = v_3154;
    if (v_3153 == nil) goto v_3100;
    else goto v_3101;
v_3100:
    v_3153 = v_3155;
    goto v_3095;
v_3101:
    v_3153 = v_3155;
    if (!consp(v_3153)) goto v_3108;
    else goto v_3109;
v_3108:
    v_3153 = v_3154;
    v_3153 = (consp(v_3153) ? nil : lisp_true);
    goto v_3107;
v_3109:
    v_3153 = nil;
    goto v_3107;
    v_3153 = nil;
v_3107:
    if (v_3153 == nil) goto v_3105;
    goto v_3121;
v_3117:
    v_3153 = v_3155;
    goto v_3118;
v_3119:
    goto v_3120;
v_3121:
    goto v_3117;
v_3118:
    goto v_3119;
v_3120:
    v_3153 = plus2(v_3153, v_3154);
    v_3155 = v_3153;
    goto v_3133;
v_3129:
    v_3154 = v_3155;
    goto v_3130;
v_3131:
    v_3153 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3132;
v_3133:
    goto v_3129;
v_3130:
    goto v_3131;
v_3132:
    if (v_3154 == v_3153) goto v_3127;
    else goto v_3128;
v_3127:
    v_3153 = nil;
    goto v_3126;
v_3128:
    v_3153 = v_3155;
    goto v_3126;
    v_3153 = nil;
v_3126:
    goto v_3095;
v_3105:
    goto v_3149;
v_3143:
    goto v_3144;
v_3145:
    goto v_3146;
v_3147:
    v_3153 = elt(env, 1); // plus
    goto v_3148;
v_3149:
    goto v_3143;
v_3144:
    goto v_3145;
v_3146:
    goto v_3147;
v_3148:
    {
        fn = elt(env, 2); // dcombine
        return (*qfnn(fn))(fn, 3, v_3155, v_3154, v_3153);
    }
    v_3153 = nil;
v_3095:
    return onevalue(v_3153);
}



// Code for optype

static LispObject CC_optype(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3101, v_3102;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3101 = v_3091;
// end of prologue
    goto v_3098;
v_3094:
    goto v_3095;
v_3096:
    v_3102 = elt(env, 1); // !*optype!*
    goto v_3097;
v_3098:
    goto v_3094;
v_3095:
    goto v_3096;
v_3097:
    return get(v_3101, v_3102);
}



// Code for setcloc!*

static LispObject CC_setclocH(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3112, v_3113, v_3114;
    argcheck(nargs, 0, "setcloc*");
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
    v_3112 = qvalue(elt(env, 1)); // ifl!*
    if (v_3112 == nil) goto v_3094;
    else goto v_3095;
v_3094:
    v_3112 = nil;
    goto v_3093;
v_3095:
    goto v_3107;
v_3101:
    v_3112 = qvalue(elt(env, 1)); // ifl!*
    v_3114 = qcar(v_3112);
    goto v_3102;
v_3103:
    v_3113 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3104;
v_3105:
    v_3112 = qvalue(elt(env, 2)); // curline!*
    goto v_3106;
v_3107:
    goto v_3101;
v_3102:
    goto v_3103;
v_3104:
    goto v_3105;
v_3106:
    v_3112 = list2star(v_3114, v_3113, v_3112);
    env = stack[0];
    goto v_3093;
    v_3112 = nil;
v_3093:
    qvalue(elt(env, 3)) = v_3112; // cloc!*
    return onevalue(v_3112);
}



// Code for getrtype2

static LispObject CC_getrtype2(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3177, v_3178;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_3091;
// end of prologue
    v_3177 = stack[0];
    fn = elt(env, 4); // vecp
    v_3177 = (*qfn1(fn))(fn, v_3177);
    env = stack[-1];
    if (v_3177 == nil) goto v_3099;
    v_3177 = elt(env, 1); // !3vector
    goto v_3097;
v_3099:
    v_3177 = stack[0];
    v_3177 = qcar(v_3177);
    if (!symbolp(v_3177)) v_3177 = nil;
    else { v_3177 = qfastgets(v_3177);
           if (v_3177 != nil) { v_3177 = elt(v_3177, 2); // rtype
#ifdef RECORD_GET
             if (v_3177 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_3177 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_3177 == SPID_NOPROP) v_3177 = nil; }}
#endif
    v_3178 = v_3177;
    if (v_3177 == nil) goto v_3104;
    v_3177 = v_3178;
    if (!symbolp(v_3177)) v_3177 = nil;
    else { v_3177 = qfastgets(v_3177);
           if (v_3177 != nil) { v_3177 = elt(v_3177, 19); // rtypefn
#ifdef RECORD_GET
             if (v_3177 != SPID_NOPROP)
                record_get(elt(fastget_names, 19), 1);
             else record_get(elt(fastget_names, 19), 0),
                v_3177 = nil; }
           else record_get(elt(fastget_names, 19), 0); }
#else
             if (v_3177 == SPID_NOPROP) v_3177 = nil; }}
#endif
    v_3178 = v_3177;
    if (v_3177 == nil) goto v_3104;
    goto v_3117;
v_3113:
    goto v_3114;
v_3115:
    v_3177 = stack[0];
    v_3177 = qcdr(v_3177);
    goto v_3116;
v_3117:
    goto v_3113;
v_3114:
    goto v_3115;
v_3116:
        return Lapply1(nil, v_3178, v_3177);
v_3104:
    v_3177 = stack[0];
    v_3177 = qcar(v_3177);
    if (!symbolp(v_3177)) v_3177 = nil;
    else { v_3177 = qfastgets(v_3177);
           if (v_3177 != nil) { v_3177 = elt(v_3177, 19); // rtypefn
#ifdef RECORD_GET
             if (v_3177 != SPID_NOPROP)
                record_get(elt(fastget_names, 19), 1);
             else record_get(elt(fastget_names, 19), 0),
                v_3177 = nil; }
           else record_get(elt(fastget_names, 19), 0); }
#else
             if (v_3177 == SPID_NOPROP) v_3177 = nil; }}
#endif
    v_3178 = v_3177;
    if (v_3177 == nil) goto v_3122;
    goto v_3131;
v_3127:
    goto v_3128;
v_3129:
    v_3177 = stack[0];
    v_3177 = qcdr(v_3177);
    goto v_3130;
v_3131:
    goto v_3127;
v_3128:
    goto v_3129;
v_3130:
        return Lapply1(nil, v_3178, v_3177);
v_3122:
    goto v_3146;
v_3142:
    v_3177 = stack[0];
    v_3178 = qcar(v_3177);
    goto v_3143;
v_3144:
    v_3177 = elt(env, 2); // matmapfn
    goto v_3145;
v_3146:
    goto v_3142;
v_3143:
    goto v_3144;
v_3145:
    v_3177 = Lflagp(nil, v_3178, v_3177);
    env = stack[-1];
    if (v_3177 == nil) goto v_3140;
    v_3177 = stack[0];
    v_3177 = qcdr(v_3177);
    if (v_3177 == nil) goto v_3152;
    else goto v_3153;
v_3152:
    v_3177 = nil;
    goto v_3151;
v_3153:
    goto v_3163;
v_3159:
    v_3177 = stack[0];
    v_3177 = qcdr(v_3177);
    v_3177 = qcar(v_3177);
    fn = elt(env, 5); // getrtype
    v_3178 = (*qfn1(fn))(fn, v_3177);
    env = stack[-1];
    goto v_3160;
v_3161:
    v_3177 = elt(env, 3); // matrix
    goto v_3162;
v_3163:
    goto v_3159;
v_3160:
    goto v_3161;
v_3162:
    v_3177 = (v_3178 == v_3177 ? lisp_true : nil);
    goto v_3151;
    v_3177 = nil;
v_3151:
    goto v_3138;
v_3140:
    v_3177 = nil;
    goto v_3138;
    v_3177 = nil;
v_3138:
    if (v_3177 == nil) goto v_3136;
    v_3177 = elt(env, 3); // matrix
    goto v_3097;
v_3136:
    v_3177 = nil;
    goto v_3097;
    v_3177 = nil;
v_3097:
    return onevalue(v_3177);
}



// Code for groeb!=testa

static LispObject CC_groebMtesta(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3116, v_3117;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3092;
    v_3116 = v_3091;
// end of prologue
    goto v_3099;
v_3095:
    goto v_3105;
v_3101:
    v_3117 = v_3116;
    goto v_3102;
v_3103:
    v_3116 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_3104;
v_3105:
    goto v_3101;
v_3102:
    goto v_3103;
v_3104:
    fn = elt(env, 1); // nth
    stack[-1] = (*qfn2(fn))(fn, v_3117, v_3116);
    env = stack[-2];
    goto v_3096;
v_3097:
    goto v_3113;
v_3109:
    v_3117 = stack[0];
    goto v_3110;
v_3111:
    v_3116 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_3112;
v_3113:
    goto v_3109;
v_3110:
    goto v_3111;
v_3112:
    fn = elt(env, 1); // nth
    v_3116 = (*qfn2(fn))(fn, v_3117, v_3116);
    env = stack[-2];
    goto v_3098;
v_3099:
    goto v_3095;
v_3096:
    goto v_3097;
v_3098:
    {
        LispObject v_3120 = stack[-1];
        fn = elt(env, 2); // mo_divides!?
        return (*qfn2(fn))(fn, v_3120, v_3116);
    }
}



// Code for gperm2

static LispObject CC_gperm2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3132, v_3133, v_3134, v_3135;
    LispObject fn;
    LispObject v_3093, v_3092, v_3091;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "gperm2");
    va_start(aa, nargs);
    v_3091 = va_arg(aa, LispObject);
    v_3092 = va_arg(aa, LispObject);
    v_3093 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_3093,v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_3091,v_3092,v_3093);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3093;
    stack[-1] = v_3092;
    v_3132 = v_3091;
// end of prologue
v_3098:
    v_3133 = v_3132;
    if (v_3133 == nil) goto v_3101;
    else goto v_3102;
v_3101:
    v_3132 = stack[0];
    goto v_3097;
v_3102:
    v_3133 = v_3132;
    v_3133 = qcdr(v_3133);
    stack[-2] = v_3133;
    goto v_3118;
v_3110:
    goto v_3124;
v_3120:
    v_3133 = qcar(v_3132);
    goto v_3121;
v_3122:
    v_3132 = nil;
    goto v_3123;
v_3124:
    goto v_3120;
v_3121:
    goto v_3122;
v_3123:
    fn = elt(env, 1); // rev
    v_3135 = (*qfn2(fn))(fn, v_3133, v_3132);
    env = stack[-3];
    goto v_3111;
v_3112:
    v_3134 = stack[-1];
    goto v_3113;
v_3114:
    v_3133 = nil;
    goto v_3115;
v_3116:
    v_3132 = stack[0];
    goto v_3117;
v_3118:
    goto v_3110;
v_3111:
    goto v_3112;
v_3113:
    goto v_3114;
v_3115:
    goto v_3116;
v_3117:
    fn = elt(env, 2); // gperm1
    v_3132 = (*qfnn(fn))(fn, 4, v_3135, v_3134, v_3133, v_3132);
    env = stack[-3];
    stack[0] = v_3132;
    v_3132 = stack[-2];
    goto v_3098;
    v_3132 = nil;
v_3097:
    return onevalue(v_3132);
}



// Code for !*i2ar

static LispObject CC_Hi2ar(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3101, v_3102;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3101 = v_3091;
// end of prologue
    goto v_3098;
v_3094:
    v_3102 = elt(env, 1); // !:ar!:
    goto v_3095;
v_3096:
    goto v_3097;
v_3098:
    goto v_3094;
v_3095:
    goto v_3096;
v_3097:
    return cons(v_3102, v_3101);
}



// Code for general!-modular!-minus

static LispObject CC_generalKmodularKminus(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3115, v_3116, v_3117;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3117 = v_3091;
// end of prologue
    goto v_3101;
v_3097:
    v_3116 = v_3117;
    goto v_3098;
v_3099:
    v_3115 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3100;
v_3101:
    goto v_3097;
v_3098:
    goto v_3099;
v_3100:
    if (v_3116 == v_3115) goto v_3095;
    else goto v_3096;
v_3095:
    v_3115 = v_3117;
    goto v_3094;
v_3096:
    goto v_3112;
v_3108:
    v_3115 = qvalue(elt(env, 1)); // current!-modulus
    goto v_3109;
v_3110:
    v_3116 = v_3117;
    goto v_3111;
v_3112:
    goto v_3108;
v_3109:
    goto v_3110;
v_3111:
    return difference2(v_3115, v_3116);
    v_3115 = nil;
v_3094:
    return onevalue(v_3115);
}



// Code for convprec!*

static LispObject CC_convprecH(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3110, v_3111;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_3110 = v_3091;
// end of prologue
    v_3111 = v_3110;
    if (!consp(v_3111)) goto v_3096;
    else goto v_3097;
v_3096:
    goto v_3095;
v_3097:
    goto v_3107;
v_3103:
    v_3111 = elt(env, 1); // !:rd!:
    goto v_3104;
v_3105:
    goto v_3106;
v_3107:
    goto v_3103;
v_3104:
    goto v_3105;
v_3106:
    v_3110 = cons(v_3111, v_3110);
    env = stack[0];
    goto v_3095;
    v_3110 = nil;
v_3095:
    {
        fn = elt(env, 2); // convchk
        return (*qfn1(fn))(fn, v_3110);
    }
}



// Code for lalr_remove_duplicates

static LispObject CC_lalr_remove_duplicates(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3134, v_3135, v_3136, v_3137;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_3134 = v_3091;
// end of prologue
    v_3137 = nil;
    stack[0] = v_3134;
v_3099:
    v_3134 = stack[0];
    if (v_3134 == nil) goto v_3103;
    else goto v_3104;
v_3103:
    goto v_3098;
v_3104:
    v_3134 = stack[0];
    v_3134 = qcar(v_3134);
    v_3136 = v_3134;
    goto v_3118;
v_3114:
    v_3135 = v_3136;
    goto v_3115;
v_3116:
    v_3134 = v_3137;
    goto v_3117;
v_3118:
    goto v_3114;
v_3115:
    goto v_3116;
v_3117:
    v_3134 = Lmember(nil, v_3135, v_3134);
    if (v_3134 == nil) goto v_3112;
    else goto v_3113;
v_3112:
    goto v_3127;
v_3123:
    v_3134 = v_3136;
    goto v_3124;
v_3125:
    v_3135 = v_3137;
    goto v_3126;
v_3127:
    goto v_3123;
v_3124:
    goto v_3125;
v_3126:
    v_3134 = cons(v_3134, v_3135);
    env = stack[-1];
    v_3137 = v_3134;
    goto v_3111;
v_3113:
v_3111:
    v_3134 = stack[0];
    v_3134 = qcdr(v_3134);
    stack[0] = v_3134;
    goto v_3099;
v_3098:
    v_3134 = v_3137;
        return Lnreverse(nil, v_3134);
    return onevalue(v_3134);
}



// Code for convertmode

static LispObject CC_convertmode(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3120, v_3121, v_3122, v_3123;
    LispObject fn;
    LispObject v_3094, v_3093, v_3092, v_3091;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "convertmode");
    va_start(aa, nargs);
    v_3091 = va_arg(aa, LispObject);
    v_3092 = va_arg(aa, LispObject);
    v_3093 = va_arg(aa, LispObject);
    v_3094 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_3094,v_3093,v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_3091,v_3092,v_3093,v_3094);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3094;
    stack[-1] = v_3093;
    stack[-2] = v_3092;
    v_3120 = v_3091;
// end of prologue
    goto v_3105;
v_3097:
    goto v_3113;
v_3107:
    v_3122 = v_3120;
    goto v_3108;
v_3109:
    v_3121 = stack[-2];
    goto v_3110;
v_3111:
    v_3120 = stack[0];
    goto v_3112;
v_3113:
    goto v_3107;
v_3108:
    goto v_3109;
v_3110:
    goto v_3111;
v_3112:
    fn = elt(env, 1); // form1
    v_3123 = (*qfnn(fn))(fn, 3, v_3122, v_3121, v_3120);
    env = stack[-3];
    goto v_3098;
v_3099:
    v_3122 = stack[-2];
    goto v_3100;
v_3101:
    v_3121 = stack[-1];
    goto v_3102;
v_3103:
    v_3120 = stack[0];
    goto v_3104;
v_3105:
    goto v_3097;
v_3098:
    goto v_3099;
v_3100:
    goto v_3101;
v_3102:
    goto v_3103;
v_3104:
    {
        fn = elt(env, 2); // convertmode1
        return (*qfnn(fn))(fn, 4, v_3123, v_3122, v_3121, v_3120);
    }
}



// Code for sfto_davp

static LispObject CC_sfto_davp(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3195, v_3196;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3092;
    stack[-1] = v_3091;
// end of prologue
v_3097:
    v_3195 = stack[-1];
    if (!consp(v_3195)) goto v_3104;
    else goto v_3105;
v_3104:
    v_3195 = lisp_true;
    goto v_3103;
v_3105:
    v_3195 = stack[-1];
    v_3195 = qcar(v_3195);
    v_3195 = (consp(v_3195) ? nil : lisp_true);
    goto v_3103;
    v_3195 = nil;
v_3103:
    if (v_3195 == nil) goto v_3101;
    v_3195 = lisp_true;
    goto v_3096;
v_3101:
    goto v_3121;
v_3117:
    v_3195 = stack[-1];
    v_3195 = qcar(v_3195);
    v_3195 = qcar(v_3195);
    v_3196 = qcdr(v_3195);
    goto v_3118;
v_3119:
    v_3195 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_3120;
v_3121:
    goto v_3117;
v_3118:
    goto v_3119;
v_3120:
    v_3195 = (LispObject)greaterp2(v_3196, v_3195);
    v_3195 = v_3195 ? lisp_true : nil;
    env = stack[-2];
    if (v_3195 == nil) goto v_3115;
    v_3195 = stack[0];
    if (v_3195 == nil) goto v_3130;
    goto v_3138;
v_3134:
    v_3195 = stack[-1];
    v_3195 = qcar(v_3195);
    v_3195 = qcar(v_3195);
    v_3196 = qcar(v_3195);
    goto v_3135;
v_3136:
    v_3195 = stack[0];
    goto v_3137;
v_3138:
    goto v_3134;
v_3135:
    goto v_3136;
v_3137:
    if (equal(v_3196, v_3195)) goto v_3130;
    v_3195 = nil;
    goto v_3096;
v_3130:
    goto v_3156;
v_3152:
    v_3195 = stack[-1];
    v_3195 = qcar(v_3195);
    v_3196 = qcdr(v_3195);
    goto v_3153;
v_3154:
    v_3195 = stack[-1];
    v_3195 = qcar(v_3195);
    v_3195 = qcar(v_3195);
    v_3195 = qcar(v_3195);
    goto v_3155;
v_3156:
    goto v_3152;
v_3153:
    goto v_3154;
v_3155:
    v_3195 = CC_sfto_davp(elt(env, 0), v_3196, v_3195);
    env = stack[-2];
    if (v_3195 == nil) goto v_3150;
    v_3195 = stack[-1];
    v_3195 = qcdr(v_3195);
    v_3196 = v_3195;
    v_3195 = stack[-1];
    v_3195 = qcar(v_3195);
    v_3195 = qcar(v_3195);
    v_3195 = qcar(v_3195);
    stack[0] = v_3195;
    v_3195 = v_3196;
    stack[-1] = v_3195;
    goto v_3097;
v_3150:
    v_3195 = nil;
    goto v_3096;
    goto v_3128;
v_3128:
    goto v_3099;
v_3115:
    goto v_3185;
v_3181:
    v_3195 = stack[-1];
    v_3195 = qcar(v_3195);
    v_3196 = qcdr(v_3195);
    goto v_3182;
v_3183:
    v_3195 = stack[0];
    goto v_3184;
v_3185:
    goto v_3181;
v_3182:
    goto v_3183;
v_3184:
    v_3195 = CC_sfto_davp(elt(env, 0), v_3196, v_3195);
    env = stack[-2];
    if (v_3195 == nil) goto v_3179;
    v_3195 = stack[-1];
    v_3195 = qcdr(v_3195);
    stack[-1] = v_3195;
    goto v_3097;
v_3179:
    v_3195 = nil;
    goto v_3096;
    goto v_3099;
v_3099:
    v_3195 = nil;
v_3096:
    return onevalue(v_3195);
}



// Code for cl_atfp

static LispObject CC_cl_atfp(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3281, v_3282, v_3283;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3282 = v_3091;
// end of prologue
    v_3281 = v_3282;
    if (!consp(v_3281)) goto v_3095;
    else goto v_3096;
v_3095:
    v_3281 = v_3282;
    goto v_3094;
v_3096:
    v_3281 = v_3282;
    v_3281 = qcar(v_3281);
    goto v_3094;
    v_3281 = nil;
v_3094:
    v_3283 = v_3281;
    goto v_3116;
v_3112:
    v_3282 = v_3283;
    goto v_3113;
v_3114:
    v_3281 = elt(env, 1); // true
    goto v_3115;
v_3116:
    goto v_3112;
v_3113:
    goto v_3114;
v_3115:
    if (v_3282 == v_3281) goto v_3110;
    else goto v_3111;
v_3110:
    v_3281 = lisp_true;
    goto v_3109;
v_3111:
    goto v_3126;
v_3122:
    v_3282 = v_3283;
    goto v_3123;
v_3124:
    v_3281 = elt(env, 2); // false
    goto v_3125;
v_3126:
    goto v_3122;
v_3123:
    goto v_3124;
v_3125:
    v_3281 = (v_3282 == v_3281 ? lisp_true : nil);
    goto v_3109;
    v_3281 = nil;
v_3109:
    if (v_3281 == nil) goto v_3107;
    v_3281 = lisp_true;
    goto v_3105;
v_3107:
    goto v_3153;
v_3149:
    v_3282 = v_3283;
    goto v_3150;
v_3151:
    v_3281 = elt(env, 3); // or
    goto v_3152;
v_3153:
    goto v_3149;
v_3150:
    goto v_3151;
v_3152:
    if (v_3282 == v_3281) goto v_3147;
    else goto v_3148;
v_3147:
    v_3281 = lisp_true;
    goto v_3146;
v_3148:
    goto v_3163;
v_3159:
    v_3282 = v_3283;
    goto v_3160;
v_3161:
    v_3281 = elt(env, 4); // and
    goto v_3162;
v_3163:
    goto v_3159;
v_3160:
    goto v_3161;
v_3162:
    v_3281 = (v_3282 == v_3281 ? lisp_true : nil);
    goto v_3146;
    v_3281 = nil;
v_3146:
    if (v_3281 == nil) goto v_3144;
    v_3281 = lisp_true;
    goto v_3142;
v_3144:
    goto v_3174;
v_3170:
    v_3282 = v_3283;
    goto v_3171;
v_3172:
    v_3281 = elt(env, 5); // not
    goto v_3173;
v_3174:
    goto v_3170;
v_3171:
    goto v_3172;
v_3173:
    v_3281 = (v_3282 == v_3281 ? lisp_true : nil);
    goto v_3142;
    v_3281 = nil;
v_3142:
    if (v_3281 == nil) goto v_3140;
    v_3281 = lisp_true;
    goto v_3138;
v_3140:
    goto v_3189;
v_3185:
    v_3282 = v_3283;
    goto v_3186;
v_3187:
    v_3281 = elt(env, 6); // impl
    goto v_3188;
v_3189:
    goto v_3185;
v_3186:
    goto v_3187;
v_3188:
    if (v_3282 == v_3281) goto v_3183;
    else goto v_3184;
v_3183:
    v_3281 = lisp_true;
    goto v_3182;
v_3184:
    goto v_3203;
v_3199:
    v_3282 = v_3283;
    goto v_3200;
v_3201:
    v_3281 = elt(env, 7); // repl
    goto v_3202;
v_3203:
    goto v_3199;
v_3200:
    goto v_3201;
v_3202:
    if (v_3282 == v_3281) goto v_3197;
    else goto v_3198;
v_3197:
    v_3281 = lisp_true;
    goto v_3196;
v_3198:
    goto v_3213;
v_3209:
    v_3282 = v_3283;
    goto v_3210;
v_3211:
    v_3281 = elt(env, 8); // equiv
    goto v_3212;
v_3213:
    goto v_3209;
v_3210:
    goto v_3211;
v_3212:
    v_3281 = (v_3282 == v_3281 ? lisp_true : nil);
    goto v_3196;
    v_3281 = nil;
v_3196:
    goto v_3182;
    v_3281 = nil;
v_3182:
    goto v_3138;
    v_3281 = nil;
v_3138:
    if (v_3281 == nil) goto v_3136;
    v_3281 = lisp_true;
    goto v_3134;
v_3136:
    goto v_3232;
v_3228:
    v_3282 = v_3283;
    goto v_3229;
v_3230:
    v_3281 = elt(env, 9); // ex
    goto v_3231;
v_3232:
    goto v_3228;
v_3229:
    goto v_3230;
v_3231:
    if (v_3282 == v_3281) goto v_3226;
    else goto v_3227;
v_3226:
    v_3281 = lisp_true;
    goto v_3225;
v_3227:
    goto v_3242;
v_3238:
    v_3282 = v_3283;
    goto v_3239;
v_3240:
    v_3281 = elt(env, 10); // all
    goto v_3241;
v_3242:
    goto v_3238;
v_3239:
    goto v_3240;
v_3241:
    v_3281 = (v_3282 == v_3281 ? lisp_true : nil);
    goto v_3225;
    v_3281 = nil;
v_3225:
    if (v_3281 == nil) goto v_3223;
    v_3281 = lisp_true;
    goto v_3221;
v_3223:
    goto v_3261;
v_3257:
    v_3282 = v_3283;
    goto v_3258;
v_3259:
    v_3281 = elt(env, 11); // bex
    goto v_3260;
v_3261:
    goto v_3257;
v_3258:
    goto v_3259;
v_3260:
    if (v_3282 == v_3281) goto v_3255;
    else goto v_3256;
v_3255:
    v_3281 = lisp_true;
    goto v_3254;
v_3256:
    goto v_3271;
v_3267:
    v_3281 = v_3283;
    goto v_3268;
v_3269:
    v_3282 = elt(env, 12); // ball
    goto v_3270;
v_3271:
    goto v_3267;
v_3268:
    goto v_3269;
v_3270:
    v_3281 = (v_3281 == v_3282 ? lisp_true : nil);
    goto v_3254;
    v_3281 = nil;
v_3254:
    if (v_3281 == nil) goto v_3252;
    v_3281 = lisp_true;
    goto v_3250;
v_3252:
    v_3281 = v_3283;
    if (!symbolp(v_3281)) v_3281 = nil;
    else { v_3281 = qfastgets(v_3281);
           if (v_3281 != nil) { v_3281 = elt(v_3281, 21); // rl_external
#ifdef RECORD_GET
             if (v_3281 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_3281 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_3281 == SPID_NOPROP) v_3281 = nil; }}
#endif
    goto v_3250;
    v_3281 = nil;
v_3250:
    goto v_3221;
    v_3281 = nil;
v_3221:
    goto v_3134;
    v_3281 = nil;
v_3134:
    goto v_3105;
    v_3281 = nil;
v_3105:
    v_3281 = (v_3281 == nil ? lisp_true : nil);
    return onevalue(v_3281);
}



// Code for powers2

static LispObject CC_powers2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3158, v_3159, v_3160;
    LispObject fn;
    LispObject v_3093, v_3092, v_3091;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "powers2");
    va_start(aa, nargs);
    v_3091 = va_arg(aa, LispObject);
    v_3092 = va_arg(aa, LispObject);
    v_3093 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_3093,v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_3091,v_3092,v_3093);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_3093;
    stack[-1] = v_3092;
    stack[-2] = v_3091;
// end of prologue
v_3098:
    v_3158 = stack[-2];
    if (!consp(v_3158)) goto v_3105;
    else goto v_3106;
v_3105:
    v_3158 = lisp_true;
    goto v_3104;
v_3106:
    v_3158 = stack[-2];
    v_3158 = qcar(v_3158);
    v_3158 = (consp(v_3158) ? nil : lisp_true);
    goto v_3104;
    v_3158 = nil;
v_3104:
    if (v_3158 == nil) goto v_3102;
    v_3158 = stack[-2];
    if (v_3158 == nil) goto v_3116;
    else goto v_3117;
v_3116:
    v_3158 = stack[-1];
    goto v_3097;
v_3117:
    goto v_3127;
v_3123:
    v_3159 = stack[0];
    goto v_3124;
v_3125:
    v_3158 = stack[-1];
    goto v_3126;
v_3127:
    goto v_3123;
v_3124:
    goto v_3125;
v_3126:
    {
        fn = elt(env, 1); // powers4
        return (*qfn2(fn))(fn, v_3159, v_3158);
    }
    goto v_3100;
v_3102:
    v_3158 = stack[-2];
    v_3158 = qcar(v_3158);
    v_3158 = qcdr(v_3158);
    stack[-3] = v_3158;
    goto v_3142;
v_3136:
    v_3158 = stack[-2];
    v_3160 = qcdr(v_3158);
    goto v_3137;
v_3138:
    v_3159 = stack[-1];
    goto v_3139;
v_3140:
    v_3158 = stack[0];
    goto v_3141;
v_3142:
    goto v_3136;
v_3137:
    goto v_3138;
v_3139:
    goto v_3140;
v_3141:
    v_3158 = CC_powers2(elt(env, 0), 3, v_3160, v_3159, v_3158);
    env = stack[-4];
    stack[-1] = v_3158;
    goto v_3152;
v_3148:
    v_3158 = stack[-2];
    v_3158 = qcar(v_3158);
    v_3159 = qcar(v_3158);
    goto v_3149;
v_3150:
    v_3158 = stack[0];
    goto v_3151;
v_3152:
    goto v_3148;
v_3149:
    goto v_3150;
v_3151:
    v_3158 = cons(v_3159, v_3158);
    env = stack[-4];
    stack[0] = v_3158;
    v_3158 = stack[-3];
    stack[-2] = v_3158;
    goto v_3098;
v_3100:
    v_3158 = nil;
v_3097:
    return onevalue(v_3158);
}



// Code for rationalizei

static LispObject CC_rationalizei(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3200, v_3201;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_3091;
// end of prologue
    v_3200 = stack[-1];
    v_3200 = qcdr(v_3200);
    stack[-2] = v_3200;
    v_3201 = v_3200;
    v_3200 = v_3201;
    if (!consp(v_3200)) goto v_3107;
    else goto v_3108;
v_3107:
    v_3200 = lisp_true;
    goto v_3106;
v_3108:
    v_3200 = v_3201;
    v_3200 = qcar(v_3200);
    v_3200 = (consp(v_3200) ? nil : lisp_true);
    goto v_3106;
    v_3200 = nil;
v_3106:
    if (v_3200 == nil) goto v_3101;
    else goto v_3099;
v_3101:
    goto v_3122;
v_3118:
    v_3201 = elt(env, 1); // i
    goto v_3119;
v_3120:
    v_3200 = stack[-2];
    goto v_3121;
v_3122:
    goto v_3118;
v_3119:
    goto v_3120;
v_3121:
    v_3200 = Lsmemq(nil, v_3201, v_3200);
    env = stack[-3];
    if (v_3200 == nil) goto v_3099;
    goto v_3100;
v_3099:
    v_3200 = stack[-1];
    goto v_3096;
v_3100:
    goto v_3131;
v_3127:
    v_3201 = elt(env, 1); // i
    goto v_3128;
v_3129:
    v_3200 = qvalue(elt(env, 2)); // kord!*
    goto v_3130;
v_3131:
    goto v_3127;
v_3128:
    goto v_3129;
v_3130:
    v_3200 = cons(v_3201, v_3200);
    env = stack[-3];
// Binding kord!*
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-3, 2, 0);
    qvalue(elt(env, 2)) = v_3200; // kord!*
    v_3200 = stack[-1];
    fn = elt(env, 4); // reordsq
    v_3200 = (*qfn1(fn))(fn, v_3200);
    env = stack[-3];
    stack[-2] = v_3200;
    ;}  // end of a binding scope
    goto v_3149;
v_3145:
    v_3200 = stack[-2];
    v_3200 = qcdr(v_3200);
    stack[0] = v_3200;
    v_3200 = qcar(v_3200);
    v_3201 = qcar(v_3200);
    goto v_3146;
v_3147:
    v_3200 = elt(env, 3); // (i . 1)
    goto v_3148;
v_3149:
    goto v_3145;
v_3146:
    goto v_3147;
v_3148:
    if (equal(v_3201, v_3200)) goto v_3143;
    else goto v_3144;
v_3143:
    v_3200 = stack[0];
    v_3200 = qcdr(v_3200);
    v_3200 = (v_3200 == nil ? lisp_true : nil);
    goto v_3142;
v_3144:
    v_3200 = nil;
    goto v_3142;
    v_3200 = nil;
v_3142:
    if (v_3200 == nil) goto v_3140;
    goto v_3166;
v_3162:
    goto v_3173;
v_3169:
    goto v_3180;
v_3176:
    goto v_3186;
v_3182:
    v_3201 = elt(env, 1); // i
    goto v_3183;
v_3184:
    v_3200 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3185;
v_3186:
    goto v_3182;
v_3183:
    goto v_3184;
v_3185:
    fn = elt(env, 5); // to
    v_3201 = (*qfn2(fn))(fn, v_3201, v_3200);
    env = stack[-3];
    goto v_3177;
v_3178:
    v_3200 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3179;
v_3180:
    goto v_3176;
v_3177:
    goto v_3178;
v_3179:
    v_3200 = cons(v_3201, v_3200);
    env = stack[-3];
    stack[-1] = ncons(v_3200);
    env = stack[-3];
    goto v_3170;
v_3171:
    v_3200 = stack[-2];
    v_3200 = qcar(v_3200);
    fn = elt(env, 6); // reorder
    v_3200 = (*qfn1(fn))(fn, v_3200);
    env = stack[-3];
    goto v_3172;
v_3173:
    goto v_3169;
v_3170:
    goto v_3171;
v_3172:
    fn = elt(env, 7); // multf
    v_3200 = (*qfn2(fn))(fn, stack[-1], v_3200);
    env = stack[-3];
    fn = elt(env, 8); // negf
    stack[-1] = (*qfn1(fn))(fn, v_3200);
    env = stack[-3];
    goto v_3163;
v_3164:
    v_3200 = stack[0];
    v_3200 = qcar(v_3200);
    v_3200 = qcdr(v_3200);
    fn = elt(env, 6); // reorder
    v_3200 = (*qfn1(fn))(fn, v_3200);
    goto v_3165;
v_3166:
    goto v_3162;
v_3163:
    goto v_3164;
v_3165:
    {
        LispObject v_3205 = stack[-1];
        return cons(v_3205, v_3200);
    }
v_3140:
    v_3200 = stack[-1];
    goto v_3138;
    v_3200 = nil;
v_3138:
v_3096:
    return onevalue(v_3200);
}



// Code for mintype

static LispObject CC_mintype(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3103, v_3104;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3103 = v_3091;
// end of prologue
    v_3104 = v_3103;
    if (!consp(v_3104)) goto v_3095;
    else goto v_3096;
v_3095:
    goto v_3094;
v_3096:
    v_3103 = qcar(v_3103);
    goto v_3094;
    v_3103 = nil;
v_3094:
    return onevalue(v_3103);
}



// Code for nextarg

static LispObject CC_nextarg(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3104, v_3105;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3105 = v_3091;
// end of prologue
    v_3104 = qvalue(elt(env, 1)); // symm
    if (v_3104 == nil) goto v_3096;
    v_3104 = v_3105;
    {
        fn = elt(env, 2); // s!-nextarg
        return (*qfn1(fn))(fn, v_3104);
    }
v_3096:
    v_3104 = v_3105;
    {
        fn = elt(env, 3); // o!-nextarg
        return (*qfn1(fn))(fn, v_3104);
    }
    v_3104 = nil;
    return onevalue(v_3104);
}



// Code for layout!-formula

static LispObject CC_layoutKformula(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3184, v_3185;
    LispObject fn;
    LispObject v_3093, v_3092, v_3091;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "layout-formula");
    va_start(aa, nargs);
    v_3091 = va_arg(aa, LispObject);
    v_3092 = va_arg(aa, LispObject);
    v_3093 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_3093,v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_3091,v_3092,v_3093);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-6] = v_3093;
    stack[-7] = v_3092;
    stack[-8] = v_3091;
// end of prologue
// Binding ycoord!*
// FLUIDBIND: reloadenv=10 litvec-offset=1 saveloc=9
{   bind_fluid_stack bind_fluid_var(-10, 1, -9);
    qvalue(elt(env, 1)) = nil; // ycoord!*
// Binding ymin!*
// FLUIDBIND: reloadenv=10 litvec-offset=2 saveloc=5
{   bind_fluid_stack bind_fluid_var(-10, 2, -5);
    qvalue(elt(env, 2)) = nil; // ymin!*
// Binding ymax!*
// FLUIDBIND: reloadenv=10 litvec-offset=3 saveloc=4
{   bind_fluid_stack bind_fluid_var(-10, 3, -4);
    qvalue(elt(env, 3)) = nil; // ymax!*
// Binding posn!*
// FLUIDBIND: reloadenv=10 litvec-offset=4 saveloc=3
{   bind_fluid_stack bind_fluid_var(-10, 4, -3);
    qvalue(elt(env, 4)) = nil; // posn!*
// Binding pline!*
// FLUIDBIND: reloadenv=10 litvec-offset=5 saveloc=2
{   bind_fluid_stack bind_fluid_var(-10, 5, -2);
    qvalue(elt(env, 5)) = nil; // pline!*
// Binding testing!-width!*
// FLUIDBIND: reloadenv=10 litvec-offset=6 saveloc=1
{   bind_fluid_stack bind_fluid_var(-10, 6, -1);
    qvalue(elt(env, 6)) = nil; // testing!-width!*
// Binding overflowed!*
// FLUIDBIND: reloadenv=10 litvec-offset=7 saveloc=0
{   bind_fluid_stack bind_fluid_var(-10, 7, 0);
    qvalue(elt(env, 7)) = nil; // overflowed!*
    v_3184 = nil;
    qvalue(elt(env, 7)) = v_3184; // overflowed!*
    qvalue(elt(env, 5)) = v_3184; // pline!*
    v_3184 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 3)) = v_3184; // ymax!*
    qvalue(elt(env, 2)) = v_3184; // ymin!*
    qvalue(elt(env, 1)) = v_3184; // ycoord!*
    v_3184 = qvalue(elt(env, 8)); // orig!*
    qvalue(elt(env, 4)) = v_3184; // posn!*
    v_3184 = lisp_true;
    qvalue(elt(env, 6)) = v_3184; // testing!-width!*
    v_3184 = stack[-6];
    if (v_3184 == nil) goto v_3111;
    goto v_3121;
v_3117:
    v_3185 = stack[-6];
    goto v_3118;
v_3119:
    v_3184 = elt(env, 9); // inbrackets
    goto v_3120;
v_3121:
    goto v_3117;
v_3118:
    goto v_3119;
v_3120:
    if (v_3185 == v_3184) goto v_3115;
    else goto v_3116;
v_3115:
    v_3184 = elt(env, 10); // "("
    fn = elt(env, 12); // prin2!*
    v_3184 = (*qfn1(fn))(fn, v_3184);
    env = stack[-10];
    goto v_3114;
v_3116:
    v_3184 = stack[-6];
    fn = elt(env, 13); // oprin
    v_3184 = (*qfn1(fn))(fn, v_3184);
    env = stack[-10];
    goto v_3114;
v_3114:
    goto v_3109;
v_3111:
v_3109:
    goto v_3135;
v_3131:
    v_3185 = stack[-8];
    goto v_3132;
v_3133:
    v_3184 = stack[-7];
    goto v_3134;
v_3135:
    goto v_3131;
v_3132:
    goto v_3133;
v_3134:
    fn = elt(env, 14); // maprint
    v_3184 = (*qfn2(fn))(fn, v_3185, v_3184);
    env = stack[-10];
    goto v_3146;
v_3142:
    v_3185 = stack[-6];
    goto v_3143;
v_3144:
    v_3184 = elt(env, 9); // inbrackets
    goto v_3145;
v_3146:
    goto v_3142;
v_3143:
    goto v_3144;
v_3145:
    if (v_3185 == v_3184) goto v_3140;
    else goto v_3141;
v_3140:
    v_3184 = elt(env, 11); // ")"
    fn = elt(env, 12); // prin2!*
    v_3184 = (*qfn1(fn))(fn, v_3184);
    env = stack[-10];
    goto v_3139;
v_3141:
v_3139:
    v_3184 = qvalue(elt(env, 7)); // overflowed!*
    if (v_3184 == nil) goto v_3154;
    v_3184 = nil;
    goto v_3103;
v_3154:
    goto v_3166;
v_3160:
    stack[-7] = qvalue(elt(env, 5)); // pline!*
    goto v_3161;
v_3162:
    goto v_3173;
v_3169:
    v_3185 = qvalue(elt(env, 4)); // posn!*
    goto v_3170;
v_3171:
    v_3184 = qvalue(elt(env, 8)); // orig!*
    goto v_3172;
v_3173:
    goto v_3169;
v_3170:
    goto v_3171;
v_3172:
    stack[-6] = difference2(v_3185, v_3184);
    env = stack[-10];
    goto v_3163;
v_3164:
    goto v_3181;
v_3177:
    v_3185 = qvalue(elt(env, 2)); // ymin!*
    goto v_3178;
v_3179:
    v_3184 = qvalue(elt(env, 3)); // ymax!*
    goto v_3180;
v_3181:
    goto v_3177;
v_3178:
    goto v_3179;
v_3180:
    v_3184 = cons(v_3185, v_3184);
    env = stack[-10];
    goto v_3165;
v_3166:
    goto v_3160;
v_3161:
    goto v_3162;
v_3163:
    goto v_3164;
v_3165:
    v_3184 = acons(stack[-7], stack[-6], v_3184);
    goto v_3103;
    v_3184 = nil;
v_3103:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_3184);
}



// Code for abs!:

static LispObject CC_absT(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3126, v_3127;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3091;
// end of prologue
    goto v_3102;
v_3098:
    v_3126 = stack[0];
    v_3126 = qcdr(v_3126);
    v_3127 = qcar(v_3126);
    goto v_3099;
v_3100:
    v_3126 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3101;
v_3102:
    goto v_3098;
v_3099:
    goto v_3100;
v_3101:
    v_3126 = (LispObject)greaterp2(v_3127, v_3126);
    v_3126 = v_3126 ? lisp_true : nil;
    env = stack[-2];
    if (v_3126 == nil) goto v_3096;
    v_3126 = stack[0];
    goto v_3094;
v_3096:
    goto v_3117;
v_3111:
    stack[-1] = elt(env, 1); // !:rd!:
    goto v_3112;
v_3113:
    v_3126 = stack[0];
    v_3126 = qcdr(v_3126);
    v_3126 = qcar(v_3126);
    v_3127 = negate(v_3126);
    goto v_3114;
v_3115:
    v_3126 = stack[0];
    v_3126 = qcdr(v_3126);
    v_3126 = qcdr(v_3126);
    goto v_3116;
v_3117:
    goto v_3111;
v_3112:
    goto v_3113;
v_3114:
    goto v_3115;
v_3116:
    {
        LispObject v_3130 = stack[-1];
        return list2star(v_3130, v_3127, v_3126);
    }
    v_3126 = nil;
v_3094:
    return onevalue(v_3126);
}



// Code for list2widestring

static LispObject CC_list2widestring(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3551, v_3552, v_3553;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_3091;
// end of prologue
    v_3551 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_3551;
    v_3551 = stack[-8];
    stack[0] = v_3551;
v_3099:
    v_3551 = stack[0];
    if (v_3551 == nil) goto v_3106;
    else goto v_3107;
v_3106:
    goto v_3100;
v_3107:
    v_3551 = stack[0];
    v_3551 = qcar(v_3551);
    stack[-9] = v_3551;
    v_3551 = stack[0];
    v_3551 = qcdr(v_3551);
    stack[0] = v_3551;
    v_3551 = stack[-9];
    if (symbolp(v_3551)) goto v_3115;
    else goto v_3116;
v_3115:
    v_3551 = stack[-9];
    v_3551 = Lsymbol_name(nil, v_3551);
    env = stack[-10];
    fn = elt(env, 5); // widestring2list
    v_3551 = (*qfn1(fn))(fn, v_3551);
    env = stack[-10];
    v_3551 = qcar(v_3551);
    stack[-9] = v_3551;
    goto v_3114;
v_3116:
    v_3551 = stack[-9];
    v_3551 = Lstringp(nil, v_3551);
    env = stack[-10];
    if (v_3551 == nil) goto v_3123;
    goto v_3132;
v_3128:
    v_3552 = stack[-9];
    goto v_3129;
v_3130:
    v_3551 = elt(env, 1); // ""
    goto v_3131;
v_3132:
    goto v_3128;
v_3129:
    goto v_3130;
v_3131:
    if (equal(v_3552, v_3551)) goto v_3123;
    v_3551 = stack[-9];
    fn = elt(env, 5); // widestring2list
    v_3551 = (*qfn1(fn))(fn, v_3551);
    env = stack[-10];
    v_3551 = qcar(v_3551);
    stack[-9] = v_3551;
    goto v_3114;
v_3123:
    v_3551 = stack[-9];
    v_3551 = integerp(v_3551);
    if (v_3551 == nil) goto v_3138;
    else goto v_3139;
v_3138:
    v_3551 = elt(env, 2); // "Invalid item in arg to list2widestring"
    fn = elt(env, 6); // rederr
    v_3551 = (*qfn1(fn))(fn, v_3551);
    env = stack[-10];
    goto v_3114;
v_3139:
v_3114:
    goto v_3153;
v_3149:
    v_3552 = stack[-9];
    goto v_3150;
v_3151:
    v_3551 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3152;
v_3153:
    goto v_3149;
v_3150:
    goto v_3151;
v_3152:
    v_3551 = (LispObject)lessp2(v_3552, v_3551);
    v_3551 = v_3551 ? lisp_true : nil;
    env = stack[-10];
    if (v_3551 == nil) goto v_3147;
    goto v_3161;
v_3157:
    v_3552 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3158;
v_3159:
    v_3551 = elt(env, 3); // "Negative integer in list2widestring"
    goto v_3160;
v_3161:
    goto v_3157;
v_3158:
    goto v_3159;
v_3160:
    fn = elt(env, 7); // error
    v_3551 = (*qfn2(fn))(fn, v_3552, v_3551);
    env = stack[-10];
    goto v_3145;
v_3147:
    goto v_3171;
v_3167:
    v_3552 = stack[-9];
    goto v_3168;
v_3169:
    v_3551 = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_3170;
v_3171:
    goto v_3167;
v_3168:
    goto v_3169;
v_3170:
    v_3551 = (LispObject)lessp2(v_3552, v_3551);
    v_3551 = v_3551 ? lisp_true : nil;
    env = stack[-10];
    if (v_3551 == nil) goto v_3165;
    v_3551 = stack[-6];
    v_3551 = add1(v_3551);
    env = stack[-10];
    stack[-6] = v_3551;
    goto v_3145;
v_3165:
    goto v_3183;
v_3179:
    v_3552 = stack[-9];
    goto v_3180;
v_3181:
    v_3551 = (LispObject)32768+TAG_FIXNUM; // 2048
    goto v_3182;
v_3183:
    goto v_3179;
v_3180:
    goto v_3181;
v_3182:
    v_3551 = (LispObject)lessp2(v_3552, v_3551);
    v_3551 = v_3551 ? lisp_true : nil;
    env = stack[-10];
    if (v_3551 == nil) goto v_3177;
    goto v_3191;
v_3187:
    v_3552 = stack[-6];
    goto v_3188;
v_3189:
    v_3551 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_3190;
v_3191:
    goto v_3187;
v_3188:
    goto v_3189;
v_3190:
    v_3551 = plus2(v_3552, v_3551);
    env = stack[-10];
    stack[-6] = v_3551;
    goto v_3145;
v_3177:
    goto v_3201;
v_3197:
    v_3552 = stack[-9];
    goto v_3198;
v_3199:
    v_3551 = (LispObject)1048576+TAG_FIXNUM; // 65536
    goto v_3200;
v_3201:
    goto v_3197;
v_3198:
    goto v_3199;
v_3200:
    v_3551 = (LispObject)lessp2(v_3552, v_3551);
    v_3551 = v_3551 ? lisp_true : nil;
    env = stack[-10];
    if (v_3551 == nil) goto v_3195;
    goto v_3209;
v_3205:
    v_3552 = stack[-6];
    goto v_3206;
v_3207:
    v_3551 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_3208;
v_3209:
    goto v_3205;
v_3206:
    goto v_3207;
v_3208:
    v_3551 = plus2(v_3552, v_3551);
    env = stack[-10];
    stack[-6] = v_3551;
    goto v_3145;
v_3195:
    goto v_3219;
v_3215:
    v_3552 = stack[-9];
    goto v_3216;
v_3217:
    v_3551 = (LispObject)17825792+TAG_FIXNUM; // 1114112
    goto v_3218;
v_3219:
    goto v_3215;
v_3216:
    goto v_3217;
v_3218:
    v_3551 = (LispObject)lessp2(v_3552, v_3551);
    v_3551 = v_3551 ? lisp_true : nil;
    env = stack[-10];
    if (v_3551 == nil) goto v_3213;
    goto v_3227;
v_3223:
    v_3552 = stack[-6];
    goto v_3224;
v_3225:
    v_3551 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_3226;
v_3227:
    goto v_3223;
v_3224:
    goto v_3225;
v_3226:
    v_3551 = plus2(v_3552, v_3551);
    env = stack[-10];
    stack[-6] = v_3551;
    goto v_3145;
v_3213:
    goto v_3237;
v_3233:
    v_3552 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3234;
v_3235:
    v_3551 = elt(env, 4); // "Integer too large in list2widestring"
    goto v_3236;
v_3237:
    goto v_3233;
v_3234:
    goto v_3235;
v_3236:
    fn = elt(env, 7); // error
    v_3551 = (*qfn2(fn))(fn, v_3552, v_3551);
    env = stack[-10];
    goto v_3145;
v_3145:
    goto v_3099;
v_3100:
    v_3551 = stack[-6];
    fn = elt(env, 8); // allocate!-string
    v_3551 = (*qfn1(fn))(fn, v_3551);
    env = stack[-10];
    stack[-7] = v_3551;
    v_3551 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_3551;
v_3245:
    v_3551 = stack[-8];
    if (v_3551 == nil) goto v_3248;
    else goto v_3249;
v_3248:
    goto v_3244;
v_3249:
    v_3551 = stack[-8];
    v_3551 = qcar(v_3551);
    stack[-9] = v_3551;
    v_3551 = stack[-9];
    if (symbolp(v_3551)) goto v_3256;
    else goto v_3257;
v_3256:
    v_3551 = stack[-9];
    v_3551 = Lsymbol_name(nil, v_3551);
    env = stack[-10];
    fn = elt(env, 5); // widestring2list
    v_3551 = (*qfn1(fn))(fn, v_3551);
    env = stack[-10];
    v_3551 = qcar(v_3551);
    stack[-9] = v_3551;
    goto v_3255;
v_3257:
    v_3551 = stack[-9];
    v_3551 = Lstringp(nil, v_3551);
    env = stack[-10];
    if (v_3551 == nil) goto v_3264;
    goto v_3273;
v_3269:
    v_3552 = stack[-9];
    goto v_3270;
v_3271:
    v_3551 = elt(env, 1); // ""
    goto v_3272;
v_3273:
    goto v_3269;
v_3270:
    goto v_3271;
v_3272:
    if (equal(v_3552, v_3551)) goto v_3264;
    v_3551 = stack[-9];
    fn = elt(env, 5); // widestring2list
    v_3551 = (*qfn1(fn))(fn, v_3551);
    env = stack[-10];
    v_3551 = qcar(v_3551);
    stack[-9] = v_3551;
    goto v_3255;
v_3264:
v_3255:
    v_3551 = stack[-8];
    v_3551 = qcdr(v_3551);
    stack[-8] = v_3551;
    goto v_3290;
v_3286:
    v_3552 = stack[-9];
    goto v_3287;
v_3288:
    v_3551 = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_3289;
v_3290:
    goto v_3286;
v_3287:
    goto v_3288;
v_3289:
    v_3551 = (LispObject)lessp2(v_3552, v_3551);
    v_3551 = v_3551 ? lisp_true : nil;
    env = stack[-10];
    if (v_3551 == nil) goto v_3284;
    goto v_3300;
v_3294:
    v_3553 = stack[-7];
    goto v_3295;
v_3296:
    v_3552 = stack[-6];
    goto v_3297;
v_3298:
    v_3551 = stack[-9];
    goto v_3299;
v_3300:
    goto v_3294;
v_3295:
    goto v_3296;
v_3297:
    goto v_3298;
v_3299:
    fn = elt(env, 9); // string!-store
    v_3551 = (*qfnn(fn))(fn, 3, v_3553, v_3552, v_3551);
    env = stack[-10];
    v_3551 = stack[-6];
    v_3551 = add1(v_3551);
    env = stack[-10];
    stack[-6] = v_3551;
    goto v_3282;
v_3284:
    goto v_3313;
v_3309:
    v_3552 = stack[-9];
    goto v_3310;
v_3311:
    v_3551 = (LispObject)32768+TAG_FIXNUM; // 2048
    goto v_3312;
v_3313:
    goto v_3309;
v_3310:
    goto v_3311;
v_3312:
    v_3551 = (LispObject)lessp2(v_3552, v_3551);
    v_3551 = v_3551 ? lisp_true : nil;
    env = stack[-10];
    if (v_3551 == nil) goto v_3307;
    goto v_3325;
v_3317:
    stack[-3] = stack[-7];
    goto v_3318;
v_3319:
    stack[-2] = stack[-6];
    goto v_3320;
v_3321:
    goto v_3333;
v_3329:
    stack[0] = (LispObject)3072+TAG_FIXNUM; // 192
    goto v_3330;
v_3331:
    goto v_3340;
v_3336:
    v_3552 = stack[-9];
    goto v_3337;
v_3338:
    v_3551 = (LispObject)-96+TAG_FIXNUM; // -6
    goto v_3339;
v_3340:
    goto v_3336;
v_3337:
    goto v_3338;
v_3339:
    fn = elt(env, 10); // lshift
    v_3551 = (*qfn2(fn))(fn, v_3552, v_3551);
    env = stack[-10];
    goto v_3332;
v_3333:
    goto v_3329;
v_3330:
    goto v_3331;
v_3332:
    stack[-1] = plus2(stack[0], v_3551);
    env = stack[-10];
    goto v_3322;
v_3323:
    goto v_3348;
v_3344:
    stack[0] = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_3345;
v_3346:
    goto v_3355;
v_3351:
    v_3552 = stack[-9];
    goto v_3352;
v_3353:
    v_3551 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_3354;
v_3355:
    goto v_3351;
v_3352:
    goto v_3353;
v_3354:
    fn = elt(env, 11); // land
    v_3551 = (*qfn2(fn))(fn, v_3552, v_3551);
    env = stack[-10];
    goto v_3347;
v_3348:
    goto v_3344;
v_3345:
    goto v_3346;
v_3347:
    v_3551 = plus2(stack[0], v_3551);
    env = stack[-10];
    goto v_3324;
v_3325:
    goto v_3317;
v_3318:
    goto v_3319;
v_3320:
    goto v_3321;
v_3322:
    goto v_3323;
v_3324:
    fn = elt(env, 12); // string!-store2
    v_3551 = (*qfnn(fn))(fn, 4, stack[-3], stack[-2], stack[-1], v_3551);
    env = stack[-10];
    goto v_3363;
v_3359:
    v_3552 = stack[-6];
    goto v_3360;
v_3361:
    v_3551 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_3362;
v_3363:
    goto v_3359;
v_3360:
    goto v_3361;
v_3362:
    v_3551 = plus2(v_3552, v_3551);
    env = stack[-10];
    stack[-6] = v_3551;
    goto v_3282;
v_3307:
    goto v_3373;
v_3369:
    v_3552 = stack[-9];
    goto v_3370;
v_3371:
    v_3551 = (LispObject)1048576+TAG_FIXNUM; // 65536
    goto v_3372;
v_3373:
    goto v_3369;
v_3370:
    goto v_3371;
v_3372:
    v_3551 = (LispObject)lessp2(v_3552, v_3551);
    v_3551 = v_3551 ? lisp_true : nil;
    env = stack[-10];
    if (v_3551 == nil) goto v_3367;
    goto v_3387;
v_3377:
    stack[-4] = stack[-7];
    goto v_3378;
v_3379:
    stack[-3] = stack[-6];
    goto v_3380;
v_3381:
    goto v_3395;
v_3391:
    stack[0] = (LispObject)3584+TAG_FIXNUM; // 224
    goto v_3392;
v_3393:
    goto v_3402;
v_3398:
    v_3552 = stack[-9];
    goto v_3399;
v_3400:
    v_3551 = (LispObject)-192+TAG_FIXNUM; // -12
    goto v_3401;
v_3402:
    goto v_3398;
v_3399:
    goto v_3400;
v_3401:
    fn = elt(env, 10); // lshift
    v_3551 = (*qfn2(fn))(fn, v_3552, v_3551);
    env = stack[-10];
    goto v_3394;
v_3395:
    goto v_3391;
v_3392:
    goto v_3393;
v_3394:
    stack[-2] = plus2(stack[0], v_3551);
    env = stack[-10];
    goto v_3382;
v_3383:
    goto v_3410;
v_3406:
    stack[0] = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_3407;
v_3408:
    goto v_3417;
v_3413:
    goto v_3423;
v_3419:
    v_3552 = stack[-9];
    goto v_3420;
v_3421:
    v_3551 = (LispObject)-96+TAG_FIXNUM; // -6
    goto v_3422;
v_3423:
    goto v_3419;
v_3420:
    goto v_3421;
v_3422:
    fn = elt(env, 10); // lshift
    v_3552 = (*qfn2(fn))(fn, v_3552, v_3551);
    env = stack[-10];
    goto v_3414;
v_3415:
    v_3551 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_3416;
v_3417:
    goto v_3413;
v_3414:
    goto v_3415;
v_3416:
    fn = elt(env, 11); // land
    v_3551 = (*qfn2(fn))(fn, v_3552, v_3551);
    env = stack[-10];
    goto v_3409;
v_3410:
    goto v_3406;
v_3407:
    goto v_3408;
v_3409:
    stack[-1] = plus2(stack[0], v_3551);
    env = stack[-10];
    goto v_3384;
v_3385:
    goto v_3432;
v_3428:
    stack[0] = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_3429;
v_3430:
    goto v_3439;
v_3435:
    v_3552 = stack[-9];
    goto v_3436;
v_3437:
    v_3551 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_3438;
v_3439:
    goto v_3435;
v_3436:
    goto v_3437;
v_3438:
    fn = elt(env, 11); // land
    v_3551 = (*qfn2(fn))(fn, v_3552, v_3551);
    env = stack[-10];
    goto v_3431;
v_3432:
    goto v_3428;
v_3429:
    goto v_3430;
v_3431:
    v_3551 = plus2(stack[0], v_3551);
    env = stack[-10];
    goto v_3386;
v_3387:
    goto v_3377;
v_3378:
    goto v_3379;
v_3380:
    goto v_3381;
v_3382:
    goto v_3383;
v_3384:
    goto v_3385;
v_3386:
    fn = elt(env, 13); // string!-store3
    v_3551 = (*qfnn(fn))(fn, 5, stack[-4], stack[-3], stack[-2], stack[-1], v_3551);
    env = stack[-10];
    goto v_3447;
v_3443:
    v_3552 = stack[-6];
    goto v_3444;
v_3445:
    v_3551 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_3446;
v_3447:
    goto v_3443;
v_3444:
    goto v_3445;
v_3446:
    v_3551 = plus2(v_3552, v_3551);
    env = stack[-10];
    stack[-6] = v_3551;
    goto v_3282;
v_3367:
    goto v_3465;
v_3453:
    stack[-5] = stack[-7];
    goto v_3454;
v_3455:
    stack[-4] = stack[-6];
    goto v_3456;
v_3457:
    goto v_3473;
v_3469:
    stack[0] = (LispObject)3840+TAG_FIXNUM; // 240
    goto v_3470;
v_3471:
    goto v_3480;
v_3476:
    v_3552 = stack[-9];
    goto v_3477;
v_3478:
    v_3551 = (LispObject)-288+TAG_FIXNUM; // -18
    goto v_3479;
v_3480:
    goto v_3476;
v_3477:
    goto v_3478;
v_3479:
    fn = elt(env, 10); // lshift
    v_3551 = (*qfn2(fn))(fn, v_3552, v_3551);
    env = stack[-10];
    goto v_3472;
v_3473:
    goto v_3469;
v_3470:
    goto v_3471;
v_3472:
    stack[-3] = plus2(stack[0], v_3551);
    env = stack[-10];
    goto v_3458;
v_3459:
    goto v_3488;
v_3484:
    stack[0] = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_3485;
v_3486:
    goto v_3495;
v_3491:
    goto v_3501;
v_3497:
    v_3552 = stack[-9];
    goto v_3498;
v_3499:
    v_3551 = (LispObject)-192+TAG_FIXNUM; // -12
    goto v_3500;
v_3501:
    goto v_3497;
v_3498:
    goto v_3499;
v_3500:
    fn = elt(env, 10); // lshift
    v_3552 = (*qfn2(fn))(fn, v_3552, v_3551);
    env = stack[-10];
    goto v_3492;
v_3493:
    v_3551 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_3494;
v_3495:
    goto v_3491;
v_3492:
    goto v_3493;
v_3494:
    fn = elt(env, 11); // land
    v_3551 = (*qfn2(fn))(fn, v_3552, v_3551);
    env = stack[-10];
    goto v_3487;
v_3488:
    goto v_3484;
v_3485:
    goto v_3486;
v_3487:
    stack[-2] = plus2(stack[0], v_3551);
    env = stack[-10];
    goto v_3460;
v_3461:
    goto v_3510;
v_3506:
    stack[0] = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_3507;
v_3508:
    goto v_3517;
v_3513:
    goto v_3523;
v_3519:
    v_3552 = stack[-9];
    goto v_3520;
v_3521:
    v_3551 = (LispObject)-96+TAG_FIXNUM; // -6
    goto v_3522;
v_3523:
    goto v_3519;
v_3520:
    goto v_3521;
v_3522:
    fn = elt(env, 10); // lshift
    v_3552 = (*qfn2(fn))(fn, v_3552, v_3551);
    env = stack[-10];
    goto v_3514;
v_3515:
    v_3551 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_3516;
v_3517:
    goto v_3513;
v_3514:
    goto v_3515;
v_3516:
    fn = elt(env, 11); // land
    v_3551 = (*qfn2(fn))(fn, v_3552, v_3551);
    env = stack[-10];
    goto v_3509;
v_3510:
    goto v_3506;
v_3507:
    goto v_3508;
v_3509:
    stack[-1] = plus2(stack[0], v_3551);
    env = stack[-10];
    goto v_3462;
v_3463:
    goto v_3532;
v_3528:
    stack[0] = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_3529;
v_3530:
    goto v_3539;
v_3535:
    v_3552 = stack[-9];
    goto v_3536;
v_3537:
    v_3551 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_3538;
v_3539:
    goto v_3535;
v_3536:
    goto v_3537;
v_3538:
    fn = elt(env, 11); // land
    v_3551 = (*qfn2(fn))(fn, v_3552, v_3551);
    env = stack[-10];
    goto v_3531;
v_3532:
    goto v_3528;
v_3529:
    goto v_3530;
v_3531:
    v_3551 = plus2(stack[0], v_3551);
    env = stack[-10];
    goto v_3464;
v_3465:
    goto v_3453;
v_3454:
    goto v_3455;
v_3456:
    goto v_3457;
v_3458:
    goto v_3459;
v_3460:
    goto v_3461;
v_3462:
    goto v_3463;
v_3464:
    fn = elt(env, 14); // string!-store4
    v_3551 = (*qfnn(fn))(fn, 6, stack[-5], stack[-4], stack[-3], stack[-2], stack[-1], v_3551);
    env = stack[-10];
    goto v_3547;
v_3543:
    v_3552 = stack[-6];
    goto v_3544;
v_3545:
    v_3551 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_3546;
v_3547:
    goto v_3543;
v_3544:
    goto v_3545;
v_3546:
    v_3551 = plus2(v_3552, v_3551);
    env = stack[-10];
    stack[-6] = v_3551;
    goto v_3282;
v_3282:
    goto v_3245;
v_3244:
    v_3551 = stack[-7];
    return onevalue(v_3551);
}



// Code for mv!-pow!-mv!-term!-!+

static LispObject CC_mvKpowKmvKtermKL(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3111, v_3112;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_3092;
    v_3111 = v_3091;
// end of prologue
    goto v_3099;
v_3095:
    goto v_3105;
v_3101:
    v_3112 = v_3111;
    goto v_3102;
v_3103:
    v_3111 = stack[0];
    v_3111 = qcar(v_3111);
    goto v_3104;
v_3105:
    goto v_3101;
v_3102:
    goto v_3103;
v_3104:
    fn = elt(env, 1); // mv!-pow!-!+
    v_3112 = (*qfn2(fn))(fn, v_3112, v_3111);
    goto v_3096;
v_3097:
    v_3111 = stack[0];
    v_3111 = qcdr(v_3111);
    goto v_3098;
v_3099:
    goto v_3095;
v_3096:
    goto v_3097;
v_3098:
    return cons(v_3112, v_3111);
}



// Code for rnplus!:

static LispObject CC_rnplusT(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3142, v_3143;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3092;
    stack[-1] = v_3091;
// end of prologue
    goto v_3099;
v_3095:
    goto v_3105;
v_3101:
    goto v_3111;
v_3107:
    v_3142 = stack[-1];
    v_3142 = qcdr(v_3142);
    v_3143 = qcar(v_3142);
    goto v_3108;
v_3109:
    v_3142 = stack[0];
    v_3142 = qcdr(v_3142);
    v_3142 = qcdr(v_3142);
    goto v_3110;
v_3111:
    goto v_3107;
v_3108:
    goto v_3109;
v_3110:
    stack[-2] = times2(v_3143, v_3142);
    env = stack[-3];
    goto v_3102;
v_3103:
    goto v_3123;
v_3119:
    v_3142 = stack[-1];
    v_3142 = qcdr(v_3142);
    v_3143 = qcdr(v_3142);
    goto v_3120;
v_3121:
    v_3142 = stack[0];
    v_3142 = qcdr(v_3142);
    v_3142 = qcar(v_3142);
    goto v_3122;
v_3123:
    goto v_3119;
v_3120:
    goto v_3121;
v_3122:
    v_3142 = times2(v_3143, v_3142);
    env = stack[-3];
    goto v_3104;
v_3105:
    goto v_3101;
v_3102:
    goto v_3103;
v_3104:
    stack[-2] = plus2(stack[-2], v_3142);
    env = stack[-3];
    goto v_3096;
v_3097:
    goto v_3135;
v_3131:
    v_3142 = stack[-1];
    v_3142 = qcdr(v_3142);
    v_3143 = qcdr(v_3142);
    goto v_3132;
v_3133:
    v_3142 = stack[0];
    v_3142 = qcdr(v_3142);
    v_3142 = qcdr(v_3142);
    goto v_3134;
v_3135:
    goto v_3131;
v_3132:
    goto v_3133;
v_3134:
    v_3142 = times2(v_3143, v_3142);
    env = stack[-3];
    goto v_3098;
v_3099:
    goto v_3095;
v_3096:
    goto v_3097;
v_3098:
    {
        LispObject v_3147 = stack[-2];
        fn = elt(env, 1); // mkrn
        return (*qfn2(fn))(fn, v_3147, v_3142);
    }
}



// Code for lalr_analyze_lookaheads

static LispObject CC_lalr_analyze_lookaheads(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3257, v_3258, v_3259;
    LispObject fn;
    argcheck(nargs, 0, "lalr_analyze_lookaheads");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// end of prologue
    stack[-10] = nil;
// Binding d
// FLUIDBIND: reloadenv=11 litvec-offset=1 saveloc=5
{   bind_fluid_stack bind_fluid_var(-11, 1, -5);
    qvalue(elt(env, 1)) = nil; // d
    v_3257 = qvalue(elt(env, 2)); // itemset_collection
    stack[-4] = v_3257;
v_3106:
    v_3257 = stack[-4];
    if (v_3257 == nil) goto v_3110;
    else goto v_3111;
v_3110:
    goto v_3105;
v_3111:
    v_3257 = stack[-4];
    v_3257 = qcar(v_3257);
    stack[-3] = v_3257;
    v_3257 = stack[-3];
    v_3257 = qcar(v_3257);
    stack[-2] = v_3257;
v_3120:
    v_3257 = stack[-2];
    if (v_3257 == nil) goto v_3125;
    else goto v_3126;
v_3125:
    goto v_3119;
v_3126:
    v_3257 = stack[-2];
    v_3257 = qcar(v_3257);
    stack[-1] = v_3257;
    goto v_3137;
v_3133:
    v_3257 = stack[-1];
    v_3258 = qcar(v_3257);
    goto v_3134;
v_3135:
    v_3257 = elt(env, 3); // (-1)
    goto v_3136;
v_3137:
    goto v_3133;
v_3134:
    goto v_3135;
v_3136:
    v_3257 = cons(v_3258, v_3257);
    env = stack[-11];
    v_3257 = ncons(v_3257);
    env = stack[-11];
    fn = elt(env, 5); // lalr_closure
    v_3257 = (*qfn1(fn))(fn, v_3257);
    env = stack[-11];
    stack[0] = v_3257;
v_3144:
    v_3257 = stack[0];
    if (v_3257 == nil) goto v_3150;
    else goto v_3151;
v_3150:
    goto v_3143;
v_3151:
    v_3257 = stack[0];
    v_3257 = qcar(v_3257);
    v_3258 = v_3257;
    v_3257 = v_3258;
    v_3257 = qcar(v_3257);
    stack[-7] = v_3257;
    v_3257 = v_3258;
    v_3257 = qcdr(v_3257);
    stack[-9] = v_3257;
    goto v_3169;
v_3165:
    v_3258 = elt(env, 4); // !.
    goto v_3166;
v_3167:
    v_3257 = stack[-7];
    goto v_3168;
v_3169:
    goto v_3165;
v_3166:
    goto v_3167;
v_3168:
    v_3257 = Lmember(nil, v_3258, v_3257);
    v_3257 = qcdr(v_3257);
    v_3258 = v_3257;
    if (v_3257 == nil) goto v_3164;
    v_3257 = v_3258;
    v_3257 = qcar(v_3257);
    stack[-6] = v_3257;
    v_3257 = v_3258;
    v_3257 = qcdr(v_3257);
    qvalue(elt(env, 1)) = v_3257; // d
    goto v_3183;
v_3179:
    v_3258 = stack[-3];
    goto v_3180;
v_3181:
    v_3257 = stack[-6];
    goto v_3182;
v_3183:
    goto v_3179;
v_3180:
    goto v_3181;
v_3182:
    fn = elt(env, 6); // lalr_goto
    v_3257 = (*qfn2(fn))(fn, v_3258, v_3257);
    env = stack[-11];
    stack[-8] = v_3257;
    goto v_3191;
v_3187:
    goto v_3197;
v_3193:
    v_3258 = stack[-7];
    goto v_3194;
v_3195:
    v_3257 = stack[-6];
    goto v_3196;
v_3197:
    goto v_3193;
v_3194:
    goto v_3195;
v_3196:
    fn = elt(env, 7); // lalr_lr0_move_dot
    v_3258 = (*qfn2(fn))(fn, v_3258, v_3257);
    env = stack[-11];
    goto v_3188;
v_3189:
    v_3257 = stack[-8];
    v_3257 = qcar(v_3257);
    goto v_3190;
v_3191:
    goto v_3187;
v_3188:
    goto v_3189;
v_3190:
    fn = elt(env, 8); // lalr_item_with_rule
    v_3257 = (*qfn2(fn))(fn, v_3258, v_3257);
    env = stack[-11];
    stack[-6] = v_3257;
    v_3257 = stack[-9];
    stack[-7] = v_3257;
v_3205:
    v_3257 = stack[-7];
    if (v_3257 == nil) goto v_3209;
    else goto v_3210;
v_3209:
    goto v_3204;
v_3210:
    v_3257 = stack[-7];
    v_3257 = qcar(v_3257);
    v_3259 = v_3257;
    goto v_3224;
v_3220:
    v_3258 = v_3259;
    goto v_3221;
v_3222:
    v_3257 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_3223;
v_3224:
    goto v_3220;
v_3221:
    goto v_3222;
v_3223:
    if (v_3258 == v_3257) goto v_3218;
    else goto v_3219;
v_3218:
    goto v_3234;
v_3228:
    v_3259 = stack[-1];
    goto v_3229;
v_3230:
    v_3258 = stack[-6];
    goto v_3231;
v_3232:
    v_3257 = stack[-10];
    goto v_3233;
v_3234:
    goto v_3228;
v_3229:
    goto v_3230;
v_3231:
    goto v_3232;
v_3233:
    v_3257 = acons(v_3259, v_3258, v_3257);
    env = stack[-11];
    stack[-10] = v_3257;
    goto v_3217;
v_3219:
    goto v_3245;
v_3241:
    v_3257 = stack[-6];
    goto v_3242;
v_3243:
    v_3258 = v_3259;
    goto v_3244;
v_3245:
    goto v_3241;
v_3242:
    goto v_3243;
v_3244:
    fn = elt(env, 9); // lalr_add_lookahead
    v_3257 = (*qfn2(fn))(fn, v_3257, v_3258);
    env = stack[-11];
    goto v_3217;
v_3217:
    v_3257 = stack[-7];
    v_3257 = qcdr(v_3257);
    stack[-7] = v_3257;
    goto v_3205;
v_3204:
    goto v_3162;
v_3164:
v_3162:
    v_3257 = stack[0];
    v_3257 = qcdr(v_3257);
    stack[0] = v_3257;
    goto v_3144;
v_3143:
    v_3257 = stack[-2];
    v_3257 = qcdr(v_3257);
    stack[-2] = v_3257;
    goto v_3120;
v_3119:
    v_3257 = stack[-4];
    v_3257 = qcdr(v_3257);
    stack[-4] = v_3257;
    goto v_3106;
v_3105:
    v_3257 = stack[-10];
    ;}  // end of a binding scope
    return onevalue(v_3257);
}



// Code for powers1

static LispObject CC_powers1(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3111, v_3112;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_3111 = v_3091;
// end of prologue
    goto v_3100;
v_3094:
    stack[0] = v_3111;
    goto v_3095;
v_3096:
    goto v_3107;
v_3103:
    v_3112 = v_3111;
    goto v_3104;
v_3105:
    v_3111 = nil;
    goto v_3106;
v_3107:
    goto v_3103;
v_3104:
    goto v_3105;
v_3106:
    fn = elt(env, 1); // powers3
    v_3112 = (*qfn2(fn))(fn, v_3112, v_3111);
    env = stack[-1];
    goto v_3097;
v_3098:
    v_3111 = nil;
    goto v_3099;
v_3100:
    goto v_3094;
v_3095:
    goto v_3096;
v_3097:
    goto v_3098;
v_3099:
    {
        LispObject v_3114 = stack[0];
        fn = elt(env, 2); // powers2
        return (*qfnn(fn))(fn, 3, v_3114, v_3112, v_3111);
    }
}



// Code for mcharg

static LispObject CC_mcharg(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3231, v_3232, v_3233;
    LispObject fn;
    LispObject v_3093, v_3092, v_3091;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mcharg");
    va_start(aa, nargs);
    v_3091 = va_arg(aa, LispObject);
    v_3092 = va_arg(aa, LispObject);
    v_3093 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_3093,v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_3091,v_3092,v_3093);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_3093;
    stack[0] = v_3092;
    v_3233 = v_3091;
// end of prologue
    goto v_3103;
v_3099:
    v_3232 = elt(env, 1); // minus
    goto v_3100;
v_3101:
    v_3231 = stack[0];
    goto v_3102;
v_3103:
    goto v_3099;
v_3100:
    goto v_3101;
v_3102:
    v_3231 = Latsoc(nil, v_3232, v_3231);
    if (v_3231 == nil) goto v_3098;
    goto v_3114;
v_3108:
    goto v_3120;
v_3116:
    v_3232 = v_3233;
    goto v_3117;
v_3118:
    v_3231 = stack[0];
    goto v_3119;
v_3120:
    goto v_3116;
v_3117:
    goto v_3118;
v_3119:
    fn = elt(env, 3); // reform!-minus
    v_3233 = (*qfn2(fn))(fn, v_3232, v_3231);
    env = stack[-5];
    goto v_3109;
v_3110:
    v_3232 = stack[0];
    goto v_3111;
v_3112:
    v_3231 = stack[-3];
    goto v_3113;
v_3114:
    goto v_3108;
v_3109:
    goto v_3110;
v_3111:
    goto v_3112;
v_3113:
    {
        fn = elt(env, 4); // mcharg1
        return (*qfnn(fn))(fn, 3, v_3233, v_3232, v_3231);
    }
v_3098:
    v_3231 = stack[0];
    if (v_3231 == nil) goto v_3126;
    goto v_3135;
v_3131:
    v_3231 = stack[0];
    v_3232 = qcar(v_3231);
    goto v_3132;
v_3133:
    v_3231 = elt(env, 2); // slash
    goto v_3134;
v_3135:
    goto v_3131;
v_3132:
    goto v_3133;
v_3134:
    if (!consp(v_3232)) goto v_3126;
    v_3232 = qcar(v_3232);
    if (v_3232 == v_3231) goto v_3129;
    else goto v_3126;
v_3129:
    goto v_3151;
v_3147:
    v_3232 = v_3233;
    goto v_3148;
v_3149:
    v_3231 = stack[0];
    goto v_3150;
v_3151:
    goto v_3147;
v_3148:
    goto v_3149;
v_3150:
    fn = elt(env, 5); // reform!-minus2
    v_3231 = (*qfn2(fn))(fn, v_3232, v_3231);
    env = stack[-5];
    stack[-4] = v_3231;
v_3144:
    v_3231 = stack[-4];
    if (v_3231 == nil) goto v_3156;
    else goto v_3157;
v_3156:
    v_3231 = nil;
    goto v_3143;
v_3157:
    v_3231 = stack[-4];
    v_3231 = qcar(v_3231);
    goto v_3170;
v_3164:
    v_3232 = v_3231;
    v_3233 = qcar(v_3232);
    goto v_3165;
v_3166:
    v_3232 = qcdr(v_3231);
    goto v_3167;
v_3168:
    v_3231 = stack[-3];
    goto v_3169;
v_3170:
    goto v_3164;
v_3165:
    goto v_3166;
v_3167:
    goto v_3168;
v_3169:
    fn = elt(env, 4); // mcharg1
    v_3231 = (*qfnn(fn))(fn, 3, v_3233, v_3232, v_3231);
    env = stack[-5];
    stack[-2] = v_3231;
    v_3231 = stack[-2];
    fn = elt(env, 6); // lastpair
    v_3231 = (*qfn1(fn))(fn, v_3231);
    env = stack[-5];
    stack[-1] = v_3231;
    v_3231 = stack[-4];
    v_3231 = qcdr(v_3231);
    stack[-4] = v_3231;
    v_3231 = stack[-1];
    if (!consp(v_3231)) goto v_3182;
    else goto v_3183;
v_3182:
    goto v_3144;
v_3183:
v_3145:
    v_3231 = stack[-4];
    if (v_3231 == nil) goto v_3187;
    else goto v_3188;
v_3187:
    v_3231 = stack[-2];
    goto v_3143;
v_3188:
    goto v_3196;
v_3192:
    stack[0] = stack[-1];
    goto v_3193;
v_3194:
    v_3231 = stack[-4];
    v_3231 = qcar(v_3231);
    goto v_3208;
v_3202:
    v_3232 = v_3231;
    v_3233 = qcar(v_3232);
    goto v_3203;
v_3204:
    v_3232 = qcdr(v_3231);
    goto v_3205;
v_3206:
    v_3231 = stack[-3];
    goto v_3207;
v_3208:
    goto v_3202;
v_3203:
    goto v_3204;
v_3205:
    goto v_3206;
v_3207:
    fn = elt(env, 4); // mcharg1
    v_3231 = (*qfnn(fn))(fn, 3, v_3233, v_3232, v_3231);
    env = stack[-5];
    goto v_3195;
v_3196:
    goto v_3192;
v_3193:
    goto v_3194;
v_3195:
    v_3231 = Lrplacd(nil, stack[0], v_3231);
    env = stack[-5];
    v_3231 = stack[-1];
    fn = elt(env, 6); // lastpair
    v_3231 = (*qfn1(fn))(fn, v_3231);
    env = stack[-5];
    stack[-1] = v_3231;
    v_3231 = stack[-4];
    v_3231 = qcdr(v_3231);
    stack[-4] = v_3231;
    goto v_3145;
v_3143:
    goto v_3096;
v_3126:
    goto v_3227;
v_3221:
    goto v_3222;
v_3223:
    v_3232 = stack[0];
    goto v_3224;
v_3225:
    v_3231 = stack[-3];
    goto v_3226;
v_3227:
    goto v_3221;
v_3222:
    goto v_3223;
v_3224:
    goto v_3225;
v_3226:
    {
        fn = elt(env, 4); // mcharg1
        return (*qfnn(fn))(fn, 3, v_3233, v_3232, v_3231);
    }
    v_3231 = nil;
v_3096:
    return onevalue(v_3231);
}



// Code for talp_tcfrp

static LispObject CC_talp_tcfrp(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3104, v_3105;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
// copy arguments values to proper place
    v_3105 = v_3091;
// end of prologue
    v_3104 = v_3105;
    if (!consp(v_3104)) goto v_3095;
    else goto v_3096;
v_3095:
    v_3104 = lisp_true;
    goto v_3094;
v_3096:
    v_3104 = v_3105;
    fn = elt(env, 1); // talp_invp
    v_3104 = (*qfn1(fn))(fn, v_3104);
    goto v_3094;
    v_3104 = nil;
v_3094:
    v_3104 = (v_3104 == nil ? lisp_true : nil);
    return onevalue(v_3104);
}



// Code for ibalp_commonlenisone

static LispObject CC_ibalp_commonlenisone(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3117;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3092;
    stack[-1] = v_3091;
// end of prologue
    v_3117 = stack[-1];
    if (v_3117 == nil) goto v_3099;
    else goto v_3100;
v_3099:
    v_3117 = stack[0];
    fn = elt(env, 1); // ibalp_lenisone
    v_3117 = (*qfn1(fn))(fn, v_3117);
    env = stack[-2];
    goto v_3098;
v_3100:
    v_3117 = nil;
    goto v_3098;
    v_3117 = nil;
v_3098:
    if (v_3117 == nil) goto v_3096;
    else goto v_3095;
v_3096:
    v_3117 = stack[0];
    if (v_3117 == nil) goto v_3109;
    else goto v_3110;
v_3109:
    v_3117 = stack[-1];
    {
        fn = elt(env, 1); // ibalp_lenisone
        return (*qfn1(fn))(fn, v_3117);
    }
v_3110:
    v_3117 = nil;
    goto v_3108;
    v_3117 = nil;
v_3108:
v_3095:
    return onevalue(v_3117);
}



// Code for omobjs

static LispObject CC_omobjs(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3134, v_3135;
    LispObject fn;
    argcheck(nargs, 0, "omobjs");
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
    goto v_3104;
v_3100:
    v_3135 = qvalue(elt(env, 1)); // char
    goto v_3101;
v_3102:
    v_3134 = elt(env, 2); // (!/ o m a)
    goto v_3103;
v_3104:
    goto v_3100;
v_3101:
    goto v_3102;
v_3103:
    if (equal(v_3135, v_3134)) goto v_3099;
    fn = elt(env, 3); // omobj
    v_3134 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_3134;
    fn = elt(env, 4); // lex
    v_3134 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_3134 = CC_omobjs(elt(env, 0), 0);
    v_3135 = stack[0];
    if (v_3135 == nil) goto v_3112;
    else goto v_3113;
v_3112:
    goto v_3120;
v_3116:
    v_3135 = stack[0];
    goto v_3117;
v_3118:
    goto v_3119;
v_3120:
    goto v_3116;
v_3117:
    goto v_3118;
v_3119:
        return Lappend(nil, v_3135, v_3134);
v_3113:
    goto v_3130;
v_3126:
    v_3135 = stack[0];
    goto v_3127;
v_3128:
    goto v_3129;
v_3130:
    goto v_3126;
v_3127:
    goto v_3128;
v_3129:
    return cons(v_3135, v_3134);
    goto v_3097;
v_3099:
v_3097:
    v_3134 = nil;
    return onevalue(v_3134);
}



// Code for letmtr3

static LispObject CC_letmtr3(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3479, v_3480, v_3481, v_3482;
    LispObject fn;
    LispObject v_3094, v_3093, v_3092, v_3091;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "letmtr3");
    va_start(aa, nargs);
    v_3091 = va_arg(aa, LispObject);
    v_3092 = va_arg(aa, LispObject);
    v_3093 = va_arg(aa, LispObject);
    v_3094 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_3094,v_3093,v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_3091,v_3092,v_3093,v_3094);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-2] = v_3094;
    stack[-3] = v_3093;
    stack[-4] = v_3092;
    stack[-5] = v_3091;
// end of prologue
    stack[-6] = nil;
    v_3479 = stack[-5];
    v_3479 = qcdr(v_3479);
    v_3479 = qcdr(v_3479);
    if (v_3479 == nil) goto v_3109;
    else goto v_3110;
v_3109:
    goto v_3123;
v_3119:
    v_3480 = stack[-3];
    goto v_3120;
v_3121:
    v_3479 = elt(env, 1); // sparsemat
    goto v_3122;
v_3123:
    goto v_3119;
v_3120:
    goto v_3121;
v_3122:
    if (!consp(v_3480)) goto v_3116;
    v_3480 = qcar(v_3480);
    if (v_3480 == v_3479) goto v_3117;
v_3116:
    goto v_3133;
v_3127:
    stack[-1] = elt(env, 2); // matrix
    goto v_3128;
v_3129:
    stack[0] = (LispObject)160+TAG_FIXNUM; // 10
    goto v_3130;
v_3131:
    goto v_3143;
v_3137:
    v_3481 = elt(env, 3); // "Matrix"
    goto v_3138;
v_3139:
    v_3479 = stack[-5];
    v_3480 = qcar(v_3479);
    goto v_3140;
v_3141:
    v_3479 = elt(env, 4); // "not set"
    goto v_3142;
v_3143:
    goto v_3137;
v_3138:
    goto v_3139;
v_3140:
    goto v_3141;
v_3142:
    v_3479 = list3(v_3481, v_3480, v_3479);
    env = stack[-7];
    goto v_3132;
v_3133:
    goto v_3127;
v_3128:
    goto v_3129;
v_3130:
    goto v_3131;
v_3132:
    fn = elt(env, 7); // rerror
    v_3479 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_3479);
    goto v_3115;
v_3117:
    v_3479 = stack[-5];
    v_3479 = qcdr(v_3479);
    fn = elt(env, 8); // revlis
    v_3479 = (*qfn1(fn))(fn, v_3479);
    env = stack[-7];
    stack[-6] = v_3479;
    fn = elt(env, 9); // numlis
    v_3479 = (*qfn1(fn))(fn, v_3479);
    env = stack[-7];
    if (v_3479 == nil) goto v_3152;
    else goto v_3153;
v_3152:
    v_3479 = lisp_true;
    goto v_3151;
v_3153:
    goto v_3166;
v_3162:
    v_3479 = stack[-6];
    v_3480 = Llength(nil, v_3479);
    env = stack[-7];
    goto v_3163;
v_3164:
    v_3479 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3165;
v_3166:
    goto v_3162;
v_3163:
    goto v_3164;
v_3165:
    v_3479 = Lneq(nil, v_3480, v_3479);
    env = stack[-7];
    goto v_3151;
    v_3479 = nil;
v_3151:
    if (v_3479 == nil) goto v_3149;
    goto v_3175;
v_3171:
    v_3480 = stack[-5];
    goto v_3172;
v_3173:
    v_3479 = elt(env, 5); // hold
    goto v_3174;
v_3175:
    goto v_3171;
v_3172:
    goto v_3173;
v_3174:
    {
        fn = elt(env, 10); // errpri2
        return (*qfn2(fn))(fn, v_3480, v_3479);
    }
v_3149:
v_3115:
    goto v_3184;
v_3178:
    v_3479 = stack[-3];
    v_3479 = qcdr(v_3479);
    v_3481 = qcar(v_3479);
    goto v_3179;
v_3180:
    v_3479 = stack[-5];
    v_3479 = qcdr(v_3479);
    v_3480 = qcar(v_3479);
    goto v_3181;
v_3182:
    v_3479 = stack[-4];
    goto v_3183;
v_3184:
    goto v_3178;
v_3179:
    goto v_3180;
v_3181:
    goto v_3182;
v_3183:
    *(LispObject *)((char *)v_3481 + (CELL-TAG_VECTOR) + (((intptr_t)v_3480-TAG_FIXNUM)/(16/CELL))) = v_3479;
    goto v_3108;
v_3110:
    goto v_3204;
v_3200:
    v_3480 = stack[-3];
    goto v_3201;
v_3202:
    v_3479 = elt(env, 1); // sparsemat
    goto v_3203;
v_3204:
    goto v_3200;
v_3201:
    goto v_3202;
v_3203:
    if (!consp(v_3480)) goto v_3197;
    v_3480 = qcar(v_3480);
    if (v_3480 == v_3479) goto v_3198;
v_3197:
    goto v_3214;
v_3208:
    stack[-1] = elt(env, 2); // matrix
    goto v_3209;
v_3210:
    stack[0] = (LispObject)160+TAG_FIXNUM; // 10
    goto v_3211;
v_3212:
    goto v_3224;
v_3218:
    v_3481 = elt(env, 3); // "Matrix"
    goto v_3219;
v_3220:
    v_3479 = stack[-5];
    v_3480 = qcar(v_3479);
    goto v_3221;
v_3222:
    v_3479 = elt(env, 4); // "not set"
    goto v_3223;
v_3224:
    goto v_3218;
v_3219:
    goto v_3220;
v_3221:
    goto v_3222;
v_3223:
    v_3479 = list3(v_3481, v_3480, v_3479);
    env = stack[-7];
    goto v_3213;
v_3214:
    goto v_3208;
v_3209:
    goto v_3210;
v_3211:
    goto v_3212;
v_3213:
    fn = elt(env, 7); // rerror
    v_3479 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_3479);
    env = stack[-7];
    goto v_3196;
v_3198:
    v_3479 = stack[-5];
    v_3479 = qcdr(v_3479);
    fn = elt(env, 8); // revlis
    v_3479 = (*qfn1(fn))(fn, v_3479);
    env = stack[-7];
    stack[-6] = v_3479;
    fn = elt(env, 9); // numlis
    v_3479 = (*qfn1(fn))(fn, v_3479);
    env = stack[-7];
    if (v_3479 == nil) goto v_3233;
    else goto v_3234;
v_3233:
    v_3479 = lisp_true;
    goto v_3232;
v_3234:
    goto v_3247;
v_3243:
    v_3479 = stack[-6];
    v_3480 = Llength(nil, v_3479);
    env = stack[-7];
    goto v_3244;
v_3245:
    v_3479 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_3246;
v_3247:
    goto v_3243;
v_3244:
    goto v_3245;
v_3246:
    v_3479 = Lneq(nil, v_3480, v_3479);
    env = stack[-7];
    goto v_3232;
    v_3479 = nil;
v_3232:
    if (v_3479 == nil) goto v_3230;
    goto v_3256;
v_3252:
    v_3480 = stack[-5];
    goto v_3253;
v_3254:
    v_3479 = elt(env, 5); // hold
    goto v_3255;
v_3256:
    goto v_3252;
v_3253:
    goto v_3254;
v_3255:
    {
        fn = elt(env, 10); // errpri2
        return (*qfn2(fn))(fn, v_3480, v_3479);
    }
v_3230:
v_3196:
    goto v_3263;
v_3259:
    v_3479 = stack[-3];
    v_3479 = qcdr(v_3479);
    v_3480 = qcar(v_3479);
    goto v_3260;
v_3261:
    v_3479 = stack[-6];
    v_3479 = qcar(v_3479);
    goto v_3262;
v_3263:
    goto v_3259;
v_3260:
    goto v_3261;
v_3262:
    v_3479 = *(LispObject *)((char *)v_3480 + (CELL-TAG_VECTOR) + (((intptr_t)v_3479-TAG_FIXNUM)/(16/CELL)));
    v_3482 = v_3479;
    v_3479 = v_3482;
    if (v_3479 == nil) goto v_3272;
    else goto v_3273;
v_3272:
    goto v_3287;
v_3283:
    v_3480 = stack[-4];
    goto v_3284;
v_3285:
    v_3479 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3286;
v_3287:
    goto v_3283;
v_3284:
    goto v_3285;
v_3286:
    if (v_3480 == v_3479) goto v_3281;
    else goto v_3282;
v_3281:
    goto v_3294;
v_3290:
    v_3480 = stack[-2];
    goto v_3291;
v_3292:
    v_3479 = elt(env, 6); // cx
    goto v_3293;
v_3294:
    goto v_3290;
v_3291:
    goto v_3292;
v_3293:
    v_3479 = (v_3480 == v_3479 ? lisp_true : nil);
    v_3479 = (v_3479 == nil ? lisp_true : nil);
    goto v_3280;
v_3282:
    v_3479 = nil;
    goto v_3280;
    v_3479 = nil;
v_3280:
    if (v_3479 == nil) goto v_3278;
    goto v_3276;
v_3278:
    goto v_3311;
v_3305:
    v_3479 = stack[-3];
    v_3479 = qcdr(v_3479);
    stack[-2] = qcar(v_3479);
    goto v_3306;
v_3307:
    v_3479 = stack[-6];
    stack[-1] = qcar(v_3479);
    goto v_3308;
v_3309:
    goto v_3322;
v_3318:
    v_3479 = nil;
    stack[0] = ncons(v_3479);
    env = stack[-7];
    goto v_3319;
v_3320:
    goto v_3330;
v_3326:
    v_3479 = stack[-6];
    v_3479 = qcdr(v_3479);
    v_3480 = qcar(v_3479);
    goto v_3327;
v_3328:
    v_3479 = stack[-4];
    goto v_3329;
v_3330:
    goto v_3326;
v_3327:
    goto v_3328;
v_3329:
    v_3479 = cons(v_3480, v_3479);
    env = stack[-7];
    goto v_3321;
v_3322:
    goto v_3318;
v_3319:
    goto v_3320;
v_3321:
    v_3479 = list2(stack[0], v_3479);
    goto v_3310;
v_3311:
    goto v_3305;
v_3306:
    goto v_3307;
v_3308:
    goto v_3309;
v_3310:
    *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-1]-TAG_FIXNUM)/(16/CELL))) = v_3479;
    goto v_3276;
v_3276:
    goto v_3271;
v_3273:
    goto v_3342;
v_3338:
    v_3479 = stack[-6];
    v_3479 = qcdr(v_3479);
    v_3480 = qcar(v_3479);
    goto v_3339;
v_3340:
    v_3479 = v_3482;
    goto v_3341;
v_3342:
    goto v_3338;
v_3339:
    goto v_3340;
v_3341:
    v_3479 = Latsoc(nil, v_3480, v_3479);
    v_3481 = v_3479;
    v_3479 = v_3481;
    if (v_3479 == nil) goto v_3350;
    else goto v_3351;
v_3350:
    goto v_3365;
v_3361:
    v_3480 = stack[-4];
    goto v_3362;
v_3363:
    v_3479 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3364;
v_3365:
    goto v_3361;
v_3362:
    goto v_3363;
v_3364:
    if (v_3480 == v_3479) goto v_3359;
    else goto v_3360;
v_3359:
    goto v_3372;
v_3368:
    v_3480 = stack[-2];
    goto v_3369;
v_3370:
    v_3479 = elt(env, 6); // cx
    goto v_3371;
v_3372:
    goto v_3368;
v_3369:
    goto v_3370;
v_3371:
    v_3479 = (v_3480 == v_3479 ? lisp_true : nil);
    v_3479 = (v_3479 == nil ? lisp_true : nil);
    goto v_3358;
v_3360:
    v_3479 = nil;
    goto v_3358;
    v_3479 = nil;
v_3358:
    if (v_3479 == nil) goto v_3356;
    goto v_3354;
v_3356:
    goto v_3390;
v_3384:
    v_3479 = stack[-6];
    v_3479 = qcdr(v_3479);
    v_3480 = qcar(v_3479);
    goto v_3385;
v_3386:
    v_3481 = v_3482;
    goto v_3387;
v_3388:
    v_3479 = stack[-4];
    goto v_3389;
v_3390:
    goto v_3384;
v_3385:
    goto v_3386;
v_3387:
    goto v_3388;
v_3389:
    fn = elt(env, 11); // sortcolelem
    v_3479 = (*qfnn(fn))(fn, 3, v_3480, v_3481, v_3479);
    goto v_3354;
v_3354:
    goto v_3349;
v_3351:
    goto v_3411;
v_3407:
    v_3480 = stack[-4];
    goto v_3408;
v_3409:
    v_3479 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_3410;
v_3411:
    goto v_3407;
v_3408:
    goto v_3409;
v_3410:
    if (v_3480 == v_3479) goto v_3405;
    else goto v_3406;
v_3405:
    goto v_3418;
v_3414:
    v_3480 = stack[-2];
    goto v_3415;
v_3416:
    v_3479 = elt(env, 6); // cx
    goto v_3417;
v_3418:
    goto v_3414;
v_3415:
    goto v_3416;
v_3417:
    v_3479 = (v_3480 == v_3479 ? lisp_true : nil);
    v_3479 = (v_3479 == nil ? lisp_true : nil);
    goto v_3404;
v_3406:
    v_3479 = nil;
    goto v_3404;
    v_3479 = nil;
v_3404:
    if (v_3479 == nil) goto v_3402;
    v_3479 = v_3482;
    v_3479 = qcdr(v_3479);
    v_3479 = qcdr(v_3479);
    if (v_3479 == nil) goto v_3428;
    else goto v_3429;
v_3428:
    goto v_3439;
v_3433:
    v_3479 = stack[-3];
    v_3479 = qcdr(v_3479);
    v_3481 = qcar(v_3479);
    goto v_3434;
v_3435:
    v_3479 = stack[-6];
    v_3480 = qcar(v_3479);
    goto v_3436;
v_3437:
    v_3479 = nil;
    goto v_3438;
v_3439:
    goto v_3433;
v_3434:
    goto v_3435;
v_3436:
    goto v_3437;
v_3438:
    *(LispObject *)((char *)v_3481 + (CELL-TAG_VECTOR) + (((intptr_t)v_3480-TAG_FIXNUM)/(16/CELL))) = v_3479;
    goto v_3427;
v_3429:
    goto v_3454;
v_3450:
    stack[0] = v_3482;
    goto v_3451;
v_3452:
    goto v_3461;
v_3457:
    v_3479 = v_3481;
    goto v_3458;
v_3459:
    v_3480 = v_3482;
    goto v_3460;
v_3461:
    goto v_3457;
v_3458:
    goto v_3459;
v_3460:
    v_3479 = Ldelete(nil, v_3479, v_3480);
    env = stack[-7];
    v_3479 = qcdr(v_3479);
    goto v_3453;
v_3454:
    goto v_3450;
v_3451:
    goto v_3452;
v_3453:
    v_3479 = Lrplacd(nil, stack[0], v_3479);
    goto v_3427;
v_3427:
    goto v_3400;
v_3402:
    goto v_3473;
v_3469:
    v_3480 = v_3481;
    goto v_3470;
v_3471:
    v_3479 = stack[-4];
    goto v_3472;
v_3473:
    goto v_3469;
v_3470:
    goto v_3471;
v_3472:
    v_3479 = Lrplacd(nil, v_3480, v_3479);
    goto v_3400;
v_3400:
    goto v_3349;
v_3349:
    goto v_3271;
v_3271:
    goto v_3108;
v_3108:
    v_3479 = nil;
    return onevalue(v_3479);
}



// Code for bound

static LispObject CC_bound(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3112, v_3113;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_3112 = v_3091;
// end of prologue
    fn = elt(env, 2); // binding
    v_3112 = (*qfn1(fn))(fn, v_3112);
    env = stack[0];
    v_3113 = v_3112;
    v_3112 = v_3113;
    if (v_3112 == nil) goto v_3098;
    else goto v_3099;
v_3098:
    v_3112 = nil;
    goto v_3097;
v_3099:
    goto v_3109;
v_3105:
    v_3112 = v_3113;
    goto v_3106;
v_3107:
    v_3113 = elt(env, 1); // unbound
    goto v_3108;
v_3109:
    goto v_3105;
v_3106:
    goto v_3107;
v_3108:
        return Lneq(nil, v_3112, v_3113);
    v_3112 = nil;
v_3097:
    return onevalue(v_3112);
}



// Code for bcsum

static LispObject CC_bcsum(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3133, v_3134, v_3135;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3092;
    stack[-1] = v_3091;
// end of prologue
    v_3133 = qvalue(elt(env, 1)); // !*grmod!*
    if (v_3133 == nil) goto v_3097;
    goto v_3105;
v_3101:
    v_3134 = stack[-1];
    goto v_3102;
v_3103:
    v_3133 = stack[0];
    goto v_3104;
v_3105:
    goto v_3101;
v_3102:
    goto v_3103;
v_3104:
    v_3133 = plus2(v_3134, v_3133);
    env = stack[-2];
    {
        fn = elt(env, 3); // bcfi
        return (*qfn1(fn))(fn, v_3133);
    }
v_3097:
    goto v_3120;
v_3114:
    v_3135 = stack[-1];
    goto v_3115;
v_3116:
    v_3134 = stack[0];
    goto v_3117;
v_3118:
    v_3133 = elt(env, 2); // plus2
    goto v_3119;
v_3120:
    goto v_3114;
v_3115:
    goto v_3116;
v_3117:
    goto v_3118;
v_3119:
    fn = elt(env, 4); // bcint2op
    v_3133 = (*qfnn(fn))(fn, 3, v_3135, v_3134, v_3133);
    env = stack[-2];
    if (v_3133 == nil) goto v_3112;
    else goto v_3111;
v_3112:
    goto v_3130;
v_3126:
    v_3134 = stack[-1];
    goto v_3127;
v_3128:
    v_3133 = stack[0];
    goto v_3129;
v_3130:
    goto v_3126;
v_3127:
    goto v_3128;
v_3129:
    fn = elt(env, 5); // addsq
    v_3133 = (*qfn2(fn))(fn, v_3134, v_3133);
    env = stack[-2];
    {
        fn = elt(env, 6); // bccheckz
        return (*qfn1(fn))(fn, v_3133);
    }
v_3111:
    goto v_3095;
    v_3133 = nil;
v_3095:
    return onevalue(v_3133);
}



// Code for vecopp

static LispObject CC_vecopp(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3142, v_3143, v_3144;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
// copy arguments values to proper place
    v_3144 = v_3091;
// end of prologue
    v_3142 = v_3144;
    if (symbolp(v_3142)) goto v_3099;
    v_3142 = nil;
    goto v_3097;
v_3099:
    goto v_3108;
v_3104:
    v_3142 = v_3144;
    if (!symbolp(v_3142)) v_3143 = nil;
    else { v_3143 = qfastgets(v_3142);
           if (v_3143 != nil) { v_3143 = elt(v_3143, 18); // phystype
#ifdef RECORD_GET
             if (v_3143 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v_3143 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v_3143 == SPID_NOPROP) v_3143 = nil; }}
#endif
    goto v_3105;
v_3106:
    v_3142 = elt(env, 1); // vector
    goto v_3107;
v_3108:
    goto v_3104;
v_3105:
    goto v_3106;
v_3107:
    v_3142 = (v_3143 == v_3142 ? lisp_true : nil);
    goto v_3097;
    v_3142 = nil;
v_3097:
    if (v_3142 == nil) goto v_3095;
    else goto v_3094;
v_3095:
    v_3142 = v_3144;
    if (!consp(v_3142)) goto v_3116;
    goto v_3126;
v_3122:
    v_3142 = v_3144;
    v_3142 = qcar(v_3142);
    if (!symbolp(v_3142)) v_3143 = nil;
    else { v_3143 = qfastgets(v_3142);
           if (v_3143 != nil) { v_3143 = elt(v_3143, 18); // phystype
#ifdef RECORD_GET
             if (v_3143 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v_3143 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v_3143 == SPID_NOPROP) v_3143 = nil; }}
#endif
    goto v_3123;
v_3124:
    v_3142 = elt(env, 1); // vector
    goto v_3125;
v_3126:
    goto v_3122;
v_3123:
    goto v_3124;
v_3125:
    if (v_3143 == v_3142) goto v_3120;
    else goto v_3121;
v_3120:
    v_3142 = v_3144;
    v_3142 = qcdr(v_3142);
    v_3142 = qcar(v_3142);
    fn = elt(env, 2); // isanindex
    v_3142 = (*qfn1(fn))(fn, v_3142);
    v_3142 = (v_3142 == nil ? lisp_true : nil);
    goto v_3119;
v_3121:
    v_3142 = nil;
    goto v_3119;
    v_3142 = nil;
v_3119:
    goto v_3114;
v_3116:
    v_3142 = nil;
    goto v_3114;
    v_3142 = nil;
v_3114:
v_3094:
    return onevalue(v_3142);
}



// Code for sroad

static LispObject CC_sroad(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_3145, v_3146, v_3147;
    LispObject fn;
    LispObject v_3093, v_3092, v_3091;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sroad");
    va_start(aa, nargs);
    v_3091 = va_arg(aa, LispObject);
    v_3092 = va_arg(aa, LispObject);
    v_3093 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_3093,v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_3091,v_3092,v_3093);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3093;
    stack[-1] = v_3092;
    stack[-2] = v_3091;
// end of prologue
    v_3147 = nil;
v_3098:
    v_3145 = stack[0];
    if (v_3145 == nil) goto v_3101;
    else goto v_3102;
v_3101:
    v_3145 = v_3147;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_3145);
    }
v_3102:
    goto v_3112;
v_3108:
    v_3146 = stack[-2];
    goto v_3109;
v_3110:
    v_3145 = stack[0];
    v_3145 = qcar(v_3145);
    goto v_3111;
v_3112:
    goto v_3108;
v_3109:
    goto v_3110;
v_3111:
    if (equal(v_3146, v_3145)) goto v_3106;
    else goto v_3107;
v_3106:
    goto v_3121;
v_3117:
    stack[-2] = v_3147;
    goto v_3118;
v_3119:
    goto v_3128;
v_3124:
    v_3146 = stack[-1];
    goto v_3125;
v_3126:
    v_3145 = stack[0];
    v_3145 = qcdr(v_3145);
    goto v_3127;
v_3128:
    goto v_3124;
v_3125:
    goto v_3126;
v_3127:
    v_3145 = Lappend(nil, v_3146, v_3145);
    env = stack[-3];
    goto v_3120;
v_3121:
    goto v_3117;
v_3118:
    goto v_3119;
v_3120:
    {
        LispObject v_3151 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_3151, v_3145);
    }
v_3107:
    goto v_3139;
v_3135:
    v_3145 = stack[0];
    v_3145 = qcar(v_3145);
    goto v_3136;
v_3137:
    v_3146 = v_3147;
    goto v_3138;
v_3139:
    goto v_3135;
v_3136:
    goto v_3137;
v_3138:
    v_3145 = cons(v_3145, v_3146);
    env = stack[-3];
    v_3147 = v_3145;
    v_3145 = stack[0];
    v_3145 = qcdr(v_3145);
    stack[0] = v_3145;
    goto v_3098;
    v_3145 = nil;
    return onevalue(v_3145);
}



// Code for simpplus

static LispObject CC_simpplus(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3136, v_3137;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3091);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3091;
// end of prologue
    goto v_3105;
v_3101:
    v_3136 = stack[0];
    v_3137 = Llength(nil, v_3136);
    env = stack[-2];
    goto v_3102;
v_3103:
    v_3136 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_3104;
v_3105:
    goto v_3101;
v_3102:
    goto v_3103;
v_3104:
    if (v_3137 == v_3136) goto v_3099;
    else goto v_3100;
v_3099:
    v_3136 = stack[0];
    fn = elt(env, 1); // ckpreci!#
    v_3136 = (*qfn1(fn))(fn, v_3136);
    env = stack[-2];
    goto v_3098;
v_3100:
v_3098:
    goto v_3116;
v_3112:
    v_3137 = nil;
    goto v_3113;
v_3114:
    v_3136 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3115;
v_3116:
    goto v_3112;
v_3113:
    goto v_3114;
v_3115:
    v_3136 = cons(v_3137, v_3136);
    env = stack[-2];
    stack[-1] = v_3136;
v_3096:
    v_3136 = stack[0];
    if (v_3136 == nil) goto v_3121;
    else goto v_3122;
v_3121:
    v_3136 = stack[-1];
    goto v_3095;
v_3122:
    goto v_3130;
v_3126:
    v_3136 = stack[0];
    fn = elt(env, 2); // simpcar
    v_3137 = (*qfn1(fn))(fn, v_3136);
    env = stack[-2];
    goto v_3127;
v_3128:
    v_3136 = stack[-1];
    goto v_3129;
v_3130:
    goto v_3126;
v_3127:
    goto v_3128;
v_3129:
    fn = elt(env, 3); // addsq
    v_3136 = (*qfn2(fn))(fn, v_3137, v_3136);
    env = stack[-2];
    stack[-1] = v_3136;
    v_3136 = stack[0];
    v_3136 = qcdr(v_3136);
    stack[0] = v_3136;
    goto v_3096;
v_3095:
    return onevalue(v_3136);
}



// Code for red!-weight1

static LispObject CC_redKweight1(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3146, v_3147;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3092;
    stack[-1] = v_3091;
// end of prologue
    stack[-2] = nil;
v_3098:
    v_3146 = stack[-1];
    if (v_3146 == nil) goto v_3103;
    else goto v_3104;
v_3103:
    goto v_3099;
v_3104:
    goto v_3111;
v_3107:
    goto v_3117;
v_3113:
    v_3146 = stack[-1];
    v_3146 = qcar(v_3146);
    v_3147 = Labsval(nil, v_3146);
    env = stack[-3];
    goto v_3114;
v_3115:
    v_3146 = stack[0];
    v_3146 = qcar(v_3146);
    goto v_3116;
v_3117:
    goto v_3113;
v_3114:
    goto v_3115;
v_3116:
    v_3147 = times2(v_3147, v_3146);
    env = stack[-3];
    goto v_3108;
v_3109:
    v_3146 = stack[-2];
    goto v_3110;
v_3111:
    goto v_3107;
v_3108:
    goto v_3109;
v_3110:
    v_3146 = cons(v_3147, v_3146);
    env = stack[-3];
    stack[-2] = v_3146;
    v_3146 = stack[-1];
    v_3146 = qcdr(v_3146);
    stack[-1] = v_3146;
    v_3146 = stack[0];
    v_3146 = qcdr(v_3146);
    stack[0] = v_3146;
    goto v_3098;
v_3099:
    v_3146 = (LispObject)0+TAG_FIXNUM; // 0
    v_3147 = v_3146;
v_3100:
    v_3146 = stack[-2];
    if (v_3146 == nil) goto v_3131;
    else goto v_3132;
v_3131:
    v_3146 = v_3147;
    goto v_3097;
v_3132:
    goto v_3140;
v_3136:
    v_3146 = stack[-2];
    v_3146 = qcar(v_3146);
    goto v_3137;
v_3138:
    goto v_3139;
v_3140:
    goto v_3136;
v_3137:
    goto v_3138;
v_3139:
    v_3146 = plus2(v_3146, v_3147);
    env = stack[-3];
    v_3147 = v_3146;
    v_3146 = stack[-2];
    v_3146 = qcdr(v_3146);
    stack[-2] = v_3146;
    goto v_3100;
v_3097:
    return onevalue(v_3146);
}



// Code for dp_times_bc

static LispObject CC_dp_times_bc(LispObject env,
                         LispObject v_3091, LispObject v_3092)
{
    env = qenv(env);
    LispObject v_3166, v_3167;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3092,v_3091);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_3091,v_3092);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_3166 = v_3092;
    stack[-4] = v_3091;
// end of prologue
    stack[-5] = v_3166;
    v_3166 = stack[-5];
    if (v_3166 == nil) goto v_3103;
    else goto v_3104;
v_3103:
    v_3166 = nil;
    goto v_3098;
v_3104:
    v_3166 = stack[-5];
    v_3166 = qcar(v_3166);
    goto v_3116;
v_3112:
    v_3167 = v_3166;
    stack[0] = qcar(v_3167);
    goto v_3113;
v_3114:
    goto v_3124;
v_3120:
    v_3167 = stack[-4];
    goto v_3121;
v_3122:
    v_3166 = qcdr(v_3166);
    goto v_3123;
v_3124:
    goto v_3120;
v_3121:
    goto v_3122;
v_3123:
    fn = elt(env, 1); // cali_bc_prod
    v_3166 = (*qfn2(fn))(fn, v_3167, v_3166);
    env = stack[-6];
    goto v_3115;
v_3116:
    goto v_3112;
v_3113:
    goto v_3114;
v_3115:
    v_3166 = cons(stack[0], v_3166);
    env = stack[-6];
    v_3166 = ncons(v_3166);
    env = stack[-6];
    stack[-2] = v_3166;
    stack[-3] = v_3166;
v_3099:
    v_3166 = stack[-5];
    v_3166 = qcdr(v_3166);
    stack[-5] = v_3166;
    v_3166 = stack[-5];
    if (v_3166 == nil) goto v_3132;
    else goto v_3133;
v_3132:
    v_3166 = stack[-3];
    goto v_3098;
v_3133:
    goto v_3141;
v_3137:
    stack[-1] = stack[-2];
    goto v_3138;
v_3139:
    v_3166 = stack[-5];
    v_3166 = qcar(v_3166);
    goto v_3152;
v_3148:
    v_3167 = v_3166;
    stack[0] = qcar(v_3167);
    goto v_3149;
v_3150:
    goto v_3160;
v_3156:
    v_3167 = stack[-4];
    goto v_3157;
v_3158:
    v_3166 = qcdr(v_3166);
    goto v_3159;
v_3160:
    goto v_3156;
v_3157:
    goto v_3158;
v_3159:
    fn = elt(env, 1); // cali_bc_prod
    v_3166 = (*qfn2(fn))(fn, v_3167, v_3166);
    env = stack[-6];
    goto v_3151;
v_3152:
    goto v_3148;
v_3149:
    goto v_3150;
v_3151:
    v_3166 = cons(stack[0], v_3166);
    env = stack[-6];
    v_3166 = ncons(v_3166);
    env = stack[-6];
    goto v_3140;
v_3141:
    goto v_3137;
v_3138:
    goto v_3139;
v_3140:
    v_3166 = Lrplacd(nil, stack[-1], v_3166);
    env = stack[-6];
    v_3166 = stack[-2];
    v_3166 = qcdr(v_3166);
    stack[-2] = v_3166;
    goto v_3099;
v_3098:
    return onevalue(v_3166);
}



// Code for dv_skelhead

static LispObject CC_dv_skelhead(LispObject env,
                         LispObject v_3091)
{
    env = qenv(env);
    LispObject v_3096;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_3096 = v_3091;
// end of prologue
    v_3096 = qcar(v_3096);
    {
        fn = elt(env, 1); // dv_cambhead
        return (*qfn1(fn))(fn, v_3096);
    }
}



setup_type const u07_setup[] =
{
    {"minus-mod-p",             CC_minusKmodKp, TOO_MANY_1,    WRONG_NO_1},
    {"raddf",                   TOO_FEW_2,      CC_raddf,      WRONG_NO_2},
    {"talp_varlt1",             TOO_FEW_2,      CC_talp_varlt1,WRONG_NO_2},
    {"mri_simplfloor",          CC_mri_simplfloor,TOO_MANY_1,  WRONG_NO_1},
    {"quotfd",                  TOO_FEW_2,      CC_quotfd,     WRONG_NO_2},
    {"downwght",                TOO_FEW_2,      CC_downwght,   WRONG_NO_2},
    {"freexp",                  CC_freexp,      TOO_MANY_1,    WRONG_NO_1},
    {"prepd",                   CC_prepd,       TOO_MANY_1,    WRONG_NO_1},
    {"diplength",               CC_diplength,   TOO_MANY_1,    WRONG_NO_1},
    {"quotematrix",             CC_quotematrix, TOO_MANY_1,    WRONG_NO_1},
    {"deg*farg",                CC_degHfarg,    TOO_MANY_1,    WRONG_NO_1},
    {"round:mt",                TOO_FEW_2,      CC_roundTmt,   WRONG_NO_2},
    {"gizerop:",                CC_gizeropT,    TOO_MANY_1,    WRONG_NO_1},
    {"red-char-downcase",       CC_redKcharKdowncase,TOO_MANY_1,WRONG_NO_1},
    {"repeatsp",                CC_repeatsp,    TOO_MANY_1,    WRONG_NO_1},
    {"macrochk",                TOO_FEW_2,      CC_macrochk,   WRONG_NO_2},
    {"red_divtestbe",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_red_divtestbe},
    {"resimp1",                 CC_resimp1,     TOO_MANY_1,    WRONG_NO_1},
    {"pappl_pv",                TOO_FEW_2,      CC_pappl_pv,   WRONG_NO_2},
    {"*modular2f",              CC_Hmodular2f,  TOO_MANY_1,    WRONG_NO_1},
    {"exptmod:",                TOO_FEW_2,      CC_exptmodT,   WRONG_NO_2},
    {"lalr_add_goto",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lalr_add_goto},
    {"procstat",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_procstat},
    {"sfto_gcdf",               TOO_FEW_2,      CC_sfto_gcdf,  WRONG_NO_2},
    {"gcdf1",                   TOO_FEW_2,      CC_gcdf1,      WRONG_NO_2},
    {"talp_smupdknowl",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_smupdknowl},
    {"qqe_id-nyt-branchb",      CC_qqe_idKnytKbranchb,TOO_MANY_1,WRONG_NO_1},
    {"kernord",                 TOO_FEW_2,      CC_kernord,    WRONG_NO_2},
    {"ibalp_calcmom",           CC_ibalp_calcmom,TOO_MANY_1,   WRONG_NO_1},
    {"multi_elem",              CC_multi_elem,  TOO_MANY_1,    WRONG_NO_1},
    {"simp*",                   CC_simpH,       TOO_MANY_1,    WRONG_NO_1},
    {"termordp",                TOO_FEW_2,      CC_termordp,   WRONG_NO_2},
    {":plus",                   TOO_FEW_2,      CC_Tplus,      WRONG_NO_2},
    {"optype",                  CC_optype,      TOO_MANY_1,    WRONG_NO_1},
    {"setcloc*",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setclocH},
    {"getrtype2",               CC_getrtype2,   TOO_MANY_1,    WRONG_NO_1},
    {"groeb=testa",             TOO_FEW_2,      CC_groebMtesta,WRONG_NO_2},
    {"gperm2",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gperm2},
    {"*i2ar",                   CC_Hi2ar,       TOO_MANY_1,    WRONG_NO_1},
    {"general-modular-minus",   CC_generalKmodularKminus,TOO_MANY_1,WRONG_NO_1},
    {"convprec*",               CC_convprecH,   TOO_MANY_1,    WRONG_NO_1},
    {"lalr_remove_duplicates",  CC_lalr_remove_duplicates,TOO_MANY_1,WRONG_NO_1},
    {"convertmode",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_convertmode},
    {"sfto_davp",               TOO_FEW_2,      CC_sfto_davp,  WRONG_NO_2},
    {"cl_atfp",                 CC_cl_atfp,     TOO_MANY_1,    WRONG_NO_1},
    {"powers2",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_powers2},
    {"rationalizei",            CC_rationalizei,TOO_MANY_1,    WRONG_NO_1},
    {"mintype",                 CC_mintype,     TOO_MANY_1,    WRONG_NO_1},
    {"nextarg",                 CC_nextarg,     TOO_MANY_1,    WRONG_NO_1},
    {"layout-formula",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_layoutKformula},
    {"abs:",                    CC_absT,        TOO_MANY_1,    WRONG_NO_1},
    {"list2widestring",         CC_list2widestring,TOO_MANY_1, WRONG_NO_1},
    {"mv-pow-mv-term-+",        TOO_FEW_2,      CC_mvKpowKmvKtermKL,WRONG_NO_2},
    {"rnplus:",                 TOO_FEW_2,      CC_rnplusT,    WRONG_NO_2},
    {"lalr_analyze_lookaheads", WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lalr_analyze_lookaheads},
    {"powers1",                 CC_powers1,     TOO_MANY_1,    WRONG_NO_1},
    {"mcharg",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mcharg},
    {"talp_tcfrp",              CC_talp_tcfrp,  TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_commonlenisone",    TOO_FEW_2,      CC_ibalp_commonlenisone,WRONG_NO_2},
    {"omobjs",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_omobjs},
    {"letmtr3",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_letmtr3},
    {"bound",                   CC_bound,       TOO_MANY_1,    WRONG_NO_1},
    {"bcsum",                   TOO_FEW_2,      CC_bcsum,      WRONG_NO_2},
    {"vecopp",                  CC_vecopp,      TOO_MANY_1,    WRONG_NO_1},
    {"sroad",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_sroad},
    {"simpplus",                CC_simpplus,    TOO_MANY_1,    WRONG_NO_1},
    {"red-weight1",             TOO_FEW_2,      CC_redKweight1,WRONG_NO_2},
    {"dp_times_bc",             TOO_FEW_2,      CC_dp_times_bc,WRONG_NO_2},
    {"dv_skelhead",             CC_dv_skelhead, TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u07", (two_args *)"146120 1689511 7625096", 0}
};

// end of generated code
