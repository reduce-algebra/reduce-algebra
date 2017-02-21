
// $destdir/u28.c        Machine generated C code

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



// Code for procstat1

static LispObject CC_procstat1(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15740, v_15741, v_15742;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_15413;
// end of prologue
    stack[-4] = nil;
    stack[0] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    v_15740 = qvalue(elt(env, 1)); // erfg!*
    stack[-6] = v_15740;
    v_15740 = qvalue(elt(env, 2)); // fname!*
    if (v_15740 == nil) goto v_15432;
    v_15740 = lisp_true;
    stack[-6] = v_15740;
    goto v_15427;
v_15432:
    goto v_15441;
v_15437:
    v_15741 = qvalue(elt(env, 3)); // cursym!*
    goto v_15438;
v_15439:
    v_15740 = elt(env, 4); // procedure
    goto v_15440;
v_15441:
    goto v_15437;
v_15438:
    goto v_15439;
v_15440:
    if (v_15741 == v_15740) goto v_15435;
    else goto v_15436;
v_15435:
    v_15740 = elt(env, 5); // expr
    stack[-4] = v_15740;
    goto v_15430;
v_15436:
    v_15740 = qvalue(elt(env, 3)); // cursym!*
    stack[-4] = v_15740;
    fn = elt(env, 20); // scan
    v_15740 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    goto v_15430;
v_15430:
    goto v_15457;
v_15453:
    v_15741 = qvalue(elt(env, 3)); // cursym!*
    goto v_15454;
v_15455:
    v_15740 = elt(env, 4); // procedure
    goto v_15456;
v_15457:
    goto v_15453;
v_15454:
    goto v_15455;
v_15456:
    if (v_15741 == v_15740) goto v_15452;
    goto v_15427;
v_15452:
    v_15740 = qvalue(elt(env, 6)); // !*reduce4
    if (v_15740 == nil) goto v_15463;
    goto v_15423;
v_15463:
    goto v_15470;
v_15466:
    v_15741 = elt(env, 7); // (xread (quote proc))
    goto v_15467;
v_15468:
    v_15740 = nil;
    goto v_15469;
v_15470:
    goto v_15466;
v_15467:
    goto v_15468;
v_15469:
    fn = elt(env, 21); // errorset!*
    v_15740 = (*qfn2(fn))(fn, v_15741, v_15740);
    env = stack[-7];
    stack[0] = v_15740;
    v_15740 = stack[0];
    fn = elt(env, 22); // errorp
    v_15740 = (*qfn1(fn))(fn, v_15740);
    env = stack[-7];
    if (v_15740 == nil) goto v_15476;
    goto v_15425;
v_15476:
    v_15740 = stack[0];
    v_15740 = qcar(v_15740);
    stack[0] = v_15740;
    if (!consp(v_15740)) goto v_15479;
    else goto v_15480;
v_15479:
    v_15740 = stack[0];
    v_15740 = ncons(v_15740);
    env = stack[-7];
    stack[0] = v_15740;
    goto v_15474;
v_15480:
v_15474:
    v_15740 = stack[0];
    v_15740 = qcar(v_15740);
    qvalue(elt(env, 2)) = v_15740; // fname!*
    v_15740 = qvalue(elt(env, 2)); // fname!*
    if (symbolp(v_15740)) goto v_15489;
    else goto v_15490;
v_15489:
    v_15740 = qvalue(elt(env, 2)); // fname!*
    if (v_15740 == nil) goto v_15498;
    else goto v_15499;
v_15498:
    v_15740 = lisp_true;
    goto v_15497;
v_15499:
    goto v_15508;
v_15504:
    v_15741 = qvalue(elt(env, 2)); // fname!*
    goto v_15505;
v_15506:
    v_15740 = lisp_true;
    goto v_15507;
v_15508:
    goto v_15504;
v_15505:
    goto v_15506;
v_15507:
    v_15740 = (v_15741 == v_15740 ? lisp_true : nil);
    goto v_15497;
    v_15740 = nil;
v_15497:
    if (v_15740 == nil) goto v_15495;
    v_15740 = qvalue(elt(env, 2)); // fname!*
    fn = elt(env, 23); // rsverr
    v_15740 = (*qfn1(fn))(fn, v_15740);
    env = stack[-7];
    goto v_15425;
v_15495:
    v_15740 = qvalue(elt(env, 2)); // fname!*
    fn = elt(env, 24); // gettype
    v_15740 = (*qfn1(fn))(fn, v_15740);
    env = stack[-7];
    stack[-2] = v_15740;
    if (v_15740 == nil) goto v_15515;
    goto v_15524;
v_15520:
    v_15741 = stack[-2];
    goto v_15521;
v_15522:
    v_15740 = elt(env, 8); // (procedure operator)
    goto v_15523;
v_15524:
    goto v_15520;
v_15521:
    goto v_15522;
v_15523:
    v_15740 = Lmemq(nil, v_15741, v_15740);
    if (v_15740 == nil) goto v_15519;
    else goto v_15515;
v_15519:
    goto v_15533;
v_15529:
    goto v_15539;
v_15535:
    v_15741 = stack[-2];
    goto v_15536;
v_15537:
    v_15740 = qvalue(elt(env, 2)); // fname!*
    goto v_15538;
v_15539:
    goto v_15535;
v_15536:
    goto v_15537;
v_15538:
    v_15741 = list2(v_15741, v_15740);
    env = stack[-7];
    goto v_15530;
v_15531:
    v_15740 = elt(env, 9); // "procedure"
    goto v_15532;
v_15533:
    goto v_15529;
v_15530:
    goto v_15531;
v_15532:
    fn = elt(env, 25); // typerr
    v_15740 = (*qfn2(fn))(fn, v_15741, v_15740);
    env = stack[-7];
    goto v_15425;
v_15515:
    goto v_15488;
v_15490:
v_15488:
    v_15740 = stack[0];
    v_15740 = qcdr(v_15740);
    stack[-3] = v_15740;
    v_15740 = stack[-3];
    fn = elt(env, 26); // idlistp
    v_15740 = (*qfn1(fn))(fn, v_15740);
    env = stack[-7];
    if (v_15740 == nil) goto v_15549;
    goto v_15557;
v_15553:
    v_15740 = stack[0];
    v_15741 = qcar(v_15740);
    goto v_15554;
v_15555:
    v_15740 = stack[-3];
    goto v_15556;
v_15557:
    goto v_15553;
v_15554:
    goto v_15555;
v_15556:
    v_15740 = cons(v_15741, v_15740);
    env = stack[-7];
    stack[0] = v_15740;
    goto v_15547;
v_15549:
    goto v_15569;
v_15565:
    v_15741 = stack[-3];
    goto v_15566;
v_15567:
    v_15740 = elt(env, 10); // "invalid as parameter list"
    goto v_15568;
v_15569:
    goto v_15565;
v_15566:
    goto v_15567;
v_15568:
    v_15740 = list2(v_15741, v_15740);
    env = stack[-7];
    fn = elt(env, 27); // lprie
    v_15740 = (*qfn1(fn))(fn, v_15740);
    env = stack[-7];
    goto v_15547;
v_15547:
    goto v_15424;
v_15423:
    fn = elt(env, 20); // scan
    v_15740 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    qvalue(elt(env, 2)) = v_15740; // fname!*
    v_15740 = qvalue(elt(env, 2)); // fname!*
    if (symbolp(v_15740)) goto v_15576;
    goto v_15583;
v_15579:
    v_15741 = qvalue(elt(env, 2)); // fname!*
    goto v_15580;
v_15581:
    v_15740 = elt(env, 11); // "procedure name"
    goto v_15582;
v_15583:
    goto v_15579;
v_15580:
    goto v_15581;
v_15582:
    fn = elt(env, 25); // typerr
    v_15740 = (*qfn2(fn))(fn, v_15741, v_15740);
    env = stack[-7];
    goto v_15425;
v_15576:
    fn = elt(env, 20); // scan
    v_15740 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    goto v_15592;
v_15588:
    goto v_15598;
v_15594:
    stack[-1] = elt(env, 12); // read_param_list
    goto v_15595;
v_15596:
    v_15740 = stack[-5];
    v_15740 = Lmkquote(nil, v_15740);
    env = stack[-7];
    goto v_15597;
v_15598:
    goto v_15594;
v_15595:
    goto v_15596;
v_15597:
    v_15741 = list2(stack[-1], v_15740);
    env = stack[-7];
    goto v_15589;
v_15590:
    v_15740 = nil;
    goto v_15591;
v_15592:
    goto v_15588;
v_15589:
    goto v_15590;
v_15591:
    fn = elt(env, 21); // errorset!*
    v_15740 = (*qfn2(fn))(fn, v_15741, v_15740);
    env = stack[-7];
    stack[-3] = v_15740;
    v_15740 = stack[-3];
    fn = elt(env, 22); // errorp
    v_15740 = (*qfn1(fn))(fn, v_15740);
    env = stack[-7];
    if (v_15740 == nil) goto v_15606;
    goto v_15425;
v_15606:
    v_15740 = stack[-3];
    v_15740 = qcar(v_15740);
    stack[-3] = v_15740;
    goto v_15619;
v_15615:
    v_15741 = qvalue(elt(env, 3)); // cursym!*
    goto v_15616;
v_15617:
    v_15740 = elt(env, 13); // !*colon!*
    goto v_15618;
v_15619:
    goto v_15615;
v_15616:
    goto v_15617;
v_15618:
    if (v_15741 == v_15740) goto v_15613;
    else goto v_15614;
v_15613:
    fn = elt(env, 28); // read_type
    v_15740 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    stack[-5] = v_15740;
    goto v_15612;
v_15614:
v_15612:
v_15424:
    v_15740 = qvalue(elt(env, 2)); // fname!*
    if (symbolp(v_15740)) goto v_15627;
    else goto v_15626;
v_15627:
    v_15740 = qvalue(elt(env, 2)); // fname!*
    fn = elt(env, 29); // getd
    v_15740 = (*qfn1(fn))(fn, v_15740);
    env = stack[-7];
    if (v_15740 == nil) goto v_15629;
    else goto v_15626;
v_15629:
    goto v_15637;
v_15633:
    v_15740 = qvalue(elt(env, 2)); // fname!*
    v_15741 = ncons(v_15740);
    env = stack[-7];
    goto v_15634;
v_15635:
    v_15740 = elt(env, 14); // fnc
    goto v_15636;
v_15637:
    goto v_15633;
v_15634:
    goto v_15635;
v_15636:
    v_15740 = Lflag(nil, v_15741, v_15740);
    env = stack[-7];
    goto v_15624;
v_15626:
v_15624:
v_15425:
    goto v_15650;
v_15646:
    v_15741 = qvalue(elt(env, 15)); // eof!*
    goto v_15647;
v_15648:
    v_15740 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15649;
v_15650:
    goto v_15646;
v_15647:
    goto v_15648;
v_15649:
    v_15740 = (LispObject)greaterp2(v_15741, v_15740);
    v_15740 = v_15740 ? lisp_true : nil;
    env = stack[-7];
    if (v_15740 == nil) goto v_15644;
    v_15740 = elt(env, 16); // !*semicol!*
    qvalue(elt(env, 3)) = v_15740; // cursym!*
    v_15740 = nil;
    qvalue(elt(env, 17)) = v_15740; // curescaped!*
    goto v_15426;
v_15644:
    goto v_15660;
v_15656:
    v_15741 = elt(env, 18); // (xread t)
    goto v_15657;
v_15658:
    v_15740 = nil;
    goto v_15659;
v_15660:
    goto v_15656;
v_15657:
    goto v_15658;
v_15659:
    fn = elt(env, 21); // errorset!*
    v_15740 = (*qfn2(fn))(fn, v_15741, v_15740);
    env = stack[-7];
    stack[-2] = v_15740;
    v_15740 = stack[-2];
    fn = elt(env, 22); // errorp
    v_15740 = (*qfn1(fn))(fn, v_15740);
    env = stack[-7];
    if (v_15740 == nil) goto v_15665;
    else goto v_15666;
v_15665:
    v_15740 = stack[-2];
    v_15740 = qcar(v_15740);
    stack[-2] = v_15740;
    goto v_15664;
v_15666:
v_15664:
    v_15740 = qvalue(elt(env, 1)); // erfg!*
    if (v_15740 == nil) goto v_15673;
    else goto v_15674;
v_15673:
    goto v_15685;
v_15677:
    stack[-1] = elt(env, 4); // procedure
    goto v_15678;
v_15679:
    v_15740 = qvalue(elt(env, 6)); // !*reduce4
    if (v_15740 == nil) goto v_15689;
    else goto v_15690;
v_15689:
    v_15740 = stack[0];
    v_15740 = qcar(v_15740);
    stack[0] = v_15740;
    goto v_15688;
v_15690:
    v_15740 = qvalue(elt(env, 2)); // fname!*
    stack[0] = v_15740;
    goto v_15688;
    stack[0] = nil;
v_15688:
    goto v_15680;
v_15681:
    goto v_15682;
v_15683:
    goto v_15705;
v_15699:
    v_15742 = stack[-4];
    goto v_15700;
v_15701:
    v_15741 = stack[-3];
    goto v_15702;
v_15703:
    v_15740 = stack[-2];
    goto v_15704;
v_15705:
    goto v_15699;
v_15700:
    goto v_15701;
v_15702:
    goto v_15703;
v_15704:
    v_15740 = list3(v_15742, v_15741, v_15740);
    env = stack[-7];
    goto v_15684;
v_15685:
    goto v_15677;
v_15678:
    goto v_15679;
v_15680:
    goto v_15681;
v_15682:
    goto v_15683;
v_15684:
    v_15740 = list3star(stack[-1], stack[0], stack[-5], v_15740);
    env = stack[-7];
    stack[-2] = v_15740;
    goto v_15672;
v_15674:
v_15672:
v_15426:
    goto v_15714;
v_15710:
    v_15740 = qvalue(elt(env, 2)); // fname!*
    v_15741 = ncons(v_15740);
    env = stack[-7];
    goto v_15711;
v_15712:
    v_15740 = elt(env, 14); // fnc
    goto v_15713;
v_15714:
    goto v_15710;
v_15711:
    goto v_15712;
v_15713:
    v_15740 = Lremflag(nil, v_15741, v_15740);
    env = stack[-7];
    v_15740 = nil;
    qvalue(elt(env, 2)) = v_15740; // fname!*
    v_15740 = qvalue(elt(env, 1)); // erfg!*
    if (v_15740 == nil) goto v_15722;
    v_15740 = nil;
    stack[-2] = v_15740;
    v_15740 = stack[-6];
    if (v_15740 == nil) goto v_15727;
    else goto v_15728;
v_15727:
    Lerror0(nil, 0);
    goto v_15726;
v_15728:
v_15726:
    goto v_15720;
v_15722:
v_15720:
    v_15740 = stack[-2];
    goto v_15422;
v_15427:
    goto v_15737;
v_15733:
    v_15741 = elt(env, 19); // (symerr (quote procedure) t)
    goto v_15734;
v_15735:
    v_15740 = nil;
    goto v_15736;
v_15737:
    goto v_15733;
v_15734:
    goto v_15735;
v_15736:
    fn = elt(env, 21); // errorset!*
    v_15740 = (*qfn2(fn))(fn, v_15741, v_15740);
    env = stack[-7];
    goto v_15425;
v_15422:
    return onevalue(v_15740);
}



// Code for get_char_value

static LispObject CC_get_char_value(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15481, v_15482;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15413,v_15414);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_15414;
    v_15482 = v_15413;
// end of prologue
    stack[-1] = nil;
    v_15481 = nil;
    stack[-3] = v_15481;
    v_15481 = v_15482;
    v_15481 = qcdr(v_15481);
    stack[0] = v_15481;
v_15426:
    v_15481 = stack[-3];
    if (v_15481 == nil) goto v_15433;
    else goto v_15434;
v_15433:
    goto v_15441;
v_15437:
    v_15481 = stack[0];
    v_15482 = Llength(nil, v_15481);
    env = stack[-4];
    goto v_15438;
v_15439:
    v_15481 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15440;
v_15441:
    goto v_15437;
v_15438:
    goto v_15439;
v_15440:
    v_15481 = (LispObject)greaterp2(v_15482, v_15481);
    v_15481 = v_15481 ? lisp_true : nil;
    env = stack[-4];
    goto v_15432;
v_15434:
    v_15481 = nil;
    goto v_15432;
    v_15481 = nil;
v_15432:
    if (v_15481 == nil) goto v_15429;
    else goto v_15430;
v_15429:
    goto v_15425;
v_15430:
    goto v_15457;
v_15453:
    v_15481 = stack[0];
    v_15481 = qcar(v_15481);
    v_15482 = qcar(v_15481);
    goto v_15454;
v_15455:
    v_15481 = stack[-2];
    goto v_15456;
v_15457:
    goto v_15453;
v_15454:
    goto v_15455;
v_15456:
    if (equal(v_15482, v_15481)) goto v_15451;
    else goto v_15452;
v_15451:
    v_15481 = stack[0];
    v_15481 = qcar(v_15481);
    v_15481 = qcdr(v_15481);
    v_15481 = qcar(v_15481);
    stack[-1] = v_15481;
    v_15481 = lisp_true;
    stack[-3] = v_15481;
    goto v_15450;
v_15452:
v_15450:
    v_15481 = stack[0];
    v_15481 = qcdr(v_15481);
    stack[0] = v_15481;
    goto v_15426;
v_15425:
    v_15481 = stack[-3];
    if (v_15481 == nil) goto v_15474;
    v_15481 = stack[-1];
    goto v_15420;
v_15474:
    v_15481 = elt(env, 1); // "error in get character element"
    fn = elt(env, 2); // rederr
    v_15481 = (*qfn1(fn))(fn, v_15481);
    goto v_15472;
v_15472:
    v_15481 = nil;
v_15420:
    return onevalue(v_15481);
}



// Code for aex_mvartest

static LispObject CC_aex_mvartest(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15426, v_15427;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15413,v_15414);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15414;
    v_15426 = v_15413;
// end of prologue
    goto v_15421;
v_15417:
    fn = elt(env, 1); // aex_ex
    v_15426 = (*qfn1(fn))(fn, v_15426);
    env = stack[-1];
    v_15427 = qcar(v_15426);
    goto v_15418;
v_15419:
    v_15426 = stack[0];
    goto v_15420;
v_15421:
    goto v_15417;
v_15418:
    goto v_15419;
v_15420:
    {
        fn = elt(env, 2); // sfto_mvartest
        return (*qfn2(fn))(fn, v_15427, v_15426);
    }
}



// Code for multi_args

static LispObject CC_multi_args(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15429;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15413;
// end of prologue
    v_15429 = stack[0];
    if (v_15429 == nil) goto v_15420;
    v_15429 = stack[0];
    v_15429 = qcar(v_15429);
    fn = elt(env, 1); // expression
    v_15429 = (*qfn1(fn))(fn, v_15429);
    env = stack[-1];
    v_15429 = stack[0];
    v_15429 = qcdr(v_15429);
    v_15429 = CC_multi_args(elt(env, 0), v_15429);
    goto v_15418;
v_15420:
v_15418:
    v_15429 = nil;
    return onevalue(v_15429);
}



// Code for n_nary

static LispObject CC_n_nary(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15484, v_15485;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15413,v_15414);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15414;
    stack[-1] = v_15413;
// end of prologue
    goto v_15430;
v_15426:
    v_15484 = stack[-1];
    v_15485 = qcar(v_15484);
    goto v_15427;
v_15428:
    v_15484 = elt(env, 1); // e
    goto v_15429;
v_15430:
    goto v_15426;
v_15427:
    goto v_15428;
v_15429:
    if (v_15485 == v_15484) goto v_15424;
    else goto v_15425;
v_15424:
    goto v_15438;
v_15434:
    v_15485 = stack[0];
    goto v_15435;
v_15436:
    v_15484 = elt(env, 2); // power
    goto v_15437;
v_15438:
    goto v_15434;
v_15435:
    goto v_15436;
v_15437:
    v_15484 = (v_15485 == v_15484 ? lisp_true : nil);
    goto v_15423;
v_15425:
    v_15484 = nil;
    goto v_15423;
    v_15484 = nil;
v_15423:
    if (v_15484 == nil) goto v_15421;
    goto v_15450;
v_15446:
    v_15484 = stack[-1];
    v_15485 = qcdr(v_15484);
    goto v_15447;
v_15448:
    v_15484 = elt(env, 3); // exp
    goto v_15449;
v_15450:
    goto v_15446;
v_15447:
    goto v_15448;
v_15449:
    fn = elt(env, 9); // unary
    v_15484 = (*qfn2(fn))(fn, v_15485, v_15484);
    goto v_15419;
v_15421:
    v_15484 = elt(env, 4); // "<apply>"
    fn = elt(env, 10); // printout
    v_15484 = (*qfn1(fn))(fn, v_15484);
    env = stack[-2];
    v_15484 = elt(env, 5); // "<"
    v_15484 = Lprinc(nil, v_15484);
    env = stack[-2];
    v_15484 = stack[0];
    v_15484 = Lprinc(nil, v_15484);
    env = stack[-2];
    v_15484 = elt(env, 6); // "/>"
    v_15484 = Lprinc(nil, v_15484);
    env = stack[-2];
    goto v_15469;
v_15465:
    v_15485 = qvalue(elt(env, 7)); // indent
    goto v_15466;
v_15467:
    v_15484 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_15468;
v_15469:
    goto v_15465;
v_15466:
    goto v_15467;
v_15468:
    v_15484 = plus2(v_15485, v_15484);
    env = stack[-2];
    qvalue(elt(env, 7)) = v_15484; // indent
    v_15484 = stack[-1];
    fn = elt(env, 11); // multi_elem
    v_15484 = (*qfn1(fn))(fn, v_15484);
    env = stack[-2];
    goto v_15479;
v_15475:
    v_15485 = qvalue(elt(env, 7)); // indent
    goto v_15476;
v_15477:
    v_15484 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_15478;
v_15479:
    goto v_15475;
v_15476:
    goto v_15477;
v_15478:
    v_15484 = difference2(v_15485, v_15484);
    env = stack[-2];
    qvalue(elt(env, 7)) = v_15484; // indent
    v_15484 = elt(env, 8); // "</apply>"
    fn = elt(env, 10); // printout
    v_15484 = (*qfn1(fn))(fn, v_15484);
    goto v_15419;
v_15419:
    v_15484 = nil;
    return onevalue(v_15484);
}



// Code for gcd2

static LispObject CC_gcd2(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15449, v_15450, v_15451;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15413,v_15414);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15414;
    v_15450 = v_15413;
// end of prologue
v_15412:
    goto v_15424;
