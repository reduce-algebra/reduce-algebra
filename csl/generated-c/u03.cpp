
// $destdir/u03.c        Machine generated C code

// $Id$

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#ifndef _cplusplus
#include <setjmp.h>
#endif

#include "config.h"

#ifndef header_machine_h
#define header_machine_h 1
#if !defined UNDER_CE && !defined EMBEDDED
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
#if defined __cplusplus && !defined __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
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
typedef int CSLbool;
#define YES 1
#define NO 0
#define CSL_IGNORE(x) ((void)(x))
#ifndef PAGE_BITS
# define PAGE_BITS 22
#endif 
#define PAGE_POWER_OF_TWO (((intptr_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE (PAGE_POWER_OF_TWO - 256)
#ifndef MAX_HEAPSIZE
# define MAX_HEAPSIZE (SIXTY_FOUR_BIT ? (512*1024) : 2048)
#endif 
#ifndef MAX_BPSSIZE
# define MAX_BPSSIZE 64
#endif 
#define MEGABYTE ((intptr_t)0x100000U)
#if PAGE_BITS >= 20
#define MAX_PAGES (MAX_HEAPSIZE >> (PAGE_BITS-20))
#define MAX_BPS_PAGES (MAX_BPSSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES (MAX_HEAPSIZE << (20-PAGE_BITS))
#define MAX_BPS_PAGES (MAX_BPSSIZE << (20-PAGE_BITS))
#endif
#define MAX_NATIVE_PAGES MAX_BPS_PAGES
#define LONGEST_LEGAL_FILENAME 1024
#define FP_WORD_ORDER 0x01
#define FP_BYTE_ORDER 0x02
#define FP_MASK 0xff
typedef intptr_t LispObject;
#define CELL ((intptr_t)sizeof(LispObject))
#define TAG_BITS 7
#define TAG_CONS 0 
#define TAG_FIXNUM 1 
#define TAG_ODDS 2 
#define TAG_SFLOAT 3 
#define TAG_SYMBOL 4 
#define TAG_NUMBERS 5 
#define TAG_VECTOR 6 
#define TAG_BOXFLOAT 7 
#define fixnum_of_int(x) ((LispObject)(TAG_FIXNUM + (((int32_t)(x)) << 4)))
#ifdef SIGNED_SHIFTS_ARE_LOGICAL
#define int_of_fixnum(x) ((int32_t)(((int32_t)(x)) < 0 ? \
 (((int32_t)(x))>>4) | (-0x10000000) : \
 (((int32_t)(x))>>4)))
#else 
#define int_of_fixnum(x) ((int32_t)(((int32_t)(x)) >> 4))
#endif 
#define GC_BIT_I 8 
#define GC_BIT_H 8 
#define GC_BIT_P ((intptr_t)~((~(uintptr_t)0) >> 1))
#define is_marked_i(w) (((int)(w) & GC_BIT_I) != 0)
extern LispObject address_sign; 
#define is_marked_p(w) (((LispObject)(w) - address_sign) < 0)
#define clear_mark_bit_p(w) (((LispObject)(w) & ~GC_BIT_P) + \
 address_sign)
#define flip_mark_bit_i(w) ((LispObject)(w) ^ GC_BIT_I)
#define flip_mark_bit_h(w) ((Header)(w) ^ GC_BIT_H)
#define flip_mark_bit_p(w) ((LispObject)(w) ^ GC_BIT_P)
#define is_marked_h(w) (((int)(w) & GC_BIT_H) != 0)
#define exception_pending() (((int)nil & 1) != 0)
#define flip_exception() (nil = C_nil = (nil ^ 1))
#define ignore_exception() \
 do { nil = C_nil; if (exception_pending()) flip_exception(); } while (0)
#define set_mark_bit_h(h) ((Header)(h) | GC_BIT_H)
#define clear_mark_bit_h(h) ((Header)(h) & ~GC_BIT_H)
#define set_mark_bit_i(h) ((LispObject)(h) | GC_BIT_I)
#define clear_mark_bit_i(h) ((LispObject)(h) & ~GC_BIT_I)
#define is_cons(p) ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & TAG_BITS) == TAG_FIXNUM)
#define is_odds(p) ((((int)(p)) & TAG_BITS) == TAG_ODDS) 
#define is_sfloat(p) ((((int)(p)) & TAG_BITS) == TAG_SFLOAT)
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)
#ifdef COMMON
#define consp(p) (is_cons(p) && (p) != nil)
#define symbolp(p) (is_symbol(p) || (p) == nil)
#else 
#define consp(p) is_cons(p)
#define symbolp(p) is_symbol(p)
#endif 
#define car_legal(p) is_cons(p)
#define is_number(p) ((((int)(p)) & 1) != 0) 
#define is_float(p) ((((int)(p)) & 3) == 3) 
#define is_immed_or_cons(p) ((((int)(p)) & 4) == 0)
typedef struct Cons_Cell
{ LispObject car;
 LispObject cdr;
} Cons_Cell;
#ifdef MEMORY_TRACE
extern Cons_Cell *memory_reference(intptr_t p);
extern char *cmemory_reference(intptr_t p);
extern void identify_page_types();
extern long int car_counter;
extern unsigned long int car_low, car_high;
#define qcar(p) (memory_reference((intptr_t)p)->car)
#define qcdr(p) (memory_reference((intptr_t)p)->cdr)
#else 
#define qcar(p) (((Cons_Cell *) (p))->car)
#define qcdr(p) (((Cons_Cell *) (p))->cdr)
#endif 
#define car32(p) (*(int32_t *)(p))
#define cdr32(p) (*(int32_t *)(p))[1])
typedef LispObject Special_Form(LispObject, LispObject);
typedef LispObject one_args(LispObject, LispObject);
typedef LispObject two_args(LispObject, LispObject, LispObject);
typedef LispObject n_args(LispObject, int, ...);
typedef uintptr_t Header;
#define header_mask 0x3f0
#define type_of_header(h) (((unsigned int)(h)) & header_mask)
#define length_of_header(h) (((uint32_t)(h)) >> 10)
#define TYPE_SYMBOL 0x00000010
#define SYM_SPECIAL_VAR 0x00000040 
#define SYM_GLOBAL_VAR 0x00000080 
#define SYM_SPECIAL_FORM 0x00000100 
#define SYM_MACRO 0x00000200 
#define SYM_C_DEF 0x00000400 
#define SYM_CODEPTR 0x00000800 
#define SYM_ANY_GENSYM 0x00001000 
#define SYM_TRACED 0x00002000
#define SYM_FASTGET_MASK 0x000fc000 
#define SYM_FASTGET_SHIFT 14
#ifdef COMMON
#define SYM_EXTERN_IN_HOME 0x00100000 
#define SYM_IN_PACKAGE 0xffe00000 
#define SYM_IN_PKG_SHIFT 23
#define SYM_IN_PKG_COUNT 11
#else 
#define SYM_UNPRINTED_GENSYM 0x00100000
#endif 
#define symhdr_length ((sizeof(Symbol_Head) + 7) & ~7)
#define is_symbol_header(h) (((int)h & 0x30) == TYPE_SYMBOL)
#define header_fastget(h) (((h) >> SYM_FASTGET_SHIFT) & 0x3f)
#define TYPE_BIGNUM 0x020 
#define TYPE_RATNUM 0x060
#define TYPE_COMPLEX_NUM 0x0a0
#define TYPE_SINGLE_FLOAT 0x120
#define TYPE_DOUBLE_FLOAT 0x160
#define TYPE_LONG_FLOAT 0x1a0
#ifdef MEMORY_TRACE
#define numhdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
 TAG_NUMBERS)))
#define flthdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
 TAG_BOXFLOAT)))
#else
#define numhdr(v) (*(Header *)((char *)(v) - TAG_NUMBERS))
#define flthdr(v) (*(Header *)((char *)(v) - TAG_BOXFLOAT))
#endif
#define is_numbers_header(h) (((int)(h) & 0x330) == 0x020)
#define is_boxfloat_header(h)(((int)(h) & 0x330) == 0x120)
#define is_ratio(n) \
 (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
 (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
#define ADDRESS_SHIFT (SIXTY_FOUR_BIT ? 3 : 2)
#ifdef MEMORY_TRACE
#define vechdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
 TAG_VECTOR)))
#define elt(v, n) (*(LispObject *)memory_reference((intptr_t)((char *)(v) + \
 (CELL-TAG_VECTOR) + \
 (((intptr_t)(n))<<ADDRESS_SHIFT))))
#define celt(v, n) (*cmemory_reference((intptr_t)((char *)(v) + \
 (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define ucelt(v, n) (*(unsigned char *)cmemory_reference( \
 (intptr_t)((char *)(v) + \
 (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define scelt(v, n) (*(signed char *)cmemory_reference( \
 (intptr_t)((char *)(v) + \
 (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#else 
#define vechdr(v) (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n) (*(LispObject *)((char *)(v) + \
 (CELL-TAG_VECTOR) + \
 (((intptr_t)(n))<<ADDRESS_SHIFT)))
#define celt(v, n) (*((char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define ucelt(v, n) (*((unsigned char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define scelt(v, n) (*((signed char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#endif 
#define helt(v, n) \
 ((*(unsigned char *)((v) + (CELL-TAG_VECTOR) + (2*(intptr_t)(n))) | \
 (*(signed char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n)))) << 8))
#define sethelt(v, n, x) \
 do { \
 *(char *)((v) + (CELL-TAG_VECTOR+0) + (2*(intptr_t)(n))) = (x); \
 *(char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n))) = (x)>>8; \
 } while (0)
#define ielt(v, n) (*(intptr_t *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))<<ADDRESS_SHIFT)))
#define ielt32(v, n) (*(int32_t *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define felt(v, n) (*(float *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define delt(v, n) (*(double *)((char *)(v) + \
 (2*CELL-TAG_VECTOR)+(((intptr_t)(n))<<3)))
#define TYPE_BITVEC1 0x030 
#define TYPE_BITVEC2 0x0b0 
#define TYPE_BITVEC3 0x130
#define TYPE_BITVEC4 0x1b0 
#define TYPE_BITVEC5 0x230 
#define TYPE_BITVEC6 0x2b0 
#define TYPE_BITVEC7 0x330 
#define TYPE_BITVEC8 0x3b0 
#define header_of_bitvector(h) (((h) & 0x70) == TYPE_BITVEC1)
#define TYPE_STRING 0x070 
#define TYPE_BPS 0x170 
#define TYPE_SPARE 0x270 
#define TYPE_MAPLEREF TYPE_SPARE 
#define TYPE_FOREIGN TYPE_SPARE 
#define TYPE_SP 0x370 
#define vector_holds_binary(h) (((h) & 0x80) == 0 || header_of_bitvector(h))
#define TYPE_SIMPLE_VEC 0x0f0 
#define TYPE_HASH 0x1f0 
#define TYPE_ARRAY 0x2f0 
#define TYPE_STRUCTURE 0x3f0 
#define is_mixed_header(h) (((h) & 0x2b0) == TYPE_MIXED1)
#define TYPE_VEC8 TYPE_BPS
#define TYPE_VEC16 0x220 
#define TYPE_VEC32 0x260 
#define TYPE_MIXED1 0x2a0 
#define TYPE_MIXED2 0x2e0 
#define TYPE_FLOAT32 0x320 
#define TYPE_FLOAT64 0x360 
#define TYPE_MIXED3 0x3a0 
#define TYPE_STREAM 0x3e0 
#define ODDS_MASK 0xff
#define TAG_CHAR 0x02 
#define TAG_BPS 0x42
#define TAG_SPID 0xc2 
#define SPID_NIL (TAG_SPID+0x0000) 
#define SPID_FBIND (TAG_SPID+0x0100) 
#define SPID_CATCH (TAG_SPID+0x0200) 
#define SPID_PROTECT (TAG_SPID+0x0300) 
#define SPID_HASH0 (TAG_SPID+0x0400) 
#define SPID_HASH1 (TAG_SPID+0x0500) 
#define SPID_GCMARK (TAG_SPID+0x0600) 
#define SPID_NOINPUT (TAG_SPID+0x0700) 
#define SPID_ERROR (TAG_SPID+0x0800) 
#define SPID_PVBIND (TAG_SPID+0x0900) 
#define SPID_NOARG (TAG_SPID+0x0a00) 
#define SPID_NOPROP (TAG_SPID+0x0b00) 
#define SPID_LIBRARY (TAG_SPID+0x0c00) 
#define is_header(x) (((int)(x) & 0x30) != 0) 
#define is_char(x) (((int)(x) & ODDS_MASK) == TAG_CHAR)
#define is_bps(x) (((int)(x) & ODDS_MASK) == TAG_BPS)
#define is_spid(x) (((int)(x) & ODDS_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xffff) == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#define font_of_char(n) (((int32_t)(n) >> 29) & 0x03)
#define bits_of_char(n) (0)
#define code_of_char(n) (((int32_t)(n) >> 8) & 0x001fffff)
#define pack_char(font, code) \
 ((LispObject)((((uint32_t)(font)) << 29) | \
 (((uint32_t)(code)) << 8) | TAG_CHAR))
#define CHAR_EOF pack_char(0, 0x0010ffff)
#define data_of_bps(v) \
 ((char *)(doubleword_align_up((intptr_t) \
 bps_pages[((uint32_t)(v))>>(PAGE_BITS+6)]) + \
 (SIXTY_FOUR_BIT ? \
 (intptr_t)((((uint64_t)(v))>>(32-PAGE_BITS)) & \
 PAGE_POWER_OF_TWO) : \
 0) + \
 (((v) >> 6) & (PAGE_POWER_OF_TWO-4))))
typedef int32_t junk; 
typedef intptr_t junkxx; 
typedef struct Symbol_Head
{
 Header header; 
 LispObject value; 
 LispObject env; 
 intptr_t function1; 
 intptr_t function2; 
 intptr_t functionn; 
 LispObject pname; 
 LispObject plist; 
 LispObject fastgets;
 uintptr_t count; 
#ifdef COMMON
 LispObject package;
#endif 
} Symbol_Head;
#define MAX_FASTGET_SIZE 63
#ifdef COMMON
#define symalign(n) (SIXTY_FOUR_BIT ? \
 ((char *)((intptr_t)(n) & ~(intptr_t)TAG_SYMBOL)) : \
 (n))
#else
#define symalign(n) (n)
#endif
#ifndef MEMORY_TRACE
#define qheader(p) (*(Header *) symalign((char *)(p) - TAG_SYMBOL))
#define qvalue(p) (*(LispObject *)symalign((char *)(p) + (CELL - TAG_SYMBOL)))
#define qenv(p) (*(LispObject *)symalign((char *)(p) + (2*CELL - TAG_SYMBOL)))
#define qfn1(p) ((one_args *) *((intptr_t *)symalign((char *)(p) + \
 (3*CELL - TAG_SYMBOL))))
#define qfn2(p) ((two_args *) *((intptr_t *)symalign((char *)(p) + \
 (4*CELL - TAG_SYMBOL))))
#define qfnn(p) ((n_args *) *((intptr_t *)symalign((char *)(p) + \
 (5*CELL - TAG_SYMBOL))))
#define ifn1(p) (*(intptr_t *)symalign((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define ifn2(p) (*(intptr_t *)symalign((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define ifnn(p) (*(intptr_t *)symalign((char *)(p) + (5*CELL-TAG_SYMBOL)))
#define qpname(p) (*(LispObject *)symalign((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define qplist(p) (*(LispObject *)symalign((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfastgets(p) (*(LispObject *)symalign((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qcount(p) (*(uintptr_t *) symalign((char *)(p) + (9*CELL-TAG_SYMBOL)))
#ifdef COMMON
#define qpackage(p) (*(LispObject *)symalign((char *)(p) + (10*CELL-TAG_SYMBOL)))
#endif
#else 
#define qheader(p) (*(Header *) memory_reference((intptr_t) \
 symalign((char *)(p) - TAG_SYMBOL)))
#define qvalue(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (CELL-TAG_SYMBOL))))
#define qenv(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (2*CELL-TAG_SYMBOL))))
#define qfn1(p) ((one_args *) *(intptr_t *)memory_reference((intptr_t) \
 symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define qfn2(p) ((two_args *) *(intptr_t *)memory_reference((intptr_t) \
 symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define qfnn(p) ((n_args *) *(intptr_t *)memory_reference((intptr_t) \
 symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define ifn1(p) (*(intptr_t *) memory_reference((intptr_t) \
 symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define ifn2(p) (*(intptr_t *) memory_reference((intptr_t) \
 symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define ifnn(p) (*(intptr_t *) memory_reference((intptr_t) \
 symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define qpname(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (6*CELL-TAG_SYMBOL))))
#define qplist(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (7*CELL-TAG_SYMBOL))))
#define qfastgets(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (8*CELL-TAG_SYMBOL))))
#define qcount(p) (*(uintptr_t *) memory_reference((intptr_t) \
 symalign((char *)(p) + (9*CELL-TAG_SYMBOL))))
#ifdef COMMON
#define qpackage(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (10*CELL-TAG_SYMBOL))))
#endif
#endif 
typedef union Float_union
{ float f;
 int32_t i;
} Float_union;
typedef struct Big_Number
{
 Header h;
 uint32_t d[1]; 
} Big_Number;
#define bignum_length(b) length_of_header(numhdr(b))
#ifdef MEMORY_TRACE
#define bignum_digits(b) ((uint32_t *)memory_reference((intptr_t)((char *)b + \
 (CELL-TAG_NUMBERS))))
#else
#define bignum_digits(b) ((uint32_t *)((char *)b + (CELL-TAG_NUMBERS)))
#endif
#define make_bighdr(n) (TAG_ODDS+TYPE_BIGNUM+(((intptr_t)(n))<<12))
#define pack_hdrlength(n) (((intptr_t)(n))<<12)
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
 int32_t i;
 } f;
} Single_Float;
#define single_float_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#define SIZEOF_DOUBLE_FLOAT 16
#define double_float_addr(v) ((double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define double_float_val(v) (*(double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define SIZEOF_LONG_FLOAT 16
#define long_float_addr(v) ((double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define long_float_val(v) (*(double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define word_align_up(n) ((LispObject)(((intptr_t)(n) + 3) & (-4)))
#define doubleword_align_up(n) ((LispObject)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((LispObject)((intptr_t)(n) & (-8)))
#define object_align_up(n) ((LispObject)(((intptr_t)(n) + \
 sizeof(LispObject) - 1) & (-sizeof(LispObject))))
#define quadword_align_up(n) ((LispObject)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((LispObject)((intptr_t)(n) & (-16)))
#define UNWIND_NULL 0x0 
#define UNWIND_GO 0x1 
#define UNWIND_RETURN 0x2 
#define UNWIND_THROW 0x3 
#define UNWIND_RESTART 0x4 
#define UNWIND_RESOURCE 0x5 
#define UNWIND_FNAME 0x100 
#define UNWIND_ARGS 0x200 
#define UNWIND_ERROR (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND 0x400 
#if 0 && defined DEBUG
#define SHOW_FNAME (exit_reason == UNWIND_THROW || \
 (exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS (exit_reason == UNWIND_THROW || \
 (exit_reason & UNWIND_ARGS) != 0)
#else
#define SHOW_FNAME ((exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS ((exit_reason & UNWIND_ARGS) != 0)
#endif
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern "C" LispObject interrupted(LispObject p);
extern "C" LispObject error(int nargs, int code, ...);
extern "C" LispObject cerror(int nargs, int code1, int code2, ...);
extern "C" LispObject too_few_2(LispObject env, LispObject a1);
extern "C" LispObject too_many_1(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject wrong_no_0a(LispObject env, LispObject a1);
extern "C" LispObject wrong_no_0b(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject wrong_no_3a(LispObject env, LispObject a1);
extern "C" LispObject wrong_no_3b(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject wrong_no_na(LispObject env, LispObject a1);
extern "C" LispObject wrong_no_nb(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject wrong_no_1(LispObject env, int nargs, ...);
extern "C" LispObject wrong_no_2(LispObject env, int nargs, ...);
extern "C" LispObject bad_specialn(LispObject env, int nargs, ...);
extern "C" LispObject aerror(const char *s); 
extern "C" LispObject aerror0(const char *s);
extern "C" LispObject aerror1(const char *s, LispObject a);
extern "C" LispObject aerror2(const char *s, LispObject a, LispObject b);
extern "C" void fatal_error(int code, ...);
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
#define err_undefined_function_1 3 
#define err_undefined_function_2 4 
#define err_undefined_function_n 5 
#define err_wrong_no_args 6 
#define err_unbound_lexical 7 
#define err_bad_rplac 8 
#define err_bad_arith 9 
#define err_redef_special 10 
#define err_bad_arg 11 
#define err_bad_declare 12 
#define err_bad_fn 13 
#define err_unset_var 14 
#define err_too_many_args1 15 
#define err_too_many_args2 16 
#define err_bad_apply 17 
#define err_macroex_hook 18 
#define err_block_tag 19 
#define err_go_tag 20 
#define err_excess_args 21
#define err_insufficient_args 22
#define err_bad_bvl 23 
#define err_bad_keyargs 24
#define err_write_err 25
#define err_bad_endp 26 
#define err_no_fasldir 27
#define err_no_fasl 28 
#define err_open_failed 29 
#define err_pipe_failed 30 
#define err_stack_overflow 31
#define err_top_bit 32
#define err_mem_spans_zero 33
#define err_no_longer_used 34 
#define err_no_tempdir 35
#ifdef INCLUDE_ERROR_STRING_TABLE
static const char *error_message_table[] =
{ "attempt to take car of an atom",
 "attempt to take cdr of an atom",
 "insufficient freestore to run this package",
 "undefined function (1 arg)",
 "undefined function (2 args)",
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
 "too many arguments",
 "too many arguments",
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
extern void **pages,
 **heap_pages, **vheap_pages,
 **bps_pages, **native_pages;
extern void **new_heap_pages, **new_vheap_pages,
 **new_bps_pages, **new_native_pages;
#ifdef CONSERVATIVE
#define PAGE_TYPE_CONS 0
#define PAGE_TYPE_VECTOR 1
#define PAGE_TYPE_BPS 2
#define PAGE_TYPE_NATIVE 3
typedef struct page_map_t
{ void *start;
 void *end;
 int type;
} page_map_t;
#endif
extern int32_t pages_count,
 heap_pages_count, vheap_pages_count,
 bps_pages_count, native_pages_count;
extern int32_t new_heap_pages_count, new_vheap_pages_count,
 new_bps_pages_count, new_native_pages_count;
extern int32_t native_pages_changed;
extern int32_t native_fringe;
extern LispObject *nilsegment, *stacksegment;
extern LispObject *stackbase;
extern int32_t stack_segsize; 
extern LispObject *C_stack;
#define stack C_stack
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
extern CSLbool restartp;
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern LispObject *C_stackbase, *C_stacktop;
#endif
extern LispObject multiplication_buffer;
#ifdef MEMORY_TRACE
#define push(a) do { \
 *++stack = (a); \
 memory_reference((intptr_t)stack); } while (0)
#define push2(a,b) do { \
 *++stack = (a); \
 memory_reference((intptr_t)stack); \
 *++stack = (b); \
 memory_reference((intptr_t)stack); } while (0)
#define push3(a,b,c) do { \
 *++stack = (a); \
 memory_reference((intptr_t)stack); \
 *++stack = (b); \
 memory_reference((intptr_t)stack); \
 *++stack = (c); \
 memory_reference((intptr_t)stack); } while (0)
#define push4(a,b,c,d) do { \
 *++stack = (a); \
 memory_reference((intptr_t)stack); \
 *++stack = (b); \
 memory_reference((intptr_t)stack); \
 *++stack = (c); \
 memory_reference((intptr_t)stack); \
 *++stack = (d); \
 memory_reference((intptr_t)stack); } while (0)
#define push5(a,b,c,d,e)do { \
 *++stack = (a); \
 memory_reference((intptr_t)stack); \
 *++stack = (b); \
 memory_reference((intptr_t)stack); \
 *++stack = (c); \
 memory_reference((intptr_t)stack); \
 *++stack = (d); \
 memory_reference((intptr_t)stack); \
 *++stack = (e); \
 memory_reference((intptr_t)stack); } while (0)
#define push6(a,b,c,d,e,f) do {push3(a,b,c); push3(d,e,f); } while (0)
#define my_pop() (memory_reference((int32_t)stack), (*stack--))
#define pop(a) { memory_reference((intptr_t)stack); (a) = *stack--; }
#define pop2(a,b) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; }
#define pop3(a,b,c) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; }
#define pop4(a,b,c,d) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
 memory_reference((intptr_t)stack); (d) = *stack--; }
