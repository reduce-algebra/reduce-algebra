
// $destdir/u38.c        Machine generated C code

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



// Code for valuecoefft

static LispObject CC_valuecoefft(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21412, v_21413, v_21414, v_21415, v_21416;
    LispObject fn;
    LispObject v_21367, v_21366, v_21365;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "valuecoefft");
    va_start(aa, nargs);
    v_21365 = va_arg(aa, LispObject);
    v_21366 = va_arg(aa, LispObject);
    v_21367 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21414 = v_21367;
    v_21415 = v_21366;
    v_21416 = v_21365;
// end of prologue
v_21371:
    v_21412 = v_21414;
    if (v_21412 == nil) goto v_21374;
    else goto v_21375;
v_21374:
    v_21412 = elt(env, 1); // "Valuecoefft - no value"
    {
        fn = elt(env, 2); // interr
        return (*qfn1(fn))(fn, v_21412);
    }
v_21375:
    goto v_21385;
v_21381:
    v_21413 = v_21416;
    goto v_21382;
v_21383:
    v_21412 = v_21414;
    v_21412 = qcar(v_21412);
    goto v_21384;
v_21385:
    goto v_21381;
v_21382:
    goto v_21383;
v_21384:
    if (v_21413 == v_21412) goto v_21379;
    else goto v_21380;
v_21379:
    goto v_21397;
v_21393:
    v_21412 = v_21415;
    v_21413 = qcar(v_21412);
    goto v_21394;
v_21395:
    v_21412 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21396;
v_21397:
    goto v_21393;
v_21394:
    goto v_21395;
v_21396:
    if (v_21413 == v_21412) goto v_21391;
    else goto v_21392;
v_21391:
    v_21412 = nil;
    goto v_21370;
v_21392:
    v_21412 = v_21415;
    v_21412 = qcar(v_21412);
    goto v_21370;
    goto v_21373;
v_21380:
    v_21412 = v_21415;
    v_21412 = qcdr(v_21412);
    v_21415 = v_21412;
    v_21412 = v_21414;
    v_21412 = qcdr(v_21412);
    v_21414 = v_21412;
    goto v_21371;
v_21373:
    v_21412 = nil;
v_21370:
    return onevalue(v_21412);
}



// Code for rl_convertarg

static LispObject CC_rl_convertarg(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21385, v_21386;
    LispObject fn;
    LispObject v_21367, v_21366, v_21365;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "rl_convertarg");
    va_start(aa, nargs);
    v_21365 = va_arg(aa, LispObject);
    v_21366 = va_arg(aa, LispObject);
    v_21367 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21367,v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21365,v_21366,v_21367);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_21385 = v_21367;
    v_21386 = v_21366;
    stack[0] = v_21365;
// end of prologue
    goto v_21374;
v_21370:
    goto v_21380;
v_21376:
    goto v_21377;
v_21378:
    goto v_21379;
v_21380:
    goto v_21376;
v_21377:
    goto v_21378;
v_21379:
    fn = elt(env, 1); // rl_conversionfunction
    stack[-1] = (*qfn2(fn))(fn, v_21386, v_21385);
    env = stack[-2];
    goto v_21371;
v_21372:
    v_21385 = stack[0];
    v_21385 = ncons(v_21385);
    env = stack[-2];
    goto v_21373;
v_21374:
    goto v_21370;
v_21371:
    goto v_21372;
v_21373:
    {
        LispObject v_21389 = stack[-1];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_21389, v_21385);
    }
}



// Code for mri_opn

static LispObject CC_mri_opn(LispObject env,
                         LispObject v_21365)
{
    env = qenv(env);
    LispObject v_21380, v_21381;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21365);
    }
// copy arguments values to proper place
    v_21380 = v_21365;
// end of prologue
    fn = elt(env, 1); // mri_op
    v_21380 = (*qfn1(fn))(fn, v_21380);
    v_21381 = v_21380;
    v_21380 = v_21381;
    if (!consp(v_21380)) goto v_21372;
    else goto v_21373;
v_21372:
    v_21380 = v_21381;
    goto v_21371;
v_21373:
    v_21380 = v_21381;
    v_21380 = qcar(v_21380);
    goto v_21371;
    v_21380 = nil;
v_21371:
    return onevalue(v_21380);
}



// Code for internal!-factorf

static LispObject CC_internalKfactorf(LispObject env,
                         LispObject v_21365)
{
    env = qenv(env);
    LispObject v_21651, v_21652;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21365);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_21365;
// end of prologue
    v_21651 = qvalue(elt(env, 1)); // current!-modulus
// Binding current!-modulus
// FLUIDBIND: reloadenv=10 litvec-offset=1 saveloc=9
{   bind_fluid_stack bind_fluid_var(-10, 1, -9);
    qvalue(elt(env, 1)) = v_21651; // current!-modulus
// Binding m!-image!-variable
// FLUIDBIND: reloadenv=10 litvec-offset=2 saveloc=7
{   bind_fluid_stack bind_fluid_var(-10, 2, -7);
    qvalue(elt(env, 2)) = nil; // m!-image!-variable
    stack[-6] = nil;
// Binding d
// FLUIDBIND: reloadenv=10 litvec-offset=3 saveloc=5
{   bind_fluid_stack bind_fluid_var(-10, 3, -5);
    qvalue(elt(env, 3)) = nil; // d
    v_21651 = stack[-8];
    if (!consp(v_21651)) goto v_21384;
    else goto v_21385;
v_21384:
    v_21651 = lisp_true;
    goto v_21383;
v_21385:
    v_21651 = stack[-8];
    v_21651 = qcar(v_21651);
    v_21651 = (consp(v_21651) ? nil : lisp_true);
    goto v_21383;
    v_21651 = nil;
v_21383:
    if (v_21651 == nil) goto v_21381;
    v_21651 = stack[-8];
    v_21651 = ncons(v_21651);
    goto v_21377;
v_21381:
    goto v_21400;
v_21396:
    v_21652 = stack[-8];
    goto v_21397;
v_21398:
    v_21651 = nil;
    goto v_21399;
v_21400:
    goto v_21396;
v_21397:
    goto v_21398;
v_21399:
    fn = elt(env, 5); // kernord
    v_21651 = (*qfn2(fn))(fn, v_21652, v_21651);
    env = stack[-10];
    v_21652 = v_21651;
    v_21651 = qvalue(elt(env, 4)); // !*kernreverse
    if (v_21651 == nil) goto v_21406;
    v_21651 = v_21652;
    v_21651 = Lreverse(nil, v_21651);
    env = stack[-10];
    v_21652 = v_21651;
    goto v_21404;
v_21406:
v_21404:
    v_21651 = v_21652;
    fn = elt(env, 6); // setkorder
    v_21651 = (*qfn1(fn))(fn, v_21651);
    env = stack[-10];
    stack[-3] = v_21651;
    v_21651 = stack[-8];
    fn = elt(env, 7); // reorder
    v_21651 = (*qfn1(fn))(fn, v_21651);
    env = stack[-10];
    stack[-8] = v_21651;
    v_21651 = stack[-8];
    fn = elt(env, 8); // minusf
    v_21651 = (*qfn1(fn))(fn, v_21651);
    env = stack[-10];
    if (v_21651 == nil) goto v_21417;
    v_21651 = stack[-6];
    v_21651 = (v_21651 == nil ? lisp_true : nil);
    stack[-6] = v_21651;
    v_21651 = stack[-8];
    fn = elt(env, 9); // negf
    v_21651 = (*qfn1(fn))(fn, v_21651);
    env = stack[-10];
    stack[-8] = v_21651;
    goto v_21415;
v_21417:
v_21415:
    v_21651 = stack[-8];
    fn = elt(env, 10); // comfac
    v_21651 = (*qfn1(fn))(fn, v_21651);
    env = stack[-10];
    stack[-2] = v_21651;
    goto v_21431;
v_21427:
    stack[0] = stack[-8];
    goto v_21428;
v_21429:
    v_21651 = stack[-2];
    fn = elt(env, 11); // comfac!-to!-poly
    v_21651 = (*qfn1(fn))(fn, v_21651);
    env = stack[-10];
    goto v_21430;
v_21431:
    goto v_21427;
v_21428:
    goto v_21429;
v_21430:
    fn = elt(env, 12); // quotf1
    v_21651 = (*qfn2(fn))(fn, stack[0], v_21651);
    env = stack[-10];
    stack[-8] = v_21651;
    v_21651 = stack[-8];
    if (!consp(v_21651)) goto v_21441;
    else goto v_21442;
v_21441:
    v_21651 = lisp_true;
    goto v_21440;
v_21442:
    v_21651 = stack[-8];
    v_21651 = qcar(v_21651);
    v_21651 = (consp(v_21651) ? nil : lisp_true);
    goto v_21440;
    v_21651 = nil;
v_21440:
    if (v_21651 == nil) goto v_21438;
    v_21651 = stack[-8];
    qvalue(elt(env, 3)) = v_21651; // d
    v_21651 = nil;
    stack[-8] = v_21651;
    goto v_21436;
v_21438:
    v_21651 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 3)) = v_21651; // d
    v_21651 = stack[-8];
    v_21651 = qcar(v_21651);
    v_21651 = qcar(v_21651);
    v_21651 = qcar(v_21651);
    qvalue(elt(env, 2)) = v_21651; // m!-image!-variable
    goto v_21464;
v_21460:
    v_21651 = stack[-8];
    fn = elt(env, 13); // factorize!-primitive!-polynomial
    v_21652 = (*qfn1(fn))(fn, v_21651);
    env = stack[-10];
    goto v_21461;
v_21462:
    v_21651 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21463;
v_21464:
    goto v_21460;
v_21461:
    goto v_21462;
v_21463:
    fn = elt(env, 14); // distribute!.multiplicity
    v_21651 = (*qfn2(fn))(fn, v_21652, v_21651);
    env = stack[-10];
    stack[-8] = v_21651;
    goto v_21436;
v_21436:
    v_21651 = stack[-2];
    v_21651 = qcar(v_21651);
    stack[-1] = v_21651;
    v_21651 = stack[-2];
    v_21651 = qcdr(v_21651);
    fn = elt(env, 15); // fctrf1
    v_21651 = (*qfn1(fn))(fn, v_21651);
    env = stack[-10];
    stack[-2] = v_21651;
    v_21651 = stack[-1];
    if (v_21651 == nil) goto v_21476;
    goto v_21485;
v_21479:
    v_21651 = stack[-2];
    stack[0] = qcar(v_21651);
    goto v_21480;
v_21481:
    goto v_21493;
v_21489:
    goto v_21500;
v_21496:
    goto v_21506;
v_21502:
    v_21651 = stack[-1];
    v_21652 = qcar(v_21651);
    goto v_21503;
v_21504:
    v_21651 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21505;
v_21506:
    goto v_21502;
v_21503:
    goto v_21504;
v_21505:
    fn = elt(env, 16); // to
    v_21652 = (*qfn2(fn))(fn, v_21652, v_21651);
    env = stack[-10];
    goto v_21497;
v_21498:
    v_21651 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21499;
v_21500:
    goto v_21496;
v_21497:
    goto v_21498;
v_21499:
    v_21651 = cons(v_21652, v_21651);
    env = stack[-10];
    v_21652 = ncons(v_21651);
    env = stack[-10];
    goto v_21490;
v_21491:
    v_21651 = stack[-1];
    v_21651 = qcdr(v_21651);
    goto v_21492;
v_21493:
    goto v_21489;
v_21490:
    goto v_21491;
v_21492:
    v_21652 = cons(v_21652, v_21651);
    env = stack[-10];
    goto v_21482;
v_21483:
    v_21651 = stack[-2];
    v_21651 = qcdr(v_21651);
    goto v_21484;
v_21485:
    goto v_21479;
v_21480:
    goto v_21481;
v_21482:
    goto v_21483;
v_21484:
    v_21651 = list2star(stack[0], v_21652, v_21651);
    env = stack[-10];
    stack[-2] = v_21651;
    goto v_21474;
v_21476:
v_21474:
    v_21651 = stack[-6];
    if (v_21651 == nil) goto v_21518;
    v_21651 = qvalue(elt(env, 3)); // d
    fn = elt(env, 9); // negf
    v_21651 = (*qfn1(fn))(fn, v_21651);
    env = stack[-10];
    qvalue(elt(env, 3)) = v_21651; // d
    goto v_21516;
v_21518:
v_21516:
    goto v_21527;
v_21523:
    stack[0] = stack[-2];
    goto v_21524;
v_21525:
    goto v_21534;
v_21530:
    v_21652 = qvalue(elt(env, 3)); // d
    goto v_21531;
v_21532:
    v_21651 = stack[-8];
    goto v_21533;
v_21534:
    goto v_21530;
v_21531:
    goto v_21532;
v_21533:
    v_21651 = cons(v_21652, v_21651);
    env = stack[-10];
    goto v_21526;
v_21527:
    goto v_21523;
v_21524:
    goto v_21525;
v_21526:
    fn = elt(env, 17); // fac!-merge
    v_21651 = (*qfn2(fn))(fn, stack[0], v_21651);
    env = stack[-10];
    stack[-8] = v_21651;
    v_21651 = stack[-3];
    fn = elt(env, 6); // setkorder
    v_21651 = (*qfn1(fn))(fn, v_21651);
    env = stack[-10];
    v_21651 = stack[-8];
    v_21651 = qcdr(v_21651);
    stack[-4] = v_21651;
    v_21651 = stack[-4];
    if (v_21651 == nil) goto v_21549;
    else goto v_21550;
v_21549:
    v_21651 = nil;
    goto v_21543;
v_21550:
    v_21651 = stack[-4];
    v_21651 = qcar(v_21651);
    stack[0] = v_21651;
    goto v_21562;
v_21558:
    v_21651 = stack[0];
    v_21651 = qcar(v_21651);
    fn = elt(env, 7); // reorder
    v_21651 = (*qfn1(fn))(fn, v_21651);
    env = stack[-10];
    qvalue(elt(env, 3)) = v_21651; // d
    fn = elt(env, 8); // minusf
    v_21651 = (*qfn1(fn))(fn, v_21651);
    env = stack[-10];
    if (v_21651 == nil) goto v_21566;
    v_21651 = stack[-6];
    v_21651 = (v_21651 == nil ? lisp_true : nil);
    stack[-6] = v_21651;
    v_21651 = qvalue(elt(env, 3)); // d
    fn = elt(env, 9); // negf
    v_21651 = (*qfn1(fn))(fn, v_21651);
    env = stack[-10];
    v_21652 = v_21651;
    goto v_21564;
v_21566:
    v_21651 = qvalue(elt(env, 3)); // d
    v_21652 = v_21651;
    goto v_21564;
    v_21652 = nil;
v_21564:
    goto v_21559;
v_21560:
    v_21651 = stack[0];
    v_21651 = qcdr(v_21651);
    goto v_21561;
v_21562:
    goto v_21558;
v_21559:
    goto v_21560;
v_21561:
    v_21651 = cons(v_21652, v_21651);
    env = stack[-10];
    v_21651 = ncons(v_21651);
    env = stack[-10];
    stack[-2] = v_21651;
    stack[-3] = v_21651;
v_21544:
    v_21651 = stack[-4];
    v_21651 = qcdr(v_21651);
    stack[-4] = v_21651;
    v_21651 = stack[-4];
    if (v_21651 == nil) goto v_21584;
    else goto v_21585;
v_21584:
    v_21651 = stack[-3];
    goto v_21543;
v_21585:
    goto v_21593;
v_21589:
    stack[-1] = stack[-2];
    goto v_21590;
v_21591:
    v_21651 = stack[-4];
    v_21651 = qcar(v_21651);
    stack[0] = v_21651;
    goto v_21604;
v_21600:
    v_21651 = stack[0];
    v_21651 = qcar(v_21651);
    fn = elt(env, 7); // reorder
    v_21651 = (*qfn1(fn))(fn, v_21651);
    env = stack[-10];
    qvalue(elt(env, 3)) = v_21651; // d
    fn = elt(env, 8); // minusf
    v_21651 = (*qfn1(fn))(fn, v_21651);
    env = stack[-10];
    if (v_21651 == nil) goto v_21608;
    v_21651 = stack[-6];
    v_21651 = (v_21651 == nil ? lisp_true : nil);
    stack[-6] = v_21651;
    v_21651 = qvalue(elt(env, 3)); // d
    fn = elt(env, 9); // negf
    v_21651 = (*qfn1(fn))(fn, v_21651);
    env = stack[-10];
    v_21652 = v_21651;
    goto v_21606;
v_21608:
    v_21651 = qvalue(elt(env, 3)); // d
    v_21652 = v_21651;
    goto v_21606;
    v_21652 = nil;
v_21606:
    goto v_21601;
v_21602:
    v_21651 = stack[0];
    v_21651 = qcdr(v_21651);
    goto v_21603;
v_21604:
    goto v_21600;
v_21601:
    goto v_21602;
v_21603:
    v_21651 = cons(v_21652, v_21651);
    env = stack[-10];
    v_21651 = ncons(v_21651);
    env = stack[-10];
    goto v_21592;
v_21593:
    goto v_21589;
v_21590:
    goto v_21591;
v_21592:
    v_21651 = Lrplacd(nil, stack[-1], v_21651);
    env = stack[-10];
    v_21651 = stack[-2];
    v_21651 = qcdr(v_21651);
    stack[-2] = v_21651;
    goto v_21544;
v_21543:
    stack[-2] = v_21651;
    goto v_21629;
v_21625:
    goto v_21638;
v_21634:
    stack[0] = stack[-6];
    goto v_21635;
v_21636:
    v_21651 = stack[-8];
    v_21651 = qcar(v_21651);
    fn = elt(env, 8); // minusf
    v_21651 = (*qfn1(fn))(fn, v_21651);
    env = stack[-10];
    goto v_21637;
v_21638:
    goto v_21634;
v_21635:
    goto v_21636;
v_21637:
    if (equal(stack[0], v_21651)) goto v_21633;
    v_21651 = stack[-8];
    v_21651 = qcar(v_21651);
    fn = elt(env, 9); // negf
    v_21651 = (*qfn1(fn))(fn, v_21651);
    env = stack[-10];
    v_21652 = v_21651;
    goto v_21631;
v_21633:
    v_21651 = stack[-8];
    v_21651 = qcar(v_21651);
    v_21652 = v_21651;
    goto v_21631;
    v_21652 = nil;
v_21631:
    goto v_21626;
v_21627:
    v_21651 = stack[-2];
    goto v_21628;
v_21629:
    goto v_21625;
v_21626:
    goto v_21627;
v_21628:
    v_21651 = cons(v_21652, v_21651);
v_21377:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_21651);
}



// Code for ioto_smaprinbuf

static LispObject CC_ioto_smaprinbuf(LispObject env,
                         LispObject v_21365)
{
    env = qenv(env);
    LispObject v_21385, v_21386;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21365);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21365;
// end of prologue
    goto v_21372;
v_21368:
    v_21386 = elt(env, 1); // !!
    goto v_21369;
v_21370:
    v_21385 = qvalue(elt(env, 2)); // rlsmaprinbuf!*
    goto v_21371;
v_21372:
    goto v_21368;
v_21369:
    goto v_21370;
v_21371:
    v_21385 = cons(v_21386, v_21385);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_21385; // rlsmaprinbuf!*
    goto v_21381;
v_21377:
    v_21386 = stack[0];
    goto v_21378;
v_21379:
    v_21385 = qvalue(elt(env, 2)); // rlsmaprinbuf!*
    goto v_21380;
v_21381:
    goto v_21377;
v_21378:
    goto v_21379;
v_21380:
    v_21385 = cons(v_21386, v_21385);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_21385; // rlsmaprinbuf!*
    v_21385 = stack[0];
    return onevalue(v_21385);
}



// Code for setfuncsnaryrd

static LispObject CC_setfuncsnaryrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21418, v_21419;
    LispObject fn;
    argcheck(nargs, 0, "setfuncsnaryrd");
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
    fn = elt(env, 3); // mathml
    v_21418 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_21418;
    v_21418 = stack[0];
    v_21418 = Lconsp(nil, v_21418);
    env = stack[-1];
    if (v_21418 == nil) goto v_21373;
    v_21418 = stack[0];
    v_21418 = qcdr(v_21418);
    v_21418 = qcar(v_21418);
    if (v_21418 == nil) goto v_21379;
    goto v_21391;
v_21387:
    v_21418 = stack[0];
    v_21418 = qcdr(v_21418);
    v_21418 = qcar(v_21418);
    v_21418 = qcar(v_21418);
    v_21418 = qcdr(v_21418);
    v_21418 = qcar(v_21418);
    v_21419 = Lintern(nil, v_21418);
    env = stack[-1];
    goto v_21388;
