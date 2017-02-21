
// $destdir/u46.c        Machine generated C code

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



// Code for qqe_simplbtat

static LispObject CC_qqe_simplbtat(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27301, v_27302;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_27301 = v_27210;
    stack[-2] = v_27209;
// end of prologue
    v_27301 = stack[-2];
    fn = elt(env, 5); // rl_prepat
    v_27301 = (*qfn1(fn))(fn, v_27301);
    env = stack[-4];
    stack[-3] = v_27301;
    v_27301 = stack[-2];
    fn = elt(env, 6); // qqe_op
    v_27301 = (*qfn1(fn))(fn, v_27301);
    env = stack[-4];
    stack[0] = v_27301;
    v_27301 = stack[-3];
    fn = elt(env, 7); // qqe_arg2l
    v_27301 = (*qfn1(fn))(fn, v_27301);
    env = stack[-4];
    fn = elt(env, 8); // qqe_eta!-in!-term
    v_27301 = (*qfn1(fn))(fn, v_27301);
    env = stack[-4];
    stack[-1] = v_27301;
    v_27301 = stack[-3];
    fn = elt(env, 9); // qqe_arg2r
    v_27301 = (*qfn1(fn))(fn, v_27301);
    env = stack[-4];
    fn = elt(env, 8); // qqe_eta!-in!-term
    v_27301 = (*qfn1(fn))(fn, v_27301);
    env = stack[-4];
    v_27302 = v_27301;
    v_27301 = stack[-1];
    if (v_27301 == nil) goto v_27231;
    v_27301 = v_27302;
    if (v_27301 == nil) goto v_27234;
    else goto v_27231;
v_27234:
    goto v_27244;
v_27240:
    v_27302 = stack[0];
    goto v_27241;
v_27242:
    v_27301 = elt(env, 1); // neq
    goto v_27243;
v_27244:
    goto v_27240;
v_27241:
    goto v_27242;
v_27243:
    if (v_27302 == v_27301) goto v_27239;
    v_27301 = elt(env, 2); // false
    goto v_27217;
v_27239:
    v_27301 = elt(env, 3); // true
    goto v_27217;
    goto v_27229;
v_27231:
    v_27301 = v_27302;
    if (v_27301 == nil) goto v_27253;
    v_27301 = stack[-1];
    if (v_27301 == nil) goto v_27256;
    else goto v_27253;
v_27256:
    goto v_27266;
v_27262:
    v_27302 = stack[0];
    goto v_27263;
v_27264:
    v_27301 = elt(env, 1); // neq
    goto v_27265;
v_27266:
    goto v_27262;
v_27263:
    goto v_27264;
v_27265:
    if (v_27302 == v_27301) goto v_27261;
    v_27301 = elt(env, 2); // false
    goto v_27217;
v_27261:
    v_27301 = elt(env, 3); // true
    goto v_27217;
    goto v_27229;
v_27253:
    v_27301 = stack[-1];
    if (v_27301 == nil) goto v_27275;
    v_27301 = v_27302;
    if (v_27301 == nil) goto v_27275;
    goto v_27288;
v_27284:
    v_27301 = stack[-2];
    fn = elt(env, 6); // qqe_op
    v_27302 = (*qfn1(fn))(fn, v_27301);
    env = stack[-4];
    goto v_27285;
v_27286:
    v_27301 = elt(env, 4); // equal
    goto v_27287;
v_27288:
    goto v_27284;
v_27285:
    goto v_27286;
v_27287:
    if (v_27302 == v_27301) goto v_27282;
    else goto v_27283;
v_27282:
    v_27301 = elt(env, 3); // true
    goto v_27217;
v_27283:
    v_27301 = elt(env, 2); // false
    goto v_27217;
    goto v_27229;
v_27275:
    v_27301 = stack[-3];
    {
        fn = elt(env, 10); // rl_simpat
        return (*qfn1(fn))(fn, v_27301);
    }
v_27229:
    v_27301 = nil;
v_27217:
    return onevalue(v_27301);
}



// Code for pasf_ceil

static LispObject CC_pasf_ceil(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27331, v_27332, v_27333;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27210;
    stack[-1] = v_27209;
// end of prologue
    v_27331 = stack[-1];
    if (!consp(v_27331)) goto v_27222;
    else goto v_27223;
v_27222:
    v_27331 = lisp_true;
    goto v_27221;
v_27223:
    v_27331 = stack[-1];
    v_27331 = qcar(v_27331);
    v_27331 = (consp(v_27331) ? nil : lisp_true);
    goto v_27221;
    v_27331 = nil;
v_27221:
    if (v_27331 == nil) goto v_27219;
    v_27331 = stack[0];
    if (!consp(v_27331)) goto v_27233;
    else goto v_27234;
v_27233:
    v_27331 = lisp_true;
    goto v_27232;
v_27234:
    v_27331 = stack[0];
    v_27331 = qcar(v_27331);
    v_27331 = (consp(v_27331) ? nil : lisp_true);
    goto v_27232;
    v_27331 = nil;
v_27232:
    goto v_27217;
v_27219:
    v_27331 = nil;
    goto v_27217;
    v_27331 = nil;
v_27217:
    if (v_27331 == nil) goto v_27215;
    v_27331 = stack[-1];
    if (v_27331 == nil) goto v_27247;
    else goto v_27248;
v_27247:
    v_27331 = nil;
    goto v_27246;
v_27248:
    goto v_27262;
v_27258:
    goto v_27268;
v_27264:
    v_27332 = stack[-1];
    goto v_27265;
v_27266:
    v_27331 = stack[0];
    goto v_27267;
v_27268:
    goto v_27264;
v_27265:
    goto v_27266;
v_27267:
    v_27332 = Cremainder(v_27332, v_27331);
    env = stack[-2];
    goto v_27259;
v_27260:
    v_27331 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27261;
v_27262:
    goto v_27258;
v_27259:
    goto v_27260;
v_27261:
    if (v_27332 == v_27331) goto v_27256;
    else goto v_27257;
v_27256:
    goto v_27277;
v_27273:
    v_27332 = stack[-1];
    goto v_27274;
v_27275:
    v_27331 = stack[0];
    goto v_27276;
v_27277:
    goto v_27273;
v_27274:
    goto v_27275;
v_27276:
    v_27331 = quot2(v_27332, v_27331);
    env = stack[-2];
    goto v_27255;
v_27257:
    goto v_27287;
v_27283:
    goto v_27293;
v_27289:
    v_27332 = stack[-1];
    goto v_27290;
v_27291:
    v_27331 = stack[0];
    goto v_27292;
v_27293:
    goto v_27289;
v_27290:
    goto v_27291;
v_27292:
    v_27332 = times2(v_27332, v_27331);
    env = stack[-2];
    goto v_27284;
v_27285:
    v_27331 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27286;
v_27287:
    goto v_27283;
v_27284:
    goto v_27285;
v_27286:
    v_27331 = (LispObject)greaterp2(v_27332, v_27331);
    v_27331 = v_27331 ? lisp_true : nil;
    env = stack[-2];
    if (v_27331 == nil) goto v_27281;
    goto v_27303;
v_27299:
    v_27332 = stack[-1];
    goto v_27300;
v_27301:
    v_27331 = stack[0];
    goto v_27302;
v_27303:
    goto v_27299;
v_27300:
    goto v_27301;
v_27302:
    v_27331 = quot2(v_27332, v_27331);
    env = stack[-2];
    v_27331 = add1(v_27331);
    env = stack[-2];
    goto v_27255;
v_27281:
    goto v_27313;
v_27309:
    v_27332 = stack[-1];
    goto v_27310;
v_27311:
    v_27331 = stack[0];
    goto v_27312;
v_27313:
    goto v_27309;
v_27310:
    goto v_27311;
v_27312:
    v_27331 = quot2(v_27332, v_27331);
    env = stack[-2];
    goto v_27255;
    v_27331 = nil;
v_27255:
    fn = elt(env, 2); // simp
    v_27331 = (*qfn1(fn))(fn, v_27331);
    v_27331 = qcar(v_27331);
    goto v_27246;
    v_27331 = nil;
v_27246:
    goto v_27213;
v_27215:
    goto v_27327;
v_27321:
    v_27333 = elt(env, 1); // "pasf_ceil: not a domain valued sf in input"
    goto v_27322;
v_27323:
    v_27332 = stack[-1];
    goto v_27324;
v_27325:
    v_27331 = stack[0];
    goto v_27326;
v_27327:
    goto v_27321;
v_27322:
    goto v_27323;
v_27324:
    goto v_27325;
v_27326:
    v_27331 = list3(v_27333, v_27332, v_27331);
    env = stack[-2];
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_27331);
    }
    v_27331 = nil;
v_27213:
    return onevalue(v_27331);
}



// Code for quotientml

static LispObject CC_quotientml(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27272;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27210;
    stack[-1] = v_27209;
// end of prologue
    v_27272 = stack[-1];
    v_27272 = qcar(v_27272);
    if (is_number(v_27272)) goto v_27218;
    else goto v_27217;
v_27218:
    v_27272 = stack[-1];
    v_27272 = qcdr(v_27272);
    v_27272 = qcar(v_27272);
    if (is_number(v_27272)) goto v_27221;
    else goto v_27217;
v_27221:
    v_27272 = qvalue(elt(env, 1)); // !*web
    if (v_27272 == nil) goto v_27227;
    else goto v_27228;
v_27227:
    v_27272 = elt(env, 2); // "<cn type=""rational""> "
    fn = elt(env, 10); // printout
    v_27272 = (*qfn1(fn))(fn, v_27272);
    env = stack[-2];
    goto v_27226;
v_27228:
    v_27272 = elt(env, 3); // "<cn type=&quot;rational&quot;> "
    fn = elt(env, 10); // printout
    v_27272 = (*qfn1(fn))(fn, v_27272);
    env = stack[-2];
    goto v_27226;
v_27226:
    v_27272 = stack[-1];
    v_27272 = qcar(v_27272);
    v_27272 = Lprinc(nil, v_27272);
    env = stack[-2];
    v_27272 = elt(env, 4); // " <sep/> "
    v_27272 = Lprinc(nil, v_27272);
    env = stack[-2];
    v_27272 = stack[-1];
    v_27272 = qcdr(v_27272);
    v_27272 = qcar(v_27272);
    v_27272 = Lprinc(nil, v_27272);
    env = stack[-2];
    v_27272 = elt(env, 5); // " </cn>"
    v_27272 = Lprinc(nil, v_27272);
    goto v_27215;
v_27217:
    v_27272 = elt(env, 6); // "<apply>"
    fn = elt(env, 10); // printout
    v_27272 = (*qfn1(fn))(fn, v_27272);
    env = stack[-2];
    v_27272 = elt(env, 7); // "<"
    v_27272 = Lprinc(nil, v_27272);
    env = stack[-2];
    v_27272 = stack[0];
    v_27272 = Lprinc(nil, v_27272);
    env = stack[-2];
    v_27272 = elt(env, 8); // "/>"
    v_27272 = Lprinc(nil, v_27272);
    env = stack[-2];
    v_27272 = lisp_true;
    fn = elt(env, 11); // indent!*
    v_27272 = (*qfn1(fn))(fn, v_27272);
    env = stack[-2];
    v_27272 = stack[-1];
    v_27272 = qcdr(v_27272);
    v_27272 = qcar(v_27272);
    fn = elt(env, 12); // expression
    v_27272 = (*qfn1(fn))(fn, v_27272);
    env = stack[-2];
    v_27272 = stack[-1];
    v_27272 = qcdr(v_27272);
    v_27272 = qcdr(v_27272);
    v_27272 = qcar(v_27272);
    fn = elt(env, 12); // expression
    v_27272 = (*qfn1(fn))(fn, v_27272);
    env = stack[-2];
    v_27272 = nil;
    fn = elt(env, 11); // indent!*
    v_27272 = (*qfn1(fn))(fn, v_27272);
    env = stack[-2];
    v_27272 = elt(env, 9); // "</apply>"
    fn = elt(env, 10); // printout
    v_27272 = (*qfn1(fn))(fn, v_27272);
    goto v_27215;
v_27215:
    v_27272 = nil;
    return onevalue(v_27272);
}



// Code for simpdf

static LispObject CC_simpdf(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27506, v_27507;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27209);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_27209;
// end of prologue
    stack[-3] = nil;
    v_27506 = qvalue(elt(env, 1)); // subfg!*
    if (v_27506 == nil) goto v_27220;
    else goto v_27221;
v_27220:
    goto v_27228;
v_27224:
    goto v_27234;
v_27230:
    v_27507 = elt(env, 2); // df
    goto v_27231;
v_27232:
    v_27506 = stack[-5];
    goto v_27233;
v_27234:
    goto v_27230;
v_27231:
    goto v_27232;
v_27233:
    v_27507 = cons(v_27507, v_27506);
    env = stack[-7];
    goto v_27225;
v_27226:
    v_27506 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27227;
v_27228:
    goto v_27224;
v_27225:
    goto v_27226;
v_27227:
    {
        fn = elt(env, 8); // mksq
        return (*qfn2(fn))(fn, v_27507, v_27506);
    }
v_27221:
    v_27506 = stack[-5];
    v_27506 = qcdr(v_27506);
    stack[-6] = v_27506;
    v_27506 = stack[-5];
    v_27506 = qcar(v_27506);
    fn = elt(env, 9); // simp!*
    v_27506 = (*qfn1(fn))(fn, v_27506);
    env = stack[-7];
    stack[-5] = v_27506;
v_27217:
    v_27506 = stack[-6];
    if (v_27506 == nil) goto v_27249;
    else goto v_27250;
v_27249:
    v_27506 = lisp_true;
    goto v_27248;
v_27250:
    v_27506 = stack[-5];
    v_27506 = qcar(v_27506);
    v_27506 = (v_27506 == nil ? lisp_true : nil);
    goto v_27248;
    v_27506 = nil;
v_27248:
    if (v_27506 == nil) goto v_27246;
    v_27506 = stack[-5];
    goto v_27216;
v_27246:
    v_27506 = stack[-3];
    if (v_27506 == nil) goto v_27265;
    else goto v_27266;
v_27265:
    v_27506 = lisp_true;
    goto v_27264;
v_27266:
    goto v_27275;
v_27271:
    v_27507 = stack[-3];
    goto v_27272;
v_27273:
    v_27506 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27274;
v_27275:
    goto v_27271;
v_27272:
    goto v_27273;
v_27274:
    v_27506 = (v_27507 == v_27506 ? lisp_true : nil);
    goto v_27264;
    v_27506 = nil;
v_27264:
    if (v_27506 == nil) goto v_27262;
    v_27506 = stack[-6];
    v_27506 = qcar(v_27506);
    fn = elt(env, 9); // simp!*
    v_27506 = (*qfn1(fn))(fn, v_27506);
    env = stack[-7];
    goto v_27260;
v_27262:
    v_27506 = stack[-3];
    goto v_27260;
    v_27506 = nil;
v_27260:
    stack[-4] = v_27506;
    goto v_27297;
v_27293:
    v_27506 = stack[-4];
    v_27507 = qcdr(v_27506);
    goto v_27294;
v_27295:
    v_27506 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27296;
v_27297:
    goto v_27293;
v_27294:
    goto v_27295;
v_27296:
    if (v_27507 == v_27506) goto v_27292;
    v_27506 = lisp_true;
    goto v_27290;
v_27292:
    v_27506 = stack[-4];
    v_27506 = qcar(v_27506);
    v_27506 = (consp(v_27506) ? nil : lisp_true);
    goto v_27290;
    v_27506 = nil;
v_27290:
    if (v_27506 == nil) goto v_27288;
    goto v_27312;
v_27308:
    v_27506 = stack[-4];
    fn = elt(env, 10); // prepsq
    v_27507 = (*qfn1(fn))(fn, v_27506);
    env = stack[-7];
    goto v_27309;
v_27310:
    v_27506 = elt(env, 3); // "kernel or integer"
    goto v_27311;
v_27312:
    goto v_27308;
v_27309:
    goto v_27310;
v_27311:
    fn = elt(env, 11); // typerr
    v_27506 = (*qfn2(fn))(fn, v_27507, v_27506);
    env = stack[-7];
    goto v_27286;
v_27288:
    v_27506 = stack[-4];
    v_27506 = qcar(v_27506);
    stack[-2] = v_27506;
    v_27506 = stack[-2];
    if (!consp(v_27506)) goto v_27327;
    else goto v_27328;
v_27327:
    v_27506 = lisp_true;
    goto v_27326;
v_27328:
    v_27506 = stack[-2];
    v_27506 = qcar(v_27506);
    v_27506 = (consp(v_27506) ? nil : lisp_true);
    goto v_27326;
    v_27506 = nil;
v_27326:
    if (v_27506 == nil) goto v_27324;
    goto v_27345;
v_27341:
    v_27506 = stack[-2];
    v_27507 = qcar(v_27506);
    goto v_27342;
v_27343:
    v_27506 = elt(env, 4); // domain!-diff!-fn
    goto v_27344;
v_27345:
    goto v_27341;
v_27342:
    goto v_27343;
v_27344:
    v_27506 = get(v_27507, v_27506);
    env = stack[-7];
    if (v_27506 == nil) goto v_27339;