#define pop5(a,b,c,d,e) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
 memory_reference((intptr_t)stack); (d) = *stack--; memory_reference((intptr_t)stack); (e) = *stack--; }
#define pop6(a,b,c,d,e,f) {pop3(a,b,c); pop3(d,e,f)}
#define popv(n) stack -= (n)
#else 
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
#endif 
#define errexit() { nil = C_nil; if (exception_pending()) return nil; }
#define errexitn(n) { nil = C_nil; \
 if (exception_pending()) { popv(n); return nil; } }
#define errexitv() { nil = C_nil; if (exception_pending()) return; }
#define errexitvn(n) { nil = C_nil; \
 if (exception_pending()) { popv(n); return; } }
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK 2
#define GC_CONS 3
#define GC_VEC 4
#define GC_BPS 5
#define GC_PRESERVE 6
#define GC_NATIVE 7
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(const char *file, int line);
extern void show_stack();
#define if_check_stack \
 if (check_stack("@" __FILE__,__LINE__)) \
 { show_stack(); return aerror("stack overflow"); }
#else
#define if_check_stack \
 { const char *p = (char *)&p; \
 if (p < C_stack_limit) return aerror("stack overflow"); \
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
extern volatile int blipflag;
extern int64_t blipcount, startblip;
#if defined __linux__ && defined DEBUG
#define HANDLE_BLIP \
 if (blipflag) \
 { blipflag = 0; \
 if (startblip >= 0 && ++blipcount > startblip) \
 { fprintf(stderr, "Line %d of file %s\n", __LINE__, __FILE__); \
 fflush(stderr); \
 } \
 }
#else
#define HANDLE_BLIP
#endif
#define stackcheck0(k) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { reclaim(nil, "stack", GC_STACK, 0); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
#define stackcheck1(k, a1) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { a1 = reclaim(a1, "stack", GC_STACK, 0); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
#define stackcheck2(k, a1, a2) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push(a2); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
#define stackcheck3(k, a1, a2, a3) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push2(a2, a3); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); \
 pop2(a3, a2); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
#define stackcheck4(k, a1, a2, a3, a4) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push3(a2, a3, a4); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); \
 pop3(a4, a3, a2); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
extern LispObject C_nil;
#define first_nil_offset 50 
#define work_0_offset 200
#define last_nil_offset 251
#define NIL_SEGMENT_SIZE (last_nil_offset*sizeof(LispObject) + 32)
#define SPARE 512
#ifdef COMMON
#define BASE ((LispObject *)nil)
#else
#define BASE (SIXTY_FOUR_BIT ? ((LispObject *)(nil+4)): ((LispObject *)nil))
#endif
extern intptr_t byteflip;
extern LispObject codefringe;
extern LispObject volatile codelimit;
extern LispObject * volatile stacklimit;
extern LispObject fringe;
extern LispObject volatile heaplimit;
extern LispObject volatile vheaplimit;
extern LispObject vfringe;
extern intptr_t nwork;
extern intptr_t exit_count;
extern intptr_t gensym_ser, print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern intptr_t modulus_is_large;
extern LispObject lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern LispObject quote_symbol, function_symbol, comma_symbol;
extern LispObject comma_at_symbol, cons_symbol, eval_symbol;
extern LispObject work_symbol, evalhook, applyhook, macroexpand_hook;
extern LispObject append_symbol, exit_tag, exit_value, catch_tags;
extern LispObject current_package, startfn;
extern LispObject gensym_base, string_char_sym, boffo;
extern LispObject err_table;
extern LispObject progn_symbol;
extern LispObject lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern LispObject echo_symbol, codevec, litvec, supervisor, B_reg;
extern LispObject savedef, comp_symbol, compiler_symbol, faslvec;
extern LispObject tracedfn, lisp_terminal_io;
extern LispObject lisp_standard_output, lisp_standard_input, lisp_error_output;
extern LispObject lisp_trace_output, lisp_debug_io, lisp_query_io;
extern LispObject prompt_thing, faslgensyms;
extern LispObject prinl_symbol, emsg_star, redef_msg;
extern LispObject expr_symbol, fexpr_symbol, macro_symbol;
extern LispObject cl_symbols, active_stream, current_module;
extern LispObject native_defs, features_symbol, lisp_package;
extern LispObject sys_hash_table, help_index, cfunarg, lex_words;
extern LispObject get_counts, fastget_names, input_libraries;
extern LispObject output_library, current_file, break_function;
extern LispObject standard_output, standard_input, debug_io;
extern LispObject error_output, query_io, terminal_io;
extern LispObject trace_output, fasl_stream;
extern LispObject native_code, native_symbol, traceprint_symbol;
extern LispObject loadsource_symbol;
extern LispObject hankaku_symbol, bytecoded_symbol, nativecoded_symbol;
extern LispObject gchook, resources, callstack, procstack, procmem;
extern LispObject trap_time, count_high;
#ifdef COMMON
extern LispObject keyword_package;
extern LispObject all_packages, package_symbol, internal_symbol;
extern LispObject external_symbol, inherited_symbol;
extern LispObject key_key, allow_other_keys, aux_key;
extern LispObject format_symbol;
extern LispObject expand_def_symbol, allow_key_key;
#endif
extern LispObject declare_symbol, special_symbol, large_modulus;
extern LispObject used_space, avail_space, eof_symbol, call_stack;
#ifdef OPENMATH
extern LispObject om_openFileDev(LispObject env, int nargs, ...);
extern LispObject om_openStringDev(LispObject nil, LispObject lstr, LispObject lenc);
extern LispObject om_closeDev(LispObject env, LispObject dev);
extern LispObject om_setDevEncoding(LispObject nil, LispObject ldev, LispObject lenc);
extern LispObject om_makeConn(LispObject nil, LispObject ltimeout);
extern LispObject om_closeConn(LispObject nil, LispObject lconn);
extern LispObject om_getConnInDevice(LispObject nil, LispObject lconn);
extern LispObject om_getConnOutDevice(LispObject nil, LispObject lconn);
extern LispObject om_connectTCP(LispObject nil, int nargs, ...);
extern LispObject om_bindTCP(LispObject nil, LispObject lconn, LispObject lport);
extern LispObject om_putApp(LispObject nil, LispObject ldev);
extern LispObject om_putEndApp(LispObject nil, LispObject ldev);
extern LispObject om_putAtp(LispObject nil, LispObject ldev);
extern LispObject om_putEndAtp(LispObject nil, LispObject ldev);
extern LispObject om_putAttr(LispObject nil, LispObject ldev);
extern LispObject om_putEndAttr(LispObject nil, LispObject ldev);
extern LispObject om_putBind(LispObject nil, LispObject ldev);
extern LispObject om_putEndBind(LispObject nil, LispObject ldev);
extern LispObject om_putBVar(LispObject nil, LispObject ldev);
extern LispObject om_putEndBVar(LispObject nil, LispObject ldev);
extern LispObject om_putError(LispObject nil, LispObject ldev);
extern LispObject om_putEndError(LispObject nil, LispObject ldev);
extern LispObject om_putObject(LispObject nil, LispObject ldev);
extern LispObject om_putEndObject(LispObject nil, LispObject ldev);
extern LispObject om_putInt(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putFloat(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putByteArray(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putVar(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putString(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putSymbol(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putSymbol2(LispObject nil, int nargs, ...);
extern LispObject om_getApp(LispObject nil, LispObject ldev);
extern LispObject om_getEndApp(LispObject nil, LispObject ldev);
extern LispObject om_getAtp(LispObject nil, LispObject ldev);
extern LispObject om_getEndAtp(LispObject nil, LispObject ldev);
extern LispObject om_getAttr(LispObject nil, LispObject ldev);
extern LispObject om_getEndAttr(LispObject nil, LispObject ldev);
extern LispObject om_getBind(LispObject nil, LispObject ldev);
extern LispObject om_getEndBind(LispObject nil, LispObject ldev);
extern LispObject om_getBVar(LispObject nil, LispObject ldev);
extern LispObject om_getEndBVar(LispObject nil, LispObject ldev);
extern LispObject om_getError(LispObject nil, LispObject ldev);
extern LispObject om_getEndError(LispObject nil, LispObject ldev);
extern LispObject om_getObject(LispObject nil, LispObject ldev);
extern LispObject om_getEndObject(LispObject nil, LispObject ldev);
extern LispObject om_getInt(LispObject nil, LispObject ldev);
extern LispObject om_getFloat(LispObject nil, LispObject ldev);
extern LispObject om_getByteArray(LispObject nil, LispObject ldev);
extern LispObject om_getVar(LispObject nil, LispObject ldev);
extern LispObject om_getString(LispObject nil, LispObject ldev);
extern LispObject om_getSymbol(LispObject nil, LispObject ldev);
extern LispObject om_getType(LispObject nil, LispObject ldev);
extern LispObject om_stringToStringPtr(LispObject nil, LispObject lstr);
extern LispObject om_stringPtrToString(LispObject nil, LispObject lpstr);
extern LispObject om_read(LispObject nil, LispObject dev);
extern LispObject om_supportsCD(LispObject nil, LispObject lcd);
extern LispObject om_supportsSymbol(LispObject nil, LispObject lcd, LispObject lsym);
extern LispObject om_listCDs(LispObject nil, int nargs, ...);
extern LispObject om_listSymbols(LispObject nil, LispObject lcd);
extern LispObject om_whichCDs(LispObject nil, LispObject lsym);
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
extern void copy_into_nilseg(int fg);
extern void copy_out_of_nilseg(int fg);
#define eq_hash_table_list BASE[50] 
#define equal_hash_table_list BASE[51] 
#define current_package_offset 52
extern void rehash_this_table(LispObject v);
extern LispObject eq_hash_tables, equal_hash_tables;
extern LispObject volatile savecodelimit;
extern LispObject * volatile savestacklimit;
extern LispObject volatile saveheaplimit;
extern LispObject volatile savevheaplimit;
extern char *exit_charvec;
extern intptr_t exit_reason;
extern int procstackp;
#ifdef DEBUG
extern int trace_all;
#endif
#ifndef NO_BYTECOUNT
extern const char *name_of_caller;
#endif
extern int garbage_collection_permitted;
#define MAX_INPUT_FILES 40 
#define MAX_SYMBOLS_TO_DEFINE 40
#define MAX_FASL_PATHS 20
extern const char *files_to_read[MAX_INPUT_FILES],
 *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
 *fasl_paths[MAX_FASL_PATHS];
extern int csl_argc;
extern const char **csl_argv;
extern int fasl_output_file, output_directory;
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif
extern int boffop;
extern void packbyte(int c);
#ifdef HAVE_FWIN
extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();
#endif
#ifdef SOCKETS
extern int sockets_ready;
extern void flush_socket(void);
#endif
extern void report_file(const char *s);
extern CSLbool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];
extern int errorset_min, errorset_max;
extern int number_of_input_files,
 number_of_symbols_to_define,
 number_of_fasl_paths,
 init_flags;
extern int native_code_tag;
extern const char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
extern int force_reclaim_method, reclaim_trap_count, reclaim_stack_limit;
#define INIT_QUIET 1
#define INIT_VERBOSE 2
#define INIT_EXPANDABLE 4
#define Lispify_predicate(p) ((p) ? lisp_true : nil)
extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];
typedef struct Ihandle
{ FILE *f; 
 long int o; 
 long int n; 
 uint32_t chk; 
 int status; 
 int nativedir; 
} Ihandle;
extern int32_t compression_worth_while;
#define CODESIZE 0x1000
typedef struct entry_point1
{ one_args *p;
 const char *s;
} entry_point1;
typedef struct entry_point2
{ two_args *p;
 const char *s;
} entry_point2;
typedef struct entry_pointn
{ n_args *p;
 const char *s;
} entry_pointn;
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_pointn entries_tablen[];
extern entry_pointn entries_table_io[];
extern void set_up_entry_lookup(void);
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
extern LispObject Lencapsulatedp(LispObject nil, LispObject a);
typedef void initfn(LispObject *, LispObject **, LispObject * volatile *);
extern int load_dynamic(const char *objname, const char *modname,
 LispObject name, LispObject fns);
extern "C" LispObject Linstate_c_code(LispObject nil,
 LispObject name, LispObject fns);
extern LispObject characterify(LispObject a);
extern LispObject char_to_id(int ch);
#ifdef MEMORY_TRACE
extern intptr_t memory_base, memory_size;
extern unsigned char *memory_map;
extern FILE *memory_file;
extern void memory_comment(int n);
#endif
#define ARG_CUT_OFF 25
extern void push_args(va_list a, int nargs);
extern void push_args_1(va_list a, int nargs);
extern void Iinit(void);
extern void IreInit(void);
extern void Icontext(Ihandle *);
extern void Irestore_context(Ihandle);
extern void Ilist(void);
extern CSLbool open_output(const char *s, int len);
#define IOPEN_OUT 0
#define IOPEN_UNCHECKED 1
#define IOPEN_CHECKED 2
extern CSLbool Iopen(const char *name, int len, int dirn, char *expanded_name);
extern CSLbool Iopen_from_stdin(void), Iopen_to_stdout(void);
extern CSLbool IopenRoot(char *expanded_name, int hard, int sixtyfour);
extern CSLbool Iwriterootp(char *expanded);
extern CSLbool Iopen_help(int32_t offset);
extern CSLbool Iopen_banner(int code);
extern CSLbool Imodulep(const char *name, int len, char *datestamp, int32_t *size,
 char *expanded_name);
extern CSLbool Icopy(const char *name, int len);
extern CSLbool Idelete(const char *name, int len);
extern CSLbool IcloseInput(int check_checksum);
extern CSLbool IcloseOutput(int write_checksum);
extern CSLbool Ifinished(void);
extern int Igetc(void);
extern int32_t Iread(void *buff, int32_t size);
extern CSLbool Iputc(int ch);
extern CSLbool Iwrite(const void *buff, int32_t size);
extern long int Ioutsize(void);
extern const char *CSLtmpdir();
extern const char *CSLtmpnam(const char *suffix, int32_t suffixlen);
extern int Cmkdir(const char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init(void);
extern void CSL_MD5_Update(const unsigned char *data, int len);
extern void CSL_MD5_Final(unsigned char *md);
extern CSLbool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(LispObject a);
extern unsigned char unpredictable[256];
extern void inject_randomness(int n);
extern void ensure_screen(void);
extern int window_heading;
extern void my_exit(int n);
extern void *my_malloc(size_t n);
extern clock_t base_time;
extern double *clock_stack;
extern void push_clock(void);
extern double pop_clock(void);
extern double consolidated_time[10], gc_time;
extern CSLbool volatile already_in_gc, tick_on_gc_exit;
extern CSLbool volatile interrupt_pending, tick_pending;
extern int deal_with_tick(void);
extern int current_fp_rep;
extern const char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(LispObject *, CSLbool findcatch);
extern CSLbool segvtrap;
extern CSLbool batch_flag;
extern int escaped_printing;
extern void low_level_signal_handler(int code);
extern int async_interrupt(int a);
extern "C" void sigint_handler(int code);
extern "C" void record_get(LispObject tag, CSLbool found);
extern int primep(int32_t);
extern void adjust_all(void);
extern void set_up_functions(CSLbool restartp);
extern void get_user_files_checksum(unsigned char *);
extern "C" LispObject acons(LispObject a, LispObject b, LispObject c);
extern "C" LispObject ash(LispObject a, LispObject b);
extern LispObject bytestream_interpret(LispObject code, LispObject lit,
 LispObject *entry_stack);
extern CSLbool complex_stringp(LispObject a);
extern void freshline_trace(void);
extern void freshline_debug(void);
extern "C" LispObject cons(LispObject a, LispObject b);
extern LispObject cons_no_gc(LispObject a, LispObject b);
extern LispObject cons_gc_test(LispObject a);
extern void convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern LispObject Ceval(LispObject u, LispObject env);
extern LispObject noisy_Ceval(LispObject u, LispObject env);
extern uint32_t Crand(void);
extern "C" LispObject Cremainder(LispObject a, LispObject b);
extern void Csrand(uint32_t a, uint32_t b);
extern void discard(LispObject a);
extern "C" CSLbool eql_fn(LispObject a, LispObject b);
extern "C" CSLbool cl_equal_fn(LispObject a, LispObject b);
extern "C" CSLbool equal_fn(LispObject a, LispObject b);
#ifdef TRACED_EQUAL
extern CSLbool traced_equal_fn(LispObject a, LispObject b,
 const char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern "C" CSLbool equalp(LispObject a, LispObject b);
extern LispObject apply(LispObject fn, int nargs,
 LispObject env, LispObject fname, int noisy);
extern LispObject apply_lambda(LispObject def, int nargs,
 LispObject env, LispObject name, int noisy);
extern void deallocate_pages(void);
extern void drop_heap_segments(void);
extern LispObject gcd(LispObject a, LispObject b);
extern LispObject get_pname(LispObject a);
#ifdef COMMON
extern "C" LispObject get(LispObject a, LispObject b, LispObject c);
#else
extern "C" LispObject get(LispObject a, LispObject b);
#endif
extern LispObject getvector(int tag, int type, size_t length);
extern LispObject getvector_init(size_t n, LispObject v);
extern LispObject getcodevector(int type, size_t size);
extern uint32_t hash_lisp_string(LispObject s);
extern void lose_C_def(LispObject a);
extern "C" CSLbool geq2(LispObject a, LispObject b);
extern "C" CSLbool greaterp2(LispObject a, LispObject b);
extern "C" CSLbool lesseq2(LispObject a, LispObject b);
extern "C" CSLbool lessp2(LispObject a, LispObject b);
extern "C" LispObject list2(LispObject a, LispObject b);
extern "C" LispObject list2star(LispObject a, LispObject b, LispObject c);
extern "C" LispObject list3(LispObject a, LispObject b, LispObject c);
extern "C" LispObject list3star(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern "C" LispObject list4(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern "C" LispObject lognot(LispObject a);
extern LispObject macroexpand(LispObject form, LispObject env);
extern LispObject make_one_word_bignum(int32_t n);
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
extern void preserve(const char *msg, int len);
extern void preserve_native_code(void);
extern void relocate_native_function(unsigned char *bps);
extern LispObject prin(LispObject u);
extern const char *get_string_data(LispObject a, const char *why, size_t *len);
extern void prin_to_stdout(LispObject u);
extern void prin_to_terminal(LispObject u);
extern void prin_to_debug(LispObject u);
extern void prin_to_query(LispObject u);
extern void prin_to_trace(LispObject u);
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
extern void print_bignum(LispObject u, CSLbool blankp, int nobreak);
extern void print_bighexoctbin(LispObject u,
 int radix, int width, CSLbool blankp, int nobreak);
extern LispObject putprop(LispObject a, LispObject b,
 LispObject c);
extern "C" LispObject quot2(LispObject a, LispObject b);
extern "C" LispObject rational(LispObject a);
extern void read_eval_print(int noisy);
extern "C" LispObject reclaim(LispObject value_to_return, const char *why,
 int stg_class, intptr_t size);
#ifdef DEBUG
extern void validate_all(const char *why, int line, const char *file);
extern int check_env(LispObject env);
#endif
extern CSLbool do_not_kill_native_code;
extern void set_fns(LispObject sym, one_args *f1,
 two_args *f2, n_args *fn);
extern void setup(int restartp, double storesize);
extern LispObject simplify_string(LispObject s);
extern CSLbool stringp(LispObject a);
extern "C" LispObject times2(LispObject a, LispObject b);
extern int32_t thirty_two_bits(LispObject a);
#ifdef HAVE_INT64_T
extern int64_t sixty_four_bits(LispObject a);
#endif
#ifdef DEBUG
extern void validate_string_fn(LispObject a, const char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 
#endif
#ifdef COMMON
#define onevalue(r) (exit_count=1, (r))
#define nvalues(r, n) (exit_count=(n), (r))
#else
#define onevalue(r) (r)
#define nvalues(r, n) (r)
#endif
#ifdef COMMON
#define eval(a, b) Ceval(a, b)
#define voideval(a, b) Ceval(a, b)
#define noisy_eval(a, b) noisy_Ceval(a, b)
#define noisy_voideval(a, b) noisy_Ceval(a, b)
#else
#define eval(a, b) \
 (is_cons(a) ? Ceval(a, b) : \
 is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
 onevalue(qvalue(a))) : \
 onevalue(a))
#define voideval(a, b) \
 if (is_cons(a)) Ceval(a, b) 
#define noisy_eval(a, b) \
 (is_cons(a) ? noisy_Ceval(a, b) : \
 is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
 onevalue(qvalue(a))) : \
 onevalue(a))
#define noisy_voideval(a, b) \
 if (is_cons(a)) noisy_Ceval(a, b) 
#endif
#define equal(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 ((unsigned)(((a) & TAG_BITS) - 1) > 3) && \
 equal_fn(a, b)))
#define cl_equal(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 ((unsigned)(((a) & TAG_BITS) - 1) > 3) && \
 cl_equal_fn(a, b)))
#define eql(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 ((unsigned)(((a) & TAG_BITS) - 1) > 3) && \
 eql_fn(a, b)))
#ifndef IMULTIPLY
extern uint32_t Imultiply(uint32_t *rlow, uint32_t a,
 uint32_t b, uint32_t c);
#endif
#ifndef IDIVIDE
extern uint32_t Idivide(uint32_t *qp, uint32_t a,
 uint32_t b, uint32_t c);
extern uint32_t Idiv10_9(uint32_t *qp, uint32_t a, uint32_t b);
#endif
#define argcheck(var, n, msg) if ((var)!=(n)) return aerror(msg);
extern n_args *zero_arg_functions[];
extern one_args *one_arg_functions[];
extern two_args *two_arg_functions[];
extern n_args *three_arg_functions[];
extern void *useful_functions[];
extern char *address_of_var(int n);
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
 print_setup[], read_setup[], mpi_setup[];
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
 LispObject env, int compilerp, int noisy);
extern LispObject mv_call_fn(LispObject args, LispObject env);
extern LispObject noisy_mv_call_fn(LispObject args, LispObject env);
extern LispObject progn_fn(LispObject args, LispObject env);
extern LispObject noisy_progn_fn(LispObject args, LispObject env);
extern LispObject quote_fn(LispObject args, LispObject env);
extern LispObject tagbody_fn(LispObject args, LispObject env);
extern LispObject noisy_tagbody_fn(LispObject args, LispObject env);
extern LispObject resource_exceeded();
extern int64_t time_base, space_base, io_base, errors_base;
extern int64_t time_now, space_now, io_now, errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;
extern CSLbool symbol_protect_flag, warn_about_protected_symbols;
#ifdef JIT
extern char *Jcompile(LispObject def, LispObject env);
extern unsigned long jit_size;
#define JIT_INIT_SIZE 8192
#endif
#endif 
#ifndef header_arith_h
#define header_arith_h 1
#define TWO_32 4294967296.0 
#define TWO_31 2147483648.0 
#define TWO_24 16777216.0 
#define TWO_22 4194304.0 
#define TWO_21 2097152.0 
#define TWO_20 1048576.0 
#define M2_31_1 -2147483649.0 
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
#define top_bit(n) (((uint32_t)(n)) >> 31)
#define set_top_bit(n) ((n) | (uint32_t)0x80000000)
#define clear_top_bit(n) ((n) & 0x7fffffff)
#define signed_overflow(n) top_bit_set((n) ^ (((int32_t)(n))<<1))
#ifdef HAVE_UINT64_T
#define IMULTIPLY 1 
#define Dmultiply(hi, lo, a, b, c) \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) + \
 (uint32_t)(c); \
 (lo) = 0x7fffffffu & (uint32_t)r64; \
 (hi) = (uint32_t)(r64 >> 31); } while (0)
#define IDIVIDE 1
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
#else
#define Dmultiply(hi, lo, a, b, c) ((hi) = Imultiply(&(lo), (a), (b), (c)))
#define Ddivide(r, q, a, b, c) ((r) = Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9(r, q, a, b) ((r) = Idiv10_9(&(q), (a), (b)))
#define Ddivideq(q, a, b, c) (Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9q(q, a, b) (Idiv10_9(&(q), (a), (b)))
#define Ddivider(r, a, b, c) ((r) = Idivide(NULL, (a), (b), (c)))
#define Ddiv10_9r(r, a, b) ((r) = Idiv10_9(NULL, (a), (b)))
#endif
#define fix_mask (-0x08000000)
#define fixnum_minusp(a) ((int32_t)(a) < 0)
#define bignum_minusp(a) \
 ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