v_21389:
    v_21418 = elt(env, 1); // multiset
    goto v_21390;
v_21391:
    goto v_21387;
v_21388:
    goto v_21389;
v_21390:
    if (v_21419 == v_21418) goto v_21385;
    else goto v_21386;
v_21385:
    v_21418 = elt(env, 1); // multiset
    qvalue(elt(env, 2)) = v_21418; // mmlatts
    goto v_21384;
v_21386:
v_21384:
    goto v_21377;
v_21379:
v_21377:
    goto v_21371;
v_21373:
v_21371:
    v_21418 = stack[0];
    if (v_21418 == nil) goto v_21404;
    else goto v_21405;
v_21404:
    v_21418 = nil;
    goto v_21403;
v_21405:
    goto v_21415;
v_21411:
    goto v_21412;
v_21413:
    v_21418 = CC_setfuncsnaryrd(elt(env, 0), 0);
    goto v_21414;
v_21415:
    goto v_21411;
v_21412:
    goto v_21413;
v_21414:
    {
        LispObject v_21421 = stack[0];
        return cons(v_21421, v_21418);
    }
    v_21418 = nil;
v_21403:
    return onevalue(v_21418);
}



// Code for rewrite

static LispObject CC_rewrite(LispObject env,
                         LispObject v_21365)
{
    env = qenv(env);
    LispObject v_21763, v_21764, v_21765;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21365);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-4] = v_21365;
// end of prologue
    v_21763 = elt(env, 1); // list
    v_21763 = ncons(v_21763);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21763 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    stack[-9] = v_21763;
    goto v_21386;
v_21380:
    v_21765 = elt(env, 2); // part
    goto v_21381;
v_21382:
    v_21764 = stack[-4];
    goto v_21383;
v_21384:
    v_21763 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21385;
v_21386:
    goto v_21380;
v_21381:
    goto v_21382;
v_21383:
    goto v_21384;
v_21385:
    v_21763 = list3(v_21765, v_21764, v_21763);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21763 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    stack[-8] = v_21763;
    goto v_21397;
v_21391:
    goto v_21404;
v_21400:
    v_21764 = elt(env, 3); // length
    goto v_21401;
v_21402:
    v_21763 = stack[-8];
    goto v_21403;
v_21404:
    goto v_21400;
v_21401:
    goto v_21402;
v_21403:
    v_21763 = list2(v_21764, v_21763);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21765 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    goto v_21392;
v_21393:
    v_21764 = nil;
    goto v_21394;
v_21395:
    v_21763 = elt(env, 4); // only
    goto v_21396;
v_21397:
    goto v_21391;
v_21392:
    goto v_21393;
v_21394:
    goto v_21395;
v_21396:
    fn = elt(env, 24); // assgnpri
    v_21763 = (*qfnn(fn))(fn, 3, v_21765, v_21764, v_21763);
    env = stack[-10];
    v_21763 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_21763;
v_21412:
    goto v_21426;
v_21420:
    stack[0] = elt(env, 5); // difference
    goto v_21421;
v_21422:
    goto v_21434;
v_21430:
    v_21764 = elt(env, 6); // arglength
    goto v_21431;
v_21432:
    v_21763 = stack[-4];
    goto v_21433;
v_21434:
    goto v_21430;
v_21431:
    goto v_21432;
v_21433:
    v_21763 = list2(v_21764, v_21763);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_21764 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    goto v_21423;
v_21424:
    v_21763 = stack[-5];
    goto v_21425;
v_21426:
    goto v_21420;
v_21421:
    goto v_21422;
v_21423:
    goto v_21424;
v_21425:
    v_21763 = list3(stack[0], v_21764, v_21763);
    env = stack[-10];
    fn = elt(env, 26); // aminusp!:
    v_21763 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    if (v_21763 == nil) goto v_21417;
    goto v_21411;
v_21417:
    goto v_21447;
v_21441:
    stack[-3] = elt(env, 7); // plus
    goto v_21442;
v_21443:
    goto v_21454;
v_21450:
    stack[-1] = elt(env, 3); // length
    goto v_21451;
v_21452:
    goto v_21461;
v_21457:
    stack[0] = elt(env, 8); // den
    goto v_21458;
v_21459:
    goto v_21470;
v_21464:
    v_21765 = elt(env, 2); // part
    goto v_21465;
v_21466:
    v_21764 = stack[-4];
    goto v_21467;
v_21468:
    v_21763 = stack[-5];
    goto v_21469;
v_21470:
    goto v_21464;
v_21465:
    goto v_21466;
v_21467:
    goto v_21468;
v_21469:
    v_21763 = list3(v_21765, v_21764, v_21763);
    env = stack[-10];
    goto v_21460;
v_21461:
    goto v_21457;
v_21458:
    goto v_21459;
v_21460:
    v_21763 = list2(stack[0], v_21763);
    env = stack[-10];
    goto v_21453;
v_21454:
    goto v_21450;
v_21451:
    goto v_21452;
v_21453:
    stack[-2] = list2(stack[-1], v_21763);
    env = stack[-10];
    goto v_21444;
v_21445:
    goto v_21479;
v_21475:
    stack[-1] = elt(env, 3); // length
    goto v_21476;
v_21477:
    goto v_21486;
v_21482:
    stack[0] = elt(env, 9); // num
    goto v_21483;
v_21484:
    goto v_21495;
v_21489:
    v_21765 = elt(env, 2); // part
    goto v_21490;
v_21491:
    v_21764 = stack[-4];
    goto v_21492;
v_21493:
    v_21763 = stack[-5];
    goto v_21494;
v_21495:
    goto v_21489;
v_21490:
    goto v_21491;
v_21492:
    goto v_21493;
v_21494:
    v_21763 = list3(v_21765, v_21764, v_21763);
    env = stack[-10];
    goto v_21485;
v_21486:
    goto v_21482;
v_21483:
    goto v_21484;
v_21485:
    v_21763 = list2(stack[0], v_21763);
    env = stack[-10];
    goto v_21478;
v_21479:
    goto v_21475;
v_21476:
    goto v_21477;
v_21478:
    v_21763 = list2(stack[-1], v_21763);
    env = stack[-10];
    goto v_21446;
v_21447:
    goto v_21441;
v_21442:
    goto v_21443;
v_21444:
    goto v_21445;
v_21446:
    v_21763 = list3(stack[-3], stack[-2], v_21763);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_21763 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    stack[0] = v_21763;
    goto v_21506;
v_21500:
    v_21763 = stack[0];
    fn = elt(env, 25); // aeval!*
    v_21765 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    goto v_21501;
v_21502:
    v_21764 = nil;
    goto v_21503;
v_21504:
    v_21763 = elt(env, 4); // only
    goto v_21505;
v_21506:
    goto v_21500;
v_21501:
    goto v_21502;
v_21503:
    goto v_21504;
v_21505:
    fn = elt(env, 24); // assgnpri
    v_21763 = (*qfnn(fn))(fn, 3, v_21765, v_21764, v_21763);
    env = stack[-10];
    goto v_21520;
v_21516:
    v_21763 = stack[0];
    fn = elt(env, 25); // aeval!*
    stack[-3] = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    goto v_21517;
v_21518:
    goto v_21531;
v_21525:
    stack[-2] = elt(env, 7); // plus
    goto v_21526;
v_21527:
    goto v_21538;
v_21534:
    stack[0] = elt(env, 3); // length
    goto v_21535;
v_21536:
    goto v_21545;
v_21541:
    v_21764 = elt(env, 8); // den
    goto v_21542;
v_21543:
    v_21763 = stack[-8];
    goto v_21544;
v_21545:
    goto v_21541;
v_21542:
    goto v_21543;
v_21544:
    v_21763 = list2(v_21764, v_21763);
    env = stack[-10];
    goto v_21537;
v_21538:
    goto v_21534;
v_21535:
    goto v_21536;
v_21537:
    stack[-1] = list2(stack[0], v_21763);
    env = stack[-10];
    goto v_21528;
v_21529:
    goto v_21553;
v_21549:
    stack[0] = elt(env, 3); // length
    goto v_21550;
v_21551:
    goto v_21560;
v_21556:
    v_21764 = elt(env, 9); // num
    goto v_21557;
v_21558:
    v_21763 = stack[-8];
    goto v_21559;
v_21560:
    goto v_21556;
v_21557:
    goto v_21558;
v_21559:
    v_21763 = list2(v_21764, v_21763);
    env = stack[-10];
    goto v_21552;
v_21553:
    goto v_21549;
v_21550:
    goto v_21551;
v_21552:
    v_21763 = list2(stack[0], v_21763);
    env = stack[-10];
    goto v_21530;
v_21531:
    goto v_21525;
v_21526:
    goto v_21527;
v_21528:
    goto v_21529;
v_21530:
    v_21763 = list3(stack[-2], stack[-1], v_21763);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_21763 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    goto v_21519;
v_21520:
    goto v_21516;
v_21517:
    goto v_21518;
v_21519:
    fn = elt(env, 27); // evallessp
    v_21763 = (*qfn2(fn))(fn, stack[-3], v_21763);
    env = stack[-10];
    if (v_21763 == nil) goto v_21514;
    goto v_21571;
v_21565:
    v_21765 = elt(env, 2); // part
    goto v_21566;
v_21567:
    v_21764 = stack[-4];
    goto v_21568;
v_21569:
    v_21763 = stack[-5];
    goto v_21570;
v_21571:
    goto v_21565;
v_21566:
    goto v_21567;
v_21568:
    goto v_21569;
v_21570:
    v_21763 = list3(v_21765, v_21764, v_21763);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_21763 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    stack[-8] = v_21763;
    goto v_21512;
v_21514:
v_21512:
    v_21763 = nil;
    fn = elt(env, 25); // aeval!*
    v_21763 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    v_21763 = stack[-5];
    goto v_21587;
v_21581:
    v_21765 = elt(env, 7); // plus
    goto v_21582;
v_21583:
    v_21764 = v_21763;
    goto v_21584;
v_21585:
    v_21763 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21586;
v_21587:
    goto v_21581;
v_21582:
    goto v_21583;
v_21584:
    goto v_21585;
v_21586:
    v_21763 = list3(v_21765, v_21764, v_21763);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_21763 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    stack[-5] = v_21763;
    goto v_21412;
v_21411:
    goto v_21598;
v_21592:
    v_21763 = elt(env, 10); // "g is "
    fn = elt(env, 23); // aeval
    v_21765 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    goto v_21593;
v_21594:
    v_21764 = nil;
    goto v_21595;
v_21596:
    v_21763 = elt(env, 11); // first
    goto v_21597;
v_21598:
    goto v_21592;
v_21593:
    goto v_21594;
v_21595:
    goto v_21596;
v_21597:
    fn = elt(env, 24); // assgnpri
    v_21763 = (*qfnn(fn))(fn, 3, v_21765, v_21764, v_21763);
    env = stack[-10];
    goto v_21610;
v_21604:
    v_21763 = stack[-8];
    fn = elt(env, 23); // aeval
    v_21765 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    goto v_21605;
v_21606:
    v_21764 = nil;
    goto v_21607;
v_21608:
    v_21763 = elt(env, 12); // last
    goto v_21609;
v_21610:
    goto v_21604;
v_21605:
    goto v_21606;
v_21607:
    goto v_21608;
v_21609:
    fn = elt(env, 24); // assgnpri
    v_21763 = (*qfnn(fn))(fn, 3, v_21765, v_21764, v_21763);
    env = stack[-10];
    v_21763 = stack[-4];
    fn = elt(env, 23); // aeval
    v_21763 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    fn = elt(env, 28); // getrlist
    v_21763 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    stack[-6] = v_21763;
v_21618:
    v_21763 = stack[-6];
    if (v_21763 == nil) goto v_21624;
    else goto v_21625;
v_21624:
    goto v_21617;
v_21625:
    v_21763 = stack[-6];
    v_21763 = qcar(v_21763);
    stack[0] = v_21763;
    goto v_21641;
v_21633:
    stack[-3] = elt(env, 13); // limit
    goto v_21634;
v_21635:
    goto v_21650;
v_21644:
    stack[-2] = elt(env, 14); // quotient
    goto v_21645;
v_21646:
    goto v_21657;
v_21653:
    v_21764 = elt(env, 15); // log
    goto v_21654;
v_21655:
    v_21763 = stack[0];
    goto v_21656;
v_21657:
    goto v_21653;
v_21654:
    goto v_21655;
v_21656:
    stack[-1] = list2(v_21764, v_21763);
    env = stack[-10];
    goto v_21647;
v_21648:
    goto v_21665;
v_21661:
    v_21764 = elt(env, 15); // log
    goto v_21662;
v_21663:
    v_21763 = stack[-8];
    goto v_21664;
v_21665:
    goto v_21661;
v_21662:
    goto v_21663;
v_21664:
    v_21763 = list2(v_21764, v_21763);
    env = stack[-10];
    goto v_21649;
v_21650:
    goto v_21644;
v_21645:
    goto v_21646;
v_21647:
    goto v_21648;
v_21649:
    v_21765 = list3(stack[-2], stack[-1], v_21763);
    env = stack[-10];
    goto v_21636;
v_21637:
    v_21764 = elt(env, 16); // x
    goto v_21638;
v_21639:
    v_21763 = elt(env, 17); // infinity
    goto v_21640;
v_21641:
    goto v_21633;
v_21634:
    goto v_21635;
v_21636:
    goto v_21637;
v_21638:
    goto v_21639;
v_21640:
    v_21763 = list4(stack[-3], v_21765, v_21764, v_21763);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21763 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    stack[-7] = v_21763;
    goto v_21678;
v_21672:
    stack[-5] = elt(env, 18); // expt
    goto v_21673;
v_21674:
    stack[-4] = elt(env, 19); // e
    goto v_21675;
v_21676:
    goto v_21688;
v_21682:
    stack[-3] = elt(env, 5); // difference
    goto v_21683;
v_21684:
    goto v_21695;
v_21691:
    v_21764 = elt(env, 15); // log
    goto v_21692;
v_21693:
    v_21763 = stack[0];
    goto v_21694;
v_21695:
    goto v_21691;
v_21692:
    goto v_21693;
v_21694:
    stack[-2] = list2(v_21764, v_21763);
    env = stack[-10];
    goto v_21685;
v_21686:
    goto v_21705;
v_21699:
    stack[-1] = elt(env, 20); // times
    goto v_21700;
v_21701:
    stack[0] = stack[-7];
    goto v_21702;
v_21703:
    goto v_21713;
v_21709:
    v_21764 = elt(env, 15); // log
    goto v_21710;
v_21711:
    v_21763 = stack[-8];
    goto v_21712;
v_21713:
    goto v_21709;
v_21710:
    goto v_21711;
v_21712:
    v_21763 = list2(v_21764, v_21763);
    env = stack[-10];
    goto v_21704;
v_21705:
    goto v_21699;
v_21700:
    goto v_21701;
v_21702:
    goto v_21703;
v_21704:
    v_21763 = list3(stack[-1], stack[0], v_21763);
    env = stack[-10];
    goto v_21687;
v_21688:
    goto v_21682;
v_21683:
    goto v_21684;
v_21685:
    goto v_21686;
v_21687:
    v_21763 = list3(stack[-3], stack[-2], v_21763);
    env = stack[-10];
    goto v_21677;
v_21678:
    goto v_21672;
v_21673:
    goto v_21674;
v_21675:
    goto v_21676;
v_21677:
    v_21763 = list3(stack[-5], stack[-4], v_21763);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21763 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    goto v_21724;
v_21718:
    stack[-1] = elt(env, 20); // times
    goto v_21719;
v_21720:
    stack[0] = v_21763;
    goto v_21721;
v_21722:
    goto v_21734;
v_21728:
    v_21765 = elt(env, 18); // expt
    goto v_21729;
v_21730:
    v_21764 = elt(env, 21); // w
    goto v_21731;
v_21732:
    v_21763 = stack[-7];
    goto v_21733;
v_21734:
    goto v_21728;
v_21729:
    goto v_21730;
v_21731:
    goto v_21732;
v_21733:
    v_21763 = list3(v_21765, v_21764, v_21763);
    env = stack[-10];
    goto v_21723;
v_21724:
    goto v_21718;
v_21719:
    goto v_21720;
v_21721:
    goto v_21722;
v_21723:
    v_21763 = list3(stack[-1], stack[0], v_21763);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21763 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    stack[0] = v_21763;
    goto v_21746;
v_21740:
    stack[-1] = elt(env, 22); // append
    goto v_21741;
v_21742:
    goto v_21753;
v_21749:
    v_21764 = elt(env, 1); // list
    goto v_21750;
v_21751:
    v_21763 = stack[0];
    goto v_21752;
v_21753:
    goto v_21749;
v_21750:
    goto v_21751;
v_21752:
    v_21764 = list2(v_21764, v_21763);
    env = stack[-10];
    goto v_21743;
v_21744:
    v_21763 = stack[-9];
    goto v_21745;
v_21746:
    goto v_21740;
v_21741:
    goto v_21742;
v_21743:
    goto v_21744;
v_21745:
    v_21763 = list3(stack[-1], v_21764, v_21763);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_21763 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    stack[-9] = v_21763;
    v_21763 = nil;
    fn = elt(env, 23); // aeval
    v_21763 = (*qfn1(fn))(fn, v_21763);
    env = stack[-10];
    v_21763 = stack[-6];
    v_21763 = qcdr(v_21763);
    stack[-6] = v_21763;
    goto v_21618;
v_21617:
    v_21763 = stack[-9];
    {
        fn = elt(env, 23); // aeval
        return (*qfn1(fn))(fn, v_21763);
    }
    return onevalue(v_21763);
}



// Code for evalnumberp

static LispObject CC_evalnumberp(LispObject env,
                         LispObject v_21365)
{
    env = qenv(env);
    LispObject v_21425, v_21426, v_21427;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21365);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21425 = v_21365;
// end of prologue
    fn = elt(env, 3); // aeval
    v_21425 = (*qfn1(fn))(fn, v_21425);
    env = stack[0];
    v_21427 = v_21425;
    v_21425 = v_21427;
    if (!consp(v_21425)) goto v_21372;
    else goto v_21373;
v_21372:
    v_21425 = v_21427;
    v_21425 = (is_number(v_21425) ? lisp_true : nil);
    goto v_21371;
v_21373:
    goto v_21387;
v_21383:
    v_21425 = v_21427;
    v_21426 = qcar(v_21425);
    goto v_21384;
v_21385:
    v_21425 = elt(env, 1); // !*sq
    goto v_21386;
v_21387:
    goto v_21383;
v_21384:
    goto v_21385;
v_21386:
    if (v_21426 == v_21425) goto v_21382;
    v_21425 = lisp_true;
    goto v_21380;
v_21382:
    v_21425 = v_21427;
    v_21425 = qcdr(v_21425);
    v_21425 = qcar(v_21425);
    v_21425 = qcdr(v_21425);
    v_21425 = (consp(v_21425) ? nil : lisp_true);
    v_21425 = (v_21425 == nil ? lisp_true : nil);
    goto v_21380;
    v_21425 = nil;
v_21380:
    if (v_21425 == nil) goto v_21378;
    v_21425 = nil;
    goto v_21371;
v_21378:
    v_21425 = v_21427;
    v_21425 = qcdr(v_21425);
    v_21425 = qcar(v_21425);
    v_21425 = qcar(v_21425);
    v_21426 = v_21425;
    v_21425 = v_21426;
    if (!consp(v_21425)) goto v_21410;
    else goto v_21411;
v_21410:
    v_21425 = lisp_true;
    goto v_21409;
v_21411:
    goto v_21421;
v_21417:
    v_21425 = v_21426;
    v_21425 = qcar(v_21425);
    goto v_21418;
v_21419:
    v_21426 = elt(env, 2); // numbertag
    goto v_21420;
v_21421:
    goto v_21417;
v_21418:
    goto v_21419;
v_21420:
        return Lflagp(nil, v_21425, v_21426);
    v_21425 = nil;
v_21409:
    goto v_21371;
    v_21425 = nil;
v_21371:
    return onevalue(v_21425);
}



// Code for contposp