v_15420:
    goto v_15421;
v_15422:
    v_15449 = stack[0];
    goto v_15423;
v_15424:
    goto v_15420;
v_15421:
    goto v_15422;
v_15423:
    v_15449 = Cremainder(v_15450, v_15449);
    env = stack[-1];
    v_15451 = v_15449;
    goto v_15435;
v_15431:
    v_15450 = v_15451;
    goto v_15432;
v_15433:
    v_15449 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15434;
v_15435:
    goto v_15431;
v_15432:
    goto v_15433;
v_15434:
    if (v_15450 == v_15449) goto v_15429;
    else goto v_15430;
v_15429:
    v_15449 = stack[0];
    goto v_15428;
v_15430:
    goto v_15446;
v_15442:
    v_15450 = stack[0];
    goto v_15443;
v_15444:
    v_15449 = v_15451;
    goto v_15445;
v_15446:
    goto v_15442;
v_15443:
    goto v_15444;
v_15445:
    stack[0] = v_15449;
    goto v_15412;
    v_15449 = nil;
v_15428:
    return onevalue(v_15449);
}



// Code for meq

static LispObject CC_meq(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15444, v_15445, v_15446;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15413,v_15414);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15414;
    stack[-1] = v_15413;
// end of prologue
    v_15444 = stack[-1];
    fn = elt(env, 2); // binding
    v_15444 = (*qfn1(fn))(fn, v_15444);
    env = stack[-2];
    v_15445 = v_15444;
    goto v_15423;
v_15419:
    v_15444 = v_15445;
    if (v_15444 == nil) goto v_15427;
    goto v_15435;
v_15431:
    v_15444 = v_15445;
    goto v_15432;
v_15433:
    v_15446 = elt(env, 1); // unbound
    goto v_15434;
v_15435:
    goto v_15431;
v_15432:
    goto v_15433;
v_15434:
    if (v_15444 == v_15446) goto v_15427;
    v_15444 = v_15445;
    v_15445 = v_15444;
    goto v_15425;
v_15427:
    v_15444 = stack[-1];
    v_15445 = v_15444;
    goto v_15425;
    v_15445 = nil;
v_15425:
    goto v_15420;
v_15421:
    v_15444 = stack[0];
    goto v_15422;
v_15423:
    goto v_15419;
v_15420:
    goto v_15421;
v_15422:
    v_15444 = (equal(v_15445, v_15444) ? lisp_true : nil);
    return onevalue(v_15444);
}



// Code for gcompatible

static LispObject CC_gcompatible(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15439, v_15440, v_15441;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15440 = v_15414;
    v_15441 = v_15413;
// end of prologue
    v_15439 = qvalue(elt(env, 1)); // gmodule!*
    if (v_15439 == nil) goto v_15418;
    else goto v_15419;
v_15418:
    v_15439 = lisp_true;
    goto v_15417;
v_15419:
    goto v_15431;
v_15425:
    v_15439 = v_15441;
    v_15439 = qcdr(v_15439);
    v_15441 = qcar(v_15439);
    goto v_15426;
v_15427:
    v_15439 = v_15440;
    v_15439 = qcdr(v_15439);
    v_15440 = qcar(v_15439);
    goto v_15428;
v_15429:
    v_15439 = qvalue(elt(env, 1)); // gmodule!*
    goto v_15430;
v_15431:
    goto v_15425;
v_15426:
    goto v_15427;
v_15428:
    goto v_15429;
v_15430:
    {
        fn = elt(env, 2); // gevcompatible1
        return (*qfnn(fn))(fn, 3, v_15441, v_15440, v_15439);
    }
    v_15439 = nil;
v_15417:
    return onevalue(v_15439);
}



// Code for groebnormalform

static LispObject CC_groebnormalform(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15431, v_15432, v_15433, v_15434;
    LispObject fn;
    LispObject v_15415, v_15414, v_15413;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "groebnormalform");
    va_start(aa, nargs);
    v_15413 = va_arg(aa, LispObject);
    v_15414 = va_arg(aa, LispObject);
    v_15415 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15431 = v_15415;
    v_15432 = v_15414;
    v_15433 = v_15413;
// end of prologue
    goto v_15426;
v_15418:
    v_15434 = v_15433;
    goto v_15419;
v_15420:
    v_15433 = v_15432;
    goto v_15421;
v_15422:
    v_15432 = v_15431;
    goto v_15423;
v_15424:
    v_15431 = nil;
    goto v_15425;
v_15426:
    goto v_15418;
v_15419:
    goto v_15420;
v_15421:
    goto v_15422;
v_15423:
    goto v_15424;
v_15425:
    {
        fn = elt(env, 1); // groebnormalform0
        return (*qfnn(fn))(fn, 4, v_15434, v_15433, v_15432, v_15431);
    }
}



// Code for memqcar

static LispObject CC_memqcar(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15433, v_15434, v_15435;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15433 = v_15414;
    v_15434 = v_15413;
// end of prologue
    v_15435 = v_15434;
    if (!consp(v_15435)) goto v_15419;
    goto v_15425;
v_15421:
    v_15434 = qcar(v_15434);
    goto v_15422;
v_15423:
    goto v_15424;
v_15425:
    goto v_15421;
v_15422:
    goto v_15423;
v_15424:
    v_15433 = Lmemq(nil, v_15434, v_15433);
    goto v_15417;
v_15419:
    v_15433 = nil;
    goto v_15417;
    v_15433 = nil;
v_15417:
    return onevalue(v_15433);
}



// Code for equalreval

static LispObject CC_equalreval(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15453, v_15454;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_15453 = v_15413;
// end of prologue
    v_15454 = qvalue(elt(env, 1)); // substitution
    if (v_15454 == nil) goto v_15417;
    else goto v_15418;
v_15417:
    goto v_15427;
v_15421:
    stack[-1] = elt(env, 2); // equal
    goto v_15422;
v_15423:
    v_15454 = v_15453;
    stack[0] = qcar(v_15454);
    goto v_15424;
v_15425:
    v_15453 = qcdr(v_15453);
    v_15453 = qcar(v_15453);
    fn = elt(env, 3); // reval
    v_15453 = (*qfn1(fn))(fn, v_15453);
    env = stack[-2];
    v_15453 = ncons(v_15453);
    goto v_15426;
v_15427:
    goto v_15421;
v_15422:
    goto v_15423;
v_15424:
    goto v_15425;
v_15426:
    {
        LispObject v_15457 = stack[-1];
        LispObject v_15458 = stack[0];
        return list2star(v_15457, v_15458, v_15453);
    }
v_15418:
    goto v_15443;
v_15439:
    v_15454 = v_15453;
    v_15454 = qcar(v_15454);
    goto v_15440;
v_15441:
    v_15453 = qcdr(v_15453);
    v_15453 = qcar(v_15453);
    goto v_15442;
v_15443:
    goto v_15439;
v_15440:
    goto v_15441;
v_15442:
    fn = elt(env, 4); // evalequal
    v_15453 = (*qfn2(fn))(fn, v_15454, v_15453);
    if (v_15453 == nil) goto v_15437;
    v_15453 = lisp_true;
    goto v_15416;
v_15437:
    v_15453 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15416;
    v_15453 = nil;
v_15416:
    return onevalue(v_15453);
}



// Code for log_assignment_list

static LispObject CC_log_assignment_list(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15441, v_15442;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15413,v_15414);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15414;
    stack[-1] = v_15413;
// end of prologue
v_15418:
    v_15441 = stack[0];
    if (!consp(v_15441)) goto v_15421;
    else goto v_15422;
v_15421:
    v_15441 = nil;
    goto v_15417;
v_15422:
    goto v_15432;
v_15428:
    v_15442 = stack[-1];
    goto v_15429;
v_15430:
    v_15441 = stack[0];
    v_15441 = qcar(v_15441);
    goto v_15431;
v_15432:
    goto v_15428;
v_15429:
    goto v_15430;
v_15431:
    fn = elt(env, 1); // log_assignment
    v_15441 = (*qfn2(fn))(fn, v_15442, v_15441);
    env = stack[-2];
    if (v_15441 == nil) goto v_15426;
    v_15441 = lisp_true;
    goto v_15417;
v_15426:
    v_15441 = stack[0];
    v_15441 = qcdr(v_15441);
    stack[0] = v_15441;
    goto v_15418;
    v_15441 = nil;
v_15417:
    return onevalue(v_15441);
}



// Code for red!=subst1

static LispObject CC_redMsubst1(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15603, v_15604, v_15605;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15413,v_15414);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_15414;
    stack[-6] = v_15413;
// end of prologue
    v_15603 = stack[-6];
    fn = elt(env, 5); // bas_dpoly
    v_15603 = (*qfn1(fn))(fn, v_15603);
    env = stack[-8];
    stack[0] = v_15603;
    v_15603 = stack[0];
    fn = elt(env, 6); // dp_lc
    v_15603 = (*qfn1(fn))(fn, v_15603);
    env = stack[-8];
    stack[-1] = v_15603;
    v_15603 = stack[-6];
    fn = elt(env, 7); // bas_rep
    v_15603 = (*qfn1(fn))(fn, v_15603);
    env = stack[-8];
    stack[-7] = v_15603;
    v_15603 = stack[-5];
    fn = elt(env, 5); // bas_dpoly
    v_15603 = (*qfn1(fn))(fn, v_15603);
    env = stack[-8];
    stack[-3] = v_15603;
    v_15603 = stack[-3];
    fn = elt(env, 6); // dp_lc
    v_15603 = (*qfn1(fn))(fn, v_15603);
    env = stack[-8];
    stack[-2] = v_15603;
    v_15603 = qvalue(elt(env, 1)); // !*bcsimp
    if (v_15603 == nil) goto v_15440;
    v_15603 = stack[-2];
    fn = elt(env, 8); // cali_bc_inv
    v_15603 = (*qfn1(fn))(fn, v_15603);
    env = stack[-8];
    stack[-4] = v_15603;
    if (v_15603 == nil) goto v_15445;
    goto v_15453;
v_15449:
    v_15604 = stack[-1];
    goto v_15450;
v_15451:
    v_15603 = stack[-4];
    goto v_15452;
v_15453:
    goto v_15449;
v_15450:
    goto v_15451;
v_15452:
    fn = elt(env, 9); // cali_bc_prod
    v_15603 = (*qfn2(fn))(fn, v_15604, v_15603);
    env = stack[-8];
    stack[-1] = v_15603;
    v_15603 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 10); // cali_bc_fi
    v_15603 = (*qfn1(fn))(fn, v_15603);
    env = stack[-8];
    stack[-2] = v_15603;
    goto v_15443;
v_15445:
    goto v_15465;
v_15461:
    v_15604 = stack[-2];
    goto v_15462;
v_15463:
    v_15603 = stack[-1];
    goto v_15464;
v_15465:
    goto v_15461;
v_15462:
    goto v_15463;
v_15464:
    fn = elt(env, 11); // cali_bc_gcd
    v_15603 = (*qfn2(fn))(fn, v_15604, v_15603);
    env = stack[-8];
    stack[-4] = v_15603;
    goto v_15473;
v_15469:
    v_15604 = stack[-2];
    goto v_15470;
v_15471:
    v_15603 = stack[-4];
    goto v_15472;
v_15473:
    goto v_15469;
v_15470:
    goto v_15471;
v_15472:
    fn = elt(env, 12); // cali_bc_divmod
    v_15603 = (*qfn2(fn))(fn, v_15604, v_15603);
    env = stack[-8];
    v_15603 = qcar(v_15603);
    stack[-2] = v_15603;
    goto v_15482;
v_15478:
    v_15604 = stack[-1];
    goto v_15479;
v_15480:
    v_15603 = stack[-4];
    goto v_15481;
v_15482:
    goto v_15478;
v_15479:
    goto v_15480;
v_15481:
    fn = elt(env, 12); // cali_bc_divmod
    v_15603 = (*qfn2(fn))(fn, v_15604, v_15603);
    env = stack[-8];
    v_15603 = qcar(v_15603);
    stack[-1] = v_15603;
    goto v_15443;
v_15443:
    goto v_15438;
v_15440:
v_15438:
    goto v_15491;
v_15487:
    v_15603 = stack[0];
    fn = elt(env, 13); // dp_lmon
    stack[-4] = (*qfn1(fn))(fn, v_15603);
    env = stack[-8];
    goto v_15488;
v_15489:
    v_15603 = stack[-3];
    fn = elt(env, 13); // dp_lmon
    v_15603 = (*qfn1(fn))(fn, v_15603);
    env = stack[-8];
    goto v_15490;
v_15491:
    goto v_15487;
v_15488:
    goto v_15489;
v_15490:
    fn = elt(env, 14); // mo_diff
    v_15603 = (*qfn2(fn))(fn, stack[-4], v_15603);
    env = stack[-8];
    stack[-4] = v_15603;
    goto v_15501;
v_15497:
    goto v_15507;
v_15503:
    v_15604 = stack[-2];
    goto v_15504;
v_15505:
    v_15603 = stack[0];
    goto v_15506;
v_15507:
    goto v_15503;
v_15504:
    goto v_15505;
v_15506:
    fn = elt(env, 15); // dp_times_bc
    stack[0] = (*qfn2(fn))(fn, v_15604, v_15603);
    env = stack[-8];
    goto v_15498;
v_15499:
    goto v_15517;
v_15511:
    v_15605 = stack[-1];
    goto v_15512;
v_15513:
    v_15604 = stack[-4];
    goto v_15514;
v_15515:
    v_15603 = stack[-3];
    goto v_15516;
v_15517:
    goto v_15511;
v_15512:
    goto v_15513;
v_15514:
    goto v_15515;
v_15516:
    fn = elt(env, 16); // dp_times_bcmo
    v_15603 = (*qfnn(fn))(fn, 3, v_15605, v_15604, v_15603);
    env = stack[-8];
    goto v_15500;
v_15501:
    goto v_15497;
v_15498:
    goto v_15499;
v_15500:
    fn = elt(env, 17); // dp_diff
    v_15603 = (*qfn2(fn))(fn, stack[0], v_15603);
    env = stack[-8];
    stack[0] = v_15603;
    goto v_15526;
v_15522:
    goto v_15532;
v_15528:
    v_15604 = stack[-2];
    goto v_15529;
v_15530:
    v_15603 = stack[-7];
    goto v_15531;
v_15532:
    goto v_15528;
v_15529:
    goto v_15530;
v_15531:
    fn = elt(env, 15); // dp_times_bc
    stack[-2] = (*qfn2(fn))(fn, v_15604, v_15603);
    env = stack[-8];
    goto v_15523;
v_15524:
    goto v_15542;
v_15536:
    goto v_15537;
v_15538:
    goto v_15539;
v_15540:
    v_15603 = stack[-5];
    fn = elt(env, 7); // bas_rep
    v_15603 = (*qfn1(fn))(fn, v_15603);
    env = stack[-8];
    goto v_15541;
v_15542:
    goto v_15536;
v_15537:
    goto v_15538;
v_15539:
    goto v_15540;
v_15541:
    fn = elt(env, 16); // dp_times_bcmo
    v_15603 = (*qfnn(fn))(fn, 3, stack[-1], stack[-4], v_15603);
    env = stack[-8];
    goto v_15525;
v_15526:
    goto v_15522;
v_15523:
    goto v_15524;
v_15525:
    fn = elt(env, 17); // dp_diff
    v_15603 = (*qfn2(fn))(fn, stack[-2], v_15603);
    env = stack[-8];
    stack[-1] = v_15603;
    goto v_15556;
v_15552:
    fn = elt(env, 18); // cali_trace
    v_15604 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_15553;
v_15554:
    v_15603 = (LispObject)1264+TAG_FIXNUM; // 79
    goto v_15555;
v_15556:
    goto v_15552;
v_15553:
    goto v_15554;
v_15555:
    v_15603 = (LispObject)greaterp2(v_15604, v_15603);
    v_15603 = v_15603 ? lisp_true : nil;
    env = stack[-8];
    if (v_15603 == nil) goto v_15550;
    v_15603 = elt(env, 2); // "---> "
    v_15603 = Lprinc(nil, v_15603);
    env = stack[-8];
    v_15603 = stack[0];
    fn = elt(env, 19); // dp_print
    v_15603 = (*qfn1(fn))(fn, v_15603);
    env = stack[-8];
    goto v_15548;
v_15550:
    goto v_15570;
v_15566:
    fn = elt(env, 18); // cali_trace
    v_15604 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_15567;
v_15568:
    v_15603 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15569;
v_15570:
    goto v_15566;
v_15567:
    goto v_15568;
v_15569:
    v_15603 = (LispObject)greaterp2(v_15604, v_15603);
    v_15603 = v_15603 ? lisp_true : nil;
    env = stack[-8];
    if (v_15603 == nil) goto v_15564;
    v_15603 = elt(env, 3); // "."
    v_15603 = Lprinc(nil, v_15603);
    env = stack[-8];
    goto v_15548;
v_15564:
v_15548:
    goto v_15584;
v_15580:
    fn = elt(env, 18); // cali_trace
    v_15604 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_15581;
v_15582:
    v_15603 = (LispObject)1424+TAG_FIXNUM; // 89
    goto v_15583;
v_15584:
    goto v_15580;
v_15581:
    goto v_15582;
v_15583:
    v_15603 = (LispObject)greaterp2(v_15604, v_15603);
    v_15603 = v_15603 ? lisp_true : nil;
    env = stack[-8];
    if (v_15603 == nil) goto v_15578;
    v_15603 = elt(env, 4); // " uses "
    v_15603 = Lprinc(nil, v_15603);
    env = stack[-8];
    v_15603 = stack[-3];
    fn = elt(env, 19); // dp_print
    v_15603 = (*qfn1(fn))(fn, v_15603);
    env = stack[-8];
    goto v_15576;
v_15578:
v_15576:
    goto v_15598;
v_15592:
    v_15603 = stack[-6];
    fn = elt(env, 20); // bas_nr
    v_15605 = (*qfn1(fn))(fn, v_15603);
    env = stack[-8];
    goto v_15593;
v_15594:
    v_15604 = stack[0];
    goto v_15595;
v_15596:
    v_15603 = stack[-1];
    goto v_15597;
v_15598:
    goto v_15592;
v_15593:
    goto v_15594;
v_15595:
    goto v_15596;
v_15597:
    {
        fn = elt(env, 21); // bas_make1
        return (*qfnn(fn))(fn, 3, v_15605, v_15604, v_15603);
    }
    return onevalue(v_15603);
}



// Code for insert

static LispObject CC_insert(LispObject env,
                         LispObject v_15414, LispObject v_15415)
{
    env = qenv(env);
    LispObject v_15473, v_15474;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15415,v_15414);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15414,v_15415);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_15473 = v_15415;
    stack[-1] = v_15414;
// end of prologue
// Binding gg!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = v_15473; // gg!*
    stack[0] = nil;
v_15426:
    v_15473 = qvalue(elt(env, 1)); // gg!*
    if (v_15473 == nil) goto v_15429;
    goto v_15439;
v_15435:
    v_15473 = stack[-1];
    v_15474 = qcdr(v_15473);
    goto v_15436;
v_15437:
    v_15473 = qvalue(elt(env, 1)); // gg!*
    v_15473 = qcar(v_15473);
    v_15473 = qcdr(v_15473);
    goto v_15438;
v_15439:
    goto v_15435;
v_15436:
    goto v_15437;
v_15438:
    fn = elt(env, 2); // dless
    v_15473 = (*qfn2(fn))(fn, v_15474, v_15473);
    env = stack[-3];
    if (v_15473 == nil) goto v_15429;
    goto v_15430;
v_15429:
    goto v_15425;
v_15430:
    goto v_15451;
v_15447:
    v_15473 = qvalue(elt(env, 1)); // gg!*
    v_15474 = qcar(v_15473);
    goto v_15448;
v_15449:
    v_15473 = stack[0];
    goto v_15450;
v_15451:
    goto v_15447;
v_15448:
    goto v_15449;
v_15450:
    v_15473 = cons(v_15474, v_15473);
    env = stack[-3];
    stack[0] = v_15473;
    v_15473 = qvalue(elt(env, 1)); // gg!*
    v_15473 = qcdr(v_15473);
    qvalue(elt(env, 1)) = v_15473; // gg!*
    goto v_15426;
v_15425:
    goto v_15462;
v_15458:
    v_15473 = stack[0];
    stack[0] = Lnreverse(nil, v_15473);
    env = stack[-3];
    goto v_15459;
v_15460:
    goto v_15470;
v_15466:
    v_15474 = stack[-1];
    goto v_15467;
v_15468:
    v_15473 = qvalue(elt(env, 1)); // gg!*
    goto v_15469;
v_15470:
    goto v_15466;
v_15467:
    goto v_15468;
v_15469:
    v_15473 = cons(v_15474, v_15473);
    env = stack[-3];
    goto v_15461;
v_15462:
    goto v_15458;
v_15459:
    goto v_15460;
v_15461:
    v_15473 = Lappend(nil, stack[0], v_15473);
    ;}  // end of a binding scope
    return onevalue(v_15473);
}



// Code for dv_cambhead

static LispObject CC_dv_cambhead(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15456, v_15457;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15413;
// end of prologue
v_15412:
    v_15456 = stack[0];
    fn = elt(env, 3); // listp
    v_15456 = (*qfn1(fn))(fn, v_15456);
    env = stack[-2];
    if (v_15456 == nil) goto v_15420;
    goto v_15431;
v_15427:
    v_15456 = stack[0];
    stack[-1] = qcar(v_15456);
    goto v_15428;
v_15429:
    goto v_15439;
v_15435:
    v_15457 = elt(env, 1); // expt
    goto v_15436;
v_15437:
    v_15456 = elt(env, 2); // minus
    goto v_15438;
v_15439:
    goto v_15435;
v_15436:
    goto v_15437;
v_15438:
    v_15456 = list2(v_15457, v_15456);
    env = stack[-2];
    goto v_15430;
v_15431:
    goto v_15427;
v_15428:
    goto v_15429;
v_15430:
    v_15456 = Lmember(nil, stack[-1], v_15456);
    if (v_15456 == nil) goto v_15426;
    v_15456 = stack[0];
    v_15456 = qcdr(v_15456);
    v_15456 = qcar(v_15456);
    stack[0] = v_15456;
    goto v_15412;
v_15426:
    v_15456 = stack[0];
    fn = elt(env, 3); // listp
    v_15456 = (*qfn1(fn))(fn, v_15456);
    if (v_15456 == nil) goto v_15450;
    v_15456 = stack[0];
    v_15456 = qcar(v_15456);
    goto v_15416;
v_15450:
    goto v_15418;
v_15420:
v_15418:
    v_15456 = nil;
v_15416:
    return onevalue(v_15456);
}