extern LispObject negateb(LispObject);
extern LispObject copyb(LispObject);
extern LispObject negate(LispObject);
extern LispObject plus2(LispObject a, LispObject b);
extern "C" LispObject difference2(LispObject a, LispObject b);
extern LispObject times2(LispObject a, LispObject b);
extern "C" LispObject quot2(LispObject a, LispObject b);
extern LispObject CLquot2(LispObject a, LispObject b);
extern LispObject quotbn(LispObject a, int32_t n);
extern LispObject quotbn1(LispObject a, int32_t n);
extern LispObject quotbb(LispObject a, LispObject b);
extern "C" LispObject Cremainder(LispObject a, LispObject b);
extern LispObject rembi(LispObject a, LispObject b);
extern LispObject rembb(LispObject a, LispObject b);
extern LispObject shrink_bignum(LispObject a, int32_t lena);
extern LispObject modulus(LispObject a, LispObject b);
extern LispObject rational(LispObject a);
extern LispObject rationalize(LispObject a);
extern LispObject lcm(LispObject a, LispObject b);
extern LispObject lengthen_by_one_bit(LispObject a, int32_t msd);
extern CSLbool numeq2(LispObject a, LispObject b);
extern "C" CSLbool zerop(LispObject a);
extern CSLbool onep(LispObject a);
extern CSLbool minusp(LispObject a);
extern CSLbool plusp(LispObject a);
extern CSLbool lesspbd(LispObject a, double b);
extern CSLbool lessprd(LispObject a, double b);
extern CSLbool lesspdb(double a, LispObject b);
extern CSLbool lesspdr(double a, LispObject b);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_two_word_bignum(int32_t a, uint32_t b);
extern LispObject make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern LispObject make_n_word_bignum(int32_t a1, uint32_t a2,
 uint32_t a3, int32_t n);