// Binding dmode!*
// FLUIDBIND: reloadenv=7 litvec-offset=5 saveloc=1
{   bind_fluid_stack bind_fluid_var(-7, 5, -1);
    qvalue(elt(env, 5)) = nil; // dmode!*
// Binding alglist!*
// FLUIDBIND: reloadenv=7 litvec-offset=6 saveloc=0
{   bind_fluid_stack bind_fluid_var(-7, 6, 0);
    qvalue(elt(env, 6)) = nil; // alglist!*
    v_27506 = nil;
    v_27506 = ncons(v_27506);
    env = stack[-7];
    qvalue(elt(env, 6)) = v_27506; // alglist!*
    v_27506 = stack[-2];
    fn = elt(env, 12); // prepf
    v_27506 = (*qfn1(fn))(fn, v_27506);
    env = stack[-7];
    stack[-4] = v_27506;
    v_27506 = stack[-4];
    fn = elt(env, 13); // prekernp
    v_27506 = (*qfn1(fn))(fn, v_27506);
    env = stack[-7];
    if (v_27506 == nil) goto v_27359;
    else goto v_27360;
v_27359:
    goto v_27368;
v_27364:
    v_27507 = stack[-4];
    goto v_27365;
v_27366:
    v_27506 = elt(env, 7); // "kernel"
    goto v_27367;
v_27368:
    goto v_27364;
v_27365:
    goto v_27366;
v_27367:
    fn = elt(env, 11); // typerr
    v_27506 = (*qfn2(fn))(fn, v_27507, v_27506);
    env = stack[-7];
    goto v_27358;
v_27360:
v_27358:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_27337;
v_27339:
    goto v_27378;
v_27374:
    v_27506 = stack[-2];
    fn = elt(env, 12); // prepf
    v_27507 = (*qfn1(fn))(fn, v_27506);
    env = stack[-7];
    goto v_27375;
v_27376:
    v_27506 = elt(env, 7); // "kernel"
    goto v_27377;
v_27378:
    goto v_27374;
v_27375:
    goto v_27376;
v_27377:
    fn = elt(env, 11); // typerr
    v_27506 = (*qfn2(fn))(fn, v_27507, v_27506);
    env = stack[-7];
    goto v_27337;
v_27337:
    goto v_27322;
v_27324:
    v_27506 = stack[-2];
    v_27506 = qcdr(v_27506);
    if (v_27506 == nil) goto v_27386;
    else goto v_27387;
v_27386:
    goto v_27398;
v_27394:
    v_27506 = stack[-2];
    v_27506 = qcar(v_27506);
    v_27507 = qcdr(v_27506);
    goto v_27395;
v_27396:
    v_27506 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27397;
v_27398:
    goto v_27394;
v_27395:
    goto v_27396;
v_27397:
    if (v_27507 == v_27506) goto v_27392;
    else goto v_27393;
v_27392:
    goto v_27407;
v_27403:
    v_27506 = stack[-2];
    v_27506 = qcar(v_27506);
    v_27506 = qcar(v_27506);
    v_27507 = qcdr(v_27506);
    goto v_27404;
v_27405:
    v_27506 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27406;
v_27407:
    goto v_27403;
v_27404:
    goto v_27405;
v_27406:
    v_27506 = (v_27507 == v_27506 ? lisp_true : nil);
    goto v_27391;
v_27393:
    v_27506 = nil;
    goto v_27391;
    v_27506 = nil;
v_27391:
    goto v_27385;
v_27387:
    v_27506 = nil;
    goto v_27385;
    v_27506 = nil;
v_27385:
    if (v_27506 == nil) goto v_27383;
    v_27506 = stack[-2];
    v_27506 = qcar(v_27506);
    v_27506 = qcar(v_27506);
    v_27506 = qcar(v_27506);
    stack[-4] = v_27506;
    goto v_27322;
v_27383:
    goto v_27431;
v_27427:
    v_27506 = stack[-2];
    fn = elt(env, 12); // prepf
    v_27507 = (*qfn1(fn))(fn, v_27506);
    env = stack[-7];
    goto v_27428;
v_27429:
    v_27506 = elt(env, 7); // "kernel"
    goto v_27430;
v_27431:
    goto v_27427;
v_27428:
    goto v_27429;
v_27430:
    fn = elt(env, 11); // typerr
    v_27506 = (*qfn2(fn))(fn, v_27507, v_27506);
    env = stack[-7];
    goto v_27322;
v_27322:
    goto v_27286;
v_27286:
    v_27506 = stack[-6];
    v_27506 = qcdr(v_27506);
    stack[-6] = v_27506;
    v_27506 = stack[-6];
    if (v_27506 == nil) goto v_27439;
    else goto v_27440;
v_27439:
    goto v_27447;
v_27443:
    v_27507 = stack[-5];
    goto v_27444;
v_27445:
    v_27506 = stack[-4];
    goto v_27446;
v_27447:
    goto v_27443;
v_27444:
    goto v_27445;
v_27446:
    fn = elt(env, 14); // diffsq
    v_27506 = (*qfn2(fn))(fn, v_27507, v_27506);
    env = stack[-7];
    stack[-5] = v_27506;
    goto v_27217;
v_27440:
    v_27506 = stack[-6];
    v_27506 = qcar(v_27506);
    fn = elt(env, 9); // simp!*
    v_27506 = (*qfn1(fn))(fn, v_27506);
    env = stack[-7];
    stack[-3] = v_27506;
    v_27506 = stack[-3];
    v_27506 = qcar(v_27506);
    if (v_27506 == nil) goto v_27455;
    else goto v_27456;
v_27455:
    v_27506 = stack[-6];
    v_27506 = qcdr(v_27506);
    stack[-6] = v_27506;
    v_27506 = nil;
    stack[-3] = v_27506;
    goto v_27217;
v_27456:
    v_27506 = stack[-3];
    fn = elt(env, 15); // d2int
    v_27506 = (*qfn1(fn))(fn, v_27506);
    env = stack[-7];
    stack[0] = v_27506;
    if (v_27506 == nil) goto v_27462;
    else goto v_27463;
v_27462:
    goto v_27471;
v_27467:
    v_27507 = stack[-5];
    goto v_27468;
v_27469:
    v_27506 = stack[-4];
    goto v_27470;
v_27471:
    goto v_27467;
v_27468:
    goto v_27469;
v_27470:
    fn = elt(env, 14); // diffsq
    v_27506 = (*qfn2(fn))(fn, v_27507, v_27506);
    env = stack[-7];
    stack[-5] = v_27506;
    goto v_27217;
v_27463:
    v_27506 = stack[-6];
    v_27506 = qcdr(v_27506);
    stack[-6] = v_27506;
    v_27506 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_27506;
v_27479:
    goto v_27491;
v_27487:
    v_27507 = stack[0];
    goto v_27488;
v_27489:
    v_27506 = stack[-1];
    goto v_27490;
v_27491:
    goto v_27487;
v_27488:
    goto v_27489;
v_27490:
    v_27506 = difference2(v_27507, v_27506);
    env = stack[-7];
    v_27506 = Lminusp(nil, v_27506);
    env = stack[-7];
    if (v_27506 == nil) goto v_27484;
    goto v_27478;
v_27484:
    goto v_27500;
v_27496:
    v_27507 = stack[-5];
    goto v_27497;
v_27498:
    v_27506 = stack[-4];
    goto v_27499;
v_27500:
    goto v_27496;
v_27497:
    goto v_27498;
v_27499:
    fn = elt(env, 14); // diffsq
    v_27506 = (*qfn2(fn))(fn, v_27507, v_27506);
    env = stack[-7];
    stack[-5] = v_27506;
    v_27506 = stack[-1];
    v_27506 = add1(v_27506);
    env = stack[-7];
    stack[-1] = v_27506;
    goto v_27479;
v_27478:
    v_27506 = nil;
    stack[-3] = v_27506;
    goto v_27217;
v_27216:
    return onevalue(v_27506);
}



// Code for wedgewedge

static LispObject CC_wedgewedge(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27297, v_27298, v_27299;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27210;
    stack[-1] = v_27209;
// end of prologue
    stack[-2] = nil;
v_27216:
    v_27297 = stack[-1];
    v_27297 = qcdr(v_27297);
    if (v_27297 == nil) goto v_27221;
    else goto v_27222;
v_27221:
    goto v_27217;
v_27222:
    goto v_27232;
v_27226:
    goto v_27240;
v_27234:
    v_27297 = stack[-1];
    v_27299 = qcar(v_27297);
    goto v_27235;
v_27236:
    v_27298 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27237;
v_27238:
    v_27297 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27239;
v_27240:
    goto v_27234;
v_27235:
    goto v_27236;
v_27237:
    goto v_27238;
v_27239:
    v_27299 = list2star(v_27299, v_27298, v_27297);
    env = stack[-3];
    goto v_27227;
v_27228:
    v_27298 = nil;
    goto v_27229;
v_27230:
    v_27297 = stack[-2];
    goto v_27231;
v_27232:
    goto v_27226;
v_27227:
    goto v_27228;
v_27229:
    goto v_27230;
v_27231:
    v_27297 = acons(v_27299, v_27298, v_27297);
    env = stack[-3];
    stack[-2] = v_27297;
    v_27297 = stack[-1];
    v_27297 = qcdr(v_27297);
    stack[-1] = v_27297;
    goto v_27216;
v_27217:
    goto v_27254;
v_27250:
    goto v_27263;
v_27257:
    v_27297 = stack[-1];
    v_27299 = qcar(v_27297);
    goto v_27258;
v_27259:
    v_27298 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27260;
v_27261:
    v_27297 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27262;
v_27263:
    goto v_27257;
v_27258:
    goto v_27259;
v_27260:
    goto v_27261;
v_27262:
    v_27297 = list2star(v_27299, v_27298, v_27297);
    env = stack[-3];
    stack[-1] = ncons(v_27297);
    env = stack[-3];
    goto v_27251;
v_27252:
    goto v_27276;
v_27270:
    v_27299 = stack[0];
    goto v_27271;
v_27272:
    v_27298 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27273;
v_27274:
    v_27297 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27275;
v_27276:
    goto v_27270;
v_27271:
    goto v_27272;
v_27273:
    goto v_27274;
v_27275:
    v_27297 = list2star(v_27299, v_27298, v_27297);
    env = stack[-3];
    v_27297 = ncons(v_27297);
    env = stack[-3];
    goto v_27253;
v_27254:
    goto v_27250;
v_27251:
    goto v_27252;
v_27253:
    fn = elt(env, 1); // wedgepf2
    v_27297 = (*qfn2(fn))(fn, stack[-1], v_27297);
    env = stack[-3];
    v_27298 = v_27297;
v_27218:
    v_27297 = stack[-2];
    if (v_27297 == nil) goto v_27282;
    else goto v_27283;
v_27282:
    v_27297 = v_27298;
    goto v_27215;
v_27283:
    goto v_27291;
v_27287:
    v_27297 = stack[-2];
    v_27297 = qcar(v_27297);
    goto v_27288;
v_27289:
    goto v_27290;
v_27291:
    goto v_27287;
v_27288:
    goto v_27289;
v_27290:
    fn = elt(env, 1); // wedgepf2
    v_27297 = (*qfn2(fn))(fn, v_27297, v_27298);
    env = stack[-3];
    v_27298 = v_27297;
    v_27297 = stack[-2];
    v_27297 = qcdr(v_27297);
    stack[-2] = v_27297;
    goto v_27218;
v_27215:
    return onevalue(v_27297);
}



// Code for simpsetdiff

static LispObject CC_simpsetdiff(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27309, v_27310, v_27311;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27209);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_27309 = v_27209;
// end of prologue
    goto v_27216;
v_27212:
    v_27310 = elt(env, 1); // setdiff
    goto v_27213;
v_27214:
    goto v_27215;
v_27216:
    goto v_27212;
v_27213:
    goto v_27214;
v_27215:
    fn = elt(env, 3); // applysetop
    v_27309 = (*qfn2(fn))(fn, v_27310, v_27309);
    env = stack[0];
    v_27311 = v_27309;
    goto v_27225;
v_27221:
    goto v_27232;
v_27228:
    goto v_27238;
v_27234:
    goto v_27247;
v_27243:
    v_27309 = v_27311;
    v_27310 = qcar(v_27309);
    goto v_27244;
v_27245:
    v_27309 = elt(env, 1); // setdiff
    goto v_27246;
v_27247:
    goto v_27243;
v_27244:
    goto v_27245;
v_27246:
    if (v_27310 == v_27309) goto v_27241;
    else goto v_27242;
v_27241:
    goto v_27263;
v_27259:
    v_27309 = v_27311;
    v_27309 = qcdr(v_27309);
    v_27310 = qcar(v_27309);
    goto v_27260;
v_27261:
    v_27309 = v_27311;
    v_27309 = qcdr(v_27309);
    v_27309 = qcdr(v_27309);
    v_27309 = qcar(v_27309);
    goto v_27262;
v_27263:
    goto v_27259;
v_27260:
    goto v_27261;
v_27262:
    if (equal(v_27310, v_27309)) goto v_27257;
    else goto v_27258;
v_27257:
    v_27309 = lisp_true;
    goto v_27256;
v_27258:
    goto v_27278;
v_27274:
    v_27309 = v_27311;
    v_27309 = qcdr(v_27309);
    v_27310 = qcar(v_27309);
    goto v_27275;
v_27276:
    v_27309 = qvalue(elt(env, 2)); // empty_set
    goto v_27277;
v_27278:
    goto v_27274;
v_27275:
    goto v_27276;
v_27277:
    v_27309 = (equal(v_27310, v_27309) ? lisp_true : nil);
    goto v_27256;
    v_27309 = nil;
v_27256:
    if (v_27309 == nil) goto v_27254;
    v_27309 = qvalue(elt(env, 2)); // empty_set
    goto v_27252;
v_27254:
    goto v_27291;
v_27287:
    v_27309 = v_27311;
    v_27309 = qcdr(v_27309);
    v_27309 = qcdr(v_27309);
    v_27310 = qcar(v_27309);
    goto v_27288;
v_27289:
    v_27309 = qvalue(elt(env, 2)); // empty_set
    goto v_27290;
v_27291:
    goto v_27287;
v_27288:
    goto v_27289;
v_27290:
    if (equal(v_27310, v_27309)) goto v_27285;
    else goto v_27286;
v_27285:
    v_27309 = v_27311;
    v_27309 = qcdr(v_27309);
    v_27309 = qcar(v_27309);
    goto v_27252;
v_27286:
    v_27309 = v_27311;
    goto v_27252;
    v_27309 = nil;
v_27252:
    v_27310 = v_27309;
    goto v_27240;
v_27242:
    v_27309 = v_27311;
    v_27310 = v_27309;
    goto v_27240;
    v_27310 = nil;
v_27240:
    goto v_27235;
v_27236:
    v_27309 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27237;
v_27238:
    goto v_27234;
v_27235:
    goto v_27236;
v_27237:
    fn = elt(env, 4); // mksp
    v_27310 = (*qfn2(fn))(fn, v_27310, v_27309);
    env = stack[0];
    goto v_27229;
v_27230:
    v_27309 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27231;
v_27232:
    goto v_27228;
v_27229:
    goto v_27230;
v_27231:
    v_27309 = cons(v_27310, v_27309);
    env = stack[0];
    v_27310 = ncons(v_27309);
    goto v_27222;
v_27223:
    v_27309 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27224;
v_27225:
    goto v_27221;
v_27222:
    goto v_27223;
v_27224:
    return cons(v_27310, v_27309);
}



// Code for evalletsub

static LispObject CC_evalletsub(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27240, v_27241, v_27242;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_27240 = v_27210;
    stack[0] = v_27209;
// end of prologue
    goto v_27222;
v_27218:
    v_27241 = stack[0];
    goto v_27219;
v_27220:
    goto v_27221;
v_27222:
    goto v_27218;
v_27219:
    goto v_27220;
v_27221:
    fn = elt(env, 3); // evalletsub2
    v_27240 = (*qfn2(fn))(fn, v_27241, v_27240);
    env = stack[-1];
    stack[0] = v_27240;
    fn = elt(env, 4); // errorp
    v_27240 = (*qfn1(fn))(fn, v_27240);
    env = stack[-1];
    if (v_27240 == nil) goto v_27215;
    goto v_27232;
v_27226:
    v_27242 = elt(env, 1); // alg
    goto v_27227;
v_27228:
    v_27241 = (LispObject)384+TAG_FIXNUM; // 24
    goto v_27229;
v_27230:
    v_27240 = elt(env, 2); // "Invalid simplification"
    goto v_27231;
v_27232:
    goto v_27226;
v_27227:
    goto v_27228;
v_27229:
    goto v_27230;
v_27231:
    {
        fn = elt(env, 5); // rerror
        return (*qfnn(fn))(fn, 3, v_27242, v_27241, v_27240);
    }
v_27215:
    v_27240 = stack[0];
    v_27240 = qcar(v_27240);
    goto v_27213;
    v_27240 = nil;
v_27213:
    return onevalue(v_27240);
}



// Code for negex

static LispObject CC_negex(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27242, v_27243;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27209);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_27209;
// end of prologue
    stack[-2] = nil;
v_27214:
    v_27242 = stack[-1];
    if (v_27242 == nil) goto v_27217;
    else goto v_27218;
v_27217:
    v_27242 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_27242);
    }
v_27218:
    goto v_27231;
v_27225:
    v_27242 = stack[-1];
    v_27242 = qcar(v_27242);
    stack[0] = qcar(v_27242);
    goto v_27226;
v_27227:
    v_27242 = stack[-1];
    v_27242 = qcar(v_27242);
    v_27242 = qcdr(v_27242);
    fn = elt(env, 2); // negf
    v_27243 = (*qfn1(fn))(fn, v_27242);
    env = stack[-3];
    goto v_27228;
v_27229:
    v_27242 = stack[-2];
    goto v_27230;
v_27231:
    goto v_27225;
v_27226:
    goto v_27227;
v_27228:
    goto v_27229;
v_27230:
    v_27242 = acons(stack[0], v_27243, v_27242);
    env = stack[-3];
    stack[-2] = v_27242;
    v_27242 = stack[-1];
    v_27242 = qcdr(v_27242);
    stack[-1] = v_27242;
    goto v_27214;
    v_27242 = nil;
    return onevalue(v_27242);
}



// Code for ra_wrapper

static LispObject CC_ra_wrapper(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27270, v_27271, v_27272;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_27210;
    v_27271 = v_27209;
// end of prologue
    v_27270 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_27270)) v_27270 = nil;
    else { v_27270 = qfastgets(v_27270);
           if (v_27270 != nil) { v_27270 = elt(v_27270, 8); // dname
#ifdef RECORD_GET
             if (v_27270 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_27270 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_27270 == SPID_NOPROP) v_27270 = nil; }}
#endif
    stack[-3] = v_27270;
    goto v_27225;
v_27219:
    goto v_27235;
v_27227:
    stack[-1] = elt(env, 2); // ra_wrapper1
    goto v_27228;
v_27229:
    v_27270 = v_27271;
    stack[0] = Lmkquote(nil, v_27270);
    env = stack[-4];
    goto v_27230;
v_27231:
    v_27270 = stack[-2];
    stack[-2] = Lmkquote(nil, v_27270);
    env = stack[-4];
    goto v_27232;
v_27233:
    v_27270 = stack[-3];
    v_27270 = Lmkquote(nil, v_27270);
    env = stack[-4];
    goto v_27234;
v_27235:
    goto v_27227;
v_27228:
    goto v_27229;
v_27230:
    goto v_27231;
v_27232:
    goto v_27233;
v_27234:
    v_27272 = list4(stack[-1], stack[0], stack[-2], v_27270);
    env = stack[-4];
    goto v_27220;
v_27221:
    v_27271 = lisp_true;
    goto v_27222;
v_27223:
    v_27270 = qvalue(elt(env, 3)); // !*backtrace
    goto v_27224;
v_27225:
    goto v_27219;
v_27220:
    goto v_27221;
v_27222:
    goto v_27223;
v_27224:
    fn = elt(env, 5); // errorset
    v_27270 = (*qfnn(fn))(fn, 3, v_27272, v_27271, v_27270);
    env = stack[-4];
    stack[0] = v_27270;
    v_27270 = stack[0];
    fn = elt(env, 6); // errorp
    v_27270 = (*qfn1(fn))(fn, v_27270);
    env = stack[-4];
    if (v_27270 == nil) goto v_27248;
    goto v_27257;
v_27253:
    v_27271 = elt(env, 4); // "caught error - restoring domain mode"
    goto v_27254;
v_27255:
    v_27270 = stack[-3];
    goto v_27256;
v_27257:
    goto v_27253;
v_27254:
    goto v_27255;
v_27256:
    v_27270 = list2(v_27271, v_27270);
    env = stack[-4];
    fn = elt(env, 7); // lprim
    v_27270 = (*qfn1(fn))(fn, v_27270);
    env = stack[-4];
    v_27270 = stack[-3];
    if (v_27270 == nil) goto v_27263;
    v_27270 = stack[-3];
    fn = elt(env, 8); // on1
    v_27270 = (*qfn1(fn))(fn, v_27270);
    env = stack[-4];
    goto v_27261;
v_27263:
v_27261:
    Lerror0(nil, 0);
    goto v_27246;
v_27248:
v_27246:
    v_27270 = stack[0];
    v_27270 = qcar(v_27270);
    return onevalue(v_27270);
}



// Code for mri_ofsf2mri

static LispObject CC_mri_ofsf2mri(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27224, v_27225;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_27224 = v_27210;
    v_27225 = v_27209;
// end of prologue
    goto v_27219;
v_27213:
    stack[-1] = v_27225;
    goto v_27214;
v_27215:
    stack[0] = elt(env, 1); // mri_ofsf2mriat
    goto v_27216;
v_27217:
    v_27224 = ncons(v_27224);
    env = stack[-2];
    goto v_27218;
v_27219:
    goto v_27213;
v_27214:
    goto v_27215;
v_27216:
    goto v_27217;
v_27218:
    {
        LispObject v_27228 = stack[-1];
        LispObject v_27229 = stack[0];
        fn = elt(env, 2); // cl_apply2ats1
        return (*qfnn(fn))(fn, 3, v_27228, v_27229, v_27224);
    }
}



// Code for cl_bnfsimpl

static LispObject CC_cl_bnfsimpl(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27228, v_27229, v_27230;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27229 = v_27210;
    v_27230 = v_27209;
// end of prologue
    v_27228 = qvalue(elt(env, 1)); // !*rlbnfsac
    if (v_27228 == nil) goto v_27215;
    goto v_27222;
v_27218:
    v_27228 = v_27230;
    goto v_27219;
v_27220:
    goto v_27221;
v_27222:
    goto v_27218;
v_27219:
    goto v_27220;
v_27221:
    {
        fn = elt(env, 2); // cl_sac
        return (*qfn2(fn))(fn, v_27228, v_27229);
    }
v_27215:
    v_27228 = v_27230;
    goto v_27213;
    v_27228 = nil;
v_27213:
    return onevalue(v_27228);
}



// Code for vdp_getprop

static LispObject CC_vdp_getprop(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27232, v_27233;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_27232 = v_27210;
    v_27233 = v_27209;
// end of prologue
    goto v_27216;
v_27212:
    stack[0] = v_27232;
    goto v_27213;
v_27214:
    v_27232 = v_27233;
    fn = elt(env, 1); // vdp_plist
    v_27232 = (*qfn1(fn))(fn, v_27232);
    goto v_27215;
v_27216:
    goto v_27212;
v_27213:
    goto v_27214;
v_27215:
    v_27232 = Latsoc(nil, stack[0], v_27232);
    v_27233 = v_27232;
    v_27232 = v_27233;
    if (v_27232 == nil) goto v_27225;
    v_27232 = v_27233;
    v_27232 = qcdr(v_27232);
    goto v_27223;
v_27225:
    v_27232 = nil;
    goto v_27223;
    v_27232 = nil;
v_27223:
    return onevalue(v_27232);
}



// Code for matrixir

static LispObject CC_matrixir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27268, v_27269, v_27270;
    LispObject fn;
    argcheck(nargs, 0, "matrixir");
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
    fn = elt(env, 4); // lex
    v_27268 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    fn = elt(env, 5); // omobjs
    v_27268 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_27270 = v_27268;
    goto v_27223;
v_27219:
    v_27268 = v_27270;
    v_27268 = qcdr(v_27268);
    v_27268 = qcar(v_27268);
    v_27268 = qcdr(v_27268);
    v_27268 = qcar(v_27268);
    v_27269 = qcar(v_27268);
    goto v_27220;
v_27221:
    v_27268 = elt(env, 1); // matrixcolumn
    goto v_27222;
v_27223:
    goto v_27219;
v_27220:
    goto v_27221;
v_27222:
    if (v_27269 == v_27268) goto v_27217;
    else goto v_27218;
v_27217:
    goto v_27238;
v_27232:
    stack[0] = elt(env, 1); // matrixcolumn
    goto v_27233;
v_27234:
    v_27268 = v_27270;
    fn = elt(env, 6); // matrixelems
    v_27269 = (*qfn1(fn))(fn, v_27268);
    env = stack[-1];
    goto v_27235;
v_27236:
    v_27268 = nil;
    goto v_27237;
v_27238:
    goto v_27232;
v_27233:
    goto v_27234;
v_27235:
    goto v_27236;
v_27237:
    v_27268 = list2star(stack[0], v_27269, v_27268);
    env = stack[-1];
    v_27270 = v_27268;
    goto v_27216;
v_27218:
    goto v_27252;
v_27246:
    stack[0] = elt(env, 2); // matrixrow
    goto v_27247;
v_27248:
    v_27268 = v_27270;
    fn = elt(env, 6); // matrixelems
    v_27269 = (*qfn1(fn))(fn, v_27268);
    env = stack[-1];
    goto v_27249;
v_27250:
    v_27268 = nil;
    goto v_27251;
v_27252:
    goto v_27246;
v_27247:
    goto v_27248;
v_27249:
    goto v_27250;
v_27251:
    v_27268 = list2star(stack[0], v_27269, v_27268);
    env = stack[-1];
    v_27270 = v_27268;
    goto v_27216;
v_27216:
    goto v_27264;
v_27258:
    v_27269 = elt(env, 3); // matrix
    goto v_27259;
v_27260:
    v_27268 = nil;
    goto v_27261;
v_27262:
    goto v_27263;
v_27264:
    goto v_27258;
v_27259:
    goto v_27260;
v_27261:
    goto v_27262;
v_27263:
    return list2star(v_27269, v_27268, v_27270);
    return onevalue(v_27268);
}



// Code for !*rn2rd

static LispObject CC_Hrn2rd(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27216;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27209);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_27216 = v_27209;
// end of prologue
    v_27216 = qcdr(v_27216);
    fn = elt(env, 1); // r2bf
    v_27216 = (*qfn1(fn))(fn, v_27216);
    env = stack[0];
    fn = elt(env, 2); // chkrn!*
    v_27216 = (*qfn1(fn))(fn, v_27216);
    env = stack[0];
    {
        fn = elt(env, 3); // mkround
        return (*qfn1(fn))(fn, v_27216);
    }
}



// Code for prim!-part

static LispObject CC_primKpart(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27221;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27209);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_27221 = v_27209;
// end of prologue
    goto v_27216;
v_27212:
    stack[0] = v_27221;
    goto v_27213;
v_27214:
    fn = elt(env, 1); // comfac
    v_27221 = (*qfn1(fn))(fn, v_27221);
    env = stack[-1];
    fn = elt(env, 2); // comfac!-to!-poly
    v_27221 = (*qfn1(fn))(fn, v_27221);
    env = stack[-1];
    goto v_27215;