// Code for lalr_make_compressed_action_table

static LispObject CC_lalr_make_compressed_action_table(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15457, v_15458;
    LispObject fn;
    argcheck(nargs, 0, "lalr_make_compressed_action_table");
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
    v_15457 = qvalue(elt(env, 1)); // itemset_collection
    v_15457 = Llength(nil, v_15457);
    env = stack[-4];
    v_15457 = sub1(v_15457);
    env = stack[-4];
    v_15457 = Lmkvect(nil, v_15457);
    env = stack[-4];
    stack[-3] = v_15457;
    v_15457 = qvalue(elt(env, 1)); // itemset_collection
    stack[-2] = v_15457;
v_15424:
    v_15457 = stack[-2];
    if (v_15457 == nil) goto v_15428;
    else goto v_15429;
v_15428:
    goto v_15423;
v_15429:
    v_15457 = stack[-2];
    v_15457 = qcar(v_15457);
    v_15458 = v_15457;
    goto v_15441;
v_15435:
    stack[-1] = stack[-3];
    goto v_15436;
v_15437:
    v_15457 = v_15458;
    stack[0] = qcdr(v_15457);
    goto v_15438;
v_15439:
    v_15457 = v_15458;
    fn = elt(env, 3); // lalr_make_compressed_action_row
    v_15457 = (*qfn1(fn))(fn, v_15457);
    env = stack[-4];
    goto v_15440;
v_15441:
    goto v_15435;
v_15436:
    goto v_15437;
v_15438:
    goto v_15439;
v_15440:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_15457;
    v_15457 = stack[-2];
    v_15457 = qcdr(v_15457);
    stack[-2] = v_15457;
    goto v_15424;
v_15423:
    v_15457 = qvalue(elt(env, 2)); // !*lalr_verbose
    if (v_15457 == nil) goto v_15452;
    v_15457 = stack[-3];
    fn = elt(env, 4); // lalr_print_compressed_action_table
    v_15457 = (*qfn1(fn))(fn, v_15457);
    goto v_15450;
v_15452:
v_15450:
    v_15457 = stack[-3];
    return onevalue(v_15457);
}



// Code for ifstat

static LispObject CC_ifstat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15503, v_15504;
    LispObject fn;
    argcheck(nargs, 0, "ifstat");
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
    stack[-1] = nil;
v_15418:
    v_15503 = lisp_true;
    fn = elt(env, 6); // xread
    v_15503 = (*qfn1(fn))(fn, v_15503);
    env = stack[-2];
    stack[0] = v_15503;
    goto v_15429;
v_15425:
    v_15504 = qvalue(elt(env, 1)); // cursym!*
    goto v_15426;
v_15427:
    v_15503 = elt(env, 2); // then
    goto v_15428;
v_15429:
    goto v_15425;
v_15426:
    goto v_15427;
v_15428:
    if (v_15504 == v_15503) goto v_15424;
    goto v_15437;
v_15433:
    v_15504 = elt(env, 3); // if
    goto v_15434;
v_15435:
    v_15503 = lisp_true;
    goto v_15436;
v_15437:
    goto v_15433;
v_15434:
    goto v_15435;
v_15436:
    fn = elt(env, 7); // symerr
    v_15503 = (*qfn2(fn))(fn, v_15504, v_15503);
    env = stack[-2];
    goto v_15422;
v_15424:
v_15422:
    goto v_15445;
v_15441:
    goto v_15442;
v_15443:
    goto v_15452;
v_15448:
    goto v_15449;
v_15450:
    v_15503 = lisp_true;
    fn = elt(env, 6); // xread
    v_15503 = (*qfn1(fn))(fn, v_15503);
    env = stack[-2];
    goto v_15451;
v_15452:
    goto v_15448;
v_15449:
    goto v_15450;
v_15451:
    v_15503 = list2(stack[0], v_15503);
    env = stack[-2];
    goto v_15444;
v_15445:
    goto v_15441;
v_15442:
    goto v_15443;
v_15444:
    fn = elt(env, 8); // aconc!*
    v_15503 = (*qfn2(fn))(fn, stack[-1], v_15503);
    env = stack[-2];
    stack[-1] = v_15503;
    goto v_15464;
v_15460:
    v_15504 = qvalue(elt(env, 1)); // cursym!*
    goto v_15461;
v_15462:
    v_15503 = elt(env, 4); // else
    goto v_15463;
v_15464:
    goto v_15460;
v_15461:
    goto v_15462;
v_15463:
    if (v_15504 == v_15503) goto v_15459;
    goto v_15457;
v_15459:
    goto v_15474;
v_15470:
    fn = elt(env, 9); // scan
    v_15504 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_15471;
v_15472:
    v_15503 = elt(env, 3); // if
    goto v_15473;
v_15474:
    goto v_15470;
v_15471:
    goto v_15472;
v_15473:
    if (v_15504 == v_15503) goto v_15468;
    else goto v_15469;
v_15468:
    goto v_15418;
v_15469:
    goto v_15484;
v_15480:
    goto v_15481;
v_15482:
    goto v_15491;
v_15487:
    stack[0] = lisp_true;
    goto v_15488;
v_15489:
    v_15503 = lisp_true;
    fn = elt(env, 10); // xread1
    v_15503 = (*qfn1(fn))(fn, v_15503);
    env = stack[-2];
    goto v_15490;
v_15491:
    goto v_15487;
v_15488:
    goto v_15489;
v_15490:
    v_15503 = list2(stack[0], v_15503);
    env = stack[-2];
    goto v_15483;
v_15484:
    goto v_15480;
v_15481:
    goto v_15482;
v_15483:
    fn = elt(env, 8); // aconc!*
    v_15503 = (*qfn2(fn))(fn, stack[-1], v_15503);
    env = stack[-2];
    stack[-1] = v_15503;
    goto v_15457;
v_15457:
    goto v_15500;
v_15496:
    v_15504 = elt(env, 5); // cond
    goto v_15497;
v_15498:
    v_15503 = stack[-1];
    goto v_15499;
v_15500:
    goto v_15496;
v_15497:
    goto v_15498;
v_15499:
    return cons(v_15504, v_15503);
    return onevalue(v_15503);
}



// Code for opmtchrevop

static LispObject CC_opmtchrevop(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15451, v_15452;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15413;
// end of prologue
    v_15451 = qvalue(elt(env, 1)); // !*val
    if (v_15451 == nil) goto v_15421;
    else goto v_15422;
v_15421:
    v_15451 = lisp_true;
    goto v_15420;
v_15422:
    goto v_15432;
v_15428:
    v_15452 = elt(env, 2); // cons
    goto v_15429;
v_15430:
    v_15451 = stack[0];
    goto v_15431;
v_15432:
    goto v_15428;
v_15429:
    goto v_15430;
v_15431:
    v_15451 = Lsmemq(nil, v_15452, v_15451);
    env = stack[-2];
    goto v_15420;
    v_15451 = nil;
v_15420:
    if (v_15451 == nil) goto v_15418;
    v_15451 = stack[0];
    {
        fn = elt(env, 3); // opmtch
        return (*qfn1(fn))(fn, v_15451);
    }
v_15418:
    goto v_15445;
v_15441:
    v_15451 = stack[0];
    stack[-1] = qcar(v_15451);
    goto v_15442;
v_15443:
    v_15451 = stack[0];
    v_15451 = qcdr(v_15451);
    fn = elt(env, 4); // revlis
    v_15451 = (*qfn1(fn))(fn, v_15451);
    env = stack[-2];
    goto v_15444;
v_15445:
    goto v_15441;
v_15442:
    goto v_15443;
v_15444:
    v_15451 = cons(stack[-1], v_15451);
    env = stack[-2];
    {
        fn = elt(env, 3); // opmtch
        return (*qfn1(fn))(fn, v_15451);
    }
    v_15451 = nil;
    return onevalue(v_15451);
}



// Code for ofsf_optsubstat

static LispObject CC_ofsf_optsubstat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15472, v_15473;
    LispObject fn;
    LispObject v_15415, v_15414, v_15413;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_optsubstat");
    va_start(aa, nargs);
    v_15413 = va_arg(aa, LispObject);
    v_15414 = va_arg(aa, LispObject);
    v_15415 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15415,v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15413,v_15414,v_15415);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_15472 = v_15415;
    stack[-2] = v_15414;
    stack[0] = v_15413;
// end of prologue
    goto v_15429;
v_15425:
    v_15473 = stack[0];
    v_15473 = qcdr(v_15473);
    v_15473 = qcar(v_15473);
    goto v_15426;
v_15427:
    goto v_15428;
v_15429:
    goto v_15425;
v_15426:
    goto v_15427;
v_15428:
    fn = elt(env, 1); // ofsf_optsplitterm
    v_15472 = (*qfn2(fn))(fn, v_15473, v_15472);
    env = stack[-4];
    stack[-3] = v_15472;
    if (v_15472 == nil) goto v_15422;
    else goto v_15423;
v_15422:
    v_15472 = stack[0];
    goto v_15419;
v_15423:
    goto v_15442;
v_15436:
    v_15472 = stack[0];
    stack[-1] = qcar(v_15472);
    goto v_15437;
v_15438:
    goto v_15450;
v_15446:
    goto v_15456;
v_15452:
    v_15472 = stack[-3];
    v_15473 = qcar(v_15472);
    goto v_15453;
v_15454:
    v_15472 = stack[-2];
    v_15472 = qcar(v_15472);
    goto v_15455;
v_15456:
    goto v_15452;
v_15453:
    goto v_15454;
v_15455:
    fn = elt(env, 2); // multf
    stack[0] = (*qfn2(fn))(fn, v_15473, v_15472);
    env = stack[-4];
    goto v_15447;
v_15448:
    goto v_15466;
v_15462:
    v_15472 = stack[-3];
    v_15473 = qcdr(v_15472);
    goto v_15463;
v_15464:
    v_15472 = stack[-2];
    v_15472 = qcdr(v_15472);
    goto v_15465;
v_15466:
    goto v_15462;
v_15463:
    goto v_15464;
v_15465:
    fn = elt(env, 2); // multf
    v_15472 = (*qfn2(fn))(fn, v_15473, v_15472);
    env = stack[-4];
    goto v_15449;
v_15450:
    goto v_15446;
v_15447:
    goto v_15448;
v_15449:
    fn = elt(env, 3); // addf
    v_15473 = (*qfn2(fn))(fn, stack[0], v_15472);
    goto v_15439;
v_15440:
    v_15472 = nil;
    goto v_15441;
v_15442:
    goto v_15436;
v_15437:
    goto v_15438;
v_15439:
    goto v_15440;
v_15441:
    {
        LispObject v_15478 = stack[-1];
        return list3(v_15478, v_15473, v_15472);
    }
v_15419:
    return onevalue(v_15472);
}



// Code for lambdavar

static LispObject CC_lambdavar(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15422;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
// copy arguments values to proper place
    v_15422 = v_15413;
// end of prologue
    v_15422 = qcdr(v_15422);
    v_15422 = qcdr(v_15422);
    v_15422 = Lreverse(nil, v_15422);
    v_15422 = qcdr(v_15422);
    return onevalue(v_15422);
}



// Code for rowdel

static LispObject CC_rowdel(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15489, v_15490, v_15491;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15413;
// end of prologue
    v_15489 = stack[0];
    fn = elt(env, 3); // delhisto
    v_15489 = (*qfn1(fn))(fn, v_15489);
    env = stack[-2];
    goto v_15423;
v_15417:
    goto v_15428;
v_15424:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_15425;
v_15426:
    goto v_15435;
v_15431:
    v_15490 = qvalue(elt(env, 2)); // maxvar
    goto v_15432;
v_15433:
    v_15489 = stack[0];
    goto v_15434;
v_15435:
    goto v_15431;
v_15432:
    goto v_15433;
v_15434:
    v_15489 = plus2(v_15490, v_15489);
    env = stack[-2];
    goto v_15427;
v_15428:
    goto v_15424;
v_15425:
    goto v_15426;
v_15427:
    v_15491 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_15489-TAG_FIXNUM)/(16/CELL)));
    goto v_15418;
v_15419:
    v_15490 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15420;
v_15421:
    v_15489 = nil;
    goto v_15422;
v_15423:
    goto v_15417;
v_15418:
    goto v_15419;
v_15420:
    goto v_15421;
v_15422:
    *(LispObject *)((char *)v_15491 + (CELL-TAG_VECTOR) + (((intptr_t)v_15490-TAG_FIXNUM)/(16/CELL))) = v_15489;
    goto v_15449;
v_15445:
    goto v_15454;
v_15450:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_15451;
v_15452:
    goto v_15461;
v_15457:
    v_15490 = qvalue(elt(env, 2)); // maxvar
    goto v_15458;
v_15459:
    v_15489 = stack[0];
    goto v_15460;
v_15461:
    goto v_15457;
v_15458:
    goto v_15459;
v_15460:
    v_15489 = plus2(v_15490, v_15489);
    env = stack[-2];
    goto v_15453;
v_15454:
    goto v_15450;
v_15451:
    goto v_15452;
v_15453:
    v_15490 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_15489-TAG_FIXNUM)/(16/CELL)));
    goto v_15446;
v_15447:
    v_15489 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_15448;
v_15449:
    goto v_15445;
v_15446:
    goto v_15447;
v_15448:
    v_15489 = *(LispObject *)((char *)v_15490 + (CELL-TAG_VECTOR) + (((intptr_t)v_15489-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_15489;
v_15444:
    v_15489 = stack[0];
    if (v_15489 == nil) goto v_15469;
    else goto v_15470;
v_15469:
    v_15489 = nil;
    goto v_15443;
v_15470:
    v_15489 = stack[0];
    v_15489 = qcar(v_15489);
    goto v_15481;
v_15477:
    v_15490 = v_15489;
    v_15490 = qcar(v_15490);
    goto v_15478;
v_15479:
    v_15489 = qcdr(v_15489);
    v_15489 = qcar(v_15489);
    goto v_15480;
v_15481:
    goto v_15477;
v_15478:
    goto v_15479;
v_15480:
    fn = elt(env, 4); // downwght
    v_15489 = (*qfn2(fn))(fn, v_15490, v_15489);
    env = stack[-2];
    v_15489 = stack[0];
    v_15489 = qcdr(v_15489);
    stack[0] = v_15489;
    goto v_15444;
v_15443:
    return onevalue(v_15489);
}



// Code for bfplusn

static LispObject CC_bfplusn(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15439, v_15440, v_15441;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15440 = v_15414;
    v_15441 = v_15413;
// end of prologue
    v_15439 = v_15441;
    if (!consp(v_15439)) goto v_15418;
    else goto v_15419;
v_15418:
    goto v_15426;
v_15422:
    v_15439 = v_15441;
    goto v_15423;
v_15424:
    goto v_15425;
v_15426:
    goto v_15422;
v_15423:
    goto v_15424;
v_15425:
    return plus2(v_15439, v_15440);
v_15419:
    goto v_15436;
v_15432:
    v_15439 = v_15441;
    goto v_15433;
v_15434:
    goto v_15435;
v_15436:
    goto v_15432;
v_15433:
    goto v_15434;
v_15435:
    {
        fn = elt(env, 1); // plus!:
        return (*qfn2(fn))(fn, v_15439, v_15440);
    }
    v_15439 = nil;
    return onevalue(v_15439);
}



// Code for fortranname

static LispObject CC_fortranname(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15478, v_15479;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15413;
// end of prologue
    v_15478 = stack[0];
    v_15478 = Lstringp(nil, v_15478);
    env = stack[-1];
    if (v_15478 == nil) goto v_15418;
    v_15478 = stack[0];
    {
        fn = elt(env, 8); // stringtoatom
        return (*qfn1(fn))(fn, v_15478);
    }
v_15418:
    goto v_15433;
v_15429:
    v_15479 = stack[0];
    goto v_15430;
v_15431:
    v_15478 = qvalue(elt(env, 1)); // !*notfortranfuns!*
    goto v_15432;
v_15433:
    goto v_15429;
v_15430:
    goto v_15431;
v_15432:
    v_15478 = Lmemq(nil, v_15479, v_15478);
    if (v_15478 == nil) goto v_15428;
    v_15478 = qvalue(elt(env, 2)); // !*stdout!*
    v_15478 = qcdr(v_15478);
    v_15478 = Lwrs(nil, v_15478);
    env = stack[-1];
    v_15478 = elt(env, 3); // "*** WARNING: "
    v_15478 = Lprinc(nil, v_15478);
    env = stack[-1];
    v_15478 = stack[0];
    v_15478 = Lprin(nil, v_15478);
    env = stack[-1];
    v_15478 = elt(env, 4); // " is not an intrinsic Fortran function"
    fn = elt(env, 9); // prin2t
    v_15478 = (*qfn1(fn))(fn, v_15478);
    env = stack[-1];
    goto v_15426;
v_15428:
v_15426:
    v_15478 = qvalue(elt(env, 5)); // !*double
    if (v_15478 == nil) goto v_15450;
    goto v_15460;
v_15456:
    v_15479 = stack[0];
    goto v_15457;
v_15458:
    v_15478 = elt(env, 6); // !*doublename!*
    goto v_15459;
v_15460:
    goto v_15456;
v_15457:
    goto v_15458;
v_15459:
    v_15478 = get(v_15479, v_15478);
    if (v_15478 == nil) goto v_15454;
    else goto v_15453;
v_15454:
    v_15478 = stack[0];
v_15453:
    goto v_15448;
v_15450:
    goto v_15474;
v_15470:
    v_15479 = stack[0];
    goto v_15471;
v_15472:
    v_15478 = elt(env, 7); // !*fortranname!*
    goto v_15473;
v_15474:
    goto v_15470;
v_15471:
    goto v_15472;
v_15473:
    v_15478 = get(v_15479, v_15478);
    if (v_15478 == nil) goto v_15468;
    else goto v_15467;
v_15468:
    v_15478 = stack[0];
v_15467:
    goto v_15448;
    v_15478 = nil;
v_15448:
    goto v_15416;
    v_15478 = nil;
v_15416:
    return onevalue(v_15478);
}



// Code for mk!-numr

static LispObject CC_mkKnumr(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15470, v_15471, v_15472;
    LispObject fn;
    LispObject v_15415, v_15414, v_15413;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mk-numr");
    va_start(aa, nargs);
    v_15413 = va_arg(aa, LispObject);
    v_15414 = va_arg(aa, LispObject);
    v_15415 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15415,v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15413,v_15414,v_15415);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15415;
    stack[-1] = v_15414;
    stack[-2] = v_15413;
// end of prologue
    stack[-3] = nil;
v_15420:
    goto v_15429;
v_15425:
    v_15471 = stack[-1];
    goto v_15426;
v_15427:
    v_15470 = stack[0];
    goto v_15428;
v_15429:
    goto v_15425;
v_15426:
    goto v_15427;
v_15428:
    if (equal(v_15471, v_15470)) goto v_15423;
    else goto v_15424;
v_15423:
    v_15470 = stack[-3];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_15470);
    }
v_15424:
    goto v_15441;
v_15437:
    goto v_15450;
v_15446:
    v_15471 = stack[-1];
    goto v_15447;
v_15448:
    v_15470 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15449;
v_15450:
    goto v_15446;
v_15447:
    goto v_15448;
v_15449:
    if (v_15471 == v_15470) goto v_15444;
    else goto v_15445;
v_15444:
    v_15470 = stack[-2];
    v_15471 = v_15470;
    goto v_15443;
v_15445:
    goto v_15463;
v_15457:
    v_15472 = elt(env, 1); // difference
    goto v_15458;
v_15459:
    v_15471 = stack[-2];
    goto v_15460;
v_15461:
    v_15470 = stack[-1];
    goto v_15462;
v_15463:
    goto v_15457;
v_15458:
    goto v_15459;
v_15460:
    goto v_15461;
v_15462:
    v_15470 = list3(v_15472, v_15471, v_15470);
    env = stack[-4];
    v_15471 = v_15470;
    goto v_15443;
    v_15471 = nil;
v_15443:
    goto v_15438;
v_15439:
    v_15470 = stack[-3];
    goto v_15440;
v_15441:
    goto v_15437;
v_15438:
    goto v_15439;
v_15440:
    v_15470 = cons(v_15471, v_15470);
    env = stack[-4];
    stack[-3] = v_15470;
    v_15470 = stack[-1];
    v_15470 = add1(v_15470);
    env = stack[-4];
    stack[-1] = v_15470;
    goto v_15420;
    v_15470 = nil;
    return onevalue(v_15470);
}



// Code for mksetq

static LispObject CC_mksetq(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15471, v_15472, v_15473, v_15474;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15413,v_15414);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15472 = v_15414;
    v_15473 = v_15413;
// end of prologue
    v_15471 = v_15473;
    if (!consp(v_15471)) goto v_15418;
    else goto v_15419;
v_15418:
    goto v_15428;
v_15422:
    v_15471 = elt(env, 1); // setq
    goto v_15423;
v_15424:
    goto v_15425;
v_15426:
    goto v_15427;
v_15428:
    goto v_15422;
v_15423:
    goto v_15424;
v_15425:
    goto v_15426;
v_15427:
    return list3(v_15471, v_15473, v_15472);
v_15419:
    goto v_15446;
v_15442:
    v_15471 = v_15473;
    v_15474 = qcar(v_15471);
    goto v_15443;
v_15444:
    v_15471 = elt(env, 2); // setfn
    goto v_15445;
v_15446:
    goto v_15442;
v_15443:
    goto v_15444;
v_15445:
    v_15471 = get(v_15474, v_15471);
    env = stack[0];
    v_15474 = v_15471;
    if (v_15471 == nil) goto v_15440;
    goto v_15457;
v_15451:
    v_15471 = v_15474;
    goto v_15452;
v_15453:
    goto v_15454;
v_15455:
    goto v_15456;
v_15457:
    goto v_15451;
v_15452:
    goto v_15453;
v_15454:
    goto v_15455;
v_15456:
        return Lapply2(nil, 3, v_15471, v_15473, v_15472);
v_15440:
    goto v_15468;
v_15464:
    v_15472 = v_15473;
    goto v_15465;
v_15466:
    v_15471 = elt(env, 3); // "assignment argument"
    goto v_15467;
v_15468:
    goto v_15464;
v_15465:
    goto v_15466;
v_15467:
    fn = elt(env, 4); // typerr
    v_15471 = (*qfn2(fn))(fn, v_15472, v_15471);
    goto v_15438;
v_15438:
    v_15471 = nil;
    goto v_15417;
    v_15471 = nil;
v_15417:
    return onevalue(v_15471);
}



// Code for bndtst