static LispObject CC_contposp(LispObject env,
                         LispObject v_21365)
{
    env = qenv(env);
    LispObject v_21387, v_21388;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21387 = v_21365;
// end of prologue
v_21364:
    v_21388 = v_21387;
    if (v_21388 == nil) goto v_21369;
    else goto v_21370;
v_21369:
    v_21387 = lisp_true;
    goto v_21368;
v_21370:
    v_21388 = v_21387;
    v_21388 = qcar(v_21388);
    if (!consp(v_21388)) goto v_21377;
    else goto v_21378;
v_21377:
    v_21387 = qcdr(v_21387);
    goto v_21364;
v_21378:
    v_21387 = nil;
    goto v_21376;
    v_21387 = nil;
v_21376:
    goto v_21368;
    v_21387 = nil;
v_21368:
    return onevalue(v_21387);
}



// Code for diff_vertex

static LispObject CC_diff_vertex(LispObject env,
                         LispObject v_21365, LispObject v_21366)
{
    env = qenv(env);
    LispObject v_21418, v_21419, v_21420;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21365,v_21366);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21366;
    stack[-1] = v_21365;
// end of prologue
    v_21420 = nil;
v_21371:
    v_21418 = stack[-1];
    if (v_21418 == nil) goto v_21374;
    else goto v_21375;
v_21374:
    v_21418 = v_21420;
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_21418);
    }
v_21375:
    goto v_21386;
v_21382:
    v_21418 = stack[-1];
    v_21418 = qcar(v_21418);
    v_21419 = qcar(v_21418);
    goto v_21383;
v_21384:
    v_21418 = stack[0];
    goto v_21385;
v_21386:
    goto v_21382;
v_21383:
    goto v_21384;
v_21385:
    v_21418 = Lassoc(nil, v_21419, v_21418);
    if (v_21418 == nil) goto v_21380;
    goto v_21397;
v_21393:
    v_21418 = stack[-1];
    v_21418 = qcar(v_21418);
    v_21419 = qcar(v_21418);
    goto v_21394;
v_21395:
    v_21418 = qvalue(elt(env, 1)); // !_0edge
    v_21418 = qcar(v_21418);
    goto v_21396;
v_21397:
    goto v_21393;
v_21394:
    goto v_21395;
v_21396:
    if (v_21419 == v_21418) goto v_21380;
    v_21418 = stack[-1];
    v_21418 = qcdr(v_21418);
    stack[-1] = v_21418;
    goto v_21371;
v_21380:
    goto v_21412;
v_21408:
    v_21418 = stack[-1];
    v_21418 = qcar(v_21418);
    goto v_21409;
v_21410:
    v_21419 = v_21420;
    goto v_21411;
v_21412:
    goto v_21408;
v_21409:
    goto v_21410;
v_21411:
    v_21418 = cons(v_21418, v_21419);
    env = stack[-2];
    v_21420 = v_21418;
    v_21418 = stack[-1];
    v_21418 = qcdr(v_21418);
    stack[-1] = v_21418;
    goto v_21371;
    v_21418 = nil;
    return onevalue(v_21418);
}



// Code for dp_from_ei

static LispObject CC_dp_from_ei(LispObject env,
                         LispObject v_21365)
{
    env = qenv(env);
    LispObject v_21378;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21365);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21365;
// end of prologue
    goto v_21373;
v_21369:
    v_21378 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 1); // cali_bc_fi
    stack[-1] = (*qfn1(fn))(fn, v_21378);
    env = stack[-2];
    goto v_21370;
v_21371:
    v_21378 = stack[0];
    fn = elt(env, 2); // mo_from_ei
    v_21378 = (*qfn1(fn))(fn, v_21378);
    env = stack[-2];
    goto v_21372;
v_21373:
    goto v_21369;
v_21370:
    goto v_21371;
v_21372:
    fn = elt(env, 3); // dp_term
    v_21378 = (*qfn2(fn))(fn, stack[-1], v_21378);
    return ncons(v_21378);
}



// Code for getavalue

static LispObject CC_getavalue(LispObject env,
                         LispObject v_21365)
{
    env = qenv(env);
    LispObject v_21381, v_21382;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21381 = v_21365;
// end of prologue
    if (!symbolp(v_21381)) v_21381 = nil;
    else { v_21381 = qfastgets(v_21381);
           if (v_21381 != nil) { v_21381 = elt(v_21381, 4); // avalue
#ifdef RECORD_GET
             if (v_21381 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_21381 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_21381 == SPID_NOPROP) v_21381 = nil; }}
#endif
    v_21382 = v_21381;
    v_21381 = v_21382;
    if (v_21381 == nil) goto v_21373;
    v_21381 = v_21382;
    v_21381 = qcdr(v_21381);
    v_21381 = qcar(v_21381);
    goto v_21371;
v_21373:
    v_21381 = nil;
    goto v_21371;
    v_21381 = nil;
v_21371:
    return onevalue(v_21381);
}



// Code for msolve!-psys1

static LispObject CC_msolveKpsys1(LispObject env,
                         LispObject v_21365, LispObject v_21366)
{
    env = qenv(env);
    LispObject v_21489, v_21490;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21365,v_21366);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_21366;
    stack[0] = v_21365;
// end of prologue
    v_21489 = nil;
    v_21489 = ncons(v_21489);
    env = stack[-7];
    v_21490 = v_21489;
    v_21489 = stack[0];
    stack[-4] = v_21489;
v_21379:
    v_21489 = stack[-4];
    if (v_21489 == nil) goto v_21383;
    else goto v_21384;
v_21383:
    goto v_21378;
v_21384:
    v_21489 = stack[-4];
    v_21489 = qcar(v_21489);
    stack[-3] = v_21489;
    v_21489 = nil;
    stack[-6] = v_21489;
    v_21489 = v_21490;
    stack[-2] = v_21489;
v_21394:
    v_21489 = stack[-2];
    if (v_21489 == nil) goto v_21398;
    else goto v_21399;
v_21398:
    goto v_21393;
v_21399:
    v_21489 = stack[-2];
    v_21489 = qcar(v_21489);
    stack[-1] = v_21489;
    goto v_21412;
v_21408:
    v_21490 = stack[-3];
    goto v_21409;
v_21410:
    v_21489 = stack[-1];
    goto v_21411;
v_21412:
    goto v_21408;
v_21409:
    goto v_21410;
v_21411:
    fn = elt(env, 1); // subf
    v_21489 = (*qfn2(fn))(fn, v_21490, v_21489);
    env = stack[-7];
    v_21489 = qcar(v_21489);
    fn = elt(env, 2); // moduntag
    v_21489 = (*qfn1(fn))(fn, v_21489);
    env = stack[-7];
    fn = elt(env, 3); // general!-reduce!-mod!-p
    v_21489 = (*qfn1(fn))(fn, v_21489);
    env = stack[-7];
    v_21490 = v_21489;
    v_21489 = v_21490;
    if (v_21489 == nil) goto v_21418;
    else goto v_21419;
v_21418:
    goto v_21426;
v_21422:
    v_21490 = stack[-1];
    goto v_21423;
v_21424:
    v_21489 = stack[-6];
    goto v_21425;
v_21426:
    goto v_21422;
v_21423:
    goto v_21424;
v_21425:
    v_21489 = cons(v_21490, v_21489);
    env = stack[-7];
    stack[-6] = v_21489;
    goto v_21417;
v_21419:
    v_21489 = v_21490;
    if (!consp(v_21489)) goto v_21433;
    else goto v_21434;
v_21433:
    v_21489 = lisp_true;
    goto v_21432;
v_21434:
    v_21489 = v_21490;
    v_21489 = qcar(v_21489);
    v_21489 = (consp(v_21489) ? nil : lisp_true);
    goto v_21432;
    v_21489 = nil;
v_21432:
    if (v_21489 == nil) goto v_21430;
    goto v_21417;
v_21430:
    goto v_21454;
v_21450:
    goto v_21451;
v_21452:
    v_21489 = stack[-5];
    goto v_21453;
v_21454:
    goto v_21450;
v_21451:
    goto v_21452;
v_21453:
    fn = elt(env, 4); // msolve!-poly
    v_21489 = (*qfn2(fn))(fn, v_21490, v_21489);
    env = stack[-7];
    stack[0] = v_21489;
v_21448:
    v_21489 = stack[0];
    if (v_21489 == nil) goto v_21459;
    else goto v_21460;
v_21459:
    goto v_21447;
v_21460:
    v_21489 = stack[0];
    v_21489 = qcar(v_21489);
    goto v_21471;
v_21467:
    goto v_21477;
v_21473:
    v_21490 = stack[-1];
    goto v_21474;
v_21475:
    goto v_21476;
v_21477:
    goto v_21473;
v_21474:
    goto v_21475;
v_21476:
    v_21490 = Lappend(nil, v_21490, v_21489);
    env = stack[-7];
    goto v_21468;
v_21469:
    v_21489 = stack[-6];
    goto v_21470;
v_21471:
    goto v_21467;
v_21468:
    goto v_21469;
v_21470:
    v_21489 = cons(v_21490, v_21489);
    env = stack[-7];
    stack[-6] = v_21489;
    v_21489 = stack[0];
    v_21489 = qcdr(v_21489);
    stack[0] = v_21489;
    goto v_21448;
v_21447:
    goto v_21417;
v_21417:
    v_21489 = stack[-2];
    v_21489 = qcdr(v_21489);
    stack[-2] = v_21489;
    goto v_21394;
v_21393:
    v_21489 = stack[-6];
    v_21490 = v_21489;
    v_21489 = stack[-4];
    v_21489 = qcdr(v_21489);
    stack[-4] = v_21489;
    goto v_21379;
v_21378:
    v_21489 = v_21490;
    return onevalue(v_21489);
}



// Code for lalr_expand_grammar

static LispObject CC_lalr_expand_grammar(LispObject env,
                         LispObject v_21365)
{
    env = qenv(env);
    LispObject v_21400, v_21401;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21365);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_21400 = v_21365;
// end of prologue
// Binding pending_rules!*
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 1, -1);
    qvalue(elt(env, 1)) = nil; // pending_rules!*
    fn = elt(env, 2); // lalr_check_grammar
    v_21400 = (*qfn1(fn))(fn, v_21400);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_21400; // pending_rules!*
    v_21400 = nil;
    stack[0] = v_21400;
v_21378:
    v_21400 = qvalue(elt(env, 1)); // pending_rules!*
    if (v_21400 == nil) goto v_21381;
    else goto v_21382;
v_21381:
    goto v_21377;
v_21382:
    v_21400 = qvalue(elt(env, 1)); // pending_rules!*
    v_21400 = qcar(v_21400);
    v_21401 = v_21400;
    v_21400 = qvalue(elt(env, 1)); // pending_rules!*
    v_21400 = qcdr(v_21400);
    qvalue(elt(env, 1)) = v_21400; // pending_rules!*
    goto v_21394;
v_21390:
    v_21400 = v_21401;
    fn = elt(env, 3); // expand_rule
    v_21401 = (*qfn1(fn))(fn, v_21400);
    env = stack[-2];
    goto v_21391;
v_21392:
    v_21400 = stack[0];
    goto v_21393;
v_21394:
    goto v_21390;
v_21391:
    goto v_21392;
v_21393:
    v_21400 = cons(v_21401, v_21400);
    env = stack[-2];
    stack[0] = v_21400;
    goto v_21378;
v_21377:
    v_21400 = stack[0];
    v_21400 = Lreverse(nil, v_21400);
    ;}  // end of a binding scope
    return onevalue(v_21400);
}



// Code for cl_atnum

static LispObject CC_cl_atnum(LispObject env,
                         LispObject v_21365)
{
    env = qenv(env);
    LispObject v_21616, v_21617, v_21618;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21365);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21365;
// end of prologue
v_21364:
    v_21616 = stack[0];
    if (!consp(v_21616)) goto v_21373;
    else goto v_21374;
v_21373:
    v_21616 = stack[0];
    goto v_21372;
v_21374:
    v_21616 = stack[0];
    v_21616 = qcar(v_21616);
    goto v_21372;
    v_21616 = nil;
v_21372:
    v_21618 = v_21616;
    goto v_21401;
v_21397:
    v_21617 = v_21618;
    goto v_21398;
v_21399:
    v_21616 = elt(env, 1); // or
    goto v_21400;
v_21401:
    goto v_21397;
v_21398:
    goto v_21399;
v_21400:
    if (v_21617 == v_21616) goto v_21395;
    else goto v_21396;
v_21395:
    v_21616 = lisp_true;
    goto v_21394;
v_21396:
    goto v_21411;
v_21407:
    v_21617 = v_21618;
    goto v_21408;
v_21409:
    v_21616 = elt(env, 2); // and
    goto v_21410;
v_21411:
    goto v_21407;
v_21408:
    goto v_21409;
v_21410:
    v_21616 = (v_21617 == v_21616 ? lisp_true : nil);
    goto v_21394;
    v_21616 = nil;
v_21394:
    if (v_21616 == nil) goto v_21392;
    v_21616 = lisp_true;
    goto v_21390;
v_21392:
    goto v_21422;
v_21418:
    v_21617 = v_21618;
    goto v_21419;
v_21420:
    v_21616 = elt(env, 3); // not
    goto v_21421;
v_21422:
    goto v_21418;
v_21419:
    goto v_21420;
v_21421:
    v_21616 = (v_21617 == v_21616 ? lisp_true : nil);
    goto v_21390;
    v_21616 = nil;
v_21390:
    if (v_21616 == nil) goto v_21388;
    v_21616 = lisp_true;
    goto v_21386;
v_21388:
    goto v_21437;
v_21433:
    v_21617 = v_21618;
    goto v_21434;
v_21435:
    v_21616 = elt(env, 4); // impl
    goto v_21436;
v_21437:
    goto v_21433;
v_21434:
    goto v_21435;
v_21436:
    if (v_21617 == v_21616) goto v_21431;
    else goto v_21432;
v_21431:
    v_21616 = lisp_true;
    goto v_21430;
v_21432:
    goto v_21451;
v_21447:
    v_21617 = v_21618;
    goto v_21448;
v_21449:
    v_21616 = elt(env, 5); // repl
    goto v_21450;
v_21451:
    goto v_21447;
v_21448:
    goto v_21449;
v_21450:
    if (v_21617 == v_21616) goto v_21445;
    else goto v_21446;
v_21445:
    v_21616 = lisp_true;
    goto v_21444;
v_21446:
    goto v_21461;
v_21457:
    v_21617 = v_21618;
    goto v_21458;
v_21459:
    v_21616 = elt(env, 6); // equiv
    goto v_21460;
v_21461:
    goto v_21457;
v_21458:
    goto v_21459;
v_21460:
    v_21616 = (v_21617 == v_21616 ? lisp_true : nil);
    goto v_21444;
    v_21616 = nil;
v_21444:
    goto v_21430;
    v_21616 = nil;
v_21430:
    goto v_21386;
    v_21616 = nil;
v_21386:
    if (v_21616 == nil) goto v_21384;
    v_21616 = stack[0];
    v_21616 = qcdr(v_21616);
    stack[-1] = v_21616;
    v_21616 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_21616;
v_21469:
    v_21616 = stack[-1];
    if (v_21616 == nil) goto v_21475;
    else goto v_21476;
v_21475:
    v_21616 = stack[0];
    goto v_21468;
v_21476:
    goto v_21484;
v_21480:
    v_21616 = stack[-1];
    v_21616 = qcar(v_21616);
    v_21617 = CC_cl_atnum(elt(env, 0), v_21616);
    env = stack[-2];
    goto v_21481;
v_21482:
    v_21616 = stack[0];
    goto v_21483;
v_21484:
    goto v_21480;
v_21481:
    goto v_21482;
v_21483:
    v_21616 = plus2(v_21617, v_21616);
    env = stack[-2];
    stack[0] = v_21616;
    v_21616 = stack[-1];
    v_21616 = qcdr(v_21616);
    stack[-1] = v_21616;
    goto v_21469;
v_21468:
    goto v_21370;
v_21384:
    goto v_21505;
v_21501:
    v_21617 = v_21618;
    goto v_21502;
v_21503:
    v_21616 = elt(env, 7); // ex
    goto v_21504;
v_21505:
    goto v_21501;
v_21502:
    goto v_21503;
v_21504:
    if (v_21617 == v_21616) goto v_21499;
    else goto v_21500;
v_21499:
    v_21616 = lisp_true;
    goto v_21498;
v_21500:
    goto v_21515;
v_21511:
    v_21617 = v_21618;
    goto v_21512;
v_21513:
    v_21616 = elt(env, 8); // all
    goto v_21514;
v_21515:
    goto v_21511;
v_21512:
    goto v_21513;
v_21514:
    v_21616 = (v_21617 == v_21616 ? lisp_true : nil);
    goto v_21498;
    v_21616 = nil;
v_21498:
    if (v_21616 == nil) goto v_21496;
    v_21616 = stack[0];
    v_21616 = qcdr(v_21616);
    v_21616 = qcdr(v_21616);
    v_21616 = qcar(v_21616);
    stack[0] = v_21616;
    goto v_21364;
v_21496:
    goto v_21536;
v_21532:
    v_21617 = v_21618;
    goto v_21533;
v_21534:
    v_21616 = elt(env, 9); // bex
    goto v_21535;
v_21536:
    goto v_21532;
v_21533:
    goto v_21534;
v_21535:
    if (v_21617 == v_21616) goto v_21530;
    else goto v_21531;
v_21530:
    v_21616 = lisp_true;
    goto v_21529;
v_21531:
    goto v_21546;
v_21542:
    v_21617 = v_21618;
    goto v_21543;
v_21544:
    v_21616 = elt(env, 10); // ball
    goto v_21545;
v_21546:
    goto v_21542;
v_21543:
    goto v_21544;
v_21545:
    v_21616 = (v_21617 == v_21616 ? lisp_true : nil);
    goto v_21529;
    v_21616 = nil;
v_21529:
    if (v_21616 == nil) goto v_21527;
    goto v_21555;
v_21551:
    v_21616 = stack[0];
    v_21616 = qcdr(v_21616);
    v_21616 = qcdr(v_21616);
    v_21616 = qcar(v_21616);
    stack[-1] = CC_cl_atnum(elt(env, 0), v_21616);
    env = stack[-2];
    goto v_21552;
v_21553:
    v_21616 = stack[0];
    v_21616 = qcdr(v_21616);
    v_21616 = qcdr(v_21616);
    v_21616 = qcdr(v_21616);
    v_21616 = qcar(v_21616);
    v_21616 = CC_cl_atnum(elt(env, 0), v_21616);
    goto v_21554;
v_21555:
    goto v_21551;
v_21552:
    goto v_21553;
v_21554:
    {
        LispObject v_21621 = stack[-1];
        return plus2(v_21621, v_21616);
    }
v_21527:
    goto v_21579;
v_21575:
    v_21617 = v_21618;
    goto v_21576;
v_21577:
    v_21616 = elt(env, 11); // true
    goto v_21578;
v_21579:
    goto v_21575;
v_21576:
    goto v_21577;
v_21578:
    if (v_21617 == v_21616) goto v_21573;
    else goto v_21574;
v_21573:
    v_21616 = lisp_true;
    goto v_21572;
v_21574:
    goto v_21589;
v_21585:
    v_21617 = v_21618;
    goto v_21586;
v_21587:
    v_21616 = elt(env, 12); // false
    goto v_21588;
v_21589:
    goto v_21585;
v_21586:
    goto v_21587;
v_21588:
    v_21616 = (v_21617 == v_21616 ? lisp_true : nil);
    goto v_21572;
    v_21616 = nil;
v_21572:
    if (v_21616 == nil) goto v_21570;
    v_21616 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21370;
v_21570:
    goto v_21603;
v_21599:
    v_21617 = v_21618;
    goto v_21600;
v_21601:
    v_21616 = elt(env, 0); // cl_atnum
    goto v_21602;
v_21603:
    goto v_21599;
v_21600:
    goto v_21601;
v_21602:
    fn = elt(env, 13); // rl_external
    v_21616 = (*qfn2(fn))(fn, v_21617, v_21616);
    env = stack[-2];
    v_21617 = v_21616;
    if (v_21616 == nil) goto v_21597;
    goto v_21611;
v_21607:
    stack[-1] = v_21617;
    goto v_21608;
v_21609:
    v_21616 = stack[0];
    v_21616 = ncons(v_21616);
    env = stack[-2];
    goto v_21610;
v_21611:
    goto v_21607;
v_21608:
    goto v_21609;
v_21610:
    {
        LispObject v_21622 = stack[-1];
        fn = elt(env, 14); // apply
        return (*qfn2(fn))(fn, v_21622, v_21616);
    }
v_21597:
    v_21616 = (LispObject)16+TAG_FIXNUM; // 1
v_21370:
    return onevalue(v_21616);
}



// Code for simpexpt1