extern LispObject make_lisp_integer32(int32_t n);
extern LispObject make_lisp_integer64(int64_t n);
extern LispObject make_sfloat(double d);
extern double float_of_integer(LispObject a);
extern "C" LispObject add1(LispObject p);
extern "C" LispObject sub1(LispObject p);
extern "C" LispObject integerp(LispObject p);
extern double float_of_number(LispObject a);
extern LispObject make_boxfloat(double a, int32_t type);
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
extern CSLbool lesspbi(LispObject a, LispObject b);
extern CSLbool lesspib(LispObject a, LispObject b);
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
extern int karatsuba_parallel;
#ifndef KARATSUBA_PARALLEL_CUTOFF
# define KARATSUBA_PARALLEL_CUTOFF 120
#endif
#endif 
#ifndef KARATSUBA_CUTOFF
#define KARATSUBA_CUTOFF 12
#endif
#endif 
#ifndef header_entries_h
#define header_entries_h 1
extern "C" LispObject Lbatchp(LispObject env, int nargs, ...);
extern "C" LispObject bytecounts(LispObject nil, int nargs, ...);
extern "C" LispObject Ldate(LispObject env, int nargs, ...);
extern "C" LispObject Ldatestamp(LispObject nil, int nargs, ...);
extern "C" LispObject Leject(LispObject env, int nargs, ...);
extern "C" LispObject Lerror(LispObject env, int nargs, ...);
extern "C" LispObject Lerror0(LispObject env, int nargs, ...);
extern "C" LispObject Lflush(LispObject nil, int nargs, ...);
extern "C" LispObject Lgc0(LispObject nil, int nargs, ...);
extern "C" LispObject Lgctime(LispObject env, int nargs, ...);
extern "C" LispObject Lgensym(LispObject env, int nargs, ...);
extern "C" LispObject Llist_modules(LispObject env, int nargs, ...);
extern "C" LispObject Llibrary_members0(LispObject env, int nargs, ...);
extern "C" LispObject Llposn(LispObject env, int nargs, ...);
extern "C" LispObject Lmapstore0(LispObject env, int nargs, ...);
extern "C" LispObject Lnext_random(LispObject env, int nargs, ...);
extern "C" LispObject Lposn(LispObject env, int nargs, ...);
extern "C" LispObject Lread(LispObject env, int nargs, ...);
extern "C" LispObject Lreadch(LispObject env, int nargs, ...);
extern "C" LispObject Lrtell(LispObject nil, int nargs, ...);
extern "C" LispObject Lterpri(LispObject env, int nargs, ...);
extern "C" LispObject Ltime(LispObject env, int nargs, ...);
extern "C" LispObject Ltmpnam(LispObject nil, int nargs, ...);
extern "C" LispObject Ltyi(LispObject env, int nargs, ...);
extern "C" LispObject autoload1(LispObject env, LispObject a1);
extern "C" LispObject bytecoded1(LispObject env, LispObject a);
extern "C" LispObject bytecounts1(LispObject env, LispObject a);
extern "C" LispObject byteopt1(LispObject def, LispObject a);
extern "C" LispObject byteoptrest1(LispObject def, LispObject a);
extern "C" LispObject double_bytecoded1(LispObject env, LispObject a);
extern "C" LispObject double_byteopt1(LispObject def, LispObject a);
extern "C" LispObject double_byteoptrest1(LispObject def, LispObject a);
extern "C" LispObject double_funarged1(LispObject env, LispObject a1);
extern "C" LispObject double_hardopt1(LispObject def, LispObject a);
extern "C" LispObject double_hardoptrest1(LispObject def, LispObject a);
extern "C" LispObject double_interpreted1(LispObject env, LispObject a1);
extern "C" LispObject funarged1(LispObject env, LispObject a1);
extern "C" LispObject tracefunarged1(LispObject env, LispObject a1);
extern "C" LispObject tracesetfunarged1(LispObject env, LispObject a1);
extern "C" LispObject hardopt1(LispObject def, LispObject a);
extern "C" LispObject hardoptrest1(LispObject def, LispObject a);
extern "C" LispObject interpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracebytecoded1(LispObject env, LispObject a);
extern "C" LispObject tracesetbytecoded1(LispObject env, LispObject a);
extern "C" LispObject jitcompileme1(LispObject env, LispObject a);
extern "C" LispObject tracebyteopt1(LispObject def, LispObject a);
extern "C" LispObject tracesetbyteopt1(LispObject def, LispObject a);
extern "C" LispObject tracebyteoptrest1(LispObject def, LispObject a);
extern "C" LispObject tracesetbyteoptrest1(LispObject def, LispObject a);
extern "C" LispObject tracebytecoded1(LispObject env, LispObject a);
extern "C" LispObject tracesetbytecoded1(LispObject env, LispObject a);
extern "C" LispObject traceinterpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracesetinterpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracehardopt1(LispObject def, LispObject a);
extern "C" LispObject tracesethardopt1(LispObject def, LispObject a);
extern "C" LispObject tracehardoptrest1(LispObject def, LispObject a);
extern "C" LispObject tracesethardoptrest1(LispObject def, LispObject a);
extern "C" LispObject undefined1(LispObject env, LispObject a1);
extern "C" LispObject f1_as_0(LispObject env, LispObject a);
extern "C" LispObject f1_as_1(LispObject env, LispObject a);
#ifdef CJAVA
extern "C" LispObject java1(LispObject env, LispObject a);
#endif
extern "C" LispObject Labsval(LispObject env, LispObject a);
extern "C" LispObject Ladd1(LispObject env, LispObject a);
extern "C" LispObject Lalpha_char_p(LispObject env, LispObject a);
extern "C" LispObject Lapply0(LispObject env, LispObject a);
extern "C" LispObject Lapply_1(LispObject env, LispObject fn);
extern "C" LispObject Latan(LispObject env, LispObject a);
extern "C" LispObject Latom(LispObject env, LispObject a);
extern "C" LispObject Lbanner(LispObject env, LispObject a);
extern "C" LispObject Lboundp(LispObject env, LispObject a);
extern "C" LispObject Lbpsp(LispObject nil, LispObject a);
extern "C" LispObject Lbpsupbv(LispObject nil, LispObject v);
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
extern "C" LispObject Lerror1(LispObject nil, LispObject a1);
extern "C" LispObject Lerrorset1(LispObject nil, LispObject form);
extern "C" LispObject Leval(LispObject env, LispObject a);
extern "C" LispObject Levenp(LispObject env, LispObject a);
extern "C" LispObject Levlis(LispObject env, LispObject a);
extern "C" LispObject Lexplode(LispObject env, LispObject a);
extern "C" LispObject Lexplode2lc(LispObject env, LispObject a);
extern "C" LispObject Lexplode2lcn(LispObject nil, LispObject a);
extern "C" LispObject Lexplode2n(LispObject env, LispObject a);
extern "C" LispObject Lexplodec(LispObject env, LispObject a);
extern "C" LispObject Lexplodecn(LispObject env, LispObject a);
extern "C" LispObject Lexplodehex(LispObject nil, LispObject a);
extern "C" LispObject Lexploden(LispObject env, LispObject a);
extern "C" LispObject Lexplodeoctal(LispObject nil, LispObject a);
extern "C" LispObject Lfixp(LispObject env, LispObject a);
extern "C" LispObject Lfloat(LispObject env, LispObject a);
extern "C" LispObject Lfloatp(LispObject env, LispObject a);
extern "C" LispObject Lfrexp(LispObject nil, LispObject a);
extern "C" LispObject Lfuncall1(LispObject env, LispObject fn);
extern "C" LispObject Lgc(LispObject nil, LispObject a);
extern "C" LispObject Lgensym1(LispObject env, LispObject a);
extern "C" LispObject Lgensym2(LispObject env, LispObject a);
extern "C" LispObject Lgetd(LispObject env, LispObject a);
extern "C" LispObject Lgetenv(LispObject env, LispObject a);
extern "C" LispObject Lget_bps(LispObject env, LispObject a);
extern "C" LispObject Lhelp(LispObject nil, LispObject a);
extern "C" LispObject Liadd1(LispObject env, LispObject a);
extern "C" LispObject Lidentity(LispObject env, LispObject a);
extern "C" LispObject Liminus(LispObject env, LispObject a);
extern "C" LispObject Liminusp(LispObject env, LispObject a);
extern "C" LispObject Lindirect(LispObject env, LispObject a);
extern "C" LispObject Lintegerp(LispObject env, LispObject a);
extern "C" LispObject Lintern(LispObject env, LispObject a);
extern "C" LispObject Lionep(LispObject nil, LispObject a);
extern "C" LispObject Lisub1(LispObject env, LispObject a);
extern "C" LispObject Lizerop(LispObject nil, LispObject a);
extern "C" LispObject Llength(LispObject env, LispObject a);
extern "C" LispObject Llengthc(LispObject env, LispObject a);
extern "C" LispObject Llibrary_members(LispObject nil, LispObject a);
extern "C" LispObject Llinelength(LispObject env, LispObject a);
extern "C" LispObject Llist_to_string(LispObject env, LispObject a);
extern "C" LispObject Llist_to_vector(LispObject env, LispObject a);
extern "C" LispObject Lload_module(LispObject env, LispObject a);
extern "C" LispObject Lload_source(LispObject env, LispObject a);
extern "C" LispObject Llognot(LispObject env, LispObject a);
extern "C" LispObject Llog_1(LispObject nil, LispObject a);
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
extern "C" LispObject Lmkevect(LispObject nil, LispObject n);
extern "C" LispObject Lmkquote(LispObject env, LispObject a);
extern "C" LispObject Lmkvect(LispObject env, LispObject a);
extern "C" LispObject Lmodular_minus(LispObject env, LispObject a);
extern "C" LispObject Lmodular_number(LispObject env, LispObject a);
extern "C" LispObject Lmodular_reciprocal(LispObject env, LispObject a);
extern "C" LispObject Lmodule_exists(LispObject env, LispObject a);
extern "C" LispObject Lmsd(LispObject env, LispObject a);
extern "C" LispObject Lmv_list(LispObject nil, LispObject a);
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
extern "C" LispObject Lprin2a(LispObject nil, LispObject a);
extern "C" LispObject Lprinc(LispObject env, LispObject a);
extern "C" LispObject Lprinc(LispObject env, LispObject a);
extern "C" LispObject Lprint(LispObject env, LispObject a);
extern "C" LispObject Lprintc(LispObject env, LispObject a);
extern "C" LispObject Lrandom(LispObject env, LispObject a);
extern "C" LispObject Lrational(LispObject env, LispObject a);
extern "C" LispObject Lrdf1(LispObject env, LispObject a);
extern "C" LispObject Lrds(LispObject env, LispObject a);
extern "C" LispObject Lremd(LispObject env, LispObject a);
extern "C" LispObject Lreverse(LispObject env, LispObject a);
extern "C" LispObject Lsetpchar(LispObject env, LispObject a);
extern "C" LispObject Lset_small_modulus(LispObject env, LispObject a);
extern "C" LispObject Lsmkvect(LispObject env, LispObject a);
extern "C" LispObject Lspecial_char(LispObject env, LispObject a);
extern "C" LispObject Lspecial_form_p(LispObject env, LispObject a);
extern "C" LispObject Lspool(LispObject env, LispObject a);
extern "C" LispObject Lstart_module(LispObject env, LispObject a);
extern "C" LispObject Lstop(LispObject env, LispObject a);
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
extern "C" LispObject Ltraceset(LispObject env, LispObject a);
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
extern "C" LispObject Lwrite_module(LispObject env, LispObject a);
extern "C" LispObject Lwrs(LispObject env, LispObject a);
extern "C" LispObject Lxtab(LispObject env, LispObject a);
extern "C" LispObject Lxtab(LispObject env, LispObject a);
extern "C" LispObject Lzerop(LispObject env, LispObject a);
#ifdef COMMON
extern "C" LispObject Lfind_symbol_1(LispObject nil, LispObject str);
extern "C" LispObject Llistp(LispObject env, LispObject a);
#endif
extern "C" LispObject autoload2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject bytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject byteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject byteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_bytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject double_byteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_byteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_funarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject double_hardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_hardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_interpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject funarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracefunarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracesetfunarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject hardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject hardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject interpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracebyteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracesetbyteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracebyteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracesetbyteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracebytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject tracesetbytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject jitcompileme2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject traceinterpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracesetinterpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracehardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracesethardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracehardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracesethardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject undefined2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject f2_as_0(LispObject env, LispObject a, LispObject b);
extern "C" LispObject f2_as_1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject f2_as_2(LispObject env, LispObject a, LispObject b);
#ifdef CJAVA
extern "C" LispObject java2(LispObject env, LispObject a, LispObject b);
#endif
extern "C" LispObject Lappend(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lapply_2(LispObject env, LispObject fn, LispObject a1);
extern "C" LispObject Lapply1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lash(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lash1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lassoc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan2d(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latsoc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lbpsgetv(LispObject nil, LispObject v, LispObject n);
extern "C" LispObject Lcons(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lcopy_native(LispObject env, LispObject a, LispObject b);
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
extern "C" LispObject Lerror2(LispObject nil, LispObject a1, LispObject a2);
extern "C" LispObject Lerrorset2(LispObject nil, LispObject form, LispObject ffg1);
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
extern "C" LispObject Lhelp_2(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lidifference(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ligeq(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Ligreaterp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lileq(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lilessp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Limax(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Limin(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Linorm(LispObject nil, LispObject a, LispObject k);
extern "C" LispObject Linstate_c_code(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lintersect(LispObject nil, LispObject a, LispObject b);
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
extern "C" LispObject Llog_2(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmake_random_state(LispObject nil, LispObject a, LispObject b);
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
extern "C" LispObject Lpair(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lplus2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lquotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrem(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lremflag(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lremprop(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lresource_limit2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrplaca(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrplacd(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrseek(LispObject nil, LispObject a);
extern "C" LispObject Lset(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lset_help_file(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lsgetv(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsmemq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsubla(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsublis(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_protect(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_set_definition(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_set_env(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lthrow_one_value(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ltimes2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunion(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lwrite_help_module(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lxcons(LispObject env, LispObject a, LispObject b);
#ifdef COMMON
extern "C" LispObject Laref2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lfloat_2(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lintern_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmacroexpand_1_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmacroexpand_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrandom_2(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Ltruncate_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunintern_2(LispObject env, LispObject a, LispObject b);
#endif
extern "C" LispObject autoloadn(LispObject env, int nargs, ...);
extern "C" LispObject bytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject bytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject bytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject byteoptn(LispObject def, int nargs, ...);
extern "C" LispObject byteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject double_bytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject double_bytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject double_bytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject double_byteoptn(LispObject def, int nargs, ...);
extern "C" LispObject double_byteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject double_funargedn(LispObject env, int nargs, ...);
extern "C" LispObject double_hardoptn(LispObject def, int nargs, ...);
extern "C" LispObject double_hardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject double_interpretedn(LispObject env, int nargs, ...);
extern "C" LispObject funargedn(LispObject env, int nargs, ...);
extern "C" LispObject tracefunargedn(LispObject env, int nargs, ...);
extern "C" LispObject tracesetfunargedn(LispObject env, int nargs, ...);
extern "C" LispObject hardoptn(LispObject def, int nargs, ...);
extern "C" LispObject hardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject interpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracebyteoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracesetbyteoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracebyteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject tracesetbyteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject tracebytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject tracesetbytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject tracebytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject tracesetbytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject tracebytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject tracesetbytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject jitcompileme0(LispObject env, int nargs, ...);
extern "C" LispObject jitcompileme3(LispObject env, int nargs, ...);
extern "C" LispObject jitcompilemen(LispObject env, int nargs, ...);
extern "C" LispObject traceinterpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracesetinterpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracehardoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracesethardoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracehardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject tracesethardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject undefinedn(LispObject env, int nargs, ...);
extern "C" LispObject f0_as_0(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_0(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_1(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_2(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_3(LispObject env, int nargs, ...);
#ifdef CJAVA
extern "C" LispObject java0(LispObject env, int nargs, ...);
extern "C" LispObject java3(LispObject env, int nargs, ...);
extern "C" LispObject javan(LispObject env, int nargs, ...);
#endif
extern "C" LispObject Lacons(LispObject env, int nargs, ...);
extern "C" LispObject Lapply_n(LispObject env, int nargs, ...);
extern "C" LispObject Lapply2(LispObject env, int nargs, ...);
extern "C" LispObject Lapply3(LispObject env, int nargs, ...);
extern "C" LispObject Lbpsputv(LispObject env, int nargs, ...);
extern "C" LispObject Lerrorset3(LispObject nil, int nargs, ...);
extern "C" LispObject Lerrorsetn(LispObject env, int nargs, ...);
extern "C" LispObject Lfuncalln(LispObject env, int nargs, ...);
extern "C" LispObject Lhelp_n(LispObject nil, int nargs, ...);
extern "C" LispObject Llist(LispObject env, int nargs, ...);
extern "C" LispObject Llist2star(LispObject env, int nargs, ...);
extern "C" LispObject Llist3(LispObject env, int nargs, ...);
extern "C" LispObject Llogand(LispObject env, int nargs, ...);
extern "C" LispObject Llogeqv(LispObject env, int nargs, ...);
extern "C" LispObject Llogor(LispObject env, int nargs, ...);
extern "C" LispObject Llogxor(LispObject env, int nargs, ...);
extern "C" LispObject Lmax(LispObject env, int nargs, ...);
extern "C" LispObject Lmin(LispObject env, int nargs, ...);
extern "C" LispObject Lmkhash(LispObject nil, int nargs, ...);
extern "C" LispObject Lput_hash(LispObject env, int nargs, ...);
extern "C" LispObject Lputprop(LispObject env, int nargs, ...);
extern "C" LispObject Lputv(LispObject env, int nargs, ...);
extern "C" LispObject Lresource_limitn(LispObject env, int nargs, ...);
extern "C" LispObject Lsputv(LispObject env, int nargs, ...);
extern "C" LispObject Lsubst(LispObject env, int nargs, ...);
extern "C" LispObject Lvalues(LispObject env, int nargs, ...);
#ifdef COMMON
extern "C" LispObject Lappend_n(LispObject nil, int nargs, ...);
extern "C" LispObject Laref(LispObject env, int nargs, ...);
extern "C" LispObject Laset(LispObject env, int nargs, ...);
extern "C" LispObject Leqn_n(LispObject nil, int nargs, ...);
extern "C" LispObject Lgcd_n(LispObject env, int nargs, ...);
extern "C" LispObject Lgeq_n(LispObject nil, int nargs, ...);
extern "C" LispObject Lget_3(LispObject env, int nargs, ...);
extern "C" LispObject Lgreaterp_n(LispObject nil, int nargs, ...);
extern "C" LispObject Llcm_n(LispObject env, int nargs, ...);
extern "C" LispObject Lleq_n(LispObject nil, int nargs, ...);
extern "C" LispObject Llessp_n(LispObject nil, int nargs, ...);
extern "C" LispObject Lquotient_n(LispObject nil, int nargs, ...);
#endif
#ifdef OPENMATH
extern "C" LispObject om_openFileDev(LispObject env, int nargs, ...);
extern "C" LispObject om_openStringDev(LispObject nil, LispObject lstr, LispObject lenc);
extern "C" LispObject om_closeDev(LispObject env, LispObject dev);
extern "C" LispObject om_setDevEncoding(LispObject nil, LispObject ldev, LispObject lenc);
extern "C" LispObject om_makeConn(LispObject nil, LispObject ltimeout);
extern "C" LispObject om_closeConn(LispObject nil, LispObject lconn);
extern "C" LispObject om_getConnInDevice(LispObject nil, LispObject lconn);
extern "C" LispObject om_getConnOutDevice(LispObject nil, LispObject lconn);
extern "C" LispObject om_connectTCP(LispObject nil, int nargs, ...);
extern "C" LispObject om_bindTCP(LispObject nil, LispObject lconn, LispObject lport);
extern "C" LispObject om_putApp(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndApp(LispObject nil, LispObject ldev);
extern "C" LispObject om_putAtp(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndAtp(LispObject nil, LispObject ldev);
extern "C" LispObject om_putAttr(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndAttr(LispObject nil, LispObject ldev);
extern "C" LispObject om_putBind(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndBind(LispObject nil, LispObject ldev);
extern "C" LispObject om_putBVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndBVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_putError(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndError(LispObject nil, LispObject ldev);
extern "C" LispObject om_putObject(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndObject(LispObject nil, LispObject ldev);
extern "C" LispObject om_putInt(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putFloat(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putByteArray(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putVar(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putString(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putSymbol(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putSymbol2(LispObject nil, int nargs, ...);
extern "C" LispObject om_getApp(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndApp(LispObject nil, LispObject ldev);
extern "C" LispObject om_getAtp(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndAtp(LispObject nil, LispObject ldev);
extern "C" LispObject om_getAttr(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndAttr(LispObject nil, LispObject ldev);
extern "C" LispObject om_getBind(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndBind(LispObject nil, LispObject ldev);
extern "C" LispObject om_getBVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndBVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_getError(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndError(LispObject nil, LispObject ldev);
extern "C" LispObject om_getObject(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndObject(LispObject nil, LispObject ldev);
extern "C" LispObject om_getInt(LispObject nil, LispObject ldev);
extern "C" LispObject om_getFloat(LispObject nil, LispObject ldev);
extern "C" LispObject om_getByteArray(LispObject nil, LispObject ldev);
extern "C" LispObject om_getVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_getString(LispObject nil, LispObject ldev);
extern "C" LispObject om_getSymbol(LispObject nil, LispObject ldev);
extern "C" LispObject om_getType(LispObject nil, LispObject ldev);
extern "C" LispObject om_stringToStringPtr(LispObject nil, LispObject lstr);
extern "C" LispObject om_stringPtrToString(LispObject nil, LispObject lpstr);
extern "C" LispObject om_read(LispObject nil, LispObject dev);
extern "C" LispObject om_supportsCD(LispObject nil, LispObject lcd);
extern "C" LispObject om_supportsSymbol(LispObject nil, LispObject lcd, LispObject lsym);
extern "C" LispObject om_listCDs(LispObject nil, int nargs, ...);
extern "C" LispObject om_listSymbols(LispObject nil, LispObject lcd);
extern "C" LispObject om_whichCDs(LispObject nil, LispObject lsym);
#endif
#endif 



// Code for !:zerop

static LispObject CC_Tzerop(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0006, v0007, v0008;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :zerop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0008 = v0000;
// end of prologue
    v0006 = v0008;
    if (v0006 == nil) goto v0009;
    v0007 = v0008;
    v0006 = (LispObject)1; // 0
    v0006 = (v0007 == v0006 ? lisp_true : nil);
    goto v0010;

v0010:
    if (v0006 == nil) goto v0011;
    v0006 = qvalue(elt(env, 1)); // t
    return onevalue(v0006);

v0011:
    v0006 = v0008;
    if (!consp(v0006)) goto v0012;
    v0006 = v0008;
    v0006 = qcar(v0006);
    if (!symbolp(v0006)) v0006 = nil;
    else { v0006 = qfastgets(v0006);
           if (v0006 != nil) { v0006 = elt(v0006, 15); // zerop
#ifdef RECORD_GET
             if (v0006 != SPID_NOPROP)
                record_get(elt(fastget_names, 15), 1);
             else record_get(elt(fastget_names, 15), 0),
                v0006 = nil; }
           else record_get(elt(fastget_names, 15), 0); }
#else
             if (v0006 == SPID_NOPROP) v0006 = nil; }}
#endif
    v0007 = v0008;
        return Lapply1(nil, v0006, v0007);

v0012:
    v0006 = qvalue(elt(env, 2)); // nil
    return onevalue(v0006);

v0009:
    v0006 = qvalue(elt(env, 1)); // t
    goto v0010;
}



// Code for evcompless!?

static LispObject CC_evcomplessW(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0017, v0004;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evcompless?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0004 = v0013;
    v0017 = v0000;
// end of prologue
    stack[0] = (LispObject)17; // 1
    fn = elt(env, 1); // evcomp
    v0017 = (*qfn2(fn))(qenv(fn), v0004, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    v0017 = (stack[0] == v0017 ? lisp_true : nil);
    { popv(1); return onevalue(v0017); }
// error exit handlers
v0018:
    popv(1);
    return nil;
}



// Code for rd!:zerop

static LispObject CC_rdTzerop(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0012, v0019;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:zerop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0012 = v0000;
// end of prologue
    v0019 = v0012;
    v0019 = qcdr(v0019);
    if (!consp(v0019)) goto v0020;
    v0012 = qcdr(v0012);
    v0019 = qcar(v0012);
    v0012 = (LispObject)1; // 0
    v0012 = (v0019 == v0012 ? lisp_true : nil);
    return onevalue(v0012);

v0020:
    v0012 = qcdr(v0012);
        return Lzerop(nil, v0012);
}



// Code for wedgepf2

static LispObject CC_wedgepf2(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0030, v0031;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wedgepf2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0013;
    stack[-2] = v0000;
// end of prologue
    v0030 = stack[-2];
    if (v0030 == nil) goto v0014;
    v0030 = stack[-1];
    v0030 = (v0030 == nil ? lisp_true : nil);
    goto v0009;

v0009:
    if (v0030 == nil) goto v0032;
    v0030 = qvalue(elt(env, 2)); // nil
    { popv(5); return onevalue(v0030); }

v0032:
    v0030 = stack[-2];
    v0031 = qcar(v0030);
    v0030 = stack[-1];
    v0030 = qcar(v0030);
    fn = elt(env, 3); // wedget2
    stack[-3] = (*qfn2(fn))(qenv(fn), v0031, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-4];
    v0030 = stack[-2];
    v0030 = qcar(v0030);
    v0031 = ncons(v0030);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-4];
    v0030 = stack[-1];
    v0030 = qcdr(v0030);
    stack[0] = CC_wedgepf2(env, v0031, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-4];
    v0030 = stack[-2];
    v0031 = qcdr(v0030);
    v0030 = stack[-1];
    v0030 = CC_wedgepf2(env, v0031, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-4];
    fn = elt(env, 4); // addpf
    v0030 = (*qfn2(fn))(qenv(fn), stack[0], v0030);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-4];
    {
        LispObject v0034 = stack[-3];
        popv(5);
        fn = elt(env, 4); // addpf
        return (*qfn2(fn))(qenv(fn), v0034, v0030);
    }

v0014:
    v0030 = qvalue(elt(env, 1)); // t
    goto v0009;
// error exit handlers
v0033:
    popv(5);
    return nil;
}



// Code for !*physopp!*

static LispObject CC_HphysoppH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0014;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *physopp*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0014 = stack[0];
    fn = elt(env, 1); // physopp!*
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-1];
    if (!(v0014 == nil)) { popv(2); return onevalue(v0014); }
    v0014 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // getphystype
        return (*qfn1(fn))(qenv(fn), v0014);
    }
// error exit handlers
v0035:
    popv(2);
    return nil;
}



// Code for union_edges

static LispObject CC_union_edges(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0032, v0038, v0039;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for union_edges");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0032 = v0013;
    v0038 = v0000;
// end of prologue

v0003:
    v0039 = v0038;
    if (v0039 == nil) { popv(2); return onevalue(v0032); }
    v0039 = v0038;
    v0039 = qcdr(v0039);
    stack[0] = v0039;
    v0038 = qcar(v0038);
    fn = elt(env, 1); // union_edge
    v0032 = (*qfn2(fn))(qenv(fn), v0038, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-1];
    v0038 = stack[0];
    goto v0003;
// error exit handlers
v0040:
    popv(2);
    return nil;
}



// Code for errorp

static LispObject CC_errorp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0041, v0042;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for errorp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0042 = v0000;
// end of prologue
    v0041 = v0042;
    if (!consp(v0041)) goto v0020;
    v0041 = v0042;
    v0041 = qcdr(v0041);
    return onevalue(v0041);

v0020:
    v0041 = qvalue(elt(env, 1)); // t
    return onevalue(v0041);
}



// Code for cdiv

static LispObject CC_cdiv(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0042, v0044;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cdiv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0042 = v0013;
    v0044 = v0000;
// end of prologue
    v0042 = cons(v0044, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[0];
    fn = elt(env, 1); // resimp
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    v0042 = qcar(v0042);
    { popv(1); return onevalue(v0042); }
// error exit handlers
v0015:
    popv(1);
    return nil;
}



// Code for add_prin_char

static LispObject CC_add_prin_char(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0049, v0050, v0025;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add_prin_char");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0013;
    stack[-1] = v0000;
// end of prologue
    v0049 = qvalue(elt(env, 1)); // !*nat
    if (v0049 == nil) goto v0011;
    v0025 = qvalue(elt(env, 2)); // posn!*
    v0050 = stack[0];
    v0049 = qvalue(elt(env, 3)); // ycoord!*
    v0025 = acons(v0025, v0050, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-2];
    v0050 = stack[-1];
    v0049 = qvalue(elt(env, 4)); // pline!*
    v0049 = acons(v0025, v0050, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0049; // pline!*
    v0049 = stack[0];
    qvalue(elt(env, 2)) = v0049; // posn!*
    { popv(3); return onevalue(v0049); }

v0011:
    v0049 = stack[-1];
    v0049 = Lstringp(nil, v0049);
    env = stack[-2];
    if (!(v0049 == nil)) goto v0043;
    v0049 = stack[-1];
    if (!symbolp(v0049)) v0049 = nil;
    else { v0049 = qfastgets(v0049);
           if (v0049 != nil) { v0049 = elt(v0049, 11); // switch!*
#ifdef RECORD_GET
             if (v0049 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v0049 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v0049 == SPID_NOPROP) v0049 = nil; }}
#endif
    if (!(v0049 == nil)) goto v0043;
    v0049 = stack[-1];
    v0049 = Ldigitp(nil, v0049);
    env = stack[-2];
    if (!(v0049 == nil)) goto v0043;
    v0049 = stack[-1];
    v0049 = Lexplodec(nil, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    v0049 = qcar(v0049);
    if (!symbolp(v0049)) v0049 = nil;
    else { v0049 = qfastgets(v0049);
           if (v0049 != nil) { v0049 = elt(v0049, 11); // switch!*
#ifdef RECORD_GET
             if (v0049 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v0049 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v0049 == SPID_NOPROP) v0049 = nil; }}
#endif
    if (!(v0049 == nil)) goto v0043;
    v0049 = stack[-1];
        popv(3);
        return Lprin(nil, v0049);

v0043:
    v0049 = stack[-1];
        popv(3);
        return Lprinc(nil, v0049);
// error exit handlers
v0031:
    popv(3);
    return nil;
}



// Code for pv_multc

static LispObject CC_pv_multc(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0057, v0058, v0059;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pv_multc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0013;
    stack[-1] = v0000;
// end of prologue
    v0058 = stack[0];
    v0057 = (LispObject)1; // 0
    if (v0058 == v0057) goto v0014;
    v0057 = stack[-1];
    v0057 = (v0057 == nil ? lisp_true : nil);
    goto v0009;

v0009:
    if (v0057 == nil) goto v0021;
    v0057 = qvalue(elt(env, 2)); // nil
    { popv(4); return onevalue(v0057); }

v0021:
    v0058 = stack[0];
    v0057 = (LispObject)17; // 1
    if (v0058 == v0057) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = nil;
    goto v0008;

v0008:
    v0057 = stack[-1];
    if (v0057 == nil) goto v0007;
    v0057 = stack[-1];
    v0057 = qcar(v0057);
    v0058 = qcar(v0057);
    v0057 = (LispObject)1; // 0
    if (v0058 == v0057) goto v0060;
    v0058 = stack[0];
    v0057 = stack[-1];
    v0057 = qcar(v0057);
    v0057 = qcar(v0057);
    v0059 = times2(v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-3];
    v0057 = stack[-1];
    v0057 = qcar(v0057);
    v0058 = qcdr(v0057);
    v0057 = stack[-2];
    v0057 = acons(v0059, v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-3];
    stack[-2] = v0057;
    goto v0060;

v0060:
    v0057 = stack[-1];
    v0057 = qcdr(v0057);
    stack[-1] = v0057;
    goto v0008;

v0007:
    v0057 = stack[-2];
        popv(4);
        return Lnreverse(nil, v0057);

v0014:
    v0057 = qvalue(elt(env, 1)); // t
    goto v0009;
// error exit handlers
v0061:
    popv(4);
    return nil;
}



// Code for upbve

static LispObject CC_upbve(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0044;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for upbve");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0044 = stack[0];
    v0044 = Lupbv(nil, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    if (v0044 == nil) goto v0020;
    v0044 = stack[0];
    v0044 = Lupbv(nil, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    popv(2);
    return add1(v0044);

v0020:
    v0044 = (LispObject)1; // 0
    { popv(2); return onevalue(v0044); }
// error exit handlers
v0016:
    popv(2);
    return nil;
}



// Code for !*i2rn

static LispObject CC_Hi2rn(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0042, v0044, v0015;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *i2rn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0042 = v0000;
// end of prologue
    v0015 = elt(env, 1); // !:rn!:
    v0044 = v0042;
    v0042 = (LispObject)17; // 1
    return list2star(v0015, v0044, v0042);
}



// Code for plus!-mod!-p

static LispObject CC_plusKmodKp(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0091, v0092, v0093;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for plus-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0013;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0009;

v0009:
    v0091 = stack[-1];
    if (v0091 == nil) goto v0041;
    v0091 = stack[0];
    if (v0091 == nil) goto v0016;
    v0091 = stack[-1];
    if (!consp(v0091)) goto v0019;
    v0091 = stack[-1];
    v0091 = qcar(v0091);
    v0091 = (consp(v0091) ? nil : lisp_true);
    goto v0012;

v0012:
    if (v0091 == nil) goto v0018;
    v0091 = stack[0];
    if (!consp(v0091)) goto v0006;
    v0091 = stack[0];
    v0091 = qcar(v0091);
    v0091 = (consp(v0091) ? nil : lisp_true);
    goto v0001;

v0001:
    if (v0091 == nil) goto v0025;
    v0092 = stack[-1];
    v0091 = stack[0];
    {   int32_t w = int_of_fixnum(v0092) + int_of_fixnum(v0091);
        if (w >= current_modulus) w -= current_modulus;
        v0091 = fixnum_of_int(w);
    }
    fn = elt(env, 3); // !*n2f
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0092 = v0091;
    goto v0095;

v0095:
    v0091 = stack[-2];
    if (v0091 == nil) { popv(4); return onevalue(v0092); }
    v0091 = stack[-2];
    v0091 = qcdr(v0091);
    stack[-1] = v0091;
    v0091 = stack[-2];
    v0091 = Lrplacd(nil, v0091, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0091 = stack[-2];
    v0092 = v0091;
    v0091 = stack[-1];
    stack[-2] = v0091;
    goto v0095;

v0025:
    v0091 = stack[0];
    v0092 = qcar(v0091);
    v0091 = stack[-2];
    v0091 = cons(v0092, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    stack[-2] = v0091;
    v0091 = stack[0];
    v0091 = qcdr(v0091);
    stack[0] = v0091;
    goto v0009;

v0006:
    v0091 = qvalue(elt(env, 1)); // t
    goto v0001;

v0018:
    v0091 = stack[0];
    if (!consp(v0091)) goto v0096;
    v0091 = stack[0];
    v0091 = qcar(v0091);
    v0091 = (consp(v0091) ? nil : lisp_true);
    goto v0097;

v0097:
    if (v0091 == nil) goto v0098;
    v0091 = stack[-1];
    v0092 = qcar(v0091);
    v0091 = stack[-2];
    v0091 = cons(v0092, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    stack[-2] = v0091;
    v0091 = stack[-1];
    v0091 = qcdr(v0091);
    stack[-1] = v0091;
    goto v0009;

v0098:
    v0091 = stack[-1];
    v0091 = qcar(v0091);
    v0092 = qcar(v0091);
    v0091 = stack[0];
    v0091 = qcar(v0091);
    v0091 = qcar(v0091);
    if (equal(v0092, v0091)) goto v0099;
    v0091 = stack[-1];
    v0091 = qcar(v0091);
    v0091 = qcar(v0091);
    v0092 = qcar(v0091);
    v0091 = stack[0];
    v0091 = qcar(v0091);
    v0091 = qcar(v0091);
    v0091 = qcar(v0091);
    if (equal(v0092, v0091)) goto v0100;
    v0091 = qvalue(elt(env, 2)); // nil
    goto v0101;

v0101:
    if (!(v0091 == nil)) goto v0102;
    v0091 = stack[-1];
    v0091 = qcar(v0091);
    v0091 = qcar(v0091);
    v0092 = qcar(v0091);
    v0091 = stack[0];
    v0091 = qcar(v0091);
    v0091 = qcar(v0091);
    v0091 = qcar(v0091);
    if (equal(v0092, v0091)) goto v0103;
    v0091 = stack[-1];
    v0091 = qcar(v0091);
    v0091 = qcar(v0091);
    v0092 = qcar(v0091);
    v0091 = stack[0];
    v0091 = qcar(v0091);
    v0091 = qcar(v0091);
    v0091 = qcar(v0091);
    fn = elt(env, 4); // ordop
    v0091 = (*qfn2(fn))(qenv(fn), v0092, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    goto v0104;

v0104:
    if (!(v0091 == nil)) goto v0102;
    v0091 = stack[0];
    v0092 = qcar(v0091);
    v0091 = stack[-2];
    v0091 = cons(v0092, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    stack[-2] = v0091;
    v0091 = stack[0];
    v0091 = qcdr(v0091);
    stack[0] = v0091;
    goto v0009;

v0102:
    v0091 = stack[-1];
    v0092 = qcar(v0091);
    v0091 = stack[-2];
    v0091 = cons(v0092, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    stack[-2] = v0091;
    v0091 = stack[-1];
    v0091 = qcdr(v0091);
    stack[-1] = v0091;
    goto v0009;

v0103:
    v0091 = qvalue(elt(env, 2)); // nil
    goto v0104;

v0100:
    v0091 = stack[-1];
    v0091 = qcar(v0091);
    v0091 = qcar(v0091);
    v0092 = qcdr(v0091);
    v0091 = stack[0];
    v0091 = qcar(v0091);
    v0091 = qcar(v0091);
    v0091 = qcdr(v0091);
    v0091 = ((intptr_t)v0092 > (intptr_t)v0091) ? lisp_true : nil;
    goto v0101;

v0099:
    v0091 = stack[-1];
    v0091 = qcar(v0091);
    v0092 = qcdr(v0091);
    v0091 = stack[0];
    v0091 = qcar(v0091);
    v0091 = qcdr(v0091);
    v0091 = CC_plusKmodKp(env, v0092, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0092 = v0091;
    if (v0092 == nil) goto v0105;
    v0092 = stack[-1];
    v0092 = qcar(v0092);
    v0093 = qcar(v0092);
    v0092 = v0091;
    v0091 = stack[-2];
    v0091 = acons(v0093, v0092, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    stack[-2] = v0091;
    goto v0105;

v0105:
    v0091 = stack[-1];
    v0091 = qcdr(v0091);
    stack[-1] = v0091;
    v0091 = stack[0];
    v0091 = qcdr(v0091);
    stack[0] = v0091;
    goto v0009;

v0096:
    v0091 = qvalue(elt(env, 1)); // t
    goto v0097;

v0019:
    v0091 = qvalue(elt(env, 1)); // t
    goto v0012;

v0016:
    v0091 = stack[-1];
    v0092 = v0091;
    goto v0095;

v0041:
    v0091 = stack[0];
    v0092 = v0091;
    goto v0095;
// error exit handlers
v0094:
    popv(4);
    return nil;
}



// Code for striptag

static LispObject CC_striptag(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0041, v0042;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for striptag");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0041 = v0000;
// end of prologue
    v0042 = v0041;
    if (!consp(v0042)) return onevalue(v0041);
    v0041 = qcdr(v0041);
    return onevalue(v0041);
}



// Code for lalr_same_core

static LispObject CC_lalr_same_core(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0042;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_same_core");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0013;
    v0042 = v0000;
// end of prologue
    fn = elt(env, 1); // lalr_core
    stack[-1] = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-2];
    v0042 = stack[0];
    fn = elt(env, 1); // lalr_core
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    v0042 = (equal(stack[-1], v0042) ? lisp_true : nil);
    { popv(3); return onevalue(v0042); }
// error exit handlers
v0016:
    popv(3);
    return nil;
}



// Code for toknump

static LispObject CC_toknump(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0106, v0040, v0055;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for toknump");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0055 = v0000;
// end of prologue
    v0106 = v0055;
    v0106 = (is_number(v0106) ? lisp_true : nil);
    if (!(v0106 == nil)) return onevalue(v0106);
    v0040 = v0055;
    v0106 = elt(env, 1); // !:dn!:
    if (!consp(v0040)) goto v0012;
    v0040 = qcar(v0040);
    if (!(v0040 == v0106)) goto v0012;
    v0106 = qvalue(elt(env, 2)); // t
    return onevalue(v0106);

v0012:
    v0106 = v0055;
    v0040 = elt(env, 3); // !:int!:
        return Leqcar(nil, v0106, v0040);
}



// Code for rl_smcpknowl

static LispObject CC_rl_smcpknowl(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0035;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_smcpknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0035 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_smcpknowl!*
    v0035 = ncons(v0035);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    {
        LispObject v0044 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0044, v0035);
    }
// error exit handlers
v0042:
    popv(2);
    return nil;
}



// Code for symbollessp

static LispObject CC_symbollessp(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0002, v0022, v0089;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for symbollessp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0022 = v0013;
    v0089 = v0000;
// end of prologue
    v0002 = v0022;
    if (v0002 == nil) goto v0011;
    v0002 = v0089;
    if (v0002 == nil) goto v0014;
    v0002 = qvalue(elt(env, 3)); // wukord!*
    if (v0002 == nil) goto v0032;
    v0002 = v0089;
    {
        fn = elt(env, 4); // wuorderp
        return (*qfn2(fn))(qenv(fn), v0002, v0022);
    }

v0032:
    v0002 = v0089;
    v0002 = Lorderp(nil, v0002, v0022);
    errexit();
    v0002 = (v0002 == nil ? lisp_true : nil);
    return onevalue(v0002);

v0014:
    v0002 = qvalue(elt(env, 2)); // t
    return onevalue(v0002);

v0011:
    v0002 = qvalue(elt(env, 1)); // nil
    return onevalue(v0002);
}



// Code for lt!*

static LispObject CC_ltH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0109, v0110, v0086;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lt*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0000;
// end of prologue
    v0109 = qvalue(elt(env, 1)); // !*mcd
    if (!(v0109 == nil)) goto v0020;
    v0109 = stack[-1];
    v0109 = qcar(v0109);
    v0109 = qcar(v0109);
    v0110 = qcdr(v0109);
    v0109 = (LispObject)1; // 0
    v0109 = (LispObject)greaterp2(v0110, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    v0109 = v0109 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0109 == nil)) goto v0020;
    v0109 = stack[-1];
    v0109 = qcar(v0109);
    stack[-2] = v0109;
    v0109 = stack[-1];
    v0109 = qcar(v0109);
    v0109 = qcar(v0109);
    v0109 = qcar(v0109);
    stack[0] = v0109;
    goto v0038;

v0038:
    v0109 = stack[-1];
    v0109 = qcdr(v0109);
    stack[-1] = v0109;
    v0109 = stack[-1];
    if (v0109 == nil) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0110 = stack[-1];
    v0109 = stack[0];
    fn = elt(env, 2); // degr
    v0110 = (*qfn2(fn))(qenv(fn), v0110, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-3];
    v0109 = (LispObject)1; // 0
    if (!(v0110 == v0109)) goto v0038;
    v0086 = stack[0];
    v0110 = (LispObject)1; // 0
    v0109 = stack[-1];
    popv(4);
    return acons(v0086, v0110, v0109);

v0020:
    v0109 = stack[-1];
    v0109 = qcar(v0109);
    { popv(4); return onevalue(v0109); }
// error exit handlers
v0111:
    popv(4);
    return nil;
}



// Code for nocp

static LispObject CC_nocp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0019;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nocp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue

v0112:
    v0019 = stack[0];
    if (v0019 == nil) goto v0020;
    v0019 = stack[0];
    v0019 = qcar(v0019);
    v0019 = qcar(v0019);
    fn = elt(env, 3); // noncomp
    v0019 = (*qfn1(fn))(qenv(fn), v0019);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-1];
    if (v0019 == nil) goto v0041;
    v0019 = stack[0];
    v0019 = qcdr(v0019);
    stack[0] = v0019;
    goto v0112;

v0041:
    v0019 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0019); }

v0020:
    v0019 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0019); }
// error exit handlers
v0021:
    popv(2);
    return nil;
}



// Code for subs2f

static LispObject CC_subs2f(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0051, v0052, v0114;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subs2f");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0052 = qvalue(elt(env, 1)); // simpcount!*
    v0051 = qvalue(elt(env, 2)); // simplimit!*
    v0051 = (LispObject)greaterp2(v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    v0051 = v0051 ? lisp_true : nil;
    env = stack[-2];
    if (v0051 == nil) goto v0003;
    v0051 = (LispObject)1; // 0
    qvalue(elt(env, 1)) = v0051; // simpcount!*
    v0114 = elt(env, 3); // poly
    v0052 = (LispObject)337; // 21
    v0051 = elt(env, 4); // "Simplification recursion too deep"
    fn = elt(env, 9); // rerror
    v0051 = (*qfnn(fn))(qenv(fn), 3, v0114, v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-2];
    goto v0003;

v0003:
    v0051 = qvalue(elt(env, 1)); // simpcount!*
    v0051 = add1(v0051);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0051; // simpcount!*
    v0051 = qvalue(elt(env, 5)); // nil
    qvalue(elt(env, 6)) = v0051; // !*sub2
    v0051 = stack[0];
    fn = elt(env, 10); // subs2f1
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-2];
    stack[-1] = v0051;
    v0051 = qvalue(elt(env, 6)); // !*sub2
    if (!(v0051 == nil)) goto v0001;
    v0051 = qvalue(elt(env, 7)); // powlis1!*
    if (!(v0051 == nil)) goto v0001;

v0002:
    v0051 = qvalue(elt(env, 1)); // simpcount!*
    v0051 = sub1(v0051);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0051; // simpcount!*
    { LispObject res = stack[-1]; popv(3); return onevalue(res); }

v0001:
    v0051 = qvalue(elt(env, 8)); // !*resubs
    if (v0051 == nil) goto v0002;
    v0051 = stack[-1];
    v0052 = qcar(v0051);
    v0051 = stack[0];
    if (equal(v0052, v0051)) goto v0026;
    v0051 = qvalue(elt(env, 5)); // nil
    goto v0107;

v0107:
    if (v0051 == nil) goto v0096;
    v0051 = qvalue(elt(env, 5)); // nil
    qvalue(elt(env, 6)) = v0051; // !*sub2
    goto v0002;

v0096:
    v0051 = stack[-1];
    fn = elt(env, 11); // subs2q
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-2];
    stack[-1] = v0051;
    goto v0002;

v0026:
    v0051 = stack[-1];
    v0052 = qcdr(v0051);
    v0051 = (LispObject)17; // 1
    v0051 = (v0052 == v0051 ? lisp_true : nil);
    goto v0107;
// error exit handlers
v0115:
    popv(3);
    return nil;
}



// Code for gcdfd

static LispObject CC_gcdfd(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0005, v0018, v0090;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdfd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0018 = v0013;
    v0090 = v0000;
// end of prologue
    v0005 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v0005)) v0005 = nil;
    else { v0005 = qfastgets(v0005);
           if (v0005 != nil) { v0005 = elt(v0005, 3); // field
#ifdef RECORD_GET
             if (v0005 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0005 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0005 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0005 == SPID_NOPROP) v0005 = nil; else v0005 = lisp_true; }}
#endif
    if (v0005 == nil) goto v0042;
    v0005 = (LispObject)17; // 1
    return onevalue(v0005);

v0042:
    v0005 = v0090;
    {
        fn = elt(env, 2); // gcdfd1
        return (*qfn2(fn))(qenv(fn), v0005, v0018);
    }
}



// Code for printout

static LispObject CC_printout(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0052, v0114;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for printout");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0052 = qvalue(elt(env, 1)); // !*web
    if (!(v0052 == nil)) goto v0011;
    v0052 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-2];
    goto v0011;

v0011:
    v0052 = qvalue(elt(env, 1)); // !*web
    if (!(v0052 == nil)) goto v0035;
    v0052 = (LispObject)17; // 1
    stack[-1] = v0052;
    goto v0021;

v0021:
    v0114 = qvalue(elt(env, 2)); // indent
    v0052 = stack[-1];
    v0052 = difference2(v0114, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-2];
    v0052 = Lminusp(nil, v0052);
    env = stack[-2];
    if (!(v0052 == nil)) goto v0035;
    v0052 = elt(env, 4); // " "
    v0052 = Lprinc(nil, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-2];
    v0052 = stack[-1];
    v0052 = add1(v0052);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-2];
    stack[-1] = v0052;
    goto v0021;

v0035:
    v0052 = stack[0];
    v0052 = Lconsp(nil, v0052);
    env = stack[-2];
    if (v0052 == nil) goto v0054;
    v0052 = stack[0];
    v0114 = qcar(v0052);
    v0052 = elt(env, 5); // !:rd!:
    if (v0114 == v0052) goto v0107;
    v0052 = stack[0];
    v0114 = qcar(v0052);
    v0052 = elt(env, 7); // !:rn!:
    v0052 = (v0114 == v0052 ? lisp_true : nil);
    goto v0060;

v0060:
    if (v0052 == nil) goto v0096;
    v0052 = stack[0];
    fn = elt(env, 8); // ma_print
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    goto v0006;

v0006:
    v0052 = nil;
    { popv(3); return onevalue(v0052); }

v0096:
    v0052 = stack[0];
    v0052 = Lprinc(nil, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    goto v0006;

v0107:
    v0052 = qvalue(elt(env, 6)); // t
    goto v0060;

v0054:
    v0052 = stack[0];
    v0052 = Lprinc(nil, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    goto v0006;
// error exit handlers
v0115:
    popv(3);
    return nil;
}



// Code for initcomb

static LispObject CC_initcomb(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0020;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for initcomb");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0020 = v0000;
// end of prologue
    return ncons(v0020);
}



// Code for evmatrixcomp

static LispObject CC_evmatrixcomp(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0044, v0015, v0016;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evmatrixcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0044 = v0013;
    v0015 = v0000;
// end of prologue
    v0016 = v0015;
    v0015 = v0044;
    v0044 = qvalue(elt(env, 1)); // vdpmatrix!*
    {
        fn = elt(env, 2); // evmatrixcomp1
        return (*qfnn(fn))(qenv(fn), 3, v0016, v0015, v0044);
    }
}



// Code for pprin2

static LispObject CC_pprin2(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0090, v0012;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pprin2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0012 = stack[0];
    v0090 = qvalue(elt(env, 1)); // !*pprinbuf!*
    v0090 = cons(v0012, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0090; // !*pprinbuf!*
    stack[-1] = qvalue(elt(env, 2)); // !*posn!*
    v0090 = stack[0];
    v0090 = Lexplodec(nil, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-2];
    v0090 = Llength(nil, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-2];
    v0090 = plus2(stack[-1], v0090);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-2];
    qvalue(elt(env, 2)) = v0090; // !*posn!*
    v0090 = nil;
    { popv(3); return onevalue(v0090); }
// error exit handlers
v0021:
    popv(3);
    return nil;
}



// Code for opmtch!*

static LispObject CC_opmtchH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0041, v0042;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for opmtch*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0042 = v0000;
// end of prologue
    v0041 = qvalue(elt(env, 1)); // subfg!*
    stack[0] = v0041;
    v0041 = qvalue(elt(env, 2)); // t
    qvalue(elt(env, 1)) = v0041; // subfg!*
    v0041 = v0042;
    fn = elt(env, 3); // opmtch
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-1];
    v0042 = v0041;
    v0041 = stack[0];
    qvalue(elt(env, 1)) = v0041; // subfg!*
    { popv(2); return onevalue(v0042); }
// error exit handlers
v0015:
    popv(2);
    return nil;
}



// Code for timesip

static LispObject CC_timesip(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0021, v0032, v0038;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for timesip");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0038 = v0000;
// end of prologue
    v0032 = v0038;
    v0021 = elt(env, 1); // times
    if (!consp(v0032)) goto v0012;
    v0032 = qcar(v0032);
    if (!(v0032 == v0021)) goto v0012;
    v0021 = elt(env, 2); // i
    v0032 = v0038;
    v0032 = qcdr(v0032);
    v0021 = Lmemq(nil, v0021, v0032);
    return onevalue(v0021);

v0012:
    v0021 = qvalue(elt(env, 3)); // nil
    return onevalue(v0021);
}



// Code for fs!:timestermterm

static LispObject CC_fsTtimestermterm(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0175, v0176, v0177;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:timestermterm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-6] = v0013;
    stack[-7] = v0000;
// end of prologue
    v0175 = (LispObject)113; // 7
    v0175 = Lmkvect(nil, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    stack[-8] = v0175;
    v0176 = stack[-7];
    v0175 = (LispObject)33; // 2
    v0175 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    stack[-4] = v0175;
    v0176 = stack[-6];
    v0175 = (LispObject)33; // 2
    v0175 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    stack[-3] = v0175;
    v0175 = (LispObject)1; // 0
    stack[-2] = v0175;
    goto v0007;

v0007:
    v0176 = (LispObject)113; // 7
    v0175 = stack[-2];
    v0175 = difference2(v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    v0175 = Lminusp(nil, v0175);
    env = stack[-9];
    if (v0175 == nil) goto v0027;
    v0175 = (LispObject)113; // 7
    v0175 = Lmkvect(nil, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    stack[-5] = v0175;
    v0175 = (LispObject)1; // 0
    stack[-2] = v0175;
    goto v0061;

v0061:
    v0176 = (LispObject)113; // 7
    v0175 = stack[-2];
    v0175 = difference2(v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    v0175 = Lminusp(nil, v0175);
    env = stack[-9];
    if (v0175 == nil) goto v0179;
    v0176 = stack[-7];
    v0175 = (LispObject)1; // 0
    v0177 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0176 = stack[-6];
    v0175 = (LispObject)1; // 0
    v0175 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    fn = elt(env, 5); // multsq
    v0175 = (*qfn2(fn))(qenv(fn), v0177, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    stack[0] = v0175;
    v0176 = stack[0];
    v0175 = elt(env, 2); // (1 . 2)
    fn = elt(env, 5); // multsq
    v0175 = (*qfn2(fn))(qenv(fn), v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    stack[0] = v0175;
    v0175 = stack[0];
    v0175 = qcar(v0175);
    if (v0175 == nil) goto v0180;
    v0176 = stack[-7];
    v0175 = (LispObject)17; // 1
    v0176 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0175 = elt(env, 3); // sin
    if (v0176 == v0175) goto v0181;
    v0176 = stack[-6];
    v0175 = (LispObject)17; // 1
    v0176 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0175 = elt(env, 3); // sin
    if (v0176 == v0175) goto v0182;
    v0177 = elt(env, 4); // cos
    v0176 = stack[-8];
    v0175 = stack[0];
    fn = elt(env, 6); // make!-term
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v0177, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    v0177 = elt(env, 4); // cos
    v0176 = stack[-5];
    v0175 = stack[0];
    fn = elt(env, 6); // make!-term
    v0175 = (*qfnn(fn))(qenv(fn), 3, v0177, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    {
        LispObject v0183 = stack[-1];
        popv(10);
        fn = elt(env, 7); // fs!:plus
        return (*qfn2(fn))(qenv(fn), v0183, v0175);
    }

v0182:
    v0177 = elt(env, 3); // sin
    v0176 = stack[-8];
    v0175 = stack[0];
    fn = elt(env, 6); // make!-term
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v0177, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    stack[-1] = elt(env, 3); // sin
    stack[-3] = stack[-5];
    v0175 = stack[0];
    fn = elt(env, 8); // negsq
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    fn = elt(env, 6); // make!-term
    v0175 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-3], v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    {
        LispObject v0184 = stack[-2];
        popv(10);
        fn = elt(env, 7); // fs!:plus
        return (*qfn2(fn))(qenv(fn), v0184, v0175);
    }

v0181:
    v0176 = stack[-6];
    v0175 = (LispObject)17; // 1
    v0176 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0175 = elt(env, 3); // sin
    if (v0176 == v0175) goto v0185;
    v0177 = elt(env, 3); // sin
    v0176 = stack[-8];
    v0175 = stack[0];
    fn = elt(env, 6); // make!-term
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v0177, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    v0177 = elt(env, 3); // sin
    v0176 = stack[-5];
    v0175 = stack[0];
    fn = elt(env, 6); // make!-term
    v0175 = (*qfnn(fn))(qenv(fn), 3, v0177, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    {
        LispObject v0186 = stack[-1];
        popv(10);
        fn = elt(env, 7); // fs!:plus
        return (*qfn2(fn))(qenv(fn), v0186, v0175);
    }

v0185:
    stack[-1] = elt(env, 4); // cos
    stack[-2] = stack[-8];
    v0175 = stack[0];
    fn = elt(env, 8); // negsq
    v0175 = (*qfn1(fn))(qenv(fn), v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    fn = elt(env, 6); // make!-term
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-2], v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    v0177 = elt(env, 4); // cos
    v0176 = stack[-5];
    v0175 = stack[0];
    fn = elt(env, 6); // make!-term
    v0175 = (*qfnn(fn))(qenv(fn), 3, v0177, v0176, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    {
        LispObject v0187 = stack[-1];
        popv(10);
        fn = elt(env, 7); // fs!:plus
        return (*qfn2(fn))(qenv(fn), v0187, v0175);
    }

v0180:
    v0175 = qvalue(elt(env, 1)); // nil
    { popv(10); return onevalue(v0175); }

v0179:
    stack[-1] = stack[-5];
    stack[0] = stack[-2];
    v0176 = stack[-4];
    v0175 = stack[-2];
    v0177 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0176 = stack[-3];
    v0175 = stack[-2];
    v0175 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0175 = difference2(v0177, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0175;
    v0175 = stack[-2];
    v0175 = add1(v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    stack[-2] = v0175;
    goto v0061;

v0027:
    stack[-1] = stack[-8];
    stack[0] = stack[-2];
    v0176 = stack[-4];
    v0175 = stack[-2];
    v0177 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0176 = stack[-3];
    v0175 = stack[-2];
    v0175 = *(LispObject *)((char *)v0176 + (CELL-TAG_VECTOR) + ((int32_t)v0175/(16/CELL)));
    v0175 = plus2(v0177, v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0175;
    v0175 = stack[-2];
    v0175 = add1(v0175);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-9];
    stack[-2] = v0175;
    goto v0007;
// error exit handlers
v0178:
    popv(10);
    return nil;
}



// Code for mo_vdivides!?

static LispObject CC_mo_vdividesW(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0038, v0039;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_vdivides?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0013;
    stack[-1] = v0000;
// end of prologue
    v0038 = stack[-1];
    fn = elt(env, 2); // mo_comp
    stack[-2] = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    v0038 = stack[0];
    fn = elt(env, 2); // mo_comp
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    v0038 = Leqn(nil, stack[-2], v0038);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-3];
    if (v0038 == nil) goto v0011;
    v0039 = stack[-1];
    v0038 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); // mo_divides!?
        return (*qfn2(fn))(qenv(fn), v0039, v0038);
    }

v0011:
    v0038 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0038); }
// error exit handlers
v0029:
    popv(4);
    return nil;
}



// Code for dless

static LispObject CC_dless(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0115, v0190, v0057;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dless");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0057 = v0013;
    stack[0] = v0000;
// end of prologue
    v0190 = qvalue(elt(env, 1)); // ordering
    v0115 = elt(env, 2); // lex
    if (v0190 == v0115) goto v0015;
    v0115 = stack[0];
    v0190 = qcar(v0115);
    v0115 = v0057;
    v0115 = qcar(v0115);
    if (((int32_t)(v0190)) < ((int32_t)(v0115))) goto v0090;
    v0115 = stack[0];
    v0190 = qcar(v0115);
    v0115 = v0057;
    v0115 = qcar(v0115);
    if (((int32_t)(v0190)) > ((int32_t)(v0115))) goto v0191;
    v0190 = qvalue(elt(env, 1)); // ordering
    v0115 = elt(env, 5); // glex
    if (v0190 == v0115) goto v0046;
    v0190 = qvalue(elt(env, 1)); // ordering
    v0115 = elt(env, 6); // grev
    if (v0190 == v0115) goto v0053;
    v0115 = nil;
    { popv(3); return onevalue(v0115); }

v0053:
    v0115 = v0057;
    v0115 = qcdr(v0115);
    stack[-1] = Lreverse(nil, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-2];
    v0115 = stack[0];
    v0115 = qcdr(v0115);
    v0115 = Lreverse(nil, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-2];
    {
        LispObject v0192 = stack[-1];
        popv(3);
        fn = elt(env, 7); // dlesslex
        return (*qfn2(fn))(qenv(fn), v0192, v0115);
    }

v0046:
    v0115 = stack[0];
    v0115 = qcdr(v0115);
    v0190 = v0057;
    v0190 = qcdr(v0190);
    {
        popv(3);
        fn = elt(env, 7); // dlesslex
        return (*qfn2(fn))(qenv(fn), v0115, v0190);
    }

v0191:
    v0115 = qvalue(elt(env, 4)); // nil
    { popv(3); return onevalue(v0115); }

v0090:
    v0115 = qvalue(elt(env, 3)); // t
    { popv(3); return onevalue(v0115); }

v0015:
    v0115 = stack[0];
    v0190 = v0057;
    {
        popv(3);
        fn = elt(env, 7); // dlesslex
        return (*qfn2(fn))(qenv(fn), v0115, v0190);
    }
// error exit handlers
v0085:
    popv(3);
    return nil;
}



// Code for pv_sort2

static LispObject CC_pv_sort2(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0041, v0042;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pv_sort2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0013;
    v0041 = v0000;
// end of prologue
    v0042 = v0041;
    v0041 = stack[0];
    fn = elt(env, 1); // pv_sort2a
    v0041 = (*qfn2(fn))(qenv(fn), v0042, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    { LispObject res = stack[0]; popv(1); return onevalue(res); }
// error exit handlers
v0015:
    popv(1);
    return nil;
}



// Code for noncomp1

static LispObject CC_noncomp1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0023, v0193, v0047;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0193 = v0000;
// end of prologue
    v0023 = v0193;
    v0023 = Lconsp(nil, v0023);
    env = stack[0];
    if (v0023 == nil) goto v0020;
    v0023 = v0193;
    v0023 = qcar(v0023);
    v0023 = Lconsp(nil, v0023);
    env = stack[0];
    if (v0023 == nil) goto v0017;
    v0023 = v0193;
    {
        popv(1);
        fn = elt(env, 4); // noncomfp
        return (*qfn1(fn))(qenv(fn), v0023);
    }

v0017:
    v0023 = v0193;
    v0047 = qcar(v0023);
    v0023 = elt(env, 2); // taylor!*
    if (v0047 == v0023) goto v0016;
    v0023 = v0193;
    v0023 = qcar(v0023);
    if (!symbolp(v0023)) v0023 = nil;
    else { v0023 = qfastgets(v0023);
           if (v0023 != nil) { v0023 = elt(v0023, 0); // noncom
#ifdef RECORD_GET
             if (v0023 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0023 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0023 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0023 == SPID_NOPROP) v0023 = nil; else v0023 = lisp_true; }}
#endif
    if (v0023 == nil) goto v0089;
    v0023 = qvalue(elt(env, 3)); // t
    { popv(1); return onevalue(v0023); }

v0089:
    v0023 = v0193;
    v0023 = qcdr(v0023);
    {
        popv(1);
        fn = elt(env, 5); // noncomlistp
        return (*qfn1(fn))(qenv(fn), v0023);
    }

v0016:
    v0023 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0023); }

v0020:
    v0023 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0023); }
}



// Code for split_form

static LispObject CC_split_form(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0017, v0004;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for split_form");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0017 = v0013;
    v0004 = v0000;
// end of prologue
    stack[-2] = v0004;
    stack[-1] = v0017;
    stack[0] = (LispObject)17; // 1
    v0017 = qvalue(elt(env, 1)); // nil
    v0017 = ncons(v0017);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-3];
    {
        LispObject v0019 = stack[-2];
        LispObject v0036 = stack[-1];
        LispObject v0021 = stack[0];
        popv(4);
        fn = elt(env, 2); // split_f
        return (*qfnn(fn))(qenv(fn), 4, v0019, v0036, v0021, v0017);
    }
// error exit handlers
v0012:
    popv(4);
    return nil;
}



// Code for rl_ordatp

static LispObject CC_rl_ordatp(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0017, v0004;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_ordatp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0017 = v0013;
    v0004 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_ordatp!*
    v0017 = list2(v0004, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-1];
    {
        LispObject v0090 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0090, v0017);
    }
// error exit handlers
v0018:
    popv(2);
    return nil;
}



// Code for monomcomparedegrevlex

static LispObject CC_monomcomparedegrevlex(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0197, v0073, v0101;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monomcomparedegrevlex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0013;
    stack[-1] = v0000;
// end of prologue
    v0197 = (LispObject)1; // 0
    stack[-2] = v0197;
    v0073 = stack[-1];
    v0197 = (LispObject)1; // 0
    v0101 = *(LispObject *)((char *)v0073 + (CELL-TAG_VECTOR) + ((int32_t)v0197/(16/CELL)));
    v0073 = stack[0];
    v0197 = (LispObject)1; // 0
    v0197 = *(LispObject *)((char *)v0073 + (CELL-TAG_VECTOR) + ((int32_t)v0197/(16/CELL)));
    v0197 = (LispObject)greaterp2(v0101, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    v0197 = v0197 ? lisp_true : nil;
    env = stack[-3];
    if (v0197 == nil) goto v0173;
    v0197 = (LispObject)17; // 1
    stack[-2] = v0197;
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }

v0173:
    v0073 = stack[-1];
    v0197 = (LispObject)1; // 0
    v0101 = *(LispObject *)((char *)v0073 + (CELL-TAG_VECTOR) + ((int32_t)v0197/(16/CELL)));
    v0073 = stack[0];
    v0197 = (LispObject)1; // 0
    v0197 = *(LispObject *)((char *)v0073 + (CELL-TAG_VECTOR) + ((int32_t)v0197/(16/CELL)));
    v0197 = (LispObject)lessp2(v0101, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    v0197 = v0197 ? lisp_true : nil;
    env = stack[-3];
    if (v0197 == nil) goto v0199;
    v0197 = (LispObject)-15; // -1
    stack[-2] = v0197;
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }

v0199:
    v0073 = stack[-1];
    v0197 = (LispObject)17; // 1
    v0197 = *(LispObject *)((char *)v0073 + (CELL-TAG_VECTOR) + ((int32_t)v0197/(16/CELL)));
    stack[-1] = v0197;
    v0073 = stack[0];
    v0197 = (LispObject)17; // 1
    v0197 = *(LispObject *)((char *)v0073 + (CELL-TAG_VECTOR) + ((int32_t)v0197/(16/CELL)));
    stack[0] = v0197;
    goto v0114;

v0114:
    v0197 = stack[-1];
    v0197 = qcar(v0197);
    if (v0197 == nil) goto v0052;
    v0197 = stack[-1];
    v0073 = qcar(v0197);
    v0197 = stack[0];
    v0197 = qcar(v0197);
    v0197 = (LispObject)lessp2(v0073, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    v0197 = v0197 ? lisp_true : nil;
    env = stack[-3];
    if (v0197 == nil) goto v0200;
    v0197 = (LispObject)17; // 1
    stack[-2] = v0197;
    v0197 = qvalue(elt(env, 1)); // nil
    v0197 = ncons(v0197);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    stack[-1] = v0197;
    goto v0114;

v0200:
    v0197 = stack[-1];
    v0073 = qcar(v0197);
    v0197 = stack[0];
    v0197 = qcar(v0197);
    v0197 = (LispObject)greaterp2(v0073, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    v0197 = v0197 ? lisp_true : nil;
    env = stack[-3];
    if (v0197 == nil) goto v0201;
    v0197 = (LispObject)-15; // -1
    stack[-2] = v0197;
    v0197 = qvalue(elt(env, 1)); // nil
    v0197 = ncons(v0197);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-3];
    stack[-1] = v0197;
    goto v0114;

v0201:
    v0197 = stack[-1];
    v0197 = qcdr(v0197);
    stack[-1] = v0197;
    v0197 = stack[0];
    v0197 = qcdr(v0197);
    stack[0] = v0197;
    goto v0114;

v0052:
    v0197 = stack[0];
    v0197 = qcar(v0197);
    if (!(v0197 == nil)) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0197 = (LispObject)1; // 0
    stack[-2] = v0197;
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }
// error exit handlers
v0198:
    popv(4);
    return nil;
}



// Code for delallasc

static LispObject CC_delallasc(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0007, v0008, v0023;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delallasc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0013;
    stack[-1] = v0000;
// end of prologue
    v0023 = nil;
    goto v0003;

v0003:
    v0007 = stack[0];
    if (v0007 == nil) goto v0014;
    v0008 = stack[-1];
    v0007 = stack[0];
    v0007 = qcar(v0007);
    v0007 = qcar(v0007);
    if (v0008 == v0007) goto v0044;
    v0007 = stack[0];
    v0007 = qcar(v0007);
    v0008 = v0023;
    v0007 = cons(v0007, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-2];
    v0023 = v0007;
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    stack[0] = v0007;
    goto v0003;

v0044:
    v0007 = stack[0];
    v0007 = qcdr(v0007);
    stack[0] = v0007;
    goto v0003;

v0014:
    v0007 = v0023;
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0007);
    }
// error exit handlers
v0173:
    popv(3);
    return nil;
}



// Code for rmultpf

static LispObject CC_rmultpf(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0057, v0058;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rmultpf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0013;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    goto v0003;

v0003:
    v0057 = stack[-1];
    if (v0057 == nil) goto v0014;
    v0057 = stack[-1];
    if (!consp(v0057)) goto v0090;
    v0057 = stack[-1];
    v0057 = qcar(v0057);
    v0057 = (consp(v0057) ? nil : lisp_true);
    goto v0018;

v0018:
    if (v0057 == nil) goto v0002;
    v0057 = qvalue(elt(env, 1)); // t
    goto v0056;

v0056:
    if (v0057 == nil) goto v0199;
    stack[0] = stack[-3];
    v0058 = stack[-2];
    v0057 = stack[-1];
    v0057 = cons(v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-4];
    v0057 = ncons(v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-4];
    {
        LispObject v0204 = stack[0];
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0204, v0057);
    }

v0199:
    v0057 = stack[-1];
    v0057 = qcar(v0057);
    stack[0] = qcar(v0057);
    v0058 = stack[-2];
    v0057 = stack[-1];
    v0057 = qcar(v0057);
    v0057 = qcdr(v0057);
    v0058 = CC_rmultpf(env, v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-4];
    v0057 = stack[-3];
    v0057 = acons(stack[0], v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-4];
    stack[-3] = v0057;
    v0057 = stack[-1];
    v0057 = qcdr(v0057);
    stack[-1] = v0057;
    goto v0003;

v0002:
    v0057 = stack[-2];
    v0058 = qcar(v0057);
    v0057 = stack[-1];
    v0057 = qcar(v0057);
    v0057 = qcar(v0057);
    v0057 = qcar(v0057);
    fn = elt(env, 3); // reordop
    v0057 = (*qfn2(fn))(qenv(fn), v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-4];
    goto v0056;

v0090:
    v0057 = qvalue(elt(env, 1)); // t
    goto v0018;

v0014:
    v0057 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(qenv(fn), v0057);
    }
// error exit handlers
v0061:
    popv(5);
    return nil;
}



// Code for gcdfd1

static LispObject CC_gcdfd1(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0205, v0027;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdfd1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0013;
    v0205 = v0000;
// end of prologue

v0011:
    v0027 = stack[0];
    if (v0027 == nil) { popv(2); return onevalue(v0205); }
    v0027 = stack[0];
    if (!consp(v0027)) goto v0016;
    v0027 = stack[0];
    v0027 = qcar(v0027);
    v0027 = (consp(v0027) ? nil : lisp_true);
    goto v0015;

v0015:
    if (v0027 == nil) goto v0022;
    v0027 = v0205;
    v0205 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // gcddd
        return (*qfn2(fn))(qenv(fn), v0027, v0205);
    }

v0022:
    v0027 = v0205;
    v0205 = stack[0];
    v0205 = qcar(v0205);
    v0205 = qcdr(v0205);
    v0205 = CC_gcdfd1(env, v0027, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-1];
    v0027 = stack[0];
    v0027 = qcdr(v0027);
    stack[0] = v0027;
    goto v0011;

v0016:
    v0027 = qvalue(elt(env, 1)); // t
    goto v0015;
// error exit handlers
v0107:
    popv(2);
    return nil;
}



// Code for multsq

static LispObject CC_multsq(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0157, v0158;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0013;
    stack[-3] = v0000;
// end of prologue
    v0157 = stack[-3];
    v0157 = qcar(v0157);
    if (v0157 == nil) goto v0014;
    v0157 = stack[-2];
    v0157 = qcar(v0157);
    v0157 = (v0157 == nil ? lisp_true : nil);
    goto v0009;

v0009:
    if (v0157 == nil) goto v0029;
    v0158 = qvalue(elt(env, 2)); // nil
    v0157 = (LispObject)17; // 1
    popv(6);
    return cons(v0158, v0157);

v0029:
    v0157 = stack[-3];
    v0158 = qcdr(v0157);
    v0157 = (LispObject)17; // 1
    if (v0158 == v0157) goto v0008;
    v0157 = qvalue(elt(env, 2)); // nil
    goto v0106;

v0106:
    if (v0157 == nil) goto v0054;
    v0157 = stack[-3];
    v0158 = qcar(v0157);
    v0157 = stack[-2];
    v0157 = qcar(v0157);
    fn = elt(env, 3); // multf
    v0158 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    v0157 = (LispObject)17; // 1
    popv(6);
    return cons(v0158, v0157);

v0054:
    v0157 = stack[-3];
    v0158 = qcar(v0157);
    v0157 = stack[-2];
    v0157 = qcdr(v0157);
    fn = elt(env, 4); // gcdf
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-5];
    stack[-4] = v0157;
    v0157 = stack[-2];
    v0158 = qcar(v0157);
    v0157 = stack[-3];
    v0157 = qcdr(v0157);
    fn = elt(env, 4); // gcdf
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-5];
    stack[-1] = v0157;
    v0157 = stack[-3];
    v0158 = qcar(v0157);
    v0157 = stack[-4];
    fn = elt(env, 5); // quotf!-fail
    stack[0] = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-5];
    v0157 = stack[-2];
    v0158 = qcar(v0157);
    v0157 = stack[-1];
    fn = elt(env, 5); // quotf!-fail
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-5];
    fn = elt(env, 3); // multf
    v0157 = (*qfn2(fn))(qenv(fn), stack[0], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-5];
    stack[0] = v0157;
    v0157 = stack[-3];
    v0158 = qcdr(v0157);
    v0157 = stack[-1];
    fn = elt(env, 5); // quotf!-fail
    stack[-1] = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-5];
    v0157 = stack[-2];
    v0158 = qcdr(v0157);
    v0157 = stack[-4];
    fn = elt(env, 5); // quotf!-fail
    v0157 = (*qfn2(fn))(qenv(fn), v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-5];
    fn = elt(env, 3); // multf
    v0157 = (*qfn2(fn))(qenv(fn), stack[-1], v0157);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-5];
    stack[-4] = v0157;
    v0158 = stack[0];
    v0157 = stack[-4];
    v0157 = cons(v0158, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 6); // canonsq
        return (*qfn1(fn))(qenv(fn), v0157);
    }

v0008:
    v0157 = stack[-2];
    v0158 = qcdr(v0157);
    v0157 = (LispObject)17; // 1
    v0157 = (v0158 == v0157 ? lisp_true : nil);
    goto v0106;

v0014:
    v0157 = qvalue(elt(env, 1)); // t
    goto v0009;
// error exit handlers
v0100:
    popv(6);
    return nil;
}



// Code for qqe_nytidp

static LispObject CC_qqe_nytidp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0011;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_nytidp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0011 = v0000;
// end of prologue
    if (!symbolp(v0011)) v0011 = nil;
    else { v0011 = qfastgets(v0011);
           if (v0011 != nil) { v0011 = elt(v0011, 10); // idtype
#ifdef RECORD_GET
             if (v0011 != SPID_NOPROP)
                record_get(elt(fastget_names, 10), 1);
             else record_get(elt(fastget_names, 10), 0),
                v0011 = nil; }
           else record_get(elt(fastget_names, 10), 0); }
#else
             if (v0011 == SPID_NOPROP) v0011 = nil; }}
#endif
    v0011 = (v0011 == nil ? lisp_true : nil);
    return onevalue(v0011);
}



// Code for bftrim!:

static LispObject CC_bftrimT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0017, v0004;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bftrim:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0017 = v0000;
// end of prologue
    stack[0] = v0017;
    v0004 = qvalue(elt(env, 1)); // !:bprec!:
    v0017 = (LispObject)49; // 3
    v0017 = difference2(v0004, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-1];
    fn = elt(env, 2); // round!:mt
    v0017 = (*qfn2(fn))(qenv(fn), stack[0], v0017);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); // normbf
        return (*qfn1(fn))(qenv(fn), v0017);
    }
// error exit handlers
v0018:
    popv(2);
    return nil;
}



// Code for off1

static LispObject CC_off1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0043, v0035;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for off1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0043 = v0000;
// end of prologue
    v0035 = v0043;
    v0043 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // onoff
        return (*qfn2(fn))(qenv(fn), v0035, v0043);
    }
}



// Code for mgenp

static LispObject CC_mgenp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0017, v0004;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mgenp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0004 = v0000;
// end of prologue
    v0017 = v0004;
    if (!consp(v0017)) goto v0009;
    v0017 = qvalue(elt(env, 2)); // nil
    return onevalue(v0017);

v0009:
    v0017 = v0004;
    v0004 = elt(env, 1); // mgen
    return get(v0017, v0004);
}



// Code for on1

static LispObject CC_on1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0043, v0035;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for on1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0043 = v0000;
// end of prologue
    v0035 = v0043;
    v0043 = qvalue(elt(env, 1)); // t
    {
        fn = elt(env, 2); // onoff
        return (*qfn2(fn))(qenv(fn), v0035, v0043);
    }
}



// Code for evsum

static LispObject CC_evsum(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0033, v0034, v0109;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evsum");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0013;
    stack[-1] = v0000;
// end of prologue
    v0109 = nil;
    goto v0009;

v0009:
    v0033 = stack[-1];
    if (v0033 == nil) goto v0010;
    v0033 = stack[0];
    if (v0033 == nil) goto v0010;
    v0033 = stack[-1];
    v0034 = qcar(v0033);
    v0033 = stack[0];
    v0033 = qcar(v0033);
    v0033 = (LispObject)(int32_t)((int32_t)v0034 + (int32_t)v0033 - TAG_FIXNUM);
    v0034 = v0109;
    v0033 = cons(v0033, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-2];
    v0109 = v0033;
    v0033 = stack[-1];
    v0033 = qcdr(v0033);
    stack[-1] = v0033;
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    stack[0] = v0033;
    goto v0009;

v0010:
    v0033 = v0109;
    v0033 = Lnreverse(nil, v0033);
    v0109 = v0033;
    v0033 = stack[-1];
    if (v0033 == nil) goto v0047;
    v0034 = v0109;
    v0033 = stack[-1];
        popv(3);
        return Lnconc(nil, v0034, v0033);

v0047:
    v0033 = stack[0];
    if (v0033 == nil) { popv(3); return onevalue(v0109); }
    v0034 = v0109;
    v0033 = stack[0];
        popv(3);
        return Lnconc(nil, v0034, v0033);
// error exit handlers
v0097:
    popv(3);
    return nil;
}



// Code for bcint2op

static LispObject CC_bcint2op(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0078, v0079, v0213, v0214, v0215;
    LispObject v0113, v0013, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "bcint2op");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0013 = va_arg(aa, LispObject);
    v0113 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcint2op");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0113,v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0013,v0113);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0215 = v0113;
    v0213 = v0013;
    v0214 = v0000;
// end of prologue
    v0078 = qvalue(elt(env, 1)); // dmode!*
    if (v0078 == nil) goto v0056;
    v0078 = qvalue(elt(env, 2)); // nil
    goto v0014;

v0014:
    if (v0078 == nil) goto v0010;
    v0079 = v0214;
    v0078 = (LispObject)1; // 0
    if (v0079 == v0078) goto v0216;
    v0078 = v0214;
    v0079 = v0078;
    goto v0217;

v0217:
    v0078 = (LispObject)17; // 1
    popv(1);
    return cons(v0079, v0078);

v0216:
    v0078 = qvalue(elt(env, 2)); // nil
    v0079 = v0078;
    goto v0217;

v0010:
    v0078 = nil;
    { popv(1); return onevalue(v0078); }

v0056:
    v0079 = (LispObject)17; // 1
    v0078 = v0214;
    v0078 = qcdr(v0078);
    if (v0079 == v0078) goto v0015;
    v0078 = qvalue(elt(env, 2)); // nil
    goto v0014;

v0015:
    v0078 = v0214;
    v0078 = qcar(v0078);
    v0214 = v0078;
    if (is_number(v0078)) goto v0001;
    v0078 = qvalue(elt(env, 2)); // nil
    goto v0014;

v0001:
    v0079 = (LispObject)17; // 1
    v0078 = v0213;
    v0078 = qcdr(v0078);
    if (v0079 == v0078) goto v0022;
    v0078 = qvalue(elt(env, 2)); // nil
    goto v0014;

v0022:
    v0078 = v0213;
    v0078 = qcar(v0078);
    v0213 = v0078;
    if (is_number(v0078)) goto v0050;
    v0078 = qvalue(elt(env, 2)); // nil
    goto v0014;

v0050:
    v0079 = v0215;
    v0078 = elt(env, 3); // times
    if (v0079 == v0078) goto v0088;
    v0079 = v0215;
    v0078 = elt(env, 4); // plus
    if (v0079 == v0078) goto v0203;
    v0078 = v0215;
    v0079 = v0214;
    v0078 = Lapply2(nil, 3, v0078, v0079, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[0];
    goto v0046;

v0046:
    v0214 = v0078;
    goto v0014;

v0203:
    v0078 = v0214;
    v0079 = v0213;
    v0078 = plus2(v0078, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[0];
    goto v0046;

v0088:
    v0078 = v0214;
    v0079 = v0213;
    v0078 = times2(v0078, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[0];
    goto v0046;
// error exit handlers
v0218:
    popv(1);
    return nil;
}



// Code for quotfm

static LispObject CC_quotfm(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0015, v0016, v0056;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotfm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0016 = v0013;
    v0056 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // !*mcd
    qvalue(elt(env, 1)) = nil; // !*mcd
    v0015 = qvalue(elt(env, 2)); // t
    qvalue(elt(env, 1)) = v0015; // !*mcd
    v0015 = v0056;
    fn = elt(env, 3); // quotf
    v0015 = (*qfn2(fn))(qenv(fn), v0015, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // !*mcd
    { popv(2); return onevalue(v0015); }
// error exit handlers
v0004:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // !*mcd
    popv(2);
    return nil;
}



// Code for !*collectphysops_reversed

static LispObject CC_Hcollectphysops_reversed(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0007, v0008;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *collectphysops_reversed");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0013;
    stack[-1] = v0000;
// end of prologue
    v0007 = stack[-1];
    fn = elt(env, 2); // physopp
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-2];
    if (v0007 == nil) goto v0018;
    v0008 = stack[-1];
    v0007 = stack[0];
    popv(3);
    return cons(v0008, v0007);

v0018:
    v0007 = stack[-1];
    if (!consp(v0007)) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0007 = stack[-1];
    v0008 = qcar(v0007);
    v0007 = stack[0];
    v0007 = CC_Hcollectphysops_reversed(env, v0008, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-2];
    stack[0] = v0007;
    v0007 = stack[-1];
    v0007 = qcdr(v0007);
    stack[-1] = v0007;
    goto v0018;
// error exit handlers
v0047:
    popv(3);
    return nil;
}



// Code for constimes

static LispObject CC_constimes(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0043, v0035;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for constimes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0043 = v0000;
// end of prologue
    v0035 = v0043;
    v0043 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // cstimes
        return (*qfn2(fn))(qenv(fn), v0035, v0043);
    }
}



// Code for arraychk

static LispObject CC_arraychk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0035;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for arraychk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0035 = v0000;
// end of prologue
    if (v0035 == nil) goto v0020;
    v0035 = qvalue(elt(env, 2)); // nil
    return onevalue(v0035);

v0020:
    v0035 = elt(env, 1); // array
    return onevalue(v0035);
}



// Code for fs!:angle!-order

static LispObject CC_fsTangleKorder(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0211, v0210, v0166;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:angle-order");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0013;
    stack[-3] = v0000;
// end of prologue
    v0211 = (LispObject)1; // 0
    stack[-4] = v0211;
    v0210 = stack[-3];
    v0211 = (LispObject)33; // 2
    v0211 = *(LispObject *)((char *)v0210 + (CELL-TAG_VECTOR) + ((int32_t)v0211/(16/CELL)));
    stack[-1] = v0211;
    v0210 = stack[-2];
    v0211 = (LispObject)33; // 2
    v0211 = *(LispObject *)((char *)v0210 + (CELL-TAG_VECTOR) + ((int32_t)v0211/(16/CELL)));
    stack[0] = v0211;
    goto v0029;

v0029:
    v0210 = stack[-1];
    v0211 = stack[-4];
    v0166 = *(LispObject *)((char *)v0210 + (CELL-TAG_VECTOR) + ((int32_t)v0211/(16/CELL)));
    v0210 = stack[0];
    v0211 = stack[-4];
    v0211 = *(LispObject *)((char *)v0210 + (CELL-TAG_VECTOR) + ((int32_t)v0211/(16/CELL)));
    v0211 = difference2(v0166, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    v0166 = v0211;
    v0210 = v0166;
    v0211 = (LispObject)1; // 0
    if (v0210 == v0211) goto v0107;
    v0210 = v0166;
    v0211 = (LispObject)1; // 0
        popv(6);
        return Lgreaterp(nil, v0210, v0211);

v0107:
    v0211 = stack[-4];
    v0211 = add1(v0211);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    stack[-4] = v0211;
    v0210 = stack[-4];
    v0211 = (LispObject)129; // 8
    v0211 = (LispObject)lessp2(v0210, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    v0211 = v0211 ? lisp_true : nil;
    env = stack[-5];
    if (!(v0211 == nil)) goto v0029;
    v0210 = stack[-3];
    v0211 = (LispObject)17; // 1
    v0166 = *(LispObject *)((char *)v0210 + (CELL-TAG_VECTOR) + ((int32_t)v0211/(16/CELL)));
    v0210 = stack[-2];
    v0211 = (LispObject)17; // 1
    v0211 = *(LispObject *)((char *)v0210 + (CELL-TAG_VECTOR) + ((int32_t)v0211/(16/CELL)));
    if (equal(v0166, v0211)) goto v0203;
    v0210 = stack[-3];
    v0211 = (LispObject)17; // 1
    v0210 = *(LispObject *)((char *)v0210 + (CELL-TAG_VECTOR) + ((int32_t)v0211/(16/CELL)));
    v0211 = elt(env, 2); // sin
    if (v0210 == v0211) goto v0099;
    v0211 = qvalue(elt(env, 3)); // t
    { popv(6); return onevalue(v0211); }

v0099:
    v0211 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0211); }

v0203:
    v0211 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0211); }
// error exit handlers
v0079:
    popv(6);
    return nil;
}



// Code for cali_trace

static LispObject CC_cali_trace(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0037;
    argcheck(nargs, 0, "cali_trace");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cali_trace");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v0037 = elt(env, 1); // cali
    if (!symbolp(v0037)) v0037 = nil;
    else { v0037 = qfastgets(v0037);
           if (v0037 != nil) { v0037 = elt(v0037, 31); // trace
#ifdef RECORD_GET
             if (v0037 != SPID_NOPROP)
                record_get(elt(fastget_names, 31), 1);
             else record_get(elt(fastget_names, 31), 0),
                v0037 = nil; }
           else record_get(elt(fastget_names, 31), 0); }
#else
             if (v0037 == SPID_NOPROP) v0037 = nil; }}
#endif
    return onevalue(v0037);
}



// Code for pcmult

static LispObject CC_pcmult(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0053, v0111;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pcmult");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-4] = v0013;
    v0053 = v0000;
// end of prologue
    stack[-5] = v0053;
    v0053 = stack[-5];
    if (v0053 == nil) goto v0041;
    v0053 = stack[-5];
    v0053 = qcar(v0053);
    v0111 = v0053;
    stack[0] = qcar(v0111);
    v0111 = stack[-4];
    v0053 = qcdr(v0053);
    fn = elt(env, 2); // cprod
    v0053 = (*qfn2(fn))(qenv(fn), v0111, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-6];
    v0053 = cons(stack[0], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-6];
    v0053 = ncons(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-6];
    stack[-2] = v0053;
    stack[-3] = v0053;
    goto v0009;

v0009:
    v0053 = stack[-5];
    v0053 = qcdr(v0053);
    stack[-5] = v0053;
    v0053 = stack[-5];
    if (v0053 == nil) { LispObject res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v0053 = stack[-5];
    v0053 = qcar(v0053);
    v0111 = v0053;
    stack[0] = qcar(v0111);
    v0111 = stack[-4];
    v0053 = qcdr(v0053);
    fn = elt(env, 2); // cprod
    v0053 = (*qfn2(fn))(qenv(fn), v0111, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-6];
    v0053 = cons(stack[0], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-6];
    v0053 = ncons(v0053);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-6];
    v0053 = Lrplacd(nil, stack[-1], v0053);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-6];
    v0053 = stack[-2];
    v0053 = qcdr(v0053);
    stack[-2] = v0053;
    goto v0009;

v0041:
    v0053 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0053); }
// error exit handlers
v0114:
    popv(7);
    return nil;
}



// Code for pkp

static LispObject CC_pkp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0225, v0226, v0206;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pkp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    stack[-3] = nil;
    v0225 = stack[0];
    if (!consp(v0225)) goto v0042;
    v0225 = qvalue(elt(env, 2)); // !*ppacked
    v0225 = (v0225 == nil ? lisp_true : nil);
    goto v0041;

v0041:
    if (!(v0225 == nil)) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    v0225 = stack[0];
    v0226 = Llength(nil, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-4];
    v0225 = (LispObject)161; // 10
    v0225 = (LispObject)geq2(v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    v0225 = v0225 ? lisp_true : nil;
    env = stack[-4];
    stack[-2] = v0225;
    v0225 = stack[0];
    stack[-1] = v0225;
    goto v0191;

v0191:
    v0225 = stack[-1];
    if (v0225 == nil) goto v0029;
    v0225 = stack[-1];
    v0225 = qcar(v0225);
    stack[0] = v0225;
    v0225 = stack[-2];
    if (v0225 == nil) goto v0079;
    v0226 = stack[0];
    v0225 = (LispObject)161; // 10
    v0225 = (LispObject)lessp2(v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    v0225 = v0225 ? lisp_true : nil;
    env = stack[-4];
    if (v0225 == nil) goto v0203;
    v0226 = stack[0];
    v0225 = qvalue(elt(env, 4)); // diglist!*
    fn = elt(env, 6); // dssoc
    v0225 = (*qfn2(fn))(qenv(fn), v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-4];
    v0206 = qcar(v0225);
    v0226 = elt(env, 5); // !0
    v0225 = stack[-3];
    v0225 = list2star(v0206, v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-4];
    stack[-3] = v0225;
    goto v0174;

v0174:
    v0225 = stack[-1];
    v0225 = qcdr(v0225);
    stack[-1] = v0225;
    goto v0191;

v0203:
    v0226 = stack[0];
    v0225 = (LispObject)161; // 10
    v0225 = Ldivide(nil, v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-4];
    stack[0] = v0225;
    v0225 = stack[0];
    v0226 = qcar(v0225);
    v0225 = qvalue(elt(env, 4)); // diglist!*
    fn = elt(env, 6); // dssoc
    v0225 = (*qfn2(fn))(qenv(fn), v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-4];
    v0226 = qcar(v0225);
    v0225 = stack[-3];
    v0225 = cons(v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-4];
    stack[-3] = v0225;
    v0225 = stack[0];
    v0226 = qcdr(v0225);
    v0225 = qvalue(elt(env, 4)); // diglist!*
    fn = elt(env, 6); // dssoc
    v0225 = (*qfn2(fn))(qenv(fn), v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-4];
    v0226 = qcar(v0225);
    v0225 = stack[-3];
    v0225 = cons(v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-4];
    stack[-3] = v0225;
    goto v0174;

v0079:
    v0226 = stack[0];
    v0225 = qvalue(elt(env, 4)); // diglist!*
    fn = elt(env, 6); // dssoc
    v0225 = (*qfn2(fn))(qenv(fn), v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-4];
    v0226 = qcar(v0225);
    v0225 = stack[-3];
    v0225 = cons(v0226, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-4];
    stack[-3] = v0225;
    goto v0174;

v0029:
    v0225 = stack[-3];
    v0225 = Lnreverse(nil, v0225);
        popv(5);
        return Lcompress(nil, v0225);

v0042:
    v0225 = qvalue(elt(env, 1)); // t
    goto v0041;
// error exit handlers
v0227:
    popv(5);
    return nil;
}



// Code for fkern

static LispObject CC_fkern(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0194, v0220, v0084;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fkern");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0000;
// end of prologue
    v0194 = stack[-1];
    if (!consp(v0194)) goto v0041;
    v0194 = stack[-1];
    v0194 = qcar(v0194);
    if (!symbolp(v0194)) v0194 = nil;
    else { v0194 = qfastgets(v0194);
           if (v0194 != nil) { v0194 = elt(v0194, 38); // fkernfn
#ifdef RECORD_GET
             if (v0194 != SPID_NOPROP)
                record_get(elt(fastget_names, 38), 1);
             else record_get(elt(fastget_names, 38), 0),
                v0194 = nil; }
           else record_get(elt(fastget_names, 38), 0); }
#else
             if (v0194 == SPID_NOPROP) v0194 = nil; }}
#endif
    stack[-2] = v0194;
    if (v0194 == nil) goto v0010;
    v0220 = stack[-2];
    v0194 = stack[-1];
        popv(4);
        return Lapply1(nil, v0220, v0194);

v0010:
    v0194 = stack[-1];
    v0194 = qcar(v0194);
    if (!consp(v0194)) goto v0191;
    v0194 = qvalue(elt(env, 2)); // exlist!*
    goto v0029;

v0029:
    stack[0] = v0194;
    v0220 = stack[-1];
    v0194 = stack[0];
    v0194 = Lassoc(nil, v0220, v0194);
    stack[-2] = v0194;
    if (!(v0194 == nil)) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0220 = stack[-1];
    v0194 = qvalue(elt(env, 1)); // nil
    v0194 = list2(v0220, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-3];
    stack[-2] = v0194;
    v0220 = stack[-2];
    v0194 = stack[0];
    fn = elt(env, 5); // ordad
    v0194 = (*qfn2(fn))(qenv(fn), v0220, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-3];
    stack[0] = v0194;
    v0194 = stack[-1];
    v0194 = qcar(v0194);
    if (!consp(v0194)) goto v0195;
    v0194 = stack[0];
    qvalue(elt(env, 2)) = v0194; // exlist!*
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }

v0195:
    v0194 = stack[-1];
    v0194 = qcar(v0194);
    v0220 = ncons(v0194);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-3];
    v0194 = qvalue(elt(env, 3)); // kprops!*
    fn = elt(env, 6); // union
    v0194 = (*qfn2(fn))(qenv(fn), v0220, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-3];
    qvalue(elt(env, 3)) = v0194; // kprops!*
    v0194 = stack[-1];
    v0084 = qcar(v0194);
    v0220 = elt(env, 4); // klist
    v0194 = stack[0];
    v0194 = Lputprop(nil, 3, v0084, v0220, v0194);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    { LispObject res = stack[-2]; popv(4); return onevalue(res); }

v0191:
    v0194 = stack[-1];
    v0194 = qcar(v0194);
    if (!symbolp(v0194)) v0194 = nil;
    else { v0194 = qfastgets(v0194);
           if (v0194 != nil) { v0194 = elt(v0194, 24); // klist
#ifdef RECORD_GET
             if (v0194 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v0194 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v0194 == SPID_NOPROP) v0194 = nil; }}
#endif
    goto v0029;

v0041:
    v0194 = stack[-1];
    v0220 = qvalue(elt(env, 1)); // nil
    popv(4);
    return list2(v0194, v0220);
// error exit handlers
v0163:
    popv(4);
    return nil;
}



// Code for setdiff

static LispObject CC_setdiff(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0039, v0106;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setdiff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0013;
    v0039 = v0000;
// end of prologue

v0011:
    v0106 = stack[0];
    if (v0106 == nil) { popv(2); return onevalue(v0039); }
    v0106 = v0039;
    if (v0106 == nil) goto v0041;
    v0106 = stack[0];
    v0106 = qcar(v0106);
    v0039 = Ldelete(nil, v0106, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-1];
    v0106 = stack[0];
    v0106 = qcdr(v0106);
    stack[0] = v0106;
    goto v0011;

v0041:
    v0039 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0039); }
// error exit handlers
v0055:
    popv(2);
    return nil;
}



// Code for lalr_cached_goto

static LispObject CC_lalr_cached_goto(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0004, v0005;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_cached_goto");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0004 = v0013;
    v0005 = v0000;
// end of prologue
    stack[0] = v0005;
    v0005 = v0004;
    v0004 = qvalue(elt(env, 1)); // goto_cache
    fn = elt(env, 2); // gethash
    v0004 = (*qfn2(fn))(qenv(fn), v0005, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    v0004 = Lassoc(nil, stack[0], v0004);
    v0004 = qcdr(v0004);
    { popv(1); return onevalue(v0004); }
// error exit handlers
v0090:
    popv(1);
    return nil;
}



// Code for subs2q

static LispObject CC_subs2q(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0192, v0228, v0061, v0204;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subs2q");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0000;
// end of prologue

v0112:
    v0192 = stack[-2];
    v0228 = qcar(v0192);
    v0192 = stack[-2];
    v0192 = qcdr(v0192);
    stack[-3] = v0228;
    stack[-1] = v0192;
    v0192 = stack[-3];
    fn = elt(env, 2); // subs2f
    stack[0] = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-4];
    v0192 = stack[-1];
    fn = elt(env, 2); // subs2f
    v0192 = (*qfn1(fn))(qenv(fn), v0192);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-4];
    v0204 = stack[0];
    v0061 = v0192;
    v0192 = v0204;
    v0228 = qcdr(v0192);
    v0192 = (LispObject)17; // 1
    if (v0228 == v0192) goto v0106;
    v0192 = qvalue(elt(env, 1)); // nil
    goto v0004;

v0004:
    if (v0192 == nil) goto v0202;
    v0192 = v0204;
    v0228 = qcar(v0192);
    v0192 = stack[-3];
    if (equal(v0228, v0192)) goto v0049;
    v0192 = qvalue(elt(env, 1)); // nil
    goto v0205;

v0205:
    if (!(v0192 == nil)) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0192 = v0204;
    v0228 = v0061;
    {
        popv(5);
        fn = elt(env, 3); // quotsq
        return (*qfn2(fn))(qenv(fn), v0192, v0228);
    }

v0049:
    v0192 = v0061;
    v0228 = qcar(v0192);
    v0192 = stack[-1];
    v0192 = (equal(v0228, v0192) ? lisp_true : nil);
    goto v0205;

v0202:
    v0192 = v0204;
    v0228 = v0061;
    fn = elt(env, 3); // quotsq
    v0192 = (*qfn2(fn))(qenv(fn), v0192, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-4];
    stack[-2] = v0192;
    goto v0112;

v0106:
    v0192 = v0061;
    v0228 = qcdr(v0192);
    v0192 = (LispObject)17; // 1
    v0192 = (v0228 == v0192 ? lisp_true : nil);
    goto v0004;
// error exit handlers
v0171:
    popv(5);
    return nil;
}



// Code for qqe_btidp

static LispObject CC_qqe_btidp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0035, v0041;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_btidp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0035 = v0000;
// end of prologue
    if (!symbolp(v0035)) v0035 = nil;
    else { v0035 = qfastgets(v0035);
           if (v0035 != nil) { v0035 = elt(v0035, 10); // idtype
#ifdef RECORD_GET
             if (v0035 != SPID_NOPROP)
                record_get(elt(fastget_names, 10), 1);
             else record_get(elt(fastget_names, 10), 0),
                v0035 = nil; }
           else record_get(elt(fastget_names, 10), 0); }
#else
             if (v0035 == SPID_NOPROP) v0035 = nil; }}
#endif
    v0041 = elt(env, 1); // bt
    v0035 = (v0035 == v0041 ? lisp_true : nil);
    return onevalue(v0035);
}



// Code for prepsq

static LispObject CC_prepsq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0004, v0005;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0005 = v0000;
// end of prologue
    v0004 = v0005;
    v0004 = qcar(v0004);
    if (v0004 == nil) goto v0020;
    v0004 = elt(env, 1); // prepf
    {
        fn = elt(env, 2); // sqform
        return (*qfn2(fn))(qenv(fn), v0005, v0004);
    }

v0020:
    v0004 = (LispObject)1; // 0
    return onevalue(v0004);
}



// Code for subs2!*

static LispObject CC_subs2H(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003, v0010;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subs2*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0010 = v0000;
// end of prologue
    v0003 = qvalue(elt(env, 1)); // !*sub2
    stack[0] = qvalue(elt(env, 1)); // !*sub2
    qvalue(elt(env, 1)) = v0003; // !*sub2
    v0003 = v0010;
    fn = elt(env, 2); // subs2
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // !*sub2
    { popv(2); return onevalue(v0003); }
// error exit handlers
v0014:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // !*sub2
    popv(2);
    return nil;
}



// Code for negsq

static LispObject CC_negsq(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0042, v0044;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for negsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0042 = stack[0];
    v0042 = qcar(v0042);
    fn = elt(env, 1); // negf
    v0044 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    v0042 = stack[0];
    v0042 = qcdr(v0042);
    popv(1);
    return cons(v0044, v0042);
// error exit handlers
v0016:
    popv(1);
    return nil;
}



// Code for hasonephysop

static LispObject CC_hasonephysop(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0004;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for hasonephysop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue

v0112:
    v0004 = stack[0];
    if (v0004 == nil) goto v0020;
    v0004 = stack[0];
    v0004 = qcar(v0004);
    fn = elt(env, 2); // physopp!*
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-1];
    if (!(v0004 == nil)) { popv(2); return onevalue(v0004); }
    v0004 = stack[0];
    v0004 = qcdr(v0004);
    stack[0] = v0004;
    goto v0112;

v0020:
    v0004 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0004); }
// error exit handlers
v0018:
    popv(2);
    return nil;
}