static LispObject CC_bndtst(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15424, v_15425;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15424 = v_15413;
// end of prologue
    goto v_15420;
v_15416:
    fn = elt(env, 2); // abs!:
    v_15425 = (*qfn1(fn))(fn, v_15424);
    env = stack[0];
    goto v_15417;
v_15418:
    v_15424 = qvalue(elt(env, 1)); // tentothetenth!*!*
    goto v_15419;
v_15420:
    goto v_15416;
v_15417:
    goto v_15418;
v_15419:
    {
        fn = elt(env, 3); // greaterp!:
        return (*qfn2(fn))(fn, v_15425, v_15424);
    }
}



// Code for termorder

static LispObject CC_termorder(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15482, v_15483, v_15484;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15413,v_15414);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15414;
    stack[-1] = v_15413;
// end of prologue
    v_15482 = stack[-1];
    if (v_15482 == nil) goto v_15422;
    else goto v_15423;
v_15422:
    goto v_15421;
v_15423:
    v_15482 = stack[-1];
    v_15482 = (LispObject)zerop(v_15482);
    v_15482 = v_15482 ? lisp_true : nil;
    env = stack[-3];
    if (v_15482 == nil) goto v_15427;
    v_15482 = stack[0];
    v_15482 = (LispObject)zerop(v_15482);
    v_15482 = v_15482 ? lisp_true : nil;
    env = stack[-3];
    if (v_15482 == nil) goto v_15427;
    goto v_15421;
v_15427:
    v_15482 = stack[-1];
    v_15482 = (LispObject)zerop(v_15482);
    v_15482 = v_15482 ? lisp_true : nil;
    env = stack[-3];
    if (v_15482 == nil) goto v_15436;
    goto v_15421;
v_15436:
    v_15482 = stack[0];
    v_15482 = (LispObject)zerop(v_15482);
    v_15482 = v_15482 ? lisp_true : nil;
    env = stack[-3];
    if (v_15482 == nil) goto v_15441;
    goto v_15421;
v_15441:
v_15421:
    v_15482 = stack[-1];
    fn = elt(env, 1); // listsum
    v_15482 = (*qfn1(fn))(fn, v_15482);
    env = stack[-3];
    stack[-2] = v_15482;
    v_15482 = stack[0];
    fn = elt(env, 1); // listsum
    v_15482 = (*qfn1(fn))(fn, v_15482);
    env = stack[-3];
    v_15484 = v_15482;
    goto v_15457;
v_15453:
    v_15483 = stack[-2];
    goto v_15454;
v_15455:
    v_15482 = v_15484;
    goto v_15456;
v_15457:
    goto v_15453;
v_15454:
    goto v_15455;
v_15456:
    if (equal(v_15483, v_15482)) goto v_15451;
    else goto v_15452;
v_15451:
    goto v_15465;
v_15461:
    v_15483 = stack[-1];
    goto v_15462;
v_15463:
    v_15482 = stack[0];
    goto v_15464;
v_15465:
    goto v_15461;
v_15462:
    goto v_15463;
v_15464:
    {
        fn = elt(env, 2); // termorder1
        return (*qfn2(fn))(fn, v_15483, v_15482);
    }
v_15452:
    goto v_15475;
v_15471:
    v_15482 = stack[-2];
    goto v_15472;
v_15473:
    v_15483 = v_15484;
    goto v_15474;
v_15475:
    goto v_15471;
v_15472:
    goto v_15473;
v_15474:
    v_15482 = (LispObject)lessp2(v_15482, v_15483);
    v_15482 = v_15482 ? lisp_true : nil;
    if (v_15482 == nil) goto v_15469;
    v_15482 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_15450;
v_15469:
    v_15482 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15450;
    v_15482 = nil;
v_15450:
    return onevalue(v_15482);
}



// Code for lalr_collect_terminals

static LispObject CC_lalr_collect_terminals(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15496, v_15497, v_15498, v_15499;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_15496 = v_15413;
// end of prologue
    v_15499 = nil;
    stack[-2] = v_15496;
v_15421:
    v_15496 = stack[-2];
    if (v_15496 == nil) goto v_15425;
    else goto v_15426;
v_15425:
    goto v_15420;
v_15426:
    v_15496 = stack[-2];
    v_15496 = qcar(v_15496);
    v_15496 = qcdr(v_15496);
    stack[-1] = v_15496;
v_15435:
    v_15496 = stack[-1];
    if (v_15496 == nil) goto v_15440;
    else goto v_15441;
v_15440:
    goto v_15434;
v_15441:
    v_15496 = stack[-1];
    v_15496 = qcar(v_15496);
    v_15496 = qcar(v_15496);
    stack[0] = v_15496;
v_15450:
    v_15496 = stack[0];
    if (v_15496 == nil) goto v_15455;
    else goto v_15456;
v_15455:
    goto v_15449;
v_15456:
    v_15496 = stack[0];
    v_15496 = qcar(v_15496);
    v_15498 = v_15496;
    goto v_15470;
v_15466:
    v_15497 = v_15498;
    goto v_15467;
v_15468:
    v_15496 = v_15499;
    goto v_15469;
v_15470:
    goto v_15466;
v_15467:
    goto v_15468;
v_15469:
    v_15496 = Lmember(nil, v_15497, v_15496);
    if (v_15496 == nil) goto v_15464;
    else goto v_15465;
v_15464:
    goto v_15479;
v_15475:
    v_15496 = v_15498;
    goto v_15476;
v_15477:
    v_15497 = v_15499;
    goto v_15478;
v_15479:
    goto v_15475;
v_15476:
    goto v_15477;
v_15478:
    v_15496 = cons(v_15496, v_15497);
    env = stack[-3];
    v_15499 = v_15496;
    goto v_15463;
v_15465:
v_15463:
    v_15496 = stack[0];
    v_15496 = qcdr(v_15496);
    stack[0] = v_15496;
    goto v_15450;
v_15449:
    v_15496 = stack[-1];
    v_15496 = qcdr(v_15496);
    stack[-1] = v_15496;
    goto v_15435;
v_15434:
    v_15496 = stack[-2];
    v_15496 = qcdr(v_15496);
    stack[-2] = v_15496;
    goto v_15421;
v_15420:
    goto v_15493;
v_15489:
    v_15497 = v_15499;
    goto v_15490;
v_15491:
    v_15496 = qvalue(elt(env, 1)); // nonterminals
    goto v_15492;
v_15493:
    goto v_15489;
v_15490:
    goto v_15491;
v_15492:
    {
        fn = elt(env, 2); // setdiff
        return (*qfn2(fn))(fn, v_15497, v_15496);
    }
    return onevalue(v_15496);
}



// Code for co_new

static LispObject CC_co_new(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15416;
    argcheck(nargs, 0, "co_new");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_15416 = nil;
    return ncons(v_15416);
}



// Code for homogp

static LispObject CC_homogp(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15502, v_15503;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15413;
// end of prologue
    v_15502 = stack[0];
    if (!consp(v_15502)) goto v_15425;
    else goto v_15426;
v_15425:
    v_15502 = lisp_true;
    goto v_15424;
v_15426:
    v_15502 = stack[0];
    v_15502 = qcar(v_15502);
    v_15502 = (consp(v_15502) ? nil : lisp_true);
    goto v_15424;
    v_15502 = nil;
v_15424:
    if (v_15502 == nil) goto v_15422;
    v_15502 = lisp_true;
    goto v_15420;
v_15422:
    v_15502 = stack[0];
    v_15502 = qcar(v_15502);
    if (!consp(v_15502)) goto v_15439;
    else goto v_15440;
v_15439:
    v_15502 = lisp_true;
    goto v_15438;
v_15440:
    v_15502 = stack[0];
    v_15502 = qcar(v_15502);
    v_15502 = qcar(v_15502);
    v_15502 = (consp(v_15502) ? nil : lisp_true);
    goto v_15438;
    v_15502 = nil;
v_15438:
    goto v_15420;
    v_15502 = nil;
v_15420:
    if (v_15502 == nil) goto v_15418;
    v_15502 = nil;
    goto v_15416;
v_15418:
    v_15502 = stack[0];
    v_15502 = qcdr(v_15502);
    v_15502 = qcar(v_15502);
    v_15502 = qcdr(v_15502);
    if (v_15502 == nil) goto v_15451;
    else goto v_15452;
v_15451:
    v_15502 = nil;
    goto v_15416;
v_15452:
    v_15502 = stack[0];
    v_15502 = qcdr(v_15502);
    v_15502 = qcar(v_15502);
    fn = elt(env, 1); // lastnondomain
    v_15502 = (*qfn1(fn))(fn, v_15502);
    env = stack[-2];
    v_15502 = qcdr(v_15502);
    v_15503 = v_15502;
    v_15502 = v_15503;
    if (!consp(v_15502)) goto v_15468;
    else goto v_15469;
v_15468:
    v_15502 = lisp_true;
    goto v_15467;
v_15469:
    v_15502 = v_15503;
    v_15502 = qcar(v_15502);
    v_15502 = (consp(v_15502) ? nil : lisp_true);
    goto v_15467;
    v_15502 = nil;
v_15467:
    if (v_15502 == nil) goto v_15459;
    v_15502 = nil;
    goto v_15416;
v_15459:
    goto v_15484;
v_15480:
    v_15502 = stack[0];
    v_15502 = qcdr(v_15502);
    v_15502 = qcar(v_15502);
    v_15502 = qcar(v_15502);
    v_15502 = qcar(v_15502);
    fn = elt(env, 2); // listsum
    stack[-1] = (*qfn1(fn))(fn, v_15502);
    env = stack[-2];
    goto v_15481;
v_15482:
    v_15502 = stack[0];
    v_15502 = qcdr(v_15502);
    v_15502 = qcar(v_15502);
    fn = elt(env, 1); // lastnondomain
    v_15502 = (*qfn1(fn))(fn, v_15502);
    env = stack[-2];
    v_15502 = qcar(v_15502);
    v_15502 = qcar(v_15502);
    fn = elt(env, 2); // listsum
    v_15502 = (*qfn1(fn))(fn, v_15502);
    goto v_15483;
v_15484:
    goto v_15480;
v_15481:
    goto v_15482;
v_15483:
    if (equal(stack[-1], v_15502)) goto v_15478;
    else goto v_15479;
v_15478:
    v_15502 = lisp_true;
    goto v_15416;
v_15479:
    v_15502 = nil;
    goto v_15416;
    v_15502 = nil;
v_15416:
    return onevalue(v_15502);
}



// Code for bc_2sq

static LispObject CC_bc_2sq(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15416;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15416 = v_15413;
// end of prologue
    return onevalue(v_15416);
}



// Code for atomlis

static LispObject CC_atomlis(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15435, v_15436;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15435 = v_15413;
// end of prologue
v_15412:
    v_15436 = v_15435;
    if (v_15436 == nil) goto v_15417;
    else goto v_15418;
v_15417:
    v_15435 = lisp_true;
    goto v_15416;
v_15418:
    v_15436 = v_15435;
    v_15436 = qcar(v_15436);
    if (!consp(v_15436)) goto v_15425;
    else goto v_15426;
v_15425:
    v_15435 = qcdr(v_15435);
    goto v_15412;
v_15426:
    v_15435 = nil;
    goto v_15424;
    v_15435 = nil;
v_15424:
    goto v_15416;
    v_15435 = nil;
v_15416:
    return onevalue(v_15435);
}



// Code for dip2vdp

static LispObject CC_dip2vdp(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15479, v_15480;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_15480 = v_15413;
// end of prologue
    v_15479 = qvalue(elt(env, 1)); // !*groebsubs
    if (v_15479 == nil) goto v_15418;
    v_15479 = v_15480;
    fn = elt(env, 3); // dipsubs2
    v_15479 = (*qfn1(fn))(fn, v_15479);
    env = stack[-3];
    goto v_15416;
v_15418:
    v_15479 = v_15480;
    goto v_15416;
    v_15479 = nil;
v_15416:
    v_15480 = v_15479;
    v_15479 = v_15480;
    if (v_15479 == nil) goto v_15428;
    else goto v_15429;
v_15428:
    goto v_15440;
v_15432:
    stack[-2] = elt(env, 2); // vdp
    goto v_15433;
v_15434:
    stack[-1] = nil;
    goto v_15435;
v_15436:
    v_15479 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 4); // a2bc
    stack[0] = (*qfn1(fn))(fn, v_15479);
    env = stack[-3];
    goto v_15437;
v_15438:
    goto v_15450;
v_15446:
    v_15480 = nil;
    goto v_15447;
v_15448:
    v_15479 = nil;
    goto v_15449;
v_15450:
    goto v_15446;
v_15447:
    goto v_15448;
v_15449:
    v_15479 = list2(v_15480, v_15479);
    goto v_15439;
v_15440:
    goto v_15432;
v_15433:
    goto v_15434;
v_15435:
    goto v_15436;
v_15437:
    goto v_15438;
v_15439:
    {
        LispObject v_15484 = stack[-2];
        LispObject v_15485 = stack[-1];
        LispObject v_15486 = stack[0];
        return list3star(v_15484, v_15485, v_15486, v_15479);
    }
v_15429:
    goto v_15464;
v_15456:
    stack[-2] = elt(env, 2); // vdp
    goto v_15457;
v_15458:
    v_15479 = v_15480;
    stack[-1] = qcar(v_15479);
    goto v_15459;
v_15460:
    v_15479 = v_15480;
    v_15479 = qcdr(v_15479);
    stack[0] = qcar(v_15479);
    goto v_15461;
v_15462:
    goto v_15476;
v_15472:
    goto v_15473;
v_15474:
    v_15479 = nil;
    goto v_15475;
v_15476:
    goto v_15472;
v_15473:
    goto v_15474;
v_15475:
    v_15479 = list2(v_15480, v_15479);
    goto v_15463;
v_15464:
    goto v_15456;
v_15457:
    goto v_15458;
v_15459:
    goto v_15460;
v_15461:
    goto v_15462;
v_15463:
    {
        LispObject v_15487 = stack[-2];
        LispObject v_15488 = stack[-1];
        LispObject v_15489 = stack[0];
        return list3star(v_15487, v_15488, v_15489, v_15479);
    }
    v_15479 = nil;
    return onevalue(v_15479);
}



// Code for contr!-strand

static LispObject CC_contrKstrand(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15438, v_15439;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15413,v_15414);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15414;
    v_15438 = v_15413;
// end of prologue
v_15418:
    v_15439 = stack[0];
    if (v_15439 == nil) goto v_15421;
    else goto v_15422;
v_15421:
    goto v_15417;
v_15422:
    goto v_15432;
v_15428:
    v_15439 = v_15438;
    goto v_15429;
v_15430:
    v_15438 = stack[0];
    v_15438 = qcar(v_15438);
    goto v_15431;
v_15432:
    goto v_15428;
v_15429:
    goto v_15430;
v_15431:
    fn = elt(env, 1); // contr1!-strand
    v_15438 = (*qfn2(fn))(fn, v_15439, v_15438);
    env = stack[-1];
    v_15439 = stack[0];
    v_15439 = qcdr(v_15439);
    stack[0] = v_15439;
    goto v_15418;
    v_15438 = nil;
v_15417:
    return onevalue(v_15438);
}



// Code for assert_stat1

static LispObject CC_assert_stat1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15521, v_15522;
    LispObject fn;
    argcheck(nargs, 0, "assert_stat1");
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
    stack[0] = nil;
    goto v_15425;
v_15421:
    fn = elt(env, 7); // scan
    v_15522 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_15422;
v_15423:
    v_15521 = elt(env, 1); // !*lpar!*
    goto v_15424;
v_15425:
    goto v_15421;
v_15422:
    goto v_15423;
v_15424:
    if (v_15522 == v_15521) goto v_15420;
    goto v_15434;
v_15430:
    v_15522 = elt(env, 2); // "expecting '(' in assert but found"
    goto v_15431;
v_15432:
    v_15521 = qvalue(elt(env, 3)); // cursym!*
    goto v_15433;
v_15434:
    goto v_15430;
v_15431:
    goto v_15432;
v_15433:
    v_15521 = list2(v_15522, v_15521);
    env = stack[-1];
    fn = elt(env, 8); // rederr
    v_15521 = (*qfn1(fn))(fn, v_15521);
    env = stack[-1];
    goto v_15418;
v_15420:
v_15418:
    goto v_15445;
v_15441:
    fn = elt(env, 7); // scan
    v_15522 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_15442;
v_15443:
    v_15521 = elt(env, 4); // !*rpar!*
    goto v_15444;
v_15445:
    goto v_15441;
v_15442:
    goto v_15443;
v_15444:
    if (v_15522 == v_15521) goto v_15439;
    else goto v_15440;
v_15439:
    v_15521 = nil;
    goto v_15416;
v_15440:
v_15451:
    goto v_15457;
v_15453:
    v_15522 = qvalue(elt(env, 3)); // cursym!*
    goto v_15454;
v_15455:
    v_15521 = stack[0];
    goto v_15456;
v_15457:
    goto v_15453;
v_15454:
    goto v_15455;
v_15456:
    v_15521 = cons(v_15522, v_15521);
    env = stack[-1];
    stack[0] = v_15521;
    fn = elt(env, 7); // scan
    v_15521 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_15473;
v_15469:
    v_15522 = qvalue(elt(env, 3)); // cursym!*
    goto v_15470;
v_15471:
    v_15521 = elt(env, 5); // !*comma!*
    goto v_15472;
v_15473:
    goto v_15469;
v_15470:
    goto v_15471;
v_15472:
    if (v_15522 == v_15521) goto v_15468;
    goto v_15481;
v_15477:
    v_15522 = qvalue(elt(env, 3)); // cursym!*
    goto v_15478;
v_15479:
    v_15521 = elt(env, 4); // !*rpar!*
    goto v_15480;
v_15481:
    goto v_15477;
v_15478:
    goto v_15479;
v_15480:
    v_15521 = Lneq(nil, v_15522, v_15521);
    env = stack[-1];
    goto v_15466;
v_15468:
    v_15521 = nil;
    goto v_15466;
    v_15521 = nil;
v_15466:
    if (v_15521 == nil) goto v_15464;
    goto v_15493;
v_15489:
    v_15522 = elt(env, 6); // "expecting ',' or ')' in assert but found"
    goto v_15490;
v_15491:
    v_15521 = qvalue(elt(env, 3)); // cursym!*
    goto v_15492;
v_15493:
    goto v_15489;
v_15490:
    goto v_15491;
v_15492:
    v_15521 = list2(v_15522, v_15521);
    env = stack[-1];
    fn = elt(env, 8); // rederr
    v_15521 = (*qfn1(fn))(fn, v_15521);
    env = stack[-1];
    goto v_15462;
v_15464:
v_15462:
    goto v_15504;
v_15500:
    v_15522 = qvalue(elt(env, 3)); // cursym!*
    goto v_15501;
v_15502:
    v_15521 = elt(env, 5); // !*comma!*
    goto v_15503;
v_15504:
    goto v_15500;
v_15501:
    goto v_15502;
v_15503:
    if (v_15522 == v_15521) goto v_15498;
    else goto v_15499;
v_15498:
    fn = elt(env, 7); // scan
    v_15521 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_15497;
v_15499:
v_15497:
    goto v_15516;
v_15512:
    v_15522 = qvalue(elt(env, 3)); // cursym!*
    goto v_15513;
v_15514:
    v_15521 = elt(env, 4); // !*rpar!*
    goto v_15515;
v_15516:
    goto v_15512;
v_15513:
    goto v_15514;
v_15515:
    if (v_15522 == v_15521) goto v_15511;
    goto v_15451;
v_15511:
    v_15521 = stack[0];
        return Lnreverse(nil, v_15521);
v_15416:
    return onevalue(v_15521);
}



// Code for nf

static LispObject CC_nf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15706, v_15707, v_15708;
    LispObject fn;
    LispObject v_15416, v_15415, v_15414;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "nf");
    va_start(aa, nargs);
    v_15414 = va_arg(aa, LispObject);
    v_15415 = va_arg(aa, LispObject);
    v_15416 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15416,v_15415,v_15414);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15414,v_15415,v_15416);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_15416;
    v_15706 = v_15415;
    v_15707 = v_15414;