static LispObject CC_simpexpt1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21915, v_21916, v_21917;
    LispObject fn;
    LispObject v_21367, v_21366, v_21365;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "simpexpt1");
    va_start(aa, nargs);
    v_21365 = va_arg(aa, LispObject);
    v_21366 = va_arg(aa, LispObject);
    v_21367 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21367,v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21365,v_21366,v_21367);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_21367;
    stack[-5] = v_21366;
    stack[-6] = v_21365;
// end of prologue
// Binding !*allfac
// FLUIDBIND: reloadenv=8 litvec-offset=1 saveloc=7
{   bind_fluid_stack bind_fluid_var(-8, 1, -7);
    qvalue(elt(env, 1)) = nil; // !*allfac
// Binding !*div
// FLUIDBIND: reloadenv=8 litvec-offset=2 saveloc=3
{   bind_fluid_stack bind_fluid_var(-8, 2, -3);
    qvalue(elt(env, 2)) = nil; // !*div
    v_21915 = stack[-6];
    v_21915 = Lonep(nil, v_21915);
    env = stack[-8];
    if (v_21915 == nil) goto v_21379;
    goto v_21387;
v_21383:
    v_21916 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21384;
v_21385:
    v_21915 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21386;
v_21387:
    goto v_21383;
v_21384:
    goto v_21385;
v_21386:
    v_21915 = cons(v_21916, v_21915);
    goto v_21375;
v_21379:
    v_21915 = lisp_true;
    qvalue(elt(env, 1)) = v_21915; // !*allfac
    v_21915 = stack[-5];
    v_21915 = qcar(v_21915);
    stack[-2] = v_21915;
    goto v_21405;
v_21401:
    v_21916 = stack[-2];
    goto v_21402;
v_21403:
    v_21915 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21404;
v_21405:
    goto v_21401;
v_21402:
    goto v_21403;
v_21404:
    if (v_21916 == v_21915) goto v_21399;
    else goto v_21400;
v_21399:
    goto v_21412;
v_21408:
    v_21915 = stack[-5];
    v_21916 = qcdr(v_21915);
    goto v_21409;
v_21410:
    v_21915 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21411;
v_21412:
    goto v_21408;
v_21409:
    goto v_21410;
v_21411:
    v_21915 = (v_21916 == v_21915 ? lisp_true : nil);
    goto v_21398;
v_21400:
    v_21915 = nil;
    goto v_21398;
    v_21915 = nil;
v_21398:
    if (v_21915 == nil) goto v_21396;
    v_21915 = stack[-6];
    fn = elt(env, 10); // simp
    v_21915 = (*qfn1(fn))(fn, v_21915);
    goto v_21375;
v_21396:
    goto v_21434;
v_21430:
    v_21916 = stack[-6];
    goto v_21431;
v_21432:
    v_21915 = elt(env, 3); // e
    goto v_21433;
v_21434:
    goto v_21430;
v_21431:
    goto v_21432;
v_21433:
    if (v_21916 == v_21915) goto v_21428;
    else goto v_21429;
v_21428:
    v_21915 = stack[-5];
    v_21915 = qcdr(v_21915);
    if (!consp(v_21915)) goto v_21443;
    else goto v_21444;
v_21443:
    v_21915 = lisp_true;
    goto v_21442;
v_21444:
    v_21915 = stack[-5];
    v_21915 = qcdr(v_21915);
    v_21915 = qcar(v_21915);
    v_21915 = (consp(v_21915) ? nil : lisp_true);
    goto v_21442;
    v_21915 = nil;
v_21442:
    if (v_21915 == nil) goto v_21440;
    v_21915 = stack[-2];
    if (!consp(v_21915)) goto v_21460;
    else goto v_21461;
v_21460:
    v_21915 = lisp_true;
    goto v_21459;
v_21461:
    v_21915 = stack[-2];
    v_21915 = qcar(v_21915);
    v_21915 = (consp(v_21915) ? nil : lisp_true);
    goto v_21459;
    v_21915 = nil;
v_21459:
    if (v_21915 == nil) goto v_21456;
    else goto v_21457;
v_21456:
    goto v_21477;
v_21473:
    v_21915 = stack[-2];
    v_21915 = qcar(v_21915);
    v_21915 = qcar(v_21915);
    v_21916 = qcdr(v_21915);
    goto v_21474;
v_21475:
    v_21915 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21476;
v_21477:
    goto v_21473;
v_21474:
    goto v_21475;
v_21476:
    if (v_21916 == v_21915) goto v_21471;
    else goto v_21472;
v_21471:
    v_21915 = stack[-2];
    v_21915 = qcdr(v_21915);
    if (v_21915 == nil) goto v_21485;
    else goto v_21486;
v_21485:
    goto v_21494;
v_21490:
    v_21915 = stack[-2];
    v_21915 = qcar(v_21915);
    v_21915 = qcar(v_21915);
    v_21916 = qcar(v_21915);
    goto v_21491;
v_21492:
    v_21915 = elt(env, 4); // log
    goto v_21493;
v_21494:
    goto v_21490;
v_21491:
    goto v_21492;
v_21493:
    v_21915 = Leqcar(nil, v_21916, v_21915);
    env = stack[-8];
    goto v_21484;
v_21486:
    v_21915 = nil;
    goto v_21484;
    v_21915 = nil;
v_21484:
    goto v_21470;
v_21472:
    v_21915 = nil;
    goto v_21470;
    v_21915 = nil;
v_21470:
    goto v_21455;
v_21457:
    v_21915 = nil;
    goto v_21455;
    v_21915 = nil;
v_21455:
    goto v_21438;
v_21440:
    v_21915 = nil;
    goto v_21438;
    v_21915 = nil;
v_21438:
    goto v_21427;
v_21429:
    v_21915 = nil;
    goto v_21427;
    v_21915 = nil;
v_21427:
    if (v_21915 == nil) goto v_21425;
    goto v_21522;
v_21516:
    v_21915 = stack[-2];
    v_21915 = qcar(v_21915);
    v_21915 = qcar(v_21915);
    v_21915 = qcar(v_21915);
    v_21915 = qcdr(v_21915);
    v_21915 = qcar(v_21915);
    fn = elt(env, 11); // simp!*
    v_21915 = (*qfn1(fn))(fn, v_21915);
    env = stack[-8];
    fn = elt(env, 12); // prepsq!*
    stack[0] = (*qfn1(fn))(fn, v_21915);
    env = stack[-8];
    goto v_21517;
v_21518:
    goto v_21536;
v_21532:
    v_21915 = stack[-2];
    v_21915 = qcar(v_21915);
    v_21916 = qcdr(v_21915);
    goto v_21533;
v_21534:
    v_21915 = stack[-5];
    v_21915 = qcdr(v_21915);
    goto v_21535;
v_21536:
    goto v_21532;
v_21533:
    goto v_21534;
v_21535:
    v_21916 = cons(v_21916, v_21915);
    env = stack[-8];
    goto v_21519;
v_21520:
    v_21915 = nil;
    goto v_21521;
v_21522:
    goto v_21516;
v_21517:
    goto v_21518;
v_21519:
    goto v_21520;
v_21521:
    v_21915 = CC_simpexpt1(elt(env, 0), 3, stack[0], v_21916, v_21915);
    goto v_21375;
v_21425:
    v_21915 = stack[-2];
    if (!consp(v_21915)) goto v_21553;
    else goto v_21554;
v_21553:
    v_21915 = lisp_true;
    goto v_21552;
v_21554:
    v_21915 = stack[-2];
    v_21915 = qcar(v_21915);
    v_21915 = (consp(v_21915) ? nil : lisp_true);
    goto v_21552;
    v_21915 = nil;
v_21552:
    if (v_21915 == nil) goto v_21549;
    else goto v_21550;
v_21549:
    v_21915 = lisp_true;
    goto v_21548;
v_21550:
    v_21915 = stack[-5];
    v_21915 = qcdr(v_21915);
    if (!consp(v_21915)) goto v_21567;
    else goto v_21568;
v_21567:
    v_21915 = lisp_true;
    goto v_21566;
v_21568:
    v_21915 = stack[-5];
    v_21915 = qcdr(v_21915);
    v_21915 = qcar(v_21915);
    v_21915 = (consp(v_21915) ? nil : lisp_true);
    goto v_21566;
    v_21915 = nil;
v_21566:
    v_21915 = (v_21915 == nil ? lisp_true : nil);
    goto v_21548;
    v_21915 = nil;
v_21548:
    if (v_21915 == nil) goto v_21546;
    goto v_21586;
v_21580:
    v_21917 = stack[-6];
    goto v_21581;
v_21582:
    v_21916 = stack[-5];
    goto v_21583;
v_21584:
    v_21915 = stack[-4];
    goto v_21585;
v_21586:
    goto v_21580;
v_21581:
    goto v_21582;
v_21583:
    goto v_21584;
v_21585:
    fn = elt(env, 13); // simpexpt11
    v_21915 = (*qfnn(fn))(fn, 3, v_21917, v_21916, v_21915);
    goto v_21375;
v_21546:
    v_21915 = stack[-6];
    fn = elt(env, 10); // simp
    v_21915 = (*qfn1(fn))(fn, v_21915);
    env = stack[-8];
    stack[-1] = v_21915;
    v_21915 = stack[-2];
    if (v_21915 == nil) goto v_21594;
    else goto v_21595;
v_21594:
    v_21915 = stack[-1];
    v_21915 = qcar(v_21915);
    if (v_21915 == nil) goto v_21599;
    else goto v_21600;
v_21599:
    goto v_21610;
v_21604:
    v_21917 = elt(env, 5); // alg
    goto v_21605;
v_21606:
    v_21916 = (LispObject)224+TAG_FIXNUM; // 14
    goto v_21607;
v_21608:
    v_21915 = elt(env, 6); // "0**0 formed"
    goto v_21609;
v_21610:
    goto v_21604;
v_21605:
    goto v_21606;
v_21607:
    goto v_21608;
v_21609:
    fn = elt(env, 14); // rerror
    v_21915 = (*qfnn(fn))(fn, 3, v_21917, v_21916, v_21915);
    goto v_21598;
v_21600:
    goto v_21621;
v_21617:
    v_21916 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21618;
v_21619:
    v_21915 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21620;
v_21621:
    goto v_21617;
v_21618:
    goto v_21619;
v_21620:
    v_21915 = cons(v_21916, v_21915);
    goto v_21598;
    v_21915 = nil;
v_21598:
    goto v_21375;
v_21595:
    v_21915 = stack[-1];
    v_21915 = qcar(v_21915);
    if (v_21915 == nil) goto v_21626;
    else goto v_21627;
v_21626:
    v_21915 = stack[-2];
    if (!consp(v_21915)) goto v_21640;
    else goto v_21641;
v_21640:
    v_21915 = lisp_true;
    goto v_21639;
v_21641:
    v_21915 = stack[-2];
    v_21915 = qcar(v_21915);
    v_21915 = (consp(v_21915) ? nil : lisp_true);
    goto v_21639;
    v_21915 = nil;
v_21639:
    if (v_21915 == nil) goto v_21637;
    v_21915 = stack[-2];
    fn = elt(env, 15); // minusf
    v_21915 = (*qfn1(fn))(fn, v_21915);
    env = stack[-8];
    goto v_21635;
v_21637:
    v_21915 = nil;
    goto v_21635;
    v_21915 = nil;
v_21635:
    if (v_21915 == nil) goto v_21633;
    goto v_21661;
v_21655:
    v_21917 = elt(env, 5); // alg
    goto v_21656;
v_21657:
    v_21916 = (LispObject)240+TAG_FIXNUM; // 15
    goto v_21658;
v_21659:
    v_21915 = elt(env, 7); // "Zero divisor"
    goto v_21660;
v_21661:
    goto v_21655;
v_21656:
    goto v_21657;
v_21658:
    goto v_21659;
v_21660:
    fn = elt(env, 14); // rerror
    v_21915 = (*qfnn(fn))(fn, 3, v_21917, v_21916, v_21915);
    goto v_21631;
v_21633:
    goto v_21672;
v_21668:
    v_21916 = nil;
    goto v_21669;
v_21670:
    v_21915 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21671;
v_21672:
    goto v_21668;
v_21669:
    goto v_21670;
v_21671:
    v_21915 = cons(v_21916, v_21915);
    goto v_21631;
    v_21915 = nil;
v_21631:
    goto v_21625;
v_21627:
    v_21915 = stack[-2];
    if (!consp(v_21915)) goto v_21679;
    else goto v_21680;
v_21679:
    goto v_21690;
v_21686:
    v_21915 = stack[-5];
    v_21916 = qcdr(v_21915);
    goto v_21687;
v_21688:
    v_21915 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21689;
v_21690:
    goto v_21686;
v_21687:
    goto v_21688;
v_21689:
    if (v_21916 == v_21915) goto v_21684;
    else goto v_21685;
v_21684:
    v_21915 = stack[-1];
    v_21915 = qcar(v_21915);
    if (!consp(v_21915)) goto v_21700;
    else goto v_21701;
v_21700:
    v_21915 = lisp_true;
    goto v_21699;
v_21701:
    v_21915 = stack[-1];
    v_21915 = qcar(v_21915);
    v_21915 = qcar(v_21915);
    v_21915 = (consp(v_21915) ? nil : lisp_true);
    goto v_21699;
    v_21915 = nil;
v_21699:
    if (v_21915 == nil) goto v_21697;
    goto v_21715;
v_21711:
    v_21915 = stack[-1];
    v_21916 = qcdr(v_21915);
    goto v_21712;
v_21713:
    v_21915 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21714;
v_21715:
    goto v_21711;
v_21712:
    goto v_21713;
v_21714:
    v_21915 = (v_21916 == v_21915 ? lisp_true : nil);
    goto v_21695;
v_21697:
    v_21915 = nil;
    goto v_21695;
    v_21915 = nil;
v_21695:
    goto v_21683;
v_21685:
    v_21915 = nil;
    goto v_21683;
    v_21915 = nil;
v_21683:
    goto v_21678;
v_21680:
    v_21915 = nil;
    goto v_21678;
    v_21915 = nil;
v_21678:
    if (v_21915 == nil) goto v_21676;
    v_21915 = stack[-1];
    v_21915 = qcar(v_21915);
    if (!consp(v_21915)) goto v_21735;
    else goto v_21736;
v_21735:
    goto v_21744;
v_21740:
    v_21916 = stack[-2];
    goto v_21741;
v_21742:
    v_21915 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21743;
v_21744:
    goto v_21740;
v_21741:
    goto v_21742;
v_21743:
    v_21915 = (LispObject)greaterp2(v_21916, v_21915);
    v_21915 = v_21915 ? lisp_true : nil;
    env = stack[-8];
    goto v_21734;
v_21736:
    v_21915 = nil;
    goto v_21734;
    v_21915 = nil;
v_21734:
    if (v_21915 == nil) goto v_21732;
    goto v_21756;
v_21752:
    v_21915 = stack[-1];
    v_21916 = qcar(v_21915);
    goto v_21753;
v_21754:
    v_21915 = stack[-2];
    goto v_21755;
v_21756:
    goto v_21752;
v_21753:
    goto v_21754;
v_21755:
    v_21915 = Lexpt(nil, v_21916, v_21915);
    env = stack[-8];
    fn = elt(env, 16); // !*d2q
    v_21915 = (*qfn1(fn))(fn, v_21915);
    goto v_21730;
v_21732:
    goto v_21767;
v_21763:
    goto v_21773;
v_21769:
    v_21915 = stack[-1];
    v_21916 = qcar(v_21915);
    goto v_21770;
v_21771:
    v_21915 = stack[-2];
    goto v_21772;
v_21773:
    goto v_21769;
v_21770:
    goto v_21771;
v_21772:
    fn = elt(env, 17); // !:expt
    v_21916 = (*qfn2(fn))(fn, v_21916, v_21915);
    env = stack[-8];
    goto v_21764;
v_21765:
    v_21915 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21766;
v_21767:
    goto v_21763;
v_21764:
    goto v_21765;
v_21766:
    v_21915 = cons(v_21916, v_21915);
    env = stack[-8];
    stack[-1] = v_21915;
    v_21915 = qvalue(elt(env, 8)); // !*mcd
    if (v_21915 == nil) goto v_21781;
    v_21915 = stack[-1];
    fn = elt(env, 18); // resimp
    v_21915 = (*qfn1(fn))(fn, v_21915);
    goto v_21779;
v_21781:
    v_21915 = stack[-1];
    goto v_21779;
    v_21915 = nil;
v_21779:
    goto v_21730;
    v_21915 = nil;
v_21730:
    goto v_21625;
v_21676:
    goto v_21795;
v_21791:
    stack[0] = elt(env, 9); // expt
    goto v_21792;
v_21793:
    goto v_21802;
v_21798:
    v_21916 = stack[-1];
    goto v_21799;
v_21800:
    v_21915 = stack[-5];
    goto v_21801;
v_21802:
    goto v_21798;
v_21799:
    goto v_21800;
v_21801:
    v_21915 = list2(v_21916, v_21915);
    env = stack[-8];
    goto v_21794;
v_21795:
    goto v_21791;
v_21792:
    goto v_21793;
v_21794:
    fn = elt(env, 19); // domainvalchk
    v_21915 = (*qfn2(fn))(fn, stack[0], v_21915);
    env = stack[-8];
    v_21916 = v_21915;
    if (v_21915 == nil) goto v_21789;
    v_21915 = v_21916;
    goto v_21625;
v_21789:
    v_21915 = stack[-2];
    if (!consp(v_21915)) goto v_21810;
    else goto v_21811;
v_21810:
    goto v_21817;
v_21813:
    v_21915 = stack[-5];
    v_21916 = qcdr(v_21915);
    goto v_21814;
v_21815:
    v_21915 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21816;
v_21817:
    goto v_21813;
v_21814:
    goto v_21815;
v_21816:
    v_21915 = (v_21916 == v_21915 ? lisp_true : nil);
    goto v_21809;
v_21811:
    v_21915 = nil;
    goto v_21809;
    v_21915 = nil;
v_21809:
    if (v_21915 == nil) goto v_21807;
    goto v_21834;
v_21830:
    v_21916 = stack[-2];
    goto v_21831;
v_21832:
    v_21915 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21833;
v_21834:
    goto v_21830;
v_21831:
    goto v_21832;
v_21833:
    v_21915 = (LispObject)lessp2(v_21916, v_21915);
    v_21915 = v_21915 ? lisp_true : nil;
    env = stack[-8];
    if (v_21915 == nil) goto v_21827;
    else goto v_21828;
v_21827:
    goto v_21842;
v_21838:
    v_21916 = stack[-1];
    goto v_21839;
v_21840:
    v_21915 = stack[-2];
    goto v_21841;
v_21842:
    goto v_21838;
v_21839:
    goto v_21840;
v_21841:
    fn = elt(env, 20); // exptsq
    v_21915 = (*qfn2(fn))(fn, v_21916, v_21915);
    goto v_21826;
v_21828:
    v_21915 = qvalue(elt(env, 8)); // !*mcd
    if (v_21915 == nil) goto v_21846;
    goto v_21854;
v_21850:
    stack[0] = stack[-1];
    goto v_21851;
v_21852:
    v_21915 = stack[-2];
    v_21915 = negate(v_21915);
    env = stack[-8];
    goto v_21853;
v_21854:
    goto v_21850;
v_21851:
    goto v_21852;
v_21853:
    fn = elt(env, 20); // exptsq
    v_21915 = (*qfn2(fn))(fn, stack[0], v_21915);
    env = stack[-8];
    fn = elt(env, 21); // invsq
    v_21915 = (*qfn1(fn))(fn, v_21915);
    goto v_21826;
v_21846:
    goto v_21865;
v_21861:
    goto v_21871;
v_21867:
    goto v_21877;
v_21873:
    v_21915 = stack[-1];
    v_21916 = qcar(v_21915);
    goto v_21874;
v_21875:
    v_21915 = stack[-2];
    goto v_21876;
v_21877:
    goto v_21873;
v_21874:
    goto v_21875;
v_21876:
    fn = elt(env, 22); // expf
    stack[0] = (*qfn2(fn))(fn, v_21916, v_21915);
    env = stack[-8];
    goto v_21868;
v_21869:
    goto v_21886;
v_21882:
    v_21915 = stack[-1];
    stack[-1] = qcdr(v_21915);
    goto v_21883;
v_21884:
    v_21915 = stack[-2];
    v_21915 = negate(v_21915);
    env = stack[-8];
    goto v_21885;
v_21886:
    goto v_21882;
v_21883:
    goto v_21884;
v_21885:
    fn = elt(env, 23); // mksfpf
    v_21915 = (*qfn2(fn))(fn, stack[-1], v_21915);
    env = stack[-8];
    goto v_21870;
v_21871:
    goto v_21867;
v_21868:
    goto v_21869;
v_21870:
    fn = elt(env, 24); // multf
    v_21916 = (*qfn2(fn))(fn, stack[0], v_21915);
    env = stack[-8];
    goto v_21862;
v_21863:
    v_21915 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21864;
v_21865:
    goto v_21861;
v_21862:
    goto v_21863;
v_21864:
    v_21915 = cons(v_21916, v_21915);
    goto v_21826;
    v_21915 = nil;
v_21826:
    goto v_21625;
v_21807:
    goto v_21901;
v_21895:
    v_21915 = stack[-4];
    if (v_21915 == nil) goto v_21905;
    v_21915 = stack[-6];
    v_21917 = v_21915;
    goto v_21903;
v_21905:
    v_21915 = stack[-1];
    fn = elt(env, 25); // subs2!*
    v_21915 = (*qfn1(fn))(fn, v_21915);
    env = stack[-8];
    fn = elt(env, 12); // prepsq!*
    v_21915 = (*qfn1(fn))(fn, v_21915);
    env = stack[-8];
    v_21917 = v_21915;
    goto v_21903;
    v_21917 = nil;
v_21903:
    goto v_21896;
v_21897:
    v_21916 = stack[-5];
    goto v_21898;
v_21899:
    v_21915 = lisp_true;
    goto v_21900;
v_21901:
    goto v_21895;
v_21896:
    goto v_21897;
v_21898:
    goto v_21899;
v_21900:
    fn = elt(env, 13); // simpexpt11
    v_21915 = (*qfnn(fn))(fn, 3, v_21917, v_21916, v_21915);
    goto v_21625;
    v_21915 = nil;
v_21625:
v_21375:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_21915);
}