v_27216:
    goto v_27212;
v_27213:
    goto v_27214;
v_27215:
    {
        LispObject v_27223 = stack[0];
        fn = elt(env, 3); // quotf1
        return (*qfn2(fn))(fn, v_27223, v_27221);
    }
}



// Code for precision

static LispObject CC_precision(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27250, v_27251, v_27252;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27209);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27209;
// end of prologue
    v_27250 = stack[0];
    if (is_number(v_27250)) goto v_27218;
    v_27250 = lisp_true;
    goto v_27216;
v_27218:
    goto v_27228;
v_27224:
    v_27251 = stack[0];
    goto v_27225;
v_27226:
    v_27250 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27227;
v_27228:
    goto v_27224;
v_27225:
    goto v_27226;
v_27227:
    v_27250 = (LispObject)lessp2(v_27251, v_27250);
    v_27250 = v_27250 ? lisp_true : nil;
    env = stack[-1];
    goto v_27216;
    v_27250 = nil;
v_27216:
    if (v_27250 == nil) goto v_27214;
    goto v_27238;
v_27232:
    v_27252 = elt(env, 1); // arith
    goto v_27233;
v_27234:
    v_27251 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_27235;
v_27236:
    v_27250 = elt(env, 2); // "positive number required"
    goto v_27237;
v_27238:
    goto v_27232;
v_27233:
    goto v_27234;
v_27235:
    goto v_27236;
v_27237:
    fn = elt(env, 3); // rerror
    v_27250 = (*qfnn(fn))(fn, 3, v_27252, v_27251, v_27250);
    env = stack[-1];
    goto v_27212;
v_27214:
v_27212:
    goto v_27247;
v_27243:
    v_27251 = stack[0];
    goto v_27244;
v_27245:
    v_27250 = lisp_true;
    goto v_27246;
v_27247:
    goto v_27243;
v_27244:
    goto v_27245;
v_27246:
    {
        fn = elt(env, 4); // precision1
        return (*qfn2(fn))(fn, v_27251, v_27250);
    }
}



// Code for mksqrt

static LispObject CC_mksqrt(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27266, v_27267, v_27268;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27209);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27209;
// end of prologue
    v_27266 = qvalue(elt(env, 1)); // !*keepsqrts
    if (v_27266 == nil) goto v_27213;
    else goto v_27214;
v_27213:
    goto v_27223;
v_27217:
    stack[-1] = elt(env, 2); // expt
    goto v_27218;
v_27219:
    goto v_27220;
v_27221:
    goto v_27233;
v_27227:
    v_27268 = elt(env, 3); // quotient
    goto v_27228;
v_27229:
    v_27267 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27230;
v_27231:
    v_27266 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_27232;
v_27233:
    goto v_27227;
v_27228:
    goto v_27229;
v_27230:
    goto v_27231;
v_27232:
    v_27266 = list3(v_27268, v_27267, v_27266);
    goto v_27222;
v_27223:
    goto v_27217;
v_27218:
    goto v_27219;
v_27220:
    goto v_27221;
v_27222:
    {
        LispObject v_27271 = stack[-1];
        LispObject v_27272 = stack[0];
        return list3(v_27271, v_27272, v_27266);
    }
v_27214:
    v_27266 = qvalue(elt(env, 4)); // !*!*sqrt
    if (v_27266 == nil) goto v_27241;
    else goto v_27242;
v_27241:
    v_27266 = lisp_true;
    qvalue(elt(env, 4)) = v_27266; // !*!*sqrt
    goto v_27254;
v_27248:
    v_27268 = elt(env, 5); // (x)
    goto v_27249;
v_27250:
    v_27267 = lisp_true;
    goto v_27251;
v_27252:
    v_27266 = elt(env, 6); // (let00 (quote ((equal (expt (sqrt x) 2) x))))
    goto v_27253;
v_27254:
    goto v_27248;
v_27249:
    goto v_27250;
v_27251:
    goto v_27252;
v_27253:
    v_27266 = list3(v_27268, v_27267, v_27266);
    env = stack[-2];
    fn = elt(env, 8); // forall
    v_27266 = (*qfn1(fn))(fn, v_27266);
    env = stack[-2];
    fn = elt(env, 9); // aeval
    v_27266 = (*qfn1(fn))(fn, v_27266);
    env = stack[-2];
    goto v_27240;
v_27242:
v_27240:
    goto v_27263;
v_27259:
    v_27267 = elt(env, 7); // sqrt
    goto v_27260;
v_27261:
    v_27266 = stack[0];
    goto v_27262;
v_27263:
    goto v_27259;
v_27260:
    goto v_27261;
v_27262:
    return list2(v_27267, v_27266);
    v_27266 = nil;
    return onevalue(v_27266);
}



// Code for which_first

static LispObject CC_which_first(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27248, v_27249, v_27250, v_27251, v_27252;
    LispObject v_27211, v_27210, v_27209;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "which_first");
    va_start(aa, nargs);
    v_27209 = va_arg(aa, LispObject);
    v_27210 = va_arg(aa, LispObject);
    v_27211 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27249 = v_27211;
    v_27250 = v_27210;
    v_27251 = v_27209;
// end of prologue
v_27215:
    v_27248 = v_27249;
    if (v_27248 == nil) goto v_27218;
    else goto v_27219;
v_27218:
    v_27248 = nil;
    goto v_27214;
v_27219:
    goto v_27228;
v_27224:
    v_27252 = v_27251;
    goto v_27225;
v_27226:
    v_27248 = v_27249;
    v_27248 = qcar(v_27248);
    goto v_27227;
v_27228:
    goto v_27224;
v_27225:
    goto v_27226;
v_27227:
    if (equal(v_27252, v_27248)) goto v_27222;
    else goto v_27223;
v_27222:
    v_27248 = v_27251;
    goto v_27214;
v_27223:
    goto v_27239;
v_27235:
    v_27252 = v_27250;
    goto v_27236;
v_27237:
    v_27248 = v_27249;
    v_27248 = qcar(v_27248);
    goto v_27238;
v_27239:
    goto v_27235;
v_27236:
    goto v_27237;
v_27238:
    if (equal(v_27252, v_27248)) goto v_27233;
    else goto v_27234;
v_27233:
    v_27248 = v_27250;
    goto v_27214;
v_27234:
    v_27248 = v_27249;
    v_27248 = qcdr(v_27248);
    v_27249 = v_27248;
    goto v_27215;
    v_27248 = nil;
v_27214:
    return onevalue(v_27248);
}



// Code for gd_gcasesimpl

static LispObject CC_gd_gcasesimpl(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27229, v_27230;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27209);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27209;
// end of prologue
    goto v_27218;
v_27212:
    v_27229 = stack[0];
    stack[-1] = qcar(v_27229);
    goto v_27213;
v_27214:
    v_27229 = stack[0];
    v_27229 = qcdr(v_27229);
    v_27229 = qcar(v_27229);
    fn = elt(env, 1); // gd_simpl
    v_27230 = (*qfn1(fn))(fn, v_27229);
    goto v_27215;
v_27216:
    v_27229 = stack[0];
    v_27229 = qcdr(v_27229);
    v_27229 = qcdr(v_27229);
    v_27229 = qcar(v_27229);
    goto v_27217;
v_27218:
    goto v_27212;
v_27213:
    goto v_27214;
v_27215:
    goto v_27216;
v_27217:
    {
        LispObject v_27233 = stack[-1];
        return list3(v_27233, v_27230, v_27229);
    }
}



// Code for cl_pnf2!-junctor

static LispObject CC_cl_pnf2Kjunctor(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27527, v_27528, v_27529;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27209);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_27209;
// end of prologue
    stack[-7] = nil;
    stack[-6] = nil;
    v_27527 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_27527;
    v_27527 = stack[-8];
    if (!consp(v_27527)) goto v_27227;
    else goto v_27228;
v_27227:
    v_27527 = stack[-8];
    goto v_27226;
v_27228:
    v_27527 = stack[-8];
    v_27527 = qcar(v_27527);
    goto v_27226;
    v_27527 = nil;
v_27226:
    stack[-9] = v_27527;
    v_27527 = stack[-8];
    v_27527 = qcdr(v_27527);
    stack[-4] = v_27527;
    v_27527 = stack[-4];
    if (v_27527 == nil) goto v_27245;
    else goto v_27246;
v_27245:
    v_27527 = nil;
    goto v_27239;
v_27246:
    v_27527 = stack[-4];
    v_27527 = qcar(v_27527);
    fn = elt(env, 3); // cl_pnf2
    v_27527 = (*qfn1(fn))(fn, v_27527);
    env = stack[-10];
    v_27527 = ncons(v_27527);
    env = stack[-10];
    stack[-1] = v_27527;
    stack[-2] = v_27527;
v_27240:
    v_27527 = stack[-4];
    v_27527 = qcdr(v_27527);
    stack[-4] = v_27527;
    v_27527 = stack[-4];
    if (v_27527 == nil) goto v_27259;
    else goto v_27260;
v_27259:
    v_27527 = stack[-2];
    goto v_27239;
v_27260:
    goto v_27268;
v_27264:
    stack[0] = stack[-1];
    goto v_27265;
v_27266:
    v_27527 = stack[-4];
    v_27527 = qcar(v_27527);
    fn = elt(env, 3); // cl_pnf2
    v_27527 = (*qfn1(fn))(fn, v_27527);
    env = stack[-10];
    v_27527 = ncons(v_27527);
    env = stack[-10];
    goto v_27267;
v_27268:
    goto v_27264;
v_27265:
    goto v_27266;
v_27267:
    v_27527 = Lrplacd(nil, stack[0], v_27527);
    env = stack[-10];
    v_27527 = stack[-1];
    v_27527 = qcdr(v_27527);
    stack[-1] = v_27527;
    goto v_27240;
v_27239:
    v_27528 = v_27527;
    v_27527 = lisp_true;
    stack[-5] = v_27527;
    v_27527 = lisp_true;
    stack[-4] = v_27527;
    v_27527 = v_27528;
    stack[-1] = v_27527;
v_27283:
    v_27527 = stack[-1];
    if (v_27527 == nil) goto v_27287;
    else goto v_27288;
v_27287:
    goto v_27282;
v_27288:
    v_27527 = stack[-1];
    v_27527 = qcar(v_27527);
    stack[0] = v_27527;
    v_27527 = stack[0];
    v_27527 = qcar(v_27527);
    fn = elt(env, 4); // cl_qb
    v_27527 = (*qfn1(fn))(fn, v_27527);
    env = stack[-10];
    stack[-2] = v_27527;
    goto v_27306;
v_27302:
    v_27528 = stack[-2];
    goto v_27303;
v_27304:
    v_27527 = stack[-3];
    goto v_27305;
v_27306:
    goto v_27302;
v_27303:
    goto v_27304;
v_27305:
    v_27527 = (LispObject)greaterp2(v_27528, v_27527);
    v_27527 = v_27527 ? lisp_true : nil;
    env = stack[-10];
    if (v_27527 == nil) goto v_27300;
    v_27527 = stack[-2];
    stack[-3] = v_27527;
    v_27527 = lisp_true;
    stack[-5] = v_27527;
    v_27527 = lisp_true;
    stack[-4] = v_27527;
    goto v_27298;
v_27300:
v_27298:
    v_27527 = stack[0];
    v_27527 = qcdr(v_27527);
    if (v_27527 == nil) goto v_27315;
    goto v_27323;
v_27319:
    v_27527 = stack[0];
    v_27528 = qcar(v_27527);
    goto v_27320;
v_27321:
    v_27527 = stack[-7];
    goto v_27322;
v_27323:
    goto v_27319;
v_27320:
    goto v_27321;
v_27322:
    v_27527 = cons(v_27528, v_27527);
    env = stack[-10];
    stack[-7] = v_27527;
    goto v_27332;
v_27328:
    v_27527 = stack[0];
    v_27527 = qcdr(v_27527);
    v_27528 = qcar(v_27527);
    goto v_27329;
v_27330:
    v_27527 = stack[-6];
    goto v_27331;
v_27332:
    goto v_27328;
v_27329:
    goto v_27330;
v_27331:
    v_27527 = cons(v_27528, v_27527);
    env = stack[-10];
    stack[-6] = v_27527;
    goto v_27313;
v_27315:
    goto v_27344;
v_27340:
    v_27527 = stack[0];
    v_27528 = qcar(v_27527);
    goto v_27341;
v_27342:
    v_27527 = stack[-7];
    goto v_27343;
v_27344:
    goto v_27340;
v_27341:
    goto v_27342;
v_27343:
    v_27527 = cons(v_27528, v_27527);
    env = stack[-10];
    stack[-7] = v_27527;
    goto v_27353;
v_27349:
    v_27527 = stack[0];
    v_27528 = qcar(v_27527);
    goto v_27350;
v_27351:
    v_27527 = stack[-6];
    goto v_27352;
v_27353:
    goto v_27349;
v_27350:
    goto v_27351;
v_27352:
    v_27527 = cons(v_27528, v_27527);
    env = stack[-10];
    stack[-6] = v_27527;
    goto v_27313;
v_27313:
    goto v_27366;
v_27362:
    v_27528 = stack[-3];
    goto v_27363;
v_27364:
    v_27527 = stack[-2];
    goto v_27365;
v_27366:
    goto v_27362;
v_27363:
    goto v_27364;
v_27365:
    v_27527 = Leqn(nil, v_27528, v_27527);
    env = stack[-10];
    if (v_27527 == nil) goto v_27360;
    goto v_27377;
v_27373:
    v_27527 = stack[-7];
    v_27527 = qcar(v_27527);
    if (!consp(v_27527)) goto v_27380;
    else goto v_27381;
v_27380:
    v_27527 = stack[-7];
    v_27527 = qcar(v_27527);
    v_27528 = v_27527;
    goto v_27379;
v_27381:
    v_27527 = stack[-7];
    v_27527 = qcar(v_27527);
    v_27527 = qcar(v_27527);
    v_27528 = v_27527;
    goto v_27379;
    v_27528 = nil;
v_27379:
    goto v_27374;
v_27375:
    v_27527 = elt(env, 1); // all
    goto v_27376;
v_27377:
    goto v_27373;
v_27374:
    goto v_27375;
v_27376:
    if (v_27528 == v_27527) goto v_27371;
    else goto v_27372;
v_27371:
    v_27527 = nil;
    stack[-5] = v_27527;
    goto v_27370;
v_27372:
v_27370:
    goto v_27401;
v_27397:
    v_27527 = stack[-6];
    v_27527 = qcar(v_27527);
    if (!consp(v_27527)) goto v_27404;
    else goto v_27405;
v_27404:
    v_27527 = stack[-6];
    v_27527 = qcar(v_27527);
    v_27528 = v_27527;
    goto v_27403;
v_27405:
    v_27527 = stack[-6];
    v_27527 = qcar(v_27527);
    v_27527 = qcar(v_27527);
    v_27528 = v_27527;
    goto v_27403;
    v_27528 = nil;
v_27403:
    goto v_27398;
v_27399:
    v_27527 = elt(env, 2); // ex
    goto v_27400;
v_27401:
    goto v_27397;
v_27398:
    goto v_27399;
v_27400:
    if (v_27528 == v_27527) goto v_27395;
    else goto v_27396;
v_27395:
    v_27527 = nil;
    stack[-4] = v_27527;
    goto v_27394;
v_27396:
v_27394:
    goto v_27358;
v_27360:
v_27358:
    v_27527 = stack[-1];
    v_27527 = qcdr(v_27527);
    stack[-1] = v_27527;
    goto v_27283;
v_27282:
    v_27527 = stack[-7];
    v_27527 = Lnreverse(nil, v_27527);
    env = stack[-10];
    stack[-7] = v_27527;
    v_27527 = stack[-6];
    v_27527 = Lnreverse(nil, v_27527);
    env = stack[-10];
    stack[-6] = v_27527;
    goto v_27433;
v_27429:
    v_27528 = stack[-3];
    goto v_27430;
v_27431:
    v_27527 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27432;
v_27433:
    goto v_27429;
v_27430:
    goto v_27431;
v_27432:
    v_27527 = Leqn(nil, v_27528, v_27527);
    env = stack[-10];
    if (v_27527 == nil) goto v_27427;
    v_27527 = stack[-8];
    return ncons(v_27527);
v_27427:
    goto v_27446;
v_27442:
    v_27528 = stack[-5];
    goto v_27443;
v_27444:
    v_27527 = stack[-4];
    goto v_27445;
v_27446:
    goto v_27442;
v_27443:
    goto v_27444;
v_27445:
    if (equal(v_27528, v_27527)) goto v_27441;
    v_27527 = stack[-5];
    if (v_27527 == nil) goto v_27452;
    goto v_27462;
v_27456:
    v_27529 = stack[-7];
    goto v_27457;
v_27458:
    v_27528 = stack[-9];
    goto v_27459;
v_27460:
    v_27527 = elt(env, 2); // ex
    goto v_27461;
v_27462:
    goto v_27456;
v_27457:
    goto v_27458;
v_27459:
    goto v_27460;
v_27461:
    fn = elt(env, 5); // cl_interchange
    v_27527 = (*qfnn(fn))(fn, 3, v_27529, v_27528, v_27527);
    return ncons(v_27527);
v_27452:
    goto v_27476;
v_27470:
    v_27529 = stack[-6];
    goto v_27471;
v_27472:
    v_27528 = stack[-9];
    goto v_27473;
v_27474:
    v_27527 = elt(env, 1); // all
    goto v_27475;
v_27476:
    goto v_27470;
v_27471:
    goto v_27472;
v_27473:
    goto v_27474;
v_27475:
    fn = elt(env, 5); // cl_interchange
    v_27527 = (*qfnn(fn))(fn, 3, v_27529, v_27528, v_27527);
    return ncons(v_27527);
    goto v_27439;
v_27441:
v_27439:
    goto v_27487;
v_27481:
    v_27529 = stack[-7];
    goto v_27482;
v_27483:
    v_27528 = stack[-9];
    goto v_27484;
v_27485:
    v_27527 = elt(env, 2); // ex
    goto v_27486;
v_27487:
    goto v_27481;
v_27482:
    goto v_27483;
v_27484:
    goto v_27485;
v_27486:
    fn = elt(env, 5); // cl_interchange
    v_27527 = (*qfnn(fn))(fn, 3, v_27529, v_27528, v_27527);
    env = stack[-10];
    stack[0] = v_27527;
    goto v_27498;
v_27492:
    v_27529 = stack[-6];
    goto v_27493;
v_27494:
    v_27528 = stack[-9];
    goto v_27495;
v_27496:
    v_27527 = elt(env, 1); // all
    goto v_27497;
v_27498:
    goto v_27492;
v_27493:
    goto v_27494;
v_27495:
    goto v_27496;
v_27497:
    fn = elt(env, 5); // cl_interchange
    v_27527 = (*qfnn(fn))(fn, 3, v_27529, v_27528, v_27527);
    v_27529 = v_27527;
    goto v_27510;
v_27506:
    v_27527 = stack[0];
    v_27528 = qcar(v_27527);
    goto v_27507;
v_27508:
    v_27527 = v_27529;
    v_27527 = qcar(v_27527);
    goto v_27509;
v_27510:
    goto v_27506;
v_27507:
    goto v_27508;
v_27509:
    if (v_27528 == v_27527) goto v_27504;
    else goto v_27505;
v_27504:
    v_27527 = stack[0];
    return ncons(v_27527);
v_27505:
    goto v_27524;
v_27520:
    v_27527 = stack[0];
    goto v_27521;
v_27522:
    v_27528 = v_27529;
    goto v_27523;
v_27524:
    goto v_27520;
v_27521:
    goto v_27522;
v_27523:
    return list2(v_27527, v_27528);
    v_27527 = nil;
    return onevalue(v_27527);
}



// Code for mri_prifloor

static LispObject CC_mri_prifloor(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27227;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27209);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27209;
// end of prologue
    v_27227 = qvalue(elt(env, 1)); // !*nat
    if (v_27227 == nil) goto v_27213;
    else goto v_27214;
v_27213:
    v_27227 = elt(env, 2); // failed
    goto v_27212;
v_27214:
    v_27227 = elt(env, 3); // "["
    fn = elt(env, 5); // prin2!*
    v_27227 = (*qfn1(fn))(fn, v_27227);
    env = stack[-1];
    v_27227 = stack[0];
    v_27227 = qcdr(v_27227);
    v_27227 = qcar(v_27227);
    fn = elt(env, 6); // maprin
    v_27227 = (*qfn1(fn))(fn, v_27227);
    env = stack[-1];
    v_27227 = elt(env, 4); // "]"
    {
        fn = elt(env, 5); // prin2!*
        return (*qfn1(fn))(fn, v_27227);
    }
    v_27227 = nil;
v_27212:
    return onevalue(v_27227);
}



// Code for factor!-prim!-sqfree!-f