// Code for errorset!*

static LispObject CC_errorsetH(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0044, v0015, v0016;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for errorset*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0044 = v0013;
    v0015 = v0000;
// end of prologue
    v0016 = v0015;
    v0015 = v0044;
    v0044 = qvalue(elt(env, 1)); // !*backtrace
    {
        fn = elt(env, 2); // errorset
        return (*qfnn(fn))(qenv(fn), 3, v0016, v0015, v0044);
    }
}



// Code for fs!:timesterm

static LispObject CC_fsTtimesterm(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0027, v0060, v0107;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:timesterm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0013;
    stack[-1] = v0000;
// end of prologue
    v0027 = stack[0];
    if (v0027 == nil) goto v0011;
    v0027 = stack[-1];
    if (v0027 == nil) goto v0014;
    v0060 = stack[-1];
    v0027 = stack[0];
    fn = elt(env, 2); // fs!:timestermterm
    v0027 = (*qfn2(fn))(qenv(fn), v0060, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-3];
    stack[-2] = v0027;
    v0107 = stack[-1];
    v0060 = stack[0];
    v0027 = (LispObject)49; // 3
    v0027 = *(LispObject *)((char *)v0060 + (CELL-TAG_VECTOR) + ((int32_t)v0027/(16/CELL)));
    v0027 = CC_fsTtimesterm(env, v0107, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-3];
    {
        LispObject v0045 = stack[-2];
        popv(4);
        fn = elt(env, 3); // fs!:plus
        return (*qfn2(fn))(qenv(fn), v0045, v0027);
    }

v0014:
    v0027 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0027); }