// Code for rl_bnfsimpl

static LispObject CC_rl_bnfsimpl(LispObject env,
                         LispObject v_21365, LispObject v_21366)
{
    env = qenv(env);
    LispObject v_21383, v_21384;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21365,v_21366);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21383 = v_21366;
    v_21384 = v_21365;
// end of prologue
    goto v_21373;
v_21369:
    stack[0] = qvalue(elt(env, 1)); // rl_bnfsimpl!*
    goto v_21370;
v_21371:
    goto v_21380;
v_21376:
    goto v_21377;
v_21378:
    goto v_21379;
v_21380:
    goto v_21376;
v_21377:
    goto v_21378;
v_21379:
    v_21383 = list2(v_21384, v_21383);
    env = stack[-1];
    goto v_21372;
v_21373:
    goto v_21369;
v_21370:
    goto v_21371;
v_21372:
    {
        LispObject v_21386 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_21386, v_21383);
    }
}



// Code for dvfsf_smupdknowl

static LispObject CC_dvfsf_smupdknowl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21405, v_21406, v_21407, v_21408, v_21409;
    LispObject fn;
    LispObject v_21368, v_21367, v_21366, v_21365;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "dvfsf_smupdknowl");
    va_start(aa, nargs);
    v_21365 = va_arg(aa, LispObject);
    v_21366 = va_arg(aa, LispObject);
    v_21367 = va_arg(aa, LispObject);
    v_21368 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21406 = v_21368;
    v_21407 = v_21367;
    v_21408 = v_21366;
    v_21409 = v_21365;
// end of prologue
    v_21405 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_21405 == nil) goto v_21373;
    goto v_21384;
v_21376:
    v_21405 = v_21409;
    goto v_21377;
v_21378:
    goto v_21379;
v_21380:
    goto v_21381;
v_21382:
    goto v_21383;
v_21384:
    goto v_21376;
v_21377:
    goto v_21378;
v_21379:
    goto v_21380;
v_21381:
    goto v_21382;
v_21383:
    {
        fn = elt(env, 2); // cl_susiupdknowl
        return (*qfnn(fn))(fn, 4, v_21405, v_21408, v_21407, v_21406);
    }
v_21373:
    goto v_21400;
v_21392:
    v_21405 = v_21409;
    goto v_21393;
v_21394:
    goto v_21395;
v_21396:
    goto v_21397;
v_21398:
    goto v_21399;
v_21400:
    goto v_21392;
v_21393:
    goto v_21394;
v_21395:
    goto v_21396;
v_21397:
    goto v_21398;
v_21399:
    {
        fn = elt(env, 3); // cl_smupdknowl
        return (*qfnn(fn))(fn, 4, v_21405, v_21408, v_21407, v_21406);
    }
    v_21405 = nil;
    return onevalue(v_21405);
}



// Code for groebinvokecritm

static LispObject CC_groebinvokecritm(LispObject env,
                         LispObject v_21365, LispObject v_21366)
{
    env = qenv(env);
    LispObject v_21409, v_21410;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21365,v_21366);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_21366;
    stack[-2] = v_21365;
// end of prologue
    v_21409 = stack[-1];
    stack[-3] = v_21409;
v_21371:
    v_21409 = stack[-3];
    if (v_21409 == nil) goto v_21375;
    else goto v_21376;
v_21375:
    goto v_21370;
v_21376:
    v_21409 = stack[-3];
    v_21409 = qcar(v_21409);
    stack[0] = v_21409;
    goto v_21391;
v_21387:
    v_21409 = stack[-2];
    v_21410 = qcar(v_21409);
    goto v_21388;
v_21389:
    v_21409 = stack[0];
    v_21409 = qcar(v_21409);
    goto v_21390;
v_21391:
    goto v_21387;
v_21388:
    goto v_21389;
v_21390:
    fn = elt(env, 2); // buchvevdivides!?
    v_21409 = (*qfn2(fn))(fn, v_21410, v_21409);
    env = stack[-4];
    if (v_21409 == nil) goto v_21385;
    v_21409 = qvalue(elt(env, 1)); // mcount!*
    v_21409 = add1(v_21409);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_21409; // mcount!*
    goto v_21403;
v_21399:
    v_21410 = stack[0];
    goto v_21400;
v_21401:
    v_21409 = stack[-1];
    goto v_21402;
v_21403:
    goto v_21399;
v_21400:
    goto v_21401;
v_21402:
    fn = elt(env, 3); // groedeletip
    v_21409 = (*qfn2(fn))(fn, v_21410, v_21409);
    env = stack[-4];
    stack[-1] = v_21409;
    goto v_21383;
v_21385:
v_21383:
    v_21409 = stack[-3];
    v_21409 = qcdr(v_21409);
    stack[-3] = v_21409;
    goto v_21371;
v_21370:
    v_21409 = stack[-1];
    return onevalue(v_21409);
}



// Code for vdpcleanup

static LispObject CC_vdpcleanup(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21368;
    argcheck(nargs, 0, "vdpcleanup");
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
    v_21368 = nil;
    v_21368 = ncons(v_21368);
    env = stack[0];
    qvalue(elt(env, 1)) = v_21368; // dipevlist!*
    return onevalue(v_21368);
}



// Code for bflessp

static LispObject CC_bflessp(LispObject env,
                         LispObject v_21365, LispObject v_21366)
{
    env = qenv(env);
    LispObject v_21391, v_21392, v_21393;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21392 = v_21366;
    v_21393 = v_21365;
// end of prologue
    v_21391 = v_21393;
    if (!consp(v_21391)) goto v_21370;
    else goto v_21371;
v_21370:
    goto v_21378;
v_21374:
    v_21391 = v_21393;
    goto v_21375;
v_21376:
    goto v_21377;
v_21378:
    goto v_21374;
v_21375:
    goto v_21376;
v_21377:
        return Llessp(nil, v_21391, v_21392);
v_21371:
    goto v_21388;
v_21384:
    v_21391 = v_21392;
    goto v_21385;
v_21386:
    v_21392 = v_21393;
    goto v_21387;
v_21388:
    goto v_21384;
v_21385:
    goto v_21386;
v_21387:
    {
        fn = elt(env, 1); // grpbf
        return (*qfn2(fn))(fn, v_21391, v_21392);
    }
    v_21391 = nil;
    return onevalue(v_21391);
}



// Code for intrdsortin

static LispObject CC_intrdsortin(LispObject env,
                         LispObject v_21365, LispObject v_21366)
{
    env = qenv(env);
    LispObject v_21432, v_21433;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21365,v_21366);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21366;
    stack[-1] = v_21365;
// end of prologue
    stack[-2] = nil;
v_21371:
    v_21432 = stack[0];
    if (v_21432 == nil) goto v_21374;
    else goto v_21375;
v_21374:
    goto v_21382;
v_21378:
    stack[0] = stack[-2];
    goto v_21379;
v_21380:
    v_21432 = stack[-1];
    v_21432 = ncons(v_21432);
    env = stack[-3];
    goto v_21381;
v_21382:
    goto v_21378;
v_21379:
    goto v_21380;
v_21381:
    {
        LispObject v_21437 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_21437, v_21432);
    }
v_21375:
    v_21432 = stack[-1];
    v_21433 = qcar(v_21432);
    v_21432 = stack[0];
    v_21432 = qcar(v_21432);
    v_21432 = qcar(v_21432);
    goto v_21401;
v_21397:
    goto v_21398;
v_21399:
    goto v_21400;
v_21401:
    goto v_21397;
v_21398:
    goto v_21399;
v_21400:
    fn = elt(env, 2); // !:difference
    v_21432 = (*qfn2(fn))(fn, v_21433, v_21432);
    env = stack[-3];
    fn = elt(env, 3); // !:minusp
    v_21432 = (*qfn1(fn))(fn, v_21432);
    env = stack[-3];
    if (v_21432 == nil) goto v_21387;
    goto v_21409;
v_21405:
    v_21432 = stack[0];
    v_21433 = qcar(v_21432);
    goto v_21406;
v_21407:
    v_21432 = stack[-2];
    goto v_21408;
v_21409:
    goto v_21405;
v_21406:
    goto v_21407;
v_21408:
    v_21432 = cons(v_21433, v_21432);
    env = stack[-3];
    stack[-2] = v_21432;
    v_21432 = stack[0];
    v_21432 = qcdr(v_21432);
    stack[0] = v_21432;
    goto v_21371;
v_21387:
    goto v_21422;
v_21418:
    goto v_21419;
v_21420:
    goto v_21429;
v_21425:
    v_21433 = stack[-1];
    goto v_21426;
v_21427:
    v_21432 = stack[0];
    goto v_21428;
v_21429:
    goto v_21425;
v_21426:
    goto v_21427;
v_21428:
    v_21432 = cons(v_21433, v_21432);
    env = stack[-3];
    goto v_21421;
v_21422:
    goto v_21418;
v_21419:
    goto v_21420;
v_21421:
    {
        LispObject v_21438 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_21438, v_21432);
    }
    v_21432 = nil;
    return onevalue(v_21432);
}



// Code for z!-roads

static LispObject CC_zKroads(LispObject env,
                         LispObject v_21365)
{
    env = qenv(env);
    LispObject v_21442, v_21443, v_21444;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21443 = v_21365;
// end of prologue
    goto v_21375;
v_21371:
    v_21444 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21372;
v_21373:
    v_21442 = v_21443;
    v_21442 = qcar(v_21442);
    v_21442 = qcar(v_21442);
    v_21442 = qcdr(v_21442);
    goto v_21374;
v_21375:
    goto v_21371;
v_21372:
    goto v_21373;
v_21374:
    if (v_21444 == v_21442) goto v_21369;
    else goto v_21370;
v_21369:
    v_21442 = v_21443;
    v_21442 = qcar(v_21442);
    v_21442 = qcar(v_21442);
    goto v_21368;
v_21370:
    goto v_21390;
v_21386:
    v_21444 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21387;
v_21388:
    v_21442 = v_21443;
    v_21442 = qcar(v_21442);
    v_21442 = qcdr(v_21442);
    v_21442 = qcar(v_21442);
    v_21442 = qcdr(v_21442);
    goto v_21389;
v_21390:
    goto v_21386;
v_21387:
    goto v_21388;
v_21389:
    if (v_21444 == v_21442) goto v_21384;
    else goto v_21385;
v_21384:
    v_21442 = v_21443;
    v_21442 = qcar(v_21442);
    v_21442 = qcdr(v_21442);
    v_21442 = qcar(v_21442);
    goto v_21368;
v_21385:
    goto v_21407;
v_21403:
    v_21444 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21404;
v_21405:
    v_21442 = v_21443;
    v_21442 = qcar(v_21442);
    v_21442 = qcdr(v_21442);
    v_21442 = qcdr(v_21442);
    v_21442 = qcar(v_21442);
    v_21442 = qcdr(v_21442);
    goto v_21406;
v_21407:
    goto v_21403;
v_21404:
    goto v_21405;
v_21406:
    if (v_21444 == v_21442) goto v_21401;
    else goto v_21402;
v_21401:
    v_21442 = v_21443;
    v_21442 = qcar(v_21442);
    v_21442 = qcdr(v_21442);
    v_21442 = qcdr(v_21442);
    v_21442 = qcar(v_21442);
    goto v_21368;
v_21402:
    v_21442 = nil;
    goto v_21368;
    v_21442 = nil;
v_21368:
    v_21444 = v_21442;
    v_21442 = v_21444;
    if (v_21442 == nil) goto v_21426;
    else goto v_21427;
v_21426:
    v_21442 = nil;
    goto v_21425;
v_21427:
    goto v_21437;
v_21433:
    v_21442 = v_21444;
    v_21442 = qcar(v_21442);
    goto v_21434;
v_21435:
    v_21443 = qcdr(v_21443);
    goto v_21436;
v_21437:
    goto v_21433;
v_21434:
    goto v_21435;
v_21436:
    return cons(v_21442, v_21443);
    v_21442 = nil;
v_21425:
    return onevalue(v_21442);
}



// Code for janettreenodebuild

static LispObject CC_janettreenodebuild(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21483, v_21484;
    LispObject fn;
    LispObject v_21367, v_21366, v_21365;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "janettreenodebuild");
    va_start(aa, nargs);
    v_21365 = va_arg(aa, LispObject);
    v_21366 = va_arg(aa, LispObject);
    v_21367 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21367,v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21365,v_21366,v_21367);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-5] = v_21367;
    stack[-6] = v_21366;
    stack[-7] = v_21365;
// end of prologue
    goto v_21378;
v_21374:
    v_21484 = stack[-5];
    goto v_21375;
v_21376:
    v_21483 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21377;
v_21378:
    goto v_21374;
v_21375:
    goto v_21376;
v_21377:
    v_21483 = *(LispObject *)((char *)v_21484 + (CELL-TAG_VECTOR) + (((intptr_t)v_21483-TAG_FIXNUM)/(16/CELL)));
    v_21483 = qcar(v_21483);
    stack[-3] = v_21483;
    goto v_21390;
v_21384:
    goto v_21396;
v_21392:
    v_21484 = stack[-3];
    goto v_21393;
v_21394:
    v_21483 = stack[-6];
    goto v_21395;
v_21396:
    goto v_21392;
v_21393:
    goto v_21394;
v_21395:
    fn = elt(env, 1); // monomgetvariabledegree
    stack[-1] = (*qfn2(fn))(fn, v_21484, v_21483);
    env = stack[-9];
    goto v_21385;
v_21386:
    stack[0] = nil;
    goto v_21387;
v_21388:
    v_21483 = nil;
    v_21483 = ncons(v_21483);
    env = stack[-9];
    goto v_21389;
v_21390:
    goto v_21384;
v_21385:
    goto v_21386;
v_21387:
    goto v_21388;
v_21389:
    v_21483 = acons(stack[-1], stack[0], v_21483);
    env = stack[-9];
    stack[-8] = v_21483;
    v_21483 = stack[-8];
    stack[-4] = v_21483;
v_21405:
    goto v_21414;
v_21410:
    stack[0] = stack[-7];
    goto v_21411;
v_21412:
    goto v_21421;
v_21417:
    v_21484 = stack[-3];
    goto v_21418;
v_21419:
    v_21483 = stack[-6];
    goto v_21420;
v_21421:
    goto v_21417;
v_21418:
    goto v_21419;
v_21420:
    fn = elt(env, 1); // monomgetvariabledegree
    v_21483 = (*qfn2(fn))(fn, v_21484, v_21483);
    env = stack[-9];
    goto v_21413;
v_21414:
    goto v_21410;
v_21411:
    goto v_21412;
v_21413:
    if (((intptr_t)(stack[0])) > ((intptr_t)(v_21483))) goto v_21409;
    goto v_21404;
v_21409:
    goto v_21429;
v_21425:
    stack[0] = stack[-7];
    goto v_21426;
v_21427:
    goto v_21436;
v_21432:
    v_21484 = stack[-3];
    goto v_21433;
v_21434:
    v_21483 = stack[-6];
    goto v_21435;
v_21436:
    goto v_21432;
v_21433:
    goto v_21434;
v_21435:
    fn = elt(env, 1); // monomgetvariabledegree
    v_21483 = (*qfn2(fn))(fn, v_21484, v_21483);
    env = stack[-9];
    goto v_21428;
v_21429:
    goto v_21425;
v_21426:
    goto v_21427;
v_21428:
    v_21483 = (LispObject)(intptr_t)((intptr_t)stack[0] - (intptr_t)v_21483 + TAG_FIXNUM);
    stack[-7] = v_21483;
    v_21483 = stack[-6];
    v_21483 = (LispObject)((intptr_t)(v_21483) + 0x10);
    stack[-6] = v_21483;
    goto v_21447;
v_21443:
    v_21483 = stack[-4];
    stack[-2] = qcdr(v_21483);
    goto v_21444;
v_21445:
    goto v_21457;
v_21451:
    goto v_21463;
v_21459:
    v_21484 = stack[-3];
    goto v_21460;
v_21461:
    v_21483 = stack[-6];
    goto v_21462;
v_21463:
    goto v_21459;
v_21460:
    goto v_21461;
v_21462:
    fn = elt(env, 1); // monomgetvariabledegree
    stack[-1] = (*qfn2(fn))(fn, v_21484, v_21483);
    env = stack[-9];
    goto v_21452;
v_21453:
    stack[0] = nil;
    goto v_21454;
v_21455:
    v_21483 = nil;
    v_21483 = ncons(v_21483);
    env = stack[-9];
    goto v_21456;
v_21457:
    goto v_21451;
v_21452:
    goto v_21453;
v_21454:
    goto v_21455;
v_21456:
    v_21483 = acons(stack[-1], stack[0], v_21483);
    env = stack[-9];
    goto v_21446;
v_21447:
    goto v_21443;
v_21444:
    goto v_21445;
v_21446:
    fn = elt(env, 2); // setcdr
    v_21483 = (*qfn2(fn))(fn, stack[-2], v_21483);
    env = stack[-9];
    v_21483 = stack[-4];
    v_21483 = qcdr(v_21483);
    v_21483 = qcdr(v_21483);
    stack[-4] = v_21483;
    goto v_21405;
v_21404:
    goto v_21478;
v_21474:
    v_21483 = stack[-4];
    v_21484 = qcar(v_21483);
    goto v_21475;
v_21476:
    v_21483 = stack[-5];
    goto v_21477;
v_21478:
    goto v_21474;
v_21475:
    goto v_21476;
v_21477:
    fn = elt(env, 2); // setcdr
    v_21483 = (*qfn2(fn))(fn, v_21484, v_21483);
    v_21483 = stack[-8];
    return onevalue(v_21483);
}



// Code for ofsf_qesubqat

static LispObject CC_ofsf_qesubqat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21562, v_21563, v_21564;
    LispObject fn;
    LispObject v_21367, v_21366, v_21365;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_qesubqat");
    va_start(aa, nargs);
    v_21365 = va_arg(aa, LispObject);
    v_21366 = va_arg(aa, LispObject);
    v_21367 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21367,v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21365,v_21366,v_21367);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_21367;
    stack[-1] = v_21366;
    stack[-2] = v_21365;
// end of prologue
    goto v_21382;
v_21378:
    stack[-3] = stack[-1];
    goto v_21379;
v_21380:
    v_21562 = stack[-2];
    fn = elt(env, 6); // ofsf_varlat
    v_21562 = (*qfn1(fn))(fn, v_21562);
    env = stack[-4];
    goto v_21381;
v_21382:
    goto v_21378;
v_21379:
    goto v_21380;
v_21381:
    v_21562 = Lmemq(nil, stack[-3], v_21562);
    if (v_21562 == nil) goto v_21376;
    else goto v_21377;
v_21376:
    v_21562 = stack[-2];
    goto v_21373;
v_21377:
    v_21562 = qvalue(elt(env, 1)); // !*rlqesubf
    if (v_21562 == nil) goto v_21391;
    goto v_21398;