static LispObject CC_factorKprimKsqfreeKf(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27542, v_27543, v_27544;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27209);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_27209;
// end of prologue
// Binding !*msg
// FLUIDBIND: reloadenv=8 litvec-offset=1 saveloc=7
{   bind_fluid_stack bind_fluid_var(-8, 1, -7);
    qvalue(elt(env, 1)) = nil; // !*msg
    v_27542 = qvalue(elt(env, 2)); // !*rounded
    stack[-5] = v_27542;
    v_27542 = stack[-5];
    if (v_27542 == nil) goto v_27222;
    v_27542 = stack[-6];
    v_27542 = qcar(v_27542);
    fn = elt(env, 13); // univariatep
    v_27542 = (*qfn1(fn))(fn, v_27542);
    env = stack[-8];
    if (v_27542 == nil) goto v_27222;
    goto v_27239;
v_27235:
    v_27542 = stack[-6];
    v_27542 = qcar(v_27542);
    v_27542 = qcar(v_27542);
    v_27543 = qcdr(v_27542);
    goto v_27236;
v_27237:
    v_27542 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27238;
v_27239:
    goto v_27235;
v_27236:
    goto v_27237;
v_27238:
    if (v_27543 == v_27542) goto v_27233;
    else goto v_27234;
v_27233:
    goto v_27249;
v_27245:
    v_27542 = stack[-6];
    v_27543 = qcdr(v_27542);
    goto v_27246;
v_27247:
    v_27542 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27248;
v_27249:
    goto v_27245;
v_27246:
    goto v_27247;
v_27248:
    v_27542 = (v_27543 == v_27542 ? lisp_true : nil);
    goto v_27232;
v_27234:
    v_27542 = nil;
    goto v_27232;
    v_27542 = nil;
v_27232:
    if (v_27542 == nil) goto v_27222;
    v_27542 = stack[-6];
    fn = elt(env, 14); // unifactor
    v_27542 = (*qfn1(fn))(fn, v_27542);
    goto v_27216;
v_27222:
    v_27542 = stack[-5];
    if (v_27542 == nil) goto v_27261;
    else goto v_27259;
v_27261:
    v_27542 = qvalue(elt(env, 3)); // !*complex
    if (v_27542 == nil) goto v_27264;
    else goto v_27259;
v_27264:
    v_27542 = qvalue(elt(env, 4)); // !*rational
    if (v_27542 == nil) goto v_27266;
    else goto v_27259;
v_27266:
    goto v_27260;
v_27259:
    v_27542 = stack[-5];
    if (v_27542 == nil) goto v_27271;
    v_27542 = elt(env, 5); // rational
    v_27542 = ncons(v_27542);
    env = stack[-8];
    fn = elt(env, 15); // on
    v_27542 = (*qfn1(fn))(fn, v_27542);
    env = stack[-8];
    goto v_27269;
v_27271:
v_27269:
    goto v_27281;
v_27277:
    goto v_27288;
v_27284:
    v_27542 = stack[-6];
    v_27543 = qcar(v_27542);
    goto v_27285;
v_27286:
    v_27542 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27287;
v_27288:
    goto v_27284;
v_27285:
    goto v_27286;
v_27287:
    v_27542 = cons(v_27543, v_27542);
    env = stack[-8];
    fn = elt(env, 16); // resimp
    v_27542 = (*qfn1(fn))(fn, v_27542);
    env = stack[-8];
    v_27543 = qcar(v_27542);
    goto v_27278;
v_27279:
    v_27542 = stack[-6];
    v_27542 = qcdr(v_27542);
    goto v_27280;
v_27281:
    goto v_27277;
v_27278:
    goto v_27279;
v_27280:
    v_27542 = cons(v_27543, v_27542);
    env = stack[-8];
    stack[-6] = v_27542;
    goto v_27220;
v_27260:
v_27220:
    v_27542 = qvalue(elt(env, 6)); // !*limitedfactors
    if (v_27542 == nil) goto v_27297;
    else goto v_27298;
v_27297:
    v_27542 = qvalue(elt(env, 7)); // dmode!*
    if (v_27542 == nil) goto v_27302;
    else goto v_27303;
v_27302:
    v_27542 = elt(env, 8); // internal!-factorf
    stack[0] = v_27542;
    goto v_27301;
v_27303:
    goto v_27313;
v_27309:
    v_27543 = qvalue(elt(env, 7)); // dmode!*
    goto v_27310;
v_27311:
    v_27542 = elt(env, 9); // sqfrfactorfn
    goto v_27312;
v_27313:
    goto v_27309;
v_27310:
    goto v_27311;
v_27312:
    v_27542 = get(v_27543, v_27542);
    env = stack[-8];
    v_27544 = v_27542;
    goto v_27321;
v_27317:
    v_27543 = qvalue(elt(env, 7)); // dmode!*
    goto v_27318;
v_27319:
    v_27542 = elt(env, 10); // factorfn
    goto v_27320;
v_27321:
    goto v_27317;
v_27318:
    goto v_27319;
v_27320:
    v_27542 = get(v_27543, v_27542);
    env = stack[-8];
    stack[0] = v_27542;
    v_27542 = v_27544;
    if (v_27542 == nil) goto v_27327;
    goto v_27335;
v_27331:
    v_27543 = v_27544;
    goto v_27332;
v_27333:
    v_27542 = stack[0];
    goto v_27334;
v_27335:
    goto v_27331;
v_27332:
    goto v_27333;
v_27334:
    if (v_27543 == v_27542) goto v_27327;
    v_27542 = elt(env, 8); // internal!-factorf
    stack[0] = v_27542;
    goto v_27325;
v_27327:
    goto v_27345;
v_27341:
    v_27543 = stack[0];
    goto v_27342;
v_27343:
    v_27542 = elt(env, 11); // factorf
    goto v_27344;
v_27345:
    goto v_27341;
v_27342:
    goto v_27343;
v_27344:
    if (v_27543 == v_27542) goto v_27339;
    else goto v_27340;
v_27339:
    v_27542 = elt(env, 8); // internal!-factorf
    stack[0] = v_27542;
    goto v_27325;
v_27340:
v_27325:
    goto v_27301;
v_27301:
    v_27542 = stack[0];
    if (v_27542 == nil) goto v_27352;
    goto v_27359;
v_27355:
    v_27543 = stack[0];
    goto v_27356;
v_27357:
    v_27542 = stack[-6];
    v_27542 = qcar(v_27542);
    goto v_27358;
v_27359:
    goto v_27355;
v_27356:
    goto v_27357;
v_27358:
    v_27542 = Lapply1(nil, v_27543, v_27542);
    env = stack[-8];
    stack[0] = v_27542;
    goto v_27368;
v_27364:
    goto v_27374;
v_27370:
    v_27542 = stack[0];
    v_27543 = qcar(v_27542);
    goto v_27371;
v_27372:
    v_27542 = stack[-6];
    v_27542 = qcdr(v_27542);
    goto v_27373;
v_27374:
    goto v_27370;
v_27371:
    goto v_27372;
v_27373:
    fn = elt(env, 17); // exptf
    stack[-4] = (*qfn2(fn))(fn, v_27543, v_27542);
    env = stack[-8];
    goto v_27365;
v_27366:
    v_27542 = stack[0];
    v_27542 = qcdr(v_27542);
    stack[-3] = v_27542;
    v_27542 = stack[-3];
    if (v_27542 == nil) goto v_27389;
    else goto v_27390;
v_27389:
    v_27542 = nil;
    goto v_27383;
v_27390:
    v_27542 = stack[-3];
    v_27542 = qcar(v_27542);
    goto v_27402;
v_27398:
    v_27543 = qcar(v_27542);
    goto v_27399;
v_27400:
    v_27542 = stack[-6];
    v_27542 = qcdr(v_27542);
    goto v_27401;
v_27402:
    goto v_27398;
v_27399:
    goto v_27400;
v_27401:
    v_27542 = cons(v_27543, v_27542);
    env = stack[-8];
    v_27542 = ncons(v_27542);
    env = stack[-8];
    stack[-1] = v_27542;
    stack[-2] = v_27542;
v_27384:
    v_27542 = stack[-3];
    v_27542 = qcdr(v_27542);
    stack[-3] = v_27542;
    v_27542 = stack[-3];
    if (v_27542 == nil) goto v_27411;
    else goto v_27412;
v_27411:
    v_27542 = stack[-2];
    goto v_27383;
v_27412:
    goto v_27420;
v_27416:
    stack[0] = stack[-1];
    goto v_27417;
v_27418:
    v_27542 = stack[-3];
    v_27542 = qcar(v_27542);
    goto v_27431;
v_27427:
    v_27543 = qcar(v_27542);
    goto v_27428;
v_27429:
    v_27542 = stack[-6];
    v_27542 = qcdr(v_27542);
    goto v_27430;
v_27431:
    goto v_27427;
v_27428:
    goto v_27429;
v_27430:
    v_27542 = cons(v_27543, v_27542);
    env = stack[-8];
    v_27542 = ncons(v_27542);
    env = stack[-8];
    goto v_27419;
v_27420:
    goto v_27416;
v_27417:
    goto v_27418;
v_27419:
    v_27542 = Lrplacd(nil, stack[0], v_27542);
    env = stack[-8];
    v_27542 = stack[-1];
    v_27542 = qcdr(v_27542);
    stack[-1] = v_27542;
    goto v_27384;
v_27383:
    goto v_27367;
v_27368:
    goto v_27364;
v_27365:
    goto v_27366;
v_27367:
    v_27542 = cons(stack[-4], v_27542);
    env = stack[-8];
    stack[-6] = v_27542;
    goto v_27217;
v_27352:
    goto v_27296;
v_27298:
v_27296:
    goto v_27443;
v_27439:
    v_27542 = stack[-6];
    v_27543 = qcar(v_27542);
    goto v_27440;
v_27441:
    v_27542 = stack[-6];
    v_27542 = qcdr(v_27542);
    goto v_27442;
v_27443:
    goto v_27439;
v_27440:
    goto v_27441;
v_27442:
    fn = elt(env, 18); // factor!-prim!-sqfree!-f!-1
    v_27542 = (*qfn2(fn))(fn, v_27543, v_27542);
    env = stack[-8];
    stack[-6] = v_27542;
v_27217:
    v_27542 = stack[-5];
    if (v_27542 == nil) goto v_27451;
    v_27542 = elt(env, 12); // rounded
    v_27542 = ncons(v_27542);
    env = stack[-8];
    fn = elt(env, 15); // on
    v_27542 = (*qfn1(fn))(fn, v_27542);
    env = stack[-8];
    goto v_27461;
v_27457:
    v_27542 = stack[-6];
    stack[-4] = qcar(v_27542);
    goto v_27458;
v_27459:
    v_27542 = stack[-6];
    v_27542 = qcdr(v_27542);
    stack[-5] = v_27542;
    v_27542 = stack[-5];
    if (v_27542 == nil) goto v_27474;
    else goto v_27475;
v_27474:
    v_27542 = nil;
    goto v_27468;
v_27475:
    v_27542 = stack[-5];
    v_27542 = qcar(v_27542);
    stack[0] = v_27542;
    goto v_27487;
v_27483:
    goto v_27494;
v_27490:
    v_27542 = stack[0];
    v_27543 = qcar(v_27542);
    goto v_27491;
v_27492:
    v_27542 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27493;
v_27494:
    goto v_27490;
v_27491:
    goto v_27492;
v_27493:
    v_27542 = cons(v_27543, v_27542);
    env = stack[-8];
    fn = elt(env, 16); // resimp
    v_27542 = (*qfn1(fn))(fn, v_27542);
    env = stack[-8];
    v_27543 = qcar(v_27542);
    goto v_27484;
v_27485:
    v_27542 = stack[0];
    v_27542 = qcdr(v_27542);
    goto v_27486;
v_27487:
    goto v_27483;
v_27484:
    goto v_27485;
v_27486:
    v_27542 = cons(v_27543, v_27542);
    env = stack[-8];
    v_27542 = ncons(v_27542);
    env = stack[-8];
    stack[-2] = v_27542;
    stack[-3] = v_27542;
v_27469:
    v_27542 = stack[-5];
    v_27542 = qcdr(v_27542);
    stack[-5] = v_27542;
    v_27542 = stack[-5];
    if (v_27542 == nil) goto v_27505;
    else goto v_27506;
v_27505:
    v_27542 = stack[-3];
    goto v_27468;
v_27506:
    goto v_27514;
v_27510:
    stack[-1] = stack[-2];
    goto v_27511;
v_27512:
    v_27542 = stack[-5];
    v_27542 = qcar(v_27542);
    stack[0] = v_27542;
    goto v_27525;
v_27521:
    goto v_27532;
v_27528:
    v_27542 = stack[0];
    v_27543 = qcar(v_27542);
    goto v_27529;
v_27530:
    v_27542 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27531;
v_27532:
    goto v_27528;
v_27529:
    goto v_27530;
v_27531:
    v_27542 = cons(v_27543, v_27542);
    env = stack[-8];
    fn = elt(env, 16); // resimp
    v_27542 = (*qfn1(fn))(fn, v_27542);
    env = stack[-8];
    v_27543 = qcar(v_27542);
    goto v_27522;
v_27523:
    v_27542 = stack[0];
    v_27542 = qcdr(v_27542);
    goto v_27524;
v_27525:
    goto v_27521;
v_27522:
    goto v_27523;
v_27524:
    v_27542 = cons(v_27543, v_27542);
    env = stack[-8];
    v_27542 = ncons(v_27542);
    env = stack[-8];
    goto v_27513;
v_27514:
    goto v_27510;
v_27511:
    goto v_27512;
v_27513:
    v_27542 = Lrplacd(nil, stack[-1], v_27542);
    env = stack[-8];
    v_27542 = stack[-2];
    v_27542 = qcdr(v_27542);
    stack[-2] = v_27542;
    goto v_27469;
v_27468:
    goto v_27460;
v_27461:
    goto v_27457;
v_27458:
    goto v_27459;
v_27460:
    v_27542 = cons(stack[-4], v_27542);
    stack[-6] = v_27542;
    goto v_27449;
v_27451:
v_27449:
    v_27542 = stack[-6];
v_27216:
    ;}  // end of a binding scope
    return onevalue(v_27542);
}



// Code for findhc

static LispObject CC_findhc(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27333, v_27334;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27209);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_27333 = v_27209;
// end of prologue
    stack[-4] = nil;
    v_27334 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_27334; // njsi
    stack[-2] = v_27334;
    v_27334 = nil;
    qvalue(elt(env, 2)) = v_27334; // jsi
    goto v_27227;
v_27223:
    goto v_27232;
v_27228:
    stack[0] = qvalue(elt(env, 3)); // codmat
    goto v_27229;
v_27230:
    goto v_27239;
v_27235:
    v_27334 = qvalue(elt(env, 4)); // maxvar
    goto v_27236;
v_27237:
    goto v_27238;
v_27239:
    goto v_27235;
v_27236:
    goto v_27237;
v_27238:
    v_27333 = plus2(v_27334, v_27333);
    env = stack[-5];
    goto v_27231;
v_27232:
    goto v_27228;
v_27229:
    goto v_27230;
v_27231:
    v_27334 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_27333-TAG_FIXNUM)/(16/CELL)));
    goto v_27224;
v_27225:
    v_27333 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_27226;
v_27227:
    goto v_27223;
v_27224:
    goto v_27225;
v_27226:
    v_27333 = *(LispObject *)((char *)v_27334 + (CELL-TAG_VECTOR) + (((intptr_t)v_27333-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_27333;
v_27222:
    v_27333 = stack[-1];
    if (v_27333 == nil) goto v_27247;
    else goto v_27248;
v_27247:
    goto v_27221;
v_27248:
    v_27333 = stack[-1];
    v_27333 = qcar(v_27333);
    goto v_27262;
v_27258:
    goto v_27267;
v_27263:
    stack[0] = qvalue(elt(env, 3)); // codmat
    goto v_27264;
v_27265:
    goto v_27274;
v_27270:
    v_27334 = qvalue(elt(env, 4)); // maxvar
    goto v_27271;
v_27272:
    v_27333 = qcar(v_27333);
    stack[-3] = v_27333;
    goto v_27273;
v_27274:
    goto v_27270;
v_27271:
    goto v_27272;
v_27273:
    v_27333 = plus2(v_27334, v_27333);
    env = stack[-5];
    goto v_27266;
v_27267:
    goto v_27263;
v_27264:
    goto v_27265;
v_27266:
    v_27334 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_27333-TAG_FIXNUM)/(16/CELL)));
    goto v_27259;
v_27260:
    v_27333 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27261;
v_27262:
    goto v_27258;
v_27259:
    goto v_27260;
v_27261:
    v_27333 = *(LispObject *)((char *)v_27334 + (CELL-TAG_VECTOR) + (((intptr_t)v_27333-TAG_FIXNUM)/(16/CELL)));
    if (v_27333 == nil) goto v_27257;
    goto v_27286;
v_27282:
    v_27334 = stack[-3];
    goto v_27283;
v_27284:
    v_27333 = qvalue(elt(env, 2)); // jsi
    goto v_27285;
v_27286:
    goto v_27282;
v_27283:
    goto v_27284;
v_27285:
    v_27333 = cons(v_27334, v_27333);
    env = stack[-5];
    qvalue(elt(env, 2)) = v_27333; // jsi
    v_27333 = qvalue(elt(env, 1)); // njsi
    v_27333 = add1(v_27333);
    env = stack[-5];
    qvalue(elt(env, 1)) = v_27333; // njsi
    goto v_27300;
v_27296:
    goto v_27305;
v_27301:
    goto v_27310;
v_27306:
    stack[0] = qvalue(elt(env, 3)); // codmat
    goto v_27307;
v_27308:
    goto v_27317;
v_27313:
    v_27334 = qvalue(elt(env, 4)); // maxvar
    goto v_27314;
v_27315:
    v_27333 = stack[-3];
    goto v_27316;
v_27317:
    goto v_27313;
v_27314:
    goto v_27315;
v_27316:
    v_27333 = plus2(v_27334, v_27333);
    env = stack[-5];
    goto v_27309;
v_27310:
    goto v_27306;
v_27307:
    goto v_27308;
v_27309:
    v_27334 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_27333-TAG_FIXNUM)/(16/CELL)));
    goto v_27302;
v_27303:
    v_27333 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27304;
v_27305:
    goto v_27301;
v_27302:
    goto v_27303;
v_27304:
    v_27333 = *(LispObject *)((char *)v_27334 + (CELL-TAG_VECTOR) + (((intptr_t)v_27333-TAG_FIXNUM)/(16/CELL)));
    v_27333 = qcar(v_27333);
    v_27334 = qcar(v_27333);
    stack[0] = v_27334;
    goto v_27297;
v_27298:
    v_27333 = stack[-2];
    goto v_27299;
v_27300:
    goto v_27296;
v_27297:
    goto v_27298;
v_27299:
    v_27333 = (LispObject)greaterp2(v_27334, v_27333);
    v_27333 = v_27333 ? lisp_true : nil;
    env = stack[-5];
    if (v_27333 == nil) goto v_27294;
    v_27333 = stack[0];
    stack[-2] = v_27333;
    v_27333 = stack[-3];
    stack[-4] = v_27333;
    goto v_27292;
v_27294:
v_27292:
    goto v_27255;
v_27257:
v_27255:
    v_27333 = stack[-1];
    v_27333 = qcdr(v_27333);
    stack[-1] = v_27333;
    goto v_27222;
v_27221:
    v_27333 = qvalue(elt(env, 2)); // jsi
    v_27333 = Lreverse(nil, v_27333);
    env = stack[-5];
    qvalue(elt(env, 2)) = v_27333; // jsi
    v_27333 = stack[-4];
    return onevalue(v_27333);
}



// Code for dipdivmon

static LispObject CC_dipdivmon(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27262, v_27263;
    LispObject fn;
    LispObject v_27211, v_27210, v_27209;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dipdivmon");
    va_start(aa, nargs);
    v_27209 = va_arg(aa, LispObject);
    v_27210 = va_arg(aa, LispObject);
    v_27211 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27211,v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27209,v_27210,v_27211);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_27211;
    stack[-1] = v_27210;
    stack[-2] = v_27209;
// end of prologue
    stack[-3] = nil;
v_27216:
    v_27262 = stack[-2];
    if (v_27262 == nil) goto v_27219;
    else goto v_27220;
v_27219:
    v_27262 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_27262);
    }
v_27220:
    goto v_27231;
v_27227:
    goto v_27237;
v_27233:
    v_27262 = stack[-2];
    v_27263 = qcar(v_27262);
    goto v_27234;
v_27235:
    v_27262 = stack[0];
    goto v_27236;
v_27237:
    goto v_27233;
v_27234:
    goto v_27235;
v_27236:
    fn = elt(env, 2); // evdif
    v_27263 = (*qfn2(fn))(fn, v_27263, v_27262);
    env = stack[-4];
    goto v_27228;
v_27229:
    v_27262 = stack[-3];
    goto v_27230;
v_27231:
    goto v_27227;
v_27228:
    goto v_27229;
v_27230:
    v_27262 = cons(v_27263, v_27262);
    env = stack[-4];
    stack[-3] = v_27262;
    goto v_27247;
v_27243:
    goto v_27253;
v_27249:
    v_27262 = stack[-2];
    v_27262 = qcdr(v_27262);
    v_27263 = qcar(v_27262);
    goto v_27250;
v_27251:
    v_27262 = stack[-1];
    goto v_27252;
v_27253:
    goto v_27249;
v_27250:
    goto v_27251;
v_27252:
    fn = elt(env, 3); // bcquot
    v_27263 = (*qfn2(fn))(fn, v_27263, v_27262);
    env = stack[-4];
    goto v_27244;
v_27245:
    v_27262 = stack[-3];
    goto v_27246;
v_27247:
    goto v_27243;
v_27244:
    goto v_27245;
v_27246:
    v_27262 = cons(v_27263, v_27262);
    env = stack[-4];
    stack[-3] = v_27262;
    v_27262 = stack[-2];
    v_27262 = qcdr(v_27262);
    v_27262 = qcdr(v_27262);
    stack[-2] = v_27262;
    goto v_27216;
    v_27262 = nil;
    return onevalue(v_27262);
}



// Code for gfftimes

static LispObject CC_gfftimes(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27276, v_27277, v_27278;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_27277 = v_27210;
    v_27278 = v_27209;
// end of prologue
    v_27276 = v_27278;
    v_27276 = qcar(v_27276);
    stack[-4] = v_27276;
    v_27276 = v_27278;
    v_27276 = qcdr(v_27276);
    stack[-3] = v_27276;
    v_27276 = v_27277;
    v_27276 = qcar(v_27276);
    stack[-2] = v_27276;
    v_27276 = v_27277;
    v_27276 = qcdr(v_27276);
    stack[-1] = v_27276;
    goto v_27231;
v_27227:
    goto v_27237;
v_27233:
    goto v_27243;
v_27239:
    v_27277 = stack[-4];
    goto v_27240;
v_27241:
    v_27276 = stack[-2];
    goto v_27242;
v_27243:
    goto v_27239;
v_27240:
    goto v_27241;
v_27242:
    stack[0] = times2(v_27277, v_27276);
    env = stack[-5];
    goto v_27234;
v_27235:
    goto v_27251;
v_27247:
    v_27277 = stack[-3];
    goto v_27248;
v_27249:
    v_27276 = stack[-1];
    goto v_27250;
v_27251:
    goto v_27247;
v_27248:
    goto v_27249;
v_27250:
    v_27276 = times2(v_27277, v_27276);
    env = stack[-5];
    goto v_27236;
v_27237:
    goto v_27233;
v_27234:
    goto v_27235;
v_27236:
    stack[0] = difference2(stack[0], v_27276);
    env = stack[-5];
    goto v_27228;
v_27229:
    goto v_27259;
v_27255:
    goto v_27265;
v_27261:
    v_27277 = stack[-4];
    goto v_27262;
v_27263:
    v_27276 = stack[-1];
    goto v_27264;
v_27265:
    goto v_27261;
v_27262:
    goto v_27263;
v_27264:
    stack[-1] = times2(v_27277, v_27276);
    env = stack[-5];
    goto v_27256;
v_27257:
    goto v_27273;
v_27269:
    v_27277 = stack[-3];
    goto v_27270;
v_27271:
    v_27276 = stack[-2];
    goto v_27272;
v_27273:
    goto v_27269;
v_27270:
    goto v_27271;
v_27272:
    v_27276 = times2(v_27277, v_27276);
    env = stack[-5];
    goto v_27258;
v_27259:
    goto v_27255;
v_27256:
    goto v_27257;
v_27258:
    v_27276 = plus2(stack[-1], v_27276);
    goto v_27230;
v_27231:
    goto v_27227;
v_27228:
    goto v_27229;
v_27230:
    {
        LispObject v_27284 = stack[0];
        return cons(v_27284, v_27276);
    }
    return onevalue(v_27276);
}