v0011:
    v0027 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0027); }
// error exit handlers
v0048:
    popv(4);
    return nil;
}



// Code for bas_rep

static LispObject CC_bas_rep(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0043, v0035;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bas_rep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0043 = v0000;
// end of prologue
    v0035 = v0043;
    v0043 = (LispObject)81; // 5
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(qenv(fn), v0035, v0043);
    }
}



// Code for !:minus

static LispObject CC_Tminus(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0196, v0028, v0024;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :minus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0028 = v0000;
// end of prologue
    v0196 = v0028;
    if (v0196 == nil) goto v0020;
    v0196 = v0028;
    if (!consp(v0196)) goto v0009;
    v0196 = v0028;
    v0024 = qcar(v0196);
    v0196 = elt(env, 2); // minus
    v0196 = get(v0024, v0196);
    env = stack[0];
    v0024 = v0196;
    v0196 = v0024;
    if (v0196 == nil) goto v0008;
    v0196 = v0024;
        popv(1);
        return Lapply1(nil, v0196, v0028);

v0008:
    v0024 = v0028;
    v0028 = (LispObject)-15; // -1
    v0196 = elt(env, 3); // times
    {
        popv(1);
        fn = elt(env, 4); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0024, v0028, v0196);
    }

v0009:
    v0196 = v0028;
    popv(1);
    return negate(v0196);