v_21394:
    v_21562 = stack[-2];
    v_21562 = qcdr(v_21562);
    stack[-3] = qcar(v_21562);
    goto v_21395;
v_21396:
    goto v_21408;
v_21404:
    goto v_21405;
v_21406:
    v_21562 = stack[0];
    fn = elt(env, 7); // prepsq
    v_21562 = (*qfn1(fn))(fn, v_21562);
    env = stack[-4];
    goto v_21407;
v_21408:
    goto v_21404;
v_21405:
    goto v_21406;
v_21407:
    v_21562 = cons(stack[-1], v_21562);
    env = stack[-4];
    v_21562 = ncons(v_21562);
    env = stack[-4];
    goto v_21397;
v_21398:
    goto v_21394;
v_21395:
    goto v_21396;
v_21397:
    fn = elt(env, 8); // subf
    v_21562 = (*qfn2(fn))(fn, stack[-3], v_21562);
    env = stack[-4];
    goto v_21389;
v_21391:
    goto v_21421;
v_21415:
    v_21562 = stack[-2];
    v_21562 = qcdr(v_21562);
    v_21564 = qcar(v_21562);
    goto v_21416;
v_21417:
    v_21563 = stack[-1];
    goto v_21418;
v_21419:
    v_21562 = stack[0];
    goto v_21420;
v_21421:
    goto v_21415;
v_21416:
    goto v_21417;
v_21418:
    goto v_21419;
v_21420:
    fn = elt(env, 9); // ofsf_subf
    v_21562 = (*qfnn(fn))(fn, 3, v_21564, v_21563, v_21562);
    env = stack[-4];
    goto v_21389;
    v_21562 = nil;
v_21389:
    stack[-1] = v_21562;
    v_21562 = stack[-2];
    v_21562 = qcar(v_21562);
    stack[0] = v_21562;
    v_21562 = qvalue(elt(env, 2)); // !*rlqelocal
    if (v_21562 == nil) goto v_21432;
    goto v_21439;
v_21435:
    v_21563 = stack[0];
    goto v_21436;
v_21437:
    v_21562 = stack[-1];
    goto v_21438;
v_21439:
    goto v_21435;
v_21436:
    goto v_21437;
v_21438:
    {
        fn = elt(env, 10); // ofsf_qesubqat!-local
        return (*qfn2(fn))(fn, v_21563, v_21562);
    }
v_21432:
    goto v_21454;
v_21450:
    v_21563 = stack[0];
    goto v_21451;
v_21452:
    v_21562 = elt(env, 3); // equal
    goto v_21453;
v_21454:
    goto v_21450;
v_21451:
    goto v_21452;
v_21453:
    if (v_21563 == v_21562) goto v_21448;
    else goto v_21449;
v_21448:
    v_21562 = lisp_true;
    goto v_21447;
v_21449:
    goto v_21468;
v_21464:
    v_21563 = stack[0];
    goto v_21465;
v_21466:
    v_21562 = elt(env, 4); // neq
    goto v_21467;
v_21468:
    goto v_21464;
v_21465:
    goto v_21466;
v_21467:
    if (v_21563 == v_21562) goto v_21462;
    else goto v_21463;
v_21462:
    v_21562 = lisp_true;
    goto v_21461;
v_21463:
    goto v_21479;
v_21475:
    goto v_21487;
v_21481:
    v_21564 = elt(env, 5); // geq
    goto v_21482;
v_21483:
    v_21562 = stack[-1];
    v_21563 = qcdr(v_21562);
    goto v_21484;
v_21485:
    v_21562 = nil;
    goto v_21486;
v_21487:
    goto v_21481;
v_21482:
    goto v_21483;
v_21484:
    goto v_21485;
v_21486:
    v_21563 = list3(v_21564, v_21563, v_21562);
    env = stack[-4];
    goto v_21476;
v_21477:
    v_21562 = nil;
    goto v_21478;
v_21479:
    goto v_21475;
v_21476:
    goto v_21477;
v_21478:
    fn = elt(env, 11); // ofsf_surep
    v_21562 = (*qfn2(fn))(fn, v_21563, v_21562);
    env = stack[-4];
    goto v_21461;
    v_21562 = nil;
v_21461:
    goto v_21447;
    v_21562 = nil;
v_21447:
    if (v_21562 == nil) goto v_21445;
    goto v_21500;
v_21494:
    v_21564 = stack[0];
    goto v_21495;
v_21496:
    v_21562 = stack[-1];
    v_21563 = qcar(v_21562);
    goto v_21497;
v_21498:
    v_21562 = nil;
    goto v_21499;
v_21500:
    goto v_21494;
v_21495:
    goto v_21496;
v_21497:
    goto v_21498;
v_21499:
    return list3(v_21564, v_21563, v_21562);
v_21445:
    v_21562 = stack[-1];
    v_21562 = qcdr(v_21562);
    fn = elt(env, 12); // sfto_pdecf
    v_21562 = (*qfn1(fn))(fn, v_21562);
    env = stack[-4];
    v_21562 = qcar(v_21562);
    stack[-2] = v_21562;
    goto v_21518;
v_21514:
    goto v_21526;
v_21520:
    v_21564 = elt(env, 5); // geq
    goto v_21521;
v_21522:
    v_21563 = stack[-2];
    goto v_21523;
v_21524:
    v_21562 = nil;
    goto v_21525;
v_21526:
    goto v_21520;
v_21521:
    goto v_21522;
v_21523:
    goto v_21524;
v_21525:
    v_21563 = list3(v_21564, v_21563, v_21562);
    env = stack[-4];
    goto v_21515;
v_21516:
    v_21562 = nil;
    goto v_21517;
v_21518:
    goto v_21514;
v_21515:
    goto v_21516;
v_21517:
    fn = elt(env, 11); // ofsf_surep
    v_21562 = (*qfn2(fn))(fn, v_21563, v_21562);
    env = stack[-4];
    if (v_21562 == nil) goto v_21512;
    goto v_21538;
v_21532:
    v_21564 = stack[0];
    goto v_21533;
v_21534:
    v_21562 = stack[-1];
    v_21563 = qcar(v_21562);
    goto v_21535;
v_21536:
    v_21562 = nil;
    goto v_21537;
v_21538:
    goto v_21532;
v_21533:
    goto v_21534;
v_21535:
    goto v_21536;
v_21537:
    return list3(v_21564, v_21563, v_21562);
v_21512:
    goto v_21550;
v_21544:
    goto v_21545;
v_21546:
    goto v_21557;
v_21553:
    v_21562 = stack[-1];
    v_21563 = qcar(v_21562);
    goto v_21554;
v_21555:
    v_21562 = stack[-2];
    goto v_21556;
v_21557:
    goto v_21553;
v_21554:
    goto v_21555;
v_21556:
    fn = elt(env, 13); // multf
    v_21563 = (*qfn2(fn))(fn, v_21563, v_21562);
    goto v_21547;
v_21548:
    v_21562 = nil;
    goto v_21549;
v_21550:
    goto v_21544;
v_21545:
    goto v_21546;
v_21547:
    goto v_21548;
v_21549:
    {
        LispObject v_21569 = stack[0];
        return list3(v_21569, v_21563, v_21562);
    }
v_21373:
    return onevalue(v_21562);
}



// Code for testord

static LispObject CC_testord(LispObject env,
                         LispObject v_21365, LispObject v_21366)
{
    env = qenv(env);
    LispObject v_21396, v_21397;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21365,v_21366);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21366;
    stack[-1] = v_21365;
// end of prologue
v_21370:
    v_21396 = stack[-1];
    if (v_21396 == nil) goto v_21373;
    else goto v_21374;
v_21373:
    v_21396 = lisp_true;
    goto v_21369;
v_21374:
    goto v_21384;
v_21380:
    v_21396 = stack[-1];
    v_21397 = qcar(v_21396);
    goto v_21381;
v_21382:
    v_21396 = stack[0];
    v_21396 = qcar(v_21396);
    goto v_21383;
v_21384:
    goto v_21380;
v_21381:
    goto v_21382;
v_21383:
    v_21396 = (LispObject)lesseq2(v_21397, v_21396);
    v_21396 = v_21396 ? lisp_true : nil;
    env = stack[-2];
    if (v_21396 == nil) goto v_21378;
    v_21396 = stack[-1];
    v_21396 = qcdr(v_21396);
    stack[-1] = v_21396;
    v_21396 = stack[0];
    v_21396 = qcdr(v_21396);
    stack[0] = v_21396;
    goto v_21370;
v_21378:
    v_21396 = nil;
    goto v_21369;
    v_21396 = nil;
v_21369:
    return onevalue(v_21396);
}



// Code for tayfkern

static LispObject CC_tayfkern(LispObject env,
                         LispObject v_21365)
{
    env = qenv(env);
    LispObject v_21428, v_21429, v_21430;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21365);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_21430 = v_21365;
// end of prologue
    v_21428 = qvalue(elt(env, 1)); // !*tayinternal!*
    if (v_21428 == nil) goto v_21374;
    v_21428 = v_21430;
    goto v_21370;
v_21374:
    v_21428 = elt(env, 2); // taylor!*
    if (!symbolp(v_21428)) v_21428 = nil;
    else { v_21428 = qfastgets(v_21428);
           if (v_21428 != nil) { v_21428 = elt(v_21428, 24); // klist
#ifdef RECORD_GET
             if (v_21428 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v_21428 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v_21428 == SPID_NOPROP) v_21428 = nil; }}
#endif
    stack[0] = v_21428;
    goto v_21383;
v_21379:
    v_21429 = v_21430;
    goto v_21380;
v_21381:
    v_21428 = stack[0];
    goto v_21382;
v_21383:
    goto v_21379;
v_21380:
    goto v_21381;
v_21382:
    v_21428 = Lassoc(nil, v_21429, v_21428);
    stack[-1] = v_21428;
    v_21428 = stack[-1];
    if (v_21428 == nil) goto v_21389;
    else goto v_21390;
v_21389:
    goto v_21397;
v_21393:
    v_21429 = v_21430;
    goto v_21394;
v_21395:
    v_21428 = nil;
    goto v_21396;
v_21397:
    goto v_21393;
v_21394:
    goto v_21395;
v_21396:
    v_21428 = list2(v_21429, v_21428);
    env = stack[-2];
    stack[-1] = v_21428;
    goto v_21405;
v_21401:
    v_21429 = stack[-1];
    goto v_21402;
v_21403:
    v_21428 = stack[0];
    goto v_21404;
v_21405:
    goto v_21401;
v_21402:
    goto v_21403;
v_21404:
    fn = elt(env, 6); // ordad
    v_21428 = (*qfn2(fn))(fn, v_21429, v_21428);
    env = stack[-2];
    stack[0] = v_21428;
    goto v_21413;
v_21409:
    v_21429 = elt(env, 3); // (taylor!*)
    goto v_21410;
v_21411:
    v_21428 = qvalue(elt(env, 4)); // kprops!*
    goto v_21412;
v_21413:
    goto v_21409;
v_21410:
    goto v_21411;
v_21412:
    fn = elt(env, 7); // union
    v_21428 = (*qfn2(fn))(fn, v_21429, v_21428);
    env = stack[-2];
    qvalue(elt(env, 4)) = v_21428; // kprops!*
    goto v_21423;
v_21417:
    v_21430 = elt(env, 2); // taylor!*
    goto v_21418;
v_21419:
    v_21429 = elt(env, 5); // klist
    goto v_21420;
v_21421:
    v_21428 = stack[0];
    goto v_21422;
v_21423:
    goto v_21417;
v_21418:
    goto v_21419;
v_21420:
    goto v_21421;
v_21422:
    v_21428 = Lputprop(nil, 3, v_21430, v_21429, v_21428);
    goto v_21388;
v_21390:
v_21388:
    v_21428 = stack[-1];
v_21370:
    return onevalue(v_21428);
}



// Code for mk!+outer!+list

static LispObject CC_mkLouterLlist(LispObject env,
                         LispObject v_21365)
{
    env = qenv(env);
    LispObject v_21378, v_21379;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21365);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_21365;
// end of prologue
    goto v_21374;
v_21370:
    v_21378 = elt(env, 1); // list
    v_21379 = ncons(v_21378);
    goto v_21371;
v_21372:
    v_21378 = stack[0];
    goto v_21373;
v_21374:
    goto v_21370;
v_21371:
    goto v_21372;
v_21373:
        return Lappend(nil, v_21379, v_21378);
    return onevalue(v_21378);
}



// Code for repr_n

static LispObject CC_repr_n(LispObject env,
                         LispObject v_21365)
{
    env = qenv(env);
    LispObject v_21401, v_21402, v_21403;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21365);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21402 = v_21365;
// end of prologue
    v_21401 = v_21402;
    v_21401 = qcdr(v_21401);
    v_21401 = qcdr(v_21401);
    v_21401 = qcar(v_21401);
    if (v_21401 == nil) goto v_21369;
    else goto v_21370;
v_21369:
    v_21401 = elt(env, 1); // "repr_n : invalid REPR structure"
    v_21401 = ncons(v_21401);
    env = stack[0];
    {
        fn = elt(env, 2); // rederr
        return (*qfn1(fn))(fn, v_21401);
    }
v_21370:
    goto v_21384;
v_21380:
    v_21401 = v_21402;
    v_21401 = qcdr(v_21401);
    v_21401 = qcdr(v_21401);
    v_21401 = qcdr(v_21401);
    v_21401 = qcdr(v_21401);
    v_21403 = qcar(v_21401);
    goto v_21381;
v_21382:
    v_21401 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21383;
v_21384:
    goto v_21380;
v_21381:
    goto v_21382;
v_21383:
    if (v_21403 == v_21401) goto v_21378;
    else goto v_21379;
v_21378:
    v_21401 = nil;
    goto v_21368;
v_21379:
    v_21401 = v_21402;
    v_21401 = qcdr(v_21401);
    v_21401 = qcdr(v_21401);
    v_21401 = qcar(v_21401);
    v_21401 = qcar(v_21401);
    v_21401 = qcar(v_21401);
    goto v_21368;
    v_21401 = nil;
v_21368:
    return onevalue(v_21401);
}



// Code for minusrd

static LispObject CC_minusrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21394, v_21395, v_21396;
    LispObject fn;
    argcheck(nargs, 0, "minusrd");
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
    v_21394 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_21394;
    fn = elt(env, 1); // mathml
    v_21394 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_21395 = v_21394;
    if (v_21395 == nil) goto v_21374;
    else goto v_21375;
v_21374:
    v_21394 = stack[0];
    v_21394 = ncons(v_21394);
    stack[0] = v_21394;
    goto v_21373;
v_21375:
    goto v_21388;
v_21382:
    v_21396 = stack[0];
    goto v_21383;
v_21384:
    v_21395 = v_21394;
    goto v_21385;
v_21386:
    v_21394 = nil;
    goto v_21387;
v_21388:
    goto v_21382;
v_21383:
    goto v_21384;
v_21385:
    goto v_21386;
v_21387:
    v_21394 = list2star(v_21396, v_21395, v_21394);
    env = stack[-1];
    stack[0] = v_21394;
    fn = elt(env, 2); // lex
    v_21394 = (*qfnn(fn))(fn, 0);
    goto v_21373;
v_21373:
    v_21394 = stack[0];
    return onevalue(v_21394);
}



// Code for divide!-by!-power!-of!-ten

static LispObject CC_divideKbyKpowerKofKten(LispObject env,
                         LispObject v_21365, LispObject v_21366)
{
    env = qenv(env);
    LispObject v_21445, v_21446, v_21447;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21365,v_21366);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21366;
    stack[-1] = v_21365;
// end of prologue
    goto v_21377;
v_21373:
    v_21446 = stack[0];
    goto v_21374;
v_21375:
    v_21445 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21376;
v_21377:
    goto v_21373;
v_21374:
    goto v_21375;
v_21376:
    v_21445 = (LispObject)lessp2(v_21446, v_21445);
    v_21445 = v_21445 ? lisp_true : nil;
    env = stack[-3];
    if (v_21445 == nil) goto v_21371;
    v_21445 = elt(env, 0); // divide!-by!-power!-of!-ten
    {
        fn = elt(env, 3); // bflerrmsg
        return (*qfn1(fn))(fn, v_21445);
    }
v_21371:
    v_21445 = qvalue(elt(env, 1)); // bften!*
    stack[-2] = v_21445;
v_21388:
    goto v_21398;
v_21394:
    v_21446 = stack[0];
    goto v_21395;
v_21396:
    v_21445 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21397;
v_21398:
    goto v_21394;
v_21395:
    goto v_21396;
v_21397:
    v_21445 = (LispObject)greaterp2(v_21446, v_21445);
    v_21445 = v_21445 ? lisp_true : nil;
    env = stack[-3];
    if (v_21445 == nil) goto v_21391;
    else goto v_21392;
v_21391:
    goto v_21387;
v_21392:
    v_21445 = stack[0];
    v_21445 = Levenp(nil, v_21445);
    env = stack[-3];
    if (v_21445 == nil) goto v_21404;
    else goto v_21405;
v_21404:
    goto v_21416;
v_21410:
    v_21447 = stack[-1];
    goto v_21411;
v_21412:
    v_21446 = stack[-2];
    goto v_21413;
v_21414:
    v_21445 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_21415;
v_21416:
    goto v_21410;
v_21411:
    goto v_21412;
v_21413:
    goto v_21414;
v_21415:
    fn = elt(env, 4); // divide!:
    v_21445 = (*qfnn(fn))(fn, 3, v_21447, v_21446, v_21445);
    env = stack[-3];
    fn = elt(env, 5); // normbf
    v_21445 = (*qfn1(fn))(fn, v_21445);
    env = stack[-3];
    stack[-1] = v_21445;
    goto v_21403;
v_21405:
v_21403:
    goto v_21425;
v_21421:
    v_21446 = stack[0];
    goto v_21422;
v_21423:
    v_21445 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_21424;
v_21425:
    goto v_21421;
v_21422:
    goto v_21423;
v_21424:
    fn = elt(env, 6); // lshift
    v_21445 = (*qfn2(fn))(fn, v_21446, v_21445);
    env = stack[-3];
    stack[0] = v_21445;
    goto v_21434;
v_21430:
    goto v_21440;
v_21436:
    v_21446 = stack[-2];
    goto v_21437;
v_21438:
    v_21445 = stack[-2];
    goto v_21439;
v_21440:
    goto v_21436;
v_21437:
    goto v_21438;
v_21439:
    fn = elt(env, 7); // times!:
    v_21446 = (*qfn2(fn))(fn, v_21446, v_21445);
    env = stack[-3];
    goto v_21431;
v_21432:
    v_21445 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_21433;
v_21434:
    goto v_21430;
v_21431:
    goto v_21432;
v_21433:
    fn = elt(env, 8); // cut!:mt
    v_21445 = (*qfn2(fn))(fn, v_21446, v_21445);
    env = stack[-3];
    fn = elt(env, 5); // normbf
    v_21445 = (*qfn1(fn))(fn, v_21445);
    env = stack[-3];
    stack[-2] = v_21445;
    goto v_21388;
v_21387:
    v_21445 = stack[-1];
    goto v_21369;
    v_21445 = nil;
v_21369:
    return onevalue(v_21445);
}



// Code for atom_compare

static LispObject CC_atom_compare(LispObject env,
                         LispObject v_21365, LispObject v_21366)
{
    env = qenv(env);
    LispObject v_21405, v_21406, v_21407;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21365,v_21366);
    }
// copy arguments values to proper place
    v_21406 = v_21366;
    v_21407 = v_21365;
// end of prologue
    v_21405 = v_21407;
    if (is_number(v_21405)) goto v_21370;
    else goto v_21371;
v_21370:
    v_21405 = v_21406;
    if (is_number(v_21405)) goto v_21376;
    v_21405 = nil;
    goto v_21374;
v_21376:
    goto v_21386;
v_21382:
    v_21405 = v_21407;
    goto v_21383;
v_21384:
    goto v_21385;
v_21386:
    goto v_21382;
v_21383:
    goto v_21384;
v_21385:
    v_21405 = (LispObject)lessp2(v_21405, v_21406);
    v_21405 = v_21405 ? lisp_true : nil;
    v_21405 = (v_21405 == nil ? lisp_true : nil);
    goto v_21374;
    v_21405 = nil;
v_21374:
    goto v_21369;
v_21371:
    v_21405 = v_21406;
    if (symbolp(v_21405)) goto v_21390;
    else goto v_21391;
v_21390:
    goto v_21398;
v_21394:
    v_21405 = v_21407;
    goto v_21395;
v_21396:
    goto v_21397;
v_21398:
    goto v_21394;
v_21395:
    goto v_21396;