// end of prologue
// Binding gg!*
// FLUIDBIND: reloadenv=11 litvec-offset=1 saveloc=10
{   bind_fluid_stack bind_fluid_var(-11, 1, -10);
    qvalue(elt(env, 1)) = v_15706; // gg!*
    v_15706 = qvalue(elt(env, 1)); // gg!*
    if (v_15706 == nil) goto v_15424;
    else goto v_15425;
v_15424:
    v_15706 = v_15707;
    goto v_15423;
v_15425:
    stack[-3] = nil;
    v_15706 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_15706;
    v_15706 = v_15707;
    stack[-8] = v_15706;
    v_15706 = qvalue(elt(env, 1)); // gg!*
    stack[-2] = v_15706;
v_15443:
    v_15706 = stack[-8];
    if (v_15706 == nil) goto v_15450;
    else goto v_15451;
v_15450:
    goto v_15444;
v_15451:
    v_15706 = stack[-8];
    v_15706 = qcar(v_15706);
    v_15706 = qcar(v_15706);
    stack[-7] = v_15706;
v_15458:
    v_15706 = stack[-2];
    if (v_15706 == nil) goto v_15466;
    goto v_15473;
v_15469:
    v_15707 = stack[-7];
    goto v_15470;
v_15471:
    v_15706 = stack[-2];
    v_15706 = qcar(v_15706);
    v_15706 = qcdr(v_15706);
    goto v_15472;
v_15473:
    goto v_15469;
v_15470:
    goto v_15471;
v_15472:
    fn = elt(env, 12); // dless
    v_15706 = (*qfn2(fn))(fn, v_15707, v_15706);
    env = stack[-11];
    goto v_15464;
v_15466:
    v_15706 = nil;
    goto v_15464;
    v_15706 = nil;
v_15464:
    if (v_15706 == nil) goto v_15461;
    else goto v_15462;
v_15461:
    goto v_15457;
v_15462:
    v_15706 = stack[-2];
    v_15706 = qcdr(v_15706);
    stack[-2] = v_15706;
    goto v_15458;
v_15457:
    v_15706 = stack[-2];
    if (v_15706 == nil) goto v_15486;
    else goto v_15487;
v_15486:
    goto v_15444;
v_15487:
    v_15706 = stack[-2];
    stack[-1] = v_15706;
v_15492:
    v_15706 = stack[-1];
    if (v_15706 == nil) goto v_15495;
    goto v_15504;
v_15500:
    goto v_15510;
v_15506:
    v_15706 = stack[-1];
    v_15706 = qcar(v_15706);
    v_15707 = qcdr(v_15706);
    goto v_15507;
v_15508:
    v_15706 = stack[-7];
    goto v_15509;
v_15510:
    goto v_15506;
v_15507:
    goto v_15508;
v_15509:
    fn = elt(env, 13); // dd
    stack[-4] = (*qfn2(fn))(fn, v_15707, v_15706);
    env = stack[-11];
    goto v_15501;
v_15502:
    goto v_15520;
v_15516:
    v_15707 = stack[-9];
    goto v_15517;
v_15518:
    v_15706 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_15519;
v_15520:
    goto v_15516;
v_15517:
    goto v_15518;
v_15519:
    v_15706 = plus2(v_15707, v_15706);
    env = stack[-11];
    goto v_15503;
v_15504:
    goto v_15500;
v_15501:
    goto v_15502;
v_15503:
    if (((intptr_t)(stack[-4])) < ((intptr_t)(v_15706))) goto v_15499;
    else goto v_15495;
v_15499:
    goto v_15496;
v_15495:
    goto v_15491;
v_15496:
    v_15706 = stack[-1];
    v_15706 = qcdr(v_15706);
    stack[-1] = v_15706;
    goto v_15492;
v_15491:
    v_15706 = stack[-1];
    if (v_15706 == nil) goto v_15528;
    else goto v_15529;
v_15528:
    v_15706 = qvalue(elt(env, 2)); // redtails
    if (v_15706 == nil) goto v_15534;
    goto v_15543;
v_15537:
    v_15708 = stack[-7];
    goto v_15538;
v_15539:
    v_15706 = stack[-8];
    v_15706 = qcar(v_15706);
    v_15707 = qcdr(v_15706);
    goto v_15540;
v_15541:
    v_15706 = stack[-3];
    goto v_15542;
v_15543:
    goto v_15537;
v_15538:
    goto v_15539;
v_15540:
    goto v_15541;
v_15542:
    v_15706 = acons(v_15708, v_15707, v_15706);
    env = stack[-11];
    stack[-3] = v_15706;
    v_15706 = stack[-8];
    v_15706 = qcdr(v_15706);
    stack[-8] = v_15706;
    goto v_15532;
v_15534:
    goto v_15444;
v_15532:
    goto v_15527;
v_15529:
    goto v_15559;
v_15555:
    v_15707 = qvalue(elt(env, 3)); // gv!*
    goto v_15556;
v_15557:
    v_15706 = stack[-1];
    v_15706 = qcar(v_15706);
    v_15706 = qcar(v_15706);
    goto v_15558;
v_15559:
    goto v_15555;
v_15556:
    goto v_15557;
v_15558:
    v_15706 = *(LispObject *)((char *)v_15707 + (CELL-TAG_VECTOR) + (((intptr_t)v_15706-TAG_FIXNUM)/(16/CELL)));
    stack[-6] = v_15706;
    goto v_15570;
v_15566:
    v_15706 = stack[-8];
    v_15706 = qcar(v_15706);
    v_15707 = qcdr(v_15706);
    goto v_15567;
v_15568:
    v_15706 = stack[-6];
    v_15706 = qcar(v_15706);
    v_15706 = qcdr(v_15706);
    goto v_15569;
v_15570:
    goto v_15566;
v_15567:
    goto v_15568;
v_15569:
    fn = elt(env, 14); // gcdf!*
    v_15706 = (*qfn2(fn))(fn, v_15707, v_15706);
    env = stack[-11];
    stack[-4] = v_15706;
    goto v_15582;
v_15578:
    v_15706 = stack[-8];
    v_15706 = qcar(v_15706);
    v_15707 = qcdr(v_15706);
    goto v_15579;
v_15580:
    v_15706 = stack[-4];
    goto v_15581;
v_15582:
    goto v_15578;
v_15579:
    goto v_15580;
v_15581:
    fn = elt(env, 15); // cdiv
    v_15706 = (*qfn2(fn))(fn, v_15707, v_15706);
    env = stack[-11];
    stack[-5] = v_15706;
    goto v_15592;
v_15588:
    v_15706 = stack[-6];
    v_15706 = qcar(v_15706);
    v_15707 = qcdr(v_15706);
    goto v_15589;
v_15590:
    v_15706 = stack[-4];
    goto v_15591;
v_15592:
    goto v_15588;
v_15589:
    goto v_15590;
v_15591:
    fn = elt(env, 15); // cdiv
    v_15706 = (*qfn2(fn))(fn, v_15707, v_15706);
    env = stack[-11];
    stack[-4] = v_15706;
    goto v_15602;
v_15598:
    v_15707 = stack[-8];
    goto v_15599;
v_15600:
    v_15706 = stack[-4];
    goto v_15601;
v_15602:
    goto v_15598;
v_15599:
    goto v_15600;
v_15601:
    fn = elt(env, 16); // pcmult
    v_15706 = (*qfn2(fn))(fn, v_15707, v_15706);
    env = stack[-11];
    stack[-8] = v_15706;
    goto v_15610;
v_15606:
    v_15707 = stack[-3];
    goto v_15607;
v_15608:
    v_15706 = stack[-4];
    goto v_15609;
v_15610:
    goto v_15606;
v_15607:
    goto v_15608;
v_15609:
    fn = elt(env, 16); // pcmult
    v_15706 = (*qfn2(fn))(fn, v_15707, v_15706);
    env = stack[-11];
    stack[-3] = v_15706;
    goto v_15618;
v_15614:
    v_15707 = stack[-6];
    goto v_15615;
v_15616:
    v_15706 = stack[-5];
    goto v_15617;
v_15618:
    goto v_15614;
v_15615:
    goto v_15616;
v_15617:
    fn = elt(env, 16); // pcmult
    v_15706 = (*qfn2(fn))(fn, v_15707, v_15706);
    env = stack[-11];
    stack[-6] = v_15706;
    goto v_15626;
v_15622:
    v_15706 = stack[-6];
    stack[-4] = qcdr(v_15706);
    goto v_15623;
v_15624:
    goto v_15634;
v_15630:
    v_15707 = stack[-7];
    goto v_15631;
v_15632:
    v_15706 = stack[-1];
    v_15706 = qcar(v_15706);
    v_15706 = qcdr(v_15706);
    goto v_15633;
v_15634:
    goto v_15630;
v_15631:
    goto v_15632;
v_15633:
    fn = elt(env, 17); // dquot
    v_15706 = (*qfn2(fn))(fn, v_15707, v_15706);
    env = stack[-11];
    goto v_15625;
v_15626:
    goto v_15622;
v_15623:
    goto v_15624;
v_15625:
    fn = elt(env, 18); // pdmult
    v_15706 = (*qfn2(fn))(fn, stack[-4], v_15706);
    env = stack[-11];
    stack[-4] = v_15706;
    v_15706 = qvalue(elt(env, 4)); // tred
    if (v_15706 == nil) goto v_15642;
    v_15706 = Lterpri(nil, 0);
    env = stack[-11];
    v_15706 = elt(env, 5); // "r e d u c t i o n :  "
    v_15706 = Lprinc(nil, v_15706);
    env = stack[-11];
    v_15706 = stack[-7];
    v_15706 = Lprinc(nil, v_15706);
    env = stack[-11];
    v_15706 = elt(env, 6); // "/"
    v_15706 = Lprinc(nil, v_15706);
    env = stack[-11];
    v_15706 = stack[-1];
    v_15706 = qcar(v_15706);
    v_15706 = qcdr(v_15706);
    v_15706 = Lprinc(nil, v_15706);
    env = stack[-11];
    v_15706 = Lterpri(nil, 0);
    env = stack[-11];
    goto v_15640;
v_15642:
v_15640:
    v_15706 = qvalue(elt(env, 7)); // stars
    if (v_15706 == nil) goto v_15661;
    v_15706 = elt(env, 8); // "*"
    v_15706 = Lprinc(nil, v_15706);
    env = stack[-11];
    goto v_15659;
v_15661:
v_15659:
    v_15706 = stack[0];
    v_15706 = (LispObject)((intptr_t)(v_15706) + 0x10);
    stack[0] = v_15706;
    goto v_15673;
v_15669:
    v_15706 = stack[-8];
    v_15707 = qcdr(v_15706);
    goto v_15670;
v_15671:
    v_15706 = stack[-4];
    goto v_15672;
v_15673:
    goto v_15669;
v_15670:
    goto v_15671;
v_15672:
    fn = elt(env, 19); // pdif
    v_15706 = (*qfn2(fn))(fn, v_15707, v_15706);
    env = stack[-11];
    stack[-8] = v_15706;
    goto v_15527;
v_15527:
    goto v_15443;
v_15444:
    goto v_15682;
v_15678:
    v_15707 = qvalue(elt(env, 9)); // reductions!*
    goto v_15679;
v_15680:
    v_15706 = stack[0];
    goto v_15681;
v_15682:
    goto v_15678;
v_15679:
    goto v_15680;
v_15681:
    v_15706 = (LispObject)(intptr_t)((intptr_t)v_15707 + (intptr_t)v_15706 - TAG_FIXNUM);
    qvalue(elt(env, 9)) = v_15706; // reductions!*
    v_15706 = qvalue(elt(env, 10)); // nforms!*
    v_15706 = (LispObject)((intptr_t)(v_15706) + 0x10);
    qvalue(elt(env, 10)) = v_15706; // nforms!*
    goto v_15694;
v_15690:
    v_15706 = stack[-3];
    v_15707 = Lnreverse(nil, v_15706);
    env = stack[-11];
    goto v_15691;
v_15692:
    v_15706 = stack[-8];
    goto v_15693;
v_15694:
    goto v_15690;
v_15691:
    goto v_15692;
v_15693:
    v_15706 = Lappend(nil, v_15707, v_15706);
    env = stack[-11];
    fn = elt(env, 20); // gcdout
    v_15706 = (*qfn1(fn))(fn, v_15706);
    env = stack[-11];
    stack[-4] = v_15706;
    v_15706 = stack[-4];
    if (v_15706 == nil) goto v_15700;
    else goto v_15701;
v_15700:
    v_15706 = qvalue(elt(env, 11)); // zeros!*
    v_15706 = (LispObject)((intptr_t)(v_15706) + 0x10);
    qvalue(elt(env, 11)) = v_15706; // zeros!*
    goto v_15699;
v_15701:
v_15699:
    v_15706 = stack[-4];
    goto v_15423;
    v_15706 = nil;
v_15423:
    ;}  // end of a binding scope
    return onevalue(v_15706);
}



// Code for setk1

static LispObject CC_setk1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15693, v_15694, v_15695, v_15696, v_15697;
    LispObject fn;
    LispObject v_15415, v_15414, v_15413;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "setk1");
    va_start(aa, nargs);
    v_15413 = va_arg(aa, LispObject);
    v_15414 = va_arg(aa, LispObject);
    v_15415 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15415,v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15413,v_15414,v_15415);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-1] = v_15415;
    stack[0] = v_15414;
    stack[-5] = v_15413;
// end of prologue
    stack[-6] = nil;
// Binding !*uncached
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-7, 1, -2);
    qvalue(elt(env, 1)) = nil; // !*uncached
    v_15693 = lisp_true;
    qvalue(elt(env, 1)) = v_15693; // !*uncached
    v_15693 = stack[-5];
    if (!consp(v_15693)) goto v_15426;
    else goto v_15427;
v_15426:
    v_15693 = stack[-1];
    if (v_15693 == nil) goto v_15431;
    else goto v_15432;
v_15431:
    v_15693 = stack[-5];
    if (!symbolp(v_15693)) v_15693 = nil;
    else { v_15693 = qfastgets(v_15693);
           if (v_15693 != nil) { v_15693 = elt(v_15693, 4); // avalue
#ifdef RECORD_GET
             if (v_15693 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_15693 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_15693 == SPID_NOPROP) v_15693 = nil; }}
#endif
    if (v_15693 == nil) goto v_15436;
    else goto v_15437;
v_15436:
    goto v_15451;
v_15441:
    v_15697 = nil;
    goto v_15442;
v_15443:
    v_15696 = stack[-5];
    goto v_15444;
v_15445:
    v_15695 = elt(env, 2); // "not found"
    goto v_15446;
v_15447:
    v_15694 = nil;
    goto v_15448;
v_15449:
    v_15693 = nil;
    goto v_15450;
v_15451:
    goto v_15441;
v_15442:
    goto v_15443;
v_15444:
    goto v_15445;
v_15446:
    goto v_15447;
v_15448:
    goto v_15449;
v_15450:
    fn = elt(env, 10); // msgpri
    v_15693 = (*qfnn(fn))(fn, 5, v_15697, v_15696, v_15695, v_15694, v_15693);
    goto v_15435;
v_15437:
    goto v_15464;
v_15460:
    v_15694 = stack[-5];
    goto v_15461;
v_15462:
    v_15693 = elt(env, 3); // avalue
    goto v_15463;
v_15464:
    goto v_15460;
v_15461:
    goto v_15462;
v_15463:
    v_15693 = Lremprop(nil, v_15694, v_15693);
    goto v_15435;
v_15435:
    v_15693 = nil;
    goto v_15422;
v_15432:
    v_15693 = stack[-5];
    if (!symbolp(v_15693)) v_15693 = nil;
    else { v_15693 = qfastgets(v_15693);
           if (v_15693 != nil) { v_15693 = elt(v_15693, 4); // avalue
#ifdef RECORD_GET
             if (v_15693 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_15693 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_15693 == SPID_NOPROP) v_15693 = nil; }}
#endif
    stack[-6] = v_15693;
    if (v_15693 == nil) goto v_15469;
    goto v_15479;
v_15473:
    v_15695 = stack[-5];
    goto v_15474;
v_15475:
    v_15693 = stack[-6];
    v_15694 = qcar(v_15693);
    goto v_15476;
v_15477:
    v_15693 = stack[0];
    goto v_15478;
v_15479:
    goto v_15473;
v_15474:
    goto v_15475;
v_15476:
    goto v_15477;
v_15478:
    fn = elt(env, 11); // put!-avalue
    v_15693 = (*qfnn(fn))(fn, 3, v_15695, v_15694, v_15693);
    goto v_15430;
v_15469:
    goto v_15493;
v_15487:
    v_15695 = stack[-5];
    goto v_15488;
v_15489:
    v_15694 = elt(env, 4); // scalar
    goto v_15490;
v_15491:
    v_15693 = stack[0];
    goto v_15492;
v_15493:
    goto v_15487;
v_15488:
    goto v_15489;
v_15490:
    goto v_15491;
v_15492:
    fn = elt(env, 11); // put!-avalue
    v_15693 = (*qfnn(fn))(fn, 3, v_15695, v_15694, v_15693);
    goto v_15430;
v_15430:
    v_15693 = stack[0];
    goto v_15422;
v_15427:
    v_15693 = stack[-5];
    v_15693 = qcar(v_15693);
    if (!consp(v_15693)) goto v_15499;
    goto v_15509;
v_15503:
    v_15695 = elt(env, 5); // alg
    goto v_15504;
v_15505:
    v_15694 = (LispObject)400+TAG_FIXNUM; // 25
    goto v_15506;
v_15507:
    v_15693 = elt(env, 6); // "Invalid syntax: improper assignment"
    goto v_15508;
v_15509:
    goto v_15503;
v_15504:
    goto v_15505;
v_15506:
    goto v_15507;
v_15508:
    fn = elt(env, 12); // rerror
    v_15693 = (*qfnn(fn))(fn, 3, v_15695, v_15694, v_15693);
    env = stack[-7];
    goto v_15425;
v_15499:
v_15425:
    goto v_15518;
v_15514:
    v_15693 = stack[-5];
    stack[-3] = qcar(v_15693);
    goto v_15515;
v_15516:
    v_15693 = stack[-5];
    v_15693 = qcdr(v_15693);
    fn = elt(env, 13); // revlis
    v_15693 = (*qfn1(fn))(fn, v_15693);
    env = stack[-7];
    goto v_15517;
v_15518:
    goto v_15514;
v_15515:
    goto v_15516;
v_15517:
    v_15693 = cons(stack[-3], v_15693);
    env = stack[-7];
    stack[-5] = v_15693;
    v_15693 = stack[-1];
    if (v_15693 == nil) goto v_15526;
    else goto v_15527;
v_15526:
    goto v_15533;
v_15529:
    v_15694 = stack[-5];
    goto v_15530;
v_15531:
    v_15693 = qvalue(elt(env, 7)); // wtl!*
    goto v_15532;
v_15533:
    goto v_15529;
v_15530:
    goto v_15531;
v_15532:
    v_15693 = Lassoc(nil, v_15694, v_15693);
    stack[-3] = v_15693;
    v_15693 = stack[-5];
    v_15693 = qcar(v_15693);
    if (!symbolp(v_15693)) v_15693 = nil;
    else { v_15693 = qfastgets(v_15693);
           if (v_15693 != nil) { v_15693 = elt(v_15693, 50); // kvalue
#ifdef RECORD_GET
             if (v_15693 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v_15693 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v_15693 == SPID_NOPROP) v_15693 = nil; }}
#endif
    stack[-4] = v_15693;
    if (v_15693 == nil) goto v_15543;
    else goto v_15544;
v_15543:
    v_15693 = lisp_true;
    goto v_15542;
v_15544:
    goto v_15555;
v_15551:
    v_15694 = stack[-5];
    goto v_15552;
v_15553:
    v_15693 = stack[-4];
    goto v_15554;
v_15555:
    goto v_15551;
v_15552:
    goto v_15553;
v_15554:
    v_15693 = Lassoc(nil, v_15694, v_15693);
    stack[-6] = v_15693;
    v_15693 = (v_15693 == nil ? lisp_true : nil);
    goto v_15542;
    v_15693 = nil;
v_15542:
    if (v_15693 == nil) goto v_15540;
    v_15693 = stack[-3];
    if (v_15693 == nil) goto v_15566;
    else goto v_15567;
v_15566:
    v_15693 = qvalue(elt(env, 8)); // !*sqrtrulep
    v_15693 = (v_15693 == nil ? lisp_true : nil);
    goto v_15565;
v_15567:
    v_15693 = nil;
    goto v_15565;
    v_15693 = nil;
v_15565:
    if (v_15693 == nil) goto v_15563;
    goto v_15585;
v_15575:
    v_15697 = nil;
    goto v_15576;
v_15577:
    v_15696 = stack[-5];
    goto v_15578;
v_15579:
    v_15695 = elt(env, 2); // "not found"
    goto v_15580;
v_15581:
    v_15694 = nil;
    goto v_15582;
v_15583:
    v_15693 = nil;
    goto v_15584;
v_15585:
    goto v_15575;
v_15576:
    goto v_15577;
v_15578:
    goto v_15579;
v_15580:
    goto v_15581;
v_15582:
    goto v_15583;
v_15584:
    fn = elt(env, 10); // msgpri
    v_15693 = (*qfnn(fn))(fn, 5, v_15697, v_15696, v_15695, v_15694, v_15693);
    env = stack[-7];
    goto v_15561;
v_15563:
v_15561:
    goto v_15538;
v_15540:
    goto v_15600;
v_15594:
    v_15693 = stack[-5];
    stack[-1] = qcar(v_15693);
    goto v_15595;
v_15596:
    stack[0] = elt(env, 9); // kvalue
    goto v_15597;
v_15598:
    goto v_15609;
v_15605:
    v_15694 = stack[-6];
    goto v_15606;
v_15607:
    v_15693 = stack[-4];
    goto v_15608;
v_15609:
    goto v_15605;
v_15606:
    goto v_15607;
v_15608:
    v_15693 = Ldelete(nil, v_15694, v_15693);
    env = stack[-7];
    goto v_15599;
v_15600:
    goto v_15594;
v_15595:
    goto v_15596;
v_15597:
    goto v_15598;
v_15599:
    v_15693 = Lputprop(nil, 3, stack[-1], stack[0], v_15693);
    env = stack[-7];
    goto v_15538;
v_15538:
    v_15693 = stack[-3];
    if (v_15693 == nil) goto v_15615;
    goto v_15622;
v_15618:
    v_15694 = stack[-5];
    goto v_15619;
v_15620:
    v_15693 = qvalue(elt(env, 7)); // wtl!*
    goto v_15621;
v_15622:
    goto v_15618;
v_15619:
    goto v_15620;
v_15621:
    fn = elt(env, 14); // delasc
    v_15693 = (*qfn2(fn))(fn, v_15694, v_15693);
    env = stack[-7];
    qvalue(elt(env, 7)) = v_15693; // wtl!*
    goto v_15613;
v_15615:
v_15613:
    v_15693 = nil;
    goto v_15422;
v_15527:
    v_15693 = stack[-5];
    v_15693 = qcar(v_15693);
    if (!symbolp(v_15693)) v_15693 = nil;
    else { v_15693 = qfastgets(v_15693);
           if (v_15693 != nil) { v_15693 = elt(v_15693, 50); // kvalue
#ifdef RECORD_GET
             if (v_15693 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v_15693 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v_15693 == SPID_NOPROP) v_15693 = nil; }}
#endif
    stack[-4] = v_15693;
    if (v_15693 == nil) goto v_15626;
    else goto v_15627;
v_15626:
    goto v_15640;
v_15632:
    v_15693 = stack[-5];
    v_15696 = qcar(v_15693);
    goto v_15633;
v_15634:
    v_15695 = nil;
    goto v_15635;
v_15636:
    v_15694 = stack[-5];
    goto v_15637;
v_15638:
    v_15693 = stack[0];
    goto v_15639;
v_15640:
    goto v_15632;
v_15633:
    goto v_15634;
v_15635:
    goto v_15636;
v_15637:
    goto v_15638;
v_15639:
    fn = elt(env, 15); // put!-kvalue
    v_15693 = (*qfnn(fn))(fn, 4, v_15696, v_15695, v_15694, v_15693);
    goto v_15525;
v_15627:
    goto v_15656;
v_15652:
    v_15694 = stack[-5];
    goto v_15653;
v_15654:
    v_15693 = stack[-4];
    goto v_15655;
v_15656:
    goto v_15652;
v_15653:
    goto v_15654;
v_15655:
    v_15693 = Lassoc(nil, v_15694, v_15693);
    stack[-6] = v_15693;
    if (v_15693 == nil) goto v_15651;
    goto v_15665;
v_15661:
    v_15694 = stack[-5];
    goto v_15662;
v_15663:
    v_15693 = stack[0];
    goto v_15664;
v_15665:
    goto v_15661;
v_15662:
    goto v_15663;
v_15664:
    fn = elt(env, 16); // updoldrules
    v_15693 = (*qfn2(fn))(fn, v_15694, v_15693);
    env = stack[-7];
    goto v_15673;