// Code for new_prove

static LispObject CC_new_prove(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27248, v_27249;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27210;
    stack[-1] = v_27209;
// end of prologue
v_27208:
    v_27248 = stack[0];
    if (v_27248 == nil) goto v_27214;
    else goto v_27215;
v_27214:
    v_27248 = nil;
    goto v_27213;
v_27215:
    goto v_27225;
v_27221:
    v_27249 = stack[-1];
    goto v_27222;
v_27223:
    v_27248 = stack[0];
    v_27248 = qcar(v_27248);
    goto v_27224;
v_27225:
    goto v_27221;
v_27222:
    goto v_27223;
v_27224:
    fn = elt(env, 1); // new_provev
    v_27248 = (*qfn2(fn))(fn, v_27249, v_27248);
    env = stack[-2];
    v_27249 = v_27248;
    v_27248 = v_27249;
    if (v_27248 == nil) goto v_27233;
    v_27248 = v_27249;
    return ncons(v_27248);
v_27233:
    goto v_27244;
v_27240:
    v_27249 = stack[-1];
    goto v_27241;
v_27242:
    v_27248 = stack[0];
    v_27248 = qcdr(v_27248);
    goto v_27243;
v_27244:
    goto v_27240;
v_27241:
    goto v_27242;
v_27243:
    stack[-1] = v_27249;
    stack[0] = v_27248;
    goto v_27208;
    v_27248 = nil;
    goto v_27213;
    v_27248 = nil;
v_27213:
    return onevalue(v_27248);
}



// Code for mkrepart

static LispObject CC_mkrepart(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27270, v_27271;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27209);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27209;
// end of prologue
    v_27270 = stack[0];
    fn = elt(env, 2); // realvaluedp
    v_27270 = (*qfn1(fn))(fn, v_27270);
    env = stack[-1];
    if (v_27270 == nil) goto v_27214;
    goto v_27222;
v_27218:
    goto v_27229;
v_27225:
    goto v_27235;
v_27231:
    v_27271 = stack[0];
    goto v_27232;
v_27233:
    v_27270 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27234;
v_27235:
    goto v_27231;
v_27232:
    goto v_27233;
v_27234:
    fn = elt(env, 3); // to
    v_27271 = (*qfn2(fn))(fn, v_27271, v_27270);
    env = stack[-1];
    goto v_27226;
v_27227:
    v_27270 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27228;
v_27229:
    goto v_27225;
v_27226:
    goto v_27227;
v_27228:
    v_27270 = cons(v_27271, v_27270);
    env = stack[-1];
    v_27271 = ncons(v_27270);
    goto v_27219;
v_27220:
    v_27270 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27221;
v_27222:
    goto v_27218;
v_27219:
    goto v_27220;
v_27221:
    return cons(v_27271, v_27270);
v_27214:
    v_27270 = stack[0];
    fn = elt(env, 4); // sfp
    v_27270 = (*qfn1(fn))(fn, v_27270);
    env = stack[-1];
    if (v_27270 == nil) goto v_27241;
    goto v_27250;
v_27246:
    v_27271 = stack[0];
    goto v_27247;
v_27248:
    v_27270 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27249;
v_27250:
    goto v_27246;
v_27247:
    goto v_27248;
v_27249:
    v_27270 = cons(v_27271, v_27270);
    env = stack[-1];
    {
        fn = elt(env, 5); // repartsq
        return (*qfn1(fn))(fn, v_27270);
    }
v_27241:
    goto v_27260;
v_27256:
    goto v_27266;
v_27262:
    v_27271 = elt(env, 1); // repart
    goto v_27263;
v_27264:
    v_27270 = stack[0];
    goto v_27265;
v_27266:
    goto v_27262;
v_27263:
    goto v_27264;
v_27265:
    v_27271 = list2(v_27271, v_27270);
    env = stack[-1];
    goto v_27257;
v_27258:
    v_27270 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27259;
v_27260:
    goto v_27256;
v_27257:
    goto v_27258;
v_27259:
    {
        fn = elt(env, 6); // mksq
        return (*qfn2(fn))(fn, v_27271, v_27270);
    }
    v_27270 = nil;
    return onevalue(v_27270);
}



// Code for prsum

static LispObject CC_prsum(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27257, v_27258, v_27259;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27210;
    stack[-1] = v_27209;
// end of prologue
    stack[-2] = nil;
v_27215:
    v_27257 = stack[-1];
    if (v_27257 == nil) goto v_27218;
    else goto v_27219;
v_27218:
    v_27257 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_27257);
    }
v_27219:
    v_27257 = stack[0];
    v_27257 = qcar(v_27257);
    if (v_27257 == nil) goto v_27223;
    else goto v_27224;
v_27223:
    v_27257 = stack[-1];
    v_27257 = qcdr(v_27257);
    stack[-1] = v_27257;
    v_27257 = stack[0];
    v_27257 = qcdr(v_27257);
    stack[0] = v_27257;
    goto v_27215;
v_27224:
    goto v_27240;
v_27234:
    goto v_27246;
v_27242:
    v_27257 = stack[-1];
    v_27258 = qcar(v_27257);
    goto v_27243;
v_27244:
    v_27257 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27245;
v_27246:
    goto v_27242;
v_27243:
    goto v_27244;
v_27245:
    fn = elt(env, 2); // to
    v_27259 = (*qfn2(fn))(fn, v_27258, v_27257);
    env = stack[-3];
    goto v_27235;
v_27236:
    v_27257 = stack[0];
    v_27258 = qcar(v_27257);
    goto v_27237;
v_27238:
    v_27257 = stack[-2];
    goto v_27239;
v_27240:
    goto v_27234;
v_27235:
    goto v_27236;
v_27237:
    goto v_27238;
v_27239:
    v_27257 = acons(v_27259, v_27258, v_27257);
    env = stack[-3];
    stack[-2] = v_27257;
    v_27257 = stack[-1];
    v_27257 = qcdr(v_27257);
    stack[-1] = v_27257;
    v_27257 = stack[0];
    v_27257 = qcdr(v_27257);
    stack[0] = v_27257;
    goto v_27215;
    v_27257 = nil;
    return onevalue(v_27257);
}



// Code for rfirst

static LispObject CC_rfirst(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27279, v_27280, v_27281;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27209);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27209;
// end of prologue
    v_27279 = stack[0];
    v_27279 = qcar(v_27279);
    fn = elt(env, 3); // reval
    v_27279 = (*qfn1(fn))(fn, v_27279);
    env = stack[-1];
    stack[0] = v_27279;
    fn = elt(env, 4); // bagp
    v_27279 = (*qfn1(fn))(fn, v_27279);
    env = stack[-1];
    if (v_27279 == nil) goto v_27214;
    v_27279 = stack[0];
    v_27279 = qcdr(v_27279);
    if (v_27279 == nil) goto v_27221;
    else goto v_27222;
v_27221:
    v_27279 = stack[0];
    v_27279 = qcar(v_27279);
    return ncons(v_27279);
v_27222:
    goto v_27237;
v_27231:
    v_27279 = stack[0];
    v_27281 = qcar(v_27279);
    goto v_27232;
v_27233:
    v_27279 = stack[0];
    v_27279 = qcdr(v_27279);
    v_27280 = qcar(v_27279);
    goto v_27234;
v_27235:
    v_27279 = nil;
    goto v_27236;
v_27237:
    goto v_27231;
v_27232:
    goto v_27233;
v_27234:
    goto v_27235;
v_27236:
    return list2star(v_27281, v_27280, v_27279);
    v_27279 = nil;
    goto v_27212;
v_27214:
    goto v_27250;
v_27246:
    v_27279 = stack[0];
    v_27280 = qcar(v_27279);
    goto v_27247;
v_27248:
    v_27279 = elt(env, 1); // list
    goto v_27249;
v_27250:
    goto v_27246;
v_27247:
    goto v_27248;
v_27249:
    if (v_27280 == v_27279) goto v_27245;
    goto v_27259;
v_27255:
    v_27280 = stack[0];
    goto v_27256;
v_27257:
    v_27279 = elt(env, 2); // "list or bag"
    goto v_27258;
v_27259:
    goto v_27255;
v_27256:
    goto v_27257;
v_27258:
    {
        fn = elt(env, 5); // typerr
        return (*qfn2(fn))(fn, v_27280, v_27279);
    }
v_27245:
    v_27279 = stack[0];
    v_27279 = qcdr(v_27279);
    if (v_27279 == nil) goto v_27262;
    else goto v_27263;
v_27262:
    goto v_27271;
v_27267:
    v_27280 = stack[0];
    goto v_27268;
v_27269:
    v_27279 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27270;
v_27271:
    goto v_27267;
v_27268:
    goto v_27269;
v_27270:
    {
        fn = elt(env, 6); // parterr
        return (*qfn2(fn))(fn, v_27280, v_27279);
    }
v_27263:
    v_27279 = stack[0];
    v_27279 = qcdr(v_27279);
    v_27279 = qcar(v_27279);
    goto v_27212;
    v_27279 = nil;
v_27212:
    return onevalue(v_27279);
}



// Code for subs2p

static LispObject CC_subs2p(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27319, v_27320;
    LispObject fn;
    LispObject v_27211, v_27210, v_27209;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "subs2p");
    va_start(aa, nargs);
    v_27209 = va_arg(aa, LispObject);
    v_27210 = va_arg(aa, LispObject);
    v_27211 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27211,v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27209,v_27210,v_27211);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27211;
    stack[-1] = v_27210;
    stack[-2] = v_27209;
// end of prologue
    v_27319 = stack[-2];
    v_27319 = qcdr(v_27319);
    v_27319 = integerp(v_27319);
    if (v_27319 == nil) goto v_27221;
    else goto v_27222;
v_27221:
    v_27319 = lisp_true;
    goto v_27220;
v_27222:
    goto v_27233;
v_27229:
    goto v_27239;
v_27235:
    v_27319 = stack[-2];
    v_27320 = qcdr(v_27319);
    goto v_27236;
v_27237:
    v_27319 = stack[-1];
    goto v_27238;
v_27239:
    goto v_27235;
v_27236:
    goto v_27237;
v_27238:
    v_27319 = Ldivide(nil, v_27320, v_27319);
    env = stack[-3];
    stack[-1] = v_27319;
    v_27320 = qcar(v_27319);
    goto v_27230;
v_27231:
    v_27319 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27232;
v_27233:
    goto v_27229;
v_27230:
    goto v_27231;
v_27232:
    v_27319 = (v_27320 == v_27319 ? lisp_true : nil);
    goto v_27220;
    v_27319 = nil;
v_27220:
    if (v_27319 == nil) goto v_27218;
    goto v_27251;
v_27247:
    goto v_27258;
v_27254:
    v_27320 = stack[-2];
    goto v_27255;
v_27256:
    v_27319 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27257;
v_27258:
    goto v_27254;
v_27255:
    goto v_27256;
v_27257:
    v_27319 = cons(v_27320, v_27319);
    env = stack[-3];
    v_27320 = ncons(v_27319);
    goto v_27248;
v_27249:
    v_27319 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27250;
v_27251:
    goto v_27247;
v_27248:
    goto v_27249;
v_27250:
    return cons(v_27320, v_27319);
v_27218:
    goto v_27267;
v_27263:
    v_27319 = stack[0];
    fn = elt(env, 1); // simp
    v_27320 = (*qfn1(fn))(fn, v_27319);
    env = stack[-3];
    goto v_27264;
v_27265:
    v_27319 = stack[-1];
    v_27319 = qcar(v_27319);
    goto v_27266;
v_27267:
    goto v_27263;
v_27264:
    goto v_27265;
v_27266:
    fn = elt(env, 2); // exptsq
    v_27319 = (*qfn2(fn))(fn, v_27320, v_27319);
    env = stack[-3];
    stack[0] = v_27319;
    goto v_27280;
v_27276:
    v_27319 = stack[-1];
    v_27320 = qcdr(v_27319);
    goto v_27277;
v_27278:
    v_27319 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27279;
v_27280:
    goto v_27276;
v_27277:
    goto v_27278;
v_27279:
    if (v_27320 == v_27319) goto v_27274;
    else goto v_27275;
v_27274:
    v_27319 = stack[0];
    goto v_27273;
v_27275:
    goto v_27292;
v_27288:
    goto v_27298;
v_27294:
    goto v_27305;
v_27301:
    goto v_27311;
v_27307:
    v_27319 = stack[-2];
    v_27320 = qcar(v_27319);
    goto v_27308;
v_27309:
    v_27319 = stack[-1];
    v_27319 = qcdr(v_27319);
    goto v_27310;
v_27311:
    goto v_27307;
v_27308:
    goto v_27309;
v_27310:
    fn = elt(env, 3); // to
    v_27320 = (*qfn2(fn))(fn, v_27320, v_27319);
    env = stack[-3];
    goto v_27302;
v_27303:
    v_27319 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27304;
v_27305:
    goto v_27301;
v_27302:
    goto v_27303;
v_27304:
    v_27319 = cons(v_27320, v_27319);
    env = stack[-3];
    v_27320 = ncons(v_27319);
    env = stack[-3];
    goto v_27295;
v_27296:
    v_27319 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27297;
v_27298:
    goto v_27294;
v_27295:
    goto v_27296;
v_27297:
    v_27320 = cons(v_27320, v_27319);
    env = stack[-3];
    goto v_27289;
v_27290:
    v_27319 = stack[0];
    goto v_27291;
v_27292:
    goto v_27288;
v_27289:
    goto v_27290;
v_27291:
    {
        fn = elt(env, 4); // multsq
        return (*qfn2(fn))(fn, v_27320, v_27319);
    }
    v_27319 = nil;
v_27273:
    return onevalue(v_27319);
}



// Code for settreset

static LispObject CC_settreset(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27215;
    argcheck(nargs, 0, "settreset");
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
    v_27215 = nil;
    qvalue(elt(env, 1)) = v_27215; // fluidbibasisjanettreerootnode
    v_27215 = nil;
    v_27215 = ncons(v_27215);
    env = stack[0];
    qvalue(elt(env, 2)) = v_27215; // fluidbibasissett
    v_27215 = nil;
    return onevalue(v_27215);
}



// Code for lto_setminus

static LispObject CC_lto_setminus(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27286, v_27287, v_27288;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_27210;
    v_27286 = v_27209;
// end of prologue
    stack[-4] = v_27286;
v_27217:
    v_27286 = stack[-4];
    if (v_27286 == nil) goto v_27222;
    else goto v_27223;
v_27222:
    v_27286 = nil;
    goto v_27216;
v_27223:
    v_27286 = stack[-4];
    v_27286 = qcar(v_27286);
    v_27288 = v_27286;
    goto v_27237;
v_27233:
    v_27287 = v_27288;
    goto v_27234;
v_27235:
    v_27286 = stack[-3];
    goto v_27236;
v_27237:
    goto v_27233;
v_27234:
    goto v_27235;
v_27236:
    v_27286 = Lmember(nil, v_27287, v_27286);
    if (v_27286 == nil) goto v_27231;
    else goto v_27232;
v_27231:
    v_27286 = v_27288;
    v_27286 = ncons(v_27286);
    env = stack[-5];
    goto v_27230;
v_27232:
    v_27286 = nil;
v_27230:
    stack[-2] = v_27286;
    v_27286 = stack[-2];
    fn = elt(env, 1); // lastpair
    v_27286 = (*qfn1(fn))(fn, v_27286);
    env = stack[-5];
    stack[-1] = v_27286;
    v_27286 = stack[-4];
    v_27286 = qcdr(v_27286);
    stack[-4] = v_27286;
    v_27286 = stack[-1];
    if (!consp(v_27286)) goto v_27249;
    else goto v_27250;
v_27249:
    goto v_27217;
v_27250:
v_27218:
    v_27286 = stack[-4];
    if (v_27286 == nil) goto v_27254;
    else goto v_27255;
v_27254:
    v_27286 = stack[-2];
    goto v_27216;
v_27255:
    goto v_27263;
v_27259:
    stack[0] = stack[-1];
    goto v_27260;
v_27261:
    v_27286 = stack[-4];
    v_27286 = qcar(v_27286);
    v_27288 = v_27286;
    goto v_27276;
v_27272:
    v_27287 = v_27288;
    goto v_27273;
v_27274:
    v_27286 = stack[-3];
    goto v_27275;
v_27276:
    goto v_27272;
v_27273:
    goto v_27274;
v_27275:
    v_27286 = Lmember(nil, v_27287, v_27286);
    if (v_27286 == nil) goto v_27270;
    else goto v_27271;
v_27270:
    v_27286 = v_27288;
    v_27286 = ncons(v_27286);
    env = stack[-5];
    goto v_27269;
v_27271:
    v_27286 = nil;
v_27269:
    goto v_27262;
v_27263:
    goto v_27259;
v_27260:
    goto v_27261;
v_27262:
    v_27286 = Lrplacd(nil, stack[0], v_27286);
    env = stack[-5];
    v_27286 = stack[-1];
    fn = elt(env, 1); // lastpair
    v_27286 = (*qfn1(fn))(fn, v_27286);
    env = stack[-5];
    stack[-1] = v_27286;
    v_27286 = stack[-4];
    v_27286 = qcdr(v_27286);
    stack[-4] = v_27286;
    goto v_27218;
v_27216:
    return onevalue(v_27286);
}



// Code for pdiffvars

static LispObject CC_pdiffvars(LispObject env,
                         LispObject v_27210, LispObject v_27211)
{
    env = qenv(env);
    LispObject v_27248, v_27249;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27211,v_27210);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27210,v_27211);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_27211;
    v_27248 = v_27210;
// end of prologue
// Binding ind
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = v_27248; // ind
    v_27248 = qvalue(elt(env, 1)); // ind
    if (v_27248 == nil) goto v_27222;
    goto v_27229;
v_27225:
    goto v_27235;
v_27231:
    v_27249 = stack[-1];
    goto v_27232;
v_27233:
    v_27248 = qvalue(elt(env, 1)); // ind
    v_27248 = qcar(v_27248);
    goto v_27234;
v_27235:
    goto v_27231;
v_27232:
    goto v_27233;
v_27234:
    fn = elt(env, 2); // nth
    stack[0] = (*qfn2(fn))(fn, v_27249, v_27248);
    env = stack[-3];
    goto v_27226;
v_27227:
    goto v_27244;
v_27240:
    v_27248 = qvalue(elt(env, 1)); // ind
    v_27249 = qcdr(v_27248);
    goto v_27241;
v_27242:
    v_27248 = stack[-1];
    goto v_27243;
v_27244:
    goto v_27240;
v_27241:
    goto v_27242;
v_27243:
    v_27248 = CC_pdiffvars(elt(env, 0), v_27249, v_27248);
    env = stack[-3];
    goto v_27228;
v_27229:
    goto v_27225;
v_27226:
    goto v_27227;
v_27228:
    v_27248 = cons(stack[0], v_27248);
    goto v_27220;
v_27222:
    v_27248 = nil;
v_27220:
    ;}  // end of a binding scope
    return onevalue(v_27248);
}



// Code for ps!:evaluate!-next

static LispObject CC_psTevaluateKnext(LispObject env,
                         LispObject v_27210, LispObject v_27211)
{
    env = qenv(env);
    LispObject v_27265, v_27266;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27211,v_27210);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27210,v_27211);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_27211;
    v_27265 = v_27210;
// end of prologue
// Binding ps
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = v_27265; // ps
    goto v_27225;
v_27221:
    goto v_27231;
v_27227:
    goto v_27237;
v_27233:
    v_27266 = qvalue(elt(env, 1)); // ps
    goto v_27234;
v_27235:
    v_27265 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_27236;
v_27237:
    goto v_27233;
v_27234:
    goto v_27235;
v_27236:
    fn = elt(env, 3); // ps!:getv
    v_27265 = (*qfn2(fn))(fn, v_27266, v_27265);
    env = stack[-4];
    v_27266 = qcar(v_27265);
    goto v_27228;
v_27229:
    v_27265 = elt(env, 2); // ps!:erule
    goto v_27230;
v_27231:
    goto v_27227;
v_27228:
    goto v_27229;
v_27230:
    stack[0] = get(v_27266, v_27265);
    env = stack[-4];
    goto v_27222;
v_27223:
    goto v_27247;
v_27243:
    v_27265 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 4); // ps!:expression
    v_27266 = (*qfn1(fn))(fn, v_27265);
    env = stack[-4];
    goto v_27244;
v_27245:
    v_27265 = stack[-2];
    goto v_27246;
v_27247:
    goto v_27243;
v_27244:
    goto v_27245;
v_27246:
    v_27265 = list2(v_27266, v_27265);
    env = stack[-4];
    goto v_27224;
v_27225:
    goto v_27221;
v_27222:
    goto v_27223;
v_27224:
    fn = elt(env, 5); // apply
    v_27265 = (*qfn2(fn))(fn, stack[0], v_27265);
    env = stack[-4];
    stack[-1] = v_27265;
    goto v_27258;
v_27252:
    stack[0] = qvalue(elt(env, 1)); // ps
    goto v_27253;
v_27254:
    goto v_27255;