v_21397:
        return Lorderp(nil, v_21405, v_21406);
v_21391:
    v_21405 = v_21406;
    v_21405 = (is_number(v_21405) ? lisp_true : nil);
    goto v_21369;
    v_21405 = nil;
v_21369:
    return onevalue(v_21405);
}



// Code for set_parser

static LispObject CC_set_parser(LispObject env,
                         LispObject v_21365)
{
    env = qenv(env);
    LispObject v_21397, v_21398;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21365);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21365;
// end of prologue
    v_21397 = stack[0];
    v_21397 = qcar(v_21397);
    fn = elt(env, 8); // lex_restore_context
    v_21397 = (*qfn1(fn))(fn, v_21397);
    env = stack[-1];
    v_21397 = stack[0];
    v_21397 = qcdr(v_21397);
    stack[0] = v_21397;
    v_21397 = qcar(v_21397);
    qvalue(elt(env, 1)) = v_21397; // parser_action_table
    v_21397 = stack[0];
    v_21397 = qcdr(v_21397);
    stack[0] = v_21397;
    v_21397 = qcar(v_21397);
    v_21398 = v_21397;
    v_21397 = v_21398;
    v_21397 = qcar(v_21397);
    qvalue(elt(env, 2)) = v_21397; // reduction_fn
    v_21397 = v_21398;
    v_21397 = qcdr(v_21397);
    v_21398 = v_21397;
    v_21397 = qcar(v_21397);
    qvalue(elt(env, 3)) = v_21397; // reduction_rhs_n
    v_21397 = v_21398;
    v_21397 = qcdr(v_21397);
    v_21397 = qcar(v_21397);
    qvalue(elt(env, 4)) = v_21397; // reduction_lhs
    v_21397 = stack[0];
    v_21397 = qcdr(v_21397);
    stack[0] = v_21397;
    v_21397 = qcar(v_21397);
    qvalue(elt(env, 5)) = v_21397; // parser_goto_table
    v_21397 = stack[0];
    v_21397 = qcdr(v_21397);
    stack[0] = v_21397;
    v_21397 = qcar(v_21397);
    qvalue(elt(env, 6)) = v_21397; // nonterminal_codes
    v_21397 = stack[0];
    v_21397 = qcdr(v_21397);
    v_21397 = qcar(v_21397);
    qvalue(elt(env, 7)) = v_21397; // terminal_codes
    v_21397 = nil;
    return onevalue(v_21397);
}



// Code for sq_member

static LispObject CC_sq_member(LispObject env,
                         LispObject v_21365, LispObject v_21366)
{
    env = qenv(env);
    LispObject v_21389, v_21390;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21365,v_21366);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21366;
    stack[-1] = v_21365;
// end of prologue
    goto v_21376;
v_21372:
    v_21390 = stack[-1];
    goto v_21373;
v_21374:
    v_21389 = stack[0];
    v_21389 = qcar(v_21389);
    goto v_21375;
v_21376:
    goto v_21372;
v_21373:
    goto v_21374;
v_21375:
    fn = elt(env, 1); // sf_member
    v_21389 = (*qfn2(fn))(fn, v_21390, v_21389);
    env = stack[-2];
    if (v_21389 == nil) goto v_21370;
    else goto v_21369;
v_21370:
    goto v_21385;
v_21381:
    v_21390 = stack[-1];
    goto v_21382;
v_21383:
    v_21389 = stack[0];
    v_21389 = qcdr(v_21389);
    goto v_21384;
v_21385:
    goto v_21381;
v_21382:
    goto v_21383;
v_21384:
    {
        fn = elt(env, 1); // sf_member
        return (*qfn2(fn))(fn, v_21390, v_21389);
    }
v_21369:
    return onevalue(v_21389);
}



// Code for mri_ofsf2mriat

static LispObject CC_mri_ofsf2mriat(LispObject env,
                         LispObject v_21365, LispObject v_21366)
{
    env = qenv(env);
    LispObject v_21382, v_21383, v_21384;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21382 = v_21366;
    v_21383 = v_21365;
// end of prologue
    goto v_21375;
v_21369:
    v_21384 = v_21383;
    v_21384 = qcar(v_21384);
    goto v_21370;
v_21371:
    v_21383 = qcdr(v_21383);
    v_21383 = qcar(v_21383);
    goto v_21372;
v_21373:
    goto v_21374;
v_21375:
    goto v_21369;
v_21370:
    goto v_21371;
v_21372:
    goto v_21373;
v_21374:
    {
        fn = elt(env, 1); // mri_0mk2
        return (*qfnn(fn))(fn, 3, v_21384, v_21383, v_21382);
    }
}



// Code for rl_surep

static LispObject CC_rl_surep(LispObject env,
                         LispObject v_21365, LispObject v_21366)
{
    env = qenv(env);
    LispObject v_21383, v_21384;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21365,v_21366);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21383 = v_21366;
    v_21384 = v_21365;
// end of prologue
    goto v_21373;
v_21369:
    stack[0] = qvalue(elt(env, 1)); // rl_surep!*
    goto v_21370;
v_21371:
    goto v_21380;
v_21376:
    goto v_21377;
v_21378:
    goto v_21379;
v_21380:
    goto v_21376;
v_21377:
    goto v_21378;
v_21379:
    v_21383 = list2(v_21384, v_21383);
    env = stack[-1];
    goto v_21372;
v_21373:
    goto v_21369;
v_21370:
    goto v_21371;
v_21372:
    {
        LispObject v_21386 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_21386, v_21383);
    }
}



// Code for sfto_b!:ordexp

static LispObject CC_sfto_bTordexp(LispObject env,
                         LispObject v_21365, LispObject v_21366)
{
    env = qenv(env);
    LispObject v_21408, v_21409;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21365,v_21366);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21366;
    stack[-1] = v_21365;
// end of prologue
v_21370:
    v_21408 = stack[-1];
    if (v_21408 == nil) goto v_21373;
    else goto v_21374;
v_21373:
    v_21408 = lisp_true;
    goto v_21369;
v_21374:
    goto v_21384;
v_21380:
    v_21408 = stack[-1];
    v_21409 = qcar(v_21408);
    goto v_21381;
v_21382:
    v_21408 = stack[0];
    v_21408 = qcar(v_21408);
    goto v_21383;
v_21384:
    goto v_21380;
v_21381:
    goto v_21382;
v_21383:
    v_21408 = (LispObject)greaterp2(v_21409, v_21408);
    v_21408 = v_21408 ? lisp_true : nil;
    env = stack[-2];
    if (v_21408 == nil) goto v_21378;
    v_21408 = lisp_true;
    goto v_21369;
v_21378:
    goto v_21396;
v_21392:
    v_21408 = stack[-1];
    v_21409 = qcar(v_21408);
    goto v_21393;
v_21394:
    v_21408 = stack[0];
    v_21408 = qcar(v_21408);
    goto v_21395;
v_21396:
    goto v_21392;
v_21393:
    goto v_21394;
v_21395:
    if (equal(v_21409, v_21408)) goto v_21390;
    else goto v_21391;
v_21390:
    v_21408 = stack[-1];
    v_21408 = qcdr(v_21408);
    stack[-1] = v_21408;
    v_21408 = stack[0];
    v_21408 = qcdr(v_21408);
    stack[0] = v_21408;
    goto v_21370;
v_21391:
    v_21408 = nil;
    goto v_21369;
    v_21408 = nil;
v_21369:
    return onevalue(v_21408);
}



// Code for intervalom

static LispObject CC_intervalom(LispObject env,
                         LispObject v_21365)
{
    env = qenv(env);
    LispObject v_21457, v_21458, v_21459;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21365);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_21365;
// end of prologue
    v_21457 = stack[-2];
    v_21457 = qcdr(v_21457);
    v_21457 = qcar(v_21457);
    stack[-3] = v_21457;
    v_21457 = stack[-2];
    v_21457 = qcar(v_21457);
    stack[-1] = v_21457;
    goto v_21386;
v_21382:
    v_21458 = stack[-1];
    goto v_21383;
v_21384:
    v_21457 = elt(env, 1); // lowupperlimit
    goto v_21385;
v_21386:
    goto v_21382;
v_21383:
    goto v_21384;
v_21385:
    if (v_21458 == v_21457) goto v_21380;
    else goto v_21381;
v_21380:
    v_21457 = elt(env, 2); // integer_interval
    stack[-1] = v_21457;
    v_21457 = nil;
    stack[-3] = v_21457;
    goto v_21398;
v_21392:
    v_21457 = stack[-2];
    v_21459 = qcar(v_21457);
    goto v_21393;
v_21394:
    v_21458 = nil;
    goto v_21395;
v_21396:
    v_21457 = stack[-2];
    v_21457 = qcdr(v_21457);
    goto v_21397;
v_21398:
    goto v_21392;
v_21393:
    goto v_21394;
v_21395:
    goto v_21396;
v_21397:
    v_21457 = list2star(v_21459, v_21458, v_21457);
    env = stack[-4];
    stack[-2] = v_21457;
    goto v_21379;
v_21381:
v_21379:
    goto v_21408;
v_21404:
    v_21458 = stack[-1];
    goto v_21405;
v_21406:
    v_21457 = qvalue(elt(env, 3)); // valid_om!*
    goto v_21407;
v_21408:
    goto v_21404;
v_21405:
    goto v_21406;
v_21407:
    v_21457 = Lassoc(nil, v_21458, v_21457);
    v_21457 = qcdr(v_21457);
    v_21457 = qcar(v_21457);
    stack[0] = v_21457;
    v_21457 = stack[-3];
    if (v_21457 == nil) goto v_21417;
    goto v_21423;
v_21419:
    v_21457 = stack[-3];
    v_21457 = qcar(v_21457);
    v_21457 = qcdr(v_21457);
    v_21457 = qcar(v_21457);
    v_21458 = Lintern(nil, v_21457);
    env = stack[-4];
    goto v_21420;
v_21421:
    v_21457 = qvalue(elt(env, 4)); // interval!*
    goto v_21422;
v_21423:
    goto v_21419;
v_21420:
    goto v_21421;
v_21422:
    v_21457 = Lassoc(nil, v_21458, v_21457);
    v_21457 = qcdr(v_21457);
    v_21457 = qcar(v_21457);
    stack[-1] = v_21457;
    goto v_21415;
v_21417:
v_21415:
    v_21457 = elt(env, 5); // "<OMA>"
    fn = elt(env, 10); // printout
    v_21457 = (*qfn1(fn))(fn, v_21457);
    env = stack[-4];
    v_21457 = lisp_true;
    fn = elt(env, 11); // indent!*
    v_21457 = (*qfn1(fn))(fn, v_21457);
    env = stack[-4];
    v_21457 = elt(env, 6); // "<OMS cd="""
    fn = elt(env, 10); // printout
    v_21457 = (*qfn1(fn))(fn, v_21457);
    env = stack[-4];
    v_21457 = stack[0];
    v_21457 = Lprinc(nil, v_21457);
    env = stack[-4];
    v_21457 = elt(env, 7); // """ name="""
    v_21457 = Lprinc(nil, v_21457);
    env = stack[-4];
    v_21457 = stack[-1];
    v_21457 = Lprinc(nil, v_21457);
    env = stack[-4];
    v_21457 = elt(env, 8); // """/>"
    v_21457 = Lprinc(nil, v_21457);
    env = stack[-4];
    v_21457 = stack[-2];
    v_21457 = qcdr(v_21457);
    v_21457 = qcdr(v_21457);
    fn = elt(env, 12); // multiom
    v_21457 = (*qfn1(fn))(fn, v_21457);
    env = stack[-4];
    v_21457 = nil;
    fn = elt(env, 11); // indent!*
    v_21457 = (*qfn1(fn))(fn, v_21457);
    env = stack[-4];
    v_21457 = elt(env, 9); // "</OMA>"
    fn = elt(env, 10); // printout
    v_21457 = (*qfn1(fn))(fn, v_21457);
    v_21457 = nil;
    return onevalue(v_21457);
}



// Code for greatertype

static LispObject CC_greatertype(LispObject env,
                         LispObject v_21365, LispObject v_21366)
{
    env = qenv(env);
    LispObject v_21555, v_21556, v_21557;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21365,v_21366);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_21366;
    stack[-6] = v_21365;
// end of prologue
    stack[-4] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    goto v_21382;
v_21378:
    v_21555 = qvalue(elt(env, 1)); // optlang!*
    if (v_21555 == nil) goto v_21386;
    v_21555 = qvalue(elt(env, 1)); // optlang!*
    v_21556 = v_21555;
    goto v_21384;
v_21386:
    v_21555 = elt(env, 2); // fortran
    v_21556 = v_21555;
    goto v_21384;
    v_21556 = nil;
v_21384:
    goto v_21379;
v_21380:
    v_21555 = elt(env, 3); // conversion
    goto v_21381;
v_21382:
    goto v_21378;
v_21379:
    goto v_21380;
v_21381:
    v_21555 = get(v_21556, v_21555);
    env = stack[-8];
    fn = elt(env, 4); // eval
    v_21555 = (*qfn1(fn))(fn, v_21555);
    env = stack[-8];
    stack[-7] = v_21555;
    goto v_21401;
v_21397:
    v_21555 = stack[-7];
    v_21556 = qcar(v_21555);
    goto v_21398;
v_21399:
    v_21555 = stack[-5];
    goto v_21400;
v_21401:
    goto v_21397;
v_21398:
    goto v_21399;
v_21400:
    if (equal(v_21556, v_21555)) goto v_21395;
    else goto v_21396;
v_21395:
    v_21555 = lisp_true;
    stack[-1] = v_21555;
    goto v_21394;
v_21396:
    goto v_21412;
v_21408:
    v_21555 = stack[-7];
    v_21556 = qcar(v_21555);
    goto v_21409;
v_21410:
    v_21555 = stack[-6];
    goto v_21411;
v_21412:
    goto v_21408;
v_21409:
    goto v_21410;
v_21411:
    if (equal(v_21556, v_21555)) goto v_21406;
    else goto v_21407;
v_21406:
    v_21555 = nil;
    stack[-1] = v_21555;
    goto v_21394;
v_21407:
v_21421:
    v_21555 = stack[-7];
    v_21555 = qcdr(v_21555);
    stack[-7] = v_21555;
    if (v_21555 == nil) goto v_21424;
    v_21555 = stack[-4];
    if (v_21555 == nil) goto v_21429;
    else goto v_21424;
v_21429:
    goto v_21425;
v_21424:
    goto v_21420;
v_21425:
    v_21555 = stack[-7];
    v_21555 = qcar(v_21555);
    v_21557 = v_21555;
v_21436:
    v_21555 = v_21557;
    if (v_21555 == nil) goto v_21439;
    v_21555 = stack[-2];
    if (v_21555 == nil) goto v_21443;
    else goto v_21439;
v_21443:
    goto v_21440;
v_21439:
    goto v_21435;
v_21440:
    goto v_21454;
v_21450:
    v_21555 = v_21557;
    v_21556 = qcar(v_21555);
    goto v_21451;
v_21452:
    v_21555 = stack[-6];
    goto v_21453;
v_21454:
    goto v_21450;
v_21451:
    goto v_21452;
v_21453:
    if (equal(v_21556, v_21555)) goto v_21448;
    else goto v_21449;
v_21448:
    v_21555 = lisp_true;
    stack[-3] = v_21555;
    goto v_21447;
v_21449:
v_21447:
    goto v_21467;
v_21463:
    v_21555 = v_21557;
    v_21556 = qcar(v_21555);
    goto v_21464;
v_21465:
    v_21555 = stack[-5];
    goto v_21466;
v_21467:
    goto v_21463;
v_21464:
    goto v_21465;
v_21466:
    if (equal(v_21556, v_21555)) goto v_21461;
    else goto v_21462;
v_21461:
    v_21555 = lisp_true;
    stack[-2] = v_21555;
    goto v_21460;
v_21462:
    v_21555 = v_21557;
    v_21555 = qcdr(v_21555);
    v_21557 = v_21555;
    goto v_21460;
v_21460:
    goto v_21436;
v_21435:
    v_21555 = stack[-2];
    if (v_21555 == nil) goto v_21479;
    v_21555 = v_21557;
    v_21555 = qcdr(v_21555);
    v_21557 = v_21555;
v_21485:
    v_21555 = v_21557;
    if (v_21555 == nil) goto v_21488;
    v_21555 = stack[-1];
    if (v_21555 == nil) goto v_21492;
    else goto v_21488;
v_21492:
    goto v_21489;
v_21488:
    goto v_21484;
v_21489:
    goto v_21503;
v_21499:
    v_21555 = v_21557;
    v_21556 = qcar(v_21555);
    goto v_21500;
v_21501:
    v_21555 = stack[-6];
    goto v_21502;
v_21503:
    goto v_21499;
v_21500:
    goto v_21501;
v_21502:
    if (equal(v_21556, v_21555)) goto v_21497;
    else goto v_21498;
v_21497:
    v_21555 = lisp_true;
    stack[-1] = v_21555;
    stack[-3] = v_21555;
    goto v_21496;
v_21498:
    v_21555 = v_21557;
    v_21555 = qcdr(v_21555);
    v_21557 = v_21555;
    goto v_21496;
v_21496:
    goto v_21485;
v_21484:
    goto v_21477;
v_21479:
v_21477:
    v_21555 = stack[-3];
    if (v_21555 == nil) goto v_21517;
    v_21555 = stack[-2];
    if (v_21555 == nil) goto v_21520;
    else goto v_21517;
v_21520:
    goto v_21515;
v_21517:
    v_21555 = stack[-3];
    if (v_21555 == nil) goto v_21525;
    else goto v_21526;
v_21525:
    v_21555 = stack[-2];
    goto v_21524;
v_21526:
    v_21555 = nil;
    goto v_21524;
    v_21555 = nil;
v_21524:
    if (v_21555 == nil) goto v_21522;
    else goto v_21515;
v_21522:
    goto v_21516;
v_21515:
    goto v_21537;
v_21533:
    stack[0] = (LispObject)64+TAG_FIXNUM; // 4
    goto v_21534;
v_21535:
    goto v_21544;
v_21540:
    v_21556 = stack[-6];
    goto v_21541;
v_21542:
    v_21555 = stack[-5];
    goto v_21543;
v_21544:
    goto v_21540;
v_21541:
    goto v_21542;
v_21543:
    v_21555 = cons(v_21556, v_21555);
    env = stack[-8];
    goto v_21536;
v_21537:
    goto v_21533;
v_21534:
    goto v_21535;
v_21536:
    fn = elt(env, 5); // typerror
    v_21555 = (*qfn2(fn))(fn, stack[0], v_21555);
    env = stack[-8];
    goto v_21514;
v_21516:
    v_21555 = stack[-3];
    if (v_21555 == nil) goto v_21548;
    v_21555 = stack[-2];
    if (v_21555 == nil) goto v_21548;
    v_21555 = lisp_true;
    stack[-4] = v_21555;
    goto v_21514;
v_21548:
v_21514:
    goto v_21421;
v_21420:
    goto v_21394;
v_21394:
    v_21555 = stack[-1];
    return onevalue(v_21555);
}



// Code for groebspolynom3

static LispObject CC_groebspolynom3(LispObject env,
                         LispObject v_21365, LispObject v_21366)
{
    env = qenv(env);
    LispObject v_21382, v_21383;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21365,v_21366);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21382 = v_21366;
    v_21383 = v_21365;
// end of prologue
    goto v_21376;
v_21372:
    goto v_21373;
v_21374:
    goto v_21375;
v_21376:
    goto v_21372;
v_21373:
    goto v_21374;
v_21375:
    fn = elt(env, 1); // groebspolynom4
    v_21382 = (*qfn2(fn))(fn, v_21383, v_21382);
    env = stack[-1];
    stack[0] = v_21382;
    v_21382 = stack[0];
    fn = elt(env, 2); // groebsavelterm
    v_21382 = (*qfn1(fn))(fn, v_21382);
    v_21382 = stack[0];
    return onevalue(v_21382);
}



// Code for exdfprn

static LispObject CC_exdfprn(LispObject env,
                         LispObject v_21365)
{
    env = qenv(env);
    LispObject v_21373;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21365);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21365;
// end of prologue
    v_21373 = elt(env, 1); // "d"
    fn = elt(env, 2); // prin2!*
    v_21373 = (*qfn1(fn))(fn, v_21373);
    env = stack[-1];
    v_21373 = stack[0];
    v_21373 = qcdr(v_21373);
    v_21373 = qcar(v_21373);
    {
        fn = elt(env, 3); // rembras
        return (*qfn1(fn))(fn, v_21373);
    }
}