v0020:
    v0196 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0196); }
}



// Code for rev

static LispObject CC_rev(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0032, v0038, v0039;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rev");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0032 = v0013;
    v0038 = v0000;
// end of prologue

v0003:
    v0039 = v0038;
    if (v0039 == nil) { popv(2); return onevalue(v0032); }
    v0039 = v0038;
    v0039 = qcdr(v0039);
    stack[0] = v0039;
    v0038 = qcar(v0038);
    v0032 = cons(v0038, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-1];
    v0038 = stack[0];
    goto v0003;
// error exit handlers
v0040:
    popv(2);
    return nil;
}



// Code for !*!*s2a

static LispObject CC_HHs2a(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject v0020, v0011;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for **s2a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0020 = v0013;
    v0011 = v0000;
// end of prologue
    return onevalue(v0011);
}



// Code for lto_insertq

static LispObject CC_lto_insertq(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0021, v0032, v0038, v0039;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lto_insertq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0032 = v0013;
    v0038 = v0000;
// end of prologue
    v0039 = v0038;
    v0021 = v0032;
    v0021 = Lmemq(nil, v0039, v0021);
    if (!(v0021 == nil)) return onevalue(v0032);
    v0021 = v0038;
    return cons(v0021, v0032);
}



// Code for lnc

static LispObject CC_lnc(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0106, v0040;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lnc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0106 = v0000;
// end of prologue

v0020:
    v0040 = v0106;
    if (v0040 == nil) goto v0010;
    v0040 = v0106;
    if (!consp(v0040)) goto v0015;
    v0040 = v0106;
    v0040 = qcar(v0040);
    v0040 = (consp(v0040) ? nil : lisp_true);
    goto v0044;

v0044:
    if (!(v0040 == nil)) return onevalue(v0106);
    v0106 = qcar(v0106);
    v0106 = qcdr(v0106);
    goto v0020;

v0015:
    v0040 = qvalue(elt(env, 1)); // t
    goto v0044;

v0010:
    v0106 = (LispObject)1; // 0
    return onevalue(v0106);
}



// Code for mtchp

static LispObject CC_mtchp(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0229, v0208, v0211, v0210;
    LispObject fn;
    LispObject v0020, v0037, v0113, v0013, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "mtchp");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0013 = va_arg(aa, LispObject);
    v0113 = va_arg(aa, LispObject);
    v0037 = va_arg(aa, LispObject);
    v0020 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mtchp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0020,v0037,v0113,v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0013,v0113,v0037,v0020);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0020;
    v0229 = v0037;
    stack[-1] = v0113;
    stack[-2] = v0013;
    stack[-3] = v0000;
// end of prologue
    v0210 = stack[-3];
    v0211 = stack[-2];
    v0208 = v0229;
    v0229 = stack[0];
    fn = elt(env, 2); // mtchp1
    v0229 = (*qfnn(fn))(qenv(fn), 4, v0210, v0211, v0208, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    stack[-4] = v0229;
    goto v0014;

v0014:
    v0229 = stack[-4];
    if (v0229 == nil) goto v0032;
    v0229 = stack[-4];
    v0208 = qcar(v0229);
    v0229 = stack[0];
    v0229 = Lsubla(nil, v0208, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    fn = elt(env, 3); // lispeval
    v0229 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    if (v0229 == nil) goto v0021;
    v0229 = stack[-3];
    stack[0] = qcdr(v0229);
    v0229 = stack[-4];
    v0208 = qcar(v0229);
    v0229 = stack[-2];
    v0229 = qcdr(v0229);
    v0229 = Lsubla(nil, v0208, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    v0229 = Ldivide(nil, stack[0], v0229);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    stack[-2] = v0229;
    v0229 = stack[-4];
    v0208 = qcar(v0229);
    v0229 = stack[-1];
    v0229 = Lsubla(nil, v0208, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    fn = elt(env, 4); // simp
    v0208 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    v0229 = stack[-2];
    v0229 = qcar(v0229);
    fn = elt(env, 5); // exptsq
    v0229 = (*qfn2(fn))(qenv(fn), v0208, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    stack[-1] = v0229;
    v0229 = stack[-2];
    v0208 = qcdr(v0229);
    v0229 = (LispObject)1; // 0
    if (v0208 == v0229) { LispObject res = stack[-1]; popv(6); return onevalue(res); }
    v0229 = stack[-3];
    v0208 = qcar(v0229);
    v0229 = stack[-2];
    v0229 = qcdr(v0229);
    fn = elt(env, 6); // to
    v0208 = (*qfn2(fn))(qenv(fn), v0208, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    v0229 = (LispObject)17; // 1
    v0229 = cons(v0208, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    v0208 = ncons(v0229);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    v0229 = (LispObject)17; // 1
    v0208 = cons(v0208, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-5];
    v0229 = stack[-1];
    fn = elt(env, 7); // multsq
    v0229 = (*qfn2(fn))(qenv(fn), v0208, v0229);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    stack[-1] = v0229;
    { LispObject res = stack[-1]; popv(6); return onevalue(res); }

v0021:
    v0229 = stack[-4];
    v0229 = qcdr(v0229);
    stack[-4] = v0229;
    goto v0014;

v0032:
    v0229 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0229); }
// error exit handlers
v0078:
    popv(6);
    return nil;
}



// Code for qqe_mk2

static LispObject CC_qqe_mk2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0015, v0016, v0056;
    LispObject v0113, v0013, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "qqe_mk2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0013 = va_arg(aa, LispObject);
    v0113 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0015 = v0113;
    v0016 = v0013;
    v0056 = v0000;
// end of prologue
    return list3(v0056, v0016, v0015);
}



// Code for absf

static LispObject CC_absf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0042;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for absf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0042 = stack[0];
    fn = elt(env, 1); // minusf
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-1];
    if (v0042 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0042 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // negf
        return (*qfn1(fn))(qenv(fn), v0042);
    }
// error exit handlers
v0015:
    popv(2);
    return nil;
}



// Code for lex

static LispObject CC_lex(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0115, v0190;
    LispObject fn;
    argcheck(nargs, 0, "lex");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// end of prologue
    v0115 = qvalue(elt(env, 2)); // atts
    if (v0115 == nil) goto v0003;
    v0115 = qvalue(elt(env, 2)); // atts
    qvalue(elt(env, 3)) = v0115; // safe_atts
    goto v0003;

v0003:
    v0115 = qvalue(elt(env, 1)); // nil
    qvalue(elt(env, 2)) = v0115; // atts
    v0190 = qvalue(elt(env, 4)); // ch
    v0115 = qvalue(elt(env, 5)); // !$eof!$
    if (equal(v0190, v0115)) goto v0042;
    v0190 = qvalue(elt(env, 4)); // ch
    v0115 = qvalue(elt(env, 6)); // space
    if (equal(v0190, v0115)) goto v0023;
    v0190 = qvalue(elt(env, 4)); // ch
    v0115 = elt(env, 7); // !<
    if (v0190 == v0115) goto v0107;
    fn = elt(env, 10); // get_content
    v0115 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-1];
    qvalue(elt(env, 8)) = v0115; // char
    goto v0019;

v0019:
    v0115 = qvalue(elt(env, 8)); // char
    if (v0115 == nil) goto v0052;
    v0115 = qvalue(elt(env, 9)); // count
    v0115 = add1(v0115);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-1];
    qvalue(elt(env, 9)) = v0115; // count
    v0115 = qvalue(elt(env, 8)); // char
    v0115 = Lreverse(nil, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-1];
    stack[0] = v0115;
    v0115 = stack[0];
    fn = elt(env, 11); // butes
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-1];
    qvalue(elt(env, 8)) = v0115; // char
    v0190 = qvalue(elt(env, 8)); // char
    v0115 = stack[0];
    fn = elt(env, 12); // attributes
    v0115 = (*qfn2(fn))(qenv(fn), v0190, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    goto v0042;

v0042:
    v0115 = nil;
    { popv(2); return onevalue(v0115); }

v0052:
    v0115 = CC_lex(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    goto v0042;

v0107:
    fn = elt(env, 13); // get_token
    v0115 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-1];
    qvalue(elt(env, 8)) = v0115; // char
    goto v0019;

v0023:
    v0190 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-1];
    qvalue(elt(env, 4)) = v0190; // ch
    v0115 = qvalue(elt(env, 6)); // space
    if (equal(v0190, v0115)) goto v0023;
    else goto v0019;
// error exit handlers
v0058:
    popv(2);
    return nil;
}



// Code for replus1

static LispObject CC_replus1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0028, v0024, v0048;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for replus1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0048 = v0000;
// end of prologue
    v0028 = v0048;
    if (v0028 == nil) goto v0020;
    v0028 = v0048;
    if (!consp(v0028)) goto v0041;
    v0024 = v0048;
    v0028 = elt(env, 2); // plus
    if (!consp(v0024)) goto v0055;
    v0024 = qcar(v0024);
    if (!(v0024 == v0028)) goto v0055;
    v0028 = v0048;
    v0028 = qcdr(v0028);
    goto v0035;

v0035:
    if (!(v0028 == nil)) return onevalue(v0048);
    v0028 = v0048;
    v0028 = qcdr(v0028);
    if (v0028 == nil) goto v0022;
    v0028 = elt(env, 2); // plus
    v0024 = v0048;
    return cons(v0028, v0024);

v0022:
    v0028 = v0048;
    v0028 = qcar(v0028);
    return onevalue(v0028);

v0055:
    v0028 = qvalue(elt(env, 3)); // nil
    goto v0035;

v0041:
    v0028 = qvalue(elt(env, 1)); // t
    goto v0035;

v0020:
    v0028 = (LispObject)1; // 0
    return onevalue(v0028);
}



// Code for !*q2a1

static LispObject CC_Hq2a1(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0044, v0015;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *q2a1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0044 = v0013;
    v0015 = v0000;
// end of prologue
    if (v0044 == nil) goto v0011;
    v0044 = v0015;
    {
        fn = elt(env, 1); // prepsqxx
        return (*qfn1(fn))(qenv(fn), v0044);
    }

v0011:
    v0044 = v0015;
    {
        fn = elt(env, 2); // mk!*sq
        return (*qfn1(fn))(qenv(fn), v0044);
    }
}



// Code for peel

static LispObject CC_peel(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0025, v0026;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for peel");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0025 = stack[0];
    v0026 = qcar(v0025);
    v0025 = elt(env, 1); // (liedf innerprod)
    v0025 = Lmemq(nil, v0026, v0025);
    if (v0025 == nil) goto v0018;
    v0025 = stack[0];
    v0025 = qcdr(v0025);
    v0025 = qcdr(v0025);
    v0025 = qcar(v0025);
    { popv(1); return onevalue(v0025); }

v0018:
    v0025 = stack[0];
    v0026 = qcar(v0025);
    v0025 = elt(env, 2); // quotient
    if (v0026 == v0025) goto v0191;
    v0025 = stack[0];
    v0025 = qcdr(v0025);
    v0025 = qcar(v0025);
    { popv(1); return onevalue(v0025); }

v0191:
    v0025 = stack[0];
    v0025 = qcdr(v0025);
    v0026 = qcar(v0025);
    v0025 = stack[0];
    v0025 = qcdr(v0025);
    v0025 = qcdr(v0025);
    v0025 = qcar(v0025);
    fn = elt(env, 3); // worderp
    v0025 = (*qfn2(fn))(qenv(fn), v0026, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    if (v0025 == nil) goto v0060;
    v0025 = stack[0];
    v0025 = qcdr(v0025);
    v0025 = qcar(v0025);
    { popv(1); return onevalue(v0025); }

v0060:
    v0025 = stack[0];
    v0025 = qcdr(v0025);
    v0025 = qcdr(v0025);
    v0025 = qcar(v0025);
    { popv(1); return onevalue(v0025); }
// error exit handlers
v0031:
    popv(1);
    return nil;
}



// Code for mo_ecart

static LispObject CC_mo_ecart(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0027, v0060;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_ecart");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0027 = stack[0];
    v0027 = qcar(v0027);
    if (v0027 == nil) goto v0020;
    v0027 = stack[0];
    fn = elt(env, 3); // mo_comp
    v0060 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-1];
    v0027 = qvalue(elt(env, 1)); // cali!=degrees
    v0027 = Latsoc(nil, v0060, v0027);
    v0060 = v0027;
    v0027 = v0060;
    if (v0027 == nil) goto v0008;
    v0027 = v0060;
    v0060 = qcdr(v0027);
    v0027 = stack[0];
    fn = elt(env, 4); // mo_sum
    v0027 = (*qfn2(fn))(qenv(fn), v0060, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-1];
    goto v0038;

v0038:
    v0027 = qcar(v0027);
    stack[0] = qcdr(v0027);
    v0027 = qvalue(elt(env, 2)); // cali!=basering
    fn = elt(env, 5); // ring_ecart
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-1];
    {
        LispObject v0028 = stack[0];
        popv(2);
        fn = elt(env, 6); // mo!=sprod
        return (*qfn2(fn))(qenv(fn), v0028, v0027);
    }

v0008:
    v0027 = stack[0];
    goto v0038;

v0020:
    v0027 = (LispObject)1; // 0
    { popv(2); return onevalue(v0027); }
// error exit handlers
v0196:
    popv(2);
    return nil;
}



// Code for pv_sort

static LispObject CC_pv_sort(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0018, v0090;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pv_sort");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0090 = v0000;
// end of prologue
    v0018 = v0090;
    if (v0018 == nil) goto v0020;
    v0018 = v0090;
    stack[0] = qcdr(v0018);
    v0018 = v0090;
    v0018 = qcar(v0018);
    v0018 = ncons(v0018);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-1];
    {
        LispObject v0036 = stack[0];
        popv(2);
        fn = elt(env, 2); // pv_sort1
        return (*qfn2(fn))(qenv(fn), v0036, v0018);
    }

v0020:
    v0018 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0018); }
// error exit handlers
v0019:
    popv(2);
    return nil;
}



// Code for bfzerop!:

static LispObject CC_bfzeropT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0041, v0042;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bfzerop:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0041 = v0000;
// end of prologue
    v0041 = qcdr(v0041);
    v0042 = qcar(v0041);
    v0041 = (LispObject)1; // 0
    v0041 = (v0042 == v0041 ? lisp_true : nil);
    return onevalue(v0041);
}



// Code for flatten!-sorted!-tree

static LispObject CC_flattenKsortedKtree(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0089, v0001, v0006;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for flatten-sorted-tree");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0089 = v0013;
    v0001 = v0000;
// end of prologue

v0003:
    v0006 = v0001;
    if (v0006 == nil) { popv(3); return onevalue(v0089); }
    v0006 = v0001;
    v0006 = qcar(v0006);
    stack[-1] = v0006;
    v0006 = v0001;
    v0006 = qcdr(v0006);
    stack[0] = qcar(v0006);
    v0001 = qcdr(v0001);
    v0001 = qcdr(v0001);
    v0089 = CC_flattenKsortedKtree(env, v0001, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-2];
    v0089 = cons(stack[0], v0089);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-2];
    v0001 = stack[-1];
    goto v0003;
// error exit handlers
v0023:
    popv(3);
    return nil;
}



// Code for sfto_reorder

static LispObject CC_sfto_reorder(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0044;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_reorder");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0044 = v0013;
    stack[0] = v0000;
// end of prologue
    v0044 = ncons(v0044);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    fn = elt(env, 1); // setkorder
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    stack[-1] = v0044;
    v0044 = stack[0];
    fn = elt(env, 2); // reorder
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    stack[0] = v0044;
    v0044 = stack[-1];
    fn = elt(env, 1); // setkorder
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    { LispObject res = stack[0]; popv(3); return onevalue(res); }
// error exit handlers
v0056:
    popv(3);
    return nil;
}



// Code for ofsf_posdefp

static LispObject CC_ofsf_posdefp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0042, v0044;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_posdefp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0044 = v0000;
// end of prologue
    v0042 = qvalue(elt(env, 1)); // !*rlpos
    if (v0042 == nil) goto v0014;
    v0042 = v0044;
    {
        fn = elt(env, 2); // ofsf_posdefp!-pos
        return (*qfn1(fn))(qenv(fn), v0042);
    }

v0014:
    v0042 = v0044;
    {
        fn = elt(env, 3); // sfto_tsqsumf
        return (*qfn1(fn))(qenv(fn), v0042);
    }
}



// Code for reordop

static LispObject CC_reordop(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0029, v0191;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reordop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0013);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0013;
    stack[-1] = v0000;
// end of prologue
    v0029 = qvalue(elt(env, 1)); // !*ncmp
    if (v0029 == nil) goto v0009;
    v0029 = stack[-1];
    fn = elt(env, 3); // noncomp1
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    if (v0029 == nil) goto v0016;
    v0029 = stack[0];
    fn = elt(env, 3); // noncomp1
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-2];
    goto v0010;

v0010:
    if (!(v0029 == nil)) { popv(3); return onevalue(v0029); }
    v0191 = stack[-1];
    v0029 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); // ordop
        return (*qfn2(fn))(qenv(fn), v0191, v0029);
    }

v0016:
    v0029 = qvalue(elt(env, 2)); // nil
    goto v0010;

v0009:
    v0029 = qvalue(elt(env, 2)); // nil
    goto v0010;
// error exit handlers
v0089:
    popv(3);
    return nil;
}



// Code for free!-powerp

static LispObject CC_freeKpowerp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0023;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for free-powerp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue

v0112:
    v0023 = stack[0];
    if (!consp(v0023)) goto v0009;
    v0023 = stack[0];
    v0023 = qcar(v0023);
    v0023 = (consp(v0023) ? nil : lisp_true);
    goto v0010;

v0010:
    if (v0023 == nil) goto v0020;
    v0023 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0023); }

v0020:
    v0023 = stack[0];
    v0023 = qcar(v0023);
    v0023 = qcar(v0023);
    v0023 = qcdr(v0023);
    v0023 = integerp(v0023);
    if (v0023 == nil) goto v0004;
    v0023 = stack[0];
    v0023 = qcar(v0023);
    v0023 = qcdr(v0023);
    v0023 = CC_freeKpowerp(env, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-1];
    if (!(v0023 == nil)) { popv(2); return onevalue(v0023); }
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    stack[0] = v0023;
    goto v0112;

v0004:
    v0023 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0023); }

v0009:
    v0023 = qvalue(elt(env, 1)); // t
    goto v0010;
// error exit handlers
v0047:
    popv(2);
    return nil;
}



// Code for retimes

static LispObject CC_retimes(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0173, v0174;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for retimes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0173 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // !*bool
    qvalue(elt(env, 1)) = nil; // !*bool
    fn = elt(env, 4); // retimes1
    v0173 = (*qfn1(fn))(qenv(fn), v0173);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-1];
    v0174 = v0173;
    if (v0174 == nil) goto v0014;
    v0174 = v0173;
    v0174 = qcdr(v0174);
    if (v0174 == nil) goto v0036;
    v0174 = elt(env, 2); // times
    v0173 = cons(v0174, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-1];
    goto v0009;

v0009:
    v0174 = qvalue(elt(env, 1)); // !*bool
    if (v0174 == nil) goto v0020;
    v0174 = elt(env, 3); // minus
    v0173 = list2(v0174, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-1];
    goto v0020;

v0020:
    qvalue(elt(env, 1)) = stack[0]; // !*bool
    { popv(2); return onevalue(v0173); }

v0036:
    v0173 = qcar(v0173);
    goto v0009;

v0014:
    v0173 = (LispObject)17; // 1
    goto v0009;
// error exit handlers
v0027:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; // !*bool
    popv(2);
    return nil;
}



// Code for mkwedge

static LispObject CC_mkwedge(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0044, v0015, v0016;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkwedge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0044 = v0000;
// end of prologue
    v0016 = v0044;
    v0015 = (LispObject)17; // 1
    v0044 = (LispObject)17; // 1
    v0044 = list2star(v0016, v0015, v0044);
    errexit();
    return ncons(v0044);
}



// Code for idlistp

static LispObject CC_idlistp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0106, v0040;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for idlistp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0106 = v0000;
// end of prologue

v0112:
    v0040 = v0106;
    if (v0040 == nil) goto v0020;
    v0040 = v0106;
    if (!consp(v0040)) goto v0032;
    v0040 = v0106;
    v0040 = qcar(v0040);
    if (symbolp(v0040)) goto v0090;
    v0106 = qvalue(elt(env, 2)); // nil
    return onevalue(v0106);

v0090:
    v0106 = qcdr(v0106);
    goto v0112;

v0032:
    v0106 = qvalue(elt(env, 2)); // nil
    return onevalue(v0106);

v0020:
    v0106 = qvalue(elt(env, 1)); // t
    return onevalue(v0106);
}



// Code for qassoc

static LispObject CC_qassoc(LispObject env,
                         LispObject v0000, LispObject v0013)
{
    LispObject nil = C_nil;
    LispObject v0039, v0106, v0040, v0055;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qassoc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0040 = v0013;
    v0055 = v0000;
// end of prologue

v0011:
    v0039 = v0040;
    if (v0039 == nil) goto v0009;
    v0106 = v0055;
    v0039 = v0040;
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    if (v0106 == v0039) goto v0041;
    v0039 = v0040;
    v0039 = qcdr(v0039);
    v0040 = v0039;
    goto v0011;

v0041:
    v0039 = v0040;
    v0039 = qcar(v0039);
    return onevalue(v0039);

v0009:
    v0039 = qvalue(elt(env, 1)); // nil
    return onevalue(v0039);
}



// Code for negf

static LispObject CC_negf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0188, v0051;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for negf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0011;

v0011:
    v0188 = stack[-1];
    if (v0188 == nil) goto v0009;
    v0188 = stack[-1];
    if (!consp(v0188)) goto v0056;
    v0188 = stack[-1];
    v0188 = qcar(v0188);
    v0188 = (consp(v0188) ? nil : lisp_true);
    goto v0016;

v0016:
    if (v0188 == nil) goto v0031;
    stack[0] = stack[-2];
    v0188 = stack[-1];
    if (!consp(v0188)) goto v0007;
    v0188 = qvalue(elt(env, 3)); // nil
    goto v0006;

v0006:
    if (v0188 == nil) goto v0108;
    v0188 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v0188)) v0051 = nil;
    else { v0051 = qfastgets(v0188);
           if (v0051 != nil) { v0051 = elt(v0051, 34); // i2d
#ifdef RECORD_GET
             if (v0051 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0051 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0051 == SPID_NOPROP) v0051 = nil; }}
#endif
    v0188 = stack[-1];
    v0188 = Lapply1(nil, v0051, v0188);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    goto v0002;

v0002:
    fn = elt(env, 4); // !:minus
    v0188 = (*qfn1(fn))(qenv(fn), v0188);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    {
        LispObject v0115 = stack[0];
        popv(4);
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(qenv(fn), v0115, v0188);
    }

v0108:
    v0188 = stack[-1];
    goto v0002;

v0007:
    v0188 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v0188)) v0188 = nil;
    else { v0188 = qfastgets(v0188);
           if (v0188 != nil) { v0188 = elt(v0188, 5); // convert
#ifdef RECORD_GET
             if (v0188 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v0188 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v0188 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v0188 == SPID_NOPROP) v0188 = nil; else v0188 = lisp_true; }}
#endif
    goto v0006;

v0031:
    v0188 = stack[-1];
    v0188 = qcar(v0188);
    stack[0] = qcar(v0188);
    v0188 = stack[-1];
    v0188 = qcar(v0188);
    v0188 = qcdr(v0188);
    v0051 = CC_negf(env, v0188);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    v0188 = stack[-2];
    v0188 = acons(stack[0], v0051, v0188);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-3];
    stack[-2] = v0188;
    v0188 = stack[-1];
    v0188 = qcdr(v0188);
    stack[-1] = v0188;
    goto v0011;

v0056:
    v0188 = qvalue(elt(env, 1)); // t
    goto v0016;

v0009:
    v0188 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); // nreverse
        return (*qfn1(fn))(qenv(fn), v0188);
    }
// error exit handlers
v0202:
    popv(4);
    return nil;
}



// Code for formlis

static LispObject CC_formlis(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0022, v0089, v0001;
    LispObject fn;
    LispObject v0113, v0013, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formlis");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0013 = va_arg(aa, LispObject);
    v0113 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formlis");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0113,v0013,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0013,v0113);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0113;
    stack[-1] = v0013;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    goto v0010;

v0010:
    v0022 = stack[-2];
    if (v0022 == nil) goto v0043;
    v0022 = stack[-2];
    v0001 = qcar(v0022);
    v0089 = stack[-1];
    v0022 = stack[0];
    fn = elt(env, 1); // form1
    v0089 = (*qfnn(fn))(qenv(fn), 3, v0001, v0089, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    v0022 = stack[-3];
    v0022 = cons(v0089, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-4];
    stack[-3] = v0022;
    v0022 = stack[-2];
    v0022 = qcdr(v0022);
    stack[-2] = v0022;
    goto v0010;

v0043:
    v0022 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); // reversip!*
        return (*qfn1(fn))(qenv(fn), v0022);
    }
// error exit handlers
v0193:
    popv(5);
    return nil;
}



// Code for nonzero!-length

static LispObject CC_nonzeroKlength(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0039, v0106, v0040;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nonzero-length");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0106 = v0000;
// end of prologue

v0020:
    v0039 = v0106;
    if (v0039 == nil) goto v0010;
    v0039 = v0106;
    v0040 = qcar(v0039);
    v0039 = (LispObject)1; // 0
    if (v0040 == v0039) goto v0035;
    v0039 = v0106;
    v0039 = qcdr(v0039);
    v0039 = CC_nonzeroKlength(env, v0039);
    errexit();
    return add1(v0039);

v0035:
    v0039 = v0106;
    v0039 = qcdr(v0039);
    v0106 = v0039;
    goto v0020;

v0010:
    v0039 = (LispObject)1; // 0
    return onevalue(v0039);
}



// Code for pv_renorm

static LispObject CC_pv_renorm(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0154, v0155;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pv_renorm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0154 = stack[0];
    if (!(v0154 == nil)) goto v0016;
    v0154 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0154); }

v0016:
    v0154 = stack[0];
    if (v0154 == nil) goto v0015;
    v0154 = stack[0];
    v0154 = qcar(v0154);
    v0155 = qcar(v0154);
    v0154 = (LispObject)1; // 0
    if (!(v0155 == v0154)) goto v0015;
    v0154 = stack[0];
    v0154 = qcdr(v0154);
    stack[0] = v0154;
    goto v0016;

v0015:
    v0154 = stack[0];
    if (v0154 == nil) goto v0001;
    v0154 = stack[0];
    v0154 = qcar(v0154);
    v0155 = qcar(v0154);
    v0154 = (LispObject)1; // 0
    v0154 = (LispObject)lessp2(v0155, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    v0154 = v0154 ? lisp_true : nil;
    env = stack[-4];
    if (v0154 == nil) goto v0193;
    v0154 = stack[0];
    fn = elt(env, 2); // pv_neg
    v0154 = (*qfn1(fn))(qenv(fn), v0154);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    stack[0] = v0154;
    goto v0193;

v0193:
    v0154 = stack[0];
    v0154 = qcar(v0154);
    v0154 = qcar(v0154);
    stack[-2] = v0154;
    v0154 = stack[0];
    v0154 = qcdr(v0154);
    stack[-3] = v0154;
    goto v0199;

v0199:
    v0154 = stack[-3];
    if (v0154 == nil) goto v0189;
    v0155 = stack[-2];
    v0154 = (LispObject)17; // 1
    if (v0155 == v0154) goto v0189;
    v0155 = stack[-2];
    v0154 = stack[-3];
    v0154 = qcar(v0154);
    v0154 = qcar(v0154);
    fn = elt(env, 3); // gcdf!*
    v0154 = (*qfn2(fn))(qenv(fn), v0155, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    stack[-2] = v0154;
    v0154 = stack[-3];
    v0154 = qcdr(v0154);
    stack[-3] = v0154;
    goto v0199;

v0189:
    v0154 = qvalue(elt(env, 1)); // nil
    stack[-3] = v0154;
    v0154 = stack[0];
    stack[-1] = v0154;
    goto v0219;

v0219:
    v0154 = stack[-1];
    if (v0154 == nil) goto v0221;
    v0154 = stack[-1];
    v0154 = qcar(v0154);
    stack[0] = v0154;
    v0154 = stack[0];
    v0155 = qcar(v0154);
    v0154 = (LispObject)1; // 0
    if (v0155 == v0154) goto v0163;
    v0155 = stack[-2];
    v0154 = (LispObject)17; // 1
    if (v0155 == v0154) goto v0210;
    v0154 = stack[0];
    v0155 = qcar(v0154);
    v0154 = stack[-2];
    v0155 = quot2(v0155, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    v0154 = stack[0];
    v0154 = qcdr(v0154);
    v0154 = cons(v0155, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    v0155 = v0154;
    goto v0164;

v0164:
    v0154 = stack[-3];
    v0154 = cons(v0155, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    stack[-3] = v0154;
    goto v0163;

v0163:
    v0154 = stack[-1];
    v0154 = qcdr(v0154);
    stack[-1] = v0154;
    goto v0219;

v0210:
    v0154 = stack[0];
    v0155 = v0154;
    goto v0164;

v0221:
    v0154 = stack[-3];
        popv(5);
        return Lnreverse(nil, v0154);

v0001:
    v0154 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0154); }
// error exit handlers
v0074:
    popv(5);
    return nil;
}



// Code for general!-modular!-number

static LispObject CC_generalKmodularKnumber(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0029, v0191;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-number");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0191 = stack[0];
    v0029 = qvalue(elt(env, 1)); // current!-modulus
    v0029 = Cremainder(v0191, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    stack[0] = v0029;
    v0191 = stack[0];
    v0029 = (LispObject)1; // 0
    v0029 = (LispObject)lessp2(v0191, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    v0029 = v0029 ? lisp_true : nil;
    env = stack[-1];
    if (v0029 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0191 = stack[0];
    v0029 = qvalue(elt(env, 1)); // current!-modulus
    v0029 = plus2(v0191, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    stack[0] = v0029;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0022:
    popv(2);
    return nil;
}



setup_type const u03_setup[] =
{
    {":zerop",                  CC_Tzerop,      too_many_1,    wrong_no_1},
    {"evcompless?",             too_few_2,      CC_evcomplessW,wrong_no_2},
    {"rd:zerop",                CC_rdTzerop,    too_many_1,    wrong_no_1},
    {"wedgepf2",                too_few_2,      CC_wedgepf2,   wrong_no_2},
    {"*physopp*",               CC_HphysoppH,   too_many_1,    wrong_no_1},
    {"union_edges",             too_few_2,      CC_union_edges,wrong_no_2},
    {"errorp",                  CC_errorp,      too_many_1,    wrong_no_1},
    {"cdiv",                    too_few_2,      CC_cdiv,       wrong_no_2},
    {"add_prin_char",           too_few_2,      CC_add_prin_char,wrong_no_2},
    {"pv_multc",                too_few_2,      CC_pv_multc,   wrong_no_2},
    {"upbve",                   CC_upbve,       too_many_1,    wrong_no_1},
    {"*i2rn",                   CC_Hi2rn,       too_many_1,    wrong_no_1},
    {"plus-mod-p",              too_few_2,      CC_plusKmodKp, wrong_no_2},
    {"striptag",                CC_striptag,    too_many_1,    wrong_no_1},
    {"lalr_same_core",          too_few_2,      CC_lalr_same_core,wrong_no_2},
    {"toknump",                 CC_toknump,     too_many_1,    wrong_no_1},
    {"rl_smcpknowl",            CC_rl_smcpknowl,too_many_1,    wrong_no_1},
    {"symbollessp",             too_few_2,      CC_symbollessp,wrong_no_2},
    {"lt*",                     CC_ltH,         too_many_1,    wrong_no_1},
    {"nocp",                    CC_nocp,        too_many_1,    wrong_no_1},
    {"subs2f",                  CC_subs2f,      too_many_1,    wrong_no_1},
    {"gcdfd",                   too_few_2,      CC_gcdfd,      wrong_no_2},
    {"printout",                CC_printout,    too_many_1,    wrong_no_1},
    {"initcomb",                CC_initcomb,    too_many_1,    wrong_no_1},
    {"evmatrixcomp",            too_few_2,      CC_evmatrixcomp,wrong_no_2},
    {"pprin2",                  CC_pprin2,      too_many_1,    wrong_no_1},
    {"opmtch*",                 CC_opmtchH,     too_many_1,    wrong_no_1},
    {"timesip",                 CC_timesip,     too_many_1,    wrong_no_1},
    {"fs:timestermterm",        too_few_2,      CC_fsTtimestermterm,wrong_no_2},
    {"mo_vdivides?",            too_few_2,      CC_mo_vdividesW,wrong_no_2},
    {"dless",                   too_few_2,      CC_dless,      wrong_no_2},
    {"pv_sort2",                too_few_2,      CC_pv_sort2,   wrong_no_2},
    {"noncomp1",                CC_noncomp1,    too_many_1,    wrong_no_1},
    {"split_form",              too_few_2,      CC_split_form, wrong_no_2},
    {"rl_ordatp",               too_few_2,      CC_rl_ordatp,  wrong_no_2},
    {"monomcomparedegrevlex",   too_few_2,      CC_monomcomparedegrevlex,wrong_no_2},
    {"delallasc",               too_few_2,      CC_delallasc,  wrong_no_2},
    {"rmultpf",                 too_few_2,      CC_rmultpf,    wrong_no_2},
    {"gcdfd1",                  too_few_2,      CC_gcdfd1,     wrong_no_2},
    {"multsq",                  too_few_2,      CC_multsq,     wrong_no_2},
    {"qqe_nytidp",              CC_qqe_nytidp,  too_many_1,    wrong_no_1},
    {"bftrim:",                 CC_bftrimT,     too_many_1,    wrong_no_1},
    {"off1",                    CC_off1,        too_many_1,    wrong_no_1},
    {"mgenp",                   CC_mgenp,       too_many_1,    wrong_no_1},
    {"on1",                     CC_on1,         too_many_1,    wrong_no_1},
    {"evsum",                   too_few_2,      CC_evsum,      wrong_no_2},
    {"bcint2op",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_bcint2op},
    {"quotfm",                  too_few_2,      CC_quotfm,     wrong_no_2},
    {"*collectphysops_reversed",too_few_2,      CC_Hcollectphysops_reversed,wrong_no_2},
    {"constimes",               CC_constimes,   too_many_1,    wrong_no_1},
    {"arraychk",                CC_arraychk,    too_many_1,    wrong_no_1},
    {"fs:angle-order",          too_few_2,      CC_fsTangleKorder,wrong_no_2},
    {"cali_trace",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_cali_trace},
    {"pcmult",                  too_few_2,      CC_pcmult,     wrong_no_2},
    {"pkp",                     CC_pkp,         too_many_1,    wrong_no_1},
    {"fkern",                   CC_fkern,       too_many_1,    wrong_no_1},
    {"setdiff",                 too_few_2,      CC_setdiff,    wrong_no_2},
    {"lalr_cached_goto",        too_few_2,      CC_lalr_cached_goto,wrong_no_2},
    {"subs2q",                  CC_subs2q,      too_many_1,    wrong_no_1},
    {"qqe_btidp",               CC_qqe_btidp,   too_many_1,    wrong_no_1},
    {"prepsq",                  CC_prepsq,      too_many_1,    wrong_no_1},
    {"subs2*",                  CC_subs2H,      too_many_1,    wrong_no_1},
    {"negsq",                   CC_negsq,       too_many_1,    wrong_no_1},
    {"hasonephysop",            CC_hasonephysop,too_many_1,    wrong_no_1},
    {"errorset*",               too_few_2,      CC_errorsetH,  wrong_no_2},
    {"fs:timesterm",            too_few_2,      CC_fsTtimesterm,wrong_no_2},
    {"bas_rep",                 CC_bas_rep,     too_many_1,    wrong_no_1},
    {":minus",                  CC_Tminus,      too_many_1,    wrong_no_1},
    {"rev",                     too_few_2,      CC_rev,        wrong_no_2},
    {"**s2a",                   too_few_2,      CC_HHs2a,      wrong_no_2},
    {"lto_insertq",             too_few_2,      CC_lto_insertq,wrong_no_2},
    {"lnc",                     CC_lnc,         too_many_1,    wrong_no_1},
    {"mtchp",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_mtchp},
    {"qqe_mk2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_qqe_mk2},
    {"absf",                    CC_absf,        too_many_1,    wrong_no_1},
    {"lex",                     wrong_no_na,    wrong_no_nb,   (n_args *)CC_lex},
    {"replus1",                 CC_replus1,     too_many_1,    wrong_no_1},
    {"*q2a1",                   too_few_2,      CC_Hq2a1,      wrong_no_2},
    {"peel",                    CC_peel,        too_many_1,    wrong_no_1},
    {"mo_ecart",                CC_mo_ecart,    too_many_1,    wrong_no_1},
    {"pv_sort",                 CC_pv_sort,     too_many_1,    wrong_no_1},
    {"bfzerop:",                CC_bfzeropT,    too_many_1,    wrong_no_1},
    {"flatten-sorted-tree",     too_few_2,      CC_flattenKsortedKtree,wrong_no_2},
    {"sfto_reorder",            too_few_2,      CC_sfto_reorder,wrong_no_2},
    {"ofsf_posdefp",            CC_ofsf_posdefp,too_many_1,    wrong_no_1},
    {"reordop",                 too_few_2,      CC_reordop,    wrong_no_2},
    {"free-powerp",             CC_freeKpowerp, too_many_1,    wrong_no_1},
    {"retimes",                 CC_retimes,     too_many_1,    wrong_no_1},
    {"mkwedge",                 CC_mkwedge,     too_many_1,    wrong_no_1},
    {"idlistp",                 CC_idlistp,     too_many_1,    wrong_no_1},
    {"qassoc",                  too_few_2,      CC_qassoc,     wrong_no_2},
    {"negf",                    CC_negf,        too_many_1,    wrong_no_1},
    {"formlis",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_formlis},
    {"nonzero-length",          CC_nonzeroKlength,too_many_1,  wrong_no_1},
    {"pv_renorm",               CC_pv_renorm,   too_many_1,    wrong_no_1},
    {"general-modular-number",  CC_generalKmodularKnumber,too_many_1,wrong_no_1},
    {NULL, (one_args *)"u03", (two_args *)"6365 7356387 9323552", 0}
};

// end of generated code