v_27256:
    v_27265 = stack[-1];
    fn = elt(env, 6); // prepsqxx
    v_27265 = (*qfn1(fn))(fn, v_27265);
    env = stack[-4];
    fn = elt(env, 7); // simp!*
    v_27265 = (*qfn1(fn))(fn, v_27265);
    env = stack[-4];
    stack[-1] = v_27265;
    goto v_27257;
v_27258:
    goto v_27252;
v_27253:
    goto v_27254;
v_27255:
    goto v_27256;
v_27257:
    fn = elt(env, 8); // ps!:set!-term
    v_27265 = (*qfnn(fn))(fn, 3, stack[0], stack[-2], v_27265);
    v_27265 = stack[-1];
    ;}  // end of a binding scope
    return onevalue(v_27265);
}



// Code for scar

static LispObject CC_scar(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27252, v_27253;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27210;
    stack[-1] = v_27209;
// end of prologue
v_27208:
    v_27252 = stack[0];
    if (!consp(v_27252)) goto v_27214;
    else goto v_27215;
v_27214:
    v_27252 = nil;
    goto v_27213;
v_27215:
    goto v_27224;
v_27220:
    v_27253 = stack[-1];
    goto v_27221;
v_27222:
    v_27252 = stack[0];
    v_27252 = qcar(v_27252);
    goto v_27223;
v_27224:
    goto v_27220;
v_27221:
    goto v_27222;
v_27223:
    if (equal(v_27253, v_27252)) goto v_27218;
    else goto v_27219;
v_27218:
    v_27252 = stack[0];
    goto v_27213;
v_27219:
    goto v_27239;
v_27235:
    v_27253 = stack[-1];
    goto v_27236;
v_27237:
    v_27252 = stack[0];
    v_27252 = qcar(v_27252);
    goto v_27238;
v_27239:
    goto v_27235;
v_27236:
    goto v_27237;
v_27238:
    v_27252 = CC_scar(elt(env, 0), v_27253, v_27252);
    env = stack[-2];
    if (v_27252 == nil) goto v_27233;
    else goto v_27232;
v_27233:
    goto v_27248;
v_27244:
    v_27253 = stack[-1];
    goto v_27245;
v_27246:
    v_27252 = stack[0];
    v_27252 = qcdr(v_27252);
    goto v_27247;
v_27248:
    goto v_27244;
v_27245:
    goto v_27246;
v_27247:
    stack[-1] = v_27253;
    stack[0] = v_27252;
    goto v_27208;
v_27232:
    goto v_27213;
    v_27252 = nil;
v_27213:
    return onevalue(v_27252);
}



// Code for partitwedge

static LispObject CC_partitwedge(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27225, v_27226;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27209);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_27226 = v_27209;
// end of prologue
    v_27225 = v_27226;
    v_27225 = qcdr(v_27225);
    if (v_27225 == nil) goto v_27213;
    else goto v_27214;
v_27213:
    v_27225 = v_27226;
    v_27225 = qcar(v_27225);
    {
        fn = elt(env, 1); // partitop
        return (*qfn1(fn))(fn, v_27225);
    }
v_27214:
    v_27225 = v_27226;
    fn = elt(env, 2); // xpndwedge
    v_27225 = (*qfn1(fn))(fn, v_27225);
    env = stack[0];
    {
        fn = elt(env, 3); // mkuniquewedge
        return (*qfn1(fn))(fn, v_27225);
    }
    v_27225 = nil;
    return onevalue(v_27225);
}



// Code for subfindices

static LispObject CC_subfindices(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27425, v_27426;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_27210;
    stack[-2] = v_27209;
// end of prologue
// Binding alglist!*
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = nil; // alglist!*
    v_27425 = nil;
    v_27425 = ncons(v_27425);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_27425; // alglist!*
    v_27425 = stack[-2];
    if (!consp(v_27425)) goto v_27223;
    else goto v_27224;
v_27223:
    v_27425 = lisp_true;
    goto v_27222;
v_27224:
    v_27425 = stack[-2];
    v_27425 = qcar(v_27425);
    v_27425 = (consp(v_27425) ? nil : lisp_true);
    goto v_27222;
    v_27425 = nil;
v_27222:
    if (v_27425 == nil) goto v_27220;
    goto v_27237;
v_27233:
    v_27426 = stack[-2];
    goto v_27234;
v_27235:
    v_27425 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27236;
v_27237:
    goto v_27233;
v_27234:
    goto v_27235;
v_27236:
    v_27425 = cons(v_27426, v_27425);
    goto v_27218;
v_27220:
    goto v_27247;
v_27243:
    goto v_27253;
v_27249:
    v_27425 = stack[-2];
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    if (!consp(v_27425)) goto v_27256;
    else goto v_27257;
v_27256:
    goto v_27267;
v_27263:
    goto v_27274;
v_27270:
    v_27425 = stack[-2];
    v_27425 = qcar(v_27425);
    v_27426 = qcar(v_27425);
    goto v_27271;
v_27272:
    v_27425 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27273;
v_27274:
    goto v_27270;
v_27271:
    goto v_27272;
v_27273:
    v_27425 = cons(v_27426, v_27425);
    env = stack[-4];
    v_27426 = ncons(v_27425);
    env = stack[-4];
    goto v_27264;
v_27265:
    v_27425 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27266;
v_27267:
    goto v_27263;
v_27264:
    goto v_27265;
v_27266:
    v_27425 = cons(v_27426, v_27425);
    env = stack[-4];
    stack[0] = v_27425;
    goto v_27255;
v_27257:
    v_27425 = stack[-2];
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    fn = elt(env, 3); // sfp
    v_27425 = (*qfn1(fn))(fn, v_27425);
    env = stack[-4];
    if (v_27425 == nil) goto v_27281;
    goto v_27292;
v_27288:
    goto v_27298;
v_27294:
    v_27425 = stack[-2];
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    v_27426 = qcar(v_27425);
    goto v_27295;
v_27296:
    v_27425 = stack[-1];
    goto v_27297;
v_27298:
    goto v_27294;
v_27295:
    goto v_27296;
v_27297:
    v_27426 = CC_subfindices(elt(env, 0), v_27426, v_27425);
    env = stack[-4];
    goto v_27289;
v_27290:
    v_27425 = stack[-2];
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    v_27425 = qcdr(v_27425);
    goto v_27291;
v_27292:
    goto v_27288;
v_27289:
    goto v_27290;
v_27291:
    fn = elt(env, 4); // exptsq
    v_27425 = (*qfn2(fn))(fn, v_27426, v_27425);
    env = stack[-4];
    stack[0] = v_27425;
    goto v_27255;
v_27281:
    v_27425 = stack[-2];
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    if (!symbolp(v_27425)) v_27425 = nil;
    else { v_27425 = qfastgets(v_27425);
           if (v_27425 != nil) { v_27425 = elt(v_27425, 16); // indexvar
#ifdef RECORD_GET
             if (v_27425 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v_27425 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v_27425 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v_27425 == SPID_NOPROP) v_27425 = nil; else v_27425 = lisp_true; }}
#endif
    if (v_27425 == nil) goto v_27309;
    goto v_27321;
v_27317:
    goto v_27328;
v_27324:
    v_27425 = stack[-2];
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    stack[0] = qcar(v_27425);
    goto v_27325;
v_27326:
    goto v_27339;
v_27335:
    v_27426 = stack[-1];
    goto v_27336;
v_27337:
    v_27425 = stack[-2];
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    v_27425 = qcdr(v_27425);
    goto v_27338;
v_27339:
    goto v_27335;
v_27336:
    goto v_27337;
v_27338:
    v_27425 = Lsubla(nil, v_27426, v_27425);
    env = stack[-4];
    goto v_27327;
v_27328:
    goto v_27324;
v_27325:
    goto v_27326;
v_27327:
    v_27425 = cons(stack[0], v_27425);
    env = stack[-4];
    fn = elt(env, 5); // simpindexvar
    v_27426 = (*qfn1(fn))(fn, v_27425);
    env = stack[-4];
    goto v_27318;
v_27319:
    v_27425 = stack[-2];
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    v_27425 = qcdr(v_27425);
    goto v_27320;
v_27321:
    goto v_27317;
v_27318:
    goto v_27319;
v_27320:
    fn = elt(env, 4); // exptsq
    v_27425 = (*qfn2(fn))(fn, v_27426, v_27425);
    env = stack[-4];
    stack[0] = v_27425;
    goto v_27255;
v_27309:
    goto v_27356;
v_27352:
    v_27425 = stack[-2];
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    v_27426 = qcar(v_27425);
    goto v_27353;
v_27354:
    v_27425 = elt(env, 2); // (wedge d partdf innerprod liedf hodge vardf)
    goto v_27355;
v_27356:
    goto v_27352;
v_27353:
    goto v_27354;
v_27355:
    v_27425 = Lmemq(nil, v_27426, v_27425);
    if (v_27425 == nil) goto v_27351;
    goto v_27369;
v_27365:
    goto v_27376;
v_27372:
    v_27426 = stack[-1];
    goto v_27373;
v_27374:
    v_27425 = stack[-2];
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    goto v_27375;
v_27376:
    goto v_27372;
v_27373:
    goto v_27374;
v_27375:
    fn = elt(env, 6); // subindk
    v_27425 = (*qfn2(fn))(fn, v_27426, v_27425);
    env = stack[-4];
    fn = elt(env, 7); // simp
    v_27426 = (*qfn1(fn))(fn, v_27425);
    env = stack[-4];
    goto v_27366;
v_27367:
    v_27425 = stack[-2];
    v_27425 = qcar(v_27425);
    v_27425 = qcar(v_27425);
    v_27425 = qcdr(v_27425);
    goto v_27368;
v_27369:
    goto v_27365;
v_27366:
    goto v_27367;
v_27368:
    fn = elt(env, 4); // exptsq
    v_27425 = (*qfn2(fn))(fn, v_27426, v_27425);
    env = stack[-4];
    stack[0] = v_27425;
    goto v_27255;
v_27351:
    goto v_27393;
v_27389:
    goto v_27400;
v_27396:
    v_27425 = stack[-2];
    v_27425 = qcar(v_27425);
    v_27426 = qcar(v_27425);
    goto v_27397;
v_27398:
    v_27425 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27399;
v_27400:
    goto v_27396;
v_27397:
    goto v_27398;
v_27399:
    v_27425 = cons(v_27426, v_27425);
    env = stack[-4];
    v_27426 = ncons(v_27425);
    env = stack[-4];
    goto v_27390;
v_27391:
    v_27425 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27392;
v_27393:
    goto v_27389;
v_27390:
    goto v_27391;
v_27392:
    v_27425 = cons(v_27426, v_27425);
    env = stack[-4];
    stack[0] = v_27425;
    goto v_27255;
    stack[0] = nil;
v_27255:
    goto v_27250;
v_27251:
    goto v_27411;
v_27407:
    v_27425 = stack[-2];
    v_27425 = qcar(v_27425);
    v_27426 = qcdr(v_27425);
    goto v_27408;
v_27409:
    v_27425 = stack[-1];
    goto v_27410;
v_27411:
    goto v_27407;
v_27408:
    goto v_27409;
v_27410:
    v_27425 = CC_subfindices(elt(env, 0), v_27426, v_27425);
    env = stack[-4];
    goto v_27252;
v_27253:
    goto v_27249;
v_27250:
    goto v_27251;
v_27252:
    fn = elt(env, 8); // multsq
    stack[0] = (*qfn2(fn))(fn, stack[0], v_27425);
    env = stack[-4];
    goto v_27244;
v_27245:
    goto v_27421;
v_27417:
    v_27425 = stack[-2];
    v_27426 = qcdr(v_27425);
    goto v_27418;
v_27419:
    v_27425 = stack[-1];
    goto v_27420;
v_27421:
    goto v_27417;
v_27418:
    goto v_27419;
v_27420:
    v_27425 = CC_subfindices(elt(env, 0), v_27426, v_27425);
    env = stack[-4];
    goto v_27246;
v_27247:
    goto v_27243;
v_27244:
    goto v_27245;
v_27246:
    fn = elt(env, 9); // addsq
    v_27425 = (*qfn2(fn))(fn, stack[0], v_27425);
    goto v_27218;
    v_27425 = nil;
v_27218:
    ;}  // end of a binding scope
    return onevalue(v_27425);
}



// Code for coeff_calc

static LispObject CC_coeff_calc(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27232, v_27233, v_27234;
    LispObject fn;
    LispObject v_27211, v_27210, v_27209;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "coeff_calc");
    va_start(aa, nargs);
    v_27209 = va_arg(aa, LispObject);
    v_27210 = va_arg(aa, LispObject);
    v_27211 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27211,v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27209,v_27210,v_27211);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_27232 = v_27211;
    v_27233 = v_27210;
    v_27234 = v_27209;
// end of prologue
    goto v_27219;
v_27215:
    stack[0] = elt(env, 1); // plus
    goto v_27216;
v_27217:
    goto v_27228;
v_27222:
    goto v_27223;
v_27224:
    goto v_27225;
v_27226:
    goto v_27227;
v_27228:
    goto v_27222;
v_27223:
    goto v_27224;
v_27225:
    goto v_27226;
v_27227:
    fn = elt(env, 2); // coeff1_calc
    v_27232 = (*qfnn(fn))(fn, 3, v_27234, v_27233, v_27232);
    env = stack[-1];
    goto v_27218;
v_27219:
    goto v_27215;
v_27216:
    goto v_27217;
v_27218:
    v_27232 = cons(stack[0], v_27232);
    env = stack[-1];
    {
        fn = elt(env, 3); // reval
        return (*qfn1(fn))(fn, v_27232);
    }
}



// Code for fs!:timescoeff

static LispObject CC_fsTtimescoeff(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27338, v_27339, v_27340, v_27341;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_27210;
    stack[-3] = v_27209;
// end of prologue
v_27208:
    v_27338 = stack[-2];
    if (v_27338 == nil) goto v_27214;
    else goto v_27215;
v_27214:
    v_27338 = nil;
    goto v_27213;
v_27215:
    goto v_27229;
v_27225:
    v_27340 = stack[-3];
    goto v_27226;
v_27227:
    goto v_27235;
v_27231:
    v_27339 = stack[-2];
    goto v_27232;
v_27233:
    v_27338 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27234;
v_27235:
    goto v_27231;
v_27232:
    goto v_27233;
v_27234:
    v_27338 = *(LispObject *)((char *)v_27339 + (CELL-TAG_VECTOR) + (((intptr_t)v_27338-TAG_FIXNUM)/(16/CELL)));
    goto v_27228;
v_27229:
    goto v_27225;
v_27226:
    goto v_27227;
v_27228:
    fn = elt(env, 3); // multsq
    v_27338 = (*qfn2(fn))(fn, v_27340, v_27338);
    env = stack[-5];
    stack[0] = v_27338;
    goto v_27247;
v_27243:
    v_27339 = stack[0];
    goto v_27244;
v_27245:
    v_27338 = elt(env, 1); // (nil . 1)
    goto v_27246;
v_27247:
    goto v_27243;
v_27244:
    goto v_27245;
v_27246:
    if (equal(v_27339, v_27338)) goto v_27241;
    else goto v_27242;
v_27241:
    v_27338 = elt(env, 2); // "zero in times"
    v_27338 = Lprint(nil, v_27338);
    env = stack[-5];
    goto v_27257;
v_27253:
    v_27340 = stack[-3];
    goto v_27254;
v_27255:
    goto v_27263;
v_27259:
    v_27339 = stack[-2];
    goto v_27260;
v_27261:
    v_27338 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_27262;
v_27263:
    goto v_27259;
v_27260:
    goto v_27261;
v_27262:
    v_27338 = *(LispObject *)((char *)v_27339 + (CELL-TAG_VECTOR) + (((intptr_t)v_27338-TAG_FIXNUM)/(16/CELL)));
    goto v_27256;
v_27257:
    goto v_27253;
v_27254:
    goto v_27255;
v_27256:
    stack[-3] = v_27340;
    stack[-2] = v_27338;
    goto v_27208;
v_27242:
    v_27338 = (LispObject)48+TAG_FIXNUM; // 3
    v_27338 = Lmkvect(nil, v_27338);
    env = stack[-5];
    stack[-4] = v_27338;
    goto v_27275;
v_27269:
    v_27340 = stack[-4];
    goto v_27270;
v_27271:
    v_27339 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27272;
v_27273:
    v_27338 = stack[0];
    goto v_27274;
v_27275:
    goto v_27269;
v_27270:
    goto v_27271;
v_27272:
    goto v_27273;
v_27274:
    *(LispObject *)((char *)v_27340 + (CELL-TAG_VECTOR) + (((intptr_t)v_27339-TAG_FIXNUM)/(16/CELL))) = v_27338;
    goto v_27285;
v_27279:
    v_27341 = stack[-4];
    goto v_27280;
v_27281:
    v_27340 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27282;
v_27283:
    goto v_27292;
v_27288:
    v_27339 = stack[-2];
    goto v_27289;
v_27290:
    v_27338 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27291;
v_27292:
    goto v_27288;
v_27289:
    goto v_27290;
v_27291:
    v_27338 = *(LispObject *)((char *)v_27339 + (CELL-TAG_VECTOR) + (((intptr_t)v_27338-TAG_FIXNUM)/(16/CELL)));
    goto v_27284;
v_27285:
    goto v_27279;
v_27280:
    goto v_27281;
v_27282:
    goto v_27283;
v_27284:
    *(LispObject *)((char *)v_27341 + (CELL-TAG_VECTOR) + (((intptr_t)v_27340-TAG_FIXNUM)/(16/CELL))) = v_27338;
    goto v_27302;
v_27296:
    v_27341 = stack[-4];
    goto v_27297;
v_27298:
    v_27340 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_27299;
v_27300:
    goto v_27309;
v_27305:
    v_27339 = stack[-2];
    goto v_27306;
v_27307:
    v_27338 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_27308;
v_27309:
    goto v_27305;
v_27306:
    goto v_27307;
v_27308:
    v_27338 = *(LispObject *)((char *)v_27339 + (CELL-TAG_VECTOR) + (((intptr_t)v_27338-TAG_FIXNUM)/(16/CELL)));
    goto v_27301;
v_27302:
    goto v_27296;
v_27297:
    goto v_27298;
v_27299:
    goto v_27300;
v_27301:
    *(LispObject *)((char *)v_27341 + (CELL-TAG_VECTOR) + (((intptr_t)v_27340-TAG_FIXNUM)/(16/CELL))) = v_27338;
    goto v_27319;
v_27313:
    stack[-1] = stack[-4];
    goto v_27314;
v_27315:
    stack[0] = (LispObject)48+TAG_FIXNUM; // 3
    goto v_27316;
v_27317:
    goto v_27327;
v_27323:
    v_27340 = stack[-3];
    goto v_27324;
v_27325:
    goto v_27333;
v_27329:
    v_27339 = stack[-2];
    goto v_27330;
v_27331:
    v_27338 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_27332;
v_27333:
    goto v_27329;
v_27330:
    goto v_27331;
v_27332:
    v_27338 = *(LispObject *)((char *)v_27339 + (CELL-TAG_VECTOR) + (((intptr_t)v_27338-TAG_FIXNUM)/(16/CELL)));
    goto v_27326;
v_27327:
    goto v_27323;
v_27324:
    goto v_27325;
v_27326:
    v_27338 = CC_fsTtimescoeff(elt(env, 0), v_27340, v_27338);
    goto v_27318;
v_27319:
    goto v_27313;
v_27314:
    goto v_27315;
v_27316:
    goto v_27317;
v_27318:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_27338;
    v_27338 = stack[-4];
    goto v_27213;
    v_27338 = nil;
v_27213:
    return onevalue(v_27338);
}



// Code for mkindxlist

static LispObject CC_mkindxlist(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27313, v_27314;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27209);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_27313 = v_27209;
// end of prologue
    stack[-4] = v_27313;
    v_27313 = stack[-4];
    if (v_27313 == nil) goto v_27220;
    else goto v_27221;
v_27220:
    v_27313 = nil;
    goto v_27215;
v_27221:
    v_27313 = stack[-4];
    v_27313 = qcar(v_27313);
    v_27314 = v_27313;
    v_27313 = v_27314;
    v_27313 = integerp(v_27313);
    if (v_27313 == nil) goto v_27231;
    v_27313 = v_27314;
    fn = elt(env, 2); // !*num2id
    v_27313 = (*qfn1(fn))(fn, v_27313);
    env = stack[-5];
    goto v_27229;
v_27231:
    v_27313 = v_27314;
    v_27313 = Lconsp(nil, v_27313);
    env = stack[-5];
    if (v_27313 == nil) goto v_27237;
    v_27313 = v_27314;
    v_27313 = qcdr(v_27313);
    v_27313 = qcar(v_27313);
    v_27313 = integerp(v_27313);
    if (v_27313 == nil) goto v_27237;
    goto v_27251;
v_27247:
    stack[0] = elt(env, 1); // minus
    goto v_27248;
v_27249:
    v_27313 = v_27314;
    v_27313 = qcdr(v_27313);
    v_27313 = qcar(v_27313);
    fn = elt(env, 2); // !*num2id
    v_27313 = (*qfn1(fn))(fn, v_27313);
    env = stack[-5];
    goto v_27250;
v_27251:
    goto v_27247;
v_27248:
    goto v_27249;
v_27250:
    v_27313 = list2(stack[0], v_27313);
    env = stack[-5];
    goto v_27229;
v_27237:
    v_27313 = v_27314;
    goto v_27229;
    v_27313 = nil;
v_27229:
    v_27313 = ncons(v_27313);
    env = stack[-5];
    stack[-2] = v_27313;
    stack[-3] = v_27313;
v_27216:
    v_27313 = stack[-4];
    v_27313 = qcdr(v_27313);
    stack[-4] = v_27313;
    v_27313 = stack[-4];
    if (v_27313 == nil) goto v_27264;
    else goto v_27265;
v_27264:
    v_27313 = stack[-3];
    goto v_27215;
v_27265:
    goto v_27273;
v_27269:
    stack[-1] = stack[-2];
    goto v_27270;
v_27271:
    v_27313 = stack[-4];
    v_27313 = qcar(v_27313);
    v_27314 = v_27313;
    v_27313 = v_27314;
    v_27313 = integerp(v_27313);
    if (v_27313 == nil) goto v_27282;
    v_27313 = v_27314;
    fn = elt(env, 2); // !*num2id
    v_27313 = (*qfn1(fn))(fn, v_27313);
    env = stack[-5];
    goto v_27280;