v_15669:
    v_15693 = stack[-6];
    v_15694 = qcar(v_15693);
    goto v_15670;
v_15671:
    v_15693 = stack[-4];
    goto v_15672;
v_15673:
    goto v_15669;
v_15670:
    goto v_15671;
v_15672:
    fn = elt(env, 14); // delasc
    v_15693 = (*qfn2(fn))(fn, v_15694, v_15693);
    env = stack[-7];
    stack[-4] = v_15693;
    goto v_15649;
v_15651:
v_15649:
    goto v_15686;
v_15678:
    v_15693 = stack[-5];
    v_15696 = qcar(v_15693);
    goto v_15679;
v_15680:
    v_15695 = stack[-4];
    goto v_15681;
v_15682:
    v_15694 = stack[-5];
    goto v_15683;
v_15684:
    v_15693 = stack[0];
    goto v_15685;
v_15686:
    goto v_15678;
v_15679:
    goto v_15680;
v_15681:
    goto v_15682;
v_15683:
    goto v_15684;
v_15685:
    fn = elt(env, 15); // put!-kvalue
    v_15693 = (*qfnn(fn))(fn, 4, v_15696, v_15695, v_15694, v_15693);
    goto v_15525;
v_15525:
    v_15693 = stack[0];
v_15422:
    ;}  // end of a binding scope
    return onevalue(v_15693);
}



// Code for lex_export_codes

static LispObject CC_lex_export_codes(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15422, v_15423;
    LispObject fn;
    argcheck(nargs, 0, "lex_export_codes");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    goto v_15419;
v_15415:
    v_15423 = qvalue(elt(env, 1)); // lex_codename
    goto v_15416;
v_15417:
    v_15422 = elt(env, 2); // ordopcar
    goto v_15418;
v_15419:
    goto v_15415;
v_15416:
    goto v_15417;
v_15418:
    {
        fn = elt(env, 3); // sort
        return (*qfn2(fn))(fn, v_15423, v_15422);
    }
}



// Code for mkfil!*

static LispObject CC_mkfilH(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15455, v_15456;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15413;
// end of prologue
    v_15456 = nil;
    v_15455 = stack[0];
    v_15455 = Lstringp(nil, v_15455);
    env = stack[-1];
    if (v_15455 == nil) goto v_15421;
    v_15455 = stack[0];
    goto v_15419;
v_15421:
    v_15455 = stack[0];
    if (symbolp(v_15455)) goto v_15426;
    goto v_15433;
v_15429:
    v_15456 = stack[0];
    goto v_15430;
v_15431:
    v_15455 = elt(env, 1); // "file name"
    goto v_15432;
v_15433:
    goto v_15429;
v_15430:
    goto v_15431;
v_15432:
    {
        fn = elt(env, 2); // typerr
        return (*qfn2(fn))(fn, v_15456, v_15455);
    }
v_15426:
    v_15455 = stack[0];
    if (!symbolp(v_15455)) v_15455 = nil;
    else { v_15455 = qfastgets(v_15455);
           if (v_15455 != nil) { v_15455 = elt(v_15455, 17); // share
#ifdef RECORD_GET
             if (v_15455 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v_15455 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v_15455 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v_15455 == SPID_NOPROP) v_15455 = nil; else v_15455 = lisp_true; }}
#endif
    if (v_15455 == nil) goto v_15441;
    v_15455 = stack[0];
    fn = elt(env, 3); // eval
    v_15455 = (*qfn1(fn))(fn, v_15455);
    env = stack[-1];
    v_15456 = v_15455;
    v_15455 = Lstringp(nil, v_15455);
    env = stack[-1];
    goto v_15439;
v_15441:
    v_15455 = nil;
    goto v_15439;
    v_15455 = nil;
v_15439:
    if (v_15455 == nil) goto v_15437;
    v_15455 = v_15456;
    goto v_15419;
v_15437:
    v_15455 = stack[0];
    {
        fn = elt(env, 4); // string!-downcase
        return (*qfn1(fn))(fn, v_15455);
    }
    v_15455 = nil;
v_15419:
    return onevalue(v_15455);
}



// Code for prepreform1

static LispObject CC_prepreform1(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15611, v_15612;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15413,v_15414);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_15414;
    stack[0] = v_15413;
// end of prologue
v_15412:
    v_15611 = stack[0];
    if (!consp(v_15611)) goto v_15422;
    else goto v_15423;
v_15422:
    v_15611 = lisp_true;
    goto v_15421;
v_15423:
    v_15611 = stack[0];
    v_15611 = qcar(v_15611);
    if (!symbolp(v_15611)) v_15611 = nil;
    else { v_15611 = qfastgets(v_15611);
           if (v_15611 != nil) { v_15611 = elt(v_15611, 8); // dname
#ifdef RECORD_GET
             if (v_15611 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_15611 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_15611 == SPID_NOPROP) v_15611 = nil; }}
#endif
    goto v_15421;
    v_15611 = nil;
v_15421:
    if (v_15611 == nil) goto v_15419;
    v_15611 = stack[0];
    goto v_15417;
v_15419:
    stack[-6] = nil;
    v_15611 = stack[-5];
    stack[-1] = v_15611;
v_15441:
    v_15611 = stack[-6];
    if (v_15611 == nil) goto v_15448;
    else goto v_15449;
v_15448:
    v_15611 = stack[-1];
    goto v_15447;
v_15449:
    v_15611 = nil;
    goto v_15447;
    v_15611 = nil;
v_15447:
    if (v_15611 == nil) goto v_15444;
    else goto v_15445;
v_15444:
    goto v_15440;
v_15445:
    goto v_15465;
v_15461:
    v_15611 = stack[-1];
    v_15612 = qcar(v_15611);
    goto v_15462;
v_15463:
    v_15611 = stack[0];
    v_15611 = qcdr(v_15611);
    goto v_15464;
v_15465:
    goto v_15461;
v_15462:
    goto v_15463;
v_15464:
    v_15611 = Lsmemq(nil, v_15612, v_15611);
    env = stack[-7];
    if (v_15611 == nil) goto v_15459;
    v_15611 = lisp_true;
    stack[-6] = v_15611;
    goto v_15457;
v_15459:
    v_15611 = stack[-1];
    v_15611 = qcdr(v_15611);
    stack[-1] = v_15611;
    goto v_15457;
v_15457:
    goto v_15441;
v_15440:
    v_15611 = stack[-6];
    if (v_15611 == nil) goto v_15477;
    else goto v_15478;
v_15477:
    v_15611 = stack[0];
    goto v_15437;
v_15478:
    goto v_15490;
v_15486:
    v_15611 = stack[0];
    v_15612 = qcar(v_15611);
    goto v_15487;
v_15488:
    v_15611 = elt(env, 1); // (plus difference minus times quotient)
    goto v_15489;
v_15490:
    goto v_15486;
v_15487:
    goto v_15488;
v_15489:
    v_15611 = Lmemq(nil, v_15612, v_15611);
    if (v_15611 == nil) goto v_15485;
    else goto v_15483;
v_15485:
    v_15611 = stack[0];
    v_15611 = qcar(v_15611);
    if (!symbolp(v_15611)) v_15611 = nil;
    else { v_15611 = qfastgets(v_15611);
           if (v_15611 != nil) { v_15611 = elt(v_15611, 22); // simpfn
#ifdef RECORD_GET
             if (v_15611 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v_15611 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v_15611 == SPID_NOPROP) v_15611 = nil; }}
#endif
    if (v_15611 == nil) goto v_15483;
    goto v_15484;
v_15483:
    v_15611 = nil;
    stack[-6] = v_15611;
    goto v_15482;
v_15484:
v_15482:
    goto v_15508;
v_15504:
    v_15611 = stack[0];
    v_15612 = qcar(v_15611);
    goto v_15505;
v_15506:
    v_15611 = elt(env, 2); // !*sq
    goto v_15507;
v_15508:
    goto v_15504;
v_15505:
    goto v_15506;
v_15507:
    if (v_15612 == v_15611) goto v_15502;
    else goto v_15503;
v_15502:
    goto v_15517;
v_15513:
    v_15611 = stack[0];
    v_15611 = qcdr(v_15611);
    v_15611 = qcar(v_15611);
    fn = elt(env, 3); // sqhorner!*
    v_15611 = (*qfn1(fn))(fn, v_15611);
    env = stack[-7];
    fn = elt(env, 4); // prepsq!*
    v_15612 = (*qfn1(fn))(fn, v_15611);
    env = stack[-7];
    goto v_15514;
v_15515:
    v_15611 = stack[-5];
    goto v_15516;
v_15517:
    goto v_15513;
v_15514:
    goto v_15515;
v_15516:
    stack[0] = v_15612;
    stack[-5] = v_15611;
    goto v_15412;
v_15503:
    goto v_15531;
v_15527:
    v_15611 = stack[0];
    stack[-4] = qcar(v_15611);
    goto v_15528;
v_15529:
    v_15611 = stack[0];
    v_15611 = qcdr(v_15611);
    stack[-3] = v_15611;
    v_15611 = stack[-3];
    if (v_15611 == nil) goto v_15544;
    else goto v_15545;
v_15544:
    v_15611 = nil;
    goto v_15538;
v_15545:
    v_15611 = stack[-3];
    v_15611 = qcar(v_15611);
    v_15612 = v_15611;
    goto v_15557;
v_15553:
    v_15611 = stack[-6];
    if (v_15611 == nil) goto v_15561;
    v_15611 = v_15612;
    fn = elt(env, 5); // simp!*
    v_15611 = (*qfn1(fn))(fn, v_15611);
    env = stack[-7];
    fn = elt(env, 3); // sqhorner!*
    v_15611 = (*qfn1(fn))(fn, v_15611);
    env = stack[-7];
    fn = elt(env, 4); // prepsq!*
    v_15611 = (*qfn1(fn))(fn, v_15611);
    env = stack[-7];
    v_15612 = v_15611;
    goto v_15559;
v_15561:
    v_15611 = v_15612;
    v_15612 = v_15611;
    goto v_15559;
    v_15612 = nil;
v_15559:
    goto v_15554;
v_15555:
    v_15611 = stack[-5];
    goto v_15556;
v_15557:
    goto v_15553;
v_15554:
    goto v_15555;
v_15556:
    v_15611 = CC_prepreform1(elt(env, 0), v_15612, v_15611);
    env = stack[-7];
    v_15611 = ncons(v_15611);
    env = stack[-7];
    stack[-1] = v_15611;
    stack[-2] = v_15611;
v_15539:
    v_15611 = stack[-3];
    v_15611 = qcdr(v_15611);
    stack[-3] = v_15611;
    v_15611 = stack[-3];
    if (v_15611 == nil) goto v_15575;
    else goto v_15576;
v_15575:
    v_15611 = stack[-2];
    goto v_15538;
v_15576:
    goto v_15584;
v_15580:
    stack[0] = stack[-1];
    goto v_15581;
v_15582:
    v_15611 = stack[-3];
    v_15611 = qcar(v_15611);
    v_15612 = v_15611;
    goto v_15595;
v_15591:
    v_15611 = stack[-6];
    if (v_15611 == nil) goto v_15599;
    v_15611 = v_15612;
    fn = elt(env, 5); // simp!*
    v_15611 = (*qfn1(fn))(fn, v_15611);
    env = stack[-7];
    fn = elt(env, 3); // sqhorner!*
    v_15611 = (*qfn1(fn))(fn, v_15611);
    env = stack[-7];
    fn = elt(env, 4); // prepsq!*
    v_15611 = (*qfn1(fn))(fn, v_15611);
    env = stack[-7];
    v_15612 = v_15611;
    goto v_15597;
v_15599:
    v_15611 = v_15612;
    v_15612 = v_15611;
    goto v_15597;
    v_15612 = nil;
v_15597:
    goto v_15592;
v_15593:
    v_15611 = stack[-5];
    goto v_15594;
v_15595:
    goto v_15591;
v_15592:
    goto v_15593;
v_15594:
    v_15611 = CC_prepreform1(elt(env, 0), v_15612, v_15611);
    env = stack[-7];
    v_15611 = ncons(v_15611);
    env = stack[-7];
    goto v_15583;
v_15584:
    goto v_15580;
v_15581:
    goto v_15582;
v_15583:
    v_15611 = Lrplacd(nil, stack[0], v_15611);
    env = stack[-7];
    v_15611 = stack[-1];
    v_15611 = qcdr(v_15611);
    stack[-1] = v_15611;
    goto v_15539;
v_15538:
    goto v_15530;
v_15531:
    goto v_15527;
v_15528:
    goto v_15529;
v_15530:
    {
        LispObject v_15620 = stack[-4];
        return cons(v_15620, v_15611);
    }
    v_15611 = nil;
v_15437:
    goto v_15417;
    v_15611 = nil;
v_15417:
    return onevalue(v_15611);
}



// Code for aex_mvar

static LispObject CC_aex_mvar(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15424;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15424 = v_15413;
// end of prologue
    goto v_15418;
    goto v_15416;
v_15418:
v_15416:
    fn = elt(env, 1); // aex_ex
    v_15424 = (*qfn1(fn))(fn, v_15424);
    env = stack[0];
    v_15424 = qcar(v_15424);
    {
        fn = elt(env, 2); // sfto_mvarx
        return (*qfn1(fn))(fn, v_15424);
    }
}



// Code for ombindir

static LispObject CC_ombindir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15445;
    LispObject fn;
    argcheck(nargs, 0, "ombindir");
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
    fn = elt(env, 2); // lex
    v_15445 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    fn = elt(env, 3); // omobj
    v_15445 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-1] = v_15445;
    fn = elt(env, 2); // lex
    v_15445 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    fn = elt(env, 4); // variablesir
    v_15445 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    fn = elt(env, 5); // tobvarir
    v_15445 = (*qfn1(fn))(fn, v_15445);
    env = stack[-3];
    stack[0] = v_15445;
    fn = elt(env, 2); // lex
    v_15445 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    fn = elt(env, 3); // omobj
    v_15445 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-2] = v_15445;
    fn = elt(env, 2); // lex
    v_15445 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    v_15445 = elt(env, 1); // (!/ o m b i n d)
    fn = elt(env, 6); // checktag
    v_15445 = (*qfn1(fn))(fn, v_15445);
    env = stack[-3];
    goto v_15434;
v_15430:
    goto v_15431;
v_15432:
    goto v_15441;
v_15437:
    goto v_15438;
v_15439:
    v_15445 = stack[-2];
    v_15445 = ncons(v_15445);
    env = stack[-3];
    goto v_15440;
v_15441:
    goto v_15437;
v_15438:
    goto v_15439;
v_15440:
    v_15445 = Lappend(nil, stack[0], v_15445);
    goto v_15433;
v_15434:
    goto v_15430;
v_15431:
    goto v_15432;
v_15433:
    {
        LispObject v_15449 = stack[-1];
        return Lappend(nil, v_15449, v_15445);
    }
    return onevalue(v_15445);
}



// Code for simpdf!*

static LispObject CC_simpdfH(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15439, v_15440, v_15441;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_15439 = v_15413;
// end of prologue
    fn = elt(env, 1); // simpdf
    v_15439 = (*qfn1(fn))(fn, v_15439);
    env = stack[-1];
    stack[0] = v_15439;
    v_15439 = stack[0];
    fn = elt(env, 2); // rootextractsq
    v_15439 = (*qfn1(fn))(fn, v_15439);
    env = stack[-1];
    v_15441 = v_15439;
    goto v_15431;
v_15427:
    v_15440 = v_15441;
    goto v_15428;
v_15429:
    v_15439 = stack[0];
    goto v_15430;
v_15431:
    goto v_15427;
v_15428:
    goto v_15429;
v_15430:
    if (equal(v_15440, v_15439)) goto v_15426;
    v_15439 = v_15441;
    {
        fn = elt(env, 3); // resimp
        return (*qfn1(fn))(fn, v_15439);
    }
v_15426:
    v_15439 = stack[0];
    goto v_15418;
    v_15439 = nil;
v_15418:
    return onevalue(v_15439);
}



// Code for nextcomb

static LispObject CC_nextcomb(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15560, v_15561;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15413,v_15414);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15414;
    v_15561 = v_15413;
// end of prologue
// Binding i
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-4, 1, -2);
    qvalue(elt(env, 1)) = nil; // i
    v_15560 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_15560; // i
    v_15560 = v_15561;
    v_15560 = qcar(v_15560);
    stack[-3] = v_15560;
    v_15560 = v_15561;
    v_15560 = qcdr(v_15560);
    stack[-1] = v_15560;
    goto v_15435;
v_15431:
    v_15561 = stack[0];
    goto v_15432;
v_15433:
    v_15560 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15434;
v_15435:
    goto v_15431;
v_15432:
    goto v_15433;
v_15434:
    if (v_15561 == v_15560) goto v_15429;
    else goto v_15430;
v_15429:
    v_15560 = nil;
    v_15560 = ncons(v_15560);
    goto v_15428;
v_15430:
    goto v_15447;
v_15443:
    goto v_15453;
v_15449:
    v_15560 = stack[-3];
    v_15561 = Llength(nil, v_15560);
    env = stack[-4];
    goto v_15450;
v_15451:
    v_15560 = stack[0];
    goto v_15452;
v_15453:
    goto v_15449;
v_15450:
    goto v_15451;
v_15452:
    v_15561 = difference2(v_15561, v_15560);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_15561; // i
    goto v_15444;
v_15445:
    v_15560 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15446;
v_15447:
    goto v_15443;
v_15444:
    goto v_15445;
v_15446:
    v_15560 = (LispObject)lessp2(v_15561, v_15560);
    v_15560 = v_15560 ? lisp_true : nil;
    env = stack[-4];
    if (v_15560 == nil) goto v_15441;
    v_15560 = nil;
    v_15560 = ncons(v_15560);
    goto v_15428;
v_15441:
    goto v_15466;
v_15462:
    v_15561 = qvalue(elt(env, 1)); // i
    goto v_15463;
v_15464:
    v_15560 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15465;
v_15466:
    goto v_15462;
v_15463:
    goto v_15464;
v_15465:
    if (v_15561 == v_15560) goto v_15460;
    else goto v_15461;
v_15460:
    v_15560 = stack[-3];
    v_15560 = ncons(v_15560);
    goto v_15428;
v_15461:
    v_15560 = stack[-1];
    if (v_15560 == nil) goto v_15472;
    goto v_15479;
v_15475:
    goto v_15476;
v_15477:
    v_15560 = stack[0];
    v_15560 = sub1(v_15560);
    env = stack[-4];
    goto v_15478;
v_15479:
    goto v_15475;
v_15476:
    goto v_15477;
v_15478:
    v_15560 = CC_nextcomb(elt(env, 0), stack[-1], v_15560);
    env = stack[-4];
    goto v_15490;
v_15484:
    v_15561 = stack[-3];
    stack[-1] = qcar(v_15561);
    goto v_15485;
v_15486:
    v_15561 = v_15560;
    stack[0] = qcar(v_15561);
    goto v_15487;
v_15488:
    v_15561 = v_15560;
    v_15561 = qcdr(v_15561);
    if (v_15561 == nil) goto v_15498;
    goto v_15506;
v_15502:
    v_15561 = stack[-3];
    goto v_15503;
v_15504:
    v_15560 = qcdr(v_15560);
    goto v_15505;
v_15506:
    goto v_15502;
v_15503:
    goto v_15504;
v_15505:
    v_15560 = cons(v_15561, v_15560);
    env = stack[-4];
    goto v_15496;
v_15498:
    v_15560 = stack[-3];
    v_15560 = qcdr(v_15560);
    v_15560 = ncons(v_15560);
    env = stack[-4];
    goto v_15496;
    v_15560 = nil;
v_15496:
    goto v_15489;
v_15490:
    goto v_15484;
v_15485:
    goto v_15486;
v_15487:
    goto v_15488;
v_15489:
    v_15560 = acons(stack[-1], stack[0], v_15560);
    goto v_15428;
v_15472:
    goto v_15522;
v_15518:
    v_15560 = stack[-3];
    v_15560 = qcdr(v_15560);
    fn = elt(env, 2); // initcomb
    stack[-1] = (*qfn1(fn))(fn, v_15560);
    env = stack[-4];
    goto v_15519;
v_15520:
    v_15560 = stack[0];
    v_15560 = sub1(v_15560);
    env = stack[-4];
    goto v_15521;
v_15522:
    goto v_15518;
v_15519:
    goto v_15520;
v_15521:
    v_15560 = CC_nextcomb(elt(env, 0), stack[-1], v_15560);
    env = stack[-4];
    goto v_15535;
v_15529:
    v_15561 = stack[-3];
    stack[-1] = qcar(v_15561);
    goto v_15530;
v_15531:
    v_15561 = v_15560;
    stack[0] = qcar(v_15561);
    goto v_15532;
v_15533:
    v_15561 = v_15560;
    v_15561 = qcdr(v_15561);
    if (v_15561 == nil) goto v_15543;
    goto v_15551;
v_15547:
    v_15561 = stack[-3];
    goto v_15548;
v_15549:
    v_15560 = qcdr(v_15560);
    goto v_15550;
v_15551:
    goto v_15547;
v_15548:
    goto v_15549;
v_15550:
    v_15560 = cons(v_15561, v_15560);
    env = stack[-4];
    goto v_15541;
v_15543:
    v_15560 = stack[-3];
    v_15560 = qcdr(v_15560);
    v_15560 = ncons(v_15560);
    env = stack[-4];
    goto v_15541;
    v_15560 = nil;
v_15541:
    goto v_15534;
v_15535:
    goto v_15529;
v_15530:
    goto v_15531;
v_15532:
    goto v_15533;
v_15534:
    v_15560 = acons(stack[-1], stack[0], v_15560);
    goto v_15428;
    v_15560 = nil;
v_15428:
    ;}  // end of a binding scope
    return onevalue(v_15560);
}



// Code for dip!-nc!-ev!-prod1

static LispObject CC_dipKncKevKprod1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15449, v_15450, v_15451, v_15452;
    LispObject fn;
    LispObject v_15415, v_15414, v_15413;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dip-nc-ev-prod1");
    va_start(aa, nargs);
    v_15413 = va_arg(aa, LispObject);
    v_15414 = va_arg(aa, LispObject);
    v_15415 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15415,v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15413,v_15414,v_15415);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_15450 = v_15415;
    v_15451 = v_15414;
    v_15452 = v_15413;
// end of prologue
    v_15449 = v_15452;
    if (v_15449 == nil) goto v_15419;
    else goto v_15420;
v_15419:
    v_15449 = v_15450;
    goto v_15418;
v_15420:
    goto v_15432;
v_15426:
    v_15449 = v_15452;
    stack[-1] = qcar(v_15449);
    goto v_15427;