// Code for multiply!-by!-power!-of!-ten

static LispObject CC_multiplyKbyKpowerKofKten(LispObject env,
                         LispObject v_21365, LispObject v_21366)
{
    env = qenv(env);
    LispObject v_21450, v_21451;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21365,v_21366);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21366;
    stack[-1] = v_21365;
// end of prologue
    goto v_21377;
v_21373:
    v_21451 = stack[0];
    goto v_21374;
v_21375:
    v_21450 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21376;
v_21377:
    goto v_21373;
v_21374:
    goto v_21375;
v_21376:
    v_21450 = (LispObject)lessp2(v_21451, v_21450);
    v_21450 = v_21450 ? lisp_true : nil;
    env = stack[-3];
    if (v_21450 == nil) goto v_21371;
    v_21450 = elt(env, 0); // multiply!-by!-power!-of!-ten
    {
        fn = elt(env, 3); // bflerrmsg
        return (*qfn1(fn))(fn, v_21450);
    }
v_21371:
    v_21450 = qvalue(elt(env, 1)); // bften!*
    stack[-2] = v_21450;
v_21388:
    goto v_21398;
v_21394:
    v_21451 = stack[0];
    goto v_21395;
v_21396:
    v_21450 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21397;
v_21398:
    goto v_21394;
v_21395:
    goto v_21396;
v_21397:
    v_21450 = (LispObject)greaterp2(v_21451, v_21450);
    v_21450 = v_21450 ? lisp_true : nil;
    env = stack[-3];
    if (v_21450 == nil) goto v_21391;
    else goto v_21392;
v_21391:
    goto v_21387;
v_21392:
    v_21450 = stack[0];
    v_21450 = Levenp(nil, v_21450);
    env = stack[-3];
    if (v_21450 == nil) goto v_21404;
    else goto v_21405;
v_21404:
    goto v_21414;
v_21410:
    v_21451 = stack[-1];
    goto v_21411;
v_21412:
    v_21450 = stack[-2];
    goto v_21413;
v_21414:
    goto v_21410;
v_21411:
    goto v_21412;
v_21413:
    fn = elt(env, 4); // times!:
    v_21450 = (*qfn2(fn))(fn, v_21451, v_21450);
    env = stack[-3];
    fn = elt(env, 5); // normbf
    v_21450 = (*qfn1(fn))(fn, v_21450);
    env = stack[-3];
    stack[-1] = v_21450;
    goto v_21403;
v_21405:
v_21403:
    goto v_21422;
v_21418:
    v_21451 = stack[0];
    goto v_21419;
v_21420:
    v_21450 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_21421;
v_21422:
    goto v_21418;
v_21419:
    goto v_21420;
v_21421:
    fn = elt(env, 6); // lshift
    v_21450 = (*qfn2(fn))(fn, v_21451, v_21450);
    env = stack[-3];
    stack[0] = v_21450;
    goto v_21431;
v_21427:
    goto v_21437;
v_21433:
    v_21451 = stack[-2];
    goto v_21434;
v_21435:
    v_21450 = stack[-2];
    goto v_21436;
v_21437:
    goto v_21433;
v_21434:
    goto v_21435;
v_21436:
    fn = elt(env, 4); // times!:
    v_21451 = (*qfn2(fn))(fn, v_21451, v_21450);
    env = stack[-3];
    goto v_21428;
v_21429:
    v_21450 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_21430;
v_21431:
    goto v_21427;
v_21428:
    goto v_21429;
v_21430:
    fn = elt(env, 7); // cut!:mt
    v_21450 = (*qfn2(fn))(fn, v_21451, v_21450);
    env = stack[-3];
    fn = elt(env, 5); // normbf
    v_21450 = (*qfn1(fn))(fn, v_21450);
    env = stack[-3];
    stack[-2] = v_21450;
    goto v_21388;
v_21387:
    goto v_21447;
v_21443:
    v_21451 = stack[-1];
    goto v_21444;
v_21445:
    v_21450 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_21446;
v_21447:
    goto v_21443;
v_21444:
    goto v_21445;
v_21446:
    fn = elt(env, 7); // cut!:mt
    v_21450 = (*qfn2(fn))(fn, v_21451, v_21450);
    env = stack[-3];
    {
        fn = elt(env, 5); // normbf
        return (*qfn1(fn))(fn, v_21450);
    }
    v_21450 = nil;
    return onevalue(v_21450);
}



// Code for calc_den_tar

static LispObject CC_calc_den_tar(LispObject env,
                         LispObject v_21365, LispObject v_21366)
{
    env = qenv(env);
    LispObject v_21393, v_21394;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21365,v_21366);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21393 = v_21366;
    v_21394 = v_21365;
// end of prologue
    goto v_21373;
v_21369:
    goto v_21370;
v_21371:
    goto v_21372;
v_21373:
    goto v_21369;
v_21370:
    goto v_21371;
v_21372:
    fn = elt(env, 1); // denlist
    v_21393 = (*qfn2(fn))(fn, v_21394, v_21393);
    env = stack[0];
    v_21394 = v_21393;
    v_21393 = v_21394;
    if (v_21393 == nil) goto v_21379;
    else goto v_21380;
v_21379:
    v_21393 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21378;
v_21380:
    v_21393 = v_21394;
    v_21393 = qcdr(v_21393);
    if (v_21393 == nil) goto v_21383;
    else goto v_21384;
v_21383:
    v_21393 = v_21394;
    v_21393 = qcar(v_21393);
    goto v_21378;
v_21384:
    v_21393 = v_21394;
    {
        fn = elt(env, 2); // constimes
        return (*qfn1(fn))(fn, v_21393);
    }
    v_21393 = nil;
v_21378:
    return onevalue(v_21393);
}



// Code for log_freevars

static LispObject CC_log_freevars(LispObject env,
                         LispObject v_21365, LispObject v_21366)
{
    env = qenv(env);
    LispObject v_21614, v_21615, v_21616;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21366,v_21365);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21365,v_21366);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21366;
    v_21615 = v_21365;
// end of prologue
    v_21614 = stack[0];
    if (!consp(v_21614)) goto v_21370;
    else goto v_21371;
v_21370:
    v_21614 = stack[0];
    if (symbolp(v_21614)) goto v_21380;
    v_21614 = lisp_true;
    goto v_21378;
v_21380:
    goto v_21392;
v_21388:
    v_21614 = stack[0];
    goto v_21389;
v_21390:
    goto v_21391;
v_21392:
    goto v_21388;
v_21389:
    goto v_21390;
v_21391:
    v_21614 = Lmember(nil, v_21614, v_21615);
    if (v_21614 == nil) goto v_21387;
    else goto v_21386;
v_21387:
    v_21614 = stack[0];
    v_21614 = Lsymbol_globalp(nil, v_21614);
    env = stack[-1];
    if (v_21614 == nil) goto v_21398;
    else goto v_21397;
v_21398:
    v_21614 = stack[0];
    v_21614 = Lsymbol_specialp(nil, v_21614);
    env = stack[-1];
    if (v_21614 == nil) goto v_21403;
    else goto v_21402;
v_21403:
    goto v_21414;
v_21410:
    v_21615 = stack[0];
    goto v_21411;
v_21412:
    v_21614 = elt(env, 1); // constant!?
    goto v_21413;
v_21414:
    goto v_21410;
v_21411:
    goto v_21412;
v_21413:
    v_21614 = get(v_21615, v_21614);
    env = stack[-1];
    if (v_21614 == nil) goto v_21408;
    else goto v_21407;
v_21408:
    v_21614 = stack[0];
    if (v_21614 == nil) goto v_21419;
    else goto v_21420;
v_21419:
    v_21614 = lisp_true;
    goto v_21418;
v_21420:
    goto v_21429;
v_21425:
    v_21615 = stack[0];
    goto v_21426;
v_21427:
    v_21614 = lisp_true;
    goto v_21428;
v_21429:
    goto v_21425;
v_21426:
    goto v_21427;
v_21428:
    v_21614 = (equal(v_21615, v_21614) ? lisp_true : nil);
    goto v_21418;
    v_21614 = nil;
v_21418:
v_21407:
v_21402:
v_21397:
v_21386:
    goto v_21378;
    v_21614 = nil;
v_21378:
    if (v_21614 == nil) goto v_21376;
    v_21614 = nil;
    goto v_21374;
v_21376:
    v_21614 = Lposn(nil, 0);
    env = stack[-1];
    v_21614 = (LispObject)zerop(v_21614);
    v_21614 = v_21614 ? lisp_true : nil;
    env = stack[-1];
    if (v_21614 == nil) goto v_21438;
    else goto v_21439;
v_21438:
    v_21614 = Lterpri(nil, 0);
    env = stack[-1];
    goto v_21437;
v_21439:
v_21437:
    v_21614 = elt(env, 2); // "+++ Use of free variable in smacro/inline body: "
    v_21614 = Lprinc(nil, v_21614);
    env = stack[-1];
    v_21614 = stack[0];
    v_21614 = Lprint(nil, v_21614);
    env = stack[-1];
    v_21614 = elt(env, 3); // "+++ Macro was: "
    v_21614 = Lprinc(nil, v_21614);
    env = stack[-1];
    v_21614 = qvalue(elt(env, 4)); // inlineinfo
    v_21614 = Lprint(nil, v_21614);
    v_21614 = lisp_true;
    goto v_21374;
    v_21614 = nil;
v_21374:
    goto v_21369;
v_21371:
    goto v_21463;
v_21459:
    v_21616 = stack[0];
    goto v_21460;
v_21461:
    v_21614 = elt(env, 5); // quote
    goto v_21462;
v_21463:
    goto v_21459;
v_21460:
    goto v_21461;
v_21462:
    if (!consp(v_21616)) goto v_21457;
    v_21616 = qcar(v_21616);
    if (v_21616 == v_21614) goto v_21456;
    else goto v_21457;
v_21456:
    v_21614 = lisp_true;
    goto v_21455;
v_21457:
    goto v_21482;
v_21478:
    v_21616 = stack[0];
    goto v_21479;
v_21480:
    v_21614 = elt(env, 6); // function
    goto v_21481;
v_21482:
    goto v_21478;
v_21479:
    goto v_21480;
v_21481:
    if (!consp(v_21616)) goto v_21476;
    v_21616 = qcar(v_21616);
    if (v_21616 == v_21614) goto v_21475;
    else goto v_21476;
v_21475:
    v_21614 = stack[0];
    v_21614 = qcdr(v_21614);
    v_21614 = qcar(v_21614);
    v_21614 = (consp(v_21614) ? nil : lisp_true);
    goto v_21474;
v_21476:
    v_21614 = nil;
    goto v_21474;
    v_21614 = nil;
v_21474:
    if (v_21614 == nil) goto v_21472;
    v_21614 = lisp_true;
    goto v_21470;
v_21472:
    goto v_21500;
v_21496:
    v_21616 = stack[0];
    goto v_21497;
v_21498:
    v_21614 = elt(env, 7); // go
    goto v_21499;
v_21500:
    goto v_21496;
v_21497:
    goto v_21498;
v_21499:
    v_21614 = Leqcar(nil, v_21616, v_21614);
    env = stack[-1];
    goto v_21470;
    v_21614 = nil;
v_21470:
    goto v_21455;
    v_21614 = nil;
v_21455:
    if (v_21614 == nil) goto v_21453;
    v_21614 = nil;
    goto v_21369;
v_21453:
    goto v_21511;
v_21507:
    v_21616 = stack[0];
    goto v_21508;
v_21509:
    v_21614 = elt(env, 8); // prog
    goto v_21510;
v_21511:
    goto v_21507;
v_21508:
    goto v_21509;
v_21510:
    if (!consp(v_21616)) goto v_21505;
    v_21616 = qcar(v_21616);
    if (v_21616 == v_21614) goto v_21504;
    else goto v_21505;
v_21504:
    goto v_21521;
v_21515:
    goto v_21527;
v_21523:
    v_21614 = stack[0];
    v_21614 = qcdr(v_21614);
    v_21614 = qcar(v_21614);
    goto v_21524;
v_21525:
    goto v_21526;
v_21527:
    goto v_21523;
v_21524:
    goto v_21525;
v_21526:
    v_21616 = Lappend(nil, v_21614, v_21615);
    env = stack[-1];
    goto v_21516;
v_21517:
    v_21614 = stack[0];
    v_21615 = qcdr(v_21614);
    goto v_21518;
v_21519:
    v_21614 = lisp_true;
    goto v_21520;
v_21521:
    goto v_21515;
v_21516:
    goto v_21517;
v_21518:
    goto v_21519;
v_21520:
    {
        fn = elt(env, 11); // log_freevars_list
        return (*qfnn(fn))(fn, 3, v_21616, v_21615, v_21614);
    }
v_21505:
    goto v_21542;
v_21538:
    v_21616 = stack[0];
    goto v_21539;
v_21540:
    v_21614 = elt(env, 9); // lambda
    goto v_21541;
v_21542:
    goto v_21538;
v_21539:
    goto v_21540;
v_21541:
    if (!consp(v_21616)) goto v_21536;
    v_21616 = qcar(v_21616);
    if (v_21616 == v_21614) goto v_21535;
    else goto v_21536;
v_21535:
    goto v_21552;
v_21546:
    goto v_21558;
v_21554:
    v_21614 = stack[0];
    v_21614 = qcdr(v_21614);
    v_21614 = qcar(v_21614);
    goto v_21555;
v_21556:
    goto v_21557;
v_21558:
    goto v_21554;
v_21555:
    goto v_21556;
v_21557:
    v_21616 = Lappend(nil, v_21614, v_21615);
    env = stack[-1];
    goto v_21547;
v_21548:
    v_21614 = stack[0];
    v_21615 = qcdr(v_21614);
    goto v_21549;
v_21550:
    v_21614 = nil;
    goto v_21551;
v_21552:
    goto v_21546;
v_21547:
    goto v_21548;
v_21549:
    goto v_21550;
v_21551:
    {
        fn = elt(env, 11); // log_freevars_list
        return (*qfnn(fn))(fn, 3, v_21616, v_21615, v_21614);
    }
v_21536:
    goto v_21573;
v_21569:
    v_21616 = stack[0];
    goto v_21570;
v_21571:
    v_21614 = elt(env, 10); // cond
    goto v_21572;
v_21573:
    goto v_21569;
v_21570:
    goto v_21571;
v_21572:
    if (!consp(v_21616)) goto v_21567;
    v_21616 = qcar(v_21616);
    if (v_21616 == v_21614) goto v_21566;
    else goto v_21567;
v_21566:
    goto v_21581;
v_21577:
    goto v_21578;
v_21579:
    v_21614 = stack[0];
    v_21614 = qcdr(v_21614);
    goto v_21580;
v_21581:
    goto v_21577;
v_21578:
    goto v_21579;
v_21580:
    {
        fn = elt(env, 12); // log_freevars_list_list
        return (*qfn2(fn))(fn, v_21615, v_21614);
    }
v_21567:
    v_21614 = stack[0];
    v_21614 = qcar(v_21614);
    if (!consp(v_21614)) goto v_21585;
    else goto v_21586;
v_21585:
    goto v_21596;
v_21590:
    v_21616 = v_21615;
    goto v_21591;
v_21592:
    v_21614 = stack[0];
    v_21615 = qcdr(v_21614);
    goto v_21593;
v_21594:
    v_21614 = nil;
    goto v_21595;
v_21596:
    goto v_21590;
v_21591:
    goto v_21592;
v_21593:
    goto v_21594;
v_21595:
    {
        fn = elt(env, 11); // log_freevars_list
        return (*qfnn(fn))(fn, 3, v_21616, v_21615, v_21614);
    }
v_21586:
    goto v_21610;
v_21604:
    v_21616 = v_21615;
    goto v_21605;
v_21606:
    v_21615 = stack[0];
    goto v_21607;
v_21608:
    v_21614 = nil;
    goto v_21609;
v_21610:
    goto v_21604;
v_21605:
    goto v_21606;
v_21607:
    goto v_21608;
v_21609:
    {
        fn = elt(env, 11); // log_freevars_list
        return (*qfnn(fn))(fn, 3, v_21616, v_21615, v_21614);
    }
    v_21614 = nil;
v_21369:
    return onevalue(v_21614);
}



setup_type const u38_setup[] =
{
    {"valuecoefft",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_valuecoefft},
    {"rl_convertarg",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rl_convertarg},
    {"mri_opn",                 CC_mri_opn,     TOO_MANY_1,    WRONG_NO_1},
    {"internal-factorf",        CC_internalKfactorf,TOO_MANY_1,WRONG_NO_1},
    {"ioto_smaprinbuf",         CC_ioto_smaprinbuf,TOO_MANY_1, WRONG_NO_1},
    {"setfuncsnaryrd",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setfuncsnaryrd},
    {"rewrite",                 CC_rewrite,     TOO_MANY_1,    WRONG_NO_1},
    {"evalnumberp",             CC_evalnumberp, TOO_MANY_1,    WRONG_NO_1},
    {"contposp",                CC_contposp,    TOO_MANY_1,    WRONG_NO_1},
    {"diff_vertex",             TOO_FEW_2,      CC_diff_vertex,WRONG_NO_2},
    {"dp_from_ei",              CC_dp_from_ei,  TOO_MANY_1,    WRONG_NO_1},
    {"getavalue",               CC_getavalue,   TOO_MANY_1,    WRONG_NO_1},
    {"msolve-psys1",            TOO_FEW_2,      CC_msolveKpsys1,WRONG_NO_2},
    {"lalr_expand_grammar",     CC_lalr_expand_grammar,TOO_MANY_1,WRONG_NO_1},
    {"cl_atnum",                CC_cl_atnum,    TOO_MANY_1,    WRONG_NO_1},
    {"simpexpt1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_simpexpt1},
    {"rl_bnfsimpl",             TOO_FEW_2,      CC_rl_bnfsimpl,WRONG_NO_2},
    {"dvfsf_smupdknowl",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dvfsf_smupdknowl},
    {"groebinvokecritm",        TOO_FEW_2,      CC_groebinvokecritm,WRONG_NO_2},
    {"vdpcleanup",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vdpcleanup},
    {"bflessp",                 TOO_FEW_2,      CC_bflessp,    WRONG_NO_2},
    {"intrdsortin",             TOO_FEW_2,      CC_intrdsortin,WRONG_NO_2},
    {"z-roads",                 CC_zKroads,     TOO_MANY_1,    WRONG_NO_1},
    {"janettreenodebuild",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_janettreenodebuild},
    {"ofsf_qesubqat",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_qesubqat},
    {"testord",                 TOO_FEW_2,      CC_testord,    WRONG_NO_2},
    {"tayfkern",                CC_tayfkern,    TOO_MANY_1,    WRONG_NO_1},
    {"mk+outer+list",           CC_mkLouterLlist,TOO_MANY_1,   WRONG_NO_1},
    {"repr_n",                  CC_repr_n,      TOO_MANY_1,    WRONG_NO_1},
    {"minusrd",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_minusrd},
    {"divide-by-power-of-ten",  TOO_FEW_2,      CC_divideKbyKpowerKofKten,WRONG_NO_2},
    {"atom_compare",            TOO_FEW_2,      CC_atom_compare,WRONG_NO_2},
    {"set_parser",              CC_set_parser,  TOO_MANY_1,    WRONG_NO_1},
    {"sq_member",               TOO_FEW_2,      CC_sq_member,  WRONG_NO_2},
    {"mri_ofsf2mriat",          TOO_FEW_2,      CC_mri_ofsf2mriat,WRONG_NO_2},
    {"rl_surep",                TOO_FEW_2,      CC_rl_surep,   WRONG_NO_2},
    {"sfto_b:ordexp",           TOO_FEW_2,      CC_sfto_bTordexp,WRONG_NO_2},
    {"intervalom",              CC_intervalom,  TOO_MANY_1,    WRONG_NO_1},
    {"greatertype",             TOO_FEW_2,      CC_greatertype,WRONG_NO_2},
    {"groebspolynom3",          TOO_FEW_2,      CC_groebspolynom3,WRONG_NO_2},
    {"exdfprn",                 CC_exdfprn,     TOO_MANY_1,    WRONG_NO_1},
    {"multiply-by-power-of-ten",TOO_FEW_2,      CC_multiplyKbyKpowerKofKten,WRONG_NO_2},
    {"calc_den_tar",            TOO_FEW_2,      CC_calc_den_tar,WRONG_NO_2},
    {"log_freevars",            TOO_FEW_2,      CC_log_freevars,WRONG_NO_2},
    {NULL, (one_args *)"u38", (two_args *)"21386 2350622 1467020", 0}
};

// end of generated code