v_27282:
    v_27313 = v_27314;
    v_27313 = Lconsp(nil, v_27313);
    env = stack[-5];
    if (v_27313 == nil) goto v_27288;
    v_27313 = v_27314;
    v_27313 = qcdr(v_27313);
    v_27313 = qcar(v_27313);
    v_27313 = integerp(v_27313);
    if (v_27313 == nil) goto v_27288;
    goto v_27302;
v_27298:
    stack[0] = elt(env, 1); // minus
    goto v_27299;
v_27300:
    v_27313 = v_27314;
    v_27313 = qcdr(v_27313);
    v_27313 = qcar(v_27313);
    fn = elt(env, 2); // !*num2id
    v_27313 = (*qfn1(fn))(fn, v_27313);
    env = stack[-5];
    goto v_27301;
v_27302:
    goto v_27298;
v_27299:
    goto v_27300;
v_27301:
    v_27313 = list2(stack[0], v_27313);
    env = stack[-5];
    goto v_27280;
v_27288:
    v_27313 = v_27314;
    goto v_27280;
    v_27313 = nil;
v_27280:
    v_27313 = ncons(v_27313);
    env = stack[-5];
    goto v_27272;
v_27273:
    goto v_27269;
v_27270:
    goto v_27271;
v_27272:
    v_27313 = Lrplacd(nil, stack[-1], v_27313);
    env = stack[-5];
    v_27313 = stack[-2];
    v_27313 = qcdr(v_27313);
    stack[-2] = v_27313;
    goto v_27216;
v_27215:
    return onevalue(v_27313);
}



// Code for mkrootsql

static LispObject CC_mkrootsql(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27292, v_27293;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27210;
    stack[-1] = v_27209;
// end of prologue
    v_27292 = stack[-1];
    if (v_27292 == nil) goto v_27214;
    else goto v_27215;
v_27214:
    v_27292 = (LispObject)16+TAG_FIXNUM; // 1
    {
        fn = elt(env, 1); // !*d2q
        return (*qfn1(fn))(fn, v_27292);
    }
v_27215:
    goto v_27226;
v_27222:
    v_27292 = stack[-1];
    v_27292 = qcar(v_27292);
    v_27293 = qcdr(v_27292);
    goto v_27223;
v_27224:
    v_27292 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27225;
v_27226:
    goto v_27222;
v_27223:
    goto v_27224;
v_27225:
    v_27292 = (LispObject)greaterp2(v_27293, v_27292);
    v_27292 = v_27292 ? lisp_true : nil;
    env = stack[-3];
    if (v_27292 == nil) goto v_27220;
    goto v_27236;
v_27232:
    goto v_27242;
v_27238:
    goto v_27248;
v_27244:
    v_27292 = stack[-1];
    v_27292 = qcar(v_27292);
    v_27293 = qcar(v_27292);
    goto v_27245;
v_27246:
    v_27292 = stack[0];
    goto v_27247;
v_27248:
    goto v_27244;
v_27245:
    goto v_27246;
v_27247:
    fn = elt(env, 2); // mkrootsq
    v_27293 = (*qfn2(fn))(fn, v_27293, v_27292);
    env = stack[-3];
    goto v_27239;
v_27240:
    v_27292 = stack[-1];
    v_27292 = qcar(v_27292);
    v_27292 = qcdr(v_27292);
    goto v_27241;
v_27242:
    goto v_27238;
v_27239:
    goto v_27240;
v_27241:
    fn = elt(env, 3); // exptsq
    stack[-2] = (*qfn2(fn))(fn, v_27293, v_27292);
    env = stack[-3];
    goto v_27233;
v_27234:
    goto v_27261;
v_27257:
    v_27292 = stack[-1];
    v_27293 = qcdr(v_27292);
    goto v_27258;
v_27259:
    v_27292 = stack[0];
    goto v_27260;
v_27261:
    goto v_27257;
v_27258:
    goto v_27259;
v_27260:
    v_27292 = CC_mkrootsql(elt(env, 0), v_27293, v_27292);
    env = stack[-3];
    goto v_27235;
v_27236:
    goto v_27232;
v_27233:
    goto v_27234;
v_27235:
    {
        LispObject v_27297 = stack[-2];
        fn = elt(env, 4); // multsq
        return (*qfn2(fn))(fn, v_27297, v_27292);
    }
v_27220:
    goto v_27272;
v_27268:
    goto v_27278;
v_27274:
    v_27292 = stack[-1];
    v_27292 = qcar(v_27292);
    v_27293 = qcar(v_27292);
    goto v_27275;
v_27276:
    v_27292 = stack[0];
    goto v_27277;
v_27278:
    goto v_27274;
v_27275:
    goto v_27276;
v_27277:
    fn = elt(env, 2); // mkrootsq
    stack[-2] = (*qfn2(fn))(fn, v_27293, v_27292);
    env = stack[-3];
    goto v_27269;
v_27270:
    goto v_27288;
v_27284:
    v_27292 = stack[-1];
    v_27293 = qcdr(v_27292);
    goto v_27285;
v_27286:
    v_27292 = stack[0];
    goto v_27287;
v_27288:
    goto v_27284;
v_27285:
    goto v_27286;
v_27287:
    v_27292 = CC_mkrootsql(elt(env, 0), v_27293, v_27292);
    env = stack[-3];
    goto v_27271;
v_27272:
    goto v_27268;
v_27269:
    goto v_27270;
v_27271:
    {
        LispObject v_27298 = stack[-2];
        fn = elt(env, 4); // multsq
        return (*qfn2(fn))(fn, v_27298, v_27292);
    }
    v_27292 = nil;
    return onevalue(v_27292);
}



// Code for evaluate!-in!-order!-mod!-p

static LispObject CC_evaluateKinKorderKmodKp(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27278, v_27279, v_27280, v_27281;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27210;
    stack[-1] = v_27209;
// end of prologue
v_27214:
    v_27278 = stack[-1];
    if (!consp(v_27278)) goto v_27221;
    else goto v_27222;
v_27221:
    v_27278 = lisp_true;
    goto v_27220;
v_27222:
    v_27278 = stack[-1];
    v_27278 = qcar(v_27278);
    v_27278 = (consp(v_27278) ? nil : lisp_true);
    goto v_27220;
    v_27278 = nil;
v_27220:
    if (v_27278 == nil) goto v_27218;
    v_27278 = stack[-1];
    {
        fn = elt(env, 1); // !*d2n
        return (*qfn1(fn))(fn, v_27278);
    }
v_27218:
    goto v_27238;
v_27234:
    v_27278 = stack[-1];
    v_27278 = qcar(v_27278);
    v_27278 = qcar(v_27278);
    v_27279 = qcar(v_27278);
    goto v_27235;
v_27236:
    v_27278 = stack[0];
    v_27278 = qcar(v_27278);
    v_27278 = qcar(v_27278);
    goto v_27237;
v_27238:
    goto v_27234;
v_27235:
    goto v_27236;
v_27237:
    if (equal(v_27279, v_27278)) goto v_27232;
    else goto v_27233;
v_27232:
    goto v_27255;
v_27247:
    goto v_27261;
v_27257:
    v_27278 = stack[-1];
    v_27278 = qcar(v_27278);
    v_27279 = qcdr(v_27278);
    goto v_27258;
v_27259:
    v_27278 = stack[0];
    v_27278 = qcdr(v_27278);
    goto v_27260;
v_27261:
    goto v_27257;
v_27258:
    goto v_27259;
v_27260:
    v_27281 = CC_evaluateKinKorderKmodKp(elt(env, 0), v_27279, v_27278);
    env = stack[-2];
    goto v_27248;
v_27249:
    v_27278 = stack[-1];
    v_27278 = qcar(v_27278);
    v_27278 = qcar(v_27278);
    v_27280 = qcdr(v_27278);
    goto v_27250;
v_27251:
    v_27278 = stack[-1];
    v_27279 = qcdr(v_27278);
    goto v_27252;
v_27253:
    v_27278 = stack[0];
    goto v_27254;
v_27255:
    goto v_27247;
v_27248:
    goto v_27249;
v_27250:
    goto v_27251;
v_27252:
    goto v_27253;
v_27254:
    {
        fn = elt(env, 2); // horner!-rule!-in!-order!-mod!-p
        return (*qfnn(fn))(fn, 4, v_27281, v_27280, v_27279, v_27278);
    }
v_27233:
    v_27278 = stack[0];
    v_27278 = qcdr(v_27278);
    stack[0] = v_27278;
    goto v_27214;
    v_27278 = nil;
    return onevalue(v_27278);
}



// Code for coeffs

static LispObject CC_coeffs(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27357, v_27358;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27209);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_27209;
// end of prologue
    stack[-2] = nil;
    v_27357 = stack[-4];
    v_27357 = qcar(v_27357);
    v_27357 = qcar(v_27357);
    v_27357 = qcar(v_27357);
    stack[-1] = v_27357;
    v_27357 = stack[-4];
    v_27357 = qcar(v_27357);
    v_27357 = qcar(v_27357);
    v_27357 = qcdr(v_27357);
    stack[-5] = v_27357;
v_27229:
    v_27357 = stack[-4];
    if (!consp(v_27357)) goto v_27240;
    else goto v_27241;
v_27240:
    v_27357 = lisp_true;
    goto v_27239;
v_27241:
    v_27357 = stack[-4];
    v_27357 = qcar(v_27357);
    v_27357 = (consp(v_27357) ? nil : lisp_true);
    goto v_27239;
    v_27357 = nil;
v_27239:
    if (v_27357 == nil) goto v_27236;
    else goto v_27237;
v_27236:
    goto v_27253;
v_27249:
    v_27357 = stack[-4];
    v_27357 = qcar(v_27357);
    v_27357 = qcar(v_27357);
    v_27358 = qcar(v_27357);
    goto v_27250;
v_27251:
    v_27357 = stack[-1];
    goto v_27252;
v_27253:
    goto v_27249;
v_27250:
    goto v_27251;
v_27252:
    v_27357 = (v_27358 == v_27357 ? lisp_true : nil);
    goto v_27235;
v_27237:
    v_27357 = nil;
    goto v_27235;
    v_27357 = nil;
v_27235:
    if (v_27357 == nil) goto v_27232;
    else goto v_27233;
v_27232:
    goto v_27228;
v_27233:
    v_27357 = stack[-4];
    v_27357 = qcar(v_27357);
    v_27357 = qcar(v_27357);
    v_27357 = qcdr(v_27357);
    stack[-3] = v_27357;
    v_27357 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_27357;
v_27271:
    goto v_27283;
v_27279:
    goto v_27290;
v_27286:
    v_27358 = stack[-5];
    goto v_27287;
v_27288:
    v_27357 = stack[-3];
    goto v_27289;
v_27290:
    goto v_27286;
v_27287:
    goto v_27288;
v_27289:
    v_27357 = difference2(v_27358, v_27357);
    env = stack[-6];
    v_27358 = sub1(v_27357);
    env = stack[-6];
    goto v_27280;
v_27281:
    v_27357 = stack[0];
    goto v_27282;
v_27283:
    goto v_27279;
v_27280:
    goto v_27281;
v_27282:
    v_27357 = difference2(v_27358, v_27357);
    env = stack[-6];
    v_27357 = Lminusp(nil, v_27357);
    env = stack[-6];
    if (v_27357 == nil) goto v_27276;
    goto v_27270;
v_27276:
    goto v_27300;
v_27296:
    v_27358 = nil;
    goto v_27297;
v_27298:
    v_27357 = stack[-2];
    goto v_27299;
v_27300:
    goto v_27296;
v_27297:
    goto v_27298;
v_27299:
    v_27357 = cons(v_27358, v_27357);
    env = stack[-6];
    stack[-2] = v_27357;
    v_27357 = stack[0];
    v_27357 = add1(v_27357);
    env = stack[-6];
    stack[0] = v_27357;
    goto v_27271;
v_27270:
    goto v_27310;
v_27306:
    v_27357 = stack[-4];
    v_27357 = qcar(v_27357);
    v_27358 = qcdr(v_27357);
    goto v_27307;
v_27308:
    v_27357 = stack[-2];
    goto v_27309;
v_27310:
    goto v_27306;
v_27307:
    goto v_27308;
v_27309:
    v_27357 = cons(v_27358, v_27357);
    env = stack[-6];
    stack[-2] = v_27357;
    v_27357 = stack[-4];
    v_27357 = qcdr(v_27357);
    stack[-4] = v_27357;
    v_27357 = stack[-3];
    stack[-5] = v_27357;
    goto v_27229;
v_27228:
    v_27357 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_27357;
v_27321:
    goto v_27333;
v_27329:
    v_27357 = stack[-5];
    v_27358 = sub1(v_27357);
    env = stack[-6];
    goto v_27330;
v_27331:
    v_27357 = stack[0];
    goto v_27332;
v_27333:
    goto v_27329;
v_27330:
    goto v_27331;
v_27332:
    v_27357 = difference2(v_27358, v_27357);
    env = stack[-6];
    v_27357 = Lminusp(nil, v_27357);
    env = stack[-6];
    if (v_27357 == nil) goto v_27326;
    goto v_27320;
v_27326:
    goto v_27343;
v_27339:
    v_27358 = nil;
    goto v_27340;
v_27341:
    v_27357 = stack[-2];
    goto v_27342;
v_27343:
    goto v_27339;
v_27340:
    goto v_27341;
v_27342:
    v_27357 = cons(v_27358, v_27357);
    env = stack[-6];
    stack[-2] = v_27357;
    v_27357 = stack[0];
    v_27357 = add1(v_27357);
    env = stack[-6];
    stack[0] = v_27357;
    goto v_27321;
v_27320:
    goto v_27354;
v_27350:
    v_27358 = stack[-4];
    goto v_27351;
v_27352:
    v_27357 = stack[-2];
    goto v_27353;
v_27354:
    goto v_27350;
v_27351:
    goto v_27352;
v_27353:
    v_27357 = cons(v_27358, v_27357);
        return Lnreverse(nil, v_27357);
    return onevalue(v_27357);
}



// Code for valuechk

static LispObject CC_valuechk(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27376, v_27377, v_27378;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_27210;
    stack[-2] = v_27209;
// end of prologue
    v_27376 = stack[-2];
    if (!symbolp(v_27376)) v_27376 = nil;
    else { v_27376 = qfastgets(v_27376);
           if (v_27376 != nil) { v_27376 = elt(v_27376, 42); // number!-of!-args
#ifdef RECORD_GET
             if (v_27376 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v_27376 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v_27376 == SPID_NOPROP) v_27376 = nil; }}
#endif
    stack[0] = v_27376;
    if (v_27376 == nil) goto v_27219;
    goto v_27232;
v_27228:
    v_27376 = stack[-1];
    v_27377 = Llength(nil, v_27376);
    env = stack[-4];
    goto v_27229;
v_27230:
    v_27376 = stack[0];
    goto v_27231;
v_27232:
    goto v_27228;
v_27229:
    goto v_27230;
v_27231:
    if (equal(v_27377, v_27376)) goto v_27227;
    goto v_27241;
v_27237:
    v_27377 = stack[-2];
    goto v_27238;
v_27239:
    v_27376 = elt(env, 1); // variadic
    goto v_27240;
v_27241:
    goto v_27237;
v_27238:
    goto v_27239;
v_27240:
    v_27376 = Lflagp(nil, v_27377, v_27376);
    env = stack[-4];
    v_27376 = (v_27376 == nil ? lisp_true : nil);
    goto v_27225;
v_27227:
    v_27376 = nil;
    goto v_27225;
    v_27376 = nil;
v_27225:
    if (v_27376 == nil) goto v_27219;
    goto v_27217;
v_27219:
    v_27376 = stack[0];
    if (v_27376 == nil) goto v_27251;
    else goto v_27252;
v_27251:
    v_27376 = stack[-1];
    if (v_27376 == nil) goto v_27256;
    else goto v_27257;
v_27256:
    v_27376 = nil;
    goto v_27255;
v_27257:
    v_27376 = stack[-1];
    v_27376 = qcdr(v_27376);
    if (v_27376 == nil) goto v_27264;
    else goto v_27265;
v_27264:
    v_27376 = nil;
    goto v_27263;
v_27265:
    goto v_27279;
v_27275:
    v_27377 = stack[-2];
    goto v_27276;
v_27277:
    v_27376 = elt(env, 2); // !:rd!:
    goto v_27278;
v_27279:
    goto v_27275;
v_27276:
    goto v_27277;
v_27278:
    v_27376 = get(v_27377, v_27376);
    env = stack[-4];
    if (v_27376 == nil) goto v_27273;
    else goto v_27272;
v_27273:
    goto v_27287;
v_27283:
    v_27377 = stack[-2];
    goto v_27284;
v_27285:
    v_27376 = elt(env, 3); // !:rn!:
    goto v_27286;
v_27287:
    goto v_27283;
v_27284:
    goto v_27285;
v_27286:
    v_27376 = get(v_27377, v_27376);
    env = stack[-4];
v_27272:
    goto v_27263;
    v_27376 = nil;
v_27263:
    goto v_27255;
    v_27376 = nil;
v_27255:
    goto v_27250;
v_27252:
    v_27376 = nil;
    goto v_27250;
    v_27376 = nil;
v_27250:
    if (v_27376 == nil) goto v_27248;
    else goto v_27217;
v_27248:
    goto v_27218;
v_27217:
    v_27376 = qvalue(elt(env, 4)); // !*strict_argcount
    if (v_27376 == nil) goto v_27296;
    goto v_27305;
v_27299:
    stack[-3] = elt(env, 5); // alg
    goto v_27300;
v_27301:
    stack[0] = (LispObject)272+TAG_FIXNUM; // 17
    goto v_27302;
v_27303:
    goto v_27313;
v_27309:
    v_27377 = elt(env, 6); // "Wrong number of arguments to"
    goto v_27310;
v_27311:
    v_27376 = stack[-2];
    goto v_27312;
v_27313:
    goto v_27309;
v_27310:
    goto v_27311;
v_27312:
    v_27376 = list2(v_27377, v_27376);
    env = stack[-4];
    goto v_27304;
v_27305:
    goto v_27299;
v_27300:
    goto v_27301;
v_27302:
    goto v_27303;
v_27304:
    fn = elt(env, 8); // rerror
    v_27376 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_27376);
    env = stack[-4];
    goto v_27294;
v_27296:
    goto v_27324;
v_27320:
    v_27377 = elt(env, 6); // "Wrong number of arguments to"
    goto v_27321;
v_27322:
    v_27376 = stack[-2];
    goto v_27323;
v_27324:
    goto v_27320;
v_27321:
    goto v_27322;
v_27323:
    v_27376 = list2(v_27377, v_27376);
    env = stack[-4];
    fn = elt(env, 9); // lprim
    v_27376 = (*qfn1(fn))(fn, v_27376);
    env = stack[-4];
    goto v_27294;
v_27294:
    goto v_27216;
v_27218:
v_27216:
    goto v_27333;
v_27329:
    v_27377 = stack[-2];
    goto v_27330;
v_27331:
    v_27376 = stack[-1];
    goto v_27332;
v_27333:
    goto v_27329;
v_27330:
    goto v_27331;
v_27332:
    v_27376 = cons(v_27377, v_27376);
    env = stack[-4];
    fn = elt(env, 10); // opfchk!!
    v_27376 = (*qfn1(fn))(fn, v_27376);
    env = stack[-4];
    stack[-1] = v_27376;
    v_27376 = stack[-1];
    if (v_27376 == nil) goto v_27339;
    goto v_27347;
v_27343:
    goto v_27357;
v_27353:
    v_27377 = stack[-1];
    goto v_27354;
v_27355:
    v_27376 = elt(env, 7); // list
    goto v_27356;
v_27357:
    goto v_27353;
v_27354:
    goto v_27355;
v_27356:
    if (!consp(v_27377)) goto v_27351;
    v_27377 = qcar(v_27377);
    if (v_27377 == v_27376) goto v_27350;
    else goto v_27351;
v_27350:
    goto v_27368;
v_27362:
    v_27378 = stack[-1];
    goto v_27363;
v_27364:
    v_27377 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27365;
v_27366:
    v_27376 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27367;
v_27368:
    goto v_27362;
v_27363:
    goto v_27364;
v_27365:
    goto v_27366;
v_27367:
    v_27376 = acons(v_27378, v_27377, v_27376);
    env = stack[-4];
    v_27376 = ncons(v_27376);
    env = stack[-4];
    v_27377 = v_27376;
    goto v_27349;
v_27351:
    v_27376 = stack[-1];
    v_27377 = v_27376;
    goto v_27349;
    v_27377 = nil;
v_27349:
    goto v_27344;
v_27345:
    v_27376 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27346;
v_27347:
    goto v_27343;
v_27344:
    goto v_27345;
v_27346:
    v_27376 = cons(v_27377, v_27376);
    env = stack[-4];
    {
        fn = elt(env, 11); // znumrnil
        return (*qfn1(fn))(fn, v_27376);
    }
v_27339:
    v_27376 = nil;
    return onevalue(v_27376);
}



// Code for iv_new

static LispObject CC_iv_new(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27237, v_27238, v_27239;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
// copy arguments values to proper place
    v_27238 = v_27210;
    v_27239 = v_27209;
// end of prologue
    goto v_27218;
v_27214:
    v_27237 = v_27239;
    if (v_27237 == nil) goto v_27222;
    v_27237 = v_27239;
    v_27239 = v_27237;
    goto v_27220;
v_27222:
    v_27237 = (LispObject)0+TAG_FIXNUM; // 0
    v_27239 = v_27237;
    goto v_27220;
    v_27239 = nil;
v_27220:
    goto v_27215;
v_27216:
    v_27237 = v_27238;
    if (v_27237 == nil) goto v_27231;
    v_27237 = v_27238;
    goto v_27229;
v_27231:
    v_27237 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27229;
    v_27237 = nil;
v_27229:
    goto v_27217;
v_27218:
    goto v_27214;
v_27215:
    goto v_27216;
v_27217:
    v_27237 = cons(v_27239, v_27237);
    return ncons(v_27237);
}



// Code for ofsf_optfindeqsol