v_15428:
    stack[0] = v_15451;
    goto v_15429;
v_15430:
    goto v_15443;
v_15437:
    v_15449 = v_15452;
    v_15449 = qcdr(v_15449);
    goto v_15438;
v_15439:
    v_15451 = (LispObject)((intptr_t)(v_15451) + 0x10);
    goto v_15440;
v_15441:
    goto v_15442;
v_15443:
    goto v_15437;
v_15438:
    goto v_15439;
v_15440:
    goto v_15441;
v_15442:
    v_15449 = CC_dipKncKevKprod1(elt(env, 0), 3, v_15449, v_15451, v_15450);
    env = stack[-2];
    goto v_15431;
v_15432:
    goto v_15426;
v_15427:
    goto v_15428;
v_15429:
    goto v_15430;
v_15431:
    {
        LispObject v_15455 = stack[-1];
        LispObject v_15456 = stack[0];
        fn = elt(env, 1); // dip!-nc!-ev!-prod2
        return (*qfnn(fn))(fn, 3, v_15455, v_15456, v_15449);
    }
    v_15449 = nil;
v_15418:
    return onevalue(v_15449);
}



// Code for pterpri

static LispObject CC_pterpri(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15478, v_15479, v_15480;
    LispObject fn;
    argcheck(nargs, 0, "pterpri");
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
    v_15478 = nil;
    v_15478 = Lwrs(nil, v_15478);
    env = stack[-4];
    stack[-3] = v_15478;
    v_15478 = qvalue(elt(env, 1)); // !*pprinbuf!*
    v_15478 = Lnreverse(nil, v_15478);
    env = stack[-4];
    stack[-2] = v_15478;
    v_15478 = qvalue(elt(env, 2)); // !*outchanl!*
    stack[-1] = v_15478;
v_15425:
    v_15478 = stack[-1];
    if (v_15478 == nil) goto v_15429;
    else goto v_15430;
v_15429:
    goto v_15424;
v_15430:
    v_15478 = stack[-1];
    v_15478 = qcar(v_15478);
    v_15478 = Lwrs(nil, v_15478);
    env = stack[-4];
    v_15478 = stack[-2];
    stack[0] = v_15478;
v_15441:
    v_15478 = stack[0];
    if (v_15478 == nil) goto v_15445;
    else goto v_15446;
v_15445:
    goto v_15440;
v_15446:
    v_15478 = stack[0];
    v_15478 = qcar(v_15478);
    v_15480 = v_15478;
    goto v_15460;
v_15456:
    v_15479 = qvalue(elt(env, 3)); // gentranlang!*
    goto v_15457;
v_15458:
    v_15478 = elt(env, 4); // fortran
    goto v_15459;
v_15460:
    goto v_15456;
v_15457:
    goto v_15458;
v_15459:
    if (v_15479 == v_15478) goto v_15454;
    else goto v_15455;
v_15454:
    v_15478 = v_15480;
    fn = elt(env, 6); // fprin2
    v_15478 = (*qfn1(fn))(fn, v_15478);
    env = stack[-4];
    goto v_15453;
v_15455:
    v_15478 = v_15480;
    v_15478 = Lprinc(nil, v_15478);
    env = stack[-4];
    goto v_15453;
v_15453:
    v_15478 = stack[0];
    v_15478 = qcdr(v_15478);
    stack[0] = v_15478;
    goto v_15441;
v_15440:
    v_15478 = Lterpri(nil, 0);
    env = stack[-4];
    v_15478 = stack[-1];
    v_15478 = qcdr(v_15478);
    stack[-1] = v_15478;
    goto v_15425;
v_15424:
    v_15478 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 5)) = v_15478; // !*posn!*
    v_15478 = nil;
    qvalue(elt(env, 1)) = v_15478; // !*pprinbuf!*
    v_15478 = stack[-3];
    v_15478 = Lwrs(nil, v_15478);
    v_15478 = nil;
    return onevalue(v_15478);
}



// Code for getphystypeor

static LispObject CC_getphystypeor(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15432;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15413;
// end of prologue
v_15412:
    v_15432 = stack[0];
    if (!consp(v_15432)) goto v_15418;
    v_15432 = stack[0];
    v_15432 = qcar(v_15432);
    fn = elt(env, 1); // getphystype
    v_15432 = (*qfn1(fn))(fn, v_15432);
    env = stack[-1];
    if (v_15432 == nil) goto v_15422;
    else goto v_15421;
v_15422:
    v_15432 = stack[0];
    v_15432 = qcdr(v_15432);
    stack[0] = v_15432;
    goto v_15412;
v_15421:
    goto v_15416;
v_15418:
    v_15432 = nil;
    goto v_15416;
    v_15432 = nil;
v_15416:
    return onevalue(v_15432);
}



// Code for prop!-simp

static LispObject CC_propKsimp(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15433, v_15434, v_15435, v_15436, v_15437;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15433 = v_15414;
    v_15434 = v_15413;
// end of prologue
    goto v_15427;
v_15417:
    v_15437 = v_15434;
    goto v_15418;
v_15419:
    v_15436 = v_15433;
    goto v_15420;
v_15421:
    v_15435 = nil;
    goto v_15422;
v_15423:
    v_15434 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15424;
v_15425:
    v_15433 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15426;
v_15427:
    goto v_15417;
v_15418:
    goto v_15419;
v_15420:
    goto v_15421;
v_15422:
    goto v_15423;
v_15424:
    goto v_15425;
v_15426:
    {
        fn = elt(env, 1); // prop!-simp1
        return (*qfnn(fn))(fn, 5, v_15437, v_15436, v_15435, v_15434, v_15433);
    }
}



// Code for nzero

static LispObject CC_nzero(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15444, v_15445;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15413;
// end of prologue
    stack[-1] = nil;
v_15418:
    goto v_15427;
v_15423:
    v_15445 = stack[0];
    goto v_15424;
v_15425:
    v_15444 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15426;
v_15427:
    goto v_15423;
v_15424:
    goto v_15425;
v_15426:
    if (v_15445 == v_15444) goto v_15421;
    else goto v_15422;
v_15421:
    v_15444 = stack[-1];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_15444);
    }
v_15422:
    goto v_15439;
v_15435:
    v_15445 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15436;
v_15437:
    v_15444 = stack[-1];
    goto v_15438;
v_15439:
    goto v_15435;
v_15436:
    goto v_15437;
v_15438:
    v_15444 = cons(v_15445, v_15444);
    env = stack[-2];
    stack[-1] = v_15444;
    v_15444 = stack[0];
    v_15444 = sub1(v_15444);
    env = stack[-2];
    stack[0] = v_15444;
    goto v_15418;
    v_15444 = nil;
    return onevalue(v_15444);
}



// Code for general!-evaluate!-mod!-p

static LispObject CC_generalKevaluateKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15536, v_15537, v_15538, v_15539, v_15540;
    LispObject fn;
    LispObject v_15415, v_15414, v_15413;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "general-evaluate-mod-p");
    va_start(aa, nargs);
    v_15413 = va_arg(aa, LispObject);
    v_15414 = va_arg(aa, LispObject);
    v_15415 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15415,v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15413,v_15414,v_15415);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15415;
    stack[-1] = v_15414;
    stack[-2] = v_15413;
// end of prologue
v_15419:
    v_15536 = stack[-2];
    if (!consp(v_15536)) goto v_15426;
    else goto v_15427;
v_15426:
    v_15536 = lisp_true;
    goto v_15425;
v_15427:
    v_15536 = stack[-2];
    v_15536 = qcar(v_15536);
    v_15536 = (consp(v_15536) ? nil : lisp_true);
    goto v_15425;
    v_15536 = nil;
v_15425:
    if (v_15536 == nil) goto v_15423;
    v_15536 = stack[-2];
    goto v_15418;
v_15423:
    goto v_15442;
v_15438:
    v_15537 = stack[0];
    goto v_15439;
v_15440:
    v_15536 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15441;
v_15442:
    goto v_15438;
v_15439:
    goto v_15440;
v_15441:
    if (v_15537 == v_15536) goto v_15436;
    else goto v_15437;
v_15436:
    v_15536 = nil;
    stack[0] = v_15536;
    goto v_15419;
v_15437:
    v_15536 = stack[-1];
    if (v_15536 == nil) goto v_15446;
    else goto v_15447;
v_15446:
    v_15536 = elt(env, 1); // "Variable=NIL in GENERAL-EVALUATE-MOD-P"
    {
        fn = elt(env, 2); // errorf
        return (*qfn1(fn))(fn, v_15536);
    }
v_15447:
    goto v_15457;
v_15453:
    v_15536 = stack[-2];
    v_15536 = qcar(v_15536);
    v_15536 = qcar(v_15536);
    v_15537 = qcar(v_15536);
    goto v_15454;
v_15455:
    v_15536 = stack[-1];
    goto v_15456;
v_15457:
    goto v_15453;
v_15454:
    goto v_15455;
v_15456:
    if (equal(v_15537, v_15536)) goto v_15451;
    else goto v_15452;
v_15451:
    goto v_15474;
v_15464:
    v_15536 = stack[-2];
    v_15536 = qcar(v_15536);
    v_15540 = qcdr(v_15536);
    goto v_15465;
v_15466:
    v_15536 = stack[-2];
    v_15536 = qcar(v_15536);
    v_15536 = qcar(v_15536);
    v_15539 = qcdr(v_15536);
    goto v_15467;
v_15468:
    v_15536 = stack[-2];
    v_15538 = qcdr(v_15536);
    goto v_15469;
v_15470:
    v_15537 = stack[0];
    goto v_15471;
v_15472:
    v_15536 = stack[-1];
    goto v_15473;
v_15474:
    goto v_15464;
v_15465:
    goto v_15466;
v_15467:
    goto v_15468;
v_15469:
    goto v_15470;
v_15471:
    goto v_15472;
v_15473:
    {
        fn = elt(env, 3); // general!-horner!-rule!-mod!-p
        return (*qfnn(fn))(fn, 5, v_15540, v_15539, v_15538, v_15537, v_15536);
    }
v_15452:
    goto v_15495;
v_15489:
    v_15536 = stack[-2];
    v_15536 = qcar(v_15536);
    v_15538 = qcdr(v_15536);
    goto v_15490;
v_15491:
    v_15537 = stack[-1];
    goto v_15492;
v_15493:
    v_15536 = stack[0];
    goto v_15494;
v_15495:
    goto v_15489;
v_15490:
    goto v_15491;
v_15492:
    goto v_15493;
v_15494:
    stack[-3] = CC_generalKevaluateKmodKp(elt(env, 0), 3, v_15538, v_15537, v_15536);
    env = stack[-4];
    goto v_15508;
v_15502:
    v_15536 = stack[-2];
    v_15538 = qcdr(v_15536);
    goto v_15503;
v_15504:
    v_15537 = stack[-1];
    goto v_15505;
v_15506:
    v_15536 = stack[0];
    goto v_15507;
v_15508:
    goto v_15502;
v_15503:
    goto v_15504;
v_15505:
    goto v_15506;
v_15507:
    v_15536 = CC_generalKevaluateKmodKp(elt(env, 0), 3, v_15538, v_15537, v_15536);
    v_15537 = stack[-3];
    v_15538 = v_15537;
    if (v_15538 == nil) goto v_15517;
    else goto v_15518;
v_15517:
    goto v_15516;
v_15518:
    goto v_15530;
v_15524:
    v_15538 = stack[-2];
    v_15538 = qcar(v_15538);
    v_15538 = qcar(v_15538);
    goto v_15525;
v_15526:
    goto v_15527;
v_15528:
    goto v_15529;
v_15530:
    goto v_15524;
v_15525:
    goto v_15526;
v_15527:
    goto v_15528;
v_15529:
    return acons(v_15538, v_15537, v_15536);
    v_15536 = nil;
v_15516:
    goto v_15418;
    v_15536 = nil;
v_15418:
    return onevalue(v_15536);
}



// Code for lalr_generate_collection

static LispObject CC_lalr_generate_collection(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15496, v_15497;
    LispObject fn;
    argcheck(nargs, 0, "lalr_generate_collection");
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
    v_15496 = qvalue(elt(env, 1)); // itemset_collection
    stack[-1] = v_15496;
v_15421:
    v_15496 = stack[-1];
    if (v_15496 == nil) goto v_15425;
    else goto v_15426;
v_15425:
    goto v_15420;
v_15426:
    v_15496 = stack[-1];
    v_15496 = qcar(v_15496);
    goto v_15437;
v_15433:
    stack[0] = v_15496;
    goto v_15434;
v_15435:
    v_15496 = qcar(v_15496);
    fn = elt(env, 3); // lalr_lr0_itemset_to_lalr_kernel
    v_15496 = (*qfn1(fn))(fn, v_15496);
    env = stack[-2];
    goto v_15436;
v_15437:
    goto v_15433;
v_15434:
    goto v_15435;
v_15436:
    v_15496 = Lrplaca(nil, stack[0], v_15496);
    env = stack[-2];
    v_15496 = stack[-1];
    v_15496 = qcdr(v_15496);
    stack[-1] = v_15496;
    goto v_15421;
v_15420:
    fn = elt(env, 4); // lalr_analyze_lookaheads
    v_15496 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[0] = v_15496;
    goto v_15450;
v_15446:
    v_15497 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15447;
v_15448:
    v_15496 = qvalue(elt(env, 1)); // itemset_collection
    goto v_15449;
v_15450:
    goto v_15446;
v_15447:
    goto v_15448;
v_15449:
    fn = elt(env, 5); // carrassoc
    v_15496 = (*qfn2(fn))(fn, v_15497, v_15496);
    env = stack[-2];
    goto v_15458;
v_15454:
    v_15497 = qcar(v_15496);
    goto v_15455;
v_15456:
    v_15496 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15457;
v_15458:
    goto v_15454;
v_15455:
    goto v_15456;
v_15457:
    fn = elt(env, 6); // lalr_add_lookahead
    v_15496 = (*qfn2(fn))(fn, v_15497, v_15496);
    env = stack[-2];
    v_15496 = stack[0];
    fn = elt(env, 7); // lalr_propagate_lookaheads
    v_15496 = (*qfn1(fn))(fn, v_15496);
    env = stack[-2];
    v_15496 = qvalue(elt(env, 1)); // itemset_collection
    stack[-1] = v_15496;
v_15467:
    v_15496 = stack[-1];
    if (v_15496 == nil) goto v_15471;
    else goto v_15472;
v_15471:
    goto v_15466;
v_15472:
    v_15496 = stack[-1];
    v_15496 = qcar(v_15496);
    goto v_15483;
v_15479:
    stack[0] = v_15496;
    goto v_15480;
v_15481:
    v_15496 = qcar(v_15496);
    fn = elt(env, 8); // lalr_closure
    v_15496 = (*qfn1(fn))(fn, v_15496);
    env = stack[-2];
    goto v_15482;
v_15483:
    goto v_15479;
v_15480:
    goto v_15481;
v_15482:
    v_15496 = Lrplaca(nil, stack[0], v_15496);
    env = stack[-2];
    v_15496 = stack[-1];
    v_15496 = qcdr(v_15496);
    stack[-1] = v_15496;
    goto v_15467;
v_15466:
    v_15496 = qvalue(elt(env, 2)); // !*lalr_verbose
    if (v_15496 == nil) goto v_15493;
    fn = elt(env, 9); // lalr_print_collection
    v_15496 = (*qfnn(fn))(fn, 0);
    goto v_15491;
v_15493:
v_15491:
    v_15496 = nil;
    return onevalue(v_15496);
}



// Code for open

static LispObject CC_open(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15493, v_15494, v_15495, v_15496;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15413,v_15414);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_15495 = v_15414;
    v_15496 = v_15413;
// end of prologue
    goto v_15424;
v_15420:
    v_15494 = v_15495;
    goto v_15421;
v_15422:
    v_15493 = elt(env, 1); // input
    goto v_15423;
v_15424:
    goto v_15420;
v_15421:
    goto v_15422;
v_15423:
    if (v_15494 == v_15493) goto v_15418;
    else goto v_15419;
v_15418:
    goto v_15432;
v_15428:
    v_15494 = v_15496;
    goto v_15429;
v_15430:
    v_15493 = (LispObject)1040+TAG_FIXNUM; // 65
    goto v_15431;
v_15432:
    goto v_15428;
v_15429:
    goto v_15430;
v_15431:
    {
        fn = elt(env, 5); // internal!-open
        return (*qfn2(fn))(fn, v_15494, v_15493);
    }
v_15419:
    goto v_15441;
v_15437:
    v_15494 = v_15495;
    goto v_15438;
v_15439:
    v_15493 = elt(env, 2); // output
    goto v_15440;
v_15441:
    goto v_15437;
v_15438:
    goto v_15439;
v_15440:
    if (v_15494 == v_15493) goto v_15435;
    else goto v_15436;
v_15435:
    goto v_15449;
v_15445:
    stack[0] = v_15496;
    goto v_15446;
v_15447:
    goto v_15456;
v_15452:
    v_15494 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_15453;
v_15454:
    v_15493 = (LispObject)832+TAG_FIXNUM; // 52
    goto v_15455;
v_15456:
    goto v_15452;
v_15453:
    goto v_15454;
v_15455:
    v_15493 = plus2(v_15494, v_15493);
    env = stack[-1];
    goto v_15448;
v_15449:
    goto v_15445;
v_15446:
    goto v_15447;
v_15448:
    {
        LispObject v_15498 = stack[0];
        fn = elt(env, 5); // internal!-open
        return (*qfn2(fn))(fn, v_15498, v_15493);
    }
v_15436:
    goto v_15465;
v_15461:
    v_15494 = v_15495;
    goto v_15462;
v_15463:
    v_15493 = elt(env, 3); // append
    goto v_15464;
v_15465:
    goto v_15461;
v_15462:
    goto v_15463;
v_15464:
    if (v_15494 == v_15493) goto v_15459;
    else goto v_15460;
v_15459:
    goto v_15473;
v_15469:
    stack[0] = v_15496;
    goto v_15470;
v_15471:
    goto v_15480;
v_15476:
    v_15494 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_15477;
v_15478:
    v_15493 = (LispObject)640+TAG_FIXNUM; // 40
    goto v_15479;
v_15480:
    goto v_15476;
v_15477:
    goto v_15478;
v_15479:
    v_15493 = plus2(v_15494, v_15493);
    env = stack[-1];
    goto v_15472;
v_15473:
    goto v_15469;
v_15470:
    goto v_15471;
v_15472:
    {
        LispObject v_15499 = stack[0];
        fn = elt(env, 5); // internal!-open
        return (*qfn2(fn))(fn, v_15499, v_15493);
    }
v_15460:
    goto v_15490;
v_15486:
    v_15493 = elt(env, 4); // "bad direction ~A in open"
    goto v_15487;
v_15488:
    v_15494 = v_15495;
    goto v_15489;
v_15490:
    goto v_15486;
v_15487:
    goto v_15488;
v_15489:
    {
        fn = elt(env, 6); // error
        return (*qfn2(fn))(fn, v_15493, v_15494);
    }
    v_15493 = nil;
    return onevalue(v_15493);
}



// Code for normalform

static LispObject CC_normalform(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15530, v_15531, v_15532;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_15413;
// end of prologue
    v_15530 = nil;
    v_15530 = ncons(v_15530);
    env = stack[-3];
    stack[-2] = v_15530;
    v_15530 = stack[-1];
    v_15530 = qcar(v_15530);
    if (v_15530 == nil) goto v_15423;
    else goto v_15424;
v_15423:
    v_15530 = stack[-2];
    goto v_15418;
v_15424:
    v_15530 = qvalue(elt(env, 1)); // fluidbibasisnormalforms
    v_15530 = (LispObject)((intptr_t)(v_15530) + 0x10);
    qvalue(elt(env, 1)) = v_15530; // fluidbibasisnormalforms
v_15433:
    v_15530 = stack[-1];
    v_15530 = qcar(v_15530);
    if (v_15530 == nil) goto v_15436;
    else goto v_15437;
v_15436:
    goto v_15432;
v_15437:
    v_15530 = stack[-1];
    v_15530 = qcar(v_15530);
    fn = elt(env, 2); // janettreefind
    v_15530 = (*qfn1(fn))(fn, v_15530);
    env = stack[-3];
v_15446:
    v_15531 = v_15530;
    if (v_15531 == nil) goto v_15449;
    else goto v_15450;
v_15449:
    goto v_15445;
v_15450:
    goto v_15458;
v_15454:
    v_15532 = stack[-1];
    goto v_15455;
v_15456:
    goto v_15464;
v_15460:
    v_15531 = v_15530;
    goto v_15461;
v_15462:
    v_15530 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15463;
v_15464:
    goto v_15460;
v_15461:
    goto v_15462;
v_15463:
    v_15530 = *(LispObject *)((char *)v_15531 + (CELL-TAG_VECTOR) + (((intptr_t)v_15530-TAG_FIXNUM)/(16/CELL)));
    goto v_15457;
v_15458:
    goto v_15454;
v_15455:
    goto v_15456;
v_15457:
    fn = elt(env, 3); // polynomheadreduceby
    v_15530 = (*qfn2(fn))(fn, v_15532, v_15530);
    env = stack[-3];
    v_15530 = stack[-1];
    v_15530 = qcar(v_15530);
    if (v_15530 == nil) goto v_15471;
    v_15530 = stack[-1];
    v_15530 = qcar(v_15530);
    fn = elt(env, 2); // janettreefind
    v_15530 = (*qfn1(fn))(fn, v_15530);
    env = stack[-3];
    goto v_15469;
v_15471:
    v_15530 = nil;
    goto v_15469;
v_15469:
    goto v_15446;
v_15445:
    v_15530 = stack[-1];
    v_15530 = qcar(v_15530);
    if (v_15530 == nil) goto v_15486;
    goto v_15494;
v_15490:
    stack[0] = stack[-2];
    goto v_15491;
v_15492:
    goto v_15503;
v_15497:
    v_15530 = stack[-1];
    v_15532 = qcar(v_15530);
    goto v_15498;
v_15499:
    v_15531 = nil;
    goto v_15500;
v_15501:
    v_15530 = nil;
    goto v_15502;
v_15503:
    goto v_15497;
v_15498:
    goto v_15499;
v_15500:
    goto v_15501;
v_15502:
    v_15530 = list2star(v_15532, v_15531, v_15530);
    env = stack[-3];
    goto v_15493;
v_15494:
    goto v_15490;
v_15491:
    goto v_15492;
v_15493:
    fn = elt(env, 4); // polynomadd
    v_15530 = (*qfn2(fn))(fn, stack[0], v_15530);
    env = stack[-3];
    goto v_15513;
v_15509:
    goto v_15519;
v_15515:
    v_15531 = stack[-1];
    goto v_15516;
v_15517:
    v_15530 = stack[-1];
    v_15530 = qcdr(v_15530);
    v_15530 = qcar(v_15530);
    goto v_15518;
v_15519:
    goto v_15515;
v_15516:
    goto v_15517;
v_15518:
    v_15531 = Lrplaca(nil, v_15531, v_15530);
    env = stack[-3];
    goto v_15510;
v_15511:
    v_15530 = stack[-1];
    v_15530 = qcdr(v_15530);
    v_15530 = qcdr(v_15530);
    goto v_15512;
v_15513:
    goto v_15509;
v_15510:
    goto v_15511;
v_15512:
    v_15530 = Lrplacd(nil, v_15531, v_15530);
    env = stack[-3];
    goto v_15484;
v_15486:
v_15484:
    goto v_15433;
v_15432:
    v_15530 = stack[-2];
v_15418:
    return onevalue(v_15530);
}



// Code for wureducedp

static LispObject CC_wureducedp(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15456, v_15457;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15413,v_15414);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15414;
    stack[-1] = v_15413;
// end of prologue
    v_15456 = stack[0];
    fn = elt(env, 1); // wuconstantp
    v_15456 = (*qfn1(fn))(fn, v_15456);
    env = stack[-2];
    if (v_15456 == nil) goto v_15418;
    else goto v_15417;
v_15418:
    v_15456 = stack[-1];
    fn = elt(env, 1); // wuconstantp
    v_15456 = (*qfn1(fn))(fn, v_15456);
    env = stack[-2];
    if (v_15456 == nil) goto v_15423;
    else goto v_15422;
v_15423:
    goto v_15431;
v_15427:
    goto v_15437;
v_15433:
    goto v_15434;
v_15435:
    v_15456 = stack[0];
    fn = elt(env, 1); // wuconstantp
    v_15456 = (*qfn1(fn))(fn, v_15456);
    env = stack[-2];
    if (v_15456 == nil) goto v_15442;
    v_15456 = nil;
    goto v_15440;
v_15442:
    v_15456 = stack[0];
    v_15456 = qcar(v_15456);
    v_15456 = qcar(v_15456);
    v_15456 = qcar(v_15456);
    goto v_15440;
    v_15456 = nil;
v_15440:
    goto v_15436;
v_15437:
    goto v_15433;
v_15434:
    goto v_15435;
v_15436:
    fn = elt(env, 2); // deginvar
    v_15457 = (*qfn2(fn))(fn, stack[-1], v_15456);
    goto v_15428;
v_15429:
    v_15456 = stack[0];
    v_15456 = qcar(v_15456);
    v_15456 = qcar(v_15456);
    v_15456 = qcdr(v_15456);
    goto v_15430;
v_15431:
    goto v_15427;
v_15428:
    goto v_15429;
v_15430:
        return Llessp(nil, v_15457, v_15456);
v_15422:
v_15417:
    return onevalue(v_15456);
}



// Code for get!-denom!-ll

static LispObject CC_getKdenomKll(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15451, v_15452;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15413,v_15414);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_15414;
    stack[-2] = v_15413;
// end of prologue
    stack[-3] = nil;
v_15419:
    v_15451 = stack[-2];
    if (v_15451 == nil) goto v_15422;
    else goto v_15423;
v_15422:
    v_15451 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_15451);
    }
v_15423:
    goto v_15434;
v_15430:
    goto v_15440;
v_15436:
    v_15451 = stack[-2];
    stack[0] = qcar(v_15451);
    goto v_15437;
v_15438:
    v_15451 = stack[-1];
    v_15451 = qcar(v_15451);
    fn = elt(env, 2); // get!-denom!-l
    v_15451 = (*qfn1(fn))(fn, v_15451);
    env = stack[-4];
    goto v_15439;
v_15440:
    goto v_15436;
v_15437:
    goto v_15438;
v_15439:
    fn = elt(env, 3); // lcmn
    v_15452 = (*qfn2(fn))(fn, stack[0], v_15451);
    env = stack[-4];
    goto v_15431;
v_15432:
    v_15451 = stack[-3];
    goto v_15433;
v_15434:
    goto v_15430;
v_15431:
    goto v_15432;
v_15433:
    v_15451 = cons(v_15452, v_15451);
    env = stack[-4];
    stack[-3] = v_15451;
    v_15451 = stack[-2];
    v_15451 = qcdr(v_15451);
    stack[-2] = v_15451;
    v_15451 = stack[-1];
    v_15451 = qcdr(v_15451);
    stack[-1] = v_15451;
    goto v_15419;
    v_15451 = nil;
    return onevalue(v_15451);
}



// Code for mk!+conjugate!+sq

static LispObject CC_mkLconjugateLsq(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15419;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15419 = v_15413;
// end of prologue
    {
        fn = elt(env, 1); // conjsq
        return (*qfn1(fn))(fn, v_15419);
    }
    return onevalue(v_15419);
}



// Code for mksp!*

static LispObject CC_mkspH(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15478, v_15479;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15413,v_15414);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15414;
    stack[-1] = v_15413;
// end of prologue
    stack[-2] = nil;
    v_15478 = stack[-1];
    if (v_15478 == nil) goto v_15425;
    else goto v_15426;
v_15425:
    v_15478 = lisp_true;
    goto v_15424;
v_15426:
    v_15478 = stack[-1];
    fn = elt(env, 1); // kernlp
    v_15478 = (*qfn1(fn))(fn, v_15478);
    env = stack[-3];
    goto v_15424;
    v_15478 = nil;
v_15424:
    if (v_15478 == nil) goto v_15422;
    goto v_15438;
v_15434:
    v_15479 = stack[-1];
    goto v_15435;
v_15436:
    v_15478 = stack[0];
    goto v_15437;
v_15438:
    goto v_15434;
v_15435:
    goto v_15436;
v_15437:
    {
        fn = elt(env, 2); // exptf
        return (*qfn2(fn))(fn, v_15479, v_15478);
    }
v_15422:
    v_15478 = stack[-1];
    fn = elt(env, 3); // minusf
    v_15478 = (*qfn1(fn))(fn, v_15478);
    env = stack[-3];
    if (v_15478 == nil) goto v_15442;
    v_15478 = lisp_true;
    stack[-2] = v_15478;
    v_15478 = stack[-1];
    fn = elt(env, 4); // negf
    v_15478 = (*qfn1(fn))(fn, v_15478);
    env = stack[-3];
    stack[-1] = v_15478;
    goto v_15420;
v_15442:
v_15420:
    goto v_15454;
v_15450:
    goto v_15460;
v_15456:
    v_15479 = stack[-1];
    goto v_15457;
v_15458:
    v_15478 = stack[0];
    goto v_15459;
v_15460:
    goto v_15456;
v_15457:
    goto v_15458;
v_15459:
    fn = elt(env, 5); // mksp
    v_15479 = (*qfn2(fn))(fn, v_15479, v_15478);
    env = stack[-3];
    goto v_15451;
v_15452:
    v_15478 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15453;
v_15454:
    goto v_15450;
v_15451:
    goto v_15452;
v_15453:
    v_15478 = cons(v_15479, v_15478);
    env = stack[-3];
    v_15478 = ncons(v_15478);
    env = stack[-3];
    stack[-1] = v_15478;
    v_15478 = stack[-2];
    if (v_15478 == nil) goto v_15467;
    v_15478 = stack[0];
    v_15478 = Levenp(nil, v_15478);
    env = stack[-3];
    if (v_15478 == nil) goto v_15470;
    else goto v_15467;
v_15470:
    v_15478 = stack[-1];
    {
        fn = elt(env, 4); // negf
        return (*qfn1(fn))(fn, v_15478);
    }
v_15467:
    v_15478 = stack[-1];
    goto v_15465;
    v_15478 = nil;
v_15465:
    return onevalue(v_15478);
}



// Code for talp_try

static LispObject CC_talp_try(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15420;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15420 = v_15413;
// end of prologue
    fn = elt(env, 1); // rl_pnf
    v_15420 = (*qfn1(fn))(fn, v_15420);
    env = stack[0];
    fn = elt(env, 2); // talp_invtscsimpl
    v_15420 = (*qfn1(fn))(fn, v_15420);
    env = stack[0];
    fn = elt(env, 3); // talp_lssimpl
    v_15420 = (*qfn1(fn))(fn, v_15420);
    env = stack[0];
    {
        fn = elt(env, 4); // talp_try1
        return (*qfn1(fn))(fn, v_15420);
    }
}



// Code for pasf_varlat

static LispObject CC_pasf_varlat(LispObject env,
                         LispObject v_15413)
{
    env = qenv(env);
    LispObject v_15514, v_15515;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15413);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15413;
// end of prologue
    goto v_15423;
v_15419:
    v_15514 = stack[0];
    v_15514 = qcdr(v_15514);
    v_15514 = qcar(v_15514);
    fn = elt(env, 3); // kernels
    stack[-1] = (*qfn1(fn))(fn, v_15514);
    env = stack[-4];
    goto v_15420;
v_15421:
    v_15514 = stack[0];
    v_15514 = Lconsp(nil, v_15514);
    env = stack[-4];
    if (v_15514 == nil) goto v_15431;
    v_15514 = stack[0];
    v_15514 = qcar(v_15514);
    v_15514 = Lconsp(nil, v_15514);
    env = stack[-4];
    if (v_15514 == nil) goto v_15431;
    goto v_15445;
v_15441:
    v_15514 = stack[0];
    v_15514 = qcar(v_15514);
    v_15515 = qcar(v_15514);
    goto v_15442;
v_15443:
    v_15514 = elt(env, 1); // (cong ncong)
    goto v_15444;
v_15445:
    goto v_15441;
v_15442:
    goto v_15443;
v_15444:
    v_15514 = Lmemq(nil, v_15515, v_15514);
    if (v_15514 == nil) goto v_15431;
    v_15514 = stack[0];
    v_15514 = qcar(v_15514);
    v_15514 = qcdr(v_15514);
    fn = elt(env, 3); // kernels
    v_15514 = (*qfn1(fn))(fn, v_15514);
    env = stack[-4];
    goto v_15429;
v_15431:
    v_15514 = nil;
    goto v_15429;
    v_15514 = nil;
v_15429:
    goto v_15422;
v_15423:
    goto v_15419;
v_15420:
    goto v_15421;
v_15422:
    v_15514 = Lappend(nil, stack[-1], v_15514);
    env = stack[-4];
    v_15515 = v_15514;
    v_15514 = qvalue(elt(env, 2)); // !*rlbrkcxk
    if (v_15514 == nil) goto v_15461;
    v_15514 = v_15515;
    stack[-3] = v_15514;
v_15468:
    v_15514 = stack[-3];
    if (v_15514 == nil) goto v_15473;
    else goto v_15474;
v_15473:
    v_15514 = nil;
    goto v_15467;
v_15474:
    v_15514 = stack[-3];
    v_15514 = qcar(v_15514);
    fn = elt(env, 4); // rltools_lpvarl
    v_15514 = (*qfn1(fn))(fn, v_15514);
    env = stack[-4];
    stack[-2] = v_15514;
    v_15514 = stack[-2];
    fn = elt(env, 5); // lastpair
    v_15514 = (*qfn1(fn))(fn, v_15514);
    env = stack[-4];
    stack[-1] = v_15514;
    v_15514 = stack[-3];
    v_15514 = qcdr(v_15514);
    stack[-3] = v_15514;
    v_15514 = stack[-1];
    if (!consp(v_15514)) goto v_15488;
    else goto v_15489;
v_15488:
    goto v_15468;
v_15489:
v_15469:
    v_15514 = stack[-3];
    if (v_15514 == nil) goto v_15493;
    else goto v_15494;
v_15493:
    v_15514 = stack[-2];
    goto v_15467;
v_15494:
    goto v_15502;
v_15498:
    stack[0] = stack[-1];
    goto v_15499;
v_15500:
    v_15514 = stack[-3];
    v_15514 = qcar(v_15514);
    fn = elt(env, 4); // rltools_lpvarl
    v_15514 = (*qfn1(fn))(fn, v_15514);
    env = stack[-4];
    goto v_15501;
v_15502:
    goto v_15498;
v_15499:
    goto v_15500;
v_15501:
    v_15514 = Lrplacd(nil, stack[0], v_15514);
    env = stack[-4];
    v_15514 = stack[-1];
    fn = elt(env, 5); // lastpair
    v_15514 = (*qfn1(fn))(fn, v_15514);
    env = stack[-4];
    stack[-1] = v_15514;
    v_15514 = stack[-3];
    v_15514 = qcdr(v_15514);
    stack[-3] = v_15514;
    goto v_15469;
v_15467:
    v_15515 = v_15514;
    goto v_15459;
v_15461:
v_15459:
    v_15514 = v_15515;
    return onevalue(v_15514);
}



// Code for bc_prod

static LispObject CC_bc_prod(LispObject env,
                         LispObject v_15413, LispObject v_15414)
{
    env = qenv(env);
    LispObject v_15532, v_15533, v_15534, v_15535;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15414,v_15413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15413,v_15414);
    }
// copy arguments values to proper place
    v_15534 = v_15414;
    v_15535 = v_15413;
// end of prologue
    goto v_15428;
v_15424:
    v_15532 = v_15535;
    v_15533 = qcdr(v_15532);
    goto v_15425;
v_15426:
    v_15532 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15427;
v_15428:
    goto v_15424;
v_15425:
    goto v_15426;
v_15427:
    if (v_15533 == v_15532) goto v_15422;
    else goto v_15423;
v_15422:
    v_15532 = v_15535;
    v_15532 = qcar(v_15532);
    if (is_number(v_15532)) goto v_15435;
    v_15532 = nil;
    goto v_15433;
v_15435:
    goto v_15449;
v_15445:
    v_15532 = v_15534;
    v_15533 = qcdr(v_15532);
    goto v_15446;
v_15447:
    v_15532 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15448;
v_15449:
    goto v_15445;
v_15446:
    goto v_15447;
v_15448:
    if (v_15533 == v_15532) goto v_15443;
    else goto v_15444;
v_15443:
    v_15532 = v_15534;
    v_15532 = qcar(v_15532);
    v_15532 = (is_number(v_15532) ? lisp_true : nil);
    goto v_15442;
v_15444:
    v_15532 = nil;
    goto v_15442;
    v_15532 = nil;
v_15442:
    goto v_15433;
    v_15532 = nil;
v_15433:
    goto v_15421;
v_15423:
    v_15532 = nil;
    goto v_15421;
    v_15532 = nil;
v_15421:
    if (v_15532 == nil) goto v_15419;
    goto v_15470;
v_15466:
    v_15532 = v_15535;
    v_15533 = qcar(v_15532);
    goto v_15467;
v_15468:
    v_15532 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15469;
v_15470:
    goto v_15466;
v_15467:
    goto v_15468;
v_15469:
    if (v_15533 == v_15532) goto v_15464;
    else goto v_15465;
v_15464:
    v_15532 = v_15534;
    goto v_15463;
v_15465:
    goto v_15481;
v_15477:
    v_15532 = v_15534;
    v_15533 = qcar(v_15532);
    goto v_15478;
v_15479:
    v_15532 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15480;
v_15481:
    goto v_15477;
v_15478:
    goto v_15479;
v_15480:
    if (v_15533 == v_15532) goto v_15475;
    else goto v_15476;
v_15475:
    v_15532 = v_15535;
    goto v_15463;
v_15476:
    goto v_15492;
v_15488:
    goto v_15498;
v_15494:
    v_15532 = v_15535;
    v_15532 = qcar(v_15532);
    goto v_15495;
v_15496:
    v_15533 = v_15534;
    v_15533 = qcar(v_15533);
    goto v_15497;
v_15498:
    goto v_15494;
v_15495:
    goto v_15496;
v_15497:
    v_15533 = times2(v_15532, v_15533);
    v_15535 = v_15533;
    goto v_15489;
v_15490:
    v_15532 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15491;
v_15492:
    goto v_15488;
v_15489:
    goto v_15490;
v_15491:
    if (v_15533 == v_15532) goto v_15486;
    else goto v_15487;
v_15486:
    goto v_15509;
v_15505:
    v_15533 = nil;
    goto v_15506;
v_15507:
    v_15532 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15508;
v_15509:
    goto v_15505;
v_15506:
    goto v_15507;
v_15508:
    return cons(v_15533, v_15532);
v_15487:
    goto v_15519;
v_15515:
    v_15533 = v_15535;
    goto v_15516;
v_15517:
    v_15532 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15518;
v_15519:
    goto v_15515;
v_15516:
    goto v_15517;
v_15518:
    return cons(v_15533, v_15532);
    v_15532 = nil;
v_15463:
    goto v_15417;
v_15419:
    goto v_15529;
v_15525:
    v_15532 = v_15535;
    goto v_15526;
v_15527:
    v_15533 = v_15534;
    goto v_15528;
v_15529:
    goto v_15525;
v_15526:
    goto v_15527;
v_15528:
    {
        fn = elt(env, 1); // multsq
        return (*qfn2(fn))(fn, v_15532, v_15533);
    }
    v_15532 = nil;
v_15417:
    return onevalue(v_15532);
}



setup_type const u28_setup[] =
{
    {"procstat1",               CC_procstat1,   TOO_MANY_1,    WRONG_NO_1},
    {"get_char_value",          TOO_FEW_2,      CC_get_char_value,WRONG_NO_2},
    {"aex_mvartest",            TOO_FEW_2,      CC_aex_mvartest,WRONG_NO_2},
    {"multi_args",              CC_multi_args,  TOO_MANY_1,    WRONG_NO_1},
    {"n_nary",                  TOO_FEW_2,      CC_n_nary,     WRONG_NO_2},
    {"gcd2",                    TOO_FEW_2,      CC_gcd2,       WRONG_NO_2},
    {"meq",                     TOO_FEW_2,      CC_meq,        WRONG_NO_2},
    {"gcompatible",             TOO_FEW_2,      CC_gcompatible,WRONG_NO_2},
    {"groebnormalform",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_groebnormalform},
    {"memqcar",                 TOO_FEW_2,      CC_memqcar,    WRONG_NO_2},
    {"equalreval",              CC_equalreval,  TOO_MANY_1,    WRONG_NO_1},
    {"log_assignment_list",     TOO_FEW_2,      CC_log_assignment_list,WRONG_NO_2},
    {"red=subst1",              TOO_FEW_2,      CC_redMsubst1, WRONG_NO_2},
    {"insert",                  TOO_FEW_2,      CC_insert,     WRONG_NO_2},
    {"dv_cambhead",             CC_dv_cambhead, TOO_MANY_1,    WRONG_NO_1},
    {"lalr_make_compressed_action_table",WRONG_NO_NA,WRONG_NO_NB,(n_args *)CC_lalr_make_compressed_action_table},
    {"ifstat",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ifstat},
    {"opmtchrevop",             CC_opmtchrevop, TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_optsubstat",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_optsubstat},
    {"lambdavar",               CC_lambdavar,   TOO_MANY_1,    WRONG_NO_1},
    {"rowdel",                  CC_rowdel,      TOO_MANY_1,    WRONG_NO_1},
    {"bfplusn",                 TOO_FEW_2,      CC_bfplusn,    WRONG_NO_2},
    {"fortranname",             CC_fortranname, TOO_MANY_1,    WRONG_NO_1},
    {"mk-numr",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mkKnumr},
    {"mksetq",                  TOO_FEW_2,      CC_mksetq,     WRONG_NO_2},
    {"bndtst",                  CC_bndtst,      TOO_MANY_1,    WRONG_NO_1},
    {"termorder",               TOO_FEW_2,      CC_termorder,  WRONG_NO_2},
    {"lalr_collect_terminals",  CC_lalr_collect_terminals,TOO_MANY_1,WRONG_NO_1},
    {"co_new",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_co_new},
    {"homogp",                  CC_homogp,      TOO_MANY_1,    WRONG_NO_1},
    {"bc_2sq",                  CC_bc_2sq,      TOO_MANY_1,    WRONG_NO_1},
    {"atomlis",                 CC_atomlis,     TOO_MANY_1,    WRONG_NO_1},
    {"dip2vdp",                 CC_dip2vdp,     TOO_MANY_1,    WRONG_NO_1},
    {"contr-strand",            TOO_FEW_2,      CC_contrKstrand,WRONG_NO_2},
    {"assert_stat1",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_assert_stat1},
    {"nf",                      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_nf},
    {"setk1",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setk1},
    {"lex_export_codes",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex_export_codes},
    {"mkfil*",                  CC_mkfilH,      TOO_MANY_1,    WRONG_NO_1},
    {"prepreform1",             TOO_FEW_2,      CC_prepreform1,WRONG_NO_2},
    {"aex_mvar",                CC_aex_mvar,    TOO_MANY_1,    WRONG_NO_1},
    {"ombindir",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ombindir},
    {"simpdf*",                 CC_simpdfH,     TOO_MANY_1,    WRONG_NO_1},
    {"nextcomb",                TOO_FEW_2,      CC_nextcomb,   WRONG_NO_2},
    {"dip-nc-ev-prod1",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dipKncKevKprod1},
    {"pterpri",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pterpri},
    {"getphystypeor",           CC_getphystypeor,TOO_MANY_1,   WRONG_NO_1},
    {"prop-simp",               TOO_FEW_2,      CC_propKsimp,  WRONG_NO_2},
    {"nzero",                   CC_nzero,       TOO_MANY_1,    WRONG_NO_1},
    {"general-evaluate-mod-p",  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_generalKevaluateKmodKp},
    {"lalr_generate_collection",WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lalr_generate_collection},
    {"open",                    TOO_FEW_2,      CC_open,       WRONG_NO_2},
    {"normalform",              CC_normalform,  TOO_MANY_1,    WRONG_NO_1},
    {"wureducedp",              TOO_FEW_2,      CC_wureducedp, WRONG_NO_2},
    {"get-denom-ll",            TOO_FEW_2,      CC_getKdenomKll,WRONG_NO_2},
    {"mk+conjugate+sq",         CC_mkLconjugateLsq,TOO_MANY_1, WRONG_NO_1},
    {"mksp*",                   TOO_FEW_2,      CC_mkspH,      WRONG_NO_2},
    {"talp_try",                CC_talp_try,    TOO_MANY_1,    WRONG_NO_1},
    {"pasf_varlat",             CC_pasf_varlat, TOO_MANY_1,    WRONG_NO_1},
    {"bc_prod",                 TOO_FEW_2,      CC_bc_prod,    WRONG_NO_2},
    {NULL, (one_args *)"u28", (two_args *)"155336 5380972 1015793", 0}
};

// end of generated code