static LispObject CC_ofsf_optfindeqsol(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27302, v_27303;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_27210;
    stack[-2] = v_27209;
// end of prologue
v_27208:
    v_27302 = stack[-2];
    v_27302 = qcar(v_27302);
    stack[-3] = v_27302;
    goto v_27230;
v_27226:
    v_27302 = stack[-3];
    v_27303 = qcar(v_27302);
    goto v_27227;
v_27228:
    v_27302 = elt(env, 1); // equal
    goto v_27229;
v_27230:
    goto v_27226;
v_27227:
    goto v_27228;
v_27229:
    if (v_27303 == v_27302) goto v_27224;
    else goto v_27225;
v_27224:
    goto v_27238;
v_27234:
    stack[0] = stack[-1];
    goto v_27235;
v_27236:
    v_27302 = stack[-3];
    fn = elt(env, 2); // ofsf_varlat
    v_27302 = (*qfn1(fn))(fn, v_27302);
    env = stack[-4];
    goto v_27237;
v_27238:
    goto v_27234;
v_27235:
    goto v_27236;
v_27237:
    v_27302 = Lmemq(nil, stack[0], v_27302);
    goto v_27223;
v_27225:
    v_27302 = nil;
    goto v_27223;
    v_27302 = nil;
v_27223:
    if (v_27302 == nil) goto v_27221;
    goto v_27251;
v_27247:
    v_27302 = stack[-3];
    v_27302 = qcdr(v_27302);
    v_27303 = qcar(v_27302);
    goto v_27248;
v_27249:
    v_27302 = stack[-1];
    goto v_27250;
v_27251:
    goto v_27247;
v_27248:
    goto v_27249;
v_27250:
    fn = elt(env, 3); // ofsf_optmksol
    v_27302 = (*qfn2(fn))(fn, v_27303, v_27302);
    env = stack[-4];
    stack[-1] = v_27302;
    goto v_27261;
v_27257:
    stack[-2] = stack[-3];
    goto v_27258;
v_27259:
    goto v_27268;
v_27264:
    goto v_27274;
v_27270:
    v_27302 = stack[-1];
    v_27303 = qcar(v_27302);
    goto v_27271;
v_27272:
    v_27302 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27273;
v_27274:
    goto v_27270;
v_27271:
    goto v_27272;
v_27273:
    stack[0] = cons(v_27303, v_27302);
    env = stack[-4];
    goto v_27265;
v_27266:
    goto v_27283;
v_27279:
    v_27302 = stack[-1];
    v_27303 = qcdr(v_27302);
    goto v_27280;
v_27281:
    v_27302 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27282;
v_27283:
    goto v_27279;
v_27280:
    goto v_27281;
v_27282:
    v_27302 = cons(v_27303, v_27302);
    env = stack[-4];
    goto v_27267;
v_27268:
    goto v_27264;
v_27265:
    goto v_27266;
v_27267:
    fn = elt(env, 4); // quotsq
    v_27302 = (*qfn2(fn))(fn, stack[0], v_27302);
    goto v_27260;
v_27261:
    goto v_27257;
v_27258:
    goto v_27259;
v_27260:
    {
        LispObject v_27308 = stack[-2];
        return cons(v_27308, v_27302);
    }
v_27221:
    v_27302 = stack[-2];
    v_27302 = qcdr(v_27302);
    if (v_27302 == nil) goto v_27290;
    goto v_27298;
v_27294:
    v_27302 = stack[-2];
    v_27303 = qcdr(v_27302);
    goto v_27295;
v_27296:
    v_27302 = stack[-1];
    goto v_27297;
v_27298:
    goto v_27294;
v_27295:
    goto v_27296;
v_27297:
    stack[-2] = v_27303;
    stack[-1] = v_27302;
    goto v_27208;
v_27290:
    v_27302 = nil;
    return onevalue(v_27302);
}



// Code for csymbolrd

static LispObject CC_csymbolrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27231, v_27232, v_27233;
    LispObject fn;
    argcheck(nargs, 0, "csymbolrd");
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
    fn = elt(env, 1); // fnrd
    v_27231 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_27231;
    fn = elt(env, 2); // stats_getargs
    v_27231 = (*qfnn(fn))(fn, 0);
    goto v_27227;
v_27221:
    v_27233 = stack[0];
    goto v_27222;
v_27223:
    v_27232 = nil;
    goto v_27224;
v_27225:
    goto v_27226;
v_27227:
    goto v_27221;
v_27222:
    goto v_27223;
v_27224:
    goto v_27225;
v_27226:
    return list2star(v_27233, v_27232, v_27231);
    return onevalue(v_27231);
}



// Code for sc_scalarproduct

static LispObject CC_sc_scalarproduct(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27275, v_27276, v_27277;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27209,v_27210);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_27210;
    stack[-3] = v_27209;
// end of prologue
    v_27275 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 1); // sc_simp
    v_27275 = (*qfn1(fn))(fn, v_27275);
    env = stack[-5];
    stack[0] = v_27275;
    v_27275 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_27275;
v_27220:
    goto v_27232;
v_27228:
    v_27275 = stack[-2];
    fn = elt(env, 2); // fast!-row!-dim
    v_27276 = (*qfn1(fn))(fn, v_27275);
    env = stack[-5];
    goto v_27229;
v_27230:
    v_27275 = stack[-4];
    goto v_27231;
v_27232:
    goto v_27228;
v_27229:
    goto v_27230;
v_27231:
    v_27275 = difference2(v_27276, v_27275);
    env = stack[-5];
    v_27275 = Lminusp(nil, v_27275);
    env = stack[-5];
    if (v_27275 == nil) goto v_27225;
    goto v_27219;
v_27225:
    goto v_27242;
v_27238:
    stack[-1] = stack[0];
    goto v_27239;
v_27240:
    goto v_27249;
v_27245:
    goto v_27257;
v_27251:
    v_27277 = stack[-3];
    goto v_27252;
v_27253:
    v_27276 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27254;
v_27255:
    v_27275 = stack[-4];
    goto v_27256;
v_27257:
    goto v_27251;
v_27252:
    goto v_27253;
v_27254:
    goto v_27255;
v_27256:
    fn = elt(env, 3); // sc_getmat
    stack[0] = (*qfnn(fn))(fn, 3, v_27277, v_27276, v_27275);
    env = stack[-5];
    goto v_27246;
v_27247:
    goto v_27268;
v_27262:
    v_27277 = stack[-2];
    goto v_27263;
v_27264:
    v_27276 = stack[-4];
    goto v_27265;
v_27266:
    v_27275 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27267;
v_27268:
    goto v_27262;
v_27263:
    goto v_27264;
v_27265:
    goto v_27266;
v_27267:
    fn = elt(env, 3); // sc_getmat
    v_27275 = (*qfnn(fn))(fn, 3, v_27277, v_27276, v_27275);
    env = stack[-5];
    goto v_27248;
v_27249:
    goto v_27245;
v_27246:
    goto v_27247;
v_27248:
    fn = elt(env, 4); // sc_multsq
    v_27275 = (*qfn2(fn))(fn, stack[0], v_27275);
    env = stack[-5];
    goto v_27241;
v_27242:
    goto v_27238;
v_27239:
    goto v_27240;
v_27241:
    fn = elt(env, 5); // sc_addsq
    v_27275 = (*qfn2(fn))(fn, stack[-1], v_27275);
    env = stack[-5];
    stack[0] = v_27275;
    v_27275 = stack[-4];
    v_27275 = add1(v_27275);
    env = stack[-5];
    stack[-4] = v_27275;
    goto v_27220;
v_27219:
    v_27275 = stack[0];
    return onevalue(v_27275);
}



// Code for fortassign

static LispObject CC_fortassign(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27224, v_27225;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27224 = v_27209;
// end of prologue
    goto v_27216;
v_27212:
    v_27225 = v_27224;
    v_27225 = qcdr(v_27225);
    v_27225 = qcar(v_27225);
    goto v_27213;
v_27214:
    v_27224 = qcdr(v_27224);
    v_27224 = qcdr(v_27224);
    v_27224 = qcar(v_27224);
    goto v_27215;
v_27216:
    goto v_27212;
v_27213:
    goto v_27214;
v_27215:
    {
        fn = elt(env, 1); // mkffortassign
        return (*qfn2(fn))(fn, v_27225, v_27224);
    }
}



// Code for ordpl

static LispObject CC_ordpl(LispObject env,
                         LispObject v_27209, LispObject v_27210)
{
    env = qenv(env);
    LispObject v_27259, v_27260, v_27261, v_27262;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27260 = v_27210;
    v_27261 = v_27209;
// end of prologue
v_27214:
    v_27259 = v_27261;
    if (!consp(v_27259)) goto v_27217;
    else goto v_27218;
v_27217:
    goto v_27225;
v_27221:
    v_27259 = v_27261;
    goto v_27222;
v_27223:
    goto v_27224;
v_27225:
    goto v_27221;
v_27222:
    goto v_27223;
v_27224:
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_27259, v_27260);
    }
v_27218:
    v_27259 = v_27260;
    if (!consp(v_27259)) goto v_27228;
    else goto v_27229;
v_27228:
    v_27259 = lisp_true;
    goto v_27213;
v_27229:
    goto v_27238;
v_27234:
    v_27259 = v_27261;
    v_27262 = qcar(v_27259);
    goto v_27235;
v_27236:
    v_27259 = v_27260;
    v_27259 = qcar(v_27259);
    goto v_27237;
v_27238:
    goto v_27234;
v_27235:
    goto v_27236;
v_27237:
    if (equal(v_27262, v_27259)) goto v_27232;
    else goto v_27233;
v_27232:
    v_27259 = v_27261;
    v_27259 = qcdr(v_27259);
    v_27261 = v_27259;
    v_27259 = v_27260;
    v_27259 = qcdr(v_27259);
    v_27260 = v_27259;
    goto v_27214;
v_27233:
    goto v_27254;
v_27250:
    v_27259 = v_27261;
    v_27259 = qcar(v_27259);
    goto v_27251;
v_27252:
    v_27260 = qcar(v_27260);
    goto v_27253;
v_27254:
    goto v_27250;
v_27251:
    goto v_27252;
v_27253:
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_27259, v_27260);
    }
    v_27259 = nil;
v_27213:
    return onevalue(v_27259);
}



// Code for strand!-alg!-top

static LispObject CC_strandKalgKtop(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27254, v_27255, v_27256;
    LispObject fn;
    LispObject v_27211, v_27210, v_27209;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "strand-alg-top");
    va_start(aa, nargs);
    v_27209 = va_arg(aa, LispObject);
    v_27210 = va_arg(aa, LispObject);
    v_27211 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27211,v_27210,v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27209,v_27210,v_27211);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27211;
    stack[-1] = v_27210;
    stack[-2] = v_27209;
// end of prologue
    goto v_27221;
v_27217:
    v_27255 = stack[-2];
    goto v_27218;
v_27219:
    v_27254 = stack[0];
    goto v_27220;
v_27221:
    goto v_27217;
v_27218:
    goto v_27219;
v_27220:
    fn = elt(env, 1); // deletez1
    v_27254 = (*qfn2(fn))(fn, v_27255, v_27254);
    env = stack[-3];
    stack[-2] = v_27254;
    goto v_27231;
v_27225:
    v_27256 = stack[0];
    goto v_27226;
v_27227:
    v_27255 = stack[-1];
    goto v_27228;
v_27229:
    v_27254 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27230;
v_27231:
    goto v_27225;
v_27226:
    goto v_27227;
v_27228:
    goto v_27229;
v_27230:
    fn = elt(env, 2); // color!-strand
    v_27254 = (*qfnn(fn))(fn, 3, v_27256, v_27255, v_27254);
    env = stack[-3];
    stack[0] = v_27254;
    goto v_27240;
v_27236:
    v_27255 = stack[-2];
    goto v_27237;
v_27238:
    v_27254 = stack[0];
    goto v_27239;
v_27240:
    goto v_27236;
v_27237:
    goto v_27238;
v_27239:
    fn = elt(env, 3); // contract!-strand
    v_27254 = (*qfn2(fn))(fn, v_27255, v_27254);
    env = stack[-3];
    stack[-2] = v_27254;
    goto v_27250;
v_27244:
    v_27256 = stack[-2];
    goto v_27245;
v_27246:
    v_27255 = stack[0];
    goto v_27247;
v_27248:
    v_27254 = nil;
    goto v_27249;
v_27250:
    goto v_27244;
v_27245:
    goto v_27246;
v_27247:
    goto v_27248;
v_27249:
    {
        fn = elt(env, 4); // dstr!-to!-alg
        return (*qfnn(fn))(fn, 3, v_27256, v_27255, v_27254);
    }
    return onevalue(v_27254);
}



// Code for inormmat

static LispObject CC_inormmat(LispObject env,
                         LispObject v_27209)
{
    env = qenv(env);
    LispObject v_27339, v_27340;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27209);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27209);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    v_27339 = v_27209;
// end of prologue
    stack[-6] = nil;
    stack[-5] = v_27339;
v_27219:
    v_27339 = stack[-5];
    if (v_27339 == nil) goto v_27223;
    else goto v_27224;
v_27223:
    goto v_27218;
v_27224:
    v_27339 = stack[-5];
    v_27339 = qcar(v_27339);
    stack[-1] = v_27339;
    v_27339 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-7] = v_27339;
    v_27339 = stack[-1];
    stack[0] = v_27339;
v_27234:
    v_27339 = stack[0];
    if (v_27339 == nil) goto v_27238;
    else goto v_27239;
v_27238:
    goto v_27233;
v_27239:
    v_27339 = stack[0];
    v_27339 = qcar(v_27339);
    goto v_27250;
v_27246:
    v_27340 = stack[-7];
    goto v_27247;
v_27248:
    v_27339 = qcdr(v_27339);
    goto v_27249;
v_27250:
    goto v_27246;
v_27247:
    goto v_27248;
v_27249:
    fn = elt(env, 1); // ilcm
    v_27339 = (*qfn2(fn))(fn, v_27340, v_27339);
    env = stack[-8];
    stack[-7] = v_27339;
    v_27339 = stack[0];
    v_27339 = qcdr(v_27339);
    stack[0] = v_27339;
    goto v_27234;
v_27233:
    goto v_27261;
v_27257:
    v_27339 = stack[-1];
    stack[-4] = v_27339;
    v_27339 = stack[-4];
    if (v_27339 == nil) goto v_27271;
    else goto v_27272;
v_27271:
    v_27339 = nil;
    v_27340 = v_27339;
    goto v_27266;
v_27272:
    v_27339 = stack[-4];
    v_27339 = qcar(v_27339);
    goto v_27284;
v_27280:
    v_27340 = v_27339;
    stack[0] = qcar(v_27340);
    goto v_27281;
v_27282:
    goto v_27292;
v_27288:
    v_27340 = stack[-7];
    goto v_27289;
v_27290:
    v_27339 = qcdr(v_27339);
    goto v_27291;
v_27292:
    goto v_27288;
v_27289:
    goto v_27290;
v_27291:
    v_27339 = quot2(v_27340, v_27339);
    env = stack[-8];
    goto v_27283;
v_27284:
    goto v_27280;
v_27281:
    goto v_27282;
v_27283:
    v_27339 = times2(stack[0], v_27339);
    env = stack[-8];
    v_27339 = ncons(v_27339);
    env = stack[-8];
    stack[-2] = v_27339;
    stack[-3] = v_27339;
v_27267:
    v_27339 = stack[-4];
    v_27339 = qcdr(v_27339);
    stack[-4] = v_27339;
    v_27339 = stack[-4];
    if (v_27339 == nil) goto v_27300;
    else goto v_27301;
v_27300:
    v_27339 = stack[-3];
    v_27340 = v_27339;
    goto v_27266;
v_27301:
    goto v_27309;
v_27305:
    stack[-1] = stack[-2];
    goto v_27306;
v_27307:
    v_27339 = stack[-4];
    v_27339 = qcar(v_27339);
    goto v_27320;
v_27316:
    v_27340 = v_27339;
    stack[0] = qcar(v_27340);
    goto v_27317;
v_27318:
    goto v_27328;
v_27324:
    v_27340 = stack[-7];
    goto v_27325;
v_27326:
    v_27339 = qcdr(v_27339);
    goto v_27327;
v_27328:
    goto v_27324;
v_27325:
    goto v_27326;
v_27327:
    v_27339 = quot2(v_27340, v_27339);
    env = stack[-8];
    goto v_27319;
v_27320:
    goto v_27316;
v_27317:
    goto v_27318;
v_27319:
    v_27339 = times2(stack[0], v_27339);
    env = stack[-8];
    v_27339 = ncons(v_27339);
    env = stack[-8];
    goto v_27308;
v_27309:
    goto v_27305;
v_27306:
    goto v_27307;
v_27308:
    v_27339 = Lrplacd(nil, stack[-1], v_27339);
    env = stack[-8];
    v_27339 = stack[-2];
    v_27339 = qcdr(v_27339);
    stack[-2] = v_27339;
    goto v_27267;
v_27266:
    goto v_27258;
v_27259:
    v_27339 = stack[-6];
    goto v_27260;
v_27261:
    goto v_27257;
v_27258:
    goto v_27259;
v_27260:
    v_27339 = cons(v_27340, v_27339);
    env = stack[-8];
    stack[-6] = v_27339;
    v_27339 = stack[-5];
    v_27339 = qcdr(v_27339);
    stack[-5] = v_27339;
    goto v_27219;
v_27218:
    v_27339 = stack[-6];
        return Lreverse(nil, v_27339);
    return onevalue(v_27339);
}



setup_type const u46_setup[] =
{
    {"qqe_simplbtat",           TOO_FEW_2,      CC_qqe_simplbtat,WRONG_NO_2},
    {"pasf_ceil",               TOO_FEW_2,      CC_pasf_ceil,  WRONG_NO_2},
    {"quotientml",              TOO_FEW_2,      CC_quotientml, WRONG_NO_2},
    {"simpdf",                  CC_simpdf,      TOO_MANY_1,    WRONG_NO_1},
    {"wedgewedge",              TOO_FEW_2,      CC_wedgewedge, WRONG_NO_2},
    {"simpsetdiff",             CC_simpsetdiff, TOO_MANY_1,    WRONG_NO_1},
    {"evalletsub",              TOO_FEW_2,      CC_evalletsub, WRONG_NO_2},
    {"negex",                   CC_negex,       TOO_MANY_1,    WRONG_NO_1},
    {"ra_wrapper",              TOO_FEW_2,      CC_ra_wrapper, WRONG_NO_2},
    {"mri_ofsf2mri",            TOO_FEW_2,      CC_mri_ofsf2mri,WRONG_NO_2},
    {"cl_bnfsimpl",             TOO_FEW_2,      CC_cl_bnfsimpl,WRONG_NO_2},
    {"vdp_getprop",             TOO_FEW_2,      CC_vdp_getprop,WRONG_NO_2},
    {"matrixir",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_matrixir},
    {"*rn2rd",                  CC_Hrn2rd,      TOO_MANY_1,    WRONG_NO_1},
    {"prim-part",               CC_primKpart,   TOO_MANY_1,    WRONG_NO_1},
    {"precision",               CC_precision,   TOO_MANY_1,    WRONG_NO_1},
    {"mksqrt",                  CC_mksqrt,      TOO_MANY_1,    WRONG_NO_1},
    {"which_first",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_which_first},
    {"gd_gcasesimpl",           CC_gd_gcasesimpl,TOO_MANY_1,   WRONG_NO_1},
    {"cl_pnf2-junctor",         CC_cl_pnf2Kjunctor,TOO_MANY_1, WRONG_NO_1},
    {"mri_prifloor",            CC_mri_prifloor,TOO_MANY_1,    WRONG_NO_1},
    {"factor-prim-sqfree-f",    CC_factorKprimKsqfreeKf,TOO_MANY_1,WRONG_NO_1},
    {"findhc",                  CC_findhc,      TOO_MANY_1,    WRONG_NO_1},
    {"dipdivmon",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dipdivmon},
    {"gfftimes",                TOO_FEW_2,      CC_gfftimes,   WRONG_NO_2},
    {"new_prove",               TOO_FEW_2,      CC_new_prove,  WRONG_NO_2},
    {"mkrepart",                CC_mkrepart,    TOO_MANY_1,    WRONG_NO_1},
    {"prsum",                   TOO_FEW_2,      CC_prsum,      WRONG_NO_2},
    {"rfirst",                  CC_rfirst,      TOO_MANY_1,    WRONG_NO_1},
    {"subs2p",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_subs2p},
    {"settreset",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_settreset},
    {"lto_setminus",            TOO_FEW_2,      CC_lto_setminus,WRONG_NO_2},
    {"pdiffvars",               TOO_FEW_2,      CC_pdiffvars,  WRONG_NO_2},
    {"ps:evaluate-next",        TOO_FEW_2,      CC_psTevaluateKnext,WRONG_NO_2},
    {"scar",                    TOO_FEW_2,      CC_scar,       WRONG_NO_2},
    {"partitwedge",             CC_partitwedge, TOO_MANY_1,    WRONG_NO_1},
    {"subfindices",             TOO_FEW_2,      CC_subfindices,WRONG_NO_2},
    {"coeff_calc",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_coeff_calc},
    {"fs:timescoeff",           TOO_FEW_2,      CC_fsTtimescoeff,WRONG_NO_2},
    {"mkindxlist",              CC_mkindxlist,  TOO_MANY_1,    WRONG_NO_1},
    {"mkrootsql",               TOO_FEW_2,      CC_mkrootsql,  WRONG_NO_2},
    {"evaluate-in-order-mod-p", TOO_FEW_2,      CC_evaluateKinKorderKmodKp,WRONG_NO_2},
    {"coeffs",                  CC_coeffs,      TOO_MANY_1,    WRONG_NO_1},
    {"valuechk",                TOO_FEW_2,      CC_valuechk,   WRONG_NO_2},
    {"iv_new",                  TOO_FEW_2,      CC_iv_new,     WRONG_NO_2},
    {"ofsf_optfindeqsol",       TOO_FEW_2,      CC_ofsf_optfindeqsol,WRONG_NO_2},
    {"csymbolrd",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_csymbolrd},
    {"sc_scalarproduct",        TOO_FEW_2,      CC_sc_scalarproduct,WRONG_NO_2},
    {"fortassign",              CC_fortassign,  TOO_MANY_1,    WRONG_NO_1},
    {"ordpl",                   TOO_FEW_2,      CC_ordpl,      WRONG_NO_2},
    {"strand-alg-top",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_strandKalgKtop},
    {"inormmat",                CC_inormmat,    TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u46", (two_args *)"184176 6585201 7107181", 0}
};

// end of generated code
